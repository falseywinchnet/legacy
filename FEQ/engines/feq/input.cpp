/* input.f -- translated by f2c (version 20240504).
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

/* COMMON rc_com__ is declared in common.hpp. */

#define feq_gen_rc_com_d_1 feq_gen_rc_com_d_

/* COMMON rc_comc__ is declared in common.hpp. */

#define feq_gen_rc_comc_d_1 feq_gen_rc_comc_d_

/* COMMON brhd_com__ is declared in common.hpp. */

#define feq_gen_brhd_com_d_1 feq_gen_brhd_com_d_

/* COMMON brhd_comc__ is declared in common.hpp. */

#define feq_gen_brhd_comc_d_1 feq_gen_brhd_comc_d_

/* COMMON tabhd_com__ is declared in common.hpp. */

#define feq_gen_tabhd_com_d_1 feq_gen_tabhd_com_d_

/* COMMON tabhd_comc__ is declared in common.hpp. */

#define feq_gen_tabhd_comc_d_1 feq_gen_tabhd_comc_d_

/* COMMON tabbrh_com__ is declared in common.hpp. */

#define feq_gen_tabbrh_com_d_1 feq_gen_tabbrh_com_d_

/* COMMON tabbrh_comc__ is declared in common.hpp. */

#define feq_gen_tabbrh_comc_d_1 feq_gen_tabbrh_comc_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_89 = 89;
static integer feq_gen_c_d_80 = 80;
static integer feq_gen_c_d_40 = 40;
static integer feq_gen_c_d_32 = 32;
static integer feq_gen_c_d_8 = 8;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_4 = 4;

/*     Code for input of various blocks that differ from fixed-format */



/* SOURCE input.for:5 */
/*<        >*/
/* Subroutine */ int feq_gen_get_branch_items_d_(integer *stdout, char *line, integer *
	nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *eflag, 
	integer *idlen, integer *hlidlen, integer *node, char *feq_gen_name_d_, char *
	xtabn, char *xchar, char *zchar, real *ca, real *cd, integer *hl, 
	char *azmc, real *cf, char *ycchar, real *std, real *kadj, char *
	tabid, ftnlen line_len, ftnlen name_len, ftnlen xtabn_len, ftnlen 
	xchar_len, ftnlen zchar_len, ftnlen azmc_len, ftnlen ycchar_len, 
	ftnlen tabid_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:375* Only \002,i3,\002 items given \
in \002,\002Branch-Description.  Need at least five items.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli(), s_cmp(char *, char *, ftnlen, ftnlen), s_wsfi(icilist *)
	    , e_wsfi(), s_rsfi(icilist *), e_rsfi();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer n;
    extern integer feq_gen_nonblank_nonzero_d_(char *, ftnlen);
    integer ie, is;
    char tpc[20], key[16];
    integer itab;
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen), 
	    feq_gen_strip_blanks_and_zeros_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, fmt_50, 0 };


/*     Get the items of data from a branch table input line. */
/* SOURCE input.for:14 */
/*<       implicitnone >*/
/* SOURCE input.for:15 */
/*<        >*/
/* SOURCE input.for:17 */
/*<       realca,cd,cf,std,kadj >*/
/* SOURCE input.for:18 */
/*<        >*/
/*     Local */
/* SOURCE input.for:23 */
/*<       integerie,is,itab,n >*/
/* SOURCE input.for:24 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE input.for:27 */
/*<       integernonblank_nonzero,lenstr >*/
/* SOURCE input.for:28 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE input.for:31 */
/*<    50  >*/
/* ******************************************************************************* */
/* SOURCE input.for:34 */
/*<       if(nitem.lt.5)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
    if (*nitem < 5) {
/* SOURCE input.for:35 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__1.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__1);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE input.for:36 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE input.for:37 */
/*<       endif >*/
    }
/* SOURCE input.for:39 */
/*<       n=1 >*/
    n = 1;
/*     Process the NODE */
/* SOURCE input.for:41 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:42 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:43 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:44 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:46 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE input.for:47 */
/*<       node=0 >*/
	*node = 0;
/* SOURCE input.for:48 */
/*<       else >*/
    } else {
/* SOURCE input.for:49 */
/*<       read(tpc,*)node >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 20;
	feq_gen_ici_d_1.iciunit = tpc;
	feq_gen_ici_d_1.icifmt = 0;
	s_rsli(&feq_gen_ici_d_1);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*node), (ftnlen)sizeof(integer));
	e_rsli();
/* SOURCE input.for:50 */
/*<       endif >*/
    }
/*     Process the node id */
/* SOURCE input.for:53 */
/*<       n=2 >*/
    n = 2;
/* SOURCE input.for:54 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:55 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:56 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:57 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:59 */
/*<       name=tpc >*/
    s_copy(feq_gen_name_d_, tpc, (ftnlen)16, (ftnlen)20);
/*     Process the table id */
/* SOURCE input.for:62 */
/*<       n=3 >*/
    n = 3;
/* SOURCE input.for:63 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:64 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:65 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:66 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:68 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/*     Convert from the table id to an internal number. */
/* SOURCE input.for:70 */
/*<       if(key.ne.' '.and.key(1:1).ne.'-')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0 && *(unsigned char *)key 
	    != '-') {
/*       We have an id given. */
/* SOURCE input.for:72 */
/*<       tabid=key >*/
	s_copy(tabid, key, (ftnlen)16, (ftnlen)16);
/* SOURCE input.for:73 */
/*<       idlen=max(idlen,lenstr(key)) >*/
/* Computing MAX */
	feq_gen_i_d_1 = *idlen, feq_gen_i_d_2 = lenstr_(key, (ftnlen)16);
	*idlen = max(feq_gen_i_d_1,feq_gen_i_d_2);
/* SOURCE input.for:74 */
/*<       callget_internal_tab_number(stdout,key,eflag,itab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &itab, (ftnlen)16);
/* SOURCE input.for:78 */
/*<       write(xtabn,'(I5)')itab >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 5;
	feq_gen_ici_d_1.iciunit = xtabn;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&itab, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE input.for:79 */
/*<       else >*/
    } else {
/* SOURCE input.for:80 */
/*<       tabid=' ' >*/
	s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE input.for:81 */
/*<       xtabn=tpc >*/
	s_copy(xtabn, tpc, (ftnlen)5, (ftnlen)20);
/* SOURCE input.for:82 */
/*<       endif >*/
    }
/*     Process the station */
/* SOURCE input.for:85 */
/*<       n=4 >*/
    n = 4;
/* SOURCE input.for:86 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:87 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:88 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:89 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
    feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:91 */
/*<       xchar=tpc >*/
    s_copy(xchar, tpc, (ftnlen)10, (ftnlen)20);
/*     Process the invert elevation */
/* SOURCE input.for:94 */
/*<       n=5 >*/
    n = 5;
/* SOURCE input.for:95 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:96 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:97 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:98 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
    feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:100 */
/*<       zchar=tpc >*/
    s_copy(zchar, tpc, (ftnlen)16, (ftnlen)20);
/*     Process the local acceleration losses */
/* SOURCE input.for:103 */
/*<       n=6 >*/
    n = 6;
/* SOURCE input.for:104 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE input.for:105 */
/*<       ca=0.0 >*/
	*ca = (float)0.;
/* SOURCE input.for:106 */
/*<       else >*/
    } else {
/* SOURCE input.for:107 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE input.for:108 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:109 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:110 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
	feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:112 */
/*<       if(tpc(1:1).eq.' ')then >*/
	if (*(unsigned char *)tpc == ' ') {
/* SOURCE input.for:113 */
/*<       ca=0.0 >*/
	    *ca = (float)0.;
/* SOURCE input.for:114 */
/*<       else >*/
	} else {
/* SOURCE input.for:115 */
/*<       read(tpc(1:5),'(F5.0)')ca >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 5;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F5.0)");
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&(*ca), (ftnlen)sizeof(real));
	    e_rsfi();
/* SOURCE input.for:116 */
/*<       endif >*/
	}
/* SOURCE input.for:117 */
/*<       endif >*/
    }
/*     Process local decceleration losses */
/* SOURCE input.for:120 */
/*<       n=7 >*/
    n = 7;
/* SOURCE input.for:121 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE input.for:122 */
/*<       cd=0.0 >*/
	*cd = (float)0.;
/* SOURCE input.for:123 */
/*<       else >*/
    } else {
/* SOURCE input.for:124 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE input.for:125 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:126 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:127 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
	feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:129 */
/*<       if(tpc(1:1).eq.' ')then >*/
	if (*(unsigned char *)tpc == ' ') {
/* SOURCE input.for:130 */
/*<       cd=0.0 >*/
	    *cd = (float)0.;
/* SOURCE input.for:131 */
/*<       else >*/
	} else {
/* SOURCE input.for:132 */
/*<       read(tpc(1:5),'(F5.0)')cd >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 5;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F5.0)");
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&(*cd), (ftnlen)sizeof(real));
	    e_rsfi();
/* SOURCE input.for:133 */
/*<       endif >*/
	}
/* SOURCE input.for:134 */
/*<       endif >*/
    }
/*     Process local structure losses */
/* SOURCE input.for:137 */
/*<       n=8 >*/
    n = 8;
/* SOURCE input.for:138 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE input.for:139 */
/*<       hl=0 >*/
	*hl = 0;
/* SOURCE input.for:140 */
/*<       else >*/
    } else {
/* SOURCE input.for:141 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE input.for:142 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:143 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:144 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:146 */
/*<       key=tpc >*/
	s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE input.for:147 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*         We have a reference to a loss table. */
/* SOURCE input.for:149 */
/*<       hlidlen=max(hlidlen,lenstr(key)) >*/
/* Computing MAX */
	    feq_gen_i_d_1 = *hlidlen, feq_gen_i_d_2 = lenstr_(key, (ftnlen)16);
	    *hlidlen = max(feq_gen_i_d_1,feq_gen_i_d_2);
/* SOURCE input.for:150 */
/*<       callget_internal_tab_number(stdout,key,eflag,hl) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, hl, (ftnlen)16);
/* SOURCE input.for:154 */
/*<       else >*/
	} else {
/* SOURCE input.for:155 */
/*<       hl=0.0 >*/
	    *hl = (float)0.;
/* SOURCE input.for:156 */
/*<       endif >*/
	}
/* SOURCE input.for:157 */
/*<       endif >*/
    }
/*     Process the element azimuth */
/* SOURCE input.for:160 */
/*<       n=9 >*/
    n = 9;
/* SOURCE input.for:161 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE input.for:162 */
/*<       azmc=' ' >*/
	s_copy(azmc, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1);
/* SOURCE input.for:163 */
/*<       else >*/
    } else {
/* SOURCE input.for:164 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE input.for:165 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:166 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:167 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
	feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:169 */
/*<       azmc=tpc >*/
	s_copy(azmc, tpc, (ftnlen)5, (ftnlen)20);
/* SOURCE input.for:170 */
/*<       endif >*/
    }
/*     Process the effective area for local inflow-outflow */
/* SOURCE input.for:173 */
/*<       n=10 >*/
    n = 10;
/* SOURCE input.for:174 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE input.for:175 */
/*<       cf=0.0 >*/
	*cf = (float)0.;
/* SOURCE input.for:176 */
/*<       else >*/
    } else {
/* SOURCE input.for:177 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE input.for:178 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:179 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:180 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
	feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:182 */
/*<       if(tpc(1:1).eq.' ')then >*/
	if (*(unsigned char *)tpc == ' ') {
/* SOURCE input.for:183 */
/*<       cf=0.0 >*/
	    *cf = (float)0.;
/* SOURCE input.for:184 */
/*<       else >*/
	} else {
/* SOURCE input.for:185 */
/*<       read(tpc(1:5),'(F5.0)')cf >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 5;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F5.0)");
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&(*cf), (ftnlen)sizeof(real));
	    e_rsfi();
/* SOURCE input.for:186 */
/*<       endif >*/
	}
/* SOURCE input.for:187 */
/*<       endif >*/
    }
/*     Process the distance to the sewer invert */
/* SOURCE input.for:190 */
/*<       n=11 >*/
    n = 11;
/* SOURCE input.for:191 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE input.for:192 */
/*<       ycchar=' ' >*/
	s_copy(ycchar, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE input.for:193 */
/*<       else >*/
    } else {
/* SOURCE input.for:194 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE input.for:195 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:196 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:197 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
	feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:199 */
/*<       ycchar=tpc >*/
	s_copy(ycchar, tpc, (ftnlen)8, (ftnlen)20);
/* SOURCE input.for:200 */
/*<       endif >*/
    }
/*     Process standard flood elevation */
/* SOURCE input.for:203 */
/*<       n=12 >*/
    n = 12;
/* SOURCE input.for:204 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE input.for:205 */
/*<       std=0.0 >*/
	*std = (float)0.;
/* SOURCE input.for:206 */
/*<       else >*/
    } else {
/* SOURCE input.for:207 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE input.for:208 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:209 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:210 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
	feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:212 */
/*<       if(tpc(1:1).eq.' ')then >*/
	if (*(unsigned char *)tpc == ' ') {
/* SOURCE input.for:213 */
/*<       std=0.0 >*/
	    *std = (float)0.;
/* SOURCE input.for:214 */
/*<       else >*/
	} else {
/* SOURCE input.for:215 */
/*<       read(tpc(1:5),'(F5.0)')std >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 5;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F5.0)");
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&(*std), (ftnlen)sizeof(real));
	    e_rsfi();
/* SOURCE input.for:216 */
/*<       endif >*/
	}
/* SOURCE input.for:217 */
/*<       endif >*/
    }
/*     Process conveyance adjustment factor */
/* SOURCE input.for:220 */
/*<       n=13 >*/
    n = 13;
/* SOURCE input.for:221 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE input.for:222 */
/*<       kadj=1.0 >*/
	*kadj = (float)1.;
/* SOURCE input.for:223 */
/*<       else >*/
    } else {
/* SOURCE input.for:224 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE input.for:225 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:226 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:227 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
	feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE input.for:229 */
/*<       if(tpc(1:1).eq.' ')then >*/
	if (*(unsigned char *)tpc == ' ') {
/* SOURCE input.for:230 */
/*<       kadj=1.0 >*/
	    *kadj = (float)1.;
/* SOURCE input.for:231 */
/*<       else >*/
	} else {
/* SOURCE input.for:232 */
/*<       read(tpc(1:10),'(F10.0)')kadj >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 10;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&(*kadj), (ftnlen)sizeof(real));
	    e_rsfi();
/* SOURCE input.for:233 */
/*<       endif >*/
	}
/* SOURCE input.for:234 */
/*<       endif >*/
    }
/* SOURCE input.for:236 */
/*<       return >*/
    return 0;
/* SOURCE input.for:237 */
/*<       end >*/
} /* get_branch_items__ */




