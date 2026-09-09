/* floodway.f -- translated by f2c (version 20240504).
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

/* COMMON fldway_ is declared in common.hpp. */

#define fldway_1 fldway_

/* COMMON fldwyc_ is declared in common.hpp. */

#define fldwyc_1 fldwyc_

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_8 = 8;
static integer feq_gen_c_d_3 = 3;




/* SOURCE floodway.for:4 */
/*<        >*/
/* Subroutine */ int feq_gen_read_floodway_items_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	eflag, integer *itab, char *opt, real *elev, char *bot, char *left, 
	char *right, char *loss, real *flow, integer *idlena, ftnlen line_len,
	 ftnlen opt_len, ftnlen bot_len, ftnlen left_len, ftnlen right_len, 
	ftnlen loss_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:775* Only \002,i3,\002 items given \
in \002,\002floodway description line.  Need st least seven items.\002)";
    static char fmt_52[] = "(/,\002 *ERR:753* Conversion error in field# \
\002,i2,\002 in:\002,/,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer n;
    extern integer feq_gen_nonblank_nonzero_d_(char *, ftnlen);
    integer ie, is;
    char tpc[20], key[16];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_52, 0 };


/*     Get the items of data a FLOODWAY-table entry line. */
/* SOURCE floodway.for:13 */
/*<       implicitnone >*/
/* SOURCE floodway.for:14 */
/*<        >*/
/* SOURCE floodway.for:17 */
/*<       realelev,flow >*/
/* SOURCE floodway.for:19 */
/*<       characterbot*8,left*8,loss*8,opt*4,right*8 >*/
/* SOURCE floodway.for:20 */
/*<       characterline*(*) >*/
/*     Local */
/* SOURCE floodway.for:24 */
/*<       integerie,is,lkey,n >*/
/* SOURCE floodway.for:25 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE floodway.for:28 */
/*<       integernonblank_nonzero >*/
/* SOURCE floodway.for:29 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE floodway.for:4 */
/*<       integer feq_len_trim >*/
/* SOURCE floodway.for:4 */
/*<       external feq_len_trim >*/
/* SOURCE floodway.for:32 */
/*<    50  >*/
/* SOURCE floodway.for:34 */
/*<    52 format(/,' *ERR:753* Conversion error in field# ',i2,' in:',/,a) >*/
/* *********************************************************************** */
/* SOURCE floodway.for:37 */
/*<       if(nitem.lt.7)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
/* L52: */
    if (*nitem < 7) {
/* SOURCE floodway.for:38 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__1.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__1);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE floodway.for:39 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE floodway.for:40 */
/*<       endif >*/
    }
/*     Process the cross-section table id */
/* SOURCE floodway.for:43 */
/*<       n=1 >*/
    n = 1;
/* SOURCE floodway.for:44 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE floodway.for:45 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE floodway.for:46 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE floodway.for:47 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE floodway.for:49 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE floodway.for:50 */
/*<       idlena=feq_len_trim(key) >*/
    *idlena = feq_gen_feq_len_trim_d_(key, (ftnlen)16);
/* SOURCE floodway.for:51 */
/*<       if(key(1:1).eq.'-')then >*/
    if (*(unsigned char *)key == '-') {
/* SOURCE floodway.for:52 */
/*<       itab=-1 >*/
	*itab = -1;
/* SOURCE floodway.for:53 */
/*<       else >*/
    } else {
/*       Convert from the table id to an internal number. */
/* SOURCE floodway.for:55 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*         We have an id given. */
/* SOURCE floodway.for:57 */
/*<       callget_internal_tab_number(stdout,key,eflag,itab) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, itab, (ftnlen)16);
/* SOURCE floodway.for:61 */
/*<       else >*/
	} else {
/* SOURCE floodway.for:62 */
/*<       itab=0 >*/
	    *itab = 0;
/* SOURCE floodway.for:63 */
/*<       endif >*/
	}
/* SOURCE floodway.for:64 */
/*<       endif >*/
    }
/*     Process the adjustment option */
/* SOURCE floodway.for:67 */
/*<       n=2 >*/
    n = 2;
/* SOURCE floodway.for:68 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE floodway.for:69 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE floodway.for:70 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE floodway.for:71 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE floodway.for:73 */
/*<       opt=tpc(1:4) >*/
    s_copy(opt, tpc, (ftnlen)4, (ftnlen)4);
/*     Process the standard-flood elevation */
/* SOURCE floodway.for:76 */
/*<       n=3 >*/
    n = 3;
/* SOURCE floodway.for:77 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE floodway.for:78 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE floodway.for:79 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE floodway.for:80 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE floodway.for:82 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE floodway.for:83 */
/*<       elev=0.0 >*/
	*elev = (float)0.;
/* SOURCE floodway.for:84 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:85 */
/*<       read(tpc,*,err=999)elev >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 20;
	feq_gen_ici_d_1.iciunit = tpc;
	feq_gen_ici_d_1.icifmt = 0;
	feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*elev), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE floodway.for:86 */
/*<       endif >*/
    }
/*     Process the invert-elevation field */
/* SOURCE floodway.for:89 */
/*<       n=4 >*/
    n = 4;
/* SOURCE floodway.for:90 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE floodway.for:91 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE floodway.for:92 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE floodway.for:93 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE floodway.for:95 */
/*<       bot=tpc(1:8) >*/
    s_copy(bot, tpc, (ftnlen)8, (ftnlen)8);
/*     Process the left-hand encroachment limit */
/* SOURCE floodway.for:98 */
/*<       n=5 >*/
    n = 5;
/* SOURCE floodway.for:99 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE floodway.for:100 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE floodway.for:101 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE floodway.for:102 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE floodway.for:104 */
/*<       left=tpc(1:8) >*/
    s_copy(left, tpc, (ftnlen)8, (ftnlen)8);
/*     Process the right-hand encroachment limit */
/* SOURCE floodway.for:107 */
/*<       n=6 >*/
    n = 6;
/* SOURCE floodway.for:108 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE floodway.for:109 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE floodway.for:110 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE floodway.for:111 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE floodway.for:113 */
/*<       right=tpc(1:8) >*/
    s_copy(right, tpc, (ftnlen)8, (ftnlen)8);
/*     Process the cross-section-loss value */
/* SOURCE floodway.for:116 */
/*<       n=7 >*/
    n = 7;
/* SOURCE floodway.for:117 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE floodway.for:118 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE floodway.for:119 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE floodway.for:120 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE floodway.for:122 */
/*<       loss=tpc(1:8) >*/
    s_copy(loss, tpc, (ftnlen)8, (ftnlen)8);
/*     Process the optional item for flow.  Used to compute velocity in the */
/*     floodway. */
/* SOURCE floodway.for:127 */
/*<       flow=0.0 >*/
    *flow = (float)0.;
/* SOURCE floodway.for:128 */
/*<       if(nitem.eq.8)then >*/
    if (*nitem == 8) {
/* SOURCE floodway.for:129 */
/*<       n=8 >*/
	n = 8;
/* SOURCE floodway.for:130 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE floodway.for:131 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE floodway.for:132 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE floodway.for:133 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE floodway.for:135 */
/*<       if(tpc(1:1).eq.' ')then >*/
	if (*(unsigned char *)tpc == ' ') {
/* SOURCE floodway.for:136 */
/*<       flow=0.0 >*/
	    *flow = (float)0.;
/* SOURCE floodway.for:137 */
/*<       else >*/
	} else {
/* SOURCE floodway.for:138 */
/*<       read(tpc,*,err=999)flow >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 20;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = 0;
	    feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*flow), (ftnlen)sizeof(real)
		    );
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = e_rsli();
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
/* SOURCE floodway.for:139 */
/*<       endif >*/
	}
/* SOURCE floodway.for:140 */
/*<       endif >*/
    }
/* SOURCE floodway.for:142 */
/*<       return >*/
    return 0;
/* SOURCE floodway.for:144 */
/*<   999 continue >*/
L999:
/* SOURCE floodway.for:145 */
/*<       write(stdout,52)n,line >*/
    feq_gen_io_d__7.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__7);
    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, line, line_len);
    e_wsfe();
/* SOURCE floodway.for:146 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE floodway.for:147 */
/*<       end >*/
    return 0;
} /* read_floodway_items__ */




