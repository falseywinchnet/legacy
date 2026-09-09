/* pumpitem.f -- translated by f2c (version 20240504).
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

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_4 = 4;
static real c_b132 = (float)0.;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_20 = 20;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_25 = 25;




/* SOURCE pumpitem.for:4 */
/*<        >*/
/* Subroutine */ int feq_gen_read_axialpump_items_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	eflag, integer *idlena, integer *idlenb, integer *idlenc, integer *
	feq_gen_net_pump_tab_d_, integer *feq_gen_number_of_pumps_d_, real *feq_gen_inlet_length_d_, 
	integer *feq_gen_inlet_tab_d_, real *feq_gen_outlet_length_d_, integer *feq_gen_outlet_tab_d_, 
	real *feq_gen_inlet_loss_factor_d_, real *feq_gen_h_des_d_, real *feq_gen_q_des_d_, char *label, 
	ftnlen line_len, ftnlen label_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:755* Only \002,i3,\002 items given \
in \002,\002axial-pump description line.  Need  ten items.\002)";
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
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer n;
    extern integer feq_gen_nonblank_nonzero_d_(char *, ftnlen);
    integer ie, is;
    char tpc[20], key[16];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_52, 0 };


/*     Get the items of data for computing an axial pump table */
/* SOURCE pumpitem.for:16 */
/*<       implicitnone >*/
/* SOURCE pumpitem.for:17 */
/*<        >*/
/* SOURCE pumpitem.for:20 */
/*<       realinlet_length,outlet_length,inlet_loss_factor,h_des,q_des >*/
/* SOURCE pumpitem.for:22 */
/*<       characterline*(*),label*50 >*/
/*     Local */
/* SOURCE pumpitem.for:26 */
/*<       integerie,is,itab,lkey,n >*/
/* SOURCE pumpitem.for:27 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE pumpitem.for:30 */
/*<       integernonblank_nonzero,lenstr >*/
/* SOURCE pumpitem.for:31 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE pumpitem.for:34 */
/*<    50  >*/
/* SOURCE pumpitem.for:36 */
/*<    52 format(/,' *ERR:753* Conversion error in field ',i1,' in:',/,a) >*/
/* *********************************************************************** */
/* SOURCE pumpitem.for:39 */
/*<       if(nitem.lt.10)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
/* L52: */
    if (*nitem < 10) {
/* SOURCE pumpitem.for:40 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__1.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__1);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE pumpitem.for:41 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE pumpitem.for:42 */
/*<       endif >*/
    }
/*     Process the net pump table */
/* SOURCE pumpitem.for:45 */
/*<       n=1 >*/
    n = 1;
/* SOURCE pumpitem.for:46 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:47 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:48 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:49 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:51 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE pumpitem.for:52 */
/*<       idlena=lenstr(key) >*/
    *idlena = lenstr_(key, (ftnlen)16);
/* SOURCE pumpitem.for:53 */
/*<       if(key(1:1).eq.'-')then >*/
    if (*(unsigned char *)key == '-') {
/* SOURCE pumpitem.for:54 */
/*<       net_pump_tab=-1 >*/
	*feq_gen_net_pump_tab_d_ = -1;
/* SOURCE pumpitem.for:55 */
/*<       else >*/
    } else {
/*       Convert from the table id to an internal number. */
/* SOURCE pumpitem.for:57 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*         We have an id given. */
/* SOURCE pumpitem.for:59 */
/*<       callget_internal_tab_number(stdout,key,eflag,net_pump_tab) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, feq_gen_net_pump_tab_d_, (
		    ftnlen)16);
/* SOURCE pumpitem.for:63 */
/*<       else >*/
	} else {
/* SOURCE pumpitem.for:64 */
/*<       net_pump_tab=0 >*/
	    *feq_gen_net_pump_tab_d_ = 0;
/* SOURCE pumpitem.for:65 */
/*<       endif >*/
	}
/* SOURCE pumpitem.for:66 */
/*<       endif >*/
    }
/*     Process the number of pumps */
/* SOURCE pumpitem.for:69 */
/*<       n=2 >*/
    n = 2;
/* SOURCE pumpitem.for:70 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:71 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:72 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:73 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:75 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:76 */
/*<       number_of_pumps=0 >*/
	*feq_gen_number_of_pumps_d_ = 0;
/* SOURCE pumpitem.for:77 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:78 */
/*<       read(tpc,*,err=999)number_of_pumps >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*feq_gen_number_of_pumps_d_), (ftnlen)
		sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:79 */
/*<       endif >*/
    }
/*     Process the inlet conduit length */
/* SOURCE pumpitem.for:82 */
/*<       n=3 >*/
    n = 3;
/* SOURCE pumpitem.for:83 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:84 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:85 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:86 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:88 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:89 */
/*<       inlet_length=0 >*/
	*feq_gen_inlet_length_d_ = (float)0.;
/* SOURCE pumpitem.for:90 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:91 */
/*<       read(tpc,*,err=999)inlet_length >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_inlet_length_d_), (ftnlen)
		sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:92 */
/*<       endif >*/
    }
/*     Process the inlet conduit table */
/* SOURCE pumpitem.for:95 */
/*<       n=4 >*/
    n = 4;
/* SOURCE pumpitem.for:96 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:97 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:98 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:99 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:101 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE pumpitem.for:102 */
/*<       idlenb=lenstr(key) >*/
    *idlenb = lenstr_(key, (ftnlen)16);
/*     Convert from the table id to an internal number. */
/* SOURCE pumpitem.for:104 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*       We have an id given. */
/* SOURCE pumpitem.for:106 */
/*<       callget_internal_tab_number(stdout,key,eflag,inlet_tab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, feq_gen_inlet_tab_d_, (ftnlen)16)
		;
/* SOURCE pumpitem.for:110 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:111 */
/*<       inlet_tab=0 >*/
	*feq_gen_inlet_tab_d_ = 0;
/* SOURCE pumpitem.for:112 */
/*<       endif >*/
    }
/*     Process the outlet conduit length */
/* SOURCE pumpitem.for:115 */
/*<       n=5 >*/
    n = 5;
/* SOURCE pumpitem.for:116 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:117 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:118 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:119 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:121 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:122 */
/*<       outlet_length=0 >*/
	*feq_gen_outlet_length_d_ = (float)0.;
/* SOURCE pumpitem.for:123 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:124 */
/*<       read(tpc,*,err=999)outlet_length >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_outlet_length_d_), (ftnlen)
		sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:125 */
/*<       endif >*/
    }
/*     Process the outlet conduit table */
/* SOURCE pumpitem.for:128 */
/*<       n=6 >*/
    n = 6;
/* SOURCE pumpitem.for:129 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:130 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:131 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:132 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:134 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE pumpitem.for:135 */
/*<       idlenc=lenstr(key) >*/
    *idlenc = lenstr_(key, (ftnlen)16);
/*     Convert from the table id to an internal number. */
/* SOURCE pumpitem.for:137 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*       We have an id given. */
/* SOURCE pumpitem.for:139 */
/*<       callget_internal_tab_number(stdout,key,eflag,outlet_tab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, feq_gen_outlet_tab_d_, (ftnlen)
		16);
/* SOURCE pumpitem.for:143 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:144 */
/*<       outlet_tab=0 >*/
	*feq_gen_outlet_tab_d_ = 0;
/* SOURCE pumpitem.for:145 */
/*<       endif >*/
    }
/*     Process the inlet-loss factor */
/* SOURCE pumpitem.for:148 */
/*<       n=7 >*/
    n = 7;
/* SOURCE pumpitem.for:149 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:150 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:151 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:152 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:154 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:155 */
/*<       inlet_loss_factor=0.0 >*/
	*feq_gen_inlet_loss_factor_d_ = (float)0.;
/* SOURCE pumpitem.for:156 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:157 */
/*<       read(tpc,*,err=999)inlet_loss_factor >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_inlet_loss_factor_d_), (ftnlen)
		sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:158 */
/*<       endif >*/
    }
/*     Process the design head */
/* SOURCE pumpitem.for:161 */
/*<       n=8 >*/
    n = 8;
/* SOURCE pumpitem.for:162 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:163 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:164 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:165 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:167 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:168 */
/*<       h_des=0.0 >*/
	*feq_gen_h_des_d_ = (float)0.;
/* SOURCE pumpitem.for:169 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:170 */
/*<       read(tpc,*,err=999)h_des >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_h_des_d_), (ftnlen)sizeof(real))
		;
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:171 */
/*<       endif >*/
    }
/*     Process the design flow */
/* SOURCE pumpitem.for:174 */
/*<       n=9 >*/
    n = 9;
/* SOURCE pumpitem.for:175 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:176 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:177 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:178 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:180 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:181 */
/*<       q_des=0.0 >*/
	*feq_gen_q_des_d_ = (float)0.;
/* SOURCE pumpitem.for:182 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:183 */
/*<       read(tpc,*,err=999)q_des >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_q_des_d_), (ftnlen)sizeof(real))
		;
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:184 */
/*<       endif >*/
    }
/*     Process the table label */
/* SOURCE pumpitem.for:187 */
/*<       n=10 >*/
    n = 10;
/* SOURCE pumpitem.for:188 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:189 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:190 */
/*<       label=line(is:ie) >*/
    s_copy(label, line + (is - 1), (ftnlen)50, ie - (is - 1));
/* SOURCE pumpitem.for:191 */
/*<       callstrip_l_blanks(label) >*/
    feq_gen_strip_l_blanks_d_(label, (ftnlen)50);
/* SOURCE pumpitem.for:193 */
/*<       return >*/
    return 0;
/* SOURCE pumpitem.for:194 */
/*<   999 continue >*/
L999:
/* SOURCE pumpitem.for:195 */
/*<       write(stdout,52)n,line >*/
    feq_gen_io_d__7.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__7);
    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, line, line_len);
    e_wsfe();
/* SOURCE pumpitem.for:196 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE pumpitem.for:197 */
/*<       end >*/
    return 0;
} /* read_axialpump_items__ */




