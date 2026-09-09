/* miscfeq.f -- translated by f2c (version 20240504).
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

/* COMMON eqsum_ is declared in common.hpp. */

#define eqsum_1 eqsum_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON inbr_ is declared in common.hpp. */

#define inbr_1 inbr_

/* COMMON inen_ is declared in common.hpp. */

#define inen_1 inen_

/* COMMON inenc_ is declared in common.hpp. */

#define inenc_1 inenc_

/* COMMON version_ is declared in common.hpp. */

#define version_1 version_

/* COMMON versionc_ is declared in common.hpp. */

#define versionc_1 versionc_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_2 = 2;

/* Miscellaneious routines. */


/* SOURCE miscfeq.for:4 */
/*<       subroutineeqsummary(stdout,nbn) >*/
/* Subroutine */ int eqsummary_(integer *stdout, integer *nbn)
{
    /* Format strings */
    static char fmt_1[] = "(i5,\002          Branch\002,i7,\002 Non-linea\
r\002)";
    static char fmt_2[] = "(i5,\002   Sum of Q is 0\002,i7,\002 Linear\002)";
    static char fmt_3[] = "(i5,\002     Equal elevs\002,i7,\002 Linear\002)";
    static char fmt_4[] = "(i5,\002       1-node CS\002,i7,\002 Non-linea\
r\002)";
    static char fmt_5[] = "(i5,\002       2-node CS\002,i7,\002 Non-linea\
r\002)";
    static char fmt_6[] = "(i5,\002    Forced Value\002,i7,\002 Linear\002)";
    static char fmt_7[] = "(i5,\002    Lvl Pool Res\002,i7,\002 Non-linea\
r\002)";
    static char fmt_8[] = "(i5,\002  Critical Depth\002,i7,\002 Non-linea\
r\002)";
    static char fmt_11[] = "(i5,\002  Cnsrv Mom/Elev\002,i7,\002 Non-linea\
r\002)";
    static char fmt_12[] = "(i5,\002   Mtch Avr Elev\002,i7,\002 Linear\002)";
    static char fmt_13[] = "(i5,\002  Cnsrv Mom/Engr\002,i7,\002 Non-linea\
r\002)";
    static char fmt_14[] = "(i5,\002       Side Weir\002,i7,\002 Non-linea\
r\002)";
    static char fmt_15[] = "(i5,\002    Dummy Branch\002,i7,\002 Linear\002)";
    static char fmt_50[] = "(/,\002 Summary of Equations in Network Matri\
x\002)";
    static char fmt_52[] = "(/,\002 Code     Description Num_Eq Category\002)"
	    ;
    static char fmt_54[] = "(/,\002 Number of equations=\002,i8)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, it, neq, feq_gen_feql_select1_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__2 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_1, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_2, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, fmt_3, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_4, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_5, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_6, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, fmt_7, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_8, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_11, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_12, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, fmt_13, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_14, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_15, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_54, 0 };


/*     Output a summary of the number, source, and type (linear or */
/*     non-linear) of the equations in the network matrix. */
/* SOURCE miscfeq.for:9 */
/*<       implicitnone >*/
/* SOURCE miscfeq.for:11 */
/*<       integernbn,stdout >*/
/* INCLUDE miscfeq.for:13 */
/*     Store info to make a summary of the equations types */
/*     in FEQ */
/* SOURCE eqsum.cmn:4 */
/*<       integereqsum_knt(15) >*/
/* SOURCE eqsum.cmn:6 */
/*<       common/eqsum/eqsum_knt >*/
/* SOURCE eqsum.cmn:8 */
/*<       save/eqsum/ >*/
/*     Local */
/* SOURCE miscfeq.for:18 */
/*<       integeri,it,neq >*/
/*     *****************************formats****************************** */
/* SOURCE miscfeq.for:4 */
/*<       integer feql_select1 >*/
/* SOURCE miscfeq.for:21 */
/*<     1 format(i5,'          Branch',i7,' Non-linear') >*/
/* SOURCE miscfeq.for:22 */
/*<     2 format(i5,'   Sum of Q is 0',i7,' Linear') >*/
/* SOURCE miscfeq.for:23 */
/*<     3 format(i5,'     Equal elevs',i7,' Linear') >*/
/* SOURCE miscfeq.for:24 */
/*<     4 format(i5,'       1-node CS',i7,' Non-linear') >*/
/* SOURCE miscfeq.for:25 */
/*<     5 format(i5,'       2-node CS',i7,' Non-linear') >*/
/* SOURCE miscfeq.for:26 */
/*<     6 format(i5,'    Forced Value',i7,' Linear') >*/
/* SOURCE miscfeq.for:27 */
/*<     7 format(i5,'    Lvl Pool Res',i7,' Non-linear') >*/
/* SOURCE miscfeq.for:28 */
/*<     8 format(i5,'  Critical Depth',i7,' Non-linear') >*/
/* SOURCE miscfeq.for:29 */
/*<    11 format(i5,'  Cnsrv Mom/Elev',i7,' Non-linear') >*/
/* SOURCE miscfeq.for:30 */
/*<    12 format(i5,'   Mtch Avr Elev',i7,' Linear') >*/
/* SOURCE miscfeq.for:31 */
/*<    13 format(i5,'  Cnsrv Mom/Engr',i7,' Non-linear') >*/
/* SOURCE miscfeq.for:32 */
/*<    14 format(i5,'       Side Weir',i7,' Non-linear') >*/
/* SOURCE miscfeq.for:33 */
/*<    15 format(i5,'    Dummy Branch',i7,' Linear') >*/
/* SOURCE miscfeq.for:35 */
/*<    50 format(/,' Summary of Equations in Network Matrix') >*/
/* SOURCE miscfeq.for:36 */
/*<    52 format(/,' Code     Description Num_Eq Category') >*/
/* SOURCE miscfeq.for:37 */
/*<    54 format(/,' Number of equations=',i8) >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:41 */
/*<       write(stdout,50) >*/
/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L6: */
/* L7: */
/* L8: */
/* L11: */
/* L12: */
/* L13: */
/* L14: */
/* L15: */
/* L50: */
/* L52: */
/* L54: */
    feq_gen_io_d__1.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__1);
    e_wsfe();
/* SOURCE miscfeq.for:42 */
/*<       write(stdout,52) >*/
    feq_gen_io_d__2.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__2);
    e_wsfe();
/*     Output in the code order and add info for each */
/* SOURCE miscfeq.for:46 */
/*<       neq=0 >*/
    neq = 0;
/* SOURCE miscfeq.for:47 */
/*<       doi=1,15 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 15; ++feq_gen_i_d_) {
/* SOURCE miscfeq.for:49 */
/*<       feql_select1=i >*/
	feq_gen_feql_select1_d_ = feq_gen_i_d_;
/* SOURCE miscfeq.for:49 */
/*<       if(feql_select1.eq.1)then >*/
	if (feq_gen_feql_select1_d_ == 1) {
/*           Branch equations.  2 per comp element. */
/* SOURCE miscfeq.for:53 */
/*<       it=2*(nbn-eqsum_knt(1)) >*/
	    it = *nbn - eqsum_1.feq_gen_eqsum_knt_d_[0] << 1;
/* SOURCE miscfeq.for:54 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:55 */
/*<       write(stdout,1)i,it >*/
	    feq_gen_io_d__7.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__7);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.2)then >*/
	} else if (feq_gen_feql_select1_d_ == 2) {
/*           Sum of flows is zero */
/* SOURCE miscfeq.for:59 */
/*<       it=eqsum_knt(2) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[1];
/* SOURCE miscfeq.for:60 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:61 */
/*<       write(stdout,2)i,it >*/
	    feq_gen_io_d__8.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__8);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.3)then >*/
	} else if (feq_gen_feql_select1_d_ == 3) {
/*           Equal elevations */
/* SOURCE miscfeq.for:65 */
/*<       it=eqsum_knt(3) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[2];
/* SOURCE miscfeq.for:66 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:67 */
/*<       write(stdout,3)i,it >*/
	    feq_gen_io_d__9.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__9);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.4)then >*/
	} else if (feq_gen_feql_select1_d_ == 4) {
/*           1-node CS */
/* SOURCE miscfeq.for:71 */
/*<       it=eqsum_knt(4) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[3];
/* SOURCE miscfeq.for:72 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:73 */
/*<       write(stdout,4)i,it >*/
	    feq_gen_io_d__10.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__10);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.5)then >*/
	} else if (feq_gen_feql_select1_d_ == 5) {
/*           2-node CS */
/* SOURCE miscfeq.for:77 */
/*<       it=eqsum_knt(5) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[4];
/* SOURCE miscfeq.for:78 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:79 */
/*<       write(stdout,5)i,it >*/
	    feq_gen_io_d__11.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__11);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.6)then >*/
	} else if (feq_gen_feql_select1_d_ == 6) {
/*           Forced value */
/* SOURCE miscfeq.for:83 */
/*<       it=eqsum_knt(6) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[5];
/* SOURCE miscfeq.for:84 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:85 */
/*<       write(stdout,6)i,it >*/
	    feq_gen_io_d__12.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__12);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.7)then >*/
	} else if (feq_gen_feql_select1_d_ == 7) {
/*           Level-pool reservoir */
/* SOURCE miscfeq.for:89 */
/*<       it=eqsum_knt(7)*2 >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[6] << 1;
/* SOURCE miscfeq.for:90 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:91 */
/*<       write(stdout,7)i,it >*/
	    feq_gen_io_d__13.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__13);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.8)then >*/
	} else if (feq_gen_feql_select1_d_ == 8) {
/*           Critical depth */
/* SOURCE miscfeq.for:95 */
/*<       it=eqsum_knt(8) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[7];
/* SOURCE miscfeq.for:96 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:97 */
/*<       write(stdout,8)i,it >*/
	    feq_gen_io_d__14.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__14);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.9)then >*/
	} else if (feq_gen_feql_select1_d_ == 9) {
/*           Unused */
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.10)then >*/
	} else if (feq_gen_feql_select1_d_ == 10) {
/*           Unused */
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.11)then >*/
	} else if (feq_gen_feql_select1_d_ == 11) {
/*           mom/elev */
/* SOURCE miscfeq.for:107 */
/*<       it=eqsum_knt(11) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[10];
/* SOURCE miscfeq.for:108 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:109 */
/*<       write(stdout,11)i,it >*/
	    feq_gen_io_d__15.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__15);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.12)then >*/
	} else if (feq_gen_feql_select1_d_ == 12) {
/*           Average elev */
/* SOURCE miscfeq.for:113 */
/*<       it=eqsum_knt(12) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[11];
/* SOURCE miscfeq.for:114 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:115 */
/*<       write(stdout,12)i,it >*/
	    feq_gen_io_d__16.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__16);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.13)then >*/
	} else if (feq_gen_feql_select1_d_ == 13) {
/*           mom/energy */
/* SOURCE miscfeq.for:119 */
/*<       it=eqsum_knt(13) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[12];
/* SOURCE miscfeq.for:120 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:121 */
/*<       write(stdout,13)i,it >*/
	    feq_gen_io_d__17.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__17);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.14)then >*/
	} else if (feq_gen_feql_select1_d_ == 14) {
/*           side weir */
/* SOURCE miscfeq.for:125 */
/*<       it=eqsum_knt(14) >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[13];
/* SOURCE miscfeq.for:126 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:127 */
/*<       write(stdout,14)i,it >*/
	    feq_gen_io_d__18.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__18);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:49 */