/* SOURCE floodway.for:151 */
/*<       subroutinefldin(stdin,stdout,stdfld,eflag,fhead) >*/
/* Subroutine */ int fldin_(integer *stdin, integer *stdout, integer *stdfld, 
	integer *eflag, char *fhead, ftnlen fhead_len)
{
    /* Initialized data */

    static char blank[8+1] = "        ";

    /* Format strings */
    static char fmt_10[] = "(/,\002 Flood way option set.  All tables listed\
 above will be \002,/,\002 processed with the flood way option.  Tables enco\
untered\002,/,\002 in input but not in the table will be processed normally\
.\002)";
    static char fmt_50[] = "(/,a)";
    static char fmt_52[] = "(1x,a16,4x,a4,f14.2,4x,a8,2x,a8,2x,a8,f10.3,f10.\
1)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(),
	     f_inqu(inlist *), f_open(olist *), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_clos(cllist *), s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    integer feq_gen_item_end_d_[8], feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer feq_gen_item_start_d_[8];
    char bot[8], opt[4], head[80];
    extern /* Subroutine */ int feq_gen_read_floodway_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, char *, 
	    real *, char *, char *, char *, char *, real *, integer *, ftnlen,
	     ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    char line[80];
    real elev;
    char left[8];
    real flow;
    char loss[8], just[5];
    integer itaba;
    char tabid[16];
    integer nitem;
    char right[8];
    logical there;
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen);
    integer idlena;
    char filnam[64];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     feq_gen_maybe_add_home_d_(char *, ftnlen), feq_gen_get_item_limits_d_(integer *, 
	    char *, integer *, char *, integer *, integer *, integer *, 
	    ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__13 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input the floodway specifications. */
/* SOURCE floodway.for:158 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE floodway.for:161 */
/*<       integereflag,stdfld,stdin,stdout >*/
/* SOURCE floodway.for:162 */
/*<       characterfhead*91 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDFLD - Fortran unit number for Floodway file */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FHEAD   - Descriptive heading */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE floodway.for:172 */
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
/* INCLUDE floodway.for:173 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE floodway.for:176 */
/*<       characterblank*8 >*/
/* SOURCE floodway.for:177 */
/*<       saveblank >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE floodway.for:180 */
/*<       integeri,idlena,itaba,maxn,nitem >*/
/* SOURCE floodway.for:182 */
/*<       parameter(maxn=8) >*/
/* SOURCE floodway.for:184 */
/*<       integeritem_start(maxn),item_end(maxn) >*/
/* SOURCE floodway.for:186 */
/*<       realelev,flow >*/
/* SOURCE floodway.for:187 */
/*<        >*/
/* SOURCE floodway.for:189 */
/*<       logicalthere >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE floodway.for:192 */
/*<       characterget_tabid*16 >*/
/* SOURCE floodway.for:193 */
/*<       externalinline,get_tabid,os_file_style >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE floodway.for:196 */
/*<       datablank/'    '/ >*/
/* SOURCE floodway.for:199 */
/*<    10  >*/
/* L10: */
/* 50   FORMAT(/,' Table Identifier  Option  BF Elevation  FEQ Invert', */
/*     A' Left-----  Right---      Loss') */
/* SOURCE floodway.for:206 */
/*<    50 format(/,a) >*/
/* L50: */
/* SOURCE floodway.for:207 */
/*<    52 format(1x,a16,4x,a4,f14.2,4x,a8,2x,a8,2x,a8,f10.3,f10.1) >*/
/* L52: */
/* *********************************************************************** */
/*     Set heading-dependent processing to right justified */
/* SOURCE floodway.for:211 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/*     Create output heading */
/* SOURCE floodway.for:214 */
/*<        >*/
    s_copy(fhead, const_cast<char*>(" Table Identifier  Option  BF Elevation  FEQ Invert Left-\
----  Right---      Loss      Flow"), (ftnlen)91, (ftnlen)91);
/* SOURCE floodway.for:217 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE floodway.for:220 */
/*<       read(line,'(5X,A)',err=991)filnam >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(5X,A)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, filnam, (ftnlen)64);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE floodway.for:221 */
/*<       if(filnam.ne.' ')then >*/
    if (s_cmp(filnam, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1) != 0) {
/* SOURCE floodway.for:222 */
/*<       callmaybe_add_home(filnam) >*/
	feq_gen_maybe_add_home_d_(filnam, (ftnlen)64);
/* SOURCE floodway.for:225 */
/*<       callos_file_style(filnam) >*/
	feq_gen_os_file_style_d_(filnam, (ftnlen)64);
/* SOURCE floodway.for:227 */
/*<       write(stdout,'('' FLOODWAY TABLE FILE IS:'',A)')filnam >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(' FLOODWAY TABLE FILE IS:',A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, filnam, (ftnlen)64);
	e_wsfe();
/* SOURCE floodway.for:228 */
/*<       inquire(file=filnam,exist=there) >*/
	feq_gen_ioin_d_1.inerr = 0;
	feq_gen_ioin_d_1.infilen = 64;
	feq_gen_ioin_d_1.infile = filnam;
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
/* SOURCE floodway.for:229 */
/*<       if(there)then >*/
	if (there) {
/* SOURCE floodway.for:230 */
/*<       open(unit=stdfld,file=filnam,status='OLD') >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = *stdfld;
	    feq_gen_o_d_1.ofnmlen = 64;
	    feq_gen_o_d_1.ofnm = filnam;
	    feq_gen_o_d_1.orl = 0;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = 0;
	    feq_gen_o_d_1.ofm = 0;
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE floodway.for:231 */
/*<       else >*/
	} else {
/* SOURCE floodway.for:232 */
/*<       write(stdout,*)' FILE NAMED:',filnam,' NOT FOUND.' >*/
	    feq_gen_io_d__13.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__13);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FILE NAMED:"), (ftnlen)12);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, filnam, (ftnlen)64);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT FOUND."), (ftnlen)11);
	    e_wsle();
/* SOURCE floodway.for:233 */
/*<       write(stdout,*)' CHECK SPELLING OF STANDARD FLOOD FILE.' >*/
	    feq_gen_io_d__14.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__14);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK SPELLING OF STANDARD FLOOD FILE."), (
		    ftnlen)39);
	    e_wsle();
/* SOURCE floodway.for:234 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE floodway.for:235 */
/*<       endif >*/
	}
/* SOURCE floodway.for:236 */
/*<       endif >*/
    }
/*     Set the flood way flag */
/* SOURCE floodway.for:240 */
/*<       flood=1 >*/
    fldway_1.flood = 1;
/* SOURCE floodway.for:242 */
/*<       callinline(stdfld,stdout,line) >*/
    inline_(stdfld, stdout, line, (ftnlen)80);
/* SOURCE floodway.for:245 */
/*<       read(line,'(A)')head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_rsfi();
/* SOURCE floodway.for:246 */
/*<       write(stdout,'(1X,A80)')head >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A80)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/*     Input the global value of the loss in conveyance-the fraction of */
/*     total conveyance to be subtracted from each overbank */
/* SOURCE floodway.for:252 */
/*<       callinline(stdfld,stdout,line) >*/
    inline_(stdfld, stdout, line, (ftnlen)80);
/* SOURCE floodway.for:255 */
/*<       read(line,'(16X, F10.0)')glbcon >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(16X, F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.glbcon, (ftnlen)sizeof(real));
    e_rsfi();
/* SOURCE floodway.for:256 */
/*<       write(stdout,'('' CONVEYANCE LOSS='',F7.2)')glbcon >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' CONVEYANCE LOSS=',F7.2)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.glbcon, (ftnlen)sizeof(real));
    e_wsfe();
/*     Input the global value of the elevation loss */
/* SOURCE floodway.for:260 */
/*<       callinline(stdfld,stdout,line) >*/
    inline_(stdfld, stdout, line, (ftnlen)80);
/* SOURCE floodway.for:263 */
/*<       read(line,'(15X,F10.0)')glbelv >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(15X,F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.glbelv, (ftnlen)sizeof(real));
    e_rsfi();
/* SOURCE floodway.for:264 */
/*<       write(stdout,'('' ELEVATION LOSS='',F7.2)')glbelv >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' ELEVATION LOSS=',F7.2)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.glbelv, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE floodway.for:266 */
/*<       callinline(stdfld,stdout,line) >*/
    inline_(stdfld, stdout, line, (ftnlen)80);
/*      WRITE(STDOUT,'(1X,A80)') LINE */
/* SOURCE floodway.for:270 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_8, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)80, (ftnlen)5);
/*     Write standard heading to make it simple.  User's heading */
/*     used only for defining columns. */
/* SOURCE floodway.for:277 */
/*<       write(stdout,50)fhead >*/
    feq_gen_io_d__19.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__19);
    do_fio(&feq_gen_c_d_1, fhead, (ftnlen)91);
    e_wsfe();
/*     Clear the option values */
/* SOURCE floodway.for:281 */
/*<       do100i=1,pmxtab >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 10002; ++feq_gen_i_d_) {
/* SOURCE floodway.for:282 */
/*<       fldopt(i)='    ' >*/
	s_copy(fldwyc_1.fldopt + (feq_gen_i_d_ - 1 << 2), const_cast<char*>("    "), (ftnlen)4, (ftnlen)4)
		;
/* SOURCE floodway.for:283 */
/*<   100 continue >*/
/* L100: */
    }
/*     Input the specification until a table number is < 0 */
/* SOURCE floodway.for:287 */
/*<   200 continue >*/
L200:
/* SOURCE floodway.for:288 */
/*<       callinline(stdfld,stdout,line) >*/
    inline_(stdfld, stdout, line, (ftnlen)80);
/* SOURCE floodway.for:293 */
/*<        >*/
    feq_gen_read_floodway_items_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, 
	    eflag, &itaba, opt, &elev, bot, left, right, loss, &flow, &idlena,
	     (ftnlen)80, (ftnlen)4, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
	    8);
/* SOURCE floodway.for:301 */
/*<       if(itaba.le.0)then >*/
    if (itaba <= 0) {
/* SOURCE floodway.for:302 */
/*<       write(stdout,10) >*/
	feq_gen_io_d__30.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__30);
	e_wsfe();
/* SOURCE floodway.for:303 */
/*<       close(stdfld) >*/
	feq_gen_cl_d_1.cerr = 0;
	feq_gen_cl_d_1.cunit = *stdfld;
	feq_gen_cl_d_1.csta = 0;
	f_clos(&feq_gen_cl_d_1);
/* SOURCE floodway.for:304 */
/*<       return >*/
	return 0;
/* SOURCE floodway.for:305 */
/*<       endif >*/
    }
