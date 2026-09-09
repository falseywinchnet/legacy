#include <feq/transition_energy.hpp>
#include <feq/steady_residual.hpp>
#include "callbacks.hpp"
/* expcon.f -- translated by f2c (version 20240504).
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

/* COMMON feccom_ is declared in common.hpp. */

#define feccom_1 feccom_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* Table of constant values */

static integer feq_gen_c_d_30 = 30;
static real c_b8 = (float)1e5;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_12 = 12;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_151 = 151;




/* SOURCE expcon.for:4 */
/*<       realfunctionfrlres(qt) >*/
doublereal frlres_(real *qt)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    extern /* Subroutine */ int fndhpl_();

/*     + + + PURPOSE + + + */
/*     Find froude number residual at the left section */
/* SOURCE expcon.for:10 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE expcon.for:13 */
/*<       realqt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     QT     - Flow rate */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE expcon.for:19 */
/*     COMMON block for Finding Expansion-Contraction tables. */
/* SOURCE feccom.cmn:3 */
/*<       integerxtabl,xtabr,flg >*/
/* SOURCE feccom.cmn:5 */
/*<        >*/
/* SOURCE feccom.cmn:9 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE expcon.for:22 */
/*<       externalfndhpl >*/
/* *********************************************************************** */
/* SOURCE expcon.for:24 */
/*<       q=qt >*/
    feccom_1.q = *qt;
/* SOURCE expcon.for:25 */
/*<       callfndhpl >*/
    fndhpl_();
    if (feccom_1.flg == 0 || feccom_1.flg == 5) {
        return feq::transition_froude_residual(feccom_1.q,feccom_1.qcl);
    }
    return -1.0;
} /* frlres_ */




/* SOURCE expcon.for:41 */
/*<       realfunctionecechk() >*/
doublereal ecechk_()
{
    const feq::TransitionEnergyInput input{feccom_1.htl,feccom_1.hpr,
        feccom_1.al,feccom_1.ar,feccom_1.alphal,feccom_1.alphar,
        feccom_1.kl,feccom_1.kr,feccom_1.dx,feccom_1.smooth,
        feccom_1.ka,feccom_1.kd,feccom_1.grv2,feccom_1.q,feccom_1.tgm};
    return feq::transition_energy_check(input,epscom_1.epsdif);
} /* ecechk_ */




/* SOURCE expcon.for:85 */
/*<       realfunctionfacdc(x,smooth,ka,kd) >*/
doublereal facdc_(real *x, real *smooth, real *ka, real *kd)
{
    return feq::transition_loss_factor(*x,*smooth,*ka,*kd);
} /* facdc_ */




/* SOURCE expcon.for:136 */
/*<       realfunctiongmean(xa,ya,ta) >*/
doublereal gmean_(real *xa, real *ya, real *ta)
{
    return feq::transition_conveyance_mean(*xa,*ya,*ta);
} /* gmean_ */




/* SOURCE expcon.for:175 */
/*<       doubleprecisionfunctionfhpl(h) >*/
doublereal fhpl_(doublereal *feq_gen_h_d_)
{
    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal ret_val;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real b, x, y, db, jl, tl, dkl, dtl;
    extern doublereal facdc_(real *, real *, real *, real *), gmean_(real *, 
	    real *, real *);
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real dalpha;

/*     + + + PURPOSE + + + */
/*     Compute the residual function defining the piezometric head */
/*     at the left end of the transition when the flow */
/*     is fixed and the piezometric head on the right is fixed. */
/* SOURCE expcon.for:183 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE expcon.for:186 */
/*<       doubleprecisionh >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H      - Piezometric head */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE expcon.for:192 */
/*     COMMON block for Finding Expansion-Contraction tables. */
/* SOURCE feccom.cmn:3 */
/*<       integerxtabl,xtabr,flg >*/
/* SOURCE feccom.cmn:5 */
/*<        >*/
/* SOURCE feccom.cmn:9 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE expcon.for:195 */
/*<       realb,dalpha,db,dkl,dtl,jl,tl,x,y >*/
/*     + + + INTRINSICS + + + */
/* SOURCE expcon.for:198 */
/*<       intrinsicsqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE expcon.for:201 */
/*<       realfacdc,gmean >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE expcon.for:204 */
/*<       externalfacdc,gmean,xlkt22 >*/
/* *********************************************************************** */
/*      WRITE(STD6,*) ' FHPL: H=',H,' Q=',Q */
/*     THE ELEMENTS AT R ARE CONSTANT AND MUST BE KNOWN ON ENTRY-- */
/*     CONTAINED IN FECCOM.FOR. */
/*     FIND ELEMENTS AT L FOR THE CURRENT PIEZOMETRIC HEAD */
/* SOURCE expcon.for:213 */
/*<       hpl=h >*/
    feccom_1.hpl = *feq_gen_h_d_;
/* SOURCE expcon.for:214 */
/*<       yl=hpl+hdatum-zbl >*/
    feccom_1.yl = static_cast<double>(static_cast<double>(feccom_1.hpl) + feccom_1.hdatum) - feccom_1.zbl;
/* SOURCE expcon.for:215 */
/*<       if(xtabl.gt.0)then >*/
    if (feccom_1.xtabl > 0) {
/* SOURCE expcon.for:216 */
/*<       callxlkt22(xtabl,yl,al,tl,dtl,jl,kl,dkl,b,db,alphal,dalpha,qcl) >*/
	xlkt22_(&feccom_1.xtabl, &feccom_1.yl, &feccom_1.al, &tl, &dtl, &jl, &
		feccom_1.kl, &dkl, &b, &db, &feccom_1.alphal, &dalpha, &
		feccom_1.qcl);
/*       WRITE(STD6,*) ' FHPL: HPL=',HPL,' YL=',YL,' QCL=',QCL */
/* SOURCE expcon.for:222 */
/*<       htl=hpl+alphal*(q/al)**2/grv2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(feccom_1.q) / feccom_1.al;
	feccom_1.htl = feq::steady_specific_energy(feccom_1.hpl,feccom_1.q,
            feccom_1.al,feccom_1.alphal,feccom_1.grv2);
/* SOURCE expcon.for:223 */
/*<       else >*/
    } else {
/*       RESERVOIR ON LEFT */
/* SOURCE expcon.for:225 */
/*<       al=1.e10 >*/
	feccom_1.al = (float)1e10;
/* SOURCE expcon.for:226 */
/*<       alphal=0.0 >*/
	feccom_1.alphal = (float)0.;
/* SOURCE expcon.for:227 */
/*<       kl=1.e10 >*/
	feccom_1.kl = (float)1e10;
/* SOURCE expcon.for:228 */
/*<       htl=hpl >*/
	feccom_1.htl = feccom_1.hpl;
/* SOURCE expcon.for:229 */
/*<       qcl=1.e20 >*/
	feccom_1.qcl = (float)1e20;
/* SOURCE expcon.for:230 */
/*<       endif >*/
    }
/* SOURCE expcon.for:233 */
/*<       x=q*(sqrt(alphar)/ar-sqrt(alphal)/al) >*/
        const feq::TransitionEnergyInput input{feccom_1.htl,feccom_1.hpr,
        feccom_1.al,feccom_1.ar,feccom_1.alphal,feccom_1.alphar,
        feccom_1.kl,feccom_1.kr,feccom_1.dx,feccom_1.smooth,
        feccom_1.ka,feccom_1.kd,feccom_1.grv2,feccom_1.q,feccom_1.tgm};
    return feq::transition_head_residual(input);
} /* fhpl_ */




/* SOURCE expcon.for:247 */
/*<       subroutinefndhpl() >*/
/* Subroutine */ int fndhpl_()
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    real htr, sum, sum1;
    doublereal darg;
    real argl;
    extern doublereal fhpl_(doublereal *);
    real argr, ymax;
    doublereal aleft, fleft, aright;
    extern /* Subroutine */ int secant_(real *, real *, real *, real *, 
	    integer *, real *, real *, FeqCallback1, real *, integer *);
    doublereal fright;
    extern doublereal fmxarg_(integer *);
    real hplmin, hplmax, hplest;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__21 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find the piezometric head at left given the piezometric head */
/*     at right and the flow rate.  If no solution set FLG in FECCOM. */
/*     flow rate is in FECCOM.COM. Solution is returned in FECCOM also. */
/* SOURCE expcon.for:254 */
/*<       implicitnone >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE expcon.for:257 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE expcon.for:258 */
/*     COMMON block for Finding Expansion-Contraction tables. */
/* SOURCE feccom.cmn:3 */
/*<       integerxtabl,xtabr,flg >*/
/* SOURCE feccom.cmn:5 */
/*<        >*/
/* SOURCE feccom.cmn:9 */
/*<        >*/
/* INCLUDE expcon.for:259 */
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
/* SOURCE expcon.for:262 */
/*<       integeri >*/
/* SOURCE expcon.for:263 */
/*<       realargl,argr,hplest,hplmax,hplmin,htr,sum,sum1,ymax >*/
/* SOURCE expcon.for:264 */
/*<       doubleprecisionaleft,aright,darg,fleft,fright >*/
/*     + + + INTRINSICS + + + */
/* SOURCE expcon.for:267 */
/*<       intrinsicabs,sngl >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE expcon.for:270 */
/*<       realfmxarg >*/
/* SOURCE expcon.for:271 */
/*<       doubleprecisionfhpl >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE expcon.for:274 */
/*<       externalfhpl,fmxarg,secant >*/
/* *********************************************************************** */
/*     USE EXHAUSTIVE SEARCH FOR SUBCRITICAL SOLUTION. */
/* SOURCE expcon.for:278 */
/*<       htr=hpr+alphar*(q/ar)**2/grv2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(feccom_1.q) / feccom_1.ar;
    htr = feq::steady_specific_energy(feccom_1.hpr,feccom_1.q,
        feccom_1.ar,feccom_1.alphar,feccom_1.grv2);
/* SOURCE expcon.for:280 */
/*<       if(xtabl.eq.0)then >*/
    if (feccom_1.xtabl == 0) {
/*       RESERVOIR ON THE LEFT.  A SUBCRITICAL SOLUTION ALWAYS EXISTS */
/*       BECAUSE THE FLOW WILL BE CRITICAL AT THE RIGHT AT MOST. */
/*       MINIMUM VALUE AT LEFT IS THE TOTAL ENERGY LINE ELEV AT RIGHT */
/* SOURCE expcon.for:286 */
/*<       hpl=1.05*htr >*/
	feccom_1.hpl = static_cast<double>(htr) * (float)1.05;
/* SOURCE expcon.for:287 */
/*<       hplest=htr >*/
	hplest = htr;
/* SOURCE expcon.for:288 */
/*<       callsecant(hplest,epsarg,epsf,epsabs,30,htr,1.e5,fhpl,hpl,flg) >*/
	secant_(&hplest, &epscom_1.epsarg, &epscom_1.epsf, &epscom_1.epsabs, &
		feq_gen_c_d_30, &htr, &c_b8, fhpl_, &feccom_1.hpl, &feccom_1.flg)
		;
/* SOURCE expcon.for:292 */
/*<       if(flg.gt.0)then >*/
	if (feccom_1.flg > 0) {
/* SOURCE expcon.for:293 */
/*<       write(std6,*)' FNDHPL: NO SOLUTION WITH RESERVOIR ON LEFT.' >*/
	    feq_gen_io_d__21.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__21);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FNDHPL: NO SOLUTION WITH RESERVOIR ON LEF\
T."), (ftnlen)44);
	    e_wsle();
/* SOURCE expcon.for:294 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE expcon.for:295 */
/*<       endif >*/
	}