/* SOURCE pumpitem.for:201 */
/*<        >*/
/* Subroutine */ int feq_gen_write_axialpump_items_d_(integer *stdout, integer *nitem, 
	integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *idlena, integer *
	idlenb, integer *idlenc, integer *feq_gen_net_pump_tab_d_, integer *
	feq_gen_number_of_pumps_d_, real *feq_gen_inlet_length_d_, integer *feq_gen_inlet_tab_d_, real *
	feq_gen_outlet_length_d_, integer *feq_gen_outlet_tab_d_, real *feq_gen_inlet_loss_factor_d_, 
	real *feq_gen_h_des_d_, real *feq_gen_q_des_d_, char *label, char *line, ftnlen 
	label_len, ftnlen line_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    integer n, w;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer ie, is;
    char tpc[20], key[16];

/*     Construct a line of output of axial-pump items. */
/* SOURCE pumpitem.for:213 */
/*<       implicitnone >*/
/* SOURCE pumpitem.for:214 */
/*<        >*/
/* SOURCE pumpitem.for:217 */
/*<       realinlet_length,outlet_length,inlet_loss_factor,h_des,q_des >*/
/* SOURCE pumpitem.for:219 */
/*<       characterline*(*),label*50 >*/
/*     Local */
/* SOURCE pumpitem.for:223 */
/*<       integerie,is,n,w >*/
/* SOURCE pumpitem.for:224 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE pumpitem.for:227 */
/*<       characterget_tabid*16 >*/
/* SOURCE pumpitem.for:228 */
/*<       integerlenstr >*/
/* SOURCE pumpitem.for:229 */
/*<       externalstrip_l_blanks,lenstr,get_tabid >*/
/*     ***********************FORMATS************************************ */
/* *********************************************************************** */
/* SOURCE pumpitem.for:232 */
/*<       line=' ' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
    s_copy(line, const_cast<char*>(" "), line_len, (ftnlen)1);
/*     Process the net pump table */
/* SOURCE pumpitem.for:234 */
/*<       n=1 >*/
    n = 1;
/* SOURCE pumpitem.for:235 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:236 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:237 */
/*<       key=get_tabid(net_pump_tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, feq_gen_net_pump_tab_d_);
    s_copy(key, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:238 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:239 */
/*<       line(is+w-idlena:)=key(1:idlena) >*/
    feq_gen_i_d_1 = is + w - *idlena - 1;
    s_copy(line + feq_gen_i_d_1, key, line_len - feq_gen_i_d_1, (*idlena));
/*     Process the number of pumps */
/* SOURCE pumpitem.for:242 */
/*<       n=2 >*/
    n = 2;
/* SOURCE pumpitem.for:243 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:244 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:245 */
/*<       write(tpc(1:5),'(I5)')number_of_pumps >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_number_of_pumps_d_), (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE pumpitem.for:246 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:247 */
/*<       line(is+w-5:)=tpc(1:5) >*/
    feq_gen_i_d_1 = is + w - 6;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)5);
/*     Process the inlet conduit length */
/* SOURCE pumpitem.for:250 */
/*<       n=3 >*/
    n = 3;
/* SOURCE pumpitem.for:251 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:252 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:253 */
/*<       write(tpc(1:8),'(F8.2)')inlet_length >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_inlet_length_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:254 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:255 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the inlet conduit table */
/* SOURCE pumpitem.for:258 */
/*<       n=4 >*/
    n = 4;
/* SOURCE pumpitem.for:259 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:260 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:261 */
/*<       key=get_tabid(inlet_tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, feq_gen_inlet_tab_d_);
    s_copy(key, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:262 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:263 */
/*<       line(is+w-idlenb:)=key(1:idlenb) >*/
    feq_gen_i_d_1 = is + w - *idlenb - 1;
    s_copy(line + feq_gen_i_d_1, key, line_len - feq_gen_i_d_1, (*idlenb));
/*     Process the outlet conduit length */
/* SOURCE pumpitem.for:266 */
/*<       n=5 >*/
    n = 5;
/* SOURCE pumpitem.for:267 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:268 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:269 */
/*<       write(tpc(1:8),'(F8.2)')outlet_length >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_outlet_length_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:270 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:271 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the outlet conduit table */
/* SOURCE pumpitem.for:274 */
/*<       n=6 >*/
    n = 6;
/* SOURCE pumpitem.for:275 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:276 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:277 */
/*<       key=get_tabid(outlet_tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, feq_gen_outlet_tab_d_);
    s_copy(key, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:278 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:279 */
/*<       line(is+w-idlenc:)=key(1:idlenc) >*/
    feq_gen_i_d_1 = is + w - *idlenc - 1;
    s_copy(line + feq_gen_i_d_1, key, line_len - feq_gen_i_d_1, (*idlenc));
/*     Process the inlet-loss factor */
/* SOURCE pumpitem.for:282 */
/*<       n=7 >*/
    n = 7;
/* SOURCE pumpitem.for:283 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:284 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:285 */
/*<       write(tpc(1:8),'(F8.2)')inlet_loss_factor >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_inlet_loss_factor_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:286 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:287 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the design head */
/* SOURCE pumpitem.for:290 */
/*<       n=8 >*/
    n = 8;
/* SOURCE pumpitem.for:291 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:292 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:293 */
/*<       write(tpc(1:8),'(F8.2)')h_des >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_h_des_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:294 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:295 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the design flow */
/* SOURCE pumpitem.for:298 */
/*<       n=9 >*/
    n = 9;
/* SOURCE pumpitem.for:299 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:300 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:301 */
/*<       write(tpc(1:8),'(F8.1)')q_des >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.1)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_q_des_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:302 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:303 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the table label */
/* SOURCE pumpitem.for:306 */
/*<       n=10 >*/
    n = 10;
/* SOURCE pumpitem.for:307 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:308 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:309 */
/*<       line(is+1:)=label >*/
    feq_gen_i_d_1 = is;
    s_copy(line + feq_gen_i_d_1, label, line_len - feq_gen_i_d_1, (ftnlen)50);
/* SOURCE pumpitem.for:310 */
/*<       return >*/
    return 0;
/* SOURCE pumpitem.for:311 */
/*<       end >*/
} /* write_axialpump_items__ */




/* SOURCE pumpitem.for:315 */
/*<        >*/
/* Subroutine */ int feq_gen_read_pumploss_items_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	eflag, integer *idlena, integer *idlenb, integer *idlenc, integer *
	feq_gen_loss_tab_d_, integer *feq_gen_number_of_pumps_d_, real *feq_gen_inlet_length_d_, integer 
	*feq_gen_inlet_tab_d_, real *feq_gen_outlet_length_d_, integer *feq_gen_outlet_tab_d_, real *
	feq_gen_inlet_loss_factor_d_, real *feq_gen_q_max_d_, char *label, ftnlen line_len, 
	ftnlen label_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:756* Only \002,i3,\002 items given \
in \002,\002pump-loss description line.  Need  nine items.\002)";
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
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer n;
    extern integer feq_gen_nonblank_nonzero_d_(char *, ftnlen);
    integer ie, is;
    char tpc[20], key[16];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_52, 0 };


/*     Get the items of data for computing pumploss table */
/* SOURCE pumpitem.for:328 */
/*<       implicitnone >*/
/* SOURCE pumpitem.for:329 */
/*<        >*/
/* SOURCE pumpitem.for:332 */
/*<       realinlet_length,outlet_length,inlet_loss_factor,q_max >*/
/* SOURCE pumpitem.for:334 */
/*<       characterline*(*),label*50 >*/
/*     Local */
/* SOURCE pumpitem.for:338 */
/*<       integerie,is,itab,lkey,n >*/
/* SOURCE pumpitem.for:339 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE pumpitem.for:342 */
/*<       integernonblank_nonzero,lenstr >*/
/* SOURCE pumpitem.for:343 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE pumpitem.for:346 */
/*<    50  >*/
/* SOURCE pumpitem.for:348 */
/*<    52 format(/,' *ERR:753* Conversion error in field ',i1,' in:',/,a) >*/
/* *********************************************************************** */
/* SOURCE pumpitem.for:351 */
/*<       if(nitem.lt.9)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
/* L52: */
    if (*nitem < 9) {
/* SOURCE pumpitem.for:352 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__14.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__14);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE pumpitem.for:353 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE pumpitem.for:354 */
/*<       endif >*/
    }
/*     Process the net pump table */
/* SOURCE pumpitem.for:357 */
/*<       n=1 >*/
    n = 1;
/* SOURCE pumpitem.for:358 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:359 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:360 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:361 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:363 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE pumpitem.for:364 */
/*<       idlena=lenstr(key) >*/
    *idlena = lenstr_(key, (ftnlen)16);
/* SOURCE pumpitem.for:365 */
/*<       if(key(1:1).eq.'-')then >*/
    if (*(unsigned char *)key == '-') {
/* SOURCE pumpitem.for:366 */
/*<       loss_tab=-1 >*/
	*feq_gen_loss_tab_d_ = -1;
/* SOURCE pumpitem.for:367 */
/*<       else >*/
    } else {
/*       Convert from the table id to an internal number. */
/* SOURCE pumpitem.for:369 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*         We have an id given. */
/* SOURCE pumpitem.for:371 */
/*<       callget_internal_tab_number(stdout,key,eflag,loss_tab) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, feq_gen_loss_tab_d_, (ftnlen)
		    16);
/* SOURCE pumpitem.for:375 */
/*<       else >*/
	} else {
/* SOURCE pumpitem.for:376 */
/*<       loss_tab=0 >*/
	    *feq_gen_loss_tab_d_ = 0;
/* SOURCE pumpitem.for:377 */
/*<       endif >*/
	}
/* SOURCE pumpitem.for:378 */
/*<       endif >*/
    }
/*     Process the number of pumps */
/* SOURCE pumpitem.for:381 */
/*<       n=2 >*/
    n = 2;
/* SOURCE pumpitem.for:382 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:383 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:384 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:385 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:387 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:388 */
/*<       number_of_pumps=0 >*/
	*feq_gen_number_of_pumps_d_ = 0;
/* SOURCE pumpitem.for:389 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:390 */
/*<       read(tpc,*,err=999)number_of_pumps >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*feq_gen_number_of_pumps_d_), (ftnlen)
		sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:391 */
/*<       endif >*/
    }
/*     Process the inlet conduit length */
/* SOURCE pumpitem.for:394 */
/*<       n=3 >*/
    n = 3;
/* SOURCE pumpitem.for:395 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:396 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:397 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:398 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:400 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:401 */
/*<       inlet_length=0 >*/
	*feq_gen_inlet_length_d_ = (float)0.;
/* SOURCE pumpitem.for:402 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:403 */
/*<       read(tpc,*,err=999)inlet_length >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_inlet_length_d_), (ftnlen)
		sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:404 */
/*<       endif >*/
    }
/*     Process the inlet conduit table */
/* SOURCE pumpitem.for:407 */
/*<       n=4 >*/
    n = 4;
/* SOURCE pumpitem.for:408 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:409 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:410 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:411 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:413 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE pumpitem.for:414 */
/*<       idlenb=lenstr(key) >*/
    *idlenb = lenstr_(key, (ftnlen)16);
/*     Convert from the table id to an internal number. */
/* SOURCE pumpitem.for:416 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*       We have an id given. */
/* SOURCE pumpitem.for:418 */
/*<       callget_internal_tab_number(stdout,key,eflag,inlet_tab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, feq_gen_inlet_tab_d_, (ftnlen)16)
		;
/* SOURCE pumpitem.for:422 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:423 */
/*<       inlet_tab=0 >*/
	*feq_gen_inlet_tab_d_ = 0;
