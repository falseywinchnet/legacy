/* fqshrinl.f -- translated by f2c (version 20240504).
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

static integer feq_gen_c_d_1 = 1;




/*      SUBROUTINE   INL80B */
/*     I                  (IN, OUT, */
/*     O                   LINE) */
/*     + + + PURPOSE + + + */
/*     Function to read lines from the input, detect comments, */
/*     and return only valid input lines to the point of call. */
/*     This routine returns a blank line as a valid input line. */
/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER IN, OUT */
/*      CHARACTER LINE*80 */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     IN     - unit number for the user input file */
/* C     OUT    - unit number for output */
/* C     LINE   - buffer for an input line */

/* C     Local */

/*      INTEGER N */

/* C     + + + SAVED VALUES + + + */
/*      CHARACTER INONLY*1, INOUT*1, PLUS*1 */

/*      SAVE INONLY, INOUT, PLUS */

/* C     + + + DATA INITIALIZATIONS + + + */
/*      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/ */

/* C     Program units called. */

/*      EXTERNAL  FILTER_CR */
/* C*********************************************************************** */
/* 100  CONTINUE */
/*        READ(IN,'(A80)',END=200) LINE */
/*        CALL FILTER_CR( */
/*     M                LINE) */
/*        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS) THEN */
/* C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE */
/*          N = LEN_TRIM(LINE) */
/*          WRITE(OUT,'(1X,A)') LINE(1:N) */
/*          GOTO 100 */
/*        ELSEIF(LINE(1:1).NE.INONLY) THEN */
/* C         LINE IS NOT A COMMENT.  RETURN THE LINE TO */
/* C         THE POINT OF CALL. */

/*          RETURN */
/*        ENDIF */
/*      GOTO 100 */
/* 200  CONTINUE */
/*        LINE = 'ENDFILE' */
/*        RETURN */

/*      END */
/* C */
/* C */
/* C */
/*      SUBROUTINE   inl112 */
/*     I                   (IN, OUT, */
/*     O                    LINE) */

/* C     + + + PURPOSE + + + */
/* C     Function to read lines from the input, detect comments, */
/* C     and return only valid input lines to the point of call. */
/* C     This routine treats blank lines like echoing comments. */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER IN, OUT */
/*      CHARACTER LINE*112 */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     IN     - unit number for the user input file */
/* C     OUT    - unit number for output */
/* C     LINE   - buffer for an input line */

/* C     Local */

/*      INTEGER N */

/* C     + + + SAVED VALUES + + + */
/*      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*112 */
/*      SAVE INONLY, INOUT, PLUS, BLINE */

/* C     + + + DATA INITIALIZATIONS + + + */
/*      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/, BLINE/' '/ */

/* C     Program units called. */

/*      EXTERNAL FILTER_CR */
/* C*********************************************************************** */
/* 100  CONTINUE */
/*        READ(IN,'(A)',END=200) LINE */
/*        CALL FILTER_CR( */
/*     M                 LINE) */
/*        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS) THEN */
/* C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE */
/*          N = LEN_TRIM(LINE) */
/*          WRITE(OUT,'(1X,A)') LINE(1:N) */
/*          GOTO 100 */
/*        ELSEIF(LINE.EQ.BLINE) THEN */
/* C         Treat a blank line as an echoing comment. */
/*          WRITE(OUT,'(1X,A1)') ' ' */
/*          GOTO 100 */
/*        ELSEIF(LINE(1:1).NE.INONLY) THEN */
/* C         LINE IS NOT BLANK AND NOT A COMMENT.  RETURN THE LINE TO */
/* C         THE POINT OF CALL. */

/*          RETURN */
/*        ENDIF */

/*      GOTO 100 */

/* 200  CONTINUE */
/*        LINE = 'ENDFILE' */
/*        RETURN */
/*      END */
/* C */
/* C */
/* C */
/*      SUBROUTINE   inl120 */
/*     I                   (IN, OUT, */
/*     O                    LINE) */

/* C     + + + PURPOSE + + + */
/* C     Function to read lines from the input, detect comments, */
/* C     and return only valid input lines to the point of call. */
/* C     This routine treats blank lines like echoing comments. */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER IN, OUT */
/*      CHARACTER LINE*120 */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     IN     - unit number for the user input file */
/* C     OUT    - unit number for output */
/* C     LINE   - buffer for an input line */

