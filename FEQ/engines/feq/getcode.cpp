/* getcode.f -- translated by f2c (version 20240504).
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
static integer feq_gen_c_d_40 = 40;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_20 = 20;

/*     *********** */
/*     *         * */
/*     * REPLACE_IDENTIFIERS */
/*     *         * */
/*     *********** */
/* SOURCE getcode.for:7 */
/*<        >*/
/* Subroutine */ int feq_gen_replace_identifiers_d_(integer *stdout, integer *
	feq_gen_max_nval_d_, integer *mode, integer *nval, char *feq_storage_cval, integer *feq_storage_clen, 
	integer *feq_gen_feq_storage_item_type_d_, integer *eflag, ftnlen cval_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *WRN:52* Name= \002,a,\002 is unknown in\
 an instruction.\002,\002  May cause later errors.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsli(icilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_rsli();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_find_internal_tab_number_d_(char *, integer *, 
	    ftnlen), feq_gen_ls_global_d_(char *, integer *, integer *, integer *, 
	    ftnlen);
    integer is;
    char key[16];
    integer indx;
    char work[16];
    integer feq_gen_class_d_, value;
    extern integer lenstr_(char *, ftnlen);
    integer lookup;
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_50, 0 };


/*     Scan the list of items and replace any unknown identifiers */
/*     with their value from the symbol table. */
/* SOURCE getcode.for:14 */
/*<       implicitnone >*/
/* SOURCE getcode.for:15 */
/*<        >*/
/* SOURCE getcode.for:18 */
/*<       charactercval(max_nval)*(*) >*/
/*     Local */
/* SOURCE getcode.for:22 */
/*<       integeris,intval,chrval,i,class,indx,value,lookup >*/
/* SOURCE getcode.for:24 */
/*<       parameter(intval=1,chrval=4) >*/
/* SOURCE getcode.for:26 */
/*<       characterwork*16,key*16 >*/
/* SOURCE getcode.for:28 */
/*<       integerlenstr >*/
/* SOURCE getcode.for:29 */
/*<       externallenstr,ls_global,strip_l_blanks,find_internal_tab_number >*/
/*     ******************************FORMATS***************************** */
/* SOURCE getcode.for:32 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE getcode.for:35 */
/*<       if(mode.eq.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, cval_len);

    /* Function Body */
/* L50: */
    if (*mode == 0) {
/*       Skip the first item in the list-it is the instruction name or */
/*       the macro name. */
/* SOURCE getcode.for:38 */
/*<       is=2 >*/
	is = 2;
/* SOURCE getcode.for:39 */
/*<       else >*/
    } else {
/*       This is a continuation line.  Start at the first item. */
/* SOURCE getcode.for:41 */
/*<       is=1 >*/
	is = 1;
/* SOURCE getcode.for:42 */
/*<       endif >*/
    }
/*     Find all items of type character value, skip any that are */
/*     predefined, and lookup the rest in the symbol table. */
/* SOURCE getcode.for:47 */
/*<       do200i=is,nval >*/
    feq_gen_i_d_1 = *nval;
    for (feq_gen_i_d_ = is; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       Clear the lookup flag */
/* SOURCE getcode.for:49 */
/*<       lookup=0 >*/
	lookup = 0;
/* SOURCE getcode.for:51 */
/*<       if(item_type(i).eq.chrval)then >*/
	if (feq_gen_item_type_d_[feq_gen_i_d_] == 4) {
/*         Eliminate predefined values. */
/* SOURCE getcode.for:53 */
/*<       if(clen(i).eq.1)then >*/
	    if (clen[feq_gen_i_d_] == 1) {
/* SOURCE getcode.for:54 */
/*<       if(cval(i).ne.'U'.and.cval(i).ne.'D'.and.cval(i).ne.'F')then >*/
		if (s_cmp(cval + feq_gen_i_d_ * cval_len, const_cast<char*>("U"), cval_len, (ftnlen)1) != 
			0 && s_cmp(cval + feq_gen_i_d_ * cval_len, const_cast<char*>("D"), cval_len, (
			ftnlen)1) != 0 && s_cmp(cval + feq_gen_i_d_ * cval_len, const_cast<char*>("F"), 
			cval_len, (ftnlen)1) != 0) {
/*             Unknown identifier of length 1. */
/* SOURCE getcode.for:57 */
/*<       lookup=1 >*/
		    lookup = 1;
/* SOURCE getcode.for:58 */
/*<       endif >*/
		}
/* SOURCE getcode.for:59 */
/*<       else >*/
	    } else {
/*           Identifier is longer than 1 character. */
/* SOURCE getcode.for:61 */
/*<        >*/
		if (*(unsigned char *)&cval[feq_gen_i_d_ * cval_len] != 'U' && *(
			unsigned char *)&cval[feq_gen_i_d_ * cval_len] != 'D' && *(
			unsigned char *)&cval[feq_gen_i_d_ * cval_len] != 'F') {
/*             Unknown identifier of length greater than 1 */
/*             which cannot be predefined. */
/* SOURCE getcode.for:66 */
/*<       lookup=1 >*/
		    lookup = 1;
/* SOURCE getcode.for:67 */
/*<       else >*/
		} else {
/*             Identifer begins with U, D, or F, is more */
/*             than 1 character long.  May be predefined */
/*             if it references an exterior node. */
/* SOURCE getcode.for:71 */
/*<       read(cval(i)(2:clen(i)),*,err=110)value >*/
		    feq_gen_ici_d_1.icierr = 1;
		    feq_gen_ici_d_1.iciend = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_] - 1;
		    feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ * cval_len + 1);
		    feq_gen_ici_d_1.icifmt = 0;
		    feq_gen_i_d_2 = s_rsli(&feq_gen_ici_d_1);
		    if (feq_gen_i_d_2 != 0) {
			goto L110;
		    }
		    feq_gen_i_d_2 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&value, (ftnlen)
			    sizeof(integer));
		    if (feq_gen_i_d_2 != 0) {
			goto L110;
		    }
		    feq_gen_i_d_2 = e_rsli();
		    if (feq_gen_i_d_2 != 0) {
			goto L110;
		    }
/*               Characters after first char are an integer. */
/* SOURCE getcode.for:73 */
/*<       if(value.gt.9999)then >*/
		    if (value > 9999) {
/* SOURCE getcode.for:74 */
/*<       lookup=1 >*/
			lookup = 1;
/* SOURCE getcode.for:75 */
/*<       endif >*/
		    }
/* SOURCE getcode.for:76 */
/*<       goto120 >*/
		    goto L120;
/* SOURCE getcode.for:77 */
/*<   110 continue >*/
L110:
/*               Character after first char not an integer. */
/*               The identifier is unknown. */
/* SOURCE getcode.for:81 */
/*<       lookup=1 >*/
		    lookup = 1;
/* SOURCE getcode.for:82 */
/*<   120 continue >*/
L120:
/* SOURCE getcode.for:83 */
/*<       endif >*/
		    ;
		}
/* SOURCE getcode.for:84 */
/*<       endif >*/
	    }
/* SOURCE getcode.for:85 */
/*<       if(lookup.eq.1)then >*/
	    if (lookup == 1) {
/*           We found an unknown identifier.  Look it up. */
/* SOURCE getcode.for:87 */
/*<       key=cval(i) >*/
		s_copy(key, cval + feq_gen_i_d_ * cval_len, (ftnlen)16, cval_len);
/* SOURCE getcode.for:88 */
/*<       callls_global(key,class,value,indx) >*/
		feq_gen_ls_global_d_(key, &feq_gen_class_d_, &value, &indx, (ftnlen)16);
/* SOURCE getcode.for:91 */
/*<       if(indx.eq.0)then >*/
		if (indx == 0) {
/*             See if it is a table id. */
/* SOURCE getcode.for:93 */
/*<       callfind_internal_tab_number(key,indx) >*/
		    feq_gen_find_internal_tab_number_d_(key, &indx, (ftnlen)16);
/* SOURCE getcode.for:96 */
/*<       if(indx.eq.0)then >*/
		    if (indx == 0) {
/* SOURCE getcode.for:97 */
/*<       if(cval(i)(1:3).ne.'TAB'.and.cval(i)(1:3).ne.'tab')then >*/
			if (s_cmp(cval + feq_gen_i_d_ * cval_len, const_cast<char*>("TAB"), (ftnlen)3, (
				ftnlen)3) != 0 && s_cmp(cval + feq_gen_i_d_ * cval_len,
				 const_cast<char*>("tab"), (ftnlen)3, (ftnlen)3) != 0) {
/* SOURCE getcode.for:98 */
/*<       write(stdout,50)cval(i)(1:clen(i)) >*/
			    feq_gen_io_d__8.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__8);
			    do_fio(&feq_gen_c_d_1, cval + feq_gen_i_d_ * cval_len, clen[feq_gen_i_d_]);
			    e_wsfe();
/* SOURCE getcode.for:99 */
/*<       endif >*/
			}
/* SOURCE getcode.for:100 */
/*<       endif >*/
		    }
/* SOURCE getcode.for:101 */
/*<       else >*/
		} else {
/* SOURCE getcode.for:102 */
/*<       write(work,'(I10)')value >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 16;
		    feq_gen_ici_d_1.iciunit = work;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I10)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(integer));
		    e_wsfi();
/* SOURCE getcode.for:103 */
/*<       callstrip_l_blanks(work) >*/
		    feq_gen_strip_l_blanks_d_(work, (ftnlen)16);
/* SOURCE getcode.for:105 */
/*<       clen(i)=lenstr(work) >*/
		    clen[feq_gen_i_d_] = lenstr_(work, (ftnlen)16);
/* SOURCE getcode.for:106 */
/*<       item_type(i)=intval >*/
		    feq_gen_item_type_d_[feq_gen_i_d_] = 1;
/* SOURCE getcode.for:107 */
/*<       cval(i)=work >*/
		    s_copy(cval + feq_gen_i_d_ * cval_len, work, cval_len, (ftnlen)16);
/* SOURCE getcode.for:108 */
/*<       endif >*/
		}
