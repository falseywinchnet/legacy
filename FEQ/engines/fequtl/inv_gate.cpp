#include "../support/format.hpp"
#include "callbacks.hpp"
/* inv_gate.f -- translated by f2c (version 20240504).
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

/* COMMON invgc_ is declared in common.hpp. */

#define invgc_1 invgc_

/* COMMON invgcc_ is declared in common.hpp. */

#define invgcc_1 invgcc_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_98 = 98;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_15 = 15;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_10002 = 10002;




/* SOURCE inv_gate.for:4 */
/*<        >*/
/* Subroutine */ int feq_gen_type10_out_d_(integer *stdout, integer *stdtab, integer *
	tabnum, integer *feq_gen_n_row_args_d_, integer *feq_gen_n_col_args_d_, char *
	feq_gen_feq_storage_row_args_d_, real *hdatum, char *feq_gen_feq_storage_col_args_d_, char *feq_storage_body, char *hdin, 
	char *hditem, char *hdout, char *rowin, char *rowlab, char *rowout, 
	char *label, ftnlen row_args_len, ftnlen col_args_len, ftnlen 
	body_len, ftnlen hdin_len, ftnlen hditem_len, ftnlen hdout_len, 
	ftnlen rowin_len, ftnlen rowlab_len, ftnlen rowout_len, ftnlen 
	label_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002TABID=\002,a)";
    static char fmt_52[] = "(\002TYPE=\002,i5)";
    static char fmt_54[] = "(\002HDATUM=\002,f10.3)";
    static char fmt_56[] = "(\002LABEL=\002,a)";
    static char fmt_58[] = "(\002  -1.0\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    char feq_gen_ch_d_1[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    integer feq_gen_i_d_, j, n;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer is;
    char line[120];
    integer feq_gen_type_d_;
    char tabid[16];
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__2 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_58, 0 };


/*     Output a function table of type 10. */
/* SOURCE inv_gate.for:13 */
/*<       implicitnone >*/
/*     Dummy arguments */
/* INCLUDE inv_gate.for:17 */
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
/* SOURCE inv_gate.for:19 */
/*<       integerstdout,stdtab,tabnum,n_row_args,n_col_args >*/
/* SOURCE inv_gate.for:21 */
/*<       realhdatum >*/
/* SOURCE inv_gate.for:23 */
/*<        >*/
/*     Local */
/* SOURCE inv_gate.for:30 */
/*<       integeri,is,j,n,type >*/
/* SOURCE inv_gate.for:32 */
/*<       characterline*120,tabid*16 >*/
/*     Called subprograms */
/* SOURCE inv_gate.for:36 */
/*<       characterget_tabid*16 >*/
/* SOURCE inv_gate.for:37 */
/*<       integerlenstr >*/
/* SOURCE inv_gate.for:39 */
/*<       externallenstr >*/
/*     ********************************FORMATS*************************** */
/* SOURCE inv_gate.for:41 */
/*<    50 format('TABID=',a) >*/
/* SOURCE inv_gate.for:42 */
/*<    52 format('TYPE=',i5) >*/
/* SOURCE inv_gate.for:43 */
/*<    54 format('HDATUM=',f10.3) >*/
/* SOURCE inv_gate.for:44 */
/*<    56 format('LABEL=',a) >*/
/* SOURCE inv_gate.for:45 */
/*<    58 format('  -1.0') >*/
/* *********************************************************************** */
/*     Output the table number */
/* SOURCE inv_gate.for:49 */
/*<       tabid=get_tabid(tabnum) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> feq_gen_row_args_d_(feq_gen_feq_storage_row_args_d_, 8);

    feq::IndexedPointer<char> body(feq_storage_body, 328);

    feq::IndexedPointer<char> feq_gen_col_args_d_(feq_gen_feq_storage_col_args_d_, 8);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, tabnum);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE inv_gate.for:50 */
/*<       write(stdtab,50)tabid(1:lenstr(tabid)) >*/
    feq_gen_io_d__2.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__2);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/*     Construct table type followed by the formats. */
/* SOURCE inv_gate.for:53 */
/*<       line=' ' >*/
    s_copy(line, const_cast<char*>(" "), (ftnlen)120, (ftnlen)1);
/* SOURCE inv_gate.for:54 */
/*<       type=-10 >*/
    feq_gen_type_d_ = -10;
/* SOURCE inv_gate.for:55 */
/*<       write(line(1:10),52)type >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 10;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_52;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE inv_gate.for:57 */
/*<       is=12 >*/
    is = 12;
/* SOURCE inv_gate.for:58 */
/*<       n=lenstr(hdin) >*/
    n = lenstr_(hdin, (ftnlen)24);
/* SOURCE inv_gate.for:59 */
/*<       line(is:is+n-1)=hdin(1:n) >*/
    s_copy(line + (is - 1), hdin, is + n - 1 - (is - 1), n);
/* SOURCE inv_gate.for:60 */
/*<       is=is+n+1 >*/
    is = is + n + 1;
/* SOURCE inv_gate.for:61 */
/*<       n=lenstr(hdout) >*/
    n = lenstr_(hdout, (ftnlen)24);
/* SOURCE inv_gate.for:62 */
/*<       line(is:is+n-1)=hdout(1:n) >*/
    s_copy(line + (is - 1), hdout, is + n - 1 - (is - 1), n);
/* SOURCE inv_gate.for:63 */
/*<       is=is+n+1 >*/
    is = is + n + 1;
/* SOURCE inv_gate.for:64 */
/*<       n=lenstr(hditem) >*/
    n = lenstr_(hditem, (ftnlen)24);
/* SOURCE inv_gate.for:65 */
/*<       line(is:is+n-1)=hditem(1:n) >*/
    s_copy(line + (is - 1), hditem, is + n - 1 - (is - 1), n);
/* SOURCE inv_gate.for:66 */
/*<       is=is+n+1 >*/
    is = is + n + 1;
/* SOURCE inv_gate.for:67 */
/*<       n=lenstr(rowin) >*/
    n = lenstr_(rowin, (ftnlen)24);
/* SOURCE inv_gate.for:68 */
/*<       line(is:is+n-1)=rowin(1:n) >*/
    s_copy(line + (is - 1), rowin, is + n - 1 - (is - 1), n);
/* SOURCE inv_gate.for:69 */
/*<       is=is+n+1 >*/
    is = is + n + 1;
/* SOURCE inv_gate.for:70 */
/*<       n=lenstr(rowout) >*/
    n = lenstr_(rowout, (ftnlen)24);
/* SOURCE inv_gate.for:71 */
/*<       line(is:is+n-1)=rowout(1:n) >*/
    s_copy(line + (is - 1), rowout, is + n - 1 - (is - 1), n);
/* SOURCE inv_gate.for:72 */
/*<       is=is+n >*/
    is += n;
/* SOURCE inv_gate.for:73 */
/*<       write(stdtab,'(A)')line(1:is) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdtab;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, is);
    e_wsfe();
/*     Output the datum for heads */
/* SOURCE inv_gate.for:76 */
/*<       write(stdtab,54)hdatum >*/
    feq_gen_io_d__7.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__7);
    do_fio(&feq_gen_c_d_1, (char *)&(*hdatum), (ftnlen)sizeof(real));
    e_wsfe();
/*     Output the table label */
/* SOURCE inv_gate.for:79 */
/*<       write(stdtab,56)label >*/
    feq_gen_io_d__8.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__8);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/*     Output the headings and the body of the table.  Note that the */
/*     output is in character-string format.  The source routine */
/*     has the task of creating the correct strings and formats for */
/*     the table. */
/* SOURCE inv_gate.for:85 */
/*<       n=lenstr(hdin) >*/
    n = lenstr_(hdin, (ftnlen)24);
/* SOURCE inv_gate.for:86 */
/*<       write(stdtab,hdin(2:n-1))rowlab,(col_args(j),j=1,n_col_args) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdtab;
    feq_gen_ci_d_1.cifmt = feq::format_text(hdin + 1, n - 2);
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, rowlab, (ftnlen)8);
    feq_gen_i_d_1 = *feq_gen_n_col_args_d_;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, feq_gen_col_args_d_ + (j << 3), (ftnlen)8);
    }
    e_wsfe();
/* SOURCE inv_gate.for:87 */
/*<       do100i=1,n_row_args >*/
    feq_gen_i_d_1 = *feq_gen_n_row_args_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inv_gate.for:88 */
/*<       write(stdtab,hdin(2:n-1))row_args(i),(body(i,j),j=1,n_col_args) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdtab;
	feq_gen_ci_d_1.cifmt = feq::format_text(hdin + 1, n - 2);
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, feq_gen_row_args_d_ + (feq_gen_i_d_ << 3), (ftnlen)8);
	feq_gen_i_d_2 = *feq_gen_n_col_args_d_;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, body + (feq_gen_i_d_ + j * 40 << 3), (ftnlen)8);
	}
	e_wsfe();
/* SOURCE inv_gate.for:90 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE inv_gate.for:91 */
/*<       write(stdtab,58) >*/
    feq_gen_io_d__11.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__11);
    e_wsfe();
/* SOURCE inv_gate.for:93 */
/*<       return >*/
    return 0;
/* SOURCE inv_gate.for:94 */
/*<       end >*/
} /* type10_out__ */




/* SOURCE inv_gate.for:98 */
/*<       realfunctiongate_res(hg) >*/
doublereal feq_gen_gate_res_d_(real *hg)
{
    /* Initialized data */

    static doublereal jtime = 0.;
    static integer mftab = 0;

    /* System generated locals */
    real ret_val;

    /* Local variables */
    real q;
    integer feq_gen_ftype_code_d_;
    real dqed, dqeu;
    extern /* Subroutine */ int tdlk15_(integer *, integer *, integer *, 
	    doublereal *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, char *, integer *, ftnlen);
    real newhg;

/*     Compute the gate residual function for an underflow */
/*     gate. */
/* SOURCE inv_gate.for:103 */
/*<       realhg >*/
/*     Common block needed values */
/* INCLUDE inv_gate.for:107 */
/*     Common block for residual function for INV_GATE command */
/* SOURCE invgate.cmn:3 */
/*<       integergate_res_table,gate_res_stdout >*/
/* SOURCE invgate.cmn:4 */
/*<       realgate_res_flow,gate_res_eup,gate_res_edn,gate_res_hbase >*/
/* SOURCE invgate.cmn:6 */
/*<        >*/
/* SOURCE invgate.cmn:10 */
/*<       character*8gate_res_ftype >*/
/* SOURCE invgate.cmn:12 */
/*<       common/invgcc/gate_res_ftype >*/
/*     Local variables. */
/* SOURCE inv_gate.for:110 */
/*<       integermftab,ftype_code >*/
/* SOURCE inv_gate.for:111 */
/*<       realdqed,dqeu,newhg,q >*/
/* SOURCE inv_gate.for:112 */
/*<       real*8jtime >*/
/* *********************************************************************** */
/*     Find the flow at the current gate opening */
/* SOURCE inv_gate.for:114 */
/*<       datajtime/0.0d0/,mftab/0/ >*/
/* SOURCE inv_gate.for:119 */
/*<        >*/
    tdlk15_(&invgc_1.feq_gen_gate_res_stdout_d_, &invgc_1.feq_gen_gate_res_table_d_, &mftab, &
	    jtime, &invgc_1.feq_gen_gate_res_edn_d_, &invgc_1.feq_gen_gate_res_eup_d_, hg, &
	    invgc_1.feq_gen_gate_res_hbase_d_, &q, &dqed, &dqeu, &newhg, 
	    invgcc_1.feq_gen_gate_res_ftype_d_, &feq_gen_ftype_code_d_, (ftnlen)8);
/* SOURCE inv_gate.for:125 */
/*<       gate_res=(gate_res_flow-q)/gate_res_flow >*/
    ret_val = static_cast<double>((static_cast<double>(invgc_1.feq_gen_gate_res_flow_d_) - q)) / invgc_1.feq_gen_gate_res_flow_d_;
/*      WRITE(GATE_RES_STDOUT,*) ' GATE_RES:HG=',HG,' Q=',Q, */
/*     A    ' RES=',GATE_RES */
/* SOURCE inv_gate.for:129 */
/*<       return >*/
    return ret_val;
/* SOURCE inv_gate.for:130 */
/*<       end >*/
} /* gate_res__ */




/* SOURCE inv_gate.for:134 */
/*<        >*/
/* Subroutine */ int feq_gen_find_gate_opening_d_(integer *stdout, integer *feq_gen_ud_table_d_,
	 integer *feq_gen_du_table_d_, real *eup, real *edn, real *feq_gen_gate_flow_d_, real *
	feq_gen_hg_max_d_, real *hbase, real *hg, real *p, char *ftype, integer *
	feq_gen_result_flag_d_, integer *feq_gen_ftype_code_d_, ftnlen ftype_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:XXX* No sign change in REGFAL in su\
broutine\002,\002 FIND_GATE_OPENING.\002)";
    static char fmt_52[] = "(/,\002 *ERR:XXX* No solution in REGFAL in subro\
utine\002,\002 FIND_GATE_OPENING after 100 iteration.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern doublereal feq_gen_gate_res_d_(real *);
    real a, b, q, feq_gen_hg_result_d_;
    integer feq_gen_flag_d_;
    real dqed, dqeu;
    integer mftab;
    extern /* Subroutine */ int tdlk15_(integer *, integer *, integer *, 
	    doublereal *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, char *, integer *, ftnlen);
    real newhg;
    doublereal jtime;
    extern /* Subroutine */ int regfal_(real *, real *, FeqCallback3, real *, real *, 
	    real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, 0, 0 };


