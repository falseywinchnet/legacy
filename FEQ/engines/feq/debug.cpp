/* debug.f -- translated by f2c (version 20240504).
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

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;

/* Routines used in debugging */





/*      SUBROUTINE   BROUT */
/*     I                  (STDOUT, NBN, NBRA, BRPT) */

/* C     + + + PURPOSE + + + */
/* C     Output the branch information for debugging. */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER STDOUT, NBN, NBRA */
/*      INTEGER BRPT(8,NBRA) */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     STDOUT   - Fortran unit number for user output and messages */
/* C     NBN    - total number on nodes on branches in the model */
/* C     NBRA   - number of branches in the model */
/* C     BRPT   - branch pointer table.  Values for each branch are: */
/* C              ROW       Meaning */
/* C              1         upstream user node number */
/* C              2         downstream user node number */
/* C              3         pointer into branch vector for upstream node */
/* C              4         pointer into branch vector for downstream node */
/* C              5         upstream exterior node number */
/* C              6         downstream exterior node number */
/* C              7         pointer to address in EMC for the branch */
/* C              8         number of unknowns at a node for the branch */

/* C     + + + COMMON BLOCKS + + + */
/*      INCLUDE 'arsize.prm' */
/*      INCLUDE 'bnothr.cmn' */

/* C     + + + LOCAL VARIABLES + + + */
/*      INTEGER I, J */

/* C     + + + OUTPUT FORMATS + + + */
/* 74   FORMAT(///,' BRANCH INFORMATION'//,' BRANCH POINTER TABLE') */
/* 75   FORMAT(' ',' BRAN','   UN','   DN','   UP','   DP', */
/*     A ' UEXN',' DEXN') */
/* 76   FORMAT(' ',7I5) */
/* 77   FORMAT(/,'BRANCH VECTORS') */
/* 78   FORMAT(' ',' XSAD',7X,'UVX',7X,'UVY') */
/* 79   FORMAT(' ',I5,2F10.6) */
/* C*********************************************************************** */
/*      WRITE(STDOUT,74) */
/*      WRITE(STDOUT,75) */
/*         DO 500 I=1,NBRA */
/*         WRITE(STDOUT,76) I, (BRPT(J,I), J=1,6) */
/* 500     CONTINUE */
/*      WRITE(STDOUT,77) */
/*      WRITE(STDOUT,78) */
/*         DO 600 I=1,NBN */
/*         WRITE(STDOUT,79) NSEC(I), UVX(I), UVY(I) */
/* 600     CONTINUE */
/*      RETURN */
/*      END */



/* SOURCE debug.for:64 */
/*<       subroutinedmpjun(stdout,junknt,ljunp,junpnt,ljoin,join,lemc,emc) >*/
/* Subroutine */ int dmpjun_(integer *stdout, integer *junknt, integer *ljunp,
	 integer *feq_storage_junpnt, integer *ljoin, integer *feq_storage_join, integer *lemc, 
	integer *feq_storage_emc)
{
    /* Initialized data */

    static integer out = 0;

    /* Format strings */
    static char fmt_50[] = "(\002  NODE FLAG POINT LENGTH\002)";
    static char fmt_52[] = "(1x,a5,i5,i6,i7)";
    static char fmt_54[] = "(/,\002*WRN:13* Elevation relationship pattern m\
ay cause\002,\002 problems.\002,/,11x,\002Recast so that code 3 relationships\
\002,\002 are all tied\002,/,11x,\002to a single node.\002,/,\002 Nodes at j\
unction are:\002)";
    static char fmt_56[] = "(1x,a5)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, m, n, ie, nd, ij, is, knt, jpt, pnt, rpt, feq_gen_flag_d_, code, node,
	     length;
    extern integer fdnumr_(integer *, integer *, integer *, integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__2 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__3 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__4 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__26 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     Dump the junction contents for checking if output > 0. */
/* SOURCE debug.for:71 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE debug.for:73 */
/*<       integerjunknt,lemc,ljoin,ljunp,stdout >*/
/* SOURCE debug.for:74 */
/*<       integeremc(lemc),join(ljoin),junpnt(ljunp) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     JUNKNT - junction counter */
/*     LJUNP  - length of the junction pointer vector */
/*     JUNPNT - junction counter */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + SAVED VALUES + + + */
/* SOURCE debug.for:87 */
/*<       integerout >*/
/* SOURCE debug.for:88 */
/*<       saveout >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE debug.for:91 */
/*<       integercode,flag,i,ie,ij,is,jpt,knt,length,m,n,nd,node,pnt,rpt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE debug.for:95 */
/*<       integerfdnumr >*/
/* SOURCE debug.for:96 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE debug.for:99 */
/*<       externalfdnumr,getusn >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE debug.for:102 */
/*<       dataout/0/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> junpnt(feq_storage_junpnt, 1);

    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE debug.for:105 */
/*<    50 format('  NODE FLAG POINT LENGTH') >*/
/* L50: */
/* SOURCE debug.for:106 */
/*<    52 format(1x,a5,i5,i6,i7) >*/
/* L52: */
/* SOURCE debug.for:107 */
/*<    54  >*/
/* L54: */
/* SOURCE debug.for:111 */
/*<    56 format(1x,a5) >*/
/* L56: */
/* *********************************************************************** */
/* SOURCE debug.for:113 */
/*<       if(out.gt.0)then >*/
    if (out > 0) {
/* SOURCE debug.for:114 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__2.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__2);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE debug.for:115 */
/*<       write(stdout,*)'  DUMP OF JUNCTION DATA' >*/
	feq_gen_io_d__3.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__3);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  DUMP OF JUNCTION DATA"), (ftnlen)23);
	e_wsle();
/* SOURCE debug.for:116 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__4.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__4);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE debug.for:117 */
/*<       endif >*/
    }
/* SOURCE debug.for:119 */
/*<       do1000ij=1,junknt >*/
    feq_gen_i_d_1 = *junknt;
    for (ij = 1; ij <= feq_gen_i_d_1; ++ij) {
/* SOURCE debug.for:120 */
/*<       jpt=junpnt(ij) >*/
	jpt = junpnt[ij];
/* SOURCE debug.for:121 */
/*<       n=join(jpt) >*/
	n = join[jpt];
/* SOURCE debug.for:122 */
/*<       if(out.gt.0)then >*/
	if (out > 0) {
/* SOURCE debug.for:123 */
/*<       write(stdout,*)' ' >*/
	    feq_gen_io_d__8.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__8);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE debug.for:124 */
/*<       write(stdout,*)' ' >*/
	    feq_gen_io_d__9.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__9);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE debug.for:125 */
/*<       write(stdout,*)'  DATA FOR JUNCTION NUMBER ',ij,' JPT=',jpt >*/
	    feq_gen_io_d__10.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__10);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  DATA FOR JUNCTION NUMBER "), (ftnlen)27);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ij, (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" JPT="), (ftnlen)5);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&jpt, (ftnlen)sizeof(integer));
	    e_wsle();
/* SOURCE debug.for:126 */
/*<       write(stdout,*)'    JUNCTION HAS ',n,' NODES.' >*/
	    feq_gen_io_d__11.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__11);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("    JUNCTION HAS "), (ftnlen)17);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODES."), (ftnlen)7);
	    e_wsle();
/* SOURCE debug.for:127 */
/*<       write(stdout,*)' JUNCTION IS CODE:',emc(join(jpt+1)) >*/
	    feq_gen_io_d__12.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__12);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" JUNCTION IS CODE:"), (ftnlen)18);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&emc[join[jpt + 1]], (ftnlen)sizeof(
		    integer));
	    e_wsle();
/* SOURCE debug.for:129 */
/*<       write(stdout,*)' ' >*/
	    feq_gen_io_d__13.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__13);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE debug.for:130 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__14.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__14);
	    e_wsfe();
/* SOURCE debug.for:131 */
/*<       endif >*/
	}
/* SOURCE debug.for:132 */
/*<       is=jpt+4 >*/
	is = jpt + 4;
/* SOURCE debug.for:133 */
/*<       ie=is+n-1 >*/
	ie = is + n - 1;
