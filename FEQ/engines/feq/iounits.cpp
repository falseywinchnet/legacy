/* iounits.f -- translated by f2c (version 20240504).
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

/* COMMON unit_com__ is declared in common.hpp. */

#define feq_gen_unit_com_d_1 feq_gen_unit_com_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;

/*     Other i/o unit handling routines are in directory SHARE */
/*     *********** */
/*     *         * */
/*     * GET_HECDSS_UNIT */
/*     *         * */
/*     *********** */
/* SOURCE iounits.for:8 */
/*<       integerfunctionget_hecdss_unit(stdout) >*/
integer feq_gen_get_hecdss_unit_d_(integer *stdout)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:319* I/O unit numbers exhausted.\
\002)";

    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__2 = { 0, 0, 0, fmt_50, 0 };


/*     Get a unit number for HECDSS I/O. */
/* SOURCE iounits.for:12 */
/*<       integerstdout >*/
/* INCLUDE iounits.for:14 */
/*     Data structure for tracking which Fortran I/O units are */
/*     in use, which should never be used, and which are */
/*     available. */
/* SOURCE forunit.cmn:5 */
/*<       integermax_unit,dim_unit,fortran_io,hecdss_io >*/
/* SOURCE forunit.cmn:6 */
/*<        >*/
/* SOURCE forunit.cmn:9 */
/*<       integerunit_status(dim_unit),unit_knt >*/
/* SOURCE forunit.cmn:11 */
/*<       common/unit_com/unit_knt,unit_status >*/
/* SOURCE forunit.cmn:13 */
/*<       save/unit_com/ >*/
/*     Note: There appears to be a limit in the software at */
/*     some point that requires keeping DIM_UNIT at 1024 or */
/*     less.  August 9, 2002.  Should be large enough for */
/*     most models! */
/*     Local */
/* SOURCE iounits.for:18 */
/*<       integeri >*/
/*     *********************************FORMATS************************** */
/* SOURCE iounits.for:20 */
/*<    50 format(/,' *ERR:319* I/O unit numbers exhausted.') >*/
/* *********************************************************************** */
/* SOURCE iounits.for:22 */
/*<       do100i=1,dim_unit >*/
/* L50: */
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 1024; ++feq_gen_i_d_) {
/* SOURCE iounits.for:23 */
/*<       if(unit_status(i).eq.0)then >*/
	if (feq_gen_unit_com_d_1.feq_gen_unit_status_d_[feq_gen_i_d_ - 1] == 0) {
/*         Found one! */
/* SOURCE iounits.for:25 */
/*<       get_hecdss_unit=i >*/
	    ret_val = feq_gen_i_d_;
/* SOURCE iounits.for:26 */
/*<       unit_knt=unit_knt+1 >*/
	    ++feq_gen_unit_com_d_1.feq_gen_unit_knt_d_;
/*         Mark unit as in use for HECDSS I/O */
/* SOURCE iounits.for:28 */
/*<       unit_status(i)=hecdss_io >*/
	    feq_gen_unit_com_d_1.feq_gen_unit_status_d_[feq_gen_i_d_ - 1] = 2;
/* SOURCE iounits.for:29 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE iounits.for:30 */
/*<       endif >*/
	}
/* SOURCE iounits.for:31 */
/*<   100 continue >*/
/* L100: */
    }
/*     If we get here then there are no unit numbers left.  This is */
/*     a fatal error. */
/* SOURCE iounits.for:34 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__2.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__2);
    e_wsfe();
/* SOURCE iounits.for:35 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE iounits.for:37 */
/*<   110 continue >*/
L110:
/* SOURCE iounits.for:38 */
/*<       return >*/
    return ret_val;
/* SOURCE iounits.for:39 */
/*<       end >*/
} /* get_hecdss_unit__ */