/* SOURCE pumpitem.for:424 */
/*<       endif >*/
    }
/*     Process the outlet conduit length */
/* SOURCE pumpitem.for:427 */
/*<       n=5 >*/
    n = 5;
/* SOURCE pumpitem.for:428 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:429 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:430 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:431 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:433 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:434 */
/*<       outlet_length=0 >*/
	*feq_gen_outlet_length_d_ = (float)0.;
/* SOURCE pumpitem.for:435 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:436 */
/*<       read(tpc,*,err=999)outlet_length >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_outlet_length_d_), (ftnlen)
		sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:437 */
/*<       endif >*/
    }
/*     Process the outlet conduit table */
/* SOURCE pumpitem.for:440 */
/*<       n=6 >*/
    n = 6;
/* SOURCE pumpitem.for:441 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:442 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:443 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:444 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:446 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE pumpitem.for:447 */
/*<       idlenc=lenstr(key) >*/
    *idlenc = lenstr_(key, (ftnlen)16);
/*     Convert from the table id to an internal number. */
/* SOURCE pumpitem.for:449 */
/*<       if(nonblank_nonzero(key).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(key, (ftnlen)16) > 0) {
/*       We have an id given. */
/* SOURCE pumpitem.for:451 */
/*<       callget_internal_tab_number(stdout,key,eflag,outlet_tab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, feq_gen_outlet_tab_d_, (ftnlen)
		16);
/* SOURCE pumpitem.for:455 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:456 */
/*<       outlet_tab=0 >*/
	*feq_gen_outlet_tab_d_ = 0;
/* SOURCE pumpitem.for:457 */
/*<       endif >*/
    }
/*     Process the inlet-loss factor */
/* SOURCE pumpitem.for:460 */
/*<       n=7 >*/
    n = 7;
/* SOURCE pumpitem.for:461 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:462 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:463 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:464 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:466 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:467 */
/*<       inlet_loss_factor=0.0 >*/
	*feq_gen_inlet_loss_factor_d_ = (float)0.;
/* SOURCE pumpitem.for:468 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:469 */
/*<       read(tpc,*,err=999)inlet_loss_factor >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_inlet_loss_factor_d_), (ftnlen)
		sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:470 */
/*<       endif >*/
    }
/*     Process the maximum flow */
/* SOURCE pumpitem.for:473 */
/*<       n=8 >*/
    n = 8;
/* SOURCE pumpitem.for:474 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:475 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:476 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE pumpitem.for:477 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE pumpitem.for:479 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE pumpitem.for:480 */
/*<       q_max=0.0 >*/
	*feq_gen_q_max_d_ = (float)0.;
/* SOURCE pumpitem.for:481 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:482 */
/*<       read(tpc,*,err=999)q_max >*/
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
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_q_max_d_), (ftnlen)sizeof(real))
		;
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE pumpitem.for:483 */
/*<       endif >*/
    }
/*     Process the table label */
/* SOURCE pumpitem.for:487 */
/*<       n=9 >*/
    n = 9;
/* SOURCE pumpitem.for:488 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:489 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:490 */
/*<       label=line(is:ie) >*/
    s_copy(label, line + (is - 1), (ftnlen)50, ie - (is - 1));
/* SOURCE pumpitem.for:491 */
/*<       callstrip_l_blanks(label) >*/
    feq_gen_strip_l_blanks_d_(label, (ftnlen)50);
/* SOURCE pumpitem.for:493 */
/*<       return >*/
    return 0;
/* SOURCE pumpitem.for:494 */
/*<   999 continue >*/
L999:
/* SOURCE pumpitem.for:495 */
/*<       write(stdout,52)n,line >*/
    feq_gen_io_d__20.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__20);
    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, line, line_len);
    e_wsfe();
/* SOURCE pumpitem.for:496 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE pumpitem.for:497 */
/*<       end >*/
    return 0;
} /* read_pumploss_items__ */




/* SOURCE pumpitem.for:501 */
/*<        >*/
/* Subroutine */ int feq_gen_write_pumploss_items_d_(integer *stdout, integer *nitem, 
	integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *idlena, integer *
	idlenb, integer *idlenc, integer *feq_gen_loss_tab_d_, integer *
	feq_gen_number_of_pumps_d_, real *feq_gen_inlet_length_d_, integer *feq_gen_inlet_tab_d_, real *
	feq_gen_outlet_length_d_, integer *feq_gen_outlet_tab_d_, real *feq_gen_inlet_loss_factor_d_, 
	real *feq_gen_q_max_d_, char *label, char *line, ftnlen label_len, ftnlen 
	line_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    integer n, w;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer ie, is;
    char tpc[20], key[16];

/*     Construct a line of output of PUMPLOSS items. */
/* SOURCE pumpitem.for:513 */
/*<       implicitnone >*/
/* SOURCE pumpitem.for:514 */
/*<        >*/
/* SOURCE pumpitem.for:517 */
/*<       realinlet_length,outlet_length,inlet_loss_factor,q_max >*/
/* SOURCE pumpitem.for:519 */
/*<       characterline*(*),label*50 >*/
/*     Local */
/* SOURCE pumpitem.for:523 */
/*<       integerie,is,n,w >*/
/* SOURCE pumpitem.for:524 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE pumpitem.for:527 */
/*<       characterget_tabid*16 >*/
/* SOURCE pumpitem.for:528 */
/*<       integerlenstr >*/
/* SOURCE pumpitem.for:529 */
/*<       externalstrip_l_blanks,lenstr,get_tabid >*/
/*     ***********************FORMATS************************************ */
/* *********************************************************************** */
/* SOURCE pumpitem.for:532 */
/*<       line=' ' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
    s_copy(line, const_cast<char*>(" "), line_len, (ftnlen)1);
/*     Process the pump loss table id */
/* SOURCE pumpitem.for:534 */
/*<       n=1 >*/
    n = 1;
/* SOURCE pumpitem.for:535 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:536 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:537 */
/*<       key=get_tabid(loss_tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, feq_gen_loss_tab_d_);
    s_copy(key, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:538 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:539 */
/*<       line(is+w-idlena:)=key(1:idlena) >*/
    feq_gen_i_d_1 = is + w - *idlena - 1;
    s_copy(line + feq_gen_i_d_1, key, line_len - feq_gen_i_d_1, (*idlena));
/*     Process the number of pumps */
/* SOURCE pumpitem.for:542 */
/*<       n=2 >*/
    n = 2;
/* SOURCE pumpitem.for:543 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:544 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:545 */
/*<       write(tpc(1:5),'(I5)')number_of_pumps >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_number_of_pumps_d_), (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE pumpitem.for:546 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:547 */
/*<       line(is+w-5:)=tpc(1:5) >*/
    feq_gen_i_d_1 = is + w - 6;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)5);
/*     Process the inlet conduit length */
/* SOURCE pumpitem.for:550 */
/*<       n=3 >*/
    n = 3;
/* SOURCE pumpitem.for:551 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:552 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:553 */
/*<       write(tpc(1:8),'(F8.2)')inlet_length >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_inlet_length_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:554 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:555 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the inlet conduit table */
/* SOURCE pumpitem.for:558 */
/*<       n=4 >*/
    n = 4;
/* SOURCE pumpitem.for:559 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:560 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:561 */
/*<       key=get_tabid(inlet_tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, feq_gen_inlet_tab_d_);
    s_copy(key, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:562 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:563 */
/*<       line(is+w-idlenb:)=key(1:idlenb) >*/
    feq_gen_i_d_1 = is + w - *idlenb - 1;
    s_copy(line + feq_gen_i_d_1, key, line_len - feq_gen_i_d_1, (*idlenb));
/*     Process the outlet conduit length */
/* SOURCE pumpitem.for:566 */
/*<       n=5 >*/
    n = 5;
/* SOURCE pumpitem.for:567 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:568 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:569 */
/*<       write(tpc(1:8),'(F8.2)')outlet_length >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_outlet_length_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:570 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:571 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the outlet conduit table */
/* SOURCE pumpitem.for:574 */
/*<       n=6 >*/
    n = 6;
/* SOURCE pumpitem.for:575 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:576 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:577 */
/*<       key=get_tabid(outlet_tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, feq_gen_outlet_tab_d_);
    s_copy(key, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:578 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:579 */
/*<       line(is+w-idlenc:)=key(1:idlenc) >*/
    feq_gen_i_d_1 = is + w - *idlenc - 1;
    s_copy(line + feq_gen_i_d_1, key, line_len - feq_gen_i_d_1, (*idlenc));
/*     Process the inlet-loss factor */
/* SOURCE pumpitem.for:582 */
/*<       n=7 >*/
    n = 7;
/* SOURCE pumpitem.for:583 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:584 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:585 */
/*<       write(tpc(1:8),'(F8.2)')inlet_loss_factor >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_inlet_loss_factor_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:586 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:587 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the maximum flow */
/* SOURCE pumpitem.for:590 */
/*<       n=8 >*/
    n = 8;
/* SOURCE pumpitem.for:591 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:592 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:593 */
/*<       write(tpc(1:8),'(F8.1)')q_max >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 8;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.1)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_q_max_d_), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:594 */
/*<       w=ie-is+1 >*/
    w = ie - is + 1;
/* SOURCE pumpitem.for:595 */
/*<       line(is+w-8:)=tpc(1:8) >*/
    feq_gen_i_d_1 = is + w - 9;
    s_copy(line + feq_gen_i_d_1, tpc, line_len - feq_gen_i_d_1, (ftnlen)8);
/*     Process the table label */
/* SOURCE pumpitem.for:598 */
/*<       n=9 >*/
    n = 9;
/* SOURCE pumpitem.for:599 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE pumpitem.for:600 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE pumpitem.for:601 */
/*<       line(is+1:)=label >*/
    feq_gen_i_d_1 = is;
    s_copy(line + feq_gen_i_d_1, label, line_len - feq_gen_i_d_1, (ftnlen)50);
/* SOURCE pumpitem.for:602 */
/*<       return >*/
    return 0;
/* SOURCE pumpitem.for:603 */
/*<       end >*/
} /* write_pumploss_items__ */




