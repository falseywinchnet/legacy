/* fqshrtdl.f -- translated by f2c (version 20240504).
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

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_13 = 13;
static integer feq_gen_c_d_43 = 43;




/* SOURCE fqshrtdl.for:4 */
/*<       subroutinetdlk10(lout,ip,ptype,argr,argc,f,dfdr,dfdc) >*/
/* Subroutine */ int tdlk10_(integer *lout, integer *ip, integer *ptype, real 
	*argr, real *argc, real *f, real *dfdr, real *dfdc)
{
    /* Format strings */
    static char fmt_50[] = "(\002*ERR:690* ROW ARG.=\002,f10.2,\002 BELOW RA\
NGE IN TABID=\002,a)";
    static char fmt_51[] = "(\002*ERR:691* ROW ARG.=\002,f10.2,\002 ABOVE RA\
NGE IN TABID=\002,a)";
    static char fmt_52[] = "(\002*ERR:692* COLUMN ARG.=\002,f10.2,\002 BELOW\
 RANGE IN TABID=\002,a)";
    static char fmt_53[] = "(\002*ERR:693* COLUMN ARG.=\002,f10.2,\002 ABOVE\
 RANGE IN TABID=\002,a)";
    static char fmt_54[] = "(\002*ERR:73* UNEXPECTED TYPE IN TWO-D TABID=\
\002,a,\002 TYPE=\002,i5,\002 EXPECTED TYPE=\002,i5)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real dc, fa, fb, df, dr;
    integer tab, inc;
    real delc;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real dfdca, dfdcb;
    integer hargc, largc, nargc, pargc, hargr, largr, pargr;
    real colarg, rowarg;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_53, 0 };


/*     + + + PURPOSE + + + */
/*     Do 2-D lookup for function in rectangular grid table. */
/* SOURCE fqshrtdl.for:11 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrtdl.for:13 */
/*<       integerip,lout,ptype >*/
/* SOURCE fqshrtdl.for:14 */
/*<       realargc,argr,dfdc,dfdr,f >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     LOUT   - Fortran unit number for user output and messages */
/*     IP     - address of table */
/*     ARGR   - argument for rows in the table */
/*     ARGC   - argument for columns in the table */
/*     F      - function value */
/*     DFDR   - derivative of function wrt row argument */
/*     DFDC   - derivative of function wrt column argument */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrtdl.for:26 */
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
/* INCLUDE fqshrtdl.for:27 */
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
/* SOURCE fqshrtdl.for:30 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrtdl.for:31 */
/*<       externalget_tabid >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrtdl.for:34 */
/*<       integerhargc,hargr,inc,j,largc,largr,nargc,pargc,pargr,tab,type >*/
/* SOURCE fqshrtdl.for:36 */
/*<       realcolarg,dc,delc,df,dfdca,dfdcb,dr,fa,fb,rowarg >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrtdl.for:39 */
/*<    50 format('*ERR:690* ROW ARG.=',f10.2,' BELOW RANGE IN TABID=',a) >*/
/* SOURCE fqshrtdl.for:40 */
/*<    51 format('*ERR:691* ROW ARG.=',f10.2,' ABOVE RANGE IN TABID=',a) >*/
/* SOURCE fqshrtdl.for:41 */
/*<    52 format('*ERR:692* COLUMN ARG.=',f10.2,' BELOW RANGE IN TABID=',a) >*/
/* SOURCE fqshrtdl.for:43 */
/*<    53 format('*ERR:693* COLUMN ARG.=',f10.2,' ABOVE RANGE IN TABID=',a) >*/
/* SOURCE fqshrtdl.for:45 */
/*<    54  >*/
/* *********************************************************************** */
/*     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT */
/*     POINTERS ARE SET TO THE PROPER VALUES AT START */
/* SOURCE fqshrtdl.for:51 */
/*<       tab=itab(ip+1) >*/
/* L50: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
    tab = itab[*ip + 1];
/* SOURCE fqshrtdl.for:52 */
/*<       type=itab(ip+2) >*/
    feq_gen_type_d_ = itab[*ip + 2];
/* SOURCE fqshrtdl.for:53 */
/*<       pargr=itab(ip+3) >*/
    pargr = itab[*ip + 3];
/* SOURCE fqshrtdl.for:54 */
/*<       hargr=itab(ip+4) >*/
    hargr = itab[*ip + 4];
/* SOURCE fqshrtdl.for:55 */
/*<       largr=itab(ip+5) >*/
    largr = itab[*ip + 5];
/*      NARGR = FTAB(IP+6) */
/* SOURCE fqshrtdl.for:58 */
/*<       pargc=itab(ip+7) >*/
    pargc = itab[*ip + 7];
/* SOURCE fqshrtdl.for:59 */
/*<       hargc=itab(ip+8) >*/
    hargc = itab[*ip + 8];
/* SOURCE fqshrtdl.for:60 */
/*<       largc=itab(ip+9) >*/
    largc = itab[*ip + 9];
/* SOURCE fqshrtdl.for:61 */
/*<       nargc=itab(ip+10) >*/
    nargc = itab[*ip + 10];
/*      WRITE(LOUT,*) 'TDLK10 ON ENTRY: LARGR=',LARGR,' LARGC=',LARGC */
/* SOURCE fqshrtdl.for:65 */
/*<       rowarg=argr >*/
    rowarg = *argr;
/* SOURCE fqshrtdl.for:66 */
/*<       colarg=argc >*/
    colarg = *argc;
/*      WRITE(LOUT,*) 'TDLK10: ROWARG=',ROWARG,' COLARG=',COLARG */
/* SOURCE fqshrtdl.for:70 */
/*<       if(type.ne.ptype)then >*/
    if (feq_gen_type_d_ != *ptype) {
/* SOURCE fqshrtdl.for:71 */
/*<       write(lout,54)get_tabid(tab),type,ptype >*/
	feq_gen_io_d__15.ciunit = *lout;
	s_wsfe(&feq_gen_io_d__15);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*ptype), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrtdl.for:72 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrtdl.for:73 */
/*<       endif >*/
    }