/*     Find the opening for an underflow gate so that the flow */
/*     through the gate will match the GATE_FLOW given in the */
/*     dummy argument list.   We assume that the GATE_FLOW differs */
/*     from zero. */
/* SOURCE inv_gate.for:144 */
/*<       implicitnone >*/
/* SOURCE inv_gate.for:146 */
/*<       integerstdout,ud_table,du_table,result_flag,ftype_code >*/
/* SOURCE inv_gate.for:148 */
/*<       realeup,edn,gate_flow,hg,p,hbase,hg_max >*/
/* SOURCE inv_gate.for:150 */
/*<       character*8ftype >*/
/*     Definition of dummy arguments */
/*     STDOUT- Fortran unit for standard output */
/*     UD_TABLE- address of type 15 table describing flow through */
/*       the gate from upstream node  to downstream node. */
/*     DU_TABLE-address of type 15 table describing flow through */
/*       the gate from downstream node to upstream node. */
/*     EUP- water-surface elevation at upstream node */
/*     EDN- water-surface elevation at downstream node */
/*     GATE_FLOW- target flow for the gate */
/*     HG_MAX- maximum gate opening in the gate-flow tables. */
/*     HBASE- datum for head for the gate */
/*     HG- gate opening to match the target flow. */
/*     P- gate opening as fraction of maximum opening. */
/*     RESULT_FLAG- 1 if a solution exists, 0 otherwise. */
/*     Common blocks */
/* INCLUDE inv_gate.for:171 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE inv_gate.for:172 */
/*     Common block for residual function for INV_GATE command */
/* SOURCE invgate.cmn:3 */
/*<       integergate_res_table,gate_res_stdout >*/
/* SOURCE invgate.cmn:4 */
/*<       realgate_res_flow,gate_res_eup,gate_res_edn,gate_res_hbase >*/
/* SOURCE invgate.cmn:6 */
/*<        >*/
/* SOURCE invgate.cmn:10 */
/*<       character*8gate_res_ftype >*/
/* SOURCE invgate.cmn:12 */
/*<       common/invgcc/gate_res_ftype >*/
/*     Local variables */
/* SOURCE inv_gate.for:176 */
/*<       integermftab,flag >*/
/* SOURCE inv_gate.for:178 */
/*<       realdqed,dqeu,newhg,q,a,b,hg_result >*/
/* SOURCE inv_gate.for:179 */
/*<       real*8jtime >*/
/*     Called program units */
/* SOURCE inv_gate.for:184 */
/*<       realgate_res >*/
/* SOURCE inv_gate.for:185 */
/*<       externalgate_res >*/
/*     *************************FORMATS********************************** */
/* SOURCE inv_gate.for:188 */
/*<    50  >*/
/* SOURCE inv_gate.for:190 */
/*<    52  >*/
/* *********************************************************************** */
/*     Clear the multiplying-factor table address and the time */
/*     value. */
/* SOURCE inv_gate.for:195 */
/*<       mftab=0 >*/
/* L50: */
/* L52: */
    mftab = 0;
/* SOURCE inv_gate.for:196 */
/*<       jtime=0.d0 >*/
    jtime = 0.;
/*     Determine if a solution exists.  Set the gate to its maximum */
/*     opening with the given heads and see if the flow exceeds the */
/*     target value.  If not, no solution is possible. */
/* SOURCE inv_gate.for:203 */
/*<       if(gate_flow.gt.0.0)then >*/
    if (*feq_gen_gate_flow_d_ > (float)0.) {
/* SOURCE inv_gate.for:204 */
/*<        >*/
	tdlk15_(stdout, feq_gen_ud_table_d_, &mftab, &jtime, edn, eup, feq_gen_hg_max_d_, hbase,
		 &q, &dqed, &dqeu, &newhg, ftype, feq_gen_ftype_code_d_, (ftnlen)8);
/* SOURCE inv_gate.for:208 */
/*<       else >*/
    } else {
/* SOURCE inv_gate.for:209 */
/*<        >*/
	tdlk15_(stdout, feq_gen_du_table_d_, &mftab, &jtime, eup, edn, feq_gen_hg_max_d_, hbase,
		 &q, &dqed, &dqeu, &newhg, ftype, feq_gen_ftype_code_d_, (ftnlen)8);
/* SOURCE inv_gate.for:213 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' FIND_GATE_OPENING: Q=',Q,' GATE_FLOW=', */
/*     A                  GATE_FLOW */
/* SOURCE inv_gate.for:216 */
/*<       if(abs(q).lt.abs(gate_flow))then >*/
    if (dabs(q) < dabs(*feq_gen_gate_flow_d_)) {
/*       No solution possible. */
/* SOURCE inv_gate.for:218 */
/*<       hg=hg_max >*/
	*hg = *feq_gen_hg_max_d_;
/* SOURCE inv_gate.for:219 */
/*<       p=1.0 >*/
	*p = (float)1.;
/* SOURCE inv_gate.for:220 */
/*<       result_flag=0 >*/
	*feq_gen_result_flag_d_ = 0;
/* SOURCE inv_gate.for:221 */
/*<       goto9000 >*/
	goto L9000;
/* SOURCE inv_gate.for:222 */
/*<       endif >*/
    }
/*     Solution appears to be possible here.  We will solve for the */
/*     root using modified Regula Falsi because we have a bound on */
/*     each end for a possible root and because the derivatives of */
/*     the flow from the gate can be discontinuous. */
/* SOURCE inv_gate.for:229 */
/*<       a=0.0 >*/
    a = (float)0.;
/* SOURCE inv_gate.for:230 */
/*<       b=hg_max >*/
    b = *feq_gen_hg_max_d_;
/*     Set values in the common block for function GATE_RES */
/* SOURCE inv_gate.for:233 */
/*<       gate_res_flow=abs(gate_flow) >*/
    invgc_1.feq_gen_gate_res_flow_d_ = dabs(*feq_gen_gate_flow_d_);
/* SOURCE inv_gate.for:234 */
/*<       gate_res_hbase=hbase >*/
    invgc_1.feq_gen_gate_res_hbase_d_ = *hbase;
/* SOURCE inv_gate.for:235 */
/*<       gate_res_stdout=stdout >*/
    invgc_1.feq_gen_gate_res_stdout_d_ = *stdout;
/* SOURCE inv_gate.for:236 */
/*<       if(gate_flow.gt.0.0)then >*/
    if (*feq_gen_gate_flow_d_ > (float)0.) {
/* SOURCE inv_gate.for:237 */
/*<       gate_res_table=ud_table >*/
	invgc_1.feq_gen_gate_res_table_d_ = *feq_gen_ud_table_d_;
/* SOURCE inv_gate.for:238 */
/*<       gate_res_eup=eup >*/
	invgc_1.feq_gen_gate_res_eup_d_ = *eup;
/* SOURCE inv_gate.for:239 */
/*<       gate_res_edn=edn >*/
	invgc_1.feq_gen_gate_res_edn_d_ = *edn;
/* SOURCE inv_gate.for:240 */
/*<       else >*/
    } else {
/* SOURCE inv_gate.for:241 */
/*<       gate_res_table=du_table >*/
	invgc_1.feq_gen_gate_res_table_d_ = *feq_gen_du_table_d_;
/* SOURCE inv_gate.for:242 */
/*<       gate_res_eup=edn >*/
	invgc_1.feq_gen_gate_res_eup_d_ = *edn;
/* SOURCE inv_gate.for:243 */
/*<       gate_res_edn=eup >*/
	invgc_1.feq_gen_gate_res_edn_d_ = *eup;
/* SOURCE inv_gate.for:244 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:246 */
/*<       callregfal(epsarg,epsf,gate_res,a,b,hg_result,flag) >*/
    regfal_(&epscom_1.epsarg, &epscom_1.epsf, feq_gen_gate_res_d_, &a, &b, &
	    feq_gen_hg_result_d_, &feq_gen_flag_d_);
/* SOURCE inv_gate.for:251 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE inv_gate.for:252 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__29.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__29);
	e_wsfe();
/* SOURCE inv_gate.for:253 */
/*<       stop' Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>(" Abnormal stop.  Errors found."), (ftnlen)30);
/* SOURCE inv_gate.for:254 */
/*<       elseif(flag.eq.2)then >*/
    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE inv_gate.for:255 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__30.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__30);
	e_wsfe();
/* SOURCE inv_gate.for:256 */
/*<       write(stdout,*)' MIN_HG=',a,' MAX_HG=',b >*/
	feq_gen_io_d__31.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__31);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" MIN_HG="), (ftnlen)8);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&a, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" MAX_HG="), (ftnlen)8);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&b, (ftnlen)sizeof(real));
	e_wsle();
/* SOURCE inv_gate.for:257 */
/*<       stop' Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>(" Abnormal stop. Errors found."), (ftnlen)29);
/* SOURCE inv_gate.for:258 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:260 */
/*<       result_flag=1 >*/
    *feq_gen_result_flag_d_ = 1;
/* SOURCE inv_gate.for:261 */
/*<       hg=hg_result >*/
    *hg = feq_gen_hg_result_d_;
/* SOURCE inv_gate.for:262 */
/*<       p=hg/hg_max >*/
    *p = static_cast<double>(*hg) / *feq_gen_hg_max_d_;
/* SOURCE inv_gate.for:263 */
/*<       ftype=gate_res_ftype >*/
    s_copy(ftype, invgcc_1.feq_gen_gate_res_ftype_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE inv_gate.for:265 */
/*<  9000 continue >*/
L9000:
/* SOURCE inv_gate.for:266 */
/*<       return >*/
    return 0;
/* SOURCE inv_gate.for:267 */
/*<       end >*/
} /* find_gate_opening__ */




/* SOURCE inv_gate.for:272 */
/*<        >*/
/* Subroutine */ int feq_gen_get_inv_gate_d_(integer *stdin, integer *stdout, integer *
	eflag, integer *feq_gen_du_table_d_, integer *feq_gen_ud_table_d_, integer *
	feq_gen_n_col_bdys_d_, integer *feq_gen_n_row_bdys_d_, integer *feq_gen_control_tab_d_, real *
	feq_gen_feq_storage_col_bdys_d_, real *feq_gen_feq_storage_row_bdys_d_, real *feq_gen_flood_elev_d_, real *feq_gen_flood_flow_d_, 
	char *feq_gen_cpnt_elev_ts_d_, char *feq_gen_ups_elev_ts_d_, char *feq_gen_dns_elev_ts_d_, char *
	feq_gen_gate_flow_ts_d_, char *feq_gen_drain_loc_d_, real *feq_gen_min_flow_d_, char *
	feq_gen_output_level_d_, char *feq_gen_reverse_flow_d_, ftnlen cpnt_elev_ts_len, ftnlen 
	ups_elev_ts_len, ftnlen dns_elev_ts_len, ftnlen gate_flow_ts_len, 
	ftnlen drain_loc_len, ftnlen output_level_len, ftnlen 
	reverse_flow_len)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*15+1] = "CPNT_ELEV       UPS_ELEV        D\
NS_ELEV        GATE_FLOW       DRAIN_LOC       DU_TABLE        UD_TABLE     \
   CONTROL_TAB     COL_BDYS        ROW_BDYS        FLOOD_ELEV      FLOOD_FLO\
W      MIN_FLOW        OUTPUT_LEVEL    REVERSE_FLOW    ";
    static integer feq_gen_symbol_value_d_[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 
	    };
    static integer feq_gen_response_type_d_[15] = { 4,4,4,4,4,1,1,1,-1,-1,3,3,3,4,4 };
    static integer feq_gen_convert_rule_d_[15] = { 0,0,0,0,0,0,0,0,0,0,1,1,1,0,0 };

    /* Format strings */
    static char fmt_52[] = "(/,\002 *BUG:XXX* Invalid index=\002,i5,\002 for\
 name=\002,a,\002 in\002,\002 subroutine GET_INV_GATE.\002)";
    static char fmt_54[] = "(/,\002 *ERR:XXX* Name=\002,a16,\002 is unknown \
INV_GATE.\002)";
    static char fmt_56[] = "(/,\002 Unable to continue due to previous error\
s.\002)";
    static char fmt_60[] = "(/,\002 Processing:\002,a)";
    static char fmt_97[] = "(1x,12x,\002ITEM\002,\002   LEN  TYPE T  TCLS\
\002)";
    static char fmt_99[] = "(\002 \002,a16,\002 \002,i5,\002 \002,i5,\002\
 \002,a1,\002 \002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_item_knt_d_, feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_chk_and_convert_response_d_(integer *, integer 
	    *, char *, integer *, integer *, integer *, integer *, char *, 
	    integer *, integer *, integer *, real *, doublereal *, ftnlen, 
	    ftnlen), feq_gen_get_multiple_real_values_d_(integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, real *, doublereal *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, integer *, real *, 
	    ftnlen, ftnlen, ftnlen);
    integer selection, feq_gen_item_type_d_[98], ip, it;
    char key[16];
    integer opt, clen[98];
    char cval[256*98], line[120];
    integer ival[98];
    real rval[98];
    char term[1*98];
    doublereal dpval[98];
    integer terml[98];
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    integer eflag2;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     getval_(integer *, char *, integer *, integer *, integer *, 
	    integer *, real *, doublereal *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, ftnlen, ftnlen, ftnlen);
    extern integer lenstr_(char *, ftnlen);
    integer termcls[98];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__55 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_52, 0 };