/*<       elseif(feql_select1.eq.15)then >*/
	} else if (feq_gen_feql_select1_d_ == 15) {
/*           mom/elev */
/* SOURCE miscfeq.for:131 */
/*<       it=eqsum_knt(15)*2 >*/
	    it = eqsum_1.feq_gen_eqsum_knt_d_[14] << 1;
/* SOURCE miscfeq.for:132 */
/*<       neq=neq+it >*/
	    neq += it;
/* SOURCE miscfeq.for:133 */
/*<       write(stdout,15)i,it >*/
	    feq_gen_io_d__19.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__19);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE miscfeq.for:135 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:136 */
/*<       enddo >*/
    }
/* SOURCE miscfeq.for:138 */
/*<       write(stdout,54)neq >*/
    feq_gen_io_d__20.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__20);
    do_fio(&feq_gen_c_d_1, (char *)&neq, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE miscfeq.for:140 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:142 */
/*<       end >*/
} /* eqsummary_ */




/* SOURCE miscfeq.for:146 */
/*<       subroutineoutpro(stdout) >*/
/* Subroutine */ int outpro_(integer *stdout)
{
    /* Format strings */
    static char fmt_50[] = "(\002 INDEX     VALUE\002)";
    static char fmt_52[] = "(i6,1pe10.3)";
    static char fmt_54[] = "(\002 INDEX       RHS\002)";
    static char fmt_56[] = "(i6,1pe10.3)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, 
	    ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__21 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__24 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__26 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Output the profile form of the matrix. */
/* SOURCE miscfeq.for:152 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:154 */
/*<       integerstdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE miscfeq.for:160 */
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
/* INCLUDE miscfeq.for:161 */
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
/* SOURCE miscfeq.for:164 */
/*<       integeri >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE miscfeq.for:167 */
/*<    50 format(' INDEX     VALUE') >*/
/* SOURCE miscfeq.for:168 */
/*<    52 format(i6,1pe10.3) >*/
/* SOURCE miscfeq.for:169 */
/*<    54 format(' INDEX       RHS') >*/
/* SOURCE miscfeq.for:170 */
/*<    56 format(i6,1pe10.3) >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:172 */
/*<       write(stdout,*)' ' >*/
/* L50: */
/* L52: */
/* L54: */
/* L56: */
    feq_gen_io_d__21.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__21);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE miscfeq.for:173 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__22.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__22);
    e_wsfe();
/* SOURCE miscfeq.for:175 */
/*<       do100i=1,c(numeq) >*/
    feq_gen_i_d_1 = matcom_1.feq_gen_c_d_[matcom_1.numeq];
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE miscfeq.for:176 */
/*<       write(stdout,52)i,pdavec(i) >*/
	feq_gen_io_d__24.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__24);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&matcom_1.pdavec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real))
		;
	e_wsfe();
/* SOURCE miscfeq.for:177 */
/*<   100 continue >*/
/* L100: */
    }
/*     OUTPUT THE RHS */
/* SOURCE miscfeq.for:180 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__25.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__25);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE miscfeq.for:181 */
/*<       write(stdout,54) >*/
    feq_gen_io_d__26.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__26);
    e_wsfe();
/* SOURCE miscfeq.for:182 */
/*<       do110i=1,numeq >*/
    feq_gen_i_d_1 = matcom_1.numeq;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE miscfeq.for:183 */
/*<       write(stdout,56)i,rhs(i) >*/
	feq_gen_io_d__27.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__27);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&matcom_1.rhs[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE miscfeq.for:184 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE miscfeq.for:186 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__28.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__28);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE miscfeq.for:187 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:188 */
/*<       end >*/
} /* outpro_ */




/* SOURCE miscfeq.for:192 */
/*<       subroutinefbrnd(innode,nbra,brpt,stdout,bra,node) >*/
/* Subroutine */ int fbrnd_(integer *innode, integer *nbra, integer *feq_storage_brpt, 
	integer *stdout, integer *bra, integer *node)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:19* ERROR IN BRPT OR INNODE DETECTE\
D IN FBRND.\002)";
    static char fmt_51[] = "(i6,i5,/(6i10))";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, ib;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Find the external branch and external node for a */
/*     given internal node number for the branch vectors */
/* SOURCE miscfeq.for:200 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:202 */
/*<       integerbra,innode,stdout,nbra,node >*/
/* SOURCE miscfeq.for:203 */
/*<       integerbrpt(8,nbra) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     INNODE - internal node number for a node on a branch */
/*     NBRA   - number of branches in the model */
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
/*     STDOUT   - Fortran unit number for user output and messages */
/*     BRA    - branch number */
/*     NODE   - node number */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:223 */
/*<       integeri,ib,j >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE miscfeq.for:226 */
/*<    50 format(/,' *BUG:19* ERROR IN BRPT OR INNODE DETECTED IN FBRND.') >*/
/* SOURCE miscfeq.for:227 */
/*<    51 format(i6,i5,/(6i10)) >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:229 */
/*<       do100ib=1,nbra >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* L50: */
/* L51: */
    feq_gen_i_d_1 = *nbra;
    for (ib = 1; ib <= feq_gen_i_d_1; ++ib) {
/* SOURCE miscfeq.for:230 */
/*<       if(innode.ge.brpt(3,ib).and.innode.le.brpt(4,ib))then >*/
	if (*innode >= brpt[(ib << 3) + 3] && *innode <= brpt[(ib << 3) + 4]) 
		{
/*         FOUND THE BRANCH */
/* SOURCE miscfeq.for:233 */
/*<       node=brpt(1,ib)+innode-brpt(3,ib) >*/
	    *node = brpt[(ib << 3) + 1] + *innode - brpt[(ib << 3) + 3];
/* SOURCE miscfeq.for:234 */
/*<       bra=ib >*/
	    *bra = ib;
/* SOURCE miscfeq.for:235 */
/*<       return >*/
	    return 0;
/* SOURCE miscfeq.for:236 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:237 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE miscfeq.for:239 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__30.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__30);
    e_wsfe();
/* SOURCE miscfeq.for:240 */
/*<       write(stdout,51)innode,nbra,((brpt(i,j),i=1,6),j=1,nbra) >*/
    feq_gen_io_d__31.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__31);
    do_fio(&feq_gen_c_d_1, (char *)&(*innode), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&(*nbra), (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = *nbra;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 6; ++feq_gen_i_d_) {
	    do_fio(&feq_gen_c_d_1, (char *)&brpt[feq_gen_i_d_ + (j << 3)], (ftnlen)sizeof(
		    integer));
	}
    }
    e_wsfe();
/* SOURCE miscfeq.for:241 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE miscfeq.for:242 */
/*<       end >*/
    return 0;
} /* fbrnd_ */




/* SOURCE miscfeq.for:246 */
/*<       realfunctionfmnarg(adrs) >*/
doublereal fmnarg_(integer *adrs)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX* FMNARG INVALID WITH 2-D TABLE. T\
AB#=\002,i5,\002 IS A 2-D TABLE.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real ret_val;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer gettbn_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the minimum argument for the table stored at ADRS. */
/* SOURCE miscfeq.for:252 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:254 */
/*<       integeradrs >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE miscfeq.for:260 */
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
/* INCLUDE miscfeq.for:261 */
/* ********************************************************************** */
/* SOURCE ftable.cmn:2 */
/*<       common/ftable/dtab >*/
/* SOURCE ftable.cmn:3 */
/*<       common/ftablea/longdummy,itmp,knt_of_ftabs,ftpnt >*/
/* SOURCE ftable.cmn:4 */
/*<       common/ftablec/ft_loc_status >*/
/* SOURCE ftable.cmn:6 */
/*<       integerftpnt(mftnum+5) >*/
/* SOURCE ftable.cmn:7 */
/*<       character*1ft_loc_status(mftnum) >*/
/* SOURCE ftable.cmn:9 */
/*<       realftab(0:mrftab) >*/
/* SOURCE ftable.cmn:10 */
/*<       real*8dtab(0:mdftab) >*/
/* SOURCE ftable.cmn:12 */
/*<       real*8longdummy >*/
/* SOURCE ftable.cmn:14 */
/*<       integeritmp,itab(0:mrftab),knt_of_ftabs >*/
/* SOURCE ftable.cmn:16 */
/*<       realrtmp >*/
/* SOURCE ftable.cmn:18 */
/*<       equivalence(dtab,ftab,itab) >*/
/* SOURCE ftable.cmn:19 */
/*<       equivalence(itmp,rtmp) >*/
/* SOURCE ftable.cmn:21 */
/*<       save/ftable/,/ftablea/,/ftablec/ >*/
/* ********************************************************************** */
/* INCLUDE miscfeq.for:262 */
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
/* SOURCE miscfeq.for:265 */
/*<       integertype >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE miscfeq.for:268 */
/*<       integergettbn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE miscfeq.for:271 */
/*<       externalgettbn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE miscfeq.for:274 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:277 */
/*<       type=itab(adrs+2) >*/
/* L50: */
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE miscfeq.for:278 */
/*<       if(type.eq.6.or.type.eq.10.or.type.eq.13.or.type.eq.14)then >*/
    if (feq_gen_type_d_ == 6 || feq_gen_type_d_ == 10 || feq_gen_type_d_ == 13 || feq_gen_type_d_ == 14) {
/* SOURCE miscfeq.for:279 */
/*<       write(std6,50)gettbn(adrs) >*/
	feq_gen_io_d__38.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__38);
	feq_gen_i_d_1 = gettbn_(adrs);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE miscfeq.for:280 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE miscfeq.for:281 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:282 */
/*<       if(type.eq.1.or.type.eq.12.or.(type.ge.20.and.type.le.25))then >*/
	if (feq_gen_type_d_ == 1 || feq_gen_type_d_ == 12 || feq_gen_type_d_ >= 20 && feq_gen_type_d_ <= 25) {
/*         CROSS SECTION TABLE */
/* SOURCE miscfeq.for:285 */
/*<       fmnarg=0.0 >*/
	    ret_val = (float)0.;
/* SOURCE miscfeq.for:286 */
/*<       else >*/
	} else {
/*         TABLE OF TYPE 2, 3, 4, OR 11 AT THIS POINT */
/* SOURCE miscfeq.for:288 */
/*<       fmnarg=ftab(adrs+off234) >*/
	    ret_val = ftab[*adrs + 22];
/* SOURCE miscfeq.for:289 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:290 */
/*<       return >*/
	return ret_val;
/* SOURCE miscfeq.for:291 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:292 */
/*<       end >*/
    return ret_val;
} /* fmnarg_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE miscfeq.for:296 */
/*<       subroutinefndelv(num,stdout,eflag,elev) >*/
/* Subroutine */ int fndelv_(integer *num, integer *stdout, integer *eflag, 
	real *elev)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:198* Cross sec. table Id= \002,a\
,\002 not found for\002,\002 elevation.\002)";
    static char fmt_52[] = "(/,\002 *BUG:XXX* NUM < 0 in sub. FNDELV.\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer adrs;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the invert elevation of the cross section from the table */