/* SOURCE debug.for:134 */
/*<       do100i=is,ie >*/
	feq_gen_i_d_2 = ie;
	for (feq_gen_i_d_ = is; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE debug.for:135 */
/*<       node=join(i) >*/
	    node = join[feq_gen_i_d_];
/* SOURCE debug.for:136 */
/*<       flag=join(i+n) >*/
	    feq_gen_flag_d_ = join[feq_gen_i_d_ + n];
/* SOURCE debug.for:137 */
/*<       pnt=join(i+2*n) >*/
	    pnt = join[feq_gen_i_d_ + (n << 1)];
/* SOURCE debug.for:138 */
/*<       length=join(i+3*n) >*/
	    length = join[feq_gen_i_d_ + n * 3];
/* SOURCE debug.for:139 */
/*<       if(out.gt.0)then >*/
	    if (out > 0) {
/* SOURCE debug.for:140 */
/*<       write(stdout,52)getusn(node),flag,pnt,length >*/
		feq_gen_io_d__22.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__22);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &node);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_flag_d_, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&pnt, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&length, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE debug.for:141 */
/*<       endif >*/
	    }
/* SOURCE debug.for:142 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE debug.for:144 */
/*<       if(out.gt.0)then >*/
	if (out > 0) {
/* SOURCE debug.for:145 */
/*<       write(stdout,*)' RELATIONSHIPS INVOLVING THE NODES.' >*/
	    feq_gen_io_d__23.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__23);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" RELATIONSHIPS INVOLVING THE NODES."), (
		    ftnlen)35);
	    e_wsle();
/* SOURCE debug.for:146 */
/*<       endif >*/
	}
/* SOURCE debug.for:148 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE debug.for:149 */
/*<       do200i=is,ie >*/
	feq_gen_i_d_2 = ie;
	for (feq_gen_i_d_ = is; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE debug.for:150 */
/*<       node=join(i) >*/
	    node = join[feq_gen_i_d_];
/* SOURCE debug.for:151 */
/*<       m=fdnumr(node,jpt,ljoin,join) >*/
	    m = fdnumr_(&node, &jpt, ljoin, &join[1]);
/* SOURCE debug.for:152 */
/*<       if(m.gt.1)then >*/
	    if (m > 1) {
/*           COUNT NODES WITH MORE THAN TWO RELATIONSHIPS TIED TO THEM */
/* SOURCE debug.for:154 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE debug.for:155 */
/*<       endif >*/
	    }
/* SOURCE debug.for:156 */
/*<       pnt=join(i+2*n) >*/
	    pnt = join[feq_gen_i_d_ + (n << 1)];
/* SOURCE debug.for:157 */
/*<       if(out.gt.0)then >*/
	    if (out > 0) {
/* SOURCE debug.for:158 */
/*<       write(stdout,*)' ' >*/
		feq_gen_io_d__26.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__26);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
		e_wsle();
/* SOURCE debug.for:159 */
/*<       write(stdout,*)' NODE=',getusn(node) >*/
		feq_gen_io_d__27.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__27);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODE="), (ftnlen)6);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &node);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		e_wsle();
/* SOURCE debug.for:160 */
/*<       endif >*/
	    }
/* SOURCE debug.for:161 */
/*<   150 continue >*/
L150:
/* SOURCE debug.for:162 */
/*<       if(pnt.eq.0)then >*/
	    if (pnt == 0) {
/*           FINISHED WITH THIS NODE */
/* SOURCE debug.for:164 */
/*<       else >*/
	    } else {
/* SOURCE debug.for:165 */
/*<       rpt=join(pnt+1) >*/
		rpt = join[pnt + 1];
/* SOURCE debug.for:166 */
/*<       nd=join(pnt+2) >*/
		nd = join[pnt + 2];
/* SOURCE debug.for:167 */
/*<       pnt=join(pnt) >*/
		pnt = join[pnt];
/* SOURCE debug.for:168 */
/*<       code=emc(join(rpt)) >*/
		code = emc[join[rpt]];
/* SOURCE debug.for:169 */
/*<       if(out.gt.0)then >*/
		if (out > 0) {
/* SOURCE debug.for:170 */
/*<       write(stdout,*)' CODE=',code,' NODE2=',getusn(nd) >*/
		    feq_gen_io_d__31.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__31);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CODE="), (ftnlen)6);
		    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(
			    integer));
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODE2="), (ftnlen)7);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nd);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    e_wsle();
/* SOURCE debug.for:171 */
/*<       endif >*/
		}
/* SOURCE debug.for:172 */
/*<       goto150 >*/
		goto L150;
/* SOURCE debug.for:173 */
/*<       endif >*/
	    }
/* SOURCE debug.for:174 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE debug.for:175 */
/*<       if(knt.gt.1)then >*/
	if (knt > 1) {
/* SOURCE debug.for:176 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__32.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__32);
	    e_wsfe();
/* SOURCE debug.for:177 */
/*<       do210i=is,ie >*/
	    feq_gen_i_d_2 = ie;
	    for (feq_gen_i_d_ = is; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE debug.for:178 */
/*<       write(stdout,56)getusn(join(i)) >*/
		feq_gen_io_d__33.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__33);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &join[feq_gen_i_d_]);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		e_wsfe();
/* SOURCE debug.for:179 */
/*<   210 continue >*/
/* L210: */
	    }
/* SOURCE debug.for:180 */
/*<       endif >*/
	}
/* SOURCE debug.for:182 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE debug.for:183 */
/*<       return >*/
    return 0;
/* SOURCE debug.for:184 */
/*<       end >*/
} /* dmpjun_ */

/* C */
/* C */
/* C */
/*      SUBROUTINE   DPWOUT */
/*     I                   (DIFFUS, STDOUT, LPNT, MLPNT, NO, POINT, WIND, */
/*     I                    MF, PFPNT) */

/* C     + + + PURPOSE + + + */
/* C     Output diffuse, point and wind loading information for debug. */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER STDOUT, LPNT, MLPNT */
/*      INTEGER PFPNT(3,MLPNT) */
/*      REAL MF(MLPNT) */
/*      CHARACTER DIFFUS*4, NO*4, POINT*4, WIND*4 */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     DIFFUS - indicator if tributary area is present.  YES if so */
/* C     STDOUT   - Fortran unit number for user output and messages */
/* C     LPNT   - length of the point load point load array */
/* C     MLPNT  - maximum length of the point load pointer arrays */
/* C     NO     - character string 'NO' */
/* C     POINT  - if YES then point inflows to a branch are present */
/* C     WIND   - flag for presence of wind stress simulation */
/* C     MF     - momentum flux value */
/* C     PFPNT  - point flow pointer array */

/* C     + + + COMMON BLOCKS + + + */
/*      INCLUDE 'arsize.prm' */
/*      INCLUDE 'wincom.cmn' */

/* C     + + + LOCAL VARIABLES + + + */
/*      INTEGER I, J */

/* C     + + + OUTPUT FORMATS + + + */
/* 2100 FORMAT(///,' POINT FLOW INFORMATION') */
/* 2110 FORMAT(/,6X,' TYPE',' NTAB','  NBN','     MF     ') */
/* 2120 FORMAT(4I5,E12.5) */
/* 2200 FORMAT(///,' WIND LOADING INFORMATION') */
/* 2210 FORMAT(/,' WIND TABLE ADDRESS  = ',I5,/,1X, */
/*     A           'AIRWAT  = ',1PE10.3,/,1X, */
/*     C           'VELOCITY AT MIN CD  = ',0PF7.2,/,1X, */
/*     D           'MIN CD =',1PE10.3,/,1X, */
/*     E           'VELOCITY AT MAX CD =',0PF7.2,/,1X, */
/*     F           'MAX CD =',1PE10.3,/,1X, */
/*     G           'VADIF=',0PF7.2,/,1X, */
/*     H           'CDDIF=',1PE10.3) */
/* C*********************************************************************** */
/* C     DIFFUSE FLOWS */

/*      IF(DIFFUS.EQ.NO) GOTO 150 */
/* C          DUMMY FOR NOW. EXPAND LATER */
/* C     POINT FLOWS */

/* 150  CONTINUE */
/*      IF(POINT.EQ.NO) GOTO 210 */
/*      WRITE(STDOUT,2100) */
/*      WRITE(STDOUT,2110) */
/*      DO 200 I=1,LPNT */
/*        WRITE(STDOUT,2120) I, (PFPNT(J,I), J=1,3), MF(I) */
/* 200  CONTINUE */