/* C     Local */

/*      INTEGER N */

/* C     + + + SAVED VALUES + + + */
/*      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*120 */
/*      SAVE INONLY, INOUT, PLUS, BLINE */

/* C     + + + DATA INITIALIZATIONS + + + */
/*      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/, BLINE/' '/ */

/* C     Program units called. */

/*      EXTERNAL FILTER_CR */
/* C*********************************************************************** */
/* 100  CONTINUE */
/*        READ(IN,'(A)',END=200) LINE */
/*        CALL FILTER_CR( */
/*     M                 LINE) */
/*        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS) THEN */
/* C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE */
/*          N = LEN_TRIM(LINE) */
/*          WRITE(OUT,'(1X,A)') LINE(1:N) */
/*          GOTO 100 */
/*        ELSEIF(LINE.EQ.BLINE) THEN */
/* C         Treat a blank line as an echoing comment. */
/*          WRITE(OUT,'(1X,A1)') ' ' */
/*          GOTO 100 */
/*        ELSEIF(LINE(1:1).NE.INONLY) THEN */
/* C         LINE IS NOT BLANK AND NOT A COMMENT.  RETURN THE LINE TO */
/* C         THE POINT OF CALL. */

/*          RETURN */
/*        ENDIF */

/*      GOTO 100 */

/* 200  CONTINUE */
/*        LINE = 'ENDFILE' */
/*        RETURN */
/*      END */



/* SOURCE fqshrinl.for:189 */
/*<       subroutineinlineb(in,out,line) >*/
/* Subroutine */ int inlineb_(integer *in, integer *out, char *line, ftnlen 
	line_len)
{
    /* Initialized data */

    static char inout[1+1] = "*";
    static char plus[1+1] = "+";
    static char inonly[1+1] = ";";
    static char bline[120+1] = "                                            \
                                                                            ";

    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer n;
    extern /* Subroutine */ int feq_gen_filter_cr_d_(char *, ftnlen);
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     + + + PURPOSE + + + */
/*     Function to read lines from the input, detect comments, */
/*     and return only valid input lines to the point of call. */
/*     This routine treats blank lines as valid input lines. */
/* SOURCE fqshrinl.for:198 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrinl.for:200 */
/*<       integerin,out >*/
/* SOURCE fqshrinl.for:201 */
/*<       characterline*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     OUT    - unit number for output */
/*     LINE   - buffer for an input line */
/*     Local */
/* SOURCE fqshrinl.for:210 */
/*<       integern >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrinl.for:213 */
/*<       characterinonly*1,inout*1,plus*1,bline*120 >*/
/* SOURCE fqshrinl.for:214 */
/*<       saveinonly,inout,plus,bline >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     Program units called. */
/* SOURCE fqshrinl.for:221 */
/*<       externalfilter_cr >*/
/* *********************************************************************** */
/* SOURCE fqshrinl.for:189 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrinl.for:189 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrinl.for:217 */
/*<       datainout/'*'/,plus/'+'/,inonly/';'/,bline/' '/ >*/
/* SOURCE fqshrinl.for:223 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrinl.for:224 */
/*<       read(in,'(A)',end=200)line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciend = 1;
    feq_gen_ci_d_1.ciunit = *in;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    feq_gen_i_d_1 = s_rsfe(&feq_gen_ci_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, line_len);
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
    feq_gen_i_d_1 = e_rsfe();
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
/* SOURCE fqshrinl.for:225 */
/*<       callfilter_cr(line) >*/
    feq_gen_filter_cr_d_(line, line_len);
/* SOURCE fqshrinl.for:227 */
/*<       if(line(1:1).eq.inout.or.line(1:1).eq.plus)then >*/
    if (*(unsigned char *)line == *(unsigned char *)&inout[0] || *(unsigned 
	    char *)line == *(unsigned char *)&plus[0]) {
/*         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE */
/* SOURCE fqshrinl.for:229 */
/*<       n=feq_len_trim(line) >*/
	n = feq_gen_feq_len_trim_d_(line, line_len);
/* SOURCE fqshrinl.for:230 */
/*<       write(out,'(1X,A)')line(1:n) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *out;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, n);
	e_wsfe();
/* SOURCE fqshrinl.for:231 */
/*<       goto100 >*/
	goto L100;
/* SOURCE fqshrinl.for:232 */
/*<       elseif(line.eq.bline)then >*/
    } else if (s_cmp(line, bline, line_len, (ftnlen)120) == 0) {
/*         Treat a blank line as an input line. */
/* SOURCE fqshrinl.for:235 */
/*<       return >*/
	return 0;
/* SOURCE fqshrinl.for:236 */
/*<       elseif(line(1:1).ne.inonly)then >*/
    } else if (*(unsigned char *)line != *(unsigned char *)&inonly[0]) {
/*         LINE IS NOT BLANK AND NOT A COMMENT.  RETURN THE LINE TO */
/*         THE POINT OF CALL. */
/* SOURCE fqshrinl.for:240 */
/*<       return >*/
	return 0;
/* SOURCE fqshrinl.for:241 */
/*<       endif >*/
    }
/* SOURCE fqshrinl.for:243 */
/*<       goto100 >*/
    goto L100;
/* SOURCE fqshrinl.for:245 */
/*<   200 continue >*/
L200:
/* SOURCE fqshrinl.for:246 */
/*<       line='ENDFILE' >*/
    s_copy(line, const_cast<char*>("ENDFILE"), line_len, (ftnlen)7);
/* SOURCE fqshrinl.for:247 */
/*<       return >*/
    return 0;
/* SOURCE fqshrinl.for:248 */
/*<       end >*/
} /* inlineb_ */