/* SOURCE input.for:242 */
/*<       subroutineset_control_source(stdout,mftnum,mnblk,nc_long,eflag,n) >*/
/* Subroutine */ int feq_gen_set_control_source_d_(integer *stdout, integer *mftnum, 
	integer *mnblk, char *feq_gen_nc_long_d_, integer *eflag, integer *n, ftnlen 
	nc_long_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char temp[16];

/*     Processs the references to an operation block number in an */
/*     instruction in the NWMCI. The user can give any of the following */
/*     values in response to this item: */
/*     1. A negative integer      | */
/*                                |-specifies a time series table of a */
/*     2. A negative alphanumeric |   structure setting. */
/*     3. A positive integer */
/*        3.1 >  MNBLK - gives numeric table id for time series table of */
/*                        operation block numbers. */
/*        3.2 <= MNBLK - gives an operation block number */
/*     4. A positive alphanumeric- gives alphanumeric table id for time series */
/*                                 table of operation block numbers. */
/* SOURCE input.for:260 */
/*<       implicitnone >*/
/* SOURCE input.for:261 */
/*<       integerstdout,mftnum,mnblk,eflag,n >*/
/* SOURCE input.for:262 */
/*<       character*16nc_long >*/
/*     Local */
/* SOURCE input.for:267 */
/*<       charactertemp*16 >*/
/* *********************************************************************** */
/* SOURCE input.for:269 */
/*<       if(nc_long(1:1).eq.'-')then >*/
    if (*(unsigned char *)feq_gen_nc_long_d_ == '-') {
/*       Table id.  Strip off leading - */
/* SOURCE input.for:271 */
/*<       temp=nc_long(2:16) >*/
	s_copy(temp, feq_gen_nc_long_d_ + 1, (ftnlen)16, (ftnlen)15);
/* SOURCE input.for:272 */
/*<       callget_internal_tab_number(stdout,temp,eflag,n) >*/
	feq_gen_get_internal_tab_number_d_(stdout, temp, eflag, n, (ftnlen)16);
/* SOURCE input.for:276 */
/*<       n=-n >*/
	*n = -(*n);
/* SOURCE input.for:277 */
/*<       else >*/
    } else {
/*       If not negative, could be a number giving the operation */
/*       block number.  If it cannot be read as an integer, it is a */
/*       time-series table id that gives the operation block numbers */
/*       as a function of time. */
/* SOURCE input.for:282 */
/*<       read(nc_long,'(I5)',err=5431)n >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 16;
	feq_gen_ici_d_1.iciunit = feq_gen_nc_long_d_;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L5431;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*n), (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L5431;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L5431;
	}
/*       Number here.  If it is larger than the current maximum number */
/*       of operation blocks, it is the id for a time-series table that */
/*       gives the operation block numbers to be used for the structure. */
/* SOURCE input.for:287 */
/*<       if(n.gt.mnblk)goto5431 >*/
	if (*n > *mnblk) {
	    goto L5431;
	}
/* SOURCE input.for:289 */
/*<       goto5432 >*/
	goto L5432;
/* SOURCE input.for:290 */
/*<  5431 continue >*/
L5431:
/*       Table id here */
/* SOURCE input.for:292 */
/*<       callget_internal_tab_number(stdout,nc_long,eflag,n) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_, eflag, n, (ftnlen)16);
/*         Increment the internal table number by a value that is */
/*         larger than any internal table number as a signal */
/*         for later processing of the reference to a table */
/*         containing the operation-block numbers. */
/* SOURCE input.for:300 */
/*<       n=n+mftnum+1 >*/
	*n = *n + *mftnum + 1;
/* SOURCE input.for:302 */
/*<  5432 continue >*/
L5432:
/* SOURCE input.for:303 */
/*<       endif >*/
	;
    }
/* SOURCE input.for:304 */
/*<       return >*/
    return 0;
/* SOURCE input.for:305 */
/*<       end >*/
} /* set_control_source__ */




/* SOURCE input.for:309 */
/*<       subroutineset_rcb_defaults() >*/
/* Subroutine */ int feq_gen_set_rcb_defaults_d_()
{
    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to process the */
/*     Run-Control Block values. */
/* SOURCE input.for:314 */
/*<       implicitnone >*/
/* INCLUDE input.for:315 */
/* SOURCE rcblock.cmn:1 */
/*<       integermaxr_rc,hmaxr_rc,maxc_rc >*/
/* SOURCE rcblock.cmn:2 */
/*<       parameter(maxr_rc=80,hmaxr_rc=maxr_rc/2,maxc_rc=32) >*/
/* SOURCE rcblock.cmn:3 */
/*<       integerrcbitab(maxr_rc) >*/
/* SOURCE rcblock.cmn:4 */
/*<       realrcbftab(maxr_rc) >*/
/* SOURCE rcblock.cmn:5 */
/*<       real*8rcbdtab(hmaxr_rc) >*/
/* SOURCE rcblock.cmn:6 */
/*<       character*256rcbctab(maxc_rc) >*/
/* SOURCE rcblock.cmn:8 */
/*<       common/rc_com/rcbdtab,rcbitab,rcbftab >*/
/* SOURCE rcblock.cmn:10 */
/*<       common/rc_comc/rcbctab >*/
/* *********************************************************************** */
/*     Default for: NBRA. Changed from 1 to 0. Version 9.93 */
/* SOURCE input.for:318 */
/*<       rcbitab(1)=0 >*/
    feq_gen_rc_com_d_1.rcbitab[0] = 0;
/*     Default for: NEX. Changed from 2 to 0. Version 9.93 */
/* SOURCE input.for:320 */
/*<       rcbitab(2)=0 >*/
    feq_gen_rc_com_d_1.rcbitab[1] = 0;
/*     Default for: MINPRT */
/* SOURCE input.for:322 */
/*<       rcbitab(3)=0 >*/
    feq_gen_rc_com_d_1.rcbitab[2] = 0;
/*     Default for: LAGTSF */
/* SOURCE input.for:324 */
/*<       rcbitab(4)=0 >*/
    feq_gen_rc_com_d_1.rcbitab[3] = 0;
/*     Default for: DMYEAR */
/* SOURCE input.for:326 */
/*<       rcbitab(5)=1925 >*/
    feq_gen_rc_com_d_1.rcbitab[4] = 1925;
/*     Default for: DMMN */
/* SOURCE input.for:328 */
/*<       rcbitab(6)=1 >*/
    feq_gen_rc_com_d_1.rcbitab[5] = 1;
/*     Default for: ZIY */
/* SOURCE input.for:330 */
/*<       rcbftab(7)=0.0 >*/
    feq_gen_rc_com_d_1.rcbftab[6] = (float)0.;
/*     Default for: SYR */
/* SOURCE input.for:332 */
/*<       rcbitab(8)=1901 >*/
    feq_gen_rc_com_d_1.rcbitab[7] = 1901;
/*     Default for: SMN */
/* SOURCE input.for:334 */
/*<       rcbitab(9)=1 >*/
    feq_gen_rc_com_d_1.rcbitab[8] = 1;
/*     Default for: SDY */
/* SOURCE input.for:336 */
/*<       rcbitab(10)=1 >*/
    feq_gen_rc_com_d_1.rcbitab[9] = 1;
/*     Default for: SFRAC */
/* SOURCE input.for:338 */
/*<       rcbdtab(6)=0.0d0 >*/
    feq_gen_rc_com_d_1.rcbdtab[5] = 0.;
/*     Default for: EYR */
/* SOURCE input.for:340 */
/*<       rcbitab(14)=1900 >*/
    feq_gen_rc_com_d_1.rcbitab[13] = 1900;
/*     Default for: EMN */
/* SOURCE input.for:342 */
/*<       rcbitab(15)=1 >*/
    feq_gen_rc_com_d_1.rcbitab[14] = 1;
/*     Default for: EDY */
/* SOURCE input.for:344 */
/*<       rcbitab(16)=1 >*/
    feq_gen_rc_com_d_1.rcbitab[15] = 1;
/*     Default for: EFRAC */
/* SOURCE input.for:346 */
/*<       rcbdtab(9)=0.0d0 >*/
    feq_gen_rc_com_d_1.rcbdtab[8] = 0.;
/*     Default for: GRAV */
/* SOURCE input.for:348 */
/*<       rcbftab(19)=32.174 >*/
    feq_gen_rc_com_d_1.rcbftab[18] = (float)32.174;
/*     Default for: SSEPS */
/* SOURCE input.for:350 */
/*<       rcbftab(20)=0.1 >*/
    feq_gen_rc_com_d_1.rcbftab[19] = (float).1;
/*     Default for: PAGE */
/* SOURCE input.for:352 */
/*<       rcbitab(21)=24 >*/
    feq_gen_rc_com_d_1.rcbitab[20] = 24;
/*     Default for: EPSSYS */
/* SOURCE input.for:354 */
/*<       rcbftab(22)=0.05 >*/
    feq_gen_rc_com_d_1.rcbftab[21] = (float).05;
/*     Default for: ABSTOL */
/* SOURCE input.for:356 */
/*<       rcbftab(23)=0.000005 >*/
    feq_gen_rc_com_d_1.rcbftab[22] = (float)5e-6;
/*     Default for: EPSFAC */
/* SOURCE input.for:358 */
/*<       rcbftab(24)=2.0 >*/
    feq_gen_rc_com_d_1.rcbftab[23] = (float)2.;
/*     Default for: MKNT */
/* SOURCE input.for:360 */
/*<       rcbitab(25)=5 >*/
    feq_gen_rc_com_d_1.rcbitab[24] = 5;
/*     Default for: NUMLIM */
/* SOURCE input.for:362 */
/*<       rcbitab(26)=0 >*/
    feq_gen_rc_com_d_1.rcbitab[25] = 0;
/*     Default for: OUTPUT */
/* SOURCE input.for:364 */
/*<       rcbitab(27)=0 >*/
    feq_gen_rc_com_d_1.rcbitab[26] = 0;
/*     Default for: PROUT */
/* SOURCE input.for:366 */
/*<       rcbitab(28)=0 >*/
    feq_gen_rc_com_d_1.rcbitab[27] = 0;
/*     Default for: PRTINT */
/* SOURCE input.for:368 */
/*<       rcbitab(29)=1 >*/
    feq_gen_rc_com_d_1.rcbitab[28] = 1;
/*     Default for: YR */
/* SOURCE input.for:370 */
/*<       rcbitab(30)=9999 >*/
    feq_gen_rc_com_d_1.rcbitab[29] = 9999;
/*     Default for: MN */
/* SOURCE input.for:372 */
/*<       rcbitab(31)=12 >*/
    feq_gen_rc_com_d_1.rcbitab[30] = 12;
/*     Default for: DY */
/* SOURCE input.for:374 */
/*<       rcbitab(32)=31 >*/
    feq_gen_rc_com_d_1.rcbitab[31] = 31;
/*     Default for: HR */
/* SOURCE input.for:376 */
/*<       rcbdtab(17)=24.d0 >*/
    feq_gen_rc_com_d_1.rcbdtab[16] = 24.;
/*     Default for: EPSB */
/* SOURCE input.for:378 */
/*<       rcbftab(36)=0.0005 >*/
    feq_gen_rc_com_d_1.rcbftab[35] = (float)5e-4;
/*     Default for: MAXIT */
/* SOURCE input.for:380 */
/*<       rcbitab(38)=30 >*/
    feq_gen_rc_com_d_1.rcbitab[37] = 30;
/*     Default for: SFAC */
/* SOURCE input.for:382 */
/*<       rcbftab(39)=5280. >*/
    feq_gen_rc_com_d_1.rcbftab[38] = (float)5280.;
/*     Default for: TAUFAC */
/* SOURCE input.for:384 */
/*<       rcbftab(40)=1.0 >*/
    feq_gen_rc_com_d_1.rcbftab[39] = (float)1.;
/*     Default for: QEPS */
/* SOURCE input.for:386 */
/*<       rcbftab(41)=1.0 >*/
    feq_gen_rc_com_d_1.rcbftab[40] = (float)1.;
/*     Default for: QCHOP --Special value to get correct units depending on GRAV. */
/* SOURCE input.for:388 */
/*<       rcbftab(42)=-1.0 >*/
    feq_gen_rc_com_d_1.rcbftab[41] = (float)-1.;
/*     Default for: IFRZ */
/* SOURCE input.for:390 */
/*<       rcbitab(43)=1 >*/
    feq_gen_rc_com_d_1.rcbitab[42] = 1;
/*     Default for: DTVEC(1) */
/* SOURCE input.for:392 */
/*<       rcbftab(44)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[43] = (float)300.;
/*     Default for: DTVEC(2) */
/* SOURCE input.for:394 */
/*<       rcbftab(45)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[44] = (float)300.;
/*     Default for: DTVEC(3) */
/* SOURCE input.for:396 */
/*<       rcbftab(46)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[45] = (float)300.;
/*     Default for: DTVEC(4) */
/* SOURCE input.for:398 */
/*<       rcbftab(47)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[46] = (float)300.;
/*     Default for: DTVEC(5) */
/* SOURCE input.for:400 */
/*<       rcbftab(48)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[47] = (float)300.;
/*     Default for: DTVEC(6) */
/* SOURCE input.for:402 */
/*<       rcbftab(49)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[48] = (float)300.;
/*     Default for: DTVEC(7) */
/* SOURCE input.for:404 */
/*<       rcbftab(50)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[49] = (float)300.;
/*     Default for: DTVEC(8) */
/* SOURCE input.for:406 */
/*<       rcbftab(51)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[50] = (float)300.;
/*     Default for: DTVEC(9) */
/* SOURCE input.for:408 */
/*<       rcbftab(52)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[51] = (float)300.;
/*     Default for: DTVEC(10) */
/* SOURCE input.for:410 */
/*<       rcbftab(53)=300.0 >*/
    feq_gen_rc_com_d_1.rcbftab[52] = (float)300.;
/*     Default for: MAXDT */
/* SOURCE input.for:412 */
/*<       rcbftab(54)=1800. >*/
    feq_gen_rc_com_d_1.rcbftab[53] = (float)1800.;
/*     Default for: MINDT */
/* SOURCE input.for:414 */
/*<       rcbftab(55)=1.0 >*/
    feq_gen_rc_com_d_1.rcbftab[54] = (float)1.;
/*     Default for: AUTO */
/* SOURCE input.for:416 */
/*<       rcbftab(56)=0.7 >*/
    feq_gen_rc_com_d_1.rcbftab[55] = (float).7;
/*     Default for: SITER */
/* SOURCE input.for:418 */
/*<       rcbftab(57)=2.8 >*/
    feq_gen_rc_com_d_1.rcbftab[56] = (float)2.8;
/*     Default for: HIGH */
/* SOURCE input.for:420 */
/*<       rcbftab(58)=3.2 >*/
    feq_gen_rc_com_d_1.rcbftab[57] = (float)3.2;
/*     Default for: LOW */
/* SOURCE input.for:422 */
/*<       rcbftab(59)=2.4 >*/
    feq_gen_rc_com_d_1.rcbftab[58] = (float)2.4;
/*     Default for: HFAC */
/* SOURCE input.for:424 */
/*<       rcbftab(60)=2.0 >*/
    feq_gen_rc_com_d_1.rcbftab[59] = (float)2.;
/*     Default for: LFAC */
/* SOURCE input.for:426 */
/*<       rcbftab(61)=0.5 >*/
    feq_gen_rc_com_d_1.rcbftab[60] = (float).5;
/*     Default for: MRE */
/* SOURCE input.for:428 */
/*<       rcbftab(62)=0.20 >*/
    feq_gen_rc_com_d_1.rcbftab[61] = (float).2;
/*     Default for: FAC */
/* SOURCE input.for:430 */
/*<       rcbftab(63)=0.0 >*/
    feq_gen_rc_com_d_1.rcbftab[62] = (float)0.;
/*     Default for: HSLOT */
/* SOURCE input.for:432 */
/*<       rcbftab(64)=0.0 >*/
    feq_gen_rc_com_d_1.rcbftab[63] = (float)0.;
/*     Default for: WSLOT */
/* SOURCE input.for:434 */
/*<       rcbftab(65)=0.0 >*/
    feq_gen_rc_com_d_1.rcbftab[64] = (float)0.;
/*     Default for: NSLOT */
/* SOURCE input.for:436 */
/*<       rcbftab(66)=0.0 >*/
    feq_gen_rc_com_d_1.rcbftab[65] = (float)0.;
/*     Default for: DWT */
/* SOURCE input.for:438 */
/*<       rcbftab(67)=0.1 >*/
    feq_gen_rc_com_d_1.rcbftab[66] = (float).1;
/*     Default for: BWT */
/* SOURCE input.for:440 */
/*<       rcbftab(68)=0.55 >*/
    feq_gen_rc_com_d_1.rcbftab[67] = (float).55;
/*     Default for: EXTTOL */
/* SOURCE input.for:442 */
/*<       rcbftab(69)=0.0 >*/
    feq_gen_rc_com_d_1.rcbftab[68] = (float)0.;
/*     Default for: SQREPS */
/* SOURCE input.for:444 */
/*<       rcbftab(70)=1e30 >*/
    feq_gen_rc_com_d_1.rcbftab[69] = (float)1e30;
/*     Control for detailed printout and dumping of equations added: Feb. 14, 2001 */
/*     Default for: START_EQ */
/* SOURCE input.for:448 */
/*<       rcbitab(71)=2 >*/
    feq_gen_rc_com_d_1.rcbitab[70] = 2;
/*     Default for: END_EQ */
/* SOURCE input.for:450 */
/*<       rcbitab(72)=1 >*/
    feq_gen_rc_com_d_1.rcbitab[71] = 1;
/*     Default for: DTMIN_OUT */
/* SOURCE input.for:452 */
/*<       rcbftab(73)=0.0 >*/
    feq_gen_rc_com_d_1.rcbftab[72] = (float)0.;
/*     High IQ Newton solution control added: Feb. 26, 2003 */
/*     Default for: HI_IQ_NS_DWN */
/* SOURCE input.for:456 */
/*<       rcbftab(74)=0.5 >*/
    feq_gen_rc_com_d_1.rcbftab[73] = (float).5;
/*     Default for: HI_IQ_NS_UP */
/* SOURCE input.for:458 */
/*<       rcbftab(75)=sqrt(1.0/rcbftab(74)) >*/
    feq_gen_rc_com_d_1.rcbftab[74] = sqrt(static_cast<double>((float)1.) / feq_gen_rc_com_d_1.rcbftab[73]);
/*     Default for: HI_IQ_NS_LMT */
/* SOURCE input.for:460 */
/*<       rcbftab(76)=0.1 >*/
    feq_gen_rc_com_d_1.rcbftab[75] = (float).1;
/*     Default for: HI_IQ_NS_NUMGT  added 8 april 2003. */
/*     The default value was near optimum for a test model having 13,808 unknowns! */
/*     I think that a small number will always prove to be optimum no matter the size of the */
/*     model. */
/* SOURCE input.for:465 */
/*<       rcbitab(77)=4 >*/
    feq_gen_rc_com_d_1.rcbitab[76] = 4;
/*     Default for: HI_IQ_NS_KNT */
/* SOURCE input.for:468 */
/*<       rcbitab(78)=25 >*/
    feq_gen_rc_com_d_1.rcbitab[77] = 25;
/*     Default for: HI_IQ_NS_DT */
/* SOURCE input.for:471 */
/*<       rcbftab(79)=40.0 >*/
    feq_gen_rc_com_d_1.rcbftab[78] = (float)40.;
/*     Default for: DZ_FOR_OUTPUT */
/* SOURCE input.for:473 */
/*<       rcbftab(80)=0.0 >*/
    feq_gen_rc_com_d_1.rcbftab[79] = (float)0.;
/*     Default for: SOPER */
/* SOURCE input.for:477 */
/*<       rcbctab(1)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for: POINT */
/* SOURCE input.for:479 */
/*<       rcbctab(2)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 256, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for: DIFFUS */
/* SOURCE input.for:481 */
/*<       rcbctab(3)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 512, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for: WIND */
/* SOURCE input.for:483 */
/*<       rcbctab(4)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 768, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for: UNDERF */
/* SOURCE input.for:485 */
/*<       rcbctab(5)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 1024, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for: NODEID */
/* SOURCE input.for:487 */
/*<       rcbctab(6)='YES' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 1280, const_cast<char*>("YES"), (ftnlen)256, (ftnlen)3);
/*     Default for: GENAME */
/* SOURCE input.for:489 */
/*<       rcbctab(7)='STDX' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 1536, const_cast<char*>("STDX"), (ftnlen)256, (ftnlen)4);
/*     Default for: BWFNAM */
/* SOURCE input.for:491 */
/*<       rcbctab(8)='     ' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 1792, const_cast<char*>("     "), (ftnlen)256, (ftnlen)5);
/*     Default for: CHKGEO */
/* SOURCE input.for:493 */
/*<       rcbctab(9)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 2048, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for: ISTYLE */
/* SOURCE input.for:495 */
/*<       rcbctab(10)='NEW' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 2304, const_cast<char*>("NEW"), (ftnlen)256, (ftnlen)3);
/*     Default for: GETIC */
/* SOURCE input.for:497 */
/*<       rcbctab(11)='   ' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 2560, const_cast<char*>("   "), (ftnlen)256, (ftnlen)3);
/*     Default for: PUTFC */
/* SOURCE input.for:499 */
/*<       rcbctab(12)='   ' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 2816, const_cast<char*>("   "), (ftnlen)256, (ftnlen)3);
/*     Default for OLD_SUMMARY--added June 1999 */
/* SOURCE input.for:501 */
/*<       rcbctab(13)='YES' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 3072, const_cast<char*>("YES"), (ftnlen)256, (ftnlen)3);
/*     Default for GISID_TO_NODEID--added Dec 1999 */
/* SOURCE input.for:503 */
/*<       rcbctab(14)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 3328, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for TABID_TO_NODEID--added Dec 1999 */
/* SOURCE input.for:505 */
/*<       rcbctab(15)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 3584, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for DO_SCHEMATIC--added July 31, 2000 */
/* SOURCE input.for:507 */
/*<       rcbctab(16)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 3840, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for CD14_TAB_DATUM--added August 2, 2000 */
/* SOURCE input.for:509 */
/*<       rcbctab(17)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 4096, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for CDT6_TAB_DATUM--added August 2, 2000 */
/* SOURCE input.for:511 */
/*<       rcbctab(18)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 4352, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for NEW_GENSCN_FEO--Added Sept. 27, 2000 */
/*     Changed to YES 28 March 2006.  GENSCN will be changed! */
/* SOURCE input.for:514 */
/*<       rcbctab(19)='YES' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 4608, const_cast<char*>("YES"), (ftnlen)256, (ftnlen)3);
/*     Default for global HOME value--Added May 17, 2002 */
/* SOURCE input.for:516 */
/*<       rcbctab(20)=' ' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 4864, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1);
/*     Default for HI_IQ_NS value--Added Feb. 26, 2003 */
/* SOURCE input.for:518 */
/*<       rcbctab(21)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 5120, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for TY13_TO_TY43 */
/* SOURCE input.for:520 */
/*<       rcbctab(22)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 5376, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for UPGRADE_XSEC_TAB */
/* SOURCE input.for:522 */
/*<       rcbctab(23)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 5632, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     Default for MAKE_DT_TAB-Added April 7, 2003 */
/* SOURCE input.for:524 */
/*<       rcbctab(24)=' ' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 5888, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1);
/*     Default for USE_MAXDT_TAB */
/* SOURCE input.for:526 */
/*<       rcbctab(25)=' ' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 6144, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1);
/*     Default for forecasting with a DTSF present-added 27 Sept 2005 */
/* SOURCE input.for:528 */
/*<       rcbctab(26)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 6400, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*     The following five values express what FEQ expects or demands to see in the */
/*     header block of function tables it uses. */

/*     Default for the zone of the horizontal grid used to define location */
/*     of a function table */
/* SOURCE input.for:535 */
/*<       rcbctab(27)='NONE' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 6656, const_cast<char*>("NONE"), (ftnlen)256, (ftnlen)4);
/*     Default for the horizontal-grid name defining location. */
/* SOURCE input.for:537 */
/*<       rcbctab(28)='NONE' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 6912, const_cast<char*>("NONE"), (ftnlen)256, (ftnlen)4);
/*       Rules: 1. Zone and hgrid must both be non-NONE if one of them is.  That is, */
/*                 we assume that any hgrid will have some zone designation.  If the one */
/*                 in use does not, well, make one up, and just be consistent! */
/*              2. If non-NONE, FEQ will output a file in the home output directory, that contains */
/*                 a list of all table ids that have a zone/hgrid value that differs from the */
/*                 one given in the run-control block.  The run will continue however, and */
/*                 currently, FEQ makes not direct use of these two values. */
/*             3.  If non-NONE, FEQ will report in a file, the table ids and the easting */
/*                 and northings for all tables that have these values missing and for */
/*                 which FEQ is able to deduce a location by its internal rules.  This */
/*                 information, combined with a table index, requested below, and a utility */
/*                 program, will then update all function tables, to have that easting and */
/*                 northing.  Also, in some cases, the utility program will also update */
/*                 the FEQUTL input used to generate the table so that on the next */
/*                 computation of the table, the easting and northing will be correct. */
/*             4.  If both are NONE, then FEQ ignores any information, if it is present, */
/*                 on the horizontal grid differences in the input tables.  Also nothing */
/*                 is done about missing easting and northing items. */
/*     Default for the name of the vertical datum used for elevations in the table, if any */
/* SOURCE input.for:558 */
/*<       rcbctab(29)='NONE' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 7168, const_cast<char*>("NONE"), (ftnlen)256, (ftnlen)4);
/*       Rules:  1. If NONE, FEQ ignores any information, even if present, in function tables. */
/*                  This is necessary to support models that know nothing about these new features. */
/*               2. If non-NONE, FEQ reports all table ids that disagree in vertical datum and */
/*                  terminates the run!  Mixed datums are deadly:) */
/*               3. Some utilities will be created to help in updating vertical datums.  However, */
/*                  some updates will be manual. */
/*     Default for the unit system used in a function table */
/* SOURCE input.for:567 */
/*<       rcbctab(30)='NONE' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 7424, const_cast<char*>("NONE"), (ftnlen)256, (ftnlen)4);
/*       Rules:  1. If non-NONE, FEQ will report all table ids that differ and terminate */
/*                  the run.  The disparate units will have to be corrected either manually */
/*                  or by using the features present in FEQ to produce a function table in */
/*                  the proper unit system. */
/*     Default for the basis for the information in function tables.  This relates to dates, */
/*       and nature of the basic data. */
/* SOURCE input.for:574 */
/*<       rcbctab(31)='NONE' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 7680, const_cast<char*>("NONE"), (ftnlen)256, (ftnlen)4);
/*       Rules:  1. If non-NONE, FEQ will report those tab ids that differ.  This can then */
/*                  be used to find tables that need to be updated. */
/*               2. The string is only 8 characters long, so be careful in what you pick to */
/*                  describe the basis.  A year and a few well-chosen characters should do it! */
/*     Default for requesting a function-table index */
/* SOURCE input.for:580 */
/*<       rcbctab(32)='NO' >*/
    s_copy(feq_gen_rc_comc_d_1.rcbctab + 7936, const_cast<char*>("NO"), (ftnlen)256, (ftnlen)2);
/*       Rules:  1. If YES, then FEQ will construct an index of table ids, with the ids sorted */
/*                  in whatever sequence Fortran uses for character strings, with the table */
/*                  type, and with the fully qualified file name that contains the table. */
/*                  This table is usable manually, searching with a text editor, or usable */
/*                  by a utility program to find the file that contains a given table id. */
/*                  If standard naming conventions, and locations are used for the input */
/*                  file to FEQUTL, then it could be possible to update the input file */
/*                  that created the function table. */
/* SOURCE input.for:591 */
/*<       return >*/
    return 0;
/* SOURCE input.for:592 */
/*<       end >*/
} /* set_rcb_defaults__ */




