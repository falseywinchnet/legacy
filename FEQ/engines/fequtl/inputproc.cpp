/* inputproc.f -- translated by f2c (version 20240504).
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

/* COMMON putget_ is declared in common.hpp. */

#define putget_1 putget_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_50 = 50;
static integer feq_gen_c_d_7 = 7;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_5 = 5;

/*     Routines used for processing input lines from the user. */



/* SOURCE inputproc.for:6 */
/*<       subroutineclear_putget() >*/
/* Subroutine */ int feq_gen_clear_putget_d_()
{
    /* Local variables */
    integer feq_gen_i_d_;
#define pgover (feq::BitView<integer>(&putget_1, sizeof(putget_1)))

/*     Clear all put/get flags for storing and accessing function */
/*     tables stored in FTAB/ITAB.  These flags should be cleared */
/*     before the processing of any command that used any of them. */
/* SOURCE inputproc.for:12 */
/*<       implicitnone >*/
/* INCLUDE inputproc.for:14 */
/*     Common block for the values used in putting function tables */
/*     into FTAB/ITAB and getting the same. */
/*     The following commands make use of the following values: */
/*     CULVERT: */
/*       Single valued ids: */
/*         PUTQ- Table number for flow in the culvert */
/*         PUTY2- Table number for depth at section 2 */
/*         PUTMF3- Table number for momentum flux out of culvert barrel */
/*         PUTY3- Table number for depth at section 3. */
/*       Multiple valued ids: */
/*          GETQ- one or more table numbers specifing the flow into */
/*                departure reach from overbank areas where flow was */
/*                represented using the commands EMBANKQ, CHANRAT or */
/*                similar command. */
/*          GETMF- one or more table numbers specifing the momentum */
/*                flux into the departure reach from the same sources */
/*                as GETQ */
/*     CHANRAT */
/*       PUTQ- Table number for flow in the channel */
/*       PUTMF- Table number for the momentum flux from the dns end */
/*              of the channel. */
/*     EMBANKQ */
/*       PUTQ- Table number for flow over the embankment */
/*       PUTMF-Table number for momentum flux estimated for */
/*             the crest of the embankment. */
/*     ORIFICE */
/*       PUTQ-Table number for flow through the orifice */
/*       PUTMF-Table number for the momentum flux through the */
/*             orifice. */
/* SOURCE putget.cmn:38 */
/*<       integermxget,mxover >*/
/* SOURCE putget.cmn:39 */
/*<       parameter(mxget=50,mxover=5+2*(mxget+1)) >*/
/* SOURCE putget.cmn:41 */
/*<        >*/
/* SOURCE putget.cmn:45 */
/*<       common/putget/putq,putmf,putmf3,puty2,puty3,getq,getmf >*/
/* SOURCE putget.cmn:47 */
/*<       equivalence(putq,pgover) >*/
/* SOURCE putget.cmn:49 */
/*<       save/putget/ >*/
/*     Local */
/* SOURCE inputproc.for:17 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE inputproc.for:19 */
/*<       do100i=1,mxover >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 107; ++feq_gen_i_d_) {
/* SOURCE inputproc.for:20 */
/*<       pgover(i)=0 >*/
	pgover[feq_gen_i_d_ - 1] = 0;
/* SOURCE inputproc.for:21 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE inputproc.for:22 */
/*<       return >*/
    return 0;
/* SOURCE inputproc.for:23 */
/*<       end >*/
} /* clear_putget__ */

#undef pgover






/* SOURCE inputproc.for:29 */
/*<        >*/
/* Subroutine */ int feq_gen_get_multiple_real_values_d_(integer *stdin, integer *
	stdout, integer *intval, integer *reaval, integer *
	feq_gen_continuation_value_d_, integer *opt, integer *nval, char *line, 
	integer *feq_gen_feq_storage_item_type_d_, integer *feq_storage_ival, real *feq_storage_rval, doublereal *feq_storage_dpval, 
	char *feq_storage_cval, integer *feq_storage_clen, integer *eflag2, char *feq_storage_term, integer *
	feq_storage_terml, integer *feq_storage_termcls, integer *feq_gen_item_knt_d_, integer *
	feq_gen_number_of_values_d_, real *feq_gen_feq_storage_the_values_d_, ftnlen line_len, ftnlen 
	cval_len, ftnlen term_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:728* There were \002,i3,\002 invali\
d real numbers \002,\002found in the current line.\002)";
    static char fmt_56[] = "(/,\002 Unable to continue due to previous error\
s.\002)";
    static char fmt_58[] = "(/,\002 *ERR:729* Found \002,i3,\002 values on l\
ine > limit of \002,i3)";
    static char fmt_60[] = "(/,\002 Processing:\002,a)";
    static char fmt_62[] = "(/,\002 Seeking additional values.\002)";
    static char fmt_64[] = "(/,\002 *BUG:XXX* GET_MULTIPLE_REAL_VALUES:\002\
,\002 Should not be here.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer j, ie, is, it;
    extern /* Subroutine */ int feq_gen_chk_for_given_type_d_(integer *, integer *, 
	    integer *, integer *, integer *);
    integer knt;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     getval_(integer *, char *, integer *, integer *, integer *, 
	    integer *, real *, doublereal *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, ftnlen, ftnlen, ftnlen);
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, fmt_64, 0 };


/*     Get multiple real values following a variable name. */
/* SOURCE inputproc.for:39 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE inputproc.for:42 */
/*<        >*/
/* SOURCE inputproc.for:44 */
/*<        >*/
/* SOURCE inputproc.for:46 */
/*<       realrval(nval),the_values(nval) >*/
/* SOURCE inputproc.for:47 */
/*<       real*8dpval(nval) >*/
/* SOURCE inputproc.for:48 */
/*<       charactercval(nval)*(*),line*(*),term(nval)*1 >*/
/*     Definition of arguments. */
/*     STDIN- unit number for input */
/*     STDOUT- unit number for output of errors and messages. */
/*     INTVAL- code for an integer value */
/*     REAVAL- code for a real value */
/*     CONTINUATION_VALUE- code for continuing to the next line */
/*     LINE- the character string to scan. */
/*     NVAL- the maximum number of values to expect.  It is an error if */
/*           this number is exceeded. */
/*     OPT-  if 0 then */
/*       ITEM_TYPE- vector giving the type of value expected for each value in */
/*              LINE */
/*       IVAL, RVAL, DPVAL, CVAL- vectors of the correct type for storing */
/*           the values found in LINE. */
/*       CLEN- vector giving the length of the character string if the */
/*             value is of type CHARACTER. */
/*       EFLAG- set to 1 if an error was found in LINE. */
/*     else if 1 */
/*       ITEM_TYPE- vector giving the type of value found in LINE */
/*       CVAL- gives the value returned */
/*       CLEN- give the length of the value */
/*     else if 2 */
/*       like 0 but ITEM_TYPE gives the type as found in LINE and */
/*       CVAL and CLEN also contain the string form of argument. */
/*     In either case: */
/*        TERM- gives the single character value for the terminator */
/*        TERML- gives the terminator length in case we want to */
/*               make it more than one character. */
/*        TERMCLS- gives the class number of the terminator. */
/*        ITEM_KNT- the number of values actually found. A value may be null or */
/*             defaulted and it is still counted. */
/*     NUMBER_OF_VALUES- number of values returned */
/*     THE_VALUES- vector containing the values found */
/*     External program units */
/* SOURCE inputproc.for:92 */
/*<       integerlenstr >*/
/* SOURCE inputproc.for:94 */
/*<       externallenstr,getval,inline,chk_for_given_type >*/
/*     Local variables */
/* SOURCE inputproc.for:98 */
/*<       integerie,is,it,knt,j >*/
/*     ********************************FORMATS*************************** */
/* SOURCE inputproc.for:100 */
/*<    50  >*/
/* SOURCE inputproc.for:102 */
/*<    56 format(/,' Unable to continue due to previous errors.') >*/
/* SOURCE inputproc.for:103 */
/*<    58 format(/,' *ERR:729* Found ',i3,' values on line > limit of ',i3) >*/
/* SOURCE inputproc.for:104 */
/*<    60 format(/,' Processing:',a) >*/
/* SOURCE inputproc.for:105 */
/*<    62 format(/,' Seeking additional values.') >*/
/* *********************************************************************** */
/* SOURCE inputproc.for:108 */
/*<       if(item_type(2).eq.intval)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_the_values_d_(feq_gen_feq_storage_the_values_d_, 1);

    feq::IndexedPointer<integer> termcls(feq_storage_termcls, 1);

    feq::IndexedPointer<integer> terml(feq_storage_terml, 1);

    feq::IndexedPointer<char> term(feq_storage_term, 1);

    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, cval_len);

    feq::IndexedPointer<doublereal> dpval(feq_storage_dpval, 1);

    feq::IndexedPointer<real> rval(feq_storage_rval, 1);

    feq::IndexedPointer<integer> ival(feq_storage_ival, 1);

    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    /* Function Body */
