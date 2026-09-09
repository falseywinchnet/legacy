#include "../support/format.hpp"
/* tabstore.f -- translated by f2c (version 20240504).
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

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON xtadd_ is declared in common.hpp. */

#define xtadd_1 xtadd_

/* COMMON xtaddc_ is declared in common.hpp. */

#define xtaddc_1 xtaddc_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* COMMON flitems_ is declared in common.hpp. */

#define flitems_1 flitems_

/* COMMON grid_datum__ is declared in common.hpp. */

#define feq_gen_grid_datum_d_1 feq_gen_grid_datum_d_

/* Table of constant values */

static integer feq_gen_c_d_6 = 6;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_25 = 25;
static integer feq_gen_c_d_8 = 8;
static real c_b188 = (float)0.;
static real c_b199 = (float)1.;
static integer feq_gen_c_d_14 = 14;
static real c_b728 = (float)-1.;




/* SOURCE tabstore.for:4 */
/*<        >*/
/* Subroutine */ int twod13get_(integer *stdout, integer *table, integer *nhu,
	 integer *nfrac, real *feq_storage_huvec, real *feq_storage_fdrop, real *feq_storage_pfdvec, real *feq_storage_qmat, 
	real *hdatum, integer *feq_gen_type_d_, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    integer feq_gen_i_d_, j, k, ip, phu;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ppfd;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer qpnt;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__5 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Get a 2-D table of type 13 from FTAB/ITAB and put it in */
/*     the computational matrices. */
/* SOURCE tabstore.for:14 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE tabstore.for:17 */
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
/* SOURCE tabstore.for:20 */
/*<       integereflag,nfrac,nhu,stdout,table,type >*/
/* SOURCE tabstore.for:21 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TABLE  - Table number */
/*     NHU    - Number of positive upstream heads. */
/*     NFRAC  - Number of fractions for defining partial free drop */
/*               values including zero free drop. */
/*     HUVEC  - Vector of upstream heads */
/*     FDROP  - Free drop values */
/*     PFDVEC - Partial free drop vector */
/*     QMAT   - Flowrate with the rows indexed by upstream head */
/*              (1:NHU) and the columns by partial free drop values */
/*              (1:NFRAC) */
/*     HDATUM - Datum for measuring head */
/*     TYPE   - Table type */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tabstore.for:41 */
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
/* SOURCE tabstore.for:45 */
/*<       integeri,ip,j,k,phu,ppfd,qpnt >*/
/*     ****************************************************************** */
/* *********************************************************************** */
/* SOURCE tabstore.for:48 */
/*<       ip=table >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> qmat(feq_storage_qmat, 152);

    feq::IndexedPointer<real> pfdvec(feq_storage_pfdvec, 1);

    feq::IndexedPointer<real> fdrop(feq_storage_fdrop, 1);

    feq::IndexedPointer<real> huvec(feq_storage_huvec, 1);

    /* Function Body */
    ip = *table;
/* SOURCE tabstore.for:49 */
/*<       callchktab(6,stdout,ftpnt,mftnum,ip,eflag) >*/
    chktab_(&feq_gen_c_d_6, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &ip, eflag);
/* SOURCE tabstore.for:55 */
/*<       hdatum=ftab(ip) >*/
    *hdatum = ftab[ip];
/* SOURCE tabstore.for:56 */
/*<       table=itab(ip+1) >*/
    *table = itab[ip + 1];
/* SOURCE tabstore.for:57 */
/*<       type=itab(ip+2) >*/
    *feq_gen_type_d_ = itab[ip + 2];
/* SOURCE tabstore.for:59 */
/*<       write(stdout,*)' TWOD13GET: TABLE=',table,' TYPE=',type >*/
    feq_gen_io_d__5.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__5);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TWOD13GET: TABLE="), (ftnlen)18);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*table), (ftnlen)sizeof(integer));
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*feq_gen_type_d_), (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE tabstore.for:60 */
/*<       phu=itab(ip+3) >*/
    phu = itab[ip + 3];
/* SOURCE tabstore.for:62 */
/*<       ppfd=itab(ip+5) >*/
    ppfd = itab[ip + 5];
/* SOURCE tabstore.for:64 */
/*<       write(stdout,*)' TWOD13GET: PHU=',phu,' PPFD=',ppfd >*/
    feq_gen_io_d__8.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__8);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TWOD13GET: PHU="), (ftnlen)16);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&phu, (ftnlen)sizeof(integer));
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PPFD="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ppfd, (ftnlen)sizeof(integer));
    e_wsle();
/*     Compute the number of nonzero upstream heads */
/* SOURCE tabstore.for:67 */
/*<       nhu=(ppfd-phu)/4-1 >*/
    *nhu = (ppfd - phu) / 4 - 1;
/*     Compute the number of partial free drops */
/* SOURCE tabstore.for:70 */
/*<       nfrac=itab(phu+3) >*/
    *nfrac = itab[phu + 3];
/* SOURCE tabstore.for:72 */
/*<       write(stdout,*)' TWOD13GET: NHU=',nhu,' NFRAC=',nfrac >*/
    feq_gen_io_d__9.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__9);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TWOD13GET: NHU="), (ftnlen)16);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*nhu), (ftnlen)sizeof(integer));
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NFRAC="), (ftnlen)7);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*nfrac), (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE tabstore.for:73 */
/*<       k=phu+4 >*/
    k = phu + 4;
/* SOURCE tabstore.for:74 */
/*<       do730i=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:75 */
/*<       huvec(i)=ftab(k) >*/
	huvec[feq_gen_i_d_] = ftab[k];
/* SOURCE tabstore.for:76 */
/*<       fdrop(i)=ftab(k+1) >*/
	fdrop[feq_gen_i_d_] = ftab[k + 1];
/* SOURCE tabstore.for:77 */
/*<       qmat(i,nfrac)=ftab(k+2) >*/
	qmat[feq_gen_i_d_ + *nfrac * 151] = ftab[k + 2];
/* SOURCE tabstore.for:78 */
/*<       k=k+4 >*/
	k += 4;
/* SOURCE tabstore.for:79 */
/*<   730 continue >*/
/* L730: */
    }
/*     Restore the partial free drops. */
/* SOURCE tabstore.for:83 */
/*<       do750i=1,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:84 */
/*<       pfdvec(i)=ftab(ppfd+i-1) >*/
	pfdvec[feq_gen_i_d_] = ftab[ppfd + feq_gen_i_d_ - 1];
/* SOURCE tabstore.for:85 */
/*<   750 continue >*/
/* L750: */
    }
/*     Restore the flows for the non-zero upstream heads. */
/* SOURCE tabstore.for:88 */
/*<       qpnt=ppfd+nfrac >*/
    qpnt = ppfd + *nfrac;
/* SOURCE tabstore.for:89 */
/*<       do802i=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:90 */
/*<       ip=qpnt+i*nfrac >*/
	ip = qpnt + feq_gen_i_d_ * *nfrac;
/* SOURCE tabstore.for:91 */
/*<       do801j=1,nfrac >*/
	feq_gen_i_d_2 = *nfrac;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE tabstore.for:92 */
/*<       qmat(i,j)=ftab(ip+j-1) >*/
	    qmat[feq_gen_i_d_ + j * 151] = ftab[ip + j - 1];
/* SOURCE tabstore.for:93 */
/*<   801 continue >*/
/* L801: */
	}
/* SOURCE tabstore.for:94 */
/*<   802 continue >*/
/* L802: */
    }
/* SOURCE tabstore.for:97 */
/*<       return >*/
    return 0;
/* SOURCE tabstore.for:98 */
/*<       end >*/
} /* twod13get_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tabstore.for:102 */
/*<        >*/
/* Subroutine */ int twod13put_(integer *stdout, integer *table, integer *nhu,
	 integer *nfrac, real *feq_storage_huvec, real *feq_storage_fdrop, real *feq_storage_pfdvec, real *feq_storage_qmat, 
	real *hdatum, integer *feq_gen_type_d_, integer *ftp, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* In TWOD13PUT: FTP+N=\002,i10\
,\002 IP+NFRAC=\002,i10)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, j, k, n, ip;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer phu;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ppfd;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer qpnt;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Store a two-D flow table of  type 13 in the FTAB/ITAB */
/*     structure given the computational matrices. */
/* SOURCE tabstore.for:112 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE tabstore.for:115 */
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
/* SOURCE tabstore.for:118 */
/*<       integereflag,ftp,nfrac,nhu,stdout,table,type >*/
/* SOURCE tabstore.for:119 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TABLE  - Table number */
/*     NHU    - Number of positive upstream heads. */
/*     NFRAC  - Number of fractions for defining partial free drop */
/*               values including zero free drop. */
/*     HUVEC  - Vector of upstream heads */
/*     FDROP  - Free drop values */
/*     PFDVEC - Partial free drop vector */
/*     QMAT   - Flowrate with the rows indexed by upstream head */
/*              (1:NHU) and the columns by partial free drop values */
/*              (1:NFRAC) */
/*     HDATUM - Datum for measuring head */
/*     TYPE   - Table type */
/*     FTP    - Pointer to next available entry in FTAB/ITAB */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tabstore.for:140 */
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
/* SOURCE tabstore.for:144 */
/*<       integeri,ip,j,k,n,phu,ppfd,qpnt >*/
/*     ****************************************************************** */
/* *********************************************************************** */
/* SOURCE tabstore.for:147 */
/*<       if(ftp+10.ge.mrftab)callkil(10,ftp,eflag) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> qmat(feq_storage_qmat, 152);

    feq::IndexedPointer<real> pfdvec(feq_storage_pfdvec, 1);

    feq::IndexedPointer<real> fdrop(feq_storage_fdrop, 1);

    feq::IndexedPointer<real> huvec(feq_storage_huvec, 1);

    /* Function Body */
    if (*ftp + 10 >= 13000001) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/*     Store the datum for heads for this table. */
/*      WRITE(STDOUT,*) ' TABLE=',TABLE */
/* SOURCE tabstore.for:153 */
/*<       if(ftpnt(table).ne.0)then >*/
    if (ftablea_1.ftpnt[*table - 1] != 0) {
/* SOURCE tabstore.for:154 */
/*<       callkil(25,table,eflag) >*/
	kil_(&feq_gen_c_d_25, table, eflag);
/* SOURCE tabstore.for:157 */
/*<       stop'Abnormal stop. Error found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error found."), (ftnlen)27);
/* SOURCE tabstore.for:158 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:159 */
/*<       ftpnt(table)=ftp >*/
    ftablea_1.ftpnt[*table - 1] = *ftp;
/* SOURCE tabstore.for:160 */
/*<       ftab(ftp)=hdatum >*/
    ftab[*ftp] = *hdatum;
/* SOURCE tabstore.for:161 */
/*<       itab(ftp+1)=table >*/
    itab[*ftp + 1] = *table;
/* SOURCE tabstore.for:162 */
/*<       itab(ftp+2)=type >*/
    itab[*ftp + 2] = *feq_gen_type_d_;
/*     Store 2-D table of type 13 in FTAB/ITAB. */
/*     Set pointer values for the upstream head */
/* SOURCE tabstore.for:167 */
/*<       phu=ftp+10 >*/
    phu = *ftp + 10;
/*      WRITE(STDOUT,*) ' PHU=',PHU */
/*     Store pointer to the start of the downstream heads. */
/* SOURCE tabstore.for:172 */
/*<       itab(ftp+3)=phu >*/
    itab[*ftp + 3] = phu;
/*     Initialize the value of the last access to the free head */
/*     list to the zero head value. */
/* SOURCE tabstore.for:176 */
/*<       itab(ftp+4)=phu >*/
    itab[*ftp + 4] = phu;
/*     CHECK FOR SPACE */
/* SOURCE tabstore.for:179 */
/*<       n=10+4*(nhu+1)+(nhu+2)*nfrac >*/
    n = (*nhu + 1 << 2) + 10 + (*nhu + 2) * *nfrac;
/* SOURCE tabstore.for:180 */
/*<       if(ftp+n.ge.mrftab)callkil(10,ftp,eflag) >*/
    if (*ftp + n >= 13000001) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/*     Find and store the base pointer for partial free drops. */
/* SOURCE tabstore.for:186 */
/*<       ppfd=phu+4*(nhu+1) >*/
    ppfd = phu + (*nhu + 1 << 2);
/*      WRITE(STDOUT,*) ' PPFD=',PPFD */
/* SOURCE tabstore.for:188 */
/*<       itab(ftp+5)=ppfd >*/
    itab[*ftp + 5] = ppfd;
/*     Initialize the last access pointer into the partial free drop */
/*     sequence */
/* SOURCE tabstore.for:191 */
/*<       itab(ftp+6)=ppfd >*/
    itab[*ftp + 6] = ppfd;
/*     Offset locations 7 and 8 are currently not used. */
/*     Store the maximum upstream head */
/* SOURCE tabstore.for:197 */
/*<       ftab(ftp+9)=huvec(nhu) >*/
    ftab[*ftp + 9] = huvec[*nhu];
/*     Compute the base pointer for the flow in the table */
/* SOURCE tabstore.for:200 */
/*<       qpnt=ppfd+nfrac >*/
    qpnt = ppfd + *nfrac;
/*      WRITE(STDOUT,*) ' QPNT=',QPNT */
/*     Store the values for the upstream heads, and the corresponding */
/*     drop to free flow, the free flow value, and the offset to */
/*     the flows for each upstream head. */
/*     Store the values for zero upstream head */
/* SOURCE tabstore.for:209 */
/*<       ftab(phu)=0.0 >*/
    ftab[phu] = (float)0.;
/* SOURCE tabstore.for:210 */
/*<       ftab(phu+1)=0.0 >*/
    ftab[phu + 1] = (float)0.;
/* SOURCE tabstore.for:211 */
/*<       ftab(phu+2)=0.0 >*/
    ftab[phu + 2] = (float)0.;
/*     Store the offset between the origin of the partial free */
/*     drop sequence and the origin of the flows at zero upstream */
/*     head so that a single addition can be used to find the */
/*     flows once the location of the partial free drop argument */
/*     is found in the partial free drop sequence. */
/* SOURCE tabstore.for:218 */
/*<       itab(phu+3)=qpnt-ppfd >*/
    itab[phu + 3] = qpnt - ppfd;
/*      WRITE(STDOUT,*) ' OFFSET AT ORIGIN=',ITAB(PHU+3) */
/* SOURCE tabstore.for:221 */
/*<       k=phu+4 >*/
    k = phu + 4;
/* SOURCE tabstore.for:222 */
/*<       do730i=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:223 */
/*<       ftab(k)=huvec(i) >*/
	ftab[k] = huvec[feq_gen_i_d_];
/* SOURCE tabstore.for:224 */
/*<       ftab(k+1)=fdrop(i) >*/
	ftab[k + 1] = fdrop[feq_gen_i_d_];
/* SOURCE tabstore.for:225 */
/*<       ftab(k+2)=qmat(i,nfrac) >*/
	ftab[k + 2] = qmat[feq_gen_i_d_ + *nfrac * 151];
/* SOURCE tabstore.for:226 */
/*<       itab(k+3)=qpnt-ppfd+i*nfrac >*/
	itab[k + 3] = qpnt - ppfd + feq_gen_i_d_ * *nfrac;
/* SOURCE tabstore.for:227 */
/*<       k=k+4 >*/
	k += 4;
/* SOURCE tabstore.for:228 */
/*<   730 continue >*/
/* L730: */
    }
/*     Store the partial free drops. */
/* SOURCE tabstore.for:233 */
/*<       do750i=1,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:234 */
/*<       ftab(ppfd+i-1)=pfdvec(i) >*/
	ftab[ppfd + feq_gen_i_d_ - 1] = pfdvec[feq_gen_i_d_];
/* SOURCE tabstore.for:235 */
/*<   750 continue >*/
/* L750: */
    }
/*     Store the zero flows for zero upstream head */
/* SOURCE tabstore.for:239 */
/*<       do800i=qpnt,qpnt+nfrac-1 >*/
    feq_gen_i_d_1 = qpnt + *nfrac - 1;
    for (feq_gen_i_d_ = qpnt; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:240 */
/*<       ftab(i)=0.0 >*/
	ftab[feq_gen_i_d_] = (float)0.;
/* SOURCE tabstore.for:241 */
/*<   800 continue >*/
/* L800: */
    }
/*     Store the flows for the non-zero upstream heads.  Q contains */
/*     the zero flow at zero partial free drop. */
/* SOURCE tabstore.for:246 */
/*<       do802i=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:247 */
/*<       ip=qpnt+i*nfrac >*/
	ip = qpnt + feq_gen_i_d_ * *nfrac;
/* SOURCE tabstore.for:248 */
/*<       do801j=1,nfrac >*/
	feq_gen_i_d_2 = *nfrac;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE tabstore.for:249 */
/*<       ftab(ip+j-1)=qmat(i,j) >*/
	    ftab[ip + j - 1] = qmat[feq_gen_i_d_ + j * 151];
/* SOURCE tabstore.for:250 */
/*<   801 continue >*/
/* L801: */
	}
/* SOURCE tabstore.for:251 */
/*<   802 continue >*/
/* L802: */
    }
/*     Update the pointer into FTAB/ITAB */
/* SOURCE tabstore.for:254 */
/*<       if(ftp+n.ne.ip+nfrac)then >*/
    if (*ftp + n != ip + *nfrac) {
/* SOURCE tabstore.for:255 */
/*<       write(stdout,50)ftp+n,ip+nfrac >*/
	feq_gen_io_d__25.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__25);
	feq_gen_i_d_1 = *ftp + n;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	feq_gen_i_d_2 = ip + *nfrac;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE tabstore.for:256 */
/*<    50 format(/,' *BUG:XXX* In TWOD13PUT: FTP+N=',i10,' IP+NFRAC=',i10) >*/
/* SOURCE tabstore.for:257 */
/*<       stop'Abnormal stop: Bug found' >*/
	s_stop(const_cast<char*>("Abnormal stop: Bug found"), (ftnlen)24);
/* SOURCE tabstore.for:258 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:260 */
/*<       ftp=ip+nfrac >*/
    *ftp = ip + *nfrac;
/* SOURCE tabstore.for:262 */
/*<       return >*/
    return 0;
