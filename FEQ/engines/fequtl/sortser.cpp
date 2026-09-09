/* sortser.f -- translated by f2c (version 20240504).
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

/*     Stuff for sorting and searching of all kinds. */



/* SOURCE sortser.for:6 */
/*<       subroutineinsert(value,eps,maxn,n,vec,eflag) >*/
/* Subroutine */ int insert_(real *value, real *eps, integer *maxn, integer *
	n, real *feq_storage_vec, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    integer feq_gen_i_d_, j;

/*     + + + PURPOSE + + + */
/*     Insert the real value, VALUE, in the proper location in */
/*     the ascending-ordered vector of distinct non-negative real */
/*     values, VEC.  On entry N gives the number of items in the */
/*     list and on exit gives the new number of items in the list. */
/*     MAXN gives the maximum extent permitted for VEC.  EPS is the */
/*     absolute tolerance for VALUE to be taken as matching */
/*     an item in the list.  If a match occurs VALUE is not */
/*     added to the list. EFLAG flags that there is no room to */
/*     add the item. */
/* SOURCE sortser.for:22 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE sortser.for:25 */
/*<       integereflag,maxn,n >*/
/* SOURCE sortser.for:26 */
/*<       realeps,value,vec(maxn) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     VALUE  - item to insert */
/*     EPS    - tolerance for a match */
/*     MAXN   - maximum extent of arrays */
/*     N      - number of items in list */
/*     VEC    - vector getting the inserted value */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sortser.for:37 */
/*<       integeri,j >*/
/* *********************************************************************** */
/* SOURCE sortser.for:39 */
/*<       if(n+1.gt.maxn)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> vec(feq_storage_vec, 1);

    /* Function Body */
    if (*n + 1 > *maxn) {
/* SOURCE sortser.for:40 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE sortser.for:41 */
/*<       else >*/
    } else {
/*       There is room to add to the list.  Do the limiting items */
/*       first. */
/* SOURCE sortser.for:44 */
/*<       if(value.gt.vec(n)+eps)then >*/
	if (*value > static_cast<double>(vec[*n]) + *eps) {
/*         Add to the top of the list. */
/* SOURCE sortser.for:46 */
/*<       n=n+1 >*/
	    ++(*n);
/* SOURCE sortser.for:47 */
/*<       vec(n)=value >*/
	    vec[*n] = *value;
/* SOURCE sortser.for:48 */
/*<       elseif(value.lt.vec(1)-eps)then >*/
	} else if (*value < static_cast<double>(vec[1]) - *eps) {
/*         Add to the beginning of the list. */
/* SOURCE sortser.for:50 */
/*<       do100i=n,1,-1 >*/
	    for (feq_gen_i_d_ = *n; feq_gen_i_d_ >= 1; --feq_gen_i_d_) {
/* SOURCE sortser.for:51 */
/*<       vec(i+1)=vec(i) >*/
		vec[feq_gen_i_d_ + 1] = vec[feq_gen_i_d_];
/* SOURCE sortser.for:52 */
/*<   100 continue >*/
/* L100: */
	    }
/* SOURCE sortser.for:53 */
/*<       vec(1)=value >*/
	    vec[1] = *value;
/* SOURCE sortser.for:54 */
/*<       n=n+1 >*/
	    ++(*n);
/* SOURCE sortser.for:55 */
/*<       else >*/
	} else {
/*         Insert at some intermediate point.  Find the interval */
/*         that contains VALUE.  Check for a match and if not */
/*         found insert it. */
/* SOURCE sortser.for:59 */
/*<       do120i=2,n >*/
	    feq_gen_i_d_1 = *n;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE sortser.for:60 */
/*<       if(value.le.vec(i))then >*/
		if (*value <= vec[feq_gen_i_d_]) {
/*             Found upper end of interval containing VALUE. */
/* SOURCE sortser.for:62 */
/*<       if(value.gt.vec(i-1)+eps.and.value.lt.vec(i)-eps)then >*/
		    if (*value > static_cast<double>(vec[feq_gen_i_d_ - 1]) + *eps && *value < static_cast<double>(vec[feq_gen_i_d_]) - *
			    eps) {
/*               Insert it. */
/* SOURCE sortser.for:64 */
/*<       do110j=n,i,-1 >*/
			feq_gen_i_d_2 = feq_gen_i_d_;
			for (j = *n; j >= feq_gen_i_d_2; --j) {
/* SOURCE sortser.for:65 */
/*<       vec(j+1)=vec(j) >*/
			    vec[j + 1] = vec[j];
/* SOURCE sortser.for:66 */
/*<   110 continue >*/
/* L110: */
			}
/* SOURCE sortser.for:67 */
/*<       vec(i)=value >*/
			vec[feq_gen_i_d_] = *value;
/* SOURCE sortser.for:68 */
/*<       n=n+1 >*/
			++(*n);
/* SOURCE sortser.for:69 */
/*<       goto130 >*/
			goto L130;
/* SOURCE sortser.for:70 */
/*<       endif >*/
		    }
/* SOURCE sortser.for:71 */
/*<       endif >*/
		}
/* SOURCE sortser.for:72 */
/*<   120 continue >*/
/* L120: */
	    }
/* SOURCE sortser.for:73 */
/*<   130 continue >*/
L130:
/* SOURCE sortser.for:74 */
/*<       endif >*/
	    ;
	}
/* SOURCE sortser.for:75 */
/*<       endif >*/
    }