/* C     WIND LOADING */

/* 210  CONTINUE */
/*      IF(WIND.EQ.NO) GOTO 220 */
/*      WRITE(STDOUT,2200) */
/*      WRITE(STDOUT,2210) WINTAB, AIRWAT, VAMIN, CDMIN, VAMAX, CDMAX, */
/*     A                 VADIF, CDDIF */

/* 220  CONTINUE */
/*      RETURN */
/*      END */



/* SOURCE debug.for:262 */
/*<       subroutinedumpit(conv,qeps,kount,stdout,nbra,nex,brpt,exnodt) >*/
/* Subroutine */ int dumpit_(real *conv, real *qeps, integer *kount, integer *
	stdout, integer *nbra, integer *nex, integer *feq_storage_brpt, integer *feq_storage_exnodt)
{
    /* Format strings */
    static char fmt_2000[] = "(\0021\002,/,\0020\002,\002DEBUG OUTPUT AT ITE\
RATION \002,i5,/,1x,\002MAXIMUM RELATIVE ERROR = \002,1pe12.5)";
    static char fmt_2010[] = "(/,\002 BRANCH NUMBER = \002,i5)";
    static char fmt_2020[] = "(/,\002 NODE\002,7x,\002Q2\002,10x,\002Q3\002,\
10x,\002Y2\002,10x,\002Y3\002)";
    static char fmt_2030[] = "(1x,i5,9(1pe12.5))";
    static char fmt_2040[] = "(//,\002 EXTERIOR NODES\002)";
    static char fmt_2050[] = "(/,\002 NODE\002,7x,\002QE2\002,10x,\002QE3\
\002,10x,\002YE2\002,10x,\002YE3\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer fa, la, nb, fn, nad;
    real arel, qrel, yrel;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_2020, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_2030, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_2040, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, fmt_2050, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_2030, 0 };


/*     + + + PURPOSE + + + */
/*     Outputs a summary of conditions at the end of an iteration. */
/* SOURCE debug.for:269 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE debug.for:271 */
/*<       integerkount,stdout,nbra,nex >*/
/* SOURCE debug.for:272 */
/*<       integerbrpt(8,nbra),exnodt(9,nex) >*/
/* SOURCE debug.for:273 */
/*<       realconv,qeps >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     CONV   - maximum relative error(correction) for current iteration */
/*     QEPS   - value of flow to prevent zero divide when computing */
/*               relative correction */
/*     KOUNT  - number of iterations to convergence or the maximum */
/*               number allowed */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
/*     EXNODT - exterior node table.  Contains the following items */
/*              for each exterior node. */
/*              Row   Content */
/*               1    sign of the node */
/*               2    pointer into vectors for nodes on a branch */
/*               3    descriptive code: if -1 then a reservoir; */
/*                    if  0 then not on a branch and not a reservoir; */
/*                    if > 0 then a branch number */
/*               4    pointer to a cross section table if on a branch, */
/*                    to storage table if a reservoir, to other node if */
/*                    a dummy branch */
/*               5    gives the variable number(in the system matrix) for */
/*                    the flow at the exterior node. Also a junction */
/*                    pointer in initial processing of input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE debug.for:310 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/* INCLUDE debug.for:311 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE debug.for:312 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE debug.for:315 */
/*<       integerfa,fn,la,nad,nb >*/
/* SOURCE debug.for:316 */
/*<       realarel,qrel,yrel >*/
/*     + + + INTRINSICS + + + */
/* SOURCE debug.for:319 */
/*<       intrinsicabs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE debug.for:322 */
/*<  2000  >*/
/* SOURCE debug.for:324 */
/*<  2010 format(/,' BRANCH NUMBER = ',i5) >*/
/* SOURCE debug.for:325 */
/*<  2020 format(/,' NODE',7x,'Q2',10x,'Q3',10x,'Y2',10x,'Y3') >*/
/* SOURCE debug.for:326 */
/*<  2030 format(1x,i5,9(1pe12.5)) >*/
/* SOURCE debug.for:327 */
/*<  2040 format(//,' EXTERIOR NODES') >*/
/* SOURCE debug.for:328 */
/*<  2050 format(/,' NODE',7x,'QE2',10x,'QE3',10x,'YE2',10x,'YE3') >*/
/* *********************************************************************** */
/*     TITLE */
/* SOURCE debug.for:332 */
/*<       write(stdout,2000)kount,conv >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
/* L2000: */
/* L2010: */
/* L2020: */
/* L2030: */
/* L2040: */
/* L2050: */
    feq_gen_io_d__34.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__34);
    do_fio(&feq_gen_c_d_1, (char *)&(*kount), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&(*conv), (ftnlen)sizeof(real));
    e_wsfe();
/*     WRITE OUT VALUES ETC FOR INTERIOR NODES */
/*     I) BRANCH LOOP */
/* SOURCE debug.for:338 */
/*<       do100nb=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE debug.for:339 */
/*<       fn=brpt(1,nb)-1 >*/
	fn = brpt[(nb << 3) + 1] - 1;
/* SOURCE debug.for:340 */
/*<       fa=brpt(3,nb) >*/
	fa = brpt[(nb << 3) + 3];
/* SOURCE debug.for:341 */
/*<       la=brpt(4,nb) >*/
	la = brpt[(nb << 3) + 4];
/* SOURCE debug.for:342 */
/*<       write(stdout,2010)nb >*/
	feq_gen_io_d__39.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__39);
	do_fio(&feq_gen_c_d_1, (char *)&nb, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE debug.for:343 */
/*<       write(stdout,2020) >*/
	feq_gen_io_d__40.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__40);
	e_wsfe();
/*       II) NODE LOOP */
/* SOURCE debug.for:347 */
/*<       do50nad=fa,la >*/
	feq_gen_i_d_2 = la;
	for (nad = fa; nad <= feq_gen_i_d_2; ++nad) {
/* SOURCE debug.for:348 */
/*<       fn=fn+1 >*/
	    ++fn;
/* SOURCE debug.for:349 */
/*<       qrel=abs(q2(nad)-q3(nad))/(abs(q3(nad))+qeps) >*/
	    qrel = (feq_gen_r_d_2 = static_cast<double>(bnelem_1.q2[nad - 1]) - bnelem_1.q3[nad - 1], dabs(
		    feq_gen_r_d_2)) / ((feq_gen_r_d_1 = bnelem_1.q3[nad - 1], dabs(feq_gen_r_d_1)) + *
		    qeps);
/* SOURCE debug.for:350 */
/*<       arel=abs((y2(nad)-y3(nad))/y3(nad)) >*/
	    arel = (feq_gen_r_d_1 = static_cast<double>((static_cast<double>(bnelem_1.y2[nad - 1]) - bnelem_1.y3[nad - 1])) / 
		    bnelem_1.y3[nad - 1], dabs(feq_gen_r_d_1));
/* SOURCE debug.for:351 */
/*<       write(stdout,2030)fn,q2(nad),q3(nad),y2(nad),y3(nad),qrel,arel >*/
	    feq_gen_io_d__44.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__44);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.q2[nad - 1], (ftnlen)sizeof(real))
		    ;
	    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.q3[nad - 1], (ftnlen)sizeof(real))
		    ;
	    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.y2[nad - 1], (ftnlen)sizeof(real))
		    ;
	    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.y3[nad - 1], (ftnlen)sizeof(real))
		    ;
	    do_fio(&feq_gen_c_d_1, (char *)&qrel, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&arel, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE debug.for:353 */
/*<    50 continue >*/
/* L50: */
	}
/* SOURCE debug.for:354 */
/*<   100 continue >*/
/* L100: */
    }
/*     WRITE OUT VALUES FOR EXTERIOR NODES-FREE NODES ONLY */
/* SOURCE debug.for:358 */
/*<       write(stdout,2040) >*/
    feq_gen_io_d__45.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__45);
    e_wsfe();
/* SOURCE debug.for:359 */
/*<       write(stdout,2050) >*/
    feq_gen_io_d__46.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__46);
    e_wsfe();
