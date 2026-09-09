/* select.f -- translated by f2c (version 20240504).
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

/* COMMON selector_c__ is declared in common.hpp. */

#define feq_gen_selector_c_d_1 feq_gen_selector_c_d_

/* COMMON selector_i__ is declared in common.hpp. */

#define feq_gen_selector_i_d_1 feq_gen_selector_i_d_

/* COMMON select_cmn__ is declared in common.hpp. */

#define feq_gen_select_cmn_d_1 feq_gen_select_cmn_d_

/* COMMON select_cmnc__ is declared in common.hpp. */

#define feq_gen_select_cmnc_d_1 feq_gen_select_cmnc_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_100 = 100;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_9 = 9;




/* SOURCE select.for:4 */
/*<       subroutineforce_slashes(name) >*/
/* Subroutine */ int feq_gen_force_slashes_d_(char *feq_gen_name_d_, ftnlen name_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, n;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Force all backslashes to be slashes: Linux rules! */
/* SOURCE select.for:8 */
/*<       implicitnone >*/
/* SOURCE select.for:9 */
/*<       character*(*)name >*/
/*     Local */
/* SOURCE select.for:12 */
/*<       integeri,n >*/
/* *********************************************************************** */
/* SOURCE select.for:4 */
/*<       integer feq_len_trim >*/
/* SOURCE select.for:4 */
/*<       external feq_len_trim >*/
/* SOURCE select.for:14 */
/*<       n=feq_len_trim(name) >*/
    n = feq_gen_feq_len_trim_d_(feq_gen_name_d_, name_len);
/* SOURCE select.for:15 */
/*<       do100i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE select.for:16 */
/*<       if(name(i:i).eq.'\')then >*/
	if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] == '\\') {
/* SOURCE select.for:17 */
/*<       name(i:i)='/' >*/
	    *(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] = '/';
/* SOURCE select.for:18 */
/*<       endif >*/
	}
/* SOURCE select.for:19 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE select.for:20 */
/*<       return >*/
    return 0;
/* SOURCE select.for:21 */
/*<       end >*/
} /* force_slashes__ */




/* SOURCE select.for:26 */
/*<       subroutineto_lower(string) >*/
/* Subroutine */ int feq_gen_to_lower_d_(char *string, ftnlen string_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, ich, iend;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);


/*     Convert all uppercase alpha characters to lower case */
/*     Modified from  a USGS routine. */
/* SOURCE select.for:31 */
/*<       character*(*)string >*/
/*     + + + ARGUMENT DEFINITIONS + + + */
/*     STRING - character string to be made lower case */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE select.for:37 */
/*<       integeri,ich,iend >*/
/*     + + + INTRINSICS + + + */
/* SOURCE select.for:40 */
/*<       intrinsicichar,char >*/
/* *********************************************************************** */
/* SOURCE select.for:26 */
/*<       integer feq_len_trim >*/
/* SOURCE select.for:26 */
/*<       external feq_len_trim >*/
/* SOURCE select.for:42 */
/*<       iend=feq_len_trim(string) >*/
    iend = feq_gen_feq_len_trim_d_(string, string_len);
/* SOURCE select.for:43 */
/*<       do10i=1,iend >*/
    feq_gen_i_d_1 = iend;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE select.for:44 */
/*<       ich=ichar(string(i:i)) >*/
	ich = *(unsigned char *)&string[feq_gen_i_d_ - 1];
/* SOURCE select.for:45 */
/*<       if(ich.ge.65.and.ich.le.90)then >*/
	if (ich >= 65 && ich <= 90) {
/*         Character is upper case. */
/* SOURCE select.for:47 */
/*<       string(i:i)=char(ich+32) >*/
	    *(unsigned char *)&string[feq_gen_i_d_ - 1] = (char) (ich + 32);
/* SOURCE select.for:48 */
/*<       endif >*/
	}
/* SOURCE select.for:49 */
/*<    10 continue >*/
/* L10: */
    }
/* SOURCE select.for:51 */
/*<       return >*/
    return 0;
/* SOURCE select.for:52 */
/*<       end >*/
} /* to_lower__ */

/*     Contains routines used in processing selectors used to */
/*     extract those parts of a master input file to use in */
/*     a given run. */
/* SOURCE select.for:58 */
/*<       subroutineselector_symbol_init() >*/
/* Subroutine */ int feq_gen_selector_symbol_init_d_()
{
/*     Initialize the selector-symbol table facility. */
/* SOURCE select.for:62 */
/*<       implicitnone >*/
/* INCLUDE select.for:64 */
/*     Symbol table for selector processing in FEQ */
/* SOURCE selector.cmn:3 */
/*<       integermax_symbol >*/
/* SOURCE selector.cmn:4 */
/*<       parameter(max_symbol=100) >*/
/* SOURCE selector.cmn:6 */
/*<       character*16symbol(max_symbol) >*/
/* SOURCE selector.cmn:8 */
/*<        >*/
/* SOURCE selector.cmn:11 */
/*<       common/selector_c/symbol >*/
/* SOURCE selector.cmn:13 */
/*<       common/selector_i/symbol_class,symbol_value,last_symbol >*/
/* SOURCE selector.cmn:15 */
/*<       save/selector_c/,/selector_i/ >*/
/* *********************************************************************** */
/* SOURCE select.for:67 */
/*<       last_symbol=0 >*/
    feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ = 0;
/* SOURCE select.for:68 */
/*<       return >*/
    return 0;
/* SOURCE select.for:69 */
/*<       end >*/
} /* selector_symbol_init__ */

/*     *********** */
/*     *         * */
/*     * LSUA_SELECT */
/*     *         * */
/*     *********** */
/* SOURCE select.for:77 */
/*<       subroutinelsua_selector(stdout,key,class,value,index,flag) >*/
/* Subroutine */ int feq_gen_lsua_selector_d_(integer *stdout, char *key, integer *
	feq_gen_class_d_, integer *value, integer *index, integer *feq_gen_flag_d_, ftnlen 
	key_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:414* Too many entries in selector-s\
ymbol table.\002,\002 Number=\002,i5,\002  Limit=\002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do a linear search for KEY in the entries in the selector */
/*     symbol table and add to the table if KEY is not found. */
/*     Otherwise, update values at  KEY.  Return Index  and */
/*     Flag */
/* SOURCE select.for:88 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE select.for:90 */
/*<       integerflag,index,stdout,class,value >*/
/* SOURCE select.for:91 */
/*<       characterkey*16 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     KEY    - search value */
/*     CLASS  - Class code for the symbol. */
/*     VALUE  - numeric value for the symbol. */
/*     INDEX  - index into the table at the match point */
/*     FLAG  -  0: KEY not in the table; 1: Key in the table; */
/*              2: error encountered. */
/* INCLUDE select.for:102 */
/*     Symbol table for selector processing in FEQ */
/* SOURCE selector.cmn:3 */
/*<       integermax_symbol >*/
/* SOURCE selector.cmn:4 */
/*<       parameter(max_symbol=100) >*/
/* SOURCE selector.cmn:6 */
/*<       character*16symbol(max_symbol) >*/
/* SOURCE selector.cmn:8 */
/*<        >*/
/* SOURCE selector.cmn:11 */
/*<       common/selector_c/symbol >*/
/* SOURCE selector.cmn:13 */
/*<       common/selector_i/symbol_class,symbol_value,last_symbol >*/
/* SOURCE selector.cmn:15 */
/*<       save/selector_c/,/selector_i/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE select.for:105 */
/*<       integeri >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE select.for:108 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE select.for:111 */
/*<       do100i=1,last_symbol >*/
/* L50: */
    feq_gen_i_d_1 = feq_gen_selector_i_d_1.feq_gen_last_symbol_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE select.for:112 */
/*<       if(key.eq.symbol(i))then >*/
	if (s_cmp(key, feq_gen_selector_c_d_1.symbol + (feq_gen_i_d_ - 1 << 4), (ftnlen)16, (
		ftnlen)16) == 0) {
/*         FOUND MATCH */
/* SOURCE select.for:114 */
/*<       index=i >*/
	    *index = feq_gen_i_d_;
/* SOURCE select.for:115 */
/*<       symbol_class(i)=class >*/
	    feq_gen_selector_i_d_1.feq_gen_symbol_class_d_[feq_gen_i_d_ - 1] = *feq_gen_class_d_;
/* SOURCE select.for:116 */
/*<       symbol_value(i)=value >*/
	    feq_gen_selector_i_d_1.feq_gen_symbol_value_d_[feq_gen_i_d_ - 1] = *value;
/* SOURCE select.for:117 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE select.for:118 */
/*<       return >*/
	    return 0;
/* SOURCE select.for:119 */
/*<       endif >*/
	}
/* SOURCE select.for:120 */
/*<   100 continue >*/
/* L100: */
    }
/*     MATCH NOT FOUND */
/* SOURCE select.for:122 */
/*<       last_symbol=last_symbol+1 >*/
    ++feq_gen_selector_i_d_1.feq_gen_last_symbol_d_;
/* SOURCE select.for:124 */
/*<       flag=0 >*/
    *feq_gen_flag_d_ = 0;
/* SOURCE select.for:125 */
/*<       if(last_symbol.gt.max_symbol)then >*/
    if (feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ > 100) {
/* SOURCE select.for:126 */
/*<       write(stdout,50)last_symbol,max_symbol >*/
	feq_gen_io_d__7.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__7);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_selector_i_d_1.feq_gen_last_symbol_d_, (ftnlen)sizeof(
		integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_100, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE select.for:127 */
/*<       flag=2 >*/
	*feq_gen_flag_d_ = 2;
/* SOURCE select.for:128 */
/*<       last_symbol=max_symbol >*/
	feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ = 100;
/* SOURCE select.for:129 */
/*<       endif >*/
    }
/* SOURCE select.for:130 */
/*<       symbol(last_symbol)=key >*/
    s_copy(feq_gen_selector_c_d_1.symbol + (feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ - 1 << 4), key,
	     (ftnlen)16, (ftnlen)16);
/* SOURCE select.for:131 */
/*<       symbol_class(last_symbol)=class >*/
    feq_gen_selector_i_d_1.feq_gen_symbol_class_d_[feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ - 1] = *feq_gen_class_d_;
/* SOURCE select.for:132 */
/*<       symbol_value(last_symbol)=value >*/
    feq_gen_selector_i_d_1.feq_gen_symbol_value_d_[feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ - 1] = *value;
/* SOURCE select.for:133 */
/*<       index=last_symbol >*/
    *index = feq_gen_selector_i_d_1.feq_gen_last_symbol_d_;
/* SOURCE select.for:134 */
/*<       return >*/
    return 0;
/* SOURCE select.for:135 */
/*<       end >*/
} /* lsua_selector__ */

/*     *********** */
/*     *         * */
/*     * LSA_SELECT */
/*     *         * */
/*     *********** */
/* SOURCE select.for:145 */
/*<       subroutinelsa_selector(stdout,key,class,value,index,flag) >*/
/* Subroutine */ int feq_gen_lsa_selector_d_(integer *stdout, char *key, integer *
	feq_gen_class_d_, integer *value, integer *index, integer *feq_gen_flag_d_, ftnlen 
	key_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:414* Too many entries in selector-s\
ymbol table.\002,\002 Number=\002,i5,\002 Limit=\002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__9 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do a linear search for KEY in the entries in the selector */
/*     symbol table and add to the table if KEY is not found. */
/*     Otherwise, return the index to KEY and the value of */
/*     CLASS and VALUE found for the symbol in KEY. */
/* SOURCE select.for:156 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE select.for:158 */
/*<       integerflag,index,stdout,class,value >*/
/* SOURCE select.for:159 */
/*<       characterkey*16 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     KEY    - search value */
/*     CLASS  - Class code for the symbol. */
/*     VALUE  - numeric value for the symbol. */
/*     INDEX  - index into the table at the match point */
/*     FLAG  -  0: KEY not in the table; 1: Key in the table; */
/*              2: error encountered. */
/* INCLUDE select.for:170 */
/*     Symbol table for selector processing in FEQ */
/* SOURCE selector.cmn:3 */
/*<       integermax_symbol >*/
/* SOURCE selector.cmn:4 */
/*<       parameter(max_symbol=100) >*/
/* SOURCE selector.cmn:6 */
/*<       character*16symbol(max_symbol) >*/
/* SOURCE selector.cmn:8 */
/*<        >*/
/* SOURCE selector.cmn:11 */
/*<       common/selector_c/symbol >*/
/* SOURCE selector.cmn:13 */
/*<       common/selector_i/symbol_class,symbol_value,last_symbol >*/
/* SOURCE selector.cmn:15 */
/*<       save/selector_c/,/selector_i/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE select.for:173 */
/*<       integeri >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE select.for:176 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE select.for:179 */
/*<       do100i=1,last_symbol >*/
/* L50: */
    feq_gen_i_d_1 = feq_gen_selector_i_d_1.feq_gen_last_symbol_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE select.for:180 */
/*<       if(key.eq.symbol(i))then >*/
	if (s_cmp(key, feq_gen_selector_c_d_1.symbol + (feq_gen_i_d_ - 1 << 4), (ftnlen)16, (
		ftnlen)16) == 0) {
/*         FOUND MATCH */
/* SOURCE select.for:182 */
/*<       index=i >*/
	    *index = feq_gen_i_d_;
/* SOURCE select.for:183 */
/*<       class=symbol_class(i) >*/
	    *feq_gen_class_d_ = feq_gen_selector_i_d_1.feq_gen_symbol_class_d_[feq_gen_i_d_ - 1];
/* SOURCE select.for:184 */
/*<       value=symbol_value(i) >*/
	    *value = feq_gen_selector_i_d_1.feq_gen_symbol_value_d_[feq_gen_i_d_ - 1];
/* SOURCE select.for:185 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE select.for:186 */
/*<       return >*/
	    return 0;
/* SOURCE select.for:187 */
/*<       endif >*/
	}
/* SOURCE select.for:188 */
/*<   100 continue >*/
/* L100: */
    }
/*     MATCH NOT FOUND */
/* SOURCE select.for:190 */
/*<       last_symbol=last_symbol+1 >*/
    ++feq_gen_selector_i_d_1.feq_gen_last_symbol_d_;
/* SOURCE select.for:192 */
/*<       flag=0 >*/
    *feq_gen_flag_d_ = 0;
