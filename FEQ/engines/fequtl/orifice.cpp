#include "callbacks.hpp"
/* orifice.f -- translated by f2c (version 20240504).
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

/* COMMON orf_shape__ is declared in common.hpp. */

#define feq_gen_orf_shape_d_1 feq_gen_orf_shape_d_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON upgrdc_ is declared in common.hpp. */

#define upgrdc_1 upgrdc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_8 = 8;
static integer feq_gen_c_d_20 = 20;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_151 = 151;
static integer feq_gen_c_d_351 = 351;
static integer feq_gen_c_d_13 = 13;
static integer feq_gen_c_d_9 = 9;




/* SOURCE orifice.for:4 */
/*<        >*/
/* Subroutine */ int feq_gen_read_orifice_items1_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	number, char *shape, char *edge, real *feq_gen_d_d_, real *w, real *invert, 
	real *cd, real *cw, ftnlen line_len, ftnlen shape_len, ftnlen 
	edge_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:752* Only \002,i3,\002 items given \
in \002,\002first orifice description line.  Need at least eight items.\002)";
    static char fmt_52[] = "(/,\002 *ERR:753* Conversion error in field \002\
,i1,\002 in:\002,/,a)";

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
    integer n, ie, is;
    char tpc[20];
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_52, 0 };


/*     Get the items of data from the first line of ORIFICE data */
/* SOURCE orifice.for:12 */
/*<       implicitnone >*/
/* SOURCE orifice.for:13 */
/*<       integerstdout,nitem,item_start(nitem),item_end(nitem),number >*/
/* SOURCE orifice.for:15 */
/*<       reald,w,invert,cd,cw >*/
/* SOURCE orifice.for:16 */
/*<       characterline*(*),shape*6,edge*6 >*/
/*     Local */
/* SOURCE orifice.for:20 */
/*<       integerie,is,n >*/
/* SOURCE orifice.for:21 */
/*<       charactertpc*20 >*/
/*     Called program units */
/* SOURCE orifice.for:24 */
/*<       externalstrip_l_blanks >*/
/*     ***********************FORMATS************************************ */
/* SOURCE orifice.for:26 */
/*<    50  >*/
/* SOURCE orifice.for:28 */
/*<    52 format(/,' *ERR:753* Conversion error in field ',i1,' in:',/,a) >*/
/* *********************************************************************** */
/* SOURCE orifice.for:31 */
/*<       if(nitem.lt.8)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
/* L52: */
    if (*nitem < 8) {
/* SOURCE orifice.for:32 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__1.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__1);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE orifice.for:33 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE orifice.for:34 */
/*<       endif >*/
    }
/* SOURCE orifice.for:36 */
/*<       n=1 >*/
    n = 1;
/*     Process NUMBER */
/* SOURCE orifice.for:38 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:39 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:40 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:41 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:43 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:44 */
/*<       number=0 >*/
	*number = 0;
/* SOURCE orifice.for:45 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:46 */
/*<       read(tpc,*,err=999)number >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*number), (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:47 */
/*<       endif >*/
    }
/*     Process the SHAPE description */
/* SOURCE orifice.for:50 */
/*<       n=2 >*/
    n = 2;
/* SOURCE orifice.for:51 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:52 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:53 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:54 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:56 */
/*<       shape=tpc >*/
    s_copy(shape, tpc, (ftnlen)6, (ftnlen)20);
/*     Process the EDGE descriptions */
/* SOURCE orifice.for:59 */
/*<       n=3 >*/
    n = 3;
/* SOURCE orifice.for:60 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:61 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:62 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:63 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:65 */
/*<       edge=tpc >*/
    s_copy(edge, tpc, (ftnlen)6, (ftnlen)20);
/*     Process the vertical diameter */
/* SOURCE orifice.for:68 */
/*<       n=4 >*/
    n = 4;
/* SOURCE orifice.for:69 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:70 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:71 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:72 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:74 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:75 */
/*<       d=0.0 >*/
	*feq_gen_d_d_ = (float)0.;
/* SOURCE orifice.for:76 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:77 */
/*<       read(tpc,*,err=999)d >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_d_d_), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:78 */
/*<       endif >*/
    }
/*     Process horizontal diameter */
/* SOURCE orifice.for:82 */
/*<       n=5 >*/
    n = 5;
/* SOURCE orifice.for:83 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:84 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:85 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:86 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:88 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:89 */
/*<       w=0.0 >*/
	*w = (float)0.;
/* SOURCE orifice.for:90 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:91 */
/*<       read(tpc,*,err=999)w >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*w), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:92 */
/*<       endif >*/
    }
/*     Process the invert elevation */
/* SOURCE orifice.for:96 */
/*<       n=6 >*/
    n = 6;
/* SOURCE orifice.for:97 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:98 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:99 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:100 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:102 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:103 */
/*<       invert=0.0 >*/
	*invert = (float)0.;
/* SOURCE orifice.for:104 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:105 */
/*<       read(tpc,*,err=999)invert >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*invert), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:106 */
/*<       endif >*/
    }
/*     Process discharge coefficient */
/* SOURCE orifice.for:109 */
/*<       n=7 >*/
    n = 7;
/* SOURCE orifice.for:110 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:111 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:112 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:113 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:115 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:116 */
/*<       cd=0.0 >*/
	*cd = (float)0.;
/* SOURCE orifice.for:117 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:118 */
/*<       read(tpc,*,err=999)cd >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*cd), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:119 */
/*<       endif >*/
    }
/*     Process the weir coefficient */
/* SOURCE orifice.for:122 */
/*<       n=8 >*/
    n = 8;
/* SOURCE orifice.for:123 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:124 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:125 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:126 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:128 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:129 */
/*<       cw=0.0 >*/
	*cw = (float)0.;
/* SOURCE orifice.for:130 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:131 */
/*<       read(tpc,*,err=999)cw >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*cw), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:132 */
/*<       endif >*/
    }
/* SOURCE orifice.for:134 */
/*<       return >*/
    return 0;
/* SOURCE orifice.for:135 */
/*<   999 continue >*/
L999:
/* SOURCE orifice.for:136 */
/*<       write(stdout,52)n,line >*/
    feq_gen_io_d__6.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__6);
    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, line, line_len);
    e_wsfe();
/* SOURCE orifice.for:137 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE orifice.for:138 */
/*<       end >*/
    return 0;
} /* read_orifice_items1__ */




/* SOURCE orifice.for:143 */
/*<        >*/
/* Subroutine */ int feq_gen_read_orifice_items2_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	eflag, integer *idlena, integer *idlenb, integer *apptab, integer *
	oritab, real *maxzup, real *minhup, real *limpfd, real *minpfd, real *
	liprec, ftnlen line_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:754* Only \002,i3,\002 items given \
in \002,\002second orifice input line.  Need at least seven items.\002)";
    static char fmt_52[] = "(/,\002 *ERR:753* Conversion error in field \002\
,i1,\002 in:\002,/,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsli(icilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_rsli();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer n, ie, is;
    char tpc[20], key[16];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, fmt_52, 0 };


/*     Get the items of data  from second line of ORIFICE data */
/* SOURCE orifice.for:153 */
/*<       implicitnone >*/
/* SOURCE orifice.for:154 */
/*<        >*/
/* SOURCE orifice.for:156 */
/*<       realmaxzup,minhup,limpfd,minpfd,liprec >*/
/* SOURCE orifice.for:157 */
/*<       characterline*(*) >*/
/*     Local */
/* SOURCE orifice.for:161 */
/*<       integerie,is,n >*/
/* SOURCE orifice.for:162 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE orifice.for:165 */
/*<       integerlenstr >*/
/* SOURCE orifice.for:166 */
/*<       externalstrip_l_blanks,lenstr,get_internal_tab_number >*/
/*     ***********************FORMATS************************************ */
/* SOURCE orifice.for:169 */
/*<    50  >*/
/* SOURCE orifice.for:171 */
/*<    52 format(/,' *ERR:753* Conversion error in field ',i1,' in:',/,a) >*/
/* *********************************************************************** */
/* SOURCE orifice.for:174 */
/*<       if(nitem.lt.7)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
/* L52: */
    if (*nitem < 7) {
/* SOURCE orifice.for:175 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__7.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__7);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE orifice.for:176 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE orifice.for:177 */
/*<       endif >*/
    }
/*     Process the approach table id */
/* SOURCE orifice.for:180 */
/*<       n=1 >*/
    n = 1;
/* SOURCE orifice.for:181 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:182 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:183 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:184 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:186 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE orifice.for:187 */
/*<       idlena=lenstr(key) >*/
    *idlena = lenstr_(key, (ftnlen)16);
/*     Convert from the table id to an internal number. */
/* SOURCE orifice.for:189 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/*       We have an id given. */
/* SOURCE orifice.for:191 */
/*<       callget_internal_tab_number(stdout,key,eflag,apptab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, apptab, (ftnlen)16);
/* SOURCE orifice.for:195 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:196 */
/*<       apptab=0 >*/
	*apptab = 0;
/* SOURCE orifice.for:197 */
/*<       endif >*/
    }
/*     Process the orifice table id */
/* SOURCE orifice.for:201 */
/*<       n=2 >*/
    n = 2;
/* SOURCE orifice.for:202 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:203 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:204 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:205 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:207 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE orifice.for:208 */
/*<       idlenb=lenstr(key) >*/
    *idlenb = lenstr_(key, (ftnlen)16);
/*     Convert from the table id to an internal number. */
/* SOURCE orifice.for:210 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/*       We have an id given. */
/* SOURCE orifice.for:212 */
/*<       callget_internal_tab_number(stdout,key,eflag,oritab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, oritab, (ftnlen)16);
/* SOURCE orifice.for:216 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:217 */
/*<       oritab=0 >*/
	*oritab = 0;
/* SOURCE orifice.for:218 */
/*<       endif >*/
    }
/*     Process maximum elevation */
/* SOURCE orifice.for:221 */
/*<       n=3 >*/
    n = 3;
/* SOURCE orifice.for:222 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:223 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:224 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:225 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:227 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:228 */
/*<       maxzup=0.0 >*/
	*maxzup = (float)0.;
/* SOURCE orifice.for:229 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:230 */
/*<       read(tpc,*,err=999)maxzup >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*maxzup), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:231 */
/*<       endif >*/
    }
/*     Process the minimum upstream head */
/* SOURCE orifice.for:235 */
/*<       n=4 >*/
    n = 4;
/* SOURCE orifice.for:236 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:237 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:238 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:239 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:241 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:242 */
/*<       minhup=0.0 >*/
	*minhup = (float)0.;
/* SOURCE orifice.for:243 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:244 */
/*<       read(tpc,*,err=999)minhup >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*minhup), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:245 */
/*<       endif >*/
    }
/*     Process the limiting partial free drop */
/* SOURCE orifice.for:249 */
/*<       n=5 >*/
    n = 5;
/* SOURCE orifice.for:250 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:251 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:252 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:253 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:255 */
/*<       if(tpc.eq.' ')then >*/
    if (s_cmp(tpc, const_cast<char*>(" "), (ftnlen)20, (ftnlen)1) == 0) {
/* SOURCE orifice.for:256 */
/*<       limpfd=0.0 >*/
	*limpfd = (float)0.;
/* SOURCE orifice.for:257 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:258 */
/*<       read(tpc,*,err=999)limpfd >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*limpfd), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:259 */
/*<       endif >*/
    }
/*     Process the minimum partial free drop */
/* SOURCE orifice.for:263 */
/*<       n=6 >*/
    n = 6;
/* SOURCE orifice.for:264 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:265 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:266 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:267 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:269 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:270 */
/*<       minpfd=0.0 >*/
	*minpfd = (float)0.;
/* SOURCE orifice.for:271 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:272 */
/*<       read(tpc,*,err=999)minpfd >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*minpfd), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:273 */
/*<       endif >*/
    }
/*     Process linear interpolation precision */
/* SOURCE orifice.for:276 */
/*<       n=7 >*/
    n = 7;
