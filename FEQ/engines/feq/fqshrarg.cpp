/* fqshrarg.f -- translated by f2c (version 20240504).
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

/* COMMON clcomc_ is declared in common.hpp. */

#define clcomc_1 clcomc_

/* COMMON clcom_ is declared in common.hpp. */

#define clcom_1 clcom_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;

/*     *********** */
/*     *         * */
/*     * GETARG  * */
/*     *         * */
/*     *********** */
/* SOURCE fqshrarg.for:8 */
/*<       subroutinegetarg(n,result) >*/
/* Subroutine */ int getarg_(integer *n, char *result, ftnlen result_len)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__2 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__3 = { 0, 6, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Get the argument number n from the list of command line */
/*     names found by IARGC. */
/* SOURCE fqshrarg.for:16 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrarg.for:18 */
/*<       integern >*/
/* SOURCE fqshrarg.for:19 */
/*<       characterresult*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - number of argument to get */
/*     RESULT - item found */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrarg.for:26 */
/*     COMMON BLOCK FOR COMMAND LINE PROCESSING FOR LAHEY COMPILER */
/* SOURCE clcom.cmn:3 */
/*<       common/clcomc/cl,namvec >*/
/* SOURCE clcom.cmn:4 */
/*<       character*127cl >*/
/* SOURCE clcom.cmn:5 */
/*<       character*64namvec(6) >*/
/* SOURCE clcom.cmn:7 */
/*<       common/clcom/iend,nxt,narg >*/
/* SOURCE clcom.cmn:8 */
/*<       integeriend,nxt,narg >*/
/* SOURCE clcom.cmn:10 */
/*<       save/clcom/ >*/
/* SOURCE clcom.cmn:11 */
/*<       save/clcomc/ >*/
/* *********************************************************************** */
/* SOURCE fqshrarg.for:28 */
/*<       if(narg.eq.0)then >*/
    if (clcom_1.narg == 0) {
/* SOURCE fqshrarg.for:29 */
/*<        >*/
	s_wsle(&feq_gen_io_d__1);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG. SEEKING COMMAND LINE ARGUMENT WHEN NONE"), 
		(ftnlen)45);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" HAVE BEEN FOUND."), (ftnlen)17);
	e_wsle();
/* SOURCE fqshrarg.for:32 */
/*<       elseif(n.gt.narg)then >*/
    } else if (*n > clcom_1.narg) {
/* SOURCE fqshrarg.for:33 */
/*<        >*/
	s_wsle(&feq_gen_io_d__2);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG. SEEKING COMMAND LINE ARGUMENT BEYOND END"),
		 (ftnlen)46);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" OF COMMAND LINE."), (ftnlen)17);
	e_wsle();
/* SOURCE fqshrarg.for:36 */
/*<       elseif(n.eq.1)then >*/
    } else if (*n == 1) {
/* SOURCE fqshrarg.for:37 */
/*<        >*/
	s_wsle(&feq_gen_io_d__3);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG. SEEKING COMMAND LINE ARGUMENT 1.  DOES N\
OT"), (ftnlen)48);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" EXIST!"), (ftnlen)7);
	e_wsle();
/* SOURCE fqshrarg.for:40 */
/*<       else >*/
    } else {
/* SOURCE fqshrarg.for:41 */
/*<       result=namvec(n) >*/
	s_copy(result, clcomc_1.namvec + (*n - 1 << 6), result_len, (ftnlen)
		64);
/* SOURCE fqshrarg.for:42 */
/*<       return >*/
	return 0;
/* SOURCE fqshrarg.for:43 */
/*<       endif >*/
    }
/* SOURCE fqshrarg.for:44 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrarg.for:45 */
/*<       end >*/
    return 0;
} /* getarg_ */

/*     *********** */
/*     *         * */
/*     * IARGC   * */
/*     *         * */
/*     *********** */
/* SOURCE fqshrarg.for:53 */
/*<       integerfunctioniargc() >*/
integer iargc_()
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer i_len(char *, ftnlen), s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int getcl_(char *, ftnlen), nxttok_(char *, 
	    integer *, char *, ftnlen, ftnlen);

