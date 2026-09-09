/* makpat.f -- translated by f2c (version 20240504).
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

/*     ***************** */
/*     *               * */
/*     * MAKPAT        * */
/*     *               * */
/*     ***************** */
/* SOURCE makpat.for:7 */
/*<       subroutinemakpat(numeq,neq,eqlen,jeq,cmat) >*/
/* Subroutine */ int makpat_(integer *numeq, integer *neq, integer *eqlen, 
	integer *feq_storage_jeq, char *feq_storage_cmat, ftnlen cmat_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    integer j, k;

/*     MAKE PATTERN OF ZERO AND NON-ZERO VALUES IN A FULL MATRIX */
/*     FOR CHECKING PURPOSES ON MODEST SIZE MODELS. */
/* SOURCE makpat.for:13 */
/*<       integerneq,eqlen,numeq >*/
/* SOURCE makpat.for:15 */
/*<       integerjeq(eqlen) >*/
/* SOURCE makpat.for:17 */
/*<       character*1cmat(1013,1013) >*/
/* *********************************************************************** */
/* SOURCE makpat.for:20 */
/*<       if(numeq.gt.1013)return >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> jeq(feq_storage_jeq, 1);

    feq::IndexedPointer<char> cmat(feq_storage_cmat, 1014);

    /* Function Body */
    if (*numeq > 1013) {
	return 0;
    }
/*     CREATE PATTERN IN CMAT FOR CHECKING */
/*     ZEROS OUTSIDE THE PROFILE ARE THE CHARACTER '.' */
/*     MAKE ZEROS WITHIN THE PROFILE THE CHARACTER '0' */
/* SOURCE makpat.for:24 */
/*<       do100j=abs(jeq(1)),abs(jeq(eqlen)) >*/
    feq_gen_i_d_2 = (feq_gen_i_d_1 = jeq[*eqlen], abs(feq_gen_i_d_1));
    for (j = abs(jeq[1]); j <= feq_gen_i_d_2; ++j) {
/* SOURCE makpat.for:25 */
/*<       if(j.le.neq)then >*/
	if (j <= *neq) {
/* SOURCE makpat.for:26 */
/*<       cmat(neq,j)='0' >*/
	    *(unsigned char *)&cmat[*neq + j * 1013] = '0';
/* SOURCE makpat.for:27 */
/*<       endif >*/
	}
/* SOURCE makpat.for:28 */
/*<   100 continue >*/
/* L100: */
    }
/*     MAKE NON-ZEROS WITHIN THE PROFILE THE CHARACTER 'X' */
/* SOURCE makpat.for:31 */
/*<       do200k=1,eqlen >*/
    feq_gen_i_d_2 = *eqlen;
    for (k = 1; k <= feq_gen_i_d_2; ++k) {
/* SOURCE makpat.for:32 */
/*<       if(jeq(k).gt.0)then >*/
	if (jeq[k] > 0) {
/* SOURCE makpat.for:33 */
/*<       cmat(neq,jeq(k))='X' >*/
	    *(unsigned char *)&cmat[*neq + jeq[k] * 1013] = 'X';
/* SOURCE makpat.for:34 */
/*<       else >*/
	} else {
/* SOURCE makpat.for:35 */
/*<       cmat(neq,-jeq(k))='?' >*/
	    *(unsigned char *)&cmat[*neq + -jeq[k] * 1013] = '?';
/* SOURCE makpat.for:36 */
/*<       endif >*/
	}
/* SOURCE makpat.for:37 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE makpat.for:38 */
/*<       return >*/
    return 0;
/* SOURCE makpat.for:39 */
/*<       end >*/
} /* makpat_ */

#ifdef __cplusplus
	}
#endif