/* L50: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
    if (feq_gen_item_type_d_[2] == *intval) {
/*       The user has given a count of the subsections.  Get the values */
/*       of roughness on the current line. NSUB gives the total */
/*       number of values expected. */
/* SOURCE inputproc.for:113 */
/*<       number_of_values=ival(2) >*/
	*feq_gen_number_of_values_d_ = ival[2];
/* SOURCE inputproc.for:114 */
/*<       is=3 >*/
	is = 3;
/* SOURCE inputproc.for:115 */
/*<       ie=item_knt >*/
	ie = *feq_gen_item_knt_d_;
/* SOURCE inputproc.for:116 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE inputproc.for:118 */
/*<   128 continue >*/
L128:
/* SOURCE inputproc.for:119 */
/*<       do130j=is,ie >*/
	feq_gen_i_d_1 = ie;
	for (j = is; j <= feq_gen_i_d_1; ++j) {
/* SOURCE inputproc.for:120 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE inputproc.for:121 */
/*<       if(knt.gt.nval)then >*/
	    if (knt > *nval) {
/* SOURCE inputproc.for:122 */
/*<       write(stdout,58)knt,nval >*/
		feq_gen_io_d__7.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__7);
		do_fio(&feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&(*nval), (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE inputproc.for:123 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE inputproc.for:124 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:125 */
/*<       the_values(knt)=rval(j) >*/
	    feq_gen_the_values_d_[knt] = rval[j];
/* SOURCE inputproc.for:126 */
/*<   130 continue >*/
/* L130: */
	}
/* SOURCE inputproc.for:127 */
/*<       if(knt.eq.number_of_values)then >*/
	if (knt == *feq_gen_number_of_values_d_) {
/*           All the claimed  values have been found. */
/*           We are done. */
/* SOURCE inputproc.for:130 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE inputproc.for:131 */
/*<       else >*/
	} else {
/*           Get the next line and parse it.  It should only contain */
/*           numeric data. */
/* SOURCE inputproc.for:134 */
/*<       write(stdout,62) >*/
	    feq_gen_io_d__8.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__8);
	    e_wsfe();
/* SOURCE inputproc.for:135 */
/*<       callinline(stdin,stdout,line) >*/
	    inline_(stdin, stdout, line, line_len);
/* SOURCE inputproc.for:138 */
/*<       it=lenstr(line) >*/
	    it = lenstr_(line, line_len);
/* SOURCE inputproc.for:139 */
/*<       write(stdout,60)line(1:it) >*/
	    feq_gen_io_d__10.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__10);
	    do_fio(&feq_gen_c_d_1, line, it);
	    e_wsfe();
/* SOURCE inputproc.for:140 */
/*<       line(it+1:it+1)='''' >*/
	    feq_gen_i_d_1 = it;
	    s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE inputproc.for:141 */
/*<        >*/
	    getval_(stdout, line, nval, opt, &feq_gen_item_type_d_[1], &ival[1], &rval[
		    1], &dpval[1], cval + cval_len, &clen[1], eflag2, term + 
		    1, &terml[1], &termcls[1], feq_gen_item_knt_d_, line_len, cval_len,
		     (ftnlen)1);
/* SOURCE inputproc.for:146 */
/*<       if(eflag2.ne.0)then >*/
	    if (*eflag2 != 0) {
/* SOURCE inputproc.for:147 */
/*<       write(stdout,56) >*/
		feq_gen_io_d__11.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__11);
		e_wsfe();
/* SOURCE inputproc.for:148 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE inputproc.for:149 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:150 */
/*<       eflag2=0 >*/
	    *eflag2 = 0;
/* SOURCE inputproc.for:151 */
/*<       callchk_for_given_type(1,item_knt,item_type,reaval,eflag2) >*/
	    feq_gen_chk_for_given_type_d_(&feq_gen_c_d_1, feq_gen_item_knt_d_, &feq_gen_item_type_d_[1], reaval, 
		    eflag2);
/* SOURCE inputproc.for:154 */
/*<       if(eflag2.ne.0)then >*/
	    if (*eflag2 != 0) {
/* SOURCE inputproc.for:155 */
/*<       write(stdout,50)eflag2 >*/
		feq_gen_io_d__12.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__12);
		do_fio(&feq_gen_c_d_1, (char *)&(*eflag2), (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE inputproc.for:156 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE inputproc.for:157 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:158 */
/*<   132 continue >*/
/* L132: */
/* SOURCE inputproc.for:159 */
/*<       is=1 >*/
	    is = 1;
/* SOURCE inputproc.for:160 */
/*<       ie=item_knt >*/
	    ie = *feq_gen_item_knt_d_;
/* SOURCE inputproc.for:161 */
/*<       goto128 >*/
	    goto L128;
/* SOURCE inputproc.for:162 */
/*<       endif >*/
	}
/* SOURCE inputproc.for:163 */
/*<       else >*/
    } else {
/* SOURCE inputproc.for:164 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE inputproc.for:165 */
/*<       is=2 >*/
	is = 2;
/* SOURCE inputproc.for:166 */
/*<   133 continue >*/
L133:
/*         The user has not given a count of the items */
/* SOURCE inputproc.for:168 */
/*<       if(item_type(item_knt).eq.continuation_value)then >*/
	if (feq_gen_item_type_d_[*feq_gen_item_knt_d_] == *feq_gen_continuation_value_d_) {
/* SOURCE inputproc.for:169 */
/*<       ie=item_knt-1 >*/
	    ie = *feq_gen_item_knt_d_ - 1;
/* SOURCE inputproc.for:170 */
/*<       else >*/
	} else {
/* SOURCE inputproc.for:171 */
/*<       ie=item_knt >*/
	    ie = *feq_gen_item_knt_d_;
/* SOURCE inputproc.for:172 */
/*<       endif >*/
	}
/* SOURCE inputproc.for:173 */
/*<       eflag2=0 >*/
	*eflag2 = 0;
/* SOURCE inputproc.for:174 */
/*<       callchk_for_given_type(is,ie,item_type,reaval,eflag2) >*/
	feq_gen_chk_for_given_type_d_(&is, &ie, &feq_gen_item_type_d_[1], reaval, eflag2);
/* SOURCE inputproc.for:176 */
/*<       if(eflag2.ne.0)then >*/
	if (*eflag2 != 0) {
/* SOURCE inputproc.for:177 */
/*<       write(stdout,50)eflag2 >*/
	    feq_gen_io_d__13.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__13);
	    do_fio(&feq_gen_c_d_1, (char *)&(*eflag2), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE inputproc.for:178 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE inputproc.for:179 */
/*<       endif >*/
	}
/* SOURCE inputproc.for:180 */
/*<       do135j=is,ie >*/
	feq_gen_i_d_1 = ie;
	for (j = is; j <= feq_gen_i_d_1; ++j) {
/* SOURCE inputproc.for:181 */
/*<       if(knt.gt.nval)then >*/
	    if (knt > *nval) {
/* SOURCE inputproc.for:182 */
/*<       write(stdout,58)knt,nval >*/
		feq_gen_io_d__14.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__14);
		do_fio(&feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&(*nval), (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE inputproc.for:183 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE inputproc.for:184 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:185 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE inputproc.for:186 */
/*<       the_values(knt)=rval(j) >*/
	    feq_gen_the_values_d_[knt] = rval[j];
/* SOURCE inputproc.for:187 */
/*<   135 continue >*/
/* L135: */
	}
/* SOURCE inputproc.for:188 */
/*<       if(item_type(item_knt).eq.continuation_value)then >*/
	if (feq_gen_item_type_d_[*feq_gen_item_knt_d_] == *feq_gen_continuation_value_d_) {
/*           Get the next line and process it. */
/* SOURCE inputproc.for:190 */
/*<       callinline(stdin,stdout,line) >*/
	    inline_(stdin, stdout, line, line_len);
/* SOURCE inputproc.for:193 */
/*<       it=lenstr(line) >*/
	    it = lenstr_(line, line_len);
/* SOURCE inputproc.for:194 */
/*<       write(stdout,60)line(1:it) >*/
	    feq_gen_io_d__15.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__15);
	    do_fio(&feq_gen_c_d_1, line, it);
	    e_wsfe();
/* SOURCE inputproc.for:195 */
/*<       line(it+1:it+1)='''' >*/
	    feq_gen_i_d_1 = it;
	    s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE inputproc.for:196 */
/*<        >*/
	    getval_(stdout, line, nval, opt, &feq_gen_item_type_d_[1], &ival[1], &rval[
		    1], &dpval[1], cval + cval_len, &clen[1], eflag2, term + 
		    1, &terml[1], &termcls[1], feq_gen_item_knt_d_, line_len, cval_len,
		     (ftnlen)1);
/* SOURCE inputproc.for:201 */
/*<       if(eflag2.ne.0)then >*/
	    if (*eflag2 != 0) {
/* SOURCE inputproc.for:202 */
/*<       write(stdout,56)line >*/
		feq_gen_io_d__16.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__16);
		do_fio(&feq_gen_c_d_1, line, line_len);
		e_wsfe();
/* SOURCE inputproc.for:203 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE inputproc.for:204 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:205 */
/*<       is=1 >*/
	    is = 1;
/* SOURCE inputproc.for:206 */
/*<       goto133 >*/
	    goto L133;
/* SOURCE inputproc.for:207 */
/*<       else >*/
	} else {
/*            All lines processed */
/* SOURCE inputproc.for:209 */
/*<       number_of_values=knt >*/
	    *feq_gen_number_of_values_d_ = knt;
/* SOURCE inputproc.for:210 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE inputproc.for:211 */
/*<       endif >*/
	}
/* SOURCE inputproc.for:212 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:214 */
/*<       write(stdout,64) >*/
    feq_gen_io_d__17.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__17);
    e_wsfe();
/* SOURCE inputproc.for:215 */
/*<    64  >*/
/* SOURCE inputproc.for:217 */
/*<       stop'Abnormal stop: bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: bug found."), (ftnlen)25);
/* SOURCE inputproc.for:218 */
/*<   200 continue >*/
L200:
/* SOURCE inputproc.for:219 */
/*<       return >*/
    return 0;
/* SOURCE inputproc.for:220 */
/*<       end >*/
} /* get_multiple_real_values__ */




/* SOURCE inputproc.for:224 */
/*<        >*/
/* Subroutine */ int feq_gen_get_tabid_values_d_(integer *stdin, integer *stdout, 
	integer *intval, integer *reaval, integer *chrval, integer *
	feq_gen_continuation_value_d_, integer *opt, integer *nval, integer *istart, 
	char *line, integer *feq_gen_feq_storage_item_type_d_, integer *feq_storage_ival, real *feq_storage_rval, 
	doublereal *feq_storage_dpval, char *feq_storage_cval, integer *feq_storage_clen, integer *eflag2, char *
	feq_storage_term, integer *feq_storage_terml, integer *feq_storage_termcls, integer *feq_gen_item_knt_d_, integer *
	feq_gen_number_of_values_d_, integer *feq_gen_feq_storage_the_values_d_, ftnlen line_len, ftnlen 
	cval_len, ftnlen term_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:730* Expected an integer or id but \
found: \002,a,\002 in the line being processed.\002)";
    static char fmt_56[] = "(/,\002 Errors found but attempting to continue\
.\002)";
    static char fmt_58[] = "(/,\002 *ERR:729* Found \002,i3,\002 values on l\
ine > limit of \002,i3)";
    static char fmt_60[] = "(/,\002 Processing:\002,a)";
    static char fmt_62[] = "(/,\002 Seeking additional values.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer is, it, knt;
    char tabid[16];
    integer itemp;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     getval_(integer *, char *, integer *, integer *, integer *, 
	    integer *, real *, doublereal *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, ftnlen, ftnlen, ftnlen);
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__24 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_50, 0 };


