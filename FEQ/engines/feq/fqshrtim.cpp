/* fqshrtim.f -- translated by f2c (version 20240504).
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




/* SOURCE fqshrtim.for:4 */
/*<       subroutineinvmjd(mjd,yr,mn,dy) >*/
/* Subroutine */ int invmjd_(integer *mjd, integer *yr, integer *mn, integer *
	dy)
{
    integer a, b, feq_gen_c_d_, feq_gen_d_d_, e, feq_gen_z_d_, alpha;

/*     + + + PURPOSE + + + */
/*     Invert the modified julian date as computed by function MJD */
/* SOURCE fqshrtim.for:11 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrtim.for:13 */
/*<       integerdy,mjd,mn,yr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     MJD    - value of modified julian data number to invert */
/*     YR     - calendar year */
/*     MN     - number of month(1-12) */
/*     DY     - day in the month */
/*     Developed from information given in: "Astronomical Formulae */
/*     for Calculators', Jean Meeus, published by Willmann-Bell. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrtim.for:25 */
/*<       integera,alpha,b,c,d,e,z >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrtim.for:28 */
/*<       intrinsicdble,int >*/
/* *********************************************************************** */
/*     CONVERT TO JULIAN TIME PLUS THE .5 DAY CORRECTION. YIELDS AN */
/*     INTEGER */
/* SOURCE fqshrtim.for:33 */
/*<       z=mjd+679006+1720994+1 >*/
    feq_gen_z_d_ = *mjd + 2400001;
/* SOURCE fqshrtim.for:35 */
/*<       if(z.lt.2299161)then >*/
    if (feq_gen_z_d_ < 2299161) {
/* SOURCE fqshrtim.for:36 */
/*<       a=z >*/
	a = feq_gen_z_d_;
/* SOURCE fqshrtim.for:37 */
/*<       else >*/
    } else {
/* SOURCE fqshrtim.for:38 */
/*<       alpha=int((dble(z)-1867216.24d0)/36524.25d0) >*/
	alpha = (integer) (((doublereal) feq_gen_z_d_ - 1867216.24) / 36524.25);
/* SOURCE fqshrtim.for:39 */
/*<       a=z+1+alpha-alpha/4 >*/
	a = feq_gen_z_d_ + 1 + alpha - alpha / 4;
/* SOURCE fqshrtim.for:40 */
/*<       endif >*/
    }
/* SOURCE fqshrtim.for:42 */
/*<       b=a+1524 >*/
    b = a + 1524;
/* SOURCE fqshrtim.for:43 */
/*<       c=int((dble(b)-122.1d0)/365.25d0) >*/
    feq_gen_c_d_ = (integer) (((doublereal) b - 122.1) / 365.25);
/* SOURCE fqshrtim.for:44 */
/*<       d=int(365.25d0*dble(c)) >*/
    feq_gen_d_d_ = (integer) ((doublereal) feq_gen_c_d_ * 365.25);
/* SOURCE fqshrtim.for:45 */
/*<       e=int(dble(b-d)/30.6001d0) >*/
    e = (integer) ((doublereal) (b - feq_gen_d_d_) / 30.6001);
/* SOURCE fqshrtim.for:47 */
/*<       dy=b-d-int(30.6001d0*dble(e)) >*/
    *dy = b - feq_gen_d_d_ - (integer) ((doublereal) e * 30.6001);
/* SOURCE fqshrtim.for:48 */
/*<       if(e.le.13)then >*/
    if (e <= 13) {
/* SOURCE fqshrtim.for:49 */
/*<       mn=e-1 >*/
	*mn = e - 1;
/* SOURCE fqshrtim.for:50 */
/*<       else >*/
    } else {
/* SOURCE fqshrtim.for:51 */
/*<       mn=e-13 >*/
	*mn = e - 13;
/* SOURCE fqshrtim.for:52 */
/*<       endif >*/
    }
/* SOURCE fqshrtim.for:53 */
/*<       if(mn.ge.3)then >*/
    if (*mn >= 3) {
/* SOURCE fqshrtim.for:54 */
/*<       yr=c-4716 >*/
	*yr = feq_gen_c_d_ - 4716;
/* SOURCE fqshrtim.for:55 */
/*<       else >*/
    } else {
/* SOURCE fqshrtim.for:56 */
/*<       yr=c-4715 >*/
	*yr = feq_gen_c_d_ - 4715;
/* SOURCE fqshrtim.for:57 */
/*<       endif >*/
    }
/* SOURCE fqshrtim.for:59 */
/*<       return >*/
    return 0;
/* SOURCE fqshrtim.for:60 */
/*<       end >*/
} /* invmjd_ */