/* SOURCE orifice.for:277 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE orifice.for:278 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE orifice.for:279 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE orifice.for:280 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE orifice.for:282 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE orifice.for:283 */
/*<       liprec=0.0 >*/
	*liprec = (float)0.;
/* SOURCE orifice.for:284 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:285 */
/*<       read(tpc,*,err=999)liprec >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*liprec), (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE orifice.for:286 */
/*<       endif >*/
    }
/* SOURCE orifice.for:289 */
/*<       return >*/
    return 0;
/* SOURCE orifice.for:290 */
/*<   999 continue >*/
L999:
/* SOURCE orifice.for:291 */
/*<       write(stdout,52)n,line >*/
    feq_gen_io_d__13.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__13);
    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, line, line_len);
    e_wsfe();
/* SOURCE orifice.for:292 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE orifice.for:294 */
/*<       end >*/
    return 0;
} /* read_orifice_items2__ */

/*     *********** */
/*     *         * */
/*     * FUN_CIRC */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:301 */
/*<       doubleprecisionfunctionfun_circ(y) >*/
doublereal feq_gen_fun_circ_d_(doublereal *y)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double sqrt(doublereal);

/*     Return the vertical diameter normalized width of the */
/*     opening at the vertical diameter normalized distance */
/*     from the invert. */
/* SOURCE orifice.for:307 */
/*<       doubleprecisiony >*/
/* ********************************************************************* */
/* SOURCE orifice.for:309 */
/*<       fun_circ=2.d0*dsqrt(y*(1.d0-y)) >*/
    ret_val = sqrt(*y * (1. - *y)) * 2.;
/* SOURCE orifice.for:310 */
/*<       return >*/
    return ret_val;
/* SOURCE orifice.for:311 */
/*<       end >*/
} /* fun_circ__ */

/*     *********** */
/*     *         * */
/*     * FUN_RECT */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:318 */
/*<       doubleprecisionfunctionfun_rect(y) >*/
doublereal feq_gen_fun_rect_d_(doublereal *y)
{
    /* System generated locals */
    doublereal ret_val;

/*     Return the vertical diameter normalized width of the */
/*     opening at the vertical diameter normalized distance */
/*     from the invert. */
/* SOURCE orifice.for:324 */
/*<       doubleprecisiony >*/
/* INCLUDE orifice.for:326 */
/*     Common block for orifice shape description and computation. */
/* SOURCE orfshape.cmn:2 */
/*<       integerorifice_shape_tab,orf_num >*/
/* SOURCE orfshape.cmn:3 */
/*<       doubleprecisionw_over_d,orf_w(15),orf_x(15) >*/
/* SOURCE orfshape.cmn:4 */
/*<       common/orf_shape/w_over_d,orf_w,orf_x,orf_num,orifice_shape_tab >*/
/* ********************************************************************* */
/* SOURCE orifice.for:328 */
/*<       fun_rect=w_over_d >*/
    ret_val = feq_gen_orf_shape_d_1.feq_gen_w_over_d_d_;
/* SOURCE orifice.for:329 */
/*<       return >*/
    return ret_val;
/* SOURCE orifice.for:330 */
/*<       end >*/
} /* fun_rect__ */

/*     *********** */
/*     *         * */
/*     * FUN_TRI */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:337 */
/*<       doubleprecisionfunctionfun_tri(y) >*/
doublereal feq_gen_fun_tri_d_(doublereal *y)
{
    /* System generated locals */
    doublereal ret_val;

/*     Return the vertical diameter normalized width of the */
/*     opening at the vertical diameter normalized distance */
/*     from the invert. */
/* SOURCE orifice.for:343 */
/*<       doubleprecisiony >*/
/* INCLUDE orifice.for:345 */
/*     Common block for orifice shape description and computation. */
/* SOURCE orfshape.cmn:2 */
/*<       integerorifice_shape_tab,orf_num >*/
/* SOURCE orfshape.cmn:3 */
/*<       doubleprecisionw_over_d,orf_w(15),orf_x(15) >*/
/* SOURCE orfshape.cmn:4 */
/*<       common/orf_shape/w_over_d,orf_w,orf_x,orf_num,orifice_shape_tab >*/
/* ********************************************************************* */
/* SOURCE orifice.for:347 */
/*<       fun_tri=y*w_over_d >*/
    ret_val = *y * feq_gen_orf_shape_d_1.feq_gen_w_over_d_d_;
/* SOURCE orifice.for:348 */
/*<       return >*/
    return ret_val;
/* SOURCE orifice.for:349 */
/*<       end >*/
} /* fun_tri__ */

/*     *********** */
/*     *         * */
/*     * FUN_ODD */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:356 */
/*<       doubleprecisionfunctionfun_odd(y) >*/
doublereal feq_gen_fun_odd_d_(doublereal *y)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    real arg, pdv;
    integer ntab;
    real func;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);

/*     Return the vertical diameter normalized width of the */
/*     opening at the vertical diameter normalized distance */
/*     from the invert. */
/* SOURCE orifice.for:362 */
/*<       doubleprecisiony >*/
/* INCLUDE orifice.for:364 */
/*     Common block for orifice shape description and computation. */
/* SOURCE orfshape.cmn:2 */
/*<       integerorifice_shape_tab,orf_num >*/
/* SOURCE orfshape.cmn:3 */
/*<       doubleprecisionw_over_d,orf_w(15),orf_x(15) >*/
/* SOURCE orfshape.cmn:4 */
/*<       common/orf_shape/w_over_d,orf_w,orf_x,orf_num,orifice_shape_tab >*/
/*     Local */
/* SOURCE orifice.for:367 */
/*<       integerntab >*/
/* SOURCE orifice.for:369 */
/*<       realarg,pdv,func >*/
/* ********************************************************************* */
/* SOURCE orifice.for:371 */
/*<       arg=y >*/
    arg = *y;
/* SOURCE orifice.for:372 */
/*<       calllktab(orifice_shape_tab,arg,0,func,ntab,pdv) >*/
    lktab_(&feq_gen_orf_shape_d_1.feq_gen_orifice_shape_tab_d_, &arg, &feq_gen_c_d_0, &func, &ntab, &pdv)
	    ;
/* SOURCE orifice.for:374 */
/*<       fun_odd=func >*/
    ret_val = func;
/* SOURCE orifice.for:375 */
/*<       return >*/
    return ret_val;
/* SOURCE orifice.for:376 */
/*<       end >*/
} /* fun_odd__ */

/*     *********** */
/*     *         * */
/*     * ORF */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:383 */
/*<       doubleprecisionfunctionorf(y,a,b,h,fun) >*/
doublereal orf_(doublereal *y, doublereal *a, doublereal *b, doublereal *feq_gen_h_d_, 
	FeqCallback1 fun)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal feq_gen_z_d_;

/*     Compute the orifice/weir flow integrand for the orifice */
/*     width given by FUN.  We use the W. Kahan rescaling */
/*     to improve accuracy of integration. */
/* SOURCE orifice.for:389 */
/*<       doubleprecisiony,a,b,h,fun >*/
/* SOURCE orifice.for:391 */
/*<       externalfun >*/
/*     Local */
/* SOURCE orifice.for:394 */
/*<       doubleprecisionz >*/
/* ********************************************************************** */
/* SOURCE orifice.for:396 */
/*<       z=0.25d0*(b-a)*y*(3.d0-y*y)+.5d0*(b+a) >*/
    feq_gen_z_d_ = (*b - *a) * .25 * *y * (3. - *y * *y) + (*b + *a) * .5;
/* SOURCE orifice.for:397 */
/*<       orf=fun(z)*dsqrt(h-z)*(1-y*y) >*/
    ret_val = (*fun)(&feq_gen_z_d_) * sqrt(*feq_gen_h_d_ - feq_gen_z_d_) * (1 - *y * *y);
/* SOURCE orifice.for:398 */
/*<       return >*/
    return ret_val;
/* SOURCE orifice.for:399 */
/*<       end >*/
} /* orf_ */

/*     *********** */
/*     *         * */
/*     * WIDTH_ORF */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:406 */
/*<       doubleprecisionfunctionwidth_orf(y,a,b,fun) >*/
doublereal feq_gen_width_orf_d_(doublereal *y, doublereal *a, doublereal *b, FeqCallback1 fun)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    doublereal feq_gen_z_d_;

/*     Compute the integrand for the normalized area of an */
/*     orifice opening. */
/* SOURCE orifice.for:411 */
/*<       doubleprecisiony,a,b,fun >*/
/* SOURCE orifice.for:413 */
/*<       externalfun >*/
/*     Local */
/* SOURCE orifice.for:416 */
/*<       doubleprecisionz >*/
/* ********************************************************************** */
/* SOURCE orifice.for:418 */
/*<       z=0.25d0*(b-a)*y*(3.d0-y*y)+.5d0*(b+a) >*/
    feq_gen_z_d_ = (*b - *a) * .25 * *y * (3. - *y * *y) + (*b + *a) * .5;
/* SOURCE orifice.for:419 */
/*<       width_orf=fun(z)*(1-y*y) >*/
    ret_val = (*fun)(&feq_gen_z_d_) * (1 - *y * *y);
/* SOURCE orifice.for:420 */
/*<       return >*/
    return ret_val;
/* SOURCE orifice.for:421 */
/*<       end >*/
} /* width_orf__ */

/*     *********** */
/*     *         * */
/*     * FIND_FREE_ORIFICE */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:429 */
/*<       subroutinefind_free_orifice(stdout,hw,twf,fun,qfree,nature) >*/
/* Subroutine */ int feq_gen_find_free_orifice_d_(integer *stdout, real *hw, real *twf,
	 FeqCallback1 fun, real *qfree, char *nature, ftnlen nature_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal a, b;
    integer feq_gen_i_d_;
    doublereal hub;
    extern doublereal orf_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, FeqCallback1);
    doublereal sum;

/*     Find the relative free flow for an orifice with the given relative */
/*     headwater piezometric level. */
/* SOURCE orifice.for:435 */
/*<       implicitnone >*/
/* SOURCE orifice.for:437 */
/*<       character*2nature >*/
/* SOURCE orifice.for:439 */
/*<       integerstdout >*/
/* SOURCE orifice.for:441 */
/*<       realhw,twf,qfree >*/
/* SOURCE orifice.for:443 */
/*<       doubleprecisionfun >*/
/* SOURCE orifice.for:445 */
/*<       externalfun >*/
/* INCLUDE orifice.for:447 */
/*     Common block for orifice shape description and computation. */
/* SOURCE orfshape.cmn:2 */
/*<       integerorifice_shape_tab,orf_num >*/
/* SOURCE orfshape.cmn:3 */
/*<       doubleprecisionw_over_d,orf_w(15),orf_x(15) >*/
/* SOURCE orfshape.cmn:4 */
/*<       common/orf_shape/w_over_d,orf_w,orf_x,orf_num,orifice_shape_tab >*/
/*     Local */
/* SOURCE orifice.for:451 */
/*<       integeri >*/
/* SOURCE orifice.for:453 */
/*<       doubleprecisionsum,orf,a,b,hub >*/
/* SOURCE orifice.for:455 */
/*<       externalorf >*/
/* ********************************************************************** */
/*     We assume that the free flow is reduced as soon as the */
/*     tailwater is at or above the orifice invert. */
/* SOURCE orifice.for:460 */
/*<       twf=0.0 >*/
    *twf = (float)0.;
/*     If the relative headwater level is <= 1.0, then we have */
/*     weir flow, else we have orifice flow. */
/* SOURCE orifice.for:464 */
/*<       hub=hw >*/
    hub = *hw;
