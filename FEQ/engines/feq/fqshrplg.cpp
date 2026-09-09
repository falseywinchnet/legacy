/* fqshrplg.f -- translated by f2c (version 20240504).
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

/*     Program units used in plane geometry computations. */



/* SOURCE fqshrplg.for:6 */
/*<       subroutinefind_line_coef(x1,y1,x2,y2,a,b,c) >*/
/* Subroutine */ int feq_gen_find_line_coef_d_(doublereal *x1, doublereal *y1, 
	doublereal *x2, doublereal *y2, doublereal *a, doublereal *b, 
	doublereal *feq_gen_c_d_)
{
/*     Find the coefficients for the straight line passing through */
/*     the points (X1,Y1) and (X2,Y2). In this context straight lines */
/*     are unlimited in extent. */
/* SOURCE fqshrplg.for:13 */
/*<       implicitnone >*/
/* SOURCE fqshrplg.for:15 */
/*<       real*8a,b,c,x1,y1,x2,y2 >*/
/* *********************************************************************** */
/* SOURCE fqshrplg.for:17 */
/*<       a=y2-y1 >*/
    *a = *y2 - *y1;
/* SOURCE fqshrplg.for:18 */
/*<       b=x1-x2 >*/
    *b = *x1 - *x2;
/* SOURCE fqshrplg.for:19 */
/*<       c=-x1*(y2-y1)+y1*(x2-x1) >*/
    *feq_gen_c_d_ = -(*x1) * (*y2 - *y1) + *y1 * (*x2 - *x1);
/*     To avoid zero divide messages, replace zero values for */
/*     A and B with small positive values.  Make sure that */
/*     the inverse of the square of the number is much less than */
/*     10**300 */
/* SOURCE fqshrplg.for:24 */
/*<       if(a.eq.0.d0)then >*/
    if (*a == 0.) {
/* SOURCE fqshrplg.for:25 */
/*<       a=1.d-20 >*/
	*a = 1e-20;
/* SOURCE fqshrplg.for:26 */
/*<       endif >*/
    }
/* SOURCE fqshrplg.for:27 */
/*<       if(b.eq.0.d0)then >*/
    if (*b == 0.) {
/* SOURCE fqshrplg.for:28 */
/*<       b=1.d-20 >*/
	*b = 1e-20;
/* SOURCE fqshrplg.for:29 */
/*<       endif >*/
    }
/* SOURCE fqshrplg.for:30 */
/*<       return >*/
    return 0;
/* SOURCE fqshrplg.for:31 */
/*<       end >*/
} /* find_line_coef__ */




/* SOURCE fqshrplg.for:36 */
/*<       subroutinefind_perpendicular(x1,y1,a,b,c,ap,bp,cp) >*/
/* Subroutine */ int feq_gen_find_perpendicular_d_(doublereal *x1, doublereal *y1, 
	doublereal *a, doublereal *b, doublereal *feq_gen_c_d_, doublereal *ap, 
	doublereal *bp, doublereal *cp)
{
/*     Find the coef. for the line perpendicular to the line with */
/*     coefficients A, B, C and passing through the point X1, Y1. */
/*     Note: X1, Y1 need not be on the line: (A, B, C).  In this */
/*     context straight lines are unlimited in extent. */
/* SOURCE fqshrplg.for:44 */
/*<       implicitnone >*/
/* SOURCE fqshrplg.for:45 */
/*<       real*8a,b,c,ap,bp,cp,x1,y1 >*/
/* *********************************************************************** */
/* SOURCE fqshrplg.for:47 */
/*<       ap=b >*/
    *ap = *b;
/* SOURCE fqshrplg.for:48 */
/*<       bp=-a >*/
    *bp = -(*a);
/* SOURCE fqshrplg.for:49 */
/*<       cp=-ap*x1-bp*y1 >*/
    *cp = -(*ap) * *x1 - *bp * *y1;
/*     Replace zero values of AP and BP with small positive values to */
/*     avoid zero divides */
/* SOURCE fqshrplg.for:52 */
/*<       if(ap.eq.0.d0)then >*/
    if (*ap == 0.) {
/* SOURCE fqshrplg.for:53 */
/*<       ap=1.d-20 >*/
	*ap = 1e-20;
/* SOURCE fqshrplg.for:54 */
/*<       endif >*/
    }
/* SOURCE fqshrplg.for:55 */
/*<       if(bp.eq.0.d0)then >*/
    if (*bp == 0.) {
/* SOURCE fqshrplg.for:56 */
/*<       bp=1.d-20 >*/
	*bp = 1e-20;
/* SOURCE fqshrplg.for:57 */
/*<       endif >*/
    }
/* SOURCE fqshrplg.for:58 */
/*<       return >*/
    return 0;
/* SOURCE fqshrplg.for:59 */
/*<       end >*/
} /* find_perpendicular__ */

#ifdef __cplusplus
	}
#endif