/*     Get multiple table ids following a variable name.  The line */
/*     on which the name appears has already been parsed with GETVAL. */
/*     Continuation lines, if any, are processed here as well.  The */
/*     variable name MUST be followed by an = to distinguish between */
/*     the variable and the responses. */
/* SOURCE inputproc.for:237 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE inputproc.for:239 */
/*<        >*/
/* SOURCE inputproc.for:242 */
/*<        >*/
/* SOURCE inputproc.for:244 */
/*<       realrval(nval) >*/
/* SOURCE inputproc.for:245 */
/*<       real*8dpval(nval) >*/
/* SOURCE inputproc.for:246 */
/*<       charactercval(nval)*(*),line*(*),term(nval)*1 >*/
/*     Definition of arguments. */
/*     STDIN- unit number for input */
/*     STDOUT- unit number for output of errors and messages. */
/*     INTVAL- code for an integer value */
/*     REAVAL- code for a real value */
/*     CHRVAL- code for a character values(identifier) not a string */
/*     CONTINUATION_VALUE- code for continuing to the next line */
/*     LINE- the character string to scan. */
/*     NVAL- the maximum number of values to expect.  It is an error if */
/*           this number is exceeded. */
/*     ISTART- On entry:index into ITEM_TYPE, and related vectors at which to */
/*             start processing */
/*           - On exit: index value  of the terminating identifier if any; */
/*              0 if no terminating identifier was found. */
/*     OPT-  if 0 then */
/*       ITEM_TYPE- vector giving the type of value expected for each value in */
/*              LINE */
/*       IVAL, RVAL, DPVAL, CVAL- vectors of the correct type for storing */
/*           the values found in LINE. */
/*       CLEN- vector giving the length of the character string if the */
/*             value is of type CHARACTER. */
/*       EFLAG- set to 1 if an error was found in LINE. */
/*     else if 1 */
/*       ITEM_TYPE- vector giving the type of value found in LINE */
/*       CVAL- gives the value returned */
/*       CLEN- give the length of the value */
/*     else if 2 */
/*       like 0 but ITEM_TYPE gives the type as found in LINE and */
/*       CVAL and CLEN also contain the string form of argument. */
/*     In any case: */
/*        TERM- gives the single character value for the terminator */
/*        TERML- gives the terminator length in case we want to */
/*               make it more than one character. */
/*        TERMCLS- gives the class number of the terminator. */
/*        ITEM_KNT- the number of values actually found. A value may be null or */
/*             defaulted and it is still counted. */
/*     NUMBER_OF_VALUES- number of values returned */
/*     THE_VALUES- vector containing the values found */
/*     External program units */
/* SOURCE inputproc.for:295 */
/*<       integerlenstr >*/
/* SOURCE inputproc.for:297 */
/*<       externallenstr,getval,inline,get_internal_tab_number >*/
/*     Local variables */
/* SOURCE inputproc.for:301 */
/*<       integerequal >*/
/* SOURCE inputproc.for:302 */
/*<       parameter(equal=8) >*/
/* SOURCE inputproc.for:303 */
/*<       integeris,it,knt,itemp >*/
/* SOURCE inputproc.for:304 */
/*<       charactertabid*16 >*/
/*     ********************************FORMATS*************************** */
/* SOURCE inputproc.for:306 */
/*<    50  >*/
/* SOURCE inputproc.for:308 */
/*<    56 format(/,' Errors found but attempting to continue.') >*/
/* SOURCE inputproc.for:309 */
/*<    58 format(/,' *ERR:729* Found ',i3,' values on line > limit of ',i3) >*/
/* SOURCE inputproc.for:310 */
/*<    60 format(/,' Processing:',a) >*/
/* SOURCE inputproc.for:311 */
/*<    62 format(/,' Seeking additional values.') >*/
/* *********************************************************************** */
/* SOURCE inputproc.for:313 */
/*<       knt=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_the_values_d_(feq_gen_feq_storage_the_values_d_, 1);

    feq::IndexedPointer<integer> termcls(feq_storage_termcls, 1);

    feq::IndexedPointer<integer> terml(feq_storage_terml, 1);

    feq::IndexedPointer<char> term(feq_storage_term, 1);

    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, cval_len);

    feq::IndexedPointer<doublereal> dpval(feq_storage_dpval, 1);

    feq::IndexedPointer<real> rval(feq_storage_rval, 1);

    feq::IndexedPointer<integer> ival(feq_storage_ival, 1);

    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    /* Function Body */
