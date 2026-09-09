#include "../support/format.hpp"
/* hec2x.f -- translated by f2c (version 20240504).
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

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON nrdzcm_ is declared in common.hpp. */

#define nrdzcm_1 nrdzcm_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON xtadd_ is declared in common.hpp. */

#define xtadd_1 xtadd_

/* COMMON xtaddc_ is declared in common.hpp. */

#define xtaddc_1 xtaddc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_254 = 254;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_200 = 200;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_2 = 2;

/*     Stuff for processing HEC-2 cross sections */



/* SOURCE hec2x.for:7 */
/*<       subroutinehecstb(in,out,stdout,stadir,sfac,stattb,ufac) >*/
/* Subroutine */ int hecstb_(integer *in, integer *out, integer *stdout, real 
	*stadir, real *sfac, real *stattb, real *ufac)
{
    /* Format strings */
    static char fmt_2[] = "(a80)";
    static char fmt_52[] = "(\002OFFS\002,10x,f10.2,10x,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_rsfe(cilist *), e_rsfe(), s_cmp(char *, char *, ftnlen, ftnlen),
	     s_rsfi(icilist *), e_rsfi(), f_rew(alist *), s_wsle(cilist *), 
	    do_lio(integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real tpa, tpl, tpr;
    char chr5[5], line[80];
    real xlch, axis, stchl;
    extern /* Subroutine */ int mkfmt_(real *, integer *, char *, ftnlen);
    real xlobl, stchr, stlob, xlobr, strob, stchlt, stchrt;
    char staout[36];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_2, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Read the HEC-2 input file and establish the sinuosity table */
/*     for the CHANNEL command.  Convert to station form in the */
/*     same way as in the HEC2X command. */
/* SOURCE hec2x.for:16 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE hec2x.for:19 */
/*<       integerin,out,stdout >*/
/* SOURCE hec2x.for:20 */
/*<       realsfac,stadir,stattb,ufac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - Fortran unit number for user input file */
/*     OUT    - Unit number for the output of the sinuosity table */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STADIR - Direction of stationing */
/*     SFAC   - Scale factor for stations */
/*     STATTB - Initial station value for all flow lines */
/*     UFAC   - Factor for conversion of units. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE hec2x.for:32 */
/*<        >*/
/* SOURCE hec2x.for:34 */
/*<       characterchr5*5,line*80,staout*36 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE hec2x.for:37 */
/*<       externalmkfmt >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE hec2x.for:40 */
/*<     2 format(a80) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE hec2x.for:43 */
/*<    52 format('OFFS',10x,f10.2,10x,f10.2) >*/
/* *********************************************************************** */
/*     CREATE THE SKELETON FORMAT */
/* SOURCE hec2x.for:46 */
/*<       staout(1:10)='(/,''STAT'',' >*/
/* L2: */
/* L52: */
    s_copy(staout, const_cast<char*>("(/,'STAT',"), (ftnlen)10, (ftnlen)10);
/* SOURCE hec2x.for:47 */
/*<       staout(16:20)=',10X,' >*/
    s_copy(staout + 15, const_cast<char*>(",10X,"), (ftnlen)5, (ftnlen)5);
/* SOURCE hec2x.for:48 */
/*<       staout(26:30)=',10X,' >*/
    s_copy(staout + 25, const_cast<char*>(",10X,"), (ftnlen)5, (ftnlen)5);
/* SOURCE hec2x.for:49 */
/*<       staout(36:36)=')' >*/
    *(unsigned char *)&staout[35] = ')';
/*     OUTPUT THE COMMAND AND OTHER HEADER INFORMATION TO THE */
/*     OUT FILE */
/* SOURCE hec2x.for:53 */
/*<        >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *out;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A,/,A,/,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("CHANNEL"), (ftnlen)7);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("SINDEF=CUBIC"), (ftnlen)12);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("HEAD      LOB                AXIS                 ROB"), (
	    ftnlen)53);
    e_wsfe();
/*     INITIALIZE THE STATION VALUES */
/* SOURCE hec2x.for:58 */
/*<       stlob=stattb >*/
    stlob = *stattb;
/* SOURCE hec2x.for:59 */
/*<       axis=stattb >*/
    axis = *stattb;
/* SOURCE hec2x.for:60 */
/*<       strob=stattb >*/
    strob = *stattb;
/* SOURCE hec2x.for:63 */
/*<   100 continue >*/
L100:
/* SOURCE hec2x.for:64 */
/*<       read(in,2)line >*/
    feq_gen_io_d__5.ciunit = *in;
    s_rsfe(&feq_gen_io_d__5);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_rsfe();
/* SOURCE hec2x.for:66 */
/*<       if(line(1:2).eq.'X1')then >*/
    if (s_cmp(line, const_cast<char*>("X1"), (ftnlen)2, (ftnlen)2) == 0) {
/*         PROCESS THE X1 CARD */
/* SOURCE hec2x.for:69 */
/*<       read(line,'(16X,5F8.0)',err=991)stchlt,stchrt,xlobl,xlobr,xlch >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(16X,5F8.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stchlt, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stchrt, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&xlobl, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&xlobr, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&xlch, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE hec2x.for:71 */
/*<       if(stadir.ge.0.0)then >*/
	if (*stadir >= (float)0.) {
/* SOURCE hec2x.for:72 */
/*<       stlob=stlob+xlobl >*/
	    stlob += xlobl;
/* SOURCE hec2x.for:73 */
/*<       axis=axis+xlch >*/
	    axis += xlch;
/* SOURCE hec2x.for:74 */
/*<       strob=strob+xlobr >*/
	    strob += xlobr;
/* SOURCE hec2x.for:75 */
/*<       else >*/
	} else {
/* SOURCE hec2x.for:76 */
/*<       stlob=stlob-xlobl >*/
	    stlob -= xlobl;
/* SOURCE hec2x.for:77 */
/*<       axis=axis-xlch >*/
	    axis -= xlch;
/* SOURCE hec2x.for:78 */
/*<       strob=strob-xlobr >*/
	    strob -= xlobr;
/* SOURCE hec2x.for:79 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:81 */
/*<       if(stchlt.ne.0.0)stchl=stchlt >*/
	if (stchlt != (float)0.) {
	    stchl = stchlt;
	}
/* SOURCE hec2x.for:82 */
/*<       if(stchrt.ne.0.0)stchr=stchrt >*/
	if (stchrt != (float)0.) {
	    stchr = stchrt;
	}
/* SOURCE hec2x.for:84 */
/*<       tpl=stlob/sfac >*/
	tpl = static_cast<double>(stlob) / *sfac;
/* SOURCE hec2x.for:85 */
/*<       tpa=axis/sfac >*/
	tpa = static_cast<double>(axis) / *sfac;
/* SOURCE hec2x.for:86 */
/*<       tpr=strob/sfac >*/
	tpr = static_cast<double>(strob) / *sfac;
/* SOURCE hec2x.for:87 */
/*<       callmkfmt(tpa,10,chr5) >*/
	mkfmt_(&tpa, &feq_gen_c_d_10, chr5, (ftnlen)5);
/* SOURCE hec2x.for:92 */
/*<       staout(11:15)=chr5 >*/
	s_copy(staout + 10, chr5, (ftnlen)5, (ftnlen)5);
/* SOURCE hec2x.for:93 */
/*<       staout(21:25)=chr5 >*/
	s_copy(staout + 20, chr5, (ftnlen)5, (ftnlen)5);
/* SOURCE hec2x.for:94 */
/*<       staout(31:35)=chr5 >*/
	s_copy(staout + 30, chr5, (ftnlen)5, (ftnlen)5);
/* SOURCE hec2x.for:96 */
/*<       write(out,staout)tpl,tpa,tpr >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *out;
	feq_gen_ci_d_1.cifmt = feq::format_text(staout, sizeof(staout));
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&tpl, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tpa, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tpr, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE hec2x.for:97 */
/*<       write(out,52)ufac*stchl,ufac*stchr >*/
	feq_gen_io_d__18.ciunit = *out;
	s_wsfe(&feq_gen_io_d__18);
	feq_gen_r_d_1 = static_cast<double>(*ufac) * stchl;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(*ufac) * stchr;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE hec2x.for:98 */
/*<       goto100 >*/
	goto L100;
/* SOURCE hec2x.for:100 */
/*<       elseif(line(1:7).eq.'ENDFILE'.or.line(1:2).eq.'ER')then >*/
    } else if (s_cmp(line, const_cast<char*>("ENDFILE"), (ftnlen)7, (ftnlen)7) == 0 || s_cmp(
	    line, const_cast<char*>("ER"), (ftnlen)2, (ftnlen)2) == 0) {
/*         END OF THE INPUT FILE.  END THE SINUOSITY TABLE */
/* SOURCE hec2x.for:102 */
/*<       write(out,'(A)')'END' >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *out;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("END"), (ftnlen)3);
	e_wsfe();
/*         REWIND THE INPUT FILE */
/* SOURCE hec2x.for:105 */
/*<       rewind(in) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *in;
	f_rew(&feq_gen_al_d_1);
/* SOURCE hec2x.for:106 */
/*<       return >*/
	return 0;
/* SOURCE hec2x.for:107 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:108 */
/*<       goto100 >*/
    goto L100;
/* SOURCE hec2x.for:110 */
/*<   991 continue >*/
L991:
/* SOURCE hec2x.for:111 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__19.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__19);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE hec2x.for:112 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__20.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__20);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE hec2x.for:113 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:115 */
/*<       end >*/
    return 0;
} /* hecstb_ */




/* SOURCE hec2x.for:119 */
/*<        >*/
/* Subroutine */ int inhecx_(integer *stdin, integer *stdout, char *savopt, 
	char *outopt, char *betopt, char *monflg, integer *eflag, char *mode, 
	integer *begtab, integer *tabinc, real *begsta, real *stadir, real *
	sfac, char *conflg, char *zone, char *hgrid, char *vdatum, char *
	unitsys, char *basis, doublereal *easting, doublereal *northing, 
	ftnlen savopt_len, ftnlen outopt_len, ftnlen betopt_len, ftnlen 
	monflg_len, ftnlen mode_len, ftnlen conflg_len, ftnlen zone_len, 
	ftnlen hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, ftnlen 
	basis_len)
{
    /* Format strings */
    static char fmt_1[] = "(a4,1x,a8,1x,a8)";
    static char fmt_2[] = "(6x,1x,a64)";
    static char fmt_3[] = "(7x,1x,a64)";
    static char fmt_4[] = "(8x,a72)";
    static char fmt_5[] = "(8x,2i5)";
    static char fmt_6[] = "(8x,f10.0,f5.0)";
    static char fmt_7[] = "(a4,1x,f10.0)";
    static char fmt_51[] = "(\002 \002,a4,\002=\002,a8,1x,a8)";
    static char fmt_52[] = "(\002 \002,\002HEC2X INPUT FILE NAME:\002,a64)";
    static char fmt_53[] = "(\002 \002,\002FEQX OUTPUT FILE NAME:\002,a64)";
    static char fmt_54[] = "(\002 \002,\002OPTIONS:\002,a71)";
    static char fmt_55[] = "(\002 BEGINNING TABLE NUMBER=\002,i5,\002 TABLE \
NUMBER INCREMENT=\002,i5)";
    static char fmt_56[] = "(\002 BEGINNING STATION=\002,f10.2,\002 STATION \
DIRECTION=\002,f5.0)";
    static char fmt_57[] = "(\002 STATIONING DIVISOR TO CONVERT FEET TO DESI\
RED\002,\002 UNIT=\002,f10.2)";
    static char fmt_66[] = "(\002 Selection of beta option \"NEWBETA\" impli\
es checking for\002,\002 monotonicity.\002)";
    static char fmt_90[] = "(\002 *ERR:646* \002,a8,\002 is invalid mode for\
 HEC2X command.\002)";
    static char fmt_92[] = "(\002 *WRN:561 NO OUTPUT FILE NAME FOR MODE=INDI\
RECT.\002,\002  USING NAME:INDIRECT\002)";
    static char fmt_94[] = "(\002 *WRN:515 NO OUTPUT FILE NAME FOR MODE=CHAN\
NEL.\002,\002  USING NAME:CHANNEL\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[8];
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_inqu(inlist *), f_open(
	    olist *), s_wsle(cilist *), do_lio(integer *, integer *, char *, 
	    ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char cin[72], line[80], char4[4];
    logical there;
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen);
    char feq_gen_infile_d_[64];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     feq_gen_maybe_add_home_d_(char *, ftnlen);
    char outfil[64];
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int setopt_(integer *, char *, char *, char *, 
	    char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), 
	    feq_gen_get_lctn_items_d_(integer *, integer *, integer *), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__24 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__26 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__37 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input controlling information for HEC2X processing */
/* SOURCE hec2x.for:129 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE hec2x.for:132 */
/*<       integerbegtab,eflag,stdin,stdout,tabinc >*/
/* SOURCE hec2x.for:133 */
/*<       realbegsta,sfac,stadir >*/
/* SOURCE hec2x.for:134 */
/*<       real*8easting,northing >*/
/* SOURCE hec2x.for:135 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     SAVOPT - Function table saving option */
/*     OUTOPT - Output option for the table file for cross section function */
/*               tables */
/*     BETOPT - Option for computing flux coefficients and critical flow */
/*     MONFLG - Monotonicity flag value */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     MODE   - Mode of processing cross section boundary specification: */
/*               MODE=1: fixed format.  MODE=2: list format. */
/*     BEGTAB - beginning cross section table number */
/*     TABINC - Increment for generating table numbers */
/*     BEGSTA - Beginning station */
/*     STADIR - Direction of stationing */
/*     SFAC   - Scale factor for stations */
/*     CONFLG - conversion flag for units of measure */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE hec2x.for:157 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/* INCLUDE hec2x.for:158 */
/*     These I/O units will NOT have the number implied by their name. */
/*     The number will be assigned in FEQ/FEQUTL and will not be the same */
/*     as the old historic standard numbers. */
/*     This common block is retained in order to make transition to */
/*     internal assignment of I/O unit numbers easier. */
/* SOURCE stdun.cmn:7 */
/*<       integerstd5,std6,std7,std10,std48,std49,std50 >*/
/* SOURCE stdun.cmn:9 */
/*<       common/stdun_com/std5,std6,std7,std10,std48,std49,std50 >*/
/* SOURCE stdun.cmn:11 */
/*<       save/stdun_com/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE hec2x.for:161 */
/*<       characterchar4*4,cin*72,infile*64,line*80,outfil*64 >*/
/* SOURCE hec2x.for:162 */
/*<       logicalthere >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE hec2x.for:165 */
/*<       charactergettok*8 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE hec2x.for:168 */
/*<       externalgettok,inline,setopt,os_file_style >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE hec2x.for:171 */
/*<     1 format(a4,1x,a8,1x,a8) >*/
/* SOURCE hec2x.for:172 */
/*<     2 format(6x,1x,a64) >*/
/* SOURCE hec2x.for:173 */
/*<     3 format(7x,1x,a64) >*/
/* SOURCE hec2x.for:174 */
/*<     4 format(8x,a72) >*/
/* SOURCE hec2x.for:175 */
/*<     5 format(8x,2i5) >*/
/* SOURCE hec2x.for:176 */
/*<     6 format(8x,f10.0,f5.0) >*/
/* SOURCE hec2x.for:177 */
/*<     7 format(a4,1x,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE hec2x.for:180 */
/*<    51 format(' ',a4,'=',a8,1x,a8) >*/
/* SOURCE hec2x.for:181 */
/*<    52 format(' ','HEC2X INPUT FILE NAME:',a64) >*/
/* SOURCE hec2x.for:182 */
/*<    53 format(' ','FEQX OUTPUT FILE NAME:',a64) >*/
/* SOURCE hec2x.for:183 */
/*<    54 format(' ','OPTIONS:',a71) >*/
/* SOURCE hec2x.for:184 */
/*<    55  >*/
/* SOURCE hec2x.for:186 */
/*<    56 format(' BEGINNING STATION=',f10.2,' STATION DIRECTION=',f5.0) >*/
/* SOURCE hec2x.for:187 */
/*<    57  >*/
/* SOURCE hec2x.for:189 */
/*<    66  >*/
/* SOURCE hec2x.for:191 */
/*<    90 format(' *ERR:646* ',a8,' is invalid mode for HEC2X command.') >*/
/* SOURCE hec2x.for:192 */
/*<    92  >*/
/* SOURCE hec2x.for:194 */
/*<    94  >*/
/* *********************************************************************** */
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE hec2x.for:201 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L6: */
/* L7: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
/* L56: */
/* L57: */
/* L66: */
/* L90: */
/* L92: */
/* L94: */
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE hec2x.for:203 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, easting, northing, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE hec2x.for:208 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:211 */
/*<       read(line,1,err=991)char4,mode,conflg >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, mode, (ftnlen)8);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, conflg, (ftnlen)8);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:212 */
/*<       write(stdout,51)char4,mode,conflg >*/
    feq_gen_io_d__23.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__23);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, mode, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, conflg, (ftnlen)8);
    e_wsfe();
/*     STRIP LEADING BLANKS */
/* SOURCE hec2x.for:215 */
/*<       mode=gettok(mode) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)8, mode, (ftnlen)8);
    s_copy(mode, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/*     CHECK FOR VALID MODES */
/* SOURCE hec2x.for:218 */
/*<        >*/
    if (s_cmp(mode, const_cast<char*>("DIRECT"), (ftnlen)8, (ftnlen)6) != 0 && s_cmp(mode, const_cast<char*>("IND\
IRECT"), (ftnlen)8, (ftnlen)8) != 0 && s_cmp(mode, const_cast<char*>("direct"), (ftnlen)8, (
	    ftnlen)6) != 0 && s_cmp(mode, const_cast<char*>("indirect"), (ftnlen)8, (ftnlen)8) !=
	     0 && s_cmp(mode, const_cast<char*>("CHANNEL"), (ftnlen)8, (ftnlen)7) != 0 && s_cmp(
	    mode, const_cast<char*>("channel"), (ftnlen)8, (ftnlen)7) != 0) {
/* SOURCE hec2x.for:221 */
/*<       write(stdout,90)mode >*/
	feq_gen_io_d__24.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__24);
	do_fio(&feq_gen_c_d_1, mode, (ftnlen)8);
	e_wsfe();
/* SOURCE hec2x.for:222 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE hec2x.for:223 */
/*<       return >*/
	return 0;
/* SOURCE hec2x.for:224 */
/*<       endif >*/
    }
/*     INPUT THE INPUT FILE NAME FOR THE HEC2 DATA */
/* SOURCE hec2x.for:227 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:230 */
/*<       read(line,2,err=991)infile >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_infile_d_, (ftnlen)64);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:231 */
/*<       callmaybe_add_home(infile) >*/
    feq_gen_maybe_add_home_d_(feq_gen_infile_d_, (ftnlen)64);
/* SOURCE hec2x.for:234 */
/*<       callos_file_style(infile) >*/
    feq_gen_os_file_style_d_(feq_gen_infile_d_, (ftnlen)64);
/* SOURCE hec2x.for:236 */
/*<       write(stdout,52)infile >*/
    feq_gen_io_d__26.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__26);
    do_fio(&feq_gen_c_d_1, feq_gen_infile_d_, (ftnlen)64);
    e_wsfe();