/* SOURCE select.for:193 */
/*<       if(last_symbol.gt.max_symbol)then >*/
    if (feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ > 100) {
/* SOURCE select.for:194 */
/*<       write(stdout,50)last_symbol,max_symbol >*/
	feq_gen_io_d__9.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__9);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_selector_i_d_1.feq_gen_last_symbol_d_, (ftnlen)sizeof(
		integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_100, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE select.for:195 */
/*<       flag=2 >*/
	*feq_gen_flag_d_ = 2;
/* SOURCE select.for:196 */
/*<       last_symbol=max_symbol >*/
	feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ = 100;
/* SOURCE select.for:197 */
/*<       endif >*/
    }
/* SOURCE select.for:198 */
/*<       symbol(last_symbol)=key >*/
    s_copy(feq_gen_selector_c_d_1.symbol + (feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ - 1 << 4), key,
	     (ftnlen)16, (ftnlen)16);
/* SOURCE select.for:199 */
/*<       symbol_class(last_symbol)=class >*/
    feq_gen_selector_i_d_1.feq_gen_symbol_class_d_[feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ - 1] = *feq_gen_class_d_;
/* SOURCE select.for:200 */
/*<       symbol_value(last_symbol)=value >*/
    feq_gen_selector_i_d_1.feq_gen_symbol_value_d_[feq_gen_selector_i_d_1.feq_gen_last_symbol_d_ - 1] = *value;
/* SOURCE select.for:201 */
/*<       index=last_symbol >*/
    *index = feq_gen_selector_i_d_1.feq_gen_last_symbol_d_;
/* SOURCE select.for:202 */
/*<       return >*/
    return 0;
/* SOURCE select.for:203 */
/*<       end >*/
} /* lsa_selector__ */

/*     *********** */
/*     *         * */
/*     * LS_SELECT */
/*     *         * */
/*     *********** */
/* SOURCE select.for:210 */
/*<       subroutinels_selector(key,class,value,index) >*/
/* Subroutine */ int feq_gen_ls_selector_d_(char *key, integer *feq_gen_class_d_, integer *
	value, integer *index, ftnlen key_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

/*     + + + PURPOSE + + + */
/*     Do a linear search for KEY in the entries in the selector */
/*     symbol table and return its class, value, and index */
/*     if it is found.  Otherwise return a zero value for */
/*     index. */
/* SOURCE select.for:220 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE select.for:222 */
/*<       integerindex,class,value >*/
/* SOURCE select.for:223 */
/*<       characterkey*16 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     KEY    - search value */
/*     CLASS  - Class code for the symbol. */
/*     VALUE  - numeric value for the symbol. */
/*     INDEX  - index into the table at the match point */
/* INCLUDE select.for:231 */
/*     Symbol table for selector processing in FEQ */
/* SOURCE selector.cmn:3 */
/*<       integermax_symbol >*/
/* SOURCE selector.cmn:4 */
/*<       parameter(max_symbol=100) >*/
/* SOURCE selector.cmn:6 */
/*<       character*16symbol(max_symbol) >*/
/* SOURCE selector.cmn:8 */
/*<        >*/
/* SOURCE selector.cmn:11 */
/*<       common/selector_c/symbol >*/
/* SOURCE selector.cmn:13 */
/*<       common/selector_i/symbol_class,symbol_value,last_symbol >*/
/* SOURCE selector.cmn:15 */
/*<       save/selector_c/,/selector_i/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE select.for:234 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE select.for:237 */
/*<       do100i=1,last_symbol >*/
    feq_gen_i_d_1 = feq_gen_selector_i_d_1.feq_gen_last_symbol_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE select.for:238 */
/*<       if(key.eq.symbol(i))then >*/
	if (s_cmp(key, feq_gen_selector_c_d_1.symbol + (feq_gen_i_d_ - 1 << 4), (ftnlen)16, (
		ftnlen)16) == 0) {
/*         Found match */
/* SOURCE select.for:240 */
/*<       index=i >*/
	    *index = feq_gen_i_d_;
/* SOURCE select.for:241 */
/*<       class=symbol_class(i) >*/
	    *feq_gen_class_d_ = feq_gen_selector_i_d_1.feq_gen_symbol_class_d_[feq_gen_i_d_ - 1];
/* SOURCE select.for:242 */
/*<       value=symbol_value(i) >*/
	    *value = feq_gen_selector_i_d_1.feq_gen_symbol_value_d_[feq_gen_i_d_ - 1];
/* SOURCE select.for:243 */
/*<       return >*/
	    return 0;
/* SOURCE select.for:244 */
/*<       endif >*/
	}
/* SOURCE select.for:245 */
/*<   100 continue >*/
/* L100: */
    }
/*     Match not found. */
/* SOURCE select.for:247 */
/*<       index=0 >*/
    *index = 0;
/* SOURCE select.for:248 */
/*<       return >*/
    return 0;
/* SOURCE select.for:249 */
/*<       end >*/
} /* ls_selector__ */




/* SOURCE select.for:254 */
/*<       subroutinemake_sb_home_name(stdout,sb_home) >*/
/* Subroutine */ int feq_gen_make_sb_home_name_d_(integer *stdout, char *feq_gen_sb_home_d_, 
	ftnlen sb_home_len)
{
    /* Initialized data */

    static integer feq_gen_true_d_ = 1;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *WRN:60* No selector variable was true. \
 It is then easy to\002,/,5x,\002create a scenario directory that matches th\
e current\002,/,5x,\002working directory.  If that is done FEQ cannot detec\
t\002,/,5x,\002equality of the file names for the primary and secondary\002,\
/,5x,\002master-input files.  Make sure that the scenario home\002,/,5x,\002\
directory that you are creating is not the same as any\002,/,5x,\002director\
y from which you will be invoking FEQ using the\002,/,5x,\002primary master-\
input file as its first command-line\002,/,5x,\002argument.  Otherwise it is\
 possible to destroy your primary\002/,5x,\002master-input file.  That is no\
t good but Fortran has no\002,/,5x,\002portable means for reporting the name\
 of the current\002,/,5x,\002working directory so that FEQ can check for tha\
t outcome.\002)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3[2];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, j, k;
    char work[128];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_50, 0 };


/*     Make a home name from the true values in the selector table. */
/* SOURCE select.for:259 */
/*<       implicitnone >*/
/* SOURCE select.for:260 */
/*<       integerstdout >*/
/* SOURCE select.for:261 */
/*<       character*(*)sb_home >*/
/* INCLUDE select.for:263 */
/*     Symbol table for selector processing in FEQ */
/* SOURCE selector.cmn:3 */
/*<       integermax_symbol >*/
/* SOURCE selector.cmn:4 */
/*<       parameter(max_symbol=100) >*/
/* SOURCE selector.cmn:6 */
/*<       character*16symbol(max_symbol) >*/
/* SOURCE selector.cmn:8 */
/*<        >*/
/* SOURCE selector.cmn:11 */
/*<       common/selector_c/symbol >*/
/* SOURCE selector.cmn:13 */
/*<       common/selector_i/symbol_class,symbol_value,last_symbol >*/
/* SOURCE selector.cmn:15 */
/*<       save/selector_c/,/selector_i/ >*/
/*     Local */
/* SOURCE select.for:266 */
/*<       integeri,j,k,true >*/
/* SOURCE select.for:268 */
/*<       characterwork*128 >*/
/*     **************************FORMATS********************************* */
/* SOURCE select.for:254 */
/*<       integer feq_len_trim >*/
/* SOURCE select.for:254 */
/*<       external feq_len_trim >*/
/* SOURCE select.for:270 */
/*<       datatrue/1/ >*/
/* SOURCE select.for:272 */
/*<    50  >*/
/* L50: */
/* ************************************************************************ */
/*     Method:  Scan through the selector table and extract the keys */
/*     that are true.  These are then appended in the order found */
/*     to the existing string in SB_HOME.  We use an underscore */
/*     character as the delimiter between adjacent keys.  It is the */
/*     user's responsibility to present the keys in the proper order */
/*     and of the proper number and length so that the result is */
/*     the desired one! */
/*     Initialize the character pointers. J points to the last */
/*     character inserted into work. */
/* SOURCE select.for:296 */
/*<       j=0 >*/
    j = 0;
/* SOURCE select.for:298 */
/*<       work='/' >*/
    s_copy(work, const_cast<char*>("/"), (ftnlen)128, (ftnlen)1);
/* SOURCE select.for:299 */
/*<       j=j+1 >*/
    ++j;
/* SOURCE select.for:300 */
/*<       do100i=1,last_symbol >*/
    feq_gen_i_d_1 = feq_gen_selector_i_d_1.feq_gen_last_symbol_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE select.for:301 */
/*<       if(symbol_value(i).eq.true)then >*/
	if (feq_gen_selector_i_d_1.feq_gen_symbol_value_d_[feq_gen_i_d_ - 1] == feq_gen_true_d_) {
/*         We have a hit! */
/* SOURCE select.for:303 */
/*<       k=feq_len_trim(symbol(i)) >*/
	    k = feq_gen_feq_len_trim_d_(feq_gen_selector_c_d_1.symbol + (feq_gen_i_d_ - 1 << 4), (ftnlen)
		    16);
/* SOURCE select.for:304 */
/*<       work(j+1:j+k)=symbol(i)(1:k) >*/
	    feq_gen_i_d_2 = j;
	    s_copy(work + feq_gen_i_d_2, feq_gen_selector_c_d_1.symbol + (feq_gen_i_d_ - 1 << 4), j + k 
		    - feq_gen_i_d_2, k);
/* SOURCE select.for:305 */
/*<       j=j+k >*/
	    j += k;
/* SOURCE select.for:306 */
/*<       work(j+1:j+1)='_' >*/
	    feq_gen_i_d_2 = j;
	    s_copy(work + feq_gen_i_d_2, const_cast<char*>("_"), j + 1 - feq_gen_i_d_2, (ftnlen)1);
/* SOURCE select.for:307 */
/*<       j=j+1 >*/
	    ++j;
/* SOURCE select.for:308 */
/*<       endif >*/
	}
/* SOURCE select.for:309 */
/*<   100 continue >*/
/* L100: */
    }
/*     We have added one too many underscores.  Trim off the trailing */
/*     underscore and add to the end of SB_HOME.  Note: SB_HOME should */
/*     not be blank nor empty.  Otherwise an error has occurred */
/*     earlier. */
/* SOURCE select.for:315 */
/*<       if(j.gt.0)then >*/
    if (j > 0) {
/* SOURCE select.for:316 */
/*<       j=j-1 >*/
	--j;
/* SOURCE select.for:317 */
/*<       k=feq_len_trim(sb_home) >*/
	k = feq_gen_feq_len_trim_d_(feq_gen_sb_home_d_, sb_home_len);
/* SOURCE select.for:318 */
/*<       sb_home=sb_home(1:k)//work(1:j) >*/
/* Writing concatenation */
	feq_gen_i_d_3[0] = k, feq_gen_a_d_1[0] = feq_gen_sb_home_d_;
	feq_gen_i_d_3[1] = j, feq_gen_a_d_1[1] = work;
	s_cat(feq_gen_sb_home_d_, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_2, sb_home_len);
/* SOURCE select.for:319 */
/*<       endif >*/
    }
/*     If J is 0 then no selector value was true.  It is then possible to */
/*     create a home name that matches the current working directory.  It is */
/*     then possible that the secondary master-file name is the same as the */
/*     primary master-file name and we will not be able to tell.  Fortran has */
/*     no portable means for getting us the current working directory! */
/* SOURCE select.for:327 */
/*<       if(j.eq.0)then >*/
    if (j == 0) {
/* SOURCE select.for:328 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__16.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__16);
	e_wsfe();
/* SOURCE select.for:329 */
/*<       endif >*/
    }
/* SOURCE select.for:330 */
/*<       return >*/
    return 0;
/* SOURCE select.for:331 */
/*<       end >*/
} /* make_sb_home_name__ */




/* SOURCE select.for:338 */
/*<       subroutineget_selectors(stdin,stdout,file_name,sb_home) >*/
/* Subroutine */ int feq_gen_get_selectors_d_(integer *stdin, integer *stdout, char *
	feq_gen_file_name_d_, char *feq_gen_sb_home_d_, ftnlen file_name_len, ftnlen 
	sb_home_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:415* No = found after a selector na\
me.\002)";
    static char fmt_52[] = "(/,\002 *ERR:416* Selector name=\002,a,\002 has \
more than 16\002,\002 characters.\002)";
    static char fmt_54[] = "(/,\002 *ERR:417* No selector name found.\002)";
    static char fmt_56[] = "(/,\002 *ERR:418* No selector value found.\002)";
    static char fmt_58[] = "(/,\002 *ERR:419* \002,a,\002 is an invalid sele\
ctor value.  \002,\002Must be TRUE, true, FALSE, or false.\002)";
    static char fmt_60[] = "(/,\002 Home directory for output files is: \002\
,a)";

    /* System generated locals */
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_force_lc_d_;
    extern /* Subroutine */ int feq_gen_to_lower_d_(char *, ftnlen), 
	    feq_gen_make_sb_home_name_d_(integer *, char *, ftnlen);
    integer it;
    char key[16];
    integer nxt;
    char line[196];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_lsa_selector_d_(integer *, char *, integer *, 
	    integer *, integer *, integer *, ftnlen);
    integer feq_gen_class_d_;
    extern /* Subroutine */ int mkdir_(integer *, char *, ftnlen);
    integer value;
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen), inline_(
	    integer *, integer *, char *, ftnlen);
    char result[128];
    extern /* Subroutine */ int nxttok_(char *, integer *, char *, ftnlen, 
	    ftnlen), feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__24 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_58, 0 };