/*     Get the values needed for the INV_GATE command */
/* SOURCE inv_gate.for:281 */
/*<       implicitnone >*/
/* INCLUDE inv_gate.for:283 */
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
/* SOURCE inv_gate.for:285 */
/*<       integerstdin,stdout,eflag >*/
/* SOURCE inv_gate.for:286 */
/*<       integerdu_table,ud_table,n_col_bdys,n_row_bdys,control_tab >*/
/* SOURCE inv_gate.for:288 */
/*<        >*/
/* SOURCE inv_gate.for:291 */
/*<        >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE inv_gate.for:298 */
/*<        >*/
/* SOURCE inv_gate.for:301 */
/*<        >*/
/* SOURCE inv_gate.for:305 */
/*<       integereflag2,i,it,opt,ip,selection,item_knt >*/
/* SOURCE inv_gate.for:306 */
/*<        >*/
/* SOURCE inv_gate.for:308 */
/*<       realrval(nval) >*/
/* SOURCE inv_gate.for:309 */
/*<       real*8dpval(nval) >*/
/* SOURCE inv_gate.for:310 */
/*<       charactercval(nval)*256,term(nval)*1,line*120,key*16 >*/
/* SOURCE inv_gate.for:313 */
/*<       integerlenstr >*/
/* SOURCE inv_gate.for:315 */
/*<        >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE inv_gate.for:319 */
/*<        >*/
/* SOURCE inv_gate.for:321 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE inv_gate.for:323 */
/*<       savesymbol_value,symbol_table >*/
/*     *****************************FORMATS****************************** */
/* SOURCE inv_gate.for:326 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_row_bdys_d_(feq_gen_feq_storage_row_bdys_d_, 1);

    feq::IndexedPointer<real> feq_gen_col_bdys_d_(feq_gen_feq_storage_col_bdys_d_, 1);

    /* Function Body */
/* SOURCE inv_gate.for:332 */
/*<       datasymbol_value/1,2,3,4,5,6,7,8,9,10,11,12,13,14,15/ >*/
/* SOURCE inv_gate.for:337 */
/*<        >*/
/* SOURCE inv_gate.for:341 */
/*<        >*/
/* SOURCE inv_gate.for:344 */
/*<    52  >*/
/* L52: */
/* SOURCE inv_gate.for:346 */
/*<    54 format(/,' *ERR:XXX* Name=',a16,' is unknown INV_GATE.') >*/
/* L54: */
/* SOURCE inv_gate.for:347 */
/*<    56 format(/,' Unable to continue due to previous errors.') >*/
/* L56: */
/* SOURCE inv_gate.for:348 */
/*<    60 format(/,' Processing:',a) >*/
/* L60: */
/* SOURCE inv_gate.for:349 */
/*<    62 format(/,' Seeking additional values.') >*/
/* L62: */
/* *********************************************************************** */
/*     Clear the local error flag for subroutine GETVAL */
/* SOURCE inv_gate.for:352 */
/*<       eflag2=0 >*/
    eflag2 = 0;
/*     Read lines of input and process each one until the expected number */
/*     of lines or an end of header signal is found. */
/*     SET DEFAULTS */
/* SOURCE inv_gate.for:358 */
/*<       du_table=0 >*/
    *feq_gen_du_table_d_ = 0;
/* SOURCE inv_gate.for:359 */
/*<       ud_table=0 >*/
    *feq_gen_ud_table_d_ = 0;
/* SOURCE inv_gate.for:360 */
/*<       n_col_bdys=0 >*/
    *feq_gen_n_col_bdys_d_ = 0;
/* SOURCE inv_gate.for:361 */
/*<       n_row_bdys=0 >*/
    *feq_gen_n_row_bdys_d_ = 0;
/* SOURCE inv_gate.for:362 */
/*<       control_tab=0 >*/
    *feq_gen_control_tab_d_ = 0;
/* SOURCE inv_gate.for:363 */
/*<       flood_elev=0.0 >*/
    *feq_gen_flood_elev_d_ = (float)0.;
/* SOURCE inv_gate.for:364 */
/*<       flood_flow=0.0 >*/
    *feq_gen_flood_flow_d_ = (float)0.;
/* SOURCE inv_gate.for:365 */
/*<       cpnt_elev_ts=' ' >*/
    s_copy(feq_gen_cpnt_elev_ts_d_, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1);
/* SOURCE inv_gate.for:366 */
/*<       ups_elev_ts=' ' >*/
    s_copy(feq_gen_ups_elev_ts_d_, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1);
/* SOURCE inv_gate.for:367 */
/*<       dns_elev_ts=' ' >*/
    s_copy(feq_gen_dns_elev_ts_d_, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1);
/* SOURCE inv_gate.for:368 */
/*<       gate_flow_ts=' ' >*/
    s_copy(feq_gen_gate_flow_ts_d_, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1);
/* SOURCE inv_gate.for:369 */
/*<       drain_loc='DNS' >*/
    s_copy(feq_gen_drain_loc_d_, const_cast<char*>("DNS"), (ftnlen)3, (ftnlen)3);
/* SOURCE inv_gate.for:370 */
/*<       min_flow=0.0 >*/
    *feq_gen_min_flow_d_ = (float)0.;
/* SOURCE inv_gate.for:371 */
/*<       output_level='MIN' >*/
    s_copy(feq_gen_output_level_d_, const_cast<char*>("MIN"), (ftnlen)3, (ftnlen)3);
/* SOURCE inv_gate.for:372 */
/*<       reverse_flow='NO ' >*/
    s_copy(feq_gen_reverse_flow_d_, const_cast<char*>("NO "), (ftnlen)3, (ftnlen)3);
/*     Select option for GETVAL to return BOTH the string value */
/*     and the converted value for numeric responses. */
/*     In some cases the value will be recomputed. */
/* SOURCE inv_gate.for:377 */
/*<       opt=2 >*/
    opt = 2;
/*     Start a loop over input lines */
/* SOURCE inv_gate.for:379 */
/*<   100 continue >*/
L100:
/* SOURCE inv_gate.for:382 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE inv_gate.for:386 */
/*<       it=lenstr(line) >*/
    it = lenstr_(line, (ftnlen)120);
/* SOURCE inv_gate.for:387 */
/*<       write(stdout,60)line(1:it) >*/
    feq_gen_io_d__40.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__40);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE inv_gate.for:389 */
/*<       line(it+1:it+1)='''' >*/
    feq_gen_i_d_1 = it;
    s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE inv_gate.for:391 */
/*<        >*/
    getval_(stdout, line, &feq_gen_c_d_98, &opt, feq_gen_item_type_d_, ival, rval, dpval, cval, 
	    clen, &eflag2, term, terml, termcls, &feq_gen_item_knt_d_, (ftnlen)120, (
	    ftnlen)256, (ftnlen)1);
/* SOURCE inv_gate.for:396 */
/*<        >*/
    feq_gen_io_d__51.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__51);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Return from GETVAL in GET_INV_GATE: ITEM_KNT="), (
	    ftnlen)46);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_item_knt_d_, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE inv_gate.for:398 */
/*<       write(stdout,97) >*/
    feq_gen_io_d__52.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__52);
    e_wsfe();
/* SOURCE inv_gate.for:399 */
/*<    97 format(1x,12x,'ITEM','   LEN  TYPE T  TCLS') >*/
/* SOURCE inv_gate.for:400 */
/*<       do9213i=1,item_knt >*/
    feq_gen_i_d_1 = feq_gen_item_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inv_gate.for:401 */