/* SOURCE floodway.for:307 */
/*<       tabid=get_tabid(itaba) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &itaba);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE floodway.for:309 */
/*<        >*/
    if (s_cmp(opt, const_cast<char*>("ELEV"), (ftnlen)4, (ftnlen)4) != 0 && s_cmp(opt, const_cast<char*>("CONV"), (
	    ftnlen)4, (ftnlen)4) != 0 && s_cmp(opt, const_cast<char*>("USET"), (ftnlen)4, (
	    ftnlen)4) != 0 && s_cmp(opt, const_cast<char*>("EQK"), (ftnlen)4, (ftnlen)3) != 0) {
/*         INVALID FLOODWAY OPTION */
/* SOURCE floodway.for:312 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE floodway.for:313 */
/*<       write(stdout,'(A)')line >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	e_wsfe();
/* SOURCE floodway.for:314 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("('*ERR:533* INVALID FLOODWAY OPTION IN ABOVE',       \
       ' LINE')");
	s_wsfe(&feq_gen_ci_d_1);
	e_wsfe();
/* SOURCE floodway.for:316 */
/*<       goto200 >*/
	goto L200;
/* SOURCE floodway.for:317 */
/*<       endif >*/
    }
/* SOURCE floodway.for:319 */
/*<       fldopt(itaba)=opt >*/
    s_copy(fldwyc_1.fldopt + (itaba - 1 << 2), opt, (ftnlen)4, (ftnlen)4);
/* SOURCE floodway.for:320 */
/*<       fldelv(itaba)=elev >*/
    fldway_1.fldelv[itaba - 1] = elev;
/* SOURCE floodway.for:321 */
/*<       if(nitem.gt.7)then >*/
    if (nitem > 7) {
/* SOURCE floodway.for:322 */
/*<       fldflow(itaba)=flow >*/
	fldway_1.fldflow[itaba - 1] = flow;
/* SOURCE floodway.for:323 */
/*<       else >*/
    } else {
/*         A flood flow of 0.0 signals that no flow has been given.  A floodway will never */
/*         be defined by zero flow so that this should be ok. */
/* SOURCE floodway.for:326 */
/*<       fldflow(itaba)=0.0 >*/
	fldway_1.fldflow[itaba - 1] = (float)0.;
/* SOURCE floodway.for:327 */
/*<       endif >*/
    }
/*       Note: elevation must always be given.  other items are optional */
/* SOURCE floodway.for:330 */
/*<       if(opt.eq.'USET')then >*/
    if (s_cmp(opt, const_cast<char*>("USET"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE floodway.for:331 */
/*<       if(left.eq.blank.or.right.eq.blank)then >*/
	if (s_cmp(left, blank, (ftnlen)8, (ftnlen)8) == 0 || s_cmp(right, 
		blank, (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE floodway.for:332 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE floodway.for:333 */
/*<       write(stdout,'(A)')line >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *stdout;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	    e_wsfe();
/* SOURCE floodway.for:334 */
/*<        >*/
	    feq_gen_io_d__32.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__32);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:534* IN LINE ABOVE, USET SELECTED BUT")
		    , (ftnlen)43);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ONE OR BOTH LIMITS MISSING."), (ftnlen)28);
	    e_wsle();
/* SOURCE floodway.for:336 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE floodway.for:337 */
/*<       endif >*/
	}
/* SOURCE floodway.for:338 */
/*<       endif >*/
    }
/* SOURCE floodway.for:340 */
/*<       if(bot.eq.blank)then >*/
    if (s_cmp(bot, blank, (ftnlen)8, (ftnlen)8) == 0) {
/*         Bottom profile in feq is same as minimum point in the */
/*         cross section */
/* SOURCE floodway.for:344 */
/*<       feqbot(itaba)=-1.e30 >*/
	fldway_1.feqbot[itaba - 1] = (float)-1e30;
/* SOURCE floodway.for:345 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:346 */
/*<       read(bot,'(F8.0)')feqbot(itaba) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 8;
	feq_gen_ici_d_1.iciunit = bot;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&fldway_1.feqbot[itaba - 1], (ftnlen)sizeof(
		real));
	e_rsfi();
/* SOURCE floodway.for:347 */
/*<       endif >*/
    }
/* SOURCE floodway.for:348 */
/*<       if(left.eq.blank)then >*/
    if (s_cmp(left, blank, (ftnlen)8, (ftnlen)8) == 0) {
/*         The left side of the cross section has no limit on the */
/*         flood way */
/* SOURCE floodway.for:351 */
/*<       fldlt(itaba)=1.e30 >*/
	fldway_1.fldlt[itaba - 1] = (float)1e30;
/* SOURCE floodway.for:352 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:353 */
/*<       read(left,'(F8.0)')fldlt(itaba) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 8;
	feq_gen_ici_d_1.iciunit = left;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldlt[itaba - 1], (ftnlen)sizeof(real)
		);
	e_rsfi();
/* SOURCE floodway.for:354 */
/*<       endif >*/
    }
/* SOURCE floodway.for:355 */
/*<       if(right.eq.blank)then >*/
    if (s_cmp(right, blank, (ftnlen)8, (ftnlen)8) == 0) {
/*         The right side of the cross section has no limit on the */
/*         floodway */
/* SOURCE floodway.for:358 */
/*<       fldrt(itaba)=-1.e30 >*/
	fldway_1.fldrt[itaba - 1] = (float)-1e30;
/* SOURCE floodway.for:359 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:360 */
/*<       read(right,'(F8.0)')fldrt(itaba) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 8;
	feq_gen_ici_d_1.iciunit = right;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldrt[itaba - 1], (ftnlen)sizeof(real)
		);
	e_rsfi();
/* SOURCE floodway.for:361 */
/*<       endif >*/
    }
/* SOURCE floodway.for:362 */
/*<       if(loss.eq.blank)then >*/
    if (s_cmp(loss, blank, (ftnlen)8, (ftnlen)8) == 0) {
/*         Take the global loss value */
/* SOURCE floodway.for:364 */
/*<       if(opt.eq.'ELEV')then >*/
	if (s_cmp(opt, const_cast<char*>("ELEV"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE floodway.for:365 */
/*<       fldlos(itaba)=glbelv >*/
	    fldway_1.fldlos[itaba - 1] = fldway_1.glbelv;
/* SOURCE floodway.for:366 */
/*<       elseif(opt.eq.'EQK')then >*/
	} else if (s_cmp(opt, const_cast<char*>("EQK"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE floodway.for:367 */
/*<       fldlos(itaba)=glbelv >*/
	    fldway_1.fldlos[itaba - 1] = fldway_1.glbelv;
/* SOURCE floodway.for:368 */
/*<       else >*/
	} else {
/* SOURCE floodway.for:369 */
/*<       fldlos(itaba)=glbcon >*/
	    fldway_1.fldlos[itaba - 1] = fldway_1.glbcon;
/* SOURCE floodway.for:370 */
/*<       endif >*/
	}
/* SOURCE floodway.for:371 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:372 */
/*<       read(loss,'(F8.0)')fldlos(itaba) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 8;
	feq_gen_ici_d_1.iciunit = loss;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldlos[itaba - 1], (ftnlen)sizeof(
		real));
	e_rsfi();
/* SOURCE floodway.for:373 */
/*<       endif >*/
    }
/* SOURCE floodway.for:375 */
/*<       if(fldrt(itaba).eq.-1.e30)then >*/
    if (fldway_1.fldrt[itaba - 1] == (float)-1e30) {
/* SOURCE floodway.for:376 */
/*<       right='  -inf  ' >*/
	s_copy(right, const_cast<char*>("  -inf  "), (ftnlen)8, (ftnlen)8);
/* SOURCE floodway.for:377 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:378 */
/*<       write(right,'(F8.1)')fldrt(itaba) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 8;
	feq_gen_ici_d_1.iciunit = right;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.1)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldrt[itaba - 1], (ftnlen)sizeof(real)
		);
	e_wsfi();
/* SOURCE floodway.for:379 */
/*<       endif >*/
    }
/* SOURCE floodway.for:380 */
/*<       if(fldlt(itaba).eq.1.e30)then >*/
    if (fldway_1.fldlt[itaba - 1] == (float)1e30) {
/* SOURCE floodway.for:381 */
/*<       left='  +inf  ' >*/
	s_copy(left, const_cast<char*>("  +inf  "), (ftnlen)8, (ftnlen)8);
/* SOURCE floodway.for:382 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:383 */
/*<       write(left,'(F8.1)')fldlt(itaba) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 8;
	feq_gen_ici_d_1.iciunit = left;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.1)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldlt[itaba - 1], (ftnlen)sizeof(real)
		);
	e_wsfi();
/* SOURCE floodway.for:384 */
/*<       endif >*/
    }
/* SOURCE floodway.for:385 */
/*<       if(feqbot(itaba).eq.-1.e30)then >*/
    if (fldway_1.feqbot[itaba - 1] == (float)-1e30) {
/* SOURCE floodway.for:386 */
/*<       bot='  same  ' >*/
	s_copy(bot, const_cast<char*>("  same  "), (ftnlen)8, (ftnlen)8);
/* SOURCE floodway.for:387 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:388 */
/*<       write(bot,'(F8.2)')feqbot(itaba) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 8;
	feq_gen_ici_d_1.iciunit = bot;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&fldway_1.feqbot[itaba - 1], (ftnlen)sizeof(
		real));
	e_wsfi();
/* SOURCE floodway.for:389 */
/*<       endif >*/
    }
/* SOURCE floodway.for:390 */
/*<        >*/
    feq_gen_io_d__33.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__33);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, fldwyc_1.fldopt + (itaba - 1 << 2), (ftnlen)4);
    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldelv[itaba - 1], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, bot, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, left, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, right, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldlos[itaba - 1], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&flow, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE floodway.for:394 */
/*<       goto200 >*/
    goto L200;
/* SOURCE floodway.for:395 */
/*<   991 continue >*/
L991:
/* SOURCE floodway.for:396 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__34.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__34);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE floodway.for:397 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__35.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__35);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE floodway.for:398 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE floodway.for:399 */
/*<       end >*/
    return 0;
} /* fldin_ */




/* SOURCE floodway.for:403 */
/*<       subroutinesetlme(itaba,stdout,eflag,left,right) >*/
/* Subroutine */ int setlme_(integer *itaba, integer *stdout, integer *eflag, 
	real *left, real *right)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:529* Too few intersections.  flood-wa\
y elevation \002,\002likely below section.\002,/,\002   IL=\002,i5,\002 IR\
=\002,i5)";
    static char fmt_52[] = "(/,\002 Final encroachment limits: Left=\002,f10\
.2,\002 Right=\002,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, il, ir;
    real dz, elev, feqbas;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__38 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Set the left and right hand values for the floodway based */
/*     on a given decrement in elevation from the 100-year flood */
/*     elevation. */
/* SOURCE floodway.for:412 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE floodway.for:415 */
/*<       integereflag,itaba,stdout >*/
/* SOURCE floodway.for:416 */
/*<       realleft,right >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ITABA  - Index for the cross section floodway descriptors */
/*     STDOUT - Fortran unit number for user output and messages */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE floodway.for:429 */
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
/* INCLUDE floodway.for:430 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/* INCLUDE floodway.for:431 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE floodway.for:434 */
/*<       integeri,il,ir >*/
/* SOURCE floodway.for:435 */
/*<       realdz,elev,feqbas >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE floodway.for:438 */
/*<    50  >*/
/* SOURCE floodway.for:440 */
/*<    52  >*/
/* *********************************************************************** */
/*     FIND THE ELEVATION TO USE IN SEARCHING THE CROSS SECTION. */
/*     MUST ADJUST FOR POTENTIAL DIFFERENCE BETWEEN THE BOTTOM PROFILE */
/*     AS USED IN FEQ AND IN FEQUTL */
/* SOURCE floodway.for:447 */
/*<       if(feqbot(itaba).lt.-1.e29)then >*/
/* L50: */
/* L52: */
    if (fldway_1.feqbot[*itaba - 1] < (float)-1e29) {
/* SOURCE floodway.for:448 */
/*<       feqbas=zminu >*/
	feqbas = xscomu_1.zminu;
/* SOURCE floodway.for:449 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:450 */
/*<       feqbas=feqbot(itaba) >*/
	feqbas = fldway_1.feqbot[*itaba - 1];
/* SOURCE floodway.for:451 */
/*<       endif >*/
    }
/* SOURCE floodway.for:453 */
/*<       elev=fldelv(itaba)-fldlos(itaba)-feqbas+zminu >*/
    elev = static_cast<double>(static_cast<double>(static_cast<double>(fldway_1.fldelv[*itaba - 1]) - fldway_1.fldlos[*itaba - 1]) - feqbas) 
	    + xscomu_1.zminu;
/* SOURCE floodway.for:455 */
/*<       write(stdout,'('' DEFINING ELEVATION='',F10.2)')elev >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' DEFINING ELEVATION=',F10.2)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE floodway.for:456 */
/*<       if(elev.le.zminu)then >*/
    if (elev <= xscomu_1.zminu) {
/* SOURCE floodway.for:457 */
/*<        >*/
	feq_gen_io_d__38.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__38);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:530* DEFINING ELEVATION BELOW CHANNEL"), (
		ftnlen)43);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BOTTOM."), (ftnlen)8);
	e_wsle();