/* SOURCE tabstore.for:263 */
/*<       end >*/
} /* twod13put_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tabstore.for:267 */
/*<       subroutinestbout(stdout,numsec,stl,offset,sinu,nflnam,flntab) >*/
/* Subroutine */ int stbout_(integer *stdout, integer *numsec, real *feq_storage_stl, 
	real *feq_storage_offset, real *feq_storage_sinu, integer *nflnam, char *feq_storage_flntab, ftnlen 
	flntab_len)
{
    /* Format strings */
    static char fmt_52[] = "(/,\002  Item\002,9(1x,a8))";
    static char fmt_54[] = "(1x,\002 STAT\002,9(1x,a8))";
    static char fmt_56[] = "(1x,\002 OFFS\002,9(1x,a8))";
    static char fmt_58[] = "(1x,\002 SINU\002,9(1x,a8))";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsfi(icilist *), e_wsfi(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();

    /* Local variables */
    integer feq_gen_i_d_, j, nfl;
    char out[8*11], chr5[5];
    extern /* Subroutine */ int mkfmt_(real *, integer *, char *, ftnlen);
    integer snout;
    char staout[7];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__37 = { 0, 0, 0, fmt_58, 0 };


/*     + + + PURPOSE + + + */
/*     Output the sinuousity table.  If all sinuousity values */
/*     are undefined for a given cross section, do not output any */
/*     values.  If one or more are defined output all values */
/*     giving a blank for values that are not defined. */
/* SOURCE tabstore.for:277 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE tabstore.for:280 */
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
/* SOURCE tabstore.for:283 */
/*<       integernflnam,numsec,stdout >*/
/* SOURCE tabstore.for:284 */
/*<       realoffset(pmxsec,pmxnfl),sinu(pmxsec,pmxnfl),stl(pmxsec,pmxnfl) >*/
/* SOURCE tabstore.for:286 */
/*<       characterflntab(nflnam)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NUMSEC - Number of cross sections in sequence */
/*     STL    - Table for flow line stations */
/*     OFFSET - Offsets for the sinuousity values */
/*     SINU   - Table of sinuousities */
/*     NFLNAM - Number of flow line names */
/*     FLNTAB - Flow line name table */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tabstore.for:298 */
/*<       integeri,j,nfl,snout >*/
/* SOURCE tabstore.for:299 */
/*<       characterchr5*5,out(pmxnfl)*8,staout*7 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE tabstore.for:302 */
/*<       intrinsicindex >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tabstore.for:305 */
/*<       externalmkfmt >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tabstore.for:308 */
/*<    52 format(/,'  Item',9(1x,a8)) >*/
/* SOURCE tabstore.for:309 */
/*<    54 format(1x,' STAT',9(1x,a8)) >*/
/* SOURCE tabstore.for:310 */
/*<    56 format(1x,' OFFS',9(1x,a8)) >*/
/* SOURCE tabstore.for:311 */
/*<    58 format(1x,' SINU',9(1x,a8)) >*/
/* *********************************************************************** */
/*     SET UP THE STATION OUTPUT FORMAT */
/* SOURCE tabstore.for:314 */
/*<       staout(1:1)='(' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> stl(feq_storage_stl, 401);

    feq::IndexedPointer<real> offset(feq_storage_offset, 401);

    feq::IndexedPointer<real> sinu(feq_storage_sinu, 401);

    feq::IndexedPointer<char> flntab(feq_storage_flntab, 8);

    /* Function Body */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
    *(unsigned char *)staout = '(';
/* SOURCE tabstore.for:315 */
/*<       staout(7:7)=')' >*/
    *(unsigned char *)&staout[6] = ')';
/*     OUTPUT THE TABLE LABEL AND THE HEADING FOR THE TABLE */
/* SOURCE tabstore.for:318 */
/*<       do90j=1,nflnam >*/
    feq_gen_i_d_1 = *nflnam;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE tabstore.for:319 */
/*<       i=index(flntab(j),' ')-1 >*/
	feq_gen_i_d_ = i_indx(flntab + (j << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) - 1;
/* SOURCE tabstore.for:320 */
/*<       if(i.eq.-1)i=8 >*/
	if (feq_gen_i_d_ == -1) {
	    feq_gen_i_d_ = 8;
	}
/* SOURCE tabstore.for:321 */
/*<       out(j)=' ' >*/
	s_copy(out + (j - 1 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tabstore.for:322 */
/*<       out(j)(8-i+1:8)=flntab(j)(1:i) >*/
	feq_gen_i_d_2 = 8 - feq_gen_i_d_;
	s_copy(out + ((j - 1 << 3) + feq_gen_i_d_2), flntab + (j << 3), 8 - feq_gen_i_d_2, feq_gen_i_d_);
/* SOURCE tabstore.for:323 */
/*<    90 continue >*/
/* L90: */
    }
/* SOURCE tabstore.for:324 */
/*<       write(stdout,52)(out(j),j=1,nflnam) >*/
    feq_gen_io_d__30.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__30);
    feq_gen_i_d_1 = *nflnam;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, out + (j - 1 << 3), (ftnlen)8);
    }
    e_wsfe();
/*     FOR EACH SECTION IN THE SINUOSITY TABLE OUTPUT THE STATIONS, */
/*     THE OFFSETS, AND IF DEFINED, THE SINUOSITY VALUES.  ALL SECTIONS */
/*     MUST HAVE AS A MINIMUM ONE OR MORE STATIONS AND EITHER EXACTLY */
/*     AS MANY OFFSETS AS STATIONS OR ONE LESS STATION THAN OFFSETS. */
/* SOURCE tabstore.for:331 */
/*<       do1000i=1,numsec >*/
    feq_gen_i_d_1 = *numsec;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       MUST SEARCH ACROSS ALL COLUMNS TO FIND THE FLOW LINES. */
/* SOURCE tabstore.for:335 */
/*<       nfl=nflnam >*/
	nfl = *nflnam;
/* SOURCE tabstore.for:336 */
/*<       do100j=1,nfl >*/
	feq_gen_i_d_2 = nfl;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE tabstore.for:337 */
/*<       if(stl(i,j).lt.-1.e29)then >*/
	    if (stl[feq_gen_i_d_ + j * 400] < (float)-1e29) {
/* SOURCE tabstore.for:338 */
/*<       out(j)=' ' >*/
		s_copy(out + (j - 1 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tabstore.for:339 */
/*<       else >*/
	    } else {
/* SOURCE tabstore.for:340 */
/*<       callmkfmt(stl(i,j),8,chr5) >*/
		mkfmt_(&stl[feq_gen_i_d_ + j * 400], &feq_gen_c_d_8, chr5, (ftnlen)5);
/* SOURCE tabstore.for:343 */
/*<       staout(2:6)=chr5 >*/
		s_copy(staout + 1, chr5, (ftnlen)5, (ftnlen)5);
/* SOURCE tabstore.for:344 */
/*<       write(out(j),staout)stl(i,j) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 8;
		feq_gen_ici_d_1.iciunit = out + (j - 1 << 3);
		feq_gen_ici_d_1.icifmt = feq::format_text(staout, sizeof(staout));
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&stl[feq_gen_i_d_ + j * 400], (ftnlen)sizeof(
			real));
		e_wsfi();
/* SOURCE tabstore.for:345 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:346 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE tabstore.for:348 */
/*<       if(i.gt.1)then >*/
	if (feq_gen_i_d_ > 1) {
/* SOURCE tabstore.for:349 */
/*<       write(stdout,*)' ' >*/
	    feq_gen_io_d__33.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__33);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE tabstore.for:350 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:352 */
/*<       write(stdout,54)(out(j),j=1,nfl) >*/
	feq_gen_io_d__34.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__34);
	feq_gen_i_d_2 = nfl;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, out + (j - 1 << 3), (ftnlen)8);
	}
	e_wsfe();
/* SOURCE tabstore.for:354 */
/*<       do200j=1,nfl >*/
	feq_gen_i_d_2 = nfl;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE tabstore.for:355 */
/*<       if(offset(i,j).lt.-1.e29)then >*/
	    if (offset[feq_gen_i_d_ + j * 400] < (float)-1e29) {
/* SOURCE tabstore.for:356 */
/*<       out(j)=' ' >*/
		s_copy(out + (j - 1 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tabstore.for:357 */
/*<       else >*/
	    } else {
/* SOURCE tabstore.for:358 */
/*<       write(out(j),'(F8.2)')offset(i,j) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 8;
		feq_gen_ici_d_1.iciunit = out + (j - 1 << 3);
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&offset[feq_gen_i_d_ + j * 400], (ftnlen)sizeof(
			real));
		e_wsfi();
/* SOURCE tabstore.for:359 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:360 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE tabstore.for:361 */
/*<       write(stdout,56)(out(j),j=1,nfl) >*/
	feq_gen_io_d__35.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__35);
	feq_gen_i_d_2 = nfl;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, out + (j - 1 << 3), (ftnlen)8);
	}
	e_wsfe();
/*       OUTPUT THE SINUOSITY . CLEAR THE SINUOSITY OUTPUT FLAG. */
/*       ONLY OUTPUT SINUOSITY AT LOCATIONS WHERE THE STATION IS */
/*       DEFINED. */
/* SOURCE tabstore.for:366 */
/*<       snout=0 >*/
	snout = 0;
/* SOURCE tabstore.for:367 */
/*<       do300j=1,nfl >*/
	feq_gen_i_d_2 = nfl;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE tabstore.for:368 */
/*<       out(j)=' ' >*/
	    s_copy(out + (j - 1 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE tabstore.for:369 */
/*<       if(stl(i,j).gt.-1.e29)then >*/
	    if (stl[feq_gen_i_d_ + j * 400] > (float)-1e29) {
/* SOURCE tabstore.for:370 */
/*<       if(sinu(i,j).gt.-1.e29)then >*/
		if (sinu[feq_gen_i_d_ + j * 400] > (float)-1e29) {
/*             A DEFINED VALUE. SET THE FLAG AND PLACE IN OUT */
/* SOURCE tabstore.for:372 */
/*<       snout=1 >*/
		    snout = 1;
/* SOURCE tabstore.for:373 */
/*<       if(sinu(i,j).eq.-1.e28)then >*/
		    if (sinu[feq_gen_i_d_ + j * 400] == (float)-1e28) {
/* SOURCE tabstore.for:374 */
/*<       out(j)='     LIN' >*/
			s_copy(out + (j - 1 << 3), const_cast<char*>("     LIN"), (ftnlen)8, (
				ftnlen)8);
/* SOURCE tabstore.for:375 */
/*<       elseif(sinu(i,j).eq.-2.e28)then >*/
		    } else if (sinu[feq_gen_i_d_ + j * 400] == (float)-2e28) {
/* SOURCE tabstore.for:376 */
/*<       out(j)='    LIND' >*/
			s_copy(out + (j - 1 << 3), const_cast<char*>("    LIND"), (ftnlen)8, (
				ftnlen)8);
/* SOURCE tabstore.for:377 */
/*<       elseif(sinu(i,j).eq.-3.e28)then >*/
		    } else if (sinu[feq_gen_i_d_ + j * 400] == (float)-3e28) {
/* SOURCE tabstore.for:378 */
/*<       out(j)='    LINU' >*/
			s_copy(out + (j - 1 << 3), const_cast<char*>("    LINU"), (ftnlen)8, (
				ftnlen)8);
/* SOURCE tabstore.for:379 */
/*<       elseif(sinu(i,j).eq.-4.e28)then >*/
		    } else if (sinu[feq_gen_i_d_ + j * 400] == (float)-4e28) {
/* SOURCE tabstore.for:380 */
/*<       out(j)='PARABOLA' >*/
			s_copy(out + (j - 1 << 3), const_cast<char*>("PARABOLA"), (ftnlen)8, (
				ftnlen)8);
/* SOURCE tabstore.for:381 */
/*<       elseif(sinu(i,j).eq.-5.e28)then >*/
		    } else if (sinu[feq_gen_i_d_ + j * 400] == (float)-5e28) {
/* SOURCE tabstore.for:382 */
/*<       out(j)='   CUBIC' >*/
			s_copy(out + (j - 1 << 3), const_cast<char*>("   CUBIC"), (ftnlen)8, (
				ftnlen)8);
/* SOURCE tabstore.for:383 */
/*<       else >*/
		    } else {
/* SOURCE tabstore.for:384 */
/*<       write(out(j),'(F8.4)')sinu(i,j) >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 8;
			feq_gen_ici_d_1.iciunit = out + (j - 1 << 3);
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.4)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&sinu[feq_gen_i_d_ + j * 400], (ftnlen)
				sizeof(real));
			e_wsfi();
/* SOURCE tabstore.for:385 */
/*<       endif >*/
		    }
/* SOURCE tabstore.for:386 */
/*<       endif >*/
		}
/* SOURCE tabstore.for:387 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:388 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE tabstore.for:390 */
/*<       if(snout.gt.0)then >*/
	if (snout > 0) {
/* SOURCE tabstore.for:391 */
/*<       write(stdout,58)(out(j),j=1,nfl) >*/
	    feq_gen_io_d__37.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__37);
	    feq_gen_i_d_2 = nfl;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, out + (j - 1 << 3), (ftnlen)8);
	    }
	    e_wsfe();
/* SOURCE tabstore.for:392 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:394 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE tabstore.for:395 */
/*<       return >*/
    return 0;
/* SOURCE tabstore.for:396 */
/*<       end >*/
} /* stbout_ */




/* SOURCE tabstore.for:400 */
/*<       subroutinesptout(stdout,stdtab,n,tab,label,z,f) >*/
/* Subroutine */ int sptout_(integer *stdout, integer *stdtab, integer *n, 
	integer *tab, integer *feq_storage_label, real *feq_gen_feq_storage_z_d_, real *feq_storage_f)
{
    /* Initialized data */

    static integer feq_gen_type_d_ = 2;

    /* Format strings */
    static char fmt_1[] = "(\002 TABID= \002,a)";
    static char fmt_2[] = "(\002TABID= \002,a)";
    static char fmt_3[] = "(\002 TYPE=\002,i5)";
    static char fmt_4[] = "(\002TYPE=\002,i5)";
    static char fmt_5[] = "(\002 REFL=\002,f10.3)";
    static char fmt_6[] = "(\002REFL=\002,f10.3)";
    static char fmt_7[] = "(\002 \002,5x,\002DEPTH\002,4x,\002HLCOEF\002,2x,\
14a4)";
    static char fmt_8[] = "(5x,\002DEPTH\002,4x,\002HLCOEF\002,2x,14a4)";
    static char fmt_9[] = "(\002 \002,f10.3,f10.4)";
    static char fmt_10[] = "(f10.3,f10.4)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer j, l;
    real y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    char tabid[16];
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_1, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_2, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_3, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_4, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_5, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, fmt_6, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_7, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_8, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_9, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_10, 0 };


/*     + + + PURPOSE + + + */
/*     Output a standard function table of type 2. */
/* SOURCE tabstore.for:406 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tabstore.for:409 */
/*<       integern,stdout,stdtab,tab >*/
/* SOURCE tabstore.for:410 */
/*<       integerlabel(20) >*/
/* SOURCE tabstore.for:411 */
/*<       realf(n),z(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     N      - Number of tabulated levels in the table */
/*     TAB    - Table number */
/*     LABEL  - Label for identification */
/*     Z      - Argument values for table */
/*     F      - Function values to output */
/*     + + + SAVED VALUES + + + */
/* SOURCE tabstore.for:423 */
/*<       integertype >*/
/* SOURCE tabstore.for:424 */
/*<       savetype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tabstore.for:427 */
/*<       integerj,l >*/
/* SOURCE tabstore.for:428 */
/*<       realy >*/
/* SOURCE tabstore.for:429 */
/*<       charactertabid*16 >*/
/*     External names */
/* SOURCE tabstore.for:432 */
/*<       integerlenstr >*/
/* SOURCE tabstore.for:433 */
/*<       characterget_tabid*16 >*/
/* SOURCE tabstore.for:435 */
/*<       externalget_tabid,lenstr >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tabstore.for:438 */
/*<       datatype/2/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> f(feq_storage_f, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<integer> label(feq_storage_label, 1);

    /* Function Body */
/* SOURCE tabstore.for:441 */
/*<     1 format(' TABID= ',a) >*/
/* L1: */
/* SOURCE tabstore.for:442 */
/*<     2 format('TABID= ',a) >*/
/* L2: */
/* SOURCE tabstore.for:443 */
/*<     3 format(' TYPE=',i5) >*/
/* L3: */
/* SOURCE tabstore.for:444 */
/*<     4 format('TYPE=',i5) >*/
/* L4: */
/* SOURCE tabstore.for:445 */
/*<     5 format(' REFL=',f10.3) >*/
/* L5: */
/* SOURCE tabstore.for:446 */
/*<     6 format('REFL=',f10.3) >*/
/* L6: */
/* SOURCE tabstore.for:447 */
/*<     7 format(' ',5x,'DEPTH',4x,'HLCOEF',2x,14a4) >*/
/* L7: */
/* SOURCE tabstore.for:448 */
/*<     8 format(5x,'DEPTH',4x,'HLCOEF',2x,14a4) >*/
/* L8: */
/* SOURCE tabstore.for:449 */
/*<     9 format(' ',f10.3,f10.4) >*/
/* L9: */
/* SOURCE tabstore.for:450 */
/*<    10 format(f10.3,f10.4) >*/
/* L10: */
/* *********************************************************************** */
/* SOURCE tabstore.for:452 */
/*<       tabid=get_tabid(tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, tab);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE tabstore.for:453 */
/*<       l=lenstr(tabid) >*/
    l = lenstr_(tabid, (ftnlen)16);
/* SOURCE tabstore.for:454 */
/*<       write(stdout,1)tabid(1:l) >*/
    feq_gen_io_d__41.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__41);
    do_fio(&feq_gen_c_d_1, tabid, l);
    e_wsfe();
/* SOURCE tabstore.for:455 */
/*<       write(stdtab,2)tabid(1:l) >*/
    feq_gen_io_d__42.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__42);
    do_fio(&feq_gen_c_d_1, tabid, l);
    e_wsfe();
/* SOURCE tabstore.for:457 */
/*<       write(stdout,3)type >*/
    feq_gen_io_d__43.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__43);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE tabstore.for:458 */
/*<       write(stdtab,4)type >*/
    feq_gen_io_d__44.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__44);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE tabstore.for:460 */
/*<       write(stdout,5)z(1) >*/
    feq_gen_io_d__45.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__45);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE tabstore.for:461 */
/*<       write(stdtab,6)z(1) >*/
    feq_gen_io_d__46.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__46);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE tabstore.for:463 */
/*<       write(stdout,7)(label(j),j=1,14) >*/
    feq_gen_io_d__47.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__47);
    for (j = 1; j <= 14; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&label[j], (ftnlen)sizeof(integer));
    }
    e_wsfe();
/* SOURCE tabstore.for:464 */
/*<       write(stdtab,8)(label(j),j=1,14) >*/
    feq_gen_io_d__49.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__49);
    for (j = 1; j <= 14; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&label[j], (ftnlen)sizeof(integer));
    }
    e_wsfe();
/* SOURCE tabstore.for:466 */
/*<       do100j=1,n >*/
    feq_gen_i_d_1 = *n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE tabstore.for:467 */
/*<       y=z(j)-z(1) >*/
	y = static_cast<double>(feq_gen_z_d_[j]) - feq_gen_z_d_[1];
