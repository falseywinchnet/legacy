/* doeqz.f -- translated by f2c (version 20240504).
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

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;




/* SOURCE doeqz.for:4 */
/*<       subroutinedoeqz(stdout,nbra,nbn,nex,exnodt,emc,ept,ye1known,eflag) >*/
/* Subroutine */ int doeqz_(integer *stdout, integer *nbra, integer *nbn, 
	integer *nex, integer *feq_storage_exnodt, integer *feq_storage_emc, integer *ept, integer *
	feq_storage_ye1known, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*BUG:XXX* Branch node:\002,a5,\002 has un\
known elev. in DOEQZ.\002)";
    static char fmt_52[] = "(/,\002*BUG*  Too many passes in DOEQZ. Runaway \
loop.\002)";
    static char fmt_60[] = "(\002 Both unknown: \002,a5,\002 \002,a5,\002  K\
NT=\002,i5)";
    static char fmt_62[] = "(\002 \002,a5,\002 known. \002,a5,\002 unknow\
n\002)";
    static char fmt_64[] = "(\002 Other end=\002,a5)";
    static char fmt_65[] = "(//,\002 Initializing EqZ connections to free no\
des on dummy branches\002)";
    static char fmt_66[] = "(/,\002 PASS=\002,i5)";
    static char fmt_68[] = "(\002 Source nodes for Code 12 unknown:\002,a5\
,\002 \002,a5,\002 \002,a5)";
    static char fmt_70[] = "(\002 \002,a5,\002 Unknown in code 12\002)";
    static char fmt_72[] = "(/,\002 EqZ connections to free nodes on dummy b\
ranches completed\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5], feq_gen_ch_d_5[5], feq_gen_ch_d_6[5];
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    integer feq_gen_other_end_d_, mid, dnn, knt, upn, code;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    real zmid;
    integer pass;
#define rdum (equiv_0)
    integer ipnt, ientry, oldknt;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer maxpass;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__21 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__24 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_72, 0 };


/*     + + + PURPOSE + + + */
/*     Make assignment of EqZ instructions if one of the pair of nodes */
/*     has an unknown value. */
/* SOURCE doeqz.for:12 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE doeqz.for:14 */
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
/* SOURCE doeqz.for:17 */
/*<       integereflag,ept,nbn,nbra,nex,stdout >*/
/* SOURCE doeqz.for:18 */
/*<       integerye1known(nex) >*/
/* SOURCE doeqz.for:19 */
/*<       integeremc(ept),exnodt(9,nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NEX    - number of exterior nodes in the model */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
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
/* INCLUDE doeqz.for:42 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE doeqz.for:43 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE doeqz.for:44 */
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
/* INCLUDE doeqz.for:45 */
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
/* SOURCE doeqz.for:48 */
/*<        >*/
/* SOURCE doeqz.for:51 */
/*<       realrdum,zmid >*/
/* SOURCE doeqz.for:53 */
/*<       equivalence(idum,rdum) >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE doeqz.for:56 */
/*<       character*5getusn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE doeqz.for:59 */
/*<       externalgetusn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE doeqz.for:61 */
/*<    50  >*/
/* SOURCE doeqz.for:63 */
/*<    52 format(/,'*BUG*  Too many passes in DOEQZ. Runaway loop.') >*/
/* SOURCE doeqz.for:64 */
/*<    60 format(' Both unknown: ',a5,' ',a5,'  KNT=',i5) >*/
/* SOURCE doeqz.for:65 */
/*<    62 format(' ',a5,' known. ',a5,' unknown') >*/
/* SOURCE doeqz.for:66 */
/*<    64 format(' Other end=',a5) >*/
/* SOURCE doeqz.for:67 */
/*<    65  >*/
/* SOURCE doeqz.for:69 */
/*<    66 format(/,' PASS=',i5) >*/
/* SOURCE doeqz.for:70 */
/*<    68 format(' Source nodes for Code 12 unknown:',a5,' ',a5,' ',a5) >*/
/* SOURCE doeqz.for:71 */
/*<    70 format(' ',a5,' Unknown in code 12') >*/
/* SOURCE doeqz.for:72 */
/*<    72  >*/
/* *********************************************************************** */
/*     The only unknown exterior nodes here should be free nodes.  All */
/*     nodes on a branch should be known here--if not, we have a bug. */
/*     Approach:  1. Set KNT to zero and then scan for EqZ instructions. */
/*      2.For each one found check for an unknown values of elevation/depth. */
/*      3. If only one value is unknown, then assign the known value to */
/*         it if the unknown value is at a free node.  If it is a */
/*         branch node, then write bug message and stop. */
/*      4. If the unknown value being assigned is on a dummy branch or */
/*         on a LPR, */
/*         then assign the same value to the other node. */
/*      5. If two values are unknown, then increment KNT. */
/*     We need to have an old value of KNT because there may be some values */
/*     that do not get assigned.  Output a warning message for each exterior */
/*     node with an unknown value. */
/* SOURCE doeqz.for:93 */
/*<       knt=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ye1known(feq_storage_ye1known, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L60: */
/* L62: */
/* L64: */
/* L65: */
/* L66: */
/* L68: */
/* L70: */
/* L72: */
    knt = 0;