/* SOURCE sortser.for:76 */
/*<       return >*/
    return 0;
/* SOURCE sortser.for:77 */
/*<       end >*/
} /* insert_ */




/* SOURCE sortser.for:81 */
/*<       subroutinesort(n,x) >*/
/* Subroutine */ int sort_(integer *n, real *feq_storage_x)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, j;
    real t;

/*     + + + PURPOSE + + + */
/*     Sort the real array, X(*), of length N into ascending */
/*     numerical order. */
/* SOURCE sortser.for:89 */
/*<       implicitnone >*/
/*     DUMMY ARGUMENTS */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE sortser.for:94 */
/*<       integern >*/
/* SOURCE sortser.for:95 */
/*<       realx(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - Number of items to sort */
/*     X      - Values to be sorted */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sortser.for:102 */
/*<       integeri,j >*/
/* SOURCE sortser.for:103 */
/*<       realt >*/
/* *********************************************************************** */
/* SOURCE sortser.for:105 */
/*<       do200i=2,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE sortser.for:106 */
/*<       j=i >*/
	j = feq_gen_i_d_;
/* SOURCE sortser.for:107 */
/*<       t=x(j) >*/
	t = x[j];
/* SOURCE sortser.for:108 */
/*<   100 continue >*/
L100:
/* SOURCE sortser.for:109 */
/*<       if(j.gt.1.and.x(j-1).gt.t)then >*/
	if (j > 1 && x[j - 1] > t) {
/* SOURCE sortser.for:110 */
/*<       x(j)=x(j-1) >*/
	    x[j] = x[j - 1];
/* SOURCE sortser.for:111 */
/*<       j=j-1 >*/
	    --j;
/* SOURCE sortser.for:112 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE sortser.for:113 */
/*<       endif >*/
	}
/* SOURCE sortser.for:114 */
/*<       x(j)=t >*/
	x[j] = t;
/* SOURCE sortser.for:115 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE sortser.for:117 */
/*<       return >*/
    return 0;
/* SOURCE sortser.for:118 */
/*<       end >*/
} /* sort_ */