/*<       write(stdout,99)cval(i),clen(i),item_type(i),term(i),termcls(i) >*/
	feq_gen_io_d__54.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__54);
	do_fio(&feq_gen_c_d_1, cval + (feq_gen_i_d_ - 1 << 8), (ftnlen)256);
	do_fio(&feq_gen_c_d_1, (char *)&clen[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_item_type_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, term + (feq_gen_i_d_ - 1), (ftnlen)1);
	do_fio(&feq_gen_c_d_1, (char *)&termcls[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE inv_gate.for:403 */
/*<    99 format(' ',a16,' ',i5,' ',i5,' ',a1,' ',i5) >*/
/* SOURCE inv_gate.for:404 */
/*<  9213 continue >*/
/* L9213: */
    }
/* SOURCE inv_gate.for:407 */
/*<       if(eflag2.ne.0)then >*/
    if (eflag2 != 0) {
/*         Error in parsing the line of input. */
/* SOURCE inv_gate.for:410 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__55.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__55);
	e_wsfe();
/* SOURCE inv_gate.for:411 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE inv_gate.for:412 */
/*<       else >*/
    } else {
/*         No errors reported.  Process the items found on the current */
/*         line. */
/*         Check for the end of input */
/* SOURCE inv_gate.for:417 */
/*<       if(cval(1).eq.'END')then >*/
	if (s_cmp(cval, const_cast<char*>("END"), (ftnlen)256, (ftnlen)3) == 0) {
/*           end of input. we are done. */
/* SOURCE inv_gate.for:419 */
/*<       return >*/
	    return 0;
/* SOURCE inv_gate.for:420 */
/*<       endif >*/
	}
/* SOURCE inv_gate.for:422 */
/*<        >*/
	feq_gen_chk_and_convert_response_d_(stdout, &feq_gen_c_d_15, feq_gen_symbol_table_d_, 
		feq_gen_response_type_d_, feq_gen_convert_rule_d_, &feq_gen_item_knt_d_, feq_gen_item_type_d_, 
		cval, clen, eflag, ival, rval, dpval, (ftnlen)16, (ftnlen)256)
		;
/* SOURCE inv_gate.for:428 */
/*<       i=1 >*/
	feq_gen_i_d_ = 1;
/* SOURCE inv_gate.for:429 */
/*<   110 continue >*/
L110:
/*           Find the value for the next item from the */
/*           symbol table. */
/* SOURCE inv_gate.for:432 */
/*<       key=cval(i)(1:clen(i)) >*/
	s_copy(key, cval + (feq_gen_i_d_ - 1 << 8), (ftnlen)16, clen[feq_gen_i_d_ - 1]);
/* SOURCE inv_gate.for:433 */
/*<       calllstab(key,symbol_table,n_symbol,ip) >*/
	lstab_(key, feq_gen_symbol_table_d_, &feq_gen_c_d_15, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE inv_gate.for:436 */
/*<       if(ip.eq.0)then >*/
	if (ip == 0) {
/*             error-symbol not found */
/* SOURCE inv_gate.for:438 */
/*<       write(stdout,54)key >*/
	    feq_gen_io_d__58.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__58);
	    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	    e_wsfe();
/* SOURCE inv_gate.for:439 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE inv_gate.for:441 */
/*<       else >*/
	} else {
/* SOURCE inv_gate.for:442 */
/*<       selection=symbol_value(ip) >*/
	    selection = feq_gen_symbol_value_d_[ip - 1];
/* SOURCE inv_gate.for:443 */
/*<       endif >*/
	}
/* SOURCE inv_gate.for:445 */
/*<       goto(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15),selection >*/
	switch (selection) {
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
/* SOURCE inv_gate.for:448 */
/*<       write(stdout,52)i,key >*/
	feq_gen_io_d__60.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__60);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	e_wsfe();
/* SOURCE inv_gate.for:449 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE inv_gate.for:451 */
/*<     1 continue >*/
L1:
/*             File name for the series at the control point. */
/* SOURCE inv_gate.for:453 */
/*<       cpnt_elev_ts=cval(i+1) >*/
	s_copy(feq_gen_cpnt_elev_ts_d_, cval + (feq_gen_i_d_ << 8), (ftnlen)64, (ftnlen)256);
/* SOURCE inv_gate.for:454 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:455 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:456 */
/*<     2 continue >*/
L2:
/*             File name for the series at the ups node for the gate */
/* SOURCE inv_gate.for:458 */
/*<       ups_elev_ts=cval(i+1) >*/
	s_copy(feq_gen_ups_elev_ts_d_, cval + (feq_gen_i_d_ << 8), (ftnlen)64, (ftnlen)256);
/* SOURCE inv_gate.for:459 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:460 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:461 */
/*<     3 continue >*/
L3:
/*             File name for the series at the dns node for the gate */
/* SOURCE inv_gate.for:463 */
/*<       dns_elev_ts=cval(i+1) >*/
	s_copy(feq_gen_dns_elev_ts_d_, cval + (feq_gen_i_d_ << 8), (ftnlen)64, (ftnlen)256);
/* SOURCE inv_gate.for:464 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:465 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:466 */
/*<     4 continue >*/
L4:
/*             File name for the series giving the flow through the gate. */
/* SOURCE inv_gate.for:468 */
/*<       gate_flow_ts=cval(i+1) >*/
	s_copy(feq_gen_gate_flow_ts_d_, cval + (feq_gen_i_d_ << 8), (ftnlen)64, (ftnlen)256);
/* SOURCE inv_gate.for:469 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:470 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:471 */
/*<     5 continue >*/
L5:
/*             Location of node for the reservoir */
/* SOURCE inv_gate.for:473 */
/*<       drain_loc=cval(i+1) >*/
	s_copy(feq_gen_drain_loc_d_, cval + (feq_gen_i_d_ << 8), (ftnlen)3, (ftnlen)256);
/* SOURCE inv_gate.for:474 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:475 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:476 */
/*<     6 continue >*/
L6:
/*             Table number for dns to upstream flow through the gate */
/* SOURCE inv_gate.for:478 */
/*<       du_table=ival(i+1) >*/
	*feq_gen_du_table_d_ = ival[feq_gen_i_d_];
/* SOURCE inv_gate.for:479 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:480 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:481 */
/*<     7 continue >*/
L7:
/*             Table number for  ups to dns flow through the gate */
/* SOURCE inv_gate.for:483 */
/*<       ud_table=ival(i+1) >*/
	*feq_gen_ud_table_d_ = ival[feq_gen_i_d_];
/* SOURCE inv_gate.for:484 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:485 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:486 */
/*<     8 continue >*/
L8:
/*             Id number for the control table. */
/* SOURCE inv_gate.for:488 */
/*<       control_tab=ival(i+1) >*/
	*feq_gen_control_tab_d_ = ival[feq_gen_i_d_];
/* SOURCE inv_gate.for:489 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:490 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:491 */
/*<     9 continue >*/
L9:
/*             Process the column arguments. */
/* SOURCE inv_gate.for:493 */
/*<        >*/
	feq_gen_get_multiple_real_values_d_(stdin, stdout, &feq_gen_c_d_1, &feq_gen_c_d_2, &feq_gen_c_d_5, &opt, &
		feq_gen_c_d_98, line, feq_gen_item_type_d_, ival, rval, dpval, cval, clen, &
		eflag2, term, terml, termcls, &feq_gen_item_knt_d_, feq_gen_n_col_bdys_d_, &
		feq_gen_col_bdys_d_[1], (ftnlen)120, (ftnlen)256, (ftnlen)1);
/*               Force next line */
/* SOURCE inv_gate.for:501 */
/*<       i=2048 >*/
	feq_gen_i_d_ = 2048;
/* SOURCE inv_gate.for:502 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:503 */
/*<    10 continue >*/
L10:
/*             Process the row arguments */
/* SOURCE inv_gate.for:505 */
/*<        >*/
	feq_gen_get_multiple_real_values_d_(stdin, stdout, &feq_gen_c_d_1, &feq_gen_c_d_2, &feq_gen_c_d_5, &opt, &
		feq_gen_c_d_98, line, feq_gen_item_type_d_, ival, rval, dpval, cval, clen, &
		eflag2, term, terml, termcls, &feq_gen_item_knt_d_, feq_gen_n_row_bdys_d_, &
		feq_gen_row_bdys_d_[1], (ftnlen)120, (ftnlen)256, (ftnlen)1);
/*               Force next line */
/* SOURCE inv_gate.for:513 */
/*<       i=2048 >*/
	feq_gen_i_d_ = 2048;
/* SOURCE inv_gate.for:514 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:515 */
/*<    11 continue >*/
L11:
/*             Elevation at control point at beginning of flooding. */
/* SOURCE inv_gate.for:517 */
/*<       flood_elev=rval(i+1) >*/
	*feq_gen_flood_elev_d_ = rval[feq_gen_i_d_];
/* SOURCE inv_gate.for:518 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:519 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:520 */
/*<    12 continue >*/
L12:
/*             Flow at the control point at beginning of flooding */
/* SOURCE inv_gate.for:522 */
/*<       flood_flow=rval(i+1) >*/
	*feq_gen_flood_flow_d_ = rval[feq_gen_i_d_];
/* SOURCE inv_gate.for:523 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:524 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:525 */
/*<    13 continue >*/
L13:
/*             Minimum flow that is treated as non-zero.  All flows */
/*             less than this value are set to zero before solving */
/*             for the gate setting. */
/* SOURCE inv_gate.for:529 */
/*<       min_flow=rval(i+1) >*/
	*feq_gen_min_flow_d_ = rval[feq_gen_i_d_];
/* SOURCE inv_gate.for:530 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:531 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:532 */
/*<    14 continue >*/
L14:
/*             Output level */
/* SOURCE inv_gate.for:534 */
/*<       output_level=cval(i+1) >*/
	s_copy(feq_gen_output_level_d_, cval + (feq_gen_i_d_ << 8), (ftnlen)3, (ftnlen)256);
/* SOURCE inv_gate.for:535 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:536 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:537 */
/*<    15 continue >*/
L15:
/*             Reverse flow signal */
/* SOURCE inv_gate.for:539 */
/*<       reverse_flow=cval(i+1) >*/
	s_copy(feq_gen_reverse_flow_d_, cval + (feq_gen_i_d_ << 8), (ftnlen)3, (ftnlen)256);
/* SOURCE inv_gate.for:540 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE inv_gate.for:541 */
/*<       goto149 >*/
	goto L149;
/* SOURCE inv_gate.for:543 */
/*<   149 continue >*/
L149:
/* SOURCE inv_gate.for:544 */
/*<       if(i.gt.item_knt)then >*/
	if (feq_gen_i_d_ > feq_gen_item_knt_d_) {
/*               Get the next line from the input */
/* SOURCE inv_gate.for:546 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE inv_gate.for:547 */
/*<       else >*/
	} else {
/*               Get the next item from the current line */
/* SOURCE inv_gate.for:549 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE inv_gate.for:550 */
/*<       endif >*/
	}
/* SOURCE inv_gate.for:551 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:553 */
/*<       end >*/
    return 0;
} /* get_inv_gate__ */




/* SOURCE inv_gate.for:557 */
/*<       integerfunctionget_type13_address(ty15_adrs) >*/
integer feq_gen_get_type13_address_d_(integer *feq_gen_ty15_adrs_d_)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    integer ip;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Get the address of the first type 13 table in a table of */
/*     type 15 given its address. */
/* SOURCE inv_gate.for:562 */
/*<       integerty15_adrs >*/
/* INCLUDE inv_gate.for:564 */
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
/* INCLUDE inv_gate.for:565 */
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
/*     Local */
/* SOURCE inv_gate.for:569 */
/*<       integerip >*/
/* *********************************************************************** */
/* SOURCE inv_gate.for:571 */
/*<       ip=ty15_adrs >*/
    ip = *feq_gen_ty15_adrs_d_;
/* SOURCE inv_gate.for:572 */
/*<       get_type13_address=itab(ip+5+1) >*/
    ret_val = itab[ip + 6];
/* SOURCE inv_gate.for:573 */
/*<       return >*/
    return ret_val;
/* SOURCE inv_gate.for:574 */
/*<       end >*/
} /* get_type13_address__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE inv_gate.for:578 */
/*<       realfunctionget_max_gate(ty15_adrs) >*/
doublereal feq_gen_get_max_gate_d_(integer *feq_gen_ty15_adrs_d_)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    integer ip;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Get the maximum gate opening. */
/* SOURCE inv_gate.for:582 */
/*<       integerty15_adrs >*/
/* INCLUDE inv_gate.for:584 */
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
/* INCLUDE inv_gate.for:585 */
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
/*     Local */
/* SOURCE inv_gate.for:589 */
/*<       integerip >*/
/* *********************************************************************** */
/* SOURCE inv_gate.for:591 */
/*<       ip=itab(ty15_adrs) >*/
    ip = itab[*feq_gen_ty15_adrs_d_];
/* SOURCE inv_gate.for:592 */
/*<       get_max_gate=ftab(ip) >*/
    ret_val = ftab[ip];
/* SOURCE inv_gate.for:593 */
/*<       return >*/
    return ret_val;
/* SOURCE inv_gate.for:594 */
/*<       end >*/
} /* get_max_gate__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE inv_gate.for:600 */
/*<       subroutineinv_gate(grav,stdin,stdout,stdtab,eflag,tabdir) >*/
/* Subroutine */ int feq_gen_inv_gate_d_(real *grav, integer *stdin, integer *stdout, 
	integer *stdtab, integer *eflag, integer *feq_storage_tabdir)
{
    /* Initialized data */

    static doublereal eps = 1e-6;

    /* Format strings */
    static char fmt_50[] = "(/,\002 Elevation time series file for control p\
oint=\002,/,5x,a,/,\002 not found.  Please check spelling of name and path\
.\002)";
    static char fmt_51[] = "(/,\002 Elevation time series file for downstrea\
m point=\002,/,5x,a,/,\002 not found.  Please check spelling of name and pat\
h.\002)";
    static char fmt_52[] = "(/,\002 Flow time series file for the underflow \
gate=\002,/,5x,a,/,\002 not found.  Please check spelling of name and path\
.\002)";
    static char fmt_53[] = "(/,\002 Elevation time series file for upstream \
point=\002,/,5x,a,/,\002 not found.  Please check spelling of name and path\
.\002)";
    static char fmt_54[] = "(/,\002 *ERR:XXX* Time mismatch in time series\
:\002/,11x,\002 Control point time series JT=\002,f20.10,/,11x,\002 Ups poin\
t time series JT=\002,f20.10,/,11x,\002 Dns point time series JT=\002,f20.10\
,/,11x,\002 Gate flow time series JT=\002,f20.10)";
    static char fmt_56[] = "(i5,i5,i3,i3,f10.2,f10.3,f10.3,f10.1,f10.3,f10.3\
,a8,i5)";
    static char fmt_58[] = "(/,\002  KNT Year Mn Dy      Hour  Ups head  Dns\
 head      Flow\002,\002   Opening  Fraction FlowTyp Flag\002)";
    static char fmt_60[] = "(/,\002 Datum for heads=\002,f10.3,\002 Maximum \
gate opening=\002,f8.3)";
    static char fmt_62[] = "(/,\002 *ERR:XXX* Ups level\002,f10.3,\002 falls\
 outside the\002,\002 min and max values of:\002,2f10.3)";
    static char fmt_64[] = "(/,\002 *ERR:XXX Head difference=\002,f10.3,\002\
 falls outside the\002,\002 min and max values of:\002,2f10.3)";
    static char fmt_66[] = "(/,\002 Number of occurrences per cell:\002)";
    static char fmt_68[] = "(25i6)";
    static char fmt_72[] = "(f7.2,1x,25a6)";
    static char fmt_73[] = "(8x,25a6)";
    static char fmt_74[] = "(/,\002 Summary of Results\002)";
    static char fmt_75[] = "(\002 Cell  \002,\002  Type \002,24f6.1)";
    static char fmt_76[] = "(\002 Bdys  \002,\002       \002,24f6.1)";
    static char fmt_61[] = "(/,\002 DU_TABLE=\002,i6,\002 UD_TABLE=\002,i6\
,\002 CONTROL_TAB=\002,i6,\002 FLOOD_ELEV=\002,f8.3,\002 FLOOD_FLOW=\002,f8.\
1,/,\002 CPNT_ELEV_TS=\002,a,/,\002 UPS_ELEV_TS=\002,a,/,\002 DNS_ELEV_TS\
=\002,a,/,\002 GATE_FLOW_TS=\002,a,/,\002 DRAIN_LOC=\002,a,\002 MIN_FLOW=\
\002,f10.2,\002 OUTPUT_LEVEL=\002,a,\002 REVERSE_FLOW=\002,a)";
    static char fmt_63[] = "(/,\002 COL_BDYS=\002,(10f10.2))";
    static char fmt_65[] = "(/,\002 ROW_BDYS=\002,(10f10.2))";

    /* System generated locals */
    address feq_gen_a_d_1[3];
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3[3];
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2, feq_gen_d_d_3;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    f_inqu(inlist *), f_open(olist *), s_rsue(cilist *), do_uio(
	    integer *, char *, ftnlen), e_rsue();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(), s_wsfi(icilist *)
	    , e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);

    /* Local variables */
    integer feq_gen_du_table_d_, feq_gen_ud_table_d_;
    char feq_gen_col_args_d_[8*19];
    real feq_gen_col_bdys_d_[20], feq_gen_dns_elev_d_, feq_gen_min_flow_d_;
    extern integer feq_gen_get_unit_d_(integer *);
    real feq_gen_ups_elev_d_;
    integer feq_gen_dns_unit_d_;
    char feq_gen_row_args_d_[8*40];
    real feq_gen_row_bdys_d_[41];
    integer feq_gen_ups_unit_d_, feq_gen_i_d_, j;
    real p;
    char feq_gen_drain_loc_d_[3];
    real feq_gen_gate_flow_d_;
    integer feq_gen_gate_unit_d_;
    real feq_gen_cpnt_elev_d_;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *), 
	    feq_gen_find_gate_opening_d_(integer *, integer *, integer *, real *, real 
	    *, real *, real *, real *, real *, real *, char *, integer *, 
	    integer *, ftnlen);
    integer feq_gen_ups_given_d_, feq_gen_cpnt_unit_d_;
    extern /* Subroutine */ int feq_gen_type10_out_d_(integer *, integer *, integer *, 
	    integer *, integer *, char *, real *, char *, char *, char *, 
	    char *, char *, char *, char *, char *, char *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    extern integer feq_gen_get_type13_address_d_(integer *);
    real hd, hg, hr;
    integer mn, dy;
    real hu, tp;
    integer yr, feq_gen_n_per_cell_d_[760]	/* was [40][19] */, feq_gen_n_col_bdys_d_;
    real feq_gen_flood_elev_d_;
    integer feq_gen_ftype_code_d_;
    real feq_gen_flood_flow_d_;
    integer feq_gen_n_row_bdys_d_, mjd, knt;
    char feq_gen_nc_per_cell_d_[6*40*19], feq_gen_pc_per_cell_d_[8*40*19], chr3[3], 
	    feq_gen_dns_elev_ts_d_[64];
    integer feq_gen_control_tab_d_, feq_gen_result_flag_d_;
    char feq_gen_ups_elev_ts_d_[64];
    doublereal frac;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char hdin[24];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern doublereal feq_gen_get_max_gate_d_(integer *);
    real feq_gen_min_per_cell_d_[760]	/* was [40][19] */, feq_gen_max_per_cell_d_[760]	/* 
	    was [40][19] */;
    extern /* Subroutine */ int feq_gen_get_inv_gate_d_(integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, real *, char *, char *, char *, char *, char *, 
	    real *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen);
    real feq_gen_sum_per_cell_d_[760]	/* was [40][19] */;
    char feq_gen_gate_flow_ts_d_[64], feq_gen_cpnt_elev_ts_d_[64], feq_gen_reverse_flow_d_[3], label[50];
    real hdiff;
    char feq_gen_chr3_1_d_[3];
    integer icode;
    char feq_gen_output_level_d_[3];
    logical there;
    char hdout[24];
    extern /* Subroutine */ int ckty15_(integer *, integer *, integer *);
    char ftype[8], feq_gen_minc_per_cell_d_[6*40*19], feq_gen_maxc_per_cell_d_[6*40*19], rowin[
	    24];
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern doublereal gethdd_(integer *);
    real feq_gen_hg_max_d_;
    char hditem[24];
    real hdatum;
    doublereal feq_gen_dns_jt_d_;
    char rowlab[8];
    extern /* Subroutine */ int invmjd_(integer *, integer *, integer *, 
	    integer *);
    doublereal feq_gen_ups_jt_d_;
    char rowout[24];
    doublereal feq_gen_gate_jt_d_, feq_gen_cpnt_jt_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_63, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__106 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__117 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__134 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__145 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__158 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__159 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__160 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__164 = { 0, 0, 0, 0, 0 };


/*     Inverts an underflow gate to create a control table to operate */
/*     the gate.  Gate inversion computes the gate opening to match */
/*     the flow produced by some fixed structure so that the gate */
/*     operation will approximate the fixed structure.  This then */
/*     creates a first approximation to the gate control tables. */
/* SOURCE inv_gate.for:609 */
/*<       implicitnone >*/
/*     Dummy arguments */
/* SOURCE inv_gate.for:612 */
/*<       integereflag,stdin,stdout,stdtab >*/
/* SOURCE inv_gate.for:613 */
/*<       integertabdir(*) >*/
/* SOURCE inv_gate.for:614 */
/*<       realgrav >*/
/*     DEFINITIONS */
/*     GRAV   - value of acceleration due to gravity */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TABDIR - Table directory to remember table numbers */
/* INCLUDE inv_gate.for:624 */
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
/* INCLUDE inv_gate.for:625 */
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
/*     Define key local values: */
/*     UD_TABLE= table number giving the type 15 rating table for the */
/*                gate for flow from the upstream node to the downstream */
/*                node. */
/*     DU_TABLE= table number giving the type 15 rating table for */
/*                the gate for flow from the downstream node to the */
/*                upstream node. */
/*     CPNT_ELEV_TS = file name for the time series of elevation at the */
/*                 control point for the structure.  The control */
/*                 is the exterior node giving the elevation */
/*                 defining the operation of the gate. */
/*     UPS_ELEV_TS = file name for the time series of elevation at the */
/*                node upstream of the gate.  Upstream is defined */
/*                by the user with the rule that the flow, given */
/*                in another time series, must always be positive */
/*                for flow from the upstream node to the downstream */
/*                node.  Given only when the control-point location */
/*                is different than the upstream-node location. */
/*     DNS_ELEV_TS = file name for the time series of elevation at the */
/*                node downstream of the gate. */
/*     GATE_FLOW_TS = file name for the time series of flows through the gate. */
/*     FLOOD_ELEV = the elevation at the control point that defines */
/*                  the zero point on the sequence of arguments for */
/*                  rows of the control table.  This is the elevation */
/*                  at the control point that often signals flood */
/*                  hazard at some point downstream. */
/*     FLOOD_FLOW = the flow at the control point when the elevation */
/*                  is at FLOOD_ELEV.  Used to estimate the gate */
/*                  operation for draining of the reservoir. The */
/*                  difference between the FLOOD_FLOW and the current */
/*                  flow at the cotnrol point gives the maximum */
/*                  flow release possible. */
/*     CONTROL_TAB = the table number for the control table computed */
/*                    by the GATE_INV command. */
/*     COL_BDYS = the  sequence of  boundary values defining  the cells */
/*                for the columns of the type 10 table.  The midpoint of the */
/*                cell will become the argument value in the table. */
/*                downstream node for the gate. */
/*     ROW_BDYS = the  sequence of  boundary values defining  the cells */
/*                for the rows of the type 10 table.  The midpoint of the */
/*                cell will become the argument value in the table. */
/*       Note: The combination of ROW_BDYS and COL_BDYS defines an */
/*             array of relative gate openings at the intersection of */
/*             each pair of  arguments.  A gate opening of 0.0 */
/*             denotes a closed gate and a gate opening of 1.0 denotes */
/*             a gate fully open.  The gate openings for points intermediate */
/*             to those tabulated are defined by linear interpolation. */
/*     DRAIN_LOC = the location defining the node that represents the */
/*                 the reservoir to be drained.  Has two values UPS or */
/*                 DNS. */
/*     MIN_FLOW =  all flows less than this value are treated as zero flow. */

/*     OUTPUT_LEVEL= user control on output level:  MIN gives the minimum */
/*                   level with the summary tables only.  MAX gives the */
/*                   results for each flow greater than MIN_FLOW. */
/*     REVERSE_FLOW= if YES, reverse flows are included.  If NO reverse */
/*                   flows are excluded.  If YES, MIN_FLOW refers to the */
/*                   absolute value of the flow. */
/*     N_PER_CELL(*,*)- number of cases per cell. */
/*     SUM_PER-CELL(*,*) - sum of the gate openings in a cell. */
/*     MAX_PER_CELL(*,*) - maximum gate opening in a cell. */
/*     MIN_PER_CELL(*,*) - minimum gate opening in a cell. */
/* SOURCE inv_gate.for:694 */
/*<        >*/
/* SOURCE inv_gate.for:699 */
/*<        >*/
/* SOURCE inv_gate.for:707 */
/*<        >*/
/* SOURCE inv_gate.for:721 */
/*<       logicalthere >*/
/* SOURCE inv_gate.for:723 */
/*<       real*8cpnt_jt,ups_jt,dns_jt,gate_jt,eps,frac >*/
/*     External program units */
/* SOURCE inv_gate.for:727 */
/*<       integerget_unit,get_type13_address >*/
/* SOURCE inv_gate.for:729 */
/*<       realgethdd,get_max_gate,tp >*/
/* SOURCE inv_gate.for:731 */
/*<        >*/
/*     ***********************************FORMATS************************ */
/* SOURCE inv_gate.for:734 */
/*<       dataeps/1.d-6/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* SOURCE inv_gate.for:737 */
/*<    50  >*/
/* L50: */
/* SOURCE inv_gate.for:739 */
/*<    51  >*/
/* L51: */
/* SOURCE inv_gate.for:741 */
/*<    52  >*/
/* L52: */
/* SOURCE inv_gate.for:743 */
/*<    53  >*/
/* L53: */
/* SOURCE inv_gate.for:745 */
/*<    54  >*/
/* L54: */
/* SOURCE inv_gate.for:750 */
/*<    56 format(i5,i5,i3,i3,f10.2,f10.3,f10.3,f10.1,f10.3,f10.3,a8,i5) >*/
/* L56: */
/* SOURCE inv_gate.for:751 */
/*<    57 format(i5,i3,i3,f10.2,f10.3) >*/
/* L57: */
/* SOURCE inv_gate.for:752 */
/*<    58  >*/
/* L58: */
/* SOURCE inv_gate.for:755 */
/*<    60 format(/,' Datum for heads=',f10.3,' Maximum gate opening=',f8.3) >*/
/* L60: */
/* SOURCE inv_gate.for:756 */
/*<    62  >*/
/* L62: */
/* SOURCE inv_gate.for:758 */
/*<    64  >*/
/* L64: */
/* SOURCE inv_gate.for:760 */
/*<    66 format(/,' Number of occurrences per cell:') >*/
/* L66: */
/* SOURCE inv_gate.for:761 */
/*<    68 format(25i6) >*/
/* L68: */
/* SOURCE inv_gate.for:762 */
/*<    70 format(/,' Mean gate opening per cell:') >*/
/* L70: */
/* SOURCE inv_gate.for:763 */
/*<    72 format(f7.2,1x,25a6) >*/
/* L72: */
/* SOURCE inv_gate.for:764 */
/*<    73 format(8x,25a6) >*/
/* L73: */
/* SOURCE inv_gate.for:765 */
/*<    74 format(/,' Summary of Results') >*/
/* L74: */
/* SOURCE inv_gate.for:766 */
/*<    75 format(' Cell  ','  Type ',24f6.1) >*/
/* L75: */
/* SOURCE inv_gate.for:767 */
/*<    76 format(' Bdys  ','       ',24f6.1) >*/
/* L76: */
/* *********************************************************************** */
/* SOURCE inv_gate.for:771 */
/*<        >*/
    feq_gen_get_inv_gate_d_(stdin, stdout, eflag, &feq_gen_du_table_d_, &feq_gen_ud_table_d_, &
	    feq_gen_n_col_bdys_d_, &feq_gen_n_row_bdys_d_, &feq_gen_control_tab_d_, feq_gen_col_bdys_d_, 
	    feq_gen_row_bdys_d_, &feq_gen_flood_elev_d_, &feq_gen_flood_flow_d_, feq_gen_cpnt_elev_ts_d_, 
	    feq_gen_ups_elev_ts_d_, feq_gen_dns_elev_ts_d_, feq_gen_gate_flow_ts_d_, feq_gen_drain_loc_d_, &
	    feq_gen_min_flow_d_, feq_gen_output_level_d_, feq_gen_reverse_flow_d_, (ftnlen)64, (ftnlen)
	    64, (ftnlen)64, (ftnlen)64, (ftnlen)3, (ftnlen)3, (ftnlen)3);
/*     Check the values so far. */
/* SOURCE inv_gate.for:781 */
/*<        >*/
    feq_gen_io_d__90.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__90);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_du_table_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ud_table_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_control_tab_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_flood_elev_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_flood_flow_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, feq_gen_cpnt_elev_ts_d_, (ftnlen)64);
    do_fio(&feq_gen_c_d_1, feq_gen_ups_elev_ts_d_, (ftnlen)64);
    do_fio(&feq_gen_c_d_1, feq_gen_dns_elev_ts_d_, (ftnlen)64);
    do_fio(&feq_gen_c_d_1, feq_gen_gate_flow_ts_d_, (ftnlen)64);
    do_fio(&feq_gen_c_d_1, feq_gen_drain_loc_d_, (ftnlen)3);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_min_flow_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, feq_gen_output_level_d_, (ftnlen)3);
    do_fio(&feq_gen_c_d_1, feq_gen_reverse_flow_d_, (ftnlen)3);
    e_wsfe();
