#include "../support/format.hpp"
/* fqshrstr.f -- translated by f2c (version 20240504).
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

/* COMMON whatos_ is declared in common.hpp. */

#define whatos_1 whatos_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;




/* SOURCE fqshrstr.for:4 */
/*<       subroutineos_file_style(string) >*/
/* Subroutine */ int feq_gen_os_file_style_d_(char *string, ftnlen string_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, n;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Convert a character string that is supposed to contain a file-name */
/*     to the style of the osflag.  There are currently two styles: */
/*     MS, and LINUX.  If neither style is given, then string is */
/*     unchanged. */
/* SOURCE fqshrstr.for:12 */
/*<       implicitnone >*/
/* SOURCE fqshrstr.for:13 */
/*<       character*(*)string >*/
/* INCLUDE fqshrstr.for:15 */
/*     Common to pass the os flag */
/* SOURCE whatos.cmn:3 */
/*<       integerosis >*/
/* SOURCE whatos.cmn:4 */
/*<       common/whatos/osis >*/
/* SOURCE whatos.cmn:6 */
/*<       save/whatos/ >*/
/* SOURCE fqshrstr.for:17 */
/*<       integerlen_trim >*/
/*     Local */
/* SOURCE fqshrstr.for:21 */
/*<       integeri,n >*/
/* SOURCE fqshrstr.for:23 */
/*<       integerms,linux >*/
/* SOURCE fqshrstr.for:24 */
/*<       parameter(ms=1,linux=2) >*/
/* *********************************************************************** */
/* SOURCE fqshrstr.for:4 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrstr.for:4 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrstr.for:26 */
/*<       n=feq_len_trim(string) >*/
    n = feq_gen_feq_len_trim_d_(string, string_len);
/* SOURCE fqshrstr.for:27 */
/*<       if(osis==ms)then >*/
    if (whatos_1.osis == 1) {
/*       Search for forward slashes and convert any found to the */
/*       backward slash. */
/* SOURCE fqshrstr.for:30 */
/*<       doi=1,n >*/
	feq_gen_i_d_1 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrstr.for:31 */
/*<       if(string(i:i)=='/')then >*/
	    if (*(unsigned char *)&string[feq_gen_i_d_ - 1] == '/') {
/* SOURCE fqshrstr.for:32 */
/*<       string(i:i)='\' >*/
		*(unsigned char *)&string[feq_gen_i_d_ - 1] = '\\';
/* SOURCE fqshrstr.for:33 */
/*<       endif >*/
	    }
/* SOURCE fqshrstr.for:34 */
/*<       enddo >*/
	}
/* SOURCE fqshrstr.for:35 */
/*<       elseif(osis==linux)then >*/
    } else if (whatos_1.osis == 2) {
/*       Search for backward slahes and convert any found to the */
/*       forward slash. */
/* SOURCE fqshrstr.for:38 */
/*<       doi=1,n >*/
	feq_gen_i_d_1 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrstr.for:39 */
/*<       if(string(i:i)=='\')then >*/
	    if (*(unsigned char *)&string[feq_gen_i_d_ - 1] == '\\') {
/* SOURCE fqshrstr.for:40 */
/*<       string(i:i)='/' >*/
		*(unsigned char *)&string[feq_gen_i_d_ - 1] = '/';
/* SOURCE fqshrstr.for:41 */
/*<       endif >*/
	    }
/* SOURCE fqshrstr.for:42 */
/*<       enddo >*/
	}
/* SOURCE fqshrstr.for:43 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:44 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:45 */
/*<       end >*/
} /* os_file_style__ */

/*     *********** */
/*     *         * */
/*     * CHAR_TO_DP */
/*     *         * */
/*     *********** */
/* SOURCE fqshrstr.for:53 */
/*<       real*8functionchar_to_dp(char_argument) >*/
doublereal feq_gen_char_to_dp_d_(char *feq_gen_char_argument_d_, ftnlen char_argument_len)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal tp;
    char tpc[8];
    extern doublereal feq_gen_feq_transfer_cd_d_(char *, ftnlen);

/*     Transfer a character string that is 8 characters long */
/*     into a 8-byte floating point variable WITHOUT any */
/*     data conversion. */
/* SOURCE fqshrstr.for:59 */
/*<       implicitnone >*/
/* SOURCE fqshrstr.for:60 */
/*<       character*8char_argument >*/
/*     Local */
/* SOURCE fqshrstr.for:64 */
/*<       real*8tp >*/
/* SOURCE fqshrstr.for:65 */
/*<       character*8tpc >*/
/* *********************************************************************** */
/*      READ(CHAR_ARGUMENT,'(A8)')  TP */
/* SOURCE fqshrstr.for:53 */
/*<       real*8 feq_transfer_cd >*/
/* SOURCE fqshrstr.for:53 */
/*<       external feq_transfer_cd >*/
/* SOURCE fqshrstr.for:69 */
/*<       tpc=char_argument >*/
    s_copy(tpc, feq_gen_char_argument_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrstr.for:70 */
/*<       tp=feq_transfer_cd(tpc) >*/
    tp = feq_gen_feq_transfer_cd_d_(tpc, (ftnlen)8);
/* SOURCE fqshrstr.for:71 */
/*<       char_to_dp=tp >*/
    ret_val = tp;
/* SOURCE fqshrstr.for:73 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrstr.for:74 */
/*<       end >*/
} /* char_to_dp__ */