/* SOURCE orifice.for:465 */
/*<       if(hub.le.1.d0)then >*/
    if (hub <= 1.) {
/*       This is weir flow. */
/* SOURCE orifice.for:467 */
/*<       a=0.d0 >*/
	a = 0.;
/* SOURCE orifice.for:468 */
/*<       b=hub >*/
	b = hub;
/* SOURCE orifice.for:469 */
/*<       nature='FW' >*/
	s_copy(nature, const_cast<char*>("FW"), (ftnlen)2, (ftnlen)2);
/* SOURCE orifice.for:470 */
/*<       else >*/
    } else {
/*       This is orifice flow */
/* SOURCE orifice.for:472 */
/*<       a=0.d0 >*/
	a = 0.;
/* SOURCE orifice.for:473 */
/*<       b=1.d0 >*/
	b = 1.;
/* SOURCE orifice.for:474 */
/*<       nature='FO' >*/
	s_copy(nature, const_cast<char*>("FO"), (ftnlen)2, (ftnlen)2);
/* SOURCE orifice.for:475 */
/*<       endif >*/
    }
/* SOURCE orifice.for:477 */
/*<       sum=0.d0 >*/
    sum = 0.;
/* SOURCE orifice.for:478 */
/*<       do100i=1,orf_num >*/
    feq_gen_i_d_1 = feq_gen_orf_shape_d_1.feq_gen_orf_num_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE orifice.for:479 */
/*<       sum=sum+orf_w(i)*orf(orf_x(i),a,b,hub,fun) >*/
	sum += feq_gen_orf_shape_d_1.feq_gen_orf_w_d_[feq_gen_i_d_ - 1] * orf_(&feq_gen_orf_shape_d_1.feq_gen_orf_x_d_[feq_gen_i_d_ 
		- 1], &a, &b, &hub, fun);
/* SOURCE orifice.for:480 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE orifice.for:482 */
/*<       sum=0.75d0*(b-a)*sum >*/
    sum = (b - a) * .75 * sum;
/* SOURCE orifice.for:483 */
/*<       qfree=sum >*/
    *qfree = sum;
/* SOURCE orifice.for:484 */
/*<       return >*/
    return 0;
/* SOURCE orifice.for:485 */
/*<       end >*/
} /* find_free_orifice__ */

/*     *********** */
/*     *         * */
/*     * FIND_SUB_ORIFICE */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:492 */
/*<       subroutinefind_sub_orifice(stdout,hw,tw,fun,qsub,nature) >*/
/* Subroutine */ int feq_gen_find_sub_orifice_d_(integer *stdout, real *hw, real *tw, 
	FeqCallback1 fun, real *qsub, char *nature, ftnlen nature_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    doublereal a, b;
    integer feq_gen_i_d_;
    extern doublereal feq_gen_width_orf_d_(doublereal *, doublereal *, doublereal *, 
	    FeqCallback1);
    doublereal hdb, hub;
    extern doublereal orf_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, FeqCallback1);
    doublereal sum, qfree;

/*     Find the relative submerged flow for an orifice with the given */
/*     relative headwater and tailwater piezometric levels. */
/* SOURCE orifice.for:498 */
/*<       implicitnone >*/
/* SOURCE orifice.for:500 */
/*<       character*2nature >*/
/* SOURCE orifice.for:502 */
/*<       integerstdout >*/
/* SOURCE orifice.for:504 */
/*<       realhw,tw,qsub >*/
/* SOURCE orifice.for:506 */
/*<       doubleprecisionfun >*/
/* SOURCE orifice.for:508 */
/*<       externalfun >*/
/* INCLUDE orifice.for:510 */
/*     Common block for orifice shape description and computation. */
/* SOURCE orfshape.cmn:2 */
/*<       integerorifice_shape_tab,orf_num >*/
/* SOURCE orfshape.cmn:3 */
/*<       doubleprecisionw_over_d,orf_w(15),orf_x(15) >*/
/* SOURCE orfshape.cmn:4 */
/*<       common/orf_shape/w_over_d,orf_w,orf_x,orf_num,orifice_shape_tab >*/
/*     Local */
/* SOURCE orifice.for:514 */
/*<       integeri >*/
/* SOURCE orifice.for:516 */
/*<       doubleprecisionsum,orf,a,b,hub,hdb,qfree,width_orf >*/
/* SOURCE orifice.for:518 */
/*<       externalorf,width_orf >*/
/* ********************************************************************** */
/*     If the relative headwater level is <= 1.0, then we have */
/*     weir flow, else we have orifice flow. */
/* SOURCE orifice.for:523 */
/*<       hub=hw >*/
    hub = *hw;
/* SOURCE orifice.for:524 */
/*<       hdb=tw >*/
    hdb = *tw;
/* SOURCE orifice.for:525 */
/*<       if(hdb.ge.1.0)then >*/
    if (hdb >= (float)1.) {
/*       The opening is completely submerged. */
/*       Compute flow using head difference and the area of the */
/*       opening. */
/* SOURCE orifice.for:529 */
/*<       nature='SO' >*/
	s_copy(nature, const_cast<char*>("SO"), (ftnlen)2, (ftnlen)2);
/*       Now compute the full area. */
/* SOURCE orifice.for:532 */
/*<       a=0.d0 >*/
	a = 0.;
/* SOURCE orifice.for:533 */
/*<       b=1.0 >*/
	b = (float)1.;
/* SOURCE orifice.for:534 */
/*<       sum=0.d0 >*/
	sum = 0.;
/* SOURCE orifice.for:535 */
/*<       do300i=1,orf_num >*/
	feq_gen_i_d_1 = feq_gen_orf_shape_d_1.feq_gen_orf_num_d_;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE orifice.for:536 */
/*<       sum=sum+orf_w(i)*width_orf(orf_x(i),a,b,fun) >*/
	    sum += feq_gen_orf_shape_d_1.feq_gen_orf_w_d_[feq_gen_i_d_ - 1] * feq_gen_width_orf_d_(&
		    feq_gen_orf_shape_d_1.feq_gen_orf_x_d_[feq_gen_i_d_ - 1], &a, &b, fun);
/* SOURCE orifice.for:537 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE orifice.for:538 */
/*<       sum=0.75d0*(b-a)*sum*dsqrt(hub-hdb) >*/
	sum = (b - a) * .75 * sum * sqrt(hub - hdb);
/* SOURCE orifice.for:539 */
/*<       qsub=sum >*/
	*qsub = sum;
/* SOURCE orifice.for:540 */
/*<       else >*/
    } else {
/* SOURCE orifice.for:541 */
/*<       if(hub.le.1.d0)then >*/
	if (hub <= 1.) {
/*         This is weir flow.  Define the free part */
/* SOURCE orifice.for:543 */
/*<       a=hdb >*/
	    a = hdb;
/* SOURCE orifice.for:544 */
/*<       b=hub >*/
	    b = hub;
/* SOURCE orifice.for:545 */
/*<       nature='SW' >*/
	    s_copy(nature, const_cast<char*>("SW"), (ftnlen)2, (ftnlen)2);
/* SOURCE orifice.for:546 */
/*<       else >*/
	} else {
/*         This is orifice flow */
/*         The opening is only partially submerged.   Define the */
/*         free part. */
/* SOURCE orifice.for:550 */
/*<       nature='SO' >*/
	    s_copy(nature, const_cast<char*>("SO"), (ftnlen)2, (ftnlen)2);
/* SOURCE orifice.for:551 */
/*<       a=hdb >*/
	    a = hdb;
/* SOURCE orifice.for:552 */
/*<       b=1.0 >*/
	    b = (float)1.;
/* SOURCE orifice.for:553 */
/*<       endif >*/
	}
/* SOURCE orifice.for:554 */
/*<       sum=0.d0 >*/
	sum = 0.;
/* SOURCE orifice.for:555 */
/*<       do100i=1,orf_num >*/
	feq_gen_i_d_1 = feq_gen_orf_shape_d_1.feq_gen_orf_num_d_;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE orifice.for:556 */
/*<       sum=sum+orf_w(i)*orf(orf_x(i),a,b,hub,fun) >*/
	    sum += feq_gen_orf_shape_d_1.feq_gen_orf_w_d_[feq_gen_i_d_ - 1] * orf_(&feq_gen_orf_shape_d_1.feq_gen_orf_x_d_[
		    feq_gen_i_d_ - 1], &a, &b, &hub, fun);
/* SOURCE orifice.for:557 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE orifice.for:558 */
/*<       sum=0.75d0*(b-a)*sum >*/
	sum = (b - a) * .75 * sum;
/* SOURCE orifice.for:559 */
/*<       qfree=sum >*/
	qfree = sum;
/*       Now compute the partial area. */
/* SOURCE orifice.for:562 */
/*<       a=0.d0 >*/
	a = 0.;
/* SOURCE orifice.for:563 */
/*<       b=hdb >*/
	b = hdb;
/* SOURCE orifice.for:564 */
/*<       sum=0.d0 >*/
	sum = 0.;
/* SOURCE orifice.for:565 */
/*<       do200i=1,orf_num >*/
	feq_gen_i_d_1 = feq_gen_orf_shape_d_1.feq_gen_orf_num_d_;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE orifice.for:566 */
/*<       sum=sum+orf_w(i)*width_orf(orf_x(i),a,b,fun) >*/
	    sum += feq_gen_orf_shape_d_1.feq_gen_orf_w_d_[feq_gen_i_d_ - 1] * feq_gen_width_orf_d_(&
		    feq_gen_orf_shape_d_1.feq_gen_orf_x_d_[feq_gen_i_d_ - 1], &a, &b, fun);
/* SOURCE orifice.for:567 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE orifice.for:568 */
/*<       sum=0.75d0*(b-a)*sum*dsqrt(hub-hdb) >*/
	sum = (b - a) * .75 * sum * sqrt(hub - hdb);
/* SOURCE orifice.for:570 */
/*<       qsub=qfree+sum >*/
	*qsub = qfree + sum;
/* SOURCE orifice.for:571 */
/*<       endif >*/
    }
/* SOURCE orifice.for:573 */
/*<       qfree=sum >*/
    qfree = sum;
/* SOURCE orifice.for:574 */
/*<       return >*/
    return 0;
/* SOURCE orifice.for:575 */
/*<       end >*/
} /* find_sub_orifice__ */

