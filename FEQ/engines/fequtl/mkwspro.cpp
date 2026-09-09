/* mkwspro.f -- translated by f2c (version 20240504).
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

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON fldway_ is declared in common.hpp. */

#define fldway_1 fldway_

/* COMMON fldwyc_ is declared in common.hpp. */

#define fldwyc_1 fldwyc_

/* COMMON nrdzcm_ is declared in common.hpp. */

#define nrdzcm_1 nrdzcm_

/* COMMON sincom_ is declared in common.hpp. */

#define sincom_1 sincom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;




/* SOURCE mkwspro.for:4 */
/*<       subroutinemkwspro(stdin,stdout,tabdir,eflag) >*/
/* Subroutine */ int mkwspro_(integer *stdin, integer *stdout, integer *
	feq_storage_tabdir, integer *eflag)
{
    /* Format strings */
    static char fmt_2[] = "(5x,a)";
    static char fmt_4[] = "(a)";
    static char fmt_52[] = "(/,\002 Cross section name=\002,a)";
    static char fmt_54[] = "(/,\002 Processing cross section in \002,a,\002 \
format.\002)";
    static char fmt_55[] = "(/,\002 *ERR:751* Format= \002,a,\002 unknown in\
 MKWSPRO.\002/,11x,\002 Must be: FEQX, FEQXLST, or FEQXEXT\002)";
    static char fmt_56[] = "(\002XS   \002,a5,f10.2)";
    static char fmt_57[] = "(/,\002 The cross section in WSPRO format is:\
\002)";
    static char fmt_58[] = "(\002GR\002,8x,f10.2,\002,\002,f9.2,5x,f10.2,\
\002,\002,f9.2,5x,f10.2,\002,\002,f9.2)";
    static char fmt_60[] = "(\002N \002,8x,7f10.3)";
    static char fmt_62[] = "(\002SA\002,8x,7f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, m, feq_gen_r_d_, m3, m7;
    real sa[200];
    char feq_gen_name_d_[7];
    integer mode;
    real left;
    char zone[8];
    real zmax;
    char hgrid[8], basis[8];
    real right;
    extern /* Subroutine */ int infeqx_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, integer *, real *, real *, integer *, real *, real *, 
	    real *, char *, char *, char *, real *, char *, char *, char *, 
	    char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen), infqxe_(integer *, integer *, integer *, integer 
	    *, integer *, real *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, real *, char *, char *, char *, real *,
	     real *, integer *, real *, real *, integer *, char *, char *, 
	    char *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    integer oldsub;
    real nwspro[200];
    char betopt[8], outopt[8], savopt[8], vdatum[8], format[8], unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, fmt_2, 0 };
    static cilist feq_gen_io_d__3 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__4 = { 0, 0, 0, fmt_4, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__21 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_62, 0 };


/*     Make a WSPRO compatiable cross section description from */
/*     an FEQX, FEQXLST, or FEQXEXT cross section description. */
/*     Initial version does not cover all options. */
/* SOURCE mkwspro.for:12 */
/*<       implicitnone >*/
/* SOURCE mkwspro.for:13 */
/*<       integereflag,stdin,stdout >*/
/* SOURCE mkwspro.for:14 */
/*<       integertabdir(*) >*/
/* INCLUDE mkwspro.for:16 */
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
/* INCLUDE mkwspro.for:17 */
/*     COMMON FOR THE UPSTREAM CROSS SECTION */

/* SOURCE xscomu.cmn:3 */
/*<       integernpntu,nsubu,navmu,tabu,ndepu,mxpntu,usgsu,snflgu >*/
/* SOURCE xscomu.cmn:4 */
/*<       integersbu(pmxpnt),nvaru(pmxsub),nnyu(pmxsub) >*/
/* SOURCE xscomu.cmn:5 */
/*<       realstatu,zminu,zmaxu >*/
/* SOURCE xscomu.cmn:6 */
/*<        >*/

