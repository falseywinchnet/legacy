/* mkdir_fun.f -- translated by f2c (version 20240504).
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

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;




/* SOURCE mkdir_fun.for:4 */
/*<       subroutinemkdir(stdout,dirname) >*/
/* Subroutine */ int mkdir_(integer *stdout, char *dirname, ftnlen 
	dirname_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Using existing directory: \002,a)";
    static char fmt_52[] = "(/,\002 Creating directory: \002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;

    /* Builtin functions */
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(), s_wsfe(cilist *), e_wsfe(), f_clos(cllist *);

    /* Local variables */
    extern integer feq_gen_get_unit_d_(integer *);
    integer feq_gen_i_d_, it;
    extern /* Subroutine */ int feq_gen_feq_system3_d_(char *, char *, char *, ftnlen, 
	    ftnlen, ftnlen);
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    char dummy[5];
    integer stdun;
    extern /* Subroutine */ int system_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_50, 0 };


/*     The system subroutine as implemented in lf95 */
/*     for msw, gives not return code.  Therefore, we cannot check */
/*     if a directory already exists.  However, we can create */
/*     the directory, as if it does not exist, and if it does, */
/*     we send the error message to the NUL device.  If it */
/*     does not exist, it is created. */

/* SOURCE mkdir_fun.for:13 */
/*<       implicitnone >*/
/* SOURCE mkdir_fun.for:15 */
/*<       integerstdout >*/
/* SOURCE mkdir_fun.for:17 */
/*<       character*(*)dirname >*/
/* SOURCE mkdir_fun.for:19 */
/*<       integerget_unit >*/
/* SOURCE mkdir_fun.for:20 */
/*<       externalget_unit >*/
/*     Local */
/* SOURCE mkdir_fun.for:24 */
/*<       integerit,stdun,i >*/
/* SOURCE mkdir_fun.for:26 */
/*<       characterdummy*5 >*/
/*     **********************Formats************************************* */
/* SOURCE mkdir_fun.for:4 */
/*<       integer feq_len_trim >*/
/* SOURCE mkdir_fun.for:4 */
/*<       external feq_len_trim >*/
/* SOURCE mkdir_fun.for:28 */
/*<    50 format(/,' Using existing directory: ',a) >*/
/* SOURCE mkdir_fun.for:29 */
/*<    52 format(/,' Creating directory: ',a) >*/
/* *********************************************************************** */
/* SOURCE mkdir_fun.for:31 */
/*<       it=feq_len_trim(dirname) >*/
/* L50: */
/* L52: */
    it = feq_gen_feq_len_trim_d_(dirname, dirname_len);
/* SOURCE mkdir_fun.for:32 */
/*<       callfeq_system3('mkdir ',dirname(1:it),' > temp.zxcv_ 2>&1') >*/
    feq_gen_feq_system3_d_(const_cast<char*>("mkdir "), dirname, const_cast<char*>(" > temp.zxcv_ 2>&1"), (ftnlen)6, it, (
	    ftnlen)18);
/* SOURCE mkdir_fun.for:33 */
/*<       stdun=get_unit(stdout) >*/
    stdun = feq_gen_get_unit_d_(stdout);
/* SOURCE mkdir_fun.for:34 */
/*<       open(unit=stdun,file='temp.zxcv_',status='old') >*/
    feq_gen_o_d_1.oerr = 0;
    feq_gen_o_d_1.ounit = stdun;
    feq_gen_o_d_1.ofnmlen = 10;
    feq_gen_o_d_1.ofnm = const_cast<char*>("temp.zxcv_");
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("old");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    f_open(&feq_gen_o_d_1);
/* SOURCE mkdir_fun.for:35 */
/*<       i=0 >*/
    feq_gen_i_d_ = 0;
/* SOURCE mkdir_fun.for:36 */
/*<       dowhile(.true.) >*/
    while(TRUE_) {
/* SOURCE mkdir_fun.for:37 */
/*<       read(stdun,'(a)',end=100)dummy >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciend = 1;
	feq_gen_ci_d_1.ciunit = stdun;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
	feq_gen_i_d_1 = s_rsfe(&feq_gen_ci_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L100;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, dummy, (ftnlen)5);
	if (feq_gen_i_d_1 != 0) {
	    goto L100;
	}
	feq_gen_i_d_1 = e_rsfe();
	if (feq_gen_i_d_1 != 0) {
	    goto L100;
	}
/* SOURCE mkdir_fun.for:38 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE mkdir_fun.for:40 */
/*<       enddo >*/
    }
/* SOURCE mkdir_fun.for:41 */
/*<   100 continue >*/
L100:
/*     These statements may not be reliable.  By default, msw */
/*     creates all parts of the path that do not exist.  Turning */
/*     that off is a system-level action.  Thus if part of the path */
/*     does not exist, it will be created. */
/* SOURCE mkdir_fun.for:47 */
/*<       if(i==0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE mkdir_fun.for:48 */
/*<       write(stdout,52)dirname >*/
	feq_gen_io_d__5.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__5);
	do_fio(&feq_gen_c_d_1, dirname, dirname_len);
	e_wsfe();
/* SOURCE mkdir_fun.for:49 */
/*<       else >*/
    } else {
/* SOURCE mkdir_fun.for:50 */
/*<       write(stdout,50)dirname >*/
	feq_gen_io_d__6.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__6);
	do_fio(&feq_gen_c_d_1, dirname, dirname_len);
	e_wsfe();
/* SOURCE mkdir_fun.for:51 */
/*<       endif >*/
    }
/* SOURCE mkdir_fun.for:53 */
/*<       close(stdun) >*/
    feq_gen_cl_d_1.cerr = 0;
    feq_gen_cl_d_1.cunit = stdun;
    feq_gen_cl_d_1.csta = 0;
    f_clos(&feq_gen_cl_d_1);
/* SOURCE mkdir_fun.for:54 */
/*<       callsystem('del \q temp.zxcv_ > NUL 2>&1') >*/
    system_(const_cast<char*>("del \\q temp.zxcv_ > NUL 2>&1"), (ftnlen)28);
/* SOURCE mkdir_fun.for:55 */
/*<       return >*/
    return 0;
/* SOURCE mkdir_fun.for:56 */
/*<       end >*/
} /* mkdir_ */

#ifdef __cplusplus
	}
#endif