/* L50: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
    knt = 0;
/* SOURCE inputproc.for:314 */
/*<       is=istart >*/
    is = *istart;
/* SOURCE inputproc.for:315 */
/*<   133 continue >*/
L133:
/* SOURCE inputproc.for:317 */
/*<       if(is.gt.item_knt)then >*/
    if (is > *feq_gen_item_knt_d_) {
/*         End of line, no continuation, therefore done! */
/* SOURCE inputproc.for:319 */
/*<       istart=0 >*/
	*istart = 0;
/* SOURCE inputproc.for:320 */
/*<       number_of_values=knt >*/
	*feq_gen_number_of_values_d_ = knt;
/* SOURCE inputproc.for:321 */
/*<       goto200 >*/
	goto L200;
/* SOURCE inputproc.for:322 */
/*<       endif >*/
    }
/*       Classify the next item in the results from GETVAL */
/* SOURCE inputproc.for:325 */
/*<       if(termcls(is).eq.equal)then >*/
    if (termcls[is] == 8) {
/*         End of processing for the current identifier */
/* SOURCE inputproc.for:327 */
/*<       istart=is >*/
	*istart = is;
/* SOURCE inputproc.for:328 */
/*<       number_of_values=knt >*/
	*feq_gen_number_of_values_d_ = knt;
/* SOURCE inputproc.for:329 */
/*<       goto200 >*/
	goto L200;
/* SOURCE inputproc.for:330 */
/*<       else >*/
    } else {
/* SOURCE inputproc.for:331 */
/*<       if(item_type(is).eq.continuation_value)then >*/
	if (feq_gen_item_type_d_[is] == *feq_gen_continuation_value_d_) {
/*           Get the next line, parse it with GETVAL and process */
/* SOURCE inputproc.for:333 */
/*<       write(stdout,62) >*/
	    feq_gen_io_d__20.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__20);
	    e_wsfe();
/* SOURCE inputproc.for:334 */
/*<       callinline(stdin,stdout,line) >*/
	    inline_(stdin, stdout, line, line_len);
/* SOURCE inputproc.for:337 */
/*<       it=lenstr(line) >*/
	    it = lenstr_(line, line_len);
/* SOURCE inputproc.for:338 */
/*<       write(stdout,60)line(1:it) >*/
	    feq_gen_io_d__22.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__22);
	    do_fio(&feq_gen_c_d_1, line, it);
	    e_wsfe();
/* SOURCE inputproc.for:339 */
/*<       line(it+1:it+1)='''' >*/
	    feq_gen_i_d_1 = it;
	    s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE inputproc.for:340 */
/*<        >*/
	    getval_(stdout, line, nval, opt, &feq_gen_item_type_d_[1], &ival[1], &rval[
		    1], &dpval[1], cval + cval_len, &clen[1], eflag2, term + 
		    1, &terml[1], &termcls[1], feq_gen_item_knt_d_, line_len, cval_len,
		     (ftnlen)1);
/* SOURCE inputproc.for:345 */
/*<       if(eflag2.ne.0)then >*/
	    if (*eflag2 != 0) {
/* SOURCE inputproc.for:346 */
/*<       write(stdout,56)line >*/
		feq_gen_io_d__23.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__23);
		do_fio(&feq_gen_c_d_1, line, line_len);
		e_wsfe();
/* SOURCE inputproc.for:347 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:348 */
/*<       is=1 >*/
	    is = 1;
/* SOURCE inputproc.for:349 */
/*<       goto133 >*/
	    goto L133;
