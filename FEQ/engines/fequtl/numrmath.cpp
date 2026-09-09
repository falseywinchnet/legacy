#include <feq/gaussian_rule.hpp>
#include "callbacks.hpp"
/* numrmath.f -- translated by f2c (version 20240504).
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

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/*     Contains stuff for some standard numerical methods. */



/* SOURCE numrmath.for:6 */
/*<       realfunctionfdcnmn(n,x,y,xl,xr) >*/
doublereal fdcnmn_(integer *n, real *feq_storage_x, real *feq_storage_y, real *xl, real *xr)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    integer feq_gen_i_d_;
    real ymin;

/*     + + + PURPOSE + + + */
/*     Find a constrained minimum.  For X between XL and XR find */
/*     minimum value of Y. */
/* SOURCE numrmath.for:13 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE numrmath.for:16 */
/*<       integern >*/
/* SOURCE numrmath.for:17 */
/*<       realx(n),xl,xr,y(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     X      - Offsets of points on cross section boundary */
/*     Y      - vector of values defining minimum */
/*     XL     - Offset at left hand end of segment */
/*     XR     - Offset at right hand end of segment */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE numrmath.for:26 */
/*<       integeri >*/
/* SOURCE numrmath.for:27 */
/*<       realymin >*/
/*     + + + INTRINSICS + + + */
/* SOURCE numrmath.for:30 */
/*<       intrinsicmin >*/
/* *********************************************************************** */
/* SOURCE numrmath.for:32 */
/*<       ymin=1.e30 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> y(feq_storage_y, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
    ymin = (float)1e30;
/* SOURCE numrmath.for:33 */
/*<       do100i=1,n >*/
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE numrmath.for:34 */
/*<       if(x(i).ge.xl.and.x(i).le.xr)then >*/
	if (x[feq_gen_i_d_] >= *xl && x[feq_gen_i_d_] <= *xr) {
/* SOURCE numrmath.for:35 */
/*<       ymin=min(ymin,y(i)) >*/
/* Computing MIN */
	    feq_gen_r_d_1 = ymin, feq_gen_r_d_2 = y[feq_gen_i_d_];
	    ymin = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE numrmath.for:36 */
/*<       endif >*/
	}
/* SOURCE numrmath.for:37 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE numrmath.for:38 */
/*<       fdcnmn=ymin >*/
    ret_val = ymin;
/* SOURCE numrmath.for:39 */
/*<       return >*/
    return ret_val;
/* SOURCE numrmath.for:40 */
/*<       end >*/
} /* fdcnmn_ */




/* SOURCE numrmath.for:44 */
/*<       subroutinevlchpp(stdout,n,x,y,lcode,lval,rcode,rval,m,adjloc) >*/
/* Subroutine */ int vlchpp_(integer *stdout, integer *n, doublereal *feq_storage_x, 
	doublereal *feq_storage_y, integer *lcode, doublereal *lval, integer *rcode, 
	doublereal *rval, doublereal *feq_storage_m, char *feq_storage_adjloc, ftnlen adjloc_len)
{
    integer nadj;
    extern /* Subroutine */ int vrlim_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, char *, ftnlen), spline_(integer *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *);

/*     + + + PURPOSE + + + */
/*     Find a variation-limited cubic Hermite piecewise polynomial */
/*     that interpolates Y at each of the break points in X.  The */
/*     derivative of the function, y, with respect to x is stored */
/*     in M.   Such a function will have montone variation between */
/*     successive breakpoints and interpolation between breakpoints */
/*     does not introduce any extreme points.  That is, all extreme */
/*     values are already present in Y. */
/*     Method: Fit a cubic spline to the N points in X and Y and */
/*     then adjust the derivatives in M, as required to make the */
/*     variation monotone between break points.  The end conditions */
/*     for the spline are given in LCODE, LVAL for the left end */
/*     and RCODE, RVAL for the right end. */
/* SOURCE numrmath.for:63 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE numrmath.for:66 */
/*<       integerlcode,n,rcode,stdout >*/
/* SOURCE numrmath.for:67 */
/*<       doubleprecisionlval,m(n),rval,x(n),y(n) >*/
/* SOURCE numrmath.for:68 */
/*<       character*1adjloc(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     N      - number of points */
/*     X      - breakpoints for the spline */
/*     Y      - function values for spline */
/*     LCODE  - Code for left hand end condition */
/*     LVAL   - Value of the left hand end condition */
/*     RCODE  - Code for the right-hand end condition for the spline */
/*     RVAL   - Value of the right-hand end condition */
/*     M      - Vector of first derivatives */
/*     ADJLOC - values at which slope was adjusted to limit variation */
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE numrmath.for:83 */
/*<       externalspline,vrlim >*/
/*     Local */
/* SOURCE numrmath.for:86 */
/*<       integernadj >*/
/* *********************************************************************** */
/* SOURCE numrmath.for:88 */
/*<       callspline(stdout,x,y,n,lcode,lval,rcode,rval,m) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> adjloc(feq_storage_adjloc, 1);

    feq::IndexedPointer<doublereal> m(feq_storage_m, 1);

    feq::IndexedPointer<doublereal> y(feq_storage_y, 1);

    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
    spline_(stdout, &x[1], &y[1], n, lcode, lval, rcode, rval, &m[1]);
/*     Check for monotone variation */
/* SOURCE numrmath.for:94 */
/*<       callvrlim(n,x,y,m,nadj,adjloc) >*/
    vrlim_(n, &x[1], &y[1], &m[1], &nadj, adjloc + 1, (ftnlen)1);
/* SOURCE numrmath.for:99 */
/*<       return >*/
    return 0;
/* SOURCE numrmath.for:100 */
/*<       end >*/
} /* vlchpp_ */