/*     given by the table number in NUM. */
/* SOURCE miscfeq.for:304 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:306 */
/*<       integereflag,stdout,num >*/
/* SOURCE miscfeq.for:307 */
/*<       realelev >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NUM    - table number */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     ELEV   - value of elevation */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE miscfeq.for:316 */
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
/* INCLUDE miscfeq.for:317 */
/* ********************************************************************** */
/* SOURCE ftable.cmn:2 */
/*<       common/ftable/dtab >*/
/* SOURCE ftable.cmn:3 */
/*<       common/ftablea/longdummy,itmp,knt_of_ftabs,ftpnt >*/
/* SOURCE ftable.cmn:4 */
/*<       common/ftablec/ft_loc_status >*/
/* SOURCE ftable.cmn:6 */
/*<       integerftpnt(mftnum+5) >*/
/* SOURCE ftable.cmn:7 */
/*<       character*1ft_loc_status(mftnum) >*/
/* SOURCE ftable.cmn:9 */
/*<       realftab(0:mrftab) >*/
/* SOURCE ftable.cmn:10 */
/*<       real*8dtab(0:mdftab) >*/
/* SOURCE ftable.cmn:12 */
/*<       real*8longdummy >*/
/* SOURCE ftable.cmn:14 */
/*<       integeritmp,itab(0:mrftab),knt_of_ftabs >*/
/* SOURCE ftable.cmn:16 */
/*<       realrtmp >*/
/* SOURCE ftable.cmn:18 */
/*<       equivalence(dtab,ftab,itab) >*/
/* SOURCE ftable.cmn:19 */
/*<       equivalence(itmp,rtmp) >*/
/* SOURCE ftable.cmn:21 */
/*<       save/ftable/,/ftablea/,/ftablec/ >*/
/* ********************************************************************** */
/*     External program units */
/* SOURCE miscfeq.for:320 */
/*<       characterget_tabid*16 >*/
/* SOURCE miscfeq.for:321 */
/*<       externalget_tabid >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:324 */
/*<       integeradrs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE miscfeq.for:327 */
/*<    50  >*/
/* SOURCE miscfeq.for:329 */
/*<    52 format(/,' *BUG:XXX* NUM < 0 in sub. FNDELV.') >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:331 */
/*<       if(num.le.0)then >*/
/* L50: */
/* L52: */
    if (*num <= 0) {
/* SOURCE miscfeq.for:332 */
/*<       write(stdout,52)num >*/
	feq_gen_io_d__42.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__42);
	do_fio(&feq_gen_c_d_1, (char *)&(*num), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE miscfeq.for:333 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE miscfeq.for:334 */
/*<       elev=0.0 >*/
	*elev = (float)0.;
/* SOURCE miscfeq.for:335 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:336 */
/*<       adrs=ftpnt(num) >*/
	adrs = ftablea_1.ftpnt[*num - 1];
/* SOURCE miscfeq.for:337 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/* SOURCE miscfeq.for:338 */
/*<       elev=ftab(adrs+5) >*/
	    *elev = ftab[adrs + 5];
/* SOURCE miscfeq.for:339 */
/*<       else >*/
	} else {
/*         TABLE DOES NOT EXIST */
/* SOURCE miscfeq.for:342 */
/*<       write(stdout,50)get_tabid(num) >*/
	    feq_gen_io_d__44.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__44);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, num);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE miscfeq.for:343 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE miscfeq.for:344 */
/*<       elev=0.0 >*/
	    *elev = (float)0.;
