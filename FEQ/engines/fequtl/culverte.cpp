/* culverte.f -- translated by f2c (version 20240504).
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

/* COMMON depitm_com__ is declared in common.hpp. */

#define feq_gen_depitm_com_d_1 feq_gen_depitm_com_d_

/* COMMON depitm_comc__ is declared in common.hpp. */

#define feq_gen_depitm_comc_d_1 feq_gen_depitm_comc_d_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_2 = 2;




/* SOURCE culverte.for:4 */
/*<        >*/
/* Subroutine */ int feq_gen_read_culvert_items_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	eflag, integer *idlen, integer *hlidlen, integer *node, char *feq_gen_name_d_, 
	char *xtabn, char *xchar, char *zchar, real *ca, real *cd, integer *
	hl, ftnlen line_len, ftnlen name_len, ftnlen xtabn_len, ftnlen 
	xchar_len, ftnlen zchar_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:739* Only \002,i3,\002 items given \
in \002,\002culvert-barrel description line.  Need at least five items.\002)";

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
    integer itab, lkey;
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, fmt_50, 0 };


/*     Get the items of data from a CULVERT barrel input line. */
/* SOURCE culverte.for:12 */
/*<       implicitnone >*/
/* SOURCE culverte.for:13 */
/*<        >*/
/* SOURCE culverte.for:15 */
/*<       realca,cd >*/
/* SOURCE culverte.for:16 */
/*<       characterline*120,name*8,xtabn*5,xchar*10,zchar*10 >*/
/*     Local */
/* SOURCE culverte.for:20 */
/*<       integerie,is,itab,lkey,n >*/
/* SOURCE culverte.for:21 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE culverte.for:24 */
/*<       integernonblank_nonzero,lenstr >*/
/* SOURCE culverte.for:25 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE culverte.for:28 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE culverte.for:32 */
/*<       if(nitem.lt.5)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
    if (*nitem < 5) {
/* SOURCE culverte.for:33 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__1.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__1);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE culverte.for:34 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE culverte.for:35 */
/*<       endif >*/
    }
/* SOURCE culverte.for:37 */
/*<       n=1 >*/
    n = 1;
/*     Process the NODE */
/* SOURCE culverte.for:39 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE culverte.for:40 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE culverte.for:41 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE culverte.for:42 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE culverte.for:44 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE culverte.for:45 */
/*<       node=0 >*/
	*node = 0;
/* SOURCE culverte.for:46 */
/*<       else >*/
    } else {
/* SOURCE culverte.for:47 */
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
/* SOURCE culverte.for:48 */
/*<       endif >*/
    }
/*     Process the node id */
/* SOURCE culverte.for:51 */
/*<       n=2 >*/
    n = 2;
/* SOURCE culverte.for:52 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE culverte.for:53 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE culverte.for:54 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE culverte.for:55 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE culverte.for:57 */
/*<       name=tpc >*/
    s_copy(feq_gen_name_d_, tpc, (ftnlen)8, (ftnlen)20);
/*     Process the table id */
/* SOURCE culverte.for:60 */
/*<       n=3 >*/
    n = 3;
/* SOURCE culverte.for:61 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE culverte.for:62 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE culverte.for:63 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE culverte.for:64 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE culverte.for:66 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE culverte.for:67 */
/*<       lkey=lenstr(key) >*/
    lkey = lenstr_(key, (ftnlen)16);
/* SOURCE culverte.for:68 */
/*<       idlen=max(idlen,lkey) >*/
    *idlen = max(*idlen,lkey);