/*     CHECK IF THE FILE EXISTS */
/* SOURCE hec2x.for:239 */
/*<       inquire(file=infile,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 64;
    feq_gen_ioin_d_1.infile = feq_gen_infile_d_;
    feq_gen_ioin_d_1.inex = &there;
    feq_gen_ioin_d_1.inopen = 0;
    feq_gen_ioin_d_1.innum = 0;
    feq_gen_ioin_d_1.innamed = 0;
    feq_gen_ioin_d_1.inname = 0;
    feq_gen_ioin_d_1.inacc = 0;
    feq_gen_ioin_d_1.inseq = 0;
    feq_gen_ioin_d_1.indir = 0;
    feq_gen_ioin_d_1.infmt = 0;
    feq_gen_ioin_d_1.inform = 0;
    feq_gen_ioin_d_1.inunf = 0;
    feq_gen_ioin_d_1.inrecl = 0;
    feq_gen_ioin_d_1.innrec = 0;
    feq_gen_ioin_d_1.inblank = 0;
    f_inqu(&feq_gen_ioin_d_1);
/* SOURCE hec2x.for:240 */
/*<       if(there)then >*/
    if (there) {
/* SOURCE hec2x.for:241 */
/*<       open(unit=std48,file=infile,status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std48;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = feq_gen_infile_d_;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE hec2x.for:242 */
/*<       else >*/
    } else {
/* SOURCE hec2x.for:243 */
/*<       write(stdout,*)' FILE NAMED:',infile,' NOT FOUND.' >*/
	feq_gen_io_d__28.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__28);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FILE NAMED:"), (ftnlen)12);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_infile_d_, (ftnlen)64);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT FOUND."), (ftnlen)11);
	e_wsle();
/* SOURCE hec2x.for:244 */
/*<       write(stdout,*)' CHECK SPELLING OF HEC2X INPUT FILE.' >*/
	feq_gen_io_d__29.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__29);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK SPELLING OF HEC2X INPUT FILE."), (ftnlen)
		36);
	e_wsle();
/* SOURCE hec2x.for:245 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:246 */
/*<       endif >*/
    }
/*     INPUT THE OUTPUT FILE NAME. USED ONLY IF MODE IS INDIRECT BUT INPUT */
/*     IN ANY CASE. */
/* SOURCE hec2x.for:250 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:253 */
/*<       read(line,3,err=991)outfil >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_3;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, outfil, (ftnlen)64);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:254 */
/*<       callmaybe_add_home(outfil) >*/
    feq_gen_maybe_add_home_d_(outfil, (ftnlen)64);
/* SOURCE hec2x.for:256 */
/*<       callos_file_style(outfil) >*/
    feq_gen_os_file_style_d_(outfil, (ftnlen)64);
/* SOURCE hec2x.for:259 */
/*<       write(stdout,53)outfil >*/
    feq_gen_io_d__31.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__31);
    do_fio(&feq_gen_c_d_1, outfil, (ftnlen)64);
    e_wsfe();
/* SOURCE hec2x.for:261 */
/*<       if(mode.eq.'INDIRECT'.or.mode.eq.'indirect')then >*/
    if (s_cmp(mode, const_cast<char*>("INDIRECT"), (ftnlen)8, (ftnlen)8) == 0 || s_cmp(mode, 
	    const_cast<char*>("indirect"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE hec2x.for:262 */
/*<       if(outfil.eq.' ')then >*/
	if (s_cmp(outfil, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1) == 0) {
/* SOURCE hec2x.for:263 */
/*<       write(stdout,92) >*/
	    feq_gen_io_d__32.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__32);
	    e_wsfe();
/* SOURCE hec2x.for:264 */
/*<       outfil='INDIRECT' >*/
	    s_copy(outfil, const_cast<char*>("INDIRECT"), (ftnlen)64, (ftnlen)8);
/* SOURCE hec2x.for:265 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:266 */
/*<       open(unit=std49,file=outfil,status='UNKNOWN') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std49;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = outfil;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE hec2x.for:267 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:269 */
/*<       if(mode.eq.'CHANNEL'.or.mode.eq.'channel')then >*/
    if (s_cmp(mode, const_cast<char*>("CHANNEL"), (ftnlen)8, (ftnlen)7) == 0 || s_cmp(mode, 
	    const_cast<char*>("channel"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE hec2x.for:270 */
/*<       if(outfil.eq.' ')then >*/
	if (s_cmp(outfil, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1) == 0) {
/* SOURCE hec2x.for:271 */
/*<       write(stdout,94) >*/
	    feq_gen_io_d__33.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__33);
	    e_wsfe();
/* SOURCE hec2x.for:272 */
/*<       outfil='CHANNEL' >*/
	    s_copy(outfil, const_cast<char*>("CHANNEL"), (ftnlen)64, (ftnlen)7);
/* SOURCE hec2x.for:273 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:274 */
/*<       open(unit=std49,file=outfil,status='UNKNOWN') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std49;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = outfil;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE hec2x.for:275 */
/*<       endif >*/
    }
/*     GET THE FEQUTL OPTIONS FOR PROCESSING THE CROSS SECTIONS */
/* SOURCE hec2x.for:278 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:281 */
/*<       read(line,4,err=991)cin >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, cin, (ftnlen)72);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:282 */
/*<       write(stdout,54)cin >*/
    feq_gen_io_d__35.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__35);
    do_fio(&feq_gen_c_d_1, cin, (ftnlen)72);
    e_wsfe();
/*     SET THE OPTION FLAGS */
/* SOURCE hec2x.for:286 */
/*<       callsetopt(stdout,cin,savopt,outopt,monflg,betopt) >*/
    setopt_(stdout, cin, savopt, outopt, monflg, betopt, (ftnlen)72, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE hec2x.for:289 */
/*<       if(betopt(1:7).eq.'NEWBETA')then >*/
    if (s_cmp(betopt, const_cast<char*>("NEWBETA"), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE hec2x.for:290 */
/*<       monflg='MONOTONE' >*/
	s_copy(monflg, const_cast<char*>("MONOTONE"), (ftnlen)8, (ftnlen)8);
/* SOURCE hec2x.for:291 */
/*<       write(stdout,66) >*/
	feq_gen_io_d__36.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__36);
	e_wsfe();
/* SOURCE hec2x.for:292 */
/*<       endif >*/
    }
/*     INPUT THE BEGINING TABLE NUMBER AND THE TABLE INCREMENT */
/* SOURCE hec2x.for:296 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:299 */
/*<       read(line,5,err=991)begtab,tabinc >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_5;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*begtab), (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*tabinc), (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:300 */
/*<       write(stdout,55)begtab,tabinc >*/
    feq_gen_io_d__37.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__37);
    do_fio(&feq_gen_c_d_1, (char *)&(*begtab), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&(*tabinc), (ftnlen)sizeof(integer));
    e_wsfe();
/*     INPUT THE BEGINNING STATION AND THE STATIONING DIRECTION */
/* SOURCE hec2x.for:304 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:307 */
/*<       read(line,6,err=991)begsta,stadir >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*begsta), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*stadir), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:308 */
/*<       write(stdout,56)begsta,stadir >*/
    feq_gen_io_d__38.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__38);
    do_fio(&feq_gen_c_d_1, (char *)&(*begsta), (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*stadir), (ftnlen)sizeof(real));
    e_wsfe();
/*     INPUT THE STATIONING FACTOR TO CONVERT FEET TO THE DESIRED UNITS */
/*     BY DIVISION */
/* SOURCE hec2x.for:314 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:317 */
/*<       read(line,7,err=991)char4,sfac >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_7;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*sfac), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:318 */
/*<       if(sfac.eq.0.0)sfac=1.0 >*/
    if (*sfac == (float)0.) {
	*sfac = (float)1.;
    }
/* SOURCE hec2x.for:319 */
/*<       write(stdout,57)sfac >*/
    feq_gen_io_d__39.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__39);
    do_fio(&feq_gen_c_d_1, (char *)&(*sfac), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE hec2x.for:321 */
/*<       return >*/
    return 0;
/* SOURCE hec2x.for:323 */
/*<   991 continue >*/
L991:
/* SOURCE hec2x.for:324 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__40.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE hec2x.for:325 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__41.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__41);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE hec2x.for:326 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:327 */
/*<       end >*/
    return 0;
} /* inhecx_ */




/* SOURCE hec2x.for:331 */
/*<        >*/
/* Subroutine */ int insfpx_(integer *stdin, integer *stdout, char *sfpnam, 
	integer *sfpn, char *savopt, char *outopt, char *betopt, char *monflg,
	 integer *eflag, char *mode, integer *begtab, integer *tabinc, real *
	begsta, real *stadir, real *sfac, char *zone, char *hgrid, char *
	vdatum, char *unitsys, char *basis, doublereal *easting, doublereal *
	northing, ftnlen sfpnam_len, ftnlen savopt_len, ftnlen outopt_len, 
	ftnlen betopt_len, ftnlen monflg_len, ftnlen mode_len, ftnlen 
	zone_len, ftnlen hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, 
	ftnlen basis_len)
{
    /* Format strings */
    static char fmt_1[] = "(a4,1x,a8)";
    static char fmt_2[] = "(6x,1x,a64)";
    static char fmt_3[] = "(7x,1x,a64)";
    static char fmt_4[] = "(8x,a72)";
    static char fmt_5[] = "(8x,2i5)";
    static char fmt_6[] = "(8x,f10.0,f5.0)";
    static char fmt_7[] = "(a4,1x,f10.0)";
    static char fmt_51[] = "(\002 \002,a4,\002=\002,a8)";
    static char fmt_52[] = "(\002 \002,a,\002 INPUT FILE NAME:\002,a)";
    static char fmt_53[] = "(\002 \002,\002FEQX OUTPUT FILE NAME:\002,a)";
    static char fmt_54[] = "(\002 \002,\002OPTIONS:\002,a)";
    static char fmt_55[] = "(\002 BEGINNING TABLE NUMBER=\002,i5,\002 TABLE \
NUMBER INCREMENT=\002,i5)";
    static char fmt_56[] = "(\002 BEGINNING STATION=\002,f10.2,\002 STATION \
DIRECTION=\002,f5.0)";
    static char fmt_57[] = "(\002 STATIONING DIVISOR TO CONVERT FEET TO DESI\
RED\002,\002 UNIT=\002,f10.2)";
    static char fmt_66[] = "(\002 Selection of beta option \"NEWBETA\" impli\
es checking for\002,\002 monotonicity.\002)";
    static char fmt_90[] = "(\002 *ERR:646* \002,a8,\002 is invalid mode f\
or \002,a,\002 command.\002)";
    static char fmt_92[] = "(\002 *WRN:561 No output file name for MODE=INDI\
RECT.\002,\002  using name:INDIRECT\002)";
    static char fmt_94[] = "(\002 *WRN:515 No output file name for MODE=CHAN\
NEL.\002,\002  using name:CHANNEL\002)";
    static char fmt_96[] = "(/,\002 File named:\002,a,\002 not found.  check\
 spelling of\002,\002 file name.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[8];
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_inqu(inlist *), f_open(
	    olist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    char cin[72], line[80], char4[4];
    logical there;
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen);
    char feq_gen_infile_d_[64];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     feq_gen_maybe_add_home_d_(char *, ftnlen);
    char outfil[64];
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int setopt_(integer *, char *, char *, char *, 
	    char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), 
	    feq_gen_get_lctn_items_d_(integer *, integer *, integer *), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__55 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__56 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input controlling information for processing cross section */
/*     descriptions from existing steady-flow profile programs. */
/* SOURCE hec2x.for:342 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE hec2x.for:345 */
/*<       integerbegtab,eflag,sfpn,stdin,stdout,tabinc >*/
/* SOURCE hec2x.for:346 */
/*<       realbegsta,sfac,stadir >*/
/* SOURCE hec2x.for:347 */
/*<       real*8easting,northing >*/
/* SOURCE hec2x.for:348 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     SFPNAM - steady-flow program name */
/*     SFPN   - number of characters in the steady-flow program name */
/*     SAVOPT - Function table saving option */
/*     OUTOPT - Output option for the table file for cross section function */
/*               tables */
/*     MONFLG - Monotonicity flag value */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     MODE   - mode of process cross sections: DIRECT or INDIRECT */
/*     BEGTAB - beginning cross section table number */
/*     TABINC - Increment for generating table numbers */
/*     BEGSTA - Beginning station */
/*     STADIR - Direction of stationing */
/*     SFAC   - Scale factor for stations */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE hec2x.for:370 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/* INCLUDE hec2x.for:371 */
/*     These I/O units will NOT have the number implied by their name. */
/*     The number will be assigned in FEQ/FEQUTL and will not be the same */
/*     as the old historic standard numbers. */
/*     This common block is retained in order to make transition to */
/*     internal assignment of I/O unit numbers easier. */
/* SOURCE stdun.cmn:7 */
/*<       integerstd5,std6,std7,std10,std48,std49,std50 >*/
/* SOURCE stdun.cmn:9 */
/*<       common/stdun_com/std5,std6,std7,std10,std48,std49,std50 >*/
/* SOURCE stdun.cmn:11 */
/*<       save/stdun_com/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE hec2x.for:374 */
/*<       characterchar4*4,cin*72,infile*64,line*80,outfil*64 >*/
/* SOURCE hec2x.for:375 */
/*<       logicalthere >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE hec2x.for:378 */
/*<       charactergettok*8 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE hec2x.for:381 */
/*<       externalgettok,inline,setopt,os_file_style >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE hec2x.for:384 */
/*<     1 format(a4,1x,a8) >*/
/* SOURCE hec2x.for:385 */
/*<     2 format(6x,1x,a64) >*/
/* SOURCE hec2x.for:386 */
/*<     3 format(7x,1x,a64) >*/
/* SOURCE hec2x.for:387 */
/*<     4 format(8x,a72) >*/
/* SOURCE hec2x.for:388 */
/*<     5 format(8x,2i5) >*/
/* SOURCE hec2x.for:389 */
/*<     6 format(8x,f10.0,f5.0) >*/
/* SOURCE hec2x.for:390 */
/*<     7 format(a4,1x,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE hec2x.for:393 */
/*<    51 format(' ',a4,'=',a8) >*/
/* SOURCE hec2x.for:394 */
/*<    52 format(' ',a,' INPUT FILE NAME:',a) >*/
/* SOURCE hec2x.for:395 */
/*<    53 format(' ','FEQX OUTPUT FILE NAME:',a) >*/
/* SOURCE hec2x.for:396 */
/*<    54 format(' ','OPTIONS:',a) >*/
/* SOURCE hec2x.for:397 */
/*<    55  >*/
/* SOURCE hec2x.for:399 */
/*<    56 format(' BEGINNING STATION=',f10.2,' STATION DIRECTION=',f5.0) >*/
/* SOURCE hec2x.for:400 */
/*<    57  >*/
/* SOURCE hec2x.for:402 */
/*<    66  >*/
/* SOURCE hec2x.for:404 */
/*<    90 format(' *ERR:646* ',a8,' is invalid mode for ',a,' command.') >*/
/* SOURCE hec2x.for:405 */
/*<    92  >*/
/* SOURCE hec2x.for:407 */
/*<    94  >*/
/* SOURCE hec2x.for:409 */
/*<    96  >*/
/* *********************************************************************** */
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE hec2x.for:415 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L6: */
/* L7: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
/* L56: */
/* L57: */
/* L66: */
/* L90: */
/* L92: */
/* L94: */
/* L96: */
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE hec2x.for:417 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, easting, northing, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE hec2x.for:421 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:424 */
/*<       read(line,1,err=991)char4,mode >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, mode, (ftnlen)8);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:425 */
/*<       write(stdout,51)char4,mode >*/
    feq_gen_io_d__44.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__44);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, mode, (ftnlen)8);
    e_wsfe();
/*     STRIP LEADING BLANKS */
/* SOURCE hec2x.for:428 */
/*<       mode=gettok(mode) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)8, mode, (ftnlen)8);
    s_copy(mode, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/*     CHECK FOR VALID MODES */
/* SOURCE hec2x.for:431 */
/*<        >*/
    if (s_cmp(mode, const_cast<char*>("DIRECT"), (ftnlen)8, (ftnlen)6) != 0 && s_cmp(mode, const_cast<char*>("IND\
IRECT"), (ftnlen)8, (ftnlen)8) != 0 && s_cmp(mode, const_cast<char*>("direct"), (ftnlen)8, (
	    ftnlen)6) != 0 && s_cmp(mode, const_cast<char*>("indirect"), (ftnlen)8, (ftnlen)8) !=
	     0 && s_cmp(mode, const_cast<char*>("CHANNEL"), (ftnlen)8, (ftnlen)7) != 0 && s_cmp(
	    mode, const_cast<char*>("channel"), (ftnlen)8, (ftnlen)7) != 0) {
/* SOURCE hec2x.for:434 */
/*<       write(stdout,90)sfpnam(1:sfpn),mode >*/
	feq_gen_io_d__45.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__45);
	do_fio(&feq_gen_c_d_1, sfpnam, (*sfpn));
	do_fio(&feq_gen_c_d_1, mode, (ftnlen)8);
	e_wsfe();
/* SOURCE hec2x.for:435 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE hec2x.for:436 */
/*<       return >*/
	return 0;
/* SOURCE hec2x.for:437 */
/*<       endif >*/
    }
