/* macro.f -- translated by f2c (version 20240504).
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

/* COMMON symbol_c__ is declared in common.hpp. */

#define feq_gen_symbol_c_d_1 feq_gen_symbol_c_d_

/* COMMON symbol_i__ is declared in common.hpp. */

#define feq_gen_symbol_i_d_1 feq_gen_symbol_i_d_

/* COMMON macro_c__ is declared in common.hpp. */

#define feq_gen_macro_c_d_1 feq_gen_macro_c_d_

/* COMMON macro_i__ is declared in common.hpp. */

#define feq_gen_macro_i_d_1 feq_gen_macro_i_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_30 = 30;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_196 = 196;

/*     *********** */
/*     *         * */
/*     * LSA_GLOBAL */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:7 */
/*<       subroutinelsa_global(stdout,key,class,value,index,flag) >*/
/* Subroutine */ int feq_gen_lsa_global_d_(integer *stdout, char *key, integer *
	feq_gen_class_d_, integer *value, integer *index, integer *feq_gen_flag_d_, ftnlen 
	key_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:302* Too many entries in global sym\
bol table.\002,\002 Number=\002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__2 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do a linear search for KEY in the entries in the global */
/*     symbol table and add to the table if KEY is not found. */
/*     Otherwise, return the index to KEY and the value of */
/*     CLASS and VALUE found for the symbol in KEY. */
/* SOURCE macro.for:18 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE macro.for:20 */
/*<       integerflag,index,stdout,class,value >*/
/* SOURCE macro.for:21 */
/*<       characterkey*16 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     KEY    - search value */
/*     CLASS  - Class code for the symbol. */
/*     VALUE  - numeric value for the symbol. */
/*     INDEX  - index into the table at the match point */
/*     FLAG  -  0: KEY not in the table; 1: Key in the table; */
/*              2: error encountered. */
/* INCLUDE macro.for:32 */
/*     Symbol table for processing FEQ. */
/* SOURCE symbol.cmn:3 */
/*<       integermax_symbol >*/
/* SOURCE symbol.cmn:4 */
/*<       parameter(max_symbol=250) >*/
/* SOURCE symbol.cmn:6 */
/*<       character*16symbol(max_symbol) >*/
/* SOURCE symbol.cmn:8 */
/*<        >*/
/* SOURCE symbol.cmn:11 */
/*<       common/symbol_c/symbol >*/
/* SOURCE symbol.cmn:13 */
/*<       common/symbol_i/symbol_class,symbol_value,last_symbol >*/
/* SOURCE symbol.cmn:15 */
/*<       save/symbol_c/,/symbol_i/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE macro.for:35 */
/*<       integeri >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE macro.for:38 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE macro.for:41 */
/*<       do100i=1,last_symbol >*/
/* L50: */
    feq_gen_i_d_1 = feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE macro.for:42 */
/*<       if(key.eq.symbol(i))then >*/
	if (s_cmp(key, feq_gen_symbol_c_d_1.symbol + (feq_gen_i_d_ - 1 << 4), (ftnlen)16, (
		ftnlen)16) == 0) {
/*         FOUND MATCH */
/* SOURCE macro.for:44 */
/*<       index=i >*/
	    *index = feq_gen_i_d_;
/* SOURCE macro.for:45 */
/*<       class=symbol_class(i) >*/
	    *feq_gen_class_d_ = feq_gen_symbol_i_d_1.feq_gen_symbol_class_d_[feq_gen_i_d_ - 1];
/* SOURCE macro.for:46 */
/*<       value=symbol_value(i) >*/
	    *value = feq_gen_symbol_i_d_1.feq_gen_symbol_value_d_[feq_gen_i_d_ - 1];
/* SOURCE macro.for:47 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE macro.for:48 */
/*<       return >*/
	    return 0;
/* SOURCE macro.for:49 */
/*<       endif >*/
	}
/* SOURCE macro.for:50 */
/*<   100 continue >*/
/* L100: */
    }
/*     MATCH NOT FOUND */
/* SOURCE macro.for:52 */
/*<       last_symbol=last_symbol+1 >*/
    ++feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_;
/* SOURCE macro.for:54 */
/*<       if(last_symbol.gt.max_symbol)then >*/
    if (feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ > 250) {
/* SOURCE macro.for:55 */
/*<       write(stdout,50)last_symbol >*/
	feq_gen_io_d__2.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__2);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_, (ftnlen)sizeof(
		integer));
	e_wsfe();
/* SOURCE macro.for:56 */
/*<       flag=2 >*/
	*feq_gen_flag_d_ = 2;
/* SOURCE macro.for:57 */
/*<       last_symbol=max_symbol >*/
	feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ = 250;
/* SOURCE macro.for:58 */
/*<       endif >*/
    }
/* SOURCE macro.for:59 */
/*<       flag=0 >*/
    *feq_gen_flag_d_ = 0;
/* SOURCE macro.for:60 */
/*<       symbol(last_symbol)=key >*/
    s_copy(feq_gen_symbol_c_d_1.symbol + (feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1 << 4), key, (
	    ftnlen)16, (ftnlen)16);
/* SOURCE macro.for:61 */
/*<       symbol_class(last_symbol)=class >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_class_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = *feq_gen_class_d_;
/* SOURCE macro.for:62 */
/*<       symbol_value(last_symbol)=value >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_value_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = *value;
/* SOURCE macro.for:63 */
/*<       index=last_symbol >*/
    *index = feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_;
/* SOURCE macro.for:64 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:65 */
/*<       end >*/
} /* lsa_global__ */

/*     *********** */
/*     *         * */
/*     * LS_GLOBAL */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:72 */
/*<       subroutinels_global(key,class,value,index) >*/
/* Subroutine */ int feq_gen_ls_global_d_(char *key, integer *feq_gen_class_d_, integer *value, 
	integer *index, ftnlen key_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

/*     + + + PURPOSE + + + */
/*     Do a linear search for KEY in the entries in the global */
/*     symbol table and return its class, value, and index */
/*     if it is found.  Otherwise return a zero value for */
/*     index. */
/* SOURCE macro.for:82 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE macro.for:84 */
/*<       integerindex,class,value >*/
/* SOURCE macro.for:85 */
/*<       characterkey*16 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     KEY    - search value */
/*     CLASS  - Class code for the symbol. */
/*     VALUE  - numeric value for the symbol. */
/*     INDEX  - index into the table at the match point */
/* INCLUDE macro.for:93 */
/*     Symbol table for processing FEQ. */
/* SOURCE symbol.cmn:3 */
/*<       integermax_symbol >*/
/* SOURCE symbol.cmn:4 */
/*<       parameter(max_symbol=250) >*/
/* SOURCE symbol.cmn:6 */
/*<       character*16symbol(max_symbol) >*/
/* SOURCE symbol.cmn:8 */
/*<        >*/
/* SOURCE symbol.cmn:11 */
/*<       common/symbol_c/symbol >*/
/* SOURCE symbol.cmn:13 */
/*<       common/symbol_i/symbol_class,symbol_value,last_symbol >*/
/* SOURCE symbol.cmn:15 */
/*<       save/symbol_c/,/symbol_i/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE macro.for:96 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE macro.for:99 */
/*<       do100i=1,last_symbol >*/
    feq_gen_i_d_1 = feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE macro.for:100 */
/*<       if(key.eq.symbol(i))then >*/
	if (s_cmp(key, feq_gen_symbol_c_d_1.symbol + (feq_gen_i_d_ - 1 << 4), (ftnlen)16, (
		ftnlen)16) == 0) {
/*         Found match */
/* SOURCE macro.for:102 */
/*<       index=i >*/
	    *index = feq_gen_i_d_;
/* SOURCE macro.for:103 */
/*<       class=symbol_class(i) >*/
	    *feq_gen_class_d_ = feq_gen_symbol_i_d_1.feq_gen_symbol_class_d_[feq_gen_i_d_ - 1];
/* SOURCE macro.for:104 */
/*<       value=symbol_value(i) >*/
	    *value = feq_gen_symbol_i_d_1.feq_gen_symbol_value_d_[feq_gen_i_d_ - 1];
/* SOURCE macro.for:105 */
/*<       return >*/
	    return 0;
/* SOURCE macro.for:106 */
/*<       endif >*/
	}
/* SOURCE macro.for:107 */
/*<   100 continue >*/
/* L100: */
    }
/*     Match not found. */
/* SOURCE macro.for:109 */
/*<       index=0 >*/
    *index = 0;
/* SOURCE macro.for:110 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:111 */
/*<       end >*/
} /* ls_global__ */