/* SOURCE inputproc.for:350 */
/*<       else >*/
	} else {
/*           We have a value.  Count it and save it. */
/* SOURCE inputproc.for:352 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE inputproc.for:353 */
/*<       if(knt.gt.nval)then >*/
	    if (knt > *nval) {
/* SOURCE inputproc.for:354 */
/*<       write(stdout,58)knt,nval >*/
		feq_gen_io_d__24.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__24);
		do_fio(&feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&(*nval), (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE inputproc.for:355 */
/*<       knt=knt-1 >*/
		--knt;
/* SOURCE inputproc.for:356 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:357 */
/*<       if(item_type(is).eq.chrval.or.item_type(is).eq.intval)then >*/
	    if (feq_gen_item_type_d_[is] == *chrval || feq_gen_item_type_d_[is] == *intval) {
/* SOURCE inputproc.for:358 */
/*<       tabid=cval(is) >*/
		s_copy(tabid, cval + is * cval_len, (ftnlen)16, cval_len);
/* SOURCE inputproc.for:359 */
/*<       callget_internal_tab_number(stdout,tabid,eflag2,itemp) >*/
		feq_gen_get_internal_tab_number_d_(stdout, tabid, eflag2, &itemp, (
			ftnlen)16);
/* SOURCE inputproc.for:364 */
/*<       the_values(knt)=itemp >*/
		feq_gen_the_values_d_[knt] = itemp;
/* SOURCE inputproc.for:365 */
/*<       else >*/
	    } else {
/*             Invalid item found. */
/* SOURCE inputproc.for:367 */
/*<       write(stdout,50)cval(is)(1:clen(is)) >*/
		feq_gen_io_d__27.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__27);
		do_fio(&feq_gen_c_d_1, cval + is * cval_len, clen[is]);
		e_wsfe();
/* SOURCE inputproc.for:368 */
/*<       eflag2=1 >*/
		*eflag2 = 1;
/* SOURCE inputproc.for:370 */
/*<       the_values(knt)=0 >*/
		feq_gen_the_values_d_[knt] = 0;
/* SOURCE inputproc.for:371 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:372 */
/*<       is=is+1 >*/
	    ++is;
/* SOURCE inputproc.for:373 */
/*<       goto133 >*/
	    goto L133;
/* SOURCE inputproc.for:374 */
/*<       endif >*/
	}
/* SOURCE inputproc.for:375 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:378 */
/*<   200 continue >*/
L200:
/* SOURCE inputproc.for:379 */
/*<       return >*/
    return 0;
/* SOURCE inputproc.for:380 */
/*<       end >*/
} /* get_tabid_values__ */




/* SOURCE inputproc.for:384 */
/*<       subroutineget_putget_options(stdin,stdout,line,command,eflag) >*/
/* Subroutine */ int feq_gen_get_putget_options_d_(integer *stdin, integer *stdout, 
	char *line, integer *command, integer *eflag, ftnlen line_len)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*7+1] = "PUTQ            PUTMF           PU\
TMF3          PUTY2           PUTY3           GETQ            GETMF         \
  ";
    static integer feq_gen_start_index_d_[7] = { 1,2,3,4,5,6,57 };
    static integer feq_gen_end_index_d_[7] = { 1,2,3,4,5,56,107 };
    static integer feq_gen_valid_for_d_[28]	/* was [7][4] */ = { 1,0,1,1,1,1,1,1,
	    1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0 };

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:731* Name=\002,a,\002 is unknown as\
 an input value.\002)";
    static char fmt_51[] = "(/,\002 *ERR:732* Name=\002,a,\002 not valid for\
 current command.\002)";
    static char fmt_52[] = "(/,\002 *ERR:733* Expected no more than \002,i3\
,\002 values for optio           \002/,11x,a,\002 but found \002,i3,\002 val\
ues instead.\002)";
    static char fmt_56[] = "(/,\002 Unable to continue due to previous error\
s.\002)";
    static char fmt_60[] = "(/,\002 Processing:\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);

    /* Local variables */
    integer feq_gen_item_knt_d_;
    extern /* Subroutine */ int feq_gen_get_tabid_values_d_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, char *, integer *, integer *, real *, doublereal *, 
	    char *, integer *, integer *, char *, integer *, integer *, 
	    integer *, integer *, integer *, ftnlen, ftnlen, ftnlen);
    integer feq_gen_number_of_values_d_, feq_gen_i_d_, j, n, feq_gen_item_type_d_[50], ib, ie, ip, is, 
	    it, feq_gen_the_values_d_[50];
    char key[16];
    integer opt, clen[50];
    char cval[256*50];
    integer ival[50];
    real rval[50];
    char term[1*50];
    extern /* Subroutine */ int feq_gen_clear_putget_d_();
    doublereal dpval[50];
    integer terml[50];
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    integer eflag2;
    extern /* Subroutine */ int getval_(integer *, char *, integer *, integer 
	    *, integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
#define pgover (feq::BitView<integer>(&putget_1, sizeof(putget_1)))
    integer istart;
    extern integer lenstr_(char *, ftnlen);
    integer termcls[50];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_52, 0 };


/*     Get the standard set of put/get function table options */
/*     for a variety of commands.  The option values are */
/*     all table numbers and are stored in common block: PUTGET. */

/* SOURCE inputproc.for:393 */
/*<       implicitnone >*/
/* INCLUDE inputproc.for:395 */
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
/* SOURCE inputproc.for:397 */
/*<       integercommand,stdin,stdout,eflag >*/
/* SOURCE inputproc.for:399 */
/*<       characterline*(*) >*/
/* INCLUDE inputproc.for:401 */
/*     Common block for the values used in putting function tables */
/*     into FTAB/ITAB and getting the same. */
/*     The following commands make use of the following values: */
/*     CULVERT: */
/*       Single valued ids: */
/*         PUTQ- Table number for flow in the culvert */
/*         PUTY2- Table number for depth at section 2 */
/*         PUTMF3- Table number for momentum flux out of culvert barrel */
/*         PUTY3- Table number for depth at section 3. */
/*       Multiple valued ids: */
/*          GETQ- one or more table numbers specifing the flow into */
/*                departure reach from overbank areas where flow was */
/*                represented using the commands EMBANKQ, CHANRAT or */
/*                similar command. */
/*          GETMF- one or more table numbers specifing the momentum */
/*                flux into the departure reach from the same sources */
/*                as GETQ */
/*     CHANRAT */
/*       PUTQ- Table number for flow in the channel */
/*       PUTMF- Table number for the momentum flux from the dns end */
/*              of the channel. */
/*     EMBANKQ */
/*       PUTQ- Table number for flow over the embankment */
/*       PUTMF-Table number for momentum flux estimated for */
/*             the crest of the embankment. */
/*     ORIFICE */
/*       PUTQ-Table number for flow through the orifice */
/*       PUTMF-Table number for the momentum flux through the */
/*             orifice. */
/* SOURCE putget.cmn:38 */
/*<       integermxget,mxover >*/
/* SOURCE putget.cmn:39 */
/*<       parameter(mxget=50,mxover=5+2*(mxget+1)) >*/
/* SOURCE putget.cmn:41 */
/*<        >*/
/* SOURCE putget.cmn:45 */
/*<       common/putget/putq,putmf,putmf3,puty2,puty3,getq,getmf >*/
/* SOURCE putget.cmn:47 */
/*<       equivalence(putq,pgover) >*/
/* SOURCE putget.cmn:49 */
/*<       save/putget/ >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE inputproc.for:406 */
/*<        >*/
/* SOURCE inputproc.for:409 */
/*<        >*/
/* SOURCE inputproc.for:412 */
/*<       integerculvert,chanrat,embankq,orifice >*/
/* SOURCE inputproc.for:413 */
/*<       parameter(culvert=1,chanrat=2,embankq=3,orifice=4) >*/
/* SOURCE inputproc.for:416 */
/*<        >*/
/* SOURCE inputproc.for:418 */
/*<        >*/
/* SOURCE inputproc.for:420 */
/*<       realrval(nval) >*/
/* SOURCE inputproc.for:421 */
/*<       real*8dpval(nval) >*/
/* SOURCE inputproc.for:422 */
/*<       charactercval(nval)*256,term(nval)*1,key*16,tabid*16 >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE inputproc.for:427 */
/*<        >*/
/* SOURCE inputproc.for:429 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE inputproc.for:431 */
/*<       savesymbol_table,valid_for,start_index,end_index >*/
/*     External names */
/* SOURCE inputproc.for:436 */
/*<       integerlenstr >*/
/* SOURCE inputproc.for:437 */
/*<       externalclear_putget,get_tabid_values,getval,lenstr,lstab >*/
/* SOURCE inputproc.for:444 */
/*<       integersi1,ei1,ei2 >*/
/* SOURCE inputproc.for:445 */
/*<       parameter(si1=mxget+7,ei1=mxget+6,ei2=2*mxget+7) >*/
/*     ****************************FORMATS******************************* */
/* SOURCE inputproc.for:440 */
/*<        >*/
/* SOURCE inputproc.for:446 */
/*<       datastart_index/1,2,3,4,5,6,si1/ >*/
/* SOURCE inputproc.for:449 */
/*<       dataend_index/1,2,3,4,5,ei1,ei2/ >*/
/* SOURCE inputproc.for:452 */
/*<        >*/
/* SOURCE inputproc.for:462 */
/*<    50 format(/,' *ERR:731* Name=',a,' is unknown as an input value.') >*/
/* L50: */
/* SOURCE inputproc.for:463 */
/*<    51 format(/,' *ERR:732* Name=',a,' not valid for current command.') >*/
/* L51: */
/* SOURCE inputproc.for:464 */
/*<    52  >*/
/* L52: */
/* SOURCE inputproc.for:466 */
/*<    56 format(/,' Unable to continue due to previous errors.') >*/
/* L56: */
/* SOURCE inputproc.for:467 */
/*<    60 format(/,' Processing:',a) >*/
/* L60: */
/* *********************************************************************** */
/*     Clear the local error flag. */
/* SOURCE inputproc.for:471 */
/*<       eflag2=0 >*/
    eflag2 = 0;