/*     *********** */
/*     *         * */
/*     * FIND_SUB_ORIFICE_FLOW */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:582 */
/*<        >*/
/* Subroutine */ int feq_gen_find_sub_orifice_flow_d_(integer *stdout, real *feq_gen_hw_rel_d_, 
	real *feq_gen_tw_rel_d_, char *shape, real *qsub, char *nature, ftnlen 
	shape_len, ftnlen nature_len)
{
    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern doublereal feq_gen_fun_circ_d_(doublereal *), feq_gen_fun_rect_d_(doublereal *);
    extern /* Subroutine */ int feq_gen_find_sub_orifice_d_(integer *, real *, real *, 
	    FeqCallback1, real *, char *, ftnlen);
    extern doublereal feq_gen_fun_odd_d_(doublereal *), feq_gen_fun_tri_d_(doublereal *);

/*     Find submerged flow cases. */
/* SOURCE orifice.for:586 */
/*<       implicitnone >*/
/* SOURCE orifice.for:588 */
/*<       characternature*2,shape*6 >*/
/* SOURCE orifice.for:590 */
/*<       integerstdout >*/
/* SOURCE orifice.for:592 */
/*<       realhw_rel,tw_rel,qsub >*/
/*     Local */
/* SOURCE orifice.for:595 */
/*<       doubleprecisionfun_circ,fun_rect,fun_tri,fun_odd >*/
/* SOURCE orifice.for:596 */
/*<       externalfun_circ,fun_rect,fun_tri,fun_odd >*/
/* ********************************************************************** */
/* SOURCE orifice.for:598 */
/*<       if(shape.eq.'CIRC')then >*/
    if (s_cmp(shape, const_cast<char*>("CIRC"), (ftnlen)6, (ftnlen)4) == 0) {
/* SOURCE orifice.for:599 */
/*<       callfind_sub_orifice(stdout,hw_rel,tw_rel,fun_circ,qsub,nature) >*/
	feq_gen_find_sub_orifice_d_(stdout, feq_gen_hw_rel_d_, feq_gen_tw_rel_d_, feq_gen_fun_circ_d_, qsub,
		 nature, (ftnlen)2);
/* SOURCE orifice.for:601 */
/*<       elseif(shape.eq.'RECT')then >*/
    } else if (s_cmp(shape, const_cast<char*>("RECT"), (ftnlen)6, (ftnlen)4) == 0) {
/* SOURCE orifice.for:602 */
/*<       callfind_sub_orifice(stdout,hw_rel,tw_rel,fun_rect,qsub,nature) >*/
	feq_gen_find_sub_orifice_d_(stdout, feq_gen_hw_rel_d_, feq_gen_tw_rel_d_, feq_gen_fun_rect_d_, qsub,
		 nature, (ftnlen)2);
/* SOURCE orifice.for:604 */
/*<       elseif(shape.eq.'TRI')then >*/
    } else if (s_cmp(shape, const_cast<char*>("TRI"), (ftnlen)6, (ftnlen)3) == 0) {
/* SOURCE orifice.for:605 */
/*<       callfind_sub_orifice(stdout,hw_rel,tw_rel,fun_tri,qsub,nature) >*/
	feq_gen_find_sub_orifice_d_(stdout, feq_gen_hw_rel_d_, feq_gen_tw_rel_d_, feq_gen_fun_tri_d_, qsub, 
		nature, (ftnlen)2);
/* SOURCE orifice.for:607 */
/*<       elseif(shape.eq.'ODD')then >*/
    } else if (s_cmp(shape, const_cast<char*>("ODD"), (ftnlen)6, (ftnlen)3) == 0) {
/* SOURCE orifice.for:608 */
/*<       callfind_sub_orifice(stdout,hw_rel,tw_rel,fun_odd,qsub,nature) >*/
	feq_gen_find_sub_orifice_d_(stdout, feq_gen_hw_rel_d_, feq_gen_tw_rel_d_, feq_gen_fun_odd_d_, qsub, 
		nature, (ftnlen)2);
/* SOURCE orifice.for:610 */
/*<       endif >*/
    }
/* SOURCE orifice.for:611 */
/*<       return >*/
    return 0;
/* SOURCE orifice.for:612 */
/*<       end >*/
} /* find_sub_orifice_flow__ */

/*     *********** */
/*     *         * */
/*     * FIND_FREE_ORIFICE_FLOW */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:619 */
/*<        >*/
/* Subroutine */ int feq_gen_find_free_orifice_flow_d_(integer *stdout, real *feq_gen_hw_rel_d_,
	 real *feq_gen_twf_rel_d_, char *shape, real *qfree, char *nature, ftnlen 
	shape_len, ftnlen nature_len)
{
    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern doublereal feq_gen_fun_circ_d_(doublereal *), feq_gen_fun_rect_d_(doublereal *);
    extern /* Subroutine */ int feq_gen_find_free_orifice_d_(integer *, real *, real *,
	     FeqCallback1, real *, char *, ftnlen);
    extern doublereal feq_gen_fun_odd_d_(doublereal *), feq_gen_fun_tri_d_(doublereal *);

/*     Find free orifice flow.  Could be weir flow if the orifice is */
/*     not submerged enough. */
/* SOURCE orifice.for:625 */
/*<       implicitnone >*/
/* SOURCE orifice.for:627 */
/*<       characternature*2,shape*6 >*/
/* SOURCE orifice.for:629 */
/*<       integerstdout >*/
/* SOURCE orifice.for:631 */
/*<       realhw_rel,twf_rel,qfree >*/
/*     Local */
/* SOURCE orifice.for:634 */
/*<       doubleprecisionfun_circ,fun_rect,fun_tri,fun_odd >*/
/* SOURCE orifice.for:635 */
/*<       externalfun_circ,fun_rect,fun_tri,fun_odd >*/
/* ********************************************************************** */
/* SOURCE orifice.for:638 */
/*<       if(shape.eq.'CIRC')then >*/
    if (s_cmp(shape, const_cast<char*>("CIRC"), (ftnlen)6, (ftnlen)4) == 0) {
/* SOURCE orifice.for:639 */
/*<       callfind_free_orifice(stdout,hw_rel,twf_rel,fun_circ,qfree,nature) >*/
	feq_gen_find_free_orifice_d_(stdout, feq_gen_hw_rel_d_, feq_gen_twf_rel_d_, feq_gen_fun_circ_d_, 
		qfree, nature, (ftnlen)2);
/* SOURCE orifice.for:641 */
/*<       elseif(shape.eq.'RECT')then >*/
    } else if (s_cmp(shape, const_cast<char*>("RECT"), (ftnlen)6, (ftnlen)4) == 0) {
/* SOURCE orifice.for:642 */
/*<       callfind_free_orifice(stdout,hw_rel,twf_rel,fun_rect,qfree,nature) >*/
	feq_gen_find_free_orifice_d_(stdout, feq_gen_hw_rel_d_, feq_gen_twf_rel_d_, feq_gen_fun_rect_d_, 
		qfree, nature, (ftnlen)2);
/* SOURCE orifice.for:644 */
/*<       elseif(shape.eq.'TRI')then >*/
    } else if (s_cmp(shape, const_cast<char*>("TRI"), (ftnlen)6, (ftnlen)3) == 0) {
/* SOURCE orifice.for:645 */
/*<       callfind_free_orifice(stdout,hw_rel,twf_rel,fun_tri,qfree,nature) >*/
	feq_gen_find_free_orifice_d_(stdout, feq_gen_hw_rel_d_, feq_gen_twf_rel_d_, feq_gen_fun_tri_d_, 
		qfree, nature, (ftnlen)2);
/* SOURCE orifice.for:647 */
/*<       elseif(shape.eq.'ODD')then >*/
    } else if (s_cmp(shape, const_cast<char*>("ODD"), (ftnlen)6, (ftnlen)3) == 0) {
/* SOURCE orifice.for:648 */
/*<       callfind_free_orifice(stdout,hw_rel,twf_rel,fun_odd,qfree,nature) >*/
	feq_gen_find_free_orifice_d_(stdout, feq_gen_hw_rel_d_, feq_gen_twf_rel_d_, feq_gen_fun_odd_d_, 
		qfree, nature, (ftnlen)2);
/* SOURCE orifice.for:650 */
/*<       endif >*/
    }
/* SOURCE orifice.for:652 */
/*<       return >*/
    return 0;
/* SOURCE orifice.for:653 */
/*<       end >*/
} /* find_free_orifice_flow__ */