/* SOURCE inv_gate.for:786 */
/*<    61  >*/
/* SOURCE inv_gate.for:794 */
/*<       write(stdout,63)(col_bdys(j),j=1,n_col_bdys) >*/
    feq_gen_io_d__91.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__91);
    feq_gen_i_d_1 = feq_gen_n_col_bdys_d_;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_col_bdys_d_[j - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* SOURCE inv_gate.for:795 */
/*<    63 format(/,' COL_BDYS=',(10f10.2)) >*/
/* SOURCE inv_gate.for:796 */
/*<       write(stdout,65)(row_bdys(j),j=1,n_row_bdys) >*/
    feq_gen_io_d__93.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__93);
    feq_gen_i_d_1 = feq_gen_n_row_bdys_d_;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_row_bdys_d_[j - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* SOURCE inv_gate.for:797 */
/*<    65 format(/,' ROW_BDYS=',(10f10.2)) >*/
/*     Initialize the arrays used for counting and recording. */
/* SOURCE inv_gate.for:800 */
/*<       do110i=1,n_row_bdys-1 >*/
    feq_gen_i_d_1 = feq_gen_n_row_bdys_d_ - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inv_gate.for:801 */
/*<       do100j=1,n_col_bdys-1 >*/
	feq_gen_i_d_2 = feq_gen_n_col_bdys_d_ - 1;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE inv_gate.for:802 */
/*<       n_per_cell(i,j)=0 >*/
	    feq_gen_n_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] = 0;
/* SOURCE inv_gate.for:803 */
/*<       sum_per_cell(i,j)=0.0 >*/
	    feq_gen_sum_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] = (float)0.;
/* SOURCE inv_gate.for:804 */
/*<       max_per_cell(i,j)=0.0 >*/
	    feq_gen_max_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] = (float)0.;
/* SOURCE inv_gate.for:805 */
/*<       min_per_cell(i,j)=1.0 >*/
	    feq_gen_min_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] = (float)1.;
/* SOURCE inv_gate.for:806 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE inv_gate.for:807 */
/*<   110 continue >*/
/* L110: */
    }
/*     Process the time series references */
/* SOURCE inv_gate.for:812 */
/*<       inquire(file=cpnt_elev_ts,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 64;
    feq_gen_ioin_d_1.infile = feq_gen_cpnt_elev_ts_d_;
    feq_gen_ioin_d_1.inex = &there;
    feq_gen_ioin_d_1.inopen = 0;
    feq_gen_ioin_d_1.innum = 0;
    feq_gen_ioin_d_1.innamed = 0;
    feq_gen_ioin_d_1.inname = 0;
    feq_gen_ioin_d_1.inacc = 0;
    feq_gen_ioin_d_1.inseq = 0;
    feq_gen_ioin_d_1.indir = 0;
    feq_gen_ioin_d_1.infmt = 0;
    feq_gen_ioin_d_1.inform = 0;
    feq_gen_ioin_d_1.inunf = 0;
    feq_gen_ioin_d_1.inrecl = 0;
    feq_gen_ioin_d_1.innrec = 0;
    feq_gen_ioin_d_1.inblank = 0;
    f_inqu(&feq_gen_ioin_d_1);
/* SOURCE inv_gate.for:814 */
/*<       if(there)then >*/
    if (there) {
/*       Assign a unit number and attempt to open the file. */
/* SOURCE inv_gate.for:816 */
/*<       cpnt_unit=get_unit(stdout) >*/
	feq_gen_cpnt_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE inv_gate.for:817 */
/*<       open(cpnt_unit,file=cpnt_elev_ts,form='UNFORMATTED',status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_cpnt_unit_d_;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = feq_gen_cpnt_elev_ts_d_;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE inv_gate.for:819 */
/*<       read(cpnt_unit)icode >*/
	feq_gen_io_d__101.ciunit = feq_gen_cpnt_unit_d_;
	s_rsue(&feq_gen_io_d__101);
	do_uio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
	e_rsue();
/* SOURCE inv_gate.for:820 */
/*<       else >*/
    } else {
/* SOURCE inv_gate.for:821 */
/*<       write(stdout,50)cpnt_elev_ts >*/
	feq_gen_io_d__103.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__103);
	do_fio(&feq_gen_c_d_1, feq_gen_cpnt_elev_ts_d_, (ftnlen)64);
	e_wsfe();
