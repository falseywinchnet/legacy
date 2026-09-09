/* newlookup.f -- translated by f2c (version 20240504).
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
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_43 = 43;
static integer feq_gen_c_d_0 = 0;
static doublereal c_b86 = 0.;
static real c_b87 = (float)0.;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1000 = 1000;
static integer feq_gen_c_d_3 = 3;

/*     1-6 March 2003:  Start some new lookup and storage options to see if */
/*     we can improve robustness of the solution in FEQ by providing, as a start, */
/*     at storage and lookup for type 13 tables that will provide at least */
/*     continuous first derivatives and in some cases continuous second derivatives. */



/* SOURCE newlookup.for:9 */
/*<        >*/
/* Subroutine */ int tdlk43_(integer *stdout, integer *ip, integer *ptype, 
	integer *mftab, doublereal *jtime, real *eda, real *eua, real *hbase, 
	real *q, real *dqed, real *dqeu, integer *free)
{
    /* Format strings */
    static char fmt_50[] = "(\002*ERR:72* EU < ED in two-D TABID=\002,a,\002\
 EU=\002,f10.2,\002 ED=\002,f10.2)";
    static char fmt_52[] = "(\002*WRN:04* HU > HMAX in two-D TABID=\002,a\
,\002 HU=\002,f10.2,\002 HMAX=\002,f10.2)";
    static char fmt_54[] = "(\002*ERR:73* Unexpected type in two-D TABID\002\
,a,\002 Type=\002,i5,\002 expected Type=\002,i5)";

    /* System generated locals */
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real pqppfdld, pqppfdrd, pqppfdlu, pqppfdru, feq_gen_h_d_, p, t;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real ed, dm, fl, fr, eu;
    integer lp, it;
    real hu, ql, qr, dthdropdhu;
    integer tab;
    real dlp, qld, flp, drp, qrd, frp;
    integer lhu, itl;
    real hul;
    integer itr;
    real hur, qlu, qru, ppqppfdphul, ppqppfdphur;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    real pfdd;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real feq_gen_h_hu_d_;
    integer ppfd;
    real hmax, pfdu, feq_gen_t_hu_d_, drop;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real ppqppfdphuld, ppqppfdphurd, ppqppfdphulu, ppqppfdphuru, feq_gen_fl_hu_d_, 
	    feq_gen_dm_hu_d_, hdrop, feq_gen_fr_hu_d_, pqphu, feq_gen_flp_hu_d_, feq_gen_dlp_hu_d_, dqldhu, 
	    feq_gen_drp_hu_d_, feq_gen_frp_hu_d_, dqrdhu, hdropl, pqppfd, hdropr, thdrop, 
	    pqphul, pqphur, dhdropl, dhdropr, pqppfdl;
    integer qoffset;
    real pqppfdr, pqphuld, pqphurd, pqphulu, pqphuru;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Do 2-d lookup for flow for tables of type 43. */
/*     These tables use piecewise-cubic Hermite interpolation in */
/*     both the upstream head, and partial free drop.  If the smoother */
/*     function gives us enough benefit, then we will revise the order */
/*     of storage and lookup to gain a bit of speed. */
/* SOURCE newlookup.for:22 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE newlookup.for:24 */
/*<       integerfree,ip,stdout,mftab,ptype >*/
/* SOURCE newlookup.for:25 */
/*<       realdqed,dqeu,eda,eua,hbase,q >*/
/* SOURCE newlookup.for:26 */
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
/* INCLUDE newlookup.for:44 */
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
/* INCLUDE newlookup.for:45 */
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
/* SOURCE newlookup.for:48 */
/*<       integerinc >*/
/* SOURCE newlookup.for:49 */
/*<       parameter(inc=4) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE newlookup.for:52 */
/*<       integerlhu,lp,ntab,tab,type >*/
/* SOURCE newlookup.for:53 */
/*<       integerit,itl,itr,qoffset,ppfd >*/
/* SOURCE newlookup.for:54 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE newlookup.for:72 */
/*<       character*16get_tabid >*/
/* SOURCE newlookup.for:73 */
/*<       externalget_tabid,lktstab >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE newlookup.for:76 */
/*<    50  >*/
/* SOURCE newlookup.for:78 */
/*<    52  >*/
/* SOURCE newlookup.for:80 */
/*<    54  >*/
/* *********************************************************************** */
/*     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT */
/*     POINTERS ARE SET TO THE PROPER VALUES AT START */
/* SOURCE newlookup.for:86 */
/*<       tab=itab(ip+1) >*/
/* L50: */
/* L52: */
/* L54: */
    tab = itab[*ip + 1];
/* SOURCE newlookup.for:87 */
/*<       type=itab(ip+2) >*/
    feq_gen_type_d_ = itab[*ip + 2];
/* SOURCE newlookup.for:88 */
/*<       lhu=itab(ip+4) >*/
    lhu = itab[*ip + 4];
/* SOURCE newlookup.for:89 */
/*<       hmax=ftab(ip+9) >*/
    hmax = ftab[*ip + 9];
/*     Get the offset from zero flow to free flow in the table.  This is */
/*     a constant for each upstream head and is 4*(number of partial free drops */
/*     including zero free drop - 1).  Must be set on input of the table! */
/* SOURCE newlookup.for:94 */
/*<       qoffset=itab(ip+10) >*/
    qoffset = itab[*ip + 10];
/*     Get the pointer to the start of the partial free-drop sequence. */
/*     needed to compute some offsets. */
/* SOURCE newlookup.for:98 */
/*<       ppfd=itab(ip+5) >*/
    ppfd = itab[*ip + 5];
/*      WRITE(STDOUT,*) ' TDLK43: TAB=',TAB,' TYPE=',TYPE,' LHU=',LHU */
/*     IMPORTANT: THE DESIGNATIONS UPSTREAM AND DOWNSTREAM REFER TO */
/*     THE TRUE RELATIONSHIP.  THUS EU >= ED ALWAYS. */
/* SOURCE newlookup.for:106 */
/*<       eu=eua >*/
    eu = *eua;
/* SOURCE newlookup.for:107 */
/*<       ed=eda >*/
    ed = *eda;
/*      write(stdout,*) ' tdlk43 EU=',EU,' ED=',ED,' HBASE=',HBASE, */
/*     a                ' HMAX=',HMAX */
/* SOURCE newlookup.for:110 */
/*<       if(type.ne.ptype)then >*/
    if (feq_gen_type_d_ != *ptype) {
/* SOURCE newlookup.for:111 */
/*<       write(stdout,54)get_tabid(tab),type,ptype >*/
	feq_gen_io_d__12.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__12);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*ptype), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE newlookup.for:112 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE newlookup.for:113 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:115 */
/*<       if(eu.lt.ed)then >*/
    if (eu < ed) {
/* SOURCE newlookup.for:116 */
/*<       write(stdout,50)get_tabid(tab),eu,ed >*/
	feq_gen_io_d__13.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__13);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&eu, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ed, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE newlookup.for:117 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE newlookup.for:118 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:121 */
/*<       hu=eu-hbase >*/
    hu = static_cast<double>(eu) - *hbase;
/* SOURCE newlookup.for:123 */
/*<       if(hu.gt.hmax)then >*/
    if (hu > hmax) {
/* SOURCE newlookup.for:124 */
/*<       write(stdout,52)get_tabid(tab),hu,hmax >*/
	feq_gen_io_d__15.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__15);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&hu, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE newlookup.for:125 */
/*<       drop=eu-ed >*/
	drop = static_cast<double>(eu) - ed;
/* SOURCE newlookup.for:126 */
/*<       hu=hmax >*/
	hu = hmax;
/* SOURCE newlookup.for:127 */
/*<       eu=hbase+hmax >*/
	eu = static_cast<double>(*hbase) + hmax;
/* SOURCE newlookup.for:128 */
/*<       ed=eu-drop >*/
	ed = static_cast<double>(eu) - drop;
/* SOURCE newlookup.for:129 */
/*<       endif >*/
    }
/*     DETERMINE IF THERE IS FLOW AND IF IT IS KNOWN TO BE FREE */
/* SOURCE newlookup.for:134 */
/*<       if(eu.le.hbase)then >*/
    if (eu <= *hbase) {
/*       FLOW IS ZERO AND SO ARE DERIVATIVES */
/* SOURCE newlookup.for:136 */
/*<       q=0.0 >*/
	*q = (float)0.;
/* SOURCE newlookup.for:137 */
/*<       dqed=0.0 >*/
	*dqed = (float)0.;
/* SOURCE newlookup.for:138 */
/*<       dqeu=0.0 >*/
	*dqeu = (float)0.;
/* SOURCE newlookup.for:139 */
/*<       free=0 >*/
	*free = 0;
/* SOURCE newlookup.for:140 */
/*<       goto9000 >*/
	goto L9000;
/* SOURCE newlookup.for:141 */
/*<       endif >*/
    }
/*     UPSTREAM LEVEL IS ABOVE BASE.  FIND THE UPSTREAM LEVEL INTERVAL */
/*     CONTAINING EU */
/* SOURCE newlookup.for:146 */
/*<       if(hu.ge.ftab(lhu))then >*/
    if (hu >= ftab[lhu]) {
/* SOURCE newlookup.for:147 */
/*<   100 continue >*/
L100:
/* SOURCE newlookup.for:148 */
/*<       if(hu.le.ftab(lhu+inc))goto120 >*/
	if (hu <= ftab[lhu + 4]) {
	    goto L120;
	}
/* SOURCE newlookup.for:149 */
/*<       lhu=lhu+inc >*/
	lhu += 4;
/* SOURCE newlookup.for:150 */
/*<       goto100 >*/
	goto L100;
/* SOURCE newlookup.for:151 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:152 */
/*<   110 continue >*/
L110:
/* SOURCE newlookup.for:153 */
/*<       lhu=lhu-inc >*/
	lhu += -4;
/* SOURCE newlookup.for:154 */
/*<       if(hu.ge.ftab(lhu))goto120 >*/
	if (hu >= ftab[lhu]) {
	    goto L120;
	}
/* SOURCE newlookup.for:155 */
/*<       goto110 >*/
	goto L110;
/* SOURCE newlookup.for:156 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:157 */
/*<   120 continue >*/
L120:
/* SOURCE newlookup.for:158 */
/*<       itab(ip+4)=lhu >*/
    itab[*ip + 4] = lhu;
/*      WRITE(STDOUT,*) ' LHU AFTER SEARCH=',LHU */
/*     FREE FLOW MAY RESULT IF THE DOWNSTREAM HEAD IS */
/*     SMALL ENOUGH */
/*     FIND THE HEAD DROP CORRESPONDING TO HU */
/*     Get the ups heads on left (smaller) and right( larger) of the argument value */
/*     of ups head.  Also get the the drop to free flow and the derivative of the drop */
/*     to free flow wrt to ups head. */
/* SOURCE newlookup.for:170 */
/*<       hul=ftab(lhu) >*/
    hul = ftab[lhu];
/* SOURCE newlookup.for:171 */
/*<       hur=ftab(lhu+inc) >*/
    hur = ftab[lhu + 4];
/* SOURCE newlookup.for:172 */
/*<       hdropl=ftab(lhu+1) >*/
    hdropl = ftab[lhu + 1];
/* SOURCE newlookup.for:173 */
/*<       hdropr=ftab(lhu+inc+1) >*/
    hdropr = ftab[lhu + 5];
/* SOURCE newlookup.for:174 */
/*<       dhdropl=ftab(lhu+2) >*/
    dhdropl = ftab[lhu + 2];
/* SOURCE newlookup.for:175 */
/*<       dhdropr=ftab(lhu+inc+2) >*/
    dhdropr = ftab[lhu + 6];
/*     Now do cubic interpolation for the value of free drop at the argument ups head.  Compute */
/*     the factors that depend only on the relative location in the interval.  We can reuse these */
/*     if the flow is in fact free. */
/* SOURCE newlookup.for:180 */
/*<       h_hu=hur-hul >*/
    feq_gen_h_hu_d_ = static_cast<double>(hur) - hul;
/* SOURCE newlookup.for:181 */
/*<       t_hu=(hu-hul)/h_hu >*/
    feq_gen_t_hu_d_ = static_cast<double>((static_cast<double>(hu) - hul)) / feq_gen_h_hu_d_;
/*     compute factors on left and right derivative. */
/* SOURCE newlookup.for:183 */
/*<       flp_hu=(1.0-t_hu)*t_hu*h_hu >*/
    feq_gen_flp_hu_d_ = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - feq_gen_t_hu_d_)) * feq_gen_t_hu_d_) * feq_gen_h_hu_d_;
/* SOURCE newlookup.for:184 */
/*<       frp_hu=-flp_hu*t_hu >*/
    feq_gen_frp_hu_d_ = static_cast<double>(-feq_gen_flp_hu_d_) * feq_gen_t_hu_d_;
/* SOURCE newlookup.for:185 */
/*<       flp_hu=flp_hu*(1.0-t_hu) >*/
    feq_gen_flp_hu_d_ *= static_cast<double>(static_cast<double>((float)1.) - feq_gen_t_hu_d_);
/*     compute factors on left and right function value */
/* SOURCE newlookup.for:187 */
/*<       fl_hu=2.*t_hu+1.0 >*/
    feq_gen_fl_hu_d_ = static_cast<double>(static_cast<double>(feq_gen_t_hu_d_) * (float)2.) + (float)1.;
/* SOURCE newlookup.for:188 */
/*<       fr_hu=(4.0-fl_hu)*t_hu*t_hu >*/
    feq_gen_fr_hu_d_ = static_cast<double>(static_cast<double>((static_cast<double>((float)4.) - feq_gen_fl_hu_d_)) * feq_gen_t_hu_d_) * feq_gen_t_hu_d_;
/* SOURCE newlookup.for:189 */
/*<       fl_hu=fl_hu*(1.0-t_hu)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>((float)1.) - feq_gen_t_hu_d_;
    feq_gen_fl_hu_d_ *= static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*     compute the factors based on relative interval for computing derivatives. */
/* SOURCE newlookup.for:192 */
/*<       dlp_hu=1.-3.*t_hu >*/
    feq_gen_dlp_hu_d_ = static_cast<double>((float)1.) - static_cast<double>(feq_gen_t_hu_d_) * (float)3.;
/* SOURCE newlookup.for:193 */
/*<       drp_hu=-(1.+dlp_hu)*t_hu >*/
    feq_gen_drp_hu_d_ = static_cast<double>(-(static_cast<double>(feq_gen_dlp_hu_d_) + (float)1.)) * feq_gen_t_hu_d_;
/* SOURCE newlookup.for:194 */
/*<       dlp_hu=dlp_hu*(1.0-t_hu) >*/
    feq_gen_dlp_hu_d_ *= static_cast<double>(static_cast<double>((float)1.) - feq_gen_t_hu_d_);
/* SOURCE newlookup.for:195 */
/*<       dm_hu=6.*(1.0-t_hu)*t_hu/h_hu >*/
    feq_gen_dm_hu_d_ = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - feq_gen_t_hu_d_)) * (float)6.) * feq_gen_t_hu_d_) / feq_gen_h_hu_d_;
/* SOURCE newlookup.for:197 */
/*<       thdrop=flp_hu*dhdropl+frp_hu*dhdropr+fl_hu*hdropl+fr_hu*hdropr >*/
    thdrop = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_flp_hu_d_) * dhdropl) + static_cast<double>(feq_gen_frp_hu_d_) * dhdropr) + static_cast<double>(feq_gen_fl_hu_d_) * hdropl) + 
	    static_cast<double>(feq_gen_fr_hu_d_) * hdropr;
/*      WRITE(STDOUT,*) ' THDROP=',THDROP */
/*     THDROP IS THE TABLE VALUE OF THE HEAD DROP TO FREE FLOW */
/*     FOR THE CURRENT UPSTREAM LEVEL */
/*     HDROP IS THE CURRENT HEAD DROP */
/* SOURCE newlookup.for:206 */
/*<       hdrop=eu-ed >*/
    hdrop = static_cast<double>(eu) - ed;
/* SOURCE newlookup.for:207 */
/*<       if(hdrop.ge.thdrop)then >*/
    if (hdrop >= thdrop) {
/*       Free flow.  Get the values we need: flow on left and right */
/*       and the derivative of flow wrt ups head on left and right. */
/*       These are stored with the submerged values because they form the */
/*       upper condition for submerged flow. */
/* SOURCE newlookup.for:213 */
/*<       it=itab(lhu+3) >*/
	it = itab[lhu + 3];
/* SOURCE newlookup.for:214 */
/*<       ql=ftab(it) >*/
	ql = ftab[it];
/* SOURCE newlookup.for:215 */
/*<       dqldhu=ftab(it+2) >*/
	dqldhu = ftab[it + 2];
/* SOURCE newlookup.for:216 */
/*<       it=itab(lhu+inc+3) >*/
	it = itab[lhu + 7];
/* SOURCE newlookup.for:217 */
/*<       qr=ftab(it) >*/
	qr = ftab[it];
/* SOURCE newlookup.for:218 */
/*<       dqrdhu=ftab(it+2) >*/
	dqrdhu = ftab[it + 2];
/* SOURCE newlookup.for:221 */
/*<       q=flp_hu*dqldhu+frp_hu*dqrdhu+fl_hu*ql+fr_hu*qr >*/
	*q = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_flp_hu_d_) * dqldhu) + static_cast<double>(feq_gen_frp_hu_d_) * dqrdhu) + static_cast<double>(feq_gen_fl_hu_d_) * ql) + static_cast<double>(feq_gen_fr_hu_d_) * 
		qr;
/* SOURCE newlookup.for:223 */
/*<       dqeu=dlp_hu*dqldhu+drp_hu*dqrdhu+dm_hu*(qr-ql) >*/
	*dqeu = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_dlp_hu_d_) * dqldhu) + static_cast<double>(feq_gen_drp_hu_d_) * dqrdhu) + static_cast<double>(feq_gen_dm_hu_d_) * (static_cast<double>(qr) - ql);
/* SOURCE newlookup.for:226 */
/*<       dqed=0.0 >*/
	*dqed = (float)0.;
/* SOURCE newlookup.for:227 */
/*<       free=1 >*/
	*free = 1;
/* SOURCE newlookup.for:229 */
/*<       goto9000 >*/
	goto L9000;
/* SOURCE newlookup.for:230 */
/*<       endif >*/
    }
/*     SUBMERGED FLOW HERE */
/*     FIND THE FRACTION OF FREE-FLOW DROP REPRESENTED BY THE CURRENT DROP */
/* SOURCE newlookup.for:237 */
/*<       p=hdrop/thdrop >*/
    p = static_cast<double>(hdrop) / thdrop;
/*      WRITE(STDOUT,*) ' P=',P */
/*     Outline of approach and variables: */
/*     1. we interpolate wrt to pfd (partial free drop) first. */
/*     2  Then interpolate wrt to ups head. */
/*     For each upstream head we have in sequence all of the values for that head. */
/*     The upstream head that is just less than the argument value will be denoted */
/*     by L for left.  The upstream head that is just greater than the argument value */
/*     will be denoted by R for right.  Note that equality is accepted at either end as well. */
/*     In the sequence of partial free drops we will have one that is just below the */
/*     argument value.  We denote that by D.  We also have one that just above the */
/*     argument value of pfd.  We denote that by U.  Now we need not distinguish left and */
/*     right for the pfd because they are the same.   The pattern looks like this: */
/*                          Value of argument upstream head */
/*                          | */
/*          huL             hu       huR */
/*        --------------    --     --------------- */
/*           .              |         . */
/*           .              |         .            Zero or more sets of 4 */
/*           .              |         . */
/*   pfdD    QLD            |        QRD */
/*           PQPpfdLD       |        PQPpfdRD      partial Q wrt to pfd */
/*           PQPhuLD        |        PQPhuRD       partial Q wrt to hu */
/*           PPQPpfdPhuLD   |        PPQPpfdPhuRD  partial partial Q wrt to pfd (2nd) and hu (1st) */
/*    P -------------------------------------------  value of argument pfd */
/*   pfdU    QLU            |        QRU */
/*           PQPpfdLU       |        PQPpfdRU */
/*           PQPhuLU        |        PQPhuRU */
/*           PPQPpfdPhuLU   |        PPQPpfdPhuRU */
/*           .              |         . */
/*           .              |         .            Zero or more sets of 4 */
/*           .              |         . */
/*     Beware:  Fortran does not distinguish upper and lower case in names!!!!! */
/*              I may use upper and lower case to more clearly recognize the role of the name. */
/*              However, this is a two-edged sword-the role may appear proper but may not be!! */
/*              There is no easy way to make sure programs work! */
/*     SEARCH IN THE PARTIAL FREE DROP LIST.  Get the value where we last found */
/*     the interval. */
/* SOURCE newlookup.for:284 */
/*<       lp=itab(ip+6) >*/
    lp = itab[*ip + 6];
/* SOURCE newlookup.for:285 */
/*<       if(p.ge.ftab(lp))then >*/
    if (p >= ftab[lp]) {
/* SOURCE newlookup.for:286 */
/*<   130 continue >*/
L130:
/* SOURCE newlookup.for:287 */
/*<       if(p.le.ftab(lp+1))goto150 >*/
	if (p <= ftab[lp + 1]) {
	    goto L150;
	}
/* SOURCE newlookup.for:288 */
/*<       lp=lp+1 >*/
	++lp;
/* SOURCE newlookup.for:289 */
/*<       goto130 >*/
	goto L130;
/* SOURCE newlookup.for:290 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:291 */
/*<   140 continue >*/
L140:
/* SOURCE newlookup.for:292 */
/*<       lp=lp-1 >*/
	--lp;
/* SOURCE newlookup.for:293 */
/*<       if(p.ge.ftab(lp))goto150 >*/
	if (p >= ftab[lp]) {
	    goto L150;
	}
/* SOURCE newlookup.for:294 */
/*<       goto140 >*/
	goto L140;
/* SOURCE newlookup.for:295 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:296 */
/*<   150 continue >*/
L150:
/* SOURCE newlookup.for:297 */
/*<       itab(ip+6)=lp >*/
    itab[*ip + 6] = lp;
/*      WRITE(STDOUT,*) ' LP=',LP */
/*     get the pointers to the free flows for the bounding upstream heads. */
/* SOURCE newlookup.for:301 */
/*<       itl=itab(lhu+3) >*/
    itl = itab[lhu + 3];
/* SOURCE newlookup.for:302 */
/*<       itr=itab(lhu+inc+3) >*/
    itr = itab[lhu + 7];
/*     Find the pointer for each flow at the partial free drop */
/*     below P (smaller than P).  4*(lp - ppfd) gives the distance from */
/*     the flow at zero pfd to the flow at the pfd just smaller than P. */
/*     qoffset is the distance from free flow to zero flow (flow at zero */
/*     partial free drop). INC is 4 and is a parameter already in the code. */
/* SOURCE newlookup.for:310 */
/*<       it=inc*(lp-ppfd)-qoffset >*/
    it = (lp - ppfd << 2) - qoffset;
/* SOURCE newlookup.for:311 */
/*<       itl=itl+it >*/
    itl += it;
/* SOURCE newlookup.for:312 */
/*<       itr=itr+it >*/
    itr += it;
/*     At this point itl points to QLD and itr points to QRD in the pattern */
/*     given above. */
/*     Set the values of pfdD and pfdU */
/* SOURCE newlookup.for:319 */
/*<       pfdd=ftab(lp) >*/
    pfdd = ftab[lp];
/* SOURCE newlookup.for:320 */
/*<       pfdu=ftab(lp+1) >*/
    pfdu = ftab[lp + 1];
/*     Get the values in the pattern above.  All will be needed plus a whole */
/*     lot more! */
/* SOURCE newlookup.for:325 */
/*<       qld=ftab(itl) >*/
    qld = ftab[itl];
/* SOURCE newlookup.for:326 */
/*<       pqppfdld=ftab(itl+1) >*/
    pqppfdld = ftab[itl + 1];
/* SOURCE newlookup.for:327 */
/*<       pqphuld=ftab(itl+2) >*/
    pqphuld = ftab[itl + 2];
/* SOURCE newlookup.for:328 */
/*<       ppqppfdphuld=ftab(itl+3) >*/
    ppqppfdphuld = ftab[itl + 3];
/* SOURCE newlookup.for:330 */
/*<       qlu=ftab(itl+4) >*/
    qlu = ftab[itl + 4];
/* SOURCE newlookup.for:331 */
/*<       pqppfdlu=ftab(itl+5) >*/
    pqppfdlu = ftab[itl + 5];
/* SOURCE newlookup.for:332 */
/*<       pqphulu=ftab(itl+6) >*/
    pqphulu = ftab[itl + 6];
/* SOURCE newlookup.for:333 */
/*<       ppqppfdphulu=ftab(itl+7) >*/
    ppqppfdphulu = ftab[itl + 7];
/* SOURCE newlookup.for:335 */
/*<       qrd=ftab(itr) >*/
    qrd = ftab[itr];
/* SOURCE newlookup.for:336 */
/*<       pqppfdrd=ftab(itr+1) >*/
    pqppfdrd = ftab[itr + 1];
/* SOURCE newlookup.for:337 */
/*<       pqphurd=ftab(itr+2) >*/
    pqphurd = ftab[itr + 2];
/* SOURCE newlookup.for:338 */
/*<       ppqppfdphurd=ftab(itr+3) >*/
    ppqppfdphurd = ftab[itr + 3];
/* SOURCE newlookup.for:340 */
/*<       qru=ftab(itr+4) >*/
    qru = ftab[itr + 4];
/* SOURCE newlookup.for:341 */
/*<       pqppfdru=ftab(itr+5) >*/
    pqppfdru = ftab[itr + 5];
/* SOURCE newlookup.for:342 */
/*<       pqphuru=ftab(itr+6) >*/
    pqphuru = ftab[itr + 6];
/* SOURCE newlookup.for:343 */
/*<       ppqppfdphuru=ftab(itr+7) >*/
    ppqppfdphuru = ftab[itr + 7];
/*     now compute the coefficients that depend only on the local interval and the interpolation */
/*     point.   These apply to both the left and right sequences since the partial free-drop interval */
/*     is the same and so is P */
/* SOURCE newlookup.for:350 */
/*<       h=pfdu-pfdd >*/
    feq_gen_h_d_ = static_cast<double>(pfdu) - pfdd;
/* SOURCE newlookup.for:351 */
/*<       t=(p-pfdd)/h >*/
    t = static_cast<double>((static_cast<double>(p) - pfdd)) / feq_gen_h_d_;
/*     compute factors on left and right derivative. */
/* SOURCE newlookup.for:353 */
/*<       flp=(1.0-t)*t*h >*/
    flp = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - t)) * t) * feq_gen_h_d_;