/* SOURCE pumpitem.for:607 */
/*<       character*10functionput10(x) >*/
/* Character */ VOID put10_(char *ret_val, ftnlen ret_val_len, real *x)
{
    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char work[12], result[10];

/*     + + + PURPOSE + + + */
/*     Function to convert a real number into a special compact */
/*     form of output to retain 6 significant figures for */
/*     numbers in the range  x < 1e10. */
/* SOURCE pumpitem.for:615 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE pumpitem.for:618 */
/*<       realx >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     X      - value to format */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE pumpitem.for:624 */
/*<       characterresult*10,work*12 >*/
/* *********************************************************************** */
/* SOURCE pumpitem.for:626 */
/*<       if(abs(x).le.1.01e-9)x=0.0 >*/
    if (dabs(*x) <= (float)1.01e-9) {
	*x = (float)0.;
    }
/* SOURCE pumpitem.for:627 */
/*<       write(work,'(1PE12.5)')x >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 12;
    feq_gen_ici_d_1.iciunit = work;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(1PE12.5)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*x), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE pumpitem.for:628 */
/*<       if(work(10:10).eq.'+'.and.work(11:11).ne.'0')then >*/
    if (*(unsigned char *)&work[9] == '+' && *(unsigned char *)&work[10] != 
	    '0') {
/* SOURCE pumpitem.for:629 */
/*<       result=' *********' >*/
	s_copy(result, const_cast<char*>(" *********"), (ftnlen)10, (ftnlen)10);
/* SOURCE pumpitem.for:630 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:631 */
/*<       result(1:8)=work(1:8) >*/
	s_copy(result, work, (ftnlen)8, (ftnlen)8);
/* SOURCE pumpitem.for:632 */
/*<       result(9:9)=work(10:10) >*/
	*(unsigned char *)&result[8] = *(unsigned char *)&work[9];
/* SOURCE pumpitem.for:633 */
/*<       result(10:10)=work(12:12) >*/
	*(unsigned char *)&result[9] = *(unsigned char *)&work[11];
/* SOURCE pumpitem.for:634 */
/*<       endif >*/
    }
/* SOURCE pumpitem.for:635 */
/*<       put10=result >*/
    s_copy(ret_val, result, (ftnlen)10, (ftnlen)10);
/* SOURCE pumpitem.for:636 */
/*<       return >*/
    return ;
/* SOURCE pumpitem.for:637 */
/*<       end >*/
} /* put10_ */




/* SOURCE pumpitem.for:641 */
/*<       character*10functionput10d(x) >*/
/* Character */ VOID put10d_(char *ret_val, ftnlen ret_val_len, doublereal *x)
{
    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char work[12], result[10];

/*     + + + PURPOSE + + + */
/*     Function to convert a real*8 number into a special compact */
/*     form of output to retain 7 significant figures for */
/*     numbers in the range  x < 1e10. */
/* SOURCE pumpitem.for:649 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE pumpitem.for:652 */
/*<       real*8x >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     X      - value to format */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE pumpitem.for:658 */
/*<       characterresult*10,work*12 >*/
/* *********************************************************************** */
/* SOURCE pumpitem.for:660 */
/*<       if(abs(x).le.1.01e-9)x=0.d0 >*/
    if (abs(*x) <= (float)1.01e-9) {
	*x = 0.;
    }
/* SOURCE pumpitem.for:661 */
/*<       write(work,'(1PE12.6)')x >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 12;
    feq_gen_ici_d_1.iciunit = work;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(1PE12.6)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*x), (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE pumpitem.for:662 */
/*<       if(work(10:10).eq.'+'.and.work(11:11).ne.'0')then >*/
    if (*(unsigned char *)&work[9] == '+' && *(unsigned char *)&work[10] != 
	    '0') {
/*       OVERFLOW */
/* SOURCE pumpitem.for:664 */
/*<       result=' *********' >*/
	s_copy(result, const_cast<char*>(" *********"), (ftnlen)10, (ftnlen)10);
/* SOURCE pumpitem.for:665 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:666 */
/*<       result(1:8)=work(1:8) >*/
	s_copy(result, work, (ftnlen)8, (ftnlen)8);
/* SOURCE pumpitem.for:667 */
/*<       result(9:9)=work(10:10) >*/
	*(unsigned char *)&result[8] = *(unsigned char *)&work[9];
/* SOURCE pumpitem.for:668 */
/*<       result(10:10)=work(12:12) >*/
	*(unsigned char *)&result[9] = *(unsigned char *)&work[11];
/* SOURCE pumpitem.for:669 */
/*<       endif >*/
    }
/* SOURCE pumpitem.for:670 */
/*<       put10d=result >*/
    s_copy(ret_val, result, (ftnlen)10, (ftnlen)10);
/* SOURCE pumpitem.for:671 */
/*<       return >*/
    return ;
/* SOURCE pumpitem.for:672 */
/*<       end >*/
} /* put10d_ */




/* SOURCE pumpitem.for:677 */
/*<        >*/
/* Subroutine */ int feq_gen_output_type_234_d_(integer *stdout, integer *stdtab, 
	integer *n, integer *tab, integer *feq_gen_type_d_, real *factor, char *head, 
	char *label, real *feq_storage_x, real *feq_storage_f1, real *feq_storage_f2, char *zone, char *hgrid, 
	char *vdatum, char *unitsys, char *basis, doublereal *easting, 
	doublereal *northing, ftnlen head_len, ftnlen label_len, ftnlen 
	zone_len, ftnlen hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, 
	ftnlen basis_len)
{
    /* Format strings */
    static char fmt_1[] = "(\002 TABID=\002,a)";
    static char fmt_2[] = "(\002TABID=\002,a)";
    static char fmt_3[] = "(\002 TYPE=\002,i5)";
    static char fmt_4[] = "(\002TYPE=\002,i5)";
    static char fmt_5[] = "(\002 REFL=\002,f10.3,\002 FAC=\002,a10)";
    static char fmt_6[] = "(\002REFL=\002,f10.3,\002 FAC=\002,a10)";
    static char fmt_7[] = "(\002 \002,a,1x,a)";
    static char fmt_8[] = "(a,1x,a)";
    static char fmt_9[] = "(\002 \002,a10,a10,a10)";
    static char fmt_10[] = "(a10,a10,a10)";
    static char fmt_60[] = "(\002ZONE=\002,a8,\002 HGRID=\002,a8,\002 VDAT\
UM=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8,/,\002EASTING=\002,0pf15.\
3,\002 NORTHING=\002,f15.3)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[10];
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer j, l;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer feq_gen_head_length_d_;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen), 
	    feq_gen_chk_vdatum_unitsys_d_(integer *, char *, char *, char *, ftnlen, 
	    ftnlen, ftnlen);
    real term;
    extern /* Character */ VOID put10_(char *, ftnlen, real *);
    integer feq_gen_label_length_d_;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    char tabid[16], feq_gen_f1_out_d_[10], feq_gen_f2_out_d_[10], feq_gen_arg_out_d_[10];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_1, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_2, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_3, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_4, 0 };
    static cilist feq_gen_io_d__37 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_5, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_6, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_7, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_8, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_9, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, fmt_9, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_10, 0 };


/*     + + + PURPOSE + + + */
/*     Output a function table of type 2, 3, or 4. */
/* SOURCE pumpitem.for:686 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE pumpitem.for:689 */
/*<       integern,stdout,stdtab,tab,type >*/
/* SOURCE pumpitem.for:690 */
/*<        >*/
/* SOURCE pumpitem.for:692 */
/*<       realfactor,f1(n),f2(n),x(n) >*/
/* SOURCE pumpitem.for:693 */
/*<       real*8easting,northing >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     N      - Number of tabulated levels in the table */
/*     TAB    - Internal table number */
/*     TYPE   - type of the table, 2, 3, or 4 */
/*     FACTOR - Factor to put in the FAC position */
/*     HEAD   - heading to put on the body of the table */
/*     LABEL  - Label for identification */
/*     X      - Argument values for table */
/*     F1      - Function values to output */
/*     F2     - derivative values to output for types 3 and 4 */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE pumpitem.for:711 */
/*<       integerj,head_length,label_length,l >*/
/* SOURCE pumpitem.for:712 */
/*<       realterm >*/
/* SOURCE pumpitem.for:713 */
/*<       characterarg_out*10,f1_out*10,f2_out*10,tabid*16 >*/
/*     External functions */
/* SOURCE pumpitem.for:716 */
/*<       characterput10*10,get_tabid*16 >*/
/*     External names */
/* SOURCE pumpitem.for:719 */
/*<       externalvar_decimal,put10,get_tabid,chk_vdatum_unitsys >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE pumpitem.for:677 */
/*<       integer feq_len_trim >*/
/* SOURCE pumpitem.for:677 */
/*<       external feq_len_trim >*/
/* SOURCE pumpitem.for:722 */
/*<     1 format(' TABID=',a) >*/
/* SOURCE pumpitem.for:723 */
/*<     2 format('TABID=',a) >*/
/* SOURCE pumpitem.for:724 */
/*<     3 format(' TYPE=',i5) >*/
/* SOURCE pumpitem.for:725 */
/*<     4 format('TYPE=',i5) >*/
/* SOURCE pumpitem.for:726 */
/*<     5 format(' REFL=',f10.3,' FAC=',a10) >*/
/* SOURCE pumpitem.for:727 */
/*<     6 format('REFL=',f10.3,' FAC=',a10) >*/
/* SOURCE pumpitem.for:728 */
/*<     7 format(' ',a,1x,a) >*/
/* SOURCE pumpitem.for:729 */
/*<     8 format(a,1x,a) >*/
/* SOURCE pumpitem.for:730 */
/*<     9 format(' ',a10,a10,a10) >*/
/* SOURCE pumpitem.for:731 */
/*<    10 format(a10,a10,a10) >*/
/* SOURCE pumpitem.for:732 */
/*<    60  >*/
/* *********************************************************************** */
/* SOURCE pumpitem.for:735 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> f2(feq_storage_f2, 1);

    feq::IndexedPointer<real> f1(feq_storage_f1, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L6: */
/* L7: */
/* L8: */
/* L9: */
/* L10: */
/* L60: */
    feq_gen_chk_vdatum_unitsys_d_(stdout, vdatum, unitsys, const_cast<char*>(" during output of type 2,\
 3, or 4 table"), (ftnlen)8, (ftnlen)8, (ftnlen)39);

/* SOURCE pumpitem.for:738 */
/*<       tabid=get_tabid(tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, tab);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:739 */
/*<       l=feq_len_trim(tabid) >*/
    l = feq_gen_feq_len_trim_d_(tabid, (ftnlen)16);
/* SOURCE pumpitem.for:740 */
/*<       write(stdout,1)tabid(1:l) >*/
    feq_gen_io_d__33.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__33);
    do_fio(&feq_gen_c_d_1, tabid, l);
    e_wsfe();
/* SOURCE pumpitem.for:741 */
/*<       write(stdtab,2)tabid(1:l) >*/
    feq_gen_io_d__34.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__34);
    do_fio(&feq_gen_c_d_1, tabid, l);
    e_wsfe();
/* SOURCE pumpitem.for:743 */
/*<       write(stdout,3)type >*/
    feq_gen_io_d__35.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__35);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_type_d_), (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE pumpitem.for:744 */
/*<       write(stdtab,4)-type >*/
    feq_gen_io_d__36.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__36);
    feq_gen_i_d_1 = -(*feq_gen_type_d_);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE pumpitem.for:745 */