/*     Get the selector values from the Set-selectors block. */
/* SOURCE select.for:343 */
/*<       implicitnone >*/
/* SOURCE select.for:345 */
/*<       integerstdin,stdout >*/
/* SOURCE select.for:347 */
/*<       characterfile_name*128,sb_home*(*) >*/
/* SOURCE select.for:349 */
/*<       externalmkdir >*/
/*     Local */
/* SOURCE select.for:352 */
/*<       integerit,nxt,value,class,force_lc >*/
/* SOURCE select.for:354 */
/*<       characterline*196,result*128,key*16 >*/
/*     ****************************Formats******************************* */
/* SOURCE select.for:338 */
/*<       integer feq_len_trim >*/
/* SOURCE select.for:338 */
/*<       external feq_len_trim >*/
/* SOURCE select.for:357 */
/*<    50 format(/,' *ERR:415* No = found after a selector name.') >*/
/* SOURCE select.for:358 */
/*<    52  >*/
/* SOURCE select.for:360 */
/*<    54 format(/,' *ERR:417* No selector name found.') >*/
/* SOURCE select.for:361 */
/*<    56 format(/,' *ERR:418* No selector value found.') >*/
/* SOURCE select.for:362 */
/*<    58  >*/
/* SOURCE select.for:364 */
/*<    60 format(/,' Home directory for output files is: ',a) >*/
/* *********************************************************************** */
/*     Set the default file name should the user not give one. Note: */
/*     the leading blank IS important.  Operating system will ignore */
/*     leading blanks in file names and we need the space to possibly */
/*     insert a slash later.  If this default name is changed be */
/*     sure to change the test for the default name about 30 lines */
/*     below! */
/* SOURCE select.for:372 */
/*<       file_name=' f_e_q_i_n_temp.default' >*/
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
    s_copy(feq_gen_file_name_d_, const_cast<char*>(" f_e_q_i_n_temp.default"), (ftnlen)128, (ftnlen)23);
/*     Set the default select-block home name to blank */
/* SOURCE select.for:374 */
/*<       sb_home=' ' >*/
    s_copy(feq_gen_sb_home_d_, const_cast<char*>(" "), sb_home_len, (ftnlen)1);
/*     Clear the lower-case flag */
/* SOURCE select.for:376 */
/*<       force_lc=0 >*/
    feq_gen_force_lc_d_ = 0;
/* SOURCE select.for:377 */
/*<   100 continue >*/
L100:
/* SOURCE select.for:378 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE select.for:381 */
/*<       it=feq_len_trim(line) >*/
    it = feq_gen_feq_len_trim_d_(line, (ftnlen)196);
/* SOURCE select.for:382 */
/*<       write(stdout,'(A)')line(1:it) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE select.for:384 */
/*<       if(line(1:5).eq.'END S')then >*/
    if (s_cmp(line, const_cast<char*>("END S"), (ftnlen)5, (ftnlen)5) == 0) {
/*         Check for making a home name. */
/* SOURCE select.for:386 */
/*<       if(sb_home.ne.' ')then >*/
	if (s_cmp(feq_gen_sb_home_d_, const_cast<char*>(" "), sb_home_len, (ftnlen)1) != 0) {
/*           Make a home name. */
/* SOURCE select.for:388 */
/*<       callmake_sb_home_name(stdout,sb_home) >*/
	    feq_gen_make_sb_home_name_d_(stdout, feq_gen_sb_home_d_, sb_home_len);
/* SOURCE select.for:390 */
/*<       if(force_lc.eq.1)then >*/
	    if (feq_gen_force_lc_d_ == 1) {
/* SOURCE select.for:391 */
/*<       callto_lower(sb_home) >*/
		feq_gen_to_lower_d_(feq_gen_sb_home_d_, sb_home_len);
/* SOURCE select.for:393 */
/*<       endif >*/
	    }
/* SOURCE select.for:394 */
/*<       it=feq_len_trim(sb_home) >*/
	    it = feq_gen_feq_len_trim_d_(feq_gen_sb_home_d_, sb_home_len);
/* SOURCE select.for:395 */
/*<       write(stdout,60)sb_home(1:it) >*/
	    feq_gen_io_d__20.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__20);
	    do_fio(&feq_gen_c_d_1, feq_gen_sb_home_d_, it);
	    e_wsfe();
/* SOURCE select.for:397 */
/*<       callos_file_style(sb_home) >*/
	    feq_gen_os_file_style_d_(feq_gen_sb_home_d_, sb_home_len);
/* SOURCE select.for:400 */
/*<       callmkdir(stdout,sb_home) >*/
	    mkdir_(stdout, feq_gen_sb_home_d_, sb_home_len);
/*           Adjust default file name if it still applies.  Note: */
/*           the code that gets the user-given file name does not */
/*           leave any leading blanks.  Thus we can tell if the */
/*           default name has been changed. */
/* SOURCE select.for:406 */
/*<       if(file_name.eq.' f_')then >*/
	    if (s_cmp(feq_gen_file_name_d_, const_cast<char*>(" f_"), (ftnlen)128, (ftnlen)3) == 0) {
/*             Default still applies and we have a home directory */
/*             given.  Add prefix of slash */
/* SOURCE select.for:409 */
/*<       file_name(1:1)='/' >*/
		*(unsigned char *)feq_gen_file_name_d_ = '/';
/* SOURCE select.for:410 */
/*<       endif >*/
	    }
/* SOURCE select.for:411 */
/*<       endif >*/
	}
/* SOURCE select.for:414 */
/*<       return >*/
	return 0;
/* SOURCE select.for:415 */
/*<       endif >*/
    }
/* SOURCE select.for:417 */
/*<       nxt=index(line,'=') >*/
    nxt = i_indx(line, const_cast<char*>("="), (ftnlen)196, (ftnlen)1);
/* SOURCE select.for:418 */
/*<       if(nxt.eq.0)then >*/
    if (nxt == 0) {
/* SOURCE select.for:419 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__22.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__22);
	e_wsfe();
/* SOURCE select.for:420 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE select.for:421 */
/*<       endif >*/
    }
/* SOURCE select.for:422 */
/*<       nxt=nxt-1 >*/
    --nxt;
/*       Extract the selector name */
/* SOURCE select.for:424 */
/*<       result=line(1:nxt) >*/
    s_copy(result, line, (ftnlen)128, nxt);
/* SOURCE select.for:425 */
/*<       callstrip_l_blanks(result) >*/
    feq_gen_strip_l_blanks_d_(result, (ftnlen)128);
/* SOURCE select.for:427 */
/*<       it=feq_len_trim(result) >*/
    it = feq_gen_feq_len_trim_d_(result, (ftnlen)128);
/* SOURCE select.for:428 */
/*<       if(it.gt.16)then >*/
    if (it > 16) {
/* SOURCE select.for:429 */
/*<       write(stdout,52)result(1:it) >*/
	feq_gen_io_d__24.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__24);
	do_fio(&feq_gen_c_d_1, result, it);
	e_wsfe();
/* SOURCE select.for:430 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE select.for:431 */
/*<       elseif(it.eq.0)then >*/
    } else if (it == 0) {
/* SOURCE select.for:432 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__25.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__25);
	e_wsfe();
/* SOURCE select.for:433 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE select.for:434 */
/*<       endif >*/
    }
/* SOURCE select.for:436 */
/*<       key=result(1:it) >*/
    s_copy(key, result, (ftnlen)16, it);
/*       Look for the selector value.  Move beyond the equal sign in line. */
/* SOURCE select.for:439 */
/*<       nxt=nxt+2 >*/
    nxt += 2;
/* SOURCE select.for:440 */
/*<       callnxttok(line,nxt,result) >*/
    nxttok_(line, &nxt, result, (ftnlen)196, (ftnlen)128);
/* SOURCE select.for:444 */
/*<       if(nxt.eq.0)then >*/
    if (nxt == 0) {
/* SOURCE select.for:445 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__27.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__27);
	e_wsfe();
/* SOURCE select.for:446 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE select.for:447 */
/*<       endif >*/
    }
/* SOURCE select.for:448 */
/*<       if(key.eq.'FILE')then >*/
    if (s_cmp(key, const_cast<char*>("FILE"), (ftnlen)16, (ftnlen)4) == 0) {
/* SOURCE select.for:449 */
/*<       file_name=result >*/
	s_copy(feq_gen_file_name_d_, result, (ftnlen)128, (ftnlen)128);
/* SOURCE select.for:450 */
/*<       elseif(key.eq.'MAKEHOMENAME')then >*/
    } else if (s_cmp(key, const_cast<char*>("MAKEHOMENAME"), (ftnlen)16, (ftnlen)12) == 0) {
/* SOURCE select.for:451 */
/*<       sb_home=result >*/
	s_copy(feq_gen_sb_home_d_, result, sb_home_len, (ftnlen)128);
/* SOURCE select.for:452 */
/*<       force_lc=0 >*/
	feq_gen_force_lc_d_ = 0;
/* SOURCE select.for:453 */
/*<       elseif(key.eq.'makehomename')then >*/
    } else if (s_cmp(key, const_cast<char*>("makehomename"), (ftnlen)16, (ftnlen)12) == 0) {
/* SOURCE select.for:454 */
/*<       sb_home=result >*/
	s_copy(feq_gen_sb_home_d_, result, sb_home_len, (ftnlen)128);
/* SOURCE select.for:455 */
/*<       force_lc=1 >*/
	feq_gen_force_lc_d_ = 1;
/* SOURCE select.for:456 */
/*<       else >*/
    } else {
/* SOURCE select.for:457 */
/*<       it=feq_len_trim(result) >*/
	it = feq_gen_feq_len_trim_d_(result, (ftnlen)128);
/* SOURCE select.for:458 */
/*<       if(result(1:4).eq.'TRUE'.or.result(1:4).eq.'true')then >*/
	if (s_cmp(result, const_cast<char*>("TRUE"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(result, 
		const_cast<char*>("true"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE select.for:459 */
/*<       value=1 >*/
	    value = 1;
/* SOURCE select.for:460 */
/*<       elseif(result(1:5).eq.'FALSE'.or.result(1:5).eq.'false')then >*/
	} else if (s_cmp(result, const_cast<char*>("FALSE"), (ftnlen)5, (ftnlen)5) == 0 || s_cmp(
		result, const_cast<char*>("false"), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE select.for:461 */
/*<       value=0 >*/
	    value = 0;
/* SOURCE select.for:462 */
/*<       else >*/
	} else {
/* SOURCE select.for:463 */
/*<       write(stdout,58)result(1:it) >*/
	    feq_gen_io_d__29.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__29);
	    do_fio(&feq_gen_c_d_1, result, it);
	    e_wsfe();
/* SOURCE select.for:464 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE select.for:465 */
/*<       endif >*/
	}
/*         The value of class is not used but is retained for possible future use. */
/* SOURCE select.for:469 */
/*<       class=1024 >*/
	feq_gen_class_d_ = 1024;
/* SOURCE select.for:471 */
/*<       calllsa_selector(stdout,key,class,value,nxt,it) >*/
	feq_gen_lsa_selector_d_(stdout, key, &feq_gen_class_d_, &value, &nxt, &it, (ftnlen)16);
/* SOURCE select.for:475 */
/*<       endif >*/
    }
/* SOURCE select.for:476 */
/*<       goto100 >*/
    goto L100;
/* SOURCE select.for:478 */
/*<       end >*/
} /* get_selectors__ */




/* SOURCE select.for:483 */
/*<       subroutinepush_token(token,state,level,line,pnt) >*/
/* Subroutine */ int feq_gen_push_token_d_(integer *token, integer *state, integer *
	level, char *line, integer *pnt, ftnlen line_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Put token set on the token stack */
/* SOURCE select.for:488 */
/*<       implicitnone >*/
/* SOURCE select.for:489 */
/*<       integertoken,state,level,pnt >*/
/* SOURCE select.for:490 */
/*<       character*(*)line >*/
/* INCLUDE select.for:492 */
/*     Stack for processing selection blocks in FEQ */
/* SOURCE selectstack.cmn:3 */
/*<       integermax_top >*/
/* SOURCE selectstack.cmn:4 */
/*<       parameter(max_top=100) >*/
/* SOURCE selectstack.cmn:6 */
/*<       integerselect_stack(3,max_top),top >*/
/* SOURCE selectstack.cmn:8 */
/*<       characterselect_stack_line(max_top)*196 >*/
/* SOURCE selectstack.cmn:10 */
/*<       common/select_cmn/select_stack,top >*/
/* SOURCE selectstack.cmn:11 */
/*<       common/select_cmnc/select_stack_line >*/
/* SOURCE selectstack.cmn:13 */
/*<       save/select_cmn/,/select_cmnc/ >*/
/* *********************************************************************** */
/* SOURCE select.for:495 */
/*<       top=top+1 >*/
    ++feq_gen_select_cmn_d_1.top;
/* SOURCE select.for:496 */
/*<       if(top.gt.max_top)then >*/
    if (feq_gen_select_cmn_d_1.top > 100) {
/* SOURCE select.for:497 */
/*<       pnt=-1 >*/
	*pnt = -1;
/* SOURCE select.for:498 */
/*<       else >*/
    } else {
/* SOURCE select.for:499 */
/*<       select_stack(1,top)=token >*/
	feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 3] = *token;
/* SOURCE select.for:500 */
/*<       select_stack(2,top)=state >*/
	feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 2] = *state;
/* SOURCE select.for:501 */
/*<       select_stack(3,top)=level >*/
	feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 1] = *level;
/* SOURCE select.for:502 */
/*<       select_stack_line(top)=line >*/
	s_copy(feq_gen_select_cmnc_d_1.feq_gen_select_stack_line_d_ + (feq_gen_select_cmn_d_1.top - 1) * 
		196, line, (ftnlen)196, line_len);
/* SOURCE select.for:503 */
/*<       pnt=top >*/
	*pnt = feq_gen_select_cmn_d_1.top;
/* SOURCE select.for:504 */
/*<       endif >*/
    }
/* SOURCE select.for:505 */
/*<       return >*/
    return 0;
/* SOURCE select.for:506 */
/*<       end >*/
} /* push_token__ */