/* SOURCE miscfeq.for:345 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:346 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:347 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:348 */
/*<       end >*/
} /* fndelv_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE miscfeq.for:354 */
/*<       subroutinefind_hdd_from_tabn(tabn,stdout,status,hdatum) >*/
/* Subroutine */ int feq_gen_find_hdd_from_tabn_d_(integer *tabn, integer *stdout, 
	integer *status, real *hdatum)
{
    /* Format strings */
    static char fmt_52[] = "(/,\002 *BUG:XXX* NUM < 0 in sub. FIND_HDD_FROM_\
TABN.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer adrs;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern doublereal gethdd_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_52, 0 };


/*     Find the head datum for a two-D table given the table number. */
/* SOURCE miscfeq.for:360 */
/*<       implicitnone >*/
/* SOURCE miscfeq.for:361 */
/*<       integertabn,stdout,status >*/
/* SOURCE miscfeq.for:363 */
/*<       realhdatum >*/
/*     Called program units */
/* SOURCE miscfeq.for:366 */
/*<       realgethdd >*/
/* SOURCE miscfeq.for:367 */
/*<       externalgethdd >*/
/*     Local */
/* SOURCE miscfeq.for:370 */
/*<       integeradrs >*/
/* INCLUDE miscfeq.for:372 */
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
/* INCLUDE miscfeq.for:373 */
/* ********************************************************************** */
/* SOURCE ftable.cmn:2 */
/*<       common/ftable/dtab >*/
/* SOURCE ftable.cmn:3 */
/*<       common/ftablea/longdummy,itmp,knt_of_ftabs,ftpnt >*/
/* SOURCE ftable.cmn:4 */
/*<       common/ftablec/ft_loc_status >*/
/* SOURCE ftable.cmn:6 */
/*<       integerftpnt(mftnum+5) >*/
/* SOURCE ftable.cmn:7 */
/*<       character*1ft_loc_status(mftnum) >*/
/* SOURCE ftable.cmn:9 */
/*<       realftab(0:mrftab) >*/
/* SOURCE ftable.cmn:10 */
/*<       real*8dtab(0:mdftab) >*/
/* SOURCE ftable.cmn:12 */
/*<       real*8longdummy >*/
/* SOURCE ftable.cmn:14 */
/*<       integeritmp,itab(0:mrftab),knt_of_ftabs >*/
/* SOURCE ftable.cmn:16 */
/*<       realrtmp >*/
/* SOURCE ftable.cmn:18 */
/*<       equivalence(dtab,ftab,itab) >*/
/* SOURCE ftable.cmn:19 */
/*<       equivalence(itmp,rtmp) >*/
/* SOURCE ftable.cmn:21 */
/*<       save/ftable/,/ftablea/,/ftablec/ >*/
/* ********************************************************************** */
/*     *********************************FORMATS************************** */
/* SOURCE miscfeq.for:375 */
/*<    52 format(/,' *BUG:XXX* NUM < 0 in sub. FIND_HDD_FROM_TABN.') >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:377 */
/*<       if(tabn.le.0)then >*/
/* L52: */
    if (*tabn <= 0) {
/* SOURCE miscfeq.for:378 */
/*<       write(stdout,52)tabn >*/
	feq_gen_io_d__48.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__48);
	do_fio(&feq_gen_c_d_1, (char *)&(*tabn), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE miscfeq.for:379 */
/*<       stop'Abnormal stop.  Bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE miscfeq.for:380 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:381 */
/*<       adrs=ftpnt(tabn) >*/
	adrs = ftablea_1.ftpnt[*tabn - 1];
/* SOURCE miscfeq.for:382 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/* SOURCE miscfeq.for:383 */
/*<       status=1 >*/
	    *status = 1;
/* SOURCE miscfeq.for:384 */
/*<       hdatum=gethdd(adrs) >*/
	    *hdatum = gethdd_(&adrs);
/* SOURCE miscfeq.for:385 */
/*<       else >*/
	} else {
/*         TABLE DOES NOT EXIST */
/* SOURCE miscfeq.for:387 */
/*<       hdatum=-1.e30 >*/
	    *hdatum = (float)-1e30;
/* SOURCE miscfeq.for:388 */
/*<       status=0 >*/
	    *status = 0;
/* SOURCE miscfeq.for:389 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:390 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:391 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:392 */
/*<       end >*/
} /* find_hdd_from_tabn__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE miscfeq.for:397 */
/*<       subroutinefndgisid(num,stdout,eflag,gisid) >*/
/* Subroutine */ int fndgisid_(integer *num, integer *stdout, integer *eflag, 
	char *gisid, ftnlen gisid_len)
{
    /* Format strings */
    static char fmt_52[] = "(/,\002 *BUG:XXX* NUM < 0 in sub. FNDELV.\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_gisid_d_(char *, ftnlen, integer *);
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer adrs;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Find the GISID string of the cross section from the table */
/*     given by the table number in NUM. */
/* SOURCE miscfeq.for:405 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:407 */
/*<       integereflag,stdout,num >*/
/* SOURCE miscfeq.for:408 */
/*<       character*16gisid >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NUM    - table number */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     GISID  - GISID string for the cross section.  Any id the user */
/*              gives. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE miscfeq.for:418 */
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
/* INCLUDE miscfeq.for:419 */
/* ********************************************************************** */
/* SOURCE ftable.cmn:2 */
/*<       common/ftable/dtab >*/
/* SOURCE ftable.cmn:3 */
/*<       common/ftablea/longdummy,itmp,knt_of_ftabs,ftpnt >*/
/* SOURCE ftable.cmn:4 */
/*<       common/ftablec/ft_loc_status >*/
/* SOURCE ftable.cmn:6 */
/*<       integerftpnt(mftnum+5) >*/
/* SOURCE ftable.cmn:7 */
/*<       character*1ft_loc_status(mftnum) >*/
/* SOURCE ftable.cmn:9 */
/*<       realftab(0:mrftab) >*/
/* SOURCE ftable.cmn:10 */
/*<       real*8dtab(0:mdftab) >*/
/* SOURCE ftable.cmn:12 */
/*<       real*8longdummy >*/
/* SOURCE ftable.cmn:14 */
/*<       integeritmp,itab(0:mrftab),knt_of_ftabs >*/
/* SOURCE ftable.cmn:16 */
/*<       realrtmp >*/
/* SOURCE ftable.cmn:18 */
/*<       equivalence(dtab,ftab,itab) >*/
/* SOURCE ftable.cmn:19 */
/*<       equivalence(itmp,rtmp) >*/
/* SOURCE ftable.cmn:21 */
/*<       save/ftable/,/ftablea/,/ftablec/ >*/
/* ********************************************************************** */
/*     External program units */
/* SOURCE miscfeq.for:422 */
/*<       characterget_gisid*16 >*/
/* SOURCE miscfeq.for:423 */
/*<       externalget_gisid >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:426 */
/*<       integeradrs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE miscfeq.for:429 */
/*<    52 format(/,' *BUG:XXX* NUM < 0 in sub. FNDELV.') >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:431 */
/*<       if(num.le.0)then >*/
/* L52: */
    if (*num <= 0) {
/* SOURCE miscfeq.for:432 */
/*<       write(stdout,52)num >*/
	feq_gen_io_d__53.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__53);
	do_fio(&feq_gen_c_d_1, (char *)&(*num), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE miscfeq.for:433 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE miscfeq.for:434 */
/*<       gisid=' ' >*/
	s_copy(gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE miscfeq.for:435 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:436 */
/*<       adrs=ftpnt(num) >*/
	adrs = ftablea_1.ftpnt[*num - 1];
/* SOURCE miscfeq.for:437 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/* SOURCE miscfeq.for:438 */
/*<       gisid=get_gisid(adrs) >*/
	    feq_gen_get_gisid_d_(feq_gen_ch_d_1, (ftnlen)16, &adrs);
	    s_copy(gisid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE miscfeq.for:439 */
/*<       else >*/
	} else {
/* SOURCE miscfeq.for:440 */
/*<       gisid=' ' >*/
	    s_copy(gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE miscfeq.for:441 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:442 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:443 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:444 */
/*<       end >*/
} /* fndgisid_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE miscfeq.for:448 */
/*<       realfunctionfroude(adrs,y,q,a,t,g) >*/
doublereal froude_(integer *adrs, real *y, real *q, real *a, real *t, real *g)
{
    /* Initialized data */

    static integer vtype[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	    0,0,1,0,0,0,0,0,0,0,0,0,0 };

    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    real qc, ya;
    extern /* Subroutine */ int lktqc_(integer *, real *, real *);
    extern integer gettyp_(integer *);

/*     + + + PURPOSE + + + */
/*     Find the square of the froude number for output. */
/* SOURCE miscfeq.for:454 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:456 */
/*<       integeradrs >*/
/* SOURCE miscfeq.for:457 */
/*<       reala,g,q,t,y >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     Y      - maximum depth in section */
/*     Q      - flow rate */
/*     A      - Area of flow */
/*     T      - top width of the cross section */
/*     G      - acceleration due to gravity */
/*     + + + SAVED VALUES + + + */
/* SOURCE miscfeq.for:468 */
/*<       integervtype(35) >*/
/* SOURCE miscfeq.for:469 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:472 */
/*<       realqc,ya >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE miscfeq.for:475 */
/*<       integergettyp >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE miscfeq.for:478 */
/*<       externalgettyp,lktqc >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/*     CHECK THE TABLE TYPE.  IF CRITICAL FLOW IS IN THE TABLE USE IT. */
/*     OTHERWISE IGNORE THE EFFECT OF NON-UNIFORM VELOCITY DISTRIBUTION */
/*     IN COMPUTING THE FROUDE NUMBER */
/* SOURCE miscfeq.for:481 */
/*<       datavtype/21*0,1,0,0,1,10*0/ >*/
/* SOURCE miscfeq.for:488 */
/*<       ya=y >*/
    ya = *y;
/* SOURCE miscfeq.for:489 */
/*<       if(vtype(gettyp(adrs)).eq.1)then >*/
    if (vtype[gettyp_(adrs) - 1] == 1) {
/*       CRITICAL FLOW IS TABULATED.  FIND IT */
/* SOURCE miscfeq.for:492 */
/*<       calllktqc(adrs,ya,qc) >*/
	lktqc_(adrs, &ya, &qc);
/* SOURCE miscfeq.for:497 */
/*<       froude=(q/qc)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(*q) / qc;
	ret_val = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE miscfeq.for:498 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:499 */
/*<       froude=q**2*t/(g*a**3) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = *q;
/* Computing 3rd power */
	feq_gen_r_d_2 = *a;
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * *t) / (static_cast<double>(*g) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)));
/* SOURCE miscfeq.for:500 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:501 */
/*<       return >*/
    return ret_val;
/* SOURCE miscfeq.for:502 */
/*<       end >*/
} /* froude_ */




/* SOURCE miscfeq.for:506 */
/*<       character*5functiongetusn(inn) >*/
/* Character */ VOID getusn_(char *ret_val, ftnlen ret_val_len, integer *inn)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     + + + PURPOSE + + + */
/*     Get the id string for a user node given the internal node number. */
/* SOURCE miscfeq.for:512 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:514 */
/*<       integerinn >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     INN    - internal exterior node number */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE miscfeq.for:520 */
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
/* INCLUDE miscfeq.for:521 */
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
/* SOURCE miscfeq.for:523 */
/*<       if(inn.eq.0)then >*/
    if (*inn == 0) {
/* SOURCE miscfeq.for:524 */
/*<       getusn='    0' >*/
	s_copy(ret_val, const_cast<char*>("    0"), (ftnlen)5, (ftnlen)5);
/* SOURCE miscfeq.for:525 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:526 */
/*<       getusn=inenus(inn) >*/
	s_copy(ret_val, inenc_1.inenus + (*inn - 1) * 5, (ftnlen)5, (ftnlen)5)
		;
/* SOURCE miscfeq.for:527 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:528 */
/*<       return >*/
    return ;
/* SOURCE miscfeq.for:529 */
/*<       end >*/
} /* getusn_ */




/* SOURCE miscfeq.for:533 */
/*<       subroutineiasort(n,x) >*/
/* Subroutine */ int iasort_(integer *n, integer *feq_storage_x)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, j, t;

/*     + + + PURPOSE + + + */
/*     Sort the integer array, X(*), of length N into ascending */
/*     numerical order. */
/* SOURCE miscfeq.for:541 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:543 */
/*<       integern >*/
/* SOURCE miscfeq.for:544 */
/*<       integerx(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - number of items to sort */
/*     X      - values to sort */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:551 */
/*<       integeri,j,t >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:553 */
/*<       do200i=2,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> x(feq_storage_x, 1);

    /* Function Body */
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE miscfeq.for:554 */
/*<       j=i >*/
	j = feq_gen_i_d_;
/* SOURCE miscfeq.for:555 */
/*<       t=x(j) >*/
	t = x[j];
/* SOURCE miscfeq.for:556 */
/*<   100 continue >*/
L100:
/* SOURCE miscfeq.for:557 */
/*<       if(j.gt.1)then >*/
	if (j > 1) {
/* SOURCE miscfeq.for:558 */
/*<       if(x(j-1).gt.t)then >*/
	    if (x[j - 1] > t) {
/* SOURCE miscfeq.for:559 */
/*<       x(j)=x(j-1) >*/
		x[j] = x[j - 1];
/* SOURCE miscfeq.for:560 */
/*<       j=j-1 >*/
		--j;
/* SOURCE miscfeq.for:561 */
/*<       goto100 >*/
		goto L100;
/* SOURCE miscfeq.for:562 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:563 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:564 */
/*<       x(j)=t >*/
	x[j] = t;
/* SOURCE miscfeq.for:565 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE miscfeq.for:567 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:568 */
/*<       end >*/
} /* iasort_ */




/* SOURCE miscfeq.for:572 */
/*<       character*5functionmakenn(prefix,num) >*/
/* Character */ VOID makenn_(char *ret_val, ftnlen ret_val_len, char *prefix, 
	integer *num, ftnlen prefix_len)
{
    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, is;
    char chr5[5];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__64 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Given the branch number and the prefix construct a valid */
/*     exterior node id for the new input style. */
/* SOURCE miscfeq.for:579 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:581 */
/*<       integernum >*/
/* SOURCE miscfeq.for:582 */
/*<       characterprefix*1 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     PREFIX - prefix for an exterior node label */
/*     NUM    - branch number */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE miscfeq.for:589 */
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
/* SOURCE miscfeq.for:592 */
/*<       integeri,is >*/
/* SOURCE miscfeq.for:593 */
/*<       characterchr5*5 >*/
/* *********************************************************************** */
/*     VALID NAME MUST BE THE CHARACTER FORM OF THE USER BRANCH */
/*     NUMBER PREFIXED BY THE PREFIX CHARACTER.  NO SPACES ALLOWED */
/*     IN THE ID AND THE ID SHOULD BE RIGHT JUSTIFIED IN THE STRING. */
/* SOURCE miscfeq.for:599 */
/*<       write(chr5,'(I5)')num >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = chr5;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*num), (ftnlen)sizeof(integer));
    e_wsfi();
/*     SEARCH FOR SPACE FROM END OF STRING */
/* SOURCE miscfeq.for:601 */
/*<       is=0 >*/
    is = 0;
/* SOURCE miscfeq.for:602 */
/*<       do100i=4,1,-1 >*/
    for (feq_gen_i_d_ = 4; feq_gen_i_d_ >= 1; --feq_gen_i_d_) {
/* SOURCE miscfeq.for:603 */
/*<       if(chr5(i:i).eq.' ')then >*/
	if (*(unsigned char *)&chr5[feq_gen_i_d_ - 1] == ' ') {
/* SOURCE miscfeq.for:604 */
/*<       is=i >*/
	    is = feq_gen_i_d_;
/* SOURCE miscfeq.for:605 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE miscfeq.for:606 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:607 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE miscfeq.for:609 */
/*<       if(is.eq.0.and.prefix.ne.' ')then >*/
    if (is == 0 && *(unsigned char *)prefix != ' ') {
/* SOURCE miscfeq.for:610 */
/*<       write(std6,*)' *BUG:XXX* IS=0 IN MAKENN' >*/
	feq_gen_io_d__64.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__64);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* IS=0 IN MAKENN"), (ftnlen)25);
	e_wsle();
/* SOURCE miscfeq.for:611 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE miscfeq.for:612 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:613 */
/*<       makenn=chr5 >*/
	s_copy(ret_val, chr5, (ftnlen)5, (ftnlen)5);
/* SOURCE miscfeq.for:614 */
/*<       return >*/
	return ;
/* SOURCE miscfeq.for:615 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:616 */
/*<   110 continue >*/
L110:
/* SOURCE miscfeq.for:617 */
/*<       chr5(is:is)=prefix >*/
    *(unsigned char *)&chr5[is - 1] = *(unsigned char *)prefix;
/* SOURCE miscfeq.for:618 */
/*<       makenn=chr5 >*/
    s_copy(ret_val, chr5, (ftnlen)5, (ftnlen)5);
/* SOURCE miscfeq.for:619 */
/*<       return >*/
    return ;
/* SOURCE miscfeq.for:620 */
/*<       end >*/
} /* makenn_ */




/* SOURCE miscfeq.for:624 */
/*<       character*10functionnote(j,emc,exnodt,ept,nex) >*/
/* Character */ VOID note_(char *ret_val, ftnlen ret_val_len, integer *j, 
	integer *feq_storage_emc, integer *feq_storage_exnodt, integer *ept, integer *nex)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer node;
    char dummy[10];

/*     + + + PURPOSE + + + */
/*     Construct a note to help identify exterior nodes more clearly */
/*     in error messages. */
/* SOURCE miscfeq.for:631 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE miscfeq.for:633 */
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
/* SOURCE miscfeq.for:636 */
/*<       integerept,j,nex >*/
/* SOURCE miscfeq.for:637 */
/*<       integeremc(ept),exnodt(9,nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     J      - pointer to node number in EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
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
/* INCLUDE miscfeq.for:658 */
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

/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:661 */
/*<       integernode >*/
/* SOURCE miscfeq.for:662 */
/*<       characterdummy*10 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE miscfeq.for:665 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:667 */
/*<       node=abs(emc(j)) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    node = (feq_gen_i_d_1 = emc[*j], abs(feq_gen_i_d_1));
/* SOURCE miscfeq.for:668 */
/*<       if(exnodt(3,node).gt.0)then >*/
    if (exnodt[node * 9 + 3] > 0) {
/* SOURCE miscfeq.for:669 */
/*<       write(dummy,'(A6,I4)')'on Br ',inbrus(exnodt(3,node)) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = dummy;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(A6,I4)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("on Br "), (ftnlen)6);
	do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[exnodt[node * 9 + 3] - 1], (
		ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE miscfeq.for:671 */
/*<       note=dummy >*/
	s_copy(ret_val, dummy, (ftnlen)10, (ftnlen)10);
/* SOURCE miscfeq.for:672 */
/*<       elseif(exnodt(3,node).eq.0)then >*/
    } else if (exnodt[node * 9 + 3] == 0) {
/* SOURCE miscfeq.for:673 */
/*<       note='Free Node ' >*/
	s_copy(ret_val, const_cast<char*>("Free Node "), (ftnlen)10, (ftnlen)10);
/* SOURCE miscfeq.for:674 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:675 */
/*<       note='Reservoir ' >*/
	s_copy(ret_val, const_cast<char*>("Reservoir "), (ftnlen)10, (ftnlen)10);
/* SOURCE miscfeq.for:676 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:677 */
/*<       return >*/
    return ;
/* SOURCE miscfeq.for:678 */
/*<       end >*/
} /* note_ */




/* SOURCE miscfeq.for:682 */
/*<       subroutinesortci(n,cval,ival) >*/
/* Subroutine */ int sortci_(integer *n, char *feq_storage_cval, integer *feq_storage_ival, ftnlen 
	cval_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;
    char t[5];
    integer ta;

/*     + + + PURPOSE + + + */
/*     Sort CVAL in ascending order and move other values at */
/*     same time */
/* SOURCE miscfeq.for:690 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:692 */
/*<       integern >*/
/* SOURCE miscfeq.for:693 */
/*<       integerival(n) >*/
/* SOURCE miscfeq.for:694 */
/*<       charactercval(n)*5 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - number of items to sort */
/*     CVAL   - character values to sort */
/*     IVAL   - integer values to move as sort on CVAL takes place */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:702 */
/*<       integeri,j,ta >*/
/* SOURCE miscfeq.for:703 */
/*<       charactert*5 >*/
/* *********************************************************************** */
/*     USE INSERTION SORT FROM PROGRAMMING PEARLS */
/*     COMM. OF ACM APRIL 1984 */
/* SOURCE miscfeq.for:708 */
/*<       do200i=2,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ival(feq_storage_ival, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, 5);

    /* Function Body */
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE miscfeq.for:709 */
/*<       j=i >*/
	j = feq_gen_i_d_;
/* SOURCE miscfeq.for:710 */
/*<       t=cval(j) >*/
	s_copy(t, cval + j * 5, (ftnlen)5, (ftnlen)5);
/* SOURCE miscfeq.for:711 */
/*<       ta=ival(j) >*/
	ta = ival[j];
/* SOURCE miscfeq.for:712 */
/*<   100 continue >*/
L100:
/* SOURCE miscfeq.for:714 */
/*<       if(j.gt.1)then >*/
	if (j > 1) {
/* SOURCE miscfeq.for:715 */
/*<       if(cval(j-1).gt.t)then >*/
	    if (s_cmp(cval + (j - 1) * 5, t, (ftnlen)5, (ftnlen)5) > 0) {
/* SOURCE miscfeq.for:716 */
/*<       cval(j)=cval(j-1) >*/
		s_copy(cval + j * 5, cval + (j - 1) * 5, (ftnlen)5, (ftnlen)5)
			;
/* SOURCE miscfeq.for:717 */
/*<       ival(j)=ival(j-1) >*/
		ival[j] = ival[j - 1];
/* SOURCE miscfeq.for:719 */
/*<       j=j-1 >*/
		--j;
/* SOURCE miscfeq.for:721 */
/*<       goto100 >*/
		goto L100;
/* SOURCE miscfeq.for:722 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:723 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:724 */
/*<       cval(j)=t >*/
	s_copy(cval + j * 5, t, (ftnlen)5, (ftnlen)5);
/* SOURCE miscfeq.for:725 */
/*<       ival(j)=ta >*/
	ival[j] = ta;
/* SOURCE miscfeq.for:727 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE miscfeq.for:729 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:730 */
/*<       end >*/
} /* sortci_ */




/* SOURCE miscfeq.for:734 */
/*<       subroutinesort2i(n,ivals,ival) >*/
/* Subroutine */ int sort2i_(integer *n, integer *feq_storage_ivals, integer *feq_storage_ival)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, j, t, ta;

/*     + + + PURPOSE + + + */
/*     Sort IVALS in ascending order and move other values at */
/*     same time */
/* SOURCE miscfeq.for:742 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:744 */
/*<       integern >*/
/* SOURCE miscfeq.for:745 */
/*<       integerivals(n),ival(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - number of items to sort */
/*     IVALS   - character values to sort */
/*     IVAL   - integer values to move as sort on IVALS takes place */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:753 */
/*<       integeri,j,t,ta >*/
/* *********************************************************************** */
/*     USE INSERTION SORT FROM PROGRAMMING PEARLS */
/*     COMM. OF ACM APRIL 1984 */
/* SOURCE miscfeq.for:758 */
/*<       do200i=2,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ival(feq_storage_ival, 1);

    feq::IndexedPointer<integer> ivals(feq_storage_ivals, 1);

    /* Function Body */
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE miscfeq.for:759 */
/*<       j=i >*/
	j = feq_gen_i_d_;
/* SOURCE miscfeq.for:760 */
/*<       t=ivals(j) >*/
	t = ivals[j];
/* SOURCE miscfeq.for:761 */
/*<       ta=ival(j) >*/
	ta = ival[j];
/* SOURCE miscfeq.for:762 */
/*<   100 continue >*/
L100:
/* SOURCE miscfeq.for:764 */
/*<       if(j.gt.1)then >*/
	if (j > 1) {
/* SOURCE miscfeq.for:765 */
/*<       if(ivals(j-1).gt.t)then >*/
	    if (ivals[j - 1] > t) {
/* SOURCE miscfeq.for:766 */
/*<       ivals(j)=ivals(j-1) >*/
		ivals[j] = ivals[j - 1];
/* SOURCE miscfeq.for:767 */
/*<       ival(j)=ival(j-1) >*/
		ival[j] = ival[j - 1];
/* SOURCE miscfeq.for:769 */
/*<       j=j-1 >*/
		--j;
/* SOURCE miscfeq.for:771 */
/*<       goto100 >*/
		goto L100;
/* SOURCE miscfeq.for:772 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:773 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:774 */
/*<       ivals(j)=t >*/
	ivals[j] = t;
/* SOURCE miscfeq.for:775 */
/*<       ival(j)=ta >*/
	ival[j] = ta;
/* SOURCE miscfeq.for:777 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE miscfeq.for:779 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:780 */
/*<       end >*/
} /* sort2i_ */




/* SOURCE miscfeq.for:784 */
/*<       subroutinestrty5(newtab,ndep,y,qc,m,ftp,ftknt,eflag) >*/
/* Subroutine */ int strty5_(integer *newtab, integer *ndep, doublereal *feq_storage_y, 
	doublereal *feq_storage_qc, doublereal *feq_storage_m, integer *ftp, integer *ftknt, integer *
	eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer adrs;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Store an internally generated table of type 5. */
/* SOURCE miscfeq.for:791 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:793 */
/*<       integereflag,ftknt,ftp,ndep,newtab >*/
/* SOURCE miscfeq.for:794 */
/*<       real*8m(ndep),qc(ndep),y(ndep) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NEWTAB - table number */
/*     NDEP   - number of depth values */
/*     Y      - depth values */
/*     QC     - critical flows */
/*     M      - slope for the special internal table of type 5 */
/*     FTP    - next open location in the function table storage */
/*     FTKNT  - function table counter */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE miscfeq.for:807 */
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
/* INCLUDE miscfeq.for:808 */
/* ********************************************************************** */
/* SOURCE ftable.cmn:2 */
/*<       common/ftable/dtab >*/
/* SOURCE ftable.cmn:3 */
/*<       common/ftablea/longdummy,itmp,knt_of_ftabs,ftpnt >*/
/* SOURCE ftable.cmn:4 */
/*<       common/ftablec/ft_loc_status >*/
/* SOURCE ftable.cmn:6 */
/*<       integerftpnt(mftnum+5) >*/
/* SOURCE ftable.cmn:7 */
/*<       character*1ft_loc_status(mftnum) >*/
/* SOURCE ftable.cmn:9 */
/*<       realftab(0:mrftab) >*/
/* SOURCE ftable.cmn:10 */
/*<       real*8dtab(0:mdftab) >*/
/* SOURCE ftable.cmn:12 */
/*<       real*8longdummy >*/
/* SOURCE ftable.cmn:14 */
/*<       integeritmp,itab(0:mrftab),knt_of_ftabs >*/
/* SOURCE ftable.cmn:16 */
/*<       realrtmp >*/
/* SOURCE ftable.cmn:18 */
/*<       equivalence(dtab,ftab,itab) >*/
/* SOURCE ftable.cmn:19 */
/*<       equivalence(itmp,rtmp) >*/
/* SOURCE ftable.cmn:21 */
/*<       save/ftable/,/ftablea/,/ftablec/ >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE miscfeq.for:811 */
/*<       integeradrs,i >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE miscfeq.for:814 */
/*<       externalkil >*/
/* *********************************************************************** */
/*     Check for space. */
/* SOURCE miscfeq.for:817 */
/*<       if((ftp+off234+3*ndep).ge.mrftab)callkil(10,ftp,eflag) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> m(feq_storage_m, 1);

    feq::IndexedPointer<doublereal> qc(feq_storage_qc, 1);

    feq::IndexedPointer<doublereal> y(feq_storage_y, 1);

    /* Function Body */
    if (*ftp + 22 + *ndep * 3 >= 13000001) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/* SOURCE miscfeq.for:821 */
/*<       adrs=ftp >*/
    adrs = *ftp;
/*     Record address for the table */
/* SOURCE miscfeq.for:823 */
/*<       ftpnt(newtab)=adrs >*/
    ftablea_1.ftpnt[*newtab - 1] = adrs;
/* SOURCE miscfeq.for:824 */
/*<       ftknt=ftknt+1 >*/
    ++(*ftknt);
/* SOURCE miscfeq.for:826 */
/*<       itab(adrs+1)=newtab >*/
    itab[adrs + 1] = *newtab;
/* SOURCE miscfeq.for:827 */
/*<       itab(adrs+2)=5 >*/
    itab[adrs + 2] = 5;
/*     INITIALIZE LAST ADDRESS ACCESSED */
/* SOURCE miscfeq.for:830 */
/*<       itab(adrs+3)=adrs+off234 >*/
    itab[adrs + 3] = adrs + 22;
/* SOURCE miscfeq.for:831 */
/*<       ftab(adrs+4)=0.0 >*/
    ftab[adrs + 4] = (float)0.;
/* SOURCE miscfeq.for:833 */
/*<       adrs=adrs+off234 >*/
    adrs += 22;
/* SOURCE miscfeq.for:835 */
/*<       do100i=1,ndep >*/
    feq_gen_i_d_1 = *ndep;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE miscfeq.for:836 */
/*<       ftab(adrs)=sngl(y(i)) >*/
	ftab[adrs] = (real) y[feq_gen_i_d_];
/* SOURCE miscfeq.for:837 */
/*<       ftab(adrs+1)=sngl(qc(i)) >*/
	ftab[adrs + 1] = (real) qc[feq_gen_i_d_];
/* SOURCE miscfeq.for:838 */
/*<       ftab(adrs+2)=sngl(m(i)) >*/
	ftab[adrs + 2] = (real) m[feq_gen_i_d_];
/* SOURCE miscfeq.for:839 */
/*<       adrs=adrs+3 >*/
	adrs += 3;
/* SOURCE miscfeq.for:840 */
/*<   100 continue >*/
/* L100: */
    }
/*     Store the high address */
/* SOURCE miscfeq.for:843 */
/*<       itab(ftp)=adrs-3 >*/
    itab[*ftp] = adrs - 3;
/* SOURCE miscfeq.for:844 */
/*<       ftp=adrs >*/
    *ftp = adrs;
/* SOURCE miscfeq.for:846 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:847 */
/*<       end >*/
} /* strty5_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE miscfeq.for:851 */
/*<       subroutinetbox(stdout) >*/
/* Subroutine */ int tbox_(integer *stdout)
{
    /* Format strings */
    static char fmt_2000[] = "(1x,77(\002*\002))";
    static char fmt_2001[] = "(//)";
    static char fmt_2010[] = "(1x,\002*\002,75x,\002*\002)";
    static char fmt_2020[] = "(1x,\002*\002,24x,\002FULL EQUATIONS FLOW ROUT\
ING\002,24x,\002*\002)";
    static char fmt_2030[] = "(/,\002 Version:\002,f5.2,\002 \002,a)";
    static char fmt_2040[] = "(\002 WARNING: This program is large and compl\
ex.  User is \002,\002totally responsible for\002,/,\002 any consequences re\
sulting from application of \002,\002this program.  Read \002,/,\002 disclai\
mer in the source code.  This program is not \002,\002to be sold in any form.\
\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__80 = { 0, 0, 0, fmt_2001, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, fmt_2020, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_2030, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_2040, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Write out title box. */
/* SOURCE miscfeq.for:857 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE miscfeq.for:859 */
/*<       integerstdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/* INCLUDE miscfeq.for:864 */
/*     Common block to allow version and date to be output */
/*     at more than one point in the code. */
/* SOURCE version.cmn:4 */
/*<       characterversion_date*17 >*/
/* SOURCE version.cmn:6 */
/*<       realversion_number >*/
/* SOURCE version.cmn:8 */
/*<       common/version/version_number >*/
/* SOURCE version.cmn:10 */
/*<       common/versionc/version_date >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE miscfeq.for:866 */
/*<  2000 format(1x,77('*')) >*/
/* SOURCE miscfeq.for:867 */
/*<  2001 format(//) >*/
/* SOURCE miscfeq.for:868 */
/*<  2010 format(1x,'*',75x,'*') >*/
/* SOURCE miscfeq.for:869 */
/*<  2020 format(1x,'*',24x,'FULL EQUATIONS FLOW ROUTING',24x,'*') >*/
/* SOURCE miscfeq.for:870 */
/*<  2030 format(/,' Version:',f5.2,' ',a) >*/
/* SOURCE miscfeq.for:871 */
/*<  2040  >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:880 */
/*<       write(stdout,2001) >*/
/* L2000: */
/* L2001: */
/* L2010: */
/* L2020: */
/* L2030: */
/* L2040: */
    feq_gen_io_d__80.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__80);
    e_wsfe();
/* SOURCE miscfeq.for:881 */
/*<       write(stdout,2000) >*/
    feq_gen_io_d__81.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__81);
    e_wsfe();
/* SOURCE miscfeq.for:882 */
/*<       write(stdout,2010) >*/
    feq_gen_io_d__82.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__82);
    e_wsfe();
/* SOURCE miscfeq.for:883 */
/*<       write(stdout,2020) >*/
    feq_gen_io_d__83.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__83);
    e_wsfe();
/* SOURCE miscfeq.for:884 */
/*<       write(stdout,2010) >*/
    feq_gen_io_d__84.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__84);
    e_wsfe();
/* SOURCE miscfeq.for:885 */
/*<       write(stdout,2010) >*/
    feq_gen_io_d__85.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__85);
    e_wsfe();
/* SOURCE miscfeq.for:886 */
/*<       write(stdout,2000) >*/
    feq_gen_io_d__86.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__86);
    e_wsfe();
/* SOURCE miscfeq.for:888 */
/*<       write(stdout,2030)version_number,version_date >*/
    feq_gen_io_d__87.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__87);
    do_fio(&feq_gen_c_d_1, (char *)&version_1.feq_gen_version_number_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, versionc_1.feq_gen_version_date_d_, (ftnlen)17);
    e_wsfe();
/* SOURCE miscfeq.for:889 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__88.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__88);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE miscfeq.for:890 */
/*<       write(stdout,2040) >*/
    feq_gen_io_d__89.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__89);
    e_wsfe();