/* SOURCE xscomu.cmn:10 */
/*<        >*/
/*     SNFLGU- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points. */
/*     SNU- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSNU- LINE SEGMENT N VALUE */
/*     NVARU- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: 0-N IS CONSTANT, */
/*           1-N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           2-N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*           IF N VARIES WITH DEPTH, THE N VALUE APPLIES TO THE WHOLE */
/*           SUBSECTION.  NO VARIATION OF ROUGHNESS PERMITTED ON LINE SEGMENTS */
/*           IN THE SUBSECTION. */
/*     NATYU-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATNU- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYU- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS.  VALUE IS ZERO IF NVARU FOR THE */
/*          SUBSECTION IS ZERO.  THE N DEPTH PAIR AT ZERO DEPTH IS STORED */
/*          AND COUNTED WITH NVARU > 0 FOR THE SUBSECTION. */
/*     YSMXU- MAXIMUM DEPTH IN EACH SUBSECTION. */
/* INCLUDE mkwspro.for:18 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/* INCLUDE mkwspro.for:19 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE mkwspro.for:20 */
/*     COMMON FOR THE SINUOUSITY TABLE IN THE CHANNEL COMMAND. */
/*     USED TO REMEMBER THE VALUES THAT ARE FINALLY NEEDED TO */
/*     DEFINE THE SINUOUSITY VALUES ON THE CROSS SECTION BOUNDARY */
/* SOURCE sincom.cmn:5 */
/*<       integernumoff(pmxsec),numsec,jaxis,dir,vartyp >*/
/* SOURCE sincom.cmn:8 */
/*<        >*/
/* SOURCE sincom.cmn:13 */
/*<       common/sincom/dir,jaxis,numsec,eps,vartyp,numoff,stl,offset,sinu >*/
/* SOURCE sincom.cmn:18 */
/*<       save/sincom/ >*/
/*     Called program units */
/* SOURCE mkwspro.for:24 */
/*<       externalinfeqx,infqxe >*/
/*     Local */
/* SOURCE mkwspro.for:27 */
/*<       integeri,j,mode,m3,r,oldsub,m7,m >*/
/* SOURCE mkwspro.for:28 */
/*<       realleft,right,zmax,nwspro(pmxsub),sa(pmxsub) >*/
/* SOURCE mkwspro.for:29 */
/*<        >*/
/* SOURCE mkwspro.for:33 */
/*<       charactername*7,format*8 >*/
/*     **************************FORMATS********************************* */
/* SOURCE mkwspro.for:35 */
/*<     2 format(5x,a) >*/
/* SOURCE mkwspro.for:36 */
/*<     4 format(a) >*/
/* SOURCE mkwspro.for:38 */
/*<    52 format(/,' Cross section name=',a) >*/
/* SOURCE mkwspro.for:39 */
/*<    54 format(/,' Processing cross section in ',a,' format.') >*/
/* SOURCE mkwspro.for:40 */
/*<    55  >*/
/* SOURCE mkwspro.for:42 */
/*<    56 format('XS   ',a5,f10.2) >*/
/* SOURCE mkwspro.for:43 */
/*<    57 format(/,' The cross section in WSPRO format is:') >*/
/* SOURCE mkwspro.for:44 */
/*<    58 format('GR',8x,f10.2,',',f9.2,5x,f10.2,',',f9.2,5x,f10.2,',',f9.2) >*/
/* SOURCE mkwspro.for:46 */
/*<    60 format('N ',8x,7f10.3) >*/
/* SOURCE mkwspro.for:47 */
/*<    62 format('SA',8x,7f10.2) >*/
/* *********************************************************************** */
/*     Read the name to place with the cross section in the WSPRO format. */
/* SOURCE mkwspro.for:50 */
/*<       read(stdin,2)name >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L2: */
/* L4: */
/* L52: */
/* L54: */
/* L55: */
/* L56: */
/* L57: */
/* L58: */
/* L60: */
/* L62: */
    feq_gen_io_d__1.ciunit = *stdin;
    s_rsfe(&feq_gen_io_d__1);
    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)7);
    e_rsfe();
/* SOURCE mkwspro.for:51 */
/*<       write(stdout,52)name >*/
    feq_gen_io_d__3.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__3);
    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)7);
    e_wsfe();
/*     Get the format of the FEQUTL cross section */
/* SOURCE mkwspro.for:55 */
/*<       read(stdin,4)format >*/
    feq_gen_io_d__4.ciunit = *stdin;
    s_rsfe(&feq_gen_io_d__4);
    do_fio(&feq_gen_c_d_1, format, (ftnlen)8);
    e_rsfe();
/* SOURCE mkwspro.for:56 */
/*<       write(stdout,54)format >*/
    feq_gen_io_d__6.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__6);
    do_fio(&feq_gen_c_d_1, format, (ftnlen)8);
    e_wsfe();