/* SOURCE newlookup.for:354 */
/*<       frp=-flp*t >*/
    frp = static_cast<double>(-flp) * t;
/* SOURCE newlookup.for:355 */
/*<       flp=flp*(1.0-t) >*/
    flp *= static_cast<double>(static_cast<double>((float)1.) - t);
/*     compute factors on left and right function value */
/* SOURCE newlookup.for:357 */
/*<       fl=2.*t+1.0 >*/
    fl = static_cast<double>(static_cast<double>(t) * (float)2.) + (float)1.;
/* SOURCE newlookup.for:358 */
/*<       fr=(4.0-fl)*t*t >*/
    fr = static_cast<double>(static_cast<double>((static_cast<double>((float)4.) - fl)) * t) * t;
/* SOURCE newlookup.for:359 */
/*<       fl=fl*(1.0-t)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>((float)1.) - t;
    fl *= static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*     compute the factors based on relative interval for computing derivatives. */
/* SOURCE newlookup.for:361 */
/*<       dlp=1.-3.*t >*/
    dlp = static_cast<double>((float)1.) - static_cast<double>(t) * (float)3.;
/* SOURCE newlookup.for:362 */
/*<       drp=-(1.+dlp)*t >*/
    drp = static_cast<double>(-(static_cast<double>(dlp) + (float)1.)) * t;
/* SOURCE newlookup.for:363 */
/*<       dlp=dlp*(1.0-t) >*/
    dlp *= static_cast<double>(static_cast<double>((float)1.) - t);
/* SOURCE newlookup.for:364 */
/*<       dm=6.*(1.0-t)*t/h >*/
    dm = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - t)) * (float)6.) * t) / feq_gen_h_d_;
/*     We need four values at P on huL and four values at P on huR to be able */
/*     to compute both the function and its two derivatives at P and hu: */
/*      1. Q ---------------------------------->  QL           QR */
/*      2. partial Q wrt to pfd --------------->  PQPpfdL      PQPpfdR */
/*      3. partial Q wrt to hu ---------------->  PQPhuL       PQPhuR */
/*      4. partial partial Q wrt to pfd and hu->  PPQPpfdPhuL  PPQPpfdPhuR */
/* SOURCE newlookup.for:373 */
/*<       ql=fl*qld+fr*qlu+flp*pqppfdld+frp*pqppfdlu >*/
    ql = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(fl) * qld) + static_cast<double>(fr) * qlu) + static_cast<double>(flp) * pqppfdld) + static_cast<double>(frp) * pqppfdlu;
/* SOURCE newlookup.for:374 */
/*<       pqppfdl=dlp*pqppfdld+drp*pqppfdlu+dm*(qlu-qld) >*/
    pqppfdl = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * pqppfdld) + static_cast<double>(drp) * pqppfdlu) + static_cast<double>(dm) * (static_cast<double>(qlu) - qld);
/* SOURCE newlookup.for:376 */
/*<       pqphul=fl*pqphuld+fr*pqphulu+flp*ppqppfdphuld+frp*ppqppfdphulu >*/
    pqphul = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(fl) * pqphuld) + static_cast<double>(fr) * pqphulu) + static_cast<double>(flp) * ppqppfdphuld) + static_cast<double>(frp) * 
	    ppqppfdphulu;
/* SOURCE newlookup.for:378 */
/*<       ppqppfdphul=dlp*ppqppfdphuld+drp*ppqppfdphulu+dm*(pqphulu-pqphuld) >*/
    ppqppfdphul = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * ppqppfdphuld) + static_cast<double>(drp) * ppqppfdphulu) + static_cast<double>(dm) * (static_cast<double>(pqphulu) - 
	    pqphuld);
/* SOURCE newlookup.for:382 */
/*<       qr=fl*qrd+fr*qru+flp*pqppfdrd+frp*pqppfdru >*/
    qr = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(fl) * qrd) + static_cast<double>(fr) * qru) + static_cast<double>(flp) * pqppfdrd) + static_cast<double>(frp) * pqppfdru;
/* SOURCE newlookup.for:383 */
/*<       pqppfdr=dlp*pqppfdrd+drp*pqppfdru+dm*(qru-qrd) >*/
    pqppfdr = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * pqppfdrd) + static_cast<double>(drp) * pqppfdru) + static_cast<double>(dm) * (static_cast<double>(qru) - qrd);
/* SOURCE newlookup.for:385 */
/*<       pqphur=fl*pqphurd+fr*pqphuru+flp*ppqppfdphurd+frp*ppqppfdphuru >*/
    pqphur = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(fl) * pqphurd) + static_cast<double>(fr) * pqphuru) + static_cast<double>(flp) * ppqppfdphurd) + static_cast<double>(frp) * 
	    ppqppfdphuru;
/* SOURCE newlookup.for:387 */
/*<       ppqppfdphur=dlp*ppqppfdphurd+drp*ppqppfdphuru+dm*(pqphuru-pqphurd) >*/
    ppqppfdphur = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * ppqppfdphurd) + static_cast<double>(drp) * ppqppfdphuru) + static_cast<double>(dm) * (static_cast<double>(pqphuru) - 
	    pqphurd);
/*     We now interpolate on upstream head for the values at p and hu. */
/* SOURCE newlookup.for:393 */
/*<       q=fl_hu*ql+fr_hu*qr+flp_hu*pqphul+frp_hu*pqphur >*/
    *q = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_fl_hu_d_) * ql) + static_cast<double>(feq_gen_fr_hu_d_) * qr) + static_cast<double>(feq_gen_flp_hu_d_) * pqphul) + static_cast<double>(feq_gen_frp_hu_d_) * pqphur;
/*     Note that PQPhu is with pfd held fixed.  To get the */
/*     derivative of flow with respect to hu,  with the hd held */
/*     fixed, we must also include the variation of pfd with hu. */
/*     A somewhat subtle point that I missed on the first pass! */
/* SOURCE newlookup.for:401 */
/*<       pqphu=dlp_hu*pqphul+drp_hu*pqphur+dm_hu*(qr-ql) >*/
    pqphu = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_dlp_hu_d_) * pqphul) + static_cast<double>(feq_gen_drp_hu_d_) * pqphur) + static_cast<double>(feq_gen_dm_hu_d_) * (static_cast<double>(qr) - ql);
/*     compute the derivative of free drop wrt to ups head. */
/* SOURCE newlookup.for:404 */
/*<       dthdropdhu=dlp_hu*dhdropl+drp_hu*dhdropr+dm_hu*(hdropr-hdropl) >*/
    dthdropdhu = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_dlp_hu_d_) * dhdropl) + static_cast<double>(feq_gen_drp_hu_d_) * dhdropr) + static_cast<double>(feq_gen_dm_hu_d_) * (static_cast<double>(hdropr) 
	    - hdropl);
/* SOURCE newlookup.for:408 */
/*<        >*/
    pqppfd = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_fl_hu_d_) * pqppfdl) + static_cast<double>(feq_gen_fr_hu_d_) * pqppfdr) + static_cast<double>(feq_gen_flp_hu_d_) * ppqppfdphul) + 
	    static_cast<double>(feq_gen_frp_hu_d_) * ppqppfdphur;
/* SOURCE newlookup.for:410 */
/*<       dqed=-pqppfd/thdrop >*/
    *dqed = static_cast<double>(-pqppfd) / thdrop;
/*     Now we can compute DQEU, that is, the partial of Q wrt hu when */
/*     hd is held constant. */
/* SOURCE newlookup.for:415 */
/*<       dqeu=pqphu+pqppfd*(1.-p*dthdropdhu)/thdrop >*/
    *dqeu = static_cast<double>(pqphu) + static_cast<double>(static_cast<double>(pqppfd) * (static_cast<double>((float)1.) - static_cast<double>(p) * dthdropdhu)) / thdrop;
/* SOURCE newlookup.for:416 */
/*<       free=0 >*/
    *free = 0;
/* SOURCE newlookup.for:418 */
/*<  9000 continue >*/
L9000:
/* SOURCE newlookup.for:421 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:423 */
/*<       end >*/
} /* tdlk43_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE newlookup.for:428 */
/*<        >*/
/* Subroutine */ int store43_(integer *stdout, integer *table, char *source, 
	integer *maxrow, integer *nhu, integer *npfd, doublereal *feq_storage_huall, 
	doublereal *feq_storage_freedrop, doublereal *feq_storage_pfdropphu, doublereal *feq_storage_pfd, 
	doublereal *feq_storage_qmat, doublereal *feq_storage_pqppfd, doublereal *feq_storage_pqphu, doublereal *
	feq_storage_ppqppfdphu, integer *ftp, real *hdatum, integer *ftpup, ftnlen 
	source_len)
{
    /* System generated locals */
    integer pqppfd_dim1, pqppfd_offset, pqphu_dim1, pqphu_offset, 
	    ppqppfdphu_dim1, ppqppfdphu_offset, qmat_dim1, qmat_offset, feq_gen_i_d_1, 
	    feq_gen_i_d_2;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, ip, it;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer pfq, phu;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ppfd;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer eflag, qoffset;

/*     Store table of type = 43- bicubic pp Hermite at a minimum yielding */
/*     values of flow and its first derivative wrt to both ups and dns head */
/*     that are continuous.  In most cases the the second derivatives will */
/*     also be continuous because the tables are created by fitting, in so */
/*     far as possible, cubic splines.  However, we apply variation limitation */
/*     to these splines to avoid the wild nonesense that sometimes occurs */
/*     in non-linear interpolation.  However, in testing and checking */
/*     so far, the points with changes to derivative to enforce monotone */
/*     variation between tabulated points, often represent fewer than */
/*     1 per cent of the total. */
/* SOURCE newlookup.for:444 */
/*<       implicitnone >*/
/* SOURCE newlookup.for:445 */
/*<       integernhu,npfd,maxrow,stdout,ftp,ftpup,table >*/
/* SOURCE newlookup.for:446 */
/*<       realhdatum >*/
/* SOURCE newlookup.for:447 */
/*<        >*/
/* SOURCE newlookup.for:451 */
/*<       character*8source >*/
/* INCLUDE newlookup.for:454 */
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
/* INCLUDE newlookup.for:455 */
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
/* SOURCE newlookup.for:459 */
/*<       integeri,j,ip,phu,ppfd,qoffset,it,pfq,eflag >*/
/* *********************************************************************** */
/* SOURCE newlookup.for:462 */
/*<       ip=ftp >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> pfdropphu(feq_storage_pfdropphu, 1);

    feq::IndexedPointer<doublereal> freedrop(feq_storage_freedrop, 1);

    feq::IndexedPointer<doublereal> huall(feq_storage_huall, 1);
    ppqppfdphu_dim1 = *maxrow;
    ppqppfdphu_offset = 1 + ppqppfdphu_dim1;

    feq::IndexedPointer<doublereal> ppqppfdphu(feq_storage_ppqppfdphu, ppqppfdphu_offset);
    pqphu_dim1 = *maxrow;
    pqphu_offset = 1 + pqphu_dim1;

    feq::IndexedPointer<doublereal> pqphu(feq_storage_pqphu, pqphu_offset);
    pqppfd_dim1 = *maxrow;
    pqppfd_offset = 1 + pqppfd_dim1;

    feq::IndexedPointer<doublereal> pqppfd(feq_storage_pqppfd, pqppfd_offset);
    qmat_dim1 = *maxrow;
    qmat_offset = 1 + qmat_dim1;

    feq::IndexedPointer<doublereal> qmat(feq_storage_qmat, qmat_offset);

    feq::IndexedPointer<doublereal> pfd(feq_storage_pfd, 1);

    /* Function Body */
    ip = *ftp;
/*     Check for room for storage. */
/* SOURCE newlookup.for:464 */
/*<       eflag=0 >*/
    eflag = 0;
/* SOURCE newlookup.for:465 */
/*<       if(ip+tdtioff+4*nhu*(1+npfd)+npfd.gt.mrftab)then >*/
    if (ip + 26 + (*nhu << 2) * (*npfd + 1) + *npfd > 13000001) {
/* SOURCE newlookup.for:466 */
/*<       callkil(10,ftp,eflag) >*/
	kil_(&feq_gen_c_d_10, ftp, &eflag);
/* SOURCE newlookup.for:469 */
/*<       stop'Abnormal stop. Out of function-table space!' >*/
	s_stop(const_cast<char*>("Abnormal stop. Out of function-table space!"), (ftnlen)43);
/* SOURCE newlookup.for:470 */
/*<       endif >*/
    }
/*      write(stdout,*) ' store43: ftp=',ftp,' on entry.' */
/*     Set head datum */
/* SOURCE newlookup.for:474 */
/*<       ftab(ip)=hdatum >*/
    ftab[ip] = *hdatum;
/*     Set table number as a dummy for now */
/* SOURCE newlookup.for:477 */
/*<       itab(ip+1)=table >*/
    itab[ip + 1] = *table;
/* SOURCE newlookup.for:478 */
/*<       itab(ip+2)=43 >*/
    itab[ip + 2] = 43;
/*     pointer to first upstream head */
/* SOURCE newlookup.for:481 */
/*<       phu=ip+tdtioff >*/
    phu = ip + 26;
/* SOURCE newlookup.for:482 */
/*<       itab(ip+3)=phu >*/
    itab[ip + 3] = phu;
/* SOURCE newlookup.for:483 */
/*<       itab(ip+4)=phu >*/
    itab[ip + 4] = phu;
/*     We store 4 items for each upstream head. */
/* SOURCE newlookup.for:487 */
/*<       ppfd=phu+4*nhu >*/
    ppfd = phu + (*nhu << 2);
/* SOURCE newlookup.for:488 */
/*<       itab(ip+5)=ppfd >*/
    itab[ip + 5] = ppfd;
/* SOURCE newlookup.for:489 */
/*<       itab(ip+6)=ppfd >*/
    itab[ip + 6] = ppfd;
/*     compute the offset between the flow at pfd=0 and pfd=1 for each */
/*     ups head. */
/* SOURCE newlookup.for:493 */
/*<       qoffset=4*(npfd-1) >*/
    qoffset = *npfd - 1 << 2;
/* SOURCE newlookup.for:494 */
/*<       itab(ip+10)=qoffset >*/
    itab[ip + 10] = qoffset;
/*     set the maximum upstream head */
/* SOURCE newlookup.for:497 */
/*<       ftab(ip+9)=sngl(huall(nhu)) >*/
    ftab[ip + 9] = (real) huall[*nhu];
/*     store the information for upstream heads */
/* SOURCE newlookup.for:500 */
/*<       it=phu >*/
    it = phu;
/* SOURCE newlookup.for:501 */
/*<       ppfd=phu+4*nhu >*/
    ppfd = phu + (*nhu << 2);
/* SOURCE newlookup.for:502 */
/*<       pfq=ppfd+npfd+qoffset >*/
    pfq = ppfd + *npfd + qoffset;
/* SOURCE newlookup.for:503 */
/*<       doi=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:504 */
/*<       ftab(it)=sngl(huall(i)) >*/
	ftab[it] = (real) huall[feq_gen_i_d_];
/* SOURCE newlookup.for:505 */
/*<       ftab(it+1)=sngl(freedrop(i)) >*/
	ftab[it + 1] = (real) freedrop[feq_gen_i_d_];
/* SOURCE newlookup.for:506 */
/*<       ftab(it+2)=sngl(pfdropphu(i)) >*/
	ftab[it + 2] = (real) pfdropphu[feq_gen_i_d_];
/* SOURCE newlookup.for:507 */
/*<       itab(it+3)=pfq >*/
	itab[it + 3] = pfq;
/* SOURCE newlookup.for:508 */
/*<       it=it+4 >*/
	it += 4;
/*       update to zero flow for the next head */
/* SOURCE newlookup.for:510 */
/*<       pfq=pfq+4 >*/
	pfq += 4;
/*       point to free flow for the next head */
/* SOURCE newlookup.for:512 */
/*<       pfq=pfq+qoffset >*/
	pfq += qoffset;
/* SOURCE newlookup.for:513 */
/*<       enddo >*/
    }
/*     store the partial free drops */
/* SOURCE newlookup.for:517 */
/*<       it=ppfd >*/
    it = ppfd;
/* SOURCE newlookup.for:518 */
/*<       doi=1,npfd >*/
    feq_gen_i_d_1 = *npfd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:519 */
/*<       ftab(it)=pfd(i) >*/
	ftab[it] = pfd[feq_gen_i_d_];
/* SOURCE newlookup.for:520 */
/*<       it=it+1 >*/
	++it;
/* SOURCE newlookup.for:521 */
/*<       enddo >*/
    }
/*     store the flow and derivatives */
/* SOURCE newlookup.for:525 */
/*<       doi=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:526 */
/*<       doj=1,npfd >*/
	feq_gen_i_d_2 = *npfd;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE newlookup.for:527 */
/*<       ftab(it)=qmat(i,j) >*/
	    ftab[it] = qmat[feq_gen_i_d_ + j * qmat_dim1];
/* SOURCE newlookup.for:528 */
/*<       ftab(it+1)=pqppfd(i,j) >*/
	    ftab[it + 1] = pqppfd[feq_gen_i_d_ + j * pqppfd_dim1];
/* SOURCE newlookup.for:529 */
/*<       ftab(it+2)=pqphu(i,j) >*/
	    ftab[it + 2] = pqphu[feq_gen_i_d_ + j * pqphu_dim1];
/* SOURCE newlookup.for:530 */
/*<       ftab(it+3)=ppqppfdphu(i,j) >*/
	    ftab[it + 3] = ppqppfdphu[feq_gen_i_d_ + j * ppqppfdphu_dim1];
/* SOURCE newlookup.for:531 */
/*<       it=it+4 >*/
	    it += 4;
/* SOURCE newlookup.for:532 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:533 */
/*<       enddo >*/
    }
/*     Set the pointer to the next open location in the ftable system */
/* SOURCE newlookup.for:536 */
/*<       ftpup=it-4 >*/
    *ftpup = it - 4;
/* SOURCE newlookup.for:539 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:540 */
/*<       end >*/
} /* store43_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE newlookup.for:544 */
/*<        >*/
/* Subroutine */ int feq_gen_convert_to_43_d_(integer *stdout, integer *mlft, integer *
	table, integer *ip, real *hdatum, integer *verbose, integer *ftp, 
	integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    doublereal freedrop[152];
    integer it;
    extern /* Subroutine */ int twodtabfit_(integer *, integer *, integer *, 
	    integer *, integer *, real *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, integer *, integer *, integer 
	    *, integer *, ftnlen);
    doublereal pfd[351];
    integer ihu, nhu, phu;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ipfd, npfd, ppfd;
    doublereal qmat[53352]	/* was [152][351] */;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    doublereal huall[152];
    integer ftpup, maxrow;
    char source[8];

/*     Convert a type 13 table to type 43.  tabadr points to the type 13 */
/*     table.  The table has just been added to ftab/itab.  We will extract */
/*     values from the table into local arrays, and then compute the type 43 */
/*     data.  This will then be stored in ftab/itab at the same address. */
/*     We must return the updated ftp. */
/* SOURCE newlookup.for:554 */
/*<       implicitnone >*/
/* SOURCE newlookup.for:556 */
/*<       integerstdout,mlft,table,ip,ftp,eflag,verbose >*/
/* SOURCE newlookup.for:557 */
/*<       realhdatum >*/
/* INCLUDE newlookup.for:559 */
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
/* INCLUDE newlookup.for:560 */
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
/* SOURCE newlookup.for:564 */
/*<       integerihu,ipfd,it,nhu,npfd,maxrow,phu,ppfd,ftpup >*/
/* SOURCE newlookup.for:565 */
/*<        >*/
/* SOURCE newlookup.for:570 */
/*<       character*8source >*/
/* *********************************************************************** */
/*     Compute the maxrow value for array passing */
/* SOURCE newlookup.for:573 */
/*<       maxrow=pmxnhu+1 >*/
    maxrow = 152;
/*     Extract various values to compute the number of ups heads */
/*     and the number of partial free drops.  The type 13 storage pattern */
/*     includes the zero head and zero partial free drop even though */
/*     the input table format does not! */
/*     Get pointer to the first upstream head */
/* SOURCE newlookup.for:581 */
/*<       phu=itab(ip+3) >*/
    phu = itab[*ip + 3];
/*     Get the pointer to the start of the partial free drop list. */
/*     This list follows after the info for the upstream heads is given */
/* SOURCE newlookup.for:585 */
/*<       ppfd=itab(ip+5) >*/
    ppfd = itab[*ip + 5];
/*     The relationship is: ppfd = phu + 4*nhu.  Therefore we can compute */
/*     nhu from these two values */
/* SOURCE newlookup.for:589 */
/*<       nhu=(ppfd-phu)/4 >*/
    nhu = (ppfd - phu) / 4;
/*     the pattern for upstream heads is: */
/*       phu+0    hu */
/*          +1    freedrop */
/*          +2    free flow */
/*          +3    offset from ppfd to the start of the list of flows for this */
/*                ups head for each partial free drop from 0 to 1.0. */
/*       Thus the difference between two consecutive  entries for the offset */
/*       should be the number of partial free drops! */
/* SOURCE newlookup.for:601 */
/*<       npfd=itab(phu+7)-itab(phu+3) >*/
    npfd = itab[phu + 7] - itab[phu + 3];
/*      write(stdout,*) 'convert_to_43: nhu=',nhu,' npfd=',npfd */
/*     now extract the upstream heads and the free drop. */
/* SOURCE newlookup.for:606 */
/*<       it=phu >*/
    it = phu;
/* SOURCE newlookup.for:607 */
/*<       doihu=1,nhu >*/
    feq_gen_i_d_1 = nhu;
    for (ihu = 1; ihu <= feq_gen_i_d_1; ++ihu) {
/* SOURCE newlookup.for:608 */
/*<       huall(ihu)=ftab(it) >*/
	huall[ihu - 1] = ftab[it];
/* SOURCE newlookup.for:609 */
/*<       freedrop(ihu)=ftab(it+1) >*/
	freedrop[ihu - 1] = ftab[it + 1];
/* SOURCE newlookup.for:610 */
/*<       it=it+4 >*/
	it += 4;
/* SOURCE newlookup.for:611 */
/*<       enddo >*/
    }
/*     extract the sequence of partial free drops next */
/* SOURCE newlookup.for:614 */
/*<       it=ppfd >*/
    it = ppfd;
/* SOURCE newlookup.for:615 */
/*<       doipfd=1,npfd >*/
    feq_gen_i_d_1 = npfd;
    for (ipfd = 1; ipfd <= feq_gen_i_d_1; ++ipfd) {
/* SOURCE newlookup.for:616 */
/*<       pfd(ipfd)=ftab(it) >*/
	pfd[ipfd - 1] = ftab[it];
/* SOURCE newlookup.for:617 */
/*<       it=it+1 >*/
	++it;
/* SOURCE newlookup.for:618 */
/*<       enddo >*/
    }
/*     extract the flows.  Get pointer to the first flow for the first */
/*     upstream head and the first partial free drop. */
/* SOURCE newlookup.for:622 */
/*<       it=ppfd+npfd >*/
    it = ppfd + npfd;
/* SOURCE newlookup.for:623 */
/*<       doihu=1,nhu >*/
    feq_gen_i_d_1 = nhu;
    for (ihu = 1; ihu <= feq_gen_i_d_1; ++ihu) {
/* SOURCE newlookup.for:624 */
/*<       doipfd=1,npfd >*/
	feq_gen_i_d_2 = npfd;
	for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
/* SOURCE newlookup.for:625 */
/*<       qmat(ihu,ipfd)=ftab(it) >*/
	    qmat[ihu + ipfd * 152 - 153] = ftab[it];
/* SOURCE newlookup.for:626 */
/*<       it=it+1 >*/
	    ++it;
/* SOURCE newlookup.for:627 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:628 */
/*<       enddo >*/
    }
/*      write(stdout,*) ' ' */
/*      write(stdout,*) ' Dump of qmat. Each row for an ups head!' */

/*      do ihu=1,nhu */
/*        write(stdout,50) huall(ihu),(qmat(ihu,ipfd), ipfd=1,npfd) */
/* 50    format(f10.4,25(1pe12.5)) */
/*      end do */
/*     Call the fitting routine, which also stores the table and does */
/*     some test lookups.  ip should be the address of the type 13 table */
/*     being replaced.  ftpup is the new value of ftp that should be */
/*     returned to the point of call.  source for now is passed but not used. */
/*     hdatum is used. */
/* SOURCE newlookup.for:644 */
/*<        >*/
    twodtabfit_(stdout, table, &nhu, &npfd, &maxrow, hdatum, huall, freedrop, 
	    pfd, qmat, source, verbose, ip, eflag, &ftpup, (ftnlen)8);
/* SOURCE newlookup.for:652 */
/*<       ftp=ftpup >*/
    *ftp = ftpup;
/* SOURCE newlookup.for:653 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:654 */
/*<       end >*/
} /* convert_to_43__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE newlookup.for:658 */
/*<        >*/
/* Subroutine */ int feq_gen_twodtabfit_storage_d_(integer *stdout, integer *table, 
	integer *nhu, integer *npfd, integer *maxrow, real *hdatum, 
	doublereal *feq_storage_huall, doublereal *feq_storage_freedrop, doublereal *feq_storage_pfd, doublereal *
	feq_storage_qmat, char *source, integer *verbose, integer *ftp, integer *eflag, 
	integer *ftpup, doublereal *feq_storage_pqppfd, doublereal *feq_storage_pqphu, doublereal *
	feq_storage_ppqppfdphu, doublereal *feq_storage_ppqphuppfd, doublereal *feq_storage_pfdropphu, char *
	feq_storage_pqppfdadj, char *feq_storage_pqphuadj, ftnlen source_len, ftnlen pqppfdadj_len, 
	ftnlen pqphuadj_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002Dump of results--------------------------\
---pfd values\002,\002------------------------------------------------------\
-----\002,/,\002hu/   Q-->\002,31f10.6)";
    static char fmt_52[] = "(f10.3,31(1pe10.4e1))";
    static char fmt_54[] = "(\002pQ/ppfd   \002,30(1pe9.3e1,a1))";
    static char fmt_56[] = "(\002pQ/phu    \002,30(1pe9.3e1,a1))";
    static char fmt_60[] = "(\002ppQ/ppfdph\002,30(1pe10.4e1))";
    static char fmt_62[] = "(\002ppQ/phppfd\002,30(1pe10.4e1))";
    static char fmt_72[] = "(5x,\002 There were\002,i5,\002 derivatives adju\
sted\002,\002 representing \002,f7.1,\002 per cent of the total.\002)";
    static char fmt_73[] = "(5x,\002 There were\002,i5,\002 derivatives adju\
sted for\002,\002 pQ/ppfd and \002,i5,\002 for pQ/phu.\002)";
    static char fmt_74[] = "(/,\002Type 43 Error Summary\002,/,\002    Item \
  MaxRerr        hu        hd        Q \002,\002pQ/phu|pfd   pQ/ppfd      Fr\
ee        Qt   pQt/peu   pQt/ped\002)";
    static char fmt_75[] = "(\002       Q\002,f10.6,f10.3,f10.3,1pe10.3e1,1p\
e10.3e1,1pe10.3e1,0pf10.1,1pe10.3e1,1pe10.3e1,1pe10.3e1)";
    static char fmt_76[] = "(\002  dQ/deu\002,f10.6,f10.3,f10.3,1pe10.3e1,1p\
e10.3e1,1pe10.3e1,0pf10.1,1pe10.3e1,1pe10.3e1,1pe10.3e1)";
    static char fmt_77[] = "(\002  dQ/ded\002,f10.6,f10.3,f10.3,1pe10.3e1,1p\
e10.3e1,1pe10.3e1,0pf10.1,1pe10.3e1,1pe10.3e1,1pe10.3e1)";
    static char fmt_78[] = "(\002 Two-D table of type 43 is a bi-cubic spl\
ine\002)";
    static char fmt_79[] = "(\002 Two-D table of type 43 is a bi-cubic Hermi\
te\002,\002 piecewise polynomial\002)";
    static char fmt_82[] = "(/,\002Warning: deriv discon:\002,/,\002eu=\002,\
f14.8,\002 eut=\002,f14.8,\002 ed=\002,f12.7,\002 dqtedl=\002,1pe12.5,\002 d\
qtedr=\002,1pe12.5,\002 dqteul=\002,1pe12.5,\002 dqteur=\002,1pe12.5,\002 pd\
fm=\002,1pe12.5)";

    /* System generated locals */
    integer qmat_dim1, qmat_offset, pqppfd_dim1, pqppfd_offset, pqphu_dim1, 
	    pqphu_offset, ppqppfdphu_dim1, ppqppfdphu_offset, ppqphuppfd_dim1,
	     ppqphuppfd_offset, pqppfdadj_dim1, pqppfdadj_offset, 
	    pqphuadj_dim1, pqphuadj_offset, feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2, feq_gen_d_d_3, feq_gen_d_d_4, feq_gen_d_d_5;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(),
	     do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer feq_gen_nadj_phu_d_, splineok;
    doublereal f[151];
    integer feq_gen_i_d_;
    doublereal m[151];
    integer feq_gen_nadj_ppfd_d_;
    real dqteddiff, dqteudiff, ed, eu, qt, feq_gen_dqted_diff_d_[10];
    integer feq_gen_nadj_mixed_d_;
    real feq_gen_dqteu_diff_d_[10];
    doublereal fac;
    integer feq_gen_feql_index1_d_, ihu;
    real eps, eut, qtl, qtr;
    integer nadj, free, ipfd;
    real pdfm, dqeu;
    doublereal lval, rval;
    integer cflag, lcode, rcode;
    real dqted, dqteu;
    extern /* Subroutine */ int tdlk43_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *), vrlim_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, char *, ftnlen);
    char feq_gen_make_monotone_d_[4], adjloc[1*351];
    real qtdiff, dqtedl, dqtedr, dqteul, dqteur;
    extern /* Subroutine */ int spline_(integer *, doublereal *, doublereal *,
	     integer *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *), store43_(integer *, integer *, char *, integer *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, real *, integer *, ftnlen);
    real feq_gen_qt_diff_d_[10];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__124 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__127 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__128 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__134 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__135 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, fmt_82, 0 };