/* SOURCE doeqz.for:94 */
/*<       oldknt=0 >*/
    oldknt = 0;
/* SOURCE doeqz.for:95 */
/*<       maxpass=nex >*/
    maxpass = *nex;
/* SOURCE doeqz.for:96 */
/*<       pass=0 >*/
    pass = 0;
/* SOURCE doeqz.for:97 */
/*<       write(stdout,65) >*/
    feq_gen_io_d__7.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__7);
    e_wsfe();
/* SOURCE doeqz.for:98 */
/*<   100 continue >*/
L100:
/* SOURCE doeqz.for:99 */
/*<       pass=pass+1 >*/
    ++pass;
/* SOURCE doeqz.for:100 */
/*<       write(stdout,66)pass >*/
    feq_gen_io_d__8.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__8);
    do_fio(&feq_gen_c_d_1, (char *)&pass, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE doeqz.for:101 */
/*<       if(pass.gt.maxpass)then >*/
    if (pass > maxpass) {
/* SOURCE doeqz.for:102 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__9.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__9);
	e_wsfe();
/* SOURCE doeqz.for:103 */
/*<       stop'Abnormal stop.  Bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE doeqz.for:104 */
/*<       endif >*/
    }
/*       Start loop seaching for EqZ:  CODE=3 */
/* SOURCE doeqz.for:106 */
/*<       ientry=0 >*/
    ientry = 0;
/* SOURCE doeqz.for:108 */
/*<   200 continue >*/
L200:
/* SOURCE doeqz.for:109 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE doeqz.for:110 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE doeqz.for:111 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE doeqz.for:112 */
/*<       if(code.eq.3)then >*/
    if (code == 3) {
/*           Get the node numbers */
/* SOURCE doeqz.for:114 */
/*<       upn=emc(ipnt+1) >*/
	upn = emc[ipnt + 1];
/* SOURCE doeqz.for:115 */
/*<       dnn=emc(ipnt+2) >*/
	dnn = emc[ipnt + 2];
/* SOURCE doeqz.for:116 */
/*<       if(ye1known(upn).eq.0)then >*/
	if (ye1known[upn] == 0) {
/*             The upstream node is unknown.  Is it on a branch? */
/* SOURCE doeqz.for:118 */
/*<       if(exnodt(3,upn).gt.0)then >*/
	    if (exnodt[upn * 9 + 3] > 0) {
/* SOURCE doeqz.for:119 */
/*<       write(stdout,50)getusn(upn) >*/
		feq_gen_io_d__15.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__15);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &upn);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		e_wsfe();
/* SOURCE doeqz.for:120 */
/*<       stop'Abnormal stop.  Bug found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE doeqz.for:121 */
/*<       endif >*/
	    }
/* SOURCE doeqz.for:122 */
/*<       if(ye1known(dnn).eq.0)then >*/
	    if (ye1known[dnn] == 0) {
/*               Both nodes are unknown.  Count the occurrence. */
/* SOURCE doeqz.for:124 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE doeqz.for:125 */
/*<       write(stdout,60)getusn(upn),getusn(dnn),knt >*/
		feq_gen_io_d__16.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__16);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &upn);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		getusn_(feq_gen_ch_d_4, (ftnlen)5, &dnn);
		s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE doeqz.for:126 */
