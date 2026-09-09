/* fqshrlin.f -- translated by f2c (version 20240504).
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

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_40 = 40;

/*     *********** */
/*     *         * */
/*     * CHK_AND_CONVERT_RESPONSE */
/*     *         * */
/*     *********** */
/* SOURCE fqshrlin.for:7 */
/*<        >*/
/* Subroutine */ int feq_gen_chk_and_convert_response_d_(integer *stdout, integer *
	feq_gen_n_symbol_d_, char *feq_gen_feq_storage_symbol_table_d_, integer *feq_gen_feq_storage_response_type_d_, integer *
	feq_gen_feq_storage_convert_rule_d_, integer *feq_gen_item_knt_d_, integer *feq_gen_feq_storage_item_type_d_, char *feq_storage_cval,
	 integer *feq_storage_clen, integer *eflag, integer *feq_storage_ival, real *feq_storage_rval, doublereal 
	*feq_storage_dpval, ftnlen symbol_table_len, ftnlen cval_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:368* Name=\002,a16,\002 is unknown \
as an input value.\002)";
    static char fmt_52[] = "(/,\002 *ERR:369* \002,a,\002 is invalid value f\
or \002,a)";
    static char fmt_54[] = "(/,\002 *ERR:370* Response for \002,a,\002 is mi\
ssing or in error.\002)";
    static char fmt_56[] = "(/,\002 *BUG:XXX* Invalid RESPONSE_TYPE=\002,i5\
,\002 at index=\002,i5,\002 in CHK_AND_CONVERT_RESPONSE.\002)";
    static char fmt_58[] = "(/,\002 *BUG:XXX* Conversion error in string:\
\002,a,/,5x,\002in CHK_AND_CONVERT_RESPONSE.\002)";
    static char fmt_60[] = "(/,\002 *ERR:384* \002,a,\002 is an invalid year\
 response.\002)";
    static char fmt_62[] = "(/,\002 *ERR:385* \002,a,\002 is an invalid mont\
h response.\002)";
    static char fmt_64[] = "(/,\002 *ERR:386* \002,a,\002 is an invalid day \
response.\002)";
    static char fmt_66[] = "(/,\002 *ERR:387* \002,a,\002 is an invalid hour\
 response.\002)";
    static char fmt_68[] = "(/,\002 *ERR:388* \002,a,\002 invalid for: \002,\
a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli();

    /* Local variables */
    char response[16];
    integer feq_gen_i_d_, j, ip, ir;
    char key[16];
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__4 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__21 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_58, 0 };


/*     Check that items that require a response have a valid response. */
/*     Also convert the numeric arguments following the rule */
/*     for the particular input variable. */
/*     Used for cases in which the user gives the variable name followed */
/*     by an equal sign followed by the response.  There may be responses */
/*     that do not fit this pattern.  If so, the response type for that */
/*     symbol in the symbol table is 0. */
/* SOURCE fqshrlin.for:21 */
/*<       implicitnone >*/
/* SOURCE fqshrlin.for:22 */
/*<       integereflag,n_symbol,item_knt,stdout >*/
/* SOURCE fqshrlin.for:23 */
/*<        >*/
/* SOURCE fqshrlin.for:26 */
/*<       realrval(item_knt) >*/
/* SOURCE fqshrlin.for:27 */
/*<       real*8dpval(item_knt) >*/
/* SOURCE fqshrlin.for:28 */
/*<       charactersymbol_table(n_symbol)*16,cval(item_knt)*(*) >*/
/*     Local */
/*     Parameters */
/* SOURCE fqshrlin.for:33 */
/*<       integerchrval,exact_type,datetime,dprval,intval,multr,reaval >*/
/* SOURCE fqshrlin.for:35 */
/*<        >*/
/* SOURCE fqshrlin.for:38 */
/*<       integeri,ip,ir,j >*/
/* SOURCE fqshrlin.for:39 */
/*<       characterkey*16,response*16 >*/
/*     *********************************FORMATS************************** */
/* SOURCE fqshrlin.for:41 */
/*<    50 format(/,' *ERR:368* Name=',a16,' is unknown as an input value.') >*/
/* SOURCE fqshrlin.for:42 */
/*<    52 format(/,' *ERR:369* ',a,' is invalid value for ',a) >*/
/* SOURCE fqshrlin.for:43 */
/*<    54 format(/,' *ERR:370* Response for ',a,' is missing or in error.') >*/
/* SOURCE fqshrlin.for:44 */
/*<    56  >*/
/* SOURCE fqshrlin.for:46 */
/*<    58  >*/
/* SOURCE fqshrlin.for:48 */
/*<    60 format(/,' *ERR:384* ',a,' is an invalid year response.') >*/
/* SOURCE fqshrlin.for:49 */
/*<    62 format(/,' *ERR:385* ',a,' is an invalid month response.') >*/
/* SOURCE fqshrlin.for:50 */
/*<    64 format(/,' *ERR:386* ',a,' is an invalid day response.') >*/
/* SOURCE fqshrlin.for:51 */
/*<    66 format(/,' *ERR:387* ',a,' is an invalid hour response.') >*/
/* SOURCE fqshrlin.for:52 */
/*<    68 format(/,' *ERR:388* ',a,' invalid for: ',a) >*/
/* *********************************************************************** */
/*     Construct a loop over the items found on the line of input. */
/*     We will be incrementing the loop variable depending on the */
/*     nature of the item so that the typical loop structures cannot */
/*     be used. */
/* SOURCE fqshrlin.for:59 */
/*<       i=1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_convert_rule_d_(feq_gen_feq_storage_convert_rule_d_, 1);

    feq::IndexedPointer<integer> feq_gen_response_type_d_(feq_gen_feq_storage_response_type_d_, 1);

    feq::IndexedPointer<char> feq_gen_symbol_table_d_(feq_gen_feq_storage_symbol_table_d_, 16);

    feq::IndexedPointer<doublereal> dpval(feq_storage_dpval, 1);

    feq::IndexedPointer<real> rval(feq_storage_rval, 1);

    feq::IndexedPointer<integer> ival(feq_storage_ival, 1);

    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, cval_len);

    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
/* L66: */
/* L68: */
    feq_gen_i_d_ = 1;
/* SOURCE fqshrlin.for:60 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrlin.for:61 */
/*<       key=cval(i)(1:clen(i)) >*/
    s_copy(key, cval + feq_gen_i_d_ * cval_len, (ftnlen)16, clen[feq_gen_i_d_]);
/* SOURCE fqshrlin.for:62 */
/*<       calllstab(key,symbol_table,n_symbol,ip) >*/
    lstab_(key, feq_gen_symbol_table_d_ + 16, feq_gen_n_symbol_d_, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrlin.for:65 */
/*<       if(ip.eq.0)then >*/
    if (ip == 0) {
/* SOURCE fqshrlin.for:66 */
/*<       write(stdout,50)key >*/
	feq_gen_io_d__4.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__4);
	do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrlin.for:67 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:68 */
/*<       else >*/
    } else {
/* SOURCE fqshrlin.for:69 */
/*<       if(response_type(ip).eq.0)then >*/
	if (feq_gen_response_type_d_[ip] == 0) {
/* SOURCE fqshrlin.for:70 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE fqshrlin.for:71 */
/*<       elseif(response_type(ip).eq.-1)then >*/
	} else if (feq_gen_response_type_d_[ip] == -1) {
/*           Get out now!  Checking cannot continue on this */
/*           line.  Errors were detected in parsing the */
/*           line. */
/* SOURCE fqshrlin.for:75 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrlin.for:76 */
/*<       elseif(response_type(ip).eq.datetime)then >*/
	} else if (feq_gen_response_type_d_[ip] == 7) {
/*           Special processing for a date-time string.  The pattern is */
/*           <id>=year/mn/dy:hour.  year, mn, dy are integers and hour is */
/*           double precision.  Currently, all values must appear. */
/*           Process for the year response. */
/* SOURCE fqshrlin.for:81 */
/*<       if(i+1.gt.item_knt)then >*/
	    if (feq_gen_i_d_ + 1 > *feq_gen_item_knt_d_) {
/* SOURCE fqshrlin.for:82 */
/*<       write(stdout,54)key >*/
		feq_gen_io_d__5.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__5);
		do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrlin.for:83 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:84 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:85 */
/*<       if(item_type(i+1).eq.intval)then >*/
	    if (feq_gen_item_type_d_[feq_gen_i_d_ + 1] == 1) {
/* SOURCE fqshrlin.for:86 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)ival(i+1) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
		feq_gen_ici_d_1.icifmt = 0;
		feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ival[feq_gen_i_d_ + 1], (ftnlen)
			sizeof(integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = e_rsli();
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
/* SOURCE fqshrlin.for:87 */
/*<       else >*/
	    } else {
/* SOURCE fqshrlin.for:88 */
/*<       write(stdout,60)cval(i+1)(1:clen(i+1)) >*/
		feq_gen_io_d__6.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__6);
		do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ + 1) * cval_len, clen[feq_gen_i_d_ + 1]);
		e_wsfe();
/* SOURCE fqshrlin.for:89 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:90 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/*           Process the month response. */
/* SOURCE fqshrlin.for:92 */
/*<       if(i+1.gt.item_knt)then >*/
	    if (feq_gen_i_d_ + 1 > *feq_gen_item_knt_d_) {
/* SOURCE fqshrlin.for:93 */
/*<       write(stdout,54)key >*/
		feq_gen_io_d__7.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__7);
		do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrlin.for:94 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:95 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:96 */
/*<       if(item_type(i+1).eq.intval)then >*/
	    if (feq_gen_item_type_d_[feq_gen_i_d_ + 1] == 1) {
/* SOURCE fqshrlin.for:97 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)ival(i+1) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
		feq_gen_ici_d_1.icifmt = 0;
		feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ival[feq_gen_i_d_ + 1], (ftnlen)
			sizeof(integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = e_rsli();
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
/* SOURCE fqshrlin.for:98 */
/*<       else >*/
	    } else {
/* SOURCE fqshrlin.for:99 */
/*<       write(stdout,62)cval(i+1)(1:clen(i+1)) >*/
		feq_gen_io_d__8.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__8);
		do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ + 1) * cval_len, clen[feq_gen_i_d_ + 1]);
		e_wsfe();
/* SOURCE fqshrlin.for:100 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:101 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/*           Process the day response. */
/* SOURCE fqshrlin.for:103 */
/*<       if(i+1.gt.item_knt)then >*/
	    if (feq_gen_i_d_ + 1 > *feq_gen_item_knt_d_) {
/* SOURCE fqshrlin.for:104 */
/*<       write(stdout,54)key >*/
		feq_gen_io_d__9.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__9);
		do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrlin.for:105 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:106 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:107 */
/*<       if(item_type(i+1).eq.intval)then >*/
	    if (feq_gen_item_type_d_[feq_gen_i_d_ + 1] == 1) {
/* SOURCE fqshrlin.for:108 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)ival(i+1) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
		feq_gen_ici_d_1.icifmt = 0;
		feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ival[feq_gen_i_d_ + 1], (ftnlen)
			sizeof(integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = e_rsli();
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
/* SOURCE fqshrlin.for:109 */
/*<       else >*/
	    } else {
/* SOURCE fqshrlin.for:110 */
/*<       write(stdout,64)cval(i+1)(1:clen(i+1)) >*/
		feq_gen_io_d__10.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__10);
		do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ + 1) * cval_len, clen[feq_gen_i_d_ + 1]);
		e_wsfe();
/* SOURCE fqshrlin.for:111 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:112 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/*           Process the hour response */
/* SOURCE fqshrlin.for:114 */
/*<       if(i+1.gt.item_knt)then >*/
	    if (feq_gen_i_d_ + 1 > *feq_gen_item_knt_d_) {
/* SOURCE fqshrlin.for:115 */
/*<       write(stdout,54)key >*/
		feq_gen_io_d__11.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__11);
		do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrlin.for:116 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:117 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:118 */
/*<       if(item_type(i+1).le.dprval)then >*/
	    if (feq_gen_item_type_d_[feq_gen_i_d_ + 1] <= 3) {
/* SOURCE fqshrlin.for:119 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)dpval(i+1) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
		feq_gen_ici_d_1.icifmt = 0;
		feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&dpval[feq_gen_i_d_ + 1], (ftnlen)
			sizeof(doublereal));
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = e_rsli();
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
/* SOURCE fqshrlin.for:120 */
/*<       else >*/
	    } else {
/* SOURCE fqshrlin.for:121 */
/*<       write(stdout,66)cval(i+1)(1:clen(i+1)) >*/
		feq_gen_io_d__12.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__12);
		do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ + 1) * cval_len, clen[feq_gen_i_d_ + 1]);
		e_wsfe();
/* SOURCE fqshrlin.for:122 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:123 */
/*<       i=i+2 >*/
	    feq_gen_i_d_ += 2;
/* SOURCE fqshrlin.for:124 */
/*<       elseif(response_type(ip).eq.multr)then >*/
	} else if (feq_gen_response_type_d_[ip] == 8) {
/*           We have one or more values with the first one possibly */
/*           an integer if there is more than one value.  All values */
/*           must be on the current line. */
/* SOURCE fqshrlin.for:128 */
/*<       if(i+1.gt.item_knt)then >*/
	    if (feq_gen_i_d_ + 1 > *feq_gen_item_knt_d_) {
/* SOURCE fqshrlin.for:129 */
/*<       write(stdout,54)key >*/
		feq_gen_io_d__13.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__13);
		do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrlin.for:130 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:131 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:132 */
/*<       if(item_type(i+1).eq.intval)then >*/
	    if (feq_gen_item_type_d_[feq_gen_i_d_ + 1] == 1) {
/* SOURCE fqshrlin.for:133 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)ival(i+1) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
		feq_gen_ici_d_1.icifmt = 0;
		feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ival[feq_gen_i_d_ + 1], (ftnlen)
			sizeof(integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = e_rsli();
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
/* SOURCE fqshrlin.for:134 */
/*<       elseif(item_type(i+1).eq.reaval)then >*/
	    } else if (feq_gen_item_type_d_[feq_gen_i_d_ + 1] == 2) {
/* SOURCE fqshrlin.for:135 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)rval(i+1) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
		feq_gen_ici_d_1.icifmt = 0;
		feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_ + 1], (ftnlen)
			sizeof(real));
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = e_rsli();
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
/* SOURCE fqshrlin.for:136 */
/*<       else >*/
	    } else {
/* SOURCE fqshrlin.for:137 */
/*<       write(stdout,68)cval(i+1)(1:clen(i+1)),key >*/
		feq_gen_io_d__14.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__14);
		do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ + 1) * cval_len, clen[feq_gen_i_d_ + 1]);
		do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrlin.for:138 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:139 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:141 */