/* SOURCE input.for:597 */
/*<        >*/
/* Subroutine */ int feq_gen_set_rcb1_d_(integer *nbra, integer *nex, integer *minprt, 
	integer *lagtsf, integer *dmyear, integer *dmmn, real *ziy, integer *
	syr, integer *smn, integer *sdy, doublereal *sfrac, integer *eyr, 
	integer *emn, integer *edy, doublereal *efrac, real *grav, real *
	sseps, integer *pagesp, real *epssys, real *abstol, real *epsfac, 
	integer *mknt, integer *numlim, integer *output, integer *prout, 
	integer *prtint, integer *yr, integer *mn, integer *dy, doublereal *
	hr, real *epsb, integer *maxit, real *sfac, real *taufac, real *qeps, 
	real *qchop, char *soper, char *point, char *diffus, char *wind, char 
	*underf, char *nodeid, char *gename, char *feq_gen_old_summary_d_, char *
	feq_gen_gisid_to_nodeid_d_, char *feq_gen_tabid_to_nodeid_d_, char *feq_gen_do_schematic_d_, 
	char *feq_gen_cd14_tab_datum_d_, char *feq_gen_cd5t6_tab_datum_d_, char *
	feq_gen_new_genscn_feo_d_, integer *feq_gen_start_eq_d_, integer *feq_gen_end_eq_d_, real *
	feq_gen_dtmin_out_d_, char *feq_gen_glb_home_d_, char *feq_gen_hi_iq_ns_d_, real *feq_gen_hi_iq_ns_dwn_d_,
	 real *feq_gen_hi_iq_ns_up_d_, real *feq_gen_hi_iq_ns_lmt_d_, char *feq_gen_ty13_to_ty43_d_, 
	char *feq_gen_upgrade_xsec_tab_d_, char *feq_gen_make_dt_tab_d_, char *feq_gen_use_maxdt_tab_d_, 
	integer *feq_gen_hi_iq_ns_numgt_d_, integer *feq_gen_hi_iq_ns_knt_d_, real *
	feq_gen_hi_iq_ns_dt_d_, char *feq_gen_frcst_wth_dtsf_d_, char *zone, char *hgrid, char *
	vdatum, char *unitsys, char *basis, char *feq_gen_make_tab_index_d_, real *
	feq_gen_dz_for_output_d_, ftnlen soper_len, ftnlen point_len, ftnlen 
	diffus_len, ftnlen wind_len, ftnlen underf_len, ftnlen nodeid_len, 
	ftnlen gename_len, ftnlen old_summary_len, ftnlen gisid_to_nodeid_len,
	 ftnlen tabid_to_nodeid_len, ftnlen do_schematic_len, ftnlen 
	cd14_tab_datum_len, ftnlen cd5t6_tab_datum_len, ftnlen 
	new_genscn_feo_len, ftnlen glb_home_len, ftnlen hi_iq_ns_len, ftnlen 
	ty13_to_ty43_len, ftnlen upgrade_xsec_tab_len, ftnlen make_dt_tab_len,
	 ftnlen use_maxdt_tab_len, ftnlen frcst_wth_dtsf_len, ftnlen zone_len,
	 ftnlen hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, ftnlen 
	basis_len, ftnlen make_tab_index_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the values in the run-control block in INFO1 */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE input.for:618 */
/*<       implicitnone >*/
/* SOURCE input.for:619 */
/*<        >*/
/* SOURCE input.for:625 */
/*<        >*/
/* SOURCE input.for:630 */
/*<       real*8sfrac,efrac,hr >*/
/* SOURCE input.for:632 */
/*<        >*/
/* INCLUDE input.for:641 */
/* SOURCE rcblock.cmn:1 */
/*<       integermaxr_rc,hmaxr_rc,maxc_rc >*/
/* SOURCE rcblock.cmn:2 */
/*<       parameter(maxr_rc=80,hmaxr_rc=maxr_rc/2,maxc_rc=32) >*/
/* SOURCE rcblock.cmn:3 */
/*<       integerrcbitab(maxr_rc) >*/
/* SOURCE rcblock.cmn:4 */
/*<       realrcbftab(maxr_rc) >*/
/* SOURCE rcblock.cmn:5 */
/*<       real*8rcbdtab(hmaxr_rc) >*/
/* SOURCE rcblock.cmn:6 */
/*<       character*256rcbctab(maxc_rc) >*/
/* SOURCE rcblock.cmn:8 */
/*<       common/rc_com/rcbdtab,rcbitab,rcbftab >*/
/* SOURCE rcblock.cmn:10 */
/*<       common/rc_comc/rcbctab >*/
/* *********************************************************************** */
/* SOURCE input.for:643 */
/*<       nbra=rcbitab(1) >*/
    *nbra = feq_gen_rc_com_d_1.rcbitab[0];
/* SOURCE input.for:644 */
/*<       nex=rcbitab(2) >*/
    *nex = feq_gen_rc_com_d_1.rcbitab[1];
/* SOURCE input.for:645 */
/*<       minprt=rcbitab(3) >*/
    *minprt = feq_gen_rc_com_d_1.rcbitab[2];
/* SOURCE input.for:646 */
/*<       lagtsf=rcbitab(4) >*/
    *lagtsf = feq_gen_rc_com_d_1.rcbitab[3];
/* SOURCE input.for:647 */
/*<       dmyear=rcbitab(5) >*/
    *dmyear = feq_gen_rc_com_d_1.rcbitab[4];
/* SOURCE input.for:648 */
/*<       dmmn=rcbitab(6) >*/
    *dmmn = feq_gen_rc_com_d_1.rcbitab[5];
/* SOURCE input.for:649 */
/*<       ziy=rcbftab(7) >*/
    *ziy = feq_gen_rc_com_d_1.rcbftab[6];
/* SOURCE input.for:650 */
/*<       syr=rcbitab(8) >*/
    *syr = feq_gen_rc_com_d_1.rcbitab[7];
/* SOURCE input.for:651 */
/*<       smn=rcbitab(9) >*/
    *smn = feq_gen_rc_com_d_1.rcbitab[8];
/* SOURCE input.for:652 */
/*<       sdy=rcbitab(10) >*/
    *sdy = feq_gen_rc_com_d_1.rcbitab[9];
/* SOURCE input.for:653 */
/*<       sfrac=rcbdtab(6) >*/
    *sfrac = feq_gen_rc_com_d_1.rcbdtab[5];
/* SOURCE input.for:654 */
/*<       eyr=rcbitab(14) >*/
    *eyr = feq_gen_rc_com_d_1.rcbitab[13];
/* SOURCE input.for:655 */
/*<       emn=rcbitab(15) >*/
    *emn = feq_gen_rc_com_d_1.rcbitab[14];
/* SOURCE input.for:656 */
/*<       edy=rcbitab(16) >*/
    *edy = feq_gen_rc_com_d_1.rcbitab[15];
/* SOURCE input.for:657 */
/*<       efrac=rcbdtab(9) >*/
    *efrac = feq_gen_rc_com_d_1.rcbdtab[8];
/* SOURCE input.for:658 */
/*<       grav=rcbftab(19) >*/
    *grav = feq_gen_rc_com_d_1.rcbftab[18];
/* SOURCE input.for:659 */
/*<       sseps=rcbftab(20) >*/
    *sseps = feq_gen_rc_com_d_1.rcbftab[19];
/* SOURCE input.for:660 */
/*<       pagesp=rcbitab(21) >*/
    *pagesp = feq_gen_rc_com_d_1.rcbitab[20];
/* SOURCE input.for:661 */
/*<       epssys=rcbftab(22) >*/
    *epssys = feq_gen_rc_com_d_1.rcbftab[21];
/* SOURCE input.for:662 */
/*<       abstol=rcbftab(23) >*/
    *abstol = feq_gen_rc_com_d_1.rcbftab[22];
/* SOURCE input.for:663 */
/*<       epsfac=rcbftab(24) >*/
    *epsfac = feq_gen_rc_com_d_1.rcbftab[23];
/* SOURCE input.for:664 */
/*<       mknt=rcbitab(25) >*/
    *mknt = feq_gen_rc_com_d_1.rcbitab[24];
/* SOURCE input.for:665 */
/*<       numlim=rcbitab(26) >*/
    *numlim = feq_gen_rc_com_d_1.rcbitab[25];
/* SOURCE input.for:666 */
/*<       output=rcbitab(27) >*/
    *output = feq_gen_rc_com_d_1.rcbitab[26];
/* SOURCE input.for:667 */
/*<       prout=rcbitab(28) >*/
    *prout = feq_gen_rc_com_d_1.rcbitab[27];
/* SOURCE input.for:668 */
/*<       prtint=rcbitab(29) >*/
    *prtint = feq_gen_rc_com_d_1.rcbitab[28];
/* SOURCE input.for:669 */
/*<       yr=rcbitab(30) >*/
    *yr = feq_gen_rc_com_d_1.rcbitab[29];
/* SOURCE input.for:670 */
/*<       mn=rcbitab(31) >*/
    *mn = feq_gen_rc_com_d_1.rcbitab[30];
/* SOURCE input.for:671 */
/*<       dy=rcbitab(32) >*/
    *dy = feq_gen_rc_com_d_1.rcbitab[31];
/* SOURCE input.for:672 */
/*<       hr=rcbdtab(17) >*/
    *hr = feq_gen_rc_com_d_1.rcbdtab[16];
/* SOURCE input.for:673 */
/*<       epsb=rcbftab(36) >*/
    *epsb = feq_gen_rc_com_d_1.rcbftab[35];
/* SOURCE input.for:674 */
/*<       maxit=rcbitab(38) >*/
    *maxit = feq_gen_rc_com_d_1.rcbitab[37];
/* SOURCE input.for:675 */
/*<       sfac=rcbftab(39) >*/
    *sfac = feq_gen_rc_com_d_1.rcbftab[38];
/* SOURCE input.for:676 */
/*<       taufac=rcbftab(40) >*/
    *taufac = feq_gen_rc_com_d_1.rcbftab[39];
/* SOURCE input.for:677 */
/*<       qeps=rcbftab(41) >*/
    *qeps = feq_gen_rc_com_d_1.rcbftab[40];
/* SOURCE input.for:678 */
/*<       qchop=rcbftab(42) >*/
    *qchop = feq_gen_rc_com_d_1.rcbftab[41];
/* SOURCE input.for:679 */
/*<       start_eq=rcbitab(71) >*/
    *feq_gen_start_eq_d_ = feq_gen_rc_com_d_1.rcbitab[70];
/* SOURCE input.for:680 */
/*<       end_eq=rcbitab(72) >*/
    *feq_gen_end_eq_d_ = feq_gen_rc_com_d_1.rcbitab[71];
/* SOURCE input.for:681 */
/*<       dtmin_out=rcbftab(73) >*/
    *feq_gen_dtmin_out_d_ = feq_gen_rc_com_d_1.rcbftab[72];
/* SOURCE input.for:682 */
/*<       hi_iq_ns_dwn=rcbftab(74) >*/
    *feq_gen_hi_iq_ns_dwn_d_ = feq_gen_rc_com_d_1.rcbftab[73];
/* SOURCE input.for:683 */
/*<       hi_iq_ns_up=rcbftab(75) >*/
    *feq_gen_hi_iq_ns_up_d_ = feq_gen_rc_com_d_1.rcbftab[74];
/* SOURCE input.for:684 */
/*<       hi_iq_ns_lmt=rcbftab(76) >*/
    *feq_gen_hi_iq_ns_lmt_d_ = feq_gen_rc_com_d_1.rcbftab[75];
/* SOURCE input.for:685 */
/*<       hi_iq_ns_numgt=rcbitab(77) >*/
    *feq_gen_hi_iq_ns_numgt_d_ = feq_gen_rc_com_d_1.rcbitab[76];
/* SOURCE input.for:686 */
/*<       hi_iq_ns_knt=rcbitab(78) >*/
    *feq_gen_hi_iq_ns_knt_d_ = feq_gen_rc_com_d_1.rcbitab[77];
/* SOURCE input.for:687 */
/*<       hi_iq_ns_dt=rcbftab(79) >*/
    *feq_gen_hi_iq_ns_dt_d_ = feq_gen_rc_com_d_1.rcbftab[78];
/* SOURCE input.for:688 */
/*<       dz_for_output=rcbftab(80) >*/
    *feq_gen_dz_for_output_d_ = feq_gen_rc_com_d_1.rcbftab[79];
/* SOURCE input.for:690 */
/*<       soper=rcbctab(1) >*/
    s_copy(soper, feq_gen_rc_comc_d_1.rcbctab, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:691 */
/*<       point=rcbctab(2) >*/
    s_copy(point, feq_gen_rc_comc_d_1.rcbctab + 256, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:692 */
/*<       diffus=rcbctab(3) >*/
    s_copy(diffus, feq_gen_rc_comc_d_1.rcbctab + 512, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:693 */
/*<       wind=rcbctab(4) >*/
    s_copy(wind, feq_gen_rc_comc_d_1.rcbctab + 768, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:694 */
/*<       underf=rcbctab(5) >*/
    s_copy(underf, feq_gen_rc_comc_d_1.rcbctab + 1024, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:695 */
/*<       nodeid=rcbctab(6) >*/
    s_copy(nodeid, feq_gen_rc_comc_d_1.rcbctab + 1280, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:696 */
/*<       gename=rcbctab(7) >*/
    s_copy(gename, feq_gen_rc_comc_d_1.rcbctab + 1536, (ftnlen)5, (ftnlen)256);
/* SOURCE input.for:697 */
/*<       old_summary=rcbctab(13) >*/
    s_copy(feq_gen_old_summary_d_, feq_gen_rc_comc_d_1.rcbctab + 3072, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:698 */
/*<       gisid_to_nodeid=rcbctab(14) >*/
    s_copy(feq_gen_gisid_to_nodeid_d_, feq_gen_rc_comc_d_1.rcbctab + 3328, (ftnlen)4, (ftnlen)
	    256);
/* SOURCE input.for:699 */
/*<       tabid_to_nodeid=rcbctab(15) >*/
    s_copy(feq_gen_tabid_to_nodeid_d_, feq_gen_rc_comc_d_1.rcbctab + 3584, (ftnlen)4, (ftnlen)
	    256);
/* SOURCE input.for:700 */
/*<       do_schematic=rcbctab(16) >*/
    s_copy(feq_gen_do_schematic_d_, feq_gen_rc_comc_d_1.rcbctab + 3840, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:701 */
/*<       cd14_tab_datum=rcbctab(17) >*/
    s_copy(feq_gen_cd14_tab_datum_d_, feq_gen_rc_comc_d_1.rcbctab + 4096, (ftnlen)4, (ftnlen)
	    256);
/* SOURCE input.for:702 */
/*<       cd5t6_tab_datum=rcbctab(18) >*/
    s_copy(feq_gen_cd5t6_tab_datum_d_, feq_gen_rc_comc_d_1.rcbctab + 4352, (ftnlen)4, (ftnlen)
	    256);
/* SOURCE input.for:703 */
/*<       new_genscn_feo=rcbctab(19) >*/
    s_copy(feq_gen_new_genscn_feo_d_, feq_gen_rc_comc_d_1.rcbctab + 4608, (ftnlen)4, (ftnlen)
	    256);
/* SOURCE input.for:704 */
/*<       glb_home=rcbctab(20) >*/
    s_copy(feq_gen_glb_home_d_, feq_gen_rc_comc_d_1.rcbctab + 4864, (ftnlen)128, (ftnlen)256);
/* SOURCE input.for:705 */
/*<       hi_iq_ns=rcbctab(21) >*/
    s_copy(feq_gen_hi_iq_ns_d_, feq_gen_rc_comc_d_1.rcbctab + 5120, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:706 */
/*<       ty13_to_ty43=rcbctab(22) >*/
    s_copy(feq_gen_ty13_to_ty43_d_, feq_gen_rc_comc_d_1.rcbctab + 5376, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:707 */
/*<       upgrade_xsec_tab=rcbctab(23) >*/
    s_copy(feq_gen_upgrade_xsec_tab_d_, feq_gen_rc_comc_d_1.rcbctab + 5632, (ftnlen)4, (ftnlen)
	    256);
/* SOURCE input.for:708 */
/*<       make_dt_tab=rcbctab(24) >*/
    s_copy(feq_gen_make_dt_tab_d_, feq_gen_rc_comc_d_1.rcbctab + 5888, (ftnlen)256, (ftnlen)256)
	    ;
/* SOURCE input.for:709 */
/*<       use_maxdt_tab=rcbctab(25) >*/
    s_copy(feq_gen_use_maxdt_tab_d_, feq_gen_rc_comc_d_1.rcbctab + 6144, (ftnlen)16, (ftnlen)
	    256);
/* SOURCE input.for:710 */
/*<       frcst_wth_dtsf=rcbctab(26) >*/
    s_copy(feq_gen_frcst_wth_dtsf_d_, feq_gen_rc_comc_d_1.rcbctab + 6400, (ftnlen)4, (ftnlen)
	    256);
/* SOURCE input.for:711 */
/*<       zone=rcbctab(27) >*/
    s_copy(zone, feq_gen_rc_comc_d_1.rcbctab + 6656, (ftnlen)8, (ftnlen)256);
/* SOURCE input.for:712 */
/*<       hgrid=rcbctab(28) >*/
    s_copy(hgrid, feq_gen_rc_comc_d_1.rcbctab + 6912, (ftnlen)8, (ftnlen)256);
/* SOURCE input.for:713 */
/*<       vdatum=rcbctab(29) >*/
    s_copy(vdatum, feq_gen_rc_comc_d_1.rcbctab + 7168, (ftnlen)8, (ftnlen)256);
/* SOURCE input.for:714 */
/*<       unitsys=rcbctab(30) >*/
    s_copy(unitsys, feq_gen_rc_comc_d_1.rcbctab + 7424, (ftnlen)8, (ftnlen)256);
/* SOURCE input.for:715 */
/*<       basis=rcbctab(31) >*/
    s_copy(basis, feq_gen_rc_comc_d_1.rcbctab + 7680, (ftnlen)8, (ftnlen)256);
/* SOURCE input.for:716 */
/*<       make_tab_index=rcbctab(32) >*/
    s_copy(feq_gen_make_tab_index_d_, feq_gen_rc_comc_d_1.rcbctab + 7936, (ftnlen)4, (ftnlen)
	    256);
/* SOURCE input.for:718 */
/*<       return >*/
    return 0;
/* SOURCE input.for:719 */
/*<       end >*/
} /* set_rcb1__ */

/* SOURCE input.for:721 */
/*<        >*/
/* Subroutine */ int feq_gen_set_rcb2_d_(integer *ifrz, real *feq_storage_dtvec, real *maxdt, real 
	*mindt, real *feq_gen_auto_d_, real *siter, real *high, real *low, real *hfac, 
	real *lfac, real *mre, real *fac, real *hslot, real *wslot, real *
	nslot, real *dwt, real *bwt, real *exttol, real *sqreps, char *bwfnam,
	 char *chkgeo, char *istyle, char *getic, char *putfc, ftnlen 
	bwfnam_len, ftnlen chkgeo_len, ftnlen istyle_len, ftnlen getic_len, 
	ftnlen putfc_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_clear_home_d_(), feq_gen_maybe_add_ghome_out_d_(char *, 
	    ftnlen), feq_gen_maybe_add_ext_d_(char *, ftnlen), feq_gen_os_file_style_d_(char *, 
	    ftnlen);

/*     Transfer values into INFO2 */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE input.for:732 */
/*<       implicitnone >*/
/* SOURCE input.for:734 */
/*<       integerifrz >*/
/* SOURCE input.for:736 */
/*<        >*/
/* SOURCE input.for:741 */
/*<       characterbwfnam*256,chkgeo*4,istyle*4,getic*256,putfc*256 >*/
/* INCLUDE input.for:744 */
/* SOURCE rcblock.cmn:1 */
/*<       integermaxr_rc,hmaxr_rc,maxc_rc >*/
/* SOURCE rcblock.cmn:2 */
/*<       parameter(maxr_rc=80,hmaxr_rc=maxr_rc/2,maxc_rc=32) >*/
/* SOURCE rcblock.cmn:3 */
/*<       integerrcbitab(maxr_rc) >*/
/* SOURCE rcblock.cmn:4 */
/*<       realrcbftab(maxr_rc) >*/
/* SOURCE rcblock.cmn:5 */
/*<       real*8rcbdtab(hmaxr_rc) >*/
/* SOURCE rcblock.cmn:6 */
/*<       character*256rcbctab(maxc_rc) >*/
/* SOURCE rcblock.cmn:8 */
/*<       common/rc_com/rcbdtab,rcbitab,rcbftab >*/
/* SOURCE rcblock.cmn:10 */
/*<       common/rc_comc/rcbctab >*/
/* ******************************************************************************* */
/*     Force local home name to blank */
/* SOURCE input.for:748 */
/*<       callclear_home() >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> dtvec(feq_storage_dtvec, 1);

    /* Function Body */
    feq_gen_clear_home_d_();
/*     After the first call to MAYBE_ADD_HOME the local home will be the same */
/*     as the global home.  This is ok here, but may not be elsewhere! */
/* SOURCE input.for:751 */
/*<       ifrz=rcbitab(43) >*/
    *ifrz = feq_gen_rc_com_d_1.rcbitab[42];
/* SOURCE input.for:752 */
/*<       dtvec(1)=rcbftab(44) >*/
    dtvec[1] = feq_gen_rc_com_d_1.rcbftab[43];
/* SOURCE input.for:753 */
/*<       dtvec(2)=rcbftab(45) >*/
    dtvec[2] = feq_gen_rc_com_d_1.rcbftab[44];
/* SOURCE input.for:754 */
/*<       dtvec(3)=rcbftab(46) >*/
    dtvec[3] = feq_gen_rc_com_d_1.rcbftab[45];
/* SOURCE input.for:755 */
/*<       dtvec(4)=rcbftab(47) >*/
    dtvec[4] = feq_gen_rc_com_d_1.rcbftab[46];
/* SOURCE input.for:756 */
/*<       dtvec(5)=rcbftab(48) >*/
    dtvec[5] = feq_gen_rc_com_d_1.rcbftab[47];
/* SOURCE input.for:757 */
/*<       dtvec(6)=rcbftab(49) >*/
    dtvec[6] = feq_gen_rc_com_d_1.rcbftab[48];
/* SOURCE input.for:758 */
/*<       dtvec(7)=rcbftab(50) >*/
    dtvec[7] = feq_gen_rc_com_d_1.rcbftab[49];
/* SOURCE input.for:759 */
/*<       dtvec(8)=rcbftab(51) >*/
    dtvec[8] = feq_gen_rc_com_d_1.rcbftab[50];
/* SOURCE input.for:760 */
/*<       dtvec(9)=rcbftab(52) >*/
    dtvec[9] = feq_gen_rc_com_d_1.rcbftab[51];
/* SOURCE input.for:761 */
/*<       dtvec(10)=rcbftab(53) >*/
    dtvec[10] = feq_gen_rc_com_d_1.rcbftab[52];
/* SOURCE input.for:762 */
/*<       maxdt=rcbftab(54) >*/
    *maxdt = feq_gen_rc_com_d_1.rcbftab[53];
/* SOURCE input.for:763 */
/*<       mindt=rcbftab(55) >*/
    *mindt = feq_gen_rc_com_d_1.rcbftab[54];
/* SOURCE input.for:764 */
/*<       auto=rcbftab(56) >*/
    *feq_gen_auto_d_ = feq_gen_rc_com_d_1.rcbftab[55];
/* SOURCE input.for:765 */
/*<       siter=rcbftab(57) >*/
    *siter = feq_gen_rc_com_d_1.rcbftab[56];
/* SOURCE input.for:766 */
/*<       high=rcbftab(58) >*/
    *high = feq_gen_rc_com_d_1.rcbftab[57];
/* SOURCE input.for:767 */
/*<       low=rcbftab(59) >*/
    *low = feq_gen_rc_com_d_1.rcbftab[58];
/* SOURCE input.for:768 */
/*<       hfac=rcbftab(60) >*/
    *hfac = feq_gen_rc_com_d_1.rcbftab[59];
/* SOURCE input.for:769 */
/*<       lfac=rcbftab(61) >*/
    *lfac = feq_gen_rc_com_d_1.rcbftab[60];
/* SOURCE input.for:770 */
/*<       mre=rcbftab(62) >*/
    *mre = feq_gen_rc_com_d_1.rcbftab[61];
/* SOURCE input.for:771 */
/*<       fac=rcbftab(63) >*/
    *fac = feq_gen_rc_com_d_1.rcbftab[62];
/* SOURCE input.for:772 */
/*<       hslot=rcbftab(64) >*/
    *hslot = feq_gen_rc_com_d_1.rcbftab[63];
/* SOURCE input.for:773 */
/*<       wslot=rcbftab(65) >*/
    *wslot = feq_gen_rc_com_d_1.rcbftab[64];
/* SOURCE input.for:774 */
/*<       nslot=rcbftab(66) >*/
    *nslot = feq_gen_rc_com_d_1.rcbftab[65];
/* SOURCE input.for:775 */
/*<       dwt=rcbftab(67) >*/
    *dwt = feq_gen_rc_com_d_1.rcbftab[66];
/* SOURCE input.for:776 */
/*<       bwt=rcbftab(68) >*/
    *bwt = feq_gen_rc_com_d_1.rcbftab[67];
/* SOURCE input.for:777 */
/*<       exttol=rcbftab(69) >*/
    *exttol = feq_gen_rc_com_d_1.rcbftab[68];
/* SOURCE input.for:778 */
/*<       sqreps=rcbftab(70) >*/
    *sqreps = feq_gen_rc_com_d_1.rcbftab[69];
/* SOURCE input.for:779 */
/*<       bwfnam=rcbctab(8) >*/
    s_copy(bwfnam, feq_gen_rc_comc_d_1.rcbctab + 1792, (ftnlen)256, (ftnlen)256);
/* SOURCE input.for:780 */
/*<       callmaybe_add_ghome_out(bwfnam) >*/
    feq_gen_maybe_add_ghome_out_d_(bwfnam, (ftnlen)256);
/* SOURCE input.for:782 */
/*<       callmaybe_add_ext(bwfnam) >*/
    feq_gen_maybe_add_ext_d_(bwfnam, (ftnlen)256);
/* SOURCE input.for:784 */
/*<       callos_file_style(bwfnam) >*/
    feq_gen_os_file_style_d_(bwfnam, (ftnlen)256);
/* SOURCE input.for:786 */
/*<       chkgeo=rcbctab(9) >*/
    s_copy(chkgeo, feq_gen_rc_comc_d_1.rcbctab + 2048, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:787 */
/*<       istyle=rcbctab(10) >*/
    s_copy(istyle, feq_gen_rc_comc_d_1.rcbctab + 2304, (ftnlen)4, (ftnlen)256);
/* SOURCE input.for:788 */
/*<       getic=rcbctab(11) >*/
    s_copy(getic, feq_gen_rc_comc_d_1.rcbctab + 2560, (ftnlen)256, (ftnlen)256);
/*     Note: A global output home name is added to the getic name because */
/*           this file can only be created by a previous run of FEQ.  Therefore, */
/*           if a global output home name is present, that file will be in the */
/*           output location.  The user must add any additional extension to */
/*           read the proper file.  Therefore we do not add an extension because */
/*           it could be the wrong one! */
/* SOURCE input.for:795 */
/*<       callmaybe_add_ghome_out(getic) >*/
    feq_gen_maybe_add_ghome_out_d_(getic, (ftnlen)256);
/* SOURCE input.for:797 */
/*<       callos_file_style(getic) >*/
    feq_gen_os_file_style_d_(getic, (ftnlen)256);
/* SOURCE input.for:799 */
/*<       putfc=rcbctab(12) >*/
    s_copy(putfc, feq_gen_rc_comc_d_1.rcbctab + 2816, (ftnlen)256, (ftnlen)256);
/* SOURCE input.for:800 */
/*<       callmaybe_add_ghome_out(putfc) >*/
    feq_gen_maybe_add_ghome_out_d_(putfc, (ftnlen)256);
/* SOURCE input.for:802 */
/*<       callmaybe_add_ext(putfc) >*/
    feq_gen_maybe_add_ext_d_(putfc, (ftnlen)256);
/* SOURCE input.for:805 */
/*<       callos_file_style(putfc) >*/
    feq_gen_os_file_style_d_(putfc, (ftnlen)256);
/* SOURCE input.for:807 */
/*<       return >*/
    return 0;
/* SOURCE input.for:808 */
/*<       end >*/
} /* set_rcb2__ */

/*     *********** */
/*     *         * */
/*     * GET_RCB */
/*     *         * */
/*     *********** */
/* SOURCE input.for:817 */
/*<       subroutineget_rcb(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_rcb_d_(integer *stdin, integer *stdout, integer *
	eflag)
{
    /* Initialized data */

    static integer group[89] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
	    1,1,2,2,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,
	    0 };
    static integer feq_gen_group_index_d_[89] = { 1,2,3,4,5,6,7,8,14,19,20,21,22,23,24,
	    25,26,27,28,29,30,36,38,39,40,41,42,43,54,55,56,57,58,59,60,61,62,
	    63,64,65,66,67,68,69,70,1,2,3,4,5,6,7,8,9,10,11,12,0,0,13,14,15,
	    16,17,18,19,71,72,73,20,21,74,75,76,22,23,24,25,77,78,79,26,27,28,
	    29,30,31,32,80 };
    static integer feq_gen_response_type_d_[89] = { 1,1,1,1,1,1,2,7,7,2,2,1,2,2,2,1,1,
	    1,1,1,7,2,1,2,2,2,2,8,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,
	    4,4,4,4,4,4,4,0,0,4,4,4,4,4,4,4,1,1,2,4,4,2,2,2,4,4,4,4,1,1,2,4,4,
	    4,4,4,4,4,2 };
    static integer feq_gen_convert_rule_d_[89] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
	    0,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,1,1,
	    1,1,1,0,1 };
    static char feq_gen_symbol_table_d_[16*89+1] = "NBRA            NEX             M\
INPRT          LAGTSF          DMYEAR          DMMN            ZL           \
   STIME           ETIME           GRAV            SSEPS           PAGE     \
       EPSSYS          ABSTOL          EPSFAC          MKNT            NUMGT\
           OUTPUT          PROUT           PRTINT          DPTIME          E\
PSB            MAXIT           SFAC            TAUFAC          QSMALL       \
   QCHOP           IFRZ            MAXDT           MINDT           AUTO     \
       SITER           HIGH            LOW             HFAC            LFAC \
           MRE             FAC             HSLOT           WSLOT           N\
SLOT           DWT             BWT             EXTTOL          SQREPS       \
   SOPER           POINT           DIFFUS          WIND            UNDERFLOW\
       NODEID          GEQOPT          BWFDSN          CHKGEO          ISTYL\
E          GETIC           PUTFC           FUNCTION        BRANCH          O\
LD_SUMMARY     GISID_TO_NODEID TABID_TO_NODEID DO_SCHEMATIC    CD14_TAB_DATU\
M  CD5T6_TAB_DATUM NEW_GENSCN_FEO  START_EQ        END_EQ          DTMIN_OUT\
       HOME            HI_IQ_NS        HI_IQ_NS_DWN    HI_IQ_NS_UP     HI_IQ\
_NS_LMT    TY13_TO_TY43    UPGRADE_XSEC_TABMAKE_DT_TAB     USE_MAXDT_TAB   H\
I_IQ_NS_NUMGT  HI_IQ_NS_KNT    HI_IQ_NS_DT     FRCST_WTH_DTSF  G_ZONE       \
   G_HGRID         G_VDATUM        G_UNITSYS       G_BASIS         MAKE_TAB_\
INDEX  DZ_FOR_OUTPUT   ";

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_rcb_defaults_d_(), feq_gen_get_named_items_d_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, integer *, real *, doublereal *, char *, integer *, 
	    ftnlen, ftnlen, ftnlen);

/*     Get the values from the run-control block */
/* SOURCE input.for:822 */
/*<       implicitnone >*/
/*      INCLUDE 'arsize.prm' */
/* SOURCE input.for:826 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE input.for:828 */
/* SOURCE rcblock.cmn:1 */
/*<       integermaxr_rc,hmaxr_rc,maxc_rc >*/
/* SOURCE rcblock.cmn:2 */
/*<       parameter(maxr_rc=80,hmaxr_rc=maxr_rc/2,maxc_rc=32) >*/
/* SOURCE rcblock.cmn:3 */
/*<       integerrcbitab(maxr_rc) >*/
/* SOURCE rcblock.cmn:4 */
/*<       realrcbftab(maxr_rc) >*/
/* SOURCE rcblock.cmn:5 */
/*<       real*8rcbdtab(hmaxr_rc) >*/
/* SOURCE rcblock.cmn:6 */
/*<       character*256rcbctab(maxc_rc) >*/
/* SOURCE rcblock.cmn:8 */
/*<       common/rc_com/rcbdtab,rcbitab,rcbftab >*/
/* SOURCE rcblock.cmn:10 */
/*<       common/rc_comc/rcbctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE input.for:833 */
/*<       integern_symbol >*/
/* SOURCE input.for:835 */
/*<       parameter(n_symbol=89) >*/
/* SOURCE input.for:836 */
/*<        >*/
/* SOURCE input.for:839 */
/*<        >*/
/* SOURCE input.for:844 */
/*<       integermax_line >*/
/* SOURCE input.for:847 */
/*<       externalset_rcb_defaults,get_named_items >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE input.for:850 */
/*<        >*/
/* SOURCE input.for:852 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE input.for:854 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE input.for:858 */
/*<        >*/
/* SOURCE input.for:875 */
/*<        >*/
/* SOURCE input.for:887 */
/*<        >*/
/* SOURCE input.for:894 */
/*<        >*/
/* SOURCE input.for:906 */
/*<        >*/
/* SOURCE input.for:920 */
/*<       callset_rcb_defaults() >*/
    feq_gen_set_rcb_defaults_d_();
/* SOURCE input.for:922 */
/*<       max_line=1000 >*/
    feq_gen_max_line_d_ = 1000;
/* SOURCE input.for:923 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_89, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_80, &feq_gen_c_d_40, &feq_gen_c_d_32, const_cast<char*>("Run-Control Block"), feq_gen_rc_com_d_1.rcbitab, 
	    feq_gen_rc_com_d_1.rcbftab, feq_gen_rc_com_d_1.rcbdtab, feq_gen_rc_comc_d_1.rcbctab, eflag, (
	    ftnlen)16, (ftnlen)17, (ftnlen)256);
/* SOURCE input.for:930 */
/*<       return >*/
    return 0;
/* SOURCE input.for:931 */
/*<       end >*/
} /* get_rcb__ */




/* SOURCE input.for:935 */
/*<       subroutineset_brhd_defaults() >*/
/* Subroutine */ int feq_gen_set_brhd_defaults_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to process a */
/*     branch header line */
/* SOURCE input.for:939 */
/*<       implicitnone >*/
/* INCLUDE input.for:940 */
/* SOURCE brhd.cmn:1 */
/*<       integermaxr_brhd,maxc_brhd,maxdp_brhd >*/
/* SOURCE brhd.cmn:2 */
/*<       parameter(maxr_brhd=5,maxc_brhd=1,maxdp_brhd=1) >*/
/* SOURCE brhd.cmn:3 */
/*<       integerbrhditab(maxr_brhd) >*/
/* SOURCE brhd.cmn:4 */
/*<       realbrhdftab(maxr_brhd) >*/
/* SOURCE brhd.cmn:5 */
/*<       real*8brhddtab(maxdp_brhd) >*/
/* SOURCE brhd.cmn:6 */
/*<       character*256brhdctab(maxc_brhd) >*/
/* SOURCE brhd.cmn:8 */
/*<       common/brhd_com/brhddtab,brhditab,brhdftab >*/
/* SOURCE brhd.cmn:10 */
/*<       common/brhd_comc/brhdctab >*/
/* *********************************************************************** */
/*     Default for: BNIN */
/* SOURCE input.for:944 */
/*<       brhditab(1)=1 >*/
    feq_gen_brhd_com_d_1.brhditab[0] = 1;
/*     Default for: INERT */
/* SOURCE input.for:946 */
/*<       brhdftab(2)=1.0 >*/
    feq_gen_brhd_com_d_1.brhdftab[1] = (float)1.;
/*     Default for: CFRATE */
/* SOURCE input.for:948 */
/*<       brhdftab(3)=0.0 >*/
    feq_gen_brhd_com_d_1.brhdftab[2] = (float)0.;
/*     Default for: WDFAC */
/* SOURCE input.for:950 */
/*<       brhdftab(4)=1.0 >*/
    feq_gen_brhd_com_d_1.brhdftab[3] = (float)1.;
/*     Default for: ADDNOD */
/* SOURCE input.for:952 */
/*<       brhditab(5)=0 >*/
    feq_gen_brhd_com_d_1.brhditab[4] = 0;
/*     Default for: GENAME */
/* SOURCE input.for:954 */
/*<       brhdctab(1)='    ' >*/
    s_copy(feq_gen_brhd_comc_d_1.brhdctab, const_cast<char*>("    "), (ftnlen)256, (ftnlen)4);
/* SOURCE input.for:955 */
/*<       return >*/
    return 0;
/* SOURCE input.for:956 */
/*<       end >*/
} /* set_brhd_defaults__ */




/* SOURCE input.for:960 */
/*<       subroutineset_brhd(bnin,inert,cfrate,wdfac,addnod,gename) >*/
/* Subroutine */ int feq_gen_set_brhd_d_(integer *bnin, real *inert, real *cfrate, 
	real *wdfac, integer *addnod, char *gename, ftnlen gename_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the values in the run-control block in INFO1 */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE input.for:965 */
/*<       implicitnone >*/
/* SOURCE input.for:967 */
/*<       integerbnin,addnod >*/
/* SOURCE input.for:968 */
/*<       realinert,cfrate,wdfac >*/
/* SOURCE input.for:969 */
/*<       charactergename*5 >*/
/* INCLUDE input.for:972 */
/* SOURCE brhd.cmn:1 */
/*<       integermaxr_brhd,maxc_brhd,maxdp_brhd >*/
/* SOURCE brhd.cmn:2 */
/*<       parameter(maxr_brhd=5,maxc_brhd=1,maxdp_brhd=1) >*/
/* SOURCE brhd.cmn:3 */
/*<       integerbrhditab(maxr_brhd) >*/
/* SOURCE brhd.cmn:4 */
/*<       realbrhdftab(maxr_brhd) >*/
/* SOURCE brhd.cmn:5 */
/*<       real*8brhddtab(maxdp_brhd) >*/
/* SOURCE brhd.cmn:6 */
/*<       character*256brhdctab(maxc_brhd) >*/
/* SOURCE brhd.cmn:8 */
/*<       common/brhd_com/brhddtab,brhditab,brhdftab >*/
/* SOURCE brhd.cmn:10 */
/*<       common/brhd_comc/brhdctab >*/
/* *********************************************************************** */
/* SOURCE input.for:974 */
/*<       bnin=brhditab(1) >*/
    *bnin = feq_gen_brhd_com_d_1.brhditab[0];
/* SOURCE input.for:975 */
/*<       inert=brhdftab(2) >*/
    *inert = feq_gen_brhd_com_d_1.brhdftab[1];
/* SOURCE input.for:976 */
/*<       cfrate=brhdftab(3) >*/
    *cfrate = feq_gen_brhd_com_d_1.brhdftab[2];
/* SOURCE input.for:977 */
/*<       wdfac=brhdftab(4) >*/
    *wdfac = feq_gen_brhd_com_d_1.brhdftab[3];
/* SOURCE input.for:978 */
/*<       addnod=brhditab(5) >*/
    *addnod = feq_gen_brhd_com_d_1.brhditab[4];
/* SOURCE input.for:979 */
/*<       gename=brhdctab(1) >*/
    s_copy(gename, feq_gen_brhd_comc_d_1.brhdctab, (ftnlen)5, (ftnlen)256);
/* SOURCE input.for:980 */
/*<       return >*/
    return 0;
/* SOURCE input.for:981 */
/*<       end >*/
} /* set_brhd__ */

/*     *********** */
/*     *         * */
/*     * GET_BRHD */
/*     *         * */
/*     *********** */
/* SOURCE input.for:989 */
/*<       subroutineget_brhd(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_brhd_d_(integer *stdin, integer *stdout, integer *
	eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*8+1] = "BNUM            BRANCH          IN\
ERTIA         CFRATE          WINDFAC         ADDNOD          ADDNODE       \
  GEQOPT          ";
    static integer group[8] = { 0,0,0,0,0,0,0,1 };
    static integer feq_gen_group_index_d_[8] = { 1,1,2,3,4,5,5,1 };
    static integer feq_gen_response_type_d_[8] = { 1,1,2,2,2,1,1,4 };
    static integer feq_gen_convert_rule_d_[8] = { 0,0,1,1,1,0,0,0 };

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_brhd_defaults_d_(), feq_gen_get_named_items_d_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, integer *, real *, doublereal *, char *, integer *, 
	    ftnlen, ftnlen, ftnlen);

/*     Get the values from the Branch header */
/* SOURCE input.for:994 */
/*<       implicitnone >*/
/*      INCLUDE 'arsize.prm' */
/* SOURCE input.for:998 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE input.for:1000 */
/* SOURCE brhd.cmn:1 */
/*<       integermaxr_brhd,maxc_brhd,maxdp_brhd >*/
/* SOURCE brhd.cmn:2 */
/*<       parameter(maxr_brhd=5,maxc_brhd=1,maxdp_brhd=1) >*/
/* SOURCE brhd.cmn:3 */
/*<       integerbrhditab(maxr_brhd) >*/
/* SOURCE brhd.cmn:4 */
/*<       realbrhdftab(maxr_brhd) >*/
/* SOURCE brhd.cmn:5 */
/*<       real*8brhddtab(maxdp_brhd) >*/
/* SOURCE brhd.cmn:6 */
/*<       character*256brhdctab(maxc_brhd) >*/
/* SOURCE brhd.cmn:8 */
/*<       common/brhd_com/brhddtab,brhditab,brhdftab >*/
/* SOURCE brhd.cmn:10 */
/*<       common/brhd_comc/brhdctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE input.for:1005 */
/*<        >*/
/* SOURCE input.for:1008 */
/*<        >*/
/* SOURCE input.for:1012 */
/*<       integermax_line >*/
/* SOURCE input.for:1015 */
/*<       externalget_named_items,set_brhd_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE input.for:1018 */
/*<        >*/
/* SOURCE input.for:1020 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE input.for:1022 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE input.for:1025 */
/*<        >*/
/* SOURCE input.for:1029 */
/*<        >*/
/* SOURCE input.for:1032 */
/*<       datagroup_index/1,1,2,3,4,5,5,1/ >*/
/* SOURCE input.for:1035 */
/*<        >*/
/* SOURCE input.for:1038 */
/*<       dataconvert_rule/exact,exact,lower,lower,lower,exact,exact,exact/ >*/
/* SOURCE input.for:1044 */
/*<       callset_brhd_defaults() >*/
    feq_gen_set_brhd_defaults_d_();
/* SOURCE input.for:1046 */
/*<       max_line=1 >*/
    feq_gen_max_line_d_ = 1;
/* SOURCE input.for:1047 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_8, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_5, &feq_gen_c_d_1, &feq_gen_c_d_1, const_cast<char*>("Branch-header items"), feq_gen_brhd_com_d_1.brhditab, 
	    feq_gen_brhd_com_d_1.brhdftab, feq_gen_brhd_com_d_1.brhddtab, feq_gen_brhd_comc_d_1.brhdctab,
	     eflag, (ftnlen)16, (ftnlen)19, (ftnlen)256);
/* SOURCE input.for:1054 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1056 */
/*<       end >*/
} /* get_brhd__ */




/* SOURCE input.for:1060 */
/*<       subroutineset_tabhd_defaults() >*/
/* Subroutine */ int feq_gen_set_tabhd_defaults_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to process a */
/*     tributary area header block */
/* SOURCE input.for:1064 */
/*<       implicitnone >*/
/* INCLUDE input.for:1065 */
/* SOURCE tabhd.cmn:1 */
/*<       integermaxr_tabhd,maxc_tabhd,maxdp_tabhd >*/
/* SOURCE tabhd.cmn:2 */
/*<       parameter(maxr_tabhd=2,maxc_tabhd=3,maxdp_tabhd=1) >*/
/* SOURCE tabhd.cmn:3 */
/*<       integertabhditab(maxr_tabhd) >*/
/* SOURCE tabhd.cmn:4 */
/*<       realtabhdftab(maxr_tabhd) >*/
/* SOURCE tabhd.cmn:5 */
/*<       real*8tabhddtab(maxdp_tabhd) >*/
/* SOURCE tabhd.cmn:6 */
/*<       character*256tabhdctab(maxc_tabhd) >*/
/* SOURCE tabhd.cmn:8 */
/*<       common/tabhd_com/tabhddtab,tabhditab,tabhdftab >*/
/* SOURCE tabhd.cmn:10 */
/*<       common/tabhd_comc/tabhdctab >*/
/* *********************************************************************** */
/*     Default for: NLUSE -Number of land uses summed over all gages */
/* SOURCE input.for:1069 */
/*<       tabhditab(1)=4 >*/
    feq_gen_tabhd_com_d_1.tabhditab[0] = 4;
/*     Default for: NGAGE - Number of gates */
/* SOURCE input.for:1071 */
/*<       tabhditab(2)=2 >*/
    feq_gen_tabhd_com_d_1.tabhditab[1] = 2;
/*     Default for: TSFNAM  - Name of file for time series of runoff intensity */
/* SOURCE input.for:1073 */
/*<       tabhdctab(1)='    ' >*/
    s_copy(feq_gen_tabhd_comc_d_1.tabhdctab, const_cast<char*>("    "), (ftnlen)256, (ftnlen)4);
/*     Default for: FFFNAM - Name for flood-frequency data file */
/* SOURCE input.for:1075 */
/*<       tabhdctab(2)='   ' >*/
    s_copy(feq_gen_tabhd_comc_d_1.tabhdctab + 256, const_cast<char*>("   "), (ftnlen)256, (ftnlen)3);
/*     Default for: HOME */
/* SOURCE input.for:1077 */
/*<       tabhdctab(3)=' ' >*/
    s_copy(feq_gen_tabhd_comc_d_1.tabhdctab + 512, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1);
/* SOURCE input.for:1078 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1079 */
/*<       end >*/
} /* set_tabhd_defaults__ */




/* SOURCE input.for:1083 */
/*<       subroutineset_tabhd(tsfnam,fffnam,nluse,ngage,tabhome) >*/
/* Subroutine */ int feq_gen_set_tabhd_d_(char *tsfnam, char *fffnam, integer *nluse, 
	integer *ngage, char *tabhome, ftnlen tsfnam_len, ftnlen fffnam_len, 
	ftnlen tabhome_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     All values not set explicitly by user are at their default value. */
/* SOURCE input.for:1087 */
/*<       implicitnone >*/
/* SOURCE input.for:1089 */
/*<       integernluse,ngage >*/
/* SOURCE input.for:1090 */
/*<       charactertsfnam*256,fffnam*256,tabhome*128 >*/
/* INCLUDE input.for:1093 */
/* SOURCE tabhd.cmn:1 */
/*<       integermaxr_tabhd,maxc_tabhd,maxdp_tabhd >*/
/* SOURCE tabhd.cmn:2 */
/*<       parameter(maxr_tabhd=2,maxc_tabhd=3,maxdp_tabhd=1) >*/
/* SOURCE tabhd.cmn:3 */
/*<       integertabhditab(maxr_tabhd) >*/
/* SOURCE tabhd.cmn:4 */
/*<       realtabhdftab(maxr_tabhd) >*/
/* SOURCE tabhd.cmn:5 */
/*<       real*8tabhddtab(maxdp_tabhd) >*/
/* SOURCE tabhd.cmn:6 */
/*<       character*256tabhdctab(maxc_tabhd) >*/
/* SOURCE tabhd.cmn:8 */
/*<       common/tabhd_com/tabhddtab,tabhditab,tabhdftab >*/
/* SOURCE tabhd.cmn:10 */
/*<       common/tabhd_comc/tabhdctab >*/
/* *********************************************************************** */
/* SOURCE input.for:1095 */
/*<       nluse=tabhditab(1) >*/
    *nluse = feq_gen_tabhd_com_d_1.tabhditab[0];
/* SOURCE input.for:1096 */
/*<       ngage=tabhditab(2) >*/
    *ngage = feq_gen_tabhd_com_d_1.tabhditab[1];
/* SOURCE input.for:1097 */
/*<       tsfnam=tabhdctab(1) >*/
    s_copy(tsfnam, feq_gen_tabhd_comc_d_1.tabhdctab, (ftnlen)256, (ftnlen)256);
/* SOURCE input.for:1098 */
/*<       fffnam=tabhdctab(2) >*/
    s_copy(fffnam, feq_gen_tabhd_comc_d_1.tabhdctab + 256, (ftnlen)256, (ftnlen)256);
/* SOURCE input.for:1099 */
/*<       tabhome=tabhdctab(3) >*/
    s_copy(tabhome, feq_gen_tabhd_comc_d_1.tabhdctab + 512, (ftnlen)128, (ftnlen)256);
/* SOURCE input.for:1100 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1101 */
/*<       end >*/
} /* set_tabhd__ */

/*     *********** */
/*     *         * */
/*     * GET_TABHD */
/*     *         * */
/*     *********** */
/* SOURCE input.for:1109 */
/*<       subroutineget_tabhd(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_tabhd_d_(integer *stdin, integer *stdout, integer *
	eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*8+1] = "TSFDSN          TSFNAM          FF\
FDSN          FFFNAM          NLUSE           NGAGE           GAGE          \
  HOME            ";
    static integer group[8] = { 1,1,1,1,0,0,2,1 };
    static integer feq_gen_group_index_d_[8] = { 1,1,2,2,1,2,1,3 };
    static integer feq_gen_response_type_d_[8] = { 4,4,4,4,1,1,0,4 };
    static integer feq_gen_convert_rule_d_[8] = { 0,0,0,0,0,0,0,0 };

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_tabhd_defaults_d_(), feq_gen_get_named_items_d_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, integer *, real *, doublereal *, char *, integer *, 
	    ftnlen, ftnlen, ftnlen);

/*     Get the values from the Tributary Area Block HeaDer */
/* SOURCE input.for:1114 */
/*<       implicitnone >*/
/*      INCLUDE 'arsize.prm' */
/* SOURCE input.for:1118 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE input.for:1120 */
/* SOURCE tabhd.cmn:1 */
/*<       integermaxr_tabhd,maxc_tabhd,maxdp_tabhd >*/
/* SOURCE tabhd.cmn:2 */
/*<       parameter(maxr_tabhd=2,maxc_tabhd=3,maxdp_tabhd=1) >*/
/* SOURCE tabhd.cmn:3 */
/*<       integertabhditab(maxr_tabhd) >*/
/* SOURCE tabhd.cmn:4 */
/*<       realtabhdftab(maxr_tabhd) >*/
/* SOURCE tabhd.cmn:5 */
/*<       real*8tabhddtab(maxdp_tabhd) >*/
/* SOURCE tabhd.cmn:6 */
/*<       character*256tabhdctab(maxc_tabhd) >*/
/* SOURCE tabhd.cmn:8 */
/*<       common/tabhd_com/tabhddtab,tabhditab,tabhdftab >*/
/* SOURCE tabhd.cmn:10 */
/*<       common/tabhd_comc/tabhdctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE input.for:1125 */
/*<        >*/
/* SOURCE input.for:1128 */
/*<        >*/
/* SOURCE input.for:1132 */
/*<       integermax_line >*/
/* SOURCE input.for:1135 */
/*<       externalget_named_items,set_tabhd_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE input.for:1138 */
/*<        >*/
/* SOURCE input.for:1140 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE input.for:1142 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/*     Note that the response type for the group: NXTBLK */
/*     is 0.  This skips any conversion attempt on the value. */
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE input.for:1145 */
/*<        >*/
/* SOURCE input.for:1149 */
/*<       datagroup/char,char,char,char,numeric,numeric,nxtblk,char/ >*/
/* SOURCE input.for:1152 */
/*<       datagroup_index/1,1,2,2,1,2,1,3/ >*/
/* SOURCE input.for:1157 */
/*<        >*/
/* SOURCE input.for:1160 */
/*<       dataconvert_rule/exact,exact,exact,exact,exact,exact,exact,exact/ >*/
/* SOURCE input.for:1166 */
/*<       callset_tabhd_defaults() >*/
    feq_gen_set_tabhd_defaults_d_();
/* SOURCE input.for:1168 */
/*<       max_line=5 >*/
    feq_gen_max_line_d_ = 5;
/* SOURCE input.for:1169 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_8, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_2, &feq_gen_c_d_1, &feq_gen_c_d_3, const_cast<char*>("Trib-area items"), feq_gen_tabhd_com_d_1.tabhditab, 
	    feq_gen_tabhd_com_d_1.tabhdftab, feq_gen_tabhd_com_d_1.tabhddtab, 
	    feq_gen_tabhd_comc_d_1.tabhdctab, eflag, (ftnlen)16, (ftnlen)15, (ftnlen)
	    256);
/* SOURCE input.for:1176 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1178 */
/*<       end >*/
} /* get_tabhd__ */




/* SOURCE input.for:1186 */
/*<       subroutineset_tabbrh_defaults() >*/
/* Subroutine */ int feq_gen_set_tabbrh_defaults_d_()
{
/*     Set the default values in the vectors used to process a */
/*     tributary area block branch header */
/* SOURCE input.for:1190 */
/*<       implicitnone >*/
/* INCLUDE input.for:1191 */
/* SOURCE tabbrh.cmn:1 */
/*<       integermaxr_tabbrh,maxc_tabbrh,maxdp_tabbrh >*/
/* SOURCE tabbrh.cmn:2 */
/*<       parameter(maxr_tabbrh=2,maxc_tabbrh=1,maxdp_tabbrh=1) >*/
/* SOURCE tabbrh.cmn:3 */
/*<       integertabbrhitab(maxr_tabbrh) >*/
/* SOURCE tabbrh.cmn:4 */
/*<       realtabbrhftab(maxr_tabbrh) >*/
/* SOURCE tabbrh.cmn:5 */
/*<       real*8tabbrhdtab(maxdp_tabbrh) >*/
/* SOURCE tabbrh.cmn:6 */
/*<       character*256tabbrhctab(maxc_tabbrh) >*/
/* SOURCE tabbrh.cmn:8 */
/*<       common/tabbrh_com/tabbrhdtab,tabbrhitab,tabbrhftab >*/
/* SOURCE tabbrh.cmn:10 */
/*<       common/tabbrh_comc/tabbrhctab >*/
/* *********************************************************************** */
/*     Default for: USBRA -User branch number */
/* SOURCE input.for:1195 */
/*<       tabbrhitab(1)=1 >*/
    feq_gen_tabbrh_com_d_1.tabbrhitab[0] = 1;
/*     Default for: FAC - Adjustment factor for tributary areas */
/* SOURCE input.for:1197 */
/*<       tabbrhftab(2)=1.0 >*/
    feq_gen_tabbrh_com_d_1.tabbrhftab[1] = (float)1.;
/* SOURCE input.for:1198 */
/*<       end >*/
    return 0;
} /* set_tabbrh_defaults__ */




/* SOURCE input.for:1202 */
/*<       subroutineset_tabbrh(usbra,fac) >*/
/* Subroutine */ int feq_gen_set_tabbrh_d_(integer *usbra, real *fac)
{
/*     All values not set explicitly by user are at their default value. */
/* SOURCE input.for:1206 */
/*<       implicitnone >*/
/* SOURCE input.for:1208 */
/*<       integerusbra >*/
/* SOURCE input.for:1209 */
/*<       realfac >*/
/* INCLUDE input.for:1211 */
/* SOURCE tabbrh.cmn:1 */
/*<       integermaxr_tabbrh,maxc_tabbrh,maxdp_tabbrh >*/
/* SOURCE tabbrh.cmn:2 */
/*<       parameter(maxr_tabbrh=2,maxc_tabbrh=1,maxdp_tabbrh=1) >*/
/* SOURCE tabbrh.cmn:3 */
/*<       integertabbrhitab(maxr_tabbrh) >*/
/* SOURCE tabbrh.cmn:4 */
/*<       realtabbrhftab(maxr_tabbrh) >*/
/* SOURCE tabbrh.cmn:5 */
/*<       real*8tabbrhdtab(maxdp_tabbrh) >*/
/* SOURCE tabbrh.cmn:6 */
/*<       character*256tabbrhctab(maxc_tabbrh) >*/
/* SOURCE tabbrh.cmn:8 */
/*<       common/tabbrh_com/tabbrhdtab,tabbrhitab,tabbrhftab >*/
/* SOURCE tabbrh.cmn:10 */
/*<       common/tabbrh_comc/tabbrhctab >*/
/* *********************************************************************** */
/* SOURCE input.for:1213 */
/*<       usbra=tabbrhitab(1) >*/
    *usbra = feq_gen_tabbrh_com_d_1.tabbrhitab[0];
/* SOURCE input.for:1214 */
/*<       fac=tabbrhftab(2) >*/
    *fac = feq_gen_tabbrh_com_d_1.tabbrhftab[1];
/* SOURCE input.for:1215 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1216 */
/*<       end >*/
} /* set_tabbrh__ */

/*     *********** */
/*     *         * */
/*     * GET_TABBRH */
/*     *         * */
/*     *********** */
/* SOURCE input.for:1224 */
/*<       subroutineget_tabbrh(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_tabbrh_d_(integer *stdin, integer *stdout, integer *
	eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*2+1] = "BRANCH          FAC             ";
    static integer group[2] = { 0,0 };
    static integer feq_gen_group_index_d_[2] = { 1,2 };
    static integer feq_gen_response_type_d_[2] = { 1,2 };
    static integer feq_gen_convert_rule_d_[2] = { 0,1 };

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_tabbrh_defaults_d_(), feq_gen_get_named_items_d_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, integer *, real *, doublereal *, char *, integer *, 
	    ftnlen, ftnlen, ftnlen);

/*     Get the values from the Tributary Area Block BRanch Header */
/* SOURCE input.for:1229 */
/*<       implicitnone >*/
/*      INCLUDE 'arsize.prm' */
/* SOURCE input.for:1233 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE input.for:1235 */
/* SOURCE tabbrh.cmn:1 */
/*<       integermaxr_tabbrh,maxc_tabbrh,maxdp_tabbrh >*/
/* SOURCE tabbrh.cmn:2 */
/*<       parameter(maxr_tabbrh=2,maxc_tabbrh=1,maxdp_tabbrh=1) >*/
/* SOURCE tabbrh.cmn:3 */
/*<       integertabbrhitab(maxr_tabbrh) >*/
/* SOURCE tabbrh.cmn:4 */
/*<       realtabbrhftab(maxr_tabbrh) >*/
/* SOURCE tabbrh.cmn:5 */
/*<       real*8tabbrhdtab(maxdp_tabbrh) >*/
/* SOURCE tabbrh.cmn:6 */
/*<       character*256tabbrhctab(maxc_tabbrh) >*/
/* SOURCE tabbrh.cmn:8 */
/*<       common/tabbrh_com/tabbrhdtab,tabbrhitab,tabbrhftab >*/
/* SOURCE tabbrh.cmn:10 */
/*<       common/tabbrh_comc/tabbrhctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE input.for:1240 */
/*<        >*/
/* SOURCE input.for:1243 */
/*<        >*/
/* SOURCE input.for:1247 */
/*<       integermax_line >*/
/* SOURCE input.for:1250 */
/*<       externalget_named_items,set_tabbrh_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE input.for:1253 */
/*<        >*/
/* SOURCE input.for:1255 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE input.for:1257 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE input.for:1260 */
/*<       datasymbol_table/'BRANCH','FAC'/ >*/
/* SOURCE input.for:1263 */
/*<       datagroup/numeric,numeric/ >*/
/* SOURCE input.for:1266 */
/*<       datagroup_index/1,2/ >*/
/* SOURCE input.for:1269 */
/*<       dataresponse_type/intval,reaval/ >*/
/* SOURCE input.for:1272 */
/*<       dataconvert_rule/exact,lower/ >*/
/* SOURCE input.for:1278 */
/*<       callset_tabbrh_defaults() >*/
    feq_gen_set_tabbrh_defaults_d_();
/* SOURCE input.for:1280 */
/*<       max_line=1 >*/
    feq_gen_max_line_d_ = 1;
/* SOURCE input.for:1281 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_2, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_2, &feq_gen_c_d_1, &feq_gen_c_d_1, const_cast<char*>("Trib-area blck brnch hdr"), 
	    feq_gen_tabbrh_com_d_1.tabbrhitab, feq_gen_tabbrh_com_d_1.tabbrhftab, 
	    feq_gen_tabbrh_com_d_1.tabbrhdtab, feq_gen_tabbrh_comc_d_1.tabbrhctab, eflag, (
	    ftnlen)16, (ftnlen)24, (ftnlen)256);
/* SOURCE input.for:1289 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1291 */
/*<       end >*/
} /* get_tabbrh__ */




/* SOURCE input.for:1298 */
/*<        >*/
/* Subroutine */ int feq_gen_get_luse_items_d_(integer *stdout, char *line, integer *
	nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *eflag, 
	integer *gage, integer *num, ftnlen line_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:400* \002,i3,\002 items given in\
 \002,\002Gage-land use line.  Need exactly two items.\002)";

    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsfi(icilist *), e_rsfi();

    /* Local variables */
    integer n, ie, is;
    char tpc[20];
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_50, 0 };


/*     Get the items of data from gage-land use line */
/* SOURCE input.for:1305 */
/*<       implicitnone >*/
/* SOURCE input.for:1306 */
/*<        >*/
/* SOURCE input.for:1308 */
/*<       characterline*80 >*/
/*     Local */
/* SOURCE input.for:1312 */
/*<       integerie,is,n >*/
/* SOURCE input.for:1313 */
/*<       charactertpc*20 >*/
/*     Called program units */
/* SOURCE input.for:1316 */
/*<       externalstrip_l_blanks >*/
/*     ***********************FORMATS************************************ */
/* SOURCE input.for:1318 */
/*<    50  >*/
/* ******************************************************************************* */
/* SOURCE input.for:1321 */
/*<       if(nitem.ne.2)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
    if (*nitem != 2) {
/* SOURCE input.for:1322 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__33.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__33);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE input.for:1323 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE input.for:1324 */
/*<       endif >*/
    }