/*     Clear any existing put/get option values.  A value of zero is the */
/*     default for each option. */
/* SOURCE inputproc.for:475 */
/*<       callclear_putget() >*/
    feq_gen_clear_putget_d_();
/*     Select option for GETVAL to return BOTH the string value */
/*     and the converted value for numeric responses. */
/*     In some cases the value will be recomputed. */
/* SOURCE inputproc.for:480 */
/*<       opt=2 >*/
    opt = 2;
/*     On entry, line will contain the user input line containing the */
/*     options, if any.  There may be none given.  The line as */
/*     passed may not contain all of the options.  If not, then a */
/*     continuation value will appear at the end of the line and the */
/*     remaining options will be on the subsequent line or lines of */
/*     the file attached to STDIN. */
/* SOURCE inputproc.for:490 */
/*<       it=lenstr(line) >*/
    it = lenstr_(line, line_len);
/* SOURCE inputproc.for:491 */
/*<       if(it.eq.0)it=it+1 >*/
    if (it == 0) {
	++it;
    }
/* SOURCE inputproc.for:492 */
/*<       write(stdout,60)line(1:it) >*/
    feq_gen_io_d__36.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__36);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE inputproc.for:494 */
/*<       line(it+1:it+1)='''' >*/
    feq_gen_i_d_1 = it;
    s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE inputproc.for:496 */
/*<        >*/
    getval_(stdout, line, &feq_gen_c_d_50, &opt, feq_gen_item_type_d_, ival, rval, dpval, cval, 
	    clen, &eflag2, term, terml, termcls, &feq_gen_item_knt_d_, line_len, (
	    ftnlen)256, (ftnlen)1);
/* SOURCE inputproc.for:502 */
/*<       if(eflag2.ne.0)then >*/
    if (eflag2 != 0) {
/* SOURCE inputproc.for:503 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__47.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__47);
	e_wsfe();
/* SOURCE inputproc.for:504 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE inputproc.for:505 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:507 */
/*<       if(item_knt.eq.0)then >*/
    if (feq_gen_item_knt_d_ == 0) {
/*       No options given.  Default values accepted. */
/* SOURCE inputproc.for:509 */
/*<       goto500 >*/
	goto L500;
/* SOURCE inputproc.for:510 */
/*<       else >*/
    } else {
/*       One or more items present. The first item in the list should */
/*       be an option name.  Look it up in the symbol table and see */
/*       if it is valid. */
/* SOURCE inputproc.for:515 */
/*<       is=1 >*/
	is = 1;
/* SOURCE inputproc.for:516 */
/*<   200 continue >*/
L200:
/* SOURCE inputproc.for:517 */
/*<       key=cval(is) >*/
	s_copy(key, cval + (is - 1 << 8), (ftnlen)16, (ftnlen)256);
/* SOURCE inputproc.for:518 */
/*<       calllstab(key,symbol_table,n_symbol,ip) >*/
	lstab_(key, feq_gen_symbol_table_d_, &feq_gen_c_d_7, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE inputproc.for:521 */
/*<       if(ip.eq.0)then >*/
	if (ip == 0) {
/*           Item not found in table. */
/* SOURCE inputproc.for:523 */
/*<       write(stdout,50)key(1:lenstr(key)) >*/
	    feq_gen_io_d__51.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__51);
	    do_fio(&feq_gen_c_d_1, key, lenstr_(key, (ftnlen)16));
	    e_wsfe();
/* SOURCE inputproc.for:524 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE inputproc.for:525 */
/*<       else >*/
	} else {
/*           Is the item valid for the command? */
/* SOURCE inputproc.for:527 */
/*<       if(valid_for(ip,command).eq.0)then >*/
	    if (feq_gen_valid_for_d_[ip + *command * 7 - 8] == 0) {
/*             No. */
/* SOURCE inputproc.for:529 */
/*<       write(stdout,51)key(1:lenstr(key)) >*/
		feq_gen_io_d__52.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__52);
		do_fio(&feq_gen_c_d_1, key, lenstr_(key, (ftnlen)16));
		e_wsfe();
/* SOURCE inputproc.for:530 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE inputproc.for:531 */
/*<       else >*/
	    } else {
/*             We have a valid option here. */
/* SOURCE inputproc.for:533 */
/*<       istart=is+1 >*/
		istart = is + 1;
/* SOURCE inputproc.for:534 */
/*<        >*/
		feq_gen_get_tabid_values_d_(stdin, stdout, &feq_gen_c_d_1, &feq_gen_c_d_2, &feq_gen_c_d_4, &feq_gen_c_d_5, 
			&opt, &feq_gen_c_d_50, &istart, line, feq_gen_item_type_d_, ival, rval, 
			dpval, cval, clen, &eflag2, term, terml, termcls, &
			feq_gen_item_knt_d_, &feq_gen_number_of_values_d_, feq_gen_the_values_d_, 
			line_len, (ftnlen)256, (ftnlen)1);
/* SOURCE inputproc.for:541 */
/*<       eflag=eflag2 >*/
		*eflag = eflag2;
/* SOURCE inputproc.for:542 */
/*<       n=end_index(ip)-start_index(ip)+1 >*/
		n = feq_gen_end_index_d_[ip - 1] - feq_gen_start_index_d_[ip - 1] + 1;
/* SOURCE inputproc.for:543 */
/*<       if(number_of_values.gt.n)then >*/
		if (feq_gen_number_of_values_d_ > n) {
/*               Too many reponses to an item */
/* SOURCE inputproc.for:545 */
/*<       write(stdout,52)n,key(1:lenstr(key)),number_of_values >*/
		    feq_gen_io_d__57.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__57);
		    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, key, lenstr_(key, (ftnlen)16));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_number_of_values_d_, (ftnlen)sizeof(
			    integer));
		    e_wsfe();
/* SOURCE inputproc.for:547 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE inputproc.for:548 */
/*<       else >*/
		} else {
/*               Store the values in the overlay vector using */
/*               the indices.  This will set the value of the */
/*               actual named get/put option. */
/* SOURCE inputproc.for:552 */
/*<       ib=start_index(ip) >*/
		    ib = feq_gen_start_index_d_[ip - 1];
/* SOURCE inputproc.for:553 */
/*<       ie=ib+number_of_values-1 >*/
		    ie = ib + feq_gen_number_of_values_d_ - 1;
/* SOURCE inputproc.for:554 */
/*<       do210i=ib,ie >*/
		    feq_gen_i_d_1 = ie;
		    for (feq_gen_i_d_ = ib; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inputproc.for:555 */
/*<       j=i-ib+1 >*/
			j = feq_gen_i_d_ - ib + 1;
/* SOURCE inputproc.for:556 */
/*<       pgover(i)=the_values(j) >*/
			pgover[feq_gen_i_d_ - 1] = feq_gen_the_values_d_[j - 1];
/* SOURCE inputproc.for:557 */
/*<   210 continue >*/
/* L210: */
		    }
/* SOURCE inputproc.for:559 */
/*<       is=istart >*/
		    is = istart;
/* SOURCE inputproc.for:560 */
/*<       if(is.gt.0)then >*/
		    if (is > 0) {
/*                 Continue processing more options. */
/* SOURCE inputproc.for:562 */
/*<       goto200 >*/
			goto L200;
/* SOURCE inputproc.for:563 */
/*<       else >*/
		    } else {
/*                 All options processed. */
/* SOURCE inputproc.for:565 */
/*<       goto500 >*/
			goto L500;
/* SOURCE inputproc.for:566 */
/*<       endif >*/
		    }
/* SOURCE inputproc.for:567 */
/*<       endif >*/
		}