/*     Convert from the table id to an internal number. */
/* SOURCE culverte.for:70 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE culverte.for:71 */
/*<       if(key(1:1).ne.'-')then >*/
	if (*(unsigned char *)key != '-') {
/*         We have an id given. */
/* SOURCE culverte.for:73 */
/*<       callget_internal_tab_number(stdout,key,eflag,itab) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &itab, (ftnlen)16);
/* SOURCE culverte.for:77 */
/*<       write(xtabn,'(I5)')itab >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 5;
	    feq_gen_ici_d_1.iciunit = xtabn;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&itab, (ftnlen)sizeof(integer));
	    e_wsfi();
/* SOURCE culverte.for:78 */
/*<       else >*/
	} else {
/*         We have a string starting with a - here */
/* SOURCE culverte.for:80 */
/*<       if(lkey.gt.1)then >*/
	    if (lkey > 1) {
/*           It is a tabid prefixed with a minus sign. */
/*           Strip the minus, define the internal number, and apply */
/*           the minus to the internal number */
/* SOURCE culverte.for:84 */
/*<       key=key(2:16) >*/
		s_copy(key, key + 1, (ftnlen)16, (ftnlen)15);
/* SOURCE culverte.for:85 */
/*<       callget_internal_tab_number(stdout,key,eflag,itab) >*/
		feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &itab, (ftnlen)
			16);
/* SOURCE culverte.for:89 */
/*<       write(xtabn,'(I5)')-itab >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 5;
		feq_gen_ici_d_1.iciunit = xtabn;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
		s_wsfi(&feq_gen_ici_d_1);
		feq_gen_i_d_1 = -itab;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		e_wsfi();
/* SOURCE culverte.for:90 */
/*<       else >*/
	    } else {
/* SOURCE culverte.for:91 */
/*<       xtabn=tpc >*/
		s_copy(xtabn, tpc, (ftnlen)5, (ftnlen)20);
/* SOURCE culverte.for:92 */
/*<       endif >*/
	    }
/* SOURCE culverte.for:93 */
/*<       endif >*/
	}
/* SOURCE culverte.for:94 */
/*<       else >*/
    } else {
/* SOURCE culverte.for:95 */
/*<       xtabn=' ' >*/
	s_copy(xtabn, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1);
/* SOURCE culverte.for:96 */
/*<       endif >*/
    }
/*     Process the station */
/* SOURCE culverte.for:99 */
/*<       n=4 >*/
    n = 4;
/* SOURCE culverte.for:100 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE culverte.for:101 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE culverte.for:102 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE culverte.for:103 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE culverte.for:105 */
/*<       xchar=tpc >*/
    s_copy(xchar, tpc, (ftnlen)10, (ftnlen)20);
/*     Process the invert elevation */
/* SOURCE culverte.for:108 */
/*<       n=5 >*/
    n = 5;
/* SOURCE culverte.for:109 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE culverte.for:110 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE culverte.for:111 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE culverte.for:112 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE culverte.for:114 */
/*<       zchar=tpc >*/
    s_copy(zchar, tpc, (ftnlen)10, (ftnlen)20);
/*     Process the local acceleration losses */
/* SOURCE culverte.for:117 */
/*<       n=6 >*/
    n = 6;
/* SOURCE culverte.for:118 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE culverte.for:119 */
/*<       ca=0.0 >*/
	*ca = (float)0.;
/* SOURCE culverte.for:120 */
/*<       else >*/
    } else {
/* SOURCE culverte.for:121 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE culverte.for:122 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE culverte.for:123 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE culverte.for:124 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE culverte.for:126 */
/*<       if(tpc(1:1).eq.' ')then >*/
	if (*(unsigned char *)tpc == ' ') {
/* SOURCE culverte.for:127 */
/*<       ca=0.0 >*/
	    *ca = (float)0.;
/* SOURCE culverte.for:128 */
/*<       else >*/
	} else {
/* SOURCE culverte.for:129 */
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
/* SOURCE culverte.for:130 */
/*<       endif >*/
	}
/* SOURCE culverte.for:131 */
/*<       endif >*/
    }
/*     Process local decceleration losses */
/* SOURCE culverte.for:134 */
/*<       n=7 >*/
    n = 7;
/* SOURCE culverte.for:135 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE culverte.for:136 */
/*<       cd=0.0 >*/
	*cd = (float)0.;