/* SOURCE getcode.for:109 */
/*<       endif >*/
	    }
/* SOURCE getcode.for:110 */
/*<       endif >*/
	}
/* SOURCE getcode.for:111 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE getcode.for:112 */
/*<       return >*/
    return 0;
/* SOURCE getcode.for:113 */
/*<       end >*/
} /* replace_identifiers__ */

/*     *********** */
/*     *         * */
/*     * PRESCAN */
/*     *         * */
/*     *********** */
/* SOURCE getcode.for:121 */
/*<        >*/
/* Subroutine */ int prescan_(integer *stdout, integer *feq_gen_max_nval_d_, integer *
	mode, integer *nval, char *feq_storage_cval, integer *feq_storage_clen, integer *feq_gen_feq_storage_item_type_d_, 
	char *feq_storage_term, integer *feq_storage_terml, integer *feq_storage_termcls, integer *feq_storage_ival, integer *
	eflag, ftnlen cval_len, ftnlen term_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:288* Argument: \002,a,\002 before a\
 + or - is not a\002,\002 valid exterior-node label.\002)";
    static char fmt_52[] = "(/,\002 *ERR:289* Argument: \002,a,\002 followin\
g a + or - is\002,\002 not an integer.\002)";
    static char fmt_54[] = "(/,\002 *ERR:290* Decrementing \002,i8,\002 by\
 \002,i8,\002 yields a\002,\002 negative result.\002)";
    static char fmt_56[] = "(/,\002 *ERR:291* A replication factor \002,a\
,\002 is not an\002,\002 integer.\002)";
    static char fmt_58[] = "(/,\002 *ERR:292* Replication factor=\002,i5,\
\002 is < 2\002)";

    /* System generated locals */
    address feq_gen_a_d_1[3];
    integer feq_gen_i_d_1, feq_gen_i_d_2[3];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli(), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), e_wsfi();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, n, replicate;
    char increment[15];
    integer is;
    char chr[1];
    extern /* Subroutine */ int feq_gen_replace_identifiers_d_(integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, integer *, 
	    ftnlen);
    integer iget, left, iput;
    char work[128];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer feq_gen_n_add_d_, right, idflag;
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__21 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__26 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_56, 0 };


/*     Do several scans of the list of items processing the */
/*     incrementation, decrementation, concatenation, and */
/*     replication operators that appear, if any. */
/* SOURCE getcode.for:130 */
/*<       implicitnone >*/
/* SOURCE getcode.for:131 */
/*<        >*/
/* SOURCE getcode.for:135 */
/*<       charactercval(max_nval)*(*),term(max_nval)*1 >*/
/*     Local */
/* SOURCE getcode.for:139 */
/*<        >*/
/* SOURCE getcode.for:143 */
/*<       parameter(asterisk=2,plus_or_minus=3,vertical_bar=17) >*/
/* SOURCE getcode.for:144 */
/*<       parameter(intval=1,reaval=2,dprval=3,chrval=4) >*/
/* SOURCE getcode.for:146 */
/*<       characterchr*1,work*128,increment*15 >*/
/* SOURCE getcode.for:148 */
/*<       integerlen_trim >*/
/*     ***********************FORMATS************************************ */
/* SOURCE getcode.for:121 */
/*<       integer feq_len_trim >*/
/* SOURCE getcode.for:121 */
/*<       external feq_len_trim >*/
/* SOURCE getcode.for:150 */
/*<    50  >*/
/* SOURCE getcode.for:152 */
/*<    52  >*/
/* SOURCE getcode.for:154 */
/*<    54  >*/
/* SOURCE getcode.for:156 */
/*<    56  >*/
/* SOURCE getcode.for:158 */
/*<    58 format(/,' *ERR:292* Replication factor=',i5,' is < 2') >*/
/* *********************************************************************** */
/* SOURCE getcode.for:160 */
/*<       if(mode.eq.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ival(feq_storage_ival, 1);

    feq::IndexedPointer<integer> termcls(feq_storage_termcls, 1);

    feq::IndexedPointer<integer> terml(feq_storage_terml, 1);

    feq::IndexedPointer<char> term(feq_storage_term, 1);

    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, cval_len);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
    if (*mode == 0) {
/*       Skip the first item in the list-it is the instruction name or */
/*       the macro name. */
/* SOURCE getcode.for:163 */
/*<       is=2 >*/
	is = 2;
/* SOURCE getcode.for:164 */
/*<       iget=2 >*/
	iget = 2;
/* SOURCE getcode.for:165 */
/*<       else >*/
    } else {
/*       This is a continuation line.  Start at the first item. */
/* SOURCE getcode.for:167 */
/*<       is=1 >*/
	is = 1;
/* SOURCE getcode.for:168 */
/*<       iget=1 >*/
	iget = 1;
/* SOURCE getcode.for:169 */
/*<       endif >*/
    }
/*     Do a scan of the arguments to lookup any identifiers. */
/* SOURCE getcode.for:173 */
/*<        >*/
    feq_gen_replace_identifiers_d_(stdout, feq_gen_max_nval_d_, mode, nval, cval + cval_len, &
	    clen[1], &feq_gen_item_type_d_[1], eflag, cval_len);
/*     Now move items in the list and check for the plus/minus operator. */
/* SOURCE getcode.for:178 */
/*<   100 continue >*/
L100:
/* SOURCE getcode.for:179 */
/*<       if(termcls(iget).eq.plus_or_minus)then >*/
    if (termcls[iget] == 3) {
/*         Do the operation.  Convert the first operand. */
/* SOURCE getcode.for:181 */
/*<       if(item_type(iget).eq.intval)then >*/
	if (feq_gen_item_type_d_[iget] == 1) {
/* SOURCE getcode.for:182 */
/*<       idflag=0 >*/
	    idflag = 0;
/* SOURCE getcode.for:183 */
/*<       read(cval(iget),*)left >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = cval_len;
	    feq_gen_ici_d_1.iciunit = cval + iget * cval_len;
	    feq_gen_ici_d_1.icifmt = 0;
	    s_rsli(&feq_gen_ici_d_1);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&left, (ftnlen)sizeof(integer));
	    e_rsli();
/* SOURCE getcode.for:184 */
/*<       elseif(item_type(iget).eq.chrval)then >*/
	} else if (feq_gen_item_type_d_[iget] == 4) {
/*           Item must be a exterior node label. */
/*           Maybe a TAB or tab-trying to get this implemented */
/* SOURCE getcode.for:187 */
/*<       idflag=1 >*/
	    idflag = 1;
/* SOURCE getcode.for:188 */
/*<       chr=cval(iget)(1:1) >*/
	    *(unsigned char *)chr = *(unsigned char *)&cval[iget * cval_len];
/* SOURCE getcode.for:189 */
/*<       if(chr.eq.'F'.or.chr.eq.'D'.or.chr.eq.'U')then >*/
	    if (*(unsigned char *)chr == 'F' || *(unsigned char *)chr == 'D' 
		    || *(unsigned char *)chr == 'U') {
/*             First character is ok.  Try to convert the integer part. */
/* SOURCE getcode.for:191 */
/*<       read(cval(iget)(2:),*,err=110)left >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = cval_len - 1;
		feq_gen_ici_d_1.iciunit = cval + (iget * cval_len + 1);
		feq_gen_ici_d_1.icifmt = 0;
		feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L110;
		}
		feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&left, (ftnlen)sizeof(
			integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L110;
		}
		feq_gen_i_d_1 = e_rsli();
		if (feq_gen_i_d_1 != 0) {
		    goto L110;
		}
/* SOURCE getcode.for:192 */
/*<       goto120 >*/
		goto L120;
/* SOURCE getcode.for:193 */
/*<   110 continue >*/
L110:
/* SOURCE getcode.for:194 */
/*<       write(stdout,50)cval(iget)(1:clen(iget)) >*/
		feq_gen_io_d__15.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__15);
		do_fio(&feq_gen_c_d_1, cval + iget * cval_len, clen[iget]);
		e_wsfe();
/* SOURCE getcode.for:195 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE getcode.for:196 */
/*<   120 continue >*/
L120:
/* SOURCE getcode.for:197 */
/*<       elseif(cval(iget)(1:3)=='TAB'.or.cval(iget)(1:3)=='tab')then >*/
		;
	    } else if (s_cmp(cval + iget * cval_len, const_cast<char*>("TAB"), (ftnlen)3, (
		    ftnlen)3) == 0 || s_cmp(cval + iget * cval_len, const_cast<char*>("tab"), (
		    ftnlen)3, (ftnlen)3) == 0) {
/*             Process adjustment to a datum not yet known. */
/*             We will combine into a single string and pass */
/*             it on to the next level for processing. */
/* SOURCE getcode.for:202 */
/*<       idflag=2 >*/
		idflag = 2;
/* SOURCE getcode.for:203 */
/*<       else >*/
	    } else {
/* SOURCE getcode.for:204 */
/*<       write(stdout,50)cval(iget)(1:clen(iget)) >*/
		feq_gen_io_d__16.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__16);
		do_fio(&feq_gen_c_d_1, cval + iget * cval_len, clen[iget]);
		e_wsfe();
/* SOURCE getcode.for:205 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE getcode.for:206 */
/*<       endif >*/
	    }
