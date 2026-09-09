/* ftlookup.f -- translated by f2c (version 20240504).
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

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;

/* Routines used in function table lookup */





/* SOURCE ftlookup.for:7 */
/*<       subroutinegetyqc(adrs,type,ndep,y,qc) >*/
/* Subroutine */ int getyqc_(integer *adrs, integer *feq_gen_type_d_, integer *ndep, 
	doublereal *feq_storage_y, doublereal *feq_storage_qc)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    integer feq_gen_i_d_, j, ha, la;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Extract depth and critical flow values from tables of type 22 */
/*     or 25 */
/* SOURCE ftlookup.for:14 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE ftlookup.for:17 */
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
/* SOURCE ftlookup.for:20 */
/*<       integeradrs,ndep,type >*/
/* SOURCE ftlookup.for:21 */
/*<       real*8qc(mndep),y(mndep) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TYPE   - type of the cross section function table */
/*     NDEP   - number of depth values */
/*     Y      - depth values */
/*     QC     - critical flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ftlookup.for:30 */
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
/* INCLUDE ftlookup.for:31 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ftlookup.for:34 */
/*<       integerha,i,j,la,xoff >*/
/* *********************************************************************** */
/*     Get the addresses in the table. HA=high address, for the last */
/*     argument in the table; LA=low address, for the first argument */
/*     in the table. */
/* SOURCE ftlookup.for:40 */
/*<       ha=itab(adrs) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> qc(feq_storage_qc, 1);

    feq::IndexedPointer<doublereal> y(feq_storage_y, 1);

    /* Function Body */
    ha = itab[*adrs];
/* SOURCE ftlookup.for:41 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE ftlookup.for:42 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[*feq_gen_type_d_ - 1];
/*     Critical flow is always at offset 7 and depth is at offset 0. */
/* SOURCE ftlookup.for:46 */
/*<       j=0 >*/
    j = 0;
/* SOURCE ftlookup.for:47 */
/*<       do100i=la,ha,xoff >*/
    feq_gen_i_d_1 = ha;
    feq_gen_i_d_2 = xoff;
    for (feq_gen_i_d_ = la; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE ftlookup.for:48 */
/*<       j=j+1 >*/
	++j;
/* SOURCE ftlookup.for:49 */
/*<       y(j)=ftab(i) >*/
	y[j] = ftab[feq_gen_i_d_];
/* SOURCE ftlookup.for:50 */
/*<       qc(j)=ftab(i+7) >*/
	qc[j] = ftab[feq_gen_i_d_ + 7];
/* SOURCE ftlookup.for:51 */
/*<   100 continue >*/
/* L100: */
    }
/*     Set number of depth values. */
/* SOURCE ftlookup.for:54 */
/*<       ndep=j >*/
    *ndep = j;
/* SOURCE ftlookup.for:56 */
/*<       return >*/
    return 0;
/* SOURCE ftlookup.for:57 */
/*<       end >*/
} /* getyqc_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE ftlookup.for:61 */
/*<        >*/
/* Subroutine */ int tdlk14_(integer *stdout, integer *ip, integer *ptype, 
	real *eda, real *hbase, real *qarg, real *hu, real *dhued, real *dhuq,
	 integer *free)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* NEGATIVE QARG IN TDLK14=\002,f\
10.2,\002 TABID=\002,a)";
    static char fmt_52[] = "(/,\002 *WRN:43* FLOW > MAXFLOW IN TWO-D TABID\
=\002,a,\002 FLOW=\002,f10.2,\002 MAXFLOW=\002,f10.2)";
    static char fmt_54[] = "(/,\002 *ERR:73* Unexpected type in two-D TABID\
=\002,a,\002 Type=\002,i5,\002 Expected Type=\002,i5)";
    static char fmt_56[] = "(/,\002 *WRN:44* HDN > MAXHDN IN TWO-D TABID=\
\002,a,\002 HDN=\002,f10.2,\002 MAXHDN=\002,f10.2)";

    /* System generated locals */
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real p;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real ed, hd, hl, pd, hr, ql, qr, pu, dhd;
    integer tab, lhd;
    real hdl, hld, dhp, hdr, hrd;
    integer lqf;
    real qfl;
    integer lhu;
    real hlu, hul, qfr, hru, hur;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer offl;
    real dhlp;
    integer offr;
    real dhrp;
    integer lpfq;
    real qmax;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real dqfhd, dhhdp, hdmax, qfree;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do 2-d lookup for flow for tables of type 14.  The arguments */
/*     are flow at the flow node and the downstream elevation. */
/* SOURCE ftlookup.for:70 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ftlookup.for:72 */
/*<       integerfree,ip,stdout,ptype >*/
/* SOURCE ftlookup.for:73 */
/*<       realdhued,dhuq,eda,hbase,hu,qarg >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     IP     - address of the table */
/*     PTYPE  - expected table type */
/*     EDA    - water surface elevation at downstream node */
/*     HBASE  - datum for heads */
/*     QARG   - flow argument for table lookup */
/*     HU     - head at upstream node */
/*     DHUED  - derivative of upstream head wrt downstream */
/*               water surface elevation */
/*     DHUQ   - derivative of upstream head wrt flow */
/*     FREE   - flag for free flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ftlookup.for:89 */
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
/* INCLUDE ftlookup.for:90 */
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
/*     Called subprograms */
/* SOURCE ftlookup.for:93 */
/*<       character*16get_tabid >*/
/* SOURCE ftlookup.for:94 */
/*<       externalget_tabid >*/
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ftlookup.for:97 */
/*<       integerinc >*/
/* SOURCE ftlookup.for:98 */
/*<       parameter(inc=4) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ftlookup.for:101 */
/*<       integerlhd,lhu,lpfq,lqf,offl,offr,tab,type >*/
/* SOURCE ftlookup.for:102 */
/*<        >*/
/*      integer verbose */
/*      common/debug/ verbose */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ftlookup.for:110 */
/*<    50 format(/,' *BUG:XXX* NEGATIVE QARG IN TDLK14=',f10.2,' TABID=',a) >*/
/* SOURCE ftlookup.for:111 */
/*<    52  >*/
/* SOURCE ftlookup.for:113 */
/*<    54  >*/
/* SOURCE ftlookup.for:115 */
/*<    56  >*/
/* *********************************************************************** */
/*     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT */
/*     POINTERS ARE SET TO THE PROPER VALUES AT START */
/* SOURCE ftlookup.for:121 */
/*<       tab=itab(ip+1) >*/
/* L50: */
/* L52: */
/* L54: */
/* L56: */
    tab = itab[*ip + 1];
/* SOURCE ftlookup.for:122 */
/*<       type=itab(ip+2) >*/
    feq_gen_type_d_ = itab[*ip + 2];
/* SOURCE ftlookup.for:125 */
/*<       ed=eda >*/
    ed = *eda;
/*      if(verbose.eq.1) then */
/*        WRITE(STDOUT,*) 'TDLK14: TAB#=',TAB, ' QARG=',QARG,' ED=',ED */
/*      endif */
/* SOURCE ftlookup.for:131 */
/*<       if(type.ne.ptype)then >*/
    if (feq_gen_type_d_ != *ptype) {
/* SOURCE ftlookup.for:132 */
/*<       write(stdout,54)get_tabid(tab),type,ptype >*/
	feq_gen_io_d__15.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__15);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*ptype), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ftlookup.for:133 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ftlookup.for:134 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:137 */
/*<       hd=ed-hbase >*/
    hd = static_cast<double>(ed) - *hbase;
/*      if(verbose.eq.1) then */
/*        WRITE(STDOUT,*) 'TDLK14: HBASE=',HBASE, ' HD=',HD */
/*      endif */
/*     FIND THE DOWNSTREAM HEAD INTERVAL CONTAINING HD. */
/*     FIRST MAKE SURE THAT HD IS WITHIN VALID RANGE. */
/* SOURCE ftlookup.for:146 */
/*<       hdmax=ftab(ip+5) >*/
    hdmax = ftab[*ip + 5];
/* SOURCE ftlookup.for:148 */
/*<       if(hd.gt.hdmax)then >*/
    if (hd > hdmax) {
/* SOURCE ftlookup.for:149 */
/*<       write(stdout,56)get_tabid(tab),hd,hdmax >*/
	feq_gen_io_d__18.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__18);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&hd, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hdmax, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ftlookup.for:150 */
/*<       hd=hdmax >*/
	hd = hdmax;
/* SOURCE ftlookup.for:151 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:153 */
/*<       if(hd.lt.0.0)hd=0.0 >*/
    if (hd < (float)0.) {
	hd = (float)0.;
    }
/*     NOW THAT HD IS IN THE VALID RANGE SEARCH FOR THE INTERVAL */
/* SOURCE ftlookup.for:157 */
/*<       lhd=itab(ip+3) >*/
    lhd = itab[*ip + 3];