/* SOURCE input.for:1326 */
/*<       n=1 >*/
    n = 1;
/*     Process the gage number */
/* SOURCE input.for:1328 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1329 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1330 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1331 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1334 */
/*<       read(tpc,'(i5)')gage >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(i5)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*gage), (ftnlen)sizeof(integer));
    e_rsfi();
/*     Process the number of land uses for the gage */
/* SOURCE input.for:1337 */
/*<       n=2 >*/
    n = 2;
/* SOURCE input.for:1338 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1339 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1340 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1341 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1343 */
/*<       read(tpc,'(i5)')num >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(i5)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*num), (ftnlen)sizeof(integer));
    e_rsfi();
/* SOURCE input.for:1345 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1346 */
/*<       end >*/
} /* get_luse_items__ */




/* SOURCE input.for:1350 */
/*<        >*/
/* Subroutine */ int feq_gen_get_trb_a_items_ndbr_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, char *lpr,
	 integer *gend, integer *gstart, integer *eflag, char *usnode, 
	integer *node, integer *gage, real *feq_storage_a, ftnlen line_len, ftnlen 
	lpr_len, ftnlen usnode_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:401* Only \002,i3,\002 items given \
in a \002,\002Trib-Area line.  Need at least \002,i3,\002 items.\002)";
    static char fmt_52[] = "(/,\002 *ERR:401* Only \002,i3,\002 items given \
in a \002,\002Trib-Area line.  Need at least 4 items.\002)";
    static char fmt_54[] = "(/,\002 *ERR:141* Gage number:\002,i5,\002 out o\
f range\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsli(icilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_rsli(), s_rsfi(icilist *)
	    , e_rsfi(), s_wsle(cilist *), e_wsle();

    /* Local variables */
    integer feq_gen_i_d_, n, ie, is, feq_gen_feql_index1_d_;
    char tpc[20];
    integer needed;
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, 0, 0 };