/* SOURCE tabstore.for:468 */
/*<       write(stdout,9)y,f(j) >*/
	feq_gen_io_d__51.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__51);
	do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&f[j], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE tabstore.for:469 */
/*<       write(stdtab,10)y,f(j) >*/
	feq_gen_io_d__52.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__52);
	do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&f[j], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE tabstore.for:470 */
/*<   100 continue >*/
/* L100: */
    }
/*     MAKE LAST ARGUMENT LARGE TO PREVENT TABLE OVERSHOOT */
/* SOURCE tabstore.for:474 */
/*<       y=y+25.0 >*/
    y += static_cast<double>((float)25.);
/* SOURCE tabstore.for:475 */
/*<       write(stdtab,10)y,f(n) >*/
    feq_gen_io_d__53.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__53);
    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&f[*n], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE tabstore.for:476 */
/*<       y=-1.0 >*/
    y = (float)-1.;
/* SOURCE tabstore.for:477 */
/*<       write(stdtab,10)y,y >*/
    feq_gen_io_d__54.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__54);
    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE tabstore.for:478 */
/*<       return >*/
    return 0;
/* SOURCE tabstore.for:479 */
/*<       end >*/
} /* sptout_ */




/* SOURCE tabstore.for:483 */
/*<        >*/
/* Subroutine */ int twdout_(integer *stdout, integer *stdtab, integer *table,
	 char *label, integer *nhu, integer *nfrac, real *feq_storage_huvec, real *feq_storage_fdrop, 
	real *feq_storage_pfdvec, real *feq_storage_q, real *hdatum, integer *feq_gen_type_d_, char *source, 
	real *zrhufd, char *zone, char *hgrid, char *vdatum, char *unitsys, 
	char *basis, doublereal *easting, doublereal *northing, integer *
	eflag, ftnlen label_len, ftnlen source_len, ftnlen zone_len, ftnlen 
	hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, ftnlen basis_len)
{
    /* Initialized data */

    static integer ioff = 10;

    /* Format strings */
    static char fmt_21[] = "(\002TYPE=\002,i5,\002 HDATUM=\002,f10.3,1x,a8)";
    static char fmt_22[] = "(\002TABID= \002,a)";
    static char fmt_23[] = "(\002TYPE=\002,i5,\002 HDATUM=\002,f10.3,1x,a8,1\
x,\002zrhufd=\002,f10.4)";
    static char fmt_24[] = "(\002    HEADUP  FREEDROP\002,1x,a50)";
    static char fmt_25[] = "(f10.3,f10.5)";
    static char fmt_26[] = "(\002    -1.0\002)";
    static char fmt_27[] = "(\002 POINTS ON LINES OF CONSTANT UPSTREAM HEA\
D\002)";
    static char fmt_28[] = "(f10.5,f10.3)";
    static char fmt_30[] = "(\002LABEL=\002,a50)";
    static char fmt_32[] = "(\002NHUP=\002,i5)";
    static char fmt_33[] = "(\002NHDN=\002,i5)";
    static char fmt_34[] = "(\002NPFD=\002,i5)";
    static char fmt_35[] = "(\002NPFQ=\002,i5)";
    static char fmt_50[] = "(\002HUP    \002,10a7)";
    static char fmt_51[] = "(\002QFREE  \002,10a7)";
    static char fmt_52[] = "(\002FDROP  \002,10a7)";
    static char fmt_53[] = "(\002HDN    \002,10a7)";
    static char fmt_54[] = "(\002   PFD\002,10x,\002Flows for HUP and Propor\
tion of FDROP\002)";
    static char fmt_56[] = "(a7,10a7)";
    static char fmt_57[] = "(\002   PFQ\002,10x,\002Ups heads for HDN and Pr\
oportion of QFREE\002)";
    static char fmt_58[] = "(\002 *ERR:592* TYPE=\002,i5,\002 INVALID FOR 2-\
D FLOW TABLES.\002)";
    static char fmt_60[] = "(\002ZONE=\002,a8,\002 HGRID=\002,a8,\002 VDAT\
UM=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8,/,\002EASTING=\002,0pf15.\
3,\002 NORTHING=\002,f15.3)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3, feq_gen_i_d_4;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[7];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, k, l;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer lim, knt;
    extern /* Subroutine */ int feq_gen_chk_vdatum_unitsys_d_(integer *, char *, char *
	    , char *, ftnlen, ftnlen, ftnlen);
    extern /* Character */ VOID put7_(char *, ftnlen, real *);
    doublereal hdat;
    char line[7*10], tabid[16], dummy[7];
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_22, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_23, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_25, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_25, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_26, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_27, 0 };
    static cilist feq_gen_io_d__67 = { 0, 0, 0, fmt_28, 0 };
    static cilist feq_gen_io_d__68 = { 0, 0, 0, fmt_28, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_28, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, fmt_23, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, fmt_21, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_30, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_32, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_33, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_34, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, fmt_35, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_58, 0 };


/*     + + + PURPOSE + + + */
/*     Output a two-D flow table of the given type. Includes */
/*     types 6, 13, and 14. */
/* SOURCE tabstore.for:495 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE tabstore.for:498 */
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
/* SOURCE tabstore.for:501 */
/*<       integereflag,nfrac,nhu,stdout,stdtab,table,type >*/
/* SOURCE tabstore.for:502 */
/*<        >*/
/* SOURCE tabstore.for:504 */
/*<       real*8easting,northing >*/
/* SOURCE tabstore.for:505 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     TABLE  - Table number */
/*     LABEL  - Label for identification */
/*     NHU    - Number of upstream heads */
/*     NFRAC  - Number of fractions for defining partial free drop */
/*     HUVEC  - Vector of upstream heads */
/*     FDROP  - Free drop values */
/*     PFDVEC - Partial free drop vector */
/*     Q      - Flowrate */
/*     zrhufd - gives the drop to free flow at zero upstram head. */
/*              Currently is zero for CULVERT, ORIFICE, EMBANKQ, */
/*              and may be positive for CHANRAT if the flow surface */
/*              has a downward slope (sustaining slope).  It is zero */
/*              in this case also if the slope is zero or retarding. */
/*              Only used for fitting cubic splines to the table. */
/*              We may add non-zero free drops for other cases if it */
/*              proves useful. The value is written such that if */
/*              it is left out it will be taken as 0.0, the current */
/*              value for the drop to free flow when the ups head is zero. */
/*     HDATUM - Datum for measuring head */
/*     TYPE   - Table type. */
/*     SOURCE - source for the table. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + SAVED VALUES + + + */
/* SOURCE tabstore.for:535 */
/*<       integerioff >*/
/* SOURCE tabstore.for:536 */
/*<       saveioff >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tabstore.for:539 */
/*<       integeri,j,k,l,knt,lim >*/
/* SOURCE tabstore.for:540 */
/*<       real*8hdat >*/
/* SOURCE tabstore.for:541 */
/*<       characterdummy*7,line(10)*7,tabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE tabstore.for:544 */
/*<       intrinsicmin >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE tabstore.for:547 */
/*<       integerlenstr >*/
/* SOURCE tabstore.for:548 */
/*<       characterput7*7,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tabstore.for:551 */
/*<       externalput7,get_tabid,lenstr >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tabstore.for:554 */
/*<       dataioff/10/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> q(feq_storage_q, 152);

    feq::IndexedPointer<real> pfdvec(feq_storage_pfdvec, 1);

    feq::IndexedPointer<real> fdrop(feq_storage_fdrop, 1);

    feq::IndexedPointer<real> huvec(feq_storage_huvec, 1);

    /* Function Body */
/* SOURCE tabstore.for:557 */
/*<    21 format('TYPE=',i5,' HDATUM=',f10.3,1x,a8) >*/
/* L21: */
/* SOURCE tabstore.for:558 */
/*<    22 format('TABID= ',a) >*/
/* L22: */
/* SOURCE tabstore.for:559 */
/*<    23 format('TYPE=',i5,' HDATUM=',f10.3,1x,a8,1x,'zrhufd=',f10.4) >*/
/* L23: */
/* SOURCE tabstore.for:560 */
/*<    24 format('    HEADUP  FREEDROP',1x,a50) >*/
/* L24: */
/* SOURCE tabstore.for:561 */
/*<    25 format(f10.3,f10.5) >*/
/* L25: */
/* SOURCE tabstore.for:562 */
/*<    26 format('    -1.0') >*/
/* L26: */
/* SOURCE tabstore.for:563 */
/*<    27 format(' POINTS ON LINES OF CONSTANT UPSTREAM HEAD') >*/
/* L27: */
/* SOURCE tabstore.for:564 */
/*<    28 format(f10.5,f10.3) >*/
/* L28: */
/* SOURCE tabstore.for:565 */
/*<    30 format('LABEL=',a50) >*/
/* L30: */
/* SOURCE tabstore.for:566 */
/*<    32 format('NHUP=',i5) >*/
/* L32: */
/* SOURCE tabstore.for:567 */
/*<    33 format('NHDN=',i5) >*/
/* L33: */
/* SOURCE tabstore.for:568 */
/*<    34 format('NPFD=',i5) >*/
/* L34: */
/* SOURCE tabstore.for:569 */
/*<    35 format('NPFQ=',i5) >*/
/* L35: */
/* SOURCE tabstore.for:570 */
/*<    50 format('HUP    ',10a7) >*/
/* L50: */
/* SOURCE tabstore.for:571 */
/*<    51 format('QFREE  ',10a7) >*/
/* L51: */
/* SOURCE tabstore.for:572 */
/*<    52 format('FDROP  ',10a7) >*/
/* L52: */
/* SOURCE tabstore.for:573 */
/*<    53 format('HDN    ',10a7) >*/
/* L53: */
/* SOURCE tabstore.for:574 */
/*<    54 format('   PFD',10x,'Flows for HUP and Proportion of FDROP') >*/
/* L54: */
/* SOURCE tabstore.for:575 */
/*<    56 format(a7,10a7) >*/
/* L56: */
/* SOURCE tabstore.for:576 */
/*<    57 format('   PFQ',10x,'Ups heads for HDN and Proportion of QFREE') >*/
/* L57: */
/* SOURCE tabstore.for:577 */
/*<    58 format(' *ERR:592* TYPE=',i5,' INVALID FOR 2-D FLOW TABLES.') >*/
/* L58: */
/* SOURCE tabstore.for:578 */
/*<    60  >*/
/* L60: */
/* *********************************************************************** */
/* SOURCE tabstore.for:581 */
/*<        >*/
    feq_gen_chk_vdatum_unitsys_d_(stdout, vdatum, unitsys, const_cast<char*>(" during output of type 6,\
 13, or 14 table"), (ftnlen)8, (ftnlen)8, (ftnlen)41);
/*     Apply the global vertical datum shift.  Default must be 0.0 */
/* SOURCE tabstore.for:585 */
/*<       hdat=hdatum >*/
    hdat = *hdatum;
/*      hdat = hdat + g_vdatum_shift */
/* SOURCE tabstore.for:588 */
/*<       tabid=get_tabid(table) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, table);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE tabstore.for:589 */
/*<       l=lenstr(tabid) >*/
    l = lenstr_(tabid, (ftnlen)16);
/* SOURCE tabstore.for:590 */
/*<       write(stdtab,22)tabid(1:l) >*/
    feq_gen_io_d__59.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__59);
    do_fio(&feq_gen_c_d_1, tabid, l);
    e_wsfe();
/* SOURCE tabstore.for:592 */
/*<       if(type.eq.6)then >*/
    if (*feq_gen_type_d_ == 6) {
/*       OUTPUT THE OLD FORMAT FOR TWO-D FLOW TABLES */
/* SOURCE tabstore.for:595 */
/*<       write(stdtab,23)-type,hdat,source,zrhufd >*/
	feq_gen_io_d__60.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__60);
	feq_gen_i_d_1 = -(*feq_gen_type_d_);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hdat, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, source, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&(*zrhufd), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE tabstore.for:596 */
/*<       write(stdtab,24)label >*/
	feq_gen_io_d__61.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__61);
	do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
	e_wsfe();
/*       PUT IN THE ZERO HEAD POINT */
/* SOURCE tabstore.for:599 */
/*<       write(stdtab,25)0.0,0.0 >*/
	feq_gen_io_d__62.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, (char *)&c_b188, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&c_b188, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE tabstore.for:600 */
/*<       do2000i=1,nhu >*/
	feq_gen_i_d_1 = *nhu;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:601 */
/*<       write(stdtab,25)huvec(i),fdrop(i) >*/
	    feq_gen_io_d__64.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__64);
	    do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&fdrop[feq_gen_i_d_], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tabstore.for:602 */
/*<  2000 continue >*/
/* L2000: */
	}
/* SOURCE tabstore.for:603 */
/*<       write(stdtab,26) >*/
	feq_gen_io_d__65.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__65);
	e_wsfe();
/* SOURCE tabstore.for:604 */
/*<       write(stdtab,27) >*/
	feq_gen_io_d__66.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__66);
	e_wsfe();
/* SOURCE tabstore.for:605 */
/*<       write(stdtab,28)0.0,0.0 >*/
	feq_gen_io_d__67.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__67);
	do_fio(&feq_gen_c_d_1, (char *)&c_b188, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&c_b188, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE tabstore.for:606 */
/*<       write(stdtab,28)1.0,0.0 >*/
	feq_gen_io_d__68.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__68);
	do_fio(&feq_gen_c_d_1, (char *)&c_b199, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&c_b188, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE tabstore.for:607 */
/*<       do2200i=1,nhu >*/
	feq_gen_i_d_1 = *nhu;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabstore.for:608 */
/*<       do2100j=1,nfrac >*/
	    feq_gen_i_d_2 = *nfrac;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE tabstore.for:609 */
/*<       write(stdtab,28)pfdvec(j),q(i,j) >*/
		feq_gen_io_d__70.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__70);
		do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&q[feq_gen_i_d_ + j * 151], (ftnlen)sizeof(real))
			;
		e_wsfe();
/* SOURCE tabstore.for:610 */
/*<  2100 continue >*/
/* L2100: */
	    }
/* SOURCE tabstore.for:611 */
/*<  2200 continue >*/
/* L2200: */
	}
/* SOURCE tabstore.for:612 */
/*<       elseif(type.eq.13.or.type.eq.14)then >*/
    } else if (*feq_gen_type_d_ == 13 || *feq_gen_type_d_ == 14) {
/*       OUTPUT TWO-D FLOW TABLE IN THE RECTANGULAR FORMAT */
/* SOURCE tabstore.for:616 */
/*<       if(type.eq.13)then >*/
	if (*feq_gen_type_d_ == 13) {
/* SOURCE tabstore.for:617 */
/*<       write(stdtab,23)-type,hdat,source,zrhufd >*/
	    feq_gen_io_d__71.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__71);
	    feq_gen_i_d_1 = -(*feq_gen_type_d_);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&hdat, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, source, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&(*zrhufd), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tabstore.for:618 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:619 */
/*<       write(stdtab,21)-type,hdat,source >*/
	    feq_gen_io_d__72.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__72);
	    feq_gen_i_d_1 = -(*feq_gen_type_d_);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&hdat, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, source, (ftnlen)8);
	    e_wsfe();
/* SOURCE tabstore.for:620 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:621 */
/*<       if(zone/='NONE')then >*/
	if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0) {
/*         Output the location information. */
/* SOURCE tabstore.for:623 */
/*<       write(stdtab,60)zone,hgrid,vdatum,unitsys,basis,easting,northing >*/
	    feq_gen_io_d__73.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__73);
	    do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&(*easting), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*northing), (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE tabstore.for:625 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:626 */
/*<       write(stdtab,30)label >*/
	feq_gen_io_d__74.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__74);
	do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
	e_wsfe();
/* SOURCE tabstore.for:627 */
/*<       if(type.eq.13)then >*/
	if (*feq_gen_type_d_ == 13) {
/* SOURCE tabstore.for:628 */
/*<       write(stdtab,32)nhu >*/
	    feq_gen_io_d__75.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__75);
	    do_fio(&feq_gen_c_d_1, (char *)&(*nhu), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE tabstore.for:629 */
/*<       else >*/
	} else {
/*         NHU IS REALLY THE NUMBER OF DOWNSTREAM HEADS! */
/* SOURCE tabstore.for:631 */
/*<       write(stdtab,33)nhu >*/
	    feq_gen_io_d__76.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__76);
	    do_fio(&feq_gen_c_d_1, (char *)&(*nhu), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE tabstore.for:632 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:633 */
/*<       if(type.eq.13)then >*/
	if (*feq_gen_type_d_ == 13) {
/* SOURCE tabstore.for:634 */
/*<       write(stdtab,34)nfrac-1 >*/
	    feq_gen_io_d__77.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__77);
	    feq_gen_i_d_1 = *nfrac - 1;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE tabstore.for:635 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:636 */
/*<       write(stdtab,35)nfrac-1 >*/
	    feq_gen_io_d__78.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__78);
	    feq_gen_i_d_1 = *nfrac - 1;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE tabstore.for:637 */
/*<       endif >*/
	}
/*       OUTPUT THE TABLE WITH IOFF COLUMNS OF DATA UNTIL TABLE IS */
/*       COMPLETE. THE ZERO HEAD, AND ZERO PROPORTION OF FREE DROP */
/*       VALUES ARE NOT PRINTED. */
/* SOURCE tabstore.for:643 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE tabstore.for:644 */
/*<       do3000i=1,nhu,ioff >*/
	feq_gen_i_d_1 = *nhu;
	feq_gen_i_d_2 = ioff;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE tabstore.for:645 */
/*<       lim=min(ioff,nhu-knt) >*/
/* Computing MIN */
	    feq_gen_i_d_3 = ioff, feq_gen_i_d_4 = *nhu - knt;
	    lim = min(feq_gen_i_d_3,feq_gen_i_d_4);
/* SOURCE tabstore.for:646 */
/*<       do100j=i,i+lim-1 >*/
	    feq_gen_i_d_3 = feq_gen_i_d_ + lim - 1;
	    for (j = feq_gen_i_d_; j <= feq_gen_i_d_3; ++j) {
/* SOURCE tabstore.for:647 */
/*<       line(j-knt)=put7(huvec(j)) >*/
		put7_(feq_gen_ch_d_2, (ftnlen)7, &huvec[j]);
		s_copy(line + (j - knt - 1) * 7, feq_gen_ch_d_2, (ftnlen)7, (ftnlen)7);
/* SOURCE tabstore.for:648 */
/*<   100 continue >*/
/* L100: */
	    }
/* SOURCE tabstore.for:649 */
/*<       if(type.eq.13)then >*/
	    if (*feq_gen_type_d_ == 13) {
/* SOURCE tabstore.for:650 */
/*<       write(stdtab,50)(line(j-knt),j=i,i+lim-1) >*/
		feq_gen_io_d__82.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__82);
		feq_gen_i_d_3 = feq_gen_i_d_ + lim - 1;
		for (j = feq_gen_i_d_; j <= feq_gen_i_d_3; ++j) {
		    do_fio(&feq_gen_c_d_1, line + (j - knt - 1) * 7, (ftnlen)7);
		}
		e_wsfe();