/* SOURCE sortser.for:122 */
/*<       subroutinesort2(n,rval,rvala) >*/
/* Subroutine */ int sort2_(integer *n, char *feq_storage_rval, integer *feq_storage_rvala, ftnlen 
	rval_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;
    char t[8];
    integer ta;

/*     + + + PURPOSE + + + */
/*     Sort RVAL into ascending order and move other values at */
/*     same time. */
/* SOURCE sortser.for:130 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE sortser.for:133 */
/*<       integern >*/
/* SOURCE sortser.for:134 */
/*<       integerrvala(n) >*/
/* SOURCE sortser.for:135 */
/*<       characterrval(n)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - Number of items to sort */
/*     RVAL   - Values to sort */
/*     RVALA  - Value to move as RVAL is sorted */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sortser.for:143 */
/*<       integeri,j,ta >*/
/* SOURCE sortser.for:144 */
/*<       charactert*8 >*/
/* *********************************************************************** */
/*     USE INSERTION SORT FROM PROGRAMMING PEARLS */
/*     COMM. OF ACM APRIL 1984 */
/* SOURCE sortser.for:149 */
/*<       do200i=2,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> rvala(feq_storage_rvala, 1);

    feq::IndexedPointer<char> rval(feq_storage_rval, 8);

    /* Function Body */
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE sortser.for:150 */
/*<       j=i >*/
	j = feq_gen_i_d_;
/* SOURCE sortser.for:151 */
/*<       t=rval(j) >*/
	s_copy(t, rval + (j << 3), (ftnlen)8, (ftnlen)8);
/* SOURCE sortser.for:152 */
/*<       ta=rvala(j) >*/
	ta = rvala[j];
/* SOURCE sortser.for:153 */
/*<   100 continue >*/
L100:
/* SOURCE sortser.for:155 */
/*<       if(j.gt.1.and.rval(j-1).gt.t)then >*/
	if (j > 1 && s_cmp(rval + (j - 1 << 3), t, (ftnlen)8, (ftnlen)8) > 0) 
		{
/* SOURCE sortser.for:156 */
/*<       rval(j)=rval(j-1) >*/
	    s_copy(rval + (j << 3), rval + (j - 1 << 3), (ftnlen)8, (ftnlen)8)
		    ;
/* SOURCE sortser.for:157 */
/*<       rvala(j)=rvala(j-1) >*/
	    rvala[j] = rvala[j - 1];
/* SOURCE sortser.for:159 */
/*<       j=j-1 >*/
	    --j;
/* SOURCE sortser.for:161 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE sortser.for:162 */
/*<       endif >*/
	}
/* SOURCE sortser.for:163 */
/*<       rval(j)=t >*/
	s_copy(rval + (j << 3), t, (ftnlen)8, (ftnlen)8);
/* SOURCE sortser.for:164 */
/*<       rvala(j)=ta >*/
	rvala[j] = ta;
/* SOURCE sortser.for:166 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE sortser.for:168 */
/*<       return >*/
    return 0;
/* SOURCE sortser.for:169 */
/*<       end >*/
} /* sort2_ */




/* SOURCE sortser.for:173 */
/*<       subroutinesort2r(n,rval,rvala) >*/
/* Subroutine */ int sort2r_(integer *n, real *feq_storage_rval, real *feq_storage_rvala)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, j;
    real t, ta;

/*     + + + PURPOSE + + + */
/*     Sort RVAL into ascending order and move other values at same time */
/* SOURCE sortser.for:180 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE sortser.for:183 */
/*<       integern >*/
/* SOURCE sortser.for:184 */
/*<       realrval(n),rvala(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - Number of items to sort */
/*     RVAL   - Values to sort */
/*     RVALA  - Value to move as RVAL is sorted */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sortser.for:192 */
/*<       integeri,j >*/
/* SOURCE sortser.for:193 */
/*<       realt,ta >*/
/* *********************************************************************** */
/*     USE INSERTION SORT FROM PROGRAMMING PEARLS */
/*     COMM. OF ACM APRIL 1984 */
/* SOURCE sortser.for:198 */
/*<       do200i=2,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> rvala(feq_storage_rvala, 1);

    feq::IndexedPointer<real> rval(feq_storage_rval, 1);

    /* Function Body */
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE sortser.for:199 */
/*<       j=i >*/
	j = feq_gen_i_d_;
/* SOURCE sortser.for:200 */
/*<       t=rval(j) >*/
	t = rval[j];
/* SOURCE sortser.for:201 */
/*<       ta=rvala(j) >*/
	ta = rvala[j];
/* SOURCE sortser.for:202 */
/*<   100 continue >*/
L100:
/* SOURCE sortser.for:204 */
/*<       if(j.gt.1.and.rval(j-1).gt.t)then >*/
	if (j > 1 && rval[j - 1] > t) {
/* SOURCE sortser.for:205 */
/*<       rval(j)=rval(j-1) >*/
	    rval[j] = rval[j - 1];
/* SOURCE sortser.for:206 */
/*<       rvala(j)=rvala(j-1) >*/
	    rvala[j] = rvala[j - 1];
/* SOURCE sortser.for:208 */
/*<       j=j-1 >*/
	    --j;
/* SOURCE sortser.for:210 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE sortser.for:211 */
/*<       endif >*/
	}
/* SOURCE sortser.for:212 */
/*<       rval(j)=t >*/
	rval[j] = t;
/* SOURCE sortser.for:213 */
/*<       rvala(j)=ta >*/
	rvala[j] = ta;
/* SOURCE sortser.for:215 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE sortser.for:217 */
/*<       return >*/
    return 0;
/* SOURCE sortser.for:218 */
/*<       end >*/
} /* sort2r_ */

#ifdef __cplusplus
	}
#endif
