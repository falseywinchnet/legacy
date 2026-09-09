/* nxttok.f -- translated by f2c (version 20240504).
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

/*     *********** */
/*     *         * */
/*     * NXTTOK  * */
/*     *         * */
/*     *********** */
/* SOURCE nxttok.for:7 */
/*<       subroutinenxttok(string,nxt,result) >*/
/* Subroutine */ int nxttok_(char *string, integer *nxt, char *result, ftnlen 
	string_len, ftnlen result_len)
{
    /* Builtin functions */
    integer i_len(char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, iend, istop, istart;

/*     + + + PURPOSE + + + */
/*     Get the next consecutive sequence of non-blank characters from */
/*     STRING, return the sequence in RESULT, and the next character */
/*     offset in NXT. */
/* SOURCE nxttok.for:17 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE nxttok.for:19 */
/*<       integernxt >*/
/* SOURCE nxttok.for:20 */
/*<       characterresult*(*),string*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STRING - string to scan */
/*     NXT    - character offset for next scan */
/*     RESULT - item found */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE nxttok.for:28 */
/*<       integeri,iend,istart,istop >*/
/*     + + + INTRINSICS + + + */
/* SOURCE nxttok.for:31 */
/*<       intrinsiclen >*/
/* *********************************************************************** */
/* SOURCE nxttok.for:33 */
/*<       i=nxt >*/
    feq_gen_i_d_ = *nxt;
/* SOURCE nxttok.for:34 */
/*<       iend=len(string) >*/
    iend = i_len(string, string_len);
/* SOURCE nxttok.for:36 */
/*<   100 continue >*/
L100:
/* SOURCE nxttok.for:37 */
/*<       if(string(i:i).eq.' ')then >*/
    if (*(unsigned char *)&string[feq_gen_i_d_ - 1] == ' ') {
/* SOURCE nxttok.for:38 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE nxttok.for:39 */
/*<       if(i.le.iend)then >*/
	if (feq_gen_i_d_ <= iend) {
/* SOURCE nxttok.for:40 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE nxttok.for:41 */
/*<       else >*/
	} else {
/*           RETURN A BLANK IF NO NON-BLANK FOUND */
/* SOURCE nxttok.for:43 */
/*<       result=' ' >*/
	    s_copy(result, const_cast<char*>(" "), result_len, (ftnlen)1);
/* SOURCE nxttok.for:44 */
/*<       nxt=-1 >*/
	    *nxt = -1;
/* SOURCE nxttok.for:45 */
/*<       return >*/
	    return 0;
/* SOURCE nxttok.for:46 */
/*<       endif >*/
	}
/* SOURCE nxttok.for:47 */
/*<       else >*/
    } else {
/* SOURCE nxttok.for:48 */
/*<       istart=i >*/
	istart = feq_gen_i_d_;
/* SOURCE nxttok.for:49 */
/*<   110 continue >*/
L110:
/* SOURCE nxttok.for:50 */
/*<       if(string(i:i).ne.' ')then >*/
	if (*(unsigned char *)&string[feq_gen_i_d_ - 1] != ' ') {
/* SOURCE nxttok.for:51 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE nxttok.for:52 */
/*<       if(i.le.iend)then >*/
	    if (feq_gen_i_d_ <= iend) {
/* SOURCE nxttok.for:53 */
/*<       goto110 >*/
		goto L110;
/* SOURCE nxttok.for:54 */
/*<       else >*/
	    } else {
/* SOURCE nxttok.for:55 */
/*<       istop=i-1 >*/
		istop = feq_gen_i_d_ - 1;
/* SOURCE nxttok.for:56 */
/*<       endif >*/
	    }
/* SOURCE nxttok.for:57 */
/*<       else >*/
	} else {
/* SOURCE nxttok.for:58 */
/*<       istop=i-1 >*/
	    istop = feq_gen_i_d_ - 1;
/* SOURCE nxttok.for:59 */
/*<       endif >*/
	}
/* SOURCE nxttok.for:60 */
/*<       endif >*/
    }
/* SOURCE nxttok.for:62 */
/*<       result=string(istart:istop) >*/
    s_copy(result, string + (istart - 1), result_len, istop - (istart - 1));
/* SOURCE nxttok.for:63 */
/*<       nxt=istop+1 >*/
    *nxt = istop + 1;
/*      WRITE(*,*) ' NXTTOK: RESULT=',RESULT,' NXT=',NXT */
/*      WRITE(*,*) ' ISTART=',ISTART,' ISTOP=',ISTOP */
/* SOURCE nxttok.for:66 */
/*<       return >*/
    return 0;
/* SOURCE nxttok.for:67 */
/*<       end >*/
} /* nxttok_ */

#ifdef __cplusplus
	}
#endif
