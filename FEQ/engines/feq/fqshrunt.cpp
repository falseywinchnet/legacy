/* fqshrunt.f -- translated by f2c (version 20240504).
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

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_1024 = 1024;
static integer feq_gen_c_d_3 = 3;

/*     *********** */
/*     *         * */
/*     * INITIALIZE_UNITS */
/*     *         * */
/*     *********** */
/* SOURCE fqshrunt.for:7 */
/*<       subroutineinitialize_units >*/
/* Subroutine */ int feq_gen_initialize_units_d_()
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__2 = { 0, 6, 0, 0, 0 };


/*     Set the unit number common block values to their default */
/*     values.  Unit numbers 5 and 6 are not used in any case */
/*     to avoid what seemed to be unavoidable confusion on some */
/*     Unix systems where these units were tied to console input */
/*     and console output and that connection could not be */
/*     changed. */
/* SOURCE fqshrunt.for:16 */
/*<       implicitnone >*/
/* INCLUDE fqshrunt.for:17 */
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
/* SOURCE fqshrunt.for:21 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE fqshrunt.for:23 */
/*<       if(dim_unit.gt.1024)then >*/
    if (FALSE_) {
/* SOURCE fqshrunt.for:24 */
/*<       write(*,*)' Invalid value for maximum I/O unit',dim_unit >*/
	s_wsle(&feq_gen_io_d__1);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Invalid value for maximum I/O unit"), (ftnlen)
		35);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_c_d_1024, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE fqshrunt.for:25 */
/*<       write(*,*)' Must be 1024 or less' >*/
	s_wsle(&feq_gen_io_d__2);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Must be 1024 or less"), (ftnlen)21);
	e_wsle();
/* SOURCE fqshrunt.for:26 */
/*<       stop'Abnormal stop: bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: bug found."), (ftnlen)25);
/* SOURCE fqshrunt.for:27 */
/*<       endif >*/
    }
/* SOURCE fqshrunt.for:28 */
/*<       do100i=1,dim_unit >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 1024; ++feq_gen_i_d_) {
/* SOURCE fqshrunt.for:29 */
/*<       unit_status(i)=0 >*/
	feq_gen_unit_com_d_1.feq_gen_unit_status_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE fqshrunt.for:30 */
/*<   100 continue >*/
/* L100: */
    }
/*     Mark units 1, 2, 3, 4, 5, 6, 7 as unavailable */
/* SOURCE fqshrunt.for:32 */
/*<       do110i=1,7 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 7; ++feq_gen_i_d_) {
/* SOURCE fqshrunt.for:33 */
/*<       unit_status(i)=-1 >*/
	feq_gen_unit_com_d_1.feq_gen_unit_status_d_[feq_gen_i_d_ - 1] = -1;
/* SOURCE fqshrunt.for:34 */
/*<   110 continue >*/
/* L110: */
    }
/*     Set the value of the current unit count.  DOES not include */
/*     the never used units. */
/* SOURCE fqshrunt.for:38 */
/*<       unit_knt=0 >*/
    feq_gen_unit_com_d_1.feq_gen_unit_knt_d_ = 0;
/* SOURCE fqshrunt.for:39 */
/*<       return >*/
    return 0;
/* SOURCE fqshrunt.for:40 */
/*<       end >*/
} /* initialize_units__ */

/*     *********** */
/*     *         * */
/*     * GET_UNIT */
/*     *         * */
/*     *********** */
/* SOURCE fqshrunt.for:48 */
/*<       integerfunctionget_unit(stdout) >*/
integer feq_gen_get_unit_d_(integer *stdout)
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
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_50, 0 };


/*     Get a unit number for Fortran I/O. */
/* SOURCE fqshrunt.for:52 */
/*<       implicitnone >*/
/* SOURCE fqshrunt.for:53 */
/*<       integerstdout >*/
/* INCLUDE fqshrunt.for:55 */
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
/* SOURCE fqshrunt.for:59 */
/*<       integeri >*/
/*     *********************************FORMATS************************** */
/* SOURCE fqshrunt.for:61 */
/*<    50 format(/,' *ERR:319* I/O unit numbers exhausted.') >*/
/* *********************************************************************** */
/* SOURCE fqshrunt.for:63 */
/*<       do100i=8,dim_unit >*/
/* L50: */
    for (feq_gen_i_d_ = 8; feq_gen_i_d_ <= 1024; ++feq_gen_i_d_) {
/* Start unit number at 8 to avoid conflicts with possibly reserved */
/* system units, such as standard input, output and error unit numbers. */
/* SOURCE fqshrunt.for:66 */
/*<       if(unit_status(i).eq.0)then >*/
	if (feq_gen_unit_com_d_1.feq_gen_unit_status_d_[feq_gen_i_d_ - 1] == 0) {
/*         Found one! */
/* SOURCE fqshrunt.for:68 */
/*<       get_unit=i >*/
	    ret_val = feq_gen_i_d_;
/* SOURCE fqshrunt.for:69 */
/*<       unit_knt=unit_knt+1 >*/
	    ++feq_gen_unit_com_d_1.feq_gen_unit_knt_d_;
/*         Mark unit as in use for Fortran I/O */
/* SOURCE fqshrunt.for:71 */
/*<       unit_status(i)=fortran_io >*/
	    feq_gen_unit_com_d_1.feq_gen_unit_status_d_[feq_gen_i_d_ - 1] = 1;
/* SOURCE fqshrunt.for:72 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE fqshrunt.for:73 */
/*<       endif >*/
	}
/* SOURCE fqshrunt.for:74 */
/*<   100 continue >*/
/* L100: */
    }