/*     INPUT THE INPUT FILE NAME FOR THE SFP INPUT DATA STREAM */
/* SOURCE hec2x.for:440 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:443 */
/*<       read(line,2,err=991)infile >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_infile_d_, (ftnlen)64);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:444 */
/*<       callmaybe_add_home(infile) >*/
    feq_gen_maybe_add_home_d_(feq_gen_infile_d_, (ftnlen)64);
/* SOURCE hec2x.for:446 */
/*<       callos_file_style(infile) >*/
    feq_gen_os_file_style_d_(feq_gen_infile_d_, (ftnlen)64);
/* SOURCE hec2x.for:448 */
/*<       write(stdout,52)sfpnam(1:sfpn),infile >*/
    feq_gen_io_d__47.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__47);
    do_fio(&feq_gen_c_d_1, sfpnam, (*sfpn));
    do_fio(&feq_gen_c_d_1, feq_gen_infile_d_, (ftnlen)64);
    e_wsfe();
/*     CHECK IF THE FILE EXISTS */
/* SOURCE hec2x.for:451 */
/*<       inquire(file=infile,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 64;
    feq_gen_ioin_d_1.infile = feq_gen_infile_d_;
    feq_gen_ioin_d_1.inex = &there;
    feq_gen_ioin_d_1.inopen = 0;
    feq_gen_ioin_d_1.innum = 0;
    feq_gen_ioin_d_1.innamed = 0;
    feq_gen_ioin_d_1.inname = 0;
    feq_gen_ioin_d_1.inacc = 0;
    feq_gen_ioin_d_1.inseq = 0;
    feq_gen_ioin_d_1.indir = 0;
    feq_gen_ioin_d_1.infmt = 0;
    feq_gen_ioin_d_1.inform = 0;
    feq_gen_ioin_d_1.inunf = 0;
    feq_gen_ioin_d_1.inrecl = 0;
    feq_gen_ioin_d_1.innrec = 0;
    feq_gen_ioin_d_1.inblank = 0;
    f_inqu(&feq_gen_ioin_d_1);
/* SOURCE hec2x.for:452 */
/*<       if(there)then >*/
    if (there) {
/* SOURCE hec2x.for:453 */
/*<       open(unit=std48,file=infile,status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std48;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = feq_gen_infile_d_;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE hec2x.for:454 */
/*<       else >*/
    } else {
/* SOURCE hec2x.for:455 */
/*<       write(stdout,96)infile >*/
	feq_gen_io_d__49.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__49);
	do_fio(&feq_gen_c_d_1, feq_gen_infile_d_, (ftnlen)64);
	e_wsfe();
/* SOURCE hec2x.for:456 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:457 */
/*<       endif >*/
    }
/*     INPUT THE OUTPUT FILE NAME. USED ONLY IF MODE IS INDIRECT BUT INPUT */
/*     IN ANY CASE. */
/* SOURCE hec2x.for:461 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:464 */
/*<       read(line,3,err=991)outfil >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_3;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, outfil, (ftnlen)64);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:465 */
/*<       callmaybe_add_home(outfil) >*/
    feq_gen_maybe_add_home_d_(outfil, (ftnlen)64);
/* SOURCE hec2x.for:467 */
/*<       callos_file_style(outfil) >*/
    feq_gen_os_file_style_d_(outfil, (ftnlen)64);
/* SOURCE hec2x.for:469 */
/*<       write(stdout,53)outfil >*/
    feq_gen_io_d__51.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__51);
    do_fio(&feq_gen_c_d_1, outfil, (ftnlen)64);
    e_wsfe();
