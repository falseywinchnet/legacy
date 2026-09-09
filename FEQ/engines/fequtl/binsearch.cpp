/* binsearch.f -- translated by f2c (version 20240504).
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




/* SOURCE binsearch.for:4 */
/*<       subroutinebinser(item,n,tab,mid) >*/
/* Subroutine */ int binser_(char *item, integer *n, char *feq_storage_tab, integer *mid, 
	ftnlen item_len, ftnlen tab_len)
{
    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer il, ir;

/*     + + + PURPOSE + + + */
/*     Binary search in a sorted list of N items stored */
/*     in TAB(*). MID=0 if element is not found, else */
/*     MID gives the location in TAB at which a match */
/*     was found. */
/* SOURCE binsearch.for:14 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE binsearch.for:17 */
/*<       integermid,n >*/
/* SOURCE binsearch.for:18 */
/*<       characteritem*(*),tab(n)*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ITEM   - Search value */
/*     N      - Number of items to search */
/*     TAB    - Vector of items to be searched for a match */
/*     MID    - Index of value found and 0 if value not found */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE binsearch.for:27 */
/*<       integeril,ir >*/
/* *********************************************************************** */
/* SOURCE binsearch.for:29 */
/*<       il=1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> tab(feq_storage_tab, tab_len);

    /* Function Body */
    il = 1;
/* SOURCE binsearch.for:30 */
/*<       ir=n >*/
    ir = *n;
/* SOURCE binsearch.for:31 */
/*<   100 continue >*/
L100:
/* SOURCE binsearch.for:32 */
/*<       if(il.gt.ir)goto140 >*/
    if (il > ir) {
	goto L140;
    }
/* SOURCE binsearch.for:33 */
/*<       mid=(il+ir)/2 >*/
    *mid = (il + ir) / 2;
/* SOURCE binsearch.for:34 */
/*<       if(item.ge.tab(mid))goto110 >*/
    if (s_cmp(item, tab + *mid * tab_len, item_len, tab_len) >= 0) {
	goto L110;
    }
/* SOURCE binsearch.for:35 */
/*<       ir=mid-1 >*/
    ir = *mid - 1;
/* SOURCE binsearch.for:36 */
/*<       goto130 >*/
    goto L130;
/* SOURCE binsearch.for:37 */
/*<   110 continue >*/
L110:
/* SOURCE binsearch.for:38 */
/*<       if(item.eq.tab(mid))goto120 >*/
    if (s_cmp(item, tab + *mid * tab_len, item_len, tab_len) == 0) {
	goto L120;
    }
/* SOURCE binsearch.for:39 */
/*<       il=mid+1 >*/
    il = *mid + 1;
/* SOURCE binsearch.for:40 */
/*<       goto130 >*/
    goto L130;
/* SOURCE binsearch.for:41 */
/*<   120 continue >*/
L120:
/* SOURCE binsearch.for:42 */
/*<       return >*/
    return 0;
/* SOURCE binsearch.for:43 */
/*<   130 continue >*/
L130:
/* SOURCE binsearch.for:44 */
/*<       goto100 >*/
    goto L100;
/* SOURCE binsearch.for:45 */
/*<   140 continue >*/
L140:
/* SOURCE binsearch.for:46 */
/*<       mid=0 >*/
    *mid = 0;
/* SOURCE binsearch.for:47 */
/*<       return >*/
    return 0;
/* SOURCE binsearch.for:48 */
/*<       end >*/
} /* binser_ */

#ifdef __cplusplus
	}
#endif