/* SOURCE select.for:510 */
/*<       subroutinepop_token(token,state,level,line,pnt) >*/
/* Subroutine */ int feq_gen_pop_token_d_(integer *token, integer *state, integer *
	level, char *line, integer *pnt, ftnlen line_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Get last token set from stack and drop top of stack. */
/* SOURCE select.for:515 */
/*<       implicitnone >*/
/* SOURCE select.for:516 */
/*<       integertoken,state,level,pnt >*/
/* SOURCE select.for:517 */
/*<       character*(*)line >*/
/* INCLUDE select.for:519 */
/*     Stack for processing selection blocks in FEQ */
/* SOURCE selectstack.cmn:3 */
/*<       integermax_top >*/
/* SOURCE selectstack.cmn:4 */
/*<       parameter(max_top=100) >*/
/* SOURCE selectstack.cmn:6 */
/*<       integerselect_stack(3,max_top),top >*/
/* SOURCE selectstack.cmn:8 */
/*<       characterselect_stack_line(max_top)*196 >*/
/* SOURCE selectstack.cmn:10 */
/*<       common/select_cmn/select_stack,top >*/
/* SOURCE selectstack.cmn:11 */
/*<       common/select_cmnc/select_stack_line >*/
/* SOURCE selectstack.cmn:13 */
/*<       save/select_cmn/,/select_cmnc/ >*/
/* *********************************************************************** */
/* SOURCE select.for:522 */
/*<       if(top.eq.0)then >*/
    if (feq_gen_select_cmn_d_1.top == 0) {
/* SOURCE select.for:523 */
/*<       pnt=-1 >*/
	*pnt = -1;
/* SOURCE select.for:524 */
/*<       else >*/
    } else {
/* SOURCE select.for:525 */
/*<       token=select_stack(1,top) >*/
	*token = feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 3];
/* SOURCE select.for:526 */
/*<       state=select_stack(2,top) >*/
	*state = feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 2];
/* SOURCE select.for:527 */
/*<       level=select_stack(3,top) >*/
	*level = feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 1];
/* SOURCE select.for:528 */
/*<       line=select_stack_line(top) >*/
	s_copy(line, feq_gen_select_cmnc_d_1.feq_gen_select_stack_line_d_ + (feq_gen_select_cmn_d_1.top 
		- 1) * 196, line_len, (ftnlen)196);
/* SOURCE select.for:529 */
/*<       top=top-1 >*/
	--feq_gen_select_cmn_d_1.top;
/* SOURCE select.for:530 */
/*<       pnt=top >*/
	*pnt = feq_gen_select_cmn_d_1.top;
/* SOURCE select.for:531 */
/*<       endif >*/
    }
/* SOURCE select.for:532 */
/*<       return >*/
    return 0;
/* SOURCE select.for:533 */
/*<       end >*/
} /* pop_token__ */




/* SOURCE select.for:538 */
/*<       subroutineget_top_of_stack(token,state,level,line,pnt) >*/
/* Subroutine */ int feq_gen_get_top_of_stack_d_(integer *token, integer *state, 
	integer *level, char *line, integer *pnt, ftnlen line_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Get last token set from stack */
/* SOURCE select.for:543 */
/*<       implicitnone >*/
/* SOURCE select.for:544 */
/*<       integertoken,state,level,pnt >*/
/* SOURCE select.for:545 */
/*<       character*(*)line >*/
/* INCLUDE select.for:546 */
/*     Stack for processing selection blocks in FEQ */
/* SOURCE selectstack.cmn:3 */
/*<       integermax_top >*/
/* SOURCE selectstack.cmn:4 */
/*<       parameter(max_top=100) >*/
/* SOURCE selectstack.cmn:6 */
/*<       integerselect_stack(3,max_top),top >*/
/* SOURCE selectstack.cmn:8 */
/*<       characterselect_stack_line(max_top)*196 >*/
/* SOURCE selectstack.cmn:10 */
/*<       common/select_cmn/select_stack,top >*/
/* SOURCE selectstack.cmn:11 */
/*<       common/select_cmnc/select_stack_line >*/
/* SOURCE selectstack.cmn:13 */
/*<       save/select_cmn/,/select_cmnc/ >*/
/* *********************************************************************** */
/* SOURCE select.for:549 */
/*<       if(top.eq.0)then >*/
    if (feq_gen_select_cmn_d_1.top == 0) {
/* SOURCE select.for:550 */
/*<       pnt=-1 >*/
	*pnt = -1;
/* SOURCE select.for:551 */
/*<       else >*/
    } else {
/* SOURCE select.for:552 */
/*<       token=select_stack(1,top) >*/
	*token = feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 3];
/* SOURCE select.for:553 */
/*<       state=select_stack(2,top) >*/
	*state = feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 2];
/* SOURCE select.for:554 */
/*<       level=select_stack(3,top) >*/
	*level = feq_gen_select_cmn_d_1.feq_gen_select_stack_d_[feq_gen_select_cmn_d_1.top * 3 - 1];
/* SOURCE select.for:555 */
/*<       line=select_stack_line(top) >*/
	s_copy(line, feq_gen_select_cmnc_d_1.feq_gen_select_stack_line_d_ + (feq_gen_select_cmn_d_1.top 
		- 1) * 196, line_len, (ftnlen)196);
/* SOURCE select.for:556 */
/*<       pnt=top >*/
	*pnt = feq_gen_select_cmn_d_1.top;
/* SOURCE select.for:557 */
/*<       endif >*/
    }
/* SOURCE select.for:558 */
/*<       return >*/
    return 0;
/* SOURCE select.for:559 */
/*<       end >*/
} /* get_top_of_stack__ */




/* SOURCE select.for:564 */
/*<       subroutineclear_select_stack() >*/
/* Subroutine */ int feq_gen_clear_select_stack_d_()
{
/*     Clear the selection-block processing stack */
/* INCLUDE select.for:568 */
/*     Stack for processing selection blocks in FEQ */
/* SOURCE selectstack.cmn:3 */
/*<       integermax_top >*/
/* SOURCE selectstack.cmn:4 */
/*<       parameter(max_top=100) >*/
/* SOURCE selectstack.cmn:6 */
/*<       integerselect_stack(3,max_top),top >*/
/* SOURCE selectstack.cmn:8 */
/*<       characterselect_stack_line(max_top)*196 >*/
/* SOURCE selectstack.cmn:10 */
/*<       common/select_cmn/select_stack,top >*/
/* SOURCE selectstack.cmn:11 */
/*<       common/select_cmnc/select_stack_line >*/
/* SOURCE selectstack.cmn:13 */
/*<       save/select_cmn/,/select_cmnc/ >*/
/* ******************************************************************************* */
/* SOURCE select.for:570 */
/*<       top=0 >*/
    feq_gen_select_cmn_d_1.top = 0;
/* SOURCE select.for:571 */
/*<       return >*/
    return 0;
/* SOURCE select.for:572 */
/*<       end >*/
} /* clear_select_stack__ */




/* SOURCE select.for:577 */
/*<        >*/
/* Subroutine */ int feq_gen_classify_line_d_(integer *stdout, char *line, integer *
	feq_gen_old_level_d_, integer *feq_gen_old_token_d_, integer *token, integer *state, 
	integer *feq_gen_token_level_d_, ftnlen line_len)
{
    /* Initialized data */

    static integer feq_gen_true_d_ = 1;
    static integer feq_gen_false_d_ = 0;
    static char feq_gen_not_symbol_d_[1+1] = "~";
    static integer feq_gen_delta_level_d_[25]	/* was [5][5] */ = { 0,1,1,1,0,0,1,1,
	    1,0,-1,0,0,0,-1,-1,0,0,0,-1,-1,0,0,0,-1 };

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char selector[16];
    integer it, feq_keyword_not, nxt;
    extern /* Subroutine */ int feq_gen_ls_selector_d_(char *, integer *, integer *, 
	    integer *, ftnlen);
    integer dlev, indx;
    char work[196];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer feq_gen_class_d_;
    char result[64];
    extern /* Subroutine */ int nxttok_(char *, integer *, char *, ftnlen, 
	    ftnlen), feq_gen_strip_l_blanks_d_(char *, ftnlen);
    integer feq_gen_selector_value_d_;

/*     Given a line, seek selection keywords, define the token values, */
/*     determine the value for the STATE of the keyword if it has one, */
/*     and adjust the level as required.  If the keyword has no STATE */
/*     return STATE as true. */
/* SOURCE select.for:586 */
/*<       implicitnone >*/
/* SOURCE select.for:587 */
/*<       integerold_level,token_level,state,token,stdout,old_token >*/
/* SOURCE select.for:589 */
/*<       character*196line >*/
/*     Local */
/* SOURCE select.for:593 */
/*<        >*/
/* SOURCE select.for:596 */
/*<       characterresult*64,work*196,selector*16,not_symbol*1 >*/
/* SOURCE select.for:599 */
/*<        >*/
/* SOURCE select.for:601 */
/*<        >*/
/*     **********************Formats************************************* */
/* ******************************************************************************* */
/* SOURCE select.for:577 */
/*<       integer feq_len_trim >*/
/* SOURCE select.for:577 */
/*<       external feq_len_trim >*/
/* SOURCE select.for:603 */
/*<       datatrue/1/,false/0/,not_symbol/'~'/ >*/
/* SOURCE select.for:604 */
/*<        >*/
/* SOURCE select.for:613 */
/*<       work=line >*/
    s_copy(work, line, (ftnlen)196, (ftnlen)196);
/* SOURCE select.for:614 */
/*<       nxt=1 >*/
    nxt = 1;
/* SOURCE select.for:615 */
/*<       callstrip_l_blanks(work) >*/
    feq_gen_strip_l_blanks_d_(work, (ftnlen)196);
/* SOURCE select.for:618 */
/*<       callnxttok(work,nxt,result) >*/
    nxttok_(work, &nxt, result, (ftnlen)196, (ftnlen)64);
/* SOURCE select.for:622 */
/*<       if(nxt.eq.0)then >*/
    if (nxt == 0) {
/*       Line was blank */
/* SOURCE select.for:624 */
/*<       token=none_token >*/
	*token = 0;
/* SOURCE select.for:625 */
/*<       state=true >*/
	*state = feq_gen_true_d_;
/* SOURCE select.for:626 */
/*<       elseif(result(1:3).eq.'IF ')then >*/
    } else if (s_cmp(result, const_cast<char*>("IF "), (ftnlen)3, (ftnlen)3) == 0) {
/*       Found the if statement */
/* SOURCE select.for:628 */
/*<       token=if_token >*/
	*token = 1;
/*       Seek the selector */
/* SOURCE select.for:630 */
/*<       callnxttok(work,nxt,result) >*/
	nxttok_(work, &nxt, result, (ftnlen)196, (ftnlen)64);
/* SOURCE select.for:634 */
/*<       if(result(1:1).eq.not_symbol)then >*/
	if (*(unsigned char *)result == *(unsigned char *)&feq_gen_not_symbol_d_[0]) {
/* SOURCE select.for:635 */
/*<       not=true >*/
	    feq_keyword_not = feq_gen_true_d_;
/* SOURCE select.for:636 */
/*<       selector=result(2:17) >*/
	    s_copy(selector, result + 1, (ftnlen)16, (ftnlen)16);
/* SOURCE select.for:637 */
/*<       else >*/
	} else {
/* SOURCE select.for:638 */
/*<       not=false >*/
	    feq_keyword_not = feq_gen_false_d_;
/* SOURCE select.for:639 */
/*<       selector=result(1:16) >*/
	    s_copy(selector, result, (ftnlen)16, (ftnlen)16);
/* SOURCE select.for:640 */
/*<       endif >*/
	}
/* SOURCE select.for:641 */
/*<       callls_selector(selector,class,selector_value,indx) >*/
	feq_gen_ls_selector_d_(selector, &feq_gen_class_d_, &feq_gen_selector_value_d_, &indx, (ftnlen)
		16);
/* SOURCE select.for:645 */
/*<       if(indx.eq.0)then >*/
	if (indx == 0) {
/* SOURCE select.for:646 */
/*<       it=feq_len_trim(selector) >*/
	    it = feq_gen_feq_len_trim_d_(selector, (ftnlen)16);
/* SOURCE select.for:647 */
/*<       selector_value=false >*/
	    feq_gen_selector_value_d_ = feq_gen_false_d_;
/* SOURCE select.for:648 */
/*<       class=1024 >*/
	    feq_gen_class_d_ = 1024;
/*          STOP 'Abnormal stop. Error(s) found.' */
/* SOURCE select.for:650 */
/*<       endif >*/
	}
/* SOURCE select.for:651 */
/*<       if(not.eq.true)then >*/
	if (feq_keyword_not == feq_gen_true_d_) {
/* SOURCE select.for:652 */
/*<       if(selector_value.eq.true)then >*/
	    if (feq_gen_selector_value_d_ == feq_gen_true_d_) {
/* SOURCE select.for:653 */
/*<       selector_value=false >*/
		feq_gen_selector_value_d_ = feq_gen_false_d_;
/* SOURCE select.for:654 */
/*<       else >*/
	    } else {
/* SOURCE select.for:655 */
/*<       selector_value=true >*/
		feq_gen_selector_value_d_ = feq_gen_true_d_;
/* SOURCE select.for:656 */
/*<       endif >*/
	    }
/* SOURCE select.for:657 */
/*<       endif >*/
	}
/* SOURCE select.for:658 */
/*<       state=selector_value >*/
	*state = feq_gen_selector_value_d_;
/* SOURCE select.for:660 */
/*<       elseif(result(1:6).eq.'ELSEIF')then >*/
    } else if (s_cmp(result, const_cast<char*>("ELSEIF"), (ftnlen)6, (ftnlen)6) == 0) {
/*       Found the elseif statement */
/* SOURCE select.for:662 */
/*<       token=elseif_token >*/
	*token = 3;
/*       Seek the selector */
/* SOURCE select.for:664 */
/*<       callnxttok(work,nxt,result) >*/
	nxttok_(work, &nxt, result, (ftnlen)196, (ftnlen)64);
/* SOURCE select.for:668 */
/*<       if(result(1:1).eq.not_symbol)then >*/
	if (*(unsigned char *)result == *(unsigned char *)&feq_gen_not_symbol_d_[0]) {
/* SOURCE select.for:669 */
/*<       not=true >*/
	    feq_keyword_not = feq_gen_true_d_;
/* SOURCE select.for:670 */
/*<       selector=result(2:17) >*/
	    s_copy(selector, result + 1, (ftnlen)16, (ftnlen)16);
/* SOURCE select.for:671 */
/*<       else >*/
	} else {
/* SOURCE select.for:672 */
/*<       not=false >*/
	    feq_keyword_not = feq_gen_false_d_;
/* SOURCE select.for:673 */
/*<       selector=result(1:16) >*/
	    s_copy(selector, result, (ftnlen)16, (ftnlen)16);
/* SOURCE select.for:674 */
/*<       endif >*/
	}
/* SOURCE select.for:675 */
/*<       callls_selector(selector,class,selector_value,indx) >*/
	feq_gen_ls_selector_d_(selector, &feq_gen_class_d_, &feq_gen_selector_value_d_, &indx, (ftnlen)
		16);
/* SOURCE select.for:679 */
/*<       if(indx.eq.0)then >*/
	if (indx == 0) {
/* SOURCE select.for:680 */
/*<       it=feq_len_trim(selector) >*/
	    it = feq_gen_feq_len_trim_d_(selector, (ftnlen)16);
/*          WRITE(STDOUT,50) SELECTOR(1:IT) */
/* SOURCE select.for:682 */
/*<       selector_value=false >*/
	    feq_gen_selector_value_d_ = feq_gen_false_d_;
/* SOURCE select.for:683 */
/*<       class=1024 >*/
	    feq_gen_class_d_ = 1024;
/*          STOP 'Abnormal stop. Error(s) found.' */
/* SOURCE select.for:685 */
/*<       endif >*/
	}
/* SOURCE select.for:686 */
/*<       if(not.eq.true)then >*/
	if (feq_keyword_not == feq_gen_true_d_) {
/* SOURCE select.for:687 */
/*<       if(selector_value.eq.true)then >*/
	    if (feq_gen_selector_value_d_ == feq_gen_true_d_) {
/* SOURCE select.for:688 */
/*<       selector_value=false >*/
		feq_gen_selector_value_d_ = feq_gen_false_d_;
/* SOURCE select.for:689 */
/*<       else >*/
	    } else {
/* SOURCE select.for:690 */
/*<       selector_value=true >*/
		feq_gen_selector_value_d_ = feq_gen_true_d_;
/* SOURCE select.for:691 */
/*<       endif >*/
	    }
/* SOURCE select.for:692 */
/*<       endif >*/
	}
/* SOURCE select.for:693 */
/*<       state=selector_value >*/
	*state = feq_gen_selector_value_d_;
/* SOURCE select.for:694 */
/*<       elseif(result(1:4).eq.'ELSE')then >*/
    } else if (s_cmp(result, const_cast<char*>("ELSE"), (ftnlen)4, (ftnlen)4) == 0) {
/*       Found the else statement */
/* SOURCE select.for:696 */
/*<       token=else_token >*/
	*token = 2;
/*       Set state here but value will be replaced by calling unit. */
/* SOURCE select.for:698 */
/*<       state=true >*/
	*state = feq_gen_true_d_;
/* SOURCE select.for:699 */
/*<       elseif(result(1:5).eq.'ENDIF')then >*/
    } else if (s_cmp(result, const_cast<char*>("ENDIF"), (ftnlen)5, (ftnlen)5) == 0) {
/*       Found the endif statement */
/* SOURCE select.for:701 */
/*<       token=endif_token >*/
	*token = 4;
/*       Set state here but value will be replaced by calling unit. */
/* SOURCE select.for:703 */
/*<       state=true >*/
	*state = feq_gen_true_d_;
/* SOURCE select.for:704 */
/*<       elseif(result(1:7).eq.'ENDFILE')then >*/
    } else if (s_cmp(result, const_cast<char*>("ENDFILE"), (ftnlen)7, (ftnlen)7) == 0) {
/*       Found the endfile statement */
/* SOURCE select.for:706 */
/*<       token=endfile_token >*/
	*token = 5;
/*       Set state here but value will be replaced by calling unit. */
/* SOURCE select.for:708 */
/*<       state=true >*/
	*state = feq_gen_true_d_;
/* SOURCE select.for:709 */
/*<       else >*/
    } else {
/* SOURCE select.for:710 */
/*<       token=none_token >*/
	*token = 0;
/* SOURCE select.for:711 */
/*<       state=true >*/
	*state = feq_gen_true_d_;
/* SOURCE select.for:712 */
/*<       endif >*/
    }
/*     Set the level and adjust OLD_TOKEN */
/* SOURCE select.for:715 */
/*<       if(token.eq.endfile_token)then >*/
    if (*token == 5) {
/* SOURCE select.for:716 */
/*<       token_level=old_level >*/
	*feq_gen_token_level_d_ = *feq_gen_old_level_d_;
/* SOURCE select.for:717 */
/*<       else >*/
    } else {
/*       Define the change in level */
/* SOURCE select.for:719 */
/*<       dlev=delta_level(old_token,token) >*/
	dlev = feq_gen_delta_level_d_[*feq_gen_old_token_d_ + *token * 5];
/*        WRITE(STDOUT,*) ' ' */
/*        WRITE(STDOUT,*) ' OLD_TOKEN=',OLD_TOKEN,' TOKEN=',TOKEN */
/*        WRITE(STDOUT,*) ' LEVEL_CHANGE=',DLEV,' NEW_LEVEL=',TOKEN_LEVEL */
/*        WRITE(STDOUT,'(A)') LINE */
/* SOURCE select.for:724 */
/*<       token_level=old_level+dlev >*/
	*feq_gen_token_level_d_ = *feq_gen_old_level_d_ + dlev;
/* SOURCE select.for:725 */
/*<       old_level=token_level >*/
	*feq_gen_old_level_d_ = *feq_gen_token_level_d_;
/* SOURCE select.for:726 */
/*<       endif >*/
    }
/* SOURCE select.for:728 */
/*<       old_token=token >*/
    *feq_gen_old_token_d_ = *token;
/* SOURCE select.for:730 */
/*<       return >*/
    return 0;
/* SOURCE select.for:731 */
/*<       end >*/
} /* classify_line__ */