/*     If we get here then there are no unit numbers left.  This is */
/*     a fatal error. */
/* SOURCE fqshrunt.for:77 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__5.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__5);
    e_wsfe();
/* SOURCE fqshrunt.for:78 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrunt.for:80 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrunt.for:81 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrunt.for:82 */
/*<       end >*/
} /* get_unit__ */

/*     *********** */
/*     *         * */
/*     * FREE_UNIT */
/*     *         * */
/*     *********** */
/* SOURCE fqshrunt.for:90 */
/*<       subroutinefree_unit(stdout,unit) >*/
/* Subroutine */ int feq_gen_free_unit_d_(integer *stdout, integer *unit)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* Unit=\002,i5,\002 out of range\
 in FREE_UNIT.\002)";
    static char fmt_52[] = "(/,\002 *BUG:XXX* Unit=\002,i5,\002 was not in u\
se in FREE_UNIT.\002)";
    static char fmt_54[] = "(/,\002 *BUG:XXX* Unit=\002,i5,\002 was not assi\
gned to Fortran \002,\002I/O in FREE_UNIT.\002)";

    /* System generated locals */
    cllist feq_gen_cl_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_54, 0 };


/*     Free a Fortran I/O unit number.  This also implies closing the */
/*     associated file, if any. */
/* SOURCE fqshrunt.for:95 */
/*<       implicitnone >*/
/* SOURCE fqshrunt.for:96 */
/*<       integerstdout,unit >*/
/* INCLUDE fqshrunt.for:98 */
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
/* SOURCE fqshrunt.for:101 */
/*<    50 format(/,' *BUG:XXX* Unit=',i5,' out of range in FREE_UNIT.') >*/
/* SOURCE fqshrunt.for:102 */
/*<    52 format(/,' *BUG:XXX* Unit=',i5,' was not in use in FREE_UNIT.') >*/
/* SOURCE fqshrunt.for:103 */
/*<    54  >*/
/* ************************************************************************ */
/* SOURCE fqshrunt.for:106 */
/*<       if(unit.lt.1.or.unit.gt.dim_unit)then >*/
/* L50: */
/* L52: */
/* L54: */
    if (*unit < 1 || *unit > 1024) {
/* SOURCE fqshrunt.for:107 */
/*<       write(stdout,50)unit >*/
	feq_gen_io_d__6.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__6);
	do_fio(&feq_gen_c_d_1, (char *)&(*unit), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrunt.for:108 */
/*<       elseif(unit_status(unit).lt.1)then >*/
    } else if (feq_gen_unit_com_d_1.feq_gen_unit_status_d_[*unit - 1] < 1) {
/* SOURCE fqshrunt.for:109 */
/*<       write(stdout,52)unit >*/
	feq_gen_io_d__7.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__7);
	do_fio(&feq_gen_c_d_1, (char *)&(*unit), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrunt.for:110 */
/*<       else >*/
    } else {
/*       UNIT appears to be valid.  Close the file if it is for */
/*       Fortran I/O. */
/* SOURCE fqshrunt.for:113 */
/*<       if(unit_status(unit).eq.fortran_io)then >*/
	if (feq_gen_unit_com_d_1.feq_gen_unit_status_d_[*unit - 1] == 1) {
/* SOURCE fqshrunt.for:115 */
/*<       close(unit) >*/
	    feq_gen_cl_d_1.cerr = 0;
	    feq_gen_cl_d_1.cunit = *unit;
	    feq_gen_cl_d_1.csta = 0;
	    f_clos(&feq_gen_cl_d_1);
/*         Free for use later. */
/* SOURCE fqshrunt.for:118 */
/*<       unit_status(unit)=0 >*/
	    feq_gen_unit_com_d_1.feq_gen_unit_status_d_[*unit - 1] = 0;
/* SOURCE fqshrunt.for:119 */
/*<       unit_knt=unit_knt-1 >*/
	    --feq_gen_unit_com_d_1.feq_gen_unit_knt_d_;
/* SOURCE fqshrunt.for:120 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrunt.for:121 */
/*<       else >*/
	} else {
/* SOURCE fqshrunt.for:122 */
/*<       write(stdout,54)unit >*/
	    feq_gen_io_d__8.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__8);
	    do_fio(&feq_gen_c_d_1, (char *)&(*unit), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE fqshrunt.for:123 */
/*<       endif >*/
	}
/* SOURCE fqshrunt.for:124 */
/*<       endif >*/
    }
/* SOURCE fqshrunt.for:125 */
/*<       stop'Abnormal stop.  Bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE fqshrunt.for:126 */
/*<       end >*/
    return 0;
} /* free_unit__ */

#ifdef __cplusplus
	}
#endif