/*      WRITE(STDOUT,*) ' LHD=',LHD,' HDMAX=',HDMAX */
/* SOURCE ftlookup.for:160 */
/*<       if(hd.ge.ftab(lhd))then >*/
    if (hd >= ftab[lhd]) {
/* SOURCE ftlookup.for:161 */
/*<   200 continue >*/
L200:
/* SOURCE ftlookup.for:162 */
/*<       if(hd.le.ftab(lhd+inc))goto220 >*/
	if (hd <= ftab[lhd + 4]) {
	    goto L220;
	}
/* SOURCE ftlookup.for:163 */
/*<       lhd=lhd+inc >*/
	lhd += 4;
/* SOURCE ftlookup.for:164 */
/*<       goto200 >*/
	goto L200;
/* SOURCE ftlookup.for:165 */
/*<       else >*/
    } else {
/* SOURCE ftlookup.for:166 */
/*<   210 continue >*/
L210:
/* SOURCE ftlookup.for:167 */
/*<       lhd=lhd-inc >*/
	lhd += -4;
/* SOURCE ftlookup.for:168 */
/*<       if(hd.ge.ftab(lhd))goto220 >*/
	if (hd >= ftab[lhd]) {
	    goto L220;
	}
/* SOURCE ftlookup.for:169 */
/*<       goto210 >*/
	goto L210;
/* SOURCE ftlookup.for:170 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:171 */
/*<   220 continue >*/
L220:
/* SOURCE ftlookup.for:172 */
/*<       itab(ip+3)=lhd >*/
    itab[*ip + 3] = lhd;
/*     NOW INTERPOLATE FOR THE VALUE OF FREE FLOW WHICH CORRESPONDS */
/*     TO INCIPIENT SUBMERGENCE AT HD. */
/* SOURCE ftlookup.for:177 */
/*<       qfl=ftab(lhd-1) >*/
    qfl = ftab[lhd - 1];
/* SOURCE ftlookup.for:178 */
/*<       qfr=ftab(lhd+inc-1) >*/
    qfr = ftab[lhd + 3];
/* SOURCE ftlookup.for:179 */
/*<       hdl=ftab(lhd) >*/
    hdl = ftab[lhd];
/* SOURCE ftlookup.for:180 */
/*<       hdr=ftab(lhd+inc) >*/
    hdr = ftab[lhd + 4];
/* SOURCE ftlookup.for:182 */
/*<       dqfhd=(qfr-qfl)/(hdr-hdl) >*/
    dqfhd = static_cast<double>((static_cast<double>(qfr) - qfl)) / (static_cast<double>(hdr) - hdl);
/* SOURCE ftlookup.for:183 */
/*<       qfree=qfl+dqfhd*(hd-hdl) >*/
    qfree = static_cast<double>(qfl) + static_cast<double>(dqfhd) * (static_cast<double>(hd) - hdl);
/*      if(verbose.eq.1) then */
/*        write(stdout,*) ' QARG=',QARG,' QFREE=',QFREE */
/*      endif */
/*     DQFHD GIVES THE RATE OF CHANGE OF THE FREE FLOW AT INCIPIENT */
/*     SUBMERGENCE WITH RESPECT TO THE DOWNSTEAM HEAD. */
/* SOURCE ftlookup.for:192 */
/*<       if(qarg.ge.qfree)then >*/
    if (*qarg >= qfree) {
/*       FLOW IS FREE.  NOW FIND THE VALUE OF UPSTREAM HEAD WHICH */
/*       CORRESPONDS TO FREE FLOW IF QARG > 0.  MUST SEARCH FREE FLOW */
/*       LIST USING  QARG. */
/* SOURCE ftlookup.for:197 */
/*<       qmax=ftab(ip+9) >*/
	qmax = ftab[*ip + 9];
/* SOURCE ftlookup.for:199 */
/*<       if(qarg.gt.qmax)then >*/
	if (*qarg > qmax) {
/* SOURCE ftlookup.for:200 */
/*<       write(stdout,52)get_tabid(tab),qarg,qmax >*/
	    feq_gen_io_d__27.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__27);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&(*qarg), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qmax, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE ftlookup.for:201 */
/*<       qarg=qmax >*/
	    *qarg = qmax;
/* SOURCE ftlookup.for:202 */
/*<       endif >*/
	}
/* SOURCE ftlookup.for:204 */
/*<       if(qarg.lt.0.0)then >*/
	if (*qarg < (float)0.) {
/* SOURCE ftlookup.for:205 */
/*<       write(stdout,50)qarg,get_tabid(tab) >*/
	    feq_gen_io_d__28.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__28);
	    do_fio(&feq_gen_c_d_1, (char *)&(*qarg), (ftnlen)sizeof(real));
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE ftlookup.for:206 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ftlookup.for:207 */
/*<       endif >*/
	}
/* SOURCE ftlookup.for:209 */
/*<       if(qarg.gt.0.0)then >*/
	if (*qarg > (float)0.) {
/*         QARG IS NOW WITHIN THE RANGE OF THE FLOWS IN THE LIST. */
/*         FIND THE FLOW INTERVAL IN THE TABLE CONTAINING QARG */
/* SOURCE ftlookup.for:213 */
/*<       lqf=itab(ip+4) >*/
	    lqf = itab[*ip + 4];
/* SOURCE ftlookup.for:214 */
/*<       if(qarg.ge.ftab(lqf))then >*/
	    if (*qarg >= ftab[lqf]) {
/* SOURCE ftlookup.for:215 */
/*<   100 continue >*/
L100:
/* SOURCE ftlookup.for:216 */
/*<       if(qarg.le.ftab(lqf+inc))goto120 >*/
		if (*qarg <= ftab[lqf + 4]) {
		    goto L120;
		}
/* SOURCE ftlookup.for:217 */
/*<       lqf=lqf+inc >*/
		lqf += 4;
/* SOURCE ftlookup.for:218 */
/*<       goto100 >*/
		goto L100;
/* SOURCE ftlookup.for:219 */
/*<       else >*/
	    } else {
/* SOURCE ftlookup.for:220 */
/*<   110 continue >*/
L110:
/* SOURCE ftlookup.for:221 */
/*<       lqf=lqf-inc >*/
		lqf += -4;
/* SOURCE ftlookup.for:222 */
/*<       if(qarg.ge.ftab(lqf))goto120 >*/
		if (*qarg >= ftab[lqf]) {
		    goto L120;
		}
/* SOURCE ftlookup.for:223 */
/*<       goto110 >*/
		goto L110;
/* SOURCE ftlookup.for:224 */
/*<       endif >*/
	    }
/* SOURCE ftlookup.for:225 */
/*<   120 continue >*/
L120:
/* SOURCE ftlookup.for:226 */
/*<       itab(ip+4)=lqf >*/
	    itab[*ip + 4] = lqf;
/*         FIND UPSTREAM LEVEL FOR QARG. */
/* SOURCE ftlookup.for:230 */
/*<       ql=ftab(lqf) >*/
	    ql = ftab[lqf];
/* SOURCE ftlookup.for:231 */
/*<       hul=ftab(lqf+2) >*/
	    hul = ftab[lqf + 2];
/* SOURCE ftlookup.for:232 */
/*<       hur=ftab(lqf+inc+2) >*/
	    hur = ftab[lqf + 6];
/* SOURCE ftlookup.for:233 */
/*<       dhuq=(hur-hul)/(ftab(lqf+inc)-ql) >*/
	    *dhuq = static_cast<double>((static_cast<double>(hur) - hul)) / (static_cast<double>(ftab[lqf + 4]) - ql);
/* SOURCE ftlookup.for:234 */
/*<       hu=hul+dhuq*(qarg-ql) >*/
	    *hu = static_cast<double>(hul) + static_cast<double>(*dhuq) * (static_cast<double>(*qarg) - ql);
/* SOURCE ftlookup.for:235 */
/*<       dhued=0.0 >*/
	    *dhued = (float)0.;
/* SOURCE ftlookup.for:236 */
/*<       free=1 >*/
	    *free = 1;
/*          if(verbose.eq.1) then */
/*            WRITE(STDOUT,*) 'TDLK14: FR FLW QARG=',QARG,' QFREE=',QFREE */
/*            WRITE(STDOUT,*) ' QL=',QL,' QR=',FTAB(LQF+INC), */
/*     A                          ' HUL=',HUL,' HUR=',HUR */
/*            WRITE(STDOUT,*) 'HU =',HU,' DHUQ=',DHUQ */
/*          endif */
/*         DHUQ GIVES THE DERIVATIVE OF UPSTREAM HEAD WITH RESPECT TO */
/*         FREE FLOW. */
/* SOURCE ftlookup.for:246 */
/*<       else >*/
	} else {
/*         FLOW IS ZERO HERE AND THE DOWNSTREAM HEAD IS LESS THAN */
/*         THE UPSTREAM HEAD.  ASSUME FREE FLOW TO GET THE FLOW */
/*         STARTED.  MUST FIND THE FREE FLOW FOR THE GIVEN UPSTREAM */
/*         HEAD.  WHEN QARG = 0.0 THEN UPSTREAM HEAD IS IN HU. */
/*         THE RESULTING VALUE OF FLOW IS RETURNED IN QARG. */
/* SOURCE ftlookup.for:253 */
/*<       itmp=itab(ip+4) >*/
	    ftablea_1.itmp = itab[*ip + 4];
/*         THE UPSTREAM HEAD FOR EACH FREE FLOW IS STORED 2 AFTER THE */
/*         FREE FLOW. */
/* SOURCE ftlookup.for:256 */
/*<       lhu=itmp+2 >*/
	    lhu = ftablea_1.itmp + 2;
/* SOURCE ftlookup.for:257 */
/*<       if(hu.ge.ftab(lhu))then >*/
	    if (*hu >= ftab[lhu]) {
/* SOURCE ftlookup.for:258 */
/*<   102 continue >*/
L102:
/* SOURCE ftlookup.for:259 */
/*<       if(hu.le.ftab(lhu+inc))goto122 >*/
		if (*hu <= ftab[lhu + 4]) {
		    goto L122;
		}
/* SOURCE ftlookup.for:260 */
/*<       lhu=lhu+inc >*/
		lhu += 4;
/* SOURCE ftlookup.for:261 */
/*<       goto102 >*/
		goto L102;
/* SOURCE ftlookup.for:262 */
/*<       else >*/
	    } else {
/* SOURCE ftlookup.for:263 */
/*<   112 continue >*/
L112:
/* SOURCE ftlookup.for:264 */
/*<       lhu=lhu-inc >*/
		lhu += -4;
/* SOURCE ftlookup.for:265 */
/*<       if(hu.ge.ftab(lhu))goto122 >*/
		if (*hu >= ftab[lhu]) {
		    goto L122;
		}
/* SOURCE ftlookup.for:266 */
/*<       goto112 >*/
		goto L112;
/* SOURCE ftlookup.for:267 */
/*<       endif >*/
	    }
/* SOURCE ftlookup.for:268 */
/*<   122 continue >*/
L122:
/*         FIND THE FREE FLOW FOR HU */
/* SOURCE ftlookup.for:272 */
/*<       hul=ftab(lhu) >*/
	    hul = ftab[lhu];
/* SOURCE ftlookup.for:273 */
/*<       ql=ftab(lhu-2) >*/
	    ql = ftab[lhu - 2];
/* SOURCE ftlookup.for:274 */
/*<       hur=ftab(lhu+inc) >*/
	    hur = ftab[lhu + 4];
/* SOURCE ftlookup.for:275 */
/*<       qr=ftab(lhu+inc-2) >*/
	    qr = ftab[lhu + 2];
/*         VARIABLE DHUQ IS USED TO RETURN A VALUE WHICH IN THIS CASE */
/*         IS DQHU! */
/* SOURCE ftlookup.for:278 */
/*<       dhuq=(qr-ql)/(hur-hul) >*/
	    *dhuq = static_cast<double>((static_cast<double>(qr) - ql)) / (static_cast<double>(hur) - hul);
/* SOURCE ftlookup.for:279 */
/*<       qarg=ql+dhuq*(hu-hul) >*/
	    *qarg = static_cast<double>(ql) + static_cast<double>(*dhuq) * (static_cast<double>(*hu) - hul);
/* SOURCE ftlookup.for:280 */
/*<       dhued=0.0 >*/
	    *dhued = (float)0.;
/* SOURCE ftlookup.for:281 */
/*<       free=1 >*/
	    *free = 1;
/*          if(verbose.eq.1) then */
/*            WRITE(STDOUT,*) 'TDLK14: FREE FLOW SPECIAL CASE. HU=',HU */
/*            WRITE(STDOUT,*) ' QL=',QL,' QR=',QR, */
/*     A                          ' HUL=',HUL,' HUR=',HUR */
/*            WRITE(STDOUT,*) 'QARG =',QARG,' DHUQ=',DHUQ */
/*          endif */
/*         DHUQ GIVES THE DERIVATIVE OF FREE FLOW WITH RESPECT TO */
/*         UPSTREAM HEAD IN THIS CASE. */
/* SOURCE ftlookup.for:291 */
/*<       endif >*/
	}
