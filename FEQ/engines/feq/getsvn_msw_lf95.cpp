/* getsvn_msw_lf95.f -- translated by f2c (version 20240504).
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

static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_1 = 1;




/* SOURCE getsvn_msw_lf95.for:4 */
/*<       subroutinegetsvn_rev(stdout,home_dir,svn_rev,svn_mod) >*/
/* Subroutine */ int feq_gen_getsvn_rev_d_(integer *stdout, char *feq_gen_home_dir_d_, integer *
	feq_gen_svn_rev_d_, integer *feq_gen_svn_mod_d_, ftnlen home_dir_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Version number is \002,i8,\002 for the S\
ubversion working \002,\002copy\002)";
    static char fmt_52[] = "(/,\002*WRN:XXX* The working copy contains loc\
al \002,\002modifications.\002,/,5x,\002 The version number given is therefo\
re\002,\002 not current and may not properly\002,/,5x,\002 provide the versi\
on\002,\002 number required to retrieve all the same files \002,\002at a lat\
er time.\002)";
    static char fmt_54[] = "(/,\002*ERR:XXX Working directory is under Subve\
rsion but\002,\002 the command-line command: svnversion is not available.\
\002,/,5x,\002Skipping any attempt at finding the version number.\002,5x,\
\002 Consult file:svn.zxcv_ in current working directory for\002,\002 details\
\002)";

    /* System generated locals */
    address feq_gen_a_d_1[3];
    integer feq_gen_i_d_1[3], feq_gen_i_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(), i_indx(char *, char *, ftnlen, ftnlen), f_clos(
	    cllist *), s_wsfe(cilist *), e_wsfe(), s_rsfi(icilist *), e_rsfi()
	    ;

    /* Local variables */
    extern integer feq_gen_get_unit_d_(integer *);
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    integer feq_gen_under_svn_d_, it;
    extern /* Subroutine */ int feq_gen_feq_system3_d_(char *, char *, char *, ftnlen, 
	    ftnlen, ftnlen);
    char temp[256];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer mflag, stdun;
    extern /* Subroutine */ int system_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__9 = { 0, 6, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__11 = { 0, 6, 0, fmt_52, 0 };


/*     Given a home directory name for input files: */
/*     1. Check if the directory is under Subversion */
/*     2. Run svnversion on the home directory and */
/*       save its output. */

/*     3. Open the temp file and read its contents: */
/*        the response can be: */
/*        3.1 a single integer-the latest revision number */
/*        3.2 a single integer followed by M or S or both */
/*        3.3 two integers with a colon between.  Gives the */
/*            range of revisions in the working copy with */
/*            the larger number given last. */
/*        3.4 range of revisions followed by M or S or both. */

/*     We want to do: */
/*       1.1 extract the larger of the two revision numbers */
/*       1.2 note if an M is present and if so we write */
/*           a warning message that there are uncommitted */
/*           changes in the working copy.  Therefore, the */
/*           revision number DOES NOT fully specify the */
/*           file status for this current run. */
/*       1.3 Return the revision number. */
/* SOURCE getsvn_msw_lf95.for:30 */
/*<       implicitnone >*/
/* SOURCE getsvn_msw_lf95.for:32 */
/*<       integerstdout,svn_rev,svn_mod >*/
/* SOURCE getsvn_msw_lf95.for:34 */
/*<       character*(*)home_dir >*/
/* SOURCE getsvn_msw_lf95.for:36 */
/*<       integerget_unit >*/
/* SOURCE getsvn_msw_lf95.for:37 */
/*<       externalget_unit >*/
/*     Local */
/* SOURCE getsvn_msw_lf95.for:41 */
/*<       integeri,it,stdun,mflag,under_svn >*/
/* SOURCE getsvn_msw_lf95.for:43 */
/*<       character*256temp >*/
/*     *******************************Formats**************************** */
/* SOURCE getsvn_msw_lf95.for:4 */
/*<       integer feq_len_trim >*/
/* SOURCE getsvn_msw_lf95.for:4 */
/*<       external feq_len_trim >*/
/* SOURCE getsvn_msw_lf95.for:46 */
/*<    50  >*/
/* SOURCE getsvn_msw_lf95.for:48 */
/*<    52  >*/
/* SOURCE getsvn_msw_lf95.for:53 */
/*<    54  >*/
/* *********************************************************************** */
/* SOURCE getsvn_msw_lf95.for:59 */
/*<       mflag=0 >*/
/* L50: */
/* L52: */
/* L54: */
    mflag = 0;
/* SOURCE getsvn_msw_lf95.for:60 */
/*<       svn_rev=0 >*/
    *feq_gen_svn_rev_d_ = 0;
/* SOURCE getsvn_msw_lf95.for:61 */
/*<       svn_mod=0 >*/
    *feq_gen_svn_mod_d_ = 0;
/* SOURCE getsvn_msw_lf95.for:62 */
/*<       under_svn=0 >*/
    feq_gen_under_svn_d_ = 0;
/* SOURCE getsvn_msw_lf95.for:63 */
/*<       it=feq_len_trim(home_dir) >*/
    it = feq_gen_feq_len_trim_d_(feq_gen_home_dir_d_, home_dir_len);
/* SOURCE getsvn_msw_lf95.for:64 */
/*<       temp='dir /b /d '//home_dir(1:it)//'\.svn > dir.zxcv_ 2>&1' >*/
/* Writing concatenation */
    feq_gen_i_d_1[0] = 10, feq_gen_a_d_1[0] = const_cast<char*>("dir /b /d ");
    feq_gen_i_d_1[1] = it, feq_gen_a_d_1[1] = feq_gen_home_dir_d_;
    feq_gen_i_d_1[2] = 22, feq_gen_a_d_1[2] = const_cast<char*>("\\.svn > dir.zxcv_ 2>&1");
    s_cat(temp, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_3, (ftnlen)256);
/* SOURCE getsvn_msw_lf95.for:65 */
/*<       it=feq_len_trim(temp) >*/
    it = feq_gen_feq_len_trim_d_(temp, (ftnlen)256);
/* SOURCE getsvn_msw_lf95.for:66 */
/*<       callsystem(temp) >*/
    system_(temp, (ftnlen)256);
/* SOURCE getsvn_msw_lf95.for:67 */
/*<       stdun=get_unit(stdout) >*/
    stdun = feq_gen_get_unit_d_(stdout);
/* SOURCE getsvn_msw_lf95.for:68 */
/*<       open(unit=stdun,file='dir.zxcv_',status='old') >*/
    feq_gen_o_d_1.oerr = 0;
    feq_gen_o_d_1.ounit = stdun;
    feq_gen_o_d_1.ofnmlen = 9;
    feq_gen_o_d_1.ofnm = const_cast<char*>("dir.zxcv_");
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("old");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    f_open(&feq_gen_o_d_1);
/*     If the home directory is under Subversion, there will be one or */
/*     more directories in the subdirectory, .svn.  Otherwise, .svn */
/*     will not exist and an error message will be given.  Assuming that */
/*     the standard msw command prompt will be used by the system command, */
/*     the error message should be "File Not Found". */
/* SOURCE getsvn_msw_lf95.for:75 */
/*<       read(stdun,'(a)')temp >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciend = 0;
    feq_gen_ci_d_1.ciunit = stdun;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
    s_rsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, temp, (ftnlen)256);
    e_rsfe();
/* SOURCE getsvn_msw_lf95.for:76 */
/*<       under_svn=index(temp,'File Not Found') >*/
    feq_gen_under_svn_d_ = i_indx(temp, const_cast<char*>("File Not Found"), (ftnlen)256, (ftnlen)14);
/* SOURCE getsvn_msw_lf95.for:77 */
/*<       close(stdun) >*/
    feq_gen_cl_d_1.cerr = 0;
    feq_gen_cl_d_1.cunit = stdun;
    feq_gen_cl_d_1.csta = 0;
    f_clos(&feq_gen_cl_d_1);
/* SOURCE getsvn_msw_lf95.for:78 */
/*<       callsystem('del /q dir.zxcv_ > NUL 2>&1') >*/
    system_(const_cast<char*>("del /q dir.zxcv_ > NUL 2>&1"), (ftnlen)27);
/* SOURCE getsvn_msw_lf95.for:79 */
/*<       if(under_svn==0)then >*/
    if (feq_gen_under_svn_d_ == 0) {
/*       The home directory is under subversion.  Run svnversion and */
/*       get the info on the versions */
/* SOURCE getsvn_msw_lf95.for:82 */
/*<       it=feq_len_trim(home_dir) >*/
	it = feq_gen_feq_len_trim_d_(feq_gen_home_dir_d_, home_dir_len);
/* SOURCE getsvn_msw_lf95.for:83 */
/*<       callfeq_system3('svnversion ',home_dir,' > svn.zxcv_ 2>&1') >*/
	feq_gen_feq_system3_d_(const_cast<char*>("svnversion "), feq_gen_home_dir_d_, const_cast<char*>(" > svn.zxcv_ 2>&1"), (ftnlen)
		11, home_dir_len, (ftnlen)17);
/* SOURCE getsvn_msw_lf95.for:84 */
/*<       stdun=get_unit(stdout) >*/
	stdun = feq_gen_get_unit_d_(stdout);
/* SOURCE getsvn_msw_lf95.for:85 */
/*<       open(unit=stdun,file='svn.zxcv_',status='old') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = stdun;
	feq_gen_o_d_1.ofnmlen = 9;
	feq_gen_o_d_1.ofnm = const_cast<char*>("svn.zxcv_");
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("old");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE getsvn_msw_lf95.for:86 */
/*<       read(stdun,'(a)')temp >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciend = 0;
	feq_gen_ci_d_1.ciunit = stdun;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
	s_rsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, temp, (ftnlen)256);
	e_rsfe();
/*       Check if svnversion was available */
/* SOURCE getsvn_msw_lf95.for:88 */
/*<       i=index(temp,'not recognized as') >*/
	feq_gen_i_d_ = i_indx(temp, const_cast<char*>("not recognized as"), (ftnlen)256, (ftnlen)17);
/* SOURCE getsvn_msw_lf95.for:89 */
/*<       if(i==0)then >*/
	if (feq_gen_i_d_ == 0) {
/*         Try another command--4NT */
/* SOURCE getsvn_msw_lf95.for:91 */
/*<       i=index(temp,'Unknown command') >*/
	    feq_gen_i_d_ = i_indx(temp, const_cast<char*>("Unknown command"), (ftnlen)256, (ftnlen)15);
/* SOURCE getsvn_msw_lf95.for:92 */
/*<       endif >*/
	}
/* SOURCE getsvn_msw_lf95.for:93 */
/*<       if(i>0)then >*/
	if (feq_gen_i_d_ > 0) {
/*         Looks like svnversion is not available. */
/*        Command-line subversion may not be installed */
/* SOURCE getsvn_msw_lf95.for:96 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__7.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__7);
	    e_wsfe();
/* SOURCE getsvn_msw_lf95.for:97 */
/*<       else >*/
	} else {
/* SOURCE getsvn_msw_lf95.for:98 */
/*<       it=feq_len_trim(temp) >*/
	    it = feq_gen_feq_len_trim_d_(temp, (ftnlen)256);
/* SOURCE getsvn_msw_lf95.for:99 */
/*<       if(temp(it:it)=='S')then >*/
	    if (*(unsigned char *)&temp[it - 1] == 'S') {
/*           Ignore switched state for now. */
/* SOURCE getsvn_msw_lf95.for:101 */
/*<       it=it-1 >*/
		--it;
/* SOURCE getsvn_msw_lf95.for:102 */
/*<       endif >*/
	    }
/* SOURCE getsvn_msw_lf95.for:103 */
/*<       if(temp(it:it)=='M')then >*/
	    if (*(unsigned char *)&temp[it - 1] == 'M') {
/* SOURCE getsvn_msw_lf95.for:104 */
/*<       mflag=1 >*/
		mflag = 1;
/* SOURCE getsvn_msw_lf95.for:105 */
/*<       it=it-1 >*/
		--it;
/* SOURCE getsvn_msw_lf95.for:106 */
/*<       endif >*/
	    }
/*         Check if there is still an S left. */
/* SOURCE getsvn_msw_lf95.for:108 */
/*<       if(temp(it:it)=='S')then >*/
	    if (*(unsigned char *)&temp[it - 1] == 'S') {
/* SOURCE getsvn_msw_lf95.for:109 */
/*<       it=it-1 >*/
		--it;
/* SOURCE getsvn_msw_lf95.for:110 */
/*<       endif >*/
	    }
/*         We should have only integers and perhaps a colon */
/*         left in the string:) */
/* SOURCE getsvn_msw_lf95.for:114 */
/*<       i=index(temp,':') >*/
	    feq_gen_i_d_ = i_indx(temp, const_cast<char*>(":"), (ftnlen)256, (ftnlen)1);
/* SOURCE getsvn_msw_lf95.for:115 */
/*<       if(i==0)then >*/
	    if (feq_gen_i_d_ == 0) {
/*           No colon--should be only a single integer */
/* SOURCE getsvn_msw_lf95.for:117 */
/*<       read(temp(1:it),'(i8)')svn_rev >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = it;
		feq_gen_ici_d_1.iciunit = temp;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(i8)");
		s_rsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_svn_rev_d_), (ftnlen)sizeof(integer));
		e_rsfi();
/* SOURCE getsvn_msw_lf95.for:118 */
/*<       else >*/
	    } else {
/*           There is a colon.  Read the integer after it. */
/* SOURCE getsvn_msw_lf95.for:120 */
/*<       read(temp(i+1:it),'(i8)')svn_rev >*/
		feq_gen_i_d_2 = feq_gen_i_d_;
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = it - feq_gen_i_d_2;
		feq_gen_ici_d_1.iciunit = temp + feq_gen_i_d_2;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(i8)");
		s_rsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_svn_rev_d_), (ftnlen)sizeof(integer));
		e_rsfi();
/* SOURCE getsvn_msw_lf95.for:121 */
/*<       endif >*/
	    }
/* SOURCE getsvn_msw_lf95.for:122 */
/*<       callfree_unit(stdout,stdun) >*/
	    feq_gen_free_unit_d_(stdout, &stdun);
/* SOURCE getsvn_msw_lf95.for:123 */
/*<       callsystem('del /q svn.zxcv_ > NUL 2>&1') >*/
	    system_(const_cast<char*>("del /q svn.zxcv_ > NUL 2>&1"), (ftnlen)27);
/* SOURCE getsvn_msw_lf95.for:124 */
/*<       endif >*/
	}