/*<       j=2 >*/
	    j = 2;
/* SOURCE fqshrlin.for:142 */
/*<   200 continue >*/
L200:
/* SOURCE fqshrlin.for:143 */
/*<       if(i+j.gt.item_knt)then >*/
	    if (feq_gen_i_d_ + j > *feq_gen_item_knt_d_) {
/*               We are done processing the multiple response item. */
/* SOURCE fqshrlin.for:145 */
/*<       goto210 >*/
		goto L210;
/* SOURCE fqshrlin.for:146 */
/*<       elseif(item_type(i+j).le.reaval)then >*/
	    } else if (feq_gen_item_type_d_[feq_gen_i_d_ + j] <= 2) {
/*               Convert the item. */
/* SOURCE fqshrlin.for:148 */
/*<       read(cval(i+j)(1:clen(i+j)),*,err=10000)rval(i+j) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + j];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + j) * cval_len;
		feq_gen_ici_d_1.icifmt = 0;
		feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_ + j], (ftnlen)
			sizeof(real));
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
		feq_gen_i_d_1 = e_rsli();
		if (feq_gen_i_d_1 != 0) {
		    goto L10000;
		}
/* SOURCE fqshrlin.for:149 */
/*<       elseif(item_type(i+j).eq.chrval)then >*/
	    } else if (feq_gen_item_type_d_[feq_gen_i_d_ + j] == 4) {
/*               We have encountered a string- take to be end of multiple item */
/*               input. */
/* SOURCE fqshrlin.for:152 */
/*<       goto210 >*/
		goto L210;
/* SOURCE fqshrlin.for:153 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:154 */
/*<       j=j+1 >*/
	    ++j;
/* SOURCE fqshrlin.for:155 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE fqshrlin.for:156 */
/*<   210 continue >*/
L210:
/* SOURCE fqshrlin.for:157 */
/*<       i=i+j >*/
	    feq_gen_i_d_ += j;
/* SOURCE fqshrlin.for:159 */
/*<       else >*/
	} else {
/*           Check the response that follows. */
/* SOURCE fqshrlin.for:161 */
/*<       if(i+1.gt.item_knt)then >*/
	    if (feq_gen_i_d_ + 1 > *feq_gen_item_knt_d_) {
/* SOURCE fqshrlin.for:162 */
/*<       write(stdout,54)key >*/
		feq_gen_io_d__16.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__16);
		do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrlin.for:163 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:164 */
/*<       endif >*/
	    }
/*           Check for valid TYPE. */
/* SOURCE fqshrlin.for:166 */
/*<       if(convert_rule(ip).eq.exact_type)then >*/
	    if (feq_gen_convert_rule_d_[ip] == 0) {
/* SOURCE fqshrlin.for:167 */
/*<       if(item_type(i+1).ne.response_type(ip))then >*/
		if (feq_gen_item_type_d_[feq_gen_i_d_ + 1] != feq_gen_response_type_d_[ip]) {
/* SOURCE fqshrlin.for:168 */
/*<       write(stdout,52)cval(i+1)(1:clen(i+1)),key >*/
		    feq_gen_io_d__17.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__17);
		    do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ + 1) * cval_len, clen[feq_gen_i_d_ + 1]);
		    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		    e_wsfe();
/* SOURCE fqshrlin.for:169 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE fqshrlin.for:170 */
/*<       else >*/
		} else {
/*               Make sure that any character response is not */
/*               in the symbol table. */
/* SOURCE fqshrlin.for:173 */
/*<       if(response_type(ip).eq.chrval)then >*/
		    if (feq_gen_response_type_d_[ip] == 4) {
/* SOURCE fqshrlin.for:174 */
/*<       response=cval(i+1)(1:clen(i+1)) >*/
			s_copy(response, cval + (feq_gen_i_d_ + 1) * cval_len, (ftnlen)
				16, clen[feq_gen_i_d_ + 1]);
/* SOURCE fqshrlin.for:175 */
/*<       calllstab(response,symbol_table,n_symbol,ir) >*/
			lstab_(response, feq_gen_symbol_table_d_ + 16, feq_gen_n_symbol_d_, &ir,
				 (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrlin.for:178 */
/*<       if(ir.ne.0)then >*/
			if (ir != 0) {
/* SOURCE fqshrlin.for:179 */
/*<       write(stdout,52)response,key >*/
			    feq_gen_io_d__20.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__20);
			    do_fio(&feq_gen_c_d_1, response, (ftnlen)16);
			    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
			    e_wsfe();
/* SOURCE fqshrlin.for:180 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE fqshrlin.for:181 */
/*<       endif >*/
			}
/* SOURCE fqshrlin.for:182 */
/*<       endif >*/
		    }
/* SOURCE fqshrlin.for:183 */
/*<       endif >*/
		}
/* SOURCE fqshrlin.for:184 */
/*<       else >*/
	    } else {
/*             Conversion rule is to accept a lower type.  Only */
/*             numeric responses should appear here. */
/* SOURCE fqshrlin.for:187 */
/*<       if(item_type(i+1).gt.response_type(ip))then >*/
		if (feq_gen_item_type_d_[feq_gen_i_d_ + 1] > feq_gen_response_type_d_[ip]) {
/* SOURCE fqshrlin.for:188 */
/*<       write(stdout,52)cval(i+1)(1:clen(i+1)),key >*/
		    feq_gen_io_d__21.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__21);
		    do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ + 1) * cval_len, clen[feq_gen_i_d_ + 1]);
		    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		    e_wsfe();
/* SOURCE fqshrlin.for:189 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE fqshrlin.for:190 */
/*<       endif >*/
		}
/* SOURCE fqshrlin.for:191 */
/*<       endif >*/
	    }
/*           Convert using RESPONSE_TYPE(IP) as the type. */
/* SOURCE fqshrlin.for:195 */
/*<       goto(1000,2000,3000,4000),response_type(ip) >*/
	    switch (feq_gen_response_type_d_[ip]) {
		case 1:  goto L1000;
		case 2:  goto L2000;
		case 3:  goto L3000;
		case 4:  goto L4000;
	    }
/* SOURCE fqshrlin.for:196 */
/*<       write(stdout,56)response_type(ip),ip >*/
	    feq_gen_io_d__22.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__22);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_response_type_d_[ip], (ftnlen)sizeof(
		    integer));
	    do_fio(&feq_gen_c_d_1, (char *)&ip, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE fqshrlin.for:197 */
/*<       stop'Abnormal stop. Bug found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE fqshrlin.for:199 */
/*<  1000 continue >*/
L1000:
/* SOURCE fqshrlin.for:200 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)ival(i+1) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
	    feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
	    feq_gen_ici_d_1.icifmt = 0;
	    feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ival[feq_gen_i_d_ + 1], (ftnlen)
		    sizeof(integer));
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
	    feq_gen_i_d_1 = e_rsli();
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
/* SOURCE fqshrlin.for:201 */
/*<       goto9000 >*/
	    goto L9000;
/* SOURCE fqshrlin.for:202 */
/*<  2000 continue >*/
L2000:
/* SOURCE fqshrlin.for:203 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)rval(i+1) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
	    feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
	    feq_gen_ici_d_1.icifmt = 0;
	    feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_ + 1], (ftnlen)
		    sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
	    feq_gen_i_d_1 = e_rsli();
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
/* SOURCE fqshrlin.for:204 */
/*<       goto9000 >*/
	    goto L9000;
/* SOURCE fqshrlin.for:205 */
/*<  3000 continue >*/
L3000:
/* SOURCE fqshrlin.for:206 */
/*<       read(cval(i+1)(1:clen(i+1)),*,err=10000)dpval(i+1) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ + 1];
	    feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ + 1) * cval_len;
	    feq_gen_ici_d_1.icifmt = 0;
	    feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&dpval[feq_gen_i_d_ + 1], (ftnlen)
		    sizeof(doublereal));
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
	    feq_gen_i_d_1 = e_rsli();
	    if (feq_gen_i_d_1 != 0) {
		goto L10000;
	    }
/* SOURCE fqshrlin.for:207 */
/*<       goto9000 >*/
	    goto L9000;
/* SOURCE fqshrlin.for:208 */
/*<  4000 continue >*/
L4000:
/* SOURCE fqshrlin.for:209 */
/*<       goto9000 >*/
	    goto L9000;
/* SOURCE fqshrlin.for:210 */
/*<  9000 continue >*/
L9000:
/* SOURCE fqshrlin.for:212 */
/*<       i=i+2 >*/
	    feq_gen_i_d_ += 2;
/* SOURCE fqshrlin.for:213 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:214 */
/*<       endif >*/
    }
/* SOURCE fqshrlin.for:215 */
/*<       if(i.le.item_knt)goto100 >*/
    if (feq_gen_i_d_ <= *feq_gen_item_knt_d_) {
	goto L100;
    }
/* SOURCE fqshrlin.for:216 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:217 */
/*< 10000 continue >*/
L10000:
/* SOURCE fqshrlin.for:218 */
/*<       write(stdout,58)cval(i+1)(1:clen(i+1)) >*/
    feq_gen_io_d__23.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__23);
    do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ + 1) * cval_len, clen[feq_gen_i_d_ + 1]);
    e_wsfe();
/* SOURCE fqshrlin.for:219 */
/*<       stop'Abnormal stop. Bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE fqshrlin.for:221 */
/*<       end >*/
    return 0;
} /* chk_and_convert_response__ */




/* SOURCE fqshrlin.for:225 */
/*<       subroutinestaint(class,state) >*/
/* Subroutine */ int staint_(integer *feq_gen_class_d_, integer *state)
{
    /* Initialized data */

    static integer feq_gen_class_to_state_d_[18] = { 3,10,16,11,12,-1,14,15,1,13,-1,2,
	    1,1,1,1,-1,17 };

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__25 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Initialize the STATE from the CLASS of the first character */
/* SOURCE fqshrlin.for:231 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrlin.for:233 */
/*<       integerclass,state >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     CLASS  - Class for the character being processed */
/*     STATE  - Status for the scanner */
/* SOURCE fqshrlin.for:239 */
/*<        >*/
/* SOURCE fqshrlin.for:243 */
/*<        >*/
/* SOURCE fqshrlin.for:248 */
/*<       integerclass_to_state(18) >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrlin.for:256 */
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
/*     State initialization rules: */
/*     Char Class     State value assigned */
/*       period          fixed */
/*      asterisk         asteriskp */
/*      plus/minus       sign */
/*      comma            commap */
/*      slash            slashi */
/*      blank            should not appear */
/*      colon            coloni */
/*      equal            equali */
/*      underline        identifier */
/*      backslash        backslashi */
/*      quote(single)    should not appear here */
/*      digit            integer */
/*      a:c              identifier */
/*       d               identifier */
/*       e               identifier */
/*      f:z              identifier */
/*      vertical bar     should not appear but nothing makes sure it does not. */
/*      dquote           string */
/* SOURCE fqshrlin.for:250 */
/*<        >*/
/* SOURCE fqshrlin.for:280 */
/*<       state=class_to_state(class) >*/
    *state = feq_gen_class_to_state_d_[(0 + (0 + (*feq_gen_class_d_ - 1 << 2))) / 4];
/* SOURCE fqshrlin.for:281 */
/*<       if(state.le.0)then >*/
    if (*state <= 0) {
/* SOURCE fqshrlin.for:282 */
/*<       write(std6,*)' *BUG:XXX* Invalid CLASS=',class,' in STAINT.' >*/
	feq_gen_io_d__25.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__25);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* Invalid CLASS="), (ftnlen)25);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*feq_gen_class_d_), (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" in STAINT."), (ftnlen)11);
	e_wsle();
/* SOURCE fqshrlin.for:283 */
/*<       state=-1 >*/
	*state = -1;
/* SOURCE fqshrlin.for:284 */
/*<       endif >*/
    }
/* SOURCE fqshrlin.for:285 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:286 */
/*<       end >*/
} /* staint_ */