/* SOURCE floodway.for:459 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE floodway.for:460 */
/*<       return >*/
	return 0;
/* SOURCE floodway.for:461 */
/*<       endif >*/
    }
/*     SEARCH FOR ELEVATION INTERVALS WHICH CONTAIN ELEV */
/* SOURCE floodway.for:465 */
/*<       if(elev.gt.zu(1))then >*/
    if (elev > xscomu_1.zu[0]) {
/* SOURCE floodway.for:466 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:531* FLDWAY ELEV=',F10.2,                  ' \
HIGHER THAN LEFT END ELEV=',F10.2)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[0], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE floodway.for:468 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE floodway.for:469 */
/*<       return >*/
	return 0;
/* SOURCE floodway.for:470 */
/*<       endif >*/
    }
/* SOURCE floodway.for:471 */
/*<       if(elev.gt.zu(npntu))then >*/
    if (elev > xscomu_1.zu[xscomu_1.npntu - 1]) {
/* SOURCE floodway.for:472 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:532* FLDWAY ELEV=',F10.2,                  ' \
HIGHER THAN RIGHT END ELEV=',F10.2)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[xscomu_1.npntu - 1], (ftnlen)
		sizeof(real));
	e_wsfe();
/* SOURCE floodway.for:474 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE floodway.for:475 */
/*<       return >*/
	return 0;
/* SOURCE floodway.for:476 */
/*<       endif >*/
    }
/*     SEARCH FOR ALL INTERVALS BUT RETAIN ONLY THE FIRST AND LAST BUT */
/*     ISSUE A WARNING IF THERE ARE ONE OR MORE 'ISLANDS' */
/* SOURCE floodway.for:481 */
/*<       ir=0 >*/
    ir = 0;
/* SOURCE floodway.for:482 */
/*<       il=0 >*/
    il = 0;
/* SOURCE floodway.for:483 */
/*<       do100i=2,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE floodway.for:484 */
/*<       if(zu(i).lt.zu(i-1).and.elev.gt.zu(i).and.elev.le.zu(i-1))then >*/
	if (xscomu_1.zu[feq_gen_i_d_ - 1] < xscomu_1.zu[feq_gen_i_d_ - 2] && elev > xscomu_1.zu[
		feq_gen_i_d_ - 1] && elev <= xscomu_1.zu[feq_gen_i_d_ - 2]) {
/*         FOUND LEFT INTERSECTION */
/* SOURCE floodway.for:486 */
/*<       if(il.eq.0)then >*/
	    if (il == 0) {
/* SOURCE floodway.for:487 */
/*<       il=i >*/
		il = feq_gen_i_d_;
/*            WRITE(STDOUT,*) ' LEFT INTERSECTION AT:',I */
/* SOURCE floodway.for:489 */
/*<       else >*/
	    } else {
/*            WRITE(STDOUT,*) ' LEFT INTERSECTION AT:',I */
/* SOURCE floodway.for:492 */
/*<        >*/
		feq_gen_io_d__42.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__42);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *WRN:516* MORE THAN ONE LEFT BOUNDARY.")
			, (ftnlen)39);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ONLY FIRST ONE RETAINED."), (ftnlen)25);
		e_wsle();
/* SOURCE floodway.for:494 */
/*<       endif >*/
	    }
/* SOURCE floodway.for:495 */
/*<       else >*/
	} else {
/* SOURCE floodway.for:496 */
/*<       if(zu(i).gt.zu(i-1).and.elev.le.zu(i).and.elev.gt.zu(i-1))then >*/
	    if (xscomu_1.zu[feq_gen_i_d_ - 1] > xscomu_1.zu[feq_gen_i_d_ - 2] && elev <= 
		    xscomu_1.zu[feq_gen_i_d_ - 1] && elev > xscomu_1.zu[feq_gen_i_d_ - 2]) {
/*           FOUND A RIGHT INTERSECTION */
/* SOURCE floodway.for:499 */
/*<       if(ir.eq.0)then >*/
		if (ir == 0) {
/* SOURCE floodway.for:500 */
/*<       ir=i >*/
		    ir = feq_gen_i_d_;
/*              WRITE(STDOUT,*) ' RIGHT INTERSECTION AT:',I */
/* SOURCE floodway.for:502 */
/*<       else >*/
		} else {
/*              WRITE(STDOUT,*) ' RIGHT INTERSECTION AT:',I */
/* SOURCE floodway.for:505 */
/*<       ir=i >*/
		    ir = feq_gen_i_d_;
/* SOURCE floodway.for:506 */
/*<        >*/
		    feq_gen_io_d__43.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__43);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *WRN:517* MORE THAN ONE RIGHT"), (
			    ftnlen)30);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BOUNDARY. ONLY LAST ONE RETAINED."),
			     (ftnlen)34);
		    e_wsle();
/* SOURCE floodway.for:508 */
/*<       endif >*/
		}
/* SOURCE floodway.for:509 */
/*<       endif >*/
	    }
/* SOURCE floodway.for:510 */
/*<       endif >*/
	}
/* SOURCE floodway.for:511 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE floodway.for:513 */
/*<       if(il.eq.0.or.ir.eq.0)then >*/
    if (il == 0 || ir == 0) {
/* SOURCE floodway.for:514 */
/*<       write(stdout,50)il,ir >*/
	feq_gen_io_d__44.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__44);
	do_fio(&feq_gen_c_d_1, (char *)&il, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&ir, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE floodway.for:515 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE floodway.for:516 */
/*<       return >*/
	return 0;
/* SOURCE floodway.for:517 */
/*<       endif >*/
    }
