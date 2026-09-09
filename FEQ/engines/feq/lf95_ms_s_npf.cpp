/* lf95_ms_s_npf.f -- translated by f2c (version 20240504).
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

/*     Create a routine that can be called at runtime */
/*     that will report the compiler and the operating */
/*     system.  Also include a routine that will */
/*     report the operating system when called at runtime. */
/*     Fortran has no builtin means for reporting this */
/*     info so we create a system at compile time */
/*     that will do that.  A file like this one */
/*     will exist for each compiler-os supported.  The */
/*     script or batch file used to compile will then */
/*     select the correct one to include. */



/* SOURCE lf95_ms_s_npf.for:15 */
/*<       integerfunctionwhat_os() >*/
integer feq_gen_what_os_d_()
{
    /* System generated locals */
    integer ret_val;

/*     Return a coded value that gives the OS. */
/* SOURCE lf95_ms_s_npf.for:19 */
/*<       implicitnone >*/
/* SOURCE lf95_ms_s_npf.for:20 */
/*<       integerms,linux >*/
/* SOURCE lf95_ms_s_npf.for:21 */
/*<       parameter(ms=1,linux=2) >*/
/* *********************************************************************** */
/* SOURCE lf95_ms_s_npf.for:25 */
/*<       what_os=ms >*/
    ret_val = 1;
/* SOURCE lf95_ms_s_npf.for:26 */
/*<       return >*/
    return ret_val;
/* SOURCE lf95_ms_s_npf.for:27 */
/*<       end >*/
} /* what_os__ */




/* SOURCE lf95_ms_s_npf.for:31 */
/*<       integerfunctionwhat_compiler() >*/
integer feq_gen_what_compiler_d_()
{
    /* System generated locals */
    integer ret_val;

/*     Return a coded value that gives the compiler. */
/* SOURCE lf95_ms_s_npf.for:35 */
/*<       implicitnone >*/
/* SOURCE lf95_ms_s_npf.for:36 */
/*<       integerlf90,lf95_ms,lf95_lnx,pgi,intel,gnu77 >*/
/* SOURCE lf95_ms_s_npf.for:37 */
/*<       parameter(lf90=1,lf95_ms=2,lf95_lnx=3,pgi=4,intel=5,gnu77=6) >*/
/* *********************************************************************** */
/* SOURCE lf95_ms_s_npf.for:41 */
/*<       what_compiler=lf95_ms >*/
    ret_val = 2;
/* SOURCE lf95_ms_s_npf.for:42 */
/*<       return >*/
    return ret_val;
/* SOURCE lf95_ms_s_npf.for:43 */
/*<       end >*/
} /* what_compiler__ */




/* SOURCE lf95_ms_s_npf.for:47 */
/*<       integerfunctionwhat_prefetch() >*/
integer feq_gen_what_prefetch_d_()
{
    /* System generated locals */
    integer ret_val;

/*     Return a coded value that gives the prefetch option. */
/* SOURCE lf95_ms_s_npf.for:51 */
/*<       implicitnone >*/
/* SOURCE lf95_ms_s_npf.for:52 */
/*<       integernone,level1,level2 >*/
/* SOURCE lf95_ms_s_npf.for:53 */
/*<       parameter(none=1,level1=2,level2=3) >*/
/* *********************************************************************** */
/* SOURCE lf95_ms_s_npf.for:57 */
/*<       what_prefetch=none >*/
    ret_val = 1;
/* SOURCE lf95_ms_s_npf.for:58 */
/*<       return >*/
    return ret_val;
/* SOURCE lf95_ms_s_npf.for:59 */
/*<       end >*/
} /* what_prefetch__ */




/* SOURCE lf95_ms_s_npf.for:64 */
/*<       integerfunctionwhat_precision() >*/
integer feq_gen_what_precision_d_()
{
    /* System generated locals */
    integer ret_val;

/*     Return a coded value that gives the prefetch option. */
/* SOURCE lf95_ms_s_npf.for:68 */
/*<       implicitnone >*/
/* SOURCE lf95_ms_s_npf.for:69 */
/*<       integersingle,double >*/
/* SOURCE lf95_ms_s_npf.for:70 */
/*<       parameter(single=1,double=2) >*/
/* *********************************************************************** */
/* SOURCE lf95_ms_s_npf.for:74 */
/*<       what_precision=single >*/
    ret_val = 1;
/* SOURCE lf95_ms_s_npf.for:75 */
/*<       return >*/
    return ret_val;
/* SOURCE lf95_ms_s_npf.for:76 */
/*<       end >*/
} /* what_precision__ */