/* SOURCE numrmath.for:104 */
/*<       subroutineimtql2(n,d,z,e,ierr) >*/
/* Subroutine */ int imtql2_(integer *n, doublereal *feq_gen_feq_storage_d_d_, doublereal *feq_gen_feq_storage_z_d_, 
	doublereal *feq_storage_e, integer *ierr)
{
    /* Initialized data */

    static doublereal machep = 2.2e-16;

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2, feq_gen_d_d_3;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    doublereal b, feq_gen_c_d_, f, g;
    integer feq_gen_i_d_, j, k, l, m;
    doublereal p, feq_gen_r_d_, s;
    integer ii, mml;

/*     + + + PURPOSE + + + */
/*     This subroutine finds the eigenvalues and first components of the */
/*     eigenvectors of a symmetric tridiagonal matrix by the implicit QL */
/*     method. */
/*     This subroutine is a translation of the algol procedure IMTQL2, */
/*     NUM. MATH. 12, 377-383(1968) by Martin and Wilkinson, */
/*     as modified in NUM. MATH. 15, 450(1970) by Dubrulle, */
/*     Handbook for Auto. Comp., Vol.II-Linear Algebra, 241-248(1971). */
/*     This is a modified version of the 'EISPACK' routine IMTQL2. */
/*     Called by GRULE and adapted from the same source. */
/* SOURCE numrmath.for:122 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE numrmath.for:125 */
/*<       integerierr,n >*/
/* SOURCE numrmath.for:126 */
/*<       doubleprecisiond(n),e(n),z(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - the order of the matrix */
/*     D      - diagonal elements of the input matrix on input, */
/*            - eigenvalues in ascending order on output.  If an */
/*              error exit is made, the eigenvalues are correct but */
/*              unordered for indices 1, 2, ..., IERR-1. */
/*     Z      - contains the first row of the identity matrix on input. */
/*              contains the first components of the orthonormal */
/*              eigenvectors of the symmetric tridiagonal matrix on */
/*              output.  If an error exit is  made, z contains the */
/*              eigenvectors  associated with the stored eigenvalues. */
/*     E      - contains the subdiagonal elements of the input matrix */
/*              in its first N-1 positions.  E(N) is arbitrary. Values */
/*              are destroyed in processing. */
/*     IERR   - is zero for normal return; is J if the J-th eigenvalue */
/*              has not been  determined after 30 iterations. */
/*     + + + SAVED VALUES + + + */
/* SOURCE numrmath.for:146 */
/*<       doubleprecisionmachep >*/
/* SOURCE numrmath.for:147 */
/*<       savemachep >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE numrmath.for:150 */
/*<       integeri,ii,j,k,l,m,mml >*/
/* SOURCE numrmath.for:151 */
/*<       doubleprecisionb,c,f,g,p,r,s >*/
/*     + + + INTRINSICS + + + */
/* SOURCE numrmath.for:154 */
/*<       intrinsicabs,sign,sqrt >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/* SOURCE numrmath.for:157 */
/*<       datamachep/2.2d-16/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> e(feq_storage_e, 1);

    feq::IndexedPointer<doublereal> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<doublereal> feq_gen_d_d_(feq_gen_feq_storage_d_d_, 1);

    /* Function Body */
/* SOURCE numrmath.for:159 */
/*<       ierr=0 >*/
    *ierr = 0;
/* SOURCE numrmath.for:160 */
/*<       if(n.eq.1)goto1001 >*/
    if (*n == 1) {
	goto L1001;
    }
/* SOURCE numrmath.for:162 */
/*<       e(n)=0.0d0 >*/
    e[*n] = 0.;
/* SOURCE numrmath.for:163 */
/*<       do240l=1,n >*/
    feq_gen_i_d_1 = *n;
    for (l = 1; l <= feq_gen_i_d_1; ++l) {
/* SOURCE numrmath.for:164 */
/*<       j=0 >*/
	j = 0;
/*     LOOK FOR SMALL SUB-DIAGONAL ELEMENT */
/* SOURCE numrmath.for:166 */
/*<   105 do110m=l,n >*/
L105:
	feq_gen_i_d_2 = *n;
	for (m = l; m <= feq_gen_i_d_2; ++m) {
/* SOURCE numrmath.for:167 */
/*<       if(m.eq.n)goto120 >*/
	    if (m == *n) {
		goto L120;
	    }
/* SOURCE numrmath.for:168 */
/*<       if(abs(e(m)).le.machep*(abs(d(m))+abs(d(m+1))))goto120 >*/
	    if ((feq_gen_d_d_3 = e[m], abs(feq_gen_d_d_3)) <= machep * ((feq_gen_d_d_1 = feq_gen_d_d_[m], abs(
		    feq_gen_d_d_1)) + (feq_gen_d_d_2 = feq_gen_d_d_[m + 1], abs(feq_gen_d_d_2)))) {
		goto L120;
	    }
/* SOURCE numrmath.for:170 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE numrmath.for:172 */
/*<   120 p=d(l) >*/
L120:
	p = feq_gen_d_d_[l];
/* SOURCE numrmath.for:173 */
/*<       if(m.eq.l)goto240 >*/
	if (m == l) {
	    goto L240;
	}
/* SOURCE numrmath.for:174 */
/*<       if(j.eq.30)goto1000 >*/
	if (j == 30) {
	    goto L1000;
	}
/* SOURCE numrmath.for:175 */
/*<       j=j+1 >*/
	++j;
/*        FORM SHIFT */
/* SOURCE numrmath.for:177 */
/*<       g=(d(l+1)-p)/(2.0d0*e(l)) >*/
	g = (feq_gen_d_d_[l + 1] - p) / (e[l] * 2.);
/* SOURCE numrmath.for:178 */
/*<       r=sqrt(g*g+1.0d0) >*/
	feq_gen_r_d_ = sqrt(g * g + 1.);
/* SOURCE numrmath.for:179 */
/*<       g=d(m)-p+e(l)/(g+sign(r,g)) >*/
	g = feq_gen_d_d_[m] - p + e[l] / (g + d_sign(&feq_gen_r_d_, &g));
/* SOURCE numrmath.for:180 */
/*<       s=1.0d0 >*/
	s = 1.;
/* SOURCE numrmath.for:181 */
/*<       c=1.0d0 >*/
	feq_gen_c_d_ = 1.;
/* SOURCE numrmath.for:182 */
/*<       p=0.0d0 >*/
	p = 0.;
/* SOURCE numrmath.for:183 */
/*<       mml=m-l >*/
	mml = m - l;
/*       FOR I=M-1 STEP -1 UNTIL L DO */
/* SOURCE numrmath.for:186 */
/*<       do200ii=1,mml >*/
	feq_gen_i_d_2 = mml;
	for (ii = 1; ii <= feq_gen_i_d_2; ++ii) {
/* SOURCE numrmath.for:187 */
/*<       i=m-ii >*/
	    feq_gen_i_d_ = m - ii;
/* SOURCE numrmath.for:188 */
/*<       f=s*e(i) >*/
	    f = s * e[feq_gen_i_d_];
/* SOURCE numrmath.for:189 */
/*<       b=c*e(i) >*/
	    b = feq_gen_c_d_ * e[feq_gen_i_d_];
/* SOURCE numrmath.for:190 */
/*<       if(abs(f).lt.abs(g))goto150 >*/
	    if (abs(f) < abs(g)) {
		goto L150;
	    }
/* SOURCE numrmath.for:191 */
/*<       c=g/f >*/
	    feq_gen_c_d_ = g / f;
/* SOURCE numrmath.for:192 */
/*<       r=sqrt(c*c+1.0d0) >*/
	    feq_gen_r_d_ = sqrt(feq_gen_c_d_ * feq_gen_c_d_ + 1.);
/* SOURCE numrmath.for:193 */
/*<       e(i+1)=f*r >*/
	    e[feq_gen_i_d_ + 1] = f * feq_gen_r_d_;
/* SOURCE numrmath.for:194 */
/*<       s=1.0d0/r >*/
	    s = 1. / feq_gen_r_d_;
/* SOURCE numrmath.for:195 */
/*<       c=c*s >*/
	    feq_gen_c_d_ *= s;
/* SOURCE numrmath.for:196 */
/*<       goto160 >*/
	    goto L160;
/* SOURCE numrmath.for:197 */
/*<   150 s=f/g >*/
L150:
	    s = f / g;
/* SOURCE numrmath.for:198 */
/*<       r=sqrt(s*s+1.0d0) >*/
	    feq_gen_r_d_ = sqrt(s * s + 1.);
/* SOURCE numrmath.for:199 */
/*<       e(i+1)=g*r >*/
	    e[feq_gen_i_d_ + 1] = g * feq_gen_r_d_;
/* SOURCE numrmath.for:200 */
/*<       c=1.0d0/r >*/
	    feq_gen_c_d_ = 1. / feq_gen_r_d_;
/* SOURCE numrmath.for:201 */
/*<       s=s*c >*/
	    s *= feq_gen_c_d_;
/* SOURCE numrmath.for:202 */
/*<   160 g=d(i+1)-p >*/
L160:
	    g = feq_gen_d_d_[feq_gen_i_d_ + 1] - p;
/* SOURCE numrmath.for:203 */
/*<       r=(d(i)-g)*s+2.0d0*c*b >*/
	    feq_gen_r_d_ = (feq_gen_d_d_[feq_gen_i_d_] - g) * s + feq_gen_c_d_ * 2. * b;
/* SOURCE numrmath.for:204 */
/*<       p=s*r >*/
	    p = s * feq_gen_r_d_;
/* SOURCE numrmath.for:205 */
/*<       d(i+1)=g+p >*/
	    feq_gen_d_d_[feq_gen_i_d_ + 1] = g + p;
/* SOURCE numrmath.for:206 */
/*<       g=c*r-b >*/
	    g = feq_gen_c_d_ * feq_gen_r_d_ - b;
/*         FORM FIRST COMPONENT OF VECTOR */
/* SOURCE numrmath.for:208 */
/*<       f=z(i+1) >*/
	    f = feq_gen_z_d_[feq_gen_i_d_ + 1];
/* SOURCE numrmath.for:209 */
/*<       z(i+1)=s*z(i)+c*f >*/
	    feq_gen_z_d_[feq_gen_i_d_ + 1] = s * feq_gen_z_d_[feq_gen_i_d_] + feq_gen_c_d_ * f;
/* SOURCE numrmath.for:210 */
/*<   200 z(i)=c*z(i)-s*f >*/
/* L200: */
	    feq_gen_z_d_[feq_gen_i_d_] = feq_gen_c_d_ * feq_gen_z_d_[feq_gen_i_d_] - s * f;
	}
/* SOURCE numrmath.for:212 */
/*<       d(l)=d(l)-p >*/
	feq_gen_d_d_[l] -= p;
/* SOURCE numrmath.for:213 */
/*<       e(l)=g >*/
	e[l] = g;
/* SOURCE numrmath.for:214 */
/*<       e(m)=0.0d0 >*/
	e[m] = 0.;
/* SOURCE numrmath.for:215 */
/*<       goto105 >*/
	goto L105;
/* SOURCE numrmath.for:216 */
/*<   240 continue >*/
L240:
	;
    }
/*     ORDER EIGENVALUES AND EIGENVECTORS */
/* SOURCE numrmath.for:219 */
/*<       do300ii=2,n >*/
    feq_gen_i_d_1 = *n;
    for (ii = 2; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE numrmath.for:220 */
/*<       i=ii-1 >*/
	feq_gen_i_d_ = ii - 1;
/* SOURCE numrmath.for:221 */
/*<       k=i >*/
	k = feq_gen_i_d_;
/* SOURCE numrmath.for:222 */
/*<       p=d(i) >*/
	p = feq_gen_d_d_[feq_gen_i_d_];
/* SOURCE numrmath.for:224 */
/*<       do260j=ii,n >*/
	feq_gen_i_d_2 = *n;
	for (j = ii; j <= feq_gen_i_d_2; ++j) {
/* SOURCE numrmath.for:225 */
/*<       if(d(j).ge.p)goto260 >*/
	    if (feq_gen_d_d_[j] >= p) {
		goto L260;
	    }
/* SOURCE numrmath.for:226 */
/*<       k=j >*/
	    k = j;
/* SOURCE numrmath.for:227 */
/*<       p=d(j) >*/
	    p = feq_gen_d_d_[j];
/* SOURCE numrmath.for:228 */
/*<   260 continue >*/
L260:
	    ;
	}
/* SOURCE numrmath.for:230 */
/*<       if(k.eq.i)goto300 >*/
	if (k == feq_gen_i_d_) {
	    goto L300;
	}
/* SOURCE numrmath.for:231 */
/*<       d(k)=d(i) >*/
	feq_gen_d_d_[k] = feq_gen_d_d_[feq_gen_i_d_];
/* SOURCE numrmath.for:232 */
/*<       d(i)=p >*/
	feq_gen_d_d_[feq_gen_i_d_] = p;
/* SOURCE numrmath.for:233 */
/*<       p=z(i) >*/
	p = feq_gen_z_d_[feq_gen_i_d_];
/* SOURCE numrmath.for:234 */
/*<       z(i)=z(k) >*/
	feq_gen_z_d_[feq_gen_i_d_] = feq_gen_z_d_[k];
/* SOURCE numrmath.for:235 */
/*<       z(k)=p >*/
	feq_gen_z_d_[k] = p;
/* SOURCE numrmath.for:236 */
/*<   300 continue >*/
L300:
	;
    }
/* SOURCE numrmath.for:238 */
/*<       goto1001 >*/
    goto L1001;
/*     SET ERROR -- NO CONVERGENCE TO AN */
/*     EIGENVALUE AFTER 30 ITERATIONS */
/* SOURCE numrmath.for:241 */
/*<  1000 ierr=l >*/
L1000:
    *ierr = l;
/* SOURCE numrmath.for:242 */
/*<  1001 return >*/
L1001:
    return 0;
/* SOURCE numrmath.for:243 */
/*<       end >*/
} /* imtql2_ */




/* SOURCE numrmath.for:247 */
/*<       subroutinegrule(n,x,w) >*/
/* Subroutine */ int grule_(integer *n, doublereal *feq_storage_x, doublereal *feq_storage_w)
{
    // All 256 supported orders verified against original GRULE/IMTQL2.
    const feq::GaussianRule rule = feq::gaussian_rule(static_cast<std::size_t>(*n));
    for (std::size_t index = 0; index < rule.nodes.size(); ++index) {
        feq_storage_x[index] = rule.nodes[index];
        feq_storage_w[index] = rule.weights[index];
    }
    return 0;
} /* grule_ */




/* SOURCE numrmath.for:330 */
/*<       subroutinesquank(a,b,eps,fun,err,err5,no,result) >*/
/* Subroutine */ int squank_(doublereal *a, doublereal *b, doublereal *eps, 
	FeqCallback1 fun, doublereal *err, doublereal *err5, integer *no, doublereal *
	result)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    doublereal t0, t1, t2, t3, x1, x2, x3, x4, x5, fx1, fx2, fx3, fx4, fx5, 
	    dim;
    integer nim;
    doublereal dum;
    integer lev, nom;
    doublereal est, sim;
    integer num;
    doublereal sum, est1, est2, x3st[30], x5st[30], diff, ceps, crit, fx3st[
	    30], adiff, fx5st[30], efact, cepsf, third, qceps, cepst, adiff1, 
	    estst[30], xzero, epmach, facerr, predif[30];
    integer levtag;

/*     + + + PURPOSE + + + */
/*     SQUANK -- Simpson quadrature used adaptively, noise killed. */
/* SOURCE numrmath.for:337 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE numrmath.for:340 */
/*<       integerno >*/
/* SOURCE numrmath.for:341 */
/*<       doubleprecisiona,b,eps,err,err5,result >*/
/*     + + + DUMMY ARGUMENT FUNCTIONS + + + */
/* SOURCE numrmath.for:344 */
/*<       doubleprecisionfun >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     A      - Lower limit for integration */
/*     B      - Upper limit for integration */
/*     EPS    - Convergence tolerance */
/*     FUN    - Integrand function */
/*     ERR    - Error indicator */
/*     ERR5   - Error indicator */
/*     NO     - Number of function evaluations */
/*     RESULT - Value of the integral */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE numrmath.for:357 */
/*<       integerlev,levtag,nim,nom,num >*/
/* SOURCE numrmath.for:358 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE numrmath.for:366 */
/*<       intrinsicdabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE numrmath.for:369 */
/*<       externalfun >*/
/* *********************************************************************** */
/*       Adapted from subroutine SQUANK from public domain library */
/*       which once existed at Stanford University. */
/*       This subroutine is basically the same as  the  one  published */
/*       by J. N. Lyness  as  ACM  Algorithm  379,  Comm.  A.C.M.  13, */
/*       1970, pp. 260-262. */
/*          ****    STAGE ONE    **** */
/*      INITIALISE QUANTITIES REQUIRED FOR CENTRAL CALCULATION (STAGE 3). */
/* SOURCE numrmath.for:381 */
/*<       sum=0.0 >*/
    sum = (float)0.;
/* SOURCE numrmath.for:382 */
/*<       sim=0.0 >*/
    sim = (float)0.;
/* SOURCE numrmath.for:383 */
/*<       dum=0.0 >*/
    dum = (float)0.;
/* SOURCE numrmath.for:384 */
/*<       dim=0.0 >*/
    dim = (float)0.;
/* SOURCE numrmath.for:385 */
/*<       cepsf=180.0*eps/(b-a) >*/
    cepsf = *eps * (float)180. / (*b - *a);
/* SOURCE numrmath.for:386 */
/*<       ceps=cepsf >*/
    ceps = cepsf;
/* SOURCE numrmath.for:387 */
/*<       adiff=0.0 >*/
    adiff = (float)0.;
/* SOURCE numrmath.for:388 */
/*<       levtag=-1 >*/
    levtag = -1;
/* SOURCE numrmath.for:389 */
/*<       facerr=1.0 >*/
    facerr = (float)1.;
/* SOURCE numrmath.for:390 */
/*<       xzero=a >*/
    xzero = *a;
/* SOURCE numrmath.for:391 */
/*<       efact=0.0 >*/
    efact = (float)0.;
/* SOURCE numrmath.for:392 */
/*<       nim=1 >*/
    nim = 1;
/* SOURCE numrmath.for:393 */
/*<       lev=0 >*/
    lev = 0;
/*     FIRST INTERVAL */
/* SOURCE numrmath.for:395 */
/*<       x1=a >*/
    x1 = *a;
/* SOURCE numrmath.for:396 */
/*<       x5=b >*/
    x5 = *b;
/* SOURCE numrmath.for:397 */
/*<       x3=0.5*(a+b) >*/
    x3 = (*a + *b) * (float).5;
/* SOURCE numrmath.for:398 */
/*<       fx1=fun(x1) >*/
    fx1 = (*fun)(&x1);
/* SOURCE numrmath.for:399 */
/*<       fx3=fun(x3) >*/
    fx3 = (*fun)(&x3);
/* SOURCE numrmath.for:400 */
/*<       fx5=fun(x5) >*/
    fx5 = (*fun)(&x5);
/* SOURCE numrmath.for:401 */
/*<       no=3 >*/
    *no = 3;
/* SOURCE numrmath.for:402 */
/*<       est=fx1+fx5+4.0*fx3 >*/
    est = fx1 + fx5 + fx3 * (float)4.;
/*          ****    STAGE TWO    **** */
/*      SET A STARTING VALUE FOR TOLERANCE IN CASE THAT CEPSF = 0.0 */
/* SOURCE numrmath.for:407 */
/*<       if(cepsf)295,205,295 >*/
    if (cepsf != 0.) {
	goto L295;
    } else {
	goto L205;
    }
/* SOURCE numrmath.for:408 */
/*<   205 levtag=0 >*/
L205:
    levtag = 0;
/* SOURCE numrmath.for:409 */
/*<       epmach=1. >*/
    epmach = (float)1.;
/* SOURCE numrmath.for:410 */
/*<   208 epmach=.5*epmach >*/
L208:
    epmach *= (float).5;
/* SOURCE numrmath.for:411 */
/*<       est1=epmach+1. >*/
    est1 = epmach + (float)1.;
/* SOURCE numrmath.for:412 */
/*<       if(est1.gt.1.)goto208 >*/
    if (est1 > (float)1.) {
	goto L208;
    }
/* SOURCE numrmath.for:413 */
/*<       facerr=15.0 >*/
    facerr = (float)15.;
/* SOURCE numrmath.for:414 */
/*<       ceps=epmach*dabs(fx1) >*/
    ceps = epmach * abs(fx1);
/* SOURCE numrmath.for:415 */
/*<       if(fx1)295,210,295 >*/
    if (fx1 != 0.) {
	goto L295;
    } else {
	goto L210;
    }
/* SOURCE numrmath.for:416 */
/*<   210 ceps=epmach*dabs(fx3) >*/
L210:
    ceps = epmach * abs(fx3);
/* SOURCE numrmath.for:417 */
/*<       levtag=3 >*/
    levtag = 3;
/* SOURCE numrmath.for:418 */
/*<       if(fx3)295,215,295 >*/
    if (fx3 != 0.) {
	goto L295;
    } else {
	goto L215;
    }
/* SOURCE numrmath.for:419 */
/*<   215 ceps=epmach*dabs(fx5) >*/
L215:
    ceps = epmach * abs(fx5);
/* SOURCE numrmath.for:420 */
/*<       if(fx5)295,220,295 >*/
    if (fx5 != 0.) {
	goto L295;
    } else {
	goto L220;
    }
/* SOURCE numrmath.for:421 */
/*<   220 ceps=epmach >*/
L220:
    ceps = epmach;
/* SOURCE numrmath.for:422 */
/*<   295 qceps=0.25*ceps >*/
L295:
    qceps = ceps * (float).25;
/*     INITIALISING COMPLETE */
/*          ****    STAGE THREE    **** */
/*      CENTRAL CALCULATION. */
/*                   REQUIRES X1,X3,X5,FX1,FX3,FX5,EST,ADIFF. */
/* SOURCE numrmath.for:429 */
/*<   300 continue >*/
L300:
/* SOURCE numrmath.for:430 */
/*<       x2=0.5*(x1+x3) >*/
    x2 = (x1 + x3) * (float).5;
/* SOURCE numrmath.for:431 */
/*<       x4=0.5*(x3+x5) >*/
    x4 = (x3 + x5) * (float).5;
/* SOURCE numrmath.for:432 */
/*<       fx2=fun(x2) >*/
    fx2 = (*fun)(&x2);
/* SOURCE numrmath.for:433 */
/*<       fx4=fun(x4) >*/
    fx4 = (*fun)(&x4);
/* SOURCE numrmath.for:434 */
/*<       no=no+2 >*/
    *no += 2;
/* SOURCE numrmath.for:435 */
/*<       est1=fx1+4.0*fx2+fx3 >*/
    est1 = fx1 + fx2 * (float)4. + fx3;
/* SOURCE numrmath.for:436 */
/*<       est2=fx3+4.0*fx4+fx5 >*/
    est2 = fx3 + fx4 * (float)4. + fx5;
/* SOURCE numrmath.for:437 */
/*<       adiff1=adiff >*/
    adiff1 = adiff;
/* SOURCE numrmath.for:438 */
/*<       diff=est+est-est1-est2 >*/
    diff = est + est - est1 - est2;
/* SOURCE numrmath.for:439 */
/*<       if(lev-30)305,800,800 >*/
    if (lev - 30 >= 0) {
	goto L800;
    } else {
	goto L305;
    }
/* SOURCE numrmath.for:440 */
/*<   305 adiff=dabs(diff) >*/
L305:
    adiff = abs(diff);
/* SOURCE numrmath.for:441 */
/*<       crit=adiff-ceps >*/
    crit = adiff - ceps;
/* SOURCE numrmath.for:442 */
/*<       if(crit)700,700,400 >*/
    if (crit <= 0.) {
	goto L700;
    } else {
	goto L400;
    }
/*     END OF CENTRAL LOOP */
/*      NEXT STAGE IS STAGE FOUR  IN CASE OF NO NATURAL CONVERGENCE */
/*      NEXT STAGE IS STAGE SEVEN IN CASE OF    NATURAL CONVERGENCE */
/*          ****    STAGE FOUR    **** */
/*      NO NATURAL CONVERGENCE.  A COMPLEX SEQUENCE OF INSTRUCTIONS */
/*      FOLLOWS WHICH ASSIGNS CONVERGENCE AND / OR ALTERS TOLERANCE */
/*      LEVEL IN UPWARD DIRECTION IF THERE ARE INDICATIONS OF ROUND OFF */
/*      ERROR. */
/* SOURCE numrmath.for:453 */
/*<   400 continue >*/
L400:
/* SOURCE numrmath.for:454 */
/*<       if(adiff1-adiff)410,410,500 >*/
    if (adiff1 - adiff <= 0.) {
	goto L410;
    } else {
	goto L500;
    }
/*      IN A NORMAL RUN WITH NO ROUND OFF ERROR PROBLEM,  ADIFF1  IS */
/*      GREATER THAN ADIFF  AND THE REST OF STAGE FOUR IS OMITTED. */
/* SOURCE numrmath.for:457 */
/*<   410 if(lev-5)500,415,415 >*/
L410:
    if (lev - 5 >= 0) {
	goto L415;
    } else {
	goto L500;
    }
/* SOURCE numrmath.for:458 */
/*<   415 efact=efact+ceps*(x1-xzero)*facerr >*/
L415:
    efact += ceps * (x1 - xzero) * facerr;
/* SOURCE numrmath.for:459 */
/*<       xzero=x1 >*/
    xzero = x1;
/* SOURCE numrmath.for:460 */
/*<       facerr=15.0 >*/
    facerr = (float)15.;
/*      THE REST OF STAGE FOUR DEALS WITH UPWARD ADJUSTMENT OF */
/*      TOLERANCE (CEPS) BECAUSE OF SUSPECTED ROUND OFF ERROR TROUBLE. */
/* SOURCE numrmath.for:463 */
/*<       if(adiff-2.0*ceps)420,420,425 >*/
    if (adiff - ceps * (float)2. <= 0.) {
	goto L420;
    } else {
	goto L425;
    }
/*      SMALL JUMP IN CEPS. ASSIGN CONVERGENCE */
/* SOURCE numrmath.for:465 */
/*<   420 ceps=adiff >*/
L420:
    ceps = adiff;
/* SOURCE numrmath.for:466 */
/*<       levtag=0 >*/
    levtag = 0;
/* SOURCE numrmath.for:467 */
/*<       goto780 >*/
    goto L780;
/* SOURCE numrmath.for:468 */
/*<   425 if(adiff1-adiff)435,430,435 >*/
L425:
    if (adiff1 - adiff != 0.) {
	goto L435;
    } else {
	goto L430;
    }
/*      LARGE JUMP IN CEPS */
/* SOURCE numrmath.for:470 */
/*<   430 ceps=adiff >*/
L430:
    ceps = adiff;
/* SOURCE numrmath.for:471 */
/*<       levtag=3 >*/
    levtag = 3;
/* SOURCE numrmath.for:472 */
/*<       goto445 >*/
    goto L445;
/*      FACTOR TWO  JUMP IN CEPS */
/* SOURCE numrmath.for:474 */
/*<   435 ceps=2.0*ceps >*/
L435:
    ceps *= (float)2.;
/* SOURCE numrmath.for:475 */
/*<       if(levtag-3)440,445,445 >*/
    if (levtag - 3 >= 0) {
	goto L445;
    } else {
	goto L440;
    }
/* SOURCE numrmath.for:476 */
/*<   440 levtag=2 >*/
L440:
    levtag = 2;
/* SOURCE numrmath.for:477 */
/*<   445 qceps=0.25*ceps >*/
L445:
    qceps = ceps * (float).25;
/*          ****    STAGE FIVE    **** */
/*       NO ACTUAL CONVERGENCE. */
/*     STORE RIGHT HAND ELEMENTS */
/* SOURCE numrmath.for:483 */
/*<   500 continue >*/
L500:
/* SOURCE numrmath.for:484 */
/*<       nim=2*nim >*/
    nim <<= 1;
/* SOURCE numrmath.for:485 */
/*<       lev=lev+1 >*/
    ++lev;
/* SOURCE numrmath.for:486 */
/*<       estst(lev)=est2 >*/
    estst[lev - 1] = est2;
/* SOURCE numrmath.for:487 */
/*<       x3st(lev)=x4 >*/
    x3st[lev - 1] = x4;
/* SOURCE numrmath.for:488 */
/*<       x5st(lev)=x5 >*/
    x5st[lev - 1] = x5;
/* SOURCE numrmath.for:489 */
/*<       fx3st(lev)=fx4 >*/
    fx3st[lev - 1] = fx4;
/* SOURCE numrmath.for:490 */
/*<       fx5st(lev)=fx5 >*/
    fx5st[lev - 1] = fx5;
/* SOURCE numrmath.for:491 */
/*<       predif(lev)=adiff >*/
    predif[lev - 1] = adiff;
/*          ****    STAGE SIX    **** */
/*      SET UP QUANTITIES FOR CENTRAL CALCULATION. */
/*     READY TO GO AHEAD AT LEVEL LOWER WITH LEFT HAND ELEMENTS */
/*     X1 AND FX1 ARE THE SAME AS BEFORE */
/* SOURCE numrmath.for:498 */
/*<       x5=x3 >*/
    x5 = x3;
/* SOURCE numrmath.for:499 */
/*<       x3=x2 >*/
    x3 = x2;
/* SOURCE numrmath.for:500 */
/*<       fx5=fx3 >*/
    fx5 = fx3;
/* SOURCE numrmath.for:501 */
/*<       fx3=fx2 >*/
    fx3 = fx2;
/* SOURCE numrmath.for:502 */
/*<       est=est1 >*/
    est = est1;
/* SOURCE numrmath.for:503 */
/*<       goto300 >*/
    goto L300;
/*          ****    STAGE SEVEN    **** */
/*      NATURAL CONVERGENCE IN PREVIOUS INTERVAL. THE  FOLLOWING  COMPLEX */
/*      SEQUENCE  CHECKS  PRIMARILY THAT TOLERANCE LEVEL IS NOT TOO HIGH. */
/*      UNDER CERTAIN CIRCUMSTANCES  NON CONVERGENCE IS ASSIGNED AND / OR */
/*      TOLERANCE LEVEL IS RE-SET. */
/* SOURCE numrmath.for:511 */
/*<   700 continue >*/
L700:
/*      CHECK THAT IT WAS NOT LEVEL ZERO INTERVAL. IF SO ASSIGN */
/*      NON CONVERGENCE */
/* SOURCE numrmath.for:514 */
/*<       if(lev)400,400,705 >*/
    if (lev <= 0) {
	goto L400;
    } else {
	goto L705;
    }
/*      LEVTAG =-1   CEPS = CEPSF, ITS ORIGINAL VALUE. */
/*      LEVTAG = 0   CEPS IS GREATER THAN CEPSF. REGULAR SITUATION. */
/*      LEVTAG = 2   CEPS IS GREATER THAN CEPSF. CEPS PREVIOUSLY */
/*                           ASKED FOR A BIG JUMP, BUT DID NOT GET ONE. */
/*      LEVTAG = 3   CEPS IS GREATER THAN CEPSF. CEPS PREVIOUSLY HAD */
/*                           A BIG JUMP. */
/* SOURCE numrmath.for:522 */
/*<   705 if(levtag)800,710,710 >*/
L705:
    if (levtag >= 0) {
	goto L710;
    } else {
	goto L800;
    }
/*      IN A NORMAL RUN WITH NO ROUND OFF ERROR PROBLEM,  LEVTAG = -1 */
/*      AND THE REST OF STAGE SEVEN IS OMITTED. */
/* SOURCE numrmath.for:525 */
/*<   710 cepst=15.0*ceps >*/
L710:
    cepst = ceps * (float)15.;
/*      CEPST HERE IS FACERR*CURRENT VALUE OF CEPS */
/* SOURCE numrmath.for:527 */
/*<       if(crit)715,800,800 >*/
    if (crit >= 0.) {
	goto L800;
    } else {
	goto L715;
    }
/* SOURCE numrmath.for:528 */
/*<   715 if(levtag-2)720,740,750 >*/
L715:
    if ((feq_gen_i_d_1 = levtag - 2) < 0) {
	goto L720;
    } else if (feq_gen_i_d_1 == 0) {
	goto L740;
    } else {
	goto L750;
    }
/*      LEVTAG = 0 */
/* SOURCE numrmath.for:530 */
/*<   720 if(adiff)800,800,725 >*/
L720:
    if (adiff <= 0.) {
	goto L800;
    } else {
	goto L725;
    }
/* SOURCE numrmath.for:531 */
/*<   725 if(adiff-qceps)730,800,800 >*/
L725:
    if (adiff - qceps >= 0.) {
	goto L800;
    } else {
	goto L730;
    }
/* SOURCE numrmath.for:532 */
/*<   730 if(adiff-cepsf)770,770,735 >*/
L730:
    if (adiff - cepsf <= 0.) {
	goto L770;
    } else {
	goto L735;
    }
/* SOURCE numrmath.for:533 */
/*<   735 levtag=0 >*/
L735:
    levtag = 0;
/* SOURCE numrmath.for:534 */
/*<       ceps=adiff >*/
    ceps = adiff;
/* SOURCE numrmath.for:535 */
/*<       efact=efact+cepst*(x1-xzero) >*/
    efact += cepst * (x1 - xzero);
/* SOURCE numrmath.for:536 */
/*<       xzero=x1 >*/
    xzero = x1;
/* SOURCE numrmath.for:537 */
/*<       goto445 >*/
    goto L445;
/*      LEVTAG = 2 */
/* SOURCE numrmath.for:539 */
/*<   740 levtag=0 >*/
L740:
    levtag = 0;
/* SOURCE numrmath.for:540 */
/*<       if(adiff)765,765,725 >*/
    if (adiff <= 0.) {
	goto L765;
    } else {
	goto L725;
    }
/*      LEVTAG = 3 */
/* SOURCE numrmath.for:542 */
/*<   750 levtag=0 >*/
L750:
    levtag = 0;
/* SOURCE numrmath.for:543 */
/*<       if(adiff)775,775,730 >*/
    if (adiff <= 0.) {
	goto L775;
    } else {
	goto L730;
    }
/* SOURCE numrmath.for:544 */
/*<   765 ceps=adiff1 >*/
L765:
    ceps = adiff1;
/* SOURCE numrmath.for:545 */
/*<       goto775 >*/
    goto L775;
/* SOURCE numrmath.for:546 */
/*<   770 levtag=-1 >*/
L770:
    levtag = -1;
/* SOURCE numrmath.for:547 */
/*<       facerr=1.0 >*/
    facerr = (float)1.;
/* SOURCE numrmath.for:548 */
/*<       ceps=cepsf >*/
    ceps = cepsf;
/* SOURCE numrmath.for:549 */
/*<   775 efact=efact+cepst*(x1-xzero) >*/
L775:
    efact += cepst * (x1 - xzero);
/* SOURCE numrmath.for:550 */
/*<       xzero=x1 >*/
    xzero = x1;
/* SOURCE numrmath.for:551 */
/*<   780 continue >*/
L780:
/* SOURCE numrmath.for:552 */
/*<       qceps=0.25*ceps >*/
    qceps = ceps * (float).25;
/*          ****    STAGE EIGHT    **** */
/*      ACTUAL CONVERGENCE IN PREVIOUS INTERVAL.  INCREMENTS ADDED INTO */
/*      RUNNING SUMS */
/*     ADD INTO SUM AND SIM */
/* SOURCE numrmath.for:558 */
/*<   800 continue >*/
L800:
/*  THE FOLLOWING CODING AVOIDS LOSS OF PRECISION IN ACCUMULATING THE */
/*  SUM.  IT CORRESPONDS TO */
/*     SUM = SUM + T1 */
/* SOURCE numrmath.for:563 */
/*<       t1=(est1+est2)*(x5-x1) >*/
    t1 = (est1 + est2) * (x5 - x1);
/* SOURCE numrmath.for:564 */
/*<       t0=sum+t1 >*/
    t0 = sum + t1;
/* SOURCE numrmath.for:565 */
/*<       t2=dabs(t1) >*/
    t2 = abs(t1);
/* SOURCE numrmath.for:566 */
/*<       t3=dabs(sum) >*/
    t3 = abs(sum);
/* SOURCE numrmath.for:567 */
/*<       if(t2.gt.t3)goto801 >*/
    if (t2 > t3) {
	goto L801;
    }
/* SOURCE numrmath.for:568 */
/*<       dum=dum+t1-(t0-sum) >*/
    dum = dum + t1 - (t0 - sum);
/* SOURCE numrmath.for:569 */
/*<       goto802 >*/
    goto L802;
/* SOURCE numrmath.for:570 */
/*<   801 dum=dum+sum-(t0-t1) >*/
L801:
    dum = dum + sum - (t0 - t1);
/* SOURCE numrmath.for:571 */
/*<   802 sum=t0 >*/
L802:
    sum = t0;
/* SOURCE numrmath.for:572 */
/*<       if(levtag)805,810,810 >*/
    if (levtag >= 0) {
	goto L810;
    } else {
	goto L805;
    }
/*      WE ADD INTO SIM ONLY IF WE ARE CLEAR OF ROUND OFF LEVEL. */
/* SOURCE numrmath.for:574 */
/*<   805 t1=diff*(x5-x1) >*/
L805:
    t1 = diff * (x5 - x1);
/* SOURCE numrmath.for:575 */
/*<       t0=sum+t1 >*/
    t0 = sum + t1;
/* SOURCE numrmath.for:576 */
/*<       t2=dabs(t1) >*/
    t2 = abs(t1);
/* SOURCE numrmath.for:577 */
/*<       t3=dabs(sim) >*/
    t3 = abs(sim);
/* SOURCE numrmath.for:578 */
/*<       if(t2.gt.t3)goto806 >*/
    if (t2 > t3) {
	goto L806;
    }
/* SOURCE numrmath.for:579 */
/*<       dim=dim+t1-(t0-sim) >*/
    dim = dim + t1 - (t0 - sim);
/* SOURCE numrmath.for:580 */
/*<       goto807 >*/
    goto L807;
/* SOURCE numrmath.for:581 */
/*<   806 dim=dim+sim-(t0-t1) >*/
L806:
    dim = dim + sim - (t0 - t1);
/* SOURCE numrmath.for:582 */
/*<   807 sim=t0 >*/
L807:
    sim = t0;
/* SOURCE numrmath.for:583 */
/*<   810 continue >*/
L810:
/*          ****    STAGE NINE    **** */
/*      SORT OUT WHICH LEVEL TO GO TO.  THIS INVOLVES NIM NUMBERING */
/*      SYSTEM DESCRIBED BEFORE STAGE ONE. */
/* SOURCE numrmath.for:589 */
/*<   905 num=nim/2 >*/
L905:
    num = nim / 2;
/* SOURCE numrmath.for:590 */
/*<       nom=nim-2*num >*/
    nom = nim - (num << 1);
/* SOURCE numrmath.for:591 */
/*<       if(nom)910,915,910 >*/
    if (nom != 0) {
	goto L910;
    } else {
	goto L915;
    }
/* SOURCE numrmath.for:592 */
/*<   910 nim=num >*/
L910:
    nim = num;
/* SOURCE numrmath.for:593 */
/*<       lev=lev-1 >*/
    --lev;
/* SOURCE numrmath.for:594 */
/*<       goto905 >*/
    goto L905;
/* SOURCE numrmath.for:595 */
/*<   915 nim=nim+1 >*/
L915:
    ++nim;
/*     NEW LEVEL IS SET. IF LEV=0 WE HAVE FINISHED */
/* SOURCE numrmath.for:597 */
/*<       if(lev)1100,1100,1000 >*/
    if (lev <= 0) {
	goto L1100;
    } else {
	goto L1000;
    }
/*          ****    STAGE TEN    **** */
/*      SET UP QUANTITIES FOR CENTRAL CALCULATION. */
/* SOURCE numrmath.for:602 */
/*<  1000 continue >*/
L1000:
/* SOURCE numrmath.for:603 */
/*<       x1=x5 >*/
    x1 = x5;
/* SOURCE numrmath.for:604 */
/*<       fx1=fx5 >*/
    fx1 = fx5;
/* SOURCE numrmath.for:605 */
/*<       x3=x3st(lev) >*/
    x3 = x3st[lev - 1];
/* SOURCE numrmath.for:606 */
/*<       x5=x5st(lev) >*/
    x5 = x5st[lev - 1];
/* SOURCE numrmath.for:607 */
/*<       fx3=fx3st(lev) >*/
    fx3 = fx3st[lev - 1];
/* SOURCE numrmath.for:608 */
/*<       fx5=fx5st(lev) >*/
    fx5 = fx5st[lev - 1];
/* SOURCE numrmath.for:609 */
/*<       est=estst(lev) >*/
    est = estst[lev - 1];
/* SOURCE numrmath.for:610 */
/*<       adiff=predif(lev) >*/
    adiff = predif[lev - 1];
/* SOURCE numrmath.for:611 */
/*<       goto300 >*/
    goto L300;
/*          ****    STAGE ELEVEN    **** */
/*      CALCULATION NOW COMPLETE. FINALISE. */
/* SOURCE numrmath.for:616 */
/*<  1100 continue >*/
L1100:
/* SOURCE numrmath.for:617 */
/*<       efact=efact+ceps*(b-xzero)*facerr >*/
    efact += ceps * (*b - xzero) * facerr;
/* SOURCE numrmath.for:618 */
/*<       err=efact/180.0 >*/
    *err = efact / (float)180.;
/* SOURCE numrmath.for:619 */
/*<       third=(sum+dum)/12.0 >*/
    third = (sum + dum) / (float)12.;
/* SOURCE numrmath.for:620 */
/*<       err5=-(sim+dim)/180.0 >*/
    *err5 = -(sim + dim) / (float)180.;
/* SOURCE numrmath.for:621 */
/*<       result=third+err5 >*/
    *result = third + *err5;
/* SOURCE numrmath.for:622 */
/*<       return >*/
    return 0;
/* SOURCE numrmath.for:623 */
/*<       end >*/
} /* squank_ */