/* SOURCE debug.for:360 */
/*<       do200nad=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (nad = 1; nad <= feq_gen_i_d_1; ++nad) {
/* SOURCE debug.for:361 */
/*<       if(exnodt(3,nad).le.0)then >*/
	if (exnodt[nad * 9 + 3] <= 0) {
/* SOURCE debug.for:362 */
/*<       yrel=abs((ye2(nad)-ye3(nad))/ye3(nad)) >*/
	    yrel = (feq_gen_r_d_1 = static_cast<double>((static_cast<double>(enelem_1.ye2[nad - 1]) - enelem_1.ye3[nad - 1])) / 
		    enelem_1.ye3[nad - 1], dabs(feq_gen_r_d_1));
/* SOURCE debug.for:363 */
/*<       qrel=abs(qe2(nad)-qe3(nad))/(abs(qe3(nad))+qeps) >*/
	    qrel = (feq_gen_r_d_2 = static_cast<double>(enelem_1.qe2[nad - 1]) - enelem_1.qe3[nad - 1], 
		    dabs(feq_gen_r_d_2)) / ((feq_gen_r_d_1 = enelem_1.qe3[nad - 1], dabs(feq_gen_r_d_1)) 
		    + *qeps);
/* SOURCE debug.for:364 */
/*<        >*/
	    feq_gen_io_d__48.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__48);
	    do_fio(&feq_gen_c_d_1, (char *)&nad, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&enelem_1.qe2[nad - 1], (ftnlen)sizeof(real)
		    );
	    do_fio(&feq_gen_c_d_1, (char *)&enelem_1.qe3[nad - 1], (ftnlen)sizeof(real)
		    );
	    do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ye2[nad - 1], (ftnlen)sizeof(real)
		    );
	    do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ye3[nad - 1], (ftnlen)sizeof(real)
		    );
	    do_fio(&feq_gen_c_d_1, (char *)&qrel, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&yrel, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE debug.for:366 */
/*<       endif >*/
	}
/* SOURCE debug.for:367 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE debug.for:368 */
/*<       return >*/
    return 0;
/* SOURCE debug.for:369 */
/*<       end >*/
} /* dumpit_ */




/*      SUBROUTINE   EXOUT */
/*     I                  (STDOUT, EPT, NEX, EMC, EXNODT) */

/* C     + + + PURPOSE + + + */
/* C     Output the exterior node table and the network-matrix */
/* C     control vector information */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER EPT, STDOUT, NEX */
/*      INTEGER EMC(EPT), EXNODT(9,NEX) */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     STDOUT   - Fortran unit number for user output and messages */
/* C     EPT    - current length of EMC(*) */
/* C     NEX    - number of exterior nodes in the model */
/* C     EMC    - vector containing coded form of the Matrix Control Input */
/* C     EXNODT - exterior node table.  Contains the following items */
/* C              for each exterior node. */
/* C              Row   Content */
/* C               1    sign of the node */
/* C               2    pointer into vectors for nodes on a branch */
/* C               3    descriptive code: if -1 then a reservoir; */
/* C                    if  0 then not on a branch and not a reservoir; */
/* C                    if > 0 then a branch number */
/* C               4    pointer to a cross section table if on a branch, */
/* C                    to storage table if a reservoir, to other node if */
/* C                    a dummy branch */
/* C               5    gives the variable number(in the system matrix) for */
/* C                    the flow at the exterior node. Also a junction */
/* C                    pointer in initial processing of input */

/* C     + + + LOCAL VARIABLES + + + */
/*      INTEGER I, IDUM, J */
/*      REAL RDUM */

/* C     + + + EQUIVALENCES + + + */
/*      EQUIVALENCE (RDUM,IDUM) */

/* C     + + + OUTPUT FORMATS + + + */
/* 40     FORMAT(I5,I10,F10.2) */
/* 80   FORMAT(///,' EXNODT',/,' NODE',' SIGN',' IPNT',' BRAN',' XSAD') */
/* 81   FORMAT(' ',5I5) */
/* 82   FORMAT(///,' NETWORK-MATRIX CONTROL') */
/* C*********************************************************************** */
/*      WRITE(STDOUT,80) */
/*         DO 500 I=1,NEX */
/*         WRITE(STDOUT,81) I, (EXNODT(J,I), J=1,4) */
/* 500     CONTINUE */

/*      WRITE(STDOUT,82) */

/*        DO 100 I=1,EPT */
/*        IDUM = EMC(I) */
/*        WRITE(STDOUT,40) I, IDUM, RDUM */
/* 100    CONTINUE */
/*        RETURN */
/*      END */



/* SOURCE debug.for:434 */
/*<       character*63functionfndemc(emcadr,lemc,emc) >*/
/* Character */ VOID fndemc_(char *ret_val, ftnlen ret_val_len, integer *
	emcadr, integer *lemc, integer *feq_storage_emc)
{
    /* Format strings */
    static char fmt_50[] = "(\002 Code=\002,i3,\002 Bra=\002,i5)";
    static char fmt_52[] = "(\002 Code=\002,i3,9(1x,a5))";
    static char fmt_54[] = "(\002 Code=\002,i3,2(1x,a5))";
    static char fmt_56[] = "(\002 Code=\002,i3,\002 Hd Node=\002,a5,\002 Qno\
de=\002,a5)";
    static char fmt_58[] = "(\002 Code=\002,i3,\002 Unn=\002,a5,\002 Dnn=\
\002,a5,\002 Qnn=\002,a5)";
    static char fmt_60[] = "(\002 Code=\002,i3,1x,a5)";
    static char fmt_62[] = "(\002 Code=\002,i3,\002 Node=\002,a5,1x,a5,1x,i5)"
	    ;
    static char fmt_64[] = "(\002 Code=\002,i3,1x,a5)";
    static char fmt_66[] = "(\002 Code=\002,i3,1x,a5,1x,a5)";
    static char fmt_68[] = "(\002 Code=\002,i3,1x,a5,1x,a5,1x,a5)";
    static char fmt_70[] = "(\002 Code=\002,i3,1x,a5,1x,a5,1x,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5], feq_gen_ch_d_5[5], feq_gen_ch_d_6[5], feq_gen_ch_d_7[5];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer j, n, it, dnn, nbr, num, unn, code, ipnt, qnode;
    extern integer getusb_(integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__51 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Get summary of an EMC entry for debugging MAKEMC and return */
/*     in a character string ready for printing. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE debug.for:442 */
/*<       integeremcadr,lemc >*/
/* SOURCE debug.for:443 */
/*<       integeremc(lemc) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     EMCADR - address of relationship in EMC(*) */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE debug.for:451 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE debug.for:454 */
/*<       integercode,dnn,ipnt,it,j,n,nbr,num,qnode,unn >*/
/*     + + + INTRINSICS + + + */
/* SOURCE debug.for:457 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE debug.for:460 */
/*<       integergetusb >*/
/* SOURCE debug.for:461 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE debug.for:464 */
/*<       externalgetusb,getusn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE debug.for:467 */
/*<    50 format(' Code=',i3,' Bra=',i5) >*/
/* SOURCE debug.for:468 */
/*<    52 format(' Code=',i3,9(1x,a5)) >*/
/* SOURCE debug.for:469 */
/*<    54 format(' Code=',i3,2(1x,a5)) >*/
/* SOURCE debug.for:470 */
/*<    56 format(' Code=',i3,' Hd Node=',a5,' Qnode=',a5) >*/
/* SOURCE debug.for:471 */
/*<    58 format(' Code=',i3,' Unn=',a5,' Dnn=',a5,' Qnn=',a5) >*/
/* SOURCE debug.for:472 */
/*<    60 format(' Code=',i3,1x,a5) >*/
/* SOURCE debug.for:473 */
/*<    62 format(' Code=',i3,' Node=',a5,1x,a5,1x,i5) >*/
/* SOURCE debug.for:474 */
/*<    64 format(' Code=',i3,1x,a5) >*/
/* SOURCE debug.for:475 */
/*<    66 format(' Code=',i3,1x,a5,1x,a5) >*/
/* SOURCE debug.for:476 */
/*<    68 format(' Code=',i3,1x,a5,1x,a5,1x,a5) >*/
/* SOURCE debug.for:477 */
/*<    70 format(' Code=',i3,1x,a5,1x,a5,1x,i5) >*/
/* *********************************************************************** */
/*     INITIALIZE VARIABLES */
/*     CODE FROM MATRIX CONTROL VECTOR */
/* SOURCE debug.for:483 */
/*<       ipnt=emcadr >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

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
/* L70: */
    ipnt = *emcadr;
/* SOURCE debug.for:484 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE debug.for:486 */
/*<        >*/
    switch (code) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
	case 10:  goto L950;
	case 11:  goto L950;
	case 12:  goto L1200;
	case 13:  goto L950;
	case 14:  goto L1200;
	case 15:  goto L1500;
    }
/* SOURCE debug.for:488 */
/*<       write(std6,*)' *BUG:05* INVALID EMC CODE IN FNDEMC. CODE=',code >*/
    feq_gen_io_d__51.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsle(&feq_gen_io_d__51);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:05* INVALID EMC CODE IN FNDEMC. CODE="), (
	    ftnlen)43);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE debug.for:490 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/*     CODE 1 GIVES BRANCH NUMBERS */