/* SOURCE getsvn_msw_lf95.for:125 */
/*<       endif >*/
    }
/* SOURCE getsvn_msw_lf95.for:126 */
/*<       if(svn_rev>0)then >*/
    if (*feq_gen_svn_rev_d_ > 0) {
/* SOURCE getsvn_msw_lf95.for:127 */
/*<       write(stdout,50)svn_rev >*/
	feq_gen_io_d__8.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__8);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_svn_rev_d_), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE getsvn_msw_lf95.for:128 */
/*<       write(*,50)svn_rev >*/
	s_wsfe(&feq_gen_io_d__9);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_svn_rev_d_), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE getsvn_msw_lf95.for:129 */
/*<       if(mflag>0)then >*/
	if (mflag > 0) {
/* SOURCE getsvn_msw_lf95.for:130 */
/*<       svn_mod=1 >*/
	    *feq_gen_svn_mod_d_ = 1;
/* SOURCE getsvn_msw_lf95.for:131 */
/*<       write(stdout,52) >*/
	    feq_gen_io_d__10.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__10);
	    e_wsfe();
/* SOURCE getsvn_msw_lf95.for:132 */
/*<       write(*,52) >*/
	    s_wsfe(&feq_gen_io_d__11);
	    e_wsfe();
/* SOURCE getsvn_msw_lf95.for:133 */
/*<       endif >*/
	}
/* SOURCE getsvn_msw_lf95.for:134 */
/*<       endif >*/
    }
/* SOURCE getsvn_msw_lf95.for:136 */
/*<       return >*/
    return 0;
/* SOURCE getsvn_msw_lf95.for:137 */
/*<       end >*/
} /* getsvn_rev__ */

#ifdef __cplusplus
	}
#endif