/* SOURCE mkwspro.for:58 */
/*<       if(format.eq.'FEQXEXT')then >*/
    if (s_cmp(format, const_cast<char*>("FEQXEXT"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE mkwspro.for:60 */
/*<        >*/
	infqxe_(stdin, stdout, &tabdir[1], eflag, &xscomu_1.tabu, &
		xscomu_1.statu, &xscomu_1.npntu, &xscomu_1.nsubu, xscomu_1.xu,
		 xscomu_1.zu, xscomu_1.sbu, xscomu_1.nu, &left, &right, 
		savopt, outopt, betopt, &zmax, xscomu_1.lsnu, xscomu_1.nvaru, 
		xscomu_1.natyu, xscomu_1.yatnu, xscomu_1.nnyu, zone, hgrid, 
		vdatum, unitsys, basis, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE mkwspro.for:68 */
/*<       elseif(format.eq.'FEQX')then >*/
    } else if (s_cmp(format, const_cast<char*>("FEQX"), (ftnlen)8, (ftnlen)4) == 0) {
/* SOURCE mkwspro.for:69 */
/*<       mode=1 >*/
	mode = 1;
/* SOURCE mkwspro.for:70 */
/*<        >*/
	infeqx_(stdin, stdout, &xscomu_1.mxpntu, &mode, &tabdir[1], eflag, &
		xscomu_1.tabu, &xscomu_1.statu, &xscomu_1.npntu, &
		xscomu_1.nsubu, &xscomu_1.navmu, xscomu_1.xu, xscomu_1.zu, 
		xscomu_1.sbu, xscomu_1.nu, &left, &right, savopt, outopt, 
		betopt, &zmax, zone, hgrid, vdatum, unitsys, basis, (ftnlen)8,
		 (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		ftnlen)8, (ftnlen)8);
/* SOURCE mkwspro.for:76 */
/*<       elseif(format.eq.'FEQXLST')then >*/
    } else if (s_cmp(format, const_cast<char*>("FEQXLST"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE mkwspro.for:77 */
/*<       mode=2 >*/
	mode = 2;
/* SOURCE mkwspro.for:78 */
/*<        >*/
	infeqx_(stdin, stdout, &xscomu_1.mxpntu, &mode, &tabdir[1], eflag, &
		xscomu_1.tabu, &xscomu_1.statu, &xscomu_1.npntu, &
		xscomu_1.nsubu, &xscomu_1.navmu, xscomu_1.xu, xscomu_1.zu, 
		xscomu_1.sbu, xscomu_1.nu, &left, &right, savopt, outopt, 
		betopt, &zmax, zone, hgrid, vdatum, unitsys, basis, (ftnlen)8,
		 (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		ftnlen)8, (ftnlen)8);
/* SOURCE mkwspro.for:84 */
/*<       else >*/
    } else {
/* SOURCE mkwspro.for:85 */
/*<       write(stdout,55)format >*/
	feq_gen_io_d__19.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__19);
	do_fio(&feq_gen_c_d_1, format, (ftnlen)8);
	e_wsfe();
/* SOURCE mkwspro.for:86 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE mkwspro.for:87 */
/*<       endif >*/
    }
/*     The FEQXEXT option for varying Manning's n and for using */
/*     a weighted Manning's n within a subsection are not yet */
/*     supported. */
/* SOURCE mkwspro.for:93 */
/*<       write(stdout,57) >*/
    feq_gen_io_d__20.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__20);
    e_wsfe();
/*     Output the name and the station of the cross section. */
/* SOURCE mkwspro.for:95 */
/*<       write(stdout,56)name,statu >*/
    feq_gen_io_d__21.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__21);
    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)7);
    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.statu, (ftnlen)sizeof(real));
    e_wsfe();
/*     Output the GR cards  with three points per card. */
/* SOURCE mkwspro.for:98 */
/*<       m3=npntu/3 >*/
    m3 = xscomu_1.npntu / 3;
/*     Get the even multiple of 3 that is less or equal to NPNTU, the number */
/*     of points on the boundary of the cross section. */
/* SOURCE mkwspro.for:101 */
/*<       m3=3*m3 >*/
    m3 *= 3;
/*     Get the remainder. May be 0, 1, or 2 */
/* SOURCE mkwspro.for:104 */
/*<       r=npntu-m3 >*/
    feq_gen_r_d_ = xscomu_1.npntu - m3;