/* SOURCE floodway.for:518 */
/*<       dz=(zu(il)-zu(il-1)) >*/
    dz = static_cast<double>(xscomu_1.zu[il - 1]) - xscomu_1.zu[il - 2];
/* SOURCE floodway.for:519 */
/*<       if(dz.eq.0.0)then >*/
    if (dz == (float)0.) {
/* SOURCE floodway.for:520 */
/*<       write(stdout,*)' *BUG:502* ZERO DIFFERENCE IN ELEVATIONS' >*/
	feq_gen_io_d__46.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__46);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:502* ZERO DIFFERENCE IN ELEVATIONS"), (
		ftnlen)40);
	e_wsle();
/* SOURCE floodway.for:521 */
/*<       write(stdout,*)'I=',i >*/
	feq_gen_io_d__47.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__47);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("I="), (ftnlen)2);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE floodway.for:522 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE floodway.for:523 */
/*<       endif >*/
    }
/* SOURCE floodway.for:525 */
/*<       left=xu(il-1)+(elev-zu(il-1))*(xu(il)-xu(il-1))/dz >*/
    *left = static_cast<double>(xscomu_1.xu[il - 2]) + static_cast<double>(static_cast<double>((static_cast<double>(elev) - xscomu_1.zu[il - 2])) * (static_cast<double>(xscomu_1.xu[
	    il - 1]) - xscomu_1.xu[il - 2])) / dz;
/* SOURCE floodway.for:527 */
/*<       dz=(zu(ir)-zu(ir-1)) >*/
    dz = static_cast<double>(xscomu_1.zu[ir - 1]) - xscomu_1.zu[ir - 2];
/* SOURCE floodway.for:528 */
/*<       if(dz.eq.0.0)then >*/
    if (dz == (float)0.) {
/* SOURCE floodway.for:529 */
/*<       write(stdout,*)' *BUG:502* ZERO DIFFERENCE IN ELEVATIONS' >*/
	feq_gen_io_d__48.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__48);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:502* ZERO DIFFERENCE IN ELEVATIONS"), (
		ftnlen)40);
	e_wsle();
/* SOURCE floodway.for:530 */
/*<       write(stdout,*)'I=',i >*/
	feq_gen_io_d__49.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__49);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("I="), (ftnlen)2);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE floodway.for:531 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE floodway.for:532 */
/*<       endif >*/
    }
/* SOURCE floodway.for:534 */
/*<       right=xu(ir-1)+(elev-zu(ir-1))*(xu(ir)-xu(ir-1))/dz >*/
    *right = static_cast<double>(xscomu_1.xu[ir - 2]) + static_cast<double>(static_cast<double>((static_cast<double>(elev) - xscomu_1.zu[ir - 2])) * (
	    static_cast<double>(xscomu_1.xu[ir - 1]) - xscomu_1.xu[ir - 2])) / dz;
/* SOURCE floodway.for:536 */
/*<       if(left.gt.fldlt(itaba))left=fldlt(itaba) >*/
    if (*left > fldway_1.fldlt[*itaba - 1]) {
	*left = fldway_1.fldlt[*itaba - 1];
    }
/* SOURCE floodway.for:537 */
/*<       if(right.lt.fldrt(itaba))right=fldrt(itaba) >*/
    if (*right < fldway_1.fldrt[*itaba - 1]) {
	*right = fldway_1.fldrt[*itaba - 1];
    }
/* SOURCE floodway.for:538 */
/*<       write(stdout,52)left,right >*/
    feq_gen_io_d__50.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__50);
    do_fio(&feq_gen_c_d_1, (char *)&(*left), (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*right), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE floodway.for:541 */
/*<       return >*/
    return 0;
/* SOURCE floodway.for:542 */
/*<       end >*/
} /* setlme_ */




/* SOURCE floodway.for:546 */
/*<       subroutinesetlmk(tab,stdout,nfac,eflag,left,right) >*/
/* Subroutine */ int setlmk_(integer *tab, integer *stdout, real *nfac, 
	integer *eflag, real *left, real *right)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:776* Floodway elevation=\002,f10.2\
,\002 has conveyance=\002,1pe12.5,/,\002 < at BFE=\002,0pf10.2,\002 with con\
veyance=\002,1pe12.5)";
    static char fmt_52[] = "(/,\002 Desired conveyance-loss fraction on each\
 side=\002,f10.3)";
    static char fmt_54[] = "(/,\002 Base-Flood Elev. for Conveyane=\002,f10.\
2)";
    static char fmt_58[] = "(/,\002 Conveyance at base-flood elev.=\002,1pe1\
2.4)";
    static char fmt_60[] = "(/,\002 Final encroachment limits: Left=\002,f10\
.2,\002 Right=\002,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    real kb, kf, fl, fm, kl, fr, km, kr, xl, xm, xr, xsv[22], elev, ktar, 
	    loss, elev2, zseek, feqbas;
    extern /* Subroutine */ int cxselm_(real *, integer *, integer *, integer 
	    *, integer *, real *, real *, real *, real *, integer *, real *, 
	    real *, real *, real *, real *, integer *, real *, real *);
    real ktotal;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__79 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__80 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Find limits for a conveyance reduction floodway by direct */
/*     computation of the conveyance of the reduced cross section. */
/*     There is no unique way of computing the loss of */
/*     conveyance which is consistent with the intrinsic */
/*     meaning of conveyance */
/* SOURCE floodway.for:557 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE floodway.for:560 */
/*<       integereflag,stdout,tab >*/
/* SOURCE floodway.for:561 */
/*<       realleft,nfac,right >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TAB    - Internal table number */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE floodway.for:575 */
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
/* INCLUDE floodway.for:576 */
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
/* INCLUDE floodway.for:577 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/* INCLUDE floodway.for:578 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE floodway.for:581 */
/*<       integeri >*/
/* SOURCE floodway.for:582 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE floodway.for:586 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE floodway.for:589 */
/*<       externalcxselm >*/
/*     ***************************FORMATS******************************** */
/* SOURCE floodway.for:592 */
/*<    50  >*/
/* SOURCE floodway.for:595 */
/*<    52 format(/,' Desired conveyance-loss fraction on each side=',f10.3) >*/
/* SOURCE floodway.for:596 */
/*<    54 format(/,' Base-Flood Elev. for Conveyane=',f10.2) >*/
/* SOURCE floodway.for:597 */
/*<    58 format(/,' Conveyance at base-flood elev.=',1pe12.4) >*/
/* SOURCE floodway.for:598 */
/*<    60  >*/
/* *********************************************************************** */
/*     DETERMINE THE ELEVATION TO USE IN DEFINING THE CONVEYANCE */
/* SOURCE floodway.for:603 */
/*<       if(feqbot(tab).lt.-1.e29)then >*/
/* L50: */
/* L52: */
/* L54: */
/* L58: */
/* L60: */
    if (fldway_1.feqbot[*tab - 1] < (float)-1e29) {
/* SOURCE floodway.for:604 */
/*<       feqbas=zminu >*/
	feqbas = xscomu_1.zminu;
/* SOURCE floodway.for:605 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:606 */
/*<       feqbas=feqbot(tab) >*/
	feqbas = fldway_1.feqbot[*tab - 1];
/* SOURCE floodway.for:607 */
/*<       endif >*/
    }
/* SOURCE floodway.for:609 */
/*<       elev=fldelv(tab)-feqbas+zminu >*/
    elev = static_cast<double>(static_cast<double>(fldway_1.fldelv[*tab - 1]) - feqbas) + xscomu_1.zminu;
/* SOURCE floodway.for:611 */
/*<       write(stdout,54)elev >*/
    feq_gen_io_d__53.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__53);
    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE floodway.for:613 */
/*<       if(elev.le.zminu)then >*/
    if (elev <= xscomu_1.zminu) {
/* SOURCE floodway.for:614 */
/*<        >*/
	feq_gen_io_d__54.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__54);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:537* Base-Flood elevation below"), (ftnlen)
		37);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" channel invert!"), (ftnlen)16);
	e_wsle();
/* SOURCE floodway.for:616 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE floodway.for:617 */
/*<       return >*/
	return 0;
/* SOURCE floodway.for:618 */
/*<       endif >*/
    }
/*     COMPUTE THE TOTAL CONVEYANCE FOR THE CROSS SECTION BELOW THE */
/*     base-flood elevataion. */
/* SOURCE floodway.for:624 */
/*<       xl=1.e20 >*/
    xl = (float)1e20;
/* SOURCE floodway.for:625 */
/*<       xr=-1e20 >*/
    xr = (float)-1e20;
/* SOURCE floodway.for:626 */
/*<        >*/
    cxselm_(&elev, stdout, &xscomu_1.npntu, &xscomu_1.nsubu, &xscomu_1.navmu, 
	    &xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu, xscomu_1.zu, 
	    xscomu_1.sbu, nfac, &xl, &xr, xscomu_1.lsnu, xscomu_1.snu, eflag, 
	    xscomu_1.nu, xsv);
/* SOURCE floodway.for:632 */
/*<       ktotal=xsv(5)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = xsv[4];
    ktotal = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE floodway.for:633 */
/*<       zseek=elev >*/
    zseek = elev;