/* SOURCE culverte.for:137 */
/*<       else >*/
    } else {
/* SOURCE culverte.for:138 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE culverte.for:139 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE culverte.for:140 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE culverte.for:141 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE culverte.for:143 */
/*<       if(tpc(1:1).eq.' ')then >*/
	if (*(unsigned char *)tpc == ' ') {
/* SOURCE culverte.for:144 */
/*<       cd=0.0 >*/
	    *cd = (float)0.;
/* SOURCE culverte.for:145 */
/*<       else >*/
	} else {
/* SOURCE culverte.for:146 */
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
/* SOURCE culverte.for:147 */
/*<       endif >*/
	}
/* SOURCE culverte.for:148 */
/*<       endif >*/
    }
/*     Process local structure losses */
/* SOURCE culverte.for:151 */
/*<       n=8 >*/
    n = 8;
/* SOURCE culverte.for:152 */
/*<       if(n.gt.nitem)then >*/
    if (n > *nitem) {
/* SOURCE culverte.for:153 */
/*<       hl=0 >*/
	*hl = 0;
/* SOURCE culverte.for:154 */
/*<       else >*/
    } else {
/* SOURCE culverte.for:155 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE culverte.for:156 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE culverte.for:157 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE culverte.for:158 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE culverte.for:160 */
/*<       key=tpc >*/
	s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE culverte.for:161 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*         We have a reference to a loss table. */
/* SOURCE culverte.for:163 */
/*<       hlidlen=max(hlidlen,lenstr(key)) >*/
/* Computing MAX */
	    feq_gen_i_d_1 = *hlidlen, feq_gen_i_d_2 = lenstr_(key, (ftnlen)16);
	    *hlidlen = max(feq_gen_i_d_1,feq_gen_i_d_2);
/* SOURCE culverte.for:164 */
/*<       callget_internal_tab_number(stdout,key,eflag,hl) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, hl, (ftnlen)16);
/* SOURCE culverte.for:168 */
/*<       else >*/
	} else {
/* SOURCE culverte.for:169 */
/*<       hl=0.0 >*/
	    *hl = (float)0.;
/* SOURCE culverte.for:170 */
/*<       endif >*/
	}
/* SOURCE culverte.for:171 */
/*<       endif >*/
    }
/* SOURCE culverte.for:173 */
/*<       return >*/
    return 0;
/* SOURCE culverte.for:174 */
/*<       end >*/
} /* read_culvert_items__ */




/* SOURCE culverte.for:178 */
/*<       subroutineset_depitm_defaults() >*/
/* Subroutine */ int feq_gen_set_depitm_defaults_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to process a */
/*     deparature reach table spec. */
/* SOURCE culverte.for:182 */
/*<       implicitnone >*/
/* INCLUDE culverte.for:183 */
/* SOURCE depitm.cmn:1 */
/*<       integermaxr_depitm,maxc_depitm,maxdp_depitm >*/
/* SOURCE depitm.cmn:2 */
/*<       parameter(maxr_depitm=2,maxc_depitm=2,maxdp_depitm=1) >*/
/* SOURCE depitm.cmn:3 */
/*<       integerdepitmitab(maxr_depitm) >*/
/* SOURCE depitm.cmn:4 */
/*<       realdepitmftab(maxr_depitm) >*/
/* SOURCE depitm.cmn:5 */
/*<       real*8depitmdtab(maxdp_depitm) >*/
/* SOURCE depitm.cmn:6 */
/*<       character*256depitmctab(maxc_depitm) >*/
/* SOURCE depitm.cmn:8 */
/*<       common/depitm_com/depitmdtab,depitmitab,depitmftab >*/
/* SOURCE depitm.cmn:10 */
/*<       common/depitm_comc/depitmctab >*/
/* *********************************************************************** */
/*     Default for: DEPTAB */
/* SOURCE culverte.for:187 */
/*<       depitmctab(1)='    ' >*/
    s_copy(feq_gen_depitm_comc_d_1.depitmctab, const_cast<char*>("    "), (ftnlen)256, (ftnlen)4);