/*     *********** */
/*     *         * */
/*     * IDENTIFIER_REPLACE */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:121 */
/*<        >*/
/* Subroutine */ int feq_gen_identifier_replace_d_(integer *stdout, char *dummy, 
	integer *feq_gen_dummy_len_d_, char *actual, integer *feq_gen_actual_len_d_, integer *
	istart, integer *feq_gen_max_line_len_d_, char *line, integer *feq_gen_line_len_d_, 
	integer *eflag, ftnlen dummy_len, ftnlen actual_len, ftnlen line_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_temp_len_d_, feq_gen_i_d_, is;
    char chr[1], temp[196];
    integer feq_gen_new_line_len_d_, shift, inext, reject;

/*     Find and replace any occurences of an identifier, DUMMY, of */
/*     length, DUMMY_LEN, with the identifer in ACTUAL, of length */
/*     ACTUAL_LEN, in LINE, of length, LINE_LEN, on input, starting */
/*     at character number, ISTART.  On return, LINE, contains the */
/*     updated string, and LINE_LEN contains the new length of the */
/*     possibly changed line.  EFLAG=0 if no error, EFLAG=1 if the */
/*     substitution causes the length of LINE to exceed */
/*     MAX_LINE_LEN. */
/* SOURCE macro.for:134 */
/*<       implicitnone >*/
/* SOURCE macro.for:136 */
/*<        >*/
/* SOURCE macro.for:139 */
/*<       characterline*196,dummy*16,actual*16 >*/
/*     Local */
/* SOURCE macro.for:143 */
/*<       integeri,is,shift,new_line_len,reject,inext,temp_len >*/
/* SOURCE macro.for:145 */
/*<       characterchr*1,temp*196 >*/
/*     Called program units/intrinsics */
/* SOURCE macro.for:149 */
/*<       intrinsicindex >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' ' */
/*      WRITE(STDOUT,*) ' Entering Idenifier_replace:' */
/*      WRITE(STDOUT,*) ' ACTUAL=',ACTUAL */
/*      WRITE(STDOUT,*) ' ACTUAL_LEN=',ACTUAL_LEN */
/*      WRITE(STDOUT,*) ' DUMMY=',DUMMY */
/*      WRITE(STDOUT,*) ' DUMMY_LEN=',DUMMY_LEN */
/*      WRITE(STDOUT,*) ' MAX_LINE_LEN=',MAX_LINE_LEN */
/*      WRITE(STDOUT,*) ' LINE=',LINE */
/*      WRITE(STDOUT,*) ' LINE_LEN=',LINE_LEN */
/*      WRITE(STDOUT,*) ' Starting processing:' */
/* SOURCE macro.for:163 */
/*<       is=istart >*/
    is = *istart;
/* SOURCE macro.for:164 */
/*<       shift=actual_len-dummy_len >*/
    shift = *feq_gen_actual_len_d_ - *feq_gen_dummy_len_d_;
/* SOURCE macro.for:165 */
/*<   100 continue >*/
L100:
/* SOURCE macro.for:166 */
/*<       if(is.le.line_len)then >*/
    if (is <= *feq_gen_line_len_d_) {
/*         Some characters still remain. */
/* SOURCE macro.for:168 */
/*<       i=index(line(is:line_len),dummy(1:dummy_len)) >*/
	feq_gen_i_d_ = i_indx(line + (is - 1), dummy, *feq_gen_line_len_d_ - (is - 1), (*
		feq_gen_dummy_len_d_));
/*          WRITE(STDOUT,*) ' I before substring adjustment=',I */
/* SOURCE macro.for:170 */
/*<       if(i.gt.0)then >*/
	if (feq_gen_i_d_ > 0) {
/*           Adjust value of I for substring. */
/* SOURCE macro.for:172 */
/*<       i=i+is-1 >*/
	    feq_gen_i_d_ = feq_gen_i_d_ + is - 1;
/*            WRITE(STDOUT,*) ' I after substring adjustment=',I, */
/*     A                 ' LINE(I:I)=',LINE(I:I) */
/*           Now verify that the occurrence is really an */
/*           identifier and not a sequence of characters embedded */
/*           in a larger string. */
/* SOURCE macro.for:179 */
/*<       reject=2 >*/
	    reject = 2;
/* SOURCE macro.for:180 */
/*<       if(i.eq.1)then >*/
	    if (feq_gen_i_d_ == 1) {
/*             Start of LINE is valid delimiter identifier */
/* SOURCE macro.for:182 */
/*<       reject=reject-1 >*/
		--reject;
/* SOURCE macro.for:183 */
/*<       else >*/
	    } else {
/* SOURCE macro.for:184 */
/*<       chr=line(i-1:i-1) >*/
		feq_gen_i_d_1 = feq_gen_i_d_ - 2;
		s_copy(chr, line + feq_gen_i_d_1, (ftnlen)1, feq_gen_i_d_ - 1 - feq_gen_i_d_1);
/* SOURCE macro.for:185 */
/*<        >*/
		if (*(unsigned char *)chr == ' ' || *(unsigned char *)chr == 
			'+' || *(unsigned char *)chr == '-' || *(unsigned 
			char *)chr == '|' || *(unsigned char *)chr == '*') {
/* SOURCE macro.for:187 */
/*<       reject=reject-1 >*/
		    --reject;
/* SOURCE macro.for:188 */
/*<       endif >*/
		}
/* SOURCE macro.for:189 */
/*<       endif >*/
	    }
/*           Find the index of the first character following DUMMY */
/* SOURCE macro.for:192 */
/*<       inext=i+dummy_len >*/
	    inext = feq_gen_i_d_ + *feq_gen_dummy_len_d_;
/* SOURCE macro.for:193 */
/*<       if(inext.gt.line_len)then >*/
	    if (inext > *feq_gen_line_len_d_) {
/*             End of line is valid delimiter for an identifier */
/* SOURCE macro.for:195 */
/*<       reject=reject-1 >*/
		--reject;
/* SOURCE macro.for:196 */
/*<       else >*/
	    } else {
/* SOURCE macro.for:197 */
/*<       chr=line(inext:inext) >*/
		*(unsigned char *)chr = *(unsigned char *)&line[inext - 1];
/* SOURCE macro.for:198 */
/*<        >*/
		if (*(unsigned char *)chr == ' ' || *(unsigned char *)chr == 
			'+' || *(unsigned char *)chr == '-' || *(unsigned 
			char *)chr == '|' || *(unsigned char *)chr == '*') {
/* SOURCE macro.for:200 */
/*<       reject=reject-1 >*/
		    --reject;
/* SOURCE macro.for:201 */
/*<       endif >*/
		}
/* SOURCE macro.for:202 */
/*<       endif >*/
	    }
/* SOURCE macro.for:203 */
/*<       if(reject.ne.0)then >*/
	    if (reject != 0) {
/*             Go back and search again. */
/* SOURCE macro.for:205 */
/*<       is=inext >*/
		is = inext;
/* SOURCE macro.for:206 */
/*<       goto100 >*/
		goto L100;
/* SOURCE macro.for:207 */
/*<       endif >*/
	    }
/*           DUMMY was found as a valid identifier. */
/* SOURCE macro.for:210 */
/*<       if(shift.eq.0)then >*/
	    if (shift == 0) {
/*             The symbols are of the same length. */
/*             Find the character that is or would be to the immediate */
/*             right of the new symbol.  This may be beyond the */
/*             end of the new line length. */
/* SOURCE macro.for:215 */
/*<       is=i+actual_len >*/
		is = feq_gen_i_d_ + *feq_gen_actual_len_d_;
/* SOURCE macro.for:216 */
/*<       line(i:is-1)=actual(1:actual_len) >*/
		s_copy(line + (feq_gen_i_d_ - 1), actual, is - 1 - (feq_gen_i_d_ - 1), (*
			feq_gen_actual_len_d_));
/* SOURCE macro.for:217 */
/*<       line_len=line_len+shift >*/
		*feq_gen_line_len_d_ += shift;
/*              WRITE(STDOUT,*) 'SHIFT=0: After replace: Line is:' */
/*              WRITE(STDOUT,*) LINE */
/*              WRITE(STDOUT,*) ' IS=',IS */
/* SOURCE macro.for:221 */
/*<       if(line_len.gt.max_line_len)then >*/
		if (*feq_gen_line_len_d_ > *feq_gen_max_line_len_d_) {
/* SOURCE macro.for:222 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE macro.for:223 */
/*<       line_len=max_line_len >*/
		    *feq_gen_line_len_d_ = *feq_gen_max_line_len_d_;
/* SOURCE macro.for:224 */
/*<       endif >*/
		}
/* SOURCE macro.for:225 */
/*<       elseif(i+dummy_len-1.eq.line_len)then >*/
	    } else if (feq_gen_i_d_ + *feq_gen_dummy_len_d_ - 1 == *feq_gen_line_len_d_) {
/*             There is nothing to the right of the symbol being */
/*             replaced. */
/* SOURCE macro.for:228 */
/*<       is=i+actual_len >*/
		is = feq_gen_i_d_ + *feq_gen_actual_len_d_;
/* SOURCE macro.for:229 */
/*<       line(i:)=actual(1:actual_len) >*/
		s_copy(line + (feq_gen_i_d_ - 1), actual, 196 - (feq_gen_i_d_ - 1), (*
			feq_gen_actual_len_d_));
/* SOURCE macro.for:230 */
/*<       line_len=line_len+shift >*/
		*feq_gen_line_len_d_ += shift;
/* SOURCE macro.for:231 */
/*<       if(line_len.gt.max_line_len)then >*/
		if (*feq_gen_line_len_d_ > *feq_gen_max_line_len_d_) {
/* SOURCE macro.for:232 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE macro.for:233 */
/*<       line_len=max_line_len >*/
		    *feq_gen_line_len_d_ = *feq_gen_max_line_len_d_;
/* SOURCE macro.for:234 */
/*<       endif >*/
		}
/* SOURCE macro.for:235 */
/*<       else >*/
	    } else {
/*             The symbol being replaced is not at the end of the */
/*             line and its length differs from the replacing symbol. */
/*             There are always some characters to the right of the */
/*             existing symbol that need to be shifted. */
/* SOURCE macro.for:241 */
/*<       new_line_len=line_len+shift >*/
		feq_gen_new_line_len_d_ = *feq_gen_line_len_d_ + shift;
/* SOURCE macro.for:242 */
/*<       if(new_line_len.gt.max_line_len)then >*/
		if (feq_gen_new_line_len_d_ > *feq_gen_max_line_len_d_) {
/* SOURCE macro.for:243 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE macro.for:244 */
/*<       new_line_len=max_line_len >*/
		    feq_gen_new_line_len_d_ = *feq_gen_max_line_len_d_;
/* SOURCE macro.for:245 */
/*<       else >*/
		} else {
/*               Compute the start point for the search after */
/*               symbol replacement. */
/* SOURCE macro.for:248 */
/*<       is=i+actual_len >*/
		    is = feq_gen_i_d_ + *feq_gen_actual_len_d_;
/*                WRITE(STDOUT,*) ' IS=',IS,' NEW_LINE_LEN=',NEW_LINE_LEN */
/*                WRITE(STDOUT,*) ' I+DUMMY_LEN=',I+DUMMY_LEN, */
/*     A                          ' LINE_LEN=', LINE_LEN */
/*                WRITE(STDOUT,*) ' Line before shift:',LINE(1:LINE_LEN) */
/*                WRITE(STDOUT,*) ' Tail to shift=', */
/*     A                           LINE(I+DUMMY_LEN:LINE_LEN) */
/* SOURCE macro.for:255 */
/*<       temp_len=line_len-(i+dummy_len)+1 >*/
		    feq_gen_temp_len_d_ = *feq_gen_line_len_d_ - (feq_gen_i_d_ + *feq_gen_dummy_len_d_) + 1;
/* SOURCE macro.for:256 */
/*<       temp=line(i+dummy_len:line_len) >*/
		    feq_gen_i_d_1 = feq_gen_i_d_ + *feq_gen_dummy_len_d_ - 1;
		    s_copy(temp, line + feq_gen_i_d_1, (ftnlen)196, *feq_gen_line_len_d_ - feq_gen_i_d_1)
			    ;
/*                WRITE(STDOUT,*) ' TEMP=',TEMP(1:TEMP_LEN) */
/*                WRITE(STDOUT,*) ' TEMP_LEN=',TEMP_LEN */
/* SOURCE macro.for:259 */
/*<       line(is:)=temp(1:temp_len) >*/
		    s_copy(line + (is - 1), temp, 196 - (is - 1), feq_gen_temp_len_d_);
/*                WRITE(STDOUT,*) ' Line after shift:', */
/*     A                           LINE(1:NEW_LINE_LEN) */
/*               Insert the new identifier */
/* SOURCE macro.for:263 */
/*<       line(i:is-1)=actual(1:actual_len) >*/
		    s_copy(line + (feq_gen_i_d_ - 1), actual, is - 1 - (feq_gen_i_d_ - 1), (*
			    feq_gen_actual_len_d_));
/*                WRITE(STDOUT,*) ' Line after insert:', */
/*     A                               LINE(1:NEW_LINE_LEN) */
/* SOURCE macro.for:267 */
/*<       line_len=new_line_len >*/
		    *feq_gen_line_len_d_ = feq_gen_new_line_len_d_;
/* SOURCE macro.for:268 */
/*<       endif >*/
		}
/* SOURCE macro.for:269 */
/*<       goto100 >*/
		goto L100;
/* SOURCE macro.for:270 */
/*<       endif >*/
	    }
/* SOURCE macro.for:271 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE macro.for:272 */
/*<       endif >*/
	}
/* SOURCE macro.for:273 */
/*<       endif >*/
    }
/*        WRITE(STDOUT,*) ' At exit: LINE=',LINE(1:LINE_LEN), */
/*     A                  ' LINE_LEN=', LINE_LEN */
/* SOURCE macro.for:276 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:277 */
/*<       end >*/
} /* identifier_replace__ */