/* SOURCE miscfeq.for:891 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__90.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__90);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE miscfeq.for:892 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:893 */
/*<       end >*/
} /* tbox_ */




/* SOURCE miscfeq.for:897 */
/*<       realfunctionget_station(adrs) >*/
doublereal feq_gen_get_station_d_(integer *adrs)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Get the station from a cross-section table given the address of the table. */
/*     The table is known to exist. */
/* SOURCE miscfeq.for:902 */
/*<       implicitnone >*/
/* SOURCE miscfeq.for:903 */
/*<       integeradrs >*/
/* INCLUDE miscfeq.for:905 */
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
/* INCLUDE miscfeq.for:906 */
/* ********************************************************************** */
/* SOURCE ftable.cmn:2 */
/*<       common/ftable/dtab >*/
/* SOURCE ftable.cmn:3 */
/*<       common/ftablea/longdummy,itmp,knt_of_ftabs,ftpnt >*/
/* SOURCE ftable.cmn:4 */
/*<       common/ftablec/ft_loc_status >*/
/* SOURCE ftable.cmn:6 */
/*<       integerftpnt(mftnum+5) >*/
/* SOURCE ftable.cmn:7 */
/*<       character*1ft_loc_status(mftnum) >*/
/* SOURCE ftable.cmn:9 */
/*<       realftab(0:mrftab) >*/
/* SOURCE ftable.cmn:10 */
/*<       real*8dtab(0:mdftab) >*/
/* SOURCE ftable.cmn:12 */
/*<       real*8longdummy >*/
/* SOURCE ftable.cmn:14 */
/*<       integeritmp,itab(0:mrftab),knt_of_ftabs >*/
/* SOURCE ftable.cmn:16 */
/*<       realrtmp >*/
/* SOURCE ftable.cmn:18 */
/*<       equivalence(dtab,ftab,itab) >*/
/* SOURCE ftable.cmn:19 */
/*<       equivalence(itmp,rtmp) >*/
/* SOURCE ftable.cmn:21 */
/*<       save/ftable/,/ftablea/,/ftablec/ >*/
/* ********************************************************************** */
/* *********************************************************************** */
/* SOURCE miscfeq.for:908 */
/*<       get_station=ftab(adrs+4) >*/
    ret_val = ftab[*adrs + 4];