/* SOURCE ftlookup.for:292 */
/*<       else >*/
    } else {
/*       SUBMERGED FLOW HERE. */
/*       GET OFFSETS FROM THE START OF THE */
/*       PARTIAL FREE FLOW LIST TO THE START OF THE LIST OF UPSTREAM */
/*       HEADS FOR EACH OF THE DOWNSTREAM HEADS WHICH BRACKET HD. */
/* SOURCE ftlookup.for:300 */
/*<       offl=itab(lhd+2) >*/
	offl = itab[lhd + 2];
/*        WRITE(STDOUT,*) ' LHD=',LHD,' OFFL=',OFFL */
/* SOURCE ftlookup.for:302 */
/*<       offr=itab(lhd+inc+2) >*/
	offr = itab[lhd + 6];
/*        WRITE(STDOUT,*) ' LHD=',LHD,' OFFR=',OFFR */
/*       GET THE LOCATION OF LAST ACCESS IN THE LIST OF PARTIAL FREE */
/*       FLOWS */
/* SOURCE ftlookup.for:308 */
/*<       lpfq=itab(ip+6) >*/
	lpfq = itab[*ip + 6];
/*       FIND THE FRACTION OF FREE FLOW REPRESENTED BY THE CURRENT FLOW */
/* SOURCE ftlookup.for:312 */
/*<       p=qarg/qfree >*/
	p = static_cast<double>(*qarg) / qfree;
/*        if(verbose.eq.1) then */
/*          WRITE(STDOUT,*) 'TDLK14; SUBMERGED FLOW' */
/*          WRITE(STDOUT,*) ' QARG=',QARG,' QFREE=',QFREE,' P=',P */
/*        endif */
/*       WE HAVE TWO LINES OF CONSTANT DWNSTRM LEVEL.  ONE IS ON THE LEFT */
/*       AND WILL BE DESIGNATED BY THE SUFFIX L.  THE OTHER IS ON THE RIGHT */
/*       AND WILL BE DESIGNATED BY THE SUFFIX R.  ON EACH LINE THERE WILL BE */
/*       A POINT ABOVE AND BELOW P.  THE ONE ABOVE IS DENOTED AS U AND THE */
/*       ONE BELOW AS D.  WE INTERPOLATE IN EACH LINE WITH P AND THEN */
/*       INTERPOLATE ON THE DOWNSTREAM LEVEL. IN TYPE 14 WE HAVE */
/*       ONLY ONE SEQUENCE OF PARTIAL FREE FLOWS.  THUS WE SEARCH ONLY */
/*       ONCE. */
/*       SEARCH IN THE PARTIAL FREE FLOW LIST */
/*        WRITE(STDOUT,*) 'PFQ SEARCH START LPFQ=',LPFQ */
/* SOURCE ftlookup.for:332 */
/*<       if(p.ge.ftab(lpfq))then >*/
	if (p >= ftab[lpfq]) {
/* SOURCE ftlookup.for:333 */
/*<   130 continue >*/
L130:
/* SOURCE ftlookup.for:334 */
/*<       if(p.le.ftab(lpfq+1))goto150 >*/
	    if (p <= ftab[lpfq + 1]) {
		goto L150;
	    }
/* SOURCE ftlookup.for:335 */
/*<       lpfq=lpfq+1 >*/
	    ++lpfq;
/* SOURCE ftlookup.for:336 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE ftlookup.for:337 */
/*<       else >*/
	} else {
/* SOURCE ftlookup.for:338 */
/*<   140 continue >*/
L140:
/* SOURCE ftlookup.for:339 */
/*<       lpfq=lpfq-1 >*/
	    --lpfq;
/* SOURCE ftlookup.for:340 */
/*<       if(p.ge.ftab(lpfq))goto150 >*/
	    if (p >= ftab[lpfq]) {
		goto L150;
	    }
/* SOURCE ftlookup.for:341 */
/*<       goto140 >*/
	    goto L140;
/* SOURCE ftlookup.for:342 */
/*<       endif >*/
	}
/* SOURCE ftlookup.for:343 */
/*<   150 continue >*/
L150:
/* SOURCE ftlookup.for:344 */
/*<       itab(ip+6)=lpfq >*/
	itab[*ip + 6] = lpfq;
/*        WRITE(STDOUT,*) ' PFQ SEARCH END LPFQ=',LPFQ */
/* SOURCE ftlookup.for:348 */
/*<       pd=ftab(lpfq) >*/
	pd = ftab[lpfq];
/* SOURCE ftlookup.for:349 */
/*<       hld=ftab(offl+lpfq) >*/
	hld = ftab[offl + lpfq];
/* SOURCE ftlookup.for:350 */
/*<       hlu=ftab(offl+lpfq+1) >*/
	hlu = ftab[offl + lpfq + 1];
/* SOURCE ftlookup.for:351 */
/*<       pu=ftab(lpfq+1) >*/
	pu = ftab[lpfq + 1];
/* SOURCE ftlookup.for:352 */
/*<       dhlp=(hlu-hld)/(pu-pd) >*/
	dhlp = static_cast<double>((static_cast<double>(hlu) - hld)) / (static_cast<double>(pu) - pd);
/* SOURCE ftlookup.for:353 */
/*<       hl=hld+dhlp*(p-pd) >*/
	hl = static_cast<double>(hld) + static_cast<double>(dhlp) * (static_cast<double>(p) - pd);
/*       DHLP GIVES THE PARTIAL DERIVATIVE OF THE UPSTREAM HEAD */
/*       WITH RESPECT TO THE PARTIAL FREE FLOW ALONG THE LEFT */
/*       LINE OF CONSTANT DOWNSTREAM HEAD. */
/*        if(verbose.eq.1) then */
/*          WRITE(STDOUT,*) ' PD=',PD,' HLD=',HLD,' LPFQ=',LPFQ */
/*          WRITE(STDOUT,*) ' PU=',PU,' HLU=',HLU,' HL=',HL */
/*        endif */
/* SOURCE ftlookup.for:363 */
/*<       hrd=ftab(offr+lpfq) >*/
	hrd = ftab[offr + lpfq];
/* SOURCE ftlookup.for:364 */
/*<       hru=ftab(offr+lpfq+1) >*/
	hru = ftab[offr + lpfq + 1];
/* SOURCE ftlookup.for:365 */
/*<       dhrp=(hru-hrd)/(pu-pd) >*/
	dhrp = static_cast<double>((static_cast<double>(hru) - hrd)) / (static_cast<double>(pu) - pd);
/* SOURCE ftlookup.for:366 */
/*<       hr=hrd+dhrp*(p-pd) >*/
	hr = static_cast<double>(hrd) + static_cast<double>(dhrp) * (static_cast<double>(p) - pd);
/*       DHRP GIVES THE PARTIAL DERIVATIVE OF UPSTREAM HEAD */
/*       WITH RESPECT TO THE PARTIAL FREE FLOW ALONG THE */
/*       RIGHT LINE OF CONSTANT DOWNSTREAM HEAD. */
/*        if(verbose.eq.1) then */
/*          WRITE(STDOUT,*) ' PD=',PD,' HRD=',HRD,' LPFQ=',LPFQ */
/*          WRITE(STDOUT,*) ' PU=',PU,' HRU=',HRU,' HR=',HR */
/*        endif */
/*        WRITE(STDOUT,*) 'TDLK14: HL=',HL,' HR=',HR */
/*       COMPUTE THE UPSTREAM HEAD AND ITS DERIVATIVES */
/* SOURCE ftlookup.for:380 */
/*<       dhd=hdr-hdl >*/
	dhd = static_cast<double>(hdr) - hdl;
/* SOURCE ftlookup.for:381 */
/*<       dhhdp=(hr-hl)/dhd >*/
	dhhdp = static_cast<double>((static_cast<double>(hr) - hl)) / dhd;
/* SOURCE ftlookup.for:382 */
/*<       hu=hl+dhhdp*(hd-hdl) >*/
	*hu = static_cast<double>(hl) + static_cast<double>(dhhdp) * (static_cast<double>(hd) - hdl);
/*       DHHDP GIVES THE PARTIAL DERIVATIVE OF THE UPSTREAM HEAD */
/*       WITH RESPECT TO DOWNSTREAM HEAD WHEN THE PARTIAL FREE FLOW */
/*       IS HELD CONSTANT. */
/* SOURCE ftlookup.for:388 */
/*<       dhp=dhlp+(hd-hdl)*(dhrp-dhlp)/dhd >*/
	dhp = static_cast<double>(dhlp) + static_cast<double>(static_cast<double>((static_cast<double>(hd) - hdl)) * (static_cast<double>(dhrp) - dhlp)) / dhd;
/* SOURCE ftlookup.for:390 */
/*<       dhuq=dhp/qfree >*/
	*dhuq = static_cast<double>(dhp) / qfree;
/* SOURCE ftlookup.for:392 */
/*<       dhued=-qarg*dhp*dqfhd/qfree**2+dhhdp >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = qfree;
	*dhued = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(-(*qarg)) * dhp) * dqfhd) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) + dhhdp;
/* SOURCE ftlookup.for:394 */
/*<       free=0 >*/
	*free = 0;
/* SOURCE ftlookup.for:396 */
/*<       endif >*/
    }
