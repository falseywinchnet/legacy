#include "../support/format.hpp"
#include <feq/section_interpolation.hpp>
extern "C" void feq_interpolate_function_interval(int,int,int,float,float*,float*);
extern "C" void feq_interpolate_critical_flow_interval(int,int,float,float*);
extern "C" void feq_interpolate_energy_section_interval(int,int,int,int,float,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*);
extern "C" void feq_interpolate_section_interval(int,int,int,float,float*,float*,float*,float*,float*,float*,float*);
extern "C" void feq_interpolate_section_interval_moment(int,int,int,float,float*,float*,float*,float*,float*,float*,float*,float*);
/* fqshrftb.f -- translated by f2c (version 20240504).
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

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON grid_datum__ is declared in common.hpp. */

#define feq_gen_grid_datum_d_1 feq_gen_grid_datum_d_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON homec_ is declared in common.hpp. */

#define homec_1 homec_

/* COMMON mktbindxc_ is declared in common.hpp. */

#define mktbindxc_1 mktbindxc_

/* COMMON mktbindx_ is declared in common.hpp. */

#define mktbindx_1 mktbindx_

/* COMMON upgrdc_ is declared in common.hpp. */

#define upgrdc_1 upgrdc_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON itabidnum_ is declared in common.hpp. */

#define itabidnum_1 itabidnum_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_25 = 25;
static integer feq_gen_c_d_24 = 24;
static integer feq_gen_c_d_1000 = 1000;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_150 = 150;
static integer feq_gen_c_d_1010 = 1010;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_5 = 5;




/* SOURCE fqshrftb.for:4 */
/*<       realfunctiongethdd(adrs) >*/
doublereal gethdd_(integer *adrs)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Get the head datum for two-d tables. expand later to all */
/*     tables that have a head datum. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:12 */
/*<       integeradrs >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:18 */
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
/* INCLUDE fqshrftb.for:19 */
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
/* SOURCE fqshrftb.for:21 */
/*<       gethdd=ftab(adrs) >*/
    ret_val = ftab[*adrs];
/* SOURCE fqshrftb.for:22 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrftb.for:23 */
/*<       end >*/
} /* gethdd_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:27 */
/*<       subroutineput1d(stdout,tabnum,type,n,arg,f1,f2,next,tabadr) >*/
/* Subroutine */ int put1d_(integer *stdout, integer *tabnum, integer *feq_gen_type_d_,
	 integer *n, real *feq_storage_arg, real *feq_storage_f1, real *feq_storage_f2, integer *next, integer *
	tabadr)
{
    /* Initialized data */

    static integer vtype[35] = { 0,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0 };

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:694* PUT1D needs limit of \002,i8\
,\002 for function\002,\002 table storage\002,/,11x,\002 but current limit is\
\002,i8)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, pnt;
    real barg;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer nfun;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer space;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__9 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Put a one-dimensional table of type, TYPE, into the function */
/*     table storage system. */
/* SOURCE fqshrftb.for:36 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:38 */
/*<       integern,next,stdout,tabadr,tabnum,type >*/
/* SOURCE fqshrftb.for:39 */
/*<       realarg(n),f1(n),f2(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TABNUM - table number to use */
/*     TYPE   - function table type */
/*     N      - number of tabulated arguments */
/*     ARG    - sequence of argument values for the 1-D table */
/*     F1     - seqence of values for first function */
/*     F2     - seqence of values for second function */
/*     NEXT   - pointer into scratch portion of ITAB/FTAB */
/*     TABADR - Table address in ITAB/FTAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:53 */
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
/* INCLUDE fqshrftb.for:54 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:57 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:58 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:61 */
/*<       integeri,nfun,pnt,space >*/
/* SOURCE fqshrftb.for:62 */
/*<       realbarg >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:65 */
/*<       datavtype/0,1,2,2,0,0,0,0,0,0,0,24*0/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> f2(feq_storage_f2, 1);

    feq::IndexedPointer<real> f1(feq_storage_f1, 1);

    feq::IndexedPointer<real> arg(feq_storage_arg, 1);

    /* Function Body */
/* SOURCE fqshrftb.for:68 */
/*<    50  >*/
/* L50: */
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' PUT1D: NEXT=',NEXT */
/*     A valid type number has a entry > 0 in VTYPE and the number */
/*     gives the number of functions that are stored in the table */
/*     of that type.  Of course the argument is always stored. */
/* SOURCE fqshrftb.for:76 */
/*<       nfun=vtype(type) >*/
    nfun = vtype[(0 + (0 + (*feq_gen_type_d_ - 1 << 2))) / 4];
/* SOURCE fqshrftb.for:77 */
/*<       if(nfun.eq.0)then >*/
    if (nfun == 0) {
/*       Bug.  Invalid type sent to this routine. */
/* SOURCE fqshrftb.for:80 */
/*<        >*/
	feq_gen_io_d__9.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__9);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG;XXX* Invalid type="), (ftnlen)24);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*feq_gen_type_d_), (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" in subroutine PUT1D."), (ftnlen)21);
	e_wsle();
/* SOURCE fqshrftb.for:82 */
/*<       stop'Abnormal stop. Bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE fqshrftb.for:83 */
/*<       else >*/
    } else {
/*       Is there room in FTAB */
/* SOURCE fqshrftb.for:85 */
/*<       space=21+n*(nfun+1) >*/
	space = *n * (nfun + 1) + 21;
/* SOURCE fqshrftb.for:86 */
/*<       if(space+next.gt.mrftab)then >*/
	if (space + *next > 13000001) {
/* SOURCE fqshrftb.for:87 */
/*<       write(stdout,50)space+next,next >*/
	    feq_gen_io_d__11.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__11);
	    feq_gen_i_d_1 = space + *next;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&(*next), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE fqshrftb.for:88 */
/*<       stop'Abnormal stop. Error found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Error found."), (ftnlen)27);
/* SOURCE fqshrftb.for:89 */
/*<       endif >*/
	}
/*       Set the local pointer */
/* SOURCE fqshrftb.for:92 */
/*<       pnt=next >*/
	pnt = *next;
/*       Set the table address */
/* SOURCE fqshrftb.for:95 */
/*<       tabadr=pnt >*/
	*tabadr = pnt;
/*       Establish the header information. */
/* SOURCE fqshrftb.for:98 */
/*<       itab(pnt+1)=tabnum >*/
	itab[pnt + 1] = *tabnum;
/* SOURCE fqshrftb.for:99 */
/*<       itab(pnt+2)=type >*/
	itab[pnt + 2] = *feq_gen_type_d_;
/*       INITIALIZE LAST ADDRESS ACCESSED */
/* SOURCE fqshrftb.for:101 */
/*<       itab(pnt+3)=pnt+off234 >*/
	itab[pnt + 3] = pnt + 22;
/* SOURCE fqshrftb.for:102 */
/*<       ftab(pnt+4)=0.0 >*/
	ftab[pnt + 4] = (float)0.;
/* SOURCE fqshrftb.for:103 */
/*<       ftab(pnt+5)=1.0 >*/
	ftab[pnt + 5] = (float)1.;
/* SOURCE fqshrftb.for:104 */
/*<       itab(pnt+18)=0 >*/
	itab[pnt + 18] = 0;
/* SOURCE fqshrftb.for:105 */
/*<       ftab(pnt+19)=0.0 >*/
	ftab[pnt + 19] = (float)0.;
/* SOURCE fqshrftb.for:106 */
/*<       pnt=pnt+off234 >*/
	pnt += 22;
/*       Set the monotone increasing argument flag. */
/* SOURCE fqshrftb.for:109 */
/*<       barg=arg(1)-100. >*/
	barg = static_cast<double>(arg[1]) - (float)100.;
/* SOURCE fqshrftb.for:111 */
/*<       do100i=1,n >*/
	feq_gen_i_d_1 = *n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:112 */
/*<       if(arg(i).gt.barg)then >*/
	    if (arg[feq_gen_i_d_] > barg) {
/*           Argument is greater than the last one. */
/* SOURCE fqshrftb.for:114 */
/*<       ftab(pnt)=arg(i) >*/
		ftab[pnt] = arg[feq_gen_i_d_];
/* SOURCE fqshrftb.for:115 */
/*<       ftab(pnt+1)=f1(i) >*/
		ftab[pnt + 1] = f1[feq_gen_i_d_];
/* SOURCE fqshrftb.for:116 */
/*<       if(nfun.eq.2)then >*/
		if (nfun == 2) {
/* SOURCE fqshrftb.for:117 */
/*<       ftab(pnt+2)=f2(i) >*/
		    ftab[pnt + 2] = f2[feq_gen_i_d_];
/* SOURCE fqshrftb.for:118 */
/*<       pnt=pnt+3 >*/
		    pnt += 3;
/* SOURCE fqshrftb.for:119 */
/*<       else >*/
		} else {
/* SOURCE fqshrftb.for:120 */
/*<       pnt=pnt+2 >*/
		    pnt += 2;
/* SOURCE fqshrftb.for:121 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:122 */
/*<       barg=arg(i) >*/
		barg = arg[feq_gen_i_d_];
/* SOURCE fqshrftb.for:123 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:124 */
/*<       write(stdout,*)' *BUG:XXX Non-increasing argument',' in PUT1D.' >*/
		feq_gen_io_d__15.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__15);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX Non-increasing argument"), (
			ftnlen)33);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" in PUT1D."), (ftnlen)10);
		e_wsle();
/* SOURCE fqshrftb.for:126 */
/*<       stop'Abnormal stop. Bug found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE fqshrftb.for:127 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:128 */
/*<   100 continue >*/
/* L100: */
	}
/*       Save address of last argument in the table. */
/* SOURCE fqshrftb.for:131 */
/*<       itab(next)=pnt-nfun-1 >*/
	itab[*next] = pnt - nfun - 1;
/* SOURCE fqshrftb.for:132 */
/*<       next=pnt >*/
	*next = pnt;
/* SOURCE fqshrftb.for:133 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:134 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:135 */
/*<       end >*/
} /* put1d_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:139 */
/*<       character*16functionget_gisid(adrs) >*/
/* Character */ VOID feq_gen_get_gisid_d_(char *ret_val, ftnlen ret_val_len, integer *
	adrs)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_2[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Get the GIS id string from the table at ADRS. */
/* SOURCE fqshrftb.for:145 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:147 */
/*<       integeradrs >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:153 */
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
/* INCLUDE fqshrftb.for:154 */
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
/* SOURCE fqshrftb.for:156 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:157 */
/*<       externalget_string_from_ft >*/
/*     Local */
/* SOURCE fqshrftb.for:160 */
/*<       integertype >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:162 */
/*<       if(adrs.eq.0)then >*/
    if (*adrs == 0) {
/*       Tables not available yet.  Return blanks */
/* SOURCE fqshrftb.for:164 */
/*<       get_gisid='                ' >*/
	s_copy(ret_val, const_cast<char*>("                "), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:165 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:166 */
/*<       type=itab(adrs+2) >*/
	feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:167 */
/*<       if(type.le.25.and.type.ge.20.or.type.le.35.and.type.ge.30)then >*/
	if (feq_gen_type_d_ <= 25 && feq_gen_type_d_ >= 20 || feq_gen_type_d_ <= 35 && feq_gen_type_d_ >= 30) {
/*         Cross-section table.  Only cross-section tables have GISID's! */
/* SOURCE fqshrftb.for:170 */
/*<       get_gisid=get_string_from_ft(adrs+12) >*/
	    feq_gen_i_d_1 = *adrs + 12;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(ret_val, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:171 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:172 */
/*<       get_gisid='                ' >*/
	    s_copy(ret_val, const_cast<char*>("                "), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:173 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:174 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:175 */
/*<       return >*/
    return ;
/* SOURCE fqshrftb.for:176 */
/*<       end >*/
} /* get_gisid__ */

#undef rtmp
#undef itab
#undef ftab


/*     *********** */
/*     *         * */
/*     * PUT_chr8_IN_FT */
/*     *         * */
/*     *********** */
/* SOURCE fqshrftb.for:183 */
/*<       subroutineput_chr8_in_ft(ftp,string) >*/
/* Subroutine */ int feq_gen_put_chr8_in_ft_d_(integer *ftp, char *string, ftnlen 
	string_len)
{
    /* System generated locals */
    static doublereal equiv_2[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define dp (equiv_2)
#define sp (feq::BitView<real>(equiv_2, sizeof(equiv_2)))
    extern doublereal feq_gen_char_to_dp_d_(char *, ftnlen);
    char cs8[8];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Put the characters in STRING into a function-table header block */
/*     with the first character being stored in the first byte of */
/*     the four-byte word at FTP.  STRING is of fixed length. */
/* SOURCE fqshrftb.for:189 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:190 */
/*<       character*8string >*/
/* SOURCE fqshrftb.for:192 */
/*<       integerftp >*/
/* INCLUDE fqshrftb.for:194 */
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
/* INCLUDE fqshrftb.for:195 */
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
/* SOURCE fqshrftb.for:199 */
/*<       charactercs8*8 >*/
/* SOURCE fqshrftb.for:200 */
/*<       real*4sp(2) >*/
/* SOURCE fqshrftb.for:201 */
/*<       real*8dp >*/
/* SOURCE fqshrftb.for:203 */
/*<       real*8char_to_dp >*/
/* SOURCE fqshrftb.for:205 */
/*<       equivalence(sp(1),dp) >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:207 */
/*<       cs8=string(1:8) >*/
    s_copy(cs8, string, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:208 */
/*<       dp=char_to_dp(cs8) >*/
    *dp = feq_gen_char_to_dp_d_(cs8, (ftnlen)8);
/* SOURCE fqshrftb.for:209 */
/*<       ftab(ftp)=sp(1) >*/
    ftab[*ftp] = sp[0];
/* SOURCE fqshrftb.for:210 */
/*<       ftab(ftp+1)=sp(2) >*/
    ftab[*ftp + 1] = sp[1];
/* SOURCE fqshrftb.for:211 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:212 */
/*<       end >*/
} /* put_chr8_in_ft__ */

#undef rtmp
#undef itab
#undef ftab
#undef sp
#undef dp


/*     *********** */
/*     *         * */
/*     * PUT_STRING_IN_FT */
/*     *         * */
/*     *********** */
/* SOURCE fqshrftb.for:220 */
/*<       subroutineput_string_in_ft(ftp,string) >*/
/* Subroutine */ int feq_gen_put_string_in_ft_d_(integer *ftp, char *string, ftnlen 
	string_len)
{
    /* System generated locals */
    static doublereal equiv_2[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define dp (equiv_2)
#define sp (feq::BitView<real>(equiv_2, sizeof(equiv_2)))
    extern doublereal feq_gen_char_to_dp_d_(char *, ftnlen);
    char cs8[8];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Put the characters in STRING into a function-table header block */
/*     with the first character being stored in the first byte of */
/*     the four-byte word at FTP.  STRING is of fixed length. */
/* SOURCE fqshrftb.for:226 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:227 */
/*<       character*16string >*/
/* SOURCE fqshrftb.for:229 */
/*<       integerftp >*/
/* INCLUDE fqshrftb.for:231 */
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
/* INCLUDE fqshrftb.for:232 */
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
/* SOURCE fqshrftb.for:236 */
/*<       charactercs8*8 >*/
/* SOURCE fqshrftb.for:237 */
/*<       real*4sp(2) >*/
/* SOURCE fqshrftb.for:238 */
/*<       real*8dp >*/
/* SOURCE fqshrftb.for:240 */
/*<       real*8char_to_dp >*/
/* SOURCE fqshrftb.for:242 */
/*<       equivalence(sp(1),dp) >*/
/* *********************************************************************** */
/*     Do upper half of STRING */
/* SOURCE fqshrftb.for:245 */
/*<       cs8=string(1:8) >*/
    s_copy(cs8, string, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:246 */
/*<       dp=char_to_dp(cs8) >*/
    *dp = feq_gen_char_to_dp_d_(cs8, (ftnlen)8);
/* SOURCE fqshrftb.for:247 */
/*<       ftab(ftp)=sp(1) >*/
    ftab[*ftp] = sp[0];
/* SOURCE fqshrftb.for:248 */
/*<       ftab(ftp+1)=sp(2) >*/
    ftab[*ftp + 1] = sp[1];
/*     Do lower half of STRING */
/* SOURCE fqshrftb.for:250 */
/*<       cs8=string(9:16) >*/
    s_copy(cs8, string + 8, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:251 */
/*<       dp=char_to_dp(cs8) >*/
    *dp = feq_gen_char_to_dp_d_(cs8, (ftnlen)8);
/* SOURCE fqshrftb.for:252 */
/*<       ftab(ftp+2)=sp(1) >*/
    ftab[*ftp + 2] = sp[0];
/* SOURCE fqshrftb.for:253 */
/*<       ftab(ftp+3)=sp(2) >*/
    ftab[*ftp + 3] = sp[1];
/* SOURCE fqshrftb.for:254 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:255 */
/*<       end >*/
} /* put_string_in_ft__ */

#undef rtmp
#undef itab
#undef ftab
#undef sp
#undef dp


/*     *********** */
/*     *         * */
/*     * GET_chr8_FROM_FT */
/*     *         * */
/*     *********** */
/* SOURCE fqshrftb.for:262 */
/*<       character*8functionget_chr8_from_ft(ftp) >*/
/* Character */ VOID feq_gen_get_chr8_from_ft_d_(char *ret_val, ftnlen ret_val_len, 
	integer *ftp)
{
    /* System generated locals */
    char feq_gen_ch_d_2[8];
    static doublereal equiv_2[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define dp (equiv_2)
#define sp (feq::BitView<real>(equiv_2, sizeof(equiv_2)))
    extern /* Character */ VOID feq_gen_dp_to_char_d_(char *, ftnlen, doublereal *);
    char cs8[8];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Get a string stored in a function-table header block  and */
/*     return it. */
/* SOURCE fqshrftb.for:267 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:268 */
/*<       integerftp >*/
/* INCLUDE fqshrftb.for:270 */
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
/* INCLUDE fqshrftb.for:271 */
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
/*     Called program units */
/* SOURCE fqshrftb.for:274 */
/*<       character*8dp_to_char >*/
/* SOURCE fqshrftb.for:275 */
/*<       externaldp_to_char >*/
/*     Local */
/* SOURCE fqshrftb.for:279 */
/*<       charactercs8*8 >*/
/* SOURCE fqshrftb.for:280 */
/*<       real*4sp(2) >*/
/* SOURCE fqshrftb.for:281 */
/*<       real*8dp >*/
/* SOURCE fqshrftb.for:284 */
/*<       equivalence(sp(1),dp) >*/
/* *********************************************************************** */
/*     Get upper half of string. */
/* SOURCE fqshrftb.for:287 */
/*<       sp(1)=ftab(ftp) >*/
    sp[0] = ftab[*ftp];
/* SOURCE fqshrftb.for:288 */
/*<       sp(2)=ftab(ftp+1) >*/
    sp[1] = ftab[*ftp + 1];
/* SOURCE fqshrftb.for:289 */
/*<       cs8=dp_to_char(dp) >*/
    feq_gen_dp_to_char_d_(feq_gen_ch_d_2, (ftnlen)8, dp);
    s_copy(cs8, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:290 */
/*<       get_chr8_from_ft=cs8 >*/
    s_copy(ret_val, cs8, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:291 */
/*<       return >*/
    return ;
/* SOURCE fqshrftb.for:292 */
/*<       end >*/
} /* get_chr8_from_ft__ */

#undef rtmp
#undef itab
#undef ftab
#undef sp
#undef dp


/*     *********** */
/*     *         * */
/*     * GET_STRING_FROM_FT */
/*     *         * */
/*     *********** */
/* SOURCE fqshrftb.for:300 */
/*<       character*16functionget_string_from_ft(ftp) >*/
/* Character */ VOID feq_gen_get_string_from_ft_d_(char *ret_val, ftnlen ret_val_len, 
	integer *ftp)
{
    /* System generated locals */
    char feq_gen_ch_d_2[8];
    static doublereal equiv_2[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define dp (equiv_2)
#define sp (feq::BitView<real>(equiv_2, sizeof(equiv_2)))
    extern /* Character */ VOID feq_gen_dp_to_char_d_(char *, ftnlen, doublereal *);
    char cs8[8], cs16[16];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Get a string stored in a function-table header block  and */
/*     return it. */
/* SOURCE fqshrftb.for:305 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:306 */
/*<       integerftp >*/
/* INCLUDE fqshrftb.for:308 */
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
/* INCLUDE fqshrftb.for:309 */
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
/*     Called program units */
/* SOURCE fqshrftb.for:312 */
/*<       character*8dp_to_char >*/
/* SOURCE fqshrftb.for:313 */
/*<       externaldp_to_char >*/
/*     Local */
/* SOURCE fqshrftb.for:317 */
/*<       charactercs8*8,cs16*16 >*/
/* SOURCE fqshrftb.for:318 */
/*<       real*4sp(2) >*/
/* SOURCE fqshrftb.for:319 */
/*<       real*8dp >*/
/* SOURCE fqshrftb.for:322 */
/*<       equivalence(sp(1),dp) >*/
/* *********************************************************************** */
/*     Get upper half of string. */
/* SOURCE fqshrftb.for:325 */
/*<       sp(1)=ftab(ftp) >*/
    sp[0] = ftab[*ftp];
/* SOURCE fqshrftb.for:326 */
/*<       sp(2)=ftab(ftp+1) >*/
    sp[1] = ftab[*ftp + 1];
/* SOURCE fqshrftb.for:327 */
/*<       cs8=dp_to_char(dp) >*/
    feq_gen_dp_to_char_d_(feq_gen_ch_d_2, (ftnlen)8, dp);
    s_copy(cs8, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:328 */
/*<       cs16(1:8)=cs8 >*/
    s_copy(cs16, cs8, (ftnlen)8, (ftnlen)8);
/*     Get lower half of string */
/* SOURCE fqshrftb.for:330 */
/*<       sp(1)=ftab(ftp+2) >*/
    sp[0] = ftab[*ftp + 2];
/* SOURCE fqshrftb.for:331 */
/*<       sp(2)=ftab(ftp+3) >*/
    sp[1] = ftab[*ftp + 3];
/* SOURCE fqshrftb.for:332 */
/*<       cs8=dp_to_char(dp) >*/
    feq_gen_dp_to_char_d_(feq_gen_ch_d_2, (ftnlen)8, dp);
    s_copy(cs8, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:333 */
/*<       cs16(9:16)=cs8 >*/
    s_copy(cs16 + 8, cs8, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:334 */
/*<       get_string_from_ft=cs16 >*/
    s_copy(ret_val, cs16, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:335 */
/*<       return >*/
    return ;
/* SOURCE fqshrftb.for:336 */
/*<       end >*/
} /* get_string_from_ft__ */

#undef rtmp
#undef itab
#undef ftab
#undef sp
#undef dp


/*     *********** */
/*     *         * */
/*     * PUT_DP_IN_FT */
/*     *         * */
/*     *********** */
/* SOURCE fqshrftb.for:343 */
/*<       subroutineput_dp_in_ft(ftp,dpin) >*/
/* Subroutine */ int feq_gen_put_dp_in_ft_d_(integer *ftp, doublereal *dpin)
{
    /* System generated locals */
    static doublereal equiv_2[1];

    /* Local variables */
#define dp (equiv_2)
#define sp (feq::BitView<real>(equiv_2, sizeof(equiv_2)))
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Put the real*8 value in DPIN into a function-table header block */
/*     with the first byte being stored in the first byte of */
/*     the four-byte word at FTP. */
/* SOURCE fqshrftb.for:349 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:350 */
/*<       real*8dpin >*/
/* SOURCE fqshrftb.for:352 */
/*<       integerftp >*/
/* INCLUDE fqshrftb.for:354 */
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
/* INCLUDE fqshrftb.for:355 */
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
/* SOURCE fqshrftb.for:359 */
/*<       real*4sp(2) >*/
/* SOURCE fqshrftb.for:360 */
/*<       real*8dp >*/
/* SOURCE fqshrftb.for:362 */
/*<       equivalence(sp(1),dp) >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:364 */
/*<       dp=dpin >*/
    *dp = *dpin;
/* SOURCE fqshrftb.for:365 */
/*<       ftab(ftp)=sp(1) >*/
    ftab[*ftp] = sp[0];
/* SOURCE fqshrftb.for:366 */
/*<       ftab(ftp+1)=sp(2) >*/
    ftab[*ftp + 1] = sp[1];
/* SOURCE fqshrftb.for:367 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:368 */
/*<       end >*/
} /* put_dp_in_ft__ */

#undef rtmp
#undef itab
#undef ftab
#undef sp
#undef dp


/*     *********** */
/*     *         * */
/*     * GET_DP_FROM_FT */
/*     *         * */
/*     *********** */
/* SOURCE fqshrftb.for:375 */
/*<       real*8functionget_dp_from_ft(ftp) >*/
doublereal feq_gen_get_dp_from_ft_d_(integer *ftp)
{
    /* System generated locals */
    doublereal ret_val;
    static doublereal equiv_2[1];

    /* Local variables */
#define dp (equiv_2)
#define sp (feq::BitView<real>(equiv_2, sizeof(equiv_2)))
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Get a a REAL*8 value stored in a function-table header block and */
/*     return it. */
/* SOURCE fqshrftb.for:380 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:381 */
/*<       integerftp >*/
/* INCLUDE fqshrftb.for:383 */
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
/* INCLUDE fqshrftb.for:384 */
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
/* SOURCE fqshrftb.for:388 */
/*<       real*4sp(2) >*/
/* SOURCE fqshrftb.for:389 */
/*<       real*8dp >*/
/* SOURCE fqshrftb.for:391 */
/*<       equivalence(sp(1),dp) >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:393 */
/*<       sp(1)=ftab(ftp) >*/
    sp[0] = ftab[*ftp];
/* SOURCE fqshrftb.for:394 */
/*<       sp(2)=ftab(ftp+1) >*/
    sp[1] = ftab[*ftp + 1];
/* SOURCE fqshrftb.for:395 */
/*<       get_dp_from_ft=dp >*/
    ret_val = *dp;
/* SOURCE fqshrftb.for:396 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrftb.for:397 */
/*<       end >*/
} /* get_dp_from_ft__ */

#undef rtmp
#undef itab
#undef ftab
#undef sp
#undef dp


/* SOURCE fqshrftb.for:399 */
/*<        >*/
/* Subroutine */ int feq_gen_get_zone_etc_d_(integer *stdout, integer *tabadrs, char *
	zone, char *hgrid, char *vdatum, char *unitsys, char *basis, ftnlen 
	zone_len, ftnlen hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, 
	ftnlen basis_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*BUG* Table id=\002,a,\002 has invalid ty\
pe=\002,i7,\002 in subroutine get_zone_etc\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[8], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_chr8_from_ft_d_(char *, ftnlen, integer *),
	     feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer ip, feq_gen_feql_select1_d_, feq_gen_type_d_;
    extern integer gettbn_(integer *), gettyp_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_50, 0 };


/*     Get the zone... info from a function table. */
/* SOURCE fqshrftb.for:405 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:407 */
/*<       integerstdout,tabadrs >*/
/* SOURCE fqshrftb.for:408 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/* SOURCE fqshrftb.for:410 */
/*<       integergettbn,gettyp >*/
/* SOURCE fqshrftb.for:411 */
/*<       character*8get_chr8_from_ft >*/
/* SOURCE fqshrftb.for:412 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:413 */
/*<       externalget_chr8_from_ft,get_tabid,gettbn,gettyp >*/
/*     Local */
/* SOURCE fqshrftb.for:416 */
/*<       integerip,type >*/
/*     **********************Formats************************************* */
/* SOURCE fqshrftb.for:399 */
/*<       integer feql_select1 >*/
/* SOURCE fqshrftb.for:418 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:421 */
/*<       ip=tabadrs >*/
/* L50: */
    ip = *tabadrs;
/* SOURCE fqshrftb.for:422 */
/*<       type=gettyp(ip) >*/
    feq_gen_type_d_ = gettyp_(&ip);
/* SOURCE fqshrftb.for:423 */
/*<       feql_select1=type >*/
    feq_gen_feql_select1_d_ = feq_gen_type_d_;
/* SOURCE fqshrftb.for:423 */
/*<        >*/
    if (feq_gen_feql_select1_d_ == 2 || feq_gen_feql_select1_d_ == 3 || feq_gen_feql_select1_d_ == 4 || 
	    feq_gen_feql_select1_d_ == 7 || feq_gen_feql_select1_d_ == 8 || feq_gen_feql_select1_d_ == 9 
	    || feq_gen_feql_select1_d_ == 11) {
/*       These are one-d function tables. */
/* SOURCE fqshrftb.for:431 */
/*<       zone=get_chr8_from_ft(ip+6) >*/
	feq_gen_i_d_1 = ip + 6;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(zone, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:432 */
/*<       hgrid=get_chr8_from_ft(ip+8) >*/
	feq_gen_i_d_1 = ip + 8;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(hgrid, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:433 */
/*<       vdatum=get_chr8_from_ft(ip+10) >*/
	feq_gen_i_d_1 = ip + 10;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(vdatum, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:434 */
/*<       unitsys=get_chr8_from_ft(ip+12) >*/
	feq_gen_i_d_1 = ip + 12;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(unitsys, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:435 */
/*<       basis=get_chr8_from_ft(ip+20) >*/
	feq_gen_i_d_1 = ip + 20;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(basis, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:423 */
/*<        >*/
    } else if (feq_gen_feql_select1_d_ == 6 || feq_gen_feql_select1_d_ == 10 || feq_gen_feql_select1_d_ 
	    == 13 || feq_gen_feql_select1_d_ == 14 || feq_gen_feql_select1_d_ == 43) {
/*       These are two-d function tables:  6, 10,13,14 are */
/*       created manually or by fequtl.  43 is from conversion */
/*       right after input in feq. */
/* SOURCE fqshrftb.for:441 */
/*<       zone=get_chr8_from_ft(ip+12) >*/
	feq_gen_i_d_1 = ip + 12;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(zone, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:442 */
/*<       hgrid=get_chr8_from_ft(ip+14) >*/
	feq_gen_i_d_1 = ip + 14;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(hgrid, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:443 */
/*<       vdatum=get_chr8_from_ft(ip+16) >*/
	feq_gen_i_d_1 = ip + 16;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(vdatum, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:444 */
/*<       unitsys=get_chr8_from_ft(ip+18) >*/
	feq_gen_i_d_1 = ip + 18;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(unitsys, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:445 */
/*<       basis=get_chr8_from_ft(ip+24) >*/
	feq_gen_i_d_1 = ip + 24;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(basis, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:423 */
/*<        >*/
    } else if (feq_gen_feql_select1_d_ == 20 || feq_gen_feql_select1_d_ == 21 || feq_gen_feql_select1_d_ 
	    == 22 || feq_gen_feql_select1_d_ == 23 || feq_gen_feql_select1_d_ == 24 || 
	    feq_gen_feql_select1_d_ == 25 || feq_gen_feql_select1_d_ == 30 || feq_gen_feql_select1_d_ == 
	    31 || feq_gen_feql_select1_d_ == 32 || feq_gen_feql_select1_d_ == 33 || 
	    feq_gen_feql_select1_d_ == 34 || feq_gen_feql_select1_d_ == 35) {
/*       20-25 are for cross-section function tables as input. */
/*       Types 30-35 are  generated internally on user option */
/*       immediately after input of types 20-25. */
/* SOURCE fqshrftb.for:452 */
/*<       zone=get_chr8_from_ft(ip+22) >*/
	feq_gen_i_d_1 = ip + 22;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(zone, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:453 */
/*<       hgrid=get_chr8_from_ft(ip+24) >*/
	feq_gen_i_d_1 = ip + 24;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(hgrid, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:454 */
/*<       vdatum=get_chr8_from_ft(ip+26) >*/
	feq_gen_i_d_1 = ip + 26;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(vdatum, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:455 */
/*<       unitsys=get_chr8_from_ft(ip+28) >*/
	feq_gen_i_d_1 = ip + 28;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(unitsys, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:456 */
/*<       basis=get_chr8_from_ft(ip+30) >*/
	feq_gen_i_d_1 = ip + 30;
	feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_i_d_1);
	s_copy(basis, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:423 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:426 */
/*<       write(stdout,50)get_tabid(gettbn(tabadrs)),type >*/
	feq_gen_io_d__58.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__58);
	feq_gen_i_d_1 = gettbn_(tabadrs);
	feq_gen_get_tabid_d_(feq_gen_ch_d_3, (ftnlen)16, &feq_gen_i_d_1);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:427 */
/*<       stop'Abnormal stop.  Bug found' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Bug found"), (ftnlen)25);
/* SOURCE fqshrftb.for:458 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:459 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:460 */
/*<       end >*/
} /* get_zone_etc__ */




/* SOURCE fqshrftb.for:464 */
/*<       integerfunctiongettyp(adrs) >*/
integer gettyp_(integer *adrs)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Get the table type of the table at ADRS. */
/* SOURCE fqshrftb.for:470 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:472 */
/*<       integeradrs >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:478 */
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
/* INCLUDE fqshrftb.for:479 */
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
/* SOURCE fqshrftb.for:481 */
/*<       gettyp=itab(adrs+2) >*/
    ret_val = itab[*adrs + 2];
/* SOURCE fqshrftb.for:482 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrftb.for:483 */
/*<       end >*/
} /* gettyp_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:487 */
/*<       subroutineget_east_north(stdout,tabadrs,easting,northing) >*/
/* Subroutine */ int feq_gen_get_east_north_d_(integer *stdout, integer *tabadrs, 
	doublereal *easting, doublereal *northing)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*BUG* Table id=\002,a,\002 has invalid ty\
pe=\002,i7,\002 in subroutine get_east_north\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer feq_gen_feql_select2_d_, feq_gen_type_d_;
    extern integer gettbn_(integer *), gettyp_(integer *);
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_50, 0 };


/*     Get the easting and northing values from a function table. */
/* SOURCE fqshrftb.for:492 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:494 */
/*<       integerstdout,tabadrs >*/
/* SOURCE fqshrftb.for:495 */
/*<       real*8easting,northing >*/
/* SOURCE fqshrftb.for:497 */
/*<       integergettbn,gettyp >*/
/* SOURCE fqshrftb.for:498 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE fqshrftb.for:499 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:500 */
/*<       externalget_dp_from_ft,get_tabid,gettbn,gettyp >*/
/*     Local */
/* SOURCE fqshrftb.for:503 */
/*<       integertype >*/
/*     **********************Formats************************************* */
/* SOURCE fqshrftb.for:487 */
/*<       integer feql_select2 >*/
/* SOURCE fqshrftb.for:505 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:508 */
/*<       type=gettyp(tabadrs) >*/
/* L50: */
    feq_gen_type_d_ = gettyp_(tabadrs);
/* SOURCE fqshrftb.for:509 */
/*<       feql_select2=type >*/
    feq_gen_feql_select2_d_ = feq_gen_type_d_;
/* SOURCE fqshrftb.for:509 */
/*<        >*/
    if (feq_gen_feql_select2_d_ == 2 || feq_gen_feql_select2_d_ == 3 || feq_gen_feql_select2_d_ == 4 || 
	    feq_gen_feql_select2_d_ == 7 || feq_gen_feql_select2_d_ == 8 || feq_gen_feql_select2_d_ == 9 
	    || feq_gen_feql_select2_d_ == 11) {
/*       These are one-d function tables. */
/* SOURCE fqshrftb.for:517 */
/*<       easting=get_dp_from_ft(tabadrs+14) >*/
	feq_gen_i_d_1 = *tabadrs + 14;
	*easting = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:518 */
/*<       northing=get_dp_from_ft(tabadrs+16) >*/
	feq_gen_i_d_1 = *tabadrs + 16;
	*northing = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:509 */
/*<        >*/
    } else if (feq_gen_feql_select2_d_ == 6 || feq_gen_feql_select2_d_ == 10 || feq_gen_feql_select2_d_ 
	    == 13 || feq_gen_feql_select2_d_ == 14 || feq_gen_feql_select2_d_ == 43) {
/*       These are two-d function tables:  6, 10,13,14 are */
/*       created manually or by fequtl.  43 is from conversion */
/*       right after input. */
/* SOURCE fqshrftb.for:524 */
/*<       easting=get_dp_from_ft(tabadrs+20) >*/
	feq_gen_i_d_1 = *tabadrs + 20;
	*easting = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:525 */
/*<       northing=get_dp_from_ft(tabadrs+22) >*/
	feq_gen_i_d_1 = *tabadrs + 22;
	*northing = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:509 */
/*<        >*/
    } else if (feq_gen_feql_select2_d_ == 20 || feq_gen_feql_select2_d_ == 21 || feq_gen_feql_select2_d_ 
	    == 22 || feq_gen_feql_select2_d_ == 23 || feq_gen_feql_select2_d_ == 24 || 
	    feq_gen_feql_select2_d_ == 25 || feq_gen_feql_select2_d_ == 30 || feq_gen_feql_select2_d_ == 
	    31 || feq_gen_feql_select2_d_ == 32 || feq_gen_feql_select2_d_ == 33 || 
	    feq_gen_feql_select2_d_ == 34 || feq_gen_feql_select2_d_ == 35) {
/*       20-25 are for cross-section function tables as input. */
/*       Types 30-35 are  generated internally on user option */
/*       immediately after input of types 20-25 */
/* SOURCE fqshrftb.for:532 */
/*<       easting=get_dp_from_ft(tabadrs+8) >*/
	feq_gen_i_d_1 = *tabadrs + 8;
	*easting = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:533 */
/*<       northing=get_dp_from_ft(tabadrs+10) >*/
	feq_gen_i_d_1 = *tabadrs + 10;
	*northing = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:509 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:512 */
/*<       write(stdout,50)get_tabid(gettbn(tabadrs)),type >*/
	feq_gen_io_d__64.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__64);
	feq_gen_i_d_1 = gettbn_(tabadrs);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_1);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:513 */
/*<       stop'Abnormal stop.  Bug found' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Bug found"), (ftnlen)25);
/* SOURCE fqshrftb.for:535 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:536 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:537 */
/*<       end >*/
} /* get_east_north__ */




/* SOURCE fqshrftb.for:541 */
/*<       subroutineput_east_north(stdout,tabadrs,easting,northing) >*/
/* Subroutine */ int feq_gen_put_east_north_d_(integer *stdout, integer *tabadrs, 
	doublereal *easting, doublereal *northing)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*BUG* Table id=\002,a,\002 has invalid ty\
pe=\002,i7,\002 in subroutine put_east_north\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer feq_gen_feql_select3_d_, feq_gen_type_d_;
    extern /* Subroutine */ int feq_gen_put_dp_in_ft_d_(integer *, doublereal *);
    extern integer gettbn_(integer *), gettyp_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__67 = { 0, 0, 0, fmt_50, 0 };


/*     Put the easting and northing values into a function table. */
/* SOURCE fqshrftb.for:546 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:548 */
/*<       integerstdout,tabadrs >*/
/* SOURCE fqshrftb.for:549 */
/*<       real*8easting,northing >*/
/* SOURCE fqshrftb.for:551 */
/*<       integergettbn,gettyp >*/
/* SOURCE fqshrftb.for:552 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:553 */
/*<       externalput_dp_in_ft,get_tabid,gettbn,gettyp >*/
/*     Local */
/* SOURCE fqshrftb.for:556 */
/*<       integertype >*/
/*     **********************Formats************************************* */
/* SOURCE fqshrftb.for:541 */
/*<       integer feql_select3 >*/
/* SOURCE fqshrftb.for:558 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:562 */
/*<       type=gettyp(tabadrs) >*/
/* L50: */
    feq_gen_type_d_ = gettyp_(tabadrs);
/* SOURCE fqshrftb.for:563 */
/*<       feql_select3=type >*/
    feq_gen_feql_select3_d_ = feq_gen_type_d_;
/* SOURCE fqshrftb.for:563 */
/*<        >*/
    if (feq_gen_feql_select3_d_ == 2 || feq_gen_feql_select3_d_ == 3 || feq_gen_feql_select3_d_ == 4 || 
	    feq_gen_feql_select3_d_ == 7 || feq_gen_feql_select3_d_ == 8 || feq_gen_feql_select3_d_ == 9 
	    || feq_gen_feql_select3_d_ == 11) {
/*       These are one-d function tables. */
/* SOURCE fqshrftb.for:571 */
/*<       callput_dp_in_ft(tabadrs+14,easting) >*/
	feq_gen_i_d_1 = *tabadrs + 14;
	feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, easting);
/* SOURCE fqshrftb.for:572 */
/*<       callput_dp_in_ft(tabadrs+16,northing) >*/
	feq_gen_i_d_1 = *tabadrs + 16;
	feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, northing);
/* SOURCE fqshrftb.for:563 */
/*<        >*/
    } else if (feq_gen_feql_select3_d_ == 6 || feq_gen_feql_select3_d_ == 10 || feq_gen_feql_select3_d_ 
	    == 13 || feq_gen_feql_select3_d_ == 14 || feq_gen_feql_select3_d_ == 43) {
/*       These are two-d function tables:  6, 10,13,14 are */
/*       created manually or by fequtl.  43 is from conversion */
/*       right after input. */
/* SOURCE fqshrftb.for:578 */
/*<       callput_dp_in_ft(tabadrs+20,easting) >*/
	feq_gen_i_d_1 = *tabadrs + 20;
	feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, easting);
/* SOURCE fqshrftb.for:579 */
/*<       callput_dp_in_ft(tabadrs+22,northing) >*/
	feq_gen_i_d_1 = *tabadrs + 22;
	feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, northing);
/* SOURCE fqshrftb.for:563 */
/*<        >*/
    } else if (feq_gen_feql_select3_d_ == 20 || feq_gen_feql_select3_d_ == 21 || feq_gen_feql_select3_d_ 
	    == 22 || feq_gen_feql_select3_d_ == 23 || feq_gen_feql_select3_d_ == 24 || 
	    feq_gen_feql_select3_d_ == 25 || feq_gen_feql_select3_d_ == 30 || feq_gen_feql_select3_d_ == 
	    31 || feq_gen_feql_select3_d_ == 32 || feq_gen_feql_select3_d_ == 33 || 
	    feq_gen_feql_select3_d_ == 34 || feq_gen_feql_select3_d_ == 35) {
/*       20-25 are for cross-section function tables as input. */
/*       Types 30-35 are  generated internally on user option */
/*       immediately after input of types 20-25 */
/* SOURCE fqshrftb.for:586 */
/*<       callput_dp_in_ft(tabadrs+8,easting) >*/
	feq_gen_i_d_1 = *tabadrs + 8;
	feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, easting);
/* SOURCE fqshrftb.for:587 */
/*<       callput_dp_in_ft(tabadrs+10,northing) >*/
	feq_gen_i_d_1 = *tabadrs + 10;
	feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, northing);
/* SOURCE fqshrftb.for:563 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:566 */
/*<       write(stdout,50)get_tabid(gettbn(tabadrs)),type >*/
	feq_gen_io_d__67.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__67);
	feq_gen_i_d_1 = gettbn_(tabadrs);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_1);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:567 */
/*<       stop'Abnormal stop.  Bug found' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Bug found"), (ftnlen)25);
/* SOURCE fqshrftb.for:589 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:590 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:591 */
/*<       end >*/
} /* put_east_north__ */




/* SOURCE fqshrftb.for:595 */
/*<        >*/
/* Subroutine */ int feq_gen_put_location_1dtab_d_(integer *adrs, char *zone, char *
	hgrid, char *vdatum, char *unitsys, char *basis, doublereal *easting, 
	doublereal *northing, ftnlen zone_len, ftnlen hgrid_len, ftnlen 
	vdatum_len, ftnlen unitsys_len, ftnlen basis_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int feq_gen_put_dp_in_ft_d_(integer *, doublereal *), 
	    feq_gen_put_chr8_in_ft_d_(integer *, char *, ftnlen);

/*     Store the location, datum, basis information in a one-d table. */
/* SOURCE fqshrftb.for:600 */
/*<       implicitnone >*/
/* INCLUDE fqshrftb.for:602 */
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
/* INCLUDE fqshrftb.for:603 */
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
/* SOURCE fqshrftb.for:605 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:606 */
/*<       real*8easting,northing >*/
/* SOURCE fqshrftb.for:607 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/*     External program units */
/* SOURCE fqshrftb.for:610 */
/*<       externalput_chr8_in_ft,put_dp_in_ft >*/
/*     ****************************************************************** */
/*     Store the zone, grid, datum, and unitsys information */
/* SOURCE fqshrftb.for:613 */
/*<       callput_chr8_in_ft(adrs+6,zone) >*/
    feq_gen_i_d_1 = *adrs + 6;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, zone, (ftnlen)8);
/* SOURCE fqshrftb.for:614 */
/*<       callput_chr8_in_ft(adrs+8,hgrid) >*/
    feq_gen_i_d_1 = *adrs + 8;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, hgrid, (ftnlen)8);
/* SOURCE fqshrftb.for:615 */
/*<       callput_chr8_in_ft(adrs+10,vdatum) >*/
    feq_gen_i_d_1 = *adrs + 10;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, vdatum, (ftnlen)8);
/* SOURCE fqshrftb.for:616 */
/*<       callput_chr8_in_ft(adrs+12,unitsys) >*/
    feq_gen_i_d_1 = *adrs + 12;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, unitsys, (ftnlen)8);
/* SOURCE fqshrftb.for:617 */
/*<       callput_chr8_in_ft(adrs+20,basis) >*/
    feq_gen_i_d_1 = *adrs + 20;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, basis, (ftnlen)8);
/* SOURCE fqshrftb.for:618 */
/*<       callput_dp_in_ft(adrs+14,easting) >*/
    feq_gen_i_d_1 = *adrs + 14;
    feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, easting);
/* SOURCE fqshrftb.for:619 */
/*<       callput_dp_in_ft(adrs+16,northing) >*/
    feq_gen_i_d_1 = *adrs + 16;
    feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, northing);
/* SOURCE fqshrftb.for:620 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:621 */
/*<       end >*/
} /* put_location_1dtab__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:625 */
/*<       subroutinechk_vdatum_unitsys(stdout,vdatum,unitsys,source) >*/
/* Subroutine */ int feq_gen_chk_vdatum_unitsys_d_(integer *stdout, char *vdatum, char 
	*unitsys, char *source, ftnlen vdatum_len, ftnlen unitsys_len, ftnlen 
	source_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*ERR:XXX* Required vertical datum is: \
\002,a,\002 but vertical datum: \002,a,\002 found \002,a)";
    static char fmt_52[] = "(/,\002*ERR:XXX* Required unit system is: \002\
,a,\002 but unit system: \002,a,\002 found \002,a)";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__71 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, fmt_52, 0 };


/*     Check that the value of vdatum and unitsys matches what */
/*     has been set in the global values. */
/* SOURCE fqshrftb.for:630 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:632 */
/*<       integerstdout >*/
/* SOURCE fqshrftb.for:634 */
/*<       character*8vdatum,unitsys >*/
/* SOURCE fqshrftb.for:635 */
/*<       character*(*)source >*/
/* INCLUDE fqshrftb.for:637 */
/*     Common to hold the global value for grid and datum values. */
/* SOURCE grid_datum.cmn:3 */
/*<       character*8g_zone,g_hgrid,g_vdatum,g_unitsys,g_basis >*/
/* SOURCE grid_datum.cmn:6 */
/*<       common/grid_datum/g_zone,g_hgrid,g_vdatum,g_unitsys,g_basis >*/
/*     g_zone- zone designation for the horizontal grid to be used. */
/*             For state plaine coordinates in the US this is an */
/*             integer number.  For example: 4601 denotes the */
/*             north zone in Washington.  The value is stored as */
/*             a string so that any 8 char sequence makes sense. */
/*             Currently, 5 Sept 2007, FEQ/FEQUTL just tracks the */
/*             zone information and does not check it. */
/*     g_hgrid- name for the horizontal grid.  Again a string of up */
/*              to eight characters.  Values that make sense include: */
/*              SPCS27- state plane coordinate system based on NAD 27, */
/*              SPCS83- state plane coordinate system based on NAD 83, */
/*              UTM27- universal transverse Mercator coordinate system */
/*              based on NAD 27, and UTM83-universal transverse Mercator */
/*              coordinate system based on NAD 83, etc */
/*     g_vdatum- the vertical datum: NGVD29, NAVD88, etc. */
/*     g_unitsys- unit system: ENGLISH or METRIC */
/*     g_basis- label for the source of the data the was used */
/*              to create the table.  For example, the year of */
/*              the survey, the name or date of a DTM that was */
/*              used, etc.  This makes it possible to track */
/*              the progress of changes as a model is updated */
/*              with more recently obtained geometric data. */
/*     ******************************formats***************************** */
/* SOURCE fqshrftb.for:640 */
/*<    50  >*/
/* SOURCE fqshrftb.for:642 */
/*<    52  >*/
/*     ****************************************************************** */
/* SOURCE fqshrftb.for:645 */
/*<       if(g_vdatum/='NONE')then >*/
/* L50: */
/* L52: */
    if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0) {
/*       Every value of vdatum must agree with g_vdatum unless it has */
/*       been called not applicable */
/* SOURCE fqshrftb.for:648 */
/*<       if(vdatum/='NA')then >*/
	if (s_cmp(vdatum, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) != 0) {
/* SOURCE fqshrftb.for:649 */
/*<       if(vdatum/=g_vdatum)then >*/
	    if (s_cmp(vdatum, feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, (ftnlen)8, (ftnlen)8) 
		    != 0) {
/* SOURCE fqshrftb.for:650 */
/*<       write(stdout,50)g_vdatum,vdatum,source >*/
		feq_gen_io_d__71.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__71);
		do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, source, source_len);
		e_wsfe();
/* SOURCE fqshrftb.for:651 */
/*<       stop'Abnormal stop: Vertical datum error' >*/
		s_stop(const_cast<char*>("Abnormal stop: Vertical datum error"), (ftnlen)35);
/* SOURCE fqshrftb.for:652 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:653 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:654 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:655 */
/*<       if(g_unitsys/='NONE')then >*/
    if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0) {
/*       Every value of unitsys must agree with g_unitsys unless it has */
/*       been called not applicable */
/* SOURCE fqshrftb.for:658 */
/*<       if(unitsys/='NA')then >*/
	if (s_cmp(unitsys, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) != 0) {
/* SOURCE fqshrftb.for:659 */
/*<       if(unitsys/=g_unitsys)then >*/
	    if (s_cmp(unitsys, feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, (ftnlen)8, (ftnlen)
		    8) != 0) {
/* SOURCE fqshrftb.for:660 */
/*<       write(stdout,52)g_unitsys,unitsys,source >*/
		feq_gen_io_d__72.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__72);
		do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, source, source_len);
		e_wsfe();
/* SOURCE fqshrftb.for:661 */
/*<       stop'Abnormal stop: Unit system error' >*/
		s_stop(const_cast<char*>("Abnormal stop: Unit system error"), (ftnlen)32);
/* SOURCE fqshrftb.for:662 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:663 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:664 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:665 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:666 */
/*<       end >*/
} /* chk_vdatum_unitsys__ */




/* SOURCE fqshrftb.for:671 */
/*<       subroutineatabin(in,stdout,mlft,ntab,eflag,ftp,type) >*/
/* Subroutine */ int atabin_(integer *in, integer *stdout, integer *mlft, 
	integer *ntab, integer *eflag, integer *ftp, integer *feq_gen_type_d_)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;
    static integer step[11] = { 0,2,3,3,0,0,2,3,3,0,3 };
    static integer dpm[24]	/* was [12][2] */ = { 31,28,31,30,31,30,31,31,
	    30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };

    /* Format strings */
    static char fmt_1[] = "(80a)";
    static char fmt_2[] = "(5x,a8,7x,a8,8x,a8,9x,a8,7x,a8)";
    static char fmt_4[] = "(8x,f15.0,10x,f15.0)";
    static char fmt_46[] = "(5x,a10,5x,f10.0,6x,f10.0,7x,f10.0)";
    static char fmt_48[] = "(8f10.0)";
    static char fmt_50[] = "(i4,1x,i2,1x,i2,7f10.0)";
    static char fmt_11[] = "(\002 \002,80a)";
    static char fmt_47[] = "(\002 Shift for function value after scaling=\
\002,1pe12.5,\002 Scale factor for function= \002,1pe12.5,/,\002 Arg scale f\
actor=\002,1pe12.5,\002 Arg shift=\002,1pe12.5)";
    static char fmt_49[] = "(\002 \002,f10.2,7(1pe10.3))";
    static char fmt_51[] = "(\002 \002,i4,1x,i2,1x,i2,f10.3,5(1pe10.3))";
    static char fmt_52[] = "(/,\002 *WRN:XXX* Non-zero REFL found without a \
prefix of h or s.\002,/,\002   The value is ignored.  If the value is\002\
,\002 a shift to be  applied to the function,\002,/\002   then prefix\002\
,\002 it with an s, otherwise prefix it with an h.\002)";
    static char fmt_53[] = "(\002 Reference level=\002,1pe12.5,\002 Scale fa\
ctor for function= \002,1pe12.5,/,\002 Arg scale factor=\002,1pe12.5,\002 Ar\
g shift=\002,1pe12.5)";
    static char fmt_58[] = "(/,\002 *WRN:53* Unexpected end of a function ta\
ble.\002)";
    static char fmt_60[] = "(/,\002 *WRN:55* End of file found before end of\
 table.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), do_fio(
	    integer *, char *, ftnlen), e_rsfi(), s_wsfe(cilist *), e_wsfe(), 
	    f_back(alist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    doublereal northing;
    real f[7];
    integer feq_gen_i_d_, n;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal hr;
    integer lp;
    doublereal jt;
    extern /* Subroutine */ int feq_gen_put_location_1dtab_d_(integer *, char *, char *
	    , char *, char *, char *, doublereal *, doublereal *, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen);
    real fac, arg;
    extern integer mjd_(integer *, integer *, integer *);
    doublereal bjt;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer dtp, out;
    extern /* Subroutine */ int feq_gen_chk_vdatum_unitsys_d_(integer *, char *, char *
	    , char *, ftnlen, ftnlen, ftnlen), feq_gen_feq_adjustl_d_(char *, char *, 
	    ftnlen, ftnlen);
    real afac;
    char head[80];
    real barg;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char line[80], zone[8];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char hgrid[8], basis[8];
    integer olddy, oldmn;
    real shift;
    integer oldyr, feq_gen_reflev_active_d_;
    char feq_gen_reflev_string_d_[10];
    integer argflg;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    real reflev;
    integer ftpold;
    char vdatum[8];
    extern integer lpyear_(integer *);
    doublereal easting;
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_47, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_11, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_49, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__117 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__118 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__123 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input an arbitrary interval table */
/*     TYPE = 2 - single function - linear interpolation */
/*     TYPE = 3 - 2 function - quadratic */
/*     TYPE = 4 - 2 function - hermite interpolation */
/*     TYPE=  7 - single function, linear interpolation but time argument */
/*                given in yr mn dy hr with hr allowed to be fractional */
/*     TYPE = 8 - like type 3 but with argument like 7 */
/*     TYPE = 9 - like type 4 but with argument like 7 */
/*     TYPE =11 - like type 7 but two functions not related by any */
/*                simple rule. Reserved for wind, giving speed and */
/*                direction. */
/* SOURCE fqshrftb.for:688 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:690 */
/*<       integereflag,ftp,in,stdout,mlft,ntab,type >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     MLFT   - maximum length of FTAB/ITAB */
/*     NTAB   - table number */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     FTP    - next open location in the function table storage */
/*     TYPE   - table type */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:702 */
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
/* INCLUDE fqshrftb.for:703 */
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
/* INCLUDE fqshrftb.for:704 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:707 */
/*<       integerdpm(12,2),step(11) >*/
/* SOURCE fqshrftb.for:708 */
/*<       savedpm,step >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:711 */
/*<        >*/
/* SOURCE fqshrftb.for:713 */
/*<       realafac,arg,barg,f(7),fac,reflev,shift >*/
/* SOURCE fqshrftb.for:714 */
/*<       real*8hr,jt,bjt,easting,northing,dnull >*/
/* SOURCE fqshrftb.for:715 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:719 */
/*<       intrinsicdble,iabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE fqshrftb.for:722 */
/*<       integerlpyear,mjd >*/
/* SOURCE fqshrftb.for:723 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:726 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE fqshrftb.for:730 */
/*<       datadnull/-33d6/ >*/
/* SOURCE fqshrftb.for:731 */
/*<       datastep/0,2,3,3,0,0,2,3,3,0,3/ >*/
/* SOURCE fqshrftb.for:732 */
/*<        >*/
/* SOURCE fqshrftb.for:736 */
/*<     1 format(80a) >*/
/* L1: */
/* SOURCE fqshrftb.for:737 */
/*<     2 format(5x,a8,7x,a8,8x,a8,9x,a8,7x,a8) >*/
/* L2: */
/* SOURCE fqshrftb.for:738 */
/*<     4 format(8x,f15.0,10x,f15.0) >*/
/* L4: */
/* SOURCE fqshrftb.for:739 */
/*<    46 format(5x,a10,5x,f10.0,6x,f10.0,7x,f10.0) >*/
/* L46: */
/* SOURCE fqshrftb.for:740 */
/*<    48 format(8f10.0) >*/
/* L48: */
/* SOURCE fqshrftb.for:741 */
/*<    50 format(i4,1x,i2,1x,i2,7f10.0) >*/
/* L50: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:744 */
/*<    11 format(' ',80a) >*/
/* L11: */
/* SOURCE fqshrftb.for:745 */
/*<    47  >*/
/* L47: */
/* SOURCE fqshrftb.for:748 */
/*<    49 format(' ',f10.2,7(1pe10.3)) >*/
/* L49: */
/* SOURCE fqshrftb.for:749 */
/*<    51 format(' ',i4,1x,i2,1x,i2,f10.3,5(1pe10.3)) >*/
/* L51: */
/* SOURCE fqshrftb.for:750 */
/*<    52  >*/
/* L52: */
/* SOURCE fqshrftb.for:755 */
/*<    53  >*/
/* L53: */
/* SOURCE fqshrftb.for:758 */
/*<    58 format(/,' *WRN:53* Unexpected end of a function table.') >*/
/* L58: */
/* SOURCE fqshrftb.for:759 */
/*<    60 format(/,' *WRN:55* End of file found before end of table.') >*/
/* L60: */
/* *********************************************************************** */
/* SOURCE fqshrftb.for:761 */
/*<       zone='NONE' >*/
    s_copy(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:762 */
/*<       hgrid='NONE' >*/
    s_copy(hgrid, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:763 */
/*<       vdatum='NONE' >*/
    s_copy(vdatum, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:764 */
/*<       unitsys='NONE' >*/
    s_copy(unitsys, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:765 */
/*<       basis='NONE' >*/
    s_copy(basis, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:766 */
/*<       easting=dnull >*/
    easting = dnull;
/* SOURCE fqshrftb.for:767 */
/*<       northing=dnull >*/
    northing = dnull;
/* SOURCE fqshrftb.for:769 */
/*<       oldyr=1900 >*/
    oldyr = 1900;
/* SOURCE fqshrftb.for:770 */
/*<       oldmn=1 >*/
    oldmn = 1;
/* SOURCE fqshrftb.for:771 */
/*<       olddy=1 >*/
    olddy = 1;
/* SOURCE fqshrftb.for:773 */
/*<       out=1 >*/
    out = 1;
/* SOURCE fqshrftb.for:774 */
/*<       if(type.lt.0)out=0 >*/
    if (*feq_gen_type_d_ < 0) {
	out = 0;
    }
/* SOURCE fqshrftb.for:775 */
/*<       type=iabs(type) >*/
    *feq_gen_type_d_ = abs(*feq_gen_type_d_);
/*     For TYPES 7, 8, 9, and 11 SET AN ARGUMENT FLAG. */
/* SOURCE fqshrftb.for:779 */
/*<       if(type.ge.7.and.type.le.9)then >*/
    if (*feq_gen_type_d_ >= 7 && *feq_gen_type_d_ <= 9) {
/* SOURCE fqshrftb.for:780 */
/*<       argflg=1 >*/
	argflg = 1;
/* SOURCE fqshrftb.for:781 */
/*<       elseif(type.eq.11)then >*/
    } else if (*feq_gen_type_d_ == 11) {
/* SOURCE fqshrftb.for:782 */
/*<       argflg=1 >*/
	argflg = 1;
/* SOURCE fqshrftb.for:783 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:784 */
/*<       argflg=0 >*/
	argflg = 0;
/* SOURCE fqshrftb.for:785 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:787 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:790 */
/*<       if(line(1:4)=='ZONE')then >*/
    if (s_cmp(line, const_cast<char*>("ZONE"), (ftnlen)4, (ftnlen)4) == 0) {
/*       We have a line of information on zone, hgrid, vdatum, and unitsys. */
/*       If present it will ALWAYS be followed by a line giving the hgrid location! */
/* SOURCE fqshrftb.for:793 */
/*<       read(line,2,err=991)zone,hgrid,vdatum,unitsys,basis >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_2;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:794 */
/*<       callfeq_adjustl(zone,zone) >*/
	feq_gen_feq_adjustl_d_(zone, zone, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:795 */
/*<       callfeq_adjustl(hgrid,hgrid) >*/
	feq_gen_feq_adjustl_d_(hgrid, hgrid, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:796 */
/*<       callfeq_adjustl(vdatum,vdatum) >*/
	feq_gen_feq_adjustl_d_(vdatum, vdatum, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:797 */
/*<       callfeq_adjustl(unitsys,unitsys) >*/
	feq_gen_feq_adjustl_d_(unitsys, unitsys, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:798 */
/*<       callfeq_adjustl(basis,basis) >*/
	feq_gen_feq_adjustl_d_(basis, basis, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:799 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:802 */
/*<       if(zone=='NA')then >*/
	if (s_cmp(zone, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) == 0) {
/*         Horizontal location has no meaning. */
/* SOURCE fqshrftb.for:804 */
/*<       easting=dnull >*/
	    easting = dnull;
/* SOURCE fqshrftb.for:805 */
/*<       northing=dnull >*/
	    northing = dnull;
/* SOURCE fqshrftb.for:806 */
/*<       ft_loc_status(ntab)='N' >*/
	    *(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*ntab - 1] = 'N';
/* SOURCE fqshrftb.for:807 */
/*<       elseif(line(9:23)==' ')then >*/
	} else if (s_cmp(line + 8, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1) == 0) {
/*         The easting value was blank.  This means that it was */
/*         missing.  We treat the northing as missing too. */
/* SOURCE fqshrftb.for:810 */
/*<       easting=dnull >*/
	    easting = dnull;
/* SOURCE fqshrftb.for:811 */
/*<       northing=dnull >*/
	    northing = dnull;
/* SOURCE fqshrftb.for:812 */
/*<       ft_loc_status(ntab)='M' >*/
	    *(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*ntab - 1] = 'M';
/* SOURCE fqshrftb.for:813 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:814 */
/*<       read(line,4,err=991)easting,northing >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_4;
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal))
		    ;
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal)
		    );
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
/* SOURCE fqshrftb.for:815 */
/*<       if(easting>dnull)then >*/
	    if (easting > dnull) {
/*           We assume valid value for both. */
/* SOURCE fqshrftb.for:817 */
/*<       ft_loc_status(ntab)='I' >*/
		*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*ntab - 1] = 'I';
/* SOURCE fqshrftb.for:818 */
/*<       else >*/
	    } else {
/*           Values are missing */
/* SOURCE fqshrftb.for:820 */
/*<       ft_loc_status(ntab)='M' >*/
		*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*ntab - 1] = 'M';
/* SOURCE fqshrftb.for:821 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:822 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:823 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:826 */
/*<       else >*/
    } else {
/*       We assume complete lack of the two header lines indicates */
/*       missing information.  Most tables from models prior to this */
/*       software change, will have no information on location.  Most */
/*       function tables will have a meaningful location.  Any that */
/*       do not, will have to be manually changed with the proper */
/*       header info:  ZONE =NONE etc, to suppress location information. */
/* SOURCE fqshrftb.for:833 */
/*<       ft_loc_status(ntab)='M' >*/
	*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*ntab - 1] = 'M';
/* SOURCE fqshrftb.for:834 */
/*<       easting=dnull >*/
	easting = dnull;
/* SOURCE fqshrftb.for:835 */
/*<       northing=dnull >*/
	northing = dnull;
/* SOURCE fqshrftb.for:836 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:837 */
/*<       read(line,46,err=991)reflev_string,fac,afac,shift >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_46;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_reflev_string_d_, (ftnlen)10);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&fac, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&afac, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*     Process reference level.  Once ignored, is active now! */
/* SOURCE fqshrftb.for:840 */
/*<       callfeq_adjustl(reflev_string,reflev_string) >*/
    feq_gen_feq_adjustl_d_(feq_gen_reflev_string_d_, feq_gen_reflev_string_d_, (ftnlen)10, (ftnlen)10);
/* SOURCE fqshrftb.for:841 */
/*<       if(reflev_string(1:1)=='s')then >*/
    if (*(unsigned char *)feq_gen_reflev_string_d_ == 's') {
/*       This is a shift value for the first function only.  That is, */
/*       we add this value to whatever we read for the first function. */
/* SOURCE fqshrftb.for:844 */
/*<       reflev_string=reflev_string(2:) >*/
	s_copy(feq_gen_reflev_string_d_, feq_gen_reflev_string_d_ + 1, (ftnlen)10, (ftnlen)9);
/* SOURCE fqshrftb.for:845 */
/*<       read(reflev_string,'(f10.0)',err=991)reflev >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = feq_gen_reflev_string_d_;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(f10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&reflev, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:846 */
/*<       reflev_active=1 >*/
	feq_gen_reflev_active_d_ = 1;
/* SOURCE fqshrftb.for:847 */
/*<       ftab(ftp+19)=reflev >*/
	ftab[*ftp + 19] = reflev;
/* SOURCE fqshrftb.for:848 */
/*<       elseif(reflev_string(1:1)=='h')then >*/
    } else if (*(unsigned char *)feq_gen_reflev_string_d_ == 'h') {
/*       This is a value for head NOT added to the first function, but */
/*       stored for later access by FEQ for setting the head datum to match */
/*       what is in the table. */
/* SOURCE fqshrftb.for:852 */
/*<       reflev_string=reflev_string(2:) >*/
	s_copy(feq_gen_reflev_string_d_, feq_gen_reflev_string_d_ + 1, (ftnlen)10, (ftnlen)9);
/* SOURCE fqshrftb.for:853 */
/*<       read(reflev_string,'(f10.0)',err=991)reflev >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = feq_gen_reflev_string_d_;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(f10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&reflev, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:854 */
/*<       reflev_active=2 >*/
	feq_gen_reflev_active_d_ = 2;
/* SOURCE fqshrftb.for:855 */
/*<       ftab(ftp+19)=reflev >*/
	ftab[*ftp + 19] = reflev;
/* SOURCE fqshrftb.for:856 */
/*<       reflev=0.0 >*/
	reflev = (float)0.;
/* SOURCE fqshrftb.for:857 */
/*<       else >*/
    } else {
/*       If non-zero ignore treat it a head reference value.  If zero */
/*       it is taken to be an unused value. */
/* SOURCE fqshrftb.for:860 */
/*<       read(reflev_string,'(f10.0)',err=991)reflev >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = feq_gen_reflev_string_d_;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(f10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&reflev, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:861 */
/*<       if(reflev==0.0)then >*/
	if (reflev == (float)0.) {
/* SOURCE fqshrftb.for:862 */
/*<       reflev_active=0 >*/
	    feq_gen_reflev_active_d_ = 0;
/* SOURCE fqshrftb.for:863 */
/*<       ftab(ftp+19)=reflev >*/
	    ftab[*ftp + 19] = reflev;
/* SOURCE fqshrftb.for:864 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:865 */
/*<       write(stdout,52) >*/
	    feq_gen_io_d__98.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__98);
	    e_wsfe();
/* SOURCE fqshrftb.for:866 */
/*<       reflev_active=2 >*/
	    feq_gen_reflev_active_d_ = 2;
/* SOURCE fqshrftb.for:867 */
/*<       ftab(ftp+19)=reflev >*/
	    ftab[*ftp + 19] = reflev;
/* SOURCE fqshrftb.for:868 */
/*<       reflev=0.0 >*/
	    reflev = (float)0.;
/* SOURCE fqshrftb.for:869 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:870 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:871 */
/*<       itab(ftp+18)=reflev_active >*/
    itab[*ftp + 18] = feq_gen_reflev_active_d_;
/* SOURCE fqshrftb.for:873 */
/*<       if(fac.eq.0.0)fac=1.0 >*/
    if (fac == (float)0.) {
	fac = (float)1.;
    }
/* SOURCE fqshrftb.for:874 */
/*<       if(afac.eq.0.0)afac=1.0 >*/
    if (afac == (float)0.) {
	afac = (float)1.;
    }
/* SOURCE fqshrftb.for:875 */
/*<       if(reflev==1)then >*/
    if (reflev == (float)1.) {
/* SOURCE fqshrftb.for:876 */
/*<       write(stdout,47)reflev,fac,afac,shift >*/
	feq_gen_io_d__99.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__99);
	do_fio(&feq_gen_c_d_1, (char *)&reflev, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&fac, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&afac, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE fqshrftb.for:877 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:878 */
/*<       write(stdout,53)ftab(ftp+19),fac,afac,shift >*/
	feq_gen_io_d__100.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__100);
	do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*ftp + 19).data(), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&fac, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&afac, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE fqshrftb.for:879 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:882 */
/*<        >*/
    feq_gen_chk_vdatum_unitsys_d_(stdout, vdatum, unitsys, const_cast<char*>(" during input of type 2, \
3, 4, 7, 8, 9, or 11 table"), (ftnlen)8, (ftnlen)8, (ftnlen)51);
/* SOURCE fqshrftb.for:885 */
/*<       if((ftp+off234).ge.mlft)callkil(10,ftp,eflag) >*/
    if (*ftp + 22 >= *mlft) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/*     FTP RESERVED FOR THE HIGH ADDRESS OF THE TABLE */
/* SOURCE fqshrftb.for:893 */
/*<       itab(ftp+1)=ntab >*/
    itab[*ftp + 1] = *ntab;
/* SOURCE fqshrftb.for:894 */
/*<       itab(ftp+2)=type >*/
    itab[*ftp + 2] = *feq_gen_type_d_;
/* SOURCE fqshrftb.for:895 */
/*<       if(type.le.11)n=step(type)-1 >*/
    if (*feq_gen_type_d_ <= 11) {
	n = step[*feq_gen_type_d_ - 1] - 1;
    }
/* SOURCE fqshrftb.for:896 */
/*<       if(type==15)n=1 >*/
    if (*feq_gen_type_d_ == 15) {
	n = 1;
    }
/*     INITIALIZE LAST ADDRESS ACCESSED */
/* SOURCE fqshrftb.for:900 */
/*<       if(argflg==0)then >*/
    if (argflg == 0) {
/*       Types 2, 3, and 4 */
/* SOURCE fqshrftb.for:902 */
/*<       itab(ftp+3)=ftp+off234 >*/
	itab[*ftp + 3] = *ftp + 22;
/* SOURCE fqshrftb.for:903 */
/*<       else >*/
    } else {
/*       Point into the dtab and NOT ftab!! */
/* SOURCE fqshrftb.for:905 */
/*<       itab(ftp+3)=(ftp+off234)/2 >*/
	itab[*ftp + 3] = (*ftp + 22) / 2;
/* SOURCE fqshrftb.for:906 */
/*<       endif >*/
    }
/*     Remember the shift and the function factor. */
/* SOURCE fqshrftb.for:908 */
/*<       ftab(ftp+4)=shift >*/
    ftab[*ftp + 4] = shift;
/* SOURCE fqshrftb.for:909 */
/*<       ftab(ftp+5)=fac >*/
    ftab[*ftp + 5] = fac;
/* SOURCE fqshrftb.for:911 */
/*<        >*/
    feq_gen_put_location_1dtab_d_(ftp, zone, hgrid, vdatum, unitsys, basis, &easting, &
	    northing, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     Remember the address of the table */
/* SOURCE fqshrftb.for:916 */
/*<       ftpold=ftp >*/
    ftpold = *ftp;
/*     point to the location for the first time point for single-precision */
/*     arguments. */
/* SOURCE fqshrftb.for:920 */
/*<       ftp=ftp+off234 >*/
    *ftp += 22;
/*     Initialize the pointer into dtab. */
/* SOURCE fqshrftb.for:922 */
/*<       dtp=ftp/2 >*/
    dtp = *ftp / 2;
/* SOURCE fqshrftb.for:924 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:927 */
/*<       read(line,1)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_rsfi();
/* SOURCE fqshrftb.for:928 */
/*<       write(stdout,11)head >*/
    feq_gen_io_d__105.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__105);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE fqshrftb.for:930 */
/*<       barg=-1.0e37 >*/
    barg = (float)-1e37;
/* SOURCE fqshrftb.for:931 */
/*<       bjt=-1.d37 >*/
    bjt = -1e37;
/* SOURCE fqshrftb.for:934 */
/*<  1000 continue >*/
L1000:
/* SOURCE fqshrftb.for:936 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:939 */
/*<       if(line(1:6).eq.'TABLE#'.or.line(1:5).eq.'TABID')then >*/
    if (s_cmp(line, const_cast<char*>("TABLE#"), (ftnlen)6, (ftnlen)6) == 0 || s_cmp(line, const_cast<char*>("TAB\
ID"), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE fqshrftb.for:940 */
/*<       write(stdout,58) >*/
	feq_gen_io_d__108.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__108);
	e_wsfe();
/* SOURCE fqshrftb.for:941 */
/*<       backspacein >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *in;
	f_back(&feq_gen_al_d_1);
/* SOURCE fqshrftb.for:942 */
/*<       goto1500 >*/
	goto L1500;
/* SOURCE fqshrftb.for:943 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:945 */
/*<       if(line(1:7).eq.'ENDFILE')then >*/
    if (s_cmp(line, const_cast<char*>("ENDFILE"), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE fqshrftb.for:946 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__109.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__109);
	e_wsfe();
/* SOURCE fqshrftb.for:947 */
/*<       stop'Abnormal stop.  End of file before end of table!' >*/
	s_stop(const_cast<char*>("Abnormal stop.  End of file before end of table!"), (ftnlen)48)
		;
/* SOURCE fqshrftb.for:948 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:951 */
/*<       if(argflg.eq.0)then >*/
    if (argflg == 0) {
/* SOURCE fqshrftb.for:952 */
/*<       read(line,48,err=991)arg,(f(i),i=1,n) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_48;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_2 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&f[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/*         Apply scale factor to argument.  Scale factor on argument */
/*         does not apply to time series tables. */
/* SOURCE fqshrftb.for:955 */
/*<       arg=arg*afac >*/
	arg *= afac;
/* SOURCE fqshrftb.for:956 */
/*<       if(arg.le.barg)goto1500 >*/
	if (arg <= barg) {
	    goto L1500;
	}
/* SOURCE fqshrftb.for:957 */
/*<       barg=arg >*/
	barg = arg;
/* SOURCE fqshrftb.for:958 */
/*<       if(out.eq.1)then >*/
	if (out == 1) {
/* SOURCE fqshrftb.for:959 */
/*<       write(stdout,49)arg,(f(i),i=1,n) >*/
	    feq_gen_io_d__113.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__113);
	    do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(real));
	    feq_gen_i_d_1 = n;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
		do_fio(&feq_gen_c_d_1, (char *)&f[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* SOURCE fqshrftb.for:960 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:961 */
/*<       if((ftp+n+1).ge.mlft)callkil(10,ftp,eflag) >*/
	if (*ftp + n + 1 >= *mlft) {
	    kil_(&feq_gen_c_d_10, ftp, eflag);
	}
/* SOURCE fqshrftb.for:964 */
/*<       ftab(ftp)=arg+shift >*/
	ftab[*ftp] = static_cast<double>(arg) + shift;
/* SOURCE fqshrftb.for:965 */
/*<       doi=1,n >*/
	feq_gen_i_d_1 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:966 */
/*<       ftp=ftp+1 >*/
	    ++(*ftp);
/* SOURCE fqshrftb.for:967 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE fqshrftb.for:968 */
/*<       ftab(ftp)=f(i)*fac+reflev >*/
		ftab[*ftp] = static_cast<double>(static_cast<double>(f[feq_gen_i_d_ - 1]) * fac) + reflev;
/* SOURCE fqshrftb.for:969 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:970 */
/*<       ftab(ftp)=f(i)*fac >*/
		ftab[*ftp] = static_cast<double>(f[feq_gen_i_d_ - 1]) * fac;
/* SOURCE fqshrftb.for:971 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:972 */
/*<       enddo >*/
	}
/* SOURCE fqshrftb.for:973 */
/*<       ftp=ftp+1 >*/
	++(*ftp);
/* SOURCE fqshrftb.for:974 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE fqshrftb.for:976 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:977 */
/*<       read(line,50,err=991)yr,mn,dy,hr,(f(i),i=1,n) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_50;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_2 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&f[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/*         PROPAGATE YR, MN, AND DY. FIRST VALUES ASSUMED TO BE */
/*         CORRECT */
/* SOURCE fqshrftb.for:982 */
/*<       if(yr.eq.0)yr=oldyr >*/
	if (julian_1.yr == 0) {
	    julian_1.yr = oldyr;
	}
/* SOURCE fqshrftb.for:983 */
/*<       if(mn.eq.0)mn=oldmn >*/
	if (julian_1.mn == 0) {
	    julian_1.mn = oldmn;
	}
/* SOURCE fqshrftb.for:984 */
/*<       if(dy.eq.0)dy=olddy >*/
	if (julian_1.dy == 0) {
	    julian_1.dy = olddy;
	}
/* SOURCE fqshrftb.for:985 */
/*<       lp=lpyear(yr) >*/
	lp = lpyear_(&julian_1.yr);
/*          WRITE(STDOUT,*) 'ATABIN2: DATE=',YR, MN, DY, HR */
/* SOURCE fqshrftb.for:989 */
/*<       oldyr=yr >*/
	oldyr = julian_1.yr;
/* SOURCE fqshrftb.for:990 */
/*<       oldmn=mn >*/
	oldmn = julian_1.mn;
/* SOURCE fqshrftb.for:991 */
/*<       olddy=dy >*/
	olddy = julian_1.dy;
/* SOURCE fqshrftb.for:992 */
/*<       if(mn.lt.1.or.mn.gt.12)then >*/
	if (julian_1.mn < 1 || julian_1.mn > 12) {
/* SOURCE fqshrftb.for:993 */
/*<       write(stdout,*)'*ERR:74* INVALID MONTH IN TABLE#=',get_tabid(ntab) >*/
	    feq_gen_io_d__116.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__116);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("*ERR:74* INVALID MONTH IN TABLE#="), (ftnlen)
		    33);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, ntab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsle();
/* SOURCE fqshrftb.for:995 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrftb.for:996 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:997 */
/*<       if(dy.lt.1.or.dy.gt.dpm(mn,lp))then >*/
	if (julian_1.dy < 1 || julian_1.dy > dpm[julian_1.mn + lp * 12 - 13]) 
		{
/* SOURCE fqshrftb.for:998 */
/*<       write(stdout,*)' *ERR:75* Invalid DAY in TABID=',get_tabid(ntab) >*/
	    feq_gen_io_d__117.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__117);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:75* Invalid DAY in TABID="), (ftnlen)
		    31);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, ntab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsle();
/* SOURCE fqshrftb.for:1000 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrftb.for:1001 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1002 */
/*<       if(yr.le.1859)then >*/
	if (julian_1.yr <= 1859) {
/* SOURCE fqshrftb.for:1003 */
/*<       write(stdout,*)' *ERR:76* Invalid YEAR in TABID=',get_tabid(ntab) >*/
	    feq_gen_io_d__118.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__118);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:76* Invalid YEAR in TABID="), (ftnlen)
		    32);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, ntab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsle();
/* SOURCE fqshrftb.for:1005 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrftb.for:1006 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1008 */
/*<       if(hr.gt.24.d0.or.hr.lt.0.d0)then >*/
	if (hr > 24. || hr < 0.) {
/* SOURCE fqshrftb.for:1009 */
/*<       write(stdout,*)' *ERR:119* Invalid HOUR in TABID=',get_tabid(ntab) >*/
	    feq_gen_io_d__119.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__119);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:119* Invalid HOUR in TABID="), (ftnlen)
		    33);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, ntab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsle();
/* SOURCE fqshrftb.for:1011 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrftb.for:1012 */
/*<       endif >*/
	}
/*         CONVERT THE DATE AND TIME TO JULIAN DAY */
/* SOURCE fqshrftb.for:1017 */
/*<       jt=dble(mjd(yr,mn,dy))+hr/24.d0 >*/
	jt = (doublereal) mjd_(&julian_1.yr, &julian_1.mn, &julian_1.dy) + hr 
		/ 24.;
/* SOURCE fqshrftb.for:1019 */
/*<       if(jt.le.bjt)goto1500 >*/
	if (jt <= bjt) {
	    goto L1500;
	}
/* SOURCE fqshrftb.for:1020 */
/*<       bjt=jt >*/
	bjt = jt;
/* SOURCE fqshrftb.for:1021 */
/*<       if(out.eq.1)then >*/
	if (out == 1) {
/* SOURCE fqshrftb.for:1022 */
/*<       write(stdout,51)yr,mn,dy,hr,(f(i),i=1,n) >*/
	    feq_gen_io_d__121.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__121);
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(doublereal));
	    feq_gen_i_d_1 = n;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
		do_fio(&feq_gen_c_d_1, (char *)&f[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* SOURCE fqshrftb.for:1023 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1024 */
/*<       if((ftp+2*(n+1)).ge.mlft)callkil(10,ftp,eflag) >*/
	if (*ftp + (n + 1 << 1) >= *mlft) {
	    kil_(&feq_gen_c_d_10, ftp, eflag);
	}
/* SOURCE fqshrftb.for:1027 */
/*<       dtab(dtp)=jt+shift/86400.d0 >*/
	ftable_1.dtab[dtp] = jt + shift / 86400.;
/* SOURCE fqshrftb.for:1028 */
/*<       if(type.ne.11)then >*/
	if (*feq_gen_type_d_ != 11) {
/* SOURCE fqshrftb.for:1029 */
/*<       doi=1,n >*/
	    feq_gen_i_d_1 = n;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:1030 */
/*<       ftp=ftp+2 >*/
		*ftp += 2;
/* SOURCE fqshrftb.for:1031 */
/*<       dtp=dtp+1 >*/
		++dtp;
/* SOURCE fqshrftb.for:1032 */
/*<       if(i==1)then >*/
		if (feq_gen_i_d_ == 1) {
/* SOURCE fqshrftb.for:1033 */
/*<       dtab(dtp)=f(i)*fac+reflev >*/
		    ftable_1.dtab[dtp] = static_cast<double>(static_cast<double>(f[feq_gen_i_d_ - 1]) * fac) + reflev;
/* SOURCE fqshrftb.for:1034 */
/*<       else >*/
		} else {
/* SOURCE fqshrftb.for:1035 */
/*<       dtab(dtp)=f(i)*fac >*/
		    ftable_1.dtab[dtp] = static_cast<double>(f[feq_gen_i_d_ - 1]) * fac;
/* SOURCE fqshrftb.for:1036 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:1037 */
/*<       enddo >*/
	    }
/* SOURCE fqshrftb.for:1038 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:1039 */
/*<       ftp=ftp+2 >*/
	    *ftp += 2;
/* SOURCE fqshrftb.for:1040 */
/*<       dtp=dtp+1 >*/
	    ++dtp;
/* SOURCE fqshrftb.for:1041 */
/*<       dtab(dtp)=f(1)*fac >*/
	    ftable_1.dtab[dtp] = static_cast<double>(f[0]) * fac;
/* SOURCE fqshrftb.for:1042 */
/*<       ftp=ftp+2 >*/
	    *ftp += 2;
/* SOURCE fqshrftb.for:1043 */
/*<       dtp=dtp+1 >*/
	    ++dtp;
/*           ADJUST THE AZIMUTH TO ACCOUNT FOR THE MANNER OF REFERING */
/*           TO WIND DIRECTION.  WE NEED THE DIRECTION THE WIND IS */
/*           GOING AND NOT THE DIRECTION IT IS COMING FROM. */
/* SOURCE fqshrftb.for:1048 */
/*<       f(2)=f(2)+180.0 >*/
	    f[1] += static_cast<double>((float)180.);
/* SOURCE fqshrftb.for:1049 */
/*<       if(f(2).ge.360.0)f(2)=f(2)-360. >*/
	    if (f[1] >= (float)360.) {
		f[1] += static_cast<double>((float)-360.);
	    }
/* SOURCE fqshrftb.for:1050 */
/*<       dtab(dtp)=f(2)*1.745329e-2 >*/
	    ftable_1.dtab[dtp] = static_cast<double>(f[1]) * (float).01745329;
/* SOURCE fqshrftb.for:1051 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1052 */
/*<       ftp=ftp+2 >*/
	*ftp += 2;
/* SOURCE fqshrftb.for:1053 */
/*<       dtp=dtp+1 >*/
	++dtp;
/* SOURCE fqshrftb.for:1054 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE fqshrftb.for:1056 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1059 */
/*<  1500 continue >*/
L1500:
/*     Set the address of the last point in the table into the first element of */
/*     the table.  Again we must make sure that we use the right pointer! */
/* SOURCE fqshrftb.for:1062 */
/*<       if(argflg==0)then >*/
    if (argflg == 0) {
/*       Table types 2, 3, 4 */
/* SOURCE fqshrftb.for:1064 */
/*<       itab(ftpold)=ftp-n-1 >*/
	itab[ftpold] = *ftp - n - 1;
/* SOURCE fqshrftb.for:1065 */
/*<       else >*/
    } else {
/*       Table types: 7, 8, 9, and 11 */
/* SOURCE fqshrftb.for:1067 */
/*<       itab(ftpold)=dtp-n-1 >*/
	itab[ftpold] = dtp - n - 1;
/* SOURCE fqshrftb.for:1068 */
/*<       endif >*/
    }
/*      write(stdout,*) ' ' */
/*      write(stdout,*) ' ATABIN: exit-- tab address=', ftpold, */
/*     a   ' internal tab number=',itab(ftpold+1),' tab type=', */
/*     b   itab(ftpold+2) */
/* SOURCE fqshrftb.for:1075 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:1077 */
/*<   991 continue >*/
L991:
/* SOURCE fqshrftb.for:1078 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__122.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__122);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE fqshrftb.for:1079 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__123.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__123);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE fqshrftb.for:1080 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1081 */
/*<       end >*/
    return 0;
} /* atabin_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:1085 */
/*<       subroutinechktyp(stdout,adrs,ctype,eflag) >*/
/* Subroutine */ int chktyp_(integer *stdout, integer *adrs, integer *ctype, 
	integer *eflag)
{
    /* Initialized data */

    static integer vrtype[130] = { 36,45,0,0,0,54,48,0,0,96,60,63,0,0,98,0,0,
	    0,0,68,76,83,87,91,94,0,0,0,0,0,0,0,0,0,0,1,12,21,22,24,25,0,0,0,
	    2,3,4,7,8,9,0,0,0,6,13,14,43,0,0,11,0,0,12,22,25,32,0,20,21,22,23,
	    24,25,30,-103,21,22,24,25,1,31,-109,22,25,32,-113,23,24,25,-101,
	    24,25,118,25,-121,10,0,15,0,0,33,-115,31,32,33,34,35,0,32,34,35,0,
	    35,0,34,35,0,34,35,0,35,0,0,0,0,0,0,0,0,0 };

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:174* Table  Id=\002,a,\002 of type\
=\002,i3,\002 invalid in \002,\002current\002,\002 context.\002,/,10x,\002 V\
alid table types are:\002,10i3)";
    static char fmt_56[] = "(\0020*BUG:42* CTYPE=\002,i5,\002 IS INVALID IN \
SUBROUTINE CHKTYP\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer n;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer tab, pnt;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer valid[20], lstval;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__128 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__136 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Given the address of the table and its desired type class, */
/*     check if the type of the table is in the class. */
/* SOURCE fqshrftb.for:1093 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:1095 */
/*<       integeradrs,ctype,eflag,stdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     CTYPE  - type class number for checking valid table types */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     Common blocks */
/* INCLUDE fqshrftb.for:1105 */
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
/* INCLUDE fqshrftb.for:1106 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:1109 */
/*<       integervrtype(130) >*/
/* SOURCE fqshrftb.for:1110 */
/*<       savevrtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:1113 */
/*<       integerj,lstval,n,pnt,tab,type >*/
/* SOURCE fqshrftb.for:1114 */
/*<       integervalid(20) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:1117 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:1120 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:1121 */
/*<       externalget_tabid >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:1124 */
/*<       data(vrtype(j),j=1,10)/36,45,0,0,0,54,48,0,0,96/ >*/
/* SOURCE fqshrftb.for:1125 */
/*<       data(vrtype(j),j=11,20)/60,63,0,0,98,0,0,0,0,68/ >*/
/* SOURCE fqshrftb.for:1126 */
/*<       data(vrtype(j),j=21,30)/76,83,87,91,94,0,0,0,0,0/ >*/
/* SOURCE fqshrftb.for:1127 */
/*<       data(vrtype(j),j=31,40)/0,0,0,0,0,1,12,21,22,24/ >*/
/* SOURCE fqshrftb.for:1128 */
/*<       data(vrtype(j),j=41,50)/25,0,0,0,2,3,4,7,8,9/ >*/
/* SOURCE fqshrftb.for:1129 */
/*<       data(vrtype(j),j=51,60)/0,0,0,6,13,14,43,0,0,11/ >*/
/* SOURCE fqshrftb.for:1130 */
/*<       data(vrtype(j),j=61,70)/0,0,12,22,25,32,0,20,21,22/ >*/
/* SOURCE fqshrftb.for:1131 */
/*<       data(vrtype(j),j=71,80)/23,24,25,30,-103,21,22,24,25,1/ >*/
/* SOURCE fqshrftb.for:1132 */
/*<       data(vrtype(j),j=81,90)/31,-109,22,25,32,-113,23,24,25,-101/ >*/
/* SOURCE fqshrftb.for:1133 */
/*<       data(vrtype(j),j=91,100)/24,25,118,25,-121,10,0,15,0,0/ >*/
/* SOURCE fqshrftb.for:1134 */
/*<       data(vrtype(j),j=101,110)/33,-115,31,32,33,34,35,0,32,34/ >*/
/* SOURCE fqshrftb.for:1135 */
/*<       data(vrtype(j),j=111,120)/35,0,35,0,34,35,0,34,35,0/ >*/
/* SOURCE fqshrftb.for:1136 */
/*<       data(vrtype(j),j=121,130)/35,0,0,0,0,0,0,0,0,0/ >*/
/* SOURCE fqshrftb.for:1139 */
/*<    50  >*/
/* L50: */
/* SOURCE fqshrftb.for:1142 */
/*<    56 format('0*BUG:42* CTYPE=',i5,' IS INVALID IN SUBROUTINE CHKTYP') >*/
/* L56: */
/* *********************************************************************** */
/*     VRTYPE contains either a zero or an index value in its */
/*     first 35 locations.  These are set aside for indexing by the */
/*     expected range of table types.  A zero value at the table type */
/*     location indicates an invalid desired type.  This does not mean */
/*     that the table type is invalid; just that CHKTYP does not now */
/*     expect that that type will appear as representative of a class */
/*     of tables.  A non-zero value points to a subsequent location */
/*     in VRTYPE containing a consecutive list of the types that */
/*     are valid for the expected type class.  Each list is terminated */
/*     by a 0 value.  A negative value is a continuation index to */
/*     allow for expansion of any type class without having to */
/*     change the existing values. */
/*     CONTENTS OF VRTYPE(*,*) */
/*  INDEX VRTYPE  INDEX VRTYPE  INDEX VRTYPE  INDEX VRTYPE  INDEX VRTYPE */
/*      1     36     31      0     61      0     91     24    121     35 */
/*      2     45     32      0     62      0     92     25    122      0 */
/*      3      0     33      0     63     12     93   -118    123 */
/*      4      0     34      0     64     22     94     25    124 */
/*      5      0     35      0     65     25     95   -121    125 */
/*      6     54     36      1     66     32     96     10    126 */
/*      7     48     37     12     67      0     97      0    127 */
/*      8      0     38     21     68     20     98     15    128 */
/*      9      0     39     22     69     21     99      0    129 */
/*     10     96     40     24     70     22    100      0    130 */
/*     11     60     41     25     71     23    101     33 */
/*     12     63     42      0     72     24    102   -115 */
/*     13      0     43      0     73     25    103     31 */
/*     14      0     44      0     74     30    104     32 */
/*     15     98     45      2     75   -103    105     33 */
/*     16      0     46      3     76     21    106     34 */
/*     17      0     47      4     77     22    107     35 */
/*     18      0     48      7     78     24    108      0 */
/*     19      0     49      8     79     25    109     32 */
/*     20     68     50      9     80      1    110     34 */
/*     21     76     51      0     81     31    111     35 */
/*     22     83     52      0     82   -109    112      0 */
/*     23     87     53      0     83     22    113     35 */
/*     24     91     54      6     84     25    114      0 */
/*     25     94     55     13     85     32    115     34 */
/*     26      0     56     14     86   -113    116     35 */
/*     27      0     57     43     87     23    117      0 */
/*     28      0     58      0     88     24    118     34 */
/*     29      0     59      0     89     25    119     35 */
/*     30      0     60     11     90   -101    120      0 */
/* SOURCE fqshrftb.for:1191 */
/*<       if(ctype.lt.1.or.ctype.gt.35)then >*/
    if (*ctype < 1 || *ctype > 35) {
/* SOURCE fqshrftb.for:1192 */
/*<       write(stdout,56)ctype >*/
	feq_gen_io_d__128.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__128);
	do_fio(&feq_gen_c_d_1, (char *)&(*ctype), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:1193 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1194 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:1195 */
/*<       pnt=vrtype(ctype) >*/
	pnt = vrtype[*ctype - 1];
/* SOURCE fqshrftb.for:1196 */
/*<       if(pnt.eq.0)then >*/
	if (pnt == 0) {
/* SOURCE fqshrftb.for:1197 */
/*<       write(stdout,56)ctype >*/
	    feq_gen_io_d__130.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__130);
	    do_fio(&feq_gen_c_d_1, (char *)&(*ctype), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE fqshrftb.for:1198 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1199 */
/*<       else >*/
	} else {
/*         WE HAVE A VALID TYPE GROUPING.  GET THE TYPE OF THE */
/*         TABLE BEING CHECKED AND SEEK IT IN THE LIST.  ALL TABLES */
/*         MUST HAVE THEIR TYPE AT OFFSET +2. */
/* SOURCE fqshrftb.for:1204 */
/*<       type=itab(adrs+2) >*/
	    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:1205 */
/*<       tab=itab(adrs+1) >*/
	    tab = itab[*adrs + 1];
/*         CLEAR THE COUNT OF VALID TYPES ENCOUNTERED */
/* SOURCE fqshrftb.for:1208 */
/*<       n=0 >*/
	    n = 0;
/* SOURCE fqshrftb.for:1210 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:1211 */
/*<       lstval=vrtype(pnt) >*/
	    lstval = vrtype[pnt - 1];
/* SOURCE fqshrftb.for:1212 */
/*<       if(lstval.gt.0)then >*/
	    if (lstval > 0) {
/*             FOUND A TYPE TO CHECK AGAINST. PUT IT ON THE LIST. */
/*             FOR ERROR REPORTING IF NEEDED. */
/* SOURCE fqshrftb.for:1215 */
/*<       n=n+1 >*/
		++n;
/* SOURCE fqshrftb.for:1216 */
/*<       valid(n)=lstval >*/
		valid[n - 1] = lstval;
/* SOURCE fqshrftb.for:1218 */
/*<       if(type.eq.lstval)then >*/
		if (feq_gen_type_d_ == lstval) {
/* SOURCE fqshrftb.for:1219 */
/*<       return >*/
		    return 0;
/* SOURCE fqshrftb.for:1220 */
/*<       else >*/
		} else {
/*               INCREMENT TO THE NEXT LOCATION */
/* SOURCE fqshrftb.for:1222 */
/*<       pnt=pnt+1 >*/
		    ++pnt;
/* SOURCE fqshrftb.for:1223 */
/*<       goto100 >*/
		    goto L100;
/* SOURCE fqshrftb.for:1224 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:1225 */
/*<       elseif(lstval.lt.0)then >*/
	    } else if (lstval < 0) {
/*             RESET THE POINTER TO CONTINUE WITH THE CURRENT LIST */
/* SOURCE fqshrftb.for:1227 */
/*<       pnt=abs(lstval) >*/
		pnt = abs(lstval);
/* SOURCE fqshrftb.for:1228 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:1229 */
/*<       endif >*/
	    }
/*           NO MATCH FOUND. */
/* SOURCE fqshrftb.for:1232 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrftb.for:1233 */
/*<       write(stdout,50)get_tabid(tab),type,(valid(pnt),pnt=1,n) >*/
	    feq_gen_io_d__136.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__136);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	    feq_gen_i_d_1 = n;
	    for (pnt = 1; pnt <= feq_gen_i_d_1; ++pnt) {
		do_fio(&feq_gen_c_d_1, (char *)&valid[pnt - 1], (ftnlen)sizeof(integer)
			);
	    }
	    e_wsfe();
/* SOURCE fqshrftb.for:1234 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrftb.for:1235 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1236 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1237 */
/*<       end >*/
    return 0;
} /* chktyp_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:1241 */
/*<       realfunctionfmxarg(adrs) >*/
doublereal fmxarg_(integer *adrs)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:46* FMXARG INVALID WITH 2-D TABLE. TA\
B#=\002,i5,\002 IS A 2-D TABLE.\002)";

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
    static cilist feq_gen_io_d__141 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the maximum argument for the table stored at ADRS. */
/* SOURCE fqshrftb.for:1247 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:1249 */
/*<       integeradrs >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:1255 */
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
/* INCLUDE fqshrftb.for:1256 */
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
/* INCLUDE fqshrftb.for:1257 */
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
/* SOURCE fqshrftb.for:1260 */
/*<       integertype >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE fqshrftb.for:1263 */
/*<       integergettbn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:1266 */
/*<       externalgettbn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:1269 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:1272 */
/*<       type=itab(adrs+2) >*/
/* L50: */
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:1273 */
/*<        >*/
    if (feq_gen_type_d_ == 5 || feq_gen_type_d_ == 6 || feq_gen_type_d_ == 10 || feq_gen_type_d_ == 13 || feq_gen_type_d_ 
	    == 14 || feq_gen_type_d_ == 15) {
/* SOURCE fqshrftb.for:1275 */
/*<       write(std6,50)gettbn(adrs) >*/
	feq_gen_io_d__141.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__141);
	feq_gen_i_d_1 = gettbn_(adrs);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:1276 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1277 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:1278 */
/*<       fmxarg=ftab(itab(adrs)) >*/
	ret_val = ftab[itab[*adrs]];
/* SOURCE fqshrftb.for:1279 */
/*<       return >*/
	return ret_val;
/* SOURCE fqshrftb.for:1280 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1281 */
/*<       end >*/
    return ret_val;
} /* fmxarg_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:1285 */
/*<       subroutinefndsta(num,stdout,eflag,x) >*/
/* Subroutine */ int fndsta_(integer *num, integer *stdout, integer *eflag, 
	real *x)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:197* Cross sec. table Id= \002,a\
,\002 not found for\002,\002 station.\002)";
    static char fmt_52[] = "(/,\002 *BUG:XXX* NUM < 0 in sub. FNDSTA\002)";

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
    static cilist feq_gen_io_d__145 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the station of the cross section from the table */
/*     given by the table number in NUM. */
/* SOURCE fqshrftb.for:1293 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:1295 */
/*<       integereflag,stdout,num >*/
/* SOURCE fqshrftb.for:1296 */
/*<       realx >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NUM    - table number */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     X      - station value */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:1305 */
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
/* INCLUDE fqshrftb.for:1306 */
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
/* SOURCE fqshrftb.for:1309 */
/*<       characterget_tabid*16 >*/
/* SOURCE fqshrftb.for:1310 */
/*<       externalget_tabid >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:1313 */
/*<       integeradrs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:1316 */
/*<    50  >*/
/* SOURCE fqshrftb.for:1318 */
/*<    52 format(/,' *BUG:XXX* NUM < 0 in sub. FNDSTA') >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:1320 */
/*<       if(num.le.0)then >*/
/* L50: */
/* L52: */
    if (*num <= 0) {
/* SOURCE fqshrftb.for:1321 */
/*<       write(stdout,52)num >*/
	feq_gen_io_d__145.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__145);
	do_fio(&feq_gen_c_d_1, (char *)&(*num), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:1322 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE fqshrftb.for:1323 */
/*<       x=0.0 >*/
	*x = (float)0.;
/* SOURCE fqshrftb.for:1324 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:1325 */
/*<       adrs=ftpnt(num) >*/
	adrs = ftablea_1.ftpnt[*num - 1];
/* SOURCE fqshrftb.for:1326 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/* SOURCE fqshrftb.for:1327 */
/*<       x=ftab(adrs+4) >*/
	    *x = ftab[adrs + 4];
/* SOURCE fqshrftb.for:1328 */
/*<       else >*/
	} else {
/*         TABLE DOES NOT EXIST */
/* SOURCE fqshrftb.for:1331 */
/*<       write(stdout,50)get_tabid(num) >*/
	    feq_gen_io_d__147.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__147);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, num);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE fqshrftb.for:1332 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrftb.for:1333 */
/*<       x=0.0 >*/
	    *x = (float)0.;
/* SOURCE fqshrftb.for:1334 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1335 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1336 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:1337 */
/*<       end >*/
} /* fndsta_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:1341 */
/*<       subroutineget_next_tabid(stdout,linea,eflag,tabid,table,nxtnam) >*/
/* Subroutine */ int feq_gen_get_next_tabid_d_(integer *stdout, char *linea, integer *
	eflag, char *tabid, integer *table, char *nxtnam, ftnlen linea_len, 
	ftnlen tabid_len, ftnlen nxtnam_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:735* Expected line with a TABID=, F\
ILE=,\002,\002 or HOME= but found:\002,/,5x,a)";
    static char fmt_52[] = "(/,\002 *ERR:736* No = found as expected in inpu\
t line:\002,/,a)";
    static char fmt_54[] = "(/,\002 *ERR:737* No file name found following F\
ILE=\002)";
    static char fmt_56[] = "(/,\002 *ERR:738* No table id found following TA\
BID or TABLE#\002)";
    static char fmt_58[] = "(/,\002 *WRN:58* No home name found following HO\
ME=. \002,\002 Home name cleared.\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer it, nxt;
    char line[196];
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen), 
	    feq_gen_maybe_add_home_d_(char *, ftnlen), nxttok_(char *, integer *, char 
	    *, ftnlen, ftnlen), feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_56, 0 };


/*     Get the next table id and the optional NXTNAM from LINE. */
/* SOURCE fqshrftb.for:1346 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:1347 */
/*<       integereflag,stdout,table >*/
/* SOURCE fqshrftb.for:1348 */
/*<       characterlinea*(*),tabid*16,nxtnam*(*) >*/
/* INCLUDE fqshrftb.for:1350 */
/*     Values of local and global home directory names */
/* 	7 dec 2005:  Add an output extension value */
/* SOURCE home.cmn:3 */
/*<       character*128stdext >*/
/* SOURCE home.cmn:4 */
/*<       character*128home,ghome,ghome_out >*/
/* SOURCE home.cmn:5 */
/*<       common/homec/home,ghome,ghome_out,stdext >*/
/* SOURCE home.cmn:6 */
/*<       save/homec/ >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:1353 */
/*<       externalstrip_l_blanks,maybe_add_home,os_file_style >*/
/*     Local */
/* SOURCE fqshrftb.for:1357 */
/*<       integerit,nxt,n >*/
/* SOURCE fqshrftb.for:1358 */
/*<       characterline*196,temp_line*196 >*/
/*     *****************************FORMATS****************************** */
/* SOURCE fqshrftb.for:1360 */
/*<    50  >*/
/* SOURCE fqshrftb.for:1362 */
/*<    52 format(/,' *ERR:736* No = found as expected in input line:',/,a) >*/
/* SOURCE fqshrftb.for:1363 */
/*<    54 format(/,' *ERR:737* No file name found following FILE=') >*/
/* SOURCE fqshrftb.for:1364 */
/*<    56 format(/,' *ERR:738* No table id found following TABID or TABLE#') >*/
/* SOURCE fqshrftb.for:1365 */
/*<    58  >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:1368 */
/*<       line=linea >*/
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
    s_copy(line, linea, (ftnlen)196, linea_len);
/*     Get the name field for the table id.  Do a search for */
/*     the equal sign because some table ids might have no intervening */
/*     space after the equal. */
/* SOURCE fqshrftb.for:1373 */
/*<       callstrip_l_blanks(line) >*/
    feq_gen_strip_l_blanks_d_(line, (ftnlen)196);
/* SOURCE fqshrftb.for:1375 */
/*<        >*/
    if (s_cmp(line, const_cast<char*>("TAB"), (ftnlen)3, (ftnlen)3) != 0 && s_cmp(line, const_cast<char*>("Tab"), (
	    ftnlen)3, (ftnlen)3) != 0 && s_cmp(line, const_cast<char*>("FILE"), (ftnlen)4, (
	    ftnlen)4) != 0 && s_cmp(line, const_cast<char*>("File"), (ftnlen)4, (ftnlen)4) != 0 
	    && s_cmp(line, const_cast<char*>("HOME"), (ftnlen)4, (ftnlen)4) != 0 && s_cmp(line, 
	    const_cast<char*>("Home"), (ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE fqshrftb.for:1378 */
/*<       write(stdout,50)line >*/
	feq_gen_io_d__149.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__149);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)196);
	e_wsfe();
/* SOURCE fqshrftb.for:1379 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1380 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1381 */
/*<       it=index(line,'=') >*/
    it = i_indx(line, const_cast<char*>("="), (ftnlen)196, (ftnlen)1);
/* SOURCE fqshrftb.for:1382 */
/*<       if(it.eq.0)then >*/
    if (it == 0) {
/* SOURCE fqshrftb.for:1383 */
/*<       write(stdout,52)line >*/
	feq_gen_io_d__151.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__151);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)196);
	e_wsfe();
/* SOURCE fqshrftb.for:1384 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1385 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1386 */
/*<       if(line(1:4).eq.'FILE'.or.line(1:4).eq.'File')then >*/
    if (s_cmp(line, const_cast<char*>("FILE"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(line, const_cast<char*>("File"), 
	    (ftnlen)4, (ftnlen)4) == 0) {
/*       We have a file name given.  No TabId given. */
/* SOURCE fqshrftb.for:1388 */
/*<       nxt=it+1 >*/
	nxt = it + 1;
/* SOURCE fqshrftb.for:1389 */
/*<       callnxttok(line,nxt,nxtnam) >*/
	nxttok_(line, &nxt, nxtnam, (ftnlen)196, nxtnam_len);
/* SOURCE fqshrftb.for:1393 */
/*<       if(nxt.le.0)then >*/
	if (nxt <= 0) {
/* SOURCE fqshrftb.for:1394 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__153.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__153);
	    e_wsfe();
/* SOURCE fqshrftb.for:1395 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1396 */
/*<       endif >*/
	}
/*       Set signal that a file name was found */
/* SOURCE fqshrftb.for:1398 */
/*<       table=-15 >*/
	*table = -15;
/* SOURCE fqshrftb.for:1399 */
/*<       tabid=' ' >*/
	s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/*       Add the prefix of HOME here if conditions are right. */
/* SOURCE fqshrftb.for:1401 */
/*<       callmaybe_add_home(nxtnam) >*/
	feq_gen_maybe_add_home_d_(nxtnam, nxtnam_len);
/* SOURCE fqshrftb.for:1403 */
/*<       callos_file_style(nxtnam) >*/
	feq_gen_os_file_style_d_(nxtnam, nxtnam_len);
/* SOURCE fqshrftb.for:1405 */
/*<       elseif(line(1:4).eq.'HOME'.or.line(1:4).eq.'Home')then >*/
    } else if (s_cmp(line, const_cast<char*>("HOME"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(line, 
	    const_cast<char*>("Home"), (ftnlen)4, (ftnlen)4) == 0) {
/*       We have a home name given.  No TabId given. */
/* SOURCE fqshrftb.for:1407 */
/*<       nxt=it+1 >*/
	nxt = it + 1;
/* SOURCE fqshrftb.for:1408 */
/*<       callnxttok(line,nxt,nxtnam) >*/
	nxttok_(line, &nxt, nxtnam, (ftnlen)196, nxtnam_len);
/* SOURCE fqshrftb.for:1412 */
/*<       if(nxt.le.0)then >*/
	if (nxt <= 0) {
/* SOURCE fqshrftb.for:1413 */
/*<       write(stdout,58) >*/
	    feq_gen_io_d__154.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__154);
	    e_wsfe();
/* SOURCE fqshrftb.for:1414 */
/*<       nxtnam=' ' >*/
	    s_copy(nxtnam, const_cast<char*>(" "), nxtnam_len, (ftnlen)1);
/*          STOP 'Abnormal stop: errors found.' */
/* SOURCE fqshrftb.for:1416 */
/*<       endif >*/
	}
/*       Set signal that a home name was found */
/* SOURCE fqshrftb.for:1418 */
/*<       home=nxtnam >*/
	s_copy(homec_1.home, nxtnam, (ftnlen)128, nxtnam_len);
/* SOURCE fqshrftb.for:1419 */
/*<       callstrip_l_blanks(home) >*/
	feq_gen_strip_l_blanks_d_(homec_1.home, (ftnlen)128);
/* SOURCE fqshrftb.for:1421 */
/*<       table=-16 >*/
	*table = -16;
/* SOURCE fqshrftb.for:1422 */
/*<       tabid=' ' >*/
	s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE fqshrftb.for:1423 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:1424 */
/*<       nxt=it+1 >*/
	nxt = it + 1;
/*       Get the TABID field */
/* SOURCE fqshrftb.for:1426 */
/*<       callnxttok(line,nxt,tabid) >*/
	nxttok_(line, &nxt, tabid, (ftnlen)196, (ftnlen)16);
/* SOURCE fqshrftb.for:1431 */
/*<       if(nxt.le.0)then >*/
	if (nxt <= 0) {
/* SOURCE fqshrftb.for:1432 */
/*<       write(stdout,56) >*/
	    feq_gen_io_d__155.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__155);
	    e_wsfe();
/* SOURCE fqshrftb.for:1433 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1434 */
/*<       endif >*/
	}
/*       Get the optional file name.  If nothing found, NXTNAM is */
/*       returned with blanks. */
/* SOURCE fqshrftb.for:1437 */
/*<       callnxttok(line,nxt,nxtnam) >*/
	nxttok_(line, &nxt, nxtnam, (ftnlen)196, nxtnam_len);
/* SOURCE fqshrftb.for:1442 */
/*<       if(nxt.gt.0)then >*/
	if (nxt > 0) {
/*         Check if a comment was found. */
/* SOURCE fqshrftb.for:1444 */
/*<       if(nxtnam(1:1).eq.'''')then >*/
	    if (*(unsigned char *)nxtnam == '\'') {
/*           Clear the the value */
/* SOURCE fqshrftb.for:1446 */
/*<       nxtnam=' ' >*/
		s_copy(nxtnam, const_cast<char*>(" "), nxtnam_len, (ftnlen)1);
/* SOURCE fqshrftb.for:1447 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:1448 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1449 */
/*<       if(nxtnam.eq.' ')then >*/
	if (s_cmp(nxtnam, const_cast<char*>(" "), nxtnam_len, (ftnlen)1) == 0) {
/* SOURCE fqshrftb.for:1450 */
/*<       if(tabid(1:1).eq.'-')then >*/
	    if (*(unsigned char *)tabid == '-') {
/*           Signal end of the Function-Table Block */
/* SOURCE fqshrftb.for:1452 */
/*<       table=-1 >*/
		*table = -1;
/* SOURCE fqshrftb.for:1453 */
/*<       else >*/
	    } else {
/*           Convert TABID to an internal number */
/* SOURCE fqshrftb.for:1455 */
/*<       callget_internal_tab_number(stdout,tabid,eflag,table) >*/
		feq_gen_get_internal_tab_number_d_(stdout, tabid, eflag, table, (
			ftnlen)16);
/* SOURCE fqshrftb.for:1459 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:1460 */
/*<       else >*/
	} else {
/*         Signal another file name to process */
/* SOURCE fqshrftb.for:1462 */
/*<       table=-15 >*/
	    *table = -15;
/* SOURCE fqshrftb.for:1463 */
/*<       tabid=' ' >*/
	    s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE fqshrftb.for:1464 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1465 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1466 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:1467 */
/*<       end >*/
} /* get_next_tabid__ */




/* SOURCE fqshrftb.for:1471 */
/*<       subroutineqsrt_alpha_plus_pointer(a,ap,n) >*/
/* Subroutine */ int feq_gen_qsrt_alpha_plus_pointer_d_(char *feq_storage_a, integer *feq_storage_ap, integer *
	n, ftnlen a_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, k, m, p, q;
    char t[16], x[16];
    integer lt[19], tp, xp, ut[19];

/*     Use quicker sort to sort the character array, a, into whatever */
/*     order Fortran happens to take.  Move the elements of the pointer */
/*     array, ap, at the same time, N is the number of elements in */
/*     each.  Based on QSORTA-obtained from a collegue more than 30 */
/*     years ago! */
/* SOURCE fqshrftb.for:1479 */
/*<       implicitnone >*/

/* SOURCE fqshrftb.for:1481 */
/*<       integern >*/
/* SOURCE fqshrftb.for:1482 */
/*<       character*16a(n),t,x >*/
/* SOURCE fqshrftb.for:1483 */
/*<       integerap(n),tp,xp >*/
/*       THE DIMENSIONS FOR LT AND UT HAVE TO BE AT LEAST LOG  N. */
/*                                                           2 */
/*        WAS CHOSEN TO HANDLE N <524288. */
/* SOURCE fqshrftb.for:1488 */
/*<       integerlt(19),ut(19),i,j,k,m,p,q >*/
/* *********************************************************************** */

/* SOURCE fqshrftb.for:1491 */
/*<       j=n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ap(feq_storage_ap, 1);

    feq::IndexedPointer<char> a(feq_storage_a, 16);

    /* Function Body */
    j = *n;
/* SOURCE fqshrftb.for:1492 */
/*<       m=1 >*/
    m = 1;
/* SOURCE fqshrftb.for:1493 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;

/*       IF THIS SEGMENT HAS MORE THAN TWO ELEMENTS  WE SPLIT IT */
/* SOURCE fqshrftb.for:1496 */
/*<    10 continue >*/
L10:
/* SOURCE fqshrftb.for:1497 */
/*<       if(j-i-1)100,90,15 >*/
    if ((feq_gen_i_d_1 = j - feq_gen_i_d_ - 1) < 0) {
	goto L100;
    } else if (feq_gen_i_d_1 == 0) {
	goto L90;
    } else {
	goto L15;
    }

/*       P IS THE POSITION OF AN ARBITRARY ELEMENT IN THE SEGMENT */
/*       WE CHOOSE THE MIDDLE ELEMENT. UNDER CERTAIN CIRCUMSTANCES */
/*       IT MAY BE ADVANTAGEOUS TO CHOOSE P AT RANDOM. */
/* SOURCE fqshrftb.for:1502 */
/*<    15 continue >*/
L15:
/* SOURCE fqshrftb.for:1503 */
/*<       p=(j+i)/2 >*/
    p = (j + feq_gen_i_d_) / 2;
/* SOURCE fqshrftb.for:1504 */
/*<       t=a(p) >*/
    s_copy(t, a + (p << 4), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1505 */
/*<       tp=ap(p) >*/
    tp = ap[p];
/* SOURCE fqshrftb.for:1506 */
/*<       a(p)=a(i) >*/
    s_copy(a + (p << 4), a + (feq_gen_i_d_ << 4), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1507 */
/*<       ap(p)=ap(i) >*/
    ap[p] = ap[feq_gen_i_d_];

/*       STARTING AT THE BEGINNING OF THE SEGMENT, SEARCH FOR K */
/*       SUCH THAT A(K)>T */
/* SOURCE fqshrftb.for:1511 */
/*<       q=j >*/
    q = j;
/* SOURCE fqshrftb.for:1512 */
/*<       k=i >*/
    k = feq_gen_i_d_;
/* SOURCE fqshrftb.for:1513 */
/*<    20 continue >*/
L20:
/* SOURCE fqshrftb.for:1514 */
/*<       k=k+1 >*/
    ++k;
/* SOURCE fqshrftb.for:1515 */
/*<       if(k.gt.q)goto60 >*/
    if (k > q) {
	goto L60;
    }
/* SOURCE fqshrftb.for:1516 */
/*<       if(a(k).le.t)goto20 >*/
    if (s_cmp(a + (k << 4), t, (ftnlen)16, (ftnlen)16) <= 0) {
	goto L20;
    }

/*        SUCH AN ELEMENT HAS NOW BEEN FOUND */
/*        NOW SEARCH FOR A Q SUCH THAT A(Q)<T STARTING AT THE END OF THE */
/*        SEGMENT. */
/* SOURCE fqshrftb.for:1521 */
/*<    30 continue >*/
L30:
/* SOURCE fqshrftb.for:1522 */
/*<       if(a(q).lt.t)goto40 >*/
    if (s_cmp(a + (q << 4), t, (ftnlen)16, (ftnlen)16) < 0) {
	goto L40;
    }
/* SOURCE fqshrftb.for:1523 */
/*<       q=q-1 >*/
    --q;
/* SOURCE fqshrftb.for:1524 */
/*<       if(q.gt.k)goto30 >*/
    if (q > k) {
	goto L30;
    }
/* SOURCE fqshrftb.for:1525 */
/*<       goto50 >*/
    goto L50;

/*        A(Q) HAS NOW BEEN FOUND. WE INTERCHANGE A(Q) AND A(K) */
/* SOURCE fqshrftb.for:1528 */
/*<    40 continue >*/
L40:
/* SOURCE fqshrftb.for:1529 */
/*<       x=a(k) >*/
    s_copy(x, a + (k << 4), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1530 */
/*<       a(k)=a(q) >*/
    s_copy(a + (k << 4), a + (q << 4), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1531 */
/*<       a(q)=x >*/
    s_copy(a + (q << 4), x, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1533 */
/*<       xp=ap(k) >*/
    xp = ap[k];
/* SOURCE fqshrftb.for:1534 */
/*<       ap(k)=ap(q) >*/
    ap[k] = ap[q];
/* SOURCE fqshrftb.for:1535 */
/*<       ap(q)=xp >*/
    ap[q] = xp;

/*        UPDATE Q AND SEARCH FOR ANOTHER PAIR TO INTERCHANGE */
/* SOURCE fqshrftb.for:1539 */
/*<       q=q-1 >*/
    --q;
/* SOURCE fqshrftb.for:1540 */
/*<       goto20 >*/
    goto L20;
/* SOURCE fqshrftb.for:1541 */
/*<    50 continue >*/
L50:
/* SOURCE fqshrftb.for:1542 */
/*<       q=k-1 >*/
    q = k - 1;
/* SOURCE fqshrftb.for:1543 */
/*<    60 continue >*/
L60:

/*        THE UPWARDS SEARCH HAS NOW MET THE DOWNWARDS SEARCH */
/* SOURCE fqshrftb.for:1546 */
/*<       a(i)=a(q) >*/
    s_copy(a + (feq_gen_i_d_ << 4), a + (q << 4), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1547 */
/*<       a(q)=t >*/
    s_copy(a + (q << 4), t, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1549 */
/*<       ap(i)=ap(q) >*/
    ap[feq_gen_i_d_] = ap[q];
/* SOURCE fqshrftb.for:1550 */
/*<       ap(q)=tp >*/
    ap[q] = tp;

/*       THE SEGMENT IS NOW DIVIDED IN THREE PARTS: (I,Q-1),(Q),(Q+1,J) */
/*       STORE THE POSITION OF THE LARGEST SEGMENT IN LT AND UT */
/* SOURCE fqshrftb.for:1555 */
/*<       if(2*q.le.i+j)goto70 >*/
    if (q << 1 <= feq_gen_i_d_ + j) {
	goto L70;
    }
/* SOURCE fqshrftb.for:1556 */
/*<       lt(m)=i >*/
    lt[m - 1] = feq_gen_i_d_;
/* SOURCE fqshrftb.for:1557 */
/*<       ut(m)=q-1 >*/
    ut[m - 1] = q - 1;
/* SOURCE fqshrftb.for:1558 */
/*<       i=q+1 >*/
    feq_gen_i_d_ = q + 1;
/* SOURCE fqshrftb.for:1559 */
/*<       goto80 >*/
    goto L80;
/* SOURCE fqshrftb.for:1560 */
/*<    70 continue >*/
L70:
/* SOURCE fqshrftb.for:1561 */
/*<       lt(m)=q+1 >*/
    lt[m - 1] = q + 1;
/* SOURCE fqshrftb.for:1562 */
/*<       ut(m)=j >*/
    ut[m - 1] = j;
/* SOURCE fqshrftb.for:1563 */
/*<       j=q-1 >*/
    j = q - 1;

/*       UPDATE M AND SPLIT THE NEW SMALLER SEGMENT */
/* SOURCE fqshrftb.for:1566 */
/*<    80 continue >*/
L80:
/* SOURCE fqshrftb.for:1567 */
/*<       m=m+1 >*/
    ++m;
/* SOURCE fqshrftb.for:1568 */
/*<       goto10 >*/
    goto L10;

/*       WE ARRIVE HERE IF THE SEGMENT HAS  TWO ELEMENTS */
/*       WE TEST TO SEE IF THE SEGMENT IS PROPERLY ORDERED */
/*       IF NOT, WE PERFORM AN INTERCHANGE */
/* SOURCE fqshrftb.for:1573 */
/*<    90 continue >*/
L90:
/* SOURCE fqshrftb.for:1574 */
/*<       if(a(i).le.a(j))goto100 >*/
    if (s_cmp(a + (feq_gen_i_d_ << 4), a + (j << 4), (ftnlen)16, (ftnlen)16) <= 0) {
	goto L100;
    }
/* SOURCE fqshrftb.for:1575 */
/*<       x=a(i) >*/
    s_copy(x, a + (feq_gen_i_d_ << 4), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1576 */
/*<       a(i)=a(j) >*/
    s_copy(a + (feq_gen_i_d_ << 4), a + (j << 4), (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1577 */
/*<       a(j)=x >*/
    s_copy(a + (j << 4), x, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1579 */
/*<       xp=ap(i) >*/
    xp = ap[feq_gen_i_d_];
/* SOURCE fqshrftb.for:1580 */
/*<       ap(i)=ap(j) >*/
    ap[feq_gen_i_d_] = ap[j];
/* SOURCE fqshrftb.for:1581 */
/*<       ap(j)=xp >*/
    ap[j] = xp;

/*       IF LT AND UT CONTAIN MORE SEGMENTS TO BE SORTED REPEAT PROCESS */
/* SOURCE fqshrftb.for:1585 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:1586 */
/*<       m=m-1 >*/
    --m;
/* SOURCE fqshrftb.for:1587 */
/*<       if(m.le.0)return >*/
    if (m <= 0) {
	return 0;
    }
/* SOURCE fqshrftb.for:1588 */
/*<       i=lt(m) >*/
    feq_gen_i_d_ = lt[m - 1];
/* SOURCE fqshrftb.for:1589 */
/*<       j=ut(m) >*/
    j = ut[m - 1];
/* SOURCE fqshrftb.for:1590 */
/*<       goto10 >*/
    goto L10;
/* SOURCE fqshrftb.for:1591 */
/*<       end >*/
} /* qsrt_alpha_plus_pointer__ */




/* SOURCE fqshrftb.for:1597 */
/*<       subroutineoutput_ftab_index(stdout) >*/
/* Subroutine */ int feq_gen_output_ftab_index_d_(integer *stdout)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 FEQ found \002,i5,\002 tables for the fu\
nction-table index.\002)";
    static char fmt_52[] = "(\002 Function-table index for the current scena\
rio.\002)";
    static char fmt_54[] = "(\002TABID\002,11x,1x,\002 Type\002,2x,\002File \
name for the table\002)";
    static char fmt_56[] = "(a16,1x,i5,2x,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_qsrt_alpha_plus_pointer_d_(char *, integer *, 
	    integer *, ftnlen);
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__168 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__170 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__173 = { 0, 0, 0, fmt_56, 0 };


/*     Sort and output function-table information to create an index to */
/*     the file names for each function table id */
/* SOURCE fqshrftb.for:1602 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:1604 */
/*<       integerstdout >*/
/* INCLUDE fqshrftb.for:1606 */
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
/* INCLUDE fqshrftb.for:1607 */
/* SOURCE maketabindex.cmn:2 */
/*<       character*4make_tab_index >*/
/* SOURCE maketabindex.cmn:4 */
/*<       integerftab_type(mftnum),data_pnt(mftnum),index_knt,stdindex >*/
/* SOURCE maketabindex.cmn:7 */
/*<       characterftabid(mftnum)*16,ftab_fn(mftnum)*256 >*/
/* SOURCE maketabindex.cmn:9 */
/*<       common/mktbindxc/ftab_fn,ftabid,make_tab_index >*/
/* SOURCE maketabindex.cmn:10 */
/*<       common/mktbindx/ftab_type,data_pnt,index_knt,stdindex >*/
/*     Local */
/* SOURCE fqshrftb.for:1611 */
/*<       integeri >*/
/*     ********************formats*************************************** */
/* SOURCE fqshrftb.for:1597 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrftb.for:1597 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrftb.for:1614 */
/*<    50 format(/,' FEQ found ',i5,' tables for the function-table index.') >*/
/* SOURCE fqshrftb.for:1615 */
/*<    52 format(' Function-table index for the current scenario.') >*/
/* SOURCE fqshrftb.for:1616 */
/*<    54 format('TABID',11x,1x,' Type',2x,'File name for the table') >*/
/* SOURCE fqshrftb.for:1617 */
/*<    56 format(a16,1x,i5,2x,a) >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:1619 */
/*<       write(stdout,50)index_knt >*/
/* L50: */
/* L52: */
/* L54: */
/* L56: */
    feq_gen_io_d__168.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__168);
    do_fio(&feq_gen_c_d_1, (char *)&mktbindx_1.feq_gen_index_knt_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE fqshrftb.for:1621 */
/*<       write(stdindex,52) >*/
    feq_gen_io_d__169.ciunit = mktbindx_1.stdindex;
    s_wsfe(&feq_gen_io_d__169);
    e_wsfe();
/* SOURCE fqshrftb.for:1622 */
/*<       write(stdindex,50)index_knt >*/
    feq_gen_io_d__170.ciunit = mktbindx_1.stdindex;
    s_wsfe(&feq_gen_io_d__170);
    do_fio(&feq_gen_c_d_1, (char *)&mktbindx_1.feq_gen_index_knt_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE fqshrftb.for:1623 */
/*<       write(stdindex,54) >*/
    feq_gen_io_d__171.ciunit = mktbindx_1.stdindex;
    s_wsfe(&feq_gen_io_d__171);
    e_wsfe();
/*     Sort the tabids. */
/* SOURCE fqshrftb.for:1626 */
/*<       callqsrt_alpha_plus_pointer(ftabid,data_pnt,index_knt) >*/
    feq_gen_qsrt_alpha_plus_pointer_d_(mktbindxc_1.ftabid, mktbindx_1.feq_gen_data_pnt_d_, &
	    mktbindx_1.feq_gen_index_knt_d_, (ftnlen)16);
/* SOURCE fqshrftb.for:1627 */
/*<       doi=1,index_knt >*/
    feq_gen_i_d_1 = mktbindx_1.feq_gen_index_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:1628 */
/*<        >*/
	feq_gen_io_d__173.ciunit = mktbindx_1.stdindex;
	s_wsfe(&feq_gen_io_d__173);
	do_fio(&feq_gen_c_d_1, mktbindxc_1.ftabid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&mktbindx_1.feq_gen_ftab_type_d_[mktbindx_1.feq_gen_data_pnt_d_[
		feq_gen_i_d_ - 1] - 1], (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, mktbindxc_1.feq_gen_ftab_fn_d_ + (mktbindx_1.feq_gen_data_pnt_d_[feq_gen_i_d_ - 1] 
		- 1 << 8), feq_gen_feq_len_trim_d_(mktbindxc_1.feq_gen_ftab_fn_d_ + (
		mktbindx_1.feq_gen_data_pnt_d_[feq_gen_i_d_ - 1] - 1 << 8), (ftnlen)256));
	e_wsfe();
/* SOURCE fqshrftb.for:1630 */
/*<       enddo >*/
    }
/* SOURCE fqshrftb.for:1632 */
/*<       callfree_unit(stdout,stdindex) >*/
    feq_gen_free_unit_d_(stdout, &mktbindx_1.stdindex);
/* SOURCE fqshrftb.for:1633 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:1634 */
/*<       end >*/
} /* output_ftab_index__ */




/* SOURCE fqshrftb.for:1639 */
/*<       subroutineset_knt_of_ftabs(ftknt) >*/
/* Subroutine */ int feq_gen_set_knt_of_ftabs_d_(integer *ftknt)
{
    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Set the count of function tables in the function-table */
/*     common block.  We have some duplication because this value */
/*     was added to the function-table common block many years too */
/*     late.  Will eventually fix:) */
/* SOURCE fqshrftb.for:1647 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:1649 */
/*<       integerftknt >*/
/* INCLUDE fqshrftb.for:1651 */
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
/* INCLUDE fqshrftb.for:1652 */
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
/* *************************************************************************** */
/* SOURCE fqshrftb.for:1654 */
/*<       knt_of_ftabs=ftknt >*/
    ftablea_1.feq_gen_knt_of_ftabs_d_ = *ftknt;
/* SOURCE fqshrftb.for:1655 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:1656 */
/*<       end >*/
} /* set_knt_of_ftabs__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:1661 */
/*<        >*/
/* Subroutine */ int ftabin_(integer *in, integer *ina, integer *stdout, 
	integer *output, integer *ftp, integer *mft, integer *mlft, real *
	hslot, char *feq_gen_current_file_d_, integer *eflag, integer *ftknt, integer *
	feq_storage_ftpnt, integer *table, char *nxtnam, ftnlen current_file_len, ftnlen 
	nxtnam_len)
{
    /* Initialized data */

    static integer vtype[35] = { 0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,1,1,
	    1,1,1,0,0,0,0,1,1,1,1,1,1 };
    static integer outtyp[24] = { 2,3,4,6,7,8,9,10,11,13,14,15,20,21,22,23,24,
	    25,30,31,32,33,34,35 };

    /* Format strings */
    static char fmt_2[] = "(5x,i5,1x,a69)";
    static char fmt_39[] = "(/,\002 Table Id= \002,a,\002  Internal number\
=\002,i6,\002  Type=\002,i5)";
    static char fmt_40[] = "(/,\002 Table Id= \002,a,\002  Internal number\
=\002,i6,\002  Type=\002,i5,\002  Hdatum=\002,f10.3)";
    static char fmt_50[] = "(/,\002 Next function-table file name= \002,a)";
    static char fmt_51[] = "(/,\002 *ERR:175* Table type=\002,i3,\002 unimpl\
emented in FTABIN.\002,/,10x,\002 Valid types are:\002,25i3)";
    static char fmt_52[] = "(/,\002 Cannot continue with invalid table typ\
es.\002)";
    static char fmt_53[] = "(/,\002 *ERR:366* Expected to find: TABLE#, TABI\
D, FILE,\002,\002 or HOME but found\002,/,5x,a20,\002 instead.  Check for in\
valid end in the\002,\002 current function table.\002)";
    static char fmt_54[] = "(/\002 HOME name changed to:\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsfi(icilist *), e_rsfi(), i_indx(char *, char *, ftnlen, 
	    ftnlen), s_wsle(cilist *), do_lio(integer *, integer *, char *, 
	    ftnlen), e_wsle();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_set_knt_of_ftabs_d_(integer *);
    integer it;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *), 
	    feq_gen_do_upgrade_xsec_tab_d_(integer *, integer *, integer *, integer *, 
	    integer *);
    char line[196], chr69[69];
    integer feq_gen_type_d_;
    extern /* Subroutine */ int feq_gen_convert_to_43_d_(integer *, integer *, integer 
	    *, integer *, real *, integer *, integer *, integer *);
    char tabid[16];
    extern /* Subroutine */ int ty15in_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
    integer tabadr;
    extern /* Subroutine */ int atabin_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), inline_(integer *, 
	    integer *, char *, ftnlen);
    real hdatum;
    integer ftpold;
    real zrhufd;
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int twodin_(integer *, integer *, integer *, 
	    integer *, real *, char *, real *, integer *, integer *, integer *
	    , ftnlen), xsecin_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), feq_gen_get_next_tabid_d_(
	    integer *, char *, integer *, char *, integer *, char *, ftnlen, 
	    ftnlen, ftnlen), feq_gen_strip_l_blanks_d_(char *, ftnlen);
    char garbage[1];
    integer verbose;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__181 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__185 = { 0, 0, 0, fmt_39, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, fmt_40, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__191 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__192 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__198 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__199 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__200 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__201 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__203 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__204 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__206 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__207 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input function tables. */
/* SOURCE fqshrftb.for:1669 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:1671 */
/*<       integereflag,ftknt,ftp,in,ina,stdout,mft,mlft,output,table >*/
/* SOURCE fqshrftb.for:1673 */
/*<       integerftpnt(mft) >*/
/* SOURCE fqshrftb.for:1674 */
/*<       realhslot >*/
/* SOURCE fqshrftb.for:1675 */
/*<       characternxtnam*(*),current_file*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     INA    - unit number for the user input file */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     OUTPUT - output level for diagnostic work */
/*     FTP    - next open location in the function table storage */
/*     MFT    - maximum function table pointer value.  Same as maximum */
/*               function table number */
/*     MLFT   - maximum length of FTAB/ITAB */
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     FTKNT  - function table counter */
/*     FTPNT  - function table pointer giving the table address for each */
/*              table number.  If the address is zero the table does not */
/*              exist. */
/*     TABLE  - table number */
/*     NXTNAM - next file name for function table input */
/* INCLUDE fqshrftb.for:1695 */
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
/* INCLUDE fqshrftb.for:1696 */
/*     common for passing info for table upgrading-going from one form */
/*     to one that is smoother in its representation */
/* SOURCE tabupgrade.cmn:4 */
/*<       characterty13_to_ty43*4,twod_cubic_out*4,upgrade_xsec_tab*4 >*/
/* SOURCE tabupgrade.cmn:6 */
/*<       common/upgrdc/ty13_to_ty43,twod_cubic_out,upgrade_xsec_tab >*/
/* INCLUDE fqshrftb.for:1697 */
/* SOURCE maketabindex.cmn:2 */
/*<       character*4make_tab_index >*/
/* SOURCE maketabindex.cmn:4 */
/*<       integerftab_type(mftnum),data_pnt(mftnum),index_knt,stdindex >*/
/* SOURCE maketabindex.cmn:7 */
/*<       characterftabid(mftnum)*16,ftab_fn(mftnum)*256 >*/
/* SOURCE maketabindex.cmn:9 */
/*<       common/mktbindxc/ftab_fn,ftabid,make_tab_index >*/
/* SOURCE maketabindex.cmn:10 */
/*<       common/mktbindx/ftab_type,data_pnt,index_knt,stdindex >*/
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE fqshrftb.for:1700 */
/*<       integermaxout,maxtyp >*/
/* SOURCE fqshrftb.for:1701 */
/*<       parameter(maxtyp=35,maxout=24) >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:1704 */
/*<       integerouttyp(maxout),vtype(maxtyp) >*/
/* SOURCE fqshrftb.for:1705 */
/*<       saveouttyp,vtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:1708 */
/*<       integerit,type,tabadr,verbose,ftpold >*/
/* SOURCE fqshrftb.for:1709 */
/*<       realhdatum,zrhufd >*/
/* SOURCE fqshrftb.for:1710 */
/*<       characterchr69*69,line*196,tabid*16,garbage*1 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:1714 */
/*<       intrinsiciabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:1717 */
/*<       integerlenstr >*/
/* SOURCE fqshrftb.for:1718 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE fqshrftb.for:1722 */
/*<       datavtype/0,3*1,0,4*1,1,1,0,2*1,1,4*0,6*1,4*0,6*1/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
/* SOURCE fqshrftb.for:1723 */
/*<        >*/
/* SOURCE fqshrftb.for:1727 */
/*<     2 format(5x,i5,1x,a69) >*/
/* L2: */
/* 37   FORMAT(7X,A16,A) */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:1731 */
/*<    38 format(/,' Table Id= ',a,' Internal number=',i6) >*/
/* L38: */
/* SOURCE fqshrftb.for:1732 */
/*<    39 format(/,' Table Id= ',a,'  Internal number=',i6,'  Type=',i5) >*/
/* L39: */
/* SOURCE fqshrftb.for:1733 */
/*<    40  >*/
/* L40: */
/* SOURCE fqshrftb.for:1735 */
/*<    50 format(/,' Next function-table file name= ',a) >*/
/* L50: */
/* SOURCE fqshrftb.for:1736 */
/*<    51  >*/
/* L51: */
/* SOURCE fqshrftb.for:1738 */
/*<    52 format(/,' Cannot continue with invalid table types.') >*/
/* L52: */
/* SOURCE fqshrftb.for:1739 */
/*<    53  >*/
/* L53: */
/* SOURCE fqshrftb.for:1743 */
/*<    54 format(/' HOME name changed to:',a) >*/
/* L54: */
/* *********************************************************************** */
/*     Set the garbage character that seems to appear at the end of */
/*     ASCII files for currently unknown reasons. */
/* SOURCE fqshrftb.for:1747 */
/*<       garbage=char(26) >*/
    *(unsigned char *)garbage = '\32';
/*     DEFINITION OF CONTENTS OF VTYPE */
/*     CURRENTLY VALID TABLE TYPES HAVE A VALUE OF */
/*     1 IN VTYPE(ABS(TYPE)) */
/*                                                20      30 */
/*                                                21      31 */
/*                         6                  16  22  29  32 */
/*                    2    7                  17  23  28  33 */
/*                    3    8            13    18  24  27  34 */
/*                1   4 5  9   10 11 12 14 15 19  25  26  35 */
/*     DATA VTYPE/0,3*1,0, 4*1, 1, 1, 0,2*1,1,4*0,6*1,4*0,6*1/ */
/* SOURCE fqshrftb.for:1759 */
/*<  1000 continue >*/
L1000:
/* SOURCE fqshrftb.for:1760 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)196);
/* SOURCE fqshrftb.for:1763 */
/*<       callstrip_l_blanks(line) >*/
    feq_gen_strip_l_blanks_d_(line, (ftnlen)196);
/* SOURCE fqshrftb.for:1765 */
/*<       if(line(1:1).eq.garbage)then >*/
    if (*(unsigned char *)line == *(unsigned char *)garbage) {
/* SOURCE fqshrftb.for:1766 */
/*<       line='ENDFILE' >*/
	s_copy(line, const_cast<char*>("ENDFILE"), (ftnlen)196, (ftnlen)7);
/* SOURCE fqshrftb.for:1767 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1768 */
/*<       if(line(1:7).eq.'ENDFILE')goto3000 >*/
    if (s_cmp(line, const_cast<char*>("ENDFILE"), (ftnlen)7, (ftnlen)7) == 0) {
	goto L3000;
    }
/* SOURCE fqshrftb.for:1769 */
/*<        >*/
    if (s_cmp(line, const_cast<char*>("TABLE#"), (ftnlen)6, (ftnlen)6) != 0 && s_cmp(line, const_cast<char*>("TAB\
ID"), (ftnlen)5, (ftnlen)5) != 0 && s_cmp(line, const_cast<char*>("FILE"), (ftnlen)4, (ftnlen)4) 
	    != 0 && s_cmp(line, const_cast<char*>("File"), (ftnlen)4, (ftnlen)4) != 0 && s_cmp(
	    line, const_cast<char*>("HOME"), (ftnlen)4, (ftnlen)4) != 0 && s_cmp(line, const_cast<char*>("Home"), (
	    ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE fqshrftb.for:1772 */
/*<       write(stdout,53)line(1:20) >*/
	feq_gen_io_d__181.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__181);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)20);
	e_wsfe();
/* SOURCE fqshrftb.for:1773 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1774 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1775 */
/*<       callget_next_tabid(stdout,line,eflag,tabid,table,nxtnam) >*/
    feq_gen_get_next_tabid_d_(stdout, line, eflag, tabid, table, nxtnam, (ftnlen)196, (
	    ftnlen)16, nxtnam_len);
/* SOURCE fqshrftb.for:1780 */
/*<       if(table.lt.0)goto2000 >*/
    if (*table < 0) {
	goto L2000;
    }
/* SOURCE fqshrftb.for:1781 */
/*<       ftknt=ftknt+1 >*/
    ++(*ftknt);
/*        WRITE(STDOUT,38) TABID(1:LENSTR(TABID)), TABLE */
/*       STORE THE TABLE POINTER */
/* SOURCE fqshrftb.for:1786 */
/*<       if(ftpnt(table).eq.0)goto300 >*/
    if (ftpnt[*table] == 0) {
	goto L300;
    }
/*          ERROR-DUPLICATE TABLE NUMBER */
/* SOURCE fqshrftb.for:1788 */
/*<       callkil(25,table,eflag) >*/
    kil_(&feq_gen_c_d_25, table, eflag);
/* SOURCE fqshrftb.for:1791 */
/*<   300 continue >*/
L300:
/* SOURCE fqshrftb.for:1794 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)196);
/* SOURCE fqshrftb.for:1797 */
/*<       read(line,2,err=991)type,chr69 >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, chr69, (ftnlen)69);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*       CATCH OLD USES OF TYPE 1 AND 12 */
/* SOURCE fqshrftb.for:1800 */
/*<       if(type.eq.1)then >*/
    if (feq_gen_type_d_ == 1) {
/* SOURCE fqshrftb.for:1801 */
/*<       type=21 >*/
	feq_gen_type_d_ = 21;
/* SOURCE fqshrftb.for:1802 */
/*<       elseif(type.eq.12)then >*/
    } else if (feq_gen_type_d_ == 12) {
/* SOURCE fqshrftb.for:1803 */
/*<       type=22 >*/
	feq_gen_type_d_ = 22;
/* SOURCE fqshrftb.for:1804 */
/*<       elseif(type.eq.-1)then >*/
    } else if (feq_gen_type_d_ == -1) {
/* SOURCE fqshrftb.for:1805 */
/*<       type=-21 >*/
	feq_gen_type_d_ = -21;
/* SOURCE fqshrftb.for:1806 */
/*<       elseif(type.eq.-12)then >*/
    } else if (feq_gen_type_d_ == -12) {
/* SOURCE fqshrftb.for:1807 */
/*<       type=-22 >*/
	feq_gen_type_d_ = -22;
/* SOURCE fqshrftb.for:1808 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1809 */
/*<       if(chr69(1:6).ne.'HDATUM')then >*/
    if (s_cmp(chr69, const_cast<char*>("HDATUM"), (ftnlen)6, (ftnlen)6) != 0) {
/* SOURCE fqshrftb.for:1810 */
/*<       write(stdout,39)tabid(1:lenstr(tabid)),table,type >*/
	feq_gen_io_d__185.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__185);
	do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	do_fio(&feq_gen_c_d_1, (char *)&(*table), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:1811 */
/*<       hdatum=-9999.0 >*/
	hdatum = (float)-9999.;
/* SOURCE fqshrftb.for:1812 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:1813 */
/*<       read(chr69(8:17),'(F10.0)',err=991)hdatum >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = chr69 + 7;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:1814 */
/*<       write(stdout,40)tabid(1:lenstr(tabid)),table,type,hdatum >*/
	feq_gen_io_d__187.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__187);
	do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	do_fio(&feq_gen_c_d_1, (char *)&(*table), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE fqshrftb.for:1815 */
/*<       if(type.eq.14.or.type.eq.-14)then >*/
	if (feq_gen_type_d_ == 14 || feq_gen_type_d_ == -14) {
/*           Bring possible WSPRO source flag to head of string */
/* SOURCE fqshrftb.for:1817 */
/*<       chr69(1:17)=' ' >*/
	    s_copy(chr69, const_cast<char*>(" "), (ftnlen)17, (ftnlen)1);
/* SOURCE fqshrftb.for:1818 */
/*<       callstrip_l_blanks(chr69) >*/
	    feq_gen_strip_l_blanks_d_(chr69, (ftnlen)69);
/*            WRITE(STDOUT,*) ' FTABIN: CHR69=',CHR69(1:5) */
/* SOURCE fqshrftb.for:1821 */
/*<       else >*/
	} else {
/*           Seek possible zero-ups head free drop value.  May not be present. */
/* SOURCE fqshrftb.for:1823 */
/*<       it=index(chr69,'zrhufd') >*/
	    it = i_indx(chr69, const_cast<char*>("zrhufd"), (ftnlen)69, (ftnlen)6);
/* SOURCE fqshrftb.for:1824 */
/*<       if(it.gt.0)then >*/
	    if (it > 0) {
/*             We have a hit!  Read it and pass it on to subroutine twodin. */
/* SOURCE fqshrftb.for:1826 */
/*<       read(chr69(it+7:it+17),'(f10.0)')zrhufd >*/
		feq_gen_i_d_1 = it + 6;
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = it + 17 - feq_gen_i_d_1;
		feq_gen_ici_d_1.iciunit = chr69 + feq_gen_i_d_1;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(f10.0)");
		s_rsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&zrhufd, (ftnlen)sizeof(real));
		e_rsfi();
/* SOURCE fqshrftb.for:1827 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:1828 */
/*<       zrhufd=0.0 >*/
		zrhufd = (float)0.;
/* SOURCE fqshrftb.for:1829 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:1830 */
/*<       chr69=' ' >*/
	    s_copy(chr69, const_cast<char*>(" "), (ftnlen)69, (ftnlen)1);
/* SOURCE fqshrftb.for:1831 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1832 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1833 */
/*<       it=iabs(type) >*/
    it = abs(feq_gen_type_d_);
/*       Record the file name and type for each table found. */
/* SOURCE fqshrftb.for:1836 */
/*<       index_knt=index_knt+1 >*/
    ++mktbindx_1.feq_gen_index_knt_d_;
/* SOURCE fqshrftb.for:1837 */
/*<       ftabid(index_knt)=tabid >*/
    s_copy(mktbindxc_1.ftabid + (mktbindx_1.feq_gen_index_knt_d_ - 1 << 4), tabid, (
	    ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:1838 */
/*<       ftab_type(index_knt)=it >*/
    mktbindx_1.feq_gen_ftab_type_d_[mktbindx_1.feq_gen_index_knt_d_ - 1] = it;
/* SOURCE fqshrftb.for:1839 */
/*<       ftab_fn(index_knt)=current_file >*/
    s_copy(mktbindxc_1.feq_gen_ftab_fn_d_ + (mktbindx_1.feq_gen_index_knt_d_ - 1 << 8), 
	    feq_gen_current_file_d_, (ftnlen)256, current_file_len);
/* SOURCE fqshrftb.for:1840 */
/*<       data_pnt(index_knt)=index_knt >*/
    mktbindx_1.feq_gen_data_pnt_d_[mktbindx_1.feq_gen_index_knt_d_ - 1] = 
	    mktbindx_1.feq_gen_index_knt_d_;
/*       Make sure that the table address is even if the table is of type 7, 8 */
/*       9, or 11 */
/* SOURCE fqshrftb.for:1844 */
/*<       if(it>6.and.it<10.or.it==11)then >*/
    if (it > 6 && it < 10 || it == 11) {
/* SOURCE fqshrftb.for:1845 */
/*<       if(mod(ftp,2)/=0)then >*/
	if (*ftp % 2 != 0) {
/* SOURCE fqshrftb.for:1846 */
/*<       ftp=ftp+1 >*/
	    ++(*ftp);
/* SOURCE fqshrftb.for:1847 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1848 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1849 */
/*<       ftpnt(table)=ftp >*/
    ftpnt[*table] = *ftp;
/* SOURCE fqshrftb.for:1852 */
/*<       if(vtype(it).eq.0)then >*/
    if (vtype[it - 1] == 0) {
/*         UNSUPPORTED TYPE FOUND.  CANNOT CONTINUE WITH PROCESSING */
/* SOURCE fqshrftb.for:1854 */
/*<       write(stdout,51)type,outtyp >*/
	feq_gen_io_d__190.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__190);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_24, (char *)&outtyp[0], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:1855 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__191.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__191);
	e_wsfe();
/* SOURCE fqshrftb.for:1856 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1857 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1859 */
/*<        >*/
    switch (it) {
	case 1:  goto L110;
	case 2:  goto L102;
	case 3:  goto L102;
	case 4:  goto L102;
	case 5:  goto L105;
	case 6:  goto L106;
	case 7:  goto L102;
	case 8:  goto L102;
	case 9:  goto L102;
	case 10:  goto L106;
	case 11:  goto L102;
	case 12:  goto L110;
	case 13:  goto L106;
	case 14:  goto L106;
	case 15:  goto L107;
	case 16:  goto L110;
	case 17:  goto L110;
	case 18:  goto L110;
	case 19:  goto L110;
	case 20:  goto L101;
	case 21:  goto L101;
	case 22:  goto L101;
	case 23:  goto L101;
	case 24:  goto L101;
	case 25:  goto L101;
	case 26:  goto L110;
	case 27:  goto L110;
	case 28:  goto L110;
	case 29:  goto L110;
	case 30:  goto L101;
	case 31:  goto L101;
	case 32:  goto L101;
	case 33:  goto L101;
	case 34:  goto L101;
	case 35:  goto L101;
    }
/* SOURCE fqshrftb.for:1863 */
/*<        >*/
    feq_gen_io_d__192.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__192);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:14* INVALID TABLE TYPE IN FTABIN."), (ftnlen)
	    39);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE fqshrftb.for:1865 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1867 */
/*<   101 continue >*/
L101:
/*          CROSS-SECTION TABLE HERE */
/* SOURCE fqshrftb.for:1869 */
/*<       if(hslot.eq.0.0)then >*/
    if (*hslot == (float)0.) {
/*            save ftp value for possible function-table upgrade */
/* SOURCE fqshrftb.for:1872 */
/*<       ftpold=ftp >*/
	ftpold = *ftp;
/* SOURCE fqshrftb.for:1873 */
/*<       callxsecin(in,stdout,mlft,table,output,eflag,ftp,type) >*/
	xsecin_(in, stdout, mlft, table, output, eflag, ftp, &feq_gen_type_d_);
/* SOURCE fqshrftb.for:1876 */
/*<       if(upgrade_xsec_tab.eq.'YES'.or.upgrade_xsec_tab.eq.'YESO')then >*/
	if (s_cmp(upgrdc_1.feq_gen_upgrade_xsec_tab_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) ==
		 0 || s_cmp(upgrdc_1.feq_gen_upgrade_xsec_tab_d_, const_cast<char*>("YESO"), (ftnlen)4, (
		ftnlen)4) == 0) {
/* SOURCE fqshrftb.for:1878 */
/*<       tabadr=ftpnt(table) >*/
	    tabadr = ftpnt[*table];
/* SOURCE fqshrftb.for:1879 */
/*<       if(upgrade_xsec_tab.eq.'YESO')then >*/
	    if (s_cmp(upgrdc_1.feq_gen_upgrade_xsec_tab_d_, const_cast<char*>("YESO"), (ftnlen)4, (ftnlen)
		    4) == 0) {
/* SOURCE fqshrftb.for:1880 */
/*<       verbose=1 >*/
		verbose = 1;
/* SOURCE fqshrftb.for:1881 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:1882 */
/*<       verbose=0 >*/
		verbose = 0;
/* SOURCE fqshrftb.for:1883 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:1884 */
/*<       calldo_upgrade_xsec_tab(stdout,tabadr,verbose,ftpold,eflag) >*/
	    feq_gen_do_upgrade_xsec_tab_d_(stdout, &tabadr, &verbose, &ftpold, eflag);
/* SOURCE fqshrftb.for:1887 */
/*<       ftp=ftpold >*/
	    *ftp = ftpold;
/* SOURCE fqshrftb.for:1888 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1891 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:1892 */
/*<       write(stdout,*)' AUTOMATIC SLOT ADDITION NO LONGER ','SUPPORTED' >*/
	feq_gen_io_d__196.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__196);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" AUTOMATIC SLOT ADDITION NO LONGER "), (ftnlen)
		35);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("SUPPORTED"), (ftnlen)9);
	e_wsle();
/* SOURCE fqshrftb.for:1894 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1895 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1897 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE fqshrftb.for:1898 */
/*<   102 continue >*/
L102:
/*          ARBITRARY INTERVAL FUNCTION TABLE */
/* SOURCE fqshrftb.for:1900 */
/*<       callatabin(in,stdout,mlft,table,eflag,ftp,type) >*/
    atabin_(in, stdout, mlft, table, eflag, ftp, &feq_gen_type_d_);
/* SOURCE fqshrftb.for:1903 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE fqshrftb.for:1905 */
/*<   105 continue >*/
L105:
/* SOURCE fqshrftb.for:1906 */
/*<       write(stdout,*)' *BUG:XXX* TABLE TYPE 5 NOT SUPPORTED.' >*/
    feq_gen_io_d__197.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__197);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* TABLE TYPE 5 NOT SUPPORTED."), (ftnlen)38)
	    ;
    e_wsle();
/* SOURCE fqshrftb.for:1907 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1909 */
/*<   106 continue >*/
L106:
/*          TWO-D TABLE INPUT */
/* SOURCE fqshrftb.for:1911 */
/*<        >*/
    twodin_(in, stdout, mlft, table, &hdatum, chr69, &zrhufd, eflag, ftp, &
	    feq_gen_type_d_, (ftnlen)69);
/* SOURCE fqshrftb.for:1914 */
/*<       if(type.eq.13)then >*/
    if (feq_gen_type_d_ == 13) {
/* SOURCE fqshrftb.for:1915 */
/*<       if(ty13_to_ty43.eq.'YES'.or.ty13_to_ty43.eq.'YESO')then >*/
	if (s_cmp(upgrdc_1.feq_gen_ty13_to_ty43_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0 
		|| s_cmp(upgrdc_1.feq_gen_ty13_to_ty43_d_, const_cast<char*>("YESO"), (ftnlen)4, (ftnlen)
		4) == 0) {
/*              Convert to type 43. */
/* SOURCE fqshrftb.for:1918 */
/*<       tabadr=ftpnt(table) >*/
	    tabadr = ftpnt[*table];
/* SOURCE fqshrftb.for:1919 */
/*<       if(ty13_to_ty43.eq.'YESO')then >*/
	    if (s_cmp(upgrdc_1.feq_gen_ty13_to_ty43_d_, const_cast<char*>("YESO"), (ftnlen)4, (ftnlen)4) 
		    == 0) {
/* SOURCE fqshrftb.for:1920 */
/*<       verbose=1 >*/
		verbose = 1;
/* SOURCE fqshrftb.for:1921 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:1922 */
/*<       verbose=0 >*/
		verbose = 0;
/* SOURCE fqshrftb.for:1923 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:1924 */
/*<        >*/
	    feq_gen_convert_to_43_d_(stdout, mlft, table, &tabadr, &hdatum, &verbose, 
		    ftp, eflag);
/* SOURCE fqshrftb.for:1927 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1928 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1929 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE fqshrftb.for:1930 */
/*<   107 continue >*/
L107:
/*          Simple 3-D table via table type 15 */
/* SOURCE fqshrftb.for:1932 */
/*<       callty15in(in,stdout,mlft,table,eflag,ftp,type) >*/
    ty15in_(in, stdout, mlft, table, eflag, ftp, &feq_gen_type_d_);
/* SOURCE fqshrftb.for:1935 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE fqshrftb.for:1936 */
/*<   110 continue >*/
L110:
/*          UNIMPLEMENTED TABLE TYPES */
/* SOURCE fqshrftb.for:1939 */
/*<        >*/
    feq_gen_io_d__198.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__198);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:14* INVALID TABLE TYPE IN FTABIN."), (ftnlen)
	    39);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE fqshrftb.for:1941 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1943 */
/*<  1500 continue >*/
L1500:
/* SOURCE fqshrftb.for:1945 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fqshrftb.for:1947 */
/*<  2000 continue >*/
L2000:
/* SOURCE fqshrftb.for:1948 */
/*<       if(nxtnam.ne.' ')then >*/
    if (s_cmp(nxtnam, const_cast<char*>(" "), nxtnam_len, (ftnlen)1) != 0) {
/* SOURCE fqshrftb.for:1949 */
/*<       if(table.eq.-15)then >*/
	if (*table == -15) {
/* SOURCE fqshrftb.for:1950 */
/*<       write(stdout,50)nxtnam(1:lenstr(nxtnam)) >*/
	    feq_gen_io_d__199.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__199);
	    do_fio(&feq_gen_c_d_1, nxtnam, lenstr_(nxtnam, nxtnam_len));
	    e_wsfe();
/* SOURCE fqshrftb.for:1951 */
/*<       elseif(table.eq.-16)then >*/
	} else if (*table == -16) {
/* SOURCE fqshrftb.for:1952 */
/*<       write(stdout,54)nxtnam(1:lenstr(nxtnam)) >*/
	    feq_gen_io_d__200.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__200);
	    do_fio(&feq_gen_c_d_1, nxtnam, lenstr_(nxtnam, nxtnam_len));
	    e_wsfe();
/* SOURCE fqshrftb.for:1953 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1954 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1956 */
/*<       callset_knt_of_ftabs(ftknt) >*/
    feq_gen_set_knt_of_ftabs_d_(ftknt);
/* SOURCE fqshrftb.for:1958 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:1959 */
/*<  3000 continue >*/
L3000:
/*     READ THE NEXT TABLE VALUE FROM INA */
/* SOURCE fqshrftb.for:1961 */
/*<       callinline(ina,stdout,line) >*/
    inline_(ina, stdout, line, (ftnlen)196);
/* SOURCE fqshrftb.for:1964 */
/*<       callget_next_tabid(stdout,line,eflag,tabid,table,nxtnam) >*/
    feq_gen_get_next_tabid_d_(stdout, line, eflag, tabid, table, nxtnam, (ftnlen)196, (
	    ftnlen)16, nxtnam_len);
/* SOURCE fqshrftb.for:1968 */
/*<       if(table.gt.0)then >*/
    if (*table > 0) {
/* SOURCE fqshrftb.for:1969 */
/*<        >*/
	feq_gen_io_d__201.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__201);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:131* INVALID USE OF AUXILIARY TABLE"), (
		ftnlen)41);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FILES"), (ftnlen)6);
	e_wsle();
/* SOURCE fqshrftb.for:1971 */
/*<       write(stdout,*)'  FEQIN TABLE INPUT MUST BE COMPLETE BEFORE' >*/
	feq_gen_io_d__202.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__202);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  FEQIN TABLE INPUT MUST BE COMPLETE BEFORE"), (
		ftnlen)43);
	e_wsle();
/* SOURCE fqshrftb.for:1972 */
/*<       write(stdout,*)'  USING AUXILIARY FILES.' >*/
	feq_gen_io_d__203.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__203);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  USING AUXILIARY FILES."), (ftnlen)24);
	e_wsle();
/* SOURCE fqshrftb.for:1973 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1974 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1975 */
/*<       if(nxtnam.ne.' ')then >*/
    if (s_cmp(nxtnam, const_cast<char*>(" "), nxtnam_len, (ftnlen)1) != 0) {
/* SOURCE fqshrftb.for:1976 */
/*<       if(table.eq.-15)then >*/
	if (*table == -15) {
/* SOURCE fqshrftb.for:1977 */
/*<       write(stdout,50)nxtnam(1:lenstr(nxtnam)) >*/
	    feq_gen_io_d__204.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__204);
	    do_fio(&feq_gen_c_d_1, nxtnam, lenstr_(nxtnam, nxtnam_len));
	    e_wsfe();
/* SOURCE fqshrftb.for:1978 */
/*<       elseif(table.eq.-16)then >*/
	} else if (*table == -16) {
/* SOURCE fqshrftb.for:1979 */
/*<       write(stdout,54)nxtnam(1:lenstr(nxtnam)) >*/
	    feq_gen_io_d__205.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__205);
	    do_fio(&feq_gen_c_d_1, nxtnam, lenstr_(nxtnam, nxtnam_len));
	    e_wsfe();
/* SOURCE fqshrftb.for:1980 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:1981 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:1983 */
/*<       callset_knt_of_ftabs(ftknt) >*/
    feq_gen_set_knt_of_ftabs_d_(ftknt);
/* SOURCE fqshrftb.for:1985 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:1987 */
/*<   991 continue >*/
L991:
/* SOURCE fqshrftb.for:1988 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__206.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__206);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE fqshrftb.for:1989 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__207.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__207);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)196);
    e_wsle();
/* SOURCE fqshrftb.for:1990 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:1991 */
/*<       end >*/
    return 0;
} /* ftabin_ */




/* SOURCE fqshrftb.for:1995 */
/*<       integerfunctiongettbn(adrs) >*/
integer gettbn_(integer *adrs)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Get the table number of the table at ADRS. */
/* SOURCE fqshrftb.for:2001 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:2003 */
/*<       integeradrs >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:2009 */
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
/* INCLUDE fqshrftb.for:2010 */
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
/* SOURCE fqshrftb.for:2012 */
/*<       gettbn=itab(adrs+1) >*/
    ret_val = itab[*adrs + 1];
/* SOURCE fqshrftb.for:2013 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrftb.for:2014 */
/*<       end >*/
} /* gettbn_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:2018 */
/*<       realfunctionget_slot_depth(adrs) >*/
doublereal feq_gen_get_slot_depth_d_(integer *adrs)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Get the slot depth of the cross-section function table at ADRS. */
/* SOURCE fqshrftb.for:2024 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:2026 */
/*<       integeradrs >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the cross-section function table in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:2032 */
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
/* INCLUDE fqshrftb.for:2033 */
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
/* SOURCE fqshrftb.for:2035 */
/*<       get_slot_depth=ftab(adrs+7) >*/
    ret_val = ftab[*adrs + 7];
/* SOURCE fqshrftb.for:2036 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrftb.for:2037 */
/*<       end >*/
} /* get_slot_depth__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:2041 */
/*<        >*/
/* Subroutine */ int interp_(integer *stdout, integer *tabl, integer *tabr, 
	real *xl, real *xr, integer *n, integer *nbn, integer *nin, integer *
	mlft, real *feq_storage_x, real *feq_gen_feq_storage_z_d_, integer *feq_storage_tab, integer *feq_storage_node, real *sfac, 
	real *feq_gen_feq_storage_yslot_left_d_, real *feq_gen_feq_storage_yslot_right_d_, integer *eflag, integer *ftp,
	 integer *feq_storage_nsec)
{
    // Original 0x442e8d, 0x443756 and 0x4438a5 retain wide distances and a reciprocal for station fractions.

    /* Initialized data */

    static integer newtyp[36]	/* was [6][6] */ = { 20,20,20,20,20,20,20,21,
	    21,23,21,21,20,21,22,20,21,22,20,23,20,23,23,23,20,21,21,23,24,24,
	    20,21,22,23,24,25 };
    static integer jid[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,
	    1,1 };
    static integer qcid[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
	    0,1 };

    /* Format strings */
    static char fmt_51[] = "(/,\002 *BUG:XXX* Right hand table type=\002,i5\
,\002 invalid in\002,\002 subroutine INTERP.\002)";
    static char fmt_52[] = "(/,\002 *BUG:XXX* Left hand table type=\002,i5\
,\002 invalid in\002,\002 subroutine INTERP.\002)";
    static char fmt_2000[] = "(\002 *ERR:86* INVALID CROSS-SECTION INTERPOLA\
TION REQUEST\002,\002 XL = \002,f10.3,\002 XM = \002,f10.3,\002 XR = \002,f1\
0.3,/,11x,\002 UPS TABID=\002,a,\002 DNS TABID=\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    real a, b;
    doublereal feq_gen_h_d_;
    integer feq_gen_i_d_, j;
    real k, t;
    extern /* Subroutine */ int feq_gen_put_string_in_ft_d_(integer *, char *, ftnlen);
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real db, al, bl, ma, dk;
    integer ij, jj;
    real ar, br, kl, qc;
    integer ip[150];
    real yb;
    doublereal dx;
    integer it;
    real kr, mq, tl, xm, tr, dbl, dma, dbr, mal, dkl, alp, mar, dkr, qcl, sdl, dtl, qcr, yal, ybl, sdr, dtr;
    doublereal fac;
    integer isp;
    real mql;
    integer isr;
    real yar, mqr, ybr, dmq;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer feq_gen_feql_select4_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    real dmal;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real dalp, dmar, alpl;
    doublereal east;
    real dmql, alpr;
    integer xoff;
    real dmqr, ymax;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int feq_gen_put_dp_in_ft_d_(integer *, doublereal *);
    real dalpl, dalpr;
    doublereal eastl, eastr;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *), xlkt21_(integer *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *),
	     xlkt22_(integer *, real *, real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *), xlkt23_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *), xlkt24_(integer *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *), xlkt25_(integer *, real *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *);
    doublereal north;
    integer typel, typer;
    extern integer gettbn_(integer *);
    integer dcrmnt;
    doublereal northl, northr;
    char feq_gen_internal_tabid_d_[16];
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);
    extern doublereal feq_gen_get_slot_depth_d_(integer *);
    integer dcrmntl, dcrmntr;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__230 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__231 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__241 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Interpolate at one or more points between left hand section at */
/*     XL with elements stored at TABL and right hand section at */
/*     XR with elements stored at TABR. */
/* SOURCE fqshrftb.for:2053 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:2055 */
/*<       integereflag,ftp,stdout,mlft,n,nbn,nin,tabl,tabr >*/
/* SOURCE fqshrftb.for:2056 */
/*<       integernode(nin),nsec(nbn),tab(nin) >*/
/* SOURCE fqshrftb.for:2057 */
/*<       realsfac,x(nin),xl,xr,z(nin),yslot_left(n),yslot_right(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TABL   - address of the cross section table on the left */
/*     TABR   - address of the cross section table on the right */
/*     XL     - station of known section on the left */
/*     XR     - station of known section on the right */
/*     N      - number of depth values for the interpolated cross section */
/*               tables */
/*     NBN    - total number on nodes on branches in the model */
/*     NIN    - number of interpolated sections */

/*     MLFT   - maximum length of FTAB/ITAB */
/*     X      - stations for interpolated cross sections */
/*     YSLOT_LEFT - depth valuse to use for the left-hand section */
/*     YSLOT_RIGHT- depth values to use for the right-hand section */
/*     Z      - bottom elevations for interpolated cross sections */
/*     TAB    - table number */
/*     NODE   - node number */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     FTP    - next open location in the function table storage */
/*     NSEC   - number and also address of cross section table at a node */
/*               on a branch */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:2085 */
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
/* INCLUDE fqshrftb.for:2086 */
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
/* INCLUDE fqshrftb.for:2087 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:2090 */
/*<       integerjid(25),newtyp(6,6),qcid(25) >*/
/* SOURCE fqshrftb.for:2091 */
/*<       savejid,newtyp,qcid >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:2094 */
/*<        >*/
/* SOURCE fqshrftb.for:2096 */
/*<       integerip(mnmid) >*/
/* SOURCE fqshrftb.for:2097 */
/*<        >*/
/* SOURCE fqshrftb.for:2103 */
/*<       real*8eastl,eastr,northl,northr,east,north >*/
/* SOURCE fqshrftb.for:2105 */
/*<       characterinternal_tabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:2108 */
/*<       intrinsicmin,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE fqshrftb.for:2111 */
/*<       realget_slot_depth >*/
/* SOURCE fqshrftb.for:2112 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE fqshrftb.for:2113 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:2114 */
/*<       integergettbn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:2117 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:2041 */
/*<       integer feql_select4 >*/
/* SOURCE fqshrftb.for:2122 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_yslot_right_d_(feq_gen_feq_storage_yslot_right_d_, 1);

    feq::IndexedPointer<real> feq_gen_yslot_left_d_(feq_gen_feq_storage_yslot_left_d_, 1);

    feq::IndexedPointer<integer> nsec(feq_storage_nsec, 1);

    feq::IndexedPointer<integer> node(feq_storage_node, 1);

    feq::IndexedPointer<integer> tab(feq_storage_tab, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* SOURCE fqshrftb.for:2128 */
/*<       datajid/20*0,1,1,0,1,1/ >*/
/* SOURCE fqshrftb.for:2129 */
/*<       dataqcid/21*0,1,0,0,1/ >*/
/* SOURCE fqshrftb.for:2132 */
/*<    51  >*/
/* L51: */
/* SOURCE fqshrftb.for:2134 */
/*<    52  >*/
/* L52: */
/* SOURCE fqshrftb.for:2136 */
/*<  2000  >*/
/* L2000: */
/* *********************************************************************** */
/* SOURCE fqshrftb.for:2140 */
/*<       typel=itab(tabl+2) >*/
    typel = itab[(0 + (0 + (*tabl + 2 - 0 << 2))) / 4];
/* SOURCE fqshrftb.for:2141 */
/*<       if(typel.ge.30.and.typel.le.35)then >*/
    if (typel >= 30 && typel <= 35) {
/* SOURCE fqshrftb.for:2142 */
/*<       dcrmntl=10 >*/
	dcrmntl = 10;
/* SOURCE fqshrftb.for:2143 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:2144 */
/*<       dcrmntl=0 >*/
	dcrmntl = 0;
/* SOURCE fqshrftb.for:2145 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:2146 */
/*<       typer=itab(tabr+2) >*/
    typer = itab[*tabr + 2];
/* SOURCE fqshrftb.for:2147 */
/*<       if(typer.ge.30.and.typer.le.35)then >*/
    if (typer >= 30 && typer <= 35) {
/* SOURCE fqshrftb.for:2148 */
/*<       dcrmntr=10 >*/
	dcrmntr = 10;
/* SOURCE fqshrftb.for:2149 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:2150 */
/*<       dcrmntr=0 >*/
	dcrmntr = 0;
/* SOURCE fqshrftb.for:2151 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:2152 */
/*<       sdl=get_slot_depth(tabl) >*/
    sdl = feq_gen_get_slot_depth_d_(tabl);
/* SOURCE fqshrftb.for:2153 */
/*<       sdr=get_slot_depth(tabr) >*/
    sdr = feq_gen_get_slot_depth_d_(tabr);
/* SOURCE fqshrftb.for:2154 */
/*<       eastl=get_dp_from_ft(tabl+8) >*/
    feq_gen_i_d_1 = *tabl + 8;
    eastl = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:2155 */
/*<       northl=get_dp_from_ft(tabl+10) >*/
    feq_gen_i_d_1 = *tabl + 10;
    northl = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:2156 */
/*<       eastr=get_dp_from_ft(tabr+8) >*/
    feq_gen_i_d_1 = *tabr + 8;
    eastr = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE fqshrftb.for:2157 */
/*<       northr=get_dp_from_ft(tabr+10) >*/
    feq_gen_i_d_1 = *tabr + 10;
    northr = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/*      XOFFL = OFFVEC(TYPEL) */
/*      XOFFR = OFFVEC(TYPER) */
/* SOURCE fqshrftb.for:2162 */
/*<       if(typel-dcrmntl.lt.20.or.typel-dcrmntl.gt.25)then >*/
    if (typel - dcrmntl < 20 || typel - dcrmntl > 25) {
/* SOURCE fqshrftb.for:2163 */
/*<       write(stdout,51)typel >*/
	feq_gen_io_d__230.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__230);
	do_fio(&feq_gen_c_d_1, (char *)&typel, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:2164 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:2165 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:2166 */
/*<       if(typer-dcrmntr.lt.20.or.typer-dcrmntr.gt.25)then >*/
    if (typer - dcrmntr < 20 || typer - dcrmntr > 25) {
/* SOURCE fqshrftb.for:2167 */
/*<       write(stdout,52)typer >*/
	feq_gen_io_d__231.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__231);
	do_fio(&feq_gen_c_d_1, (char *)&typer, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:2168 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:2169 */
/*<       endif >*/
    }
/*     SET THE TYPE OF THE TABLE THAT CAN BE INTERPOLATED BETWEEN THE */
/*     TWO GIVEN TABLES. */
/* SOURCE fqshrftb.for:2173 */
/*<       type=newtyp(typel-19-dcrmntl,typer-19-dcrmntr) >*/
    feq_gen_type_d_ = newtyp[typel - 19 - dcrmntl + (typer - 19 - dcrmntr) * 6 - 7];
/* SOURCE fqshrftb.for:2175 */
/*<       if(dcrmntl.gt.0.and.dcrmntr.gt.0)then >*/
    if (dcrmntl > 0 && dcrmntr > 0) {
/*       Both tables have extra derivatives */
/* SOURCE fqshrftb.for:2177 */
/*<       dcrmnt=10 >*/
	dcrmnt = 10;
/* SOURCE fqshrftb.for:2178 */
/*<       type=type+dcrmnt >*/
	feq_gen_type_d_ += dcrmnt;
/* SOURCE fqshrftb.for:2179 */
/*<       xoff=offvec(type) >*/
	xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:2180 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:2181 */
/*<       dcrmnt=0 >*/
	dcrmnt = 0;
/* SOURCE fqshrftb.for:2182 */
/*<       xoff=offvec(type) >*/
	xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:2183 */
/*<       endif >*/
    }
/*     SET MAXIMUM ARGUMENT FOR TABLES AS IF THEY HAD NOT BEEN */
/*     EXTRAPOLATED VERTICALLY.  YMAX GIVES THE MAXIMUM DEPTH */
/*     DEFINED BY THE CROSS SECTION MEASUREMENTS. */
/* SOURCE fqshrftb.for:2189 */
/*<       ymax=min(ftab(tabl+6),ftab(tabr+6)) >*/
/* Computing MIN */
    feq_gen_r_d_1 = ftab[*tabl + 6], feq_gen_r_d_2 = ftab[*tabr + 6];
    ymax = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/*     CHECK SPACE LEFT IN FTAB. */
/*     NIN = NUMBER OF INTERPOLATED SECTIONS AND N = NUMBER OF DEPTH */
/*     LEVELS IN EACH TABLE.  ALL TABLES WILL HAVE SAME NUMBER OF */
/*     DEPTH VALUES. XOFF IS NUMBER OF ENTRIES PER ROW. */
/*     XTIOFF GIVES THE NUMBER OF ITEMS IN THE HEADING OF THE TABLE. */
/* SOURCE fqshrftb.for:2197 */
/*<       isr=nin*(xtioff+n*xoff) >*/
    isr = *nin * (*n * xoff + 32);
/* SOURCE fqshrftb.for:2198 */
/*<       if((ftp+isr).ge.mlft)callkil(10,ftp,eflag) >*/
    if (*ftp + isr >= *mlft) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/*     SET UP POINTERS SO THAT EACH TABLE CAN BE CONSTRUCTED AT EACH */
/*     DEPTH LEVEL.  ISP = SPACE REQUIRED FOR EACH TABLE */
/* SOURCE fqshrftb.for:2205 */
/*<       isp=xtioff+n*xoff >*/
    isp = *n * xoff + 32;
/* SOURCE fqshrftb.for:2206 */
/*<       do100i=1,nin >*/
    feq_gen_i_d_1 = *nin;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:2207 */
/*<       ip(i)=ftp >*/
	ip[feq_gen_i_d_ - 1] = *ftp;
/* SOURCE fqshrftb.for:2208 */
/*<       ftp=ftp+isp >*/
	*ftp += isp;
/* SOURCE fqshrftb.for:2209 */
/*<   100 continue >*/
/* L100: */
    }
/*     CHECK FOR VALIDITY OF INTERPOLATION REQUEST */
/* SOURCE fqshrftb.for:2213 */
/*<       do110i=1,nin >*/
    feq_gen_i_d_1 = *nin;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:2214 */
/*<       xm=x(i) >*/
	xm = x[feq_gen_i_d_];
/* SOURCE fqshrftb.for:2215 */
/*<       if((xl.lt.xm.and.xm.lt.xr).or.(xr.lt.xm.and.xm.lt.xl))goto110 >*/
	if (*xl < xm && xm < *xr || *xr < xm && xm < *xl) {
	    goto L110;
	}
/* SOURCE fqshrftb.for:2216 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE fqshrftb.for:2217 */
/*<        >*/
	feq_gen_io_d__241.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__241);
	feq_gen_r_d_1 = static_cast<double>(*xl) / *sfac;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(xm) / *sfac;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	feq_gen_r_d_3 = static_cast<double>(*xr) / *sfac;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
	feq_gen_i_d_2 = gettbn_(tabl);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_2);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	feq_gen_i_d_3 = gettbn_(tabr);
	feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &feq_gen_i_d_3);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:2220 */
/*<   110 continue >*/
L110:
	;
    }
/*    STORE HEADINGS AND ESTABLISH ADDRESSES FOR ALL THE INTERMEDIATE */
/*     TABLES */
/* SOURCE fqshrftb.for:2226 */
/*<       dx=xr-xl >*/
    dx = static_cast<double>(*xr) - *xl;
/* SOURCE fqshrftb.for:2227 */
/*<       do150j=1,nin >*/
    feq_gen_i_d_1 = *nin;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fqshrftb.for:2228 */
/*<       it=ip(j) >*/
	it = ip[j - 1];
/* SOURCE fqshrftb.for:2229 */
/*<       itab(it)=it+isp-xoff >*/
	itab[it] = it + isp - xoff;
/* SOURCE fqshrftb.for:2230 */
/*<       itab(it+1)=tab(j) >*/
	itab[it + 1] = tab[j];
/* SOURCE fqshrftb.for:2231 */
/*<       itab(it+2)=type >*/
	itab[it + 2] = feq_gen_type_d_;
/* SOURCE fqshrftb.for:2232 */
/*<       itab(it+3)=it+xtioff >*/
	itab[it + 3] = it + 32;
/* SOURCE fqshrftb.for:2233 */
/*<       ftab(it+4)=x(j)/sfac >*/
	ftab[it + 4] = static_cast<double>(x[j]) / *sfac;
/* SOURCE fqshrftb.for:2234 */
/*<       ftab(it+5)=z(j) >*/
	ftab[it + 5] = feq_gen_z_d_[j];
/* SOURCE fqshrftb.for:2235 */
/*<       ftab(it+6)=ymax >*/
	ftab[it + 6] = ymax;
/*       Set the slot depth for the interpolated sections. */
/* SOURCE fqshrftb.for:2238 */
/*<       h=x(j)-xl >*/
	feq_gen_h_d_ = static_cast<double>(x[j]) - *xl;
/* SOURCE fqshrftb.for:2239 */
/*<       fac=h/dx >*/
	fac = feq::section_station_fraction(*xl,*xr,x[j]);
/* SOURCE fqshrftb.for:2240 */
/*<       ftab(it+7)=sdl+fac*(sdr-sdl) >*/
	ftab[it + 7] = static_cast<double>(sdl) + static_cast<double>(fac) * (static_cast<double>(sdr) - sdl);
/*       Set the Easting value as well */
/* SOURCE fqshrftb.for:2243 */
/*<       east=eastl+fac*(eastr-eastl) >*/
	east = eastl + fac * (eastr - eastl);
/*       Set the Northing value as well */
/* SOURCE fqshrftb.for:2246 */
/*<       north=northl+fac*(northr-northl) >*/
	north = northl + fac * (northr - northl);
/* SOURCE fqshrftb.for:2248 */
/*<       callput_dp_in_ft(it+8,east) >*/
	feq_gen_i_d_2 = it + 8;
	feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_2, &east);
/* SOURCE fqshrftb.for:2249 */
/*<       callput_dp_in_ft(it+10,north) >*/
	feq_gen_i_d_2 = it + 10;
	feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_2, &north);
/* SOURCE fqshrftb.for:2251 */
/*<       callput_string_in_ft(it+12,'Interpolated    ') >*/
	feq_gen_i_d_2 = it + 12;
	feq_gen_put_string_in_ft_d_(&feq_gen_i_d_2, const_cast<char*>("Interpolated    "), (ftnlen)16);
/* SOURCE fqshrftb.for:2252 */
/*<       internal_tabid=get_tabid(tab(j)) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tab[j]);
	s_copy(feq_gen_internal_tabid_d_, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:2253 */
/*<       callput_string_in_ft(it+16,internal_tabid) >*/
	feq_gen_i_d_2 = it + 16;
	feq_gen_put_string_in_ft_d_(&feq_gen_i_d_2, feq_gen_internal_tabid_d_, (ftnlen)16);
/*       Set source flag to interpolated */
/* SOURCE fqshrftb.for:2256 */
/*<       itab(it+20)=1 >*/
	itab[it + 20] = 1;
/*       Set the derivative flag */
/* SOURCE fqshrftb.for:2259 */
/*<       if(type.le.25)then >*/
	if (feq_gen_type_d_ <= 25) {
/* SOURCE fqshrftb.for:2260 */
/*<       itab(it+21)=0 >*/
	    itab[it + 21] = 0;
/* SOURCE fqshrftb.for:2261 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:2262 */
/*<       itab(it+21)=offvec(type-10) >*/
	    itab[it + 21] = offcom_1.offvec[feq_gen_type_d_ - 11];
/* SOURCE fqshrftb.for:2263 */
/*<       endif >*/
	}
/*       Transfer the zone, hgrid, vdatum, unitsys data from the left table. */
/*       Values should be the same in all tables at this point in processing! */
/* SOURCE fqshrftb.for:2267 */
/*<       dojj=22,29 >*/
	for (jj = 22; jj <= 29; ++jj) {
/* SOURCE fqshrftb.for:2268 */
/*<       itab(it+jj)=itab(tabl+jj) >*/
	    itab[it + jj] = itab[*tabl + jj];
/* SOURCE fqshrftb.for:2269 */
/*<       enddo >*/
	}
/*       Transfer basis */
/* SOURCE fqshrftb.for:2271 */
/*<       itab(it+30)=itab(tabl+30) >*/
	itab[it + 30] = itab[*tabl + 30];
/* SOURCE fqshrftb.for:2272 */
/*<       itab(it+31)=itab(tabl+31) >*/
	itab[it + 31] = itab[*tabl + 31];
/* SOURCE fqshrftb.for:2274 */
/*<       ij=tab(j) >*/
	ij = tab[j];
/* SOURCE fqshrftb.for:2275 */
/*<       if(ftpnt(ij).eq.0)goto120 >*/
	if (ftablea_1.ftpnt[ij - 1] == 0) {
	    goto L120;
	}
/*         ERROR-DUPLICATE INTERPOLATION TABLE NUMBER */
/* SOURCE fqshrftb.for:2277 */
/*<       callkil(25,ij,eflag) >*/
	kil_(&feq_gen_c_d_25, &ij, eflag);
/* SOURCE fqshrftb.for:2280 */
/*<   120 continue >*/
L120:
/*       Treat all tables as if they could be referenced with */
/*       their internal table number or tabid.  Will not happen */
/*       but is needed to avoid confusion of internal table */
/*       numbers in FEQUTL. */
/* SOURCE fqshrftb.for:2286 */
/*<       ftpnt(tab(j))=it >*/
	ftablea_1.ftpnt[tab[j] - 1] = it;
/* SOURCE fqshrftb.for:2287 */
/*<       nsec(node(j))=it >*/
	nsec[node[j]] = it;
/*       POINT TO LOCATION OF FIRST DEPTH VALUE */
/* SOURCE fqshrftb.for:2290 */
/*<       ip(j)=it+xtioff >*/
	ip[j - 1] = it + 32;
/* SOURCE fqshrftb.for:2291 */
/*<   150 continue >*/
/* L150: */
    }
/*     NOW INTERPOLATE FOR THE BODY OF THE TABLES */
/* SOURCE fqshrftb.for:2295 */
/*<       do200i=1,n >*/
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:2296 */
/*<       yal=yslot_left(i) >*/
	yal = feq_gen_yslot_left_d_[feq_gen_i_d_];
/* SOURCE fqshrftb.for:2297 */
/*<       yar=yslot_right(i) >*/
	yar = feq_gen_yslot_right_d_[feq_gen_i_d_];
/*       FIND THE ELEMENTS ON THE RIGHT AND LEFT.  LOOKUP ROUTINE */
/*       IS BASED ON THE TABLE TYPE AT THAT LOCATION. */
/* SOURCE fqshrftb.for:2302 */
/*<       goto(20,21,22,23,24,25),typel-19-dcrmntl >*/
	switch (typel - 19 - dcrmntl) {
	    case 1:  goto L20;
	    case 2:  goto L21;
	    case 3:  goto L22;
	    case 4:  goto L23;
	    case 5:  goto L24;
	    case 6:  goto L25;
	}
/* SOURCE fqshrftb.for:2304 */
/*<    20 continue >*/
L20:
/* SOURCE fqshrftb.for:2305 */
/*<       callxlkt20(tabl,yal,al,tl,dtl,kl,dkl,bl,dbl) >*/
	xlkt20_(tabl, &yal, &al, &tl, &dtl, &kl, &dkl, &bl, &dbl);
/* SOURCE fqshrftb.for:2309 */
/*<       goto30 >*/
	goto L30;
/* SOURCE fqshrftb.for:2310 */
/*<    21 continue >*/
L21:
/* SOURCE fqshrftb.for:2311 */
/*<       callxlkt21(tabl,yal,al,tl,dtl,ybl,kl,dkl,bl,dbl) >*/
	xlkt21_(tabl, &yal, &al, &tl, &dtl, &ybl, &kl, &dkl, &bl, &dbl);
/* SOURCE fqshrftb.for:2315 */
/*<       goto30 >*/
	goto L30;
/* SOURCE fqshrftb.for:2316 */
/*<    22 continue >*/
L22:
/* SOURCE fqshrftb.for:2317 */
/*<       callxlkt22(tabl,yal,al,tl,dtl,ybl,kl,dkl,bl,dbl,alpl,dalpl,qcl) >*/
	xlkt22_(tabl, &yal, &al, &tl, &dtl, &ybl, &kl, &dkl, &bl, &dbl, &alpl,
		 &dalpl, &qcl);
/* SOURCE fqshrftb.for:2322 */
/*<       goto30 >*/
	goto L30;
/* SOURCE fqshrftb.for:2323 */
/*<    23 continue >*/
L23:
/* SOURCE fqshrftb.for:2324 */
/*<       callxlkt23(tabl,yal,al,tl,dtl,kl,dkl,bl,dbl,mal,dmal,mql,dmql) >*/
	xlkt23_(tabl, &yal, &al, &tl, &dtl, &kl, &dkl, &bl, &dbl, &mal, &dmal,
		 &mql, &dmql);
/* SOURCE fqshrftb.for:2329 */
/*<       goto30 >*/
	goto L30;
/* SOURCE fqshrftb.for:2330 */
/*<    24 continue >*/
L24:
/* SOURCE fqshrftb.for:2331 */
/*<       callxlkt24(tabl,yal,al,tl,dtl,ybl,kl,dkl,bl,dbl,mal,dmal,mql,dmql) >*/
	xlkt24_(tabl, &yal, &al, &tl, &dtl, &ybl, &kl, &dkl, &bl, &dbl, &mal, 
		&dmal, &mql, &dmql);
/* SOURCE fqshrftb.for:2336 */
/*<       goto30 >*/
	goto L30;
/* SOURCE fqshrftb.for:2337 */
/*<    25 continue >*/
L25:
/* SOURCE fqshrftb.for:2338 */
/*<        >*/
	xlkt25_(tabl, &yal, &al, &tl, &dtl, &ybl, &kl, &dkl, &bl, &dbl, &alpl,
		 &dalpl, &qcl, &mal, &dmal, &mql, &dmql);
/* SOURCE fqshrftb.for:2343 */
/*<       goto30 >*/
	goto L30;
/* SOURCE fqshrftb.for:2344 */
/*<    30 continue >*/
L30:
/* SOURCE fqshrftb.for:2346 */
/*<       goto(40,41,42,43,44,45),typer-19-dcrmntr >*/
	switch (typer - 19 - dcrmntr) {
	    case 1:  goto L40;
	    case 2:  goto L41;
	    case 3:  goto L42;
	    case 4:  goto L43;
	    case 5:  goto L44;
	    case 6:  goto L45;
	}
/* SOURCE fqshrftb.for:2348 */
/*<    40 continue >*/
L40:
/* SOURCE fqshrftb.for:2349 */
/*<       callxlkt20(tabr,yar,ar,tr,dtr,kr,dkr,br,dbr) >*/
	xlkt20_(tabr, &yar, &ar, &tr, &dtr, &kr, &dkr, &br, &dbr);
/* SOURCE fqshrftb.for:2353 */
/*<       goto50 >*/
	goto L50;
/* SOURCE fqshrftb.for:2354 */
/*<    41 continue >*/
L41:
/* SOURCE fqshrftb.for:2355 */
/*<       callxlkt21(tabr,yar,ar,tr,dtr,ybr,kr,dkr,br,dbr) >*/
	xlkt21_(tabr, &yar, &ar, &tr, &dtr, &ybr, &kr, &dkr, &br, &dbr);
/* SOURCE fqshrftb.for:2359 */
/*<       goto50 >*/
	goto L50;
/* SOURCE fqshrftb.for:2360 */
/*<    42 continue >*/
L42:
/* SOURCE fqshrftb.for:2361 */
/*<       callxlkt22(tabr,yar,ar,tr,dtr,ybr,kr,dkr,br,dbr,alpr,dalpr,qcr) >*/
	xlkt22_(tabr, &yar, &ar, &tr, &dtr, &ybr, &kr, &dkr, &br, &dbr, &alpr,
		 &dalpr, &qcr);
/* SOURCE fqshrftb.for:2366 */
/*<       goto50 >*/
	goto L50;
/* SOURCE fqshrftb.for:2367 */
/*<    43 continue >*/
L43:
/* SOURCE fqshrftb.for:2368 */
/*<       callxlkt23(tabr,yar,ar,tr,dtr,kr,dkr,br,dbr,mar,dmar,mqr,dmqr) >*/
	xlkt23_(tabr, &yar, &ar, &tr, &dtr, &kr, &dkr, &br, &dbr, &mar, &dmar,
		 &mqr, &dmqr);
/* SOURCE fqshrftb.for:2373 */
/*<       goto50 >*/
	goto L50;
/* SOURCE fqshrftb.for:2374 */
/*<    44 continue >*/
L44:
/* SOURCE fqshrftb.for:2375 */
/*<       callxlkt24(tabr,yar,ar,tr,dtr,ybr,kr,dkr,br,dbr,mar,dmar,mqr,dmqr) >*/
	xlkt24_(tabr, &yar, &ar, &tr, &dtr, &ybr, &kr, &dkr, &br, &dbr, &mar, 
		&dmar, &mqr, &dmqr);
/* SOURCE fqshrftb.for:2380 */
/*<       goto50 >*/
	goto L50;
/* SOURCE fqshrftb.for:2381 */
/*<    45 continue >*/
L45:
/* SOURCE fqshrftb.for:2382 */
/*<        >*/
	xlkt25_(tabr, &yar, &ar, &tr, &dtr, &ybr, &kr, &dkr, &br, &dbr, &alpr,
		 &dalpr, &qcr, &mar, &dmar, &mqr, &dmqr);
/* SOURCE fqshrftb.for:2387 */
/*<       goto50 >*/
	goto L50;
/* SOURCE fqshrftb.for:2388 */
/*<    50 continue >*/
L50:
/* SOURCE fqshrftb.for:2390 */
/*<       kl=sqrt(kl) >*/
	kl = sqrt(kl);
/* SOURCE fqshrftb.for:2391 */
/*<       kr=sqrt(kr) >*/
	kr = sqrt(kr);
/*       adjust derivatives as well */
/* SOURCE fqshrftb.for:2393 */
/*<       if(kl.gt.0.0)then >*/
	if (kl > (float)0.) {
/* SOURCE fqshrftb.for:2394 */
/*<       dkl=0.5*dkl/kl >*/
	    dkl = static_cast<double>(static_cast<double>(dkl) * (float).5) / kl;
/* SOURCE fqshrftb.for:2395 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:2396 */
/*<       dkl=0.0 >*/
	    dkl = (float)0.;
/* SOURCE fqshrftb.for:2397 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:2398 */
/*<       if(kr.gt.0.0)then >*/
	if (kr > (float)0.) {
/* SOURCE fqshrftb.for:2399 */
/*<       dkr=0.5*dkr/kr >*/
	    dkr = static_cast<double>(static_cast<double>(dkr) * (float).5) / kr;
/* SOURCE fqshrftb.for:2400 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:2401 */
/*<       dkr=0.0 >*/
	    dkr = (float)0.;
/* SOURCE fqshrftb.for:2402 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:2403 */
/*<       do160j=1,nin >*/
	feq_gen_i_d_2 = *nin;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE fqshrftb.for:2404 */
/*<       it=ip(j) >*/
	    it = ip[j - 1];
/* SOURCE fqshrftb.for:2405 */
/*<       h=x(j)-xl >*/
	    feq_gen_h_d_ = static_cast<double>(x[j]) - *xl;
/* SOURCE fqshrftb.for:2406 */
/*<       fac=h/dx >*/
	    fac = feq::section_station_fraction(*xl,*xr,x[j]);
/*         DO THE CORE ELEMENTS THAT ARE COMMON TO ALL TABLES AND */
/*         STORE THEM. */
/* SOURCE fqshrftb.for:2410 */
/*<       t=tl+fac*(tr-tl) >*/
	    t = static_cast<double>(tl) + static_cast<double>(fac) * (static_cast<double>(tr) - tl);
/* SOURCE fqshrftb.for:2411 */
/*<       a=al+fac*(ar-al) >*/
	    a = static_cast<double>(al) + static_cast<double>(fac) * (static_cast<double>(ar) - al);
/* SOURCE fqshrftb.for:2412 */
/*<       k=kl+fac*(kr-kl) >*/
	    k = static_cast<double>(kl) + static_cast<double>(fac) * (static_cast<double>(kr) - kl);
/* SOURCE fqshrftb.for:2413 */
/*<       b=bl+fac*(br-bl) >*/
	    b = static_cast<double>(bl) + static_cast<double>(fac) * (static_cast<double>(br) - bl);
/* SOURCE fqshrftb.for:2414 */
/*<       ftab(it)=yal+fac*(yar-yal) >*/
	    ftab[it] = static_cast<double>(yal) + static_cast<double>(fac) * (static_cast<double>(yar) - yal);
/* SOURCE fqshrftb.for:2415 */
/*<       ftab(it+1)=t >*/
	    ftab[it + 1] = t;
/* SOURCE fqshrftb.for:2416 */
/*<       ftab(it+2)=a >*/
	    ftab[it + 2] = a;
/* SOURCE fqshrftb.for:2417 */
/*<       ftab(it+3)=k >*/
	    ftab[it + 3] = k;
/* SOURCE fqshrftb.for:2418 */
/*<       ftab(it+4)=b >*/
	    ftab[it + 4] = b;
/*         THE CORE SET HAS BEEN DONE.  NOW DO THE TABLES THAT CONTAIN */
/*         ADDITIONAL ELEMENTS */
/* SOURCE fqshrftb.for:2423 */
/*<       if(jid(type-dcrmnt).eq.1)then >*/
	    if (jid[feq_gen_type_d_ - dcrmnt - 1] == 1) {
/*           FIRST MOMENT EXISTS IN THESE TABLES. */
/* SOURCE fqshrftb.for:2425 */
/*<       yb=ybl+fac*(ybr-ybl) >*/
		yb = static_cast<double>(ybl) + static_cast<double>(fac) * (static_cast<double>(ybr) - ybl);
/* SOURCE fqshrftb.for:2426 */
/*<       ftab(it+5)=yb >*/
		ftab[it + 5] = yb;
/* SOURCE fqshrftb.for:2427 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:2429 */
/*<       if(qcid(type-dcrmnt).eq.1)then >*/
	    if (qcid[feq_gen_type_d_ - dcrmnt - 1] == 1) {
/*           ALP AND QC EXISTS IN THESE TABLES. */
/* SOURCE fqshrftb.for:2431 */
/*<       alp=alpl+fac*(alpr-alpl) >*/
		alp = static_cast<double>(alpl) + static_cast<double>(fac) * (static_cast<double>(alpr) - alpl);
/* SOURCE fqshrftb.for:2432 */
/*<       qc=qcl+fac*(qcr-qcl) >*/
		qc = static_cast<double>(qcl) + static_cast<double>(fac) * (static_cast<double>(qcr) - qcl);
/* SOURCE fqshrftb.for:2433 */
/*<       ftab(it+6)=alp >*/
		ftab[it + 6] = alp;
/* SOURCE fqshrftb.for:2434 */
/*<       ftab(it+7)=qc >*/
		ftab[it + 7] = qc;
/* SOURCE fqshrftb.for:2435 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:2437 */
/*<       if(type-dcrmnt.ge.23)then >*/
	    if (feq_gen_type_d_ - dcrmnt >= 23) {
/*           WE HAVE THE WEIGHT COEFFICIENTS TO INTERPOLATE. */
/* SOURCE fqshrftb.for:2440 */
/*<       ma=mal+fac*(mar-mal) >*/
		ma = static_cast<double>(mal) + static_cast<double>(fac) * (static_cast<double>(mar) - mal);
/* SOURCE fqshrftb.for:2441 */
/*<       mq=mql+fac*(mqr-mql) >*/
		mq = static_cast<double>(mql) + static_cast<double>(fac) * (static_cast<double>(mqr) - mql);
/* SOURCE fqshrftb.for:2443 */
/*<       if(type-dcrmnt.eq.23)then >*/
		if (feq_gen_type_d_ - dcrmnt == 23) {
/* SOURCE fqshrftb.for:2444 */
/*<       ftab(it+5)=ma >*/
		    ftab[it + 5] = ma;
/* SOURCE fqshrftb.for:2445 */
/*<       ftab(it+6)=mq >*/
		    ftab[it + 6] = mq;
/* SOURCE fqshrftb.for:2446 */
/*<       elseif(type-dcrmnt.eq.24)then >*/
		} else if (feq_gen_type_d_ - dcrmnt == 24) {
/* SOURCE fqshrftb.for:2447 */
/*<       ftab(it+6)=ma >*/
		    ftab[it + 6] = ma;
/* SOURCE fqshrftb.for:2448 */
/*<       ftab(it+7)=mq >*/
		    ftab[it + 7] = mq;
/* SOURCE fqshrftb.for:2449 */
/*<       elseif(type-dcrmnt.eq.25)then >*/
		} else if (feq_gen_type_d_ - dcrmnt == 25) {
/* SOURCE fqshrftb.for:2450 */
/*<       ftab(it+8)=ma >*/
		    ftab[it + 8] = ma;
/* SOURCE fqshrftb.for:2451 */
/*<       ftab(it+9)=mq >*/
		    ftab[it + 9] = mq;
/* SOURCE fqshrftb.for:2452 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:2453 */
/*<       endif >*/
	    }
/*         Process extra derivatives. */
/* SOURCE fqshrftb.for:2456 */
/*<       if(type.ge.30)then >*/
	    if (feq_gen_type_d_ >= 30) {
/* SOURCE fqshrftb.for:2457 */
/*<       feql_select4=type >*/
		feq_gen_feql_select4_d_ = feq_gen_type_d_;
/* SOURCE fqshrftb.for:2457 */
/*<       if(feql_select4.eq.30)then >*/
		if (feq_gen_feql_select4_d_ == 30) {
/* SOURCE fqshrftb.for:2460 */
/*<       dk=dkl+fac*(dkr-dkl) >*/
		    dk = static_cast<double>(dkl) + static_cast<double>(fac) * (static_cast<double>(dkr) - dkl);
/* SOURCE fqshrftb.for:2461 */
/*<       db=dbl+fac*(dbr-dbl) >*/
		    db = static_cast<double>(dbl) + static_cast<double>(fac) * (static_cast<double>(dbr) - dbl);
/* SOURCE fqshrftb.for:2462 */
/*<       if(abs(dk).lt.1.01e-9)dk=0.0 >*/
		    if (dabs(dk) < (float)1.01e-9) {
			dk = (float)0.;
		    }
/* SOURCE fqshrftb.for:2463 */
/*<       if(abs(db).lt.1.01e-9)db=0.0 >*/
		    if (dabs(db) < (float)1.01e-9) {
			db = (float)0.;
		    }
/* SOURCE fqshrftb.for:2464 */
/*<       ftab(it+5)=dk >*/
		    ftab[it + 5] = dk;
/* SOURCE fqshrftb.for:2465 */
/*<       ftab(it+6)=db >*/
		    ftab[it + 6] = db;
/* SOURCE fqshrftb.for:2457 */
/*<       elseif(feql_select4.eq.31)then >*/
		} else if (feq_gen_feql_select4_d_ == 31) {
/* SOURCE fqshrftb.for:2468 */
/*<       dk=dkl+fac*(dkr-dkl) >*/
		    dk = static_cast<double>(dkl) + static_cast<double>(fac) * (static_cast<double>(dkr) - dkl);
/* SOURCE fqshrftb.for:2469 */
/*<       db=dbl+fac*(dbr-dbl) >*/
		    db = static_cast<double>(dbl) + static_cast<double>(fac) * (static_cast<double>(dbr) - dbl);
/* SOURCE fqshrftb.for:2470 */
/*<       if(abs(dk).lt.1.01e-9)dk=0.0 >*/
		    if (dabs(dk) < (float)1.01e-9) {
			dk = (float)0.;
		    }
/* SOURCE fqshrftb.for:2471 */
/*<       if(abs(db).lt.1.01e-9)db=0.0 >*/
		    if (dabs(db) < (float)1.01e-9) {
			db = (float)0.;
		    }
/* SOURCE fqshrftb.for:2472 */
/*<       ftab(it+6)=dk >*/
		    ftab[it + 6] = dk;
/* SOURCE fqshrftb.for:2473 */
/*<       ftab(it+7)=db >*/
		    ftab[it + 7] = db;
/* SOURCE fqshrftb.for:2457 */
/*<       elseif(feql_select4.eq.32)then >*/
		} else if (feq_gen_feql_select4_d_ == 32) {
/* SOURCE fqshrftb.for:2475 */
/*<       dk=dkl+fac*(dkr-dkl) >*/
		    dk = static_cast<double>(dkl) + static_cast<double>(fac) * (static_cast<double>(dkr) - dkl);
/* SOURCE fqshrftb.for:2476 */
/*<       db=dbl+fac*(dbr-dbl) >*/
		    db = static_cast<double>(dbl) + static_cast<double>(fac) * (static_cast<double>(dbr) - dbl);
/* SOURCE fqshrftb.for:2477 */
/*<       dalp=dalpl+fac*(dalpr-dalpl) >*/
		    dalp = static_cast<double>(dalpl) + static_cast<double>(fac) * (static_cast<double>(dalpr) - dalpl);
/* SOURCE fqshrftb.for:2478 */
/*<       if(abs(dk).lt.1.01e-9)dk=0.0 >*/
		    if (dabs(dk) < (float)1.01e-9) {
			dk = (float)0.;
		    }
/* SOURCE fqshrftb.for:2479 */
/*<       if(abs(db).lt.1.01e-9)db=0.0 >*/
		    if (dabs(db) < (float)1.01e-9) {
			db = (float)0.;
		    }
/* SOURCE fqshrftb.for:2480 */
/*<       if(abs(dalp).lt.1.01e-9)dalp=0.0 >*/
		    if (dabs(dalp) < (float)1.01e-9) {
			dalp = (float)0.;
		    }
/* SOURCE fqshrftb.for:2481 */
/*<       ftab(it+8)=dk >*/
		    ftab[it + 8] = dk;
/* SOURCE fqshrftb.for:2482 */
/*<       ftab(it+9)=db >*/
		    ftab[it + 9] = db;
/* SOURCE fqshrftb.for:2483 */
/*<       ftab(it+10)=dalp >*/
		    ftab[it + 10] = dalp;
/* SOURCE fqshrftb.for:2457 */
/*<       elseif(feql_select4.eq.33)then >*/
		} else if (feq_gen_feql_select4_d_ == 33) {
/* SOURCE fqshrftb.for:2485 */
/*<       dk=dkl+fac*(dkr-dkl) >*/
		    dk = static_cast<double>(dkl) + static_cast<double>(fac) * (static_cast<double>(dkr) - dkl);
/* SOURCE fqshrftb.for:2486 */
/*<       db=dbl+fac*(dbr-dbl) >*/
		    db = static_cast<double>(dbl) + static_cast<double>(fac) * (static_cast<double>(dbr) - dbl);
/* SOURCE fqshrftb.for:2487 */
/*<       dma=dmal+fac*(dmar-dmal) >*/
		    dma = static_cast<double>(dmal) + static_cast<double>(fac) * (static_cast<double>(dmar) - dmal);
/* SOURCE fqshrftb.for:2488 */
/*<       dmq=dmql+fac*(dmqr-dmql) >*/
		    dmq = static_cast<double>(dmql) + static_cast<double>(fac) * (static_cast<double>(dmqr) - dmql);
/* SOURCE fqshrftb.for:2489 */
/*<       if(abs(dk).lt.1.01e-9)dk=0.0 >*/
		    if (dabs(dk) < (float)1.01e-9) {
			dk = (float)0.;
		    }
/* SOURCE fqshrftb.for:2490 */
/*<       if(abs(db).lt.1.01e-9)db=0.0 >*/
		    if (dabs(db) < (float)1.01e-9) {
			db = (float)0.;
		    }
/* SOURCE fqshrftb.for:2491 */
/*<       if(abs(dma).lt.1.01e-9)dma=0.0 >*/
		    if (dabs(dma) < (float)1.01e-9) {
			dma = (float)0.;
		    }
/* SOURCE fqshrftb.for:2492 */
/*<       if(abs(dmq).lt.1.01e-9)dmq=0.0 >*/
		    if (dabs(dmq) < (float)1.01e-9) {
			dmq = (float)0.;
		    }
/* SOURCE fqshrftb.for:2493 */
/*<       ftab(it+7)=dk >*/
		    ftab[it + 7] = dk;
/* SOURCE fqshrftb.for:2494 */
/*<       ftab(it+8)=db >*/
		    ftab[it + 8] = db;
/* SOURCE fqshrftb.for:2495 */
/*<       ftab(it+9)=dma >*/
		    ftab[it + 9] = dma;
/* SOURCE fqshrftb.for:2496 */
/*<       ftab(it+10)=dmq >*/
		    ftab[it + 10] = dmq;
/* SOURCE fqshrftb.for:2457 */
/*<       elseif(feql_select4.eq.34)then >*/
		} else if (feq_gen_feql_select4_d_ == 34) {
/* SOURCE fqshrftb.for:2498 */
/*<       dk=dkl+fac*(dkr-dkl) >*/
		    dk = static_cast<double>(dkl) + static_cast<double>(fac) * (static_cast<double>(dkr) - dkl);
/* SOURCE fqshrftb.for:2499 */
/*<       db=dbl+fac*(dbr-dbl) >*/
		    db = static_cast<double>(dbl) + static_cast<double>(fac) * (static_cast<double>(dbr) - dbl);
/* SOURCE fqshrftb.for:2500 */
/*<       dma=dmal+fac*(dmar-dmal) >*/
		    dma = static_cast<double>(dmal) + static_cast<double>(fac) * (static_cast<double>(dmar) - dmal);
/* SOURCE fqshrftb.for:2501 */
/*<       dmq=dmql+fac*(dmqr-dmql) >*/
		    dmq = static_cast<double>(dmql) + static_cast<double>(fac) * (static_cast<double>(dmqr) - dmql);
/* SOURCE fqshrftb.for:2502 */
/*<       if(abs(dk).lt.1.01e-9)dk=0.0 >*/
		    if (dabs(dk) < (float)1.01e-9) {
			dk = (float)0.;
		    }
/* SOURCE fqshrftb.for:2503 */
/*<       if(abs(db).lt.1.01e-9)db=0.0 >*/
		    if (dabs(db) < (float)1.01e-9) {
			db = (float)0.;
		    }
/* SOURCE fqshrftb.for:2504 */
/*<       if(abs(dma).lt.1.01e-9)dma=0.0 >*/
		    if (dabs(dma) < (float)1.01e-9) {
			dma = (float)0.;
		    }
/* SOURCE fqshrftb.for:2505 */
/*<       if(abs(dmq).lt.1.01e-9)dmq=0.0 >*/
		    if (dabs(dmq) < (float)1.01e-9) {
			dmq = (float)0.;
		    }
/* SOURCE fqshrftb.for:2506 */
/*<       ftab(it+8)=dk >*/
		    ftab[it + 8] = dk;
/* SOURCE fqshrftb.for:2507 */
/*<       ftab(it+9)=db >*/
		    ftab[it + 9] = db;
/* SOURCE fqshrftb.for:2508 */
/*<       ftab(it+10)=dma >*/
		    ftab[it + 10] = dma;
/* SOURCE fqshrftb.for:2509 */
/*<       ftab(it+11)=dmq >*/
		    ftab[it + 11] = dmq;
/* SOURCE fqshrftb.for:2457 */
/*<       elseif(feql_select4.eq.35)then >*/
		} else if (feq_gen_feql_select4_d_ == 35) {
/* SOURCE fqshrftb.for:2511 */
/*<       dk=dkl+fac*(dkr-dkl) >*/
		    dk = static_cast<double>(dkl) + static_cast<double>(fac) * (static_cast<double>(dkr) - dkl);
/* SOURCE fqshrftb.for:2512 */
/*<       db=dbl+fac*(dbr-dbl) >*/
		    db = static_cast<double>(dbl) + static_cast<double>(fac) * (static_cast<double>(dbr) - dbl);
/* SOURCE fqshrftb.for:2513 */
/*<       dalp=dalpl+fac*(dalpr-dalpl) >*/
		    dalp = static_cast<double>(dalpl) + static_cast<double>(fac) * (static_cast<double>(dalpr) - dalpl);
/* SOURCE fqshrftb.for:2514 */
/*<       dma=dmal+fac*(dmar-dmal) >*/
		    dma = static_cast<double>(dmal) + static_cast<double>(fac) * (static_cast<double>(dmar) - dmal);
/* SOURCE fqshrftb.for:2515 */
/*<       dmq=dmql+fac*(dmqr-dmql) >*/
		    dmq = static_cast<double>(dmql) + static_cast<double>(fac) * (static_cast<double>(dmqr) - dmql);
/* SOURCE fqshrftb.for:2516 */
/*<       if(abs(dk).lt.1.01e-9)dk=0.0 >*/
		    if (dabs(dk) < (float)1.01e-9) {
			dk = (float)0.;
		    }
/* SOURCE fqshrftb.for:2517 */
/*<       if(abs(db).lt.1.01e-9)db=0.0 >*/
		    if (dabs(db) < (float)1.01e-9) {
			db = (float)0.;
		    }
/* SOURCE fqshrftb.for:2518 */
/*<       if(abs(dalp).lt.1.01e-9)dalp=0.0 >*/
		    if (dabs(dalp) < (float)1.01e-9) {
			dalp = (float)0.;
		    }
/* SOURCE fqshrftb.for:2519 */
/*<       if(abs(dma).lt.1.01e-9)dma=0.0 >*/
		    if (dabs(dma) < (float)1.01e-9) {
			dma = (float)0.;
		    }
/* SOURCE fqshrftb.for:2520 */
/*<       if(abs(dmq).lt.1.01e-9)dmq=0.0 >*/
		    if (dabs(dmq) < (float)1.01e-9) {
			dmq = (float)0.;
		    }
/* SOURCE fqshrftb.for:2521 */
/*<       ftab(it+10)=dk >*/
		    ftab[it + 10] = dk;
/* SOURCE fqshrftb.for:2522 */
/*<       ftab(it+11)=db >*/
		    ftab[it + 11] = db;
/* SOURCE fqshrftb.for:2523 */
/*<       ftab(it+12)=dma >*/
		    ftab[it + 12] = dma;
/* SOURCE fqshrftb.for:2524 */
/*<       ftab(it+13)=dmq >*/
		    ftab[it + 13] = dmq;
/* SOURCE fqshrftb.for:2525 */
/*<       ftab(it+14)=dalp >*/
		    ftab[it + 14] = dalp;
/* SOURCE fqshrftb.for:2526 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:2527 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:2528 */
/*<       ip(j)=ip(j)+xoff >*/
	    ip[j - 1] += xoff;
/* SOURCE fqshrftb.for:2530 */
/*<   160 continue >*/
/* L160: */
	}
/* SOURCE fqshrftb.for:2531 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE fqshrftb.for:2532 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:2533 */
/*<       end >*/
} /* interp_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:2537 */
/*<       subroutinekil(icode,n,iflag) >*/
/* Subroutine */ int kil_(integer *icode, integer *n, integer *iflag)
{
    /* Initialized data */

    static char mesg[72*51+1] = " Branch number out of range                \
                              Node on a branch outside valid range          \
                          Node on a branch out of sequence or a duplicate   \
                      Upstream exterior node number out of range            \
                  Downstream exterior node number out of range              \
              AVAILABLE MESSAGE                                             \
          Invalid device type for a control structure                       \
      Message available                                                     \
  Internal table number out of valid range                                Fu\
nction table space exceeded                                           Invali\
d code for Network Matrix Control                                 AVAILABLE \
MESSAGE                                                       Network Matrix\
 Control space exceeded                                   Number of nodes at\
 a junction > 9 or < 2                                Unknown branch number \
in Ntwrk Mtrx Cntrl input                         Type must be 1,or 2 for a \
forced boundary                               Number of reservoir inflow nod\
es must be 1                              Type for point flows > 2 or < 1   \
                                      Too many point flows given            \
                                  MESSAGE AVAILABLE                         \
                              Message available                             \
                          The nodes for head must be distinct               \
                      The node for flow must equal one of the head nodes    \
                  Reservoir node duplicates an existing node                \
              Duplicate function table id                                   \
          Message available                                                 \
      Too many nodes                                                        \
  Point flow invalid for upstream node                                    To\
o many branches                                                       Too ma\
ny exterior nodes                                                 Invalid op\
eration block number in CHKEX                                 Level pool res\
ervoir inflow node is not free or is in use elsewhere.    Free node on a dum\
my branch is not free or is in use elsewhere.        AVAILABLE MESSAGE      \
                                                  Invalid print out option  \
                                              Point flows no longer supporte\
d                                         Invalid option for diffuse flows  \
                                      Invalid option for wind loading       \
                                  Message available                         \
                              Message available                             \
                          Special Operation Block number out of range       \
                      Invalid option for Special Operation Block            \
                  Exterior node used as a flow node more than once          \
              Exterior node appears on more than one branch                 \
          Invalid slope source for channel control:-1,0,1, are valid        \
      This node matches another when nodes must be distinct.                \
 Message available                                                       Mes\
sage available                                                        Messag\
e available                                                       Invalid di\
rection: 1 or -1 are valid.                                   Branch has alr\
eady appeared in Ntwrk Mtrx Cntrl input.                 ";

    /* Format strings */
    static char fmt_10000[] = "(\0020\002,\002*ERR:\002,i2,\002*\002)";
    static char fmt_10100[] = "(\002 REFERENCE VALUE= \002,i10)";
    static char fmt_10102[] = "(\002 Table id= \002,a)";
    static char fmt_10200[] = "(a)";
    static char fmt_10300[] = "(/,\002 PREVIOUS ERROR FORCES CESSATION OF PR\
OCESSING.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__300 = { 0, 0, 0, fmt_10000, 0 };
    static cilist feq_gen_io_d__301 = { 0, 0, 0, fmt_10102, 0 };
    static cilist feq_gen_io_d__302 = { 0, 0, 0, fmt_10100, 0 };
    static cilist feq_gen_io_d__303 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__304 = { 0, 0, 0, fmt_10200, 0 };
    static cilist feq_gen_io_d__305 = { 0, 0, 0, fmt_10300, 0 };


/*     + + + PURPOSE + + + */
/*     Prints out error messages and sets a flag */
/*     and adjusts the value of N */
/* SOURCE fqshrftb.for:2545 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:2547 */
/*<       integericode,iflag,n >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ICODE  - code number for the error message to output */
/*     N      - reference value to report and adjust */
/*     IFLAG  - error flag */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:2555 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/*     Called program units */
/* SOURCE fqshrftb.for:2558 */
/*<       characterget_tabid*16 >*/
/* SOURCE fqshrftb.for:2559 */
/*<       externalget_tabid >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:2562 */
/*<       charactermesg(51)*72 >*/
/* SOURCE fqshrftb.for:2563 */
/*<       savemesg >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:2566 */
/*<       intrinsicabs >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:2569 */
/*<       datamesg(1)/' Branch number out of range'/ >*/
/* SOURCE fqshrftb.for:2570 */
/*<       datamesg(2)/' Node on a branch outside valid range'/ >*/
/* SOURCE fqshrftb.for:2571 */
/*<       datamesg(3)/' Node on a branch out of sequence or a duplicate'/ >*/
/* SOURCE fqshrftb.for:2572 */
/*<       datamesg(4)/' Upstream exterior node number out of range'/ >*/
/* SOURCE fqshrftb.for:2573 */
/*<       datamesg(5)/' Downstream exterior node number out of range'/ >*/
/* SOURCE fqshrftb.for:2574 */
/*<       datamesg(6)/' AVAILABLE MESSAGE '/ >*/
/* SOURCE fqshrftb.for:2575 */
/*<       datamesg(7)/' Invalid device type for a control structure'/ >*/
/* SOURCE fqshrftb.for:2576 */
/*<       datamesg(8)/' Message available'/ >*/
/* SOURCE fqshrftb.for:2577 */
/*<       datamesg(9)/' Internal table number out of valid range'/ >*/
/* SOURCE fqshrftb.for:2578 */
/*<       datamesg(10)/' Function table space exceeded'/ >*/
/* SOURCE fqshrftb.for:2579 */
/*<       datamesg(11)/' Invalid code for Network Matrix Control'/ >*/
/* SOURCE fqshrftb.for:2580 */
/*<       datamesg(12)/' AVAILABLE MESSAGE'/ >*/
/* SOURCE fqshrftb.for:2581 */
/*<       datamesg(13)/' Network Matrix Control space exceeded'/ >*/
/* SOURCE fqshrftb.for:2582 */
/*<       datamesg(14)/' Number of nodes at a junction > 9 or < 2'/ >*/
/* SOURCE fqshrftb.for:2583 */
/*<       datamesg(15)/' Unknown branch number in Ntwrk Mtrx Cntrl input'/ >*/
/* SOURCE fqshrftb.for:2584 */
/*<       datamesg(16)/' Type must be 1,or 2 for a forced boundary'/ >*/
/* SOURCE fqshrftb.for:2585 */
/*<       datamesg(17)/' Number of reservoir inflow nodes must be 1'/ >*/
/* SOURCE fqshrftb.for:2586 */
/*<       datamesg(18)/' Type for point flows > 2 or < 1'/ >*/
/* SOURCE fqshrftb.for:2587 */
/*<       datamesg(19)/' Too many point flows given'/ >*/
/* SOURCE fqshrftb.for:2588 */
/*<       datamesg(20)/' MESSAGE AVAILABLE'/ >*/
/* SOURCE fqshrftb.for:2589 */
/*<       datamesg(21)/' Message available'/ >*/
/* SOURCE fqshrftb.for:2590 */
/*<       datamesg(22)/' The nodes for head must be distinct'/ >*/
/* SOURCE fqshrftb.for:2591 */
/*<        >*/
/* SOURCE fqshrftb.for:2593 */
/*<       datamesg(24)/' Reservoir node duplicates an existing node'/ >*/
/* SOURCE fqshrftb.for:2594 */
/*<       datamesg(25)/' Duplicate function table id'/ >*/
/* SOURCE fqshrftb.for:2595 */
/*<       datamesg(26)/' Message available'/ >*/
/* SOURCE fqshrftb.for:2596 */
/*<       datamesg(27)/' Too many nodes'/ >*/
/* SOURCE fqshrftb.for:2597 */
/*<       datamesg(28)/' Point flow invalid for upstream node'/ >*/
/* SOURCE fqshrftb.for:2598 */
/*<       datamesg(29)/' Too many branches'/ >*/
/* SOURCE fqshrftb.for:2599 */
/*<       datamesg(30)/' Too many exterior nodes'/ >*/
/* SOURCE fqshrftb.for:2600 */
/*<       datamesg(31)/' Invalid operation block number in CHKEX'/ >*/
/* SOURCE fqshrftb.for:2601 */
/*<        >*/
/* SOURCE fqshrftb.for:2604 */
/*<        >*/
/* SOURCE fqshrftb.for:2607 */
/*<       datamesg(34)/'AVAILABLE MESSAGE'/ >*/
/* SOURCE fqshrftb.for:2608 */
/*<       datamesg(35)/' Invalid print out option'/ >*/
/* SOURCE fqshrftb.for:2609 */
/*<       datamesg(36)/' Point flows no longer supported'/ >*/
/* SOURCE fqshrftb.for:2610 */
/*<       datamesg(37)/' Invalid option for diffuse flows'/ >*/
/* SOURCE fqshrftb.for:2611 */
/*<       datamesg(38)/' Invalid option for wind loading'/ >*/
/* SOURCE fqshrftb.for:2612 */
/*<       datamesg(39)/' Message available'/ >*/
/* SOURCE fqshrftb.for:2613 */
/*<       datamesg(40)/' Message available'/ >*/
/* SOURCE fqshrftb.for:2614 */
/*<       datamesg(41)/' Special Operation Block number out of range'/ >*/
/* SOURCE fqshrftb.for:2615 */
/*<       datamesg(42)/' Invalid option for Special Operation Block'/ >*/
/* SOURCE fqshrftb.for:2616 */
/*<       datamesg(43)/' Exterior node used as a flow node more than once'/ >*/
/* SOURCE fqshrftb.for:2618 */
/*<       datamesg(44)/' Exterior node appears on more than one branch'/ >*/
/* SOURCE fqshrftb.for:2619 */
/*<        >*/
/* SOURCE fqshrftb.for:2621 */
/*<        >*/
/* SOURCE fqshrftb.for:2623 */
/*<       datamesg(47)/'Message available'/ >*/
/* SOURCE fqshrftb.for:2624 */
/*<       datamesg(48)/'Message available'/ >*/
/* SOURCE fqshrftb.for:2625 */
/*<       datamesg(49)/' Message available'/ >*/
/* SOURCE fqshrftb.for:2626 */
/*<       datamesg(50)/' Invalid direction: 1 or -1 are valid.'/ >*/
/* SOURCE fqshrftb.for:2627 */
/*<        >*/
/* SOURCE fqshrftb.for:2631 */
/*< 10000 format('0','*ERR:',i2,'*') >*/
/* L10000: */
/* SOURCE fqshrftb.for:2632 */
/*< 10100 format(' REFERENCE VALUE= ',i10) >*/
/* L10100: */
/* SOURCE fqshrftb.for:2633 */
/*< 10102 format(' Table id= ',a) >*/
/* L10102: */
/* SOURCE fqshrftb.for:2634 */
/*< 10200 format(a) >*/
/* L10200: */
/* SOURCE fqshrftb.for:2635 */
/*< 10300 format(/,' PREVIOUS ERROR FORCES CESSATION OF PROCESSING.') >*/
/* L10300: */
/* *********************************************************************** */
/*     NOTE: DO NOT USE ICODE GREATER THAN 60 FOR SUBROUTINE */
/*     KIL. OTHERWISE DUPLICATE NUMBERS WILL APPEAR FOR ERROR */
/*     MESSAGES. */
/* SOURCE fqshrftb.for:2641 */
/*<       write(stdout,10000)abs(icode) >*/
    feq_gen_io_d__300.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__300);
    feq_gen_i_d_1 = abs(*icode);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE fqshrftb.for:2643 */
/*<       iflag=iflag+1 >*/
    ++(*iflag);
/* SOURCE fqshrftb.for:2644 */
/*<       if(abs(icode).eq.25)then >*/
    if (abs(*icode) == 25) {
/* SOURCE fqshrftb.for:2645 */
/*<       write(stdout,10102)get_tabid(n) >*/
	feq_gen_io_d__301.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__301);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, n);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:2646 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:2647 */
/*<       write(stdout,10100)n >*/
	feq_gen_io_d__302.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__302);
	do_fio(&feq_gen_c_d_1, (char *)&(*n), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:2648 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:2649 */
/*<       n=1 >*/
    *n = 1;
/* SOURCE fqshrftb.for:2651 */
/*<       if(icode.lt.0.or.icode.gt.51)then >*/
    if (*icode < 0 || *icode > 51) {
/* SOURCE fqshrftb.for:2652 */
/*<       write(stdout,*)' *BUG:01* INVALID ICODE IN KIL. CODE=',icode >*/
	feq_gen_io_d__303.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__303);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:01* INVALID ICODE IN KIL. CODE="), (ftnlen)
		37);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*icode), (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE fqshrftb.for:2653 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:2654 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:2655 */
/*<       write(stdout,10200)mesg(icode) >*/
    feq_gen_io_d__304.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__304);
    do_fio(&feq_gen_c_d_1, mesg + (*icode - 1) * 72, (ftnlen)72);
    e_wsfe();
/* SOURCE fqshrftb.for:2656 */
/*<       if(icode.eq.10.or.icode.eq.13)then >*/
    if (*icode == 10 || *icode == 13) {
/* SOURCE fqshrftb.for:2657 */
/*<       write(stdout,10300) >*/
	feq_gen_io_d__305.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__305);
	e_wsfe();
/* SOURCE fqshrftb.for:2658 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:2659 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:2660 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:2661 */
/*<       end >*/
} /* kil_ */




/* SOURCE fqshrftb.for:2665 */
/*<       subroutinelktab(adrs,arga,sklt,func,ntab,pdv) >*/
/* Subroutine */ int lktab_(integer *adrs, real *arga, integer *sklt, real *
	func, integer *ntab, real *pdv)
{
    /* Initialized data */

    static integer step[5] = { 0,2,3,3,3 };

    /* Format strings */
    static char fmt_50[] = "(/,\002*BUG:XXX* Invalid TYPE=\002,i5,\002 in LK\
TAB for TABID=\002,a)";
    static char fmt_2000[] = "(\0020\002,\002*ERR:70* Argument below range i\
n LKTAB\002,/,1x,\002 Table Id   = \002,a,/,1x,\002 Time           = \002,f1\
4.0,/,1x,\002 Arguument      = \002,f10.4)";
    static char fmt_2010[] = "(\0020\002,\002*ERR:71* Argument above range i\
n LKTAB\002,/,1x,\002 Table Id   = \002,a,/,1x,\002 Time           = \002,f1\
4.0,/,1x,\002 Argument       = \002,f10.4)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    double log(doublereal);
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double exp(doublereal);

    /* Local variables */
    real feq_gen_h_d_, p;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real a2, a3;
    integer ha;
    real df;
    integer la;
    real ph;
    integer inc;
    real arg, arg2;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    real fact;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real aone, fone;
    integer lsta, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real adiff, fpone, azero, fzero, fpzero;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__318 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__319 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__320 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do function table look up for all but cross-section tables, */
/*     two-d tables, and time-series tables. */
/* SOURCE fqshrftb.for:2673 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:2675 */
/*<       integeradrs,ntab,sklt >*/
/* SOURCE fqshrftb.for:2676 */
/*<       realarga,func,pdv >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     ARGA   - argument for finding values in a function table */
/*     SKLT   - flag for skipping the lower bound test on table lookup */
/*     FUNC   - value of function found at ARGA */
/*     NTAB   - table number */
/*     PDV    - partial derivative value */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:2687 */
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
/* INCLUDE fqshrftb.for:2688 */
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
/* INCLUDE fqshrftb.for:2689 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:2692 */
/*<       integerstep(5) >*/
/* SOURCE fqshrftb.for:2693 */
/*<       savestep >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:2696 */
/*<       integerha,inc,la,lsta,type,i,datum_is_active >*/
/* SOURCE fqshrftb.for:2697 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:2701 */
/*<       intrinsicexp,log >*/
/*     Called subprograms */
/* SOURCE fqshrftb.for:2705 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:2706 */
/*<       externalget_tabid >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:2709 */
/*<       datastep/0,2,3,3,3/ >*/
/* SOURCE fqshrftb.for:2712 */
/*<    50 format(/,'*BUG:XXX* Invalid TYPE=',i5,' in LKTAB for TABID=',a) >*/
/* L50: */
/* SOURCE fqshrftb.for:2713 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:2717 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     ITAB(ADRS+1) = TABLE NUMBER */
/*     LSTA = LAST ADDRESS */
/* SOURCE fqshrftb.for:2727 */
/*<       ha=itab(adrs) >*/
    ha = itab[(0 + (0 + (*adrs - 0 << 2))) / 4];
/* SOURCE fqshrftb.for:2728 */
/*<       la=adrs+off234 >*/
    la = *adrs + 22;
/* SOURCE fqshrftb.for:2729 */
/*<       lsta=itab(adrs+3) >*/
    lsta = itab[*adrs + 3];
/* SOURCE fqshrftb.for:2730 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:2731 */
/*<       ntab=itab(adrs+1) >*/
    *ntab = itab[*adrs + 1];
/*      datum_is_active = itab(adrs+18)       !Not needed, at least not yet:) */
/*      datum = ftab(adrs+19) */
/*      SHIFT = FTAB(ADRS+4)                !Shift is applied during input of the table */
/* SOURCE fqshrftb.for:2736 */
/*<       arg=arga >*/
    arg = *arga;
/* SOURCE fqshrftb.for:2737 */
/*<       if(type.gt.4)then >*/
    if (feq_gen_type_d_ > 4) {
/* SOURCE fqshrftb.for:2738 */
/*<       inc=3 >*/
	inc = 3;
/* SOURCE fqshrftb.for:2739 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:2740 */
/*<       inc=step(type) >*/
	inc = step[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:2741 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:2743 */
/*<       if(type.eq.5)then >*/
    if (feq_gen_type_d_ == 5) {
/* SOURCE fqshrftb.for:2744 */
/*<       arg2=arg >*/
	arg2 = arg;
/* SOURCE fqshrftb.for:2745 */
/*<       arg=log(arg) >*/
	arg = log(arg);
/* SOURCE fqshrftb.for:2746 */
/*<       endif >*/
    }
/*     INITIALIZE */
/* SOURCE fqshrftb.for:2750 */
/*<       adiff=arg-ftab(lsta) >*/
    adiff = static_cast<double>(arg) - ftab[lsta];
/* SOURCE fqshrftb.for:2751 */
/*<       if(adiff)100,300,200 >*/
    if (adiff < (float)0.) {
	goto L100;
    } else if (adiff == 0) {
	goto L300;
    } else {
	goto L200;
    }
/*     ARGUMENT PASSED LESS THAN AT PREVIOUS ACCESS TO TABLE */
/* SOURCE fqshrftb.for:2755 */
/*<   100 if(lsta.ge.la)goto110 >*/
L100:
    if (lsta >= la) {
	goto L110;
    }
/* SOURCE fqshrftb.for:2756 */
/*<       if(sklt.eq.0)goto105 >*/
    if (*sklt == 0) {
	goto L105;
    }
/*     SKIP LOWER BOUND TEST */
/* SOURCE fqshrftb.for:2760 */
/*<       lsta=lsta+inc >*/
    lsta += inc;
/* SOURCE fqshrftb.for:2761 */
/*<       arg=ftab(lsta) >*/
    arg = ftab[lsta];
/* SOURCE fqshrftb.for:2762 */
/*<       goto300 >*/
    goto L300;
/* SOURCE fqshrftb.for:2764 */
/*<   105 write(stdout,2000)get_tabid(itab(adrs+1)),time,arg >*/
L105:
    feq_gen_io_d__318.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__318);
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE fqshrftb.for:2765 */
/*<       eflag=1 >*/
    xscom_1.eflag = 1;
/* SOURCE fqshrftb.for:2766 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/*      RETURN */
/* SOURCE fqshrftb.for:2769 */
/*<   110 if(arg.ge.ftab(lsta))goto300 >*/
L110:
    if (arg >= ftab[lsta]) {
	goto L300;
    }
/* SOURCE fqshrftb.for:2770 */
/*<       lsta=lsta-inc >*/
    lsta -= inc;
/* SOURCE fqshrftb.for:2771 */
/*<       goto100 >*/
    goto L100;
/*     ARGUMENT PASSED GREATER THAN AT PREVIOUS ACCESS TO TABLE */
/* SOURCE fqshrftb.for:2775 */
/*<   200 if(lsta.lt.ha)goto210 >*/
L200:
    if (lsta < ha) {
	goto L210;
    }
/* SOURCE fqshrftb.for:2776 */
/*<       write(stdout,2010)get_tabid(itab(adrs+1)),time,arg >*/
    feq_gen_io_d__319.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__319);
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE fqshrftb.for:2777 */
/*<       eflag=1 >*/
    xscom_1.eflag = 1;
/* SOURCE fqshrftb.for:2778 */
/*<       lsta=ha-inc >*/
    lsta = ha - inc;
/* SOURCE fqshrftb.for:2779 */
/*<       arg=ftab(ha) >*/
    arg = ftab[ha];
/* SOURCE fqshrftb.for:2780 */
/*<       goto300 >*/
    goto L300;
/* SOURCE fqshrftb.for:2781 */
/*<   210 if(arg.le.ftab(lsta+inc))goto300 >*/
L210:
    if (arg <= ftab[lsta + inc]) {
	goto L300;
    }
/* SOURCE fqshrftb.for:2782 */
/*<       lsta=lsta+inc >*/
    lsta += inc;
/* SOURCE fqshrftb.for:2783 */
/*<       goto200 >*/
    goto L200;
/* SOURCE fqshrftb.for:2785 */
/*<   300 continue >*/
L300:
/* SOURCE fqshrftb.for:2787 */
/*<       goto(1,2,3,4,5,1,1,1,1,1,1),type >*/
    switch (feq_gen_type_d_) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L1;
	case 7:  goto L1;
	case 8:  goto L1;
	case 9:  goto L1;
	case 10:  goto L1;
	case 11:  goto L1;
    }
/* SOURCE fqshrftb.for:2789 */
/*<     1 continue >*/
L1:
/* SOURCE fqshrftb.for:2790 */
/*<       write(stdout,50)type,get_tabid(ntab) >*/
    feq_gen_io_d__320.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__320);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, ntab);
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:2791 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:2793 */
/*<     2 continue >*/
L2:
L3:
L4:
    // Every output bit verified against both released programs.
    feq_interpolate_function_interval(feq_gen_type_d_,lsta,inc,arg,func,pdv);
    goto L1000;
L5:
/*       Special treatment needed if in the first panel of the */
/*       breakpoint sequence.  We will extrapolate from the second */
/*       panel because the zero argument point is included implicitly. */
/* SOURCE fqshrftb.for:2857 */
/*<       if(lsta.eq.la)then >*/
    if (lsta == la) {
/* SOURCE fqshrftb.for:2858 */
/*<       lsta=la+3 >*/
	lsta = la + 3;
/* SOURCE fqshrftb.for:2859 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:2860 */
/*<       azero=ftab(lsta) >*/
    azero = ftab[lsta];
/* SOURCE fqshrftb.for:2861 */
/*<       fzero=ftab(lsta+1) >*/
    fzero = ftab[lsta + 1];
/* SOURCE fqshrftb.for:2862 */
/*<       fpzero=ftab(lsta+2) >*/
    fpzero = ftab[lsta + 2];
/* SOURCE fqshrftb.for:2863 */
/*<       ph=arg-azero >*/
    ph = static_cast<double>(arg) - azero;
/* SOURCE fqshrftb.for:2864 */
/*<       func=exp(fzero+ph*fpzero) >*/
    *func = exp(static_cast<double>(fzero) + static_cast<double>(ph) * fpzero);
/* SOURCE fqshrftb.for:2865 */
/*<       pdv=func*fpzero/arg2 >*/
    *pdv = static_cast<double>(static_cast<double>(*func) * fpzero) / arg2;
/* SOURCE fqshrftb.for:2866 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fqshrftb.for:2869 */
/*<  1000 continue >*/
L1000:
/*     RESET POINTER TO LAST ADDRESS */
/* SOURCE fqshrftb.for:2873 */
/*<       itab(adrs+3)=lsta >*/
    itab[*adrs + 3] = lsta;
/* SOURCE fqshrftb.for:2876 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:2878 */
/*<       end >*/
} /* lktab_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:2882 */
/*<       subroutinelktstab(adrs,jta,func,ntab,pdv) >*/
/* Subroutine */ int lktstab_(integer *adrs, doublereal *jta, real *func, 
	integer *ntab, real *pdv)
{
    /* Initialized data */

    static integer step[11] = { 0,0,0,0,0,0,2,3,3,0,3 };

    /* Format strings */
    static char fmt_50[] = "(/,\002*BUG:XXX* Invalid TYPE=\002,i5,\002 in LK\
TSTAB for TABID=\002,a)";
    static char fmt_2000[] = "(\0020\002,\002*ERR:70* Argument below range i\
n LKTSTAB\002,/,1x,\002 Table Id   = \002,a,/,1x,\002 Min tab arg           \
= \002,f16.5,/,1x,\002 Arguument      = \002,f16.5)";
    static char fmt_2010[] = "(\0020\002,\002*ERR:71* Argument above range i\
n LKTSTAB\002,/,1x,\002 Table Id   = \002,a,/,1x,\002 Max tab arg           \
= \002,f16.5,/,1x,\002 Argument       = \002,f16.5)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal feq_gen_h_d_, p;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal a2, a3;
    integer ha;
    doublereal df;
    integer la;
    doublereal ph, tp;
    integer inc;
    doublereal arg;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    doublereal fact;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    doublereal aone, fone;
    integer lsta, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    doublereal adiff, fpone, azero, fzero, fpzero;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__345 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__346 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__347 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do function table look up for time-series tables: types */
/*     7, 8, 9, and 11.  All use full double precision in order */
/*     to have a precise argument. */
/*     Note: Only type 11 need return a value of pdv because that */
/*     is the second value.  Other time series do not need a value */
/*     of the derivative.  Thus do not comput and return a value of */
/*     zero.  Also we still return single precision values--the */
/*     use of double precision is only for the benefit of the */
/*     argument. */
/* SOURCE fqshrftb.for:2898 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:2900 */
/*<       integeradrs,ntab >*/
/* SOURCE fqshrftb.for:2901 */
/*<       realfunc,pdv >*/
/* SOURCE fqshrftb.for:2902 */
/*<       real*8jta >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB/DTAB */
/*     jta   - argument for finding values in a function table */
/*     FUNC   - value of function found at ARGA */
/*     NTAB   - table number */
/*     PDV    - partial derivative value */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:2912 */
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
/* INCLUDE fqshrftb.for:2913 */
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
/* INCLUDE fqshrftb.for:2914 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:2917 */
/*<       integerstep(11) >*/
/* SOURCE fqshrftb.for:2918 */
/*<       savestep >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:2921 */
/*<       integerha,inc,la,lsta,type >*/
/* SOURCE fqshrftb.for:2922 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:2926 */
/*<       intrinsicishft >*/
/*     Called subprograms */
/* SOURCE fqshrftb.for:2930 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:2931 */
/*<       externalget_tabid >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:2934 */
/*<       datastep/0,0,0,0,0,0,2,3,3,0,3/ >*/
/* SOURCE fqshrftb.for:2937 */
/*<    50 format(/,'*BUG:XXX* Invalid TYPE=',i5,' in LKTSTAB for TABID=',a) >*/
/* L50: */
/* SOURCE fqshrftb.for:2938 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:2942 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     ITAB(ADRS+1) = TABLE NUMBER */
/*     LSTA = LAST ADDRESS */
/* SOURCE fqshrftb.for:2952 */
/*<       ha=itab(adrs) >*/
    ha = itab[(0 + (0 + (*adrs - 0 << 2))) / 4];
/* SOURCE fqshrftb.for:2953 */
/*<       la=(adrs+off234)/2 >*/
    la = (*adrs + 22) / 2;
/* SOURCE fqshrftb.for:2954 */
/*<       lsta=itab(adrs+3) >*/
    lsta = itab[*adrs + 3];
/* SOURCE fqshrftb.for:2955 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:2956 */
/*<       ntab=itab(adrs+1) >*/
    *ntab = itab[*adrs + 1];
/* SOURCE fqshrftb.for:2957 */
/*<       arg=jta >*/
    arg = *jta;
/* SOURCE fqshrftb.for:2958 */
/*<       inc=step(type) >*/
    inc = step[feq_gen_type_d_ - 1];
/*     INITIALIZE */
/* SOURCE fqshrftb.for:2962 */
/*<       adiff=arg-dtab(lsta) >*/
    adiff = arg - ftable_1.dtab[lsta];
/* SOURCE fqshrftb.for:2963 */
/*<       if(adiff)100,300,200 >*/
    if (adiff < 0.) {
	goto L100;
    } else if (adiff == 0) {
	goto L300;
    } else {
	goto L200;
    }
/*     ARGUMENT PASSED LESS THAN AT PREVIOUS ACCESS TO TABLE */
/* SOURCE fqshrftb.for:2967 */
/*<   100 if(lsta.ge.la)goto110 >*/
L100:
    if (lsta >= la) {
	goto L110;
    }
/* SOURCE fqshrftb.for:2969 */
/*<       write(stdout,2000)get_tabid(itab(adrs+1)),dtab(la),arg >*/
    feq_gen_io_d__345.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__345);
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, (char *)&ftable_1.dtab[la], (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE fqshrftb.for:2970 */
/*<       eflag=1 >*/
    xscom_1.eflag = 1;
/* SOURCE fqshrftb.for:2971 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:2973 */
/*<   110 if(arg.ge.dtab(lsta))goto300 >*/
L110:
    if (arg >= ftable_1.dtab[lsta]) {
	goto L300;
    }
/* SOURCE fqshrftb.for:2974 */
/*<       lsta=lsta-inc >*/
    lsta -= inc;
/* SOURCE fqshrftb.for:2975 */
/*<       goto100 >*/
    goto L100;
/*     ARGUMENT PASSED GREATER THAN AT PREVIOUS ACCESS TO TABLE */
/* SOURCE fqshrftb.for:2979 */
/*<   200 if(lsta.lt.ha)goto210 >*/
L200:
    if (lsta < ha) {
	goto L210;
    }
/* SOURCE fqshrftb.for:2980 */
/*<       write(stdout,2010)get_tabid(itab(adrs+1)),dtab(ha),arg >*/
    feq_gen_io_d__346.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__346);
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, (char *)&ftable_1.dtab[ha], (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE fqshrftb.for:2981 */
/*<       eflag=1 >*/
    xscom_1.eflag = 1;
/* SOURCE fqshrftb.for:2982 */
/*<       lsta=ha-inc >*/
    lsta = ha - inc;
/* SOURCE fqshrftb.for:2983 */
/*<       arg=dtab(ha) >*/
    arg = ftable_1.dtab[ha];
/* SOURCE fqshrftb.for:2984 */
/*<       goto300 >*/
    goto L300;
/* SOURCE fqshrftb.for:2985 */
/*<   210 if(arg.le.dtab(lsta+inc))goto300 >*/
L210:
    if (arg <= ftable_1.dtab[lsta + inc]) {
	goto L300;
    }
/* SOURCE fqshrftb.for:2986 */
/*<       lsta=lsta+inc >*/
    lsta += inc;
/* SOURCE fqshrftb.for:2987 */
/*<       goto200 >*/
    goto L200;
/* SOURCE fqshrftb.for:2989 */
/*<   300 continue >*/
L300:
/* SOURCE fqshrftb.for:2991 */
/*<       goto(1,1,1,1,1,1,7,8,9,1,11),type >*/
    switch (feq_gen_type_d_) {
	case 1:  goto L1;
	case 2:  goto L1;
	case 3:  goto L1;
	case 4:  goto L1;
	case 5:  goto L1;
	case 6:  goto L1;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L1;
	case 11:  goto L11;
    }
/* SOURCE fqshrftb.for:2993 */
/*<     1 continue >*/
L1:
/* SOURCE fqshrftb.for:2994 */
/*<       write(stdout,50)type,get_tabid(ntab) >*/
    feq_gen_io_d__347.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__347);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, ntab);
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:2995 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:2997 */
/*<     7 continue >*/
L7:
/*     SINGLE FUNCTION - LINEAR INTERPOLATION */
/*       FETCH VALUES FROM DTAB */
/* SOURCE fqshrftb.for:3003 */
/*<       azero=dtab(lsta) >*/
    azero = ftable_1.dtab[lsta];
/* SOURCE fqshrftb.for:3004 */
/*<       fzero=dtab(lsta+1) >*/
    fzero = ftable_1.dtab[lsta + 1];
/* SOURCE fqshrftb.for:3005 */
/*<       aone=dtab(lsta+2) >*/
    aone = ftable_1.dtab[lsta + 2];
/* SOURCE fqshrftb.for:3006 */
/*<       fone=dtab(lsta+3) >*/
    fone = ftable_1.dtab[lsta + 3];
/*       INTERPOLATE */
/* SOURCE fqshrftb.for:3010 */
/*<       fact=(arg-azero)/(aone-azero) >*/
    fact = (arg - azero) / (aone - azero);
/* SOURCE fqshrftb.for:3011 */
/*<       func=fzero+fact*(fone-fzero) >*/
    *func = fzero + fact * (fone - fzero);
/*        PDV  = (FONE - FZERO)/(AONE - AZERO) */
/* SOURCE fqshrftb.for:3013 */
/*<       pdv=0.0 >*/
    *pdv = (float)0.;
/* SOURCE fqshrftb.for:3014 */
/*<       goto1000 >*/
    goto L1000;
/*     Dual value- trapezoidal rule interpolation */
/* SOURCE fqshrftb.for:3018 */
/*<     8 continue >*/
L8:
/*       FETCH VALUES */
/* SOURCE fqshrftb.for:3021 */
/*<       azero=dtab(lsta) >*/
    azero = ftable_1.dtab[lsta];
/* SOURCE fqshrftb.for:3022 */
/*<       fzero=dtab(lsta+1) >*/
    fzero = ftable_1.dtab[lsta + 1];
/* SOURCE fqshrftb.for:3023 */
/*<       fpzero=dtab(lsta+2) >*/
    fpzero = ftable_1.dtab[lsta + 2];
/* SOURCE fqshrftb.for:3024 */
/*<       aone=dtab(lsta+3) >*/
    aone = ftable_1.dtab[lsta + 3];
/* SOURCE fqshrftb.for:3025 */
/*<       fone=dtab(lsta+4) >*/
    fone = ftable_1.dtab[lsta + 4];
/* SOURCE fqshrftb.for:3026 */
/*<       fpone=dtab(lsta+5) >*/
    fpone = ftable_1.dtab[lsta + 5];
/* SOURCE fqshrftb.for:3027 */
/*<       ph=arg-azero >*/
    ph = arg - azero;
/* SOURCE fqshrftb.for:3028 */
/*<       h=aone-azero >*/
    feq_gen_h_d_ = aone - azero;
/* SOURCE fqshrftb.for:3029 */
/*<       p=ph/h >*/
    p = ph / feq_gen_h_d_;
/* SOURCE fqshrftb.for:3030 */
/*<       tp=fpzero+p*(fpone-fpzero) >*/
    tp = fpzero + p * (fpone - fpzero);
/* SOURCE fqshrftb.for:3031 */
/*<       func=fzero+0.5*ph*(fpzero+tp) >*/
    *func = fzero + ph * (float).5 * (fpzero + tp);
/* SOURCE fqshrftb.for:3032 */
/*<       pdv=0.0 >*/
    *pdv = (float)0.;
/* SOURCE fqshrftb.for:3033 */
/*<       goto1000 >*/
    goto L1000;
/*     HERMITE CUBIC  INTERPOLATION */
/* SOURCE fqshrftb.for:3037 */
/*<     9 continue >*/
L9:
/* SOURCE fqshrftb.for:3038 */
/*<       azero=dtab(lsta) >*/
    azero = ftable_1.dtab[lsta];
/* SOURCE fqshrftb.for:3039 */
/*<       fzero=dtab(lsta+1) >*/
    fzero = ftable_1.dtab[lsta + 1];
/* SOURCE fqshrftb.for:3040 */
/*<       fpzero=dtab(lsta+2) >*/
    fpzero = ftable_1.dtab[lsta + 2];
/* SOURCE fqshrftb.for:3041 */
/*<       aone=dtab(lsta+3) >*/
    aone = ftable_1.dtab[lsta + 3];
/* SOURCE fqshrftb.for:3042 */
/*<       fone=dtab(lsta+4) >*/
    fone = ftable_1.dtab[lsta + 4];
/* SOURCE fqshrftb.for:3043 */
/*<       fpone=dtab(lsta+5) >*/
    fpone = ftable_1.dtab[lsta + 5];
/* SOURCE fqshrftb.for:3044 */
/*<       ph=arg-azero >*/
    ph = arg - azero;
/* SOURCE fqshrftb.for:3045 */
/*<       h=aone-azero >*/
    feq_gen_h_d_ = aone - azero;
/* SOURCE fqshrftb.for:3046 */
/*<       p=ph/h >*/
    p = ph / feq_gen_h_d_;
/* SOURCE fqshrftb.for:3047 */
/*<       df=fone-fzero >*/
    df = fone - fzero;
/* SOURCE fqshrftb.for:3048 */
/*<       a2=3.*df-h*(fpzero+fpzero+fpone) >*/
    a2 = df * (float)3. - feq_gen_h_d_ * (fpzero + fpzero + fpone);
/* SOURCE fqshrftb.for:3049 */
/*<       a3=h*(fpzero+fpone)-2.*df >*/
    a3 = feq_gen_h_d_ * (fpzero + fpone) - df * (float)2.;
/*        pdv = FPZERO + P*(A2 + A2 + 3.*A3*P)/H */
/* SOURCE fqshrftb.for:3051 */
/*<       func=fzero+ph*fpzero+p*p*(a2+p*a3) >*/
    *func = fzero + ph * fpzero + p * p * (a2 + p * a3);
/* SOURCE fqshrftb.for:3052 */
/*<       pdv=0.d0 >*/
    *pdv = (float)0.;
/* SOURCE fqshrftb.for:3053 */
/*<       goto1000 >*/
    goto L1000;
/*     TIME SERIES WITH TWO VALUES PER TIME POINT */
/* SOURCE fqshrftb.for:3057 */
/*<    11 continue >*/
L11:
/* SOURCE fqshrftb.for:3058 */
/*<       azero=dtab(lsta) >*/
    azero = ftable_1.dtab[lsta];
/* SOURCE fqshrftb.for:3059 */
/*<       fzero=dtab(lsta+1) >*/
    fzero = ftable_1.dtab[lsta + 1];
/* SOURCE fqshrftb.for:3060 */
/*<       fpzero=dtab(lsta+2) >*/
    fpzero = ftable_1.dtab[lsta + 2];
/* SOURCE fqshrftb.for:3061 */
/*<       aone=dtab(lsta+3) >*/
    aone = ftable_1.dtab[lsta + 3];
/* SOURCE fqshrftb.for:3062 */
/*<       fone=dtab(lsta+4) >*/
    fone = ftable_1.dtab[lsta + 4];
/* SOURCE fqshrftb.for:3063 */
/*<       fpone=dtab(lsta+5) >*/
    fpone = ftable_1.dtab[lsta + 5];
/* SOURCE fqshrftb.for:3064 */
/*<       ph=arg-azero >*/
    ph = arg - azero;
/* SOURCE fqshrftb.for:3065 */
/*<       h=aone-azero >*/
    feq_gen_h_d_ = aone - azero;
/* SOURCE fqshrftb.for:3066 */
/*<       p=ph/h >*/
    p = ph / feq_gen_h_d_;
/* SOURCE fqshrftb.for:3068 */
/*<       func=fzero+p*(fone-fzero) >*/
    *func = fzero + p * (fone - fzero);
/* SOURCE fqshrftb.for:3069 */
/*<       pdv=fpzero+p*(fpone-fpzero) >*/
    *pdv = fpzero + p * (fpone - fpzero);
/* SOURCE fqshrftb.for:3070 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fqshrftb.for:3072 */
/*<  1000 continue >*/
L1000:
/*     RESET POINTER TO LAST ADDRESS accessed */
/* SOURCE fqshrftb.for:3076 */
/*<       itab(adrs+3)=lsta >*/
    itab[*adrs + 3] = lsta;
/* SOURCE fqshrftb.for:3079 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:3081 */
/*<       end >*/
} /* lktstab_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:3085 */
/*<       subroutinelsatab(stdout,key,nmax,table,n,index,eflag) >*/
/* Subroutine */ int lsatab_(integer *stdout, char *key, integer *nmax, char *
	feq_storage_table, integer *n, integer *index, integer *eflag, ftnlen key_len, 
	ftnlen table_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:651* Too many entries in LSATAB. Nu\
mber=\002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__363 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do a linear search for KEY in the entries in TABLE.  If match */
/*     is found, return the index of the match, otherwise, add the */
/*     value to the end of the table, increment N, and return an */
/*     index of N. */
/* SOURCE fqshrftb.for:3096 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:3098 */
/*<       integereflag,index,n,nmax,stdout >*/
/* SOURCE fqshrftb.for:3099 */
/*<       character*(*)key,table(nmax) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     KEY    - search value */
/*     NMAX   - maximum permit extent of the table */
/*     TABLE  - table of values to be searched */
/*     N      - number of items in the table */
/*     INDEX  - index into the table at the match point */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:3111 */
/*<       integeri >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:3114 */
/*<    50 format(/,' *ERR:651* Too many entries in LSATAB. Number=',i5) >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:3116 */
/*<       do100i=1,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> table(feq_storage_table, table_len);

    /* Function Body */
/* L50: */
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:3117 */
/*<       if(key.eq.table(i))then >*/
	if (s_cmp(key, table + feq_gen_i_d_ * table_len, key_len, table_len) == 0) {
/*         FOUND MATCH */
/* SOURCE fqshrftb.for:3119 */
/*<       index=i >*/
	    *index = feq_gen_i_d_;
/* SOURCE fqshrftb.for:3120 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrftb.for:3121 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:3122 */
/*<   100 continue >*/
/* L100: */
    }
/*     MATCH NOT FOUND */
/* SOURCE fqshrftb.for:3124 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3125 */
/*<       if(n.gt.nmax)then >*/
    if (*n > *nmax) {
/* SOURCE fqshrftb.for:3126 */
/*<       write(stdout,50)n >*/
	feq_gen_io_d__363.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__363);
	do_fio(&feq_gen_c_d_1, (char *)&(*n), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:3127 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE fqshrftb.for:3128 */
/*<       n=nmax >*/
	*n = *nmax;
/* SOURCE fqshrftb.for:3129 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3130 */
/*<       table(n)=key >*/
    s_copy(table + *n * table_len, key, table_len, key_len);
/* SOURCE fqshrftb.for:3131 */
/*<       index=n >*/
    *index = *n;
/* SOURCE fqshrftb.for:3132 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:3133 */
/*<       end >*/
} /* lsatab_ */




/* SOURCE fqshrftb.for:3137 */
/*<       subroutinelstab(key,table,n,index) >*/
/* Subroutine */ int lstab_(char *key, char *feq_storage_table, integer *n, integer *
	index, ftnlen key_len, ftnlen table_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

/*     + + + PURPOSE + + + */
/*     Do a linear search for KEY in the entries in TABLE.  If match */
/*     is found, return the index of the match, otherwise, return */
/*     a zero value for the index. */
/* SOURCE fqshrftb.for:3146 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:3148 */
/*<       integerindex,n >*/
/* SOURCE fqshrftb.for:3149 */
/*<       character*(*)key,table(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     KEY    - search value */
/*     TABLE  - table of values to be searched */
/*     N      - number of items in the table */
/*     INDEX  - index into the table at the match point */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:3158 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:3160 */
/*<       do100i=1,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> table(feq_storage_table, table_len);

    /* Function Body */
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:3161 */
/*<       if(key.eq.table(i))then >*/
	if (s_cmp(key, table + feq_gen_i_d_ * table_len, key_len, table_len) == 0) {
/*         FOUND MATCH */
/* SOURCE fqshrftb.for:3163 */
/*<       index=i >*/
	    *index = feq_gen_i_d_;
/* SOURCE fqshrftb.for:3164 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrftb.for:3165 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:3166 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE fqshrftb.for:3167 */
/*<       index=0 >*/
    *index = 0;
/* SOURCE fqshrftb.for:3168 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:3169 */
/*<       end >*/
} /* lstab_ */




/* SOURCE fqshrftb.for:3173 */
/*<       subroutinemerge(stdout,tabl,tabr,eflag,n,y) >*/
/* Subroutine */ int merge_(integer *stdout, integer *tabl, integer *tabr, 
	integer *eflag, integer *n, real *feq_storage_y)
{
    /* Format strings */
    static char fmt_10[] = "(\002 *ERR:87* More than\002,i5,\002 depth value\
s between\002,\002 TABIDS \002,a,\002 and \002,a)";
    static char fmt_50[] = "(\002 *BUG:XXX* TYPE=\002,i5,\002 INVALID IN TAB\
ID=\002,a,\002 IN MERGE.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real yl, yr;
    integer adl, adr;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real tval;
    integer list;
    real ymax;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real crval;
    integer xoffl, xoffr, typel, typer;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__373 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__376 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__379 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__381 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__383 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__385 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__386 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__387 = { 0, 0, 0, fmt_10, 0 };


/*     + + + PURPOSE + + + */
/*     Compile the list of merged depth values from the left hand */
/*     section (TABL) and the right hand section(TABR).  place */
/*     list into Y(*) with N giving the number of depth values in */
/*     Y(*).  The merged list must contain strictly increasing */
/*     values of depth-- no duplicate values allowed. */
/* SOURCE fqshrftb.for:3184 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE fqshrftb.for:3186 */
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
/* SOURCE fqshrftb.for:3189 */
/*<       integereflag,stdout,n,tabl,tabr >*/
/* SOURCE fqshrftb.for:3190 */
/*<       realy(mndep) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TABL   - address of the cross section table on the left */
/*     TABR   - address of the cross section table on the right */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     N      - number of depth values in final merged list */
/*     Y      - merged depth values */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:3201 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE fqshrftb.for:3202 */
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
/* SOURCE fqshrftb.for:3205 */
/*<       integeradl,adr,list,typel,typer,xoffl,xoffr >*/
/* SOURCE fqshrftb.for:3206 */
/*<       realcrval,tval,yl,ymax,yr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:3209 */
/*<       intrinsicamin1 >*/
/*     Called program units */
/* SOURCE fqshrftb.for:3212 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:3214 */
/*<       externalget_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:3217 */
/*<    10  >*/
/* SOURCE fqshrftb.for:3219 */
/*<    50 format(' *BUG:XXX* TYPE=',i5,' INVALID IN TABID=',a,' IN MERGE.') >*/
/* *********************************************************************** */
/*     FIND MINIMUM VALUE OF MAXIMUM DEPTH FOR THE TWO SECTIONS */
/* SOURCE fqshrftb.for:3223 */
/*<       ymax=amin1(ftab(itab(tabl)),ftab(itab(tabr))) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> y(feq_storage_y, 1);

    /* Function Body */
/* L10: */
/* L50: */
/* Computing MIN */
    feq_gen_r_d_1 = ftab[itab[*tabl]], feq_gen_r_d_2 = ftab[itab[*tabr]];
    ymax = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/*     INITIALIZE ADDRESSES FOR DEPTH VALUE IN FTAB */
/* SOURCE fqshrftb.for:3227 */
/*<       adl=tabl+xtioff >*/
    adl = *tabl + 32;
/* SOURCE fqshrftb.for:3228 */
/*<       adr=tabr+xtioff >*/
    adr = *tabr + 32;
/*     SET THE OFFSETS FOR EACH TABLE */
/* SOURCE fqshrftb.for:3232 */
/*<       typel=itab(tabl+2) >*/
    typel = itab[*tabl + 2];
/* SOURCE fqshrftb.for:3233 */
/*<       xoffl=offvec(typel) >*/
    xoffl = offcom_1.offvec[typel - 1];
/* SOURCE fqshrftb.for:3234 */
/*<       if(xoffl.eq.0)then >*/
    if (xoffl == 0) {
/* SOURCE fqshrftb.for:3235 */
/*<       write(stdout,50)typel,get_tabid(itab(tabl+1)) >*/
	feq_gen_io_d__373.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__373);
	do_fio(&feq_gen_c_d_1, (char *)&typel, (ftnlen)sizeof(integer));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:3236 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3237 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3239 */
/*<       typer=itab(tabr+2) >*/
    typer = itab[*tabr + 2];
/* SOURCE fqshrftb.for:3240 */
/*<       xoffr=offvec(typer) >*/
    xoffr = offcom_1.offvec[typer - 1];
/* SOURCE fqshrftb.for:3241 */
/*<       if(xoffr.eq.0)then >*/
    if (xoffr == 0) {
/* SOURCE fqshrftb.for:3242 */
/*<       write(stdout,50)typer,get_tabid(itab(tabr+1)) >*/
	feq_gen_io_d__376.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__376);
	do_fio(&feq_gen_c_d_1, (char *)&typer, (ftnlen)sizeof(integer));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabr + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:3243 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3244 */
/*<       endif >*/
    }
/*     COMPILE MERGED LIST OF DEPTH VALUES FROM MINIMUM DEPTH */
/*     (WHICH MUST BE ZERO FOR BOTH SECTIONS) UNTIL YMAX. */
/* SOURCE fqshrftb.for:3249 */
/*<       n=0 >*/
    *n = 0;
/*     GET NEXT PAIR OF DEPTH VALUES */
/* SOURCE fqshrftb.for:3253 */
/*<    90 continue >*/
L90:
/* SOURCE fqshrftb.for:3254 */
/*<       yl=ftab(adl) >*/
    yl = ftab[adl];
/* SOURCE fqshrftb.for:3255 */
/*<       yr=ftab(adr) >*/
    yr = ftab[adr];
/* SOURCE fqshrftb.for:3256 */
/*<       if(yl.ne.yr)goto100 >*/
    if (yl != yr) {
	goto L100;
    }
/*        EQUALITY. STORE ONE VALUE IN Y */
/* SOURCE fqshrftb.for:3260 */
/*<       if(n.lt.mndep)goto92 >*/
    if (*n < 1000) {
	goto L92;
    }
/* SOURCE fqshrftb.for:3261 */
/*<        >*/
    feq_gen_io_d__379.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__379);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:3263 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3264 */
/*<    92 continue >*/
L92:
/* SOURCE fqshrftb.for:3265 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3266 */
/*<       y(n)=yl >*/
    y[*n] = yl;
/* SOURCE fqshrftb.for:3267 */
/*<       if(yl.eq.ymax)return >*/
    if (yl == ymax) {
	return 0;
    }
/* SOURCE fqshrftb.for:3268 */
/*<       adl=adl+xoffl >*/
    adl += xoffl;
/* SOURCE fqshrftb.for:3269 */
/*<       adr=adr+xoffr >*/
    adr += xoffr;
/* SOURCE fqshrftb.for:3270 */
/*<       goto90 >*/
    goto L90;
/* SOURCE fqshrftb.for:3271 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:3272 */
/*<       if(yl.lt.yr)goto120 >*/
    if (yl < yr) {
	goto L120;
    }
/*           YL > YR.  PUT MINIMUM VALUE IN Y AND INITIALIZE CURRENT */
/*           VALUE, SET SOURCE LIST TO RIGHT HAND SECTION. */
/* SOURCE fqshrftb.for:3276 */
/*<       list=1 >*/
    list = 1;
/* SOURCE fqshrftb.for:3277 */
/*<       if(n.lt.mndep)goto102 >*/
    if (*n < 1000) {
	goto L102;
    }
/* SOURCE fqshrftb.for:3278 */
/*<        >*/
    feq_gen_io_d__381.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__381);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:3280 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE fqshrftb.for:3281 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3282 */
/*<   102 continue >*/
L102:
/* SOURCE fqshrftb.for:3283 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3284 */
/*<       y(n)=yr >*/
    y[*n] = yr;
/* SOURCE fqshrftb.for:3285 */
/*<       crval=yl >*/
    crval = yl;
/* SOURCE fqshrftb.for:3286 */
/*<       goto130 >*/
    goto L130;
/* SOURCE fqshrftb.for:3287 */
/*<   120 continue >*/
L120:
/*           YL<YR.  PUT MIN VALUE IN Y, INITIALIZE CURRENT VALUE, AND */
/*           SET SOURCE LIST TO LEFT HAND SECTION. */
/* SOURCE fqshrftb.for:3291 */
/*<       list=-1 >*/
    list = -1;
/* SOURCE fqshrftb.for:3292 */
/*<       if(n.lt.mndep)goto122 >*/
    if (*n < 1000) {
	goto L122;
    }
/* SOURCE fqshrftb.for:3293 */
/*<        >*/
    feq_gen_io_d__383.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__383);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:3295 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE fqshrftb.for:3296 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3297 */
/*<   122 continue >*/
L122:
/* SOURCE fqshrftb.for:3298 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3299 */
/*<       y(n)=yl >*/
    y[*n] = yl;
/* SOURCE fqshrftb.for:3300 */
/*<       crval=yr >*/
    crval = yr;
/* SOURCE fqshrftb.for:3301 */
/*<   130 continue >*/
L130:
/* SOURCE fqshrftb.for:3302 */
/*<       if(y(n).eq.ymax)return >*/
    if (y[*n] == ymax) {
	return 0;
    }
/*             INCREMENT SOURCE LIST POINTER AND GET TEST VALUE THEREFROM */
/* SOURCE fqshrftb.for:3306 */
/*<       if(list.eq.-1)goto140 >*/
    if (list == -1) {
	goto L140;
    }
/* SOURCE fqshrftb.for:3307 */
/*<       adr=adr+xoffr >*/
    adr += xoffr;
/* SOURCE fqshrftb.for:3308 */
/*<       tval=ftab(adr) >*/
    tval = ftab[adr];
/* SOURCE fqshrftb.for:3309 */
/*<       goto150 >*/
    goto L150;
/* SOURCE fqshrftb.for:3310 */
/*<   140 continue >*/
L140:
/* SOURCE fqshrftb.for:3311 */
/*<       adl=adl+xoffl >*/
    adl += xoffl;
/* SOURCE fqshrftb.for:3312 */
/*<       tval=ftab(adl) >*/
    tval = ftab[adl];
/* SOURCE fqshrftb.for:3313 */
/*<   150 continue >*/
L150:
/* SOURCE fqshrftb.for:3314 */
/*<       if(tval.eq.crval)goto200 >*/
    if (tval == crval) {
	goto L200;
    }
/* SOURCE fqshrftb.for:3315 */
/*<       if(tval.gt.crval)goto170 >*/
    if (tval > crval) {
	goto L170;
    }
/* SOURCE fqshrftb.for:3316 */
/*<       if(n.lt.mndep)goto165 >*/
    if (*n < 1000) {
	goto L165;
    }
/* SOURCE fqshrftb.for:3317 */
/*<        >*/
    feq_gen_io_d__385.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__385);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:3319 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE fqshrftb.for:3320 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3321 */
/*<   165 continue >*/
L165:
/* SOURCE fqshrftb.for:3322 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3323 */
/*<       y(n)=tval >*/
    y[*n] = tval;
/* SOURCE fqshrftb.for:3324 */
/*<       goto130 >*/
    goto L130;
/* SOURCE fqshrftb.for:3325 */
/*<   170 continue >*/
L170:
/* SOURCE fqshrftb.for:3326 */
/*<       if(n.lt.mndep)goto175 >*/
    if (*n < 1000) {
	goto L175;
    }
/* SOURCE fqshrftb.for:3327 */
/*<        >*/
    feq_gen_io_d__386.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__386);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:3329 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE fqshrftb.for:3330 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3331 */
/*<   175 continue >*/
L175:
/* SOURCE fqshrftb.for:3332 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3333 */
/*<       y(n)=crval >*/
    y[*n] = crval;
/* SOURCE fqshrftb.for:3334 */
/*<       crval=tval >*/
    crval = tval;
/* SOURCE fqshrftb.for:3335 */
/*<       list=-list >*/
    list = -list;
/* SOURCE fqshrftb.for:3336 */
/*<       goto130 >*/
    goto L130;
/* SOURCE fqshrftb.for:3337 */
/*<   200 continue >*/
L200:
/* SOURCE fqshrftb.for:3338 */
/*<       if(n.lt.mndep)goto205 >*/
    if (*n < 1000) {
	goto L205;
    }
/* SOURCE fqshrftb.for:3339 */
/*<        >*/
    feq_gen_io_d__387.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__387);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:3341 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE fqshrftb.for:3342 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3343 */
/*<   205 continue >*/
L205:
/* SOURCE fqshrftb.for:3344 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3345 */
/*<       y(n)=tval >*/
    y[*n] = tval;
/* SOURCE fqshrftb.for:3346 */
/*<       adr=adr+xoffr >*/
    adr += xoffr;
/* SOURCE fqshrftb.for:3347 */
/*<       adl=adl+xoffl >*/
    adl += xoffl;
/* SOURCE fqshrftb.for:3348 */
/*<       if(y(n).eq.ymax)return >*/
    if (y[*n] == ymax) {
	return 0;
    }
/* SOURCE fqshrftb.for:3349 */
/*<       goto90 >*/
    goto L90;
/* SOURCE fqshrftb.for:3350 */
/*<       end >*/
} /* merge_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:3354 */
/*<       subroutineget_real_depths(stdout,adrs,sd,n,real_depth) >*/
/* Subroutine */ int feq_gen_get_real_depths_d_(integer *stdout, integer *adrs, real *
	sd, integer *n, real *feq_gen_feq_storage_real_depth_d_)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:406 There are \002,i5,\002 > \002,i\
5,\002 depth\002,\002         values in TABID=\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer off;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer last, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real depth;
    integer first;
    extern integer gettbn_(integer *);
    extern doublereal feq_gen_get_slot_depth_d_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__397 = { 0, 0, 0, fmt_50, 0 };


/*     Get the sequence of "real" depths from a cross section */
/*     that may have a slot.  A real depth has a datum at the */
/*     invert of the cross section BEFORE any slot was added. */
/* SOURCE fqshrftb.for:3361 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE fqshrftb.for:3363 */
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
/* SOURCE fqshrftb.for:3365 */
/*<       integerstdout,adrs,n >*/
/* SOURCE fqshrftb.for:3367 */
/*<       realsd,real_depth(mndep) >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:3370 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE fqshrftb.for:3371 */
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
/*     Called program units */
/* SOURCE fqshrftb.for:3374 */
/*<       integergettbn >*/
/* SOURCE fqshrftb.for:3375 */
/*<       realget_slot_depth >*/
/* SOURCE fqshrftb.for:3376 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:3378 */
/*<       externalgettbn,get_slot_depth,get_tabid >*/
/*     Local */
/* SOURCE fqshrftb.for:3381 */
/*<       integeri,first,type,off,last >*/
/* SOURCE fqshrftb.for:3383 */
/*<       realdepth >*/
/*     **************************FORMATS********************************* */
/* SOURCE fqshrftb.for:3386 */
/*<    50  >*/
/* *********************************************************************** */
/*     Get the slot depth.  It will be zero or negative.  We want */
/*     its absolute value in the current context. */
/* SOURCE fqshrftb.for:3392 */
/*<       sd=abs(get_slot_depth(adrs)) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_real_depth_d_(feq_gen_feq_storage_real_depth_d_, 1);

    /* Function Body */
/* L50: */
    *sd = (feq_gen_r_d_1 = feq_gen_get_slot_depth_d_(adrs), dabs(feq_gen_r_d_1));
/*     Get the address of the first depth value in the table. */
/* SOURCE fqshrftb.for:3396 */
/*<       first=adrs+xtioff >*/
    first = *adrs + 32;
/*     Get the address of the last depth value in the table */
/* SOURCE fqshrftb.for:3399 */
/*<       last=itab(adrs) >*/
    last = itab[*adrs];
/*     Find the offset for the depth arguments for this table. */
/*     Depends on table type. */
/* SOURCE fqshrftb.for:3404 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:3405 */
/*<       off=offvec(type) >*/
    off = offcom_1.offvec[feq_gen_type_d_ - 1];
/*     Outline of method: scan all depths in the table and subtact */
/*     the slot depth.  If the remaining value is positive, store */
/*     in the real-depth vector.  Initialize the real-depth vector so that */
/*     its first element is 0.0. */
/* SOURCE fqshrftb.for:3412 */
/*<       n=1 >*/
    *n = 1;
/* SOURCE fqshrftb.for:3413 */
/*<       real_depth(1)=0.0 >*/
    feq_gen_real_depth_d_[1] = (float)0.;
/* SOURCE fqshrftb.for:3415 */
/*<       do100i=first,last,off >*/
    feq_gen_i_d_1 = last;
    feq_gen_i_d_2 = off;
    for (feq_gen_i_d_ = first; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE fqshrftb.for:3417 */
/*<       depth=ftab(i)-sd >*/
	depth = static_cast<double>(ftab[feq_gen_i_d_]) - *sd;
/* SOURCE fqshrftb.for:3418 */
/*<       if(depth.gt.0.0)then >*/
	if (depth > (float)0.) {
/* SOURCE fqshrftb.for:3419 */
/*<       n=n+1 >*/
	    ++(*n);
/* SOURCE fqshrftb.for:3420 */
/*<       if(n.gt.mndep)then >*/
	    if (*n > 1000) {
/* SOURCE fqshrftb.for:3421 */
/*<       write(stdout,50)n,mndep,get_tabid(gettbn(adrs)) >*/
		feq_gen_io_d__397.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__397);
		do_fio(&feq_gen_c_d_1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
		feq_gen_i_d_3 = gettbn_(adrs);
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_3);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrftb.for:3422 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE fqshrftb.for:3423 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:3424 */
/*<       real_depth(n)=depth >*/
	    feq_gen_real_depth_d_[*n] = depth;
/* SOURCE fqshrftb.for:3425 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:3426 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE fqshrftb.for:3428 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:3429 */
/*<       end >*/
} /* get_real_depths__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:3435 */
/*<       subroutinemerge_with_slot(stdout,tabl,tabr,eflag,n,y,sdl,sdr) >*/
/* Subroutine */ int feq_gen_merge_with_slot_d_(integer *stdout, integer *tabl, 
	integer *tabr, integer *eflag, integer *n, real *feq_storage_y, real *sdl, real *
	sdr)
{
    /* Format strings */
    static char fmt_10[] = "(\002 *ERR:87* More than\002,i5,\002 depth value\
s between\002,\002 TABIDS \002,a,\002 and \002,a)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer il, nl, ir, nr;
    real yl, yr;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real tval;
    integer list;
    real ymax;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real crval, yleft[1000], yright[1000];
    extern /* Subroutine */ int feq_gen_get_real_depths_d_(integer *, integer *, real *
	    , integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__410 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__412 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__414 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__416 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__417 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__418 = { 0, 0, 0, fmt_10, 0 };


/*     + + + PURPOSE + + + */
/*     Compile the list of merged depth values from the left hand */
/*     section (TABL) and the right hand section(TABR).  place */
/*     list into Y(*) with N giving the number of depth values in */
/*     Y(*).  The merged list must contain strictly increasing */
/*     values of depth-- no duplicate values allowed. */
/* SOURCE fqshrftb.for:3446 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE fqshrftb.for:3448 */
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
/* SOURCE fqshrftb.for:3451 */
/*<       integereflag,stdout,n,tabl,tabr >*/
/* SOURCE fqshrftb.for:3452 */
/*<       realsdl,sdr,y(mndep) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TABL   - address of the cross section table on the left */
/*     TABR   - address of the cross section table on the right */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     N      - number of depth values in final merged list */
/*     Y      - merged depth values */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:3463 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE fqshrftb.for:3464 */
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
/* SOURCE fqshrftb.for:3467 */
/*<       integeril,ir,list,nl,nr >*/
/* SOURCE fqshrftb.for:3468 */
/*<       realcrval,tval,yl,ymax,yr,yleft(mndep),yright(mndep) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:3471 */
/*<       intrinsicamin1 >*/
/*     Called program units */
/* SOURCE fqshrftb.for:3474 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:3476 */
/*<       externalget_tabid,get_real_depths >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:3479 */
/*<    10  >*/
/* *********************************************************************** */
/*     Find the tabulated depth sequence for each table with */
/*     only depths in the real section, starting at 0.0, being */
/*     included. */
/* SOURCE fqshrftb.for:3485 */
/*<       callget_real_depths(stdout,tabl,sdl,nl,yleft) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> y(feq_storage_y, 1);

    /* Function Body */
/* L10: */
    feq_gen_get_real_depths_d_(stdout, tabl, sdl, &nl, yleft);
/* SOURCE fqshrftb.for:3487 */
/*<       callget_real_depths(stdout,tabr,sdr,nr,yright) >*/
    feq_gen_get_real_depths_d_(stdout, tabr, sdr, &nr, yright);
/*     FIND MINIMUM VALUE OF MAXIMUM DEPTH FOR THE TWO SECTIONS */
/* SOURCE fqshrftb.for:3493 */
/*<       ymax=amin1(yleft(nl),yright(nr)) >*/
/* Computing MIN */
    feq_gen_r_d_1 = yleft[nl - 1], feq_gen_r_d_2 = yright[nr - 1];
    ymax = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/*     COMPILE MERGED LIST OF DEPTH VALUES FROM MINIMUM DEPTH */
/*     (WHICH MUST BE ZERO FOR BOTH SECTIONS) UNTIL YMAX. */
/* SOURCE fqshrftb.for:3499 */
/*<       n=0 >*/
    *n = 0;
/* SOURCE fqshrftb.for:3500 */
/*<       il=1 >*/
    il = 1;
/* SOURCE fqshrftb.for:3501 */
/*<       ir=1 >*/
    ir = 1;
/*     GET NEXT PAIR OF DEPTH VALUES */
/* SOURCE fqshrftb.for:3505 */
/*<    90 continue >*/
L90:
/* SOURCE fqshrftb.for:3506 */
/*<       yl=yleft(il) >*/
    yl = yleft[il - 1];
/* SOURCE fqshrftb.for:3507 */
/*<       yr=yright(ir) >*/
    yr = yright[ir - 1];
/* SOURCE fqshrftb.for:3508 */
/*<       if(yl.ne.yr)goto100 >*/
    if (yl != yr) {
	goto L100;
    }
/*        EQUALITY. STORE ONE VALUE IN Y */
/* SOURCE fqshrftb.for:3512 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3513 */
/*<       if(n.gt.mndep)then >*/
    if (*n > 1000) {
/* SOURCE fqshrftb.for:3514 */
/*<        >*/
	feq_gen_io_d__410.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__410);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:3516 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3517 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3518 */
/*<       y(n)=yl >*/
    y[*n] = yl;
/* SOURCE fqshrftb.for:3519 */
/*<       if(yl.eq.ymax)return >*/
    if (yl == ymax) {
	return 0;
    }
/* SOURCE fqshrftb.for:3520 */
/*<       il=il+1 >*/
    ++il;
/* SOURCE fqshrftb.for:3521 */
/*<       ir=ir+1 >*/
    ++ir;
/* SOURCE fqshrftb.for:3522 */
/*<       goto90 >*/
    goto L90;
/* SOURCE fqshrftb.for:3523 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:3524 */
/*<       if(yl.lt.yr)goto120 >*/
    if (yl < yr) {
	goto L120;
    }
/*           YL > YR.  PUT MINIMUM VALUE IN Y AND INITIALIZE CURRENT */
/*           VALUE, SET SOURCE LIST TO RIGHT HAND SECTION. */
/* SOURCE fqshrftb.for:3528 */
/*<       list=1 >*/
    list = 1;
/* SOURCE fqshrftb.for:3529 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3530 */
/*<       if(n.gt.mndep)then >*/
    if (*n > 1000) {
/* SOURCE fqshrftb.for:3531 */
/*<        >*/
	feq_gen_io_d__412.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__412);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:3533 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3534 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3535 */
/*<       y(n)=yr >*/
    y[*n] = yr;
/* SOURCE fqshrftb.for:3536 */
/*<       crval=yl >*/
    crval = yl;
/* SOURCE fqshrftb.for:3537 */
/*<       goto130 >*/
    goto L130;
/* SOURCE fqshrftb.for:3538 */
/*<   120 continue >*/
L120:
/*           YL<YR.  PUT MIN VALUE IN Y, INITIALIZE CURRENT VALUE, AND */
/*           SET SOURCE LIST TO LEFT HAND SECTION. */
/* SOURCE fqshrftb.for:3542 */
/*<       list=-1 >*/
    list = -1;
/* SOURCE fqshrftb.for:3543 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3544 */
/*<       if(n.gt.mndep)then >*/
    if (*n > 1000) {
/* SOURCE fqshrftb.for:3545 */
/*<        >*/
	feq_gen_io_d__414.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__414);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:3547 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3548 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3549 */
/*<       y(n)=yl >*/
    y[*n] = yl;
/* SOURCE fqshrftb.for:3550 */
/*<       crval=yr >*/
    crval = yr;
/* SOURCE fqshrftb.for:3551 */
/*<   130 continue >*/
L130:
/* SOURCE fqshrftb.for:3552 */
/*<       if(y(n).eq.ymax)return >*/
    if (y[*n] == ymax) {
	return 0;
    }
/*             INCREMENT SOURCE LIST POINTER AND GET TEST VALUE THEREFROM */
/* SOURCE fqshrftb.for:3556 */
/*<       if(list.eq.-1)goto140 >*/
    if (list == -1) {
	goto L140;
    }
/* SOURCE fqshrftb.for:3557 */
/*<       ir=ir+1 >*/
    ++ir;
/* SOURCE fqshrftb.for:3558 */
/*<       tval=yright(ir) >*/
    tval = yright[ir - 1];
/* SOURCE fqshrftb.for:3559 */
/*<       goto150 >*/
    goto L150;
/* SOURCE fqshrftb.for:3560 */
/*<   140 continue >*/
L140:
/* SOURCE fqshrftb.for:3561 */
/*<       il=il+1 >*/
    ++il;
/* SOURCE fqshrftb.for:3562 */
/*<       tval=yleft(il) >*/
    tval = yleft[il - 1];
/* SOURCE fqshrftb.for:3563 */
/*<   150 continue >*/
L150:
/* SOURCE fqshrftb.for:3564 */
/*<       if(tval.eq.crval)goto200 >*/
    if (tval == crval) {
	goto L200;
    }
/* SOURCE fqshrftb.for:3565 */
/*<       if(tval.gt.crval)goto170 >*/
    if (tval > crval) {
	goto L170;
    }
/* SOURCE fqshrftb.for:3566 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3567 */
/*<       if(n.gt.mndep)then >*/
    if (*n > 1000) {
/* SOURCE fqshrftb.for:3568 */
/*<        >*/
	feq_gen_io_d__416.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__416);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:3570 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3571 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3572 */
/*<       y(n)=tval >*/
    y[*n] = tval;
/* SOURCE fqshrftb.for:3573 */
/*<       goto130 >*/
    goto L130;
/* SOURCE fqshrftb.for:3574 */
/*<   170 continue >*/
L170:
/* SOURCE fqshrftb.for:3575 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3576 */
/*<       if(n.gt.mndep)then >*/
    if (*n > 1000) {
/* SOURCE fqshrftb.for:3577 */
/*<        >*/
	feq_gen_io_d__417.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__417);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:3579 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3580 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3581 */
/*<       y(n)=crval >*/
    y[*n] = crval;
/* SOURCE fqshrftb.for:3582 */
/*<       crval=tval >*/
    crval = tval;
/* SOURCE fqshrftb.for:3583 */
/*<       list=-list >*/
    list = -list;
/* SOURCE fqshrftb.for:3584 */
/*<       goto130 >*/
    goto L130;
/* SOURCE fqshrftb.for:3585 */
/*<   200 continue >*/
L200:
/* SOURCE fqshrftb.for:3586 */
/*<       n=n+1 >*/
    ++(*n);
/* SOURCE fqshrftb.for:3587 */
/*<       if(n.gt.mndep)then >*/
    if (*n > 1000) {
/* SOURCE fqshrftb.for:3588 */
/*<        >*/
	feq_gen_io_d__418.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__418);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabl + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(*tabr + 1).data());
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrftb.for:3590 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3591 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3592 */
/*<       y(n)=tval >*/
    y[*n] = tval;
/* SOURCE fqshrftb.for:3593 */
/*<       ir=ir+1 >*/
    ++ir;
/* SOURCE fqshrftb.for:3594 */
/*<       il=il+1 >*/
    ++il;
/* SOURCE fqshrftb.for:3595 */
/*<       if(y(n).eq.ymax)return >*/
    if (y[*n] == ymax) {
	return 0;
    }
/* SOURCE fqshrftb.for:3596 */
/*<       goto90 >*/
    goto L90;
/* SOURCE fqshrftb.for:3597 */
/*<       end >*/
} /* merge_with_slot__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:3602 */
/*<       subroutinemake_yslot(maxndep,npslot,n,sd,y,newn,yslot) >*/
/* Subroutine */ int feq_gen_make_yslot_d_(integer *maxndep, integer *npslot, integer *
	n, real *sd, real *feq_storage_y, integer *newn, real *feq_storage_yslot)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;

/*     Make the sequence of depths for a section with a slot */
/*     so that interpolation for an intermediate table between */
/*     two tables that have a slot, will produce a valid */
/*     slotted intermediate result. */
/* SOURCE fqshrftb.for:3611 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:3612 */
/*<       integermaxndep,npslot,n,newn >*/
/* SOURCE fqshrftb.for:3613 */
/*<       realsd,yslot(maxndep),y(n) >*/
/*     Local */
/* SOURCE fqshrftb.for:3616 */
/*<       integeri >*/
/* *********************************************************************** */
/*     Distribute the depths in the slot uniformly over the slot depth. */
/* SOURCE fqshrftb.for:3619 */
/*<       do100i=1,npslot-1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> yslot(feq_storage_yslot, 1);

    feq::IndexedPointer<real> y(feq_storage_y, 1);

    /* Function Body */
    feq_gen_i_d_1 = *npslot - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:3620 */
/*<       yslot(i)=sd*real(i-1)/real(npslot-1) >*/
	yslot[feq_gen_i_d_] = static_cast<double>(static_cast<double>(*sd) * (real) (feq_gen_i_d_ - 1)) / (real) (*npslot - 1);
/* SOURCE fqshrftb.for:3621 */
/*<   100 continue >*/
/* L100: */
    }
/*     The first value in Y(*) is 0.0 always.  We add SD to each value */
/*     in Y and place it in YSLOT starting at NPSLOT */
/* SOURCE fqshrftb.for:3626 */
/*<       do110i=1,n >*/
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:3627 */
/*<       yslot(npslot+i-1)=y(i)+sd >*/
	yslot[*npslot + feq_gen_i_d_ - 1] = static_cast<double>(y[feq_gen_i_d_]) + *sd;
/* SOURCE fqshrftb.for:3628 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE fqshrftb.for:3629 */
/*<       newn=npslot+n-1 >*/
    *newn = *npslot + *n - 1;
/* SOURCE fqshrftb.for:3630 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:3631 */
/*<       end >*/
} /* make_yslot__ */




/* SOURCE fqshrftb.for:3639 */
/*<       integerfunctionget_kount_of_internal_tabids() >*/
integer feq_gen_get_kount_of_internal_tabids_d_()
{
    /* System generated locals */
    integer ret_val;

/*     Get the existing count of table ids. */
/* INCLUDE fqshrftb.for:3643 */
/*     Common for the counter for the number of internally */
/*     generated table ids */
/* SOURCE itbidnm.cmn:4 */
/*<       integerkount_of_internal_tabids >*/
/* SOURCE itbidnm.cmn:6 */
/*<       common/itabidnum/kount_of_internal_tabids >*/
/* SOURCE itbidnm.cmn:8 */
/*<       save/itabidnum/ >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:3645 */
/*<       get_kount_of_internal_tabids=kount_of_internal_tabids >*/
    ret_val = itabidnum_1.feq_gen_kount_of_internal_tabids_d_;
/* SOURCE fqshrftb.for:3646 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrftb.for:3647 */
/*<       end >*/
} /* get_kount_of_internal_tabids__ */




/* SOURCE fqshrftb.for:3651 */
/*<       subroutinereset_kount_of_internal_tabids() >*/
/* Subroutine */ int feq_gen_reset_kount_of_internal_tabids_d_()
{
/*     Initialize the KOUNT_OF_INTERNAL_TABIDS */
/* INCLUDE fqshrftb.for:3655 */
/*     Common for the counter for the number of internally */
/*     generated table ids */
/* SOURCE itbidnm.cmn:4 */
/*<       integerkount_of_internal_tabids >*/
/* SOURCE itbidnm.cmn:6 */
/*<       common/itabidnum/kount_of_internal_tabids >*/
/* SOURCE itbidnm.cmn:8 */
/*<       save/itabidnum/ >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:3657 */
/*<       kount_of_internal_tabids=0 >*/
    itabidnum_1.feq_gen_kount_of_internal_tabids_d_ = 0;
/* SOURCE fqshrftb.for:3658 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:3659 */
/*<       end >*/
} /* reset_kount_of_internal_tabids__ */




/* SOURCE fqshrftb.for:3664 */
/*<       integerfunctionnextn() >*/
integer nextn_()
{
    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer ret_val, feq_gen_i_d_1[2];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_internal_tab_number_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char char6[6];
    integer eflag;
    char tabid[16];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__427 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Use to assign an internally generated table id that */
/*     cannot be duplicated by the user on input.  Will be */
/*     to make sure that the internal table numbers follow */
/*     a standard pattern.  Needed in FEQUTL because we cannot */
/*     ensure that all user tables are stored before any */
/*     cross-section interpolation requests are made. */
/*     This can and is done in FEQ. */
/* SOURCE fqshrftb.for:3676 */
/*<       implicitnone >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:3678 */
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
/* INCLUDE fqshrftb.for:3679 */
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
/* INCLUDE fqshrftb.for:3680 */
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
/* INCLUDE fqshrftb.for:3681 */
/*     Common for the counter for the number of internally */
/*     generated table ids */
/* SOURCE itbidnm.cmn:4 */
/*<       integerkount_of_internal_tabids >*/
/* SOURCE itbidnm.cmn:6 */
/*<       common/itabidnum/kount_of_internal_tabids >*/
/* SOURCE itbidnm.cmn:8 */
/*<       save/itabidnum/ >*/
/*     Called program units */
/* SOURCE fqshrftb.for:3685 */
/*<       externalget_internal_tab_number >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:3689 */
/*<       integeri,eflag,internal_tab_number >*/
/* SOURCE fqshrftb.for:3690 */
/*<       charactertabid*16,char6*6 >*/
/* *********************************************************************** */
/*     Create a tabid that contains special characters that cannot */
/*     appear in a valid tabid supplied in the input.  Index so */
/*     that we will be unique. */
/* SOURCE fqshrftb.for:3697 */
/*<       kount_of_internal_tabids=kount_of_internal_tabids+1 >*/
    ++itabidnum_1.feq_gen_kount_of_internal_tabids_d_;
/* SOURCE fqshrftb.for:3698 */
/*<       write(char6,'(I6)')kount_of_internal_tabids >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 6;
    feq_gen_ici_d_1.iciunit = char6;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I6)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&itabidnum_1.feq_gen_kount_of_internal_tabids_d_, (ftnlen)
	    sizeof(integer));
    e_wsfi();
/* SOURCE fqshrftb.for:3699 */
/*<       tabid='Internal:'//char6 >*/
/* Writing concatenation */
    feq_gen_i_d_1[0] = 9, feq_gen_a_d_1[0] = const_cast<char*>("Internal:");
    feq_gen_i_d_1[1] = 6, feq_gen_a_d_1[1] = char6;
    s_cat(tabid, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_2, (ftnlen)16);
/* SOURCE fqshrftb.for:3700 */
/*<       eflag=0 >*/
    eflag = 0;
/* SOURCE fqshrftb.for:3701 */
/*<       callget_internal_tab_number(std6,tabid,eflag,internal_tab_number) >*/
    feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, tabid, &eflag, &
	    feq_gen_internal_tab_number_d_, (ftnlen)16);
/* SOURCE fqshrftb.for:3705 */
/*<       if(eflag.ne.0)then >*/
    if (eflag != 0) {
/* SOURCE fqshrftb.for:3706 */
/*<        >*/
	feq_gen_io_d__427.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__427);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:164* Tabid table exhausted by cross-sect\
ion interpolations"), (ftnlen)64);
	e_wsle();
/* SOURCE fqshrftb.for:3708 */
/*<       stop'Abnormal stop.  Error found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3709 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:3710 */
/*<       nextn=internal_tab_number >*/
    ret_val = feq_gen_internal_tab_number_d_;
/* SOURCE fqshrftb.for:3711 */
/*<       return >*/
    return ret_val;
/* SOURCE fqshrftb.for:3712 */
/*<       end >*/
} /* nextn_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:3716 */
/*<       subroutinereset_last_level(adrs) >*/
/* Subroutine */ int feq_gen_reset_last_level_d_(integer *adrs)
{
    /* Local variables */
    integer la;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Reset the last level accessed in a cross-section function table */
/*     to the default value. */
/* SOURCE fqshrftb.for:3721 */
/*<       integeradrs >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:3724 */
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
/* INCLUDE fqshrftb.for:3725 */
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
/* SOURCE fqshrftb.for:3727 */
/*<       integerla >*/
/* *********************************************************************** */
/*     Compute address of the first level ( Low Address) in the table. */
/* SOURCE fqshrftb.for:3731 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:3732 */
/*<       itab(adrs+3)=la >*/
    itab[*adrs + 3] = la;
/* SOURCE fqshrftb.for:3733 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:3734 */
/*<       end >*/
} /* reset_last_level__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:3739 */
/*<        >*/
/* Subroutine */ int scan_(integer *stdout, integer *nbra, integer *nbn, 
	integer *mft, integer *mlft, integer *feq_storage_brpt, integer *feq_storage_nsec, real *feq_storage_xvec,
	 real *feq_storage_zvec, real *sfac, integer *eflag, integer *ftp, integer *ftknt)
{
    /* Format strings */
    static char fmt_10[] = "(/,\002 \002,i5,\002 X-sections interpolated bet\
ween \002,\002 stations\002,f10.3,\002 and\002,f10.3,/,5x,\002 Max. depth =\
 \002,f10.3,\002 NUMBER OF DEPTH VALUES = \002,i5)";
    static char fmt_11[] = "(5x,\002 Start internal Tabid#=\002,i6,\002 End \
internal Tabid#=\002,i6)";
    static char fmt_12[] = "(6x,\002There are now \002,i6,\002 function tabl\
es and \002,i8,\002 locations left in FTAB.\002)";
    static char fmt_16[] = "(\002 *ERR:148* in branch \002,i5,\002 There hav\
e been \002,i4,\002 consecutive interpolation\002,/,9x,\002requests.  Onl\
y\002,i5,\002 are \002,\002allowed.\002)";
    static char fmt_18[] = "(/,\002 *ERR:407* Ups Tabid=\002,a16,\002 has sl\
ot depth=\002,f10.3,/,\002 but dns Tabid=\002,a16,\002 has slot depth=\002,f\
10.3,/,\002 Both must\002,\002 be 0.0 or both must be > 0.0 for interpolatio\
n.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3, feq_gen_i_d_4;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_merge_with_slot_d_(integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *);
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_reset_last_level_d_(integer *);
    integer n;
    real x[150], y[1000], feq_gen_z_d_[150];
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer feq_gen_start_knt_d_, ib, nd, fn, ln;
    real xl, xr;
    extern /* Subroutine */ int feq_gen_make_yslot_d_(integer *, integer *, integer *, 
	    real *, real *, integer *, real *);
    real feq_gen_yslot_left_d_[1010];
    integer tab[150];
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    real sdl;
    integer nin;
    real sdr, xtl, xtr, feq_gen_yslot_right_d_[1010];
    integer itab, tabl, node[150], tabr, newn;
    extern /* Subroutine */ int rdup_(integer *, real *, integer *), merge_(
	    integer *, integer *, integer *, integer *, integer *, real *);
    extern integer nextn_(), feq_gen_get_kount_of_internal_tabids_d_(), gettbn_(
	    integer *), getusb_(integer *);
    integer sloteq;
    extern /* Subroutine */ int interp_(integer *, integer *, integer *, real 
	    *, real *, integer *, integer *, integer *, integer *, real *, 
	    real *, integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *);
    extern doublereal feq_gen_get_slot_depth_d_(integer *);
    integer feq_gen_end_knt_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__439 = { 0, 0, 0, fmt_16, 0 };
    static cilist feq_gen_io_d__456 = { 0, 0, 0, fmt_18, 0 };
    static cilist feq_gen_io_d__457 = { 0, 0, 0, fmt_18, 0 };
    static cilist feq_gen_io_d__462 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__463 = { 0, 0, 0, fmt_11, 0 };
    static cilist feq_gen_io_d__464 = { 0, 0, 0, fmt_12, 0 };


/*     + + + PURPOSE + + + */
/*     Scan the branch tables to find requests for interpolation */
/*     and do the requested interpolation. */
/* SOURCE fqshrftb.for:3748 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:3750 */
/*<       integereflag,ftknt,ftp,stdout,mft,mlft,nbn,nbra >*/
/* SOURCE fqshrftb.for:3751 */
/*<       integerbrpt(8,nbra),nsec(nbn) >*/
/* SOURCE fqshrftb.for:3752 */
/*<       realsfac,xvec(nbn),zvec(nbn) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     MFT    - maximum function table pointer value.  Same as maximum */
/*               function table number */
/*     MLFT   - maximum length of FTAB/ITAB */
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
/*     NSEC   - address of cross section table at a node on a branch */
/*     XVEC   - station values for each node on a branch */
/*     ZVEC   - bottom profile elevations for nodes on a branch */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     FTP    - next open location in the function table storage */
/*     FTKNT  - function table counter */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:3780 */
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
/* SOURCE fqshrftb.for:3782 */
/*<       integermaxndep >*/
/* SOURCE fqshrftb.for:3783 */
/*<       parameter(maxndep=mndep+npslot) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:3786 */
/*<        >*/
/* SOURCE fqshrftb.for:3789 */
/*<       integernode(mnmid),tab(mnmid) >*/
/* SOURCE fqshrftb.for:3791 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:3795 */
/*<       intrinsiciabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE fqshrftb.for:3798 */
/*<       integergetusb,nextn,get_kount_of_internal_tabids,gettbn >*/
/* SOURCE fqshrftb.for:3799 */
/*<       realget_slot_depth >*/
/* SOURCE fqshrftb.for:3800 */
/*<       character*16get_tabid >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:3804 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:3808 */
/*<    10  >*/
/* SOURCE fqshrftb.for:3811 */
/*<    11 format(5x,' Start internal Tabid#=',i6,' End internal Tabid#=',i6) >*/
/* SOURCE fqshrftb.for:3813 */
/*<    12  >*/
/* SOURCE fqshrftb.for:3815 */
/*<    16  >*/
/* SOURCE fqshrftb.for:3818 */
/*<    18  >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:3822 */
/*<       do200ib=1,nbra >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<real> zvec(feq_storage_zvec, 1);

    feq::IndexedPointer<real> xvec(feq_storage_xvec, 1);

    feq::IndexedPointer<integer> nsec(feq_storage_nsec, 1);

    /* Function Body */
/* L10: */
/* L11: */
/* L12: */
/* L16: */
/* L18: */
    feq_gen_i_d_1 = *nbra;
    for (ib = 1; ib <= feq_gen_i_d_1; ++ib) {
/* SOURCE fqshrftb.for:3823 */
/*<       fn=brpt(3,ib) >*/
	fn = brpt[(ib << 3) + 3];
/* SOURCE fqshrftb.for:3824 */
/*<       ln=brpt(4,ib) >*/
	ln = brpt[(ib << 3) + 4];
/* SOURCE fqshrftb.for:3826 */
/*<       start_knt=get_kount_of_internal_tabids() >*/
	feq_gen_start_knt_d_ = feq_gen_get_kount_of_internal_tabids_d_();
/* SOURCE fqshrftb.for:3827 */
/*<       nin=0 >*/
	nin = 0;
/* SOURCE fqshrftb.for:3828 */
/*<       do100nd=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (nd = fn; nd <= feq_gen_i_d_2; ++nd) {
/* SOURCE fqshrftb.for:3829 */
/*<       itab=nsec(nd) >*/
	    itab = nsec[nd];
/* SOURCE fqshrftb.for:3830 */
/*<       if(itab.gt.0)goto50 >*/
	    if (itab > 0) {
		goto L50;
	    }
/*         KEEP RECORD OF all NEGATIVE VALUES HERE */
/* SOURCE fqshrftb.for:3832 */
/*<       nin=nin+1 >*/
	    ++nin;
/* SOURCE fqshrftb.for:3833 */
/*<       if(nin.gt.mnmid)then >*/
	    if (nin > 150) {
/* SOURCE fqshrftb.for:3834 */
/*<       write(stdout,16)getusb(ib),nin,mnmid >*/
		feq_gen_io_d__439.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__439);
		feq_gen_i_d_3 = getusb_(&ib);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&nin, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_150, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE fqshrftb.for:3835 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:3836 */
/*<       endif >*/
	    }
/*         Assign a valid internal table number to */
/*         interpolation requests given with only a - */
/* SOURCE fqshrftb.for:3840 */
/*<       if(itab.eq.-1000000)then >*/
	    if (itab == -1000000) {
/* SOURCE fqshrftb.for:3841 */
/*<       itab=nextn() >*/
		itab = nextn_();
/* SOURCE fqshrftb.for:3842 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:3843 */
/*<       itab=iabs(itab) >*/
	    itab = abs(itab);
/* SOURCE fqshrftb.for:3844 */
/*<       if(itab.gt.mft)callkil(9,itab,eflag) >*/
	    if (itab > *mft) {
		kil_(&feq_gen_c_d_9, &itab, eflag);
	    }
/* SOURCE fqshrftb.for:3847 */
/*<       tab(nin)=itab >*/
	    tab[nin - 1] = itab;
/* SOURCE fqshrftb.for:3848 */
/*<       x(nin)=xvec(nd) >*/
	    x[nin - 1] = xvec[nd];
/* SOURCE fqshrftb.for:3849 */
/*<       z(nin)=zvec(nd) >*/
	    feq_gen_z_d_[nin - 1] = zvec[nd];
/* SOURCE fqshrftb.for:3850 */
/*<       node(nin)=nd >*/
	    node[nin - 1] = nd;
/* SOURCE fqshrftb.for:3851 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE fqshrftb.for:3852 */
/*<    50 continue >*/
L50:
/* SOURCE fqshrftb.for:3853 */
/*<       if(nin.eq.0)goto70 >*/
	    if (nin == 0) {
		goto L70;
	    }
/*           WE HAVE FOUND THE TERMINAL KNOWN CROSS-SECTION AFTER */
/*           A REQUEST  FOR ONE OR MORE INTERPOLATIONS */
/* SOURCE fqshrftb.for:3856 */
/*<       tabr=itab >*/
	    tabr = itab;
/* SOURCE fqshrftb.for:3857 */
/*<       xr=xvec(nd) >*/
	    xr = xvec[nd];
/*           PROCESS THE REQUESTS FOR INTERPOLATION. */
/*           ESTABLISH THE DEPTH VALUES FOR INTERPOLATION */
/* SOURCE fqshrftb.for:3861 */
/*<       sdl=abs(get_slot_depth(tabl)) >*/
	    sdl = (feq_gen_r_d_1 = feq_gen_get_slot_depth_d_(&tabl), dabs(feq_gen_r_d_1));
/* SOURCE fqshrftb.for:3862 */
/*<       sdr=abs(get_slot_depth(tabr)) >*/
	    sdr = (feq_gen_r_d_1 = feq_gen_get_slot_depth_d_(&tabr), dabs(feq_gen_r_d_1));
/* SOURCE fqshrftb.for:3863 */
/*<       if(sdl.gt.0.0.and.sdr.gt.0.0)then >*/
	    if (sdl > (float)0. && sdr > (float)0.) {
/*             both have a slot.  If the slots are of equal depth */
/*             we will taken the depth sequence as is.  The machinations */
/*             we go thrhough when the slot depths are unequal are needed */
/*             to make sense in that situation.  However, in practice, we */
/*             avoid having slots that are of unequal depth. */
/* SOURCE fqshrftb.for:3870 */
/*<       if(2.*abs(sdl-sdr)/(sdr+sdl).le.0.0001)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(sdl) - sdr, dabs(feq_gen_r_d_1)) * (float)2. / (static_cast<double>(sdr) + sdl) 
			<= (float)1e-4) {
/*               take the slots to be equal! */
/* SOURCE fqshrftb.for:3872 */
/*<       sloteq=1 >*/
		    sloteq = 1;
/* SOURCE fqshrftb.for:3874 */
/*<       callmerge(stdout,tabl,tabr,eflag,n,y) >*/
		    merge_(stdout, &tabl, &tabr, eflag, &n, y);
/* SOURCE fqshrftb.for:3877 */
/*<       else >*/
		} else {
/* SOURCE fqshrftb.for:3878 */
/*<       sloteq=0 >*/
		    sloteq = 0;
/* SOURCE fqshrftb.for:3879 */
/*<       callmerge_with_slot(stdout,tabl,tabr,eflag,n,y,sdl,sdr) >*/
		    feq_gen_merge_with_slot_d_(stdout, &tabl, &tabr, eflag, &n, y, &
			    sdl, &sdr);
/* SOURCE fqshrftb.for:3882 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:3883 */
/*<       else >*/
	    } else {
/*             neither has a slot */
/* SOURCE fqshrftb.for:3885 */
/*<       callmerge(stdout,tabl,tabr,eflag,n,y) >*/
		merge_(stdout, &tabl, &tabr, eflag, &n, y);
/* SOURCE fqshrftb.for:3888 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:3890 */
/*<       callrdup(n,y,newn) >*/
	    rdup_(&n, y, &newn);
/* SOURCE fqshrftb.for:3895 */
/*<       n=newn >*/
	    n = newn;
/*           Y(*) contains the unique series of depth values, relative to */
/*           the real invert but only if both have a slot and the slots are of */
/*           unequal depth. */
/*           Construct a vector for each of the two tables */
/*           that contains a depth sequence relative to the bottom elevation */
/*           of the slot if both have a slot.  If only one has a slot, it */
/*           is an error.  Mixtures potentially create interpolated sections */
/*           that are not what we want. */
/* SOURCE fqshrftb.for:3906 */
/*<       if(sdl.eq.0.0)then >*/
	    if (sdl == (float)0.) {
/* SOURCE fqshrftb.for:3907 */
/*<       if(sdr.eq.0.0)then >*/
		if (sdr == (float)0.) {
/*               No slot present.  Transfer Y(*) to each vector. */
/* SOURCE fqshrftb.for:3909 */
/*<       do52i=1,n >*/
		    feq_gen_i_d_3 = n;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:3910 */
/*<       yslot_left(i)=y(i) >*/
			feq_gen_yslot_left_d_[feq_gen_i_d_ - 1] = y[feq_gen_i_d_ - 1];
/* SOURCE fqshrftb.for:3911 */
/*<       yslot_right(i)=y(i) >*/
			feq_gen_yslot_right_d_[feq_gen_i_d_ - 1] = y[feq_gen_i_d_ - 1];
/* SOURCE fqshrftb.for:3912 */
/*<    52 continue >*/
/* L52: */
		    }
/* SOURCE fqshrftb.for:3913 */
/*<       else >*/
		} else {
/* SOURCE fqshrftb.for:3914 */
/*<        >*/
		    feq_gen_io_d__456.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__456);
		    feq_gen_i_d_3 = gettbn_(&tabl);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_3);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, (char *)&sdl, (ftnlen)sizeof(real));
		    feq_gen_i_d_4 = gettbn_(&tabr);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &feq_gen_i_d_4);
		    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, (char *)&sdr, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE fqshrftb.for:3916 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE fqshrftb.for:3917 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:3918 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:3919 */
/*<       if(sdr.eq.0.0)then >*/
		if (sdr == (float)0.) {
/* SOURCE fqshrftb.for:3920 */
/*<        >*/
		    feq_gen_io_d__457.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__457);
		    feq_gen_i_d_3 = gettbn_(&tabl);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_3);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, (char *)&sdl, (ftnlen)sizeof(real));
		    feq_gen_i_d_4 = gettbn_(&tabr);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &feq_gen_i_d_4);
		    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, (char *)&sdr, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE fqshrftb.for:3922 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE fqshrftb.for:3923 */
/*<       else >*/
		} else {
/*               Both have a slot here. */
/* SOURCE fqshrftb.for:3925 */
/*<       if(sloteq.eq.1)then >*/
		    if (sloteq == 1) {
/*                 slots are of equal depth.  Y(*) already contains the merged depths */
/*                 for the section INCLUDING the slots. */
/* SOURCE fqshrftb.for:3928 */
/*<       doi=1,n >*/
			feq_gen_i_d_3 = n;
			for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:3929 */
/*<       yslot_left(i)=y(i) >*/
			    feq_gen_yslot_left_d_[feq_gen_i_d_ - 1] = y[feq_gen_i_d_ - 1];
/* SOURCE fqshrftb.for:3930 */
/*<       yslot_right(i)=y(i) >*/
			    feq_gen_yslot_right_d_[feq_gen_i_d_ - 1] = y[feq_gen_i_d_ - 1];
/* SOURCE fqshrftb.for:3931 */
/*<       enddo >*/
			}
/* SOURCE fqshrftb.for:3932 */
/*<       else >*/
		    } else {
/* SOURCE fqshrftb.for:3933 */
/*<       callmake_yslot(maxndep,npslot,n,sdl,y,newn,yslot_left) >*/
			feq_gen_make_yslot_d_(&feq_gen_c_d_1010, &feq_gen_c_d_10, &n, &sdl, y, &newn, 
				feq_gen_yslot_left_d_);
/* SOURCE fqshrftb.for:3936 */
/*<       callmake_yslot(maxndep,npslot,n,sdr,y,newn,yslot_right) >*/
			feq_gen_make_yslot_d_(&feq_gen_c_d_1010, &feq_gen_c_d_10, &n, &sdr, y, &newn, 
				feq_gen_yslot_right_d_);
/* SOURCE fqshrftb.for:3939 */
/*<       n=newn >*/
			n = newn;
/* SOURCE fqshrftb.for:3940 */
/*<       endif >*/
		    }
/* SOURCE fqshrftb.for:3941 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:3942 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:3944 */
/*<        >*/
	    interp_(stdout, &tabl, &tabr, &xl, &xr, &n, nbn, &nin, mlft, x, 
		    feq_gen_z_d_, tab, node, sfac, feq_gen_yslot_left_d_, feq_gen_yslot_right_d_, eflag, 
		    ftp, &nsec[1]);
/*           Interpolation has changed the stored value of the address */
/*           of the last level accessed.  This must be reset to the */
/*           default so that potential adjustment of conveyance */
/*           which follows will take place. */
/* SOURCE fqshrftb.for:3955 */
/*<       callreset_last_level(tabl) >*/
	    feq_gen_reset_last_level_d_(&tabl);
/* SOURCE fqshrftb.for:3956 */
/*<       callreset_last_level(tabr) >*/
	    feq_gen_reset_last_level_d_(&tabr);
/* SOURCE fqshrftb.for:3958 */
/*<       end_knt=get_kount_of_internal_tabids() >*/
	    feq_gen_end_knt_d_ = feq_gen_get_kount_of_internal_tabids_d_();
/*           REPORT OPERATIONS */
/* SOURCE fqshrftb.for:3961 */
/*<       xtl=xl/sfac >*/
	    xtl = static_cast<double>(xl) / *sfac;
/* SOURCE fqshrftb.for:3962 */
/*<       xtr=xr/sfac >*/
	    xtr = static_cast<double>(xr) / *sfac;
/* SOURCE fqshrftb.for:3963 */
/*<       write(stdout,10)nin,xtl,xtr,yslot_left(n),n >*/
	    feq_gen_io_d__462.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__462);
	    do_fio(&feq_gen_c_d_1, (char *)&nin, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&xtl, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xtr, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_yslot_left_d_[n - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE fqshrftb.for:3964 */
/*<       if(start_knt.lt.end_knt)then >*/
	    if (feq_gen_start_knt_d_ < feq_gen_end_knt_d_) {
/* SOURCE fqshrftb.for:3965 */
/*<       write(stdout,11)start_knt+1,end_knt >*/
		feq_gen_io_d__463.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__463);
		feq_gen_i_d_3 = feq_gen_start_knt_d_ + 1;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_end_knt_d_, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE fqshrftb.for:3966 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:3967 */
/*<       ftknt=ftknt+nin >*/
	    *ftknt += nin;
/* SOURCE fqshrftb.for:3968 */
/*<       write(stdout,12)ftknt,mrftab-ftp >*/
	    feq_gen_io_d__464.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__464);
	    do_fio(&feq_gen_c_d_1, (char *)&(*ftknt), (ftnlen)sizeof(integer));
	    feq_gen_i_d_3 = 13000001 - *ftp;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
	    e_wsfe();
/*           INITIALIZE AS IF NEXT SECTION IS A REQUEST FOR INTERP */
/* SOURCE fqshrftb.for:3971 */
/*<       start_knt=end_knt >*/
	    feq_gen_start_knt_d_ = feq_gen_end_knt_d_;
/* SOURCE fqshrftb.for:3972 */
/*<       tabl=tabr >*/
	    tabl = tabr;
/* SOURCE fqshrftb.for:3973 */
/*<       xl=xr >*/
	    xl = xr;
/* SOURCE fqshrftb.for:3974 */
/*<       nin=0 >*/
	    nin = 0;
/* SOURCE fqshrftb.for:3975 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE fqshrftb.for:3976 */
/*<    70 continue >*/
L70:
/* SOURCE fqshrftb.for:3977 */
/*<       tabl=itab >*/
	    tabl = itab;
/* SOURCE fqshrftb.for:3978 */
/*<       xl=xvec(nd) >*/
	    xl = xvec[nd];
/* SOURCE fqshrftb.for:3979 */
/*<   100 continue >*/
L100:
	    ;
	}
/* SOURCE fqshrftb.for:3980 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE fqshrftb.for:3981 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:3982 */
/*<       end >*/
} /* scan_ */




/* SOURCE fqshrftb.for:3986 */
/*<        >*/
/* Subroutine */ int feq_gen_put_location_2dtab_d_(integer *adrs, char *zone, char *
	hgrid, char *vdatum, char *unitsys, char *basis, doublereal *easting, 
	doublereal *northing, ftnlen zone_len, ftnlen hgrid_len, ftnlen 
	vdatum_len, ftnlen unitsys_len, ftnlen basis_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int feq_gen_put_dp_in_ft_d_(integer *, doublereal *), 
	    feq_gen_put_chr8_in_ft_d_(integer *, char *, ftnlen);

/*     Store the location, datum, basis information in a two-d table. */
/* SOURCE fqshrftb.for:3991 */
/*<       implicitnone >*/
/* INCLUDE fqshrftb.for:3993 */
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
/* INCLUDE fqshrftb.for:3994 */
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
/* SOURCE fqshrftb.for:3996 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:3997 */
/*<       real*8easting,northing >*/
/* SOURCE fqshrftb.for:3998 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/*     External program units */
/* SOURCE fqshrftb.for:4001 */
/*<       externalput_chr8_in_ft,put_dp_in_ft >*/
/*     ****************************************************************** */
/* SOURCE fqshrftb.for:4003 */
/*<       callput_chr8_in_ft(adrs+12,zone) >*/
    feq_gen_i_d_1 = *adrs + 12;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, zone, (ftnlen)8);
/* SOURCE fqshrftb.for:4004 */
/*<       callput_chr8_in_ft(adrs+14,hgrid) >*/
    feq_gen_i_d_1 = *adrs + 14;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, hgrid, (ftnlen)8);
/* SOURCE fqshrftb.for:4005 */
/*<       callput_chr8_in_ft(adrs+16,vdatum) >*/
    feq_gen_i_d_1 = *adrs + 16;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, vdatum, (ftnlen)8);
/* SOURCE fqshrftb.for:4006 */
/*<       callput_chr8_in_ft(adrs+18,unitsys) >*/
    feq_gen_i_d_1 = *adrs + 18;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, unitsys, (ftnlen)8);
/* SOURCE fqshrftb.for:4007 */
/*<       callput_dp_in_ft(adrs+20,easting) >*/
    feq_gen_i_d_1 = *adrs + 20;
    feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, easting);
/* SOURCE fqshrftb.for:4008 */
/*<       callput_dp_in_ft(adrs+22,northing) >*/
    feq_gen_i_d_1 = *adrs + 22;
    feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, northing);
/* SOURCE fqshrftb.for:4009 */
/*<       callput_chr8_in_ft(adrs+24,basis) >*/
    feq_gen_i_d_1 = *adrs + 24;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, basis, (ftnlen)8);
/* SOURCE fqshrftb.for:4010 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:4011 */
/*<       end >*/
} /* put_location_2dtab__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:4015 */
/*<        >*/
/* Subroutine */ int twodin_(integer *in, integer *stdout, integer *mlft, 
	integer *table, real *hdatum, char *chr69, real *zrhufd, integer *
	eflag, integer *ftp, integer *feq_gen_type_d_, ftnlen chr69_len)
{
    /* Initialized data */

    static char blank[8+1] = "        ";
    static doublereal dnull = -3.3e7;

    /* Format strings */
    static char fmt_1[] = "(80a)";
    static char fmt_2[] = "(2f10.0)";
    static char fmt_4[] = "(2f10.0)";
    static char fmt_6[] = "(5x,a8,7x,a8,8x,a8,9x,a8,7x,a8)";
    static char fmt_8[] = "(8x,f15.0,10x,f15.0)";
    static char fmt_10[] = "(5x,i5)";
    static char fmt_12[] = "(7x,10f7.0)";
    static char fmt_14[] = "(11f7.0)";
    static char fmt_50[] = "(/,\002 \002,a80)";
    static char fmt_51[] = "(\002 \002,a80)";
    static char fmt_52[] = "(\002 \002,2f10.3)";
    static char fmt_54[] = "(\002 \002,2f10.3)";
    static char fmt_56[] = "(/,\0020*ERR:77* FIRST VALUE OF P FOR CONSTANT H\
EAD LINE\002,\002 NOT ZERO. P=\002,f10.3)";
    static char fmt_58[] = "(/,\0020*ERR:78* P DECREASES P=\002,f10.3,\002 P\
OLD=\002,f10.3)";
    static char fmt_62[] = "(/,\0020*ERR:79* VALUES OF UPSTREAM HEAD ARE DEC\
REASING\002,\002 IN 2-D TABLE.\002)";
    static char fmt_68[] = "(/,\0020*ERR:547* COLUMN ARGUMENTS MUST BE STRIC\
TLY\002,\002 INCREASING\002)";
    static char fmt_70[] = "(\002 NHUP=\002,i5)";
    static char fmt_71[] = "(\002 NPFD=\002,i5)";
    static char fmt_72[] = "(/,\002 *ERR:367* Conversion error in reading us\
er format for\002,\002 Type 10 table:\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3, feq_gen_i_d_4;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), do_fio(
	    integer *, char *, ftnlen), e_rsfi(), f_back(alist *), s_wsfe(
	    cilist *), e_wsfe(), s_rsli(icilist *), do_lio(integer *, integer 
	    *, char *, ftnlen), e_rsli(), s_wsle(cilist *), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal northing;
    integer feq_gen_i_d_, j, k, n;
    real p, q;
    integer je, ip, js;
    real hu;
    extern /* Subroutine */ int feq_gen_put_location_2dtab_d_(integer *, char *, char *
	    , char *, char *, char *, doublereal *, doublereal *, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen);
    integer inc;
    real pfd;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer ihu, nhu, phu, out;
    extern /* Subroutine */ int feq_gen_chk_vdatum_unitsys_d_(integer *, char *, char *
	    , char *, ftnlen, ftnlen, ftnlen);
    char chr3[3];
    extern /* Subroutine */ int feq_gen_feq_adjustl_d_(char *, char *, ftnlen, ftnlen);
    char head[80];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char hdin[24], feq_gen_feql_adjust5_d_[8];
    integer npfd;
    char line[80];
    integer ppfd;
    real pold, qvec[10], drop;
    integer nhup;
    char zone[8];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer qpnt, jbase, nargc;
    real fdvec[10];
    char hgrid[8], basis[8];
    integer nargr;
    real oldhu;
    char hdout[24], rowin[24], line120[120], colarg[8*19];
    real oldarg, colvec[19];
    char hditem[24];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    char rowlab[8];
    integer ftpold;
    real hupvec[10], rowarg;
    char vdatum[8], rowout[24];
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);
    integer feq_gen_max_col_d_, ftpbase;
    doublereal easting;
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__486 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__492 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__493 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__495 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__499 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__500 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__502 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__503 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__511 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__518 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__522 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__524 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__526 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__534 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__536 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__539 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__541 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__544 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__545 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__546 = { 0, 0, 0, fmt_72, 0 };


/*     + + + PURPOSE + + + */
/*     Input two-D tables */
/* SOURCE fqshrftb.for:4023 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:4025 */
/*<       integereflag,ftp,in,stdout,mlft,table,type >*/
/* SOURCE fqshrftb.for:4026 */
/*<       realhdatum,zrhufd >*/
/* SOURCE fqshrftb.for:4027 */
/*<       characterchr69*69 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     MLFT   - maximum length of FTAB/ITAB */
/*     TABLE  - table number */
/*     HDATUM - datum for heads */
/*     CHR69  - optional format for reading function tables of type 10 */
/*     zrhufd - free drop at zero ups head if it makes sense in context. */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     FTP    - next open location in the function table storage */
/*     TYPE   - table type */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:4042 */
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
/* INCLUDE fqshrftb.for:4043 */
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
/* INCLUDE fqshrftb.for:4044 */
/*     common for passing info for table upgrading-going from one form */
/*     to one that is smoother in its representation */
/* SOURCE tabupgrade.cmn:4 */
/*<       characterty13_to_ty43*4,twod_cubic_out*4,upgrade_xsec_tab*4 >*/
/* SOURCE tabupgrade.cmn:6 */
/*<       common/upgrdc/ty13_to_ty43,twod_cubic_out,upgrade_xsec_tab >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:4047 */
/*<       characterblank*8 >*/
/* SOURCE fqshrftb.for:4048 */
/*<       saveblank >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:4051 */
/*<        >*/
/* SOURCE fqshrftb.for:4054 */
/*<        >*/
/* SOURCE fqshrftb.for:4056 */
/*<       real*8easting,northing,dnull >*/
/* SOURCE fqshrftb.for:4057 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:4062 */
/*<       intrinsicmin >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:4065 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE fqshrftb.for:4015 */
/*<       character*8 feql_adjust5 >*/
/* SOURCE fqshrftb.for:4069 */
/*<       datablank/'      '/,dnull/-33d6/ >*/
/* SOURCE fqshrftb.for:4072 */
/*<     1 format(80a) >*/
/* L1: */
/* SOURCE fqshrftb.for:4073 */
/*<     2 format(2f10.0) >*/
/* L2: */
/* SOURCE fqshrftb.for:4074 */
/*<     4 format(2f10.0) >*/
/* L4: */
/* SOURCE fqshrftb.for:4075 */
/*<     6 format(5x,a8,7x,a8,8x,a8,9x,a8,7x,a8) >*/
/* L6: */
/* SOURCE fqshrftb.for:4076 */
/*<     8 format(8x,f15.0,10x,f15.0) >*/
/* L8: */
/* SOURCE fqshrftb.for:4078 */
/*<    10 format(5x,i5) >*/
/* L10: */
/* SOURCE fqshrftb.for:4079 */
/*<    12 format(7x,10f7.0) >*/
/* L12: */
/* SOURCE fqshrftb.for:4080 */
/*<    14 format(11f7.0) >*/
/* L14: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:4083 */
/*<    50 format(/,' ',a80) >*/
/* L50: */
/* SOURCE fqshrftb.for:4084 */
/*<    51 format(' ',a80) >*/
/* L51: */
/* SOURCE fqshrftb.for:4085 */
/*<    52 format(' ',2f10.3) >*/
/* L52: */
/* SOURCE fqshrftb.for:4086 */
/*<    54 format(' ',2f10.3) >*/
/* L54: */
/* SOURCE fqshrftb.for:4087 */
/*<    56  >*/
/* L56: */
/* SOURCE fqshrftb.for:4089 */
/*<    58 format(/,'0*ERR:78* P DECREASES P=',f10.3,' POLD=',f10.3) >*/
/* L58: */
/* SOURCE fqshrftb.for:4090 */
/*<    62  >*/
/* L62: */
/* SOURCE fqshrftb.for:4092 */
/*<    68  >*/
/* L68: */
/* SOURCE fqshrftb.for:4094 */
/*<    70 format(' NHUP=',i5) >*/
/* L70: */
/* SOURCE fqshrftb.for:4095 */
/*<    71 format(' NPFD=',i5) >*/
/* L71: */
/* SOURCE fqshrftb.for:4096 */
/*<    72  >*/
/* L72: */
/* *********************************************************************** */
/* SOURCE fqshrftb.for:4099 */
/*<       zone='NONE' >*/
    s_copy(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:4100 */
/*<       hgrid='NONE' >*/
    s_copy(hgrid, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:4101 */
/*<       vdatum='NONE' >*/
    s_copy(vdatum, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:4102 */
/*<       unitsys='NONE' >*/
    s_copy(unitsys, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:4103 */
/*<       basis='NONE' >*/
    s_copy(basis, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:4105 */
/*<       easting=dnull >*/
    easting = dnull;
/* SOURCE fqshrftb.for:4106 */
/*<       northing=dnull >*/
    northing = dnull;

/* SOURCE fqshrftb.for:4108 */
/*<       if(ftp+tdtioff.ge.mlft)callkil(10,ftp,eflag) >*/
    if (*ftp + 26 >= *mlft) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/*     STORE THE DATUM FOR HEADS FOR THIS TABLE.  Also save the base value */
/*     of FTP for possible use later. */
/* SOURCE fqshrftb.for:4114 */
/*<       ftab(ftp)=hdatum >*/
    ftab[*ftp] = *hdatum;
/* SOURCE fqshrftb.for:4115 */
/*<       ftpbase=ftp >*/
    ftpbase = *ftp;
/* SOURCE fqshrftb.for:4116 */
/*<       itab(ftp+1)=table >*/
    itab[*ftp + 1] = *table;
/* SOURCE fqshrftb.for:4117 */
/*<       if(type.gt.0)then >*/
    if (*feq_gen_type_d_ > 0) {
/* SOURCE fqshrftb.for:4118 */
/*<       out=1 >*/
	out = 1;
/* SOURCE fqshrftb.for:4119 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:4120 */
/*<       type=-type >*/
	*feq_gen_type_d_ = -(*feq_gen_type_d_);
/* SOURCE fqshrftb.for:4121 */
/*<       out=0 >*/
	out = 0;
/* SOURCE fqshrftb.for:4122 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:4123 */
/*<       itab(ftp+2)=type >*/
    itab[*ftp + 2] = *feq_gen_type_d_;
/* SOURCE fqshrftb.for:4124 */
/*<       ftpold=ftp >*/
    ftpold = *ftp;
/* SOURCE fqshrftb.for:4126 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4130 */
/*<       if(line(1:4)=='ZONE')then >*/
    if (s_cmp(line, const_cast<char*>("ZONE"), (ftnlen)4, (ftnlen)4) == 0) {
/*       We have a line of information on zone, hgrid, vdatum, and unitsys. */
/*       If present it will ALWAYS be followed by a line giving the hgrid location! */
/* SOURCE fqshrftb.for:4133 */
/*<       read(line,6,err=991)zone,hgrid,vdatum,unitsys,basis >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_6;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:4134 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4137 */
/*<       callfeq_adjustl(zone,feql_adjust5) >*/
	feq_gen_feq_adjustl_d_(zone, feq_gen_feql_adjust5_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:4137 */
/*<       if(feql_adjust5=='NA')then >*/
	if (s_cmp(feq_gen_feql_adjust5_d_, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) == 0) {
/*         Horizontal location has no meaning. */
/* SOURCE fqshrftb.for:4139 */
/*<       easting=dnull >*/
	    easting = dnull;
/* SOURCE fqshrftb.for:4140 */
/*<       northing=dnull >*/
	    northing = dnull;
/* SOURCE fqshrftb.for:4141 */
/*<       ft_loc_status(table)='N' >*/
	    *(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*table - 1] = 'N';
/* SOURCE fqshrftb.for:4142 */
/*<       elseif(line(9:23)==' ')then >*/
	} else if (s_cmp(line + 8, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1) == 0) {
/*         The easting value was blank.  This means that it was */
/*         missing.  We treat the northing as missing too. */
/* SOURCE fqshrftb.for:4145 */
/*<       easting=dnull >*/
	    easting = dnull;
/* SOURCE fqshrftb.for:4146 */
/*<       northing=dnull >*/
	    northing = dnull;
/* SOURCE fqshrftb.for:4147 */
/*<       ft_loc_status(table)='M' >*/
	    *(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*table - 1] = 'M';
/* SOURCE fqshrftb.for:4148 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:4149 */
/*<       read(line,8,err=991)easting,northing >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_8;
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal))
		    ;
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal)
		    );
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
/* SOURCE fqshrftb.for:4150 */
/*<       if(easting>dnull)then >*/
	    if (easting > dnull) {
/*           We assume valid value for both. */
/* SOURCE fqshrftb.for:4152 */
/*<       ft_loc_status(table)='I' >*/
		*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*table - 1] = 
			'I';
/* SOURCE fqshrftb.for:4153 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:4154 */
/*<       ft_loc_status(table)='M' >*/
		*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*table - 1] = 
			'M';
/* SOURCE fqshrftb.for:4155 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:4156 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:4157 */
/*<       else >*/
    } else {
/*       Put the line back!  Zone, hgrid, etc, not present. */
/* SOURCE fqshrftb.for:4159 */
/*<       backspace(in) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *in;
	f_back(&feq_gen_al_d_1);
/* SOURCE fqshrftb.for:4160 */
/*<       ft_loc_status(table)='M' >*/
	*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*table - 1] = 'M';
/* SOURCE fqshrftb.for:4161 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:4163 */
/*<        >*/
    feq_gen_put_location_2dtab_d_(ftp, zone, hgrid, vdatum, unitsys, basis, &easting, &
	    northing, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrftb.for:4166 */
/*<        >*/
    feq_gen_chk_vdatum_unitsys_d_(stdout, vdatum, unitsys, const_cast<char*>(" during input of twod tab\
les"), (ftnlen)8, (ftnlen)8, (ftnlen)28);
/* SOURCE fqshrftb.for:4169 */
/*<       if(type.eq.6)then >*/
    if (*feq_gen_type_d_ == 6) {
/* SOURCE fqshrftb.for:4170 */
/*<       ftp=ftp+tdtioff >*/
	*ftp += 26;
/*       SET POINTER VALUES FOR THE UPSTREAM LEVELS */
/* SOURCE fqshrftb.for:4173 */
/*<       itab(ftpold+3)=ftp >*/
	itab[ftpold + 3] = *ftp;
/* SOURCE fqshrftb.for:4174 */
/*<       itab(ftpold+4)=ftp >*/
	itab[ftpold + 4] = *ftp;
/* SOURCE fqshrftb.for:4176 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4179 */
/*<       read(line,1)head >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_rsfi();
/* SOURCE fqshrftb.for:4180 */
/*<       write(stdout,50)head >*/
	feq_gen_io_d__486.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__486);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_wsfe();
/*       INPUT THE UPSTREAM HEAD AND THE HEAD DROP TO FREE FLOW */
/* SOURCE fqshrftb.for:4184 */
/*<       nhu=0 >*/
	nhu = 0;
/* SOURCE fqshrftb.for:4185 */
/*<       inc=5 >*/
	inc = 5;
/* SOURCE fqshrftb.for:4186 */
/*<       oldhu=-1.0 >*/
	oldhu = (float)-1.;
/* SOURCE fqshrftb.for:4187 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:4188 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4191 */
/*<       read(line,2,err=991)hu,drop >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_2;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&hu, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:4192 */
/*<       if(hu.lt.0.0)goto110 >*/
	if (hu < (float)0.) {
	    goto L110;
	}
/* SOURCE fqshrftb.for:4193 */
/*<       if(out.eq.1)write(stdout,52)hu,drop >*/
	if (out == 1) {
	    feq_gen_io_d__492.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__492);
	    do_fio(&feq_gen_c_d_1, (char *)&hu, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
	    e_wsfe();
	}
/* SOURCE fqshrftb.for:4194 */
/*<       if(hu.le.oldhu)then >*/
	if (hu <= oldhu) {
/* SOURCE fqshrftb.for:4195 */
/*<       write(stdout,62) >*/
	    feq_gen_io_d__493.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__493);
	    e_wsfe();
/* SOURCE fqshrftb.for:4196 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrftb.for:4197 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:4198 */
/*<       oldhu=hu >*/
	oldhu = hu;
/* SOURCE fqshrftb.for:4199 */
/*<       nhu=nhu+1 >*/
	++nhu;
/* SOURCE fqshrftb.for:4200 */
/*<       if(ftp+inc.ge.mlft)callkil(10,ftp,eflag) >*/
	if (*ftp + inc >= *mlft) {
	    kil_(&feq_gen_c_d_10, ftp, eflag);
	}
/* SOURCE fqshrftb.for:4203 */
/*<       ftab(ftp)=hu >*/
	ftab[*ftp] = hu;
/* SOURCE fqshrftb.for:4204 */
/*<       ftab(ftp+1)=drop >*/
	ftab[*ftp + 1] = drop;
/* SOURCE fqshrftb.for:4205 */
/*<       ftp=ftp+inc >*/
	*ftp += inc;
/* SOURCE fqshrftb.for:4206 */
/*<       goto100 >*/
	goto L100;
/* SOURCE fqshrftb.for:4207 */
/*<   110 continue >*/
L110:
/*       SET THE MAXIMUM UPSTREAM HEAD VALUE */
/* SOURCE fqshrftb.for:4211 */
/*<       ftab(ftpold+9)=ftab(ftp-inc) >*/
	ftab[ftpold + 9] = ftab[*ftp - inc];
/*       INPUT THE VALUES DEFINING THE LINES OF CONSTANT UPSTREAM HEAD */
/*       SET POINTERS FOR THE UPSTREAM HEAD VALUES */
/* SOURCE fqshrftb.for:4217 */
/*<       ip=itab(ftpold+3) >*/
	ip = itab[ftpold + 3];
/* SOURCE fqshrftb.for:4219 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4222 */
/*<       read(line,1)head >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_rsfi();
/* SOURCE fqshrftb.for:4223 */
/*<       write(stdout,50)head >*/
	feq_gen_io_d__495.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__495);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_wsfe();
/* SOURCE fqshrftb.for:4225 */
/*<       do300j=1,nhu >*/
	feq_gen_i_d_1 = nhu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fqshrftb.for:4226 */
/*<       if(ftp+2.ge.mlft)callkil(10,ftp,eflag) >*/
	    if (*ftp + 2 >= *mlft) {
		kil_(&feq_gen_c_d_10, ftp, eflag);
	    }
/* SOURCE fqshrftb.for:4229 */
/*<       callinline(in,stdout,line) >*/
	    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4232 */
/*<       read(line,4,err=991)p,q >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_4;
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&q, (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/* SOURCE fqshrftb.for:4233 */
/*<       if(out.eq.1)write(stdout,54)p,q >*/
	    if (out == 1) {
		feq_gen_io_d__499.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__499);
		do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&q, (ftnlen)sizeof(real));
		e_wsfe();
	    }
/* SOURCE fqshrftb.for:4234 */
/*<       if(p.ne.0.0)then >*/
	    if (p != (float)0.) {
/* SOURCE fqshrftb.for:4235 */
/*<       write(stdout,56)p >*/
		feq_gen_io_d__500.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__500);
		do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE fqshrftb.for:4236 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE fqshrftb.for:4237 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:4238 */
/*<       pold=p >*/
	    pold = p;
/*         SET POINTERS FOR THIS CONSTANT HEAD LINE */
/* SOURCE fqshrftb.for:4241 */
/*<       itab(ip+2)=ftp >*/
	    itab[ip + 2] = *ftp;
/* SOURCE fqshrftb.for:4242 */
/*<       itab(ip+3)=ftp >*/
	    itab[ip + 3] = *ftp;
/* SOURCE fqshrftb.for:4244 */
/*<       ftab(ftp)=p >*/
	    ftab[*ftp] = p;
/* SOURCE fqshrftb.for:4245 */
/*<       ftab(ftp+1)=q >*/
	    ftab[*ftp + 1] = q;
/* SOURCE fqshrftb.for:4246 */
/*<       ftp=ftp+2 >*/
	    *ftp += 2;
/* SOURCE fqshrftb.for:4249 */
/*<   200 continue >*/
L200:
/* SOURCE fqshrftb.for:4250 */
/*<       if(ftp+2.ge.mlft)callkil(10,ftp,eflag) >*/
	    if (*ftp + 2 >= *mlft) {
		kil_(&feq_gen_c_d_10, ftp, eflag);
	    }
/* SOURCE fqshrftb.for:4253 */
/*<       callinline(in,stdout,line) >*/
	    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4256 */
/*<       read(line,4,err=991)p,q >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_4;
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&q, (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/* SOURCE fqshrftb.for:4257 */
/*<       if(out.eq.1)write(stdout,54)p,q >*/
	    if (out == 1) {
		feq_gen_io_d__502.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__502);
		do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&q, (ftnlen)sizeof(real));
		e_wsfe();
	    }
/* SOURCE fqshrftb.for:4258 */
/*<       if(p.le.pold)then >*/
	    if (p <= pold) {
/* SOURCE fqshrftb.for:4259 */
/*<       write(stdout,58)p,pold >*/
		feq_gen_io_d__503.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__503);
		do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&pold, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE fqshrftb.for:4260 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE fqshrftb.for:4261 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:4262 */
/*<       pold=p >*/
	    pold = p;
/* SOURCE fqshrftb.for:4263 */
/*<       ftab(ftp)=p >*/
	    ftab[*ftp] = p;
/* SOURCE fqshrftb.for:4264 */
/*<       ftab(ftp+1)=q >*/
	    ftab[*ftp + 1] = q;
/* SOURCE fqshrftb.for:4265 */
/*<       ftp=ftp+2 >*/
	    *ftp += 2;
/* SOURCE fqshrftb.for:4266 */
/*<       if(p.eq.1.0)goto210 >*/
	    if (p == (float)1.) {
		goto L210;
	    }
/* SOURCE fqshrftb.for:4267 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE fqshrftb.for:4268 */
/*<   210 continue >*/
L210:
/*         STORE THE FREE FLOW IN THE MAIN TABLE */
/* SOURCE fqshrftb.for:4271 */
/*<       ftab(ip+4)=q >*/
	    ftab[ip + 4] = q;
/* SOURCE fqshrftb.for:4272 */
/*<       ip=ip+inc >*/
	    ip += inc;
/* SOURCE fqshrftb.for:4273 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE fqshrftb.for:4275 */
/*<       elseif(type.eq.10)then >*/
    } else if (*feq_gen_type_d_ == 10) {
/*       PROCESS TABLE TYPE=10. TRADITIONAL TWO-D TABLE */
/*       MEANING OF ARGUMENTS DEPENDS ON CONTEXT OF USE OF THE */
/*       TABLE. */
/*       Set formats for processing the table. */
/* SOURCE fqshrftb.for:4281 */
/*<       if(chr69.ne.' ')then >*/
	if (s_cmp(chr69, const_cast<char*>(" "), (ftnlen)69, (ftnlen)1) != 0) {
/* SOURCE fqshrftb.for:4282 */
/*<       line=chr69 >*/
	    s_copy(line, chr69, (ftnlen)80, (ftnlen)69);
/* SOURCE fqshrftb.for:4283 */
/*<       read(chr69,*,err=991)hdin,hdout,hditem,rowin,rowout >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 69;
	    feq_gen_ici_d_1.iciunit = chr69;
	    feq_gen_ici_d_1.icifmt = 0;
	    feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, hdin, (ftnlen)24);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, hdout, (ftnlen)24);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, hditem, (ftnlen)24);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, rowin, (ftnlen)24);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, rowout, (ftnlen)24);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = e_rsli();
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
/*         Try to find the number of columns from the provided format. */
/*         Assumes that HDIN will start (xxA...) where xx is one, two */
/*         or three digits. */
/* SOURCE fqshrftb.for:4288 */
/*<       callstrip_l_blanks(hdin) >*/
	    feq_gen_strip_l_blanks_d_(hdin, (ftnlen)24);
/*          WRITE(STDOUT,*) ' HDIN=',HDIN */
/* SOURCE fqshrftb.for:4291 */
/*<       chr3=hdin(2:4) >*/
	    s_copy(chr3, hdin + 1, (ftnlen)3, (ftnlen)3);
/*          WRITE(STDOUT,*) ' CHR3=',CHR3 */
/* SOURCE fqshrftb.for:4293 */
/*<       if(chr3(2:2).eq.'A'.or.chr3(2:2).eq.'a')then >*/
	    if (*(unsigned char *)&chr3[1] == 'A' || *(unsigned char *)&chr3[
		    1] == 'a') {
/*           There is one digit. */
/* SOURCE fqshrftb.for:4295 */
/*<       read(chr3(1:1),'(I1)',err=993)max_col >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 1;
		feq_gen_ici_d_1.iciunit = chr3;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(I1)");
		feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_col_d_, (ftnlen)sizeof(
			integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
		feq_gen_i_d_1 = e_rsfi();
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
/* SOURCE fqshrftb.for:4296 */
/*<       max_col=max_col-1 >*/
		--feq_gen_max_col_d_;
/* SOURCE fqshrftb.for:4297 */
/*<       elseif(chr3(3:3).eq.'A'.or.chr3(3:3).eq.'a')then >*/
	    } else if (*(unsigned char *)&chr3[2] == 'A' || *(unsigned char *)
		    &chr3[2] == 'a') {
/*           There are two digits */
/* SOURCE fqshrftb.for:4299 */
/*<       read(chr3(1:2),'(I2)',err=993)max_col >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 2;
		feq_gen_ici_d_1.iciunit = chr3;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(I2)");
		feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_col_d_, (ftnlen)sizeof(
			integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
		feq_gen_i_d_1 = e_rsfi();
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
/* SOURCE fqshrftb.for:4300 */
/*<       max_col=max_col-1 >*/
		--feq_gen_max_col_d_;
/* SOURCE fqshrftb.for:4301 */
/*<       else >*/
	    } else {
/*           Assume there are 3 digits. */
/* SOURCE fqshrftb.for:4303 */
/*<       read(chr3(1:3),'(I3)',err=993)max_col >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 3;
		feq_gen_ici_d_1.iciunit = chr3;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(I3)");
		feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_col_d_, (ftnlen)sizeof(
			integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
		feq_gen_i_d_1 = e_rsfi();
		if (feq_gen_i_d_1 != 0) {
		    goto L993;
		}
/* SOURCE fqshrftb.for:4304 */
/*<       max_col=max_col-1 >*/
		--feq_gen_max_col_d_;
/* SOURCE fqshrftb.for:4305 */
/*<       endif >*/
	    }
/*          WRITE(STDOUT,*) ' MAX_COL=',MAX_COL */
/* SOURCE fqshrftb.for:4308 */
/*<       else >*/
	} else {
/*         Use the default values. */
/* SOURCE fqshrftb.for:4310 */
/*<       hdin='(20A6)' >*/
	    s_copy(hdin, const_cast<char*>("(20A6)"), (ftnlen)24, (ftnlen)6);
/* SOURCE fqshrftb.for:4311 */
/*<       hdout='(1X,20A6)' >*/
	    s_copy(hdout, const_cast<char*>("(1X,20A6)"), (ftnlen)24, (ftnlen)9);
/* SOURCE fqshrftb.for:4312 */
/*<       hditem='(F6.0)' >*/
	    s_copy(hditem, const_cast<char*>("(F6.0)"), (ftnlen)24, (ftnlen)6);
/* SOURCE fqshrftb.for:4313 */
/*<       rowin='(20F6.0)' >*/
	    s_copy(rowin, const_cast<char*>("(20F6.0)"), (ftnlen)24, (ftnlen)8);
/* SOURCE fqshrftb.for:4314 */
/*<       rowout='(1X,F6.2,19F6.3)' >*/
	    s_copy(rowout, const_cast<char*>("(1X,F6.2,19F6.3)"), (ftnlen)24, (ftnlen)16);
/* SOURCE fqshrftb.for:4315 */
/*<       max_col=19 >*/
	    feq_gen_max_col_d_ = 19;
/* SOURCE fqshrftb.for:4316 */
/*<       endif >*/
	}
/*       READ AND ECHO THE LABEL FOR THE TABLE, this might also be the */
/*       optional line giving the head datum for the table. */
/* SOURCE fqshrftb.for:4321 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4324 */
/*<       if(line(1:6).eq.'HDATUM')then >*/
	if (s_cmp(line, const_cast<char*>("HDATUM"), (ftnlen)6, (ftnlen)6) == 0) {
/* SOURCE fqshrftb.for:4325 */
/*<       read(line(8:17),'(F10.0)',err=991)hdatum >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 10;
	    feq_gen_ici_d_1.iciunit = line + 7;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*hdatum), (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
/*         Store HDATUM */
/* SOURCE fqshrftb.for:4327 */
/*<       ftab(ftpbase)=hdatum >*/
	    ftab[ftpbase] = *hdatum;
/* SOURCE fqshrftb.for:4328 */
/*<       callinline(in,stdout,line) >*/
	    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4331 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:4332 */
/*<       read(line,1)head >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_rsfi();
/* SOURCE fqshrftb.for:4333 */
/*<       write(stdout,50)head >*/
	feq_gen_io_d__511.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__511);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_wsfe();
/*       READ argument heading and count the number of arguments on the */
/*       columns of the table. */
/* SOURCE fqshrftb.for:4338 */
/*<       callinline(in,stdout,line120) >*/
	inline_(in, stdout, line120, (ftnlen)120);
/* SOURCE fqshrftb.for:4341 */
/*<       read(line120,hdin,err=992)rowlab,(colarg(j),j=1,max_col) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 120;
	feq_gen_ici_d_1.iciunit = line120;
	feq_gen_ici_d_1.icifmt = feq::format_text(hdin, sizeof(hdin));
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L992;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, rowlab, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L992;
	}
	feq_gen_i_d_2 = feq_gen_max_col_d_;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, colarg + (j - 1 << 3), (ftnlen)8);
	    if (feq_gen_i_d_1 != 0) {
		goto L992;
	    }
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L992;
	}
/* SOURCE fqshrftb.for:4342 */
/*<       if(out.eq.1)write(stdout,hdout)rowlab,(colarg(j),j=1,max_col) >*/
	if (out == 1) {
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *stdout;
	    feq_gen_ci_d_1.cifmt = feq::format_text(hdout, sizeof(hdout));
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, rowlab, (ftnlen)8);
	    feq_gen_i_d_1 = feq_gen_max_col_d_;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
		do_fio(&feq_gen_c_d_1, colarg + (j - 1 << 3), (ftnlen)8);
	    }
	    e_wsfe();
	}
/* SOURCE fqshrftb.for:4343 */
/*<       nargc=0 >*/
	nargc = 0;
/* SOURCE fqshrftb.for:4344 */
/*<       oldarg=-1.e35 >*/
	oldarg = (float)-1e35;
/* SOURCE fqshrftb.for:4345 */
/*<       do600j=1,max_col >*/
	feq_gen_i_d_1 = feq_gen_max_col_d_;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fqshrftb.for:4346 */
/*<       if(colarg(j).ne.blank)then >*/
	    if (s_cmp(colarg + (j - 1 << 3), blank, (ftnlen)8, (ftnlen)8) != 
		    0) {
/* SOURCE fqshrftb.for:4347 */
/*<       nargc=nargc+1 >*/
		++nargc;
/* SOURCE fqshrftb.for:4348 */
/*<       read(colarg(j),hditem,err=991)colvec(j) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 8;
		feq_gen_ici_d_1.iciunit = colarg + (j - 1 << 3);
		feq_gen_ici_d_1.icifmt = feq::format_text(hditem, sizeof(hditem));
		feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&colvec[j - 1], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
		feq_gen_i_d_2 = e_rsfi();
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
/* SOURCE fqshrftb.for:4349 */
/*<       if(colvec(j).le.oldarg)then >*/
		if (colvec[j - 1] <= oldarg) {
/* SOURCE fqshrftb.for:4350 */
/*<       write(stdout,68)j >*/
		    feq_gen_io_d__518.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__518);
		    do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE fqshrftb.for:4351 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE fqshrftb.for:4352 */
/*<       endif >*/
		}
/* SOURCE fqshrftb.for:4353 */
/*<       oldarg=colvec(j) >*/
		oldarg = colvec[j - 1];
/* SOURCE fqshrftb.for:4354 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:4355 */
/*<   600 continue >*/
/* L600: */
	}
/*       STORE THE COLUMN ARGUMENTS */
/* SOURCE fqshrftb.for:4359 */
/*<       ftp=ftp+tdtioff >*/
	*ftp += 26;
/*       ESTABLISH PARGC, HARGC, LARGC, AND NARGC IN THE HEADER */
/* SOURCE fqshrftb.for:4362 */
/*<       itab(ftpold+7)=ftp >*/
	itab[ftpold + 7] = *ftp;
/* SOURCE fqshrftb.for:4363 */
/*<       itab(ftpold+8)=ftp+nargc-1 >*/
	itab[ftpold + 8] = *ftp + nargc - 1;
/* SOURCE fqshrftb.for:4364 */
/*<       itab(ftpold+9)=ftp >*/
	itab[ftpold + 9] = *ftp;
/* SOURCE fqshrftb.for:4365 */
/*<       itab(ftpold+10)=nargc >*/
	itab[ftpold + 10] = nargc;
/*       STORE THE VALUES */
/* SOURCE fqshrftb.for:4368 */
/*<       if(ftp+nargc.ge.mlft)callkil(10,ftp,eflag) >*/
	if (*ftp + nargc >= *mlft) {
	    kil_(&feq_gen_c_d_10, ftp, eflag);
	}
/* SOURCE fqshrftb.for:4372 */
/*<       do610j=1,nargc >*/
	feq_gen_i_d_1 = nargc;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fqshrftb.for:4373 */
/*<       ftab(ftp+j-1)=colvec(j) >*/
	    ftab[*ftp + j - 1] = colvec[j - 1];
/* SOURCE fqshrftb.for:4374 */
/*<   610 continue >*/
/* L610: */
	}
/* SOURCE fqshrftb.for:4376 */
/*<       ftp=ftp+nargc >*/
	*ftp += nargc;
/*       READ AND STORE THE ROW ARGUMENTS AND THE ROW CONTENTS */
/*       ESTABLISH PARGR, AND LARGR */
/* SOURCE fqshrftb.for:4382 */
/*<       itab(ftpold+3)=ftp >*/
	itab[ftpold + 3] = *ftp;
/* SOURCE fqshrftb.for:4383 */
/*<       itab(ftpold+5)=ftp >*/
	itab[ftpold + 5] = *ftp;
/* SOURCE fqshrftb.for:4385 */
/*<       nargr=0 >*/
	nargr = 0;
/* SOURCE fqshrftb.for:4386 */
/*<       oldarg=-1.e35 >*/
	oldarg = (float)-1e35;
/* SOURCE fqshrftb.for:4387 */
/*<   700 continue >*/
L700:
/* SOURCE fqshrftb.for:4388 */
/*<       callinline(in,stdout,line120) >*/
	inline_(in, stdout, line120, (ftnlen)120);
/* SOURCE fqshrftb.for:4391 */
/*<       read(line120,rowin,err=992)rowarg,(colvec(j),j=1,nargc) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 120;
	feq_gen_ici_d_1.iciunit = line120;
	feq_gen_ici_d_1.icifmt = feq::format_text(rowin, sizeof(rowin));
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L992;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&rowarg, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L992;
	}
	feq_gen_i_d_2 = nargc;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&colvec[j - 1], (ftnlen)sizeof(real))
		    ;
	    if (feq_gen_i_d_1 != 0) {
		goto L992;
	    }
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L992;
	}
/* SOURCE fqshrftb.for:4392 */
/*<       if(rowarg.gt.oldarg)then >*/
	if (rowarg > oldarg) {
/* SOURCE fqshrftb.for:4393 */
/*<       oldarg=rowarg >*/
	    oldarg = rowarg;
/* SOURCE fqshrftb.for:4394 */
/*<       if(out.eq.1)write(stdout,rowout)rowarg,(colvec(j),j=1,nargc) >*/
	    if (out == 1) {
		feq_gen_ci_d_1.cierr = 0;
		feq_gen_ci_d_1.ciunit = *stdout;
		feq_gen_ci_d_1.cifmt = feq::format_text(rowout, sizeof(rowout));
		s_wsfe(&feq_gen_ci_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&rowarg, (ftnlen)sizeof(real));
		feq_gen_i_d_1 = nargc;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
		    do_fio(&feq_gen_c_d_1, (char *)&colvec[j - 1], (ftnlen)sizeof(real)
			    );
		}
		e_wsfe();
	    }
/*           PROCESS THIS ROW OF INFORMATION */
/* SOURCE fqshrftb.for:4398 */
/*<       if(ftp+nargc+1.ge.mlft)callkil(10,ftp,eflag) >*/
	    if (*ftp + nargc + 1 >= *mlft) {
		kil_(&feq_gen_c_d_10, ftp, eflag);
	    }
/* SOURCE fqshrftb.for:4402 */
/*<       nargr=nargr+1 >*/
	    ++nargr;
/* SOURCE fqshrftb.for:4403 */
/*<       ftab(ftp)=rowarg >*/
	    ftab[*ftp] = rowarg;
/* SOURCE fqshrftb.for:4404 */
/*<       ftp=ftp+1 >*/
	    ++(*ftp);
/* SOURCE fqshrftb.for:4405 */
/*<       do710j=1,nargc >*/
	    feq_gen_i_d_1 = nargc;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fqshrftb.for:4406 */
/*<       ftab(ftp)=colvec(j) >*/
		ftab[*ftp] = colvec[j - 1];
/* SOURCE fqshrftb.for:4407 */
/*<       ftp=ftp+1 >*/
		++(*ftp);
/* SOURCE fqshrftb.for:4408 */
/*<   710 continue >*/
/* L710: */
	    }
/* SOURCE fqshrftb.for:4410 */
/*<       goto700 >*/
	    goto L700;
/* SOURCE fqshrftb.for:4411 */
/*<       else >*/
	} else {
/*           INPUT COMPLETE. ESTABLISH HARGR AND NARGR IN HEADER */
/* SOURCE fqshrftb.for:4413 */
/*<       itab(ftpold+4)=ftp-nargc-1 >*/
	    itab[ftpold + 4] = *ftp - nargc - 1;
/* SOURCE fqshrftb.for:4414 */
/*<       itab(ftpold+6)=nargr >*/
	    itab[ftpold + 6] = nargr;
/* SOURCE fqshrftb.for:4415 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:4416 */
/*<       elseif(type.eq.13.or.type.eq.14)then >*/
    } else if (*feq_gen_type_d_ == 13 || *feq_gen_type_d_ == 14) {
/*       SET POINTER VALUES FOR THE UPSTREAM HEAD */
/* SOURCE fqshrftb.for:4420 */
/*<       phu=ftp+tdtioff >*/
	phu = *ftp + 26;
/*        WRITE(STDOUT,*) ' PHU=',PHU */
/*       STORE POINTER TO THE START OF THE DOWNSTREAM HEADS. */
/* SOURCE fqshrftb.for:4425 */
/*<       if(type.eq.14)then >*/
	if (*feq_gen_type_d_ == 14) {
/* SOURCE fqshrftb.for:4426 */
/*<       itab(ftpold+3)=phu+1 >*/
	    itab[ftpold + 3] = phu + 1;
/* SOURCE fqshrftb.for:4427 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:4428 */
/*<       itab(ftpold+3)=phu >*/
	    itab[ftpold + 3] = phu;
/* SOURCE fqshrftb.for:4429 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:4431 */
/*<       itab(ftpold+4)=phu >*/
	itab[ftpold + 4] = phu;
/*       READ AND ECHO THE LABEL */
/* SOURCE fqshrftb.for:4434 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4437 */
/*<       read(line,1)head >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_rsfi();
/* SOURCE fqshrftb.for:4438 */
/*<       write(stdout,51)head >*/
	feq_gen_io_d__522.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__522);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_wsfe();
/*       GET THE NUMBER OF NON-ZERO UPSTREAM HEADS */
/* SOURCE fqshrftb.for:4441 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4444 */
/*<       read(line,10,err=991)nhup >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_10;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nhup, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:4445 */
/*<       if(out.eq.1)write(stdout,70)nhup >*/
	if (out == 1) {
	    feq_gen_io_d__524.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__524);
	    do_fio(&feq_gen_c_d_1, (char *)&nhup, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/*       GET NUMBER OF NON-ZERO PARTIAL FREE DROPS */
/* SOURCE fqshrftb.for:4448 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4451 */
/*<       read(line,10,err=991)npfd >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_10;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&npfd, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:4452 */
/*<       if(out.eq.1)write(stdout,71)npfd >*/
	if (out == 1) {
	    feq_gen_io_d__526.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__526);
	    do_fio(&feq_gen_c_d_1, (char *)&npfd, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/*       CHECK FOR SPACE */
/* SOURCE fqshrftb.for:4455 */
/*<       n=tdtioff+4*(nhup+1)+(nhup+2)*(npfd+1) >*/
	n = (nhup + 1 << 2) + 26 + (nhup + 2) * (npfd + 1);
/* SOURCE fqshrftb.for:4456 */
/*<       if(ftp+n.ge.mlft)callkil(10,ftp,eflag) >*/
	if (*ftp + n >= *mlft) {
	    kil_(&feq_gen_c_d_10, ftp, eflag);
	}
/*       COMPUTE THE START LOCATION FOR PARTIAL FREE DROPS. NOTE: */
/*       ZERO UPSTREAM HEAD, ZERO PARTIAL FREE DROP, ZERO FLOWS ARE */
/*       NOT IN THE INPUT TABLE BUT THEY WILL BE STORED TO MAKE */
/*       SEARCHING AND TABLE LOOKUP SIMPLER AND SAFER.  THERE ARE */
/*       4 VALUES STORED AT EACH UPSTREAM HEAD: THE UPSTREAM HEAD, */
/*       THE FREE DROP, THE FREE FLOW, AND A POINTER TO THE */
/*       FLOWS FOR THE PARTIAL FREE DROPS. */
/*       FOR TABLE TYPE 14 THE VALUES DIFFER.  THE */
/*       CORRESPONDENCE IS: */
/*           TYPE 13                 TYPE 14 */
/*       UPSTREAM HEAD            FREE FLOW */
/*       FREE DROPS               DOWNSTREAM HEAD */
/*       PARTIAL FREE DROPS       PARTIAL FREE FLOWS */
/*       FLOWS                    UPSTREAM HEADS */
/*       AT ZERO DOWNSTREAM HEAD THE FREE FLOW AND UPSTREAM HEAD */
/*       ARE ZERO.  AT A PARTIAL FREE FLOW OF ZERO HOWEVER THE */
/*       UPSTREAM HEAD IS THE SAME AS THE DOWNSTREAM HEAD. */
/*       ALL VARIABLES ARE NAMED ACCORDING TO THEIR TYPE 13 ROLE. */
/* SOURCE fqshrftb.for:4482 */
/*<       ppfd=phu+4*(nhup+1) >*/
	ppfd = phu + (nhup + 1 << 2);
/*        WRITE(STDOUT,*) ' PPFD=',PPFD */
/* SOURCE fqshrftb.for:4484 */
/*<       itab(ftpold+5)=ppfd >*/
	itab[ftpold + 5] = ppfd;
/* SOURCE fqshrftb.for:4485 */
/*<       itab(ftpold+6)=ppfd >*/
	itab[ftpold + 6] = ppfd;
/*       Set the source flag location */
/* SOURCE fqshrftb.for:4488 */
/*<       if(type.eq.14)then >*/
	if (*feq_gen_type_d_ == 14) {
/* SOURCE fqshrftb.for:4489 */
/*<       if(chr69(1:5).eq.'WSPRO')then >*/
	    if (s_cmp(chr69, const_cast<char*>("WSPRO"), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE fqshrftb.for:4490 */
/*<       itab(ftpold+7)=1 >*/
		itab[ftpold + 7] = 1;
/* SOURCE fqshrftb.for:4491 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:4492 */
/*<       itab(ftpold+7)=0 >*/
		itab[ftpold + 7] = 0;
/* SOURCE fqshrftb.for:4493 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:4494 */
/*<       endif >*/
	}
/*       COMPUTE THE BASE LOCATION FOR THE FLOWS IN THE TABLE */
/* SOURCE fqshrftb.for:4498 */
/*<       qpnt=ppfd+npfd+1 >*/
	qpnt = ppfd + npfd + 1;
/*        WRITE(STDOUT,*) ' QPNT=',QPNT */
/*       STORE THE VALUES FOR ZERO UPSTREAM HEAD */
/* SOURCE fqshrftb.for:4503 */
/*<       ftab(phu)=0.0 >*/
	ftab[phu] = (float)0.;
/* SOURCE fqshrftb.for:4504 */
/*<       ftab(phu+1)=0.0 >*/
	ftab[phu + 1] = (float)0.;
/* SOURCE fqshrftb.for:4505 */
/*<       ftab(phu+2)=0.0 >*/
	ftab[phu + 2] = (float)0.;
/* SOURCE fqshrftb.for:4506 */
/*<       if(type.eq.13)then >*/
	if (*feq_gen_type_d_ == 13) {
/*         set the free drop at zero upstream head  if we are going to convert to type 43 */
/* SOURCE fqshrftb.for:4508 */
/*<       if(ty13_to_ty43.eq.'YES'.or.ty13_to_ty43.eq.'YESO')then >*/
	    if (s_cmp(upgrdc_1.feq_gen_ty13_to_ty43_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) ==
		     0 || s_cmp(upgrdc_1.feq_gen_ty13_to_ty43_d_, const_cast<char*>("YESO"), (ftnlen)4, (
		    ftnlen)4) == 0) {
/* SOURCE fqshrftb.for:4510 */
/*<       ftab(phu+1)=zrhufd >*/
		ftab[phu + 1] = *zrhufd;
/* SOURCE fqshrftb.for:4511 */
/*<       else >*/
	    } else {
/* SOURCE fqshrftb.for:4512 */
/*<       ftab(phu+1)=0.0 >*/
		ftab[phu + 1] = (float)0.;
/* SOURCE fqshrftb.for:4513 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:4514 */
/*<       endif >*/
	}
/*       STORE THE OFFSET BETWEEN THE ORIGIN OF THE PARTIAL FREE */
/*       DROP SEQUENCE AND THE ORIGIN OF THE FLOWS AT ZERO UPSTREAM */
/*       HEAD SO THAT A SINGLE ADDITION CAN BE USED TO FIND THE */
/*       FLOWS ONCE THE LOCATION OF THE PARTIAL FREE DROP ARGUMENT */
/*       IS FOUND IN THE PARTIAL FREE DROP SEQUENCE. */
/* SOURCE fqshrftb.for:4522 */
/*<       itab(phu+3)=qpnt-ppfd >*/
	itab[phu + 3] = qpnt - ppfd;
/*        WRITE(STDOUT,*) ' OFFSET AT ORIGIN=',ITAB(PHU+3) */
/*       STORE THE ZERO PARTIAL FREE DROP VALUE(TYPE 13) AND THE ZERO */
/*       PARTIAL FREE FLOW(TYPE 14). */
/* SOURCE fqshrftb.for:4528 */
/*<       ftab(ppfd)=0.0 >*/
	ftab[ppfd] = (float)0.;
/*       STORE THE ZERO FLOWS FOR ZERO UPSTREAM HEAD */
/* SOURCE fqshrftb.for:4532 */
/*<       do800i=qpnt,qpnt+npfd >*/
	feq_gen_i_d_1 = qpnt + npfd;
	for (feq_gen_i_d_ = qpnt; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:4533 */
/*<       ftab(i)=0.0 >*/
	    ftab[feq_gen_i_d_] = (float)0.;
/* SOURCE fqshrftb.for:4534 */
/*<   800 continue >*/
/* L800: */
	}
/*       STORE THE ZERO FLOWS FOR ZERO PARTIAL FREE DROPS FOR NON */
/*       ZERO HEADS.  FOR TYPE 14 OVERWRITTEN LATER BY THE */
/*       DOWNSTREAM HEAD. */
/* SOURCE fqshrftb.for:4540 */
/*<       do802i=1,nhup >*/
	feq_gen_i_d_1 = nhup;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:4541 */
/*<       ip=qpnt+i*(npfd+1) >*/
	    ip = qpnt + feq_gen_i_d_ * (npfd + 1);
/* SOURCE fqshrftb.for:4542 */
/*<       ftab(ip)=0.0 >*/
	    ftab[ip] = (float)0.;
/* SOURCE fqshrftb.for:4543 */
/*<   802 continue >*/
/* L802: */
	}
/*       NOW STORE THE VALUES FOR NON-ZERO HEAD AND NON-ZERO PARTIAL */
/*       FREE DROPS */
/*       INITALIZE BASE COUNTER FOR TYPE 14.  USED  TO STORE THE */
/*       DOWNSTREAM HEADS AT ZERO PARTIAL FREE FLOW. */
/* SOURCE fqshrftb.for:4551 */
/*<       jbase=0 >*/
	jbase = 0;
/* SOURCE fqshrftb.for:4552 */
/*<       do850i=1,nhup,10 >*/
	feq_gen_i_d_1 = nhup;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 10) {
/* SOURCE fqshrftb.for:4553 */
/*<       js=1 >*/
	    js = 1;
/* SOURCE fqshrftb.for:4554 */
/*<       je=min(10,nhup-i+1) >*/
/* Computing MIN */
	    feq_gen_i_d_2 = 10, feq_gen_i_d_3 = nhup - feq_gen_i_d_ + 1;
	    je = min(feq_gen_i_d_2,feq_gen_i_d_3);
/*         READ LINE OF UPSTREAM HEADS FOR THIS BLOCK.  FREE FLOW */
/*         FOR TYPE 14 */
/* SOURCE fqshrftb.for:4558 */
/*<       callinline(in,stdout,line) >*/
	    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4561 */
/*<       read(line,1)head >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_1;
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	    e_rsfi();
/* SOURCE fqshrftb.for:4562 */
/*<       if(out.eq.1)write(stdout,51)head >*/
	    if (out == 1) {
		feq_gen_io_d__534.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__534);
		do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
		e_wsfe();
	    }
/* SOURCE fqshrftb.for:4563 */
/*<       read(line,12,err=991)(hupvec(j),j=js,je) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_12;
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_3 = je;
	    for (j = js; j <= feq_gen_i_d_3; ++j) {
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&hupvec[j - 1], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/*         READ LINE OF FREE DROPS.  DOWNSTREAM HEADS FOR TYPE 14 */
/* SOURCE fqshrftb.for:4566 */
/*<       callinline(in,stdout,line) >*/
	    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4569 */
/*<       read(line,1)head >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_1;
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	    e_rsfi();
/* SOURCE fqshrftb.for:4570 */
/*<       if(out.eq.1)write(stdout,51)head >*/
	    if (out == 1) {
		feq_gen_io_d__536.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__536);
		do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
		e_wsfe();
	    }
/* SOURCE fqshrftb.for:4571 */
/*<       read(line,12,err=991)(fdvec(j),j=js,je) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_12;
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_3 = je;
	    for (j = js; j <= feq_gen_i_d_3; ++j) {
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&fdvec[j - 1], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/* SOURCE fqshrftb.for:4573 */
/*<       if(type.eq.14)then >*/
	    if (*feq_gen_type_d_ == 14) {
/*           STORE THE DOWNSTREAM HEADS AT ZERO PARTIAL FREE FLOW */
/* SOURCE fqshrftb.for:4575 */
/*<       do849j=js,je >*/
		feq_gen_i_d_2 = je;
		for (j = js; j <= feq_gen_i_d_2; ++j) {
/* SOURCE fqshrftb.for:4576 */
/*<       ip=qpnt+(jbase+j)*(npfd+1) >*/
		    ip = qpnt + (jbase + j) * (npfd + 1);
/* SOURCE fqshrftb.for:4577 */
/*<       ftab(ip)=fdvec(j) >*/
		    ftab[ip] = fdvec[j - 1];
/* SOURCE fqshrftb.for:4578 */
/*<   849 continue >*/
/* L849: */
		}
/* SOURCE fqshrftb.for:4579 */
/*<       endif >*/
	    }
/*         STORE THE HEADS AND DROPS WITH OFFSET BETWEEN THE */
/*         START OF THE PARTIAL FREE DROP SEQUENCE AND THE FLOW */
/*         SEQUENCE FOR EACH UPSTREAM HEAD. */
/* SOURCE fqshrftb.for:4585 */
/*<       do804j=js,je >*/
	    feq_gen_i_d_2 = je;
	    for (j = js; j <= feq_gen_i_d_2; ++j) {
/*           IHU GIVES THE COUNT OF NON ZERO UPSTREAM HEADS */
/* SOURCE fqshrftb.for:4587 */
/*<       ihu=i+j-1 >*/
		ihu = feq_gen_i_d_ + j - 1;
/* SOURCE fqshrftb.for:4588 */
/*<       ip=phu+4*ihu >*/
		ip = phu + (ihu << 2);
/* SOURCE fqshrftb.for:4589 */
/*<       ftab(ip)=hupvec(j) >*/
		ftab[ip] = hupvec[j - 1];
/* SOURCE fqshrftb.for:4590 */
/*<       ftab(ip+1)=fdvec(j) >*/
		ftab[ip + 1] = fdvec[j - 1];
/*           FREE FLOW IS FILLED AT OFFSET +2 LATER.  THIS IS */
/*           UPSTREAM HEAD AT FREE FLOW FOR TYPE 14. */
/*           STORE THE OFFSET VALUE TO START OF THE LIST OF */
/*           FLOWS FOR EACH UPSTREAM HEAD(TYPE 13) LIST OF */
/*           UPSTREAM HEADS FOR EACH DOWNSTREAM HEAD(TYPE 14) */
/* SOURCE fqshrftb.for:4598 */
/*<       itmp=qpnt+ihu*(npfd+1)-ppfd >*/
		ftablea_1.itmp = qpnt + ihu * (npfd + 1) - ppfd;
/*            WRITE(STDOUT,*) ' IP =',IP,' J=',J,' OFFSET=',ITMP */
/* SOURCE fqshrftb.for:4600 */
/*<       itab(ip+3)=itmp >*/
		itab[ip + 3] = ftablea_1.itmp;
/* SOURCE fqshrftb.for:4601 */
/*<   804 continue >*/
/* L804: */
	    }
/*         READ HEADING FOR BODY OF TABLE */
/* SOURCE fqshrftb.for:4605 */
/*<       callinline(in,stdout,line) >*/
	    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4608 */
/*<       read(line,1)head >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_1;
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	    e_rsfi();
/* SOURCE fqshrftb.for:4609 */
/*<       if(out.eq.1)write(stdout,51)head >*/
	    if (out == 1) {
		feq_gen_io_d__539.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__539);
		do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
		e_wsfe();
	    }
/*         READ THE TABLE BODY AND STORE THE NON-ZERO PARTIAL */
/*         FREE DROPS AND FLOWS.  NON-ZERO FREE FLOWS AND */
/*         UPSTREAM HEAD AT FREE FLOW FOR TYPE 14. */
/* SOURCE fqshrftb.for:4615 */
/*<       do810k=1,npfd >*/
	    feq_gen_i_d_2 = npfd;
	    for (k = 1; k <= feq_gen_i_d_2; ++k) {
/* SOURCE fqshrftb.for:4616 */
/*<       callinline(in,stdout,line) >*/
		inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4619 */
/*<       read(line,1)head >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 80;
		feq_gen_ici_d_1.iciunit = line;
		feq_gen_ici_d_1.icifmt = fmt_1;
		s_rsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
		e_rsfi();
/* SOURCE fqshrftb.for:4620 */
/*<       if(out.eq.1)write(stdout,51)head >*/
		if (out == 1) {
		    feq_gen_io_d__541.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__541);
		    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
		    e_wsfe();
		}
/* SOURCE fqshrftb.for:4621 */
/*<       read(line,14,err=991)pfd,(qvec(j),j=js,je) >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 80;
		feq_gen_ici_d_1.iciunit = line;
		feq_gen_ici_d_1.icifmt = fmt_14;
		feq_gen_i_d_3 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
		feq_gen_i_d_3 = do_fio(&feq_gen_c_d_1, (char *)&pfd, (ftnlen)sizeof(real));
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
		feq_gen_i_d_4 = je;
		for (j = js; j <= feq_gen_i_d_4; ++j) {
		    feq_gen_i_d_3 = do_fio(&feq_gen_c_d_1, (char *)&qvec[j - 1], (ftnlen)sizeof(
			    real));
		    if (feq_gen_i_d_3 != 0) {
			goto L991;
		    }
		}
		feq_gen_i_d_3 = e_rsfi();
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
/*           STORE THE VALUES */
/* SOURCE fqshrftb.for:4626 */
/*<       ftab(ppfd+k)=pfd >*/
		ftab[ppfd + k] = pfd;
/* SOURCE fqshrftb.for:4627 */
/*<       do808j=js,je >*/
		feq_gen_i_d_3 = je;
		for (j = js; j <= feq_gen_i_d_3; ++j) {
/* SOURCE fqshrftb.for:4628 */
/*<       ihu=i+j-1 >*/
		    ihu = feq_gen_i_d_ + j - 1;
/* SOURCE fqshrftb.for:4629 */
/*<       ip=qpnt+ihu*(npfd+1)+k >*/
		    ip = qpnt + ihu * (npfd + 1) + k;
/* SOURCE fqshrftb.for:4630 */
/*<       ftab(ip)=qvec(j) >*/
		    ftab[ip] = qvec[j - 1];
/* SOURCE fqshrftb.for:4631 */
/*<   808 continue >*/
/* L808: */
		}
/* SOURCE fqshrftb.for:4632 */
/*<   810 continue >*/
/* L810: */
	    }
/*         QVEC CONTAINS THE FREE FLOWS AT THIS POINT */
/* SOURCE fqshrftb.for:4635 */
/*<       do820j=js,je >*/
	    feq_gen_i_d_2 = je;
	    for (j = js; j <= feq_gen_i_d_2; ++j) {
/* SOURCE fqshrftb.for:4636 */
/*<       ihu=i+j-1 >*/
		ihu = feq_gen_i_d_ + j - 1;
/* SOURCE fqshrftb.for:4637 */
/*<       ftab(phu+4*ihu+2)=qvec(j) >*/
		ftab[phu + (ihu << 2) + 2] = qvec[j - 1];
/* SOURCE fqshrftb.for:4638 */
/*<   820 continue >*/
/* L820: */
	    }
/* SOURCE fqshrftb.for:4639 */
/*<       jbase=jbase+10 >*/
	    jbase += 10;
/* SOURCE fqshrftb.for:4640 */
/*<   850 continue >*/
/* L850: */
	}
/*       STORE THE MAXIMUM UPSTREAM HEAD. MAXIMUM FREE FLOW FOR */
/*       TYPE 14 */
/* SOURCE fqshrftb.for:4645 */
/*<       ftab(ftpold+9)=hupvec(je) >*/
	ftab[ftpold + 9] = hupvec[je - 1];
/*       STORE THE MAXIMUM DOWNSTREAM HEAD FOR TYPE 14.  IN FDVEC */
/* SOURCE fqshrftb.for:4648 */
/*<       if(type.eq.14)then >*/
	if (*feq_gen_type_d_ == 14) {
/* SOURCE fqshrftb.for:4649 */
/*<       ftab(ftpold+5)=fdvec(je) >*/
	    ftab[ftpold + 5] = fdvec[je - 1];
/* SOURCE fqshrftb.for:4650 */
/*<       endif >*/
	}
/*       UPDATE THE FUNCTION TABLE POINTER */
/* SOURCE fqshrftb.for:4654 */
/*<       ftp=ip+1 >*/
	*ftp = ip + 1;
/*       CHECK TABLE CONTENTS */
/*        WRITE(STDOUT,*) ' TABLE#=',ITAB(FTPOLD+1) */
/*        WRITE(STDOUT,*) ' TYPE=',ITAB(FTPOLD+2) */
/*        IF(TYPE.EQ.13) THEN */
/*          WRITE(STDOUT,*) ' HU BASE=',ITAB(FTPOLD+3) */
/*        ELSE */
/*          WRITE(STDOUT,*) ' HU BASE=',ITAB(FTPOLD+3) - 1 */
/*        ENDIF */
/*        WRITE(STDOUT,*) ' HU LAST=',ITAB(FTPOLD+4) */
/*        IF(TYPE.EQ.13) THEN */
/*          WRITE(STDOUT,*) ' PFD LIST BASE=',ITAB(FTPOLD+5) */
/*        ELSE */
/*          WRITE(STDOUT,*) ' MAXIMUM DNS HEAD=',FTAB(FTPOLD+5) */
/*        ENDIF */
/*        WRITE(STDOUT,*) ' PFD LIST LAST=',ITAB(FTPOLD+6) */
/*        WRITE(STDOUT,*) ' HU MAX=',FTAB(FTPOLD+9) */

/*        ITMP = ITAB(FTPOLD+3) */
/*        IF(TYPE.EQ.13) THEN */
/*          IP = ITMP */
/*        ELSE */
/*          IP = ITMP -1 */
/*        ENDIF */

/*        DO 500 I=0,NHUP */
/*          IOFF = ITAB(IP+3) */
/*          WRITE(STDOUT,72) FTAB(IP), FTAB(IP+1), FTAB(IP+2), */
/*     A                   ITAB(IP+3) */
/*          WRITE(STDOUT,*) ' PARTIAL FREE DROP LIST' */
/*          IT = ITAB(FTPOLD+6) */
/*          WRITE(STDOUT,'('' PAR DROP DISCHARGE'')') */
/* 400       CONTINUE */
/*            WRITE(STDOUT,'(F10.4,F10.2)') FTAB(IT), FTAB(IT + IOFF) */
/*            IF(FTAB(IT).EQ.1.0) GOTO 410 */
/*            IT = IT + 1 */
/*            GOTO 400 */
/* 410       CONTINUE */

/*          IP = IP + 4 */
/* 500     CONTINUE */
/* SOURCE fqshrftb.for:4697 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:4698 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:4699 */
/*<   991 continue >*/
L991:
/* SOURCE fqshrftb.for:4700 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__544.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__544);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE fqshrftb.for:4701 */
/*<       write(stdout,'(A)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE fqshrftb.for:4702 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:4703 */
/*<   992 continue >*/
L992:
/* SOURCE fqshrftb.for:4704 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__545.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__545);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE fqshrftb.for:4705 */
/*<       write(stdout,'(A)')line120 >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line120, (ftnlen)120);
    e_wsfe();
/* SOURCE fqshrftb.for:4706 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:4708 */
/*<   993 continue >*/
L993:
/* SOURCE fqshrftb.for:4709 */
/*<       write(stdout,72)hdin >*/
    feq_gen_io_d__546.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__546);
    do_fio(&feq_gen_c_d_1, hdin, (ftnlen)24);
    e_wsfe();
/* SOURCE fqshrftb.for:4710 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:4712 */
/*<       end >*/
    return 0;
} /* twodin_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:4716 */
/*<        >*/
/* Subroutine */ int feq_gen_read_tabty15_items_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, real *
	barg, integer *eflag, real *arg, integer *tab2d, real *feq_storage_f, ftnlen 
	line_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:383* Only \002,i3,\002 items given \
in a Type 15 \002,\002 table line.  Need five items.\002)";
    static char fmt_52[] = "(/,\002 *ERR:500* Conversion error in: \002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer n, ie, is;
    char tpc[20];
    integer feq_gen_internal_tab_number_d_;
    char tabid[16];
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__547 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__554 = { 0, 0, 0, fmt_52, 0 };


/*     Get the items of data from a line of input in at table of type 15. */
/* SOURCE fqshrftb.for:4724 */
/*<       implicitnone >*/
/* SOURCE fqshrftb.for:4725 */
/*<       integerstdout,nitem,item_start(nitem),item_end(nitem),eflag,tab2d >*/
/* SOURCE fqshrftb.for:4727 */
/*<       realarg,barg,f(3) >*/
/* SOURCE fqshrftb.for:4728 */
/*<       characterline*(*) >*/
/*     Local */
/* SOURCE fqshrftb.for:4732 */
/*<       integerie,is,n,internal_tab_number >*/
/* SOURCE fqshrftb.for:4733 */
/*<       charactertpc*20,tabid*16 >*/
/*     Called program units */
/* SOURCE fqshrftb.for:4737 */
/*<       externalstrip_l_blanks,get_internal_tab_number >*/
/*     ***********************FORMATS************************************ */
/* SOURCE fqshrftb.for:4740 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:4743 */
/*<       if(nitem.lt.5)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    feq::IndexedPointer<real> f(feq_storage_f, 1);

    /* Function Body */
/* L50: */
    if (*nitem < 5) {
/* SOURCE fqshrftb.for:4744 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__547.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__547);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:4745 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrftb.for:4746 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:4748 */
/*<       n=1 >*/
    n = 1;
/*     Process the argument field */
/* SOURCE fqshrftb.for:4750 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE fqshrftb.for:4751 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE fqshrftb.for:4752 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE fqshrftb.for:4753 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE fqshrftb.for:4755 */
/*<       read(tpc,*,err=991)arg >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = 0;
    feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*arg), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsli();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE fqshrftb.for:4757 */
/*<       if(arg.le.barg)then >*/
    if (*arg <= *barg) {
/*       Last line in the table. */
/* SOURCE fqshrftb.for:4759 */
/*<       tab2d=0 >*/
	*tab2d = 0;
/* SOURCE fqshrftb.for:4760 */
/*<       f(1)=0 >*/
	f[1] = (float)0.;
/* SOURCE fqshrftb.for:4761 */
/*<       f(2)=0 >*/
	f[2] = (float)0.;
/* SOURCE fqshrftb.for:4762 */
/*<       f(3)=0 >*/
	f[3] = (float)0.;
/* SOURCE fqshrftb.for:4763 */
/*<       else >*/
    } else {
/*       Process the 2-D table id */
/* SOURCE fqshrftb.for:4765 */
/*<       n=2 >*/
	n = 2;
/* SOURCE fqshrftb.for:4766 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE fqshrftb.for:4767 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE fqshrftb.for:4768 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE fqshrftb.for:4769 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE fqshrftb.for:4771 */
/*<       tabid=tpc >*/
	s_copy(tabid, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE fqshrftb.for:4772 */
/*<        >*/
	feq_gen_get_internal_tab_number_d_(stdout, tabid, eflag, &
		feq_gen_internal_tab_number_d_, (ftnlen)16);
/* SOURCE fqshrftb.for:4776 */
/*<       tab2d=internal_tab_number >*/
	*tab2d = feq_gen_internal_tab_number_d_;
/*       Process three points for each argument */
/* SOURCE fqshrftb.for:4779 */
/*<       do100n=3,5 >*/
	for (n = 3; n <= 5; ++n) {
/* SOURCE fqshrftb.for:4780 */
/*<       is=item_start(n) >*/
	    is = feq_gen_item_start_d_[n];
/* SOURCE fqshrftb.for:4781 */
/*<       ie=item_end(n) >*/
	    ie = feq_gen_item_end_d_[n];
/* SOURCE fqshrftb.for:4782 */
/*<       tpc=line(is:ie) >*/
	    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE fqshrftb.for:4783 */
/*<       callstrip_l_blanks(tpc) >*/
	    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE fqshrftb.for:4785 */
/*<       read(tpc,*,err=991)f(n-2) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 20;
	    feq_gen_ici_d_1.iciunit = tpc;
	    feq_gen_ici_d_1.icifmt = 0;
	    feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&f[n - 2], (ftnlen)sizeof(
		    real));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = e_rsli();
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
/* SOURCE fqshrftb.for:4786 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE fqshrftb.for:4787 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:4789 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:4790 */
/*<   991 continue >*/
L991:
/* SOURCE fqshrftb.for:4791 */
/*<       write(stdout,52)tpc >*/
    feq_gen_io_d__554.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__554);
    do_fio(&feq_gen_c_d_1, tpc, (ftnlen)20);
    e_wsfe();
/* SOURCE fqshrftb.for:4792 */
/*<    52 format(/,' *ERR:500* Conversion error in: ',a) >*/
/* SOURCE fqshrftb.for:4793 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE fqshrftb.for:4794 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:4796 */
/*<       end >*/
} /* read_tabty15_items__ */




/* SOURCE fqshrftb.for:4800 */
/*<       subroutinety15in(in,stdout,mlft,ntab,eflag,ftp,type) >*/
/* Subroutine */ int ty15in_(integer *in, integer *stdout, integer *mlft, 
	integer *ntab, integer *eflag, integer *ftp, integer *feq_gen_type_d_)
{
    /* Format strings */
    static char fmt_1[] = "(80a)";
    static char fmt_46[] = "(5x,f10.0,7x,a50)";
    static char fmt_48[] = "(f10.0,i5,3f10.0)";
    static char fmt_11[] = "(\002 \002,80a)";
    static char fmt_47[] = "(\002 \002,\002LABEL=\002,a50)";
    static char fmt_49[] = "(\002 \002,f10.3,i5,3f10.3)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_item_end_d_[5];
    real f[3];
    extern /* Subroutine */ int feq_gen_read_tabty15_items_d_(integer *, char *, 
	    integer *, integer *, integer *, real *, integer *, real *, 
	    integer *, real *, ftnlen);
    integer feq_gen_item_start_d_[5];
    real arg;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer out;
    char head[80];
    real barg;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char line[80];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char just[5];
    integer tab2d;
    char label[50];
    integer nitem;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    real reflev;
    integer ftpold;
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__562 = { 0, 0, 0, fmt_47, 0 };
    static cilist feq_gen_io_d__566 = { 0, 0, 0, fmt_11, 0 };
    static cilist feq_gen_io_d__574 = { 0, 0, 0, fmt_49, 0 };
    static cilist feq_gen_io_d__575 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__576 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input a table of type 15. */
/* SOURCE fqshrftb.for:4807 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:4809 */
/*<       integereflag,ftp,in,stdout,mlft,ntab,type >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     MLFT   - maximum length of FTAB/ITAB */
/*     NTAB   - table number */
/*     FTP    - next open location in the function table storage */
/*     TYPE   - table type */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:4819 */
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
/* INCLUDE fqshrftb.for:4820 */
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
/* SOURCE fqshrftb.for:4823 */
/*<       integerftpold,out,tab2d >*/
/* SOURCE fqshrftb.for:4824 */
/*<       realarg,barg,f(3),reflev >*/
/* SOURCE fqshrftb.for:4825 */
/*<       characterhead*80,label*50,line*80 >*/
/* SOURCE fqshrftb.for:4826 */
/*<       integermax_item,nitem >*/
/* SOURCE fqshrftb.for:4827 */
/*<       parameter(max_item=5) >*/
/* SOURCE fqshrftb.for:4828 */
/*<       integeritem_start(max_item),item_end(max_item) >*/
/* SOURCE fqshrftb.for:4829 */
/*<       characterjust*5 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:4832 */
/*<       intrinsiciabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:4835 */
/*<       externalinline,kil,read_tabty15_items >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE fqshrftb.for:4838 */
/*<     1 format(80a) >*/
/* SOURCE fqshrftb.for:4839 */
/*<    46 format(5x,f10.0,7x,a50) >*/
/* SOURCE fqshrftb.for:4840 */
/*<    48 format(f10.0,i5,3f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:4843 */
/*<    11 format(' ',80a) >*/
/* SOURCE fqshrftb.for:4844 */
/*<    47 format(' ','LABEL=',a50) >*/
/* SOURCE fqshrftb.for:4845 */
/*<    49 format(' ',f10.3,i5,3f10.3) >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:4847 */
/*<       just='RIGHT' >*/
/* L1: */
/* L46: */
/* L48: */
/* L11: */
/* L47: */
/* L49: */
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/* SOURCE fqshrftb.for:4848 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4851 */
/*<       read(line,46,err=991)reflev,label >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_46;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&reflev, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE fqshrftb.for:4852 */
/*<       write(stdout,47)label >*/
    feq_gen_io_d__562.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__562);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/* SOURCE fqshrftb.for:4854 */
/*<       if((ftp+4).ge.mlft)callkil(10,ftp,eflag) >*/
    if (*ftp + 4 >= *mlft) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/*     FTP RESERVED FOR THE HIGH ADDRESS OF THE TABLE */
/* SOURCE fqshrftb.for:4860 */
/*<       out=1 >*/
    out = 1;
/* SOURCE fqshrftb.for:4861 */
/*<       if(type.lt.0)out=0 >*/
    if (*feq_gen_type_d_ < 0) {
	out = 0;
    }
/* SOURCE fqshrftb.for:4862 */
/*<       type=iabs(type) >*/
    *feq_gen_type_d_ = abs(*feq_gen_type_d_);
/* SOURCE fqshrftb.for:4864 */
/*<       itab(ftp+1)=ntab >*/
    itab[*ftp + 1] = *ntab;
/* SOURCE fqshrftb.for:4865 */
/*<       itab(ftp+2)=type >*/
    itab[*ftp + 2] = *feq_gen_type_d_;
/*     Set flag to indicate that table needs processing. */
/* SOURCE fqshrftb.for:4868 */
/*<       itab(ftp+3)=1 >*/
    itab[*ftp + 3] = 1;
/*     INITIALIZE LAST ADDRESS ACCESSED */
/* SOURCE fqshrftb.for:4873 */
/*<       itab(ftp+4)=ftp+off234 >*/
    itab[*ftp + 4] = *ftp + 22;
/* SOURCE fqshrftb.for:4874 */
/*<       ftpold=ftp >*/
    ftpold = *ftp;
/* SOURCE fqshrftb.for:4875 */
/*<       ftp=ftp+off234 >*/
    *ftp += 22;
/* SOURCE fqshrftb.for:4877 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4880 */
/*<       read(line,1)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_rsfi();
/* SOURCE fqshrftb.for:4881 */
/*<       write(stdout,11)head >*/
    feq_gen_io_d__566.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__566);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE fqshrftb.for:4884 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, head, &feq_gen_c_d_5, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)80, (ftnlen)5);
/* SOURCE fqshrftb.for:4888 */
/*<       barg=-1.0e37 >*/
    barg = (float)-1e37;
/* SOURCE fqshrftb.for:4890 */
/*<  1000 continue >*/
L1000:
/* SOURCE fqshrftb.for:4892 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE fqshrftb.for:4895 */
/*<       read(line,48,err=991)arg,tab2d,f >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_48;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&tab2d, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_3, (char *)&f[0], (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE fqshrftb.for:4896 */
/*<        >*/
    feq_gen_read_tabty15_items_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, &
	    barg, eflag, &arg, &tab2d, f, (ftnlen)80);
/* SOURCE fqshrftb.for:4902 */
/*<       if(arg.le.barg)goto1500 >*/
    if (arg <= barg) {
	goto L1500;
    }
/* SOURCE fqshrftb.for:4903 */
/*<       barg=arg >*/
    barg = arg;
/* SOURCE fqshrftb.for:4904 */
/*<       if(out.eq.1)then >*/
    if (out == 1) {
/* SOURCE fqshrftb.for:4905 */
/*<       write(stdout,49)arg,tab2d,f >*/
	feq_gen_io_d__574.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__574);
	do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tab2d, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_3, (char *)&f[0], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE fqshrftb.for:4906 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:4907 */
/*<       if((ftp+5).ge.mlft)callkil(10,ftp,eflag) >*/
    if (*ftp + 5 >= *mlft) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/* SOURCE fqshrftb.for:4910 */
/*<       ftab(ftp)=arg >*/
    ftab[*ftp] = arg;
/* SOURCE fqshrftb.for:4911 */
/*<       itab(ftp+1)=tab2d >*/
    itab[*ftp + 1] = tab2d;
/* SOURCE fqshrftb.for:4912 */
/*<       ftab(ftp+2)=f(1) >*/
    ftab[*ftp + 2] = f[0];
/* SOURCE fqshrftb.for:4913 */
/*<       ftab(ftp+3)=f(2) >*/
    ftab[*ftp + 3] = f[1];
/* SOURCE fqshrftb.for:4914 */
/*<       ftab(ftp+4)=f(3) >*/
    ftab[*ftp + 4] = f[2];
/* SOURCE fqshrftb.for:4915 */
/*<       ftp=ftp+5 >*/
    *ftp += 5;
/* SOURCE fqshrftb.for:4916 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fqshrftb.for:4918 */
/*<  1500 continue >*/
L1500:
/* SOURCE fqshrftb.for:4919 */
/*<       itab(ftpold)=ftp-5 >*/
    itab[ftpold] = *ftp - 5;
/* SOURCE fqshrftb.for:4920 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:4921 */
/*<   991 continue >*/
L991:
/* SOURCE fqshrftb.for:4922 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__575.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__575);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE fqshrftb.for:4923 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__576.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__576);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE fqshrftb.for:4924 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:4925 */
/*<       end >*/
    return 0;
} /* ty15in_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:4929 */
/*<       subroutinexlkt20bak(adrs,ya,a,t,dt,k,dk,b,db) >*/
/* Subroutine */ int xlkt20bak_(integer *adrs, real *ya, real *a, real *t, 
	real *dt, real *k, real *dk, real *b, real *db)
{
    /* Initialized data */

    static integer vtype[35] = { 1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,
	    1,1,1,0,0,0,0,0,0,0,0,0,0 };

    /* Format strings */
    static char fmt_2000[] = "(\002 \002,\002*WRN:02* X-SECTION BELOW RANGE \
IN XLKT20\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";
    static char fmt_2010[] = "(\002 \002,\002*WRN:03* X-SECTION ABOVE RANGE \
IN XLKT20\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real y, b0, k0, t0, y0;
    integer ha, la;
    real hh;
    char cs[16];
    integer it;
    real dy;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real dyi;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__588 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__589 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth find area, top-width, conveyance, etc. */
/*     using direct linear interpolation for top width. */
/* SOURCE fqshrftb.for:4938 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:4940 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:4941 */
/*<       reala,b,db,dk,dt,k,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:4956 */
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
/* INCLUDE fqshrftb.for:4957 */
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
/* INCLUDE fqshrftb.for:4958 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:4959 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:4962 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:4963 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:4966 */
/*<       integerha,it,l,la,type,xoff >*/
/* SOURCE fqshrftb.for:4967 */
/*<       realb0,dy,dyi,h,hh,k0,t0,y,y0 >*/
/* SOURCE fqshrftb.for:4968 */
/*<       charactercs*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:4971 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:4972 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:4975 */
/*<       datavtype/1,10*0,1,7*0,6*1,10*0/ >*/
/* SOURCE fqshrftb.for:4978 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:4983 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKT20 */
/* SOURCE fqshrftb.for:4993 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:4994 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:4995 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:4996 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:4998 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:4999 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:5000 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:5001 */
/*<       callxstype(stdout,vtype,adrs) >*/
	xstype_(&xscom_1.stdout, vtype, adrs);
/* SOURCE fqshrftb.for:5003 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:5004 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:5006 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5008 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:5009 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5010 */
/*<       write(stdout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__588.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__588);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5012 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:5013 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:5014 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5015 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5016 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:5017 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:5018 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:5019 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:5020 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:5021 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5022 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5024 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:5025 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5026 */
/*<       write(stdout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__589.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__589);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5028 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:5029 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:5030 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5031 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5032 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:5033 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:5034 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:5035 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5036 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:5043 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
/*     FETCH VALUES FROM FTAB */
/* SOURCE fqshrftb.for:5047 */
/*<       y0=ftab(l) >*/
    y0 = ftab[l];
/* SOURCE fqshrftb.for:5048 */
/*<       t0=ftab(l+1) >*/
    t0 = ftab[l + 1];
/* SOURCE fqshrftb.for:5049 */
/*<       k0=ftab(l+3) >*/
    k0 = ftab[l + 3];
/* SOURCE fqshrftb.for:5050 */
/*<       b0=ftab(l+4) >*/
    b0 = ftab[l + 4];
/*     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE) */
/*     N.B. K IN FTAB IS SQRT(CONVEYANCE) */
/* SOURCE fqshrftb.for:5055 */
/*<       it=l+xoff >*/
    it = l + xoff;
/* SOURCE fqshrftb.for:5056 */
/*<       dy=ftab(it)-y0 >*/
    dy = static_cast<double>(ftab[it]) - y0;
/* SOURCE fqshrftb.for:5057 */
/*<       h=y-y0 >*/
    feq_gen_h_d_ = static_cast<double>(y) - y0;
/* SOURCE fqshrftb.for:5058 */
/*<       hh=0.5*h >*/
    hh = static_cast<double>(feq_gen_h_d_) * (float).5;
/* SOURCE fqshrftb.for:5059 */
/*<       dyi=1.0/dy >*/
    dyi = static_cast<double>((float)1.) / dy;
/* SOURCE fqshrftb.for:5060 */
/*<       db=(ftab(it+4)-b0)*dyi >*/
    *db = static_cast<double>((static_cast<double>(ftab[it + 4]) - b0)) * dyi;
/* SOURCE fqshrftb.for:5061 */
/*<       dt=(ftab(it+1)-t0)*dyi >*/
    *dt = static_cast<double>((static_cast<double>(ftab[it + 1]) - t0)) * dyi;
/* SOURCE fqshrftb.for:5062 */
/*<       dk=(ftab(it+3)-k0)*dyi >*/
    *dk = static_cast<double>((static_cast<double>(ftab[it + 3]) - k0)) * dyi;
/* SOURCE fqshrftb.for:5063 */
/*<       t=t0+h*dt >*/
    *t = static_cast<double>(t0) + static_cast<double>(feq_gen_h_d_) * *dt;
/* SOURCE fqshrftb.for:5064 */
/*<       b=b0+h*db >*/
    *b = static_cast<double>(b0) + static_cast<double>(feq_gen_h_d_) * *db;
/* SOURCE fqshrftb.for:5065 */
/*<       a=ftab(l+2)+hh*(t+t0) >*/
    *a = static_cast<double>(ftab[l + 2]) + static_cast<double>(hh) * (static_cast<double>(*t) + t0);
/* SOURCE fqshrftb.for:5066 */
/*<       k=k0+h*dk >*/
    *k = static_cast<double>(k0) + static_cast<double>(feq_gen_h_d_) * *dk;
/* SOURCE fqshrftb.for:5067 */
/*<       dk=(k+k)*dk >*/
    *dk = static_cast<double>((static_cast<double>(*k) + *k)) * *dk;
/* SOURCE fqshrftb.for:5068 */
/*<       k=k*k >*/
    *k *= *k;
/* SOURCE fqshrftb.for:5070 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:5071 */
/*<       end >*/
} /* xlkt20bak_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:5075 */
/*<       subroutinexlkt20(adrs,ya,a,t,dt,k,dk,b,db) >*/
/* Subroutine */ int xlkt20_(integer *adrs, real *ya, real *a, real *t, real *
	dt, real *k, real *dk, real *b, real *db)
{
    /* Initialized data */

    static integer vtype[35] = { 1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,
	    1,1,1,0,0,0,0,1,1,1,1,1,1 };

    /* Format strings */
    static char fmt_2000[] = "(\002 \002,\002*WRN:02* X-SECTION BELOW RANGE \
IN XLKT20\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";
    static char fmt_2010[] = "(\002 \002,\002*WRN:03* X-SECTION ABOVE RANGE \
IN XLKT20\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real p, y, b0, b1, k0, k1, t0, y0;
    integer ha, la;
    real hh, fl;
    char cs[16];
    real fr;
    integer it;
    real dy, db0, db1, dk0, dk1, dmf;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real dlp, flp, dyi, drp, frp;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__611 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__612 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth find area, top-width, conveyance, etc. */
/*     using direct linear interpolation for top width. */
/* SOURCE fqshrftb.for:5084 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:5086 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:5087 */
/*<       reala,b,db,dk,dt,k,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:5102 */
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
/* INCLUDE fqshrftb.for:5103 */
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
/* INCLUDE fqshrftb.for:5104 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:5105 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:5108 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:5109 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:5112 */
/*<       integerha,it,l,la,type,xoff,doff >*/
/* SOURCE fqshrftb.for:5113 */
/*<       realb0,dy,dyi,h,hh,k0,t0,y,y0,b1,k1,db0,db1,dk0,dk1 >*/
/* SOURCE fqshrftb.for:5115 */
/*<       realflp,frp,fl,fr,dlp,drp,dmf,p >*/
/* SOURCE fqshrftb.for:5117 */
/*<       charactercs*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:5120 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:5121 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:5124 */
/*<       datavtype/1,10*0,1,7*0,6*1,4*0,6*1/ >*/
/* SOURCE fqshrftb.for:5127 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:5132 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKT20 */
/*     XOFF - number of items stored per line in the table.  includes */
/*            depth and all other elements. */
/*     DOFF - offset from depth to the first tabulated derivative if */
/*            derivatives are available.  They may not be! */
/*     Note: all tables types in the range of 20-25 and 30-35 are valid */
/*           here because they contain the data required. */
/* SOURCE fqshrftb.for:5149 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:5150 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:5151 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:5152 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:5153 */
/*<       doff=itab(adrs+21) >*/
    doff = itab[*adrs + 21];
/* SOURCE fqshrftb.for:5155 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:5156 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:5157 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:5158 */
/*<       callxstype(stdout,vtype,adrs) >*/
	xstype_(&xscom_1.stdout, vtype, adrs);
/* SOURCE fqshrftb.for:5160 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:5161 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:5163 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5165 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:5166 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5167 */
/*<       write(stdout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__611.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__611);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5169 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:5170 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:5171 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5172 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5173 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:5174 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:5175 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:5176 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:5177 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:5178 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5179 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5181 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:5182 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5183 */
/*<       write(stdout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__612.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__612);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5185 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:5186 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:5187 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5188 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5189 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:5190 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:5191 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:5192 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5193 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:5200 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
    // Directly verified against both FEQ and FEQUTL releases.
    feq_interpolate_section_interval(l,l+xoff,doff,*ya,a,t,dt,k,dk,b,db);
    return 0;
/* SOURCE fqshrftb.for:5263 */
/*<       end >*/
} /* xlkt20_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:5267 */
/*<       subroutinexlkt21(adrs,ya,a,t,dt,j,k,dk,b,db) >*/
/* Subroutine */ int xlkt21_(integer *adrs, real *ya, real *a, real *t, real *
	dt, real *j, real *k, real *dk, real *b, real *db)
{
    /* Initialized data */

    static integer vtype[35] = { 1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,
	    0,1,1,0,0,0,0,0,1,1,0,1,1 };

    /* Format strings */
    static char fmt_2000[] = "(\002 \002,\002*WRN:02* X-SECTION BELOW RANGE \
IN XLKT21\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";
    static char fmt_2010[] = "(\002 \002,\002*WRN:03* X-SECTION ABOVE RANGE \
IN XLKT21\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real p, y, a0, b0, b1, j0, k0, k1, t0, y0;
    integer ha, la;
    real hh, fl;
    char cs[16];
    real fr;
    integer it;
    real dy, db0, db1, dk0, dk1, dmf;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real dlp, flp, dyi, drp, frp;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__648 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__649 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth find area, top-width, conveyance, etc. */
/*     using direct linear interpolation for top width. */
/* SOURCE fqshrftb.for:5276 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:5278 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:5279 */
/*<       reala,b,db,dk,dt,j,k,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     J      - first moment of area about water surface in the table */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:5295 */
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
/* INCLUDE fqshrftb.for:5296 */
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
/* INCLUDE fqshrftb.for:5297 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:5298 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:5301 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:5302 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:5305 */
/*<       integerha,l,la,type,xoff,doff,it >*/
/* SOURCE fqshrftb.for:5306 */
/*<       reala0,b0,dy,dyi,h,hh,j0,k0,t0,y,y0,b1,k1,db0,db1,dk0,dk1 >*/
/* SOURCE fqshrftb.for:5308 */
/*<       realflp,frp,fl,fr,dlp,drp,dmf,p >*/
/* SOURCE fqshrftb.for:5309 */
/*<       charactercs*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:5312 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:5313 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:5316 */
/*<       datavtype/1,10*0,1,7*0,0,2*1,0,2*1,4*0,0,2*1,0,2*1/ >*/
/* SOURCE fqshrftb.for:5319 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:5324 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKT21 */
/* SOURCE fqshrftb.for:5334 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:5335 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:5336 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:5337 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:5338 */
/*<       doff=itab(adrs+21) >*/
    doff = itab[*adrs + 21];
/* SOURCE fqshrftb.for:5340 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:5341 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:5342 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:5343 */
/*<       callxstype(stdout,vtype,adrs) >*/
	xstype_(&xscom_1.stdout, vtype, adrs);
/* SOURCE fqshrftb.for:5345 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:5346 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:5348 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5350 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:5351 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5352 */
/*<       write(stdout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__648.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__648);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5354 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:5355 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:5356 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5357 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5358 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:5359 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:5360 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:5361 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:5362 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:5363 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5364 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5366 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:5367 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5368 */
/*<       write(stdout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__649.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__649);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5370 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:5371 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:5372 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5373 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5374 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:5375 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:5376 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:5377 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5378 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:5385 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
    // Directly verified against both FEQ and FEQUTL releases.
    feq_interpolate_section_interval_moment(l,l+xoff,doff,*ya,a,t,dt,j,k,dk,b,db);
    return 0;
/* SOURCE fqshrftb.for:5451 */
/*<       end >*/
} /* xlkt21_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:5455 */
/*<       subroutinexlkt22(adrs,ya,a,t,dt,j,k,dk,b,db,alp,dalp,qc) >*/
/* Subroutine */ int xlkt22_(integer *adrs, real *ya, real *a, real *t, real *
	dt, real *j, real *k, real *dk, real *b, real *db, real *alp, real *
	dalp, real *qc)
{
    /* Initialized data */

    static integer vtype[35] = { 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
	    0,0,1,0,0,0,0,0,0,1,0,0,1 };

    /* Format strings */
    static char fmt_2000[] = "(\002 \002,\002*WRN:33* X-SECTION BELOW RANGE \
IN XLKT22\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";
    static char fmt_2010[] = "(\002 \002,\002*WRN:34* X-SECTION ABOVE RANGE \
IN XLKT22\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double log(doublereal), exp(doublereal);

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real p, y, a0, b0, b1, j0, k0, k1, t0, y0, y1;
    integer ha, la;
    real hh, fl;
    char cs[16];
    real fr;
    integer it;
    real dy, db0, db1, dk0, dk1, qc0, qc1, dmf;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real dlp, flp, drp, frp, alp0, alp1;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real dalp0, dalp1;
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__687 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__688 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given the depth, YA, find: A-area; T-top width; DT- derivative */
/*     of top width; J-first moment of area about water surface; */
/*     K-conveyance; DK=derivative of conveyance; B- beta; */
/*     DB- derivative of beta; ALP-alpha; and DALP-derivative of */
/*     alpha, and QC, critical flow.  Use linear interpolation */
/*     on logarithms of QC and depth. */
/* SOURCE fqshrftb.for:5468 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:5470 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:5471 */
/*<       reala,alp,b,dalp,db,dk,dt,j,k,qc,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     J      - first moment of area about water surface in the table */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     ALP    - value of energy flux correction coefficient */
/*     DALP   - derivative wrt depth of the energy flux coefficient */
/*     QC     - critical flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:5490 */
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
/* INCLUDE fqshrftb.for:5491 */
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
/* INCLUDE fqshrftb.for:5492 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:5493 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:5496 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:5497 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:5500 */
/*<       integerha,l,la,type,xoff,doff,it >*/
/* SOURCE fqshrftb.for:5501 */
/*<        >*/
/* SOURCE fqshrftb.for:5503 */
/*<       realflp,frp,fl,fr,dlp,drp,dmf >*/
/* SOURCE fqshrftb.for:5505 */
/*<       charactercs*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:5507 */
/*<       intrinsicexp,log >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:5510 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:5511 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*      DATA VTYPE/11*0,1,9*0,1,0,0,1,4*0,0,0,1,0,0,0/ */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:5514 */
/*<       datavtype/11*0,1,9*0,1,0,0,1,4*0,0,0,1,0,0,1/ >*/
/* SOURCE fqshrftb.for:5518 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:5523 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKT22 */
/* SOURCE fqshrftb.for:5533 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:5534 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:5535 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:5536 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:5537 */
/*<       doff=itab(adrs+21) >*/
    doff = itab[*adrs + 21];
/*      WRITE(STDOUT,*) ' XLKT22: doff=', doff */
/*      if(doff.ne.0) then */
/*        write(stdout,*) 'doff not zero!!!' */
/*        stop */
/*      endif */
/* SOURCE fqshrftb.for:5544 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:5545 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:5546 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:5547 */
/*<       callxstype(stdout,vtype,adrs) >*/
	xstype_(&xscom_1.stdout, vtype, adrs);
/* SOURCE fqshrftb.for:5549 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:5550 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:5552 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5554 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:5555 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5556 */
/*<       write(stdout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__687.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__687);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5558 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:5559 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:5560 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5561 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5562 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:5563 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:5564 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:5565 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:5566 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:5567 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5568 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5570 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:5571 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5572 */
/*<       write(stdout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__688.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__688);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5574 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:5575 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:5576 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5577 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5578 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:5579 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:5580 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:5581 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5582 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:5589 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
    // Directly verified against both FEQ and FEQUTL releases.
    feq_interpolate_energy_section_interval(l,l+xoff,doff,feq_gen_type_d_,*ya,a,t,dt,j,k,dk,b,db,alp,dalp,qc);
    return 0;
/* SOURCE fqshrftb.for:5695 */
/*<       end >*/
} /* xlkt22_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:5699 */
/*<       subroutinexlkt23(adrs,ya,a,t,dt,k,dk,b,db,ma,dma,mq,dmq) >*/
/* Subroutine */ int xlkt23_(integer *adrs, real *ya, real *a, real *t, real *
	dt, real *k, real *dk, real *b, real *db, real *ma, real *dma, real *
	mq, real *dmq)
{
    /* Initialized data */

    static integer vtype[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    1,1,1,0,0,0,0,0,0,0,1,1,1 };

    /* Format strings */
    static char fmt_2000[] = "(\002 \002,\002*WRN:02* X-SECTION BELOW RANGE \
IN XLKT23\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";
    static char fmt_2010[] = "(\002 \002,\002*WRN:03* X-SECTION ABOVE RANGE \
IN XLKT23\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real p, y, b0, b1, k0, k1, t0, y0;
    integer ha, la;
    real hh, fl;
    char cs[16];
    real fr;
    integer it;
    real dy, db0, db1, ma0, dk0, dk1, ma1, mq0, mq1, dmf;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real dlp, flp, dyi, drp, frp, dma0, dma1, dmq0, dmq1;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__732 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__733 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth, YA, compute the area, top width, derivative */
/*     of top width, DT, the conveyance, K, the derivative of conveyanc, DK, */
/*     the momentum flux correction coefficient, B, its */
/*     derivative, DB, the correction factor on area */
/*     to give volume per unit length for the distance axis, MA, */
/*     the derivative wrt depth of MA, DMA; the correction factor */
/*     on Q to give momentum per unit length for the distance */
/*     axis, MQ; and the derivative wrt depth of MQ, DMQ. */
/* SOURCE fqshrftb.for:5714 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:5716 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:5717 */
/*<       reala,b,db,dk,dma,dmq,dt,k,ma,mq,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     MA     - weight factor on area to get volume per unit length */
/*     DMA    - derivative of the sinuosity correction of area wrt depth */
/*     MQ     - weight factor on flow to get momentum per unit length */
/*     DMQ    - derivative of the sinuosity correction of momentum wrt */
/*               depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:5737 */
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
/* INCLUDE fqshrftb.for:5738 */
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
/* INCLUDE fqshrftb.for:5739 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:5740 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:5743 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:5744 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:5747 */
/*<       integerha,it,l,la,type,xoff,doff >*/
/* SOURCE fqshrftb.for:5748 */
/*<        >*/
/* SOURCE fqshrftb.for:5751 */
/*<       realflp,frp,fl,fr,dlp,drp,dmf,p >*/
/* SOURCE fqshrftb.for:5753 */
/*<       charactercs*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:5755 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:5756 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:5759 */
/*<       datavtype/22*0,1,1,1,4*0,3*0,3*1/ >*/
/* SOURCE fqshrftb.for:5762 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:5767 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKT23 */
/* SOURCE fqshrftb.for:5777 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:5778 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:5779 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:5780 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:5781 */
/*<       doff=itab(adrs+21) >*/
    doff = itab[*adrs + 21];
/* SOURCE fqshrftb.for:5783 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:5784 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:5785 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:5786 */
/*<       callxstype(stdout,vtype,adrs) >*/
	xstype_(&xscom_1.stdout, vtype, adrs);
/* SOURCE fqshrftb.for:5788 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:5789 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:5791 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5793 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:5794 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5795 */
/*<       write(stdout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__732.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__732);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5797 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:5798 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:5799 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5800 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5801 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:5802 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:5803 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:5804 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:5805 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:5806 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5807 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:5809 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:5810 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:5811 */
/*<       write(stdout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__733.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__733);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:5813 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:5814 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:5815 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:5816 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:5817 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:5818 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:5819 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:5820 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:5821 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:5828 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
/*     FETCH VALUES FROM FTAB */
/* SOURCE fqshrftb.for:5832 */
/*<       y0=ftab(l) >*/
    y0 = ftab[l];
/* SOURCE fqshrftb.for:5833 */
/*<       t0=ftab(l+1) >*/
    t0 = ftab[l + 1];
/* SOURCE fqshrftb.for:5834 */
/*<       k0=ftab(l+3) >*/
    k0 = ftab[l + 3];
/* SOURCE fqshrftb.for:5835 */
/*<       b0=ftab(l+4) >*/
    b0 = ftab[l + 4];
/* SOURCE fqshrftb.for:5836 */
/*<       it=l+xoff >*/
    it = l + xoff;
/*     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE) */
/*     N.B. K IN FTAB IS SQRT(CONVEYANCE) */
/* SOURCE fqshrftb.for:5841 */
/*<       dy=ftab(it)-y0 >*/
    dy = static_cast<double>(ftab[it]) - y0;
/* SOURCE fqshrftb.for:5842 */
/*<       h=y-y0 >*/
    feq_gen_h_d_ = static_cast<double>(y) - y0;
/* SOURCE fqshrftb.for:5843 */
/*<       hh=0.5*h >*/
    hh = static_cast<double>(feq_gen_h_d_) * (float).5;
/* SOURCE fqshrftb.for:5844 */
/*<       dyi=1.0/dy >*/
    dyi = static_cast<double>((float)1.) / dy;
/* SOURCE fqshrftb.for:5845 */
/*<       dt=(ftab(it+1)-t0)*dyi >*/
    *dt = static_cast<double>((static_cast<double>(ftab[it + 1]) - t0)) * dyi;
/* SOURCE fqshrftb.for:5846 */
/*<       t=t0+h*dt >*/
    *t = static_cast<double>(t0) + static_cast<double>(feq_gen_h_d_) * *dt;
/* SOURCE fqshrftb.for:5847 */
/*<       a=ftab(l+2)+hh*(t+t0) >*/
    *a = static_cast<double>(ftab[l + 2]) + static_cast<double>(hh) * (static_cast<double>(*t) + t0);
/* SOURCE fqshrftb.for:5849 */
/*<       if(doff.eq.0)then >*/
    if (doff == 0) {
/* SOURCE fqshrftb.for:5850 */
/*<       db=(ftab(it+4)-b0)*dyi >*/
	*db = static_cast<double>((static_cast<double>(ftab[it + 4]) - b0)) * dyi;
/* SOURCE fqshrftb.for:5851 */
/*<       b=b0+h*db >*/
	*b = static_cast<double>(b0) + static_cast<double>(feq_gen_h_d_) * *db;
/* SOURCE fqshrftb.for:5852 */
/*<       dk=(ftab(it+3)-k0)*dyi >*/
	*dk = static_cast<double>((static_cast<double>(ftab[it + 3]) - k0)) * dyi;
/* SOURCE fqshrftb.for:5853 */
/*<       k=k0+h*dk >*/
	*k = static_cast<double>(k0) + static_cast<double>(feq_gen_h_d_) * *dk;
/* SOURCE fqshrftb.for:5854 */
/*<       goto(23,24,25),type-22 >*/
	switch (feq_gen_type_d_ - 22) {
	    case 1:  goto L23;
	    case 2:  goto L24;
	    case 3:  goto L25;
	}
/* SOURCE fqshrftb.for:5855 */
/*<    23 continue >*/
L23:
/*           Find the curvilinear elements from type 23 */
/* SOURCE fqshrftb.for:5857 */
/*<       ma0=ftab(l+5) >*/
	ma0 = ftab[l + 5];
/* SOURCE fqshrftb.for:5858 */
/*<       mq0=ftab(l+6) >*/
	mq0 = ftab[l + 6];
/* SOURCE fqshrftb.for:5859 */
/*<       ma1=ftab(it+5) >*/
	ma1 = ftab[it + 5];
/* SOURCE fqshrftb.for:5860 */
/*<       mq1=ftab(it+6) >*/
	mq1 = ftab[it + 6];
/* SOURCE fqshrftb.for:5861 */
/*<       dma=(ma1-ma0)*dyi >*/
	*dma = static_cast<double>((static_cast<double>(ma1) - ma0)) * dyi;
/* SOURCE fqshrftb.for:5862 */
/*<       dmq=(mq1-mq0)*dyi >*/
	*dmq = static_cast<double>((static_cast<double>(mq1) - mq0)) * dyi;
/* SOURCE fqshrftb.for:5863 */
/*<       ma=ma0+dma*h >*/
	*ma = static_cast<double>(ma0) + static_cast<double>(*dma) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:5864 */
/*<       mq=mq0+dmq*h >*/
	*mq = static_cast<double>(mq0) + static_cast<double>(*dmq) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:5865 */
/*<       goto26 >*/
	goto L26;
/* SOURCE fqshrftb.for:5866 */
/*<    24 continue >*/
L24:
/*           Find the curvilinear elements from type 24 */
/* SOURCE fqshrftb.for:5868 */
/*<       ma0=ftab(l+6) >*/
	ma0 = ftab[l + 6];
/* SOURCE fqshrftb.for:5869 */
/*<       mq0=ftab(l+7) >*/
	mq0 = ftab[l + 7];
/* SOURCE fqshrftb.for:5870 */
/*<       ma1=ftab(it+6) >*/
	ma1 = ftab[it + 6];
/* SOURCE fqshrftb.for:5871 */
/*<       mq1=ftab(it+7) >*/
	mq1 = ftab[it + 7];
/* SOURCE fqshrftb.for:5872 */
/*<       dma=(ma1-ma0)*dyi >*/
	*dma = static_cast<double>((static_cast<double>(ma1) - ma0)) * dyi;
/* SOURCE fqshrftb.for:5873 */
/*<       dmq=(mq1-mq0)*dyi >*/
	*dmq = static_cast<double>((static_cast<double>(mq1) - mq0)) * dyi;
/* SOURCE fqshrftb.for:5874 */
/*<       ma=ma0+dma*h >*/
	*ma = static_cast<double>(ma0) + static_cast<double>(*dma) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:5875 */
/*<       mq=mq0+dmq*h >*/
	*mq = static_cast<double>(mq0) + static_cast<double>(*dmq) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:5876 */
/*<       goto26 >*/
	goto L26;
/* SOURCE fqshrftb.for:5877 */
/*<    25 continue >*/
L25:
/*           Find the curvilinear elements from type 25 */
/* SOURCE fqshrftb.for:5879 */
/*<       ma0=ftab(l+8) >*/
	ma0 = ftab[l + 8];
/* SOURCE fqshrftb.for:5880 */
/*<       mq0=ftab(l+9) >*/
	mq0 = ftab[l + 9];
/* SOURCE fqshrftb.for:5881 */
/*<       dma=(ftab(it+8)-ma0)*dyi >*/
	*dma = static_cast<double>((static_cast<double>(ftab[it + 8]) - ma0)) * dyi;
/* SOURCE fqshrftb.for:5882 */
/*<       dmq=(ftab(it+9)-mq0)*dyi >*/
	*dmq = static_cast<double>((static_cast<double>(ftab[it + 9]) - mq0)) * dyi;
/* SOURCE fqshrftb.for:5883 */
/*<       ma=ma0+dma*h >*/
	*ma = static_cast<double>(ma0) + static_cast<double>(*dma) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:5884 */
/*<       mq=mq0+dmq*h >*/
	*mq = static_cast<double>(mq0) + static_cast<double>(*dmq) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:5885 */
/*<    26 continue >*/
L26:
/* SOURCE fqshrftb.for:5886 */
/*<       else >*/
	;
    } else {
/* SOURCE fqshrftb.for:5887 */
/*<       k1=ftab(it+3) >*/
	k1 = ftab[it + 3];
/* SOURCE fqshrftb.for:5888 */
/*<       b1=ftab(it+4) >*/
	b1 = ftab[it + 4];
/* SOURCE fqshrftb.for:5889 */
/*<       p=h*dyi >*/
	p = static_cast<double>(feq_gen_h_d_) * dyi;
/*       compute factors on left and right derivative. */
/* SOURCE fqshrftb.for:5891 */
/*<       flp=(1.0-p)*p*dy >*/
	flp = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * p) * dy;
/* SOURCE fqshrftb.for:5892 */
/*<       frp=-flp*p >*/
	frp = static_cast<double>(-flp) * p;
/* SOURCE fqshrftb.for:5893 */
/*<       flp=flp*(1.0-p) >*/
	flp *= static_cast<double>(static_cast<double>((float)1.) - p);
/*       compute factors on left and right function value */
/* SOURCE fqshrftb.for:5895 */
/*<       fl=2.*p+1.0 >*/
	fl = static_cast<double>(static_cast<double>(p) * (float)2.) + (float)1.;
/* SOURCE fqshrftb.for:5896 */
/*<       fr=(4.0-fl)*p*p >*/
	fr = static_cast<double>(static_cast<double>((static_cast<double>((float)4.) - fl)) * p) * p;
/* SOURCE fqshrftb.for:5897 */
/*<       fl=fl*(1.0-p)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>((float)1.) - p;
	fl *= static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*       compute the factors based on relative interval for computing derivatives. */
/* SOURCE fqshrftb.for:5899 */
/*<       dlp=1.-3.*p >*/
	dlp = static_cast<double>((float)1.) - static_cast<double>(p) * (float)3.;
/* SOURCE fqshrftb.for:5900 */
/*<       drp=-(1.+dlp)*p >*/
	drp = static_cast<double>(-(static_cast<double>(dlp) + (float)1.)) * p;
/* SOURCE fqshrftb.for:5901 */
/*<       dlp=dlp*(1.0-p) >*/
	dlp *= static_cast<double>(static_cast<double>((float)1.) - p);
/* SOURCE fqshrftb.for:5902 */
/*<       dmf=6.*(1.0-p)*p*dyi >*/
	dmf = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * (float)6.) * p) * dyi;
/* SOURCE fqshrftb.for:5904 */
/*<       goto(33,34,35),type-32 >*/
	switch (feq_gen_type_d_ - 32) {
	    case 1:  goto L33;
	    case 2:  goto L34;
	    case 3:  goto L35;
	}
/* SOURCE fqshrftb.for:5905 */
/*<    33 continue >*/
L33:
/*           Find the remaining elements from type 33 */
/* SOURCE fqshrftb.for:5907 */
/*<       ma0=ftab(l+5) >*/
	ma0 = ftab[l + 5];
/* SOURCE fqshrftb.for:5908 */
/*<       mq0=ftab(l+6) >*/
	mq0 = ftab[l + 6];
/* SOURCE fqshrftb.for:5909 */
/*<       ma1=ftab(it+5) >*/
	ma1 = ftab[it + 5];
/* SOURCE fqshrftb.for:5910 */
/*<       mq1=ftab(it+6) >*/
	mq1 = ftab[it + 6];
/* SOURCE fqshrftb.for:5911 */
/*<       goto36 >*/
	goto L36;
/* SOURCE fqshrftb.for:5912 */
/*<    34 continue >*/
L34:
/*           Find the remaining elements from type 34 */
/* SOURCE fqshrftb.for:5914 */
/*<       ma0=ftab(l+6) >*/
	ma0 = ftab[l + 6];
/* SOURCE fqshrftb.for:5915 */
/*<       mq0=ftab(l+7) >*/
	mq0 = ftab[l + 7];
/* SOURCE fqshrftb.for:5916 */
/*<       ma1=ftab(it+6) >*/
	ma1 = ftab[it + 6];
/* SOURCE fqshrftb.for:5917 */
/*<       mq1=ftab(it+7) >*/
	mq1 = ftab[it + 7];
/* SOURCE fqshrftb.for:5918 */
/*<       goto36 >*/
	goto L36;
/* SOURCE fqshrftb.for:5919 */
/*<    35 continue >*/
L35:
/*           Find the remaining elements from type 35 */
/* SOURCE fqshrftb.for:5921 */
/*<       ma0=ftab(l+8) >*/
	ma0 = ftab[l + 8];
/* SOURCE fqshrftb.for:5922 */
/*<       mq0=ftab(l+9) >*/
	mq0 = ftab[l + 9];
/* SOURCE fqshrftb.for:5923 */
/*<       ma1=ftab(it+8) >*/
	ma1 = ftab[it + 8];
/* SOURCE fqshrftb.for:5924 */
/*<       mq1=ftab(it+9) >*/
	mq1 = ftab[it + 9];
/* SOURCE fqshrftb.for:5925 */
/*<    36 continue >*/
L36:
/* SOURCE fqshrftb.for:5927 */
/*<       l=l+doff >*/
	l += doff;
/* SOURCE fqshrftb.for:5928 */
/*<       it=it+doff >*/
	it += doff;
/* SOURCE fqshrftb.for:5929 */
/*<       dk0=ftab(l) >*/
	dk0 = ftab[l];
/* SOURCE fqshrftb.for:5930 */
/*<       dk1=ftab(it) >*/
	dk1 = ftab[it];
/* SOURCE fqshrftb.for:5932 */
/*<       db0=ftab(l+1) >*/
	db0 = ftab[l + 1];
/* SOURCE fqshrftb.for:5933 */
/*<       db1=ftab(it+1) >*/
	db1 = ftab[it + 1];
/* SOURCE fqshrftb.for:5935 */
/*<       dma0=ftab(l+2) >*/
	dma0 = ftab[l + 2];
/* SOURCE fqshrftb.for:5936 */
/*<       dma1=ftab(it+2) >*/
	dma1 = ftab[it + 2];
/* SOURCE fqshrftb.for:5938 */
/*<       dmq0=ftab(l+3) >*/
	dmq0 = ftab[l + 3];
/* SOURCE fqshrftb.for:5939 */
/*<       dmq1=ftab(it+3) >*/
	dmq1 = ftab[it + 3];
/* SOURCE fqshrftb.for:5941 */
/*<       k=flp*dk0+frp*dk1+fl*k0+fr*k1 >*/
	*k = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dk0) + static_cast<double>(frp) * dk1) + static_cast<double>(fl) * k0) + static_cast<double>(fr) * k1;
/* SOURCE fqshrftb.for:5942 */
/*<       dk=dlp*dk0+drp*dk1+dmf*(k1-k0) >*/
	*dk = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dk0) + static_cast<double>(drp) * dk1) + static_cast<double>(dmf) * (static_cast<double>(k1) - k0);
/* SOURCE fqshrftb.for:5944 */
/*<       b=flp*db0+frp*db1+fl*b0+fr*b1 >*/
	*b = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * db0) + static_cast<double>(frp) * db1) + static_cast<double>(fl) * b0) + static_cast<double>(fr) * b1;
/* SOURCE fqshrftb.for:5945 */
/*<       db=dlp*db0+drp*db1+dmf*(b1-b0) >*/
	*db = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * db0) + static_cast<double>(drp) * db1) + static_cast<double>(dmf) * (static_cast<double>(b1) - b0);
/* SOURCE fqshrftb.for:5947 */
/*<       ma=flp*dma0+frp*dma1+fl*ma0+fr*ma1 >*/
	*ma = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dma0) + static_cast<double>(frp) * dma1) + static_cast<double>(fl) * ma0) + static_cast<double>(fr) * ma1;
/* SOURCE fqshrftb.for:5948 */
/*<       dma=dlp*dma0+drp*dma1+dmf*(ma1-ma0) >*/
	*dma = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dma0) + static_cast<double>(drp) * dma1) + static_cast<double>(dmf) * (static_cast<double>(ma1) - ma0);
/* SOURCE fqshrftb.for:5950 */
/*<       mq=flp*dmq0+frp*dmq1+fl*mq0+fr*mq1 >*/
	*mq = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dmq0) + static_cast<double>(frp) * dmq1) + static_cast<double>(fl) * mq0) + static_cast<double>(fr) * mq1;
/* SOURCE fqshrftb.for:5951 */
/*<       dmq=dlp*dmq0+drp*dmq1+dmf*(mq1-mq0) >*/
	*dmq = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dmq0) + static_cast<double>(drp) * dmq1) + static_cast<double>(dmf) * (static_cast<double>(mq1) - mq0);
/* SOURCE fqshrftb.for:5952 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:5954 */
/*<       dk=(k+k)*dk >*/
    *dk = static_cast<double>((static_cast<double>(*k) + *k)) * *dk;
/* SOURCE fqshrftb.for:5955 */
/*<       k=k*k >*/
    *k *= *k;
/* SOURCE fqshrftb.for:5957 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:5959 */
/*<       end >*/
} /* xlkt23_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:5963 */
/*<       subroutinexlkt24(adrs,ya,a,t,dt,j,k,dk,b,db,ma,dma,mq,dmq) >*/
/* Subroutine */ int xlkt24_(integer *adrs, real *ya, real *a, real *t, real *
	dt, real *j, real *k, real *dk, real *b, real *db, real *ma, real *
	dma, real *mq, real *dmq)
{
    /* Initialized data */

    static integer vtype[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,1,1,0,0,0,0,0,0,0,0,1,1 };

    /* Format strings */
    static char fmt_2000[] = "(\002 \002,\002*WRN:02* X-SECTION BELOW RANGE \
IN XLKT24\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";
    static char fmt_2010[] = "(\002 \002,\002*WRN:03* X-SECTION ABOVE RANGE \
IN XLKT24\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real p, y, a0, b0, b1, j0, k0, k1, t0, y0;
    integer ha, la;
    real hh, fl;
    char cs[16];
    real fr;
    integer it;
    real dy, db0, db1, ma0, dk0, dk1, ma1, mq0, mq1, dmf;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real dlp, flp, dyi, drp, frp, dma0, dma1, dmq0, dmq1;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__777 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__778 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth find area, top-width, conveyance, etc. */
/*     using direct linear interpolation for top width. */
/* SOURCE fqshrftb.for:5972 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:5974 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:5975 */
/*<       reala,b,db,dk,dma,dmq,dt,j,k,ma,mq,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     J      - first moment of area about water surface in the table */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     MA     - weight factor on area to get volume per unit length */
/*     DMA    - derivative of the sinuosity correction of area wrt depth */
/*     MQ     - weight factor on flow to get momentum per unit length */
/*     DMQ    - derivative of the sinuosity correction of momentum wrt */
/*               depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:5996 */
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
/* INCLUDE fqshrftb.for:5997 */
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
/* INCLUDE fqshrftb.for:5998 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:5999 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:6002 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:6003 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:6006 */
/*<       integerha,it,l,la,type,xoff,doff >*/
/* SOURCE fqshrftb.for:6007 */
/*<        >*/
/* SOURCE fqshrftb.for:6010 */
/*<       realflp,frp,fl,fr,dlp,drp,dmf,p >*/
/* SOURCE fqshrftb.for:6012 */
/*<       charactercs*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:6015 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:6016 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:6019 */
/*<       datavtype/23*0,1,1,4*0,4*0,1,1/ >*/
/* SOURCE fqshrftb.for:6022 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:6027 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKT24 */
/* SOURCE fqshrftb.for:6037 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:6038 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:6039 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:6040 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:6041 */
/*<       doff=itab(adrs+21) >*/
    doff = itab[*adrs + 21];
/* SOURCE fqshrftb.for:6043 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:6044 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:6045 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:6046 */
/*<       callxstype(stdout,vtype,adrs) >*/
	xstype_(&xscom_1.stdout, vtype, adrs);
/* SOURCE fqshrftb.for:6048 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:6049 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6051 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:6053 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:6054 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:6055 */
/*<       write(stdout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__777.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__777);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:6057 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:6058 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:6059 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:6060 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:6061 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:6062 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:6063 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:6064 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:6065 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:6066 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6067 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:6069 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:6070 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:6071 */
/*<       write(stdout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__778.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__778);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:6073 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:6074 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:6075 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:6076 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:6077 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:6078 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:6079 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:6080 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6081 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:6088 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
/*     FETCH VALUES FROM FTAB */
/* SOURCE fqshrftb.for:6092 */
/*<       y0=ftab(l) >*/
    y0 = ftab[l];
/* SOURCE fqshrftb.for:6093 */
/*<       t0=ftab(l+1) >*/
    t0 = ftab[l + 1];
/* SOURCE fqshrftb.for:6094 */
/*<       a0=ftab(l+2) >*/
    a0 = ftab[l + 2];
/* SOURCE fqshrftb.for:6095 */
/*<       k0=ftab(l+3) >*/
    k0 = ftab[l + 3];
/* SOURCE fqshrftb.for:6096 */
/*<       b0=ftab(l+4) >*/
    b0 = ftab[l + 4];
/* SOURCE fqshrftb.for:6097 */
/*<       j0=ftab(l+5) >*/
    j0 = ftab[l + 5];
/* SOURCE fqshrftb.for:6098 */
/*<       it=l+xoff >*/
    it = l + xoff;
/* SOURCE fqshrftb.for:6099 */
/*<       k1=ftab(it+3) >*/
    k1 = ftab[it + 3];
/* SOURCE fqshrftb.for:6100 */
/*<       b1=ftab(it+4) >*/
    b1 = ftab[it + 4];
/*     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE) */
/*     N.B. K IN FTAB IS SQRT(CONVEYANCE) */
/* SOURCE fqshrftb.for:6104 */
/*<       dy=ftab(it)-y0 >*/
    dy = static_cast<double>(ftab[it]) - y0;
/* SOURCE fqshrftb.for:6105 */
/*<       h=y-y0 >*/
    feq_gen_h_d_ = static_cast<double>(y) - y0;
/* SOURCE fqshrftb.for:6106 */
/*<       hh=0.5*h >*/
    hh = static_cast<double>(feq_gen_h_d_) * (float).5;
/* SOURCE fqshrftb.for:6107 */
/*<       dyi=1.0/dy >*/
    dyi = static_cast<double>((float)1.) / dy;
/* SOURCE fqshrftb.for:6108 */
/*<       dt=(ftab(it+1)-t0)*dyi >*/
    *dt = static_cast<double>((static_cast<double>(ftab[it + 1]) - t0)) * dyi;
/* SOURCE fqshrftb.for:6109 */
/*<       t=t0+h*dt >*/
    *t = static_cast<double>(t0) + static_cast<double>(feq_gen_h_d_) * *dt;
/* SOURCE fqshrftb.for:6110 */
/*<       a=a0+hh*(t+t0) >*/
    *a = static_cast<double>(a0) + static_cast<double>(hh) * (static_cast<double>(*t) + t0);
/* SOURCE fqshrftb.for:6111 */
/*<       j=j0+hh*(a+a0-h*(t-t0)*0.1666667) >*/
    *j = static_cast<double>(j0) + static_cast<double>(hh) * (static_cast<double>(static_cast<double>(*a) + a0) - static_cast<double>(static_cast<double>(feq_gen_h_d_) * (static_cast<double>(*t) - t0)) * (float).1666667);
/* SOURCE fqshrftb.for:6113 */
/*<       if(doff.eq.0)then >*/
    if (doff == 0) {
/* SOURCE fqshrftb.for:6114 */
/*<       db=(b1-b0)*dyi >*/
	*db = static_cast<double>((static_cast<double>(b1) - b0)) * dyi;
/* SOURCE fqshrftb.for:6115 */
/*<       b=b0+h*db >*/
	*b = static_cast<double>(b0) + static_cast<double>(feq_gen_h_d_) * *db;
/* SOURCE fqshrftb.for:6116 */
/*<       dk=(k1-k0)*dyi >*/
	*dk = static_cast<double>((static_cast<double>(k1) - k0)) * dyi;
/* SOURCE fqshrftb.for:6117 */
/*<       k=k0+h*dk >*/
	*k = static_cast<double>(k0) + static_cast<double>(feq_gen_h_d_) * *dk;
/* SOURCE fqshrftb.for:6118 */
/*<       if(type.eq.24)then >*/
	if (feq_gen_type_d_ == 24) {
/*         find the curvilinear elements from type 24 */
/* SOURCE fqshrftb.for:6120 */
/*<       ma0=ftab(l+6) >*/
	    ma0 = ftab[l + 6];
/* SOURCE fqshrftb.for:6121 */
/*<       mq0=ftab(l+7) >*/
	    mq0 = ftab[l + 7];
/* SOURCE fqshrftb.for:6122 */
/*<       dma=(ftab(it+6)-ma0)*dyi >*/
	    *dma = static_cast<double>((static_cast<double>(ftab[it + 6]) - ma0)) * dyi;
/* SOURCE fqshrftb.for:6123 */
/*<       dmq=(ftab(it+7)-mq0)*dyi >*/
	    *dmq = static_cast<double>((static_cast<double>(ftab[it + 7]) - mq0)) * dyi;
/* SOURCE fqshrftb.for:6124 */
/*<       ma=ma0+dma*h >*/
	    *ma = static_cast<double>(ma0) + static_cast<double>(*dma) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:6125 */
/*<       mq=mq0+dmq*h >*/
	    *mq = static_cast<double>(mq0) + static_cast<double>(*dmq) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:6126 */
/*<       else >*/
	} else {
/*         find the curvilinear elements from type 25 */
/* SOURCE fqshrftb.for:6128 */
/*<       ma0=ftab(l+8) >*/
	    ma0 = ftab[l + 8];
/* SOURCE fqshrftb.for:6129 */
/*<       mq0=ftab(l+9) >*/
	    mq0 = ftab[l + 9];
/* SOURCE fqshrftb.for:6130 */
/*<       dma=(ftab(it+8)-ma0)*dyi >*/
	    *dma = static_cast<double>((static_cast<double>(ftab[it + 8]) - ma0)) * dyi;
/* SOURCE fqshrftb.for:6131 */
/*<       dmq=(ftab(it+9)-mq0)*dyi >*/
	    *dmq = static_cast<double>((static_cast<double>(ftab[it + 9]) - mq0)) * dyi;
/* SOURCE fqshrftb.for:6132 */
/*<       ma=ma0+dma*h >*/
	    *ma = static_cast<double>(ma0) + static_cast<double>(*dma) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:6133 */
/*<       mq=mq0+dmq*h >*/
	    *mq = static_cast<double>(mq0) + static_cast<double>(*dmq) * feq_gen_h_d_;
/* SOURCE fqshrftb.for:6134 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6135 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:6136 */
/*<       p=h*dyi >*/
	p = static_cast<double>(feq_gen_h_d_) * dyi;
/*       compute factors on left and right derivative. */
/* SOURCE fqshrftb.for:6138 */
/*<       flp=(1.0-p)*p*dy >*/
	flp = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * p) * dy;
/* SOURCE fqshrftb.for:6139 */
/*<       frp=-flp*p >*/
	frp = static_cast<double>(-flp) * p;
/* SOURCE fqshrftb.for:6140 */
/*<       flp=flp*(1.0-p) >*/
	flp *= static_cast<double>(static_cast<double>((float)1.) - p);
/*       compute factors on left and right function value */
/* SOURCE fqshrftb.for:6142 */
/*<       fl=2.*p+1.0 >*/
	fl = static_cast<double>(static_cast<double>(p) * (float)2.) + (float)1.;
/* SOURCE fqshrftb.for:6143 */
/*<       fr=(4.0-fl)*p*p >*/
	fr = static_cast<double>(static_cast<double>((static_cast<double>((float)4.) - fl)) * p) * p;
/* SOURCE fqshrftb.for:6144 */
/*<       fl=fl*(1.0-p)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>((float)1.) - p;
	fl *= static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*       compute the factors based on relative interval for computing derivatives. */
/* SOURCE fqshrftb.for:6146 */
/*<       dlp=1.-3.*p >*/
	dlp = static_cast<double>((float)1.) - static_cast<double>(p) * (float)3.;
/* SOURCE fqshrftb.for:6147 */
/*<       drp=-(1.+dlp)*p >*/
	drp = static_cast<double>(-(static_cast<double>(dlp) + (float)1.)) * p;
/* SOURCE fqshrftb.for:6148 */
/*<       dlp=dlp*(1.0-p) >*/
	dlp *= static_cast<double>(static_cast<double>((float)1.) - p);
/* SOURCE fqshrftb.for:6149 */
/*<       dmf=6.*(1.0-p)*p*dyi >*/
	dmf = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * (float)6.) * p) * dyi;
/* SOURCE fqshrftb.for:6151 */
/*<       goto(34,35),type-33 >*/
	switch (feq_gen_type_d_ - 33) {
	    case 1:  goto L34;
	    case 2:  goto L35;
	}
/* SOURCE fqshrftb.for:6152 */
/*<    34 continue >*/
L34:
/*           Find the remaining elements from type 34 */
/* SOURCE fqshrftb.for:6154 */
/*<       ma0=ftab(l+6) >*/
	ma0 = ftab[l + 6];
/* SOURCE fqshrftb.for:6155 */
/*<       mq0=ftab(l+7) >*/
	mq0 = ftab[l + 7];
/* SOURCE fqshrftb.for:6156 */
/*<       ma1=ftab(it+6) >*/
	ma1 = ftab[it + 6];
/* SOURCE fqshrftb.for:6157 */
/*<       mq1=ftab(it+7) >*/
	mq1 = ftab[it + 7];
/* SOURCE fqshrftb.for:6158 */
/*<       goto36 >*/
	goto L36;
/* SOURCE fqshrftb.for:6159 */
/*<    35 continue >*/
L35:
/*           Find the remaining elements from type 35 */
/* SOURCE fqshrftb.for:6161 */
/*<       ma0=ftab(l+8) >*/
	ma0 = ftab[l + 8];
/* SOURCE fqshrftb.for:6162 */
/*<       mq0=ftab(l+9) >*/
	mq0 = ftab[l + 9];
/* SOURCE fqshrftb.for:6163 */
/*<       ma1=ftab(it+8) >*/
	ma1 = ftab[it + 8];
/* SOURCE fqshrftb.for:6164 */
/*<       mq1=ftab(it+9) >*/
	mq1 = ftab[it + 9];
/* SOURCE fqshrftb.for:6166 */
/*<    36 continue >*/
L36:
/* SOURCE fqshrftb.for:6168 */
/*<       l=l+doff >*/
	l += doff;
/* SOURCE fqshrftb.for:6169 */
/*<       it=it+doff >*/
	it += doff;
/* SOURCE fqshrftb.for:6171 */
/*<       dk0=ftab(l) >*/
	dk0 = ftab[l];
/* SOURCE fqshrftb.for:6172 */
/*<       dk1=ftab(it) >*/
	dk1 = ftab[it];
/* SOURCE fqshrftb.for:6174 */
/*<       db0=ftab(l+1) >*/
	db0 = ftab[l + 1];
/* SOURCE fqshrftb.for:6175 */
/*<       db1=ftab(it+1) >*/
	db1 = ftab[it + 1];
/* SOURCE fqshrftb.for:6177 */
/*<       dma0=ftab(l+2) >*/
	dma0 = ftab[l + 2];
/* SOURCE fqshrftb.for:6178 */
/*<       dma1=ftab(it+2) >*/
	dma1 = ftab[it + 2];
/* SOURCE fqshrftb.for:6180 */
/*<       dmq0=ftab(l+3) >*/
	dmq0 = ftab[l + 3];
/* SOURCE fqshrftb.for:6181 */
/*<       dmq1=ftab(it+3) >*/
	dmq1 = ftab[it + 3];
/* SOURCE fqshrftb.for:6184 */
/*<       k=flp*dk0+frp*dk1+fl*k0+fr*k1 >*/
	*k = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dk0) + static_cast<double>(frp) * dk1) + static_cast<double>(fl) * k0) + static_cast<double>(fr) * k1;
/* SOURCE fqshrftb.for:6185 */
/*<       dk=dlp*dk0+drp*dk1+dmf*(k1-k0) >*/
	*dk = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dk0) + static_cast<double>(drp) * dk1) + static_cast<double>(dmf) * (static_cast<double>(k1) - k0);
/* SOURCE fqshrftb.for:6187 */
/*<       b=flp*db0+frp*db1+fl*b0+fr*b1 >*/
	*b = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * db0) + static_cast<double>(frp) * db1) + static_cast<double>(fl) * b0) + static_cast<double>(fr) * b1;
/* SOURCE fqshrftb.for:6188 */
/*<       db=dlp*db0+drp*db1+dmf*(b1-b0) >*/
	*db = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * db0) + static_cast<double>(drp) * db1) + static_cast<double>(dmf) * (static_cast<double>(b1) - b0);
/* SOURCE fqshrftb.for:6190 */
/*<       ma=flp*dma0+frp*dma1+fl*ma0+fr*ma1 >*/
	*ma = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dma0) + static_cast<double>(frp) * dma1) + static_cast<double>(fl) * ma0) + static_cast<double>(fr) * ma1;
/* SOURCE fqshrftb.for:6191 */
/*<       dma=dlp*dma0+drp*dma1+dmf*(ma1-ma0) >*/
	*dma = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dma0) + static_cast<double>(drp) * dma1) + static_cast<double>(dmf) * (static_cast<double>(ma1) - ma0);
/* SOURCE fqshrftb.for:6193 */
/*<       mq=flp*dmq0+frp*dmq1+fl*mq0+fr*mq1 >*/
	*mq = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dmq0) + static_cast<double>(frp) * dmq1) + static_cast<double>(fl) * mq0) + static_cast<double>(fr) * mq1;
/* SOURCE fqshrftb.for:6194 */
/*<       dmq=dlp*dmq0+drp*dmq1+dmf*(mq1-mq0) >*/
	*dmq = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dmq0) + static_cast<double>(drp) * dmq1) + static_cast<double>(dmf) * (static_cast<double>(mq1) - mq0);
/* SOURCE fqshrftb.for:6195 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6197 */
/*<       dk=(k+k)*dk >*/
    *dk = static_cast<double>((static_cast<double>(*k) + *k)) * *dk;
/* SOURCE fqshrftb.for:6198 */
/*<       k=k*k >*/
    *k *= *k;
/* SOURCE fqshrftb.for:6199 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:6202 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:6203 */
/*<       end >*/
} /* xlkt24_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:6207 */
/*<        >*/
/* Subroutine */ int xlkt25_(integer *adrs, real *ya, real *a, real *t, real *
	dt, real *j, real *k, real *dk, real *b, real *db, real *alp, real *
	dalp, real *qc, real *ma, real *dma, real *mq, real *dmq)
{
    /* Initialized data */

    static integer vtype[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,1,0,0,0,0,0,0,0,0,0,1 };

    /* Format strings */
    static char fmt_2000[] = "(\002 \002,\002*WRN:33* X-SECTION BELOW RANGE \
IN XLKT25\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";
    static char fmt_2010[] = "(\002 \002,\002*WRN:34* X-SECTION ABOVE RANGE \
IN XLKT25\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double log(doublereal), exp(doublereal);

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real p, y, a0, b0, b1, j0, k0, k1, t0, y0, y1;
    integer ha, la;
    real hh, fl;
    char cs[16];
    real fr;
    integer it;
    real dy, db0, db1, ma0, dk0, dk1, ma1, qc0, qc1, mq0, mq1, dmf;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real dlp, flp, dyi, drp, frp, dma0, dma1, alp0, alp1, dmq0, dmq1;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real dalp0, dalp1;
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__824 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__825 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given the depth, YA, find: A-area; T-top width; DT- derivative */
/*     of top width; J-first moment of area about water surface; */
/*     K-conveyance; DK=derivative of conveyance; B- beta; */
/*     DB- derivative of beta; ALP-alpha;  DALP-derivative of */
/*     alpha;  QC, critical flow; MA= correction factor on area */
/*     to give volume per unit length for the distance axis; */
/*     DMA= derivative wrt depth of MA; MQ= correction factor */
/*     on Q to give momentum per unit length for the distance */
/*     axis; and DMQ= derivative wrt depth of MQ. */
/* SOURCE fqshrftb.for:6224 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:6226 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:6227 */
/*<       reala,alp,b,dalp,db,dk,dma,dmq,dt,j,k,ma,mq,qc,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     J      - first moment of area about water surface in the table */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     ALP    - value of energy flux correction coefficient */
/*     DALP   - derivative wrt depth of the energy flux coefficient */
/*     QC     - critical flow */
/*     MA     - weight factor on area to get volume per unit length */
/*     DMA    - derivative of the sinuosity correction of area wrt depth */
/*     MQ     - weight factor on flow to get momentum per unit length */
/*     DMQ    - derivative of the sinuosity correction of momentum wrt */
/*               depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:6252 */
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
/* INCLUDE fqshrftb.for:6253 */
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
/* INCLUDE fqshrftb.for:6254 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:6255 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:6258 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:6259 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:6262 */
/*<       integerha,l,la,type,xoff,doff,it >*/
/* SOURCE fqshrftb.for:6263 */
/*<        >*/
/* SOURCE fqshrftb.for:6267 */
/*<       realflp,frp,fl,fr,dlp,drp,dmf,p >*/
/* SOURCE fqshrftb.for:6269 */
/*<       charactercs*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:6271 */
/*<       intrinsicexp,log >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:6274 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:6275 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:6278 */
/*<       datavtype/24*0,1,4*0,5*0,1/ >*/
/* SOURCE fqshrftb.for:6281 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:6286 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKT25 */
/* SOURCE fqshrftb.for:6296 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:6297 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:6298 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:6299 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:6300 */
/*<       doff=itab(adrs+21) >*/
    doff = itab[*adrs + 21];
/* SOURCE fqshrftb.for:6302 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:6303 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:6304 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:6305 */
/*<       callxstype(stdout,vtype,adrs) >*/
	xstype_(&xscom_1.stdout, vtype, adrs);
/* SOURCE fqshrftb.for:6307 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:6308 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6310 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:6312 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:6313 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:6314 */
/*<       write(stdout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__824.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__824);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:6316 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:6317 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:6318 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:6319 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:6320 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:6321 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:6322 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:6323 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:6324 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:6325 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6326 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:6328 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:6329 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:6330 */
/*<       write(stdout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__825.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__825);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:6332 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:6333 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:6334 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:6335 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:6336 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:6337 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:6338 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:6339 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6340 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:6347 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
/*     FETCH VALUES FROM FTAB */
/* SOURCE fqshrftb.for:6351 */
/*<       y0=ftab(l) >*/
    y0 = ftab[l];
/* SOURCE fqshrftb.for:6352 */
/*<       t0=ftab(l+1) >*/
    t0 = ftab[l + 1];
/* SOURCE fqshrftb.for:6353 */
/*<       a0=ftab(l+2) >*/
    a0 = ftab[l + 2];
/* SOURCE fqshrftb.for:6354 */
/*<       k0=ftab(l+3) >*/
    k0 = ftab[l + 3];
/* SOURCE fqshrftb.for:6355 */
/*<       b0=ftab(l+4) >*/
    b0 = ftab[l + 4];
/* SOURCE fqshrftb.for:6356 */
/*<       j0=ftab(l+5) >*/
    j0 = ftab[l + 5];
/* SOURCE fqshrftb.for:6357 */
/*<       alp0=ftab(l+6) >*/
    alp0 = ftab[l + 6];
/* SOURCE fqshrftb.for:6358 */
/*<       qc0=ftab(l+7) >*/
    qc0 = ftab[l + 7];
/* SOURCE fqshrftb.for:6359 */
/*<       ma0=ftab(l+8) >*/
    ma0 = ftab[l + 8];
/* SOURCE fqshrftb.for:6360 */
/*<       mq0=ftab(l+9) >*/
    mq0 = ftab[l + 9];
/* SOURCE fqshrftb.for:6362 */
/*<       it=l+xoff >*/
    it = l + xoff;
/* SOURCE fqshrftb.for:6363 */
/*<       k1=ftab(it+3) >*/
    k1 = ftab[it + 3];
/* SOURCE fqshrftb.for:6364 */
/*<       b1=ftab(it+4) >*/
    b1 = ftab[it + 4];
/* SOURCE fqshrftb.for:6365 */
/*<       alp1=ftab(it+6) >*/
    alp1 = ftab[it + 6];
/* SOURCE fqshrftb.for:6366 */
/*<       ma1=ftab(it+8) >*/
    ma1 = ftab[it + 8];
/* SOURCE fqshrftb.for:6367 */
/*<       mq1=ftab(it+9) >*/
    mq1 = ftab[it + 9];
/*     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE) */
/*     N.B. K IN FTAB IS SQRT(CONVEYANCE) */
/* SOURCE fqshrftb.for:6371 */
/*<       y1=ftab(it) >*/
    y1 = ftab[it];
/* SOURCE fqshrftb.for:6372 */
/*<       dy=y1-y0 >*/
    dy = static_cast<double>(y1) - y0;
/* SOURCE fqshrftb.for:6373 */
/*<       dyi=1.0/dy >*/
    dyi = static_cast<double>((float)1.) / dy;
/* SOURCE fqshrftb.for:6374 */
/*<       h=y-y0 >*/
    feq_gen_h_d_ = static_cast<double>(y) - y0;
/* SOURCE fqshrftb.for:6375 */
/*<       hh=0.5*h >*/
    hh = static_cast<double>(feq_gen_h_d_) * (float).5;
/* SOURCE fqshrftb.for:6376 */
/*<       dt=(ftab(it+1)-t0)*dyi >*/
    *dt = static_cast<double>((static_cast<double>(ftab[it + 1]) - t0)) * dyi;
/* SOURCE fqshrftb.for:6377 */
/*<       qc1=ftab(it+7) >*/
    qc1 = ftab[it + 7];
/* SOURCE fqshrftb.for:6378 */
/*<       t=t0+h*dt >*/
    *t = static_cast<double>(t0) + static_cast<double>(feq_gen_h_d_) * *dt;
/* SOURCE fqshrftb.for:6379 */
/*<       a=a0+hh*(t+t0) >*/
    *a = static_cast<double>(a0) + static_cast<double>(hh) * (static_cast<double>(*t) + t0);
/* SOURCE fqshrftb.for:6380 */
/*<       j=j0+hh*(a+a0-h*(t-t0)/6.) >*/
    *j = static_cast<double>(j0) + static_cast<double>(hh) * (static_cast<double>(static_cast<double>(*a) + a0) - static_cast<double>(static_cast<double>(feq_gen_h_d_) * (static_cast<double>(*t) - t0)) / (float)6.);
/*     COMPUTE VALUE OF QC USING LOGARITHMS */
/* SOURCE fqshrftb.for:6384 */
/*<       if(y0.eq.0.0)then >*/
    if (y0 == (float)0.) {
/* SOURCE fqshrftb.for:6385 */
/*<       la=l+xoff >*/
	la = l + xoff;
/* SOURCE fqshrftb.for:6386 */
/*<       y0=ftab(la) >*/
	y0 = ftab[la];
/* SOURCE fqshrftb.for:6387 */
/*<       y1=ftab(la+xoff) >*/
	y1 = ftab[la + xoff];
/* SOURCE fqshrftb.for:6388 */
/*<       qc0=ftab(la+7) >*/
	qc0 = ftab[la + 7];
/* SOURCE fqshrftb.for:6389 */
/*<       qc1=ftab(la+xoff+7) >*/
	qc1 = ftab[la + xoff + 7];
/* SOURCE fqshrftb.for:6390 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6392 */
/*<       if(doff.eq.0)then >*/
    if (doff == 0) {
/* SOURCE fqshrftb.for:6393 */
/*<       db=(b1-b0)*dyi >*/
	*db = static_cast<double>((static_cast<double>(b1) - b0)) * dyi;
/* SOURCE fqshrftb.for:6394 */
/*<       b=b0+h*db >*/
	*b = static_cast<double>(b0) + static_cast<double>(feq_gen_h_d_) * *db;
/* SOURCE fqshrftb.for:6395 */
/*<       dalp=(alp1-alp0)*dyi >*/
	*dalp = static_cast<double>((static_cast<double>(alp1) - alp0)) * dyi;
/* SOURCE fqshrftb.for:6396 */
/*<       alp=alp0+h*dalp >*/
	*alp = static_cast<double>(alp0) + static_cast<double>(feq_gen_h_d_) * *dalp;
/* SOURCE fqshrftb.for:6397 */
/*<       dma=(ma1-ma0)*dyi >*/
	*dma = static_cast<double>((static_cast<double>(ma1) - ma0)) * dyi;
/* SOURCE fqshrftb.for:6398 */
/*<       ma=ma0+h*dma >*/
	*ma = static_cast<double>(ma0) + static_cast<double>(feq_gen_h_d_) * *dma;
/* SOURCE fqshrftb.for:6399 */
/*<       dmq=(mq1-mq0)*dyi >*/
	*dmq = static_cast<double>((static_cast<double>(mq1) - mq0)) * dyi;
/* SOURCE fqshrftb.for:6400 */
/*<       mq=mq0+h*dmq >*/
	*mq = static_cast<double>(mq0) + static_cast<double>(feq_gen_h_d_) * *dmq;
/* SOURCE fqshrftb.for:6401 */
/*<       dk=(k1-k0)*dyi >*/
	*dk = static_cast<double>((static_cast<double>(k1) - k0)) * dyi;
/* SOURCE fqshrftb.for:6402 */
/*<       k=k0+h*dk >*/
	*k = static_cast<double>(k0) + static_cast<double>(feq_gen_h_d_) * *dk;
/* SOURCE fqshrftb.for:6403 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:6404 */
/*<       p=h*dyi >*/
	p = static_cast<double>(feq_gen_h_d_) * dyi;
/*       compute factors on left and right derivative. */
/* SOURCE fqshrftb.for:6406 */
/*<       flp=(1.0-p)*p*dy >*/
	flp = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * p) * dy;
/* SOURCE fqshrftb.for:6407 */
/*<       frp=-flp*p >*/
	frp = static_cast<double>(-flp) * p;
/* SOURCE fqshrftb.for:6408 */
/*<       flp=flp*(1.0-p) >*/
	flp *= static_cast<double>(static_cast<double>((float)1.) - p);
/*       compute factors on left and right function value */
/* SOURCE fqshrftb.for:6410 */
/*<       fl=2.*p+1.0 >*/
	fl = static_cast<double>(static_cast<double>(p) * (float)2.) + (float)1.;
/* SOURCE fqshrftb.for:6411 */
/*<       fr=(4.0-fl)*p*p >*/
	fr = static_cast<double>(static_cast<double>((static_cast<double>((float)4.) - fl)) * p) * p;
/* SOURCE fqshrftb.for:6412 */
/*<       fl=fl*(1.0-p)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>((float)1.) - p;
	fl *= static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*       compute the factors based on relative interval for computing derivatives. */
/* SOURCE fqshrftb.for:6414 */
/*<       dlp=1.-3.*p >*/
	dlp = static_cast<double>((float)1.) - static_cast<double>(p) * (float)3.;
/* SOURCE fqshrftb.for:6415 */
/*<       drp=-(1.+dlp)*p >*/
	drp = static_cast<double>(-(static_cast<double>(dlp) + (float)1.)) * p;
/* SOURCE fqshrftb.for:6416 */
/*<       dlp=dlp*(1.0-p) >*/
	dlp *= static_cast<double>(static_cast<double>((float)1.) - p);
/* SOURCE fqshrftb.for:6417 */
/*<       dmf=6.*(1.0-p)*p*dyi >*/
	dmf = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * (float)6.) * p) * dyi;
/* SOURCE fqshrftb.for:6420 */
/*<       l=l+doff >*/
	l += doff;
/* SOURCE fqshrftb.for:6421 */
/*<       it=it+doff >*/
	it += doff;
/* SOURCE fqshrftb.for:6423 */
/*<       dk0=ftab(l) >*/
	dk0 = ftab[l];
/* SOURCE fqshrftb.for:6424 */
/*<       dk1=ftab(it) >*/
	dk1 = ftab[it];
/* SOURCE fqshrftb.for:6426 */
/*<       db0=ftab(l+1) >*/
	db0 = ftab[l + 1];
/* SOURCE fqshrftb.for:6427 */
/*<       db1=ftab(it+1) >*/
	db1 = ftab[it + 1];
/* SOURCE fqshrftb.for:6429 */
/*<       dma0=ftab(l+2) >*/
	dma0 = ftab[l + 2];
/* SOURCE fqshrftb.for:6430 */
/*<       dma1=ftab(it+2) >*/
	dma1 = ftab[it + 2];
/* SOURCE fqshrftb.for:6432 */
/*<       dmq0=ftab(l+3) >*/
	dmq0 = ftab[l + 3];
/* SOURCE fqshrftb.for:6433 */
/*<       dmq1=ftab(it+3) >*/
	dmq1 = ftab[it + 3];
/* SOURCE fqshrftb.for:6435 */
/*<       dalp0=ftab(l+4) >*/
	dalp0 = ftab[l + 4];
/* SOURCE fqshrftb.for:6436 */
/*<       dalp1=ftab(it+4) >*/
	dalp1 = ftab[it + 4];
/* SOURCE fqshrftb.for:6438 */
/*<       k=flp*dk0+frp*dk1+fl*k0+fr*k1 >*/
	*k = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dk0) + static_cast<double>(frp) * dk1) + static_cast<double>(fl) * k0) + static_cast<double>(fr) * k1;
/* SOURCE fqshrftb.for:6439 */
/*<       dk=dlp*dk0+drp*dk1+dmf*(k1-k0) >*/
	*dk = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dk0) + static_cast<double>(drp) * dk1) + static_cast<double>(dmf) * (static_cast<double>(k1) - k0);
/* SOURCE fqshrftb.for:6441 */
/*<       b=flp*db0+frp*db1+fl*b0+fr*b1 >*/
	*b = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * db0) + static_cast<double>(frp) * db1) + static_cast<double>(fl) * b0) + static_cast<double>(fr) * b1;
/* SOURCE fqshrftb.for:6442 */
/*<       db=dlp*db0+drp*db1+dmf*(b1-b0) >*/
	*db = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * db0) + static_cast<double>(drp) * db1) + static_cast<double>(dmf) * (static_cast<double>(b1) - b0);
/* SOURCE fqshrftb.for:6444 */
/*<       ma=flp*dma0+frp*dma1+fl*ma0+fr*ma1 >*/
	*ma = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dma0) + static_cast<double>(frp) * dma1) + static_cast<double>(fl) * ma0) + static_cast<double>(fr) * ma1;
/* SOURCE fqshrftb.for:6445 */
/*<       dma=dlp*dma0+drp*dma1+dmf*(ma1-ma0) >*/
	*dma = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dma0) + static_cast<double>(drp) * dma1) + static_cast<double>(dmf) * (static_cast<double>(ma1) - ma0);
/* SOURCE fqshrftb.for:6447 */
/*<       mq=flp*dmq0+frp*dmq1+fl*mq0+fr*mq1 >*/
	*mq = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dmq0) + static_cast<double>(frp) * dmq1) + static_cast<double>(fl) * mq0) + static_cast<double>(fr) * mq1;
/* SOURCE fqshrftb.for:6448 */
/*<       dmq=dlp*dmq0+drp*dmq1+dmf*(mq1-mq0) >*/
	*dmq = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dmq0) + static_cast<double>(drp) * dmq1) + static_cast<double>(dmf) * (static_cast<double>(mq1) - mq0);
/* SOURCE fqshrftb.for:6450 */
/*<       alp=flp*dalp0+frp*dalp1+fl*alp0+fr*alp1 >*/
	*alp = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dalp0) + static_cast<double>(frp) * dalp1) + static_cast<double>(fl) * alp0) + static_cast<double>(fr) * alp1;
/* SOURCE fqshrftb.for:6451 */
/*<       dalp=dlp*dalp0+drp*dalp1+dmf*(alp1-alp0) >*/
	*dalp = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dalp0) + static_cast<double>(drp) * dalp1) + static_cast<double>(dmf) * (static_cast<double>(alp1) - alp0);
/* SOURCE fqshrftb.for:6452 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6454 */
/*<       dk=(k+k)*dk >*/
    *dk = static_cast<double>((static_cast<double>(*k) + *k)) * *dk;
/* SOURCE fqshrftb.for:6455 */
/*<       k=k*k >*/
    *k *= *k;
/* SOURCE fqshrftb.for:6457 */
/*<       if(y.gt.0.0)then >*/
    if (y > (float)0.) {
/* SOURCE fqshrftb.for:6458 */
/*<       p=log(y/y0)*log(qc1/qc0)/log(y1/y0) >*/
	p = log(static_cast<double>(y) / y0) * log(static_cast<double>(qc1) / qc0) / log(static_cast<double>(y1) / y0);
/* SOURCE fqshrftb.for:6459 */
/*<       qc=qc0*exp(p) >*/
	*qc = qc0 * exp(p);
/* SOURCE fqshrftb.for:6460 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:6461 */
/*<       qc=0.0 >*/
	*qc = (float)0.;
/* SOURCE fqshrftb.for:6462 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6464 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:6465 */
/*<       end >*/
} /* xlkt25_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:6469 */
/*<       subroutinexlktal(adrs,ya,a,t,dt,j,k,dk,b,db,alp,dalp) >*/
/* Subroutine */ int xlktal_(integer *adrs, real *ya, real *a, real *t, real *
	dt, real *j, real *k, real *dk, real *b, real *db, real *alp, real *
	dalp)
{
    /* Initialized data */

    static integer vtype[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	    0,0,1,0,0,0,0,0,0,1,0,0,1 };

    /* Format strings */
    static char fmt_2000[] = "(\002 \002,\002*WRN:31* X-SECTION BELOW RANGE \
IN XLKTAL\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";
    static char fmt_2010[] = "(\002 \002,\002*WRN:32* X-SECTION ABOVE RANGE \
IN XLKTAL\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,\
f10.3/,1x,\002 TIME           = \002,f14.0,/,1x,\002 DEPTH          = \002,f\
10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real y, a0, b0, j0, k0, t0, y0;
    integer ha, la;
    real hh, qc;
    char cs[16];
    real dy;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real alp0;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__878 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__879 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given the depth, YA, find: A-area; T-top width; DT- derivative */
/*     of top width; J-first moment of area about water surface; */
/*     K-conveyance; DK=derivative of conveyance; B- beta; */
/*     DB- derivative of beta; ALP-alpha; and DALP-derivative of */
/*     alpha.  QC is in the table but not looked up or returned. */
/* SOURCE fqshrftb.for:6481 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:6483 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:6484 */
/*<       reala,alp,b,dalp,db,dk,dt,j,k,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     J      - first moment of area about water surface in the table */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     ALP    - value of energy flux correction coefficient */
/*     DALP   - derivative wrt depth of the energy flux coefficient */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:6502 */
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
/* INCLUDE fqshrftb.for:6503 */
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
/* INCLUDE fqshrftb.for:6504 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:6505 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:6508 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:6509 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:6512 */
/*<       integerha,l,la,type,xoff >*/
/* SOURCE fqshrftb.for:6513 */
/*<       reala0,alp0,b0,dy,h,hh,j0,k0,t0,y,y0,qc >*/
/* SOURCE fqshrftb.for:6514 */
/*<       charactercs*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:6517 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:6518 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:6521 */
/*<       datavtype/21*0,1,0,0,1,4*0,0,0,1,0,0,1/ >*/
/* SOURCE fqshrftb.for:6524 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:6529 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/* SOURCE fqshrftb.for:6535 */
/*<       callxlkt22(adrs,ya,a,t,dt,j,k,dk,b,db,alp,dalp,qc) >*/
    xlkt22_(adrs, ya, a, t, dt, j, k, dk, b, db, alp, dalp, &qc);
/* SOURCE fqshrftb.for:6540 */
/*<       return >*/
    return 0;
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKTAL */
/* SOURCE fqshrftb.for:6546 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:6547 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:6548 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:6549 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:6551 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:6552 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:6553 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:6554 */
/*<       callxstype(stdout,vtype,adrs) >*/
	xstype_(&xscom_1.stdout, vtype, adrs);
/* SOURCE fqshrftb.for:6556 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:6557 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6558 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:6560 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:6561 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:6562 */
/*<       write(stdout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__878.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__878);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:6564 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:6565 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:6566 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:6567 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:6568 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:6569 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:6570 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:6571 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:6572 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:6573 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6574 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:6576 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:6577 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:6578 */
/*<       write(stdout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__879.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__879);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:6580 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:6581 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:6582 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:6583 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:6584 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:6585 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:6586 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:6587 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6588 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:6595 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
/*     FETCH VALUES FROM FTAB */
/* SOURCE fqshrftb.for:6599 */
/*<       y0=ftab(l) >*/
    y0 = ftab[l];
/* SOURCE fqshrftb.for:6600 */
/*<       t0=ftab(l+1) >*/
    t0 = ftab[l + 1];
/* SOURCE fqshrftb.for:6601 */
/*<       a0=ftab(l+2) >*/
    a0 = ftab[l + 2];
/* SOURCE fqshrftb.for:6602 */
/*<       k0=ftab(l+3) >*/
    k0 = ftab[l + 3];
/* SOURCE fqshrftb.for:6603 */
/*<       b0=ftab(l+4) >*/
    b0 = ftab[l + 4];
/* SOURCE fqshrftb.for:6604 */
/*<       j0=ftab(l+5) >*/
    j0 = ftab[l + 5];
/* SOURCE fqshrftb.for:6605 */
/*<       alp0=ftab(l+6) >*/
    alp0 = ftab[l + 6];
/*     DIRECT LINEAR INTERPOLATION FOR T AND SQRT(CONVEYANCE) */
/*     N.B. K IN FTAB IS SQRT(CONVEYANCE) */
/* SOURCE fqshrftb.for:6610 */
/*<       dy=ftab(l+xoff)-y0 >*/
    dy = static_cast<double>(ftab[l + xoff]) - y0;
/* SOURCE fqshrftb.for:6611 */
/*<       h=y-y0 >*/
    feq_gen_h_d_ = static_cast<double>(y) - y0;
/* SOURCE fqshrftb.for:6612 */
/*<       hh=0.5*h >*/
    hh = static_cast<double>(feq_gen_h_d_) * (float).5;
/* SOURCE fqshrftb.for:6613 */
/*<       db=(ftab(l+xoff+4)-b0)/dy >*/
    *db = static_cast<double>((static_cast<double>(ftab[l + xoff + 4]) - b0)) / dy;
/* SOURCE fqshrftb.for:6614 */
/*<       dt=(ftab(l+xoff+1)-t0)/dy >*/
    *dt = static_cast<double>((static_cast<double>(ftab[l + xoff + 1]) - t0)) / dy;
/* SOURCE fqshrftb.for:6615 */
/*<       dk=(ftab(l+xoff+3)-k0)/dy >*/
    *dk = static_cast<double>((static_cast<double>(ftab[l + xoff + 3]) - k0)) / dy;
/* SOURCE fqshrftb.for:6616 */
/*<       dalp=(ftab(l+xoff+6)-alp0)/dy >*/
    *dalp = static_cast<double>((static_cast<double>(ftab[l + xoff + 6]) - alp0)) / dy;
/* SOURCE fqshrftb.for:6617 */
/*<       t=t0+h*dt >*/
    *t = static_cast<double>(t0) + static_cast<double>(feq_gen_h_d_) * *dt;
/* SOURCE fqshrftb.for:6618 */
/*<       b=b0+h*db >*/
    *b = static_cast<double>(b0) + static_cast<double>(feq_gen_h_d_) * *db;
/* SOURCE fqshrftb.for:6619 */
/*<       alp=alp0+h*dalp >*/
    *alp = static_cast<double>(alp0) + static_cast<double>(feq_gen_h_d_) * *dalp;
/* SOURCE fqshrftb.for:6620 */
/*<       a=a0+hh*(t+t0) >*/
    *a = static_cast<double>(a0) + static_cast<double>(hh) * (static_cast<double>(*t) + t0);
/* SOURCE fqshrftb.for:6621 */
/*<       j=j0+hh*(a+a0-h*(t-t0)/6.) >*/
    *j = static_cast<double>(j0) + static_cast<double>(hh) * (static_cast<double>(static_cast<double>(*a) + a0) - static_cast<double>(static_cast<double>(feq_gen_h_d_) * (static_cast<double>(*t) - t0)) / (float)6.);
/* SOURCE fqshrftb.for:6622 */
/*<       k=k0+h*dk >*/
    *k = static_cast<double>(k0) + static_cast<double>(feq_gen_h_d_) * *dk;
/* SOURCE fqshrftb.for:6623 */
/*<       dk=2.*k*dk >*/
    *dk = static_cast<double>(static_cast<double>(*k) * (float)2.) * *dk;
/* SOURCE fqshrftb.for:6624 */
/*<       k=k*k >*/
    *k *= *k;
/* SOURCE fqshrftb.for:6626 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:6627 */
/*<       end >*/
} /* xlktal_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:6631 */
/*<       subroutinelktqc(adrs,ya,qc) >*/
/* Subroutine */ int lktqc_(integer *adrs, real *ya, real *qc)
{
    /* Initialized data */

    static integer vtype[35] = { 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
	    0,0,1,0,0,0,0,0,0,1,0,0,1 };

    /* Format strings */
    static char fmt_2000[] = "(\0020\002,\002*WRN:35* X-SECTION BELOW RANGE \
IN LKTQC\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,f\
10.3/,1x,\002 TIME           = \002,f10.0,/,1x,\002 DEPTH          = \002,f1\
0.2)";
    static char fmt_2010[] = "(\0020\002,\002*WRN:36* X-SECTION ABOVE RANGE \
IN LKTQC\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,f\
10.3/,1x,\002 TIME           = \002,f10.0,/,1x,\002 DEPTH          = \002,f1\
0.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double log(doublereal), exp(doublereal);

    /* Local variables */
    integer l;
    real p, y, y0, y1;
    integer ha, la;
    char cs[16];
    real dy, qc0, qc1;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__901 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__902 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth lookup critical flow. */
/* SOURCE fqshrftb.for:6639 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:6642 */
/*<       integeradrs >*/
/* SOURCE fqshrftb.for:6643 */
/*<       realqc,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - Address of function table */
/*     YA     - maximum depth in a cross section */
/*     QC     - Critical flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:6651 */
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
/* INCLUDE fqshrftb.for:6652 */
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
/* INCLUDE fqshrftb.for:6653 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE fqshrftb.for:6654 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:6657 */
/*<       integervtype(35) >*/
/* SOURCE fqshrftb.for:6658 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:6661 */
/*<       integerha,l,la,type,xoff >*/
/* SOURCE fqshrftb.for:6662 */
/*<       realdy,p,qc0,qc1,y,y0,y1 >*/
/* SOURCE fqshrftb.for:6663 */
/*<       charactercs*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:6666 */
/*<       intrinsicexp,log >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:6669 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:6670 */
/*<       externalget_string_from_ft,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:6673 */
/*<       datavtype/11*0,1,9*0,1,0,0,1,4*0,0,0,1,0,0,1/ >*/
/* SOURCE fqshrftb.for:6676 */
/*<  2000  >*/
/* L2000: */
/* SOURCE fqshrftb.for:6681 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLOOKY */
/* SOURCE fqshrftb.for:6691 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE fqshrftb.for:6692 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fqshrftb.for:6693 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE fqshrftb.for:6694 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE fqshrftb.for:6696 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fqshrftb.for:6697 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:6698 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE fqshrftb.for:6699 */
/*<       callxstype(lout,vtype,adrs) >*/
	xstype_(&xscom_1.lout, vtype, adrs);
/* SOURCE fqshrftb.for:6701 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrftb.for:6702 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6704 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE fqshrftb.for:6706 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE fqshrftb.for:6707 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:6708 */
/*<       write(lout,2010)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__901.ciunit = xscom_1.lout;
	    s_wsfe(&feq_gen_io_d__901);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:6710 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE fqshrftb.for:6711 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE fqshrftb.for:6712 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:6713 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:6714 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrftb.for:6715 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE fqshrftb.for:6716 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE fqshrftb.for:6717 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrftb.for:6718 */
/*<       endif >*/
	    }
/* SOURCE fqshrftb.for:6719 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6720 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE fqshrftb.for:6722 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE fqshrftb.for:6723 */
/*<       cs=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_1 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:6724 */
/*<       write(lout,2000)cs,ftab(adrs+4),time,y >*/
	    feq_gen_io_d__902.ciunit = xscom_1.lout;
	    s_wsfe(&feq_gen_io_d__902);
	    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:6726 */
/*<       l=la >*/
	    l = la;
/* SOURCE fqshrftb.for:6727 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE fqshrftb.for:6728 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE fqshrftb.for:6729 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:6730 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrftb.for:6731 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE fqshrftb.for:6732 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE fqshrftb.for:6733 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6734 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrftb.for:6741 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
    // Directly verified against both FEQ and FEQUTL releases.
    feq_interpolate_critical_flow_interval(l,l+xoff,*ya,qc);
    return 0;
/* SOURCE fqshrftb.for:6770 */
/*<       end >*/
} /* lktqc_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:6774 */
/*<       subroutinexsecin(in,stdout,mlft,ntab,output,eflag,ftp,type) >*/
/* Subroutine */ int xsecin_(integer *in, integer *stdout, integer *mlft, 
	integer *ntab, integer *output, integer *eflag, integer *ftp, integer 
	*feq_gen_type_d_)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;
    static integer form[35] = { 2,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,2,3,4,
	    5,6,0,0,0,0,7,8,9,10,11,12 };
    static integer hdlen[35] = { 80,0,0,0,0,0,0,0,0,0,0,92,0,0,0,0,0,0,0,80,
	    80,92,80,92,112,0,0,0,0,76,89,122,116,129,162 };
    static char feq_gen_inform_d_[80*12+1] = "(F10.0,F10.0,2E13.0,F10.0)             \
                                         (F10.0,F10.0,2E13.0,F10.0,E13.0)   \
                                             (F10.0,F10.0,2E13.0,F10.0,E13.0\
,F10.0,E13.0)                                    (F10.0,F10.0,2E13.0,3F10.0)\
                                                     (F10.0,F10.0,2E13.0,F10\
.0,E13.0,2F10.0)                                         (F10.0,F10.0,2E13.0\
,F10.0,E13.0,F10.0,E13.0,2F10.0)                             (F10.0,F10.0,2E\
13.0,F10.0,2f10.0)                                               (F10.0,F10.\
0,2E13.0,F10.0,E13.0,2f10.0)                                         (F10.0,\
F10.0,2E13.0,F10.0,E13.0,F10.0,E13.0,3f10.0)                             (F1\
0.0,F10.0,2E13.0,3F10.0,4f10.0)                                             \
 (F10.0,F10.0,2E13.0,F10.0,E13.0,2F10.0,4f10.0)                             \
     (F10.0,F10.0,2E13.0,F10.0,E13.0,F10.0,E13.0,2F10.0,5f10.0)             \
         ";
    static char prform[80*12+1] = "(F10.5,F10.3,1P2E13.5,0PF10.4)           \
                                       (F10.5,F10.3,1P2E13.5,0PF10.4,1PE13.5\
)                                          (F10.5,F10.3,1P2E13.5,0PF10.4,1PE\
13.5,0PF10.4,1PE13.5)                          (F10.5,F10.3,1P2E13.5,0P3F10.\
4)                                                 (F10.5,F10.3,1P2E13.5,0PF\
10.4,1PE13.5,0P2F10.4)                                 (F10.5,F10.3,1P2E13.5\
,0PF10.4,1PE13.5,0PF10.4,1PE13.5,0P2F10.4)                 (F10.5,F10.3,1P2E\
13.5,0PF10.4,2(1pe10.4e1))                                     (F10.5,F10.3,\
1P2E13.5,0PF10.4,1PE13.5,2(1pe10.4e1))                             (F10.5,F1\
0.3,1P2E13.5,0PF10.4,1PE13.5,0PF10.4,1PE13.5,3(1pe10.4e1))             (F10.\
5,F10.3,1P2E13.5,0P3F10.4,4(1pe10.4e1))                                    (\
F10.5,F10.3,1P2E13.5,0PF10.4,1PE13.5,0P2F10.4,4(1pe10.4e1))                 \
   (F10.5,F10.3,1P2E13.5,0PF10.4,1PE13.5,0PF10.4,1PE13.5,0P2F10.4,5(1pe10.4e\
1))    ";

    /* Format strings */
    static char fmt_1[] = "(a)";
    static char fmt_2[] = "(5x,a8,7x,a8,8x,a8,9x,a8,7x,a8)";
    static char fmt_39[] = "(8x,e12.0)";
    static char fmt_40[] = "(8x,e12.0,7x,a16,9x,f15.0,10x,f15.0)";
    static char fmt_42[] = "(10x,e12.0,7x,f10.0,5x,f10.0,5x,f5.0,6x,f10.0)";
    static char fmt_41[] = "(\002 \002,\002Station=\002,f10.3,\002 Gisid=\
\002,a16,\002 Easting=\002,f15.3,\002 Northing=\002,f15.3)";
    static char fmt_43[] = "(\002 \002,\002Elevation=\002,f10.2,\002 Cutoff\
=\002,f10.2,\002 Ext=\002,f10.2,\002 Fac=\002,f5.3,\002 Slot=\002,f10.3)";
    static char fmt_46[] = "(/,\002 *WRN:09* Conveyance nonincreasing at dep\
th=\002,f8.3)";
    static char fmt_48[] = "(/,\002 *WRN:11* Drop of\002,f4.0,\002 per cent \
in conveyance\002,\002 at depth=\002,f8.3)";
    static char fmt_76[] = "(/,\002 *BUG:XXX* Type=\002,i3,\002 has zero off\
set in XSECIN.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi()
	    ;
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    doublereal northing;
    integer j;
    extern /* Subroutine */ int feq_gen_put_string_in_ft_d_(integer *, char *, ftnlen);
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer it;
    real feq_gen_slot_depth_d_, fac;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    real ext;
    integer out;
    extern /* Subroutine */ int feq_gen_chk_vdatum_unitsys_d_(integer *, char *, char *
	    , char *, ftnlen, ftnlen, ftnlen);
    char head[196];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real elem[15];
    char line[196];
    real elev;
    integer xoff;
    real drop, stat;
    char zone[8];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_put_dp_in_ft_d_(integer *, doublereal *);
    integer headl;
    char tabid[16], hgrid[8], gisid[16];
    real khold;
    char basis[8];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    integer formid;
    extern /* Subroutine */ int feq_gen_put_chr8_in_ft_d_(integer *, char *, ftnlen);
    real cutoff;
    integer ftpold;
    char vdatum[8];
    extern /* Subroutine */ int extrap_(integer *, integer *, integer *, 
	    integer *, real *, integer *);
    doublereal easting;
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__926 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__932 = { 0, 0, 0, fmt_41, 0 };
    static cilist feq_gen_io_d__938 = { 0, 0, 0, fmt_43, 0 };
    static cilist feq_gen_io_d__947 = { 0, 0, 0, fmt_48, 0 };
    static cilist feq_gen_io_d__948 = { 0, 0, 0, fmt_46, 0 };
    static cilist feq_gen_io_d__949 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input a cross-section table. */
/* SOURCE fqshrftb.for:6781 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:6783 */
/*<       integereflag,ftp,in,stdout,mlft,ntab,output,type >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     MLFT   - maximum length of FTAB/ITAB */
/*     NTAB   - table number */
/*     OUTPUT - output level for diagnostic work */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     FTP    - next open location in the function table storage */
/*     TYPE   - table type */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrftb.for:6796 */
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
/* INCLUDE fqshrftb.for:6797 */
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
/* INCLUDE fqshrftb.for:6798 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE fqshrftb.for:6801 */
/*<       integerform(35),hdlen(35) >*/
/* SOURCE fqshrftb.for:6802 */
/*<       characterinform(12)*80,prform(12)*80 >*/
/* SOURCE fqshrftb.for:6803 */
/*<       saveform,hdlen,inform,prform >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:6806 */
/*<       integerformid,ftpold,headl,it,j,out,xoff >*/
/* SOURCE fqshrftb.for:6807 */
/*<       realcutoff,drop,elem(15),elev,ext,fac,khold,stat,slot_depth >*/
/* SOURCE fqshrftb.for:6809 */
/*<       real*8easting,northing,dnull >*/
/* SOURCE fqshrftb.for:6810 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrftb.for:6814 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrftb.for:6817 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrftb.for:6818 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE fqshrftb.for:6774 */
/*<       integer feq_len_trim >*/
/* SOURCE fqshrftb.for:6774 */
/*<       external feq_len_trim >*/
/* SOURCE fqshrftb.for:6823 */
/*<       datadnull/-33d6/ >*/
/* SOURCE fqshrftb.for:6824 */
/*<        >*/
/* SOURCE fqshrftb.for:6827 */
/*<        >*/
/* SOURCE fqshrftb.for:6842 */
/*<        >*/
/* SOURCE fqshrftb.for:6859 */
/*<     1 format(a) >*/
/* L1: */
/* SOURCE fqshrftb.for:6860 */
/*<     2 format(5x,a8,7x,a8,8x,a8,9x,a8,7x,a8) >*/
/* L2: */
/* SOURCE fqshrftb.for:6861 */
/*<    39 format(8x,e12.0) >*/
/* L39: */
/* SOURCE fqshrftb.for:6862 */
/*<    40 format(8x,e12.0,7x,a16,9x,f15.0,10x,f15.0) >*/
/* L40: */
/* SOURCE fqshrftb.for:6863 */
/*<    42 format(10x,e12.0,7x,f10.0,5x,f10.0,5x,f5.0,6x,f10.0) >*/
/* L42: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:6866 */
/*<    41  >*/
/* L41: */
/* SOURCE fqshrftb.for:6868 */
/*<    43  >*/
/* L43: */
/* SOURCE fqshrftb.for:6870 */
/*<    46 format(/,' *WRN:09* Conveyance nonincreasing at depth=',f8.3) >*/
/* L46: */
/* SOURCE fqshrftb.for:6871 */
/*<    48  >*/
/* L48: */
/* SOURCE fqshrftb.for:6873 */
/*<    76 format(/,' *BUG:XXX* Type=',i3,' has zero offset in XSECIN.') >*/
/* L76: */
/* *********************************************************************** */
/*     The values in each of the 14 tables are in the following */
/*     order in the tables.  This is also the order in which the */
/*     values are stored in FTAB. */
/*              Cross Section Function Table Type */
/*     Order   1   12   20   21   22   23   24   25      30      31      32      33      34      35 */
/*       1     Y    Y    Y    Y    Y    Y    Y    Y       Y       Y       Y       Y       Y       Y */
/*       2     T    T    T    T    T    T    T    T       T       T       T       T       T       T */
/*       3     A    A    A    A    A    A    A    A       A       A       A       A       A       A */
/*       4    KH   KH   KH   KH   KH   KH   KH   KH      KH      KH      KH      KH      KH      KH */
/*       5     B    B    B    B    B    B    B    B       B       B       B       B       B       B */
/*       6     J    J    -    J    J   MA    J    J  dkh/dy       J       J      MA       J       J */
/*       7     -  ALP    -    -  ALP   MQ   MA  ALP   db/dy  dkh/dy     ALP      MQ      MA     ALP */
/*       8     -   QC    -    -   QC    -   MQ   QC       -   db/dy      QC  dkh/dy      MQ      QC */
/*       9     -    -    -    -    -    -    -   MA       -       -  dkh/dy   db/dy  dkh/dy      MA */
/*      10     -    -    -    -    -    -    -   MQ       -       -   db/dy  dma/dy   db/dy      MQ */
/*      11     -    -    -    -    -    -    -    -       -       - dalp/dy   dmq/dy  dma/dy  dkh/dy */
/*      12     -    -    -    -    -    -    -    -       -       -       -       -  dmq/dy    db/dy */
/*      13     -    -    -    -    -    -    -    -       -       -       -       -       -   dma/dy */
/*      14     -    -    -    -    -    -    -    -       -       -       -       -       -   dmq/dy */
/*      15     -    -    -    -    -    -    -    -       -       -       -       -       -  dalp/dy */
/*      In this table Y= maximum depth in the section; T= top */
/*      width of the wetted area; A= the wetted area;, KH= */
/*      square root of conveaycne; B= momentum flux coefficient; */
/*      J= first moment of area about the water surface; */
/*      ALP= kinetic energy flux coefficient; QC= critical flow; */
/*      MA= weight factor to convert A to the water volume per */
/*      unit length along the distance axis; and MQ= the weight */
/*      factor to convert flowrate(Q) to momentum per unit */
/*      length along the distance axis.  Note: Table types 1 and */
/*      12 are the same as types 21 and 22.  Types 1 and 12 are */
/*      being phased out.  They are given the new type numbers when */
/*      they are encountered during input. */
/*     Set defaults for the grid, datum, and units */
/* SOURCE fqshrftb.for:6910 */
/*<       zone='NONE' >*/
    s_copy(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:6911 */
/*<       hgrid='NONE' >*/
    s_copy(hgrid, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:6912 */
/*<       vdatum='NONE' >*/
    s_copy(vdatum, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:6913 */
/*<       unitsys='NONE' >*/
    s_copy(unitsys, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:6914 */
/*<       basis='NONE' >*/
    s_copy(basis, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fqshrftb.for:6916 */
/*<       out=output >*/
    out = *output;
/* SOURCE fqshrftb.for:6917 */
/*<       if(type.lt.0)then >*/
    if (*feq_gen_type_d_ < 0) {
/* SOURCE fqshrftb.for:6918 */
/*<       out=0 >*/
	out = 0;
/* SOURCE fqshrftb.for:6919 */
/*<       type=-type >*/
	*feq_gen_type_d_ = -(*feq_gen_type_d_);
/* SOURCE fqshrftb.for:6920 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6921 */
/*<       formid=form(type) >*/
    formid = form[*feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:6922 */
/*<       headl=hdlen(type) >*/
    headl = hdlen[*feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:6923 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[*feq_gen_type_d_ - 1];
/* SOURCE fqshrftb.for:6924 */
/*<       if(xoff.eq.0)then >*/
    if (xoff == 0) {
/* SOURCE fqshrftb.for:6925 */
/*<       write(stdout,76)type >*/
	feq_gen_io_d__926.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__926);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_type_d_), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrftb.for:6926 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:6927 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6929 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)196);
/* SOURCE fqshrftb.for:6932 */
/*<       if(line(26:31).eq.'Interp')then >*/
    if (s_cmp(line + 25, const_cast<char*>("Interp"), (ftnlen)6, (ftnlen)6) == 0) {
/* SOURCE fqshrftb.for:6933 */
/*<       read(line,39,err=991)stat >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 196;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_39;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:6934 */
/*<       gisid=' ' >*/
	s_copy(gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE fqshrftb.for:6935 */
/*<       easting=0.d0 >*/
	easting = 0.;
/* SOURCE fqshrftb.for:6936 */
/*<       northing=0.d0 >*/
	northing = 0.;
/* SOURCE fqshrftb.for:6937 */
/*<       elseif(line(1:4)=='ZONE')then >*/
    } else if (s_cmp(line, const_cast<char*>("ZONE"), (ftnlen)4, (ftnlen)4) == 0) {
/*       We have a line of information about horizontal grid, vertical datum, and units */
/* SOURCE fqshrftb.for:6939 */
/*<       read(line,2,err=991)zone,hgrid,vdatum,unitsys,basis >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 196;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_2;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:6940 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)196);
/* SOURCE fqshrftb.for:6943 */
/*<       read(line,40,err=991)stat,gisid,easting,northing >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 196;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_40;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:6944 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:6945 */
/*<       read(line,40,err=991)stat,gisid,easting,northing >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 196;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_40;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fqshrftb.for:6946 */
/*<       endif >*/
    }
/*     If zone = NA, then the cross-section table has no meaning */
/*     for location.  This could be the case for a prismatic channel */
/*     in which a single cross section table is reused at many nodes */
/*     on a branch.  Or it might be a case in which the user does not */
/*     want to supply the information. */
/* SOURCE fqshrftb.for:6954 */
/*<       if(zone=='NA')then >*/
    if (s_cmp(zone, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) == 0) {
/* SOURCE fqshrftb.for:6955 */
/*<       easting=dnull >*/
	easting = dnull;
/* SOURCE fqshrftb.for:6956 */
/*<       northing=dnull >*/
	northing = dnull;
/* SOURCE fqshrftb.for:6957 */
/*<       ft_loc_status(ntab)='N' >*/
	*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*ntab - 1] = 'N';
/* SOURCE fqshrftb.for:6958 */
/*<       else >*/
    } else {
/*       Check if the easting value was blank.  If so, set both */
/*       to the standard null value. */
/* SOURCE fqshrftb.for:6962 */
/*<       ft_loc_status(ntab)='I' >*/
	*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*ntab - 1] = 'I';
/* SOURCE fqshrftb.for:6963 */
/*<       if(line(53:67)==' ')then >*/
	if (s_cmp(line + 52, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1) == 0) {
/*         No value given for easting.  Both values assumed missing. */
/* SOURCE fqshrftb.for:6965 */
/*<       easting=dnull >*/
	    easting = dnull;
/* SOURCE fqshrftb.for:6966 */
/*<       northing=dnull >*/
	    northing = dnull;
/* SOURCE fqshrftb.for:6967 */
/*<       ft_loc_status(ntab)='M' >*/
	    *(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[*ntab - 1] = 'M';
/* SOURCE fqshrftb.for:6968 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:6969 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:6972 */
/*<       if(out.gt.0)write(stdout,41)stat,gisid,easting,northing >*/
    if (out > 0) {
	feq_gen_io_d__932.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__932);
	do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
/* SOURCE fqshrftb.for:6974 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)196);
/* SOURCE fqshrftb.for:6977 */
/*<       read(line,42,err=991)elev,cutoff,ext,fac,slot_depth >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_42;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cutoff, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&ext, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&fac, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_slot_depth_d_, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*     CHECK FOR ZERO VALUE OF FAC AND SET DEFAULT OF UNITY */
/* SOURCE fqshrftb.for:6981 */
/*<       if(fac.eq.0.0)fac=1.0 >*/
    if (fac == (float)0.) {
	fac = (float)1.;
    }
/* SOURCE fqshrftb.for:6982 */
/*<       if(out.gt.0)write(stdout,43)elev,cutoff,ext,fac,slot_depth >*/
    if (out > 0) {
	feq_gen_io_d__938.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__938);
	do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&cutoff, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ext, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&fac, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_slot_depth_d_, (ftnlen)sizeof(real));
	e_wsfe();
    }
/*     CHANGE THE FACTOR TO APPLY TO THE SQRT OF CONVEYANCE */
/* SOURCE fqshrftb.for:6986 */
/*<       fac=sqrt(fac) >*/
    fac = sqrt(fac);
/* SOURCE fqshrftb.for:6988 */
/*<       if((ftp+xoff).ge.mlft)callkil(10,ftp,eflag) >*/
    if (*ftp + xoff >= *mlft) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/* SOURCE fqshrftb.for:6992 */
/*<       itab(ftp+1)=ntab >*/
    itab[*ftp + 1] = *ntab;
/* SOURCE fqshrftb.for:6993 */
/*<       itab(ftp+2)=abs(type) >*/
    itab[*ftp + 2] = abs(*feq_gen_type_d_);
/*     SET INITIAL ADDRESS FOR TABLE LOOK UP */
/* SOURCE fqshrftb.for:6997 */
/*<       itab(ftp+3)=ftp+xtioff >*/
    itab[*ftp + 3] = *ftp + 32;
/* SOURCE fqshrftb.for:6998 */
/*<       ftab(ftp+4)=stat >*/
    ftab[*ftp + 4] = stat;
/* SOURCE fqshrftb.for:6999 */
/*<       ftab(ftp+5)=elev >*/
    ftab[*ftp + 5] = elev;
/* SOURCE fqshrftb.for:7000 */
/*<       ftab(ftp+7)=slot_depth >*/
    ftab[*ftp + 7] = feq_gen_slot_depth_d_;
/* SOURCE fqshrftb.for:7001 */
/*<       callput_dp_in_ft(ftp+8,easting) >*/
    feq_gen_i_d_1 = *ftp + 8;
    feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, &easting);
/* SOURCE fqshrftb.for:7002 */
/*<       callput_dp_in_ft(ftp+10,northing) >*/
    feq_gen_i_d_1 = *ftp + 10;
    feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, &northing);
/* SOURCE fqshrftb.for:7003 */
/*<       callput_string_in_ft(ftp+12,gisid) >*/
    feq_gen_i_d_1 = *ftp + 12;
    feq_gen_put_string_in_ft_d_(&feq_gen_i_d_1, gisid, (ftnlen)16);
/* SOURCE fqshrftb.for:7004 */
/*<       tabid=get_tabid(ntab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, ntab);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:7005 */
/*<       callput_string_in_ft(ftp+16,tabid) >*/
    feq_gen_i_d_1 = *ftp + 16;
    feq_gen_put_string_in_ft_d_(&feq_gen_i_d_1, tabid, (ftnlen)16);
/*     Set the source flag to input source */
/* SOURCE fqshrftb.for:7009 */
/*<       itab(ftp+20)=0 >*/
    itab[*ftp + 20] = 0;
/*     Set the offset value to the start of the extra derivatives for the */
/*     upgraded tables. */
/* SOURCE fqshrftb.for:7013 */
/*<       if(type.le.25)then >*/
    if (*feq_gen_type_d_ <= 25) {
/* SOURCE fqshrftb.for:7014 */
/*<       itab(ftp+21)=0 >*/
	itab[*ftp + 21] = 0;
/* SOURCE fqshrftb.for:7015 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:7016 */
/*<       itab(ftp+21)=offvec(type-10) >*/
	itab[*ftp + 21] = offcom_1.offvec[*feq_gen_type_d_ - 11];
/* SOURCE fqshrftb.for:7017 */
/*<       endif >*/
    }
/*     Store the zone, grid, datum, unitsys, and basis information */
/* SOURCE fqshrftb.for:7020 */
/*<       callput_chr8_in_ft(ftp+22,zone) >*/
    feq_gen_i_d_1 = *ftp + 22;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, zone, (ftnlen)8);
/* SOURCE fqshrftb.for:7021 */
/*<       callput_chr8_in_ft(ftp+24,hgrid) >*/
    feq_gen_i_d_1 = *ftp + 24;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, hgrid, (ftnlen)8);
/* SOURCE fqshrftb.for:7022 */
/*<       callput_chr8_in_ft(ftp+26,vdatum) >*/
    feq_gen_i_d_1 = *ftp + 26;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, vdatum, (ftnlen)8);
/* SOURCE fqshrftb.for:7023 */
/*<       callput_chr8_in_ft(ftp+28,unitsys) >*/
    feq_gen_i_d_1 = *ftp + 28;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, unitsys, (ftnlen)8);
/* SOURCE fqshrftb.for:7024 */
/*<       callput_chr8_in_ft(ftp+30,basis) >*/
    feq_gen_i_d_1 = *ftp + 30;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, basis, (ftnlen)8);
/* SOURCE fqshrftb.for:7027 */
/*<       ftpold=ftp >*/
    ftpold = *ftp;
/*     POINT TO FIRST DEPTH ENTRY IN THE TABLE */
/* SOURCE fqshrftb.for:7029 */
/*<       ftp=ftp+xtioff >*/
    *ftp += 32;
/* SOURCE fqshrftb.for:7031 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)196);
/* SOURCE fqshrftb.for:7034 */
/*<       read(line,1)head(1:headl) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, headl);
    e_rsfi();
/* SOURCE fqshrftb.for:7035 */
/*<       if(out.gt.0)write(stdout,'(A)')head(1:headl) >*/
    if (out > 0) {
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, head, headl);
	e_wsfe();
    }
/* SOURCE fqshrftb.for:7037 */
/*<        >*/
    feq_gen_chk_vdatum_unitsys_d_(stdout, vdatum, unitsys, const_cast<char*>(" during input of a cross-\
section table"), (ftnlen)8, (ftnlen)8, (ftnlen)38);
/*       SET OLD VALUES */
/* SOURCE fqshrftb.for:7042 */
/*<       khold=-1. >*/
    khold = (float)-1.;
/* SOURCE fqshrftb.for:7044 */
/*<  1000 continue >*/
L1000:
/* SOURCE fqshrftb.for:7045 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)196);
/* SOURCE fqshrftb.for:7048 */
/*<       read(line,inform(formid),err=991)(elem(j),j=1,xoff) >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = feq::format_text(feq_gen_inform_d_ + (formid - 1) * 80, 80);
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_2 = xoff;
    for (j = 1; j <= feq_gen_i_d_2; ++j) {
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elem[j - 1], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*       CHECK FOR THE END OF THE TABLE */
/* SOURCE fqshrftb.for:7051 */
/*<       if(elem(1).lt.0.0)goto1500 >*/
    if (elem[0] < (float)0.) {
	goto L1500;
    }
/*       SUPPORT THE CUTOFF OPTION.  NOT USED RECENTLY. */
/* SOURCE fqshrftb.for:7054 */
/*<       if(elem(1).lt.cutoff)goto1000 >*/
    if (elem[0] < cutoff) {
	goto L1000;
    }
/*       APPLY THE FACTOR ADJUSTMENT TO THE SQRT OF CONVEYANCE and to */
/*       dkh/dy if   30 =type<= 35 */
/* SOURCE fqshrftb.for:7059 */
/*<       elem(4)=elem(4)/fac >*/
    elem[3] /= fac;
/* SOURCE fqshrftb.for:7060 */
/*<       if(type.ge.30.and.type.le.35)then >*/
    if (*feq_gen_type_d_ >= 30 && *feq_gen_type_d_ <= 35) {
/*         dkh/dy is always stored first after the last item for */
/*         the corresponding type: 20-25.  Thus we can compute the offset */
/*         of dkh/dy in the elem vector. */
/* SOURCE fqshrftb.for:7064 */
/*<       it=offvec(type-10)+1 >*/
	it = offcom_1.offvec[*feq_gen_type_d_ - 11] + 1;
/* SOURCE fqshrftb.for:7065 */
/*<       elem(it)=elem(it)/fac >*/
	elem[it - 1] /= fac;
/* SOURCE fqshrftb.for:7066 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:7069 */
/*<       if(out.gt.0)then >*/
    if (out > 0) {
/* SOURCE fqshrftb.for:7070 */
/*<       write(stdout,prform(formid))(elem(j),j=1,xoff) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = feq::format_text(prform + (formid - 1) * 80, 80);
	s_wsfe(&feq_gen_ci_d_1);
	feq_gen_i_d_1 = xoff;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&elem[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE fqshrftb.for:7071 */
/*<       endif >*/
    }
/*       CHECK FOR ROOM IN FTAB */
/* SOURCE fqshrftb.for:7074 */
/*<       if((ftp+xoff).ge.mlft)callkil(10,ftp,eflag) >*/
    if (*ftp + xoff >= *mlft) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/*       STORE IN FTAB */
/* SOURCE fqshrftb.for:7079 */
/*<       do1010j=1,xoff >*/
    feq_gen_i_d_1 = xoff;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fqshrftb.for:7080 */
/*<       ftab(ftp+j-1)=elem(j) >*/
	ftab[*ftp + j - 1] = elem[j - 1];
/* SOURCE fqshrftb.for:7081 */
/*<  1010 continue >*/
/* L1010: */
    }
/* SOURCE fqshrftb.for:7082 */
/*<       ftp=ftp+xoff >*/
    *ftp += xoff;
/*       CHECK FOR NONINCREASING CONVEYANCE */
/* SOURCE fqshrftb.for:7086 */
/*<       if(elem(4).le.khold)then >*/
    if (elem[3] <= khold) {
/* SOURCE fqshrftb.for:7087 */
/*<       if(khold.gt.0.0.and.elem(2).gt.0.1)then >*/
	if (khold > (float)0. && elem[1] > (float).1) {
/* SOURCE fqshrftb.for:7088 */
/*<       drop=-(elem(4)**2-khold**2)/khold**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = elem[3];
/* Computing 2nd power */
	    feq_gen_r_d_2 = khold;
/* Computing 2nd power */
	    feq_gen_r_d_3 = khold;
	    drop = static_cast<double>(-(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) - static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3);
/* SOURCE fqshrftb.for:7089 */
/*<       if(drop.gt.0.005)write(stdout,48)drop*100.,elem(1) >*/
	    if (drop > (float).005) {
		feq_gen_io_d__947.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__947);
		feq_gen_r_d_1 = static_cast<double>(drop) * (float)100.;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&elem[0], (ftnlen)sizeof(real));
		e_wsfe();
	    }
/* SOURCE fqshrftb.for:7090 */
/*<       else >*/
	} else {
/* SOURCE fqshrftb.for:7091 */
/*<       write(stdout,46)elem(1) >*/
	    feq_gen_io_d__948.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__948);
	    do_fio(&feq_gen_c_d_1, (char *)&elem[0], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fqshrftb.for:7092 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:7093 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:7094 */
/*<       khold=elem(4) >*/
    khold = elem[3];
/* SOURCE fqshrftb.for:7096 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fqshrftb.for:7097 */
/*<  1500 continue >*/
L1500:
/*     SAVE THE UNEXTRAPOLATED MAXIMUM ARGUMENT IN THE TABLE */
/*     FOR CHECKING THE MAXIMUM RESULTS. */
/* SOURCE fqshrftb.for:7102 */
/*<       ftab(ftpold+6)=ftab(ftp-xoff) >*/
    ftab[ftpold + 6] = ftab[*ftp - xoff];
/*     CALL EXTRAPOLATION IF NEEDED */
/* SOURCE fqshrftb.for:7106 */
/*<       if(ext.ne.0.0)callextrap(type,xoff,mlft,eflag,ext,ftp) >*/
    if (ext != (float)0.) {
	extrap_(feq_gen_type_d_, &xoff, mlft, eflag, &ext, ftp);
    }
/*     STORE THE HIGH ADDRESS FOR RUN TIME CHECKING */
/* SOURCE fqshrftb.for:7112 */
/*<       itab(ftpold)=ftp-xoff >*/
    itab[ftpold] = *ftp - xoff;
/* SOURCE fqshrftb.for:7113 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:7115 */
/*<   991 continue >*/
L991:
/* SOURCE fqshrftb.for:7116 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__949.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__949);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE fqshrftb.for:7117 */
/*<       it=feq_len_trim(line) >*/
    it = feq_gen_feq_len_trim_d_(line, (ftnlen)196);
/* SOURCE fqshrftb.for:7118 */
/*<       write(stdout,'(A)')line(1:it) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE fqshrftb.for:7119 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrftb.for:7120 */
/*<       end >*/
    return 0;
} /* xsecin_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrftb.for:7124 */
/*<       subroutinexstype(stdout,vtype,adrs) >*/
/* Subroutine */ int xstype_(integer *stdout, integer *feq_storage_vtype, integer *adrs)
{
    /* Format strings */
    static char fmt_50[] = "(\0020*ERR:195* Data deficiency in Tabid= \002\
,a,\002 Valid Types:\002)";
    static char fmt_52[] = "(11x,\002Type=\002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_;
    char cs[16];
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__951 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__953 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Dump valid list of cross section table types. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:7131 */
/*<       integerstdout,adrs >*/
/* SOURCE fqshrftb.for:7132 */
/*<       integervtype(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     VTYPE  - list of valid cross section table types */
/*     ADRS    - address of the cross section table */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:7140 */
/*<       integeri >*/
/* SOURCE fqshrftb.for:7141 */
/*<       charactercs*16 >*/
/*     Called program units */
/* SOURCE fqshrftb.for:7144 */
/*<       character*16get_string_from_ft >*/
/* SOURCE fqshrftb.for:7145 */
/*<       externalget_string_from_ft >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrftb.for:7148 */
/*<    50 format('0*ERR:195* Data deficiency in Tabid= ',a,' Valid Types:') >*/
/* SOURCE fqshrftb.for:7149 */
/*<    52 format(11x,'Type=',i5) >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:7151 */
/*<       cs=get_string_from_ft(adrs+16) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> vtype(feq_storage_vtype, 1);

    /* Function Body */
/* L50: */
/* L52: */
    feq_gen_i_d_1 = *adrs + 16;
    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
    s_copy(cs, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fqshrftb.for:7152 */
/*<       write(stdout,50)cs >*/
    feq_gen_io_d__951.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__951);
    do_fio(&feq_gen_c_d_1, cs, (ftnlen)16);
    e_wsfe();
/* SOURCE fqshrftb.for:7153 */
/*<       do100i=1,35 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 35; ++feq_gen_i_d_) {
/* SOURCE fqshrftb.for:7154 */
/*<       if(vtype(i).gt.0)then >*/
	if (vtype[feq_gen_i_d_] > 0) {
/* SOURCE fqshrftb.for:7155 */
/*<       write(stdout,52)i >*/
	    feq_gen_io_d__953.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__953);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE fqshrftb.for:7156 */
/*<       endif >*/
	}
/* SOURCE fqshrftb.for:7157 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE fqshrftb.for:7158 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:7159 */
/*<       end >*/
} /* xstype_ */




/* SOURCE fqshrftb.for:7163 */
/*<       subroutinetstsow(h1,h4,hg,h1fw,h4fw,h4sw,flag) >*/
/* Subroutine */ int tstsow_(real *h1, real *h4, real *hg, real *h1fw, real *
	h4fw, real *h4sw, integer *feq_gen_flag_d_)
{
    real h1sw, h4star;

/*     + + + PURPOSE + + + */
/*     Test for being in the SO flow region that exists above the */
/*     the SW flow region.  On entry H1 is known to be between */
/*     H1FW and HG. */
/* SOURCE fqshrftb.for:7172 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrftb.for:7174 */
/*<       integerflag >*/
/* SOURCE fqshrftb.for:7175 */
/*<       realh1,h1fw,h4,h4fw,h4sw,hg >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H1     - head at section 1 */
/*     H4     - head at section 4 */
/*     HG     - underflow gate opening */
/*     H1FW   - head at section 1 at the limit of FW flow */
/*     H4FW   - head at section 4 at the limit of FW flow */
/*     H4SW   - head at section 4 when the head at section 1 is */
/*              at the mid-point of the special SO region */
/*     FLAG   - flag for being in the special SO region */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrftb.for:7188 */
/*<       realh1sw,h4star >*/
/* *********************************************************************** */
/* SOURCE fqshrftb.for:7190 */
/*<       h1sw=0.5*(hg+h1fw) >*/
    h1sw = static_cast<double>((static_cast<double>(*hg) + *h1fw)) * (float).5;
/* SOURCE fqshrftb.for:7192 */
/*<       if(h1.le.h1sw)then >*/
    if (*h1 <= h1sw) {
/* SOURCE fqshrftb.for:7193 */
/*<       h4star=hg+(h1-hg)*(h4sw-hg)/(h1sw-hg) >*/
	h4star = static_cast<double>(*hg) + static_cast<double>(static_cast<double>((static_cast<double>(*h1) - *hg)) * (static_cast<double>(*h4sw) - *hg)) / (static_cast<double>(h1sw) - *hg);
/* SOURCE fqshrftb.for:7194 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:7195 */
/*<       h4star=h4sw+(h1-h1sw)*(h4fw-h4sw)/(h1fw-h1sw) >*/
	h4star = static_cast<double>(*h4sw) + static_cast<double>(static_cast<double>((static_cast<double>(*h1) - h1sw)) * (static_cast<double>(*h4fw) - *h4sw)) / (static_cast<double>(*h1fw) - h1sw);
/* SOURCE fqshrftb.for:7196 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:7197 */
/*<       if(h4.gt.h4star)then >*/
    if (*h4 > h4star) {
/*       The point is in the special SO region. */
/* SOURCE fqshrftb.for:7199 */
/*<       flag=1 >*/
	*feq_gen_flag_d_ = 1;
/* SOURCE fqshrftb.for:7200 */
/*<       else >*/
    } else {
/* SOURCE fqshrftb.for:7201 */
/*<       flag=0 >*/
	*feq_gen_flag_d_ = 0;
/* SOURCE fqshrftb.for:7202 */
/*<       endif >*/
    }
/* SOURCE fqshrftb.for:7203 */
/*<       return >*/
    return 0;
/* SOURCE fqshrftb.for:7204 */
/*<       end >*/
} /* tstsow_ */

#ifdef __cplusplus
	}
#endif
