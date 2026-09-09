extern "C" void feq_root_variant(int,float,float,double(*)(float*),float*,float*,float*,float*,float*,int*);
extern "C" void feq_regfal(float,float,double(*)(float*),float*,float*,float*,int*);
extern "C" void feq_fdroot(float,double(*)(float*),float*,float*,int*);
#include "callbacks.hpp"
/* rootfind.f -- translated by f2c (version 20240504).
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




/* SOURCE rootfind.for:4 */
/*<       subroutinefdroot(b,fun,epsf,a,eflag) >*/
/* Subroutine */ int fdroot_(real *b, FeqCallback3 fun, real *epsf, real *a, integer *
	eflag)
{
    // Original-verified bracket updates, wide residuals and convergence ordering.
    feq_fdroot(*epsf,fun,a,b,eflag);
    return 0;
} /* fdroot_ */




/* SOURCE rootfind.for:60 */
/*<       subroutineregfal(epsx,epsf,f,a,b,xm,flag) >*/
/* Subroutine */ int regfal_(real *epsx, real *epsf, FeqCallback3 f, real *a, real *b,
	 real *xm, integer *feq_gen_flag_d_)
{
    // Original-verified bracket updates, wide residuals and convergence ordering.
    feq_regfal(*epsx,*epsf,f,a,b,xm,feq_gen_flag_d_);
    return 0;
} /* regfal_ */




/* SOURCE rootfind.for:187 */
/*<       subroutineregflt(epsx,epsf,f,a,b,fl,fr,xm,flag) >*/
/* Subroutine */ int regflt_(real *epsx, real *epsf, FeqCallback3 f, real *a, real *b,
	 real *fl, real *fr, real *xm, integer *feq_gen_flag_d_)
{
    // Original-verified bracket updates, wide residuals and convergence ordering.
    feq_root_variant(0,*epsx,*epsf,f,a,b,fl,fr,xm,feq_gen_flag_d_);
    return 0;
} /* regflt_ */




/* SOURCE rootfind.for:328 */
/*<       subroutinergf(epsx,epsf,f,a,b,fl,fr,xm,flag) >*/
/* Subroutine */ int rgf_(real *epsx, real *epsf, FeqCallback3 f, real *a, real *b, 
	real *fl, real *fr, real *xm, integer *feq_gen_flag_d_)
{
    // Original-verified bracket updates, wide residuals and convergence ordering.
    feq_root_variant(1,*epsx,*epsf,f,a,b,fl,fr,xm,feq_gen_flag_d_);
    return 0;
} /* rgf_ */




/* SOURCE rootfind.for:463 */
/*<       subroutinefdblrgf(epsx,epsf,f,a,b,fl,fr,root,flag) >*/
/* Subroutine */ int fdblrgf_(doublereal *epsx, doublereal *epsf, FeqCallback1 f, 
	doublereal *a, doublereal *b, doublereal *fl, doublereal *fr, 
	doublereal *root, integer *feq_gen_flag_d_)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1;

    /* Local variables */
    doublereal fm, xl, xm, xr;
    integer knt;
    doublereal fmold;

/*     + + + PURPOSE + + + */
/*     Find at least one root of the function, F(), in the */
/*     interval (A, B).  On entry the signs of FL and FR must differ */
/*     because they are the values of F() at the ends of the interval. */
/*     The root is returned as ROOT. Uses modified regula falsi. */
/*     Version of RGF with full double precision. */
/* SOURCE rootfind.for:475 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE rootfind.for:478 */
/*<       integerflag >*/
/* SOURCE rootfind.for:479 */
/*<       real*8a,b >*/
/* SOURCE rootfind.for:480 */
/*<       real*8epsf,epsx,fl,fr,root >*/
/*     + + + DUMMY ARGUMENT FUNCTIONS + + + */
/* SOURCE rootfind.for:483 */
/*<       real*8f >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     EPSX   - Convergence tolerance on arguments */
/*     EPSF   - Convergence tolerance for function values */
/*     F      - Function defining the root being sought */
/*     A      - Left end of interval containing at least one root */
/*     B      - Right end of interval containing at least one root */
/*     FL     - Function value on the left end of the interval */
/*     FR     - Value of function on the right end of the interval */
/*     XM     - interpolated point for next residual function evaluation */
/*     FLAG   - Result flag */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE rootfind.for:498 */
/*<       integerknt >*/
/* SOURCE rootfind.for:500 */
/*<       real*8fm,fmold,xl,xr,xm >*/
/*     + + + INTRINSICS + + + */
/* SOURCE rootfind.for:503 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE rootfind.for:506 */
/*<       externalf >*/
/* *********************************************************************** */
/* SOURCE rootfind.for:508 */
/*<       flag=0 >*/
    *feq_gen_flag_d_ = 0;