/* SOURCE getcode.for:207 */
/*<       else >*/
	} else {
/* SOURCE getcode.for:208 */
/*<       write(stdout,50)cval(iget)(1:clen(iget)) >*/
	    feq_gen_io_d__17.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__17);
	    do_fio(&feq_gen_c_d_1, cval + iget * cval_len, clen[iget]);
	    e_wsfe();
/* SOURCE getcode.for:209 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE getcode.for:210 */
/*<       endif >*/
	}
/*         Convert the second operand.  Could be integer, real, or double */
/* SOURCE getcode.for:213 */
/*<       if(item_type(iget+1).eq.intval)then >*/
	if (feq_gen_item_type_d_[iget + 1] == 1) {
/* SOURCE getcode.for:214 */
/*<       read(cval(iget+1),*)right >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = cval_len;
	    feq_gen_ici_d_1.iciunit = cval + (iget + 1) * cval_len;
	    feq_gen_ici_d_1.icifmt = 0;
	    s_rsli(&feq_gen_ici_d_1);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&right, (ftnlen)sizeof(integer));
	    e_rsli();
/* SOURCE getcode.for:215 */
/*<        >*/
	} else if (feq_gen_item_type_d_[iget + 1] == 2 || feq_gen_item_type_d_[iget + 1] == 3) {
/*           Extract the string */
/* SOURCE getcode.for:218 */
/*<       increment=cval(iget+1) >*/
	    s_copy(increment, cval + (iget + 1) * cval_len, (ftnlen)15, 
		    cval_len);
/* SOURCE getcode.for:219 */
/*<       else >*/
	} else {
/* SOURCE getcode.for:220 */
/*<       write(stdout,52)cval(iget+1)(1:clen(iget+1)) >*/
	    feq_gen_io_d__20.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__20);
	    do_fio(&feq_gen_c_d_1, cval + (iget + 1) * cval_len, clen[iget + 1]);
	    e_wsfe();
/* SOURCE getcode.for:221 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE getcode.for:222 */
/*<       endif >*/
	}
/*         Now do the operation. */
/* SOURCE getcode.for:225 */
/*<       if(idflag/=2)then >*/
	if (idflag != 2) {
/* SOURCE getcode.for:226 */
/*<       if(term(iget).eq.'+')then >*/
	    if (*(unsigned char *)&term[iget] == '+') {
/* SOURCE getcode.for:227 */
/*<       left=left+right >*/
		left += right;
/* SOURCE getcode.for:228 */
/*<       else >*/
	    } else {
/* SOURCE getcode.for:229 */
/*<       left=left-right >*/
		left -= right;
/* SOURCE getcode.for:230 */
/*<       if(left.le.0)then >*/
		if (left <= 0) {
/* SOURCE getcode.for:231 */
/*<       write(stdout,54)left,right >*/
		    feq_gen_io_d__21.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__21);
		    do_fio(&feq_gen_c_d_1, (char *)&left, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&right, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE getcode.for:232 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE getcode.for:233 */
/*<       endif >*/
		}
/* SOURCE getcode.for:234 */
/*<       endif >*/
	    }
/*           Now create the character-string form of the result. */
/* SOURCE getcode.for:238 */
/*<       write(work,'(I10)')left >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 128;
	    feq_gen_ici_d_1.iciunit = work;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I10)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&left, (ftnlen)sizeof(integer));
	    e_wsfi();
/* SOURCE getcode.for:239 */
/*<       callstrip_l_blanks(work) >*/
	    feq_gen_strip_l_blanks_d_(work, (ftnlen)128);
/* SOURCE getcode.for:241 */
/*<       if(idflag.eq.0)then >*/
	    if (idflag == 0) {
/* SOURCE getcode.for:242 */
/*<       cval(is)=work >*/
		s_copy(cval + is * cval_len, work, cval_len, (ftnlen)128);
/* SOURCE getcode.for:243 */
/*<       else >*/
	    } else {
/* SOURCE getcode.for:244 */
/*<       cval(is)(1:1)=chr >*/
		*(unsigned char *)&cval[is * cval_len] = *(unsigned char *)
			chr;
/* SOURCE getcode.for:245 */
/*<       cval(is)(2:)=work >*/
		s_copy(cval + (is * cval_len + 1), work, cval_len - 1, (
			ftnlen)128);
/* SOURCE getcode.for:246 */
/*<       endif >*/
	    }
/* SOURCE getcode.for:247 */
/*<       else >*/
	} else {
/*           concatenate the increment back onto the */
/*           TAB or tab so that it is passed to the next level */
/* SOURCE getcode.for:251 */
/*<       cval(is)='TAB'//term(iget)//increment >*/
/* Writing concatenation */
	    feq_gen_i_d_2[0] = 3, feq_gen_a_d_1[0] = const_cast<char*>("TAB");
	    feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = term + iget;
	    feq_gen_i_d_2[2] = 15, feq_gen_a_d_1[2] = increment;
	    s_cat(cval + is * cval_len, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_3, cval_len);
/* SOURCE getcode.for:252 */
/*<       endif >*/
	}
/* SOURCE getcode.for:253 */
/*<       clen(is)=feq_len_trim(cval(is)) >*/
	clen[is] = feq_gen_feq_len_trim_d_(cval + is * cval_len, cval_len);
/* SOURCE getcode.for:254 */
/*<       item_type(is)=item_type(iget) >*/
	feq_gen_item_type_d_[is] = feq_gen_item_type_d_[iget];
/* SOURCE getcode.for:255 */
/*<       term(is)=term(iget+1) >*/
	*(unsigned char *)&term[is] = *(unsigned char *)&term[iget + 1];
/* SOURCE getcode.for:256 */
/*<       termcls(is)=termcls(iget+1) >*/
	termcls[is] = termcls[iget + 1];
/* SOURCE getcode.for:257 */
/*<       terml(is)=terml(iget+1) >*/
	terml[is] = terml[iget + 1];
/* SOURCE getcode.for:259 */
/*<       is=is+1 >*/
	++is;
/*         Skip over the operand just processed. */
/* SOURCE getcode.for:261 */
/*<       iget=iget+2 >*/
	iget += 2;
/* SOURCE getcode.for:262 */
/*<       if(iget.le.nval)goto100 >*/
	if (iget <= *nval) {
	    goto L100;
	}
/* SOURCE getcode.for:263 */
/*<       else >*/
    } else {
/* SOURCE getcode.for:264 */
/*<       cval(is)=cval(iget) >*/
	s_copy(cval + is * cval_len, cval + iget * cval_len, cval_len, 
		cval_len);
/* SOURCE getcode.for:265 */
/*<       clen(is)=clen(iget) >*/
	clen[is] = clen[iget];
/* SOURCE getcode.for:266 */
/*<       item_type(is)=item_type(iget) >*/
	feq_gen_item_type_d_[is] = feq_gen_item_type_d_[iget];
/* SOURCE getcode.for:267 */
/*<       term(is)=term(iget) >*/
	*(unsigned char *)&term[is] = *(unsigned char *)&term[iget];
/* SOURCE getcode.for:268 */
/*<       termcls(is)=termcls(iget) >*/
	termcls[is] = termcls[iget];
/* SOURCE getcode.for:269 */
/*<       terml(is)=terml(iget) >*/
	terml[is] = terml[iget];
/* SOURCE getcode.for:270 */
/*<       is=is+1 >*/
	++is;
/* SOURCE getcode.for:271 */
/*<       iget=iget+1 >*/
	++iget;
/* SOURCE getcode.for:272 */
/*<       if(iget.le.nval)goto100 >*/
	if (iget <= *nval) {
	    goto L100;
	}
/* SOURCE getcode.for:273 */
/*<       endif >*/
    }
/* SOURCE getcode.for:274 */
/*<       nval=is-1 >*/
    *nval = is - 1;
/*      WRITE(STDOUT,*) ' After first scan: NVAL=',NVAL */
/*      WRITE(STDOUT,97) */
/* 97    FORMAT(1X,12X,'ITEM','   LEN  TYPE T  TCLS') */
/*      DO 9213 I=1,NVAL */
/*        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I), */
/*     A                  TERMCLS(I) */
/* 99    FORMAT(' ',A16,' ',I5,' ',I5,' ',A1,' ',I5) */
/* 9213  CONTINUE */
/*     Now move items in the list and check for the concatenation operator. */
/* SOURCE getcode.for:287 */
/*<       if(mode.eq.0)then >*/
    if (*mode == 0) {
/*       Skip the first item in the list-it is the instruction name or */
/*       the macro name. */
/* SOURCE getcode.for:290 */
/*<       is=2 >*/
	is = 2;
/* SOURCE getcode.for:291 */
/*<       iget=2 >*/
	iget = 2;
/* SOURCE getcode.for:292 */
/*<       else >*/
    } else {
/*       This is a continuation line.  Start at the first item. */
/* SOURCE getcode.for:294 */
/*<       is=1 >*/
	is = 1;
/* SOURCE getcode.for:295 */
/*<       iget=1 >*/
	iget = 1;
/* SOURCE getcode.for:296 */
/*<       endif >*/
    }