/* SOURCE inv_gate.for:822 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE inv_gate.for:823 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:825 */
/*<       inquire(file=dns_elev_ts,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 64;
    feq_gen_ioin_d_1.infile = feq_gen_dns_elev_ts_d_;
    feq_gen_ioin_d_1.inex = &there;
    feq_gen_ioin_d_1.inopen = 0;
    feq_gen_ioin_d_1.innum = 0;
    feq_gen_ioin_d_1.innamed = 0;
    feq_gen_ioin_d_1.inname = 0;
    feq_gen_ioin_d_1.inacc = 0;
    feq_gen_ioin_d_1.inseq = 0;
    feq_gen_ioin_d_1.indir = 0;
    feq_gen_ioin_d_1.infmt = 0;
    feq_gen_ioin_d_1.inform = 0;
    feq_gen_ioin_d_1.inunf = 0;
    feq_gen_ioin_d_1.inrecl = 0;
    feq_gen_ioin_d_1.innrec = 0;
    feq_gen_ioin_d_1.inblank = 0;
    f_inqu(&feq_gen_ioin_d_1);
/* SOURCE inv_gate.for:827 */
/*<       if(there)then >*/
    if (there) {
/*       Assign a unit number and attempt to open the file. */
/* SOURCE inv_gate.for:829 */
/*<       dns_unit=get_unit(stdout) >*/
	feq_gen_dns_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE inv_gate.for:830 */
/*<       open(dns_unit,file=dns_elev_ts,form='UNFORMATTED',status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_dns_unit_d_;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = feq_gen_dns_elev_ts_d_;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE inv_gate.for:832 */
/*<       read(dns_unit)icode >*/
	feq_gen_io_d__105.ciunit = feq_gen_dns_unit_d_;
	s_rsue(&feq_gen_io_d__105);
	do_uio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
	e_rsue();
/* SOURCE inv_gate.for:833 */
/*<       else >*/
    } else {
/* SOURCE inv_gate.for:834 */
/*<       write(stdout,51)dns_elev_ts >*/
	feq_gen_io_d__106.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__106);
	do_fio(&feq_gen_c_d_1, feq_gen_dns_elev_ts_d_, (ftnlen)64);
	e_wsfe();
/* SOURCE inv_gate.for:835 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE inv_gate.for:836 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:838 */
/*<       inquire(file=gate_flow_ts,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 64;
    feq_gen_ioin_d_1.infile = feq_gen_gate_flow_ts_d_;
    feq_gen_ioin_d_1.inex = &there;
    feq_gen_ioin_d_1.inopen = 0;
    feq_gen_ioin_d_1.innum = 0;
    feq_gen_ioin_d_1.innamed = 0;
    feq_gen_ioin_d_1.inname = 0;
    feq_gen_ioin_d_1.inacc = 0;
    feq_gen_ioin_d_1.inseq = 0;
    feq_gen_ioin_d_1.indir = 0;
    feq_gen_ioin_d_1.infmt = 0;
    feq_gen_ioin_d_1.inform = 0;
    feq_gen_ioin_d_1.inunf = 0;
    feq_gen_ioin_d_1.inrecl = 0;
    feq_gen_ioin_d_1.innrec = 0;
    feq_gen_ioin_d_1.inblank = 0;
    f_inqu(&feq_gen_ioin_d_1);
/* SOURCE inv_gate.for:840 */
/*<       if(there)then >*/
    if (there) {
/*       Assign a unit number and attempt to open the file. */
/* SOURCE inv_gate.for:842 */
/*<       gate_unit=get_unit(stdout) >*/
	feq_gen_gate_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE inv_gate.for:843 */
/*<       open(gate_unit,file=gate_flow_ts,form='UNFORMATTED',status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = feq_gen_gate_unit_d_;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = feq_gen_gate_flow_ts_d_;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE inv_gate.for:845 */
/*<       read(gate_unit)icode >*/
	feq_gen_io_d__108.ciunit = feq_gen_gate_unit_d_;
	s_rsue(&feq_gen_io_d__108);
	do_uio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
	e_rsue();
/* SOURCE inv_gate.for:846 */
/*<       else >*/
    } else {
/* SOURCE inv_gate.for:847 */
/*<       write(stdout,52)gate_flow_ts >*/
	feq_gen_io_d__109.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__109);
	do_fio(&feq_gen_c_d_1, feq_gen_gate_flow_ts_d_, (ftnlen)64);
	e_wsfe();
/* SOURCE inv_gate.for:848 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE inv_gate.for:849 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:852 */
/*<       ups_given=0 >*/
    feq_gen_ups_given_d_ = 0;
/* SOURCE inv_gate.for:853 */
/*<       if(ups_elev_ts.ne.' ')then >*/
    if (s_cmp(feq_gen_ups_elev_ts_d_, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1) != 0) {
/* SOURCE inv_gate.for:854 */
/*<       ups_given=1 >*/
	feq_gen_ups_given_d_ = 1;
/*       User did give an upstream location distinct from */
/*       the control point location.  Therefore, the upstream */
/*       location is not the same as the control point. */
/* SOURCE inv_gate.for:859 */
/*<       inquire(file=ups_elev_ts,exist=there) >*/
	feq_gen_ioin_d_1.inerr = 0;
	feq_gen_ioin_d_1.infilen = 64;
	feq_gen_ioin_d_1.infile = feq_gen_ups_elev_ts_d_;
	feq_gen_ioin_d_1.inex = &there;
	feq_gen_ioin_d_1.inopen = 0;
	feq_gen_ioin_d_1.innum = 0;
	feq_gen_ioin_d_1.innamed = 0;
	feq_gen_ioin_d_1.inname = 0;
	feq_gen_ioin_d_1.inacc = 0;
	feq_gen_ioin_d_1.inseq = 0;
	feq_gen_ioin_d_1.indir = 0;
	feq_gen_ioin_d_1.infmt = 0;
	feq_gen_ioin_d_1.inform = 0;
	feq_gen_ioin_d_1.inunf = 0;
	feq_gen_ioin_d_1.inrecl = 0;
	feq_gen_ioin_d_1.innrec = 0;
	feq_gen_ioin_d_1.inblank = 0;
	f_inqu(&feq_gen_ioin_d_1);
/* SOURCE inv_gate.for:861 */
/*<       if(there)then >*/
	if (there) {
/*         Assign a unit number and attempt to open the file. */
/* SOURCE inv_gate.for:863 */
/*<       ups_unit=get_unit(stdout) >*/
	    feq_gen_ups_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE inv_gate.for:864 */
/*<       open(ups_unit,file=ups_elev_ts,form='UNFORMATTED',status='OLD') >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = feq_gen_ups_unit_d_;
	    feq_gen_o_d_1.ofnmlen = 64;
	    feq_gen_o_d_1.ofnm = feq_gen_ups_elev_ts_d_;
	    feq_gen_o_d_1.orl = 0;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = 0;
	    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE inv_gate.for:866 */
/*<       read(ups_unit)icode >*/
	    feq_gen_io_d__112.ciunit = feq_gen_ups_unit_d_;
	    s_rsue(&feq_gen_io_d__112);
	    do_uio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
	    e_rsue();
/* SOURCE inv_gate.for:867 */
/*<       else >*/
	} else {
/* SOURCE inv_gate.for:868 */
/*<       write(stdout,53)ups_elev_ts >*/
	    feq_gen_io_d__113.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__113);
	    do_fio(&feq_gen_c_d_1, feq_gen_ups_elev_ts_d_, (ftnlen)64);
	    e_wsfe();
/* SOURCE inv_gate.for:869 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE inv_gate.for:870 */
/*<       endif >*/
	}
/* SOURCE inv_gate.for:871 */
/*<       endif >*/
    }
/*     Check that the function tables are known. */
/* SOURCE inv_gate.for:874 */
/*<       callchktab(15,stdout,ftpnt,pmxtab,ud_table,eflag) >*/
    chktab_(&feq_gen_c_d_15, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &feq_gen_ud_table_d_, eflag);
/* SOURCE inv_gate.for:878 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/*       Check the contents of the table to make sure that */
/*       the tables referenced in the table also exist and */
/*       are of the proper type. */
/* SOURCE inv_gate.for:882 */
/*<       callckty15(ud_table,stdout,eflag) >*/
	ckty15_(&feq_gen_ud_table_d_, stdout, eflag);
/* SOURCE inv_gate.for:885 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:886 */
/*<       callchktab(15,stdout,ftpnt,pmxtab,du_table,eflag) >*/
    chktab_(&feq_gen_c_d_15, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &feq_gen_du_table_d_, eflag);
/* SOURCE inv_gate.for:890 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/*       Check the contents of the table to make sure that */
/*       the tables referenced in the table also exist and */
/*       are of the proper type. */
/* SOURCE inv_gate.for:894 */
/*<       callckty15(du_table,stdout,eflag) >*/
	ckty15_(&feq_gen_du_table_d_, stdout, eflag);
/* SOURCE inv_gate.for:897 */
/*<       endif >*/
    }
/*     Find the datum for the type 15 tables.  Type 15 tables do */
/*     do not store their datum; that value is present in the */
/*     type 13 tables within the type 15 table. */
/* SOURCE inv_gate.for:903 */
/*<       hdatum=gethdd(get_type13_address(ud_table)) >*/
    feq_gen_i_d_1 = feq_gen_get_type13_address_d_(&feq_gen_ud_table_d_);
    hdatum = gethdd_(&feq_gen_i_d_1);
/*     Get the maximum gate opening. */
/* SOURCE inv_gate.for:907 */
/*<       hg_max=get_max_gate(ud_table) >*/
    feq_gen_hg_max_d_ = feq_gen_get_max_gate_d_(&feq_gen_ud_table_d_);
/* SOURCE inv_gate.for:909 */
/*<       write(stdout,60)hdatum,hg_max >*/
    feq_gen_io_d__116.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__116);
    do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_hg_max_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE inv_gate.for:911 */
/*<       if(output_level.eq.'MAX')write(stdout,58) >*/
    if (s_cmp(feq_gen_output_level_d_, const_cast<char*>("MAX"), (ftnlen)3, (ftnlen)3) == 0) {
	feq_gen_io_d__117.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__117);
	e_wsfe();
    }
/* SOURCE inv_gate.for:913 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE inv_gate.for:914 */
/*<   200 continue >*/
L200:
/*       We read each time step from the files and then invert the */
/*       gate relationship for each time step and tabulate the */
/*       results. */
/* SOURCE inv_gate.for:919 */
/*<       read(cpnt_unit)cpnt_jt,cpnt_elev >*/
    feq_gen_io_d__119.ciunit = feq_gen_cpnt_unit_d_;
    s_rsue(&feq_gen_io_d__119);
    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_cpnt_jt_d_, (ftnlen)sizeof(doublereal));
    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_cpnt_elev_d_, (ftnlen)sizeof(real));
    e_rsue();
/* SOURCE inv_gate.for:920 */
/*<       if(cpnt_jt.lt.1.d-10)goto9000 >*/
    if (feq_gen_cpnt_jt_d_ < 1e-10) {
	goto L9000;
    }
/* SOURCE inv_gate.for:921 */
/*<       mjd=int(cpnt_jt) >*/
    mjd = (integer) feq_gen_cpnt_jt_d_;
/* SOURCE inv_gate.for:922 */
/*<       frac=cpnt_jt-dble(mjd) >*/
    frac = feq_gen_cpnt_jt_d_ - (doublereal) mjd;
/* SOURCE inv_gate.for:923 */
/*<       hr=24.d0*frac >*/
    hr = frac * 24.;
/* SOURCE inv_gate.for:924 */
/*<       callinvmjd(mjd,yr,mn,dy) >*/
    invmjd_(&mjd, &yr, &mn, &dy);
/* SOURCE inv_gate.for:927 */
/*<       if(ups_given.eq.0)then >*/
    if (feq_gen_ups_given_d_ == 0) {
/* SOURCE inv_gate.for:928 */
/*<       ups_elev=cpnt_elev >*/
	feq_gen_ups_elev_d_ = feq_gen_cpnt_elev_d_;
/* SOURCE inv_gate.for:929 */
/*<       ups_jt=cpnt_jt >*/
	feq_gen_ups_jt_d_ = feq_gen_cpnt_jt_d_;
/* SOURCE inv_gate.for:930 */
/*<       else >*/
    } else {
/* SOURCE inv_gate.for:931 */
/*<       read(ups_unit)ups_jt,ups_elev >*/
	feq_gen_io_d__130.ciunit = feq_gen_ups_unit_d_;
	s_rsue(&feq_gen_io_d__130);
	do_uio(&feq_gen_c_d_1, (char *)&feq_gen_ups_jt_d_, (ftnlen)sizeof(doublereal));
	do_uio(&feq_gen_c_d_1, (char *)&feq_gen_ups_elev_d_, (ftnlen)sizeof(real));
	e_rsue();
/* SOURCE inv_gate.for:932 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:933 */
/*<       read(dns_unit)dns_jt,dns_elev >*/
    feq_gen_io_d__131.ciunit = feq_gen_dns_unit_d_;
    s_rsue(&feq_gen_io_d__131);
    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_dns_jt_d_, (ftnlen)sizeof(doublereal));
    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_dns_elev_d_, (ftnlen)sizeof(real));
    e_rsue();