/* SOURCE select.for:735 */
/*<        >*/
/* Subroutine */ int feq_gen_discard_lines_d_(integer *stdin, integer *stdout, integer 
	*feq_gen_target_level_d_, integer *feq_gen_old_level_d_, integer *feq_gen_old_token_d_, integer *
	token, integer *state, integer *feq_gen_token_level_d_)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:421* End of master-input file reach\
ed when not\002,\002 expected.  Possible missing ENDIF statement.\002)";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_inline_all_d_(integer *, char *, ftnlen);
    char line[196];
    extern /* Subroutine */ int feq_gen_classify_line_d_(integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__46 = { 0, 0, 0, fmt_50, 0 };


/*     Read and discard lines until the level of a keyword matches */
/*     the target level.  Return the keyword description. */
/* SOURCE select.for:742 */
/*<       implicitnone >*/
/* SOURCE select.for:744 */
/*<        >*/
/*     Local */
/* SOURCE select.for:749 */
/*<       characterline*196 >*/
/*     **************************Formats********************************* */
/* SOURCE select.for:751 */
/*<    50  >*/
/* ******************************************************************************* */
/*      WRITE(STDOUT,*) 'Entering Discard lines' */
/* SOURCE select.for:755 */
/*<   100 continue >*/
/* L50: */
L100:
/* SOURCE select.for:756 */
/*<       callinline_all(stdin,line) >*/
    feq_gen_inline_all_d_(stdin, line, (ftnlen)196);
/* SOURCE select.for:759 */
/*<       if(line(1:7).eq.'ENDFILE')then >*/
    if (s_cmp(line, const_cast<char*>("ENDFILE"), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE select.for:760 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__46.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__46);
	e_wsfe();
/* SOURCE select.for:761 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:762 */
/*<       endif >*/
    }
/* SOURCE select.for:764 */
/*<        >*/
    feq_gen_classify_line_d_(stdout, line, feq_gen_old_level_d_, feq_gen_old_token_d_, token, state, 
	    feq_gen_token_level_d_, (ftnlen)196);
/* SOURCE select.for:768 */
/*<       if(token_level.eq.target_level)then >*/
    if (*feq_gen_token_level_d_ == *feq_gen_target_level_d_) {
/*      WRITE(STDOUT,*) 'Leaving Discard lines' */
/* SOURCE select.for:771 */
/*<       return >*/
	return 0;
/* SOURCE select.for:772 */
/*<       endif >*/
    }
/* SOURCE select.for:773 */
/*<       goto100 >*/
    goto L100;
/* SOURCE select.for:774 */
/*<       end >*/
} /* discard_lines__ */




/* SOURCE select.for:779 */
/*<        >*/
/* Subroutine */ int feq_gen_discard_lines_to_endif_d_(integer *stdin, integer *stdout,
	 integer *feq_gen_target_level_d_, integer *feq_gen_old_level_d_, integer *feq_gen_old_token_d_, 
	integer *token, integer *state, integer *feq_gen_token_level_d_)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:421* End of master-input file reach\
ed when not\002,\002 expected.  Possible missing ENDIF statement.\002)";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_inline_all_d_(integer *, char *, ftnlen);
    char line[196];
    extern /* Subroutine */ int feq_gen_classify_line_d_(integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_50, 0 };


/*     Read and discard lines until an ENDIF token is found at the */
/*     the target level.  Return the keyword description. */
/* SOURCE select.for:786 */
/*<       implicitnone >*/
/* SOURCE select.for:788 */
/*<        >*/
/*     Local */
/* SOURCE select.for:792 */
/*<       integerendif_token >*/
/* SOURCE select.for:793 */
/*<       parameter(endif_token=4) >*/
/* SOURCE select.for:795 */
/*<       characterline*196 >*/
/*     **************************Formats********************************* */
/* SOURCE select.for:797 */
/*<    50  >*/
/* ******************************************************************************* */
/*      WRITE(STDOUT,*) 'Entering Discard lines to endif' */
/* SOURCE select.for:802 */
/*<   100 continue >*/
/* L50: */
L100:
/* SOURCE select.for:803 */
/*<       callinline_all(stdin,line) >*/
    feq_gen_inline_all_d_(stdin, line, (ftnlen)196);
/* SOURCE select.for:806 */
/*<       if(line(1:7).eq.'ENDFILE')then >*/
    if (s_cmp(line, const_cast<char*>("ENDFILE"), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE select.for:807 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__48.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__48);
	e_wsfe();
/* SOURCE select.for:808 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:809 */
/*<       endif >*/
    }
/* SOURCE select.for:811 */
/*<        >*/
    feq_gen_classify_line_d_(stdout, line, feq_gen_old_level_d_, feq_gen_old_token_d_, token, state, 
	    feq_gen_token_level_d_, (ftnlen)196);
/* SOURCE select.for:815 */
/*<       if(token_level.eq.target_level.and.token.eq.endif_token)then >*/
    if (*feq_gen_token_level_d_ == *feq_gen_target_level_d_ && *token == 4) {
/*      WRITE(STDOUT,*) 'Leaving Discard lines to endif' */
/* SOURCE select.for:819 */
/*<       return >*/
	return 0;
/* SOURCE select.for:820 */
/*<       endif >*/
    }
/* SOURCE select.for:821 */
/*<       goto100 >*/
    goto L100;
/* SOURCE select.for:822 */
/*<       end >*/
} /* discard_lines_to_endif__ */




/* SOURCE select.for:826 */
/*<       subroutineset_or_update_selector(stdout,stdtmp,work,flag) >*/
/* Subroutine */ int feq_gen_set_or_update_selector_d_(integer *stdout, integer *
	stdtmp, char *work, integer *feq_gen_flag_d_, ftnlen work_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:441*  Selector variable=\002,a16\
,\002 has invalid value=\002,a5,\002.  Should be true or false.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_cmp(char *, char *, 
	    ftnlen, ftnlen), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_to_lower_d_(char *, ftnlen);
    integer k;
    char key[16];
    extern /* Subroutine */ int feq_gen_feq_adjustl_d_(char *, char *, ftnlen, ftnlen);
    integer feq_gen_class_d_, value;
    extern /* Subroutine */ int feq_gen_lsua_selector_d_(integer *, char *, integer *, 
	    integer *, integer *, integer *, ftnlen);
    char result[5];
    integer feq_gen_key_pnt_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_50, 0 };


/*     Process a set selector line outside of the set selector's block */
/* SOURCE select.for:831 */
/*<       implicitnone >*/
/* SOURCE select.for:832 */
/*<       integerstdout,stdtmp >*/
/* SOURCE select.for:833 */
/*<       character*(*)work >*/
/*     Local variables */
/* SOURCE select.for:836 */
/*<       integerk,class,value,key_pnt,flag,nxt >*/
/* SOURCE select.for:837 */
/*<       characterkey*16,result*5 >*/
/*     *****************************formats****************************** */
/* SOURCE select.for:840 */
/*<    50  >*/
/* *********************************************************************** */
/*      write(stdtmp,*) ' SET statement found' */
/*     Find the equal sign. */
/* SOURCE select.for:845 */
/*<       k=index(work,'=') >*/
/* L50: */
    k = i_indx(work, const_cast<char*>("="), work_len, (ftnlen)1);
/* SOURCE select.for:846 */
/*<       if(k==0)then >*/
    if (k == 0) {
/* SOURCE select.for:847 */
/*<       flag=10 >*/
	*feq_gen_flag_d_ = 10;
/* SOURCE select.for:848 */
/*<       return >*/
	return 0;
/* SOURCE select.for:849 */
/*<       endif >*/
    }
/*     Get the selector name */
/* SOURCE select.for:851 */
/*<       callfeq_adjustl(work(1:k-1),key) >*/
    feq_gen_feq_adjustl_d_(work, key, k - 1, (ftnlen)16);
/*     Class not used yet but set to 0 */
/* SOURCE select.for:854 */
/*<       class=0 >*/
    feq_gen_class_d_ = 0;
/*     get the value for the selector */
/* SOURCE select.for:858 */
/*<       callfeq_adjustl(work(k+1:),result) >*/
    feq_gen_i_d_1 = k;
    feq_gen_feq_adjustl_d_(work + feq_gen_i_d_1, result, work_len - feq_gen_i_d_1, (ftnlen)5);
/* SOURCE select.for:859 */
/*<       callto_lower(result) >*/
    feq_gen_to_lower_d_(result, (ftnlen)5);