/*     Get the items of data from a tributary area line in NODE or */
/*     BRANCH format */
/* SOURCE input.for:1359 */
/*<       implicitnone >*/
/* INCLUDE input.for:1360 */
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
/* SOURCE input.for:1362 */
/*<        >*/
/* SOURCE input.for:1364 */
/*<       reala(mxn_lu_g) >*/
/* SOURCE input.for:1365 */
/*<       characterlpr*3,usnode*5,line*112 >*/
/*     Local */
/* SOURCE input.for:1369 */
/*<       integeri,ie,is,n,needed,gage >*/
/* SOURCE input.for:1370 */
/*<       charactertpc*20 >*/
/*     Called program units */
/* SOURCE input.for:1373 */
/*<       externalstrip_l_blanks >*/
/*     ***********************FORMATS************************************ */
/* SOURCE input.for:1350 */
/*<       integer feql_index1 >*/
/* SOURCE input.for:1376 */
/*<    50  >*/
/* SOURCE input.for:1378 */
/*<    52  >*/
/* SOURCE input.for:1380 */
/*<    54 format(/,' *ERR:141* Gage number:',i5,' out of range') >*/
/* ******************************************************************************* */
/* SOURCE input.for:1382 */
/*<       if(nitem.lt.2)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    feq::IndexedPointer<real> a(feq_storage_a, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    if (*nitem < 2) {
/* SOURCE input.for:1383 */
/*<       write(stdout,52)nitem >*/
	feq_gen_io_d__38.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__38);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE input.for:1384 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE input.for:1385 */
