/* linuxcr.f -- translated by f2c (version 20240504).
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

/* COMMON crcom_ is declared in common.hpp. */

#define crcom_1 crcom_




/* SOURCE linuxcr.for:4 */
/*<       subroutinesetcr() >*/
/* Subroutine */ int setcr_()
{
/*     Set the carriage return character to use */
/*     in filtering carriage-return characters from */
/*     input files transfered from NT to Linux without */
/*     doing a conversion.  We find all carriage-return */
/*     characters and replace them with a single space. */
/*     There will be only one per line and then at the */
/*     last none-blank of the line. */
/* INCLUDE linuxcr.for:14 */
/*     Common block to hold the carriage return character */
/* SOURCE cr.cmn:3 */
/*<       character*1cr >*/
/* SOURCE cr.cmn:5 */
/*<       common/crcom/cr >*/
/* SOURCE cr.cmn:7 */
/*<       save/crcom/ >*/
/* *********************************************************************** */
/* SOURCE linuxcr.for:16 */
/*<       cr=char(13) >*/
    *(unsigned char *)crcom_1.cr = '\r';
/* SOURCE linuxcr.for:17 */
/*<       return >*/
    return 0;
/* SOURCE linuxcr.for:18 */
/*<       end >*/
} /* setcr_ */




/* SOURCE linuxcr.for:23 */
/*<       subroutinefilter_cr(line) >*/
/* Subroutine */ int feq_gen_filter_cr_d_(char *line, ftnlen line_len)
{
    integer n;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Seek a carriage-return character at the end */
/*     of the line and change it to a space if found. */
/*     The logic of this routine is as follows: */
/*     1. If we are running on some MS Windows system */
/*        the final character in the line that Fortran */
/*        sees will never be a carriage return because */
/*        the OS sends Fortran the actual data in the */
/*        text file and not the end of line characters. */
/*     2. If we are running on a Linux/Unix system using */
/*        input data transfered from MS Windows without */
/*        conversion of the end of line characters, we */
/*        will have a carriage return at the end of the */
/*        line because Linux/Unix treats it like data. */
/*     3. If we are running on a Linux/Unix system using */
/*        input data created on that system so that each */
/*        line in the file is ended with only a line feed, */
/*        we will never see a carriage return at the end */
/*        of the line so the line is unchanged.  The */
/*        same holds for input data transferred from */
/*        MS Windows and then converte to the Linux/Unix */
/*        end of lines. */
/*     The purpose of this scanning is to make it possible */
/*     to transfer huge amounts of text input between Linux */
/*     and MS Windows without having to convert the end of */
/*     line character.  Visual Slick Edit, the editor I use */
/*     under Linux recognizes the end of line and maintains it */
/*     for each file.  Thus changes made on the Linux side */
/*     will reflect the end of line used for MS Windows. */
/*     However, manipulation of the text files in Linux using */
/*     any of the Linux commands could present problems with */
/*     this approach. */
/* SOURCE linuxcr.for:63 */
/*<       implicitnone >*/
/* SOURCE linuxcr.for:64 */
/*<       characterline*(*) >*/
/* INCLUDE linuxcr.for:66 */
/*     Common block to hold the carriage return character */
/* SOURCE cr.cmn:3 */
/*<       character*1cr >*/
/* SOURCE cr.cmn:5 */
/*<       common/crcom/cr >*/
/* SOURCE cr.cmn:7 */
/*<       save/crcom/ >*/
/*     Local */
/* SOURCE linuxcr.for:69 */
/*<       integern >*/
/* *********************************************************************** */
/* SOURCE linuxcr.for:23 */
/*<       integer feq_len_trim >*/
/* SOURCE linuxcr.for:23 */
/*<       external feq_len_trim >*/
/* SOURCE linuxcr.for:71 */
/*<       n=feq_len_trim(line) >*/
    n = feq_gen_feq_len_trim_d_(line, line_len);
/* SOURCE linuxcr.for:72 */
/*<       if(n.gt.0)then >*/
    if (n > 0) {
/* SOURCE linuxcr.for:73 */
/*<       if(line(n:n).eq.cr)then >*/
	if (*(unsigned char *)&line[n - 1] == *(unsigned char *)crcom_1.cr) {
/* SOURCE linuxcr.for:74 */
/*<       line(n:n)=' ' >*/
	    *(unsigned char *)&line[n - 1] = ' ';
/* SOURCE linuxcr.for:75 */
/*<       endif >*/
	}
/* SOURCE linuxcr.for:76 */
/*<       endif >*/
    }
/* SOURCE linuxcr.for:77 */
/*<       return >*/
    return 0;
/* SOURCE linuxcr.for:78 */
/*<       end >*/
} /* filter_cr__ */

#ifdef __cplusplus
	}
#endif