/* C */
/* C */
/* C */
/*      SUBROUTINE   inl196 */
/*     I                   (IN, OUT, */
/*     O                    LINE) */

/* C     + + + PURPOSE + + + */
/* C     Function to read lines from the input, detect comments, */
/* C     and return only valid input lines to the point of call. */
/* C     This routine treats blank lines like echoing comments. */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER IN, OUT */
/*      CHARACTER LINE*196 */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     IN     - unit number for the user input file */
/* C     OUT    - unit number for output */
/* C     LINE   - buffer for an input line */

/* C     Local */

/*      INTEGER N */

/* C     + + + SAVED VALUES + + + */
/*      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*196 */
/*      SAVE INONLY, INOUT, PLUS, BLINE */

/* C     + + + DATA INITIALIZATIONS + + + */
/*      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/, BLINE/' '/ */

/* C     Program units called. */

/*      EXTERNAL FILTER_CR */
/* C*********************************************************************** */
/* 100  CONTINUE */
/*        READ(IN,'(A)',END=200) LINE */
/*        CALL FILTER_CR( */
/*     M                 LINE) */
/*        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS) THEN */
/* C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE */
/*          N = LEN_TRIM(LINE) */
/*          WRITE(OUT,'(1X,A)') LINE(1:N) */
/*          GOTO 100 */
/*        ELSEIF(LINE.EQ.BLINE) THEN */
/* C         Treat a blank line as an echoing comment. */
/*          WRITE(OUT,'(1X,A1)') ' ' */
/*          GOTO 100 */
/*        ELSEIF(LINE(1:1).NE.INONLY) THEN */
/* C         LINE IS NOT BLANK AND NOT A COMMENT.  RETURN THE LINE TO */
/* C         THE POINT OF CALL. */

/*          RETURN */
/*        ENDIF */

/*      GOTO 100 */

/* 200  CONTINUE */
/*        LINE = 'ENDFILE' */
/*        RETURN */
/*      END */