/*<       endif >*/
    }
/* SOURCE input.for:1387 */
/*<       n=1 >*/
    n = 1;
/*     Process the USNODE (LPR =LPR) or NODE(LPR not= LPR) */
/* SOURCE input.for:1389 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1390 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1391 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1392 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1394 */
/*<       if(lpr.eq.'LPR')then >*/
    if (s_cmp(lpr, const_cast<char*>("LPR"), (ftnlen)3, (ftnlen)3) == 0) {
/*       Level-pool reservoirs or boundary nodes. */
/* SOURCE input.for:1396 */
/*<       usnode=tpc(1:5) >*/
	s_copy(usnode, tpc, (ftnlen)5, (ftnlen)5);
/* SOURCE input.for:1397 */
/*<       if(usnode(1:1).eq.'-')then >*/
	if (*(unsigned char *)usnode == '-') {
/*         We have found the terminating line for this */
/*         set of LPR's or boundary nodes. */
/* SOURCE input.for:1400 */
/*<       node=-1 >*/
	    *node = -1;
/* SOURCE input.for:1401 */
/*<       else >*/
	} else {
/* SOURCE input.for:1402 */
/*<       node=1 >*/
	    *node = 1;
/* SOURCE input.for:1403 */
/*<       endif >*/
	}
/* SOURCE input.for:1404 */
/*<       else >*/
    } else {
/* SOURCE input.for:1405 */
/*<       read(tpc,*,err=999)node >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*node), (ftnlen)sizeof(integer))
		;
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE input.for:1406 */
/*<       usnode=' ' >*/
	s_copy(usnode, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1);
/* SOURCE input.for:1407 */
/*<       endif >*/
    }