/*      if(verbose.eq.1) then */
/*        WRITE(STDOUT,*) 'TDLK14: Q=',QARG,' DHUED=',DHUED,' DHUQ=',DHUQ, */
/*     A               ' HU=',HU */
/*      endif */
/* SOURCE ftlookup.for:401 */
/*<       return >*/
    return 0;
/* SOURCE ftlookup.for:403 */
/*<       end >*/
} /* tdlk14_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE ftlookup.for:407 */
/*<       subroutinetdlk14_chk(stdout,ip,ptype,eda,hbase,qarg,hu,qfree,free) >*/
/* Subroutine */ int feq_gen_tdlk14_chk_d_(integer *stdout, integer *ip, integer *
	ptype, real *eda, real *hbase, real *qarg, real *hu, real *qfree, 
	integer *free)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* NEGATIVE QARG IN TDLK14_CHK\
=\002,f10.3,\002 TABID=\002,a)";
    static char fmt_52[] = "(/,\002 *WRN:43* Flow > Maxflow in Two-D tabid\
=\002,a,\002 Flow=\002,f10.2,\002 Maxflow=\002,f10.2)";
    static char fmt_54[] = "(/,\002 *ERR:73* Unexpected type in two-D TABID\
=\002,a,\002 Type=\002,i5,\002 Expected Type=\002,i5)";
    static char fmt_56[] = "(/,\002 *WRN:44* HDN > MAXHDN IN TWO-D TABID=\
\002,a,\002 HDN=\002,f10.2,\002 MAXHDN=\002,f10.2)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real p;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real ed, hd, hl, pd, hr, ql, qr, pu, dhd;
    integer tab, lhd;
    real hdl, hld, dhp, hdr, hrd;
    integer lqf;
    real qfl;
    integer lhu;
    real hlu, hul, qfr, hru, hur;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer offl;
    real dhlp;
    integer offr;
    real dhrp, dhuq;
    integer lpfq;
    real qmax;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real dqfhd, dhhdp, hdmax;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__69 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do 2-d lookup for flow for tables of type 14.  The arguments */
/*     are flow at the flow node and the downstream elevation. */
/*     This version used for checking tables. */
/* SOURCE ftlookup.for:417 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ftlookup.for:419 */
/*<       integerfree,ip,stdout,ptype >*/
/* SOURCE ftlookup.for:420 */
/*<       realeda,hbase,hu,qarg,qfree >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     IP     - address of the table */
/*     PTYPE  - expected table type */
/*     EDA    - water surface elevation at downstream node */
/*     HBASE  - datum for heads */
/*     QARG   - flow argument for table lookup */
/*     HU     - head at upstream node */
/*     QFREE  - free flow at the downstream head */
/*     FREE   - flag for free flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ftlookup.for:434 */
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
/* INCLUDE ftlookup.for:435 */
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
/*     Called subprograms */
/* SOURCE ftlookup.for:438 */
/*<       character*16get_tabid >*/
/* SOURCE ftlookup.for:439 */
/*<       externalget_tabid >*/
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ftlookup.for:442 */
/*<       integerinc >*/
/* SOURCE ftlookup.for:443 */
/*<       parameter(inc=4) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ftlookup.for:446 */
/*<       integerlhd,lhu,lpfq,lqf,offl,offr,tab,type >*/
/* SOURCE ftlookup.for:447 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ftlookup.for:452 */
/*<    50  >*/
/* SOURCE ftlookup.for:454 */
/*<    52  >*/
/* SOURCE ftlookup.for:456 */
/*<    54  >*/
/* SOURCE ftlookup.for:458 */
/*<    56  >*/
/* *********************************************************************** */
/*     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT */
/*     POINTERS ARE SET TO THE PROPER VALUES AT START */
/* SOURCE ftlookup.for:464 */
/*<       tab=itab(ip+1) >*/
/* L50: */
/* L52: */
/* L54: */
/* L56: */
    tab = itab[*ip + 1];
/* SOURCE ftlookup.for:465 */
/*<       type=itab(ip+2) >*/
    feq_gen_type_d_ = itab[*ip + 2];
/* SOURCE ftlookup.for:468 */
/*<       ed=eda >*/
    ed = *eda;
/*      WRITE(STDOUT,*) 'TDLK14: TAB#=',TAB, ' QARG=',QARG,' ED=',ED */
/* SOURCE ftlookup.for:472 */
/*<       if(type.ne.ptype)then >*/
    if (feq_gen_type_d_ != *ptype) {
/* SOURCE ftlookup.for:473 */
/*<       write(stdout,54)get_tabid(tab),type,ptype >*/
	feq_gen_io_d__58.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__58);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*ptype), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ftlookup.for:474 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ftlookup.for:475 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:478 */
/*<       hd=ed-hbase >*/
    hd = static_cast<double>(ed) - *hbase;
/*      WRITE(STDOUT,*) 'TDLK14: HBASE=',HBASE, ' HD=',HD */
/*     FIND THE DOWNSTREAM HEAD INTERVAL CONTAINING HD. */
/*     FIRST MAKE SURE THAT HD IS WITHIN VALID RANGE. */
/* SOURCE ftlookup.for:485 */
/*<       hdmax=ftab(ip+5) >*/
    hdmax = ftab[*ip + 5];
/* SOURCE ftlookup.for:487 */
/*<       if(hd.gt.hdmax)then >*/
    if (hd > hdmax) {
/* SOURCE ftlookup.for:488 */
/*<       write(stdout,56)get_tabid(tab),hd,hdmax >*/
	feq_gen_io_d__61.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__61);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&hd, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hdmax, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ftlookup.for:489 */
/*<       hd=hdmax >*/
	hd = hdmax;
/* SOURCE ftlookup.for:490 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:492 */
/*<       if(hd.lt.0.0)hd=0.0 >*/
    if (hd < (float)0.) {
	hd = (float)0.;
    }
/*     NOW THAT HD IS IN THE VALID RANGE SEARCH FOR THE INTERVAL */
/* SOURCE ftlookup.for:496 */
/*<       lhd=itab(ip+3) >*/
    lhd = itab[*ip + 3];
/*      WRITE(STDOUT,*) ' LHD=',LHD,' HDMAX=',HDMAX */
/* SOURCE ftlookup.for:499 */
/*<       if(hd.ge.ftab(lhd))then >*/
    if (hd >= ftab[lhd]) {
/* SOURCE ftlookup.for:500 */
/*<   200 continue >*/
L200:
/* SOURCE ftlookup.for:501 */
/*<       if(hd.le.ftab(lhd+inc))goto220 >*/
	if (hd <= ftab[lhd + 4]) {
	    goto L220;
	}
/* SOURCE ftlookup.for:502 */
/*<       lhd=lhd+inc >*/
	lhd += 4;
/* SOURCE ftlookup.for:503 */
/*<       goto200 >*/
	goto L200;
/* SOURCE ftlookup.for:504 */
/*<       else >*/
    } else {
/* SOURCE ftlookup.for:505 */
/*<   210 continue >*/
L210:
/* SOURCE ftlookup.for:506 */
/*<       lhd=lhd-inc >*/
	lhd += -4;
/* SOURCE ftlookup.for:507 */
/*<       if(hd.ge.ftab(lhd))goto220 >*/
	if (hd >= ftab[lhd]) {
	    goto L220;
	}
/* SOURCE ftlookup.for:508 */
/*<       goto210 >*/
	goto L210;
/* SOURCE ftlookup.for:509 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:510 */
/*<   220 continue >*/
L220:
/* SOURCE ftlookup.for:511 */
/*<       itab(ip+3)=lhd >*/
    itab[*ip + 3] = lhd;
/*     NOW INTERPOLATE FOR THE VALUE OF FREE FLOW WHICH CORRESPONDS */
/*     TO INCIPIENT SUBMERGENCE AT HD. */
/* SOURCE ftlookup.for:516 */
/*<       qfl=ftab(lhd-1) >*/
    qfl = ftab[lhd - 1];
/* SOURCE ftlookup.for:517 */
/*<       qfr=ftab(lhd+inc-1) >*/
    qfr = ftab[lhd + 3];
/* SOURCE ftlookup.for:518 */
/*<       hdl=ftab(lhd) >*/
    hdl = ftab[lhd];
/* SOURCE ftlookup.for:519 */
/*<       hdr=ftab(lhd+inc) >*/
    hdr = ftab[lhd + 4];
/* SOURCE ftlookup.for:521 */
/*<       dqfhd=(qfr-qfl)/(hdr-hdl) >*/
    dqfhd = static_cast<double>((static_cast<double>(qfr) - qfl)) / (static_cast<double>(hdr) - hdl);
/* SOURCE ftlookup.for:522 */
/*<       qfree=qfl+dqfhd*(hd-hdl) >*/
    *qfree = static_cast<double>(qfl) + static_cast<double>(dqfhd) * (static_cast<double>(hd) - hdl);
/*     DQFHD GIVES THE RATE OF CHANGE OF THE FREE FLOW AT INCIPIENT */
/*     SUBMERGENCE WITH RESPECT TO THE DOWNSTEAM HEAD. */
/* SOURCE ftlookup.for:527 */
/*<       if(qarg.ge.qfree)then >*/
    if (*qarg >= *qfree) {
/*       FLOW IS FREE.  NOW FIND THE VALUE OF UPSTREAM HEAD WHICH */
/*       CORRESPONDS TO FREE FLOW IF QARG > 0.  MUST SEARCH FREE FLOW */
/*       LIST USING  QARG. */
/* SOURCE ftlookup.for:532 */
/*<       qmax=ftab(ip+9) >*/
	qmax = ftab[*ip + 9];
/* SOURCE ftlookup.for:534 */
/*<       if(qarg.gt.qmax)then >*/
	if (*qarg > qmax) {
/* SOURCE ftlookup.for:535 */
/*<       write(stdout,52)get_tabid(tab),qarg,qmax >*/
	    feq_gen_io_d__69.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__69);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&(*qarg), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qmax, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE ftlookup.for:536 */
/*<       qarg=qmax >*/
	    *qarg = qmax;
/* SOURCE ftlookup.for:537 */
/*<       endif >*/
	}
/* SOURCE ftlookup.for:539 */
/*<       if(qarg.lt.0.0)then >*/
	if (*qarg < (float)0.) {
/* SOURCE ftlookup.for:540 */
/*<       write(stdout,50)qarg,get_tabid(tab) >*/
	    feq_gen_io_d__70.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__70);
	    do_fio(&feq_gen_c_d_1, (char *)&(*qarg), (ftnlen)sizeof(real));
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE ftlookup.for:541 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ftlookup.for:542 */
/*<       endif >*/
	}