/*     + + + PURPOSE + + + */
/*     Fit a table of type 13 to create information for a table of type 43. */
/*     The basic data for a type 13 table is already stored in the proper */
/*     arrays for processing.  Note that here  qmat includes all flows */
/*     at zero upshead and zero drop.  The partial free drop sequence and */
/*     the upstream head sequences are complete, having their zero entries */
/*     present.  nhu gives the count of all  upstream heads including zero, */
/*     and npfd gives all partial free drops including zero. */
/* SOURCE newlookup.for:674 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE newlookup.for:677 */
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
/* SOURCE newlookup.for:680 */
/*<       integereflag,ftp,ftpup,nhu,npfd,maxrow,stdout,table,verbose >*/
/* SOURCE newlookup.for:682 */
/*<       realhdatum >*/
/* SOURCE newlookup.for:684 */
/*<       real*8huall(nhu),freedrop(nhu),pfd(npfd),qmat(maxrow,npfd) >*/
/* SOURCE newlookup.for:687 */
/*<       charactersource*8 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE newlookup.for:690 */
/*<        >*/
/* SOURCE newlookup.for:692 */
/*<        >*/
/* SOURCE newlookup.for:697 */
/*<       integerlcode,rcode >*/
/* SOURCE newlookup.for:698 */
/*<       real*8lval,rval,fac >*/
/* SOURCE newlookup.for:699 */
/*<        >*/
/* SOURCE newlookup.for:706 */
/*<        >*/
/*     note: ppQppfdphu is the mixed partial derivative of flow first with */
/*     respect to hu and then wrt pfd.  ppQphuppfd is the mixed partial */
/*     of flow first wrt pfd and then wrt hu.  We want to test if these */
/*     are equal if no variation limitation is imposed. */
/*     ***************************formats******************************** */
/* SOURCE newlookup.for:658 */
/*<       integer feql_index1 >*/
/* SOURCE newlookup.for:715 */
/*<    50  >*/
/* SOURCE newlookup.for:718 */
/*<    52 format(f10.3,31(1pe10.4e1)) >*/
/* SOURCE newlookup.for:719 */
/*<    54 format('pQ/ppfd   ',30(1pe9.3e1,a1)) >*/
/* SOURCE newlookup.for:720 */
/*<    56 format('pQ/phu    ',30(1pe9.3e1,a1)) >*/
/* SOURCE newlookup.for:721 */
/*<    60 format('ppQ/ppfdph',30(1pe10.4e1)) >*/
/* SOURCE newlookup.for:722 */
/*<    62 format('ppQ/phppfd',30(1pe10.4e1)) >*/
/* SOURCE newlookup.for:723 */
/*<    72  >*/
/* SOURCE newlookup.for:725 */
/*<    73  >*/
/* SOURCE newlookup.for:727 */
/*<    74  >*/
/* SOURCE newlookup.for:730 */
/*<    75  >*/
/* SOURCE newlookup.for:732 */
/*<    76  >*/
/* SOURCE newlookup.for:734 */
/*<    77  >*/
/* SOURCE newlookup.for:736 */
/*<    78 format(' Two-D table of type 43 is a bi-cubic spline') >*/
/* SOURCE newlookup.for:737 */
/*<    79  >*/
/* *********************************************************************** */
/* SOURCE newlookup.for:740 */
/*<       make_monotone='YES' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> pfdropphu(feq_storage_pfdropphu, 1);

    feq::IndexedPointer<doublereal> freedrop(feq_storage_freedrop, 1);

    feq::IndexedPointer<doublereal> huall(feq_storage_huall, 1);

    feq::IndexedPointer<doublereal> pfd(feq_storage_pfd, 1);
    pqphuadj_dim1 = *maxrow;
    pqphuadj_offset = 1 + pqphuadj_dim1;

    feq::IndexedPointer<char> pqphuadj(feq_storage_pqphuadj, pqphuadj_offset);
    pqppfdadj_dim1 = *maxrow;
    pqppfdadj_offset = 1 + pqppfdadj_dim1;

    feq::IndexedPointer<char> pqppfdadj(feq_storage_pqppfdadj, pqppfdadj_offset);
    ppqphuppfd_dim1 = *maxrow;
    ppqphuppfd_offset = 1 + ppqphuppfd_dim1;

    feq::IndexedPointer<doublereal> ppqphuppfd(feq_storage_ppqphuppfd, ppqphuppfd_offset);
    ppqppfdphu_dim1 = *maxrow;
    ppqppfdphu_offset = 1 + ppqppfdphu_dim1;

    feq::IndexedPointer<doublereal> ppqppfdphu(feq_storage_ppqppfdphu, ppqppfdphu_offset);
    pqphu_dim1 = *maxrow;
    pqphu_offset = 1 + pqphu_dim1;

    feq::IndexedPointer<doublereal> pqphu(feq_storage_pqphu, pqphu_offset);
    pqppfd_dim1 = *maxrow;
    pqppfd_offset = 1 + pqppfd_dim1;

    feq::IndexedPointer<doublereal> pqppfd(feq_storage_pqppfd, pqppfd_offset);
    qmat_dim1 = *maxrow;
    qmat_offset = 1 + qmat_dim1;

    feq::IndexedPointer<doublereal> qmat(feq_storage_qmat, qmat_offset);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L60: */
/* L62: */
/* L72: */
/* L73: */
/* L74: */
/* L75: */
/* L76: */
/* L77: */
/* L78: */
/* L79: */
    s_copy(feq_gen_make_monotone_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3);
/* SOURCE newlookup.for:741 */
/*<       dofeql_index1=1,pmxfrc >*/
    for (feq_gen_feql_index1_d_ = 1; feq_gen_feql_index1_d_ <= 351; ++feq_gen_feql_index1_d_) {
/* SOURCE newlookup.for:741 */
/*<       adjloc(feql_index1)=' ' >*/
	*(unsigned char *)&adjloc[feq_gen_feql_index1_d_ - 1] = ' ';
/* SOURCE newlookup.for:741 */
/*<       enddo >*/
    }
/*     Set not-a-knot conditions for cubic spline */
/* SOURCE newlookup.for:744 */
/*<       lcode=3 >*/
    lcode = 3;
/* SOURCE newlookup.for:745 */
/*<       lval=0.5d0 >*/
    lval = .5;
/* SOURCE newlookup.for:746 */
/*<       rcode=3 >*/
    rcode = 3;
/* SOURCE newlookup.for:747 */
/*<       rval=0.5d0 >*/
    rval = .5;
/*     fit free drop versus ups head */
/* SOURCE newlookup.for:750 */
/*<        >*/
    spline_(stdout, &huall[1], &freedrop[1], nhu, &lcode, &lval, &rcode, &
	    rval, &pfdropphu[1]);
/*     compute the 1-d spline fits of flow vs pfd for each upstream head.  This gives */
/*     the partials of flow wrt to pfd */
/*     Impose what seems like reasonable end conditions: */
/*     On the left, that is for pfd=0, that is, complete submergence */
/*     to zero flow, we know that the derivative is infinite.  However, */
/*     we will not attempt to match that.  Instead we will just use */
/*     the extension, maybe same as not-a-knot, end condition. */
/*     At the right end, that is, pfd=1.0, theory implies that the */
/*     derivative should be zero.  It appears that to be consistent */
/*     as we approach free flow, that this condition must be forced */
/*     as well.  7 march 2003. It seems that forcing zero derivative */
/*     at the free-flow limit, as makes sense, does not make sense */
/*     for some 2-D tables, especially those from CULVERT.  The actual */
/*     table contents do not support zero derivatives.  Thus we will */
/*     shift that condition to the not-a-knot one as well.  Those tables */
/*     that DO statisfy the theory there should have small derivatives at the */
/*     free flow limit.  4 April 2003. */
/* SOURCE newlookup.for:774 */
/*<       nadj=0 >*/
    nadj = 0;
/* SOURCE newlookup.for:776 */
/*<       lcode=3 >*/
    lcode = 3;
/* SOURCE newlookup.for:777 */
/*<       lval=0.5d0 >*/
    lval = .5;
/*     Theory would like this set. */
/* SOURCE newlookup.for:779 */
/*<       rcode=1 >*/
    rcode = 1;
/* SOURCE newlookup.for:780 */
/*<       rval=0.0d0 >*/
    rval = 0.;
/*     but practice seems to want this one.  4 April 2003.  This */
/*     also produces equality between the two mixed derivatives at each */
/*     lattice point.  We can get this by forcing more complex conditions */
/*     at the limits.  However, the not-a-knot condition for the mixed */
/*     deriatives is attractive. */
/*      rcode = 3 */
/*      rval = 0.5d0 */
/* SOURCE newlookup.for:789 */
/*<       splineok=0 >*/
    splineok = 0;
/* SOURCE newlookup.for:790 */
/*<       nadj_ppfd=0 >*/
    feq_gen_nadj_ppfd_d_ = 0;
/* SOURCE newlookup.for:791 */
/*<       doihu=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (ihu = 1; ihu <= feq_gen_i_d_1; ++ihu) {
/* SOURCE newlookup.for:792 */
/*<       doipfd=1,npfd >*/
	feq_gen_i_d_2 = *npfd;
	for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
/* SOURCE newlookup.for:793 */
/*<       f(ipfd)=qmat(ihu,ipfd) >*/
	    f[ipfd - 1] = qmat[ihu + ipfd * qmat_dim1];
/* SOURCE newlookup.for:794 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:795 */
/*<       callspline(stdout,pfd,f,npfd,lcode,lval,rcode,rval,m) >*/
	spline_(stdout, &pfd[1], f, npfd, &lcode, &lval, &rcode, &rval, m);