/* SOURCE miscfeq.for:909 */
/*<       return >*/
    return ret_val;
/* SOURCE miscfeq.for:910 */
/*<       end >*/
} /* get_station__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE miscfeq.for:915 */
/*<       subroutineseek_free_node_stations(stdout,nbra,nex,brpt,emc,exnodt) >*/
/* Subroutine */ int feq_gen_seek_free_node_stations_d_(integer *stdout, integer *nbra,
	 integer *nex, integer *feq_storage_brpt, integer *feq_storage_emc, integer *feq_storage_exnodt)
{
    /* Initialized data */

    static integer null = -2147483647;

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    integer k, n;
    doublereal x;
    integer cnn, knt;
    extern doublereal feq_gen_get_station_d_(integer *);
    integer code, adrs, ipnt;
    doublereal sumx;
    integer feq_gen_class_d_, ientry;
    doublereal station;

/*     Scan EMC seeking to assign stations to all free nodes for */
/*     which this is possible. */

/* SOURCE miscfeq.for:922 */
/*<       implicitnone >*/
/* INCLUDE miscfeq.for:923 */
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
/* SOURCE miscfeq.for:924 */
/*<       integernbra,nex,stdout,brpt(8,nbra),exnodt(9,nex),emc(mremc) >*/
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
/* INCLUDE miscfeq.for:943 */
/* SOURCE bnothr.cmn:1 */
/*<        >*/
/* SOURCE bnothr.cmn:6 */
/*<       common/bnothc/bnodid >*/
/* SOURCE bnothr.cmn:8 */
/*<       character*16bnodid(mnbn) >*/
/* SOURCE bnothr.cmn:10 */
/*<        >*/
/* SOURCE bnothr.cmn:13 */
/*<        >*/
/* INCLUDE miscfeq.for:944 */
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
/*     Called program units */
/* SOURCE miscfeq.for:948 */
/*<       realget_station >*/
/* SOURCE miscfeq.for:949 */
/*<       externalget_station >*/
/*     Local */
/* SOURCE miscfeq.for:954 */
/*<       integeradrs,code,ientry,ipnt,k,knt,n,cnn,class,null >*/
/* SOURCE miscfeq.for:957 */
/*<       real*8x,sumx,station >*/
/* *********************************************************************** */
/*     Scan over all CODE 2 entries and ccompute the stations for any */
/*     free nodes that are in the junction with one or more branch nodes. */
/* SOURCE miscfeq.for:959 */
/*<       datanull/-2147483647/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE miscfeq.for:964 */
/*<       ientry=0 >*/
    ientry = 0;
/* SOURCE miscfeq.for:967 */
/*<   100 continue >*/
L100:
/* SOURCE miscfeq.for:968 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE miscfeq.for:969 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE miscfeq.for:970 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE miscfeq.for:971 */
/*<       if(code.eq.2)then >*/
    if (code == 2) {
/* SOURCE miscfeq.for:972 */
/*<       n=emc(ipnt+1) >*/
	n = emc[ipnt + 1];
/*         Scan for nodes on branches and compute the average station */
/*         for them. */
/* SOURCE miscfeq.for:975 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE miscfeq.for:976 */
/*<       sumx=0.d0 >*/
	sumx = 0.;
/* SOURCE miscfeq.for:977 */
/*<       do150k=1,n >*/
	feq_gen_i_d_1 = n;
	for (k = 1; k <= feq_gen_i_d_1; ++k) {
/* SOURCE miscfeq.for:978 */
/*<       cnn=emc(ipnt+1+k) >*/
	    cnn = emc[ipnt + 1 + k];
/* SOURCE miscfeq.for:979 */
/*<       class=exnodt(3,cnn) >*/
	    feq_gen_class_d_ = exnodt[cnn * 9 + 3];
/* SOURCE miscfeq.for:980 */
/*<       if(class.gt.0)then >*/
	    if (feq_gen_class_d_ > 0) {
/*             We have a branch. Get the station. */
/* SOURCE miscfeq.for:982 */
/*<       adrs=exnodt(4,cnn) >*/
		adrs = exnodt[cnn * 9 + 4];
/* SOURCE miscfeq.for:983 */
/*<       x=get_station(adrs) >*/
		x = feq_gen_get_station_d_(&adrs);
/* SOURCE miscfeq.for:984 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE miscfeq.for:985 */
/*<       sumx=sumx+x >*/
		sumx += x;
/* SOURCE miscfeq.for:986 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:987 */
/*<   150 continue >*/
/* L150: */
	}
/* SOURCE miscfeq.for:988 */
/*<       if(knt.gt.0)then >*/
	if (knt > 0) {
/*           Compute the average value for the station */
/* SOURCE miscfeq.for:990 */
/*<       station=sumx/dble(knt) >*/
	    station = sumx / (doublereal) knt;
/*           Now scan the junction again and assign the average station from */
/*           branch nodes to any free nodes in the junction but only if */
/*           the free node has a NULL value for station. */
/* SOURCE miscfeq.for:994 */
/*<       do160k=1,n >*/
	    feq_gen_i_d_1 = n;
	    for (k = 1; k <= feq_gen_i_d_1; ++k) {
/* SOURCE miscfeq.for:995 */
/*<       cnn=emc(ipnt+1+k) >*/
		cnn = emc[ipnt + 1 + k];
/* SOURCE miscfeq.for:996 */
/*<       class=exnodt(3,cnn) >*/
		feq_gen_class_d_ = exnodt[cnn * 9 + 3];
/* SOURCE miscfeq.for:997 */
/*<       if(class.le.0)then >*/
		if (feq_gen_class_d_ <= 0) {
/*               We have a free node */
/* SOURCE miscfeq.for:999 */
/*<       if(exnodt(8,cnn).eq.null)then >*/
		    if (exnodt[cnn * 9 + 8] == null) {
/* SOURCE miscfeq.for:1000 */
/*<       exnodt(8,cnn)=nint(station*1.d4) >*/
			feq_gen_d_d_1 = station * 1e4;
			exnodt[cnn * 9 + 8] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE miscfeq.for:1001 */
/*<       endif >*/
		    }
/* SOURCE miscfeq.for:1002 */
/*<       endif >*/
		}
/* SOURCE miscfeq.for:1003 */
/*<   160 continue >*/
/* L160: */
	    }
/* SOURCE miscfeq.for:1004 */
/*<       endif >*/
	}
/* SOURCE miscfeq.for:1005 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:1006 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE miscfeq.for:1008 */
/*<       goto100 >*/
	goto L100;
/* SOURCE miscfeq.for:1009 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:1011 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:1012 */
/*<       end >*/
} /* seek_free_node_stations__ */




/* SOURCE miscfeq.for:1017 */
/*<       subroutinedmpeqs(stdout,first,last,kount,jtime) >*/
/* Subroutine */ int dmpeqs_(integer *stdout, integer *first, integer *last, 
	integer *kount, doublereal *jtime)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Selected block of equations from Network\
 Matrix\002,\002 KOUNT=\002,i5,/,\002EqNum  Coefficients . . . . . . . . . .\
 . . . . . . . . . . .\002,\002 . . . . . . . . . . . . . . . . . . . .  Rgh\
thnd Sd\002,\002  Correction Variable ID\002)";
    static char fmt_55[] = "(i5,10a12,a12,2a12)";
    static char fmt_56[] = "(5x,10a12)";
    static char fmt_58[] = "(/,\002 Band limits=\002,i10,i10)";
    static char fmt_60[] = "(/,\002 Min/Max coef=\002,1pd15.5,1pd15.5)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2[2], feq_gen_i_d_3;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[5];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), e_wsfi();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<doublereal> feq_heap_a(10001);
    doublereal *a = feq_heap_a.data();
    integer feq_gen_i_d_, j, k, n, vn, neq, feq_gen_global_kmin_d_, feq_gen_global_kmax_d_;
    doublereal coef[50];
    integer kmin, kmax;
    char eqvar[12];
    integer lower, upper;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer varnum[20];
    doublereal feq_gen_global_mincoef_d_, feq_gen_global_maxcoef_d_;
    char outmin[12], outmax[12], output[12*10];
    doublereal mincoef, maxcoef;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__134 = { 0, 0, 0, fmt_60, 0 };


/*     Ouput the selected equations in the network matrix.  Used */
/*     for special debugging */
/* SOURCE miscfeq.for:1023 */
/*<       implicitnone >*/
/* SOURCE miscfeq.for:1024 */
/*<       integerstdout,first,last,kount >*/
/* SOURCE miscfeq.for:1025 */
/*<       real*8jtime >*/
/*     Called program units */
/* SOURCE miscfeq.for:1028 */
/*<       charactergetusn*5 >*/
/* SOURCE miscfeq.for:1030 */
/*<       externalgetusn >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE miscfeq.for:1033 */
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
/* INCLUDE miscfeq.for:1034 */
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
/*     Local variables */
/* SOURCE miscfeq.for:1038 */
/*<       integerhalf,lower,upper,neq >*/
/* SOURCE miscfeq.for:1039 */
/*<       parameter(half=5000) >*/
/* SOURCE miscfeq.for:1040 */
/*<       integeri,j,k,n,kmin,kmax,varnum(20),vn,global_kmin,global_kmax >*/
/* SOURCE miscfeq.for:1042 */
/*<        >*/
/* SOURCE miscfeq.for:1044 */
/*<       characteroutput(10)*12,eqvar*12,outmin*12,outmax*12 >*/
/*     *****************************FORMATS****************************** */
/* SOURCE miscfeq.for:1046 */
/*<    50  >*/
/* SOURCE miscfeq.for:1051 */
/*<    52 format(i10,i10,i10) >*/
/* SOURCE miscfeq.for:1052 */
/*<    54 format(25i10) >*/
/* SOURCE miscfeq.for:1053 */
/*<    55 format(i5,10a12,a12,2a12) >*/
/* SOURCE miscfeq.for:1054 */
/*<    56 format(5x,10a12) >*/
/* SOURCE miscfeq.for:1055 */
/*<    58 format(/,' Band limits=',i10,i10) >*/
/* SOURCE miscfeq.for:1056 */
/*<    60 format(/,' Min/Max coef=',1pd15.5,1pd15.5) >*/
/* *********************************************************************** */
/* SOURCE miscfeq.for:1058 */
/*<       global_kmin=123456789 >*/
/* L50: */
/* L52: */
/* L54: */
/* L55: */
/* L56: */
/* L58: */
/* L60: */
    feq_gen_global_kmin_d_ = 123456789;
/* SOURCE miscfeq.for:1059 */
/*<       global_kmax=-123456789 >*/
    feq_gen_global_kmax_d_ = -123456789;
/* SOURCE miscfeq.for:1060 */
/*<       global_mincoef=1.d100 >*/
    feq_gen_global_mincoef_d_ = 1e100;
/* SOURCE miscfeq.for:1061 */
/*<       global_maxcoef=-1.d100 >*/
    feq_gen_global_maxcoef_d_ = -1e100;
/* SOURCE miscfeq.for:1063 */
/*<       write(stdout,50)kount >*/
    feq_gen_io_d__111.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__111);
    do_fio(&feq_gen_c_d_1, (char *)&(*kount), (ftnlen)sizeof(integer));
    e_wsfe();