/* SOURCE ftlookup.for:544 */
/*<       if(qarg.gt.0.0)then >*/
	if (*qarg > (float)0.) {
/*         QARG IS NOW WITHIN THE RANGE OF THE FLOWS IN THE LIST. */
/*         FIND THE FLOW INTERVAL IN THE TABLE CONTAINING QARG */
/* SOURCE ftlookup.for:548 */
/*<       lqf=itab(ip+4) >*/
	    lqf = itab[*ip + 4];
/* SOURCE ftlookup.for:549 */
/*<       if(qarg.ge.ftab(lqf))then >*/
	    if (*qarg >= ftab[lqf]) {
/* SOURCE ftlookup.for:550 */
/*<   100 continue >*/
L100:
/* SOURCE ftlookup.for:551 */
/*<       if(qarg.le.ftab(lqf+inc))goto120 >*/
		if (*qarg <= ftab[lqf + 4]) {
		    goto L120;
		}
/* SOURCE ftlookup.for:552 */
/*<       lqf=lqf+inc >*/
		lqf += 4;
/* SOURCE ftlookup.for:553 */
/*<       goto100 >*/
		goto L100;
/* SOURCE ftlookup.for:554 */
/*<       else >*/
	    } else {
/* SOURCE ftlookup.for:555 */
/*<   110 continue >*/
L110:
/* SOURCE ftlookup.for:556 */
/*<       lqf=lqf-inc >*/
		lqf += -4;
/* SOURCE ftlookup.for:557 */
/*<       if(qarg.ge.ftab(lqf))goto120 >*/
		if (*qarg >= ftab[lqf]) {
		    goto L120;
		}
/* SOURCE ftlookup.for:558 */
/*<       goto110 >*/
		goto L110;
/* SOURCE ftlookup.for:559 */
/*<       endif >*/
	    }
/* SOURCE ftlookup.for:560 */
/*<   120 continue >*/
L120:
/* SOURCE ftlookup.for:561 */
/*<       itab(ip+4)=lqf >*/
	    itab[*ip + 4] = lqf;
/*         FIND UPSTREAM LEVEL FOR QARG. */
/* SOURCE ftlookup.for:565 */
/*<       ql=ftab(lqf) >*/
	    ql = ftab[lqf];
/* SOURCE ftlookup.for:566 */
/*<       hul=ftab(lqf+2) >*/
	    hul = ftab[lqf + 2];
/* SOURCE ftlookup.for:567 */
/*<       hur=ftab(lqf+inc+2) >*/
	    hur = ftab[lqf + 6];
/* SOURCE ftlookup.for:568 */
/*<       dhuq=(hur-hul)/(ftab(lqf+inc)-ql) >*/
	    dhuq = static_cast<double>((static_cast<double>(hur) - hul)) / (static_cast<double>(ftab[lqf + 4]) - ql);
/* SOURCE ftlookup.for:569 */
/*<       hu=hul+dhuq*(qarg-ql) >*/
	    *hu = static_cast<double>(hul) + static_cast<double>(dhuq) * (static_cast<double>(*qarg) - ql);
/* SOURCE ftlookup.for:570 */
/*<       free=1 >*/
	    *free = 1;
/*          WRITE(STDOUT,*) 'TDLK14: FREE FLOW QARG=',QARG,' QFREE=',QFREE */
/*          WRITE(STDOUT,*) ' QL=',QL,' QR=',FTAB(LQF+INC), */
/*     A                          ' HUL=',HUL,' HUR=',HUR */
/*          WRITE(STDOUT,*) 'HU =',HU,' DHUQ=',DHUQ */
/*         DHUQ GIVES THE DERIVATIVE OF UPSTREAM HEAD WITH RESPECT TO */
/*         FREE FLOW. */
/* SOURCE ftlookup.for:578 */
/*<       else >*/
	} else {
/*         FLOW IS ZERO HERE AND THE DOWNSTREAM HEAD IS LESS THAN */
/*         THE UPSTREAM HEAD.  ASSUME FREE FLOW TO GET THE FLOW */
/*         STARTED.  MUST FIND THE FREE FLOW FOR THE GIVEN UPSTREAM */
/*         HEAD.  WHEN QARG = 0.0 THEN UPSTREAM HEAD IS IN HU. */
/*         THE RESULTING VALUE OF FLOW IS RETURNED IN QARG. */
/* SOURCE ftlookup.for:585 */
/*<       itmp=itab(ip+4) >*/
	    ftablea_1.itmp = itab[*ip + 4];
/*         THE UPSTREAM HEAD FOR EACH FREE FLOW IS STORED 2 AFTER THE */
/*         FREE FLOW. */
/* SOURCE ftlookup.for:588 */
/*<       lhu=itmp+2 >*/
	    lhu = ftablea_1.itmp + 2;
/* SOURCE ftlookup.for:589 */
/*<       if(hu.ge.ftab(lhu))then >*/
	    if (*hu >= ftab[lhu]) {
/* SOURCE ftlookup.for:590 */
/*<   102 continue >*/
L102:
/* SOURCE ftlookup.for:591 */
/*<       if(hu.le.ftab(lhu+inc))goto122 >*/
		if (*hu <= ftab[lhu + 4]) {
		    goto L122;
		}
/* SOURCE ftlookup.for:592 */
/*<       lhu=lhu+inc >*/
		lhu += 4;
/* SOURCE ftlookup.for:593 */
/*<       goto102 >*/
		goto L102;
/* SOURCE ftlookup.for:594 */
/*<       else >*/
	    } else {
/* SOURCE ftlookup.for:595 */
/*<   112 continue >*/
L112:
/* SOURCE ftlookup.for:596 */
/*<       lhu=lhu-inc >*/
		lhu += -4;
/* SOURCE ftlookup.for:597 */
/*<       if(hu.ge.ftab(lhu))goto122 >*/
		if (*hu >= ftab[lhu]) {
		    goto L122;
		}
/* SOURCE ftlookup.for:598 */
/*<       goto112 >*/
		goto L112;
/* SOURCE ftlookup.for:599 */
/*<       endif >*/
	    }
/* SOURCE ftlookup.for:600 */
/*<   122 continue >*/
L122:
/*         FIND THE FREE FLOW FOR HU */
/* SOURCE ftlookup.for:604 */
/*<       hul=ftab(lhu) >*/
	    hul = ftab[lhu];
/* SOURCE ftlookup.for:605 */
/*<       ql=ftab(lhu-2) >*/
	    ql = ftab[lhu - 2];
/* SOURCE ftlookup.for:606 */
/*<       hur=ftab(lhu+inc) >*/
	    hur = ftab[lhu + 4];
/* SOURCE ftlookup.for:607 */
/*<       qr=ftab(lhu+inc-2) >*/
	    qr = ftab[lhu + 2];
/*         VARIABLE DHUQ IS USED TO RETURN A VALUE WHICH IN THIS CASE */
/*         IS DQHU! */
/* SOURCE ftlookup.for:610 */
/*<       dhuq=(qr-ql)/(hur-hul) >*/
	    dhuq = static_cast<double>((static_cast<double>(qr) - ql)) / (static_cast<double>(hur) - hul);
/* SOURCE ftlookup.for:611 */
/*<       qarg=ql+dhuq*(hu-hul) >*/
	    *qarg = static_cast<double>(ql) + static_cast<double>(dhuq) * (static_cast<double>(*hu) - hul);
/* SOURCE ftlookup.for:612 */
/*<       free=1 >*/
	    *free = 1;
/*          WRITE(STDOUT,*) 'TDLK14: FREE FLOW SPECIAL CASE. HU=',HU */
/*          WRITE(STDOUT,*) ' QL=',QL,' QR=',QR, */
/*     A                          ' HUL=',HUL,' HUR=',HUR */
/*          WRITE(STDOUT,*) 'QARG =',QARG,' DHUQ=',DHUQ */
/*         DHUQ GIVES THE DERIVATIVE OF FREE FLOW WITH RESPECT TO */
/*         UPSTREAM HEAD IN THIS CASE. */
/* SOURCE ftlookup.for:620 */
/*<       endif >*/
	}