/* SOURCE debug.for:494 */
/*<   100 continue >*/
L100:
/* SOURCE debug.for:496 */
/*<       nbr=emc(ipnt+1) >*/
    nbr = emc[ipnt + 1];
/* SOURCE debug.for:497 */
/*<       if(nbr.lt.0)then >*/
    if (nbr < 0) {
/* SOURCE debug.for:498 */
/*<       it=-getusb(abs(nbr)) >*/
	feq_gen_i_d_1 = abs(nbr);
	it = -getusb_(&feq_gen_i_d_1);
/* SOURCE debug.for:499 */
/*<       else >*/
    } else {
/* SOURCE debug.for:500 */
/*<       it=getusb(nbr) >*/
	it = getusb_(&nbr);
/* SOURCE debug.for:501 */
/*<       endif >*/
    }
/* SOURCE debug.for:502 */
/*<       write(fndemc,50)code,it >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_50;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE debug.for:503 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 2 GIVES DISCHARGE CONTINUITY AT JUNCTIONS. NO VARIABLE */
/*     NUMBER ASSIGNMENTS.  UPDATE EQUATION COUNT */
/* SOURCE debug.for:508 */
/*<   200 continue >*/
L200:
/* SOURCE debug.for:510 */
/*<       n=emc(ipnt+1) >*/
    n = emc[ipnt + 1];
/* SOURCE debug.for:511 */
/*<       write(fndemc,52)code,(getusn(emc(ipnt+1+j)),j=1,n) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_52;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[ipnt + 1 + j]);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    }
    e_wsfi();
/* SOURCE debug.for:512 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 3 - GIVES ELEVATION EQUALITY. CHECK FOR NON-RESERVOIR */
/*     NODES NOT ON A BRANCH. */
/* SOURCE debug.for:517 */
/*<   300 continue >*/
L300:
/* SOURCE debug.for:518 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE debug.for:519 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/* SOURCE debug.for:520 */
/*<       write(fndemc,54)code,getusn(unn),getusn(dnn) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_54;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &unn);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
    e_wsfi();
/* SOURCE debug.for:521 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 4 - CONTROL STRUCTURE WITH 1 NODE HEAD DISCHARGE */
/*     UNN = UPSTREAM NODE FOR HEAD */
/*     DNN = NODE FOR DISCHARGE */
/* SOURCE debug.for:527 */
/*<   400 continue >*/
L400:
/* SOURCE debug.for:528 */
/*<       unn=emc(ipnt+2) >*/
    unn = emc[ipnt + 2];
/* SOURCE debug.for:529 */
/*<       qnode=emc(ipnt+4) >*/
    qnode = emc[ipnt + 4];
/* SOURCE debug.for:530 */
/*<       write(fndemc,56)code,getusn(unn),getusn(qnode) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_56;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &unn);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    getusn_(feq_gen_ch_d_5, (ftnlen)5, &qnode);
    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
    e_wsfi();
/* SOURCE debug.for:531 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 5 - CONTROL STRUCTURE WITH 2 NODE HEAD DISCHARGE */
/* SOURCE debug.for:534 */
/*<   500 continue >*/
L500:
/* SOURCE debug.for:537 */
/*<       unn=emc(ipnt+2) >*/
    unn = emc[ipnt + 2];
/* SOURCE debug.for:538 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[ipnt + 3];
/* SOURCE debug.for:539 */
/*<       qnode=emc(ipnt+4) >*/
    qnode = emc[ipnt + 4];
/* SOURCE debug.for:540 */
/*<       write(fndemc,58)code,getusn(unn),getusn(dnn),getusn(qnode) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_58;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &unn);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
    getusn_(feq_gen_ch_d_7, (ftnlen)5, &qnode);
    s_copy(feq_gen_ch_d_6, feq_gen_ch_d_7, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_6, (ftnlen)5);
    e_wsfi();
/* SOURCE debug.for:541 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 6 - GIVES DETAILS OF FORCED BOUNDARY */
/* SOURCE debug.for:545 */
/*<   600 continue >*/
L600:
/* SOURCE debug.for:546 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/* SOURCE debug.for:547 */
/*<       write(fndemc,60)code,getusn(dnn) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_60;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &dnn);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    e_wsfi();
/* SOURCE debug.for:549 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 7 - LEVEL POOL RESERVOIR */
/*     DNN = NODE OF RESERVOIR */
/* SOURCE debug.for:554 */
/*<   700 continue >*/
L700:
/* SOURCE debug.for:555 */
/*<       dnn=emc(ipnt+1) >*/
    dnn = emc[ipnt + 1];
/* SOURCE debug.for:556 */
/*<       write(fndemc,62)code,getusn(dnn),getusn(emc(ipnt+5)),emc(ipnt+6) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_62;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &dnn);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    getusn_(feq_gen_ch_d_5, (ftnlen)5, &emc[ipnt + 5]);
    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&emc[ipnt + 6], (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE debug.for:558 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 8 - CRITICAL DEPTH CONDITION */
/*     NUM = NODE NUMBER */
/* SOURCE debug.for:563 */
/*<   800 continue >*/
L800:
/* SOURCE debug.for:564 */
/*<       num=emc(ipnt+1) >*/
    num = emc[ipnt + 1];
/* SOURCE debug.for:565 */
/*<       write(fndemc,64)code,getusn(num) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_64;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &num);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    e_wsfi();
/* SOURCE debug.for:566 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 9 MOMENTUM JUNCTION- NOT COMPLETE */
/* SOURCE debug.for:571 */
/*<   900 continue >*/
L900:
/* SOURCE debug.for:572 */
/*<       write(std6,*)' SHOULD NOT GET HERE. FUNCTION FNDEMC.' >*/
    feq_gen_io_d__60.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsle(&feq_gen_io_d__60);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SHOULD NOT GET HERE. FUNCTION FNDEMC."), (ftnlen)38)
	    ;
    e_wsle();
/* SOURCE debug.for:573 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/*     CODE 10 - EQUALITY OF ELEVATION OF TOTAL ENERGY LINE */
/* SOURCE debug.for:579 */
/*<   950 continue >*/
L950:
/* SOURCE debug.for:580 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE debug.for:581 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/* SOURCE debug.for:582 */
/*<       write(fndemc,66)code,getusn(unn),getusn(dnn) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_66;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &unn);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
    e_wsfi();
/* SOURCE debug.for:583 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE debug.for:585 */
/*<  1200 continue >*/
L1200:
/*       THREE NODES INVOLVED HERE. */
/* SOURCE debug.for:587 */
/*<       write(fndemc,68)code,(getusn(emc(ipnt+j)),j=1,3) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_68;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    for (j = 1; j <= 3; ++j) {
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[ipnt + j]);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    }
    e_wsfi();
/* SOURCE debug.for:588 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE debug.for:590 */
/*<  1500 continue >*/
L1500:
/*       NULL BRANCH */
/* SOURCE debug.for:592 */
/*<        >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 63;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_70;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[ipnt + 1]);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    getusn_(feq_gen_ch_d_5, (ftnlen)5, &emc[ipnt + 2]);
    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&emc[ipnt + 3], (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE debug.for:594 */
/*<  9000 continue >*/
L9000:
/* SOURCE debug.for:596 */
/*<       return >*/
    return ;
/* SOURCE debug.for:597 */
/*<       end >*/
} /* fndemc_ */




/*      SUBROUTINE   FTOUT */
/*     I                  (STDOUT, */
/*     M                   OUTPUT) */