/* SOURCE getcode.for:297 */
/*<   200 continue >*/
L200:
/* SOURCE getcode.for:298 */
/*<       if(termcls(iget).eq.vertical_bar)then >*/
    if (termcls[iget] == 17) {
/*         Do the operation. */
/* SOURCE getcode.for:300 */
/*<       cval(is)=cval(iget) >*/
	s_copy(cval + is * cval_len, cval + iget * cval_len, cval_len, 
		cval_len);
/* SOURCE getcode.for:301 */
/*<       cval(is)(clen(iget)+1:)=cval(iget+1) >*/
	feq_gen_i_d_1 = clen[iget];
	s_copy(cval + (is * cval_len + feq_gen_i_d_1), cval + (iget + 1) * cval_len, 
		cval_len - feq_gen_i_d_1, cval_len);
/* SOURCE getcode.for:302 */
/*<       clen(is)=feq_len_trim(cval(is)) >*/
	clen[is] = feq_gen_feq_len_trim_d_(cval + is * cval_len, cval_len);
/* SOURCE getcode.for:303 */
/*<       item_type(is)=item_type(iget) >*/
	feq_gen_item_type_d_[is] = feq_gen_item_type_d_[iget];
/* SOURCE getcode.for:304 */
/*<       term(is)=term(iget+1) >*/
	*(unsigned char *)&term[is] = *(unsigned char *)&term[iget + 1];
/* SOURCE getcode.for:305 */
/*<       termcls(is)=termcls(iget+1) >*/
	termcls[is] = termcls[iget + 1];
/* SOURCE getcode.for:306 */
/*<       terml(is)=terml(iget+1) >*/
	terml[is] = terml[iget + 1];
/* SOURCE getcode.for:308 */
/*<       is=is+1 >*/
	++is;
/*         Skip over the operand just processed. */
/* SOURCE getcode.for:310 */
/*<       iget=iget+2 >*/
	iget += 2;
/* SOURCE getcode.for:311 */
/*<       if(iget.le.nval)goto200 >*/
	if (iget <= *nval) {
	    goto L200;
	}
/* SOURCE getcode.for:312 */
/*<       else >*/
    } else {
/* SOURCE getcode.for:313 */
/*<       cval(is)=cval(iget) >*/
	s_copy(cval + is * cval_len, cval + iget * cval_len, cval_len, 
		cval_len);
/* SOURCE getcode.for:314 */
/*<       clen(is)=clen(iget) >*/
	clen[is] = clen[iget];
/* SOURCE getcode.for:315 */
/*<       item_type(is)=item_type(iget) >*/
	feq_gen_item_type_d_[is] = feq_gen_item_type_d_[iget];
/* SOURCE getcode.for:316 */
/*<       term(is)=term(iget) >*/
	*(unsigned char *)&term[is] = *(unsigned char *)&term[iget];
/* SOURCE getcode.for:317 */
/*<       termcls(is)=termcls(iget) >*/
	termcls[is] = termcls[iget];
/* SOURCE getcode.for:318 */
/*<       terml(is)=terml(iget) >*/
	terml[is] = terml[iget];
/* SOURCE getcode.for:319 */
/*<       is=is+1 >*/
	++is;
/* SOURCE getcode.for:320 */
/*<       iget=iget+1 >*/
	++iget;
/* SOURCE getcode.for:321 */
/*<       if(iget.le.nval)goto200 >*/
	if (iget <= *nval) {
	    goto L200;
	}
/* SOURCE getcode.for:322 */
/*<       endif >*/
    }
/* SOURCE getcode.for:323 */
/*<       nval=is-1 >*/
    *nval = is - 1;
/*     Now do the replication operations.  Need two passes. */
/*     The first computes the increased numbers of items. */
/*     The second does the transfer. */
/* SOURCE getcode.for:330 */
/*<       if(mode.eq.0)then >*/
    if (*mode == 0) {
/*       Skip the first item in the list-it is the instruction name or */
/*       the macro name. */
/* SOURCE getcode.for:333 */
/*<       is=1 >*/
	is = 1;
/* SOURCE getcode.for:334 */
/*<       iget=2 >*/
	iget = 2;
/* SOURCE getcode.for:335 */
/*<       else >*/
    } else {
/*       This is a continuation line.  Start at the first item. */
/* SOURCE getcode.for:337 */
/*<       is=0 >*/
	is = 0;
/* SOURCE getcode.for:338 */
/*<       iget=1 >*/
	iget = 1;
/* SOURCE getcode.for:339 */
/*<       endif >*/
    }
/* SOURCE getcode.for:340 */
/*<       n_add=0 >*/
    feq_gen_n_add_d_ = 0;
/* SOURCE getcode.for:341 */
/*<       replicate=0 >*/
    replicate = 0;
/* SOURCE getcode.for:342 */
/*<   300 continue >*/
L300:
/* SOURCE getcode.for:343 */
/*<       if(termcls(iget).eq.asterisk)then >*/
    if (termcls[iget] == 2) {
/*         Convert the replication factor. */
/* SOURCE getcode.for:345 */
/*<       replicate=1 >*/
	replicate = 1;
/* SOURCE getcode.for:346 */
/*<       if(item_type(iget).eq.intval)then >*/
	if (feq_gen_item_type_d_[iget] == 1) {
/* SOURCE getcode.for:347 */
/*<       read(cval(iget),*)n >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = cval_len;
	    feq_gen_ici_d_1.iciunit = cval + iget * cval_len;
	    feq_gen_ici_d_1.icifmt = 0;
	    s_rsli(&feq_gen_ici_d_1);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
	    e_rsli();
/* SOURCE getcode.for:348 */
/*<       if(n.le.1)then >*/
	    if (n <= 1) {
/* SOURCE getcode.for:349 */
/*<       write(stdout,58)n >*/
		feq_gen_io_d__26.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__26);
		do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE getcode.for:350 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE getcode.for:351 */
/*<       endif >*/
	    }
/* SOURCE getcode.for:352 */
/*<       ival(iget)=n >*/
	    ival[iget] = n;
/* SOURCE getcode.for:353 */
/*<       else >*/
	} else {
/* SOURCE getcode.for:354 */
/*<       write(stdout,56)cval(iget)(1:clen(iget)) >*/
	    feq_gen_io_d__27.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__27);
	    do_fio(&feq_gen_c_d_1, cval + iget * cval_len, clen[iget]);
	    e_wsfe();
/* SOURCE getcode.for:355 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE getcode.for:356 */
/*<       endif >*/
	}
/*         Compute the number of added items.  A replication */
/*         factor of 1 is invalid.  The replication factor itself */
/*         will be removed from the list.  Therefore, a factor */
/*         of 2 leaves the list length unchanged. */
/* SOURCE getcode.for:361 */
/*<       n_add=n_add+n-2 >*/
	feq_gen_n_add_d_ = feq_gen_n_add_d_ + n - 2;
/* SOURCE getcode.for:362 */
/*<       iget=iget+2 >*/
	iget += 2;
/* SOURCE getcode.for:363 */
/*<       else >*/
    } else {
/* SOURCE getcode.for:364 */
/*<       iget=iget+1 >*/
	++iget;
/* SOURCE getcode.for:365 */
/*<       endif >*/
    }
/* SOURCE getcode.for:366 */
/*<       if(iget.le.nval)goto300 >*/
    if (iget <= *nval) {
	goto L300;
    }
/* SOURCE getcode.for:368 */
/*<       if(replicate.eq.1)then >*/
    if (replicate == 1) {
/*         We have to do a replicate operation.  Scan the list */
/*         in reverse and transfer the values to the new locations */
/*         replicating arguments as required. */
/* SOURCE getcode.for:373 */
/*<       iput=nval+n_add >*/
	iput = *nval + feq_gen_n_add_d_;
/* SOURCE getcode.for:374 */
/*<       iget=nval >*/
	iget = *nval;
/* SOURCE getcode.for:376 */
/*<   400 continue >*/
L400:
/* SOURCE getcode.for:377 */
/*<       if(termcls(iget).eq.asterisk)then >*/
	if (termcls[iget] == 2) {
/*             One instance of the item being replicated has */
/*             already been transfered. Transfer it to */
/*             subsequent locations. */
/* SOURCE getcode.for:381 */
/*<       n=ival(iget)-1 >*/
	    n = ival[iget] - 1;
/* SOURCE getcode.for:382 */
/*<       do410i=iput,iput-n+1,-1 >*/
	    feq_gen_i_d_1 = iput - n + 1;
	    for (feq_gen_i_d_ = iput; feq_gen_i_d_ >= feq_gen_i_d_1; --feq_gen_i_d_) {
/* SOURCE getcode.for:383 */
/*<       cval(i)=cval(iput+1) >*/
		s_copy(cval + feq_gen_i_d_ * cval_len, cval + (iput + 1) * cval_len, 
			cval_len, cval_len);
/* SOURCE getcode.for:384 */
/*<       clen(i)=clen(iput+1) >*/
		clen[feq_gen_i_d_] = clen[iput + 1];
/* SOURCE getcode.for:385 */
/*<       item_type(i)=item_type(iput+1) >*/
		feq_gen_item_type_d_[feq_gen_i_d_] = feq_gen_item_type_d_[iput + 1];
/* SOURCE getcode.for:386 */
/*<       term(i)=term(iput+1) >*/
		*(unsigned char *)&term[feq_gen_i_d_] = *(unsigned char *)&term[iput + 
			1];
/* SOURCE getcode.for:387 */
/*<       termcls(i)=termcls(iput+1) >*/
		termcls[feq_gen_i_d_] = termcls[iput + 1];
/* SOURCE getcode.for:388 */
/*<       terml(i)=terml(iput+1) >*/
		terml[feq_gen_i_d_] = terml[iput + 1];
/* SOURCE getcode.for:389 */
/*<   410 continue >*/
/* L410: */
	    }
/* SOURCE getcode.for:390 */
/*<       iput=iput-n >*/
	    iput -= n;
/* SOURCE getcode.for:391 */
/*<       iget=iget-1 >*/
	    --iget;
/* SOURCE getcode.for:392 */
/*<       else >*/
	} else {
/*             Transfer the item. */
/* SOURCE getcode.for:394 */
/*<       cval(iput)=cval(iget) >*/
	    s_copy(cval + iput * cval_len, cval + iget * cval_len, cval_len, 
		    cval_len);
/* SOURCE getcode.for:395 */
/*<       clen(iput)=clen(iget) >*/
	    clen[iput] = clen[iget];
/* SOURCE getcode.for:396 */
/*<       item_type(iput)=item_type(iget) >*/
	    feq_gen_item_type_d_[iput] = feq_gen_item_type_d_[iget];
/* SOURCE getcode.for:397 */
/*<       term(iput)=term(iget) >*/
	    *(unsigned char *)&term[iput] = *(unsigned char *)&term[iget];
/* SOURCE getcode.for:398 */
/*<       termcls(iput)=termcls(iget) >*/
	    termcls[iput] = termcls[iget];
/* SOURCE getcode.for:399 */
/*<       terml(iput)=terml(iget) >*/
	    terml[iput] = terml[iget];
/* SOURCE getcode.for:400 */
/*<       iput=iput-1 >*/
	    --iput;
/* SOURCE getcode.for:401 */
/*<       iget=iget-1 >*/
	    --iget;
/* SOURCE getcode.for:402 */
/*<       endif >*/
	}
/* SOURCE getcode.for:403 */
/*<       if(iget.gt.is)goto400 >*/
	if (iget > is) {
	    goto L400;
	}
/* SOURCE getcode.for:404 */
/*<       endif >*/
    }