/*     + + + PURPOSE + + + */
/* SOURCE fqshrarg.for:57 */
/*<       implicitnone >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrarg.for:59 */
/*     COMMON BLOCK FOR COMMAND LINE PROCESSING FOR LAHEY COMPILER */
/* SOURCE clcom.cmn:3 */
/*<       common/clcomc/cl,namvec >*/
/* SOURCE clcom.cmn:4 */
/*<       character*127cl >*/
/* SOURCE clcom.cmn:5 */
/*<       character*64namvec(6) >*/
/* SOURCE clcom.cmn:7 */
/*<       common/clcom/iend,nxt,narg >*/
/* SOURCE clcom.cmn:8 */
/*<       integeriend,nxt,narg >*/
/* SOURCE clcom.cmn:10 */
/*<       save/clcom/ >*/
/* SOURCE clcom.cmn:11 */
/*<       save/clcomc/ >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrarg.for:62 */
/*<       intrinsiclen >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrarg.for:65 */
/*<       externalnxttok >*/
/* *********************************************************************** */
/*     USE THE SVS NUMBERING SCHEME FOR COMMAND LINE ARGUMENTS. */
/*     THE COMMAND IS CONSIDERED TO BE ARGUMENT 1. THUS THE FIRST */
/*     ITEM OF INTEREST TO US IS THE SECOND ARGUMENT.  THE LAHEY */
/*     COMPILER DOES NOT PLACE THE COMMAND IN THE COMMAND LINE STRING */
/*     AND THUS WE CANNOT ACCESS THE STRING. MORG IN ARSIZE SHOULD BE */
/*     1. */
/* SOURCE fqshrarg.for:73 */
/*<       narg=1 >*/
    clcom_1.narg = 1;
/* SOURCE fqshrarg.for:75 */
/*<       nxt=1 >*/
    clcom_1.nxt = 1;
/*     GET THE COMMAND LINE STRING USING THE LAHEY COMPILER CALL. */
/* SOURCE fqshrarg.for:78 */
/*<       callgetcl(cl) >*/
    getcl_(clcomc_1.cl, (ftnlen)127);
/*      WRITE(*,50) CL */
/* 50    FORMAT(' CL=',A) */
/* SOURCE fqshrarg.for:81 */
/*<       iend=len(cl) >*/
    clcom_1.iend = i_len(clcomc_1.cl, (ftnlen)127);
/* SOURCE fqshrarg.for:83 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrarg.for:84 */
/*<       narg=narg+1 >*/
    ++clcom_1.narg;
/* SOURCE fqshrarg.for:85 */
/*<       callnxttok(cl,nxt,namvec(narg)) >*/
    nxttok_(clcomc_1.cl, &clcom_1.nxt, clcomc_1.namvec + (clcom_1.narg - 1 << 
	    6), (ftnlen)127, (ftnlen)64);
/* SOURCE fqshrarg.for:89 */
/*<       if(namvec(narg).ne.' ')then >*/
    if (s_cmp(clcomc_1.namvec + (clcom_1.narg - 1 << 6), const_cast<char*>(" "), (ftnlen)64, (
	    ftnlen)1) != 0) {
/*          WRITE(*,*) ' IARGC: NARG=',NARG,' NAMVEC(NARG)=', */
/*     A               NAMVEC(NARG) */
/* SOURCE fqshrarg.for:92 */
/*<       goto100 >*/
	goto L100;
/* SOURCE fqshrarg.for:93 */
/*<       endif >*/
    }
/* SOURCE fqshrarg.for:94 */
/*<       narg=narg-1 >*/
    --clcom_1.narg;
/*     WRITE(*,*) ' EXIT FROM IARGC: NARG=',NARG */
/* SOURCE fqshrarg.for:96 */
/*<       iargc=narg >*/
    ret_val = clcom_1.narg;
/* SOURCE fqshrarg.for:97 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrarg.for:98 */
/*<       end >*/
} /* iargc_ */

#ifdef __cplusplus
	}
#endif