/*     *********** */
/*     *         * */
/*     * ORIFICE */
/*     *         * */
/*     *********** */
/* SOURCE orifice.for:660 */
/*<       subroutineorifice(grav,stdin,stdout,stdtab,eflag,tabdir,ftp) >*/
/* Subroutine */ int orifice_(real *grav, integer *stdin, integer *stdout, 
	integer *stdtab, integer *eflag, integer *feq_storage_tabdir, integer *ftp)
{
    /* Format strings */
    static char fmt_2[] = "(6x,a)";
    static char fmt_50[] = "(/,\002 Table Id= \002,a,\002 for type 13 table \
for orifice.\002)";
    static char fmt_52[] = "(/,\002 Label=\002,a50)";
    static char fmt_54[] = "(\002 \002,\002Number  Shape   Edge VertD HoriD \
Invrt OrifC WeirC\002)";
    static char fmt_55[] = "(a,\002AppTbId\002,a,\002OriTbId MxZup MnHup MxP\
FD MnPFD LIPrc\002)";
    static char fmt_56[] = "(1x,i6,1x,a6,1x,a6,2f6.2,f6.2,2f6.3)";
    static char fmt_58[] = "(a,a,2f6.1,2f6.3,f6.2)";
    static char fmt_60[] = "(/,\002 Datum for defining heads=\002,f10.2)";
    static char fmt_62[] = "(/,\002 *ERR:580* Shape is ODD but orifice table\
 number,\002,\002 ORITAB, is blank.\002)";
    static char fmt_72[] = "(/,\002Upstream head=\002,f9.4,\002 Elevation\
=\002,f10.4,\002 Free flow=\002,a8)";
    static char fmt_74[] = "(/,\002  Partial  Drop    Elev.   Head    Flow D\
ischarge Local\002,/,\002   free    sect.   sect.   sect.   Code           p\
ower\002,/,\002   drop    1->4     4       4\002,/,\002 --------  ------  --\
----  ------   --- --------- ------\002)";
    static char fmt_75[] = "(1x,f8.4,f8.3,f8.3,f8.3,3x,a3,2x,a8,f7.2)";
    static char fmt_78[] = "(/,\002  *ERR:634* Maximum ups head=\002,f8.2\
,\002 <= 0.\002,\002 Max ups elev=\002,f8.2,\002 and head datum=\002,f8.2)";
    static char fmt_80[] = "(/,\002 *WRN:595* Minimum non-zero upstream he\
ad=\002,f8.2,\002 <= 0.\002,\002 Setting to 0.15\002)";
    static char fmt_86[] = "(/,\002 Maximum relative error=\002,f6.3,\002  U\
pstream head=\002,f9.4,/,\002  and partial free drop=\002,f8.5)";
    static char fmt_88[] = "(/\002 Root-mean-squared error=\002,f6.3,\002 N \
in sample=\002,i5)";
    static char fmt_89[] = "(\002  Processing ORIFICE TabId= \002,a)";
    static char fmt_99[] = "(/,\002 *ERR:635* Interpolation precision tables\
 missing.\002,\002 Check for version\002,/,11x,\002of file: TYPE5.TAB.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen), 
	    s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, ftnlen, ftnlen)
	    ;
    double log(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_n_global_d_, feq_gen_item_end_d_[8];
    char apptabid[16], oritabid[16];
    real feq_gen_twf_relt_d_;
    doublereal northing;
    real feq_gen_d_d_;
    integer feq_gen_i_d_, j, l;
    real w;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer w1, w2;
    real cd, ce, feq_gen_sqrt_of_2g_d_;
    char cq[8];
    real cw, ya;
    integer nn, it;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    real hw, feq_gen_head_datum_d_, tw, feq_gen_rms_global_d_;
    integer w1a, w2a, feq_gen_item_start_d_[8], tab;
    real pfd, hwe;
    char key[16];
    extern /* Subroutine */ int feq_gen_read_orifice_items1_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, char *, char *, real *
	    , real *, real *, real *, real *, ftnlen, ftnlen, ftnlen), 
	    feq_gen_read_orifice_items2_d_(integer *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, real *, real *, real *, ftnlen);
    real twe, twf;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen);
    real pow;
    char edge[6];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real appa;
    integer ipfd;
    char line[80];
    extern /* Subroutine */ int lkta_(integer *, real *, real *);
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_qmat(53001);
    real qhat, herr, *qmat = feq_heap_qmat.data()	/* was [151][351] */, drop;
    integer ihup;
    real xbrk[351], twef;
    integer nhup;
    real rerr, qsub;
    char zone[8];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real work[351];
    char just[5], label[50], tabid[16];
    integer jbase;
    real fdvec[151];
    integer nfrac;
    char hgrid[8], shape[6];
    integer tabgt;
    real qfree;
    integer tablt, nitem;
    real fdrop, htemp, appzb;
    char tempa[25], tempb[25];
    integer ftpup;
    char basis[8];
    extern /* Subroutine */ int grule_(integer *, doublereal *, doublereal *);
    real feq_gen_orifice_limit_d_;
    extern /* Subroutine */ int feq_gen_find_sub_orifice_flow_d_(integer *, real *, 
	    real *, char *, real *, char *, ftnlen, ftnlen);
    integer idlena, idlenb;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), tabchk_(integer *, integer *, 
	    integer *, integer *, integer *);
    integer apptab, oritab;
    real bigerr, limpfd, liprec;
    integer number;
    real hupvec[151], maxzup, maxhup, minhup, minpfd, pfdtmp[351], pfdvec[351]
	    , invert, feq_gen_hw_rel_d_, feq_gen_tw_rel_d_, offset, zrhufd;
    char nature[2], vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     lstopf_(integer *, integer *, integer *, real *, real *, real *, 
	    real *, real *, integer *, integer *, real *, integer *), twdout_(
	    integer *, integer *, integer *, char *, integer *, integer *, 
	    real *, real *, real *, real *, real *, integer *, char *, real *,
	     char *, char *, char *, char *, char *, doublereal *, doublereal 
	    *, integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), feq_gen_get_lctn_items_d_(integer *, integer *, integer *), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), fndelv_(integer *, integer *, integer *, real *), 
	    feq_gen_find_free_orifice_flow_d_(integer *, real *, real *, char *, real *
	    , char *, ftnlen, ftnlen);
    doublereal easting;
    real fnumber, feq_gen_twf_rel_d_, feq_gen_hw_relt_d_;
    integer verbose;
    extern /* Subroutine */ int twodfit_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    char *, real *, integer *, integer *, integer *, integer *, 
	    ftnlen), feq_gen_get_item_limits_d_(integer *, char *, integer *, char *, 
	    integer *, integer *, integer *, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__45 = { 0, 6, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__140 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, 0, 0 };


/*     Compute a 2-D table of type 13 for a vertical orifice. */
/* SOURCE orifice.for:665 */
/*<       implicitnone >*/
/*     Dummy arguments */
/* SOURCE orifice.for:667 */
/*<       integereflag,stdin,stdout,stdtab,ftp >*/
/* SOURCE orifice.for:668 */
/*<       integertabdir(*) >*/
/* SOURCE orifice.for:669 */
/*<       realgrav >*/
/*     DEFINITIONS */
/*     GRAV   - value of acceleration due to gravity */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TABDIR - Table directory to remember table numbers */
/* INCLUDE orifice.for:679 */
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
/* INCLUDE orifice.for:680 */
/* ********************************************************************** */
/* SOURCE ftable.cmn:2 */
/*<       common/ftable/dtab >*/
/* SOURCE ftable.cmn:3 */
/*<       common/ftablea/longdummy,itmp,knt_of_ftabs,ftpnt >*/
/* SOURCE ftable.cmn:4 */
/*<       common/ftablec/ft_loc_status >*/
/* SOURCE ftable.cmn:6 */
/*<       integerftpnt(mftnum+5) >*/
/* SOURCE ftable.cmn:7 */
/*<       character*1ft_loc_status(mftnum) >*/
/* SOURCE ftable.cmn:9 */
/*<       realftab(0:mrftab) >*/
/* SOURCE ftable.cmn:10 */
/*<       real*8dtab(0:mdftab) >*/
/* SOURCE ftable.cmn:12 */
/*<       real*8longdummy >*/
/* SOURCE ftable.cmn:14 */
/*<       integeritmp,itab(0:mrftab),knt_of_ftabs >*/
/* SOURCE ftable.cmn:16 */
/*<       realrtmp >*/
/* SOURCE ftable.cmn:18 */
/*<       equivalence(dtab,ftab,itab) >*/
/* SOURCE ftable.cmn:19 */
/*<       equivalence(itmp,rtmp) >*/
/* SOURCE ftable.cmn:21 */
/*<       save/ftable/,/ftablea/,/ftablec/ >*/
/* ********************************************************************** */
/* INCLUDE orifice.for:681 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE orifice.for:682 */
/*     Common block for orifice shape description and computation. */
/* SOURCE orfshape.cmn:2 */
/*<       integerorifice_shape_tab,orf_num >*/
/* SOURCE orfshape.cmn:3 */
/*<       doubleprecisionw_over_d,orf_w(15),orf_x(15) >*/
/* SOURCE orfshape.cmn:4 */
/*<       common/orf_shape/w_over_d,orf_w,orf_x,orf_num,orifice_shape_tab >*/
/* INCLUDE orifice.for:683 */
/*     common for passing info for table upgrading-going from one form */
/*     to one that is smoother in its representation */
/* SOURCE tabupgrade.cmn:4 */
/*<       characterty13_to_ty43*4,twod_cubic_out*4,upgrade_xsec_tab*4 >*/
/* SOURCE tabupgrade.cmn:6 */
/*<       common/upgrdc/ty13_to_ty43,twod_cubic_out,upgrade_xsec_tab >*/
/*     Local */
/* SOURCE orifice.for:686 */
/*<       integermaxn >*/
/* SOURCE orifice.for:687 */
/*<       parameter(maxn=8) >*/
/* SOURCE orifice.for:688 */
/*<        >*/
/* SOURCE orifice.for:693 */
/*<        >*/
/* SOURCE orifice.for:702 */
/*<       real*8fun_circ,fun_rect,fun_tri,fun_odd,easting,northing >*/
/* SOURCE orifice.for:704 */
/*<        >*/
/*     Intrinsics */
/* SOURCE orifice.for:710 */
/*<       intrinsicabs,float,log,sqrt >*/
/*     External names */
/* SOURCE orifice.for:714 */
/*<       character*16get_tabid >*/
/* SOURCE orifice.for:715 */
/*<       integerlenstr >*/
/* SOURCE orifice.for:716 */
/*<        >*/
/*     ************************************FORMATS********************** */
/* SOURCE orifice.for:720 */
/*<     1 format(7x,i5) >*/
/* SOURCE orifice.for:721 */
/*<     2 format(6x,a) >*/
/* SOURCE orifice.for:722 */
/*<     4 format(i6,2a6,5f6.0) >*/
/* SOURCE orifice.for:723 */
/*<     6 format(2i6,5f6.0) >*/
/* SOURCE orifice.for:725 */
/*<    50 format(/,' Table Id= ',a,' for type 13 table for orifice.') >*/
/* SOURCE orifice.for:726 */
/*<    52 format(/,' Label=',a50) >*/
/* SOURCE orifice.for:727 */
/*<    54 format(' ','Number  Shape   Edge VertD HoriD Invrt OrifC WeirC') >*/
/* SOURCE orifice.for:728 */
/*<    55 format(a,'AppTbId',a,'OriTbId MxZup MnHup MxPFD MnPFD LIPrc') >*/
/* SOURCE orifice.for:729 */
/*<    56 format(1x,i6,1x,a6,1x,a6,2f6.2,f6.2,2f6.3) >*/
/* SOURCE orifice.for:730 */
/*<    58 format(a,a,2f6.1,2f6.3,f6.2) >*/
/* SOURCE orifice.for:731 */
/*<    60 format(/,' Datum for defining heads=',f10.2) >*/
/* SOURCE orifice.for:732 */
/*<    62  >*/
/* SOURCE orifice.for:734 */
/*<    72  >*/
/* SOURCE orifice.for:736 */
/*<    74  >*/
/* SOURCE orifice.for:741 */
/*<    75 format(1x,f8.4,f8.3,f8.3,f8.3,3x,a3,2x,a8,f7.2) >*/
/* SOURCE orifice.for:742 */
/*<    78  >*/
/* SOURCE orifice.for:744 */
/*<    80  >*/
/* SOURCE orifice.for:746 */
/*<    86  >*/
/* SOURCE orifice.for:748 */
/*<    88 format(/' Root-mean-squared error=',f6.3,' N in sample=',i5) >*/
/* SOURCE orifice.for:749 */
/*<    89 format('  Processing ORIFICE TabId= ',a) >*/
/* SOURCE orifice.for:750 */
/*<    99  >*/
/* ********************************************************************** */
/* SOURCE orifice.for:753 */
/*<       sqrt_of_2g=sqrt(2.*grav) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L4: */
/* L6: */
/* L50: */
/* L52: */
/* L54: */
/* L55: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L72: */
/* L74: */
/* L75: */
/* L78: */
/* L80: */
/* L86: */
/* L88: */
/* L89: */
/* L99: */
    feq_gen_sqrt_of_2g_d_ = sqrt(static_cast<double>(*grav) * (float)2.);
/* SOURCE orifice.for:754 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/*     Define the linear interpolation precision tables. */
/* SOURCE orifice.for:756 */
/*<       key='10001' >*/
    s_copy(key, const_cast<char*>("10001"), (ftnlen)16, (ftnlen)5);
/* SOURCE orifice.for:757 */
/*<       callget_internal_tab_number(stdout,key,eflag,tablt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &tablt, (ftnlen)16);
/* SOURCE orifice.for:761 */
/*<       tablt=ftpnt(tablt) >*/
    tablt = ftablea_1.ftpnt[tablt - 1];
/* SOURCE orifice.for:762 */
/*<       key='10002' >*/
    s_copy(key, const_cast<char*>("10002"), (ftnlen)16, (ftnlen)5);
/* SOURCE orifice.for:763 */
/*<       callget_internal_tab_number(stdout,key,eflag,tabgt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &tabgt, (ftnlen)16);
/* SOURCE orifice.for:767 */
/*<       tabgt=ftpnt(tabgt) >*/
    tabgt = ftablea_1.ftpnt[tabgt - 1];
/* SOURCE orifice.for:768 */
/*<       if(tablt.lt.1.or.tabgt.lt.1)then >*/
    if (tablt < 1 || tabgt < 1) {
/* SOURCE orifice.for:769 */
/*<       write(stdout,99) >*/
	feq_gen_io_d__40.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__40);
	e_wsfe();
/* SOURCE orifice.for:770 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE orifice.for:771 */
/*<       return >*/
	return 0;
/* SOURCE orifice.for:772 */
/*<       endif >*/
    }
/*     Define the Guass rule values for numerical integration. */
/* SOURCE orifice.for:774 */
/*<       orf_num=10 >*/
    feq_gen_orf_shape_d_1.feq_gen_orf_num_d_ = 10;
/* SOURCE orifice.for:775 */
/*<       callgrule(orf_num,orf_x,orf_w) >*/
    grule_(&feq_gen_orf_shape_d_1.feq_gen_orf_num_d_, feq_gen_orf_shape_d_1.feq_gen_orf_x_d_, 
	    feq_gen_orf_shape_d_1.feq_gen_orf_w_d_);
/* SOURCE orifice.for:779 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE orifice.for:781 */
/*<       callread_tabid(stdout,line,'TAB',eflag,tabid,tab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("TAB"), eflag, tabid, &tab, (ftnlen)80, (ftnlen)
	    3, (ftnlen)16);
/*      READ(LINE,1,ERR=991) TAB */
/* SOURCE orifice.for:785 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)) >*/
    feq_gen_io_d__44.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__44);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE orifice.for:786 */
/*<       write(*,89)tabid(1:lenstr(tabid)) >*/
    s_wsfe(&feq_gen_io_d__45);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE orifice.for:788 */
/*<       calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE orifice.for:794 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE orifice.for:796 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE orifice.for:800 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE orifice.for:802 */
/*<       read(line,2,err=991)label >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE orifice.for:803 */
/*<       write(stdout,52)label >*/
    feq_gen_io_d__54.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__54);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/*     Get the heading line. */
/* SOURCE orifice.for:806 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/*      WRITE(STDOUT,54) LINE */
/* SOURCE orifice.for:810 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_8, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)80, (ftnlen)5);
/* SOURCE orifice.for:814 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/*      READ(LINE,4,ERR=991) NUMBER, SHAPE, EDGE, D, W, INVERT, CD, CW */
/* SOURCE orifice.for:818 */
/*<        >*/
    feq_gen_read_orifice_items1_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, &
	    number, shape, edge, &feq_gen_d_d_, &w, &invert, &cd, &cw, (ftnlen)80, (
	    ftnlen)6, (ftnlen)6);
/* SOURCE orifice.for:823 */
/*<       if(edge.eq.'     ')edge='SHARP' >*/
    if (s_cmp(edge, const_cast<char*>("     "), (ftnlen)6, (ftnlen)5) == 0) {
	s_copy(edge, const_cast<char*>("SHARP"), (ftnlen)6, (ftnlen)5);
    }