/*     Default for: BEGTAB */
/* SOURCE culverte.for:189 */
/*<       depitmctab(2)='    ' >*/
    s_copy(feq_gen_depitm_comc_d_1.depitmctab + 256, const_cast<char*>("    "), (ftnlen)256, (ftnlen)4);
/*     Default for: RMFFAC */
/* SOURCE culverte.for:191 */
/*<       depitmftab(1)=1.0 >*/
    feq_gen_depitm_com_d_1.depitmftab[0] = (float)1.;
/* SOURCE culverte.for:192 */
/*<       return >*/
    return 0;
/* SOURCE culverte.for:193 */
/*<       end >*/
} /* set_depitm_defaults__ */




/* SOURCE culverte.for:197 */
/*<       subroutineset_depitm(deptab,begtab,rmffac,eflag) >*/
/* Subroutine */ int feq_gen_set_depitm_d_(integer *deptab, integer *begtab, real *
	rmffac, integer *eflag)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char key[16];

/*     Set items for a departure reach table spec. */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE culverte.for:203 */
/*<       implicitnone >*/
/* SOURCE culverte.for:206 */
/*<       integerbegtab,deptab,eflag >*/
/* SOURCE culverte.for:207 */
/*<       realrmffac >*/
/*     Local */
/* SOURCE culverte.for:211 */
/*<       character*16key >*/
/* INCLUDE culverte.for:213 */
/* SOURCE depitm.cmn:1 */
/*<       integermaxr_depitm,maxc_depitm,maxdp_depitm >*/
/* SOURCE depitm.cmn:2 */
/*<       parameter(maxr_depitm=2,maxc_depitm=2,maxdp_depitm=1) >*/
/* SOURCE depitm.cmn:3 */
/*<       integerdepitmitab(maxr_depitm) >*/
/* SOURCE depitm.cmn:4 */
/*<       realdepitmftab(maxr_depitm) >*/
/* SOURCE depitm.cmn:5 */
/*<       real*8depitmdtab(maxdp_depitm) >*/
/* SOURCE depitm.cmn:6 */
/*<       character*256depitmctab(maxc_depitm) >*/
/* SOURCE depitm.cmn:8 */
/*<       common/depitm_com/depitmdtab,depitmitab,depitmftab >*/
/* SOURCE depitm.cmn:10 */
/*<       common/depitm_comc/depitmctab >*/
/* INCLUDE culverte.for:214 */
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
/* *********************************************************************** */
/* SOURCE culverte.for:216 */
/*<       key=depitmctab(1) >*/
    s_copy(key, feq_gen_depitm_comc_d_1.depitmctab, (ftnlen)16, (ftnlen)256);
/* SOURCE culverte.for:217 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE culverte.for:218 */
/*<       callget_internal_tab_number(std6,key,eflag,deptab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key, eflag, deptab, (
		ftnlen)16);
/* SOURCE culverte.for:222 */
/*<       else >*/
    } else {
/* SOURCE culverte.for:223 */
/*<       deptab=0 >*/
	*deptab = 0;
/* SOURCE culverte.for:224 */
/*<       endif >*/
    }
/* SOURCE culverte.for:225 */
/*<       key=depitmctab(2) >*/
    s_copy(key, feq_gen_depitm_comc_d_1.depitmctab + 256, (ftnlen)16, (ftnlen)256);
/* SOURCE culverte.for:226 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE culverte.for:227 */
/*<       callget_internal_tab_number(std6,key,eflag,begtab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key, eflag, begtab, (
		ftnlen)16);
/* SOURCE culverte.for:231 */
/*<       else >*/
    } else {
/* SOURCE culverte.for:232 */
/*<       begtab=0 >*/
	*begtab = 0;
/* SOURCE culverte.for:233 */
/*<       endif >*/
    }
/* SOURCE culverte.for:234 */
/*<       rmffac=depitmftab(1) >*/
    *rmffac = feq_gen_depitm_com_d_1.depitmftab[0];