/*     Place the diagonal element at index 0. */
/* SOURCE miscfeq.for:1066 */
/*<       if(last.lt.0)then >*/
    if (*last < 0) {
/* SOURCE miscfeq.for:1067 */
/*<       upper=numeq >*/
	upper = matcom_1.numeq;
/* SOURCE miscfeq.for:1068 */
/*<       elseif(last.gt.numeq)then >*/
    } else if (*last > matcom_1.numeq) {
/* SOURCE miscfeq.for:1069 */
/*<       upper=numeq >*/
	upper = matcom_1.numeq;
/* SOURCE miscfeq.for:1070 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:1071 */
/*<       upper=last >*/
	upper = *last;
/* SOURCE miscfeq.for:1072 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:1074 */
/*<       if(first.lt.0)then >*/
    if (*first < 0) {
/* SOURCE miscfeq.for:1075 */
/*<       lower=1 >*/
	lower = 1;
/* SOURCE miscfeq.for:1076 */
/*<       elseif(first.gt.numeq)then >*/
    } else if (*first > matcom_1.numeq) {
/* SOURCE miscfeq.for:1077 */
/*<       lower=1 >*/
	lower = 1;
/* SOURCE miscfeq.for:1078 */
/*<       else >*/
    } else {
/* SOURCE miscfeq.for:1079 */
/*<       lower=first >*/
	lower = *first;
/* SOURCE miscfeq.for:1080 */
/*<       endif >*/
    }
/* SOURCE miscfeq.for:1082 */
/*<       neq=upper-lower+1 >*/
    neq = upper - lower + 1;
/*      WRITE(45) NEQ, KOUNT, JTIME */
/* SOURCE miscfeq.for:1085 */
/*<       do500i=lower,upper >*/
    feq_gen_i_d_1 = upper;
    for (feq_gen_i_d_ = lower; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       Define the id string for the variable on the diagonal of this */
/*       equation. */
/* SOURCE miscfeq.for:1089 */
/*<       eqvar=' ' >*/
	s_copy(eqvar, const_cast<char*>(" "), (ftnlen)12, (ftnlen)1);
/* SOURCE miscfeq.for:1090 */
/*<       if(varid(i).eq.0)then >*/
	if (matcom_1.varid[feq_gen_i_d_ - 1] == 0) {
/*         We don't have an assigned id.  Use the */
/*         variable number itself */
/* SOURCE miscfeq.for:1093 */
/*<       if(mod(i,2).eq.0)then >*/
	    if (feq_gen_i_d_ % 2 == 0) {
/* SOURCE miscfeq.for:1094 */
/*<       write(eqvar,'(5X,I5,'':Y'')')i >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 12;
		feq_gen_ici_d_1.iciunit = eqvar;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(5X,I5,':Y')");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
		e_wsfi();
/* SOURCE miscfeq.for:1095 */
/*<       else >*/
	    } else {
/* SOURCE miscfeq.for:1096 */
/*<       write(eqvar,'(5X,I5,'':Q'')')i >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 12;
		feq_gen_ici_d_1.iciunit = eqvar;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(5X,I5,':Q')");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
		e_wsfi();
/* SOURCE miscfeq.for:1097 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:1098 */
/*<       else >*/
	} else {
/*         We have an exterior node number */
/* SOURCE miscfeq.for:1100 */
/*<       if(mod(i,2).eq.0)then >*/
	    if (feq_gen_i_d_ % 2 == 0) {
/* SOURCE miscfeq.for:1101 */
/*<       eqvar(6:12)=getusn(varid(i))//':Y' >*/
/* Writing concatenation */
		getusn_(feq_gen_ch_d_1, (ftnlen)5, &matcom_1.varid[feq_gen_i_d_ - 1]);
		feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
		feq_gen_i_d_2[1] = 2, feq_gen_a_d_1[1] = const_cast<char*>(":Y");
		s_cat(eqvar + 5, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)7);
/* SOURCE miscfeq.for:1102 */
/*<       else >*/
	    } else {
/* SOURCE miscfeq.for:1103 */
/*<       eqvar(6:12)=getusn(varid(i))//':Q' >*/
/* Writing concatenation */
		getusn_(feq_gen_ch_d_1, (ftnlen)5, &matcom_1.varid[feq_gen_i_d_ - 1]);
		feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
		feq_gen_i_d_2[1] = 2, feq_gen_a_d_1[1] = const_cast<char*>(":Q");
		s_cat(eqvar + 5, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)7);
/* SOURCE miscfeq.for:1104 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:1105 */
/*<       endif >*/
	}
/*       C(I) points to the last element in the column that ends with the */
/*       diagonal element  for the I-th equation.  It only includes */
/*       the potentially non-zero values from the diagonal element */
/*       upward to the equations above the I-th equation.  Its first */
/*       element is given by R(I) + 1. */
/*       R(I) points to the last element on the I-th row that ends just */
/*       to the left of the diagonal element.   The first element */
/*       in the potentially non-zero values on ths row is given */
/*       by C(I-1) + 1. */
/*       Extract the elements on the row that are to the left of the */
/*       main diagonal if they exist. They may not exist in all cases. */

/* SOURCE miscfeq.for:1123 */
/*<       k=0 >*/
	k = 0;
/* SOURCE miscfeq.for:1124 */
/*<       do100j=r(i),c(i-1)+1,-1 >*/
	feq_gen_i_d_3 = matcom_1.feq_gen_c_d_[feq_gen_i_d_ - 1] + 1;
	for (j = matcom_1.feq_gen_r_d_[feq_gen_i_d_ - 1]; j >= feq_gen_i_d_3; --j) {
/* SOURCE miscfeq.for:1125 */
/*<       k=k-1 >*/
	    --k;
/* SOURCE miscfeq.for:1126 */
/*<       a(k)=pdavec2(j) >*/
	    a[k + 5000] = matcom2_1.pdavec2[j - 1];
/* SOURCE miscfeq.for:1127 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE miscfeq.for:1128 */
/*<       kmin=k >*/
	kmin = k;
/*       Now extract the diagonal element and those to the right. */
/* SOURCE miscfeq.for:1132 */
/*<       k=0 >*/
	k = 0;
/* SOURCE miscfeq.for:1133 */
/*<       a(k)=pdavec2(c(i)) >*/
	a[k + 5000] = matcom2_1.pdavec2[matcom_1.feq_gen_c_d_[feq_gen_i_d_] - 1];
/* SOURCE miscfeq.for:1134 */
/*<       k=1 >*/
	k = 1;
/* SOURCE miscfeq.for:1135 */
/*<       kmax=eqend(i) >*/
	kmax = matcom_1.eqend[feq_gen_i_d_ - 1];
/* SOURCE miscfeq.for:1136 */
/*<   200 continue >*/
L200:
/* SOURCE miscfeq.for:1138 */
/*<       if(k.le.kmax)then >*/
	if (k <= kmax) {
/* SOURCE miscfeq.for:1139 */
/*<       if(c(i+k)-k.ge.r(i+k)+1)then >*/
	    if (matcom_1.feq_gen_c_d_[feq_gen_i_d_ + k] - k >= matcom_1.feq_gen_r_d_[feq_gen_i_d_ + k - 1] + 1) {
/* SOURCE miscfeq.for:1140 */
/*<       a(k)=pdavec2(c(i+k)-k) >*/
		a[k + 5000] = matcom2_1.pdavec2[matcom_1.feq_gen_c_d_[feq_gen_i_d_ + k] - k - 1]
			;
/* SOURCE miscfeq.for:1141 */
/*<       else >*/
	    } else {
/* SOURCE miscfeq.for:1142 */
/*<       a(k)=0.0 >*/
		a[k + 5000] = (float)0.;
/* SOURCE miscfeq.for:1143 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:1144 */
/*<       k=k+1 >*/
	    ++k;
/* SOURCE miscfeq.for:1145 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE miscfeq.for:1146 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,52) I, KMIN, KMAX */
/* SOURCE miscfeq.for:1149 */
/*<       global_kmin=min(kmin,global_kmin) >*/
	feq_gen_global_kmin_d_ = min(kmin,feq_gen_global_kmin_d_);
/* SOURCE miscfeq.for:1150 */
/*<       global_kmax=max(kmax,global_kmax) >*/
	feq_gen_global_kmax_d_ = max(kmax,feq_gen_global_kmax_d_);
/*        WRITE(45) I, KMIN, KMAX, (A(K), K=KMIN,KMAX), RHS2(I), RHS(I), */
/*     A           EQVAR */
/* SOURCE miscfeq.for:1154 */
/*<       n=0 >*/
	n = 0;
/* SOURCE miscfeq.for:1155 */
/*<       mincoef=1.d100 >*/
	mincoef = 1e100;
/* SOURCE miscfeq.for:1156 */
/*<       maxcoef=-1.d100 >*/
	maxcoef = -1e100;
/* SOURCE miscfeq.for:1157 */
/*<       do300k=kmin,kmax >*/
	feq_gen_i_d_3 = kmax;
	for (k = kmin; k <= feq_gen_i_d_3; ++k) {
/* SOURCE miscfeq.for:1158 */
/*<       if(a(k).ne.0.0)then >*/
	    if (a[k + 5000] != (float)0.) {
/* SOURCE miscfeq.for:1159 */
/*<       n=n+1 >*/
		++n;
/* SOURCE miscfeq.for:1160 */
/*<       varnum(n)=k+i >*/
		varnum[n - 1] = k + feq_gen_i_d_;
/* SOURCE miscfeq.for:1161 */
/*<       coef(n)=a(k) >*/
		coef[n - 1] = a[k + 5000];
/* SOURCE miscfeq.for:1162 */
/*<       mincoef=min(abs(coef(n)),mincoef) >*/
/* Computing MIN */
		feq_gen_d_d_2 = (feq_gen_d_d_1 = coef[n - 1], abs(feq_gen_d_d_1));
		mincoef = min(feq_gen_d_d_2,mincoef);
/* SOURCE miscfeq.for:1163 */
/*<       maxcoef=max(abs(coef(n)),maxcoef) >*/
/* Computing MAX */
		feq_gen_d_d_2 = (feq_gen_d_d_1 = coef[n - 1], abs(feq_gen_d_d_1));
		maxcoef = max(feq_gen_d_d_2,maxcoef);
/* SOURCE miscfeq.for:1164 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:1165 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE miscfeq.for:1166 */
/*<       do350j=1,n >*/
	feq_gen_i_d_3 = n;
	for (j = 1; j <= feq_gen_i_d_3; ++j) {
/*         Construct variable numbers and names (when known) */
/* SOURCE miscfeq.for:1168 */
/*<       vn=varnum(j) >*/
	    vn = varnum[j - 1];
/* SOURCE miscfeq.for:1169 */
/*<       output(j)=' ' >*/
	    s_copy(output + (j - 1) * 12, const_cast<char*>(" "), (ftnlen)12, (ftnlen)1);
/* SOURCE miscfeq.for:1170 */
/*<       if(varid(vn).eq.0)then >*/
	    if (matcom_1.varid[vn - 1] == 0) {
/*           We don't have an assigned id.  Use the */
/*           variable number itself */
/* SOURCE miscfeq.for:1173 */
/*<       if(mod(vn,2).eq.0)then >*/
		if (vn % 2 == 0) {
/* SOURCE miscfeq.for:1174 */
/*<       write(output(j),'(5X,I5,'':Y'')')vn >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 12;
		    feq_gen_ici_d_1.iciunit = output + (j - 1) * 12;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(5X,I5,':Y')");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&vn, (ftnlen)sizeof(integer));
		    e_wsfi();
/* SOURCE miscfeq.for:1175 */
/*<       else >*/
		} else {
/* SOURCE miscfeq.for:1176 */
/*<       write(output(j),'(5X,I5,'':Q'')')vn >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 12;
		    feq_gen_ici_d_1.iciunit = output + (j - 1) * 12;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(5X,I5,':Q')");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&vn, (ftnlen)sizeof(integer));
		    e_wsfi();
/* SOURCE miscfeq.for:1177 */
/*<       endif >*/
		}
/* SOURCE miscfeq.for:1178 */
/*<       else >*/
	    } else {
/*           We have an exterior node number */
/* SOURCE miscfeq.for:1180 */
/*<       if(mod(vn,2).eq.0)then >*/
		if (vn % 2 == 0) {
/* SOURCE miscfeq.for:1181 */
/*<       output(j)(6:12)=getusn(varid(vn))//':Y' >*/
/* Writing concatenation */
		    getusn_(feq_gen_ch_d_1, (ftnlen)5, &matcom_1.varid[vn - 1]);
		    feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
		    feq_gen_i_d_2[1] = 2, feq_gen_a_d_1[1] = const_cast<char*>(":Y");
		    s_cat(output + ((j - 1) * 12 + 5), feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (
			    ftnlen)7);
/* SOURCE miscfeq.for:1182 */
/*<       else >*/
		} else {
/* SOURCE miscfeq.for:1183 */
/*<       output(j)(6:12)=getusn(varid(vn))//':Q' >*/
/* Writing concatenation */
		    getusn_(feq_gen_ch_d_1, (ftnlen)5, &matcom_1.varid[vn - 1]);
		    feq_gen_i_d_2[0] = 5, feq_gen_a_d_1[0] = feq_gen_ch_d_1;
		    feq_gen_i_d_2[1] = 2, feq_gen_a_d_1[1] = const_cast<char*>(":Q");
		    s_cat(output + ((j - 1) * 12 + 5), feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (
			    ftnlen)7);
/* SOURCE miscfeq.for:1184 */
/*<       endif >*/
		}
/* SOURCE miscfeq.for:1185 */
/*<       endif >*/
	    }
/* SOURCE miscfeq.for:1186 */
/*<   350 continue >*/
/* L350: */
	}
/* SOURCE miscfeq.for:1188 */
/*<       do360j=n+1,10 >*/
	for (j = n + 1; j <= 10; ++j) {
/* SOURCE miscfeq.for:1189 */
/*<       output(j)=' ' >*/
	    s_copy(output + (j - 1) * 12, const_cast<char*>(" "), (ftnlen)12, (ftnlen)1);
/* SOURCE miscfeq.for:1190 */
/*<   360 continue >*/
/* L360: */
	}
/* SOURCE miscfeq.for:1192 */
/*<       write(stdout,56)output >*/
	feq_gen_io_d__129.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__129);
	do_fio(&feq_gen_c_d_10, output, (ftnlen)12);
	e_wsfe();
/* SOURCE miscfeq.for:1194 */
/*<       do370j=1,n >*/
	feq_gen_i_d_3 = n;
	for (j = 1; j <= feq_gen_i_d_3; ++j) {
/* SOURCE miscfeq.for:1195 */
/*<       write(output(j),'(1PE12.4)')coef(j) >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 12;
	    feq_gen_ici_d_1.iciunit = output + (j - 1) * 12;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(1PE12.4)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&coef[j - 1], (ftnlen)sizeof(doublereal));
	    e_wsfi();
/* SOURCE miscfeq.for:1196 */
/*<   370 continue >*/
/* L370: */
	}
/* SOURCE miscfeq.for:1197 */
/*<       do380j=n+1,8 >*/
	for (j = n + 1; j <= 8; ++j) {
/* SOURCE miscfeq.for:1198 */
/*<       output(j)=' . . . . . .' >*/
	    s_copy(output + (j - 1) * 12, const_cast<char*>(" . . . . . ."), (ftnlen)12, (ftnlen)
		    12);
/* SOURCE miscfeq.for:1199 */
/*<   380 continue >*/
/* L380: */
	}
/* SOURCE miscfeq.for:1200 */
/*<       write(output(9),'(1PE12.4)')rhs2(i) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 12;
	feq_gen_ici_d_1.iciunit = output + 96;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(1PE12.4)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&matcom2_1.rhs2[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfi();
/* SOURCE miscfeq.for:1201 */
/*<       write(output(10),'(1PE12.4)')rhs(i) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 12;
	feq_gen_ici_d_1.iciunit = output + 108;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(1PE12.4)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&matcom_1.rhs[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfi();
/* SOURCE miscfeq.for:1202 */
/*<       write(outmin,'(1PE12.4)')mincoef >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 12;
	feq_gen_ici_d_1.iciunit = outmin;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(1PE12.4)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&mincoef, (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE miscfeq.for:1203 */
/*<       write(outmax,'(1PE12.4)')maxcoef >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 12;
	feq_gen_ici_d_1.iciunit = outmax;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(1PE12.4)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&maxcoef, (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE miscfeq.for:1204 */
/*<       write(stdout,55)i,output,eqvar,outmin,outmax >*/
	feq_gen_io_d__132.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__132);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_10, output, (ftnlen)12);
	do_fio(&feq_gen_c_d_1, eqvar, (ftnlen)12);
	do_fio(&feq_gen_c_d_1, outmin, (ftnlen)12);
	do_fio(&feq_gen_c_d_1, outmax, (ftnlen)12);
	e_wsfe();
/* SOURCE miscfeq.for:1206 */
/*<       global_mincoef=min(mincoef,global_mincoef) >*/
	feq_gen_global_mincoef_d_ = min(mincoef,feq_gen_global_mincoef_d_);
/* SOURCE miscfeq.for:1207 */
/*<       global_maxcoef=max(maxcoef,global_maxcoef) >*/
	feq_gen_global_maxcoef_d_ = max(maxcoef,feq_gen_global_maxcoef_d_);
/* SOURCE miscfeq.for:1209 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE miscfeq.for:1210 */
/*<       write(stdout,58)global_kmin,global_kmax >*/
    feq_gen_io_d__133.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__133);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_global_kmin_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_global_kmax_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE miscfeq.for:1211 */
/*<       write(stdout,60)global_mincoef,global_maxcoef >*/
    feq_gen_io_d__134.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__134);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_global_mincoef_d_, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_global_maxcoef_d_, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE miscfeq.for:1213 */
/*<       return >*/
    return 0;
/* SOURCE miscfeq.for:1214 */
/*<       end >*/
} /* dmpeqs_ */

#ifdef __cplusplus
	}
#endif