/* SOURCE ftlookup.for:621 */
/*<       else >*/
    } else {
/*       SUBMERGED FLOW HERE. */
/*       GET OFFSETS FROM THE START OF THE */
/*       PARTIAL FREE FLOW LIST TO THE START OF THE LIST OF UPSTREAM */
/*       HEADS FOR EACH OF THE DOWNSTREAM HEADS WHICH BRACKET HD. */
/* SOURCE ftlookup.for:629 */
/*<       offl=itab(lhd+2) >*/
	offl = itab[lhd + 2];
/*        WRITE(STDOUT,*) ' LHD=',LHD,' OFFL=',OFFL */
/* SOURCE ftlookup.for:631 */
/*<       offr=itab(lhd+inc+2) >*/
	offr = itab[lhd + 6];
/*        WRITE(STDOUT,*) ' LHD=',LHD,' OFFR=',OFFR */
/*       GET THE LOCATION OF LAST ACCESS IN THE LIST OF PARTIAL FREE */
/*       FLOWS */
/* SOURCE ftlookup.for:637 */
/*<       lpfq=itab(ip+6) >*/
	lpfq = itab[*ip + 6];
/*       FIND THE FRACTION OF FREE FLOW REPRESENTED BY THE CURRENT FLOW */
/* SOURCE ftlookup.for:641 */
/*<       p=qarg/qfree >*/
	p = static_cast<double>(*qarg) / *qfree;
/*        WRITE(STDOUT,*) 'TDLK14; SUBMERGED FLOW' */
/*        WRITE(STDOUT,*) ' QARG=',QARG,' QFREE=',QFREE,' P=',P */
/*       WE HAVE TWO LINES OF CONSTANT DWNSTRM LEVEL.  ONE IS ON THE LEFT */
/*       AND WILL BE DESIGNATED BY THE SUFFIX L.  THE OTHER IS ON THE RIGHT */
/*       AND WILL BE DESIGNATED BY THE SUFFIX R.  ON EACH LINE THERE WILL BE */
/*       A POINT ABOVE AND BELOW P.  THE ONE ABOVE IS DENOTED AS U AND THE */
/*       ONE BELOW AS D.  WE INTERPOLATE IN EACH LINE WITH P AND THEN */
/*       INTERPOLATE ON THE DOWNSTREAM LEVEL. IN TYPE 14 WE HAVE */
/*       ONLY ONE SEQUENCE OF PARTIAL FREE FLOWS.  THUS WE SEARCH ONLY */
/*       ONCE. */
/*       SEARCH IN THE PARTIAL FREE FLOW LIST */
/*        WRITE(STDOUT,*) 'PFQ SEARCH START LPFQ=',LPFQ */
/* SOURCE ftlookup.for:659 */
/*<       if(p.ge.ftab(lpfq))then >*/
	if (p >= ftab[lpfq]) {
/* SOURCE ftlookup.for:660 */
/*<   130 continue >*/
L130:
/* SOURCE ftlookup.for:661 */
/*<       if(p.le.ftab(lpfq+1))goto150 >*/
	    if (p <= ftab[lpfq + 1]) {
		goto L150;
	    }
/* SOURCE ftlookup.for:662 */
/*<       lpfq=lpfq+1 >*/
	    ++lpfq;
/* SOURCE ftlookup.for:663 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE ftlookup.for:664 */
/*<       else >*/
	} else {
/* SOURCE ftlookup.for:665 */
/*<   140 continue >*/
L140:
/* SOURCE ftlookup.for:666 */
/*<       lpfq=lpfq-1 >*/
	    --lpfq;
/* SOURCE ftlookup.for:667 */
/*<       if(p.ge.ftab(lpfq))goto150 >*/
	    if (p >= ftab[lpfq]) {
		goto L150;
	    }
/* SOURCE ftlookup.for:668 */
/*<       goto140 >*/
	    goto L140;
/* SOURCE ftlookup.for:669 */
/*<       endif >*/
	}
/* SOURCE ftlookup.for:670 */
/*<   150 continue >*/
L150:
/* SOURCE ftlookup.for:671 */
/*<       itab(ip+6)=lpfq >*/
	itab[*ip + 6] = lpfq;
/*        WRITE(STDOUT,*) ' PFQ SEARCH END LPFQ=',LPFQ */
/* SOURCE ftlookup.for:675 */
/*<       pd=ftab(lpfq) >*/
	pd = ftab[lpfq];
/* SOURCE ftlookup.for:676 */
/*<       hld=ftab(offl+lpfq) >*/
	hld = ftab[offl + lpfq];
/* SOURCE ftlookup.for:677 */
/*<       hlu=ftab(offl+lpfq+1) >*/
	hlu = ftab[offl + lpfq + 1];
/* SOURCE ftlookup.for:678 */
/*<       pu=ftab(lpfq+1) >*/
	pu = ftab[lpfq + 1];
/* SOURCE ftlookup.for:679 */
/*<       dhlp=(hlu-hld)/(pu-pd) >*/
	dhlp = static_cast<double>((static_cast<double>(hlu) - hld)) / (static_cast<double>(pu) - pd);
/* SOURCE ftlookup.for:680 */
/*<       hl=hld+dhlp*(p-pd) >*/
	hl = static_cast<double>(hld) + static_cast<double>(dhlp) * (static_cast<double>(p) - pd);
/*       DHLP GIVES THE PARTIAL DERIVATIVE OF THE UPSTREAM HEAD */
/*       WITH RESPECT TO THE PARTIAL FREE FLOW ALONG THE LEFT */
/*       LINE OF CONSTANT DOWNSTREAM HEAD. */
/*        WRITE(STDOUT,*) ' PD=',PD,' HLD=',HLD,' LPFQ=',LPFQ */
/*        WRITE(STDOUT,*) ' PU=',PU,' HLU=',HLU,' HL=',HL */
/* SOURCE ftlookup.for:689 */
/*<       hrd=ftab(offr+lpfq) >*/
	hrd = ftab[offr + lpfq];
/* SOURCE ftlookup.for:690 */
/*<       hru=ftab(offr+lpfq+1) >*/
	hru = ftab[offr + lpfq + 1];
/* SOURCE ftlookup.for:691 */
/*<       dhrp=(hru-hrd)/(pu-pd) >*/
	dhrp = static_cast<double>((static_cast<double>(hru) - hrd)) / (static_cast<double>(pu) - pd);
/* SOURCE ftlookup.for:692 */
/*<       hr=hrd+dhrp*(p-pd) >*/
	hr = static_cast<double>(hrd) + static_cast<double>(dhrp) * (static_cast<double>(p) - pd);
/*       DHRP GIVES THE PARTIAL DERIVATIVE OF UPSTREAM HEAD */
/*       WITH RESPECT TO THE PARTIAL FREE FLOW ALONG THE */
/*       RIGHT LINE OF CONSTANT DOWNSTREAM HEAD. */
/*        WRITE(STDOUT,*) ' PD=',PD,' HRD=',HRD,' LPFQ=',LPFQ */
/*        WRITE(STDOUT,*) ' PU=',PU,' HRU=',HRU,' HR=',HR */
/*        WRITE(STDOUT,*) 'TDLK14: HL=',HL,' HR=',HR */
/*       COMPUTE THE UPSTREAM HEAD AND ITS DERIVATIVES */
/* SOURCE ftlookup.for:705 */
/*<       dhd=hdr-hdl >*/
	dhd = static_cast<double>(hdr) - hdl;
/* SOURCE ftlookup.for:706 */
/*<       dhhdp=(hr-hl)/dhd >*/
	dhhdp = static_cast<double>((static_cast<double>(hr) - hl)) / dhd;
/* SOURCE ftlookup.for:707 */
/*<       hu=hl+dhhdp*(hd-hdl) >*/
	*hu = static_cast<double>(hl) + static_cast<double>(dhhdp) * (static_cast<double>(hd) - hdl);
/*       DHHDP GIVES THE PARTIAL DERIVATIVE OF THE UPSTREAM HEAD */
/*       WITH RESPECT TO DOWNSTREAM HEAD WHEN THE PARTIAL FREE FLOW */
/*       IS HELD CONSTANT. */
/* SOURCE ftlookup.for:713 */
/*<       dhp=dhlp+(hd-hdl)*(dhrp-dhlp)/dhd >*/
	dhp = static_cast<double>(dhlp) + static_cast<double>(static_cast<double>((static_cast<double>(hd) - hdl)) * (static_cast<double>(dhrp) - dhlp)) / dhd;
/* SOURCE ftlookup.for:715 */
/*<       dhuq=dhp/qfree >*/
	dhuq = static_cast<double>(dhp) / *qfree;
/* SOURCE ftlookup.for:718 */
/*<       free=0 >*/
	*free = 0;
/* SOURCE ftlookup.for:720 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) 'TDLK14: Q=',QARG,' DHUED=',DHUED,' DHUQ=',DHUQ, */
/*     A               ' HU=',HU */
/* SOURCE ftlookup.for:723 */
/*<       return >*/
    return 0;
/* SOURCE ftlookup.for:725 */
/*<       end >*/
} /* tdlk14_chk__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE ftlookup.for:729 */
/*<        >*/
/* Subroutine */ int tdlk6_(integer *stdout, integer *ip, integer *ptype, 
	integer *mftab, doublereal *jtime, real *eda, real *eua, real *hbase, 
	real *q, real *dqed, real *dqeu, integer *free)
{
    /* Format strings */
    static char fmt_50[] = "(\002*ERR:72* EU < ED in two-D TABID=\002,a,\002\
 EU=\002,f10.2,\002 ED=\002,f10.2)";
    static char fmt_52[] = "(\002*WRN:04* HU > HMAX in two-D TABID=\002,a\
,\002 HU=\002,f10.2,\002 HMAX=\002,f10.2)";
    static char fmt_54[] = "(\002*ERR:73* Unexpected type in two-D TABID=\
\002,a,\002 Type=\002,i5,\002 expected Type=\002,i5)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real p;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real ed, eu;
    integer lp;
    real hu, ql, qr, fac;
    integer tab;
    real pld, qld, prd, qrd;
    integer lhu;
    real hul, hur, plu, qlu, pru, qru;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real dpeu, hmax, dqlp, dqhu, drop, dqrp;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real dqled, dqred, dqleu, dqreu, hdrop, hdropl, ddropu, hdropr, thdrop;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Do 2-d lookup for flow in tables of type 6. */
/* SOURCE ftlookup.for:737 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ftlookup.for:739 */
/*<       integerfree,ip,stdout,mftab,ptype >*/
/* SOURCE ftlookup.for:740 */
/*<       realdqed,dqeu,eda,eua,hbase,q >*/
/* SOURCE ftlookup.for:741 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     IP     - address of the table */
/*     PTYPE  - expected table type */
/*     MFTAB  - table number and later table address of the function */
/*               table that supplies an adjustment factor for flows */
/*     TIME   - elapsed time in seconds from start of run */
/*     EDA    - water surface elevation at downstream node */
/*     EUA    - elevation of water surface at upstream node */
/*     HBASE  - datum for heads */
/*     Q      - flow rate */
/*     DQED   - derivative of flow wrt downstream elevation */
/*     DQEU   - derivative flow wrt upstream elevation */
/*     FREE   - flag for free flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ftlookup.for:759 */
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
/* INCLUDE ftlookup.for:760 */
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
/*     Called subprograms */
/* SOURCE ftlookup.for:763 */
/*<       character*16get_tabid >*/
/* SOURCE ftlookup.for:764 */
/*<       externalget_tabid >*/
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ftlookup.for:767 */
/*<       integerinc >*/
/* SOURCE ftlookup.for:768 */
/*<       parameter(inc=5) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ftlookup.for:771 */
/*<       integerlhu,lp,ntab,tab,type >*/
/* SOURCE ftlookup.for:772 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ftlookup.for:778 */
/*<       externallktab >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ftlookup.for:781 */
/*<    50  >*/
/* SOURCE ftlookup.for:783 */
/*<    52  >*/
/* SOURCE ftlookup.for:785 */
/*<    54  >*/
/* *********************************************************************** */
/*     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT */
/*     POINTERS ARE SET TO THE PROPER VALUES AT START */
/* SOURCE ftlookup.for:791 */
/*<       tab=itab(ip+1) >*/
/* L50: */
/* L52: */
/* L54: */
    tab = itab[*ip + 1];
/* SOURCE ftlookup.for:792 */
/*<       type=itab(ip+2) >*/
    feq_gen_type_d_ = itab[*ip + 2];
/* SOURCE ftlookup.for:793 */
/*<       lhu=itab(ip+4) >*/
    lhu = itab[*ip + 4];
/* SOURCE ftlookup.for:794 */
/*<       hmax=ftab(ip+9) >*/
    hmax = ftab[*ip + 9];
/*      WRITE(STDOUT,*) 'TDLK6: LHU=',LHU,' HMAX=',HMAX */
/*     IMPORTANT: THE DESIGNATIONS UPSTREAM AND DOWNSTREAM REFER TO */
/*     THE TRUE RELATIONSHIP.  THUS EU >= ED ALWAYS. */
/* SOURCE ftlookup.for:801 */
/*<       eu=eua >*/
    eu = *eua;
/* SOURCE ftlookup.for:802 */
/*<       ed=eda >*/
    ed = *eda;
/*      WRITE(STDOUT,*) 'TDLK6: EU=',EU,' ED=',ED */
/* SOURCE ftlookup.for:806 */
/*<       if(type.ne.ptype)then >*/
    if (feq_gen_type_d_ != *ptype) {
/* SOURCE ftlookup.for:807 */
/*<       write(stdout,54)get_tabid(tab),type,ptype >*/
	feq_gen_io_d__104.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__104);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*ptype), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ftlookup.for:808 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ftlookup.for:809 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:811 */
