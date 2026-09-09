/* locsubs.f -- translated by f2c (version 20240504).
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




/* SOURCE locsubs.for:4 */
/*<       subroutinetimerl(itick) >*/
/* Subroutine */ int timerl_(integer *itick)
{
    /* Initialized data */

    static integer first = 0;

    integer ihr, imn;
    static integer base;
    integer isec;
    char cdate[8], ctime[10];
    extern /* Subroutine */ int feq_gen_date_and_time_d_(char *, char *, char *, 
	    integer *, ftnlen, ftnlen, ftnlen);
    char czone[5];
    integer imilli, seconds, ivalues[8];


/*     + + + PURPOSE + + + */
/*     Determine the elapsed time in 100-th seconds since first call to this */
/*     routine. */

/* SOURCE locsubs.for:11 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE locsubs.for:13 */
/*<       integeritick >*/

/*     + + + ARGUMENT DEFINITIONS + + + */
/*     ITICK  - Number of seconds elapsed since first call. */

/*     + + + LOCAL VARIABLES + + + */
/* SOURCE locsubs.for:19 */
/*<       charactercdate*8,ctime*10,czone*5 >*/
/* SOURCE locsubs.for:20 */
/*<       integerivalues(8),ihr,imn,isec,seconds,imilli >*/

/*     DATE_AND_TIME IS A LAHEY FORTRAN 90 SYSTEM SUBROUTINE */

/*     + + + SAVE VARIABLES + + + */
/* SOURCE locsubs.for:25 */
/*<       integerfirst,base >*/
/* SOURCE locsubs.for:26 */
/*<       savefirst,base >*/

/*     + + + DATA INITIALIZATIONS + + + */

/*     + + + END SPECIFICATIONS + + + */

/* SOURCE locsubs.for:29 */
/*<       datafirst/0/ >*/
/* SOURCE locsubs.for:33 */
/*<       calldate_and_time(cdate,ctime,czone,ivalues) >*/
    feq_gen_date_and_time_d_(cdate, ctime, czone, ivalues, (ftnlen)8, (ftnlen)10, (
	    ftnlen)5);
/* SOURCE locsubs.for:34 */
/*<       ihr=ivalues(5) >*/
    ihr = ivalues[4];
/* SOURCE locsubs.for:35 */
/*<       imn=ivalues(6) >*/
    imn = ivalues[5];
/* SOURCE locsubs.for:36 */
/*<       isec=ivalues(7) >*/
    isec = ivalues[6];
/* SOURCE locsubs.for:37 */
/*<       imilli=ivalues(8) >*/
    imilli = ivalues[7];
/* SOURCE locsubs.for:39 */
/*<       seconds=(ihr*3600+imn*60+isec)*100+imilli/10 >*/
    seconds = (ihr * 3600 + imn * 60 + isec) * 100 + imilli / 10;
/*      secnds = (ihr*3600 + imn*60 + isec )*100 */
/* SOURCE locsubs.for:41 */
/*<       if(first.eq.0)then >*/
    if (first == 0) {
/* SOURCE locsubs.for:42 */
/*<       first=1 >*/
	first = 1;
/* SOURCE locsubs.for:43 */
/*<       base=seconds >*/
	base = seconds;
/* SOURCE locsubs.for:44 */
/*<       itick=0 >*/
	*itick = 0;
/* SOURCE locsubs.for:45 */
/*<       else >*/
    } else {
/* SOURCE locsubs.for:46 */
/*<       itick=seconds-base >*/
	*itick = seconds - base;
/* SOURCE locsubs.for:47 */
/*<       endif >*/
    }

/* SOURCE locsubs.for:49 */
/*<       return >*/
    return 0;
/* SOURCE locsubs.for:50 */
/*<       end >*/
} /* timerl_ */

#ifdef __cplusplus
	}
#endif