/* SOURCE expcon.for:296 */
/*<       else >*/
    } else {
/*       DO A SEARCH ON VALID UPSTREAM HEADS FOR A SIGN CHANGE IN */
/*       FHPL */
/* SOURCE expcon.for:300 */
/*<       ymax=fmxarg(xtabl) >*/
	ymax = fmxarg_(&feccom_1.xtabl);
/* SOURCE expcon.for:301 */
/*<       hplmax=zbl+ymax-hdatum >*/
	hplmax = static_cast<double>(static_cast<double>(feccom_1.zbl) + ymax) - feccom_1.hdatum;
/* SOURCE expcon.for:302 */
/*<       if(hplmax.gt.2.*htr)then >*/
	if (hplmax > static_cast<double>(htr) * (float)2.) {
/* SOURCE expcon.for:303 */
/*<       hplmax=2.*htr >*/
	    hplmax = static_cast<double>(htr) * (float)2.;
/* SOURCE expcon.for:304 */
/*<       endif >*/
	}
/* SOURCE expcon.for:305 */
/*<       hplmin=zbl-hdatum >*/
	hplmin = static_cast<double>(feccom_1.zbl) - feccom_1.hdatum;
/* SOURCE expcon.for:306 */
/*<       if(hplmin.lt.0.0)then >*/
	if (hplmin < (float)0.) {
/* SOURCE expcon.for:307 */
/*<       hplmin=0.0 >*/
	    hplmin = (float)0.;
/* SOURCE expcon.for:308 */
/*<       endif >*/
	}
/* SOURCE expcon.for:309 */
/*<       aright=hplmax >*/
	aright = hplmax;
/* SOURCE expcon.for:310 */
/*<       fright=fhpl(aright) >*/
	fright = fhpl_(&aright);
/* SOURCE expcon.for:311 */
/*<       darg=(hplmax-hplmin)/32. >*/
	darg = static_cast<double>((static_cast<double>(hplmax) - hplmin)) / (float)32.;
/*       WRITE(STD6,*) ' FNDHPL: ARIGHT=',ARIGHT,' FRIGHT=',FRIGHT */
/* SOURCE expcon.for:314 */
/*<       sum=1.e10 >*/
	sum = (float)1e10;
/* SOURCE expcon.for:315 */
/*<       do100i=1,31 >*/
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 31; ++feq_gen_i_d_) {
/* SOURCE expcon.for:316 */
/*<       aleft=aright-darg >*/
	    aleft = aright - darg;
/* SOURCE expcon.for:317 */
/*<       fleft=fhpl(aleft) >*/
	    fleft = fhpl_(&aleft);
/*       WRITE(STD6,*) ' FNDHPL: ALEFT=',ALEFT,' FLEFT=',FLEFT */
/* SOURCE expcon.for:320 */
/*<       if(fleft*fright.le.0d0)goto105 >*/
	    if (fleft * fright <= 0.) {
		goto L105;
	    }
/* SOURCE expcon.for:321 */
/*<       sum1=abs(fleft)+abs(fright) >*/
	    sum1 = abs(fleft) + abs(fright);
/* SOURCE expcon.for:322 */
/*<       if(sum1.lt.sum)then >*/
	    if (sum1 < sum) {
/* SOURCE expcon.for:323 */
/*<       sum=sum1 >*/
		sum = sum1;
/* SOURCE expcon.for:324 */
/*<       argl=aleft >*/
		argl = aleft;
/* SOURCE expcon.for:325 */
/*<       argr=aright >*/
		argr = aright;
/* SOURCE expcon.for:326 */
/*<       endif >*/
	    }
/* SOURCE expcon.for:327 */
/*<       aright=aleft >*/
	    aright = aleft;
/* SOURCE expcon.for:328 */
/*<       fright=fleft >*/
	    fright = fleft;
/* SOURCE expcon.for:329 */
/*<   100 continue >*/
/* L100: */
	}
/*       NO SIGN CHANGE HERE. */
/*       TRY FOR A SOLUTION BECAUSE THE SEARCH MAY HAVE MISSED */
/*       WRITE(STD6,*) ' FNDHPL: NO SIGN CHANGE.' */
/* SOURCE expcon.for:333 */
/*<       hpl=(argr) >*/
	feccom_1.hpl = argr;
/* SOURCE expcon.for:334 */
/*<        >*/
	feq_gen_r_d_1 = argl;
	secant_(&feq_gen_r_d_1, &epscom_1.epsarg, &epscom_1.epsf, &epscom_1.epsabs, &
		feq_gen_c_d_30, &hplmin, &hplmax, fhpl_, &feccom_1.hpl, &
		feccom_1.flg);
/* SOURCE expcon.for:338 */
/*<       if(flg.gt.0)then >*/
	if (feccom_1.flg > 0) {
/* SOURCE expcon.for:339 */
/*<       flg=3 >*/
	    feccom_1.flg = 3;
/*         WRITE(STD6,*) ' FNDHPL: NO SOLUTION WITH NO SIGN CHANGE.' */
/* SOURCE expcon.for:341 */
/*<       return >*/
	    return 0;
/* SOURCE expcon.for:342 */
/*<       endif >*/
	}
/* SOURCE expcon.for:344 */
/*<       goto110 >*/
	goto L110;
/* SOURCE expcon.for:345 */
/*<   105 continue >*/
L105:
/*       SOLUTION EXISTS.  USE SECANT TO FIND IT IN THE INTERVAL. */
/* SOURCE expcon.for:347 */
/*<       hpl=sngl(aright) >*/
	feccom_1.hpl = (real) aright;
/* SOURCE expcon.for:348 */
/*<        >*/
	feq_gen_r_d_1 = (real) aleft;
	secant_(&feq_gen_r_d_1, &epscom_1.epsarg, &epscom_1.epsf, &epscom_1.epsabs, &
		feq_gen_c_d_30, &hplmin, &hplmax, fhpl_, &feccom_1.hpl, &
		feccom_1.flg);
/* SOURCE expcon.for:352 */
/*<       if(flg.gt.0)flg=4 >*/
	if (feccom_1.flg > 0) {
	    feccom_1.flg = 4;
	}
/* SOURCE expcon.for:353 */
/*<   110 continue >*/
L110:
/*       CHECK FOR SUBCRITICAL SOLUTION */
/* SOURCE expcon.for:355 */
/*<       if(flg.eq.0.and.q/qcl.ge.1.0)then >*/
	if (feccom_1.flg == 0 && static_cast<double>(feccom_1.q) / feccom_1.qcl >= (float)1.) {
/* SOURCE expcon.for:356 */
/*<       flg=5 >*/
	    feccom_1.flg = 5;
/*          WRITE(STD6,*) ' FNDHPL: FROUDE > 1: Q=',Q,' QCL=',QCL */
/* SOURCE expcon.for:358 */
/*<       endif >*/
	}
/* SOURCE expcon.for:359 */
/*<       endif >*/
    }
/*      WRITE(STD6,50) HTL, HPL, HPR, FLG */
/* 50    FORMAT('0FNDHPL EXIT: HTL=',F10.4,' HPL=',F10.4,' HPR=',F10.4, */
/*     A         ' FLG=',I5) */
/* SOURCE expcon.for:363 */
/*<       return >*/
    return 0;
/* SOURCE expcon.for:364 */
/*<       end >*/
} /* fndhpl_ */