/* SOURCE getcode.for:405 */
/*<       return >*/
    return 0;
/* SOURCE getcode.for:406 */
/*<       end >*/
} /* prescan_ */





/* SOURCE getcode.for:412 */
/*<       subroutineto_upper(string) >*/
/* Subroutine */ int feq_gen_to_upper_d_(char *string, ftnlen string_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer i_len(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, ich, iend;


/*     Convert a character string from lower case to upper case */
/*     Modified from USGS routine. */
/* SOURCE getcode.for:418 */
/*<       implicitnone >*/
/* SOURCE getcode.for:419 */
/*<       character*(*)string >*/
/*     + + + ARGUMENT DEFINITIONS + + + */
/*     STRING - character string to be made upper case */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE getcode.for:425 */
/*<       integeri,ich,iend >*/
/*     + + + INTRINSICS + + + */
/* SOURCE getcode.for:428 */
/*<       intrinsicichar,len,char >*/
/* *********************************************************************** */
/* SOURCE getcode.for:430 */
/*<       iend=len(string) >*/
    iend = i_len(string, string_len);
/* SOURCE getcode.for:431 */
/*<       do10i=1,iend >*/
    feq_gen_i_d_1 = iend;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE getcode.for:432 */
/*<       ich=ichar(string(i:i)) >*/
	ich = *(unsigned char *)&string[feq_gen_i_d_ - 1];
/* SOURCE getcode.for:433 */
/*<       if(ich.ge.97.and.ich.le.122)then >*/
	if (ich >= 97 && ich <= 122) {
/*         Character is lower case. */
/* SOURCE getcode.for:435 */
/*<       string(i:i)=char(ich-32) >*/
	    *(unsigned char *)&string[feq_gen_i_d_ - 1] = (char) (ich - 32);
/* SOURCE getcode.for:436 */
/*<       endif >*/
	}
/* SOURCE getcode.for:437 */
/*<    10 continue >*/
/* L10: */
    }
/* SOURCE getcode.for:439 */
/*<       return >*/
    return 0;
/* SOURCE getcode.for:440 */
/*<       end >*/
} /* to_upper__ */

/*     *********** */
/*     *         * */
/*     * GET_CODE_NC_F */
/*     *         * */
/*     *********** */
/* SOURCE getcode.for:448 */
/*<        >*/
/* Subroutine */ int feq_gen_get_code_nc_f_d_(integer *stdout, integer *mode, char *
	feq_gen_long_line_d_, integer *code, char *feq_storage_nc, char *feq_gen_feq_storage_nc_long_d_, real *feq_storage_f, char *
	feq_storage_fc, integer *eflag, ftnlen long_line_len, ftnlen nc_len, ftnlen 
	nc_long_len, ftnlen fc_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG* in GET_CODE_NC_F: No values found \
in line.\002)";
    static char fmt_52[] = "(/,\002 *ERR:293* First value on line:\002,a8\
,\002 not valid for\002,\002 CODE.\002)";
    static char fmt_54[] = "(/,\002 *ERR:294* Too many values. Float values \
MUST have\002,\002 a decimal point present.\002)";
    static char fmt_56[] = "(/,\002 *ERR:295* Wrong type. Make sure float va\
lues have a\002,\002 decimal point present.\002)";
    static char fmt_58[] = "(/,\002 *ERR:296 Too many float values.\002)";
    static char fmt_60[] = "(/,\002 *ERR:297* Instruction named: \002,a,\002\
 not known.  Check\002,\002 spelling here\002,/,5x,\002and in DEFINE MACROS \
block.\002)";
    static char fmt_62[] = "(/,\002 Found macro instruction: \002,a)";
    static char fmt_64[] = "(/,\002 Found instruction: \002,a)";
    static char fmt_98[] = "(/,\002 Current instruction line:\002,/,1x,a)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(), s_rsli(icilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_rsli();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_ls_global_d_(char *, integer *, integer *, 
	    integer *, ftnlen);
    integer feq_gen_init_iknt_d_, feq_gen_item_type_d_[40], it, feq_gen_non_int_id_d_, opt;
    char instruction[16];
    integer clen[40];
    char cval[256*40], line[200];
    integer ival[40], nval, fknt, indx;
    real rval[40];
    integer iknt;
    char term[1*40];
    extern /* Subroutine */ int feq_gen_insert_argument_knt_d_(integer *, integer *, 
	    char *, integer *, integer *, char *, integer *, integer *, 
	    ftnlen, ftnlen), feq_gen_expand_macro_d_(integer *, integer *, integer *, 
	    char *, integer *, integer *, ftnlen);
    integer feq_gen_class_d_;
    doublereal dpval[40];
    integer value, terml[40];
    extern /* Subroutine */ int getval_(integer *, char *, integer *, integer 
	    *, integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    integer ilimit, istart;
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int prescan_(integer *, integer *, integer *, 
	    integer *, char *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, ftnlen, ftnlen);
    integer termcls[40];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__55 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__56 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_58, 0 };


/*     Process the items in LONG_LINE and create values */
/*     for CODE, NC, and F. */
/*     Dummy Arguments */
/* SOURCE getcode.for:456 */
/*<       implicitnone >*/
/* SOURCE getcode.for:457 */
/*<       integercode,eflag,mode,stdout >*/
/* SOURCE getcode.for:458 */
/*<       realf(5) >*/
/* SOURCE getcode.for:459 */
/*<       characternc(10)*5,long_line*196,nc_long(10)*16,fc(5)*4 >*/
/*     Local variables */
/* SOURCE getcode.for:464 */
/*<       characterline*200 >*/
/* SOURCE getcode.for:466 */
/*<       integermax_nval >*/
/* SOURCE getcode.for:468 */
/*<       parameter(max_nval=40) >*/
/* SOURCE getcode.for:470 */
/*<       integerchrval,continuation_value,intval,reaval,dprval,place_holder >*/
/* SOURCE getcode.for:472 */
/*<        >*/
/* SOURCE getcode.for:475 */
/*<       integermacro_class,instruction_class,variable_arguments_class >*/
/* SOURCE getcode.for:476 */
/*<        >*/
/* SOURCE getcode.for:479 */
/*<       integersemicolon >*/
/* SOURCE getcode.for:480 */
/*<       parameter(semicolon=20) >*/
/* SOURCE getcode.for:482 */
/*<        >*/
/* SOURCE getcode.for:485 */
/*<        >*/
/* SOURCE getcode.for:487 */
/*<       realrval(max_nval) >*/
/* SOURCE getcode.for:488 */
/*<       real*8dpval(max_nval) >*/
/* SOURCE getcode.for:489 */
/*<       charactercval(max_nval)*256,term(max_nval)*1,instruction*16 >*/
/* SOURCE getcode.for:492 */
/*<       integerlenstr >*/
/* SOURCE getcode.for:493 */
/*<       externalto_upper,ls_global,lenstr >*/
/*     *********************************FORMATS************************** */
/* SOURCE getcode.for:496 */
/*<    50 format(/,' *BUG* in GET_CODE_NC_F: No values found in line.') >*/
/* SOURCE getcode.for:497 */
/*<    52  >*/
/* SOURCE getcode.for:499 */
/*<    54  >*/
/* SOURCE getcode.for:501 */
/*<    56  >*/
/* SOURCE getcode.for:503 */
/*<    58 format(/,' *ERR:296 Too many float values.') >*/
/* SOURCE getcode.for:504 */
/*<    60  >*/
/* SOURCE getcode.for:506 */
/*<    62 format(/,' Found macro instruction: ',a) >*/
/* SOURCE getcode.for:507 */
/*<    64 format(/,' Found instruction: ',a) >*/
/* *********************************************************************** */
/*     Clear the target variables. */
/* SOURCE getcode.for:510 */
/*<       do95i=1,10 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> fc(feq_storage_fc, 4);

    feq::IndexedPointer<real> f(feq_storage_f, 1);

    feq::IndexedPointer<char> feq_gen_nc_long_d_(feq_gen_feq_storage_nc_long_d_, 16);

    feq::IndexedPointer<char> nc(feq_storage_nc, 5);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 10; ++feq_gen_i_d_) {
/* SOURCE getcode.for:511 */
/*<       nc(i)=' ' >*/
	s_copy(nc + feq_gen_i_d_ * 5, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1);