/* SOURCE newlookup.for:798 */
/*<       if(make_monotone.eq.'YES')then >*/
	if (s_cmp(feq_gen_make_monotone_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE newlookup.for:799 */
/*<       callvrlim(npfd,pfd,f,m,nadj,adjloc) >*/
	    vrlim_(npfd, &pfd[1], f, m, &nadj, adjloc, (ftnlen)1);
/* SOURCE newlookup.for:803 */
/*<       else >*/
	} else {
/* SOURCE newlookup.for:804 */
/*<       nadj=0 >*/
	    nadj = 0;
/* SOURCE newlookup.for:805 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:806 */
/*<       splineok=splineok+nadj >*/
	splineok += nadj;
/* SOURCE newlookup.for:807 */
/*<       nadj_ppfd=nadj_ppfd+nadj >*/
	feq_gen_nadj_ppfd_d_ += nadj;
/*       store results in matrix for later output and analysis */
/* SOURCE newlookup.for:810 */
/*<       doipfd=1,npfd >*/
	feq_gen_i_d_2 = *npfd;
	for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
/* SOURCE newlookup.for:811 */
/*<       pqppfd(ihu,ipfd)=m(ipfd) >*/
	    pqppfd[ihu + ipfd * pqppfd_dim1] = m[ipfd - 1];
/* SOURCE newlookup.for:812 */
/*<       pqppfdadj(ihu,ipfd)=adjloc(ipfd) >*/
	    *(unsigned char *)&pqppfdadj[ihu + ipfd * pqppfdadj_dim1] = *(
		    unsigned char *)&adjloc[ipfd - 1];
/* SOURCE newlookup.for:813 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:814 */
/*<       enddo >*/
    }
/*     Now do a fit for pfd constant, that is, flow versus upstream head */
/*     for each line of constant partial free drop. */
/*     In some cases the partial wrt to hu with pfd held fixed should be */
/*     zero at the left end.  EMBANKQ, CHANRAT, CULVERT, and even ORIFICE */
/*     all start out at small heads as weir-like flow.  Thus if pfd=1.0, */
/*     free flow, it is clear that the partial wrt to hu should be zero. */
/* SOURCE newlookup.for:824 */
/*<       lcode=1 >*/
    lcode = 1;
/* SOURCE newlookup.for:825 */
/*<       lval=0.0d0 >*/
    lval = 0.;
/*     Try not-a-knot */
/*      lcode = 3 */
/*      lval = 0.5d0 */
/* SOURCE newlookup.for:830 */
/*<       rcode=3 >*/
    rcode = 3;
/* SOURCE newlookup.for:831 */
/*<       rval=0.5d0 >*/
    rval = .5;
/* SOURCE newlookup.for:833 */
/*<       nadj_phu=0 >*/
    feq_gen_nadj_phu_d_ = 0;
/* SOURCE newlookup.for:834 */
/*<       doipfd=1,npfd >*/
    feq_gen_i_d_1 = *npfd;
    for (ipfd = 1; ipfd <= feq_gen_i_d_1; ++ipfd) {
/* SOURCE newlookup.for:835 */
/*<       doihu=1,nhu >*/
	feq_gen_i_d_2 = *nhu;
	for (ihu = 1; ihu <= feq_gen_i_d_2; ++ihu) {
/* SOURCE newlookup.for:836 */
/*<       f(ihu)=qmat(ihu,ipfd) >*/
	    f[ihu - 1] = qmat[ihu + ipfd * qmat_dim1];
/* SOURCE newlookup.for:837 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:839 */
/*<       callspline(stdout,huall,f,nhu,lcode,lval,rcode,rval,m) >*/
	spline_(stdout, &huall[1], f, nhu, &lcode, &lval, &rcode, &rval, m);
/* SOURCE newlookup.for:842 */
/*<       if(make_monotone.eq.'YES')then >*/
	if (s_cmp(feq_gen_make_monotone_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE newlookup.for:843 */
/*<       callvrlim(nhu,huall,f,m,nadj,adjloc) >*/
	    vrlim_(nhu, &huall[1], f, m, &nadj, adjloc, (ftnlen)1);
/* SOURCE newlookup.for:847 */
/*<       else >*/
	} else {
/* SOURCE newlookup.for:848 */
/*<       nadj=0 >*/
	    nadj = 0;
/* SOURCE newlookup.for:849 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:850 */
/*<       splineok=splineok+nadj >*/
	splineok += nadj;
/* SOURCE newlookup.for:851 */
/*<       nadj_phu=nadj_phu+nadj >*/
	feq_gen_nadj_phu_d_ += nadj;
/* SOURCE newlookup.for:853 */
/*<       doihu=1,nhu >*/
	feq_gen_i_d_2 = *nhu;
	for (ihu = 1; ihu <= feq_gen_i_d_2; ++ihu) {
/* SOURCE newlookup.for:854 */
/*<       pqphu(ihu,ipfd)=m(ihu) >*/
	    pqphu[ihu + ipfd * pqphu_dim1] = m[ihu - 1];
/* SOURCE newlookup.for:855 */
/*<       pqphuadj(ihu,ipfd)=adjloc(ihu) >*/
	    *(unsigned char *)&pqphuadj[ihu + ipfd * pqphuadj_dim1] = *(
		    unsigned char *)&adjloc[ihu - 1];
/* SOURCE newlookup.for:856 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:857 */
/*<       enddo >*/
    }
/*     For the mixed partials, we have no good theory to guide us */
/*     in what conditions to use.  We select boundary conditions that */
/*     cause the two estimates of mixed partials to be equal whenever */
/*     a cubic-spline fit satisfies monotonicity requirements. */
/* SOURCE newlookup.for:864 */
/*<       lcode=3 >*/
    lcode = 3;
/* SOURCE newlookup.for:865 */
/*<       lval=0.5d0 >*/
    lval = .5;
/* SOURCE newlookup.for:866 */
/*<       rcode=1 >*/
    rcode = 1;
/* SOURCE newlookup.for:867 */
/*<       rval=0.0d0 >*/
    rval = 0.;
/*     Now compute the mixed partial derivatives. */
/*     Do those wrt to pfd. */
/* SOURCE newlookup.for:872 */
/*<       nadj=0 >*/
    nadj = 0;
/* SOURCE newlookup.for:873 */
/*<       doihu=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (ihu = 1; ihu <= feq_gen_i_d_1; ++ihu) {
/* SOURCE newlookup.for:874 */
/*<       doipfd=1,npfd >*/
	feq_gen_i_d_2 = *npfd;
	for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
/* SOURCE newlookup.for:875 */
/*<       f(ipfd)=pqphu(ihu,ipfd) >*/
	    f[ipfd - 1] = pqphu[ihu + ipfd * pqphu_dim1];
/* SOURCE newlookup.for:876 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:877 */
/*<       callspline(stdout,pfd,f,npfd,lcode,lval,rcode,rval,m) >*/
	spline_(stdout, &pfd[1], f, npfd, &lcode, &lval, &rcode, &rval, m);
/*       Only force monotonicity on the mixed partials if adjustments were */
/*       made in the original fits. */
/* SOURCE newlookup.for:882 */
/*<       if(nadj_phu.ne.0)then >*/
	if (feq_gen_nadj_phu_d_ != 0) {
/* SOURCE newlookup.for:883 */
/*<       callvrlim(npfd,pfd,f,m,nadj_mixed,adjloc) >*/
	    vrlim_(npfd, &pfd[1], f, m, &feq_gen_nadj_mixed_d_, adjloc, (ftnlen)1);
/* SOURCE newlookup.for:887 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:888 */
/*<       doipfd=1,npfd >*/
	feq_gen_i_d_2 = *npfd;
	for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
/* SOURCE newlookup.for:889 */
/*<       ppqppfdphu(ihu,ipfd)=m(ipfd) >*/
	    ppqppfdphu[ihu + ipfd * ppqppfdphu_dim1] = m[ipfd - 1];
/* SOURCE newlookup.for:890 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:891 */
/*<       enddo >*/
    }
/*     Do those wrt to hu */
/* SOURCE newlookup.for:894 */
/*<       lcode=1 >*/
    lcode = 1;
/* SOURCE newlookup.for:895 */
/*<       lval=0.0d0 >*/
    lval = 0.;
/* SOURCE newlookup.for:896 */
/*<       rcode=3 >*/
    rcode = 3;
/* SOURCE newlookup.for:897 */
/*<       rval=0.5d0 >*/
    rval = .5;
/* SOURCE newlookup.for:899 */
/*<       nadj=0 >*/
    nadj = 0;
/* SOURCE newlookup.for:900 */
/*<       doipfd=1,npfd >*/
    feq_gen_i_d_1 = *npfd;
    for (ipfd = 1; ipfd <= feq_gen_i_d_1; ++ipfd) {
/* SOURCE newlookup.for:901 */
/*<       doihu=1,nhu >*/
	feq_gen_i_d_2 = *nhu;
	for (ihu = 1; ihu <= feq_gen_i_d_2; ++ihu) {
/* SOURCE newlookup.for:902 */
/*<       f(ihu)=pqppfd(ihu,ipfd) >*/
	    f[ihu - 1] = pqppfd[ihu + ipfd * pqppfd_dim1];
/* SOURCE newlookup.for:903 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:905 */
/*<       callspline(stdout,huall,f,nhu,lcode,lval,rcode,rval,m) >*/
	spline_(stdout, &huall[1], f, nhu, &lcode, &lval, &rcode, &rval, m);
/* SOURCE newlookup.for:908 */
/*<       if(nadj_ppfd.ne.0)then >*/
	if (feq_gen_nadj_ppfd_d_ != 0) {
/* SOURCE newlookup.for:909 */
/*<       callvrlim(nhu,huall,f,m,nadj_mixed,adjloc) >*/
	    vrlim_(nhu, &huall[1], f, m, &feq_gen_nadj_mixed_d_, adjloc, (ftnlen)1);
/* SOURCE newlookup.for:913 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:914 */
/*<       doihu=1,nhu >*/
	feq_gen_i_d_2 = *nhu;
	for (ihu = 1; ihu <= feq_gen_i_d_2; ++ihu) {
/* SOURCE newlookup.for:915 */
/*<       ppqphuppfd(ihu,ipfd)=m(ihu) >*/
	    ppqphuppfd[ihu + ipfd * ppqphuppfd_dim1] = m[ihu - 1];
/* SOURCE newlookup.for:916 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:917 */
/*<       enddo >*/
    }
/* SOURCE newlookup.for:919 */
/*<       if(splineok.eq.0)then >*/
    if (splineok == 0) {
/* SOURCE newlookup.for:920 */
/*<       write(stdout,78) >*/
	feq_gen_io_d__124.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__124);
	e_wsfe();
/* SOURCE newlookup.for:921 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:922 */
/*<       write(stdout,79) >*/
	feq_gen_io_d__125.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__125);
	e_wsfe();
/* SOURCE newlookup.for:923 */
/*<       fac=float(splineok)/float(2*nhu*npfd) >*/
	fac = static_cast<double>((real) splineok) / (real) ((*nhu << 1) * *npfd);
/* SOURCE newlookup.for:924 */
/*<       write(stdout,72)splineok,fac*100. >*/
	feq_gen_io_d__127.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__127);
	do_fio(&feq_gen_c_d_1, (char *)&splineok, (ftnlen)sizeof(integer));
	feq_gen_d_d_1 = fac * (float)100.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE newlookup.for:925 */
/*<       write(stdout,73)nadj_ppfd,nadj_phu >*/
	feq_gen_io_d__128.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__128);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_nadj_ppfd_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_nadj_phu_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE newlookup.for:926 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:928 */
/*<       if(verbose.eq.1)then >*/
    if (*verbose == 1) {
/* SOURCE newlookup.for:929 */
/*<       doihu=1,nhu >*/
	feq_gen_i_d_1 = *nhu;
	for (ihu = 1; ihu <= feq_gen_i_d_1; ++ihu) {
/* SOURCE newlookup.for:930 */
/*<       write(stdout,50)(pfd(i),i=1,npfd) >*/
	    feq_gen_io_d__129.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__129);
	    feq_gen_i_d_2 = *npfd;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
		do_fio(&feq_gen_c_d_1, (char *)&pfd[feq_gen_i_d_], (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
/* SOURCE newlookup.for:932 */
/*<        >*/
	    feq_gen_io_d__131.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__131);
	    do_fio(&feq_gen_c_d_1, (char *)&huall[ihu], (ftnlen)sizeof(doublereal));
	    feq_gen_i_d_2 = *npfd;
	    for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
		do_fio(&feq_gen_c_d_1, (char *)&qmat[ihu + ipfd * qmat_dim1], (ftnlen)
			sizeof(doublereal));
	    }
	    do_fio(&feq_gen_c_d_1, (char *)&freedrop[ihu], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE newlookup.for:935 */
/*<        >*/
	    feq_gen_io_d__132.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__132);
	    feq_gen_i_d_2 = *npfd;
	    for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
		do_fio(&feq_gen_c_d_1, (char *)&pqppfd[ihu + ipfd * pqppfd_dim1], (
			ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, pqppfdadj + (ihu + ipfd * pqppfdadj_dim1), (
			ftnlen)1);
	    }
	    do_fio(&feq_gen_c_d_1, (char *)&pfdropphu[ihu], (ftnlen)sizeof(doublereal))
		    ;
	    e_wsfe();
/* SOURCE newlookup.for:939 */
/*<       write(stdout,56)(pqphu(ihu,ipfd),pqphuadj(ihu,ipfd),ipfd=1,npfd) >*/
	    feq_gen_io_d__133.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__133);
	    feq_gen_i_d_2 = *npfd;
	    for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
		do_fio(&feq_gen_c_d_1, (char *)&pqphu[ihu + ipfd * pqphu_dim1], (
			ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, pqphuadj + (ihu + ipfd * pqphuadj_dim1), (
			ftnlen)1);
	    }
	    e_wsfe();
/* SOURCE newlookup.for:942 */
/*<       write(stdout,60)(ppqppfdphu(ihu,ipfd),ipfd=1,npfd) >*/
	    feq_gen_io_d__134.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__134);
	    feq_gen_i_d_2 = *npfd;
	    for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
		do_fio(&feq_gen_c_d_1, (char *)&ppqppfdphu[ihu + ipfd * 
			ppqppfdphu_dim1], (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
/* SOURCE newlookup.for:944 */
/*<       write(stdout,62)(ppqphuppfd(ihu,ipfd),ipfd=1,npfd) >*/
	    feq_gen_io_d__135.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__135);
	    feq_gen_i_d_2 = *npfd;
	    for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
		do_fio(&feq_gen_c_d_1, (char *)&ppqphuppfd[ihu + ipfd * 
			ppqphuppfd_dim1], (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
/* SOURCE newlookup.for:945 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:946 */
/*<       endif >*/
    }
/*     store the table in the function-table structure but do not update */
/*     the pointer.  We will do some tests of this table */
/*     without retaining information in function-table structure. */
/*     The pointer may be updated by the routine that calls this one */
/*     however. */
/*      call store43(stdout, table, source, maxrow, nhu, npfd, */
/*     i         huall, freedrop, pfdropphu, pfd, qmat, pqppfd, */
/*     i         pqphu, ppQphuppfd, ftp,   hdatum , */
/*     o         ftpup ) */
/* SOURCE newlookup.for:958 */
/*<        >*/
    store43_(stdout, table, source, maxrow, nhu, npfd, &huall[1], &freedrop[1]
	    , &pfdropphu[1], &pfd[1], &qmat[qmat_offset], &pqppfd[
	    pqppfd_offset], &pqphu[pqphu_offset], &ppqppfdphu[
	    ppqppfdphu_offset], ftp, hdatum, ftpup, (ftnlen)8);
/*     Check against the table at lattice points */
/*      write(stdout,71) */
/* 71    format('        hu        hd        qt    qtdiff', */
/*     a'     dqted dqteddiff     dqteu dqteudiff free') */
/* SOURCE newlookup.for:969 */
/*<       qt_diff(1)=-1.e10 >*/
    feq_gen_qt_diff_d_[0] = (float)-1e10;
/* SOURCE newlookup.for:970 */
/*<       dqteu_diff(1)=-1.e10 >*/
    feq_gen_dqteu_diff_d_[0] = (float)-1e10;
/* SOURCE newlookup.for:971 */
/*<       dqted_diff(1)=-1.e10 >*/
    feq_gen_dqted_diff_d_[0] = (float)-1e10;
/*     eliminate zero free drop for checking */
/* SOURCE newlookup.for:974 */
/*<       if(freedrop(1).eq.0.0)then >*/
    if (freedrop[1] == (float)0.) {
/* SOURCE newlookup.for:975 */
/*<       freedrop(1)=freedrop(2) >*/
	freedrop[1] = freedrop[2];
/* SOURCE newlookup.for:976 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:977 */
/*<       doihu=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (ihu = 1; ihu <= feq_gen_i_d_1; ++ihu) {
/* SOURCE newlookup.for:978 */
/*<       doipfd=1,npfd >*/
	feq_gen_i_d_2 = *npfd;
	for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
/* SOURCE newlookup.for:979 */
/*<       eu=huall(ihu) >*/
	    eu = huall[ihu];
/* SOURCE newlookup.for:980 */
/*<       ed=huall(ihu)-pfd(ipfd)*freedrop(ihu) >*/
	    ed = huall[ihu] - pfd[ipfd] * freedrop[ihu];
/*         set datum to zero so that heads are used! */
/* SOURCE newlookup.for:983 */
/*<       calltdlk43(stdout,ftp,43,0,0.0d0,ed,eu,0.0,qt,dqted,dqteu,free) >*/
	    tdlk43_(stdout, ftp, &feq_gen_c_d_43, &feq_gen_c_d_0, &c_b86, &ed, &eu, &c_b87, &qt,
		     &dqted, &dqteu, &free);
/* SOURCE newlookup.for:988 */
/*<       if(qmat(ihu,ipfd).gt.0.0)then >*/
	    if (qmat[ihu + ipfd * qmat_dim1] > (float)0.) {
/* SOURCE newlookup.for:989 */
/*<       qtdiff=(qt-qmat(ihu,ipfd))/max(0.005d0,qmat(ihu,ipfd)) >*/
/* Computing MAX */
		feq_gen_d_d_1 = .005, feq_gen_d_d_2 = qmat[ihu + ipfd * qmat_dim1];
		qtdiff = (qt - qmat[ihu + ipfd * qmat_dim1]) / max(feq_gen_d_d_1,feq_gen_d_d_2);
/* SOURCE newlookup.for:990 */
/*<       else >*/
	    } else {
/*           use absolute error. */
/* SOURCE newlookup.for:992 */
/*<       qtdiff=qt >*/
		qtdiff = qt;
/* SOURCE newlookup.for:993 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:994 */
/*<       if(abs(qtdiff).gt.qt_diff(1))then >*/
	    if (dabs(qtdiff) > feq_gen_qt_diff_d_[0]) {
/* SOURCE newlookup.for:995 */
/*<       qt_diff(1)=abs(qtdiff) >*/
		feq_gen_qt_diff_d_[0] = dabs(qtdiff);
/* SOURCE newlookup.for:996 */
/*<       qt_diff(2)=eu >*/
		feq_gen_qt_diff_d_[1] = eu;
/* SOURCE newlookup.for:997 */
/*<       qt_diff(3)=ed >*/
		feq_gen_qt_diff_d_[2] = ed;
/* SOURCE newlookup.for:998 */
/*<       qt_diff(4)=qmat(ihu,ipfd) >*/
		feq_gen_qt_diff_d_[3] = qmat[ihu + ipfd * qmat_dim1];
/* SOURCE newlookup.for:999 */
/*<       qt_diff(5)=pqphu(ihu,ipfd) >*/
		feq_gen_qt_diff_d_[4] = pqphu[ihu + ipfd * pqphu_dim1];
/* SOURCE newlookup.for:1000 */
/*<       qt_diff(6)=pqppfd(ihu,ipfd) >*/
		feq_gen_qt_diff_d_[5] = pqppfd[ihu + ipfd * pqppfd_dim1];
/* SOURCE newlookup.for:1001 */
/*<       qt_diff(7)=free >*/
		feq_gen_qt_diff_d_[6] = (real) free;
/* SOURCE newlookup.for:1002 */
/*<       qt_diff(8)=qt >*/
		feq_gen_qt_diff_d_[7] = qt;
/* SOURCE newlookup.for:1003 */
/*<       qt_diff(9)=dqteu >*/
		feq_gen_qt_diff_d_[8] = dqteu;
/* SOURCE newlookup.for:1004 */
/*<       qt_diff(10)=dqted >*/
		feq_gen_qt_diff_d_[9] = dqted;
/* SOURCE newlookup.for:1006 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1007 */
/*<       if(abs(pqppfd(ihu,ipfd)).gt.0.0)then >*/
	    if ((feq_gen_d_d_1 = pqppfd[ihu + ipfd * pqppfd_dim1], abs(feq_gen_d_d_1)) > (float)
		    0.) {
/* SOURCE newlookup.for:1008 */
/*<        >*/
/* Computing MAX */
		feq_gen_d_d_2 = .001, feq_gen_d_d_3 = freedrop[ihu];
/* Computing MAX */
		feq_gen_d_d_4 = .005, feq_gen_d_d_5 = (feq_gen_d_d_1 = pqppfd[ihu + ipfd * pqppfd_dim1] /
			 freedrop[ihu], abs(feq_gen_d_d_1));
		dqteddiff = (dqted + pqppfd[ihu + ipfd * pqppfd_dim1] / max(
			feq_gen_d_d_2,feq_gen_d_d_3)) / max(feq_gen_d_d_4,feq_gen_d_d_5);
/* SOURCE newlookup.for:1011 */
/*<       else >*/
	    } else {
/*           use absolute error. */
/* SOURCE newlookup.for:1013 */
/*<       dqteddiff=abs(pqppfd(ihu,ipfd)/freedrop(ihu)) >*/
		dqteddiff = (feq_gen_d_d_1 = pqppfd[ihu + ipfd * pqppfd_dim1] / 
			freedrop[ihu], abs(feq_gen_d_d_1));
/* SOURCE newlookup.for:1014 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1015 */
/*<       if(abs(dqteddiff).gt.dqted_diff(1))then >*/
	    if (dabs(dqteddiff) > feq_gen_dqted_diff_d_[0]) {
/* SOURCE newlookup.for:1016 */
/*<       dqted_diff(1)=abs(dqteddiff) >*/
		feq_gen_dqted_diff_d_[0] = dabs(dqteddiff);
/* SOURCE newlookup.for:1017 */
/*<       dqted_diff(2)=eu >*/
		feq_gen_dqted_diff_d_[1] = eu;
/* SOURCE newlookup.for:1018 */
/*<       dqted_diff(3)=ed >*/
		feq_gen_dqted_diff_d_[2] = ed;
/* SOURCE newlookup.for:1019 */
/*<       dqted_diff(4)=qmat(ihu,ipfd) >*/
		feq_gen_dqted_diff_d_[3] = qmat[ihu + ipfd * qmat_dim1];
/* SOURCE newlookup.for:1020 */
/*<       dqted_diff(5)=pqphu(ihu,ipfd) >*/
		feq_gen_dqted_diff_d_[4] = pqphu[ihu + ipfd * pqphu_dim1];
/* SOURCE newlookup.for:1021 */
/*<       dqted_diff(6)=pqppfd(ihu,ipfd) >*/
		feq_gen_dqted_diff_d_[5] = pqppfd[ihu + ipfd * pqppfd_dim1];
/* SOURCE newlookup.for:1022 */
/*<       dqted_diff(7)=free >*/
		feq_gen_dqted_diff_d_[6] = (real) free;
/* SOURCE newlookup.for:1023 */
/*<       dqted_diff(8)=qt >*/
		feq_gen_dqted_diff_d_[7] = qt;
/* SOURCE newlookup.for:1024 */
/*<       dqted_diff(9)=dqteu >*/
		feq_gen_dqted_diff_d_[8] = dqteu;
/* SOURCE newlookup.for:1025 */
/*<       dqted_diff(10)=dqted >*/
		feq_gen_dqted_diff_d_[9] = dqted;
/* SOURCE newlookup.for:1026 */
/*<       endif >*/
	    }
/*         compute dqeu from the basic data */
/* SOURCE newlookup.for:1029 */
/*<        >*/
	    dqeu = pqphu[ihu + ipfd * pqphu_dim1] + pqppfd[ihu + ipfd * 
		    pqppfd_dim1] * ((float)1. - pfd[ipfd] * pfdropphu[ihu]) / 
		    freedrop[ihu];
/* SOURCE newlookup.for:1031 */
/*<       if(abs(dqeu).gt.0.0)then >*/
	    if (dabs(dqeu) > (float)0.) {
/* SOURCE newlookup.for:1032 */
/*<       dqteudiff=(dqteu-dqeu)/max(0.005,abs(dqeu)) >*/
/* Computing MAX */
		feq_gen_r_d_1 = (float).005, feq_gen_r_d_2 = dabs(dqeu);
		dqteudiff = (static_cast<double>(dqteu) - dqeu) / dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE newlookup.for:1034 */
/*<       else >*/
	    } else {
/*           use absolute error */
/* SOURCE newlookup.for:1036 */
/*<       dqteudiff=abs(dqteu) >*/
		dqteudiff = dabs(dqteu);
/* SOURCE newlookup.for:1037 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1038 */
/*<       if(abs(dqteudiff).gt.dqteu_diff(1))then >*/
	    if (dabs(dqteudiff) > feq_gen_dqteu_diff_d_[0]) {
/* SOURCE newlookup.for:1039 */
/*<       dqteu_diff(1)=abs(dqteudiff) >*/
		feq_gen_dqteu_diff_d_[0] = dabs(dqteudiff);
/* SOURCE newlookup.for:1040 */
/*<       dqteu_diff(2)=eu >*/
		feq_gen_dqteu_diff_d_[1] = eu;
/* SOURCE newlookup.for:1041 */
/*<       dqteu_diff(3)=ed >*/
		feq_gen_dqteu_diff_d_[2] = ed;
/* SOURCE newlookup.for:1042 */
/*<       dqteu_diff(4)=qmat(ihu,ipfd) >*/
		feq_gen_dqteu_diff_d_[3] = qmat[ihu + ipfd * qmat_dim1];
/* SOURCE newlookup.for:1043 */
/*<       dqteu_diff(5)=pqphu(ihu,ipfd) >*/
		feq_gen_dqteu_diff_d_[4] = pqphu[ihu + ipfd * pqphu_dim1];
/* SOURCE newlookup.for:1044 */
/*<       dqteu_diff(6)=pqppfd(ihu,ipfd) >*/
		feq_gen_dqteu_diff_d_[5] = pqppfd[ihu + ipfd * pqppfd_dim1];
/* SOURCE newlookup.for:1045 */
/*<       dqteu_diff(7)=free >*/
		feq_gen_dqteu_diff_d_[6] = (real) free;
/* SOURCE newlookup.for:1046 */
/*<       dqteu_diff(8)=qt >*/
		feq_gen_dqteu_diff_d_[7] = qt;
/* SOURCE newlookup.for:1047 */
/*<       dqteu_diff(9)=dqteu >*/
		feq_gen_dqteu_diff_d_[8] = dqteu;
/* SOURCE newlookup.for:1048 */
/*<       dqteu_diff(10)=dqted >*/
		feq_gen_dqteu_diff_d_[9] = dqted;
/* SOURCE newlookup.for:1049 */
/*<       endif >*/
	    }
/*          write(stdout,73) */
/*     a      eu, ed, qt, qtdiff, dqted, dqteddiff, dqteu, dqteudiff, free */

/* 73    format(f10.3,f10.3,6(1pe10.3),i5) */
/* SOURCE newlookup.for:1055 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:1056 */
/*<       enddo >*/
    }
/* SOURCE newlookup.for:1058 */
/*<       write(stdout,74) >*/
    feq_gen_io_d__149.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__149);
    e_wsfe();
/* SOURCE newlookup.for:1060 */
/*<       write(stdout,75)qt_diff >*/
    feq_gen_io_d__150.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__150);
    do_fio(&feq_gen_c_d_10, (char *)&feq_gen_qt_diff_d_[0], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE newlookup.for:1062 */
/*<       write(stdout,76)dqteu_diff >*/
    feq_gen_io_d__151.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__151);
    do_fio(&feq_gen_c_d_10, (char *)&feq_gen_dqteu_diff_d_[0], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE newlookup.for:1064 */
/*<       write(stdout,77)dqted_diff >*/
    feq_gen_io_d__152.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__152);
    do_fio(&feq_gen_c_d_10, (char *)&feq_gen_dqted_diff_d_[0], (ftnlen)sizeof(real));
    e_wsfe();
/*     check for continuity of function and derivative between lattice points. */
/* SOURCE newlookup.for:1068 */
/*<       eps=5.e-4 >*/
    eps = (float)5e-4;
/* SOURCE newlookup.for:1069 */
/*<       cflag=0 >*/
    cflag = 0;
/* SOURCE newlookup.for:1070 */
/*<       doipfd=2,npfd >*/
    feq_gen_i_d_1 = *npfd;
    for (ipfd = 2; ipfd <= feq_gen_i_d_1; ++ipfd) {
/* SOURCE newlookup.for:1071 */
/*<       pdfm=0.5*(pfd(ipfd-1)+pfd(ipfd)) >*/
	pdfm = (pfd[ipfd - 1] + pfd[ipfd]) * (float).5;
/* SOURCE newlookup.for:1072 */
/*<       doihu=2,nhu-1 >*/
	feq_gen_i_d_2 = *nhu - 1;
	for (ihu = 2; ihu <= feq_gen_i_d_2; ++ihu) {
/* SOURCE newlookup.for:1073 */
/*<       cflag=0 >*/
	    cflag = 0;
/* SOURCE newlookup.for:1074 */
/*<       eu=huall(ihu) >*/
	    eu = huall[ihu];
/* SOURCE newlookup.for:1075 */
/*<       eut=eu-eu*1.1920928955078125e-7 >*/
	    eut = static_cast<double>(eu) - static_cast<double>(eu) * (float)1.1920928955078125e-7;
/* SOURCE newlookup.for:1077 */
/*<       ed=eut-pdfm*freedrop(ihu) >*/
	    ed = eut - pdfm * freedrop[ihu];
/*         Compute a small deviation from the ups elevation/head */
/*         to force lookup on both sides of the tabulated values. */
/*         set datum to zero so that heads are used! */
/* SOURCE newlookup.for:1083 */
/*<        >*/
	    tdlk43_(stdout, ftp, &feq_gen_c_d_43, &feq_gen_c_d_0, &c_b86, &ed, &eut, &c_b87, &
		    qtl, &dqtedl, &dqteul, &free);
/* SOURCE newlookup.for:1088 */
/*<       calltdlk43(stdout,ftp,43,0,0.0d0,ed,eu,0.0,qt,dqted,dqteu,free) >*/
	    tdlk43_(stdout, ftp, &feq_gen_c_d_43, &feq_gen_c_d_0, &c_b86, &ed, &eu, &c_b87, &qt,
		     &dqted, &dqteu, &free);
/* SOURCE newlookup.for:1093 */
/*<       eut=eu+eu*1.1920928955078125e-7 >*/
	    eut = static_cast<double>(eu) + static_cast<double>(eu) * (float)1.1920928955078125e-7;
/* SOURCE newlookup.for:1094 */
/*<        >*/
	    tdlk43_(stdout, ftp, &feq_gen_c_d_43, &feq_gen_c_d_0, &c_b86, &ed, &eut, &c_b87, &
		    qtr, &dqtedr, &dqteur, &free);
/* SOURCE newlookup.for:1100 */
/*<       if(min(abs(dqtedl),abs(dqtedr)).gt.eps)then >*/
/* Computing MIN */
	    feq_gen_r_d_1 = dabs(dqtedl), feq_gen_r_d_2 = dabs(dqtedr);
	    if (dmin(feq_gen_r_d_1,feq_gen_r_d_2) > eps) {
/* SOURCE newlookup.for:1101 */
/*<        >*/
/* Computing MIN */
		feq_gen_r_d_2 = dabs(dqtedl), feq_gen_r_d_3 = dabs(dqtedr);
		if ((feq_gen_r_d_1 = static_cast<double>((static_cast<double>(dqtedl) - dqtedr)) * (float).5 / dmin(feq_gen_r_d_2,feq_gen_r_d_3), 
			dabs(feq_gen_r_d_1)) > eps) {
/* SOURCE newlookup.for:1104 */
/*<       cflag=1 >*/
		    cflag = 1;
/* SOURCE newlookup.for:1105 */
/*<       endif >*/
		}
/* SOURCE newlookup.for:1106 */
/*<       else >*/
	    } else {
/* SOURCE newlookup.for:1107 */
/*<       if(abs(dqtedl-dqtedr).gt.eps)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(dqtedl) - dqtedr, dabs(feq_gen_r_d_1)) > eps) {
/* SOURCE newlookup.for:1108 */
/*<       cflag=1 >*/
		    cflag = 1;
/* SOURCE newlookup.for:1109 */
/*<       endif >*/
		}
/* SOURCE newlookup.for:1110 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1111 */
/*<       if(min(abs(dqteul),abs(dqteur)).gt.eps)then >*/
/* Computing MIN */
	    feq_gen_r_d_1 = dabs(dqteul), feq_gen_r_d_2 = dabs(dqteur);
	    if (dmin(feq_gen_r_d_1,feq_gen_r_d_2) > eps) {
/* SOURCE newlookup.for:1112 */
/*<        >*/
/* Computing MIN */
		feq_gen_r_d_2 = dabs(dqteul), feq_gen_r_d_3 = dabs(dqteur);
		if ((feq_gen_r_d_1 = static_cast<double>((static_cast<double>(dqteul) - dqteur)) * (float).5 / dmin(feq_gen_r_d_2,feq_gen_r_d_3), 
			dabs(feq_gen_r_d_1)) > eps) {
/* SOURCE newlookup.for:1114 */
/*<       cflag=1 >*/
		    cflag = 1;
/* SOURCE newlookup.for:1115 */
/*<       endif >*/
		}
/* SOURCE newlookup.for:1116 */
/*<       else >*/
	    } else {
/* SOURCE newlookup.for:1117 */
/*<       if(abs(dqteul-dqteur).gt.eps)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(dqteul) - dqteur, dabs(feq_gen_r_d_1)) > eps) {
/* SOURCE newlookup.for:1118 */
/*<       cflag=1 >*/
		    cflag = 1;
/* SOURCE newlookup.for:1119 */
/*<       endif >*/
		}
/* SOURCE newlookup.for:1120 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1122 */
/*<       if(cflag.gt.0)then >*/
	    if (cflag > 0) {
/*        write(stdout,80) cflag */
/* 80    format(/,'Warning: Count of derivative discontinuities=',i5) */
/* SOURCE newlookup.for:1126 */
/*<       write(stdout,82)eu,eut,ed,dqtedl,dqtedr,dqteul,dqteur,pdfm >*/
		feq_gen_io_d__163.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__163);
		do_fio(&feq_gen_c_d_1, (char *)&eu, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&eut, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ed, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&dqtedl, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&dqtedr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&dqteul, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&dqteur, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&pdfm, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE newlookup.for:1128 */
/*<    82  >*/
/* SOURCE newlookup.for:1132 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1134 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:1135 */
/*<       enddo >*/
    }
/* SOURCE newlookup.for:1138 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:1139 */
/*<       end >*/
} /* twodtabfit_storage__ */




/* SOURCE newlookup.for:1143 */
/*<       subroutinevrlim(n,x,y,m,nadj,adjloc) >*/
/* Subroutine */ int vrlim_(integer *n, doublereal *feq_storage_x, doublereal *feq_storage_y, 
	doublereal *feq_storage_m, integer *nadj, char *feq_storage_adjloc, ftnlen adjloc_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2, feq_gen_d_d_3;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal feq_gen_r_d_, s, sl, xl, sr, st, xr;

/*     + + + PURPOSE + + + */
/*     Force limited variation on the cubic piecewise polynomial */
/*     representation of the function Y. */
/* SOURCE newlookup.for:1152 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE newlookup.for:1155 */
/*<       integern,nadj >*/
/* SOURCE newlookup.for:1156 */
/*<       doubleprecisionm(n),x(n),y(n) >*/
/* SOURCE newlookup.for:1158 */
/*<       characteradjloc(n)*1 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - number of points */
/*     X      - breakpoints for the spline */
/*     Y      - function values for spline */
/*     M      - Vector of first derivatives */
/*     ADJLOC - values at which slope was adjusted to limit variation */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE newlookup.for:1169 */
/*<       integeri >*/
/* SOURCE newlookup.for:1170 */
/*<       doubleprecisionr,s,sl,sr,st,xl,xr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE newlookup.for:1173 */
/*<       intrinsicabs,min,sign >*/
/* *********************************************************************** */
/*     To have limited variation, the ratio, R,  of the derivative at the */
/*     breakpoints in X(*) to the slopes in M(*) */
/*     must satisfy 0 <= R <= 3 at each breakpoint.  This is somewhat more */
/*     restrictive than it need be.  For example if the relative slope on the */
/*     left is 1.0 then the relative slope on the right may be as large as */
/*     4 and still maintain a zero or positive slope.  However, making the */
/*     changes depend on a particular slope outcome is more involved. */
/*     Thus we restrict the relative slope to be between 0 and 3 even though */
/*     that forces a change at a point where the variation is already monotone. */
/*     We capture most of the region involved this way and keep the adjustment */
/*     of computed slopes relatively simple.  If we made the adjustment */
/*     dependent on the local computed slopes, to gain more of the region of */
/*     monotone behavior, then we have to have special action if the computed */
/*     relative slope is negative and the problem of propagation of changes */
/*     must be solved.  We are only trying to create a smoother function */
/*     to constrain wild behavior.  This smoother function */
/*     may be more accurate but we have not checked nor are we motivated */
/*     by concern for accuracy here-we are motivated by concern for smoothness */
/*     and certainty about the nature of interpolated results. */
/*     13 march 2003. */
/* SOURCE newlookup.for:1198 */
/*<       nadj=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> adjloc(feq_storage_adjloc, 1);

    feq::IndexedPointer<doublereal> m(feq_storage_m, 1);

    feq::IndexedPointer<doublereal> y(feq_storage_y, 1);

    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
    *nadj = 0;
/*     Check the left end.  Chord is on the right. */
/* SOURCE newlookup.for:1201 */
/*<       xr=(x(2)-x(1)) >*/
    xr = x[2] - x[1];
/* SOURCE newlookup.for:1202 */
/*<       sr=(y(2)-y(1))/xr >*/
    sr = (y[2] - y[1]) / xr;
/* SOURCE newlookup.for:1204 */
/*<       adjloc(1)=' ' >*/
    *(unsigned char *)&adjloc[1] = ' ';
/* SOURCE newlookup.for:1205 */
/*<       if(sr.eq.0.d0)then >*/
    if (sr == 0.) {
/* SOURCE newlookup.for:1206 */
/*<       if(m(1).ne.0.d0)then >*/
	if (m[1] != 0.) {
/*         Derivative must be zero if the secant slope is zero */
/* SOURCE newlookup.for:1208 */
/*<       m(1)=0.d0 >*/
	    m[1] = 0.;
/* SOURCE newlookup.for:1209 */
/*<       adjloc(1)='^' >*/
	    *(unsigned char *)&adjloc[1] = '^';
/* SOURCE newlookup.for:1210 */
/*<       nadj=nadj+1 >*/
	    ++(*nadj);
/* SOURCE newlookup.for:1211 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1212 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:1213 */
/*<       r=m(1)/sr >*/
	feq_gen_r_d_ = m[1] / sr;
/* SOURCE newlookup.for:1214 */
/*<       if(r.gt.3.d0)then >*/
	if (feq_gen_r_d_ > 3.) {
/*         Limit slope to three times the secant slope. */
/* SOURCE newlookup.for:1216 */
/*<       m(1)=3.d0*sr >*/
	    m[1] = sr * 3.;
/* SOURCE newlookup.for:1217 */
/*<       adjloc(1)='^' >*/
	    *(unsigned char *)&adjloc[1] = '^';
/* SOURCE newlookup.for:1218 */
/*<       nadj=nadj+1 >*/
	    ++(*nadj);
/* SOURCE newlookup.for:1219 */
/*<       elseif(r.lt.0.0)then >*/
	} else if (feq_gen_r_d_ < (float)0.) {
/*         The slope  outcome for the spline is inconsistent with the */
/*         slope of the secant.  Force the slope to match */
/*         the slope of the secant at this point */
/* SOURCE newlookup.for:1223 */
/*<       m(1)=sr >*/
	    m[1] = sr;
/* SOURCE newlookup.for:1224 */
/*<       adjloc(1)='^' >*/
	    *(unsigned char *)&adjloc[1] = '^';
/* SOURCE newlookup.for:1225 */
/*<       nadj=nadj+1 >*/
	    ++(*nadj);
/* SOURCE newlookup.for:1226 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1227 */
/*<       endif >*/
    }
/*     Now check the interior breakpoints.  Each point has two chords. */
/* SOURCE newlookup.for:1231 */
/*<       sl=sr >*/
    sl = sr;
/* SOURCE newlookup.for:1232 */
/*<       xl=xr >*/
    xl = xr;
/* SOURCE newlookup.for:1233 */
/*<       do100i=2,n-1 >*/
    feq_gen_i_d_1 = *n - 1;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:1234 */
/*<       adjloc(i)=' ' >*/
	*(unsigned char *)&adjloc[feq_gen_i_d_] = ' ';
/* SOURCE newlookup.for:1235 */
/*<       xr=x(i+1)-x(i) >*/
	xr = x[feq_gen_i_d_ + 1] - x[feq_gen_i_d_];
/* SOURCE newlookup.for:1236 */
/*<       sr=(y(i+1)-y(i))/xr >*/
	sr = (y[feq_gen_i_d_ + 1] - y[feq_gen_i_d_]) / xr;
/*       Derivative must be zero at a local extreme */
/* SOURCE newlookup.for:1240 */
/*<       if(sl*sr.le.0.0)then >*/
	if (sl * sr <= (float)0.) {
/* SOURCE newlookup.for:1241 */
/*<       if(m(i).ne.0.d0)then >*/
	    if (m[feq_gen_i_d_] != 0.) {
/* SOURCE newlookup.for:1242 */
/*<       adjloc(i)='^' >*/
		*(unsigned char *)&adjloc[feq_gen_i_d_] = '^';
/* SOURCE newlookup.for:1243 */
/*<       nadj=nadj+1 >*/
		++(*nadj);
/* SOURCE newlookup.for:1244 */
/*<       m(i)=0.d0 >*/
		m[feq_gen_i_d_] = 0.;
/* SOURCE newlookup.for:1245 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1246 */
/*<       else >*/
	} else {
/*         Find the chord slope closest to 0.  SL and SR are of the */
/*         same sign here and both differ from 0. */
/* SOURCE newlookup.for:1250 */
/*<       s=sign(min(abs(sl),abs(sr)),sl) >*/
/* Computing MIN */
	    feq_gen_d_d_2 = abs(sl), feq_gen_d_d_3 = abs(sr);
	    feq_gen_d_d_1 = min(feq_gen_d_d_2,feq_gen_d_d_3);
	    s = d_sign(&feq_gen_d_d_1, &sl);
/* SOURCE newlookup.for:1251 */
/*<       r=m(i)/s >*/
	    feq_gen_r_d_ = m[feq_gen_i_d_] / s;
/* SOURCE newlookup.for:1252 */
/*<       if(r.gt.3.d0)then >*/
	    if (feq_gen_r_d_ > 3.) {
/* SOURCE newlookup.for:1253 */
/*<       m(i)=3.d0*s >*/
		m[feq_gen_i_d_] = s * 3.;
/* SOURCE newlookup.for:1254 */
/*<       adjloc(i)='^' >*/
		*(unsigned char *)&adjloc[feq_gen_i_d_] = '^';
/* SOURCE newlookup.for:1255 */
/*<       nadj=nadj+1 >*/
		++(*nadj);
/* SOURCE newlookup.for:1256 */
/*<       elseif(r.lt.0.d0)then >*/
	    } else if (feq_gen_r_d_ < 0.) {
/*          Computed derivative is inconsistent.   Match the */
/*          slope estimated from the secants to the left and right of */
/*          point.  We do not use a three-point slope estimate because if */
/*          a cubic spline fit has a "wild" derivative here, then so will */
/*          a parabola.  Use a weighted-slope estimate so that we get */
/*          improved accuracy if the argument increment is locally uniform. */
/* SOURCE newlookup.for:1263 */
/*<       st=(sl*xr+sr*xl)/(xl+xr) >*/
		st = (sl * xr + sr * xl) / (xl + xr);
/* SOURCE newlookup.for:1264 */
/*<       r=st/s >*/
		feq_gen_r_d_ = st / s;
/* SOURCE newlookup.for:1265 */
/*<       if(r.gt.3.d0)then >*/
		if (feq_gen_r_d_ > 3.) {
/*            Limit slope to 3 times the smaller secant slope at this point. */
/* SOURCE newlookup.for:1267 */
/*<       st=3.d0*s >*/
		    st = s * 3.;
/* SOURCE newlookup.for:1268 */
/*<       endif >*/
		}
/* SOURCE newlookup.for:1269 */
/*<       m(i)=st >*/
		m[feq_gen_i_d_] = st;
/* SOURCE newlookup.for:1270 */
/*<       adjloc(i)='^' >*/
		*(unsigned char *)&adjloc[feq_gen_i_d_] = '^';
/* SOURCE newlookup.for:1271 */
/*<       nadj=nadj+1 >*/
		++(*nadj);
/* SOURCE newlookup.for:1272 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1273 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1274 */
/*<       sl=sr >*/
	sl = sr;
/* SOURCE newlookup.for:1275 */
/*<       xl=xr >*/
	xl = xr;
/* SOURCE newlookup.for:1276 */
/*<   100 continue >*/
/* L100: */
    }
/*     Check right end.  Chord is on left and its slope was computed */
/*     in the loop just completed. */
/* SOURCE newlookup.for:1281 */
/*<       adjloc(n)=' ' >*/
    *(unsigned char *)&adjloc[*n] = ' ';
/* SOURCE newlookup.for:1282 */
/*<       if(sl.eq.0.d0)then >*/
    if (sl == 0.) {
/* SOURCE newlookup.for:1283 */
/*<       if(m(n).ne.0.d0)then >*/
	if (m[*n] != 0.) {
/*         Force derivative to 0. */
/* SOURCE newlookup.for:1285 */
/*<       m(n)=0.d0 >*/
	    m[*n] = 0.;
/* SOURCE newlookup.for:1286 */
/*<       adjloc(n)='^' >*/
	    *(unsigned char *)&adjloc[*n] = '^';
/* SOURCE newlookup.for:1287 */
/*<       nadj=nadj+1 >*/
	    ++(*nadj);
/* SOURCE newlookup.for:1288 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1289 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:1290 */
/*<       r=m(n)/sl >*/
	feq_gen_r_d_ = m[*n] / sl;
/* SOURCE newlookup.for:1291 */
/*<       if(r.gt.3.d0)then >*/
	if (feq_gen_r_d_ > 3.) {
/* SOURCE newlookup.for:1292 */
/*<       m(n)=3.d0*sl >*/
	    m[*n] = sl * 3.;
/* SOURCE newlookup.for:1293 */
/*<       adjloc(n)='^' >*/
	    *(unsigned char *)&adjloc[*n] = '^';
/* SOURCE newlookup.for:1294 */
/*<       nadj=nadj+1 >*/
	    ++(*nadj);
/* SOURCE newlookup.for:1295 */
/*<       elseif(r.lt.0.d0)then >*/
	} else if (feq_gen_r_d_ < 0.) {
/*         outcome for the spline is inconsistent with the */
/*         slope of the secant.  Force the slope to match */
/*         the slope of the secant at this point */
/* SOURCE newlookup.for:1299 */
/*<       m(n)=sl >*/
	    m[*n] = sl;
/* SOURCE newlookup.for:1300 */
/*<       adjloc(n)='^' >*/
	    *(unsigned char *)&adjloc[*n] = '^';
/* SOURCE newlookup.for:1301 */
/*<       nadj=nadj+1 >*/
	    ++(*nadj);
/* SOURCE newlookup.for:1302 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1303 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:1304 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:1305 */
/*<       end >*/
} /* vrlim_ */




/* SOURCE newlookup.for:1310 */
/*<       subroutinespline(stdout,x,y,n,lcode,lval,rcode,rval,m) >*/
/* Subroutine */ int spline_(integer *stdout, doublereal *feq_storage_x, doublereal *feq_storage_y, 
	integer *n, integer *lcode, doublereal *lval, integer *rcode, 
	doublereal *rval, doublereal *feq_storage_m)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal feq_gen_d_d_[1000], feq_gen_h_d_;
    integer j;
    doublereal l[1000], u[1000], hj, hjp1;
    extern /* Subroutine */ int trid_(doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, integer *);
    integer iflag;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__172 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__173 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__174 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Estimate the first derivative of Y wrt X at each of the */
/*     N pairs of points stored in X(*),Y(*) and store in M(*). */
/*     Use a cubic spline with specified end conditions. */
/* SOURCE newlookup.for:1319 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE newlookup.for:1322 */
/*<       integerlcode,n,rcode,stdout >*/
/* SOURCE newlookup.for:1323 */
/*<       real*8lval,m(n),rval,x(n),y(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     X      - Abscissas for cubic spline */
/*     Y      - Ordinate values for cubic spline */
/*     N      - Number of points defining the cubic spline */
/*     LCODE  - Code for left hand end condition */
/*     LVAL   - Value of the left hand end condition */
/*     RCODE  - Code for the right-hand end condition */
/*     RVAL   - Value of the right-hand end condition */
/*     M      - Vector of first derivatives */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE newlookup.for:1337 */
/*<       integermaxn >*/
/* SOURCE newlookup.for:1338 */
/*<       parameter(maxn=1000) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE newlookup.for:1341 */
/*<       integeriflag,j >*/
/* SOURCE newlookup.for:1342 */
/*<       doubleprecisiond(maxn),h,hj,hjp1,l(maxn),u(maxn) >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE newlookup.for:1345 */
/*<       externaltrid >*/
/* *********************************************************************** */
/* SOURCE newlookup.for:1347 */
/*<       if(n.gt.maxn)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> m(feq_storage_m, 1);

    feq::IndexedPointer<doublereal> y(feq_storage_y, 1);

    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
    if (*n > 1000) {
/* SOURCE newlookup.for:1348 */
/*<       write(stdout,*)'TOO MANY POINTS FOR SUBROUTINE SPLINE' >*/
	feq_gen_io_d__172.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__172);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("TOO MANY POINTS FOR SUBROUTINE SPLINE"), (ftnlen)
		37);
	e_wsle();
/* SOURCE newlookup.for:1349 */
/*<        >*/
	feq_gen_io_d__173.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__173);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("SPACE FOR "), (ftnlen)10);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" POINTS BUT "), (ftnlen)12);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*n), (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" POINTS"), (ftnlen)7);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" REQUESTED"), (ftnlen)10);
	e_wsle();
/* SOURCE newlookup.for:1351 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE newlookup.for:1352 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:1353 */
/*<       if(n.lt.2)then >*/
    if (*n < 2) {
/* SOURCE newlookup.for:1354 */
/*<        >*/
	feq_gen_io_d__174.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__174);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("LESS THAN TWO POINTS IN SUB. SPLINE. AT LEAST"), 
		(ftnlen)45);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TWO ARE REQUIRED."), (ftnlen)18);
	e_wsle();
/* SOURCE newlookup.for:1356 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE newlookup.for:1357 */
/*<       endif >*/
    }
/*     COMPUTE THE VALUES IN L, D, U, AND M.  M SERVES AS THE RIGHT */
/*     HAND SIDE VECTOR FOR NOW */
/* SOURCE newlookup.for:1363 */
/*<       hj=x(2)-x(1) >*/
    hj = x[2] - x[1];
/* SOURCE newlookup.for:1364 */
/*<       do100j=2,n-1 >*/
    feq_gen_i_d_1 = *n - 1;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE newlookup.for:1365 */
/*<       hjp1=x(j+1)-x(j) >*/
	hjp1 = x[j + 1] - x[j];
/* SOURCE newlookup.for:1366 */
/*<       l(j)=hjp1/(hj+hjp1) >*/
	l[j - 1] = hjp1 / (hj + hjp1);
/* SOURCE newlookup.for:1367 */
/*<       u(j)=1.d0-l(j) >*/
	u[j - 1] = 1. - l[j - 1];
/* SOURCE newlookup.for:1368 */
/*<       d(j)=2.d0 >*/
	feq_gen_d_d_[j - 1] = 2.;
/* SOURCE newlookup.for:1369 */
/*<       m(j)=3.d0*(l(j)*(y(j)-y(j-1))/hj+u(j)*(y(j+1)-y(j))/hjp1) >*/
	m[j] = (l[j - 1] * (y[j] - y[j - 1]) / hj + u[j - 1] * (y[j + 1] - y[
		j]) / hjp1) * 3.;
/* SOURCE newlookup.for:1372 */
/*<       hj=hjp1 >*/
	hj = hjp1;
/* SOURCE newlookup.for:1373 */
/*<   100 continue >*/
/* L100: */
    }
/*     DO THE LEFT END CONDITION */
/* SOURCE newlookup.for:1377 */
/*<       d(1)=2.d0 >*/
    feq_gen_d_d_[0] = 2.;
/* SOURCE newlookup.for:1378 */
/*<       h=x(2)-x(1) >*/
    feq_gen_h_d_ = x[2] - x[1];
/* SOURCE newlookup.for:1379 */
/*<       if(lcode.eq.1)then >*/
    if (*lcode == 1) {
/*       FIRST DERIVATIVE GIVEN */
/* SOURCE newlookup.for:1382 */
/*<       u(1)=0.d0 >*/
	u[0] = 0.;
/* SOURCE newlookup.for:1383 */
/*<       m(1)=2.d0*lval >*/
	m[1] = *lval * 2.;
/* SOURCE newlookup.for:1385 */
/*<       elseif(lcode.eq.2)then >*/
    } else if (*lcode == 2) {
/*       SECOND DERIVATIVE GIVEN */
/* SOURCE newlookup.for:1388 */
/*<       u(1)=1.d0 >*/
	u[0] = 1.;
/* SOURCE newlookup.for:1389 */
/*<       m(1)=3.d0*(y(2)-y(1))/h-0.5d0*h*lval >*/
	m[1] = (y[2] - y[1]) * 3. / feq_gen_h_d_ - feq_gen_h_d_ * .5 * *lval;
/* SOURCE newlookup.for:1391 */
/*<       else >*/
    } else {
/*       SPECIAL END CASE */
/* SOURCE newlookup.for:1394 */
/*<       u(1)=4.d0*(1.d0-lval)/(4.d0-lval) >*/
	u[0] = (1. - *lval) * 4. / (4. - *lval);
/* SOURCE newlookup.for:1395 */
/*<       m(1)=6.d0*(2.d0-lval)*(y(2)-y(1))/((4.d0-lval)*h) >*/
	m[1] = (2. - *lval) * 6. * (y[2] - y[1]) / ((4. - *lval) * feq_gen_h_d_);
/* SOURCE newlookup.for:1397 */
/*<       endif >*/
    }
/*     DO RIGHT END CONDITION */
/* SOURCE newlookup.for:1402 */
/*<       d(n)=2.d0 >*/
    feq_gen_d_d_[*n - 1] = 2.;
/* SOURCE newlookup.for:1403 */
/*<       h=x(n)-x(n-1) >*/
    feq_gen_h_d_ = x[*n] - x[*n - 1];
/* SOURCE newlookup.for:1404 */
/*<       if(rcode.eq.1)then >*/
    if (*rcode == 1) {
/* SOURCE newlookup.for:1405 */
/*<       l(n)=0.d0 >*/
	l[*n - 1] = 0.;
/* SOURCE newlookup.for:1406 */
/*<       m(n)=2.d0*rval >*/
	m[*n] = *rval * 2.;
/* SOURCE newlookup.for:1407 */
/*<       elseif(rcode.eq.2)then >*/
    } else if (*rcode == 2) {
/* SOURCE newlookup.for:1408 */
/*<       l(n)=1.d0 >*/
	l[*n - 1] = 1.;
/* SOURCE newlookup.for:1409 */
/*<       m(n)=3.d0*(y(n)-y(n-1))/h+0.5d0*h*rval >*/
	m[*n] = (y[*n] - y[*n - 1]) * 3. / feq_gen_h_d_ + feq_gen_h_d_ * .5 * *rval;
/* SOURCE newlookup.for:1410 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:1411 */
/*<       l(n)=4.d0*(1.d0-rval)/(4.d0-rval) >*/
	l[*n - 1] = (1. - *rval) * 4. / (4. - *rval);
/* SOURCE newlookup.for:1412 */
/*<       m(n)=6.d0*(2.d0-rval)*(y(n)-y(n-1))/((4.d0-rval)*h) >*/
	m[*n] = (2. - *rval) * 6. * (y[*n] - y[*n - 1]) / ((4. - *rval) * feq_gen_h_d_)
		;
/* SOURCE newlookup.for:1414 */
/*<       endif >*/
    }
/*     FIND THE SOLUTION */
/* SOURCE newlookup.for:1418 */
/*<       calltrid(l,u,n,d,m,iflag) >*/
    trid_(l, u, n, feq_gen_d_d_, &m[1], &iflag);
/* SOURCE newlookup.for:1423 */
/*<       if(iflag.eq.1)then >*/
    if (iflag == 1) {
/* SOURCE newlookup.for:1424 */
/*<       write(stdout,*)'SINGULAR MATRIX IN SUBROUTINE SPLINE' >*/
	feq_gen_io_d__183.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__183);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("SINGULAR MATRIX IN SUBROUTINE SPLINE"), (ftnlen)
		36);
	e_wsle();
/* SOURCE newlookup.for:1425 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE newlookup.for:1426 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:1428 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:1430 */
/*<       end >*/
} /* spline_ */




/* SOURCE newlookup.for:1435 */
/*<       subroutinetrid(sb,sp,n,md,rhs,iflag) >*/
/* Subroutine */ int trid_(doublereal *feq_storage_sb, doublereal *feq_storage_sp, integer *n, 
	doublereal *feq_storage_md, doublereal *feq_storage_rhs, integer *iflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer k;
    doublereal rat;

/*     + + + purpose + + + */
/*     Solve the tridiagonal system with coefficient matrix */
/*     given by sb, md, sp.  sb(1) and sp(n) are not used. */
/*     The right hand side is contained in rhs. n gives the number of */
/*     equations.  md and rhs are changed in the solution */
/*     process.  rhs is used to return the solution. */
/*     Based on Conte and DeBoor, 1st Ed. p. 122. */
/*     iflag=1 signals a singular matrix */
/* SOURCE newlookup.for:1450 */
/*<       implicitnone >*/
/*     + + + dummy arguments + + + */
/* SOURCE newlookup.for:1453 */
/*<       integeriflag,n >*/
/* SOURCE newlookup.for:1454 */
/*<       doubleprecisionrhs(n),md(n),sb(n),sp(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     sb    - Sub-diagonal elements */
/*     sp    - Super diagonal elements */
/*     n      - Number of equations */
/*     md   - main diagonal elements for a tri-diagonal matrix */
/*     rhs      - Right hand side vector */
/*     iflag  - error flag */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE newlookup.for:1465 */
/*<       integerk >*/
/* SOURCE newlookup.for:1466 */
/*<       doubleprecisionrat >*/
/* *********************************************************************** */
/* SOURCE newlookup.for:1468 */
/*<       iflag=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> rhs(feq_storage_rhs, 1);

    feq::IndexedPointer<doublereal> md(feq_storage_md, 1);

    feq::IndexedPointer<doublereal> sp(feq_storage_sp, 1);

    feq::IndexedPointer<doublereal> sb(feq_storage_sb, 1);

    /* Function Body */
    *iflag = 0;
/* SOURCE newlookup.for:1470 */
/*<       if(n.eq.1)then >*/
    if (*n == 1) {
/* SOURCE newlookup.for:1471 */
/*<       if(md(1).eq.0.d0)then >*/
	if (md[1] == 0.) {
/* SOURCE newlookup.for:1472 */
/*<       iflag=1 >*/
	    *iflag = 1;
/* SOURCE newlookup.for:1473 */
/*<       return >*/
	    return 0;
/* SOURCE newlookup.for:1474 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1476 */
/*<       rhs(1)=rhs(1)/md(1) >*/
	rhs[1] /= md[1];
/* SOURCE newlookup.for:1477 */
/*<       return >*/
	return 0;
/* SOURCE newlookup.for:1478 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:1480 */
/*<       do11k=2,n >*/
	feq_gen_i_d_1 = *n;
	for (k = 2; k <= feq_gen_i_d_1; ++k) {
/* SOURCE newlookup.for:1481 */
/*<       if(md(k-1).eq.0.d0)then >*/
	    if (md[k - 1] == 0.) {
/* SOURCE newlookup.for:1482 */
/*<       iflag=1 >*/
		*iflag = 1;
/* SOURCE newlookup.for:1483 */
/*<       return >*/
		return 0;
/* SOURCE newlookup.for:1484 */
/*<       endif >*/
	    }
/* SOURCE newlookup.for:1485 */
/*<       rat=-sb(k)/md(k-1) >*/
	    rat = -sb[k] / md[k - 1];
/* SOURCE newlookup.for:1486 */
/*<       md(k)=md(k)+rat*sp(k-1) >*/
	    md[k] += rat * sp[k - 1];
/* SOURCE newlookup.for:1487 */
/*<       rhs(k)=rhs(k)+rat*rhs(k-1) >*/
	    rhs[k] += rat * rhs[k - 1];
/* SOURCE newlookup.for:1488 */
/*<    11 continue >*/
/* L11: */
	}
/* SOURCE newlookup.for:1490 */
/*<       if(md(n).eq.0.d0)then >*/
	if (md[*n] == 0.) {
/* SOURCE newlookup.for:1491 */
/*<       iflag=1 >*/
	    *iflag = 1;
/* SOURCE newlookup.for:1492 */
/*<       return >*/
	    return 0;
/* SOURCE newlookup.for:1493 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1494 */
/*<       rhs(n)=rhs(n)/md(n) >*/
	rhs[*n] /= md[*n];
/* SOURCE newlookup.for:1495 */
/*<       do12k=n-1,1,-1 >*/
	for (k = *n - 1; k >= 1; --k) {
/* SOURCE newlookup.for:1496 */
/*<       rhs(k)=(rhs(k)-sp(k)*rhs(k+1))/md(k) >*/
	    rhs[k] = (rhs[k] - sp[k] * rhs[k + 1]) / md[k];
/* SOURCE newlookup.for:1497 */
/*<    12 continue >*/
/* L12: */
	}
/* SOURCE newlookup.for:1498 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:1500 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:1502 */
/*<       end >*/
} /* trid_ */




/* SOURCE newlookup.for:1507 */
/*<        >*/
/* Subroutine */ int feq_gen_store_xsec_tab_d_(integer *stdout, integer *ndep, integer 
	*feq_gen_type_d_, char *tabid, integer *tab, real *stat, real *zmin, real *
	feq_gen_slot_depth_d_, char *gisid, doublereal *easting, doublereal *northing, 
	real *feq_storage_xst, real *feq_gen_max_arg_d_, char *zone, char *hgrid, char *vdatum, 
	char *unitsys, char *basis, integer *ftp, ftnlen tabid_len, ftnlen 
	gisid_len, ftnlen zone_len, ftnlen hgrid_len, ftnlen vdatum_len, 
	ftnlen unitsys_len, ftnlen basis_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*BUG* type=\002,i5,\002in store_xsec_tab \
invalid.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;
    extern /* Subroutine */ int feq_gen_put_string_in_ft_d_(integer *, char *, ftnlen);
    integer feq_gen_feql_select2_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int feq_gen_put_dp_in_ft_d_(integer *, doublereal *), 
	    feq_gen_put_chr8_in_ft_d_(integer *, char *, ftnlen);
    integer nstore;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__193 = { 0, 0, 0, fmt_50, 0 };


/*     Store a cross section table in the FTAB/ITAB system */
/* SOURCE newlookup.for:1514 */
/*<       implicitnone >*/
/*     + + + parameters + + + */
/* INCLUDE newlookup.for:1516 */
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
/* SOURCE newlookup.for:1518 */
/*<       integerstdout,ndep,type,tab,ftp >*/
/* SOURCE newlookup.for:1519 */
/*<       realstat,xst(pmxpnt,pmxelm),zmin,slot_depth,max_arg >*/
/* SOURCE newlookup.for:1520 */
/*<       real*8easting,northing >*/
/* SOURCE newlookup.for:1521 */
/*<        >*/
/* INCLUDE newlookup.for:1525 */
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
/* INCLUDE newlookup.for:1526 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     Local */
/* SOURCE newlookup.for:1529 */
/*<       integeri,j,nstore >*/
/*     ***********************formats************************************ */
/* SOURCE newlookup.for:1507 */
/*<       integer feql_select2 >*/
/* SOURCE newlookup.for:1531 */
/*<    50 format(/,'*BUG* type=',i5,'in store_xsec_tab invalid.') >*/
/* *********************************************************************** */
/* SOURCE newlookup.for:1534 */
/*<       ftpnt(tab)=ftp >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> xst(feq_storage_xst, 1000);

    /* Function Body */
/* L50: */
    ftablea_1.ftpnt[*tab - 1] = *ftp;
/* SOURCE newlookup.for:1535 */
/*<       itab(ftp+1)=tab >*/
    itab[*ftp + 1] = *tab;
/* SOURCE newlookup.for:1536 */
/*<       itab(ftp+2)=type >*/
    itab[*ftp + 2] = *feq_gen_type_d_;
/* SOURCE newlookup.for:1537 */
/*<       itab(ftp+3)=ftp+xtioff >*/
    itab[*ftp + 3] = *ftp + 32;
/* SOURCE newlookup.for:1538 */
/*<       ftab(ftp+4)=stat >*/
    ftab[*ftp + 4] = *stat;
/*     Apply vertical datum shift.  Must default to 0.0! */
/* SOURCE newlookup.for:1540 */
/*<       ftab(ftp+5)=zmin >*/
    ftab[*ftp + 5] = *zmin;
/*     Store the maximum unextrapolated argument in the */
/*     cross-section function table. */
/* SOURCE newlookup.for:1543 */
/*<       ftab(ftp+6)=max_arg >*/
    ftab[*ftp + 6] = *feq_gen_max_arg_d_;
/*     Put the slot depth into the table--Note: SLOT_DEPTH <=0.0 */
/* SOURCE newlookup.for:1545 */
/*<       ftab(ftp+7)=slot_depth >*/
    ftab[*ftp + 7] = *feq_gen_slot_depth_d_;
/*     Put the easting coordinate value in the table. */
/* SOURCE newlookup.for:1547 */
/*<       callput_dp_in_ft(ftp+8,easting) >*/
    feq_gen_i_d_1 = *ftp + 8;
    feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, easting);
/*     Put the northing coordinate value in the table */
/* SOURCE newlookup.for:1549 */
/*<       callput_dp_in_ft(ftp+10,northing) >*/
    feq_gen_i_d_1 = *ftp + 10;
    feq_gen_put_dp_in_ft_d_(&feq_gen_i_d_1, northing);
/*     Store the GIS identifier string.  May be blank. */
/* SOURCE newlookup.for:1552 */
/*<       callput_string_in_ft(ftp+12,gisid) >*/
    feq_gen_i_d_1 = *ftp + 12;
    feq_gen_put_string_in_ft_d_(&feq_gen_i_d_1, gisid, (ftnlen)16);
/*     Store the table name in the table. */
/* SOURCE newlookup.for:1554 */
/*<       callput_string_in_ft(ftp+16,tabid) >*/
    feq_gen_i_d_1 = *ftp + 16;
    feq_gen_put_string_in_ft_d_(&feq_gen_i_d_1, tabid, (ftnlen)16);
/*     Store the zone, grid, datum, and unitsys information */
/* SOURCE newlookup.for:1557 */
/*<       callput_chr8_in_ft(ftp+22,zone) >*/
    feq_gen_i_d_1 = *ftp + 22;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, zone, (ftnlen)8);
/* SOURCE newlookup.for:1558 */
/*<       callput_chr8_in_ft(ftp+24,hgrid) >*/
    feq_gen_i_d_1 = *ftp + 24;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, hgrid, (ftnlen)8);
/* SOURCE newlookup.for:1559 */
/*<       callput_chr8_in_ft(ftp+26,vdatum) >*/
    feq_gen_i_d_1 = *ftp + 26;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, vdatum, (ftnlen)8);
/* SOURCE newlookup.for:1560 */
/*<       callput_chr8_in_ft(ftp+28,unitsys) >*/
    feq_gen_i_d_1 = *ftp + 28;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, unitsys, (ftnlen)8);