/* SOURCE fqshrlin.for:290 */
/*<        >*/
/* Subroutine */ int gitem_(char *line, logical *first, char *item, integer *
	itml, integer *itmsta, char *term, integer *terml, integer *termcls, 
	integer *eos, ftnlen line_len, ftnlen item_len, ftnlen term_len)
{
    /* Initialized data */

    static integer chrcls[256] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,6,19,18,19,19,19,19,11,19,19,2,3,4,3,1,5,12,
	    12,12,12,12,12,12,12,12,12,7,20,19,8,19,19,19,13,13,13,14,15,16,
	    16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,19,10,
	    19,19,9,0,13,13,13,14,15,16,16,16,16,16,16,16,16,16,16,16,16,16,
	    16,16,16,16,16,16,16,16,19,17,19,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    static integer action[340]	/* was [17][20] */ = { 1,4,2,2,2,2,2,2,2,2,7,
	    2,2,2,2,4,1,2,3,2,2,2,2,2,2,2,2,7,2,2,2,2,2,1,3,3,10,10,2,2,14,2,
	    2,2,7,2,2,2,2,2,1,3,3,3,2,2,3,2,2,3,3,7,2,2,2,2,2,1,1,3,2,2,2,2,2,
	    2,2,2,7,2,2,2,2,2,1,11,11,11,2,2,11,2,2,11,11,7,11,2,2,2,17,1,1,3,
	    2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,
	    2,2,2,2,2,2,2,2,2,7,12,12,2,2,12,1,1,2,2,2,2,2,2,2,2,2,7,2,2,2,2,
	    2,1,9,9,9,2,2,9,2,2,9,9,8,9,2,2,2,2,9,1,1,1,15,15,1,16,16,1,2,7,
	    12,12,2,2,6,1,1,12,2,12,2,2,12,2,2,2,7,12,12,2,2,12,1,1,13,13,12,
	    2,2,12,2,2,2,7,12,12,2,2,12,1,1,5,5,12,2,2,12,2,2,2,7,12,12,2,2,
	    12,1,1,12,2,12,2,2,12,2,2,2,7,12,12,2,2,12,1,3,2,2,2,2,2,2,2,2,2,
	    2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,17,17,17,17,17,17,
	    17,17,17,17,17,17,17,17,17,17,1,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 
	    };

    /* Format strings */
    static char fmt_50[] = "(/,\002 Found in following line:\002,/,1x,a)";
    static char fmt_52[] = "(/,\002 Invalid item or invalid sequence:\002,a)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1[2], feq_gen_i_d_2;
    char feq_gen_ch_d_1[257];

    /* Builtin functions */
    integer i_len(char *, ftnlen), s_wsfe(cilist *), do_fio(integer *, char *,
	     ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen), s_cat(char *, char **, 
	    integer *, integer *, ftnlen);

    /* Local variables */
    integer j;
    static integer l;
    integer act;
    char chr[1];
    static integer slen, next;
    integer feq_gen_class_d_;
    static char value[256];
    static integer state;
    extern /* Subroutine */ int staint_(integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Get an item from a LINE of input.  GITEM keeps track of the */
/*     call sequence and signals EOS=1 if the string has been exhausted */
/*     by the item returned. */

/* SOURCE fqshrlin.for:300 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrlin.for:302 */
/*<       integereos,itmsta,itml,terml,termcls >*/
/* SOURCE fqshrlin.for:303 */
/*<       characteritem*(*),line*(*),term*(*) >*/
/* SOURCE fqshrlin.for:304 */
/*<       logicalfirst >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     LINE   - Character string to be processed */
/*     FIRST  - Flag for first call to GITEM */
/*     ITEM   - Value of the next item in the search string */
/*     ITML   - Number of characters in the item found */
/*     ITMSTA   - State for the item found */
/*     EOS    - End of string flag */
/*     TERM   - string value of terminating entity */
/*     TERML  - number of characters in the terminating entity */
/*     TERMCLS - character-class number for the terminator */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrlin.for:318 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrlin.for:321 */
/*<       integeraction(17,20),chrcls(0:255),l,next,slen,state >*/
/* SOURCE fqshrlin.for:322 */
/*<       charactervalue*256 >*/
/* SOURCE fqshrlin.for:323 */
/*<       saveaction,chrcls,l,next,slen,state,value >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrlin.for:326 */
/*<       integeract,class,i,j >*/
/* SOURCE fqshrlin.for:327 */
/*<       characterchr*1 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrlin.for:330 */
/*<       intrinsicichar,len >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrlin.for:333 */
/*<       externalstaint >*/
/*     This is the action matrix in two forms: labeled for a human reader */
/*     and in data input form for a computer reader. */
/*                 Class of the next character: */
/*                    1        2       3      4     5      6     7     8    9     10    11    12   13  14  15 
  16  17   18    19   20 */
/*    Current       period asterisk  plus  comma  slash blank colon equal under back  sngle digit a:c   d   e 
 f:z vert dble  misc semi */
/*     State                         minus                                line  slash quote                   
     bar  quote char coln */
/*  --------        ------ -------- ------ ----- ------ ----- ----- ----- ----- ----- ----- ----- --- --- --- 
---- ---- ----- ---- ---- */
/*  1  identifier      1      2        3     3      1    11     1     3     1     1     9     1    1    1   1 
  1   3     2    17    3 */
/*  2  integer         4      3        3     3      3    11     3     2     2     2     9     1   12   13   5 
 12   2     2    17    3 */
/*  3  fixed           2      2       10     3      2    11     2     2     2     2     9     1    2   13   5 
  2   2     2    17    2 */
/*  4  single1         2      2       10     2      2     2     2     2     2     2     2    15   12   12  12 
 12   2     2    17    2 */
/*  5  single2         2      2        2     2      2     2     2     2     2     2     2    15    2    2   2 
  2   2     2    17    2 */
/*  6  single3         2      2        2     3      2    11     2     2     2     2     9     1    2    2   2 
  2   2     2    17    2 */
/*  7  double1         2      2       14     2      2     2     2     2     2     2     2    16   12   12  12 
 12   2     2    17    2 */
/*  8  double2         2      2        2     2      2     2     2     2     2     2     2    16    2    2   2 
  2   2     2    17    2 */
/*  9  double3         2      2        2     3      2    11     2     2     2     2     9     1    2    2   2 
  2   2     2    17    2 */
/* 10  asteriskp       2      2        2     3      2    11     2     2     2     2     9     2    2    2   2 
  2   2     2    17    2 */
/* 11  commap          7      7        7     7      7     7     2     2     7     7     8     7    7    7   7 
  7   2     2    17    2 */
/* 12  slashi          2      2        2     2      2    11     2     2    12     2     9    12   12   12  12 
 12   2     2    17    2 */
/* 13  backslashi      2      2        2     2      2     2     2     2    12     2     2    12   12   12  12 
 12   2     2    17    2 */
/* 14  coloni          2      2        2     2      2     2     2     2     2     2     2     2    2    2   2 
  2   2     2    17    2 */
/* 15  equali          2      2        2     2      2     2     2     2     2     2     2     2    2    2   2 
  2   2     2    17    2 */
/* 16  sign            4      2        2     2      2    17     2     2    12     2     2     6   12   12  12 
 12   2     2    17    2 */
/* 17  string          1      1        1     1      1     1     1     1     1     1     9     1    1    1   1 
  1   1     3     1    1 */
/*     Summary statement of each action. */
/*     Action#   Description */
/*        1      add a character to the current item */
/*        2      error condition-invalid sequence of characters */
/*        3      Terminate and return the current item. */
/*        4      Add character to the current item and change state to a fixed point number. */
/*        5      Add char to current item and change state to single1 item. */
/*        6      Add char to current item and change state to integer */
/*        7      Terminate and return an asteriskp with comma as terminater */
/*        8      Terminate and return an asteriskp with quote as terminater- end of line */
/*        9      End of input line.  Return the item and set the end of string flag. */
/*       10      Add char to item and change the state to single2. */
/*       11      Find next non-blank, reset terminator as needed, and return. */
/*       12      Add to current item and change state to identifier */
/*       13      Add char to current item and change state to double1 item. */
/*       14      Add char to current item and change state to double2 */
/*       15      Add char to current item and change state to single3 */
/*       16      Add char to current item and change state to double3 */
/*       17      Ignore char and look for next char. */
/*     State initialization rules: */
/*     Char Class     State value assigned */
/*       period          fixed */
/*      asterisk         asteriskp          asterisk as a place holder */
/*      plus/minus       integer */
/*      comma            commap             comma as a place holder */
/*      slash            slashi */
/*      blank            skip to non-blank and try again */
/*      colon            coloni */
/*      equal            error */
/*      underline        identifier */
/*      backslash        backslashi */
/*      quote            end of line */
/*      digit            integer */
/*      a:c              identifier */
/*       d               identifier */
/*       e               identifier */
/*      f:z              identifier */
/*      dquote           string */

/*      Note: comma and asterisk can be terminators but in that role they */
/*            will never be the first item.  An asterisk is taken as a */
/*            terminator whenever it appears at the end of another item */
/*            with no intervening spaces.  A comma is a place holder if */
/*            it is found as the first character after another item has */
/*            been completed.  Also a detected comma place holder is */
/*            returned as an asterisk place holder with a terminating */
/*            comma.  Thus COMMAP will not be seen as an item state */
/*            outside GITEM and STAINT. */
/* SOURCE fqshrlin.for:415 */
/*<        >*/
/* SOURCE fqshrlin.for:421 */
/*<        >*/
/* SOURCE fqshrlin.for:427 */
/*<        >*/
/*     Set the class for each of the 256 characters that might be seen in */
/*     a string.  Assumes the ASCII sequence!  This will not work with */
/*     EBCIDC.  Characters that are skipped(ignored) are given the class */
/*     of zero. */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrlin.for:437 */
/*<        >*/
/* SOURCE fqshrlin.for:444 */
/*<        >*/
/* SOURCE fqshrlin.for:464 */
/*<    50 format(/,' Found in following line:',/,1x,a) >*/
/* L50: */
/* SOURCE fqshrlin.for:465 */
/*<    52 format(/,' Invalid item or invalid sequence:',a) >*/
/* L52: */
/* *********************************************************************** */
/* SOURCE fqshrlin.for:467 */
/*<       if(first)then >*/
    if (*first) {
/*       THIS IS THE FIRST CALL FOR LINE */
/* SOURCE fqshrlin.for:469 */
/*<       first=.false. >*/
	*first = FALSE_;
/*       CLEAR THE LOCAL ITEM LENGTH */
/* SOURCE fqshrlin.for:472 */
/*<       l=0 >*/
	l = 0;
/*       CLEAR THE END OF STRING FLAG */
/* SOURCE fqshrlin.for:474 */
/*<       eos=0 >*/
	*eos = 0;
/*       GET THE LENGTH OF THE CURRENT STRING */
/* SOURCE fqshrlin.for:476 */
/*<       slen=len(line) >*/
	slen = i_len(line, line_len);
/* SOURCE fqshrlin.for:477 */
/*<       next=1 >*/
	next = 1;
/* SOURCE fqshrlin.for:478 */
/*<       endif >*/
    }
/* SOURCE fqshrlin.for:480 */
/*<  6000 continue >*/
L6000:
/* SOURCE fqshrlin.for:481 */
/*<       chr=line(next:next) >*/
    *(unsigned char *)chr = *(unsigned char *)&line[next - 1];
/* SOURCE fqshrlin.for:482 */
/*<       class=chrcls(ichar(chr)) >*/
    feq_gen_class_d_ = chrcls[*(unsigned char *)chr];
/*       Skip spaces and any non-printing characaters as well as */
/*       characters ignored. Characters of class MISC are skipped */
/*       until a double quote starts a string. */
/* SOURCE fqshrlin.for:487 */
/*<       if(class.eq.0.or.class.eq.space.or.class.eq.misc)then >*/
    if (feq_gen_class_d_ == 0 || feq_gen_class_d_ == 6 || feq_gen_class_d_ == 19) {
/* SOURCE fqshrlin.for:488 */
/*<       next=next+1 >*/
	++next;
/* SOURCE fqshrlin.for:489 */
/*<       goto6000 >*/
	goto L6000;
/* SOURCE fqshrlin.for:490 */
/*<       endif >*/
    }
/* SOURCE fqshrlin.for:491 */
/*<       l=1 >*/
    l = 1;
/* SOURCE fqshrlin.for:492 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:494 */
/*<       if(class.ne.quote)then >*/
    if (feq_gen_class_d_ != 11) {
/* SOURCE fqshrlin.for:495 */
/*<       callstaint(class,state) >*/
	staint_(&feq_gen_class_d_, &state);
/* SOURCE fqshrlin.for:497 */
/*<       if(state.lt.0)then >*/
	if (state < 0) {
/* SOURCE fqshrlin.for:498 */
/*<       write(std6,52)chr >*/
	    feq_gen_io_d__35.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__35);
	    do_fio(&feq_gen_c_d_1, chr, (ftnlen)1);
	    e_wsfe();
/* SOURCE fqshrlin.for:499 */
/*<       write(std6,50)line >*/
	    feq_gen_io_d__36.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__36);
	    do_fio(&feq_gen_c_d_1, line, line_len);
	    e_wsfe();
/* SOURCE fqshrlin.for:501 */
/*<       eos=1 >*/
	    *eos = 1;
/* SOURCE fqshrlin.for:502 */
/*<       item=' ' >*/
	    s_copy(item, const_cast<char*>(" "), item_len, (ftnlen)1);
/* SOURCE fqshrlin.for:503 */
/*<       itml=0 >*/
	    *itml = 0;
/* SOURCE fqshrlin.for:504 */
/*<       itmsta=state >*/
	    *itmsta = state;
/* SOURCE fqshrlin.for:505 */
/*<       term=' ' >*/
	    s_copy(term, const_cast<char*>(" "), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:506 */
/*<       terml=0 >*/
	    *terml = 0;
/* SOURCE fqshrlin.for:507 */
/*<       termcls=-1 >*/
	    *termcls = -1;
/* SOURCE fqshrlin.for:508 */
/*<       first=.true. >*/
	    *first = TRUE_;
/* SOURCE fqshrlin.for:509 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrlin.for:510 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:511 */
/*<       next=next+1 >*/
	++next;
/* SOURCE fqshrlin.for:512 */
/*<       else >*/
    } else {
/*       The quote was found as the first character. */
/*       Signal end of string with no item to process. */
/* SOURCE fqshrlin.for:515 */
/*<       itml=0 >*/
	*itml = 0;
/* SOURCE fqshrlin.for:516 */
/*<       eos=1 >*/
	*eos = 1;
/* SOURCE fqshrlin.for:517 */
/*<       first=.true. >*/
	*first = TRUE_;
/* SOURCE fqshrlin.for:518 */
/*<       termcls=quote >*/
	*termcls = 11;
/* SOURCE fqshrlin.for:519 */
/*<       terml=1 >*/
	*terml = 1;
/* SOURCE fqshrlin.for:520 */
/*<       return >*/
	return 0;
/* SOURCE fqshrlin.for:521 */
/*<       endif >*/
    }
/*     GET THE NEXT CHARACTER AND PROCESS. */
/* SOURCE fqshrlin.for:525 */
/*<  9000 continue >*/
L9000:
/* SOURCE fqshrlin.for:526 */
/*<       chr=line(next:next) >*/
    *(unsigned char *)chr = *(unsigned char *)&line[next - 1];
/* SOURCE fqshrlin.for:527 */
/*<       class=chrcls(ichar(chr)) >*/
    feq_gen_class_d_ = chrcls[*(unsigned char *)chr];
/* SOURCE fqshrlin.for:528 */
/*<       if(class.eq.0)then >*/
    if (feq_gen_class_d_ == 0) {
/* SOURCE fqshrlin.for:529 */
/*<       next=next+1 >*/
	++next;
/* SOURCE fqshrlin.for:530 */
/*<       goto9000 >*/
	goto L9000;
/* SOURCE fqshrlin.for:531 */
/*<       endif >*/
    }
/*        WRITE(STD6,*) ' CHR=',CHR,' ICHAR=',ICHAR(CHR) */
/*       NOW SELECT THE NEXT ACTION USING THE MATRIX, STATE, AND */
/*       CLASS */
/* SOURCE fqshrlin.for:538 */
/*<       act=action(state,class) >*/
    act = action[state + feq_gen_class_d_ * 17 - 18];
/*        WRITE(STD6,*) ' STATE=',STATE,' CLASS=',CLASS,' ACT=',ACT */
/* SOURCE fqshrlin.for:541 */
/*<        >*/
    switch (act) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
	case 10:  goto L1000;
	case 11:  goto L1100;
	case 12:  goto L1200;
	case 13:  goto L1300;
	case 14:  goto L1400;
	case 15:  goto L1500;
	case 16:  goto L1600;
	case 17:  goto L1700;
    }
/* SOURCE fqshrlin.for:544 */
/*<       write(std6,*)' BUG: INVALID INDEX FOR COMP. GOTO.' >*/
    feq_gen_io_d__38.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsle(&feq_gen_io_d__38);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG: INVALID INDEX FOR COMP. GOTO."), (ftnlen)35);
    e_wsle();
/* SOURCE fqshrlin.for:545 */
/*<       write(std6,*)' IN SUB. GITEM. INDEX=',act >*/
    feq_gen_io_d__39.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsle(&feq_gen_io_d__39);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN SUB. GITEM. INDEX="), (ftnlen)22);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&act, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE fqshrlin.for:546 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:548 */
/*<   100 continue >*/
L100:
/*           Add a character to the current item */
/* SOURCE fqshrlin.for:550 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:551 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:552 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:554 */
/*<   200 continue >*/
L200:
/*           Error condition */
/* SOURCE fqshrlin.for:557 */
/*<       write(std6,52)value(1:l)//chr >*/
    feq_gen_io_d__40.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__40);