/* SOURCE getcode.for:512 */
/*<       nc_long(i)=' ' >*/
	s_copy(feq_gen_nc_long_d_ + (feq_gen_i_d_ << 4), const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE getcode.for:513 */
/*<    95 continue >*/
/* L95: */
    }
/* SOURCE getcode.for:514 */
/*<       do96i=1,5 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 5; ++feq_gen_i_d_) {
/* SOURCE getcode.for:515 */
/*<       f(i)=0.0 >*/
	f[feq_gen_i_d_] = (float)0.;
/*       Set information to check for missing float values */
/*       so they do not get set to zero as a default. */
/* SOURCE getcode.for:518 */
/*<       fc(i)='NONE' >*/
	s_copy(fc + (feq_gen_i_d_ << 2), const_cast<char*>("NONE"), (ftnlen)4, (ftnlen)4);
/* SOURCE getcode.for:519 */
/*<    96 continue >*/
/* L96: */
    }
/* SOURCE getcode.for:521 */
/*<       line=long_line >*/
    s_copy(line, feq_gen_long_line_d_, (ftnlen)200, (ftnlen)196);
/* SOURCE getcode.for:522 */
/*<       it=lenstr(line) >*/
    it = lenstr_(line, (ftnlen)200);
/*     Search for user given quote. */
/* SOURCE getcode.for:524 */
/*<       i=index(line(1:it),'''') >*/
    feq_gen_i_d_ = i_indx(line, const_cast<char*>("'"), it, (ftnlen)1);
/* SOURCE getcode.for:525 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE getcode.for:526 */
/*<       line(it+1:it+1)='''' >*/
	feq_gen_i_d_1 = it;
	s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/*      ELSE */
/*       Revise user quote to  ,quote */
/*        LINE(I:I+2) = ' ,''' */
/*        IT = I */
/* SOURCE getcode.for:531 */
/*<       endif >*/
    }
/* SOURCE getcode.for:533 */
/*<       write(stdout,98)line(1:it) >*/
    feq_gen_io_d__36.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__36);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE getcode.for:534 */
/*<    98 format(/,' Current instruction line:',/,1x,a) >*/
/*     Select the option to return what is found with no */
/*     expectations being enforced. */
/* SOURCE getcode.for:539 */
/*<       opt=1 >*/
    opt = 1;
/* SOURCE getcode.for:540 */
/*<        >*/
    getval_(stdout, line, &feq_gen_c_d_40, &opt, feq_gen_item_type_d_, ival, rval, dpval, cval, 
	    clen, eflag, term, terml, termcls, &nval, (ftnlen)200, (ftnlen)
	    256, (ftnlen)1);
/*      WRITE(STDOUT,*) ' Return from GETVAL in GET_CODE_NC_F: NVAL=',NVAL */
/*      WRITE(STDOUT,97) */
/* 97    FORMAT(1X,12X,'ITEM','   LEN  TYPE T  TCLS') */
/*      DO 9213 I=1,NVAL */
/*        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I), */
/*     A                  TERMCLS(I) */
/* 99    FORMAT(' ',A16,' ',I5,' ',I5,' ',A1,' ',I5) */
/* 9213  CONTINUE */
/*     Trim off the end of line item. */
/*      NVAL = NVAL - 1 */
/*     Put the prescan manipulations here. */
/* SOURCE getcode.for:559 */
/*<       if(nval.gt.1)then >*/
    if (nval > 1) {
/* SOURCE getcode.for:560 */
/*<        >*/
	prescan_(stdout, &feq_gen_c_d_40, mode, &nval, cval, clen, feq_gen_item_type_d_, term, 
		terml, termcls, ival, eflag, (ftnlen)256, (ftnlen)1);
/* SOURCE getcode.for:565 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' Return from PRESCAN: NVAL=',NVAL */
/*      WRITE(STDOUT,97) */
/*      DO 9214 I=1,NVAL */
/*        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I), */
/*     A                  TERMCLS(I) */
/* 9214  CONTINUE */
/*     At this point we should have at least one item in the list. */
/*     The all integer or identifier items should appear first */
/*     followed in some cases by floating point numbers and */
/*     once in a while there will be a continuation flag.  If a */
/*     continuation flag is present it is the last item in the */
/*     list.   MODE will signal if the line we are to process */
/*     is a continuation line.  The format of the continuation line */
/*     may depend on the CODE and the TYPE. */
/* SOURCE getcode.for:583 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     Process a line of information. */
/* SOURCE getcode.for:587 */
/*<       if(nval.le.0)then >*/
    if (nval <= 0) {
/* SOURCE getcode.for:588 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__48.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__48);
	e_wsfe();
/* SOURCE getcode.for:589 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE getcode.for:590 */
/*<       else >*/
    } else {
/* SOURCE getcode.for:591 */
/*<       if(mode.eq.0)then >*/
	if (*mode == 0) {
/*         Transfer the code value. */
/* SOURCE getcode.for:593 */
/*<       if(item_type(1).eq.intval)then >*/
	    if (feq_gen_item_type_d_[0] == 1) {
/* SOURCE getcode.for:594 */
/*<       read(cval(1),*)code >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 256;
		feq_gen_ici_d_1.iciunit = cval;
		feq_gen_ici_d_1.icifmt = 0;
		s_rsli(&feq_gen_ici_d_1);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*code), (ftnlen)sizeof(integer)
			);
		e_rsli();
/* SOURCE getcode.for:595 */
/*<       elseif(item_type(1).eq.chrval)then >*/
	    } else if (feq_gen_item_type_d_[0] == 4) {
/*           We have an identifier first in the line.  Could */
/*           be a macro instruction or an instruction. */
/* SOURCE getcode.for:598 */
/*<       instruction=cval(1) >*/
		s_copy(instruction, cval, (ftnlen)16, (ftnlen)256);
/* SOURCE getcode.for:599 */
/*<       callls_global(instruction,class,value,indx) >*/
		feq_gen_ls_global_d_(instruction, &feq_gen_class_d_, &value, &indx, (ftnlen)16);
/* SOURCE getcode.for:602 */
/*<       if(indx.eq.0)then >*/
		if (indx == 0) {
/* SOURCE getcode.for:603 */
/*<       write(stdout,60)instruction >*/
		    feq_gen_io_d__53.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__53);
		    do_fio(&feq_gen_c_d_1, instruction, (ftnlen)16);
		    e_wsfe();
/* SOURCE getcode.for:604 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE getcode.for:605 */
/*<       else >*/
		} else {
/* SOURCE getcode.for:606 */
/*<       if(class.eq.instruction_class)then >*/
		    if (feq_gen_class_d_ == 2) {
/*               Not a macro instruction.  Return value */
/*               as the CODE. */
/* SOURCE getcode.for:609 */
/*<       write(stdout,64)long_line(1:lenstr(long_line)) >*/
			feq_gen_io_d__54.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__54);
			do_fio(&feq_gen_c_d_1, feq_gen_long_line_d_, lenstr_(feq_gen_long_line_d_, (
				ftnlen)196));
			e_wsfe();
/* SOURCE getcode.for:610 */
/*<       code=value >*/
			*code = value;
/* SOURCE getcode.for:611 */
/*<       elseif(class.eq.macro_class)then >*/
		    } else if (feq_gen_class_d_ == 1) {
/*               Macro instruction.  Go expand it. */
/* SOURCE getcode.for:613 */
/*<       write(stdout,62)long_line(1:lenstr(long_line)) >*/
			feq_gen_io_d__55.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__55);
			do_fio(&feq_gen_c_d_1, feq_gen_long_line_d_, lenstr_(feq_gen_long_line_d_, (
				ftnlen)196));
			e_wsfe();
/* SOURCE getcode.for:614 */
/*<       callexpand_macro(stdout,value,nval,cval,clen,eflag) >*/
			feq_gen_expand_macro_d_(stdout, &value, &nval, cval, clen, 
				eflag, (ftnlen)256);
/*               Return to process the next line of input.  This */
/*               line may come from the macro stack or it may come from */
/*               the user input file.  Signal macro expansion return */
/*               by setting CODE to 999 */
/* SOURCE getcode.for:620 */
/*<       code=999 >*/
			*code = 999;
/* SOURCE getcode.for:621 */
/*<       goto120 >*/
			goto L120;
/* SOURCE getcode.for:622 */
/*<       elseif(class.eq.variable_arguments_class)then >*/
		    } else if (feq_gen_class_d_ == 3) {
/*               Special case for sum of flows = 0.  The number */
/*               of nodes is a variable.  This instruction class */
/*               will have one or more arguments and the number */
/*               of arguments is inserted into the list.  Thus */
/*               the user need not supply the number of arguments. */
/* SOURCE getcode.for:629 */
/*<       code=value >*/
			*code = value;
/*               Insert the number of arguments into the lists adjusting */
/*               only those items needed below. */
/* SOURCE getcode.for:634 */
/*<       write(stdout,64)long_line(1:lenstr(long_line)) >*/
			feq_gen_io_d__56.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__56);
			do_fio(&feq_gen_c_d_1, feq_gen_long_line_d_, lenstr_(feq_gen_long_line_d_, (
				ftnlen)196));
			e_wsfe();
/* SOURCE getcode.for:635 */
/*<        >*/
			feq_gen_insert_argument_knt_d_(&feq_gen_c_d_40, &nval, cval, clen, 
				feq_gen_item_type_d_, term, terml, termcls, (ftnlen)
				256, (ftnlen)1);
/*      WRITE(STDOUT,*) ' Return from INSERT_ARG...: NVAL=',NVAL */
/*      WRITE(STDOUT,97) */
/*      DO 9215 I=1,NVAL */
/*        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I), */
/*     A                  TERMCLS(I) */
/* 9215  CONTINUE */
/* SOURCE getcode.for:644 */
/*<       endif >*/
		    }
/* SOURCE getcode.for:645 */
/*<       endif >*/
		}