/*     *********** */
/*     *         * */
/*     * DP_TO_CHAR */
/*     *         * */
/*     *********** */
/* SOURCE fqshrstr.for:81 */
/*<       character*8functiondp_to_char(dp_argument) >*/
/* Character */ VOID feq_gen_dp_to_char_d_(char *ret_val, ftnlen ret_val_len, 
	doublereal *feq_gen_dp_argument_d_)
{
    /* System generated locals */
    char feq_gen_ch_d_2[8];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char tp[8];
    extern /* Character */ VOID feq_gen_feq_transfer_dc_d_(char *, ftnlen, doublereal *
	    );

/*     Transfer the characters placed in the DP_ARGUMENT */
/*     by the function CHAR_TO_DP to a character string. */
/* SOURCE fqshrstr.for:86 */
/*<       implicitnone >*/
/* SOURCE fqshrstr.for:88 */
/*<       real*8dp_argument >*/
/*     Local */
/* SOURCE fqshrstr.for:92 */
/*<       character*8tp >*/
/* *********************************************************************** */
/*      WRITE(TP,'(A8)')  DP_ARGUMENT */
/* SOURCE fqshrstr.for:81 */
/*<       character*8 feq_transfer_dc >*/
/* SOURCE fqshrstr.for:81 */
/*<       external feq_transfer_dc >*/
/* SOURCE fqshrstr.for:95 */
/*<       tp=feq_transfer_dc(dp_argument) >*/
    feq_gen_feq_transfer_dc_d_(feq_gen_ch_d_2, (ftnlen)8, feq_gen_dp_argument_d_);
    s_copy(tp, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrstr.for:96 */
/*<       dp_to_char=tp >*/
    s_copy(ret_val, tp, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrstr.for:98 */
/*<       return >*/
    return ;
/* SOURCE fqshrstr.for:99 */
/*<       end >*/
} /* dp_to_char__ */

/*     *********** */
/*     *         * */
/*     * VAR_DECIMAL */
/*     *         * */
/*     *********** */
/* SOURCE fqshrstr.for:108 */
/*<       subroutinevar_decimal(value,result) >*/
/* Subroutine */ int feq_gen_var_decimal_d_(real *value, char *result, ftnlen 
	result_len)
{
    /* Initialized data */

    static char feq_gen_rout_format_d_[8+1] = "(F  .  )";
    static char feq_gen_iout_format_d_[5+1] = "(I  )";

    /* System generated locals */
    real feq_gen_r_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer i_len(char *, ftnlen), s_wsfi(icilist *), do_fio(integer *, char *
	    , ftnlen), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double r_lg10(real *);

    /* Local variables */
    integer feq_gen_number_of_decimal_places_d_, feq_gen_d_d_;
    real y;
    integer it, feq_gen_max_decimal_places_d_, feq_gen_field_width_d_;
    char char2[2];

/*     Convert VALUE to a number and output it in RESULT so as */
/*     to get a good use of the columns for precision of output. */
/* SOURCE fqshrstr.for:114 */
/*<       implicitnone >*/
/* SOURCE fqshrstr.for:115 */
/*<       character*(*)result >*/
/* SOURCE fqshrstr.for:117 */
/*<       realvalue >*/
/*     Local */
/* SOURCE fqshrstr.for:121 */
/*<        >*/
/* SOURCE fqshrstr.for:124 */
/*<       realy >*/
/* SOURCE fqshrstr.for:126 */
/*<       characterrout_format*8,iout_format*5,char2*2 >*/
/* SOURCE fqshrstr.for:128 */
/*<       intrinsiclog10,abs >*/
/*                       12345678                 12345 */
/* *********************************************************************** */
/* SOURCE fqshrstr.for:131 */
/*<       datarout_format/'(F  .  )'/,iout_format/'(I  )'/ >*/
/* SOURCE fqshrstr.for:134 */
/*<       field_width=len(result) >*/
    feq_gen_field_width_d_ = i_len(result, result_len);
/* SOURCE fqshrstr.for:135 */
/*<       if(field_width.gt.20)field_width=20 >*/
    if (feq_gen_field_width_d_ > 20) {
	feq_gen_field_width_d_ = 20;
    }
/* SOURCE fqshrstr.for:136 */
/*<       max_decimal_places=field_width-3 >*/
    feq_gen_max_decimal_places_d_ = feq_gen_field_width_d_ - 3;
/* SOURCE fqshrstr.for:137 */
/*<       write(char2,'(I2)')field_width >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 2;
    feq_gen_ici_d_1.iciunit = char2;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_field_width_d_, (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE fqshrstr.for:138 */
/*<       rout_format(3:4)=char2 >*/
    s_copy(feq_gen_rout_format_d_ + 2, char2, (ftnlen)2, (ftnlen)2);
/* SOURCE fqshrstr.for:139 */
/*<       iout_format(3:4)=char2 >*/
    s_copy(feq_gen_iout_format_d_ + 2, char2, (ftnlen)2, (ftnlen)2);
/* SOURCE fqshrstr.for:140 */
/*<       if(value.ne.0.0)then >*/
    if (*value != (float)0.) {
/* SOURCE fqshrstr.for:141 */
/*<       y=log10(abs(value)) >*/
	feq_gen_r_d_1 = dabs(*value);
	y = r_lg10(&feq_gen_r_d_1);
/* SOURCE fqshrstr.for:142 */
/*<       if(y.lt.0.0)y=0.0 >*/
	if (y < (float)0.) {
	    y = (float)0.;
	}
/* SOURCE fqshrstr.for:143 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:144 */
/*<       y=0.0 >*/
	y = (float)0.;
/* SOURCE fqshrstr.for:145 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:147 */
/*<       d=int(y)+3 >*/
    feq_gen_d_d_ = (integer) y + 3;
/* SOURCE fqshrstr.for:148 */
/*<       if(d.lt.field_width)then >*/
    if (feq_gen_d_d_ < feq_gen_field_width_d_) {
/* SOURCE fqshrstr.for:150 */
/*<       number_of_decimal_places=field_width-d >*/
	feq_gen_number_of_decimal_places_d_ = feq_gen_field_width_d_ - feq_gen_d_d_;
/* SOURCE fqshrstr.for:152 */
/*<        >*/
	if (feq_gen_number_of_decimal_places_d_ > feq_gen_max_decimal_places_d_) {
	    feq_gen_number_of_decimal_places_d_ = feq_gen_max_decimal_places_d_;
	}
/* SOURCE fqshrstr.for:154 */
/*<       write(rout_format(6:7),'(I2)')number_of_decimal_places >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 2;
	feq_gen_ici_d_1.iciunit = feq_gen_rout_format_d_ + 5;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_number_of_decimal_places_d_, (ftnlen)sizeof(
		integer));
	e_wsfi();
/* SOURCE fqshrstr.for:156 */
/*<       write(result,rout_format)value >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = result_len;
	feq_gen_ici_d_1.iciunit = result;
	feq_gen_ici_d_1.icifmt = feq::format_text(feq_gen_rout_format_d_, sizeof(feq_gen_rout_format_d_));
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&(*value), (ftnlen)sizeof(real));
	e_wsfi();
/* SOURCE fqshrstr.for:157 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:158 */
/*<       it=abs(value)+0.5 >*/
	it = dabs(*value) + (float).5;
/* SOURCE fqshrstr.for:159 */
/*<       if(value.lt.0.0)it=-it >*/
	if (*value < (float)0.) {
	    it = -it;
	}
/* SOURCE fqshrstr.for:160 */
/*<       write(result,iout_format)it >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = result_len;
	feq_gen_ici_d_1.iciunit = result;
	feq_gen_ici_d_1.icifmt = feq::format_text(feq_gen_iout_format_d_, sizeof(feq_gen_iout_format_d_));
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE fqshrstr.for:161 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:163 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:164 */
/*<       end >*/
} /* var_decimal__ */

/*     *********** */
/*     *         * */
/*     * VAR_DECIMALD */
/*     *         * */
/*     *********** */
/* SOURCE fqshrstr.for:171 */
/*<       subroutinevar_decimald(value,result) >*/
/* Subroutine */ int feq_gen_var_decimald_d_(doublereal *value, char *result, ftnlen 
	result_len)
{
    /* Initialized data */

    static char feq_gen_rout_format_d_[7+1] = "(F  . )";
    static char feq_gen_iout_format_d_[5+1] = "(I  )";

    /* System generated locals */
    doublereal feq_gen_d_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer i_len(char *, ftnlen), s_wsfi(icilist *), do_fio(integer *, char *
	    , ftnlen), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double d_lg10(doublereal *);

    /* Local variables */
    integer feq_gen_number_of_decimal_places_d_, feq_gen_d_d_;
    doublereal y;
    integer it, feq_gen_field_width_d_;
    char char2[2];

/*     Convert VALUE to a number and output it in RESULT so as */
/*     to get a good use of the columns for precision of output. */
/* SOURCE fqshrstr.for:177 */
/*<       implicitnone >*/
/* SOURCE fqshrstr.for:178 */
/*<       character*(*)result >*/
/* SOURCE fqshrstr.for:180 */
/*<       real*8value >*/
/*     Local */
/* SOURCE fqshrstr.for:184 */
/*<       integerfield_width,number_of_decimal_places,d,it >*/
/* SOURCE fqshrstr.for:187 */
/*<       real*8y >*/
/* SOURCE fqshrstr.for:189 */
/*<       characterrout_format*7,iout_format*5,char2*2 >*/
/* SOURCE fqshrstr.for:191 */
/*<       intrinsiclog10,abs >*/
/* *********************************************************************** */
/* SOURCE fqshrstr.for:193 */
/*<       datarout_format/'(F  . )'/,iout_format/'(I  )'/ >*/
/* SOURCE fqshrstr.for:196 */
/*<       field_width=len(result) >*/
    feq_gen_field_width_d_ = i_len(result, result_len);
/* SOURCE fqshrstr.for:197 */
/*<       if(field_width.gt.20)field_width=20 >*/
    if (feq_gen_field_width_d_ > 20) {
	feq_gen_field_width_d_ = 20;
    }
/* SOURCE fqshrstr.for:198 */
/*<       write(char2,'(I2)')field_width >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 2;
    feq_gen_ici_d_1.iciunit = char2;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_field_width_d_, (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE fqshrstr.for:199 */
/*<       rout_format(3:4)=char2 >*/
    s_copy(feq_gen_rout_format_d_ + 2, char2, (ftnlen)2, (ftnlen)2);
/* SOURCE fqshrstr.for:200 */
/*<       iout_format(3:4)=char2 >*/
    s_copy(feq_gen_iout_format_d_ + 2, char2, (ftnlen)2, (ftnlen)2);
/* SOURCE fqshrstr.for:201 */
/*<       if(value.ne.0.0)then >*/
    if (*value != (float)0.) {
/* SOURCE fqshrstr.for:202 */
/*<       y=log10(abs(value)) >*/
	feq_gen_d_d_1 = abs(*value);
	y = d_lg10(&feq_gen_d_d_1);
/* SOURCE fqshrstr.for:203 */
/*<       if(y.lt.0.d0)y=0.0 >*/
	if (y < 0.) {
	    y = (float)0.;
	}
/* SOURCE fqshrstr.for:204 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:205 */
/*<       y=0.d0 >*/
	y = 0.;
/* SOURCE fqshrstr.for:206 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:208 */
/*<       d=int(y)+3 >*/
    feq_gen_d_d_ = (integer) y + 3;
/* SOURCE fqshrstr.for:209 */
/*<       if(d.lt.field_width)then >*/
    if (feq_gen_d_d_ < feq_gen_field_width_d_) {
/* SOURCE fqshrstr.for:211 */
/*<       number_of_decimal_places=field_width-d >*/
	feq_gen_number_of_decimal_places_d_ = feq_gen_field_width_d_ - feq_gen_d_d_;
/* SOURCE fqshrstr.for:212 */
/*<       if(number_of_decimal_places.gt.7)number_of_decimal_places=7 >*/
	if (feq_gen_number_of_decimal_places_d_ > 7) {
	    feq_gen_number_of_decimal_places_d_ = 7;
	}
/* SOURCE fqshrstr.for:213 */
/*<       write(rout_format(6:6),'(I1)')number_of_decimal_places >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 1;
	feq_gen_ici_d_1.iciunit = feq_gen_rout_format_d_ + 5;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I1)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_number_of_decimal_places_d_, (ftnlen)sizeof(
		integer));
	e_wsfi();
/* SOURCE fqshrstr.for:215 */
/*<       write(result,rout_format)value >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = result_len;
	feq_gen_ici_d_1.iciunit = result;
	feq_gen_ici_d_1.icifmt = feq::format_text(feq_gen_rout_format_d_, sizeof(feq_gen_rout_format_d_));
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&(*value), (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE fqshrstr.for:216 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:217 */
/*<       it=abs(value)+0.5 >*/
	it = (integer) (abs(*value) + (float).5);
/* SOURCE fqshrstr.for:218 */
/*<       if(value.lt.0.0)it=-it >*/
	if (*value < (float)0.) {
	    it = -it;
	}
/* SOURCE fqshrstr.for:219 */
/*<       write(result,iout_format)it >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = result_len;
	feq_gen_ici_d_1.iciunit = result;
	feq_gen_ici_d_1.icifmt = feq::format_text(feq_gen_iout_format_d_, sizeof(feq_gen_iout_format_d_));
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE fqshrstr.for:220 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:222 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:223 */
/*<       end >*/
} /* var_decimald__ */




/* SOURCE fqshrstr.for:227 */
/*<       subroutinegetnxt(name,is,ie,nxtstr) >*/
/* Subroutine */ int getnxt_(char *feq_gen_name_d_, integer *is, integer *ie, char *
	nxtstr, ftnlen name_len, ftnlen nxtstr_len)
{
    /* Builtin functions */
    integer i_len(char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, iend, istop, istart;

/*     + + + PURPOSE + + + */
/*     Get the next consecutive sequence of non-blank characters from */
/*     NAME, starting at character position IS, and return the */
/*     substring together with the index of the next character in */
/*     NAME at which to start the next search. */
/* SOURCE fqshrstr.for:237 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrstr.for:239 */
/*<       integerie,is >*/
/* SOURCE fqshrstr.for:240 */
/*<       charactername*(*),nxtstr*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NAME   - string being scanned */
/*     IS     - character position for starting scan */
/*     IE     - next character position after current scan */
/*     NXTSTR - the next string found */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrstr.for:249 */
/*<       integeri,iend,istart,istop >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrstr.for:252 */
/*<       intrinsiclen >*/
/* *********************************************************************** */
/* SOURCE fqshrstr.for:254 */
/*<       i=is >*/
    feq_gen_i_d_ = *is;
/* SOURCE fqshrstr.for:255 */
/*<       iend=len(name) >*/
    iend = i_len(feq_gen_name_d_, name_len);
/* SOURCE fqshrstr.for:257 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrstr.for:258 */
/*<       if(name(i:i).eq.' ')then >*/
    if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] == ' ') {
/* SOURCE fqshrstr.for:259 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE fqshrstr.for:260 */
/*<       if(i.le.iend)then >*/
	if (feq_gen_i_d_ <= iend) {
/* SOURCE fqshrstr.for:261 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE fqshrstr.for:262 */
/*<       else >*/
	} else {
/*           RETURN A BLANK IF NO NON-BLANK FOUND */
/* SOURCE fqshrstr.for:264 */
/*<       nxtstr=' ' >*/
	    s_copy(nxtstr, const_cast<char*>(" "), nxtstr_len, (ftnlen)1);
/* SOURCE fqshrstr.for:265 */
/*<       ie=iend >*/
	    *ie = iend;
/* SOURCE fqshrstr.for:266 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrstr.for:267 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:268 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:269 */
/*<       istart=i >*/
	istart = feq_gen_i_d_;
/* SOURCE fqshrstr.for:270 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrstr.for:271 */
/*<       if(name(i:i).ne.' ')then >*/
	if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] != ' ') {
/* SOURCE fqshrstr.for:272 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE fqshrstr.for:273 */
/*<       if(i.le.iend)then >*/
	    if (feq_gen_i_d_ <= iend) {
/* SOURCE fqshrstr.for:274 */
/*<       goto110 >*/
		goto L110;
/* SOURCE fqshrstr.for:275 */
/*<       else >*/
	    } else {
/* SOURCE fqshrstr.for:276 */
/*<       istop=iend >*/
		istop = iend;
/* SOURCE fqshrstr.for:277 */
/*<       endif >*/
	    }
/* SOURCE fqshrstr.for:278 */
/*<       else >*/
	} else {
/* SOURCE fqshrstr.for:279 */
/*<       istop=i-1 >*/
	    istop = feq_gen_i_d_ - 1;
/* SOURCE fqshrstr.for:280 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:281 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:283 */
/*<       nxtstr=name(istart:istop) >*/
    s_copy(nxtstr, feq_gen_name_d_ + (istart - 1), nxtstr_len, istop - (istart - 1));
/* SOURCE fqshrstr.for:284 */
/*<       ie=istop+1 >*/
    *ie = istop + 1;
/* SOURCE fqshrstr.for:285 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:286 */
/*<       end >*/
} /* getnxt_ */

/*     *********** */
/*     *         * */
/*     * STRIP_L_BLANKS */
/*     *         * */
/*     *********** */
/* SOURCE fqshrstr.for:293 */
/*<       subroutinestrip_l_blanks(name) >*/
/* Subroutine */ int feq_gen_strip_l_blanks_d_(char *feq_gen_name_d_, ftnlen name_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer i_len(char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, iend, istart;

/*     Strip leading blanks from the string NAME and return. */
/* SOURCE fqshrstr.for:298 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrstr.for:300 */
/*<       charactername*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NAME   - string being scanned */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrstr.for:306 */
/*<       integeri,iend,istart >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrstr.for:309 */
/*<       intrinsiclen >*/
/* *********************************************************************** */
/* SOURCE fqshrstr.for:311 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE fqshrstr.for:312 */
/*<       iend=len(name) >*/
    iend = i_len(feq_gen_name_d_, name_len);
/* SOURCE fqshrstr.for:314 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrstr.for:315 */
/*<       if(name(i:i).eq.' ')then >*/
    if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] == ' ') {
/* SOURCE fqshrstr.for:316 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE fqshrstr.for:317 */
/*<       if(i.le.iend)then >*/
	if (feq_gen_i_d_ <= iend) {
/* SOURCE fqshrstr.for:318 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE fqshrstr.for:319 */
/*<       else >*/
	} else {
/*           RETURN A BLANK IF NO NON-BLANK FOUND */
/* SOURCE fqshrstr.for:321 */
/*<       name=' ' >*/
	    s_copy(feq_gen_name_d_, const_cast<char*>(" "), name_len, (ftnlen)1);
/* SOURCE fqshrstr.for:322 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrstr.for:323 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:324 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:325 */
/*<       istart=i >*/
	istart = feq_gen_i_d_;
/* SOURCE fqshrstr.for:326 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:328 */
/*<       name=name(istart:iend) >*/
    s_copy(feq_gen_name_d_, feq_gen_name_d_ + (istart - 1), name_len, iend - (istart - 1));
/* SOURCE fqshrstr.for:329 */
/*<       if(istart.gt.1)then >*/
    if (istart > 1) {
/* SOURCE fqshrstr.for:330 */
/*<       name(iend-istart+2:iend)=' ' >*/
	feq_gen_i_d_1 = iend - istart + 1;
	s_copy(feq_gen_name_d_ + feq_gen_i_d_1, const_cast<char*>(" "), iend - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE fqshrstr.for:331 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:332 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:333 */
/*<       end >*/
} /* strip_l_blanks__ */

/*     *********** */
/*     *         * */
/*     * STRIP_BLANKS_AND_ZEROS */
/*     *         * */
/*     *********** */
/* SOURCE fqshrstr.for:340 */
/*<       subroutinestrip_blanks_and_zeros(name) >*/
/* Subroutine */ int feq_gen_strip_blanks_and_zeros_d_(char *feq_gen_name_d_, ftnlen name_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*ERR:xxx* One or more blanks found in:\
 \002,a,\002  Invalid in this context.\002)";

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_feq_adjustl_d_(char *, char *, ftnlen, ftnlen);
    integer iend;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_50, 0 };


/*     Strip trailing and leading blanks and leading zeros */
/*     from the string NAME and return. */
/*     Added 7 Dec 2005: check for blanks internal to the field and */
/*     if found write error message and stop processing. */
/* SOURCE fqshrstr.for:348 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrstr.for:350 */
/*<       charactername*(*) >*/
/* INCLUDE fqshrstr.for:352 */
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
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NAME   - string being scanned */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrstr.for:358 */
/*<       integeri,iend,istart >*/
/*     Called program units */
/*     *************************formats********************************** */
/* SOURCE fqshrstr.for:340 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrstr.for:340 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrstr.for:362 */
/*<    50  >*/
/* *********************************************************************** */
/*     Strip any leading blanks */
/* SOURCE fqshrstr.for:366 */
/*<       callfeq_adjustl(name,name) >*/
/* L50: */
    feq_gen_feq_adjustl_d_(feq_gen_name_d_, feq_gen_name_d_, name_len, name_len);
/* SOURCE fqshrstr.for:367 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/*     Strip trailing blanks */
/* SOURCE fqshrstr.for:369 */
/*<       iend=feq_len_trim(name) >*/
    iend = feq_gen_feq_len_trim_d_(feq_gen_name_d_, name_len);
/*     Change leading zeros to blanks */
/* SOURCE fqshrstr.for:372 */
/*<       dowhile(i<=iend) >*/
    while(feq_gen_i_d_ <= iend) {
/* SOURCE fqshrstr.for:373 */
/*<       if(name(i:i)=='0')then >*/
	if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] == '0') {
/* SOURCE fqshrstr.for:374 */
/*<       name(i:i)=' ' >*/
	    *(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] = ' ';
/* SOURCE fqshrstr.for:375 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE fqshrstr.for:376 */
/*<       else >*/
	} else {
/* SOURCE fqshrstr.for:377 */
/*<       goto99000 >*/
	    goto L99000;
/* SOURCE fqshrstr.for:378 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:379 */
/*<       enddo >*/
    }
/* SOURCE fqshrstr.for:379 */
/*< 99000 continue >*/
L99000:
/*     Strip leading  and trailing blanks again */
/* SOURCE fqshrstr.for:382 */
/*<       callfeq_adjustl(name,name) >*/
    feq_gen_feq_adjustl_d_(feq_gen_name_d_, feq_gen_name_d_, name_len, name_len);
/* SOURCE fqshrstr.for:383 */
/*<       iend=feq_len_trim(name) >*/
    iend = feq_gen_feq_len_trim_d_(feq_gen_name_d_, name_len);
/* SOURCE fqshrstr.for:384 */
/*<       if(iend>2)then >*/
    if (iend > 2) {
/*       Check for internal blanks */
/* SOURCE fqshrstr.for:386 */
/*<       if(index(name(1:iend),' ')>0)then >*/
	if (i_indx(feq_gen_name_d_, const_cast<char*>(" "), iend, (ftnlen)1) > 0) {
/*         Found a blank interior to the item--error */
/* SOURCE fqshrstr.for:388 */
/*<       write(std6,50)name(1:iend) >*/
	    feq_gen_io_d__32.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__32);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, iend);
	    e_wsfe();
/* SOURCE fqshrstr.for:389 */
/*<       stop'Abnormal stop. Error(s) found:(' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Error(s) found:("), (ftnlen)31);
/* SOURCE fqshrstr.for:390 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:391 */
/*<       elseif(iend==0)then >*/
    } else if (iend == 0) {
/*       return a single blank */
/* SOURCE fqshrstr.for:393 */
/*<       name=' ' >*/
	s_copy(feq_gen_name_d_, const_cast<char*>(" "), name_len, (ftnlen)1);
/* SOURCE fqshrstr.for:394 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:395 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:396 */
/*<       end >*/
} /* strip_blanks_and_zeros__ */




/* SOURCE fqshrstr.for:400 */
/*<       character*(*)functiongettok(name) >*/
/* Character */ VOID gettok_(char *ret_val, ftnlen ret_val_len, char *feq_gen_name_d_, 
	ftnlen name_len)
{
    /* Builtin functions */
    integer i_len(char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, iend, istop, istart;

/*     + + + PURPOSE + + + */
/*     Get the first consecutive sequence of non-blank characters from */
/*     NAME */
/* SOURCE fqshrstr.for:406 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrstr.for:409 */
/*<       charactername*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NAME   - string being scanned */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrstr.for:415 */
/*<       integeri,iend,istart,istop >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrstr.for:418 */
/*<       intrinsiclen >*/
/* *********************************************************************** */
/* SOURCE fqshrstr.for:420 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE fqshrstr.for:421 */
/*<       iend=len(name) >*/
    iend = i_len(feq_gen_name_d_, name_len);
/* SOURCE fqshrstr.for:423 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrstr.for:424 */
/*<       if(name(i:i).eq.' ')then >*/
    if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] == ' ') {
/* SOURCE fqshrstr.for:425 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE fqshrstr.for:426 */
/*<       if(i.le.iend)then >*/
	if (feq_gen_i_d_ <= iend) {
/* SOURCE fqshrstr.for:427 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE fqshrstr.for:428 */
/*<       else >*/
	} else {
/*           RETURN A BLANK IF NO NON-BLANK FOUND */
/* SOURCE fqshrstr.for:430 */
/*<       gettok=' ' >*/
	    s_copy(ret_val, const_cast<char*>(" "), ret_val_len, (ftnlen)1);
/* SOURCE fqshrstr.for:431 */
/*<       return >*/
	    return ;
/* SOURCE fqshrstr.for:432 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:433 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:434 */
/*<       istart=i >*/
	istart = feq_gen_i_d_;
/* SOURCE fqshrstr.for:435 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrstr.for:436 */
/*<       if(name(i:i).ne.' ')then >*/
	if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] != ' ') {
/* SOURCE fqshrstr.for:437 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE fqshrstr.for:438 */
/*<       if(i.le.iend)then >*/
	    if (feq_gen_i_d_ <= iend) {
/* SOURCE fqshrstr.for:439 */
/*<       goto110 >*/
		goto L110;
/* SOURCE fqshrstr.for:440 */
/*<       else >*/
	    } else {
/* SOURCE fqshrstr.for:441 */
/*<       istop=i-1 >*/
		istop = feq_gen_i_d_ - 1;
/* SOURCE fqshrstr.for:442 */
/*<       endif >*/
	    }
/* SOURCE fqshrstr.for:443 */
/*<       else >*/
	} else {
/* SOURCE fqshrstr.for:444 */
/*<       istop=i >*/
	    istop = feq_gen_i_d_;
/* SOURCE fqshrstr.for:445 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:446 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:448 */
/*<       gettok=name(istart:istop) >*/
    s_copy(ret_val, feq_gen_name_d_ + (istart - 1), ret_val_len, istop - (istart - 1));
/* SOURCE fqshrstr.for:449 */
/*<       return >*/
    return ;
/* SOURCE fqshrstr.for:450 */
/*<       end >*/
} /* gettok_ */

/*     *********** */
/*     *         * */
/*     * LENSTR  * */
/*     *         * */
/*     *********** */
/* SOURCE fqshrstr.for:457 */
/*<       integerfunctionlenstr(str) >*/
integer lenstr_(char *str, ftnlen str_len)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Invoke the F95 intrinsic LEN_TRIM */
/*     Return the actual length of the character string, */
/*     excluding trailing blanks.  Modified from USGS. */
/* SOURCE fqshrstr.for:467 */
/*<       implicitnone >*/
/* SOURCE fqshrstr.for:468 */
/*<       character*(*)str >*/
/*     + + + ARGUMENT DEFINITIONS + + + */
/*     STR    - character string */
/*     + + + LOCAL VARIALBES + + + */
/*      INTEGER LENT, DONE, LEN */
/*     Program units */
/* *********************************************************************** */
/* SOURCE fqshrstr.for:457 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrstr.for:457 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrstr.for:480 */
/*<       lenstr=feq_len_trim(str) >*/
    ret_val = feq_gen_feq_len_trim_d_(str, str_len);
/* SOURCE fqshrstr.for:481 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrstr.for:482 */
/*<       end >*/
} /* lenstr_ */

/*      DONE = 0 */
/*      LENT = LEN(STR) */
/*  10  CONTINUE */
/*        IF (STR(LENT:LENT).EQ.' ') THEN */
/*          LENT = LENT - 1 */
/*        ELSE */
/*          DONE = 1 */
/*        END IF */
/*      IF (LENT.GT.0.AND.DONE.EQ.0) GO TO 10 */
/* C */
/*      LENSTR= LENT */
/* C */
/*      RETURN */
/*      END */
/*     *********** */
/*     *         * */
/*     * GET_HECDSS_PATH */
/*     *         * */
/*     *********** */
/* SOURCE fqshrstr.for:505 */
/*<       subroutineget_hecdss_path(string,next,result,eflag) >*/
/* Subroutine */ int feq_gen_get_hecdss_path_d_(char *string, integer *next, char *
	result, integer *eflag, ftnlen string_len, ftnlen result_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_len(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, feq_gen_max_length_result_d_, knt, feq_gen_first_slash_d_, feq_gen_string_length_d_;
    extern integer lenstr_(char *, ftnlen);

/*     Get a HECDSS path name from STRING starting at position NEXT and */
/*     returning it in RESULT if one is found.  Otherwise return a blank */
/*     in RESULT.  NEXT should point to the position in the string after */
/*     the last character of the path if that position exists.  If the */
/*     position does not exist, return 0. */
/* SOURCE fqshrstr.for:515 */
/*<       implicitnone >*/
/* SOURCE fqshrstr.for:516 */
/*<       integereflag,next >*/
/* SOURCE fqshrstr.for:518 */
/*<       character*(*)string,result >*/
/*     Local */
/* SOURCE fqshrstr.for:522 */
/*<       integeri,j,string_length,first_slash,max_length_result,knt >*/
/*     Called routines */
/* SOURCE fqshrstr.for:527 */
/*<       integerlenstr >*/
/* SOURCE fqshrstr.for:529 */
/*<       externallenstr >*/
/* SOURCE fqshrstr.for:530 */
/*<       intrinsiclen >*/
/* *********************************************************************** */
/* SOURCE fqshrstr.for:532 */
/*<       eflag=0 >*/
    *eflag = 0;
/* SOURCE fqshrstr.for:533 */
/*<       result=' ' >*/
    s_copy(result, const_cast<char*>(" "), result_len, (ftnlen)1);
/* SOURCE fqshrstr.for:534 */
/*<       string_length=lenstr(string) >*/
    feq_gen_string_length_d_ = lenstr_(string, string_len);
/* SOURCE fqshrstr.for:535 */
/*<       max_length_result=len(result) >*/
    feq_gen_max_length_result_d_ = i_len(result, result_len);
/*     Find the first / */
/* SOURCE fqshrstr.for:537 */
/*<       do90i=next,string_length >*/
    feq_gen_i_d_1 = feq_gen_string_length_d_;
    for (feq_gen_i_d_ = *next; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrstr.for:538 */
/*<       if(string(i:i).eq.'/')then >*/
	if (*(unsigned char *)&string[feq_gen_i_d_ - 1] == '/') {
/* SOURCE fqshrstr.for:539 */
/*<       first_slash=i >*/
	    feq_gen_first_slash_d_ = feq_gen_i_d_;
/* SOURCE fqshrstr.for:540 */
/*<       goto95 >*/
	    goto L95;
/* SOURCE fqshrstr.for:541 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:542 */
/*<    90 continue >*/
/* L90: */
    }
/* SOURCE fqshrstr.for:543 */
/*<       result=' ' >*/
    s_copy(result, const_cast<char*>(" "), result_len, (ftnlen)1);
/* SOURCE fqshrstr.for:544 */
/*<       next=-1 >*/
    *next = -1;
/* SOURCE fqshrstr.for:545 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:546 */
/*<    95 continue >*/
L95:
/*     Starting at the first slash, transfer characters to */
/*     RESULT, counting slashes until the 7th slash is transferred */
/*     or some string limit is exhausted. */
/* SOURCE fqshrstr.for:552 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE fqshrstr.for:553 */
/*<       j=0 >*/
    j = 0;
/* SOURCE fqshrstr.for:554 */
/*<       do100i=first_slash,string_length >*/
    feq_gen_i_d_1 = feq_gen_string_length_d_;
    for (feq_gen_i_d_ = feq_gen_first_slash_d_; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrstr.for:555 */
/*<       j=j+1 >*/
	++j;
/* SOURCE fqshrstr.for:556 */
/*<       if(j.gt.max_length_result)then >*/
	if (j > feq_gen_max_length_result_d_) {
/* SOURCE fqshrstr.for:557 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrstr.for:558 */
/*<       next=-2 >*/
	    *next = -2;
/* SOURCE fqshrstr.for:559 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrstr.for:560 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:561 */
/*<       result(j:j)=string(i:i) >*/
	*(unsigned char *)&result[j - 1] = *(unsigned char *)&string[feq_gen_i_d_ - 1];
/* SOURCE fqshrstr.for:562 */
/*<       if(string(i:i).eq.'/')then >*/
	if (*(unsigned char *)&string[feq_gen_i_d_ - 1] == '/') {
/* SOURCE fqshrstr.for:563 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE fqshrstr.for:564 */
/*<       if(knt.eq.7)goto110 >*/
	    if (knt == 7) {
		goto L110;
	    }
/* SOURCE fqshrstr.for:565 */
/*<       endif >*/
	}
/* SOURCE fqshrstr.for:566 */
/*<   100 continue >*/
/* L100: */
    }
/*     A pathname was not found.  We hit the end of string */
/*     before finding 7 slashes. */
/* SOURCE fqshrstr.for:569 */
/*<       result=' ' >*/
    s_copy(result, const_cast<char*>(" "), result_len, (ftnlen)1);
/* SOURCE fqshrstr.for:570 */
/*<       next=-3 >*/
    *next = -3;
/* SOURCE fqshrstr.for:571 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:573 */
/*<   110 continue >*/
L110:
/*     Here we have a path name.  Set the value of NEXT */
/* SOURCE fqshrstr.for:575 */
/*<       if(i.eq.string_length)then >*/
    if (feq_gen_i_d_ == feq_gen_string_length_d_) {
/* SOURCE fqshrstr.for:576 */
/*<       next=0 >*/
	*next = 0;
/* SOURCE fqshrstr.for:577 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:578 */
/*<       next=i+1 >*/
	*next = feq_gen_i_d_ + 1;
/* SOURCE fqshrstr.for:579 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:581 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:582 */
/*<       end >*/
} /* get_hecdss_path__ */




/* SOURCE fqshrstr.for:586 */
/*<       character*8functionput8(x) >*/
/* Character */ VOID put8_(char *ret_val, ftnlen ret_val_len, real *x)
{
    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char work[10], result[8];

/*     + + + PURPOSE + + + */
/*     Function to convert a real number into a special compact */
/*     form of output to retain 4 significant figures for */
/*     numbers in the range -1e10 < x < 1e10.  This range includes */
/*     all reasonable flows for any river on earth! */
/*     The smallest non-zero flow is 1e-9, again smaller than any */
/*     flow of interest in a stream. */
/* SOURCE fqshrstr.for:597 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrstr.for:599 */
/*<       realx >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     X      - value to format */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrstr.for:605 */
/*<       characterresult*8,work*10 >*/
/* *********************************************************************** */
/* SOURCE fqshrstr.for:607 */
/*<       write(work,'(1PE10.3)')x >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 10;
    feq_gen_ici_d_1.iciunit = work;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(1PE10.3)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*x), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE fqshrstr.for:608 */
/*<       if(work(8:8).eq.'+'.and.work(9:9).ne.'0')then >*/
    if (*(unsigned char *)&work[7] == '+' && *(unsigned char *)&work[8] != 
	    '0') {
/*       OVERFLOW */
/* SOURCE fqshrstr.for:610 */
/*<       result=' *******' >*/
	s_copy(result, const_cast<char*>(" *******"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrstr.for:611 */
/*<       elseif(work(8:8).eq.'-'.and.work(9:9).ne.'0')then >*/
    } else if (*(unsigned char *)&work[7] == '-' && *(unsigned char *)&work[8]
	     != '0') {
/*       UNDERFLOW */
/* SOURCE fqshrstr.for:613 */
/*<       result=' 0.000+0' >*/
	s_copy(result, const_cast<char*>(" 0.000+0"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrstr.for:614 */
/*<       else >*/
    } else {
/* SOURCE fqshrstr.for:615 */
/*<       result(1:6)=work(1:6) >*/
	s_copy(result, work, (ftnlen)6, (ftnlen)6);
/* SOURCE fqshrstr.for:616 */
/*<       result(7:7)=work(8:8) >*/
	*(unsigned char *)&result[6] = *(unsigned char *)&work[7];
/* SOURCE fqshrstr.for:617 */
/*<       result(8:8)=work(10:10) >*/
	*(unsigned char *)&result[7] = *(unsigned char *)&work[9];
/* SOURCE fqshrstr.for:618 */
/*<       endif >*/
    }
/* SOURCE fqshrstr.for:619 */
/*<       put8=result >*/
    s_copy(ret_val, result, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrstr.for:620 */
/*<       return >*/
    return ;
/* SOURCE fqshrstr.for:621 */
/*<       end >*/
} /* put8_ */




/* SOURCE fqshrstr.for:625 */
/*<       subroutinerdup(n,a,newn) >*/
/* Subroutine */ int rdup_(integer *n, real *feq_storage_a, integer *newn)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Local variables */
    integer feq_gen_i_d_, j, j1;
    real div;

/*     + + + PURPOSE + + + */
/*     Remove duplicates from the sorted vector A(*) of */
/*     length N returning the new value of N, NEWN. */
/* SOURCE fqshrstr.for:634 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrstr.for:636 */
/*<       integern,newn >*/
/* SOURCE fqshrstr.for:637 */
/*<       reala(n) >*/
/*      INCLUDE 'stdun.cmn' */
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - Number of items in list */
/*     A      - Vector of sorted values possibly having duplicates */
/*     NEWN   - New number of items in list free of duplicates */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrstr.for:647 */
/*<       integeri,j,j1 >*/
/* SOURCE fqshrstr.for:648 */
/*<       realdiv >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrstr.for:651 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/*     Select a value near the middle of the list for scale. */
/* SOURCE fqshrstr.for:654 */
/*<       div=0.5*(abs(a(1))+abs(a(n)))-a(1) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> a(feq_storage_a, 1);

    /* Function Body */
    div = (dabs(a[1]) + (feq_gen_r_d_1 = a[*n], dabs(feq_gen_r_d_1))) * (float).5 - a[1];
/*      IF(DIV.EQ.0.0) THEN */
/*        WRITE(STD6,*) ' N=',N */
/*        WRITE(STD6,*) ' DIV=',DIV */
/*        WRITE(STD6,*) (A(I),I=1,N) */
/*        STOP 'Bug found in RDUP' */
/*      ENDIF */
/* SOURCE fqshrstr.for:661 */
/*<       j=1 >*/
    j = 1;
/* SOURCE fqshrstr.for:662 */
/*<       if(j+1.gt.n)goto100 >*/
    if (j + 1 > *n) {
	goto L100;
    }
/* SOURCE fqshrstr.for:663 */
/*<       j1=j+1 >*/
    j1 = j + 1;
/* SOURCE fqshrstr.for:664 */
/*<       do90i=j1,n >*/
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = j1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrstr.for:665 */
/*<       if(abs((a(j)-a(1))-(a(i)-a(1)))/div.le.1.e-5)goto90 >*/
	if ((feq_gen_r_d_1 = static_cast<double>(static_cast<double>(a[j]) - a[1]) - (static_cast<double>(a[feq_gen_i_d_]) - a[1]), dabs(feq_gen_r_d_1)) / div <= (
		float)1e-5) {
	    goto L90;
	}
/* SOURCE fqshrstr.for:666 */
/*<       j=j+1 >*/
	++j;
/* SOURCE fqshrstr.for:667 */
/*<       if(j.ne.i)a(j)=a(i) >*/
	if (j != feq_gen_i_d_) {
	    a[j] = a[feq_gen_i_d_];
	}
/* SOURCE fqshrstr.for:668 */
/*<    90 continue >*/
L90:
	;
    }
/* SOURCE fqshrstr.for:669 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrstr.for:670 */
/*<       newn=j >*/
    *newn = j;
/* SOURCE fqshrstr.for:671 */
/*<       return >*/
    return 0;
/* SOURCE fqshrstr.for:672 */
/*<       end >*/
} /* rdup_ */

#ifdef __cplusplus
	}
#endif