/*<       if(zone/='NONE')then >*/
    if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0) {
/*       Output the location information. */
/* SOURCE pumpitem.for:747 */
/*<       write(stdtab,60)zone,hgrid,vdatum,unitsys,basis,easting,northing >*/
	feq_gen_io_d__37.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__37);
	do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&(*easting), (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&(*northing), (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE pumpitem.for:749 */
/*<       endif >*/
    }
/* SOURCE pumpitem.for:751 */
/*<       arg_out=put10(factor) >*/
    put10_(feq_gen_ch_d_2, (ftnlen)10, factor);
    s_copy(feq_gen_arg_out_d_, feq_gen_ch_d_2, (ftnlen)10, (ftnlen)10);
/* SOURCE pumpitem.for:752 */
/*<       write(stdout,5)0.0,arg_out >*/
    feq_gen_io_d__39.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__39);
    do_fio(&feq_gen_c_d_1, (char *)&c_b132, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, feq_gen_arg_out_d_, (ftnlen)10);
    e_wsfe();
/* SOURCE pumpitem.for:753 */
/*<       write(stdtab,6)0.0,arg_out >*/
    feq_gen_io_d__40.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__40);
    do_fio(&feq_gen_c_d_1, (char *)&c_b132, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, feq_gen_arg_out_d_, (ftnlen)10);
    e_wsfe();
/* SOURCE pumpitem.for:755 */
/*<       if(type.eq.2)then >*/
    if (*feq_gen_type_d_ == 2) {
/* SOURCE pumpitem.for:756 */
/*<       head_length=20 >*/
	feq_gen_head_length_d_ = 20;
/* SOURCE pumpitem.for:757 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:758 */
/*<       head_length=30 >*/
	feq_gen_head_length_d_ = 30;
/* SOURCE pumpitem.for:759 */
/*<       endif >*/
    }
/* SOURCE pumpitem.for:761 */
/*<       label_length=feq_len_trim(label) >*/
    feq_gen_label_length_d_ = feq_gen_feq_len_trim_d_(label, (ftnlen)50);
/* SOURCE pumpitem.for:762 */
/*<       if(label_length.eq.0)label_length=1 >*/
    if (feq_gen_label_length_d_ == 0) {
	feq_gen_label_length_d_ = 1;
    }
/* SOURCE pumpitem.for:763 */
/*<       write(stdout,7)head(1:head_length),label(1:label_length) >*/
    feq_gen_io_d__43.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__43);
    do_fio(&feq_gen_c_d_1, head, feq_gen_head_length_d_);
    do_fio(&feq_gen_c_d_1, label, feq_gen_label_length_d_);
    e_wsfe();
/* SOURCE pumpitem.for:764 */
/*<       write(stdtab,8)head(1:head_length),label(1:label_length) >*/
    feq_gen_io_d__44.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__44);
    do_fio(&feq_gen_c_d_1, head, feq_gen_head_length_d_);
    do_fio(&feq_gen_c_d_1, label, feq_gen_label_length_d_);
    e_wsfe();
/* SOURCE pumpitem.for:766 */
/*<       do100j=1,n >*/
    feq_gen_i_d_1 = *n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE pumpitem.for:768 */
/*<       callvar_decimal(x(j),arg_out) >*/
	feq_gen_var_decimal_d_(&x[j], feq_gen_arg_out_d_, (ftnlen)10);
/* SOURCE pumpitem.for:770 */
/*<       callvar_decimal(f1(j),f1_out) >*/
	feq_gen_var_decimal_d_(&f1[j], feq_gen_f1_out_d_, (ftnlen)10);
/* SOURCE pumpitem.for:772 */
/*<       if(type.gt.2)then >*/
	if (*feq_gen_type_d_ > 2) {
/* SOURCE pumpitem.for:773 */
/*<       callvar_decimal(f2(j),f2_out) >*/
	    feq_gen_var_decimal_d_(&f2[j], feq_gen_f2_out_d_, (ftnlen)10);
/* SOURCE pumpitem.for:775 */
/*<       write(stdout,9)arg_out,f1_out,f2_out >*/
	    feq_gen_io_d__48.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__48);
	    do_fio(&feq_gen_c_d_1, feq_gen_arg_out_d_, (ftnlen)10);
	    do_fio(&feq_gen_c_d_1, feq_gen_f1_out_d_, (ftnlen)10);
	    do_fio(&feq_gen_c_d_1, feq_gen_f2_out_d_, (ftnlen)10);
	    e_wsfe();
/* SOURCE pumpitem.for:776 */
/*<       write(stdtab,10)arg_out,f1_out,f2_out >*/
	    feq_gen_io_d__49.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__49);
	    do_fio(&feq_gen_c_d_1, feq_gen_arg_out_d_, (ftnlen)10);
	    do_fio(&feq_gen_c_d_1, feq_gen_f1_out_d_, (ftnlen)10);
	    do_fio(&feq_gen_c_d_1, feq_gen_f2_out_d_, (ftnlen)10);
	    e_wsfe();
/* SOURCE pumpitem.for:777 */
/*<       else >*/
	} else {
/* SOURCE pumpitem.for:778 */
/*<       write(stdout,9)arg_out,f1_out >*/
	    feq_gen_io_d__50.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__50);
	    do_fio(&feq_gen_c_d_1, feq_gen_arg_out_d_, (ftnlen)10);
	    do_fio(&feq_gen_c_d_1, feq_gen_f1_out_d_, (ftnlen)10);
	    e_wsfe();
/* SOURCE pumpitem.for:779 */
/*<       write(stdtab,10)arg_out,f1_out >*/
	    feq_gen_io_d__51.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__51);
	    do_fio(&feq_gen_c_d_1, feq_gen_arg_out_d_, (ftnlen)10);
	    do_fio(&feq_gen_c_d_1, feq_gen_f1_out_d_, (ftnlen)10);
	    e_wsfe();
/* SOURCE pumpitem.for:780 */
/*<       endif >*/
	}
/* SOURCE pumpitem.for:782 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE pumpitem.for:783 */
/*<       if(x(n)>0.0)then >*/
    if (x[*n] > (float)0.) {
/* SOURCE pumpitem.for:784 */
/*<       term=-1.0 >*/
	term = (float)-1.;
/* SOURCE pumpitem.for:785 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:786 */
/*<       term=x(n)-1.0 >*/
	term = static_cast<double>(x[*n]) - (float)1.;
/* SOURCE pumpitem.for:787 */
/*<       endif >*/
    }
/* SOURCE pumpitem.for:788 */
/*<       write(stdtab,'(F10.1)')term >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdtab;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(F10.1)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&term, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE pumpitem.for:789 */
/*<       return >*/
    return 0;
/* SOURCE pumpitem.for:790 */
/*<       end >*/
} /* output_type_234__ */




/* SOURCE pumpitem.for:797 */
/*<       subroutinepumpitems(option,grav,stdin,stdout,stdtab,eflag,ftp) >*/
/* Subroutine */ int pumpitems_(char *option, real *grav, integer *stdin, 
	integer *stdout, integer *stdtab, integer *eflag, integer *ftp, 
	ftnlen option_len)
{
    /* Initialized data */

    static real feq_gen_axial_h_rel_d_[17] = { (float)1e3,(float)2.96,(float)2.62,(
	    float)2.34,(float)2.1,(float)1.93,(float)1.73,(float)1.59,(float)
	    1.49,(float)1.41,(float)1.24,(float)1.,(float).75,(float).53,(
	    float).18,(float)0.,(float)-10. };
    static real feq_gen_axial_q_rel_d_[17] = { (float)0.,(float)0.,(float).1,(float).2,
	    (float).3,(float).4,(float).5,(float).6,(float).7,(float).8,(
	    float).9,(float)1.,(float)1.1,(float)1.2,(float)1.3,(float)1.37,(
	    float)1.37 };

    /* Format strings */
    static char fmt_1[] = "(6x,f15.0)";
    static char fmt_4[] = "(2i8,f8.0,i8,f8.0,i8,f8.0,1x,a)";
    static char fmt_51[] = "(/,\002 Unit for flows in the input is \002,f12.\
8,\002 \002,a5)";
    static char fmt_52[] = "(1x,a)";
    static char fmt_54[] = "(1x,/,\002 *ERR:726* TabId= \002,a,\002 for inle\
t conduit cross \002,\002section not found.\002)";
    static char fmt_56[] = "(1x,/,\002 *ERR:727* TabId=\002,a,\002 for outle\
t conduit cross \002,\002section not found.\002)";
    static char fmt_58[] = "(1x,/,\002 *BUG: Invalid option in sub. PUMPITEM\
S.\002)";
    static char fmt_62[] = "(1x,2i8,f8.2,i8,f8.2,i8,f8.2,f8.0,f8.1,f8.0,1x,a)"
	    ;
    static char fmt_61[] = "(1x,a)";
    static char fmt_64[] = "(\002 A=\002,a7)";
    static char fmt_66[] = "(\002 The values of flow in the pump capacity ta\
ble are in\002,\002 the same\002,/,\002 units as used for the design flows \
.\002,\002  The body of the table gives the\002,/,\002 capacity for one\002\
,\002 pump and FAC includes the adjustment for flow\002,/,\002 units as well\
 as number of pumps.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[7];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle(), s_cmp(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    integer feq_gen_number_of_pumps_d_, feq_gen_head_len_d_[4], feq_gen_item_end_d_[10];
    real feq_gen_q_factor_d_;
    integer feq_gen_loss_tab_d_;
    real feq_gen_d_outlet_d_, feq_gen_k_outlet_d_;
    doublereal northing;
    real a, b;
    integer feq_gen_i_d_, m, n;
    real t;
    char feq_gen_body_head_d_[30];
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer feq_gen_inlet_tab_d_;
    char feq_gen_exit_area_d_[7];
    real f1[1000], f2[1000], db;
    integer ef;
    real dk, feq_gen_inlet_loss_factor_d_, dt;
    integer it, feq_gen_inlet_adrs_d_, feq_gen_outlet_tab_d_, feq_gen_item_start_d_[10];
    char feq_gen_flow_units_d_[5];
    real arg[1000];
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer feq_gen_outlet_adrs_d_;
    extern /* Character */ VOID put7_(char *, ftnlen, real *);
    char head[120*4];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    extern doublereal getd_(integer *, integer *);
    char line[120];
    extern /* Subroutine */ int feq_gen_read_pumploss_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *, real *, 
	    integer *, real *, real *, char *, ftnlen, ftnlen);
    char zone[8];
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char just[5];
    real feq_gen_inlet_length_d_;
    integer feq_gen_net_pump_tab_d_;
    char label[50];
    real feq_gen_h_des_d_;
    char tabid[16];
    extern /* Subroutine */ int feq_gen_read_axialpump_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *, real *, 
	    integer *, real *, real *, real *, char *, ftnlen, ftnlen);
    real feq_gen_q_des_d_;
    char hgrid[8], basis[8];
    real feq_gen_q_max_d_;
    integer nitem;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *), feq_gen_write_pumploss_items_d_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *, real *, 
	    integer *, real *, real *, char *, char *, ftnlen, ftnlen);
    real feq_gen_outlet_length_d_;
    integer idlena, idlenb, idlenc;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    real factor;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    real feq_gen_q_unit_d_;
    char vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_output_type_234_d_(integer *, integer *, 
	    integer *, integer *, integer *, real *, char *, char *, real *, 
	    real *, real *, char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen), feq_gen_write_axialpump_items_d_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *, real *, integer *, real *
	    , real *, real *, char *, char *, ftnlen, ftnlen), 
	    feq_gen_get_lctn_items_d_(integer *, integer *, integer *), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);
    integer feq_gen_gross_pump_tab_d_;
    real feq_gen_a_inlet_d_, feq_gen_d_inlet_d_, feq_gen_k_inlet_d_;
    doublereal easting;
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__69 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__128 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute various functions needed for modeling variable- */
/*     head and variable-speed pumps. */
/*     Options: */
/*         SFWMD- Compute the net head for an idealized axial flow */
/*                pump moving water through a given length of */
/*                inlet and outlet conduit plus losses at the */
/*                entrance of the inlet pipe. */
/*         PUMPLOSS - Compute the loss through the inlet and outlet */
/*                    conduit plus losses at the entrance of */
/*                    the inlet pipe. */
/*         PUMPADJ- given a pump curve for FEQ and the inlet and */
/*                  outlet conduits and an entrance loss coeff., */
/*                  compute a net pump curve. */