/* SOURCE orifice.for:824 */
/*<       if(number.eq.0)number=1 >*/
    if (number == 0) {
	number = 1;
    }
/* SOURCE orifice.for:825 */
/*<       write(stdout,54) >*/
    feq_gen_io_d__66.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__66);
    e_wsfe();
/* SOURCE orifice.for:826 */
/*<       l=lenstr(shape) >*/
    l = lenstr_(shape, (ftnlen)6);
/* SOURCE orifice.for:827 */
/*<       tempa=' ' >*/
    s_copy(tempa, const_cast<char*>(" "), (ftnlen)25, (ftnlen)1);
/* SOURCE orifice.for:828 */
/*<       tempb=' ' >*/
    s_copy(tempb, const_cast<char*>(" "), (ftnlen)25, (ftnlen)1);
/* SOURCE orifice.for:829 */
/*<       tempa(1+6-l:)=shape >*/
    feq_gen_i_d_1 = 7 - l - 1;
    s_copy(tempa + feq_gen_i_d_1, shape, 25 - feq_gen_i_d_1, (ftnlen)6);
/* SOURCE orifice.for:830 */
/*<       l=lenstr(edge) >*/
    l = lenstr_(edge, (ftnlen)6);
/* SOURCE orifice.for:831 */
/*<       tempb(1+6-l:)=edge >*/
    feq_gen_i_d_1 = 7 - l - 1;
    s_copy(tempb + feq_gen_i_d_1, edge, 25 - feq_gen_i_d_1, (ftnlen)6);
/* SOURCE orifice.for:832 */
/*<       write(stdout,56)number,tempa(1:6),tempb(1:6),d,w,invert,cd,cw >*/
    feq_gen_io_d__70.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__70);
    do_fio(&feq_gen_c_d_1, (char *)&number, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, tempa, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, tempb, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&w, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&invert, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&cd, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&cw, (ftnlen)sizeof(real));
    e_wsfe();
/*      CALL STRIP_L_BLANKS(SHAPE) */
/*      CALL STRIP_L_BLANKS(EDGE) */
/* SOURCE orifice.for:836 */
/*<       if(shape.eq.'ROUND'.or.shape.eq.'CIRCLE'.or.shape.eq.'CIRC')then >*/
    if (s_cmp(shape, const_cast<char*>("ROUND"), (ftnlen)6, (ftnlen)5) == 0 || s_cmp(shape, 
	    const_cast<char*>("CIRCLE"), (ftnlen)6, (ftnlen)6) == 0 || s_cmp(shape, const_cast<char*>("CIRC"), (
	    ftnlen)6, (ftnlen)4) == 0) {
/* SOURCE orifice.for:837 */
/*<       shape='CIRC' >*/
	s_copy(shape, const_cast<char*>("CIRC"), (ftnlen)6, (ftnlen)4);
/* SOURCE orifice.for:838 */
/*<       w=d >*/
	w = feq_gen_d_d_;
/* SOURCE orifice.for:839 */
/*<       endif >*/
    }
/* SOURCE orifice.for:841 */
/*<       if(shape.eq.'OTHER')then >*/
    if (s_cmp(shape, const_cast<char*>("OTHER"), (ftnlen)6, (ftnlen)5) == 0) {
/* SOURCE orifice.for:842 */
/*<       shape='ODD' >*/
	s_copy(shape, const_cast<char*>("ODD"), (ftnlen)6, (ftnlen)3);
/* SOURCE orifice.for:843 */
/*<       endif >*/
    }
/* SOURCE orifice.for:844 */
/*<       if(shape.eq.'INVTRI')then >*/
    if (s_cmp(shape, const_cast<char*>("INVTRI"), (ftnlen)6, (ftnlen)6) == 0) {
/* SOURCE orifice.for:845 */
/*<       shape='TRI' >*/
	s_copy(shape, const_cast<char*>("TRI"), (ftnlen)6, (ftnlen)3);
/* SOURCE orifice.for:846 */
/*<       endif >*/
    }
/* SOURCE orifice.for:847 */
/*<       fnumber=number >*/
    fnumber = (real) number;
/*     Get the heading line. */
/* SOURCE orifice.for:849 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/*      WRITE(STDOUT,54) LINE */
/* SOURCE orifice.for:852 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_8, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)80, (ftnlen)5);
/* SOURCE orifice.for:856 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/*      READ(LINE,6,ERR=991) APPTAB, ORITAB, MAXZUP, MINHUP, */
/*     A       LIMPFD, MINPFD, LIPREC */
/* SOURCE orifice.for:860 */
/*<        >*/
    feq_gen_read_orifice_items2_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, 
	    eflag, &idlena, &idlenb, &apptab, &oritab, &maxzup, &minhup, &
	    limpfd, &minpfd, &liprec, (ftnlen)80);
/* SOURCE orifice.for:867 */
/*<       apptabid=get_tabid(apptab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &apptab);
    s_copy(apptabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE orifice.for:868 */
/*<       oritabid=get_tabid(oritab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &oritab);
    s_copy(oritabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE orifice.for:869 */
/*<       w1=item_end(1)-item_start(1)+1 >*/
    w1 = feq_gen_item_end_d_[0] - feq_gen_item_start_d_[0] + 1;
/* SOURCE orifice.for:870 */
/*<       w2=item_end(2)-item_start(2)+1 >*/
    w2 = feq_gen_item_end_d_[1] - feq_gen_item_start_d_[1] + 1;
/* SOURCE orifice.for:871 */
/*<       w1a=w1 >*/
    w1a = w1;
/* SOURCE orifice.for:872 */
/*<       w2a=w2 >*/
    w2a = w2;
/* SOURCE orifice.for:873 */
/*<       if(w1a.lt.8)w1a=8 >*/
    if (w1a < 8) {
	w1a = 8;
    }
/* SOURCE orifice.for:874 */
/*<       if(w2a.lt.8)w2a=8 >*/
    if (w2a < 8) {
	w2a = 8;
    }
/* SOURCE orifice.for:875 */
/*<       tempa=' ' >*/
    s_copy(tempa, const_cast<char*>(" "), (ftnlen)25, (ftnlen)1);
/* SOURCE orifice.for:876 */
/*<       tempb=' ' >*/
    s_copy(tempb, const_cast<char*>(" "), (ftnlen)25, (ftnlen)1);
/* SOURCE orifice.for:877 */
/*<       write(stdout,55)tempa(1:w1a-8+1),tempb(1:w2a-8+1) >*/
    feq_gen_io_d__87.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__87);
    do_fio(&feq_gen_c_d_1, tempa, w1a - 7);
    do_fio(&feq_gen_c_d_1, tempb, w2a - 7);
    e_wsfe();
/* SOURCE orifice.for:878 */
/*<       if(w1.lt.8)w1=8 >*/
    if (w1 < 8) {
	w1 = 8;
    }
/* SOURCE orifice.for:879 */
/*<       if(w2.lt.8)w2=8 >*/
    if (w2 < 8) {
	w2 = 8;
    }
/* SOURCE orifice.for:880 */
/*<       tempa(1+w1-idlena:)=apptabid >*/
    feq_gen_i_d_1 = w1 + 1 - idlena - 1;
    s_copy(tempa + feq_gen_i_d_1, apptabid, 25 - feq_gen_i_d_1, (ftnlen)16);
/* SOURCE orifice.for:881 */
/*<       tempb(1+w2-idlenb:)=oritabid >*/
    feq_gen_i_d_1 = w2 + 1 - idlenb - 1;
    s_copy(tempb + feq_gen_i_d_1, oritabid, 25 - feq_gen_i_d_1, (ftnlen)16);
/* SOURCE orifice.for:882 */
/*<        >*/
    feq_gen_io_d__88.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__88);
    do_fio(&feq_gen_c_d_1, tempa, w1);
    do_fio(&feq_gen_c_d_1, tempb, w2);
    do_fio(&feq_gen_c_d_1, (char *)&maxzup, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&minhup, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&limpfd, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE orifice.for:885 */
/*<       if(apptab.gt.0)then >*/
    if (apptab > 0) {
/*       Check on the existence of the table and its type. */
/* SOURCE orifice.for:887 */
/*<       it=apptab >*/
	it = apptab;
/* SOURCE orifice.for:888 */
/*<       callchktab(20,stdout,ftpnt,pmxtab,apptab,eflag) >*/
	chktab_(&feq_gen_c_d_20, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &apptab, eflag);
/* SOURCE orifice.for:891 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/* SOURCE orifice.for:892 */
/*<       callfndelv(it,stdout,eflag,appzb) >*/
	    fndelv_(&it, stdout, eflag, &appzb);
/* SOURCE orifice.for:894 */
/*<       endif >*/
	}
/* SOURCE orifice.for:895 */
/*<       endif >*/
    }
/* SOURCE orifice.for:896 */
/*<       if(shape.eq.'ODD')then >*/
    if (s_cmp(shape, const_cast<char*>("ODD"), (ftnlen)6, (ftnlen)3) == 0) {
/* SOURCE orifice.for:897 */
/*<       if(oritab.gt.0)then >*/
	if (oritab > 0) {
/*         Check on existence of the table for the orifice shape. */
/* SOURCE orifice.for:899 */
/*<       callchktab(2,stdout,ftpnt,pmxtab,oritab,eflag) >*/
	    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &oritab, eflag)
		    ;
/* SOURCE orifice.for:902 */
/*<       orifice_shape_tab=oritab >*/
	    feq_gen_orf_shape_d_1.feq_gen_orifice_shape_tab_d_ = oritab;
/* SOURCE orifice.for:903 */
/*<       else >*/
	} else {
/* SOURCE orifice.for:904 */
/*<       write(stdout,62) >*/
	    feq_gen_io_d__91.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__91);
	    e_wsfe();
/* SOURCE orifice.for:905 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE orifice.for:906 */
/*<       endif >*/
	}
/* SOURCE orifice.for:907 */
/*<       endif >*/
    }
/* SOURCE orifice.for:909 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     INPUT OF DATA COMPLETE.  BEGIN THE COMPUTATIONS. */
/*     Define the width to vertical diameter ratio */
/* SOURCE orifice.for:914 */
/*<       if(d.gt.0.0)then >*/
    if (feq_gen_d_d_ > (float)0.) {
/* SOURCE orifice.for:915 */
/*<       w_over_d=dble(w)/dble(d) >*/
	feq_gen_orf_shape_d_1.feq_gen_w_over_d_d_ = (doublereal) w / (doublereal) feq_gen_d_d_;
/* SOURCE orifice.for:916 */
/*<       endif >*/
    }
/*     Compute the upstream head sequence.  First, find the head */
/*     range requested. */
/* SOURCE orifice.for:920 */
/*<       head_datum=invert >*/
    feq_gen_head_datum_d_ = invert;
/* SOURCE orifice.for:921 */
/*<       write(stdout,60)head_datum >*/
    feq_gen_io_d__93.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__93);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_head_datum_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE orifice.for:922 */
/*<       maxhup=maxzup-head_datum >*/
    maxhup = static_cast<double>(maxzup) - feq_gen_head_datum_d_;
/* SOURCE orifice.for:923 */
/*<       if(maxhup.le.0.0)then >*/
    if (maxhup <= (float)0.) {
/* SOURCE orifice.for:924 */
/*<       write(stdout,78)maxhup,maxzup,head_datum >*/
	feq_gen_io_d__95.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__95);
	do_fio(&feq_gen_c_d_1, (char *)&maxhup, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&maxzup, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_head_datum_d_, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE orifice.for:925 */
/*<       maxhup=2.0 >*/
	maxhup = (float)2.;
/* SOURCE orifice.for:926 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE orifice.for:927 */
/*<       endif >*/
    }