/* SOURCE expcon.for:368 */
/*<       subroutinefrftrn(stdout,eflag,qfree,cntloc) >*/
/* Subroutine */ int frftrn_(integer *stdout, integer *eflag, real *qfree, 
	char *cntloc, ftnlen cntloc_len)
{
    /* Format strings */
    static char fmt_50[] = "(\0020*ERR:551 No control found for transition i\
n FRFTRN.\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    real fl, br, dq, qc, fr, qd, jr, ql, qr, tr, ald, dbr, dkr, dtr;
    integer feq_gen_flag_d_;
    real hpld, htld, hprd, qmax;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real alphad, dalpha;
    integer dnflag;
    extern /* Subroutine */ int fndhpl_(), regflt_(real *, real *, FeqCallback3, real 
	    *, real *, real *, real *, real *, integer *);
    extern doublereal frlres_(real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__56 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find free flow and upstream piezometric head at free flow. */
/*     also report the control location.  the upstream piezometric */
/*     head value, HPL, is in FECCOM. */
/* SOURCE expcon.for:377 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE expcon.for:380 */
/*<       integereflag,stdout >*/
/* SOURCE expcon.for:381 */
/*<       realqfree >*/
/* SOURCE expcon.for:382 */
/*<       charactercntloc*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     QFREE  - Free flow */
/*     CNTLOC - String giving location of critical control */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE expcon.for:391 */
/*     COMMON block for Finding Expansion-Contraction tables. */
/* SOURCE feccom.cmn:3 */
/*<       integerxtabl,xtabr,flg >*/
/* SOURCE feccom.cmn:5 */
/*<        >*/
/* SOURCE feccom.cmn:9 */
/*<        >*/
/* INCLUDE expcon.for:392 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE expcon.for:395 */
/*<       integerdnflag,flag,i >*/
/* SOURCE expcon.for:396 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE expcon.for:400 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE expcon.for:403 */
/*<       realfrlres >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE expcon.for:406 */
/*<       externalfndhpl,frlres,regflt,xlkt22 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE expcon.for:409 */
/*<    50 format('0*ERR:551 No control found for transition in FRFTRN.') >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' ENTERING FRFTRN: HPR=', HPR */
/*     RESERVOIRS AT R MUST BE TREATED SEPERATELY */
/* SOURCE expcon.for:415 */
/*<       if(xtabr.gt.0)then >*/
/* L50: */
    if (feccom_1.xtabr > 0) {
/*       CROSS SECTION PRESENT AT R */
/*       GET ELEMENTS FOR THE SECTION AT THE RIGHT. */
/* SOURCE expcon.for:420 */
/*<       yr=hpr+hdatum-zbr >*/
	feccom_1.yr = static_cast<double>(static_cast<double>(feccom_1.hpr) + feccom_1.hdatum) - feccom_1.zbr;
/* SOURCE expcon.for:421 */
/*<       callxlkt22(xtabr,yr,ar,tr,dtr,jr,kr,dkr,br,dbr,alphar,dalpha,qcr) >*/
	xlkt22_(&feccom_1.xtabr, &feccom_1.yr, &feccom_1.ar, &tr, &dtr, &jr, &
		feccom_1.kr, &dkr, &br, &dbr, &feccom_1.alphar, &dalpha, &
		feccom_1.qcr);
/*       TRY TO FIND SUBCRITICAL VALUE AT LEFT FOR CRITICAL FLOW AT */
/*       RIGHT SECTION */
/* SOURCE expcon.for:430 */
/*<       dnflag=0 >*/
	dnflag = 0;
/* SOURCE expcon.for:431 */
/*<       q=qcr >*/
	feccom_1.q = feccom_1.qcr;
/* SOURCE expcon.for:432 */
/*<       callfndhpl >*/
	fndhpl_();
/* SOURCE expcon.for:433 */
/*<       if(flg.eq.0)then >*/
	if (feccom_1.flg == 0) {
/*         SUBCRITICAL SOLUTION WAS FOUND. */
/*         CONTROL IS ON THE RIGHT AND WE HAVE A SOLUTION. */
/* SOURCE expcon.for:438 */
/*<       cntloc='  DN' >*/
	    s_copy(cntloc, const_cast<char*>("  DN"), (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:439 */
/*<       qfree=q >*/
	    *qfree = feccom_1.q;
/*         SAVE VALUES FOR LATER */
/* SOURCE expcon.for:441 */
/*<       hprd=hpr >*/
	    hprd = feccom_1.hpr;
/* SOURCE expcon.for:442 */
/*<       hpld=hpl >*/
	    hpld = feccom_1.hpl;
/* SOURCE expcon.for:443 */
/*<       alphad=alphal >*/
	    alphad = feccom_1.alphal;
/* SOURCE expcon.for:444 */
/*<       ald=al >*/
	    ald = feccom_1.al;
/* SOURCE expcon.for:445 */
/*<       htld=htl >*/
	    htld = feccom_1.htl;
/* SOURCE expcon.for:446 */
/*<       qd=q >*/
	    qd = feccom_1.q;
/* SOURCE expcon.for:447 */
/*<       dnflag=1 >*/
	    dnflag = 1;
/*         WRITE(STDOUT,*) ' CONTROL ON RIGHT: Q=',Q */
/* SOURCE expcon.for:449 */
/*<       else >*/
	} else {
/*         NO SOLUTION ASSUMING CONTROL ON THE RIGHT */
/*          WRITE(STDOUT,54) */
/* SOURCE expcon.for:452 */
/*<       endif >*/
	}
/*         WRITE(STDOUT,*) ' CHECK FOR CONTROL ON LEFT.' */
/*         SEARCH FOR SOLUTION AT OTHER END.  MAY BE MORE THAN ONE */
/*         CONTROL POINT. */
/*         SEARCH ON FLOW UNTIL WE HAVE */
/*         CLOSELY BRACKETED CRITICAL FLOW.  THEN USE REGULA FALSI */
/*         TO FIND THE CONDITIONS AT CRITICAL FLOW. */
/* SOURCE expcon.for:460 */
/*<       qmax=qcr >*/
	qmax = feccom_1.qcr;
/* SOURCE expcon.for:461 */
/*<       dq=qmax/64.0 >*/
	dq = static_cast<double>(qmax) / (float)64.;
/*         WRITE(STDOUT,*) ' QMAX=',QMAX,' DQ=',DQ */
/*         WE WILL START AT Q = 0.0 BECAUSE THE FROUDE NUMBER RESIDUAL */
/*         IS KNOWN TO BE 1.0. */
/* SOURCE expcon.for:466 */
/*<       ql=0.0 >*/
	ql = (float)0.;
/* SOURCE expcon.for:467 */
/*<       fl=1.0 >*/
	fl = (float)1.;
/*         SEARCH FOR A SUBCRITICAL SOLUTION */
/* SOURCE expcon.for:469 */
/*<       do100i=1,64 >*/
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 64; ++feq_gen_i_d_) {
/* SOURCE expcon.for:470 */
/*<       qr=ql+dq >*/
	    qr = static_cast<double>(ql) + dq;
/* SOURCE expcon.for:471 */
/*<       fr=frlres(qr) >*/
	    fr = frlres_(&qr);
/*           WRITE(STDOUT,*) 'FRFTRN  Q=',Q,' FR=',FR,' HPL=',HPL,' QCL=',QCL */
/* SOURCE expcon.for:473 */
/*<       if(fr*fl.le.0.0)goto105 >*/
	    if (static_cast<double>(fr) * fl <= (float)0.) {
		goto L105;
	    }
/* SOURCE expcon.for:474 */
/*<       ql=qr >*/
	    ql = qr;
/* SOURCE expcon.for:475 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE expcon.for:476 */
/*<   100 continue >*/
/* L100: */
	}
/*         WRITE(STDOUT,*) ' NO SIGN CHANGE FOUND IN SEARCH' */
/* SOURCE expcon.for:479 */
/*<       if(dnflag.eq.1)then >*/
	if (dnflag == 1) {
/*           SOLUTION DOWNSTREAM EXISTS */
/* SOURCE expcon.for:481 */
/*<       hpr=hprd >*/
	    feccom_1.hpr = hprd;
/* SOURCE expcon.for:482 */
/*<       hpl=hpld >*/
	    feccom_1.hpl = hpld;
/* SOURCE expcon.for:483 */
/*<       alphal=alphad >*/
	    feccom_1.alphal = alphad;
/* SOURCE expcon.for:484 */
/*<       al=ald >*/
	    feccom_1.al = ald;
/* SOURCE expcon.for:485 */
/*<       htl=htld >*/
	    feccom_1.htl = htld;
/* SOURCE expcon.for:486 */
/*<       q=qd >*/
	    feccom_1.q = qd;
/* SOURCE expcon.for:487 */
/*<       return >*/
	    return 0;
/* SOURCE expcon.for:488 */
/*<       else >*/
	} else {
/* SOURCE expcon.for:489 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__56.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__56);
	    e_wsfe();
/* SOURCE expcon.for:490 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE expcon.for:491 */
/*<       return >*/
	    return 0;
/* SOURCE expcon.for:492 */
/*<       endif >*/
	}
/* SOURCE expcon.for:493 */
/*<   105 continue >*/
L105:
/*         FOUND SIGN CHANGE.  SOLVE FOR THE CRITICAL CONDITION. */
/*          WRITE(STDOUT,60) QL, FL, QR, FR */
/* 60    FORMAT(' FRFTRN BEFORE REGFLT: QL=',F10.2,' FL=',F10.4, */
/*     A      ' QR=',F10.2,' FR=',F10.4) */
/* SOURCE expcon.for:500 */
/*<       callregflt(epsarg,epsf,frlres,ql,qr,fl,fr,qc,flag) >*/
	regflt_(&epscom_1.epsarg, &epscom_1.epsf, frlres_, &ql, &qr, &
		fl, &fr, &qc, &feq_gen_flag_d_);
/*         WRITE(STDOUT,62) QC, FL, QL, QR, FR */
/* 62    FORMAT(' FRFTRN AFTER REGFLT: QC=',F10.3,' F(QC)=',1PE10.3, */
/*     A        ' QL=',0PF10.3,' QR=',F10.3,' FR=',F10.3) */
/*         COMPARE THE RESULTS WITH THOSE OBTAINED, IF ANY, ASSUMING */
/*         CONTROL DOWNSTREAM.  TAKE THE SET WITH THE SMALLEST FLOW. */
/* SOURCE expcon.for:512 */
/*<       if(dnflag.eq.1)then >*/
	if (dnflag == 1) {
/* SOURCE expcon.for:513 */
/*<       if(qd.lt.q)then >*/
	    if (qd < feccom_1.q) {
/* SOURCE expcon.for:514 */
/*<       hpr=hprd >*/
		feccom_1.hpr = hprd;
/* SOURCE expcon.for:515 */
/*<       hpl=hpld >*/
		feccom_1.hpl = hpld;
/* SOURCE expcon.for:516 */
/*<       alphal=alphad >*/
		feccom_1.alphal = alphad;
/* SOURCE expcon.for:517 */
/*<       al=ald >*/
		feccom_1.al = ald;
/* SOURCE expcon.for:518 */
/*<       htl=htld >*/
		feccom_1.htl = htld;
/* SOURCE expcon.for:519 */
/*<       q=qd >*/
		feccom_1.q = qd;
/* SOURCE expcon.for:520 */
/*<       cntloc='  DN' >*/
		s_copy(cntloc, const_cast<char*>("  DN"), (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:521 */
/*<       return >*/
		return 0;
/* SOURCE expcon.for:522 */
/*<       endif >*/
	    }
/* SOURCE expcon.for:523 */
/*<       endif >*/
	}
/* SOURCE expcon.for:525 */
/*<       if(abs(fl).gt.0.01)then >*/
	if (dabs(fl) > (float).01) {
/* SOURCE expcon.for:526 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__59.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__59);
	    e_wsfe();
/* SOURCE expcon.for:527 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE expcon.for:528 */
/*<       return >*/
	    return 0;
/* SOURCE expcon.for:529 */
/*<       endif >*/
	}
/* SOURCE expcon.for:530 */
/*<       cntloc='  UP' >*/
	s_copy(cntloc, const_cast<char*>("  UP"), (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:531 */
/*<       qfree=qc >*/
	*qfree = qc;
/*        ENDIF */
/* SOURCE expcon.for:534 */
/*<       else >*/
    } else {
/*       RESERVOIR ON THE RIGHT.  SEEK VALUES USING SPECIAL METHOD */
/*       BECAUSE CRITICAL FLOW CAN ONLY OCCUR ON THE LEFT. */
/* SOURCE expcon.for:538 */
/*<       write(stdout,*)' CODE FOR RESERVOIR ON THE RIGHT NOT DONE YET.' >*/
	feq_gen_io_d__60.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__60);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CODE FOR RESERVOIR ON THE RIGHT NOT DONE YET."),
		 (ftnlen)46);
	e_wsle();
/* SOURCE expcon.for:539 */
/*<       write(stdout,*)' A LARGE CROSS SECTION ON RIGHT YIELDS THE SAME' >*/
	feq_gen_io_d__61.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__61);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" A LARGE CROSS SECTION ON RIGHT YIELDS THE SAME")
		, (ftnlen)47);
	e_wsle();
/* SOURCE expcon.for:540 */
/*<       write(stdout,*)' RESULTS AS A RESERVOIR ON THE RIGHT.' >*/
	feq_gen_io_d__62.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__62);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" RESULTS AS A RESERVOIR ON THE RIGHT."), (ftnlen)
		37);
	e_wsle();
/* SOURCE expcon.for:541 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE expcon.for:543 */
/*<       endif >*/
    }
/* SOURCE expcon.for:545 */
/*<       return >*/
    return 0;
/* SOURCE expcon.for:546 */
/*<       end >*/
} /* frftrn_ */




/* SOURCE expcon.for:550 */
/*<        >*/
/* Subroutine */ int fndect_(integer *stdout, integer *xtabu, real *zbu, 
	integer *xtabd, real *zbd, real *dxx, real *smth, real *tgmean, real *
	grv, real *kacc, real *kdec, integer *nhd, real *hdat, real *feq_storage_hdvec, 
	integer *nfrac, real *feq_storage_pfqvec, integer *eflag, real *feq_storage_hufvec, real *
	feq_storage_humat, real *feq_storage_qfvec)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002  Dwns piezometric head=\002,f10.4,\002 U\
ps head at\002,\002 free flow=\002,f10.4)";
    static char fmt_52[] = "(\002  Fraction   Upstream    Downstream      Fl\
ow\002,\002     Location  Sense\002,/,\002  of Free   Piezometric  Piezometr\
ic   through       \002,\002of      of\002,/,\002    Flow       Head        \
 Head      Transition  Control\002,\002   Flow\002)";
    static char fmt_54[] = "(\002 \002,1x,f7.4,2x,2x,f8.4,5x,f8.4,3x,3x,a8,1\
x,2x,a4,4x,1x,a4,3x,1x)";
    static char fmt_56[] = "(\002 Max. error in energy relative to energy lo\
ss=\002,1pe8.1,\002  at PFQ=\002,0pf10.4)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;
    char cq[8];
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen);
    real ebal, maxee, qfree;
    char qtype[4];
    extern doublereal ecechk_();
    extern /* Subroutine */ int fndhpl_();
    char cntloc[4];
    real maxpfq;
    extern /* Subroutine */ int frftrn_(integer *, integer *, real *, char *, 
	    ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__67 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__68 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a 2-d table for an expansion-contraction. */
/* SOURCE expcon.for:559 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE expcon.for:562 */
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
/* SOURCE expcon.for:565 */
/*<       integereflag,nfrac,nhd,stdout,xtabd,xtabu >*/
/* SOURCE expcon.for:566 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     XTABU  - Address of upstream cross section function table */
/*     ZBU    - Bottom elevation at upstream section */
/*     XTABD  - Address of downstream cross section function table */
/*     ZBD    - Bottom elevation at downstream section */
/*     DXX    - Length of the transition.  Used for boundary friction */
/*               estimates */
/*     SMTH   - Smoothing parameter for expansion and contraction */
/*              losses */
/*     TGMEAN - Generalized mean parameter */
/*     GRV    - value of acceleration due to gravity */
/*     KACC   - Loss coefficient when flow is accelerating */
/*     KDEC   - Loss coefficient when flow is decelerating */
/*     NHD    - Number of downstream heads */
/*     HDAT   - Datum for measuring head */
/*     HDVEC  - Vector of prescribed downstream heads */
/*     NFRAC  - Number of fractions for defining partial free flows */
/*     PFQVEC - Partial free flow vector */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     HUFVEC - Vector of computed upstream heads at free flow */
/*     HUMAT  - Matrix of computed upstream heads */
/*     QFVEC  - Free flow vector */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE expcon.for:595 */
/*     COMMON block for Finding Expansion-Contraction tables. */
/* SOURCE feccom.cmn:3 */
/*<       integerxtabl,xtabr,flg >*/
/* SOURCE feccom.cmn:5 */
/*<        >*/
/* SOURCE feccom.cmn:9 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE expcon.for:598 */
/*<       integeri,j >*/
/* SOURCE expcon.for:599 */
/*<       realebal,maxee,maxpfq,qfree >*/
/* SOURCE expcon.for:600 */
/*<       charactercntloc*4,qtype*4,cq*8 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE expcon.for:603 */
/*<       realecechk >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE expcon.for:606 */
/*<       externalecechk,fndhpl,frftrn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE expcon.for:609 */
/*<    50  >*/
/* SOURCE expcon.for:611 */
/*<    52  >*/
/* SOURCE expcon.for:617 */
/*<    54  >*/
/* SOURCE expcon.for:619 */
/*<    56  >*/
/* *********************************************************************** */
/*     ESTABLISH THE VALUES IN THE COMMON BLOCK WHICH REMAIN CONSTANT */
/* SOURCE expcon.for:624 */
/*<       grv2=2.*grv >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> qfvec(feq_storage_qfvec, 1);

    feq::IndexedPointer<real> humat(feq_storage_humat, 152);

    feq::IndexedPointer<real> hufvec(feq_storage_hufvec, 1);

    feq::IndexedPointer<real> pfqvec(feq_storage_pfqvec, 1);

    feq::IndexedPointer<real> hdvec(feq_storage_hdvec, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
    feccom_1.grv2 = static_cast<double>(*grv) * (float)2.;
/* SOURCE expcon.for:625 */
/*<       xtabl=xtabu >*/
    feccom_1.xtabl = *xtabu;
/* SOURCE expcon.for:626 */
/*<       xtabr=xtabd >*/
    feccom_1.xtabr = *xtabd;
/* SOURCE expcon.for:627 */
/*<       zbl=zbu >*/
    feccom_1.zbl = *zbu;
/* SOURCE expcon.for:628 */
/*<       zbr=zbd >*/
    feccom_1.zbr = *zbd;
/* SOURCE expcon.for:629 */
/*<       smooth=smth >*/
    feccom_1.smooth = *smth;
/* SOURCE expcon.for:630 */
/*<       dx=dxx >*/
    feccom_1.dx = *dxx;
/* SOURCE expcon.for:631 */
/*<       ka=kacc >*/
    feccom_1.ka = *kacc;
/* SOURCE expcon.for:632 */
/*<       kd=kdec >*/
    feccom_1.kd = *kdec;
/* SOURCE expcon.for:633 */
/*<       hdatum=hdat >*/
    feccom_1.hdatum = *hdat;
/* SOURCE expcon.for:634 */
/*<       tgm=tgmean >*/
    feccom_1.tgm = *tgmean;
/*     SET VALUES FOR RESERVOIRS */
/* SOURCE expcon.for:638 */
/*<       if(xtabl.eq.0)then >*/
    if (feccom_1.xtabl == 0) {
/* SOURCE expcon.for:639 */
/*<       alphal=0.0 >*/
	feccom_1.alphal = (float)0.;
/* SOURCE expcon.for:640 */
/*<       al=1.e10 >*/
	feccom_1.al = (float)1e10;
/* SOURCE expcon.for:641 */
/*<       endif >*/
    }
/* SOURCE expcon.for:642 */
/*<       if(xtabr.eq.0)then >*/
    if (feccom_1.xtabr == 0) {
/* SOURCE expcon.for:643 */
/*<       alphar=0.0 >*/
	feccom_1.alphar = (float)0.;
/* SOURCE expcon.for:644 */
/*<       ar=1.e10 >*/
	feccom_1.ar = (float)1e10;
/* SOURCE expcon.for:645 */
/*<       endif >*/
    }
/* SOURCE expcon.for:647 */
/*<       do2000i=1,nhd >*/
    feq_gen_i_d_1 = *nhd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       INITIALIZE THE MAXIMUM ENERGY ERROR VALUE */
/* SOURCE expcon.for:651 */
/*<       maxee=-1.0 >*/
	maxee = (float)-1.;
/* SOURCE expcon.for:653 */
/*<       hpr=hdvec(i) >*/
	feccom_1.hpr = hdvec[feq_gen_i_d_];
/*       COMPUTE FREE FLOW AND UPSTREAM HEAD THROUGH THE TRANSITION */
/* SOURCE expcon.for:657 */
/*<       callfrftrn(stdout,eflag,qfree,cntloc) >*/
	frftrn_(stdout, eflag, &qfree, cntloc, (ftnlen)4);
/* SOURCE expcon.for:662 */
/*<       if(eflag.ne.0)then >*/
	if (*eflag != 0) {
/* SOURCE expcon.for:663 */
/*<       return >*/
	    return 0;
/* SOURCE expcon.for:664 */
/*<       endif >*/
	}
/*       FOR EACH OF THE PARTIAL FREE FLOWS(EXCLUDING 0.00 AND 1.0) */
/*       COMPUTE THE UPSTREAM PIEZOMETRIC HEAD */
/* SOURCE expcon.for:668 */
/*<       write(stdout,50)hpr,hpl >*/
	feq_gen_io_d__67.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__67);
	do_fio(&feq_gen_c_d_1, (char *)&feccom_1.hpr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feccom_1.hpl, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE expcon.for:671 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__68.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__68);
	e_wsfe();