/*     *********** */
/*     *         * */
/*     * MACRO_SYMBOL_INIT */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:286 */
/*<       subroutinemacro_symbol_init() >*/
/* Subroutine */ int feq_gen_macro_symbol_init_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Initialize the macro instruction and symbol table facility. */
/* SOURCE macro.for:290 */
/*<       implicitnone >*/
/* INCLUDE macro.for:292 */
/*     Variables for macro instruction processing in the */
/*     Network-Matrix Control Input. */
/* SOURCE macro.cmn:4 */
/*<       integermax_macro,max_body,max_arg,max_stack >*/
/* SOURCE macro.cmn:7 */
/*<       parameter(max_macro=200,max_body=600,max_arg=600,max_stack=100) >*/
/* SOURCE macro.cmn:10 */
/*<        >*/
/* SOURCE macro.cmn:14 */
/*<        >*/
/* SOURCE macro.cmn:24 */
/*<       common/macro_c/macro_body,macro_stack,macro_arg >*/
/* SOURCE macro.cmn:25 */
/*<        >*/
/* SOURCE macro.cmn:30 */
/*<       save/macro_c/,/macro_i/ >*/
/*     Definitions */
/*     MACRO_BODY_PNT(I) - points to the first line of the */
/*                             macro body.  The value of I is */
/*                             stored in the global symbol list. */
/*                             Thus the macro name is found in the */
/*                             global symbol list, it points into */
/*                             the macro_body_pointer, and that */
/*                             points to the row contining the first */
/*                             line of the macro body. */
/*     MACRO_BODY_KNT(I)  - number of lines in the macro body */
/*     MACRO_ARG_PNT(I) -  points to the first argument in the */
/*                         MACRO-ARG(*). */
/*     MACRO_ARG_KNT(I) -  gives the number of arguments for this macro */
/*     MACRO_ARG(J) -   macro argument identifiers. */
/*     MACRO_ARG_LEN(J)  - length of the macro dummy argment. */
/*     MACRO_BODY(K) - contains the macro body.  Pointed to by */
/*                     MACRO_BODY_POINTER */
/*     MACRO_LINE_LEN(K) - length of the line in the macro body. */
/*     MACRO_STACK_TOP - pointer to the currently filled top of stack. */
/*                       Zero means that stack is empty.  Increment */
/*                       adds to the stack, decrement deletes from */
/*                       stack. */
/*     LAST_MACRO  - Pointer to the last used location in the macro */
/*                   table.  Starts at 0. */
/*     LAST_BODY  - Pointer to the last used location in the */
/*                  macro body table.  Starts at 0. */
/*     LAST_ARG  - pointer to the last used location in the */
/*                 macro argument table.  Starts at 0. */
/* INCLUDE macro.for:293 */
/*     Symbol table for processing FEQ. */
/* SOURCE symbol.cmn:3 */
/*<       integermax_symbol >*/
/* SOURCE symbol.cmn:4 */
/*<       parameter(max_symbol=250) >*/
/* SOURCE symbol.cmn:6 */
/*<       character*16symbol(max_symbol) >*/
/* SOURCE symbol.cmn:8 */
/*<        >*/
/* SOURCE symbol.cmn:11 */
/*<       common/symbol_c/symbol >*/
/* SOURCE symbol.cmn:13 */
/*<       common/symbol_i/symbol_class,symbol_value,last_symbol >*/
/* SOURCE symbol.cmn:15 */
/*<       save/symbol_c/,/symbol_i/ >*/
/*     Local */
/* SOURCE macro.for:296 */
/*<       integervariable_arguments_class >*/
/* SOURCE macro.for:297 */
/*<       parameter(variable_arguments_class=3) >*/
/* ********************************************************************** */
/*     Clear the top of stack pointer. */
/* SOURCE macro.for:301 */
/*<       macro_stack_top=0 >*/
    feq_gen_macro_i_d_1.feq_gen_macro_stack_top_d_ = 0;
/*     Clear the various counters */
/* SOURCE macro.for:305 */
/*<       last_arg=0 >*/
    feq_gen_macro_i_d_1.feq_gen_last_arg_d_ = 0;
/* SOURCE macro.for:306 */
/*<       last_macro=0 >*/
    feq_gen_macro_i_d_1.feq_gen_last_macro_d_ = 0;
/* SOURCE macro.for:307 */
/*<       last_body=0 >*/
    feq_gen_macro_i_d_1.feq_gen_last_body_d_ = 0;
/*     Add the special instructions for sum of flows being zero. */
/* SOURCE macro.for:310 */
/*<       last_symbol=1 >*/
    feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ = 1;
/* SOURCE macro.for:311 */
/*<       symbol(last_symbol)='SUMQ' >*/
    s_copy(feq_gen_symbol_c_d_1.symbol + (feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1 << 4), const_cast<char*>("SUMQ"), 
	    (ftnlen)16, (ftnlen)4);
/* SOURCE macro.for:312 */
/*<       symbol_class(last_symbol)=variable_arguments_class >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_class_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 3;
/* SOURCE macro.for:313 */
/*<       symbol_value(last_symbol)=2 >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_value_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 2;
/* SOURCE macro.for:315 */
/*<       last_symbol=2 >*/
    feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ = 2;
/* SOURCE macro.for:316 */
/*<       symbol(last_symbol)='SQ' >*/
    s_copy(feq_gen_symbol_c_d_1.symbol + (feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1 << 4), const_cast<char*>("SQ"), (
	    ftnlen)16, (ftnlen)2);
/* SOURCE macro.for:317 */
/*<       symbol_class(last_symbol)=variable_arguments_class >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_class_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 3;
/* SOURCE macro.for:318 */
/*<       symbol_value(last_symbol)=2 >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_value_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 2;
/* SOURCE macro.for:320 */
/*<       last_symbol=3 >*/
    feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ = 3;
/* SOURCE macro.for:321 */
/*<       symbol(last_symbol)='QSUM' >*/
    s_copy(feq_gen_symbol_c_d_1.symbol + (feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1 << 4), const_cast<char*>("QSUM"), 
	    (ftnlen)16, (ftnlen)4);
/* SOURCE macro.for:322 */
/*<       symbol_class(last_symbol)=variable_arguments_class >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_class_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 3;
/* SOURCE macro.for:323 */
/*<       symbol_value(last_symbol)=2 >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_value_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 2;
/* SOURCE macro.for:325 */
/*<       last_symbol=4 >*/
    feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ = 4;
/* SOURCE macro.for:326 */
/*<       symbol(last_symbol)='SumQ' >*/
    s_copy(feq_gen_symbol_c_d_1.symbol + (feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1 << 4), const_cast<char*>("SumQ"), 
	    (ftnlen)16, (ftnlen)4);
/* SOURCE macro.for:327 */
/*<       symbol_class(last_symbol)=variable_arguments_class >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_class_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 3;
/* SOURCE macro.for:328 */
/*<       symbol_value(last_symbol)=2 >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_value_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 2;
/* SOURCE macro.for:330 */
/*<       last_symbol=5 >*/
    feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ = 5;
/* SOURCE macro.for:331 */
/*<       symbol(last_symbol)='sumq' >*/
    s_copy(feq_gen_symbol_c_d_1.symbol + (feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1 << 4), const_cast<char*>("sumq"), 
	    (ftnlen)16, (ftnlen)4);
/* SOURCE macro.for:332 */
/*<       symbol_class(last_symbol)=variable_arguments_class >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_class_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 3;
/* SOURCE macro.for:333 */
/*<       symbol_value(last_symbol)=2 >*/
    feq_gen_symbol_i_d_1.feq_gen_symbol_value_d_[feq_gen_symbol_i_d_1.feq_gen_last_symbol_d_ - 1] = 2;
/* SOURCE macro.for:335 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:336 */
/*<       end >*/
} /* macro_symbol_init__ */

/*     *********** */
/*     *         * */
/*     * DEFINE_MACRO */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:347 */
/*<       subroutinedefine_macro(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_define_macro_d_(integer *stdin, integer *stdout, integer *
	eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:303* File named:\002,a,/,5x,\002 no\
t found. Check\002,\002 spelling of macro instruction file.\002)";
    static char fmt_52[] = "(/,\002 *ERR:304* File name:\002,a,/,5x,\002foun\
d in current\002,\002 macro instruction file.\002,/,5x,\002File reference in\
 a\002,\002 macro instruction file is not supported.\002)";
    static char fmt_54[] = "(/,\002 *ERR:305* Macro instruction file name ex\
pected but\002,\002 none found.\002)";
    static char fmt_56[] = "(/,\002 *ERR:306* Identifer: FILE is reserved bu\
t appears\002,\002 as a macro instruction.\002)";
    static char fmt_58[] = "(/,\002 *ERR:307* Macro instruction table overfl\
ow.\002,\002 Number=\002,i5)";
    static char fmt_60[] = "(/,\002 *ERR:308* Macro instruction: \002,a,\002\
 already\002,\002 defined.\002)";
    static char fmt_62[] = "(/,\002 *ERR:309* Macro instruction argument:\
 \002,a,\002 is invalid.  Must be an identifier.\002)";
    static char fmt_64[] = "(/,\002 *ERR:310* END found before a macro instr\
uction\002,\002 name was found.\002)";
    static char fmt_66[] = "(/,\002 *ERR:311* Macro instruction name; \002\
,a,\002 has no\002,\002 arguments.\002)";
    static char fmt_68[] = "(/,\002 *ERR:312* Macro instruction argument tab\
le overflow.\002,\002 Number=\002,i5)";
    static char fmt_70[] = "(/,\002 *ERR:313* Expecting a macro instruction \
name but\002,\002 found:\002,/,5x,a)";
    static char fmt_72[] = "(/,\002 *ERR:314* Macro instruction body table o\
verflow.\002,\002 Number=\002,i5)";
    static char fmt_74[] = "(/,\002 Processing macro file: \002,a)";
    static char fmt_76[] = "(/,\002 Closing macro file: \002,a)";
    static char fmt_78[] = "(\002 \002,a)";
    static char fmt_82[] = "(/,\002 *ERR:315* Instruction definition has mor\
e than two\002,\002 arguments.\002)";
    static char fmt_84[] = "(/,\002 *ERR:316* Macro instruction: \002,a,\002\
 not terminated.\002,/,11x,\002Check spelling of name following END.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), f_inqu(inlist *), f_open(
	    olist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli();

    /* Local variables */
    extern integer feq_gen_get_unit_d_(integer *);
    integer feq_gen_i_d_, n, feq_gen_file_flag_d_;
    char feq_gen_long_line_d_[196];
    integer feq_gen_file_unit_d_;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    integer feq_gen_item_type_d_[30], feq_gen_macro_name_length_d_, it, feq_gen_macro_flag_d_;
    extern /* Subroutine */ int feq_gen_lsa_global_d_(integer *, char *, integer *, 
	    integer *, integer *, integer *, ftnlen);
    char feq_gen_macro_name_d_[16];
    integer feq_gen_input_unit_d_, opt, feq_gen_macro_lines_d_, feq_gen_flag_d_, clen[30];
    char cval[256*30], line[200];
    integer ival[30], nval, indx;
    real rval[30];
    char term[1*30];
    integer feq_gen_class_d_;
    doublereal dpval[30];
    logical there;
    integer value, terml[30];
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen), 
	    feq_gen_maybe_add_home_d_(char *, ftnlen), inline_(integer *, integer *, 
	    char *, ftnlen), getval_(integer *, char *, integer *, integer *, 
	    integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);
    char feq_gen_macro_file_name_d_[256];
    integer termcls[30];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__21 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__37 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__56 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_72, 0 };