/* SOURCE orifice.for:928 */
/*<       if(minhup.le.0.0)then >*/
    if (minhup <= (float)0.) {
/* SOURCE orifice.for:929 */
/*<       write(stdout,80)minhup >*/
	feq_gen_io_d__96.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__96);
	do_fio(&feq_gen_c_d_1, (char *)&minhup, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE orifice.for:930 */
/*<       minhup=0.125*d >*/
	minhup = static_cast<double>(feq_gen_d_d_) * (float).125;
/* SOURCE orifice.for:931 */
/*<       endif >*/
    }
/* SOURCE orifice.for:932 */
/*<       if(minhup.gt.d)then >*/
    if (minhup > feq_gen_d_d_) {
/* SOURCE orifice.for:933 */
/*<       minhup=0.125*d >*/
	minhup = static_cast<double>(feq_gen_d_d_) * (float).125;
/* SOURCE orifice.for:934 */
/*<       endif >*/
    }
/*     Compute the spacing for weir flow. */
/* SOURCE orifice.for:936 */
/*<       htemp=d >*/
    htemp = feq_gen_d_d_;
/* SOURCE orifice.for:937 */
/*<       pow=1.5 >*/
    pow = (float)1.5;
/* SOURCE orifice.for:938 */
/*<       offset=0.0 >*/
    offset = (float)0.;
/* SOURCE orifice.for:939 */
/*<        >*/
    lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &minhup, &htemp, &liprec, &
	    feq_gen_c_d_151, &nhup, xbrk, eflag);
/* SOURCE orifice.for:943 */
/*<       do190i=1,nhup >*/
    feq_gen_i_d_1 = nhup;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE orifice.for:944 */
/*<       hupvec(i)=xbrk(i) >*/
	hupvec[feq_gen_i_d_ - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE orifice.for:945 */
/*<   190 continue >*/
/* L190: */
    }
/*     Compute the orifice flow region. */
/* SOURCE orifice.for:948 */
/*<       pow=0.5 >*/
    pow = (float).5;
/* SOURCE orifice.for:949 */
/*<        >*/
    feq_gen_r_d_1 = static_cast<double>(htemp) + minhup;
    lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &feq_gen_r_d_1, &maxhup, &liprec, &
	    feq_gen_c_d_151, &nn, xbrk, eflag);
/* SOURCE orifice.for:953 */
/*<       do191i=1,nn >*/
    feq_gen_i_d_1 = nn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE orifice.for:954 */
/*<       nhup=nhup+1 >*/
	++nhup;
/* SOURCE orifice.for:955 */
/*<       hupvec(nhup)=xbrk(i) >*/
	hupvec[nhup - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE orifice.for:956 */
/*<   191 continue >*/
/* L191: */
    }
/*     Compute the proportions of free drop. */
/* SOURCE orifice.for:959 */
/*<       pow=0.5 >*/
    pow = (float).5;
/* SOURCE orifice.for:960 */
/*<       offset=0.0 >*/
    offset = (float)0.;
/* SOURCE orifice.for:961 */
/*<        >*/
    lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &minpfd, &limpfd, &liprec, 
	    &feq_gen_c_d_351, &nn, xbrk, eflag);
/* SOURCE orifice.for:965 */
/*<       work(1)=0.0 >*/
    work[0] = (float)0.;
/* SOURCE orifice.for:966 */
/*<       do195i=1,nn >*/
    feq_gen_i_d_1 = nn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE orifice.for:967 */
/*<       work(i+1)=xbrk(i) >*/
	work[feq_gen_i_d_] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE orifice.for:968 */
/*<   195 continue >*/
/* L195: */
    }
/* SOURCE orifice.for:969 */
/*<       nfrac=nn+1 >*/
    nfrac = nn + 1;
/* SOURCE orifice.for:971 */
/*<       work(nfrac+1)=1.0 >*/
    work[nfrac] = (float)1.;
/* SOURCE orifice.for:972 */
/*<       nfrac=nfrac+1 >*/
    ++nfrac;
/*     Transfer to PFDVEC and insert the intermediate points for computing */
/*     an estimated interpolation error. */
/* SOURCE orifice.for:976 */
/*<       pfdvec(1)=work(1) >*/
    pfdvec[0] = work[0];
/* SOURCE orifice.for:977 */
/*<       pfdvec(2)=work(2) >*/
    pfdvec[1] = work[1];
/* SOURCE orifice.for:978 */
/*<       j=2 >*/
    j = 2;
/* SOURCE orifice.for:979 */
/*<       do201i=3,nfrac-1 >*/
    feq_gen_i_d_1 = nfrac - 1;
    for (feq_gen_i_d_ = 3; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE orifice.for:980 */
/*<       j=j+1 >*/
	++j;
/* SOURCE orifice.for:981 */
/*<       pfdvec(j)=0.5*(work(i)+work(i-1)) >*/
	pfdvec[j - 1] = static_cast<double>((static_cast<double>(work[feq_gen_i_d_ - 1]) + work[feq_gen_i_d_ - 2])) * (float).5;
/* SOURCE orifice.for:982 */
/*<       j=j+1 >*/
	++j;
/* SOURCE orifice.for:983 */
/*<       pfdvec(j)=work(i) >*/
	pfdvec[j - 1] = work[feq_gen_i_d_ - 1];
/* SOURCE orifice.for:984 */
/*<   201 continue >*/
/* L201: */
    }
/* SOURCE orifice.for:985 */
/*<       pfdvec(j+1)=work(nfrac) >*/
    pfdvec[j] = work[nfrac - 1];
/* SOURCE orifice.for:986 */
/*<       nfrac=j+1 >*/
    nfrac = j + 1;
/*      DO 202 I=1,NFRAC */
/*        WRITE(STDOUT,*) ' I=',I,' PFDVEC(I)=',PFDVEC(I) */
/* 202   CONTINUE */
/* SOURCE orifice.for:991 */
/*<       rms_global=0.0 >*/
    feq_gen_rms_global_d_ = (float)0.;
/* SOURCE orifice.for:992 */
/*<       n_global=0.0 >*/
    feq_gen_n_global_d_ = (float)0.;
/* SOURCE orifice.for:993 */
/*<       bigerr=0.0 >*/
    bigerr = (float)0.;
/* SOURCE orifice.for:995 */
/*<       do1000ihup=1,nhup >*/
    feq_gen_i_d_1 = nhup;
    for (ihup = 1; ihup <= feq_gen_i_d_1; ++ihup) {
/* SOURCE orifice.for:996 */
/*<       hw=hupvec(ihup) >*/
	hw = hupvec[ihup - 1];
/* SOURCE orifice.for:997 */
/*<       hw_rel=hw/d >*/
	feq_gen_hw_rel_d_ = static_cast<double>(hw) / feq_gen_d_d_;
/* SOURCE orifice.for:998 */
/*<       hwe=hw+head_datum >*/
	hwe = static_cast<double>(hw) + feq_gen_head_datum_d_;
/* SOURCE orifice.for:1000 */
/*<       if(apptab.gt.0)then >*/
	if (apptab > 0) {
/*         Define the approach area. */
/* SOURCE orifice.for:1002 */
/*<       ya=hwe-appzb >*/
	    ya = static_cast<double>(hwe) - appzb;
/* SOURCE orifice.for:1003 */
/*<       calllkta(apptab,ya,appa) >*/
	    lkta_(&apptab, &ya, &appa);
/* SOURCE orifice.for:1006 */
/*<       else >*/
	} else {
/* SOURCE orifice.for:1007 */
/*<       appa=-1.0 >*/
	    appa = (float)-1.;
/* SOURCE orifice.for:1008 */
/*<       endif >*/
	}
/*       Find the free flow values. */
/* SOURCE orifice.for:1011 */
/*<        >*/
	feq_gen_find_free_orifice_flow_d_(stdout, &feq_gen_hw_rel_d_, &feq_gen_twf_rel_d_, shape, &qfree,
		 nature, (ftnlen)6, (ftnlen)2);
/* SOURCE orifice.for:1013 */
/*<       twf=d*twf_rel >*/
	twf = static_cast<double>(feq_gen_d_d_) * feq_gen_twf_rel_d_;
/* SOURCE orifice.for:1014 */
/*<       twef=twf+head_datum >*/
	twef = static_cast<double>(twf) + feq_gen_head_datum_d_;
/* SOURCE orifice.for:1015 */
/*<       fdrop=hw-twf >*/
	fdrop = static_cast<double>(hw) - twf;
/*       Interpolate for the coefficient to use. */
/* SOURCE orifice.for:1017 */
/*<       orifice_limit=1.5*d >*/
	feq_gen_orifice_limit_d_ = static_cast<double>(feq_gen_d_d_) * (float)1.5;
/* SOURCE orifice.for:1018 */
/*<       if(hw.le.d)then >*/
	if (hw <= feq_gen_d_d_) {
/* SOURCE orifice.for:1019 */
/*<       ce=cw >*/
	    ce = cw;
/* SOURCE orifice.for:1020 */
/*<       elseif(hw.ge.orifice_limit)then >*/
	} else if (hw >= feq_gen_orifice_limit_d_) {
/* SOURCE orifice.for:1021 */
/*<       ce=cd >*/
	    ce = cd;
/* SOURCE orifice.for:1022 */
/*<       else >*/
	} else {
/* SOURCE orifice.for:1023 */
/*<       ce=cw+(hw-d)*(cd-cw)/(orifice_limit-d) >*/
	    ce = static_cast<double>(cw) + static_cast<double>(static_cast<double>((static_cast<double>(hw) - feq_gen_d_d_)) * (static_cast<double>(cd) - cw)) / (static_cast<double>(feq_gen_orifice_limit_d_) - feq_gen_d_d_);
/* SOURCE orifice.for:1024 */
/*<       endif >*/
	}
/* SOURCE orifice.for:1026 */
/*<       qfree=qfree*fnumber*ce*sqrt(d)*d**2*sqrt_of_2g >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = feq_gen_d_d_;
	qfree = static_cast<double>(static_cast<double>(qfree) * fnumber) * ce * sqrt(feq_gen_d_d_) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * 
		feq_gen_sqrt_of_2g_d_;
/* SOURCE orifice.for:1028 */
/*<       if(appa.gt.0.0)then >*/
	if (appa > (float)0.) {
/*         Make an approx. adjustment for approach velocity head */
/*         as induced by the flow through the orifice itself. */
/* SOURCE orifice.for:1031 */
/*<       hw_relt=(hw+(qfree/appa)**2/(2.*grav))/d >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(qfree) / appa;
	    feq_gen_hw_relt_d_ = static_cast<double>((static_cast<double>(hw) + static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / (static_cast<double>(*grav) * (float)2.))) / feq_gen_d_d_;
/* SOURCE orifice.for:1032 */
/*<        >*/
	    feq_gen_find_free_orifice_flow_d_(stdout, &feq_gen_hw_relt_d_, &feq_gen_twf_relt_d_, shape, &
		    qfree, nature, (ftnlen)6, (ftnlen)2);
/* SOURCE orifice.for:1034 */
/*<       qfree=qfree*fnumber*ce*sqrt(d)*d**2*sqrt_of_2g >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = feq_gen_d_d_;
	    qfree = static_cast<double>(static_cast<double>(qfree) * fnumber) * ce * sqrt(feq_gen_d_d_) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * 
		    feq_gen_sqrt_of_2g_d_;
/* SOURCE orifice.for:1035 */
/*<       endif >*/
	}
/* SOURCE orifice.for:1036 */
/*<       qmat(ihup,nfrac)=qfree >*/
	qmat[ihup + nfrac * 151 - 152] = qfree;
/*       Set the flow at zero partial free drop to 0.0 */
/* SOURCE orifice.for:1038 */
/*<       qmat(ihup,1)=0.0 >*/
	qmat[ihup - 1] = (float)0.;
/* SOURCE orifice.for:1039 */
/*<       fdvec(ihup)=fdrop >*/
	fdvec[ihup - 1] = fdrop;
/* SOURCE orifice.for:1041 */
/*<       callvar_decimal(qfree,cq) >*/
	feq_gen_var_decimal_d_(&qfree, cq, (ftnlen)8);
/* SOURCE orifice.for:1043 */
/*<       write(stdout,72)hw,hwe,cq >*/
	feq_gen_io_d__131.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__131);
	do_fio(&feq_gen_c_d_1, (char *)&hw, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hwe, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	e_wsfe();
/* SOURCE orifice.for:1044 */
/*<       write(stdout,74) >*/
	feq_gen_io_d__132.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__132);
	e_wsfe();