/* SOURCE getcode.for:646 */
/*<       else >*/
	    } else {
/* SOURCE getcode.for:647 */
/*<       write(stdout,52)cval(1) >*/
		feq_gen_io_d__57.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__57);
		do_fio(&feq_gen_c_d_1, cval, (ftnlen)256);
		e_wsfe();
/* SOURCE getcode.for:648 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE getcode.for:649 */
/*<       endif >*/
	    }
/*         Set the key values. */
/* SOURCE getcode.for:651 */
/*<       istart=2 >*/
	    istart = 2;
/* SOURCE getcode.for:652 */
/*<       init_iknt=0 >*/
	    feq_gen_init_iknt_d_ = 0;
/* SOURCE getcode.for:653 */
/*<       elseif(mode.eq.1)then >*/
	} else if (*mode == 1) {
/*         Continuation line for Code 5 Type 6. */
/* SOURCE getcode.for:655 */
/*<       istart=1 >*/
	    istart = 1;
/* SOURCE getcode.for:656 */
/*<       init_iknt=4 >*/
	    feq_gen_init_iknt_d_ = 4;
/* SOURCE getcode.for:657 */
/*<       endif >*/
	}
/* SOURCE getcode.for:658 */
/*<       endif >*/
    }
/*     Check to see if a continuation signal is present. */
/* SOURCE getcode.for:662 */
/*<       if(item_type(nval).eq.continuation_value)then >*/
    if (feq_gen_item_type_d_[nval - 1] == 5) {
/*       Continuation signal found. */
/* SOURCE getcode.for:664 */
/*<       ilimit=9 >*/
	ilimit = 9;
/* SOURCE getcode.for:665 */
/*<       nc(10)='    1' >*/
	s_copy(nc + 50, const_cast<char*>("    1"), (ftnlen)5, (ftnlen)5);
/* SOURCE getcode.for:666 */
/*<       nc_long(10)='1' >*/
	s_copy(feq_gen_nc_long_d_ + 160, const_cast<char*>("1"), (ftnlen)16, (ftnlen)1);
/* SOURCE getcode.for:667 */
/*<       nval=nval-1 >*/
	--nval;
/* SOURCE getcode.for:668 */
/*<       else >*/
    } else {
/*       No continuation signal present. */
/* SOURCE getcode.for:670 */
/*<       ilimit=10 >*/
	ilimit = 10;
/* SOURCE getcode.for:671 */
/*<       endif >*/
    }
/*     Now transfer integers or identifiers until NVAL is reached, or */
/*     a non-integer and non-identifier type is found. */
/* SOURCE getcode.for:678 */
/*<       non_int_id=0 >*/
    feq_gen_non_int_id_d_ = 0;
/* SOURCE getcode.for:679 */
/*<       iknt=init_iknt >*/
    iknt = feq_gen_init_iknt_d_;
/* SOURCE getcode.for:680 */
/*<       fknt=0 >*/
    fknt = 0;
/*      WRITE(STDOUT,*) ' ISTART=',ISTART,' NVAL=',NVAL */
/* SOURCE getcode.for:682 */
/*<       do110i=istart,nval >*/
    feq_gen_i_d_1 = nval;
    for (feq_gen_i_d_ = istart; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE getcode.for:683 */
/*<       if(non_int_id.eq.0)then >*/
	if (feq_gen_non_int_id_d_ == 0) {
/*         Check for type */
/* SOURCE getcode.for:685 */
/*<        >*/
	    if (feq_gen_item_type_d_[feq_gen_i_d_ - 1] != 1 && feq_gen_item_type_d_[feq_gen_i_d_ - 1] != 4 && 
		    feq_gen_item_type_d_[feq_gen_i_d_ - 1] != 6) {
/* SOURCE getcode.for:687 */
/*<       non_int_id=1 >*/
		feq_gen_non_int_id_d_ = 1;
/* SOURCE getcode.for:688 */
/*<       else >*/
	    } else {
/* SOURCE getcode.for:689 */
/*<       iknt=iknt+1 >*/
		++iknt;
/* SOURCE getcode.for:690 */
/*<       if(iknt.le.ilimit)then >*/
		if (iknt <= ilimit) {
/* SOURCE getcode.for:691 */
/*<       if(item_type(i).eq.place_holder)then >*/
		    if (feq_gen_item_type_d_[feq_gen_i_d_ - 1] == 6) {
/* SOURCE getcode.for:692 */
/*<       nc(iknt)=' ' >*/
			s_copy(nc + iknt * 5, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1);
/* SOURCE getcode.for:693 */
/*<       nc_long(iknt)=' ' >*/
			s_copy(feq_gen_nc_long_d_ + (iknt << 4), const_cast<char*>(" "), (ftnlen)16, (
				ftnlen)1);
/* SOURCE getcode.for:694 */
/*<       else >*/
		    } else {
/* SOURCE getcode.for:695 */
/*<       nc(iknt)=' ' >*/
			s_copy(nc + iknt * 5, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1);
/* SOURCE getcode.for:696 */
/*<       it=clen(i) >*/
			it = clen[feq_gen_i_d_ - 1];
/* SOURCE getcode.for:697 */
/*<       if(it.gt.5)then >*/
			if (it > 5) {
/* SOURCE getcode.for:698 */
/*<       it=5 >*/
			    it = 5;
/* SOURCE getcode.for:699 */
/*<       endif >*/
			}
/* SOURCE getcode.for:700 */
/*<       nc(iknt)(6-it:5)=cval(i) >*/
			feq_gen_i_d_2 = 6 - it - 1;
			s_copy(nc + (iknt * 5 + feq_gen_i_d_2), cval + (feq_gen_i_d_ - 1 << 8), 
				5 - feq_gen_i_d_2, (ftnlen)256);
/* SOURCE getcode.for:701 */
/*<       nc_long(iknt)=cval(i) >*/
			s_copy(feq_gen_nc_long_d_ + (iknt << 4), cval + (feq_gen_i_d_ - 1 << 8),
				 (ftnlen)16, (ftnlen)256);
/* SOURCE getcode.for:702 */
/*<       endif >*/
		    }
/* SOURCE getcode.for:703 */
/*<       else >*/
		} else {
/* SOURCE getcode.for:704 */
/*<       write(stdout,54) >*/
		    feq_gen_io_d__64.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__64);
		    e_wsfe();
/* SOURCE getcode.for:705 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE getcode.for:706 */
/*<       endif >*/
		}
/* SOURCE getcode.for:707 */
/*<       if(termcls(i).eq.semicolon)then >*/
		if (termcls[feq_gen_i_d_ - 1] == 20) {
/* SOURCE getcode.for:708 */
/*<       non_int_id=1 >*/
		    feq_gen_non_int_id_d_ = 1;
/*             This is the terminator for the last item in the set of */
/*             integer/identifier.  Thus skip to end of loop so that the */
/*             next item is processed as the first in the floating */
/*             point values set. */
/* SOURCE getcode.for:713 */
/*<       goto110 >*/
		    goto L110;
/* SOURCE getcode.for:714 */
/*<       endif >*/
		}
/* SOURCE getcode.for:715 */
/*<       endif >*/
	    }
/* SOURCE getcode.for:716 */
/*<       endif >*/
	}