/* SOURCE fqshrinl.for:315 */
/*<       subroutineinline_all(in,line) >*/
/* Subroutine */ int feq_gen_inline_all_d_(integer *in, char *line, ftnlen line_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_filter_cr_d_(char *, ftnlen);

/*     + + + PURPOSE + + + */
/*     Function to read lines from the input, returning all */
/*     lines.  Only strip carriage returns if found so that */
/*     un-recoded files from MS can be read in Linux! */
/* SOURCE fqshrinl.for:324 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrinl.for:326 */
/*<       integerin >*/
/* SOURCE fqshrinl.for:327 */
/*<       characterline*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     LINE   - buffer for an input line */
/*     Local */
/* SOURCE fqshrinl.for:335 */
/*<       integern >*/
/*     Program units called. */
/* SOURCE fqshrinl.for:339 */
/*<       externalfilter_cr >*/
/* *********************************************************************** */
/* SOURCE fqshrinl.for:341 */
/*<       read(in,'(A)',end=200)line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciend = 1;
    feq_gen_ci_d_1.ciunit = *in;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    feq_gen_i_d_1 = s_rsfe(&feq_gen_ci_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, line_len);
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
    feq_gen_i_d_1 = e_rsfe();
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
/* SOURCE fqshrinl.for:342 */
/*<       callfilter_cr(line) >*/
    feq_gen_filter_cr_d_(line, line_len);
/* SOURCE fqshrinl.for:344 */
/*<       return >*/
    return 0;
/* SOURCE fqshrinl.for:346 */
/*<   200 continue >*/
L200:
/* SOURCE fqshrinl.for:347 */
/*<       line='ENDFILE' >*/
    s_copy(line, const_cast<char*>("ENDFILE"), line_len, (ftnlen)7);
/* SOURCE fqshrinl.for:348 */
/*<       return >*/
    return 0;
/* SOURCE fqshrinl.for:349 */
/*<       end >*/
} /* inline_all__ */

/* C */
/* C */
/* C */
/*      SUBROUTINE   inl80 */
/*     I                  (IN, OUT, */
/*     O                   LINE) */

/* C     + + + PURPOSE + + + */
/* C     Function to read lines from the input, detect comments, */
/* C     and return only valid input lines to the point of call. */
/* C     This routine treats blank lines like echoing comments. */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER IN, OUT */
/*      CHARACTER LINE*80 */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     IN     - unit number for the user input file */
/* C     OUT    - unit number for output */
/* C     LINE   - buffer for an input line */

/* C     Local */

/*      INTEGER N */

/* C     + + + SAVED VALUES + + + */
/*      CHARACTER INONLY*1, INOUT*1, PLUS*1, BLINE*80 */

/*      SAVE INONLY, INOUT, PLUS, BLINE */

/* C     + + + DATA INITIALIZATIONS + + + */
/*      DATA INOUT/'*'/, PLUS/'+'/, INONLY/';'/,BLINE/' '/ */

/* C     Called program units */

/*      EXTERNAL FILTER_CR */
/* C*********************************************************************** */
/* 100  CONTINUE */
/*        READ(IN,'(A80)',END=200) LINE */
/*        CALL FILTER_CR( */
/*     M                 LINE) */

/*        IF(LINE(1:1).EQ.INOUT.OR.LINE(1:1).EQ.PLUS) THEN */
/* C         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE */
/*          N = LEN_TRIM(LINE) */
/*          WRITE(OUT,'(1X,A)') LINE(1:N) */
/*          GOTO 100 */
/*        ELSEIF(LINE.EQ.BLINE) THEN */
/* C         Treat a blank line as an echoing comment */
/*          WRITE(OUT,'(1X,A1)') ' ' */
/*          GOTO 100 */
/*        ELSEIF(LINE(1:1).NE.INONLY) THEN */
/* C         LINE IS NOT BLANK AND NOT A COMMENT.  RETURN THE LINE TO */
/* C         THE POINT OF CALL. */

/*          RETURN */
/*        ENDIF */

/*      GOTO 100 */

/* 200  CONTINUE */
/*        LINE = 'ENDFILE' */
/*        RETURN */

/*      END */