/* SOURCE newlookup.for:1561 */
/*<       callput_chr8_in_ft(ftp+30,basis) >*/
    feq_gen_i_d_1 = *ftp + 30;
    feq_gen_put_chr8_in_ft_d_(&feq_gen_i_d_1, basis, (ftnlen)8);
/*     Set the offset to the extra derivatives */
/*      write(stdout,*) 'store_xsec_tab: storing type=',type */
/* SOURCE newlookup.for:1566 */
/*<       if(type.le.25)then >*/
    if (*feq_gen_type_d_ <= 25) {
/* SOURCE newlookup.for:1567 */
/*<       itab(ftp+21)=0 >*/
	itab[*ftp + 21] = 0;
/* SOURCE newlookup.for:1568 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:1569 */
/*<       itab(ftp+21)=offvec(type-10) >*/
	itab[*ftp + 21] = offcom_1.offvec[*feq_gen_type_d_ - 11];
/*        write(stdout,*) ' doff=',itab(ftp+21) */
/* SOURCE newlookup.for:1571 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:1572 */
/*<       nstore=offvec(type) >*/
    nstore = offcom_1.offvec[*feq_gen_type_d_ - 1];
/* SOURCE newlookup.for:1573 */
/*<       i=ftp+xtioff >*/
    feq_gen_i_d_ = *ftp + 32;
/* SOURCE newlookup.for:1574 */
/*<       do200j=1,ndep >*/
    feq_gen_i_d_1 = *ndep;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE newlookup.for:1575 */
/*<       ftab(i+0)=xst(j,1) >*/
	ftab[feq_gen_i_d_] = xst[j + 999];
/* SOURCE newlookup.for:1576 */
/*<       ftab(i+1)=xst(j,2) >*/
	ftab[feq_gen_i_d_ + 1] = xst[j + 1998];
/* SOURCE newlookup.for:1577 */
/*<       ftab(i+2)=xst(j,3) >*/
	ftab[feq_gen_i_d_ + 2] = xst[j + 2997];
/* SOURCE newlookup.for:1578 */
/*<       ftab(i+3)=xst(j,5) >*/
	ftab[feq_gen_i_d_ + 3] = xst[j + 4995];
/* SOURCE newlookup.for:1579 */
/*<       ftab(i+4)=xst(j,6) >*/
	ftab[feq_gen_i_d_ + 4] = xst[j + 5994];
/*       REMAINDER OF THE TABLE DEPENDS ON THE TYPE. */
/* SOURCE newlookup.for:1582 */
/*<       feql_select2=type >*/
	feq_gen_feql_select2_d_ = *feq_gen_type_d_;
/* SOURCE newlookup.for:1582 */
/*<       if(feql_select2.eq.20)then >*/
	if (feq_gen_feql_select2_d_ == 20) {
/*         TABLE TYPE 20.  EVERYTHING ALREADY STORED */
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.21)then >*/
	} else if (feq_gen_feql_select2_d_ == 21) {
/*         TABLE TYPE 1 AND 21.  ADD STORAGE OF THE FIRST MOMENT OF */
/*         AREA ABOUT THE WATER SURFACE. */
/* SOURCE newlookup.for:1594 */
/*<       ftab(i+5)=xst(j,4) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 3996];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.22)then >*/
	} else if (feq_gen_feql_select2_d_ == 22) {
/*         TABLE TYPE 12 AND 22.  ADD FIRST MOMENT, ALPHA, AND */
/*         CRITICAL FLOW */
/* SOURCE newlookup.for:1599 */
/*<       ftab(i+5)=xst(j,4) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 3996];
/* SOURCE newlookup.for:1600 */
/*<       ftab(i+6)=xst(j,7) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 6993];
/* SOURCE newlookup.for:1601 */
/*<       ftab(i+7)=xst(j,13) >*/
	    ftab[feq_gen_i_d_ + 7] = xst[j + 12987];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.23)then >*/
	} else if (feq_gen_feql_select2_d_ == 23) {
/*         TABLE TYPE 23.  ADD THE CURVILINEAR ELEMENTS: MA AND MQ */
/* SOURCE newlookup.for:1605 */
/*<       ftab(i+5)=xst(j,14) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 13986];
/* SOURCE newlookup.for:1606 */
/*<       ftab(i+6)=xst(j,15) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 14985];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.24)then >*/
	} else if (feq_gen_feql_select2_d_ == 24) {
/*         TABLE TYPE 24.  ADD FIRST MOMENT, MA, AND MQ */
/* SOURCE newlookup.for:1610 */
/*<       ftab(i+5)=xst(j,4) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 3996];
/* SOURCE newlookup.for:1611 */
/*<       ftab(i+6)=xst(j,14) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 13986];
/* SOURCE newlookup.for:1612 */
/*<       ftab(i+7)=xst(j,15) >*/
	    ftab[feq_gen_i_d_ + 7] = xst[j + 14985];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.25)then >*/
	} else if (feq_gen_feql_select2_d_ == 25) {
/*         TABLE TYPE 25. ADD FIRST MOMENT, ALPHA, CRITICAL FLOW, MA, */
/*         AND MQ. */
/* SOURCE newlookup.for:1617 */
/*<       ftab(i+5)=xst(j,4) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 3996];
/* SOURCE newlookup.for:1618 */
/*<       ftab(i+6)=xst(j,7) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 6993];
/* SOURCE newlookup.for:1619 */
/*<       ftab(i+7)=xst(j,13) >*/
	    ftab[feq_gen_i_d_ + 7] = xst[j + 12987];
/* SOURCE newlookup.for:1620 */
/*<       ftab(i+8)=xst(j,14) >*/
	    ftab[feq_gen_i_d_ + 8] = xst[j + 13986];
/* SOURCE newlookup.for:1621 */
/*<       ftab(i+9)=xst(j,15) >*/
	    ftab[feq_gen_i_d_ + 9] = xst[j + 14985];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.30)then >*/
	} else if (feq_gen_feql_select2_d_ == 30) {
/*         TABLE TYPE 30. store dkh/dy and dbeta/dy from cubic-spline fit. */
/* SOURCE newlookup.for:1626 */
/*<       ftab(i+5)=xst(j,18) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 17982];
/* SOURCE newlookup.for:1627 */
/*<       ftab(i+6)=xst(j,20) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 19980];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.31)then >*/
	} else if (feq_gen_feql_select2_d_ == 31) {
/*         TABLE 31.  add first moment, dkh/dy and dbeta/dy from cubic-spline fit */
/* SOURCE newlookup.for:1631 */
/*<       ftab(i+5)=xst(j,4) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 3996];
/* SOURCE newlookup.for:1632 */
/*<       ftab(i+6)=xst(j,18) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 17982];
/* SOURCE newlookup.for:1633 */
/*<       ftab(i+7)=xst(j,20) >*/
	    ftab[feq_gen_i_d_ + 7] = xst[j + 19980];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.32)then >*/
	} else if (feq_gen_feql_select2_d_ == 32) {
/*         TABLE type 32. add first moment, alpha, critical flow. dkh/dy, dbeta/dy, dalpha/dy from cubic-splin
e fit */
/* SOURCE newlookup.for:1637 */
/*<       ftab(i+5)=xst(j,4) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 3996];
/* SOURCE newlookup.for:1638 */
/*<       ftab(i+6)=xst(j,7) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 6993];
/* SOURCE newlookup.for:1639 */
/*<       ftab(i+7)=xst(j,13) >*/
	    ftab[feq_gen_i_d_ + 7] = xst[j + 12987];
/* SOURCE newlookup.for:1640 */
/*<       ftab(i+8)=xst(j,18) >*/
	    ftab[feq_gen_i_d_ + 8] = xst[j + 17982];
/* SOURCE newlookup.for:1641 */
/*<       ftab(i+9)=xst(j,20) >*/
	    ftab[feq_gen_i_d_ + 9] = xst[j + 19980];
/* SOURCE newlookup.for:1642 */
/*<       ftab(i+10)=xst(j,19) >*/
	    ftab[feq_gen_i_d_ + 10] = xst[j + 18981];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.33)then >*/
	} else if (feq_gen_feql_select2_d_ == 33) {
/*         TABLE TYPE 33. add ma, mq.  dkh/dy, dbeta/dy, dma/dy, and dmq/dy from cubic-spline fit */
/* SOURCE newlookup.for:1646 */
/*<       ftab(i+5)=xst(j,14) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 13986];
/* SOURCE newlookup.for:1647 */
/*<       ftab(i+6)=xst(j,15) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 14985];
/* SOURCE newlookup.for:1648 */
/*<       ftab(i+7)=xst(j,18) >*/
	    ftab[feq_gen_i_d_ + 7] = xst[j + 17982];
/* SOURCE newlookup.for:1649 */
/*<       ftab(i+8)=xst(j,20) >*/
	    ftab[feq_gen_i_d_ + 8] = xst[j + 19980];
/* SOURCE newlookup.for:1650 */
/*<       ftab(i+9)=xst(j,21) >*/
	    ftab[feq_gen_i_d_ + 9] = xst[j + 20979];
/* SOURCE newlookup.for:1651 */
/*<       ftab(i+10)=xst(j,22) >*/
	    ftab[feq_gen_i_d_ + 10] = xst[j + 21978];
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.34)then >*/
	} else if (feq_gen_feql_select2_d_ == 34) {
/*         TABLE TYPE 34. add first moment, ma, mq, dkh/dy, dbeta/dy, dma/dy, and dmq/dy from cubic-spline fit
 */
/* SOURCE newlookup.for:1655 */
/*<       ftab(i+5)=xst(j,4) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 3996];
/* SOURCE newlookup.for:1656 */
/*<       ftab(i+6)=xst(j,14) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 13986];
/* SOURCE newlookup.for:1657 */
/*<       ftab(i+7)=xst(j,15) >*/
	    ftab[feq_gen_i_d_ + 7] = xst[j + 14985];
/* SOURCE newlookup.for:1658 */
/*<       ftab(i+8)=xst(j,18) >*/
	    ftab[feq_gen_i_d_ + 8] = xst[j + 17982];
/* SOURCE newlookup.for:1659 */
/*<       ftab(i+9)=xst(j,20) >*/
	    ftab[feq_gen_i_d_ + 9] = xst[j + 19980];
/* SOURCE newlookup.for:1660 */
/*<       ftab(i+10)=xst(j,21) >*/
	    ftab[feq_gen_i_d_ + 10] = xst[j + 20979];
/* SOURCE newlookup.for:1661 */
/*<       ftab(i+11)=xst(j,22) >*/
	    ftab[feq_gen_i_d_ + 11] = xst[j + 21978];
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
/* SOURCE newlookup.for:1582 */
/*<       elseif(feql_select2.eq.35)then >*/
	} else if (feq_gen_feql_select2_d_ == 35) {
/*         TABLE TYPE 35. add first moment, alpha, critical flow, ma, mq, dkh/dy, dbeta/dy, dma/dy, dma/dy, an
d dalpha/dy from cubic-spline fit */
/* SOURCE newlookup.for:1688 */
/*<       ftab(i+5)=xst(j,4) >*/
	    ftab[feq_gen_i_d_ + 5] = xst[j + 3996];
/* SOURCE newlookup.for:1689 */
/*<       ftab(i+6)=xst(j,7) >*/
	    ftab[feq_gen_i_d_ + 6] = xst[j + 6993];
/* SOURCE newlookup.for:1690 */
/*<       ftab(i+7)=xst(j,13) >*/
	    ftab[feq_gen_i_d_ + 7] = xst[j + 12987];
/* SOURCE newlookup.for:1691 */
/*<       ftab(i+8)=xst(j,14) >*/
	    ftab[feq_gen_i_d_ + 8] = xst[j + 13986];
/* SOURCE newlookup.for:1692 */
/*<       ftab(i+9)=xst(j,15) >*/
	    ftab[feq_gen_i_d_ + 9] = xst[j + 14985];
/* SOURCE newlookup.for:1693 */
/*<       ftab(i+10)=xst(j,18) >*/
	    ftab[feq_gen_i_d_ + 10] = xst[j + 17982];
/* SOURCE newlookup.for:1694 */
/*<       ftab(i+11)=xst(j,20) >*/
	    ftab[feq_gen_i_d_ + 11] = xst[j + 19980];
/* SOURCE newlookup.for:1695 */
/*<       ftab(i+12)=xst(j,21) >*/
	    ftab[feq_gen_i_d_ + 12] = xst[j + 20979];
/* SOURCE newlookup.for:1696 */
/*<       ftab(i+13)=xst(j,22) >*/
	    ftab[feq_gen_i_d_ + 13] = xst[j + 21978];
/* SOURCE newlookup.for:1697 */
/*<       ftab(i+14)=xst(j,19) >*/
	    ftab[feq_gen_i_d_ + 14] = xst[j + 18981];
/* SOURCE newlookup.for:1582 */
/*<       else >*/
	} else {
/* SOURCE newlookup.for:1585 */
/*<       write(stdout,50)type >*/
	    feq_gen_io_d__193.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__193);
	    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_type_d_), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE newlookup.for:1586 */
