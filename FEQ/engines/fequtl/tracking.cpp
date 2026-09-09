/* tracking.f -- translated by f2c (version 20240504).
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
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_0 = 0;

/*     Program units related to tracking of files.  Will */
/*     expand over time as we extend coverage to a greater */
/*     depth in the files involved in a model. */



/* SOURCE tracking.for:8 */
/*<       subroutineupdate_message(line,m,message) >*/
/* Subroutine */ int feq_gen_update_message_d_(char *line, integer *m, char *message, 
	ftnlen line_len, ftnlen message_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, n;
    extern /* Subroutine */ int feq_gen_feq_adjustl_d_(char *, char *, ftnlen, ftnlen);
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    char string[256];

/*     Add the non-blank contents of line to the end of message . */
/*     On entry m points to the last character added to message */
/* SOURCE tracking.for:14 */
/*<       implicitnone >*/
/* SOURCE tracking.for:16 */
/*<       integerm >*/
/* SOURCE tracking.for:17 */
/*<       character*(*)line >*/
/* SOURCE tracking.for:18 */
/*<       character*(*)message >*/
/*     Local */
/* SOURCE tracking.for:21 */
/*<       integern,i >*/
/* SOURCE tracking.for:22 */
/*<       character*256string >*/
/* *********************************************************************** */
/* SOURCE tracking.for:8 */
/*<       integer feq_len_trim >*/
/* SOURCE tracking.for:8 */
/*<       external feq_len_trim >*/
/* SOURCE tracking.for:24 */
/*<       callfeq_adjustl(line,string) >*/
    feq_gen_feq_adjustl_d_(line, string, line_len, (ftnlen)256);
/* SOURCE tracking.for:26 */
/*<       n=feq_len_trim(string) >*/
    n = feq_gen_feq_len_trim_d_(string, (ftnlen)256);
/* SOURCE tracking.for:27 */
/*<       doi=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tracking.for:28 */
/*<       if(string(i:i)/=' ')then >*/
	if (*(unsigned char *)&string[feq_gen_i_d_ - 1] != ' ') {
/* SOURCE tracking.for:29 */
/*<       m=m+1 >*/
	    ++(*m);
/* SOURCE tracking.for:30 */
/*<       message(m:m)=string(i:i) >*/
	    *(unsigned char *)&message[*m - 1] = *(unsigned char *)&string[
		    feq_gen_i_d_ - 1];
/* SOURCE tracking.for:31 */
/*<       endif >*/
	}
/* SOURCE tracking.for:32 */
/*<       enddo >*/
    }
/* SOURCE tracking.for:33 */
/*<       return >*/
    return 0;
/* SOURCE tracking.for:34 */
/*<       end >*/
} /* update_message__ */




/* SOURCE tracking.for:40 */
/*<       subroutinecopy_master_input_file(stdin,stdscr) >*/
/* Subroutine */ int feq_gen_copy_master_input_file_d_(integer *stdin, integer *stdscr)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;
    olist feq_gen_o_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(), s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char 
	    *, ftnlen, ftnlen), f_rew(alist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer it;
    char line[256];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Copy the master-input to a scratch file so that we can process */
/*     it for computing md5 digests of various blocks of input after we */
/*     have processed the header information. */
/* SOURCE tracking.for:46 */
/*<       implicitnone >*/
/* SOURCE tracking.for:48 */
/*<       integerstdin,stdscr >*/
/*     Local */
/* SOURCE tracking.for:51 */
/*<       integerit >*/
/* SOURCE tracking.for:53 */
/*<       character*256line >*/
/* *********************************************************************** */
/*     open the scratch file */
/* SOURCE tracking.for:40 */
/*<       integer feq_len_trim >*/
/* SOURCE tracking.for:40 */
/*<       external feq_len_trim >*/
/* SOURCE tracking.for:56 */
/*<       open(unit=stdscr,file='scratch',status='unknown') >*/
    feq_gen_o_d_1.oerr = 0;
    feq_gen_o_d_1.ounit = *stdscr;
    feq_gen_o_d_1.ofnmlen = 7;
    feq_gen_o_d_1.ofnm = const_cast<char*>("scratch");
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("unknown");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    f_open(&feq_gen_o_d_1);
/* SOURCE tracking.for:58 */
/*<       dowhile(.true.) >*/
    while(TRUE_) {
/* SOURCE tracking.for:59 */
/*<       read(stdin,'(a)',end=999)line >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciend = 1;
	feq_gen_ci_d_1.ciunit = *stdin;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
	feq_gen_i_d_1 = s_rsfe(&feq_gen_ci_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, (ftnlen)256);
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsfe();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE tracking.for:60 */
/*<       it=feq_len_trim(line) >*/
	it = feq_gen_feq_len_trim_d_(line, (ftnlen)256);
/* SOURCE tracking.for:61 */
/*<       write(stdscr,'(a)')line(1:it) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdscr;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, it);
	e_wsfe();
/* SOURCE tracking.for:62 */
/*<       if(line(1:6)=='FINISH')then >*/
	if (s_cmp(line, const_cast<char*>("FINISH"), (ftnlen)6, (ftnlen)6) == 0) {
/* SOURCE tracking.for:63 */
/*<       goto99000 >*/
	    goto L99000;
/* SOURCE tracking.for:64 */
/*<       endif >*/
	}
/* SOURCE tracking.for:65 */
/*<       enddo >*/
    }
/* SOURCE tracking.for:65 */
/*< 99000 continue >*/
L99000:
/*     Do not close the scratch file because if we do it will be deleted. */
/* SOURCE tracking.for:67 */
/*<       rewindstdscr >*/
    feq_gen_al_d_1.aerr = 0;
    feq_gen_al_d_1.aunit = *stdscr;
    f_rew(&feq_gen_al_d_1);
/* SOURCE tracking.for:68 */
/*<       rewindstdin >*/
    feq_gen_al_d_1.aerr = 0;
    feq_gen_al_d_1.aunit = *stdin;
    f_rew(&feq_gen_al_d_1);
/* SOURCE tracking.for:69 */
/*<       return >*/
    return 0;
/* SOURCE tracking.for:71 */
/*<   999 continue >*/
L999:
/*     We should reach here only if the user has failed to properly terminate the */
/*     master-input file for FEQUTL.  Supply a FINISH statement for the scratch */
/*     file to prevent problems later.  The end of file on the master-input file */
/*     is detected elsewhere during processing. */
/* SOURCE tracking.for:76 */
/*<       line='FINISH' >*/
    s_copy(line, const_cast<char*>("FINISH"), (ftnlen)256, (ftnlen)6);
/* SOURCE tracking.for:77 */
/*<       it=6 >*/
    it = 6;
/* SOURCE tracking.for:78 */
/*<       write(stdscr,'(a)')line(1:it) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdscr;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE tracking.for:79 */
/*<       rewindstdscr >*/
    feq_gen_al_d_1.aerr = 0;
    feq_gen_al_d_1.aunit = *stdscr;
    f_rew(&feq_gen_al_d_1);
/* SOURCE tracking.for:80 */
/*<       return >*/
    return 0;
/* SOURCE tracking.for:82 */
/*<       end >*/
} /* copy_master_input_file__ */