/* SOURCE tabstore.for:651 */
/*<       else >*/
	    } else {
/* SOURCE tabstore.for:652 */
/*<       write(stdtab,51)(line(j-knt),j=i,i+lim-1) >*/
		feq_gen_io_d__83.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__83);
		feq_gen_i_d_3 = feq_gen_i_d_ + lim - 1;
		for (j = feq_gen_i_d_; j <= feq_gen_i_d_3; ++j) {
		    do_fio(&feq_gen_c_d_1, line + (j - knt - 1) * 7, (ftnlen)7);
		}
		e_wsfe();
/* SOURCE tabstore.for:653 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:654 */
/*<       do101j=i,i+lim-1 >*/
	    feq_gen_i_d_3 = feq_gen_i_d_ + lim - 1;
	    for (j = feq_gen_i_d_; j <= feq_gen_i_d_3; ++j) {
/* SOURCE tabstore.for:655 */
/*<       line(j-knt)=put7(fdrop(j)) >*/
		put7_(feq_gen_ch_d_2, (ftnlen)7, &fdrop[j]);
		s_copy(line + (j - knt - 1) * 7, feq_gen_ch_d_2, (ftnlen)7, (ftnlen)7);
/* SOURCE tabstore.for:656 */
/*<   101 continue >*/
/* L101: */
	    }
/* SOURCE tabstore.for:657 */
/*<       if(type.eq.13)then >*/
	    if (*feq_gen_type_d_ == 13) {
/* SOURCE tabstore.for:658 */
/*<       write(stdtab,52)(line(j-knt),j=i,i+lim-1) >*/
		feq_gen_io_d__84.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__84);
		feq_gen_i_d_3 = feq_gen_i_d_ + lim - 1;
		for (j = feq_gen_i_d_; j <= feq_gen_i_d_3; ++j) {
		    do_fio(&feq_gen_c_d_1, line + (j - knt - 1) * 7, (ftnlen)7);
		}
		e_wsfe();
/* SOURCE tabstore.for:659 */
/*<       else >*/
	    } else {
/* SOURCE tabstore.for:660 */
/*<       write(stdtab,53)(line(j-knt),j=i,i+lim-1) >*/
		feq_gen_io_d__85.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__85);
		feq_gen_i_d_3 = feq_gen_i_d_ + lim - 1;
		for (j = feq_gen_i_d_; j <= feq_gen_i_d_3; ++j) {
		    do_fio(&feq_gen_c_d_1, line + (j - knt - 1) * 7, (ftnlen)7);
		}
		e_wsfe();
/* SOURCE tabstore.for:661 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:662 */
/*<       if(type.eq.13)then >*/
	    if (*feq_gen_type_d_ == 13) {
/* SOURCE tabstore.for:663 */
/*<       write(stdtab,54) >*/
		feq_gen_io_d__86.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__86);
		e_wsfe();
/* SOURCE tabstore.for:664 */
/*<       else >*/
	    } else {
/* SOURCE tabstore.for:665 */
/*<       write(stdtab,57) >*/
		feq_gen_io_d__87.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__87);
		e_wsfe();
/* SOURCE tabstore.for:666 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:668 */
/*<       do2900j=2,nfrac >*/
	    feq_gen_i_d_3 = *nfrac;
	    for (j = 2; j <= feq_gen_i_d_3; ++j) {
/* SOURCE tabstore.for:670 */
/*<       do103k=i,i+lim-1 >*/
		feq_gen_i_d_4 = feq_gen_i_d_ + lim - 1;
		for (k = feq_gen_i_d_; k <= feq_gen_i_d_4; ++k) {
/* SOURCE tabstore.for:671 */
/*<       line(k-knt)=put7(q(k,j)) >*/
		    put7_(feq_gen_ch_d_2, (ftnlen)7, &q[k + j * 151]);
		    s_copy(line + (k - knt - 1) * 7, feq_gen_ch_d_2, (ftnlen)7, (
			    ftnlen)7);
/* SOURCE tabstore.for:672 */
/*<   103 continue >*/
/* L103: */
		}
/* SOURCE tabstore.for:673 */
/*<       dummy=put7(pfdvec(j)) >*/
		put7_(feq_gen_ch_d_2, (ftnlen)7, &pfdvec[j]);
		s_copy(dummy, feq_gen_ch_d_2, (ftnlen)7, (ftnlen)7);
/* SOURCE tabstore.for:674 */
/*<       write(stdtab,56)dummy,(line(k-knt),k=i,i+lim-1) >*/
		feq_gen_io_d__90.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__90);
		do_fio(&feq_gen_c_d_1, dummy, (ftnlen)7);
		feq_gen_i_d_4 = feq_gen_i_d_ + lim - 1;
		for (k = feq_gen_i_d_; k <= feq_gen_i_d_4; ++k) {
		    do_fio(&feq_gen_c_d_1, line + (k - knt - 1) * 7, (ftnlen)7);
		}
		e_wsfe();
/* SOURCE tabstore.for:676 */
/*<  2900 continue >*/
/* L2900: */
	    }
/* SOURCE tabstore.for:677 */
/*<       knt=knt+ioff >*/
	    knt += ioff;
/* SOURCE tabstore.for:678 */
/*<  3000 continue >*/
/* L3000: */
	}
/* SOURCE tabstore.for:680 */
/*<       else >*/
    } else {
/* SOURCE tabstore.for:681 */
/*<       write(stdout,58)type >*/
	feq_gen_io_d__91.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__91);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_type_d_), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE tabstore.for:682 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE tabstore.for:683 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:685 */
/*<       return >*/
    return 0;
/* SOURCE tabstore.for:686 */
/*<       end >*/
} /* twdout_ */




/* SOURCE tabstore.for:690 */
/*<        >*/
/* Subroutine */ int tabout_(integer *stdout, integer *stdtab, integer *tab, 
	real *stat, real *zmin, integer *mesg, char *savopt, char *outopt, 
	char *betopt, char *zone, char *hgrid, char *vdatum, char *unitsys, 
	char *basis, char *feq_storage_khflag, char *feq_storage_alphaflag, char *feq_storage_betaflag, char *
	feq_storage_maflag, char *feq_storage_mqflag, integer *ndep, real *feq_storage_xst, integer *ftp, ftnlen 
	savopt_len, ftnlen outopt_len, ftnlen betopt_len, ftnlen zone_len, 
	ftnlen hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, ftnlen 
	basis_len, ftnlen khflag_len, ftnlen alphaflag_len, ftnlen 
	betaflag_len, ftnlen maflag_len, ftnlen mqflag_len)
{
    /* Initialized data */

    static char sotab[8*14+1] = "SAVE1   SAVE12  SAVE20  SAVE21  SAVE22  SAV\
E23  SAVE24  SAVE25  SAVE30  SAVE31  SAVE32  SAVE33  SAVE34  SAVE35  ";
    static char outotab[8*14+1] = "OUT1    OUT12   OUT20   OUT21   OUT22   O\
UT23   OUT24   OUT25   OUT30   OUT31   OUT32   OUT33   OUT34   OUT35   ";
    static integer soval[14] = { 6,8,5,6,8,7,8,10,7,8,11,11,12,15 };
    static integer typvec[14] = { 21,22,20,21,22,23,24,25,30,31,32,33,34,35 };

    /* Format strings */
    static char fmt_40[] = "(a10,a10,2a13,f10.6,2a10)";
    static char fmt_41[] = "(a10,a10,2a13,f10.6,a13,2a10)";
    static char fmt_42[] = "(a10,a10,2a13,f10.6,a13,f10.6,a13,3a10)";
    static char fmt_43[] = "(a10,a10,2a13,f10.6,2f10.7,4a10)";
    static char fmt_44[] = "(a10,a10,2a13,f10.6,a13,2f10.7,4a10)";
    static char fmt_45[] = "(a10,a10,2a13,f10.6,a13,f10.6,a13,2f10.7,5a10)";
    static char fmt_50[] = "(/,\002 *BUG:XXX* Save option=\002,a8,\002 unkno\
wn in TABOUT.\002)";
    static char fmt_51[] = "(/,\002 Elements for section ID: \002,a)";
    static char fmt_52[] = "(/,\002 TABID= \002,a,/,1x,\002TYPE=\002,i5,/,\
1x,\002STATION=\002,1pe12.5,/,1x,\002ELEVATION=\002,1pe12.5)";
    static char fmt_530[] = "(\002TABID= \002,a,/,\002TYPE=\002,i5,/,\002STA\
TION=\002,1pe12.5,\002 GISID=\002,a,\002 EASTING=\002,0pf15.2,\002 NORTHING\
=\002,f15.2,/,\002ELEVATION=\002,1pe12.5,17x,\002 EXT=-99.900000\002,\002 FA\
C=1.000 SLOT=\002,0pf10.3)";
    static char fmt_531[] = "(\002TABID= \002,a,/,\002TYPE=\002,i5,/,\002ZON\
E=\002,a8,\002 HGRID=\002,a8,\002 VDATUM=\002,a8,\002 UNITSYS=\002,a8,\002 B\
ASIS=\002,a8,/,\002STATION=\002,1pe12.5,\002 GISID=\002,a,\002 EASTING=\002,\
0pf15.3,\002 NORTHING=\002,f15.3,/,\002ELEVATION=\002,1pe12.5,17x,\002 EXT=-\
99.900000\002,\002 FAC=1.000 SLOT=\002,0pf10.4)";
    static char fmt_532[] = "(\002TABID= \002,a,/,\002TYPE=\002,i5,/,\002STA\
TION=\002,1pe12.5,\002 GISID=\002,a,\002 EASTING=\002,0pf15.2,\002 NORTHING\
=\002,f15.2,/,\002ELEVATION=\002,1pe12.5,17x,\002 EXT=-30.449520\002,\002 FA\
C=1.000 SLOT=\002,0pf10.3)";
    static char fmt_533[] = "(\002TABID= \002,a,/,\002TYPE=\002,i5,/,\002ZON\
E=\002,a8,\002 HGRID=\002,a8,\002 VDATUM=\002,a8,\002 UNITSYS=\002,a8,\002 B\
ASIS=\002,a8,/,\002STATION=\002,1pe12.5,\002 GISID=\002,a,\002 EASTING=\002,\
0pf15.3,\002 NORTHING=\002,f15.3,/,\002ELEVATION=\002,1pe12.5,17x,\002 EXT=-\
30.449520\002,\002 FAC=1.000 SLOT=\002,0pf10.4)";
    static char fmt_54[] = "(/,3x,\002Depth Top Wid\002,4x,\002Area\002,\002\
 Sqr(Cv)\002,3x,\002Beta\002,7x,\002J\002,2x,\002Alpha\002,3x,\002CritQ\002,\
5x,\002Ma\002,5x,\002Mq\002,\002  AVER n\002,\002   dkh/dy  dbta/dy  dalp/dy\
   dma/dy   dmq/dy\002)";
    static char fmt_55[] = "(/,\002 *BUG:XXX* Out option=\002,a8,\002 unknow\
n in TABOUT.\002)";
    static char fmt_56[] = "(\002 \002,f7.3,3a8,f7.3,a8,f7.3,a8,2f7.3,f8.4,f\
8.3,a1,4(f8.4,a1))";
    static char fmt_57[] = "(f10.0)";
    static char fmt_58[] = "(/,\002 *WRN:506* Conveyance non-increasing at d\
epth=\002,f10.2,/,11x,\002 decrease=\002,f6.1,\002 per cent\002)";
    static char fmt_60[] = "(\002 *ERR:569* Insufficient space in ITAB/FTAB \
to save\002,\002 cross section table.\002,/,10x,\002 need\002,i5,\002 mor\
e\002,\002 elements.\002)";
    static char fmt_62[] = "(\002 \002,\002     Depth      Beta   dBetadY   \
  Alpha  DAlphadY\002,\002     Qbeta    Qalpha     Qcrit\002)";
    static char fmt_64[] = "(1x,f10.5,4f10.6,3f10.1)";
    static char fmt_70[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta    dkh/dy  dbeta/dy\002)";
    static char fmt_71[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment    dkh/dy  dbeta/dy\002)";
    static char fmt_72[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,5x,\002Alpha\002,8x,\002Critq    dkh/d\
y  dbeta/dy dalpha/dy\002)";
    static char fmt_73[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta\002,8x,\002Ma\002,8x,\002Mq    dkh/dy  dbeta/dy    dma/\
dy    dmq/dy\002)";
    static char fmt_74[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,8x,\002Ma\002,8x,\002Mq    dkh/dy  dbe\
ta/dy    dma/dy    dmq/dy\002)";
    static char fmt_75[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,5x,\002Alpha\002,8x,\002Critq\002,8x\
,\002Ma\002,8x,\002Mq    dkh/dy  dbeta/dy    dma/dy    dmq/dy dalpha/dy\002)";
    static char fmt_80[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta\002)";
    static char fmt_81[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002)";
    static char fmt_82[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,5x,\002Alpha\002,8x,\002Critq\002)";
    static char fmt_83[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta\002,8x,\002Ma\002,8x,\002Mq\002)";
    static char fmt_84[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,8x,\002Ma\002,8x,\002Mq\002)";
    static char fmt_85[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,5x,\002Alpha\002,8x,\002Critq\002,8x\
,\002Ma\002,8x,\002Mq\002)";
    static char fmt_90[] = "(a10,a10,2a13,f10.6)";
    static char fmt_91[] = "(a10,a10,2a13,f10.6,a13)";
    static char fmt_92[] = "(a10,a10,2a13,f10.6,a13,f10.6,a13)";
    static char fmt_93[] = "(a10,a10,2a13,f10.6,2f10.7)";
    static char fmt_94[] = "(a10,a10,2a13,f10.6,a13,2f10.7)";
    static char fmt_95[] = "(a10,a10,2a13,f10.6,a13,f10.6,a13,2f10.7)";
    static char fmt_98[] = "(/,\002 Note: A caret (^) following a derivative\
 indicates\002,\002 imposition of variation limitation at that point.  Conti\
nuity\002,\002 of\002,/,7x,\002 second derivative is lost at these points\
.\002,\002  Otherwise both the first and second derivative is continuous.\
\002)";
    static char fmt_99[] = "(/,\002 Saving TabId= \002,a,\002  Internal tabl\
e number=\002,i5)";
    static char fmt_9124[] = "(f10.4,6(1pe12.4))";
    static char fmt_9123[] = "(f10.4,15(1pe12.4))";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4, feq_gen_r_d_5, feq_gen_r_d_6, feq_gen_r_d_7, feq_gen_r_d_8, feq_gen_r_d_9, feq_gen_r_d_10, feq_gen_r_d_11, 
	    feq_gen_r_d_12, feq_gen_r_d_13, feq_gen_r_d_14, feq_gen_r_d_15;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[8], feq_gen_ch_d_3[10];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    char dbetaout[10], depthout[10];
    integer j, l, n;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    char dalphaout[10];
    real bl, bm, jf, br, kl, km;
    integer it;
    real kr;
    integer iy;
    real dbl, dbm, dbr, qcf, dkl, dkm, mal, dtf, mam, mar, dkr;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    real mql, mqm, mqr;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen), 
	    feq_gen_chk_vdatum_unitsys_d_(integer *, char *, char *, char *, ftnlen, 
	    ftnlen, ftnlen);
    extern /* Character */ VOID put8_(char *, ftnlen, real *);
    integer feq_gen_flag_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    real dmal, dmam;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char achr[8];
    real dmar, alpl, oldk, alpm, dmql, mone, alpr, dmqm, yarg, dmqr, drop;
    char jchr[8], kchr[8];
    real topf;
    char tchr[8], aout[13];
    extern /* Character */ VOID put10_(char *, ftnlen, real *);
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char jout[13];
    integer eflag;
    real areaf, dalpl, dalpm, dalpr;
    char qcchr[8];
    extern /* Subroutine */ int xlkt25_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    char khout[13], qcout[13];
    extern /* Subroutine */ int chktaj_(integer *, integer *, real *, integer 
	    *), binser_(char *, integer *, char *, integer *, ftnlen, ftnlen),
	     cuttab_(integer *, real *);
    char dmaout[10];
    integer nstore;
    real mxslot;
    char topout[10], dkhout[10], dmqout[10];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_store_xsec_tab_d_(integer *, integer *, 
	    integer *, char *, integer *, real *, real *, real *, char *, 
	    doublereal *, doublereal *, real *, real *, char *, char *, char *
	    , char *, char *, integer *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    real feq_gen_max_arg_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_530, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_531, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_532, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, fmt_533, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__115 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__117 = { 0, 0, 0, fmt_83, 0 };
    static cilist feq_gen_io_d__118 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, fmt_85, 0 };
    static cilist feq_gen_io_d__120 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__123 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__124 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__145 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, fmt_91, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_93, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_40, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_41, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, fmt_42, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, fmt_43, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_44, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_45, 0 };
    static cilist feq_gen_io_d__158 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__159 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__160 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__164 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__165 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__166 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__168 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__207 = { 0, 0, 0, fmt_9124, 0 };
    static cilist feq_gen_io_d__208 = { 0, 0, 0, fmt_9123, 0 };
    static cilist feq_gen_io_d__209 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__210 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__211 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__212 = { 0, 0, 0, fmt_64, 0 };


/*     + + + PURPOSE + + + */
/*     Output a standard table of elements for a cross section. */
/* SOURCE tabstore.for:699 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE tabstore.for:701 */
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
/* SOURCE tabstore.for:704 */
/*<       integerftp,mesg,ndep,stdout,stdtab,tab >*/
/* SOURCE tabstore.for:705 */
/*<       realstat,xst(pmxpnt,pmxelm),zmin >*/
/* SOURCE tabstore.for:706 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     TAB    - Table number */
/*     STAT   - Station value */
/*     ZMIN   - Minimum elevation */
/*     MESG   - Flag for decreasing conveyance message appearance */
/*     SAVOPT - Function table saving option */
/*     OUTOPT - Output option for the table file for cross section function */
/*               tables */
/*     BETOPT - Option for computing flux coefficients and critical flow */
/*     NDEP   - Number of depth values */
/*     XST    - Storage table for various elements of cross section */
/*     FTP    - next open location in the function table storage */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tabstore.for:727 */
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
/* INCLUDE tabstore.for:728 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE tabstore.for:729 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/* INCLUDE tabstore.for:730 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE tabstore.for:733 */
/*<       integernsave >*/
/* SOURCE tabstore.for:734 */
/*<       parameter(nsave=14) >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE tabstore.for:737 */
/*<       integersoval(nsave),typvec(nsave) >*/
/* SOURCE tabstore.for:738 */
/*<       charactersotab(nsave)*8,outotab(nsave)*8 >*/
/* SOURCE tabstore.for:739 */
/*<       savesotab,soval,typvec >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tabstore.for:742 */
/*<       integerflag,i,it,j,l,n,nstore,type,eflag,iy >*/
/* SOURCE tabstore.for:744 */
/*<        >*/
/* SOURCE tabstore.for:753 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE tabstore.for:760 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE tabstore.for:763 */
/*<       integerlenstr >*/
/* SOURCE tabstore.for:764 */
/*<       characterput8*8,get_tabid*16,put10*10 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tabstore.for:767 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tabstore.for:772 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> xst(feq_storage_xst, 1000);

    feq::IndexedPointer<char> mqflag(feq_storage_mqflag, 1);

    feq::IndexedPointer<char> maflag(feq_storage_maflag, 1);

    feq::IndexedPointer<char> betaflag(feq_storage_betaflag, 1);

    feq::IndexedPointer<char> alphaflag(feq_storage_alphaflag, 1);

    feq::IndexedPointer<char> khflag(feq_storage_khflag, 1);

    /* Function Body */