/*<       if(eu.lt.ed)then >*/
    if (eu < ed) {
/* SOURCE ftlookup.for:812 */
/*<       write(stdout,50)get_tabid(tab),eu,ed >*/
	feq_gen_io_d__105.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__105);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&eu, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ed, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ftlookup.for:813 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ftlookup.for:814 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:817 */
/*<       hu=eu-hbase >*/
    hu = static_cast<double>(eu) - *hbase;
/*      WRITE(STDOUT,*) 'TDLK6: HBASE=',HBASE, ' HU=',HU */
/* SOURCE ftlookup.for:820 */
/*<       if(hu.gt.hmax)then >*/
    if (hu > hmax) {
/* SOURCE ftlookup.for:821 */
/*<       write(stdout,52)get_tabid(tab),hu,hmax >*/
	feq_gen_io_d__107.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__107);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&hu, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ftlookup.for:822 */
/*<       drop=eu-ed >*/
	drop = static_cast<double>(eu) - ed;
/* SOURCE ftlookup.for:823 */
/*<       hu=hmax >*/
	hu = hmax;
/* SOURCE ftlookup.for:824 */
/*<       eu=hbase+hmax >*/
	eu = static_cast<double>(*hbase) + hmax;
/* SOURCE ftlookup.for:825 */
/*<       ed=eu-drop >*/
	ed = static_cast<double>(eu) - drop;
/* SOURCE ftlookup.for:826 */
/*<       endif >*/
    }
/*     DETERMINE IF THERE IS FLOW AND IF IT IS KNOWN TO BE FREE */
/* SOURCE ftlookup.for:830 */
/*<       if(eu.lt.hbase)then >*/
    if (eu < *hbase) {
/*       FLOW IS ZERO AND SO ARE DERIVATIVES */
/* SOURCE ftlookup.for:832 */
/*<       q=0.0 >*/
	*q = (float)0.;
/* SOURCE ftlookup.for:833 */
/*<       dqed=0.0 >*/
	*dqed = (float)0.;
/* SOURCE ftlookup.for:834 */
/*<       dqeu=0.0 >*/
	*dqeu = (float)0.;
/* SOURCE ftlookup.for:835 */
/*<       free=0 >*/
	*free = 0;
/* SOURCE ftlookup.for:836 */
/*<       return >*/
	return 0;
/* SOURCE ftlookup.for:837 */
/*<       endif >*/
    }