/* C     + + + PURPOSE + + + */
/* C     Output the function tables for debugging. */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER STDOUT, OUTPUT */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     STDOUT   - Fortran unit number for user output and messages */
/* C     OUTPUT - output level for diagnostic work */

/* C     + + + COMMON BLOCKS + + + */
/*      INCLUDE 'arsize.prm' */
/*      INCLUDE 'ftable.cmn' */

/* C     + + + LOCAL VARIABLES + + + */
/*      INTEGER FTP, HA, I, J, K, LA, NTAB, TYPE */

/* C     + + + OUTPUT FORMATS + + + */
/* 60   FORMAT(///,' FUNCTION TABLES') */
/* 61   FORMAT(' ','*BUG:22* ADDRESSING BUG FOR TABLES*',2I5) */
/* 62   FORMAT(' ','*BUG:23* TABLE TYPE INVALID:',I5) */
/* 63   FORMAT(/,'TABLE = ',I5,/,' TYPE = ',I5,/,' FIRST ADD = ',I5,/, */
/*     A      ' HIGH ADD = ',I5,/,' LAST ADD = ',I5) */
/* 64   FORMAT(' ','STATION = ',F15.3,' ELEVATION = ',F10.2) */
/* 65   FORMAT(' ',F7.3,F9.2,1P2E11.4,0PF7.3,1P2E11.4) */
/* 66   FORMAT(' ','REFERENCE LEVEL = ',F10.2) */
/* 67   FORMAT(/,'  ARGUMENT',' FUNCTION VALUE') */
/* 68   FORMAT(' ',F10.2,2(1PE15.5)) */
/* 69   FORMAT(/,'  ARGUMENT    FUNCTION1        FUNCTION2') */
/* 641  FORMAT(/,2X,'DEPTH',' TOPWIDTH',7X,'AREA',4X,'CONVFAC', */
/*     1  3X,'BETA',8X,'YBA',9X,'SJ') */
/* C*********************************************************************** */
/*      IF(OUTPUT.GT.0) */
/*     1   WRITE(STDOUT,60) */

/*         DO 3000 I=1,MFTNUM */
/*         FTP = FTPNT(I) */
/*         IF(FTP.EQ.0) GOTO 3000 */

/* C           TABLE EXISTS */

/*            NTAB = ITAB(FTP+1) */
/*            IF(NTAB.EQ.I) GOTO 100 */
/*               WRITE(STDOUT,61) NTAB, I */
/* 100        CONTINUE */
/*            TYPE = ITAB(FTP+2) */
/*            IF(OUTPUT.GT.0) */
/*     1         WRITE(STDOUT,63) NTAB, TYPE, FTP, ITAB(FTP), ITAB(FTP+3) */
/*            IF(TYPE.GE.1 .AND. TYPE.LE.4) GOTO 500 */
/*            WRITE(STDOUT,62) TYPE */
/*            GOTO 1000 */
/* 500        GOTO(1,2,3,3),TYPE */
/*         WRITE(STDOUT,*) ' *BUG:24* INVALID TABLE TYPE IN FTOUT. TYPE=', */
/*     A               TYPE */
/*              STOP 'Abnormal stop: errors found.' */

/* 1          CONTINUE */
/*               IF(OUTPUT.GT.0) */
/*     1            WRITE(STDOUT,64) FTAB(FTP+4), FTAB(FTP+5) */
/*               IF(OUTPUT.GT.0) */
/*     1            WRITE(STDOUT,641) */
/*               LA = FTP+6 */
/*               HA = ITAB(FTP) */
/*               IF(OUTPUT.EQ.0) GOTO 1000 */
/*                  DO 200 J=LA,HA,6 */
/*                  WRITE(STDOUT,65) (FTAB(J+K-1), K=1,6) */
/* 200              CONTINUE */
/*               GOTO 1000 */
/* 2          CONTINUE */
/*               IF(OUTPUT.GT.0) */
/*     1            WRITE(STDOUT,66) FTAB(FTP+4) */
/*               IF(OUTPUT.GT.0) */
/*     1            WRITE(STDOUT,67) */
/*               LA = FTP+5 */
/*               HA = ITAB(FTP) */
/*               IF(OUTPUT.EQ.0) GOTO 1000 */
/*                  DO 300 J=LA,HA,2 */
/*                  WRITE(STDOUT,68) (FTAB(J+K-1), K=1,2) */
/* 300              CONTINUE */
/*               GOTO 1000 */
/* 3          CONTINUE */
/*               IF(OUTPUT.GT.0) */
/*     1            WRITE(STDOUT,66) FTAB(FTP+4) */
/*               IF(OUTPUT.GT.0) */
/*     1            WRITE(STDOUT,69) */
/*               LA = FTP+ 5 */
/*               HA = ITAB(FTP) */
/*               IF(OUTPUT.EQ.0) GOTO 1000 */
/*               DO 400 J=LA,HA,3 */
/*                  WRITE(STDOUT,68) (FTAB(J+K-1), K=1,3) */
/* 400           CONTINUE */
/*               GOTO 1000 */
/* 1000       CONTINUE */
/* 3000    CONTINUE */
/*      IF(OUTPUT.EQ.0) OUTPUT = 1 */
/*      RETURN */
/*      END */



/*      SUBROUTINE   INOUT */
/*     I                  (STDOUT, NBRA, NEX, BRPT) */

/* C     + + + PURPOSE + + + */
/* C     Output a summary of initial conditions for debugging purposes. */

/*      IMPLICIT NONE */
/* C     + + + DUMMY ARGUMENTS + + + */
/*      INTEGER STDOUT, NBRA, NEX */
/*      INTEGER BRPT(8,NBRA) */

/* C     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/* C     STDOUT   - Fortran unit number for user output and messages */
/* C     NBRA   - number of branches in the model */
/* C     NEX    - number of exterior nodes in the model */
/* C     BRPT   - branch pointer table.  Values for each branch are: */
/* C              ROW       Meaning */
/* C              1         upstream user node number */
/* C              2         downstream user node number */
/* C              3         pointer into branch vector for upstream node */
/* C              4         pointer into branch vector for downstream node */
/* C              5         upstream exterior node number */
/* C              6         downstream exterior node number */
/* C              7         pointer to address in EMC for the branch */
/* C              8         number of unknowns at a node for the branch */

/* C     + + + COMMON BLOCKS + + + */
/*      INCLUDE 'arsize.prm' */
/*      INCLUDE 'bnelem.cmn' */
/*      INCLUDE 'enelem.cmn' */

/* C     + + + LOCAL VARIABLES + + + */
/*      INTEGER FA, FN, LA, NAD, NB */

/* C     + + + OUTPUT FORMATS + + + */
/* 2000 FORMAT('1',/,/,' DEBUG OUTPUT FOR INITIAL CONDITIONS') */
/* 2010 FORMAT(/,'BRANCH NUMBER = ',I5) */
/* 2020 FORMAT(/,' NODE',10X,'Q1',10X,'Y1',10X,'A1',10X,'DX', */
/*     A           10X,'DZ') */
/* 2030 FORMAT(1X,I5,5(1PE12.5)) */
/* 2040 FORMAT(//,' EXTERIOR NODES') */
/* 2050 FORMAT(/,'NODE',5X,'QE1',8X,'YE1',8X,'AE1',8X,'ZE') */
/* C*********************************************************************** */
/* C     TITLE */

/*      WRITE(STDOUT,2000) */

/* C     WRITE OUT INITIAL CONDITIONS ETC FOR INTERIOR NODES */

/* C     I) BRANCH LOOP */

/*      DO 100 NB=1,NBRA */
/*        FN = BRPT(1,NB) - 1 */
/*        FA = BRPT(3,NB) */
/*        LA = BRPT(4,NB) */
/*        WRITE(STDOUT,2010) NB */
/*        WRITE(STDOUT,2020) */

/* C       II) NODE LOOP */

/*        DO 50 NAD=FA,LA */
/*          FN = FN + 1 */
/*          WRITE(STDOUT,2030) FN, Q1(NAD), Y1(NAD), A1(NAD), DXVEC(NAD), */
/*     A                     DZVEC(NAD) */
/* 50     CONTINUE */
/* 100  CONTINUE */

/* C     WRITE OUT INITIAL CONDITIONS FOR EXTERIOR NODES */