/* SOURCE tracking.for:86 */
/*<        >*/
/* Subroutine */ int feq_gen_find_md5_for_fequtl_input_d_(integer *stdscr, integer *
	stdout, integer *stdsys, integer *stdin, char *fname, integer *ncmd, 
	char *feq_storage_cmdtab, integer *feq_storage_cmdval, char *feq_gen_conf_file_d_, char *ghome, ftnlen 
	fname_len, ftnlen cmdtab_len, ftnlen conf_file_len, ftnlen ghome_len)
{
    /* Format strings */
    static char fmt_50[] = "(a16,1x,a8,1x,i5,i5,1x,a8,1x,a32,1x,a)";

    /* System generated locals */
    address feq_gen_a_d_1[3], feq_gen_a_d_2[2];
    integer feq_gen_i_d_1[3], feq_gen_i_d_2[2], feq_gen_i_d_3;
    cilist feq_gen_ci_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), f_rew(alist *), i_indx(char *, char *, ftnlen, 
	    ftnlen), s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_rsfe(), s_cmp(char *, char *, ftnlen, ftnlen), f_clos(cllist *),
	     s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    extern integer feq_gen_get_unit_d_(integer *);
    integer feq_gen_i_d_, m;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    char feq_gen_md5_digest_d_[32];
    integer feq_gen_stdmd5_mif_d_, ie, ip, is, it;
    extern /* Subroutine */ int md5_(char *, char *, ftnlen, ftnlen);
    integer feq_gen_feql_index1_d_;
    char cmd[8], cwd[256];
    extern /* Subroutine */ int pwd_(char *, ftnlen), feq_gen_feq_adjustl_d_(char *, 
	    char *, ftnlen, ftnlen);
    char feq_gen_conf_file_with_path_d_[256], feq_gen_md5_header_file_name_d_[256], feq_gen_name_d_[9], 
	    line[192];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    char feq_gen_md5_file_name_d_[256];
    integer feq_gen_stdmd5_header_d_;
    char tabid[16], feq_gen_class_d_[8], feq_gen_standard_name_d_[8], feq_gen_mif_with_path_d_[256];
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen);
    integer stdmd5;
    extern /* Subroutine */ int binser_(char *, integer *, char *, integer *, 
	    ftnlen, ftnlen);
    integer stdtmp;
    extern /* Subroutine */ int feq_gen_update_message_d_(char *, integer *, char *, 
	    ftnlen, ftnlen);
    char feq_gen_cmd_in_process_d_[8], command[8*44], message[256000];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__9 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, 0, 0 };


/*     Compute the standard md5 digests for various parts of the master-input */
/*     file for fequtl and place the results in a special file.  The master-input */
/*     file is open at this point but nothing has been read from it. */
/* SOURCE tracking.for:94 */
/*<       implicitnone >*/
/* SOURCE tracking.for:96 */
/*<       integerstdscr,stdout,stdsys,stdin,ncmd >*/
/* SOURCE tracking.for:98 */
/*<       character*(*)fname,conf_file,ghome >*/
/* SOURCE tracking.for:99 */
/*<       integercmdval(ncmd) >*/
/* SOURCE tracking.for:100 */
/*<       character*8cmdtab(ncmd) >*/
/*     Called program units */
/* SOURCE tracking.for:103 */
/*<       integerget_unit >*/
/* SOURCE tracking.for:104 */
/*<       externalget_unit >*/
/*     Local */
/* SOURCE tracking.for:108 */
/*<       integermaxm >*/
/* SOURCE tracking.for:109 */
/*<       parameter(maxm=256000) >*/
/* SOURCE tracking.for:111 */
/*<       integeri,ip,it,j,is,ie,m,stdmd5,stdtmp,stdmd5_header,stdmd5_mif >*/
/* SOURCE tracking.for:114 */
/*<        >*/
/*     *****************************formats****************************** */
/* SOURCE tracking.for:86 */
/*<       integer feql_index1 >*/
/* SOURCE tracking.for:86 */
/*<       integer feq_len_trim >*/
/* SOURCE tracking.for:86 */
/*<       external feq_len_trim >*/
/* SOURCE tracking.for:121 */
/*<    50 format(a16,1x,a8,1x,i5,i5,1x,a8,1x,a32,1x,a) >*/
/* *********************************************************************** */
/*     Setup the standard command names.  Needed because a user can change */
/*     the name of a command! */
/* SOURCE tracking.for:125 */
/*<       dofeql_index1=1,44 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> cmdval(feq_storage_cmdval, 1);

    feq::IndexedPointer<char> cmdtab(feq_storage_cmdtab, 8);

    /* Function Body */
/* L50: */
    for (feq_gen_feql_index1_d_ = 1; feq_gen_feql_index1_d_ <= 44; ++feq_gen_feql_index1_d_) {
/* SOURCE tracking.for:125 */
/*<       command(feql_index1)='null' >*/
	s_copy(command + (feq_gen_feql_index1_d_ - 1 << 3), const_cast<char*>("null"), (ftnlen)8, (ftnlen)
		4);
/* SOURCE tracking.for:125 */
/*<       enddo >*/
    }