/* SOURCE pumpitem.for:819 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE pumpitem.for:821 */
/*<       characteroption*8 >*/
/* SOURCE pumpitem.for:822 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE pumpitem.for:823 */
/*<       realgrav >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     OPTION - gives the option */
/*     GRAV   - value of acceleration due to gravity */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTP    - next open location in the function table storage */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE pumpitem.for:835 */
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
/* INCLUDE pumpitem.for:836 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE pumpitem.for:839 */
/*<       integernhead,maxn >*/
/* SOURCE pumpitem.for:840 */
/*<       parameter(nhead=4,maxn=10) >*/
/* SOURCE pumpitem.for:841 */
/*<        >*/
/* SOURCE pumpitem.for:847 */
/*<        >*/
/* SOURCE pumpitem.for:854 */
/*<       real*8easting,northing >*/
/* SOURCE pumpitem.for:856 */
/*<        >*/
/*     External Functions */
/* SOURCE pumpitem.for:861 */
/*<       integerlenstr >*/
/* SOURCE pumpitem.for:862 */
/*<       realgetd >*/
/* SOURCE pumpitem.for:863 */
/*<       characterput7*7,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE pumpitem.for:866 */
/*<        >*/
/*     Data initializations */
/* *********************************Formats******************************* */
/* SOURCE pumpitem.for:870 */
/*<        >*/
/* SOURCE pumpitem.for:875 */
/*<     1 format(6x,f15.0) >*/
/* L1: */
/* SOURCE pumpitem.for:876 */
/*<     2 format(2i8,f8.0,i8,f8.0,i8,2f8.0,1x,a) >*/
/* L2: */
/* SOURCE pumpitem.for:877 */
/*<     3 format(2i8,f8.0,i8,f8.0,i8,3f8.0,1x,a) >*/
/* L3: */
/* SOURCE pumpitem.for:878 */
/*<     4 format(2i8,f8.0,i8,f8.0,i8,f8.0,1x,a) >*/
/* L4: */
/* SOURCE pumpitem.for:881 */
/*<    50 format(1x,2i8,f8.2,i8,f8.2,i8,f8.2,f8.0,1x,a) >*/
/* L50: */
/* SOURCE pumpitem.for:882 */
/*<    51 format(/,' Unit for flows in the input is ',f12.8,' ',a5) >*/
/* L51: */
/* SOURCE pumpitem.for:883 */
/*<    52 format(1x,a) >*/
/* L52: */
/* SOURCE pumpitem.for:884 */
/*<    54  >*/
/* L54: */
/* SOURCE pumpitem.for:886 */
/*<    56  >*/
/* L56: */
/* SOURCE pumpitem.for:888 */
/*<    58 format(1x,/,' *BUG: Invalid option in sub. PUMPITEMS.') >*/
/* L58: */
/* SOURCE pumpitem.for:889 */
/*<    60 format(1x,2i8,f8.2,i8,f8.2,i8,f8.2,f8.1,f8.0,1x,a) >*/
/* L60: */
/* SOURCE pumpitem.for:890 */
/*<    62 format(1x,2i8,f8.2,i8,f8.2,i8,f8.2,f8.0,f8.1,f8.0,1x,a) >*/
/* L62: */
/* SOURCE pumpitem.for:891 */
/*<    61 format(1x,a) >*/
/* L61: */
/* SOURCE pumpitem.for:892 */
/*<    64 format(' A=',a7) >*/
/* L64: */
/* SOURCE pumpitem.for:893 */
/*<    66  >*/
/* L66: */
/* *********************************************************************** */
/* SOURCE pumpitem.for:899 */
/*<       if(grav.lt.12.)then >*/
    if (*grav < (float)12.) {
/*       FEQ wants cubic meters per second for flows. */
/* SOURCE pumpitem.for:901 */
/*<       flow_units='m^3/s' >*/
	s_copy(feq_gen_flow_units_d_, const_cast<char*>("m^3/s"), (ftnlen)5, (ftnlen)5);
/* SOURCE pumpitem.for:902 */
/*<       else >*/
    } else {
/*       FEQ wants cubic feet per second for flows. */
/* SOURCE pumpitem.for:904 */
/*<       flow_units='f^3/s' >*/
	s_copy(feq_gen_flow_units_d_, const_cast<char*>("f^3/s"), (ftnlen)5, (ftnlen)5);
/* SOURCE pumpitem.for:905 */
/*<       endif >*/
    }
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items.  Global values for zone, hgrid, vdatum, and */
/*     unitsys are handled in subroutine TABOUT */
/* SOURCE pumpitem.for:911 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE pumpitem.for:913 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE pumpitem.for:917 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/*     Get the size of the user's flow unit in the input for flows. */
/* SOURCE pumpitem.for:920 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE pumpitem.for:924 */
/*<       read(line,1)q_unit >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 120;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_q_unit_d_, (ftnlen)sizeof(real));
    e_rsfi();
/* SOURCE pumpitem.for:926 */
/*<       write(stdout,51)q_unit,flow_units >*/
    feq_gen_io_d__69.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__69);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_q_unit_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, feq_gen_flow_units_d_, (ftnlen)5);
    e_wsfe();
/* SOURCE pumpitem.for:927 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__70.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__70);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE pumpitem.for:928 */
/*<       if(option.eq.'SFWMD')then >*/
    if (s_cmp(option, const_cast<char*>("SFWMD"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE pumpitem.for:929 */
/*<       write(stdout,66) >*/
	feq_gen_io_d__71.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__71);
	e_wsfe();
/* SOURCE pumpitem.for:930 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__72.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__72);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE pumpitem.for:931 */
/*<       endif >*/
    }
/*     Read the heading lines. */
/* SOURCE pumpitem.for:934 */
/*<       do100i=1,nhead >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 4; ++feq_gen_i_d_) {
/* SOURCE pumpitem.for:935 */
/*<       callinline(stdin,stdout,head(i)) >*/
	inline_(stdin, stdout, head + (feq_gen_i_d_ - 1) * 120, (ftnlen)120);
/* SOURCE pumpitem.for:938 */
/*<       head_len(i)=lenstr(head(i)) >*/
	feq_gen_head_len_d_[feq_gen_i_d_ - 1] = lenstr_(head + (feq_gen_i_d_ - 1) * 120, (ftnlen)120);
/* SOURCE pumpitem.for:939 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE pumpitem.for:941 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, head + 360, &feq_gen_c_d_10, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)120, (ftnlen)5);
/* SOURCE pumpitem.for:946 */
/*<   200 continue >*/
L200:
/* SOURCE pumpitem.for:947 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE pumpitem.for:951 */
/*<       if(option.eq.'PUMPLOSS')then >*/
    if (s_cmp(option, const_cast<char*>("PUMPLOSS"), (ftnlen)8, (ftnlen)8) == 0) {
/*          READ(LINE,2) LOSS_TAB, NUMBER_OF_PUMPS, INLET_LENGTH, */
/*     A                 INLET_TAB, OUTLET_LENGTH, OUTLET_TAB, */
/*     B                 INLET_LOSS_FACTOR,  Q_MAX, LABEL */
/* SOURCE pumpitem.for:955 */
/*<        >*/
	feq_gen_read_pumploss_items_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, 
		eflag, &idlena, &idlenb, &idlenc, &feq_gen_loss_tab_d_, &
		feq_gen_number_of_pumps_d_, &feq_gen_inlet_length_d_, &feq_gen_inlet_tab_d_, &
		feq_gen_outlet_length_d_, &feq_gen_outlet_tab_d_, &feq_gen_inlet_loss_factor_d_, &
		feq_gen_q_max_d_, label, (ftnlen)120, (ftnlen)50);
/* SOURCE pumpitem.for:965 */
/*<       n=loss_tab >*/
	n = feq_gen_loss_tab_d_;
/* SOURCE pumpitem.for:966 */
/*<       m=n >*/
	m = n;
/* SOURCE pumpitem.for:967 */
/*<       elseif(option.eq.'SFWMD')then >*/
    } else if (s_cmp(option, const_cast<char*>("SFWMD"), (ftnlen)8, (ftnlen)5) == 0) {
/*          READ(LINE,3) NET_PUMP_TAB, NUMBER_OF_PUMPS, */
/*     A                INLET_LENGTH, INLET_TAB, */
/*     B      OUTLET_LENGTH, OUTLET_TAB, INLET_LOSS_FACTOR, */
/*     C      H_DES, Q_DES, LABEL */
/* SOURCE pumpitem.for:972 */
/*<        >*/
	feq_gen_read_axialpump_items_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_,
		 eflag, &idlena, &idlenb, &idlenc, &feq_gen_net_pump_tab_d_, &
		feq_gen_number_of_pumps_d_, &feq_gen_inlet_length_d_, &feq_gen_inlet_tab_d_, &
		feq_gen_outlet_length_d_, &feq_gen_outlet_tab_d_, &feq_gen_inlet_loss_factor_d_, &
		feq_gen_h_des_d_, &feq_gen_q_des_d_, label, (ftnlen)120, (ftnlen)50);
/* SOURCE pumpitem.for:982 */
/*<       if(number_of_pumps.le.0)number_of_pumps=1 >*/
	if (feq_gen_number_of_pumps_d_ <= 0) {
	    feq_gen_number_of_pumps_d_ = 1;
	}