/*<       stop'Abnormal stop. Bug found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE newlookup.for:1698 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1700 */
/*<       i=i+nstore >*/
	feq_gen_i_d_ += nstore;
/* SOURCE newlookup.for:1701 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE newlookup.for:1702 */
/*<       itab(ftp)=i-nstore >*/
    itab[*ftp] = feq_gen_i_d_ - nstore;
/* SOURCE newlookup.for:1703 */
/*<       ftp=i >*/
    *ftp = feq_gen_i_d_;
/* SOURCE newlookup.for:1705 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:1706 */
/*<       end >*/
} /* store_xsec_tab__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE newlookup.for:1711 */
/*<       subroutinedo_upgrade_xsec_tab(stdout,ip,verbose,ftp,eflag) >*/
/* Subroutine */ int feq_gen_do_upgrade_xsec_tab_d_(integer *stdout, integer *ip, 
	integer *verbose, integer *ftp, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Possible problem on upgrade. Errors are\
:\002,/,\002        kh      beta     alpha        ma        mq\002)";
    static char fmt_52[] = "(5(1pe10.2))";
    static char fmt_54[] = "(\002 Upgrade is OK.\002)";
    static char fmt_60[] = "(/,\002 Possible problem on upgrade. Errors are\
:\002,/,\002        kh      beta\002)";
    static char fmt_62[] = "(2(1pe10.2))";
    static char fmt_70[] = "(/,\002 Possible problem on upgrade. Errors are\
:\002,/,\002        kh      beta        ma        mq\002)";
    static char fmt_72[] = "(4(1pe10.2))";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[8];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    char betaflag[1*999];
    extern /* Character */ VOID feq_gen_get_chr8_from_ft_d_(char *, ftnlen, integer *);
    real feq_gen_beta_err_d_;
    doublereal northing;
    integer feq_gen_i_d_;
    char alphaflag[1*999];
    real feq_gen_alpha_err_d_;
    integer ha, la;
    real al, am, ar, jl, jm, kl, km, jr, kr, tl, tm, yl, ym, tr, yr, 
	    feq_gen_max_ma_err_d_, feq_gen_max_kh_err_d_, feq_gen_max_mq_err_d_, feq_gen_slot_depth_d_;
    integer tab;
    real mal, mam, dkl, dkm;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
    real khl, khm, mar, dkr, qcl, dtl, khr, dtm, qcm, qcr, mql, mqm, dtr, mqr,
	     xst[21978]	/* was [999][22] */;
    integer feq_gen_feql_select3_d_, feq_gen_feql_select4_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    real dmal, dmam;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real dkhl, dkhm, dmar;
    integer ndep;
    real dkhr, dmql, dmqm;
    integer xoff;
    real dmqr, stat;
    char zone[8];
    real zmin;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real feq_gen_max_beta_err_d_;
    char tabid[16];
    real betal, betam, betar;
    char gisid[16], hgrid[8], basis[8];
    extern /* Subroutine */ int xlkt21_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *), xlkt23_(integer *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *), xlkt25_(integer *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *);
    real feq_gen_max_alpha_err_d_;
    char maflag[1*999];
    real dbetal, dbetam;
    char khflag[1*999];
    real dbetar, alphal, alpham, feq_gen_ma_err_d_, alphar, feq_gen_kh_err_d_;
    char mqflag[1*999];
    real feq_gen_mq_err_d_;
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);
    char vdatum[8];
    extern /* Subroutine */ int feq_gen_store_xsec_tab_d_(integer *, integer *, 
	    integer *, char *, integer *, real *, real *, real *, char *, 
	    doublereal *, doublereal *, real *, real *, char *, char *, char *
	    , char *, char *, integer *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    real dalphal, dalpham, dalphar, feq_gen_max_arg_d_;
    doublereal easting;
    extern /* Subroutine */ int xsecfit_(integer *, integer *, integer *, 
	    real *, char *, char *, char *, char *, char *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__262 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__263 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__264 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__281 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__282 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__283 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__295 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__296 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__297 = { 0, 0, 0, fmt_54, 0 };


/*     Convert tables of 20-25 to 30-35.  The table has just been added */
/*     to the ftab/itab system.  We will extract the data to  local arrays, */
/*     compute the additional values, and then store the table into the */
/*     current location of the table. */

/* SOURCE newlookup.for:1721 */
/*<       implicitnone >*/
/* SOURCE newlookup.for:1723 */
/*<       integerstdout,ip,ftp,eflag,verbose >*/
/* INCLUDE newlookup.for:1725 */
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
/* INCLUDE newlookup.for:1726 */
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
/* INCLUDE newlookup.for:1727 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* SOURCE newlookup.for:1729 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE newlookup.for:1730 */
/*<       character*16get_string_from_ft >*/
/* SOURCE newlookup.for:1731 */
/*<       character*8get_chr8_from_ft >*/
/* SOURCE newlookup.for:1732 */
/*<       externalget_string_from_ft,get_dp_from_ft,get_chr8_from_ft >*/
/*     Local */
/* SOURCE newlookup.for:1736 */
/*<       integeri,la,ha,type,xoff,ndep,tab >*/
/* SOURCE newlookup.for:1737 */
/*<       realxst(pmxpnt,pmxelm),stat,zmin,slot_depth >*/
/* SOURCE newlookup.for:1738 */
/*<        >*/
/* SOURCE newlookup.for:1750 */
/*<       real*8easting,northing >*/
/* SOURCE newlookup.for:1752 */
/*<        >*/
/*     ***************************formats******************************** */
/* SOURCE newlookup.for:1711 */
/*<       integer feql_select3 >*/
/* SOURCE newlookup.for:1711 */
/*<       integer feql_select4 >*/
/* SOURCE newlookup.for:1758 */
/*<    50  >*/
/* SOURCE newlookup.for:1760 */
/*<    52 format(5(1pe10.2)) >*/
/* SOURCE newlookup.for:1761 */
/*<    54 format(' Upgrade is OK.') >*/
/* SOURCE newlookup.for:1762 */
/*<    60  >*/
/* SOURCE newlookup.for:1764 */
/*<    62 format(2(1pe10.2)) >*/
/* SOURCE newlookup.for:1765 */
/*<    70  >*/
/* SOURCE newlookup.for:1767 */
/*<    72 format(4(1pe10.2)) >*/
/* *********************************************************************** */
/*     Added May 22, 1998: definition of XST(i,*) contents */
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
/*     Extract the data from the itab/ftab structure for each type and place */
/*     in xst.  Then call the fitting routine, and then store the new values */
/*     over the old.  ip gives the table address.   We will fill in the */
/*     data in fields not in the tables so that the fitting process can compute */
/*     values even though they are not needed. */
/*     ha = high address */
/*     la = low address */
/* SOURCE newlookup.for:1808 */
/*<       ha=itab(ip) >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
/* L62: */
/* L70: */
/* L72: */
    ha = itab[*ip];
/* SOURCE newlookup.for:1809 */
/*<       la=ip+xtioff >*/
    la = *ip + 32;
/* SOURCE newlookup.for:1810 */
/*<       type=itab(ip+2) >*/
    feq_gen_type_d_ = itab[*ip + 2];
/* SOURCE newlookup.for:1811 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE newlookup.for:1813 */
/*<       ndep=0 >*/
    ndep = 0;
/* SOURCE newlookup.for:1814 */
/*<       doi=la,ha,xoff >*/
    feq_gen_i_d_1 = ha;
    feq_gen_i_d_2 = xoff;
    for (feq_gen_i_d_ = la; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE newlookup.for:1815 */
/*<       ndep=ndep+1 >*/
	++ndep;
/*       extract the universal element group. */
/*       max depth in the section */
/* SOURCE newlookup.for:1819 */
/*<       xst(ndep,1)=ftab(i) >*/
	xst[ndep - 1] = ftab[feq_gen_i_d_];
/*       top width */
/* SOURCE newlookup.for:1821 */
/*<       xst(ndep,2)=ftab(i+1) >*/
	xst[ndep + 998] = ftab[feq_gen_i_d_ + 1];
/*       area */
/* SOURCE newlookup.for:1823 */
/*<       xst(ndep,3)=ftab(i+2) >*/
	xst[ndep + 1997] = ftab[feq_gen_i_d_ + 2];
/*       sqrt of conveyance */
/* SOURCE newlookup.for:1825 */
/*<       xst(ndep,5)=ftab(i+3) >*/
	xst[ndep + 3995] = ftab[feq_gen_i_d_ + 3];
/*       beta */
/* SOURCE newlookup.for:1827 */
/*<       xst(ndep,6)=ftab(i+4) >*/
	xst[ndep + 4994] = ftab[feq_gen_i_d_ + 4];
/* SOURCE newlookup.for:1829 */
/*<       feql_select3=type >*/
	feq_gen_feql_select3_d_ = feq_gen_type_d_;
/* SOURCE newlookup.for:1829 */
/*<       if(feql_select3.eq.20)then >*/
	if (feq_gen_feql_select3_d_ == 20) {
/*         first moment */
/* SOURCE newlookup.for:1833 */
/*<       xst(ndep,4)=0.0 >*/
	    xst[ndep + 2996] = (float)0.;
/*         alpha */
/* SOURCE newlookup.for:1835 */
/*<       xst(ndep,7)=1.0 >*/
	    xst[ndep + 5993] = (float)1.;
/*         critical flow */
/* SOURCE newlookup.for:1837 */
/*<       xst(ndep,13)=0.0 >*/
	    xst[ndep + 11987] = (float)0.;
/*         ma */
/* SOURCE newlookup.for:1839 */
/*<       xst(ndep,14)=1.0 >*/
	    xst[ndep + 12986] = (float)1.;
/*         mq */
/* SOURCE newlookup.for:1841 */
/*<       xst(ndep,15)=1.0 >*/
	    xst[ndep + 13985] = (float)1.;
/* SOURCE newlookup.for:1829 */
/*<       elseif(feql_select3.eq.21)then >*/
	} else if (feq_gen_feql_select3_d_ == 21) {
/* SOURCE newlookup.for:1844 */
/*<       xst(ndep,4)=ftab(i+5) >*/
	    xst[ndep + 2996] = ftab[feq_gen_i_d_ + 5];
/* SOURCE newlookup.for:1845 */
/*<       xst(ndep,7)=1.0 >*/
	    xst[ndep + 5993] = (float)1.;
/* SOURCE newlookup.for:1846 */
/*<       xst(ndep,13)=0.0 >*/
	    xst[ndep + 11987] = (float)0.;
/* SOURCE newlookup.for:1847 */
/*<       xst(ndep,14)=1.0 >*/
	    xst[ndep + 12986] = (float)1.;
/* SOURCE newlookup.for:1848 */
/*<       xst(ndep,15)=1.0 >*/
	    xst[ndep + 13985] = (float)1.;
/* SOURCE newlookup.for:1829 */
/*<       elseif(feql_select3.eq.22)then >*/
	} else if (feq_gen_feql_select3_d_ == 22) {
/* SOURCE newlookup.for:1851 */
/*<       xst(ndep,4)=ftab(i+5) >*/
	    xst[ndep + 2996] = ftab[feq_gen_i_d_ + 5];
/* SOURCE newlookup.for:1852 */
/*<       xst(ndep,7)=ftab(i+6) >*/
	    xst[ndep + 5993] = ftab[feq_gen_i_d_ + 6];
/* SOURCE newlookup.for:1853 */
/*<       xst(ndep,13)=ftab(i+7) >*/
	    xst[ndep + 11987] = ftab[feq_gen_i_d_ + 7];
/* SOURCE newlookup.for:1854 */
/*<       xst(ndep,14)=1.0 >*/
	    xst[ndep + 12986] = (float)1.;
/* SOURCE newlookup.for:1855 */
/*<       xst(ndep,15)=1.0 >*/
	    xst[ndep + 13985] = (float)1.;
/* SOURCE newlookup.for:1829 */
/*<       elseif(feql_select3.eq.23)then >*/
	} else if (feq_gen_feql_select3_d_ == 23) {
/* SOURCE newlookup.for:1858 */
/*<       xst(ndep,4)=0.0 >*/
	    xst[ndep + 2996] = (float)0.;
/* SOURCE newlookup.for:1859 */
/*<       xst(ndep,7)=1.0 >*/
	    xst[ndep + 5993] = (float)1.;
/* SOURCE newlookup.for:1860 */
/*<       xst(ndep,13)=0.0 >*/
	    xst[ndep + 11987] = (float)0.;
/* SOURCE newlookup.for:1861 */
/*<       xst(ndep,14)=ftab(i+5) >*/
	    xst[ndep + 12986] = ftab[feq_gen_i_d_ + 5];
/* SOURCE newlookup.for:1862 */
/*<       xst(ndep,15)=ftab(i+6) >*/
	    xst[ndep + 13985] = ftab[feq_gen_i_d_ + 6];
/* SOURCE newlookup.for:1829 */
/*<       elseif(feql_select3.eq.24)then >*/
	} else if (feq_gen_feql_select3_d_ == 24) {
/* SOURCE newlookup.for:1865 */
/*<       xst(ndep,4)=ftab(i+5) >*/
	    xst[ndep + 2996] = ftab[feq_gen_i_d_ + 5];
/* SOURCE newlookup.for:1866 */
/*<       xst(ndep,7)=1.0 >*/
	    xst[ndep + 5993] = (float)1.;
/* SOURCE newlookup.for:1867 */
/*<       xst(ndep,13)=0.0 >*/
	    xst[ndep + 11987] = (float)0.;
/* SOURCE newlookup.for:1868 */
/*<       xst(ndep,14)=ftab(i+6) >*/
	    xst[ndep + 12986] = ftab[feq_gen_i_d_ + 6];
/* SOURCE newlookup.for:1869 */
/*<       xst(ndep,15)=ftab(i+7) >*/
	    xst[ndep + 13985] = ftab[feq_gen_i_d_ + 7];
/* SOURCE newlookup.for:1829 */
/*<       elseif(feql_select3.eq.25)then >*/
	} else if (feq_gen_feql_select3_d_ == 25) {
/* SOURCE newlookup.for:1872 */
/*<       xst(ndep,4)=ftab(i+5) >*/
	    xst[ndep + 2996] = ftab[feq_gen_i_d_ + 5];
/* SOURCE newlookup.for:1873 */
/*<       xst(ndep,7)=ftab(i+6) >*/
	    xst[ndep + 5993] = ftab[feq_gen_i_d_ + 6];
/* SOURCE newlookup.for:1874 */
/*<       xst(ndep,13)=ftab(i+7) >*/
	    xst[ndep + 11987] = ftab[feq_gen_i_d_ + 7];
/* SOURCE newlookup.for:1875 */
/*<       xst(ndep,14)=ftab(i+8) >*/
	    xst[ndep + 12986] = ftab[feq_gen_i_d_ + 8];
/* SOURCE newlookup.for:1876 */
/*<       xst(ndep,15)=ftab(i+9) >*/
	    xst[ndep + 13985] = ftab[feq_gen_i_d_ + 9];
/* SOURCE newlookup.for:1877 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1878 */
/*<       enddo >*/
    }
/* SOURCE newlookup.for:1882 */
/*<        >*/
    xsecfit_(stdout, verbose, &ndep, xst, khflag, alphaflag, betaflag, maflag,
	     mqflag, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
/*     extract stuff to be restored */
/* SOURCE newlookup.for:1889 */
/*<       tab=itab(ip+1) >*/
    tab = itab[*ip + 1];
/* SOURCE newlookup.for:1890 */
/*<       stat=ftab(ip+4) >*/
    stat = ftab[*ip + 4];
/* SOURCE newlookup.for:1891 */
/*<       zmin=ftab(ip+5) >*/
    zmin = ftab[*ip + 5];
/* SOURCE newlookup.for:1892 */
/*<       max_arg=ftab(ip+6) >*/
    feq_gen_max_arg_d_ = ftab[*ip + 6];
/* SOURCE newlookup.for:1893 */
/*<       slot_depth=ftab(ip+7) >*/
    feq_gen_slot_depth_d_ = ftab[*ip + 7];
/*     Put the easting coordinate value in the table. */
/* SOURCE newlookup.for:1895 */
/*<       easting=get_dp_from_ft(ip+8) >*/
    feq_gen_i_d_2 = *ip + 8;
    easting = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE newlookup.for:1896 */
/*<       northing=get_dp_from_ft(ip+10) >*/
    feq_gen_i_d_2 = *ip + 10;
    northing = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE newlookup.for:1897 */
/*<       gisid=get_string_from_ft(ip+12) >*/
    feq_gen_i_d_2 = *ip + 12;
    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
    s_copy(gisid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE newlookup.for:1898 */
/*<       tabid=get_string_from_ft(ip+16) >*/
    feq_gen_i_d_2 = *ip + 16;
    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/*     get the zone, grid, datum, and unitsys information */
/* SOURCE newlookup.for:1900 */
/*<       zone=get_chr8_from_ft(ip+22) >*/
    feq_gen_i_d_2 = *ip + 22;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_2);
    s_copy(zone, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE newlookup.for:1901 */
/*<       hgrid=get_chr8_from_ft(ip+24) >*/
    feq_gen_i_d_2 = *ip + 24;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_2);
    s_copy(hgrid, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE newlookup.for:1902 */
/*<       vdatum=get_chr8_from_ft(ip+26) >*/
    feq_gen_i_d_2 = *ip + 26;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_2);
    s_copy(vdatum, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE newlookup.for:1903 */
/*<       unitsys=get_chr8_from_ft(ip+28) >*/
    feq_gen_i_d_2 = *ip + 28;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_2);
    s_copy(unitsys, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/* SOURCE newlookup.for:1904 */
/*<       basis=get_chr8_from_ft(ip+30) >*/
    feq_gen_i_d_2 = *ip + 30;
    feq_gen_get_chr8_from_ft_d_(feq_gen_ch_d_2, (ftnlen)8, &feq_gen_i_d_2);
    s_copy(basis, feq_gen_ch_d_2, (ftnlen)8, (ftnlen)8);
/*     upgrade the type- always by 10. */
/* SOURCE newlookup.for:1908 */
/*<       type=type+10 >*/
    feq_gen_type_d_ += 10;
/* SOURCE newlookup.for:1911 */
/*<        >*/
    feq_gen_store_xsec_tab_d_(stdout, &ndep, &feq_gen_type_d_, tabid, &tab, &stat, &zmin, &
	    feq_gen_slot_depth_d_, gisid, &easting, &northing, xst, &feq_gen_max_arg_d_, zone, 
	    hgrid, vdatum, unitsys, basis, ftp, (ftnlen)16, (ftnlen)16, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     Compute checks on the upgraded tables and report summaries. */
/* SOURCE newlookup.for:1920 */
/*<       feql_select4=type >*/
    feq_gen_feql_select4_d_ = feq_gen_type_d_;
/* SOURCE newlookup.for:1920 */
/*<       if(feql_select4.eq.30)then >*/
    if (feq_gen_feql_select4_d_ == 30) {
/* SOURCE newlookup.for:1920 */
/*<       elseif(feql_select4.eq.31)then >*/
    } else if (feq_gen_feql_select4_d_ == 31) {
/* SOURCE newlookup.for:1926 */
/*<       yl=xst(1,1) >*/
	yl = xst[0];
/* SOURCE newlookup.for:1927 */
/*<       callxlkt21(ip,yl,al,tl,dtl,jl,kl,dkl,betal,dbetal) >*/
	xlkt21_(ip, &yl, &al, &tl, &dtl, &jl, &kl, &dkl, &betal, &dbetal);
/* SOURCE newlookup.for:1931 */
/*<       khl=0.0 >*/
	khl = (float)0.;
/* SOURCE newlookup.for:1932 */
/*<       dkhl=0.0 >*/
	dkhl = (float)0.;
/* SOURCE newlookup.for:1933 */
/*<       max_kh_err=-1.0 >*/
	feq_gen_max_kh_err_d_ = (float)-1.;
/* SOURCE newlookup.for:1934 */
/*<       max_beta_err=-1.0 >*/
	feq_gen_max_beta_err_d_ = (float)-1.;
/* SOURCE newlookup.for:1935 */
/*<       doi=2,ndep >*/
	feq_gen_i_d_2 = ndep;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:1936 */
/*<       yr=xst(i,1) >*/
	    yr = xst[feq_gen_i_d_ - 1];
/* SOURCE newlookup.for:1937 */
/*<       ym=0.5*(yl+yr) >*/
	    ym = static_cast<double>((static_cast<double>(yl) + yr)) * (float).5;
/* SOURCE newlookup.for:1938 */
/*<       callxlkt21(ip,ym,am,tm,dtm,jm,km,dkm,betam,dbetam) >*/
	    xlkt21_(ip, &ym, &am, &tm, &dtm, &jm, &km, &dkm, &betam, &dbetam);
/* SOURCE newlookup.for:1942 */
/*<       khm=sqrt(km) >*/
	    khm = sqrt(km);
/* SOURCE newlookup.for:1943 */
/*<       dkhm=0.5*dkm/khm >*/
	    dkhm = static_cast<double>(static_cast<double>(dkm) * (float).5) / khm;
/* SOURCE newlookup.for:1944 */
/*<       callxlkt21(ip,yr,ar,tr,dtr,jr,kr,dkr,betar,dbetar) >*/
	    xlkt21_(ip, &yr, &ar, &tr, &dtr, &jr, &kr, &dkr, &betar, &dbetar);
/* SOURCE newlookup.for:1948 */
/*<       khr=sqrt(kr) >*/
	    khr = sqrt(kr);
/* SOURCE newlookup.for:1949 */
/*<       dkhr=0.5*dkr/khr >*/
	    dkhr = static_cast<double>(static_cast<double>(dkr) * (float).5) / khr;
/* SOURCE newlookup.for:1951 */
/*<       kh_err=khr-khl-(yr-yl)*(dkhl+4.*dkhm+dkhr)/6.0 >*/
	    feq_gen_kh_err_d_ = static_cast<double>(static_cast<double>(khr) - khl) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dkhl) + static_cast<double>(dkhm) * (float)4.) + 
		    dkhr)) / (float)6.;
/* SOURCE newlookup.for:1952 */
/*<       kh_err=abs(kh_err)/max(abs(khr-khl),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(khr) - khl, dabs(feq_gen_r_d_1));
	    feq_gen_kh_err_d_ = dabs(feq_gen_kh_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:1953 */
/*<       max_kh_err=max(max_kh_err,kh_err) >*/
	    feq_gen_max_kh_err_d_ = dmax(feq_gen_max_kh_err_d_,feq_gen_kh_err_d_);
/* SOURCE newlookup.for:1955 */
/*<       beta_err=betar-betal-(yr-yl)*(dbetal+4.*dbetam+dbetar)/6.0 >*/
	    feq_gen_beta_err_d_ = static_cast<double>(static_cast<double>(betar) - betal) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dbetal) + static_cast<double>(dbetam) * (
		    float)4.) + dbetar)) / (float)6.;