/* SOURCE select.for:861 */
/*<       if(result(1:4)=='true')then >*/
    if (s_cmp(result, const_cast<char*>("true"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE select.for:862 */
/*<       value=1 >*/
	value = 1;
/* SOURCE select.for:863 */
/*<       elseif(result=='false')then >*/
    } else if (s_cmp(result, const_cast<char*>("false"), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE select.for:864 */
/*<       value=0 >*/
	value = 0;
/* SOURCE select.for:865 */
/*<       else >*/
    } else {
/* SOURCE select.for:866 */
/*<       write(stdout,50)key,result >*/
	feq_gen_io_d__54.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__54);
	do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, result, (ftnlen)5);
	e_wsfe();
/* SOURCE select.for:867 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE select.for:868 */
/*<       endif >*/
    }
/* SOURCE select.for:869 */
/*<       calllsua_selector(stdout,key,class,value,key_pnt,flag) >*/
    feq_gen_lsua_selector_d_(stdout, key, &feq_gen_class_d_, &value, &feq_gen_key_pnt_d_, feq_gen_flag_d_, (
	    ftnlen)16);
/* SOURCE select.for:873 */
/*<       if(flag>1)then >*/
    if (*feq_gen_flag_d_ > 1) {
/* SOURCE select.for:874 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE select.for:875 */
/*<       endif >*/
    }
/* SOURCE select.for:877 */
/*<       return >*/
    return 0;
/* SOURCE select.for:878 */
/*<       end >*/
} /* set_or_update_selector__ */




/* SOURCE select.for:883 */
/*<        >*/
/* Subroutine */ int feq_gen_scan_master_input_d_(integer *stdin, integer *stdout, 
	char *feq_gen_file_name_d_, char *feq_gen_sb_home_d_, char *fname1, integer *eflag, 
	ftnlen file_name_len, ftnlen sb_home_len, ftnlen fname1_len)
{
    /* Initialized data */

    static integer feq_gen_true_d_ = 1;
    static integer feq_gen_false_d_ = 0;
    static integer action[24]	/* was [4][6] */ = { 1,2,2,2,3,4,4,4,5,6,7,6,
	    8,9,10,9,11,12,12,12,13,14,15,16 };

    /* Format strings */
    static char fmt_54[] = "(/,\002 *ERR:423* The following file could not b\
e opened:\002,/,5x,a,/,\002 Make sure the pathname exists and that you\002\
,\002 have permission to write to the file.\002)";
    static char fmt_56[] = "(/,\002 *WRN:59* The selector-block home directo\
ry is:\002,/,5x,a,/,\002 and the file name: \002,a,/,\002 does not have a le\
ading slash.  A slash has been\002,\002 added.\002)";
    static char fmt_58[] = "(/,\002 *BUG* STACK_TOKEN=\002,i5,\002 invalid o\
n stack!\002)";
    static char fmt_60[] = "(/,\002 *ERR:433* Secondary master-input file na\
me=\002,/,5x,a,/,\002 is same as primary master-input filename=\002,/,5x,a)";
    static char fmt_505[] = "(/,\002 *ERR:424* ELSE found but no matching IF\
/ELSEIF exists.\002)";
    static char fmt_506[] = "(/,\002 *ERR:425* Possible missing ENDIF.\002)";
    static char fmt_507[] = "(/,\002 *ERR:426* ELSE found after an ELSE.\002)"
	    ;
    static char fmt_508[] = "(/,\002 *ERR:427* ELSEIF found but no matching \
IF/ELSEIF exists.\002)";
    static char fmt_510[] = "(/,\002 *ERR:428* ELSEIF found after matching E\
LSE.\002)";
    static char fmt_511[] = "(/,\002 *ERR:429* ENDIF found with no matching \
IF, ELSE, or ENDIF.\002)";
    static char fmt_514[] = "(/,\002 *ERR:430* At end of master-input file a\
nd no ENDIF\002,\002 for IF found.\002)";
    static char fmt_515[] = "(/,\002 *ERR:431* At end of master-input file a\
nd no ENDIF\002,\002 for ELSE found.\002)";
    static char fmt_516[] = "(/,\002 *ERR:432* At end of master-input file a\
nd no ENDIF\002,\002 for ELSEIF found.\002)";
    static char fmt_518[] = "(/,\002 *ERR:442* Equal sign missing from a set\
 selector line\002,\002outside of the set selectors block.\002)";
    static char fmt_520[] = "(/,\002 Line is:\002,a)";

    /* System generated locals */
    address feq_gen_a_d_1[3], feq_gen_a_d_2[2];
    integer feq_gen_i_d_1[3], feq_gen_i_d_2[2];
    cilist feq_gen_ci_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_stop(char *, ftnlen);
    integer f_open(olist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle(), f_clos(cllist *);

    /* Local variables */
    extern integer feq_gen_get_unit_d_(integer *);
    extern /* Subroutine */ int feq_gen_get_top_of_stack_d_(integer *, integer *, 
	    integer *, char *, integer *, ftnlen);
    integer feq_gen_old_level_d_, feq_gen_old_token_d_;
    extern /* Subroutine */ int feq_gen_pop_token_d_(integer *, integer *, integer *, 
	    char *, integer *, ftnlen);
    integer it;
    extern /* Subroutine */ int feq_gen_inline_all_d_(integer *, char *, ftnlen);
    char feq_gen_stack_line_d_[196];
    extern /* Subroutine */ int feq_gen_clear_select_stack_d_(), feq_gen_push_token_d_(integer *
	    , integer *, integer *, char *, integer *, ftnlen);
    integer act, feq_gen_stack_level_d_;
    extern /* Subroutine */ int feq_gen_feq_adjustl_d_(char *, char *, ftnlen, ftnlen);
    integer feq_gen_stack_token_d_, feq_gen_stack_state_d_, feq_gen_flag_d_;
    char line[196], work[196];
    integer feq_gen_inhand_level_d_, feq_gen_inhand_token_d_, feq_gen_inhand_state_d_;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer feq_gen_discard_level_d_;
    extern /* Subroutine */ int feq_gen_discard_lines_d_(integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *);
    integer feq_gen_discard_token_d_, feq_gen_discard_state_d_;
    extern /* Subroutine */ int feq_gen_classify_line_d_(integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen), 
	    feq_gen_os_file_style_d_(char *, ftnlen);
    integer inhand, ioflag, feq_gen_len_stack_line_d_, stdtmp;
    extern /* Subroutine */ int feq_gen_discard_lines_to_endif_d_(integer *, integer *,
	     integer *, integer *, integer *, integer *, integer *, integer *)
	    , feq_gen_set_or_update_selector_d_(integer *, integer *, char *, integer *
	    , ftnlen);
    integer feq_gen_top_pnt_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__79 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_518, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_518, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_505, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_506, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, fmt_507, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_508, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_506, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_510, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_511, 0 };
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_506, 0 };
    static cilist feq_gen_io_d__106 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_514, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_515, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_520, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_516, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, fmt_520, 0 };


/*     Scan the master input file and select the input to use. */
/* SOURCE select.for:889 */
/*<       implicitnone >*/
/* SOURCE select.for:891 */
/*<       integerstdin,stdout,eflag >*/
/* SOURCE select.for:893 */
/*<       characterfile_name*128,sb_home*(*),fname1*64 >*/
/*     Called program units */
/* SOURCE select.for:897 */
/*<       integerget_unit >*/
/* SOURCE select.for:898 */
/*<       externalget_unit,os_file_style >*/
/*     Local */
/* SOURCE select.for:902 */
/*<        >*/
/* SOURCE select.for:909 */
/*<       characterline*196,work*196,stack_line*196 >*/
/* SOURCE select.for:911 */
/*<        >*/
/* SOURCE select.for:913 */
/*<        >*/
/*     Outline of process: */
/*       We read lines from STDIN and check each line for a keyword, */
/*       IF, ELSE, ELSEIF, ENDIF, or ENDFILE.  Each occurrence of a keyword */
/*       is assigned a level.  The level starts at 0.  When an IF is found, */
/*       it is given the current level and then the current level is incremented. */
/*       When a ENDIF is found the current level is decremented and the */
/*       value is then given to the ENDIF.  An ELSE or an ELSEIF gets */
/*       current level less 1.   Each keyword gets a token values, */
/*       that is, a numeric code that we assign for our convenience. */
/*       We maintain a pushdown stack, or just a stack, that is a last-in */
/*       first-out structure.  We can put sets of values on this stack and */
/*       we can pop off the top of the stack.  We also maintain a pointer that */
/*       points to the top of the stack. */
/*       A line that does not contain a keyword is given a token as */
/*       well and has values just like a line with a keyword.  These values */
/*       are carefully chosen so that the algorithm will work.  The token */
/*       is the NONE_TOKEN for a line not containing a keyword. */
/*       We keep track of the the current truth STATE of each token. */
/*       It can be true or false.  In some cases the value we assign is */
/*       for our convenience, e. g. for a line not containing a keyword */
/*       as well as the ENDFILE line.  Otherwise the truth state is */
/*       based on the context.  Thus we keep track of three values: */
/*       TOKEN, STATE, and LEVEL.  We do this for two sets of values: */
/*       1. the top-of-stack, and 2. the in-hand.  The in-hand values */
/*       are the ones we get as we process the information. */
/*       It is then possible using the current top-of-stack set and the */
/*       current in-hand set, to define a set of actions that depends on these */
/*       two sets of values.  It is then possible to process any valid nested */
/*       set of keywords to select those parts of the input from the master input */
/*       file that we will retain for processing with FEQ. */
/*       We initialize the top of stack to the NONE_TOKEN, STATE:false, and level 0. */
/*       At some points the next line that we need has already been processed in the */
/*       actions.  At other times we must read a new line to get the in-hand information. */
/*       Thuse we must set a control value for reading a new line: INHAND.  INHAND */
/*       must start out as false. */
/*       Here is the contents of the action matrix: */
/*  Token on                        Token in */
/*  Stack                           Hand */
/* ----------  ------------------------------------------------------------------------------------------- */
/*     -       NONE           IF             ELSE*          ELSEIF*        ENDIF*         ENDFILE */
/*     -      |--------------|--------------|--------------|--------------|--------------|---------------| */
/* NONE       |Transfer line |Put on stack  |Error         |Error         |Error         |Close workfile.| */
/*            |              |              |    5         |   8          |              |Close master   | */
/*            |              |     3        |              |              |     11       | file.     13  | */
/*            |     1        |              |              |              |              |Open workfile  | */
/*            |              |              |              |              |              | as input file.| */
/*            ____________________________________________________________________________________________ */
/*            |top stack:F   |top stack:F   |Pop stack. If |Pop stack. If |Pop stack.    |Error.         | */
/* IF         | Discard lines| Discard lines|T,dscrd lns to|T,dscrd lns to|              |               | */
/*            | until level  | until level  |ENDIF@crrntlvl|ENDIF@crrntlvl|    12        |       14      | */
/*            | matches stck | mtchs stcklvl|If F,psh ELSE |If F,psh      |              |               | */
/*            | level        |else          |as T          |ELSEIF        |              |               | */
/*            |else      2   | Put on stck  |          .   |              |              |               | */
/*            | transfer line|     4        |      6       |        9     |              |               | */
/*            ____________________________________________________________________________________________ */
/* ELSE       |Same as above |Same as above |Error         |Error         |Pop stack.    |Error.         | */
/*            |              |     4        |     7        |       10     |    12        |       15      | */
/*            |     2        |              |              |              |              |               | */
/*            ____________________________________________________________________________________________ */
/* ELSEIF     |Same as above |Same as above |Same as for IF|Same as for IF|Pop stack.    |Error          | */
/*            |     2        |      4       |     6        |     9        |    12        |        16     | */
/*            ____________________________________________________________________________________________ */
/*            * Levels for these tokens should match the level for the token on the top of stack. */
/* SOURCE select.for:990 */
/*<       integeraction(0:3,0:5) >*/
/*     *****************************Formats****************************** */
/* SOURCE select.for:883 */
/*<       integer feq_len_trim >*/
/* SOURCE select.for:883 */
/*<       external feq_len_trim >*/
/* SOURCE select.for:915 */
/*<       datatrue/1/,false/0/ >*/
/* SOURCE select.for:992 */
/*<        >*/
/* SOURCE select.for:1000 */
/*<    50 format(/,' *ERR:420* Selector name=',a,' has unknown value.') >*/
/* L50: */
/* SOURCE select.for:1001 */
/*<    52  >*/
/* L52: */
/* SOURCE select.for:1003 */
/*<    54  >*/
/* L54: */
/* SOURCE select.for:1006 */
/*<    56  >*/
/* L56: */
/* SOURCE select.for:1010 */
/*<    58 format(/,' *BUG* STACK_TOKEN=',i5,' invalid on stack!') >*/
/* L58: */
/* SOURCE select.for:1011 */
/*<    60  >*/
/* L60: */
/* SOURCE select.for:1014 */
/*<   505  >*/
/* L505: */
/* SOURCE select.for:1016 */
/*<   506 format(/,' *ERR:425* Possible missing ENDIF.') >*/
/* L506: */
/* SOURCE select.for:1017 */
/*<   507 format(/,' *ERR:426* ELSE found after an ELSE.') >*/
/* L507: */
/* SOURCE select.for:1018 */
/*<   508  >*/
/* L508: */
/* SOURCE select.for:1020 */
/*<   510 format(/,' *ERR:428* ELSEIF found after matching ELSE.') >*/
/* L510: */
/* SOURCE select.for:1021 */
/*<   511  >*/
/* L511: */
/* SOURCE select.for:1023 */
/*<   514  >*/
/* L514: */
/* SOURCE select.for:1025 */
/*<   515  >*/
/* L515: */
/* SOURCE select.for:1027 */
/*<   516  >*/
/* L516: */
/* SOURCE select.for:1029 */
/*<   518  >*/
/* L518: */
/* SOURCE select.for:1031 */
/*<   520 format(/,' Line is:',a) >*/
/* L520: */
/* *********************************************************************** */
/*     Open a file for holding the new input sequence. */
/* SOURCE select.for:1035 */
/*<       stdtmp=get_unit(0) >*/
    stdtmp = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE select.for:1037 */