/* SOURCE floodway.for:636 */
/*<       if(fldopt(tab).eq.'EQK ')then >*/
    if (s_cmp(fldwyc_1.fldopt + (*tab - 1 << 2), const_cast<char*>("EQK "), (ftnlen)4, (ftnlen)4)
	     == 0) {
/*       Use KB for EQK option */
/* SOURCE floodway.for:638 */
/*<       kb=ktotal >*/
	kb = ktotal;
/* SOURCE floodway.for:639 */
/*<       write(stdout,58)kb >*/
	feq_gen_io_d__61.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__61);
	do_fio(&feq_gen_c_d_1, (char *)&kb, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE floodway.for:641 */
/*<       elev2=elev+fldlos(tab) >*/
	elev2 = static_cast<double>(elev) + fldway_1.fldlos[*tab - 1];
/*       Find conveyance at the new elevation */
/* SOURCE floodway.for:645 */
/*<       xl=1.e20 >*/
	xl = (float)1e20;
/* SOURCE floodway.for:646 */
/*<       xr=-1e20 >*/
	xr = (float)-1e20;
/* SOURCE floodway.for:647 */
/*<        >*/
	cxselm_(&elev2, stdout, &xscomu_1.npntu, &xscomu_1.nsubu, &
		xscomu_1.navmu, &xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu,
		 xscomu_1.zu, xscomu_1.sbu, nfac, &xl, &xr, xscomu_1.lsnu, 
		xscomu_1.snu, eflag, xscomu_1.nu, xsv);
/* SOURCE floodway.for:653 */
/*<       kf=xsv(5)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = xsv[4];
	kf = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE floodway.for:654 */
/*<       if(kf.le.kb)then >*/
	if (kf <= kb) {
/* SOURCE floodway.for:655 */
/*<       write(stdout,50)elev2,kf,elev,kb >*/
	    feq_gen_io_d__64.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__64);
	    do_fio(&feq_gen_c_d_1, (char *)&elev2, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&kf, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&kb, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE floodway.for:656 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE floodway.for:657 */
/*<       return >*/
	    return 0;
/* SOURCE floodway.for:658 */
/*<       endif >*/
	}
/*       Reset KTOTAL and ZSEEK for this case */
/* SOURCE floodway.for:661 */
/*<       ktotal=kf >*/
	ktotal = kf;
/* SOURCE floodway.for:662 */
/*<       zseek=elev2 >*/
	zseek = elev2;
/* SOURCE floodway.for:663 */
/*<       endif >*/
    }
/*     Compute the loss of conveyance that is to be used on */
/*     each side */
/* SOURCE floodway.for:668 */
/*<       if(fldopt(tab).eq.'EQK ')then >*/
    if (s_cmp(fldwyc_1.fldopt + (*tab - 1 << 2), const_cast<char*>("EQK "), (ftnlen)4, (ftnlen)4)
	     == 0) {
/* SOURCE floodway.for:669 */
/*<       loss=0.5*(kf-kb)/kf >*/
	loss = static_cast<double>(static_cast<double>((static_cast<double>(kf) - kb)) * (float).5) / kf;
/* SOURCE floodway.for:671 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:672 */
/*<       loss=fldlos(tab) >*/
	loss = fldway_1.fldlos[*tab - 1];
/* SOURCE floodway.for:673 */
/*<       endif >*/
    }
/* SOURCE floodway.for:675 */
/*<       write(stdout,52)loss >*/
    feq_gen_io_d__66.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__66);
    do_fio(&feq_gen_c_d_1, (char *)&loss, (ftnlen)sizeof(real));
    e_wsfe();

/*     COMPUTE THE TARGET AMOUNT FOR SETTING THE RIGHT HAND LIMIT */
/* SOURCE floodway.for:680 */
/*<       ktar=ktotal*(1.0-loss) >*/
    ktar = static_cast<double>(ktotal) * (static_cast<double>((float)1.) - loss);
/*     SEARCH FOR AN INTERVAL ON THE CROSS SECTION PERIPHIERY */
/*     WHICH CONTAINS KTAR . FIND RIGHT HAND LIMIT FIRST. */
/* SOURCE floodway.for:685 */
/*<       kr=ktotal >*/
    kr = ktotal;
/* SOURCE floodway.for:686 */
/*<       left=xu(1) >*/
    *left = xscomu_1.xu[0];
/* SOURCE floodway.for:687 */
/*<       xr=xu(npntu) >*/
    xr = xscomu_1.xu[xscomu_1.npntu - 1];
/*      WRITE(STDOUT,*) ' SEARCHING FOR RIGHT LIMIT KTAR=', KTAR */
/*      WRITE(STDOUT,*) '      XOFF          K' */
/*      WRITE(STDOUT,'(F10.1,1PE12.5)') XR, KR */
/* SOURCE floodway.for:691 */
/*<       do200i=npntu-1,1,-1 >*/
    for (feq_gen_i_d_ = xscomu_1.npntu - 1; feq_gen_i_d_ >= 1; --feq_gen_i_d_) {
/* SOURCE floodway.for:693 */
/*<       xl=xu(i) >*/
	xl = xscomu_1.xu[feq_gen_i_d_ - 1];
/* SOURCE floodway.for:694 */
/*<        >*/
	cxselm_(&zseek, stdout, &xscomu_1.npntu, &xscomu_1.nsubu, &
		xscomu_1.navmu, &xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu,
		 xscomu_1.zu, xscomu_1.sbu, nfac, left, &xl, xscomu_1.lsnu, 
		xscomu_1.snu, eflag, xscomu_1.nu, xsv);
/* SOURCE floodway.for:699 */
/*<       kl=xsv(5)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = xsv[4];
	kl = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*        WRITE(STDOUT,'(F10.1,1PE12.5)') XL, KL */
/* SOURCE floodway.for:703 */
/*<       if(ktar.le.kr.and.ktar.ge.kl)then >*/
	if (ktar <= kr && ktar >= kl) {
/*         FOUND INTERVAL */
/* SOURCE floodway.for:705 */
/*<       goto210 >*/
	    goto L210;
/* SOURCE floodway.for:706 */
/*<       endif >*/
	}
/* SOURCE floodway.for:708 */
/*<       xr=xl >*/
	xr = xl;
/* SOURCE floodway.for:709 */
/*<       kr=kl >*/
	kr = kl;
/* SOURCE floodway.for:710 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE floodway.for:712 */
/*<       write(stdout,*)' *ERR:538* NO INTERVAL FOUND FOR KTAR ON RIGHT' >*/
    feq_gen_io_d__71.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__71);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:538* NO INTERVAL FOUND FOR KTAR ON RIGHT"), (
	    ftnlen)46);
    e_wsle();
/* SOURCE floodway.for:713 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE floodway.for:714 */
/*<   210 continue >*/
L210:
/*     FIND THE MATCH VALUE USING BISECTION */
/* SOURCE floodway.for:718 */
/*<       fl=kl-ktar >*/
    fl = static_cast<double>(kl) - ktar;
/* SOURCE floodway.for:719 */
/*<       fr=kr-ktar >*/
    fr = static_cast<double>(kr) - ktar;
/*      WRITE(STDOUT,*) ' BISECTION' */
/* SOURCE floodway.for:722 */
/*<   300 continue >*/
L300:
/* SOURCE floodway.for:724 */
/*<       xm=xl-fl*(xr-xl)/(fr-fl) >*/
    xm = static_cast<double>(xl) - static_cast<double>(static_cast<double>(fl) * (static_cast<double>(xr) - xl)) / (static_cast<double>(fr) - fl);
/* SOURCE floodway.for:726 */
/*<        >*/
    cxselm_(&zseek, stdout, &xscomu_1.npntu, &xscomu_1.nsubu, &xscomu_1.navmu,
	     &xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu, xscomu_1.zu, 
	    xscomu_1.sbu, nfac, left, &xm, xscomu_1.lsnu, xscomu_1.snu, eflag,
	     xscomu_1.nu, xsv);
/* SOURCE floodway.for:732 */
/*<       km=xsv(5)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = xsv[4];
    km = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE floodway.for:734 */
/*<       fm=km-ktar >*/
    fm = static_cast<double>(km) - ktar;
/* SOURCE floodway.for:736 */
/*<       if(abs(fm/ktar).lt.1.d-4)goto310 >*/
    if ((feq_gen_r_d_1 = static_cast<double>(fm) / ktar, dabs(feq_gen_r_d_1)) < 1e-4) {
	goto L310;
    }
/* SOURCE floodway.for:737 */
/*<       if(abs(xr-xl).le.epsdif)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(xr) - xl, dabs(feq_gen_r_d_1)) <= epscom_1.epsdif) {
/* SOURCE floodway.for:738 */
/*<       write(stdout,*)' Bisection trapped at possible discontinuity' >*/
	feq_gen_io_d__77.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__77);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Bisection trapped at possible discontinuity"), (
		ftnlen)44);
	e_wsle();
/* SOURCE floodway.for:739 */
/*<       write(stdout,*)' at boundary between subsections.' >*/
	feq_gen_io_d__78.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__78);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" at boundary between subsections."), (ftnlen)33);
	e_wsle();
/* SOURCE floodway.for:740 */
/*<       write(stdout,*)' Requested reduction cannot be matched' >*/
	feq_gen_io_d__79.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__79);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Requested reduction cannot be matched"), (
		ftnlen)38);
	e_wsle();
/* SOURCE floodway.for:741 */
/*<       goto310 >*/
	goto L310;
/* SOURCE floodway.for:742 */
/*<       endif >*/
    }