/*     Process the raingage number */
/* SOURCE input.for:1410 */
/*<       n=2 >*/
    n = 2;
/* SOURCE input.for:1411 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1412 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1413 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1414 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1416 */
/*<       if(tpc.eq.' ')then >*/
    if (s_cmp(tpc, const_cast<char*>(" "), (ftnlen)20, (ftnlen)1) == 0) {
/* SOURCE input.for:1417 */
/*<       gage=0 >*/
	*gage = 0;
/* SOURCE input.for:1418 */
/*<       else >*/
    } else {
/* SOURCE input.for:1419 */
/*<       read(tpc,*,err=999)gage >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*gage), (ftnlen)sizeof(integer))
		;
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE input.for:1420 */
/*<       endif >*/
    }
/* SOURCE input.for:1422 */
/*<       if(node.lt.0)then >*/
    if (*node < 0) {
/*       Input complete for LPR or boundary node */
/* SOURCE input.for:1424 */
/*<       return >*/
	return 0;
/* SOURCE input.for:1425 */
/*<       endif >*/
    }
/*     GAGE should be valid here */
/* SOURCE input.for:1428 */
/*<       if(gage.lt.1.or.gage.gt.mxgage)then >*/
    if (*gage < 1 || *gage > 16) {
/* SOURCE input.for:1429 */
/*<       write(stdout,54)gage >*/
	feq_gen_io_d__43.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__43);
	do_fio(&feq_gen_c_d_1, (char *)&(*gage), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE input.for:1430 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE input.for:1431 */
/*<       endif >*/
    }
