/* ntwmxstr.f -- translated by f2c (version 20240504).
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

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON gate1_ is declared in common.hpp. */

#define gate1_1 gate1_

/* COMMON gate2_ is declared in common.hpp. */

#define gate2_1 gate2_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* COMMON usintp_ is declared in common.hpp. */

#define usintp_1 usintp_

/* COMMON inbr_ is declared in common.hpp. */

#define inbr_1 inbr_

/* COMMON inen_ is declared in common.hpp. */

#define inen_1 inen_

/* COMMON inenc_ is declared in common.hpp. */

#define inenc_1 inenc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_50 = 50;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_14 = 14;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_100 = 100;
static integer feq_gen_c_d_8400 = 8400;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_4401 = 4401;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_6 = 6;

/* Routines used in determining the structure of the network matrix */





/* SOURCE ntwmxstr.for:7 */
/*<       subroutineaddrel(jpt,nd1,nd2,ept,ljoin,join,flag) >*/
/* Subroutine */ int addrel_(integer *jpt, integer *nd1, integer *nd2, 
	integer *ept, integer *ljoin, integer *feq_storage_join, integer *feq_gen_flag_d_)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:219* Too many relationships in juncti\
on with nodes:\002)";
    static char fmt_52[] = "(\002 Node=\002,a5)";
    static char fmt_54[] = "(\002 *ERR:220* Node=\002,a5,\002 not found in j\
unction. NODE2=\002,a5)";
    static char fmt_56[] = "(\002 Nodes at junction are:\002)";
    static char fmt_58[] = "(\002 Extra relationship involves nodes: \002,\
a5,\002 and \002,a5)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j, n, adr, rpt, jfree, endlst;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer maxlst;
    extern /* Subroutine */ int updlst_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Add a relationship to the junction structure. */
/* SOURCE ntwmxstr.for:15 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:17 */
/*<       integerept,flag,jpt,ljoin,nd1,nd2 >*/
/* SOURCE ntwmxstr.for:18 */
/*<       integerjoin(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JPT    - pointer for the junction descriptions */
/*     ND1    - first node of a relationship */
/*     ND2    - second node of a relationship */
/*     EPT    - pointer to a relationship in EMC(*) */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     FLAG   - flag for errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:30 */
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
/* SOURCE ntwmxstr.for:33 */
/*<       integeradr,endlst,j,jfree,maxlst,n,rpt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:36 */
/*<       integerexnodn >*/
/* SOURCE ntwmxstr.for:37 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:40 */
/*<       externalexnodn,getusn,updlst >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:43 */
/*<    50  >*/
/* SOURCE ntwmxstr.for:45 */
/*<    52 format(' Node=',a5) >*/
/* SOURCE ntwmxstr.for:46 */
/*<    54 format(' *ERR:220* Node=',a5,' not found in junction. NODE2=',a5) >*/
/* SOURCE ntwmxstr.for:47 */
/*<    56 format(' Nodes at junction are:') >*/
/* SOURCE ntwmxstr.for:48 */
/*<    58 format(' Extra relationship involves nodes: ',a5,' and ',a5) >*/
/* *********************************************************************** */
/*     SET THE NUMBER OF NODES */
/* SOURCE ntwmxstr.for:53 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
    n = join[*jpt];
/*     SET THE END OF THE LIST FOR THIS JUNCTION */
/* SOURCE ntwmxstr.for:57 */
/*<       endlst=jpt+4+4*n+(n-1) >*/
    endlst = *jpt + 4 + (n << 2) + (n - 1);
/* SOURCE ntwmxstr.for:58 */
/*<       maxlst=jpt+4+4*n+8*(n-1) >*/
    maxlst = *jpt + 4 + (n << 2) + (n - 1 << 3);
/*     GET POINTER TO THE NEXT OPEN SLOT FOR A RELATIONSHIP POINTER */
/* SOURCE ntwmxstr.for:62 */
/*<       rpt=join(jpt+3) >*/
    rpt = join[*jpt + 3];
/* SOURCE ntwmxstr.for:64 */
/*<       if(rpt.ge.endlst)then >*/
    if (rpt >= endlst) {
/*       WE HAVE TOO MANY RELATIONSHIPS IN THIS JUNCTION */
/* SOURCE ntwmxstr.for:66 */
/*<       write(std6,50) >*/
	feq_gen_io_d__5.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__5);
	e_wsfe();
/* SOURCE ntwmxstr.for:67 */
/*<       do105j=jpt+4,jpt+4+n-1 >*/
	feq_gen_i_d_1 = *jpt + 4 + n - 1;
	for (j = *jpt + 4; j <= feq_gen_i_d_1; ++j) {
/* SOURCE ntwmxstr.for:68 */
/*<       write(std6,52)getusn(join(j)) >*/
	    feq_gen_io_d__7.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__7);
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &join[j]);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:69 */
/*<   105 continue >*/
/* L105: */
	}
/* SOURCE ntwmxstr.for:70 */
/*<       write(std6,58)getusn(nd1),getusn(nd2) >*/
	feq_gen_io_d__8.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__8);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, nd1);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	getusn_(feq_gen_ch_d_4, (ftnlen)5, nd2);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	e_wsfe();
/* SOURCE ntwmxstr.for:71 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:72 */
/*<       endif >*/
    }
/*     STORE POINTER TO RELATIONSHIP */
/* SOURCE ntwmxstr.for:76 */
/*<       join(rpt)=ept >*/
    join[rpt] = *ept;
/*     ADD THE RELATIONSHIP TO THE NODE, ND1 */
/*     FIND THE ADDRESS OF THE NODE IN THE JUNCTION */
/* SOURCE ntwmxstr.for:82 */
/*<       adr=exnodn(nd1,jpt,ljoin,join) >*/
    adr = exnodn_(nd1, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:83 */
/*<       if(adr.eq.0)then >*/
    if (adr == 0) {
/* SOURCE ntwmxstr.for:84 */
/*<       write(std6,54)getusn(nd1),getusn(nd2) >*/
	feq_gen_io_d__10.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__10);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, nd1);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	getusn_(feq_gen_ch_d_4, (ftnlen)5, nd2);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	e_wsfe();
/* SOURCE ntwmxstr.for:85 */
/*<       write(std6,56) >*/
	feq_gen_io_d__11.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__11);
	e_wsfe();
/* SOURCE ntwmxstr.for:86 */
/*<       do101j=jpt+4,jpt+4+n-1 >*/
	feq_gen_i_d_1 = *jpt + 4 + n - 1;
	for (j = *jpt + 4; j <= feq_gen_i_d_1; ++j) {
/* SOURCE ntwmxstr.for:87 */
/*<       write(std6,52)getusn(join(j)) >*/
	    feq_gen_io_d__12.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__12);
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &join[j]);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:88 */
/*<   101 continue >*/
/* L101: */
	}
/* SOURCE ntwmxstr.for:90 */
/*<       else >*/
    } else {
/*       NODE WAS FOUND.  SKIP OVER 2 COLUMNS */
/* SOURCE ntwmxstr.for:92 */
/*<       adr=adr+2*n >*/
	adr += n << 1;
/*       ADD TO THE LIST FOR THIS NODE.  GET CURRENT OPEN POSITION IN */
/*       THE LIST */
/* SOURCE ntwmxstr.for:96 */
/*<       jfree=join(jpt+2) >*/
	jfree = join[*jpt + 2];
/* SOURCE ntwmxstr.for:97 */
/*<       callupdlst(rpt,nd2,ljoin,adr,jfree,join,flag) >*/
	updlst_(&rpt, nd2, ljoin, &adr, &jfree, &join[1], feq_gen_flag_d_);
/*       CHECK FOR LIST OVERFLOW */
/* SOURCE ntwmxstr.for:103 */
/*<       if(jfree.gt.maxlst)then >*/
	if (jfree > maxlst) {
/* SOURCE ntwmxstr.for:104 */
/*<       write(std6,50) >*/
	    feq_gen_io_d__14.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__14);
	    e_wsfe();
/* SOURCE ntwmxstr.for:105 */
/*<       do100j=jpt+4,jpt+4+n-1 >*/
	    feq_gen_i_d_1 = *jpt + 4 + n - 1;
	    for (j = *jpt + 4; j <= feq_gen_i_d_1; ++j) {
/* SOURCE ntwmxstr.for:106 */
/*<       write(std6,52)join(j) >*/
		feq_gen_io_d__15.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsfe(&feq_gen_io_d__15);
		do_fio(&feq_gen_c_d_1, (char *)&join[j], (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE ntwmxstr.for:107 */
/*<   100 continue >*/
/* L100: */
	    }
/* SOURCE ntwmxstr.for:108 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:109 */
/*<       endif >*/
	}
/*       UPDATE FREE SPACE POINTER FOR THIS JUNCTION */
/* SOURCE ntwmxstr.for:113 */
/*<       join(jpt+2)=jfree >*/
	join[*jpt + 2] = jfree;
/* SOURCE ntwmxstr.for:114 */
/*<       endif >*/
    }
/*     DO THE OTHER NODE IF IT IS NON-ZERO */
/* SOURCE ntwmxstr.for:117 */
/*<       if(nd2.gt.0)then >*/
    if (*nd2 > 0) {
/* SOURCE ntwmxstr.for:118 */
/*<       adr=exnodn(nd2,jpt,ljoin,join) >*/
	adr = exnodn_(nd2, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:119 */
/*<       if(adr.eq.0)then >*/
	if (adr == 0) {
/* SOURCE ntwmxstr.for:120 */
/*<       write(std6,54)getusn(nd2),getusn(nd1) >*/
	    feq_gen_io_d__16.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__16);
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, nd2);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    getusn_(feq_gen_ch_d_4, (ftnlen)5, nd1);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:121 */
/*<       write(std6,56) >*/
	    feq_gen_io_d__17.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__17);
	    e_wsfe();
/* SOURCE ntwmxstr.for:122 */
/*<       do102j=jpt+4,jpt+4+n-1 >*/
	    feq_gen_i_d_1 = *jpt + 4 + n - 1;
	    for (j = *jpt + 4; j <= feq_gen_i_d_1; ++j) {
/* SOURCE ntwmxstr.for:123 */
/*<       write(std6,52)getusn(join(j)) >*/
		feq_gen_io_d__18.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsfe(&feq_gen_io_d__18);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &join[j]);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		e_wsfe();
/* SOURCE ntwmxstr.for:124 */
/*<   102 continue >*/
/* L102: */
	    }
/* SOURCE ntwmxstr.for:125 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:126 */
/*<       adr=adr+2*n >*/
	    adr += n << 1;
/* SOURCE ntwmxstr.for:127 */
/*<       jfree=join(jpt+2) >*/
	    jfree = join[*jpt + 2];
/* SOURCE ntwmxstr.for:128 */
/*<       callupdlst(rpt,nd1,ljoin,adr,jfree,join,flag) >*/
	    updlst_(&rpt, nd1, ljoin, &adr, &jfree, &join[1], feq_gen_flag_d_);
/*         CHECK FOR LIST OVERFLOW */
/* SOURCE ntwmxstr.for:134 */
/*<       if(jfree.gt.maxlst)then >*/
	    if (jfree > maxlst) {
/* SOURCE ntwmxstr.for:135 */
/*<       write(std6,50) >*/
		feq_gen_io_d__19.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsfe(&feq_gen_io_d__19);
		e_wsfe();
/* SOURCE ntwmxstr.for:136 */
/*<       do103j=jpt+4,jpt+4+n-1 >*/
		feq_gen_i_d_1 = *jpt + 4 + n - 1;
		for (j = *jpt + 4; j <= feq_gen_i_d_1; ++j) {
/* SOURCE ntwmxstr.for:137 */
/*<       write(std6,52)join(j) >*/
		    feq_gen_io_d__20.ciunit = feq_gen_stdun_com_d_1.std6;
		    s_wsfe(&feq_gen_io_d__20);
		    do_fio(&feq_gen_c_d_1, (char *)&join[j], (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE ntwmxstr.for:138 */
/*<   103 continue >*/
/* L103: */
		}
/* SOURCE ntwmxstr.for:139 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:140 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:142 */
/*<       join(jpt+2)=jfree >*/
	    join[*jpt + 2] = jfree;
/* SOURCE ntwmxstr.for:143 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:144 */
/*<       endif >*/
    }
/*     UPDATE THE POINTER TO THE NEXT SLOT FOR A RELATIONSHIP POINTER */
/* SOURCE ntwmxstr.for:148 */
/*<       join(jpt+3)=rpt+1 >*/
    join[*jpt + 3] = rpt + 1;
/* SOURCE ntwmxstr.for:150 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:151 */
/*<       end >*/
} /* addrel_ */




/* SOURCE ntwmxstr.for:155 */
/*<       subroutinebnvarn(bran,brpt,nbra,nex,ivar,neq,exnvar,brnvar,varid) >*/
/* Subroutine */ int bnvarn_(integer *bran, integer *feq_storage_brpt, integer *nbra, 
	integer *nex, integer *ivar, integer *neq, integer *feq_storage_exnvar, integer *
	brnvar, integer *feq_storage_varid)
{
    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    integer nbr, num;
    char dummy[5];
    integer elmknt, nodknt;

/*     + + + PURPOSE + + + */
/*     Assign variable numbers to nodes on a branch. If BRAN < 0 then */
/*     assign them in reverse order.  Signaled by having the */
/*     variable number in BRVARN() < 0 */
/* SOURCE ntwmxstr.for:165 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:167 */
/*<       integerbran,ivar,nbra,neq,nex >*/
/* SOURCE ntwmxstr.for:168 */
/*<       integerbrnvar(0:nbra),brpt(8,nbra),exnvar(nex),varid(*) >*/
/* INCLUDE ntwmxstr.for:170 */
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
/*     BRAN   - branch number */
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
/*     IVAR   - variable number */
/*     NEQ    - equation counter */
/*     EXNVAR - variable number for the first variable(Q) at an exterior */
/*               node */
/*     BRNVAR - branch node variable number for first variable on the */
/*               branch(flow rate) */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:192 */
/*<       integerelmknt,nbr,nodknt,num >*/
/* SOURCE ntwmxstr.for:193 */
/*<       character*5dummy >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntwmxstr.for:196 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/*     ASSIGN THE VARIABLE NUMBERS TO THE NODES ON THE BRANCH.  THE */
/*     ASSIGNMENT IS FROM UPSTREAM END TO DOWNSTREAM END IF THE */
/*     BRANCH NUMBER IS POSITIVE AND THE REVERSE IF IT IS NEGATIVE. */
/* SOURCE ntwmxstr.for:202 */
/*<       nbr=bran >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnvar(feq_storage_exnvar, 1);

    feq::IndexedPointer<integer> varid(feq_storage_varid, 1);

    /* Function Body */
    nbr = *bran;
/*     GET THE NUMBER OF ELEMENTS  AND NODES ON THIS BRANCH */
/*     ON THIS BRANCH */
/* SOURCE ntwmxstr.for:206 */
/*<       elmknt=brpt(4,abs(nbr))-brpt(3,abs(nbr)) >*/
    elmknt = brpt[(abs(nbr) << 3) + 4] - brpt[(abs(nbr) << 3) + 3];
/* SOURCE ntwmxstr.for:207 */
/*<       nodknt=elmknt+1 >*/
    nodknt = elmknt + 1;
/* SOURCE ntwmxstr.for:209 */
/*<       if(nbr.gt.0)then >*/
    if (nbr > 0) {
/*       ASSIGN FROM UPSTREAM END TO DOWNSTREAM END. */
/* SOURCE ntwmxstr.for:211 */
/*<       brnvar(nbr)=ivar >*/
	brnvar[nbr] = *ivar;
/*       ALSO SET LOCATION FOR EXTERIOR NODE AT UPSTREAM END */
/* SOURCE ntwmxstr.for:213 */
/*<       num=brpt(5,nbr) >*/
	num = brpt[(nbr << 3) + 5];
/* SOURCE ntwmxstr.for:214 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:215 */
/*<       brnvar(abs(nbr))=-ivar >*/
	brnvar[abs(nbr)] = -(*ivar);
/*       ALSO SET LOCATION FOR EXTERIOR NODE AT DOWNSTREAM END */
/* SOURCE ntwmxstr.for:217 */
/*<       num=brpt(6,abs(nbr)) >*/
	num = brpt[(abs(nbr) << 3) + 6];
/* SOURCE ntwmxstr.for:218 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:219 */
/*<       exnvar(num)=ivar >*/
    exnvar[num] = *ivar;
/*     Identify the variable number with the exterior node number */
/* SOURCE ntwmxstr.for:221 */
/*<       varid(ivar)=num >*/
    varid[*ivar] = num;
/* SOURCE ntwmxstr.for:222 */
/*<       varid(ivar+1)=num >*/
    varid[*ivar + 1] = num;
/*     Write statement to prevent bug in F95--linux version still */
/*     has it! */
/* SOURCE ntwmxstr.for:226 */
/*<       write(dummy,'(I5)')exnvar(1) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = dummy;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&exnvar[1], (ftnlen)sizeof(integer));
    e_wsfi();
/*     UPDATE THE COUNTER FOR UNKNOWNS. */
/* SOURCE ntwmxstr.for:231 */
/*<       ivar=ivar+brpt(8,abs(nbr))*nodknt >*/
    *ivar += brpt[(abs(nbr) << 3) + 8] * nodknt;
/*     NOW DO THE REMAINING EXTERIOR NODE ON THE BRANCH */
/* SOURCE ntwmxstr.for:234 */
/*<       if(nbr.gt.0)then >*/
    if (nbr > 0) {
/*       DO THE EXTERIOR NODE ON THE DOWNSTREAM END OF THE BRANCH */
/*       NOTE THAT IVAR IS SET TO THE VARIABLE BEYOND THE END OF */
/*       THE BRANCH.  DECREMENT TO REPRESENT THE END OF THE BRANCH. */
/* SOURCE ntwmxstr.for:238 */
/*<       num=brpt(6,nbr) >*/
	num = brpt[(nbr << 3) + 6];
/* SOURCE ntwmxstr.for:239 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:240 */
/*<       num=brpt(5,abs(nbr)) >*/
	num = brpt[(abs(nbr) << 3) + 5];
/* SOURCE ntwmxstr.for:241 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:242 */
/*<       exnvar(num)=ivar-2 >*/
    exnvar[num] = *ivar - 2;
/* SOURCE ntwmxstr.for:243 */
/*<       varid(ivar-2)=num >*/
    varid[*ivar - 2] = num;
/* SOURCE ntwmxstr.for:244 */
/*<       varid(ivar-1)=num >*/
    varid[*ivar - 1] = num;
/*     UPDATE THE COUNTER FOR THE NUMBER OF EQUATIONS */
/* SOURCE ntwmxstr.for:250 */
/*<       neq=neq+brpt(8,abs(nbr))*elmknt >*/
    *neq += brpt[(abs(nbr) << 3) + 8] * elmknt;
/* SOURCE ntwmxstr.for:252 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:253 */
/*<       end >*/
} /* bnvarn_ */




/* SOURCE ntwmxstr.for:257 */
/*<       subroutinecnvenf(enf,prefix,number) >*/
/* Subroutine */ int cnvenf_(char *enf, char *prefix, integer *number, ftnlen 
	enf_len, ftnlen prefix_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:210* Conversion error in exterior n\
ode field:\002,a5)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[5];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, num;
    char chr5[5];
    extern /* Character */ VOID makenn_(char *, ftnlen, char *, integer *, 
	    ftnlen);
    extern integer isnumd_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Convert an exterior node field and return the prefix and */
/*     the number found in the field.  Replace the field with the */
/*     properly formated version of the node id. */
/* SOURCE ntwmxstr.for:266 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:268 */
/*<       integernumber >*/
/* SOURCE ntwmxstr.for:269 */
/*<       characterenf*5,prefix*1 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ENF    - exterior node field */
/*     PREFIX - prefix for an exterior node label */
/*     NUMBER - number found in an exterior node field in Network */
/*               Matrix input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:278 */
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
/* SOURCE ntwmxstr.for:281 */
/*<       integeri,num >*/
/* SOURCE ntwmxstr.for:282 */
/*<       characterchr5*5 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:285 */
/*<       integerisnumd >*/
/* SOURCE ntwmxstr.for:286 */
/*<       charactermakenn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:289 */
/*<       externalisnumd,makenn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:292 */
/*<    50 format(/,' *ERR:210* Conversion error in exterior node field:',a5) >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:294 */
/*<       chr5=enf >*/
/* L50: */
    s_copy(chr5, enf, (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:295 */
/*<       do100i=1,5 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 5; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:296 */
/*<       if(isnumd(chr5(i:i)).eq.0)then >*/
	if (isnumd_(chr5 + (feq_gen_i_d_ - 1), (ftnlen)1) == 0) {
/*         CHARACTER FOUND THAT IS NOT A DECIMAL DIGIT. */
/* SOURCE ntwmxstr.for:298 */
/*<       if(chr5(i:i).ne.' ')then >*/
	    if (*(unsigned char *)&chr5[feq_gen_i_d_ - 1] != ' ') {
/* SOURCE ntwmxstr.for:299 */
/*<       prefix=chr5(i:i) >*/
		*(unsigned char *)prefix = *(unsigned char *)&chr5[feq_gen_i_d_ - 1];
/* SOURCE ntwmxstr.for:300 */
/*<       chr5(i:i)=' ' >*/
		*(unsigned char *)&chr5[feq_gen_i_d_ - 1] = ' ';
/* SOURCE ntwmxstr.for:301 */
/*<       read(chr5,'(I5)',err=991)num >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 5;
		feq_gen_ici_d_1.iciunit = chr5;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
		feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = e_rsfi();
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
/* SOURCE ntwmxstr.for:302 */
/*<       number=num >*/
		*number = num;
/* SOURCE ntwmxstr.for:303 */
/*<       enf=makenn(prefix,num) >*/
		makenn_(feq_gen_ch_d_1, (ftnlen)5, prefix, &num, (ftnlen)1);
		s_copy(enf, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:304 */
/*<       return >*/
		return 0;
/* SOURCE ntwmxstr.for:305 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:306 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:307 */
/*<   100 continue >*/
/* L100: */
    }
/*     NO NON-NUMBER FOUND.  MUST BE AN OLD STYLE EXTERIOR NUMBER. */
/* SOURCE ntwmxstr.for:309 */
/*<       prefix=' ' >*/
    *(unsigned char *)prefix = ' ';
/* SOURCE ntwmxstr.for:310 */
/*<       read(chr5,'(I5)',err=991)num >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = chr5;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ntwmxstr.for:311 */
/*<       number=num >*/
    *number = num;
/* SOURCE ntwmxstr.for:312 */
/*<       enf=makenn(prefix,num) >*/
    makenn_(feq_gen_ch_d_1, (ftnlen)5, prefix, &num, (ftnlen)1);
    s_copy(enf, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:313 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:315 */
/*<   991 continue >*/
L991:
/*     CONVERSION ERROR IN THE FIELD */
/* SOURCE ntwmxstr.for:317 */
/*<       write(std6,50)chr5 >*/
    feq_gen_io_d__29.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__29);
    do_fio(&feq_gen_c_d_1, chr5, (ftnlen)5);
    e_wsfe();
/* SOURCE ntwmxstr.for:318 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:319 */
/*<       end >*/
    return 0;
} /* cnvenf_ */




/* SOURCE ntwmxstr.for:323 */
/*<       subroutinedocode_5_6(stdout,nc_long,eflag,n) >*/
/* Subroutine */ int feq_gen_docode_5_6_d_(integer *stdout, char *feq_gen_feq_storage_nc_long_d_, integer *
	eflag, integer *feq_storage_n, ftnlen nc_long_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:XXX* Conversion error in capacity f\
ield:\002,a)";
    static char fmt_89[] = "(/,\002 *ERR:257* Gate or pump name=\002,a16,\
\002 already in use.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char tmpstrng[16];
    integer feq_gen_i_d_;
    extern integer feq_gen_nonblank_nonzero_d_(char *, ftnlen);
    integer ngtmp;
    extern /* Subroutine */ int lsatab_(integer *, char *, integer *, char *, 
	    integer *, integer *, integer *, ftnlen, ftnlen);
    extern integer fndnum_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_50, 0 };


/*     Process the non-node input for Code 5 Type 6. */
/* SOURCE ntwmxstr.for:328 */
/*<       implicitnone >*/
/* SOURCE ntwmxstr.for:329 */
/*<       integerstdout,eflag,n(10) >*/
/* SOURCE ntwmxstr.for:330 */
/*<       characternc_long(10)*16 >*/
/* INCLUDE ntwmxstr.for:332 */
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
/* INCLUDE ntwmxstr.for:333 */
/*     Common block for the names for gates.  Includes the */
/*     information needed to place the flow class and the current */
/*     gate opening in the special output file.  Start the GOPEN and */
/*     FCLASS at 0 to provide space for gates/pumps without a name. */
/*     We can then avoid an IF statement to see if we should store */
/*     something.  If no name is given the data goes into slot */
/*     zero and is never used!  FCLASS_CODE gives a unique numerical */
/*     code for each flow class string given in FCLASS. */
/*     Use slot MNGATE+1 for the McHenry gates. */
/* SOURCE gatcom.cmn:12 */
/*<       integerngate >*/
/* SOURCE gatcom.cmn:14 */
/*<       realgopen(0:mngate+1) >*/
/* SOURCE gatcom.cmn:16 */
/*<       integerfclass_code(0:mngate+1) >*/
/* SOURCE gatcom.cmn:18 */
/*<       charactergname(mngate+1)*16,fclass(0:mngate+1)*8 >*/
/*     FCLASS gives the flow class of the gate.  The meaning of this field */
/*     depends on the gate type and the kinds of flow that FEQ can report. */
/* SOURCE gatcom.cmn:24 */
/*<       common/gate1/ngate,gopen,fclass_code >*/
/* SOURCE gatcom.cmn:25 */
/*<       common/gate2/gname,fclass >*/
/* SOURCE gatcom.cmn:27 */
/*<       save/gate1/,/gate2/ >*/
/*     External names */
/* SOURCE ntwmxstr.for:336 */
/*<       integerfndnum,nonblank_nonzero >*/
/* SOURCE ntwmxstr.for:337 */
/*<       externalfndnum,nonblank_nonzero,lsatab >*/
/*     Local */
/* SOURCE ntwmxstr.for:341 */
/*<       integeri,ngtmp >*/
/* SOURCE ntwmxstr.for:342 */
/*<       character*16tmpstrng >*/
/* ******************************Formats********************************** */
/* SOURCE ntwmxstr.for:344 */
/*<    50 format(/,' *ERR:XXX* Conversion error in capacity field:',a) >*/
/* SOURCE ntwmxstr.for:345 */
/*<    89 format(/,' *ERR:257* Gate or pump name=',a16,' already in use.') >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:348 */
/*<       do561i=5,6 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> n(feq_storage_n, 1);

    feq::IndexedPointer<char> feq_gen_nc_long_d_(feq_gen_feq_storage_nc_long_d_, 16);

    /* Function Body */
/* L50: */
/* L89: */
    for (feq_gen_i_d_ = 5; feq_gen_i_d_ <= 6; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:349 */
/*<       callget_internal_tab_number(stdout,nc_long(i),eflag,n(i)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + (feq_gen_i_d_ << 4), eflag, &n[
		feq_gen_i_d_], (ftnlen)16);
/* SOURCE ntwmxstr.for:353 */
/*<   561 continue >*/
/* L561: */
    }
/* SOURCE ntwmxstr.for:354 */
/*<       if(nonblank_nonzero(nc_long(7)).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 112, (ftnlen)16) > 0) {
/*       11 Dec 2006-ddf: This field is now changdd to include the */
/*       following options: */
/*       If blank we have no control block nor a time-series table */
/*       If first character is a minus sign, '-', then we have a */
/*       time series table. */
/*       otherwise we have a control block number */
/* SOURCE ntwmxstr.for:361 */
/*<       if(nc_long(7)(1:1).eq.'-')then >*/
	if (*(unsigned char *)&feq_gen_nc_long_d_[112] == '-') {
/*         This is a table id with prefixed minus sign.  Strip the sign */
/* SOURCE ntwmxstr.for:363 */
/*<       tmpstrng=nc_long(7)(2:) >*/
	    s_copy(tmpstrng, feq_gen_nc_long_d_ + 113, (ftnlen)16, (ftnlen)15);
/* SOURCE ntwmxstr.for:364 */
/*<       callget_internal_tab_number(stdout,tmpstrng,eflag,n(7)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, tmpstrng, eflag, &n[7], (ftnlen)
		    16);
/*         Make internal table number  negative as a signal that it is an address */
/* SOURCE ntwmxstr.for:369 */
/*<       n(7)=-n(7) >*/
	    n[7] = -n[7];
/* SOURCE ntwmxstr.for:370 */
/*<       else >*/
	} else {
/*         No prefixed minus sign.  We assume we have an integer. */
/* SOURCE ntwmxstr.for:372 */
/*<       read(nc_long(7),'(i10)',err=999)n(7) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 16;
	    feq_gen_ici_d_1.iciunit = feq_gen_nc_long_d_ + 112;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(i10)");
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&n[7], (ftnlen)sizeof(integer));
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
/* SOURCE ntwmxstr.for:373 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:374 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:375 */
/*<       n(7)=0 >*/
	n[7] = 0;
/* SOURCE ntwmxstr.for:376 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:378 */
/*<       if(nonblank_nonzero(nc_long(8)).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 128, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:379 */
/*<       callget_internal_tab_number(stdout,nc_long(8),eflag,n(8)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 128, eflag, &n[8], (
		ftnlen)16);
/* SOURCE ntwmxstr.for:383 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:384 */
/*<       n(8)=0 >*/
	n[8] = 0;
/* SOURCE ntwmxstr.for:385 */
/*<       endif >*/
    }
/*     Process a possible structure name for use in special output */
/* SOURCE ntwmxstr.for:388 */
/*<       n(9)=0 >*/
    n[9] = 0;
/* SOURCE ntwmxstr.for:389 */
/*<       if(nonblank_nonzero(nc_long(9)).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 144, (ftnlen)16) > 0) {
/*       We have a name for a variable geometry structure. */
/*       Add this name to the gate table and if already there */
/*       signal an error. */
/*       Check if gate name is already in the table. If it is */
/*       in the table it is an error otherwise add it to the table. */
/* SOURCE ntwmxstr.for:395 */
/*<       ngtmp=ngate >*/
	ngtmp = gate1_1.ngate;
/* SOURCE ntwmxstr.for:396 */
/*<       calllsatab(stdout,nc_long(9),mngate,gname,ngate,n(9),eflag) >*/
	lsatab_(stdout, feq_gen_nc_long_d_ + 144, &feq_gen_c_d_50, gate2_1.gname, &
		gate1_1.ngate, &n[9], eflag, (ftnlen)16, (ftnlen)16);
/* SOURCE ntwmxstr.for:400 */
/*<       if(ngate.eq.ngtmp)then >*/
	if (gate1_1.ngate == ngtmp) {
/*         The new name did not increase the size of the table. */
/*         Therefore the name was in the table and is not new! */
/* SOURCE ntwmxstr.for:403 */
/*<       write(stdout,89)nc_long(9) >*/
	    feq_gen_io_d__33.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__33);
	    do_fio(&feq_gen_c_d_1, feq_gen_nc_long_d_ + 144, (ftnlen)16);
	    e_wsfe();
/* SOURCE ntwmxstr.for:404 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:405 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:406 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:408 */
/*<       n(10)=fndnum(nc_long(10)(1:5)) >*/
    n[10] = fndnum_(feq_gen_nc_long_d_ + 160, (ftnlen)5);
/* SOURCE ntwmxstr.for:409 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:410 */
/*<   999 continue >*/
L999:
/* SOURCE ntwmxstr.for:411 */
/*<       write(stdout,50)nc_long(7) >*/
    feq_gen_io_d__34.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__34);
    do_fio(&feq_gen_c_d_1, feq_gen_nc_long_d_ + 112, (ftnlen)16);
    e_wsfe();
/* SOURCE ntwmxstr.for:412 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:413 */
/*<       end >*/
    return 0;
} /* docode_5_6__ */




/* SOURCE ntwmxstr.for:417 */
/*<        >*/
/* Subroutine */ int cnvrtn_(integer *stdout, integer *code, char *feq_storage_nc, char *
	feq_gen_feq_storage_nc_long_d_, integer *feq_storage_usenin, integer *enoden, integer *eflag, char *
	feq_storage_inenus, integer *feq_storage_n, ftnlen nc_len, ftnlen nc_long_len, ftnlen 
	inenus_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:215* Branch number =\002,i5,\002 <=\
 0 invalid.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_i_d_, m;
    extern /* Subroutine */ int feq_gen_docode_5_6_d_(integer *, char *, integer *, 
	    integer *, ftnlen);
    extern integer feq_gen_nonblank_nonzero_d_(char *, ftnlen);
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer num;
    extern /* Subroutine */ int feq_gen_set_control_source_d_(integer *, integer *, 
	    integer *, char *, integer *, integer *, ftnlen), cnvenf_(char *, 
	    char *, integer *, ftnlen, ftnlen), fndinn_(char *, integer *, 
	    integer *, integer *, char *, integer *, ftnlen, ftnlen);
    extern integer fndnum_(char *, ftnlen);
    char prefix[1];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__35 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Convert the integers in the matrix input record to numbers */
/*     with exterior node ids going to internal numbers. */
/* SOURCE ntwmxstr.for:426 */
/*<       implicitnone >*/
/* INCLUDE ntwmxstr.for:427 */
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
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:430 */
/*<       integercode,eflag,enoden,stdout >*/
/* SOURCE ntwmxstr.for:431 */
/*<       integern(10),usenin(-9999:19998) >*/
/* SOURCE ntwmxstr.for:432 */
/*<       characterinenus(mnex)*5,nc(10)*5,nc_long(10)*16 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     CODE   - code number for the network matrix input line */
/*     NC     - input fields from Network Matrix input */
/*     NC_LONG - input fields in long format */
/*     NEX    - number of exterior nodes in the model */
/*     USENIN - conversion from user exterior node number to internal */
/*               exterior node number */
/*     ENODEN - internal exterior-node number */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     INENUS - conversion from internal exterior node number to user */
/*              exterior node designation */
/*     N      - internal node numbers */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:449 */
/*<       integeri,m,num >*/
/* SOURCE ntwmxstr.for:450 */
/*<       characterprefix*1 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:453 */
/*<       integerfndnum,nonblank_nonzero >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:456 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:460 */
/*<    50 format(/,' *ERR:215* Branch number =',i5,' <= 0 invalid.') >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:462 */
/*<       goto(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15),code >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> n(feq_storage_n, 1);

    feq::IndexedPointer<char> inenus(feq_storage_inenus, 5);

    feq::IndexedPointer<integer> usenin(feq_storage_usenin, -9999);

    feq::IndexedPointer<char> feq_gen_nc_long_d_(feq_gen_feq_storage_nc_long_d_, 16);

    feq::IndexedPointer<char> nc(feq_storage_nc, 5);

    /* Function Body */
/* L50: */
    switch (*code) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L14;
	case 15:  goto L15;
    }
/* SOURCE ntwmxstr.for:463 */
/*<       write(stdout,*)' *BUG:11* INVALID EMC CODE IN CNVRTN. CODE=',code >*/
    feq_gen_io_d__35.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__35);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:11* INVALID EMC CODE IN CNVRTN. CODE="), (
	    ftnlen)43);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*code), (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE ntwmxstr.for:465 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/*     CODE FOR A BRANCH */
/* SOURCE ntwmxstr.for:469 */
/*<     1 continue >*/
L1:
/*         N(1) = user branch number; N(2) = time-series indicator for */
/*         rainfall on water surface; N(3) = time-series indicator for */
/*         evaporation on water surface */
/*         Note: N(2) and N(3) are input values but they are not stored as */
/*         part of the instruction.  They only set values in the time-series */
/*         management system.  The effect of rainfall and evaporation on */
/*         the branch water surface is represented as a lateral inflow. */
/*         GET THE USER BRANCH NUMBER. */
/* SOURCE ntwmxstr.for:479 */
/*<       n(1)=fndnum(nc(1)) >*/
    n[1] = fndnum_(nc + 5, (ftnlen)5);
/* SOURCE ntwmxstr.for:480 */
/*<       if(n(1).le.0)then >*/
    if (n[1] <= 0) {
/* SOURCE ntwmxstr.for:481 */
/*<       write(stdout,50)n(1) >*/
	feq_gen_io_d__36.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__36);
	do_fio(&feq_gen_c_d_1, (char *)&n[1], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ntwmxstr.for:482 */
/*<       n(1)=-n(1) >*/
	n[1] = -n[1];
/* SOURCE ntwmxstr.for:483 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ntwmxstr.for:484 */
/*<       endif >*/
    }
/*         Process possible time-series references for rain and evap */
/* SOURCE ntwmxstr.for:486 */
/*<       if(nc_long(2).eq.' ')then >*/
    if (s_cmp(feq_gen_nc_long_d_ + 32, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) == 0) {
/*           No rainfall time-series reference */
/* SOURCE ntwmxstr.for:488 */
/*<       n(2)=0 >*/
	n[2] = 0;
/* SOURCE ntwmxstr.for:490 */
/*<       elseif(nc_long(2)(1:1).eq.'-')then >*/
    } else if (*(unsigned char *)&feq_gen_nc_long_d_[32] == '-') {
/*           The contents refer to a time series file.  Set N(2) to */
/*           a negative value to force checking of the time series */
/*           reference for rain.   Also strip the - from the id. */
/* SOURCE ntwmxstr.for:494 */
/*<       n(2)=-1 >*/
	n[2] = -1;
/* SOURCE ntwmxstr.for:495 */
/*<       nc_long(2)=nc_long(2)(2:16) >*/
	s_copy(feq_gen_nc_long_d_ + 32, feq_gen_nc_long_d_ + 33, (ftnlen)16, (ftnlen)15);
/* SOURCE ntwmxstr.for:496 */
/*<       elseif(nc_long(2).ne.' ')then >*/
    } else if (s_cmp(feq_gen_nc_long_d_ + 32, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/*           The reference is to a time series table.  The value */
/*           could be a zero in which case it signals no time */
/*           series. */
/* SOURCE ntwmxstr.for:501 */
/*<       if(nonblank_nonzero(nc_long(2)).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 32, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:502 */
/*<       callget_internal_tab_number(stdout,nc_long(2),eflag,n(2)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 32, eflag, &n[2], (
		    ftnlen)16);
/* SOURCE ntwmxstr.for:506 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:507 */
/*<       n(2)=0 >*/
	    n[2] = 0;
/* SOURCE ntwmxstr.for:508 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:509 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:511 */
/*<       if(nc_long(3).eq.' ')then >*/
    if (s_cmp(feq_gen_nc_long_d_ + 48, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) == 0) {
/*           No rainfall time-series reference */
/* SOURCE ntwmxstr.for:513 */
/*<       n(3)=0 >*/
	n[3] = 0;
/* SOURCE ntwmxstr.for:515 */
/*<       elseif(nc_long(3)(1:1).eq.'-')then >*/
    } else if (*(unsigned char *)&feq_gen_nc_long_d_[48] == '-') {
/*           The contents refer to a time series file.  Set N(3) to */
/*           a negative value to force checking of the time series */
/*           reference for evap.   Also strip the - from the id. */
/* SOURCE ntwmxstr.for:519 */
/*<       n(3)=-1 >*/
	n[3] = -1;
/* SOURCE ntwmxstr.for:520 */
/*<       nc_long(3)=nc_long(3)(2:16) >*/
	s_copy(feq_gen_nc_long_d_ + 48, feq_gen_nc_long_d_ + 49, (ftnlen)16, (ftnlen)15);
/* SOURCE ntwmxstr.for:521 */
/*<       elseif(nc_long(3).ne.' ')then >*/
    } else if (s_cmp(feq_gen_nc_long_d_ + 48, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/*           The reference is to a time series table.  The value */
/*           could be a zero in which case it signals no time */
/*           series. */
/* SOURCE ntwmxstr.for:526 */
/*<       if(nonblank_nonzero(nc_long(3)).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 48, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:527 */
/*<       callget_internal_tab_number(stdout,nc_long(3),eflag,n(3)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 48, eflag, &n[3], (
		    ftnlen)16);
/* SOURCE ntwmxstr.for:531 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:532 */
/*<       n(3)=0 >*/
	    n[3] = 0;
/* SOURCE ntwmxstr.for:533 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:534 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:535 */
/*<       goto8000 >*/
    goto L8000;
/*     CODE FOR SUM OF FLOW RATES EQUALS ZERO */
/* SOURCE ntwmxstr.for:539 */
/*<     2 continue >*/
L2:
/* SOURCE ntwmxstr.for:541 */
/*<       n(1)=fndnum(nc(1)) >*/
    n[1] = fndnum_(nc + 5, (ftnlen)5);
/* SOURCE ntwmxstr.for:542 */
/*<       m=n(1) >*/
    m = n[1];
/* SOURCE ntwmxstr.for:543 */
/*<       if(m.lt.2.or.m.gt.9)callkil(14,m,eflag) >*/
    if (m < 2 || m > 9) {
	kil_(&feq_gen_c_d_14, &m, eflag);
    }
/* SOURCE ntwmxstr.for:546 */
/*<       m=n(1) >*/
    m = n[1];
/* SOURCE ntwmxstr.for:547 */
/*<       do210i=2,2+m-1 >*/
    feq_gen_i_d_1 = m + 1;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:549 */
/*<       callfndinn(nc(i),enoden,usenin,eflag,inenus,n(i)) >*/
	fndinn_(nc + feq_gen_i_d_ * 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[
		feq_gen_i_d_], (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:553 */
/*<   210 continue >*/
/* L210: */
    }
/* SOURCE ntwmxstr.for:554 */
/*<       goto8000 >*/
    goto L8000;
/*     ELEVATION EQUALITY */
/* SOURCE ntwmxstr.for:558 */
/*<     3 continue >*/
L3:
/* SOURCE ntwmxstr.for:559 */
/*<       do300i=1,2 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 2; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:560 */
/*<       callfndinn(nc(i),enoden,usenin,eflag,inenus,n(i)) >*/
	fndinn_(nc + feq_gen_i_d_ * 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[
		feq_gen_i_d_], (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:564 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE ntwmxstr.for:565 */
/*<       goto8000 >*/
    goto L8000;
/*     ONE-NODE HEAD-DISCHARGE */
/* SOURCE ntwmxstr.for:569 */
/*<     4 continue >*/
L4:
/*         N(1) = TYPE; N(2) = HEAD; N(3) = DIRECTION; N(4) = FLOW NODE */
/*         CHECK AND REPORT STANDARD INFOR FOR CODE = 4. */
/* SOURCE ntwmxstr.for:574 */
/*<       n(1)=fndnum(nc(1)) >*/
    n[1] = fndnum_(nc + 5, (ftnlen)5);
/* SOURCE ntwmxstr.for:575 */
/*<       n(3)=fndnum(nc(3)) >*/
    n[3] = fndnum_(nc + 15, (ftnlen)5);
/* SOURCE ntwmxstr.for:577 */
/*<       do450i=2,4,2 >*/
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= 4; feq_gen_i_d_ += 2) {
/* SOURCE ntwmxstr.for:578 */
/*<       callfndinn(nc(i),enoden,usenin,eflag,inenus,n(i)) >*/
	fndinn_(nc + feq_gen_i_d_ * 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[
		feq_gen_i_d_], (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:582 */
/*<   450 continue >*/
/* L450: */
    }
/*         BRANCH ON N(1) AND COMPLETE PROCESSING */
/* SOURCE ntwmxstr.for:586 */
/*<       goto(401,401,403,404,405,406),n(1) >*/
    switch (n[1]) {
	case 1:  goto L401;
	case 2:  goto L401;
	case 3:  goto L403;
	case 4:  goto L404;
	case 5:  goto L405;
	case 6:  goto L406;
    }
/* SOURCE ntwmxstr.for:587 */
/*<        >*/
    feq_gen_io_d__39.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__39);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:12* INVALID CODE=4 TYPE IN CNVRTN."), (ftnlen)
	    40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&n[1], (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE ntwmxstr.for:589 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:591 */
/*<   401 continue >*/
L401:
/* SOURCE ntwmxstr.for:592 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (ftnlen)
	    16);
/*              N(5) = FNDNUM(NC(5)) */
/* SOURCE ntwmxstr.for:598 */
/*<       goto499 >*/
    goto L499;
/* SOURCE ntwmxstr.for:600 */
/*<   403 continue >*/
L403:
/* SOURCE ntwmxstr.for:601 */
/*<       n(5)=fndnum(nc(5)) >*/
    n[5] = fndnum_(nc + 25, (ftnlen)5);
/* SOURCE ntwmxstr.for:602 */
/*<       goto499 >*/
    goto L499;
/* SOURCE ntwmxstr.for:604 */
/*<   404 continue >*/
L404:
/* SOURCE ntwmxstr.for:605 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (ftnlen)
	    16);
/* SOURCE ntwmxstr.for:609 */
/*<       callget_internal_tab_number(stdout,nc_long(6),eflag,n(6)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 96, eflag, &n[6], (ftnlen)
	    16);
/*              N(5) = FNDNUM(NC(5)) */
/*              N(6) = FNDNUM(NC(6)) */
/* SOURCE ntwmxstr.for:616 */
/*<       goto499 >*/
    goto L499;
/* SOURCE ntwmxstr.for:618 */
/*<   405 continue >*/
L405:
/* SOURCE ntwmxstr.for:620 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (ftnlen)
	    16);
/*              N(5) = FNDNUM(NC(5)) */
/*              N(6) = FNDNUM(NC(6)) */
/* SOURCE ntwmxstr.for:626 */
/*<       callset_control_source(stdout,mftnum,mnblk,nc_long(6),eflag,n(6)) >*/
    feq_gen_set_control_source_d_(stdout, &feq_gen_c_d_10002, &feq_gen_c_d_100, feq_gen_nc_long_d_ + 96, eflag, &
	    n[6], (ftnlen)16);
/* SOURCE ntwmxstr.for:629 */
/*<       goto499 >*/
    goto L499;
/* SOURCE ntwmxstr.for:631 */
/*<   406 continue >*/
L406:
/*             N(5) = RATING TABLE NUMBER, N(6) = SOURCE FOR CONTROLLING */
/*             LEVEL.  N(6) > 0: TIME SERIES TABLE; N(6) < 0 FILE IN */
/*             CONNECTION FORMAT. N(7)= TABLE CONVERTING CONTROLLING LEVEL */
/*             INTO FLOWRATE. */
/*              N(5) = FNDNUM(NC(5)) */
/* SOURCE ntwmxstr.for:638 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (ftnlen)
	    16);
/*              N(6) = FNDNUM(NC(6)) */
/* SOURCE ntwmxstr.for:643 */
/*<       if(nc_long(6)(1:1).eq.'-')then >*/
    if (*(unsigned char *)&feq_gen_nc_long_d_[96] == '-') {
/*               The contents refer to a time series file.  Set N(6) to */
/*               a negative value to force checking of the time series */
/*               reference.   Also strip the - from the id. */
/* SOURCE ntwmxstr.for:647 */
/*<       n(6)=-1 >*/
	n[6] = -1;
/* SOURCE ntwmxstr.for:648 */
/*<       nc_long(6)=nc_long(6)(2:16) >*/
	s_copy(feq_gen_nc_long_d_ + 96, feq_gen_nc_long_d_ + 97, (ftnlen)16, (ftnlen)15);
/* SOURCE ntwmxstr.for:649 */
/*<       else >*/
    } else {
/*               The reference is to a time series table or to */
/*               a constant value given later in the instruction. */
/*               A blank or zero value signals the constant value. */
/*               The reference is to a time series table or to */
/*               a constant value given later in the instruction. */
/*               A blank or zero value signals the constant value. */
/* SOURCE ntwmxstr.for:656 */
/*<       if(nonblank_nonzero(nc_long(6)).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 96, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:657 */
/*<       callget_internal_tab_number(stdout,nc_long(6),eflag,n(6)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 96, eflag, &n[6], (
		    ftnlen)16);
/* SOURCE ntwmxstr.for:661 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:662 */
/*<       n(6)=0 >*/
	    n[6] = 0;
/* SOURCE ntwmxstr.for:663 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:664 */
/*<       endif >*/
    }
/*              N(7) = FNDNUM(NC(7)) */
/* SOURCE ntwmxstr.for:666 */
/*<       callget_internal_tab_number(stdout,nc_long(7),eflag,n(7)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 112, eflag, &n[7], (ftnlen)
	    16);
/* SOURCE ntwmxstr.for:670 */
/*<       goto499 >*/
    goto L499;
/* SOURCE ntwmxstr.for:671 */
/*<   499 continue >*/
L499:
/* SOURCE ntwmxstr.for:672 */
/*<       goto8000 >*/
    goto L8000;
/* SOURCE ntwmxstr.for:674 */
/*<     5 continue >*/
L5:
/*         N(1) = TYPE; N(2) = UPN; N(3) = DNN; N(4) = FLOW NODE; */
/* SOURCE ntwmxstr.for:678 */
/*<       n(1)=fndnum(nc(1)) >*/
    n[1] = fndnum_(nc + 5, (ftnlen)5);
/* SOURCE ntwmxstr.for:679 */
/*<       do580i=2,4 >*/
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= 4; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:680 */
/*<       callfndinn(nc(i),enoden,usenin,eflag,inenus,n(i)) >*/
	fndinn_(nc + feq_gen_i_d_ * 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[
		feq_gen_i_d_], (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:684 */
/*<   580 continue >*/
/* L580: */
    }
/*          BRANCH ON N(1) AND COMPLETE PROCESSING */
/* SOURCE ntwmxstr.for:686 */
/*<       goto(501,502,503,504,505,506,507,508,509),n(1) >*/
    switch (n[1]) {
	case 1:  goto L501;
	case 2:  goto L502;
	case 3:  goto L503;
	case 4:  goto L504;
	case 5:  goto L505;
	case 6:  goto L506;
	case 7:  goto L507;
	case 8:  goto L508;
	case 9:  goto L509;
    }
/* SOURCE ntwmxstr.for:687 */
/*<        >*/
    feq_gen_io_d__40.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:13* INVALID CODE=5 TYPE IN CNVRTN."), (ftnlen)
	    40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&n[1], (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE ntwmxstr.for:689 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:691 */
/*<   501 continue >*/
L501:
/*             EXPANSION-CONTRACTION WITH CRITICAL DEPTH POSSIBLE */
/*             N(5) = TRANSISTION SIGN; N((6) = TABLE# FOR */
/*             COMPUTING CRITICAL FLOW; */
/* SOURCE ntwmxstr.for:698 */
/*<       n(5)=fndnum(nc(5)) >*/
    n[5] = fndnum_(nc + 25, (ftnlen)5);
/*              N(6) = FNDNUM(NC(6)) */
/* SOURCE ntwmxstr.for:700 */
/*<       callget_internal_tab_number(stdout,nc_long(6),eflag,n(6)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 96, eflag, &n[6], (ftnlen)
	    16);
/* SOURCE ntwmxstr.for:704 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:706 */
/*<   502 continue >*/
L502:
/*             N(5) = TABLE NUMBER FOR UPSTREAM TO DOWNSTREAM FLOW */
/*             VERSUS HEAD; N(6) = TABLE NUMBER FOR SUBMERGENCE */
/*             CORRECTION FOR TABLE GIVEN BY N(5); N(7) = TABLE NUMBER */
/*             FOR DOWNSTREAM TO UPSTREAM FLOW VERSUS HEAD; N(8) = */
/*             TABLE NUMBER FOR SUBMERGENCE CORRECTION FOR TABLE */
/*             GIVEN BY N(7); */
/*             N(9) = KEY. KEY = 0 IF TURNON IS ELEVATION, KEY = 1 */
/*              IF TURNON IS FLOWRATE */
/*             N(10) = SWITCH NODE. IF FLOW AT NODE IS > 0 THEN PUMP */
/*                     IF ON MUST BE TURNED OFF AND IF OFF SHOULD NOT BE */
/*                     TURNED ON BY OTHER RULES. */
/* SOURCE ntwmxstr.for:720 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (ftnlen)
	    16);
/* SOURCE ntwmxstr.for:724 */
/*<       if(nonblank_nonzero(nc_long(6)).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 96, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:725 */
/*<       callget_internal_tab_number(stdout,nc_long(6),eflag,n(6)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 96, eflag, &n[6], (
		ftnlen)16);
/* SOURCE ntwmxstr.for:729 */
/*<       callget_internal_tab_number(stdout,nc_long(7),eflag,n(7)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 112, eflag, &n[7], (
		ftnlen)16);
/* SOURCE ntwmxstr.for:733 */
/*<       callget_internal_tab_number(stdout,nc_long(8),eflag,n(8)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 128, eflag, &n[8], (
		ftnlen)16);
/* SOURCE ntwmxstr.for:737 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:738 */
/*<       n(6)=0 >*/
	n[6] = 0;
/* SOURCE ntwmxstr.for:739 */
/*<       n(7)=0 >*/
	n[7] = 0;
/* SOURCE ntwmxstr.for:740 */
/*<       n(8)=0 >*/
	n[8] = 0;
/* SOURCE ntwmxstr.for:741 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:742 */
/*<       n(9)=fndnum(nc(9)) >*/
    n[9] = fndnum_(nc + 45, (ftnlen)5);
/* SOURCE ntwmxstr.for:744 */
/*<       if(nc(10).ne.'    ')then >*/
    if (s_cmp(nc + 50, const_cast<char*>("    "), (ftnlen)5, (ftnlen)4) != 0) {
/* SOURCE ntwmxstr.for:745 */
/*<       callfndinn(nc(10),enoden,usenin,eflag,inenus,n(10)) >*/
	fndinn_(nc + 50, enoden, &usenin[-9999], eflag, inenus + 5, &n[10], (
		ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:749 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:750 */
/*<       n(10)=0 >*/
	n[10] = 0;
/* SOURCE ntwmxstr.for:751 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:753 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:755 */
/*<   503 continue >*/
L503:
/*         Pump with variable head and optional conduit and */
/*         entrance and exit losses */
/*         N(5)-flow direction: 1 is U to D and -1 is D to U */
/*         N(6)-Table number for the pump curve.  Head across */
/*              the pump for flow.  Defined for the standard or */
/*              base speed if the pump is variable speed. */
/*         N(7)-Table number for the losses at the inlet, in the */
/*              inlet conduit, and in the outlet conduit.  Taken */
/*              as a function of the flow through the pump. */
/*         N(8)-Table number for the coefficient on the velocity */
/*              head difference between the end of the outlet */
/*              conduit and the target node.  Is a function of the */
/*              depth of submergence of the outlet.  Must be 1.0 at */
/*              zero submergence. */
/*         N(9)-Table number for pump speed as a function of time if */
/*              < 0.  Operation block number controlling the pump if > 0. */
/*          NC(10)- Optional name for the pump for output to special */
/*                  output file. */
/* SOURCE ntwmxstr.for:778 */
/*<       n(5)=fndnum(nc(5)) >*/
    n[5] = fndnum_(nc + 25, (ftnlen)5);
/* SOURCE ntwmxstr.for:779 */
/*<       callget_internal_tab_number(stdout,nc_long(6),eflag,n(6)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 96, eflag, &n[6], (ftnlen)
	    16);
/* SOURCE ntwmxstr.for:783 */
/*<       do543i=7,8 >*/
    for (feq_gen_i_d_ = 7; feq_gen_i_d_ <= 8; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:784 */
/*<       if(nonblank_nonzero(nc_long(i)).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + (feq_gen_i_d_ << 4), (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:785 */
/*<       callget_internal_tab_number(stdout,nc_long(i),eflag,n(i)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + (feq_gen_i_d_ << 4), eflag, &
		    n[feq_gen_i_d_], (ftnlen)16);
/* SOURCE ntwmxstr.for:789 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:790 */
/*<       n(i)=0 >*/
	    n[feq_gen_i_d_] = 0;
/* SOURCE ntwmxstr.for:791 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:792 */
/*<   543 continue >*/
/* L543: */
    }
/* SOURCE ntwmxstr.for:794 */
/*<       callset_control_source(stdout,mftnum,mnblk,nc_long(9),eflag,n(9)) >*/
    feq_gen_set_control_source_d_(stdout, &feq_gen_c_d_10002, &feq_gen_c_d_100, feq_gen_nc_long_d_ + 144, eflag, &
	    n[9], (ftnlen)16);
/* SOURCE ntwmxstr.for:798 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:800 */
/*<   504 continue >*/
L504:
/*            BRIDGE / FLOW OVER THE ROADWAY POSSIBLE */
/*            N(5) - TABLE# OF HEAD LOSS COEF VS DEPTH + FLOW */
/*            N(6) - TABLE# OF HEAD LOSS COEF VS DEPTH - FLOW */
/*            N(7) - TABLE# OF AREA VS DEPTH FOR BRIDGE OPENING */
/*            N(8) - TABLE# OF FLOW OVER ROAD VS HEAD  + FLOW */
/*            N(9) - TABLE# OF FLOW OVER ROAD VS HEAD  - FLOW */
/*            N(10)- TABLE# GIVING FLOW RATIO VS SUBMERGENCE RATIO */
/* SOURCE ntwmxstr.for:809 */
/*<       do565i=5,10 >*/
    for (feq_gen_i_d_ = 5; feq_gen_i_d_ <= 10; ++feq_gen_i_d_) {
/*               N(I) = FNDNUM(NC(I)) */
/* SOURCE ntwmxstr.for:811 */
/*<       callget_internal_tab_number(stdout,nc_long(i),eflag,n(i)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + (feq_gen_i_d_ << 4), eflag, &n[
		feq_gen_i_d_], (ftnlen)16);
/* SOURCE ntwmxstr.for:815 */
/*<   565 continue >*/
/* L565: */
    }
/* SOURCE ntwmxstr.for:816 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:818 */
/*<   505 continue >*/
L505:
/*             ABRUPT EXAPANSION- */
/*             N(5) = TABLE NUMBER OF CRITICAL FLOW TABLE */
/*              N(5) = FNDNUM(NC(5)) */
/* SOURCE ntwmxstr.for:823 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (ftnlen)
	    16);
/* SOURCE ntwmxstr.for:827 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:829 */
/*<   506 continue >*/
L506:
/*             TWO-D FLOW TABLE WITH ELEVATION AS ARGUMENTS */

/*             N(5) = TABLE NUMBER FOR FLOW FROM U TO D */
/*             N(6) = TABLE NUMBER FOR FLOW FROM D TO U */
/*             N(7) = OPTIONAL TABLE NUMBER FOR TABLE GIVING THE FACTOR */
/*                    TO USE TO MULTIPLY THE VALUE DERIVED FROM THE TABLES. */
/*                    IF ZERO FACTOR IS TAKEN AS 1.0 */
/*             N(8) = OPTIONAL TABLE NUMBER FOR TABLE GIVING THE ELEVATION */
/*                    FOR COMPUTING HEAD VERSUS TIME.  IF ZERO THE ELEVATION */
/*                    FOR COMPUTING HEAD IS THE VALUE IN F(1) */
/*             N(10) = IF GT 0 THEN INDICATES A CONTINUATION LINE FOLLOWS. */
/*                     THE CONTINUATION LINE WILL HAVE ONLY N(5:10), AND */
/*                     F(1) ON IT IN THE SAME FORMAT AS THE FIRST LINE OF */
/*                     INPUT FOR THIS TYPE.  THIS ALLOWS MULTIPLE TABLES */
/*                    FOR THE FLOW BETWEEN THE TWO NODES. */
/* SOURCE ntwmxstr.for:846 */
/*<       calldocode_5_6(stdout,nc_long,eflag,n) >*/
    feq_gen_docode_5_6_d_(stdout, feq_gen_nc_long_d_ + 16, eflag, &n[1], (ftnlen)16);
/* SOURCE ntwmxstr.for:851 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:853 */
/*<   507 continue >*/
L507:
/*             BIDIRECTIONAL FLOW OVER A WEIR WITH VARIABLE HEIGHT */
/*             AND DISCHARGE COEFFICIENT */
/*             N(5) = OPERATION BLOCK NUMBER OR NEGATIVE OF */
/*             TABLE NUMBER GIVING THE OPENING FRACTION AS */
/*             A FUNCTION OF TIME; N(6) = TABLE NUMBER */
/*             OF THE TABLE GIVING THE ELEVATION OF THE WEIR CREST */
/*             VS. P; N(7)= TABLE NUMBER OF TABLE GIVING C VS. P */
/*             FOR POSITIVE FLOW; N(8) = TABLE NUMBER OF TABLE GIVING */
/*             C VS. P FOR NEGATIVE FLOW; N(9)= TABLE NUMBER OF TABLE */
/*             GIVING SUMERGENCE CORRECTION FOR BOTH DIRECTIONS; */
/*             FOR THE VELOCITY HEAD COMPUTED FROM THE AVERAGE VELOCITY. */
/*             NC(10)- Optional name for the gate for output to */
/*                 the special output file. */
/* SOURCE ntwmxstr.for:871 */
/*<       callset_control_source(stdout,mftnum,mnblk,nc_long(5),eflag,n(5)) >*/
    feq_gen_set_control_source_d_(stdout, &feq_gen_c_d_10002, &feq_gen_c_d_100, feq_gen_nc_long_d_ + 80, eflag, &
	    n[5], (ftnlen)16);
/* SOURCE ntwmxstr.for:875 */
/*<       do570i=6,9 >*/
    for (feq_gen_i_d_ = 6; feq_gen_i_d_ <= 9; ++feq_gen_i_d_) {
/*                N(I) = FNDNUM(NC(I)) */
/* SOURCE ntwmxstr.for:877 */
/*<       callget_internal_tab_number(stdout,nc_long(i),eflag,n(i)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + (feq_gen_i_d_ << 4), eflag, &n[
		feq_gen_i_d_], (ftnlen)16);
/* SOURCE ntwmxstr.for:881 */
/*<   570 continue >*/
/* L570: */
    }
/* SOURCE ntwmxstr.for:882 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:884 */
/*<   508 continue >*/
L508:
/*             MCHENRY SLUICE GATES ON THE FOX RIVER BELOW FOX CHAIN OF */
/*             LAKES. */
/*             N(5) = OPERATION BLOCK NUMBER OR NEGATIVE OF */
/*             TABLE NUMBER GIVING THE OPENING FRACTION AS */
/*             A FUNCTION OF TIME. */
/* SOURCE ntwmxstr.for:891 */
/*<       callset_control_source(stdout,mftnum,mnblk,nc_long(5),eflag,n(5)) >*/
    feq_gen_set_control_source_d_(stdout, &feq_gen_c_d_10002, &feq_gen_c_d_100, feq_gen_nc_long_d_ + 80, eflag, &
	    n[5], (ftnlen)16);
/* SOURCE ntwmxstr.for:894 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:897 */
/*<   509 continue >*/
L509:
/*             Generic gate */
/*             N(5) = OPERATION BLOCK NUMBER OR NEGATIVE OF */
/*             TABLE NUMBER GIVING THE OPENING FRACTION AS */
/*             A FUNCTION OF TIME; N(6) = 4-character string for */
/*             gate id. */
/*             N(7)= TABLE NUMBER of type 15 giving flow from u to d */
/*             N(8)= table number of type 15 giving flow from d to u */
/* SOURCE ntwmxstr.for:908 */
/*<       callset_control_source(stdout,mftnum,mnblk,nc_long(5),eflag,n(5)) >*/
    feq_gen_set_control_source_d_(stdout, &feq_gen_c_d_10002, &feq_gen_c_d_100, feq_gen_nc_long_d_ + 80, eflag, &
	    n[5], (ftnlen)16);
/* SOURCE ntwmxstr.for:912 */
/*<       do5091i=7,8 >*/
    for (feq_gen_i_d_ = 7; feq_gen_i_d_ <= 8; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:913 */
/*<       callget_internal_tab_number(stdout,nc_long(i),eflag,n(i)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + (feq_gen_i_d_ << 4), eflag, &n[
		feq_gen_i_d_], (ftnlen)16);
/* SOURCE ntwmxstr.for:917 */
/*<  5091 continue >*/
/* L5091: */
    }
/*             NC(6) already contains the 4-character string giving the */
/*             gate name. */
/*             Check for a gate-efficiency table. */
/* SOURCE ntwmxstr.for:924 */
/*<       if(nonblank_nonzero(nc_long(9)).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 144, (ftnlen)16) > 0) {
/*               There is a table for gate efficiency. */
/* SOURCE ntwmxstr.for:926 */
/*<       callget_internal_tab_number(stdout,nc_long(9),eflag,n(9)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 144, eflag, &n[9], (
		ftnlen)16);
/* SOURCE ntwmxstr.for:930 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:931 */
/*<       n(9)=0 >*/
	n[9] = 0;
/* SOURCE ntwmxstr.for:932 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:933 */
/*<       if(n(9).gt.0)then >*/
    if (n[9] > 0) {
/*               There is a gate-efficiency table specified. */
/*               Get the exterior node id and convert to */
/*               internal form. */
/* SOURCE ntwmxstr.for:937 */
/*<       callfndinn(nc(10),enoden,usenin,eflag,inenus,n(10)) >*/
	fndinn_(nc + 50, enoden, &usenin[-9999], eflag, inenus + 5, &n[10], (
		ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:941 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:943 */
/*<       goto599 >*/
    goto L599;
/* SOURCE ntwmxstr.for:945 */
/*<   599 continue >*/
L599:
/* SOURCE ntwmxstr.for:946 */
/*<       goto8000 >*/
    goto L8000;
/*       FORCED BOUNDARY */
/* SOURCE ntwmxstr.for:950 */
/*<     6 continue >*/
L6:
/*         N(1)=TYPE; N(2)=NODE; N(3)=DIRECTION; N(4)=time-series id */
/*         N(5) = time-series table id giving an adjustment factor on the */
/*                flow or elevation value as function of time.  May be */
/*                missing. */
/* SOURCE ntwmxstr.for:956 */
/*<       n(1)=fndnum(nc(1)) >*/
    n[1] = fndnum_(nc + 5, (ftnlen)5);
/* SOURCE ntwmxstr.for:957 */
/*<       callfndinn(nc(2),enoden,usenin,eflag,inenus,n(2)) >*/
    fndinn_(nc + 10, enoden, &usenin[-9999], eflag, inenus + 5, &n[2], (
	    ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:961 */
/*<       n(3)=fndnum(nc(3)) >*/
    n[3] = fndnum_(nc + 15, (ftnlen)5);
/*          N(4) = FNDNUM(NC(4)) */
/* SOURCE ntwmxstr.for:963 */
/*<       if(nc_long(4)(1:1).eq.'-')then >*/
    if (*(unsigned char *)&feq_gen_nc_long_d_[64] == '-') {
/*           The contents refer to a time series file.  Set N(4) to */
/*           a negative value to force checking of the time series */
/*           reference.   Also strip the - from the id. */
/* SOURCE ntwmxstr.for:967 */
/*<       n(4)=-1 >*/
	n[4] = -1;
/* SOURCE ntwmxstr.for:968 */
/*<       nc_long(4)=nc_long(4)(2:16) >*/
	s_copy(feq_gen_nc_long_d_ + 64, feq_gen_nc_long_d_ + 65, (ftnlen)16, (ftnlen)15);
/* SOURCE ntwmxstr.for:969 */
/*<       else >*/
    } else {
/*           The reference is to a time series table or to */
/*           a constant value given later in the instruction. */
/*           A blank or zero value signals the constant value. */
/* SOURCE ntwmxstr.for:973 */
/*<       if(nonblank_nonzero(nc_long(4)).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 64, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:974 */
/*<       callget_internal_tab_number(stdout,nc_long(4),eflag,n(4)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 64, eflag, &n[4], (
		    ftnlen)16);
/* SOURCE ntwmxstr.for:978 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:979 */
/*<       n(4)=0 >*/
	    n[4] = 0;
/* SOURCE ntwmxstr.for:980 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:981 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:983 */
/*<       if(nonblank_nonzero(nc_long(5)).gt.0)then >*/
    if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 80, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:984 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (
		ftnlen)16);
/* SOURCE ntwmxstr.for:988 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:989 */
/*<       n(5)=0 >*/
	n[5] = 0;
/* SOURCE ntwmxstr.for:990 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:991 */
/*<       goto8000 >*/
    goto L8000;
/*       LEVEL POOL RESERVOIR */
/* SOURCE ntwmxstr.for:995 */
/*<     7 continue >*/
L7:
/*         IN THIS VERSION N(3) MUST BE 1! */
/*         N(1) = NODE NUMBER; N(2) = STORAGE TABLE NUMBER; */
/*         N(3) = NUMBER OF INFLOW NODES; N(4) = INFLOW NODE NUMBER */
/*         N(5) = time-series indicator for rainfall on surface */
/*         N(6) =  time-series indicator for evaporation on surface */
/*         Note: N(5) and N(6) are input values but they are not stored as */
/*         part of the instruction.  They only set values in the time-series */
/*         management system.  The effect of rainfall and evaporation on */
/*         the branch water surface is represented as a lateral inflow. */
/* SOURCE ntwmxstr.for:1007 */
/*<       callfndinn(nc(1),enoden,usenin,eflag,inenus,n(1)) >*/
    fndinn_(nc + 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[1], (ftnlen)
	    5, (ftnlen)5);
/*          N(2) = FNDNUM(NC(2)) */
/* SOURCE ntwmxstr.for:1012 */
/*<       callget_internal_tab_number(stdout,nc_long(2),eflag,n(2)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 32, eflag, &n[2], (ftnlen)
	    16);
/* SOURCE ntwmxstr.for:1016 */
/*<       n(3)=fndnum(nc(3)) >*/
    n[3] = fndnum_(nc + 15, (ftnlen)5);
/* SOURCE ntwmxstr.for:1017 */
/*<       callfndinn(nc(4),enoden,usenin,eflag,inenus,n(4)) >*/
    fndinn_(nc + 20, enoden, &usenin[-9999], eflag, inenus + 5, &n[4], (
	    ftnlen)5, (ftnlen)5);
/*         Process references to time series for rainfall and evaporations */
/* SOURCE ntwmxstr.for:1023 */
/*<       if(nc_long(5).eq.' ')then >*/
    if (s_cmp(feq_gen_nc_long_d_ + 80, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) == 0) {
/*           No rainfall time-series reference */
/* SOURCE ntwmxstr.for:1025 */
/*<       n(5)=0 >*/
	n[5] = 0;
/* SOURCE ntwmxstr.for:1027 */
/*<       elseif(nc_long(5)(1:1).eq.'-')then >*/
    } else if (*(unsigned char *)&feq_gen_nc_long_d_[80] == '-') {
/*           The contents refer to a time series file.  Set N(5) to */
/*           a negative value to force checking of the time series */
/*           reference for rain.   Also strip the - from the id. */
/* SOURCE ntwmxstr.for:1031 */
/*<       n(5)=-1 >*/
	n[5] = -1;
/* SOURCE ntwmxstr.for:1032 */
/*<       nc_long(5)=nc_long(5)(2:16) >*/
	s_copy(feq_gen_nc_long_d_ + 80, feq_gen_nc_long_d_ + 81, (ftnlen)16, (ftnlen)15);
/* SOURCE ntwmxstr.for:1033 */
/*<       elseif(nc_long(5).ne.' ')then >*/
    } else if (s_cmp(feq_gen_nc_long_d_ + 80, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/*           The reference is to a time series table.  The value */
/*           could be a zero in which case it signals no time */
/*           series. */
/* SOURCE ntwmxstr.for:1038 */
/*<       if(nonblank_nonzero(nc_long(5)).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 80, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:1039 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (
		    ftnlen)16);
/* SOURCE ntwmxstr.for:1043 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:1044 */
/*<       n(5)=0 >*/
	    n[5] = 0;
/* SOURCE ntwmxstr.for:1045 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:1046 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1047 */
/*<       if(nc_long(6).eq.' ')then >*/
    if (s_cmp(feq_gen_nc_long_d_ + 96, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) == 0) {
/*           No evaporation time-series reference */
/* SOURCE ntwmxstr.for:1049 */
/*<       n(6)=0 >*/
	n[6] = 0;
/* SOURCE ntwmxstr.for:1051 */
/*<       elseif(nc_long(6)(1:1).eq.'-')then >*/
    } else if (*(unsigned char *)&feq_gen_nc_long_d_[96] == '-') {
/*           The contents refer to a time series file.  Set N(6) to */
/*           a negative value to force checking of the time series */
/*           reference for evap.   Also strip the - from the id. */
/* SOURCE ntwmxstr.for:1055 */
/*<       n(6)=-1 >*/
	n[6] = -1;
/* SOURCE ntwmxstr.for:1056 */
/*<       nc_long(6)=nc_long(6)(2:16) >*/
	s_copy(feq_gen_nc_long_d_ + 96, feq_gen_nc_long_d_ + 97, (ftnlen)16, (ftnlen)15);
/* SOURCE ntwmxstr.for:1057 */
/*<       elseif(nc_long(6).ne.' ')then >*/
    } else if (s_cmp(feq_gen_nc_long_d_ + 96, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/*           The reference is to a time series table.  The value */
/*           could be a zero in which case it signals no time */
/*           series. */
/* SOURCE ntwmxstr.for:1062 */
/*<       if(nonblank_nonzero(nc_long(6)).gt.0)then >*/
	if (feq_gen_nonblank_nonzero_d_(feq_gen_nc_long_d_ + 96, (ftnlen)16) > 0) {
/* SOURCE ntwmxstr.for:1063 */
/*<       callget_internal_tab_number(stdout,nc_long(6),eflag,n(6)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 96, eflag, &n[6], (
		    ftnlen)16);
/* SOURCE ntwmxstr.for:1067 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:1068 */
/*<       n(6)=0 >*/
	    n[6] = 0;
/* SOURCE ntwmxstr.for:1069 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:1070 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1071 */
/*<       goto8000 >*/
    goto L8000;
/*     CRITICAL DEPTH */
/* SOURCE ntwmxstr.for:1075 */
/*<     8 continue >*/
L8:
/* SOURCE ntwmxstr.for:1076 */
/*<       callfndinn(nc(1),enoden,usenin,eflag,inenus,n(1)) >*/
    fndinn_(nc + 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[1], (ftnlen)
	    5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1080 */
/*<       goto8000 >*/
    goto L8000;
/*     Code number available. */
/* SOURCE ntwmxstr.for:1085 */
/*<     9 continue >*/
L9:
/* SOURCE ntwmxstr.for:1086 */
/*<       goto8000 >*/
    goto L8000;
/*       ENERGY HEAD EQUALITY */
/* SOURCE ntwmxstr.for:1090 */
/*<    10 continue >*/
L10:
/* SOURCE ntwmxstr.for:1091 */
/*<       callcnvenf(nc(1),prefix,num) >*/
    cnvenf_(nc + 5, prefix, &num, (ftnlen)5, (ftnlen)1);
/* SOURCE ntwmxstr.for:1094 */
/*<       callfndinn(nc(1),enoden,usenin,eflag,inenus,n(1)) >*/
    fndinn_(nc + 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[1], (ftnlen)
	    5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1098 */
/*<       callfndinn(nc(2),enoden,usenin,eflag,inenus,n(2)) >*/
    fndinn_(nc + 10, enoden, &usenin[-9999], eflag, inenus + 5, &n[2], (
	    ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1102 */
/*<       goto8000 >*/
    goto L8000;
/*       MOMENTUM FLUX PLUS PRESSURE FORCE EQUALITY.  USE ONLY */
/*       IF UPSTREAM AND DOWNSTREAM SECTION ARE SAME SIZE AND FLOW */
/*       CHANGES AT RIGHT ANGLES TO THE CHANNEL TAKE PLACE */
/* SOURCE ntwmxstr.for:1108 */
/*<    11 continue >*/
L11:
/* SOURCE ntwmxstr.for:1110 */
/*<       callfndinn(nc(1),enoden,usenin,eflag,inenus,n(1)) >*/
    fndinn_(nc + 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[1], (ftnlen)
	    5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1114 */
/*<       callfndinn(nc(2),enoden,usenin,eflag,inenus,n(2)) >*/
    fndinn_(nc + 10, enoden, &usenin[-9999], eflag, inenus + 5, &n[2], (
	    ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1118 */
/*<       goto8000 >*/
    goto L8000;
/*       MATCH AN AVERAGE ELEVATION WITH THE ELEVATION AT A THIRD NODE */
/*       USEFUL WHEN MOMENTUM IS CONSERVED AT A JUNCTION INVOLVING A */
/*       RIGHT ANGLED ENTRY OR NEARLY SO! */
/* SOURCE ntwmxstr.for:1124 */
/*<    12 continue >*/
L12:
/* SOURCE ntwmxstr.for:1126 */
/*<       do120i=1,3 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 3; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:1127 */
/*<       callfndinn(nc(i),enoden,usenin,eflag,inenus,n(i)) >*/
	fndinn_(nc + feq_gen_i_d_ * 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[
		feq_gen_i_d_], (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1131 */
/*<   120 continue >*/
/* L120: */
    }
/* SOURCE ntwmxstr.for:1132 */
/*<       goto8000 >*/
    goto L8000;
/*       EQUALITY OF MOMENTUM AT A SIMPLE JUNCTION IF FLOW IS */
/*       ENTERING OR EQUALITY OF SPECIFIC ENERGY IF FLOW IS LEAVING */
/*       REPLACEMENT FOR CODE 11 BUT CODE 11 IS RETAINED FOR */
/*       CONSISTENCY WITH PAST USAGE AND FOR SPECIAL CASES. */
/* SOURCE ntwmxstr.for:1139 */
/*<    13 continue >*/
L13:
/* SOURCE ntwmxstr.for:1140 */
/*<       callfndinn(nc(1),enoden,usenin,eflag,inenus,n(1)) >*/
    fndinn_(nc + 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[1], (ftnlen)
	    5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1144 */
/*<       callfndinn(nc(2),enoden,usenin,eflag,inenus,n(2)) >*/
    fndinn_(nc + 10, enoden, &usenin[-9999], eflag, inenus + 5, &n[2], (
	    ftnlen)5, (ftnlen)5);
/*         Get the number of side nodes. */
/* SOURCE ntwmxstr.for:1150 */
/*<       n(3)=fndnum(nc(3)) >*/
    n[3] = fndnum_(nc + 15, (ftnlen)5);
/* SOURCE ntwmxstr.for:1151 */
/*<       do1301i=1,n(3) >*/
    feq_gen_i_d_1 = n[3];
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:1152 */
/*<       callfndinn(nc(3+i),enoden,usenin,eflag,inenus,n(3+i)) >*/
	fndinn_(nc + (feq_gen_i_d_ + 3) * 5, enoden, &usenin[-9999], eflag, inenus + 5,
		 &n[feq_gen_i_d_ + 3], (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1156 */
/*<  1301 continue >*/
/* L1301: */
    }
/* SOURCE ntwmxstr.for:1157 */
/*<       goto8000 >*/
    goto L8000;
/*     SIDE-WEIR FLOW COMPUTATION. USED IN CONJUNCTION WITH */
/*     CODE 13. */
/* SOURCE ntwmxstr.for:1162 */
/*<    14 continue >*/
L14:
/* SOURCE ntwmxstr.for:1163 */
/*<       do140i=1,3 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 3; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:1164 */
/*<       callfndinn(nc(i),enoden,usenin,eflag,inenus,n(i)) >*/
	fndinn_(nc + feq_gen_i_d_ * 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[
		feq_gen_i_d_], (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1168 */
/*<   140 continue >*/
/* L140: */
    }
/*         Process the tabid for the U to D flow table */
/* SOURCE ntwmxstr.for:1170 */
/*<       callget_internal_tab_number(stdout,nc_long(4),eflag,n(4)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 64, eflag, &n[4], (ftnlen)
	    16);
/*         Process the tabid for the D to U flow table */
/* SOURCE ntwmxstr.for:1175 */
/*<       callget_internal_tab_number(stdout,nc_long(5),eflag,n(5)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 80, eflag, &n[5], (ftnlen)
	    16);
/*         Process the tabid for the optional table giving an adjustment */
/*         factor as a function of time. */
/* SOURCE ntwmxstr.for:1181 */
/*<       if(nc_long(6).ne.' ')then >*/
    if (s_cmp(feq_gen_nc_long_d_ + 96, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE ntwmxstr.for:1182 */
/*<       callget_internal_tab_number(stdout,nc_long(6),eflag,n(6)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 96, eflag, &n[6], (
		ftnlen)16);
/* SOURCE ntwmxstr.for:1186 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:1187 */
/*<       n(6)=0 >*/
	n[6] = 0;
/* SOURCE ntwmxstr.for:1188 */
/*<       endif >*/
    }
/*         Process the tabid for the optional table giving the fractional */
/*         crest change as a function of time. */
/* SOURCE ntwmxstr.for:1192 */
/*<       if(nc_long(7).ne.' ')then >*/
    if (s_cmp(feq_gen_nc_long_d_ + 112, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE ntwmxstr.for:1193 */
/*<       callget_internal_tab_number(stdout,nc_long(7),eflag,n(7)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, feq_gen_nc_long_d_ + 112, eflag, &n[7], (
		ftnlen)16);
/* SOURCE ntwmxstr.for:1197 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:1198 */
/*<       n(7)=0 >*/
	n[7] = 0;
/* SOURCE ntwmxstr.for:1199 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1200 */
/*<       goto8000 >*/
    goto L8000;
/*       DUMMY BRANCH */
/* SOURCE ntwmxstr.for:1204 */
/*<    15 continue >*/
L15:
/* SOURCE ntwmxstr.for:1205 */
/*<       callfndinn(nc(1),enoden,usenin,eflag,inenus,n(1)) >*/
    fndinn_(nc + 5, enoden, &usenin[-9999], eflag, inenus + 5, &n[1], (ftnlen)
	    5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1209 */
/*<       callfndinn(nc(2),enoden,usenin,eflag,inenus,n(2)) >*/
    fndinn_(nc + 10, enoden, &usenin[-9999], eflag, inenus + 5, &n[2], (
	    ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:1213 */
/*<       goto8000 >*/
    goto L8000;
/* SOURCE ntwmxstr.for:1215 */
/*<  8000 continue >*/
L8000:
/* SOURCE ntwmxstr.for:1217 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:1218 */
/*<       end >*/
} /* cnvrtn_ */




/* SOURCE ntwmxstr.for:1222 */
/*<       character*4functionconchr(id) >*/
/* Character */ VOID conchr_(char *ret_val, ftnlen ret_val_len, integer *id)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     + + + PURPOSE + + + */
/*     Return string for the connecting id number. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1229 */
/*<       integerid >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ID     - connecting id number */
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:1234 */
/*<       if(id.eq.1)then >*/
    if (*id == 1) {
/* SOURCE ntwmxstr.for:1235 */
/*<       conchr='BRA ' >*/
	s_copy(ret_val, const_cast<char*>("BRA "), (ftnlen)4, (ftnlen)4);
/* SOURCE ntwmxstr.for:1236 */
/*<       elseif(id.eq.2)then >*/
    } else if (*id == 2) {
/* SOURCE ntwmxstr.for:1237 */
/*<       conchr='JUNC' >*/
	s_copy(ret_val, const_cast<char*>("JUNC"), (ftnlen)4, (ftnlen)4);
/* SOURCE ntwmxstr.for:1238 */
/*<       elseif(id.eq.3)then >*/
    } else if (*id == 3) {
/* SOURCE ntwmxstr.for:1239 */
/*<       conchr='BC  ' >*/
	s_copy(ret_val, const_cast<char*>("BC  "), (ftnlen)4, (ftnlen)4);
/* SOURCE ntwmxstr.for:1240 */
/*<       elseif(id.eq.4)then >*/
    } else if (*id == 4) {
/* SOURCE ntwmxstr.for:1241 */
/*<       conchr='NB  ' >*/
	s_copy(ret_val, const_cast<char*>("NB  "), (ftnlen)4, (ftnlen)4);
/* SOURCE ntwmxstr.for:1242 */
/*<       elseif(id.eq.5)then >*/
    } else if (*id == 5) {
/* SOURCE ntwmxstr.for:1243 */
/*<       conchr='LPR ' >*/
	s_copy(ret_val, const_cast<char*>("LPR "), (ftnlen)4, (ftnlen)4);
/* SOURCE ntwmxstr.for:1244 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:1245 */
/*<       conchr='????' >*/
	s_copy(ret_val, const_cast<char*>("????"), (ftnlen)4, (ftnlen)4);
/* SOURCE ntwmxstr.for:1246 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1247 */
/*<       return >*/
    return ;
/* SOURCE ntwmxstr.for:1248 */
/*<       end >*/
} /* conchr_ */




/* SOURCE ntwmxstr.for:1252 */
/*<       integerfunctionexnodn(node,jpt,ljoin,join) >*/
integer exnodn_(integer *node, integer *jpt, integer *ljoin, integer *feq_storage_join)
{
    /* System generated locals */
    integer ret_val, feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, ie, is;

/*     + + + PURPOSE + + + */
/*     Find the address of the node number in NODE in the list of */
/*     nodes for the junction given by JPT.  Return zero if NODE */
/*     not found in the list. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1261 */
/*<       integerjpt,ljoin,node >*/
/* SOURCE ntwmxstr.for:1262 */
/*<       integerjoin(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NODE   - node number */
/*     JPT    - pointer for the junction descriptions */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:1271 */
/*<       integeri,ie,is >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:1273 */
/*<       is=jpt+4 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    /* Function Body */
    is = *jpt + 4;
/* SOURCE ntwmxstr.for:1274 */
/*<       ie=is+join(jpt)-1 >*/
    ie = is + join[*jpt] - 1;
/* SOURCE ntwmxstr.for:1275 */
/*<       do100i=is,ie >*/
    feq_gen_i_d_1 = ie;
    for (feq_gen_i_d_ = is; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:1276 */
/*<       if(node.eq.join(i))then >*/
	if (*node == join[feq_gen_i_d_]) {
/* SOURCE ntwmxstr.for:1277 */
/*<       exnodn=i >*/
	    ret_val = feq_gen_i_d_;
/* SOURCE ntwmxstr.for:1278 */
/*<       return >*/
	    return ret_val;
/* SOURCE ntwmxstr.for:1279 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:1280 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE ntwmxstr.for:1281 */
/*<       exnodn=0 >*/
    ret_val = 0;
/* SOURCE ntwmxstr.for:1282 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:1283 */
/*<       end >*/
} /* exnodn_ */




/* SOURCE ntwmxstr.for:1287 */
/*<       integerfunctionfdnumr(node,jpt,ljoin,join) >*/
integer fdnumr_(integer *node, integer *jpt, integer *ljoin, integer *feq_storage_join)
{
    /* System generated locals */
    integer ret_val;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, knt, rpt, emcadr, nodadr;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    integer nxtadr;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__48 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Return the number of  relationships at NODE.  All codes can be */
/*     counted. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1295 */
/*<       integerjpt,ljoin,node >*/
/* SOURCE ntwmxstr.for:1296 */
/*<       integerjoin(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NODE   - node number */
/*     JPT    - pointer for the junction descriptions */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:1305 */
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
/* SOURCE ntwmxstr.for:1308 */
/*<       integeremcadr,knt,n,nodadr,nxtadr,rpt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:1311 */
/*<       integerexnodn >*/
/* SOURCE ntwmxstr.for:1312 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:1315 */
/*<       externalexnodn,getusn >*/
/* *********************************************************************** */
/*     SET NUMBER OF NODES */
/* SOURCE ntwmxstr.for:1318 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    /* Function Body */
    n = join[*jpt];
/* SOURCE ntwmxstr.for:1320 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:1321 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:1322 */
/*<        >*/
	feq_gen_io_d__48.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__48);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* FDNUMR:NODE="), (ftnlen)23);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT IN"), (ftnlen)7);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" LIST. JPT="), (ftnlen)11);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE ntwmxstr.for:1324 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1325 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1327 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE ntwmxstr.for:1328 */
/*<       nxtadr=join(nodadr+2*n) >*/
    nxtadr = join[nodadr + (n << 1)];
/* SOURCE ntwmxstr.for:1330 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:1331 */
/*<       if(nxtadr.gt.0)then >*/
    if (nxtadr > 0) {
/* SOURCE ntwmxstr.for:1332 */
/*<       rpt=join(nxtadr+1) >*/
	rpt = join[nxtadr + 1];
/* SOURCE ntwmxstr.for:1333 */
/*<       emcadr=join(rpt) >*/
	emcadr = join[rpt];
/* SOURCE ntwmxstr.for:1334 */
/*<       if(emcadr.gt.0)then >*/
	if (emcadr > 0) {
/* SOURCE ntwmxstr.for:1335 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE ntwmxstr.for:1336 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:1337 */
/*<       nxtadr=join(nxtadr) >*/
	nxtadr = join[nxtadr];
/* SOURCE ntwmxstr.for:1338 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:1339 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1341 */
/*<       fdnumr=knt >*/
    ret_val = knt;
/* SOURCE ntwmxstr.for:1342 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:1343 */
/*<       end >*/
} /* fdnumr_ */




/* SOURCE ntwmxstr.for:1347 */
/*<       subroutinefind4(jpt,node,ljoin,lemc,emc,join,node2,radr) >*/
/* Subroutine */ int find4_(integer *jpt, integer *node, integer *ljoin, 
	integer *lemc, integer *feq_storage_emc, integer *feq_storage_join, integer *node2, integer *
	radr)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, rpt, code, qnode, emcadr, nodadr;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    integer nxtadr;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__55 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find code 4 relationship with flow node at NODE.  If flow node */
/*     and head node are the same then NODE2 = 0 otherwise NODE2 */
/*     is the flow node.  Return address of relationship in EMC if found */
/*     and zero otherwise. */
/* SOURCE ntwmxstr.for:1358 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1360 */
/*<       integerjpt,lemc,ljoin,node,node2,radr >*/
/* SOURCE ntwmxstr.for:1361 */
/*<       integeremc(lemc),join(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JPT    - pointer for the junction descriptions */
/*     NODE   - node number */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     JOIN   - vector for storing the junction descriptions */
/*     NODE2  - second node in relationship if any exists */
/*     RADR   - relationship address */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:1374 */
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
/* SOURCE ntwmxstr.for:1377 */
/*<       integercode,emcadr,n,nodadr,nxtadr,qnode,rpt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:1380 */
/*<       integerexnodn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:1383 */
/*<       externalexnodn >*/
/* *********************************************************************** */
/*     GET THE NUMBER OF NODES */
/* SOURCE ntwmxstr.for:1386 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    n = join[*jpt];
/*     FIND THE NODE IN THE LIST */
/* SOURCE ntwmxstr.for:1389 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:1390 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:1391 */
/*<       write(std6,*)' *BUG:* NODE NOT IN NODE LIST IN FIND4.' >*/
	feq_gen_io_d__55.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__55);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:* NODE NOT IN NODE LIST IN FIND4."), (
		ftnlen)39);
	e_wsle();
/* SOURCE ntwmxstr.for:1392 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1393 */
/*<       endif >*/
    }
/*     GET THE POINTER TO THE FIRST RELATIONSHIP POINTER RECORD */
/* SOURCE ntwmxstr.for:1396 */
/*<       nxtadr=join(nodadr+2*n) >*/
    nxtadr = join[nodadr + (n << 1)];
/*     SCAN THE RELATIONSHIPS IN THE LIST FOR THIS NODE FOR A MATCH */
/* SOURCE ntwmxstr.for:1399 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:1400 */
/*<       if(nxtadr.gt.0)then >*/
    if (nxtadr > 0) {
/*         GET THE POINTER TO THE RELATIONSHIP POINTER */
/* SOURCE ntwmxstr.for:1402 */
/*<       rpt=join(nxtadr+1) >*/
	rpt = join[nxtadr + 1];
/*         GET THE SECOND NODE.  ALREADY SET PROPERLY IN THE JUNCTION */
/* SOURCE ntwmxstr.for:1404 */
/*<       node2=join(nxtadr+2) >*/
	*node2 = join[nxtadr + 2];
/*         GET THE POINTER TO THE RELATIONSHIP */
/* SOURCE ntwmxstr.for:1407 */
/*<       emcadr=join(rpt) >*/
	emcadr = join[rpt];
/* SOURCE ntwmxstr.for:1408 */
/*<       if(emcadr.gt.0)then >*/
	if (emcadr > 0) {
/*           A RELATIONSHIP IS AVAILABLE */
/* SOURCE ntwmxstr.for:1410 */
/*<       code=emc(emcadr) >*/
	    code = emc[emcadr];
/* SOURCE ntwmxstr.for:1411 */
/*<       if(code.eq.4)then >*/
	    if (code == 4) {
/*             FOUND THE CODE WE ARE SEEKING.  CHECK FLOW NODE. */
/* SOURCE ntwmxstr.for:1413 */
/*<       qnode=emc(emcadr+4) >*/
		qnode = emc[emcadr + 4];
/* SOURCE ntwmxstr.for:1414 */
/*<       if(qnode.eq.node)then >*/
		if (qnode == *node) {
/*               FOUND MATCH! */
/* SOURCE ntwmxstr.for:1416 */
/*<       radr=emcadr >*/
		    *radr = emcadr;
/*               MARK RELATIONSHIP AS UNAVAILABLE */
/* SOURCE ntwmxstr.for:1418 */
/*<       join(rpt)=-emcadr >*/
		    join[rpt] = -emcadr;
/* SOURCE ntwmxstr.for:1419 */
/*<       return >*/
		    return 0;
/* SOURCE ntwmxstr.for:1420 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:1421 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:1422 */
/*<       endif >*/
	}
/*         GET THE ADDRESS OF THE NEXT RECORD IN THE LIST */
/* SOURCE ntwmxstr.for:1425 */
/*<       nxtadr=join(nxtadr) >*/
	nxtadr = join[nxtadr];
/* SOURCE ntwmxstr.for:1426 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:1427 */
/*<       endif >*/
    }
/*     IF WE REACH HERE NO RELATIONSHIP MATCH WAS FOUND. */
/* SOURCE ntwmxstr.for:1431 */
/*<       radr=0 >*/
    *radr = 0;
/* SOURCE ntwmxstr.for:1432 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:1433 */
/*<       end >*/
} /* find4_ */




/* SOURCE ntwmxstr.for:1437 */
/*<       subroutinefind8(jpt,node,ljoin,lemc,emc,join,node2,radr) >*/
/* Subroutine */ int find8_(integer *jpt, integer *node, integer *ljoin, 
	integer *lemc, integer *feq_storage_emc, integer *feq_storage_join, integer *node2, integer *
	radr)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, rpt, code, emcadr, nodadr;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    integer nxtadr;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__63 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find any code 8 at node NODE and return the address of the code */
/*     8 relationship in EMC.  If not found, return zero.  If found, */
/*     mark the relationship as in use.  Return NODE2 as zero because */
/*     code 8 never involves more than one node. */
/* SOURCE ntwmxstr.for:1448 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1450 */
/*<       integerjpt,lemc,ljoin,node,node2,radr >*/
/* SOURCE ntwmxstr.for:1451 */
/*<       integeremc(lemc),join(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JPT    - pointer for the junction descriptions */
/*     NODE   - node number */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     JOIN   - vector for storing the junction descriptions */
/*     NODE2  - second node in relationship if any exists */
/*     RADR   - relationship address */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:1464 */
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
/* SOURCE ntwmxstr.for:1467 */
/*<       integercode,emcadr,n,nodadr,nxtadr,rpt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:1470 */
/*<       integerexnodn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:1473 */
/*<       externalexnodn >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:1475 */
/*<       node2=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    *node2 = 0;
/*     SET THE NUMBER OF NODES AT THE JUNCTION */
/* SOURCE ntwmxstr.for:1478 */
/*<       n=join(jpt) >*/
    n = join[*jpt];
/*     FIND THE ADDRESS FOR THE NODE IN THE NODE LIST */
/* SOURCE ntwmxstr.for:1482 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:1483 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:1484 */
/*<       write(std6,*)' *BUG:* NODE NOT IN NODE LIST IN FIND8.' >*/
	feq_gen_io_d__63.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__63);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:* NODE NOT IN NODE LIST IN FIND8."), (
		ftnlen)39);
	e_wsle();
/* SOURCE ntwmxstr.for:1485 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1486 */
/*<       endif >*/
    }
/*     GET THE POINTER TO THE FIRST RELATIONSHIP POINTER RECORD */
/* SOURCE ntwmxstr.for:1489 */
/*<       nxtadr=join(nodadr+2*n) >*/
    nxtadr = join[nodadr + (n << 1)];
/*     FIND EACH RELATIONSHIP IN THE LIST FOR NODE.  IF RELATIONSHIP IS */
/*     AVAILABLE, CHECK THE CODE IN EMC.  IF CODE IS 8 GET ADDRESS IN */
/*     EMC OF THE RELATION AND RETURN IT. */
/* SOURCE ntwmxstr.for:1495 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:1496 */
/*<       if(nxtadr.gt.0)then >*/
    if (nxtadr > 0) {
/*         THERE IS A NEXT RECORD IN THE LIST. GET DATA AND CHECK */
/*         GET THE POINTER TO THE POINTER TO THE RELATIONSHIP. */
/* SOURCE ntwmxstr.for:1499 */
/*<       rpt=join(nxtadr+1) >*/
	rpt = join[nxtadr + 1];
/*         GET THE ADDRESS IN EMC */
/* SOURCE ntwmxstr.for:1501 */
/*<       emcadr=join(rpt) >*/
	emcadr = join[rpt];
/* SOURCE ntwmxstr.for:1502 */
/*<       if(emcadr.gt.0)then >*/
	if (emcadr > 0) {
/*           RELATIONSHIP IS AVAILABLE */
/* SOURCE ntwmxstr.for:1504 */
/*<       code=emc(emcadr) >*/
	    code = emc[emcadr];
/* SOURCE ntwmxstr.for:1507 */
/*<       if(code.eq.8)then >*/
	    if (code == 8) {
/*             FOUND IT! */
/* SOURCE ntwmxstr.for:1509 */
/*<       radr=emcadr >*/
		*radr = emcadr;
/*             MARK THE RELATIONSHIP AS UNAVAILABLE */
/* SOURCE ntwmxstr.for:1511 */
/*<       join(rpt)=-emcadr >*/
		join[rpt] = -emcadr;
/* SOURCE ntwmxstr.for:1512 */
/*<       return >*/
		return 0;
/* SOURCE ntwmxstr.for:1513 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:1514 */
/*<       endif >*/
	}
/*         GET THE ADDRESS OF THE NEXT RECORD IN THE LIST */
/* SOURCE ntwmxstr.for:1518 */
/*<       nxtadr=join(nxtadr) >*/
	nxtadr = join[nxtadr];
/* SOURCE ntwmxstr.for:1519 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:1520 */
/*<       endif >*/
    }
/*     IF WE GET HERE CODE 8 WAS NOT FOUND */
/* SOURCE ntwmxstr.for:1524 */
/*<       radr=0 >*/
    *radr = 0;
/* SOURCE ntwmxstr.for:1525 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:1526 */
/*<       end >*/
} /* find8_ */




/* SOURCE ntwmxstr.for:1530 */
/*<       subroutinefnd4(stdout,exn,emc,ept,ipnt) >*/
/* Subroutine */ int fnd4_(integer *stdout, integer *exn, integer *feq_storage_emc, 
	integer *ept, integer *ipnt)
{
    /* Format strings */
    static char fmt_10[] = "(/,\002 *ERR:89* Exterior node = \002,a5,\002 no\
t found in \002,\002Network-Matrix Control with Code = 4\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer code, ientry;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_10, 0 };


/*     + + + PURPOSE + + + */
/*     Find location of CODE = 4 with a head node equal */
/*     to EXN in the network-matrix control vector. */
/* SOURCE ntwmxstr.for:1538 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1540 */
/*<       integerexn,ipnt,stdout,ept >*/
/* SOURCE ntwmxstr.for:1541 */
/*<       integeremc(ept) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     EXN    - exterior node number */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     MLEMC  - maximum length of EMC(*) */
/*     IPNT   - pointer into EMC for description of control structure */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:1551 */
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
/* INCLUDE ntwmxstr.for:1552 */
/* *********************************************************************** */
/*     COMMON BLOCK FOR PROFILE MATRIX SOLUTION. */
/* SOURCE matcom.cmn:4 */
/*<        >*/
/* SOURCE matcom.cmn:8 */
/*<       common/matcom2/pdavec2,rhs2 >*/
/* SOURCE matcom.cmn:10 */
/*<       integermatblk,numeq,nentry >*/
/* SOURCE matcom.cmn:12 */
/*<        >*/
/* SOURCE matcom.cmn:16 */
/*<       realpdavec(mlpda),rhs(mrmat),hi_iq_ns_fac(mrmat) >*/
/*     Add second set to help in diagnostics-at least as a trial. */
/* SOURCE matcom.cmn:19 */
/*<       realpdavec2(mlpda),rhs2(mrmat) >*/
/* *********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:1555 */
/*<       integercode,ientry >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:1558 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:1561 */
/*<       externalgetusn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:1564 */
/*<    10  >*/
/* *********************************************************************** */
/*     START SEARCH */
/* SOURCE ntwmxstr.for:1568 */
/*<       ientry=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L10: */
    ientry = 0;
/* SOURCE ntwmxstr.for:1570 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:1571 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE ntwmxstr.for:1572 */
/*<       ipnt=add(ientry) >*/
    *ipnt = matcom_1.add[ientry - 1];
/* SOURCE ntwmxstr.for:1573 */
/*<       code=emc(ipnt) >*/
    code = emc[*ipnt];
/* SOURCE ntwmxstr.for:1574 */
/*<       if(code.eq.4)then >*/
    if (code == 4) {
/*         CODE = 4.  Check if the head node matches EXN. */
/* SOURCE ntwmxstr.for:1576 */
/*<       if(exn.eq.emc(ipnt+2))return >*/
	if (*exn == emc[*ipnt + 2]) {
	    return 0;
	}
/* SOURCE ntwmxstr.for:1577 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1579 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE ntwmxstr.for:1581 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:1582 */
/*<       else >*/
    } else {
/*         End of Network-Matrix Control data. */
/* SOURCE ntwmxstr.for:1584 */
/*<       write(stdout,10)getusn(exn) >*/
	feq_gen_io_d__70.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__70);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, exn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	e_wsfe();
/* SOURCE ntwmxstr.for:1585 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1586 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1587 */
/*<       end >*/
    return 0;
} /* fnd4_ */




/* SOURCE ntwmxstr.for:1591 */
/*<       subroutinefnd5(stdout,type,uexn,dexn,emc,ept,ipnt) >*/
/* Subroutine */ int fnd5_(integer *stdout, integer *feq_gen_type_d_, integer *uexn, 
	integer *dexn, integer *feq_storage_emc, integer *ept, integer *ipnt)
{
    /* Format strings */
    static char fmt_10[] = "(/,\002 *ERR:245* TYPE=\002,i5,\002 and nodes\
:\002,2a6,\002 not\002,\002 found in Network-Matrix Control with CODE = 5\
\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer code, ientry;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_10, 0 };


/*     + + + PURPOSE + + + */
/*     Find location of CODE = 5 with TYPE and upstream and */
/*     downstream nodes as given in the network-matrix control vector. */
/* SOURCE ntwmxstr.for:1599 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1601 */
/*<       integerdexn,ept,ipnt,stdout,type,uexn >*/
/* SOURCE ntwmxstr.for:1602 */
/*<       integeremc(ept) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TYPE   - code type being sought */
/*     UEXN   - upstream exterior node */
/*     DEXN   - downstream exterior node number */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     MLEMC  - maximum length of EMC(*) */
/*     IPNT   - pointer into EMC for description of control structure */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:1614 */
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
/* INCLUDE ntwmxstr.for:1615 */
/* *********************************************************************** */
/*     COMMON BLOCK FOR PROFILE MATRIX SOLUTION. */
/* SOURCE matcom.cmn:4 */
/*<        >*/
/* SOURCE matcom.cmn:8 */
/*<       common/matcom2/pdavec2,rhs2 >*/
/* SOURCE matcom.cmn:10 */
/*<       integermatblk,numeq,nentry >*/
/* SOURCE matcom.cmn:12 */
/*<        >*/
/* SOURCE matcom.cmn:16 */
/*<       realpdavec(mlpda),rhs(mrmat),hi_iq_ns_fac(mrmat) >*/
/*     Add second set to help in diagnostics-at least as a trial. */
/* SOURCE matcom.cmn:19 */
/*<       realpdavec2(mlpda),rhs2(mrmat) >*/
/* *********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:1618 */
/*<       integercode,ientry >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:1621 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:1624 */
/*<       externalgetusn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:1627 */
/*<    10  >*/
/* *********************************************************************** */
/*     START SEARCH */
/* SOURCE ntwmxstr.for:1631 */
/*<       ientry=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L10: */
    ientry = 0;
/* SOURCE ntwmxstr.for:1633 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:1634 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE ntwmxstr.for:1635 */
/*<       ipnt=add(ientry) >*/
    *ipnt = matcom_1.add[ientry - 1];
/* SOURCE ntwmxstr.for:1636 */
/*<       code=emc(ipnt) >*/
    code = emc[*ipnt];
/* SOURCE ntwmxstr.for:1637 */
/*<       if(code.eq.5)then >*/
    if (code == 5) {
/*         CODE = 5.  Check for type. */
/* SOURCE ntwmxstr.for:1639 */
/*<       if(type.eq.emc(ipnt+1))then >*/
	if (*feq_gen_type_d_ == emc[*ipnt + 1]) {
/*           Found match for type */
/* SOURCE ntwmxstr.for:1641 */
/*<       if(uexn.eq.emc(ipnt+2))then >*/
	    if (*uexn == emc[*ipnt + 2]) {
/*             Found match for upstream node. */
/* SOURCE ntwmxstr.for:1643 */
/*<       if(dexn.eq.emc(ipnt+3))then >*/
		if (*dexn == emc[*ipnt + 3]) {
/*               Found match for downstream node. */
/* SOURCE ntwmxstr.for:1645 */
/*<       return >*/
		    return 0;
/* SOURCE ntwmxstr.for:1646 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:1647 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:1648 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:1649 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1651 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE ntwmxstr.for:1653 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:1654 */
/*<       else >*/
    } else {
/*         End of Network-Matrix Control data. */
/* SOURCE ntwmxstr.for:1656 */
/*<       write(stdout,10)type,getusn(uexn),getusn(dexn) >*/
	feq_gen_io_d__73.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__73);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_type_d_), (ftnlen)sizeof(integer));
	getusn_(feq_gen_ch_d_2, (ftnlen)5, uexn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	getusn_(feq_gen_ch_d_4, (ftnlen)5, dexn);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	e_wsfe();
/* SOURCE ntwmxstr.for:1657 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1658 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1659 */
/*<       end >*/
    return 0;
} /* fnd5_ */




/* SOURCE ntwmxstr.for:1663 */
/*<       subroutinefnd514(jpt,node,ljoin,lemc,emc,join,node2,radr) >*/
/* Subroutine */ int fnd514_(integer *jpt, integer *node, integer *ljoin, 
	integer *lemc, integer *feq_storage_emc, integer *feq_storage_join, integer *node2, integer *
	radr)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, rpt, code, qnode, emcadr, nodadr;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    integer nxtadr;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__76 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find code 5 or 14 relationship with flow node at NODE. */
/*     NODE2 is set properly in the junction already. */
/* SOURCE ntwmxstr.for:1672 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1674 */
/*<       integerjpt,lemc,ljoin,node,node2,radr >*/
/* SOURCE ntwmxstr.for:1675 */
/*<       integeremc(lemc),join(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JPT    - pointer for the junction descriptions */
/*     NODE   - node number */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     JOIN   - vector for storing the junction descriptions */
/*     NODE2  - second node in relationship if any exists */
/*     RADR   - relationship address */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:1688 */
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
/* SOURCE ntwmxstr.for:1691 */
/*<       integercode,emcadr,n,nodadr,nxtadr,qnode,rpt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:1694 */
/*<       integerexnodn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:1697 */
/*<       externalexnodn >*/
/* *********************************************************************** */
/*     GET THE NUMBER OF NODES */
/* SOURCE ntwmxstr.for:1700 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    n = join[*jpt];
/*     FIND THE NODE IN THE LIST */
/* SOURCE ntwmxstr.for:1703 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:1704 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:1705 */
/*<       write(std6,*)' *BUG:* NODE NOT IN NODE LIST IN FND514.' >*/
	feq_gen_io_d__76.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__76);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:* NODE NOT IN NODE LIST IN FND514."), (
		ftnlen)40);
	e_wsle();
/* SOURCE ntwmxstr.for:1706 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1707 */
/*<       endif >*/
    }
/*     GET THE POINTER TO THE FIRST RELATIONSHIP POINTER RECORD */
/* SOURCE ntwmxstr.for:1710 */
/*<       nxtadr=join(nodadr+2*n) >*/
    nxtadr = join[nodadr + (n << 1)];
/*     SCAN THE RELATIONSHIPS IN THE LIST FOR THIS NODE FOR A MATCH */
/* SOURCE ntwmxstr.for:1713 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:1714 */
/*<       if(nxtadr.gt.0)then >*/
    if (nxtadr > 0) {
/*         GET THE POINTER TO THE RELATIONSHIP POINTER */
/* SOURCE ntwmxstr.for:1716 */
/*<       rpt=join(nxtadr+1) >*/
	rpt = join[nxtadr + 1];
/*         GET THE SECOND NODE.  ALREADY SET PROPERLY IN THE JUNCTION */
/* SOURCE ntwmxstr.for:1718 */
/*<       node2=join(nxtadr+2) >*/
	*node2 = join[nxtadr + 2];
/*         GET THE POINTER TO THE RELATIONSHIP */
/* SOURCE ntwmxstr.for:1721 */
/*<       emcadr=join(rpt) >*/
	emcadr = join[rpt];
/* SOURCE ntwmxstr.for:1722 */
/*<       if(emcadr.gt.0)then >*/
	if (emcadr > 0) {
/*           A RELATIONSHIP IS AVAILABLE */
/* SOURCE ntwmxstr.for:1724 */
/*<       code=emc(emcadr) >*/
	    code = emc[emcadr];
/* SOURCE ntwmxstr.for:1725 */
/*<       if(code.eq.5)then >*/
	    if (code == 5) {
/*             FOUND A CODE WE ARE SEEKING.  CHECK FLOW NODE. */
/* SOURCE ntwmxstr.for:1727 */
/*<       qnode=emc(emcadr+4) >*/
		qnode = emc[emcadr + 4];
/* SOURCE ntwmxstr.for:1728 */
/*<       if(qnode.eq.node)then >*/
		if (qnode == *node) {
/*               FOUND MATCH! */
/* SOURCE ntwmxstr.for:1730 */
/*<       radr=emcadr >*/
		    *radr = emcadr;
/*               MARK RELATIONSHIP AS UNAVAILABLE */
/* SOURCE ntwmxstr.for:1732 */
/*<       join(rpt)=-emcadr >*/
		    join[rpt] = -emcadr;
/* SOURCE ntwmxstr.for:1733 */
/*<       return >*/
		    return 0;
/* SOURCE ntwmxstr.for:1734 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:1735 */
/*<       elseif(code.eq.14)then >*/
	    } else if (code == 14) {
/*             FOUND A CODE WE ARE SEEKING.  CHECK FLOW NODE. */
/* SOURCE ntwmxstr.for:1737 */
/*<       qnode=emc(emcadr+3) >*/
		qnode = emc[emcadr + 3];
/* SOURCE ntwmxstr.for:1738 */
/*<       if(qnode.eq.node)then >*/
		if (qnode == *node) {
/*               FOUND MATCH! */
/* SOURCE ntwmxstr.for:1740 */
/*<       radr=emcadr >*/
		    *radr = emcadr;
/*               Mark relationship as unavailable. */
/* SOURCE ntwmxstr.for:1742 */
/*<       join(rpt)=-emcadr >*/
		    join[rpt] = -emcadr;
/* SOURCE ntwmxstr.for:1743 */
/*<       return >*/
		    return 0;
/* SOURCE ntwmxstr.for:1744 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:1745 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:1746 */
/*<       endif >*/
	}
/*         GET THE ADDRESS OF THE NEXT RECORD IN THE LIST */
/* SOURCE ntwmxstr.for:1749 */
/*<       nxtadr=join(nxtadr) >*/
	nxtadr = join[nxtadr];
/* SOURCE ntwmxstr.for:1750 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:1751 */
/*<       endif >*/
    }
/*     IF WE REACH HERE NO RELATIONSHIP MATCH WAS FOUND. */
/* SOURCE ntwmxstr.for:1755 */
/*<       radr=0 >*/
    *radr = 0;
/* SOURCE ntwmxstr.for:1756 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:1757 */
/*<       end >*/
} /* fnd514_ */




/* SOURCE ntwmxstr.for:1761 */
/*<       subroutinefnd7(stdout,rnode,emc,mlemc,inode,adrs) >*/
/* Subroutine */ int fnd7_(integer *stdout, integer *rnode, integer *feq_storage_emc, 
	integer *mlemc, integer *inode, integer *adrs)
{
    /* Format strings */
    static char fmt_10[] = "(/,\002 *BUG:XXX* Reservoir node=\002,a5,\002 an\
d inflow node=\002,a5,\002 not found in Network-Matrix Control with CODE = \
7\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer code, ipnt, ientry;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_10, 0 };


/*     + + + PURPOSE + + + */
/*     Find location of CODE = 7 with the given reservoir node and */
/*     return the inflow node and the address of the reservoir storage */
/*     table. */
/* SOURCE ntwmxstr.for:1770 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1772 */
/*<       integeradrs,inode,stdout,mlemc,rnode >*/
/* SOURCE ntwmxstr.for:1773 */
/*<       integeremc(mlemc) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     RNODE  - reservoir node */
/*     MLEMC  - maximum length of EMC(*) */
/*     INODE  - inflow node for the level-pool reservoir */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:1783 */
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
/* INCLUDE ntwmxstr.for:1784 */
/* *********************************************************************** */
/*     COMMON BLOCK FOR PROFILE MATRIX SOLUTION. */
/* SOURCE matcom.cmn:4 */
/*<        >*/
/* SOURCE matcom.cmn:8 */
/*<       common/matcom2/pdavec2,rhs2 >*/
/* SOURCE matcom.cmn:10 */
/*<       integermatblk,numeq,nentry >*/
/* SOURCE matcom.cmn:12 */
/*<        >*/
/* SOURCE matcom.cmn:16 */
/*<       realpdavec(mlpda),rhs(mrmat),hi_iq_ns_fac(mrmat) >*/
/*     Add second set to help in diagnostics-at least as a trial. */
/* SOURCE matcom.cmn:19 */
/*<       realpdavec2(mlpda),rhs2(mrmat) >*/
/* *********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:1787 */
/*<       integercode,ientry,ipnt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:1790 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:1793 */
/*<       externalgetusn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:1796 */
/*<    10  >*/
/* *********************************************************************** */
/*     START SEARCH */
/* SOURCE ntwmxstr.for:1800 */
/*<       ientry=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L10: */
    ientry = 0;
/* SOURCE ntwmxstr.for:1802 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:1803 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE ntwmxstr.for:1804 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE ntwmxstr.for:1805 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE ntwmxstr.for:1806 */
/*<       if(code.eq.7)then >*/
    if (code == 7) {
/*         CODE = 7.  Check reservoir node. */
/* SOURCE ntwmxstr.for:1808 */
/*<       if(rnode.eq.emc(ipnt+1))then >*/
	if (*rnode == emc[ipnt + 1]) {
/*           Found match for reservoir node.  Get the inflow node. */
/* SOURCE ntwmxstr.for:1810 */
/*<       inode=emc(ipnt+5) >*/
	    *inode = emc[ipnt + 5];
/*           Get the address of the storage table. */
/* SOURCE ntwmxstr.for:1812 */
/*<       adrs=emc(ipnt+2) >*/
	    *adrs = emc[ipnt + 2];
/* SOURCE ntwmxstr.for:1813 */
/*<       return >*/
	    return 0;
/* SOURCE ntwmxstr.for:1814 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:1815 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1817 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE ntwmxstr.for:1819 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:1820 */
/*<       else >*/
    } else {
/*         End of Network-Matrix Control data. */
/* SOURCE ntwmxstr.for:1822 */
/*<       write(stdout,10)getusn(rnode),getusn(inode) >*/
	feq_gen_io_d__85.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__85);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, rnode);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	getusn_(feq_gen_ch_d_4, (ftnlen)5, inode);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	e_wsfe();
/* SOURCE ntwmxstr.for:1823 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1824 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:1825 */
/*<       end >*/
    return 0;
} /* fnd7_ */




/* SOURCE ntwmxstr.for:1829 */
/*<       subroutinefndany(jpt,node,ljoin,lemc,emc,join,node2,anyr) >*/
/* Subroutine */ int fndany_(integer *jpt, integer *node, integer *ljoin, 
	integer *lemc, integer *feq_storage_emc, integer *feq_storage_join, integer *node2, integer *
	anyr)
{
    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, len, rpt, code, nd2adr, minnd2, emcadr, nodadr, minadr, minlen,
	     nodgrp;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    integer nxtadr;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer minrpt;
    extern integer isnumr_(integer *, integer *, integer *, integer *, 
	    integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__88 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find any relationship excluding code 4 and code 8--code 8 should */
/*     should not appear and code 4 should only appear with its head */
/*     node only at the node. */
/* SOURCE ntwmxstr.for:1839 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:1841 */
/*<       integeranyr,jpt,lemc,ljoin,node,node2 >*/
/* SOURCE ntwmxstr.for:1842 */
/*<       integeremc(lemc),join(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JPT    - pointer for the junction descriptions */
/*     NODE   - node number */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     JOIN   - vector for storing the junction descriptions */
/*     NODE2  - second node in relationship if any exists */
/*     ANYR   - address of relationship found in EMC(*) */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:1855 */
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
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ntwmxstr.for:1858 */
/*<       integerbig >*/
/* SOURCE ntwmxstr.for:1859 */
/*<       parameter(big=9999999) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:1862 */
/*<        >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:1866 */
/*<       integerexnodn,isnumr >*/
/* SOURCE ntwmxstr.for:1867 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:1870 */
/*<       externalexnodn,getusn,isnumr >*/
/* *********************************************************************** */
/*     GET THE NUMBER OF NODES. */
/* SOURCE ntwmxstr.for:1873 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    n = join[*jpt];

/*     FIND THE NODE IN THE LIST */
/* SOURCE ntwmxstr.for:1877 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:1878 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:1879 */
/*<        >*/
	feq_gen_io_d__88.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__88);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX NODE="), (ftnlen)15);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT IN NODE LIST"), (ftnlen)17);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN FNDANY"), (ftnlen)10);
	e_wsle();
/* SOURCE ntwmxstr.for:1881 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1882 */
/*<       endif >*/
    }
/*     GET THE POINTER TO THE FIRST RELATIONSHIP POINTER RECORD */
/* SOURCE ntwmxstr.for:1885 */
/*<       nxtadr=join(nodadr+2*n) >*/
    nxtadr = join[nodadr + (n << 1)];
/*     SCAN THE AVAILABLE AND CODE VALID RELATIONSHIPS FOR THIS */
/*     NODE. */
/*     There are three groups of available relationships for a node */
/*     all classified on the basis of NODE2.  Note that all of the */
/*     relationships permitted here have a positive value of NODE2. */
/*     The groups are defined as follows: */
/*            NODE2 is terminated. */
/*            NODE2 is initiated. */
/*            NODE2 is uninitiated. */
/*     The first priority relationship would be any in the first group. */
/*     Since the second node is terminated any relationship will be ok. */
/*     The next priority is the second group so that we keep the profile */
/*     of the matrix smaller.  However, this group must be used with */
/*     care because we must make sure that  NODE2 will have a relationship */
/*     available when its path is terminated.  The last group is last */
/*     in priority but any node can be taken.  If there is more than one */
/*     we will pick the NODE2 with the shortest path length. */
/*     Optimization may be added to the first two groups as we */
/*     gain experience with the new method. */
/* SOURCE ntwmxstr.for:1914 */
/*<       minlen=big >*/
    minlen = 9999999;
/* SOURCE ntwmxstr.for:1915 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:1916 */
/*<       if(nxtadr.gt.0)then >*/
    if (nxtadr > 0) {
/*         GET THE POINTER TO THE POINTER TO THE RELATIONSHIP IN EMC */
/* SOURCE ntwmxstr.for:1918 */
/*<       rpt=join(nxtadr+1) >*/
	rpt = join[nxtadr + 1];
/*         GET THE SECOND NODE */
/* SOURCE ntwmxstr.for:1920 */
/*<       node2=join(nxtadr+2) >*/
	*node2 = join[nxtadr + 2];
/*         GET THE EMC POINTER */
/* SOURCE ntwmxstr.for:1922 */
/*<       emcadr=join(rpt) >*/
	emcadr = join[rpt];
/* SOURCE ntwmxstr.for:1923 */
/*<       if(emcadr.gt.0)then >*/
	if (emcadr > 0) {
/*           RELATIONSHIP IS AVAILABLE-CHECK CODE */
/* SOURCE ntwmxstr.for:1925 */
/*<       code=emc(emcadr) >*/
	    code = emc[emcadr];
/* SOURCE ntwmxstr.for:1926 */
/*<       if(code.eq.8)then >*/
	    if (code == 8) {
/* SOURCE ntwmxstr.for:1927 */
/*<       write(std6,*)' *BUG:XXX* CODE 8 FOUND IN FNDANY. JPT=',jpt >*/
		feq_gen_io_d__94.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsle(&feq_gen_io_d__94);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* CODE 8 FOUND IN FNDANY. JPT=")
			, (ftnlen)39);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer))
			;
		e_wsle();
/* SOURCE ntwmxstr.for:1929 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1930 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:1932 */
/*<       if(code.ne.4.and.code.ne.5.and.code.ne.14)then >*/
	    if (code != 4 && code != 5 && code != 14) {
/*             We have an available relationship at NODE. NODE2, RPT, */
/*             and EMCADR are all defined.  Now check for the various */
/*             groups. */
/* SOURCE ntwmxstr.for:1937 */
/*<       nd2adr=exnodn(node2,jpt,ljoin,join) >*/
		nd2adr = exnodn_(node2, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:1938 */
/*<       if(nd2adr.le.0)then >*/
		if (nd2adr <= 0) {
/* SOURCE ntwmxstr.for:1939 */
/*<        >*/
		    feq_gen_io_d__96.ciunit = feq_gen_stdun_com_d_1.std6;
		    s_wsle(&feq_gen_io_d__96);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* NODE2="), (ftnlen)17);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, node2);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT IN"), (ftnlen)7);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODE LIST. JPT="), (ftnlen)16);
		    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(
			    integer));
		    e_wsle();
/* SOURCE ntwmxstr.for:1941 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:1942 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:1944 */
/*<       nodgrp=join(nd2adr+n) >*/
		nodgrp = join[nd2adr + n];
/* SOURCE ntwmxstr.for:1945 */
/*<       if(nodgrp.eq.2)then >*/
		if (nodgrp == 2) {
/*               NODE2 in the relationship is a terminated node. */
/*               Use the relationship.  We take the first one */
/*               we find now but might add optimization later. */
/* SOURCE ntwmxstr.for:1949 */
/*<       anyr=emcadr >*/
		    *anyr = emcadr;
/*               Mark the relationship as used. */
/* SOURCE ntwmxstr.for:1951 */
/*<       join(rpt)=-emcadr >*/
		    join[rpt] = -emcadr;
/* SOURCE ntwmxstr.for:1952 */
/*<       return >*/
		    return 0;
/* SOURCE ntwmxstr.for:1953 */
/*<       elseif(nodgrp.eq.1)then >*/
		} else if (nodgrp == 1) {
/*               NODE2 in the relationship is initiated. */
/*               Since it is initiated it will be seeking a terminating */
/*               relationship.  The sum of flows relationship is */
/*               of high priority for initiating the beginning */
/*               of a path.  Therefore do not depend on it being */
/*               available for terminating a path. */
/*               Must leave at least one relationship at NODE2 */
/*               so that it can be terminated. */
/* SOURCE ntwmxstr.for:1963 */
/*<       if(isnumr(node2,jpt,ljoin,join,lemc,emc).ge.2)then >*/
		    if (isnumr_(node2, jpt, ljoin, &join[1], lemc, &emc[1]) >=
			     2) {
/*                 There are two or more relationships at NODE2. */
/*                 Therefore we can use the one we have and still */
/*                 leave one for terminating the initiated path. */
/* SOURCE ntwmxstr.for:1968 */
/*<       anyr=emcadr >*/
			*anyr = emcadr;
/*                 Mark the relationship as used */
/* SOURCE ntwmxstr.for:1970 */
/*<       join(rpt)=-emcadr >*/
			join[rpt] = -emcadr;
/* SOURCE ntwmxstr.for:1971 */
/*<       return >*/
			return 0;
/* SOURCE ntwmxstr.for:1972 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:1973 */
/*<       else >*/
		} else {
/*               NODE2 not initiated.  Find minimum length. */
/* SOURCE ntwmxstr.for:1976 */
/*<       len=join(nd2adr+3*n) >*/
		    len = join[nd2adr + n * 3];
/* SOURCE ntwmxstr.for:1977 */
/*<       if(len.lt.minlen)then >*/
		    if (len < minlen) {
/* SOURCE ntwmxstr.for:1978 */
/*<       minlen=len >*/
			minlen = len;
/* SOURCE ntwmxstr.for:1979 */
/*<       minadr=emcadr >*/
			minadr = emcadr;
/* SOURCE ntwmxstr.for:1980 */
/*<       minrpt=rpt >*/
			minrpt = rpt;
/* SOURCE ntwmxstr.for:1981 */
/*<       minnd2=node2 >*/
			minnd2 = *node2;
/* SOURCE ntwmxstr.for:1982 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:1984 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:1985 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:1986 */
/*<       endif >*/
	}
/*         GET THE ADDRESS OF THE NEXT RELATIONSHIP POINTER RECORD */
/* SOURCE ntwmxstr.for:1990 */
/*<       nxtadr=join(nxtadr) >*/
	nxtadr = join[nxtadr];
/* SOURCE ntwmxstr.for:1991 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:1992 */
/*<       endif >*/
    }
/*     IF A RELATIONSHIP WITH AN UNINITIATED NODE2 WAS FOUND */
/*     WE FALL TO HERE. */
/* SOURCE ntwmxstr.for:1997 */
/*<       if(minlen.ne.big)then >*/
    if (minlen != 9999999) {
/* SOURCE ntwmxstr.for:1998 */
/*<       anyr=minadr >*/
	*anyr = minadr;
/* SOURCE ntwmxstr.for:1999 */
/*<       node2=minnd2 >*/
	*node2 = minnd2;
/*       Mark the relationship as used. */
/* SOURCE ntwmxstr.for:2001 */
/*<       join(minrpt)=-minadr >*/
	join[minrpt] = -minadr;
/* SOURCE ntwmxstr.for:2002 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2003 */
/*<       anyr=0 >*/
	*anyr = 0;
/* SOURCE ntwmxstr.for:2004 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2007 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:2008 */
/*<       end >*/
} /* fndany_ */




/* SOURCE ntwmxstr.for:2012 */
/*<       subroutinefndinn(enf,enoden,usenin,eflag,inenus,eidinn) >*/
/* Subroutine */ int fndinn_(char *enf, integer *enoden, integer *feq_storage_usenin, 
	integer *eflag, char *feq_storage_inenus, integer *eidinn, ftnlen enf_len, ftnlen 
	inenus_len)
{
    /* Initialized data */

    static integer style = -1;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:207* Exterior node number=\002,i5\
,\002 out of range.\002)";
    static char fmt_51[] = "(/,\002 *ERR:211* Number=\002,i5,\002 out of ran\
ge for\002,\002 exterior node. Prefix=\002,a2)";
    static char fmt_52[] = "(/,\002 *ERR:208* Prefix=\002,a2,\002 is inval\
id.\002)";
    static char fmt_54[] = "(/,\002 *ERR:212* Branch number=\002,i5,\002 doe\
s not exist. \002,\002Prefix=\002,a2,\002 for the node id.\002)";
    static char fmt_56[] = "(/,\002 *ERR:213* Node=\002,a5,\002 makes node c\
ount > max value\002,\002 of:\002,i5)";
    static char fmt_58[] = "(/,\002 *ERR:90* Mixed input style. Node#=\002,i\
5)";
    static char fmt_60[] = "(/,\002 *ERR:104* Mixed input style. Node id=\
\002,1x,a5)";

    /* System generated locals */
    char feq_gen_ch_d_1[5];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer ii, num;
    char chr5[5];
    extern /* Character */ VOID makenn_(char *, ftnlen, char *, integer *, 
	    ftnlen);
    extern /* Subroutine */ int cnvenf_(char *, char *, integer *, ftnlen, 
	    ftnlen);
    char prefix[1];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__106 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     Find an internal node number for an exterior node id.  The node */
/*     may never have been seen or it may have been seen already. */
/* SOURCE ntwmxstr.for:2022 */
/*<       implicitnone >*/
/* INCLUDE ntwmxstr.for:2023 */
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
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2025 */
/*<       integereflag,eidinn,enoden >*/
/* SOURCE ntwmxstr.for:2026 */
/*<       integerusenin(-9999:19998) >*/
/* SOURCE ntwmxstr.for:2027 */
/*<       characterenf*5,inenus(mnex)*5 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ENF    - exterior node field */
/*     ENODEN - internal exterior-node number */
/*     USENIN - conversion from user exterior node number to internal */
/*               exterior node number */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     INENUS - conversion from internal exterior node number to user */
/*              exterior node designation */
/*     EIDINN - internal node number for an exterior node id */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2040 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE ntwmxstr.for:2043 */
/*<       integerstyle >*/
/* SOURCE ntwmxstr.for:2044 */
/*<       savestyle >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:2047 */
/*<       integerii,num >*/
/* SOURCE ntwmxstr.for:2048 */
/*<       characterchr5*5,prefix*1 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:2051 */
/*<       charactermakenn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:2054 */
/*<       externalcnvenf,makenn >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:2057 */
/*<       datastyle/-1/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> inenus(feq_storage_inenus, 5);

    feq::IndexedPointer<integer> usenin(feq_storage_usenin, -9999);

    /* Function Body */
/* SOURCE ntwmxstr.for:2060 */
/*<    50 format(/,' *ERR:207* Exterior node number=',i5,' out of range.') >*/
/* L50: */
/* SOURCE ntwmxstr.for:2061 */
/*<    51  >*/
/* L51: */
/* SOURCE ntwmxstr.for:2063 */
/*<    52 format(/,' *ERR:208* Prefix=',a2,' is invalid.') >*/
/* L52: */
/* SOURCE ntwmxstr.for:2064 */
/*<    54  >*/
/* L54: */
/* SOURCE ntwmxstr.for:2066 */
/*<    56  >*/
/* L56: */
/* SOURCE ntwmxstr.for:2068 */
/*<    58 format(/,' *ERR:90* Mixed input style. Node#=',i5) >*/
/* L58: */
/* SOURCE ntwmxstr.for:2069 */
/*<    60 format(/,' *ERR:104* Mixed input style. Node id=',1x,a5) >*/
/* L60: */
/* *********************************************************************** */
/*     GET THE PREFIX AND THE BRANCH NUMBER */
/* SOURCE ntwmxstr.for:2072 */
/*<       callcnvenf(enf,prefix,num) >*/
    cnvenf_(enf, prefix, &num, (ftnlen)5, (ftnlen)1);
/* SOURCE ntwmxstr.for:2076 */
/*<       if(prefix.eq.' ')then >*/
    if (*(unsigned char *)prefix == ' ') {
/*       OLD STYLE */
/* SOURCE ntwmxstr.for:2078 */
/*<       if(num.lt.1.or.num.gt.19998)then >*/
	if (num < 1 || num > 19998) {
/* SOURCE ntwmxstr.for:2079 */
/*<       write(std6,50)num >*/
	    feq_gen_io_d__105.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__105);
	    do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:2080 */
/*<       num=19998 >*/
	    num = 19998;
/* SOURCE ntwmxstr.for:2081 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:2082 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2083 */
/*<       if(style.eq.-1)then >*/
	if (style == -1) {
/* SOURCE ntwmxstr.for:2084 */
/*<       style=0 >*/
	    style = 0;
/* SOURCE ntwmxstr.for:2085 */
/*<       elseif(style.eq.1)then >*/
	} else if (style == 1) {
/* SOURCE ntwmxstr.for:2086 */
/*<       write(std6,58)num >*/
	    feq_gen_io_d__106.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__106);
	    do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:2087 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:2088 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2089 */
/*<       else >*/
    } else {
/*       NEW STYLE */
/* SOURCE ntwmxstr.for:2091 */
/*<       if(num.lt.1.or.num.gt.9999)then >*/
	if (num < 1 || num > 9999) {
/* SOURCE ntwmxstr.for:2092 */
/*<       write(std6,51)num,prefix >*/
	    feq_gen_io_d__107.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__107);
	    do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, prefix, (ftnlen)1);
	    e_wsfe();
/* SOURCE ntwmxstr.for:2093 */
/*<       num=9999 >*/
	    num = 9999;
/* SOURCE ntwmxstr.for:2094 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:2095 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2096 */
/*<       if(style.eq.-1)then >*/
	if (style == -1) {
/* SOURCE ntwmxstr.for:2097 */
/*<       style=1 >*/
	    style = 1;
/* SOURCE ntwmxstr.for:2098 */
/*<       elseif(style.eq.0)then >*/
	} else if (style == 0) {
/* SOURCE ntwmxstr.for:2099 */
/*<       write(std6,60)enf >*/
	    feq_gen_io_d__108.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__108);
	    do_fio(&feq_gen_c_d_1, enf, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:2100 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:2101 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2103 */
/*<       endif >*/
    }
/*     COMPUTE INDEX INTO USENIN() TO FIND THE INTERNAL NUMBER */
/* SOURCE ntwmxstr.for:2106 */
/*<       if(prefix.eq.' ')then >*/
    if (*(unsigned char *)prefix == ' ') {
/* SOURCE ntwmxstr.for:2107 */
/*<       ii=num >*/
	ii = num;
/* SOURCE ntwmxstr.for:2108 */
/*<       elseif(prefix.eq.'F')then >*/
    } else if (*(unsigned char *)prefix == 'F') {
/* SOURCE ntwmxstr.for:2109 */
/*<       ii=-num >*/
	ii = -num;
/* SOURCE ntwmxstr.for:2110 */
/*<       elseif(prefix.eq.'U')then >*/
    } else if (*(unsigned char *)prefix == 'U') {
/* SOURCE ntwmxstr.for:2111 */
/*<       ii=num >*/
	ii = num;
/* SOURCE ntwmxstr.for:2112 */
/*<       elseif(prefix.eq.'D')then >*/
    } else if (*(unsigned char *)prefix == 'D') {
/* SOURCE ntwmxstr.for:2113 */
/*<       ii=9999+num >*/
	ii = num + 9999;
/* SOURCE ntwmxstr.for:2114 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2115 */
/*<       write(std6,52)prefix >*/
	feq_gen_io_d__110.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__110);
	do_fio(&feq_gen_c_d_1, prefix, (ftnlen)1);
	e_wsfe();
/* SOURCE ntwmxstr.for:2116 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2117 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2119 */
/*<       if(usenin(ii).eq.0)then >*/
    if (usenin[ii] == 0) {
/*       NODE HAS NOT BEEN SEEN BEFORE.  MUST NOT BE ON A BRANCH. */
/* SOURCE ntwmxstr.for:2122 */
/*<       if(prefix.eq.'U'.or.prefix.eq.'D')then >*/
	if (*(unsigned char *)prefix == 'U' || *(unsigned char *)prefix == 
		'D') {
/* SOURCE ntwmxstr.for:2123 */
/*<       write(std6,54)num,prefix >*/
	    feq_gen_io_d__111.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__111);
	    do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, prefix, (ftnlen)1);
	    e_wsfe();
/* SOURCE ntwmxstr.for:2124 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2125 */
/*<       endif >*/
	}
/*       ASSIGN THE NEXT INTERNAL NUMBER TO THE NODE */
/* SOURCE ntwmxstr.for:2129 */
/*<       enoden=enoden+1 >*/
	++(*enoden);
/* SOURCE ntwmxstr.for:2130 */
/*<       if(enoden.gt.mnex)then >*/
	if (*enoden > 8400) {
/*         PROBLEM */
/* SOURCE ntwmxstr.for:2132 */
/*<       chr5=makenn(prefix,num) >*/
	    makenn_(feq_gen_ch_d_1, (ftnlen)5, prefix, &num, (ftnlen)1);
	    s_copy(chr5, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:2133 */
/*<       write(std6,56)chr5,mnex >*/
	    feq_gen_io_d__113.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__113);
	    do_fio(&feq_gen_c_d_1, chr5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_8400, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:2134 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2135 */
/*<       endif >*/
	}
/*       ADD IT TO THE TRANSLATION VECTORS */
/* SOURCE ntwmxstr.for:2137 */
/*<       usenin(ii)=enoden >*/
	usenin[ii] = *enoden;
/* SOURCE ntwmxstr.for:2138 */
/*<       inenus(enoden)=makenn(prefix,num) >*/
	makenn_(feq_gen_ch_d_1, (ftnlen)5, prefix, &num, (ftnlen)1);
	s_copy(inenus + *enoden * 5, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:2139 */
/*<       eidinn=enoden >*/
	*eidinn = *enoden;
/* SOURCE ntwmxstr.for:2140 */
/*<       else >*/
    } else {
/*       NODE HAS BEEN SEEN BEFORE */
/* SOURCE ntwmxstr.for:2143 */
/*<       eidinn=usenin(ii) >*/
	*eidinn = usenin[ii];
/* SOURCE ntwmxstr.for:2144 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2145 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:2146 */
/*<       end >*/
} /* fndinn_ */




/* SOURCE ntwmxstr.for:2150 */
/*<       integerfunctionfndnod(fnode,mnbn,lnode,stat,stlist) >*/
integer fndnod_(integer *fnode, integer *mnbn, integer *lnode, real *stat, 
	real *feq_storage_stlist)
{
    /* System generated locals */
    integer ret_val, feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Local variables */
    integer node;

/*     + + + PURPOSE + + + */
/*     Return the node number if a match for STAT is found */
/*     in STLIST and -1 otherwise. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2158 */
/*<       integerfnode,lnode,mnbn >*/
/* SOURCE ntwmxstr.for:2159 */
/*<       realstat,stlist(mnbn) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     FNODE  - location of the first node in the search */
/*     MNBN   - maximum number of branch nodes */
/*     LNODE  - location of last node in the search */
/*     STAT   - station value */
/*     STLIST - list of stations to search */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:2169 */
/*<       integernode >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntwmxstr.for:2172 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:2174 */
/*<       do100node=fnode,lnode >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> stlist(feq_storage_stlist, 1);

    /* Function Body */
    feq_gen_i_d_1 = *lnode;
    for (node = *fnode; node <= feq_gen_i_d_1; ++node) {
/* SOURCE ntwmxstr.for:2175 */
/*<       if(abs(stat-stlist(node)).lt.1.e-4)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*stat) - stlist[node], dabs(feq_gen_r_d_1)) < (float)1e-4) {
/* SOURCE ntwmxstr.for:2176 */
/*<       fndnod=node >*/
	    ret_val = node;
/* SOURCE ntwmxstr.for:2177 */
/*<       return >*/
	    return ret_val;
/* SOURCE ntwmxstr.for:2178 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2179 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE ntwmxstr.for:2180 */
/*<       fndnod=-1 >*/
    ret_val = -1;
/* SOURCE ntwmxstr.for:2181 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:2182 */
/*<       end >*/
} /* fndnod_ */




/* SOURCE ntwmxstr.for:2186 */
/*<       integerfunctionfndnum(chr5) >*/
integer fndnum_(char *chr5, ftnlen chr5_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:214* Conversion error in: \002,a5)";

    /* System generated locals */
    integer ret_val, feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer num;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the number for a non-exterior node integer field in the */
/*     matrix control input. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2194 */
/*<       characterchr5*5 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     CHR5   - 5 character non-exterior node field value */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2200 */
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
/* SOURCE ntwmxstr.for:2203 */
/*<       integernum >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:2206 */
/*<    50 format(/,' *ERR:214* Conversion error in: ',a5) >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:2208 */
/*<       read(chr5,'(I5)',err=991)num >*/
/* L50: */
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = chr5;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ntwmxstr.for:2209 */
/*<       fndnum=num >*/
    ret_val = num;
/* SOURCE ntwmxstr.for:2210 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:2212 */
/*<   991 continue >*/
L991:
/* SOURCE ntwmxstr.for:2213 */
/*<       write(std6,50)chr5 >*/
    feq_gen_io_d__116.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__116);
    do_fio(&feq_gen_c_d_1, chr5, (ftnlen)5);
    e_wsfe();
/* SOURCE ntwmxstr.for:2214 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2215 */
/*<       end >*/
    return ret_val;
} /* fndnum_ */




/* SOURCE ntwmxstr.for:2219 */
/*<       integerfunctionfndnxt(jpt,ljoin,join,lemc,emc) >*/
integer fndnxt_(integer *jpt, integer *ljoin, integer *feq_storage_join, integer *lemc, 
	integer *feq_storage_emc)
{
    /* System generated locals */
    integer ret_val, feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, n, ie, is, len, num, node, node0, minlen, minnod;
    extern integer isndav_(integer *, integer *, integer *, integer *, 
	    integer *, integer *);
    integer numflg;
    extern integer isnumr_(integer *, integer *, integer *, integer *, 
	    integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__125 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find the next path to initiate at the junction since the */
/*     previous path did not force a next path.  If an uninitiated */
/*     path has no relationships available at its initiating node */
/*     then that path must be taken next. Otherwise, take the */
/*     uninitated path with the shortest attached length */
/*     that has an available node. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2231 */
/*<       integerjpt,lemc,ljoin >*/
/* SOURCE ntwmxstr.for:2232 */
/*<       integeremc(lemc),join(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JPT    - pointer for the junction descriptions */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2242 */
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
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ntwmxstr.for:2245 */
/*<       integerbig >*/
/* SOURCE ntwmxstr.for:2246 */
/*<       parameter(big=9999999) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:2249 */
/*<       integeri,ie,is,len,minlen,minnod,n,node,node0,num,numflg >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:2253 */
/*<       integerisndav,isnumr >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:2256 */
/*<       externalisndav,isnumr >*/
/* *********************************************************************** */
/*     GET THE NUMBER OF NODES */
/* SOURCE ntwmxstr.for:2259 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    n = join[*jpt];
/*     CHECK FOR UNINITATED NODE THAT HAS NO RELATIONSHIP AVAILABLE. */
/* SOURCE ntwmxstr.for:2262 */
/*<       is=jpt+4 >*/
    is = *jpt + 4;
/* SOURCE ntwmxstr.for:2263 */
/*<       ie=is+n-1 >*/
    ie = is + n - 1;
/* SOURCE ntwmxstr.for:2264 */
/*<       numflg=0 >*/
    numflg = 0;
/* SOURCE ntwmxstr.for:2265 */
/*<       do100i=is,ie >*/
    feq_gen_i_d_1 = ie;
    for (feq_gen_i_d_ = is; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:2266 */
/*<       if(join(i+n).eq.0)then >*/
	if (join[feq_gen_i_d_ + n] == 0) {
/*         NODE IS UNINITIATED. */
/* SOURCE ntwmxstr.for:2268 */
/*<       node=join(i) >*/
	    node = join[feq_gen_i_d_];
/* SOURCE ntwmxstr.for:2269 */
/*<       num=isnumr(node,jpt,ljoin,join,lemc,emc) >*/
	    num = isnumr_(&node, jpt, ljoin, &join[1], lemc, &emc[1]);
/* SOURCE ntwmxstr.for:2270 */
/*<       if(num.eq.0)then >*/
	    if (num == 0) {
/* SOURCE ntwmxstr.for:2271 */
/*<       numflg=numflg+1 >*/
		++numflg;
/* SOURCE ntwmxstr.for:2272 */
/*<       node0=node >*/
		node0 = node;
/* SOURCE ntwmxstr.for:2273 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:2274 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2275 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE ntwmxstr.for:2276 */
/*<       if(numflg.gt.0)then >*/
    if (numflg > 0) {
/*       FOUND A NODE WITH ZERO RELATIONSHIPS */
/* SOURCE ntwmxstr.for:2278 */
/*<       if(numflg.gt.1)then >*/
	if (numflg > 1) {
/* SOURCE ntwmxstr.for:2279 */
/*<        >*/
	    feq_gen_io_d__125.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__125);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PROBLEM IN FNDNXT. JPT="), (ftnlen)24);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NUMFLG="), (ftnlen)8);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&numflg, (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODE0="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&node0, (ftnlen)sizeof(integer));
	    e_wsle();
/* SOURCE ntwmxstr.for:2281 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2282 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2283 */
/*<       fndnxt=node0 >*/
	ret_val = node0;
/* SOURCE ntwmxstr.for:2284 */
/*<       return >*/
	return ret_val;
/* SOURCE ntwmxstr.for:2285 */
/*<       endif >*/
    }
/*     CHECK EACH NODE AND TAKE THE AVAILABLE NODE WITH THE */
/*     MINIMUM LENGTH */
/* SOURCE ntwmxstr.for:2289 */
/*<       minlen=big >*/
    minlen = 9999999;
/* SOURCE ntwmxstr.for:2290 */
/*<       is=jpt+4 >*/
    is = *jpt + 4;
/* SOURCE ntwmxstr.for:2291 */
/*<       ie=is+n-1 >*/
    ie = is + n - 1;
/* SOURCE ntwmxstr.for:2292 */
/*<       do200i=is,ie >*/
    feq_gen_i_d_1 = ie;
    for (feq_gen_i_d_ = is; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:2293 */
/*<       if(join(i+n).eq.0)then >*/
	if (join[feq_gen_i_d_ + n] == 0) {
/*         PATH IS AVAILABLE. IS THE NODE AVAILABLE. */
/* SOURCE ntwmxstr.for:2295 */
/*<       node=join(i) >*/
	    node = join[feq_gen_i_d_];
/* SOURCE ntwmxstr.for:2296 */
/*<       if(isndav(jpt,node,ljoin,join,lemc,emc).eq.1)then >*/
	    if (isndav_(jpt, &node, ljoin, &join[1], lemc, &emc[1]) == 1) {
/* SOURCE ntwmxstr.for:2297 */
/*<       len=join(i+3*n) >*/
		len = join[feq_gen_i_d_ + n * 3];
/* SOURCE ntwmxstr.for:2298 */
/*<       if(len.lt.minlen)then >*/
		if (len < minlen) {
/* SOURCE ntwmxstr.for:2299 */
/*<       minlen=len >*/
		    minlen = len;
/* SOURCE ntwmxstr.for:2300 */
/*<       minnod=node >*/
		    minnod = node;
/* SOURCE ntwmxstr.for:2301 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:2302 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:2303 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2304 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE ntwmxstr.for:2306 */
/*<       if(minlen.eq.big)then >*/
    if (minlen == 9999999) {
/* SOURCE ntwmxstr.for:2307 */
/*<       fndnxt=0 >*/
	ret_val = 0;
/* SOURCE ntwmxstr.for:2308 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2309 */
/*<       fndnxt=minnod >*/
	ret_val = minnod;
/* SOURCE ntwmxstr.for:2310 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2312 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:2313 */
/*<       end >*/
} /* fndnxt_ */




/* SOURCE ntwmxstr.for:2317 */
/*<       subroutinefnvarn(node,exnodt,ivar,exnvar,varid) >*/
/* Subroutine */ int fnvarn_(integer *node, integer *feq_storage_exnodt, integer *ivar, 
	integer *feq_storage_exnvar, integer *feq_storage_varid)
{
    integer nd;

/*     + + + PURPOSE + + + */
/*     Assign variable numbers to a free node. */
/* SOURCE ntwmxstr.for:2324 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2326 */
/*<       integerivar,node >*/
/* SOURCE ntwmxstr.for:2327 */
/*<       integerexnodt(9,*),exnvar(*),varid(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NODE   - node number */
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
/*     IVAR   - variable number */
/*     EXNVAR - variable number for the first variable(Q) at an exterior */
/*               node */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:2350 */
/*<       integernd >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntwmxstr.for:2353 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:2355 */
/*<       nd=abs(node) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> varid(feq_storage_varid, 1);

    feq::IndexedPointer<integer> exnvar(feq_storage_exnvar, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    nd = abs(*node);
/* SOURCE ntwmxstr.for:2356 */
/*<       if(exnodt(3,nd).le.0)then >*/
    if (exnodt[nd * 9 + 3] <= 0) {
/*       ASSIGN VARIABLE NUMBER AND INCREMENT THE NUMBER */
/* SOURCE ntwmxstr.for:2358 */
/*<       if(exnvar(nd).eq.0)then >*/
	if (exnvar[nd] == 0) {
/* SOURCE ntwmxstr.for:2359 */
/*<       exnvar(nd)=ivar >*/
	    exnvar[nd] = *ivar;
/*         Identify the variable with the exterior node number */
/* SOURCE ntwmxstr.for:2361 */
/*<       varid(ivar)=nd >*/
	    varid[*ivar] = nd;
/* SOURCE ntwmxstr.for:2362 */
/*<       varid(ivar+1)=nd >*/
	    varid[*ivar + 1] = nd;
/* SOURCE ntwmxstr.for:2363 */
/*<       ivar=ivar+2 >*/
	    *ivar += 2;
/* SOURCE ntwmxstr.for:2364 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2365 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2366 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:2367 */
/*<       end >*/
} /* fnvarn_ */




/* SOURCE ntwmxstr.for:2371 */
/*<       subroutinegetinb(ebn,eflag,inb) >*/
/* Subroutine */ int getinb_(integer *ebn, integer *eflag, integer *inb)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:205* Branch=\002,i5,\002 out of ran\
ge.\002)";
    static char fmt_52[] = "(/,\002 *ERR:206* Branch=\002,i5,\002 has undefi\
ned internal value.\002,\002  Branch id is invalid.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Get an internal branch number.  If none exists write an error. */
/* SOURCE ntwmxstr.for:2378 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2380 */
/*<       integerebn,eflag,inb >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     EBN    - external(user) branch number */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     INB    - internal branch number */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2388 */
/*     COMMON FOR TRANSLATION OF USER NODES AND BRANCHS TO THE INTERNAL */
/*     VALUES FOR THESE BRANCHES.  ONLY USED DURING PROCESSING OF */
/*     INPUT.  THUS DO NOT PUT COMMON BLOCK IN SAVE.  IT SHOULD BE */
/*     RELEASED FROM STORAGE WHEN SUBROUTINE INFO IS LEFT. */
/* SOURCE usintp.cmn:6 */
/*<       common/usintp/usbrin,usenin >*/
/* SOURCE usintp.cmn:8 */
/*<       integerusbrin(9999),usenin(-9999:19998) >*/

/* INCLUDE ntwmxstr.for:2389 */
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
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:2392 */
/*<    50 format(/,' *ERR:205* Branch=',i5,' out of range.') >*/
/* SOURCE ntwmxstr.for:2393 */
/*<    52  >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:2396 */
/*<       if(ebn.lt.0)then >*/
/* L50: */
/* L52: */
    if (*ebn < 0) {
/* SOURCE ntwmxstr.for:2397 */
/*<       inb=-1 >*/
	*inb = -1;
/* SOURCE ntwmxstr.for:2398 */
/*<       return >*/
	return 0;
/* SOURCE ntwmxstr.for:2399 */
/*<       elseif(ebn.eq.0)then >*/
    } else if (*ebn == 0) {
/* SOURCE ntwmxstr.for:2400 */
/*<       inb=0 >*/
	*inb = 0;
/* SOURCE ntwmxstr.for:2401 */
/*<       return >*/
	return 0;
/* SOURCE ntwmxstr.for:2402 */
/*<       elseif(ebn.gt.9999)then >*/
    } else if (*ebn > 9999) {
/* SOURCE ntwmxstr.for:2403 */
/*<       write(std6,50)ebn >*/
	feq_gen_io_d__130.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__130);
	do_fio(&feq_gen_c_d_1, (char *)&(*ebn), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ntwmxstr.for:2404 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ntwmxstr.for:2405 */
/*<       ebn=9999 >*/
	*ebn = 9999;
/* SOURCE ntwmxstr.for:2406 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2407 */
/*<       if(usbrin(ebn).eq.0)then >*/
    if (usintp_1.usbrin[*ebn - 1] == 0) {
/* SOURCE ntwmxstr.for:2408 */
/*<       write(std6,52)ebn >*/
	feq_gen_io_d__131.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__131);
	do_fio(&feq_gen_c_d_1, (char *)&(*ebn), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ntwmxstr.for:2409 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2410 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2411 */
/*<       inb=usbrin(ebn) >*/
	*inb = usintp_1.usbrin[*ebn - 1];
/* SOURCE ntwmxstr.for:2412 */
/*<       return >*/
	return 0;
/* SOURCE ntwmxstr.for:2413 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2414 */
/*<       end >*/
    return 0;
} /* getinb_ */




/* SOURCE ntwmxstr.for:2418 */
/*<       subroutinegetinn(enf,eflag,inn) >*/
/* Subroutine */ int getinn_(char *enf, integer *eflag, integer *inn, ftnlen 
	enf_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:207* Exterior node number=\002,i5\
,\002 out of range.\002)";
    static char fmt_51[] = "(/,\002 *ERR:211* Number=\002,i5,\002 out of ran\
ge for\002,\002 exterior node. Prefix=\002,a2)";
    static char fmt_52[] = "(/,\002 *ERR:208* Prefix=\002,a2,\002 is inval\
id.\002)";
    static char fmt_56[] = "(/,\002 *ERR:209* Node=\002,a5,\002 has an undef\
ined internal \002,\002value.  Node id is invalid.\002)";
    static char fmt_58[] = "(/,\002 *ERR:364* Field for exterior node id:\
\002,a6,\002,\002,\002 does not make sense.  Some input lines may be missing.\
\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, ii, num;
    char chr5[5];
    integer minus;
    char prefix[1];
    extern integer isnumd_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__140 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__141 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__142 = { 0, 0, 0, fmt_58, 0 };


/*     + + + PURPOSE + + + */
/*     Find an internal node number for an exterior node id.  If none */
/*     exists it is an error.  May be a minus sign prefixing the id. */
/* SOURCE ntwmxstr.for:2426 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2428 */
/*<       integereflag,inn >*/
/* SOURCE ntwmxstr.for:2429 */
/*<       characterenf*5 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ENF    - exterior node field */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     INN    - internal exterior node number */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2437 */
/*     COMMON FOR TRANSLATION OF USER NODES AND BRANCHS TO THE INTERNAL */
/*     VALUES FOR THESE BRANCHES.  ONLY USED DURING PROCESSING OF */
/*     INPUT.  THUS DO NOT PUT COMMON BLOCK IN SAVE.  IT SHOULD BE */
/*     RELEASED FROM STORAGE WHEN SUBROUTINE INFO IS LEFT. */
/* SOURCE usintp.cmn:6 */
/*<       common/usintp/usbrin,usenin >*/
/* SOURCE usintp.cmn:8 */
/*<       integerusbrin(9999),usenin(-9999:19998) >*/

/* INCLUDE ntwmxstr.for:2438 */
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
/* SOURCE ntwmxstr.for:2441 */
/*<       integeri,ii,minus,num >*/
/* SOURCE ntwmxstr.for:2442 */
/*<       characterchr5*5,prefix*1 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:2445 */
/*<       integerisnumd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:2448 */
/*<       externalisnumd >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:2451 */
/*<    50 format(/,' *ERR:207* Exterior node number=',i5,' out of range.') >*/
/* SOURCE ntwmxstr.for:2452 */
/*<    51  >*/
/* SOURCE ntwmxstr.for:2454 */
/*<    52 format(/,' *ERR:208* Prefix=',a2,' is invalid.') >*/
/* SOURCE ntwmxstr.for:2455 */
/*<    56  >*/
/* SOURCE ntwmxstr.for:2457 */
/*<    58  >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:2460 */
/*<       chr5=enf >*/
/* L50: */
/* L51: */
/* L52: */
/* L56: */
/* L58: */
    s_copy(chr5, enf, (ftnlen)5, (ftnlen)5);
/* SOURCE ntwmxstr.for:2461 */
/*<       minus=1 >*/
    minus = 1;
/* SOURCE ntwmxstr.for:2462 */
/*<       do100i=1,5 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 5; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:2463 */
/*<       if(chr5(i:i).eq.'-')then >*/
	if (*(unsigned char *)&chr5[feq_gen_i_d_ - 1] == '-') {
/* SOURCE ntwmxstr.for:2464 */
/*<       minus=-1 >*/
	    minus = -1;
/* SOURCE ntwmxstr.for:2465 */
/*<       chr5(i:i)=' ' >*/
	    *(unsigned char *)&chr5[feq_gen_i_d_ - 1] = ' ';
/* SOURCE ntwmxstr.for:2466 */
/*<       enf(i:i)=' ' >*/
	    *(unsigned char *)&enf[feq_gen_i_d_ - 1] = ' ';
/* SOURCE ntwmxstr.for:2467 */
/*<       elseif(chr5(i:i).eq.'+')then >*/
	} else if (*(unsigned char *)&chr5[feq_gen_i_d_ - 1] == '+') {
/* SOURCE ntwmxstr.for:2468 */
/*<       chr5(i:i)=' ' >*/
	    *(unsigned char *)&chr5[feq_gen_i_d_ - 1] = ' ';
/* SOURCE ntwmxstr.for:2469 */
/*<       enf(i:i)=' ' >*/
	    *(unsigned char *)&enf[feq_gen_i_d_ - 1] = ' ';
/* SOURCE ntwmxstr.for:2470 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:2471 */
/*<       if(isnumd(chr5(i:i)).eq.0)then >*/
	    if (isnumd_(chr5 + (feq_gen_i_d_ - 1), (ftnlen)1) == 0) {
/*           CHARACTER FOUND THAT IS NOT A DECIMAL DIGIT. */
/* SOURCE ntwmxstr.for:2473 */
/*<       if(chr5(i:i).ne.' ')then >*/
		if (*(unsigned char *)&chr5[feq_gen_i_d_ - 1] != ' ') {
/* SOURCE ntwmxstr.for:2474 */
/*<       prefix=chr5(i:i) >*/
		    *(unsigned char *)prefix = *(unsigned char *)&chr5[feq_gen_i_d_ - 
			    1];
/* SOURCE ntwmxstr.for:2475 */
/*<       chr5(i:i)=' ' >*/
		    *(unsigned char *)&chr5[feq_gen_i_d_ - 1] = ' ';
/* SOURCE ntwmxstr.for:2476 */
/*<       read(chr5,'(I5)',err=991)num >*/
		    feq_gen_ici_d_1.icierr = 1;
		    feq_gen_ici_d_1.iciend = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 5;
		    feq_gen_ici_d_1.iciunit = chr5;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
		    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer)
			    );
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_1 = e_rsfi();
		    if (feq_gen_i_d_1 != 0) {
			goto L991;
		    }
/* SOURCE ntwmxstr.for:2477 */
/*<       goto120 >*/
		    goto L120;
/* SOURCE ntwmxstr.for:2478 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:2479 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:2480 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2481 */
/*<   100 continue >*/
/* L100: */
    }
/*     NO NON-NUMBER FOUND.  MUST BE AN OLD STYLE EXTERIOR NUMBER. */
/* SOURCE ntwmxstr.for:2483 */
/*<       prefix=' ' >*/
    *(unsigned char *)prefix = ' ';
/* SOURCE ntwmxstr.for:2484 */
/*<       read(chr5,'(I5)',err=991)num >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = chr5;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ntwmxstr.for:2486 */
/*<   120 continue >*/
L120:
/* SOURCE ntwmxstr.for:2488 */
/*<       if(prefix.eq.' ')then >*/
    if (*(unsigned char *)prefix == ' ') {
/*       OLD STYLE */
/* SOURCE ntwmxstr.for:2490 */
/*<       if(num.lt.1.or.num.gt.1998)then >*/
	if (num < 1 || num > 1998) {
/* SOURCE ntwmxstr.for:2491 */
/*<       write(std6,50)num >*/
	    feq_gen_io_d__137.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__137);
	    do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:2492 */
/*<       num=1998 >*/
	    num = 1998;
/* SOURCE ntwmxstr.for:2493 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:2494 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2495 */
/*<       else >*/
    } else {
/*       NEW STYLE */
/* SOURCE ntwmxstr.for:2497 */
/*<       if(num.lt.1.or.num.gt.9999)then >*/
	if (num < 1 || num > 9999) {
/* SOURCE ntwmxstr.for:2498 */
/*<       write(std6,51)num,prefix >*/
	    feq_gen_io_d__138.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__138);
	    do_fio(&feq_gen_c_d_1, (char *)&num, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, prefix, (ftnlen)1);
	    e_wsfe();
/* SOURCE ntwmxstr.for:2499 */
/*<       num=9999 >*/
	    num = 9999;
/* SOURCE ntwmxstr.for:2500 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:2501 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2502 */
/*<       endif >*/
    }
/*     COMPUTE INDEX INTO USENIN() TO FIND THE INTERNAL NUMBER */
/* SOURCE ntwmxstr.for:2505 */
/*<       if(prefix.eq.' ')then >*/
    if (*(unsigned char *)prefix == ' ') {
/* SOURCE ntwmxstr.for:2506 */
/*<       ii=num >*/
	ii = num;
/* SOURCE ntwmxstr.for:2507 */
/*<       elseif(prefix.eq.'F')then >*/
    } else if (*(unsigned char *)prefix == 'F') {
/* SOURCE ntwmxstr.for:2508 */
/*<       ii=-num >*/
	ii = -num;
/* SOURCE ntwmxstr.for:2509 */
/*<       elseif(prefix.eq.'U')then >*/
    } else if (*(unsigned char *)prefix == 'U') {
/* SOURCE ntwmxstr.for:2510 */
/*<       ii=num >*/
	ii = num;
/* SOURCE ntwmxstr.for:2511 */
/*<       elseif(prefix.eq.'D')then >*/
    } else if (*(unsigned char *)prefix == 'D') {
/* SOURCE ntwmxstr.for:2512 */
/*<       ii=9999+num >*/
	ii = num + 9999;
/* SOURCE ntwmxstr.for:2513 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2514 */
/*<       write(std6,52)prefix >*/
	feq_gen_io_d__140.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__140);
	do_fio(&feq_gen_c_d_1, prefix, (ftnlen)1);
	e_wsfe();
/* SOURCE ntwmxstr.for:2515 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2516 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2518 */
/*<       if(usenin(ii).eq.0)then >*/
    if (usintp_1.usenin[ii + 9999] == 0) {
/*       NODE HAS NOT BEEN SEEN BEFORE. */
/* SOURCE ntwmxstr.for:2520 */
/*<       write(std6,56)enf >*/
	feq_gen_io_d__141.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__141);
	do_fio(&feq_gen_c_d_1, enf, (ftnlen)5);
	e_wsfe();
/* SOURCE ntwmxstr.for:2521 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2522 */
/*<       else >*/
    } else {
/*       NODE HAS BEEN SEEN BEFORE */
/* SOURCE ntwmxstr.for:2525 */
/*<       inn=usenin(ii) >*/
	*inn = usintp_1.usenin[ii + 9999];
/* SOURCE ntwmxstr.for:2526 */
/*<       if(minus.lt.0)inn=-inn >*/
	if (minus < 0) {
	    *inn = -(*inn);
	}
/* SOURCE ntwmxstr.for:2527 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2528 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:2529 */
/*<   991 continue >*/
L991:
/*     CONVERSION ERROR IN THE FIELD */
/* SOURCE ntwmxstr.for:2531 */
/*<       write(std6,58)chr5 >*/
    feq_gen_io_d__142.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__142);
    do_fio(&feq_gen_c_d_1, chr5, (ftnlen)5);
    e_wsfe();
/* SOURCE ntwmxstr.for:2532 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2533 */
/*<       end >*/
    return 0;
} /* getinn_ */




/* SOURCE ntwmxstr.for:2537 */
/*<        >*/
/* Subroutine */ int getrec_(integer *stdout, integer *begbuf, integer *
	endbuf, integer *lbuff, integer *feq_storage_buff, integer *iget, integer *nin, 
	integer *emcadr, integer *conid, integer *point, integer *nodein)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX GETREC CALLED WHEN BUFFER IS EMPT\
Y.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__143 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Get the next record from the pending instruction buffer. */
/* SOURCE ntwmxstr.for:2545 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2547 */
/*<        >*/
/* SOURCE ntwmxstr.for:2549 */
/*<       integerbuff(lbuff) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     BEGBUF - beginning address for pending instruction buffer */
/*     ENDBUF - end point for the pending instruction buffer */
/*     LBUFF  - number of elements in the pending instruction buffer */
/*     BUFF   - pending instruction buffer */
/*     IGET   - address of the instruction in the pending instruction */
/*               buffer */
/*     NIN    - number or records remaining in the pending instruction */
/*               buffer */
/*     EMCADR - address of relationship in EMC(*) */
/*     CONID  - connecting item id code.  Defined in MAKEMC */
/*     POINT  - pointer to the connecting item */
/*     NODEIN - user node identification string */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:2567 */
/*<    50 format(' *BUG:XXX GETREC CALLED WHEN BUFFER IS EMPTY.') >*/
/* *********************************************************************** */
/*     ON ENTRY NIN SHOULD BE POSITIVE BUT CHECK FOR BUGS */
/* SOURCE ntwmxstr.for:2570 */
/*<       if(nin.le.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> buff(feq_storage_buff, 1);

    /* Function Body */
/* L50: */
    if (*nin <= 0) {
/* SOURCE ntwmxstr.for:2571 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__143.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__143);
	e_wsfe();
/* SOURCE ntwmxstr.for:2572 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2573 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2574 */
/*<       nin=nin-1 >*/
	--(*nin);
/* SOURCE ntwmxstr.for:2575 */
/*<       emcadr=buff(iget) >*/
	*emcadr = buff[*iget];
/* SOURCE ntwmxstr.for:2576 */
/*<       conid=buff(iget+1) >*/
	*conid = buff[*iget + 1];
/* SOURCE ntwmxstr.for:2577 */
/*<       point=buff(iget+2) >*/
	*point = buff[*iget + 2];
/* SOURCE ntwmxstr.for:2578 */
/*<       nodein=buff(iget+3) >*/
	*nodein = buff[*iget + 3];
/* SOURCE ntwmxstr.for:2580 */
/*<       iget=iget+4 >*/
	*iget += 4;
/* SOURCE ntwmxstr.for:2581 */
/*<       if(iget.gt.endbuf)then >*/
	if (*iget > *endbuf) {
/*         WRAP TO THE BEGINNING */
/* SOURCE ntwmxstr.for:2583 */
/*<       iget=begbuf >*/
	    *iget = *begbuf;
/* SOURCE ntwmxstr.for:2584 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2585 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2587 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:2588 */
/*<       end >*/
} /* getrec_ */




/* SOURCE ntwmxstr.for:2592 */
/*<       integerfunctiongetusb(ibn) >*/
integer getusb_(integer *ibn)
{
    /* System generated locals */
    integer ret_val;

/*     + + + PURPOSE + + + */
/*     Get a user branch number. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2599 */
/*<       integeribn >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IBN    - internal branch number */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2605 */
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
/* INCLUDE ntwmxstr.for:2606 */
/*     COMMON BLOCKS FOR THE TRANSLATION FROM INTERNAL NODE AND BRANCH */
/*     NUMBERS TO THEIR USER DESIGINATION.  NEED TWO BLOCKS BECAUSE */
/*     OF FORTRAN RESTRICTIONS ON CHARACTER VARIABLES IN COMMON WITH */
/*     NON-CHARACTER VARIABLES. */
/*     ALSO INCLUDE THE MAPPING VECTOR SO THE OLD STYLE INPUT WILL */
/*     OUTPUT EXTERIOR NODES IN ASCENDING NUMERICAL ORDER. */
/* SOURCE inusnb.cmn:10 */
/*<       integerinbrus(9999),usnsrt(mnex) >*/
/* SOURCE inusnb.cmn:12 */
/*<       character*5inenus(mnex) >*/
/* SOURCE inusnb.cmn:14 */
/*<       common/inbr/inbrus >*/
/* SOURCE inusnb.cmn:16 */
/*<       common/inen/usnsrt >*/
/* SOURCE inusnb.cmn:18 */
/*<       common/inenc/inenus >*/

/* *********************************************************************** */
/* SOURCE ntwmxstr.for:2608 */
/*<       if(ibn>0)then >*/
    if (*ibn > 0) {
/* SOURCE ntwmxstr.for:2609 */
/*<       getusb=inbrus(ibn) >*/
	ret_val = inbr_1.inbrus[*ibn - 1];
/* SOURCE ntwmxstr.for:2610 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2611 */
/*<       getusb=0 >*/
	ret_val = 0;
/* SOURCE ntwmxstr.for:2612 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2613 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:2614 */
/*<       end >*/
} /* getusb_ */




/* SOURCE ntwmxstr.for:2618 */
/*<       integerfunctionisndav(jpt,node,ljoin,join,lemc,emc) >*/
integer isndav_(integer *jpt, integer *node, integer *ljoin, integer *feq_storage_join, 
	integer *lemc, integer *feq_storage_emc)
{
    /* System generated locals */
    integer ret_val;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, rpt, code, node2, nd2adr, emcadr, nodadr;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    integer nxtadr;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__146 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Is node available for initiating a path at a junction?  We */
/*     already know that the path is available.  A relationship */
/*     must be available at the node.  If this is true then any */
/*     of the following will qualify the node as available: */
/*     1. Node has CODE 8. */
/*     2. Node is a flow node with CODE 4. */
/*     3. Node is a flow node with CODE 5. */
/*     4. Node is a flow node with CODE 14. */
/*     5. Node is attached to a node that is already initiated or */
/*        terminated. */
/*     6. Sum of flows = 0 is still available for the junction. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2636 */
/*<       integerjpt,lemc,ljoin,node >*/
/* SOURCE ntwmxstr.for:2637 */
/*<       integeremc(lemc),join(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JPT    - pointer for the junction descriptions */
/*     NODE   - node number */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2648 */
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
/* SOURCE ntwmxstr.for:2651 */
/*<       integercode,emcadr,n,nd2adr,nodadr,node2,nxtadr,rpt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:2654 */
/*<       integerexnodn >*/
/* SOURCE ntwmxstr.for:2655 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:2658 */
/*<       externalexnodn,getusn >*/
/* *********************************************************************** */
/*     Scan the relationships at NODE--for each available relationship */
/*     check if it satisfies any of the criteria. */
/* SOURCE ntwmxstr.for:2663 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    n = join[*jpt];
/* SOURCE ntwmxstr.for:2664 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:2665 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:2666 */
/*<        >*/
	feq_gen_io_d__146.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__146);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* NODE="), (ftnlen)16);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT IN LIST"), (ftnlen)12);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN ISNDAV. JPT="), (ftnlen)16);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE ntwmxstr.for:2668 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2669 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2671 */
/*<       nxtadr=join(nodadr+2*n) >*/
    nxtadr = join[nodadr + (n << 1)];
/* SOURCE ntwmxstr.for:2672 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:2673 */
/*<       if(nxtadr.gt.0)then >*/
    if (nxtadr > 0) {
/* SOURCE ntwmxstr.for:2674 */
/*<       rpt=join(nxtadr+1) >*/
	rpt = join[nxtadr + 1];
/* SOURCE ntwmxstr.for:2675 */
/*<       node2=join(nxtadr+2) >*/
	node2 = join[nxtadr + 2];
/* SOURCE ntwmxstr.for:2676 */
/*<       emcadr=join(rpt) >*/
	emcadr = join[rpt];
/* SOURCE ntwmxstr.for:2677 */
/*<       if(emcadr.gt.0)then >*/
	if (emcadr > 0) {
/*           THE RELATIONSHIP IS AVAILABLE. */
/* SOURCE ntwmxstr.for:2679 */
/*<       code=emc(emcadr) >*/
	    code = emc[emcadr];
/* SOURCE ntwmxstr.for:2680 */
/*<       if(code.eq.8)then >*/
	    if (code == 8) {
/* SOURCE ntwmxstr.for:2681 */
/*<       isndav=1 >*/
		ret_val = 1;
/* SOURCE ntwmxstr.for:2682 */
/*<       return >*/
		return ret_val;
/* SOURCE ntwmxstr.for:2683 */
/*<       elseif(code.eq.4)then >*/
	    } else if (code == 4) {
/* SOURCE ntwmxstr.for:2684 */
/*<       if(emc(emcadr+4).eq.node)then >*/
		if (emc[emcadr + 4] == *node) {
/* SOURCE ntwmxstr.for:2685 */
/*<       isndav=1 >*/
		    ret_val = 1;
/* SOURCE ntwmxstr.for:2686 */
/*<       return >*/
		    return ret_val;
/* SOURCE ntwmxstr.for:2687 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:2688 */
/*<       elseif(code.eq.5)then >*/
	    } else if (code == 5) {
/* SOURCE ntwmxstr.for:2689 */
/*<       if(emc(emcadr+4).eq.node)then >*/
		if (emc[emcadr + 4] == *node) {
/* SOURCE ntwmxstr.for:2690 */
/*<       isndav=1 >*/
		    ret_val = 1;
/* SOURCE ntwmxstr.for:2691 */
/*<       return >*/
		    return ret_val;
/* SOURCE ntwmxstr.for:2692 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:2693 */
/*<       elseif(code.eq.14)then >*/
	    } else if (code == 14) {
/* SOURCE ntwmxstr.for:2694 */
/*<       if(emc(emcadr+3).eq.node)then >*/
		if (emc[emcadr + 3] == *node) {
/* SOURCE ntwmxstr.for:2695 */
/*<       isndav=1 >*/
		    ret_val = 1;
/* SOURCE ntwmxstr.for:2696 */
/*<       return >*/
		    return ret_val;
/* SOURCE ntwmxstr.for:2697 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:2698 */
/*<       endif >*/
	    }
/*           AT THIS POINT WE CHECK NODE2 TO SEE IF IT INVOLVES A NODE */
/*           ALREADY INITIATED OR TERMINATED.  NODE2 SHOULD EXIST. */
/* SOURCE ntwmxstr.for:2702 */
/*<       if(node2.eq.0)then >*/
	    if (node2 == 0) {
/* SOURCE ntwmxstr.for:2703 */
/*<        >*/
		feq_gen_io_d__152.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsle(&feq_gen_io_d__152);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* NODE2=0 IN ISNDAV. JPT="), (
			ftnlen)34);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer))
			;
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODE="), (ftnlen)6);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		e_wsle();
/* SOURCE ntwmxstr.for:2705 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2706 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:2708 */
/*<       nd2adr=exnodn(node2,jpt,ljoin,join) >*/
	    nd2adr = exnodn_(&node2, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:2709 */
/*<       if(nd2adr.le.0)then >*/
	    if (nd2adr <= 0) {
/* SOURCE ntwmxstr.for:2710 */
/*<        >*/
		feq_gen_io_d__154.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsle(&feq_gen_io_d__154);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* NODE2="), (ftnlen)17);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &node2);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT FOUND"), (ftnlen)10);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN JUNCTION JPT="), (ftnlen)17);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer))
			;
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN ISNDAV."), (ftnlen)11);
		e_wsle();
/* SOURCE ntwmxstr.for:2712 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2713 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:2715 */
/*<       if(join(nd2adr+n).gt.0)then >*/
	    if (join[nd2adr + n] > 0) {
/*             NODE2 PATH IS INITIATED OR TERMINATED. */
/* SOURCE ntwmxstr.for:2717 */
/*<       isndav=1 >*/
		ret_val = 1;
/* SOURCE ntwmxstr.for:2718 */
/*<       return >*/
		return ret_val;
/* SOURCE ntwmxstr.for:2719 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:2721 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2723 */
/*<       nxtadr=join(nxtadr) >*/
	nxtadr = join[nxtadr];
/* SOURCE ntwmxstr.for:2724 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:2725 */
/*<       endif >*/
    }
/*     IF WE ARRIVE HERE THRE IS NO AVAILABLE RELATIONSHIP MEETING THE */
/*     CRITERIA.  CHECK IF SUM OF FLOWS = 0 IS STILL AVAILABLE. */
/* SOURCE ntwmxstr.for:2730 */
/*<       if(join(jpt+1).gt.0)then >*/
    if (join[*jpt + 1] > 0) {
/* SOURCE ntwmxstr.for:2731 */
/*<       isndav=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2732 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2733 */
/*<       isndav=0 >*/
	ret_val = 0;
/* SOURCE ntwmxstr.for:2734 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2736 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:2737 */
/*<       end >*/
} /* isndav_ */




/* SOURCE ntwmxstr.for:2741 */
/*<       integerfunctionisndin(node,jpt,ljoin,join) >*/
integer isndin_(integer *node, integer *jpt, integer *ljoin, integer *feq_storage_join)
{
    /* System generated locals */
    integer ret_val;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, adr, nodadr;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__157 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Is the path for the given node initiated?  If so return 1 else */
/*     return zero. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2749 */
/*<       integerjpt,ljoin,node >*/
/* SOURCE ntwmxstr.for:2750 */
/*<       integerjoin(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NODE   - node number */
/*     JPT    - pointer for the junction descriptions */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2759 */
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
/* SOURCE ntwmxstr.for:2762 */
/*<       integeradr,n,nodadr >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:2765 */
/*<       integerexnodn >*/
/* SOURCE ntwmxstr.for:2766 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:2769 */
/*<       externalexnodn,getusn >*/
/* *********************************************************************** */
/*     SET NUMBER OF NODES */
/* SOURCE ntwmxstr.for:2772 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    /* Function Body */
    n = join[*jpt];
/* SOURCE ntwmxstr.for:2774 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:2775 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:2776 */
/*<        >*/
	feq_gen_io_d__157.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__157);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ISNDIN:NODE="), (ftnlen)23);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT IN"), (ftnlen)7);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" LIST. JPT="), (ftnlen)11);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE ntwmxstr.for:2778 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2779 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2781 */
/*<       adr=nodadr+n >*/
    adr = nodadr + n;
/* SOURCE ntwmxstr.for:2782 */
/*<       if(join(adr).ne.0)then >*/
    if (join[adr] != 0) {
/* SOURCE ntwmxstr.for:2783 */
/*<       isndin=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2784 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2785 */
/*<       isndin=0 >*/
	ret_val = 0;
/* SOURCE ntwmxstr.for:2786 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2788 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:2789 */
/*<       end >*/
} /* isndin_ */




/* SOURCE ntwmxstr.for:2793 */
/*<       integerfunctionisnumd(x) >*/
integer isnumd_(char *x, ftnlen x_len)
{
    /* System generated locals */
    integer ret_val;

/*     + + + PURPOSE + + + */
/*     If X is a decimal digit return 1 else return 0. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2800 */
/*<       characterx*1 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     X      - character checked for being a numerical digit */
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:2805 */
/*<       if(x.eq.'0')then >*/
    if (*(unsigned char *)x == '0') {
/* SOURCE ntwmxstr.for:2806 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2807 */
/*<       elseif(x.eq.'1')then >*/
    } else if (*(unsigned char *)x == '1') {
/* SOURCE ntwmxstr.for:2808 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2809 */
/*<       elseif(x.eq.'2')then >*/
    } else if (*(unsigned char *)x == '2') {
/* SOURCE ntwmxstr.for:2810 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2811 */
/*<       elseif(x.eq.'3')then >*/
    } else if (*(unsigned char *)x == '3') {
/* SOURCE ntwmxstr.for:2812 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2813 */
/*<       elseif(x.eq.'4')then >*/
    } else if (*(unsigned char *)x == '4') {
/* SOURCE ntwmxstr.for:2814 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2815 */
/*<       elseif(x.eq.'5')then >*/
    } else if (*(unsigned char *)x == '5') {
/* SOURCE ntwmxstr.for:2816 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2817 */
/*<       elseif(x.eq.'6')then >*/
    } else if (*(unsigned char *)x == '6') {
/* SOURCE ntwmxstr.for:2818 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2819 */
/*<       elseif(x.eq.'7')then >*/
    } else if (*(unsigned char *)x == '7') {
/* SOURCE ntwmxstr.for:2820 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2821 */
/*<       elseif(x.eq.'8')then >*/
    } else if (*(unsigned char *)x == '8') {
/* SOURCE ntwmxstr.for:2822 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2823 */
/*<       elseif(x.eq.'9')then >*/
    } else if (*(unsigned char *)x == '9') {
/* SOURCE ntwmxstr.for:2824 */
/*<       isnumd=1 >*/
	ret_val = 1;
/* SOURCE ntwmxstr.for:2825 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:2826 */
/*<       isnumd=0 >*/
	ret_val = 0;
/* SOURCE ntwmxstr.for:2827 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2828 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:2829 */
/*<       end >*/
} /* isnumd_ */




/* SOURCE ntwmxstr.for:2833 */
/*<       integerfunctionisnumr(node,jpt,ljoin,join,lemc,emc) >*/
integer isnumr_(integer *node, integer *jpt, integer *ljoin, integer *feq_storage_join, 
	integer *lemc, integer *feq_storage_emc)
{
    /* System generated locals */
    integer ret_val;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, knt, rpt, code, qnode, emcadr, nodadr;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    integer nxtadr;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__161 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Return the number of available relationships at NODE. */
/*     All codes can be counted. */
/*     For a flow node relationship to be available it must have its */
/*     flow node match NODE. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2843 */
/*<       integerjpt,lemc,ljoin,node >*/
/* SOURCE ntwmxstr.for:2844 */
/*<       integeremc(lemc),join(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NODE   - node number */
/*     JPT    - pointer for the junction descriptions */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     LEMC   - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:2855 */
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
/* SOURCE ntwmxstr.for:2858 */
/*<       integercode,emcadr,knt,n,nodadr,nxtadr,qnode,rpt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:2861 */
/*<       integerexnodn >*/
/* SOURCE ntwmxstr.for:2862 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:2865 */
/*<       externalexnodn,getusn >*/
/* *********************************************************************** */
/*     SET NUMBER OF NODES */
/* SOURCE ntwmxstr.for:2868 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    n = join[*jpt];
/* SOURCE ntwmxstr.for:2870 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:2871 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:2872 */
/*<        >*/
	feq_gen_io_d__161.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__161);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ISNUMR:NODE="), (ftnlen)23);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT IN"), (ftnlen)7);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" LIST. JPT="), (ftnlen)11);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE ntwmxstr.for:2874 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:2875 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2877 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE ntwmxstr.for:2878 */
/*<       nxtadr=join(nodadr+2*n) >*/
    nxtadr = join[nodadr + (n << 1)];
/* SOURCE ntwmxstr.for:2880 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:2881 */
/*<       if(nxtadr.gt.0)then >*/
    if (nxtadr > 0) {
/* SOURCE ntwmxstr.for:2882 */
/*<       rpt=join(nxtadr+1) >*/
	rpt = join[nxtadr + 1];
/* SOURCE ntwmxstr.for:2883 */
/*<       emcadr=join(rpt) >*/
	emcadr = join[rpt];
/* SOURCE ntwmxstr.for:2884 */
/*<       if(emcadr.gt.0)then >*/
	if (emcadr > 0) {
/* SOURCE ntwmxstr.for:2885 */
/*<       qnode=0 >*/
	    qnode = 0;
/*           The relationship is unused. Is it available to NODE? */
/* SOURCE ntwmxstr.for:2887 */
/*<       code=emc(emcadr) >*/
	    code = emc[emcadr];
/* SOURCE ntwmxstr.for:2888 */
/*<       if(code.eq.4)then >*/
	    if (code == 4) {
/* SOURCE ntwmxstr.for:2889 */
/*<       qnode=emc(emcadr+4) >*/
		qnode = emc[emcadr + 4];
/* SOURCE ntwmxstr.for:2890 */
/*<       elseif(code.eq.5)then >*/
	    } else if (code == 5) {
/* SOURCE ntwmxstr.for:2891 */
/*<       qnode=emc(emcadr+4) >*/
		qnode = emc[emcadr + 4];
/* SOURCE ntwmxstr.for:2892 */
/*<       elseif(code.eq.14)then >*/
	    } else if (code == 14) {
/* SOURCE ntwmxstr.for:2893 */
/*<       qnode=emc(emcadr+3) >*/
		qnode = emc[emcadr + 3];
/* SOURCE ntwmxstr.for:2894 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:2895 */
/*<       if(qnode.eq.0)then >*/
	    if (qnode == 0) {
/*             NO RESTRICTIONS ON AVAILABILITY. */
/* SOURCE ntwmxstr.for:2897 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE ntwmxstr.for:2898 */
/*<       else >*/
	    } else {
/* SOURCE ntwmxstr.for:2899 */
/*<       if(qnode.eq.node)then >*/
		if (qnode == *node) {
/* SOURCE ntwmxstr.for:2900 */
/*<       knt=knt+1 >*/
		    ++knt;
/* SOURCE ntwmxstr.for:2901 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:2902 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:2903 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:2904 */
/*<       nxtadr=join(nxtadr) >*/
	nxtadr = join[nxtadr];
/* SOURCE ntwmxstr.for:2905 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:2906 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:2908 */
/*<       isnumr=knt >*/
    ret_val = knt;
/* SOURCE ntwmxstr.for:2909 */
/*<       return >*/
    return ret_val;
/* SOURCE ntwmxstr.for:2910 */
/*<       end >*/
} /* isnumr_ */




/* SOURCE ntwmxstr.for:2914 */
/*<        >*/
/* Subroutine */ int makemc_(integer *stdout, integer *bnode, integer *nentry,
	 integer *lemc, integer *ljoin, integer *lbuff, integer *nex, integer 
	*nbra, integer *feq_storage_exnodt, integer *feq_storage_brpt, integer *nbn, integer *bdyflg, 
	integer *mrmat, integer *feq_storage_join, integer *feq_storage_emc, integer *feq_storage_buff, integer *
	feq_storage_add, integer *feq_storage_exnvar, integer *brnvar, integer *neq, integer *feq_storage_varid)
{
    /* Format strings */
    static char fmt_50[] = "(\002 TO BUFF: EMCADR=\002,i5,\002 CODE=\002,i3\
,\002 CONID=\002,a4,\002 POINT=\002,i7,\002 NODEIN=\002,a5)";
    static char fmt_52[] = "(\002 FR BUFF: EMCADR=\002,i5,\002 CODE=\002,i3\
,\002 CONID=\002,a4,\002 POINT=\002,i7,\002 NODEIN=\002,a5)";
    static char fmt_54[] = "(i9,1x,a6,1x,i6,1x,a)";
    static char fmt_55[] = "(i9,2i6,1x,a)";
    static char fmt_56[] = "(\002 *BUG:XXX BNODE=\002,a5,\002 not on boundar\
y in MAKEMC.\002)";
    static char fmt_58[] = "(/,\002 Dump of activity in MAKEMC.\002)";
    static char fmt_60[] = "(/,\002 *ERR:301* Wrong entry count=\002,i5,\002\
 in MAKEMC.\002,\002  Count expected=\002,i5,\002.\002,/,5x,\002  Model may \
be disjoint.\002)";
    static char fmt_2010[] = "(/,\002 *ERR:103* Incorrect no. of equations s\
pecified\002,\002 for Network Matrix\002,/,1x,\002No. of equations specified\
  = \002,i5,/,1x,\002No. of equations required   = \002,i5)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2[2];
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[4], feq_gen_ch_d_4[4], feq_gen_ch_d_5[63];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    integer j, it, feq_gen_feql_index1_d_, nin, jpt, code, bran;
    char chr63[63];
    integer iget, dexn, ivar, nexp, uexn, iput;
    extern /* Subroutine */ int fnd514_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), find4_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
    integer node2;
    extern /* Subroutine */ int find8_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
    integer conid, point, begbuf, emcadr;
    extern /* Character */ VOID fndemc_(char *, ftnlen, integer *, integer *, 
	    integer *);
    integer endbuf;
    extern /* Subroutine */ int getrec_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
    integer nodein;
    extern /* Character */ VOID conchr_(char *, ftnlen, integer *);
    extern /* Subroutine */ int fndany_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), mkndin_(
	    integer *, integer *, integer *, integer *, integer *, integer *);
    integer mkpath;
    extern integer isndin_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int bnvarn_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);
    integer maxnin;
    extern /* Subroutine */ int fnvarn_(integer *, integer *, integer *, 
	    integer *, integer *);
    extern integer fndnxt_(integer *, integer *, integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int putrec_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer nodout, ientry;
    char varname[6];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__168 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__179 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__191 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__192 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__194 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__195 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__198 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__199 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__201 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__206 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__209 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__210 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__211 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__212 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__214 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__215 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__217 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__218 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__219 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__220 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__221 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__222 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__223 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__224 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__225 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__226 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__227 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__228 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__229 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Make a reordered version of EMC using ADD to store the order */
/*     and BNODE as the starting boundary node.  Also number the */
/*     variables and count the equations. */
/* SOURCE ntwmxstr.for:2925 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:2928 */
/*<        >*/
/* SOURCE ntwmxstr.for:2930 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     BNODE  - boundary node number at which to start defining the */
/*               coefficient matrix */

/*     NENTRY - number of entries in Network Matrix input */
/*     LEMC   - length of EMC(*) */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     LBUFF  - number of elements in the pending instruction buffer */
/*     NEX    - number of exterior nodes in the model */
/*     NBRA   - number of branches in the model */
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
/*     NBN    - total number on nodes on branches in the model */
/*     BDYFLG - 0 if user supplied boundary node; 1 if not */
/*     JOIN   - vector for storing the junction descriptions */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     BUFF   - pending instruction buffer */
/*     ADD    - Address of entry in EMC, that is, the index in EMC */
/*               at which a matrix control specification begins. */
/*     EXNVAR - variable number for the first variable(Q) at an exterior */
/*               node */
/*     BRNVAR - branch node variable number for first variable on the */
/*               branch(flow rate) */
/*     NEQ    - equation counter */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ntwmxstr.for:2983 */
/*<       integerbc,branch,junc,lpr,nb,nrec,out >*/
/* SOURCE ntwmxstr.for:2984 */
/*<       parameter(nrec=4,junc=2,branch=1,bc=3,nb=4,lpr=5) >*/
/* SOURCE ntwmxstr.for:2985 */
/*<       parameter(out=0) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:2988 */
/*<        >*/
/* SOURCE ntwmxstr.for:2991 */
/*<       characterchr63*63,varname*6 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntwmxstr.for:2994 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:2997 */
/*<       integerfndnxt,isndin >*/
/* SOURCE ntwmxstr.for:2998 */
/*<       characterconchr*4,fndemc*63,getusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:3001 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:2914 */
/*<       integer feql_index1 >*/
/* SOURCE ntwmxstr.for:3005 */
/*<    50  >*/
/* SOURCE ntwmxstr.for:3007 */
/*<    52  >*/
/* SOURCE ntwmxstr.for:3009 */
/*<    54 format(i9,1x,a6,1x,i6,1x,a) >*/
/* SOURCE ntwmxstr.for:3010 */
/*<    55 format(i9,2i6,1x,a) >*/
/* SOURCE ntwmxstr.for:3011 */
/*<    56 format(' *BUG:XXX BNODE=',a5,' not on boundary in MAKEMC.') >*/
/* SOURCE ntwmxstr.for:3012 */
/*<    58 format(/,' Dump of activity in MAKEMC.') >*/
/* SOURCE ntwmxstr.for:3013 */
/*<    60  >*/
/* SOURCE ntwmxstr.for:3016 */
/*<  2010  >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:3021 */
/*<       if(out.gt.0)write(stdout,58) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> add(feq_storage_add, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> buff(feq_storage_buff, 1);

    feq::IndexedPointer<integer> exnvar(feq_storage_exnvar, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> varid(feq_storage_varid, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L55: */
/* L56: */
/* L58: */
/* L60: */
/* L2010: */
    if (FALSE_) {
	feq_gen_io_d__168.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__168);
	e_wsfe();
    }
/*     SET THE CIRCULAR BUFFER VALUES */
/* SOURCE ntwmxstr.for:3023 */
/*<       begbuf=1 >*/
    begbuf = 1;
/* SOURCE ntwmxstr.for:3024 */
/*<       maxnin=lbuff/nrec >*/
    maxnin = *lbuff / 4;
/* SOURCE ntwmxstr.for:3025 */
/*<       endbuf=maxnin*nrec+begbuf >*/
    endbuf = (maxnin << 2) + begbuf;
/* SOURCE ntwmxstr.for:3026 */
/*<       iput=begbuf >*/
    iput = begbuf;
/* SOURCE ntwmxstr.for:3027 */
/*<       iget=begbuf >*/
    iget = begbuf;
/* SOURCE ntwmxstr.for:3028 */
/*<       nin=0 >*/
    nin = 0;
/*     Clear the variable id numbers */
/* SOURCE ntwmxstr.for:3032 */
/*<       dofeql_index1=1,mrmat >*/
    feq_gen_i_d_1 = *mrmat;
    for (feq_gen_feql_index1_d_ = 1; feq_gen_feql_index1_d_ <= feq_gen_i_d_1; ++feq_gen_feql_index1_d_) {
/* SOURCE ntwmxstr.for:3032 */
/*<       varid(feql_index1)=0 >*/
	varid[feq_gen_feql_index1_d_] = 0;
/* SOURCE ntwmxstr.for:3032 */
/*<       enddo >*/
    }
/*     CLEAR THE EQUATION COUNTER */
/* SOURCE ntwmxstr.for:3035 */
/*<       neq=0 >*/
    *neq = 0;
/*     SET THE VARIABLE COUNTER TO THE NEXT VARIABLE NUMBER */
/* SOURCE ntwmxstr.for:3038 */
/*<       ivar=1 >*/
    ivar = 1;
/*     CLEAR THE EXTERIOR NODE VARIABLE INDEX VECTOR */
/* SOURCE ntwmxstr.for:3042 */
/*<       do200j=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE ntwmxstr.for:3043 */
/*<       exnvar(j)=0 >*/
	exnvar[j] = 0;
/* SOURCE ntwmxstr.for:3044 */
/*<   200 continue >*/
/* L200: */
    }
/*     SET THE POINT FOR PUTTING POINTERS INTO ADD(). PREVIOUS */
/*     CONTENTS OF ADD NO LONGER NEEDED.  POINT TO NEXT OPEN SLOT. */
/* SOURCE ntwmxstr.for:3048 */
/*<       ientry=1 >*/
    ientry = 1;
/*     Create the record for the starting boundary condition.  Note that */
/*     free nodes in non-default context are not permitted at a boundary. */
/*     The record contents are: */
/*     elem#   Contents */
/*     -----   ---------------------------------------------------------- */
/*       1     Address of entry in EMC() to be placed in ADD() */
/*       2     Connecting item ID number */
/*               1-branch number(may be negative)(BRANCH) */
/*               2-junction pointer(JUNC) */
/*               3-boundary condition(BC) */
/*               4-null branch(NB) */
/*               5-level pool reservoir(LPR) */
/*       3     Pointer to the connecting item. */
/*       4     node of entry for a junction, node for boundary condtion */
/*     A record is created for an entry to be made in EMC().  There are */
/*     some entries in EMC which are transferred directly and not by */
/*     a record in the buffer. */
/* SOURCE ntwmxstr.for:3070 */
/*<       if(exnodt(3,bnode).le.0)then >*/
    if (exnodt[*bnode * 9 + 3] <= 0) {
/*       FREE NODE.  EVERY FREE NODE IS ATTACHED TO EITHER A LPR OR */
/*       A NB.  GET THE EMC ADDRESS FOR THE BC. */
/* SOURCE ntwmxstr.for:3074 */
/*<       if(exnodt(5,bnode).ge.0)then >*/
	if (exnodt[*bnode * 9 + 5] >= 0) {
/* SOURCE ntwmxstr.for:3075 */
/*<       write(stdout,56)getusn(bnode) >*/
	    feq_gen_io_d__179.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__179);
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, bnode);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:3076 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:3077 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:3078 */
/*<       emcadr=-exnodt(5,bnode) >*/
	emcadr = -exnodt[*bnode * 9 + 5];
/*       GET THE CODE FROM EMC TO GET DESCRIPTION OF THE ITEM ATTACHED */
/*       TO THE FREE NODE. */
/* SOURCE ntwmxstr.for:3083 */
/*<       point=abs(exnodt(2,bnode)) >*/
	point = (feq_gen_i_d_1 = exnodt[*bnode * 9 + 2], abs(feq_gen_i_d_1));
/* SOURCE ntwmxstr.for:3084 */
/*<       code=emc(point) >*/
	code = emc[point];
/* SOURCE ntwmxstr.for:3085 */
/*<       if(code.eq.7)then >*/
	if (code == 7) {
/*         ATTACHED TO A LPR. GET THE UPSTREAM AND DOWNSTREAM NODES */
/*         AND SET THE DIRECTION IN EMC ACCORDINGLY. ALSO SET CONID */
/*         AND THE NODE AT THE END OF THE LPR OPPOSITE FROM BNODE. */
/* SOURCE ntwmxstr.for:3090 */
/*<       uexn=emc(point+5) >*/
	    uexn = emc[point + 5];
/* SOURCE ntwmxstr.for:3091 */
/*<       dexn=emc(point+1) >*/
	    dexn = emc[point + 1];
/* SOURCE ntwmxstr.for:3092 */
/*<       if(bnode.eq.uexn)then >*/
	    if (*bnode == uexn) {
/* SOURCE ntwmxstr.for:3093 */
/*<       nodein=dexn >*/
		nodein = dexn;
/* SOURCE ntwmxstr.for:3094 */
/*<       emc(point+6)=1 >*/
		emc[point + 6] = 1;
/* SOURCE ntwmxstr.for:3095 */
/*<       else >*/
	    } else {
/* SOURCE ntwmxstr.for:3096 */
/*<       nodein=uexn >*/
		nodein = uexn;
/* SOURCE ntwmxstr.for:3097 */
/*<       emc(point+6)=-1 >*/
		emc[point + 6] = -1;
/* SOURCE ntwmxstr.for:3098 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3100 */
/*<       conid=lpr >*/
	    conid = 5;
/* SOURCE ntwmxstr.for:3101 */
/*<       elseif(code.eq.15)then >*/
	} else if (code == 15) {
/*         ATTACHED TO A NB.  DO THE SAME AS FOR LPR */
/* SOURCE ntwmxstr.for:3104 */
/*<       uexn=emc(point+1) >*/
	    uexn = emc[point + 1];
/* SOURCE ntwmxstr.for:3105 */
/*<       dexn=emc(point+2) >*/
	    dexn = emc[point + 2];
/* SOURCE ntwmxstr.for:3106 */
/*<       if(bnode.eq.uexn)then >*/
	    if (*bnode == uexn) {
/* SOURCE ntwmxstr.for:3107 */
/*<       nodein=dexn >*/
		nodein = dexn;
/* SOURCE ntwmxstr.for:3108 */
/*<       emc(point+3)=1 >*/
		emc[point + 3] = 1;
/* SOURCE ntwmxstr.for:3109 */
/*<       else >*/
	    } else {
/* SOURCE ntwmxstr.for:3110 */
/*<       nodein=uexn >*/
		nodein = uexn;
/* SOURCE ntwmxstr.for:3111 */
/*<       emc(point+3)=-1 >*/
		emc[point + 3] = -1;
/* SOURCE ntwmxstr.for:3112 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3114 */
/*<       conid=nb >*/
	    conid = 4;
/* SOURCE ntwmxstr.for:3115 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:3116 */
/*<        >*/
	    feq_gen_io_d__187.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__187);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* INVALID CODE FOR BOUNDARY "), (
		    ftnlen)37);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FOR LPR OR NB."), (ftnlen)15);
	    e_wsle();
/* SOURCE ntwmxstr.for:3118 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:3119 */
/*<       endif >*/
	}
/*       PUT THE RECORD IN THE BUFFER */
/* SOURCE ntwmxstr.for:3122 */
/*<        >*/
	if (FALSE_) {
	    feq_gen_io_d__188.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__188);
	    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)sizeof(integer));
	    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
	}
/* SOURCE ntwmxstr.for:3126 */
/*<        >*/
	putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &emcadr, &conid, &
		point, &nodein, &iput, &nin, &buff[1]);
/*       CREATE THE RECORD FOR THE LPR OR NB. */
/* SOURCE ntwmxstr.for:3134 */
/*<       emcadr=point >*/
	emcadr = point;
/* SOURCE ntwmxstr.for:3135 */
/*<       if(exnodt(5,nodein).gt.0)then >*/
	if (exnodt[nodein * 9 + 5] > 0) {
/* SOURCE ntwmxstr.for:3136 */
/*<       conid=junc >*/
	    conid = 2;
/* SOURCE ntwmxstr.for:3137 */
/*<       point=exnodt(5,nodein) >*/
	    point = exnodt[nodein * 9 + 5];
/*         MARK THE PATH FOR NODIN IN THE JUNCTION GIVEN BY POINT AS */
/*         INITIATED. */
/* SOURCE ntwmxstr.for:3140 */
/*<       callmkndin(nodein,1,point,ljoin,join,mkpath) >*/
	    mkndin_(&nodein, &feq_gen_c_d_1, &point, ljoin, &join[1], &mkpath);
/* SOURCE ntwmxstr.for:3144 */
/*<       if(mkpath.eq.0)then >*/
	    if (mkpath == 0) {
/* SOURCE ntwmxstr.for:3145 */
/*<        >*/
		feq_gen_io_d__190.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__190);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX FOR NODE IN="), (ftnlen)22);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PATH ALREADY INITIATED."), (ftnlen)24);
		e_wsle();
/* SOURCE ntwmxstr.for:3147 */
/*<       write(stdout,*)' JPT=',point >*/
		feq_gen_io_d__191.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__191);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" JPT="), (ftnlen)5);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(integer));
		e_wsle();
/* SOURCE ntwmxstr.for:3148 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:3149 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3150 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:3151 */
/*<       conid=bc >*/
	    conid = 3;
/* SOURCE ntwmxstr.for:3152 */
/*<       point=-exnodt(5,nodein) >*/
	    point = -exnodt[nodein * 9 + 5];
/* SOURCE ntwmxstr.for:3153 */
/*<       endif >*/
	}
/*       PUT THE RECORD IN THE BUFFER */
/* SOURCE ntwmxstr.for:3156 */
/*<        >*/
	if (FALSE_) {
	    feq_gen_io_d__192.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__192);
	    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)sizeof(integer));
	    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
	}
/* SOURCE ntwmxstr.for:3160 */
/*<        >*/
	putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &emcadr, &conid, &
		point, &nodein, &iput, &nin, &buff[1]);
/* SOURCE ntwmxstr.for:3166 */
/*<       else >*/
    } else {
/*       Boundary node is on an end of a branch. EXNODT(5,BNODE) points */
/*       to the boundary condition in EMC(). The branch number is */
/*       in EXNODT(3,BNODE).  We determine which end of the branch is */
/*       involved from BRPT(). */
/* SOURCE ntwmxstr.for:3172 */
/*<       bran=exnodt(3,bnode) >*/
	bran = exnodt[*bnode * 9 + 3];
/* SOURCE ntwmxstr.for:3173 */
/*<       uexn=brpt(5,bran) >*/
	uexn = brpt[(bran << 3) + 5];
/* SOURCE ntwmxstr.for:3174 */
/*<       dexn=brpt(6,bran) >*/
	dexn = brpt[(bran << 3) + 6];
/* SOURCE ntwmxstr.for:3176 */
/*<       if(exnodt(5,bnode).gt.0)then >*/
	if (exnodt[*bnode * 9 + 5] > 0) {
/* SOURCE ntwmxstr.for:3177 */
/*<       write(stdout,56)getusn(bnode) >*/
	    feq_gen_io_d__194.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__194);
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, bnode);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:3178 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:3179 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:3180 */
/*<       emcadr=-exnodt(5,bnode) >*/
	emcadr = -exnodt[*bnode * 9 + 5];
/* SOURCE ntwmxstr.for:3181 */
/*<       conid=branch >*/
	conid = 1;
/* SOURCE ntwmxstr.for:3182 */
/*<       if(bnode.eq.uexn)then >*/
	if (*bnode == uexn) {
/*         ENTRY NODE IS THE DOWNSTREAM NODE AND THE BRANCH */
/*         IS IN DEFAULT ORDER. */
/* SOURCE ntwmxstr.for:3185 */
/*<       point=bran >*/
	    point = bran;
/* SOURCE ntwmxstr.for:3186 */
/*<       nodein=dexn >*/
	    nodein = dexn;
/* SOURCE ntwmxstr.for:3187 */
/*<       else >*/
	} else {
/*         ENTRY NODE IS THE UPSTREAM NODE AND THE BRANCH IS */
/*         IN REVERSE ORDER */
/* SOURCE ntwmxstr.for:3190 */
/*<       point=-bran >*/
	    point = -bran;
/* SOURCE ntwmxstr.for:3191 */
/*<       nodein=uexn >*/
	    nodein = uexn;
/* SOURCE ntwmxstr.for:3192 */
/*<       endif >*/
	}
/*       PUT THE RECORD IN THE BUFFER */
/* SOURCE ntwmxstr.for:3195 */
/*<        >*/
	if (FALSE_) {
	    feq_gen_io_d__195.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__195);
	    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)sizeof(integer));
	    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
	}
/* SOURCE ntwmxstr.for:3199 */
/*<        >*/
	putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &emcadr, &conid, &
		point, &nodein, &iput, &nin, &buff[1]);
/*       CREATE THE RECORD FOR THE BRANCH AND TRANSFER TO THE */
/*       BUFFER */
/* SOURCE ntwmxstr.for:3208 */
/*<       emcadr=brpt(7,bran) >*/
	emcadr = brpt[(bran << 3) + 7];
/*       SELECT THE CONNECTING ITEM ID */
/* SOURCE ntwmxstr.for:3211 */
/*<       if(exnodt(5,nodein).gt.0)then >*/
	if (exnodt[nodein * 9 + 5] > 0) {
/* SOURCE ntwmxstr.for:3212 */
/*<       conid=junc >*/
	    conid = 2;
/* SOURCE ntwmxstr.for:3213 */
/*<       point=exnodt(5,nodein) >*/
	    point = exnodt[nodein * 9 + 5];
/*         NODEIN IS UNCHANGED. */
/*         MARK THE PATH FOR NODIN IN THE JUNCTION GIVEN BY POINT AS */
/*         INITIATED. */
/* SOURCE ntwmxstr.for:3217 */
/*<       callmkndin(nodein,1,point,ljoin,join,mkpath) >*/
	    mkndin_(&nodein, &feq_gen_c_d_1, &point, ljoin, &join[1], &mkpath);
/* SOURCE ntwmxstr.for:3221 */
/*<       if(mkpath.eq.0)then >*/
	    if (mkpath == 0) {
/* SOURCE ntwmxstr.for:3222 */
/*<        >*/
		feq_gen_io_d__196.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__196);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX FOR NODE IN="), (ftnlen)22);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PATH ALREADY INITIATED."), (ftnlen)24);
		e_wsle();
/* SOURCE ntwmxstr.for:3224 */
/*<       write(stdout,*)' JPT=',point >*/
		feq_gen_io_d__197.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__197);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" JPT="), (ftnlen)5);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(integer));
		e_wsle();
/* SOURCE ntwmxstr.for:3225 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:3226 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3227 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:3228 */
/*<       conid=bc >*/
	    conid = 3;
/* SOURCE ntwmxstr.for:3229 */
/*<       point=-exnodt(5,nodein) >*/
	    point = -exnodt[nodein * 9 + 5];
/*         NODEIN IS UNCHANGED. */
/* SOURCE ntwmxstr.for:3231 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:3232 */
/*<        >*/
	if (FALSE_) {
	    feq_gen_io_d__198.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__198);
	    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)sizeof(integer));
	    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
	}
/* SOURCE ntwmxstr.for:3236 */
/*<        >*/
	putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &emcadr, &conid, &
		point, &nodein, &iput, &nin, &buff[1]);
/* SOURCE ntwmxstr.for:3241 */
/*<       endif >*/
    }
/*     Now start reading the records in the buffer.  As we go */
/*     through the records in the buffer we take the following actions: */
/*     put EMCADR in the next entry in ADD, and process the CONID. */
/*     Processing CONID will add one or more records to the buffer */
/*     or in some cases will add an entry directly to ADD.  The */
/*     process is complete when there are no records remaining in the */
/*     pending buffer. */
/* SOURCE ntwmxstr.for:3251 */
/*<   100 continue >*/
L100:
/*       ARE WE DONE? */
/* SOURCE ntwmxstr.for:3253 */
/*<       if(nin.eq.0)then >*/
    if (nin == 0) {
/* SOURCE ntwmxstr.for:3254 */
/*<       if(ientry-1.ne.nentry)then >*/
	if (ientry - 1 != *nentry) {
/*           Wrong entry count.  Model may be disjoint. */
/* SOURCE ntwmxstr.for:3256 */
/*<       write(stdout,60)ientry-1,nentry >*/
	    feq_gen_io_d__199.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__199);
	    feq_gen_i_d_1 = ientry - 1;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&(*nentry), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:3257 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:3258 */
/*<       endif >*/
	}
/*         CHECK ON THE NUMBER OF EQUATIONS.  ONLY VALID FOR CURRENT CASE */
/*         OF 2 UNKNOWNS PER BRANCH NODE.  NEEDS CHANGE IF MORE GENERAL */
/*         BRANCH EQUATIONS ARE ADDED. */
/* SOURCE ntwmxstr.for:3263 */
/*<       nexp=2*(nbn+nex-2*nbra) >*/
	nexp = *nbn + *nex - (*nbra << 1) << 1;
/* SOURCE ntwmxstr.for:3264 */
/*<       if(nexp.ne.neq)then >*/
	if (nexp != *neq) {
/* SOURCE ntwmxstr.for:3265 */
/*<       write(stdout,2010)neq,nexp >*/
	    feq_gen_io_d__201.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__201);
	    do_fio(&feq_gen_c_d_1, (char *)&(*neq), (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nexp, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:3266 */
/*<       endif >*/
	}
/*          WRITE(STDOUT,*) ' NUMBER OF EQUATIONS=',NEQ */
/* SOURCE ntwmxstr.for:3269 */
/*<       return >*/
	return 0;
/* SOURCE ntwmxstr.for:3271 */
/*<       else >*/
    } else {
/*         GET NEXT RECORD FROM THE BUFFER. */
/* SOURCE ntwmxstr.for:3273 */
/*<        >*/
	getrec_(stdout, &begbuf, &endbuf, lbuff, &buff[1], &iget, &nin, &
		emcadr, &conid, &point, &nodein);
/* SOURCE ntwmxstr.for:3277 */
/*<        >*/
	if (FALSE_) {
	    feq_gen_io_d__202.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__202);
	    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)sizeof(integer));
	    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
	}
/*         ASSIGN VARIABLES TO THE EQUATIONS. */
/* SOURCE ntwmxstr.for:3282 */
/*<       if(emc(emcadr).eq.1)then >*/
	if (emc[emcadr] == 1) {
/*           BRANCH ADDED TO EMC.  GET THE BRANCH NUMBER AND */
/*           ASSIGN VARIABLES AND COUNT EQUATIONS. */
/* SOURCE ntwmxstr.for:3285 */
/*<       bran=emc(emcadr+1) >*/
	    bran = emc[emcadr + 1];
/* SOURCE ntwmxstr.for:3287 */
/*<       callbnvarn(bran,brpt,nbra,nex,ivar,neq,exnvar,brnvar,varid) >*/
	    bnvarn_(&bran, &brpt[9], nbra, nex, &ivar, neq, &exnvar[1], 
		    brnvar, &varid[1]);
/* SOURCE ntwmxstr.for:3292 */
/*<       elseif(emc(emcadr).eq.7)then >*/
	} else if (emc[emcadr] == 7) {
/*           LPR TO BE ADDED TO EMC. */
/* SOURCE ntwmxstr.for:3294 */
/*<       uexn=emc(emcadr+5) >*/
	    uexn = emc[emcadr + 5];
/* SOURCE ntwmxstr.for:3295 */
/*<       dexn=emc(emcadr+1) >*/
	    dexn = emc[emcadr + 1];
/* SOURCE ntwmxstr.for:3296 */
/*<       if(emc(emcadr+6).gt.0)then >*/
	    if (emc[emcadr + 6] > 0) {
/*             DEFAULT DIRECTION */
/* SOURCE ntwmxstr.for:3298 */
/*<       callfnvarn(uexn,exnodt,ivar,exnvar,varid) >*/
		fnvarn_(&uexn, &exnodt[10], &ivar, &exnvar[1], &varid[1]);
/* SOURCE ntwmxstr.for:3301 */
/*<       callfnvarn(dexn,exnodt,ivar,exnvar,varid) >*/
		fnvarn_(&dexn, &exnodt[10], &ivar, &exnvar[1], &varid[1]);
/* SOURCE ntwmxstr.for:3304 */
/*<       else >*/
	    } else {
/*             REVERSE DIRECTION */
/* SOURCE ntwmxstr.for:3306 */
/*<       callfnvarn(dexn,exnodt,ivar,exnvar,varid) >*/
		fnvarn_(&dexn, &exnodt[10], &ivar, &exnvar[1], &varid[1]);
/* SOURCE ntwmxstr.for:3309 */
/*<       callfnvarn(uexn,exnodt,ivar,exnvar,varid) >*/
		fnvarn_(&uexn, &exnodt[10], &ivar, &exnvar[1], &varid[1]);
/* SOURCE ntwmxstr.for:3312 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3314 */
/*<       neq=neq+2 >*/
	    *neq += 2;
/* SOURCE ntwmxstr.for:3315 */
/*<       elseif(emc(emcadr).eq.15)then >*/
	} else if (emc[emcadr] == 15) {
/*           NB TO BE ADDED TO EMC. */
/* SOURCE ntwmxstr.for:3317 */
/*<       uexn=emc(emcadr+1) >*/
	    uexn = emc[emcadr + 1];
/* SOURCE ntwmxstr.for:3318 */
/*<       dexn=emc(emcadr+2) >*/
	    dexn = emc[emcadr + 2];
/* SOURCE ntwmxstr.for:3319 */
/*<       if(emc(emcadr+3).gt.0)then >*/
	    if (emc[emcadr + 3] > 0) {
/*             DEFAULT DIRECTION */
/* SOURCE ntwmxstr.for:3321 */
/*<       callfnvarn(uexn,exnodt,ivar,exnvar,varid) >*/
		fnvarn_(&uexn, &exnodt[10], &ivar, &exnvar[1], &varid[1]);
/* SOURCE ntwmxstr.for:3324 */
/*<       callfnvarn(dexn,exnodt,ivar,exnvar,varid) >*/
		fnvarn_(&dexn, &exnodt[10], &ivar, &exnvar[1], &varid[1]);
/* SOURCE ntwmxstr.for:3327 */
/*<       else >*/
	    } else {
/*             REVERSE DIRECTION */
/* SOURCE ntwmxstr.for:3329 */
/*<       callfnvarn(dexn,exnodt,ivar,exnvar,varid) >*/
		fnvarn_(&dexn, &exnodt[10], &ivar, &exnvar[1], &varid[1]);
/* SOURCE ntwmxstr.for:3332 */
/*<       callfnvarn(uexn,exnodt,ivar,exnvar,varid) >*/
		fnvarn_(&uexn, &exnodt[10], &ivar, &exnvar[1], &varid[1]);
/* SOURCE ntwmxstr.for:3335 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3337 */
/*<       neq=neq+2 >*/
	    *neq += 2;
/* SOURCE ntwmxstr.for:3338 */
/*<       else >*/
	} else {
/*           COUNT THE EQUATION. NO NODES TO NUMBER. */
/* SOURCE ntwmxstr.for:3340 */
/*<       neq=neq+1 >*/
	    ++(*neq);
/* SOURCE ntwmxstr.for:3341 */
/*<       endif >*/
	}
/*         TRANSFER THE VALUE TO EMC() */
/* SOURCE ntwmxstr.for:3345 */
/*<       if(out.eq.1.or.bdyflg.eq.0)then >*/
	if (*bdyflg == 0) {
/* SOURCE ntwmxstr.for:3346 */
/*<       chr63=fndemc(emcadr,lemc,emc) >*/
	    fndemc_(feq_gen_ch_d_5, (ftnlen)63, &emcadr, lemc, &emc[1]);
	    s_copy(chr63, feq_gen_ch_d_5, (ftnlen)63, (ftnlen)63);
/* SOURCE ntwmxstr.for:3347 */
/*<       if(varid(neq).gt.0)then >*/
	    if (varid[*neq] > 0) {
/* SOURCE ntwmxstr.for:3348 */
/*<       if(mod(neq,2).eq.0)then >*/
		if (*neq % 2 == 0) {
/*               This is depth */
/* SOURCE ntwmxstr.for:3350 */
/*<       varname=getusn(varid(neq))//'Y' >*/
/* Writing concatenation */
		    getusn_(feq_gen_ch_d_1, (ftnlen)5, &varid[*neq]);
		    feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
		    feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("Y");
		    s_cat(varname, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE ntwmxstr.for:3351 */
/*<       else >*/
		} else {
/* SOURCE ntwmxstr.for:3352 */
/*<       varname=getusn(varid(neq))//'Q' >*/
/* Writing concatenation */
		    getusn_(feq_gen_ch_d_1, (ftnlen)5, &varid[*neq]);
		    feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
		    feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("Q");
		    s_cat(varname, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE ntwmxstr.for:3353 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:3354 */
/*<       else >*/
	    } else {
/* SOURCE ntwmxstr.for:3355 */
/*<       varname=' ' >*/
		s_copy(varname, const_cast<char*>(" "), (ftnlen)6, (ftnlen)1);
/* SOURCE ntwmxstr.for:3356 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3357 */
/*<       write(stdout,54)neq,varname,emc(emcadr-1),chr63 >*/
	    feq_gen_io_d__205.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__205);
	    do_fio(&feq_gen_c_d_1, (char *)&(*neq), (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, varname, (ftnlen)6);
	    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr - 1], (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, chr63, (ftnlen)63);
	    e_wsfe();
/* SOURCE ntwmxstr.for:3358 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:3360 */
/*<       add(ientry)=emcadr >*/
	add[ientry] = emcadr;
/* SOURCE ntwmxstr.for:3361 */
/*<       ientry=ientry+1 >*/
	++ientry;
/*         PROCESS THE CONNECTING ITEM. CONNECTING ITEMS LPR AND */
/*         NB DO NOTHING.  SIGN CHANGE ALREADY MADE IN EMC WHEN */
/*         RECORD WAS WRITTEN. */
/* SOURCE ntwmxstr.for:3367 */
/*<       if(conid.eq.branch)then >*/
	if (conid == 1) {
/*           POINT GIVES THE BRANCH NUMBER AND ITS SIGN GIVES THE */
/*           SIGN THE BRANCH NUMBER IN EMC MUST HAVE.  CHANGE SIGN IN */
/*           EMC. */
/* SOURCE ntwmxstr.for:3371 */
/*<       if(point.lt.0)then >*/
	    if (point < 0) {
/*             BRANCH IN REVERSE.  MAKE SIGN NEGATIVE IN EMC. */
/* SOURCE ntwmxstr.for:3373 */
/*<       point=brpt(7,-point) >*/
		point = brpt[(-point << 3) + 7];
/* SOURCE ntwmxstr.for:3374 */
/*<       emc(point+1)=-abs(emc(point+1)) >*/
		emc[point + 1] = -(feq_gen_i_d_1 = emc[point + 1], abs(feq_gen_i_d_1));
/* SOURCE ntwmxstr.for:3375 */
/*<       else >*/
	    } else {
/*             MAKE BRANCH POSITIVE-COULD BE NEGATIVE FROM A PREVIOUS */
/*             SCAN. */
/* SOURCE ntwmxstr.for:3378 */
/*<       point=brpt(7,point) >*/
		point = brpt[(point << 3) + 7];
/* SOURCE ntwmxstr.for:3379 */
/*<       emc(point+1)=abs(emc(point+1)) >*/
		emc[point + 1] = (feq_gen_i_d_1 = emc[point + 1], abs(feq_gen_i_d_1));
/* SOURCE ntwmxstr.for:3380 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3381 */
/*<       elseif(conid.eq.bc)then >*/
	} else if (conid == 3) {
/*           THE BOUNDARY CONDITION MUST BE TRANSFERED TO EMC NOW */
/*           TO PROPERLY TERMINATE THE PREVIOUS ENTRY. */
/*           COUNT THE EQUATION */
/* SOURCE ntwmxstr.for:3387 */
/*<       neq=neq+1 >*/
	    ++(*neq);
/* SOURCE ntwmxstr.for:3389 */
/*<       if(out.eq.1.or.bdyflg.eq.0)then >*/
	    if (*bdyflg == 0) {
/* SOURCE ntwmxstr.for:3390 */
/*<       chr63=fndemc(point,lemc,emc) >*/
		fndemc_(feq_gen_ch_d_5, (ftnlen)63, &point, lemc, &emc[1]);
		s_copy(chr63, feq_gen_ch_d_5, (ftnlen)63, (ftnlen)63);
/* SOURCE ntwmxstr.for:3391 */
/*<       if(varid(neq).gt.0)then >*/
		if (varid[*neq] > 0) {
/* SOURCE ntwmxstr.for:3392 */
/*<       if(mod(neq,2).eq.0)then >*/
		    if (*neq % 2 == 0) {
/*               This is depth */
/* SOURCE ntwmxstr.for:3394 */
/*<       varname=getusn(varid(neq))//'Y' >*/
/* Writing concatenation */
			getusn_(feq_gen_ch_d_1, (ftnlen)5, &varid[*neq]);
			feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
			feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("Y");
			s_cat(varname, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE ntwmxstr.for:3395 */
/*<       else >*/
		    } else {
/* SOURCE ntwmxstr.for:3396 */
/*<       varname=getusn(varid(neq))//'Q' >*/
/* Writing concatenation */
			getusn_(feq_gen_ch_d_1, (ftnlen)5, &varid[*neq]);
			feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
			feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("Q");
			s_cat(varname, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE ntwmxstr.for:3397 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:3398 */
/*<       else >*/
		} else {
/* SOURCE ntwmxstr.for:3399 */
/*<       varname=' ' >*/
		    s_copy(varname, const_cast<char*>(" "), (ftnlen)6, (ftnlen)1);
/* SOURCE ntwmxstr.for:3400 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:3401 */
/*<       write(stdout,54)neq,varname,emc(point-1),chr63 >*/
		feq_gen_io_d__206.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__206);
		do_fio(&feq_gen_c_d_1, (char *)&(*neq), (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, varname, (ftnlen)6);
		do_fio(&feq_gen_c_d_1, (char *)&emc[point - 1], (ftnlen)sizeof(integer)
			);
		do_fio(&feq_gen_c_d_1, chr63, (ftnlen)63);
		e_wsfe();
/* SOURCE ntwmxstr.for:3402 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3404 */
/*<       add(ientry)=point >*/
	    add[ientry] = point;
/* SOURCE ntwmxstr.for:3405 */
/*<       ientry=ientry+1 >*/
	    ++ientry;
/* SOURCE ntwmxstr.for:3407 */
/*<       elseif(conid.eq.junc)then >*/
	} else if (conid == 2) {
/*           PROCESS A JUNCTION.  USE JPT AS THE JUNCTION ADDRESS. */
/* SOURCE ntwmxstr.for:3410 */
/*<       jpt=point >*/
	    jpt = point;
/*           WRITE THE TERMINATING CONDITION FOR NODEIN IN EMC(). */
/*           SEEK CODE 8 FIRST.  IF FOUND MUST BE USED. */
/*            EMCADR = FIND8(JPT, NODEIN, NODE2, LJOIN, JOIN, LEMC, EMC) */
/* SOURCE ntwmxstr.for:3417 */
/*<       callfind8(jpt,nodein,ljoin,lemc,emc,join,node2,emcadr) >*/
	    find8_(&jpt, &nodein, ljoin, lemc, &emc[1], &join[1], &node2, &
		    emcadr);
/* SOURCE ntwmxstr.for:3422 */
/*<       if(emcadr.eq.0)then >*/
	    if (emcadr == 0) {
/*             CODE 8 NOT PRESENT-TRY FOR A CODE 4 NEXT. */
/*             EMCADR = FIND4(JPT, NODEIN, NODE2, LJOIN, JOIN, LEMC, EMC) */
/* SOURCE ntwmxstr.for:3427 */
/*<       callfind4(jpt,nodein,ljoin,lemc,emc,join,node2,emcadr) >*/
		find4_(&jpt, &nodein, ljoin, lemc, &emc[1], &join[1], &node2, 
			&emcadr);
/* SOURCE ntwmxstr.for:3431 */
/*<       if(emcadr.eq.0)then >*/
		if (emcadr == 0) {
/*               CODE 4 NOT FOUND. TRY FOR CODE 5 OR 14 WITH FLOW NODE */
/*               AT NODEIN */
/* SOURCE ntwmxstr.for:3436 */
/*<       callfnd514(jpt,nodein,ljoin,lemc,emc,join,node2,emcadr) >*/
		    fnd514_(&jpt, &nodein, ljoin, lemc, &emc[1], &join[1], &
			    node2, &emcadr);
/* SOURCE ntwmxstr.for:3440 */
/*<       if(emcadr.eq.0)then >*/
		    if (emcadr == 0) {
/*                 NO CODE 5 WITH FLOW NODE AT NODEIN FOUND.  TRY FOR */
/*                 ANY ELEVATION RELATIONSHIP */
/*                  EMCADR = FNDANY(JPT, NODEIN, NODE2, LJOIN, JOIN, LEMC, */
/*     A                            EMC) */
/* SOURCE ntwmxstr.for:3447 */
/*<       callfndany(jpt,nodein,ljoin,lemc,emc,join,node2,emcadr) >*/
			fndany_(&jpt, &nodein, ljoin, lemc, &emc[1], &join[1],
				 &node2, &emcadr);
/* SOURCE ntwmxstr.for:3451 */
/*<       if(emcadr.eq.0)then >*/
			if (emcadr == 0) {
/*                   NO ELEVATION RELATIONSHIPS AVAILABLE FOR THIS */
/*                   NODE.  THE JUNCTION RELATIONSHIP SHOULD BE */
/*                   AVAILABLE. */
/* SOURCE ntwmxstr.for:3455 */
/*<       emcadr=join(jpt+1) >*/
			    emcadr = join[jpt + 1];
/* SOURCE ntwmxstr.for:3456 */
/*<       node2=0 >*/
			    node2 = 0;
/* SOURCE ntwmxstr.for:3457 */
/*<       if(emcadr.lt.0)then >*/
			    if (emcadr < 0) {
/* SOURCE ntwmxstr.for:3458 */
/*<        >*/
				feq_gen_io_d__209.ciunit = *stdout;
				s_wsle(&feq_gen_io_d__209);
				do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NO AVAILABLE TERMINAT\
ING "), (ftnlen)26);
				do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("CONDITON AT JUNCTION J\
PT="), (ftnlen)25);
				do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&jpt, (ftnlen)
					sizeof(integer));
				do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FOR NODEIN="), (ftnlen)
					12);
				getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
				s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
				do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
				e_wsle();
/* SOURCE ntwmxstr.for:3461 */
/*<       stop'Abnormal stop: errors found.' >*/
				s_stop(const_cast<char*>("Abnormal stop: errors found."), (
					ftnlen)28);
/* SOURCE ntwmxstr.for:3462 */
/*<       else >*/
			    } else {
/*                     JUNCTION RELATIONSHIP IS AVAILABLE. MARK AS USED. */
/* SOURCE ntwmxstr.for:3464 */
/*<       join(jpt+1)=-join(jpt+1) >*/
				join[jpt + 1] = -join[jpt + 1];
/* SOURCE ntwmxstr.for:3465 */
/*<       endif >*/
			    }
/* SOURCE ntwmxstr.for:3466 */
/*<       endif >*/
			}
/* SOURCE ntwmxstr.for:3467 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:3468 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:3469 */
/*<       endif >*/
	    }
/*           WE HAVE A TERMINATING CONDITION.  TRANSFER TO EMC */
/*           COUNT THE EQUATION. */
/* SOURCE ntwmxstr.for:3475 */
/*<       neq=neq+1 >*/
	    ++(*neq);
/* SOURCE ntwmxstr.for:3477 */
/*<       if(out.eq.1)then >*/
	    if (FALSE_) {
/* SOURCE ntwmxstr.for:3478 */
/*<       write(stdout,*)' TERMINATING AT NODE=',getusn(nodein),' WITH:' >*/
		feq_gen_io_d__210.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__210);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TERMINATING AT NODE="), (ftnlen)21);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" WITH:"), (ftnlen)6);
		e_wsle();
/* SOURCE ntwmxstr.for:3480 */
/*<       chr63=fndemc(emcadr,lemc,emc) >*/
		fndemc_(feq_gen_ch_d_5, (ftnlen)63, &emcadr, lemc, &emc[1]);
		s_copy(chr63, feq_gen_ch_d_5, (ftnlen)63, (ftnlen)63);
/* SOURCE ntwmxstr.for:3481 */
/*<       if(varid(neq).gt.0)then >*/
		if (varid[*neq] > 0) {
/* SOURCE ntwmxstr.for:3482 */
/*<       if(mod(neq,2).eq.0)then >*/
		    if (*neq % 2 == 0) {
/*                 This is depth */
/* SOURCE ntwmxstr.for:3484 */
/*<       varname=getusn(varid(neq))//'Y' >*/
/* Writing concatenation */
			getusn_(feq_gen_ch_d_1, (ftnlen)5, &varid[*neq]);
			feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
			feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("Y");
			s_cat(varname, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE ntwmxstr.for:3485 */
/*<       else >*/
		    } else {
/* SOURCE ntwmxstr.for:3486 */
/*<       varname=getusn(varid(neq))//'Q' >*/
/* Writing concatenation */
			getusn_(feq_gen_ch_d_1, (ftnlen)5, &varid[*neq]);
			feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
			feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("Q");
			s_cat(varname, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE ntwmxstr.for:3487 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:3488 */
/*<       else >*/
		} else {
/* SOURCE ntwmxstr.for:3489 */
/*<       varname=' ' >*/
		    s_copy(varname, const_cast<char*>(" "), (ftnlen)6, (ftnlen)1);
/* SOURCE ntwmxstr.for:3490 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:3491 */
/*<       write(stdout,55)neq,varname,ientry,emcadr,chr63 >*/
		feq_gen_io_d__211.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__211);
		do_fio(&feq_gen_c_d_1, (char *)&(*neq), (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, varname, (ftnlen)6);
		do_fio(&feq_gen_c_d_1, (char *)&ientry, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, chr63, (ftnlen)63);
		e_wsfe();
/* SOURCE ntwmxstr.for:3492 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3493 */
/*<       if(bdyflg.eq.0)then >*/
	    if (*bdyflg == 0) {
/* SOURCE ntwmxstr.for:3494 */
/*<       chr63=fndemc(emcadr,lemc,emc) >*/
		fndemc_(feq_gen_ch_d_5, (ftnlen)63, &emcadr, lemc, &emc[1]);
		s_copy(chr63, feq_gen_ch_d_5, (ftnlen)63, (ftnlen)63);
/* SOURCE ntwmxstr.for:3495 */
/*<       if(varid(neq).gt.0)then >*/
		if (varid[*neq] > 0) {
/* SOURCE ntwmxstr.for:3496 */
/*<       if(mod(neq,2).eq.0)then >*/
		    if (*neq % 2 == 0) {
/*                 This is depth */
/* SOURCE ntwmxstr.for:3498 */
/*<       varname=getusn(varid(neq))//'Y' >*/
/* Writing concatenation */
			getusn_(feq_gen_ch_d_1, (ftnlen)5, &varid[*neq]);
			feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
			feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("Y");
			s_cat(varname, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE ntwmxstr.for:3499 */
/*<       else >*/
		    } else {
/* SOURCE ntwmxstr.for:3500 */
/*<       varname=getusn(varid(neq))//'Q' >*/
/* Writing concatenation */
			getusn_(feq_gen_ch_d_1, (ftnlen)5, &varid[*neq]);
			feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
			feq_gen_i_d_2[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("Q");
			s_cat(varname, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE ntwmxstr.for:3501 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:3502 */
/*<       else >*/
		} else {
/* SOURCE ntwmxstr.for:3503 */
/*<       varname=' ' >*/
		    s_copy(varname, const_cast<char*>(" "), (ftnlen)6, (ftnlen)1);
/* SOURCE ntwmxstr.for:3504 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:3505 */
/*<       write(stdout,54)neq,varname,emc(emcadr-1),chr63 >*/
		feq_gen_io_d__212.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__212);
		do_fio(&feq_gen_c_d_1, (char *)&(*neq), (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, varname, (ftnlen)6);
		do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr - 1], (ftnlen)sizeof(
			integer));
		do_fio(&feq_gen_c_d_1, chr63, (ftnlen)63);
		e_wsfe();
/* SOURCE ntwmxstr.for:3506 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3508 */
/*<       add(ientry)=emcadr >*/
	    add[ientry] = emcadr;
/* SOURCE ntwmxstr.for:3509 */
/*<       ientry=ientry+1 >*/
	    ++ientry;
/*           MARK THE PATH AS COMPLETED */
/*            IT = MKNDIN(NODEIN, 2, JPT, LJOIN, JOIN) */
/* SOURCE ntwmxstr.for:3513 */
/*<       callmkndin(nodein,2,jpt,ljoin,join,it) >*/
	    mkndin_(&nodein, &feq_gen_c_d_2, &jpt, ljoin, &join[1], &it);
/*           NOW INITIATE THE NODES AT THIS JUNCTION WHICH ARE NOT */
/*           YET INITIATED. */
/* SOURCE ntwmxstr.for:3521 */
/*<   500 continue >*/
L500:
/* SOURCE ntwmxstr.for:3522 */
/*<        >*/
	    if (FALSE_) {
		feq_gen_io_d__214.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__214);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODE2="), (ftnlen)7);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&node2, (ftnlen)sizeof(integer));
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &node2);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FROM PREVIOUS RELATIONSHIP"), (ftnlen)
			27);
		e_wsle();
	    }
/* SOURCE ntwmxstr.for:3525 */
/*<       if(node2.ne.0)then >*/
	    if (node2 != 0) {
/*               Is NODE2 initiated? */
/* SOURCE ntwmxstr.for:3527 */
/*<       if(isndin(node2,jpt,ljoin,join).ne.1)goto505 >*/
		if (isndin_(&node2, &jpt, ljoin, &join[1]) != 1) {
		    goto L505;
		}
/* SOURCE ntwmxstr.for:3528 */
/*<       endif >*/
	    }
/*             Yes- Seek another node in the junction. */
/*             NO UNINITIATED NODE GIVEN BY PREVIOUS RELATIONSHIP */
/* SOURCE ntwmxstr.for:3531 */
/*<       node2=fndnxt(jpt,ljoin,join,lemc,emc) >*/
	    node2 = fndnxt_(&jpt, ljoin, &join[1], lemc, &emc[1]);
/* SOURCE ntwmxstr.for:3532 */
/*<        >*/
	    if (FALSE_) {
		feq_gen_io_d__215.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__215);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODE2="), (ftnlen)7);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&node2, (ftnlen)sizeof(integer));
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &node2);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FROM FNDNXT"), (ftnlen)12);
		e_wsle();
	    }
/* SOURCE ntwmxstr.for:3535 */
/*<   505 continue >*/
L505:
/* SOURCE ntwmxstr.for:3537 */
/*<       if(node2.eq.0)then >*/
	    if (node2 == 0) {
/*               No other uninitiated nodes found. */
/* SOURCE ntwmxstr.for:3539 */
/*<       goto600 >*/
		goto L600;
/* SOURCE ntwmxstr.for:3540 */
/*<       else >*/
	    } else {
/*               We now have a node at the junction that represents */
/*               an uninitiated path out of the junction.  Call it */
/*               NODOUT because NODE2 is redefined in the loop. */
/* SOURCE ntwmxstr.for:3545 */
/*<       nodout=node2 >*/
		nodout = node2;
/*               MARK THE PATH FOR THIS NODE AS INITIATED AND COMPLETED */
/*               IN THE CURRENT JUNCTION.  INITIATE FIRST TO FIND */
/*               BUGS. */
/*                IF(MKNDIN(NODOUT, 1, JPT, LJOIN, JOIN).EQ.0) THEN */
/* SOURCE ntwmxstr.for:3553 */
/*<       callmkndin(nodout,1,jpt,ljoin,join,mkpath) >*/
		mkndin_(&nodout, &feq_gen_c_d_1, &jpt, ljoin, &join[1], &mkpath);
/* SOURCE ntwmxstr.for:3557 */
/*<       if(mkpath.eq.0)then >*/
		if (mkpath == 0) {
/* SOURCE ntwmxstr.for:3558 */
/*<        >*/
		    feq_gen_io_d__217.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__217);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX FOR NODE OUT="), (ftnlen)
			    23);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodout);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PATH ALREADY INITIATED."), (ftnlen)
			    24);
		    e_wsle();
/* SOURCE ntwmxstr.for:3560 */
/*<       write(stdout,*)' JPT=',jpt >*/
		    feq_gen_io_d__218.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__218);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" JPT="), (ftnlen)5);
		    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&jpt, (ftnlen)sizeof(integer)
			    );
		    e_wsle();
/* SOURCE ntwmxstr.for:3561 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:3562 */
/*<       endif >*/
		}
/*               NOW MARK AS COMPLETED */
/*                IT = MKNDIN(NODOUT, 2, JPT, LJOIN, JOIN) */
/* SOURCE ntwmxstr.for:3566 */
/*<       callmkndin(nodout,2,jpt,ljoin,join,it) >*/
		mkndin_(&nodout, &feq_gen_c_d_2, &jpt, ljoin, &join[1], &it);
/*               SELECT THE INITIATING RELATIONSHIP FOR THIS PATH. */
/*               SEEK CODE 8 FIRST */
/*                EMCADR = FIND8(JPT, NODOUT, NODE2, LJOIN, JOIN, LEMC, */
/* SOURCE ntwmxstr.for:3574 */
/*<       callfind8(jpt,nodout,ljoin,lemc,emc,join,node2,emcadr) >*/
		find8_(&jpt, &nodout, ljoin, lemc, &emc[1], &join[1], &node2, 
			&emcadr);
/* SOURCE ntwmxstr.for:3578 */
/*<       if(emcadr.eq.0)then >*/
		if (emcadr == 0) {
/*                 NO CODE 8. TRY CODE 4. */
/*                  EMCADR = FIND4(JPT, NODOUT, NODE2, LJOIN, JOIN, */
/*     A                           LEMC, EMC) */
/* SOURCE ntwmxstr.for:3582 */
/*<       callfind4(jpt,nodout,ljoin,lemc,emc,join,node2,emcadr) >*/
		    find4_(&jpt, &nodout, ljoin, lemc, &emc[1], &join[1], &
			    node2, &emcadr);
/* SOURCE ntwmxstr.for:3586 */
/*<       if(emcadr.eq.0)then >*/
		    if (emcadr == 0) {
/*                   NO CODE 4. TRY CODE 5 AND 14. */
/* SOURCE ntwmxstr.for:3588 */
/*<       callfnd514(jpt,nodout,ljoin,lemc,emc,join,node2,emcadr) >*/
			fnd514_(&jpt, &nodout, ljoin, lemc, &emc[1], &join[1],
				 &node2, &emcadr);
/* SOURCE ntwmxstr.for:3592 */
/*<       if(emcadr.eq.0)then >*/
			if (emcadr == 0) {
/*                     NO CODE 5. TRY THE JUNCTION CONDITION. */
/* SOURCE ntwmxstr.for:3594 */
/*<       emcadr=join(jpt+1) >*/
			    emcadr = join[jpt + 1];
/* SOURCE ntwmxstr.for:3597 */
/*<       if(emcadr.lt.0)then >*/
			    if (emcadr < 0) {
/*                       JUNCTION ALREADY USED. TRY FOR ANY. */
/* SOURCE ntwmxstr.for:3599 */
/*<       callfndany(jpt,nodout,ljoin,lemc,emc,join,node2,emcadr) >*/
				fndany_(&jpt, &nodout, ljoin, lemc, &emc[1], &
					join[1], &node2, &emcadr);
/* SOURCE ntwmxstr.for:3603 */
/*<       if(emcadr.eq.0)then >*/
				if (emcadr == 0) {
/* SOURCE ntwmxstr.for:3604 */
/*<        >*/
				    feq_gen_io_d__219.ciunit = *stdout;
				    s_wsle(&feq_gen_io_d__219);
				    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* NO AVAI\
LABLE"), (ftnlen)23);
				    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" RELATIONSHIP FOR \
INITIATING AT JPT="), (ftnlen)36);
				    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&jpt, (
					    ftnlen)sizeof(integer));
				    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODE OUT="), (
					    ftnlen)10);
				    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodout);
				    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5)
					    ;
				    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
				    e_wsle();
/* SOURCE ntwmxstr.for:3607 */
/*<       stop'Abnormal stop: errors found.' >*/
				    s_stop(const_cast<char*>("Abnormal stop: errors found."), (
					    ftnlen)28);
/* SOURCE ntwmxstr.for:3608 */
/*<       endif >*/
				}
/* SOURCE ntwmxstr.for:3609 */
/*<       else >*/
			    } else {
/*                       JUNCTION AVAILABLE. MARK AS USED */
/* SOURCE ntwmxstr.for:3611 */
/*<       join(jpt+1)=-join(jpt+1) >*/
				join[jpt + 1] = -join[jpt + 1];
/* SOURCE ntwmxstr.for:3612 */
/*<       endif >*/
			    }
/* SOURCE ntwmxstr.for:3613 */
/*<       endif >*/
			}
/* SOURCE ntwmxstr.for:3614 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:3615 */
/*<       endif >*/
		}
/*               We have the pointer to the initiating condition in hand. */
/*               Now find the address and nature of the connecting item. */
/*               NODOUT is the node.  It is in the initiating condition. */
/* SOURCE ntwmxstr.for:3621 */
/*<       if(exnodt(3,nodout).le.0)then >*/
		if (exnodt[nodout * 9 + 3] <= 0) {
/*                 NODOUT IS A FREE NODE.  IT IS ON EITHER A NULL BRANCH */
/*                 OR A LEVEL POOL RESERVOIR. */
/* SOURCE ntwmxstr.for:3625 */
/*<       if(exnodt(5,nodout).lt.0)then >*/
		    if (exnodt[nodout * 9 + 5] < 0) {
/*                   BOUNDARY CONDITION AT THE NODE.  INVALID! */
/* SOURCE ntwmxstr.for:3627 */
/*<        >*/
			feq_gen_io_d__220.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__220);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* BC INVALID AT FREE \
ND"), (ftnlen)32);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("NODOUT="), (ftnlen)7);
			getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodout);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" AT JUNCTION="), (ftnlen)13);
			do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&jpt, (ftnlen)sizeof(
				integer));
			e_wsle();
/* SOURCE ntwmxstr.for:3629 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:3630 */
/*<       else >*/
		    } else {
/* SOURCE ntwmxstr.for:3632 */
/*<       point=abs(exnodt(2,nodout)) >*/
			point = (feq_gen_i_d_1 = exnodt[nodout * 9 + 2], abs(feq_gen_i_d_1));
/* SOURCE ntwmxstr.for:3633 */
/*<       code=emc(point) >*/
			code = emc[point];
/* SOURCE ntwmxstr.for:3634 */
/*<       if(code.eq.7)then >*/
			if (code == 7) {
/*                     ATTACHED TO A LPR. GET THE UPSTREAM AND DOWNSTREAM */
/*                     NODES AND SET THE DIRECTION IN EMC ACCORDINGLY. */
/*                     ALSO SET CONID AND THE NODE AT THE END OF THE LPR */
/*                     OPPOSITE FROM BNODE. */
/* SOURCE ntwmxstr.for:3640 */
/*<       uexn=emc(point+5) >*/
			    uexn = emc[point + 5];
/* SOURCE ntwmxstr.for:3641 */
/*<       dexn=emc(point+1) >*/
			    dexn = emc[point + 1];
/* SOURCE ntwmxstr.for:3642 */
/*<       if(nodout.eq.uexn)then >*/
			    if (nodout == uexn) {
/* SOURCE ntwmxstr.for:3643 */
/*<       nodein=dexn >*/
				nodein = dexn;
/* SOURCE ntwmxstr.for:3644 */
/*<       emc(point+6)=1 >*/
				emc[point + 6] = 1;
/* SOURCE ntwmxstr.for:3645 */
/*<       else >*/
			    } else {
/* SOURCE ntwmxstr.for:3646 */
/*<       nodein=uexn >*/
				nodein = uexn;
/* SOURCE ntwmxstr.for:3647 */
/*<       emc(point+6)=-1 >*/
				emc[point + 6] = -1;
/* SOURCE ntwmxstr.for:3648 */
/*<       endif >*/
			    }
/* SOURCE ntwmxstr.for:3650 */
/*<       conid=lpr >*/
			    conid = 5;
/* SOURCE ntwmxstr.for:3651 */
/*<       elseif(code.eq.15)then >*/
			} else if (code == 15) {
/*                     ATTACHED TO A NB.  DO THE SAME AS FOR LPR */
/* SOURCE ntwmxstr.for:3654 */
/*<       uexn=emc(point+1) >*/
			    uexn = emc[point + 1];
/* SOURCE ntwmxstr.for:3655 */
/*<       dexn=emc(point+2) >*/
			    dexn = emc[point + 2];
/* SOURCE ntwmxstr.for:3656 */
/*<       if(nodout.eq.uexn)then >*/
			    if (nodout == uexn) {
/* SOURCE ntwmxstr.for:3657 */
/*<       nodein=dexn >*/
				nodein = dexn;
/* SOURCE ntwmxstr.for:3658 */
/*<       emc(point+3)=1 >*/
				emc[point + 3] = 1;
/* SOURCE ntwmxstr.for:3659 */
/*<       else >*/
			    } else {
/* SOURCE ntwmxstr.for:3660 */
/*<       nodein=uexn >*/
				nodein = uexn;
/* SOURCE ntwmxstr.for:3661 */
/*<       emc(point+3)=-1 >*/
				emc[point + 3] = -1;
/* SOURCE ntwmxstr.for:3662 */
/*<       endif >*/
			    }
/* SOURCE ntwmxstr.for:3664 */
/*<       conid=nb >*/
			    conid = 4;
/* SOURCE ntwmxstr.for:3665 */
/*<       else >*/
			} else {
/* SOURCE ntwmxstr.for:3666 */
/*<        >*/
			    feq_gen_io_d__221.ciunit = *stdout;
			    s_wsle(&feq_gen_io_d__221);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* INVALID CODE."), (
				    ftnlen)24);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NODOUT="), (ftnlen)8);
			    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodout);
			    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN JPT="), (ftnlen)8);
			    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&jpt, (ftnlen)sizeof(
				    integer));
			    e_wsle();
/* SOURCE ntwmxstr.for:3669 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE ntwmxstr.for:3670 */
/*<       endif >*/
			}
/*                   PUT THE RECORD IN THE BUFFER */
/* SOURCE ntwmxstr.for:3673 */
/*<        >*/
			if (FALSE_) {
			    feq_gen_io_d__222.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__222);
			    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)
				    sizeof(integer));
			    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
			    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
			    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(
				    integer));
			    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
			    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			    e_wsfe();
			}
/* SOURCE ntwmxstr.for:3677 */
/*<        >*/
			putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &
				emcadr, &conid, &point, &nodein, &iput, &nin, 
				&buff[1]);
/*                   CREATE THE RECORD FOR THE LPR OR NB. */
/* SOURCE ntwmxstr.for:3685 */
/*<       emcadr=point >*/
			emcadr = point;
/* SOURCE ntwmxstr.for:3686 */
/*<       if(exnodt(5,nodein).gt.0)then >*/
			if (exnodt[nodein * 9 + 5] > 0) {
/* SOURCE ntwmxstr.for:3687 */
/*<       conid=junc >*/
			    conid = 2;
/* SOURCE ntwmxstr.for:3688 */
/*<       point=exnodt(5,nodein) >*/
			    point = exnodt[nodein * 9 + 5];
/*                     MARK THE PATH FOR NODIN IN THE JUNCTION GIVEN */
/*                     BY POINT AS INITIATED. */
/*                      IF(MKNDIN(NODEIN, 1, POINT, LJOIN, JOIN).EQ.0) */
/* SOURCE ntwmxstr.for:3692 */
/*<       callmkndin(nodein,1,point,ljoin,join,mkpath) >*/
			    mkndin_(&nodein, &feq_gen_c_d_1, &point, ljoin, &join[1], &
				    mkpath);
/* SOURCE ntwmxstr.for:3696 */
/*<       if(mkpath.eq.0)then >*/
			    if (mkpath == 0) {
/* SOURCE ntwmxstr.for:3697 */
/*<        >*/
				feq_gen_io_d__223.ciunit = *stdout;
				s_wsle(&feq_gen_io_d__223);
				do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX FOR NODE IN="),
					 (ftnlen)22);
				getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
				s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
				do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
				do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PATH ALREADY INITIATE\
D."), (ftnlen)24);
				e_wsle();
/* SOURCE ntwmxstr.for:3699 */
/*<       write(stdout,*)' JPT=',point >*/
				feq_gen_io_d__224.ciunit = *stdout;
				s_wsle(&feq_gen_io_d__224);
				do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" JPT="), (ftnlen)5);
				do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&point, (ftnlen)
					sizeof(integer));
				e_wsle();
/* SOURCE ntwmxstr.for:3700 */
/*<       stop'Abnormal stop: errors found.' >*/
				s_stop(const_cast<char*>("Abnormal stop: errors found."), (
					ftnlen)28);
/* SOURCE ntwmxstr.for:3701 */
/*<       endif >*/
			    }
/* SOURCE ntwmxstr.for:3702 */
/*<       else >*/
			} else {
/* SOURCE ntwmxstr.for:3703 */
/*<       conid=bc >*/
			    conid = 3;
/* SOURCE ntwmxstr.for:3704 */
/*<       point=-exnodt(5,nodein) >*/
			    point = -exnodt[nodein * 9 + 5];
/* SOURCE ntwmxstr.for:3705 */
/*<       endif >*/
			}
/*                   PUT THE RECORD IN THE BUFFER */
/* SOURCE ntwmxstr.for:3707 */
/*<        >*/
			if (FALSE_) {
			    feq_gen_io_d__225.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__225);
			    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)
				    sizeof(integer));
			    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
			    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
			    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(
				    integer));
			    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
			    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			    e_wsfe();
			}
/* SOURCE ntwmxstr.for:3711 */
/*<        >*/
			putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &
				emcadr, &conid, &point, &nodein, &iput, &nin, 
				&buff[1]);
/* SOURCE ntwmxstr.for:3716 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:3718 */
/*<       else >*/
		} else {
/*                 NODOUT is on a branch--connecting item is a branch. */
/*                 Find the branch number. */
/* SOURCE ntwmxstr.for:3722 */
/*<       conid=branch >*/
		    conid = 1;
/* SOURCE ntwmxstr.for:3724 */
/*<       bran=exnodt(3,nodout) >*/
		    bran = exnodt[nodout * 9 + 3];
/*                 FIND THE UPS AND DNS EXTERIOR NODE ON THIS BRANCH */
/* SOURCE ntwmxstr.for:3726 */
/*<       uexn=brpt(5,bran) >*/
		    uexn = brpt[(bran << 3) + 5];
/* SOURCE ntwmxstr.for:3727 */
/*<       dexn=brpt(6,bran) >*/
		    dexn = brpt[(bran << 3) + 6];
/*                 SET SIGN OF BRAN TO INDICATE DIRECTION OF THE BRANCH. */
/*                 SET NODEIN FOR THE POSSIBLE JUNCTION AT THE OTHER END */
/*                 OF THE BRANCH. */
/* SOURCE ntwmxstr.for:3731 */
/*<       if(nodout.eq.uexn)then >*/
		    if (nodout == uexn) {
/* SOURCE ntwmxstr.for:3732 */
/*<       nodein=dexn >*/
			nodein = dexn;
/* SOURCE ntwmxstr.for:3733 */
/*<       else >*/
		    } else {
/* SOURCE ntwmxstr.for:3734 */
/*<       nodein=uexn >*/
			nodein = uexn;
/* SOURCE ntwmxstr.for:3735 */
/*<       bran=-bran >*/
			bran = -bran;
/* SOURCE ntwmxstr.for:3736 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:3737 */
/*<       point=bran >*/
		    point = bran;
/* SOURCE ntwmxstr.for:3739 */
/*<        >*/
		    if (FALSE_) {
			feq_gen_io_d__226.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__226);
			do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(integer)
				);
			do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)sizeof(
				integer));
			conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
			s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
			do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(integer))
				;
			getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			e_wsfe();
		    }
/* SOURCE ntwmxstr.for:3743 */
/*<        >*/
		    putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &emcadr,
			     &conid, &point, &nodein, &iput, &nin, &buff[1]);
/*                 NOW GET THE ADDRESS OF EMC ENTRY FOR THE BRANCH AND */
/*                 DESCRIBE THE ITEM CONNECTED TO THE BRANCH. */
/* SOURCE ntwmxstr.for:3753 */
/*<       emcadr=brpt(7,abs(bran)) >*/
		    emcadr = brpt[(abs(bran) << 3) + 7];
/*                 FOR A NODE ON A BRANCH, EXNODT(5,NODEIN) GIVES */
/*                 EITHER A BC OR A JUNCTION. */
/* SOURCE ntwmxstr.for:3757 */
/*<       if(exnodt(5,nodein).lt.0)then >*/
		    if (exnodt[nodein * 9 + 5] < 0) {
/*                   BOUNDARY CONDITION AT THE NODE. */
/* SOURCE ntwmxstr.for:3759 */
/*<       conid=bc >*/
			conid = 3;
/* SOURCE ntwmxstr.for:3760 */
/*<       point=-exnodt(5,nodein) >*/
			point = -exnodt[nodein * 9 + 5];
/* SOURCE ntwmxstr.for:3761 */
/*<        >*/
			if (FALSE_) {
			    feq_gen_io_d__227.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__227);
			    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)
				    sizeof(integer));
			    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
			    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
			    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(
				    integer));
			    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
			    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			    e_wsfe();
			}
/* SOURCE ntwmxstr.for:3765 */
/*<        >*/
			putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &
				emcadr, &conid, &point, &nodein, &iput, &nin, 
				&buff[1]);
/* SOURCE ntwmxstr.for:3770 */
/*<       else >*/
		    } else {
/*                   JUNCTION IS CONNECTED TO THE END OF THE BRANCH */
/* SOURCE ntwmxstr.for:3772 */
/*<       conid=junc >*/
			conid = 2;
/* SOURCE ntwmxstr.for:3773 */
/*<       point=exnodt(5,nodein) >*/
			point = exnodt[nodein * 9 + 5];
/* SOURCE ntwmxstr.for:3774 */
/*<        >*/
			if (FALSE_) {
			    feq_gen_io_d__228.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__228);
			    do_fio(&feq_gen_c_d_1, (char *)&emcadr, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, (char *)&emc[emcadr], (ftnlen)
				    sizeof(integer));
			    conchr_(feq_gen_ch_d_4, (ftnlen)4, &conid);
			    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)4, (ftnlen)4);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)4);
			    do_fio(&feq_gen_c_d_1, (char *)&point, (ftnlen)sizeof(
				    integer));
			    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
			    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			    e_wsfe();
			}
/* SOURCE ntwmxstr.for:3778 */
/*<        >*/
			putrec_(stdout, &maxnin, &begbuf, &endbuf, lbuff, &
				emcadr, &conid, &point, &nodein, &iput, &nin, 
				&buff[1]);
/*                    IF(MKNDIN(NODEIN, 1, POINT, LJOIN, JOIN).EQ.0) THEN */
/* SOURCE ntwmxstr.for:3785 */
/*<       callmkndin(nodein,1,point,ljoin,join,mkpath) >*/
			mkndin_(&nodein, &feq_gen_c_d_1, &point, ljoin, &join[1], &
				mkpath);
/* SOURCE ntwmxstr.for:3789 */
/*<       if(mkpath.eq.0)then >*/
			if (mkpath == 0) {
/* SOURCE ntwmxstr.for:3790 */
/*<        >*/
			    feq_gen_io_d__229.ciunit = *stdout;
			    s_wsle(&feq_gen_io_d__229);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* AT JUNCTION="), (
				    ftnlen)23);
			    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&point, (ftnlen)
				    sizeof(integer));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" AND NODEIN="), (ftnlen)12);
			    getusn_(feq_gen_ch_d_2, (ftnlen)5, &nodein);
			    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PATH ALREADY MARKED INITI\
ATED."), (ftnlen)31);
			    e_wsle();
/* SOURCE ntwmxstr.for:3792 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE ntwmxstr.for:3793 */
/*<       endif >*/
			}
/* SOURCE ntwmxstr.for:3794 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:3795 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:3796 */
/*<       goto500 >*/
		goto L500;
/* SOURCE ntwmxstr.for:3797 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:3798 */
/*<   600 continue >*/
L600:
/*           JUNCTION COMPLETED */
/* SOURCE ntwmxstr.for:3800 */
/*<       endif >*/
	    ;
	}
/* SOURCE ntwmxstr.for:3801 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:3802 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:3804 */
/*<       end >*/
    return 0;
} /* makemc_ */




/* SOURCE ntwmxstr.for:3808 */
/*<        >*/
/* Subroutine */ int makjun_(integer *stdout, integer *nex, integer *nbra, 
	integer *lemc, integer *ljoin, integer *nentry, integer *feq_storage_add, integer 
	*feq_storage_emc, integer *feq_storage_brpt, integer *feq_storage_exnodt, integer *feq_storage_join, integer *junknt, 
	integer *feq_storage_junpnt, integer *ljunc, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:221* NODE=\002,a5,\002 not in a junct\
ion or boundary\002,\002 condition.\002)";
    static char fmt_52[] = "(\002 *ERR:222* \002,i5,\002 relationships missi\
ng for\002,\002 junction with nodes:\002)";
    static char fmt_54[] = "(\002     NODE=\002,a5)";
    static char fmt_56[] = "(\002 *ERR:223* Duplication of relationships inv\
olving nodes:\002,a5,\002 and \002,a5)";
    static char fmt_58[] = "(\002 *WRN:47* Node=\002,a5,\002 < 0 invalid. FE\
Q takes absolute\002,\002 value.\002)";
    static char fmt_60[] = "(\002 *ERR:224* Relationship with Code=\002,i5\
,\002 and nodes\002,1x,a5,\002 and \002,a5,/,11x,\002 not in a junction.\002)"
	    ;
    static char fmt_62[] = "(\002 *ERR:225* Node=\002,a5,\002, a flow node, \
is used in a\002,\002 relationship other than\002,/,11x,\002the one defining\
 it\002,\002 as a flow node.\002)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3[2], feq_gen_i_d_4;
    char feq_gen_ch_d_1[6], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5], feq_gen_ch_d_5[5];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe(), s_wsle(cilist *), 
	    do_lio(integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, n, it, nd1, nd2, len, ept, jpt, feq_gen_flag_d_, code, bran, node, 
	    qnode, emcadr;
    extern /* Subroutine */ int addrel_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
    extern integer fdnumr_(integer *, integer *, integer *, integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__237 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__241 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__242 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__246 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__247 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__248 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__249 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__250 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__251 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__252 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__255 = { 0, 0, 0, fmt_62, 0 };


/*     + + + PURPOSE + + + */
/*     Create the junction information and the temporary pointers in */
/*     BRPT and EXNODT for creating the revised pattern in EMC for */
/*     generating the matrix. */
/* SOURCE ntwmxstr.for:3818 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:3820 */
/*<       integereflag,junknt,lemc,ljoin,ljunc,nbra,nentry,nex,stdout >*/
/* SOURCE ntwmxstr.for:3822 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     NEX    - number of exterior nodes in the model */
/*     NBRA   - number of branches in the model */
/*     LEMC   - length of EMC(*) */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     NENTRY - number of entries in Network Matrix input */
/*     ADD    - Address of entry in EMC, that is, the index in EMC */
/*               at which a matrix control specification begins. */
/*     EMC    - vector containing coded form of the Matrix Control Input */
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
/*     JOIN   - vector for storing the junction descriptions */
/*     JUNKNT - junction counter */
/*     JUNPNT - junction counter */
/*     LJUNC  - length of the junction description used */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:3866 */
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
/* SOURCE ntwmxstr.for:3869 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntwmxstr.for:3873 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:3876 */
/*<       integerfdnumr >*/
/* SOURCE ntwmxstr.for:3877 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:3880 */
/*<       externaladdrel,fdnumr,getusn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:3883 */
/*<    50  >*/
/* SOURCE ntwmxstr.for:3885 */
/*<    52  >*/
/* SOURCE ntwmxstr.for:3887 */
/*<    54 format('     NODE=',a5) >*/
/* SOURCE ntwmxstr.for:3888 */
/*<    56  >*/
/* SOURCE ntwmxstr.for:3890 */
/*<    58  >*/
/* SOURCE ntwmxstr.for:3892 */
/*<    60  >*/
/* SOURCE ntwmxstr.for:3894 */
/*<    62  >*/
/* *********************************************************************** */
/*     THE  STRUCTURE FOR EACH JUNCTION IS DEFINED IN A VECTOR AS */
/*     FOLLOWS: */
/*     LOCATION     CONTENTS */
/*       JPT+0      Number of nodes in the junction-N. */
/*       JPT+1      Pointer to the junction condition in EMC(*) */
/*       JPT+2      Pointer to next open slot for the linked list */
/*                  of pointers to the EMC pointers to the relationships */
/*                  involved at this junction.  Excludes the sum of */
/*                  flows = 0 relationship.  Maximum number of */
/*                  entries possible in the linked list for this */
/*                  junction is 2*(N-1).  There are 3 elements of */
/*                  the vector used for each item stored in the list. */
/*                  Structure of an item in the list is: */
/*                          Element #    Contents */
/*                              1        pointer to the next item if */
/*                                       a next item exists. Otherwise */
/*                                       0. */
/*                              2        pointer to the EMC pointer in */
/*                                       list starting at  JPT+3 */
/*                              3        Second node in the relationship */
/*                                       if one exists, 0 otherwise. */
/*       JPT+3      Pointer to the first EMC pointer in the relationship */
/*                  list for this junction.  There are always N-1 */
/*                  relationships. */
/*       JPT+4      List of N nodes in the junction. */
/*       JPT+4+N    Path flag for the path attached to the node. */
/*                  0 if path has not been initiated. 1 if path */
/*                  has been initiated, and 2 if the path has */
/*                  terminated in this junciton. */
/*       JPT+4+2*N  Pointer to the first relationship item in the */
/*                  linked list of relationships referencing this */
/*                  node.  0 if there is no relationship. */
/*       JPT+4+3*N  Length of the path connected to the node. */
/*                  Length is the number of nodes on the path. */
/*       JPT+4+4*N  List of EMC pointers for the N-1 relationships. */
/*       JPT+4+4*N+ */
/*           N-1    List of N-1 elements not currently used. */
/*       JPT+4+4*N+ */
/*         2*(N-1)  Start of the 6*(N-1) elements for storing the */
/*                  linked list items. */
/*     CLEAR THE WORK SPACE */
/* SOURCE ntwmxstr.for:3942 */
/*<       do80i=1,ljoin >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    feq::IndexedPointer<integer> junpnt(feq_storage_junpnt, 1);

    feq::IndexedPointer<integer> add(feq_storage_add, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
    feq_gen_i_d_1 = *ljoin;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:3943 */
/*<       join(i)=0 >*/
	join[feq_gen_i_d_] = 0;
/* SOURCE ntwmxstr.for:3944 */
/*<    80 continue >*/
/* L80: */
    }
/*     FIRST PASS THROUGH EMC: SET THE JUNCTIONS AND THE FORCED BOUNDARY */
/*     CONDITIONS AND THE BRANCHES. */
/*     CLEAR THE JUNCTION POINTERS.  IF > 0 POINTS TO A JUNCTION. */
/*     IF < 0 POINTS TO AN EMC ENTRY FOR A BOUNDARY CONDTION. */
/* SOURCE ntwmxstr.for:3952 */
/*<       do90i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:3953 */
/*<       exnodt(5,i)=0 >*/
	exnodt[feq_gen_i_d_ * 9 + 5] = 0;
/* SOURCE ntwmxstr.for:3954 */
/*<    90 continue >*/
/* L90: */
    }
/*     CLEAR THE JUNCTION COUNTER */
/* SOURCE ntwmxstr.for:3958 */
/*<       junknt=0 >*/
    *junknt = 0;
/*     JPT IS THE POINTER TO THE NEXT OPEN LOCATION IN VECTOR JOIN */
/*     WHICH IS REALLY THE REAL VECTOR PDAVEC.  USE AS WORK SPACE. */
/* SOURCE ntwmxstr.for:3963 */
/*<       jpt=1 >*/
    jpt = 1;
/* SOURCE ntwmxstr.for:3964 */
/*<       do1000i=1,nentry >*/
    feq_gen_i_d_1 = *nentry;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:3965 */
/*<       ept=add(i) >*/
	ept = add[feq_gen_i_d_];
/* SOURCE ntwmxstr.for:3966 */
/*<       code=emc(ept) >*/
	code = emc[ept];
/* SOURCE ntwmxstr.for:3967 */
/*<       if(code.eq.2)then >*/
	if (code == 2) {
/* SOURCE ntwmxstr.for:3969 */
/*<       junknt=junknt+1 >*/
	    ++(*junknt);
/* SOURCE ntwmxstr.for:3970 */
/*<       junpnt(junknt)=jpt >*/
	    junpnt[*junknt] = jpt;
/*         SUM OF Q =0 */
/* SOURCE ntwmxstr.for:3973 */
/*<       n=emc(ept+1) >*/
	    n = emc[ept + 1];
/*         STORE THE NUMBER OF NODES AT THE JUNCTION */
/* SOURCE ntwmxstr.for:3977 */
/*<       join(jpt)=n >*/
	    join[jpt] = n;
/*         STORE THE POINTER INTO EMC(*) OF THE CODE 2 CONDITION */
/* SOURCE ntwmxstr.for:3981 */
/*<       join(jpt+1)=ept >*/
	    join[jpt + 1] = ept;
/*         STORE THE  INDEX OF THE FIRST OPEN SLOT FOR THE */
/*         LISTS OF POINTERS TO THE POINTERS FOR THE ELEVATION */
/*         RELATIONSHIPS BETWEEN AND AT NODES IN THE JUNCTION. */
/* SOURCE ntwmxstr.for:3987 */
/*<       join(jpt+2)=jpt+4*n+2*(n-1)+4 >*/
	    join[jpt + 2] = jpt + (n << 2) + (n - 1 << 1) + 4;
/*         STORE THE INDEX FOR THE STORING OF THE RELATIONSHIP POINTERS */
/* SOURCE ntwmxstr.for:3991 */
/*<       join(jpt+3)=jpt+4*n+4 >*/
	    join[jpt + 3] = jpt + (n << 2) + 4;
/*         SET POINTERS IN EXNODT() AND MAKE NODE LIST FOR THE NODES */
/*         AT THE JUNCTION.  ALSO ESTABLISH INITIAL VALUES FOR PATH */
/*         FLAGS AND FOR THE INITIAL POINTER FOR THE LISTS OF RELATIONSHIP */
/*         POINTERS. SET THE LENGTH FIELD FOR THE ITEM ATTACHED TO EACH */
/*         NODE. */
/* SOURCE ntwmxstr.for:3999 */
/*<       do100j=1,n >*/
	    feq_gen_i_d_2 = n;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE ntwmxstr.for:4000 */
/*<       node=emc(ept+j+1) >*/
		node = emc[ept + j + 1];
/*            WRITE(STD6,*) ' MAKJUN: INT NODE=',NODE,' EXT NODE=', */
/*     A                   GETUSN(NODE) */
/* SOURCE ntwmxstr.for:4004 */
/*<       if(node.gt.0)then >*/
		if (node > 0) {
/*             NODE IN ITS DEFAULT SIGN CONTEXT. ONLY CONTEXT */
/*             PERMITTED IN VERSION 7.0 AND LATER. */
/* SOURCE ntwmxstr.for:4007 */
/*<       exnodt(5,node)=jpt >*/
		    exnodt[node * 9 + 5] = jpt;
/* SOURCE ntwmxstr.for:4008 */
/*<       else >*/
		} else {
/*             SHOULD NOT OCCUR. */
/* SOURCE ntwmxstr.for:4010 */
/*<       write(stdout,58)'-'//getusn(-node) >*/
		    feq_gen_io_d__237.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__237);
/* Writing concatenation */
		    feq_gen_i_d_3[0] = 1, feq_gen_a_d_1[0] = const_cast<char*>("-");
		    feq_gen_i_d_4 = -node;
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_4);
		    feq_gen_i_d_3[1] = 5, feq_gen_a_d_1[1] = feq_gen_ch_d_2;
		    s_cat(feq_gen_ch_d_1, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_2, (ftnlen)6);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)6);
		    e_wsfe();
/* SOURCE ntwmxstr.for:4011 */
/*<       node=abs(node) >*/
		    node = abs(node);
/* SOURCE ntwmxstr.for:4012 */
/*<       exnodt(5,node)=jpt >*/
		    exnodt[node * 9 + 5] = jpt;
/* SOURCE ntwmxstr.for:4013 */
/*<       emc(ept+j+1)=node >*/
		    emc[ept + j + 1] = node;
/* SOURCE ntwmxstr.for:4014 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:4016 */
/*<       it=jpt+j+3 >*/
		it = jpt + j + 3;
/*           STORE THE NODE NUMBER */
/* SOURCE ntwmxstr.for:4018 */
/*<       join(it)=node >*/
		join[it] = node;
/*           CLEAR THE PATH FLAG AND THE RELATIONSHIP POINTER */
/* SOURCE ntwmxstr.for:4020 */
/*<       join(it+n)=0 >*/
		join[it + n] = 0;
/* SOURCE ntwmxstr.for:4021 */
/*<       join(it+2*n)=0 >*/
		join[it + (n << 1)] = 0;
/*           SET THE PATH LENGTH */
/* SOURCE ntwmxstr.for:4023 */
/*<       if(exnodt(3,node).le.0)then >*/
		if (exnodt[node * 9 + 3] <= 0) {
/*             ALL FREE NODES ARE PART OF A UNIT THAT ALWAYS INVOLVES */
/*             TWO NODES. */
/* SOURCE ntwmxstr.for:4026 */
/*<       len=2 >*/
		    len = 2;
/* SOURCE ntwmxstr.for:4027 */
/*<       else >*/
		} else {
/* SOURCE ntwmxstr.for:4028 */
/*<       bran=exnodt(3,node) >*/
		    bran = exnodt[node * 9 + 3];
/* SOURCE ntwmxstr.for:4029 */
/*<       len=brpt(4,bran)-brpt(3,bran)+1 >*/
		    len = brpt[(bran << 3) + 4] - brpt[(bran << 3) + 3] + 1;
/* SOURCE ntwmxstr.for:4030 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:4031 */
/*<       join(it+3*n)=len >*/
		join[it + n * 3] = len;
/* SOURCE ntwmxstr.for:4032 */
/*<   100 continue >*/
/* L100: */
	    }
/*         CLEAR THE ENTRY LEVEL FOR EACH OF THE ELEVATION */
/*         RELATIONSHIPS */
/* SOURCE ntwmxstr.for:4036 */
/*<       it=jpt+4*n+n-1+4 >*/
	    it = jpt + (n << 2) + n + 3;
/* SOURCE ntwmxstr.for:4037 */
/*<       do102j=1,n-1 >*/
	    feq_gen_i_d_2 = n - 1;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE ntwmxstr.for:4038 */
/*<       join(it)=0 >*/
		join[it] = 0;
/* SOURCE ntwmxstr.for:4039 */
/*<       it=it+1 >*/
		++it;
/* SOURCE ntwmxstr.for:4040 */
/*<   102 continue >*/
/* L102: */
	    }
/* SOURCE ntwmxstr.for:4041 */
/*<       jpt=jpt+4*n+8*(n-1)+4 >*/
	    jpt = jpt + (n << 2) + (n - 1 << 3) + 4;
/* SOURCE ntwmxstr.for:4043 */
/*<       elseif(code.eq.1)then >*/
	} else if (code == 1) {
/*         ADD BRANCH CODE POINTER */
/* SOURCE ntwmxstr.for:4045 */
/*<       brpt(7,abs(emc(ept+1)))=ept >*/
	    brpt[((feq_gen_i_d_2 = emc[ept + 1], abs(feq_gen_i_d_2)) << 3) + 7] = ept;
/* SOURCE ntwmxstr.for:4046 */
/*<       elseif(code.eq.6)then >*/
	} else if (code == 6) {
/*         RECORD POINTER TO FORCED BOUNDARY */
/* SOURCE ntwmxstr.for:4048 */
/*<       node=emc(ept+2) >*/
	    node = emc[ept + 2];
/* SOURCE ntwmxstr.for:4049 */
/*<       if(node.gt.0)then >*/
	    if (node > 0) {
/* SOURCE ntwmxstr.for:4050 */
/*<       exnodt(5,node)=-ept >*/
		exnodt[node * 9 + 5] = -ept;
/* SOURCE ntwmxstr.for:4051 */
/*<       else >*/
	    } else {
/* SOURCE ntwmxstr.for:4052 */
/*<       write(stdout,58)'-'//getusn(-node) >*/
		feq_gen_io_d__241.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__241);
/* Writing concatenation */
		feq_gen_i_d_3[0] = 1, feq_gen_a_d_1[0] = const_cast<char*>("-");
		feq_gen_i_d_2 = -node;
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_2);
		feq_gen_i_d_3[1] = 5, feq_gen_a_d_1[1] = feq_gen_ch_d_2;
		s_cat(feq_gen_ch_d_1, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_2, (ftnlen)6);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)6);
		e_wsfe();
/* SOURCE ntwmxstr.for:4053 */
/*<       node=abs(node) >*/
		node = abs(node);
/* SOURCE ntwmxstr.for:4054 */
/*<       exnodt(5,node)=-ept >*/
		exnodt[node * 9 + 5] = -ept;
/* SOURCE ntwmxstr.for:4055 */
/*<       emc(ept+2)=node >*/
		emc[ept + 2] = node;
/* SOURCE ntwmxstr.for:4056 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:4057 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4058 */
/*<  1000 continue >*/
/* L1000: */
    }
/*     SET THE LENGTH OF THE JUNCTION PORTION */
/* SOURCE ntwmxstr.for:4061 */
/*<       ljunc=jpt-1 >*/
    *ljunc = jpt - 1;
/*      WRITE(STDOUT,*) ' ' */
/*      WRITE(STDOUT,*) ' LENGTH OF JUNCTION DATA IS: ', LJUNC */
/*      WRITE(STDOUT,*) ' ' */
/*     Make sure that the LJUNC value is always > 0 to avoid problems */
/*     with some compilers when LJUNC is used in a dimension of an array. */
/* SOURCE ntwmxstr.for:4070 */
/*<       if(ljunc.eq.0)ljunc=1 >*/
    if (*ljunc == 0) {
	*ljunc = 1;
    }
/*      WRITE(STDOUT,*) ' ' */
/*      WRITE(STDOUT,*) ' DUMP OF EXNODT AFTER FIRST PASS' */
/*      WRITE(STDOUT,1234) */
/* 1234  FORMAT(' NODE CLASS EXNODT(2,*) EXNODT(5,*)') */
/*      DO 1001 I=1,NEX */
/*        IF(EXNODT(3,I).LT.0) THEN */
/*          CHR6 = '   LPR' */
/*        ELSEIF(EXNODT(3,I).EQ.0) THEN */
/*          CHR6 = '  FREE' */
/*        ELSE */
/*          CHR6 = '  BRAN' */
/*        ENDIF */
/*        WRITE(STDOUT,1235) I, CHR6, EXNODT(2,I), EXNODT(5,I) */
/* 1235  FORMAT(I5,A6,2I12) */
/* 1001  CONTINUE */
/*      WRITE(STDOUT,*) ' ' */
/*     ON THE SECOND PASS ADD THE INFORMATION FOR BOUNDARY CONDITIONS */
/*     OTHER THAN FORCED BOUNDARIES, I. E. CODE 4 AND CODE 8 CAN BE */
/*     ON A BOUNDARY, AND FOR THE ELEVATION RELATIONSHIPS */
/*     AT THE JUNCTIONS. */
/* SOURCE ntwmxstr.for:4094 */
/*<       do5000i=1,nentry >*/
    feq_gen_i_d_1 = *nentry;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:4095 */
/*<       ept=add(i) >*/
	ept = add[feq_gen_i_d_];
/* SOURCE ntwmxstr.for:4096 */
/*<       code=emc(ept) >*/
	code = emc[ept];
/* SOURCE ntwmxstr.for:4097 */
/*<        >*/
	switch (code) {
	    case 1:  goto L2000;
	    case 2:  goto L2000;
	    case 3:  goto L2003;
	    case 4:  goto L2004;
	    case 5:  goto L2005;
	    case 6:  goto L2000;
	    case 7:  goto L2000;
	    case 8:  goto L2008;
	    case 9:  goto L2000;
	    case 10:  goto L2010;
	    case 11:  goto L2011;
	    case 12:  goto L2012;
	    case 13:  goto L2013;
	    case 14:  goto L2014;
	    case 15:  goto L2000;
	}
/* SOURCE ntwmxstr.for:4100 */
/*<       write(std6,*)' BUG: INVALID CODE IN MAKJUN. CODE=',code >*/
	feq_gen_io_d__242.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__242);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG: INVALID CODE IN MAKJUN. CODE="), (ftnlen)
		35);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE ntwmxstr.for:4101 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:4103 */
/*<  2000 continue >*/
L2000:
/*         SKIP CODES 1, 2, 6, 7 AND 9, AND 15.  ALREADY PROCESSED. */
/* SOURCE ntwmxstr.for:4105 */
/*<       goto4999 >*/
	goto L4999;
/* SOURCE ntwmxstr.for:4107 */
/*<  2003 continue >*/
L2003:
/*         EQUALITY OF WATER SURFACE */
/* SOURCE ntwmxstr.for:4109 */
/*<       nd1=emc(ept+1) >*/
	nd1 = emc[ept + 1];
/* SOURCE ntwmxstr.for:4110 */
/*<       nd2=emc(ept+2) >*/
	nd2 = emc[ept + 2];
/* SOURCE ntwmxstr.for:4111 */
/*<       goto4900 >*/
	goto L4900;
/* SOURCE ntwmxstr.for:4113 */
/*<  2004 continue >*/
L2004:
/*         ONE-NODE CONTROL. CHECK FOR BOUNDARY CONDITION. */
/* SOURCE ntwmxstr.for:4115 */
/*<       nd1=emc(ept+2) >*/
	nd1 = emc[ept + 2];
/* SOURCE ntwmxstr.for:4116 */
/*<       nd2=emc(ept+4) >*/
	nd2 = emc[ept + 4];
/* SOURCE ntwmxstr.for:4117 */
/*<       if(nd2.eq.nd1)then >*/
	if (nd2 == nd1) {
/*           FLOW NODE AND HEAD NODE THE SAME */
/* SOURCE ntwmxstr.for:4119 */
/*<       nd2=0 >*/
	    nd2 = 0;
/* SOURCE ntwmxstr.for:4120 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4121 */
/*<       jpt=exnodt(5,nd1) >*/
	jpt = exnodt[nd1 * 9 + 5];
/* SOURCE ntwmxstr.for:4122 */
/*<       if(jpt.eq.0)then >*/
	if (jpt == 0) {
/*           NODE NEVER APPEARS IN A JUNCTION.  IT MUST BE A */
/*           BOUNDARY NODE. */
/* SOURCE ntwmxstr.for:4126 */
/*<       exnodt(5,nd1)=-ept >*/
	    exnodt[nd1 * 9 + 5] = -ept;
/* SOURCE ntwmxstr.for:4127 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:4128 */
/*<       calladdrel(jpt,nd1,nd2,ept,ljoin,join,flag) >*/
	    addrel_(&jpt, &nd1, &nd2, &ept, ljoin, &join[1], &feq_gen_flag_d_);
/* SOURCE ntwmxstr.for:4132 */
/*<       if(flag.eq.1)then >*/
	    if (feq_gen_flag_d_ == 1) {
/* SOURCE ntwmxstr.for:4133 */
/*<       write(stdout,56)getusn(nd1),getusn(nd2) >*/
		feq_gen_io_d__246.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__246);
		getusn_(feq_gen_ch_d_3, (ftnlen)5, &nd1);
		s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
		getusn_(feq_gen_ch_d_5, (ftnlen)5, &nd2);
		s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
		e_wsfe();
/* SOURCE ntwmxstr.for:4134 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE ntwmxstr.for:4135 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:4136 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4137 */
/*<       goto4999 >*/
	goto L4999;
/* SOURCE ntwmxstr.for:4139 */
/*<  2005 continue >*/
L2005:
/*         2-NODE CONTROL */
/* SOURCE ntwmxstr.for:4141 */
/*<       nd1=emc(ept+2) >*/
	nd1 = emc[ept + 2];
/* SOURCE ntwmxstr.for:4142 */
/*<       nd2=emc(ept+3) >*/
	nd2 = emc[ept + 3];
/* SOURCE ntwmxstr.for:4143 */
/*<       goto4900 >*/
	goto L4900;
/* SOURCE ntwmxstr.for:4145 */
/*<  2008 continue >*/
L2008:
/*         CRITICAL DEPTH */
/* SOURCE ntwmxstr.for:4147 */
/*<       nd1=emc(ept+1) >*/
	nd1 = emc[ept + 1];
/* SOURCE ntwmxstr.for:4148 */
/*<       nd2=0 >*/
	nd2 = 0;
/* SOURCE ntwmxstr.for:4149 */
/*<       jpt=exnodt(5,nd1) >*/
	jpt = exnodt[nd1 * 9 + 5];
/* SOURCE ntwmxstr.for:4150 */
/*<       if(jpt.eq.0)then >*/
	if (jpt == 0) {
/*           BOUNDARY NODE */
/* SOURCE ntwmxstr.for:4152 */
/*<       exnodt(5,nd1)=-ept >*/
	    exnodt[nd1 * 9 + 5] = -ept;
/* SOURCE ntwmxstr.for:4153 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:4154 */
/*<       calladdrel(jpt,nd1,nd2,ept,ljoin,join,flag) >*/
	    addrel_(&jpt, &nd1, &nd2, &ept, ljoin, &join[1], &feq_gen_flag_d_);
/* SOURCE ntwmxstr.for:4158 */
/*<       if(flag.eq.1)then >*/
	    if (feq_gen_flag_d_ == 1) {
/* SOURCE ntwmxstr.for:4159 */
/*<       write(stdout,56)getusn(nd1),getusn(nd2) >*/
		feq_gen_io_d__247.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__247);
		getusn_(feq_gen_ch_d_3, (ftnlen)5, &nd1);
		s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
		getusn_(feq_gen_ch_d_5, (ftnlen)5, &nd2);
		s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
		e_wsfe();
/* SOURCE ntwmxstr.for:4160 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE ntwmxstr.for:4161 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:4162 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4163 */
/*<       goto4999 >*/
	goto L4999;
/* SOURCE ntwmxstr.for:4165 */
/*<  2010 continue >*/
L2010:
/*         EQUALITY OF ENERGY LINE */
/* SOURCE ntwmxstr.for:4167 */
/*<       nd1=emc(ept+1) >*/
	nd1 = emc[ept + 1];
/* SOURCE ntwmxstr.for:4168 */
/*<       nd2=emc(ept+2) >*/
	nd2 = emc[ept + 2];
/* SOURCE ntwmxstr.for:4169 */
/*<       goto4900 >*/
	goto L4900;
/* SOURCE ntwmxstr.for:4171 */
/*<  2011 continue >*/
L2011:
/*         SIMPLE MOMENTUM BALANCE */
/* SOURCE ntwmxstr.for:4173 */
/*<       nd1=emc(ept+1) >*/
	nd1 = emc[ept + 1];
/* SOURCE ntwmxstr.for:4174 */
/*<       nd2=emc(ept+2) >*/
	nd2 = emc[ept + 2];
/* SOURCE ntwmxstr.for:4175 */
/*<       goto4900 >*/
	goto L4900;
/* SOURCE ntwmxstr.for:4177 */
/*<  2012 continue >*/
L2012:
/*         MATCH AVERAGE ELEVATION. TAKE UPSTREAM NODE FOR NOW */
/* SOURCE ntwmxstr.for:4179 */
/*<       nd1=emc(ept+1) >*/
	nd1 = emc[ept + 1];
/* SOURCE ntwmxstr.for:4180 */
/*<       nd2=emc(ept+3) >*/
	nd2 = emc[ept + 3];
/* SOURCE ntwmxstr.for:4181 */
/*<       goto4900 >*/
	goto L4900;
/* SOURCE ntwmxstr.for:4183 */
/*<  2013 continue >*/
L2013:
/*         ENERGY/MOMENTUM MATCH */
/* SOURCE ntwmxstr.for:4185 */
/*<       nd1=emc(ept+1) >*/
	nd1 = emc[ept + 1];
/* SOURCE ntwmxstr.for:4186 */
/*<       nd2=emc(ept+2) >*/
	nd2 = emc[ept + 2];
/* SOURCE ntwmxstr.for:4187 */
/*<       goto4900 >*/
	goto L4900;
/* SOURCE ntwmxstr.for:4189 */
/*<  2014 continue >*/
L2014:
/*         SIDE WEIR FLOW. */
/* SOURCE ntwmxstr.for:4191 */
/*<       nd1=emc(ept+1) >*/
	nd1 = emc[ept + 1];
/* SOURCE ntwmxstr.for:4192 */
/*<       nd2=emc(ept+3) >*/
	nd2 = emc[ept + 3];
/* SOURCE ntwmxstr.for:4193 */
/*<       goto4900 >*/
	goto L4900;
/* SOURCE ntwmxstr.for:4196 */
/*<  4900 continue >*/
L4900:
/*         PROCESS RELATIONSHIPS INVOLVING TWO NODES. */
/* SOURCE ntwmxstr.for:4199 */
/*<       jpt=exnodt(5,nd1) >*/
	jpt = exnodt[nd1 * 9 + 5];
/* SOURCE ntwmxstr.for:4200 */
/*<       if(jpt.le.0)then >*/
	if (jpt <= 0) {
/* SOURCE ntwmxstr.for:4201 */
/*<       write(stdout,60)code,getusn(nd1),getusn(nd2) >*/
	    feq_gen_io_d__248.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__248);
	    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &nd1);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    getusn_(feq_gen_ch_d_5, (ftnlen)5, &nd2);
	    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:4202 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:4203 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4204 */
/*<       calladdrel(jpt,nd1,nd2,ept,ljoin,join,flag) >*/
	addrel_(&jpt, &nd1, &nd2, &ept, ljoin, &join[1], &feq_gen_flag_d_);
/* SOURCE ntwmxstr.for:4208 */
/*<       if(flag.eq.1)then >*/
	if (feq_gen_flag_d_ == 1) {
/* SOURCE ntwmxstr.for:4209 */
/*<       write(stdout,56)getusn(nd1),getusn(nd2) >*/
	    feq_gen_io_d__249.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__249);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &nd1);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    getusn_(feq_gen_ch_d_5, (ftnlen)5, &nd2);
	    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:4210 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:4211 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4212 */
/*<       goto4999 >*/
	goto L4999;
/* SOURCE ntwmxstr.for:4214 */
/*<  4999 continue >*/
L4999:
/* SOURCE ntwmxstr.for:4216 */
/*<  5000 continue >*/
/* L5000: */
	;
    }
/*     CHECK FOR ERRORS IN THE MODEL SPECIFICATION */
/* SOURCE ntwmxstr.for:4221 */
/*<       do5100i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:4222 */
/*<       if(exnodt(5,i).eq.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 5] == 0) {
/* SOURCE ntwmxstr.for:4223 */
/*<       write(stdout,50)getusn(i) >*/
	    feq_gen_io_d__250.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__250);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &feq_gen_i_d_);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    e_wsfe();
/* SOURCE ntwmxstr.for:4224 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:4225 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4226 */
/*<  5100 continue >*/
/* L5100: */
    }
/* SOURCE ntwmxstr.for:4228 */
/*<       do5200i=1,junknt >*/
    feq_gen_i_d_1 = *junknt;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:4229 */
/*<       jpt=junpnt(i) >*/
	jpt = junpnt[feq_gen_i_d_];
/* SOURCE ntwmxstr.for:4230 */
/*<       n=join(jpt) >*/
	n = join[jpt];
/* SOURCE ntwmxstr.for:4232 */
/*<       it=join(jpt+3)-(jpt+4+4*n) >*/
	it = join[jpt + 3] - (jpt + 4 + (n << 2));
/* SOURCE ntwmxstr.for:4234 */
/*<       if(it.lt.n-1)then >*/
	if (it < n - 1) {
/*         TOO FEW RELATIONSHIPS IN A JUNCTION */
/* SOURCE ntwmxstr.for:4236 */
/*<       write(stdout,52)n-1-it >*/
	    feq_gen_io_d__251.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__251);
	    feq_gen_i_d_2 = n - 1 - it;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:4237 */
/*<       do5150j=jpt+4,jpt+4+n-1 >*/
	    feq_gen_i_d_2 = jpt + 4 + n - 1;
	    for (j = jpt + 4; j <= feq_gen_i_d_2; ++j) {
/* SOURCE ntwmxstr.for:4238 */
/*<       write(stdout,54)getusn(join(j)) >*/
		feq_gen_io_d__252.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__252);
		getusn_(feq_gen_ch_d_3, (ftnlen)5, &join[j]);
		s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
		e_wsfe();
/* SOURCE ntwmxstr.for:4239 */
/*<  5150 continue >*/
/* L5150: */
	    }
/* SOURCE ntwmxstr.for:4240 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ntwmxstr.for:4241 */
/*<       endif >*/
	}
/*       CHECK TO MAKE SURE THAT NODES GIVEN AS FLOW NODES */
/*       DO NOT HAVE ANY OTHER RELATIONSHIP ATTACHED TO THEM. */
/* SOURCE ntwmxstr.for:4245 */
/*<       if(n.gt.1)then >*/
	if (n > 1) {
/*         SCAN THE RELATIONSHIPS AND CHECK THE RELATIONSHIP */
/*         COUNT AT THE FLOW NODES FOUND. */
/* SOURCE ntwmxstr.for:4248 */
/*<       do5160j=jpt+4+4*n,jpt+4+4*n+n-2 >*/
	    feq_gen_i_d_2 = jpt + 4 + (n << 2) + n - 2;
	    for (j = jpt + 4 + (n << 2); j <= feq_gen_i_d_2; ++j) {
/* SOURCE ntwmxstr.for:4249 */
/*<       emcadr=join(j) >*/
		emcadr = join[j];
/* SOURCE ntwmxstr.for:4250 */
/*<       code=emc(emcadr) >*/
		code = emc[emcadr];
/* SOURCE ntwmxstr.for:4251 */
/*<       qnode=0 >*/
		qnode = 0;
/* SOURCE ntwmxstr.for:4252 */
/*<       if(code.eq.4)then >*/
		if (code == 4) {
/* SOURCE ntwmxstr.for:4253 */
/*<       qnode=emc(emcadr+4) >*/
		    qnode = emc[emcadr + 4];
/* SOURCE ntwmxstr.for:4254 */
/*<       elseif(code.eq.5)then >*/
		} else if (code == 5) {
/* SOURCE ntwmxstr.for:4255 */
/*<       qnode=emc(emcadr+4) >*/
		    qnode = emc[emcadr + 4];
/* SOURCE ntwmxstr.for:4256 */
/*<       elseif(code.eq.14)then >*/
		} else if (code == 14) {
/* SOURCE ntwmxstr.for:4257 */
/*<       qnode=emc(emcadr+3) >*/
		    qnode = emc[emcadr + 3];
/* SOURCE ntwmxstr.for:4258 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:4259 */
/*<       if(qnode.gt.0)then >*/
		if (qnode > 0) {
/*             Relationship has a flow node. Count relationships at */
/*             the flow node.  There can only be one relationship */
/*             at a flow node--the one that defines the flow node. */
/*             The sum of flows = 0 condition is not counted as */
/*             a relationship. */
/* SOURCE ntwmxstr.for:4266 */
/*<       if(fdnumr(qnode,jpt,ljoin,join).ne.1)then >*/
		    if (fdnumr_(&qnode, &jpt, ljoin, &join[1]) != 1) {
/*               Problem with relationship at a flow node */
/* SOURCE ntwmxstr.for:4268 */
/*<       write(stdout,62)getusn(qnode) >*/
			feq_gen_io_d__255.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__255);
			getusn_(feq_gen_ch_d_3, (ftnlen)5, &qnode);
			s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
			e_wsfe();
/* SOURCE ntwmxstr.for:4269 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE ntwmxstr.for:4270 */
/*<       endif >*/
		    }
/* SOURCE ntwmxstr.for:4271 */
/*<       endif >*/
		}
/* SOURCE ntwmxstr.for:4272 */
/*<  5160 continue >*/
/* L5160: */
	    }
/* SOURCE ntwmxstr.for:4273 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4274 */
/*<  5200 continue >*/
/* L5200: */
    }
/* SOURCE ntwmxstr.for:4276 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:4277 */
/*<       end >*/
} /* makjun_ */




/* SOURCE ntwmxstr.for:4281 */
/*<       subroutinemakmat(stdout,nbra,nex,nbn,brpt,exnodt,emc) >*/
/* Subroutine */ int makmat_(integer *stdout, integer *nbra, integer *nex, 
	integer *nbn, integer *feq_storage_brpt, integer *feq_storage_exnodt, integer *feq_storage_emc)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:226* Model requires \002,i5,\002 or\
 more matrix blocks\002,\002 but only\002,i5,\002 available.\002)";
    static char fmt_57[] = "(/,\002 *BUG:XXX* Wrong block type for CODE=\002\
,i5,\002 in\002,\002 MAKMAT.\002,/,11x,\002Expected -1 but found MBTYPE=\002\
,i5)";
    static char fmt_58[] = "(/,\002 *BUG:XXX* Invalid EDNCON for CODE=\002,i\
5,\002 in MAKMAT.\002,/,11x,\002Expected > 0 but found -1.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, j, nd, dnn, nnd, nbr, jeq[20], neq, num, unn, code, ivar, 
	    itmp, ipnt, nexp, feq_gen_type_d_, eqoff, eqlen, eqstr, pdapnt, elmknt, 
	    ientry;
    extern /* Subroutine */ int makpro_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__262 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__271 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__272 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__279 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__282 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__283 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__284 = { 0, 0, 0, fmt_58, 0 };


/*     + + + PURPOSE + + + */
/*     Create the pattern in the solution matrix.  Variable numbers */
/*     have already been assigned.  We need to create the pointer */
/*     vectors for the matrix profile and create the matrix blocks. */
/* SOURCE ntwmxstr.for:4290 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE ntwmxstr.for:4292 */
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
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:4295 */
/*<       integerstdout,nbn,nbra,nex >*/
/* SOURCE ntwmxstr.for:4296 */
/*<       integerbrpt(8,nbra),emc(mremc),exnodt(9,nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     NBN    - total number on nodes on branches in the model */
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
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:4330 */
/* *********************************************************************** */
/*     COMMON BLOCK FOR PROFILE MATRIX SOLUTION. */
/* SOURCE matcom.cmn:4 */
/*<        >*/
/* SOURCE matcom.cmn:8 */
/*<       common/matcom2/pdavec2,rhs2 >*/
/* SOURCE matcom.cmn:10 */
/*<       integermatblk,numeq,nentry >*/
/* SOURCE matcom.cmn:12 */
/*<        >*/
/* SOURCE matcom.cmn:16 */
/*<       realpdavec(mlpda),rhs(mrmat),hi_iq_ns_fac(mrmat) >*/
/*     Add second set to help in diagnostics-at least as a trial. */
/* SOURCE matcom.cmn:19 */
/*<       realpdavec2(mlpda),rhs2(mrmat) >*/
/* *********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:4333 */
/*<        >*/
/* SOURCE ntwmxstr.for:4335 */
/*<       integerjeq(20) >*/
/* SOURCE ntwmxstr.for:4336 */
/*<       integerelmknt >*/
/*      CHARACTER*1 CMAT(1013,1013) */
/*     + + + INTRINSICS + + + */
/* SOURCE ntwmxstr.for:4341 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:4344 */
/*<       externalmakpro >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:4347 */
/*<    50  >*/
/* SOURCE ntwmxstr.for:4349 */
/*<    57  >*/
/* SOURCE ntwmxstr.for:4351 */
/*<    58  >*/
/* *********************************************************************** */
/*     CMAT USED TO DISPLAY PATTERN OF THE MATRIX FOR DEBUGGING. */
/*     NORMALLY DISABLED. */
/*      CHARACTER*1 CMAT(1013,1013) */
/*      CHARACTER*1 CMAT(1,1) */
/*     INITIALIZE VARIABLES */
/*     IPNT = COUNTER FOR EMC */
/*     NEQ = NO. OF EQUATIONS FOR THE MATRIX */
/*     IENTRY = INDEX FOR ADDRESSES OF ENTRIES IN EMC IN ADD(*) */
/*     IVAR = COUNTER FOR THE VARIABLE NUMBER.  EACH NODE HAS 2 VARIABLES */
/*            FOR THE 4-POINT SCHEME.  MORE COMPLEX SCHEMES ON A BRANCH */
/*            MAY REQUIRE 4 OR 6 VARIABLES OR MORE FOR EACH NODE. */
/*     PDAPNT = POINTER INTO THE PARTIAL DERIVATIVE ARRAY VECTOR */
/*              USED IN MAKPRO TO ASSIGN VALUES TO C() AND R(). */
/* SOURCE ntwmxstr.for:4370 */
/*<       ipnt=emc(1) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L57: */
/* L58: */
    ipnt = emc[1];
/* SOURCE ntwmxstr.for:4371 */
/*<       ientry=1 >*/
    ientry = 1;
/* SOURCE ntwmxstr.for:4372 */
/*<       neq=0 >*/
    neq = 0;
/* SOURCE ntwmxstr.for:4373 */
/*<       pdapnt=0 >*/
    pdapnt = 0;
/*     OPEN THE FIRST BLOCK FOR THE MATRIX.  GENERAL TYPE WITH A */
/*     NULL ENDING CONDITION.  THE TYPE IS SET NEGATIVE TO INDICATE THAT */
/*     IT IS OPEN.  THE ENDING CONDITION WILL CHANGE BEFORE THE BLOCK IS */
/*     COMPLETE.  THUS IT CANNOT BE USED AS A SIGNAL THAT THE BLOCK */
/*     IS STILL OPEN. */
/* SOURCE ntwmxstr.for:4381 */
/*<       matblk=1 >*/
    matcom_1.matblk = 1;
/* SOURCE ntwmxstr.for:4382 */
/*<       begrow(1)=2 >*/
    matcom_1.begrow[0] = 2;
/* SOURCE ntwmxstr.for:4383 */
/*<       endcon(1)=-1 >*/
    matcom_1.endcon[0] = -1;
/* SOURCE ntwmxstr.for:4384 */
/*<       mbtype(1)=-1 >*/
    matcom_1.mbtype[0] = -1;
/*     INITIALIZE THE POINTER FOR THE COLUMNS IN THE MATRIX PROFILE */
/* SOURCE ntwmxstr.for:4388 */
/*<       do9i=0,mrmat >*/
    for (feq_gen_i_d_ = 0; feq_gen_i_d_ <= 24800; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:4389 */
/*<       c(i)=0 >*/
	matcom_1.feq_gen_c_d_[feq_gen_i_d_] = 0;
/* SOURCE ntwmxstr.for:4390 */
/*<     9 continue >*/
/* L9: */
    }
/* C     INITIALIZE CMAT FOR CHECKING MATRIX STRUCTURE */
/*      DO 813 I=1,1013 */
/*        DO 713 J=1,1013 */
/*          CMAT(I,J)='.' */
/* 713     CONTINUE */
/* 813   CONTINUE */
/* SOURCE ntwmxstr.for:4399 */
/*< 10000 continue >*/
L10000:
/*     GET NEXT CODE FROM MATRIX CONTROL VECTOR */
/* SOURCE ntwmxstr.for:4403 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE ntwmxstr.for:4404 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE ntwmxstr.for:4405 */
/*<       if(code.eq.-1)goto20000 >*/
    if (code == -1) {
	goto L20000;
    }
/* SOURCE ntwmxstr.for:4406 */
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
	case 13:  goto L1300;
	case 14:  goto L1400;
	case 15:  goto L1500;
    }
/* SOURCE ntwmxstr.for:4408 */
/*<       write(stdout,*)' *BUG:05* INVALID EMC CODE IN MAKMAT. CODE=',code >*/
    feq_gen_io_d__262.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__262);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:05* INVALID EMC CODE IN MAKMAT. CODE="), (
	    ftnlen)43);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE ntwmxstr.for:4410 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/*     CODE 1 GIVES BRANCH NUMBERS */
/* SOURCE ntwmxstr.for:4414 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:4416 */
/*<       nbr=emc(ipnt+1) >*/
    nbr = emc[ipnt + 1];
/*       GET THE NUMBER OF ELEMENTS  AND NODES ON THIS BRANCH */
/* SOURCE ntwmxstr.for:4419 */
/*<       elmknt=brpt(4,abs(nbr))-brpt(3,abs(nbr)) >*/
    elmknt = brpt[(abs(nbr) << 3) + 4] - brpt[(abs(nbr) << 3) + 3];
/*        NODKNT = ELMKNT + 1 */
/*       MAKE BRANCH NUMBER IN EMC() POSITIVE */
/* SOURCE ntwmxstr.for:4424 */
/*<       nbr=abs(nbr) >*/
    nbr = abs(nbr);
/* SOURCE ntwmxstr.for:4425 */
/*<       emc(ipnt+1)=nbr >*/
    emc[ipnt + 1] = nbr;
/*       GET THE VARIABLE NUMBER FOR THIS BRANCH */
/* SOURCE ntwmxstr.for:4429 */
/*<       ivar=abs(brpt(7,nbr)) >*/
    ivar = (feq_gen_i_d_1 = brpt[(nbr << 3) + 7], abs(feq_gen_i_d_1));
/*       UPDATE THE POINTERS FOR THE MATRIX PROFILE FOR THE */
/*       EQUATIONS WHICH WILL APPEAR FOR THIS BRANCH. */
/*       SET THE EQUATION OFFSET FOR THE BRANCH.  SAME AS NUMBER OF */
/*       UNKNOWNS FOR EACH NODE ON THE BRANCH. */
/* SOURCE ntwmxstr.for:4437 */
/*<       eqoff=brpt(8,nbr) >*/
    eqoff = brpt[(nbr << 3) + 8];
/*       SET THE EQUATION LENGTH.  FOR SINGLE CHANNELS CURRENTLY */
/*       IMPLEMENTED THE EQUATION LENGTH IS TWICE THE NUMBER OF */
/*       UNKNOWNS AT EACH NODE. */
/* SOURCE ntwmxstr.for:4443 */
/*<       eqlen=2*eqoff >*/
    eqlen = eqoff << 1;
/*       SET THE STARTING POINT FOR THE FIRST EQUATION IN THE BRANCH */
/* SOURCE ntwmxstr.for:4447 */
/*<       eqstr=ivar >*/
    eqstr = ivar;
/* SOURCE ntwmxstr.for:4449 */
/*<       do120i=1,elmknt >*/
    feq_gen_i_d_1 = elmknt;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*         SET THE VARIABLE NUMBERS INVOLVED IN THE NEXT SET OF */
/*         EQUATIONS. */
/* SOURCE ntwmxstr.for:4452 */
/*<       do105j=1,eqlen >*/
	feq_gen_i_d_2 = eqlen;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE ntwmxstr.for:4453 */
/*<       jeq(j)=eqstr+j-1 >*/
	    jeq[j - 1] = eqstr + j - 1;
/* SOURCE ntwmxstr.for:4454 */
/*<   105 continue >*/
/* L105: */
	}
/*         CALL MKPRO EQOFF TIMES INCREMENTING THE NUMBER OF EQUATIONS */
/* SOURCE ntwmxstr.for:4457 */
/*<       do110j=1,eqoff >*/
	feq_gen_i_d_2 = eqoff;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE ntwmxstr.for:4458 */
/*<       neq=neq+1 >*/
	    ++neq;
/* SOURCE ntwmxstr.for:4459 */
/*<       callmakpro(neq,eqlen,jeq,pdapnt,c,r) >*/
	    makpro_(&neq, &eqlen, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*           Set the offset from the main diagonal for the rightmost nonzero */
/*           coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4466 */
/*<       eqend(neq)=jeq(eqlen)-neq >*/
	    matcom_1.eqend[neq - 1] = jeq[eqlen - 1] - neq;
/*           SET PATTERN IN THE MATRIX FOR CHECKING */
/*            CALL MAKPAT(NUMEQ, NEQ, EQLEN, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4472 */
/*<   110 continue >*/
/* L110: */
	}
/*         UPDATE THE STARTING POINT OF THE EQUATIONS FOR THE NEXT */
/*         SET IN THE MATRIX FOR THE BRANCH. */
/* SOURCE ntwmxstr.for:4477 */
/*<       eqstr=eqstr+eqoff >*/
	eqstr += eqoff;
/* SOURCE ntwmxstr.for:4479 */
/*<   120 continue >*/
/* L120: */
    }
/*       NOW PROCESS THE MATRIX BLOCKS. */
/*       THE CURRENT OPEN BLOCK TYPE SHOULD BE -1 SHOWING AN */
/*       OPEN GENERAL BLOCK. */
/* SOURCE ntwmxstr.for:4485 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4486 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4487 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4488 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4489 */
/*<       goto999 >*/
	goto L999;
/* SOURCE ntwmxstr.for:4490 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4492 */
/*<       if(elmknt.le.3)then >*/
    if (elmknt <= 3) {
/*         BLOCK IS TOO SHORT FOR SPECIAL OPERATIONS.  THE EQUATIONS */
/*         FOR THE FIRST AND LAST ELEMENT IN THE BRANCH CANNOT BE */
/*         IN A SPECIAL SOLUTION TYPE BECAUSE THEY COULD INVOLVE */
/*         CONNECTIONS TO OTHER BRANCHES.  THUS THE MATRIX PROFILE */
/*         COULD DIFFER FROM THE STANDARD WITHIN-BRANCH PATTERN. */
/*         PLACE ALL THE EQUATIONS IN THE CURRENTLY OPEN BLOCK AND */
/*         LEAVE THE BLOCK OPEN BECAUSE OTHER EQUATIONS WILL HAVE TO */
/*         BE ADDED TO IT. */
/*         EQUATIONS ARE PLACED IN THE BLOCK BY CHANGING THE ENDING */
/*         CONDITION VALUE TO THE CURRENT LAST EQUATION NUMBER.  THE */
/*         STARTING EQUATION NUMBER WAS SET WHEN THE BLOCK WAS OPENED. */
/* SOURCE ntwmxstr.for:4506 */
/*<       endcon(matblk)=neq >*/
	matcom_1.endcon[matcom_1.matblk - 1] = neq;
/* SOURCE ntwmxstr.for:4507 */
/*<       else >*/
    } else {
/*         THE BLOCK IS LONGER THAN THREE ELEMENTS.  ADD THE FIRST */
/*         TWO EQUATIONS TO THE CURRENTLY OPEN BLOCK.  CLOSE THE */
/*         CURRENT BLOCK AND OPEN A NEW BLOCK OF TYPE 2. FILL THIS */
/*         BLOCK. CLOSE IT. OPEN ANOTHER BLOCK OF TYPE -1 AND PLACE */
/*         THE LAST TWO EQUATIONS IN IT. THUS BLOCKS FOR THE */
/*         INTERNALS OF BRANCHES ARE ONLY OPEN FOR THE PROCESSING */
/*         OF THAT BRANCH. */
/* SOURCE ntwmxstr.for:4516 */
/*<       endcon(matblk)=endcon(matblk)+2 >*/
	matcom_1.endcon[matcom_1.matblk - 1] += 2;
/* SOURCE ntwmxstr.for:4517 */
/*<       mbtype(matblk)=abs(mbtype(matblk)) >*/
	matcom_1.mbtype[matcom_1.matblk - 1] = (feq_gen_i_d_1 = matcom_1.mbtype[
		matcom_1.matblk - 1], abs(feq_gen_i_d_1));
/* SOURCE ntwmxstr.for:4518 */
/*<       matblk=matblk+1 >*/
	++matcom_1.matblk;
/* SOURCE ntwmxstr.for:4519 */
/*<       if(matblk.gt.mrmblk)then >*/
	if (matcom_1.matblk > 4401) {
/* SOURCE ntwmxstr.for:4520 */
/*<       write(stdout,50)matblk,mrmblk >*/
	    feq_gen_io_d__271.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__271);
	    do_fio(&feq_gen_c_d_1, (char *)&matcom_1.matblk, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_4401, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:4521 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:4522 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4523 */
/*<       begrow(matblk)=endcon(matblk-1)+1 >*/
	matcom_1.begrow[matcom_1.matblk - 1] = matcom_1.endcon[
		matcom_1.matblk - 2] + 1;
/*         THE ENDING CONDITION FOR A BLOCK FOR A BRANCH IS NOT THE */
/*         ENDING EQUATION NUMBER BUT THE ROW ADDRESS IN R() GIVEN */
/*         BY THE EQUATION NUMBER OF THE FIRST EQUATION OF THE ENDING */
/*         PAIR OF EQUATIONS APPEARING IN THE BLOCK. */
/* SOURCE ntwmxstr.for:4529 */
/*<       endcon(matblk)=r(neq-3) >*/
	matcom_1.endcon[matcom_1.matblk - 1] = matcom_1.feq_gen_r_d_[neq - 4];
/*         BLOCK IS DEFINED. CLOSE BLOCK WITH POSTIVE BLOCK TYPE. */
/* SOURCE ntwmxstr.for:4533 */
/*<       mbtype(matblk)=2 >*/
	matcom_1.mbtype[matcom_1.matblk - 1] = 2;
/*         OPEN NEXT BLOCK OF GENERAL TYPE AND PUT THE LAST TWO EQUATIONS */
/*         FOR THIS BRANCH IN IT. */
/* SOURCE ntwmxstr.for:4538 */
/*<       matblk=matblk+1 >*/
	++matcom_1.matblk;
/* SOURCE ntwmxstr.for:4539 */
/*<       if(matblk.gt.mrmblk)then >*/
	if (matcom_1.matblk > 4401) {
/* SOURCE ntwmxstr.for:4540 */
/*<       write(stdout,50)matblk,mrmblk >*/
	    feq_gen_io_d__272.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__272);
	    do_fio(&feq_gen_c_d_1, (char *)&matcom_1.matblk, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_4401, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ntwmxstr.for:4541 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:4542 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:4543 */
/*<       begrow(matblk)=neq-1 >*/
	matcom_1.begrow[matcom_1.matblk - 1] = neq - 1;
/* SOURCE ntwmxstr.for:4544 */
/*<       endcon(matblk)=neq >*/
	matcom_1.endcon[matcom_1.matblk - 1] = neq;
/* SOURCE ntwmxstr.for:4545 */
/*<       mbtype(matblk)=-1 >*/
	matcom_1.mbtype[matcom_1.matblk - 1] = -1;
/* SOURCE ntwmxstr.for:4546 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4547 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 2 GIVES DISCHARGE CONTINUITY AT JUNCTIONS. */
/* SOURCE ntwmxstr.for:4551 */
/*<   200 continue >*/
L200:
/* SOURCE ntwmxstr.for:4552 */
/*<       nnd=emc(ipnt+1) >*/
    nnd = emc[ipnt + 1];
/*       TRANSFER THE VARIABLE NUMBERS TO JEQ(). THESE INVOLVE THE FLOW */
/*       SO THE VARIABLE NUMBERS AS STORED IN EXNODT() GIVE THE CORRECT */
/*       VALUES */
/* SOURCE ntwmxstr.for:4556 */
/*<       do210i=1,nnd >*/
    feq_gen_i_d_1 = nnd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:4557 */
/*<       jeq(i)=exnodt(5,abs(emc(ipnt+1+i))) >*/
	jeq[feq_gen_i_d_ - 1] = exnodt[(feq_gen_i_d_2 = emc[ipnt + 1 + feq_gen_i_d_], abs(feq_gen_i_d_2)) * 9 + 5]
		;
/* SOURCE ntwmxstr.for:4558 */
/*<   210 continue >*/
/* L210: */
    }
/*       PROCESS THE EQUATIONS */
/* SOURCE ntwmxstr.for:4561 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4562 */
/*<       callmakpro(neq,nnd,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &nnd, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4569 */
/*<       eqend(neq)=jeq(nnd)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[nnd - 1] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, NND, JEQ, CMAT) */
/*       ADD THE EQUATION TO THE CURRENT OPEN BLOCK. */
/* SOURCE ntwmxstr.for:4576 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4577 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4578 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4580 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/*         SUM OF FLOWS WITH ONE NODE AS A FORCED ZERO FLOW */
/* SOURCE ntwmxstr.for:4583 */
/*<       endcon(matblk)=1 >*/
	matcom_1.endcon[matcom_1.matblk - 1] = 1;
/* SOURCE ntwmxstr.for:4584 */
/*<       else >*/
    } else {
/*         UPDATE ENDCON TO THE CURRENT EQUATION NUMBER */
/* SOURCE ntwmxstr.for:4587 */
/*<       endcon(matblk)=neq >*/
	matcom_1.endcon[matcom_1.matblk - 1] = neq;
/* SOURCE ntwmxstr.for:4588 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4589 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 3 - GIVES ELEVATION EQUALITY */
/* SOURCE ntwmxstr.for:4593 */
/*<   300 continue >*/
L300:
/* SOURCE ntwmxstr.for:4594 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE ntwmxstr.for:4595 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/*       TRANSFER THE VARIABLE NUMBERS.  INVOLVES ONLY ELEVATIONS SO ADD */
/*       ONE TO THE VARIABLE NUMBERS IN EXNODT() */
/* SOURCE ntwmxstr.for:4598 */
/*<       jeq(1)=exnodt(5,unn)+1 >*/
    jeq[0] = exnodt[unn * 9 + 5] + 1;
/* SOURCE ntwmxstr.for:4599 */
/*<       jeq(2)=exnodt(5,dnn)+1 >*/
    jeq[1] = exnodt[dnn * 9 + 5] + 1;
/* SOURCE ntwmxstr.for:4600 */
/*<       if(jeq(1).gt.jeq(2))then >*/
    if (jeq[0] > jeq[1]) {
/* SOURCE ntwmxstr.for:4601 */
/*<       itmp=jeq(2) >*/
	itmp = jeq[1];
/* SOURCE ntwmxstr.for:4602 */
/*<       jeq(2)=jeq(1) >*/
	jeq[1] = jeq[0];
/* SOURCE ntwmxstr.for:4603 */
/*<       jeq(1)=itmp >*/
	jeq[0] = itmp;
/* SOURCE ntwmxstr.for:4604 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4606 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4607 */
/*<       callmakpro(neq,2,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_2, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4614 */
/*<       eqend(neq)=jeq(2)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[1] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 2, JEQ, CMAT) */
/*       ADD TO CURRENT BLOCK */
/* SOURCE ntwmxstr.for:4621 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4622 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4623 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4624 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4625 */
/*<       goto999 >*/
	goto L999;
/* SOURCE ntwmxstr.for:4626 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4628 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
    ++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4629 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 4 - CONTROL STRUCTURE WITH 1 NODE HEAD DISCHARGE */
/*     UNN = UPSTREAM NODE FOR HEAD */
/*     DNN = NODE FOR DISCHARGE */
/* SOURCE ntwmxstr.for:4635 */
/*<   400 continue >*/
L400:
/* SOURCE ntwmxstr.for:4636 */
/*<       unn=emc(ipnt+2) >*/
    unn = emc[ipnt + 2];
/* SOURCE ntwmxstr.for:4637 */
/*<       dnn=emc(ipnt+4) >*/
    dnn = emc[ipnt + 4];
/*       GET THE VARIABLE NUMBERS.  THE NODE FOR HEAD ONLY INVOLVES */
/*       HEAD AND THE NODE FOR FLOW ONLY INVOLVES FLOW. */
/* SOURCE ntwmxstr.for:4641 */
/*<       jeq(1)=exnodt(5,unn)+1 >*/
    jeq[0] = exnodt[unn * 9 + 5] + 1;
/* SOURCE ntwmxstr.for:4642 */
/*<       jeq(2)=exnodt(5,dnn) >*/
    jeq[1] = exnodt[dnn * 9 + 5];
/* SOURCE ntwmxstr.for:4643 */
/*<       if(jeq(1).gt.jeq(2))then >*/
    if (jeq[0] > jeq[1]) {
/* SOURCE ntwmxstr.for:4644 */
/*<       itmp=jeq(2) >*/
	itmp = jeq[1];
/* SOURCE ntwmxstr.for:4645 */
/*<       jeq(2)=jeq(1) >*/
	jeq[1] = jeq[0];
/* SOURCE ntwmxstr.for:4646 */
/*<       jeq(1)=itmp >*/
	jeq[0] = itmp;
/* SOURCE ntwmxstr.for:4647 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4648 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4649 */
/*<       callmakpro(neq,2,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_2, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4656 */
/*<       eqend(neq)=jeq(2)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[1] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/* SOURCE ntwmxstr.for:4659 */
/*<       if(jeq(1).eq.exnodt(5,unn)+1)then >*/
    if (jeq[0] == exnodt[unn * 9 + 5] + 1) {
/* SOURCE ntwmxstr.for:4660 */
/*<       jeq(1)=-jeq(1) >*/
	jeq[0] = -jeq[0];
/* SOURCE ntwmxstr.for:4661 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:4662 */
/*<       jeq(2)=-jeq(2) >*/
	jeq[1] = -jeq[1];
/* SOURCE ntwmxstr.for:4663 */
/*<       endif >*/
    }
/*        CALL MAKPAT(NUMEQ, NEQ, 2, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4666 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4667 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4668 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4669 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/*         MATRIX STARTS AT A DOWNSTREAM BOUNDARY */
/* SOURCE ntwmxstr.for:4671 */
/*<       endcon(matblk)=1 >*/
	matcom_1.endcon[matcom_1.matblk - 1] = 1;
/* SOURCE ntwmxstr.for:4672 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:4673 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
	++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4674 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4675 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 5 - CONTROL STRUCTURE WITH 2 NODE HEAD DISCHARGE */
/* SOURCE ntwmxstr.for:4678 */
/*<   500 continue >*/
L500:
/* SOURCE ntwmxstr.for:4680 */
/*<       unn=emc(ipnt+2) >*/
    unn = emc[ipnt + 2];
/* SOURCE ntwmxstr.for:4681 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[ipnt + 3];
/*       GET THE VARIABLE NUMBERS.  BOTH NODES INVOLVE BOTH FLOW */
/*       AND ELEVATION */
/* SOURCE ntwmxstr.for:4684 */
/*<       jeq(1)=exnodt(5,unn) >*/
    jeq[0] = exnodt[unn * 9 + 5];
/* SOURCE ntwmxstr.for:4685 */
/*<       jeq(2)=jeq(1)+1 >*/
    jeq[1] = jeq[0] + 1;
/* SOURCE ntwmxstr.for:4686 */
/*<       jeq(3)=exnodt(5,dnn) >*/
    jeq[2] = exnodt[dnn * 9 + 5];
/* SOURCE ntwmxstr.for:4687 */
/*<       jeq(4)=jeq(3)+1 >*/
    jeq[3] = jeq[2] + 1;
/* SOURCE ntwmxstr.for:4688 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4689 */
/*<       callmakpro(neq,4,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_4, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4696 */
/*<       eqend(neq)=jeq(4)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[3] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/* SOURCE ntwmxstr.for:4699 */
/*<       if(jeq(2).eq.exnodt(5,unn)+1)then >*/
    if (jeq[1] == exnodt[unn * 9 + 5] + 1) {
/* SOURCE ntwmxstr.for:4700 */
/*<       jeq(2)=-jeq(2) >*/
	jeq[1] = -jeq[1];
/* SOURCE ntwmxstr.for:4701 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:4702 */
/*<       jeq(4)=-jeq(4) >*/
	jeq[3] = -jeq[3];
/* SOURCE ntwmxstr.for:4703 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4704 */
/*<       if(jeq(2).eq.exnodt(5,dnn)+1)then >*/
    if (jeq[1] == exnodt[dnn * 9 + 5] + 1) {
/* SOURCE ntwmxstr.for:4705 */
/*<       jeq(2)=-jeq(2) >*/
	jeq[1] = -jeq[1];
/* SOURCE ntwmxstr.for:4706 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:4707 */
/*<       jeq(4)=-jeq(4) >*/
	jeq[3] = -jeq[3];
/* SOURCE ntwmxstr.for:4708 */
/*<       endif >*/
    }
/*        CALL MAKPAT(NUMEQ, NEQ, 4, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4711 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4712 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4713 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4714 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4715 */
/*<       goto999 >*/
	goto L999;
/* SOURCE ntwmxstr.for:4716 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4717 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
    ++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4719 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 6 - GIVES DETAILS OF FORCED BOUNDARY */
/*     ITYPE = 1  Q VS T */
/*     ITYPE = 2  Y VS T */
/* SOURCE ntwmxstr.for:4725 */
/*<   600 continue >*/
L600:
/* SOURCE ntwmxstr.for:4726 */
/*<       type=emc(ipnt+1) >*/
    feq_gen_type_d_ = emc[ipnt + 1];
/* SOURCE ntwmxstr.for:4727 */
/*<       num=emc(ipnt+2) >*/
    num = emc[ipnt + 2];
/*       VARIABLE NUMBER INVOLVED VARIES WITH TYPE */
/* SOURCE ntwmxstr.for:4729 */
/*<       if(type.eq.1)then >*/
    if (feq_gen_type_d_ == 1) {
/* SOURCE ntwmxstr.for:4730 */
/*<       jeq(1)=exnodt(5,num) >*/
	jeq[0] = exnodt[num * 9 + 5];
/* SOURCE ntwmxstr.for:4731 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:4732 */
/*<       jeq(1)=exnodt(5,num)+1 >*/
	jeq[0] = exnodt[num * 9 + 5] + 1;
/* SOURCE ntwmxstr.for:4733 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4734 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4735 */
/*<       callmakpro(neq,1,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_1, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4742 */
/*<       eqend(neq)=jeq(1)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[0] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 1, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4747 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4748 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4749 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4750 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4751 */
/*<       endcon(matblk)=1 >*/
	matcom_1.endcon[matcom_1.matblk - 1] = 1;
/* SOURCE ntwmxstr.for:4752 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:4753 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
	++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4754 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4755 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 7 - LEVEL POOL RESERVOIR */
/*     NND = NO. OF INFLOW NODES = 1 EXACTLY */
/*     DNN = NODE OF RESERVOIR */
/*     UNN = INFLOW NODES IN TURN */
/* SOURCE ntwmxstr.for:4762 */
/*<   700 continue >*/
L700:
/*       MODIFY THE RESERVOIR SO THAT IT IS MORE LIKE A DUMMY BRANCH */
/*       GOAL IS TO FILL OUT ALL SLOTS IN THE MATRIX ENTRIES FOR THE */
/*       RESERVOIR */
/* SOURCE ntwmxstr.for:4767 */
/*<       dnn=emc(ipnt+1) >*/
    dnn = emc[ipnt + 1];
/* SOURCE ntwmxstr.for:4768 */
/*<       unn=emc(ipnt+5) >*/
    unn = emc[ipnt + 5];
/*       USE KINEMATIC FUNCTION LIKE FOR A DUMMY BRANCH */
/* SOURCE ntwmxstr.for:4771 */
/*<       jeq(1)=exnodt(5,dnn) >*/
    jeq[0] = exnodt[dnn * 9 + 5];
/* SOURCE ntwmxstr.for:4772 */
/*<       jeq(2)=jeq(1)+1 >*/
    jeq[1] = jeq[0] + 1;
/* SOURCE ntwmxstr.for:4773 */
/*<       jeq(3)=exnodt(5,unn) >*/
    jeq[2] = exnodt[unn * 9 + 5];
/* SOURCE ntwmxstr.for:4774 */
/*<       jeq(4)=jeq(3)+1 >*/
    jeq[3] = jeq[2] + 1;
/* SOURCE ntwmxstr.for:4776 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4777 */
/*<       callmakpro(neq,4,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_4, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4784 */
/*<       eqend(neq)=jeq(4)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[3] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 4, JEQ, CMAT) */
/*       SET THE RESERVOIR NODE VALUES */
/* SOURCE ntwmxstr.for:4791 */
/*<       jeq(1)=exnodt(5,dnn) >*/
    jeq[0] = exnodt[dnn * 9 + 5];
/* SOURCE ntwmxstr.for:4792 */
/*<       jeq(2)=jeq(1)+1 >*/
    jeq[1] = jeq[0] + 1;
/* SOURCE ntwmxstr.for:4793 */
/*<       jeq(3)=exnodt(5,unn) >*/
    jeq[2] = exnodt[unn * 9 + 5];
/* SOURCE ntwmxstr.for:4794 */
/*<       jeq(4)=jeq(3)+1 >*/
    jeq[3] = jeq[2] + 1;
/* SOURCE ntwmxstr.for:4796 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4797 */
/*<       callmakpro(neq,4,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_4, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4804 */
/*<       eqend(neq)=jeq(4)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[3] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 4, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4809 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4810 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4811 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4812 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4813 */
/*<       goto999 >*/
	goto L999;
/* SOURCE ntwmxstr.for:4814 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4815 */
/*<       endcon(matblk)=endcon(matblk)+2 >*/
    matcom_1.endcon[matcom_1.matblk - 1] += 2;
/* SOURCE ntwmxstr.for:4817 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 8 - CRITICAL DEPTH CONDITION */
/*     NUM = NODE NUMBER */
/* SOURCE ntwmxstr.for:4822 */
/*<   800 continue >*/
L800:
/* SOURCE ntwmxstr.for:4823 */
/*<       num=emc(ipnt+1) >*/
    num = emc[ipnt + 1];
/*       INVOLVES BOTH VARIABLES AT THE NODE */
/* SOURCE ntwmxstr.for:4825 */
/*<       jeq(1)=exnodt(5,num) >*/
    jeq[0] = exnodt[num * 9 + 5];
/* SOURCE ntwmxstr.for:4826 */
/*<       jeq(2)=jeq(1)+1 >*/
    jeq[1] = jeq[0] + 1;
/* SOURCE ntwmxstr.for:4827 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4828 */
/*<       callmakpro(neq,2,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_2, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4835 */
/*<       eqend(neq)=jeq(2)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[1] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 2, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4840 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4841 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4842 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4843 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4844 */
/*<       endcon(matblk)=1 >*/
	matcom_1.endcon[matcom_1.matblk - 1] = 1;
/* SOURCE ntwmxstr.for:4845 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:4846 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
	++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4847 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4848 */
/*<       goto9000 >*/
    goto L9000;
/*     CODE 9 MOMENTUM JUNCTION */
/* SOURCE ntwmxstr.for:4853 */
/*<   900 continue >*/
L900:
/* SOURCE ntwmxstr.for:4854 */
/*<       write(stdout,*)' SHOULD NOT REACH CODE=9 IN MAKMAT' >*/
    feq_gen_io_d__279.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__279);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SHOULD NOT REACH CODE=9 IN MAKMAT"), (ftnlen)34);
    e_wsle();
/* SOURCE ntwmxstr.for:4855 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/*        GOTO 9000 */
/*     CODE 10 - EQUALITY OF ELEVATION OF TOTAL ENERGY LINE, */
/*     and momentum balance code 11 */
/* SOURCE ntwmxstr.for:4862 */
/*<   950 continue >*/
L950:
/* SOURCE ntwmxstr.for:4863 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE ntwmxstr.for:4864 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/*       ALL VARIABLES AT EACH NODE INVOLVED */
/* SOURCE ntwmxstr.for:4866 */
/*<       jeq(1)=exnodt(5,unn) >*/
    jeq[0] = exnodt[unn * 9 + 5];
/* SOURCE ntwmxstr.for:4867 */
/*<       jeq(2)=jeq(1)+1 >*/
    jeq[1] = jeq[0] + 1;
/* SOURCE ntwmxstr.for:4868 */
/*<       jeq(3)=exnodt(5,dnn) >*/
    jeq[2] = exnodt[dnn * 9 + 5];
/* SOURCE ntwmxstr.for:4869 */
/*<       jeq(4)=jeq(3)+1 >*/
    jeq[3] = jeq[2] + 1;
/* SOURCE ntwmxstr.for:4870 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4871 */
/*<       callmakpro(neq,4,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_4, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4878 */
/*<       eqend(neq)=jeq(4)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[3] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 4, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4883 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4884 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4885 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4886 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4887 */
/*<       goto999 >*/
	goto L999;
/* SOURCE ntwmxstr.for:4888 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4890 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
    ++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4891 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE ntwmxstr.for:4893 */
/*<  1200 continue >*/
L1200:
/*       THREE NODES INVOLVED HERE.  ONLY DEPTH VARIABLE INVOLVED. */
/* SOURCE ntwmxstr.for:4895 */
/*<       do1201i=1,3 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 3; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:4896 */
/*<       nd=emc(ipnt+i) >*/
	nd = emc[ipnt + feq_gen_i_d_];
/* SOURCE ntwmxstr.for:4897 */
/*<       jeq(i)=exnodt(5,nd)+1 >*/
	jeq[feq_gen_i_d_ - 1] = exnodt[nd * 9 + 5] + 1;
/* SOURCE ntwmxstr.for:4898 */
/*<  1201 continue >*/
/* L1201: */
    }
/* SOURCE ntwmxstr.for:4899 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4900 */
/*<       callmakpro(neq,3,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_3, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4907 */
/*<       eqend(neq)=jeq(3)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[2] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 3, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4912 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4913 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4914 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4915 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4916 */
/*<       goto999 >*/
	goto L999;
/* SOURCE ntwmxstr.for:4917 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4918 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
    ++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4919 */
/*<       goto9000 >*/
    goto L9000;
/*     Momentum/energy conservation */
/* SOURCE ntwmxstr.for:4923 */
/*<  1300 continue >*/
L1300:
/* SOURCE ntwmxstr.for:4924 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE ntwmxstr.for:4925 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/*       ALL VARIABLES AT EACH NODE INVOLVED */
/* SOURCE ntwmxstr.for:4927 */
/*<       jeq(1)=exnodt(5,unn) >*/
    jeq[0] = exnodt[unn * 9 + 5];
/* SOURCE ntwmxstr.for:4928 */
/*<       jeq(2)=jeq(1)+1 >*/
    jeq[1] = jeq[0] + 1;
/* SOURCE ntwmxstr.for:4929 */
/*<       jeq(3)=exnodt(5,dnn) >*/
    jeq[2] = exnodt[dnn * 9 + 5];
/* SOURCE ntwmxstr.for:4930 */
/*<       jeq(4)=jeq(3)+1 >*/
    jeq[3] = jeq[2] + 1;
/* SOURCE ntwmxstr.for:4931 */
/*<       nnd=4 >*/
    nnd = 4;
/*       Do the side nodes if any are present.   Both variables */
/*       are involved with a side node. */
/* SOURCE ntwmxstr.for:4934 */
/*<       do1301j=1,emc(ipnt+6) >*/
    feq_gen_i_d_1 = emc[ipnt + 6];
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE ntwmxstr.for:4935 */
/*<       nnd=nnd+1 >*/
	++nnd;
/* SOURCE ntwmxstr.for:4936 */
/*<       jeq(nnd)=exnodt(5,emc(ipnt+6+j)) >*/
	jeq[nnd - 1] = exnodt[emc[ipnt + 6 + j] * 9 + 5];
/* SOURCE ntwmxstr.for:4937 */
/*<       nnd=nnd+1 >*/
	++nnd;
/* SOURCE ntwmxstr.for:4938 */
/*<       jeq(nnd)=jeq(nnd-1)+1 >*/
	jeq[nnd - 1] = jeq[nnd - 2] + 1;
/* SOURCE ntwmxstr.for:4939 */
/*<  1301 continue >*/
/* L1301: */
    }
/* SOURCE ntwmxstr.for:4940 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4941 */
/*<       callmakpro(neq,nnd,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &nnd, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4948 */
/*<       eqend(neq)=jeq(nnd)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[nnd - 1] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 4, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4953 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4954 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4955 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4956 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4957 */
/*<       goto999 >*/
	goto L999;
/* SOURCE ntwmxstr.for:4958 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4960 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
    ++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4961 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE ntwmxstr.for:4964 */
/*<  1400 continue >*/
L1400:
/*       THREE NODES INVOLVED HERE.  BOTH VARIABLES INVOLVED AT THE NODES. */
/* SOURCE ntwmxstr.for:4966 */
/*<       j=1 >*/
    j = 1;
/* SOURCE ntwmxstr.for:4967 */
/*<       do1401i=1,3 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 3; ++feq_gen_i_d_) {
/* SOURCE ntwmxstr.for:4968 */
/*<       nd=emc(ipnt+i) >*/
	nd = emc[ipnt + feq_gen_i_d_];
/* SOURCE ntwmxstr.for:4969 */
/*<       jeq(j)=exnodt(5,nd) >*/
	jeq[j - 1] = exnodt[nd * 9 + 5];
/* SOURCE ntwmxstr.for:4970 */
/*<       jeq(j+1)=jeq(j)+1 >*/
	jeq[j] = jeq[j - 1] + 1;
/* SOURCE ntwmxstr.for:4971 */
/*<       j=j+2 >*/
	j += 2;
/* SOURCE ntwmxstr.for:4972 */
/*<  1401 continue >*/
/* L1401: */
    }
/* SOURCE ntwmxstr.for:4973 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:4974 */
/*<       callmakpro(neq,6,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_6, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:4981 */
/*<       eqend(neq)=jeq(6)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[5] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 6, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:4986 */
/*<       if(mbtype(matblk).ne.-1)then >*/
    if (matcom_1.mbtype[matcom_1.matblk - 1] != -1) {
/* SOURCE ntwmxstr.for:4987 */
/*<       goto998 >*/
	goto L998;
/* SOURCE ntwmxstr.for:4988 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4989 */
/*<       if(endcon(matblk).eq.-1)then >*/
    if (matcom_1.endcon[matcom_1.matblk - 1] == -1) {
/* SOURCE ntwmxstr.for:4990 */
/*<       goto999 >*/
	goto L999;
/* SOURCE ntwmxstr.for:4991 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:4992 */
/*<       endcon(matblk)=endcon(matblk)+1 >*/
    ++matcom_1.endcon[matcom_1.matblk - 1];
/* SOURCE ntwmxstr.for:4993 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE ntwmxstr.for:4995 */
/*<  1500 continue >*/
L1500:
/*       NULL BRANCH.  TWO EQUATIONS GENERATED HERE */
/* SOURCE ntwmxstr.for:4998 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE ntwmxstr.for:4999 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/*       DO FIRST EQUATION: LINEAR KINEMATIC */
/* SOURCE ntwmxstr.for:5002 */
/*<       jeq(1)=exnodt(5,unn) >*/
    jeq[0] = exnodt[unn * 9 + 5];
/* SOURCE ntwmxstr.for:5003 */
/*<       jeq(2)=jeq(1)+1 >*/
    jeq[1] = jeq[0] + 1;
/* SOURCE ntwmxstr.for:5004 */
/*<       jeq(3)=exnodt(5,dnn) >*/
    jeq[2] = exnodt[dnn * 9 + 5];
/* SOURCE ntwmxstr.for:5005 */
/*<       jeq(4)=jeq(3)+1 >*/
    jeq[3] = jeq[2] + 1;
/* SOURCE ntwmxstr.for:5006 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:5007 */
/*<       callmakpro(neq,4,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_4, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:5014 */
/*<       eqend(neq)=jeq(4)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[3] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 4, JEQ, CMAT) */
/*       DO SECOND EQUATION: CONTINUITY EQUATION */
/* SOURCE ntwmxstr.for:5021 */
/*<       jeq(1)=exnodt(5,unn) >*/
    jeq[0] = exnodt[unn * 9 + 5];
/* SOURCE ntwmxstr.for:5022 */
/*<       jeq(2)=jeq(1)+1 >*/
    jeq[1] = jeq[0] + 1;
/* SOURCE ntwmxstr.for:5023 */
/*<       jeq(3)=exnodt(5,dnn) >*/
    jeq[2] = exnodt[dnn * 9 + 5];
/* SOURCE ntwmxstr.for:5024 */
/*<       jeq(4)=jeq(3)+1 >*/
    jeq[3] = jeq[2] + 1;
/* SOURCE ntwmxstr.for:5025 */
/*<       neq=neq+1 >*/
    ++neq;
/* SOURCE ntwmxstr.for:5026 */
/*<       callmakpro(neq,4,jeq,pdapnt,c,r) >*/
    makpro_(&neq, &feq_gen_c_d_4, jeq, &pdapnt, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_);
/*       Set the offset from the main diagonal for the rightmost nonzero */
/*       coeff. in the current equation. */
/* SOURCE ntwmxstr.for:5033 */
/*<       eqend(neq)=jeq(4)-neq >*/
    matcom_1.eqend[neq - 1] = jeq[3] - neq;
/*       SET PATTERN IN THE MATRIX FOR CHECKING */
/*        CALL MAKPAT(NUMEQ, NEQ, 4, JEQ, CMAT) */
/* SOURCE ntwmxstr.for:5038 */
/*<       endcon(matblk)=endcon(matblk)+2 >*/
    matcom_1.endcon[matcom_1.matblk - 1] += 2;
/* SOURCE ntwmxstr.for:5039 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE ntwmxstr.for:5041 */
/*<  9000 continue >*/
L9000:
/* SOURCE ntwmxstr.for:5043 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE ntwmxstr.for:5044 */
/*<       goto10000 >*/
    goto L10000;
/* SOURCE ntwmxstr.for:5046 */
/*< 20000 continue >*/
L20000:
/*     CLOSE THE LAST BLOCK */
/* SOURCE ntwmxstr.for:5049 */
/*<       mbtype(matblk)=abs(mbtype(matblk)) >*/
    matcom_1.mbtype[matcom_1.matblk - 1] = (feq_gen_i_d_1 = matcom_1.mbtype[
	    matcom_1.matblk - 1], abs(feq_gen_i_d_1));
/*     CHECK NUMBER OF EQUATIONS. ONLY WORKS WITH BRANCHES WITH */
/*     2 UNKNOWNS PER NODE. */
/* SOURCE ntwmxstr.for:5054 */
/*<       nexp=2*(nbn+nex-2*nbra) >*/
    nexp = *nbn + *nex - (*nbra << 1) << 1;
/* SOURCE ntwmxstr.for:5055 */
/*<       if(neq.ne.nexp)then >*/
    if (neq != nexp) {
/* SOURCE ntwmxstr.for:5056 */
/*<        >*/
	feq_gen_io_d__282.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__282);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* FOUND "), (ftnlen)17);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&neq, (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" EQUATIONS IN MAKMAT"), (ftnlen)20);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUT EXPECTED "), (ftnlen)14);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&nexp, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE ntwmxstr.for:5058 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:5059 */
/*<       endif >*/
    }
/*     OUTPUT MATRIX PATTERN */
/*      IF(NUMEQ.LE.1013) THEN */
/*        CALL PUTPAT(STDOUT, NEQ, CMAT, NEX, EXNODT, NBRA, BRPT) */
/*      ENDIF */
/* SOURCE ntwmxstr.for:5067 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:5068 */
/*<   998 continue >*/
L998:
/* SOURCE ntwmxstr.for:5069 */
/*<       write(stdout,57)code,mbtype(matblk) >*/
    feq_gen_io_d__283.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__283);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&matcom_1.mbtype[matcom_1.matblk - 1], (ftnlen)
	    sizeof(integer));
    e_wsfe();
/* SOURCE ntwmxstr.for:5070 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:5071 */
/*<   999 continue >*/
L999:
/* SOURCE ntwmxstr.for:5072 */
/*<       write(stdout,58)code >*/
    feq_gen_io_d__284.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__284);
    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE ntwmxstr.for:5073 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:5074 */
/*<       end >*/
    return 0;
} /* makmat_ */




/* SOURCE ntwmxstr.for:5078 */
/*<       subroutinemakpro(ieq,nonzr,jeq,fp,c,r) >*/
/* Subroutine */ int makpro_(integer *ieq, integer *nonzr, integer *feq_storage_jeq, 
	integer *fp, integer *feq_gen_c_d_, integer *feq_gen_feq_storage_r_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer j, k, minj;
    extern /* Subroutine */ int iasort_(integer *, integer *);

/*     + + + PURPOSE + + + */
/*     Process equation number, IEQ, creating the pointers into */
/*     PDAVEC(*) used to store the profile of a variable-band matrix. */
/*     NONZR gives the number of non-zero entries on the current */
/*     row given by IEQ.  JEQ(*) contains the column numbers of the */
/*     entries.  FP is the pointer into */
/*     PDAVEC(*) and points to the last entry used in PDAVEC(*). */
/*     Therefore FP should be zero for the first call to MAKPRO and */
/*     should be left unchanged for all subsequent calls. */
/*     On the first call C(0:*) must be set to zero also. */
/*     After the equation has been processed, R(IEQ) points to the */
/*     location in PDAVEC(*) of the first subdiagonal in row IEQ of the */
/*     matrix.  If there are no coefficients in the row below the */
/*     main diagonal then R(IEQ) has the same value as C(IEQ-1). */
/*     On exit C(IEQ) points to the diagonal coefficient in row */
/*     IEQ. */
/* SOURCE ntwmxstr.for:5100 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE ntwmxstr.for:5102 */
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
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:5105 */
/*<       integerfp,ieq,nonzr >*/
/* SOURCE ntwmxstr.for:5106 */
/*<       integerc(0:mrmat),jeq(20),r(mrmat) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IEQ    - equation number */
/*     NONZR  - number of non-zero entries for an equation */
/*     JEQ    - column numbers of nonzero coefficients for current */
/*               equation */
/*     FP     - pointer to last entry used in PDAVEC */
/*     C      - pointer to diagonal element for each equation in the */
/*               network matrix */
/*     R      - pointer to first subdiagonal element for each equation */
/*               in the network matrix */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ntwmxstr.for:5120 */
/*<       integermaxint >*/
/* SOURCE ntwmxstr.for:5121 */
/*<       parameter(maxint=2147483647) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:5124 */
/*<       integerj,k,minj >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntwmxstr.for:5127 */
/*<       intrinsicmin >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:5130 */
/*<       externaliasort >*/
/* *********************************************************************** */
/*     SORT JEQ INTO ASCENDING ORDER */
/* SOURCE ntwmxstr.for:5133 */
/*<       calliasort(nonzr,jeq) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_r_d_(feq_gen_feq_storage_r_d_, 1);

    feq::IndexedPointer<integer> jeq(feq_storage_jeq, 1);

    /* Function Body */
    iasort_(nonzr, &jeq[1]);
/*     SET THE MINIMUM COLUMN VALUE FOR THE ROW */
/* SOURCE ntwmxstr.for:5138 */
/*<       minj=maxint >*/
    minj = 2147483647;
/* SOURCE ntwmxstr.for:5140 */
/*<       do100k=1,nonzr >*/
    feq_gen_i_d_1 = *nonzr;
    for (k = 1; k <= feq_gen_i_d_1; ++k) {
/*       GET THE CURRENT COLUMN NUMBER */
/* SOURCE ntwmxstr.for:5142 */
/*<       j=jeq(k) >*/
	j = jeq[k];
/* SOURCE ntwmxstr.for:5143 */
/*<       if(j.ge.ieq)then >*/
	if (j >= *ieq) {
/*         WE HAVE A VALUE IN THE CURRENT ROW ON OR ABOVE THE MAIN */
/*         DIAGONAL.  REMEMBER THE ROW NUMBER FOR THIS COLUMN IF THIS */
/*         IS THE FIRST TIME A NONZERO VALUE HAS OCCURRED IN THIS COLUMN. */
/* SOURCE ntwmxstr.for:5148 */
/*<       if(c(j).eq.0)then >*/
	    if (feq_gen_c_d_[j] == 0) {
/* SOURCE ntwmxstr.for:5149 */
/*<       c(j)=ieq >*/
		feq_gen_c_d_[j] = *ieq;
/* SOURCE ntwmxstr.for:5150 */
/*<       endif >*/
	    }
/* SOURCE ntwmxstr.for:5151 */
/*<       else >*/
	} else {
/*         WE HAVE A VALUE BELOW THE MAIN DIAGONAL IN THE CURRENT ROW. */
/*         FIND THE MINIMUM VALUE FOR ALL COLUMNS BELOW THE MAIN DIAGONAL */
/*         IN THE CURRENT ROW. */
/* SOURCE ntwmxstr.for:5156 */
/*<       minj=min(j,minj) >*/
	    minj = min(j,minj);
/* SOURCE ntwmxstr.for:5157 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:5159 */
/*<   100 continue >*/
/* L100: */
    }
/*     AT THIS POINT ALL THE POSSIBLE COEFFICIENTS AT OR ABOVE */
/*     ROW IEQ HAVE BEEN ENCOUNTERED.  THUS THE COLUMN ABOVE THE */
/*     DIAGONAL IN THE CURRENT ROW IS DEFINED. */
/*     PROCESS THE CURRENT ROW */
/* SOURCE ntwmxstr.for:5166 */
/*<       if(minj.eq.maxint)then >*/
    if (minj == 2147483647) {
/*       NO VALUES BELOW THE MAIN DIAGONAL. SIGNAL A NULL ROW. */
/* SOURCE ntwmxstr.for:5168 */
/*<       r(ieq)=c(ieq-1) >*/
	feq_gen_r_d_[*ieq] = feq_gen_c_d_[*ieq - 1];
/* SOURCE ntwmxstr.for:5169 */
/*<       else >*/
    } else {
/*       MUST ALLOCATE SPACE IN PDAVEC(*) FROM MINIMUM COLUMN THROUGH THE */
/*       ELEMENT IN THE FIRST SUBDIAGONAL. */
/* SOURCE ntwmxstr.for:5173 */
/*<       fp=fp+ieq-minj >*/
	*fp = *fp + *ieq - minj;
/* SOURCE ntwmxstr.for:5174 */
/*<       r(ieq)=fp >*/
	feq_gen_r_d_[*ieq] = *fp;
/* SOURCE ntwmxstr.for:5175 */
/*<       endif >*/
    }
/*     PROCESS THE CURRENT COLUMN(COLUMN ABOVE THE DIAGONAL ELEMENT OF */
/*     THE CURRENT ROW) */
/* SOURCE ntwmxstr.for:5179 */
/*<       if(c(ieq).eq.0)then >*/
    if (feq_gen_c_d_[*ieq] == 0) {
/*       NO COLUMN ENTRIES FOUND.  MUST ALLOCATE SPACE FOR THE */
/*       DIAGONAL ELEMENT. */
/* SOURCE ntwmxstr.for:5183 */
/*<       fp=fp+1 >*/
	++(*fp);
/* SOURCE ntwmxstr.for:5184 */
/*<       c(ieq)=fp >*/
	feq_gen_c_d_[*ieq] = *fp;
/* SOURCE ntwmxstr.for:5185 */
/*<       else >*/
    } else {
/*       C(IEQ) GIVES THE VALUE OF THE FIRST ROW IN THE MATRIX HAVING */
/*       A NON-ZERO ELEMENT IN COLUMN IEQ. */
/* SOURCE ntwmxstr.for:5189 */
/*<       fp=fp+ieq-c(ieq)+1 >*/
	*fp = *fp + *ieq - feq_gen_c_d_[*ieq] + 1;
/* SOURCE ntwmxstr.for:5190 */
/*<       c(ieq)=fp >*/
	feq_gen_c_d_[*ieq] = *fp;
/* SOURCE ntwmxstr.for:5191 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:5193 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:5194 */
/*<       end >*/
} /* makpro_ */




/* SOURCE ntwmxstr.for:5198 */
/*<       subroutinemkndin(node,action,jpt,ljoin,join,mkpath) >*/
/* Subroutine */ int mkndin_(integer *node, integer *action, integer *jpt, 
	integer *ljoin, integer *feq_storage_join, integer *mkpath)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX MKNDIN: NODE=\002,a5,\002 NOT IN \
LIST. JPT=\002,i6)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer n, adr, nodadr;
    extern integer exnodn_(integer *, integer *, integer *, integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__290 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Mark the path at NODE according to ACTION. If ACTION=1 then */
/*     the path should not have been marked before. If it is marked */
/*     return a value of zero, else mark it with 1 and return value */
/*     of 1. If ACTION=2 then set the path at NODE to 2 and return */
/*     2. */
/* SOURCE ntwmxstr.for:5210 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:5212 */
/*<       integeraction,jpt,ljoin,mkpath,node >*/
/* SOURCE ntwmxstr.for:5213 */
/*<       integerjoin(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NODE   - node number */
/*     ACTION - Coded value for the action to take when initiating a */
/*               path */
/*     JPT    - pointer for the junction descriptions */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     JOIN   - vector for storing the junction descriptions */
/*     MKPATH - mark value for the path */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntwmxstr.for:5225 */
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
/* SOURCE ntwmxstr.for:5228 */
/*<       integeradr,n,nodadr >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntwmxstr.for:5231 */
/*<       integerexnodn >*/
/* SOURCE ntwmxstr.for:5232 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntwmxstr.for:5235 */
/*<       externalexnodn,getusn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:5238 */
/*<    50 format(' *BUG:XXX MKNDIN: NODE=',a5,' NOT IN LIST. JPT=',i6) >*/
/* *********************************************************************** */
/*     SET NUMBER OF NODES */
/* SOURCE ntwmxstr.for:5241 */
/*<       n=join(jpt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    /* Function Body */
/* L50: */
    n = join[*jpt];
/* SOURCE ntwmxstr.for:5243 */
/*<       nodadr=exnodn(node,jpt,ljoin,join) >*/
    nodadr = exnodn_(node, jpt, ljoin, &join[1]);
/* SOURCE ntwmxstr.for:5244 */
/*<       if(nodadr.le.0)then >*/
    if (nodadr <= 0) {
/* SOURCE ntwmxstr.for:5245 */
/*<       write(std6,50)getusn(node),jpt >*/
	feq_gen_io_d__290.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__290);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&(*jpt), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ntwmxstr.for:5246 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:5247 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:5249 */
/*<       adr=nodadr+n >*/
    adr = nodadr + n;
/* SOURCE ntwmxstr.for:5250 */
/*<       if(action.eq.1)then >*/
    if (*action == 1) {
/* SOURCE ntwmxstr.for:5251 */
/*<       if(join(adr).ne.0)then >*/
	if (join[adr] != 0) {
/* SOURCE ntwmxstr.for:5252 */
/*<       mkpath=0 >*/
	    *mkpath = 0;
/* SOURCE ntwmxstr.for:5253 */
/*<       else >*/
	} else {
/* SOURCE ntwmxstr.for:5254 */
/*<       mkpath=1 >*/
	    *mkpath = 1;
/* SOURCE ntwmxstr.for:5255 */
/*<       join(adr)=1 >*/
	    join[adr] = 1;
/*          WRITE(STD6,*) ' NODE=',GETUSN(NODE),' INITIATED IN JPT=',JPT */
/* SOURCE ntwmxstr.for:5257 */
/*<       endif >*/
	}
/* SOURCE ntwmxstr.for:5258 */
/*<       else >*/
    } else {
/* SOURCE ntwmxstr.for:5259 */
/*<       mkpath=2 >*/
	*mkpath = 2;
/* SOURCE ntwmxstr.for:5260 */
/*<       join(adr)=2 >*/
	join[adr] = 2;
/*        WRITE(STD6,*) ' NODE=',GETUSN(NODE),' COMPLETED IN JPT=',JPT */
/* SOURCE ntwmxstr.for:5262 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:5263 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:5264 */
/*<       end >*/
} /* mkndin_ */




/* SOURCE ntwmxstr.for:5268 */
/*<        >*/
/* Subroutine */ int putrec_(integer *stdout, integer *maxnin, integer *
	begbuf, integer *endbuf, integer *lbuff, integer *emcadr, integer *
	conid, integer *point, integer *nodein, integer *iput, integer *nin, 
	integer *feq_storage_buff)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:227* Pending instruction buffer overf\
low. Number \002,\002 of records=\002,i5)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__292 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Write the next record in the pending instruction buffer. */
/*     The buffer is circular.  Each record has four elements in */
/*     it.  NIN gives the count of the number of records in the */
/*     buffer and MAXNIN gives the maximum number of records which */
/*     the buffer can hold without overlap of information. */
/* SOURCE ntwmxstr.for:5281 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:5283 */
/*<        >*/
/* SOURCE ntwmxstr.for:5285 */
/*<       integerbuff(lbuff) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     MAXNIN - maximum number of records that the pending instruction */
/*               buffer can hold */
/*     BEGBUF - beginning address for pending instruction buffer */
/*     ENDBUF - end point for the pending instruction buffer */
/*     LBUFF  - number of elements in the pending instruction buffer */
/*     EMCADR - address of relationship in EMC(*) */
/*     CONID  - connecting item id code.  Defined in MAKEMC */
/*     POINT  - pointer to the connecting item */
/*     NODEIN - user node identification string */
/*     IPUT   - address in the pending instruction buffer for storing */
/*               the next instruction */
/*     NIN    - number or records remaining in the pending instruction */
/*               buffer */
/*     BUFF   - pending instruction buffer */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntwmxstr.for:5305 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:5308 */
/*<       nin=nin+1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> buff(feq_storage_buff, 1);

    /* Function Body */
/* L50: */
    ++(*nin);
/* SOURCE ntwmxstr.for:5309 */
/*<       if(nin.gt.maxnin)then >*/
    if (*nin > *maxnin) {
/*       BUFFER IS OVER FULL. MUST STOP PROCESSING */
/* SOURCE ntwmxstr.for:5311 */
/*<       write(stdout,50)maxnin >*/
	feq_gen_io_d__292.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__292);
	do_fio(&feq_gen_c_d_1, (char *)&(*maxnin), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ntwmxstr.for:5312 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntwmxstr.for:5313 */
/*<       endif >*/
    }
/*     PUT THE VALUES IN THE BUFFER STARTING AT IPUT */
/* SOURCE ntwmxstr.for:5317 */
/*<       buff(iput)=emcadr >*/
    buff[*iput] = *emcadr;
/* SOURCE ntwmxstr.for:5318 */
/*<       buff(iput+1)=conid >*/
    buff[*iput + 1] = *conid;
/* SOURCE ntwmxstr.for:5319 */
/*<       buff(iput+2)=point >*/
    buff[*iput + 2] = *point;
/* SOURCE ntwmxstr.for:5320 */
/*<       buff(iput+3)=nodein >*/
    buff[*iput + 3] = *nodein;
/* SOURCE ntwmxstr.for:5322 */
/*<       iput=iput+4 >*/
    *iput += 4;
/* SOURCE ntwmxstr.for:5323 */
/*<       if(iput.gt.endbuf)then >*/
    if (*iput > *endbuf) {
/*       WRAP BACK TO THE START OF THE BUFFER */
/* SOURCE ntwmxstr.for:5326 */
/*<       iput=begbuf >*/
	*iput = *begbuf;
/* SOURCE ntwmxstr.for:5327 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:5329 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:5330 */
/*<       end >*/
} /* putrec_ */




/* SOURCE ntwmxstr.for:5334 */
/*<       subroutineupdlst(rpt,node,ljoin,adr,jfree,join,flag) >*/
/* Subroutine */ int updlst_(integer *rpt, integer *node, integer *ljoin, 
	integer *adr, integer *jfree, integer *feq_storage_join, integer *feq_gen_flag_d_)
{
    integer ipnt;

/*     + + + PURPOSE + + + */
/*     Update the list of relationships for a node.  The address */
/*     for the start of the list is stored at ADR in JOIN. */
/* SOURCE ntwmxstr.for:5343 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntwmxstr.for:5345 */
/*<       integeradr,flag,jfree,ljoin,node,rpt >*/
/* SOURCE ntwmxstr.for:5346 */
/*<       integerjoin(ljoin) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     RPT    - pointer to the relationship pointer */
/*     NODE   - node number */
/*     LJOIN  - length of the junction description vector: JOIN */
/*     ADR    -  the address of the list of addresses of relationships */
/*               that reference a node. */
/*     JFREE  - free space pointer for a junction */
/*     JOIN   - vector for storing the junction descriptions */
/*     FLAG   - flag for errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntwmxstr.for:5359 */
/*<       integeripnt >*/
/* *********************************************************************** */
/* SOURCE ntwmxstr.for:5361 */
/*<       flag=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> join(feq_storage_join, 1);

    /* Function Body */
    *feq_gen_flag_d_ = 0;
/* SOURCE ntwmxstr.for:5362 */
/*<       ipnt=join(adr) >*/
    ipnt = join[*adr];
/* SOURCE ntwmxstr.for:5363 */
/*<   100 continue >*/
L100:
/* SOURCE ntwmxstr.for:5364 */
/*<       if(ipnt.eq.0)then >*/
    if (ipnt == 0) {
/*         FOUND END OF THE LIST.  ADD NEW ITEM AND PUT IN ADDRESS OF */
/*         NEW ITEM. (SINGLE LINKED LIST) */
/* SOURCE ntwmxstr.for:5368 */
/*<       join(adr)=jfree >*/
	join[*adr] = *jfree;
/*         CLEAR THE POINTER TO THE NEXT ITEM */
/* SOURCE ntwmxstr.for:5372 */
/*<       join(jfree)=0 >*/
	join[*jfree] = 0;
/*         STORE POINTER TO THE RELATIONSHIP POINTER */
/* SOURCE ntwmxstr.for:5374 */
/*<       join(jfree+1)=rpt >*/
	join[*jfree + 1] = *rpt;
/*         STORE THE NODE NUMBER FOR THE OTHER END OF THE RELATIONSHIP */
/*         NODE IS ZERO IF THERE IS NO OTHER END. */
/* SOURCE ntwmxstr.for:5377 */
/*<       join(jfree+2)=node >*/
	join[*jfree + 2] = *node;
/* SOURCE ntwmxstr.for:5379 */
/*<       jfree=jfree+3 >*/
	*jfree += 3;
/* SOURCE ntwmxstr.for:5380 */
/*<       else >*/
    } else {
/*         CHECK TO MAKE SURE THAT THE SECOND NODE IS NOT DUPLICATED */
/*         AT ANY NODE. */
/* SOURCE ntwmxstr.for:5383 */
/*<       if(join(ipnt+2).eq.node)then >*/
	if (join[ipnt + 2] == *node) {
/*           ERROR-DUPLICATE USE OF TWO NODES FOR A RELATIONSHIP. */
/* SOURCE ntwmxstr.for:5385 */
/*<       flag=flag+1 >*/
	    ++(*feq_gen_flag_d_);
/* SOURCE ntwmxstr.for:5386 */
/*<       endif >*/
	}
/*         GO TO THE NEXT ITEM IN THE LIST */
/* SOURCE ntwmxstr.for:5389 */
/*<       adr=ipnt >*/
	*adr = ipnt;
/* SOURCE ntwmxstr.for:5390 */
/*<       ipnt=join(adr) >*/
	ipnt = join[*adr];
/* SOURCE ntwmxstr.for:5391 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ntwmxstr.for:5392 */
/*<       endif >*/
    }
/* SOURCE ntwmxstr.for:5394 */
/*<       return >*/
    return 0;
/* SOURCE ntwmxstr.for:5395 */
/*<       end >*/
} /* updlst_ */

#ifdef __cplusplus
	}
#endif