/* Writing concatenation */
    feq_gen_i_d_1[0] = l, feq_gen_a_d_1[0] = value;
    feq_gen_i_d_1[1] = 1, feq_gen_a_d_1[1] = chr;
    s_cat(feq_gen_ch_d_1, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_2, (ftnlen)257);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, l + 1);
    e_wsfe();
/* SOURCE fqshrlin.for:558 */
/*<       write(std6,50)line >*/
    feq_gen_io_d__41.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__41);
    do_fio(&feq_gen_c_d_1, line, line_len);
    e_wsfe();
/* SOURCE fqshrlin.for:560 */
/*<       eos=1 >*/
    *eos = 1;
/* SOURCE fqshrlin.for:561 */
/*<       item=' ' >*/
    s_copy(item, const_cast<char*>(" "), item_len, (ftnlen)1);
/* SOURCE fqshrlin.for:562 */
/*<       itml=0 >*/
    *itml = 0;
/* SOURCE fqshrlin.for:563 */
/*<       itmsta=state >*/
    *itmsta = state;
/* SOURCE fqshrlin.for:564 */
/*<       term=' ' >*/
    s_copy(term, const_cast<char*>(" "), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:565 */
/*<       terml=0 >*/
    *terml = 0;
/* SOURCE fqshrlin.for:566 */
/*<       termcls=-1 >*/
    *termcls = -1;
/* SOURCE fqshrlin.for:567 */
/*<       first=.true. >*/
    *first = TRUE_;
/* SOURCE fqshrlin.for:568 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:570 */
/*<   300 continue >*/
L300:
/*           Terminate and return the current item */
/* SOURCE fqshrlin.for:573 */
/*<       item=value(1:l) >*/
    s_copy(item, value, item_len, l);
/* SOURCE fqshrlin.for:574 */
/*<       itml=l >*/
    *itml = l;
/* SOURCE fqshrlin.for:575 */
/*<       itmsta=state >*/
    *itmsta = state;
/* SOURCE fqshrlin.for:577 */
/*<       term=chr >*/
    s_copy(term, chr, term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:578 */
/*<       terml=1 >*/
    *terml = 1;
/* SOURCE fqshrlin.for:579 */
/*<       termcls=class >*/
    *termcls = feq_gen_class_d_;
/* SOURCE fqshrlin.for:581 */
/*<       next=next+1 >*/
    ++next;
/* SOURCE fqshrlin.for:582 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:584 */
/*<   400 continue >*/
L400:
/*           Add character to the current item and change state to */
/*           a fixed point number */
/* SOURCE fqshrlin.for:587 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:588 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:589 */
/*<       state=fixed >*/
    state = 3;
/* SOURCE fqshrlin.for:590 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:592 */
/*<   500 continue >*/
L500:
/*           Add char to current item and change state to SINGLE1 */
/* SOURCE fqshrlin.for:594 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:595 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:596 */
/*<       state=single1 >*/
    state = 4;
/* SOURCE fqshrlin.for:597 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:599 */
/*<   600 continue >*/
L600:
/*           Add char to current item and change state to INTEGER */
/* SOURCE fqshrlin.for:601 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:602 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:603 */
/*<       state=integer >*/
    state = 2;
/* SOURCE fqshrlin.for:604 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:607 */
/*<   700 continue >*/
L700:
/*           Terminate and return an asteriskp with comma as terminater */
/* SOURCE fqshrlin.for:609 */
/*<       item='*' >*/
    s_copy(item, const_cast<char*>("*"), item_len, (ftnlen)1);
/* SOURCE fqshrlin.for:610 */
/*<       itml=1 >*/
    *itml = 1;
/* SOURCE fqshrlin.for:611 */
/*<       itmsta=asteriskp >*/
    *itmsta = 10;
/* SOURCE fqshrlin.for:613 */
/*<       term=',' >*/
    s_copy(term, const_cast<char*>(","), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:614 */
/*<       terml=1 >*/
    *terml = 1;
/* SOURCE fqshrlin.for:615 */
/*<       termcls=comma >*/
    *termcls = 4;
/*           Do not increment NEXT because the char at NEXT must be */
/*           used for the next item. */
/*            NEXT = NEXT + 1 */
/* SOURCE fqshrlin.for:620 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:622 */
/*<   800 continue >*/
L800:
/*           Terminate and return an asteriskp with quote as terminater- */
/*           end of line */
/* SOURCE fqshrlin.for:625 */
/*<       item='*' >*/
    s_copy(item, const_cast<char*>("*"), item_len, (ftnlen)1);
/* SOURCE fqshrlin.for:626 */
/*<       itml=1 >*/
    *itml = 1;
/* SOURCE fqshrlin.for:627 */
/*<       itmsta=asteriskp >*/
    *itmsta = 10;
/* SOURCE fqshrlin.for:629 */
/*<       term='''' >*/
    s_copy(term, const_cast<char*>("'"), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:630 */
/*<       terml=1 >*/
    *terml = 1;
/* SOURCE fqshrlin.for:631 */
/*<       termcls=quote >*/
    *termcls = 11;
/* SOURCE fqshrlin.for:633 */
/*<       eos=1 >*/
    *eos = 1;
/* SOURCE fqshrlin.for:634 */
/*<       first=.true. >*/
    *first = TRUE_;
/* SOURCE fqshrlin.for:635 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:637 */
/*<   900 continue >*/
L900:
/*           End of input line.  Return the item and set the end of */
/*           string flag. */
/* SOURCE fqshrlin.for:640 */
/*<       item=value(1:l) >*/
    s_copy(item, value, item_len, l);
/* SOURCE fqshrlin.for:641 */
/*<       itml=l >*/
    *itml = l;
/* SOURCE fqshrlin.for:642 */
/*<       itmsta=state >*/
    *itmsta = state;
/* SOURCE fqshrlin.for:643 */
/*<       term='''' >*/
    s_copy(term, const_cast<char*>("'"), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:644 */
/*<       terml=1 >*/
    *terml = 1;
/* SOURCE fqshrlin.for:645 */
/*<       termcls=quote >*/
    *termcls = 11;
/* SOURCE fqshrlin.for:646 */
/*<       eos=1 >*/
    *eos = 1;
/* SOURCE fqshrlin.for:647 */
/*<       first=.true. >*/
    *first = TRUE_;
/* SOURCE fqshrlin.for:648 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:650 */
/*<  1000 continue >*/
L1000:
/*           Add char to item and change the state to single2. */
/* SOURCE fqshrlin.for:652 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:653 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:654 */
/*<       state=single2 >*/
    state = 5;
/* SOURCE fqshrlin.for:655 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:657 */
/*<  1100 continue >*/
L1100:
/*           Find next non-blank and reset terminator as needed. */
/*           Must set terminater to the correct value.  May not be */
/*           a blank.  The following values could be the terminater */
/*           with one or more blanks between it and the current value: */
/*            comma, equal, quote, semi-colon */
/* SOURCE fqshrlin.for:664 */
/*<       item=value(1:l) >*/
    s_copy(item, value, item_len, l);
/* SOURCE fqshrlin.for:665 */
/*<       itml=l >*/
    *itml = l;
/* SOURCE fqshrlin.for:666 */
/*<       itmsta=state >*/
    *itmsta = state;
/*           Chr contains a blank.  NEXT points at its location. */
/*           Search ahead for the next non-blank or end of string. */
/* SOURCE fqshrlin.for:672 */
/*<       do1101j=next+1,slen >*/
    feq_gen_i_d_2 = slen;
    for (j = next + 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE fqshrlin.for:673 */
/*<       chr=line(j:j) >*/
	*(unsigned char *)chr = *(unsigned char *)&line[j - 1];
/* SOURCE fqshrlin.for:674 */
/*<       class=chrcls(ichar(chr)) >*/
	feq_gen_class_d_ = chrcls[*(unsigned char *)chr];
/* SOURCE fqshrlin.for:675 */
/*<       if(class.ne.space)then >*/
	if (feq_gen_class_d_ != 6) {
/* SOURCE fqshrlin.for:676 */
/*<       if(class.eq.comma)then >*/
	    if (feq_gen_class_d_ == 4) {
/*                 Found a comma. Adjust the pointer to use */
/*                 it as the terminater instead of the space. */
/* SOURCE fqshrlin.for:679 */
/*<       term=',' >*/
		s_copy(term, const_cast<char*>(","), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:680 */
/*<       termcls=comma >*/
		*termcls = 4;
/* SOURCE fqshrlin.for:681 */
/*<       next=j+1 >*/
		next = j + 1;
/* SOURCE fqshrlin.for:682 */
/*<       elseif(class.eq.semicolon)then >*/
	    } else if (feq_gen_class_d_ == 20) {
/* SOURCE fqshrlin.for:683 */
/*<       term=';' >*/
		s_copy(term, const_cast<char*>(";"), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:684 */
/*<       termcls=semicolon >*/
		*termcls = 20;
/* SOURCE fqshrlin.for:685 */
/*<       next=j+1 >*/
		next = j + 1;
/* SOURCE fqshrlin.for:686 */
/*<       elseif(class.eq.equal)then >*/
	    } else if (feq_gen_class_d_ == 8) {
/* SOURCE fqshrlin.for:687 */
/*<       term='=' >*/
		s_copy(term, const_cast<char*>("="), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:688 */
/*<       termcls=equal >*/
		*termcls = 8;
/* SOURCE fqshrlin.for:689 */
/*<       next=j+1 >*/
		next = j + 1;
/* SOURCE fqshrlin.for:690 */
/*<       elseif(class.eq.quote)then >*/
	    } else if (feq_gen_class_d_ == 11) {
/*                 This is the end of the line.  The quote has */
/*                 terminated the last item and also signaled the */
/*                 end of line. */
/* SOURCE fqshrlin.for:694 */
/*<       term='''' >*/
		s_copy(term, const_cast<char*>("'"), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:695 */
/*<       termcls=quote >*/
		*termcls = 11;
/* SOURCE fqshrlin.for:696 */
/*<       next=j+1 >*/
		next = j + 1;
/* SOURCE fqshrlin.for:697 */
/*<       eos=1 >*/
		*eos = 1;
/* SOURCE fqshrlin.for:698 */
/*<       first=.true. >*/
		*first = TRUE_;
/* SOURCE fqshrlin.for:699 */
/*<       else >*/
	    } else {
/*                 The blank is the terminater. */
/* SOURCE fqshrlin.for:701 */
/*<       term=' ' >*/
		s_copy(term, const_cast<char*>(" "), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:702 */
/*<       termcls=space >*/
		*termcls = 6;
/* SOURCE fqshrlin.for:703 */
/*<       next=j >*/
		next = j;
/* SOURCE fqshrlin.for:704 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:705 */
/*<       terml=1 >*/
	    *terml = 1;
/* SOURCE fqshrlin.for:706 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrlin.for:707 */
/*<       else >*/
	} else {
/* SOURCE fqshrlin.for:709 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:710 */
/*<  1101 continue >*/
/* L1101: */
    }
/*           DROP THROUGH MEANS NO NON-SPACE FOUND UNTIL END OF LINE */
/*           SIMULATE WITH A COMMA ALSO */
/* SOURCE fqshrlin.for:713 */
/*<       next=slen+1 >*/
    next = slen + 1;
/* SOURCE fqshrlin.for:714 */
/*<       term=' ' >*/
    s_copy(term, const_cast<char*>(" "), term_len, (ftnlen)1);
/* SOURCE fqshrlin.for:715 */
/*<       terml=1 >*/
    *terml = 1;
/* SOURCE fqshrlin.for:716 */
/*<       termcls=space >*/
    *termcls = 6;
/* SOURCE fqshrlin.for:717 */
/*<       eos=1 >*/
    *eos = 1;
/* SOURCE fqshrlin.for:718 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:721 */
/*<  1200 continue >*/
L1200:
/*           Add to current item and change state to identifier */
/* SOURCE fqshrlin.for:723 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:724 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:725 */
/*<       state=identifier >*/
    state = 1;
/* SOURCE fqshrlin.for:726 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:728 */
/*<  1300 continue >*/
L1300:
/*           Add char to current item and change state to double1. */
/* SOURCE fqshrlin.for:730 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:731 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:732 */
/*<       state=double1 >*/
    state = 7;
/* SOURCE fqshrlin.for:733 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:735 */
/*<  1400 continue >*/
L1400:
/*           Add char to current item and change state to double2 */
/* SOURCE fqshrlin.for:737 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:738 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:739 */
/*<       state=double2 >*/
    state = 8;
/* SOURCE fqshrlin.for:740 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:742 */
/*<  1500 continue >*/
L1500:
/*           Add char to current item and change state to single3 */
/* SOURCE fqshrlin.for:744 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:745 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:746 */
/*<       state=single3 >*/
    state = 6;
/* SOURCE fqshrlin.for:747 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:749 */
/*<  1600 continue >*/
L1600:
/*           Add char to current item and change state to double3 */
/* SOURCE fqshrlin.for:751 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE fqshrlin.for:752 */
/*<       value(l:l)=chr >*/
    *(unsigned char *)&value[l - 1] = *(unsigned char *)chr;
/* SOURCE fqshrlin.for:753 */
/*<       state=double3 >*/
    state = 9;
/* SOURCE fqshrlin.for:755 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:757 */
/*<  1700 continue >*/
L1700:
/*           Ignore char and return for the next one */
/* SOURCE fqshrlin.for:759 */
/*<       goto8900 >*/
    goto L8900;
/* SOURCE fqshrlin.for:761 */
/*<  8900 continue >*/
L8900:
/* SOURCE fqshrlin.for:763 */
/*<       next=next+1 >*/
    ++next;
/* SOURCE fqshrlin.for:764 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE fqshrlin.for:766 */
/*<       end >*/
} /* gitem_ */




/* SOURCE fqshrlin.for:770 */
/*<        >*/
/* Subroutine */ int getval_(integer *stderr, char *line, integer *nval, 
	integer *opt, integer *feq_gen_feq_storage_item_type_d_, integer *feq_storage_ival, real *feq_storage_rval, 
	doublereal *feq_storage_dpval, char *feq_storage_cval, integer *feq_storage_clen, integer *eflag, char *
	feq_storage_term, integer *feq_storage_terml, integer *feq_storage_termcls, integer *mval, ftnlen 
	line_len, ftnlen cval_len, ftnlen term_len)
{
    /* Initialized data */

    static integer deftyp[17] = { 4,1,2,-1,-1,2,-1,-1,3,6,-2,5,-2,-2,-2,-1,4 }
	    ;

    /* Format strings */
    static char fmt_50[] = "(/,\002*ERR:552* Found at least\002,i5,\002 item\
s. Expected no more\002,\002 than\002,i5)";
    static char fmt_51[] = "(/,\002*BUG:XXX* Invalid type=\002,i5,\002 found\
 in GETVAL.\002)";
    static char fmt_52[] = "(/,\002*ERR:553* Expected an integer number but \
found \002,a20,\002 instead.\002)";
    static char fmt_53[] = "(/,\002*ERR:554* Expected a number but found \
\002,a20,\002 instead.\002)";
    static char fmt_54[] = "(/,\002*WRN:555* Expected an identifier but foun\
d \002,a20,\002 instead.\002)";
    static char fmt_56[] = "(/,\002 Offending line:\002,a)";
    static char fmt_58[] = "(/,\002*BUG:XXX* Invalid numeric field in GETV\
AL:\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_rsfi(icilist *), e_rsfi();

    /* Local variables */
    integer eos;
    char trm[1], item[256];
    integer itml, trml;
    extern /* Subroutine */ int gitem_(char *, logical *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    logical first;
    integer itmsta, trmcls;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__55 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__56 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_58, 0 };


/* SOURCE fqshrlin.for:775 */
/*<       implicitnone >*/
/*     + + + PURPOSE + + + */
/*     Get values from LINE and store them in the appropriate element */
/*     of the vector(IVAL, RVAL, DPVAL, or CVAL) of the proper type. */
/*     Report errors in type that prevent proper conversions.  Report */
/*     excess values. */
/*     STDERR- unit number for output of errors and messages. */
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
/*        MVAL- the number of values actually found. A value may be null or */
/*             defaulted and it is still counted. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrlin.for:814 */
/*<       integereflag,mval,nval,opt,stderr >*/
/* SOURCE fqshrlin.for:815 */
/*<        >*/
/* SOURCE fqshrlin.for:817 */
/*<       realrval(nval) >*/
/* SOURCE fqshrlin.for:818 */
/*<       real*8dpval(nval) >*/
/* SOURCE fqshrlin.for:819 */
/*<       charactercval(nval)*(*),line*(*),term(nval)*1 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDERR - Fortran unit number for output of error messages */
/*     LINE   - Character string to be processed */
/*     NVAL   - Number of items expected in the string */
/*     OPT    - If OPT=0 then number and type of items are known else */
/*               if OPT=1 then number and type are unknown */
/*     ITEM_TYPE   - Type of item: real, integer, char, double precision */
/*     IVAL   - Contains integer value for an integer item */
/*     RVAL   - Return value for a real item */
/*     DPVAL  - Return for a double precision value */
/*     CVAL   - Contains character string returned for a string value */
/*     CLEN   - Vector giving the length of the character string if the */
/*               value is of type CHARACTER */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     MVAL   - Number of item found in the string */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE fqshrlin.for:838 */
/*<       integerchrval,continuation_value,intval,reaval,dprval,place_holder >*/
/* SOURCE fqshrlin.for:840 */
/*<        >*/
/* SOURCE fqshrlin.for:843 */
/*<        >*/
/* SOURCE fqshrlin.for:846 */
/*<        >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrlin.for:851 */
/*<       integerdeftyp(17) >*/
/* SOURCE fqshrlin.for:852 */
/*<       savedeftyp >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrlin.for:855 */
/*<       integereos,itmsta,itml,trml,trmcls >*/
/* SOURCE fqshrlin.for:856 */
/*<       characteritem*256,trm*1 >*/
/* SOURCE fqshrlin.for:857 */
/*<       logicalfirst >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrlin.for:860 */
/*<       externalgitem >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*      1  identifier */
/*      2  integer         Gives the offset number for the state */
/*      3  fixed           number of the item. */
/*      4  single1 */
/*      5  single2 */
/*      6  single3 */
/*      7  double1         Negative values in DEFTYP denote items */
/*      8  double2         that should not be seen. -1: never to be */
/*      9  double3         seen; -2:might be some reason to see them */
/*     10  asteriskp       in the future. */
/*     11  commap */
/*     12  slashi */
/*     13  backslashi */
/*     14  coloni */
/*     15  equali */
/*     16  sign */
/*     17  string */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrlin.for:880 */
/*<        >*/
    /* Parameter adjustments */
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
/* SOURCE fqshrlin.for:885 */
/*<    50  >*/
/* L50: */
/* SOURCE fqshrlin.for:887 */
/*<    51 format(/,'*BUG:XXX* Invalid type=',i5,' found in GETVAL.') >*/
/* L51: */
/* SOURCE fqshrlin.for:888 */
/*<    52  >*/
/* L52: */
/* SOURCE fqshrlin.for:890 */
/*<    53 format(/,'*ERR:554* Expected a number but found ',a20,' instead.') >*/
/* L53: */
/* SOURCE fqshrlin.for:891 */
/*<    54  >*/
/* L54: */
/* SOURCE fqshrlin.for:893 */
/*<    56 format(/,' Offending line:',a) >*/
/* L56: */
/* SOURCE fqshrlin.for:894 */
/*<    58 format(/,'*BUG:XXX* Invalid numeric field in GETVAL:',a) >*/
/* L58: */
/* *********************************************************************** */
/*     CLEAR THE COUNTER FOR VALUES FOUND */
/* SOURCE fqshrlin.for:898 */
/*<       mval=0 >*/
    *mval = 0;
/*     SET THE FIRST CALL TO TRUE */
/* SOURCE fqshrlin.for:902 */
/*<       first=.true. >*/
    first = TRUE_;
/*     SEEK SUCCESSIVE ITEMS FROM LINE AND TAKE THE REQUIRED ACTION. */
/* SOURCE fqshrlin.for:906 */
/*< 99999 continue >*/
L99999:
/* SOURCE fqshrlin.for:907 */
/*<       callgitem(line,first,item,itml,itmsta,trm,trml,trmcls,eos) >*/
    gitem_(line, &first, item, &itml, &itmsta, trm, &trml, &trmcls, &eos, 
	    line_len, (ftnlen)256, (ftnlen)1);
/* SOURCE fqshrlin.for:912 */
/*<       if(trmcls.eq.-1)eflag=1 >*/
    if (trmcls == -1) {
	*eflag = 1;
    }
/* SOURCE fqshrlin.for:913 */
/*<       if(eos.eq.1.and.itml.eq.0)then >*/
    if (eos == 1 && itml == 0) {
/*         END OF LINE FOUND. */
/* SOURCE fqshrlin.for:916 */
/*<       return >*/
	return 0;
/* SOURCE fqshrlin.for:917 */
/*<       else >*/
    } else {
/*         PROCESS A VALUE. */
/* SOURCE fqshrlin.for:919 */
/*<       mval=mval+1 >*/
	++(*mval);
/* SOURCE fqshrlin.for:920 */
/*<       if(mval.gt.nval)then >*/
	if (*mval > *nval) {
/* SOURCE fqshrlin.for:921 */
/*<       write(stderr,50)mval,nval >*/
	    feq_gen_io_d__52.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__52);
	    do_fio(&feq_gen_c_d_1, (char *)&(*mval), (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&(*nval), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE fqshrlin.for:922 */
/*<       mval=mval-1 >*/
	    --(*mval);
/* SOURCE fqshrlin.for:923 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrlin.for:924 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrlin.for:925 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:926 */
/*<       if(opt.eq.1.or.opt.eq.2)then >*/
	if (*opt == 1 || *opt == 2) {
/* SOURCE fqshrlin.for:927 */
/*<       item_type(mval)=deftyp(itmsta) >*/
	    feq_gen_item_type_d_[*mval] = deftyp[itmsta - 1];
/* SOURCE fqshrlin.for:928 */
/*<       cval(mval)=item >*/
	    s_copy(cval + *mval * cval_len, item, cval_len, (ftnlen)256);
/* SOURCE fqshrlin.for:929 */
/*<       clen(mval)=itml >*/
	    clen[*mval] = itml;
/* SOURCE fqshrlin.for:930 */
/*<       term(mval)=trm >*/
	    *(unsigned char *)&term[*mval] = *(unsigned char *)trm;
/* SOURCE fqshrlin.for:931 */
/*<       terml(mval)=trml >*/
	    terml[*mval] = trml;
/* SOURCE fqshrlin.for:932 */
/*<       termcls(mval)=trmcls >*/
	    termcls[*mval] = trmcls;
/* SOURCE fqshrlin.for:933 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:935 */
/*<       if(opt.eq.1)goto70000 >*/
	if (*opt == 1) {
	    goto L70000;
	}
/*         If the item type is ASTERISKP, then we do not */
/*         attempt to compute its value. Note that comma */
/*         place holders have been replaced by ASTERISKP. */
/*         Also do not try to convert a continuation signal. */

/* SOURCE fqshrlin.for:943 */
/*<       if(itmsta.eq.asteriskp.or.itmsta.eq.slashi)goto70000 >*/
	if (itmsta == 10 || itmsta == 12) {
	    goto L70000;
	}
/*         BRANCH ON THE TYPE EXPECTED/FOUND. */
/* SOURCE fqshrlin.for:947 */
/*<       goto(10000,20000,30000,40000),item_type(mval) >*/
	switch (feq_gen_item_type_d_[*mval]) {
	    case 1:  goto L10000;
	    case 2:  goto L20000;
	    case 3:  goto L30000;
	    case 4:  goto L40000;
	}
/* SOURCE fqshrlin.for:949 */
/*<       write(stderr,51)item_type(mval) >*/
	feq_gen_io_d__53.ciunit = *stderr;
	s_wsfe(&feq_gen_io_d__53);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_item_type_d_[*mval], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrlin.for:950 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrlin.for:952 */
/*< 10000 continue >*/
L10000:
/*             EXPECTING AN INTEGER VALUE */
/* SOURCE fqshrlin.for:954 */
/*<       if(itmsta.ne.integer)then >*/
	if (itmsta != 2) {
/* SOURCE fqshrlin.for:955 */
/*<       write(stderr,52)item(1:itml) >*/
	    feq_gen_io_d__54.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__54);
	    do_fio(&feq_gen_c_d_1, item, itml);
	    e_wsfe();
/* SOURCE fqshrlin.for:956 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrlin.for:957 */
/*<       write(stderr,56)line >*/
	    feq_gen_io_d__55.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__55);
	    do_fio(&feq_gen_c_d_1, line, line_len);
	    e_wsfe();
/* SOURCE fqshrlin.for:958 */
/*<       write(stderr,*)' ' >*/
	    feq_gen_io_d__56.ciunit = *stderr;
	    s_wsle(&feq_gen_io_d__56);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE fqshrlin.for:959 */
/*<       else >*/
	} else {
/* SOURCE fqshrlin.for:960 */
/*<       read(item(1:itml),'(I10)',err=90000)ival(mval) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = itml;
	    feq_gen_ici_d_1.iciunit = item;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I10)");
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&ival[*mval], (ftnlen)sizeof(integer)
		    );
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
/* SOURCE fqshrlin.for:961 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:962 */
/*<       goto70000 >*/
	goto L70000;
/* SOURCE fqshrlin.for:964 */
/*< 20000 continue >*/
L20000:
/*             Expecting a real value.  Accept INTEGER, FIXED, and SINGLE3 */
/* SOURCE fqshrlin.for:967 */
/*<       if(itmsta.eq.integer.or.itmsta.eq.single3.or.itmsta.eq.fixed)then >*/
	if (itmsta == 2 || itmsta == 6 || itmsta == 3) {
/* SOURCE fqshrlin.for:969 */
/*<       read(item(1:itml),'(F20.0)',err=90000)rval(mval) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = itml;
	    feq_gen_ici_d_1.iciunit = item;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F20.0)");
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&rval[*mval], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
/* SOURCE fqshrlin.for:970 */
/*<       else >*/
	} else {
/* SOURCE fqshrlin.for:971 */
/*<       write(stderr,53)item(1:itml) >*/
	    feq_gen_io_d__57.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__57);
	    do_fio(&feq_gen_c_d_1, item, itml);
	    e_wsfe();
/* SOURCE fqshrlin.for:972 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrlin.for:973 */
/*<       write(stderr,56)line >*/
	    feq_gen_io_d__58.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__58);
	    do_fio(&feq_gen_c_d_1, line, line_len);
	    e_wsfe();
/* SOURCE fqshrlin.for:974 */
/*<       write(stderr,*)' ' >*/
	    feq_gen_io_d__59.ciunit = *stderr;
	    s_wsle(&feq_gen_io_d__59);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE fqshrlin.for:975 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:976 */
/*<       goto70000 >*/
	goto L70000;
/* SOURCE fqshrlin.for:978 */
/*< 30000 continue >*/
L30000:
/*             EXPECTING A DOUBLE PRECISION VALUE. */
/*             Accept INTEGER, FIXED, SINGLE3, AND DOUBLE3 */
/* SOURCE fqshrlin.for:981 */
/*<        >*/
	if (itmsta == 2 || itmsta == 3 || itmsta == 6 || itmsta == 9) {
/* SOURCE fqshrlin.for:983 */
/*<       read(item(1:itml),'(D20.0)',err=90000)dpval(mval) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = itml;
	    feq_gen_ici_d_1.iciunit = item;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(D20.0)");
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&dpval[*mval], (ftnlen)sizeof(
		    doublereal));
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L90000;
	    }
/* SOURCE fqshrlin.for:984 */
/*<       else >*/
	} else {
/* SOURCE fqshrlin.for:985 */
/*<       write(stderr,53)item(1:itml) >*/
	    feq_gen_io_d__60.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__60);
	    do_fio(&feq_gen_c_d_1, item, itml);
	    e_wsfe();
/* SOURCE fqshrlin.for:986 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrlin.for:987 */
/*<       write(stderr,56)line >*/
	    feq_gen_io_d__61.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__61);
	    do_fio(&feq_gen_c_d_1, line, line_len);
	    e_wsfe();
/* SOURCE fqshrlin.for:988 */
/*<       write(stderr,*)' ' >*/
	    feq_gen_io_d__62.ciunit = *stderr;
	    s_wsle(&feq_gen_io_d__62);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE fqshrlin.for:989 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:990 */
/*<       goto70000 >*/
	goto L70000;
/* SOURCE fqshrlin.for:992 */
/*< 40000 continue >*/
L40000:
/*             Expecting a character value.  This could be an identifier */
/*             or a generic string.  Accept anything else that gets */
/*             through but issue a warning.  Primarily useful in */
/*             debugging changes in the code.  Normally nothing */
/*             else should appear here. */

/* SOURCE fqshrlin.for:999 */
/*<       if(itmsta.ne.identifier.and.itmsta.ne.string)then >*/
	if (itmsta != 1 && itmsta != 17) {
/* SOURCE fqshrlin.for:1000 */
/*<       write(stderr,54)item(1:itml) >*/
	    feq_gen_io_d__63.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__63);
	    do_fio(&feq_gen_c_d_1, item, itml);
	    e_wsfe();
/* SOURCE fqshrlin.for:1001 */
/*<       write(stderr,56)line >*/
	    feq_gen_io_d__64.ciunit = *stderr;
	    s_wsfe(&feq_gen_io_d__64);
	    do_fio(&feq_gen_c_d_1, line, line_len);
	    e_wsfe();
/* SOURCE fqshrlin.for:1002 */
/*<       write(stderr,*)' ' >*/
	    feq_gen_io_d__65.ciunit = *stderr;
	    s_wsle(&feq_gen_io_d__65);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE fqshrlin.for:1003 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:1004 */
/*<       cval(mval)=item >*/
	s_copy(cval + *mval * cval_len, item, cval_len, (ftnlen)256);
/* SOURCE fqshrlin.for:1005 */
/*<       clen(mval)=itml >*/
	clen[*mval] = itml;
/* SOURCE fqshrlin.for:1006 */
/*<       goto70000 >*/
	goto L70000;
/* SOURCE fqshrlin.for:1008 */
/*< 70000 continue >*/
L70000:
/* SOURCE fqshrlin.for:1009 */
/*<       endif >*/
	;
    }
/* SOURCE fqshrlin.for:1010 */
/*<       if(eos.eq.1)return >*/
    if (eos == 1) {
	return 0;
    }
/* SOURCE fqshrlin.for:1011 */
/*<       goto99999 >*/
    goto L99999;
/* SOURCE fqshrlin.for:1013 */
/*< 90000 continue >*/
L90000:
/* SOURCE fqshrlin.for:1014 */
/*<       write(stderr,58)item(1:itml) >*/
    feq_gen_io_d__66.ciunit = *stderr;
    s_wsfe(&feq_gen_io_d__66);
    do_fio(&feq_gen_c_d_1, item, itml);
    e_wsfe();
/* SOURCE fqshrlin.for:1015 */
/*<       stop'Abnormal stop. Bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE fqshrlin.for:1017 */
/*<       end >*/
    return 0;
} /* getval_ */

/*     *********** */
/*     *         * */
/*     * GET_NAMED_ITEMS */
/*     *         * */
/*     *********** */
/* SOURCE fqshrlin.for:1024 */
/*<        >*/
/* Subroutine */ int feq_gen_get_named_items_d_(integer *stdin, integer *stdout, 
	integer *feq_gen_max_line_d_, integer *feq_gen_n_name_d_, integer *feq_storage_group, integer *
	feq_gen_feq_storage_response_type_d_, integer *feq_gen_feq_storage_convert_rule_d_, integer *feq_gen_feq_storage_group_index_d_, 
	char *feq_gen_feq_storage_name_table_d_, integer *feq_gen_n_integer_d_, integer *feq_gen_n_dp_d_, integer *
	feq_gen_n_char_d_, char *feq_gen_block_name_d_, integer *feq_gen_feq_storage_integer_response_d_, real *
	feq_gen_feq_storage_real_response_d_, doublereal *feq_gen_feq_storage_dp_response_d_, char *feq_gen_feq_storage_char_response_d_, 
	integer *eflag, ftnlen name_table_len, ftnlen block_name_len, ftnlen 
	char_response_len)
{
    /* Format strings */
    static char fmt_54[] = "(/,\002 *ERR:389* Name=\002,a,\002 is unknown in\
: \002,a)";
    static char fmt_56[] = "(/,\002 Unable to continue due to previous error\
s in: \002,a)";
    static char fmt_60[] = "(/,\002 Processing:\002,a)";
    static char fmt_62[] = "(/,\002 *ERR:390* Count=\002,i5,\002 is too larg\
e for: \002,a)";
    static char fmt_64[] = "(/,\002 *WRN:391* \002,i4,\002 items requested\
 \002,\002but only \002,i4,\002 found.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);
    integer f_back(alist *);

    /* Local variables */
    integer feq_gen_line_knt_d_, feq_gen_item_knt_d_, feq_gen_i_d_, j, k;
    extern /* Subroutine */ int feq_gen_chk_and_convert_response_d_(integer *, integer 
	    *, char *, integer *, integer *, integer *, integer *, char *, 
	    integer *, integer *, integer *, real *, doublereal *, ftnlen, 
	    ftnlen);
    integer feq_gen_item_type_d_[40], ip, it, js, feq_gen_group_code_d_;
    char key[16];
    integer opt, feq_gen_nmult_given_d_, clen[40];
    char cval[256*40], line[196];
    integer ival[40];
    real rval[40];
    char term[1*40];
    integer feq_gen_type_d_;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    doublereal dpval[40];
    integer terml[40], eflag2, feq_gen_nmult_counted_d_;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     getval_(integer *, char *, integer *, integer *, integer *, 
	    integer *, real *, doublereal *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, ftnlen, ftnlen, ftnlen);
    integer maxknt, termcls[40];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__72 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_62, 0 };


/*     Get one or more named items from one or more lines of user input. */
/*     A named item is a name known to the routine that called us */
/*     followed by an equal sign which is followed by one or more */
/*     responses on a single line.  No response can carry over to */
/*     a following line.  A response can be more than one value */
/*     of a type that depends on the response type of the name. */
/*     Some names will not have a response.  They represent a value */
/*     in themselves. */
/*     STDIN- unit number for input of lines of user information. */
/*     STDOUT- unit number for communication with the user via output */
/*     MAX_LINE- maximum number of lines to process.  Used to enable processing */
/*               a single line.  Otherwise MAX_LINE should be large. */
/*     N_NAME- number of names that might appear.  There can be aliases, */
/*             that is, different names that have the same meaning. */
/*     The following values are all vectors that have the extent: N_NAME */
/*     GROUP- gives the code defining the response group: numeric data, */
/*            character data, end signal, or next block. */
/*            Numeric data are integer, real, or double */
/*            precision.  Character data are character strings. */
/*            End signal and next block are used to terminate the processing */
/*            of lines. */
/*     RESPONSE_TYPE- gives the type of the response: integer value, */
/*                real value, double precision value, multiple real */
/*                value, date-time, or none. */
/*     CONVERT_RULE-  exact: the numeric value must exactly match the */
/*                   numeric type or types.  Thus if the response type */
/*                   is integer, the response MUST be an integer.  That */
/*                   is 123 is valid but 123. is not valid.  lower: the */
/*                   numeric response will take a lower type where */
/*                   the ranking from high to low is: double precision, */
/*                   real, integer.  Thus if the response type is real, */
/*                   a response of 123 is valid even though it is an */
/*                   integer. */
/*     GROUP_INDEX- index into the vector of the type that matches the */
/*                  GROUP-numeric or character.  The numeric responses */
/*                  are considered to be in an overlay.  That is */
/*                  real, integer, and double precision are overlaid */
/*                  on the same space.  We assume that integer and real */
/*                  values are the same size in the target processor */
/*                  and the double precision is double the size of */
/*                  a real.  The index for a double precision value is */
/*                  the index in the real vector to its first real */
/*                  element.  For example: */
/* Name          Name       Group    Response   Group */
/* count                             type      index          Notes */
/* -----   ----------    --------  ----------  ------  ------------------------------------------------------
------ */
/*   1     NBRA           NUMERIC  INTVAL        1 */
/*   2     NEX            NUMERIC  INTVAL        2 */
/*   3     SFAC           NUMERIC  REAVAL        3     This is the first real value but it gets index 3 */
/*                                               4     We need this space  so that */
/*                                                     the following double precision value will have the corr
ect */
/*                                                     index value.  The index value must alwasy be the first 
*/
/*                                                     of two real elements */
/*   4     FACTOR         NUMERIC  DPRVAL        5     This one takes two slots */
/*                                               6     Needed for the double precision value */
/*                                               7     Needed so that following date-time value has proper ind
ex. */
/*                                                     This can be avoided in most cases but I put it here as 
*/
/*                                                     an example of how the data-time value must be placed. 
*/
/*   5     STIME          NUMERIC  DATETIME      8     Contains the year */
/*                                               9     Contains the month number */
/*                                              10     contains the day number */
/*                                              11     contains double */
/*                                              12      precision hour of the day */
/*   6     SOPER          CHAR     CHRVAL        1     Note that character values have their own index.  Each 
*/
/*                                                     character value can be 64 characters long. */
/*   7     BRANCH         NXTBLK   NONE          0     Group index is not used.  This example would apply to 
*/
/*                                                     processing the run-control block because the heading */
/*                                                     for the branch-description block could follow it. */
/*                                                     The line containing BRANCH must be put back on the inpu
t. */
/*   8     END            ENDSIG   NONE          0     An explicit end signal for the current block. */
/*     NAME_TABLE-  contains the names for the possible responses.  In the example just above, */
/*                  there would be 8 names in the table of names. */
/*     N_INTEGER-  number of elements in the numeric-response table for integers and reals. */
/*                 Should be even number   because the double precision vector will get one-half this */
/*                 number of elements. */
/*     N_DP-       number of elements in the numeric-response table for double precision values. */
/*                 Should be one-half N_INTEGER. */
/*     N_CHAR-     number of elements in the character-response table */
/*     BLOCK_NAME- name of the block or command being processed.  Needed in error messages. */
/*     INTEGER_RESPONSE - vector for integer responses */
/*     REAL_RESPONSE - vector for the real responses */
/*     DP_RESPONSE- vector for double precision responses */
/*     CHAR_RESPONSE- vector for character responses */
/*     EFLAG- error flag.  If > 0 an error has been found. */
/* SOURCE fqshrlin.for:1119 */
/*<       implicitnone >*/
/* SOURCE fqshrlin.for:1121 */
/*<       integerstdin,stdout,max_line,n_name,eflag,n_integer,n_dp,n_char >*/
/* SOURCE fqshrlin.for:1123 */
/*<        >*/
/* SOURCE fqshrlin.for:1127 */
/*<       realreal_response(n_integer) >*/
/* SOURCE fqshrlin.for:1129 */
/*<       real*8dp_response(n_dp) >*/
/* SOURCE fqshrlin.for:1131 */
/*<        >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE fqshrlin.for:1137 */
/*<        >*/
/* SOURCE fqshrlin.for:1141 */
/*<        >*/
/* SOURCE fqshrlin.for:1146 */
/*<        >*/
/* SOURCE fqshrlin.for:1149 */
/*<        >*/
/* SOURCE fqshrlin.for:1151 */
/*<       realrval(nval) >*/
/* SOURCE fqshrlin.for:1152 */
/*<       real*8dpval(nval) >*/
/* SOURCE fqshrlin.for:1153 */
/*<       charactercval(nval)*256,term(nval)*1,line*196,key*16 >*/
/* SOURCE fqshrlin.for:1157 */
/*<       externalgetval,inline >*/
/*     *****************************FORMATS****************************** */
/* SOURCE fqshrlin.for:1024 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrlin.for:1024 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrlin.for:1160 */
/*<    54 format(/,' *ERR:389* Name=',a,' is unknown in: ',a) >*/
/* SOURCE fqshrlin.for:1161 */
/*<    56 format(/,' Unable to continue due to previous errors in: ',a) >*/
/* SOURCE fqshrlin.for:1162 */
/*<    60 format(/,' Processing:',a) >*/
/* SOURCE fqshrlin.for:1163 */
/*<    62 format(/,' *ERR:390* Count=',i5,' is too large for: ',a) >*/
/* SOURCE fqshrlin.for:1164 */
/*<    64  >*/
/* *********************************************************************** */
/*     Clear the local error flag for subroutine GETVAL */
/* SOURCE fqshrlin.for:1168 */
/*<       eflag2=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> feq_gen_name_table_d_(feq_gen_feq_storage_name_table_d_, 16);

    feq::IndexedPointer<integer> feq_gen_group_index_d_(feq_gen_feq_storage_group_index_d_, 1);

    feq::IndexedPointer<integer> feq_gen_convert_rule_d_(feq_gen_feq_storage_convert_rule_d_, 1);

    feq::IndexedPointer<integer> feq_gen_response_type_d_(feq_gen_feq_storage_response_type_d_, 1);

    feq::IndexedPointer<integer> group(feq_storage_group, 1);

    feq::IndexedPointer<real> feq_gen_real_response_d_(feq_gen_feq_storage_real_response_d_, 1);

    feq::IndexedPointer<integer> feq_gen_integer_response_d_(feq_gen_feq_storage_integer_response_d_, 1);

    feq::IndexedPointer<doublereal> feq_gen_dp_response_d_(feq_gen_feq_storage_dp_response_d_, 1);

    feq::IndexedPointer<char> feq_gen_char_response_d_(feq_gen_feq_storage_char_response_d_, char_response_len);

    /* Function Body */
/* L54: */
/* L56: */
/* L60: */
/* L62: */
/* L64: */
    eflag2 = 0;
/*     Read lines of input and process each one until the expected number */
/*     of lines or an end of block signal is found. */
/*     Default values must be set for all possible responses before we */
/*     get here. */
/*     Select option for GETVAL to return BOTH the string value */
/*     and the converted value for numeric responses. */
/*     In some cases the value will be recomputed. */
/* SOURCE fqshrlin.for:1178 */
/*<       opt=2 >*/
    opt = 2;
/*     Start a loop over input lines */
/* SOURCE fqshrlin.for:1180 */
/*<       line_knt=0 >*/
    feq_gen_line_knt_d_ = 0;
/* SOURCE fqshrlin.for:1181 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrlin.for:1183 */
/*<       if(line_knt.ge.max_line)return >*/
    if (feq_gen_line_knt_d_ >= *feq_gen_max_line_d_) {
	return 0;
    }
/* SOURCE fqshrlin.for:1185 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE fqshrlin.for:1189 */
/*<       line_knt=line_knt+1 >*/
    ++feq_gen_line_knt_d_;
/* SOURCE fqshrlin.for:1192 */
/*<       it=feq_len_trim(line) >*/
    it = feq_gen_feq_len_trim_d_(line, (ftnlen)196);
/* SOURCE fqshrlin.for:1193 */
/*<       write(stdout,60)line(1:it) >*/
    feq_gen_io_d__72.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__72);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE fqshrlin.for:1195 */
/*<       line(it+1:it+1)='''' >*/
    feq_gen_i_d_1 = it;
    s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE fqshrlin.for:1197 */
/*<        >*/
    getval_(stdout, line, &feq_gen_c_d_40, &opt, feq_gen_item_type_d_, ival, rval, dpval, cval, 
	    clen, &eflag2, term, terml, termcls, &feq_gen_item_knt_d_, (ftnlen)196, (
	    ftnlen)256, (ftnlen)1);
/*      WRITE(STDOUT,*) */
/*     A  ' Return from GETVAL in GET_NAMED_ITEMS: ITEM_KNT=',ITEM_KNT */
/*      WRITE(STDOUT,97) */
/* 97    FORMAT(1X,12X,'ITEM','   LEN  TYPE T  TCLS') */
/*      DO 9213 I=1,ITEM_KNT */
/*        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I), */
/*     A                  TERMCLS(I) */
/* 99    FORMAT(' ',A16,' ',I5,' ',I5,' ',A1,' ',I5) */
/* 9213  CONTINUE */
/* SOURCE fqshrlin.for:1213 */
/*<       if(eflag2.ne.0)then >*/
    if (eflag2 != 0) {
/*         Error in parsing the line of input. */
/* SOURCE fqshrlin.for:1216 */
/*<       write(stdout,56)block_name(1:feq_len_trim(block_name)) >*/
	feq_gen_io_d__83.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__83);
	do_fio(&feq_gen_c_d_1, feq_gen_block_name_d_, feq_gen_feq_len_trim_d_(feq_gen_block_name_d_, 
		block_name_len));
	e_wsfe();
/* SOURCE fqshrlin.for:1217 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrlin.for:1218 */
/*<       else >*/
    } else {
/*         No errors reported.  Process the items found on the current */
/*         line. */
/*         Check if this is already something from a following input block */
/*         or the end of block signal.  CHK_AND_CONVERT_RESPONSE does */
/*         not know anything about what might follow this signal value. */
/* SOURCE fqshrlin.for:1226 */
/*<       i=1 >*/
	feq_gen_i_d_ = 1;
/*         Find the value for the next item from the */
/*         symbol table. */
/* SOURCE fqshrlin.for:1229 */
/*<       key=cval(i)(1:clen(i)) >*/
	s_copy(key, cval + (feq_gen_i_d_ - 1 << 8), (ftnlen)16, clen[feq_gen_i_d_ - 1]);
/* SOURCE fqshrlin.for:1230 */
/*<       calllstab(key,name_table,n_name,ip) >*/
	lstab_(key, feq_gen_name_table_d_ + 16, feq_gen_n_name_d_, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrlin.for:1233 */
/*<       if(ip.eq.0)then >*/
	if (ip == 0) {
/*           error-symbol not found */
/* SOURCE fqshrlin.for:1235 */
/*<       write(stdout,54)key,block_name(1:feq_len_trim(block_name)) >*/
	    feq_gen_io_d__87.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__87);
	    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_block_name_d_, feq_gen_feq_len_trim_d_(feq_gen_block_name_d_, 
		    block_name_len));
	    e_wsfe();
/* SOURCE fqshrlin.for:1236 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrlin.for:1237 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrlin.for:1238 */
/*<       else >*/
	} else {
/* SOURCE fqshrlin.for:1239 */
/*<       group_code=group(ip) >*/
	    feq_gen_group_code_d_ = group[ip];
/* SOURCE fqshrlin.for:1240 */
/*<       if(group_code.eq.nxtblk)then >*/
	    if (feq_gen_group_code_d_ == 2) {
/* SOURCE fqshrlin.for:1241 */
/*<       backspace(stdin) >*/
		feq_gen_al_d_1.aerr = 0;
		feq_gen_al_d_1.aunit = *stdin;
		f_back(&feq_gen_al_d_1);
/* SOURCE fqshrlin.for:1242 */
/*<       return >*/
		return 0;
/* SOURCE fqshrlin.for:1243 */
/*<       elseif(group_code.eq.endsig)then >*/
	    } else if (feq_gen_group_code_d_ == 3) {
/* SOURCE fqshrlin.for:1244 */
/*<       return >*/
		return 0;
/* SOURCE fqshrlin.for:1245 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:1246 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:1249 */
/*<        >*/
	feq_gen_chk_and_convert_response_d_(stdout, feq_gen_n_name_d_, feq_gen_name_table_d_ + 16, &
		feq_gen_response_type_d_[1], &feq_gen_convert_rule_d_[1], &feq_gen_item_knt_d_, 
		feq_gen_item_type_d_, cval, clen, eflag, ival, rval, dpval, (ftnlen)16,
		 (ftnlen)256);
/* SOURCE fqshrlin.for:1255 */
/*<       i=1 >*/
	feq_gen_i_d_ = 1;
/* SOURCE fqshrlin.for:1256 */
/*<   110 continue >*/
L110:
/*           Find the value for the next item from the */
/*           symbol table. */
/* SOURCE fqshrlin.for:1259 */
/*<       key=cval(i)(1:clen(i)) >*/
	s_copy(key, cval + (feq_gen_i_d_ - 1 << 8), (ftnlen)16, clen[feq_gen_i_d_ - 1]);
/* SOURCE fqshrlin.for:1260 */
/*<       calllstab(key,name_table,n_name,ip) >*/
	lstab_(key, feq_gen_name_table_d_ + 16, feq_gen_n_name_d_, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrlin.for:1263 */
/*<       if(ip.eq.0)then >*/
	if (ip == 0) {
/*             error-symbol not found */
/* SOURCE fqshrlin.for:1265 */
/*<       write(stdout,54)key,block_name(1:feq_len_trim(block_name)) >*/
	    feq_gen_io_d__89.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__89);
	    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_block_name_d_, feq_gen_feq_len_trim_d_(feq_gen_block_name_d_, 
		    block_name_len));
	    e_wsfe();
/* SOURCE fqshrlin.for:1266 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrlin.for:1267 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrlin.for:1268 */
/*<       else >*/
	} else {
/* SOURCE fqshrlin.for:1269 */
/*<       group_code=group(ip) >*/
	    feq_gen_group_code_d_ = group[ip];
/* SOURCE fqshrlin.for:1270 */
/*<       it=group_index(ip) >*/
	    it = feq_gen_group_index_d_[ip];
/* SOURCE fqshrlin.for:1271 */
/*<       type=response_type(ip) >*/
	    feq_gen_type_d_ = feq_gen_response_type_d_[ip];
/* SOURCE fqshrlin.for:1272 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:1275 */
/*<       if(group_code.eq.numeric)then >*/
	if (feq_gen_group_code_d_ == 0) {
/*             Responses are a numeric value. */
/* SOURCE fqshrlin.for:1277 */
/*<       if(type.eq.intval)then >*/
	    if (feq_gen_type_d_ == 1) {
/* SOURCE fqshrlin.for:1278 */
/*<       integer_response(it)=ival(i+1) >*/
		feq_gen_integer_response_d_[it] = ival[feq_gen_i_d_];
/* SOURCE fqshrlin.for:1279 */
/*<       elseif(type.eq.reaval)then >*/
	    } else if (feq_gen_type_d_ == 2) {
/* SOURCE fqshrlin.for:1280 */
/*<       real_response(it)=rval(i+1) >*/
		feq_gen_real_response_d_[it] = rval[feq_gen_i_d_];
/* SOURCE fqshrlin.for:1281 */
/*<       elseif(type.eq.dprval)then >*/
	    } else if (feq_gen_type_d_ == 3) {
/* SOURCE fqshrlin.for:1282 */
/*<       dp_response((it+1)/2)=dpval(i+1) >*/
		feq_gen_dp_response_d_[(it + 1) / 2] = dpval[feq_gen_i_d_];
/* SOURCE fqshrlin.for:1283 */
/*<       elseif(type.eq.datetime)then >*/
	    } else if (feq_gen_type_d_ == 7) {
/*               IT points to the year location.  Month and day are */
/*               at unit increments away.  The hour is double precision */
/*               and is stored as a conceptual overlay on the real and */
/*               integer vectors.  E. G. IT -> year, IT+1->month */
/*               IT+2-> day and (IT+4)/2-> hour. */
/* SOURCE fqshrlin.for:1289 */
/*<       integer_response(it)=ival(i+1) >*/
		feq_gen_integer_response_d_[it] = ival[feq_gen_i_d_];
/* SOURCE fqshrlin.for:1290 */
/*<       integer_response(it+1)=ival(i+2) >*/
		feq_gen_integer_response_d_[it + 1] = ival[feq_gen_i_d_ + 1];
/* SOURCE fqshrlin.for:1291 */
/*<       integer_response(it+2)=ival(i+3) >*/
		feq_gen_integer_response_d_[it + 2] = ival[feq_gen_i_d_ + 2];
/* SOURCE fqshrlin.for:1292 */
/*<       dp_response((it+4)/2)=dpval(i+4) >*/
		feq_gen_dp_response_d_[(it + 4) / 2] = dpval[feq_gen_i_d_ + 3];
/* SOURCE fqshrlin.for:1293 */
/*<       i=i+3 >*/
		feq_gen_i_d_ += 3;
/* SOURCE fqshrlin.for:1294 */
/*<       elseif(type.eq.multr)then >*/
	    } else if (feq_gen_type_d_ == 8) {
/*               Compute the maximum number of real items.  Note: the */
/*               multiple real repsonses cannot be the last in the */
/*               vectors.  There must be another input item following */
/*               so that IP + 1 is valid. */
/* SOURCE fqshrlin.for:1299 */
/*<       maxknt=group_index(ip+1)-it-1 >*/
		maxknt = feq_gen_group_index_d_[ip + 1] - it - 1;
/* SOURCE fqshrlin.for:1300 */
/*<       js=1 >*/
		js = 1;
/* SOURCE fqshrlin.for:1301 */
/*<       nmult_given=-1 >*/
		feq_gen_nmult_given_d_ = -1;
/* SOURCE fqshrlin.for:1302 */
/*<       nmult_counted=0 >*/
		feq_gen_nmult_counted_d_ = 0;
/* SOURCE fqshrlin.for:1303 */
/*<       if(item_type(i+1).eq.intval.and.ival(i+1).le.maxknt)then >*/
		if (feq_gen_item_type_d_[feq_gen_i_d_] == 1 && ival[feq_gen_i_d_] <= maxknt) {
/*                 Treat as count of the number of real values. */
/* SOURCE fqshrlin.for:1306 */
/*<       nmult_given=ival(i+1) >*/
		    feq_gen_nmult_given_d_ = ival[feq_gen_i_d_];
/* SOURCE fqshrlin.for:1307 */
/*<       js=2 >*/
		    js = 2;
/* SOURCE fqshrlin.for:1308 */
/*<       endif >*/
		}
/*               Determine the number of items for error checking */
/* SOURCE fqshrlin.for:1310 */
/*<       j=js >*/
		j = js;
/* SOURCE fqshrlin.for:1311 */
/*<   150 continue >*/
L150:
/* SOURCE fqshrlin.for:1312 */
/*<       if(i+j.gt.item_knt)goto160 >*/
		if (feq_gen_i_d_ + j > feq_gen_item_knt_d_) {
		    goto L160;
		}
/* SOURCE fqshrlin.for:1313 */
/*<       if(item_type(i+j).eq.chrval)goto160 >*/
		if (feq_gen_item_type_d_[feq_gen_i_d_ + j - 1] == 4) {
		    goto L160;
		}
/* SOURCE fqshrlin.for:1314 */
/*<       j=j+1 >*/
		++j;
/* SOURCE fqshrlin.for:1315 */
/*<       goto150 >*/
		goto L150;
/* SOURCE fqshrlin.for:1316 */
/*<   160 continue >*/
L160:
/* SOURCE fqshrlin.for:1317 */
/*<       nmult_counted=j-js >*/
		feq_gen_nmult_counted_d_ = j - js;
/*                WRITE(STDOUT,*) ' NMULT_GIVEN=',NMULT_GIVEN, */
/*     A                       ' NMULT_COUNTED=',NMULT_COUNTED */
/* SOURCE fqshrlin.for:1321 */
/*<       if(nmult_given.gt.nmult_counted)then >*/
		if (feq_gen_nmult_given_d_ > feq_gen_nmult_counted_d_) {
/* SOURCE fqshrlin.for:1322 */
/*<       write(stdout,64)nmult_given,nmult_counted >*/
		    feq_gen_io_d__96.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__96);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_nmult_given_d_, (ftnlen)sizeof(
			    integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_nmult_counted_d_, (ftnlen)sizeof(
			    integer));
		    e_wsfe();
/* SOURCE fqshrlin.for:1323 */
/*<       nmult_given=nmult_counted >*/
		    feq_gen_nmult_given_d_ = feq_gen_nmult_counted_d_;
/* SOURCE fqshrlin.for:1324 */
/*<       endif >*/
		}
/* SOURCE fqshrlin.for:1325 */
/*<       if(nmult_given.ge.0)then >*/
		if (feq_gen_nmult_given_d_ >= 0) {
/* SOURCE fqshrlin.for:1326 */
/*<       integer_response(it)=nmult_given >*/
		    feq_gen_integer_response_d_[it] = feq_gen_nmult_given_d_;
/* SOURCE fqshrlin.for:1327 */
/*<       else >*/
		} else {
/* SOURCE fqshrlin.for:1328 */
/*<       integer_response(it)=nmult_counted >*/
		    feq_gen_integer_response_d_[it] = feq_gen_nmult_counted_d_;
/* SOURCE fqshrlin.for:1329 */
/*<       endif >*/
		}
/* SOURCE fqshrlin.for:1331 */
/*<       if(integer_response(it).gt.maxknt)then >*/
		if (feq_gen_integer_response_d_[it] > maxknt) {
/* SOURCE fqshrlin.for:1332 */
/*<       write(stdout,62)integer_response(it),key >*/
		    feq_gen_io_d__97.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__97);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_integer_response_d_[it], (ftnlen)
			    sizeof(integer));
		    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
		    e_wsfe();
/* SOURCE fqshrlin.for:1333 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrlin.for:1334 */
/*<       endif >*/
		}
/* SOURCE fqshrlin.for:1336 */
/*<       if(integer_response(it).gt.0)then >*/
		if (feq_gen_integer_response_d_[it] > 0) {
/* SOURCE fqshrlin.for:1337 */
/*<       do165j=1,integer_response(it) >*/
		    feq_gen_i_d_1 = feq_gen_integer_response_d_[it];
		    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fqshrlin.for:1338 */
/*<       k=j+js-1 >*/
			k = j + js - 1;
/* SOURCE fqshrlin.for:1339 */
/*<       real_response(it+j)=rval(i+k) >*/
			feq_gen_real_response_d_[it + j] = rval[feq_gen_i_d_ + k - 1];
/* SOURCE fqshrlin.for:1340 */
/*<   165 continue >*/
/* L165: */
		    }
/* SOURCE fqshrlin.for:1341 */
/*<       endif >*/
		}
/* SOURCE fqshrlin.for:1342 */
/*<       i=i+nmult_counted+js-1 >*/
		feq_gen_i_d_ = feq_gen_i_d_ + feq_gen_nmult_counted_d_ + js - 1;
/* SOURCE fqshrlin.for:1343 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:1344 */
/*<       elseif(group_code.eq.char)then >*/
	} else if (feq_gen_group_code_d_ == 1) {
/*             The responses are character values. */
/* SOURCE fqshrlin.for:1346 */
/*<       char_response(it)=cval(i+1)(1:clen(i+1)) >*/
	    s_copy(feq_gen_char_response_d_ + it * char_response_len, cval + (feq_gen_i_d_ << 8)
		    , char_response_len, clen[feq_gen_i_d_]);
/* SOURCE fqshrlin.for:1347 */
/*<       endif >*/
	}
/*           Do the increment for single response items.  Multiple response */
/*           items must increment such that the correct result occurs with this */
/*           final increment! */
/* SOURCE fqshrlin.for:1351 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE fqshrlin.for:1352 */
/*<       if(i.gt.item_knt)then >*/
	if (feq_gen_i_d_ > feq_gen_item_knt_d_) {
/*             Get the next line from the input */
/* SOURCE fqshrlin.for:1354 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE fqshrlin.for:1355 */
/*<       else >*/
	} else {
/*             Get the next item from the current line */
/* SOURCE fqshrlin.for:1357 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE fqshrlin.for:1358 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:1359 */
/*<       endif >*/
    }
/* SOURCE fqshrlin.for:1361 */
/*<   200 continue >*/
/* L200: */
/* SOURCE fqshrlin.for:1362 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:1363 */
/*<       end >*/
} /* get_named_items__ */

/*     *********** */
/*     *         * */
/*     * GET_HEAD_LIMTS */
/*     *         * */
/*     *********** */
/* SOURCE fqshrlin.for:1371 */
/*<        >*/
/* Subroutine */ int feq_gen_get_head_limits_d_(integer *stdout, char *string, integer 
	*maxn, integer *n, integer *feq_gen_feq_storage_head_start_d_, integer *feq_gen_feq_storage_head_end_d_, ftnlen 
	string_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:392* Found \002,i3,\002 headings >\
 \002,i3,\002 allowed.\002)";

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, it, iend, done;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer istop, istart;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Get the starting and stopping column numbers for each */
/*     heading in the string. */
/* SOURCE fqshrlin.for:1378 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrlin.for:1380 */
/*<       integermaxn,n,head_start(maxn),head_end(maxn),stdout >*/
/* SOURCE fqshrlin.for:1381 */
/*<       characterstring*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output */
/*     STRING - string to scan */
/*     MAXN - maximum extent for vectors in arg list */
/*     N - number of headings found */
/*     HEAD_START - column number of start of each heading */
/*     HEAD_END - column number of end of each heading. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrlin.for:1392 */
/*<       integerdone,i,iend,istart,istop,it >*/
/*     + + + INTRINSICS + + + */
/*     **************************FORMATS********************************* */
/* SOURCE fqshrlin.for:1371 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrlin.for:1371 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrlin.for:1397 */
/*<    50 format(/,' *ERR:392* Found ',i3,' headings > ',i3,' allowed.') >*/
/* *********************************************************************** */
/* SOURCE fqshrlin.for:1399 */
/*<       i=1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_head_end_d_(feq_gen_feq_storage_head_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_head_start_d_(feq_gen_feq_storage_head_start_d_, 1);

    /* Function Body */
/* L50: */
    feq_gen_i_d_ = 1;
/* SOURCE fqshrlin.for:1400 */
/*<       done=0 >*/
    done = 0;
/* SOURCE fqshrlin.for:1401 */
/*<       iend=feq_len_trim(string) >*/
    iend = feq_gen_feq_len_trim_d_(string, string_len);
/*     Seek a single quote marking beginning of a comment */
/* SOURCE fqshrlin.for:1403 */
/*<       it=index(string(1:iend),'''') >*/
    it = i_indx(string, const_cast<char*>("'"), iend, (ftnlen)1);
/* SOURCE fqshrlin.for:1404 */
/*<       if(it.gt.0)then >*/
    if (it > 0) {
/*       Single quote found.  Character before it becomes the end */
/* SOURCE fqshrlin.for:1406 */
/*<       iend=it-1 >*/
	iend = it - 1;
/* SOURCE fqshrlin.for:1407 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' IEND=',IEND */
/* SOURCE fqshrlin.for:1411 */
/*<       n=0 >*/
    *n = 0;
/* SOURCE fqshrlin.for:1413 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrlin.for:1414 */
/*<       if(string(i:i).eq.' ')then >*/
    if (*(unsigned char *)&string[feq_gen_i_d_ - 1] == ' ') {
/* SOURCE fqshrlin.for:1415 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE fqshrlin.for:1416 */
/*<       if(i.le.iend)then >*/
	if (feq_gen_i_d_ <= iend) {
/* SOURCE fqshrlin.for:1417 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE fqshrlin.for:1418 */
/*<       else >*/
	} else {
/*           RETURN if no non-blank found */
/* SOURCE fqshrlin.for:1420 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrlin.for:1421 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:1422 */
/*<       else >*/
    } else {
/* SOURCE fqshrlin.for:1423 */
/*<       istart=i >*/
	istart = feq_gen_i_d_;
/* SOURCE fqshrlin.for:1424 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrlin.for:1425 */
/*<       if(string(i:i).ne.' ')then >*/
	if (*(unsigned char *)&string[feq_gen_i_d_ - 1] != ' ') {
/* SOURCE fqshrlin.for:1426 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE fqshrlin.for:1427 */
/*<       if(i.le.iend)then >*/
	    if (feq_gen_i_d_ <= iend) {
/* SOURCE fqshrlin.for:1428 */
/*<       goto110 >*/
		goto L110;
/* SOURCE fqshrlin.for:1429 */
/*<       else >*/
	    } else {
/* SOURCE fqshrlin.for:1430 */
/*<       istop=i-1 >*/
		istop = feq_gen_i_d_ - 1;
/* SOURCE fqshrlin.for:1431 */
/*<       done=1 >*/
		done = 1;
/* SOURCE fqshrlin.for:1432 */
/*<       endif >*/
	    }
/* SOURCE fqshrlin.for:1433 */
/*<       else >*/
	} else {
/* SOURCE fqshrlin.for:1434 */
/*<       istop=i-1 >*/
	    istop = feq_gen_i_d_ - 1;
/* SOURCE fqshrlin.for:1435 */
/*<       endif >*/
	}
/* SOURCE fqshrlin.for:1436 */
/*<       endif >*/
    }
/* SOURCE fqshrlin.for:1438 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrlin.for:1439 */
/*<       if(n.gt.maxn)then >*/
    if (*n > *maxn) {
/* SOURCE fqshrlin.for:1440 */
/*<       write(stdout,50)n,maxn >*/
	feq_gen_io_d__105.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__105);
	do_fio(&feq_gen_c_d_1, (char *)&(*n), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*maxn), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrlin.for:1441 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrlin.for:1442 */
/*<       endif >*/
    }
/* SOURCE fqshrlin.for:1443 */
/*<       head_start(n)=istart >*/
    feq_gen_head_start_d_[*n] = istart;
/* SOURCE fqshrlin.for:1444 */
/*<       head_end(n)=istop >*/
    feq_gen_head_end_d_[*n] = istop;
/* SOURCE fqshrlin.for:1446 */
/*<       if(done.eq.1)return >*/
    if (done == 1) {
	return 0;
    }
/* SOURCE fqshrlin.for:1448 */
/*<       goto100 >*/
    goto L100;
/* SOURCE fqshrlin.for:1449 */
/*<       end >*/
} /* get_head_limits__ */




/* SOURCE fqshrlin.for:1453 */
/*<        >*/
/* Subroutine */ int feq_gen_get_item_limits_storage_d_(integer *stdout, char *string, 
	integer *maxn, char *just, integer *n, integer *feq_gen_feq_storage_item_start_d_, integer 
	*feq_gen_feq_storage_item_end_d_, integer *feq_gen_feq_storage_head_start_d_, integer *feq_gen_feq_storage_head_end_d_, ftnlen 
	string_len, ftnlen just_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_get_head_limits_d_(integer *, char *, integer *
	    , integer *, integer *, integer *, ftnlen);

/*     Find the column limits for the items on an input line as defined */
/*     by the justification rule and the limits for the headings supplied */
/*     by the user. */
/* SOURCE fqshrlin.for:1461 */
/*<       implicitnone >*/
/* SOURCE fqshrlin.for:1462 */
/*<       characterjust*5,string*(*) >*/
/* SOURCE fqshrlin.for:1463 */
/*<       integern,maxn,stdout,item_start(maxn),item_end(maxn) >*/
/*     Called program units */
/* SOURCE fqshrlin.for:1467 */
/*<       externalget_head_limits >*/
/*     Local */
/* SOURCE fqshrlin.for:1471 */
/*<       integeri >*/
/* SOURCE fqshrlin.for:1472 */
/*<       integerhead_start(maxn),head_end(maxn) >*/
/* *********************************************************************** */
/* SOURCE fqshrlin.for:1474 */
/*<       callget_head_limits(stdout,string,maxn,n,head_start,head_end) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_head_end_d_(feq_gen_feq_storage_head_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_head_start_d_(feq_gen_feq_storage_head_start_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
    feq_gen_get_head_limits_d_(stdout, string, maxn, n, &feq_gen_head_start_d_[1], &feq_gen_head_end_d_[
	    1], string_len);
/* SOURCE fqshrlin.for:1477 */
/*<       if(just.eq.'LEFT')then >*/
    if (s_cmp(just, const_cast<char*>("LEFT"), (ftnlen)5, (ftnlen)4) == 0) {
/*       Use left justification to set the limits */
/* SOURCE fqshrlin.for:1479 */
/*<       do100i=1,n-1 >*/
	feq_gen_i_d_1 = *n - 1;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrlin.for:1480 */
/*<       item_start(i)=head_start(i) >*/
	    feq_gen_item_start_d_[feq_gen_i_d_] = feq_gen_head_start_d_[feq_gen_i_d_];
/* SOURCE fqshrlin.for:1481 */
/*<       item_end(i)=head_start(i+1)-1 >*/
	    feq_gen_item_end_d_[feq_gen_i_d_] = feq_gen_head_start_d_[feq_gen_i_d_ + 1] - 1;
/* SOURCE fqshrlin.for:1482 */
/*<   100 continue >*/
/* L100: */
	}
/*       Assume a max of 10 columns for the last column of input. */
/* SOURCE fqshrlin.for:1484 */
/*<       item_start(n)=head_start(n) >*/
	feq_gen_item_start_d_[*n] = feq_gen_head_start_d_[*n];
/* SOURCE fqshrlin.for:1485 */
/*<       item_end(n)=item_start(n)+10-1 >*/
	feq_gen_item_end_d_[*n] = feq_gen_item_start_d_[*n] + 9;
/* SOURCE fqshrlin.for:1486 */
/*<       else >*/
    } else {
/*       Use right justification to set the limits */
/*       Do the first item.  Always starts in column 1. */
/* SOURCE fqshrlin.for:1489 */
/*<       item_start(1)=1 >*/
	feq_gen_item_start_d_[1] = 1;
/* SOURCE fqshrlin.for:1490 */
/*<       item_end(1)=head_end(1) >*/
	feq_gen_item_end_d_[1] = feq_gen_head_end_d_[1];
/* SOURCE fqshrlin.for:1491 */
/*<       do110i=2,n >*/
	feq_gen_i_d_1 = *n;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrlin.for:1492 */
/*<       item_start(i)=head_end(i-1)+1 >*/
	    feq_gen_item_start_d_[feq_gen_i_d_] = feq_gen_head_end_d_[feq_gen_i_d_ - 1] + 1;
/* SOURCE fqshrlin.for:1493 */
/*<       item_end(i)=head_end(i) >*/
	    feq_gen_item_end_d_[feq_gen_i_d_] = feq_gen_head_end_d_[feq_gen_i_d_];
/* SOURCE fqshrlin.for:1494 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE fqshrlin.for:1495 */
/*<       endif >*/
    }
/* SOURCE fqshrlin.for:1496 */
/*<       return >*/
    return 0;
/* SOURCE fqshrlin.for:1497 */
/*<       end >*/
} /* get_item_limits_storage__ */

#ifdef __cplusplus
	}
#endif
