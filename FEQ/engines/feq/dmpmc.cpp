/* dmpmc.f -- translated by f2c (version 20240504).
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

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;

/*     ***************** */
/*     *               * */
/*     * DMPMC         * */
/*     *               * */
/*     ***************** */
/* SOURCE dmpmc.for:7 */
/*<       subroutinedmpmc(stdout,nbra,nex,brpt,exnodt) >*/
/* Subroutine */ int dmpmc_(integer *stdout, integer *nbra, integer *nex, 
	integer *feq_storage_brpt, integer *feq_storage_exnodt)
{
    /* Format strings */
    static char fmt_50[] = "(\002   EQU NUM   ROW PNT   COL PNT\002)";
    static char fmt_52[] = "(3i10)";
    static char fmt_54[] = "(\002 BLOCK NUM    BEGROW    ENDCON    MBTYPE\
\002)";
    static char fmt_56[] = "(4i10)";
    static char fmt_60[] = "(\002 BRANCH POINTER\002)";
    static char fmt_62[] = "(i7,i8)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, 
	    ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__2 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__3 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__4 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, 0, 0 };


/*     OUTPUT THE CONTROL INFORMATION FOR CHECKING */
/* SOURCE dmpmc.for:11 */
/*<       integerstdout,nbra,nex >*/
/* SOURCE dmpmc.for:13 */
/*<       integerbrpt(8,nex),exnodt(9,nex) >*/
/* INCLUDE dmpmc.for:15 */
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
/* INCLUDE dmpmc.for:16 */
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
/*     LOCAL */
/* SOURCE dmpmc.for:20 */
/*<       integeri >*/
/*     *********************FORMATS************************************** */
/* SOURCE dmpmc.for:22 */
/*<    50 format('   EQU NUM   ROW PNT   COL PNT') >*/
/* SOURCE dmpmc.for:23 */
/*<    52 format(3i10) >*/
/* SOURCE dmpmc.for:24 */
/*<    54 format(' BLOCK NUM    BEGROW    ENDCON    MBTYPE') >*/
/* SOURCE dmpmc.for:25 */
/*<    56 format(4i10) >*/
/* SOURCE dmpmc.for:26 */
/*<    60 format(' BRANCH POINTER') >*/
/* SOURCE dmpmc.for:27 */
/*<    62 format(i7,i8) >*/
/* *********************************************************************** */
/* SOURCE dmpmc.for:31 */
/*<       write(stdout,*)'  ' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L60: */
/* L62: */
    feq_gen_io_d__1.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__1);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  "), (ftnlen)2);
    e_wsle();
/* SOURCE dmpmc.for:32 */
/*<       write(stdout,*)' NUMEQ=',numeq >*/
    feq_gen_io_d__2.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__2);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NUMEQ="), (ftnlen)7);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&matcom_1.numeq, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE dmpmc.for:34 */
/*<       write(stdout,*)' POINTERS FOR PROFILE STORAGE OF MATRIX.' >*/
    feq_gen_io_d__3.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__3);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" POINTERS FOR PROFILE STORAGE OF MATRIX."), (ftnlen)
	    40);
    e_wsle();
/* SOURCE dmpmc.for:35 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__4.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__4);
    e_wsfe();
/* SOURCE dmpmc.for:37 */
/*<       do100i=1,numeq >*/
    feq_gen_i_d_1 = matcom_1.numeq;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dmpmc.for:38 */
/*<       write(stdout,52)i,r(i),c(i) >*/
	feq_gen_io_d__6.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__6);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&matcom_1.feq_gen_r_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer))
		;
	do_fio(&feq_gen_c_d_1, (char *)&matcom_1.feq_gen_c_d_[feq_gen_i_d_], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE dmpmc.for:39 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE dmpmc.for:41 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__7.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__7);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE dmpmc.for:42 */
/*<       write(stdout,*)' MATRIX BLOCK CONTROL' >*/
    feq_gen_io_d__8.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__8);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" MATRIX BLOCK CONTROL"), (ftnlen)21);
    e_wsle();
/* SOURCE dmpmc.for:43 */
/*<       write(stdout,*)' MATBLK=',matblk >*/
    feq_gen_io_d__9.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__9);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" MATBLK="), (ftnlen)8);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&matcom_1.matblk, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE dmpmc.for:44 */
/*<       write(stdout,54) >*/
    feq_gen_io_d__10.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__10);
    e_wsfe();
/* SOURCE dmpmc.for:46 */
/*<       do200i=1,matblk >*/
    feq_gen_i_d_1 = matcom_1.matblk;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dmpmc.for:47 */
/*<       write(stdout,56)i,begrow(i),endcon(i),mbtype(i) >*/
	feq_gen_io_d__11.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__11);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&matcom_1.begrow[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&feq_gen_c_d_1, (char *)&matcom_1.endcon[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&feq_gen_c_d_1, (char *)&matcom_1.mbtype[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		integer));
	e_wsfe();
/* SOURCE dmpmc.for:48 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE dmpmc.for:51 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__12.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__12);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE dmpmc.for:52 */
/*<       write(stdout,*)' POINTERS TO VARIABLES FOR BRANCHES' >*/
    feq_gen_io_d__13.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__13);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" POINTERS TO VARIABLES FOR BRANCHES"), (ftnlen)35);
    e_wsle();
/* SOURCE dmpmc.for:53 */
/*<       write(stdout,60) >*/
    feq_gen_io_d__14.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__14);
    e_wsfe();
/* SOURCE dmpmc.for:54 */
/*<       do300i=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dmpmc.for:55 */
/*<       write(stdout,62)i,brpt(7,i) >*/
	feq_gen_io_d__15.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__15);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&brpt[(feq_gen_i_d_ << 3) + 7], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE dmpmc.for:56 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE dmpmc.for:58 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__16.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__16);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE dmpmc.for:59 */
/*<       write(stdout,*)' POINTERS TO VARIABLE FOR EXTERIOR NODES' >*/
    feq_gen_io_d__17.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__17);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" POINTERS TO VARIABLE FOR EXTERIOR NODES"), (ftnlen)
	    40);
    e_wsle();
/* SOURCE dmpmc.for:60 */
/*<       write(stdout,60) >*/
    feq_gen_io_d__18.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__18);
    e_wsfe();
/* SOURCE dmpmc.for:61 */
/*<       do400i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dmpmc.for:62 */
/*<       write(stdout,62)i,exnodt(5,i) >*/
	feq_gen_io_d__19.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__19);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&exnodt[feq_gen_i_d_ * 9 + 5], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE dmpmc.for:63 */
/*<   400 continue >*/
/* L400: */
    }
/* SOURCE dmpmc.for:65 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__20.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__20);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE dmpmc.for:66 */
/*<       return >*/
    return 0;
/* SOURCE dmpmc.for:67 */
/*<       end >*/
} /* dmpmc_ */

#ifdef __cplusplus
	}
#endif