/* SOURCE expcon.for:673 */
/*<       if(alphal/al**2.gt.alphar/ar**2)then >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = feccom_1.al;
/* Computing 2nd power */
	feq_gen_r_d_2 = feccom_1.ar;
	if (static_cast<double>(feccom_1.alphal) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) > static_cast<double>(feccom_1.alphar) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))
		 {
/* SOURCE expcon.for:674 */
/*<       qtype=' EXP' >*/
	    s_copy(qtype, const_cast<char*>(" EXP"), (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:675 */
/*<       else >*/
	} else {
/* SOURCE expcon.for:676 */
/*<       qtype=' CON' >*/
	    s_copy(qtype, const_cast<char*>(" CON"), (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:677 */
/*<       endif >*/
	}
/* SOURCE expcon.for:678 */
/*<       ebal=ecechk() >*/
	ebal = ecechk_();
/* SOURCE expcon.for:679 */
/*<       if(ebal.gt.maxee)then >*/
	if (ebal > maxee) {
/* SOURCE expcon.for:680 */
/*<       maxee=ebal >*/
	    maxee = ebal;
/* SOURCE expcon.for:681 */
/*<       maxpfq=pfqvec(nfrac) >*/
	    maxpfq = pfqvec[*nfrac];
/* SOURCE expcon.for:682 */
/*<       endif >*/
	}
/* SOURCE expcon.for:683 */
/*<       callvar_decimal(qfree,cq) >*/
	feq_gen_var_decimal_d_(&qfree, cq, (ftnlen)8);
/* SOURCE expcon.for:685 */
/*<       write(stdout,54)pfqvec(nfrac),hpl,hpr,cq,cntloc,qtype >*/
	feq_gen_io_d__73.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__73);
	do_fio(&feq_gen_c_d_1, (char *)&pfqvec[*nfrac], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feccom_1.hpl, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feccom_1.hpr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, cntloc, (ftnlen)4);
	do_fio(&feq_gen_c_d_1, qtype, (ftnlen)4);
	e_wsfe();
/* SOURCE expcon.for:687 */
/*<       cntloc='BOTH' >*/
	s_copy(cntloc, const_cast<char*>("BOTH"), (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:689 */
/*<       humat(i,1)=hpr >*/
	humat[feq_gen_i_d_ + 151] = feccom_1.hpr;
/* SOURCE expcon.for:690 */
/*<       humat(i,nfrac)=hpl >*/
	humat[feq_gen_i_d_ + *nfrac * 151] = feccom_1.hpl;
/* SOURCE expcon.for:691 */
/*<       hufvec(i)=hpl >*/
	hufvec[feq_gen_i_d_] = feccom_1.hpl;
/* SOURCE expcon.for:692 */
/*<       qfvec(i)=qfree >*/
	qfvec[feq_gen_i_d_] = qfree;
/* SOURCE expcon.for:694 */
/*<       do500j=nfrac-1,2,-1 >*/
	for (j = *nfrac - 1; j >= 2; --j) {
/* SOURCE expcon.for:695 */
/*<       q=qfree*pfqvec(j) >*/
	    feccom_1.q = static_cast<double>(qfree) * pfqvec[j];
/* SOURCE expcon.for:697 */
/*<       if(xtabr.gt.0)then >*/
	    if (feccom_1.xtabr > 0) {
/*           CROSS SECTION EXISTS AT R */
/* SOURCE expcon.for:699 */
/*<       callfndhpl >*/
		fndhpl_();
/* SOURCE expcon.for:701 */
/*<       else >*/
	    } else {
/*           NO CROSS SECTION EXISTS AT R. RESERVOIR ON THE RIGHT. */
/* SOURCE expcon.for:703 */
/*<       write(stdout,*)' RESERVOIR ON RIGHT NOT YET DONE.' >*/
		feq_gen_io_d__75.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__75);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" RESERVOIR ON RIGHT NOT YET DONE."), (
			ftnlen)33);
		e_wsle();
/* SOURCE expcon.for:704 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE expcon.for:705 */
/*<       endif >*/
	    }
/* SOURCE expcon.for:706 */
/*<       if(alphal/al**2.gt.alphar/ar**2)then >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = feccom_1.al;
/* Computing 2nd power */
	    feq_gen_r_d_2 = feccom_1.ar;
	    if (static_cast<double>(feccom_1.alphal) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) > static_cast<double>(feccom_1.alphar) / (static_cast<double>(feq_gen_r_d_2) * 
		    feq_gen_r_d_2)) {
/* SOURCE expcon.for:707 */
/*<       qtype=' EXP' >*/
		s_copy(qtype, const_cast<char*>(" EXP"), (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:708 */
/*<       else >*/
	    } else {
/* SOURCE expcon.for:709 */
/*<       qtype=' CON' >*/
		s_copy(qtype, const_cast<char*>(" CON"), (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:710 */
/*<       endif >*/
	    }
/* SOURCE expcon.for:711 */
/*<       ebal=ecechk() >*/
	    ebal = ecechk_();
/* SOURCE expcon.for:712 */
/*<       if(ebal.gt.maxee)then >*/
	    if (ebal > maxee) {
/* SOURCE expcon.for:713 */
/*<       maxee=ebal >*/
		maxee = ebal;
/* SOURCE expcon.for:714 */
/*<       maxpfq=pfqvec(j) >*/
		maxpfq = pfqvec[j];
/* SOURCE expcon.for:715 */
/*<       endif >*/
	    }
/* SOURCE expcon.for:716 */
/*<       callvar_decimal(q,cq) >*/
	    feq_gen_var_decimal_d_(&feccom_1.q, cq, (ftnlen)8);
/* SOURCE expcon.for:718 */
/*<       write(stdout,54)pfqvec(j),hpl,hpr,cq,cntloc,qtype >*/
	    feq_gen_io_d__76.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__76);
	    do_fio(&feq_gen_c_d_1, (char *)&pfqvec[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feccom_1.hpl, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feccom_1.hpr, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, cntloc, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, qtype, (ftnlen)4);
	    e_wsfe();
/* SOURCE expcon.for:719 */
/*<       humat(i,j)=hpl >*/
	    humat[feq_gen_i_d_ + j * 151] = feccom_1.hpl;
/* SOURCE expcon.for:721 */
/*<   500 continue >*/
/* L500: */
	}
/* SOURCE expcon.for:723 */
/*<       write(stdout,56)maxee,maxpfq >*/
	feq_gen_io_d__77.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__77);
	do_fio(&feq_gen_c_d_1, (char *)&maxee, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&maxpfq, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE expcon.for:725 */
/*<  2000 continue >*/
/* L2000: */
    }
/* SOURCE expcon.for:727 */
/*<       return >*/
    return 0;
/* SOURCE expcon.for:728 */
/*<       end >*/
} /* fndect_ */




/* SOURCE expcon.for:732 */
/*<        >*/
/* Subroutine */ int feq_gen_read_expcon_items1_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	eflag, integer *idlen, char *char4, integer *xtab, real *x, real *zb, 
	ftnlen line_len, ftnlen char4_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:741* Only \002,i3,\002 items given \
in \002,\002EXPCON-1 description line.  Need at least four items.\002)";

    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi()
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
    static cilist feq_gen_io_d__78 = { 0, 0, 0, fmt_50, 0 };


/*     Get the items of data from the first set of EXPCON input */
/* SOURCE expcon.for:740 */
/*<       implicitnone >*/
/* SOURCE expcon.for:741 */
/*<        >*/
/* SOURCE expcon.for:743 */
/*<       realx,zb >*/
/* SOURCE expcon.for:744 */
/*<       characterline*(*),char4*4 >*/
/*     Local */
/* SOURCE expcon.for:748 */
/*<       integerie,is,itab,lkey,n >*/
/* SOURCE expcon.for:749 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE expcon.for:752 */
/*<       integernonblank_nonzero,lenstr >*/
/* SOURCE expcon.for:753 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE expcon.for:756 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE expcon.for:760 */
/*<       if(nitem.lt.4)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
    if (*nitem < 4) {
/* SOURCE expcon.for:761 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__78.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__78);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE expcon.for:762 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE expcon.for:763 */
/*<       endif >*/
    }
/* SOURCE expcon.for:765 */
/*<       n=1 >*/
    n = 1;
/*     Process the location */
/* SOURCE expcon.for:767 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:768 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:769 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE expcon.for:770 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE expcon.for:772 */
/*<       char4=tpc >*/
    s_copy(char4, tpc, (ftnlen)4, (ftnlen)20);
/*     Process the table id */
/* SOURCE expcon.for:775 */
/*<       n=2 >*/
    n = 2;
/* SOURCE expcon.for:776 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:777 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:778 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE expcon.for:779 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE expcon.for:781 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE expcon.for:782 */
/*<       lkey=lenstr(key) >*/
    lkey = lenstr_(key, (ftnlen)16);
/* SOURCE expcon.for:783 */
/*<       idlen=max(idlen,lkey) >*/
    *idlen = max(*idlen,lkey);
/*     Convert from the table id to an internal number. */
/* SOURCE expcon.for:785 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE expcon.for:786 */
/*<       callget_internal_tab_number(stdout,key,eflag,itab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &itab, (ftnlen)16);
/* SOURCE expcon.for:790 */
/*<       xtab=itab >*/
	*xtab = itab;
/* SOURCE expcon.for:791 */
/*<       else >*/
    } else {
/* SOURCE expcon.for:792 */
/*<       xtab=0 >*/
	*xtab = 0;
/* SOURCE expcon.for:793 */
/*<       endif >*/
    }