/* SOURCE getcode.for:717 */
/*<       if(non_int_id.eq.1)then >*/
	if (feq_gen_non_int_id_d_ == 1) {
/*         We expect type to be real or double precision or place holder or */
/*         the special identifier TAB or tab. */
/* SOURCE getcode.for:720 */
/*<        >*/
	    if (feq_gen_item_type_d_[feq_gen_i_d_ - 1] != 2 && feq_gen_item_type_d_[feq_gen_i_d_ - 1] != 3 && 
		    feq_gen_item_type_d_[feq_gen_i_d_ - 1] != 6 && s_cmp(cval + (feq_gen_i_d_ - 1 << 8), 
		    const_cast<char*>("TAB"), (ftnlen)3, (ftnlen)3) != 0 && s_cmp(cval + (feq_gen_i_d_ - 
		    1 << 8), const_cast<char*>("tab"), (ftnlen)3, (ftnlen)3) != 0) {
/* SOURCE getcode.for:723 */
/*<       write(stdout,56) >*/
		feq_gen_io_d__65.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__65);
		e_wsfe();
/* SOURCE getcode.for:724 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE getcode.for:725 */
/*<       else >*/
	    } else {
/* SOURCE getcode.for:726 */
/*<       fknt=fknt+1 >*/
		++fknt;
/* SOURCE getcode.for:727 */
/*<       if(fknt.le.5)then >*/
		if (fknt <= 5) {
/* SOURCE getcode.for:728 */
/*<       if(item_type(i).eq.place_holder)then >*/
		    if (feq_gen_item_type_d_[feq_gen_i_d_ - 1] == 6) {
/* SOURCE getcode.for:729 */
/*<       f(fknt)=0.0 >*/
			f[fknt] = (float)0.;
/* SOURCE getcode.for:730 */
/*<       fc(fknt)=' ' >*/
			s_copy(fc + (fknt << 2), const_cast<char*>(" "), (ftnlen)4, (ftnlen)1);
/* SOURCE getcode.for:731 */
/*<       elseif(cval(i)(1:3).eq.'TAB'.or.cval(i)(1:3).eq.'tab')then >*/
		    } else if (s_cmp(cval + (feq_gen_i_d_ - 1 << 8), const_cast<char*>("TAB"), (ftnlen)3, 
			    (ftnlen)3) == 0 || s_cmp(cval + (feq_gen_i_d_ - 1 << 8), 
			    const_cast<char*>("tab"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE getcode.for:733 */
/*<       fc(fknt)='LKUP' >*/
			s_copy(fc + (fknt << 2), const_cast<char*>("LKUP"), (ftnlen)4, (ftnlen)4)
				;
/* SOURCE getcode.for:734 */
/*<       if(clen(i)>3)then >*/
			if (clen[feq_gen_i_d_ - 1] > 3) {
/*                 An increment to the eventual datum is present. */
/* SOURCE getcode.for:736 */
/*<       read(cval(i)(4:clen(i)),*)f(fknt) >*/
			    feq_gen_ici_d_1.icierr = 0;
			    feq_gen_ici_d_1.iciend = 0;
			    feq_gen_ici_d_1.icirnum = 1;
			    feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ - 1] - 3;
			    feq_gen_ici_d_1.iciunit = cval + ((feq_gen_i_d_ - 1 << 8) + 3);
			    feq_gen_ici_d_1.icifmt = 0;
			    s_rsli(&feq_gen_ici_d_1);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&f[fknt], (ftnlen)
				    sizeof(real));
			    e_rsli();
/* SOURCE getcode.for:737 */
/*<       else >*/
			} else {
/* SOURCE getcode.for:738 */
/*<       f(fknt)=0.0 >*/
			    f[fknt] = (float)0.;
/* SOURCE getcode.for:739 */
/*<       endif >*/
			}
/* SOURCE getcode.for:740 */
/*<       else >*/
		    } else {
/* SOURCE getcode.for:741 */
/*<       read(cval(i),*)f(fknt) >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 256;
			feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ - 1 << 8);
			feq_gen_ici_d_1.icifmt = 0;
			s_rsli(&feq_gen_ici_d_1);
			do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&f[fknt], (ftnlen)sizeof(
				real));
			e_rsli();
/* SOURCE getcode.for:742 */
/*<       fc(fknt)=' ' >*/
			s_copy(fc + (fknt << 2), const_cast<char*>(" "), (ftnlen)4, (ftnlen)1);
/* SOURCE getcode.for:743 */
/*<       endif >*/
		    }
/* SOURCE getcode.for:744 */
/*<       else >*/
		} else {
/* SOURCE getcode.for:745 */
/*<       write(stdout,58) >*/
		    feq_gen_io_d__66.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__66);
		    e_wsfe();
/* SOURCE getcode.for:746 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE getcode.for:747 */
/*<       endif >*/
		}
/* SOURCE getcode.for:748 */
/*<       endif >*/
	    }
/* SOURCE getcode.for:749 */
/*<       endif >*/
	}
/* SOURCE getcode.for:750 */
/*<   110 continue >*/
L110:
	;
    }
/* SOURCE getcode.for:751 */
/*<   120 continue >*/
L120:
/* SOURCE getcode.for:752 */
/*<       return >*/
    return 0;
/* SOURCE getcode.for:753 */
/*<       end >*/
} /* get_code_nc_f__ */

/*     *********** */
/*     *         * */
/*     * GET_ITEMS */
/*     *         * */
/*     *********** */
/* SOURCE getcode.for:761 */
/*<        >*/
/* Subroutine */ int feq_gen_get_items_d_(integer *stdout, char *feq_gen_line_in_d_, integer *
	feq_gen_max_knt_d_, integer *feq_gen_item_knt_d_, char *feq_storage_items, integer *feq_gen_feq_storage_item_length_d_, 
	integer *feq_gen_feq_storage_item_type_d_, integer *feq_gen_feq_storage_term_class_d_, integer *eflag, ftnlen 
	line_in_len, ftnlen items_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:298* Found \002,i3,\002 items when \
no more than \002,i3,\002 were expected.\002/)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, it, opt, clen[20];
    char cval[256*20], line[256];
    integer ival[20], nval;
    real rval[20];
    char term[1*20];
    doublereal dpval[20];
    integer terml[20], itype[20];
    extern /* Subroutine */ int getval_(integer *, char *, integer *, integer 
	    *, integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    extern integer lenstr_(char *, ftnlen);
    integer termcls[20];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_50, 0 };


/*     Get a sequence of items from a line of user input. */
/*     That is, break a line of input into its parts.  An item */
/*     can be: an identifier(by our definition), an integer, */
/*     a single precision floating point value, or a double precision */
/*     floating point value. */
/* SOURCE getcode.for:771 */
/*<       implicitnone >*/
/* SOURCE getcode.for:772 */
/*<        >*/
/* SOURCE getcode.for:776 */
/*<       characteritems(max_knt)*(*),line_in*(*) >*/
/*     Local variables */
/* SOURCE getcode.for:780 */
/*<       characterline*256 >*/
/* SOURCE getcode.for:782 */
/*<       integermax_nval >*/
/* SOURCE getcode.for:784 */
/*<       parameter(max_nval=20) >*/
/* SOURCE getcode.for:786 */
/*<       integeropt,i,it,nval >*/
/* SOURCE getcode.for:788 */
/*<        >*/
/* SOURCE getcode.for:790 */
/*<       realrval(max_nval) >*/
/* SOURCE getcode.for:791 */
/*<       real*8dpval(max_nval) >*/
/* SOURCE getcode.for:792 */
/*<       charactercval(max_nval)*256,term(max_nval)*1 >*/
/* SOURCE getcode.for:794 */
/*<       integerlenstr >*/
/* SOURCE getcode.for:795 */
/*<       externalgetval,lenstr >*/
/* SOURCE getcode.for:797 */
/*<       intrinsicindex >*/
/*     *********************************FORMATS************************** */
/* SOURCE getcode.for:799 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE getcode.for:803 */
/*<       line=line_in >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_term_class_d_(feq_gen_feq_storage_term_class_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_length_d_(feq_gen_feq_storage_item_length_d_, 1);

    feq::IndexedPointer<char> items(feq_storage_items, items_len);

    /* Function Body */
/* L50: */
    s_copy(line, feq_gen_line_in_d_, (ftnlen)256, line_in_len);
/* SOURCE getcode.for:804 */
/*<       i=index(line,'''') >*/
    feq_gen_i_d_ = i_indx(line, const_cast<char*>("'"), (ftnlen)256, (ftnlen)1);
/* SOURCE getcode.for:805 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE getcode.for:806 */
/*<       it=lenstr(line) >*/
	it = lenstr_(line, (ftnlen)256);
/* SOURCE getcode.for:807 */
/*<       line(it+1:it+1)='''' >*/
	feq_gen_i_d_1 = it;
	s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE getcode.for:808 */
/*<       else >*/
    } else {
/*       Revise user quote to  ,quote */
/*        LINE(I:I+2) = ' ,''' */
/* SOURCE getcode.for:811 */
/*<       endif >*/
    }
/*     Select the option to return what is found with no */
/*     expectations being enforced. */
/* SOURCE getcode.for:815 */
/*<       opt=1 >*/
    opt = 1;
/* SOURCE getcode.for:816 */
/*<        >*/
    getval_(stdout, line, &feq_gen_c_d_20, &opt, itype, ival, rval, dpval, cval, clen, 
	    eflag, term, terml, termcls, &nval, (ftnlen)256, (ftnlen)256, (
	    ftnlen)1);
/*      WRITE(STDOUT,*) ' Return from GETVAL in GET_ITEMS: NVAL=',NVAL */
/*      DO 9213 I=1,NVAL */
/*        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I) */
/* 99    FORMAT(' ',A12,' ',I5,' ',I5,' ',A1) */
/* 9213  CONTINUE */
/*     Transfer to arguments.  Trim off last item since it is the */
/*     special end of line item. */
/*      IF(NVAL-1.GT.MAX_KNT) THEN */
/* SOURCE getcode.for:828 */
/*<       if(nval.gt.max_knt)then >*/
    if (nval > *feq_gen_max_knt_d_) {
/* SOURCE getcode.for:829 */
/*<       write(stdout,50)nval,max_knt >*/
	feq_gen_io_d__81.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__81);
	do_fio(&feq_gen_c_d_1, (char *)&nval, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_max_knt_d_), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE getcode.for:830 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE getcode.for:831 */
/*<       nval=max_knt >*/
	nval = *feq_gen_max_knt_d_;
/* SOURCE getcode.for:832 */
/*<       endif >*/
    }
/*      ITEM_KNT = NVAL - 1 */
/* SOURCE getcode.for:834 */
/*<       item_knt=nval >*/
    *feq_gen_item_knt_d_ = nval;
/*      DO 100 I=1,NVAL-1 */
/* SOURCE getcode.for:836 */
/*<       do100i=1,nval >*/
    feq_gen_i_d_1 = nval;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE getcode.for:837 */
/*<       items(i)=cval(i) >*/
	s_copy(items + feq_gen_i_d_ * items_len, cval + (feq_gen_i_d_ - 1 << 8), items_len, (
		ftnlen)256);
/* SOURCE getcode.for:838 */
/*<       item_length(i)=clen(i) >*/
	feq_gen_item_length_d_[feq_gen_i_d_] = clen[feq_gen_i_d_ - 1];
/* SOURCE getcode.for:839 */
/*<       item_type(i)=itype(i) >*/
	feq_gen_item_type_d_[feq_gen_i_d_] = itype[feq_gen_i_d_ - 1];
/* SOURCE getcode.for:840 */
/*<       term_class(i)=termcls(i) >*/
	feq_gen_term_class_d_[feq_gen_i_d_] = termcls[feq_gen_i_d_ - 1];
/* SOURCE getcode.for:841 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE getcode.for:842 */
/*<       return >*/
    return 0;
/* SOURCE getcode.for:843 */
/*<       end >*/
} /* get_items__ */

#ifdef __cplusplus
	}
#endif