/* SOURCE floodway.for:744 */
/*<       if(fm*fl.lt.0.0)then >*/
    if (static_cast<double>(fm) * fl < (float)0.) {
/* SOURCE floodway.for:745 */
/*<       fr=fm >*/
	fr = fm;
/* SOURCE floodway.for:746 */
/*<       xr=xm >*/
	xr = xm;
/* SOURCE floodway.for:747 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:748 */
/*<       fl=fm >*/
	fl = fm;
/* SOURCE floodway.for:749 */
/*<       xl=xm >*/
	xl = xm;
/* SOURCE floodway.for:750 */
/*<       endif >*/
    }
/* SOURCE floodway.for:751 */
/*<       goto300 >*/
    goto L300;
/* SOURCE floodway.for:753 */
/*<   310 continue >*/
L310:
/*     FOUND THE BOUNDARY ON THE RIGHT */
/* SOURCE floodway.for:757 */
/*<       right=xm >*/
    *right = xm;
/*     NOW FIND THE  TARGET VALUE FOR THE LEFT LIMIT */
/* SOURCE floodway.for:761 */
/*<       ktar=ktotal*(1.-2.*loss) >*/
    ktar = static_cast<double>(ktotal) * (static_cast<double>((float)1.) - static_cast<double>(loss) * (float)2.);
/*     SEARCH FOR AN INTERVAL ON THE CROSS SECTION PERIPHIERY */
/*     WHICH CONTAINS KTAR */
/* SOURCE floodway.for:766 */
/*<       kl=km >*/
    kl = km;
/* SOURCE floodway.for:767 */
/*<       xl=xu(1) >*/
    xl = xscomu_1.xu[0];
/*      WRITE(STDOUT,*) ' SEARCHING FOR LEFT LIMIT KTAR=', KTAR */
/*      WRITE(STDOUT,*) '      XOFF          K' */
/*      WRITE(STDOUT,'(F10.1,1PE12.5)') XL, KL */
/* SOURCE floodway.for:771 */
/*<       do400i=2,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE floodway.for:773 */
/*<       xr=xu(i) >*/
	xr = xscomu_1.xu[feq_gen_i_d_ - 1];
/* SOURCE floodway.for:774 */
/*<       if(xr.ge.right)then >*/
	if (xr >= *right) {
/* SOURCE floodway.for:775 */
/*<       xr=right-1.0 >*/
	    xr = static_cast<double>(*right) - (float)1.;
/* SOURCE floodway.for:776 */
/*<       endif >*/
	}
/* SOURCE floodway.for:777 */
/*<        >*/
	cxselm_(&zseek, stdout, &xscomu_1.npntu, &xscomu_1.nsubu, &
		xscomu_1.navmu, &xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu,
		 xscomu_1.zu, xscomu_1.sbu, nfac, &xr, right, xscomu_1.lsnu, 
		xscomu_1.snu, eflag, xscomu_1.nu, xsv);
/* SOURCE floodway.for:782 */
/*<       kr=xsv(5)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = xsv[4];
	kr = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*        WRITE(STDOUT,'(F10.1,1PE12.5)') XR, KR */
/* SOURCE floodway.for:786 */
/*<       if(ktar.le.kl.and.ktar.ge.kr)then >*/
	if (ktar <= kl && ktar >= kr) {
/*         FOUND INTERVAL */
/* SOURCE floodway.for:788 */
/*<       goto410 >*/
	    goto L410;
/* SOURCE floodway.for:789 */
/*<       endif >*/
	}
/* SOURCE floodway.for:791 */
/*<       xl=xr >*/
	xl = xr;
/* SOURCE floodway.for:792 */
/*<       kl=kr >*/
	kl = kr;
/* SOURCE floodway.for:793 */
/*<   400 continue >*/
/* L400: */
    }
/* SOURCE floodway.for:795 */
/*<       write(stdout,*)' *ERR:539* NO INTERVAL FOUND FOR KTAR ON LEFT' >*/
    feq_gen_io_d__80.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__80);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:539* NO INTERVAL FOUND FOR KTAR ON LEFT"), (
	    ftnlen)45);
    e_wsle();
/* SOURCE floodway.for:796 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE floodway.for:797 */
/*<   410 continue >*/
L410:
/*     FIND THE MATCH VALUE USING BISECTION */
/* SOURCE floodway.for:801 */
/*<       fl=kl-ktar >*/
    fl = static_cast<double>(kl) - ktar;
/* SOURCE floodway.for:802 */
/*<       fr=kr-ktar >*/
    fr = static_cast<double>(kr) - ktar;
/*      WRITE(STDOUT,*) ' BISECTION' */
/* SOURCE floodway.for:805 */
/*<   500 continue >*/
L500:
/* SOURCE floodway.for:807 */
/*<       xm=xl-fl*(xr-xl)/(fr-fl) >*/
    xm = static_cast<double>(xl) - static_cast<double>(static_cast<double>(fl) * (static_cast<double>(xr) - xl)) / (static_cast<double>(fr) - fl);
/* SOURCE floodway.for:809 */
/*<        >*/
    cxselm_(&zseek, stdout, &xscomu_1.npntu, &xscomu_1.nsubu, &xscomu_1.navmu,
	     &xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu, xscomu_1.zu, 
	    xscomu_1.sbu, nfac, &xm, right, xscomu_1.lsnu, xscomu_1.snu, 
	    eflag, xscomu_1.nu, xsv);
/* SOURCE floodway.for:815 */
/*<       km=xsv(5)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = xsv[4];
    km = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE floodway.for:817 */
/*<       fm=km-ktar >*/
    fm = static_cast<double>(km) - ktar;
/* SOURCE floodway.for:818 */
/*<       if(abs(fm/ktar).lt.1.d-4)goto510 >*/
    if ((feq_gen_r_d_1 = static_cast<double>(fm) / ktar, dabs(feq_gen_r_d_1)) < 1e-4) {
	goto L510;
    }
/* SOURCE floodway.for:819 */
/*<       if(abs(xr-xl).le.epsdif)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(xr) - xl, dabs(feq_gen_r_d_1)) <= epscom_1.epsdif) {
/* SOURCE floodway.for:820 */
/*<       write(stdout,*)' Bisection trapped at possible discontinuity' >*/
	feq_gen_io_d__81.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__81);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Bisection trapped at possible discontinuity"), (
		ftnlen)44);
	e_wsle();
/* SOURCE floodway.for:821 */
/*<       write(stdout,*)' at boundary between subsections.' >*/
	feq_gen_io_d__82.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__82);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" at boundary between subsections."), (ftnlen)33);
	e_wsle();
/* SOURCE floodway.for:822 */
/*<       write(stdout,*)' Requested reduction cannot be matched' >*/
	feq_gen_io_d__83.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__83);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Requested reduction cannot be matched"), (
		ftnlen)38);
	e_wsle();
/* SOURCE floodway.for:823 */
/*<       goto510 >*/
	goto L510;
/* SOURCE floodway.for:824 */
/*<       endif >*/
    }
/* SOURCE floodway.for:826 */
/*<       if(fm*fl.lt.0.0)then >*/
    if (static_cast<double>(fm) * fl < (float)0.) {
/* SOURCE floodway.for:827 */
/*<       fr=fm >*/
	fr = fm;
/* SOURCE floodway.for:828 */
/*<       xr=xm >*/
	xr = xm;
/* SOURCE floodway.for:829 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:830 */
/*<       fl=fm >*/
	fl = fm;
/* SOURCE floodway.for:831 */
/*<       xl=xm >*/
	xl = xm;
/* SOURCE floodway.for:832 */
/*<       endif >*/
    }
/* SOURCE floodway.for:833 */
/*<       goto500 >*/
    goto L500;
/* SOURCE floodway.for:835 */
/*<   510 continue >*/
L510:
/*     FOUND THE BOUNDARY ON THE LEFT */
/* SOURCE floodway.for:839 */
/*<       left=xm >*/
    *left = xm;
/*     CHECK FOR THE PRESET LIMITS */
/* SOURCE floodway.for:843 */
/*<       if(left.gt.fldlt(tab))left=fldlt(tab) >*/
    if (*left > fldway_1.fldlt[*tab - 1]) {
	*left = fldway_1.fldlt[*tab - 1];
    }
/* SOURCE floodway.for:844 */
/*<       if(right.lt.fldrt(tab))right=fldrt(tab) >*/
    if (*right < fldway_1.fldrt[*tab - 1]) {
	*right = fldway_1.fldrt[*tab - 1];
    }
/* SOURCE floodway.for:845 */
/*<       write(stdout,60)left,right >*/
    feq_gen_io_d__84.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__84);
    do_fio(&feq_gen_c_d_1, (char *)&(*left), (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*right), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE floodway.for:847 */
/*<       return >*/
    return 0;
/* SOURCE floodway.for:848 */
/*<       end >*/
} /* setlmk_ */




/* SOURCE floodway.for:852 */
/*<       subroutinefndway(tab,stdout,eflag,nfac,left,right,area) >*/
/* Subroutine */ int fndway_(integer *tab, integer *stdout, integer *eflag, 
	real *nfac, real *left, real *right, real *area)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Realized conveyence-loss fraction on eac\