/*<       else >*/
	    } else {
/*               DNN node has known elevation.  Assign its value */
/*               to UPN node and update the known flag. */
/* SOURCE doeqz.for:129 */
/*<       write(stdout,62)getusn(dnn),getusn(upn) >*/
		feq_gen_io_d__17.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__17);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &dnn);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		getusn_(feq_gen_ch_d_4, (ftnlen)5, &upn);
		s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
		e_wsfe();
/* SOURCE doeqz.for:130 */
/*<       ye1(upn)=ye1(dnn)+ze(dnn)-ze(upn) >*/
		enelem_1.ye1[upn - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[dnn - 1]) + enelem_1.ze[
			dnn - 1]) - enelem_1.ze[upn - 1];
/* SOURCE doeqz.for:131 */
/*<       ye1known(upn)=1 >*/
		ye1known[upn] = 1;
/*               Now propagate the value to the other end of the */
/*               dummy branch. */
/* SOURCE doeqz.for:134 */
/*<       if(exnodt(3,upn).eq.0)then >*/
		if (exnodt[upn * 9 + 3] == 0) {
/*                 Node on dummy branch or inflow node to LPR */
/* SOURCE doeqz.for:136 */
/*<       if(exnodt(4,upn).gt.0)then >*/
		    if (exnodt[upn * 9 + 4] > 0) {
/*                   Node on a dummy branch */
/* SOURCE doeqz.for:138 */
/*<       other_end=exnodt(4,upn) >*/
			feq_gen_other_end_d_ = exnodt[upn * 9 + 4];
/* SOURCE doeqz.for:139 */
/*<       write(stdout,64)getusn(other_end) >*/
			feq_gen_io_d__19.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__19);
			getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_other_end_d_);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			e_wsfe();
/* SOURCE doeqz.for:140 */
/*<       ye1(other_end)=ye1(dnn)+ze(dnn)-ze(other_end) >*/
			enelem_1.ye1[feq_gen_other_end_d_ - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[dnn - 1]) 
				+ enelem_1.ze[dnn - 1]) - enelem_1.ze[
				feq_gen_other_end_d_ - 1];
/* SOURCE doeqz.for:141 */
/*<       ye1known(other_end)=1 >*/
			ye1known[feq_gen_other_end_d_] = 1;
/* SOURCE doeqz.for:142 */
/*<       endif >*/
		    }
/* SOURCE doeqz.for:143 */
/*<       endif >*/
		}
/* SOURCE doeqz.for:144 */
/*<       endif >*/
	    }
/* SOURCE doeqz.for:145 */
/*<       else >*/
	} else {
/*             UPN node is known */
/* SOURCE doeqz.for:147 */
/*<       if(ye1known(dnn).eq.0)then >*/
	    if (ye1known[dnn] == 0) {
/* SOURCE doeqz.for:148 */
/*<       write(stdout,62)getusn(upn),getusn(dnn) >*/
		feq_gen_io_d__20.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__20);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &upn);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		getusn_(feq_gen_ch_d_4, (ftnlen)5, &dnn);
		s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
		e_wsfe();
/*               DNN node is unknown.  Is it on a branch? */
/* SOURCE doeqz.for:151 */
/*<       if(exnodt(3,dnn).gt.0)then >*/
		if (exnodt[dnn * 9 + 3] > 0) {
/* SOURCE doeqz.for:152 */
/*<       write(stdout,50)getusn(dnn) >*/
		    feq_gen_io_d__21.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__21);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &dnn);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    e_wsfe();
/* SOURCE doeqz.for:153 */
/*<       stop'Abnormal stop.  Bug found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE doeqz.for:154 */
/*<       endif >*/
		}