/*     *********** */
/*     *         * */
/*     * RELEASE_HECDSS_UNIT */
/*     *         * */
/*     *********** */
/* SOURCE iounits.for:47 */
/*<       subroutinerelease_hecdss_unit(stdout,unit) >*/
/* Subroutine */ int feq_gen_release_hecdss_unit_d_(integer *stdout, integer *unit)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* Unit=\002,i5,\002 out of range\
 in\002,\002 RELEASE_HECDSS_UNIT.\002)";
    static char fmt_52[] = "(/,\002 *BUG:XXX* Unit=\002,i5,\002 was not in u\
se in\002,\002 RELEASE_HECDSS_UNIT.\002)";
    static char fmt_54[] = "(/,\002 *BUG:XXX* Unit=\002,i5,\002 was not assi\
gned to HECDSS in\002,\002 RELEASE_HECDSS_UNIT.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__3 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__4 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_54, 0 };


/*     Free a HECDSS file I/O unit number.  The file is closed elsewhere. */
/* SOURCE iounits.for:51 */
/*<       implicitnone >*/
/* SOURCE iounits.for:52 */
/*<       integerstdout,unit >*/
/* INCLUDE iounits.for:54 */
/*     Data structure for tracking which Fortran I/O units are */
/*     in use, which should never be used, and which are */
/*     available. */
/* SOURCE forunit.cmn:5 */
/*<       integermax_unit,dim_unit,fortran_io,hecdss_io >*/
/* SOURCE forunit.cmn:6 */
/*<        >*/
/* SOURCE forunit.cmn:9 */
/*<       integerunit_status(dim_unit),unit_knt >*/
/* SOURCE forunit.cmn:11 */
/*<       common/unit_com/unit_knt,unit_status >*/
/* SOURCE forunit.cmn:13 */
/*<       save/unit_com/ >*/
/*     Note: There appears to be a limit in the software at */
/*     some point that requires keeping DIM_UNIT at 1024 or */
/*     less.  August 9, 2002.  Should be large enough for */
/*     most models! */
/*     *****************************Formats****************************** */
/* SOURCE iounits.for:57 */
/*<    50  >*/
/* SOURCE iounits.for:59 */
/*<    52  >*/
/* SOURCE iounits.for:61 */
/*<    54  >*/
/* *********************************************************************** */
/* SOURCE iounits.for:64 */
/*<       if(unit.le.0.or.unit.gt.dim_unit)then >*/
/* L50: */
/* L52: */
/* L54: */
    if (*unit <= 0 || *unit > 1024) {
/* SOURCE iounits.for:65 */
/*<       write(stdout,50)unit >*/
	feq_gen_io_d__3.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__3);
	do_fio(&feq_gen_c_d_1, (char *)&(*unit), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE iounits.for:66 */
/*<       elseif(unit_status(unit).le.0)then >*/
    } else if (feq_gen_unit_com_d_1.feq_gen_unit_status_d_[*unit - 1] <= 0) {
/* SOURCE iounits.for:67 */
/*<       write(stdout,52)unit >*/
	feq_gen_io_d__4.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__4);
	do_fio(&feq_gen_c_d_1, (char *)&(*unit), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE iounits.for:68 */
/*<       else >*/
    } else {
/* SOURCE iounits.for:69 */
/*<       if(unit_status(unit).eq.hecdss_io)then >*/
	if (feq_gen_unit_com_d_1.feq_gen_unit_status_d_[*unit - 1] == 2) {
/*         Free for use later. */
/* SOURCE iounits.for:71 */
/*<       unit_status(unit)=0 >*/
	    feq_gen_unit_com_d_1.feq_gen_unit_status_d_[*unit - 1] = 0;
/* SOURCE iounits.for:72 */
/*<       return >*/
	    return 0;
/* SOURCE iounits.for:73 */
/*<       else >*/
	} else {
/* SOURCE iounits.for:74 */
/*<       write(stdout,54)unit >*/
	    feq_gen_io_d__5.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__5);
	    do_fio(&feq_gen_c_d_1, (char *)&(*unit), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE iounits.for:75 */
/*<       endif >*/
	}
/* SOURCE iounits.for:76 */
/*<       endif >*/
    }
/* SOURCE iounits.for:77 */
/*<       stop'Abnormal stop: bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: bug found."), (ftnlen)25);
/* SOURCE iounits.for:78 */
/*<       end >*/
    return 0;
} /* release_hecdss_unit__ */

#ifdef __cplusplus
	}
#endif