/* SOURCE tabstore.for:776 */
/*<        >*/
/* SOURCE tabstore.for:781 */
/*<       datasoval/6,8,5,6,8,7,8,10,7,8,11,11,12,15/ >*/
/* SOURCE tabstore.for:785 */
/*<       datatypvec/21,22,20,21,22,23,24,25,30,31,32,33,34,35/ >*/
/* SOURCE tabstore.for:792 */
/*<    40 format(a10,a10,2a13,f10.6,2a10) >*/
/* L40: */
/* SOURCE tabstore.for:793 */
/*<    41 format(a10,a10,2a13,f10.6,a13,2a10) >*/
/* L41: */
/* SOURCE tabstore.for:794 */
/*<    42 format(a10,a10,2a13,f10.6,a13,f10.6,a13,3a10) >*/
/* L42: */
/* SOURCE tabstore.for:796 */
/*<    43 format(a10,a10,2a13,f10.6,2f10.7,4a10) >*/
/* L43: */
/* SOURCE tabstore.for:797 */
/*<    44 format(a10,a10,2a13,f10.6,a13,2f10.7,4a10) >*/
/* L44: */
/* SOURCE tabstore.for:798 */
/*<    45 format(a10,a10,2a13,f10.6,a13,f10.6,a13,2f10.7,5a10) >*/
/* L45: */
/* SOURCE tabstore.for:799 */
/*<    50 format(/,' *BUG:XXX* Save option=',a8,' unknown in TABOUT.') >*/
/* L50: */
/* SOURCE tabstore.for:800 */
/*<    51 format(/,' Elements for section ID: ',a) >*/
/* L51: */
/* SOURCE tabstore.for:801 */
/*<    52  >*/
/* L52: */
/*     English unit system without zone, etc and with zone */
/* SOURCE tabstore.for:804 */
/*<   530  >*/
/* L530: */
/* SOURCE tabstore.for:809 */
/*<   531  >*/
/* L531: */
/*     Metric unit system without zone, etc and with zone */
/* SOURCE tabstore.for:817 */
/*<   532  >*/
/* L532: */
/* SOURCE tabstore.for:822 */
/*<   533  >*/
/* L533: */
/* SOURCE tabstore.for:828 */
/*<    54  >*/
/* L54: */
/* SOURCE tabstore.for:832 */
/*<    55 format(/,' *BUG:XXX* Out option=',a8,' unknown in TABOUT.') >*/
/* L55: */
/* SOURCE tabstore.for:833 */
/*<    56 format(' ',f7.3,3a8,f7.3,a8,f7.3,a8,2f7.3,f8.4,f8.3,a1,4(f8.4,a1)) >*/
/* L56: */
/* SOURCE tabstore.for:835 */
/*<    57 format(f10.0) >*/
/* L57: */
/* SOURCE tabstore.for:836 */
/*<    58  >*/
/* L58: */
/* SOURCE tabstore.for:838 */
/*<    59  >*/
/* L59: */
/* SOURCE tabstore.for:840 */
/*<    60  >*/
/* L60: */
/* SOURCE tabstore.for:843 */
/*<    62  >*/
/* L62: */
/* SOURCE tabstore.for:845 */
/*<    64 format(1x,f10.5,4f10.6,3f10.1) >*/
/* L64: */
/* SOURCE tabstore.for:848 */
/*<    70  >*/
/* L70: */
/* SOURCE tabstore.for:850 */
/*<    71  >*/
/* L71: */
/* SOURCE tabstore.for:852 */
/*<    72  >*/
/* L72: */
/* SOURCE tabstore.for:855 */
/*<    73  >*/
/* L73: */
/* SOURCE tabstore.for:858 */
/*<    74  >*/
/* L74: */
/* SOURCE tabstore.for:861 */
/*<    75  >*/
/* L75: */
/* SOURCE tabstore.for:866 */
/*<    80 format(5x,'Depth Top_width',9x,'Area   Sqrt(Conv)',6x,'Beta') >*/
/* L80: */
/* SOURCE tabstore.for:867 */
/*<    81  >*/
/* L81: */
/* SOURCE tabstore.for:869 */
/*<    82  >*/
/* L82: */
/* SOURCE tabstore.for:871 */
/*<    83  >*/
/* L83: */
/* SOURCE tabstore.for:873 */
/*<    84  >*/
/* L84: */
/* SOURCE tabstore.for:875 */
/*<    85  >*/
/* L85: */
/* SOURCE tabstore.for:878 */
/*<    90 format(a10,a10,2a13,f10.6) >*/
/* L90: */
/* SOURCE tabstore.for:879 */
/*<    91 format(a10,a10,2a13,f10.6,a13) >*/
/* L91: */
/* SOURCE tabstore.for:880 */
/*<    92 format(a10,a10,2a13,f10.6,a13,f10.6,a13) >*/
/* L92: */
/* SOURCE tabstore.for:882 */
/*<    93 format(a10,a10,2a13,f10.6,2f10.7) >*/
/* L93: */
/* SOURCE tabstore.for:883 */
/*<    94 format(a10,a10,2a13,f10.6,a13,2f10.7) >*/
/* L94: */
/* SOURCE tabstore.for:884 */
/*<    95 format(a10,a10,2a13,f10.6,a13,f10.6,a13,2f10.7) >*/
/* L95: */
/* SOURCE tabstore.for:886 */
/*<    98  >*/
/* L98: */
/* SOURCE tabstore.for:890 */
/*<    99 format(/,' Saving TabId= ',a,'  Internal table number=',i5) >*/
/* L99: */
/* *********************************************************************** */
/* SOURCE tabstore.for:892 */
/*<       eflag=0 >*/
    eflag = 0;
/* SOURCE tabstore.for:894 */
/*<       if(grav.gt.15.0)then >*/
    if (grvcom_1.grav > (float)15.) {
/* SOURCE tabstore.for:895 */
/*<       mxslot=0.07 >*/
	mxslot = (float).07;
/* SOURCE tabstore.for:896 */
/*<       else >*/
    } else {
/* SOURCE tabstore.for:897 */
/*<       mxslot=0.02134 >*/
	mxslot = (float).02134;
/* SOURCE tabstore.for:898 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:899 */
/*<       mone=-1. >*/
    mone = (float)-1.;
/* SOURCE tabstore.for:901 */
/*<       tabid=get_tabid(tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, tab);
    s_copy(xtaddc_1.tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE tabstore.for:902 */
/*<       l=lenstr(tabid) >*/
    l = lenstr_(xtaddc_1.tabid, (ftnlen)16);
/* SOURCE tabstore.for:903 */
/*<       write(stdout,51)tabid(1:l) >*/
    feq_gen_io_d__103.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__103);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
    e_wsfe();
/*     TRIM TOP OF TABLE IF IT IS A CLOSED CONDUIT AND THEN CHECK FOR */
/*     CONSISTENCY OF THE TOP WIDTH, AREA, AND FIRST MOMENT OF AREA */
/* SOURCE tabstore.for:908 */
/*<       callcuttab(ndep,xst) >*/
    cuttab_(ndep, &xst[1000]);
/* SOURCE tabstore.for:910 */
/*<       callchktaj(stdout,ndep,xst,flag) >*/
    chktaj_(stdout, ndep, &xst[1000], &feq_gen_flag_d_);
/* SOURCE tabstore.for:915 */
/*<       if(outopt.eq.' ')then >*/
    if (s_cmp(outopt, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) == 0) {
/* SOURCE tabstore.for:916 */
/*<       type=-25 >*/
	feq_gen_type_d_ = -25;
/* SOURCE tabstore.for:917 */
/*<       elseif(outopt.eq.'NOOUT')then >*/
    } else if (s_cmp(outopt, const_cast<char*>("NOOUT"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:918 */
/*<       type=-25 >*/
	feq_gen_type_d_ = -25;
/* SOURCE tabstore.for:919 */
/*<       else >*/
    } else {
/* SOURCE tabstore.for:920 */
/*<       callbinser(outopt,nsave,outotab,it) >*/
	binser_(outopt, &feq_gen_c_d_14, outotab, &it, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:924 */
/*<       if(it.eq.0)then >*/
	if (it == 0) {
/* SOURCE tabstore.for:925 */
/*<       write(stdout,55)outopt >*/
	    feq_gen_io_d__107.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__107);
	    do_fio(&feq_gen_c_d_1, outopt, (ftnlen)8);
	    e_wsfe();
/* SOURCE tabstore.for:926 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE tabstore.for:927 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:928 */
/*<       type=-typvec(it) >*/
	    feq_gen_type_d_ = -typvec[it - 1];
/* SOURCE tabstore.for:929 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:930 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:932 */
/*<       if(gisid.eq.' ')then >*/
    if (s_cmp(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) == 0) {
/* SOURCE tabstore.for:933 */
/*<       gisid=tabid >*/
	s_copy(xtaddc_1.gisid, xtaddc_1.tabid, (ftnlen)16, (ftnlen)16);
/* SOURCE tabstore.for:934 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:935 */
/*<       write(stdout,52)tabid(1:l),type,stat,zmin >*/
    feq_gen_io_d__108.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__108);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*zmin), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE tabstore.for:936 */
/*<       if(outopt.ne.'NOOUT'.and.flag.eq.0)then >*/
    if (s_cmp(outopt, const_cast<char*>("NOOUT"), (ftnlen)8, (ftnlen)5) != 0 && feq_gen_flag_d_ == 0) {
/* SOURCE tabstore.for:937 */
/*<       if(grav.gt.15.0)then >*/
	if (grvcom_1.grav > (float)15.) {
/* SOURCE tabstore.for:938 */
/*<       if(zone=='NONE')then >*/
	    if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) == 0) {
/* SOURCE tabstore.for:939 */
/*<        >*/
		feq_gen_io_d__109.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__109);
		do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, xtaddc_1.gisid, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.easting, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.northing, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&(*zmin), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.feq_gen_slot_depth_d_, (ftnlen)sizeof(
			real));
		e_wsfe();
/* SOURCE tabstore.for:942 */
/*<       else >*/
	    } else {
/* SOURCE tabstore.for:943 */
/*<        >*/
		feq_gen_io_d__110.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__110);
		do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, xtaddc_1.gisid, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.easting, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.northing, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&(*zmin), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.feq_gen_slot_depth_d_, (ftnlen)sizeof(
			real));
		e_wsfe();
/* SOURCE tabstore.for:947 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:948 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:949 */
/*<       if(zone=='NONE')then >*/
	    if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) == 0) {
/* SOURCE tabstore.for:950 */
/*<        >*/
		feq_gen_io_d__111.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__111);
		do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, xtaddc_1.gisid, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.easting, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.northing, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&(*zmin), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.feq_gen_slot_depth_d_, (ftnlen)sizeof(
			real));
		e_wsfe();
/* SOURCE tabstore.for:953 */
/*<       else >*/
	    } else {
/* SOURCE tabstore.for:954 */
/*<        >*/
		feq_gen_io_d__112.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__112);
		do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, xtaddc_1.gisid, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.easting, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.northing, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&(*zmin), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.feq_gen_slot_depth_d_, (ftnlen)sizeof(
			real));
		e_wsfe();
/* SOURCE tabstore.for:958 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:959 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:960 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:962 */
/*<       write(stdout,54) >*/
    feq_gen_io_d__113.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__113);
    e_wsfe();
/* SOURCE tabstore.for:963 */
/*<       if(flag.eq.0)then >*/
    if (feq_gen_flag_d_ == 0) {
/* SOURCE tabstore.for:964 */
/*<       if(outopt.eq.'OUT20')then >*/
	if (s_cmp(outopt, const_cast<char*>("OUT20"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:965 */
/*<       write(stdtab,80) >*/
	    feq_gen_io_d__114.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__114);
	    e_wsfe();
/* SOURCE tabstore.for:966 */
/*<       elseif(outopt.eq.'OUT21'.or.outopt.eq.'OUT1')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT21"), (ftnlen)8, (ftnlen)5) == 0 || s_cmp(
		outopt, const_cast<char*>("OUT1"), (ftnlen)8, (ftnlen)4) == 0) {
/* SOURCE tabstore.for:967 */
/*<       write(stdtab,81) >*/
	    feq_gen_io_d__115.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__115);
	    e_wsfe();
/* SOURCE tabstore.for:968 */
/*<       elseif(outopt.eq.'OUT22'.or.outopt.eq.'OUT12')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT22"), (ftnlen)8, (ftnlen)5) == 0 || s_cmp(
		outopt, const_cast<char*>("OUT12"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:969 */
/*<       write(stdtab,82) >*/
	    feq_gen_io_d__116.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__116);
	    e_wsfe();
/* SOURCE tabstore.for:970 */
/*<       elseif(outopt.eq.'OUT23')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT23"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:971 */
/*<       write(stdtab,83) >*/
	    feq_gen_io_d__117.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__117);
	    e_wsfe();
/* SOURCE tabstore.for:972 */
/*<       elseif(outopt.eq.'OUT24')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT24"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:973 */
/*<       write(stdtab,84) >*/
	    feq_gen_io_d__118.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__118);
	    e_wsfe();
/* SOURCE tabstore.for:974 */
/*<       elseif(outopt.eq.'OUT25')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT25"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:975 */
/*<       write(stdtab,85) >*/
	    feq_gen_io_d__119.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__119);
	    e_wsfe();
/* SOURCE tabstore.for:976 */
/*<       elseif(outopt.eq.'OUT30')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT30"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:977 */
/*<       write(stdtab,70) >*/
	    feq_gen_io_d__120.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__120);
	    e_wsfe();
/* SOURCE tabstore.for:978 */
/*<       elseif(outopt.eq.'OUT31')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT31"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:979 */
/*<       write(stdtab,71) >*/
	    feq_gen_io_d__121.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__121);
	    e_wsfe();
/* SOURCE tabstore.for:980 */
/*<       elseif(outopt.eq.'OUT32')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT32"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:981 */
/*<       write(stdtab,72) >*/
	    feq_gen_io_d__122.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__122);
	    e_wsfe();
/* SOURCE tabstore.for:982 */
/*<       elseif(outopt.eq.'OUT33')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT33"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:983 */
/*<       write(stdtab,73) >*/
	    feq_gen_io_d__123.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__123);
	    e_wsfe();
/* SOURCE tabstore.for:984 */
/*<       elseif(outopt.eq.'OUT34')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT34"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:985 */
/*<       write(stdtab,74) >*/
	    feq_gen_io_d__124.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__124);
	    e_wsfe();
/* SOURCE tabstore.for:986 */
/*<       elseif(outopt.eq.'OUT35')then >*/
	} else if (s_cmp(outopt, const_cast<char*>("OUT35"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:987 */
/*<       write(stdtab,75) >*/
	    feq_gen_io_d__125.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__125);
	    e_wsfe();
/* SOURCE tabstore.for:988 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:989 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:991 */
/*<        >*/
    feq_gen_chk_vdatum_unitsys_d_(stdout, vdatum, unitsys, const_cast<char*>(" during output/store of a\
 cross-section table"), (ftnlen)8, (ftnlen)8, (ftnlen)45);
/* SOURCE tabstore.for:996 */
/*<       oldk=-1.0 >*/
    oldk = (float)-1.;
/* SOURCE tabstore.for:997 */
/*<       do100j=1,ndep >*/
    feq_gen_i_d_1 = *ndep;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/*       OUTPUT ALL VALUES TO STDOUT EVEN THOUGH NOT REQUESTED FOR THE */
/*       TABLE TO BE OUTPUT TO STDTAB OR TO BE STORED. */
/* SOURCE tabstore.for:1002 */
/*<       tchr=put8(xst(j,2)) >*/
	put8_(feq_gen_ch_d_2, (ftnlen)8, &xst[j + 1998]);
	s_copy(tchr, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1003 */
/*<       achr=put8(xst(j,3)) >*/
	put8_(feq_gen_ch_d_2, (ftnlen)8, &xst[j + 2997]);
	s_copy(achr, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1004 */
/*<       kchr=put8(xst(j,5)) >*/
	put8_(feq_gen_ch_d_2, (ftnlen)8, &xst[j + 4995]);
	s_copy(kchr, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1005 */
/*<       jchr=put8(xst(j,4)) >*/
	put8_(feq_gen_ch_d_2, (ftnlen)8, &xst[j + 3996]);
	s_copy(jchr, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1006 */
/*<       qcchr=put8(xst(j,13)) >*/
	put8_(feq_gen_ch_d_2, (ftnlen)8, &xst[j + 12987]);
	s_copy(qcchr, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1008 */
/*<        >*/
	feq_gen_io_d__133.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__133);
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 999], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, tchr, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, achr, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, kchr, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, jchr, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 6993], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, qcchr, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 13986], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 14985], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 16983], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 17982], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, khflag + j, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 19980], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, betaflag + j, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 18981], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, alphaflag + j, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 20979], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, maflag + j, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, (char *)&xst[j + 21978], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, mqflag + j, (ftnlen)1);
	e_wsfe();