/*     Input the macro definitions. */
/* SOURCE macro.for:351 */
/*<       implicitnone >*/
/* SOURCE macro.for:353 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE macro.for:355 */
/*     Variables for macro instruction processing in the */
/*     Network-Matrix Control Input. */
/* SOURCE macro.cmn:4 */
/*<       integermax_macro,max_body,max_arg,max_stack >*/
/* SOURCE macro.cmn:7 */
/*<       parameter(max_macro=200,max_body=600,max_arg=600,max_stack=100) >*/
/* SOURCE macro.cmn:10 */
/*<        >*/
/* SOURCE macro.cmn:14 */
/*<        >*/
/* SOURCE macro.cmn:24 */
/*<       common/macro_c/macro_body,macro_stack,macro_arg >*/
/* SOURCE macro.cmn:25 */
/*<        >*/
/* SOURCE macro.cmn:30 */
/*<       save/macro_c/,/macro_i/ >*/
/*     Definitions */
/*     MACRO_BODY_PNT(I) - points to the first line of the */
/*                             macro body.  The value of I is */
/*                             stored in the global symbol list. */
/*                             Thus the macro name is found in the */
/*                             global symbol list, it points into */
/*                             the macro_body_pointer, and that */
/*                             points to the row contining the first */
/*                             line of the macro body. */
/*     MACRO_BODY_KNT(I)  - number of lines in the macro body */
/*     MACRO_ARG_PNT(I) -  points to the first argument in the */
/*                         MACRO-ARG(*). */
/*     MACRO_ARG_KNT(I) -  gives the number of arguments for this macro */
/*     MACRO_ARG(J) -   macro argument identifiers. */
/*     MACRO_ARG_LEN(J)  - length of the macro dummy argment. */
/*     MACRO_BODY(K) - contains the macro body.  Pointed to by */
/*                     MACRO_BODY_POINTER */
/*     MACRO_LINE_LEN(K) - length of the line in the macro body. */
/*     MACRO_STACK_TOP - pointer to the currently filled top of stack. */
/*                       Zero means that stack is empty.  Increment */
/*                       adds to the stack, decrement deletes from */
/*                       stack. */
/*     LAST_MACRO  - Pointer to the last used location in the macro */
/*                   table.  Starts at 0. */
/*     LAST_BODY  - Pointer to the last used location in the */
/*                  macro body table.  Starts at 0. */
/*     LAST_ARG  - pointer to the last used location in the */
/*                 macro argument table.  Starts at 0. */
/* SOURCE macro.for:357 */
/*<       externalos_file_style,maybe_add_home >*/
/*     Local variables */
/* SOURCE macro.for:362 */
/*<       characterline*200,long_line*196,macro_file_name*256 >*/
/* SOURCE macro.for:364 */
/*<       integermax_nval >*/
/* SOURCE macro.for:366 */
/*<       parameter(max_nval=30) >*/
/* SOURCE macro.for:368 */
/*<       integerchrval,intval >*/
/* SOURCE macro.for:369 */
/*<       parameter(intval=1,chrval=4) >*/
/* SOURCE macro.for:371 */
/*<       integermacro_class,instruction_class,variable_arguments_class >*/
/* SOURCE macro.for:372 */
/*<        >*/
/* SOURCE macro.for:375 */
/*<       logicalthere >*/
/* SOURCE macro.for:377 */
/*<        >*/
/* SOURCE macro.for:381 */
/*<        >*/
/* SOURCE macro.for:383 */
/*<       realrval(max_nval) >*/
/* SOURCE macro.for:384 */
/*<       real*8dpval(max_nval) >*/
/* SOURCE macro.for:385 */
/*<       charactercval(max_nval)*256,term(max_nval)*1,macro_name*16 >*/
/*     Called program units and intrinsics. */
/* SOURCE macro.for:388 */
/*<       integerlenstr,get_unit >*/
/* SOURCE macro.for:390 */
/*<        >*/
/* SOURCE macro.for:393 */
/*<       intrinsicindex >*/
/*     ******************************FORMATS***************************** */
/* SOURCE macro.for:395 */
/*<    50  >*/
/* SOURCE macro.for:397 */
/*<    52  >*/
/* SOURCE macro.for:400 */
/*<    54  >*/
/* SOURCE macro.for:402 */
/*<    56  >*/
/* SOURCE macro.for:404 */
/*<    58  >*/
/* SOURCE macro.for:406 */
/*<    60  >*/
/* SOURCE macro.for:408 */
/*<    62  >*/
/* SOURCE macro.for:410 */
/*<    64  >*/
/* SOURCE macro.for:412 */
/*<    66  >*/
/* SOURCE macro.for:414 */
/*<    68  >*/
/* SOURCE macro.for:416 */
/*<    70  >*/
/* SOURCE macro.for:418 */
/*<    72  >*/
/* SOURCE macro.for:420 */
/*<    74 format(/,' Processing macro file: ',a) >*/
/* SOURCE macro.for:421 */
/*<    76 format(/,' Closing macro file: ',a) >*/
/* SOURCE macro.for:422 */
/*<    78 format(' ',a) >*/
/* SOURCE macro.for:423 */
/*<    82  >*/
/* SOURCE macro.for:425 */
/*<    84  >*/
/* *********************************************************************** */
/*     At entry the heading for the DEFINE MACROS block has been processed. */
/*     The lines can be up to 196 characters wide in the DEFINE MACROS */
/*     block. */
/*     Clear the counters. */
/* SOURCE macro.for:433 */
/*<       last_macro=0 >*/
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
/* L70: */
/* L72: */
/* L74: */
/* L76: */
/* L78: */
/* L82: */
/* L84: */
    feq_gen_macro_i_d_1.feq_gen_last_macro_d_ = 0;
/* SOURCE macro.for:434 */
/*<       last_body=0 >*/
    feq_gen_macro_i_d_1.feq_gen_last_body_d_ = 0;
/* SOURCE macro.for:435 */
/*<       last_arg=0 >*/
    feq_gen_macro_i_d_1.feq_gen_last_arg_d_ = 0;
/*     Clear the macro flag.  Set when a macro name has been found. */
/* SOURCE macro.for:438 */
/*<       macro_flag=0 >*/
    feq_gen_macro_flag_d_ = 0;
/*     Clear the file flag.  Set when a macro file is being processed. */
/* SOURCE macro.for:441 */
/*<       file_flag=0 >*/
    feq_gen_file_flag_d_ = 0;
/* SOURCE macro.for:442 */
/*<       file_unit=0 >*/
    feq_gen_file_unit_d_ = 0;
/* SOURCE macro.for:443 */
/*<   100 continue >*/
L100:
/* SOURCE macro.for:445 */
/*<       if(file_flag.eq.0)then >*/
    if (feq_gen_file_flag_d_ == 0) {
/* SOURCE macro.for:446 */
/*<       input_unit=stdin >*/
	feq_gen_input_unit_d_ = *stdin;
/* SOURCE macro.for:447 */
/*<       else >*/
    } else {
/* SOURCE macro.for:448 */
/*<       input_unit=file_unit >*/
	feq_gen_input_unit_d_ = feq_gen_file_unit_d_;
/* SOURCE macro.for:449 */
/*<       endif >*/
    }
/*       Get the next line of input.  Could be in the current macro */
/*       file as well as in the user input file. */
/* SOURCE macro.for:453 */
/*<       callinline(input_unit,stdout,long_line) >*/
    inline_(&feq_gen_input_unit_d_, stdout, feq_gen_long_line_d_, (ftnlen)196);
/* SOURCE macro.for:456 */
/*<       if(input_unit.eq.file_unit)then >*/
    if (feq_gen_input_unit_d_ == feq_gen_file_unit_d_) {
/*         Check for end of file on the macro instruction file. */
/* SOURCE macro.for:458 */
/*<       if(long_line(1:7).eq.'ENDFILE')then >*/
	if (s_cmp(feq_gen_long_line_d_, const_cast<char*>("ENDFILE"), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE macro.for:459 */
/*<       callfree_unit(stdout,file_unit) >*/
	    feq_gen_free_unit_d_(stdout, &feq_gen_file_unit_d_);
/* SOURCE macro.for:460 */
/*<       write(stdout,76)macro_file_name >*/
	    feq_gen_io_d__18.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__18);
	    do_fio(&feq_gen_c_d_1, feq_gen_macro_file_name_d_, (ftnlen)256);
	    e_wsfe();
/* SOURCE macro.for:461 */
/*<       file_flag=0 >*/
	    feq_gen_file_flag_d_ = 0;
/* SOURCE macro.for:462 */
/*<       goto9000 >*/
	    goto L9000;
/* SOURCE macro.for:463 */
/*<       endif >*/
	}
/* SOURCE macro.for:464 */
/*<       endif >*/
    }
/* SOURCE macro.for:466 */
/*<       n=lenstr(long_line) >*/
    n = lenstr_(feq_gen_long_line_d_, (ftnlen)196);
/* SOURCE macro.for:467 */
/*<       write(stdout,78)long_line(1:n) >*/
    feq_gen_io_d__21.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__21);
    do_fio(&feq_gen_c_d_1, feq_gen_long_line_d_, n);
    e_wsfe();