/* SOURCE inv_gate.for:934 */
/*<       read(gate_unit)gate_jt,gate_flow >*/
    feq_gen_io_d__134.ciunit = feq_gen_gate_unit_d_;
    s_rsue(&feq_gen_io_d__134);
    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_gate_jt_d_, (ftnlen)sizeof(doublereal));
    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_gate_flow_d_, (ftnlen)sizeof(real));
    e_rsue();
/* SOURCE inv_gate.for:936 */
/*<       if(reverse_flow.eq.'NO ')then >*/
    if (s_cmp(feq_gen_reverse_flow_d_, const_cast<char*>("NO "), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE inv_gate.for:937 */
/*<       if(gate_flow.le.min_flow)gate_flow=0.0 >*/
	if (feq_gen_gate_flow_d_ <= feq_gen_min_flow_d_) {
	    feq_gen_gate_flow_d_ = (float)0.;
	}
/* SOURCE inv_gate.for:938 */
/*<       else >*/
    } else {
/* SOURCE inv_gate.for:939 */
/*<       if(abs(gate_flow).le.min_flow)gate_flow=0.0 >*/
	if (dabs(feq_gen_gate_flow_d_) <= feq_gen_min_flow_d_) {
	    feq_gen_gate_flow_d_ = (float)0.;
	}
/* SOURCE inv_gate.for:940 */
/*<       endif >*/
    }
/*       Check for synchronization */
/* SOURCE inv_gate.for:942 */
/*<        >*/
    if ((feq_gen_d_d_1 = feq_gen_cpnt_jt_d_ - feq_gen_ups_jt_d_, abs(feq_gen_d_d_1)) > eps || (feq_gen_d_d_2 = feq_gen_cpnt_jt_d_ - 
	    feq_gen_dns_jt_d_, abs(feq_gen_d_d_2)) > eps || (feq_gen_d_d_3 = feq_gen_cpnt_jt_d_ - feq_gen_gate_jt_d_, abs(
	    feq_gen_d_d_3)) > eps) {
/* SOURCE inv_gate.for:945 */
/*<       write(stdout,54)cpnt_jt,ups_jt,dns_jt,gate_jt >*/
	feq_gen_io_d__137.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__137);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_cpnt_jt_d_, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ups_jt_d_, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_dns_jt_d_, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_gate_jt_d_, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE inv_gate.for:946 */
/*<       stop' Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>(" Abnormal stop.  Errors found."), (ftnlen)30);
/* SOURCE inv_gate.for:947 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:949 */
/*<       hu=ups_elev-flood_elev >*/
    hu = static_cast<double>(feq_gen_ups_elev_d_) - feq_gen_flood_elev_d_;
/* SOURCE inv_gate.for:950 */
/*<       hd=dns_elev-flood_elev >*/
    hd = static_cast<double>(feq_gen_dns_elev_d_) - feq_gen_flood_elev_d_;
/* SOURCE inv_gate.for:952 */
/*<       if(gate_flow.ne.0.0)then >*/
    if (feq_gen_gate_flow_d_ != (float)0.) {
/*         Solve for the gate setting that would have to exist to match the */
/*         given flow and water surface elevations. */
/* SOURCE inv_gate.for:957 */
/*<        >*/
	feq_gen_find_gate_opening_d_(stdout, &feq_gen_ud_table_d_, &feq_gen_du_table_d_, &feq_gen_ups_elev_d_, &
		feq_gen_dns_elev_d_, &feq_gen_gate_flow_d_, &feq_gen_hg_max_d_, &hdatum, &hg, &p, ftype, 
		&feq_gen_result_flag_d_, &feq_gen_ftype_code_d_, (ftnlen)8);
/* SOURCE inv_gate.for:964 */
/*<       if(result_flag.eq.1)then >*/
	if (feq_gen_result_flag_d_ == 1) {
/* SOURCE inv_gate.for:965 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE inv_gate.for:966 */
/*<       if(output_level.eq.'MAX')then >*/
	    if (s_cmp(feq_gen_output_level_d_, const_cast<char*>("MAX"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE inv_gate.for:967 */
/*<        >*/
		feq_gen_io_d__145.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__145);
		do_fio(&feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&mn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&dy, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&hu, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&hd, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_gate_flow_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&hg, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, ftype, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_result_flag_d_, (ftnlen)sizeof(integer))
			;
		e_wsfe();
/* SOURCE inv_gate.for:969 */
/*<       endif >*/
	    }
/* SOURCE inv_gate.for:970 */
/*<       endif >*/
	}
/* SOURCE inv_gate.for:972 */
/*<       else >*/
    } else {
/* SOURCE inv_gate.for:973 */
/*<       hg=0.0 >*/
	hg = (float)0.;
/* SOURCE inv_gate.for:974 */
/*<       p=0.0 >*/
	p = (float)0.;
/* SOURCE inv_gate.for:975 */
/*<       result_flag=0 >*/
	feq_gen_result_flag_d_ = 0;
/* SOURCE inv_gate.for:977 */
/*<       endif >*/
    }
/* SOURCE inv_gate.for:979 */
/*<       if(result_flag.eq.1)then >*/
    if (feq_gen_result_flag_d_ == 1) {
/*         Increment the various matrices.  First find the row and */
/*         column of the cell that is to be incremented. */
/* SOURCE inv_gate.for:983 */
/*<       hdiff=hu-hd >*/
	hdiff = static_cast<double>(hu) - hd;
/* SOURCE inv_gate.for:985 */
/*<       if(hu.lt.row_bdys(1).or.hu.gt.row_bdys(n_row_bdys))then >*/
	if (hu < feq_gen_row_bdys_d_[0] || hu > feq_gen_row_bdys_d_[feq_gen_n_row_bdys_d_ - 1]) {
/* SOURCE inv_gate.for:986 */
/*<       write(stdout,62)hu,row_bdys(1),row_bdys(n_row_bdys) >*/
	    feq_gen_io_d__147.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__147);
	    do_fio(&feq_gen_c_d_1, (char *)&hu, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_row_bdys_d_[0], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_row_bdys_d_[feq_gen_n_row_bdys_d_ - 1], (ftnlen)
		    sizeof(real));
	    e_wsfe();
/* SOURCE inv_gate.for:987 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE inv_gate.for:988 */
/*<       hu=row_bdys(2) >*/
	    hu = feq_gen_row_bdys_d_[1];
/* SOURCE inv_gate.for:989 */
/*<       endif >*/
	}
/* SOURCE inv_gate.for:990 */
/*<       if(hdiff.lt.col_bdys(1).or.hdiff.gt.col_bdys(n_col_bdys))then >*/
	if (hdiff < feq_gen_col_bdys_d_[0] || hdiff > feq_gen_col_bdys_d_[feq_gen_n_col_bdys_d_ - 1]) {
/* SOURCE inv_gate.for:991 */
/*<       write(stdout,64)hdiff,col_bdys(1),col_bdys(n_col_bdys) >*/
	    feq_gen_io_d__148.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__148);
	    do_fio(&feq_gen_c_d_1, (char *)&hdiff, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_col_bdys_d_[0], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_col_bdys_d_[feq_gen_n_col_bdys_d_ - 1], (ftnlen)
		    sizeof(real));
	    e_wsfe();
/* SOURCE inv_gate.for:992 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE inv_gate.for:993 */
/*<       hdiff=col_bdys(2) >*/
	    hdiff = feq_gen_col_bdys_d_[1];
/* SOURCE inv_gate.for:994 */
/*<       endif >*/
	}
/* SOURCE inv_gate.for:995 */
/*<       do130i=1,n_row_bdys-1 >*/
	feq_gen_i_d_1 = feq_gen_n_row_bdys_d_ - 1;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inv_gate.for:996 */
/*<       if(row_bdys(i+1).ge.hu)then >*/
	    if (feq_gen_row_bdys_d_[feq_gen_i_d_] >= hu) {
/*             I gives the row */
/* SOURCE inv_gate.for:998 */
/*<       goto132 >*/
		goto L132;
/* SOURCE inv_gate.for:999 */
/*<       endif >*/
	    }
/* SOURCE inv_gate.for:1000 */
/*<   130 continue >*/
/* L130: */
	}
/* SOURCE inv_gate.for:1001 */
/*<       write(stdout,*)' Bug in INV_GATE. Should not get here. 130' >*/
	feq_gen_io_d__149.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__149);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Bug in INV_GATE. Should not get here. 130"), (
		ftnlen)42);
	e_wsle();
/* SOURCE inv_gate.for:1002 */
/*<       stop' Abnormal stop.  Bug found' >*/
	s_stop(const_cast<char*>(" Abnormal stop.  Bug found"), (ftnlen)26);
/* SOURCE inv_gate.for:1003 */
/*<   132 continue >*/
L132:
/* SOURCE inv_gate.for:1004 */
/*<       do135j=1,n_col_bdys-1 >*/
	feq_gen_i_d_1 = feq_gen_n_col_bdys_d_ - 1;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE inv_gate.for:1005 */
/*<       if(col_bdys(j+1).ge.hdiff)then >*/
	    if (feq_gen_col_bdys_d_[j] >= hdiff) {
/*             J gives the column */
/* SOURCE inv_gate.for:1007 */
/*<       n_per_cell(i,j)=n_per_cell(i,j)+1 >*/
		++feq_gen_n_per_cell_d_[feq_gen_i_d_ + j * 40 - 41];
/* SOURCE inv_gate.for:1008 */
/*<       sum_per_cell(i,j)=sum_per_cell(i,j)+p >*/
		feq_gen_sum_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] += p;
/* SOURCE inv_gate.for:1009 */
/*<       max_per_cell(i,j)=max(p,max_per_cell(i,j)) >*/
/* Computing MAX */
		feq_gen_r_d_1 = p, feq_gen_r_d_2 = feq_gen_max_per_cell_d_[feq_gen_i_d_ + j * 40 - 41];
		feq_gen_max_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE inv_gate.for:1010 */
/*<       min_per_cell(i,j)=min(p,min_per_cell(i,j)) >*/
/* Computing MIN */
		feq_gen_r_d_1 = p, feq_gen_r_d_2 = feq_gen_min_per_cell_d_[feq_gen_i_d_ + j * 40 - 41];
		feq_gen_min_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE inv_gate.for:1011 */
/*<       goto137 >*/
		goto L137;
/* SOURCE inv_gate.for:1012 */
/*<       endif >*/
	    }
/* SOURCE inv_gate.for:1013 */
/*<   135 continue >*/
/* L135: */
	}
/* SOURCE inv_gate.for:1014 */
/*<       write(stdout,*)' Bug in INV_GATE.  Should not get here. 135' >*/
	feq_gen_io_d__150.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__150);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Bug in INV_GATE.  Should not get here. 135"), (
		ftnlen)43);
	e_wsle();
/* SOURCE inv_gate.for:1015 */
/*<       stop' Abnormal stop.  Bug found.' >*/
	s_stop(const_cast<char*>(" Abnormal stop.  Bug found."), (ftnlen)27);
/* SOURCE inv_gate.for:1016 */
/*<   137 continue >*/
L137:
/* SOURCE inv_gate.for:1017 */
/*<       endif >*/
	;
    }
/* SOURCE inv_gate.for:1018 */
/*<       goto200 >*/
    goto L200;
/* SOURCE inv_gate.for:1019 */
/*<  9000 continue >*/
L9000:
/*     Close open files */
/* SOURCE inv_gate.for:1022 */
/*<       callfree_unit(stdout,cpnt_unit) >*/
    feq_gen_free_unit_d_(stdout, &feq_gen_cpnt_unit_d_);
/* SOURCE inv_gate.for:1023 */
/*<       callfree_unit(stdout,dns_unit) >*/
    feq_gen_free_unit_d_(stdout, &feq_gen_dns_unit_d_);
/* SOURCE inv_gate.for:1024 */
/*<       callfree_unit(stdout,gate_unit) >*/
    feq_gen_free_unit_d_(stdout, &feq_gen_gate_unit_d_);
/* SOURCE inv_gate.for:1025 */
/*<       if(ups_given.ne.0)then >*/
    if (feq_gen_ups_given_d_ != 0) {
/* SOURCE inv_gate.for:1026 */
/*<       callfree_unit(stdout,ups_unit) >*/
	feq_gen_free_unit_d_(stdout, &feq_gen_ups_unit_d_);
/* SOURCE inv_gate.for:1027 */
/*<       endif >*/
    }
/*     Compute the mean gate opening in each cell. */
/* SOURCE inv_gate.for:1031 */
/*<       do300i=1,n_row_bdys-1 >*/
    feq_gen_i_d_1 = feq_gen_n_row_bdys_d_ - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inv_gate.for:1032 */
/*<       do290j=1,n_col_bdys >*/
	feq_gen_i_d_2 = feq_gen_n_col_bdys_d_;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE inv_gate.for:1033 */