/*     B               POWERK_VS_J, POWERQC_VS_J, POWERK_VS_A, */
/*     C               POWERQC_VS_A */
/* SOURCE tabstore.for:1020 */
/*<       if(flag.eq.0)then >*/
	if (feq_gen_flag_d_ == 0) {
/* SOURCE tabstore.for:1021 */
/*<       callvar_decimal(xst(j,1),depthout) >*/
	    feq_gen_var_decimal_d_(&xst[j + 999], depthout, (ftnlen)10);
/* SOURCE tabstore.for:1023 */
/*<       callvar_decimal(xst(j,2),topout) >*/
	    feq_gen_var_decimal_d_(&xst[j + 1998], topout, (ftnlen)10);
/* SOURCE tabstore.for:1025 */
/*<       callvar_decimal(xst(j,3),aout) >*/
	    feq_gen_var_decimal_d_(&xst[j + 2997], aout, (ftnlen)13);
/* SOURCE tabstore.for:1027 */
/*<       callvar_decimal(xst(j,4),jout) >*/
	    feq_gen_var_decimal_d_(&xst[j + 3996], jout, (ftnlen)13);
/* SOURCE tabstore.for:1029 */
/*<       callvar_decimal(xst(j,5),khout) >*/
	    feq_gen_var_decimal_d_(&xst[j + 4995], khout, (ftnlen)13);
/* SOURCE tabstore.for:1031 */
/*<       callvar_decimal(xst(j,13),qcout) >*/
	    feq_gen_var_decimal_d_(&xst[j + 12987], qcout, (ftnlen)13);

/*          call var_decimal(xst(j,18), */
/*     o                        dkhout) */
/*          call var_decimal(xst(j,19), */
/*     o                        dalphaout) */
/*          call var_decimal(xst(j,20), */
/*     o                        dbetaout) */
/*          call var_decimal(xst(j,21), */
/*     o                        dmaout) */
/*          call var_decimal(xst(j,22), */
/*     o                        dmqout) */
/* SOURCE tabstore.for:1045 */
/*<       dkhout=put10(xst(j,18)) >*/
	    put10_(feq_gen_ch_d_3, (ftnlen)10, &xst[j + 17982]);
	    s_copy(dkhout, feq_gen_ch_d_3, (ftnlen)10, (ftnlen)10);
/* SOURCE tabstore.for:1046 */
/*<       dalphaout=put10(xst(j,19)) >*/
	    put10_(feq_gen_ch_d_3, (ftnlen)10, &xst[j + 18981]);
	    s_copy(dalphaout, feq_gen_ch_d_3, (ftnlen)10, (ftnlen)10);
/* SOURCE tabstore.for:1047 */
/*<       dbetaout=put10(xst(j,20)) >*/
	    put10_(feq_gen_ch_d_3, (ftnlen)10, &xst[j + 19980]);
	    s_copy(dbetaout, feq_gen_ch_d_3, (ftnlen)10, (ftnlen)10);
/* SOURCE tabstore.for:1048 */
/*<       dmaout=put10(xst(j,21)) >*/
	    put10_(feq_gen_ch_d_3, (ftnlen)10, &xst[j + 20979]);
	    s_copy(dmaout, feq_gen_ch_d_3, (ftnlen)10, (ftnlen)10);
/* SOURCE tabstore.for:1049 */
/*<       dmqout=put10(xst(j,22)) >*/
	    put10_(feq_gen_ch_d_3, (ftnlen)10, &xst[j + 21978]);
	    s_copy(dmqout, feq_gen_ch_d_3, (ftnlen)10, (ftnlen)10);
/* SOURCE tabstore.for:1052 */
/*<       if(outopt.eq.'OUT20')then >*/
	    if (s_cmp(outopt, const_cast<char*>("OUT20"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1053 */
/*<       write(stdtab,90)depthout,topout,aout,khout,xst(j,6) >*/
		feq_gen_io_d__145.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__145);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE tabstore.for:1055 */
/*<       elseif(outopt.eq.'OUT21'.or.outopt.eq.'OUT1')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT21"), (ftnlen)8, (ftnlen)5) == 0 || 
		    s_cmp(outopt, const_cast<char*>("OUT1"), (ftnlen)8, (ftnlen)4) == 0) {
/* SOURCE tabstore.for:1056 */
/*<       write(stdtab,91)depthout,topout,aout,khout,xst(j,6),jout >*/
		feq_gen_io_d__146.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__146);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, jout, (ftnlen)13);
		e_wsfe();
/* SOURCE tabstore.for:1058 */
/*<       elseif(outopt.eq.'OUT22'.or.outopt.eq.'OUT12')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT22"), (ftnlen)8, (ftnlen)5) == 0 || 
		    s_cmp(outopt, const_cast<char*>("OUT12"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1059 */
/*<        >*/
		feq_gen_io_d__147.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__147);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, jout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 6993], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, qcout, (ftnlen)13);
		e_wsfe();
/* SOURCE tabstore.for:1061 */
/*<       elseif(outopt.eq.'OUT23')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT23"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1062 */
/*<        >*/
		feq_gen_io_d__148.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__148);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 13986], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 14985], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE tabstore.for:1064 */
/*<       elseif(outopt.eq.'OUT24')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT24"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1065 */
/*<        >*/
		feq_gen_io_d__149.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__149);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, jout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 13986], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 14985], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE tabstore.for:1067 */
/*<       elseif(outopt.eq.'OUT25')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT25"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1068 */
/*<        >*/
		feq_gen_io_d__150.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__150);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, jout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 6993], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, qcout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 13986], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 14985], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE tabstore.for:1071 */
/*<       elseif(outopt.eq.'OUT30')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT30"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1072 */
/*<        >*/
		feq_gen_io_d__151.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__151);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, dkhout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dbetaout, (ftnlen)10);
		e_wsfe();
/* SOURCE tabstore.for:1074 */
/*<       elseif(outopt.eq.'OUT31')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT31"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1075 */
/*<        >*/
		feq_gen_io_d__152.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__152);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, jout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, dkhout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dbetaout, (ftnlen)10);
		e_wsfe();
/* SOURCE tabstore.for:1077 */
/*<       elseif(outopt.eq.'OUT32')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT32"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1078 */
/*<        >*/
		feq_gen_io_d__153.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__153);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, jout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 6993], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, qcout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, dkhout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dbetaout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dalphaout, (ftnlen)10);
		e_wsfe();
/* SOURCE tabstore.for:1081 */
/*<       elseif(outopt.eq.'OUT33')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT33"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1082 */
/*<        >*/
		feq_gen_io_d__154.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__154);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 13986], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 14985], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, dkhout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dbetaout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dmaout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dmqout, (ftnlen)10);
		e_wsfe();
/* SOURCE tabstore.for:1085 */
/*<       elseif(outopt.eq.'OUT34')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT34"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1086 */
/*<        >*/
		feq_gen_io_d__155.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__155);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, jout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 13986], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 14985], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, dkhout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dbetaout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dmaout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dmqout, (ftnlen)10);
		e_wsfe();
/* SOURCE tabstore.for:1089 */
/*<       elseif(outopt.eq.'OUT35')then >*/
	    } else if (s_cmp(outopt, const_cast<char*>("OUT35"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE tabstore.for:1090 */
/*<        >*/
		feq_gen_io_d__156.ciunit = *stdtab;
		s_wsfe(&feq_gen_io_d__156);
		do_fio(&feq_gen_c_d_1, depthout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, topout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, aout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, khout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, jout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 6993], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, qcout, (ftnlen)13);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 13986], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 14985], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, dkhout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dbetaout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dmaout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dmqout, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, dalphaout, (ftnlen)10);
		e_wsfe();
/* SOURCE tabstore.for:1094 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:1095 */
/*<       endif >*/
	}
/*       CHECK FOR NON-INCREASING CONVEYANCE */
/* SOURCE tabstore.for:1099 */
/*<       if(xst(j,5).le.oldk.and.mesg.eq.1)then >*/
	if (xst[j + 4995] <= oldk && *mesg == 1) {
/* SOURCE tabstore.for:1100 */
/*<       if(xst(j,2).gt.mxslot)then >*/
	    if (xst[j + 1998] > mxslot) {
/* SOURCE tabstore.for:1101 */
/*<       drop=((xst(j,5)**2-oldk**2)/oldk**2)*100.0 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = xst[j + 4995];
/* Computing 2nd power */
		feq_gen_r_d_2 = oldk;
/* Computing 2nd power */
		feq_gen_r_d_3 = oldk;
		drop = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) - static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3)) * (float)
			100.;
/* SOURCE tabstore.for:1102 */
/*<       write(stdout,58)xst(j,1),abs(drop) >*/
		feq_gen_io_d__158.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__158);
		do_fio(&feq_gen_c_d_1, (char *)&xst[j + 999], (ftnlen)sizeof(real));
		feq_gen_r_d_1 = dabs(drop);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE tabstore.for:1103 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:1104 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:1105 */
/*<       oldk=xst(j,5) >*/
	oldk = xst[j + 4995];
/* SOURCE tabstore.for:1107 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE tabstore.for:1108 */
/*<       if(flag.eq.0.and.outopt.ne.'NOOUT')then >*/
    if (feq_gen_flag_d_ == 0 && s_cmp(outopt, const_cast<char*>("NOOUT"), (ftnlen)8, (ftnlen)5) != 0) {
/*       WRITE THE TERMINATING LINE FOR EACH TABLE TO STDTAB. */
/* SOURCE tabstore.for:1110 */
/*<       write(stdtab,57)mone >*/
	feq_gen_io_d__159.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__159);
	do_fio(&feq_gen_c_d_1, (char *)&mone, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE tabstore.for:1111 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:1113 */
/*<       write(stdout,98) >*/
    feq_gen_io_d__160.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__160);
    e_wsfe();
/* SOURCE tabstore.for:1115 */
/*<       if(savopt.ne.'NOSAVE'.and.flag.eq.0)then >*/
    if (s_cmp(savopt, const_cast<char*>("NOSAVE"), (ftnlen)8, (ftnlen)6) != 0 && feq_gen_flag_d_ == 0) {
/*       WE HAVE A SAVE OPERATION TO COMPLETE.  FIND THE NUMBER OF */
/*       VALUES TO STORE FOR EACH TABLE TYPE */
/* SOURCE tabstore.for:1119 */
/*<       callbinser(savopt,nsave,sotab,it) >*/
	binser_(savopt, &feq_gen_c_d_14, sotab, &it, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1122 */
/*<       if(it.eq.0)then >*/
	if (it == 0) {
/* SOURCE tabstore.for:1123 */
/*<       write(stdout,50)savopt >*/
	    feq_gen_io_d__161.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__161);
	    do_fio(&feq_gen_c_d_1, savopt, (ftnlen)8);
	    e_wsfe();
/* SOURCE tabstore.for:1124 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE tabstore.for:1125 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:1126 */
/*<       nstore=soval(it) >*/
	    nstore = soval[it - 1];
/* SOURCE tabstore.for:1127 */
/*<       type=typvec(it) >*/
	    feq_gen_type_d_ = typvec[it - 1];
/*         IS THERE ENOUGH ROOM IN FTAB/ITAB FOR THE TABLE? */
/* SOURCE tabstore.for:1131 */
/*<       n=xtioff+ndep*nstore >*/
	    n = *ndep * nstore + 32;
/* SOURCE tabstore.for:1132 */
/*<       if(ftp+n.gt.mrftab)then >*/
	    if (*ftp + n > 13000001) {
/* SOURCE tabstore.for:1133 */
/*<       write(stdout,60)ftp+n-mrftab >*/
		feq_gen_io_d__164.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__164);
		feq_gen_i_d_1 = *ftp + n - 13000001;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE tabstore.for:1134 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE tabstore.for:1135 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:1137 */
/*<       write(stdout,99)tabid(1:l),tab >*/
	    feq_gen_io_d__165.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__165);
	    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
	    do_fio(&feq_gen_c_d_1, (char *)&(*tab), (ftnlen)sizeof(integer));
	    e_wsfe();
/*         STORE THE HEADER INFORMATION FOR THE TABLE */
/* SOURCE tabstore.for:1139 */
/*<       if(ftpnt(tab).ne.0)then >*/
	    if (ftablea_1.ftpnt[*tab - 1] != 0) {
/* SOURCE tabstore.for:1140 */
/*<       write(stdout,*)' FTPNT(TAB)=',ftpnt(tab),' TAB=',tab >*/
		feq_gen_io_d__166.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__166);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FTPNT(TAB)="), (ftnlen)12);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ftablea_1.ftpnt[*tab - 1], (
			ftnlen)sizeof(integer));
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TAB="), (ftnlen)5);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*tab), (ftnlen)sizeof(integer))
			;
		e_wsle();
/* SOURCE tabstore.for:1141 */
/*<       callkil(25,tab,eflag) >*/
		kil_(&feq_gen_c_d_25, tab, &eflag);
/* SOURCE tabstore.for:1144 */
/*<       stop'Abnormal stop. Error found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Error found."), (ftnlen)27);
/* SOURCE tabstore.for:1145 */
/*<       endif >*/
	    }
/*         Store the table for subsequent use in this run of FEQUTL. */
/* SOURCE tabstore.for:1148 */
/*<       max_arg=xst(ndep,1) >*/
	    feq_gen_max_arg_d_ = xst[*ndep + 999];
/* SOURCE tabstore.for:1149 */
/*<        >*/
	    feq_gen_store_xsec_tab_d_(stdout, ndep, &feq_gen_type_d_, xtaddc_1.tabid, tab, stat,
		     zmin, &xtadd_1.feq_gen_slot_depth_d_, xtaddc_1.gisid, &
		    xtadd_1.easting, &xtadd_1.northing, &xst[1000], &
		    feq_gen_max_arg_d_, zone, hgrid, vdatum, unitsys, basis, ftp, (
		    ftnlen)16, (ftnlen)16, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		    ftnlen)8, (ftnlen)8);
/*         Add test of the lookup in types 30-35. */
/* SOURCE tabstore.for:1156 */
/*<       if(type.eq.9999)then >*/
	    if (feq_gen_type_d_ == 9999) {
/* SOURCE tabstore.for:1157 */
/*<       write(stdout,*)' ' >*/
		feq_gen_io_d__168.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__168);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
		e_wsle();
/* SOURCE tabstore.for:1158 */
/*<       write(stdout,*)' Testing lookup for types: 30-35' >*/
		feq_gen_io_d__169.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__169);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Testing lookup for types: 30-35"), (
			ftnlen)32);
		e_wsle();
/* SOURCE tabstore.for:1161 */
/*<        >*/
		xlkt25_(&ftablea_1.ftpnt[*tab - 1], &xst[1000], &areaf, &topf,
			 &dtf, &jf, &kl, &dkl, &bl, &dbl, &alpl, &dalpl, &qcf,
			 &mal, &dmal, &mql, &dmql);
/* SOURCE tabstore.for:1167 */
/*<       doiy=2,ndep >*/
		feq_gen_i_d_1 = *ndep;
		for (iy = 2; iy <= feq_gen_i_d_1; ++iy) {
/* SOURCE tabstore.for:1168 */
/*<       yarg=0.5*(xst(iy-1,1)+xst(iy,1)) >*/
		    yarg = static_cast<double>((static_cast<double>(xst[iy + 998]) + xst[iy + 999])) * (float).5;
/* SOURCE tabstore.for:1170 */
/*<        >*/
		    xlkt25_(&ftablea_1.ftpnt[*tab - 1], &yarg, &areaf, &topf, 
			    &dtf, &jf, &km, &dkm, &bm, &dbm, &alpm, &dalpm, &
			    qcf, &mam, &dmam, &mqm, &dmqm);
/* SOURCE tabstore.for:1176 */
/*<        >*/
		    xlkt25_(&ftablea_1.ftpnt[*tab - 1], &xst[iy + 999], &
			    areaf, &topf, &dtf, &jf, &kr, &dkr, &br, &dbr, &
			    alpr, &dalpr, &qcf, &mar, &dmar, &mqr, &dmqr);
/* SOURCE tabstore.for:1182 */
/*<        >*/
		    feq_gen_io_d__207.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__207);
		    do_fio(&feq_gen_c_d_1, (char *)&xst[iy + 999], (ftnlen)sizeof(real)
			    );
/* Computing MAX */
		    feq_gen_r_d_7 = (feq_gen_r_d_1 = static_cast<double>(kr) - kl, dabs(feq_gen_r_d_1));
		    feq_gen_r_d_6 = (static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xst[iy + 999]) - xst[iy + 998])) * (static_cast<double>(static_cast<double>(dkl) + static_cast<double>(dkm) * (
			    float)4.) + dkr)) / (float)6.) - (static_cast<double>(kr) - kl)) / dmax(
			    feq_gen_r_d_7,(float).01);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_6, (ftnlen)sizeof(real));
/* Computing MAX */
		    feq_gen_r_d_9 = (feq_gen_r_d_2 = static_cast<double>(br) - bl, dabs(feq_gen_r_d_2));
		    feq_gen_r_d_8 = (static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xst[iy + 999]) - xst[iy + 998])) * (static_cast<double>(static_cast<double>(dbl) + static_cast<double>(dbm) * (
			    float)4.) + dbr)) / (float)6.) - (static_cast<double>(br) - bl)) / dmax(
			    feq_gen_r_d_9,(float).002);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_8, (ftnlen)sizeof(real));
/* Computing MAX */
		    feq_gen_r_d_11 = (feq_gen_r_d_3 = static_cast<double>(alpr) - alpl, dabs(feq_gen_r_d_3));
		    feq_gen_r_d_10 = (static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xst[iy + 999]) - xst[iy + 998])) * (static_cast<double>(static_cast<double>(dalpl) + static_cast<double>(dalpm) 
			    * (float)4.) + dalpr)) / (float)6.) - (static_cast<double>(alpr) - alpl)) 
			    / dmax(feq_gen_r_d_11,(float).002);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_10, (ftnlen)sizeof(real));
/* Computing MAX */
		    feq_gen_r_d_13 = (feq_gen_r_d_4 = static_cast<double>(mar) - mal, dabs(feq_gen_r_d_4));
		    feq_gen_r_d_12 = (static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xst[iy + 999]) - xst[iy + 998])) * (static_cast<double>(static_cast<double>(dmal) + static_cast<double>(dmam) * 
			    (float)4.) + dmar)) / (float)6.) - (static_cast<double>(mar) - mal)) / 
			    dmax(feq_gen_r_d_13,(float).002);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_12, (ftnlen)sizeof(real));
/* Computing MAX */
		    feq_gen_r_d_15 = (feq_gen_r_d_5 = static_cast<double>(mqr) - mql, dabs(feq_gen_r_d_5));
		    feq_gen_r_d_14 = (static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xst[iy + 999]) - xst[iy + 998])) * (static_cast<double>(static_cast<double>(dmql) + static_cast<double>(dmqm) * 
			    (float)4.) + dmqr)) / (float)6.) - (static_cast<double>(mqr) - mql)) / 
			    dmax(feq_gen_r_d_15,(float).002);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_14, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE tabstore.for:1194 */
/*<  9124 format(f10.4,6(1pe12.4)) >*/
/* SOURCE tabstore.for:1197 */
/*<       kl=kr >*/
		    kl = kr;
/* SOURCE tabstore.for:1198 */
/*<       dkl=dkr >*/
		    dkl = dkr;
/* SOURCE tabstore.for:1199 */
/*<       bl=br >*/
		    bl = br;
/* SOURCE tabstore.for:1200 */
/*<       dbl=dbr >*/
		    dbl = dbr;
/* SOURCE tabstore.for:1201 */
/*<       alpl=alpr >*/
		    alpl = alpr;
/* SOURCE tabstore.for:1202 */
/*<       dalpl=dalpr >*/
		    dalpl = dalpr;