/* SOURCE macro.for:468 */
/*<       if(macro_flag.eq.0)then >*/
    if (feq_gen_macro_flag_d_ == 0) {
/*         Looking for a macro name. */
/* SOURCE macro.for:470 */
/*<       line=long_line >*/
	s_copy(line, feq_gen_long_line_d_, (ftnlen)200, (ftnlen)196);
/*          CALL TO_UPPER ( */
/*     M                   LINE) */
/*         Search for user given quote. */
/* SOURCE macro.for:474 */
/*<       i=index(line,'''') >*/
	feq_gen_i_d_ = i_indx(line, const_cast<char*>("'"), (ftnlen)200, (ftnlen)1);
/* SOURCE macro.for:475 */
/*<       if(i.eq.0)then >*/
	if (feq_gen_i_d_ == 0) {
/* SOURCE macro.for:476 */
/*<       it=lenstr(line) >*/
	    it = lenstr_(line, (ftnlen)200);
/* SOURCE macro.for:477 */
/*<       line(it+1:it+1)='''' >*/
	    feq_gen_i_d_1 = it;
	    s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE macro.for:478 */
/*<       else >*/
	} else {
/*           Revise user quote to  ,quote */
/*            LINE(I:I+2) = ' ,''' */
/* SOURCE macro.for:481 */
/*<       endif >*/
	}
/* SOURCE macro.for:483 */
/*<       opt=1 >*/
	opt = 1;
/* SOURCE macro.for:484 */
/*<        >*/
	getval_(stdout, line, &feq_gen_c_d_30, &opt, feq_gen_item_type_d_, ival, rval, dpval, 
		cval, clen, eflag, term, terml, termcls, &nval, (ftnlen)200, (
		ftnlen)256, (ftnlen)1);
/*          WRITE(STDOUT,*) */
/*     A       ' Return from GETVAL in DEFINE_MACRO: NVAL=',NVAL */
/*          DO 9213 I=1,NVAL */
/*            WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I) */
/* 99    FORMAT(' ',A12,' ',I5,' ',I5,' ',A1) */
/* 9213  CONTINUE */
/*         Trim off the end of line item. */
/*          NVAL = NVAL - 1 */
/* SOURCE macro.for:497 */
/*<       if(item_type(1).eq.chrval)then >*/
	if (feq_gen_item_type_d_[0] == 4) {
/*           Found an identifier.  Is it a file reference? */
/* SOURCE macro.for:499 */
/*<       if(cval(1)(1:4).eq.'FILE')then >*/
	    if (s_cmp(cval, const_cast<char*>("FILE"), (ftnlen)4, (ftnlen)4) == 0) {
/*             Yes, looks like it could be. */
/* SOURCE macro.for:501 */
/*<       if(term(1).eq.'=')then >*/
		if (*(unsigned char *)&term[0] == '=') {
/* SOURCE macro.for:502 */
/*<       if(item_type(2).eq.chrval)then >*/
		    if (feq_gen_item_type_d_[1] == 4) {
/*                 This is a file reference. */
/* SOURCE macro.for:504 */
/*<       if(file_flag.eq.0)then >*/
			if (feq_gen_file_flag_d_ == 0) {
/*                   Open the file. */
/* SOURCE macro.for:506 */
/*<       macro_file_name=cval(2) >*/
			    s_copy(feq_gen_macro_file_name_d_, cval + 256, (ftnlen)256,
				     (ftnlen)256);
/* SOURCE macro.for:507 */
/*<       callmaybe_add_home(macro_file_name) >*/
			    feq_gen_maybe_add_home_d_(feq_gen_macro_file_name_d_, (ftnlen)256);
/* SOURCE macro.for:509 */
/*<       callos_file_style(macro_file_name) >*/
			    feq_gen_os_file_style_d_(feq_gen_macro_file_name_d_, (ftnlen)256);
/* SOURCE macro.for:511 */
/*<       inquire(file=macro_file_name,exist=there) >*/
			    feq_gen_ioin_d_1.inerr = 0;
			    feq_gen_ioin_d_1.infilen = 256;
			    feq_gen_ioin_d_1.infile = feq_gen_macro_file_name_d_;
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
/* SOURCE macro.for:512 */
/*<       if(there)then >*/
			    if (there) {
/* SOURCE macro.for:513 */
/*<       file_unit=get_unit(stdout) >*/
				feq_gen_file_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE macro.for:514 */
/*<       open(unit=file_unit,file=macro_file_name,status='OLD') >*/
				feq_gen_o_d_1.oerr = 0;
				feq_gen_o_d_1.ounit = feq_gen_file_unit_d_;
				feq_gen_o_d_1.ofnmlen = 256;
				feq_gen_o_d_1.ofnm = feq_gen_macro_file_name_d_;
				feq_gen_o_d_1.orl = 0;
				feq_gen_o_d_1.osta = const_cast<char*>("OLD");
				feq_gen_o_d_1.oacc = 0;
				feq_gen_o_d_1.ofm = 0;
				feq_gen_o_d_1.oblnk = 0;
				f_open(&feq_gen_o_d_1);
/* SOURCE macro.for:516 */
/*<       file_flag=1 >*/
				feq_gen_file_flag_d_ = 1;
/* SOURCE macro.for:517 */
/*<       write(stdout,74)macro_file_name >*/
				feq_gen_io_d__37.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__37);
				do_fio(&feq_gen_c_d_1, feq_gen_macro_file_name_d_, (ftnlen)256);
				e_wsfe();
/* SOURCE macro.for:518 */
/*<       goto9000 >*/
				goto L9000;
/* SOURCE macro.for:519 */
/*<       else >*/
			    } else {
/* SOURCE macro.for:520 */
/*<       write(stdout,50)macro_file_name >*/
				feq_gen_io_d__38.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__38);
				do_fio(&feq_gen_c_d_1, feq_gen_macro_file_name_d_, (ftnlen)256);
				e_wsfe();
/* SOURCE macro.for:521 */
/*<       stop'Abnormal stop: errors found.' >*/
				s_stop(const_cast<char*>("Abnormal stop: errors found."), (
					ftnlen)28);
/* SOURCE macro.for:522 */
/*<       endif >*/
			    }
/* SOURCE macro.for:523 */
/*<       else >*/
			} else {
/*                   File reference in a macro instruction file */
/*                   is not supported. */
/* SOURCE macro.for:526 */
/*<       write(stdout,52)cval(2) >*/
			    feq_gen_io_d__39.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__39);
			    do_fio(&feq_gen_c_d_1, cval + 256, (ftnlen)256);
			    e_wsfe();
/* SOURCE macro.for:527 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE macro.for:528 */
/*<       endif >*/
			}
/* SOURCE macro.for:529 */
/*<       else >*/
		    } else {
/*                 File name expected but none found. */
/* SOURCE macro.for:531 */
/*<       write(stdout,54) >*/
			feq_gen_io_d__40.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__40);
			e_wsfe();
/* SOURCE macro.for:532 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:533 */
/*<       endif >*/
		    }
/* SOURCE macro.for:534 */
/*<       else >*/
		} else {
/*               Identifier 'FILE' is reserved. */
/* SOURCE macro.for:536 */
/*<       write(stdout,56) >*/
		    feq_gen_io_d__41.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__41);
		    e_wsfe();
/* SOURCE macro.for:537 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:538 */
/*<       endif >*/
		}
/* SOURCE macro.for:540 */
/*<       elseif(cval(1)(1:3).eq.'END')then >*/
	    } else if (s_cmp(cval, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE macro.for:542 */
/*<       if(cval(2)(1:6).eq.'MACROS')then >*/
		if (s_cmp(cval + 256, const_cast<char*>("MACROS"), (ftnlen)6, (ftnlen)6) == 0) {
/*               All macro definitions are completed. */
/* SOURCE macro.for:544 */
/*<       goto9001 >*/
		    goto L9001;
/* SOURCE macro.for:545 */
/*<       else >*/
		} else {
/* SOURCE macro.for:546 */
/*<       write(stdout,64) >*/
		    feq_gen_io_d__42.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__42);
		    e_wsfe();
/* SOURCE macro.for:547 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:548 */
/*<       endif >*/
		}
/* SOURCE macro.for:550 */
/*<       elseif(item_type(2).eq.intval)then >*/
	    } else if (feq_gen_item_type_d_[1] == 1) {
/*             Assume an  instruction here. */
/* SOURCE macro.for:552 */
/*<       macro_name=cval(1) >*/
		s_copy(feq_gen_macro_name_d_, cval, (ftnlen)16, (ftnlen)256);
/* SOURCE macro.for:553 */
/*<       macro_name_length=clen(1) >*/
		feq_gen_macro_name_length_d_ = clen[0];
/* SOURCE macro.for:554 */
/*<       read(cval(2)(1:clen(2)),*)value >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[1];
		feq_gen_ici_d_1.iciunit = cval + 256;
		feq_gen_ici_d_1.icifmt = 0;
		s_rsli(&feq_gen_ici_d_1);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(integer));
		e_rsli();
/* SOURCE macro.for:555 */
/*<       if(nval.eq.2)then >*/
		if (nval == 2) {
/*               Simple value replacement instruction */
/* SOURCE macro.for:557 */
/*<       class=instruction_class >*/
		    feq_gen_class_d_ = 2;
/* SOURCE macro.for:558 */
/*<       elseif(nval.eq.3)then >*/
		} else if (nval == 3) {
/*               Special case for Code 2: Sum of flows is zero. */
/* SOURCE macro.for:560 */
/*<       class=variable_arguments_class >*/
		    feq_gen_class_d_ = 3;
/* SOURCE macro.for:561 */
/*<       value=2 >*/
		    value = 2;
/* SOURCE macro.for:562 */
/*<       else >*/
		} else {
/* SOURCE macro.for:563 */
/*<       write(stdout,82)nval >*/
		    feq_gen_io_d__47.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__47);
		    do_fio(&feq_gen_c_d_1, (char *)&nval, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE macro.for:564 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:565 */
/*<       endif >*/
		}
/* SOURCE macro.for:567 */
/*<       calllsa_global(stdout,macro_name,class,value,indx,flag) >*/
		feq_gen_lsa_global_d_(stdout, feq_gen_macro_name_d_, &feq_gen_class_d_, &value, &indx, &
			feq_gen_flag_d_, (ftnlen)16);
/* SOURCE macro.for:571 */
/*<       if(flag.eq.1)then >*/
		if (feq_gen_flag_d_ == 1) {
/*               Problem.  Macro name is already in the table. */
/* SOURCE macro.for:573 */
/*<       write(stdout,60)macro_name >*/
		    feq_gen_io_d__50.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__50);
		    do_fio(&feq_gen_c_d_1, feq_gen_macro_name_d_, (ftnlen)16);
		    e_wsfe();
/* SOURCE macro.for:574 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:575 */
/*<       elseif(flag.eq.2)then >*/
		} else if (feq_gen_flag_d_ == 2) {
/* SOURCE macro.for:576 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:577 */
/*<       endif >*/
		}
/* SOURCE macro.for:578 */
/*<       else >*/
	    } else {
/*             Assume macro name here. */
/* SOURCE macro.for:580 */
/*<       macro_flag=1 >*/
		feq_gen_macro_flag_d_ = 1;
/* SOURCE macro.for:581 */
/*<       macro_name=cval(1) >*/
		s_copy(feq_gen_macro_name_d_, cval, (ftnlen)16, (ftnlen)256);
/* SOURCE macro.for:582 */
/*<       macro_name_length=clen(1) >*/
		feq_gen_macro_name_length_d_ = clen[0];
/*             Determine its location in the macro table. */
/* SOURCE macro.for:584 */
/*<       last_macro=last_macro+1 >*/
		++feq_gen_macro_i_d_1.feq_gen_last_macro_d_;
/* SOURCE macro.for:585 */
/*<       if(last_macro.gt.max_macro)then >*/
		if (feq_gen_macro_i_d_1.feq_gen_last_macro_d_ > 200) {
/* SOURCE macro.for:586 */
/*<       write(stdout,58) >*/
		    feq_gen_io_d__51.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__51);
		    e_wsfe();
/* SOURCE macro.for:587 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:588 */
/*<       endif >*/
		}