/* SOURCE fqshrtim.for:64 */
/*<       integerfunctionlpyear(yr) >*/
integer lpyear_(integer *yr)
{
    /* System generated locals */
    integer ret_val;

/*     + + + PURPOSE + + + */
/*     Compute code for leap year for the Gregorian calender for */
/*     all possible cases. */
/* SOURCE fqshrtim.for:71 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrtim.for:73 */
/*<       integeryr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     YR     - calendar year */
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrtim.for:79 */
/*<       intrinsicmod >*/
/* *********************************************************************** */
/* SOURCE fqshrtim.for:81 */
/*<       if(mod(yr,4).eq.0)then >*/
    if (*yr % 4 == 0) {
/*       This could be a leap year. */
/* SOURCE fqshrtim.for:83 */
/*<       if(mod(yr,100).eq.0)then >*/
	if (*yr % 100 == 0) {
/*         It is a century year. */
/* SOURCE fqshrtim.for:85 */
/*<       if(mod(yr,400).eq.0)then >*/
	    if (*yr % 400 == 0) {
/*           It is a century year divisible by 4 and by 400.  Therefore */
/*           it is a leap year. */
/* SOURCE fqshrtim.for:88 */
/*<       lpyear=2 >*/
		ret_val = 2;
/* SOURCE fqshrtim.for:89 */
/*<       else >*/
	    } else {
/*           Not divisible by 400.  Therefore it is not a leap year. */
/* SOURCE fqshrtim.for:91 */
/*<       lpyear=1 >*/
		ret_val = 1;
/* SOURCE fqshrtim.for:92 */
/*<       endif >*/
	    }
/* SOURCE fqshrtim.for:93 */
/*<       else >*/
	} else {
/*         Not a century year and divisible by 4-leap year. */
/* SOURCE fqshrtim.for:95 */
/*<       lpyear=2 >*/
	    ret_val = 2;
/* SOURCE fqshrtim.for:96 */
/*<       endif >*/
	}
/* SOURCE fqshrtim.for:97 */
/*<       else >*/
    } else {
/*       Not divisible by 4- not a leap year */
/* SOURCE fqshrtim.for:99 */
/*<       lpyear=1 >*/
	ret_val = 1;
/* SOURCE fqshrtim.for:100 */
/*<       endif >*/
    }
/* SOURCE fqshrtim.for:101 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrtim.for:102 */
/*<       end >*/
} /* lpyear_ */




/* SOURCE fqshrtim.for:106 */
/*<       integerfunctionmjd(yr,mn,dy) >*/
integer mjd_(integer *yr, integer *mn, integer *dy)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    integer a, b, m, y;

/*     + + + PURPOSE + + + */
/*     Compute modified julian date for any date with a year greater */
/*     than 1582.  We take the resulting date to represent the */
/*     elapsed time from some point in the past to the first instant */
/*     of the given day. */
/*     The date must be later than Nov. 17, 1858 for MJD to be */
/*     a positive number.  Thus for use in FEQ the year must be */
/*     1859 or greater. */
/*     This routine and INVMJD have been checked for every day */
/*     from 1860 through the year 25000.  Using Lahey compilers! */
/*     Others may fail! */
/*     Developed from information given in: "Astronomical Formulae */
/*     for Calculators', Jean Meeus, published by Willmann-Bell. */
/* SOURCE fqshrtim.for:125 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrtim.for:127 */
/*<       integerdy,mn,yr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     YR     - calendar year */
/*     MN     - number of month(1-12) */
/*     DY     - day in the month */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrtim.for:135 */
/*<       integera,b,m,y >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrtim.for:138 */
/*<       intrinsicint >*/
/* *********************************************************************** */
/* SOURCE fqshrtim.for:140 */
/*<       if(mn.gt.2)then >*/
    if (*mn > 2) {
/* SOURCE fqshrtim.for:141 */
/*<       y=yr >*/
	y = *yr;
/* SOURCE fqshrtim.for:142 */
/*<       m=mn >*/
	m = *mn;
/* SOURCE fqshrtim.for:143 */
/*<       else >*/
    } else {
/* SOURCE fqshrtim.for:144 */
/*<       y=yr-1 >*/
	y = *yr - 1;
/* SOURCE fqshrtim.for:145 */
/*<       m=mn+12 >*/
	m = *mn + 12;
/* SOURCE fqshrtim.for:146 */
/*<       endif >*/
    }
/* SOURCE fqshrtim.for:148 */
/*<       a=y/100 >*/
    a = y / 100;
/* SOURCE fqshrtim.for:149 */
/*<       b=2-a+a/4 >*/
    b = 2 - a + a / 4;
/* SOURCE fqshrtim.for:151 */
/*<       mjd=(36525*y)/100+int(30.6001*(m+1))+dy+b-679006 >*/
    ret_val = y * 36525 / 100 + (integer) (static_cast<double>((m + 1)) * (float)30.6001) + *dy + 
	    b - 679006;
/* SOURCE fqshrtim.for:152 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrtim.for:153 */
/*<       end >*/
} /* mjd_ */

#ifdef __cplusplus
	}
#endif