/* SOURCE tabstore.for:1203 */
/*<       mal=mar >*/
		    mal = mar;
/* SOURCE tabstore.for:1204 */
/*<       dmal=dmar >*/
		    dmal = dmar;
/* SOURCE tabstore.for:1205 */
/*<       mql=mqr >*/
		    mql = mqr;
/* SOURCE tabstore.for:1206 */
/*<       dmql=dmqr >*/
		    dmql = dmqr;
/* SOURCE tabstore.for:1207 */
/*<        >*/
		    feq_gen_io_d__208.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__208);
		    do_fio(&feq_gen_c_d_1, (char *)&xst[iy + 999], (ftnlen)sizeof(real)
			    );
		    feq_gen_r_d_1 = static_cast<double>(topf) - xst[iy + 1998];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    feq_gen_r_d_2 = static_cast<double>(areaf) - xst[iy + 2997];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
		    feq_gen_r_d_3 = static_cast<double>(jf) - xst[iy + 3996];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
/* Computing 2nd power */
		    feq_gen_r_d_5 = xst[iy + 4995];
		    feq_gen_r_d_4 = static_cast<double>(kr) - static_cast<double>(feq_gen_r_d_5) * feq_gen_r_d_5;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_4, (ftnlen)sizeof(real));
		    feq_gen_r_d_6 = static_cast<double>(dkr) - static_cast<double>(static_cast<double>(xst[iy + 4995]) * (float)2.) * xst[iy + 17982];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_6, (ftnlen)sizeof(real));
		    feq_gen_r_d_7 = static_cast<double>(qcf) - xst[iy + 12987];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_7, (ftnlen)sizeof(real));
		    feq_gen_r_d_8 = static_cast<double>(br) - xst[iy + 5994];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_8, (ftnlen)sizeof(real));
		    feq_gen_r_d_9 = static_cast<double>(dbr) - xst[iy + 19980];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_9, (ftnlen)sizeof(real));
		    feq_gen_r_d_10 = static_cast<double>(alpr) - xst[iy + 6993];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_10, (ftnlen)sizeof(real));
		    feq_gen_r_d_11 = static_cast<double>(dalpr) - xst[iy + 18981];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_11, (ftnlen)sizeof(real));
		    feq_gen_r_d_12 = static_cast<double>(mar) - xst[iy + 13986];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_12, (ftnlen)sizeof(real));
		    feq_gen_r_d_13 = static_cast<double>(dmar) - xst[iy + 20979];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_13, (ftnlen)sizeof(real));
		    feq_gen_r_d_14 = static_cast<double>(mqr) - xst[iy + 14985];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_14, (ftnlen)sizeof(real));
		    feq_gen_r_d_15 = static_cast<double>(dmqr) - xst[iy + 21978];
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_15, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE tabstore.for:1218 */
/*<  9123 format(f10.4,15(1pe12.4)) >*/
/* SOURCE tabstore.for:1220 */
/*<       enddo >*/
		}
/* SOURCE tabstore.for:1221 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:1225 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:1226 */
/*<       endif >*/
    }
/*     Added May 22, 1998: definition of XSV(*) contents */
/*     Extended 13 March 2003 */
/*     Offset    Value */
/*     1         Maximum depth-y */
/*     2         Top width */
/*     3         Area */
/*     4         First moment of area about water surface */
/*     5         Square root of conveyance- kh */
/*     6         Beta */
/*     7         Alpha */
/*     8         dBeta/dy */
/*     9         dAlpha/dy */
/*     10        Critical flow from momentum */
/*     11        Critical flow from energy */
/*     12        Critcal flow assuming Alpha=beta=1 */
/*     13        Critical flow that is selected by user: 10, 11, or 12 */
/*     14        MA- correction of volumes for sinuousity */
/*     15        MQ- correction of momentum for sinuosity */
/*     16        Total wetted perimeter- added May 22, 1998 */
/*     17        Average Manning's n value for the cross section */
/*     18        dkh/dy computed by cubic-spline fit */
/*     19        dalpha/dy computed by cubic-spline fit */
/*     20        dbeta/dy computed by cubic-spline fit */
/*     21        dma/dy computed by cubic-spline fit */
/*     22        dmq/dy computed by cubic-spline fit */
/* SOURCE tabstore.for:1256 */
/*<       if(betopt(1:7).eq.'NEWBETA'.and.flag.eq.0)then >*/
    if (s_cmp(betopt, const_cast<char*>("NEWBETA"), (ftnlen)7, (ftnlen)7) == 0 && feq_gen_flag_d_ == 0) {
/* SOURCE tabstore.for:1257 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__209.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__209);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE tabstore.for:1258 */
/*<       write(stdout,*)' Estimates of critical flow:' >*/
	feq_gen_io_d__210.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__210);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Estimates of critical flow:"), (ftnlen)28);
	e_wsle();
/* SOURCE tabstore.for:1259 */
/*<       write(stdout,62) >*/
	feq_gen_io_d__211.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__211);
	e_wsfe();
/* SOURCE tabstore.for:1260 */
/*<       do900j=1,ndep >*/
	feq_gen_i_d_1 = *ndep;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/*                          Y,        Beta,    dBeta/dy   Alpha */
/*      dAlpha/dy  Qcm           Qce        Qcsimple */
/* SOURCE tabstore.for:1263 */
/*<        >*/
	    feq_gen_io_d__212.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__212);
	    do_fio(&feq_gen_c_d_1, (char *)&xst[j + 999], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xst[j + 5994], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xst[j + 7992], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xst[j + 6993], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xst[j + 8991], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xst[j + 9990], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xst[j + 10989], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xst[j + 11988], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tabstore.for:1265 */
/*<   900 continue >*/
/* L900: */
	}
/* SOURCE tabstore.for:1266 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:1268 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE tabstore.for:1269 */
/*<       stop'Abnormal stop. Potential BUG found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Potential BUG found."), (ftnlen)35);
/* SOURCE tabstore.for:1270 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:1271 */
/*<       return >*/
    return 0;
/* SOURCE tabstore.for:1272 */
/*<       end >*/
} /* tabout_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tabstore.for:1277 */
/*<       subroutineget_xs_location(stdout,rm,easting,northing) >*/
/* Subroutine */ int feq_gen_get_xs_location_d_(integer *stdout, doublereal *rm, 
	doublereal *easting, doublereal *northing)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:757* Flow-line station=\002,f12.4\
,\002 overflows flow-line data\002)";
    static char fmt_52[] = "(/,\002 *ERR:758* Flow-line station=\002,f12.4\
,\002 underflows flow-line data\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__213 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__214 = { 0, 0, 0, fmt_52, 0 };