/*     Process the station */
/* SOURCE expcon.for:796 */
/*<       n=3 >*/
    n = 3;
/* SOURCE expcon.for:797 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:798 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:799 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE expcon.for:800 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE expcon.for:802 */
/*<       read(tpc,'(F10.0)')x >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*x), (ftnlen)sizeof(real));
    e_rsfi();
/*     Process the invert elevation */
/* SOURCE expcon.for:805 */
/*<       n=4 >*/
    n = 4;
/* SOURCE expcon.for:806 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:807 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:808 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE expcon.for:809 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE expcon.for:811 */
/*<       read(tpc,'(F10.0)')zb >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*zb), (ftnlen)sizeof(real));
    e_rsfi();
/* SOURCE expcon.for:813 */
/*<       return >*/
    return 0;
/* SOURCE expcon.for:814 */
/*<       end >*/
} /* read_expcon_items1__ */




/* SOURCE expcon.for:818 */
/*<        >*/
/* Subroutine */ int feq_gen_read_expcon_items2_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	eflag, integer *idlen, char *char4, integer *tab, real *kacc, real *
	kdec, char *lab, ftnlen line_len, ftnlen char4_len, ftnlen lab_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:742* Only \002,i3,\002 items given \
in \002,\002EXPCON-2 description line.  Need at least five items.\002)";

    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi()
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
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_50, 0 };


/*     Get the items of data from the second set of EXPCON input */
/* SOURCE expcon.for:826 */
/*<       implicitnone >*/
/* SOURCE expcon.for:827 */
/*<        >*/
/* SOURCE expcon.for:829 */
/*<       realkacc,kdec >*/
/* SOURCE expcon.for:830 */
/*<       characterline*(*),char4*4,lab*50 >*/
/*     Local */
/* SOURCE expcon.for:834 */
/*<       integerie,is,itab,lkey,n >*/
/* SOURCE expcon.for:835 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE expcon.for:838 */
/*<       integernonblank_nonzero,lenstr >*/
/* SOURCE expcon.for:839 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE expcon.for:842 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE expcon.for:846 */
/*<       if(nitem.lt.5)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
    if (*nitem < 5) {
/* SOURCE expcon.for:847 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__86.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__86);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE expcon.for:848 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE expcon.for:849 */
/*<       endif >*/
    }
/* SOURCE expcon.for:851 */
/*<       n=1 >*/
    n = 1;
/*     Process the direction */
/* SOURCE expcon.for:853 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:854 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:855 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE expcon.for:856 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE expcon.for:858 */
/*<       char4=tpc >*/
    s_copy(char4, tpc, (ftnlen)4, (ftnlen)20);
/*     Process the table id */
/* SOURCE expcon.for:861 */
/*<       n=2 >*/
    n = 2;
/* SOURCE expcon.for:862 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:863 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:864 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE expcon.for:865 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE expcon.for:867 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE expcon.for:868 */
/*<       lkey=lenstr(key) >*/
    lkey = lenstr_(key, (ftnlen)16);
/* SOURCE expcon.for:869 */
/*<       idlen=max(idlen,lkey) >*/
    *idlen = max(*idlen,lkey);
/*     Convert from the table id to an internal number. */
/* SOURCE expcon.for:871 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE expcon.for:872 */
/*<       callget_internal_tab_number(stdout,key,eflag,itab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &itab, (ftnlen)16);
/* SOURCE expcon.for:876 */
/*<       tab=itab >*/
	*tab = itab;
/* SOURCE expcon.for:877 */
/*<       else >*/
    } else {
/* SOURCE expcon.for:878 */
/*<       tab=0 >*/
	*tab = 0;
/* SOURCE expcon.for:879 */
/*<       endif >*/
    }
/*     Process the the acceleration loss */
/* SOURCE expcon.for:882 */
/*<       n=3 >*/
    n = 3;
/* SOURCE expcon.for:883 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:884 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:885 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE expcon.for:886 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE expcon.for:888 */
/*<       read(tpc,'(F10.0)')kacc >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*kacc), (ftnlen)sizeof(real));
    e_rsfi();
/*     Process the deceleration loss */
/* SOURCE expcon.for:891 */
/*<       n=4 >*/
    n = 4;
/* SOURCE expcon.for:892 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:893 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:894 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE expcon.for:895 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE expcon.for:897 */
/*<       read(tpc,'(F10.0)')kdec >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*kdec), (ftnlen)sizeof(real));
    e_rsfi();
/*     Process the label */
/* SOURCE expcon.for:900 */
/*<       n=5 >*/
    n = 5;
/* SOURCE expcon.for:901 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE expcon.for:902 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE expcon.for:903 */
/*<       lab=line(is:ie) >*/
    s_copy(lab, line + (is - 1), (ftnlen)50, ie - (is - 1));
/* SOURCE expcon.for:904 */
/*<       callstrip_l_blanks(lab) >*/
    feq_gen_strip_l_blanks_d_(lab, (ftnlen)50);
/* SOURCE expcon.for:907 */
/*<       return >*/
    return 0;
/* SOURCE expcon.for:908 */
/*<       end >*/
} /* read_expcon_items2__ */




/* SOURCE expcon.for:912 */
/*<       subroutineexpcon(stdin,stdout,stdtab,grv,tabdir,eflag) >*/
/* Subroutine */ int expcon_(integer *stdin, integer *stdout, integer *stdtab,
	 real *grv, integer *feq_storage_tabdir, integer *eflag)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;

    /* Format strings */
    static char fmt_4[] = "(7x,f10.0)";
    static char fmt_5[] = "(6x,f10.0)";
    static char fmt_16[] = "(a5,1x,f10.0)";
    static char fmt_24[] = "(a80)";
    static char fmt_26[] = "(a5,1x,i5)";
    static char fmt_50[] = "(\002 \002,a80)";
    static char fmt_52[] = "(\002 \002,a4,a,f5.0,f10.2)";
    static char fmt_54[] = "(\002 \002,a4,a,2f5.2,1x,a50)";
    static char fmt_56[] = "(\002 SMOOTH=\002,f10.5)";
    static char fmt_57[] = "(\002 GENERALIZED MEAN VALUE PARAMETER=\002,f10.\
2,/,\002  MEAN VALUE IS THEREFORE:\002)";
    static char fmt_66[] = "(\002 \002,a5,\002=\002,f10.2)";
    static char fmt_70[] = "(/,\002 *ERR:618* Upstream section out of order \
in EXPCON.\002)";
    static char fmt_71[] = "(/,\002 *ERR:619* Downstream section ouf of orde\
r in EXPCON.\002)";
    static char fmt_72[] = "(/,\002 *ERR:620* Loss coefficient < 0 or > 1\
:\002,f8.3)";
    static char fmt_74[] = "(/,\002 *ERR:621* U to D coefficients and table \
not first.\002)";
    static char fmt_75[] = "(/,\002 *ERR:622* D to U coefficients and table \
not second.\002)";
    static char fmt_76[] = "(/,\002  Transition length is zero.  Boundary fr\
iction\002,\002 losses ignored.\002)";
    static char fmt_78[] = "(/,\002 COMPUTING TABLE FOR FLOW UP -> DOWN\002)";
    static char fmt_80[] = "(/,\002 COMPUTING TABLE FOR FLOW DOWN -> UP\002)";
    static char fmt_82[] = "(/,\002 *ERR:623* EXPCON requires at least one c\
ross section.\002,\002  None were found.\002)";
    static char fmt_88[] = "(/,\002 Checking cross section tables for possib\
le critical\002,\002 flow\002,/,5x,\002 or celerity problems.\002)";
    static char fmt_89[] = "(/,\002 *WRN:550* EXPCON command may not converg\
e because\002,\002 critical\002,/,10x,\002 flow/celerity decreases in TabId= \
\002,a)";
    static char fmt_90[] = "(\002  Processing EXPCON TabIds= \002,a,\002 a\
nd \002,a)";
    static char fmt_92[] = "(/,\002 \002,a80)";
    static char fmt_94[] = "(/,\002 \002,a5,\002=\002,i5)";
    static char fmt_95[] = "(/,\002 \002,\002INPUT COMPLETE. BEGIN COMPUTATI\
ONS\002)";
    static char fmt_96[] = "(/,\002 \002,\002DATUM FOR HEADS IS:\002,f10.2)";
    static char fmt_98[] = "(/,\002 *WRN:519* Free flow=\002,f10.3,\002 decr\
eases at downstream\002,\002 head=\002,f10.4)";
    static char fmt_99[] = "(/,\002 *ERR:624* DOWNSTREAM HEADS NON-INCREASIN\
G AT:\002,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[4], feq_gen_ch_d_3[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    double pow_dd(doublereal *, doublereal *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_item_end_d_[5];
    doublereal eastingl;
    integer colwidth;
    doublereal eastingr, northing;
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal northingl, northingr;
    real dx, xl, xr;
    extern /* Subroutine */ int feq_gen_read_expcon_items1_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, char *, 
	    integer *, real *, real *, ftnlen, ftnlen), feq_gen_read_expcon_items2_d_(
	    integer *, char *, integer *, integer *, integer *, integer *, 
	    integer *, char *, integer *, real *, real *, char *, ftnlen, 
	    ftnlen, ftnlen);
    integer feq_gen_item_start_d_[5], nhd;
    real zbl, zbr;
    char head[80];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char line[80];
    real qold;
    char zone[8];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char just[5], char4[4], char5[5], tabid[16], labdu[50];
    integer nfrac;
    real hdold;
    integer idlen;
    real hdvec[151];
    char labud[50];
    integer dutab, udtab, wflag;
    real qfvec[151];
    integer xtabl, xtabr, nitem;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_humat(53001);
    real *humat = feq_heap_humat.data()	/* was [151][351] */;
    char idout[32], hgrid[8];
    real power;
    char basis[8];
    extern /* Subroutine */ int chkcfc_(real *, integer *, integer *, integer 
	    *);
    char tabidd[16];
    real kaccdu, kaccud;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    real kdecdu, kdecud;
    extern /* Subroutine */ int tabchk_(integer *, integer *, integer *, 
	    integer *, integer *), fndect_(integer *, integer *, real *, 
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     integer *, real *, real *, integer *, real *, integer *, real *, 
	    real *, real *);
    char tabidu[16];
    real tgmean, hufvec[151], hdatum;
    extern integer gettbn_(integer *);
    real pfqvec[351];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    integer tabtyp;
    real smooth, zrhufd;
    char vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int twdout_(integer *, integer *, integer *, char 
	    *, integer *, integer *, real *, real *, real *, real *, real *, 
	    integer *, char *, real *, char *, char *, char *, char *, char *,
	     doublereal *, doublereal *, integer *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), feq_gen_get_lctn_items_d_(integer *, 
	    integer *, integer *), feq_gen_get_east_north_d_(integer *, integer *, 
	    doublereal *, doublereal *), feq_gen_set_lctn_items_d_(char *, char *, 
	    char *, char *, char *, doublereal *, doublereal *, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen);
    doublereal easting;
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__123 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__127 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__128 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__139 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__140 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__150 = { 0, 6, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__158 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__159 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__160 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__166 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__168 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__174 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__175 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__177 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__178 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__185 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__193 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__195 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__198 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a two-d table for flow through an expansion-contraction. */
/*     use the table with downstream piezometric head and flow as */
/*     argument.  The table gives the upstream piezometric head. */
/* SOURCE expcon.for:922 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE expcon.for:924 */
/*<       integereflag,stdin,stdout,stdtab >*/
/* SOURCE expcon.for:925 */
/*<       integertabdir(*) >*/
/* SOURCE expcon.for:926 */
/*<       realgrv >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     GRV    - value of acceleration due to gravity */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE expcon.for:937 */
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
/* INCLUDE expcon.for:938 */
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
/* SOURCE expcon.for:941 */
/*<       integermaxn >*/
/* SOURCE expcon.for:942 */
/*<       parameter(maxn=5) >*/
/* SOURCE expcon.for:943 */
/*<        >*/
/* SOURCE expcon.for:945 */
/*<        >*/
/* SOURCE expcon.for:949 */
/*<       real*8easting,northing,dnull,eastingl,northingl,eastingr,northingr >*/
/* SOURCE expcon.for:951 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE expcon.for:956 */
/*<       intrinsicabs,float,max >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE expcon.for:959 */
/*<       integergettbn,lenstr >*/
/* SOURCE expcon.for:960 */
/*<       charactergettok*4,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE expcon.for:963 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE expcon.for:967 */
/*<       datadnull/-33d6/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* SOURCE expcon.for:970 */
/*<     1 format(a4,i5,f5.0,f10.0) >*/
/* L1: */
/* SOURCE expcon.for:971 */
/*<     2 format(a4,i5,2f5.0,1x,a50) >*/
/* L2: */
/* SOURCE expcon.for:972 */
/*<     4 format(7x,f10.0) >*/
/* L4: */
/* SOURCE expcon.for:973 */
/*<     5 format(6x,f10.0) >*/
/* L5: */
/* SOURCE expcon.for:974 */
/*<    16 format(a5,1x,f10.0) >*/
/* L16: */
/* SOURCE expcon.for:975 */
/*<    24 format(a80) >*/
/* L24: */
/* SOURCE expcon.for:976 */
/*<    26 format(a5,1x,i5) >*/
/* L26: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE expcon.for:979 */
/*<    50 format(' ',a80) >*/
/* L50: */
/* SOURCE expcon.for:980 */
/*<    52 format(' ',a4,a,f5.0,f10.2) >*/
/* L52: */
/* SOURCE expcon.for:981 */
/*<    54 format(' ',a4,a,2f5.2,1x,a50) >*/
/* L54: */
/* SOURCE expcon.for:982 */
/*<    56 format(' SMOOTH=',f10.5) >*/
/* L56: */
/* SOURCE expcon.for:983 */
/*<    57  >*/
/* L57: */
/* SOURCE expcon.for:985 */
/*<    66 format(' ',a5,'=',f10.2) >*/
/* L66: */
/* SOURCE expcon.for:986 */
/*<    70 format(/,' *ERR:618* Upstream section out of order in EXPCON.') >*/
/* L70: */
/* SOURCE expcon.for:987 */
/*<    71 format(/,' *ERR:619* Downstream section ouf of order in EXPCON.') >*/
/* L71: */
/* SOURCE expcon.for:988 */
/*<    72 format(/,' *ERR:620* Loss coefficient < 0 or > 1:',f8.3) >*/
/* L72: */
/* SOURCE expcon.for:989 */
/*<    74 format(/,' *ERR:621* U to D coefficients and table not first.') >*/
/* L74: */
/* SOURCE expcon.for:990 */
/*<    75 format(/,' *ERR:622* D to U coefficients and table not second.') >*/
/* L75: */
/* SOURCE expcon.for:991 */
/*<    76  >*/
/* L76: */
/* SOURCE expcon.for:993 */
/*<    78 format(/,' COMPUTING TABLE FOR FLOW UP -> DOWN') >*/
/* L78: */
/* SOURCE expcon.for:994 */
/*<    80 format(/,' COMPUTING TABLE FOR FLOW DOWN -> UP') >*/
/* L80: */
/* SOURCE expcon.for:995 */
/*<    82  >*/
/* L82: */
/* SOURCE expcon.for:997 */
/*<    88  >*/
/* L88: */
/* SOURCE expcon.for:999 */
/*<    89  >*/
/* L89: */
/* SOURCE expcon.for:1002 */
/*<    90 format('  Processing EXPCON TabIds= ',a,' and ',a) >*/
/* L90: */
/* SOURCE expcon.for:1003 */
/*<    92 format(/,' ',a80) >*/
/* L92: */
/* SOURCE expcon.for:1004 */
/*<    94 format(/,' ',a5,'=',i5) >*/
/* L94: */
/* SOURCE expcon.for:1005 */
/*<    95 format(/,' ','INPUT COMPLETE. BEGIN COMPUTATIONS') >*/
/* L95: */
/* SOURCE expcon.for:1006 */
/*<    96 format(/,' ','DATUM FOR HEADS IS:',f10.2) >*/
/* L96: */
/* SOURCE expcon.for:1007 */
/*<    98  >*/
/* L98: */
/* SOURCE expcon.for:1009 */
/*<    99 format(/,' *ERR:624* DOWNSTREAM HEADS NON-INCREASING AT:',f10.2) >*/
/* L99: */
/* *********************************************************************** */
/* SOURCE expcon.for:1011 */
/*<       tabtyp=14 >*/
    tabtyp = 14;
/* SOURCE expcon.for:1012 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE expcon.for:1017 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE expcon.for:1019 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     INPUT THE BASIC DATA FROM USER. */
/* SOURCE expcon.for:1024 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1027 */
/*<       read(line,24)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_rsfi();
/* SOURCE expcon.for:1028 */
/*<       write(stdout,50)head >*/
    feq_gen_io_d__109.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__109);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE expcon.for:1029 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1032 */