/*     FIND THE INTERVAL IN THE ROW ARGUMENT LIST CONTAINING THE */
/*     CURRENT ROW ARGUMENT. */
/*     MAKE SURE THE ARGUMENT IS IN THE RANGE OF THE TABLE */
/* SOURCE fqshrtdl.for:79 */
/*<       if(rowarg.lt.ftab(pargr))then >*/
    if (rowarg < ftab[pargr]) {
/* SOURCE fqshrtdl.for:80 */
/*<       write(lout,50)rowarg,get_tabid(tab) >*/
	feq_gen_io_d__16.ciunit = *lout;
	s_wsfe(&feq_gen_io_d__16);
	do_fio(&feq_gen_c_d_1, (char *)&rowarg, (ftnlen)sizeof(real));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrtdl.for:81 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrtdl.for:82 */
/*<       elseif(rowarg.gt.ftab(hargr))then >*/
    } else if (rowarg > ftab[hargr]) {
/* SOURCE fqshrtdl.for:83 */
/*<       write(lout,51)rowarg,get_tabid(tab) >*/
	feq_gen_io_d__17.ciunit = *lout;
	s_wsfe(&feq_gen_io_d__17);
	do_fio(&feq_gen_c_d_1, (char *)&rowarg, (ftnlen)sizeof(real));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrtdl.for:84 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrtdl.for:85 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:87 */
/*<       inc=nargc+1 >*/
    inc = nargc + 1;
/* SOURCE fqshrtdl.for:89 */
/*<       if(rowarg.ge.ftab(largr))then >*/
    if (rowarg >= ftab[largr]) {
/* SOURCE fqshrtdl.for:90 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrtdl.for:91 */
/*<       if(rowarg.le.ftab(largr+inc))goto120 >*/
	if (rowarg <= ftab[largr + inc]) {
	    goto L120;
	}
/* SOURCE fqshrtdl.for:92 */
/*<       largr=largr+inc >*/
	largr += inc;
/* SOURCE fqshrtdl.for:93 */
/*<       goto100 >*/
	goto L100;
/* SOURCE fqshrtdl.for:94 */
/*<       else >*/
    } else {
/* SOURCE fqshrtdl.for:95 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrtdl.for:96 */
/*<       largr=largr-inc >*/
	largr -= inc;
/* SOURCE fqshrtdl.for:97 */
/*<       if(rowarg.ge.ftab(largr))goto120 >*/
	if (rowarg >= ftab[largr]) {
	    goto L120;
	}
/* SOURCE fqshrtdl.for:98 */
/*<       goto110 >*/
	goto L110;
/* SOURCE fqshrtdl.for:99 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:100 */
/*<   120 continue >*/
L120:
/* SOURCE fqshrtdl.for:101 */
/*<       itab(ip+5)=largr >*/
    itab[*ip + 5] = largr;
/*     FIND INTERVAL IN THE COLUMN ARGUMENT LIST CONTAINING THE CURRENT */
/*     COLUMN ARGUMENT. */
/*     MAKE SURE THE ARGUMENT IS IN THE RANGE OF THE TABLE */
/* SOURCE fqshrtdl.for:107 */
/*<       if(colarg.lt.ftab(pargc))then >*/
    if (colarg < ftab[pargc]) {
/* SOURCE fqshrtdl.for:108 */
/*<       write(lout,52)colarg,get_tabid(tab) >*/
	feq_gen_io_d__19.ciunit = *lout;
	s_wsfe(&feq_gen_io_d__19);
	do_fio(&feq_gen_c_d_1, (char *)&colarg, (ftnlen)sizeof(real));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrtdl.for:109 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrtdl.for:110 */
/*<       elseif(colarg.gt.ftab(hargc))then >*/
    } else if (colarg > ftab[hargc]) {
/* SOURCE fqshrtdl.for:111 */
/*<       write(lout,53)colarg,get_tabid(tab) >*/
	feq_gen_io_d__20.ciunit = *lout;
	s_wsfe(&feq_gen_io_d__20);
	do_fio(&feq_gen_c_d_1, (char *)&colarg, (ftnlen)sizeof(real));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrtdl.for:112 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrtdl.for:113 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:115 */
/*<       if(colarg.ge.ftab(largc))then >*/
    if (colarg >= ftab[largc]) {
/* SOURCE fqshrtdl.for:116 */
/*<   200 continue >*/
L200:
/* SOURCE fqshrtdl.for:117 */
/*<       if(colarg.le.ftab(largc+1))goto220 >*/
	if (colarg <= ftab[largc + 1]) {
	    goto L220;
	}
/* SOURCE fqshrtdl.for:118 */
/*<       largc=largc+1 >*/
	++largc;
/* SOURCE fqshrtdl.for:119 */
/*<       goto200 >*/
	goto L200;
/* SOURCE fqshrtdl.for:120 */
/*<       else >*/
    } else {
/* SOURCE fqshrtdl.for:121 */
/*<   210 continue >*/
L210:
/* SOURCE fqshrtdl.for:122 */
/*<       largc=largc-1 >*/
	--largc;
/* SOURCE fqshrtdl.for:123 */
/*<       if(colarg.ge.ftab(largc))goto220 >*/
	if (colarg >= ftab[largc]) {
	    goto L220;
	}
/* SOURCE fqshrtdl.for:124 */
/*<       goto210 >*/
	goto L210;
/* SOURCE fqshrtdl.for:125 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:126 */
/*<   220 continue >*/
L220:
/* SOURCE fqshrtdl.for:127 */
/*<       itab(ip+9)=largc >*/
    itab[*ip + 9] = largc;
/*      WRITE(LOUT,*) 'TDLK10 AFTER LOOKUP: LARGR=',LARGR,' LARGC=',LARGC */
/* SOURCE fqshrtdl.for:131 */
/*<       j=largc-pargc+1 >*/
    j = largc - pargc + 1;
/*     INTERPOLATE ALONG EACH ROW FIRST. DC-difference between */
/*     the tabulated column arguments; DR-difference between tabulated */
/*     row arguments;  DELC- offset with the column argument interval; */

/* SOURCE fqshrtdl.for:138 */
/*<       dc=ftab(largc+1)-ftab(largc) >*/
    dc = static_cast<double>(ftab[largc + 1]) - ftab[largc];
/* SOURCE fqshrtdl.for:139 */
/*<       delc=colarg-ftab(largc) >*/
    delc = static_cast<double>(colarg) - ftab[largc];
/* SOURCE fqshrtdl.for:141 */
/*<       dr=ftab(largr+inc)-ftab(largr) >*/
    dr = static_cast<double>(ftab[largr + inc]) - ftab[largr];
/* SOURCE fqshrtdl.for:142 */
/*<       df=ftab(largr+j+1)-ftab(largr+j) >*/
    df = static_cast<double>(ftab[largr + j + 1]) - ftab[largr + j];
/* SOURCE fqshrtdl.for:143 */
/*<       dfdca=df/dc >*/
    dfdca = static_cast<double>(df) / dc;
/* SOURCE fqshrtdl.for:145 */
/*<       df=ftab(largr+inc+j+1)-ftab(largr+inc+j) >*/
    df = static_cast<double>(ftab[largr + inc + j + 1]) - ftab[largr + inc + j];
/* SOURCE fqshrtdl.for:146 */
/*<       dfdcb=df/dc >*/
    dfdcb = static_cast<double>(df) / dc;
/* SOURCE fqshrtdl.for:148 */
/*<       fa=ftab(largr+j)+dfdca*delc >*/
    fa = static_cast<double>(ftab[largr + j]) + static_cast<double>(dfdca) * delc;
/* SOURCE fqshrtdl.for:149 */
/*<       fb=ftab(largr+inc+j)+dfdcb*delc >*/
    fb = static_cast<double>(ftab[largr + inc + j]) + static_cast<double>(dfdcb) * delc;
/*     NOW INTERPOLATE BETWEEN ROWS FOR FUNCTION AND DERIVATIVE */
/* SOURCE fqshrtdl.for:153 */
/*<       dfdr=(dfdcb-dfdca)/dr >*/
    *dfdr = static_cast<double>((static_cast<double>(dfdcb) - dfdca)) / dr;
/* SOURCE fqshrtdl.for:154 */
/*<       dfdc=dfdca+dfdr*(rowarg-ftab(largr)) >*/
    *dfdc = static_cast<double>(dfdca) + static_cast<double>(*dfdr) * (static_cast<double>(rowarg) - ftab[largr]);
/* SOURCE fqshrtdl.for:155 */
/*<       dfdr=(fb-fa)/dr >*/
    *dfdr = static_cast<double>((static_cast<double>(fb) - fa)) / dr;
/* SOURCE fqshrtdl.for:156 */
/*<       f=fa+dfdr*(rowarg-ftab(largr)) >*/
    *f = static_cast<double>(fa) + static_cast<double>(*dfdr) * (static_cast<double>(rowarg) - ftab[largr]);
/*      WRITE(LOUT,*) 'TDLK10 ON RETURN:F=',F,' DFDR=',DFDR,' DFDC=',DFDC */
/* SOURCE fqshrtdl.for:159 */
/*<       return >*/
    return 0;
/* SOURCE fqshrtdl.for:160 */
/*<       end >*/
} /* tdlk10_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrtdl.for:164 */
/*<        >*/
/* Subroutine */ int tdlk13_(integer *stdout, integer *ip, integer *ptype, 
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
    real ed, dp, dq, eu;
    integer lp;
    real hu, ql, qr, fac;
    integer tab;
    real pld, qld, prd, qrd;
    integer lhu;
    real hul, hur, plu, qlu, pru, qru;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer lpfd, offl, offr;
    real dpeu, hmax, dqlp, dqhu, drop, dqrp;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real dqled, dqred, dqleu, dqreu, hdrop, hdropl, ddropu, hdropr, thdrop;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Do 2-d lookup for flow for tables of type 13. */
/* SOURCE fqshrtdl.for:171 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrtdl.for:173 */
/*<       integerfree,ip,stdout,mftab,ptype >*/
/* SOURCE fqshrtdl.for:174 */
/*<       realdqed,dqeu,eda,eua,hbase,q >*/
/* SOURCE fqshrtdl.for:175 */
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
/* INCLUDE fqshrtdl.for:193 */
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
/* INCLUDE fqshrtdl.for:194 */
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
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE fqshrtdl.for:197 */
/*<       integerinc >*/
/* SOURCE fqshrtdl.for:198 */
/*<       parameter(inc=4) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fqshrtdl.for:201 */
/*<       integerlhu,lp,lpfd,ntab,offl,offr,tab,type >*/
/* SOURCE fqshrtdl.for:202 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrtdl.for:208 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrtdl.for:209 */
/*<       externalget_tabid,lktstab >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrtdl.for:212 */
/*<    50  >*/
/* SOURCE fqshrtdl.for:214 */
/*<    52  >*/
/* SOURCE fqshrtdl.for:216 */
/*<    54  >*/
/* *********************************************************************** */
/*     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT */
/*     POINTERS ARE SET TO THE PROPER VALUES AT START */
/* SOURCE fqshrtdl.for:222 */
/*<       tab=itab(ip+1) >*/
/* L50: */
/* L52: */
/* L54: */
    tab = itab[*ip + 1];
/* SOURCE fqshrtdl.for:223 */
/*<       type=itab(ip+2) >*/
    feq_gen_type_d_ = itab[*ip + 2];
/* SOURCE fqshrtdl.for:224 */
/*<       lhu=itab(ip+4) >*/
    lhu = itab[*ip + 4];
/* SOURCE fqshrtdl.for:225 */
/*<       hmax=ftab(ip+9) >*/
    hmax = ftab[*ip + 9];
/*      WRITE(STDOUT,*) ' TDLK13: TAB=',TAB,' TYPE=',TYPE,' LHU=',LHU */
/*     IMPORTANT: THE DESIGNATIONS UPSTREAM AND DOWNSTREAM REFER TO */
/*     THE TRUE RELATIONSHIP.  THUS EU >= ED ALWAYS. */
/* SOURCE fqshrtdl.for:232 */
/*<       eu=eua >*/
    eu = *eua;
/* SOURCE fqshrtdl.for:233 */
/*<       ed=eda >*/
    ed = *eda;
/* SOURCE fqshrtdl.for:235 */
/*<       if(type.ne.ptype)then >*/
    if (feq_gen_type_d_ != *ptype) {
/* SOURCE fqshrtdl.for:236 */
/*<       write(stdout,54)get_tabid(tab),type,ptype >*/
	feq_gen_io_d__39.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__39);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*ptype), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fqshrtdl.for:237 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrtdl.for:238 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:240 */
/*<       if(eu.lt.ed)then >*/
    if (eu < ed) {
/* SOURCE fqshrtdl.for:241 */
/*<       write(stdout,50)get_tabid(tab),eu,ed >*/
	feq_gen_io_d__40.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__40);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&eu, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ed, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE fqshrtdl.for:242 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrtdl.for:243 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:246 */
/*<       hu=eu-hbase >*/
    hu = static_cast<double>(eu) - *hbase;
/* SOURCE fqshrtdl.for:248 */
/*<       if(hu.gt.hmax)then >*/
    if (hu > hmax) {
/* SOURCE fqshrtdl.for:249 */
/*<       write(stdout,52)get_tabid(tab),hu,hmax >*/
	feq_gen_io_d__42.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__42);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&hu, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE fqshrtdl.for:250 */
/*<       drop=eu-ed >*/
	drop = static_cast<double>(eu) - ed;
/* SOURCE fqshrtdl.for:251 */
/*<       hu=hmax >*/
	hu = hmax;
/* SOURCE fqshrtdl.for:252 */
/*<       eu=hbase+hmax >*/
	eu = static_cast<double>(*hbase) + hmax;
/* SOURCE fqshrtdl.for:253 */
/*<       ed=eu-drop >*/
	ed = static_cast<double>(eu) - drop;
/* SOURCE fqshrtdl.for:254 */
/*<       endif >*/
    }
/*     DETERMINE IF THERE IS FLOW AND IF IT IS KNOWN TO BE FREE */
/* SOURCE fqshrtdl.for:258 */
/*<       if(eu.le.hbase)then >*/
    if (eu <= *hbase) {
/*       FLOW IS ZERO AND SO ARE DERIVATIVES */
/* SOURCE fqshrtdl.for:260 */
/*<       q=0.0 >*/
	*q = (float)0.;
/* SOURCE fqshrtdl.for:261 */
/*<       dqed=0.0 >*/
	*dqed = (float)0.;
/* SOURCE fqshrtdl.for:262 */
/*<       dqeu=0.0 >*/
	*dqeu = (float)0.;
/* SOURCE fqshrtdl.for:263 */
/*<       free=0 >*/
	*free = 0;
/* SOURCE fqshrtdl.for:264 */
/*<       return >*/
	return 0;
/* SOURCE fqshrtdl.for:265 */
/*<       endif >*/
    }
/*     UPSTREAM LEVEL IS ABOVE BASE.  FIND THE UPSTREAM LEVEL INTERVAL */
/*     CONTAINING EU */
/* SOURCE fqshrtdl.for:270 */
/*<       if(hu.ge.ftab(lhu))then >*/
    if (hu >= ftab[lhu]) {
/* SOURCE fqshrtdl.for:271 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrtdl.for:272 */
/*<       if(hu.le.ftab(lhu+inc))goto120 >*/
	if (hu <= ftab[lhu + 4]) {
	    goto L120;
	}
/* SOURCE fqshrtdl.for:273 */
/*<       lhu=lhu+inc >*/
	lhu += 4;
/* SOURCE fqshrtdl.for:274 */
/*<       goto100 >*/
	goto L100;
/* SOURCE fqshrtdl.for:275 */
/*<       else >*/
    } else {
/* SOURCE fqshrtdl.for:276 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrtdl.for:277 */
/*<       lhu=lhu-inc >*/
	lhu += -4;
/* SOURCE fqshrtdl.for:278 */
/*<       if(hu.ge.ftab(lhu))goto120 >*/
	if (hu >= ftab[lhu]) {
	    goto L120;
	}
/* SOURCE fqshrtdl.for:279 */
/*<       goto110 >*/
	goto L110;
/* SOURCE fqshrtdl.for:280 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:281 */
/*<   120 continue >*/
L120:
/* SOURCE fqshrtdl.for:282 */
/*<       itab(ip+4)=lhu >*/
    itab[*ip + 4] = lhu;
/*      WRITE(STDOUT,*) ' LHU AFTER SEARCH=',LHU */
/*     FREE FLOW MAY RESULT IF THE DOWNSTREAM HEAD IS */
/*     SMALL ENOUGH */
/*     FIND THE HEAD DROP CORRESPONDING TO HU */
/* SOURCE fqshrtdl.for:291 */
/*<       hul=ftab(lhu) >*/
    hul = ftab[lhu];
/* SOURCE fqshrtdl.for:292 */
/*<       hur=ftab(lhu+inc) >*/
    hur = ftab[lhu + 4];
/* SOURCE fqshrtdl.for:293 */
/*<       hdropl=ftab(lhu+1) >*/
    hdropl = ftab[lhu + 1];
/* SOURCE fqshrtdl.for:294 */
/*<       hdropr=ftab(lhu+inc+1) >*/
    hdropr = ftab[lhu + 5];
/* SOURCE fqshrtdl.for:295 */
/*<       ddropu=(hdropr-hdropl)/(hur-hul) >*/
    ddropu = static_cast<double>((static_cast<double>(hdropr) - hdropl)) / (static_cast<double>(hur) - hul);
/* SOURCE fqshrtdl.for:296 */
/*<       thdrop=hdropl+ddropu*(hu-hul) >*/
    thdrop = static_cast<double>(hdropl) + static_cast<double>(ddropu) * (static_cast<double>(hu) - hul);
/*      WRITE(STDOUT,*) ' THDROP=',THDROP */
/*     THDROP IS THE TABLE VALUE OF THE HEAD DROP TO FREE FLOW */
/*     FOR THE CURRENT UPSTREAM LEVEL */
/*     HDROP IS THE CURRENT HEAD DROP */
/* SOURCE fqshrtdl.for:303 */
/*<       hdrop=eu-ed >*/
    hdrop = static_cast<double>(eu) - ed;
/* SOURCE fqshrtdl.for:305 */
/*<       if(hdrop.ge.thdrop)then >*/
    if (hdrop >= thdrop) {
/*       FREE FLOW */
/* SOURCE fqshrtdl.for:308 */
/*<       ql=ftab(lhu+2) >*/
	ql = ftab[lhu + 2];
/* SOURCE fqshrtdl.for:309 */
/*<       qr=ftab(lhu+inc+2) >*/
	qr = ftab[lhu + 6];
/* SOURCE fqshrtdl.for:310 */
/*<       dqeu=(qr-ql)/(hur-hul) >*/
	*dqeu = static_cast<double>((static_cast<double>(qr) - ql)) / (static_cast<double>(hur) - hul);
/* SOURCE fqshrtdl.for:311 */
/*<       q=ql+dqeu*(hu-hul) >*/
	*q = static_cast<double>(ql) + static_cast<double>(*dqeu) * (static_cast<double>(hu) - hul);
/* SOURCE fqshrtdl.for:312 */
/*<       dqed=0.0 >*/
	*dqed = (float)0.;
/* SOURCE fqshrtdl.for:313 */
/*<       free=1 >*/
	*free = 1;
/* SOURCE fqshrtdl.for:315 */
/*<       goto9000 >*/
	goto L9000;
/* SOURCE fqshrtdl.for:316 */
/*<       endif >*/
    }
/*     SUBMERGED FLOW HERE */
/* SOURCE fqshrtdl.for:320 */
/*<       offl=itab(lhu+3) >*/
    offl = itab[lhu + 3];
/* SOURCE fqshrtdl.for:321 */
/*<       offr=itab(lhu+inc+3) >*/
    offr = itab[lhu + 7];
/* SOURCE fqshrtdl.for:322 */
/*<       lpfd=itab(ip+6) >*/
    lpfd = itab[*ip + 6];
/*     FIND THE FRACTION OF FREE FLOW DROP REPRESENTED BY THE CURRENT DROP */
/* SOURCE fqshrtdl.for:326 */
/*<       p=hdrop/thdrop >*/
    p = static_cast<double>(hdrop) / thdrop;
/*      WRITE(STDOUT,*) ' P=',P */
/*     WE HAVE TWO LINES OF CONSTANT UPSTREAM LEVEL.  ONE IS ON THE LEFT */
/*     AND WILL BE DESIGNATED BY THE SUFFIX L.  THE OTHER IS ON THE RIGHT */
/*     AND WILL BE DESIGNATED BY THE SUFFIX R.  ON EACH LINE THERE WILL BE */
/*     A POINT ABOVE AND BELOW P.  THE ONE ABOVE IS DENOTED AS U AND THE */
/*     ONE BELOW AS D.  WE INTERPOLATE IN EACH LINE WITH P AND THEN */
/*     INTERPOLATE ON THE UPSTREAM LEVEL. IN TYPES 13 AND 14 WE HAVE */
/*     ONLY ONE SEQUENCE OF PARTIAL FREE DROPS.  THUS WE SEARCH ONLY */
/*     ONCE. */
/*      WRITE(STDOUT,*) ' TDLK13: OFFL=',OFFL,' OFFR=',OFFR,' LPFD=',LPFD */
/*     SEARCH IN THE PARTIAL FREE DROP LIST */
/* SOURCE fqshrtdl.for:343 */
/*<       lp=lpfd >*/
    lp = lpfd;
/* SOURCE fqshrtdl.for:344 */
/*<       if(p.ge.ftab(lp))then >*/
    if (p >= ftab[lp]) {
/* SOURCE fqshrtdl.for:345 */
/*<   130 continue >*/
L130:
/* SOURCE fqshrtdl.for:346 */
/*<       if(p.le.ftab(lp+1))goto150 >*/
	if (p <= ftab[lp + 1]) {
	    goto L150;
	}
/* SOURCE fqshrtdl.for:347 */
/*<       lp=lp+1 >*/
	++lp;
/* SOURCE fqshrtdl.for:348 */
/*<       goto130 >*/
	goto L130;
/* SOURCE fqshrtdl.for:349 */
/*<       else >*/
    } else {
/* SOURCE fqshrtdl.for:350 */
/*<   140 continue >*/
L140:
/* SOURCE fqshrtdl.for:351 */
/*<       lp=lp-1 >*/
	--lp;
/* SOURCE fqshrtdl.for:352 */
/*<       if(p.ge.ftab(lp))goto150 >*/
	if (p >= ftab[lp]) {
	    goto L150;
	}
/* SOURCE fqshrtdl.for:353 */
/*<       goto140 >*/
	goto L140;
/* SOURCE fqshrtdl.for:354 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:355 */
/*<   150 continue >*/
L150:
/* SOURCE fqshrtdl.for:356 */
/*<       itab(ip+6)=lp >*/
    itab[*ip + 6] = lp;
/*      WRITE(STDOUT,*) ' LP=',LP */
/* SOURCE fqshrtdl.for:360 */
/*<       pld=ftab(lp) >*/
    pld = ftab[lp];
/* SOURCE fqshrtdl.for:361 */
/*<       qld=ftab(offl+lp) >*/
    qld = ftab[offl + lp];
/* SOURCE fqshrtdl.for:362 */
/*<       plu=ftab(lp+1) >*/
    plu = ftab[lp + 1];
/* SOURCE fqshrtdl.for:363 */
/*<       qlu=ftab(offl+lp+1) >*/
    qlu = ftab[offl + lp + 1];
/* SOURCE fqshrtdl.for:364 */
/*<       dq=qlu-qld >*/
    dq = static_cast<double>(qlu) - qld;
/* SOURCE fqshrtdl.for:365 */
/*<       dp=plu-pld >*/
    dp = static_cast<double>(plu) - pld;
/* SOURCE fqshrtdl.for:366 */
/*<       dqlp=dq/dp >*/
    dqlp = static_cast<double>(dq) / dp;
/*      DQLP = (QLU - QLD)/(PLU - PLD) */
/* SOURCE fqshrtdl.for:369 */
/*<       ql=qld+dqlp*(p-pld) >*/
    ql = static_cast<double>(qld) + static_cast<double>(dqlp) * (static_cast<double>(p) - pld);
/* SOURCE fqshrtdl.for:371 */
/*<       prd=pld >*/
    prd = pld;
/* SOURCE fqshrtdl.for:372 */
/*<       qrd=ftab(offr+lp) >*/
    qrd = ftab[offr + lp];
/* SOURCE fqshrtdl.for:373 */
/*<       qru=ftab(offr+lp+1) >*/
    qru = ftab[offr + lp + 1];
/* SOURCE fqshrtdl.for:374 */
/*<       pru=plu >*/
    pru = plu;
/* SOURCE fqshrtdl.for:375 */
/*<       dqrp=(qru-qrd)/(pru-prd) >*/
    dqrp = static_cast<double>((static_cast<double>(qru) - qrd)) / (static_cast<double>(pru) - prd);
/* SOURCE fqshrtdl.for:376 */
/*<       qr=qrd+dqrp*(p-prd) >*/
    qr = static_cast<double>(qrd) + static_cast<double>(dqrp) * (static_cast<double>(p) - prd);
/*     COMPUTE THE FLOW AND ITS DERIVATIVES */
/* SOURCE fqshrtdl.for:380 */
/*<       dqhu=(qr-ql)/(hur-hul) >*/
    dqhu = static_cast<double>((static_cast<double>(qr) - ql)) / (static_cast<double>(hur) - hul);
/* SOURCE fqshrtdl.for:381 */
/*<       q=ql+dqhu*(hu-hul) >*/
    *q = static_cast<double>(ql) + static_cast<double>(dqhu) * (static_cast<double>(hu) - hul);
/* SOURCE fqshrtdl.for:383 */
/*<       fac=(hu-hul)/(hur-hul) >*/
    fac = static_cast<double>((static_cast<double>(hu) - hul)) / (static_cast<double>(hur) - hul);
/* SOURCE fqshrtdl.for:384 */
/*<       dpeu=(1.0-p*ddropu)/thdrop >*/
    dpeu = static_cast<double>((static_cast<double>((float)1.) - static_cast<double>(p) * ddropu)) / thdrop;
/* SOURCE fqshrtdl.for:385 */
/*<       dqleu=dqlp*dpeu >*/
    dqleu = static_cast<double>(dqlp) * dpeu;
/* SOURCE fqshrtdl.for:386 */
/*<       dqreu=dqrp*dpeu >*/
    dqreu = static_cast<double>(dqrp) * dpeu;
/* SOURCE fqshrtdl.for:387 */
/*<       dqeu=dqleu+dqhu+fac*(dqreu-dqleu) >*/
    *dqeu = static_cast<double>(static_cast<double>(dqleu) + dqhu) + static_cast<double>(fac) * (static_cast<double>(dqreu) - dqleu);
/* SOURCE fqshrtdl.for:389 */
/*<       dqled=-dqlp/thdrop >*/
    dqled = static_cast<double>(-dqlp) / thdrop;
/* SOURCE fqshrtdl.for:390 */
/*<       dqred=-dqrp/thdrop >*/
    dqred = static_cast<double>(-dqrp) / thdrop;
/* SOURCE fqshrtdl.for:391 */
/*<       dqed=dqled+fac*(dqred-dqled) >*/
    *dqed = static_cast<double>(dqled) + static_cast<double>(fac) * (static_cast<double>(dqred) - dqled);
/* SOURCE fqshrtdl.for:393 */
/*<       free=0 >*/
    *free = 0;
/* SOURCE fqshrtdl.for:395 */
/*<  9000 continue >*/
L9000:
/* SOURCE fqshrtdl.for:397 */
/*<       return >*/
    return 0;
/* SOURCE fqshrtdl.for:399 */
/*<       end >*/
} /* tdlk13_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrtdl.for:403 */
/*<       subroutineckty15(tabadr,stdout,eflag) >*/
/* Subroutine */ int ckty15_(integer *tabadr, integer *stdout, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*ERR:240* In Table Id=\002,a,\002 of type\
 15 at argument=\002,f10.2,\002 2-D Table Id=\002,a,\002 is invalid\002)";
    static char fmt_52[] = "(/,\002*ERR:241* In Table Id=\002,a,\002 of type\
 15 at argument=\002,f10.2,\002 2-D Table Id=\002,a,\002 is missing.\002)";
    static char fmt_54[] = "(/,\002*ERR:242* In Table Id=\002,a,\002 of type\
 15 at argument=\002,f10.2,\002 2-D Table Id=\002,a,\002 is Type=\002,i5,\
\002.  Type must\002,\002 be 6, 13, or 43.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer ef, tab, low;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer high, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_54, 0 };


/*     + + + PURPOSE + + + */
/*     Check the 2-D table numbers in a table of type 15 and */
/*     replace the table numbers with the addresses of the tables. */
/* SOURCE fqshrtdl.for:411 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrtdl.for:413 */
/*<       integereflag,stdout,tabadr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TABADR - table address */
/*     STDOUT - standard output unit for user messages */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrtdl.for:421 */
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
/* INCLUDE fqshrtdl.for:422 */
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
/* SOURCE fqshrtdl.for:425 */
/*<       integeref,high,i,low,tab,type >*/
/*     Called program units */
/* SOURCE fqshrtdl.for:428 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrtdl.for:429 */
/*<       externalget_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrtdl.for:432 */
/*<    50  >*/
/* SOURCE fqshrtdl.for:434 */
/*<    52  >*/
/* SOURCE fqshrtdl.for:436 */
/*<    54  >*/
/* *********************************************************************** */
/* SOURCE fqshrtdl.for:440 */
/*<       low=tabadr+off234 >*/
/* L50: */
/* L52: */
/* L54: */
    low = *tabadr + 22;
/*     Added July 29,1996. */
/* SOURCE fqshrtdl.for:442 */
/*<       if(itab(tabadr+3).lt.0)then >*/
    if (itab[*tabadr + 3] < 0) {
/*       Table has already been processed. */
/* SOURCE fqshrtdl.for:444 */
/*<       return >*/
	return 0;
/* SOURCE fqshrtdl.for:445 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:446 */
/*<       high=itab(tabadr) >*/
    high = itab[*tabadr];
/* SOURCE fqshrtdl.for:447 */
/*<       do100i=low,high,5 >*/
    feq_gen_i_d_1 = high;
    for (feq_gen_i_d_ = low; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 5) {
/* SOURCE fqshrtdl.for:448 */
/*<       ef=0 >*/
	ef = 0;
/* SOURCE fqshrtdl.for:449 */
/*<       tab=itab(i+1) >*/
	tab = itab[feq_gen_i_d_ + 1];
/* SOURCE fqshrtdl.for:450 */
/*<       if(tab.gt.mftnum)then >*/
	if (tab > 10002) {
/* SOURCE fqshrtdl.for:451 */
/*<       write(stdout,50)get_tabid(itab(tabadr+1)),ftab(i),get_tabid(tab) >*/
	    feq_gen_io_d__85.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__85);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabadr + 1).data());
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(feq_gen_i_d_).data(), (ftnlen)sizeof(real));
	    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &tab);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	    e_wsfe();
/* SOURCE fqshrtdl.for:453 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE fqshrtdl.for:454 */
/*<       ef=1 >*/
	    ef = 1;
/* SOURCE fqshrtdl.for:455 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE fqshrtdl.for:456 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:457 */
/*<       if(ef.eq.0)then >*/
	if (ef == 0) {
/*         The table number is valid.  Convert the table number to the */
/*         address if the table exists. */
/* SOURCE fqshrtdl.for:460 */
/*<       if(ftpnt(tab).gt.0)then >*/
	    if (ftablea_1.ftpnt[tab - 1] > 0) {
/*           The table exists.  Put its address in place of the table# */
/* SOURCE fqshrtdl.for:462 */
/*<       itab(i+1)=ftpnt(tab) >*/
		itab[feq_gen_i_d_ + 1] = ftablea_1.ftpnt[tab - 1];
/* SOURCE fqshrtdl.for:463 */
/*<       else >*/
	    } else {
/* SOURCE fqshrtdl.for:464 */
/*<       write(stdout,52)get_tabid(itab(tabadr+1)),ftab(i),get_tabid(tab) >*/
		feq_gen_io_d__86.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__86);
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabadr + 1).data());
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)ftab.lease(feq_gen_i_d_).data(), (ftnlen)sizeof(real));
		feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &tab);
		s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
		e_wsfe();