/* SOURCE mkwspro.for:106 */
/*<       do100i=1,m3,3 >*/
    feq_gen_i_d_1 = m3;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 3) {
/* SOURCE mkwspro.for:107 */
/*<       write(stdout,58)(xu(i+j),zu(i+j),j=0,2) >*/
	feq_gen_io_d__25.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__25);
	for (j = 0; j <= 2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[feq_gen_i_d_ + j - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[feq_gen_i_d_ + j - 1], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
/* SOURCE mkwspro.for:108 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE mkwspro.for:109 */
/*<       if(r.gt.0)then >*/
    if (feq_gen_r_d_ > 0) {
/* SOURCE mkwspro.for:110 */
/*<       write(stdout,58)(xu(m3+j),zu(m3+j),j=1,r) >*/
	feq_gen_io_d__27.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__27);
	feq_gen_i_d_1 = feq_gen_r_d_;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[m3 + j - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[m3 + j - 1], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
/* SOURCE mkwspro.for:111 */
/*<       endif >*/
    }
/*     Output the values of Manning's n for the subsections.  Find the */
/*     change in subsection to get the value of n and of the offset at */
/*     the boundary between adjacent subsections.   The final value of */
/*     SA will be the final point on the cross section.  This last */
/*     point of SA will not be output. */
/* SOURCE mkwspro.for:118 */
/*<       oldsub=sbu(1) >*/
    oldsub = xscomu_1.sbu[0];
/* SOURCE mkwspro.for:119 */
/*<       m=0 >*/
    m = 0;
/* SOURCE mkwspro.for:120 */
/*<       do200i=2,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE mkwspro.for:121 */
/*<       if(sbu(i).ne.oldsub)then >*/
	if (xscomu_1.sbu[feq_gen_i_d_ - 1] != oldsub) {
/*         Save the old value because it applies to the previous */
/*         subsection. */
/* SOURCE mkwspro.for:124 */
/*<       m=m+1 >*/
	    ++m;
/* SOURCE mkwspro.for:125 */
/*<       nwspro(m)=nu(oldsub) >*/
	    nwspro[m - 1] = xscomu_1.nu[oldsub - 1];
/* SOURCE mkwspro.for:126 */
/*<       sa(m)=xu(i) >*/
	    sa[m - 1] = xscomu_1.xu[feq_gen_i_d_ - 1];
/* SOURCE mkwspro.for:127 */
/*<       oldsub=sbu(i) >*/
	    oldsub = xscomu_1.sbu[feq_gen_i_d_ - 1];
/* SOURCE mkwspro.for:128 */
/*<       endif >*/
	}
/* SOURCE mkwspro.for:129 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE mkwspro.for:131 */
/*<       m7=m/7 >*/
    m7 = m / 7;
/* SOURCE mkwspro.for:132 */
/*<       m7=7*m7 >*/
    m7 *= 7;
/* SOURCE mkwspro.for:133 */
/*<       r=m-m7 >*/
    feq_gen_r_d_ = m - m7;
/* SOURCE mkwspro.for:134 */
/*<       do300i=1,m7,7 >*/
    feq_gen_i_d_1 = m7;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 7) {
/* SOURCE mkwspro.for:135 */
/*<       write(stdout,60)(nwspro(i+j),j=0,6) >*/
	feq_gen_io_d__33.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__33);
	for (j = 0; j <= 6; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&nwspro[feq_gen_i_d_ + j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE mkwspro.for:136 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE mkwspro.for:137 */
/*<       if(r.gt.0)then >*/
    if (feq_gen_r_d_ > 0) {
/* SOURCE mkwspro.for:138 */
/*<       write(stdout,60)(nwspro(m7+j),j=1,r) >*/
	feq_gen_io_d__34.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__34);
	feq_gen_i_d_1 = feq_gen_r_d_;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&nwspro[m7 + j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE mkwspro.for:139 */
/*<       endif >*/
    }
/*     Reduce the count by 1 to clip the last value. */
/* SOURCE mkwspro.for:142 */
/*<       m=m-1 >*/
    --m;
/* SOURCE mkwspro.for:143 */
/*<       m7=m/7 >*/
    m7 = m / 7;
/* SOURCE mkwspro.for:144 */
/*<       m7=7*m7 >*/
    m7 *= 7;
/* SOURCE mkwspro.for:145 */
/*<       r=m-m7 >*/
    feq_gen_r_d_ = m - m7;
/* SOURCE mkwspro.for:146 */
/*<       do400i=1,m7,7 >*/
    feq_gen_i_d_1 = m7;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 7) {
/* SOURCE mkwspro.for:147 */
/*<       write(stdout,62)(sa(i+j),j=0,6) >*/
	feq_gen_io_d__35.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__35);
	for (j = 0; j <= 6; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&sa[feq_gen_i_d_ + j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE mkwspro.for:148 */
/*<   400 continue >*/
/* L400: */
    }
/* SOURCE mkwspro.for:149 */
/*<       if(r.gt.0)then >*/
    if (feq_gen_r_d_ > 0) {
/* SOURCE mkwspro.for:150 */
/*<       write(stdout,62)(sa(m7+j),j=1,r) >*/
	feq_gen_io_d__36.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__36);
	feq_gen_i_d_1 = feq_gen_r_d_;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&sa[m7 + j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE mkwspro.for:151 */
/*<       endif >*/
    }
/* SOURCE mkwspro.for:156 */
/*<       return >*/
    return 0;
/* SOURCE mkwspro.for:157 */
/*<       end >*/
} /* mkwspro_ */

#ifdef __cplusplus
	}
#endif