/*               Assign the value to the unknown node. */
/* SOURCE doeqz.for:156 */
/*<       ye1(dnn)=ye1(upn)+ze(upn)-ze(dnn) >*/
		enelem_1.ye1[dnn - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[upn - 1]) + enelem_1.ze[
			upn - 1]) - enelem_1.ze[dnn - 1];
/* SOURCE doeqz.for:157 */
/*<       ye1known(dnn)=1 >*/
		ye1known[dnn] = 1;
/*               Now propagate the value to the other end of the */
/*               dummy branch. */
/* SOURCE doeqz.for:160 */
/*<       if(exnodt(3,dnn).eq.0)then >*/
		if (exnodt[dnn * 9 + 3] == 0) {
/*                 Node on dummy branch or inflow node to LPR */
/* SOURCE doeqz.for:162 */
/*<       if(exnodt(4,dnn).gt.0)then >*/
		    if (exnodt[dnn * 9 + 4] > 0) {
/*                   Node on a dummy branch */
/* SOURCE doeqz.for:164 */
/*<       other_end=exnodt(4,dnn) >*/
			feq_gen_other_end_d_ = exnodt[dnn * 9 + 4];
/* SOURCE doeqz.for:165 */
/*<       write(stdout,64)getusn(other_end) >*/
			feq_gen_io_d__22.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__22);
			getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_other_end_d_);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			e_wsfe();
/* SOURCE doeqz.for:166 */
/*<       ye1(other_end)=ye1(upn)+ze(upn)-ze(other_end) >*/
			enelem_1.ye1[feq_gen_other_end_d_ - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[upn - 1]) 
				+ enelem_1.ze[upn - 1]) - enelem_1.ze[
				feq_gen_other_end_d_ - 1];
/* SOURCE doeqz.for:167 */
/*<       ye1known(other_end)=1 >*/
			ye1known[feq_gen_other_end_d_] = 1;
/* SOURCE doeqz.for:168 */
/*<       endif >*/
		    }
/* SOURCE doeqz.for:169 */
/*<       endif >*/
		}
/* SOURCE doeqz.for:170 */
/*<       endif >*/
	    }
/* SOURCE doeqz.for:171 */
/*<       endif >*/
	}
/* SOURCE doeqz.for:172 */
/*<       elseif(code.eq.12)then >*/
    } else if (code == 12) {
/*           Get the node numbers */
/* SOURCE doeqz.for:174 */
/*<       upn=emc(ipnt+1) >*/
	upn = emc[ipnt + 1];
/* SOURCE doeqz.for:175 */
/*<       dnn=emc(ipnt+2) >*/
	dnn = emc[ipnt + 2];
/* SOURCE doeqz.for:176 */
/*<       mid=emc(ipnt+3) >*/
	mid = emc[ipnt + 3];
/* SOURCE doeqz.for:177 */
/*<       if(ye1known(mid).eq.0)then >*/
	if (ye1known[mid] == 0) {
/* SOURCE doeqz.for:178 */
/*<       write(stdout,70)getusn(mid) >*/
	    feq_gen_io_d__24.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__24);
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &mid);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    e_wsfe();
/* SOURCE doeqz.for:180 */
/*<       if(ye1known(upn).eq.0.or.ye1known(dnn).eq.0)then >*/
	    if (ye1known[upn] == 0 || ye1known[dnn] == 0) {
/*               Count as an unknown. */
/* SOURCE doeqz.for:182 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE doeqz.for:183 */
/*<       write(stdout,68)getusn(upn),getusn(dnn),getusn(mid) >*/
		feq_gen_io_d__25.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__25);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &upn);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		getusn_(feq_gen_ch_d_4, (ftnlen)5, &dnn);
		s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
		getusn_(feq_gen_ch_d_6, (ftnlen)5, &mid);
		s_copy(feq_gen_ch_d_5, feq_gen_ch_d_6, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_5, (ftnlen)5);
		e_wsfe();