/* SOURCE pumpitem.for:983 */
/*<       n=net_pump_tab >*/
	n = feq_gen_net_pump_tab_d_;
/* SOURCE pumpitem.for:984 */
/*<       m=n >*/
	m = n;
/* SOURCE pumpitem.for:985 */
/*<       elseif(option.eq.'PUMPADJ')then >*/
    } else if (s_cmp(option, const_cast<char*>("PUMPADJ"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE pumpitem.for:986 */
/*<        >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 120;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_4;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_gross_pump_tab_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_net_pump_tab_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_inlet_length_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_inlet_tab_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_outlet_length_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_outlet_tab_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_inlet_loss_factor_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
	e_rsfi();
/* SOURCE pumpitem.for:989 */
/*<       n=gross_pump_tab >*/
	n = feq_gen_gross_pump_tab_d_;
/* SOURCE pumpitem.for:990 */
/*<       m=net_pump_tab >*/
	m = feq_gen_net_pump_tab_d_;
/* SOURCE pumpitem.for:991 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:992 */
/*<       write(stdout,58) >*/
	feq_gen_io_d__97.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__97);
	e_wsfe();
/* SOURCE pumpitem.for:993 */
/*<       stop' Abnormal stop. Bug found.' >*/
	s_stop(const_cast<char*>(" Abnormal stop. Bug found."), (ftnlen)26);
/* SOURCE pumpitem.for:994 */
/*<       endif >*/
    }
/* SOURCE pumpitem.for:996 */
/*<       if(n.le.0)goto300 >*/
    if (n <= 0) {
	goto L300;
    }
/* SOURCE pumpitem.for:998 */
/*<       write(stdout,'(/)') >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(/)");
    s_wsfe(&feq_gen_ci_d_1);
    e_wsfe();
/* SOURCE pumpitem.for:999 */
/*<       do210i=1,nhead >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 4; ++feq_gen_i_d_) {
/* SOURCE pumpitem.for:1000 */
/*<       write(stdout,52)head(i)(1:head_len(i)) >*/
	feq_gen_io_d__98.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__98);
	do_fio(&feq_gen_c_d_1, head + (feq_gen_i_d_ - 1) * 120, feq_gen_head_len_d_[feq_gen_i_d_ - 1]);
	e_wsfe();
/* SOURCE pumpitem.for:1001 */
/*<   210 continue >*/
/* L210: */
    }
/* SOURCE pumpitem.for:1003 */
/*<       if(option.eq.'PUMPLOSS')then >*/
    if (s_cmp(option, const_cast<char*>("PUMPLOSS"), (ftnlen)8, (ftnlen)8) == 0) {
/*          WRITE(STDOUT,50) LOSS_TAB, NUMBER_OF_PUMPS, */
/*     A                     INLET_LENGTH, INLET_TAB, */
/*     B                     OUTLET_LENGTH, OUTLET_TAB, */
/*     C                     INLET_LOSS_FACTOR, Q_MAX, LABEL */
/* SOURCE pumpitem.for:1008 */
/*<        >*/
	feq_gen_write_pumploss_items_d_(stdout, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, &
		idlena, &idlenb, &idlenc, &feq_gen_loss_tab_d_, &feq_gen_number_of_pumps_d_, &
		feq_gen_inlet_length_d_, &feq_gen_inlet_tab_d_, &feq_gen_outlet_length_d_, &feq_gen_outlet_tab_d_,
		 &feq_gen_inlet_loss_factor_d_, &feq_gen_q_max_d_, label, line, (ftnlen)50, (
		ftnlen)120);
/* SOURCE pumpitem.for:1017 */
/*<       write(stdout,61)line >*/
	feq_gen_io_d__99.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__99);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
	e_wsfe();
/* SOURCE pumpitem.for:1018 */
/*<       elseif(option.eq.'SFWMD')then >*/
    } else if (s_cmp(option, const_cast<char*>("SFWMD"), (ftnlen)8, (ftnlen)5) == 0) {
/*          WRITE(STDOUT,60) NET_PUMP_TAB, NUMBER_OF_PUMPS, */
/*     A                    INLET_LENGTH, INLET_TAB, */
/*     B           OUTLET_LENGTH, OUTLET_TAB, INLET_LOSS_FACTOR, */
/*     C           H_DES, Q_DES, LABEL */
/* SOURCE pumpitem.for:1023 */
/*<        >*/
	feq_gen_write_axialpump_items_d_(stdout, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, &
		idlena, &idlenb, &idlenc, &feq_gen_net_pump_tab_d_, &feq_gen_number_of_pumps_d_,
		 &feq_gen_inlet_length_d_, &feq_gen_inlet_tab_d_, &feq_gen_outlet_length_d_, &
		feq_gen_outlet_tab_d_, &feq_gen_inlet_loss_factor_d_, &feq_gen_h_des_d_, &feq_gen_q_des_d_, label,
		 line, (ftnlen)50, (ftnlen)120);
/* SOURCE pumpitem.for:1032 */
/*<       write(stdout,61)line >*/
	feq_gen_io_d__100.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__100);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
	e_wsfe();
/* SOURCE pumpitem.for:1033 */
/*<       elseif(option.eq.'PUMPADJ')then >*/
    } else if (s_cmp(option, const_cast<char*>("PUMPADJ"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE pumpitem.for:1034 */
/*<        >*/
	feq_gen_io_d__101.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__101);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_gross_pump_tab_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_net_pump_tab_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_inlet_length_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_inlet_tab_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_outlet_length_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_outlet_tab_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_inlet_loss_factor_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
	e_wsfe();
/* SOURCE pumpitem.for:1037 */
/*<       endif >*/
    }
/*       Get the values needed by all options. */
/* SOURCE pumpitem.for:1040 */
/*<       ef=0 >*/
    ef = 0;
/* SOURCE pumpitem.for:1041 */
/*<       if(inlet_tab.gt.0)then >*/
    if (feq_gen_inlet_tab_d_ > 0) {
/* SOURCE pumpitem.for:1042 */
/*<       inlet_adrs=inlet_tab >*/
	feq_gen_inlet_adrs_d_ = feq_gen_inlet_tab_d_;
/* SOURCE pumpitem.for:1043 */
/*<       callchktab(20,stdout,ftpnt,pmxtab,inlet_adrs,ef) >*/
	chktab_(&feq_gen_c_d_20, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &feq_gen_inlet_adrs_d_, &
		ef);
/* SOURCE pumpitem.for:1047 */
/*<       if(ef.ne.0)then >*/
	if (ef != 0) {
/* SOURCE pumpitem.for:1048 */
/*<       tabid=get_tabid(inlet_tab) >*/
	    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_inlet_tab_d_);
	    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:1049 */
/*<       write(stdout,54)tabid(1:lenstr(tabid)) >*/
	    feq_gen_io_d__105.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__105);
	    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	    e_wsfe();
/* SOURCE pumpitem.for:1050 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE pumpitem.for:1051 */
/*<       else >*/
	} else {
/* SOURCE pumpitem.for:1052 */
/*<       d_inlet=getd(inlet_adrs,stdout) >*/
	    feq_gen_d_inlet_d_ = getd_(&feq_gen_inlet_adrs_d_, stdout);
/* SOURCE pumpitem.for:1053 */
/*<       endif >*/
	}
/* SOURCE pumpitem.for:1054 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:1055 */
/*<       inlet_adrs=0 >*/
	feq_gen_inlet_adrs_d_ = 0;
/* SOURCE pumpitem.for:1056 */
/*<       endif >*/
    }
/* SOURCE pumpitem.for:1058 */
/*<       ef=0 >*/
    ef = 0;
/* SOURCE pumpitem.for:1059 */
/*<       if(outlet_tab.gt.0)then >*/
    if (feq_gen_outlet_tab_d_ > 0) {
/* SOURCE pumpitem.for:1060 */
/*<       outlet_adrs=outlet_tab >*/
	feq_gen_outlet_adrs_d_ = feq_gen_outlet_tab_d_;
/* SOURCE pumpitem.for:1061 */
/*<       callchktab(20,stdout,ftpnt,pmxtab,outlet_adrs,ef) >*/
	chktab_(&feq_gen_c_d_20, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &feq_gen_outlet_adrs_d_, &
		ef);
/* SOURCE pumpitem.for:1065 */
/*<       if(ef.ne.0)then >*/
	if (ef != 0) {
/* SOURCE pumpitem.for:1066 */
/*<       tabid=get_tabid(outlet_tab) >*/
	    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_outlet_tab_d_);
	    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE pumpitem.for:1067 */
/*<       write(stdout,56)tabid(1:lenstr(tabid)) >*/
	    feq_gen_io_d__108.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__108);
	    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	    e_wsfe();
/* SOURCE pumpitem.for:1068 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE pumpitem.for:1069 */
/*<       else >*/
	} else {
/* SOURCE pumpitem.for:1070 */
/*<       d_outlet=getd(outlet_adrs,stdout) >*/
	    feq_gen_d_outlet_d_ = getd_(&feq_gen_outlet_adrs_d_, stdout);
/* SOURCE pumpitem.for:1072 */
/*<       endif >*/
	}
/* SOURCE pumpitem.for:1073 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:1074 */
/*<       outlet_adrs=0 >*/
	feq_gen_outlet_adrs_d_ = 0;
/* SOURCE pumpitem.for:1075 */
/*<       endif >*/
    }
/*       Does the table to be created already exist? */
/* SOURCE pumpitem.for:1078 */
/*<       if(ftpnt(m).ne.0)callkil(25,m,eflag) >*/
    if (ftablea_1.ftpnt[m - 1] != 0) {
	kil_(&feq_gen_c_d_25, &m, eflag);
    }
/* SOURCE pumpitem.for:1083 */
/*<       if(inlet_loss_factor.lt.0.0)inlet_loss_factor=0.0 >*/
    if (feq_gen_inlet_loss_factor_d_ < (float)0.) {
	feq_gen_inlet_loss_factor_d_ = (float)0.;
    }
/*       Establish the physical parameters. */
/* SOURCE pumpitem.for:1086 */
/*<       if(inlet_adrs.gt.0)then >*/
    if (feq_gen_inlet_adrs_d_ > 0) {
/* SOURCE pumpitem.for:1087 */
/*<       callxlkt20(inlet_adrs,d_inlet,a_inlet,t,dt,k_inlet,dk,b,db) >*/
	xlkt20_(&feq_gen_inlet_adrs_d_, &feq_gen_d_inlet_d_, &feq_gen_a_inlet_d_, &t, &dt, &feq_gen_k_inlet_d_, &
		dk, &b, &db);
/* SOURCE pumpitem.for:1090 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:1091 */
/*<       a_inlet=1.0 >*/
	feq_gen_a_inlet_d_ = (float)1.;
/* SOURCE pumpitem.for:1092 */
/*<       k_inlet=1.0 >*/
	feq_gen_k_inlet_d_ = (float)1.;
/* SOURCE pumpitem.for:1093 */
/*<       inlet_length=0.0 >*/
	feq_gen_inlet_length_d_ = (float)0.;
/* SOURCE pumpitem.for:1094 */
/*<       inlet_loss_factor=0.0 >*/
	feq_gen_inlet_loss_factor_d_ = (float)0.;
/* SOURCE pumpitem.for:1095 */
/*<       endif >*/
    }