/* SOURCE macro.for:589 */
/*<       class=macro_class >*/
		feq_gen_class_d_ = 1;
/* SOURCE macro.for:590 */
/*<       value=last_macro >*/
		value = feq_gen_macro_i_d_1.feq_gen_last_macro_d_;
/* SOURCE macro.for:591 */
/*<       calllsa_global(stdout,macro_name,class,value,indx,flag) >*/
		feq_gen_lsa_global_d_(stdout, feq_gen_macro_name_d_, &feq_gen_class_d_, &value, &indx, &
			feq_gen_flag_d_, (ftnlen)16);
/* SOURCE macro.for:595 */
/*<       if(flag.eq.1)then >*/
		if (feq_gen_flag_d_ == 1) {
/*               Problem.  Macro name is already in the table. */
/* SOURCE macro.for:597 */
/*<       write(stdout,60)macro_name >*/
		    feq_gen_io_d__52.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__52);
		    do_fio(&feq_gen_c_d_1, feq_gen_macro_name_d_, (ftnlen)16);
		    e_wsfe();
/* SOURCE macro.for:598 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:599 */
/*<       elseif(flag.eq.2)then >*/
		} else if (feq_gen_flag_d_ == 2) {
/* SOURCE macro.for:600 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:601 */
/*<       endif >*/
		}
/* SOURCE macro.for:603 */
/*<       if(nval.eq.1)then >*/
		if (nval == 1) {
/* SOURCE macro.for:604 */
/*<       write(stdout,66)macro_name >*/
		    feq_gen_io_d__53.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__53);
		    do_fio(&feq_gen_c_d_1, feq_gen_macro_name_d_, (ftnlen)16);
		    e_wsfe();
/* SOURCE macro.for:605 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:606 */
/*<       endif >*/
		}
/*             Check that all other values are of the */
/*             correct type. */
/* SOURCE macro.for:610 */
/*<       do110i=2,nval >*/
		feq_gen_i_d_1 = nval;
		for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE macro.for:611 */
/*<       if(item_type(i).ne.chrval)then >*/
		    if (feq_gen_item_type_d_[feq_gen_i_d_ - 1] != 4) {
/* SOURCE macro.for:612 */
/*<       write(stdout,62)cval(i)(1:clen(i)) >*/
			feq_gen_io_d__54.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__54);
			do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ - 1 << 8), clen[feq_gen_i_d_ - 1]);
			e_wsfe();
/* SOURCE macro.for:613 */
/*<       flag=1 >*/
			feq_gen_flag_d_ = 1;
/* SOURCE macro.for:614 */
/*<       endif >*/
		    }
/* SOURCE macro.for:615 */
/*<   110 continue >*/
/* L110: */
		}
/* SOURCE macro.for:616 */
/*<       if(flag.ne.0)then >*/
		if (feq_gen_flag_d_ != 0) {
/* SOURCE macro.for:617 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:618 */
/*<       endif >*/
		}
/*             Macro name appears to be valid.  Clear the */
/*             line counter and store the values currently known. */
/* SOURCE macro.for:622 */
/*<       macro_lines=0 >*/
		feq_gen_macro_lines_d_ = 0;
/* SOURCE macro.for:624 */
/*<       macro_body_pnt(last_macro)=last_body+1 >*/
		feq_gen_macro_i_d_1.feq_gen_macro_body_pnt_d_[feq_gen_macro_i_d_1.feq_gen_last_macro_d_ - 1] = 
			feq_gen_macro_i_d_1.feq_gen_last_body_d_ + 1;
/* SOURCE macro.for:625 */
/*<       macro_arg_knt(last_macro)=nval-1 >*/
		feq_gen_macro_i_d_1.feq_gen_macro_arg_knt_d_[feq_gen_macro_i_d_1.feq_gen_last_macro_d_ - 1] = 
			nval - 1;
/* SOURCE macro.for:626 */
/*<       macro_arg_pnt(last_macro)=last_arg+1 >*/
		feq_gen_macro_i_d_1.feq_gen_macro_arg_pnt_d_[feq_gen_macro_i_d_1.feq_gen_last_macro_d_ - 1] = 
			feq_gen_macro_i_d_1.feq_gen_last_arg_d_ + 1;
/*             Store the dummy argument names. */
/* SOURCE macro.for:628 */
/*<       do120i=2,nval >*/
		feq_gen_i_d_1 = nval;
		for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE macro.for:629 */
/*<       last_arg=last_arg+1 >*/
		    ++feq_gen_macro_i_d_1.feq_gen_last_arg_d_;
/* SOURCE macro.for:630 */
/*<       if(last_arg.gt.max_arg)then >*/
		    if (feq_gen_macro_i_d_1.feq_gen_last_arg_d_ > 600) {
/* SOURCE macro.for:631 */
/*<       write(stdout,68)last_arg >*/
			feq_gen_io_d__56.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__56);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_macro_i_d_1.feq_gen_last_arg_d_, (ftnlen)
				sizeof(integer));
			e_wsfe();
/* SOURCE macro.for:632 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:633 */
/*<       endif >*/
		    }
/* SOURCE macro.for:634 */
/*<       macro_arg(last_arg)=cval(i) >*/
		    s_copy(feq_gen_macro_c_d_1.feq_gen_macro_arg_d_ + (feq_gen_macro_i_d_1.feq_gen_last_arg_d_ - 
			    1 << 4), cval + (feq_gen_i_d_ - 1 << 8), (ftnlen)16, (
			    ftnlen)256);
/* SOURCE macro.for:635 */
/*<       macro_arg_len(last_arg)=clen(i) >*/
		    feq_gen_macro_i_d_1.feq_gen_macro_arg_len_d_[feq_gen_macro_i_d_1.feq_gen_last_arg_d_ - 1] = 
			    clen[feq_gen_i_d_ - 1];
/* SOURCE macro.for:636 */
/*<   120 continue >*/
/* L120: */
		}
/* SOURCE macro.for:637 */
/*<       endif >*/
	    }
/* SOURCE macro.for:638 */
/*<       else >*/
	} else {
/*           Expected Macro instruction name but found something */
/*           else. */
/* SOURCE macro.for:641 */
/*<       write(stdout,70)cval(i)(1:clen(1)) >*/
	    feq_gen_io_d__57.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__57);
	    do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ - 1 << 8), clen[0]);
	    e_wsfe();
/* SOURCE macro.for:642 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:643 */
/*<       endif >*/
	}
/* SOURCE macro.for:644 */
/*<       else >*/
    } else {
/*         We are in the body of a macro definition here. */
/*         We store the lines without examination.  Errors */
/*         will be detected after expansion in the normal */
/*         processing of the Network-Matrix Control Input. */
/* SOURCE macro.for:650 */
/*<       callstrip_l_blanks(long_line) >*/
	feq_gen_strip_l_blanks_d_(feq_gen_long_line_d_, (ftnlen)196);
/* SOURCE macro.for:653 */
/*<       if(long_line(1:3).eq.'END')then >*/
	if (s_cmp(feq_gen_long_line_d_, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) == 0) {
/*           The current macro instruction is done.  Store the */
/*           line count for the macro body and clear the */
/*           macro flag. */
/* SOURCE macro.for:657 */
/*<       macro_body_knt(last_macro)=macro_lines >*/
	    feq_gen_macro_i_d_1.feq_gen_macro_body_knt_d_[feq_gen_macro_i_d_1.feq_gen_last_macro_d_ - 1] = 
		    feq_gen_macro_lines_d_;
/* SOURCE macro.for:658 */
/*<       macro_flag=0 >*/
	    feq_gen_macro_flag_d_ = 0;
/*           Make sure that the end is for the correct name. */
/* SOURCE macro.for:660 */
/*<       i=index(long_line,macro_name(1:macro_name_length)) >*/
	    feq_gen_i_d_ = i_indx(feq_gen_long_line_d_, feq_gen_macro_name_d_, (ftnlen)196, 
		    feq_gen_macro_name_length_d_);
/* SOURCE macro.for:661 */
/*<       if(i.eq.0)then >*/
	    if (feq_gen_i_d_ == 0) {
/* SOURCE macro.for:662 */
/*<       write(stdout,84)macro_name(1:macro_name_length) >*/
		feq_gen_io_d__58.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__58);
		do_fio(&feq_gen_c_d_1, feq_gen_macro_name_d_, feq_gen_macro_name_length_d_);
		e_wsfe();
/* SOURCE macro.for:663 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:664 */
/*<       endif >*/
	    }
/* SOURCE macro.for:665 */
/*<       else >*/
	} else {
/*           Store the line in the body with its true length. */
/* SOURCE macro.for:667 */
/*<       last_body=last_body+1 >*/
	    ++feq_gen_macro_i_d_1.feq_gen_last_body_d_;
/* SOURCE macro.for:668 */
/*<       if(last_body.gt.max_body)then >*/
	    if (feq_gen_macro_i_d_1.feq_gen_last_body_d_ > 600) {
/* SOURCE macro.for:669 */
/*<       write(stdout,72)last_body >*/
		feq_gen_io_d__59.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__59);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_macro_i_d_1.feq_gen_last_body_d_, (ftnlen)sizeof(
			integer));
		e_wsfe();
/* SOURCE macro.for:670 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:671 */
/*<       endif >*/
	    }
/* SOURCE macro.for:672 */
/*<       macro_lines=macro_lines+1 >*/
	    ++feq_gen_macro_lines_d_;
/* SOURCE macro.for:673 */
/*<       macro_body(last_body)=long_line >*/
	    s_copy(feq_gen_macro_c_d_1.feq_gen_macro_body_d_ + (feq_gen_macro_i_d_1.feq_gen_last_body_d_ - 1) * 
		    196, feq_gen_long_line_d_, (ftnlen)196, (ftnlen)196);
/* SOURCE macro.for:674 */
/*<       macro_line_len(last_body)=lenstr(long_line) >*/
	    feq_gen_macro_i_d_1.feq_gen_macro_line_len_d_[feq_gen_macro_i_d_1.feq_gen_last_body_d_ - 1] = lenstr_(
		    feq_gen_long_line_d_, (ftnlen)196);
/* SOURCE macro.for:675 */
/*<       endif >*/
	}
/* SOURCE macro.for:676 */
/*<       endif >*/
    }
/* SOURCE macro.for:677 */
/*<  9000 continue >*/
L9000:
/* SOURCE macro.for:678 */
/*<       goto100 >*/
    goto L100;
/* SOURCE macro.for:680 */
/*<  9001 continue >*/
L9001:
/* SOURCE macro.for:681 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:682 */
/*<       end >*/
} /* define_macro__ */

/*     *********** */
/*     *         * */
/*     * PUSH_LINE */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:689 */
/*<       subroutinepush_line(stdout,line) >*/
/* Subroutine */ int feq_gen_push_line_d_(integer *stdout, char *line, ftnlen line_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:317* Macro instruction stack overfl\
ow.  Number=\002,i5)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_50, 0 };