/*<       if(sb_home.ne.' ')then >*/
    if (s_cmp(feq_gen_sb_home_d_, const_cast<char*>(" "), sb_home_len, (ftnlen)1) != 0) {
/* SOURCE select.for:1038 */
/*<       work=sb_home >*/
	s_copy(work, feq_gen_sb_home_d_, (ftnlen)196, sb_home_len);
/* SOURCE select.for:1039 */
/*<       it=feq_len_trim(work) >*/
	it = feq_gen_feq_len_trim_d_(work, (ftnlen)196);
/* SOURCE select.for:1040 */
/*<       if(file_name(1:1).ne.'/')then >*/
	if (*(unsigned char *)feq_gen_file_name_d_ != '/') {
/* SOURCE select.for:1041 */
/*<       write(stdout,56)sb_home,file_name >*/
	    feq_gen_io_d__62.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__62);
	    do_fio(&feq_gen_c_d_1, feq_gen_sb_home_d_, sb_home_len);
	    do_fio(&feq_gen_c_d_1, feq_gen_file_name_d_, (ftnlen)128);
	    e_wsfe();
/* SOURCE select.for:1042 */
/*<       work=work(1:it)//'/'//file_name >*/
/* Writing concatenation */
	    feq_gen_i_d_1[0] = it, feq_gen_a_d_1[0] = work;
	    feq_gen_i_d_1[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("/");
	    feq_gen_i_d_1[2] = 128, feq_gen_a_d_1[2] = feq_gen_file_name_d_;
	    s_cat(work, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_3, (ftnlen)196);
/* SOURCE select.for:1043 */
/*<       else >*/
	} else {
/* SOURCE select.for:1044 */
/*<       work=work(1:it)//file_name >*/
/* Writing concatenation */
	    feq_gen_i_d_2[0] = it, feq_gen_a_d_2[0] = work;
	    feq_gen_i_d_2[1] = 128, feq_gen_a_d_2[1] = feq_gen_file_name_d_;
	    s_cat(work, feq_gen_a_d_2, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)196);
/* SOURCE select.for:1045 */
/*<       endif >*/
	}
/* SOURCE select.for:1046 */
/*<       file_name=work >*/
	s_copy(feq_gen_file_name_d_, work, (ftnlen)128, (ftnlen)196);
/* SOURCE select.for:1047 */
/*<       endif >*/
    }
/* SOURCE select.for:1049 */
/*<       callos_file_style(file_name) >*/
    feq_gen_os_file_style_d_(feq_gen_file_name_d_, (ftnlen)128);
/*     Try to prevent a disaster-overwriting the primary master-input file! */
/*     We assume that the user will be running FEQ in the directory that */
/*     contains this file.  Thus if the selector-block home name is */
/*     non-blank the fully qualified name will disagree with the value */
/*     of the command-line argument giving an unqualified primary master-input */
/*     file name.  This is not fool-proof but it should prevent most */
/*     accidents.  The means used to construct the scenario directory names */
/*     should essentially prevent a disaster. */
/* SOURCE select.for:1062 */
/*<       if(file_name.eq.fname1)then >*/
    if (s_cmp(feq_gen_file_name_d_, fname1, (ftnlen)128, (ftnlen)64) == 0) {
/*       Will write over the primary master-input file! */
/* SOURCE select.for:1064 */
/*<       write(stdout,60)file_name,fname1 >*/
	feq_gen_io_d__63.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__63);
	do_fio(&feq_gen_c_d_1, feq_gen_file_name_d_, (ftnlen)128);
	do_fio(&feq_gen_c_d_1, fname1, (ftnlen)64);
	e_wsfe();
/* SOURCE select.for:1065 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE select.for:1066 */
/*<       endif >*/
    }
/* SOURCE select.for:1067 */
/*<       open(unit=stdtmp,file=file_name,status='UNKNOWN',iostat=ioflag) >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = stdtmp;
    feq_gen_o_d_1.ofnmlen = 128;
    feq_gen_o_d_1.ofnm = feq_gen_file_name_d_;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE select.for:1068 */
/*<       if(ioflag.ne.0)then >*/
    if (ioflag != 0) {
/* SOURCE select.for:1069 */
/*<       it=feq_len_trim(file_name) >*/
	it = feq_gen_feq_len_trim_d_(feq_gen_file_name_d_, (ftnlen)128);
/* SOURCE select.for:1070 */
/*<       write(stdout,54)file_name(1:it) >*/
	feq_gen_io_d__65.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__65);
	do_fio(&feq_gen_c_d_1, feq_gen_file_name_d_, it);
	e_wsfe();
/*        WRITE(STDOUT,*) ' IOFLAG=',IOFLAG */
/* SOURCE select.for:1072 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE select.for:1073 */
/*<       endif >*/
    }
/*     Initialize the selection-processing values */
/* SOURCE select.for:1076 */
/*<       old_level=0 >*/
    feq_gen_old_level_d_ = 0;
/* SOURCE select.for:1077 */
/*<       old_token=none_token >*/
    feq_gen_old_token_d_ = 0;
/* SOURCE select.for:1078 */
/*<       callclear_select_stack() >*/
    feq_gen_clear_select_stack_d_();
/* SOURCE select.for:1080 */
/*<       inhand_token=none_token >*/
    feq_gen_inhand_token_d_ = 0;
/* SOURCE select.for:1081 */
/*<       inhand_state=true >*/
    feq_gen_inhand_state_d_ = feq_gen_true_d_;
/* SOURCE select.for:1082 */
/*<       inhand_level=old_level >*/
    feq_gen_inhand_level_d_ = feq_gen_old_level_d_;
/* SOURCE select.for:1083 */
/*<        >*/
    feq_gen_push_token_d_(&feq_gen_inhand_token_d_, &feq_gen_inhand_state_d_, &feq_gen_inhand_level_d_, const_cast<char*>("  "), &
	    feq_gen_top_pnt_d_, (ftnlen)2);
/*     Enable reading input lines to start the process. We have nothing */
/*     in hand! */
/* SOURCE select.for:1088 */
/*<       inhand=false >*/
    inhand = feq_gen_false_d_;
/*     Read the STDIN transfering to STDTMP and search for IF statements and END */
/*     statements. */
/* SOURCE select.for:1094 */
/*<  9000 continue >*/
L9000:
/* SOURCE select.for:1096 */
/*<       if(inhand.eq.false)then >*/
    if (inhand == feq_gen_false_d_) {
/*         Get next line from master input file and define the */
/*         inhand values. */
/* SOURCE select.for:1099 */
/*<       callinline_all(stdin,line) >*/
	feq_gen_inline_all_d_(stdin, line, (ftnlen)196);
/* SOURCE select.for:1103 */
/*<        >*/
	feq_gen_classify_line_d_(stdout, line, &feq_gen_old_level_d_, &feq_gen_old_token_d_, &
		feq_gen_inhand_token_d_, &feq_gen_inhand_state_d_, &feq_gen_inhand_level_d_, (ftnlen)196)
		;
/* SOURCE select.for:1106 */
/*<       endif >*/
    }
/*       Get the top of stack values. This does not pop the stack! */
/* SOURCE select.for:1109 */
/*<        >*/
    feq_gen_get_top_of_stack_d_(&feq_gen_stack_token_d_, &feq_gen_stack_state_d_, &feq_gen_stack_level_d_, 
	    feq_gen_stack_line_d_, &feq_gen_top_pnt_d_, (ftnlen)196);
/* SOURCE select.for:1111 */
/*<       len_stack_line=feq_len_trim(stack_line) >*/
    feq_gen_len_stack_line_d_ = feq_gen_feq_len_trim_d_(feq_gen_stack_line_d_, (ftnlen)196);
/*        WRITE(STDOUT,*) ' STACK_TOKEN=',STACK_TOKEN, */
/*     A                  ' INHAND_TOKEN=',INHAND_TOKEN */
/* SOURCE select.for:1115 */
/*<       if(stack_token.gt.3)then >*/
    if (feq_gen_stack_token_d_ > 3) {
/* SOURCE select.for:1116 */
/*<       write(stdout,58)stack_token >*/
	feq_gen_io_d__79.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__79);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_stack_token_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE select.for:1117 */
/*<       stop'Abnormal stop.  Bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE select.for:1118 */
/*<       endif >*/
    }
/* SOURCE select.for:1119 */
/*<       act=action(stack_token,inhand_token) >*/
    act = action[feq_gen_stack_token_d_ + (feq_gen_inhand_token_d_ << 2)];
/* SOURCE select.for:1120 */
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
    }
/* SOURCE select.for:1123 */
/*<       write(stdout,*)' BUG: INVALID INDEX FOR COMP. GOTO.' >*/
    feq_gen_io_d__81.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__81);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG: INVALID INDEX FOR COMP. GOTO."), (ftnlen)35);
    e_wsle();
/* SOURCE select.for:1124 */
/*<       write(stdout,*)' IN SUB. SCAN_MASTER_INPUT. INDEX=',act >*/
    feq_gen_io_d__82.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__82);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN SUB. SCAN_MASTER_INPUT. INDEX="), (ftnlen)34);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&act, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE select.for:1125 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE select.for:1128 */
/*<   100 continue >*/
L100:
/*         Transfer LINE */
/* SOURCE select.for:1130 */
/*<       it=feq_len_trim(line) >*/
    it = feq_gen_feq_len_trim_d_(line, (ftnlen)196);
/* SOURCE select.for:1132 */
/*<       if(it.eq.0)then >*/
    if (it == 0) {
/*           Line is blank */
/* SOURCE select.for:1134 */
/*<       write(stdtmp,'(A)')' ' >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = stdtmp;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsfe();
/* SOURCE select.for:1135 */
/*<       else >*/
    } else {
/*           Line is not blank */
/*           Check if this line is a SET on a selector variable. */
/*            write(stdout,'(a2,a)') 'x ',work(1:it) */
/* SOURCE select.for:1139 */
/*<       callfeq_adjustl(line,work) >*/
	feq_gen_feq_adjustl_d_(line, work, (ftnlen)196, (ftnlen)196);
/* SOURCE select.for:1140 */
/*<       if(work(1:4)=='SET ')then >*/
	if (s_cmp(work, const_cast<char*>("SET "), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE select.for:1141 */
/*<       callfeq_adjustl(work(5:),work) >*/
	    feq_gen_feq_adjustl_d_(work + 4, work, (ftnlen)192, (ftnlen)196);
/* SOURCE select.for:1142 */
/*<       callset_or_update_selector(stdout,stdtmp,work,flag) >*/
	    feq_gen_set_or_update_selector_d_(stdout, &stdtmp, work, &feq_gen_flag_d_, (ftnlen)
		    196);
/* SOURCE select.for:1145 */
/*<       if(flag==10)then >*/
	    if (feq_gen_flag_d_ == 10) {
/* SOURCE select.for:1146 */
/*<       write(stdout,518) >*/
		feq_gen_io_d__84.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__84);
		e_wsfe();
/* SOURCE select.for:1147 */
/*<       write(stdout,520)line >*/
		feq_gen_io_d__85.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__85);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)196);
		e_wsfe();
/* SOURCE select.for:1148 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE select.for:1149 */
/*<       endif >*/
	    }
/* SOURCE select.for:1151 */
/*<       write(stdtmp,'(a1,a)')'*',line(1:it) >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = stdtmp;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a1,a)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("*"), (ftnlen)1);
	    do_fio(&feq_gen_c_d_1, line, it);
	    e_wsfe();
/* SOURCE select.for:1152 */
/*<       else >*/
	} else {
/* SOURCE select.for:1153 */
/*<       write(stdtmp,'(A)')line(1:it) >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = stdtmp;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, line, it);
	    e_wsfe();
/* SOURCE select.for:1154 */
/*<       endif >*/
	}
/* SOURCE select.for:1155 */
/*<       endif >*/
    }
/* SOURCE select.for:1156 */
/*<       inhand=false >*/
    inhand = feq_gen_false_d_;
/* SOURCE select.for:1157 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE select.for:1159 */
/*<   200 continue >*/
L200:
/* SOURCE select.for:1160 */
/*<       if(stack_state.eq.false)then >*/
    if (feq_gen_stack_state_d_ == feq_gen_false_d_) {
/*           Discard lines until we find a keyword whose level */
/*           matches the level of the token on the top of stack. */
/* SOURCE select.for:1163 */
/*<        >*/
	feq_gen_discard_lines_d_(stdin, stdout, &feq_gen_stack_level_d_, &feq_gen_old_level_d_, &
		feq_gen_old_token_d_, &feq_gen_inhand_token_d_, &feq_gen_inhand_state_d_, &
		feq_gen_inhand_level_d_);
/* SOURCE select.for:1167 */
/*<       inhand=true >*/
	inhand = feq_gen_true_d_;
/* SOURCE select.for:1168 */
/*<       else >*/
    } else {
/*           Transfer LINE */
/* SOURCE select.for:1170 */
/*<       it=feq_len_trim(line) >*/
	it = feq_gen_feq_len_trim_d_(line, (ftnlen)196);
/* SOURCE select.for:1172 */
/*<       if(it.eq.0)then >*/
	if (it == 0) {
/*             Line is blank */
/* SOURCE select.for:1174 */
/*<       write(stdtmp,'(A)')' ' >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = stdtmp;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsfe();
/* SOURCE select.for:1175 */
/*<       else >*/
	} else {
/*             Line is not blank */
/*             Check if this line is a SET on a selector variable. */
/* SOURCE select.for:1178 */
/*<       callfeq_adjustl(line,work) >*/
	    feq_gen_feq_adjustl_d_(line, work, (ftnlen)196, (ftnlen)196);
/*            write(stdout,'(a2,a)') 'y ',work */
/* SOURCE select.for:1180 */
/*<       if(work(1:4)=='SET ')then >*/
	    if (s_cmp(work, const_cast<char*>("SET "), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE select.for:1181 */
/*<       callfeq_adjustl(work(5:),work) >*/
		feq_gen_feq_adjustl_d_(work + 4, work, (ftnlen)192, (ftnlen)196);
/* SOURCE select.for:1182 */
/*<       callset_or_update_selector(stdout,stdtmp,work,flag) >*/
		feq_gen_set_or_update_selector_d_(stdout, &stdtmp, work, &feq_gen_flag_d_, (
			ftnlen)196);
/* SOURCE select.for:1185 */
/*<       if(flag==10)then >*/
		if (feq_gen_flag_d_ == 10) {
/* SOURCE select.for:1186 */
/*<       write(stdout,518) >*/
		    feq_gen_io_d__86.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__86);
		    e_wsfe();
/* SOURCE select.for:1187 */
/*<       write(stdout,520)line >*/
		    feq_gen_io_d__87.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__87);
		    do_fio(&feq_gen_c_d_1, line, (ftnlen)196);
		    e_wsfe();
/* SOURCE select.for:1188 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE select.for:1189 */
/*<       endif >*/
		}
/* SOURCE select.for:1191 */
/*<       write(stdtmp,'(a1,a)')'*',line(1:it) >*/
		feq_gen_ci_d_1.cierr = 0;
		feq_gen_ci_d_1.ciunit = stdtmp;
		feq_gen_ci_d_1.cifmt = const_cast<char*>("(a1,a)");
		s_wsfe(&feq_gen_ci_d_1);
		do_fio(&feq_gen_c_d_1, const_cast<char*>("*"), (ftnlen)1);
		do_fio(&feq_gen_c_d_1, line, it);
		e_wsfe();
/* SOURCE select.for:1192 */
/*<       else >*/
	    } else {
/* SOURCE select.for:1193 */
/*<       write(stdtmp,'(A)')line(1:it) >*/
		feq_gen_ci_d_1.cierr = 0;
		feq_gen_ci_d_1.ciunit = stdtmp;
		feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
		s_wsfe(&feq_gen_ci_d_1);
		do_fio(&feq_gen_c_d_1, line, it);
		e_wsfe();
/* SOURCE select.for:1194 */
/*<       endif >*/
	    }
/* SOURCE select.for:1195 */
/*<       endif >*/
	}