/* SOURCE hec2x.for:471 */
/*<       if(mode.eq.'INDIRECT'.or.mode.eq.'indirect')then >*/
    if (s_cmp(mode, const_cast<char*>("INDIRECT"), (ftnlen)8, (ftnlen)8) == 0 || s_cmp(mode, 
	    const_cast<char*>("indirect"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE hec2x.for:472 */
/*<       if(outfil.eq.' ')then >*/
	if (s_cmp(outfil, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1) == 0) {
/* SOURCE hec2x.for:473 */
/*<       write(stdout,92) >*/
	    feq_gen_io_d__52.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__52);
	    e_wsfe();
/* SOURCE hec2x.for:474 */
/*<       outfil='INDIRECT' >*/
	    s_copy(outfil, const_cast<char*>("INDIRECT"), (ftnlen)64, (ftnlen)8);
/* SOURCE hec2x.for:475 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:476 */
/*<       open(unit=std49,file=outfil,status='UNKNOWN') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std49;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = outfil;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE hec2x.for:477 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:479 */
/*<       if(mode.eq.'CHANNEL'.or.mode.eq.'channel')then >*/
    if (s_cmp(mode, const_cast<char*>("CHANNEL"), (ftnlen)8, (ftnlen)7) == 0 || s_cmp(mode, 
	    const_cast<char*>("channel"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE hec2x.for:480 */
/*<       if(outfil.eq.' ')then >*/
	if (s_cmp(outfil, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1) == 0) {
/* SOURCE hec2x.for:481 */
/*<       write(stdout,94) >*/
	    feq_gen_io_d__53.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__53);
	    e_wsfe();
/* SOURCE hec2x.for:482 */
/*<       outfil='CHANNEL' >*/
	    s_copy(outfil, const_cast<char*>("CHANNEL"), (ftnlen)64, (ftnlen)7);
/* SOURCE hec2x.for:483 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:484 */
/*<       if(sfpnam(1:sfpn).eq.'WSPRO')then >*/
	if (s_cmp(sfpnam, const_cast<char*>("WSPRO"), (*sfpn), (ftnlen)5) == 0) {
/*         Open a scratch file attached to STD50 */
/* SOURCE hec2x.for:486 */
/*<       open(unit=std50,status='SCRATCH') >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std50;
	    feq_gen_o_d_1.ofnm = 0;
	    feq_gen_o_d_1.orl = 0;
	    feq_gen_o_d_1.osta = const_cast<char*>("SCRATCH");
	    feq_gen_o_d_1.oacc = 0;
	    feq_gen_o_d_1.ofm = 0;
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE hec2x.for:487 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:488 */
/*<       open(unit=std49,file=outfil,status='UNKNOWN') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std49;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = outfil;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE hec2x.for:489 */
/*<       endif >*/
    }
/*     GET THE FEQUTL OPTIONS FOR PROCESSING THE CROSS SECTIONS */
/* SOURCE hec2x.for:492 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:495 */
/*<       read(line,4,err=991)cin >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, cin, (ftnlen)72);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:496 */
/*<       write(stdout,54)cin >*/
    feq_gen_io_d__55.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__55);
    do_fio(&feq_gen_c_d_1, cin, (ftnlen)72);
    e_wsfe();
/*     SET THE OPTION FLAGS */
/* SOURCE hec2x.for:500 */
/*<       callsetopt(stdout,cin,savopt,outopt,monflg,betopt) >*/
    setopt_(stdout, cin, savopt, outopt, monflg, betopt, (ftnlen)72, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE hec2x.for:503 */
/*<       if(betopt(1:7).eq.'NEWBETA')then >*/
    if (s_cmp(betopt, const_cast<char*>("NEWBETA"), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE hec2x.for:504 */
/*<       monflg='MONOTONE' >*/
	s_copy(monflg, const_cast<char*>("MONOTONE"), (ftnlen)8, (ftnlen)8);
/* SOURCE hec2x.for:505 */
/*<       write(stdout,66) >*/
	feq_gen_io_d__56.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__56);
	e_wsfe();
/* SOURCE hec2x.for:506 */
/*<       endif >*/
    }
/*     INPUT THE BEGINING TABLE NUMBER AND THE TABLE INCREMENT */
/* SOURCE hec2x.for:510 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:513 */
/*<       read(line,5,err=991)begtab,tabinc >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_5;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*begtab), (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*tabinc), (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:514 */
/*<       write(stdout,55)begtab,tabinc >*/
    feq_gen_io_d__57.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__57);
    do_fio(&feq_gen_c_d_1, (char *)&(*begtab), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&(*tabinc), (ftnlen)sizeof(integer));
    e_wsfe();
/*     INPUT THE BEGINNING STATION AND THE STATIONING DIRECTION */
/* SOURCE hec2x.for:518 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:521 */
/*<       read(line,6,err=991)begsta,stadir >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*begsta), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*stadir), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:522 */
/*<       write(stdout,56)begsta,stadir >*/
    feq_gen_io_d__58.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__58);
    do_fio(&feq_gen_c_d_1, (char *)&(*begsta), (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*stadir), (ftnlen)sizeof(real));
    e_wsfe();
/*     INPUT THE STATIONING FACTOR TO CONVERT FEET TO THE DESIRED UNITS */
/*     BY DIVISION */
/* SOURCE hec2x.for:528 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:531 */
/*<       read(line,7,err=991)char4,sfac >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_7;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*sfac), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE hec2x.for:532 */
/*<       if(sfac.eq.0.0)sfac=1.0 >*/
    if (*sfac == (float)0.) {
	*sfac = (float)1.;
    }
/* SOURCE hec2x.for:533 */
/*<       write(stdout,57)sfac >*/
    feq_gen_io_d__59.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__59);
    do_fio(&feq_gen_c_d_1, (char *)&(*sfac), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE hec2x.for:535 */
/*<       return >*/
    return 0;
/* SOURCE hec2x.for:537 */
/*<   991 continue >*/
L991:
/* SOURCE hec2x.for:538 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__60.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__60);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE hec2x.for:539 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__61.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__61);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE hec2x.for:540 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:541 */
/*<       end >*/
    return 0;
} /* insfpx_ */




/* SOURCE hec2x.for:545 */
/*<       subroutinefixnh(stdout,numnh,stn,sizexz,npnt,x,z) >*/
/* Subroutine */ int fixnh_(integer *stdout, integer *numnh, real *feq_storage_stn, 
	integer *sizexz, integer *npnt, real *feq_storage_x, real *feq_gen_feq_storage_z_d_)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:719* Cross section offset non-incre\
asing at\002,\002 offset=\002,f10.2)";
    static char fmt_52[] = "(/,\002 *ERR:720* No space left in cross section\
 boundary\002,\002when adding point for NH card.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, js;
    real xnh, znh;
    integer jadd;
    real diff;
    extern /* Subroutine */ int sort2r_(integer *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__68 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Add coordinate points to the cross section boundary to match */
/*     offsets at which the boundaries for horizontal variation of */
/*     n are given.  Needed for handling HEC-2 input resulting from */
/*     translation from the Kansas City District steady water surface */
/*     profile program. */
/* SOURCE hec2x.for:556 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/*      INCLUDE 'arsize.prm' */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE hec2x.for:562 */
/*<       integernpnt,numnh,sizexz,stdout >*/
/* SOURCE hec2x.for:563 */
/*<       realstn(numnh),x(sizexz),z(sizexz) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NUMNH  - number of n values given */
/*     STN    - offsets for n values */
/*     NPNT   - Number of points on boundary of a cross section */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE hec2x.for:574 */
/*<       integeri,j,jadd,js >*/
/* SOURCE hec2x.for:575 */
/*<       realdiff,xnh,znh >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE hec2x.for:578 */
/*<       externalsort2r >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE hec2x.for:581 */
/*<    50  >*/
/* SOURCE hec2x.for:583 */
/*<    52  >*/
/* *********************************************************************** */
/* SOURCE hec2x.for:586 */
/*<       jadd=npnt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> stn(feq_storage_stn, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* L50: */
/* L52: */
    jadd = *npnt;
/* SOURCE hec2x.for:587 */
/*<       js=2 >*/
    js = 2;
/* SOURCE hec2x.for:588 */
/*<       do200i=1,numnh >*/
    feq_gen_i_d_1 = *numnh;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE hec2x.for:589 */
/*<       xnh=stn(i) >*/
	xnh = stn[feq_gen_i_d_];
/* SOURCE hec2x.for:590 */
/*<       if(xnh.ge.x(npnt))goto110 >*/
	if (xnh >= x[*npnt]) {
	    goto L110;
	}
/* SOURCE hec2x.for:591 */
/*<       do100j=js,npnt >*/
	feq_gen_i_d_2 = *npnt;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
/* SOURCE hec2x.for:592 */
/*<       if(xnh.ge.x(j-1).and.xnh.le.x(j))then >*/
	    if (xnh >= x[j - 1] && xnh <= x[j]) {
/*           In the interval.  Is it at one of the end points? */
/* SOURCE hec2x.for:594 */
/*<       if(xnh.ne.x(j-1).and.xnh.ne.x(j))then >*/
		if (xnh != x[j - 1] && xnh != x[j]) {
/*             Not at the end points.  Add a point to the boundary. */
/* SOURCE hec2x.for:596 */
/*<       diff=x(j)-x(j-1) >*/
		    diff = static_cast<double>(x[j]) - x[j - 1];
/* SOURCE hec2x.for:597 */
/*<       if(diff.le.0.0)then >*/
		    if (diff <= (float)0.) {
/* SOURCE hec2x.for:598 */
/*<       write(stdout,50)x(j) >*/
			feq_gen_io_d__68.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__68);
			do_fio(&feq_gen_c_d_1, (char *)&x[j], (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE hec2x.for:599 */
/*<       stop'Abnormal stop. Errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:600 */
/*<       endif >*/
		    }
/* SOURCE hec2x.for:601 */
/*<       znh=z(j-1)+(xnh-x(j-1))*(z(j)-z(j-1))/diff >*/
		    znh = static_cast<double>(feq_gen_z_d_[j - 1]) + static_cast<double>(static_cast<double>((static_cast<double>(xnh) - x[j - 1])) * (static_cast<double>(feq_gen_z_d_[j]) - feq_gen_z_d_[j - 1]
			    )) / diff;
/* SOURCE hec2x.for:602 */
/*<       jadd=jadd+1 >*/
		    ++jadd;
/* SOURCE hec2x.for:603 */
/*<       if(jadd.gt.sizexz)then >*/
		    if (jadd > *sizexz) {
/* SOURCE hec2x.for:604 */
/*<       write(stdout,52)jadd >*/
			feq_gen_io_d__70.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__70);
			do_fio(&feq_gen_c_d_1, (char *)&jadd, (ftnlen)sizeof(integer));
			e_wsfe();
/* SOURCE hec2x.for:605 */
/*<       stop'Abnormal stop. Errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:606 */
/*<       endif >*/
		    }
/* SOURCE hec2x.for:607 */
/*<       x(jadd)=xnh >*/
		    x[jadd] = xnh;
/* SOURCE hec2x.for:608 */
/*<       z(jadd)=znh >*/
		    feq_gen_z_d_[jadd] = znh;
/* SOURCE hec2x.for:609 */
/*<       js=j >*/
		    js = j;
/* SOURCE hec2x.for:610 */
/*<       goto110 >*/
		    goto L110;
/* SOURCE hec2x.for:611 */
/*<       endif >*/
		}
/* SOURCE hec2x.for:612 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:613 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE hec2x.for:614 */
/*<   110 continue >*/
L110:
/* SOURCE hec2x.for:615 */
/*<   200 continue >*/
/* L200: */
	;
    }
/* SOURCE hec2x.for:616 */
/*<       if(jadd.gt.npnt)then >*/
    if (jadd > *npnt) {
/*       Points were added. */
/* SOURCE hec2x.for:618 */
/*<       npnt=jadd >*/
	*npnt = jadd;
/* SOURCE hec2x.for:619 */
/*<       callsort2r(npnt,x,z) >*/
	sort2r_(npnt, &x[1], &feq_gen_z_d_[1]);
/* SOURCE hec2x.for:622 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:624 */
/*<       return >*/
    return 0;
/* SOURCE hec2x.for:625 */
/*<       end >*/
} /* fixnh_ */




/* SOURCE hec2x.for:629 */
/*<        >*/
/* Subroutine */ int scnhec_(integer *in, integer *stdout, integer *mxpntu, 
	real *stadir, real *stattb, integer *eflag, integer *ncflag, integer *
	grflag, integer *lnflag, integer *npntu, integer *nsubu, integer *
	navmu, real *scale, real *shift, real *feq_storage_xu, real *feq_storage_zu, integer *feq_storage_sbu, 
	real *feq_storage_nu, real *left, real *right, char *secid, integer *nhflag, 
	integer *x4flag, ftnlen secid_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *WRN:586* Left overbank n$=$0.0 on first N\
C card.\002,\002  Setting n to 1.0.\002)";
    static char fmt_51[] = "(\002 *WRN:587* Channel n$=$0.0 on first NC ca\
rd.\002,\002  Setting n to 1.0.\002)";
    static char fmt_52[] = "(\002 *WRN:588* Right overbank n$=$0.0 on first \
NC card.\002,\002  Setting n to 1.0.\002)";
    static char fmt_53[] = "(\002 *ERR:637* CARDS OUT OF ORDER. LAST CARD RE\
AD:\002)";
    static char fmt_54[] = "(\002 *ERR:638* GR CARDS FOUND BUT NC OR NH CARD\
 MISSING.\002)";
    static char fmt_55[] = "(\002 *ERR:639* X1 REFERS TO PREVIOUS GR DATA BU\
T NO GR DATA\002,\002 IS IN HAND.\002)";
    static char fmt_56[] = "(\002 *ERR:640* NUMNH=\002,i3,\002 > 20 ON NH CA\
RD.\002)";
    static char fmt_58[] = "(\002 *ERR:641* NELT=\002,i3,\002 > 20 ON X4 CAR\
D.\002)";
    static char fmt_60[] = "(\002 *ERR:642* NH CARD DOES NOT COVER CROSS SEC\
TION.\002)";
    static char fmt_61[] = "(\002  Last offset on NH card=\002,f10.1,\002 La\
st offset on GR\002,\002 card=\002,f10.1)";
    static char fmt_62[] = "(\002 *ERR:643* MANNING N=\002,f8.3,\002 <= 0 IN\
 SUBSECTION\002,i4)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), do_fio(
	    integer *, char *, ftnlen), e_rsfi(), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, k, je;
    static real el[254];
    integer js;
    real el2[254];
    static real elt[20], sta[254], xnl, stn[25], xnr;
    real sta2[254];
    static char line[80];
    real xlch;
    static real valn[25], xnch;
    static integer nelt;
    static real stat[20];
    real xnlt, xnrt;
    extern /* Subroutine */ int fixnh_(integer *, integer *, real *, integer *
	    , integer *, real *, real *);
    static real stchl, stchr;
    real xncht;
    static integer numnh, numst;
    extern /* Subroutine */ int sort2r_(integer *, real *, real *), inline_(
	    integer *, integer *, char *, ftnlen);
    real pxsece, stchlt, pxsecr, dumnum, stchrt, numstt;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__115 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__118 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Scan HEC2 input in the file, IN, and get the next */
/*     cross section and return the values needed for computing */
/*     a cross section table. */
/* SOURCE hec2x.for:640 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE hec2x.for:643 */
/*<        >*/
/* SOURCE hec2x.for:645 */
/*<       integersbu(mxpntu) >*/
/* SOURCE hec2x.for:646 */
/*<        >*/
/* SOURCE hec2x.for:648 */
/*<       charactersecid*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     MXPNTU - Maximum number of points on a cross section boundary */
/*     STADIR - Direction of stationing */
/*     STATTB - Initial station value for all flow lines */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     NCFLAG - Flag for the NC card */
/*     GRFLAG - Flag set when GR cards are encountered */
/*     LNFLAG - Flag to signal the state of the current line buffer */
/*     NPNTU  - Number of points on boundary of a cross section */
/*     NSUBU  - Number of subsections */
/*     NAVMU  - Flag for averaging roughness */
/*     SCALE  - Scale factor to apply to the offsets */
/*     SHIFT  - Value of vertical shift to apply to the points on the */
/*               cross section boundary */
/*     XU     - Offsets for points on boundary of cross section */
/*     ZU     - Elevation of points on boundary of cross section */
/*     SBU    - Subsection numbers for the line segments-upstream */
/*               location */
/*     NU     - Vector for Manning's n values */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     SECID  - Section identification value */
/*     NHFLAG - Flag for the NH card */
/*     X4FLAG - Flag for X4 card */
/*     + + + SAVED VALUES + + + */
/* SOURCE hec2x.for:681 */
/*<       integernelt,numnh,numst >*/
/* SOURCE hec2x.for:682 */
/*<        >*/
/* SOURCE hec2x.for:684 */
/*<       characterline*80 >*/
/* SOURCE hec2x.for:685 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE hec2x.for:689 */
/*<       integeri,j,je,js,k >*/
/* SOURCE hec2x.for:690 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE hec2x.for:694 */
/*<       intrinsicmin >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE hec2x.for:697 */
/*<       externalfixnh,inline,sort2r >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE hec2x.for:700 */
/*<    50  >*/
/* SOURCE hec2x.for:702 */
/*<    51  >*/
/* SOURCE hec2x.for:704 */
/*<    52  >*/
/* SOURCE hec2x.for:706 */
/*<    53 format(' *ERR:637* CARDS OUT OF ORDER. LAST CARD READ:') >*/
/* SOURCE hec2x.for:707 */
/*<    54 format(' *ERR:638* GR CARDS FOUND BUT NC OR NH CARD MISSING.') >*/
/* SOURCE hec2x.for:708 */
/*<    55  >*/
/* SOURCE hec2x.for:710 */
/*<    56 format(' *ERR:640* NUMNH=',i3,' > 20 ON NH CARD.') >*/
/* SOURCE hec2x.for:711 */
/*<    58 format(' *ERR:641* NELT=',i3,' > 20 ON X4 CARD.') >*/
/* SOURCE hec2x.for:712 */
/*<    60 format(' *ERR:642* NH CARD DOES NOT COVER CROSS SECTION.') >*/
/* SOURCE hec2x.for:713 */
/*<    61  >*/
/* SOURCE hec2x.for:715 */
/*<    62 format(' *ERR:643* MANNING N=',f8.3,' <= 0 IN SUBSECTION',i4) >*/
/* *********************************************************************** */
/*     GET THE NEXT LINE FROM THE HEC2 INPUT FILE */
/* SOURCE hec2x.for:719 */
/*<    90 continue >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> sbu(feq_storage_sbu, 1);

    feq::IndexedPointer<real> zu(feq_storage_zu, 1);

    feq::IndexedPointer<real> xu(feq_storage_xu, 1);

    feq::IndexedPointer<real> nu(feq_storage_nu, 1);

    /* Function Body */
/* L50: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
/* L56: */
/* L58: */
/* L60: */
/* L61: */
/* L62: */
L90:
/* SOURCE hec2x.for:720 */
/*<       if(lnflag.eq.0)then >*/
    if (*lnflag == 0) {
/* SOURCE hec2x.for:721 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:724 */
/*<       else >*/
    } else {
/*         CLEAR THE LINE BUFFER FLAG TO SIGNAL THAT THE BUFFER HAS */
/*         BEEN PROCESSED. */
/* SOURCE hec2x.for:727 */
/*<       lnflag=0 >*/
	*lnflag = 0;
/* SOURCE hec2x.for:728 */
/*<       endif >*/
    }
/*       USE AN IF-THEN-ELSE SEQUENCE TO DECIDE WHAT TO DO.  NOTE THAT */
/*       NCFLAG AND GRFLAG MUST BE CLEARED BY THE CALLING PROGRAM. */
/* SOURCE hec2x.for:733 */
/*<       if(line(1:2).eq.'NC')then >*/
    if (s_cmp(line, const_cast<char*>("NC"), (ftnlen)2, (ftnlen)2) == 0) {
/*         WE HAVE A CARD WHICH MIGHT CHANGE VALUES OF N */
/* SOURCE hec2x.for:735 */
/*<       read(line,'(2X,F6.0,9F8.0)',err=991)xnlt,xnrt,xncht >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(2X,F6.0,9F8.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&xnlt, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&xnrt, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&xncht, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE hec2x.for:736 */
/*<       if(ncflag.eq.0)then >*/
	if (*ncflag == 0) {
/* SOURCE hec2x.for:737 */
/*<       if(xnlt.eq.0.0)then >*/
	    if (xnlt == (float)0.) {
/* SOURCE hec2x.for:738 */
/*<       write(stdout,50) >*/
		feq_gen_io_d__75.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__75);
		e_wsfe();
/*              EFLAG = 1 */
/* SOURCE hec2x.for:740 */
/*<       xnlt=1.0 >*/
		xnlt = (float)1.;
/* SOURCE hec2x.for:741 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:742 */
/*<       if(xncht.eq.0.0)then >*/
	    if (xncht == (float)0.) {
/* SOURCE hec2x.for:743 */
/*<       write(stdout,51) >*/
		feq_gen_io_d__76.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__76);
		e_wsfe();
/*              EFLAG = 1 */
/* SOURCE hec2x.for:745 */
/*<       xncht=1.0 >*/
		xncht = (float)1.;
/* SOURCE hec2x.for:746 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:747 */
/*<       if(xnrt.eq.0.0)then >*/
	    if (xnrt == (float)0.) {
/*              EFLAG = 1 */
/* SOURCE hec2x.for:749 */
/*<       xnrt=1.0 >*/
		xnrt = (float)1.;
/* SOURCE hec2x.for:750 */
/*<       write(stdout,52) >*/
		feq_gen_io_d__77.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__77);
		e_wsfe();
/* SOURCE hec2x.for:751 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:752 */
/*<       if(eflag.eq.0)then >*/
	    if (*eflag == 0) {
/* SOURCE hec2x.for:753 */
/*<       ncflag=1 >*/
		*ncflag = 1;
/* SOURCE hec2x.for:754 */
/*<       nhflag=0 >*/
		*nhflag = 0;
/* SOURCE hec2x.for:755 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:756 */
/*<       else >*/
	} else {
/* SOURCE hec2x.for:757 */
/*<       nhflag=0 >*/
	    *nhflag = 0;
/*           Take value of zero to mean that n is unchanged. */
/* SOURCE hec2x.for:759 */
/*<       if(xnlt.eq.0.0)then >*/
	    if (xnlt == (float)0.) {
/* SOURCE hec2x.for:760 */
/*<       xnlt=-1.0 >*/
		xnlt = (float)-1.;
/* SOURCE hec2x.for:761 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:762 */
/*<       if(xncht.eq.0.0)then >*/
	    if (xncht == (float)0.) {
/* SOURCE hec2x.for:763 */
/*<       xncht=-1.0 >*/
		xncht = (float)-1.;
/* SOURCE hec2x.for:764 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:765 */
/*<       if(xnrt.eq.0.0)then >*/
	    if (xnrt == (float)0.) {
/* SOURCE hec2x.for:766 */
/*<       xnrt=-1.0 >*/
		xnrt = (float)-1.;
/* SOURCE hec2x.for:767 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:769 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:771 */
/*<       if(xnlt.gt.0.0.and.xnlt.le.9.0)then >*/
	if (xnlt > (float)0. && xnlt <= (float)9.) {
/* SOURCE hec2x.for:772 */
/*<       xnl=xnlt >*/
	    xnl = xnlt;
/* SOURCE hec2x.for:773 */
/*<       else >*/
	} else {
/*            XNL = 9.0 */
/* SOURCE hec2x.for:775 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:776 */
/*<       if(xnrt.gt.0.0.and.xnrt.le.9.0)then >*/
	if (xnrt > (float)0. && xnrt <= (float)9.) {
/* SOURCE hec2x.for:777 */
/*<       xnr=xnrt >*/
	    xnr = xnrt;
/* SOURCE hec2x.for:778 */
/*<       else >*/
	} else {
/*            XNR = 9.0 */
/* SOURCE hec2x.for:780 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:781 */
/*<       if(xncht.gt.0.0.and.xncht.le.9.0)then >*/
	if (xncht > (float)0. && xncht <= (float)9.) {
/* SOURCE hec2x.for:782 */
/*<       xnch=xncht >*/
	    xnch = xncht;
/* SOURCE hec2x.for:783 */
/*<       else >*/
	} else {
/*            XNCH = 9.0 */
/* SOURCE hec2x.for:785 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:787 */
/*<       elseif(line(1:2).eq.'X1')then >*/
    } else if (s_cmp(line, const_cast<char*>("X1"), (ftnlen)2, (ftnlen)2) == 0) {
/*         PROCESS THE X1 CARD */
/* SOURCE hec2x.for:790 */
/*<        >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(A8,3F8.0,16X,3F8.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, secid, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&numstt, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stchlt, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stchrt, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&xlch, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&pxsecr, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&pxsece, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE hec2x.for:792 */
/*<       scale=pxsecr >*/
	*scale = pxsecr;
/* SOURCE hec2x.for:793 */
/*<       shift=pxsece >*/
	*shift = pxsece;
/* SOURCE hec2x.for:794 */
/*<       if(stadir.ge.0.0)then >*/
	if (*stadir >= (float)0.) {
/* SOURCE hec2x.for:795 */
/*<       stattb=stattb+xlch >*/
	    *stattb += xlch;
/* SOURCE hec2x.for:796 */
/*<       else >*/
	} else {
/* SOURCE hec2x.for:797 */
/*<       stattb=stattb-xlch >*/
	    *stattb -= xlch;
/* SOURCE hec2x.for:798 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:800 */
/*<       if(numstt.gt.0.0)numst=numstt+.1 >*/
	if (numstt > (float)0.) {
	    numst = static_cast<double>(numstt) + (float).1;
	}
/* SOURCE hec2x.for:801 */
/*<       if(stchlt.ne.0.0)stchl=stchlt >*/
	if (stchlt != (float)0.) {
	    stchl = stchlt;
	}
/* SOURCE hec2x.for:802 */
/*<       if(stchrt.ne.0.0)stchr=stchrt >*/
	if (stchrt != (float)0.) {
	    stchr = stchrt;
	}
/*         LOOK AHEAD FOR AN X4 CARD.  MUST FOLLOW X1 CARD IMMEDIATELY. */
/* SOURCE hec2x.for:806 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:809 */
/*<       if(line(1:2).eq.'X4')then >*/
	if (s_cmp(line, const_cast<char*>("X4"), (ftnlen)2, (ftnlen)2) == 0) {
/* SOURCE hec2x.for:810 */
/*<       x4flag=1 >*/
	    *x4flag = 1;
/*           INPUT THE X4 CARD */
/* SOURCE hec2x.for:814 */
/*<        >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(2X,F6.0,9F8.0)");
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&dumnum, (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[0], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[0], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[2], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[2], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[3], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[3], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[4], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
/* SOURCE hec2x.for:817 */
/*<       nelt=dumnum+.1 >*/
	    nelt = static_cast<double>(dumnum) + (float).1;
/* SOURCE hec2x.for:818 */
/*<       if(nelt.gt.20)then >*/
	    if (nelt > 20) {
/* SOURCE hec2x.for:819 */
/*<       write(stdout,58)nelt >*/
		feq_gen_io_d__94.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__94);
		do_fio(&feq_gen_c_d_1, (char *)&nelt, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE hec2x.for:820 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE hec2x.for:821 */
/*<       return >*/
		return 0;
/* SOURCE hec2x.for:822 */
/*<       endif >*/
	    }
/*           SET THE OFFSET */
/* SOURCE hec2x.for:825 */
/*<       j=0 >*/
	    j = 0;
/* SOURCE hec2x.for:827 */
/*<   230 continue >*/
L230:
/* SOURCE hec2x.for:828 */
/*<       if(nelt.gt.4+j)then >*/
	    if (nelt > j + 4) {
/* SOURCE hec2x.for:829 */
/*<       callinline(in,stdout,line) >*/
		inline_(in, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:832 */
/*<       if(line(1:2).ne.'X4')then >*/
		if (s_cmp(line, const_cast<char*>("X4"), (ftnlen)2, (ftnlen)2) != 0) {
/* SOURCE hec2x.for:833 */
/*<       write(stdout,53) >*/
		    feq_gen_io_d__96.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__96);
		    e_wsfe();
/* SOURCE hec2x.for:834 */
/*<       write(stdout,'(1H ,A80)')line >*/
		    feq_gen_ci_d_1.cierr = 0;
		    feq_gen_ci_d_1.ciunit = *stdout;
		    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1H ,A80)");
		    s_wsfe(&feq_gen_ci_d_1);
		    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		    e_wsfe();
/* SOURCE hec2x.for:835 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE hec2x.for:836 */
/*<       return >*/
		    return 0;
/* SOURCE hec2x.for:837 */
/*<       else >*/
		} else {
/* SOURCE hec2x.for:838 */
/*<        >*/
		    feq_gen_ici_d_1.icierr = 1;
		    feq_gen_ici_d_1.iciend = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 80;
		    feq_gen_ici_d_1.iciunit = line;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(2X,F6.0,9F8.0)");
		    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[j + 4], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[j + 5], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[j + 5], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[j + 6], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[j + 6], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[j + 7], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[j + 7], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[j + 8], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat[j + 8], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elt[j + 9], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = e_rsfi();
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
/* SOURCE hec2x.for:841 */
/*<       endif >*/
		}
/* SOURCE hec2x.for:843 */
/*<       j=j+5 >*/
		j += 5;
/* SOURCE hec2x.for:844 */
/*<       goto230 >*/
		goto L230;
/* SOURCE hec2x.for:845 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:846 */
/*<       else >*/
	} else {
/* SOURCE hec2x.for:847 */
/*<       lnflag=1 >*/
	    *lnflag = 1;
/* SOURCE hec2x.for:848 */
/*<       x4flag=0 >*/
	    *x4flag = 0;
/* SOURCE hec2x.for:849 */
/*<       nelt=0 >*/
	    nelt = 0;
/* SOURCE hec2x.for:850 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:852 */
/*<       if(numstt.eq.0)then >*/
	if (numstt == (float)0.) {
/*           IS GR DATA IN HAND ALREADY? */
/* SOURCE hec2x.for:854 */
/*<       if(grflag.eq.0)then >*/
	    if (*grflag == 0) {
/* SOURCE hec2x.for:855 */
/*<       write(stdout,55) >*/
		feq_gen_io_d__97.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__97);
		e_wsfe();
/* SOURCE hec2x.for:856 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE hec2x.for:857 */
/*<       return >*/
		return 0;
/* SOURCE hec2x.for:858 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:859 */
/*<       if(ncflag.eq.0.and.nhflag.eq.0)then >*/
	    if (*ncflag == 0 && *nhflag == 0) {
/*             NO N VALUES IN HAND YET. CARDS OUT OF ORDER */
/* SOURCE hec2x.for:861 */
/*<       write(stdout,54) >*/
		feq_gen_io_d__98.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__98);
		e_wsfe();
/* SOURCE hec2x.for:862 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE hec2x.for:863 */
/*<       return >*/
		return 0;
/* SOURCE hec2x.for:864 */
/*<       endif >*/
	    }
/*           CROSS SECTION IN HAND. PROCESS IT INTO FEQX FORM. */
/* SOURCE hec2x.for:868 */
/*<       goto500 >*/
	    goto L500;
/* SOURCE hec2x.for:870 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:872 */
/*<       elseif(line(1:2).eq.'GR')then >*/
    } else if (s_cmp(line, const_cast<char*>("GR"), (ftnlen)2, (ftnlen)2) == 0) {
/*         PROCESS GR CARDS.  NUMST > 0 HERE. */
/* SOURCE hec2x.for:875 */
/*<       grflag=1 >*/
	*grflag = 1;
/* SOURCE hec2x.for:877 */
/*<       do100i=1,numst,5 >*/
	feq_gen_i_d_1 = numst;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 5) {
/* SOURCE hec2x.for:878 */
/*<       js=i >*/
	    js = feq_gen_i_d_;
/* SOURCE hec2x.for:879 */
/*<       je=min(js+4,numst) >*/
/* Computing MIN */
	    feq_gen_i_d_2 = js + 4;
	    je = min(feq_gen_i_d_2,numst);
/* SOURCE hec2x.for:880 */
/*<       read(line,'(2X,F6.0,9F8.0)',err=991)(el(j),sta(j),j=js,je) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(2X,F6.0,9F8.0)");
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_3 = je;
	    for (j = js; j <= feq_gen_i_d_3; ++j) {
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&el[j - 1], (ftnlen)sizeof(real))
			;
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&sta[j - 1], (ftnlen)sizeof(real)
			);
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/* SOURCE hec2x.for:881 */
/*<       if(je.lt.numst)then >*/
	    if (je < numst) {
/*             GET THE NEXT CARD */
/* SOURCE hec2x.for:883 */
/*<       callinline(in,stdout,line) >*/
		inline_(in, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:886 */
/*<       if(line(1:2).ne.'GR')then >*/
		if (s_cmp(line, const_cast<char*>("GR"), (ftnlen)2, (ftnlen)2) != 0) {
/* SOURCE hec2x.for:887 */
/*<       write(stdout,53) >*/
		    feq_gen_io_d__104.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__104);
		    e_wsfe();
/* SOURCE hec2x.for:888 */
/*<       write(stdout,'(1H ,A80)')line >*/
		    feq_gen_ci_d_1.cierr = 0;
		    feq_gen_ci_d_1.ciunit = *stdout;
		    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1H ,A80)");
		    s_wsfe(&feq_gen_ci_d_1);
		    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		    e_wsfe();
/* SOURCE hec2x.for:889 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE hec2x.for:890 */
/*<       return >*/
		    return 0;
/* SOURCE hec2x.for:891 */
/*<       endif >*/
		}
/* SOURCE hec2x.for:892 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:893 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE hec2x.for:895 */
/*<       if(ncflag.eq.0.and.nhflag.eq.0)then >*/
	if (*ncflag == 0 && *nhflag == 0) {
/*           NO N VALUES IN HAND YET. CARDS OUT OF ORDER */
/* SOURCE hec2x.for:897 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__105.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__105);
	    e_wsfe();
/* SOURCE hec2x.for:898 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE hec2x.for:899 */
/*<       return >*/
	    return 0;
/* SOURCE hec2x.for:900 */
/*<       endif >*/
	}
/*         CROSS SECTION DEFINED.  CONVERT IT TO THE FEQX DESCRIPTION */
/* SOURCE hec2x.for:904 */
/*<       goto500 >*/
	goto L500;
/* SOURCE hec2x.for:905 */
/*<       elseif(line(1:2).eq.'ER')then >*/
    } else if (s_cmp(line, const_cast<char*>("ER"), (ftnlen)2, (ftnlen)2) == 0) {
/*         END OF HEC2 INPUT */
/* SOURCE hec2x.for:907 */
/*<       secid='END' >*/
	s_copy(secid, const_cast<char*>("END"), (ftnlen)8, (ftnlen)3);
/* SOURCE hec2x.for:908 */
/*<       return >*/
	return 0;
/* SOURCE hec2x.for:909 */
/*<       elseif(line(1:7).eq.'ENDFILE')then >*/
    } else if (s_cmp(line, const_cast<char*>("ENDFILE"), (ftnlen)7, (ftnlen)7) == 0) {
/*         END OF FILE IN HEC2 INPUT */
/* SOURCE hec2x.for:911 */
/*<       secid='END' >*/
	s_copy(secid, const_cast<char*>("END"), (ftnlen)8, (ftnlen)3);
/* SOURCE hec2x.for:912 */
/*<       return >*/
	return 0;
/* SOURCE hec2x.for:913 */
/*<       elseif(line(1:2).eq.'NH')then >*/
    } else if (s_cmp(line, const_cast<char*>("NH"), (ftnlen)2, (ftnlen)2) == 0) {
/*         INPUT THE NH CARD AND SET FLAGS TO REFLECT VARIABLE */
/*         HORIZONTAL N VALUES. */
/* SOURCE hec2x.for:917 */
/*<        >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(2X,F6.0,9F8.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&dumnum, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[0], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[0], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[1], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[1], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[2], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[2], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[3], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[3], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[4], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE hec2x.for:920 */
/*<       numnh=dumnum+.1 >*/
	numnh = static_cast<double>(dumnum) + (float).1;
/* SOURCE hec2x.for:921 */
/*<       if(numnh.gt.20)then >*/
	if (numnh > 20) {
/* SOURCE hec2x.for:922 */
/*<       write(stdout,56)numnh >*/
	    feq_gen_io_d__109.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__109);
	    do_fio(&feq_gen_c_d_1, (char *)&numnh, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE hec2x.for:923 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE hec2x.for:924 */
/*<       return >*/
	    return 0;
/* SOURCE hec2x.for:925 */
/*<       endif >*/
	}
/*         SET THE OFFSET */
/* SOURCE hec2x.for:928 */
/*<       j=0 >*/
	j = 0;
/* SOURCE hec2x.for:930 */
/*<   200 continue >*/
L200:
/* SOURCE hec2x.for:931 */
/*<       if(numnh.gt.4+j)then >*/
	if (numnh > j + 4) {
/* SOURCE hec2x.for:932 */
/*<       callinline(in,stdout,line) >*/
	    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE hec2x.for:935 */
/*<       if(line(1:2).ne.'NH')then >*/
	    if (s_cmp(line, const_cast<char*>("NH"), (ftnlen)2, (ftnlen)2) != 0) {
/* SOURCE hec2x.for:936 */
/*<       write(stdout,53) >*/
		feq_gen_io_d__110.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__110);
		e_wsfe();
/* SOURCE hec2x.for:937 */
/*<       write(stdout,'(1H ,A80)')line >*/
		feq_gen_ci_d_1.cierr = 0;
		feq_gen_ci_d_1.ciunit = *stdout;
		feq_gen_ci_d_1.cifmt = const_cast<char*>("(1H ,A80)");
		s_wsfe(&feq_gen_ci_d_1);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		e_wsfe();
/* SOURCE hec2x.for:938 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE hec2x.for:939 */
/*<       return >*/
		return 0;
/* SOURCE hec2x.for:940 */
/*<       else >*/
	    } else {
/* SOURCE hec2x.for:941 */
/*<        >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 80;
		feq_gen_ici_d_1.iciunit = line;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(2X,F6.0,9F8.0)");
		feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[j + 4], (ftnlen)sizeof(real)
			);
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[j + 5], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[j + 5], (ftnlen)sizeof(real)
			);
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[j + 6], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[j + 6], (ftnlen)sizeof(real)
			);
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[j + 7], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[j + 7], (ftnlen)sizeof(real)
			);
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[j + 8], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stn[j + 8], (ftnlen)sizeof(real)
			);
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&valn[j + 9], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = e_rsfi();
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
/* SOURCE hec2x.for:944 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:946 */
/*<       j=j+5 >*/
	    j += 5;
/* SOURCE hec2x.for:947 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE hec2x.for:948 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:950 */
/*<       nhflag=1 >*/
	*nhflag = 1;
/*          NCFLAG = 0 */
/* SOURCE hec2x.for:953 */
/*<       endif >*/
    }
/*       READ THE NEXT CARD */
/* SOURCE hec2x.for:956 */
/*<       goto90 >*/
    goto L90;
/* SOURCE hec2x.for:958 */
/*<   500 continue >*/
L500:
/*     PROCESS THE EFFECT OF THE X4 CARD IF ANY WAS FOUND.  ASSUME THAT */
/*     THE X4 CARD MODIFIES BUT DOES NOT CHANGE THE RETAINED GR CARD */
/*     DATA.  TRANSFER THE RETAINED GR DATA TO THE WORK SPACE IN */
/*     ANY CASE. */
/* SOURCE hec2x.for:966 */
/*<       npntu=numst >*/
    *npntu = numst;
/* SOURCE hec2x.for:967 */
/*<       do300j=1,numst >*/
    feq_gen_i_d_1 = numst;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE hec2x.for:968 */
/*<       sta2(j)=sta(j) >*/
	sta2[j - 1] = sta[j - 1];
/* SOURCE hec2x.for:969 */
/*<       el2(j)=el(j) >*/
	el2[j - 1] = el[j - 1];
/* SOURCE hec2x.for:970 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE hec2x.for:973 */
/*<       if(x4flag.eq.1)then >*/
    if (*x4flag == 1) {
/*       X4 IS ACTIVE.  APPEND TO THE LIST OF THE CURRENT GR CARD */
/*       PATTERN AND SORT TO PLACE THE STATIONS IN ASCENDING ORDER */
/* SOURCE hec2x.for:976 */
/*<       npntu=numst+nelt >*/
	*npntu = numst + nelt;
/* SOURCE hec2x.for:977 */
/*<       do310j=numst+1,npntu >*/
	feq_gen_i_d_1 = *npntu;
	for (j = numst + 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE hec2x.for:978 */
/*<       sta2(j)=stat(j-numst) >*/
	    sta2[j - 1] = stat[j - numst - 1];
/* SOURCE hec2x.for:979 */
/*<       el2(j)=elt(j-numst) >*/
	    el2[j - 1] = elt[j - numst - 1];
/* SOURCE hec2x.for:980 */
/*<   310 continue >*/
/* L310: */
	}
/*       SORT THE VALUES INTO INCREASING ORDER OF STATION */
/* SOURCE hec2x.for:984 */
/*<       callsort2r(npntu,sta2,el2) >*/
	sort2r_(npntu, sta2, el2);
/* SOURCE hec2x.for:987 */
/*<       x4flag=0 >*/
	*x4flag = 0;
/* SOURCE hec2x.for:988 */
/*<       endif >*/
    }
/*     CONVERT THE CURRENT HEC2 CROSS SECTION TO FEQX FORM.  THEN USE */
/*     THE USUAL METHOD FOR COMPUTING CROSS SECTION TABLES. */
/* SOURCE hec2x.for:993 */
/*<       navmu=0 >*/
    *navmu = 0;
/*      WRITE(STDOUT,*) ' NUMST=',NUMST,' SCALE=',SCALE,' SHIFT=',SHIFT */
/* SOURCE hec2x.for:995 */
/*<       if(scale.eq.0.0)scale=1.0 >*/
    if (*scale == (float)0.) {
	*scale = (float)1.;
    }
/*     ASSIGN SUBSECTIONS */
/* SOURCE hec2x.for:997 */
/*<       if(ncflag.eq.1.and.nhflag.eq.0)then >*/
    if (*ncflag == 1 && *nhflag == 0) {
/* SOURCE hec2x.for:998 */
/*<       nsubu=3 >*/
	*nsubu = 3;
/* SOURCE hec2x.for:999 */
/*<       nu(1)=xnl >*/
	nu[1] = xnl;
/* SOURCE hec2x.for:1000 */
/*<       nu(2)=xnch >*/
	nu[2] = xnch;
/* SOURCE hec2x.for:1001 */
/*<       nu(3)=xnr >*/
	nu[3] = xnr;
/* SOURCE hec2x.for:1003 */
/*<       do510j=1,npntu >*/
	feq_gen_i_d_1 = *npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/*         WRITE(STDOUT,*) ' J=',J,' STA2(J)=',STA2(J),' EL2(J)=',EL2(J) */
/* SOURCE hec2x.for:1005 */
/*<       xu(j)=sta2(j)*scale >*/
	    xu[j] = static_cast<double>(sta2[j - 1]) * *scale;
/* SOURCE hec2x.for:1006 */
/*<       zu(j)=el2(j)+shift >*/
	    zu[j] = static_cast<double>(el2[j - 1]) + *shift;
/* SOURCE hec2x.for:1007 */
/*<       if(sta2(j).lt.stchl)then >*/
	    if (sta2[j - 1] < stchl) {
/* SOURCE hec2x.for:1008 */
/*<       sbu(j)=1 >*/
		sbu[j] = 1;
/* SOURCE hec2x.for:1009 */
/*<       elseif(sta2(j).ge.stchl.and.sta2(j).lt.stchr)then >*/
	    } else if (sta2[j - 1] >= stchl && sta2[j - 1] < stchr) {
/* SOURCE hec2x.for:1010 */
/*<       sbu(j)=2 >*/
		sbu[j] = 2;
/* SOURCE hec2x.for:1011 */
/*<       else >*/
	    } else {
/* SOURCE hec2x.for:1012 */
/*<       sbu(j)=3 >*/
		sbu[j] = 3;
/* SOURCE hec2x.for:1013 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:1014 */
/*<   510 continue >*/
/* L510: */
	}
/* SOURCE hec2x.for:1015 */
/*<       sbu(npntu)=-1 >*/
	sbu[*npntu] = -1;
/* SOURCE hec2x.for:1016 */
/*<       else >*/
    } else {
/* SOURCE hec2x.for:1017 */
/*<       if(nhflag.ne.1)then >*/
	if (*nhflag != 1) {
/* SOURCE hec2x.for:1018 */
/*<       write(stdout,*)' BUG IN FEQX2. NHFLAG INVALID.' >*/
	    feq_gen_io_d__113.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__113);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG IN FEQX2. NHFLAG INVALID."), (ftnlen)30)
		    ;
	    e_wsle();
/* SOURCE hec2x.for:1019 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:1020 */
/*<       endif >*/
	}
/*       Check for matching of boundary points.  If match not found */
/*       add a point to the boundary. */
/* SOURCE hec2x.for:1023 */
/*<       callfixnh(stdout,numnh,stn,254,npntu,sta2,el2) >*/
	fixnh_(stdout, &numnh, stn, &feq_gen_c_d_254, npntu, sta2, el2);
/* SOURCE hec2x.for:1027 */
/*<       nsubu=numnh >*/
	*nsubu = numnh;
/* SOURCE hec2x.for:1028 */
/*<       do210j=1,numnh >*/
	feq_gen_i_d_1 = numnh;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE hec2x.for:1029 */
/*<       if(valn(j).le.0.0)then >*/
	    if (valn[j - 1] <= (float)0.) {
/* SOURCE hec2x.for:1030 */
/*<       write(stdout,62)valn(j),j >*/
		feq_gen_io_d__114.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__114);
		do_fio(&feq_gen_c_d_1, (char *)&valn[j - 1], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE hec2x.for:1031 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE hec2x.for:1032 */
/*<       valn(j)=1.0 >*/
		valn[j - 1] = (float)1.;
/* SOURCE hec2x.for:1033 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:1034 */
/*<       if(valn(j).gt.9.0)then >*/
	    if (valn[j - 1] > (float)9.) {
/* SOURCE hec2x.for:1035 */
/*<       valn(j)=9.0 >*/
		valn[j - 1] = (float)9.;
/* SOURCE hec2x.for:1036 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:1037 */
/*<       nu(j)=valn(j) >*/
	    nu[j] = valn[j - 1];
/* SOURCE hec2x.for:1038 */
/*<   210 continue >*/
/* L210: */
	}
/* SOURCE hec2x.for:1040 */
/*<       if(stn(numnh).lt.sta2(npntu))then >*/
	if (stn[numnh - 1] < sta2[*npntu - 1]) {
/*         SPECIFICATION OF N DOES NOT COVER THE CROSS SECTION */
/* SOURCE hec2x.for:1042 */
/*<       write(stdout,60) >*/
	    feq_gen_io_d__115.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__115);
	    e_wsfe();
/* SOURCE hec2x.for:1043 */
/*<       write(stdout,61)stn(numnh),sta2(npntu) >*/
	    feq_gen_io_d__116.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__116);
	    do_fio(&feq_gen_c_d_1, (char *)&stn[numnh - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&sta2[*npntu - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE hec2x.for:1044 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE hec2x.for:1045 */
/*<       stn(numnh)=sta2(npntu) >*/
	    stn[numnh - 1] = sta2[*npntu - 1];
/* SOURCE hec2x.for:1046 */
/*<       endif >*/
	}
/*       ASSIGN VALUES TO THE LINE SEGMENTS ON THE CROSS SECTION */
/*       BOUNDARY */
/* SOURCE hec2x.for:1049 */
/*<       k=1 >*/
	k = 1;
/* SOURCE hec2x.for:1050 */
/*<       do220j=1,npntu >*/
	feq_gen_i_d_1 = *npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE hec2x.for:1051 */
/*<       xu(j)=sta2(j)*scale >*/
	    xu[j] = static_cast<double>(sta2[j - 1]) * *scale;
/* SOURCE hec2x.for:1052 */
/*<       zu(j)=el2(j)+shift >*/
	    zu[j] = static_cast<double>(el2[j - 1]) + *shift;
/* SOURCE hec2x.for:1054 */
/*<       sbu(j)=-1 >*/
	    sbu[j] = -1;
/* SOURCE hec2x.for:1055 */
/*<       if(sta2(j).lt.stn(k))then >*/
	    if (sta2[j - 1] < stn[k - 1]) {
/* SOURCE hec2x.for:1056 */
/*<       sbu(j)=k >*/
		sbu[j] = k;
/* SOURCE hec2x.for:1057 */
/*<       else >*/
	    } else {
/* SOURCE hec2x.for:1058 */
/*<       k=k+1 >*/
		++k;
/* SOURCE hec2x.for:1059 */
/*<       sbu(j)=k >*/
		sbu[j] = k;
/* SOURCE hec2x.for:1060 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:1061 */
/*<   220 continue >*/
/* L220: */
	}
/* SOURCE hec2x.for:1062 */
/*<       sbu(npntu)=-1 >*/
	sbu[*npntu] = -1;
/* SOURCE hec2x.for:1063 */
/*<       endif >*/
    }
/*     SET SCALE AND SHIFT TO DEFAULT VALUES */
/* SOURCE hec2x.for:1068 */
/*<       scale=1.0 >*/
    *scale = (float)1.;
/* SOURCE hec2x.for:1069 */
/*<       shift=0.0 >*/
    *shift = (float)0.;
/* SOURCE hec2x.for:1070 */
/*<       left=1.e20 >*/
    *left = (float)1e20;
/* SOURCE hec2x.for:1071 */
/*<       right=-1.e20 >*/
    *right = (float)-1e20;
/* SOURCE hec2x.for:1074 */
/*<       return >*/
    return 0;
/* SOURCE hec2x.for:1075 */
/*<   991 continue >*/
L991:
/* SOURCE hec2x.for:1076 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__118.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__118);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE hec2x.for:1077 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__119.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__119);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE hec2x.for:1078 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE hec2x.for:1079 */
/*<       end >*/
    return 0;
} /* scnhec_ */




/* SOURCE hec2x.for:1083 */
/*<       subroutinehec2x(stdin,stdout,stdtab,nfac,tabdir,ftp,eflag) >*/
/* Subroutine */ int hec2x_(integer *stdin, integer *stdout, integer *stdtab, 
	real *nfac, integer *feq_storage_tabdir, integer *ftp, integer *eflag)
{
    /* Initialized data */

    static char staout[18+1] = "('STATION=',      ";

    /* Format strings */
    static char fmt_50[] = "(//)";
    static char fmt_51[] = "(/,\002 TABID=\002,i8)";
    static char fmt_52[] = "(\002 NAVM=\002,i5,\002  SCALE=\002,f10.3,\002 S\
HIFT=\002,f10.3)";
    static char fmt_53[] = "(\002 STATION=\002,f10.3,\002 LEFT=\002,f10.1\
,\002 RIGHT=\002,f10.1)";
    static char fmt_54[] = "(\002 STATION=\002,f10.3)";
    static char fmt_55[] = "(1x,\002NSUB\002,i5,6f6.3)";
    static char fmt_56[] = "(10x,6f6.3)";
    static char fmt_58[] = "(\002 *ERR:504* NUMBER OF SUBSECTIONS=\002,i5\
,\002 > \002,i5)";
    static char fmt_61[] = "(\002 *ERR:506* ONLY ONE POINT GIVEN ON BOUNDARY\
 OF THE\002,\002 CROSS SECTION.\002)";
    static char fmt_67[] = "(\0020*WRN:554* Extending left end of cross sect\
ion\002,\002 by \002,f8.3)";
    static char fmt_68[] = "(/,\002 *WRN:555* Extending right end of cross s\
ection\002,\002 by \002,f8.3)";
    static char fmt_69[] = "(/,\002 *WRN:556* Some point in cross section hi\
gher than\002,\002 either end.\002,/,10x,\002All area above minimum end elev\
ation\002,\002 is ignored.\002)";
    static char fmt_70[] = "(\002     OFFSET ELEVATION SUBS\002,3x,a8)";
    static char fmt_72[] = "(\002 \002,f10.2,f10.2,i5)";
    static char fmt_75[] = "(\002TABID=\002,i8,2x,a8,1x,a8,1x,a8,1x,a8)";
    static char fmt_76[] = "(\002TABID=\002,i8,\002  EXTEND\002,2x,a8,1x,a8,\
1x,a8,1x,a8)";
    static char fmt_77[] = "(\002FEQX\002)";
    static char fmt_79[] = "(\002NAVM=0\002)";
    static char fmt_80[] = "(\002NSUB\002,i5,6f10.3)";
    static char fmt_81[] = "(\002    OFFSET ELEVATION SUBS\002,2x,a8)";
    static char fmt_82[] = "(2a10,i5)";
    static char fmt_83[] = "(9x,6f10.3)";
    static char fmt_84[] = "(i10)";
    static char fmt_85[] = "(\002 ZONE=\002,a8,\002 HGRID=\002,a8,\002 VDATU\
M=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8,/,\002 EASTING=\002,f15.3\
,\002 NORTHING=\002,f15.3)";
    static char fmt_86[] = "(\002ZONE=\002,a8,\002 HGRID=\002,a8,\002 VDAT\
UM=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8,/,\002EASTING=\002,f15.3\
,\002 NORTHING=\002,f15.3)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3[2];
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    cllist feq_gen_cl_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_clos(cllist *), s_wsfe(
	    cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), s_wsle(
	    cilist *), do_lio(integer *, integer *, char *, ftnlen), e_wsle(),
	     s_wsfi(icilist *), e_wsfi();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    char betaflag[1*999];
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_i_d_, j;
    char alphaflag[1*999];
    integer jj, in;
    real tp;
    char f10x[5];
    integer lim;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen);
    real sfac;
    char coff[10];
    real ufac;
    char mode[8];
    integer mesg;
    real left, xold;
    char zone[8];
    real zmax, scale;
    char secid[8], celev[10], hgrid[8], basis[8];
    integer itemp;
    real right, shift;
    extern /* Subroutine */ int mkfmt_(real *, integer *, char *, ftnlen);
    real statt;
    integer x4flag, begtab;
    char maflag[1*999];
    integer ncflag;
    char khflag[1*999];
    integer nhflag, tabinc;
    extern /* Subroutine */ int tabchk_(integer *, integer *, integer *, 
	    integer *, integer *);
    integer grflag, lnflag;
    extern /* Subroutine */ int scnhec_(integer *, integer *, integer *, real 
	    *, real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, real *, integer *, 
	    real *, real *, real *, char *, integer *, integer *, ftnlen);
    real begsta;
    char mqflag[1*999], monflg[8];
    real stadir;
    char conflg[8], betopt[8], outopt[8], savopt[8], vdatum[8];
    extern /* Subroutine */ int cxstab_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, char *, integer *, integer *, real *
	    , real *, integer *, integer *, real *, real *, real *, real *, 
	    integer *, integer *, real *, real *, real *, integer *, real *, 
	    ftnlen), hecstb_(integer *, integer *, integer *, real *, real *, 
	    real *, real *), inhecx_(integer *, integer *, char *, char *, 
	    char *, char *, integer *, char *, integer *, integer *, real *, 
	    real *, real *, char *, char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), tabout_(
	    integer *, integer *, integer *, real *, real *, integer *, char *
	    , char *, char *, char *, char *, char *, char *, char *, char *, 
	    char *, char *, char *, char *, integer *, real *, integer *, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), feq_gen_strip_l_blanks_d_(char *, 
	    ftnlen);
    integer locflag;
    extern /* Subroutine */ int xsecfit_(integer *, integer *, integer *, 
	    real *, char *, char *, char *, char *, char *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_85, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__158 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__165 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__166 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__167 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__168 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__170 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, fmt_67, 0 };
    static cilist feq_gen_io_d__172 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__173 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__182 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__184 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__189 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_83, 0 };
    static cilist feq_gen_io_d__191 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__194 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__195 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Abstract HEC2 cross sections from a HEC2 input deck. */
/*     Two options:  Compute the cross section tables directly or */
/*     compute the FEQX input form for later editing before the */
/*     cross section tables are computed. */
/* SOURCE hec2x.for:1094 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE hec2x.for:1097 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE hec2x.for:1098 */
/*<       integertabdir(*) >*/
/* SOURCE hec2x.for:1099 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     TABDIR - Table directory to remember table numbers */
/*     FTP    - next open location in the function table storage */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE hec2x.for:1111 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/* INCLUDE hec2x.for:1112 */
/*     COMMON FOR THE UPSTREAM CROSS SECTION */

/* SOURCE xscomu.cmn:3 */
/*<       integernpntu,nsubu,navmu,tabu,ndepu,mxpntu,usgsu,snflgu >*/
/* SOURCE xscomu.cmn:4 */
/*<       integersbu(pmxpnt),nvaru(pmxsub),nnyu(pmxsub) >*/
/* SOURCE xscomu.cmn:5 */
/*<       realstatu,zminu,zmaxu >*/
/* SOURCE xscomu.cmn:6 */
/*<        >*/

/* SOURCE xscomu.cmn:10 */
/*<        >*/
/*     SNFLGU- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points. */
/*     SNU- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSNU- LINE SEGMENT N VALUE */
/*     NVARU- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: 0-N IS CONSTANT, */
/*           1-N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           2-N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*           IF N VARIES WITH DEPTH, THE N VALUE APPLIES TO THE WHOLE */
/*           SUBSECTION.  NO VARIATION OF ROUGHNESS PERMITTED ON LINE SEGMENTS */
/*           IN THE SUBSECTION. */
/*     NATYU-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATNU- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYU- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS.  VALUE IS ZERO IF NVARU FOR THE */
/*          SUBSECTION IS ZERO.  THE N DEPTH PAIR AT ZERO DEPTH IS STORED */
/*          AND COUNTED WITH NVARU > 0 FOR THE SUBSECTION. */
/*     YSMXU- MAXIMUM DEPTH IN EACH SUBSECTION. */
/* INCLUDE hec2x.for:1113 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE hec2x.for:1114 */
/*     These I/O units will NOT have the number implied by their name. */
/*     The number will be assigned in FEQ/FEQUTL and will not be the same */
/*     as the old historic standard numbers. */
/*     This common block is retained in order to make transition to */
/*     internal assignment of I/O unit numbers easier. */
/* SOURCE stdun.cmn:7 */
/*<       integerstd5,std6,std7,std10,std48,std49,std50 >*/
/* SOURCE stdun.cmn:9 */
/*<       common/stdun_com/std5,std6,std7,std10,std48,std49,std50 >*/
/* SOURCE stdun.cmn:11 */
/*<       save/stdun_com/ >*/
/* INCLUDE hec2x.for:1115 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE hec2x.for:1116 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE hec2x.for:1119 */
/*<       characterstaout*18 >*/
/* SOURCE hec2x.for:1120 */
/*<       savestaout >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE hec2x.for:1123 */
/*<        >*/
/* SOURCE hec2x.for:1125 */
/*<        >*/
/* SOURCE hec2x.for:1127 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE hec2x.for:1135 */
/*<       intrinsicabs,max,min >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE hec2x.for:1138 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE hec2x.for:1142 */
/*<       datastaout/'(''STATION='','/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* SOURCE hec2x.for:1145 */
/*<    50 format(//) >*/
/* L50: */
/* SOURCE hec2x.for:1146 */
/*<    51 format(/,' TABID=',i8) >*/
/* L51: */
/* SOURCE hec2x.for:1147 */
/*<    52 format(' NAVM=',i5,'  SCALE=',f10.3,' SHIFT=',f10.3) >*/
/* L52: */
/* SOURCE hec2x.for:1148 */
/*<    53 format(' STATION=',f10.3,' LEFT=',f10.1,' RIGHT=',f10.1) >*/
/* L53: */
/* SOURCE hec2x.for:1149 */
/*<    54 format(' STATION=',f10.3) >*/
/* L54: */
/* SOURCE hec2x.for:1150 */
/*<    55 format(1x,'NSUB',i5,6f6.3) >*/
/* L55: */
/* SOURCE hec2x.for:1151 */
/*<    56 format(10x,6f6.3) >*/
/* L56: */
/* SOURCE hec2x.for:1152 */
/*<    58 format(' *ERR:504* NUMBER OF SUBSECTIONS=',i5,' > ',i5) >*/
/* L58: */
/* SOURCE hec2x.for:1153 */
/*<    61  >*/
/* L61: */
/* SOURCE hec2x.for:1155 */
/*<    67  >*/
/* L67: */
/* SOURCE hec2x.for:1157 */
/*<    68  >*/
/* L68: */
/* SOURCE hec2x.for:1159 */
/*<    69  >*/
/* L69: */
/* SOURCE hec2x.for:1162 */
/*<    70 format('     OFFSET ELEVATION SUBS',3x,a8) >*/
/* L70: */
/* SOURCE hec2x.for:1163 */
/*<    72 format(' ',f10.2,f10.2,i5) >*/
/* L72: */
/* SOURCE hec2x.for:1164 */
/*<    75 format('TABID=',i8,2x,a8,1x,a8,1x,a8,1x,a8) >*/
/* L75: */
/* SOURCE hec2x.for:1165 */
/*<    76 format('TABID=',i8,'  EXTEND',2x,a8,1x,a8,1x,a8,1x,a8) >*/
/* L76: */
/* SOURCE hec2x.for:1166 */
/*<    77 format('FEQX') >*/
/* L77: */
/* SOURCE hec2x.for:1167 */
/*<    79 format('NAVM=0') >*/
/* L79: */
/* SOURCE hec2x.for:1168 */
/*<    80 format('NSUB',i5,6f10.3) >*/
/* L80: */
/* SOURCE hec2x.for:1169 */
/*<    81 format('    OFFSET ELEVATION SUBS',2x,a8) >*/
/* L81: */
/* SOURCE hec2x.for:1170 */
/*<    82 format(2a10,i5) >*/
/* L82: */
/* SOURCE hec2x.for:1171 */
/*<    83 format(9x,6f10.3) >*/
/* L83: */
/* SOURCE hec2x.for:1172 */
/*<    84 format(i10) >*/
/* L84: */
/* SOURCE hec2x.for:1173 */
/*<    85  >*/
/* L85: */
/* SOURCE hec2x.for:1175 */
/*<    86  >*/
/* L86: */
/* *********************************************************************** */
/*     Clear the flags for values not set */
/* SOURCE hec2x.for:1179 */
/*<       gisid=' ' >*/
    s_copy(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE hec2x.for:1180 */
/*<       northing=0.d0 >*/
    xtadd_1.northing = 0.;
/* SOURCE hec2x.for:1181 */
/*<       easting=0.d0 >*/
    xtadd_1.easting = 0.;
/* SOURCE hec2x.for:1182 */
/*<       zone='NONE' >*/
    s_copy(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE hec2x.for:1183 */
/*<       hgrid='NONE' >*/
    s_copy(hgrid, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE hec2x.for:1184 */
/*<       vdatum='NONE' >*/
    s_copy(vdatum, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE hec2x.for:1185 */
/*<       unitsys='NONE' >*/
    s_copy(unitsys, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE hec2x.for:1186 */
/*<       basis='NONE' >*/
    s_copy(basis, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/*     CLEAR THE ERROR FLAG.  USED TO DETECT PROBLEMS THAT REQUIRE */
/*     EARLY EXITS FROM PROCESSING */
/* SOURCE hec2x.for:1191 */
/*<       eflag=0 >*/
    *eflag = 0;
/*     CLEAR THE VALUES NOT NEEDED TO REPRESENT THE CROSS SECTIONS BUT */
/*     STILL USED IN THE COMPUTATION OF THE TABLE. */
/* SOURCE hec2x.for:1196 */
/*<       do95i=1,pmxsub >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 200; ++feq_gen_i_d_) {
/* SOURCE hec2x.for:1197 */
/*<       nnyu(i)=0 >*/
	xscomu_1.nnyu[feq_gen_i_d_ - 1] = 0;
/* SOURCE hec2x.for:1198 */
/*<       nvaru(i)=0 >*/
	xscomu_1.nvaru[feq_gen_i_d_ - 1] = 0;
/* SOURCE hec2x.for:1199 */
/*<    95 continue >*/
/* L95: */
    }
/* SOURCE hec2x.for:1201 */
/*<       do96i=1,pmxpnt >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 999; ++feq_gen_i_d_) {
/* SOURCE hec2x.for:1202 */
/*<       snu(i)=1.0 >*/
	xscomu_1.snu[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE hec2x.for:1203 */
/*<       lsnu(i)=0.0 >*/
	xscomu_1.lsnu[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE hec2x.for:1204 */
/*<    96 continue >*/
/* L96: */
    }
/* SOURCE hec2x.for:1206 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/*     INPUT THE CONTROLLING DATA */
/* SOURCE hec2x.for:1209 */
/*<        >*/
    inhecx_(stdin, stdout, savopt, outopt, betopt, monflg, eflag, mode, &
	    begtab, &tabinc, &begsta, &stadir, &sfac, conflg, zone, hgrid, 
	    vdatum, unitsys, basis, &xtadd_1.easting, &xtadd_1.northing, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     Location information only supplied if vdatum or unit system is */
/*     active! */
/* SOURCE hec2x.for:1217 */
/*<       locflag=0 >*/
    locflag = 0;
/* SOURCE hec2x.for:1218 */
/*<       if(vdatum/='NONE'.or.vdatum/='NA')then >*/
    if (s_cmp(vdatum, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0 || s_cmp(vdatum, 
	    const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) != 0) {
/* SOURCE hec2x.for:1219 */
/*<       locflag=1 >*/
	locflag = 1;
/* SOURCE hec2x.for:1220 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:1221 */
/*<       if(unitsys/='NONE'.or.unitsys/='NA')then >*/
    if (s_cmp(unitsys, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0 || s_cmp(unitsys, 
	    const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) != 0) {
/* SOURCE hec2x.for:1222 */
/*<       locflag=1 >*/
	locflag = 1;
/* SOURCE hec2x.for:1223 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:1225 */
/*<       if(eflag.eq.1)return >*/
    if (*eflag == 1) {
	return 0;
    }
/*     Set conversion options */
/* SOURCE hec2x.for:1228 */
/*<       if(abs(nfac-1.0).le.0.0001)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(*nfac) - (float)1., dabs(feq_gen_r_d_1)) <= (float)1e-4) {
/*       Metric */
/* SOURCE hec2x.for:1230 */
/*<       if(conflg.ne.'        ')then >*/
	if (s_cmp(conflg, const_cast<char*>("        "), (ftnlen)8, (ftnlen)8) != 0) {
/*         Assume units are to be converted from english to metric */
/* SOURCE hec2x.for:1232 */
/*<       ufac=0.3048 >*/
	    ufac = (float).3048;
/* SOURCE hec2x.for:1233 */
/*<       else >*/
	} else {
/* SOURCE hec2x.for:1234 */
/*<       ufac=1.0 >*/
	    ufac = (float)1.;
/* SOURCE hec2x.for:1235 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1236 */
/*<       else >*/
    } else {
/* SOURCE hec2x.for:1237 */
/*<       if(conflg.ne.'        ')then >*/
	if (s_cmp(conflg, const_cast<char*>("        "), (ftnlen)8, (ftnlen)8) != 0) {
/*         Assume units are to be converted from metric to english */
/* SOURCE hec2x.for:1239 */
/*<       ufac=3.280840 >*/
	    ufac = (float)3.28084;
/* SOURCE hec2x.for:1240 */
/*<       else >*/
	} else {
/* SOURCE hec2x.for:1241 */
/*<       ufac=1.0 >*/
	    ufac = (float)1.;
/* SOURCE hec2x.for:1242 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1243 */
/*<       endif >*/
    }
/*     SET THE INPUT UNIT NUMBER */
/* SOURCE hec2x.for:1247 */
/*<       in=std48 >*/
    in = feq_gen_stdun_com_d_1.std48;
/* SOURCE hec2x.for:1249 */
/*<       if(mode.eq.'CHANNEL'.or.mode.eq.'channel')then >*/
    if (s_cmp(mode, const_cast<char*>("CHANNEL"), (ftnlen)8, (ftnlen)7) == 0 || s_cmp(mode, 
	    const_cast<char*>("channel"), (ftnlen)8, (ftnlen)7) == 0) {
/*       DO A SCAN OF THE INPUT FILE TO ESTABLISH THE */
/*       SINUOSITY TABLE. */
/* SOURCE hec2x.for:1253 */
/*<       callhecstb(in,std49,stdout,stadir,sfac,begsta,ufac) >*/
	hecstb_(&in, &feq_gen_stdun_com_d_1.std49, stdout, &stadir, &sfac, &begsta, &
		ufac);
/* SOURCE hec2x.for:1256 */
/*<       endif >*/
    }
/*     GET THE NEXT CROSS SECTION FROM THE HEC2 INPUT.  WHEN A */
/*     COMPLETE CROSS SECTION HAS BEEN DEFINED, RETURN WITH */
/*     THE FEQX INPUT AND PROCESS.  RETURN A FLAG WHEN NO */
/*     CROSS SECTION HAS BEEN FOUND.  THIS TERMINATES THE PROCESSING */
/*     OF THE FILE. */
/*     START THE TABLE NUMBERS */
/* SOURCE hec2x.for:1266 */
/*<       tabu=begtab >*/
    xscomu_1.tabu = begtab;
/*     ENABLE CONVEYANCE WARNING MESSAGES */
/* SOURCE hec2x.for:1270 */
/*<       nocm=0 >*/
    nrdzcm_1.nocm = 0;
/* SOURCE hec2x.for:1271 */
/*<       slot=0.0 >*/
    nrdzcm_1.slot = (float)0.;
/*     START THE STATION AT BEGSTA */
/* SOURCE hec2x.for:1276 */
/*<       statu=begsta >*/
    xscomu_1.statu = begsta;
/*     CLEAR THE FLAGS FOR CARD SEQUENCE CHECKING */
/* SOURCE hec2x.for:1279 */
/*<       ncflag=0 >*/
    ncflag = 0;
/* SOURCE hec2x.for:1280 */
/*<       grflag=0 >*/
    grflag = 0;
/* SOURCE hec2x.for:1281 */
/*<       nhflag=0 >*/
    nhflag = 0;
/* SOURCE hec2x.for:1282 */
/*<       lnflag=0 >*/
    lnflag = 0;
/* SOURCE hec2x.for:1283 */
/*<       x4flag=0 >*/
    x4flag = 0;
/* SOURCE hec2x.for:1285 */
/*<   100 continue >*/
L100:
/* SOURCE hec2x.for:1287 */
/*<       if(tabu.ge.0)calltabchk(stdout,pmxtab,tabu,tabdir,eflag) >*/
    if (xscomu_1.tabu >= 0) {
	tabchk_(stdout, &feq_gen_c_d_10002, &xscomu_1.tabu, &tabdir[1], eflag);
    }
/* SOURCE hec2x.for:1291 */
/*<        >*/
    scnhec_(&in, stdout, &xscomu_1.mxpntu, &stadir, &xscomu_1.statu, eflag, &
	    ncflag, &grflag, &lnflag, &xscomu_1.npntu, &xscomu_1.nsubu, &
	    xscomu_1.navmu, &scale, &shift, xscomu_1.xu, xscomu_1.zu, 
	    xscomu_1.sbu, xscomu_1.nu, &left, &right, secid, &nhflag, &x4flag,
	     (ftnlen)8);
/* SOURCE hec2x.for:1297 */
/*<       if(secid(1:3).eq.'END')then >*/
    if (s_cmp(secid, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE hec2x.for:1298 */
/*<       close(std48) >*/
	feq_gen_cl_d_1.cerr = 0;
	feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std48;
	feq_gen_cl_d_1.csta = 0;
	f_clos(&feq_gen_cl_d_1);
/* SOURCE hec2x.for:1299 */
/*<       if(mode.eq.'indirect'.or.mode.eq.'INDIRECT')then >*/
	if (s_cmp(mode, const_cast<char*>("indirect"), (ftnlen)8, (ftnlen)8) == 0 || s_cmp(mode, 
		const_cast<char*>("INDIRECT"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE hec2x.for:1300 */
/*<       close(std49) >*/
	    feq_gen_cl_d_1.cerr = 0;
	    feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std49;
	    feq_gen_cl_d_1.csta = 0;
	    f_clos(&feq_gen_cl_d_1);
/* SOURCE hec2x.for:1301 */
/*<       elseif(mode.eq.'CHANNEL'.or.mode.eq.'channel')then >*/
	} else if (s_cmp(mode, const_cast<char*>("CHANNEL"), (ftnlen)8, (ftnlen)7) == 0 || s_cmp(
		mode, const_cast<char*>("channel"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE hec2x.for:1302 */
/*<       write(std49,'(A)')'ENDCHAN' >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std49;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("ENDCHAN"), (ftnlen)7);
	    e_wsfe();
/* SOURCE hec2x.for:1303 */
/*<       close(std49) >*/
	    feq_gen_cl_d_1.cerr = 0;
	    feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std49;
	    feq_gen_cl_d_1.csta = 0;
	    f_clos(&feq_gen_cl_d_1);
/* SOURCE hec2x.for:1304 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1305 */
/*<       return >*/
	return 0;
/* SOURCE hec2x.for:1306 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:1307 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/* SOURCE hec2x.for:1309 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__151.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__151);
    e_wsfe();
/* SOURCE hec2x.for:1310 */
/*<       write(stdout,51)tabu >*/
    feq_gen_io_d__152.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__152);
    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.tabu, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE hec2x.for:1311 */
/*<       left=scale*left >*/
    left = static_cast<double>(scale) * left;
/* SOURCE hec2x.for:1312 */
/*<       right=scale*right >*/
    right = static_cast<double>(scale) * right;
/* SOURCE hec2x.for:1313 */
/*<       if(left.ge.right)then >*/
    if (left >= right) {
/* SOURCE hec2x.for:1314 */
/*<       write(stdout,54)statu/sfac >*/
	feq_gen_io_d__153.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__153);
	feq_gen_r_d_1 = static_cast<double>(xscomu_1.statu) / sfac;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE hec2x.for:1315 */
/*<       else >*/
    } else {
/* SOURCE hec2x.for:1316 */
/*<       write(stdout,53)statu/sfac,left,right >*/
	feq_gen_io_d__154.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__154);
	feq_gen_r_d_1 = static_cast<double>(xscomu_1.statu) / sfac;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&left, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&right, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE hec2x.for:1317 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:1318 */
/*<       write(stdout,85)zone,hgrid,vdatum,unitsys,basis,easting,northing >*/
    feq_gen_io_d__155.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__155);
    do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.easting, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.northing, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE hec2x.for:1320 */
/*<       write(stdout,52)navmu,scale,shift >*/
    feq_gen_io_d__156.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__156);
    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.navmu, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&scale, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE hec2x.for:1322 */
/*<       if(nsubu.gt.pmxsub)then >*/
    if (xscomu_1.nsubu > 200) {
/* SOURCE hec2x.for:1323 */
/*<       write(stdout,58)nsubu,pmxsub >*/
	feq_gen_io_d__157.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__157);
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nsubu, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_200, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE hec2x.for:1324 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE hec2x.for:1325 */
/*<       nsubu=pmxsub >*/
	xscomu_1.nsubu = 200;
/* SOURCE hec2x.for:1326 */
/*<       endif >*/
    }
/*        WRITE(STDOUT,55)  NSUBU, (NU(J),J=1,NSUBU) */
/* SOURCE hec2x.for:1329 */
/*<       write(stdout,55)nsubu,(nu(j),j=1,min(6,nsubu)) >*/
    feq_gen_io_d__158.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__158);
    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nsubu, (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = min(6,xscomu_1.nsubu);
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nu[j - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* SOURCE hec2x.for:1330 */
/*<       do280jj=7,nsubu,6 >*/
    feq_gen_i_d_1 = xscomu_1.nsubu;
    for (jj = 7; jj <= feq_gen_i_d_1; jj += 6) {
/* SOURCE hec2x.for:1331 */
/*<       lim=nsubu-jj >*/
	lim = xscomu_1.nsubu - jj;
/* SOURCE hec2x.for:1332 */
/*<       if(lim.gt.5)lim=5 >*/
	if (lim > 5) {
	    lim = 5;
	}
/* SOURCE hec2x.for:1333 */
/*<       write(stdout,56)(nu(jj+j),j=0,lim) >*/
	feq_gen_io_d__162.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__162);
	feq_gen_i_d_2 = lim;
	for (j = 0; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nu[jj + j - 1], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
/* SOURCE hec2x.for:1334 */
/*<   280 continue >*/
/* L280: */
    }
/*       SHIFT and SCALE applied in SCNHEC already.  Check */
/*       for monotonicity. */
/* SOURCE hec2x.for:1338 */
/*<       zmax=-9999999. >*/
    zmax = (float)-9999999.;
/* SOURCE hec2x.for:1339 */
/*<       xold=-1.e20 >*/
    xold = (float)-1e20;
/* SOURCE hec2x.for:1341 */
/*<       write(stdout,70)secid >*/
    feq_gen_io_d__165.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__165);
    do_fio(&feq_gen_c_d_1, secid, (ftnlen)8);
    e_wsfe();
/* SOURCE hec2x.for:1343 */
/*<       do110j=1,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE hec2x.for:1344 */
/*<       write(stdout,72)xu(j),zu(j),sbu(j) >*/
	feq_gen_io_d__166.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__166);
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.sbu[j - 1], (ftnlen)sizeof(integer));
	e_wsfe();
/*         FIND MAXIMUM ELEVATION IN CROSS SECTION FOR LATER CHECKING */
/* SOURCE hec2x.for:1348 */
/*<       zmax=max(zu(j),zmax) >*/
/* Computing MAX */
	feq_gen_r_d_1 = xscomu_1.zu[j - 1];
	zmax = dmax(feq_gen_r_d_1,zmax);
/*         CHECK FOR MONOTONICITY OF TOP WIDTH.  THIS REQUIRES THAT */
/*         THE OFFSET NEVER DECREASE. */
/* SOURCE hec2x.for:1353 */
/*<       if(monflg.eq.'MONOTONE')then >*/
	if (s_cmp(monflg, const_cast<char*>("MONOTONE"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE hec2x.for:1354 */
/*<       if(xu(j).lt.xold)then >*/
	    if (xscomu_1.xu[j - 1] < xold) {
/* SOURCE hec2x.for:1355 */
/*<        >*/
		feq_gen_io_d__167.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__167);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:508* SECTION VIOLATES MONOTONICI\
TY AT OFFSET="), (ftnlen)51);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)
			sizeof(real));
		e_wsle();
/* SOURCE hec2x.for:1357 */
/*<       eflag=eflag+1 >*/
		++(*eflag);
/* SOURCE hec2x.for:1358 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:1359 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1361 */
/*<       xold=xu(j) >*/
	xold = xscomu_1.xu[j - 1];
/* SOURCE hec2x.for:1363 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE hec2x.for:1365 */
/*<       if(npntu.le.1)then >*/
    if (xscomu_1.npntu <= 1) {
/* SOURCE hec2x.for:1366 */
/*<       write(stdout,61) >*/
	feq_gen_io_d__168.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__168);
	e_wsfe();
/* SOURCE hec2x.for:1367 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE hec2x.for:1368 */
/*<       endif >*/
    }
/*       CHECK THE CROSS SECTION FOR NONSENSE BEHAVIOR AT THE END */
/* SOURCE hec2x.for:1372 */
/*<       if(zu(1).le.zu(2).and.xu(2).gt.xu(1))then >*/
    if (xscomu_1.zu[0] <= xscomu_1.zu[1] && xscomu_1.xu[1] > xscomu_1.xu[0]) {
/*         THE LEFT MOST LINE SEGMENT HAS UPWARD SLOPE, THEREFORE HIGH */
/*         POINT IS NOT AT THE LEFT LIMIT. */
/* SOURCE hec2x.for:1376 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" *WRN:502* UNEXPECTED SLOPE"), (ftnlen)27);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" AT LEFT END."), (ftnlen)13);
	e_wsfe();
/* SOURCE hec2x.for:1378 */
/*<       write(stdout,*)'  SLOPE EXPECTED TO BE < 0  AT LEFT BOUNDARY' >*/
	feq_gen_io_d__169.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__169);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  SLOPE EXPECTED TO BE < 0  AT LEFT BOUNDARY"), (
		ftnlen)44);
	e_wsle();
/* SOURCE hec2x.for:1379 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:1380 */
/*<       if(zu(npntu).le.zu(npntu-1).and.xu(npntu).gt.xu(npntu-1))then >*/
    if (xscomu_1.zu[xscomu_1.npntu - 1] <= xscomu_1.zu[xscomu_1.npntu - 2] && 
	    xscomu_1.xu[xscomu_1.npntu - 1] > xscomu_1.xu[xscomu_1.npntu - 2])
	     {
/*         THE RIGHT MOST LINE SEGMENT HAS DOWNWARD SLOPE */
/* SOURCE hec2x.for:1383 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" *WRN:503* UNEXPECTED SLOPE"), (ftnlen)27);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" AT RIGHT END."), (ftnlen)14);
	e_wsfe();
/* SOURCE hec2x.for:1385 */
/*<       write(stdout,*)'  SLOPE EXPECTED TO BE > 0 AT RIGHT BOUNDARY' >*/
	feq_gen_io_d__170.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__170);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  SLOPE EXPECTED TO BE > 0 AT RIGHT BOUNDARY"), (
		ftnlen)44);
	e_wsle();
/* SOURCE hec2x.for:1386 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:1388 */
/*<       if(extend.eq.1)then >*/
    if (nrdzcm_1.extend == 1) {
/*         CHECK FOR ONE END BEING HIGHER THAN THE OTHER */
/* SOURCE hec2x.for:1391 */
/*<       if(abs(zmax-zu(1)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[0], dabs(feq_gen_r_d_1)) > epscom_1.epsdif) {
/* SOURCE hec2x.for:1392 */
/*<       write(stdout,67)zmax-zu(1) >*/
	    feq_gen_io_d__171.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__171);
	    feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[0];
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE hec2x.for:1393 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1394 */
/*<       if(abs(zmax-zu(npntu)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[xscomu_1.npntu - 1], dabs(feq_gen_r_d_1)) > 
		epscom_1.epsdif) {
/* SOURCE hec2x.for:1395 */
/*<       write(stdout,68)zmax-zu(npntu) >*/
	    feq_gen_io_d__172.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__172);
	    feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[xscomu_1.npntu - 1];
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE hec2x.for:1396 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1397 */
/*<       else >*/
    } else {
/*         CHECK FOR AN INTERMEDIATE POINT BEING HIGHER THAN EITHER */
/*         END */
/* SOURCE hec2x.for:1400 */
/*<        >*/
	if ((feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[0], dabs(feq_gen_r_d_1)) > epscom_1.epsdif && (
		feq_gen_r_d_2 = static_cast<double>(zmax) - xscomu_1.zu[xscomu_1.npntu - 1], dabs(feq_gen_r_d_2)) > 
		epscom_1.epsdif) {
/* SOURCE hec2x.for:1402 */
/*<       write(stdout,69) >*/
	    feq_gen_io_d__173.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__173);
	    e_wsfe();
/* SOURCE hec2x.for:1403 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1405 */
/*<       zmax=min(zu(1),zu(npntu)) >*/
/* Computing MIN */
	feq_gen_r_d_1 = xscomu_1.zu[0], feq_gen_r_d_2 = xscomu_1.zu[xscomu_1.npntu - 1];
	zmax = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE hec2x.for:1406 */
/*<       endif >*/
    }
/*       ASSIGN THE VALUES OF N FROM THE SUBSECTIONS TO THE LINE SEGMENT */
/*       LOCATIONS. */
/* SOURCE hec2x.for:1410 */
/*<       do120i=1,npntu-1 >*/
    feq_gen_i_d_1 = xscomu_1.npntu - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE hec2x.for:1411 */
/*<       lsnu(i)=nu(sbu(i)) >*/
	xscomu_1.lsnu[feq_gen_i_d_ - 1] = xscomu_1.nu[xscomu_1.sbu[feq_gen_i_d_ - 1] - 1];
/* SOURCE hec2x.for:1412 */
/*<   120 continue >*/
/* L120: */
    }
/*       Convert units here. */
/* SOURCE hec2x.for:1415 */
/*<       do122j=1,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE hec2x.for:1416 */
/*<       xu(j)=ufac*xu(j) >*/
	xscomu_1.xu[j - 1] = static_cast<double>(ufac) * xscomu_1.xu[j - 1];
/* SOURCE hec2x.for:1417 */
/*<       zu(j)=ufac*zu(j) >*/
	xscomu_1.zu[j - 1] = static_cast<double>(ufac) * xscomu_1.zu[j - 1];
/* SOURCE hec2x.for:1418 */
/*<   122 continue >*/
/* L122: */
    }
/* SOURCE hec2x.for:1419 */
/*<       zmax=ufac*zmax >*/
    zmax = static_cast<double>(ufac) * zmax;
/* SOURCE hec2x.for:1421 */
/*<       if(mode.eq.'DIRECT'.or.mode.eq.'direct')then >*/
    if (s_cmp(mode, const_cast<char*>("DIRECT"), (ftnlen)8, (ftnlen)6) == 0 || s_cmp(mode, const_cast<char*>("dir\
ect"), (ftnlen)8, (ftnlen)6) == 0) {
/*         COMPUTE ELEMENTS FOR CURRENT CROSS SECTION */
/* SOURCE hec2x.for:1425 */
/*<       if(npntu.gt.1)then >*/
	if (xscomu_1.npntu > 1) {
/*           FIND THE MAXIMUM AND MINIMUM ARGUMENT VALUES */
/* SOURCE hec2x.for:1427 */
/*<       zminu=9999999. >*/
	    xscomu_1.zminu = (float)9999999.;
/* SOURCE hec2x.for:1428 */
/*<       zmaxu=-9999999. >*/
	    xscomu_1.zmaxu = (float)-9999999.;
/* SOURCE hec2x.for:1429 */
/*<       do150j=1,npntu >*/
	    feq_gen_i_d_1 = xscomu_1.npntu;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE hec2x.for:1430 */
/*<       if(zu(j).gt.zmaxu)zmaxu=zu(j) >*/
		if (xscomu_1.zu[j - 1] > xscomu_1.zmaxu) {
		    xscomu_1.zmaxu = xscomu_1.zu[j - 1];
		}
/* SOURCE hec2x.for:1431 */
/*<       if(zu(j).lt.zminu)zminu=zu(j) >*/
		if (xscomu_1.zu[j - 1] < xscomu_1.zminu) {
		    xscomu_1.zminu = xscomu_1.zu[j - 1];
		}
/* SOURCE hec2x.for:1432 */
/*<   150 continue >*/
/* L150: */
	    }
/* SOURCE hec2x.for:1434 */
/*<       if(extend.eq.0)zmaxu=zmax >*/
	    if (nrdzcm_1.extend == 0) {
		xscomu_1.zmaxu = zmax;
	    }
/* SOURCE hec2x.for:1436 */
/*<       if(eflag.eq.0)then >*/
	    if (*eflag == 0) {
/* SOURCE hec2x.for:1438 */
/*<        >*/
		cxstab_(stdout, &xscomu_1.nsubu, &xscomu_1.navmu, nfac, &
			xscomu_1.mxpntu, &left, &right, betopt, &
			xscomu_1.snflgu, xscomu_1.nvaru, xscomu_1.natyu, 
			xscomu_1.yatnu, xscomu_1.nnyu, &xscomu_1.npntu, &
			xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu, 
			xscomu_1.zu, xscomu_1.sbu, eflag, xscomu_1.lsnu, 
			xscomu_1.snu, xscomu_1.nu, &xscomu_1.ndepu, 
			xscomu_1.xstu, (ftnlen)8);
/* SOURCE hec2x.for:1445 */
/*<       endif >*/
	    }
/* SOURCE hec2x.for:1446 */
/*<       endif >*/
	}
/*         OUTPUT THE TABLE IF NO ERRORS AND IF OUTPUT IS REQUESTED */
/* SOURCE hec2x.for:1450 */
/*<       if(eflag.ne.0.or.tabu.eq.0)goto200 >*/
	if (*eflag != 0 || xscomu_1.tabu == 0) {
	    goto L200;
	}
/* SOURCE hec2x.for:1451 */
/*<       if(nocm.eq.1)then >*/
	if (nrdzcm_1.nocm == 1) {
/* SOURCE hec2x.for:1452 */
/*<       mesg=0 >*/
	    mesg = 0;
/* SOURCE hec2x.for:1453 */
/*<       else >*/
	} else {
/* SOURCE hec2x.for:1454 */
/*<       mesg=1 >*/
	    mesg = 1;
/* SOURCE hec2x.for:1455 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1456 */
/*<       statt=statu/sfac >*/
	statt = static_cast<double>(xscomu_1.statu) / sfac;
/*           Change the generated table number to a tabid and get */
/*           an internal table number. */
/* SOURCE hec2x.for:1459 */
/*<       write(tabid,84)tabu >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 16;
	feq_gen_ici_d_1.iciunit = xtaddc_1.tabid;
	feq_gen_ici_d_1.icifmt = fmt_84;
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.tabu, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE hec2x.for:1460 */
/*<       callstrip_l_blanks(tabid) >*/
	feq_gen_strip_l_blanks_d_(xtaddc_1.tabid, (ftnlen)16);
/* SOURCE hec2x.for:1462 */
/*<       callget_internal_tab_number(stdout,tabid,eflag,itemp) >*/
	feq_gen_get_internal_tab_number_d_(stdout, xtaddc_1.tabid, eflag, &itemp, (
		ftnlen)16);
/*           compute derivatives of square root of conveyance, alpha, beta, */
/*           da, and dq */
/* SOURCE hec2x.for:1469 */
/*<        >*/
	xsecfit_(stdout, &feq_gen_c_d_0, &xscomu_1.ndepu, xscomu_1.xstu, khflag, 
		alphaflag, betaflag, maflag, mqflag, (ftnlen)1, (ftnlen)1, (
		ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE hec2x.for:1474 */
/*<        >*/
	tabout_(stdout, stdtab, &itemp, &statt, &xscomu_1.zminu, &mesg, 
		savopt, outopt, betopt, zone, hgrid, vdatum, unitsys, basis, 
		khflag, alphaflag, betaflag, maflag, mqflag, &xscomu_1.ndepu, 
		xscomu_1.xstu, ftp, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
		8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)1, (
		ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE hec2x.for:1480 */
/*<   200 continue >*/
L200:
/* SOURCE hec2x.for:1481 */
/*<       else >*/
	;
    } else {
/*         OUTPUT TO A FILE ATTACHED TO UNIT STD49 */
/* SOURCE hec2x.for:1484 */
/*<       write(std49,77) >*/
	feq_gen_io_d__182.ciunit = feq_gen_stdun_com_d_1.std49;
	s_wsfe(&feq_gen_io_d__182);
	e_wsfe();
/* SOURCE hec2x.for:1486 */
/*<       if(extend.eq.0)then >*/
	if (nrdzcm_1.extend == 0) {
/* SOURCE hec2x.for:1487 */
/*<       write(std49,75)tabu,monflg,betopt,savopt,outopt >*/
	    feq_gen_io_d__183.ciunit = feq_gen_stdun_com_d_1.std49;
	    s_wsfe(&feq_gen_io_d__183);
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.tabu, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, monflg, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, betopt, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, savopt, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, outopt, (ftnlen)8);
	    e_wsfe();
/* SOURCE hec2x.for:1488 */
/*<       else >*/
	} else {
/* SOURCE hec2x.for:1489 */
/*<       write(std49,76)tabu,monflg,betopt,savopt,outopt >*/
	    feq_gen_io_d__184.ciunit = feq_gen_stdun_com_d_1.std49;
	    s_wsfe(&feq_gen_io_d__184);
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.tabu, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, monflg, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, betopt, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, savopt, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, outopt, (ftnlen)8);
	    e_wsfe();
/* SOURCE hec2x.for:1490 */
/*<       endif >*/
	}
/* SOURCE hec2x.for:1492 */
/*<       tp=statu/sfac >*/
	tp = static_cast<double>(xscomu_1.statu) / sfac;
/* SOURCE hec2x.for:1493 */
/*<       callmkfmt(tp,10,f10x) >*/
	mkfmt_(&tp, &feq_gen_c_d_10, f10x, (ftnlen)5);
/* SOURCE hec2x.for:1496 */
/*<       staout(13:18)=f10x//')' >*/
/* Writing concatenation */
	feq_gen_i_d_3[0] = 5, feq_gen_a_d_1[0] = f10x;
	feq_gen_i_d_3[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>(")");
	s_cat(staout + 12, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE hec2x.for:1497 */
/*<       write(std49,staout)tp >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std49;
	feq_gen_ci_d_1.cifmt = feq::format_text(staout, sizeof(staout));
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&tp, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE hec2x.for:1498 */
/*<       write(std49,86)zone,hgrid,vdatum,unitsys,basis,easting,northing >*/
	feq_gen_io_d__187.ciunit = feq_gen_stdun_com_d_1.std49;
	s_wsfe(&feq_gen_io_d__187);
	do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.easting, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.northing, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE hec2x.for:1501 */
/*<       write(std49,79) >*/
	feq_gen_io_d__188.ciunit = feq_gen_stdun_com_d_1.std49;
	s_wsfe(&feq_gen_io_d__188);
	e_wsfe();
/* SOURCE hec2x.for:1503 */
/*<       write(std49,80)nsubu,(nu(j),j=1,min(6,nsubu)) >*/
	feq_gen_io_d__189.ciunit = feq_gen_stdun_com_d_1.std49;
	s_wsfe(&feq_gen_io_d__189);
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nsubu, (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = min(6,xscomu_1.nsubu);
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nu[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE hec2x.for:1504 */
/*<       do290jj=7,nsubu,6 >*/
	feq_gen_i_d_1 = xscomu_1.nsubu;
	for (jj = 7; jj <= feq_gen_i_d_1; jj += 6) {
/* SOURCE hec2x.for:1505 */
/*<       lim=nsubu-jj >*/
	    lim = xscomu_1.nsubu - jj;
/* SOURCE hec2x.for:1506 */
/*<       if(lim.gt.5)lim=5 >*/
	    if (lim > 5) {
		lim = 5;
	    }
/* SOURCE hec2x.for:1507 */
/*<       write(std49,83)(nu(jj+j),j=0,lim) >*/
	    feq_gen_io_d__190.ciunit = feq_gen_stdun_com_d_1.std49;
	    s_wsfe(&feq_gen_io_d__190);
	    feq_gen_i_d_2 = lim;
	    for (j = 0; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nu[jj + j - 1], (ftnlen)
			sizeof(real));
	    }
	    e_wsfe();
/* SOURCE hec2x.for:1508 */
/*<   290 continue >*/
/* L290: */
	}
/*          WRITE(STD49,80) NSUBU, (NU(J), J=1,NSUBU) */
/* SOURCE hec2x.for:1511 */
/*<       write(std49,81)secid >*/
	feq_gen_io_d__191.ciunit = feq_gen_stdun_com_d_1.std49;
	s_wsfe(&feq_gen_io_d__191);
	do_fio(&feq_gen_c_d_1, secid, (ftnlen)8);
	e_wsfe();
/* SOURCE hec2x.for:1513 */
/*<       do300j=1,npntu >*/
	feq_gen_i_d_1 = xscomu_1.npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE hec2x.for:1514 */
/*<       callvar_decimal(xu(j),coff) >*/
	    feq_gen_var_decimal_d_(&xscomu_1.xu[j - 1], coff, (ftnlen)10);
/* SOURCE hec2x.for:1516 */
/*<       callvar_decimal(zu(j),celev) >*/
	    feq_gen_var_decimal_d_(&xscomu_1.zu[j - 1], celev, (ftnlen)10);
/* SOURCE hec2x.for:1518 */
/*<       write(std49,82)coff,celev,sbu(j) >*/
	    feq_gen_io_d__194.ciunit = feq_gen_stdun_com_d_1.std49;
	    s_wsfe(&feq_gen_io_d__194);
	    do_fio(&feq_gen_c_d_1, coff, (ftnlen)10);
	    do_fio(&feq_gen_c_d_1, celev, (ftnlen)10);
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.sbu[j - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
/* SOURCE hec2x.for:1519 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE hec2x.for:1520 */
/*<       write(std49,50) >*/
	feq_gen_io_d__195.ciunit = feq_gen_stdun_com_d_1.std49;
	s_wsfe(&feq_gen_io_d__195);
	e_wsfe();
/* SOURCE hec2x.for:1521 */
/*<       endif >*/
    }
/* SOURCE hec2x.for:1523 */
/*<       tabu=tabu+tabinc >*/
    xscomu_1.tabu += tabinc;
/* SOURCE hec2x.for:1524 */
/*<       goto100 >*/
    goto L100;
/* SOURCE hec2x.for:1526 */
/*<       end >*/
} /* hec2x_ */

#ifdef __cplusplus
	}
#endif