/*<       read(line,24)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_rsfi();
/* SOURCE expcon.for:1033 */
/*<       write(stdout,50)head >*/
    feq_gen_io_d__110.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__110);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE expcon.for:1034 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, head, &feq_gen_c_d_5, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)80, (ftnlen)5);
/*     Set the  column width */
/* SOURCE expcon.for:1039 */
/*<       colwidth=item_end(2)-item_start(2)+1 >*/
    colwidth = feq_gen_item_end_d_[1] - feq_gen_item_start_d_[1] + 1;
/*     INPUT THE UPSTREAM TABLE INFORMATION */
/* SOURCE expcon.for:1042 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1045 */
/*<       idlen=0 >*/
    idlen = 0;
/* SOURCE expcon.for:1046 */
/*<        >*/
    feq_gen_read_expcon_items1_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, 
	    eflag, &idlen, char4, &xtabl, &xl, &zbl, (ftnlen)80, (ftnlen)4);
/* SOURCE expcon.for:1052 */
/*<       tabid=get_tabid(xtabl) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &xtabl);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE expcon.for:1053 */
/*<       idout=' ' >*/
    s_copy(idout, const_cast<char*>(" "), (ftnlen)32, (ftnlen)1);
/* SOURCE expcon.for:1054 */
/*<       idout(colwidth-idlen+1:colwidth)=tabid(1:idlen) >*/
    feq_gen_i_d_1 = colwidth - idlen;
    s_copy(idout + feq_gen_i_d_1, tabid, colwidth - feq_gen_i_d_1, idlen);
/* SOURCE expcon.for:1055 */
/*<       write(stdout,52)char4,idout(1:colwidth),xl,zbl >*/
    feq_gen_io_d__122.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__122);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, idout, colwidth);
    do_fio(&feq_gen_c_d_1, (char *)&xl, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&zbl, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE expcon.for:1056 */
/*<       char4=gettok(char4) >*/
    gettok_(feq_gen_ch_d_2, (ftnlen)4, char4, (ftnlen)4);
    s_copy(char4, feq_gen_ch_d_2, (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:1057 */
/*<       if(char4.ne.'UP')then >*/
    if (s_cmp(char4, const_cast<char*>("UP"), (ftnlen)4, (ftnlen)2) != 0) {
/* SOURCE expcon.for:1058 */
/*<       write(stdout,70) >*/
	feq_gen_io_d__123.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__123);
	e_wsfe();
/* SOURCE expcon.for:1059 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE expcon.for:1060 */
/*<       else >*/
    } else {
/*       CHECK THE TABLE FOR EXISTENCE */
/* SOURCE expcon.for:1062 */
/*<       callchktab(12,stdout,ftpnt,mftnum,xtabl,eflag) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &xtabl, eflag);
/* SOURCE expcon.for:1066 */
/*<       endif >*/
    }
/*     INPUT THE DOWNSTREAM TABLE INFORMATION */
/* SOURCE expcon.for:1069 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1072 */
/*<       idlen=0 >*/
    idlen = 0;
/* SOURCE expcon.for:1073 */
/*<        >*/
    feq_gen_read_expcon_items1_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, 
	    eflag, &idlen, char4, &xtabr, &xr, &zbr, (ftnlen)80, (ftnlen)4);
/* SOURCE expcon.for:1078 */
/*<       tabid=get_tabid(xtabr) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &xtabr);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE expcon.for:1079 */
/*<       idout=' ' >*/
    s_copy(idout, const_cast<char*>(" "), (ftnlen)32, (ftnlen)1);
/* SOURCE expcon.for:1080 */
/*<       idout(colwidth-idlen+1:colwidth)=tabid(1:idlen) >*/
    feq_gen_i_d_1 = colwidth - idlen;
    s_copy(idout + feq_gen_i_d_1, tabid, colwidth - feq_gen_i_d_1, idlen);
/* SOURCE expcon.for:1081 */
/*<       write(stdout,52)char4,idout(1:colwidth),xr,zbr >*/
    feq_gen_io_d__127.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__127);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, idout, colwidth);
    do_fio(&feq_gen_c_d_1, (char *)&xr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&zbr, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE expcon.for:1082 */
/*<       char4=gettok(char4) >*/
    gettok_(feq_gen_ch_d_2, (ftnlen)4, char4, (ftnlen)4);
    s_copy(char4, feq_gen_ch_d_2, (ftnlen)4, (ftnlen)4);
/* SOURCE expcon.for:1083 */
/*<       if(char4.eq.'DN'.or.char4.eq.'DOWN')then >*/
    if (s_cmp(char4, const_cast<char*>("DN"), (ftnlen)4, (ftnlen)2) == 0 || s_cmp(char4, const_cast<char*>("DOWN"), 
	    (ftnlen)4, (ftnlen)4) == 0) {
/*       CHECK THE TABLE FOR EXISTENCE */
/* SOURCE expcon.for:1085 */
/*<       callchktab(12,stdout,ftpnt,mftnum,xtabr,eflag) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &xtabr, eflag);
/* SOURCE expcon.for:1089 */
/*<       else >*/
    } else {
/* SOURCE expcon.for:1090 */
/*<       write(stdout,71) >*/
	feq_gen_io_d__128.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__128);
	e_wsfe();
/* SOURCE expcon.for:1091 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE expcon.for:1092 */
/*<       endif >*/
    }
/*     MAKE SURE THAT AT LEAST ONE CROSS SECTION EXISTS */
/* SOURCE expcon.for:1095 */
/*<       if(xtabl.eq.0.and.xtabr.eq.0)then >*/
    if (xtabl == 0 && xtabr == 0) {
/* SOURCE expcon.for:1096 */
/*<       write(stdout,82) >*/
	feq_gen_io_d__129.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__129);
	e_wsfe();
/* SOURCE expcon.for:1097 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE expcon.for:1098 */
/*<       endif >*/
    }
/*     INPUT THE COEFFICIENT AND OUTPUT TABLES */
/* SOURCE expcon.for:1101 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1104 */
/*<       read(line,24)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_rsfi();
/* SOURCE expcon.for:1105 */
/*<       write(stdout,50)head >*/
    feq_gen_io_d__130.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__130);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE expcon.for:1106 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1109 */
/*<       read(line,24)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_rsfi();
/* SOURCE expcon.for:1110 */
/*<       write(stdout,50)head >*/
    feq_gen_io_d__131.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__131);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE expcon.for:1111 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, head, &feq_gen_c_d_5, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)80, (ftnlen)5);
/*     Set the  column width */
/* SOURCE expcon.for:1115 */
/*<       colwidth=item_end(2)-item_start(2)+1 >*/
    colwidth = feq_gen_item_end_d_[1] - feq_gen_item_start_d_[1] + 1;
/* SOURCE expcon.for:1116 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1119 */
/*<       idlen=0 >*/
    idlen = 0;
/* SOURCE expcon.for:1120 */
/*<        >*/
    feq_gen_read_expcon_items2_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, 
	    eflag, &idlen, char4, &udtab, &kaccud, &kdecud, labud, (ftnlen)80,
	     (ftnlen)4, (ftnlen)50);
/*      READ(LINE,2,ERR=991) CHAR4, UDTAB, KACCUD, KDECUD, LABUD */
/* SOURCE expcon.for:1126 */
/*<       tabidu=get_tabid(udtab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &udtab);
    s_copy(tabidu, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE expcon.for:1127 */