/* SOURCE doeqz.for:184 */
/*<       else >*/
	    } else {
/*               Both source nodes are known.   Get the factor */
/* SOURCE doeqz.for:186 */
/*<       idum=emc(ipnt+4) >*/
		*idum = emc[ipnt + 4];
/* SOURCE doeqz.for:187 */
/*<       zmid=rdum*(ye1(upn)+ze(upn))+(1.-rdum)*(ye1(dnn)+ze(dnn)) >*/
		zmid = static_cast<double>(static_cast<double>(*rdum) * (static_cast<double>(enelem_1.ye1[upn - 1]) + enelem_1.ze[upn - 1])) 
			+ static_cast<double>((static_cast<double>((float)1.) - *rdum)) * (static_cast<double>(enelem_1.ye1[dnn - 1]) + 
			enelem_1.ze[dnn - 1]);
/* SOURCE doeqz.for:189 */
/*<       ye1(mid)=zmid-ze(mid) >*/
		enelem_1.ye1[mid - 1] = static_cast<double>(zmid) - enelem_1.ze[mid - 1];
/* SOURCE doeqz.for:190 */
/*<       ye1known(mid)=1 >*/
		ye1known[mid] = 1;
/*               Now set the other end. */
/* SOURCE doeqz.for:192 */
/*<       if(exnodt(3,mid).eq.0)then >*/
		if (exnodt[mid * 9 + 3] == 0) {
/*                 Node on dummy branch or inflow node to LPR */
/* SOURCE doeqz.for:194 */
/*<       if(exnodt(4,mid).gt.0)then >*/
		    if (exnodt[mid * 9 + 4] > 0) {
/*                   Node on dummy branch */
/* SOURCE doeqz.for:196 */
/*<       other_end=exnodt(4,mid) >*/
			feq_gen_other_end_d_ = exnodt[mid * 9 + 4];
/* SOURCE doeqz.for:197 */
/*<       write(stdout,64)getusn(other_end) >*/
			feq_gen_io_d__27.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__27);
			getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_other_end_d_);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			e_wsfe();
/* SOURCE doeqz.for:198 */
/*<       ye1(other_end)=zmid-ze(other_end) >*/
			enelem_1.ye1[feq_gen_other_end_d_ - 1] = static_cast<double>(zmid) - enelem_1.ze[
				feq_gen_other_end_d_ - 1];
/* SOURCE doeqz.for:199 */
/*<       ye1known(other_end)=1 >*/
			ye1known[feq_gen_other_end_d_] = 1;
/* SOURCE doeqz.for:200 */
/*<       endif >*/
		    }
/* SOURCE doeqz.for:201 */
/*<       endif >*/
		}
/* SOURCE doeqz.for:202 */
/*<       endif >*/
	    }
/* SOURCE doeqz.for:203 */
/*<       endif >*/
	}
/* SOURCE doeqz.for:204 */
/*<       endif >*/
    }
/* SOURCE doeqz.for:205 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*           Continue the search. */
/* SOURCE doeqz.for:207 */
/*<       goto200 >*/
	goto L200;
/* SOURCE doeqz.for:208 */
/*<       endif >*/
    }
/*       If KNT is zero at this point, then all unknown values */
/*       of depth/elevation have been assign and we are done. */
/*       If KNT is positive, then place its value in OLDKNT, */
/*       clear KNT, and go back for another pass.  If KNT is the */
/*       same as OLDKNT, then we are done but with some undefined */
/*       depths/elevations. */
/* SOURCE doeqz.for:217 */
/*<       if(knt.gt.0)then >*/
    if (knt > 0) {
/* SOURCE doeqz.for:218 */
/*<       if(knt.eq.oldknt)then >*/
	if (knt == oldknt) {
/*           We are done but there are still some undefined values. */
/*           Do a scan again but print all nodes with an undefined value. */
/* SOURCE doeqz.for:222 */
/*<       write(stdout,*)' In DOEQZ: KNT=',knt,' OLDKNT=',oldknt >*/
	    feq_gen_io_d__28.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__28);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" In DOEQZ: KNT="), (ftnlen)15);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" OLDKNT="), (ftnlen)8);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&oldknt, (ftnlen)sizeof(integer));
	    e_wsle();