/* SOURCE tracking.for:126 */
/*<       command(1)='FEQX    ' >*/
    s_copy(command, const_cast<char*>("FEQX    "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:127 */
/*<       command(2)='FLOODWAY' >*/
    s_copy(command + 8, const_cast<char*>("FLOODWAY"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:128 */
/*<       command(3)='BRIDGE  ' >*/
    s_copy(command + 16, const_cast<char*>("BRIDGE  "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:129 */
/*<       command(4)='CULVERT ' >*/
    s_copy(command + 24, const_cast<char*>("CULVERT "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:130 */
/*<       command(5)='FINISH  ' >*/
    s_copy(command + 32, const_cast<char*>("FINISH  "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:131 */
/*<       command(8)='FEQXLST ' >*/
    s_copy(command + 56, const_cast<char*>("FEQXLST "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:132 */
/*<       command(10)='SEWER   ' >*/
    s_copy(command + 72, const_cast<char*>("SEWER   "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:133 */
/*<       command(11)='MULPIPES' >*/
    s_copy(command + 80, const_cast<char*>("MULPIPES"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:134 */
/*<       command(12)='FTABIN  ' >*/
    s_copy(command + 88, const_cast<char*>("FTABIN  "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:135 */
/*<       command(13)='EMBANKQ ' >*/
    s_copy(command + 96, const_cast<char*>("EMBANKQ "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:136 */
/*<       command(15)='CRITQ   ' >*/
    s_copy(command + 112, const_cast<char*>("CRITQ   "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:137 */
/*<       command(16)='GRITTER ' >*/
    s_copy(command + 120, const_cast<char*>("GRITTER "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:138 */
/*<       command(18)='MULCON  ' >*/
    s_copy(command + 136, const_cast<char*>("MULCON  "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:139 */
/*<       command(19)='CHANRAT ' >*/
    s_copy(command + 144, const_cast<char*>("CHANRAT "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:140 */
/*<       command(20)='EXPCON  ' >*/
    s_copy(command + 152, const_cast<char*>("EXPCON  "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:141 */
/*<       command(21)='HEC2X   ' >*/
    s_copy(command + 160, const_cast<char*>("HEC2X   "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:142 */
/*<       command(22)='QCLIMIT ' >*/
    s_copy(command + 168, const_cast<char*>("QCLIMIT "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:143 */
/*<       command(23)='XSINTERP' >*/
    s_copy(command + 176, const_cast<char*>("XSINTERP"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:144 */
/*<       command(25)='FEQXEXT ' >*/
    s_copy(command + 192, const_cast<char*>("FEQXEXT "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:145 */
/*<       command(26)='CHANNEL ' >*/
    s_copy(command + 200, const_cast<char*>("CHANNEL "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:146 */
/*<       command(27)='WSPROX  ' >*/
    s_copy(command + 208, const_cast<char*>("WSPROX  "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:147 */
/*<       command(28)='WSPROQZ ' >*/
    s_copy(command + 216, const_cast<char*>("WSPROQZ "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:148 */
/*<       command(29)='WSPROT14' >*/
    s_copy(command + 224, const_cast<char*>("WSPROT14"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:149 */
/*<       command(30)='UFGATE  ' >*/
    s_copy(command + 232, const_cast<char*>("UFGATE  "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:150 */
/*<       command(31)='RISERCLV' >*/
    s_copy(command + 240, const_cast<char*>("RISERCLV"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:151 */
/*<       command(32)='ORIFICE ' >*/
    s_copy(command + 248, const_cast<char*>("ORIFICE "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:152 */
/*<       command(33)='AXIALPMP' >*/
    s_copy(command + 256, const_cast<char*>("AXIALPMP"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:153 */
/*<       command(34)='PUMPLOSS' >*/
    s_copy(command + 264, const_cast<char*>("PUMPLOSS"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:154 */
/*<       command(35)='SETSLOT ' >*/
    s_copy(command + 272, const_cast<char*>("SETSLOT "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:155 */
/*<       command(36)='CLRSLOT ' >*/
    s_copy(command + 280, const_cast<char*>("CLRSLOT "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:156 */
/*<       command(39)='MKEMBANK' >*/
    s_copy(command + 304, const_cast<char*>("MKEMBANK"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:157 */
/*<       command(40)='MKWSPRO ' >*/
    s_copy(command + 312, const_cast<char*>("MKWSPRO "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:158 */
/*<       command(41)='wsprot14' >*/
    s_copy(command + 320, const_cast<char*>("wsprot14"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:159 */
/*<       command(42)='LPRFIT  ' >*/
    s_copy(command + 328, const_cast<char*>("LPRFIT  "), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:160 */
/*<       command(44)='SETSLOTE' >*/
    s_copy(command + 344, const_cast<char*>("SETSLOTE"), (ftnlen)8, (ftnlen)8);
/*     Create the file name for the md5 digest and related info.  It is */
/*     formed from the master-input file name by appending '.md5' to */
/*     that name.  The file will be placed in the current working directory */
/*     from which fequtl was invoked.  The standard usage for fequtl is to execute it in the */
/*     directory that contains the files on its command line. */
/*     Find the current working directory. */
/* SOURCE tracking.for:168 */
/*<       callpwd(cwd) >*/
    pwd_(cwd, (ftnlen)256);
/* SOURCE tracking.for:170 */
/*<       write(stdout,*)' Current working directory=',cwd >*/
    feq_gen_io_d__9.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__9);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Current working directory="), (ftnlen)27);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, cwd, (ftnlen)256);
    e_wsle();
/*     Add the path to the master-input file (mif) name. */
/* SOURCE tracking.for:173 */
/*<       it=feq_len_trim(cwd) >*/
    it = feq_gen_feq_len_trim_d_(cwd, (ftnlen)256);
/* SOURCE tracking.for:175 */
/*<       mif_with_path=cwd(1:it)//'/'//fname >*/
/* Writing concatenation */
    feq_gen_i_d_1[0] = it, feq_gen_a_d_1[0] = cwd;
    feq_gen_i_d_1[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("/");
    feq_gen_i_d_1[2] = fname_len, feq_gen_a_d_1[2] = fname;
    s_cat(feq_gen_mif_with_path_d_, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_3, (ftnlen)256);
/* SOURCE tracking.for:176 */
/*<       callos_file_style(mif_with_path) >*/
    feq_gen_os_file_style_d_(feq_gen_mif_with_path_d_, (ftnlen)256);
/* SOURCE tracking.for:178 */
/*<       it=feq_len_trim(mif_with_path) >*/
    it = feq_gen_feq_len_trim_d_(feq_gen_mif_with_path_d_, (ftnlen)256);
/* SOURCE tracking.for:180 */
/*<       md5_file_name=mif_with_path(1:it)//'.md5' >*/
/* Writing concatenation */
    feq_gen_i_d_2[0] = it, feq_gen_a_d_2[0] = feq_gen_mif_with_path_d_;
    feq_gen_i_d_2[1] = 4, feq_gen_a_d_2[1] = const_cast<char*>(".md5");
    s_cat(feq_gen_md5_file_name_d_, feq_gen_a_d_2, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)256);
/* SOURCE tracking.for:181 */
/*<       stdmd5_mif=get_unit(0) >*/
    feq_gen_stdmd5_mif_d_ = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE tracking.for:182 */
/*<       open(unit=stdmd5_mif,file=md5_file_name,status='unknown') >*/
    feq_gen_o_d_1.oerr = 0;
    feq_gen_o_d_1.ounit = feq_gen_stdmd5_mif_d_;
    feq_gen_o_d_1.ofnmlen = 256;
    feq_gen_o_d_1.ofnm = feq_gen_md5_file_name_d_;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("unknown");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    f_open(&feq_gen_o_d_1);
/* SOURCE tracking.for:185 */
/*<       it=feq_len_trim(ghome) >*/
    it = feq_gen_feq_len_trim_d_(ghome, ghome_len);
/* SOURCE tracking.for:186 */
/*<       mif_with_path=mif_with_path(it+1:) >*/
    feq_gen_i_d_3 = it;
    s_copy(feq_gen_mif_with_path_d_, feq_gen_mif_with_path_d_ + feq_gen_i_d_3, (ftnlen)256, 256 - feq_gen_i_d_3);
/* SOURCE tracking.for:188 */
/*<        >*/
    feq_gen_io_d__14.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__14);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" MIF name relative to global home name="), (ftnlen)
	    39);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_mif_with_path_d_, (ftnlen)256);
    e_wsle();
/*     General outline of the approach:  For each command block of the */
/*     input: */
/*       record first line number and last line number */
/*       compute the message as a concatenation of all characters in */
/*       block with all spaces removed.  We also delete blank lines, */
/*       and comment lines.  However, trailing comments on a line are */
/*       retained.  However, these lines are retained when establishing */
/*       the starting and ending line numbers. */

/*       When the block has a TABID it will be used to reference the */
/*       md5 digest and related info.  When it does not have a TABID, */
/*       it may stand along, like FTABIN, or it may be a modifier of */
/*       a command to come later.  This applies to SETSLOTx, and CHANNEL, */
/*       for example.  We need to remember these later two and then */
/*       add them to the description for the block or blocks they affect */
/*       and that do have a TABID.  There are some cases in which a */
/*       block has a TABID but yet is also a modifier to a subsequent */
/*       command.  An example of this would be the FEQxxx family of commands */
/*       that compute cross section tables.  These are often used to compute */
/*       the cross-section function tables required for a subsequent */
/*       command.  There may be no table output from such a command and */
/*       then it is a pure modifier.  But it is also possible that the */
/*       FEQxxx command is both a modifier and also a creater of a */
/*       function table that is placed in the *.tab file.  Thus the */
/*       prescence of a SAVE option creates a modifer state and the */
/*       prescence of NOOUT makes it a pure modifier.  As is already */
/*       clear, we will have to make some rather fine distinctions to */
/*       make sense of the tracking system. */

/*       Many details yet to be defined: 13 Dec 2007 */
/*       14 Dec 2007:  After a few test runs it is apparent that */
/*       we must implement command specific process here.  Each command */
/*       has its nuances.  Thus we will start with implementing the */
/*       simpler commands.  This also requires that we allow for a */
/*       there being no tracking for some function tables. */

/*     Process the header block. If stdin = stdsys, then the header block */
/*     is in the file pointed to by stdscr, otherwise, it is in the */
/*     file pointed to by stdsys and has ALREADY been read to the end. */
/*     Thus we must rewind the file before we start to process it!  We are */
/*     interested in the following lines for the reasons given: */
/*     UNITS=  ENGLISH  NOMINAL      45.0       0.0 */
/*      The above line affects the value of g used.  Thus affects */
/*      anything that includes the value of the gravitational acceleration. */

/*     DZLIM= */
/*       The above line affects cross-section function tables */

/*     NRZERO= */
/*       The above line affects cross-section function tables */

/*     EPSARG */
/*       Affects any commands that use an iteration to find a solution. */

/*     EPSF=      EPSABS= */
/*       Affects any commands that us an iteration to find a solution. */

/*     EXTEND= */
/*       Affects cross-section function tables */

/*     MINQ= */
/*      Affects flow tables from EMBANKQ and CHANRAT */

/*     We will compute the md5sum for each of these lines, if present, */
/*     and store each using the first name on the line.  These will all */
/*     be modifiers,  that is, they are values whose change affect all */
/*     tables of a given class. */
/* SOURCE tracking.for:261 */
/*<       if(stdsys==stdin)then >*/
    if (*stdsys == *stdin) {
/*       The header information is in the file pointed to by stdscr */
/*       and has not been read yet!  The header block is in the master-input */
/*       file to fequtl */
/* SOURCE tracking.for:265 */
/*<       stdtmp=stdscr >*/
	stdtmp = *stdscr;
/* SOURCE tracking.for:266 */
/*<       stdmd5=stdmd5_mif >*/
	stdmd5 = feq_gen_stdmd5_mif_d_;
/* SOURCE tracking.for:267 */
/*<       conf_file_with_path=mif_with_path >*/
	s_copy(feq_gen_conf_file_with_path_d_, feq_gen_mif_with_path_d_, (ftnlen)256, (ftnlen)
		256);
/* SOURCE tracking.for:268 */
/*<       else >*/
    } else {
/*       The header information is in the file pointed to by stdsys and */
/*       has been read already!   THe header block is in a distinct configuration */
/*       file. */
/* SOURCE tracking.for:272 */
/*<       rewind(stdsys) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdsys;
	f_rew(&feq_gen_al_d_1);
/* SOURCE tracking.for:273 */
/*<       stdtmp=stdsys >*/
	stdtmp = *stdsys;
/*       Get the path name for the conf file.  The file was given */
/*       with a full path name (perhaps missing a drive letter under */
/*       MSW) or it was in the current working directory.  We first */
/*       try to determine if the full path name was given, in which */
/*       case we have what we want.  If that fails, then the file */
/*       was in the current working directory, so we prepend the path */
/*       we found for the MIF. */
/* SOURCE tracking.for:282 */
/*<       conf_file_with_path=conf_file >*/
	s_copy(feq_gen_conf_file_with_path_d_, feq_gen_conf_file_d_, (ftnlen)256, conf_file_len)
		;
/* SOURCE tracking.for:283 */
/*<       callos_file_style(conf_file_with_path) >*/
	feq_gen_os_file_style_d_(feq_gen_conf_file_with_path_d_, (ftnlen)256);
/* SOURCE tracking.for:285 */
/*<       it=index(conf_file_with_path,':') >*/
	it = i_indx(feq_gen_conf_file_with_path_d_, const_cast<char*>(":"), (ftnlen)256, (ftnlen)1);
/* SOURCE tracking.for:286 */
/*<        >*/
	if (it > 0 || *(unsigned char *)feq_gen_conf_file_with_path_d_ == '~' || *(
		unsigned char *)feq_gen_conf_file_with_path_d_ == '/' || *(unsigned 
		char *)feq_gen_conf_file_with_path_d_ == '\\') {
/*         A full path name was given when the file was referenced */
/* SOURCE tracking.for:291 */
/*<       continue >*/
/* SOURCE tracking.for:292 */
/*<       else >*/
	} else {
/*         Prepend the cwd found above */
/* SOURCE tracking.for:294 */
/*<       it=feq_len_trim(cwd) >*/
	    it = feq_gen_feq_len_trim_d_(cwd, (ftnlen)256);
/* SOURCE tracking.for:295 */
/*<       conf_file_with_path=cwd(1:it)//'/'//conf_file >*/
/* Writing concatenation */
	    feq_gen_i_d_1[0] = it, feq_gen_a_d_1[0] = cwd;
	    feq_gen_i_d_1[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("/");
	    feq_gen_i_d_1[2] = conf_file_len, feq_gen_a_d_1[2] = feq_gen_conf_file_d_;
	    s_cat(feq_gen_conf_file_with_path_d_, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_3, (ftnlen)256);
/* SOURCE tracking.for:296 */
/*<       callos_file_style(conf_file_with_path) >*/
	    feq_gen_os_file_style_d_(feq_gen_conf_file_with_path_d_, (ftnlen)256);
/* SOURCE tracking.for:298 */
/*<       endif >*/
	}
/*       create the md5 name for the header */
/* SOURCE tracking.for:301 */
/*<       it=feq_len_trim(conf_file_with_path) >*/
	it = feq_gen_feq_len_trim_d_(feq_gen_conf_file_with_path_d_, (ftnlen)256);
/* SOURCE tracking.for:302 */
/*<       md5_header_file_name=conf_file_with_path(1:it)//'.md5' >*/
/* Writing concatenation */
	feq_gen_i_d_2[0] = it, feq_gen_a_d_2[0] = feq_gen_conf_file_with_path_d_;
	feq_gen_i_d_2[1] = 4, feq_gen_a_d_2[1] = const_cast<char*>(".md5");
	s_cat(feq_gen_md5_header_file_name_d_, feq_gen_a_d_2, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)256);
/* SOURCE tracking.for:303 */
/*<       stdmd5_header=get_unit(0) >*/
	feq_gen_stdmd5_header_d_ = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE tracking.for:304 */
/*<        >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_stdmd5_header_d_;
	feq_gen_o_d_1.ofnmlen = 256;
	feq_gen_o_d_1.ofnm = feq_gen_md5_header_file_name_d_;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("unknown");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE tracking.for:306 */
/*<       stdmd5=stdmd5_header >*/
	stdmd5 = feq_gen_stdmd5_header_d_;
/*       Get the file name for the standard header relative to the global */
/*       home name. */
/* SOURCE tracking.for:309 */
/*<       it=feq_len_trim(ghome) >*/
	it = feq_gen_feq_len_trim_d_(ghome, ghome_len);
/* SOURCE tracking.for:310 */
/*<       conf_file_with_path=conf_file_with_path(it+1:) >*/
	feq_gen_i_d_3 = it;
	s_copy(feq_gen_conf_file_with_path_d_, feq_gen_conf_file_with_path_d_ + feq_gen_i_d_3, (ftnlen)
		256, 256 - feq_gen_i_d_3);
/* SOURCE tracking.for:311 */
/*<       endif >*/
    }
/* SOURCE tracking.for:312 */
/*<        >*/
    feq_gen_io_d__20.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__20);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("conf file name relative to global home name="), (
	    ftnlen)44);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_conf_file_with_path_d_, (ftnlen)256);
    e_wsle();
/* SOURCE tracking.for:316 */
/*<       i=0 >*/
    feq_gen_i_d_ = 0;
/* SOURCE tracking.for:317 */
/*<       dowhile(.true.) >*/
    while(TRUE_) {
/* SOURCE tracking.for:318 */
/*<       read(stdtmp,'(a)')line >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciend = 0;
	feq_gen_ci_d_1.ciunit = stdtmp;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
	s_rsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)192);
	e_rsfe();
/* SOURCE tracking.for:319 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE tracking.for:321 */
/*<       if(line(1:6)=='UNITS=')then >*/
	if (s_cmp(line, const_cast<char*>("UNITS="), (ftnlen)6, (ftnlen)6) == 0) {
/* SOURCE tracking.for:322 */
/*<       name='UNITS=' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>("UNITS="), (ftnlen)9, (ftnlen)6);
/* SOURCE tracking.for:323 */
/*<       elseif(line(1:6)=='DZLIM=')then >*/
	} else if (s_cmp(line, const_cast<char*>("DZLIM="), (ftnlen)6, (ftnlen)6) == 0) {
/* SOURCE tracking.for:324 */
/*<       name='DZLIM=' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>("DZLIM="), (ftnlen)9, (ftnlen)6);
/* SOURCE tracking.for:325 */
/*<       elseif(line(1:7)=='NRZERO=')then >*/
	} else if (s_cmp(line, const_cast<char*>("NRZERO="), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE tracking.for:326 */
/*<       name='NRZERO=' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>("NRZERO="), (ftnlen)9, (ftnlen)7);
/* SOURCE tracking.for:327 */
/*<       elseif(line(1:7)=='EPSARG=')then >*/
	} else if (s_cmp(line, const_cast<char*>("EPSARG="), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE tracking.for:328 */
/*<       name='EPSARG=' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>("EPSARG="), (ftnlen)9, (ftnlen)7);
/* SOURCE tracking.for:329 */
/*<       elseif(line(1:5)=='EPSF=')then >*/
	} else if (s_cmp(line, const_cast<char*>("EPSF="), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE tracking.for:330 */
/*<       name='EPSF=' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>("EPSF="), (ftnlen)9, (ftnlen)5);
/* SOURCE tracking.for:331 */
/*<       elseif(line(1:7)=='EXTEND=')then >*/
	} else if (s_cmp(line, const_cast<char*>("EXTEND="), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE tracking.for:332 */
/*<       name='EXTEND=' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>("EXTEND="), (ftnlen)9, (ftnlen)7);
/* SOURCE tracking.for:333 */
/*<       elseif(line(1:5)=='MINQ=')then >*/
	} else if (s_cmp(line, const_cast<char*>("MINQ="), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE tracking.for:334 */
/*<       name='MINQ=' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>("MINQ="), (ftnlen)9, (ftnlen)5);
/* SOURCE tracking.for:335 */
/*<       elseif(line==' ')then >*/
	} else if (s_cmp(line, const_cast<char*>(" "), (ftnlen)192, (ftnlen)1) == 0) {
/* SOURCE tracking.for:336 */
/*<       name='done' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>("done"), (ftnlen)9, (ftnlen)4);
/* SOURCE tracking.for:337 */
/*<       else >*/
	} else {
/* SOURCE tracking.for:338 */
/*<       name=' ' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>(" "), (ftnlen)9, (ftnlen)1);
/* SOURCE tracking.for:339 */
/*<       endif >*/
	}
/* SOURCE tracking.for:341 */
/*<       if(name=='done')then >*/
	if (s_cmp(feq_gen_name_d_, const_cast<char*>("done"), (ftnlen)9, (ftnlen)4) == 0) {
/*         We have reached the end of the header block. Tidy up afterward! */
/* SOURCE tracking.for:343 */
/*<       if(stdtmp==stdsys)then >*/
	    if (stdtmp == *stdsys) {
/*           The header block was in its own file. Close stdmd5, reset */
/*           to the master-input file value, clear the line counter. */
/* SOURCE tracking.for:346 */
/*<       close(stdmd5) >*/
		feq_gen_cl_d_1.cerr = 0;
		feq_gen_cl_d_1.cunit = stdmd5;
		feq_gen_cl_d_1.csta = 0;
		f_clos(&feq_gen_cl_d_1);
/* SOURCE tracking.for:347 */
/*<       stdmd5=stdmd5_mif >*/
		stdmd5 = feq_gen_stdmd5_mif_d_;
/* SOURCE tracking.for:348 */
/*<       i=0 >*/
		feq_gen_i_d_ = 0;
/* SOURCE tracking.for:349 */
/*<       endif >*/
	    }
/* SOURCE tracking.for:350 */
/*<       goto99000 >*/
	    goto L99000;
/* SOURCE tracking.for:351 */
/*<       endif >*/
	}
/* SOURCE tracking.for:353 */
/*<       if(name/=' ')then >*/
	if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), (ftnlen)9, (ftnlen)1) != 0) {
/* SOURCE tracking.for:354 */
/*<       m=0 >*/
	    m = 0;
/* SOURCE tracking.for:355 */
/*<       message='' >*/
	    s_copy(message, const_cast<char*>(""), (ftnlen)256000, (ftnlen)0);
/* SOURCE tracking.for:356 */
/*<       is=i >*/
	    is = feq_gen_i_d_;
/* SOURCE tracking.for:357 */
/*<       ie=i >*/
	    ie = feq_gen_i_d_;
/* SOURCE tracking.for:358 */
/*<       tabid=name >*/
	    s_copy(tabid, feq_gen_name_d_, (ftnlen)16, (ftnlen)9);
/* SOURCE tracking.for:359 */
/*<       class='modifier' >*/
	    s_copy(feq_gen_class_d_, const_cast<char*>("modifier"), (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:360 */
/*<       cmd_in_process=' ' >*/
	    s_copy(feq_gen_cmd_in_process_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tracking.for:361 */
/*<       callupdate_message(line,m,message) >*/
	    feq_gen_update_message_d_(line, &m, message, (ftnlen)192, (ftnlen)256000);
/* SOURCE tracking.for:363 */
/*<       callmd5(message(1:m),md5_digest) >*/
	    md5_(message, feq_gen_md5_digest_d_, m, (ftnlen)32);
/* SOURCE tracking.for:365 */
/*<       it=feq_len_trim(conf_file_with_path) >*/
	    it = feq_gen_feq_len_trim_d_(feq_gen_conf_file_with_path_d_, (ftnlen)256);
/* SOURCE tracking.for:366 */
/*<        >*/
	    feq_gen_io_d__32.ciunit = stdmd5;
	    s_wsfe(&feq_gen_io_d__32);
	    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_class_d_, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&is, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&ie, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, feq_gen_cmd_in_process_d_, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, feq_gen_md5_digest_d_, (ftnlen)32);
	    do_fio(&feq_gen_c_d_1, feq_gen_conf_file_with_path_d_, it);
	    e_wsfe();
/* SOURCE tracking.for:368 */
/*<       endif >*/
	}
/* SOURCE tracking.for:369 */
/*<       enddo >*/
    }
/* SOURCE tracking.for:369 */
/*< 99000 continue >*/
L99000:
/* SOURCE tracking.for:372 */
/*<       cmd_in_process=' ' >*/
    s_copy(feq_gen_cmd_in_process_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tracking.for:373 */
/*<       tabid=' ' >*/
    s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE tracking.for:374 */
/*<       class=' ' >*/
    s_copy(feq_gen_class_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tracking.for:375 */
/*<       dowhile(.true.) >*/
    while(TRUE_) {
/* SOURCE tracking.for:376 */
/*<       read(stdscr,'(a)')line >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciend = 0;
	feq_gen_ci_d_1.ciunit = *stdscr;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
	s_rsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)192);
	e_rsfe();
/* SOURCE tracking.for:378 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE tracking.for:379 */
/*<       write(stdout,*)'From scratch i=',i,' line=',line >*/
	feq_gen_io_d__33.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__33);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("From scratch i="), (ftnlen)15);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" line="), (ftnlen)6);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)192);
	e_wsle();
/*       Is this line a comment, or is it blank?  Note: old style comments are not */
/*       detected and become part of the command block that precedes them--DO NOT use */
/*       old style comments! */
/* SOURCE tracking.for:386 */
/*<        >*/
	if (*(unsigned char *)line == '*' || *(unsigned char *)line == '+' || 
		*(unsigned char *)line == ';' || s_cmp(line, const_cast<char*>(" "), (ftnlen)192,
		 (ftnlen)1) == 0) {
/* SOURCE tracking.for:388 */
/*<       write(stdout,*)' i=',i,' Skipping line:',line >*/
	    feq_gen_io_d__34.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__34);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" i="), (ftnlen)3);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Skipping line:"), (ftnlen)15);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)192);
	    e_wsle();
/* SOURCE tracking.for:389 */
/*<       goto98997 >*/
	    goto L98997;
/* SOURCE tracking.for:390 */
/*<       else >*/
	} else {
/*         Look for a command.  It should be the only value on the line. */
/* SOURCE tracking.for:392 */
/*<       cmd=line(1:8) >*/
	    s_copy(cmd, line, (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:393 */
/*<       callbinser(cmd,ncmd,cmdtab,ip) >*/
	    binser_(cmd, ncmd, cmdtab + 8, &ip, (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:396 */
/*<       if(ip/=0)then >*/
	    if (ip != 0) {
/*           We have found a command.  Is it FINISH? */
/* SOURCE tracking.for:398 */
/*<       standard_name=command(cmdval(ip)) >*/
		s_copy(feq_gen_standard_name_d_, command + (cmdval[ip] - 1 << 3), (
			ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:399 */
/*<       if(standard_name/='FINISH')then >*/
		if (s_cmp(feq_gen_standard_name_d_, const_cast<char*>("FINISH"), (ftnlen)8, (ftnlen)6) != 
			0) {
/*             No, it is not FINISH! */
/*             Are we already processing a cmd? */
/* SOURCE tracking.for:402 */
/*<       if(cmd_in_process/=' ')then >*/
		    if (s_cmp(feq_gen_cmd_in_process_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) != 
			    0) {
/*               Yes we are.  Wrap it up and output the result.   The message */
/*               is complete and ready to process. */
/* SOURCE tracking.for:405 */
/*<       callmd5(message(1:m),md5_digest) >*/
			md5_(message, feq_gen_md5_digest_d_, m, (ftnlen)32);
/* SOURCE tracking.for:408 */
/*<       ie=i-1 >*/
			ie = feq_gen_i_d_ - 1;
/* SOURCE tracking.for:410 */
/*<       it=feq_len_trim(mif_with_path) >*/
			it = feq_gen_feq_len_trim_d_(feq_gen_mif_with_path_d_, (ftnlen)256);
/* SOURCE tracking.for:411 */
/*<        >*/
			feq_gen_io_d__38.ciunit = stdmd5;
			s_wsfe(&feq_gen_io_d__38);
			do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, feq_gen_class_d_, (ftnlen)8);
			do_fio(&feq_gen_c_d_1, (char *)&is, (ftnlen)sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&ie, (ftnlen)sizeof(integer));
			do_fio(&feq_gen_c_d_1, feq_gen_cmd_in_process_d_, (ftnlen)8);
			do_fio(&feq_gen_c_d_1, feq_gen_md5_digest_d_, (ftnlen)32);
			do_fio(&feq_gen_c_d_1, feq_gen_mif_with_path_d_, it);
			e_wsfe();
/*               Clear the message buffer */
/* SOURCE tracking.for:415 */
/*<       m=0 >*/
			m = 0;
/* SOURCE tracking.for:416 */
/*<       message='' >*/
			s_copy(message, const_cast<char*>(""), (ftnlen)256000, (ftnlen)0);
/* SOURCE tracking.for:417 */
/*<       is=i >*/
			is = feq_gen_i_d_;
/* SOURCE tracking.for:418 */
/*<       cmd_in_process=cmd >*/
			s_copy(feq_gen_cmd_in_process_d_, cmd, (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:419 */
/*<       tabid=' ' >*/
			s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE tracking.for:420 */
/*<       class=' ' >*/
			s_copy(feq_gen_class_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tracking.for:421 */
/*<       callupdate_message(line,m,message) >*/
			feq_gen_update_message_d_(line, &m, message, (ftnlen)192, (
				ftnlen)256000);
/* SOURCE tracking.for:423 */
/*<       else >*/
		    } else {
/*               No, this is the first command */
/* SOURCE tracking.for:425 */
/*<       m=0 >*/
			m = 0;
/* SOURCE tracking.for:426 */
/*<       message='' >*/
			s_copy(message, const_cast<char*>(""), (ftnlen)256000, (ftnlen)0);
/* SOURCE tracking.for:427 */
/*<       is=i >*/
			is = feq_gen_i_d_;
/* SOURCE tracking.for:428 */
/*<       cmd_in_process=cmd >*/
			s_copy(feq_gen_cmd_in_process_d_, cmd, (ftnlen)8, (ftnlen)8);
/* SOURCE tracking.for:429 */
/*<       callupdate_message(line,m,message) >*/
			feq_gen_update_message_d_(line, &m, message, (ftnlen)192, (
				ftnlen)256000);
/* SOURCE tracking.for:431 */
/*<       write(stdout,*)' Trking: First command is:',cmd >*/
			feq_gen_io_d__39.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__39);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Trking: First command is:"), (
				ftnlen)26);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, cmd, (ftnlen)8);
			e_wsle();
/* SOURCE tracking.for:432 */
/*<       write(stdout,*)'is=',is,' m=',m >*/
			feq_gen_io_d__40.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__40);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("is="), (ftnlen)3);
			do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&is, (ftnlen)sizeof(
				integer));
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" m="), (ftnlen)3);
			do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&m, (ftnlen)sizeof(
				integer));
			e_wsle();
/* SOURCE tracking.for:433 */
/*<       endif >*/
		    }
/* SOURCE tracking.for:434 */
/*<       else >*/
		} else {
/*             We have found the end of the input.  Wrap up the md5 file, and */
/*             close the scratch file. */
/* SOURCE tracking.for:437 */
/*<       callfree_unit(0,stdscr) >*/
		    feq_gen_free_unit_d_(&feq_gen_c_d_0, stdscr);
/* SOURCE tracking.for:438 */
/*<       callfree_unit(0,stdmd5) >*/
		    feq_gen_free_unit_d_(&feq_gen_c_d_0, &stdmd5);
/* SOURCE tracking.for:439 */
/*<       return >*/
		    return 0;
/* SOURCE tracking.for:440 */
/*<       endif >*/
		}
/* SOURCE tracking.for:443 */
/*<       else >*/
	    } else {
/*           We do not have a command. */
/* SOURCE tracking.for:445 */
/*<       if(cmd_in_process/=' ')then >*/
		if (s_cmp(feq_gen_cmd_in_process_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) != 0) {
/*             We are processing a command. */
/* SOURCE tracking.for:447 */
/*<       callupdate_message(line,m,message) >*/
		    feq_gen_update_message_d_(line, &m, message, (ftnlen)192, (ftnlen)
			    256000);
/* SOURCE tracking.for:449 */
/*<       it=index(line,'TABID') >*/
		    it = i_indx(line, const_cast<char*>("TABID"), (ftnlen)192, (ftnlen)5);
/* SOURCE tracking.for:450 */
/*<       if(it>0)then >*/
		    if (it > 0) {
/*               We have a tabid.  Extract it. */
/* SOURCE tracking.for:452 */
/*<       line=line(it+5:) >*/
			feq_gen_i_d_3 = it + 4;
			s_copy(line, line + feq_gen_i_d_3, (ftnlen)192, 192 - feq_gen_i_d_3);
/* SOURCE tracking.for:453 */
/*<       it=index(line,'=') >*/
			it = i_indx(line, const_cast<char*>("="), (ftnlen)192, (ftnlen)1);
/* SOURCE tracking.for:454 */
/*<       if(it>0)then >*/
			if (it > 0) {
/* SOURCE tracking.for:455 */
/*<       callfeq_adjustl(line(it+1:),line) >*/
			    feq_gen_i_d_3 = it;
			    feq_gen_feq_adjustl_d_(line + feq_gen_i_d_3, line, 192 - feq_gen_i_d_3, (
				    ftnlen)192);
/* SOURCE tracking.for:456 */
/*<       it=index(line,' ') >*/
			    it = i_indx(line, const_cast<char*>(" "), (ftnlen)192, (ftnlen)1);
/* SOURCE tracking.for:457 */
/*<       tabid=line(1:it-1) >*/
			    s_copy(tabid, line, (ftnlen)16, it - 1);
/* SOURCE tracking.for:458 */
/*<       class='user' >*/
			    s_copy(feq_gen_class_d_, const_cast<char*>("user"), (ftnlen)8, (ftnlen)4);
/* SOURCE tracking.for:459 */
/*<       if(tabid=='-1')then >*/
			    if (s_cmp(tabid, const_cast<char*>("-1"), (ftnlen)16, (ftnlen)2) == 
				    0) {
/* SOURCE tracking.for:460 */
/*<       tabid=' ' >*/
				s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE tracking.for:461 */
/*<       class=' ' >*/
				s_copy(feq_gen_class_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tracking.for:462 */
/*<       endif >*/
			    }
/* SOURCE tracking.for:463 */
/*<       if(tabid(1:1)=='-')then >*/
			    if (*(unsigned char *)tabid == '-') {
/* SOURCE tracking.for:464 */
/*<       tabid=tabid(2:) >*/
				s_copy(tabid, tabid + 1, (ftnlen)16, (ftnlen)
					15);
/* SOURCE tracking.for:465 */
/*<       endif >*/
			    }
/* SOURCE tracking.for:466 */
/*<       endif >*/
			}
/* SOURCE tracking.for:467 */
/*<       endif >*/
		    }
/* SOURCE tracking.for:468 */
/*<       else >*/
		} else {
/* SOURCE tracking.for:469 */
/*<       write(stdout,*)' Skipping line;',line >*/
		    feq_gen_io_d__41.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__41);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Skipping line;"), (ftnlen)15);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)192);
		    e_wsle();
/* SOURCE tracking.for:470 */
/*<       endif >*/
		}
/* SOURCE tracking.for:471 */
/*<       endif >*/
	    }
/* SOURCE tracking.for:472 */
/*<       endif >*/
	}
/* SOURCE tracking.for:473 */
/*< 98997 continue >*/
L98997:
/* SOURCE tracking.for:473 */
/*<       enddo >*/
	;
    }
/* SOURCE tracking.for:475 */
/*<       end >*/
    return 0;
} /* find_md5_for_fequtl_input__ */

#ifdef __cplusplus
	}
#endif