/*     Put a line on the stack. */
/* SOURCE macro.for:692 */
/*<       implicitnone >*/
/* SOURCE macro.for:694 */
/*<       integerstdout >*/
/* SOURCE macro.for:695 */
/*<       character*196line >*/
/* INCLUDE macro.for:697 */
/*     Variables for macro instruction processing in the */
/*     Network-Matrix Control Input. */
/* SOURCE macro.cmn:4 */
/*<       integermax_macro,max_body,max_arg,max_stack >*/
/* SOURCE macro.cmn:7 */
/*<       parameter(max_macro=200,max_body=600,max_arg=600,max_stack=100) >*/
/* SOURCE macro.cmn:10 */
/*<        >*/
/* SOURCE macro.cmn:14 */
/*<        >*/
/* SOURCE macro.cmn:24 */
/*<       common/macro_c/macro_body,macro_stack,macro_arg >*/
/* SOURCE macro.cmn:25 */
/*<        >*/
/* SOURCE macro.cmn:30 */
/*<       save/macro_c/,/macro_i/ >*/
/*     Definitions */
/*     MACRO_BODY_PNT(I) - points to the first line of the */
/*                             macro body.  The value of I is */
/*                             stored in the global symbol list. */
/*                             Thus the macro name is found in the */
/*                             global symbol list, it points into */
/*                             the macro_body_pointer, and that */
/*                             points to the row contining the first */
/*                             line of the macro body. */
/*     MACRO_BODY_KNT(I)  - number of lines in the macro body */
/*     MACRO_ARG_PNT(I) -  points to the first argument in the */
/*                         MACRO-ARG(*). */
/*     MACRO_ARG_KNT(I) -  gives the number of arguments for this macro */
/*     MACRO_ARG(J) -   macro argument identifiers. */
/*     MACRO_ARG_LEN(J)  - length of the macro dummy argment. */
/*     MACRO_BODY(K) - contains the macro body.  Pointed to by */
/*                     MACRO_BODY_POINTER */
/*     MACRO_LINE_LEN(K) - length of the line in the macro body. */
/*     MACRO_STACK_TOP - pointer to the currently filled top of stack. */
/*                       Zero means that stack is empty.  Increment */
/*                       adds to the stack, decrement deletes from */
/*                       stack. */
/*     LAST_MACRO  - Pointer to the last used location in the macro */
/*                   table.  Starts at 0. */
/*     LAST_BODY  - Pointer to the last used location in the */
/*                  macro body table.  Starts at 0. */
/*     LAST_ARG  - pointer to the last used location in the */
/*                 macro argument table.  Starts at 0. */
/*     *****************************FORMATS****************************** */
/* SOURCE macro.for:699 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE macro.for:702 */
/*<       macro_stack_top=macro_stack_top+1 >*/
/* L50: */
    ++feq_gen_macro_i_d_1.feq_gen_macro_stack_top_d_;
/* SOURCE macro.for:703 */
/*<       if(macro_stack_top.gt.max_stack)then >*/
    if (feq_gen_macro_i_d_1.feq_gen_macro_stack_top_d_ > 100) {
/* SOURCE macro.for:704 */
/*<       write(stdout,50)macro_stack_top >*/
	feq_gen_io_d__60.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__60);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_macro_i_d_1.feq_gen_macro_stack_top_d_, (ftnlen)sizeof(
		integer));
	e_wsfe();
/* SOURCE macro.for:705 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:706 */
/*<       else >*/
    } else {
/* SOURCE macro.for:707 */
/*<       macro_stack(macro_stack_top)=line >*/
	s_copy(feq_gen_macro_c_d_1.feq_gen_macro_stack_d_ + (feq_gen_macro_i_d_1.feq_gen_macro_stack_top_d_ - 1) *
		 196, line, (ftnlen)196, (ftnlen)196);
/* SOURCE macro.for:708 */
/*<       endif >*/
    }
/* SOURCE macro.for:709 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:710 */
/*<       end >*/
} /* push_line__ */

/*     *********** */
/*     *         * */
/*     * POP_LINE */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:717 */
/*<       subroutinepop_line(line) >*/
/* Subroutine */ int feq_gen_pop_line_d_(char *line, ftnlen line_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Get a line from the stack. */
/* SOURCE macro.for:720 */
/*<       implicitnone >*/
/* SOURCE macro.for:722 */
/*<       character*196line >*/
/* INCLUDE macro.for:724 */
/*     Variables for macro instruction processing in the */
/*     Network-Matrix Control Input. */
/* SOURCE macro.cmn:4 */
/*<       integermax_macro,max_body,max_arg,max_stack >*/
/* SOURCE macro.cmn:7 */
/*<       parameter(max_macro=200,max_body=600,max_arg=600,max_stack=100) >*/
/* SOURCE macro.cmn:10 */
/*<        >*/
/* SOURCE macro.cmn:14 */
/*<        >*/
/* SOURCE macro.cmn:24 */
/*<       common/macro_c/macro_body,macro_stack,macro_arg >*/
/* SOURCE macro.cmn:25 */
/*<        >*/
/* SOURCE macro.cmn:30 */
/*<       save/macro_c/,/macro_i/ >*/
/*     Definitions */
/*     MACRO_BODY_PNT(I) - points to the first line of the */
/*                             macro body.  The value of I is */
/*                             stored in the global symbol list. */
/*                             Thus the macro name is found in the */
/*                             global symbol list, it points into */
/*                             the macro_body_pointer, and that */
/*                             points to the row contining the first */
/*                             line of the macro body. */
/*     MACRO_BODY_KNT(I)  - number of lines in the macro body */
/*     MACRO_ARG_PNT(I) -  points to the first argument in the */
/*                         MACRO-ARG(*). */
/*     MACRO_ARG_KNT(I) -  gives the number of arguments for this macro */
/*     MACRO_ARG(J) -   macro argument identifiers. */
/*     MACRO_ARG_LEN(J)  - length of the macro dummy argment. */
/*     MACRO_BODY(K) - contains the macro body.  Pointed to by */
/*                     MACRO_BODY_POINTER */
/*     MACRO_LINE_LEN(K) - length of the line in the macro body. */
/*     MACRO_STACK_TOP - pointer to the currently filled top of stack. */
/*                       Zero means that stack is empty.  Increment */
/*                       adds to the stack, decrement deletes from */
/*                       stack. */
/*     LAST_MACRO  - Pointer to the last used location in the macro */
/*                   table.  Starts at 0. */
/*     LAST_BODY  - Pointer to the last used location in the */
/*                  macro body table.  Starts at 0. */
/*     LAST_ARG  - pointer to the last used location in the */
/*                 macro argument table.  Starts at 0. */
/* *********************************************************************** */
/* SOURCE macro.for:726 */
/*<       line=macro_stack(macro_stack_top) >*/
    s_copy(line, feq_gen_macro_c_d_1.feq_gen_macro_stack_d_ + (feq_gen_macro_i_d_1.feq_gen_macro_stack_top_d_ - 1)
	     * 196, (ftnlen)196, (ftnlen)196);
/* SOURCE macro.for:727 */
/*<       macro_stack_top=macro_stack_top-1 >*/
    --feq_gen_macro_i_d_1.feq_gen_macro_stack_top_d_;
/* SOURCE macro.for:728 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:729 */
/*<       end >*/
} /* pop_line__ */

/*     *********** */
/*     *         * */
/*     * EXPAND_MACRO */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:737 */
/*<       subroutineexpand_macro(stdout,address,nval,cval,clen,eflag) >*/
/* Subroutine */ int feq_gen_expand_macro_d_(integer *stdout, integer *feq_gen_address_d_, 
	integer *nval, char *feq_storage_cval, integer *feq_storage_clen, integer *eflag, ftnlen 
	cval_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:318* Macro: \002,a,\002 expects \
\002,i3,\002 arguments but \002,\002found \002,i3)";
    static char fmt_52[] = "(/,\002 Macro instruction expansion fails.  Chk \
for errors.\002)";
    static char fmt_54[] = "(/,\002 Expanding macro: \002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_iend_arg_d_, feq_gen_line_len_d_, feq_gen_iend_body_d_;
    extern /* Subroutine */ int feq_gen_push_line_d_(integer *, char *, ftnlen);
    integer feq_gen_actual_len_d_, feq_gen_istart_arg_d_;
    extern /* Subroutine */ int feq_gen_identifier_replace_d_(integer *, char *, 
	    integer *, char *, integer *, integer *, integer *, char *, 
	    integer *, integer *, ftnlen, ftnlen, ftnlen);
    integer feq_gen_istart_body_d_, iarg;
    char line[196];
    integer iline;
    char actual[16];
    integer istart;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_52, 0 };


/*     Expand a macro instruction.  ADDRESS is the index into the */
/*     macro table,  CVAL(2:NVAL) gives the actual arguments, and */
/*     CLEN(2:NVAL) gives the length of the arguments. */
/* SOURCE macro.for:745 */
/*<       implicitnone >*/
/* SOURCE macro.for:747 */
/*<       integerstdout,address,nval,clen(nval),eflag >*/
/* SOURCE macro.for:749 */
/*<       character*(*)cval(nval) >*/
/* INCLUDE macro.for:751 */
/*     Variables for macro instruction processing in the */
/*     Network-Matrix Control Input. */
/* SOURCE macro.cmn:4 */
/*<       integermax_macro,max_body,max_arg,max_stack >*/
/* SOURCE macro.cmn:7 */
/*<       parameter(max_macro=200,max_body=600,max_arg=600,max_stack=100) >*/
/* SOURCE macro.cmn:10 */
/*<        >*/
/* SOURCE macro.cmn:14 */
/*<        >*/
/* SOURCE macro.cmn:24 */
/*<       common/macro_c/macro_body,macro_stack,macro_arg >*/
/* SOURCE macro.cmn:25 */
/*<        >*/
/* SOURCE macro.cmn:30 */
/*<       save/macro_c/,/macro_i/ >*/
/*     Definitions */
/*     MACRO_BODY_PNT(I) - points to the first line of the */
/*                             macro body.  The value of I is */
/*                             stored in the global symbol list. */
/*                             Thus the macro name is found in the */
/*                             global symbol list, it points into */
/*                             the macro_body_pointer, and that */
/*                             points to the row contining the first */
/*                             line of the macro body. */
/*     MACRO_BODY_KNT(I)  - number of lines in the macro body */
/*     MACRO_ARG_PNT(I) -  points to the first argument in the */
/*                         MACRO-ARG(*). */
/*     MACRO_ARG_KNT(I) -  gives the number of arguments for this macro */
/*     MACRO_ARG(J) -   macro argument identifiers. */
/*     MACRO_ARG_LEN(J)  - length of the macro dummy argment. */
/*     MACRO_BODY(K) - contains the macro body.  Pointed to by */
/*                     MACRO_BODY_POINTER */
/*     MACRO_LINE_LEN(K) - length of the line in the macro body. */
/*     MACRO_STACK_TOP - pointer to the currently filled top of stack. */
/*                       Zero means that stack is empty.  Increment */
/*                       adds to the stack, decrement deletes from */
/*                       stack. */
/*     LAST_MACRO  - Pointer to the last used location in the macro */
/*                   table.  Starts at 0. */
/*     LAST_BODY  - Pointer to the last used location in the */
/*                  macro body table.  Starts at 0. */
/*     LAST_ARG  - pointer to the last used location in the */
/*                 macro argument table.  Starts at 0. */
/*     Local */
/* SOURCE macro.for:755 */
/*<       characterline*196,actual*16 >*/
/* SOURCE macro.for:757 */
/*<        >*/
/* SOURCE macro.for:760 */
/*<       externalpush_line,identifier_replace >*/
/*     *************************FORMATS********************************** */
/* SOURCE macro.for:762 */
/*<    50  >*/
/* SOURCE macro.for:764 */
/*<    52 format(/,' Macro instruction expansion fails.  Chk for errors.') >*/
/* SOURCE macro.for:765 */
/*<    54 format(/,' Expanding macro: ',a) >*/
/* *********************************************************************** */
/* SOURCE macro.for:767 */
/*<       write(stdout,54)cval(1)(1:clen(1)) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, cval_len);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    feq_gen_io_d__61.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__61);
    do_fio(&feq_gen_c_d_1, cval + cval_len, clen[1]);
    e_wsfe();
/*     Check that the number of arguments is correct. */
/* SOURCE macro.for:770 */
/*<       if(macro_arg_knt(address).ne.nval-1)then >*/
    if (feq_gen_macro_i_d_1.feq_gen_macro_arg_knt_d_[*feq_gen_address_d_ - 1] != *nval - 1) {
/* SOURCE macro.for:771 */
/*<       write(stdout,50)cval(1)(1:clen(1)),macro_arg_knt(address),nval-1 >*/
	feq_gen_io_d__62.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, cval + cval_len, clen[1]);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_macro_i_d_1.feq_gen_macro_arg_knt_d_[*feq_gen_address_d_ - 1], (
		ftnlen)sizeof(integer));
	feq_gen_i_d_1 = *nval - 1;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE macro.for:773 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:774 */