/* SOURCE fqshrinl.for:419 */
/*<       subroutineinline(in,out,line) >*/
/* Subroutine */ int inline_(integer *in, integer *out, char *line, ftnlen 
	line_len)
{
    /* Initialized data */

    static char inout[1+1] = "*";
    static char plus[1+1] = "+";
    static char inonly[1+1] = ";";
    static char bline[80+1] = "                                             \
                                   ";

    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer n;
    extern /* Subroutine */ int feq_gen_filter_cr_d_(char *, ftnlen);
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     + + + PURPOSE + + + */
/*     Function to read lines from the input, detect comments, */
/*     and return only valid input lines to the point of call. */
/*     This routine treats blank lines like echoing comments. */
/*     Jan. 8, 2002: Experiment with a generic-length string */
/*     to see how well it works. */
/* SOURCE fqshrinl.for:431 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrinl.for:433 */
/*<       integerin,out >*/
/* SOURCE fqshrinl.for:434 */
/*<       characterline*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     OUT    - unit number for output */
/*     LINE   - buffer for an input line */
/*     Local */
/* SOURCE fqshrinl.for:443 */
/*<       integern >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrinl.for:446 */
/*<       characterinonly*1,inout*1,plus*1,bline*80 >*/
/* SOURCE fqshrinl.for:448 */
/*<       saveinonly,inout,plus,bline >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     Called program units */
/* SOURCE fqshrinl.for:455 */
/*<       externalfilter_cr >*/
/* *********************************************************************** */
/* SOURCE fqshrinl.for:419 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrinl.for:419 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrinl.for:451 */
/*<       datainout/'*'/,plus/'+'/,inonly/';'/,bline/' '/ >*/
/* SOURCE fqshrinl.for:457 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrinl.for:458 */
/*<       read(in,'(A)',end=200)line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciend = 1;
    feq_gen_ci_d_1.ciunit = *in;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    feq_gen_i_d_1 = s_rsfe(&feq_gen_ci_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, line_len);
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
    feq_gen_i_d_1 = e_rsfe();
    if (feq_gen_i_d_1 != 0) {
	goto L200;
    }
/* SOURCE fqshrinl.for:459 */
/*<       callfilter_cr(line) >*/
    feq_gen_filter_cr_d_(line, line_len);
/* SOURCE fqshrinl.for:462 */
/*<       if(line(1:1).eq.inout.or.line(1:1).eq.plus)then >*/
    if (*(unsigned char *)line == *(unsigned char *)&inout[0] || *(unsigned 
	    char *)line == *(unsigned char *)&plus[0]) {
/*         OUTPUT THE LINE AND GO BACK AND GET NEXT LINE */
/* SOURCE fqshrinl.for:464 */
/*<       n=feq_len_trim(line) >*/
	n = feq_gen_feq_len_trim_d_(line, line_len);
/* SOURCE fqshrinl.for:465 */
/*<       write(out,'(1X,A)')line(1:n) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *out;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, n);
	e_wsfe();
/* SOURCE fqshrinl.for:466 */
/*<       goto100 >*/
	goto L100;
/* SOURCE fqshrinl.for:467 */
/*<       elseif(line.eq.bline)then >*/
    } else if (s_cmp(line, bline, line_len, (ftnlen)80) == 0) {
/*         Treat a blank line as an echoing comment */
/* SOURCE fqshrinl.for:469 */
/*<       write(out,'(1X,A1)')' ' >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *out;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A1)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsfe();
/* SOURCE fqshrinl.for:470 */
/*<       goto100 >*/
	goto L100;
/* SOURCE fqshrinl.for:471 */
/*<       elseif(line(1:1).ne.inonly)then >*/
    } else if (*(unsigned char *)line != *(unsigned char *)&inonly[0]) {
/*         LINE IS NOT BLANK AND NOT A COMMENT.  RETURN THE LINE TO */
/*         THE POINT OF CALL. */
/* SOURCE fqshrinl.for:475 */
/*<       return >*/
	return 0;
/* SOURCE fqshrinl.for:476 */
/*<       endif >*/
    }
/* SOURCE fqshrinl.for:478 */
/*<       goto100 >*/
    goto L100;
/* SOURCE fqshrinl.for:480 */
/*<   200 continue >*/
L200:
/* SOURCE fqshrinl.for:481 */
/*<       line='ENDFILE' >*/
    s_copy(line, const_cast<char*>("ENDFILE"), line_len, (ftnlen)7);
/* SOURCE fqshrinl.for:482 */
/*<       return >*/
    return 0;
/* SOURCE fqshrinl.for:484 */
/*<       end >*/
} /* inline_ */

#ifdef __cplusplus
	}
#endif