/*<       idout=' ' >*/
    s_copy(idout, const_cast<char*>(" "), (ftnlen)32, (ftnlen)1);
/* SOURCE expcon.for:1128 */
/*<       idout(colwidth-idlen+1:colwidth)=tabidu(1:idlen) >*/
    feq_gen_i_d_1 = colwidth - idlen;
    s_copy(idout + feq_gen_i_d_1, tabidu, colwidth - feq_gen_i_d_1, idlen);
/* SOURCE expcon.for:1129 */
/*<       write(stdout,54)char4,idout(1:colwidth),kaccud,kdecud,labud >*/
    feq_gen_io_d__137.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__137);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, idout, colwidth);
    do_fio(&feq_gen_c_d_1, (char *)&kaccud, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&kdecud, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, labud, (ftnlen)50);
    e_wsfe();
/* SOURCE expcon.for:1130 */
/*<       char4=gettok(char4) >*/
    gettok_(feq_gen_ch_d_2, (ftnlen)4, char4, (ftnlen)4);
    s_copy(char4, feq_gen_ch_d_2, (ftnlen)4, (ftnlen)4);
/*     CHECK TABLE NUMBER FOR VALIDITY */
/* SOURCE expcon.for:1134 */
/*<       calltabchk(stdout,pmxtab,udtab,tabdir,eflag) >*/
    tabchk_(stdout, &feq_gen_c_d_10002, &udtab, &tabdir[1], eflag);
/*     CHECK LOSS COEFFICIENTS FOR VALIDITY. */
/* SOURCE expcon.for:1138 */
/*<       if(kaccud.gt.1.0.or.kaccud.lt.0.0)then >*/
    if (kaccud > (float)1. || kaccud < (float)0.) {
/* SOURCE expcon.for:1139 */
/*<       write(stdout,72)kaccud >*/
	feq_gen_io_d__138.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__138);
	do_fio(&feq_gen_c_d_1, (char *)&kaccud, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE expcon.for:1140 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE expcon.for:1141 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1142 */
/*<       if(kdecud.gt.1.0.or.kdecud.lt.0.0)then >*/
    if (kdecud > (float)1. || kdecud < (float)0.) {
/* SOURCE expcon.for:1143 */
/*<       write(stdout,72)kdecud >*/
	feq_gen_io_d__139.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__139);
	do_fio(&feq_gen_c_d_1, (char *)&kdecud, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE expcon.for:1144 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE expcon.for:1145 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1146 */
/*<       if(char4.ne.'UD'.and.char4.ne.'UTOD')then >*/
    if (s_cmp(char4, const_cast<char*>("UD"), (ftnlen)4, (ftnlen)2) != 0 && s_cmp(char4, const_cast<char*>("UTOD"), 
	    (ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE expcon.for:1147 */
/*<       write(stdout,74) >*/
	feq_gen_io_d__140.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__140);
	e_wsfe();
/* SOURCE expcon.for:1148 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE expcon.for:1149 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1151 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1154 */
/*<       idlen=0 >*/
    idlen = 0;
/* SOURCE expcon.for:1155 */
/*<        >*/
    feq_gen_read_expcon_items2_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, 
	    eflag, &idlen, char4, &dutab, &kaccdu, &kdecdu, labdu, (ftnlen)80,
	     (ftnlen)4, (ftnlen)50);
/*      READ(LINE,2,ERR=991) CHAR4, DUTAB, KACCDU, KDECDU, LABDU */
/* SOURCE expcon.for:1161 */
/*<       tabidd=get_tabid(dutab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &dutab);
    s_copy(tabidd, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE expcon.for:1162 */
/*<       idout=' ' >*/
    s_copy(idout, const_cast<char*>(" "), (ftnlen)32, (ftnlen)1);
/* SOURCE expcon.for:1163 */
/*<       idout(colwidth-idlen+1:colwidth)=tabidd(1:idlen) >*/
    feq_gen_i_d_1 = colwidth - idlen;
    s_copy(idout + feq_gen_i_d_1, tabidd, colwidth - feq_gen_i_d_1, idlen);
/* SOURCE expcon.for:1164 */
/*<       write(stdout,54)char4,idout(1:colwidth),kaccdu,kdecdu,labdu >*/
    feq_gen_io_d__146.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__146);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, idout, colwidth);
    do_fio(&feq_gen_c_d_1, (char *)&kaccdu, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&kdecdu, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, labdu, (ftnlen)50);
    e_wsfe();
/* SOURCE expcon.for:1165 */
/*<       char4=gettok(char4) >*/
    gettok_(feq_gen_ch_d_2, (ftnlen)4, char4, (ftnlen)4);
    s_copy(char4, feq_gen_ch_d_2, (ftnlen)4, (ftnlen)4);
/*     CHECK TABLE NUMBER FOR VALIDITY */
/* SOURCE expcon.for:1168 */
/*<       if(dutab.gt.0)then >*/
    if (dutab > 0) {
/* SOURCE expcon.for:1169 */
/*<       calltabchk(stdout,pmxtab,dutab,tabdir,eflag) >*/
	tabchk_(stdout, &feq_gen_c_d_10002, &dutab, &tabdir[1], eflag);
/*       CHECK LOSS COEFFICIENTS FOR VALIDITY. */
/* SOURCE expcon.for:1173 */
/*<       if(kaccdu.gt.1.0.or.kaccdu.lt.0.0)then >*/
	if (kaccdu > (float)1. || kaccdu < (float)0.) {
/* SOURCE expcon.for:1174 */
/*<       write(stdout,72)kaccdu >*/
	    feq_gen_io_d__147.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__147);
	    do_fio(&feq_gen_c_d_1, (char *)&kaccdu, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE expcon.for:1175 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE expcon.for:1176 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1177 */
/*<       if(kdecdu.gt.1.0.or.kdecdu.lt.0.0)then >*/
	if (kdecdu > (float)1. || kdecdu < (float)0.) {
/* SOURCE expcon.for:1178 */
/*<       write(stdout,72)kdecdu >*/
	    feq_gen_io_d__148.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__148);
	    do_fio(&feq_gen_c_d_1, (char *)&kdecdu, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE expcon.for:1179 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE expcon.for:1180 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1181 */
/*<       if(char4.ne.'DU'.and.char4.ne.'DTOU')then >*/
	if (s_cmp(char4, const_cast<char*>("DU"), (ftnlen)4, (ftnlen)2) != 0 && s_cmp(char4, 
		const_cast<char*>("DTOU"), (ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE expcon.for:1182 */
/*<       write(stdout,75) >*/
	    feq_gen_io_d__149.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__149);
	    e_wsfe();
/* SOURCE expcon.for:1183 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE expcon.for:1184 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1185 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1187 */
/*<       write(*,90)tabidu(1:lenstr(tabidu)),tabidd(1:lenstr(tabidd)) >*/
    s_wsfe(&feq_gen_io_d__150);
    do_fio(&feq_gen_c_d_1, tabidu, lenstr_(tabidu, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, tabidd, lenstr_(tabidd, (ftnlen)16));
    e_wsfe();
/*     INPUT THE SMOOTHING CONSTANT FOR LOSSES WHEN AREAS ARE NEARLY */
/*     EQUAL. */
/* SOURCE expcon.for:1191 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1194 */
/*<       read(line,4,err=991)smooth >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&smooth, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE expcon.for:1195 */
/*<       write(stdout,56)smooth >*/
    feq_gen_io_d__152.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__152);
    do_fio(&feq_gen_c_d_1, (char *)&smooth, (ftnlen)sizeof(real));
    e_wsfe();
/*     INPUT THE MEAN VALUE PARAMETER */
/* SOURCE expcon.for:1199 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1202 */
/*<       read(line,5,err=991)tgmean >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_5;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&tgmean, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE expcon.for:1203 */
/*<       write(stdout,57)tgmean >*/
    feq_gen_io_d__154.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__154);
    do_fio(&feq_gen_c_d_1, (char *)&tgmean, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE expcon.for:1204 */
/*<       if(tgmean.lt.-1.0)then >*/
    if (tgmean < (float)-1.) {
/* SOURCE expcon.for:1205 */
/*<       write(stdout,*)'  MINIMUM < MEAN VALUE < HARMONIC MEAN.' >*/
	feq_gen_io_d__155.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__155);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  MINIMUM < MEAN VALUE < HARMONIC MEAN."), (
		ftnlen)39);
	e_wsle();
/* SOURCE expcon.for:1206 */
/*<       elseif(tgmean.eq.-1.0)then >*/
    } else if (tgmean == (float)-1.) {
/* SOURCE expcon.for:1207 */
/*<       write(stdout,*)'   HARMONIC MEAN.' >*/
	feq_gen_io_d__156.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__156);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("   HARMONIC MEAN."), (ftnlen)17);
	e_wsle();
/* SOURCE expcon.for:1208 */
/*<       elseif(tgmean.lt.0.0)then >*/
    } else if (tgmean < (float)0.) {
/* SOURCE expcon.for:1209 */
/*<       write(stdout,*)'  HARMONIC MEAN < MEAN VALUE < GEOMETRIC MEAN.' >*/
	feq_gen_io_d__157.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__157);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  HARMONIC MEAN < MEAN VALUE < GEOMETRIC MEAN."),
		 (ftnlen)46);
	e_wsle();
/* SOURCE expcon.for:1210 */
/*<       elseif(tgmean.eq.0.0)then >*/
    } else if (tgmean == (float)0.) {
/* SOURCE expcon.for:1211 */
/*<       write(stdout,*)'   GEOMETRIC MEAN.' >*/
	feq_gen_io_d__158.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__158);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("   GEOMETRIC MEAN."), (ftnlen)18);
	e_wsle();
/* SOURCE expcon.for:1212 */
/*<       elseif(tgmean.lt.1.0)then >*/
    } else if (tgmean < (float)1.) {
/* SOURCE expcon.for:1213 */
/*<        >*/
	feq_gen_io_d__159.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__159);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  GEOMETRIC MEAN < MEAN VALUE < ARITHMETIC"), (
		ftnlen)42);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" MEAN."), (ftnlen)6);
	e_wsle();
/* SOURCE expcon.for:1215 */
/*<       elseif(tgmean.eq.1.)then >*/
    } else if (tgmean == (float)1.) {
/* SOURCE expcon.for:1216 */
/*<       write(stdout,*)'   ARITHMETIC MEAN.' >*/
	feq_gen_io_d__160.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__160);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("   ARITHMETIC MEAN."), (ftnlen)19);
	e_wsle();
/* SOURCE expcon.for:1217 */
/*<       elseif(tgmean.gt.1.0)then >*/
    } else if (tgmean > (float)1.) {
/* SOURCE expcon.for:1218 */
/*<       write(stdout,*)'  ARITHMETIC MEAN < MEAN VALUE <  MAXIMUM.' >*/
	feq_gen_io_d__161.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__161);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  ARITHMETIC MEAN < MEAN VALUE <  MAXIMUM."), (
		ftnlen)42);
	e_wsle();
/* SOURCE expcon.for:1219 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1220 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__162.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__162);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/*     INPUT THE DOWNSTREAM HEADS AND THE FACTORS CONTROLLING THE */
/*     DISTRIBUTION OF PARTIAL FREE FLOWS. */
/* SOURCE expcon.for:1225 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1228 */
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
/* SOURCE expcon.for:1229 */
/*<       write(stdout,92)head >*/
    feq_gen_io_d__163.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__163);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE expcon.for:1231 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1234 */
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
/* SOURCE expcon.for:1235 */
/*<       write(stdout,94)char5,nfrac >*/
    feq_gen_io_d__166.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__166);
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE expcon.for:1237 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1240 */
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
/* SOURCE expcon.for:1241 */
/*<       write(stdout,66)char5,power >*/
    feq_gen_io_d__168.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__168);
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&power, (ftnlen)sizeof(real));
    e_wsfe();
/*     COMPUTE THE PARTIAL FREE FLOWS */
/* SOURCE expcon.for:1245 */
/*<       do200i=1,nfrac >*/
    feq_gen_i_d_1 = nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE expcon.for:1246 */
/*<       pfqvec(i)=(float(i-1)/float(nfrac-1))**power >*/
	feq_gen_d_d_1 = (doublereal) (static_cast<double>((real) (feq_gen_i_d_ - 1)) / (real) (nfrac - 1));
	feq_gen_d_d_2 = (doublereal) power;
	pfqvec[feq_gen_i_d_ - 1] = feq::transition_partial_free_flow(feq_gen_i_d_,nfrac,power);
