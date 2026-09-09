/* pwd.f -- translated by f2c (version 20240504).
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

static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_1 = 1;




/* SOURCE pwd.for:4 */
/*<       subroutinepwd(cwd_path) >*/
/* Subroutine */ int pwd_(char *feq_gen_cwd_path_d_, ftnlen cwd_path_len)
{
    /* System generated locals */
    cilist feq_gen_ci_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;

    /* Builtin functions */
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(), f_clos(cllist *);

    /* Local variables */
    extern integer feq_gen_get_unit_d_(integer *);
    integer stddum;
    extern /* Subroutine */ int system_(char *, ftnlen);

/*     Find the path to the current working directory. */
/*     For lf95 under MSW. */
/* SOURCE pwd.for:10 */
/*<       implicitnone >*/
/* SOURCE pwd.for:11 */
/*<       character*(*)cwd_path >*/
/* SOURCE pwd.for:13 */
/*<       integerget_unit >*/
/* SOURCE pwd.for:14 */
/*<       externalget_unit,free_unit >*/
/*     Local */
/* SOURCE pwd.for:18 */
/*<       integerstddum,it >*/
/* *********************************************************************** */
/* SOURCE pwd.for:20 */
/*<       callsystem('cd > pwd.pwd') >*/
    system_(const_cast<char*>("cd > pwd.pwd"), (ftnlen)12);
/* SOURCE pwd.for:21 */
/*<       stddum=get_unit(0) >*/
    stddum = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE pwd.for:22 */
/*<       open(unit=stddum,file='pwd.pwd',status='old') >*/
    feq_gen_o_d_1.oerr = 0;
    feq_gen_o_d_1.ounit = stddum;
    feq_gen_o_d_1.ofnmlen = 7;
    feq_gen_o_d_1.ofnm = const_cast<char*>("pwd.pwd");
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("old");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    f_open(&feq_gen_o_d_1);
/* SOURCE pwd.for:23 */
/*<       read(stddum,'(a)')cwd_path >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciend = 0;
    feq_gen_ci_d_1.ciunit = stddum;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
    s_rsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_cwd_path_d_, cwd_path_len);
    e_rsfe();
/* SOURCE pwd.for:24 */
/*<       close(unit=stddum,status='delete') >*/
    feq_gen_cl_d_1.cerr = 0;
    feq_gen_cl_d_1.cunit = stddum;
    feq_gen_cl_d_1.csta = const_cast<char*>("delete");
    f_clos(&feq_gen_cl_d_1);
/* SOURCE pwd.for:25 */
/*<       return >*/
    return 0;
/* SOURCE pwd.for:26 */
/*<       end >*/
} /* pwd_ */

#ifdef __cplusplus
	}
#endif