/* SOURCE input.for:1434 */
/*<       needed=2+gend(gage)-gstart(gage)+1 >*/
    needed = gend[*gage] + 2 - gstart[*gage] + 1;
/* SOURCE input.for:1435 */
/*<       if(nitem.lt.needed)then >*/
    if (*nitem < needed) {
/* SOURCE input.for:1436 */
/*<       write(stdout,50)nitem,needed >*/
	feq_gen_io_d__45.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__45);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&needed, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE input.for:1437 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE input.for:1438 */
/*<       endif >*/
    }
/* SOURCE input.for:1441 */
/*<       if(gage.gt.0)then >*/
    if (*gage > 0) {
/*       Process the trib-area values.  There should be NEEDED-2 of them */
/* SOURCE input.for:1443 */
/*<       do100n=3,needed >*/
	feq_gen_i_d_1 = needed;
	for (n = 3; n <= feq_gen_i_d_1; ++n) {
/* SOURCE input.for:1444 */
/*<       i=n-2 >*/
	    feq_gen_i_d_ = n - 2;
/* SOURCE input.for:1445 */
/*<       is=item_start(n) >*/
	    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1446 */
/*<       ie=item_end(n) >*/
	    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1447 */
/*<       tpc=line(is:ie) >*/
	    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1448 */
/*<       callstrip_l_blanks(tpc) >*/
	    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1450 */
/*<       read(tpc,'(F15.0)',err=998)a(i) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 20;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.0)");
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L998;
	    }
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&a[feq_gen_i_d_], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L998;
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L998;
	    }
/* SOURCE input.for:1451 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE input.for:1452 */
/*<       else >*/
    } else {
/* SOURCE input.for:1453 */
/*<       dofeql_index1=1,mxn_lu_g >*/
	for (feq_gen_feql_index1_d_ = 1; feq_gen_feql_index1_d_ <= 8; ++feq_gen_feql_index1_d_) {
/* SOURCE input.for:1453 */
/*<       a(feql_index1)=0.0 >*/
	    a[feq_gen_feql_index1_d_] = (float)0.;
/* SOURCE input.for:1453 */
/*<       enddo >*/
	}
/* SOURCE input.for:1454 */
/*<       endif >*/
    }
/* SOURCE input.for:1455 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1457 */
/*<   998 continue >*/
L998:
/* SOURCE input.for:1458 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__48.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__48);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE input.for:1459 */
/*<       write(stdout,*)tpc >*/
    feq_gen_io_d__49.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__49);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, tpc, (ftnlen)20);
    e_wsle();
/* SOURCE input.for:1460 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE input.for:1461 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1462 */
/*<   999 continue >*/
L999:
/* SOURCE input.for:1463 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE input.for:1464 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1465 */
/*<       end >*/
} /* get_trb_a_items_ndbr__ */




/* SOURCE input.for:1471 */
/*<        >*/
/* Subroutine */ int feq_gen_get_trb_a_items_strng_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	gend, integer *gstart, integer *eflag, real *ustat, real *dstat, 
	integer *gage, real *feq_storage_a, ftnlen line_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:401* Only \002,i3,\002 items given \
in a \002,\002Trib-Area line.  Need at least \002,i3,\002 items.\002)";
    static char fmt_52[] = "(/,\002 *ERR:401* Only \002,i3,\002 items given \
in a \002,\002TRib-Area line.  Need at least 4 items.\002)";
    static char fmt_54[] = "(/,\002 *ERR:141* Gage number:\002,i5,\002 out o\
f range\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli(), s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, 
	    ftnlen, ftnlen), s_wsle(cilist *), e_wsle();

    /* Local variables */
    integer feq_gen_i_d_, n, ie, is, feq_gen_feql_index2_d_;
    char tpc[20];
    integer needed;
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__50 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__55 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, 0, 0 };


/*     Get the items of data from a tributary area line in Station- */
/*     Range format */
/* SOURCE input.for:1480 */
/*<       implicitnone >*/
/* INCLUDE input.for:1481 */
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
/* SOURCE input.for:1483 */
/*<        >*/
/* SOURCE input.for:1485 */
/*<       reala(mxn_lu_g),ustat,dstat >*/
/* SOURCE input.for:1486 */
/*<       characterline*112 >*/
/*     Local */
/* SOURCE input.for:1490 */
/*<       integeri,ie,is,n,needed,gage >*/
/* SOURCE input.for:1491 */
/*<       charactertpc*20 >*/
/*     Called program units */
/* SOURCE input.for:1494 */
/*<       externalstrip_l_blanks >*/
/*     ***********************FORMATS************************************ */
/* SOURCE input.for:1471 */
/*<       integer feql_index2 >*/
/* SOURCE input.for:1497 */
/*<    50  >*/
/* SOURCE input.for:1499 */
/*<    52  >*/
/* SOURCE input.for:1501 */
/*<    54 format(/,' *ERR:141* Gage number:',i5,' out of range') >*/
/* ******************************************************************************* */
/* SOURCE input.for:1503 */
/*<       if(nitem.lt.2)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    feq::IndexedPointer<real> a(feq_storage_a, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    if (*nitem < 2) {
/* SOURCE input.for:1504 */
/*<       write(stdout,52)nitem >*/
	feq_gen_io_d__50.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__50);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE input.for:1505 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE input.for:1506 */
/*<       endif >*/
    }
/* SOURCE input.for:1508 */
/*<       n=1 >*/
    n = 1;
/*     Process USTAT */
/* SOURCE input.for:1510 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1511 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1512 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1513 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1515 */
/*<       read(tpc,*,err=999)ustat >*/
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
    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*ustat), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L999;
    }
    feq_gen_i_d_1 = e_rsli();
    if (feq_gen_i_d_1 != 0) {
	goto L999;
    }
/* SOURCE input.for:1517 */
/*<       n=2 >*/
    n = 2;
/*     Process DSTAT */
/* SOURCE input.for:1519 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1520 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1521 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1522 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1524 */
/*<       read(tpc,'(f20.0)',err=999)dstat >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(f20.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L999;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*dstat), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L999;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L999;
    }
/*     Process the raingage number */
/* SOURCE input.for:1527 */
/*<       n=3 >*/
    n = 3;
/* SOURCE input.for:1528 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1529 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1530 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1531 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1533 */
/*<       if(tpc.eq.' ')then >*/
    if (s_cmp(tpc, const_cast<char*>(" "), (ftnlen)20, (ftnlen)1) == 0) {
/* SOURCE input.for:1534 */
/*<       gage=0 >*/
	*gage = 0;
/* SOURCE input.for:1535 */
/*<       else >*/
    } else {
/* SOURCE input.for:1536 */
/*<       read(tpc,'(i5)',err=999)gage >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 20;
	feq_gen_ici_d_1.iciunit = tpc;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(i5)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*gage), (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE input.for:1537 */
/*<       endif >*/
    }
/* SOURCE input.for:1539 */
/*<       if(gage.gt.0)then >*/
    if (*gage > 0) {
/*       GAGE should be valid. */
/* SOURCE input.for:1541 */
/*<       if(gage.lt.1.or.gage.gt.mxgage)then >*/
	if (*gage < 1 || *gage > 16) {
/* SOURCE input.for:1542 */
/*<       write(stdout,54)gage >*/
	    feq_gen_io_d__55.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__55);
	    do_fio(&feq_gen_c_d_1, (char *)&(*gage), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE input.for:1543 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE input.for:1544 */
/*<       endif >*/
	}
/* SOURCE input.for:1545 */
/*<       endif >*/
    }
/* SOURCE input.for:1546 */
/*<       needed=3+gend(gage)-gstart(gage)+1 >*/
    needed = gend[*gage] + 3 - gstart[*gage] + 1;
/* SOURCE input.for:1547 */
/*<       if(nitem.lt.needed)then >*/
    if (*nitem < needed) {
/* SOURCE input.for:1548 */
/*<       write(stdout,50)nitem,needed >*/
	feq_gen_io_d__57.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__57);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&needed, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE input.for:1549 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE input.for:1550 */
/*<       endif >*/
    }
/* SOURCE input.for:1552 */
/*<       if(gage.gt.0)then >*/
    if (*gage > 0) {
/*       Process the trib-area values.  There should be NEEDED-3 of them */
/* SOURCE input.for:1554 */
/*<       do100n=4,needed >*/
	feq_gen_i_d_1 = needed;
	for (n = 4; n <= feq_gen_i_d_1; ++n) {
/* SOURCE input.for:1555 */
/*<       i=n-3 >*/
	    feq_gen_i_d_ = n - 3;
/* SOURCE input.for:1556 */
/*<       is=item_start(n) >*/
	    is = feq_gen_item_start_d_[n];
/* SOURCE input.for:1557 */
/*<       ie=item_end(n) >*/
	    ie = feq_gen_item_end_d_[n];
/* SOURCE input.for:1558 */
/*<       tpc=line(is:ie) >*/
	    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE input.for:1559 */
/*<       callstrip_l_blanks(tpc) >*/
	    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE input.for:1561 */
/*<       read(tpc,'(f20.0)',err=998)a(i) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 20;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(f20.0)");
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L998;
	    }
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&a[feq_gen_i_d_], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L998;
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L998;
	    }
/* SOURCE input.for:1562 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE input.for:1563 */
/*<       else >*/
    } else {
/* SOURCE input.for:1564 */
/*<       dofeql_index2=1,mxn_lu_g >*/
	for (feq_gen_feql_index2_d_ = 1; feq_gen_feql_index2_d_ <= 8; ++feq_gen_feql_index2_d_) {
/* SOURCE input.for:1564 */
/*<       a(feql_index2)=0.0 >*/
	    a[feq_gen_feql_index2_d_] = (float)0.;
/* SOURCE input.for:1564 */
/*<       enddo >*/
	}
/* SOURCE input.for:1565 */
/*<       endif >*/
    }
/* SOURCE input.for:1566 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1568 */
/*<   998 continue >*/
L998:
/* SOURCE input.for:1569 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__60.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__60);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE input.for:1570 */
/*<       write(stdout,*)tpc >*/
    feq_gen_io_d__61.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__61);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, tpc, (ftnlen)20);
    e_wsle();
/* SOURCE input.for:1571 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE input.for:1572 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1573 */
/*<   999 continue >*/
L999:
/* SOURCE input.for:1574 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE input.for:1575 */
/*<       return >*/
    return 0;
/* SOURCE input.for:1576 */
/*<       end >*/
} /* get_trb_a_items_strng__ */

#ifdef __cplusplus
	}
#endif