/*      WRITE(STDOUT,2040) */
/*      WRITE(STDOUT,2050) */
/*      DO 200 NAD=1,NEX */
/*        WRITE(STDOUT,2030) NAD, QE1(NAD), YE1(NAD), AE1(NAD), ZE(NAD) */
/* 200  CONTINUE */
/*      RETURN */
/*      END */



/* SOURCE debug.for:785 */
/*<       subroutineqpvout(nbra,nbn,stdout,brpt,qpvec,nrwta,rwta,rtap) >*/
/* Subroutine */ int qpvout_(integer *nbra, integer *nbn, integer *stdout, 
	integer *feq_storage_brpt, real *feq_storage_qpvec, integer *nrwta, integer *feq_storage_rwta, integer *
	feq_storage_rtap)
{
    /* Format strings */
    static char fmt_4900[] = "(/,\002 BRANCH = \002,i5)";
    static char fmt_4901[] = "(\002 \002,i5,1pe13.6)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, j, ij, jend, jstart;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_4900, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_4901, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_4900, 0 };
    static cilist feq_gen_io_d__69 = { 0, 0, 0, fmt_4901, 0 };


/*     + + + PURPOSE + + + */
/*     Output QPVEC(*) for checking. */
/* SOURCE debug.for:792 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE debug.for:794 */
/*<       integerstdout,nbn,nbra,nrwta >*/
/* SOURCE debug.for:795 */
/*<       integerbrpt(8,nbra),rtap(nrwta),rwta(nrwta) >*/
/* SOURCE debug.for:796 */
/*<       realqpvec(nbn) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
/*     QPVEC  - lateral inflows for a time step */
/*     NRWTA  - number of reservoirs with tributary area */
/*     RWTA   - reservoirs with tributary area */
/*     RTAP   - reservoir tributary area pointer */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE debug.for:818 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE debug.for:821 */
/*<       integeri,ij,j,jend,jstart >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE debug.for:824 */
/*<  4900 format(/,' BRANCH = ',i5) >*/
/* SOURCE debug.for:825 */
/*<  4901 format(' ',i5,1pe13.6) >*/
/* *********************************************************************** */
/* SOURCE debug.for:827 */
/*<       if(nrwta.gt.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<real> qpvec(feq_storage_qpvec, 1);

    feq::IndexedPointer<integer> rtap(feq_storage_rtap, 1);

    feq::IndexedPointer<integer> rwta(feq_storage_rwta, 1);

    /* Function Body */
/* L4900: */
/* L4901: */
    if (*nrwta > 0) {
/* SOURCE debug.for:828 */
/*<       i=0 >*/
	feq_gen_i_d_ = 0;
/* SOURCE debug.for:829 */
/*<       write(stdout,4900)i >*/
	feq_gen_io_d__62.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE debug.for:830 */
/*<       do4100i=1,nrwta >*/
	feq_gen_i_d_1 = *nrwta;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE debug.for:831 */
/*<       write(stdout,4901)rwta(i),qpvec(rtap(i)) >*/
	    feq_gen_io_d__63.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__63);
	    do_fio(&feq_gen_c_d_1, (char *)&rwta[feq_gen_i_d_], (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&qpvec[rtap[feq_gen_i_d_]], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE debug.for:832 */
/*<  4100 continue >*/
/* L4100: */
	}
/* SOURCE debug.for:833 */
/*<       endif >*/
    }
/* SOURCE debug.for:835 */
/*<       do4200i=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE debug.for:836 */
/*<       write(stdout,4900)i >*/
	feq_gen_io_d__64.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__64);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE debug.for:837 */
/*<       jstart=brpt(3,i)+1 >*/
	jstart = brpt[(feq_gen_i_d_ << 3) + 3] + 1;
/* SOURCE debug.for:838 */
/*<       jend=brpt(4,i) >*/
	jend = brpt[(feq_gen_i_d_ << 3) + 4];
/* SOURCE debug.for:839 */
/*<       ij=brpt(1,i)+1 >*/
	ij = brpt[(feq_gen_i_d_ << 3) + 1] + 1;
/* SOURCE debug.for:840 */
/*<       do4150j=jstart,jend >*/
	feq_gen_i_d_2 = jend;
	for (j = jstart; j <= feq_gen_i_d_2; ++j) {
/* SOURCE debug.for:841 */
/*<       write(stdout,4901)ij,qpvec(j) >*/
	    feq_gen_io_d__69.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__69);
	    do_fio(&feq_gen_c_d_1, (char *)&ij, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&qpvec[j], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE debug.for:842 */
/*<       ij=ij+1 >*/
	    ++ij;
/* SOURCE debug.for:843 */
/*<  4150 continue >*/
/* L4150: */
	}
/* SOURCE debug.for:844 */
/*<  4200 continue >*/
/* L4200: */
    }
/* SOURCE debug.for:846 */
/*<       return >*/
    return 0;
/* SOURCE debug.for:847 */
/*<       end >*/
} /* qpvout_ */




/* SOURCE debug.for:851 */
/*<        >*/
/* Subroutine */ int feq_gen_find_volumes_d_(integer *nbra, integer *nbn, integer *nex,
	 integer *resnum, integer *feq_gen_dlay_knt_d_, integer *feq_gen_dten_knt_d_, integer *
	feq_storage_brpt, integer *feq_storage_resvec, real *feq_storage_dxvec, real *feq_storage_a, real *feq_storage_ae, real *feq_storage_pond, 
	integer *feq_storage_geqvec, real *feq_storage_qvec, real *feq_storage_wxvec, real *feq_storage_ma, doublereal *
	feq_gen_feq_storage_dlay_q_d_, doublereal *feq_gen_dlay_k_d_, real *feq_gen_feq_storage_dten_s_d_, real *feq_gen_feq_storage_dten_nbar_d_, 
	doublereal *feq_gen_lprb_vol_d_, doublereal *feq_gen_dd_vol_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, fn;
    real wa;
    integer ln, geq;
    doublereal sum, suma;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__76 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find volume in the stream system. */
/* SOURCE debug.for:861 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE debug.for:863 */
/*<       integerdlay_knt,dten_knt,nbn,nbra,nex,resnum >*/
/* SOURCE debug.for:864 */
/*<       integerbrpt(8,nbra),geqvec(nbra),resvec(nex) >*/
/* SOURCE debug.for:865 */
/*<        >*/
/* SOURCE debug.for:867 */
/*<       real*8dlay_q(dlay_knt),dlay_k(0:dlay_knt),lprb_vol,dd_vol >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     RESNUM - number of level-pool reservoirs */
/*     DLAY_KNT - number of delay reservoirs */
/*     DTEN_KNT - number of detention ponds */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
/*     RESVEC - index into area vector for each level-pool reservoir */
/*     DXVEC  - distance increments along the x-axis for the channel */
/*     A      - Cross sectional areas in the branches. */
/*     AE     - area at exterior nodes and if < 0 volume in a reservoir */
/*     POND   - volume of surcharge storage for each element */
/*     GEQVEC - code for the governing equation option for each branch */
/*     QVEC   - flow rate at each node on a branch */
/*     WXVEC  - value of weight for volumes when variable weight active */
/*     MA     - weight factor on area to get volume per unit length */
/*     DLAY_Q - outflow from delay reservoirs */
/*     DLAY_K - delay time for the linear delay reservoirs */
/*     DTEN_S - storage in a detention pond. */
/*     DTEN_NBAR - number of average ponds per trib-area unit. */
/*     LPRB_VOL - volume in level-pool reservoirs and branches */
/*     DD_VOL   - volume in detention and delay reservoirs */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE debug.for:905 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE debug.for:908 */
/*<       integerfn,geq,i,j,ln >*/
/* SOURCE debug.for:909 */
/*<       realwa >*/
/* SOURCE debug.for:910 */
/*<       real*8sum,suma >*/
/*     + + + INTRINSICS + + + */
/* SOURCE debug.for:913 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/* SOURCE debug.for:915 */
/*<       sum=0.d0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> geqvec(feq_storage_geqvec, 1);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<real> ma(feq_storage_ma, 1);

    feq::IndexedPointer<real> wxvec(feq_storage_wxvec, 1);

    feq::IndexedPointer<real> qvec(feq_storage_qvec, 1);

    feq::IndexedPointer<real> pond(feq_storage_pond, 1);

    feq::IndexedPointer<real> a(feq_storage_a, 1);

    feq::IndexedPointer<real> dxvec(feq_storage_dxvec, 1);

    feq::IndexedPointer<real> ae(feq_storage_ae, 1);

    feq::IndexedPointer<integer> resvec(feq_storage_resvec, 1);

    feq::IndexedPointer<doublereal> feq_gen_dlay_q_d_(feq_gen_feq_storage_dlay_q_d_, 1);

    feq::IndexedPointer<real> feq_gen_dten_nbar_d_(feq_gen_feq_storage_dten_nbar_d_, 1);

    feq::IndexedPointer<real> feq_gen_dten_s_d_(feq_gen_feq_storage_dten_s_d_, 1);

    /* Function Body */
    sum = 0.;
/* SOURCE debug.for:916 */
/*<       suma=0.d0 >*/
    suma = 0.;
/* SOURCE debug.for:917 */
/*<       do200i=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE debug.for:918 */
/*<       fn=brpt(3,i)+1 >*/
	fn = brpt[(feq_gen_i_d_ << 3) + 3] + 1;
/* SOURCE debug.for:919 */
/*<       ln=brpt(4,i) >*/
	ln = brpt[(feq_gen_i_d_ << 3) + 4];
/* SOURCE debug.for:920 */
/*<       geq=geqvec(i) >*/
	geq = geqvec[feq_gen_i_d_];
/* SOURCE debug.for:921 */
/*<       goto(1,2,3,4)geq >*/
	switch (geq) {
	    case 1:  goto L1;
	    case 2:  goto L2;
	    case 3:  goto L3;
	    case 4:  goto L4;
	}
/* SOURCE debug.for:922 */
/*<       write(std6,*)' *BUG:XXX* INVALID GEQ OPTION IN FIND_VOLUMES' >*/
	feq_gen_io_d__76.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__76);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* INVALID GEQ OPTION IN FIND_VOLUMES"), 
		(ftnlen)45);
	e_wsle();