/* SOURCE orifice.for:1045 */
/*<       callvar_decimal(qfree,cq) >*/
	feq_gen_var_decimal_d_(&qfree, cq, (ftnlen)8);
/* SOURCE orifice.for:1047 */
/*<       write(stdout,75)pfdvec(nfrac),fdrop,twef,twf,nature,cq >*/
	feq_gen_io_d__133.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__133);
	do_fio(&feq_gen_c_d_1, (char *)&pfdvec[nfrac - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&twef, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&twf, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, nature, (ftnlen)2);
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	e_wsfe();
/* SOURCE orifice.for:1050 */
/*<       do400j=nfrac-1,2,-1 >*/
	for (j = nfrac - 1; j >= 2; --j) {
/* SOURCE orifice.for:1051 */
/*<       pfd=pfdvec(j) >*/
	    pfd = pfdvec[j - 1];
/* SOURCE orifice.for:1052 */
/*<       drop=fdrop*pfd >*/
	    drop = static_cast<double>(fdrop) * pfd;
/* SOURCE orifice.for:1053 */
/*<       tw=hw-drop >*/
	    tw = static_cast<double>(hw) - drop;
/* SOURCE orifice.for:1054 */
/*<       twe=tw+head_datum >*/
	    twe = static_cast<double>(tw) + feq_gen_head_datum_d_;
/* SOURCE orifice.for:1055 */
/*<       tw_rel=tw/d >*/
	    feq_gen_tw_rel_d_ = static_cast<double>(tw) / feq_gen_d_d_;
/*         Find the submerged flow values. */
/* SOURCE orifice.for:1057 */
/*<       callfind_sub_orifice_flow(stdout,hw_rel,tw_rel,shape,qsub,nature) >*/
	    feq_gen_find_sub_orifice_flow_d_(stdout, &feq_gen_hw_rel_d_, &feq_gen_tw_rel_d_, shape, &
		    qsub, nature, (ftnlen)6, (ftnlen)2);
/* SOURCE orifice.for:1059 */
/*<       qsub=qsub*fnumber*ce*sqrt(d)*d**2*sqrt_of_2g >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = feq_gen_d_d_;
	    qsub = static_cast<double>(static_cast<double>(qsub) * fnumber) * ce * sqrt(feq_gen_d_d_) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * 
		    feq_gen_sqrt_of_2g_d_;
/* SOURCE orifice.for:1060 */
/*<       if(appa.gt.0.0)then >*/
	    if (appa > (float)0.) {
/*           Make an approximate adjustment for approach velocity */
/*           head. */
/* SOURCE orifice.for:1063 */
/*<       hw_rel=(hw+(qsub/appa)**2/(2.*grav))/d >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qsub) / appa;
		feq_gen_hw_rel_d_ = static_cast<double>((static_cast<double>(hw) + static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / (static_cast<double>(*grav) * (float)2.))) / feq_gen_d_d_;
/* SOURCE orifice.for:1064 */
/*<       callfind_sub_orifice_flow(stdout,hw_rel,tw_rel,shape,qsub,nature) >*/
		feq_gen_find_sub_orifice_flow_d_(stdout, &feq_gen_hw_rel_d_, &feq_gen_tw_rel_d_, shape, &
			qsub, nature, (ftnlen)6, (ftnlen)2);
/* SOURCE orifice.for:1066 */
/*<       qsub=qsub*fnumber*ce*sqrt(d)*d**2*sqrt_of_2g >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = feq_gen_d_d_;
		qsub = static_cast<double>(static_cast<double>(qsub) * fnumber) * ce * sqrt(feq_gen_d_d_) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * 
			feq_gen_sqrt_of_2g_d_;
/* SOURCE orifice.for:1067 */
/*<       endif >*/
	    }
/* SOURCE orifice.for:1069 */
/*<       qmat(ihup,j)=qsub >*/
	    qmat[ihup + j * 151 - 152] = qsub;
/* SOURCE orifice.for:1070 */
/*<       pow=log(qsub/qmat(ihup,j+1))/log(pfdvec(j)/pfdvec(j+1)) >*/
	    pow = log(static_cast<double>(qsub) / qmat[ihup + (j + 1) * 151 - 152]) / log(static_cast<double>(pfdvec[j 
		    - 1]) / pfdvec[j]);
/* SOURCE orifice.for:1071 */
/*<       callvar_decimal(qsub,cq) >*/
	    feq_gen_var_decimal_d_(&qsub, cq, (ftnlen)8);
/* SOURCE orifice.for:1073 */
/*<       write(stdout,75)pfdvec(j),drop,twe,tw,nature,cq,pow >*/
	    feq_gen_io_d__140.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__140);
	    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&twe, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tw, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, nature, (ftnlen)2);
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&pow, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE orifice.for:1075 */
/*<   400 continue >*/
/* L400: */
	}
/*       Compute approximate maximum error and report */
/* SOURCE orifice.for:1078 */
/*<       do600j=3,nfrac-2,2 >*/
	feq_gen_i_d_2 = nfrac - 2;
	for (j = 3; j <= feq_gen_i_d_2; j += 2) {
/* SOURCE orifice.for:1079 */
/*<       qhat=0.5*(qmat(ihup,j-1)+qmat(ihup,j+1)) >*/
	    qhat = static_cast<double>((static_cast<double>(qmat[ihup + (j - 1) * 151 - 152]) + qmat[ihup + (j + 1) * 
		    151 - 152])) * (float).5;
/* SOURCE orifice.for:1080 */
/*<       rerr=abs(qhat-qmat(ihup,j))/qmat(ihup,j) >*/
	    rerr = (feq_gen_r_d_1 = static_cast<double>(qhat) - qmat[ihup + j * 151 - 152], dabs(feq_gen_r_d_1)) / 
		    qmat[ihup + j * 151 - 152];
/* SOURCE orifice.for:1081 */
/*<       rms_global=rms_global+rerr*rerr >*/
	    feq_gen_rms_global_d_ += static_cast<double>(rerr) * rerr;
/* SOURCE orifice.for:1082 */
/*<       n_global=n_global+1 >*/
	    ++feq_gen_n_global_d_;
/* SOURCE orifice.for:1083 */
/*<       if(rerr.gt.bigerr)then >*/
	    if (rerr > bigerr) {
/* SOURCE orifice.for:1084 */
/*<       bigerr=rerr >*/
		bigerr = rerr;
/* SOURCE orifice.for:1085 */
/*<       herr=hw >*/
		herr = hw;
/* SOURCE orifice.for:1086 */
/*<       ipfd=j >*/
		ipfd = j;
/* SOURCE orifice.for:1087 */
/*<       endif >*/
	    }
/* SOURCE orifice.for:1088 */
/*<   600 continue >*/
/* L600: */
	}
/*       Eliminate the checking values from QMAT */
/* SOURCE orifice.for:1091 */
/*<       jbase=3 >*/
	jbase = 3;
/* SOURCE orifice.for:1092 */
/*<       do700j=4,nfrac-1,2 >*/
	feq_gen_i_d_2 = nfrac - 1;
	for (j = 4; j <= feq_gen_i_d_2; j += 2) {
/* SOURCE orifice.for:1093 */
/*<       qmat(ihup,jbase)=qmat(ihup,j) >*/
	    qmat[ihup + jbase * 151 - 152] = qmat[ihup + j * 151 - 152];
/* SOURCE orifice.for:1094 */
/*<       jbase=jbase+1 >*/
	    ++jbase;
/* SOURCE orifice.for:1095 */
/*<   700 continue >*/
/* L700: */
	}
/* SOURCE orifice.for:1096 */
/*<       qmat(ihup,jbase)=qmat(ihup,nfrac) >*/
	qmat[ihup + jbase * 151 - 152] = qmat[ihup + nfrac * 151 - 152];
/* SOURCE orifice.for:1098 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE orifice.for:1100 */
/*<   900 continue >*/
/* L900: */
/* SOURCE orifice.for:1101 */
/*<       pfdtmp(1)=pfdvec(1) >*/
    pfdtmp[0] = pfdvec[0];
/* SOURCE orifice.for:1102 */
/*<       pfdtmp(2)=pfdvec(2) >*/
    pfdtmp[1] = pfdvec[1];
/*       Eliminate checking values of PFD */
/* SOURCE orifice.for:1104 */
/*<       jbase=3 >*/
    jbase = 3;
/* SOURCE orifice.for:1105 */
/*<       do910j=4,nfrac-1,2 >*/
    feq_gen_i_d_1 = nfrac - 1;
    for (j = 4; j <= feq_gen_i_d_1; j += 2) {
/* SOURCE orifice.for:1106 */
/*<       pfdtmp(jbase)=pfdvec(j) >*/
	pfdtmp[jbase - 1] = pfdvec[j - 1];
/* SOURCE orifice.for:1107 */
/*<       jbase=jbase+1 >*/
	++jbase;
/* SOURCE orifice.for:1108 */
/*<   910 continue >*/
/* L910: */
    }
/* SOURCE orifice.for:1109 */
/*<       pfdtmp(jbase)=pfdvec(nfrac) >*/
    pfdtmp[jbase - 1] = pfdvec[nfrac - 1];
/* SOURCE orifice.for:1111 */
/*<       zrhufd=0.0 >*/
    zrhufd = (float)0.;
/* SOURCE orifice.for:1112 */
/*<        >*/
    twdout_(stdout, stdtab, &tab, label, &nhup, &jbase, hupvec, fdvec, pfdtmp,
	     qmat, &feq_gen_head_datum_d_, &feq_gen_c_d_13, const_cast<char*>(" ORIFICE"), &zrhufd, zone, hgrid, 
	    vdatum, unitsys, basis, &easting, &northing, eflag, (ftnlen)50, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE orifice.for:1119 */
/*<       write(stdout,86)bigerr,herr,pfdvec(ipfd) >*/
    feq_gen_io_d__148.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__148);
    do_fio(&feq_gen_c_d_1, (char *)&bigerr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&herr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[ipfd - 1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE orifice.for:1122 */
/*<       rms_global=sqrt(rms_global/float(n_global)) >*/
    feq_gen_rms_global_d_ = sqrt(static_cast<double>(feq_gen_rms_global_d_) / (real) feq_gen_n_global_d_);
/* SOURCE orifice.for:1123 */
/*<       write(stdout,88)rms_global,n_global >*/
    feq_gen_io_d__149.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__149);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_rms_global_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_n_global_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE orifice.for:1125 */
/*<       if(twod_cubic_out.eq.'YES')then >*/
    if (s_cmp(upgrdc_1.feq_gen_twod_cubic_out_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE orifice.for:1126 */
/*<       verbose=1 >*/
	verbose = 1;
/* SOURCE orifice.for:1127 */
/*<        >*/
	twodfit_(stdout, &tab, &nhup, &jbase, hupvec, fdvec, pfdtmp, qmat, &
		feq_gen_head_datum_d_, &feq_gen_c_d_13, const_cast<char*>(" ORIFICE"), &zrhufd, &verbose, ftp, 
		eflag, &ftpup, (ftnlen)8);
/* SOURCE orifice.for:1134 */
/*<       endif >*/
    }
/* SOURCE orifice.for:1136 */
/*<       return >*/
    return 0;
/* SOURCE orifice.for:1137 */
/*<   991 continue >*/
L991:
/* SOURCE orifice.for:1138 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__152.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__152);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE orifice.for:1139 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__153.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__153);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE orifice.for:1140 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE orifice.for:1141 */
/*<       end >*/
    return 0;
} /* orifice_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