/* SOURCE inputproc.for:568 */
/*<       endif >*/
	    }
/* SOURCE inputproc.for:569 */
/*<       endif >*/
	}
/* SOURCE inputproc.for:570 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:571 */
/*<   500 continue >*/
L500:
/* SOURCE inputproc.for:572 */
/*<       return >*/
    return 0;
/* SOURCE inputproc.for:573 */
/*<       end >*/
} /* get_putget_options__ */

#undef pgover





/* SOURCE inputproc.for:578 */
/*<       subroutineread_tabid_plus(stdout,linea,eflag,tabid,table,follow) >*/
/* Subroutine */ int feq_gen_read_tabid_plus_d_(integer *stdout, char *linea, integer *
	eflag, char *tabid, integer *table, char *follow, ftnlen linea_len, 
	ftnlen tabid_len, ftnlen follow_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:746* Expected line with a table id \
but found:\002,/,5x,a)";
    static char fmt_52[] = "(/,\002 *ERR:747* No = found as expected in inpu\
t line:\002,/,a)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    extern integer feq_gen_nonblank_nonzero_d_(char *, ftnlen);
    integer it, nxt;
    char line[120];
    extern /* Subroutine */ int nxttok_(char *, integer *, char *, ftnlen, 
	    ftnlen), feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_52, 0 };


/*     Get the next table id and any following material */
/* SOURCE inputproc.for:584 */
/*<       implicitnone >*/
/* SOURCE inputproc.for:585 */
/*<       integereflag,stdout,table >*/
/* SOURCE inputproc.for:586 */
/*<       characterlinea*(*),tabid*16,follow*(*) >*/
/*     External names */
/* SOURCE inputproc.for:589 */
/*<       integernonblank_nonzero >*/
/* SOURCE inputproc.for:590 */
/*<       externalstrip_l_blanks,nonblank_nonzero >*/
/*     Local */
/* SOURCE inputproc.for:594 */
/*<       integerit,nxt >*/
/* SOURCE inputproc.for:595 */
/*<       characterline*120 >*/
/*     *****************************FORMATS****************************** */
/* SOURCE inputproc.for:597 */
/*<    50  >*/
/* SOURCE inputproc.for:599 */
/*<    52 format(/,' *ERR:747* No = found as expected in input line:',/,a) >*/
/* *********************************************************************** */
/* SOURCE inputproc.for:601 */
/*<       line=linea >*/
/* L50: */
/* L52: */
    s_copy(line, linea, (ftnlen)120, linea_len);
/*     Get the name field for the table id and discard.  Do a search for */
/*     the equal sign because some table ids might have no intervening */
/*     space after the equal. */
/* SOURCE inputproc.for:606 */
/*<       callstrip_l_blanks(line) >*/
    feq_gen_strip_l_blanks_d_(line, (ftnlen)120);
/* SOURCE inputproc.for:608 */
/*<       if(line(1:3).ne.'TAB')then >*/
    if (s_cmp(line, const_cast<char*>("TAB"), (ftnlen)3, (ftnlen)3) != 0) {
/* SOURCE inputproc.for:609 */
/*<       write(stdout,50)line >*/
	feq_gen_io_d__63.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__63);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
	e_wsfe();
/* SOURCE inputproc.for:610 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE inputproc.for:611 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:612 */
/*<       it=index(line,'=') >*/
    it = i_indx(line, const_cast<char*>("="), (ftnlen)120, (ftnlen)1);
/* SOURCE inputproc.for:613 */
/*<       if(it.eq.0)then >*/
    if (it == 0) {
/* SOURCE inputproc.for:614 */
/*<       write(stdout,52)line >*/
	feq_gen_io_d__65.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__65);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
	e_wsfe();
/* SOURCE inputproc.for:615 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE inputproc.for:616 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:618 */
/*<       nxt=it+1 >*/
    nxt = it + 1;
/*     Get the TABID field */
/* SOURCE inputproc.for:620 */
/*<       callnxttok(line,nxt,tabid) >*/
    nxttok_(line, &nxt, tabid, (ftnlen)120, (ftnlen)16);
/*     Get the following material.  Could be multiple items */
/*     that are processed later. */
/* SOURCE inputproc.for:628 */
/*<       follow=line(nxt:) >*/
    s_copy(follow, line + (nxt - 1), follow_len, 120 - (nxt - 1));
/* SOURCE inputproc.for:630 */
/*<       callstrip_l_blanks(follow) >*/
    feq_gen_strip_l_blanks_d_(follow, follow_len);
/*     Convert TABID to an internal number */
/* SOURCE inputproc.for:634 */
/*<       if(tabid(1:1).eq.'-')then >*/
    if (*(unsigned char *)tabid == '-') {
/* SOURCE inputproc.for:635 */
/*<       nxt=-1 >*/
	nxt = -1;
/* SOURCE inputproc.for:636 */
/*<       tabid=tabid(2:16) >*/
	s_copy(tabid, tabid + 1, (ftnlen)16, (ftnlen)15);
/* SOURCE inputproc.for:637 */
/*<       else >*/
    } else {
/* SOURCE inputproc.for:638 */
/*<       nxt=1 >*/
	nxt = 1;
/* SOURCE inputproc.for:639 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:640 */
/*<       if(nonblank_nonzero(tabid).eq.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(tabid, (ftnlen)16) == 0) {
/* SOURCE inputproc.for:641 */
/*<       table=0 >*/
	*table = 0;
/* SOURCE inputproc.for:642 */
/*<       else >*/
    } else {
/* SOURCE inputproc.for:643 */
/*<       callget_internal_tab_number(stdout,tabid,eflag,table) >*/
	feq_gen_get_internal_tab_number_d_(stdout, tabid, eflag, table, (ftnlen)16);
/* SOURCE inputproc.for:647 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:648 */
/*<       table=nxt*table >*/
    *table = nxt * *table;
/* SOURCE inputproc.for:650 */
/*<       return >*/
    return 0;
/* SOURCE inputproc.for:651 */
/*<       end >*/
} /* read_tabid_plus__ */