/*     Get the location of the cross section from the stored flow-line data */
/* SOURCE tabstore.for:1281 */
/*<       implicitnone >*/
/* SOURCE tabstore.for:1282 */
/*<       integerstdout >*/
/* SOURCE tabstore.for:1283 */
/*<       real*8rm,easting,northing >*/
/* INCLUDE tabstore.for:1285 */
/*     Data structures and parameters for handling assignment */
/*     of Easting and Northing values to cross section tables */
/*     interpolated by XSINTERP. */
/* SOURCE flowline.cmn:5 */
/*<       integerfl_point_max >*/
/* SOURCE flowline.cmn:7 */
/*<       parameter(fl_point_max=5000) >*/
/* SOURCE flowline.cmn:9 */
/*<       integerfl_present,fl_pnt_knt,l >*/
/* SOURCE flowline.cmn:11 */
/*<       real*8rm_origin,s_atrmorg,rm_factor,s_begin >*/
/* SOURCE flowline.cmn:13 */
/*<        >*/
/* SOURCE flowline.cmn:17 */
/*<        >*/
/*     Definitions */
/*     L - initial pointer in search. */
/*     FL_PNT_KNT - number of points on the current flow line. */
/*     RM_ORIGIN - distance along the flow line at the point */
/*                 defining the stationing to be used in FEQ. */
/*                 This is often in miles, called river miles */
/*                 but it need not be.  This is any convenient */
/*                 point that has a given or assigned value of */
/*                 stationing.  It need not be zero! */
/*     S_ATRMORG-  Distance along the flow line at RM_ORIGIN in the units used */
/*                 for the coordinate points that define the polyline */
/*                 representing the flow line. */
/*     RM_FACTOR-  number used to multiply the units used */
/*                 for RM_ORIGIN to get the units used in S_ATRMORG. */
/*                 If the stationing in FEQ is in miles and the */
/*                 coordinate points on the flow line are given in */
/*                 feet then RM_FACTOR = 5280. */
/*     S_BEGIN- initial value to use for the cumulative distance along */
/*              flow line in its coordinate units. */
/*     FL_PRESENT- 1 if a flow line is known, 0 otherwise */
/*     FL_DISTANCE(*)-distance along the flow line at each coordinate point */
/*                     on the polyline in FEQ stationing units. */
/*     FL_EASTING(*)- the x-coordinate for a flow-line point */
/*     FL_NORTHING(*)- the y-coordinate for a flow-line point */
/*     Local */
/*     **********************FORMATS************************************* */
/* SOURCE tabstore.for:1290 */
/*<    50  >*/
/* SOURCE tabstore.for:1292 */
/*<    52  >*/
/* *********************************************************************** */
/*     Find interval in flow-line distance that contains RM. */
/* SOURCE tabstore.for:1297 */
/*<       if(rm.ge.fl_distance(l))then >*/
/* L50: */
/* L52: */
    if (*rm >= flitems_1.feq_gen_fl_distance_d_[flitems_1.l - 1]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE tabstore.for:1299 */
/*<       if(rm.gt.fl_distance(fl_pnt_knt))then >*/
	if (*rm > flitems_1.feq_gen_fl_distance_d_[flitems_1.feq_gen_fl_pnt_knt_d_ - 1]) {
/* SOURCE tabstore.for:1300 */
/*<       write(stdout,50)rm >*/
	    feq_gen_io_d__213.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__213);
	    do_fio(&feq_gen_c_d_1, (char *)&(*rm), (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE tabstore.for:1301 */
/*<       stop'Abnormal stop. Error found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Error found."), (ftnlen)27);
/* SOURCE tabstore.for:1302 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:1303 */
/*<   100 continue >*/
L100:
/* SOURCE tabstore.for:1304 */
/*<       if(rm.gt.fl_distance(l+1))then >*/
	    if (*rm > flitems_1.feq_gen_fl_distance_d_[flitems_1.l]) {
/* SOURCE tabstore.for:1305 */
/*<       l=l+1 >*/
		++flitems_1.l;
/* SOURCE tabstore.for:1306 */
/*<       goto100 >*/
		goto L100;
/* SOURCE tabstore.for:1307 */
/*<       endif >*/
	    }
/* SOURCE tabstore.for:1308 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:1309 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE tabstore.for:1311 */
/*<       if(rm.lt.fl_distance(1))then >*/
	if (*rm < flitems_1.feq_gen_fl_distance_d_[0]) {
/* SOURCE tabstore.for:1312 */
/*<       write(stdout,52)rm >*/
	    feq_gen_io_d__214.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__214);
	    do_fio(&feq_gen_c_d_1, (char *)&(*rm), (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE tabstore.for:1313 */
/*<       stop'Abnormal stop.  Error found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Error found."), (ftnlen)28);
/* SOURCE tabstore.for:1314 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:1315 */
/*<   110 continue >*/
L110:
/* SOURCE tabstore.for:1316 */
/*<       l=l-1 >*/
	    --flitems_1.l;
/* SOURCE tabstore.for:1317 */
/*<       if(rm.lt.fl_distance(l))goto110 >*/
	    if (*rm < flitems_1.feq_gen_fl_distance_d_[flitems_1.l - 1]) {
		goto L110;
	    }
/* SOURCE tabstore.for:1318 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:1319 */
/*<       endif >*/
    }
/*     At this point L defines the low argument end of the */
/*     interval containing the argument. */
/*     Interpolate linearly for the values */
/* SOURCE tabstore.for:1325 */
/*<        >*/
    *easting = flitems_1.feq_gen_fl_easting_d_[flitems_1.l - 1] + (*rm - 
	    flitems_1.feq_gen_fl_distance_d_[flitems_1.l - 1]) * (
	    flitems_1.feq_gen_fl_easting_d_[flitems_1.l] - flitems_1.feq_gen_fl_easting_d_[
	    flitems_1.l - 1]) / (flitems_1.feq_gen_fl_distance_d_[flitems_1.l] - 
	    flitems_1.feq_gen_fl_distance_d_[flitems_1.l - 1]);
/* SOURCE tabstore.for:1328 */
/*<        >*/
    *northing = flitems_1.feq_gen_fl_northing_d_[flitems_1.l - 1] + (*rm - 
	    flitems_1.feq_gen_fl_distance_d_[flitems_1.l - 1]) * (
	    flitems_1.feq_gen_fl_northing_d_[flitems_1.l] - flitems_1.feq_gen_fl_northing_d_[
	    flitems_1.l - 1]) / (flitems_1.feq_gen_fl_distance_d_[flitems_1.l] - 
	    flitems_1.feq_gen_fl_distance_d_[flitems_1.l - 1]);
/* SOURCE tabstore.for:1332 */
/*<       return >*/
    return 0;
/* SOURCE tabstore.for:1333 */
/*<       end >*/
} /* get_xs_location__ */




/* SOURCE tabstore.for:1340 */
/*<       subroutineixtout(stdtab,stdout,adrs,begtab,endtab) >*/
/* Subroutine */ int ixtout_(integer *stdtab, integer *stdout, integer *adrs, 
	integer *begtab, integer *endtab)
{
    /* Initialized data */

    static char prform[80*12+1] = "(F10.5,F10.3,1P,2E13.5,0PF10.4)          \
                                       (F10.5,F10.3,1P,2E13.5,0PF10.4,1PE13.\
5)                                         (F10.5,F10.3,1P,2E13.5,0PF10.4,1P\
E13.5,0PF10.4,1PE13.5)                         (F10.5,F10.3,1P,2E13.5,0P3F10\
.4)                                                (F10.5,F10.3,1P,2E13.5,0P\
F10.4,1PE13.5,0P2F10.4)                                (F10.5,F10.3,1P,2E13.\
5,0PF10.4,1PE13.5,0PF10.4,1PE13.5,0P2F10.4)                (F10.5,F10.3,1P,2\
E13.5,0PF10.4,2(1pe10.4e1))                                    (F10.5,F10.3,\
1P,2E13.5,0PF10.4,1PE13.5,2(1pe10.4e1))                            (F10.5,F1\
0.3,1P,2E13.5,0PF10.4,1PE13.5,0PF10.4,1PE13.5,3(1pe10.4e1))            (F10.\
5,F10.3,1P,2E13.5,0P3F10.4,4(1pe10.4e1))                                   (\
F10.5,F10.3,1P,2E13.5,0PF10.4,1PE13.5,0P2F10.4,4(1pe10.4e1))                \
   (F10.5,F10.3,1P,2E13.5,0PF10.4,1PE13.5,0PF10.4,1PE13.5,0P2F10.4,5(1pe10.4\
e1))   ";

    /* Format strings */
    static char fmt_52[] = "(\002TABID= \002,a,/,\002TYPE=\002,i5,/,\002STAT\
ION=\002,1pe12.5,\002 GISID=\002,a,\002 EASTING=\002,0pf15.2,\002 NORTHING\
=\002,f15.2,/,\002;\002,5x,\002Interpolated between tables: \002,a,\002 and\
 \002,a,/,\002ELEVATION=\002,1pe12.5,17x,\002 EXT=-99.900000\002,\002 FAC=1.\
000 SLOT=\002,0pf10.3)";
    static char fmt_521[] = "(\002TABID= \002,a,/,\002TYPE=\002,i5,/,\002STA\
TION=\002,1pe12.5,\002 GISID=\002,a,\002 EASTING=\002,0pf15.2,\002 NORTHING\
=\002,f15.2,/,\002;\002,5x,\002Interpolated between tables: \002,a,\002 and\
 \002,a,/,\002ELEVATION=\002,1pe12.5,17x,\002 EXT=-30.449520\002,\002 FAC=1.\
000 SLOT=\002,0pf10.3)";
    static char fmt_53[] = "(\002TABID= \002,a,/,\002TYPE=\002,i5,/,\002ZO\
NE=\002,a8,\002 HGRID=\002,a8,\002 VDATUM=\002,a8,\002 UNITSYS=\002,a8,\002 \
BASIS=\002,a8,/,\002STATION=\002,1pe12.5,\002 GISID=\002,a,\002 EASTING=\002\
,0pf15.2,\002 NORTHING=\002,f15.2,/,\002;\002,5x,\002Interpolated between ta\
bles: \002,a,\002 and \002,a,/,\002ELEVATION=\002,1pe12.5,17x,\002 EXT=-99.9\
00000\002,\002 FAC=1.000 SLOT=\002,0pf10.3)";
    static char fmt_531[] = "(\002TABID= \002,a,/,\002TYPE=\002,i5,/,\002ZON\
E=\002,a8,\002 HGRID=\002,a8,\002 VDATUM=\002,a8,\002 UNITSYS=\002,a8,\002 B\
ASIS=\002,a8,/,\002STATION=\002,1pe12.5,\002 GISID=\002,a,\002 EASTING=\002,\
0pf15.2,\002 NORTHING=\002,f15.2,/,\002;\002,5x,\002Interpolated between tab\
les: \002,a,\002 and \002,a,/,\002ELEVATION=\002,1pe12.5,17x,\002 EXT=-30.44\
9520\002,\002 FAC=1.000 SLOT=\002,0pf10.3)";
    static char fmt_70[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta    dkh/dy  dbeta/dy\002)";
    static char fmt_71[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment    dkh/dy  dbeta/dy\002)";
    static char fmt_72[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,5x,\002Alpha\002,8x,\002Critq    dkh/d\
y  dbeta/dy dalpha/dy\002)";
    static char fmt_73[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta\002,8x,\002Ma\002,8x,\002Mq    dkh/dy  dbeta/dy    dma/\
dy    dmq/dy\002)";
    static char fmt_74[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,8x,\002Ma\002,8x,\002Mq    dkh/dy  dbe\
ta/dy    dma/dy    dmq/dy\002)";
    static char fmt_75[] = "(5x,\002Depth Top_width\002,9x,\002Area   Sqrt(C\
onv)\002,6x,\002Beta First_moment\002,5x,\002Alpha\002,8x,\002Critq\002,8x\
,\002Ma\002,8x,\002Mq    dkh/dy  dbeta/dy dalpha/dy    dma/dy    dmq/dy\002)";
    static char fmt_80[] = "(5x,\002DEPTH TOP WIDTH\002,9x,\002AREA   SQRT(C\
ONV)\002,6x,\002BETA\002)";
    static char fmt_81[] = "(5x,\002DEPTH TOP WIDTH\002,9x,\002AREA   SQRT(C\
ONV)\002,6x,\002BETA FIRST MOMENT\002)";
    static char fmt_82[] = "(5x,\002DEPTH TOP WIDTH\002,9x,\002AREA   SQRT(C\
ONV)\002,6x,\002BETA FIRST MOMENT\002,5x,\002ALPHA\002,8x,\002CRITQ\002)";
    static char fmt_83[] = "(5x,\002DEPTH TOP WIDTH\002,9x,\002AREA   SQRT(C\
ONV)\002,6x,\002BETA\002,8x,\002MA\002,8x,\002MQ\002)";
    static char fmt_84[] = "(5x,\002DEPTH TOP WIDTH\002,9x,\002AREA   SQRT(C\
ONV)\002,6x,\002BETA FIRST MOMENT\002,8x,\002MA\002,8x,\002MQ\002)";
    static char fmt_85[] = "(5x,\002DEPTH TOP WIDTH\002,9x,\002AREA   SQRT(C\
ONV)\002,6x,\002BETA FIRST MOMENT\002,5x,\002ALPHA\002,8x,\002CRITQ\002,8x\
,\002MA\002,8x,\002MQ\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[8];
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    char begtabid[16], endtabid[16];
    extern /* Character */ VOID feq_gen_get_chr8_from_ft_d_(char *, ftnlen, integer *);
    doublereal northing;
    integer feq_gen_i_d_, j;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer ha, la;
    doublereal rm;
    integer lbeg;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ltab, lend, tabn;
    real elev;
    integer xoff;
    real stat;
    char zone[8];
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char tabid[16], hgrid[8], gisid[16], basis[8], vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    doublereal easting;
    char unitsys[8];
    extern /* Subroutine */ int feq_gen_get_xs_location_d_(integer *, doublereal *, 
	    doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__240 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__241 = { 0, 0, 0, fmt_521, 0 };
    static cilist feq_gen_io_d__242 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__243 = { 0, 0, 0, fmt_531, 0 };
    static cilist feq_gen_io_d__245 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__246 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__247 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__248 = { 0, 0, 0, fmt_83, 0 };
    static cilist feq_gen_io_d__249 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__250 = { 0, 0, 0, fmt_85, 0 };
    static cilist feq_gen_io_d__251 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__252 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__253 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__254 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__255 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__256 = { 0, 0, 0, fmt_75, 0 };


/*     + + + PURPOSE + + + */
/*     Output the cross section table at ADRS. Output a label */
/*     to show that it is an interpolated table. */
/* SOURCE tabstore.for:1347 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tabstore.for:1349 */
/*<       integeradrs,begtab,endtab,stdout,stdtab >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDTAB - Fortran unit number for output of function tables */
/*     STDOUT - Fortran unit number for standard user output */
/*     ADRS   - Address of function table */
/*     BEGTAB - Upstream table number for cross section used to define */
/*               the interpolated cross section table being output */
/*     ENDTAB - Downstream table number for cross section used to define */
/*               the interpolated cross section table being output */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tabstore.for:1361 */
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
/* INCLUDE tabstore.for:1362 */
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
/* INCLUDE tabstore.for:1363 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE tabstore.for:1364 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE tabstore.for:1365 */
/*     Data structures and parameters for handling assignment */
/*     of Easting and Northing values to cross section tables */
/*     interpolated by XSINTERP. */
/* SOURCE flowline.cmn:5 */
/*<       integerfl_point_max >*/
/* SOURCE flowline.cmn:7 */
/*<       parameter(fl_point_max=5000) >*/
/* SOURCE flowline.cmn:9 */
/*<       integerfl_present,fl_pnt_knt,l >*/
/* SOURCE flowline.cmn:11 */
/*<       real*8rm_origin,s_atrmorg,rm_factor,s_begin >*/
/* SOURCE flowline.cmn:13 */
/*<        >*/
/* SOURCE flowline.cmn:17 */
/*<        >*/
/*     Definitions */
/*     L - initial pointer in search. */
/*     FL_PNT_KNT - number of points on the current flow line. */
/*     RM_ORIGIN - distance along the flow line at the point */
/*                 defining the stationing to be used in FEQ. */
/*                 This is often in miles, called river miles */
/*                 but it need not be.  This is any convenient */
/*                 point that has a given or assigned value of */
/*                 stationing.  It need not be zero! */
/*     S_ATRMORG-  Distance along the flow line at RM_ORIGIN in the units used */
/*                 for the coordinate points that define the polyline */
/*                 representing the flow line. */
/*     RM_FACTOR-  number used to multiply the units used */
/*                 for RM_ORIGIN to get the units used in S_ATRMORG. */
/*                 If the stationing in FEQ is in miles and the */
/*                 coordinate points on the flow line are given in */
/*                 feet then RM_FACTOR = 5280. */
/*     S_BEGIN- initial value to use for the cumulative distance along */
/*              flow line in its coordinate units. */
/*     FL_PRESENT- 1 if a flow line is known, 0 otherwise */
/*     FL_DISTANCE(*)-distance along the flow line at each coordinate point */
/*                     on the polyline in FEQ stationing units. */
/*     FL_EASTING(*)- the x-coordinate for a flow-line point */
/*     FL_NORTHING(*)- the y-coordinate for a flow-line point */
/* INCLUDE tabstore.for:1366 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE tabstore.for:1369 */
/*<       characterprform(12)*80 >*/
/* SOURCE tabstore.for:1370 */
/*<       saveprform >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tabstore.for:1373 */
/*<       integerha,i,j,la,tabn,type,xoff,ltab,lbeg,lend >*/
/* SOURCE tabstore.for:1375 */
/*<       realelev,stat >*/
/* SOURCE tabstore.for:1377 */
/*<       real*8easting,northing,rm >*/
/* SOURCE tabstore.for:1379 */
/*<       character*16tabid,begtabid,endtabid,gisid >*/
/* SOURCE tabstore.for:1380 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/*     Called program units */
/* SOURCE tabstore.for:1383 */
/*<       integerlenstr >*/
/* SOURCE tabstore.for:1384 */
/*<       characterget_tabid*16,get_chr8_from_ft*8 >*/
/* SOURCE tabstore.for:1385 */
/*<       externallenstr,get_tabid,get_xs_location,get_chr8_from_ft >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tabstore.for:1389 */
/*<        >*/
/* SOURCE tabstore.for:1407 */
/*<    52  >*/
/* L52: */
/* SOURCE tabstore.for:1412 */
/*<   521  >*/
/* L521: */
/* SOURCE tabstore.for:1418 */
/*<    53  >*/
/* L53: */
/* SOURCE tabstore.for:1425 */
/*<   531  >*/
/* L531: */
/* SOURCE tabstore.for:1433 */
/*<    70  >*/
/* L70: */
/* SOURCE tabstore.for:1435 */
/*<    71  >*/
/* L71: */
/* SOURCE tabstore.for:1437 */
/*<    72  >*/
/* L72: */
/* SOURCE tabstore.for:1440 */
/*<    73  >*/
/* L73: */
/* SOURCE tabstore.for:1443 */
/*<    74  >*/
/* L74: */
/* SOURCE tabstore.for:1446 */
/*<    75  >*/
/* L75: */
/* SOURCE tabstore.for:1452 */
/*<    80 format(5x,'DEPTH TOP WIDTH',9x,'AREA   SQRT(CONV)',6x,'BETA') >*/
/* L80: */
/* SOURCE tabstore.for:1453 */
/*<    81  >*/
/* L81: */
/* SOURCE tabstore.for:1455 */
/*<    82  >*/
/* L82: */
/* SOURCE tabstore.for:1457 */
/*<    83  >*/
/* L83: */
/* SOURCE tabstore.for:1459 */
/*<    84  >*/
/* L84: */
/* SOURCE tabstore.for:1461 */
/*<    85  >*/
/* L85: */
/* *********************************************************************** */
/*     GET KEY VALUES */
/* SOURCE tabstore.for:1467 */
/*<       tabn=itab(adrs+1) >*/
    tabn = itab[(0 + (0 + (*adrs + 1 - 0 << 2))) / 4];
/* SOURCE tabstore.for:1468 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE tabstore.for:1469 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE tabstore.for:1470 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE tabstore.for:1471 */
/*<       stat=ftab(adrs+4) >*/
    stat = ftab[*adrs + 4];
/* SOURCE tabstore.for:1472 */
/*<       elev=ftab(adrs+5) >*/
    elev = ftab[*adrs + 5];
/*     30 October 2007:  NO, NO, NO do not apply the datum shift */
/*     when interpolating cross sections.  If the datum shift is applied */
/*     to all cross sections when they are input to fequtl.  Therefore */
/*     applying it to interpolated sections is incorrect.  The datum shift */
/*     requested by the user is already present in the invert elevations */
/*     of the cross sections used as the basis for interpolation! */
/*     Apply the datum shift to the datum for depth */
/*      elev = elev + g_vdatum_shift */
/* SOURCE tabstore.for:1483 */
/*<       tabid=get_tabid(tabn) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tabn);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE tabstore.for:1484 */
/*<       gisid=tabid >*/
    s_copy(gisid, tabid, (ftnlen)16, (ftnlen)16);
/* SOURCE tabstore.for:1485 */
/*<       ltab=lenstr(tabid) >*/
    ltab = lenstr_(tabid, (ftnlen)16);
/* SOURCE tabstore.for:1486 */
/*<       begtabid=get_tabid(begtab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, begtab);
    s_copy(begtabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE tabstore.for:1487 */
/*<       lbeg=lenstr(begtabid) >*/
    lbeg = lenstr_(begtabid, (ftnlen)16);
/* SOURCE tabstore.for:1488 */
/*<       endtabid=get_tabid(endtab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, endtab);
    s_copy(endtabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE tabstore.for:1489 */
/*<       lend=lenstr(endtabid) >*/
    lend = lenstr_(endtabid, (ftnlen)16);
/*     Get the location values (other than easting and northing), */
/*     from the ADRS. */
/* SOURCE tabstore.for:1493 */
/*<       zone=get_chr8_from_ft(adrs+22) >*/
    feq_gen_i_d_1 = *adrs + 22;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_1);
    s_copy(zone, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1494 */
/*<       hgrid=get_chr8_from_ft(adrs+24) >*/
    feq_gen_i_d_1 = *adrs + 24;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_1);
    s_copy(hgrid, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1495 */
/*<       vdatum=get_chr8_from_ft(adrs+26) >*/
    feq_gen_i_d_1 = *adrs + 26;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_1);
    s_copy(vdatum, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1496 */
/*<       unitsys=get_chr8_from_ft(adrs+28) >*/
    feq_gen_i_d_1 = *adrs + 28;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_1);
    s_copy(unitsys, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1497 */
/*<       basis=get_chr8_from_ft(adrs+30) >*/
    feq_gen_i_d_1 = *adrs + 30;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_1);
    s_copy(basis, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE tabstore.for:1500 */
/*<       if(fl_present.eq.1)then >*/
    if (flitems_1.feq_gen_fl_present_d_ == 1) {
/*       We have a defining flow line.  Compute the location for the */
/*       interpolated table. */
/* SOURCE tabstore.for:1503 */
/*<       rm=dble(stat) >*/
	rm = (doublereal) stat;
/* SOURCE tabstore.for:1504 */
/*<       callget_xs_location(stdout,rm,easting,northing) >*/
	feq_gen_get_xs_location_d_(stdout, &rm, &easting, &northing);
/* SOURCE tabstore.for:1506 */
/*<       else >*/
    } else {
/* SOURCE tabstore.for:1507 */
/*<       easting=0.d0 >*/
	easting = 0.;
/* SOURCE tabstore.for:1508 */
/*<       northing=0.d0 >*/
	northing = 0.;
/* SOURCE tabstore.for:1509 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:1511 */
/*<       if(zone=='NONE')then >*/
    if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) == 0) {
/* SOURCE tabstore.for:1512 */
/*<       if(grav.gt.15.0)then >*/
	if (grvcom_1.grav > (float)15.) {
/* SOURCE tabstore.for:1513 */
/*<        >*/
	    feq_gen_io_d__240.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__240);
	    do_fio(&feq_gen_c_d_1, tabid, ltab);
	    feq_gen_i_d_1 = -feq_gen_type_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, begtabid, lbeg);
	    do_fio(&feq_gen_c_d_1, endtabid, lend);
	    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 7).data(), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tabstore.for:1517 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:1518 */
/*<        >*/
	    feq_gen_io_d__241.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__241);
	    do_fio(&feq_gen_c_d_1, tabid, ltab);
	    feq_gen_i_d_1 = -feq_gen_type_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, begtabid, lbeg);
	    do_fio(&feq_gen_c_d_1, endtabid, lend);
	    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 7).data(), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tabstore.for:1522 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:1523 */
/*<       else >*/
    } else {
/* SOURCE tabstore.for:1524 */
/*<       if(grav.gt.15.0)then >*/
	if (grvcom_1.grav > (float)15.) {
/* SOURCE tabstore.for:1525 */
/*<        >*/
	    feq_gen_io_d__242.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__242);
	    do_fio(&feq_gen_c_d_1, tabid, ltab);
	    feq_gen_i_d_1 = -feq_gen_type_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, begtabid, lbeg);
	    do_fio(&feq_gen_c_d_1, endtabid, lend);
	    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 7).data(), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tabstore.for:1530 */
/*<       else >*/
	} else {
/* SOURCE tabstore.for:1531 */
/*<        >*/
	    feq_gen_io_d__243.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__243);
	    do_fio(&feq_gen_c_d_1, tabid, ltab);
	    feq_gen_i_d_1 = -feq_gen_type_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, begtabid, lbeg);
	    do_fio(&feq_gen_c_d_1, endtabid, lend);
	    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 7).data(), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tabstore.for:1536 */
/*<       endif >*/
	}
/* SOURCE tabstore.for:1537 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:1539 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE tabstore.for:1541 */
/*<       if(type.ge.30)then >*/
    if (feq_gen_type_d_ >= 30) {
/* SOURCE tabstore.for:1542 */
/*<       type=type-4 >*/
	feq_gen_type_d_ += -4;
/* SOURCE tabstore.for:1543 */
/*<       endif >*/
    }
/* SOURCE tabstore.for:1544 */
/*<       goto(20,21,22,23,24,25,30,31,32,33,34,35),type-19 >*/
    switch (feq_gen_type_d_ - 19) {
	case 1:  goto L20;
	case 2:  goto L21;
	case 3:  goto L22;
	case 4:  goto L23;
	case 5:  goto L24;
	case 6:  goto L25;
	case 7:  goto L30;
	case 8:  goto L31;
	case 9:  goto L32;
	case 10:  goto L33;
	case 11:  goto L34;
	case 12:  goto L35;
    }
/* SOURCE tabstore.for:1546 */
/*<    20 continue >*/
L20:
/* SOURCE tabstore.for:1547 */
/*<       write(stdtab,80) >*/
    feq_gen_io_d__245.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__245);
    e_wsfe();
/* SOURCE tabstore.for:1548 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1549 */
/*<    21 continue >*/
L21:
/* SOURCE tabstore.for:1550 */
/*<       write(stdtab,81) >*/
    feq_gen_io_d__246.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__246);
    e_wsfe();
/* SOURCE tabstore.for:1551 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1552 */
/*<    22 continue >*/
L22:
/* SOURCE tabstore.for:1553 */
/*<       write(stdtab,82) >*/
    feq_gen_io_d__247.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__247);
    e_wsfe();
/* SOURCE tabstore.for:1554 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1555 */
/*<    23 continue >*/
L23:
/* SOURCE tabstore.for:1556 */
/*<       write(stdtab,83) >*/
    feq_gen_io_d__248.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__248);
    e_wsfe();
/* SOURCE tabstore.for:1557 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1558 */
/*<    24 continue >*/
L24:
/* SOURCE tabstore.for:1559 */
/*<       write(stdtab,84) >*/
    feq_gen_io_d__249.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__249);
    e_wsfe();
/* SOURCE tabstore.for:1560 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1561 */
/*<    25 continue >*/
L25:
/* SOURCE tabstore.for:1562 */
/*<       write(stdtab,85) >*/
    feq_gen_io_d__250.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__250);
    e_wsfe();
/* SOURCE tabstore.for:1563 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1565 */
/*<    30 continue >*/
L30:
/* SOURCE tabstore.for:1566 */
/*<       write(stdtab,70) >*/
    feq_gen_io_d__251.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__251);
    e_wsfe();
/* SOURCE tabstore.for:1567 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1568 */
/*<    31 continue >*/
L31:
/* SOURCE tabstore.for:1569 */
/*<       write(stdtab,71) >*/
    feq_gen_io_d__252.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__252);
    e_wsfe();
/* SOURCE tabstore.for:1570 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1571 */
/*<    32 continue >*/
L32:
/* SOURCE tabstore.for:1572 */
/*<       write(stdtab,72) >*/
    feq_gen_io_d__253.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__253);
    e_wsfe();
/* SOURCE tabstore.for:1573 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1574 */
/*<    33 continue >*/
L33:
/* SOURCE tabstore.for:1575 */
/*<       write(stdtab,73) >*/
    feq_gen_io_d__254.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__254);
    e_wsfe();
/* SOURCE tabstore.for:1576 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1577 */
/*<    34 continue >*/
L34:
/* SOURCE tabstore.for:1578 */
/*<       write(stdtab,74) >*/
    feq_gen_io_d__255.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__255);
    e_wsfe();
/* SOURCE tabstore.for:1579 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1580 */
/*<    35 continue >*/
L35:
/* SOURCE tabstore.for:1581 */
/*<       write(stdtab,75) >*/
    feq_gen_io_d__256.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__256);
    e_wsfe();
/* SOURCE tabstore.for:1582 */
/*<       goto40 >*/
    goto L40;
/* SOURCE tabstore.for:1585 */
/*<    40 continue >*/
L40:
/* SOURCE tabstore.for:1588 */
/*<       do100i=la,ha,xoff >*/
    feq_gen_i_d_1 = ha;
    feq_gen_i_d_2 = xoff;
    for (feq_gen_i_d_ = la; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE tabstore.for:1589 */
/*<       write(stdtab,prform(type-19))(ftab(i+j),j=0,xoff-1) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdtab;
	feq_gen_ci_d_1.cifmt = feq::format_text(prform + (feq_gen_type_d_ - 20) * 80, 80);
	s_wsfe(&feq_gen_ci_d_1);
	feq_gen_i_d_3 = xoff - 1;
	for (j = 0; j <= feq_gen_i_d_3; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(feq_gen_i_d_ + j).data(), (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE tabstore.for:1590 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE tabstore.for:1591 */
/*<       write(stdtab,'(F10.0)')-1.0 >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdtab;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(F10.0)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&c_b728, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE tabstore.for:1593 */
/*<       return >*/
    return 0;
/* SOURCE tabstore.for:1594 */
/*<       end >*/
} /* ixtout_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