/* SOURCE rootfind.for:509 */
/*<       xl=a >*/
    xl = *a;
/* SOURCE rootfind.for:510 */
/*<       xr=b >*/
    xr = *b;
/* SOURCE rootfind.for:512 */
/*<       fmold=fl >*/
    fmold = *fl;
/* SOURCE rootfind.for:515 */
/*<       if(fl*fr.gt.0.0)then >*/
    if (*fl * *fr > (float)0.) {
/*       NO SOLUTION POSSIBLE */
/* SOURCE rootfind.for:517 */
/*<       flag=1 >*/
	*feq_gen_flag_d_ = 1;
/* SOURCE rootfind.for:518 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:519 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:521 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE rootfind.for:522 */
/*<   100 continue >*/
L100:
/*       COMPUTE THE INTERMEDIATE POINT LOCATION */
/* SOURCE rootfind.for:527 */
/*<       xm=(fr*xl-fl*xr)/(fr-fl) >*/
    xm = (*fr * xl - *fl * xr) / (*fr - *fl);
/*       Get the function at the current intermediate argument. */
/* SOURCE rootfind.for:530 */
/*<       fm=f(xm) >*/
    fm = (*f)(&xm);
/* SOURCE rootfind.for:533 */
/*<       if(abs(fm).lt.epsf)then >*/
    if (abs(fm) < *epsf) {
/* SOURCE rootfind.for:534 */
/*<       a=xl >*/
	*a = xl;
/* SOURCE rootfind.for:535 */
/*<       b=xr >*/
	*b = xr;
/* SOURCE rootfind.for:536 */
/*<       fl=fm >*/
	*fl = fm;
/* SOURCE rootfind.for:537 */
/*<       root=xm >*/
	*root = xm;
/* SOURCE rootfind.for:538 */
/*<       fr=dble(knt) >*/
	*fr = (doublereal) knt;
/* SOURCE rootfind.for:539 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:540 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:542 */
/*<       if(abs(xl-xr)/(abs(xl)+abs(xr)).lt.epsx)then >*/
    if ((feq_gen_d_d_1 = xl - xr, abs(feq_gen_d_d_1)) / (abs(xl) + abs(xr)) < *epsx) {
/*         Argument collapse . */
/* SOURCE rootfind.for:545 */
/*<       a=xl >*/
	*a = xl;
/* SOURCE rootfind.for:546 */
/*<       b=xr >*/
	*b = xr;
/* SOURCE rootfind.for:547 */
/*<       fl=fm >*/
	*fl = fm;
/* SOURCE rootfind.for:548 */
/*<       root=xm >*/
	*root = xm;
/* SOURCE rootfind.for:549 */
/*<       fr=dble(knt) >*/
	*fr = (doublereal) knt;
/* SOURCE rootfind.for:550 */
/*<       if(abs(fm).gt.2.d0*epsf)then >*/
	if (abs(fm) > *epsf * 2.) {
/* SOURCE rootfind.for:551 */
/*<       flag=3 >*/
	    *feq_gen_flag_d_ = 3;
/* SOURCE rootfind.for:552 */
/*<       endif >*/
	}
/* SOURCE rootfind.for:553 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:554 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:556 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE rootfind.for:557 */
/*<       if(knt.gt.100)then >*/
    if (knt > 100) {
/* SOURCE rootfind.for:558 */
/*<       a=xl >*/
	*a = xl;
/* SOURCE rootfind.for:559 */
/*<       b=xr >*/
	*b = xr;
/* SOURCE rootfind.for:560 */
/*<       root=xm >*/
	*root = xm;
/* SOURCE rootfind.for:561 */
/*<       flag=2 >*/
	*feq_gen_flag_d_ = 2;
/* SOURCE rootfind.for:562 */
/*<       fr=dble(knt) >*/
	*fr = (doublereal) knt;
/* SOURCE rootfind.for:563 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:564 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:565 */
/*<       if(fl*fm.le.0.0)then >*/
    if (*fl * fm <= (float)0.) {
/*         RETAIN LEFT POINT TO RETAIN SIGN CHANGE */
/* SOURCE rootfind.for:568 */
/*<       xr=xm >*/
	xr = xm;
/* SOURCE rootfind.for:569 */
/*<       fr=fm >*/
	*fr = fm;
/*         HAVE INTERMEDIATE POINTS BEEN ON THE SAME SIDE OF THE ROOT */
/*         TWICE IN SUCCESSION? */
/* SOURCE rootfind.for:572 */
/*<       if(fmold*fm.gt.0.0)then >*/
	if (fmold * fm > (float)0.) {
/*           YES */
/* SOURCE rootfind.for:574 */
/*<       fl=0.75d0*fl >*/
	    *fl *= .75;
/* SOURCE rootfind.for:575 */
/*<       endif >*/
	}
/* SOURCE rootfind.for:576 */
/*<       fmold=fm >*/
	fmold = fm;
/* SOURCE rootfind.for:577 */
/*<       else >*/
    } else {
/*         RETAIN RIGHT POINT TO RETAIN SIGN CHANGE */
/* SOURCE rootfind.for:580 */
/*<       xl=xm >*/
	xl = xm;
/* SOURCE rootfind.for:581 */
/*<       fl=fm >*/
	*fl = fm;
/*         HAVE INTERMEDIATE POINTS BEEN ON THE SAME SIDE OF THE ROOT */
/*         TWICE IN SUCCESSION? */
/* SOURCE rootfind.for:585 */
/*<       if(fm*fmold.gt.0.0d0)then >*/
	if (fm * fmold > 0.) {
/*           YES */
/* SOURCE rootfind.for:587 */
/*<       fr=0.75d0*fr >*/
	    *fr *= .75;
/* SOURCE rootfind.for:588 */
/*<       endif >*/
	}
/* SOURCE rootfind.for:589 */
/*<       fmold=fm >*/
	fmold = fm;
/* SOURCE rootfind.for:590 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:592 */
/*<       goto100 >*/
    goto L100;
/* SOURCE rootfind.for:593 */
/*<       end >*/
} /* fdblrgf_ */




/* SOURCE rootfind.for:597 */
/*<       subroutinedblrgf(epsx,epsf,f,a,b,fl,fr,xm,flag) >*/
/* Subroutine */ int dblrgf_(doublereal *epsx, doublereal *epsf, FeqCallback1 f, real 
	*a, real *b, doublereal *fl, doublereal *fr, doublereal *xm, integer *
	feq_gen_flag_d_)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1;

    /* Local variables */
    doublereal fm, xl, xr;
    integer knt;
    doublereal fmold;

/*     + + + PURPOSE + + + */
/*     Find at least one root of the function, F(), in the */
/*     interval (A, B).  On entry the signs of FL and FR must differ */
/*     because they are the values of F() at the ends of the interval. */
/*     The root is returned as XM. Uses modified regula falsi. */
/*     Version of RGF with double precision function evaluation. */
/*     XM enters with value in this version. */
/* SOURCE rootfind.for:610 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE rootfind.for:613 */
/*<       integerflag >*/
/* SOURCE rootfind.for:614 */
/*<       reala,b >*/
/* SOURCE rootfind.for:615 */
/*<       real*8epsf,epsx,fl,fr,xm >*/
/*     + + + DUMMY ARGUMENT FUNCTIONS + + + */
/* SOURCE rootfind.for:618 */
/*<       real*8f >*/
/* INCLUDE rootfind.for:620 */
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
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     EPSX   - Convergence tolerance on arguments */
/*     EPSF   - Convergence tolerance for function values */
/*     F      - Function defining the root being sought */
/*     A      - Left end of interval containing at least one root */
/*     B      - Right end of interval containing at least one root */
/*     FL     - Function value on the left end of the interval */
/*     FR     - Value of function on the right end of the interval */
/*     XM     - interpolated point for next residual function evaluation */
/*     FLAG   - Result flag */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE rootfind.for:634 */
/*<       integerknt >*/
/* SOURCE rootfind.for:636 */
/*<       real*8fm,fmold,xl,xr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE rootfind.for:639 */
/*<       intrinsicabs,dble >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE rootfind.for:642 */
/*<       externalf >*/
/*     *****************************FORMATS****************************** */
/* SOURCE rootfind.for:644 */
/*<    50  >*/
/* SOURCE rootfind.for:646 */
/*<    52 format(' DBLRGF: XM=',1pe12.5,' FM=',1pe12.5) >*/
/* *********************************************************************** */
/* SOURCE rootfind.for:648 */
/*<       flag=0 >*/
/* L50: */
/* L52: */
    *feq_gen_flag_d_ = 0;
/* SOURCE rootfind.for:649 */
/*<       xl=dble(a) >*/
    xl = (doublereal) (*a);
/* SOURCE rootfind.for:650 */
/*<       xr=dble(b) >*/
    xr = (doublereal) (*b);
/* SOURCE rootfind.for:652 */
/*<       fmold=fl >*/
    fmold = *fl;
/* SOURCE rootfind.for:655 */
/*<       if(fl*fr.gt.0.0)then >*/
    if (*fl * *fr > (float)0.) {
/*       NO SOLUTION POSSIBLE */
/* SOURCE rootfind.for:657 */
/*<       flag=1 >*/
	*feq_gen_flag_d_ = 1;
/* SOURCE rootfind.for:658 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:659 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:661 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE rootfind.for:662 */
/*<   100 continue >*/
L100:
/*        WRITE(STD6,50) XL, FL, XR, FR */
/*       Get the function at the current intermediate argument. */
/* SOURCE rootfind.for:668 */
/*<       fm=f(xm) >*/
    fm = (*f)(xm);
/* SOURCE rootfind.for:670 */
/*<       if(fm.eq.0.0d0)then >*/
    if (fm == 0.) {
/* SOURCE rootfind.for:671 */
/*<       a=xl >*/
	*a = xl;
/* SOURCE rootfind.for:672 */
/*<       b=xr >*/
	*b = xr;
/* SOURCE rootfind.for:673 */
/*<       fl=fm >*/
	*fl = fm;
/* SOURCE rootfind.for:674 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:675 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:677 */
/*<       if(abs(fm).lt.epsf)then >*/
    if (abs(fm) < *epsf) {
/* SOURCE rootfind.for:678 */
/*<       a=xl >*/
	*a = xl;
/* SOURCE rootfind.for:679 */
/*<       b=xr >*/
	*b = xr;
/* SOURCE rootfind.for:680 */
/*<       fl=fm >*/
	*fl = fm;
/* SOURCE rootfind.for:681 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:682 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:684 */
/*<       if(abs(xl-xr)/(abs(xl)+abs(xr)).lt.epsx)then >*/
    if ((feq_gen_d_d_1 = xl - xr, abs(feq_gen_d_d_1)) / (abs(xl) + abs(xr)) < *epsx) {
/*         Argument collapse . */
/* SOURCE rootfind.for:687 */
/*<       a=xl >*/
	*a = xl;
/* SOURCE rootfind.for:688 */
/*<       b=xr >*/
	*b = xr;
/* SOURCE rootfind.for:689 */
/*<       fl=fm >*/
	*fl = fm;
/* SOURCE rootfind.for:690 */
/*<       if(abs(fm).gt.2.*epsf)then >*/
	if (abs(fm) > *epsf * (float)2.) {
/* SOURCE rootfind.for:691 */
/*<       flag=3 >*/
	    *feq_gen_flag_d_ = 3;
/* SOURCE rootfind.for:692 */
/*<       endif >*/
	}
/* SOURCE rootfind.for:693 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:694 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:696 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE rootfind.for:697 */
/*<       if(knt.gt.100)then >*/
    if (knt > 100) {
/* SOURCE rootfind.for:698 */
/*<       a=xl >*/
	*a = xl;
/* SOURCE rootfind.for:699 */
/*<       b=xr >*/
	*b = xr;
/* SOURCE rootfind.for:700 */
/*<       flag=2 >*/
	*feq_gen_flag_d_ = 2;
/* SOURCE rootfind.for:701 */
/*<       return >*/
	return 0;
/* SOURCE rootfind.for:702 */
/*<       endif >*/
    }
/* SOURCE rootfind.for:703 */
/*<       if(fl*fm.le.0.0)then >*/
    if (*fl * fm <= (float)0.) {
/*         RETAIN LEFT POINT TO RETAIN SIGN CHANGE */
/* SOURCE rootfind.for:706 */
/*<       xr=xm >*/
	xr = *xm;
/* SOURCE rootfind.for:707 */
/*<       fr=fm >*/
	*fr = fm;
/*         HAVE INTERMEDIATE POINTS BEEN ON THE SAME SIDE OF THE ROOT */
/*         TWICE IN SUCCESSION? */
/* SOURCE rootfind.for:710 */
/*<       if(fmold*fm.gt.0.0)then >*/
	if (fmold * fm > (float)0.) {
/*           YES */
/* SOURCE rootfind.for:712 */
/*<       fl=0.5*fl >*/
	    *fl *= (float).5;
/* SOURCE rootfind.for:713 */
/*<       endif >*/
	}
/* SOURCE rootfind.for:714 */
/*<       fmold=fm >*/
	fmold = fm;
/* SOURCE rootfind.for:715 */
/*<       else >*/
    } else {
/*         RETAIN RIGHT POINT TO RETAIN SIGN CHANGE */
/* SOURCE rootfind.for:718 */
/*<       xl=xm >*/
	xl = *xm;
/* SOURCE rootfind.for:719 */
/*<       fl=fm >*/
	*fl = fm;
/*         HAVE INTERMEDIATE POINTS BEEN ON THE SAME SIDE OF THE ROOT */
/*         TWICE IN SUCCESSION? */
/* SOURCE rootfind.for:723 */
/*<       if(fm*fmold.gt.0.0)then >*/
	if (fm * fmold > (float)0.) {
/*           YES */
/* SOURCE rootfind.for:725 */
/*<       fr=0.5*fr >*/
	    *fr *= (float).5;
/* SOURCE rootfind.for:726 */
/*<       endif >*/
	}
/* SOURCE rootfind.for:727 */
/*<       fmold=fm >*/
	fmold = fm;
/* SOURCE rootfind.for:728 */
/*<       endif >*/
    }
/*       COMPUTE THE INTERMEDIATE POINT LOCATION */
/* SOURCE rootfind.for:732 */
/*<       xm=(fr*xl-fl*xr)/(fr-fl) >*/
    *xm = (*fr * xl - *fl * xr) / (*fr - *fl);
/* SOURCE rootfind.for:733 */
/*<       goto100 >*/
    goto L100;
/* SOURCE rootfind.for:734 */
/*<       end >*/
} /* dblrgf_ */




/* SOURCE rootfind.for:738 */
/*<       subroutinergf3(epsx,epsf,f,a,b,fl,fr,xm,flag) >*/
/* Subroutine */ int rgf3_(real *epsx, real *epsf, FeqCallback3 f, real *a, real *b, 
	real *fl, real *fr, real *xm, integer *feq_gen_flag_d_)
{
    // Original-verified bracket updates, wide residuals and convergence ordering.
    feq_root_variant(2,*epsx,*epsf,f,a,b,fl,fr,xm,feq_gen_flag_d_);
    return 0;
} /* rgf3_ */




/* SOURCE rootfind.for:885 */
/*<       subroutinergf5(epsx,epsf,f,a,b,fl,fr,xm,flag) >*/
/* Subroutine */ int rgf5_(real *epsx, real *epsf, FeqCallback3 f, real *a, real *b, 
	real *fl, real *fr, real *xm, integer *feq_gen_flag_d_)
{
    // Original-verified bracket updates, wide residuals and convergence ordering.
    feq_root_variant(3,*epsx,*epsf,f,a,b,fl,fr,xm,feq_gen_flag_d_);
    return 0;
} /* rgf5_ */




/* SOURCE rootfind.for:1042 */
/*<        >*/
/* Subroutine */ int secant_(real *xla, real *epsarg, real *epsf, real *
	epsabs, integer *maxit, real *xmin, real *xmax, FeqCallback1 fun, real *xra, 
	integer *feq_gen_flag_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal df, fl, fr, dx, xl, xr, oldval, dxtemp;

/*     + + + PURPOSE + + + */
/*     Find a root of the function, FUN, using the secant method. */
/*     XLA and XRA give the starting points.  XMAX and XMIN give the */
/*     maximum and minimum values allowed for the root.  The final */
/*     root is returned in XRA.  FUN is a double precision function */
/*     of one argument.  All other values must be passed to FUN using */
/*     a common block.  FLAG = 0: solution found. FLAG=1: MAXIT */
/*     interations and no solution. FLAG=2: computed derivative is */
/*     zero and the function is still larger than the tolerance. */
/*     Indicates a local max or min of the function. */
/* SOURCE rootfind.for:1059 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE rootfind.for:1062 */
/*<       integerflag,maxit >*/
/* SOURCE rootfind.for:1063 */
/*<       realepsarg,epsabs,epsf,xla,xmax,xmin,xra >*/
/*     + + + DUMMY ARGUMENT FUNCTIONS + + + */
/* SOURCE rootfind.for:1066 */
/*<       doubleprecisionfun >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     XLA    - Left hand end of starting interval */
/*     EPSARG - Convergence tolerance on arguments */
/*     EPSF   - Convergence tolerance for function values */
/*     EPSABS - Absolute convergence tolerance on arguments */
/*     MAXIT  - Maximum number of iterations */
/*     XMIN   - Lower limit for root */
/*     XMAX   - Upper limit for root */
/*     FUN    - Integrand function */
/*     XRA    - Right hand end of starting interval */
/*     FLAG   - Result flag */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE rootfind.for:1081 */
/*<       integeri >*/
/* SOURCE rootfind.for:1082 */
/*<       doubleprecisiondf,dx,dxtemp,fl,fr,oldval,xl,xr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE rootfind.for:1085 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE rootfind.for:1088 */
/*<       externalfun >*/
/* *********************************************************************** */
/* SOURCE rootfind.for:1090 */
/*<       xl=xla >*/
    xl = *xla;
/* SOURCE rootfind.for:1091 */
/*<       xr=xra >*/
    xr = *xra;
/* SOURCE rootfind.for:1092 */
/*<       oldval=1.d0 >*/
    oldval = 1.;
/*      WRITE(STD6,*) ' ENTERING SECANT. XL=',XL,' XR=',XR */
/* SOURCE rootfind.for:1095 */
/*<       flag=0 >*/
    *feq_gen_flag_d_ = 0;
/* SOURCE rootfind.for:1096 */
/*<       fl=fun(xl) >*/
    fl = (*fun)(&xl);
/*      WRITE(STD6,*) ' FL=',FL */
/* SOURCE rootfind.for:1098 */
/*<       dx=xr-xl >*/
    dx = xr - xl;
/* SOURCE rootfind.for:1099 */
/*<       do100i=1,maxit >*/
    feq_gen_i_d_1 = *maxit;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE rootfind.for:1100 */
/*<       fr=fun(xr) >*/
	fr = (*fun)(&xr);
/*       WRITE(STD6,*) ' I=',I,' FR=',FR */
/* SOURCE rootfind.for:1102 */
/*<       if(abs(fr).le.epsf)then >*/
	if (abs(fr) <= *epsf) {
/* SOURCE rootfind.for:1103 */
/*<       xra=xr >*/
	    *xra = xr;
/* SOURCE rootfind.for:1104 */
/*<       return >*/
	    return 0;
/* SOURCE rootfind.for:1105 */
/*<       endif >*/
	}
/* SOURCE rootfind.for:1106 */
/*<       df=fl-fr >*/
	df = fl - fr;
/*        WRITE(STD6,*) ' SECANT:I=',I,' FL=',FL,' FR=',FR,' DX=',DX */
/* SOURCE rootfind.for:1108 */
/*<       if(df.ne.0.0)then >*/
	if (df != (float)0.) {
/* SOURCE rootfind.for:1109 */
/*<       dxtemp=0.0 >*/
	    dxtemp = (float)0.;
/* SOURCE rootfind.for:1110 */
/*<       oldval=dx/df >*/
	    oldval = dx / df;
/* SOURCE rootfind.for:1111 */
/*<       dx=fr*oldval >*/
	    dx = fr * oldval;
/* SOURCE rootfind.for:1112 */
/*<       xl=xr >*/
	    xl = xr;
/* SOURCE rootfind.for:1113 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE rootfind.for:1114 */
/*<       xr=xr+dx >*/
	    xr += dx;
/* SOURCE rootfind.for:1115 */
/*<       if(xr.ge.xmax)then >*/
	    if (xr >= *xmax) {
/* SOURCE rootfind.for:1116 */
/*<       xr=0.5*(xl+xmax) >*/
		xr = (xl + *xmax) * (float).5;
/* SOURCE rootfind.for:1117 */
/*<       dxtemp=xr-xl >*/
		dxtemp = xr - xl;
/* SOURCE rootfind.for:1118 */
/*<       elseif(xr.le.xmin)then >*/
	    } else if (xr <= *xmin) {
/* SOURCE rootfind.for:1119 */
/*<       xr=0.5*(xl+xmin) >*/
		xr = (xl + *xmin) * (float).5;
/* SOURCE rootfind.for:1120 */
/*<       dxtemp=xr-xl >*/
		dxtemp = xr - xl;
/* SOURCE rootfind.for:1121 */
/*<       endif >*/
	    }
/*          WRITE(STD6,*) ' DX=',DX */
/* SOURCE rootfind.for:1123 */
/*<       if(abs(dx/xr).le.epsarg.or.abs(dx).le.epsabs)then >*/
	    if ((feq_gen_d_d_1 = dx / xr, abs(feq_gen_d_d_1)) <= *epsarg || abs(dx) <= *epsabs) 
		    {
/* SOURCE rootfind.for:1124 */
/*<       xra=xr >*/
		*xra = xr;
/* SOURCE rootfind.for:1125 */
/*<       return >*/
		return 0;
/* SOURCE rootfind.for:1126 */
/*<       endif >*/
	    }
/* SOURCE rootfind.for:1127 */
/*<       if(dxtemp.ne.0.0)then >*/
	    if (dxtemp != (float)0.) {
/* SOURCE rootfind.for:1128 */
/*<       dx=dxtemp >*/
		dx = dxtemp;
/* SOURCE rootfind.for:1129 */
/*<       endif >*/
	    }
/* SOURCE rootfind.for:1130 */
/*<       else >*/
	} else {
/*         DF = 0. SIGNAL POSSIBLE ERROR */
/* SOURCE rootfind.for:1132 */
/*<       xra=xr >*/
	    *xra = xr;
/* SOURCE rootfind.for:1133 */
/*<       if(abs(fr).le.epsf)then >*/
	    if (abs(fr) <= *epsf) {
/* SOURCE rootfind.for:1134 */
/*<       return >*/
		return 0;
/* SOURCE rootfind.for:1135 */
/*<       else >*/
	    } else {
/* SOURCE rootfind.for:1136 */
/*<       flag=2 >*/
		*feq_gen_flag_d_ = 2;
/* SOURCE rootfind.for:1137 */
/*<       return >*/
		return 0;
/* SOURCE rootfind.for:1138 */
/*<       endif >*/
	    }
/* SOURCE rootfind.for:1139 */
/*<       endif >*/
	}
/* SOURCE rootfind.for:1141 */
/*<   100 continue >*/
/* L100: */
    }
/*     DROP THROUGH INDICATES NO CONVERGENCE WITHIN MAXIT ITERATIONS */
/* SOURCE rootfind.for:1144 */
/*<       flag=1 >*/
    *feq_gen_flag_d_ = 1;
/* SOURCE rootfind.for:1145 */
/*<       xra=xr >*/
    *xra = xr;
/* SOURCE rootfind.for:1146 */
/*<       return >*/
    return 0;
/* SOURCE rootfind.for:1147 */
/*<       end >*/
} /* secant_ */

#ifdef __cplusplus
	}
#endif