/* SOURCE newlookup.for:1957 */
/*<       beta_err=abs(beta_err)/max(abs(betar-betal),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(betar) - betal, dabs(feq_gen_r_d_1));
	    feq_gen_beta_err_d_ = dabs(feq_gen_beta_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:1958 */
/*<       max_beta_err=max(max_beta_err,beta_err) >*/
	    feq_gen_max_beta_err_d_ = dmax(feq_gen_max_beta_err_d_,feq_gen_beta_err_d_);
/* SOURCE newlookup.for:1962 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE newlookup.for:1963 */
/*<       khl=khr >*/
	    khl = khr;
/* SOURCE newlookup.for:1964 */
/*<       dkhl=dkhr >*/
	    dkhl = dkhr;
/* SOURCE newlookup.for:1965 */
/*<       betal=betar >*/
	    betal = betar;
/* SOURCE newlookup.for:1966 */
/*<       dbetal=dbetar >*/
	    dbetal = dbetar;
/* SOURCE newlookup.for:1967 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:1968 */
/*<       if(max(max_kh_err,max_beta_err).gt.1.e-3)then >*/
	if (dmax(feq_gen_max_kh_err_d_,feq_gen_max_beta_err_d_) > (float).001) {
/* SOURCE newlookup.for:1970 */
/*<       write(stdout,60) >*/
	    feq_gen_io_d__262.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__262);
	    e_wsfe();
/* SOURCE newlookup.for:1971 */
/*<       write(stdout,62)max_kh_err,max_beta_err >*/
	    feq_gen_io_d__263.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__263);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_kh_err_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_beta_err_d_, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE newlookup.for:1972 */
/*<       else >*/
	} else {
/* SOURCE newlookup.for:1973 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__264.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__264);
	    e_wsfe();
/* SOURCE newlookup.for:1974 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1920 */
/*<       elseif(feql_select4.eq.32)then >*/
    } else if (feq_gen_feql_select4_d_ == 32) {
/* SOURCE newlookup.for:1920 */
/*<       elseif(feql_select4.eq.33)then >*/
    } else if (feq_gen_feql_select4_d_ == 33) {
/* SOURCE newlookup.for:1979 */
/*<       yl=xst(1,1) >*/
	yl = xst[0];
/* SOURCE newlookup.for:1980 */
/*<       callxlkt23(ip,yl,al,tl,dtl,kl,dkl,betal,dbetal,mal,dmal,mql,dmql) >*/
	xlkt23_(ip, &yl, &al, &tl, &dtl, &kl, &dkl, &betal, &dbetal, &mal, &
		dmal, &mql, &dmql);
/* SOURCE newlookup.for:1985 */
/*<       khl=0.0 >*/
	khl = (float)0.;
/* SOURCE newlookup.for:1986 */
/*<       dkhl=0.0 >*/
	dkhl = (float)0.;
/* SOURCE newlookup.for:1987 */
/*<       max_kh_err=-1.0 >*/
	feq_gen_max_kh_err_d_ = (float)-1.;
/* SOURCE newlookup.for:1988 */
/*<       max_beta_err=-1.0 >*/
	feq_gen_max_beta_err_d_ = (float)-1.;
/* SOURCE newlookup.for:1989 */
/*<       max_ma_err=-1.0 >*/
	feq_gen_max_ma_err_d_ = (float)-1.;
/* SOURCE newlookup.for:1990 */
/*<       max_mq_err=-1.0 >*/
	feq_gen_max_mq_err_d_ = (float)-1.;
/*        write(stdout,50) */
/* SOURCE newlookup.for:1992 */
/*<       doi=2,ndep >*/
	feq_gen_i_d_2 = ndep;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:1993 */
/*<       yr=xst(i,1) >*/
	    yr = xst[feq_gen_i_d_ - 1];
/* SOURCE newlookup.for:1994 */
/*<       ym=0.5*(yl+yr) >*/
	    ym = static_cast<double>((static_cast<double>(yl) + yr)) * (float).5;
/* SOURCE newlookup.for:1995 */
/*<       callxlkt23(ip,ym,am,tm,dtm,km,dkm,betam,dbetam,mam,dmam,mqm,dmqm) >*/
	    xlkt23_(ip, &ym, &am, &tm, &dtm, &km, &dkm, &betam, &dbetam, &mam,
		     &dmam, &mqm, &dmqm);
/* SOURCE newlookup.for:2000 */
/*<       khm=sqrt(km) >*/
	    khm = sqrt(km);
/* SOURCE newlookup.for:2001 */
/*<       dkhm=0.5*dkm/khm >*/
	    dkhm = static_cast<double>(static_cast<double>(dkm) * (float).5) / khm;
/* SOURCE newlookup.for:2002 */
/*<       callxlkt23(ip,yr,ar,tr,dtr,kr,dkr,betar,dbetar,mar,dmar,mqr,dmqr) >*/
	    xlkt23_(ip, &yr, &ar, &tr, &dtr, &kr, &dkr, &betar, &dbetar, &mar,
		     &dmar, &mqr, &dmqr);
/* SOURCE newlookup.for:2007 */
/*<       khr=sqrt(kr) >*/
	    khr = sqrt(kr);
/* SOURCE newlookup.for:2008 */
/*<       dkhr=0.5*dkr/khr >*/
	    dkhr = static_cast<double>(static_cast<double>(dkr) * (float).5) / khr;
/* SOURCE newlookup.for:2010 */
/*<       kh_err=khr-khl-(yr-yl)*(dkhl+4.*dkhm+dkhr)/6.0 >*/
	    feq_gen_kh_err_d_ = static_cast<double>(static_cast<double>(khr) - khl) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dkhl) + static_cast<double>(dkhm) * (float)4.) + 
		    dkhr)) / (float)6.;
/* SOURCE newlookup.for:2011 */
/*<       kh_err=abs(kh_err)/max(abs(khr-khl),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(khr) - khl, dabs(feq_gen_r_d_1));
	    feq_gen_kh_err_d_ = dabs(feq_gen_kh_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2012 */
/*<       max_kh_err=max(max_kh_err,kh_err) >*/
	    feq_gen_max_kh_err_d_ = dmax(feq_gen_max_kh_err_d_,feq_gen_kh_err_d_);
/* SOURCE newlookup.for:2014 */
/*<       beta_err=betar-betal-(yr-yl)*(dbetal+4.*dbetam+dbetar)/6.0 >*/
	    feq_gen_beta_err_d_ = static_cast<double>(static_cast<double>(betar) - betal) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dbetal) + static_cast<double>(dbetam) * (
		    float)4.) + dbetar)) / (float)6.;
/* SOURCE newlookup.for:2016 */
/*<       beta_err=abs(beta_err)/max(abs(betar-betal),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(betar) - betal, dabs(feq_gen_r_d_1));
	    feq_gen_beta_err_d_ = dabs(feq_gen_beta_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2017 */
/*<       max_beta_err=max(max_beta_err,beta_err) >*/
	    feq_gen_max_beta_err_d_ = dmax(feq_gen_max_beta_err_d_,feq_gen_beta_err_d_);
/* SOURCE newlookup.for:2020 */
/*<       ma_err=mar-mal-(yr-yl)*(dmal+4.*dmam+dmar)/6.0 >*/
	    feq_gen_ma_err_d_ = static_cast<double>(static_cast<double>(mar) - mal) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dmal) + static_cast<double>(dmam) * (float)4.) + 
		    dmar)) / (float)6.;
/* SOURCE newlookup.for:2021 */
/*<       ma_err=abs(ma_err)/max(abs(mar-mal),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(mar) - mal, dabs(feq_gen_r_d_1));
	    feq_gen_ma_err_d_ = dabs(feq_gen_ma_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2022 */
/*<       max_ma_err=max(max_ma_err,ma_err) >*/
	    feq_gen_max_ma_err_d_ = dmax(feq_gen_max_ma_err_d_,feq_gen_ma_err_d_);
/* SOURCE newlookup.for:2024 */
/*<       mq_err=mqr-mql-(yr-yl)*(dmql+4.*dmqm+dmqr)/6.0 >*/
	    feq_gen_mq_err_d_ = static_cast<double>(static_cast<double>(mqr) - mql) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dmql) + static_cast<double>(dmqm) * (float)4.) + 
		    dmqr)) / (float)6.;
/* SOURCE newlookup.for:2025 */
/*<       mq_err=abs(mq_err)/max(abs(mqr-mql),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(mqr) - mql, dabs(feq_gen_r_d_1));
	    feq_gen_mq_err_d_ = dabs(feq_gen_mq_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2026 */
/*<       max_mq_err=max(max_mq_err,mq_err) >*/
	    feq_gen_max_mq_err_d_ = dmax(feq_gen_max_mq_err_d_,feq_gen_mq_err_d_);
/* SOURCE newlookup.for:2029 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE newlookup.for:2030 */
/*<       khl=khr >*/
	    khl = khr;
/* SOURCE newlookup.for:2031 */
/*<       dkhl=dkhr >*/
	    dkhl = dkhr;
/* SOURCE newlookup.for:2032 */
/*<       betal=betar >*/
	    betal = betar;
/* SOURCE newlookup.for:2033 */
/*<       dbetal=dbetar >*/
	    dbetal = dbetar;
/* SOURCE newlookup.for:2034 */
/*<       mal=mar >*/
	    mal = mar;
/* SOURCE newlookup.for:2035 */
/*<       dmal=dmar >*/
	    dmal = dmar;
/* SOURCE newlookup.for:2036 */
/*<       mql=mqr >*/
	    mql = mqr;
/* SOURCE newlookup.for:2037 */
/*<       dmql=dmqr >*/
	    dmql = dmqr;
/* SOURCE newlookup.for:2038 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:2039 */
/*<        >*/
/* Computing MAX */
	feq_gen_r_d_1 = max(feq_gen_max_kh_err_d_,feq_gen_max_beta_err_d_), feq_gen_r_d_1 = max(feq_gen_r_d_1,feq_gen_max_ma_err_d_)
		;
	if (dmax(feq_gen_r_d_1,feq_gen_max_mq_err_d_) > (float).001) {
/* SOURCE newlookup.for:2042 */
/*<       write(stdout,70) >*/
	    feq_gen_io_d__281.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__281);
	    e_wsfe();
/* SOURCE newlookup.for:2043 */
/*<       write(stdout,72)max_kh_err,max_beta_err,max_ma_err,max_mq_err >*/
	    feq_gen_io_d__282.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__282);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_kh_err_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_beta_err_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_ma_err_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_mq_err_d_, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE newlookup.for:2045 */
/*<       else >*/
	} else {
/* SOURCE newlookup.for:2046 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__283.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__283);
	    e_wsfe();
/* SOURCE newlookup.for:2047 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:1920 */
/*<       elseif(feql_select4.eq.34)then >*/
    } else if (feq_gen_feql_select4_d_ == 34) {
/* SOURCE newlookup.for:1920 */
/*<       elseif(feql_select4.eq.35)then >*/
    } else if (feq_gen_feql_select4_d_ == 35) {
/* SOURCE newlookup.for:2054 */
/*<       yl=xst(1,1) >*/
	yl = xst[0];
/* SOURCE newlookup.for:2055 */
/*<        >*/
	xlkt25_(ip, &yl, &al, &tl, &dtl, &jl, &kl, &dkl, &betal, &dbetal, &
		alphal, &dalphal, &qcl, &mal, &dmal, &mql, &dmql);
/* SOURCE newlookup.for:2060 */
/*<       khl=0.0 >*/
	khl = (float)0.;
/* SOURCE newlookup.for:2061 */
/*<       dkhl=0.0 >*/
	dkhl = (float)0.;
/* SOURCE newlookup.for:2062 */
/*<       max_kh_err=-1.0 >*/
	feq_gen_max_kh_err_d_ = (float)-1.;
/* SOURCE newlookup.for:2063 */
/*<       max_beta_err=-1.0 >*/
	feq_gen_max_beta_err_d_ = (float)-1.;
/* SOURCE newlookup.for:2064 */
/*<       max_alpha_err=-1.0 >*/
	feq_gen_max_alpha_err_d_ = (float)-1.;
/* SOURCE newlookup.for:2065 */
/*<       max_ma_err=-1.0 >*/
	feq_gen_max_ma_err_d_ = (float)-1.;
/* SOURCE newlookup.for:2066 */
/*<       max_mq_err=-1.0 >*/
	feq_gen_max_mq_err_d_ = (float)-1.;
/*        write(stdout,50) */
/* SOURCE newlookup.for:2068 */
/*<       doi=2,ndep >*/
	feq_gen_i_d_2 = ndep;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:2069 */
/*<       yr=xst(i,1) >*/
	    yr = xst[feq_gen_i_d_ - 1];
/* SOURCE newlookup.for:2070 */
/*<       ym=0.5*(yl+yr) >*/
	    ym = static_cast<double>((static_cast<double>(yl) + yr)) * (float).5;
/* SOURCE newlookup.for:2071 */
/*<        >*/
	    xlkt25_(ip, &ym, &am, &tm, &dtm, &jm, &km, &dkm, &betam, &dbetam, 
		    &alpham, &dalpham, &qcm, &mam, &dmam, &mqm, &dmqm);
/* SOURCE newlookup.for:2076 */
/*<       khm=sqrt(km) >*/
	    khm = sqrt(km);
/* SOURCE newlookup.for:2077 */
/*<       dkhm=0.5*dkm/khm >*/
	    dkhm = static_cast<double>(static_cast<double>(dkm) * (float).5) / khm;
/* SOURCE newlookup.for:2078 */
/*<        >*/
	    xlkt25_(ip, &yr, &ar, &tr, &dtr, &jr, &kr, &dkr, &betar, &dbetar, 
		    &alphar, &dalphar, &qcr, &mar, &dmar, &mqr, &dmqr);
/* SOURCE newlookup.for:2083 */
/*<       khr=sqrt(kr) >*/
	    khr = sqrt(kr);
/* SOURCE newlookup.for:2084 */
/*<       dkhr=0.5*dkr/khr >*/
	    dkhr = static_cast<double>(static_cast<double>(dkr) * (float).5) / khr;
/* SOURCE newlookup.for:2086 */
/*<       kh_err=khr-khl-(yr-yl)*(dkhl+4.*dkhm+dkhr)/6.0 >*/
	    feq_gen_kh_err_d_ = static_cast<double>(static_cast<double>(khr) - khl) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dkhl) + static_cast<double>(dkhm) * (float)4.) + 
		    dkhr)) / (float)6.;