h side =\002,f10.3)";

    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(), s_wsfe(cilist *),
	     do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real xl, xr, xsv[22];
    extern /* Subroutine */ int xchk_(integer *, integer *, real *, real *, 
	    real *, real *);
    real kpart, zgive, feqbas, ktotal;
    extern /* Subroutine */ int cxselm_(real *, integer *, integer *, integer 
	    *, integer *, real *, real *, real *, real *, integer *, real *, 
	    real *, real *, real *, real *, integer *, real *, real *), 
	    setlme_(integer *, integer *, integer *, real *, real *), setlmk_(
	    integer *, integer *, real *, integer *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__85 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the left and right limits for a floodway in the */
/*     channel. */
/* SOURCE floodway.for:860 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE floodway.for:863 */
/*<       integereflag,stdout,tab >*/
/* SOURCE floodway.for:864 */
/*<       realleft,nfac,right,area >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TAB    - Table number */
/*     STDOUT - Fortran unit number for user output and messages */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     NFAC   - Factor in Manning's formula */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     area   - area of the floodway */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE floodway.for:879 */
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
/* INCLUDE floodway.for:880 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/* INCLUDE floodway.for:881 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE floodway.for:884 */
/*<       integeri >*/
/* SOURCE floodway.for:885 */
/*<       realfeqbas,kpart,ktotal,xl,xr,xsv(pmxelm),zgive >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE floodway.for:888 */
/*<       externalcxselm,setlme,setlmk,xchk >*/
/*     ***************************FORMAT********************************* */
/* SOURCE floodway.for:890 */
/*<    50  >*/
/* *********************************************************************** */
/*     CHECK FOR INVALID HORIZONTAL LINE SEGMENTS */
/* SOURCE floodway.for:895 */
/*<       callxchk(stdout,npntu,zminu,xu,nfac,zu) >*/
/* L50: */
    xchk_(stdout, &xscomu_1.npntu, &xscomu_1.zminu, xscomu_1.xu, nfac, 
	    xscomu_1.zu);
/*     SELECT FLOODWAY OPTION */
/*      WRITE(STDOUT,*) ' In FNDWAY TAB=',TAB */
/*      WRITE(STDOUT,*) ' In FNDWAY FLDOPT(TAB)=', FLDOPT(TAB) */
/* SOURCE floodway.for:903 */
/*<       if(fldopt(tab).eq.'ELEV')then >*/
    if (s_cmp(fldwyc_1.fldopt + (*tab - 1 << 2), const_cast<char*>("ELEV"), (ftnlen)4, (ftnlen)4)
	     == 0) {
/* SOURCE floodway.for:904 */
/*<       callsetlme(tab,stdout,eflag,left,right) >*/
	setlme_(tab, stdout, eflag, left, right);
/* SOURCE floodway.for:907 */
/*<       elseif(fldopt(tab).eq.'CONV'.or.fldopt(tab).eq.'EQK')then >*/
    } else if (s_cmp(fldwyc_1.fldopt + (*tab - 1 << 2), const_cast<char*>("CONV"), (ftnlen)4, (
	    ftnlen)4) == 0 || s_cmp(fldwyc_1.fldopt + (*tab - 1 << 2), const_cast<char*>("EQK"), 
	    (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE floodway.for:908 */
/*<       callsetlmk(tab,stdout,nfac,eflag,left,right) >*/
	setlmk_(tab, stdout, nfac, eflag, left, right);
/* SOURCE floodway.for:911 */
/*<       elseif(fldopt(tab).eq.'USET')then >*/
    } else if (s_cmp(fldwyc_1.fldopt + (*tab - 1 << 2), const_cast<char*>("USET"), (ftnlen)4, (
	    ftnlen)4) == 0) {
/* SOURCE floodway.for:912 */
/*<       left=fldlt(tab) >*/
	*left = fldway_1.fldlt[*tab - 1];
/* SOURCE floodway.for:913 */
/*<       right=fldrt(tab) >*/
	*right = fldway_1.fldrt[*tab - 1];
/* SOURCE floodway.for:914 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:915 */
/*<       return >*/
	return 0;
/* SOURCE floodway.for:916 */
/*<       endif >*/
    }
/* SOURCE floodway.for:918 */
/*<       if(eflag.gt.0)then >*/
    if (*eflag > 0) {
/* SOURCE floodway.for:919 */
/*<        >*/
	feq_gen_io_d__85.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__85);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FLOODWAY COMPUTATIONS SUPPRESSED."), (ftnlen)34)
		;
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ERRORS ENCOUNTERED."), (ftnlen)20);
	e_wsle();
/* SOURCE floodway.for:921 */
/*<       return >*/
	return 0;
/* SOURCE floodway.for:922 */
/*<       endif >*/
    }
/*     RESET THE LEFT AND RIGHT LIMITS IN THE FLOODWAY TABLE */
/* SOURCE floodway.for:926 */
/*<       fldlt(tab)=left >*/
    fldway_1.fldlt[*tab - 1] = *left;
/* SOURCE floodway.for:927 */
/*<       fldrt(tab)=right >*/
    fldway_1.fldrt[*tab - 1] = *right;
/*     COMPUTE THE REDUCTION IN CONVEYENCE RESULTING FROM THE IMPOSITION */
/*     OF THE FLOODWAY LIMITS. */
/*     DETERMINE THE ELEVATION TO USE IN DEFINING THE CONVEYANCE */
/* SOURCE floodway.for:935 */
/*<       if(feqbot(tab).lt.-1.e29)then >*/
    if (fldway_1.feqbot[*tab - 1] < (float)-1e29) {
/* SOURCE floodway.for:936 */
/*<       feqbas=zminu >*/
	feqbas = xscomu_1.zminu;
/* SOURCE floodway.for:937 */
/*<       else >*/
    } else {
/* SOURCE floodway.for:938 */
/*<       feqbas=feqbot(tab) >*/
	feqbas = fldway_1.feqbot[*tab - 1];
/* SOURCE floodway.for:939 */
/*<       endif >*/
    }
/* SOURCE floodway.for:941 */
/*<       zgive=fldelv(tab)-feqbas+zminu >*/
    zgive = static_cast<double>(static_cast<double>(fldway_1.fldelv[*tab - 1]) - feqbas) + xscomu_1.zminu;
/* SOURCE floodway.for:942 */
/*<       if(fldopt(tab).eq.'EQK')then >*/
    if (s_cmp(fldwyc_1.fldopt + (*tab - 1 << 2), const_cast<char*>("EQK"), (ftnlen)4, (ftnlen)3) 
	    == 0) {
/* SOURCE floodway.for:943 */
/*<       zgive=zgive+fldlos(tab) >*/
	zgive += fldway_1.fldlos[*tab - 1];
/* SOURCE floodway.for:944 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' ZGIVE=',ZGIVE */
/*      WRITE(STDOUT,*) ' ZMINU=',ZMINU */
/*      WRITE(STDOUT,*) ' ZMAXU=',ZMAXU */
/*      WRITE(STDOUT,*) ' NPNTU=',NPNTU */
/*      WRITE(STDOUT,*) ' NAVMU=',NAVMU */
/*      WRITE(STDOUT,*) ' NSUBU=',NSUBU */
/*      WRITE(STDOUT,*) ' NFAC=',NFAC */
/*      WRITE(STDOUT,*) 'NU:',(NU(I),I=1,NSUBU) */

/*      DO 9123 I=1,NPNTU */
/*        WRITE(STDOUT,'(F10.1,F10.2,I5)') XU(I), ZU(I), SBU(I) */
/* 9123  CONTINUE */
/* SOURCE floodway.for:959 */
/*<       xl=999999. >*/
    xl = (float)999999.;
/* SOURCE floodway.for:960 */
/*<       xr=-999999. >*/
    xr = (float)-999999.;
/* SOURCE floodway.for:961 */
/*<        >*/
    cxselm_(&zgive, stdout, &xscomu_1.npntu, &xscomu_1.nsubu, &xscomu_1.navmu,
	     &xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu, xscomu_1.zu, 
	    xscomu_1.sbu, nfac, &xl, &xr, xscomu_1.lsnu, xscomu_1.snu, eflag, 
	    xscomu_1.nu, xsv);
/* SOURCE floodway.for:967 */
/*<       ktotal=xsv(5)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = xsv[4];
    ktotal = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE floodway.for:969 */
/*<        >*/
    cxselm_(&zgive, stdout, &xscomu_1.npntu, &xscomu_1.nsubu, &xscomu_1.navmu,
	     &xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu, xscomu_1.zu, 
	    xscomu_1.sbu, nfac, left, right, xscomu_1.lsnu, xscomu_1.snu, 
	    eflag, xscomu_1.nu, xsv);
/* SOURCE floodway.for:974 */
/*<       kpart=xsv(5)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = xsv[4];
    kpart = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE floodway.for:975 */
/*<       area=xsv(3) >*/
    *area = xsv[2];
/*      WRITE(STDOUT,*) ' KTOTAL=',KTOTAL */
/*      WRITE(STDOUT,*) ' KPART=',KPART */
/* SOURCE floodway.for:980 */
/*<       fldlos(tab)=(1.0-kpart/ktotal)/2.0 >*/
    fldway_1.fldlos[*tab - 1] = static_cast<double>((static_cast<double>((float)1.) - static_cast<double>(kpart) / ktotal)) / (float)2.;
/* SOURCE floodway.for:982 */
/*<       write(stdout,50)fldlos(tab) >*/
    feq_gen_io_d__93.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__93);
    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldlos[*tab - 1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE floodway.for:985 */
/*<       return >*/
    return 0;
/* SOURCE floodway.for:986 */
/*<       end >*/
} /* fndway_ */

#ifdef __cplusplus
	}
#endif