/* SOURCE fqshrtdl.for:466 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE fqshrtdl.for:467 */
/*<       ef=1 >*/
		ef = 1;
/* SOURCE fqshrtdl.for:468 */
/*<       endif >*/
	    }
/* SOURCE fqshrtdl.for:469 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:470 */
/*<       if(ef.eq.0)then >*/
	if (ef == 0) {
/*         Table number is valid and the table exists.  Is it the */
/*         correct type? */
/* SOURCE fqshrtdl.for:473 */
/*<       type=itab(itab(i+1)+2) >*/
	    feq_gen_type_d_ = itab[itab[feq_gen_i_d_ + 1] + 2];
/* SOURCE fqshrtdl.for:474 */
/*<       if(type.ne.6.and.type.ne.13.and.type.ne.43)then >*/
	    if (feq_gen_type_d_ != 6 && feq_gen_type_d_ != 13 && feq_gen_type_d_ != 43) {
/*           Not the right type. */
/* SOURCE fqshrtdl.for:476 */
/*<        >*/
		feq_gen_io_d__88.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__88);
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*tabadr + 1).data());
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)ftab.lease(feq_gen_i_d_).data(), (ftnlen)sizeof(real));
		feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &tab);
		s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE fqshrtdl.for:478 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE fqshrtdl.for:479 */