/* SOURCE culverte.for:235 */
/*<       return >*/
    return 0;
/* SOURCE culverte.for:236 */
/*<       end >*/
} /* set_depitm__ */




/* SOURCE culverte.for:240 */
/*<       subroutineget_departure_items(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_departure_items_d_(integer *stdin, integer *stdout, 
	integer *eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*3+1] = "DEPTAB          BEGTAB          RM\
FFAC          ";
    static integer group[3] = { 1,1,0 };
    static integer feq_gen_group_index_d_[3] = { 1,2,1 };
    static integer feq_gen_response_type_d_[3] = { 4,4,2 };
    static integer feq_gen_convert_rule_d_[3] = { 1,1,1 };

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_depitm_defaults_d_(), feq_gen_get_named_items_d_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, integer *, real *, doublereal *, char *, integer *, 
	    ftnlen, ftnlen, ftnlen);

/*     Get the values from departure reach table specification */
/* SOURCE culverte.for:245 */
/*<       implicitnone >*/
/* INCLUDE culverte.for:247 */
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
/* SOURCE culverte.for:249 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE culverte.for:251 */
/* SOURCE depitm.cmn:1 */
/*<       integermaxr_depitm,maxc_depitm,maxdp_depitm >*/
/* SOURCE depitm.cmn:2 */
/*<       parameter(maxr_depitm=2,maxc_depitm=2,maxdp_depitm=1) >*/
/* SOURCE depitm.cmn:3 */
/*<       integerdepitmitab(maxr_depitm) >*/
/* SOURCE depitm.cmn:4 */
/*<       realdepitmftab(maxr_depitm) >*/
/* SOURCE depitm.cmn:5 */
/*<       real*8depitmdtab(maxdp_depitm) >*/
/* SOURCE depitm.cmn:6 */
/*<       character*256depitmctab(maxc_depitm) >*/
/* SOURCE depitm.cmn:8 */
/*<       common/depitm_com/depitmdtab,depitmitab,depitmftab >*/
/* SOURCE depitm.cmn:10 */
/*<       common/depitm_comc/depitmctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE culverte.for:256 */
/*<        >*/
/* SOURCE culverte.for:259 */
/*<        >*/
/* SOURCE culverte.for:263 */
/*<       integermax_line >*/
/* SOURCE culverte.for:266 */
/*<       externalget_named_items,set_depitm_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE culverte.for:269 */
/*<        >*/
/* SOURCE culverte.for:271 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE culverte.for:273 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE culverte.for:276 */
/*<       datasymbol_table/'DEPTAB','BEGTAB','RMFFAC'/ >*/
/* SOURCE culverte.for:279 */
/*<       datagroup/char,char,numeric/ >*/
/* SOURCE culverte.for:282 */
/*<       datagroup_index/1,2,1/ >*/
/* SOURCE culverte.for:285 */
/*<       dataresponse_type/chrval,chrval,reaval/ >*/
/* SOURCE culverte.for:288 */
/*<       dataconvert_rule/lower,lower,lower/ >*/
/* SOURCE culverte.for:294 */
/*<       callset_depitm_defaults() >*/
    feq_gen_set_depitm_defaults_d_();
/* SOURCE culverte.for:296 */
/*<       max_line=1 >*/
    feq_gen_max_line_d_ = 1;
/* SOURCE culverte.for:297 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_3, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_2, &feq_gen_c_d_1, &feq_gen_c_d_2, const_cast<char*>("Dep. reach items"), feq_gen_depitm_com_d_1.depitmitab, 
	    feq_gen_depitm_com_d_1.depitmftab, feq_gen_depitm_com_d_1.depitmdtab, 
	    feq_gen_depitm_comc_d_1.depitmctab, eflag, (ftnlen)16, (ftnlen)16, (ftnlen)
	    256);
/* SOURCE culverte.for:304 */
/*<       return >*/
    return 0;
/* SOURCE culverte.for:306 */
/*<       end >*/
} /* get_departure_items__ */

#ifdef __cplusplus
	}
#endif