/*     UPSTREAM LEVEL IS ABOVE BASE.  FIND THE UPSTREAM LEVEL INTERVAL */
/*     CONTAINING EU */
/* SOURCE ftlookup.for:842 */
/*<       if(hu.ge.ftab(lhu))then >*/
    if (hu >= ftab[lhu]) {
/* SOURCE ftlookup.for:843 */
/*<   100 continue >*/
L100:
/* SOURCE ftlookup.for:844 */
/*<       if(hu.le.ftab(lhu+inc))goto120 >*/
	if (hu <= ftab[lhu + 5]) {
	    goto L120;
	}
/* SOURCE ftlookup.for:845 */
/*<       lhu=lhu+inc >*/
	lhu += 5;
/* SOURCE ftlookup.for:846 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ftlookup.for:847 */
/*<       else >*/
    } else {
/* SOURCE ftlookup.for:848 */
/*<   110 continue >*/
L110:
/* SOURCE ftlookup.for:849 */
/*<       lhu=lhu-inc >*/
	lhu += -5;
/* SOURCE ftlookup.for:850 */
/*<       if(hu.ge.ftab(lhu))goto120 >*/
	if (hu >= ftab[lhu]) {
	    goto L120;
	}
/* SOURCE ftlookup.for:851 */
/*<       goto110 >*/
	goto L110;
/* SOURCE ftlookup.for:852 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:853 */
/*<   120 continue >*/
L120:
/* SOURCE ftlookup.for:854 */
/*<       itab(ip+4)=lhu >*/
    itab[*ip + 4] = lhu;
/*     ELIMINATE SPECIAL CASE OF FREE FLOW TO ALLOW THE HEAD DROP TO */
/*     BE LARGER THAN THE UPSTREAM HEAD.  THIS MEANS THAT THE DOWNSTREAM */
/*     HEAD COULD BE BELOW THE ZERO FLOW LEVEL. */
/*      IF(ED.LT.HBASE) THEN */
/*       FREE FLOW BECAUSE DOWNSTREAM LEVEL IS BELOW BASE */
/*        HUL = FTAB(LHU) */
/*        HUR = FTAB(LHU+INC) */
/*        QL = FTAB(LHU+4) */
/*        QR = FTAB(LHU+INC+4) */
/*        DQEU = (QR - QL)/(HUR - HUL) */
/*        Q = QL + DQEU*(HU - HUL) */
/*        DQED = 0.0 */
/*        FREE = 1 */
/* C        WRITE(STDOUT,*) 'TDLK6: SIMPLE FREE FLOW' */
/* C        WRITE(STDOUT,*) ' HUL=',HUL,' HUR=',HUR,' QL=',QL,' QR=',QR */
/* C        WRITE(STDOUT,*) 'Q =',Q,' DQEU=',DQEU */
/*        GOTO 9000 */
/*        RETURN */
/*      ENDIF */
/*     GENERAL CASE. FREE FLOW MAY RESULT IF THE DOWNSTREAM HEAD IS */
/*     SMALL ENOUGH */
/*     FIND THE HEAD DROP CORRESPONDING TO HU */
/* SOURCE ftlookup.for:885 */
/*<       hul=ftab(lhu) >*/
    hul = ftab[lhu];
/* SOURCE ftlookup.for:886 */
/*<       hur=ftab(lhu+inc) >*/
    hur = ftab[lhu + 5];
/* SOURCE ftlookup.for:887 */
/*<       hdropl=ftab(lhu+1) >*/
    hdropl = ftab[lhu + 1];
/* SOURCE ftlookup.for:888 */
/*<       hdropr=ftab(lhu+inc+1) >*/
    hdropr = ftab[lhu + 6];
/* SOURCE ftlookup.for:889 */
/*<       ddropu=(hdropr-hdropl)/(hur-hul) >*/
    ddropu = static_cast<double>((static_cast<double>(hdropr) - hdropl)) / (static_cast<double>(hur) - hul);
/* SOURCE ftlookup.for:890 */
/*<       thdrop=hdropl+ddropu*(hu-hul) >*/
    thdrop = static_cast<double>(hdropl) + static_cast<double>(ddropu) * (static_cast<double>(hu) - hul);
/*     THDROP IS THE TABLE VALUE OF THE HEAD DROP TO FREE FLOW */
/*     FOR THE CURRENT UPSTREAM LEVEL */
/*     HDROP IS THE CURRENT HEAD DROP */
/* SOURCE ftlookup.for:895 */
/*<       hdrop=eu-ed >*/
    hdrop = static_cast<double>(eu) - ed;
/* SOURCE ftlookup.for:898 */
/*<       if(hdrop.ge.thdrop)then >*/
    if (hdrop >= thdrop) {
/*       FREE FLOW */
/* SOURCE ftlookup.for:901 */
/*<       ql=ftab(lhu+4) >*/
	ql = ftab[lhu + 4];
/* SOURCE ftlookup.for:902 */
/*<       qr=ftab(lhu+inc+4) >*/
	qr = ftab[lhu + 9];
/* SOURCE ftlookup.for:903 */
/*<       dqeu=(qr-ql)/(hur-hul) >*/
	*dqeu = static_cast<double>((static_cast<double>(qr) - ql)) / (static_cast<double>(hur) - hul);
/* SOURCE ftlookup.for:904 */
/*<       q=ql+dqeu*(hu-hul) >*/
	*q = static_cast<double>(ql) + static_cast<double>(*dqeu) * (static_cast<double>(hu) - hul);
/* SOURCE ftlookup.for:905 */
/*<       dqed=0.0 >*/
	*dqed = (float)0.;
/* SOURCE ftlookup.for:906 */
/*<       free=1 >*/
	*free = 1;
/*        WRITE(STDOUT,*) 'TDLK6: COMPLEX FREE FLOW' */
/*        WRITE(STDOUT,*) ' HUL=',HUL,' HUR=',HUR,' QL=',QL,' QR=',QR */
/*        WRITE(STDOUT,*) 'Q =',Q,' DQEU=',DQEU */
/* SOURCE ftlookup.for:911 */
/*<       goto9000 >*/
	goto L9000;
/*        RETURN */
/* SOURCE ftlookup.for:913 */
/*<       endif >*/
    }
/*     SUBMERGED FLOW HERE */
/*     FIND THE FRACTION OF FREE FLOW DROP REPRESENTED BY THE CURRENT DROP */
/* SOURCE ftlookup.for:919 */
/*<       p=hdrop/thdrop >*/
    p = static_cast<double>(hdrop) / thdrop;
/*      WRITE(STDOUT,*) 'TDLK6; SUBMERGED FLOW' */
/*      WRITE(STDOUT,*) ' HDROP=',HDROP,' THDROP=',THDROP,' P=',P */
/*     WE HAVE TWO LINES OF CONSTANT UPSTREAM LEVEL.  ONE IS ON THE LEFT */
/*     AND WILL BE DESIGNATED BY THE SUFFIX L.  THE OTHER IS ON THE RIGHT */
/*     AND WILL BE DESIGNATED BY THE SUFFIX R.  ON EACH LINE THERE WILL BE */
/*     A POINT ABOVE AND BELOW P.  THE ONE ABOVE IS DENOTED AS U AND THE */
/*     ONE BELOW AS D.  WE INTERPOLATE IN EACH LINE WITH P AND THEN */
/*     INTERPOLATE ON THE UPSTREAM LEVEL. */
/*     DO SEARCH ALONG THE LEFT LINE OF P VERSUS Q */
/* SOURCE ftlookup.for:935 */
/*<       lp=itab(lhu+3) >*/
    lp = itab[lhu + 3];
/*      WRITE(STDOUT,*) 'LEFT LINE START LP=',LP */
/* SOURCE ftlookup.for:938 */
/*<       if(p.ge.ftab(lp))then >*/
    if (p >= ftab[lp]) {
/* SOURCE ftlookup.for:939 */
/*<   130 continue >*/
L130:
/* SOURCE ftlookup.for:940 */
/*<       if(p.le.ftab(lp+2))goto150 >*/
	if (p <= ftab[lp + 2]) {
	    goto L150;
	}
/* SOURCE ftlookup.for:941 */
/*<       lp=lp+2 >*/
	lp += 2;
/* SOURCE ftlookup.for:942 */
/*<       goto130 >*/
	goto L130;
/* SOURCE ftlookup.for:943 */
/*<       else >*/
    } else {
/* SOURCE ftlookup.for:944 */
/*<   140 continue >*/
L140:
/* SOURCE ftlookup.for:945 */
/*<       lp=lp-2 >*/
	lp += -2;
/* SOURCE ftlookup.for:946 */
/*<       if(p.ge.ftab(lp))goto150 >*/
	if (p >= ftab[lp]) {
	    goto L150;
	}
/* SOURCE ftlookup.for:947 */
/*<       goto140 >*/
	goto L140;
/* SOURCE ftlookup.for:948 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:949 */
/*<   150 continue >*/
L150:
/* SOURCE ftlookup.for:950 */
/*<       itab(lhu+3)=lp >*/
    itab[lhu + 3] = lp;
/* SOURCE ftlookup.for:952 */
/*<       pld=ftab(lp) >*/
    pld = ftab[lp];
/* SOURCE ftlookup.for:953 */
/*<       qld=ftab(lp+1) >*/
    qld = ftab[lp + 1];
/* SOURCE ftlookup.for:954 */
/*<       plu=ftab(lp+2) >*/
    plu = ftab[lp + 2];
/* SOURCE ftlookup.for:955 */
/*<       qlu=ftab(lp+3) >*/
    qlu = ftab[lp + 3];
/* SOURCE ftlookup.for:956 */
/*<       dqlp=(qlu-qld)/(plu-pld) >*/
    dqlp = static_cast<double>((static_cast<double>(qlu) - qld)) / (static_cast<double>(plu) - pld);
/* SOURCE ftlookup.for:957 */
/*<       ql=qld+dqlp*(p-pld) >*/
    ql = static_cast<double>(qld) + static_cast<double>(dqlp) * (static_cast<double>(p) - pld);
/*      WRITE(STDOUT,*) ' PLD=',PLD,' QLD=',QLD,' LP=',LP */
/*      WRITE(STDOUT,*) ' PLU=',PLU,' QLU=',QLU,' QL=',QL */
/*     DO SEARCH ALONG THE RIGHT LINE */
/* SOURCE ftlookup.for:963 */
/*<       lp=itab(lhu+inc+3) >*/
    lp = itab[lhu + 8];
/*      WRITE(STDOUT,*) 'RIGHT LINE START LP=',LP */
/* SOURCE ftlookup.for:965 */
/*<       if(p.ge.ftab(lp))then >*/
    if (p >= ftab[lp]) {
/* SOURCE ftlookup.for:966 */
/*<   160 continue >*/
L160:
/* SOURCE ftlookup.for:967 */
/*<       if(p.le.ftab(lp+2))goto180 >*/
	if (p <= ftab[lp + 2]) {
	    goto L180;
	}
/* SOURCE ftlookup.for:968 */
/*<       lp=lp+2 >*/
	lp += 2;
/* SOURCE ftlookup.for:969 */
/*<       goto160 >*/
	goto L160;
/* SOURCE ftlookup.for:970 */
/*<       else >*/
    } else {
/* SOURCE ftlookup.for:971 */
/*<   170 continue >*/
L170:
/* SOURCE ftlookup.for:972 */
/*<       lp=lp-2 >*/
	lp += -2;
/* SOURCE ftlookup.for:973 */
/*<       if(p.ge.ftab(lp))goto180 >*/
	if (p >= ftab[lp]) {
	    goto L180;
	}
/* SOURCE ftlookup.for:974 */
/*<       goto170 >*/
	goto L170;
/* SOURCE ftlookup.for:975 */
/*<       endif >*/
    }
/* SOURCE ftlookup.for:976 */
/*<   180 continue >*/
L180:
/* SOURCE ftlookup.for:978 */
/*<       itab(lhu+inc+3)=lp >*/
    itab[lhu + 8] = lp;
/* SOURCE ftlookup.for:980 */
/*<       prd=ftab(lp) >*/
    prd = ftab[lp];
/* SOURCE ftlookup.for:981 */
/*<       qrd=ftab(lp+1) >*/
    qrd = ftab[lp + 1];
/* SOURCE ftlookup.for:982 */
/*<       pru=ftab(lp+2) >*/
    pru = ftab[lp + 2];
/* SOURCE ftlookup.for:983 */
/*<       qru=ftab(lp+3) >*/
    qru = ftab[lp + 3];
/* SOURCE ftlookup.for:984 */
/*<       dqrp=(qru-qrd)/(pru-prd) >*/
    dqrp = static_cast<double>((static_cast<double>(qru) - qrd)) / (static_cast<double>(pru) - prd);
/* SOURCE ftlookup.for:985 */
/*<       qr=qrd+dqrp*(p-prd) >*/
    qr = static_cast<double>(qrd) + static_cast<double>(dqrp) * (static_cast<double>(p) - prd);
/*      WRITE(STDOUT,*) ' PRD=',PRD,' QRD=',QRD,' LP=',LP */
/*      WRITE(STDOUT,*) ' PRU=',PRU,' QRU=',QRU,' QR=',QR */
/*      WRITE(STDOUT,*) 'TDLK6: QL=',QL,' QR=',QR */
/*     COMPUTE THE FLOW AND ITS DERIVATIVES */
/* SOURCE ftlookup.for:993 */
/*<       dqhu=(qr-ql)/(hur-hul) >*/
    dqhu = static_cast<double>((static_cast<double>(qr) - ql)) / (static_cast<double>(hur) - hul);
/* SOURCE ftlookup.for:994 */
/*<       q=ql+dqhu*(hu-hul) >*/
    *q = static_cast<double>(ql) + static_cast<double>(dqhu) * (static_cast<double>(hu) - hul);
/* SOURCE ftlookup.for:996 */
/*<       fac=(hu-hul)/(hur-hul) >*/
    fac = static_cast<double>((static_cast<double>(hu) - hul)) / (static_cast<double>(hur) - hul);
/* SOURCE ftlookup.for:997 */
/*<       dpeu=(1.0-p*ddropu)/thdrop >*/
    dpeu = static_cast<double>((static_cast<double>((float)1.) - static_cast<double>(p) * ddropu)) / thdrop;
/* SOURCE ftlookup.for:998 */
/*<       dqleu=dqlp*dpeu >*/
    dqleu = static_cast<double>(dqlp) * dpeu;
/* SOURCE ftlookup.for:999 */
/*<       dqreu=dqrp*dpeu >*/
    dqreu = static_cast<double>(dqrp) * dpeu;
/* SOURCE ftlookup.for:1000 */
/*<       dqeu=dqleu+dqhu+fac*(dqreu-dqleu) >*/
    *dqeu = static_cast<double>(static_cast<double>(dqleu) + dqhu) + static_cast<double>(fac) * (static_cast<double>(dqreu) - dqleu);
/* SOURCE ftlookup.for:1002 */
/*<       dqled=-dqlp/thdrop >*/
    dqled = static_cast<double>(-dqlp) / thdrop;
/* SOURCE ftlookup.for:1003 */
/*<       dqred=-dqrp/thdrop >*/
    dqred = static_cast<double>(-dqrp) / thdrop;
/* SOURCE ftlookup.for:1004 */
/*<       dqed=dqled+fac*(dqred-dqled) >*/
    *dqed = static_cast<double>(dqled) + static_cast<double>(fac) * (static_cast<double>(dqred) - dqled);
/* SOURCE ftlookup.for:1006 */
/*<       free=0 >*/
    *free = 0;
/* SOURCE ftlookup.for:1008 */
/*<  9000 continue >*/
L9000:
/*      WRITE(STDOUT,*) 'TDLK6: Q=',Q,' DQEU=',DQEU,' DQED=',DQED */
/* SOURCE ftlookup.for:1010 */
/*<       return >*/
    return 0;
/* SOURCE ftlookup.for:1012 */
/*<       end >*/
} /* tdlk6_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