/* SOURCE lf95_ms_s_npf.for:81 */
/*<       subroutinewhat_executable(stdout) >*/
/* Subroutine */ int feq_gen_what_executable_d_(integer *stdout)
{
    /* Initialized data */

    static char feq_gen_os_name_d_[40*2+1] = "MS Windows                             \
 Linux                                   ";
    static char feq_gen_compiler_name_d_[40*6+1] = "Lahey F90-V 4.5i                 \
       Lahey F95-V 5.70f                       Lahey F95-V 6.20d            \
           PGI F90 4.0                             Intel 6.0                \
               GNU77                                   ";
    static char feq_gen_prefetch_name_d_[70*3+1] = "No prefetch. For Pentium II and g\
reater. Athlon 64, Pentium 4.        Prefetch level 1. For Pentium III, Athl\
on. Not Pentium 4.             Prefetch level 2. For Pentium III, Athlon. No\
t Pentium 4.             ";
    static char feq_gen_precision_name_d_[40*2+1] = "Single                          \
        Double                                  ";

    /* Format strings */
    static char fmt_50[] = "(/,\002 Report on executable:\002,/,5x,\002 Oper\
ating system is: \002,a,/,5x,\002 Compiler used was: \002,a,/,5x,\002 Soluti\
on precision: \002,a,/,5x,\002 Prefetch option used was: \002,a)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer prefetch, compiler, precision, os;
    extern integer feq_gen_what_prefetch_d_(), feq_gen_what_compiler_d_(), feq_gen_what_precision_d_(), 
	    feq_gen_what_os_d_();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__9 = { 0, 0, 0, fmt_50, 0 };


/*     Report the compiler,the OS, and pre-fetch options for this executable. */
/* SOURCE lf95_ms_s_npf.for:84 */
/*<       implicitnone >*/
/* SOURCE lf95_ms_s_npf.for:86 */
/*<       integerstdout >*/
/*     Local */
/* SOURCE lf95_ms_s_npf.for:89 */
/*<       integeros,compiler,precision,prefetch >*/
/* SOURCE lf95_ms_s_npf.for:91 */
/*<       character*40os_name(2),compiler_name(6),precision_name(2) >*/
/* SOURCE lf95_ms_s_npf.for:92 */
/*<       character*70prefetch_name(3) >*/
/*     Called routines */
/* SOURCE lf95_ms_s_npf.for:95 */
/*<       integerwhat_os,what_compiler,what_prefetch,what_precision >*/
/*     **************************Formats********************************* */
/* SOURCE lf95_ms_s_npf.for:97 */
/*<       dataos_name/'MS Windows','Linux'/ >*/
/* SOURCE lf95_ms_s_npf.for:98 */
/*<        >*/
/* SOURCE lf95_ms_s_npf.for:100 */
/*<        >*/
/* SOURCE lf95_ms_s_npf.for:104 */
/*<       dataprecision_name/'Single','Double'/ >*/
/* SOURCE lf95_ms_s_npf.for:109 */
/*<    50  >*/
/* L50: */
/* *********************************************************************** */
/* SOURCE lf95_ms_s_npf.for:115 */
/*<       os=what_os() >*/
    os = feq_gen_what_os_d_();
/* SOURCE lf95_ms_s_npf.for:116 */
/*<       compiler=what_compiler() >*/
    compiler = feq_gen_what_compiler_d_();
/* SOURCE lf95_ms_s_npf.for:117 */
/*<       precision=what_precision() >*/
    precision = feq_gen_what_precision_d_();
/* SOURCE lf95_ms_s_npf.for:118 */
/*<       prefetch=what_prefetch() >*/
    prefetch = feq_gen_what_prefetch_d_();
/* SOURCE lf95_ms_s_npf.for:120 */
/*<        >*/
    feq_gen_io_d__9.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__9);
    do_fio(&feq_gen_c_d_1, feq_gen_os_name_d_ + (os - 1) * 40, (ftnlen)40);
    do_fio(&feq_gen_c_d_1, feq_gen_compiler_name_d_ + (compiler - 1) * 40, (ftnlen)40);
    do_fio(&feq_gen_c_d_1, feq_gen_precision_name_d_ + (precision - 1) * 40, (ftnlen)40);
    do_fio(&feq_gen_c_d_1, feq_gen_prefetch_name_d_ + (prefetch - 1) * 70, (ftnlen)70);
    e_wsfe();
/* SOURCE lf95_ms_s_npf.for:123 */
/*<       return >*/
    return 0;
/* SOURCE lf95_ms_s_npf.for:124 */
/*<       end >*/
} /* what_executable__ */

#ifdef __cplusplus
	}
#endif