/*<       endif >*/
    }
/*     Transfer the the macro body lines to the macro stack such that */
/*     the last line in the body goes onto the stack first.  Thus the */
/*     first line of the macro body will be at the top of the stack. */
/* SOURCE macro.for:780 */
/*<       iend_body=macro_body_pnt(address) >*/
    feq_gen_iend_body_d_ = feq_gen_macro_i_d_1.feq_gen_macro_body_pnt_d_[*feq_gen_address_d_ - 1];
/* SOURCE macro.for:781 */
/*<       istart_body=iend_body+macro_body_knt(address)-1 >*/
    feq_gen_istart_body_d_ = feq_gen_iend_body_d_ + feq_gen_macro_i_d_1.feq_gen_macro_body_knt_d_[*feq_gen_address_d_ - 1] 
	    - 1;
/* SOURCE macro.for:783 */
/*<       istart_arg=macro_arg_pnt(address) >*/
    feq_gen_istart_arg_d_ = feq_gen_macro_i_d_1.feq_gen_macro_arg_pnt_d_[*feq_gen_address_d_ - 1];
/* SOURCE macro.for:784 */
/*<       iend_arg=istart_arg+macro_arg_knt(address)-1 >*/
    feq_gen_iend_arg_d_ = feq_gen_istart_arg_d_ + feq_gen_macro_i_d_1.feq_gen_macro_arg_knt_d_[*feq_gen_address_d_ - 1] - 
	    1;
/*     Put each line in a temporary string and do the argument replacement */
/*     operation. */
/* SOURCE macro.for:789 */
/*<       eflag=0 >*/
    *eflag = 0;
/*     Start scan at first character of each line. */
/* SOURCE macro.for:791 */
/*<       istart=1 >*/
    istart = 1;
/* SOURCE macro.for:792 */
/*<       do200iline=istart_body,iend_body,-1 >*/
    feq_gen_i_d_1 = feq_gen_iend_body_d_;
    for (iline = feq_gen_istart_body_d_; iline >= feq_gen_i_d_1; --iline) {
/* SOURCE macro.for:793 */
/*<       line_len=macro_line_len(iline) >*/
	feq_gen_line_len_d_ = feq_gen_macro_i_d_1.feq_gen_macro_line_len_d_[iline - 1];
/* SOURCE macro.for:794 */
/*<       line=macro_body(iline) >*/
	s_copy(line, feq_gen_macro_c_d_1.feq_gen_macro_body_d_ + (iline - 1) * 196, (ftnlen)196,
		 (ftnlen)196);
/* SOURCE macro.for:795 */
/*<       do100iarg=istart_arg,iend_arg >*/
	feq_gen_i_d_2 = feq_gen_iend_arg_d_;
	for (iarg = feq_gen_istart_arg_d_; iarg <= feq_gen_i_d_2; ++iarg) {
/* SOURCE macro.for:796 */
/*<       actual=cval(iarg-istart_arg+2) >*/
	    s_copy(actual, cval + (iarg - feq_gen_istart_arg_d_ + 2) * cval_len, (
		    ftnlen)16, cval_len);
/* SOURCE macro.for:797 */
/*<       actual_len=clen(iarg-istart_arg+2) >*/
	    feq_gen_actual_len_d_ = clen[iarg - feq_gen_istart_arg_d_ + 2];
/* SOURCE macro.for:798 */
/*<        >*/
	    feq_gen_identifier_replace_d_(stdout, feq_gen_macro_c_d_1.feq_gen_macro_arg_d_ + (iarg - 1 <<
		     4), &feq_gen_macro_i_d_1.feq_gen_macro_arg_len_d_[iarg - 1], actual, &
		    feq_gen_actual_len_d_, &istart, &feq_gen_c_d_196, line, &feq_gen_line_len_d_, eflag, 
		    (ftnlen)16, (ftnlen)16, (ftnlen)196);
/* SOURCE macro.for:802 */
/*<   100 continue >*/
/* L100: */
	}
/*       Put the line on the top of stack. */
/* SOURCE macro.for:805 */
/*<       callpush_line(stdout,line) >*/
	feq_gen_push_line_d_(stdout, line, (ftnlen)196);
/* SOURCE macro.for:807 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE macro.for:808 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE macro.for:809 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__74.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__74);
	e_wsfe();
/* SOURCE macro.for:810 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE macro.for:811 */
/*<       endif >*/
    }
/* SOURCE macro.for:812 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:813 */
/*<       end >*/
} /* expand_macro__ */

/*     *********** */
/*     *         * */
/*     * INSERT_ARGUMENT_KNT */
/*     *         * */
/*     *********** */
/* SOURCE macro.for:821 */
/*<        >*/
/* Subroutine */ int feq_gen_insert_argument_knt_d_(integer *feq_gen_max_nval_d_, integer *nval,
	 char *feq_storage_cval, integer *feq_storage_clen, integer *feq_gen_feq_storage_item_type_d_, char *feq_storage_term, integer 
	*feq_storage_terml, integer *feq_storage_termcls, ftnlen cval_len, ftnlen term_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    integer feq_gen_i_d_;

/*     Special case for variable number of arguments where the user */
/*     need not give the count of the arguments. */
/* SOURCE macro.for:828 */
/*<       implicitnone >*/
/* SOURCE macro.for:830 */
/*<        >*/
/* SOURCE macro.for:833 */
/*<       charactercval(max_nval)*256,term(max_nval)*1 >*/
/*     Local */
/* SOURCE macro.for:837 */
/*<       integerintval >*/
/* SOURCE macro.for:838 */
/*<       parameter(intval=1) >*/
/* SOURCE macro.for:840 */
/*<       integeri >*/
/* *********************************************************************** */
/*     The number of arugments should appear at index 2.  Thus */
/*     move all items above this location so that space is created */
/*     in CVAL, CLEN, and ITEM_TYPE for a new entry at index 2. */
/*     We need not check for overflow in the vectors because NVAL */
/*     was already reduced by 1 in the calling program.  Thus an */
/*     increase of 1 will not overflow the vectors--we hope! */
/* SOURCE macro.for:850 */
/*<       do100i=nval,2,-1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> termcls(feq_storage_termcls, 1);

    feq::IndexedPointer<integer> terml(feq_storage_terml, 1);

    feq::IndexedPointer<char> term(feq_storage_term, 1);

    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, 256);

    /* Function Body */
    for (feq_gen_i_d_ = *nval; feq_gen_i_d_ >= 2; --feq_gen_i_d_) {
/* SOURCE macro.for:851 */
/*<       cval(i+1)=cval(i) >*/
	s_copy(cval + (feq_gen_i_d_ + 1 << 8), cval + (feq_gen_i_d_ << 8), (ftnlen)256, (ftnlen)
		256);
/* SOURCE macro.for:852 */
/*<       clen(i+1)=clen(i) >*/
	clen[feq_gen_i_d_ + 1] = clen[feq_gen_i_d_];
/* SOURCE macro.for:853 */
/*<       item_type(i+1)=item_type(i) >*/
	feq_gen_item_type_d_[feq_gen_i_d_ + 1] = feq_gen_item_type_d_[feq_gen_i_d_];
/* SOURCE macro.for:854 */
/*<       termcls(i+1)=termcls(i) >*/
	termcls[feq_gen_i_d_ + 1] = termcls[feq_gen_i_d_];
/* SOURCE macro.for:855 */
/*<       terml(i+1)=terml(i) >*/
	terml[feq_gen_i_d_ + 1] = terml[feq_gen_i_d_];
/* SOURCE macro.for:856 */
/*<       term(i+1)=term(i) >*/
	*(unsigned char *)&term[feq_gen_i_d_ + 1] = *(unsigned char *)&term[feq_gen_i_d_];
/* SOURCE macro.for:857 */
/*<   100 continue >*/
/* L100: */
    }
/*     There are NVAL - 1 arguments.  Convert the number of arguments */
/*     to a character string to make it appear as if it were input. */
/*     Leading spaces are ok so long as the string length includes */
/*     them. */
/* SOURCE macro.for:863 */
/*<       cval(2)=' ' >*/
    s_copy(cval + 512, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1);
/* SOURCE macro.for:864 */
/*<       write(cval(2)(1:5),'(I5)')nval-1 >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = cval + 512;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    s_wsfi(&feq_gen_ici_d_1);
    feq_gen_i_d_1 = *nval - 1;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE macro.for:865 */
/*<       item_type(2)=intval >*/
    feq_gen_item_type_d_[2] = 1;
/* SOURCE macro.for:866 */
/*<       clen(2)=5 >*/
    clen[2] = 5;
/* SOURCE macro.for:867 */
/*<       term(2)=' ' >*/
    *(unsigned char *)&term[2] = ' ';
/* SOURCE macro.for:868 */
/*<       terml(2)=1 >*/
    terml[2] = 1;
/* SOURCE macro.for:869 */
/*<       termcls(2)=6 >*/
    termcls[2] = 6;
/* SOURCE macro.for:870 */
/*<       nval=nval+1 >*/
    ++(*nval);
/* SOURCE macro.for:871 */
/*<       return >*/
    return 0;
/* SOURCE macro.for:872 */
/*<       end >*/
} /* insert_argument_knt__ */

#ifdef __cplusplus
	}
#endif