/* SOURCE debug.for:923 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE debug.for:924 */
/*<     1 continue >*/
L1:
/*         TRAPEZOIDAL RULE FOR VOLUMES IN THE ELEMENTS */
/* SOURCE debug.for:926 */
/*<       do100j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE debug.for:927 */
/*<       sum=sum+dxvec(j)*0.5*(a(j-1)+a(j))+pond(j) >*/
	    sum = sum + static_cast<double>(static_cast<double>(dxvec[j]) * (float).5) * (static_cast<double>(a[j - 1]) + a[j]) + pond[j];
/* SOURCE debug.for:928 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE debug.for:929 */
/*<       goto190 >*/
	goto L190;
/* SOURCE debug.for:931 */
/*<     2 continue >*/
L2:
/*         VARIABLE WEIGHTING. */
/* SOURCE debug.for:933 */
/*<       do110j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE debug.for:934 */
/*<       wa=wxvec(j) >*/
	    wa = wxvec[j];
/* SOURCE debug.for:935 */
/*<       if(qvec(j-1)+qvec(j).lt.0.0)then >*/
	    if (static_cast<double>(qvec[j - 1]) + qvec[j] < (float)0.) {
/* SOURCE debug.for:936 */
/*<       wa=1.-wa >*/
		wa = static_cast<double>((float)1.) - wa;
/* SOURCE debug.for:937 */
/*<       endif >*/
	    }
/* SOURCE debug.for:938 */
/*<       sum=sum+dxvec(j)*(a(j-1)+wa*(a(j)-a(j-1)))+pond(j) >*/
	    sum = sum + static_cast<double>(dxvec[j]) * (static_cast<double>(a[j - 1]) + static_cast<double>(wa) * (static_cast<double>(a[j]) - a[j - 1])) + pond[
		    j];
/* SOURCE debug.for:939 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE debug.for:940 */
/*<       goto190 >*/
	goto L190;
/* SOURCE debug.for:942 */
/*<     3 continue >*/
L3:
/*         CURVILINEAR WEIGHTS USED */
/* SOURCE debug.for:944 */
/*<       do120j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE debug.for:945 */
/*<       sum=sum+0.5*dxvec(j)*(ma(j-1)*a(j-1)+ma(j)*a(j))+pond(j) >*/
	    sum = sum + static_cast<double>(static_cast<double>(dxvec[j]) * (float).5) * (static_cast<double>(static_cast<double>(ma[j - 1]) * a[j - 1]) + static_cast<double>(ma[j]) *
		     a[j]) + pond[j];
/* SOURCE debug.for:947 */
/*<   120 continue >*/
/* L120: */
	}
/* SOURCE debug.for:948 */
/*<       goto190 >*/
	goto L190;
/* SOURCE debug.for:950 */
/*<     4 continue >*/
L4:
/*         CURVILINEAR WEIGHTS PLUS VARIABLE WEIGHTING. */
/* SOURCE debug.for:952 */
/*<       do130j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE debug.for:953 */
/*<       wa=wxvec(j) >*/
	    wa = wxvec[j];
/* SOURCE debug.for:954 */
/*<       if(qvec(j-1)+qvec(j).lt.0.0)then >*/
	    if (static_cast<double>(qvec[j - 1]) + qvec[j] < (float)0.) {
/* SOURCE debug.for:955 */
/*<       wa=1.-wa >*/
		wa = static_cast<double>((float)1.) - wa;
/* SOURCE debug.for:956 */
/*<       endif >*/
	    }
/* SOURCE debug.for:957 */
/*<       sum=sum+dxvec(j)*((1.-wa)*ma(j-1)*a(j-1)+wa*ma(j)*a(j))+pond(j) >*/
	    sum = sum + static_cast<double>(dxvec[j]) * (static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - wa)) * ma[j - 1]) * a[j - 1]) + 
		    static_cast<double>(static_cast<double>(wa) * ma[j]) * a[j]) + pond[j];
/* SOURCE debug.for:959 */
/*<   130 continue >*/
/* L130: */
	}
/* SOURCE debug.for:960 */
/*<       goto190 >*/
	goto L190;
/* SOURCE debug.for:962 */
/*<   190 continue >*/
L190:
/* SOURCE debug.for:963 */
/*<   200 continue >*/
/* L200: */
	;
    }
/* SOURCE debug.for:965 */
/*<       if(resnum.eq.0)goto400 >*/
    if (*resnum == 0) {
	goto L400;
    }
/* SOURCE debug.for:966 */
/*<       do300j=1,resnum >*/
    feq_gen_i_d_1 = *resnum;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE debug.for:967 */
/*<       sum=sum+abs(ae(resvec(j))) >*/
	sum += (feq_gen_r_d_1 = ae[resvec[j]], dabs(feq_gen_r_d_1));
/* SOURCE debug.for:968 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE debug.for:969 */
/*<   400 continue >*/
L400:
/*     Delay reservoir volumes */
/* SOURCE debug.for:973 */
/*<       do500j=1,dlay_knt >*/
    feq_gen_i_d_1 = *feq_gen_dlay_knt_d_;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE debug.for:974 */
/*<       suma=suma+dlay_q(j)*dlay_k(j) >*/
	suma += feq_gen_dlay_q_d_[j] * feq_gen_dlay_k_d_[j];
/* SOURCE debug.for:975 */
/*<   500 continue >*/
/* L500: */
    }
/*     Detention ponds */
/* SOURCE debug.for:977 */
/*<       do600j=1,dten_knt >*/
    feq_gen_i_d_1 = *feq_gen_dten_knt_d_;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE debug.for:978 */
/*<       suma=suma+dten_nbar(j)*dten_s(j) >*/
	suma += static_cast<double>(feq_gen_dten_nbar_d_[j]) * feq_gen_dten_s_d_[j];
/* SOURCE debug.for:979 */
/*<   600 continue >*/
/* L600: */
    }
/* SOURCE debug.for:980 */
/*<       lprb_vol=sum >*/
    *feq_gen_lprb_vol_d_ = sum;
/* SOURCE debug.for:981 */
/*<       dd_vol=suma >*/
    *feq_gen_dd_vol_d_ = suma;
/* SOURCE debug.for:982 */
/*<       return >*/
    return 0;
/* SOURCE debug.for:983 */
/*<       end >*/
} /* find_volumes__ */

#ifdef __cplusplus
	}
#endif