/*<       endif >*/
	    }
/* SOURCE fqshrtdl.for:480 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:481 */
/*<   100 continue >*/
/* L100: */
    }
/*     Set flag to signal that table has been processed. */
/* SOURCE fqshrtdl.for:484 */
/*<       itab(tabadr+3)=-1 >*/
    itab[*tabadr + 3] = -1;
/* SOURCE fqshrtdl.for:485 */
/*<       return >*/
    return 0;
/* SOURCE fqshrtdl.for:486 */
/*<       end >*/
} /* ckty15_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fqshrtdl.for:490 */
/*<        >*/
/* Subroutine */ int tdlk15_(integer *stdout, integer *ip, integer *mftab, 
	doublereal *jtime, real *eda, real *eua, real *hg, real *hbase, real *
	q, real *dqed, real *dqeu, real *newhg, char *ftype, integer *
	feq_gen_ftype_code_d_, ftnlen ftype_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:258* Gate opening=\002,f10.3,\002 >\
 maximum=\002,f10.3,\002 in TabId=\002,a)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real h1, h4, ql, rl, qr, rr, h1l, h4l, h1r, h4r;
    integer tab;
    real hgl, hgr;
    integer low;
    real h1fw, h4fw, h4sw;
    integer feq_gen_flag_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer high, free, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real h1fac, h4fac, h1fwl, h4fwl, h1fwr, h4fwr, h4swl, h4swr;
    integer flagl;
    real dqedl;
    integer flagr, freel;
    real dqedr, mgate;
    extern /* Subroutine */ int tdlk13_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *);
    integer freer;
    real dqeul, dqeur;
    extern /* Subroutine */ int tdlk43_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *);
    real rlsqr;
    integer tab2dl;
    real rrsqr;
    integer tab2dr;
    real h1fwrl, h4fwrl, h1fwrr, h4fwrr, h4swrl, h4swrr, rlcube, rrcube;
    integer lstadr;
    extern /* Subroutine */ int tstsow_(real *, real *, real *, real *, real *
	    , real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Do 3-d lookup for flow for tables of type 15 */
/* SOURCE fqshrtdl.for:497 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fqshrtdl.for:499 */
/*<       integerip,mftab,stdout,ftype_code >*/
/* SOURCE fqshrtdl.for:500 */
/*<       realdqed,dqeu,eda,eua,hbase,hg,newhg,q >*/
/* SOURCE fqshrtdl.for:501 */
/*<       real*8jtime >*/
/* SOURCE fqshrtdl.for:502 */
/*<       characterftype*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     IP     - address of the table */
/*     MFTAB  - table number and later table address of the function */
/*               table that supplies an adjustment factor for flows */
/*     JTIME   - julian time in days */
/*     EDA    - water surface elevation at downstream node */
/*     EUA    - elevation of water surface at upstream node */
/*     HG     - underflow gate opening */
/*     HBASE  - datum for heads */
/*     DQED   - derivative of flow wrt downstream elevation */
/*     DQEU   - derivative flow wrt upstream elevation */
/*     NEWHG  - new gate opening for weir flow */
/*     FTYPE  - descriptor of the state of the underflow gate */
/*     FTYPE_CODE - code number for the string for use in plotting program */
/*               interface */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fqshrtdl.for:521 */
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
/* INCLUDE fqshrtdl.for:522 */
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
/* SOURCE fqshrtdl.for:525 */
/*<        >*/
/* SOURCE fqshrtdl.for:527 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fqshrtdl.for:534 */
/*<       intrinsicsqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fqshrtdl.for:537 */
/*<       character*16get_tabid >*/
/* SOURCE fqshrtdl.for:538 */
/*<       externalget_tabid,tdlk13,tstsow >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fqshrtdl.for:541 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE fqshrtdl.for:544 */
/*<       tab=itab(ip+1) >*/
/* L50: */
    tab = itab[*ip + 1];
/* SOURCE fqshrtdl.for:545 */
/*<       lstadr=itab(ip+4) >*/
    lstadr = itab[*ip + 4];
/* SOURCE fqshrtdl.for:546 */
/*<       high=itab(ip) >*/
    high = itab[*ip];
/* SOURCE fqshrtdl.for:547 */
/*<       low=ip+off234 >*/
    low = *ip + 22;
/*     Compute the heads and eliminate the simple cases. */
/* SOURCE fqshrtdl.for:550 */
/*<       h1=eua-hbase >*/
    h1 = static_cast<double>(*eua) - *hbase;
/* SOURCE fqshrtdl.for:551 */
/*<       h4=eda-hbase >*/
    h4 = static_cast<double>(*eda) - *hbase;
/*      WRITE(STDOUT,*) ' TDLK15: H1=',H1,' H4=',H4 */
/* SOURCE fqshrtdl.for:553 */
/*<       if(h1.le.0.0.or.hg.eq.0.0)then >*/
    if (h1 <= (float)0. || *hg == (float)0.) {
/*       The flow is zero.  Simple case. */
/* SOURCE fqshrtdl.for:555 */
/*<       q=0.0 >*/
	*q = (float)0.;
/* SOURCE fqshrtdl.for:556 */
/*<       dqeu=0.0 >*/
	*dqeu = (float)0.;
/* SOURCE fqshrtdl.for:557 */
/*<       dqed=0.0 >*/
	*dqed = (float)0.;
/* SOURCE fqshrtdl.for:558 */
/*<       ftype=' NO FLOW' >*/
	s_copy(ftype, const_cast<char*>(" NO FLOW"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:559 */
/*<       ftype_code=3 >*/
	*feq_gen_ftype_code_d_ = 3;
/* SOURCE fqshrtdl.for:560 */
/*<       return >*/
	return 0;
/* SOURCE fqshrtdl.for:561 */
/*<       endif >*/
    }
/*     Find the interval containing the argument.   Table underflow */
/*     is OK. */
/* SOURCE fqshrtdl.for:566 */
/*<       if(hg.lt.ftab(low))then >*/
    if (*hg < ftab[low]) {
/* SOURCE fqshrtdl.for:567 */
/*<       tab2dl=0 >*/
	tab2dl = 0;
/* SOURCE fqshrtdl.for:568 */
/*<       hgl=0.0 >*/
	hgl = (float)0.;
/* SOURCE fqshrtdl.for:569 */
/*<       h1fwrl=0.0 >*/
	h1fwrl = (float)0.;
/* SOURCE fqshrtdl.for:570 */
/*<       h4fwrl=0.0 >*/
	h4fwrl = (float)0.;
/* SOURCE fqshrtdl.for:571 */
/*<       h4swrl=0.0 >*/
	h4swrl = (float)0.;
/* SOURCE fqshrtdl.for:572 */
/*<       hgr=ftab(low) >*/
	hgr = ftab[low];
/* SOURCE fqshrtdl.for:573 */
/*<       tab2dr=itab(low+1) >*/
	tab2dr = itab[low + 1];
/* SOURCE fqshrtdl.for:574 */
/*<       h1fwrr=ftab(low+2) >*/
	h1fwrr = ftab[low + 2];
/* SOURCE fqshrtdl.for:575 */
/*<       h4fwrr=ftab(low+3) >*/
	h4fwrr = ftab[low + 3];
/* SOURCE fqshrtdl.for:576 */
/*<       h4swrr=ftab(low+4) >*/
	h4swrr = ftab[low + 4];
/* SOURCE fqshrtdl.for:577 */
/*<       h1fwr=hgr*h1fwrr >*/
	h1fwr = static_cast<double>(hgr) * h1fwrr;
/* SOURCE fqshrtdl.for:578 */
/*<       h4fwr=hgr*h4fwrr >*/
	h4fwr = static_cast<double>(hgr) * h4fwrr;
/* SOURCE fqshrtdl.for:579 */
/*<       h4swr=hgr*h4swrr >*/
	h4swr = static_cast<double>(hgr) * h4swrr;
/* SOURCE fqshrtdl.for:580 */
/*<       elseif(hg.gt.ftab(high))then >*/
    } else if (*hg > ftab[high]) {
/*       Table overflow on the third argument.  Give message and stop. */
/* SOURCE fqshrtdl.for:582 */
/*<       write(stdout,50)hg,ftab(high),get_tabid(tab) >*/
	feq_gen_io_d__111.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__111);
	do_fio(&feq_gen_c_d_1, (char *)&(*hg), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)ftab.lease(high).data(), (ftnlen)sizeof(real));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE fqshrtdl.for:583 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fqshrtdl.for:584 */
/*<       else >*/
    } else {
/*       Seems to be in range of the table.  Search from last access */
/*       point. */
/* SOURCE fqshrtdl.for:588 */
/*<       if(hg.ge.ftab(lstadr))then >*/
	if (*hg >= ftab[lstadr]) {
/* SOURCE fqshrtdl.for:589 */
/*<   100 continue >*/
L100:
/* SOURCE fqshrtdl.for:590 */
/*<       if(hg.gt.ftab(lstadr+5))then >*/
	    if (*hg > ftab[lstadr + 5]) {
/* SOURCE fqshrtdl.for:591 */
/*<       lstadr=lstadr+5 >*/
		lstadr += 5;
/* SOURCE fqshrtdl.for:592 */
/*<       goto100 >*/
		goto L100;
/* SOURCE fqshrtdl.for:593 */
/*<       endif >*/
	    }
/* SOURCE fqshrtdl.for:594 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:595 */
/*<   110 continue >*/
L110:
/* SOURCE fqshrtdl.for:596 */
/*<       lstadr=lstadr-5 >*/
	    lstadr += -5;
/* SOURCE fqshrtdl.for:597 */
/*<       if(hg.lt.ftab(lstadr))goto110 >*/
	    if (*hg < ftab[lstadr]) {
		goto L110;
	    }
/* SOURCE fqshrtdl.for:598 */
/*<       endif >*/
	}
/*       AT THIS POINT LSTADR DEFINES THE LOW ARGUMENT END OF THE */
/*       INTERVAL CONTAINING THE ARGUMENT */
/*       RESET POINTER FOR LAST ADDRESS */
/* SOURCE fqshrtdl.for:604 */
/*<       itab(ip+4)=lstadr >*/
	itab[*ip + 4] = lstadr;
/* SOURCE fqshrtdl.for:606 */
/*<       hgl=ftab(lstadr) >*/
	hgl = ftab[lstadr];
/* SOURCE fqshrtdl.for:607 */
/*<       tab2dl=itab(lstadr+1) >*/
	tab2dl = itab[lstadr + 1];
/* SOURCE fqshrtdl.for:608 */
/*<       h1fwrl=ftab(lstadr+2) >*/
	h1fwrl = ftab[lstadr + 2];
/* SOURCE fqshrtdl.for:609 */
/*<       h4fwrl=ftab(lstadr+3) >*/
	h4fwrl = ftab[lstadr + 3];
/* SOURCE fqshrtdl.for:610 */
/*<       h4swrl=ftab(lstadr+4) >*/
	h4swrl = ftab[lstadr + 4];
/* SOURCE fqshrtdl.for:611 */
/*<       h1fwl=hgl*h1fwrl >*/
	h1fwl = static_cast<double>(hgl) * h1fwrl;
/* SOURCE fqshrtdl.for:612 */
/*<       h4fwl=hgl*h4fwrl >*/
	h4fwl = static_cast<double>(hgl) * h4fwrl;
/* SOURCE fqshrtdl.for:613 */
/*<       h4swl=hgl*h4swrl >*/
	h4swl = static_cast<double>(hgl) * h4swrl;
/* SOURCE fqshrtdl.for:615 */
/*<       hgr=ftab(lstadr+5) >*/
	hgr = ftab[lstadr + 5];
/* SOURCE fqshrtdl.for:616 */
/*<       tab2dr=itab(lstadr+6) >*/
	tab2dr = itab[lstadr + 6];
/* SOURCE fqshrtdl.for:617 */
/*<       h1fwrr=ftab(lstadr+7) >*/
	h1fwrr = ftab[lstadr + 7];
/* SOURCE fqshrtdl.for:618 */
/*<       h4fwrr=ftab(lstadr+8) >*/
	h4fwrr = ftab[lstadr + 8];
/* SOURCE fqshrtdl.for:619 */
/*<       h4swrr=ftab(lstadr+9) >*/
	h4swrr = ftab[lstadr + 9];
/* SOURCE fqshrtdl.for:620 */
/*<       h1fwr=hgr*h1fwrr >*/
	h1fwr = static_cast<double>(hgr) * h1fwrr;
/* SOURCE fqshrtdl.for:621 */
/*<       h4fwr=hgr*h4fwrr >*/
	h4fwr = static_cast<double>(hgr) * h4fwrr;
/* SOURCE fqshrtdl.for:622 */
/*<       h4swr=hgr*h4swrr >*/
	h4swr = static_cast<double>(hgr) * h4swrr;
/* SOURCE fqshrtdl.for:623 */
/*<       endif >*/
    }
/*     set type for 2-d lookup */
/* SOURCE fqshrtdl.for:626 */
/*<       type=itab(tab2dr+2) >*/
    feq_gen_type_d_ = itab[tab2dr + 2];
/*      WRITE(STDOUT,*) ' TDLK15: HGL=',HGL,' HG=',HG,' HGR=',HGR */
/* SOURCE fqshrtdl.for:630 */
/*<       mgate=(hg-hgl)/(hgr-hgl) >*/
    mgate = static_cast<double>((static_cast<double>(*hg) - hgl)) / (static_cast<double>(hgr) - hgl);
/*      WRITE(STDOUT,*) ' TDLK15: TAB2DL=',ITAB(TAB2DL+1), */
/*     A                 ' TAB2DR=',ITAB(TAB2DR+1) */
/*      WRITE(STDOUT,*) ' H1FWRL=',H1FWRL,' H4FWRL=',H4FWRL, */
/*     A                ' H4SWRL=',H4SWRL */
/*      WRITE(STDOUT,*) ' H1FWRR=',H1FWRR,' H4FWRR=',H4FWRR, */
/*     A                ' H4SWRR=',H4SWRR */
/*     Compute the upper limit of upstream head for FW flow. */
/* SOURCE fqshrtdl.for:640 */
/*<       h1fw=hg*(h1fwrl+mgate*(h1fwrr-h1fwrl)) >*/
    h1fw = static_cast<double>(*hg) * (static_cast<double>(h1fwrl) + static_cast<double>(mgate) * (static_cast<double>(h1fwrr) - h1fwrl));
/*     Compute the values for the boundary between SW and SO */
/* SOURCE fqshrtdl.for:643 */
/*<       h4fw=hg*(h4fwrl+mgate*(h4fwrr-h4fwrl)) >*/
    h4fw = static_cast<double>(*hg) * (static_cast<double>(h4fwrl) + static_cast<double>(mgate) * (static_cast<double>(h4fwrr) - h4fwrl));
/* SOURCE fqshrtdl.for:644 */
/*<       h4sw=hg*(h4swrl+mgate*(h4swrr-h4swrl)) >*/
    h4sw = static_cast<double>(*hg) * (static_cast<double>(h4swrl) + static_cast<double>(mgate) * (static_cast<double>(h4swrr) - h4swrl));
/*     Decide what flow type is involved at the gate opening, HG. */
/* SOURCE fqshrtdl.for:647 */
/*<       if(h1.le.hg)then >*/
    if (h1 <= *hg) {
/*       The flow is weir flow.  Lookup in the right-hand table because */
/*       it should have weir flow high enough for any intermediate */
/*       point. */
/* SOURCE fqshrtdl.for:651 */
/*<       if(type.eq.13)then >*/
	if (feq_gen_type_d_ == 13) {
/* SOURCE fqshrtdl.for:652 */
/*<        >*/
	    tdlk13_(stdout, &tab2dr, &feq_gen_c_d_13, mftab, jtime, eda, eua, hbase, q,
		     dqed, dqeu, &free);
/* SOURCE fqshrtdl.for:655 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:656 */
/*<        >*/
	    tdlk43_(stdout, &tab2dr, &feq_gen_c_d_43, mftab, jtime, eda, eua, hbase, q,
		     dqed, dqeu, &free);
/* SOURCE fqshrtdl.for:659 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' Q=',Q,' DQED=',DQED,' DQEU=',DQEU */
/* SOURCE fqshrtdl.for:662 */
/*<       if(free.eq.1)then >*/
	if (free == 1) {
/* SOURCE fqshrtdl.for:663 */
/*<       ftype='      FW' >*/
	    s_copy(ftype, const_cast<char*>("      FW"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:664 */
/*<       ftype_code=2 >*/
	    *feq_gen_ftype_code_d_ = 2;
/* SOURCE fqshrtdl.for:665 */
/*<       newhg=h4fw >*/
	    *newhg = h4fw;
/* SOURCE fqshrtdl.for:666 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:667 */
/*<       ftype='      SW' >*/
	    s_copy(ftype, const_cast<char*>("      SW"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:668 */
/*<       ftype_code=1 >*/
	    *feq_gen_ftype_code_d_ = 1;
/* SOURCE fqshrtdl.for:669 */
/*<       newhg=eda-hbase >*/
	    *newhg = static_cast<double>(*eda) - *hbase;
/* SOURCE fqshrtdl.for:670 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:671 */
/*<       return >*/
	return 0;
/* SOURCE fqshrtdl.for:672 */
/*<       elseif(h1.le.h1fw)then >*/
    } else if (h1 <= h1fw) {
/*       Flow might be weir flow. */
/* SOURCE fqshrtdl.for:674 */
/*<       calltstsow(h1,h4,hg,h1fw,h4fw,h4sw,flag) >*/
	tstsow_(&h1, &h4, hg, &h1fw, &h4fw, &h4sw, &feq_gen_flag_d_);
/* SOURCE fqshrtdl.for:677 */
/*<       if(flag.eq.0)then >*/
	if (feq_gen_flag_d_ == 0) {
/*         The flow is weir flow. */
/* SOURCE fqshrtdl.for:679 */
/*<       if(type.eq.13)then >*/
	    if (feq_gen_type_d_ == 13) {
/* SOURCE fqshrtdl.for:680 */
/*<        >*/
		tdlk13_(stdout, &tab2dr, &feq_gen_c_d_13, mftab, jtime, eda, eua, 
			hbase, q, dqed, dqeu, &free);
/* SOURCE fqshrtdl.for:683 */
/*<       else >*/
	    } else {
/* SOURCE fqshrtdl.for:684 */
/*<        >*/
		tdlk43_(stdout, &tab2dr, &feq_gen_c_d_43, mftab, jtime, eda, eua, 
			hbase, q, dqed, dqeu, &free);
/* SOURCE fqshrtdl.for:687 */
/*<       endif >*/
	    }
/*          WRITE(STDOUT,*) ' Q=',Q,' DQED=',DQED,' DQEU=',DQEU */
/* SOURCE fqshrtdl.for:690 */
/*<       if(free.eq.1)then >*/
	    if (free == 1) {
/* SOURCE fqshrtdl.for:691 */
/*<       ftype='      FW' >*/
		s_copy(ftype, const_cast<char*>("      FW"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:692 */
/*<       ftype_code=2 >*/
		*feq_gen_ftype_code_d_ = 2;
/* SOURCE fqshrtdl.for:693 */
/*<       newhg=h4fw >*/
		*newhg = h4fw;
/* SOURCE fqshrtdl.for:694 */
/*<       else >*/
	    } else {
/* SOURCE fqshrtdl.for:695 */
/*<       ftype='      SW' >*/
		s_copy(ftype, const_cast<char*>("      SW"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:696 */
/*<       ftype_code=1 >*/
		*feq_gen_ftype_code_d_ = 1;
/* SOURCE fqshrtdl.for:697 */
/*<       newhg=eda-hbase >*/
		*newhg = static_cast<double>(*eda) - *hbase;
/* SOURCE fqshrtdl.for:698 */
/*<       endif >*/
	    }
/* SOURCE fqshrtdl.for:699 */
/*<       return >*/
	    return 0;
/* SOURCE fqshrtdl.for:700 */
/*<       else >*/
	} else {
/*         At least one table is in SO for the intermediate */
/*         point to be in SO. */
/* SOURCE fqshrtdl.for:703 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:704 */
/*<       endif >*/
    }
/*     Orifice flow remains.  Two cases: 1. The left-hand table is */
/*     for HG=0.  2. Both tables have non-zero HG. */

/* SOURCE fqshrtdl.for:709 */
/*<       if(tab2dl.eq.0)then >*/
    if (tab2dl == 0) {
/*       The gate opening is between 0.0 and the first table. */
/*       We assume that all values at Hg=0.0 are zero. */
/* SOURCE fqshrtdl.for:713 */
/*<       if(type.eq.13)then >*/
	if (feq_gen_type_d_ == 13) {
/* SOURCE fqshrtdl.for:714 */
/*<        >*/
	    tdlk13_(stdout, &tab2dr, &feq_gen_c_d_13, mftab, jtime, eda, eua, hbase, &
		    qr, &dqedr, &dqeur, &freer);
/* SOURCE fqshrtdl.for:717 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:718 */
/*<        >*/
	    tdlk43_(stdout, &tab2dr, &feq_gen_c_d_43, mftab, jtime, eda, eua, hbase, &
		    qr, &dqedr, &dqeur, &freer);
/* SOURCE fqshrtdl.for:721 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:724 */
/*<       q=hg*qr/hgr >*/
	*q = static_cast<double>(static_cast<double>(*hg) * qr) / hgr;
/* SOURCE fqshrtdl.for:725 */
/*<       dqed=hg*dqedr/hgr >*/
	*dqed = static_cast<double>(static_cast<double>(*hg) * dqedr) / hgr;
/* SOURCE fqshrtdl.for:726 */
/*<       dqeu=hg*dqeur/hgr >*/
	*dqeu = static_cast<double>(static_cast<double>(*hg) * dqeur) / hgr;
/* SOURCE fqshrtdl.for:727 */
/*<       if(freer.eq.1)then >*/
	if (freer == 1) {
/* SOURCE fqshrtdl.for:728 */
/*<       ftype='      FO' >*/
	    s_copy(ftype, const_cast<char*>("      FO"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:729 */
/*<       ftype_code=11 >*/
	    *feq_gen_ftype_code_d_ = 11;
/* SOURCE fqshrtdl.for:730 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:731 */
/*<       ftype='      SO' >*/
	    s_copy(ftype, const_cast<char*>("      SO"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:732 */
/*<       ftype_code=12 >*/
	    *feq_gen_ftype_code_d_ = 12;
/* SOURCE fqshrtdl.for:733 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:734 */
/*<       else >*/
    } else {
/*       Test if tables are in orifice flow. */
/* SOURCE fqshrtdl.for:736 */
/*<       flagl=0 >*/
	flagl = 0;
/* SOURCE fqshrtdl.for:737 */
/*<       if(h1.le.h1fwl)then >*/
	if (h1 <= h1fwl) {
/* SOURCE fqshrtdl.for:738 */
/*<       calltstsow(h1,h4,hgl,h1fwl,h4fwl,h4swl,flagl) >*/
	    tstsow_(&h1, &h4, &hgl, &h1fwl, &h4fwl, &h4swl, &flagl);
/*          IF(FLAGL.EQ.1) THEN */
/*            WRITE(STDOUT,*) ' Left tab in SO above SW' */
/*          ENDIF */
/* SOURCE fqshrtdl.for:744 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:745 */
/*<       flagl=1 >*/
	    flagl = 1;
/* SOURCE fqshrtdl.for:746 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:747 */
/*<       flagr=0 >*/
	flagr = 0;
/* SOURCE fqshrtdl.for:748 */
/*<       if(h1.le.h1fwr)then >*/
	if (h1 <= h1fwr) {
/* SOURCE fqshrtdl.for:749 */
/*<       calltstsow(h1,h4,hgr,h1fwr,h4fwr,h4swr,flagr) >*/
	    tstsow_(&h1, &h4, &hgr, &h1fwr, &h4fwr, &h4swr, &flagr);
/*          IF(FLAGR.EQ.1) THEN */
/*            WRITE(STDOUT,*) ' Right tab in SO above SW' */
/*          ENDIF */
/* SOURCE fqshrtdl.for:755 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:756 */
/*<       flagr=1 >*/
	    flagr = 1;
/* SOURCE fqshrtdl.for:757 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:759 */
/*<       h1fac=h1/hg >*/
	h1fac = static_cast<double>(h1) / *hg;
/* SOURCE fqshrtdl.for:760 */
/*<       h4fac=h4/hg >*/
	h4fac = static_cast<double>(h4) / *hg;
/* SOURCE fqshrtdl.for:761 */
/*<       h1l=h1fac*hgl >*/
	h1l = static_cast<double>(h1fac) * hgl;
/* SOURCE fqshrtdl.for:762 */
/*<       h4l=h4fac*hgl >*/
	h4l = static_cast<double>(h4fac) * hgl;
/* SOURCE fqshrtdl.for:764 */
/*<       h1r=h1fac*hgr >*/
	h1r = static_cast<double>(h1fac) * hgr;
/* SOURCE fqshrtdl.for:765 */
/*<       h4r=h4fac*hgr >*/
	h4r = static_cast<double>(h4fac) * hgr;
/* SOURCE fqshrtdl.for:767 */
/*<       if(type.eq.13)then >*/
	if (feq_gen_type_d_ == 13) {
/* SOURCE fqshrtdl.for:768 */
/*<        >*/
	    feq_gen_r_d_1 = static_cast<double>(h4l) + *hbase;
	    feq_gen_r_d_2 = static_cast<double>(h1l) + *hbase;
	    tdlk13_(stdout, &tab2dl, &feq_gen_c_d_13, mftab, jtime, &feq_gen_r_d_1, &feq_gen_r_d_2, 
		    hbase, &ql, &dqedl, &dqeul, &freel);
/* SOURCE fqshrtdl.for:772 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:773 */
/*<        >*/
	    feq_gen_r_d_1 = static_cast<double>(h4l) + *hbase;
	    feq_gen_r_d_2 = static_cast<double>(h1l) + *hbase;
	    tdlk43_(stdout, &tab2dl, &feq_gen_c_d_43, mftab, jtime, &feq_gen_r_d_1, &feq_gen_r_d_2, 
		    hbase, &ql, &dqedl, &dqeul, &freel);
/* SOURCE fqshrtdl.for:777 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' H1L=',H1L,' H4L=',H4L */
/*        WRITE(STDOUT,*) ' QL=',QL,' DQEUL=',DQEUL,' DQEDL=',DQEDL */
/* SOURCE fqshrtdl.for:781 */
/*<       if(type.eq.13)then >*/
	if (feq_gen_type_d_ == 13) {
/* SOURCE fqshrtdl.for:782 */
/*<        >*/
	    feq_gen_r_d_1 = static_cast<double>(h4r) + *hbase;
	    feq_gen_r_d_2 = static_cast<double>(h1r) + *hbase;
	    tdlk13_(stdout, &tab2dr, &feq_gen_c_d_13, mftab, jtime, &feq_gen_r_d_1, &feq_gen_r_d_2, 
		    hbase, &qr, &dqedr, &dqeur, &freer);
/* SOURCE fqshrtdl.for:786 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:787 */
/*<        >*/
	    feq_gen_r_d_1 = static_cast<double>(h4r) + *hbase;
	    feq_gen_r_d_2 = static_cast<double>(h1r) + *hbase;
	    tdlk43_(stdout, &tab2dr, &feq_gen_c_d_43, mftab, jtime, &feq_gen_r_d_1, &feq_gen_r_d_2, 
		    hbase, &qr, &dqedr, &dqeur, &freer);
/* SOURCE fqshrtdl.for:791 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' H1R=',H1R,' H4R=',H4R */
/*        WRITE(STDOUT,*) ' QR=',QR,' DQEUR=',DQEUR,' DQEDR=',DQEDR */
/* SOURCE fqshrtdl.for:795 */
/*<       rl=hg/hgl >*/
	rl = static_cast<double>(*hg) / hgl;
/* SOURCE fqshrtdl.for:796 */
/*<       rlsqr=rl**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = rl;
	rlsqr = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE fqshrtdl.for:797 */
/*<       rlcube=rl*rlsqr >*/
	rlcube = static_cast<double>(rl) * rlsqr;
/* SOURCE fqshrtdl.for:798 */
/*<       rr=hg/hgr >*/
	rr = static_cast<double>(*hg) / hgr;
/* SOURCE fqshrtdl.for:799 */
/*<       rrsqr=rr**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = rr;
	rrsqr = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE fqshrtdl.for:800 */
/*<       rrcube=rr*rrsqr >*/
	rrcube = static_cast<double>(rr) * rrsqr;
/* SOURCE fqshrtdl.for:802 */
/*<       q=sqrt(rlcube*ql**2+mgate*(rrcube*qr**2-rlcube*ql**2)) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ql;
/* Computing 2nd power */
	feq_gen_r_d_2 = qr;
/* Computing 2nd power */
	feq_gen_r_d_3 = ql;
	*q = sqrt(static_cast<double>(static_cast<double>(rlcube) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) + static_cast<double>(mgate) * (static_cast<double>(static_cast<double>(rrcube) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) - 
		static_cast<double>(rlcube) * (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3)));
/* SOURCE fqshrtdl.for:805 */
/*<       rlsqr=rlsqr*ql >*/
	rlsqr *= ql;
/* SOURCE fqshrtdl.for:806 */
/*<       rrsqr=rrsqr*qr >*/
	rrsqr *= qr;
/* SOURCE fqshrtdl.for:807 */
/*<       dqeu=(rlsqr*dqeul+mgate*(rrsqr*dqeur-rlsqr*dqeul))/q >*/
	*dqeu = static_cast<double>((static_cast<double>(static_cast<double>(rlsqr) * dqeul) + static_cast<double>(mgate) * (static_cast<double>(static_cast<double>(rrsqr) * dqeur) - static_cast<double>(rlsqr) * dqeul))) / *
		q;
/* SOURCE fqshrtdl.for:809 */
/*<       dqed=(rlsqr*dqedl+mgate*(rrsqr*dqedr-rlsqr*dqedl))/q >*/
	*dqed = static_cast<double>((static_cast<double>(static_cast<double>(rlsqr) * dqedl) + static_cast<double>(mgate) * (static_cast<double>(static_cast<double>(rrsqr) * dqedr) - static_cast<double>(rlsqr) * dqedl))) / *
		q;
/*        WRITE(STDOUT,*) ' Rescaled interpolation:' */
/*        WRITE(STDOUT,*) ' Q=',Q,' DQEU=',DQEU,' DQED=',DQED */
/*       Set the flow type */
/* SOURCE fqshrtdl.for:815 */
/*<       if(freel.eq.1)then >*/
	if (freel == 1) {
/* SOURCE fqshrtdl.for:816 */
/*<       if(freer.eq.1)then >*/
	    if (freer == 1) {
/* SOURCE fqshrtdl.for:817 */
/*<       ftype='      FO' >*/
		s_copy(ftype, const_cast<char*>("      FO"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:818 */
/*<       ftype_code=11 >*/
		*feq_gen_ftype_code_d_ = 11;
/* SOURCE fqshrtdl.for:819 */
/*<       else >*/
	    } else {
/* SOURCE fqshrtdl.for:820 */
/*<       ftype='      OR' >*/
		s_copy(ftype, const_cast<char*>("      OR"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:821 */
/*<       ftype_code=13 >*/
		*feq_gen_ftype_code_d_ = 13;
/* SOURCE fqshrtdl.for:822 */
/*<       endif >*/
	    }
/* SOURCE fqshrtdl.for:823 */
/*<       else >*/
	} else {
/* SOURCE fqshrtdl.for:824 */
/*<       if(freer.eq.1)then >*/
	    if (freer == 1) {
/* SOURCE fqshrtdl.for:825 */
/*<       ftype='      OR' >*/
		s_copy(ftype, const_cast<char*>("      OR"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:826 */
/*<       ftype_code=13 >*/
		*feq_gen_ftype_code_d_ = 13;
/* SOURCE fqshrtdl.for:827 */
/*<       else >*/
	    } else {
/* SOURCE fqshrtdl.for:828 */
/*<       ftype='      SO' >*/
		s_copy(ftype, const_cast<char*>("      SO"), (ftnlen)8, (ftnlen)8);
/* SOURCE fqshrtdl.for:829 */
/*<       ftype_code=12 >*/
		*feq_gen_ftype_code_d_ = 12;
/* SOURCE fqshrtdl.for:830 */
/*<       endif >*/
	    }
/* SOURCE fqshrtdl.for:831 */
/*<       endif >*/
	}
/* SOURCE fqshrtdl.for:832 */
/*<       endif >*/
    }
/* SOURCE fqshrtdl.for:833 */
/*<       return >*/
    return 0;
/* SOURCE fqshrtdl.for:834 */
/*<       end >*/
} /* tdlk15_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