/* SOURCE expcon.for:1247 */
/*<   200 continue >*/
/* L200: */
    }
/*     INPUT THE DOWNSTREAM HEAD SEQUENCE */
/* SOURCE expcon.for:1251 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE expcon.for:1252 */
/*<       hdold=-1.0 >*/
    hdold = (float)-1.;
/* SOURCE expcon.for:1253 */
/*<   300 continue >*/
L300:
/* SOURCE expcon.for:1254 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE expcon.for:1257 */
/*<       read(line,'(F10.0)',err=991)hdvec(i) >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&hdvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE expcon.for:1258 */
/*<       write(stdout,'(1X,F10.2)')hdvec(i) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,F10.2)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&hdvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE expcon.for:1259 */
/*<       if(hdvec(i).le.0.0)then >*/
    if (hdvec[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE expcon.for:1260 */
/*<       nhd=i-1 >*/
	nhd = feq_gen_i_d_ - 1;
/* SOURCE expcon.for:1261 */
/*<       goto310 >*/
	goto L310;
/* SOURCE expcon.for:1262 */
/*<       else >*/
    } else {
/* SOURCE expcon.for:1263 */
/*<       if(hdvec(i).le.hdold)then >*/
	if (hdvec[feq_gen_i_d_ - 1] <= hdold) {
/* SOURCE expcon.for:1264 */
/*<       write(stdout,99)hdvec(i) >*/
	    feq_gen_io_d__174.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__174);
	    do_fio(&feq_gen_c_d_1, (char *)&hdvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE expcon.for:1265 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE expcon.for:1266 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1267 */
/*<       hdold=hdvec(i) >*/
	hdold = hdvec[feq_gen_i_d_ - 1];
/* SOURCE expcon.for:1268 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE expcon.for:1269 */
/*<       if(i.gt.pmxnhu)then >*/
	if (feq_gen_i_d_ > 151) {
/* SOURCE expcon.for:1270 */
/*<        >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *stdout;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:548* MORE THAN ',I5,' UPSTREAM HEADS')");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_151, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE expcon.for:1273 */
/*<       i=pmxnhu >*/
	    feq_gen_i_d_ = 151;
/* SOURCE expcon.for:1274 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE expcon.for:1275 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1277 */
/*<       goto300 >*/
	goto L300;
/* SOURCE expcon.for:1278 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1279 */
/*<   310 continue >*/
L310:
/* SOURCE expcon.for:1281 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     CHECK FOR THE CRITICAL FLOW AND CELERITY IN THE TABLE. */
/* SOURCE expcon.for:1284 */
/*<       write(stdout,88) >*/
    feq_gen_io_d__175.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__175);
    e_wsfe();
/* SOURCE expcon.for:1285 */
/*<       if(xtabl.gt.0)then >*/
    if (xtabl > 0) {
/* SOURCE expcon.for:1286 */
/*<       callchkcfc(grv,stdout,xtabl,wflag) >*/
	chkcfc_(grv, stdout, &xtabl, &wflag);
/* SOURCE expcon.for:1289 */
/*<       if(wflag.ne.0)then >*/
	if (wflag != 0) {
/* SOURCE expcon.for:1290 */
/*<       write(stdout,89)get_tabid(gettbn(xtabl)) >*/
	    feq_gen_io_d__177.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__177);
	    feq_gen_i_d_1 = gettbn_(&xtabl);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_3, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_3, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE expcon.for:1291 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1292 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1293 */
/*<       if(xtabr.gt.0)then >*/
    if (xtabr > 0) {
/* SOURCE expcon.for:1294 */
/*<       callchkcfc(grv,stdout,xtabr,wflag) >*/
	chkcfc_(grv, stdout, &xtabr, &wflag);
/* SOURCE expcon.for:1297 */
/*<       if(wflag.ne.0)then >*/
	if (wflag != 0) {
/* SOURCE expcon.for:1298 */
/*<       write(stdout,89)get_tabid(gettbn(xtabr)) >*/
	    feq_gen_io_d__178.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__178);
	    feq_gen_i_d_1 = gettbn_(&xtabr);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_3, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_3, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE expcon.for:1299 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1300 */
/*<       endif >*/
    }
/*     Check for existence of easting-northing in the cross-section tables */
/* SOURCE expcon.for:1303 */
/*<       if(easting<=dnull)then >*/
    if (easting <= dnull) {
/*       User did not input a value of easting. */
/*       Get values from each of the tables. */
/* SOURCE expcon.for:1306 */
/*<       callget_east_north(stdout,xtabl,eastingl,northingl) >*/
	feq_gen_get_east_north_d_(stdout, &xtabl, &eastingl, &northingl);
/* SOURCE expcon.for:1309 */
/*<       callget_east_north(stdout,xtabr,eastingr,northingr) >*/
	feq_gen_get_east_north_d_(stdout, &xtabr, &eastingr, &northingr);
/*       If both are defined, take the average, else, take */
/*       the value that is defined. */
/* SOURCE expcon.for:1314 */
/*<       if(eastingl>dnull)then >*/
	if (eastingl > dnull) {
/* SOURCE expcon.for:1315 */
/*<       if(eastingr>dnull)then >*/
	    if (eastingr > dnull) {
/*           Both are defined. */
/* SOURCE expcon.for:1317 */
/*<       easting=0.5*(eastingl+eastingr) >*/
		easting = (eastingl + eastingr) * (float).5;
/* SOURCE expcon.for:1318 */
/*<       northing=0.5*(northingl+northingr) >*/
		northing = (northingl + northingr) * (float).5;
/* SOURCE expcon.for:1319 */
/*<       else >*/
	    } else {
/*           Only left values are defined. */
/* SOURCE expcon.for:1321 */
/*<       easting=eastingl >*/
		easting = eastingl;
/* SOURCE expcon.for:1322 */
/*<       northing=northingl >*/
		northing = northingl;
/* SOURCE expcon.for:1323 */
/*<       endif >*/
	    }
/* SOURCE expcon.for:1324 */
/*<       else >*/
	} else {
/*         left values undefined */
/* SOURCE expcon.for:1326 */
/*<       if(eastingr>dnull)then >*/
	    if (eastingr > dnull) {
/*           right values are defined */
/* SOURCE expcon.for:1328 */
/*<       easting=eastingr >*/
		easting = eastingr;
/* SOURCE expcon.for:1329 */
/*<       northing=northingr >*/
		northing = northingr;
/* SOURCE expcon.for:1330 */
/*<       endif >*/
	    }
/* SOURCE expcon.for:1331 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1332 */
/*<       endif >*/
    }
/*     INPUT OF DATA COMPLETE.  BEGIN THE COMPUTATIONS. */
/* SOURCE expcon.for:1336 */
/*<       write(stdout,95) >*/
    feq_gen_io_d__183.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__183);
    e_wsfe();
/*     SELECT THE DATUM FOR HEADS. */
/* SOURCE expcon.for:1339 */
/*<       hdatum=max(zbl,zbr) >*/
    hdatum = dmax(zbl,zbr);
/* SOURCE expcon.for:1340 */
/*<       write(stdout,96)hdatum >*/
    feq_gen_io_d__185.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__185);
    do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
    e_wsfe();
/*     COMPUTE THE DISTANCE BETWEEN THE SECTIONS */
/* SOURCE expcon.for:1344 */
/*<       dx=abs(xl-xr) >*/
    dx = (feq_gen_r_d_1 = static_cast<double>(xl) - xr, dabs(feq_gen_r_d_1));
/* SOURCE expcon.for:1345 */
/*<       if(dx.eq.0.0)then >*/
    if (dx == (float)0.) {
/* SOURCE expcon.for:1346 */
/*<       write(stdout,76) >*/
	feq_gen_io_d__187.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__187);
	e_wsfe();
/* SOURCE expcon.for:1347 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1349 */
/*<       write(stdout,78) >*/
    feq_gen_io_d__188.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__188);
    e_wsfe();
/* SOURCE expcon.for:1351 */
/*<        >*/
    fndect_(stdout, &xtabl, &zbl, &xtabr, &zbr, &dx, &smooth, &tgmean, grv, &
	    kaccud, &kdecud, &nhd, &hdatum, hdvec, &nfrac, pfqvec, eflag, 
	    hufvec, humat, qfvec);
/*     CHECK FOR DECREASING FREE FLOW */
/* SOURCE expcon.for:1358 */
/*<       qold=0.0 >*/
    qold = (float)0.;
/* SOURCE expcon.for:1359 */
/*<       do320i=1,nhd >*/
    feq_gen_i_d_1 = nhd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE expcon.for:1360 */
/*<       if(qfvec(i).lt.qold)then >*/
	if (qfvec[feq_gen_i_d_ - 1] < qold) {
/* SOURCE expcon.for:1361 */
/*<       write(stdout,98)qfvec(i),hdvec(i) >*/
	    feq_gen_io_d__193.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__193);
	    do_fio(&feq_gen_c_d_1, (char *)&qfvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&hdvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE expcon.for:1362 */
/*<       endif >*/
	}
/* SOURCE expcon.for:1363 */
/*<       qold=qfvec(i) >*/
	qold = qfvec[feq_gen_i_d_ - 1];
/* SOURCE expcon.for:1364 */
/*<   320 continue >*/
/* L320: */
    }
/*     OUTPUT THE TABLE */
/* SOURCE expcon.for:1367 */
/*<       zrhufd=0.0 >*/
    zrhufd = (float)0.;
/* SOURCE expcon.for:1368 */
/*<        >*/
    twdout_(stdout, stdtab, &udtab, labud, &nhd, &nfrac, qfvec, hdvec, pfqvec,
	     humat, &hdatum, &tabtyp, const_cast<char*>("  EXPCON"), &zrhufd, zone, hgrid, 
	    vdatum, unitsys, basis, &easting, &northing, eflag, (ftnlen)50, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE expcon.for:1376 */
/*<       if(dutab.gt.0)then >*/
    if (dutab > 0) {
/* SOURCE expcon.for:1377 */
/*<       write(stdout,80) >*/
	feq_gen_io_d__195.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__195);
	e_wsfe();
/* SOURCE expcon.for:1379 */
/*<        >*/
	fndect_(stdout, &xtabr, &zbr, &xtabl, &zbl, &dx, &smooth, &tgmean, 
		grv, &kaccdu, &kdecdu, &nhd, &hdatum, hdvec, &nfrac, pfqvec, 
		eflag, hufvec, humat, qfvec);
/*       CHECK FOR DECREASING FREE FLOW */
/* SOURCE expcon.for:1387 */
/*<       qold=0.0 >*/
	qold = (float)0.;
/* SOURCE expcon.for:1388 */
/*<       do330i=1,nhd >*/
	feq_gen_i_d_1 = nhd;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE expcon.for:1389 */
/*<       if(qfvec(i).lt.qold)then >*/
	    if (qfvec[feq_gen_i_d_ - 1] < qold) {
/* SOURCE expcon.for:1390 */
/*<       write(stdout,98)qfvec(i),hdvec(i) >*/
		feq_gen_io_d__196.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__196);
		do_fio(&feq_gen_c_d_1, (char *)&qfvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&hdvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE expcon.for:1391 */
/*<       endif >*/
	    }
/* SOURCE expcon.for:1392 */
/*<       qold=qfvec(i) >*/
	    qold = qfvec[feq_gen_i_d_ - 1];
/* SOURCE expcon.for:1393 */
/*<   330 continue >*/
/* L330: */
	}
/*       OUTPUT THE TABLE */
/* SOURCE expcon.for:1396 */
/*<       zrhufd=0.0 >*/
	zrhufd = (float)0.;
/* SOURCE expcon.for:1397 */
/*<        >*/
	twdout_(stdout, stdtab, &dutab, labdu, &nhd, &nfrac, qfvec, hdvec, 
		pfqvec, humat, &hdatum, &tabtyp, const_cast<char*>("  EXPCON"), &zrhufd, zone, 
		hgrid, vdatum, unitsys, basis, &easting, &northing, eflag, (
		ftnlen)50, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		ftnlen)8, (ftnlen)8);
/* SOURCE expcon.for:1405 */
/*<       endif >*/
    }
/* SOURCE expcon.for:1406 */
/*<       return >*/
    return 0;
/* SOURCE expcon.for:1407 */
/*<   991 continue >*/
L991:
/* SOURCE expcon.for:1408 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__197.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__197);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE expcon.for:1409 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__198.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__198);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE expcon.for:1410 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE expcon.for:1411 */
/*<       end >*/
    return 0;
} /* expcon_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