/* SOURCE pumpitem.for:1096 */
/*<       if(outlet_adrs.gt.0)then >*/
    if (feq_gen_outlet_adrs_d_ > 0) {
/* SOURCE pumpitem.for:1097 */
/*<       callxlkt20(outlet_adrs,d_outlet,a,t,dt,k_outlet,dk,b,db) >*/
	xlkt20_(&feq_gen_outlet_adrs_d_, &feq_gen_d_outlet_d_, &a, &t, &dt, &feq_gen_k_outlet_d_, &dk, &
		b, &db);
/* SOURCE pumpitem.for:1100 */
/*<       a=float(number_of_pumps)*a >*/
	a = static_cast<double>((real) feq_gen_number_of_pumps_d_) * a;
/* SOURCE pumpitem.for:1101 */
/*<       exit_area=put7(a) >*/
	put7_(feq_gen_ch_d_2, (ftnlen)7, &a);
	s_copy(feq_gen_exit_area_d_, feq_gen_ch_d_2, (ftnlen)7, (ftnlen)7);
/* SOURCE pumpitem.for:1102 */
/*<       it=lenstr(label) >*/
	it = lenstr_(label, (ftnlen)50);
/* SOURCE pumpitem.for:1103 */
/*<       if(it.lt.40)then >*/
	if (it < 40) {
/* SOURCE pumpitem.for:1104 */
/*<       write(label(it+1:it+11),64)exit_area >*/
	    feq_gen_i_d_1 = it;
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = it + 11 - feq_gen_i_d_1;
	    feq_gen_ici_d_1.iciunit = label + feq_gen_i_d_1;
	    feq_gen_ici_d_1.icifmt = fmt_64;
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, feq_gen_exit_area_d_, (ftnlen)7);
	    e_wsfi();
/* SOURCE pumpitem.for:1105 */
/*<       endif >*/
	}
/* SOURCE pumpitem.for:1106 */
/*<       else >*/
    } else {
/* SOURCE pumpitem.for:1107 */
/*<       k_outlet=1.0 >*/
	feq_gen_k_outlet_d_ = (float)1.;
/* SOURCE pumpitem.for:1108 */
/*<       outlet_length=0.0 >*/
	feq_gen_outlet_length_d_ = (float)0.;
/* SOURCE pumpitem.for:1109 */
/*<       endif >*/
    }
/*       The loss caused by the inlet and outlet conduit and the inlet */
/*       entrance losses are all proportional to the square of the flow. */
/*       Compute the factor  to use. */
/* SOURCE pumpitem.for:1115 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = feq_gen_a_inlet_d_;
/* Computing 2nd power */
    feq_gen_r_d_2 = feq_gen_k_inlet_d_;
/* Computing 2nd power */
    feq_gen_r_d_3 = feq_gen_k_outlet_d_;
    feq_gen_q_factor_d_ = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_inlet_loss_factor_d_) / (static_cast<double>(static_cast<double>(*grav) * (float)2.) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) + 
	    static_cast<double>(feq_gen_inlet_length_d_) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) + static_cast<double>(feq_gen_outlet_length_d_) / (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3);
/* SOURCE pumpitem.for:1121 */
/*<       if(eflag.ne.0)goto300 >*/
    if (*eflag != 0) {
	goto L300;
    }
/* SOURCE pumpitem.for:1124 */
/*<       if(option.eq.'PUMPLOSS')then >*/
    if (s_cmp(option, const_cast<char*>("PUMPLOSS"), (ftnlen)8, (ftnlen)8) == 0) {
/*         Compute the pump loss relationship.  Need only two values for */
/*         a table of type 4.  Output middle value for checking. */
/* SOURCE pumpitem.for:1127 */
/*<       arg(1)=0.0 >*/
	arg[0] = (float)0.;
/* SOURCE pumpitem.for:1128 */
/*<       f1(1)=0.0 >*/
	f1[0] = (float)0.;
/* SOURCE pumpitem.for:1129 */
/*<       f2(1)=0.0 >*/
	f2[0] = (float)0.;
/* SOURCE pumpitem.for:1131 */
/*<       arg(2)=0.5*q_max*q_unit*float(number_of_pumps) >*/
	arg[1] = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_q_max_d_) * (float).5) * feq_gen_q_unit_d_) * (real) feq_gen_number_of_pumps_d_;
/* SOURCE pumpitem.for:1132 */
/*<       f1(2)=q_factor*(0.5*q_max*q_unit)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(static_cast<double>(feq_gen_q_max_d_) * (float).5) * feq_gen_q_unit_d_;
	f1[1] = static_cast<double>(feq_gen_q_factor_d_) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE pumpitem.for:1133 */
/*<       f2(2)=q_factor*q_max*q_unit/float(number_of_pumps) >*/
	f2[1] = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_q_factor_d_) * feq_gen_q_max_d_) * feq_gen_q_unit_d_) / (real) feq_gen_number_of_pumps_d_;
/* SOURCE pumpitem.for:1137 */
/*<       arg(3)=q_max*q_unit*float(number_of_pumps) >*/
	arg[2] = static_cast<double>(static_cast<double>(feq_gen_q_max_d_) * feq_gen_q_unit_d_) * (real) feq_gen_number_of_pumps_d_;
/* SOURCE pumpitem.for:1138 */
/*<       f1(3)=q_factor*(q_max*q_unit)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(feq_gen_q_max_d_) * feq_gen_q_unit_d_;
	f1[2] = static_cast<double>(feq_gen_q_factor_d_) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE pumpitem.for:1139 */
/*<       f2(3)=2*q_factor*q_max*q_unit/float(number_of_pumps) >*/
	f2[2] = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_q_factor_d_) * 2) * feq_gen_q_max_d_) * feq_gen_q_unit_d_) / (real) 
		feq_gen_number_of_pumps_d_;
/* SOURCE pumpitem.for:1141 */
/*<       type=4 >*/
	feq_gen_type_d_ = 4;
/* SOURCE pumpitem.for:1142 */
/*<       body_head='      Flow Head Loss Derivativ' >*/
	s_copy(feq_gen_body_head_d_, const_cast<char*>("      Flow Head Loss Derivativ"), (ftnlen)30, (
		ftnlen)30);
/* SOURCE pumpitem.for:1143 */
/*<       factor=1.0 >*/
	factor = (float)1.;
/* SOURCE pumpitem.for:1144 */
/*<       n=3 >*/
	n = 3;
/* SOURCE pumpitem.for:1145 */
/*<       elseif(option.eq.'SFWMD')then >*/
    } else if (s_cmp(option, const_cast<char*>("SFWMD"), (ftnlen)8, (ftnlen)5) == 0) {
/*         The pump in question is assumed to be an axial flow pump */
/*         with a standard relative performance.  The flow and head are */
/*         taken relative to those at the point of maximum efficiency and */
/*         the head and flow at that point are called the design values. */
/*         The pump curve we need in FEQ is not convenient for deducting */
/*         the losses.  Therefore we will deduct the losses using the */
/*         inverse of the FEQ pump curve, the one normally given in */
/*         pump handbooks.    However, the values will still be stored */
/*         in the vectors consistent with the form that FEQ wants. */
/*         FEQ wants the pump curve to contain the flow in the pump */
/*         as a function of head across the pump.  However, when */
/*         we compute the effect of the losses in the conduits and */
/*         at the inlet conduit entrance, we will treat the */
/*         relationship as the head across the pump being a functioin */
/*         of flow. */
/*         Fill the vectors in the order required by FEQ for */
/*         the head across the pump. */
/* SOURCE pumpitem.for:1165 */
/*<       do220i=1,17 >*/
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 17; ++feq_gen_i_d_) {
/* SOURCE pumpitem.for:1166 */
/*<       f1(i)=q_des*axial_q_rel(18-i) >*/
	    f1[feq_gen_i_d_ - 1] = static_cast<double>(feq_gen_q_des_d_) * feq_gen_axial_q_rel_d_[18 - feq_gen_i_d_ - 1];
/* SOURCE pumpitem.for:1167 */
/*<       arg(i)=h_des*axial_h_rel(18-i)-q_factor*(f1(i)*q_unit)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(f1[feq_gen_i_d_ - 1]) * feq_gen_q_unit_d_;
	    arg[feq_gen_i_d_ - 1] = static_cast<double>(static_cast<double>(feq_gen_h_des_d_) * feq_gen_axial_h_rel_d_[18 - feq_gen_i_d_ - 1]) - static_cast<double>(feq_gen_q_factor_d_) 
		    * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE pumpitem.for:1169 */
/*<   220 continue >*/
/* L220: */
	}
/* SOURCE pumpitem.for:1170 */
/*<       n=17 >*/
	n = 17;
/* SOURCE pumpitem.for:1171 */
/*<       body_head='      Head      Flow' >*/
	s_copy(feq_gen_body_head_d_, const_cast<char*>("      Head      Flow"), (ftnlen)30, (ftnlen)20);
/* SOURCE pumpitem.for:1172 */
/*<       type=2 >*/
	feq_gen_type_d_ = 2;
/*         Provide for conversion of GPM to CFS and adjust for the */
/*         number of pumps.  The body of the table will contain the */
/*         the flows for ONE pump so that the user can check it */
/*         more easily. */
/* SOURCE pumpitem.for:1177 */
/*<       factor=q_unit*float(number_of_pumps) >*/
	factor = static_cast<double>(feq_gen_q_unit_d_) * (real) feq_gen_number_of_pumps_d_;
/* SOURCE pumpitem.for:1178 */
/*<       endif >*/
    }
/*       Output the finished table. */
/* SOURCE pumpitem.for:1182 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__128.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__128);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE pumpitem.for:1183 */
/*<        >*/
    feq_gen_output_type_234_d_(stdout, stdtab, &n, &m, &feq_gen_type_d_, &factor, feq_gen_body_head_d_, 
	    label, arg, f1, f2, zone, hgrid, vdatum, unitsys, basis, &easting,
	     &northing, (ftnlen)30, (ftnlen)50, (ftnlen)8, (ftnlen)8, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8);
/* SOURCE pumpitem.for:1190 */
/*<       goto200 >*/
    goto L200;
/* SOURCE pumpitem.for:1192 */
/*<   300 continue >*/
L300:
/* SOURCE pumpitem.for:1195 */
/*<       return >*/
    return 0;
/* SOURCE pumpitem.for:1196 */
/*<       end >*/
} /* pumpitems_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