/*<       if(n_per_cell(i,j).gt.0)then >*/
	    if (feq_gen_n_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] > 0) {
/* SOURCE inv_gate.for:1034 */
/*<       sum_per_cell(i,j)=sum_per_cell(i,j)/n_per_cell(i,j) >*/
		feq_gen_sum_per_cell_d_[feq_gen_i_d_ + j * 40 - 41] /= feq_gen_n_per_cell_d_[feq_gen_i_d_ + j * 
			40 - 41];
/* SOURCE inv_gate.for:1035 */
/*<       write(pc_per_cell(i,j)(1:6),'(F6.3)')sum_per_cell(i,j) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 6;
		feq_gen_ici_d_1.iciunit = feq_gen_pc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41 << 3);
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.3)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sum_per_cell_d_[feq_gen_i_d_ + j * 40 - 41], (
			ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE inv_gate.for:1036 */
/*<       write(minc_per_cell(i,j),'(F6.2)')min_per_cell(i,j) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 6;
		feq_gen_ici_d_1.iciunit = feq_gen_minc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_min_per_cell_d_[feq_gen_i_d_ + j * 40 - 41], (
			ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE inv_gate.for:1037 */
/*<       write(maxc_per_cell(i,j),'(F6.2)')max_per_cell(i,j) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 6;
		feq_gen_ici_d_1.iciunit = feq_gen_maxc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_per_cell_d_[feq_gen_i_d_ + j * 40 - 41], (
			ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE inv_gate.for:1038 */
/*<       write(nc_per_cell(i,j),'(I6)')n_per_cell(i,j) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 6;
		feq_gen_ici_d_1.iciunit = feq_gen_nc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(I6)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_n_per_cell_d_[feq_gen_i_d_ + j * 40 - 41], (
			ftnlen)sizeof(integer));
		e_wsfi();
/* SOURCE inv_gate.for:1039 */
/*<       else >*/
	    } else {
/* SOURCE inv_gate.for:1040 */
/*<       pc_per_cell(i,j)(1:6)='   0.0' >*/
		s_copy(feq_gen_pc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41 << 3), const_cast<char*>("   0.0"), (
			ftnlen)6, (ftnlen)6);
/* SOURCE inv_gate.for:1041 */
/*<       maxc_per_cell(i,j)='   0.0' >*/
		s_copy(feq_gen_maxc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6, const_cast<char*>("   0.0"), (
			ftnlen)6, (ftnlen)6);
/* SOURCE inv_gate.for:1042 */
/*<       minc_per_cell(i,j)='   0.0' >*/
		s_copy(feq_gen_minc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6, const_cast<char*>("   0.0"), (
			ftnlen)6, (ftnlen)6);
/* SOURCE inv_gate.for:1043 */
/*<       nc_per_cell(i,j)='     0' >*/
		s_copy(feq_gen_nc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6, const_cast<char*>("     0"), (
			ftnlen)6, (ftnlen)6);
/* SOURCE inv_gate.for:1044 */
/*<       endif >*/
	    }
/* SOURCE inv_gate.for:1045 */
/*<   290 continue >*/
/* L290: */
	}
/* SOURCE inv_gate.for:1046 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE inv_gate.for:1048 */
/*<       write(stdout,66) >*/
    feq_gen_io_d__155.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__155);
    e_wsfe();
/* SOURCE inv_gate.for:1049 */
/*<       do320i=1,n_row_bdys-1 >*/
    feq_gen_i_d_1 = feq_gen_n_row_bdys_d_ - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inv_gate.for:1050 */
/*<       write(stdout,68)(n_per_cell(i,j),j=1,n_col_bdys-1) >*/
	feq_gen_io_d__156.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__156);
	feq_gen_i_d_2 = feq_gen_n_col_bdys_d_ - 1;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_n_per_cell_d_[feq_gen_i_d_ + j * 40 - 41], (ftnlen)
		    sizeof(integer));
	}
	e_wsfe();
/* SOURCE inv_gate.for:1051 */
/*<   320 continue >*/
/* L320: */
    }
/*      WRITE(STDOUT,70) */
/*      DO 330 I=1,N_ROW_BDYS-1 */
/*        WRITE(STDOUT,72) (SUM_PER_CELL(I,J), J=1,N_COL_BDYS-1) */
/* 330   CONTINUE */
/* SOURCE inv_gate.for:1056 */
/*<       write(stdout,74) >*/
    feq_gen_io_d__157.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__157);
    e_wsfe();
/* SOURCE inv_gate.for:1057 */
/*<       write(stdout,75)(col_bdys(j),j=1,n_col_bdys-1) >*/
    feq_gen_io_d__158.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__158);
    feq_gen_i_d_1 = feq_gen_n_col_bdys_d_ - 1;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_col_bdys_d_[j - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* SOURCE inv_gate.for:1058 */
/*<       write(stdout,76)(col_bdys(j),j=2,n_col_bdys) >*/
    feq_gen_io_d__159.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__159);
    feq_gen_i_d_1 = feq_gen_n_col_bdys_d_;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_col_bdys_d_[j - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* SOURCE inv_gate.for:1059 */
/*<       do340i=1,n_row_bdys-1 >*/
    feq_gen_i_d_1 = feq_gen_n_row_bdys_d_ - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inv_gate.for:1060 */
/*<        >*/
	feq_gen_io_d__160.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__160);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_row_bdys_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, const_cast<char*>("AvrP:"), (ftnlen)5);
	feq_gen_i_d_2 = feq_gen_n_col_bdys_d_ - 1;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, feq_gen_pc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41 << 3), (ftnlen)8)
		    ;
	}
	e_wsfe();
/* SOURCE inv_gate.for:1062 */
/*<        >*/
	feq_gen_io_d__161.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__161);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_row_bdys_d_[feq_gen_i_d_], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, const_cast<char*>("MinP:"), (ftnlen)5);
	feq_gen_i_d_2 = feq_gen_n_col_bdys_d_ - 1;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, feq_gen_minc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6, (ftnlen)
		    6);
	}
	e_wsfe();
/* SOURCE inv_gate.for:1064 */
/*<       write(stdout,73)'MaxP:',(maxc_per_cell(i,j),j=1,n_col_bdys-1) >*/
	feq_gen_io_d__162.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__162);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("MaxP:"), (ftnlen)5);
	feq_gen_i_d_2 = feq_gen_n_col_bdys_d_ - 1;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, feq_gen_maxc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6, (ftnlen)
		    6);
	}
	e_wsfe();
/* SOURCE inv_gate.for:1065 */
/*<       write(stdout,73)'N   :',(nc_per_cell(i,j),j=1,n_col_bdys-1) >*/
	feq_gen_io_d__163.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__163);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("N   :"), (ftnlen)5);
	feq_gen_i_d_2 = feq_gen_n_col_bdys_d_ - 1;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, feq_gen_nc_per_cell_d_ + (feq_gen_i_d_ + j * 40 - 41) * 6, (ftnlen)6);
	}
	e_wsfe();
/* SOURCE inv_gate.for:1066 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__164.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__164);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE inv_gate.for:1067 */
/*<   340 continue >*/
/* L340: */
    }
/*     Create the items needed to output the table of type 10 */
/* SOURCE inv_gate.for:1070 */
/*<       do350i=1,n_row_bdys-1 >*/
    feq_gen_i_d_1 = feq_gen_n_row_bdys_d_ - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE inv_gate.for:1071 */
/*<       tp=0.5*(row_bdys(i)+row_bdys(i+1)) >*/
	tp = static_cast<double>((static_cast<double>(feq_gen_row_bdys_d_[feq_gen_i_d_ - 1]) + feq_gen_row_bdys_d_[feq_gen_i_d_])) * (float).5;
/* SOURCE inv_gate.for:1072 */
/*<       write(row_args(i)(1:6),'(F6.2)')tp >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 6;
	feq_gen_ici_d_1.iciunit = feq_gen_row_args_d_ + (feq_gen_i_d_ - 1 << 3);
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&tp, (ftnlen)sizeof(real));
	e_wsfi();
/* SOURCE inv_gate.for:1073 */
/*<   350 continue >*/
/* L350: */
    }
/* SOURCE inv_gate.for:1074 */
/*<       do360j=1,n_col_bdys-1 >*/
    feq_gen_i_d_1 = feq_gen_n_col_bdys_d_ - 1;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE inv_gate.for:1075 */
/*<       tp=0.5*(col_bdys(j)+col_bdys(j+1)) >*/
	tp = static_cast<double>((static_cast<double>(feq_gen_col_bdys_d_[j - 1]) + feq_gen_col_bdys_d_[j])) * (float).5;
/* SOURCE inv_gate.for:1076 */
/*<       write(col_args(j)(1:6),'(F6.2)')tp >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 6;
	feq_gen_ici_d_1.iciunit = feq_gen_col_args_d_ + (j - 1 << 3);
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&tp, (ftnlen)sizeof(real));
	e_wsfi();
/* SOURCE inv_gate.for:1077 */
/*<   360 continue >*/
/* L360: */
    }
/*     Set the formats for the table. */
/*     Note: The number of columns in the table is always one more than */
/*     the number of column arguments because there is a column of the */
/*     row arguments.  Therefor the number of column boundaries, being */
/*     one more than the number of column arguments, also gives the */
/*     number of columns in the table. */
/* SOURCE inv_gate.for:1085 */
/*<       write(chr3,'(I3)')n_col_bdys >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 3;
    feq_gen_ici_d_1.iciunit = chr3;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I3)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_n_col_bdys_d_, (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE inv_gate.for:1086 */
/*<       write(chr3_1,'(I3)')n_col_bdys-1 >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 3;
    feq_gen_ici_d_1.iciunit = feq_gen_chr3_1_d_;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I3)");
    s_wsfi(&feq_gen_ici_d_1);
    feq_gen_i_d_1 = feq_gen_n_col_bdys_d_ - 1;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE inv_gate.for:1087 */
/*<       hdin='''('//chr3//'A6)''' >*/
/* Writing concatenation */
    feq_gen_i_d_3[0] = 2, feq_gen_a_d_1[0] = const_cast<char*>("'(");
    feq_gen_i_d_3[1] = 3, feq_gen_a_d_1[1] = chr3;
    feq_gen_i_d_3[2] = 4, feq_gen_a_d_1[2] = const_cast<char*>("A6)'");
    s_cat(hdin, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_3, (ftnlen)24);
/* SOURCE inv_gate.for:1088 */
/*<       hdout='''(1X,'//chr3//'A6)''' >*/
/* Writing concatenation */
    feq_gen_i_d_3[0] = 5, feq_gen_a_d_1[0] = const_cast<char*>("'(1X,");
    feq_gen_i_d_3[1] = 3, feq_gen_a_d_1[1] = chr3;
    feq_gen_i_d_3[2] = 4, feq_gen_a_d_1[2] = const_cast<char*>("A6)'");
    s_cat(hdout, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_3, (ftnlen)24);
/* SOURCE inv_gate.for:1089 */
/*<       hditem='''(F6.0)''' >*/
    s_copy(hditem, const_cast<char*>("'(F6.0)'"), (ftnlen)24, (ftnlen)8);
/* SOURCE inv_gate.for:1090 */
/*<       rowin='''('//chr3//'F6.0)''' >*/
/* Writing concatenation */
    feq_gen_i_d_3[0] = 2, feq_gen_a_d_1[0] = const_cast<char*>("'(");
    feq_gen_i_d_3[1] = 3, feq_gen_a_d_1[1] = chr3;
    feq_gen_i_d_3[2] = 6, feq_gen_a_d_1[2] = const_cast<char*>("F6.0)'");
    s_cat(rowin, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_3, (ftnlen)24);
/* SOURCE inv_gate.for:1091 */
/*<       rowout='''(1X,F6.1,'//chr3_1//'F6.2)''' >*/
/* Writing concatenation */
    feq_gen_i_d_3[0] = 10, feq_gen_a_d_1[0] = const_cast<char*>("'(1X,F6.1,");
    feq_gen_i_d_3[1] = 3, feq_gen_a_d_1[1] = feq_gen_chr3_1_d_;
    feq_gen_i_d_3[2] = 6, feq_gen_a_d_1[2] = const_cast<char*>("F6.2)'");
    s_cat(rowout, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_3, (ftnlen)24);
/* SOURCE inv_gate.for:1092 */
/*<       rowlab='Fstage' >*/
    s_copy(rowlab, const_cast<char*>("Fstage"), (ftnlen)8, (ftnlen)6);
/* SOURCE inv_gate.for:1093 */
/*<       label=' Replace with desired value' >*/
    s_copy(label, const_cast<char*>(" Replace with desired value"), (ftnlen)50, (ftnlen)27);
/*      WRITE(STDOUT,*) ' HDIN=',HDIN */
/*      WRITE(STDOUT,*) ' HDOUT=',HDOUT */
/*      WRITE(STDOUT,*) ' HDITEM=',HDITEM */
/*      WRITE(STDOUT,*) ' ROWIN=',ROWIN */
/*      WRITE(STDOUT,*) ' ROWOUT=',ROWOUT */
/* SOURCE inv_gate.for:1100 */
/*<        >*/
    feq_gen_i_d_1 = feq_gen_n_row_bdys_d_ - 1;
    feq_gen_i_d_2 = feq_gen_n_col_bdys_d_ - 1;
    feq_gen_type10_out_d_(stdout, stdtab, &feq_gen_control_tab_d_, &feq_gen_i_d_1, &feq_gen_i_d_2, feq_gen_row_args_d_, &
	    feq_gen_flood_elev_d_, feq_gen_col_args_d_, feq_gen_pc_per_cell_d_, hdin, hditem, hdout, 
	    rowin, rowlab, rowout, label, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)24, (ftnlen)24, (ftnlen)24, (ftnlen)24, (ftnlen)8, (ftnlen)
	    24, (ftnlen)50);
/* SOURCE inv_gate.for:1110 */
/*<       return >*/
    return 0;
/* SOURCE inv_gate.for:1111 */
/*<       end >*/
} /* inv_gate__ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