/* SOURCE numrmath.for:627 */
/*<       subroutineqfun(a,b,fun,qerr,result) >*/
/* Subroutine */ int qfun_(real *a, real *b, FeqCallback1 fun, real *qerr, doublereal 
	*result)
{
    integer n;
    doublereal tp, eps, err, err5, adbl, bdbl;
    integer limflg;
    extern /* Subroutine */ int squank_(doublereal *, doublereal *, 
	    doublereal *, FeqCallback1, doublereal *, doublereal *, integer *, 
	    doublereal *);

/*     + + + PURPOSE + + + */
/*     Integrate the double precision function, FUN, between the limits */
/*     of A and B.  Standard error limits are obtained from EPSCOM. */
/* SOURCE numrmath.for:635 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE numrmath.for:638 */
/*<       reala,b,qerr >*/
/* SOURCE numrmath.for:639 */
/*<       doubleprecisionresult >*/
/*     + + + DUMMY ARGUMENT FUNCTIONS + + + */
/* SOURCE numrmath.for:642 */
/*<       doubleprecisionfun >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     A      - Lower limit for integration */
/*     B      - Upper limit for integration */
/*     FUN    - Integrand function */
/*     QERR   - Quadrature error */
/*     RESULT - Value of the integral */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE numrmath.for:652 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE numrmath.for:653 */
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
/* SOURCE numrmath.for:656 */
/*<       integerlimflg,n >*/
/* SOURCE numrmath.for:657 */
/*<       doubleprecisionabserr,adbl,bdbl,eps,err,err5,tp >*/
/*     + + + INTRINSICS + + + */
/* SOURCE numrmath.for:660 */
/*<       intrinsicdble >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE numrmath.for:663 */
/*<       externalfun,squank >*/
/*     *********************************FORMATS************************** */
/* 50    FORMAT(' QFUN: ERR=',1PE12.4,' ERR5=',1PE12.4,' N=',I7) */
/* *********************************************************************** */
/*     SET THE DOUBLE PRECISION LIMITS */
/* SOURCE numrmath.for:669 */
/*<       adbl=dble(a) >*/
    adbl = (doublereal) (*a);
/* SOURCE numrmath.for:670 */
/*<       bdbl=dble(b) >*/
    bdbl = (doublereal) (*b);
/* SOURCE numrmath.for:672 */
/*<       if(adbl.gt.bdbl)then >*/
    if (adbl > bdbl) {
/*       SWITCH LIMITS BECAUSE SOME QUADRATURE ROUTINES FAIL TO FUNCTION */
/*       IF A > B. */
/* SOURCE numrmath.for:676 */
/*<       limflg=1 >*/
	limflg = 1;
/* SOURCE numrmath.for:677 */
/*<       tp=bdbl >*/
	tp = bdbl;
/* SOURCE numrmath.for:678 */
/*<       bdbl=adbl >*/
	bdbl = adbl;
/* SOURCE numrmath.for:679 */
/*<       adbl=tp >*/
	adbl = tp;
/* SOURCE numrmath.for:680 */
/*<       else >*/
    } else {
/* SOURCE numrmath.for:681 */
/*<       limflg=0 >*/
	limflg = 0;
/* SOURCE numrmath.for:682 */
/*<       endif >*/
    }
/*     SET THE ERROR TOLERANCES */
/* SOURCE numrmath.for:685 */
/*<       eps=epsint >*/
    eps = epscom_1.epsint;
/* SOURCE numrmath.for:688 */
/*<       if(adbl.ne.bdbl)then >*/
    if (adbl != bdbl) {
/* SOURCE numrmath.for:689 */
/*<       if(inthow.eq.1)then >*/
	if (epscom_1.inthow == 1) {
/*         USE ADAPTIVE SIMPSON'S RULE */
/* SOURCE numrmath.for:691 */
/*<       callsquank(adbl,bdbl,eps,fun,err,err5,n,result) >*/
	    squank_(&adbl, &bdbl, &eps, fun, &err, &err5, &n, result);
/* SOURCE numrmath.for:694 */
/*<       qerr=err >*/
	    *qerr = err;
/*          WRITE(STD6,50) ERR, ERR5, N */
/* SOURCE numrmath.for:696 */
/*<       else >*/
	} else {
/* SOURCE numrmath.for:697 */
/*<       callsquank(adbl,bdbl,eps,fun,err,err5,n,result) >*/
	    squank_(&adbl, &bdbl, &eps, fun, &err, &err5, &n, result);
/* SOURCE numrmath.for:700 */
/*<       qerr=err >*/
	    *qerr = err;
/*          WRITE(STD6,50) ERR, ERR5, N */
/* SOURCE numrmath.for:702 */
/*<       endif >*/
	}
/* SOURCE numrmath.for:703 */
/*<       else >*/
    } else {
/* SOURCE numrmath.for:704 */
/*<       result=0.0d0 >*/
	*result = 0.;
/* SOURCE numrmath.for:705 */
/*<       endif >*/
    }
/* SOURCE numrmath.for:706 */
/*<       if(limflg.eq.1)then >*/
    if (limflg == 1) {
/* SOURCE numrmath.for:707 */
/*<       result=-result >*/
	*result = -(*result);
/* SOURCE numrmath.for:708 */
/*<       endif >*/
    }
/* SOURCE numrmath.for:710 */
/*<       return >*/
    return 0;
/* SOURCE numrmath.for:711 */
/*<       end >*/
} /* qfun_ */

#ifdef __cplusplus
	}
#endif