/* SOURCE inputproc.for:655 */
/*<       subroutineread_tabid(stdout,linea,match,eflag,tabid,table) >*/
/* Subroutine */ int feq_gen_read_tabid_d_(integer *stdout, char *linea, char *match, 
	integer *eflag, char *tabid, integer *table, ftnlen linea_len, ftnlen 
	match_len, ftnlen tabid_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:748* Expected line with \002,a,\002\
 but found:\002,/,5x,a)";
    static char fmt_52[] = "(/,\002 *ERR:749* No = found as expected in inpu\
t line:\002,/,a)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer l;
    extern integer feq_gen_nonblank_nonzero_d_(char *, ftnlen);
    integer it, nxt;
    char line[120];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int nxttok_(char *, integer *, char *, ftnlen, 
	    ftnlen), feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__69 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, fmt_52, 0 };


/*     Read a table id from the line.  The name used to */
/*     reference the table id must match MATCH */
/* SOURCE inputproc.for:663 */
/*<       implicitnone >*/
/* SOURCE inputproc.for:664 */
/*<       integereflag,stdout,table >*/
/* SOURCE inputproc.for:665 */
/*<       characterlinea*(*),tabid*16,match*(*) >*/
/*     External names */
/* SOURCE inputproc.for:668 */
/*<       integerlenstr,nonblank_nonzero >*/
/* SOURCE inputproc.for:669 */
/*<        >*/
/*     Local */
/* SOURCE inputproc.for:674 */
/*<       integerit,nxt,l >*/
/* SOURCE inputproc.for:675 */
/*<       characterline*120 >*/
/*     *****************************FORMATS****************************** */
/* SOURCE inputproc.for:677 */
/*<    50 format(/,' *ERR:748* Expected line with ',a,' but found:',/,5x,a) >*/
/* SOURCE inputproc.for:679 */
/*<    52 format(/,' *ERR:749* No = found as expected in input line:',/,a) >*/
/* *********************************************************************** */
/* SOURCE inputproc.for:681 */
/*<       line=linea >*/
/* L50: */
/* L52: */
    s_copy(line, linea, (ftnlen)120, linea_len);
/* SOURCE inputproc.for:682 */
/*<       l=lenstr(match) >*/
    l = lenstr_(match, match_len);
/*     Get the name field for the table id and discard.  Do a search for */
/*     the equal sign because some table ids might have no intervening */
/*     space after the equal. */
/* SOURCE inputproc.for:687 */
/*<       callstrip_l_blanks(line) >*/
    feq_gen_strip_l_blanks_d_(line, (ftnlen)120);
/* SOURCE inputproc.for:689 */
/*<       if(line(1:l).ne.match)then >*/
    if (s_cmp(line, match, l, match_len) != 0) {
/* SOURCE inputproc.for:690 */
/*<       write(stdout,50)match,line >*/
	feq_gen_io_d__69.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__69);
	do_fio(&feq_gen_c_d_1, match, match_len);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
	e_wsfe();
/* SOURCE inputproc.for:691 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE inputproc.for:692 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:693 */
/*<       it=index(line,'=') >*/
    it = i_indx(line, const_cast<char*>("="), (ftnlen)120, (ftnlen)1);
/* SOURCE inputproc.for:694 */
/*<       if(it.eq.0)then >*/
    if (it == 0) {
/* SOURCE inputproc.for:695 */
/*<       write(stdout,52)line >*/
	feq_gen_io_d__71.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__71);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
	e_wsfe();
/* SOURCE inputproc.for:696 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE inputproc.for:697 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:699 */
/*<       nxt=it+1 >*/
    nxt = it + 1;
/*     Get the TABID field */
/* SOURCE inputproc.for:701 */
/*<       callnxttok(line,nxt,tabid) >*/
    nxttok_(line, &nxt, tabid, (ftnlen)120, (ftnlen)16);
/*     Convert TABID to an internal number including the negative */
/*     sign that is sometimes used to signal some special action. */
/* SOURCE inputproc.for:708 */
/*<       if(tabid(1:1).eq.'-')then >*/
    if (*(unsigned char *)tabid == '-') {
/* SOURCE inputproc.for:709 */
/*<       nxt=-1 >*/
	nxt = -1;
/* SOURCE inputproc.for:710 */
/*<       tabid=tabid(2:16) >*/
	s_copy(tabid, tabid + 1, (ftnlen)16, (ftnlen)15);
/* SOURCE inputproc.for:711 */
/*<       else >*/
    } else {
/* SOURCE inputproc.for:712 */
/*<       nxt=1 >*/
	nxt = 1;
/* SOURCE inputproc.for:713 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:714 */
/*<       if(nonblank_nonzero(tabid).eq.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(tabid, (ftnlen)16) == 0) {
/* SOURCE inputproc.for:715 */
/*<       table=0 >*/
	*table = 0;
/* SOURCE inputproc.for:716 */
/*<       else >*/
    } else {
/* SOURCE inputproc.for:717 */
/*<       callget_internal_tab_number(stdout,tabid,eflag,table) >*/
	feq_gen_get_internal_tab_number_d_(stdout, tabid, eflag, table, (ftnlen)16);
/* SOURCE inputproc.for:721 */
/*<       endif >*/
    }
/* SOURCE inputproc.for:722 */
/*<       table=nxt*table >*/
    *table = nxt * *table;
/* SOURCE inputproc.for:724 */
/*<       return >*/
    return 0;
/* SOURCE inputproc.for:725 */
/*<       end >*/
} /* read_tabid__ */




/* SOURCE inputproc.for:729 */
/*<       subroutinetab_in_use(tabid,eflag) >*/
/* Subroutine */ int feq_gen_tab_in_use_d_(char *tabid, integer *eflag, ftnlen 
	tabid_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*ERR:750 Table id= \002,a,\002 is in use \
and is not available.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_50, 0 };


/*     Report that a table id is already being used. */
/* SOURCE inputproc.for:735 */
/*<       implicitnone >*/
/* SOURCE inputproc.for:737 */
/*<       integereflag >*/
/* SOURCE inputproc.for:738 */
/*<       charactertabid*16 >*/
/* INCLUDE inputproc.for:740 */
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
/*     *****************************FORMAT******************************* */
/* SOURCE inputproc.for:742 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE inputproc.for:745 */
/*<       eflag=1 >*/
/* L50: */
    *eflag = 1;
/* SOURCE inputproc.for:746 */
/*<       write(std6,50)tabid >*/
    feq_gen_io_d__73.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__73);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    e_wsfe();
/* SOURCE inputproc.for:747 */
/*<       return >*/
    return 0;
/* SOURCE inputproc.for:748 */
/*<       end >*/
} /* tab_in_use__ */

#ifdef __cplusplus
	}
#endif