/* SOURCE doeqz.for:224 */
/*<       else >*/
	} else {
/*           There has been a change in the count of cases where both */
/*           values are unknown.  Continue the scanning to possibly */
/*           spread the change to the next set of unknowns. */
/* SOURCE doeqz.for:228 */
/*<       oldknt=knt >*/
	    oldknt = knt;
/* SOURCE doeqz.for:229 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE doeqz.for:230 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE doeqz.for:231 */
/*<       endif >*/
	}
/* SOURCE doeqz.for:232 */
/*<       endif >*/
    }
/* SOURCE doeqz.for:234 */
/*<       write(stdout,72) >*/
    feq_gen_io_d__29.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__29);
    e_wsfe();
/* SOURCE doeqz.for:235 */
/*<       return >*/
    return 0;
/* SOURCE doeqz.for:236 */
/*<       end >*/
} /* doeqz_ */

#undef rdum
#undef idum





/* SOURCE doeqz.for:240 */
/*<       subroutinefind_code7(stdout,node,mr,emc,inode) >*/
/* Subroutine */ int feq_gen_find_code7_d_(integer *stdout, integer *node, integer *mr,
	 integer *feq_storage_emc, integer *inode)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*BUG* Exterior node=\002,a5,\002 expected\
 as a LPR\002,\002 node but code 7 with this node not found in EMC!\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer code, ipnt;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer ientry;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_50, 0 };


/*     Search EMC, the network-matrix control vector for a code 7 with */
/*     a reservoir node of NODE and return with the inflow node value, INODE. */
/* SOURCE doeqz.for:246 */
/*<       implicitnone >*/
/* SOURCE doeqz.for:247 */
/*<       integernode,mr,inode,stdout >*/
/* SOURCE doeqz.for:248 */
/*<       integeremc(mr) >*/
/*     Common blocks */
/* INCLUDE doeqz.for:251 */
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
/* INCLUDE doeqz.for:252 */
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
/*     External routines */
/* SOURCE doeqz.for:255 */
/*<       character*5getusn >*/
/* SOURCE doeqz.for:256 */
/*<       externalgetusn >*/
/*     Local variables */
/* SOURCE doeqz.for:258 */
/*<       integercode,ientry,ipnt >*/
/* *********************************************************************** */
/* SOURCE doeqz.for:261 */
/*<       ientry=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    ientry = 0;
/* SOURCE doeqz.for:263 */
/*<   200 continue >*/
L200:
/* SOURCE doeqz.for:264 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE doeqz.for:265 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE doeqz.for:266 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE doeqz.for:267 */
/*<       if(code.eq.7)then >*/
    if (code == 7) {
/* SOURCE doeqz.for:268 */
/*<       if(emc(ipnt+1).eq.node)then >*/
	if (emc[ipnt + 1] == *node) {
/*           We have a hit. */
/* SOURCE doeqz.for:270 */
/*<       inode=emc(ipnt+5) >*/
	    *inode = emc[ipnt + 5];
/* SOURCE doeqz.for:271 */
/*<       return >*/
	    return 0;
/* SOURCE doeqz.for:272 */
/*<       endif >*/
	}
/* SOURCE doeqz.for:273 */
/*<       endif >*/
    }
/* SOURCE doeqz.for:274 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE doeqz.for:276 */
/*<       goto200 >*/
	goto L200;
/* SOURCE doeqz.for:277 */
/*<       endif >*/
    }
/*     If we fall through, then we have a bug.  We were seeking a code */
/*     7 with NODE and it had better exist in EMC or there are major problems */
/*     afoot elsewhere. */
/* SOURCE doeqz.for:283 */
/*<       write(stdout,50)getusn(node) >*/
    feq_gen_io_d__33.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__33);
    getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
    e_wsfe();
/* SOURCE doeqz.for:284 */
/*<    50  >*/
/* SOURCE doeqz.for:287 */
/*<       stop'Abnormal stop.  Bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE doeqz.for:288 */
/*<       end >*/
    return 0;
} /* find_code7__ */

#ifdef __cplusplus
	}
#endif