/* SOURCE newlookup.for:2087 */
/*<       kh_err=abs(kh_err)/max(abs(khr-khl),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(khr) - khl, dabs(feq_gen_r_d_1));
	    feq_gen_kh_err_d_ = dabs(feq_gen_kh_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2088 */
/*<       max_kh_err=max(max_kh_err,kh_err) >*/
	    feq_gen_max_kh_err_d_ = dmax(feq_gen_max_kh_err_d_,feq_gen_kh_err_d_);
/* SOURCE newlookup.for:2090 */
/*<       beta_err=betar-betal-(yr-yl)*(dbetal+4.*dbetam+dbetar)/6.0 >*/
	    feq_gen_beta_err_d_ = static_cast<double>(static_cast<double>(betar) - betal) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dbetal) + static_cast<double>(dbetam) * (
		    float)4.) + dbetar)) / (float)6.;
/* SOURCE newlookup.for:2092 */
/*<       beta_err=abs(beta_err)/max(abs(betar-betal),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(betar) - betal, dabs(feq_gen_r_d_1));
	    feq_gen_beta_err_d_ = dabs(feq_gen_beta_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2093 */
/*<       max_beta_err=max(max_beta_err,beta_err) >*/
	    feq_gen_max_beta_err_d_ = dmax(feq_gen_max_beta_err_d_,feq_gen_beta_err_d_);
/* SOURCE newlookup.for:2095 */
/*<       alpha_err=alphar-alphal-(yr-yl)*(dalphal+4.*dalpham+dalphar)/6.0 >*/
	    feq_gen_alpha_err_d_ = static_cast<double>(static_cast<double>(alphar) - alphal) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dalphal) + static_cast<double>(dalpham) * (
		    float)4.) + dalphar)) / (float)6.;
/* SOURCE newlookup.for:2097 */
/*<       alpha_err=abs(alpha_err)/max(abs(alphar-alphal),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(alphar) - alphal, dabs(feq_gen_r_d_1));
	    feq_gen_alpha_err_d_ = dabs(feq_gen_alpha_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2098 */
/*<       max_alpha_err=max(max_alpha_err,alpha_err) >*/
	    feq_gen_max_alpha_err_d_ = dmax(feq_gen_max_alpha_err_d_,feq_gen_alpha_err_d_);
/* SOURCE newlookup.for:2100 */
/*<       ma_err=mar-mal-(yr-yl)*(dmal+4.*dmam+dmar)/6.0 >*/
	    feq_gen_ma_err_d_ = static_cast<double>(static_cast<double>(mar) - mal) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dmal) + static_cast<double>(dmam) * (float)4.) + 
		    dmar)) / (float)6.;
/* SOURCE newlookup.for:2101 */
/*<       ma_err=abs(ma_err)/max(abs(mar-mal),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(mar) - mal, dabs(feq_gen_r_d_1));
	    feq_gen_ma_err_d_ = dabs(feq_gen_ma_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2102 */
/*<       max_ma_err=max(max_ma_err,ma_err) >*/
	    feq_gen_max_ma_err_d_ = dmax(feq_gen_max_ma_err_d_,feq_gen_ma_err_d_);
/* SOURCE newlookup.for:2104 */
/*<       mq_err=mqr-mql-(yr-yl)*(dmql+4.*dmqm+dmqr)/6.0 >*/
	    feq_gen_mq_err_d_ = static_cast<double>(static_cast<double>(mqr) - mql) - static_cast<double>(static_cast<double>((static_cast<double>(yr) - yl)) * (static_cast<double>(static_cast<double>(dmql) + static_cast<double>(dmqm) * (float)4.) + 
		    dmqr)) / (float)6.;
/* SOURCE newlookup.for:2105 */
/*<       mq_err=abs(mq_err)/max(abs(mqr-mql),1.0) >*/
/* Computing MAX */
	    feq_gen_r_d_2 = (feq_gen_r_d_1 = static_cast<double>(mqr) - mql, dabs(feq_gen_r_d_1));
	    feq_gen_mq_err_d_ = dabs(feq_gen_mq_err_d_) / dmax(feq_gen_r_d_2,(float)1.);
/* SOURCE newlookup.for:2106 */
/*<       max_mq_err=max(max_mq_err,mq_err) >*/
	    feq_gen_max_mq_err_d_ = dmax(feq_gen_max_mq_err_d_,feq_gen_mq_err_d_);
/* SOURCE newlookup.for:2109 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE newlookup.for:2110 */
/*<       khl=khr >*/
	    khl = khr;
/* SOURCE newlookup.for:2111 */
/*<       dkhl=dkhr >*/
	    dkhl = dkhr;
/* SOURCE newlookup.for:2112 */
/*<       betal=betar >*/
	    betal = betar;
/* SOURCE newlookup.for:2113 */
/*<       dbetal=dbetar >*/
	    dbetal = dbetar;
/* SOURCE newlookup.for:2114 */
/*<       alphal=alphar >*/
	    alphal = alphar;
/* SOURCE newlookup.for:2115 */
/*<       dalphal=dalphar >*/
	    dalphal = dalphar;
/* SOURCE newlookup.for:2116 */
/*<       mal=mar >*/
	    mal = mar;
/* SOURCE newlookup.for:2117 */
/*<       dmal=dmar >*/
	    dmal = dmar;
/* SOURCE newlookup.for:2118 */
/*<       mql=mqr >*/
	    mql = mqr;
/* SOURCE newlookup.for:2119 */
/*<       dmql=dmqr >*/
	    dmql = dmqr;
/* SOURCE newlookup.for:2120 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:2121 */
/*<        >*/
/* Computing MAX */
	feq_gen_r_d_1 = max(feq_gen_max_kh_err_d_,feq_gen_max_beta_err_d_), feq_gen_r_d_1 = max(feq_gen_r_d_1,
		feq_gen_max_alpha_err_d_), feq_gen_r_d_1 = max(feq_gen_r_d_1,feq_gen_max_ma_err_d_);
	if (dmax(feq_gen_r_d_1,feq_gen_max_mq_err_d_) > (float).001) {
/* SOURCE newlookup.for:2124 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__295.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__295);
	    e_wsfe();
/* SOURCE newlookup.for:2125 */
/*<        >*/
	    feq_gen_io_d__296.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__296);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_kh_err_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_beta_err_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_alpha_err_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_ma_err_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_mq_err_d_, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE newlookup.for:2127 */
/*<       else >*/
	} else {
/* SOURCE newlookup.for:2128 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__297.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__297);
	    e_wsfe();
/* SOURCE newlookup.for:2129 */
/*<       endif >*/
	}
/* SOURCE newlookup.for:2131 */
/*<       endif >*/
    }
/*     Reset the last lookup position to the first level.  Needed */
/*     for later possible adjustment of conveyance */
/* SOURCE newlookup.for:2136 */
/*<       itab(ip+3)=ip+xtioff >*/
    itab[*ip + 3] = *ip + 32;
/* SOURCE newlookup.for:2138 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:2139 */
/*<       end >*/
} /* do_upgrade_xsec_tab__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE newlookup.for:2144 */
/*<        >*/
/* Subroutine */ int xsecfit_(integer *stdout, integer *verbose, integer *
	ndep, real *feq_storage_xst, char *feq_storage_khflag, char *feq_storage_alphaflag, char *feq_storage_betaflag, char *
	feq_storage_maflag, char *feq_storage_mqflag, ftnlen khflag_len, ftnlen alphaflag_len, ftnlen 
	betaflag_len, ftnlen maflag_len, ftnlen mqflag_len)
{
    /* Format strings */
    static char fmt_70[] = "(/,\002 Results for upgrade:\002)";
    static char fmt_72[] = "(\002         y        kh     dkh/dy     alpha  \
dalpha/dy\002,\002      beta   dbeta/dy        ma     dma/dy\002,\002       \
 mq     dmq/dy\002)";
    static char fmt_74[] = "(f10.3,1pe10.4e1,1pe10.4e1,a1,0pf10.6,f10.5,a1,f\
10.6,f10.5,a1,f10.6,f10.5,a1,f10.6,f10.5,a1)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double log(doublereal);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(),
	     do_fio(integer *, char *, ftnlen);

    /* Local variables */
    doublereal dalphady[999];
    integer feq_gen_i_d_, n;
    doublereal p, y[999], ma[999], kh[999], mq[999], yl, yr;
    integer feq_gen_feql_index5_d_, feq_gen_feql_index6_d_, feq_gen_feql_index7_d_, feq_gen_feql_index8_d_;
    doublereal khl, khr, beta[999];
    integer nadj;
    doublereal lval, rval, alpha[999];
    integer lcode, rcode;
    doublereal dmady[999], dkhdy[999], dmqdy[999];
    extern /* Subroutine */ int vrlim_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, char *, ftnlen);
    char feq_gen_make_monotone_d_[4];
    extern /* Subroutine */ int spline_(integer *, doublereal *, doublereal *,
	     integer *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *);
    doublereal dbetady[999];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__326 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__327 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__328 = { 0, 0, 0, fmt_74, 0 };


/*     + + + PURPOSE + + + */
/*     Compute some fits to the values in a cross-section function table. */
/* SOURCE newlookup.for:2151 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE newlookup.for:2153 */
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
/* SOURCE newlookup.for:2156 */
/*<       integerndep,stdout,verbose >*/
/* SOURCE newlookup.for:2157 */
/*<       realxst(pmxpnt,pmxelm) >*/
/* SOURCE newlookup.for:2158 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NDEP   - Number of depth values */
/*     XST    - Storage matrix for various elements of cross section */
/*     + + + COMMON BLOCKS + + + */
/*      INCLUDE 'ftable.cmn' */
/*      INCLUDE 'grvcom.cmn' */
/*      INCLUDE 'xtadd.cmn' */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE newlookup.for:2174 */
/*<       integeri,n >*/
/* SOURCE newlookup.for:2176 */
/*<       integerlcode,rcode,nadj >*/
/* SOURCE newlookup.for:2178 */
/*<       real*8lval,rval,khl,khr,yl,yr,p >*/
/* SOURCE newlookup.for:2180 */
/*<        >*/
/* SOURCE newlookup.for:2185 */
/*<       real*8y(pmxpnt) >*/
/* SOURCE newlookup.for:2187 */
/*<       charactermake_monotone*4 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE newlookup.for:2192 */
/*<       externalspline,vrlim >*/
/*     *********************formats************************************** */
/* SOURCE newlookup.for:2144 */
/*<       integer feql_index5 >*/
/* SOURCE newlookup.for:2144 */
/*<       integer feql_index6 >*/
/* SOURCE newlookup.for:2144 */
/*<       integer feql_index7 >*/
/* SOURCE newlookup.for:2144 */
/*<       integer feql_index8 >*/
/* SOURCE newlookup.for:2194 */
/*<    70 format(/,' Results for upgrade:') >*/
/* SOURCE newlookup.for:2195 */
/*<    72  >*/
/* SOURCE newlookup.for:2198 */
/*<    74  >*/
/* SOURCE newlookup.for:2204 */
/*<    75 format(' Power for sqrt of conveyance near zero=',f10.4) >*/
/* *********************************************************************** */
/* SOURCE newlookup.for:2207 */
/*<       make_monotone='YES' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> mqflag(feq_storage_mqflag, 1);

    feq::IndexedPointer<char> maflag(feq_storage_maflag, 1);

    feq::IndexedPointer<char> betaflag(feq_storage_betaflag, 1);

    feq::IndexedPointer<char> alphaflag(feq_storage_alphaflag, 1);

    feq::IndexedPointer<char> khflag(feq_storage_khflag, 1);

    feq::IndexedPointer<real> xst(feq_storage_xst, 1000);

    /* Function Body */
/* L70: */
/* L72: */
/* L74: */
/* L75: */
    s_copy(feq_gen_make_monotone_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3);
/* SOURCE newlookup.for:2208 */
/*<       dofeql_index5=1,pmxpnt >*/
    for (feq_gen_feql_index5_d_ = 1; feq_gen_feql_index5_d_ <= 999; ++feq_gen_feql_index5_d_) {
/* SOURCE newlookup.for:2208 */
/*<       alphaflag(feql_index5)=' ' >*/
	*(unsigned char *)&alphaflag[feq_gen_feql_index5_d_] = ' ';
/* SOURCE newlookup.for:2208 */
/*<       enddo >*/
    }
/* SOURCE newlookup.for:2209 */
/*<       dofeql_index6=1,pmxpnt >*/
    for (feq_gen_feql_index6_d_ = 1; feq_gen_feql_index6_d_ <= 999; ++feq_gen_feql_index6_d_) {
/* SOURCE newlookup.for:2209 */
/*<       betaflag(feql_index6)=' ' >*/
	*(unsigned char *)&betaflag[feq_gen_feql_index6_d_] = ' ';
/* SOURCE newlookup.for:2209 */
/*<       enddo >*/
    }
/* SOURCE newlookup.for:2210 */
/*<       dofeql_index7=1,pmxpnt >*/
    for (feq_gen_feql_index7_d_ = 1; feq_gen_feql_index7_d_ <= 999; ++feq_gen_feql_index7_d_) {
/* SOURCE newlookup.for:2210 */
/*<       maflag(feql_index7)=' ' >*/
	*(unsigned char *)&maflag[feq_gen_feql_index7_d_] = ' ';
/* SOURCE newlookup.for:2210 */
/*<       enddo >*/
    }
/* SOURCE newlookup.for:2211 */
/*<       dofeql_index8=1,pmxpnt >*/
    for (feq_gen_feql_index8_d_ = 1; feq_gen_feql_index8_d_ <= 999; ++feq_gen_feql_index8_d_) {
/* SOURCE newlookup.for:2211 */
/*<       mqflag(feql_index8)=' ' >*/
	*(unsigned char *)&mqflag[feq_gen_feql_index8_d_] = ' ';
/* SOURCE newlookup.for:2211 */
/*<       enddo >*/
    }
/*     FILL IN THE VELOCITY DISTRIBUTION COEFFICIENTS AT DEPTH 0.0 */
/*     AND CRITICAL FLOW AT ZERO DEPTH. */
/* SOURCE newlookup.for:2215 */
/*<       xst(1,6)=xst(1+1,6) >*/
    xst[5995] = xst[5996];
/* SOURCE newlookup.for:2216 */
/*<       xst(1,7)=xst(1+1,7) >*/
    xst[6994] = xst[6995];
/* SOURCE newlookup.for:2217 */
/*<       xst(1,13)=0.0 >*/
    xst[12988] = (float)0.;
/*     do for ma and mq also */
/* SOURCE newlookup.for:2220 */
/*<       xst(1,14)=xst(2,14) >*/
    xst[13987] = xst[13988];
/* SOURCE newlookup.for:2221 */
/*<       xst(1,15)=xst(2,15) >*/
    xst[14986] = xst[14987];
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
/*     Transfer the data to the working variables. */
/* SOURCE newlookup.for:2253 */
/*<       n=ndep >*/
    n = *ndep;
/* SOURCE newlookup.for:2254 */
/*<       doi=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:2255 */
/*<       y(i)=dble(xst(i,1)) >*/
	y[feq_gen_i_d_ - 1] = (doublereal) xst[feq_gen_i_d_ + 999];
/*        t(i) = dble(xst(i,2)) */
/* SOURCE newlookup.for:2257 */
/*<       kh(i)=dble(xst(i,5)) >*/
	kh[feq_gen_i_d_ - 1] = (doublereal) xst[feq_gen_i_d_ + 4995];
/* SOURCE newlookup.for:2258 */
/*<       alpha(i)=dble(xst(i,7)) >*/
	alpha[feq_gen_i_d_ - 1] = (doublereal) xst[feq_gen_i_d_ + 6993];
/* SOURCE newlookup.for:2259 */
/*<       beta(i)=dble(xst(i,6)) >*/
	beta[feq_gen_i_d_ - 1] = (doublereal) xst[feq_gen_i_d_ + 5994];
/* SOURCE newlookup.for:2260 */
/*<       ma(i)=dble(xst(i,14)) >*/
	ma[feq_gen_i_d_ - 1] = (doublereal) xst[feq_gen_i_d_ + 13986];
/* SOURCE newlookup.for:2261 */
/*<       mq(i)=dble(xst(i,15)) >*/
	mq[feq_gen_i_d_ - 1] = (doublereal) xst[feq_gen_i_d_ + 14985];
/* SOURCE newlookup.for:2262 */
/*<       enddo >*/
    }
/*     compute power of the square root of conveyance near zero. */
/* SOURCE newlookup.for:2265 */
/*<       yl=y(2) >*/
    yl = y[1];
/* SOURCE newlookup.for:2266 */
/*<       yr=y(3) >*/
    yr = y[2];
/* SOURCE newlookup.for:2267 */
/*<       khl=kh(2) >*/
    khl = kh[1];
/* SOURCE newlookup.for:2268 */
/*<       khr=kh(3) >*/
    khr = kh[2];
/* SOURCE newlookup.for:2269 */
/*<       p=log(khr/khl)/log(yr/yl) >*/
    p = log(khr / khl) / log(yr / yl);
/*      write(stdout,75) p */
/*     The code values for vlchpp which calls spline are: */
/*        code       Meaning of val */
/*       -------     -------------------------- */
/*          1         first derivative at the given end */
/*          2         second derivative at the given end */
/*          3          0 < val  < 1 */
/*   In terms of the "beam" theory behind the idea of a spline: */
/*   code 1 provides a cantilever support at the end.  That is, */
/*   the beam has a fixed slope there.  Code 2 is for a simple */
/*   support, the beam can rotate there as required.  The third */
/*   case for the left end places a simple support at location */
/*      xa  = (x(1) - val*x(2))/(1 - val) */
/*     and requiring that the entire curve from xa to x(2) be a */
/*     cubic.  A typical value of val is 0.5. */
/*     try sqrt of conveyance.  If power near zero is 1.0 or greater, */
/*     impose zero slope at zero depth.  Otherwise use the third option. */
/*     If the power is less than 1.0, then the derivative at zero depth is */
/*     infinite but we cannot impose that! */
/* SOURCE newlookup.for:2296 */
/*<       if(p.ge.1.d0)then >*/
    if (p >= 1.) {
/* SOURCE newlookup.for:2297 */
/*<       lcode=1 >*/
	lcode = 1;
/* SOURCE newlookup.for:2298 */
/*<       lval=0.0d0 >*/
	lval = 0.;
/* SOURCE newlookup.for:2299 */
/*<       else >*/
    } else {
/* SOURCE newlookup.for:2300 */
/*<       lcode=3 >*/
	lcode = 3;
/* SOURCE newlookup.for:2301 */
/*<       lval=0.5d0 >*/
	lval = .5;
/* SOURCE newlookup.for:2302 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:2304 */
/*<       rcode=3 >*/
    rcode = 3;
/* SOURCE newlookup.for:2305 */
/*<       rval=0.5d0 >*/
    rval = .5;
/*      call  vlchpp */
/*     i            (stdout, n, y, kh, lcode, lval, rcode, rval, */
/*     o                dkhdy, khflag) */
/* SOURCE newlookup.for:2311 */
/*<       callspline(stdout,y,kh,n,lcode,lval,rcode,rval,dkhdy) >*/
    spline_(stdout, y, kh, &n, &lcode, &lval, &rcode, &rval, dkhdy);
/* SOURCE newlookup.for:2314 */
/*<       callvrlim(n,y,kh,dkhdy,nadj,khflag) >*/
    vrlim_(&n, y, kh, dkhdy, &nadj, khflag + 1, (ftnlen)1);
/*     try the rest */
/* SOURCE newlookup.for:2322 */
/*<       lcode=3 >*/
    lcode = 3;
/* SOURCE newlookup.for:2323 */
/*<       lval=0.5d0 >*/
    lval = .5;
/* SOURCE newlookup.for:2325 */
/*<       rcode=3 >*/
    rcode = 3;
/* SOURCE newlookup.for:2326 */
/*<       rval=0.5d0 >*/
    rval = .5;
/* SOURCE newlookup.for:2328 */
/*<       callspline(stdout,y,alpha,n,lcode,lval,rcode,rval,dalphady) >*/
    spline_(stdout, y, alpha, &n, &lcode, &lval, &rcode, &rval, dalphady);
/* SOURCE newlookup.for:2331 */
/*<       if(make_monotone.eq.'YES')then >*/
    if (s_cmp(feq_gen_make_monotone_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE newlookup.for:2332 */
/*<       callvrlim(n,y,alpha,dalphady,nadj,alphaflag) >*/
	vrlim_(&n, y, alpha, dalphady, &nadj, alphaflag + 1, (ftnlen)1);
/* SOURCE newlookup.for:2336 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:2338 */
/*<       callspline(stdout,y,beta,n,lcode,lval,rcode,rval,dbetady) >*/
    spline_(stdout, y, beta, &n, &lcode, &lval, &rcode, &rval, dbetady);
/* SOURCE newlookup.for:2341 */
/*<       if(make_monotone.eq.'YES')then >*/
    if (s_cmp(feq_gen_make_monotone_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE newlookup.for:2342 */
/*<       callvrlim(n,y,beta,dbetady,nadj,betaflag) >*/
	vrlim_(&n, y, beta, dbetady, &nadj, betaflag + 1, (ftnlen)1);
/* SOURCE newlookup.for:2346 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:2347 */
/*<       callspline(stdout,y,ma,n,lcode,lval,rcode,rval,dmady) >*/
    spline_(stdout, y, ma, &n, &lcode, &lval, &rcode, &rval, dmady);
/* SOURCE newlookup.for:2350 */
/*<       if(make_monotone.eq.'YES')then >*/
    if (s_cmp(feq_gen_make_monotone_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE newlookup.for:2351 */
/*<       callvrlim(n,y,ma,dmady,nadj,maflag) >*/
	vrlim_(&n, y, ma, dmady, &nadj, maflag + 1, (ftnlen)1);
/* SOURCE newlookup.for:2355 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:2356 */
/*<       callspline(stdout,y,mq,n,lcode,lval,rcode,rval,dmqdy) >*/
    spline_(stdout, y, mq, &n, &lcode, &lval, &rcode, &rval, dmqdy);
/* SOURCE newlookup.for:2359 */
/*<       if(make_monotone.eq.'YES')then >*/
    if (s_cmp(feq_gen_make_monotone_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE newlookup.for:2360 */
/*<       callvrlim(n,y,mq,dmqdy,nadj,mqflag) >*/
	vrlim_(&n, y, mq, dmqdy, &nadj, mqflag + 1, (ftnlen)1);
/* SOURCE newlookup.for:2364 */
/*<       endif >*/
    }
/* SOURCE newlookup.for:2367 */
/*<       if(verbose.eq.1)then >*/
    if (*verbose == 1) {
/* SOURCE newlookup.for:2368 */
/*<       write(stdout,70) >*/
	feq_gen_io_d__326.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__326);
	e_wsfe();
/* SOURCE newlookup.for:2369 */
/*<       write(stdout,72) >*/
	feq_gen_io_d__327.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__327);
	e_wsfe();
/* SOURCE newlookup.for:2370 */
/*<       doi=1,n >*/
	feq_gen_i_d_1 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:2371 */
/*<        >*/
	    feq_gen_io_d__328.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__328);
	    do_fio(&feq_gen_c_d_1, (char *)&y[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&kh[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&dkhdy[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&feq_gen_c_d_1, khflag + feq_gen_i_d_, (ftnlen)1);
	    do_fio(&feq_gen_c_d_1, (char *)&alpha[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&feq_gen_c_d_1, (char *)&dalphady[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&feq_gen_c_d_1, alphaflag + feq_gen_i_d_, (ftnlen)1);
	    do_fio(&feq_gen_c_d_1, (char *)&beta[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&dbetady[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&feq_gen_c_d_1, betaflag + feq_gen_i_d_, (ftnlen)1);
	    do_fio(&feq_gen_c_d_1, (char *)&ma[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&dmady[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&feq_gen_c_d_1, maflag + feq_gen_i_d_, (ftnlen)1);
	    do_fio(&feq_gen_c_d_1, (char *)&mq[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&dmqdy[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&feq_gen_c_d_1, mqflag + feq_gen_i_d_, (ftnlen)1);
	    e_wsfe();
/* SOURCE newlookup.for:2375 */
/*<       enddo >*/
	}
/* SOURCE newlookup.for:2377 */
/*<       endif >*/
    }
/*     Put the values in the standard structure */
/* SOURCE newlookup.for:2379 */
/*<       doi=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE newlookup.for:2380 */
/*<       xst(i,18)=dkhdy(i) >*/
	xst[feq_gen_i_d_ + 17982] = dkhdy[feq_gen_i_d_ - 1];
/* SOURCE newlookup.for:2381 */
/*<       xst(i,19)=dalphady(i) >*/
	xst[feq_gen_i_d_ + 18981] = dalphady[feq_gen_i_d_ - 1];
/* SOURCE newlookup.for:2382 */
/*<       xst(i,20)=dbetady(i) >*/
	xst[feq_gen_i_d_ + 19980] = dbetady[feq_gen_i_d_ - 1];
/* SOURCE newlookup.for:2383 */
/*<       xst(i,21)=dmady(i) >*/
	xst[feq_gen_i_d_ + 20979] = dmady[feq_gen_i_d_ - 1];
/* SOURCE newlookup.for:2384 */
/*<       xst(i,22)=dmqdy(i) >*/
	xst[feq_gen_i_d_ + 21978] = dmqdy[feq_gen_i_d_ - 1];
/* SOURCE newlookup.for:2385 */
/*<       enddo >*/
    }
/* SOURCE newlookup.for:2387 */
/*<       return >*/
    return 0;
/* SOURCE newlookup.for:2388 */
/*<       end >*/
} /* xsecfit_ */

#ifdef __cplusplus
	}
#endif