/* SOURCE select.for:1196 */
/*<       inhand=false >*/
	inhand = feq_gen_false_d_;
/* SOURCE select.for:1197 */
/*<       endif >*/
    }
/* SOURCE select.for:1198 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE select.for:1200 */
/*<   300 continue >*/
L300:
/*         Push in-hand values onto the stack. */
/* SOURCE select.for:1202 */
/*<        >*/
    feq_gen_push_token_d_(&feq_gen_inhand_token_d_, &feq_gen_inhand_state_d_, &feq_gen_inhand_level_d_, line, &
	    feq_gen_top_pnt_d_, (ftnlen)196);
/* SOURCE select.for:1204 */
/*<       inhand=false >*/
    inhand = feq_gen_false_d_;
/* SOURCE select.for:1205 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE select.for:1207 */
/*<   400 continue >*/
L400:
/* SOURCE select.for:1208 */
/*<       if(stack_state.eq.false)then >*/
    if (feq_gen_stack_state_d_ == feq_gen_false_d_) {
/*           Discard lines until we find a keyword whose level */
/*           matches the level of the token on the top of stack. */
/* SOURCE select.for:1211 */
/*<        >*/
	feq_gen_discard_lines_d_(stdin, stdout, &feq_gen_stack_level_d_, &feq_gen_old_level_d_, &
		feq_gen_old_token_d_, &feq_gen_inhand_token_d_, &feq_gen_inhand_state_d_, &
		feq_gen_inhand_level_d_);
/* SOURCE select.for:1215 */
/*<       inhand=true >*/
	inhand = feq_gen_true_d_;
/* SOURCE select.for:1216 */
/*<       else >*/
    } else {
/*           Push in-hand values onto the stack. */
/* SOURCE select.for:1218 */
/*<        >*/
	feq_gen_push_token_d_(&feq_gen_inhand_token_d_, &feq_gen_inhand_state_d_, &feq_gen_inhand_level_d_, line, 
		&feq_gen_top_pnt_d_, (ftnlen)196);
/* SOURCE select.for:1221 */
/*<       inhand=false >*/
	inhand = feq_gen_false_d_;
/* SOURCE select.for:1222 */
/*<       endif >*/
    }
/* SOURCE select.for:1223 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE select.for:1225 */
/*<   500 continue >*/
L500:
/*         Error- ELSE found but no matching IF or ELSEIF */
/* SOURCE select.for:1227 */
/*<       write(stdout,505) >*/
    feq_gen_io_d__88.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__88);
    e_wsfe();
/* SOURCE select.for:1228 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
    feq_gen_io_d__89.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__89);
    do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
    e_wsfe();
/* SOURCE select.for:1229 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1231 */
/*<   600 continue >*/
L600:
/*         process an in-hand ELSE with a matching IF or ELSEIF */
/* SOURCE select.for:1233 */
/*<       callpop_token(stack_token,stack_state,stack_level,line,top_pnt) >*/
    feq_gen_pop_token_d_(&feq_gen_stack_token_d_, &feq_gen_stack_state_d_, &feq_gen_stack_level_d_, line, &
	    feq_gen_top_pnt_d_, (ftnlen)196);
/* SOURCE select.for:1236 */
/*<       if(stack_level.ne.inhand_level)then >*/
    if (feq_gen_stack_level_d_ != feq_gen_inhand_level_d_) {
/*           Possible user error. */
/* SOURCE select.for:1238 */
/*<       write(stdout,506) >*/
	feq_gen_io_d__90.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__90);
	e_wsfe();
/* SOURCE select.for:1239 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
	feq_gen_io_d__91.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__91);
	do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
	e_wsfe();
/* SOURCE select.for:1240 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1241 */
/*<       endif >*/
    }
/*         If the just popped token was true, then we need to discard lines */
/*         until we find an ENDIF whose level matches the just popped value. */
/* SOURCE select.for:1245 */
/*<       if(stack_state.eq.true)then >*/
    if (feq_gen_stack_state_d_ == feq_gen_true_d_) {
/* SOURCE select.for:1246 */
/*<        >*/
	feq_gen_discard_lines_to_endif_d_(stdin, stdout, &feq_gen_stack_level_d_, &feq_gen_old_level_d_, 
		&feq_gen_old_token_d_, &feq_gen_discard_token_d_, &feq_gen_discard_state_d_, &
		feq_gen_discard_level_d_);
/* SOURCE select.for:1250 */
/*<       else >*/
    } else {
/* SOURCE select.for:1251 */
/*<       inhand_state=true >*/
	feq_gen_inhand_state_d_ = feq_gen_true_d_;
/* SOURCE select.for:1252 */
/*<        >*/
	feq_gen_push_token_d_(&feq_gen_inhand_token_d_, &feq_gen_inhand_state_d_, &feq_gen_inhand_level_d_, line, 
		&feq_gen_top_pnt_d_, (ftnlen)196);
/* SOURCE select.for:1255 */
/*<       endif >*/
    }
/* SOURCE select.for:1256 */
/*<       inhand=false >*/
    inhand = feq_gen_false_d_;
/* SOURCE select.for:1257 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE select.for:1259 */
/*<   700 continue >*/
L700:
/*         Error- ELSE found  after a matching ELSE */
/* SOURCE select.for:1261 */
/*<       write(stdout,507) >*/
    feq_gen_io_d__95.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__95);
    e_wsfe();
/* SOURCE select.for:1262 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
    feq_gen_io_d__96.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__96);
    do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
    e_wsfe();
/* SOURCE select.for:1263 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1265 */
/*<   800 continue >*/
L800:
/*         Error- ELSEIF found with no preceding IF or ELSEIF */
/* SOURCE select.for:1267 */
/*<       write(stdout,508) >*/
    feq_gen_io_d__97.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__97);
    e_wsfe();
/* SOURCE select.for:1268 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
    feq_gen_io_d__98.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__98);
    do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
    e_wsfe();
/* SOURCE select.for:1269 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1271 */
/*<   900 continue >*/
L900:
/*         Process an ELSEIF with a matching IF or ELSEIF */
/* SOURCE select.for:1273 */
/*<       callpop_token(stack_token,stack_state,stack_level,line,top_pnt) >*/
    feq_gen_pop_token_d_(&feq_gen_stack_token_d_, &feq_gen_stack_state_d_, &feq_gen_stack_level_d_, line, &
	    feq_gen_top_pnt_d_, (ftnlen)196);
/* SOURCE select.for:1276 */
/*<       if(stack_level.ne.inhand_level)then >*/
    if (feq_gen_stack_level_d_ != feq_gen_inhand_level_d_) {
/*           Possible user error. */
/* SOURCE select.for:1278 */
/*<       write(stdout,506) >*/
	feq_gen_io_d__99.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__99);
	e_wsfe();
/* SOURCE select.for:1279 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
	feq_gen_io_d__100.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__100);
	do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
	e_wsfe();
/* SOURCE select.for:1280 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1281 */
/*<       endif >*/
    }
/*         If the stack state is true, discard lines until we find */
/*         an ENDIF at the stack level. */
/* SOURCE select.for:1284 */
/*<       if(stack_state.eq.true)then >*/
    if (feq_gen_stack_state_d_ == feq_gen_true_d_) {
/* SOURCE select.for:1285 */
/*<        >*/
	feq_gen_discard_lines_to_endif_d_(stdin, stdout, &feq_gen_stack_level_d_, &feq_gen_old_level_d_, 
		&feq_gen_old_token_d_, &feq_gen_discard_token_d_, &feq_gen_discard_state_d_, &
		feq_gen_discard_level_d_);
/* SOURCE select.for:1289 */
/*<       else >*/
    } else {
/* SOURCE select.for:1290 */
/*<        >*/
	feq_gen_push_token_d_(&feq_gen_inhand_token_d_, &feq_gen_inhand_state_d_, &feq_gen_inhand_level_d_, line, 
		&feq_gen_top_pnt_d_, (ftnlen)196);
/* SOURCE select.for:1293 */
/*<       endif >*/
    }
/* SOURCE select.for:1294 */
/*<       inhand=false >*/
    inhand = feq_gen_false_d_;
/* SOURCE select.for:1295 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE select.for:1297 */
/*<  1000 continue >*/
L1000:
/*         Error- ELSEIF after matching ELSE */
/* SOURCE select.for:1299 */
/*<       write(stdout,510) >*/
    feq_gen_io_d__101.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__101);
    e_wsfe();
/* SOURCE select.for:1300 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
    feq_gen_io_d__102.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__102);
    do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
    e_wsfe();
/* SOURCE select.for:1301 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1304 */
/*<  1100 continue >*/
L1100:
/*         Error-ENDIF found but no matching statement exists */
/* SOURCE select.for:1306 */
/*<       write(stdout,511) >*/
    feq_gen_io_d__103.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__103);
    e_wsfe();
/* SOURCE select.for:1307 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
    feq_gen_io_d__104.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__104);
    do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
    e_wsfe();
/* SOURCE select.for:1308 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1310 */
/*<  1200 continue >*/
L1200:
/*         Process an ENDIF with a matching IF, ELSE, or ELSEIF */
/* SOURCE select.for:1312 */
/*<       callpop_token(stack_token,stack_state,stack_level,line,top_pnt) >*/
    feq_gen_pop_token_d_(&feq_gen_stack_token_d_, &feq_gen_stack_state_d_, &feq_gen_stack_level_d_, line, &
	    feq_gen_top_pnt_d_, (ftnlen)196);
/* SOURCE select.for:1315 */
/*<       if(stack_level.ne.inhand_level)then >*/
    if (feq_gen_stack_level_d_ != feq_gen_inhand_level_d_) {
/*           Possible user error. */
/* SOURCE select.for:1317 */
/*<       write(stdout,506) >*/
	feq_gen_io_d__105.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__105);
	e_wsfe();
/* SOURCE select.for:1318 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
	feq_gen_io_d__106.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__106);
	do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
	e_wsfe();
/* SOURCE select.for:1319 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1320 */
/*<       endif >*/
    }
/* SOURCE select.for:1321 */
/*<       inhand=false >*/
    inhand = feq_gen_false_d_;
/* SOURCE select.for:1322 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE select.for:1324 */
/*<  1300 continue >*/
L1300:
/*         Process the ENDFILE. */
/*         Master file has been processed. */
/* SOURCE select.for:1327 */
/*<       close(stdtmp) >*/
    feq_gen_cl_d_1.cerr = 0;
    feq_gen_cl_d_1.cunit = stdtmp;
    feq_gen_cl_d_1.csta = 0;
    f_clos(&feq_gen_cl_d_1);
/* SOURCE select.for:1328 */
/*<       close(stdin) >*/
    feq_gen_cl_d_1.cerr = 0;
    feq_gen_cl_d_1.cunit = *stdin;
    feq_gen_cl_d_1.csta = 0;
    f_clos(&feq_gen_cl_d_1);
/* SOURCE select.for:1329 */
/*<       open(unit=stdin,file=file_name,status='OLD') >*/
    feq_gen_o_d_1.oerr = 0;
    feq_gen_o_d_1.ounit = *stdin;
    feq_gen_o_d_1.ofnmlen = 128;
    feq_gen_o_d_1.ofnm = feq_gen_file_name_d_;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    f_open(&feq_gen_o_d_1);
/* SOURCE select.for:1331 */
/*<       goto10000 >*/
    goto L10000;
/* SOURCE select.for:1333 */
/*<  1400 continue >*/
L1400:
/*         Error-End of Master input file found before ENDIF for */
/*               IF was found. */
/* SOURCE select.for:1336 */
/*<       write(stdout,514) >*/
    feq_gen_io_d__107.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__107);
    e_wsfe();
/* SOURCE select.for:1337 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
    feq_gen_io_d__108.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__108);
    do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
    e_wsfe();
/* SOURCE select.for:1338 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1340 */
/*<  1500 continue >*/
L1500:
/*         Error-End of Master input file found before ENDIF for */
/*               ELSE was found. */
/* SOURCE select.for:1343 */
/*<       write(stdout,515) >*/
    feq_gen_io_d__109.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__109);
    e_wsfe();
/* SOURCE select.for:1344 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
    feq_gen_io_d__110.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__110);
    do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
    e_wsfe();
/* SOURCE select.for:1345 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1347 */
/*<  1600 continue >*/
L1600:
/*         Error-End of Master input file found before ENDIF for */
/*               ELSEIF was found. */
/* SOURCE select.for:1350 */
/*<       write(stdout,516) >*/
    feq_gen_io_d__111.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__111);
    e_wsfe();
/* SOURCE select.for:1351 */
/*<       write(stdout,520)stack_line(1:len_stack_line) >*/
    feq_gen_io_d__112.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__112);
    do_fio(&feq_gen_c_d_1, feq_gen_stack_line_d_, feq_gen_len_stack_line_d_);
    e_wsfe();
/* SOURCE select.for:1352 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE select.for:1354 */
/*<  9999 continue >*/
L9999:
/* SOURCE select.for:1355 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE select.for:1357 */
/*< 10000 continue >*/
L10000:
/* SOURCE select.for:1358 */
/*<       return >*/
    return 0;
/* SOURCE select.for:1359 */
/*<       end >*/
} /* scan_master_input__ */

#ifdef __cplusplus
	}
#endif
