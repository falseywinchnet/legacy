#include "callbacks.hpp"
/* imptrap.f -- translated by f2c (version 20240504).
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

/* COMMON ufgc1_ is declared in common.hpp. */

#define ufgc1_1 ufgc1_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_2 = 2;
static doublereal c_b113 = .33333333333333;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_5 = 5;
static doublereal c_b134 = .3333333333;




/* SOURCE imptrap.for:4 */
/*<       subroutinetd13_fdrop(stdout,ip,ptype,hu,hbase,fdrop) >*/
/* Subroutine */ int feq_gen_td13_fdrop_d_(integer *stdout, integer *ip, integer *
	ptype, real *hu, real *hbase, real *fdrop)
{
    /* Format strings */
    static char fmt_52[] = "(\002*WRN:04* HU > HMAX in two-D TABID=\002,a\
,\002 HU=\002,f10.2,\002 HMAX=\002,f10.2)";
    static char fmt_54[] = "(\002*ERR:73* Unexpected type in two-D TABID=\
\002,a,\002 Type=\002,i5,\002 expected Type=\002,i5)";

    /* System generated locals */
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer l;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer tab, lhu;
    real hul, hur;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real hmax;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char tabid[16];
    real hdropl, ddropu, hdropr;
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Find drop to free flow for a given upstream head. */
/* SOURCE imptrap.for:11 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE imptrap.for:13 */
/*<       integerip,stdout,ptype >*/
/* SOURCE imptrap.for:14 */
/*<       realhu,hbase,fdrop >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     IP     - address of the table */
/*     PTYPE  - expected table type */
/*     HU     - upstream head */
/*     HBASE  - datum for heads */
/*     DROP   - drop to free flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE imptrap.for:25 */
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
/* INCLUDE imptrap.for:26 */
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
/* SOURCE imptrap.for:29 */
/*<       integerinc >*/
/* SOURCE imptrap.for:30 */
/*<       parameter(inc=4) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE imptrap.for:33 */
/*<       integerlhu,lp,lpfd,tab,type,l >*/
/* SOURCE imptrap.for:34 */
/*<       realddropu,hdropl,hdropr,hmax,hul,hur >*/
/* SOURCE imptrap.for:35 */
/*<       charactertabid*16 >*/
/*     External names */
/* SOURCE imptrap.for:38 */
/*<       integerlenstr >*/
/* SOURCE imptrap.for:39 */
/*<       characterget_tabid*16 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE imptrap.for:42 */
/*<    52  >*/
/* SOURCE imptrap.for:44 */
/*<    54  >*/
/* *********************************************************************** */
/*     GET VALUES FROM HEADER-  MUST BE INITIALIZED ON INPUT SO THAT */
/*     POINTERS ARE SET TO THE PROPER VALUES AT START */
/* SOURCE imptrap.for:50 */
/*<       tab=itab(ip+1) >*/
/* L52: */
/* L54: */
    tab = itab[*ip + 1];
/* SOURCE imptrap.for:51 */
/*<       tabid=get_tabid(tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tab);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE imptrap.for:52 */
/*<       l=lenstr(tabid) >*/
    l = lenstr_(tabid, (ftnlen)16);
/* SOURCE imptrap.for:53 */
/*<       type=itab(ip+2) >*/
    feq_gen_type_d_ = itab[*ip + 2];
/* SOURCE imptrap.for:54 */
/*<       lhu=itab(ip+4) >*/
    lhu = itab[*ip + 4];
/* SOURCE imptrap.for:55 */
/*<       hmax=ftab(ip+9) >*/
    hmax = ftab[*ip + 9];
/* SOURCE imptrap.for:57 */
/*<       if(type.ne.ptype)then >*/
    if (feq_gen_type_d_ != *ptype) {
/* SOURCE imptrap.for:58 */
/*<       write(stdout,54)tabid(1:l),type,ptype >*/
	feq_gen_io_d__10.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__10);
	do_fio(&feq_gen_c_d_1, tabid, l);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*ptype), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE imptrap.for:59 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE imptrap.for:60 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:62 */
/*<       if(hu.gt.hmax)then >*/
    if (*hu > hmax) {
/* SOURCE imptrap.for:63 */
/*<       write(stdout,52)tabid(1:l),hu,hmax >*/
	feq_gen_io_d__11.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__11);
	do_fio(&feq_gen_c_d_1, tabid, l);
	do_fio(&feq_gen_c_d_1, (char *)&(*hu), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE imptrap.for:64 */
/*<       hu=hmax >*/
	*hu = hmax;
/* SOURCE imptrap.for:65 */
/*<       endif >*/
    }
/*     DETERMINE IF THERE IS FLOW AND IF IT IS KNOWN TO BE FREE */
/* SOURCE imptrap.for:69 */
/*<       if(hu.le.0.0)then >*/
    if (*hu <= (float)0.) {
/*       Return a zero for FDROP */
/* SOURCE imptrap.for:71 */
/*<       fdrop=0.0 >*/
	*fdrop = (float)0.;
/* SOURCE imptrap.for:72 */
/*<       return >*/
	return 0;
/* SOURCE imptrap.for:73 */
/*<       endif >*/
    }
/*     UPSTREAM LEVEL IS ABOVE BASE.  FIND THE UPSTREAM LEVEL INTERVAL */
/*     CONTAINING HU */
/* SOURCE imptrap.for:78 */
/*<       if(hu.ge.ftab(lhu))then >*/
    if (*hu >= ftab[lhu]) {
/* SOURCE imptrap.for:79 */
/*<   100 continue >*/
L100:
/* SOURCE imptrap.for:80 */
/*<       if(hu.le.ftab(lhu+inc))goto120 >*/
	if (*hu <= ftab[lhu + 4]) {
	    goto L120;
	}
/* SOURCE imptrap.for:81 */
/*<       lhu=lhu+inc >*/
	lhu += 4;
/* SOURCE imptrap.for:82 */
/*<       goto100 >*/
	goto L100;
/* SOURCE imptrap.for:83 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:84 */
/*<   110 continue >*/
L110:
/* SOURCE imptrap.for:85 */
/*<       lhu=lhu-inc >*/
	lhu += -4;
/* SOURCE imptrap.for:86 */
/*<       if(hu.ge.ftab(lhu))goto120 >*/
	if (*hu >= ftab[lhu]) {
	    goto L120;
	}
/* SOURCE imptrap.for:87 */
/*<       goto110 >*/
	goto L110;
/* SOURCE imptrap.for:88 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:89 */
/*<   120 continue >*/
L120:
/* SOURCE imptrap.for:90 */
/*<       itab(ip+4)=lhu >*/
    itab[*ip + 4] = lhu;
/*      WRITE(STDOUT,*) ' LHU AFTER SEARCH=',LHU */
/*     FREE FLOW MAY RESULT IF THE DOWNSTREAM HEAD IS */
/*     SMALL ENOUGH */
/*     FIND THE HEAD DROP CORRESPONDING TO HU */
/* SOURCE imptrap.for:99 */
/*<       hul=ftab(lhu) >*/
    hul = ftab[lhu];
/* SOURCE imptrap.for:100 */
/*<       hur=ftab(lhu+inc) >*/
    hur = ftab[lhu + 4];
/* SOURCE imptrap.for:101 */
/*<       hdropl=ftab(lhu+1) >*/
    hdropl = ftab[lhu + 1];
/* SOURCE imptrap.for:102 */
/*<       hdropr=ftab(lhu+inc+1) >*/
    hdropr = ftab[lhu + 5];
/* SOURCE imptrap.for:103 */
/*<       ddropu=(hdropr-hdropl)/(hur-hul) >*/
    ddropu = static_cast<double>((static_cast<double>(hdropr) - hdropl)) / (static_cast<double>(hur) - hul);
/* SOURCE imptrap.for:104 */
/*<       fdrop=hdropl+ddropu*(hu-hul) >*/
    *fdrop = static_cast<double>(hdropl) + static_cast<double>(ddropu) * (static_cast<double>(*hu) - hul);
/* SOURCE imptrap.for:107 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:109 */
/*<       end >*/
} /* td13_fdrop__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE imptrap.for:113 */
/*<       subroutinelkt_zb(set_interval,x,zb) >*/
/* Subroutine */ int feq_gen_lkt_zb_d_(integer *feq_gen_set_interval_d_, doublereal *x, 
	doublereal *zb)
{
    integer loc;
    doublereal frac;
    extern /* Subroutine */ int feq_gen_set_barrel_interval_d_(integer *);
    extern integer feq_gen_find_barrel_interval_d_(doublereal *);

/*     Find the bottom elevation at position X */
/* SOURCE imptrap.for:120 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:122 */
/*<       integerset_interval >*/
/* SOURCE imptrap.for:124 */
/*<       real*8x,zb >*/
/* INCLUDE imptrap.for:126 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE imptrap.for:130 */
/*<       integerloc >*/
/* SOURCE imptrap.for:131 */
/*<       real*8frac >*/
/*     Called functions */
/* SOURCE imptrap.for:135 */
/*<       integerfind_barrel_interval >*/
/* SOURCE imptrap.for:137 */
/*<       externalfind_barrel_interval,set_barrel_interval >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:139 */
/*<       if(set_interval.eq.1)then >*/
    if (*feq_gen_set_interval_d_ == 1) {
/* SOURCE imptrap.for:141 */
/*<       loc=find_barrel_interval(x) >*/
	loc = feq_gen_find_barrel_interval_d_(x);
/* SOURCE imptrap.for:143 */
/*<       callset_barrel_interval(loc) >*/
	feq_gen_set_barrel_interval_d_(&loc);
/* SOURCE imptrap.for:145 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:147 */
/*<       frac=(x-x_l)/(x_r-x_l) >*/
    frac = (*x - ufgc1_1.feq_gen_x_l_d_) / (ufgc1_1.feq_gen_x_r_d_ - ufgc1_1.feq_gen_x_l_d_);
/* SOURCE imptrap.for:148 */
/*<       zb=z_l+frac*(z_r-z_l) >*/
    *zb = ufgc1_1.feq_gen_z_l_d_ + frac * (ufgc1_1.feq_gen_z_r_d_ - ufgc1_1.feq_gen_z_l_d_);
/* SOURCE imptrap.for:149 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:150 */
/*<       end >*/
} /* lkt_zb__ */




/* SOURCE imptrap.for:154 */
/*<       subroutinelkt_ad(set_interval,x,y,ad,alphad) >*/
/* Subroutine */ int feq_gen_lkt_ad_d_(integer *feq_gen_set_interval_d_, doublereal *x, 
	doublereal *y, doublereal *ad, doublereal *alphad)
{
    real a, j, k, t, al, dk, ar, qc, dt, tp;
    integer loc;
    real beta;
    doublereal frac;
    extern /* Subroutine */ int feq_gen_set_barrel_interval_d_(integer *);
    extern integer feq_gen_find_barrel_interval_d_(doublereal *);
    real dbeta, alpha;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real dalpha, alphal, alphar;

/*     Find the area and alpha in the barrel at stations X and depth Y. */
/* SOURCE imptrap.for:161 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:163 */
/*<       integerset_interval >*/
/* SOURCE imptrap.for:165 */
/*<       real*8x,y,ad,alphad >*/
/* INCLUDE imptrap.for:167 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE imptrap.for:171 */
/*<       integerloc >*/
/* SOURCE imptrap.for:172 */
/*<        >*/
/* SOURCE imptrap.for:174 */
/*<       real*8frac >*/
/*     Called functions */
/* SOURCE imptrap.for:178 */
/*<       integerfind_barrel_interval >*/
/* SOURCE imptrap.for:180 */
/*<       externalfind_barrel_interval,set_barrel_interval >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:182 */
/*<       if(pris_flag.eq.1)then >*/
    if (ufgc1_1.feq_gen_pris_flag_d_ == 1) {
/*       Prismatic channel.  Look up elements at left end only */
/* SOURCE imptrap.for:185 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:186 */
/*<       callxlkt22(adrs_l,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_l_d_, &tp, &a, &t, &dt, &j, &k, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qc);
/* SOURCE imptrap.for:191 */
/*<       ad=dble(a) >*/
	*ad = (doublereal) a;
/* SOURCE imptrap.for:192 */
/*<       alphad=dble(alpha) >*/
	*alphad = (doublereal) alpha;
/* SOURCE imptrap.for:193 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:194 */
/*<       if(set_interval.eq.1)then >*/
	if (*feq_gen_set_interval_d_ == 1) {
/* SOURCE imptrap.for:196 */
/*<       loc=find_barrel_interval(x) >*/
	    loc = feq_gen_find_barrel_interval_d_(x);
/* SOURCE imptrap.for:198 */
/*<       callset_barrel_interval(loc) >*/
	    feq_gen_set_barrel_interval_d_(&loc);
/* SOURCE imptrap.for:200 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:202 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:203 */
/*<       callxlkt22(adrs_l,tp,al,t,dt,j,k,dk,beta,dbeta,alphal,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_l_d_, &tp, &al, &t, &dt, &j, &k, &dk, &beta, &
		dbeta, &alphal, &dalpha, &qc);
/* SOURCE imptrap.for:208 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:209 */
/*<       callxlkt22(adrs_r,tp,ar,t,dt,j,k,dk,beta,dbeta,alphar,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_r_d_, &tp, &ar, &t, &dt, &j, &k, &dk, &beta, &
		dbeta, &alphar, &dalpha, &qc);
/* SOURCE imptrap.for:214 */
/*<       frac=(x-x_l)/(x_r-x_l) >*/
	frac = (*x - ufgc1_1.feq_gen_x_l_d_) / (ufgc1_1.feq_gen_x_r_d_ - ufgc1_1.feq_gen_x_l_d_);
/* SOURCE imptrap.for:215 */
/*<       ad=dble(al)+frac*(dble(ar)-dble(al)) >*/
	*ad = (doublereal) al + frac * ((doublereal) ar - (doublereal) al);
/* SOURCE imptrap.for:216 */
/*<       alphad=dble(alphal)+frac*(dble(alphar)-dble(alphal)) >*/
	*alphad = (doublereal) alphal + frac * ((doublereal) alphar - (
		doublereal) alphal);
/* SOURCE imptrap.for:217 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:218 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:219 */
/*<       end >*/
} /* lkt_ad__ */




/* SOURCE imptrap.for:223 */
/*<       subroutinelkt_jda(set_interval,x,y,ad,jd) >*/
/* Subroutine */ int feq_gen_lkt_jda_d_(integer *feq_gen_set_interval_d_, doublereal *x, 
	doublereal *y, doublereal *ad, doublereal *jd)
{
    real a, j, k, t, al, dk, ar, qc, jl, dt, jr, tp;
    integer loc;
    real beta;
    doublereal frac;
    extern /* Subroutine */ int feq_gen_set_barrel_interval_d_(integer *);
    extern integer feq_gen_find_barrel_interval_d_(doublereal *);
    real dbeta, alpha;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real dalpha;

/*     Find the first moment in the barrel at stations X and depth Y. */
/* SOURCE imptrap.for:229 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:231 */
/*<       integerset_interval >*/
/* SOURCE imptrap.for:233 */
/*<       real*8x,y,ad,jd >*/
/* INCLUDE imptrap.for:235 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE imptrap.for:239 */
/*<       integerloc >*/
/* SOURCE imptrap.for:240 */
/*<       realal,ar,jl,jr,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qc >*/
/* SOURCE imptrap.for:243 */
/*<       real*8frac >*/
/*     Called functions */
/* SOURCE imptrap.for:246 */
/*<       integerfind_barrel_interval >*/
/* SOURCE imptrap.for:248 */
/*<       externalfind_barrel_interval,set_barrel_interval >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:250 */
/*<       if(pris_flag.eq.1)then >*/
    if (ufgc1_1.feq_gen_pris_flag_d_ == 1) {
/*       Prismatic channel.  Look up elements at left end only */
/* SOURCE imptrap.for:253 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:254 */
/*<       callxlkt22(adrs_l,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_l_d_, &tp, &a, &t, &dt, &j, &k, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qc);
/* SOURCE imptrap.for:259 */
/*<       ad=dble(a) >*/
	*ad = (doublereal) a;
/* SOURCE imptrap.for:260 */
/*<       jd=dble(j) >*/
	*jd = (doublereal) j;
/* SOURCE imptrap.for:262 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:263 */
/*<       if(set_interval.eq.1)then >*/
	if (*feq_gen_set_interval_d_ == 1) {
/* SOURCE imptrap.for:265 */
/*<       loc=find_barrel_interval(x) >*/
	    loc = feq_gen_find_barrel_interval_d_(x);
/* SOURCE imptrap.for:267 */
/*<       callset_barrel_interval(loc) >*/
	    feq_gen_set_barrel_interval_d_(&loc);
/* SOURCE imptrap.for:269 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:271 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:272 */
/*<       callxlkt22(adrs_l,tp,al,t,dt,jl,k,dk,beta,dbeta,alpha,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_l_d_, &tp, &al, &t, &dt, &jl, &k, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qc);
/* SOURCE imptrap.for:277 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:278 */
/*<       callxlkt22(adrs_r,tp,ar,t,dt,jr,k,dk,beta,dbeta,alpha,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_r_d_, &tp, &ar, &t, &dt, &jr, &k, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qc);
/* SOURCE imptrap.for:283 */
/*<       frac=(x-x_l)/(x_r-x_l) >*/
	frac = (*x - ufgc1_1.feq_gen_x_l_d_) / (ufgc1_1.feq_gen_x_r_d_ - ufgc1_1.feq_gen_x_l_d_);
/* SOURCE imptrap.for:284 */
/*<       jd=dble(jl)+frac*(dble(jr)-dble(jl)) >*/
	*jd = (doublereal) jl + frac * ((doublereal) jr - (doublereal) jl);
/* SOURCE imptrap.for:285 */
/*<       ad=dble(al)+frac*(dble(ar)-dble(al)) >*/
	*ad = (doublereal) al + frac * ((doublereal) ar - (doublereal) al);
/* SOURCE imptrap.for:286 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:287 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:288 */
/*<       end >*/
} /* lkt_jda__ */




/* SOURCE imptrap.for:292 */
/*<       subroutinelkt_qcd(set_interval,x,y,qcd) >*/
/* Subroutine */ int feq_gen_lkt_qcd_d_(integer *feq_gen_set_interval_d_, doublereal *x, 
	doublereal *y, doublereal *qcd)
{
    real a, j, k, t, dk, qc, dt, tp;
    integer loc;
    real qcl, qcr, beta;
    doublereal frac;
    extern /* Subroutine */ int feq_gen_set_barrel_interval_d_(integer *);
    extern integer feq_gen_find_barrel_interval_d_(doublereal *);
    real dbeta, alpha;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real dalpha;

/*     Find critical flow in the barrel at stations X and depth Y. */
/* SOURCE imptrap.for:299 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:301 */
/*<       integerset_interval >*/
/* SOURCE imptrap.for:303 */
/*<       real*8x,y,qcd >*/
/* INCLUDE imptrap.for:305 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE imptrap.for:309 */
/*<       integerloc >*/
/* SOURCE imptrap.for:310 */
/*<       realqcl,qcr,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qc >*/
/* SOURCE imptrap.for:312 */
/*<       real*8frac >*/
/*     Called functions */
/* SOURCE imptrap.for:316 */
/*<       integerfind_barrel_interval >*/
/* SOURCE imptrap.for:318 */
/*<       externalfind_barrel_interval,set_barrel_interval >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:320 */
/*<       if(pris_flag.eq.1)then >*/
    if (ufgc1_1.feq_gen_pris_flag_d_ == 1) {
/*       Prismatic channel.  Look up elements at left end only */
/* SOURCE imptrap.for:323 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:324 */
/*<       callxlkt22(adrs_l,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_l_d_, &tp, &a, &t, &dt, &j, &k, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qc);
/* SOURCE imptrap.for:329 */
/*<       qcd=dble(qc) >*/
	*qcd = (doublereal) qc;
/* SOURCE imptrap.for:330 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:331 */
/*<       if(set_interval.eq.1)then >*/
	if (*feq_gen_set_interval_d_ == 1) {
/* SOURCE imptrap.for:333 */
/*<       loc=find_barrel_interval(x) >*/
	    loc = feq_gen_find_barrel_interval_d_(x);
/* SOURCE imptrap.for:335 */
/*<       callset_barrel_interval(loc) >*/
	    feq_gen_set_barrel_interval_d_(&loc);
/* SOURCE imptrap.for:337 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:339 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:340 */
/*<       callxlkt22(adrs_l,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qcl) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_l_d_, &tp, &a, &t, &dt, &j, &k, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qcl);
/* SOURCE imptrap.for:345 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:346 */
/*<       callxlkt22(adrs_r,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qcr) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_r_d_, &tp, &a, &t, &dt, &j, &k, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qcr);
/* SOURCE imptrap.for:351 */
/*<       frac=(x-x_l)/(x_r-x_l) >*/
	frac = (*x - ufgc1_1.feq_gen_x_l_d_) / (ufgc1_1.feq_gen_x_r_d_ - ufgc1_1.feq_gen_x_l_d_);
/* SOURCE imptrap.for:352 */
/*<       qcd=dble(qcl)+frac*(dble(qcr)-dble(qcl)) >*/
	*qcd = (doublereal) qcl + frac * ((doublereal) qcr - (doublereal) qcl)
		;
/* SOURCE imptrap.for:353 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:354 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:355 */
/*<       end >*/
} /* lkt_qcd__ */




/* SOURCE imptrap.for:359 */
/*<       subroutinelkt_kd(set_interval,x,y,kd) >*/
/* Subroutine */ int feq_gen_lkt_kd_d_(integer *feq_gen_set_interval_d_, doublereal *x, 
	doublereal *y, doublereal *kd)
{
    real a, j, k, t, dk, qc, kl, dt, kr, tp;
    integer loc;
    real beta;
    doublereal frac;
    extern /* Subroutine */ int feq_gen_set_barrel_interval_d_(integer *);
    extern integer feq_gen_find_barrel_interval_d_(doublereal *);
    real dbeta, alpha;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real dalpha;

/*     Find the conveyance in the barrel at stations X and depth Y. */
/* SOURCE imptrap.for:366 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:368 */
/*<       integerset_interval >*/
/* SOURCE imptrap.for:370 */
/*<       real*8x,y,kd >*/
/* INCLUDE imptrap.for:372 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE imptrap.for:376 */
/*<       integerloc >*/
/* SOURCE imptrap.for:377 */
/*<       realkl,kr,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qc >*/
/* SOURCE imptrap.for:379 */
/*<       real*8frac >*/
/*     Called functions */
/* SOURCE imptrap.for:383 */
/*<       integerfind_barrel_interval >*/
/* SOURCE imptrap.for:385 */
/*<       externalfind_barrel_interval,set_barrel_interval >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:387 */
/*<       if(pris_flag.eq.1)then >*/
    if (ufgc1_1.feq_gen_pris_flag_d_ == 1) {
/*       Prismatic channel.  Look up elements at left end only */
/* SOURCE imptrap.for:390 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:391 */
/*<       callxlkt22(adrs_l,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_l_d_, &tp, &a, &t, &dt, &j, &k, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qc);
/* SOURCE imptrap.for:396 */
/*<       kd=dble(k) >*/
	*kd = (doublereal) k;
/* SOURCE imptrap.for:397 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:398 */
/*<       if(set_interval.eq.1)then >*/
	if (*feq_gen_set_interval_d_ == 1) {
/* SOURCE imptrap.for:400 */
/*<       loc=find_barrel_interval(x) >*/
	    loc = feq_gen_find_barrel_interval_d_(x);
/* SOURCE imptrap.for:402 */
/*<       callset_barrel_interval(loc) >*/
	    feq_gen_set_barrel_interval_d_(&loc);
/* SOURCE imptrap.for:404 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:406 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:407 */
/*<       callxlkt22(adrs_l,tp,a,t,dt,j,kl,dk,beta,dbeta,alpha,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_l_d_, &tp, &a, &t, &dt, &j, &kl, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qc);
/* SOURCE imptrap.for:412 */
/*<       tp=sngl(y) >*/
	tp = (real) (*y);
/* SOURCE imptrap.for:413 */
/*<       callxlkt22(adrs_r,tp,a,t,dt,j,kr,dk,beta,dbeta,alpha,dalpha,qc) >*/
	xlkt22_(&ufgc1_1.feq_gen_adrs_r_d_, &tp, &a, &t, &dt, &j, &kr, &dk, &beta, &
		dbeta, &alpha, &dalpha, &qc);
/* SOURCE imptrap.for:418 */
/*<       frac=(x-x_l)/(x_r-x_l) >*/
	frac = (*x - ufgc1_1.feq_gen_x_l_d_) / (ufgc1_1.feq_gen_x_r_d_ - ufgc1_1.feq_gen_x_l_d_);
/* SOURCE imptrap.for:419 */
/*<       kd=dble(kl)+frac*(dble(kr)-dble(kl)) >*/
	*kd = (doublereal) kl + frac * ((doublereal) kr - (doublereal) kl);
/* SOURCE imptrap.for:420 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:421 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:422 */
/*<       end >*/
} /* lkt_kd__ */




/* SOURCE imptrap.for:428 */
/*<        >*/
/* Subroutine */ int feq_gen_get_ycynym_d_(integer *stdout, doublereal *x, doublereal *
	epsarg, doublereal *epsf, doublereal *epsabs, doublereal *ycrit, 
	doublereal *ynorm, doublereal *ymax, integer *rflag)
{
    integer loc;
    extern /* Subroutine */ int feq_gen_find_ycynym_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), feq_gen_set_barrel_interval_d_(
	    integer *);
    extern integer feq_gen_find_barrel_interval_d_(doublereal *);

/*     Find the values of critical depth, normal depth (if it exists), */
/*     and the maximum argument.  Sets the channel interval */
/*     before calling FIND_YCYNYM.  On entry, YCRIT and YNORM should */
/*     be estimates of the critical depth and normal depth respectively. */
/*     If normal depth does not exist, the input value of YNORM is ignored */
/*     and a value of -1.0 is returned for the normal depth. */
/* SOURCE imptrap.for:440 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:442 */
/*<       integerstdout,rflag >*/
/* SOURCE imptrap.for:444 */
/*<       real*8x,ycrit,ynorm,ymax,epsarg,epsf,epsabs >*/
/* INCLUDE imptrap.for:447 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     External function */
/* SOURCE imptrap.for:451 */
/*<       integerfind_barrel_interval >*/
/*     Called routines */
/* SOURCE imptrap.for:455 */
/*<       externalfind_barrel_interval,set_barrel_interval,find_ycynym >*/
/*     Local */
/* SOURCE imptrap.for:459 */
/*<       integerloc >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:463 */
/*<       loc=find_barrel_interval(x) >*/
    loc = feq_gen_find_barrel_interval_d_(x);
/* SOURCE imptrap.for:465 */
/*<       callset_barrel_interval(loc) >*/
    feq_gen_set_barrel_interval_d_(&loc);
/* SOURCE imptrap.for:467 */
/*<        >*/
    feq_gen_find_ycynym_d_(stdout, x, epsarg, epsf, epsabs, ycrit, ynorm, ymax, rflag);
/* SOURCE imptrap.for:472 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:473 */
/*<       end >*/
} /* get_ycynym__ */





/* SOURCE imptrap.for:478 */
/*<       subroutinedfndcd(stdout,epsarg,epsf,epsabs,ymax,ye,flag) >*/
/* Subroutine */ int dfndcd_(integer *stdout, doublereal *epsarg, doublereal *
	epsf, doublereal *epsabs, doublereal *ymax, doublereal *ye, integer *
	feq_gen_flag_d_)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:743* TABID=\002,a,\002 Table overflow\
 seeeking critical\002,\002 depth for flow=\002,f10.2,11x,\002 D=\002,f10.2)";
    static char fmt_52[] = "(\002 *ERR:626* TABID=\002,a,\002 Underflow seek\
ing norm. depth for\002,\002 flow=\002,f10.3)";
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT FDBLRGF C\
LAIMS NONE IN\002,\002 DFNDCD.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* FDBLRGF ITERATION>100 IN DFNDC\
D\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    extern doublereal feq_gen_yc_resid_d_(doublereal *);
    doublereal y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal fl, fr, yl, yr;
    char tabid[16];
    extern integer gettbn_(integer *), lenstr_(char *, ftnlen);
    extern /* Subroutine */ int fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Find critial depth for the given bottom slope. Full double */
/*     precsion version for UFGCULV. */
/* SOURCE imptrap.for:487 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE imptrap.for:490 */
/*<       integerflag,stdout >*/
/* SOURCE imptrap.for:491 */
/*<       real*8epsarg,epsf,epsabs,ye,ymax >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     YE     - Normal depth with initial estimate on entry */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE imptrap.for:498 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE imptrap.for:501 */
/*<       real*8fl,fr,y,yl,yr >*/
/* SOURCE imptrap.for:502 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE imptrap.for:505 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE imptrap.for:508 */
/*<       integergettbn,lenstr >*/
/* SOURCE imptrap.for:509 */
/*<       real*8yc_resid >*/
/* SOURCE imptrap.for:510 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE imptrap.for:513 */
/*<       externalgettbn,yc_resid,get_tabid,lenstr >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE imptrap.for:516 */
/*<    50  >*/
/* SOURCE imptrap.for:518 */
/*<    52  >*/
/* SOURCE imptrap.for:520 */
/*<    54  >*/
/* SOURCE imptrap.for:522 */
/*<    60 format(' *BUG:XXX* FDBLRGF ITERATION>100 IN DFNDCD') >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:524 */
/*<       flag=0 >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
    *feq_gen_flag_d_ = 0;
/*      WRITE(STDOUT,*) ' Entering DFNDCD with YE=',YE */
/*     SEARCH FOR A positive RESIDUAL */
/* SOURCE imptrap.for:530 */
/*<       yr=ye >*/
    yr = *ye;
/* SOURCE imptrap.for:531 */
/*<       yl=-1.d0 >*/
    yl = -1.;
/* SOURCE imptrap.for:532 */
/*<   100 continue >*/
L100:
/* SOURCE imptrap.for:533 */
/*<       fr=yc_resid(yr) >*/
    fr = feq_gen_yc_resid_d_(&yr);
/*        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE imptrap.for:535 */
/*<       if(fr.ge.0.0d0)then >*/
    if (fr >= 0.) {
/* SOURCE imptrap.for:536 */
/*<       goto110 >*/
	goto L110;
/* SOURCE imptrap.for:537 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:538 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE imptrap.for:539 */
/*<       fl=fr >*/
	fl = fr;
/* SOURCE imptrap.for:540 */
/*<       yr=0.7*yr+0.3*vert_d >*/
	yr = yr * (float).7 + ufgc1_1.feq_gen_vert_d_d_ * (float).3;
/* SOURCE imptrap.for:541 */
/*<       if(abs(yr-ymax).le.epsarg)then >*/
	if ((feq_gen_d_d_1 = yr - *ymax, abs(feq_gen_d_d_1)) <= *epsarg) {
/* SOURCE imptrap.for:542 */
/*<       tabid=get_tabid(gettbn(adrs_l)) >*/
	    feq_gen_i_d_1 = gettbn_(&ufgc1_1.feq_gen_adrs_l_d_);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE imptrap.for:543 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),qd,vert_d >*/
	    feq_gen_io_d__93.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__93);
	    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	    do_fio(&feq_gen_c_d_1, (char *)&ufgc1_1.qd, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&ufgc1_1.feq_gen_vert_d_d_, (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
/* SOURCE imptrap.for:544 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE imptrap.for:545 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:546 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:547 */
/*<       goto100 >*/
	goto L100;
/* SOURCE imptrap.for:548 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:549 */
/*<   110 continue >*/
L110:
/*     POSITIVE RESIDUAL FOUND- SEARCH FOR NEGATIVE RESIDUAL */
/* SOURCE imptrap.for:552 */
/*<       if(yl.lt.0.0d0)then >*/
    if (yl < 0.) {
/* SOURCE imptrap.for:553 */
/*<       yl=0.6d0*yr >*/
	yl = yr * .6;
/* SOURCE imptrap.for:554 */
/*<   120 continue >*/
L120:
/* SOURCE imptrap.for:555 */
/*<       fl=yc_resid(yl) >*/
	fl = feq_gen_yc_resid_d_(&yl);
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE imptrap.for:557 */
/*<       if(fl.le.0.0d0)then >*/
	if (fl <= 0.) {
/* SOURCE imptrap.for:558 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE imptrap.for:559 */
/*<       else >*/
	} else {
/* SOURCE imptrap.for:560 */
/*<       fr=fl >*/
	    fr = fl;
/* SOURCE imptrap.for:561 */
/*<       yr=yl >*/
	    yr = yl;
/* SOURCE imptrap.for:562 */
/*<       yl=0.6d0*yl >*/
	    yl *= .6;
/* SOURCE imptrap.for:563 */
/*<       if(abs(yl).lt.epsabs)then >*/
	    if (abs(yl) < *epsabs) {
/* SOURCE imptrap.for:564 */
/*<       tabid=get_tabid(gettbn(adrs_l)) >*/
		feq_gen_i_d_1 = gettbn_(&ufgc1_1.feq_gen_adrs_l_d_);
		feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
		s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE imptrap.for:565 */
/*<       write(stdout,52)tabid(1:lenstr(tabid)),qd >*/
		feq_gen_io_d__94.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__94);
		do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		do_fio(&feq_gen_c_d_1, (char *)&ufgc1_1.qd, (ftnlen)sizeof(doublereal))
			;
		e_wsfe();
/* SOURCE imptrap.for:566 */
/*<       flag=1 >*/
		*feq_gen_flag_d_ = 1;
/* SOURCE imptrap.for:567 */
/*<       goto1000 >*/
		goto L1000;
/* SOURCE imptrap.for:568 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:569 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE imptrap.for:570 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:571 */
/*<   130 continue >*/
L130:
/* SOURCE imptrap.for:572 */
/*<       endif >*/
	;
    }
/*     WE HAVE A SIGN CHANGE OR ONE OR BOTH POINTS HAVE ZERO RESIDUAL */
/*      WRITE(STDOUT,*) ' Calling FDBLRGF with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE imptrap.for:579 */
/*<       callfdblrgf(epsarg,epsf,yc_resid,yl,yr,fl,fr,y,flag) >*/
    fdblrgf_(epsarg, epsf, feq_gen_yc_resid_d_, &yl, &yr, &fl, &fr, &y, feq_gen_flag_d_);
/* SOURCE imptrap.for:583 */
/*<       ye=y >*/
    *ye = y;
/* SOURCE imptrap.for:584 */
/*<       if(flag.eq.3)flag=0 >*/
    if (*feq_gen_flag_d_ == 3) {
	*feq_gen_flag_d_ = 0;
    }
/*      WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' Y =',Y,' FL=',FL */
/*      WRITE(STDOUT,*) ' EPSARG=',EPSARG,' EPSF=',EPSF */
/* SOURCE imptrap.for:590 */
/*<       if(flag.eq.1)then >*/
    if (*feq_gen_flag_d_ == 1) {
/* SOURCE imptrap.for:591 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__96.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__96);
	e_wsfe();
/* SOURCE imptrap.for:592 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:593 */
/*<       elseif(flag.eq.2)then >*/
    } else if (*feq_gen_flag_d_ == 2) {
/* SOURCE imptrap.for:594 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__97.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__97);
	e_wsfe();
/* SOURCE imptrap.for:595 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:596 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:598 */
/*<  1000 continue >*/
L1000:
/* SOURCE imptrap.for:599 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:600 */
/*<       end >*/
} /* dfndcd_ */




/* SOURCE imptrap.for:604 */
/*<       subroutinedfndnd(stdout,epsarg,epsf,epsabs,ymax,ye,flag) >*/
/* Subroutine */ int dfndnd_(integer *stdout, doublereal *epsarg, doublereal *
	epsf, doublereal *epsabs, doublereal *ymax, doublereal *ye, integer *
	feq_gen_flag_d_)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:744* TABID=\002,a,\002 Soffit found s\
eeking normal\002,\002 depth for flow=\002,f10.2,11x,\002 D=\002,f10.2)";
    static char fmt_52[] = "(\002 *ERR:626* TABID=\002,a,\002 Underflow seek\
ing norm. depth for\002,\002 flow=\002,f10.3)";
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT FDBLRGF C\
LAIMS NONE IN\002,\002 DFNDND.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* FDBLRGF ITERATION>100 IN DFNDN\
D\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    doublereal feq_gen_res_at_d_d_;
    extern doublereal feq_gen_yn_resid_d_(doublereal *);
    doublereal y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal fl, fr, yl, yr;
    char tabid[16];
    extern integer gettbn_(integer *), lenstr_(char *, ftnlen);
    extern /* Subroutine */ int fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Find normal depth for the given bottom slope. Full double */
/*     precsion version for UFGCULV. */
/* SOURCE imptrap.for:613 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE imptrap.for:616 */
/*<       integerflag,stdout >*/
/* SOURCE imptrap.for:617 */
/*<       real*8epsarg,epsf,epsabs,ye,ymax >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     YE     - Normal depth with initial estimate on entry */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE imptrap.for:624 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE imptrap.for:627 */
/*<       real*8fl,fr,res_at_d,y,yl,yr >*/
/* SOURCE imptrap.for:628 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE imptrap.for:631 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE imptrap.for:634 */
/*<       integergettbn,lenstr >*/
/* SOURCE imptrap.for:635 */
/*<       real*8yn_resid >*/
/* SOURCE imptrap.for:636 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE imptrap.for:639 */
/*<       externalgettbn,yn_resid,get_tabid,lenstr >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE imptrap.for:642 */
/*<    50  >*/
/* SOURCE imptrap.for:644 */
/*<    52  >*/
/* SOURCE imptrap.for:646 */
/*<    54  >*/
/* SOURCE imptrap.for:648 */
/*<    60 format(' *BUG:XXX* FDBLRGF ITERATION>100 IN DFNDND') >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:650 */
/*<       flag=0 >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
    *feq_gen_flag_d_ = 0;
/*      WRITE(STDOUT,*) ' Entering DFNDND with YE=',YE */
/*     Compute the residual at the vertical diameter in the culvert. */
/*     The residual function is defined such that if > 0 then */
/*     QD > the normal flow at the given depth. */
/* SOURCE imptrap.for:658 */
/*<       res_at_d=yn_resid(vert_d) >*/
    feq_gen_res_at_d_d_ = feq_gen_yn_resid_d_(&ufgc1_1.feq_gen_vert_d_d_);
/*      WRITE(STDOUT,*) ' RES_AT_D=',RES_AT_D */
/* SOURCE imptrap.for:661 */
/*<       if(res_at_d.gt.0.d0)then >*/
    if (feq_gen_res_at_d_d_ > 0.) {
/*       The normal depth is above the culvert soffit. */
/*       We assume that the capacity of the barrel */
/*       is not increased when we are in the slot.  Thus */
/*       the normal depth should be made as large as */
/*       possible and still remain within the range of the */
/*       cross-section function tables involved. */
/* SOURCE imptrap.for:669 */
/*<       ye=ymax >*/
	*ye = *ymax;
/* SOURCE imptrap.for:670 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:671 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:673 */
/*<       if(ye.gt.vert_d)then >*/
    if (*ye > ufgc1_1.feq_gen_vert_d_d_) {
/*       Adjust to be less than VERT_D */
/* SOURCE imptrap.for:675 */
/*<       ye=0.5d0*vert_d >*/
	*ye = ufgc1_1.feq_gen_vert_d_d_ * .5;
/* SOURCE imptrap.for:676 */
/*<       endif >*/
    }
/*     SEARCH FOR A negative RESIDUAL */
/* SOURCE imptrap.for:679 */
/*<       yr=ye >*/
    yr = *ye;
/* SOURCE imptrap.for:680 */
/*<       yl=-1.d0 >*/
    yl = -1.;
/* SOURCE imptrap.for:681 */
/*<   100 continue >*/
L100:
/* SOURCE imptrap.for:682 */
/*<       fr=yn_resid(yr) >*/
    fr = feq_gen_yn_resid_d_(&yr);
/*        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE imptrap.for:684 */
/*<       if(fr.le.0.0d0)then >*/
    if (fr <= 0.) {
/* SOURCE imptrap.for:685 */
/*<       goto110 >*/
	goto L110;
/* SOURCE imptrap.for:686 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:687 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE imptrap.for:688 */
/*<       fl=fr >*/
	fl = fr;
/* SOURCE imptrap.for:689 */
/*<       yr=0.7*yr+0.3*vert_d >*/
	yr = yr * (float).7 + ufgc1_1.feq_gen_vert_d_d_ * (float).3;
/* SOURCE imptrap.for:690 */
/*<       if(abs(yr-vert_d).le.epsarg)then >*/
	if ((feq_gen_d_d_1 = yr - ufgc1_1.feq_gen_vert_d_d_, abs(feq_gen_d_d_1)) <= *epsarg) {
/* SOURCE imptrap.for:691 */
/*<       tabid=get_tabid(gettbn(adrs_l)) >*/
	    feq_gen_i_d_1 = gettbn_(&ufgc1_1.feq_gen_adrs_l_d_);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE imptrap.for:692 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),qd,vert_d >*/
	    feq_gen_io_d__104.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__104);
	    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	    do_fio(&feq_gen_c_d_1, (char *)&ufgc1_1.qd, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&ufgc1_1.feq_gen_vert_d_d_, (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
/* SOURCE imptrap.for:693 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE imptrap.for:694 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:695 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:696 */
/*<       goto100 >*/
	goto L100;
/* SOURCE imptrap.for:697 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:698 */
/*<   110 continue >*/
L110:
/*     Negative RESIDUAL FOUND- SEARCH FOR positive RESIDUAL */
/* SOURCE imptrap.for:701 */
/*<       if(yl.lt.0.0d0)then >*/
    if (yl < 0.) {
/* SOURCE imptrap.for:702 */
/*<       yl=0.6d0*yr >*/
	yl = yr * .6;
/* SOURCE imptrap.for:703 */
/*<   120 continue >*/
L120:
/* SOURCE imptrap.for:704 */
/*<       fl=yn_resid(yl) >*/
	fl = feq_gen_yn_resid_d_(&yl);
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE imptrap.for:706 */
/*<       if(fl.ge.0.0d0)then >*/
	if (fl >= 0.) {
/* SOURCE imptrap.for:707 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE imptrap.for:708 */
/*<       else >*/
	} else {
/* SOURCE imptrap.for:709 */
/*<       fr=fl >*/
	    fr = fl;
/* SOURCE imptrap.for:710 */
/*<       yr=yl >*/
	    yr = yl;
/* SOURCE imptrap.for:711 */
/*<       yl=0.6d0*yl >*/
	    yl *= .6;
/* SOURCE imptrap.for:712 */
/*<       if(abs(yl).lt.epsabs)then >*/
	    if (abs(yl) < *epsabs) {
/* SOURCE imptrap.for:713 */
/*<       tabid=get_tabid(gettbn(adrs_l)) >*/
		feq_gen_i_d_1 = gettbn_(&ufgc1_1.feq_gen_adrs_l_d_);
		feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
		s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE imptrap.for:714 */
/*<       write(stdout,52)tabid(1:lenstr(tabid)),qd >*/
		feq_gen_io_d__105.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__105);
		do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		do_fio(&feq_gen_c_d_1, (char *)&ufgc1_1.qd, (ftnlen)sizeof(doublereal))
			;
		e_wsfe();
/* SOURCE imptrap.for:715 */
/*<       flag=1 >*/
		*feq_gen_flag_d_ = 1;
/* SOURCE imptrap.for:716 */
/*<       goto1000 >*/
		goto L1000;
/* SOURCE imptrap.for:717 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:718 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE imptrap.for:719 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:720 */
/*<   130 continue >*/
L130:
/* SOURCE imptrap.for:721 */
/*<       endif >*/
	;
    }
/*     WE HAVE A SIGN CHANGE OR ONE OR BOTH POINTS HAVE ZERO RESIDUAL */
/*      WRITE(STDOUT,*) ' Calling FDBLRGF with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE imptrap.for:728 */
/*<       callfdblrgf(epsarg,epsf,yn_resid,yl,yr,fl,fr,y,flag) >*/
    fdblrgf_(epsarg, epsf, feq_gen_yn_resid_d_, &yl, &yr, &fl, &fr, &y, feq_gen_flag_d_);
/* SOURCE imptrap.for:732 */
/*<       ye=y >*/
    *ye = y;
/* SOURCE imptrap.for:733 */
/*<       if(flag.eq.3)flag=0 >*/
    if (*feq_gen_flag_d_ == 3) {
	*feq_gen_flag_d_ = 0;
    }
/*      WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' Y =',Y,' FL=',FL */
/*      WRITE(STDOUT,*) ' EPSARG=',EPSARG,' EPSF=',EPSF */
/* SOURCE imptrap.for:739 */
/*<       if(flag.eq.1)then >*/
    if (*feq_gen_flag_d_ == 1) {
/* SOURCE imptrap.for:740 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__107.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__107);
	e_wsfe();
/* SOURCE imptrap.for:741 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:742 */
/*<       elseif(flag.eq.2)then >*/
    } else if (*feq_gen_flag_d_ == 2) {
/* SOURCE imptrap.for:743 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__108.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__108);
	e_wsfe();
/* SOURCE imptrap.for:744 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:745 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:747 */
/*<  1000 continue >*/
L1000:
/* SOURCE imptrap.for:748 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:749 */
/*<       end >*/
} /* dfndnd_ */




/* SOURCE imptrap.for:753 */
/*<       real*8functione(x,y) >*/
doublereal e_(doublereal *x, doublereal *y)
{
    /* System generated locals */
    doublereal ret_val, feq_gen_d_d_1;

    /* Local variables */
    doublereal ad, alphad;
    extern /* Subroutine */ int feq_gen_lkt_ad_d_(integer *, doublereal *, doublereal *
	    , doublereal *, doublereal *);

/*     Compute the conservation quantity. */
/* SOURCE imptrap.for:757 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:758 */
/*<       real*8x,y >*/
/* INCLUDE imptrap.for:760 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE imptrap.for:761 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE imptrap.for:763 */
/*<       real*8ad,alphad >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:765 */
/*<       calllkt_ad(0,x,y,ad,alphad) >*/
    feq_gen_lkt_ad_d_(&feq_gen_c_d_0, x, y, &ad, &alphad);
/* SOURCE imptrap.for:769 */
/*<       e=alphad*(qd/ad)**2/dble(grav2)+y*cos_theta >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd / ad;
    ret_val = alphad * (feq_gen_d_d_1 * feq_gen_d_d_1) / (doublereal) grvcom_1.grav2 + *y * 
	    ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE imptrap.for:771 */
/*<       return >*/
    return ret_val;
/* SOURCE imptrap.for:772 */
/*<       end >*/
} /* e_ */




/* SOURCE imptrap.for:776 */
/*<       real*8functionrhse(x,y) >*/
doublereal rhse_(doublereal *x, doublereal *y)
{
    /* System generated locals */
    doublereal ret_val, feq_gen_d_d_1;

    /* Local variables */
    doublereal kd;
    extern /* Subroutine */ int feq_gen_lkt_kd_d_(integer *, doublereal *, doublereal *
	    , doublereal *);

/*     Right-hand-side function. */
/* SOURCE imptrap.for:779 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:781 */
/*<       real*8x,y >*/
/* INCLUDE imptrap.for:783 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE imptrap.for:787 */
/*<       real*8kd >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:789 */
/*<       calllkt_kd(0,x,y,kd) >*/
    feq_gen_lkt_kd_d_(&feq_gen_c_d_0, x, y, &kd);
/* SOURCE imptrap.for:793 */
/*<       rhse=sin_theta-abs(qd)*qd/kd**2 >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = kd;
    ret_val = ufgc1_1.feq_gen_sin_theta_d_ - abs(ufgc1_1.qd) * ufgc1_1.qd / (feq_gen_d_d_1 * 
	    feq_gen_d_d_1);
/* SOURCE imptrap.for:794 */
/*<       return >*/
    return ret_val;
/* SOURCE imptrap.for:795 */
/*<       end >*/
} /* rhse_ */




/* SOURCE imptrap.for:799 */
/*<       real*8functionyc_resid(y) >*/
doublereal feq_gen_yc_resid_d_(doublereal *y)
{
    /* System generated locals */
    doublereal ret_val, feq_gen_d_d_1;

    /* Local variables */
    doublereal qcd;
    extern /* Subroutine */ int feq_gen_lkt_qcd_d_(integer *, doublereal *, doublereal 
	    *, doublereal *);

/*     Residual function for finding critical depth. */
/* SOURCE imptrap.for:803 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:804 */
/*<       real*8y >*/
/* INCLUDE imptrap.for:806 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local */
/* SOURCE imptrap.for:810 */
/*<       real*8qcd >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:812 */
/*<       calllkt_qcd(0,xloc,y,qcd) >*/
    feq_gen_lkt_qcd_d_(&feq_gen_c_d_0, &ufgc1_1.xloc, y, &qcd);
/* SOURCE imptrap.for:816 */
/*<       yc_resid=(cos_theta-(qd/qcd)**2) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd / qcd;
    ret_val = ufgc1_1.feq_gen_cos_theta_d_ - feq_gen_d_d_1 * feq_gen_d_d_1;
/* SOURCE imptrap.for:817 */
/*<       return >*/
    return ret_val;
/* SOURCE imptrap.for:818 */
/*<       end >*/
} /* yc_resid__ */




/* SOURCE imptrap.for:822 */
/*<       real*8functionyn_resid(y) >*/
doublereal feq_gen_yn_resid_d_(doublereal *y)
{
    /* System generated locals */
    doublereal ret_val, feq_gen_d_d_1;

    /* Local variables */
    doublereal kd;
    extern /* Subroutine */ int feq_gen_lkt_kd_d_(integer *, doublereal *, doublereal *
	    , doublereal *);

/*     Residual function for finding normal depth. */
/* SOURCE imptrap.for:826 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:827 */
/*<       real*8y >*/
/* INCLUDE imptrap.for:829 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local */
/* SOURCE imptrap.for:833 */
/*<       real*8kd >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:835 */
/*<       calllkt_kd(0,xloc,y,kd) >*/
    feq_gen_lkt_kd_d_(&feq_gen_c_d_0, &ufgc1_1.xloc, y, &kd);
/* SOURCE imptrap.for:839 */
/*<       yn_resid=1.d0-sin_theta*(kd/qd)**2 >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = kd / ufgc1_1.qd;
    ret_val = 1. - ufgc1_1.feq_gen_sin_theta_d_ * (feq_gen_d_d_1 * feq_gen_d_d_1);
/* SOURCE imptrap.for:841 */
/*<       return >*/
    return ret_val;
/* SOURCE imptrap.for:842 */
/*<       end >*/
} /* yn_resid__ */




/* SOURCE imptrap.for:846 */
/*<        >*/
/* Subroutine */ int feq_gen_find_ycynym_d_(integer *stdout, doublereal *x, doublereal 
	*epsarg, doublereal *epsf, doublereal *epsabs, doublereal *ycrit, 
	doublereal *ynorm, doublereal *ymax, integer *rflag)
{
    integer feq_gen_flag_d_;
    extern /* Subroutine */ int dfndcd_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *), dfndnd_(
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, integer *);

/*     Find the values of critical depth, normal depth (if it exists), */
/*     and the maximum argument.  Assumes the channel interval */
/*     has been set in barrel.cmn. */
/* SOURCE imptrap.for:855 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:857 */
/*<       integerstdout,rflag >*/
/* SOURCE imptrap.for:858 */
/*<       real*8x,ycrit,ynorm,ymax,epsarg,epsf,epsabs >*/
/* INCLUDE imptrap.for:861 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local */
/* SOURCE imptrap.for:865 */
/*<       integerflag >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:868 */
/*<       rflag=1 >*/
    *rflag = 1;
/*      WRITE(STDOUT,*) ' FIND_YCYNYM: YMAX_L=',YMAX_L */
/*      WRITE(STDOUT,*) ' YMAX_R=',YMAX_R */
/* SOURCE imptrap.for:874 */
/*<       ymax=min(ymax_l,ymax_r) >*/
    *ymax = min(ufgc1_1.feq_gen_ymax_l_d_,ufgc1_1.feq_gen_ymax_r_d_);
/*     Set the location for the residual functions */
/* SOURCE imptrap.for:877 */
/*<       xloc=x >*/
    ufgc1_1.xloc = *x;
/*     Compute critical depth.   YCRIT is an estimate. */
/* SOURCE imptrap.for:881 */
/*<       calldfndcd(stdout,epsarg,epsf,epsabs,ymax,ycrit,flag) >*/
    dfndcd_(stdout, epsarg, epsf, epsabs, ymax, ycrit, &feq_gen_flag_d_);
/* SOURCE imptrap.for:885 */
/*<       if(flag.ne.0)then >*/
    if (feq_gen_flag_d_ != 0) {
/* SOURCE imptrap.for:886 */
/*<       rflag=-6 >*/
	*rflag = -6;
/*        RETURN */
/* SOURCE imptrap.for:888 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' SIN_THETA=',SIN_THETA */
/*     Compute normal depth. */
/* SOURCE imptrap.for:892 */
/*<       if(sin_theta.gt.0.d0)then >*/
    if (ufgc1_1.feq_gen_sin_theta_d_ > 0.) {
/* SOURCE imptrap.for:893 */
/*<       calldfndnd(stdout,epsarg,epsf,epsabs,ymax,ynorm,flag) >*/
	dfndnd_(stdout, epsarg, epsf, epsabs, ymax, ynorm, &feq_gen_flag_d_);
/* SOURCE imptrap.for:897 */
/*<       if(flag.ne.0)then >*/
	if (feq_gen_flag_d_ != 0) {
/* SOURCE imptrap.for:898 */
/*<       rflag=-7 >*/
	    *rflag = -7;
/* SOURCE imptrap.for:899 */
/*<       return >*/
	    return 0;
/* SOURCE imptrap.for:900 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:901 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:902 */
/*<       ynorm=-1.d0 >*/
	*ynorm = -1.;
/* SOURCE imptrap.for:903 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:905 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:906 */
/*<       end >*/
} /* find_ycynym__ */




/* SOURCE imptrap.for:910 */
/*<       subroutinesetup_for_secant(y,yup,ydn,ya,yb) >*/
/* Subroutine */ int feq_gen_setup_for_secant_d_(doublereal *y, doublereal *yup, 
	doublereal *ydn, doublereal *ya, doublereal *yb)
{
    doublereal ytry, dylim, dytry;

/*     Set an increment for starting the secant method so that the two */
/*     points are close and both within the solution limits.  The solution */
/*     limits can be close together and we do not want to fall outside */
/*     those limits. */
/* SOURCE imptrap.for:919 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:921 */
/*<       real*8y,yup,ydn,ya,yb >*/
/*     Local variables */
/* SOURCE imptrap.for:925 */
/*<       real*8dytry,dylim,ytry >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:927 */
/*<       dytry=0.005d0*y >*/
    dytry = *y * .005;
/* SOURCE imptrap.for:928 */
/*<       dylim=0.5d0*(yup-ydn) >*/
    dylim = (*yup - *ydn) * .5;
/* SOURCE imptrap.for:929 */
/*<       if(dytry.gt.dylim)dytry=dylim >*/
    if (dytry > dylim) {
	dytry = dylim;
    }
/* SOURCE imptrap.for:930 */
/*<       ytry=y+dytry >*/
    ytry = *y + dytry;
/* SOURCE imptrap.for:931 */
/*<       if(ytry.gt.yup)ytry=y-dytry >*/
    if (ytry > *yup) {
	ytry = *y - dytry;
    }
/* SOURCE imptrap.for:932 */
/*<       ya=y >*/
    *ya = *y;
/* SOURCE imptrap.for:933 */
/*<       yb=ytry >*/
    *yb = ytry;
/* SOURCE imptrap.for:934 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:935 */
/*<       end >*/
} /* setup_for_secant__ */




/* SOURCE imptrap.for:939 */
/*<        >*/
/* Subroutine */ int feq_gen_set_limits_and_estimate_d_(integer *state, integer *sub, 
	integer *sup, doublereal *ycrit, doublereal *ynorm, doublereal *ymax, 
	doublereal *y, doublereal *yup, doublereal *ydn, integer *feq_gen_ycrit_yes_d_)
{
/*     Set the upper and lower limits for a profile based on the */
/*     state of the solution and the location of the current */
/*     result.  Also checks the current estimate, Y, for the root, */
/*     and adjusts to be valid. */
/* SOURCE imptrap.for:950 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:951 */
/*<       integerstate,sub,sup,ycrit_yes >*/
/* SOURCE imptrap.for:952 */
/*<       real*8y,ycrit,ynorm,ymax,yup,ydn >*/
/* *********************************************************************** */
/*     YCRIT_YES is a flag that signals that the computations can */
/*     encounter critical flow as they progress. */
/*     Clear the flag that signals that the computations can approach */
/*     critical depth. */
/* SOURCE imptrap.for:960 */
/*<       ycrit_yes=0 >*/
    *feq_gen_ycrit_yes_d_ = 0;
/* SOURCE imptrap.for:961 */
/*<       if(ynorm.lt.0.d0)then >*/
    if (*ynorm < 0.) {
/*       Normal depth does not exist. */
/* SOURCE imptrap.for:963 */
/*<       if(state.eq.sub)then >*/
	if (*state == *sub) {
/* SOURCE imptrap.for:964 */
/*<       yup=ymax >*/
	    *yup = *ymax;
/* SOURCE imptrap.for:965 */
/*<       ydn=ycrit >*/
	    *ydn = *ycrit;
/* SOURCE imptrap.for:966 */
/*<       if(y.lt.ycrit)then >*/
	    if (*y < *ycrit) {
/*           Move to the closest boundary. */
/* SOURCE imptrap.for:968 */
/*<       y=ycrit >*/
		*y = *ycrit;
/* SOURCE imptrap.for:969 */
/*<       elseif(y.gt.ymax)then >*/
	    } else if (*y > *ymax) {
/* SOURCE imptrap.for:970 */
/*<       y=ymax >*/
		*y = *ymax;
/* SOURCE imptrap.for:971 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:972 */
/*<       else >*/
	} else {
/* SOURCE imptrap.for:973 */
/*<       yup=ycrit >*/
	    *yup = *ycrit;
/* SOURCE imptrap.for:974 */
/*<       ydn=0.d0 >*/
	    *ydn = 0.;
/* SOURCE imptrap.for:975 */
/*<       ycrit_yes=1 >*/
	    *feq_gen_ycrit_yes_d_ = 1;
/* SOURCE imptrap.for:976 */
/*<       if(y.gt.ycrit)then >*/
	    if (*y > *ycrit) {
/* SOURCE imptrap.for:977 */
/*<       y=ycrit >*/
		*y = *ycrit;
/* SOURCE imptrap.for:978 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:979 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:980 */
/*<       else >*/
    } else {
/*       Normal depth exists. Three cases: local slope is mild, steep, or */
/*       critical. */
/* SOURCE imptrap.for:983 */
/*<       if(ycrit.lt.ynorm)then >*/
	if (*ycrit < *ynorm) {
/*         Local channel slope is mild. */
/* SOURCE imptrap.for:985 */
/*<       if(state.eq.sub)then >*/
	    if (*state == *sub) {
/* SOURCE imptrap.for:986 */
/*<       if(y.ge.ynorm)then >*/
		if (*y >= *ynorm) {
/* SOURCE imptrap.for:987 */
/*<       yup=ymax >*/
		    *yup = *ymax;
/* SOURCE imptrap.for:988 */
/*<       ydn=ynorm >*/
		    *ydn = *ynorm;
/* SOURCE imptrap.for:989 */
/*<       elseif(y.ge.ycrit)then >*/
		} else if (*y >= *ycrit) {
/* SOURCE imptrap.for:990 */
/*<       yup=ynorm >*/
		    *yup = *ynorm;
/* SOURCE imptrap.for:991 */
/*<       ydn=ycrit >*/
		    *ydn = *ycrit;
/* SOURCE imptrap.for:992 */
/*<       else >*/
		} else {
/*             Invalid solution: Expected subcritical result on a mild */
/*             slope but found a super critical estimate.  Move estimate */
/*             to closest boundary. */
/* SOURCE imptrap.for:996 */
/*<       y=ycrit >*/
		    *y = *ycrit;
/* SOURCE imptrap.for:997 */
/*<       endif >*/
		}
/* SOURCE imptrap.for:998 */
/*<       else >*/
	    } else {
/*           Solution is super critical here. */
/* SOURCE imptrap.for:1000 */
/*<       if(y.le.ycrit)then >*/
		if (*y <= *ycrit) {
/* SOURCE imptrap.for:1001 */
/*<       yup=ycrit >*/
		    *yup = *ycrit;
/* SOURCE imptrap.for:1002 */
/*<       ydn=0.d0 >*/
		    *ydn = 0.;
/* SOURCE imptrap.for:1003 */
/*<       ycrit_yes=1 >*/
		    *feq_gen_ycrit_yes_d_ = 1;
/* SOURCE imptrap.for:1004 */
/*<       else >*/
		} else {
/*             Invalid solution: Expected super critical result on a */
/*             mild slope but found a subcritcal estimate. Move */
/*             estimate to closest boundary. */
/* SOURCE imptrap.for:1008 */
/*<       y=ycrit >*/
		    *y = *ycrit;
/* SOURCE imptrap.for:1009 */
/*<       endif >*/
		}
/* SOURCE imptrap.for:1010 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1011 */
/*<       elseif(ycrit.gt.ynorm)then >*/
	} else if (*ycrit > *ynorm) {
/*         Local channel slope is steep. */
/* SOURCE imptrap.for:1013 */
/*<       if(state.eq.sub)then >*/
	    if (*state == *sub) {
/* SOURCE imptrap.for:1014 */
/*<       if(y.ge.ycrit)then >*/
		if (*y >= *ycrit) {
/* SOURCE imptrap.for:1015 */
/*<       yup=ymax >*/
		    *yup = *ymax;
/* SOURCE imptrap.for:1016 */
/*<       ydn=ycrit >*/
		    *ydn = *ycrit;
/* SOURCE imptrap.for:1017 */
/*<       ycrit_yes=1 >*/
		    *feq_gen_ycrit_yes_d_ = 1;
/* SOURCE imptrap.for:1018 */
/*<       else >*/
		} else {
/*             Invalid solution: Expected subcritical result on a steep */
/*             slope but found a super critical estimate.  Move to */
/*             closest boundary. */
/* SOURCE imptrap.for:1022 */
/*<       y=ycrit >*/
		    *y = *ycrit;
/* SOURCE imptrap.for:1023 */
/*<       endif >*/
		}
/* SOURCE imptrap.for:1024 */
/*<       else >*/
	    } else {
/*           Solution is super critical here. */
/* SOURCE imptrap.for:1026 */
/*<       if(y.gt.ycrit)then >*/
		if (*y > *ycrit) {
/*             Invalid solution: Expected a super critical result on a */
/*             steep slope but found a subcritical estimate.  Move to */
/*             closet boundary. */
/* SOURCE imptrap.for:1030 */
/*<       y=ycrit >*/
		    *y = *ycrit;
/* SOURCE imptrap.for:1031 */
/*<       elseif(y.ge.ynorm)then >*/
		} else if (*y >= *ynorm) {
/* SOURCE imptrap.for:1032 */
/*<       yup=ycrit >*/
		    *yup = *ycrit;
/* SOURCE imptrap.for:1033 */
/*<       ydn=ynorm >*/
		    *ydn = *ynorm;
/* SOURCE imptrap.for:1034 */
/*<       else >*/
		} else {
/* SOURCE imptrap.for:1035 */
/*<       yup=ynorm >*/
		    *yup = *ynorm;
/* SOURCE imptrap.for:1036 */
/*<       ydn=0.d0 >*/
		    *ydn = 0.;
/* SOURCE imptrap.for:1037 */
/*<       endif >*/
		}
/* SOURCE imptrap.for:1038 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1039 */
/*<       else >*/
	} else {
/*         Local channel slope is critical. */
/* SOURCE imptrap.for:1041 */
/*<       if(state.eq.sub)then >*/
	    if (*state == *sub) {
/* SOURCE imptrap.for:1042 */
/*<       if(y.ge.ycrit)then >*/
		if (*y >= *ycrit) {
/* SOURCE imptrap.for:1043 */
/*<       yup=ymax >*/
		    *yup = *ymax;
/* SOURCE imptrap.for:1044 */
/*<       ydn=ycrit >*/
		    *ydn = *ycrit;
/* SOURCE imptrap.for:1045 */
/*<       else >*/
		} else {
/*             Invalid solution: Expected a subcritical result on a */
/*             critical slope but found a super critical estimate. */
/*             Move to closest boundary. */
/* SOURCE imptrap.for:1049 */
/*<       y=ycrit >*/
		    *y = *ycrit;
/* SOURCE imptrap.for:1050 */
/*<       endif >*/
		}
/* SOURCE imptrap.for:1051 */
/*<       else >*/
	    } else {
/*           Solution super critical here. */
/* SOURCE imptrap.for:1053 */
/*<       if(y.gt.ycrit)then >*/
		if (*y > *ycrit) {
/*             Invalid solution: Expected a super critical result on a */
/*             critical slope but found a subcritical result. Move to */
/*             closest boundary. */
/* SOURCE imptrap.for:1057 */
/*<       y=ycrit >*/
		    *y = *ycrit;
/* SOURCE imptrap.for:1058 */
/*<       else >*/
		} else {
/* SOURCE imptrap.for:1059 */
/*<       yup=ycrit >*/
		    *yup = *ycrit;
/* SOURCE imptrap.for:1060 */
/*<       ydn=0.d0 >*/
		    *ydn = 0.;
/* SOURCE imptrap.for:1061 */
/*<       endif >*/
		}
/* SOURCE imptrap.for:1062 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1063 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1064 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1065 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:1066 */
/*<       end >*/
} /* set_limits_and_estimate__ */




/* SOURCE imptrap.for:1071 */
/*<        >*/
/* Subroutine */ int feq_gen_get_root_d_(doublereal *feq_gen_h_d_, doublereal *f1, doublereal *
	p1, doublereal *x2, doublereal *y2, FeqCallback2 f, FeqCallback2 p, doublereal *epsf, 
	doublereal *epsarg, doublereal *epsabs, doublereal *ymax, doublereal *
	ymin, doublereal *root, integer *rflag)
{
    /* Initialized data */

    static integer maxit = 30;

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal df, fl, fr, dy, yl, yr, oldval, dytemp;

/*     Find a root for subroutine IMPTRAP.  Use secant method as */
/*     implemented in subroutine SECANT. */
/* SOURCE imptrap.for:1080 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:1082 */
/*<       integerrflag >*/
/* SOURCE imptrap.for:1083 */
/*<       real*8h,f1,p1,x2,y2,epsf,epsarg,epsabs,ymax,ymin,root >*/
/* SOURCE imptrap.for:1086 */
/*<       real*8f,p >*/
/* SOURCE imptrap.for:1087 */
/*<       externalf,p >*/
/*     Local variables */
/* SOURCE imptrap.for:1092 */
/*<       integeri,maxit >*/
/* SOURCE imptrap.for:1093 */
/*<       real*8yl,yr,dy,oldval,fl,fr,df,dytemp >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:1095 */
/*<       datamaxit/30/ >*/
/* SOURCE imptrap.for:1098 */
/*<       rflag=1 >*/
    *rflag = 1;
/*     Set the initial starting points */
/* SOURCE imptrap.for:1100 */
/*<       yl=y2 >*/
    yl = *y2;
/* SOURCE imptrap.for:1101 */
/*<       yr=root >*/
    yr = *root;
/* SOURCE imptrap.for:1102 */
/*<       oldval=1.d0 >*/
    oldval = 1.;
/*      WRITE(STD6,*) ' ENTERING GET_ROOT. YL=',YL,' YR=',YR */
/* SOURCE imptrap.for:1105 */
/*<       fl=(p(x2,yl)-p1-0.5d0*h*(f1+f(x2,yl)))/p(x2,yl) >*/
    fl = ((*p)(x2, &yl) - *p1 - *feq_gen_h_d_ * .5 * (*f1 + (*f)(x2, &yl))) / (*p)(x2, 
	    &yl);
/* SOURCE imptrap.for:1106 */
/*<       if(abs(fl).le.epsf)then >*/
    if (abs(fl) <= *epsf) {
/* SOURCE imptrap.for:1107 */
/*<       root=yl >*/
	*root = yl;
/* SOURCE imptrap.for:1108 */
/*<       return >*/
	return 0;
/* SOURCE imptrap.for:1109 */
/*<       endif >*/
    }
/*      WRITE(STD6,*) ' FL=',FL */
/* SOURCE imptrap.for:1111 */
/*<       dy=yr-yl >*/
    dy = yr - yl;
/* SOURCE imptrap.for:1112 */
/*<       do100i=1,maxit >*/
    feq_gen_i_d_1 = maxit;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE imptrap.for:1113 */
/*<       fr=(p(x2,yr)-p1-0.5d0*h*(f1+f(x2,yr)))/p(x2,yr) >*/
	fr = ((*p)(x2, &yr) - *p1 - *feq_gen_h_d_ * .5 * (*f1 + (*f)(x2, &yr))) / (*p)(
		x2, &yr);
/*       WRITE(STD6,*) ' I=',I,' FR=',FR */
/* SOURCE imptrap.for:1115 */
/*<       if(abs(fr).le.epsf)then >*/
	if (abs(fr) <= *epsf) {
/*          WRITE(6,*) ' Convergence on FR with EPSF' */
/* SOURCE imptrap.for:1117 */
/*<       root=yr >*/
	    *root = yr;
/* SOURCE imptrap.for:1118 */
/*<       return >*/
	    return 0;
/* SOURCE imptrap.for:1119 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1120 */
/*<       df=fl-fr >*/
	df = fl - fr;
/*        WRITE(STD6,50) I, FL, FR, DY */
/* 50    FORMAT(' I=1',I5,' FL=',F10.5,' FR=',F10.5,' DY=',F15.8) */
/* SOURCE imptrap.for:1123 */
/*<       if(df.ne.0.0)then >*/
	if (df != (float)0.) {
/* SOURCE imptrap.for:1124 */
/*<       dytemp=0.0d0 >*/
	    dytemp = 0.;
/* SOURCE imptrap.for:1125 */
/*<       oldval=dy/df >*/
	    oldval = dy / df;
/* SOURCE imptrap.for:1126 */
/*<       dy=fr*oldval >*/
	    dy = fr * oldval;
/* SOURCE imptrap.for:1127 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE imptrap.for:1128 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE imptrap.for:1129 */
/*<       yr=yr+dy >*/
	    yr += dy;
/* SOURCE imptrap.for:1130 */
/*<       if(yr.gt.ymax)then >*/
	    if (yr > *ymax) {
/* SOURCE imptrap.for:1131 */
/*<       yr=0.5*(yl+ymax) >*/
		yr = (yl + *ymax) * (float).5;
/* SOURCE imptrap.for:1132 */
/*<       dytemp=yr-yl >*/
		dytemp = yr - yl;
/* SOURCE imptrap.for:1133 */
/*<       elseif(yr.lt.ymin)then >*/
	    } else if (yr < *ymin) {
/* SOURCE imptrap.for:1134 */
/*<       yr=0.5*(yl+ymin) >*/
		yr = (yl + *ymin) * (float).5;
/* SOURCE imptrap.for:1135 */
/*<       dytemp=yr-yl >*/
		dytemp = yr - yl;
/* SOURCE imptrap.for:1136 */
/*<       endif >*/
	    }
/*          WRITE(STD6,*) ' DY=',DY */
/* SOURCE imptrap.for:1138 */
/*<       if(abs(dy/yr).le.epsarg.or.abs(dy).le.epsabs)then >*/
	    if ((feq_gen_d_d_1 = dy / yr, abs(feq_gen_d_d_1)) <= *epsarg || abs(dy) <= *epsabs) 
		    {
/*            WRITE(6,*) ' Convergence on EPSARG or EPSABS' */
/* SOURCE imptrap.for:1140 */
/*<       root=yr >*/
		*root = yr;
/* SOURCE imptrap.for:1141 */
/*<       return >*/
		return 0;
/* SOURCE imptrap.for:1142 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1143 */
/*<       if(dytemp.ne.0.0)then >*/
	    if (dytemp != (float)0.) {
/* SOURCE imptrap.for:1144 */
/*<       dy=dytemp >*/
		dy = dytemp;
/* SOURCE imptrap.for:1145 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1146 */
/*<       else >*/
	} else {
/*         DF = 0. SIGNAL POSSIBLE ERROR */
/* SOURCE imptrap.for:1148 */
/*<       root=yr >*/
	    *root = yr;
/* SOURCE imptrap.for:1149 */
/*<       if(abs(fr).le.epsf)then >*/
	    if (abs(fr) <= *epsf) {
/*            WRITE(6,*) ' Convergence on EPSF when DF=0.0' */
/* SOURCE imptrap.for:1151 */
/*<       return >*/
		return 0;
/* SOURCE imptrap.for:1152 */
/*<       else >*/
	    } else {
/* SOURCE imptrap.for:1153 */
/*<       rflag=0 >*/
		*rflag = 0;
/* SOURCE imptrap.for:1154 */
/*<       return >*/
		return 0;
/* SOURCE imptrap.for:1155 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1156 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1158 */
/*<   100 continue >*/
/* L100: */
    }
/*     DROP THROUGH INDICATES NO CONVERGENCE WITHIN MAXIT ITERATIONS */
/* SOURCE imptrap.for:1161 */
/*<       rflag=0 >*/
    *rflag = 0;
/* SOURCE imptrap.for:1162 */
/*<       root=yr >*/
    *root = yr;
/* SOURCE imptrap.for:1163 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:1164 */
/*<       end >*/
} /* get_root__ */




/* SOURCE imptrap.for:1168 */
/*<        >*/
/* Subroutine */ int feq_gen_invert_p_d_(doublereal *pvalue, doublereal *x, doublereal 
	*y, FeqCallback2 p, doublereal *ymax, doublereal *ymin, doublereal *epsf, 
	doublereal *epsabs, doublereal *epsarg, doublereal *root, integer *
	rflag)
{
    /* Initialized data */

    static integer maxit = 30;

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal df, fl, fr, dy, yl, yr, oldval, dytemp;

/*     Invert P for IMPTRAP.  Use secant method based on SECANT. */
/* SOURCE imptrap.for:1177 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:1178 */
/*<       integerrflag >*/
/* SOURCE imptrap.for:1179 */
/*<       real*8pvalue,x,y,epsf,epsarg,epsabs,root,ymax,ymin >*/
/* SOURCE imptrap.for:1182 */
/*<       real*8p >*/
/* SOURCE imptrap.for:1183 */
/*<       externalp >*/
/*     Local variables */
/* SOURCE imptrap.for:1188 */
/*<       integeri,maxit >*/
/* SOURCE imptrap.for:1189 */
/*<       real*8yl,yr,dy,oldval,fl,fr,df,dytemp >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:1191 */
/*<       datamaxit/30/ >*/
/* SOURCE imptrap.for:1194 */
/*<       rflag=1 >*/
    *rflag = 1;
/*     Set the initial starting points */
/* SOURCE imptrap.for:1196 */
/*<       yl=y >*/
    yl = *y;
/* SOURCE imptrap.for:1197 */
/*<       yr=root >*/
    yr = *root;
/* SOURCE imptrap.for:1198 */
/*<       oldval=1.d0 >*/
    oldval = 1.;
/*      WRITE(STD6,*) ' ENTERING INVERT_P. YL=',YL,' YR=',YR */
/* SOURCE imptrap.for:1201 */
/*<       fl=(pvalue-p(x,yl))/pvalue >*/
    fl = (*pvalue - (*p)(x, &yl)) / *pvalue;
/*      WRITE(STD6,*) ' FL=',FL */
/* SOURCE imptrap.for:1204 */
/*<       dy=yr-yl >*/
    dy = yr - yl;
/* SOURCE imptrap.for:1205 */
/*<       do100i=1,maxit >*/
    feq_gen_i_d_1 = maxit;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE imptrap.for:1206 */
/*<       fr=(pvalue-p(x,yr))/pvalue >*/
	fr = (*pvalue - (*p)(x, &yr)) / *pvalue;
/*       WRITE(STD6,*) ' I=',I,' FR=',FR */
/* SOURCE imptrap.for:1208 */
/*<       if(abs(fr).le.epsf)then >*/
	if (abs(fr) <= *epsf) {
/* SOURCE imptrap.for:1209 */
/*<       root=yr >*/
	    *root = yr;
/* SOURCE imptrap.for:1210 */
/*<       return >*/
	    return 0;
/* SOURCE imptrap.for:1211 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1212 */
/*<       df=fl-fr >*/
	df = fl - fr;
/*        WRITE(STD6,*) ' INVERT_P:I=',I,' FL=',FL,' FR=',FR,' DY=',DY */
/* SOURCE imptrap.for:1214 */
/*<       if(df.ne.0.0)then >*/
	if (df != (float)0.) {
/* SOURCE imptrap.for:1215 */
/*<       dytemp=0.0d0 >*/
	    dytemp = 0.;
/* SOURCE imptrap.for:1216 */
/*<       oldval=dy/df >*/
	    oldval = dy / df;
/* SOURCE imptrap.for:1217 */
/*<       dy=fr*oldval >*/
	    dy = fr * oldval;
/* SOURCE imptrap.for:1218 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE imptrap.for:1219 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE imptrap.for:1220 */
/*<       yr=yr+dy >*/
	    yr += dy;
/* SOURCE imptrap.for:1221 */
/*<       if(yr.gt.ymax)then >*/
	    if (yr > *ymax) {
/* SOURCE imptrap.for:1222 */
/*<       yr=0.5*(yl+ymax) >*/
		yr = (yl + *ymax) * (float).5;
/* SOURCE imptrap.for:1223 */
/*<       dytemp=yr-yl >*/
		dytemp = yr - yl;
/* SOURCE imptrap.for:1224 */
/*<       elseif(yr.lt.ymin)then >*/
	    } else if (yr < *ymin) {
/* SOURCE imptrap.for:1225 */
/*<       yr=0.5*(yl+ymin) >*/
		yr = (yl + *ymin) * (float).5;
/* SOURCE imptrap.for:1226 */
/*<       dytemp=yr-yl >*/
		dytemp = yr - yl;
/* SOURCE imptrap.for:1227 */
/*<       endif >*/
	    }
/*          WRITE(STD6,*) ' DY=',DY */
/* SOURCE imptrap.for:1229 */
/*<       if(abs(dy/yr).le.epsarg.or.abs(dy).le.epsabs)then >*/
	    if ((feq_gen_d_d_1 = dy / yr, abs(feq_gen_d_d_1)) <= *epsarg || abs(dy) <= *epsabs) 
		    {
/* SOURCE imptrap.for:1230 */
/*<       root=yr >*/
		*root = yr;
/* SOURCE imptrap.for:1231 */
/*<       return >*/
		return 0;
/* SOURCE imptrap.for:1232 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1233 */
/*<       if(dytemp.ne.0.0)then >*/
	    if (dytemp != (float)0.) {
/* SOURCE imptrap.for:1234 */
/*<       dy=dytemp >*/
		dy = dytemp;
/* SOURCE imptrap.for:1235 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1236 */
/*<       else >*/
	} else {
/*         DF = 0. SIGNAL POSSIBLE ERROR */
/* SOURCE imptrap.for:1238 */
/*<       root=yr >*/
	    *root = yr;
/* SOURCE imptrap.for:1239 */
/*<       if(abs(fr).le.epsf)then >*/
	    if (abs(fr) <= *epsf) {
/* SOURCE imptrap.for:1240 */
/*<       return >*/
		return 0;
/* SOURCE imptrap.for:1241 */
/*<       else >*/
	    } else {
/* SOURCE imptrap.for:1242 */
/*<       rflag=0 >*/
		*rflag = 0;
/* SOURCE imptrap.for:1243 */
/*<       return >*/
		return 0;
/* SOURCE imptrap.for:1244 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1245 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1247 */
/*<   100 continue >*/
/* L100: */
    }
/*     DROP THROUGH INDICATES NO CONVERGENCE WITHIN MAXIT ITERATIONS */
/* SOURCE imptrap.for:1250 */
/*<       rflag=0 >*/
    *rflag = 0;
/* SOURCE imptrap.for:1251 */
/*<       root=yr >*/
    *root = yr;
/* SOURCE imptrap.for:1252 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:1253 */
/*<       end >*/
} /* invert_p__ */




/* SOURCE imptrap.for:1257 */
/*<       subroutineerrors_in_imptrap(stdout,rflag,n,x,nmax,h,h2) >*/
/* Subroutine */ int feq_gen_errors_in_imptrap_d_(integer *stdout, integer *rflag, 
	integer *n, doublereal *x, integer *nmax, doublereal *feq_gen_h_d_, doublereal 
	*h2)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:745*: Computational problem(s) in I\
MPTRAP on\002,/,11x,\002 step after station=\002,f12.4,\002 and after index\
=\002,i10,\002.\002,/,11x,\002 The problem was identified as:\002)";
    static char fmt_51[] = "(\002 Maximum number of steps=\002,i5,\002 excee\
ded.\002)";
    static char fmt_52[] = "(\002 Minimum step length reached seeking soluti\
on at full\002,\002 step=\002,1pd10.3)";
    static char fmt_53[] = "(\002 Minimum step length reached seeking soluti\
on at first\002,\002 half-step=\002,1pd10.3)";
    static char fmt_54[] = "(\002 Minimum step length reached seeking soluti\
on at second\002,\002 half-step=\002,1pd10.3)";
    static char fmt_55[] = "(\002 Minimum step length reached seeking soluti\
on after\002,\002 extrapolation.\002)";
    static char fmt_56[] = "(\002 Critical depth not found.\002)";
    static char fmt_57[] = "(\002 Normal depth not found when it should exis\
t.\002)";
    static char fmt_58[] = "(\002 Starting depth exactly matches critical de\
pth. Desired \002,\002profile unknown.\002)";
    static char fmt_59[] = "(\002 Minimum step length reached seeking to mee\
t error\002,\002 tolerance.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__139 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__140 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__141 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__142 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__143 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__145 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_59, 0 };


/*     Report errors in subroutine IMPTRAP */
/* SOURCE imptrap.for:1262 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:1264 */
/*<       integerstdout,rflag,n,nmax >*/
/* SOURCE imptrap.for:1266 */
/*<       real*8x,h,h2 >*/
/*     ****************************FORMATS******************************* */
/* SOURCE imptrap.for:1270 */
/*<    50  >*/
/* SOURCE imptrap.for:1273 */
/*<    51 format(' Maximum number of steps=',i5,' exceeded.') >*/
/* SOURCE imptrap.for:1274 */
/*<    52  >*/
/* SOURCE imptrap.for:1276 */
/*<    53  >*/
/* SOURCE imptrap.for:1278 */
/*<    54  >*/
/* SOURCE imptrap.for:1280 */
/*<    55  >*/
/* SOURCE imptrap.for:1282 */
/*<    56 format(' Critical depth not found.') >*/
/* SOURCE imptrap.for:1283 */
/*<    57 format(' Normal depth not found when it should exist.') >*/
/* SOURCE imptrap.for:1284 */
/*<    58  >*/
/* SOURCE imptrap.for:1286 */
/*<    59  >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:1290 */
/*<       write(stdout,50)x,n >*/
/* L50: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
/* L56: */
/* L57: */
/* L58: */
/* L59: */
    feq_gen_io_d__138.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__138);
    do_fio(&feq_gen_c_d_1, (char *)&(*x), (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&(*n), (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE imptrap.for:1291 */
/*<       if(rflag.eq.-1)then >*/
    if (*rflag == -1) {
/* SOURCE imptrap.for:1292 */
/*<       write(stdout,51)nmax >*/
	feq_gen_io_d__139.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__139);
	do_fio(&feq_gen_c_d_1, (char *)&(*nmax), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE imptrap.for:1293 */
/*<       elseif(rflag.eq.-2)then >*/
    } else if (*rflag == -2) {
/* SOURCE imptrap.for:1294 */
/*<       write(stdout,52)h >*/
	feq_gen_io_d__140.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__140);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_h_d_), (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE imptrap.for:1295 */
/*<       elseif(rflag.eq.-3)then >*/
    } else if (*rflag == -3) {
/* SOURCE imptrap.for:1296 */
/*<       write(stdout,53)h2 >*/
	feq_gen_io_d__141.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__141);
	do_fio(&feq_gen_c_d_1, (char *)&(*h2), (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE imptrap.for:1297 */
/*<       elseif(rflag.eq.-4)then >*/
    } else if (*rflag == -4) {
/* SOURCE imptrap.for:1298 */
/*<       write(stdout,54)h2 >*/
	feq_gen_io_d__142.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__142);
	do_fio(&feq_gen_c_d_1, (char *)&(*h2), (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE imptrap.for:1299 */
/*<       elseif(rflag.eq.-5)then >*/
    } else if (*rflag == -5) {
/* SOURCE imptrap.for:1300 */
/*<       write(stdout,55) >*/
	feq_gen_io_d__143.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__143);
	e_wsfe();
/* SOURCE imptrap.for:1301 */
/*<       elseif(rflag.eq.-6)then >*/
    } else if (*rflag == -6) {
/* SOURCE imptrap.for:1302 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__144.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__144);
	e_wsfe();
/* SOURCE imptrap.for:1303 */
/*<       elseif(rflag.eq.-7)then >*/
    } else if (*rflag == -7) {
/* SOURCE imptrap.for:1304 */
/*<       write(stdout,57) >*/
	feq_gen_io_d__145.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__145);
	e_wsfe();
/* SOURCE imptrap.for:1305 */
/*<       elseif(rflag.eq.-8)then >*/
    } else if (*rflag == -8) {
/* SOURCE imptrap.for:1306 */
/*<       write(stdout,58) >*/
	feq_gen_io_d__146.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__146);
	e_wsfe();
/* SOURCE imptrap.for:1307 */
/*<       elseif(rflag.eq.-9)then >*/
    } else if (*rflag == -9) {
/* SOURCE imptrap.for:1308 */
/*<       write(stdout,59) >*/
	feq_gen_io_d__147.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__147);
	e_wsfe();
/* SOURCE imptrap.for:1309 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1310 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:1311 */
/*<       end >*/
} /* errors_in_imptrap__ */




/* SOURCE imptrap.for:1315 */
/*<        >*/
/* Subroutine */ int imptrap_(integer *stdout, integer *prismatic, doublereal 
	*xs, doublereal *xe, doublereal *ys, doublereal *eps, doublereal *
	epsarg, doublereal *epsf, doublereal *epsabs, doublereal *hmina, 
	doublereal *hmaxa, doublereal *ycrita, doublereal *ynorma, doublereal 
	*ymaxa, FeqCallback2 p, FeqCallback2 f, FeqCallback4 feq_gen_find_ycynym_d_, integer *extrap, 
	doublereal *ysfac, doublereal *dhlim, integer *nmax, integer *n, 
	doublereal *feq_storage_xvec, doublereal *feq_storage_yvec, doublereal *feq_storage_ycvec, doublereal *
	feq_storage_ynvec, integer *rflag)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_set_limits_and_estimate_d_(integer *, integer *
	    , integer *, doublereal *, doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, integer *);
    doublereal feq_gen_ymax_mid_d_;
    extern /* Subroutine */ int feq_gen_get_root_d_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, FeqCallback2, FeqCallback2, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), feq_gen_invert_p_d_(doublereal *, doublereal *, 
	    doublereal *, FeqCallback2, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    doublereal feq_gen_h_d_;
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_setup_for_secant_d_(doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *);
    doublereal f1, h2, p1, p2, feq_gen_ycrit_mid_d_, x1, x2, y1, y2, feq_gen_ynorm_mid_d_;
    integer feq_gen_ycrit_yes_d_;
    doublereal yt;
    extern /* Subroutine */ int feq_gen_errors_in_imptrap_d_(integer *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, doublereal *);
    integer inc;
    doublereal ydn2, yup2, hfac, fmid, pmid, hmin, hmax, xmid, ymid, root, 
	    p2end, y2end, ymax2;
    integer state;
    doublereal p2best, y2best, ycrit2, ynorm2, relerr, feq_gen_ydn_mid_d_, feq_gen_yup_mid_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__182 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, 0, 0 };


/*     Solve for the steady 1-D water surface profile using the */
/*     conservation  form of the equations, */
/*                dP(x,y) */
/*                -------  = F(x,y) */
/*                dx */
/*     using the implicit trapezoidal rule, varying the step length to */
/*     keep the estimated local truncation error, in relative terms, */
/*     less than EPS.  If EXTRAP = 1, apply one Richardson extrapolation */
/*     correction to the result before starting the next step. */
/*     Assumes that the proper channel interval has been set in the */
/*     common blocks internal to the functions P, F, and FIND_YCYNYM. */
/* SOURCE imptrap.for:1338 */
/*<       implicitnone >*/
/* SOURCE imptrap.for:1340 */
/*<       integerextrap,n,nmax,prismatic,rflag,stdout >*/
/* SOURCE imptrap.for:1341 */
/*<        >*/
/* SOURCE imptrap.for:1343 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE imptrap.for:1345 */
/*<       real*8f,p >*/
/* SOURCE imptrap.for:1346 */
/*<       externalf,p,find_ycynym >*/
/*         Definition of dummy arguments. */
/*     STDOUT-  unit for output of messages. */
/*     PRISMATIC- if 1, then channel is primatic, if 0 non-prismatic. */
/*     XS-     starting value of x, distance along the channel. */
/*     XE-     ending value of x */
/*     YS-     starting value of y, the maximum depth in a cross section */
/*             The starting value should not exactly equal critical depth */
/*             to give a clear indication of which of two solutions is being */
/*             sought.  The rate of change of depth with distance at critical */
/*             depth is infinite.  Thus the distance between critical depth */
/*             and the depth that differs by 1 percent is negligible in any */
/*             engineering application. */
/*     EPS-    limit for the maximum local truncation error in estimates */
/*             of E relative to E. */
/*     The following three values relate to the non-linear solution required */
/*     in the implicit trapezoidal method: */
/*     EPSARG- relative tolerance on the change in an argument when finding */
/*             a root. */
/*     EPSF-   toleracne on the value of the function when finding a root. */
/*     EPSABS- absolute tolerance on the change in an argument when */
/*             finding a root. */
/*     HMINA-   minimum step size permitted. */
/*     HMAXA-   upper limit for step size. */
/*     The following three values apply at XS only if the channel is */
/*     non-prismatic, and at all points if the channel is prismatic. */
/*     YCRITA-  critical depth */
/*     YNORMA-  normal depth if it exists; otherwise, -1.0 */
/*     YMAXA-   maximum argument supported in the cross-section function */
/*              table defining the channel shape at XS. */
/*     P-      function of x and y, either the specific energy or the */
/*             impulse-momentum function. */
/*     F-      function of x and y, giving the correct right-hand side for */
/*             conservation law being used. */
/*     FIND_YCYNYM- subroutine to return values of critical depth, normal */
/*              depth, and maximum allowed depth. */
/*     EXTRAP- if 1 apply an extrapolation correction, otherwise, no */
/*             correction is applied. */
/*     YSFAC-  factor on YS giving the initial step. */
/*     DHLIM-  maximum increase ratio for a step.  DHLIM = 2 limits increases */
/*             to twice the previous value. */
/*     NMAX-   maximum number of steps permitted. */
/*     N-      on entry gives the index into the result vectors at which */
/*             to start storing values.  On exit gives the last index */
/*             filed.  We will store values  such that the X location */
/*             will always increase with increase in index. */
/*             Also the initial point is only stored on the first */
/*             entry to the IMPTRAP in a series of entries. */
/*     XVEC(*)-values of x at which a solution has been computed. */
/*     RFLAG-  result flag: 1-normal completion.  See ERRORS_IN_IMPTRAP. */
/*     External routines */
/* SOURCE imptrap.for:1407 */
/*<       externalset_limits_and_estimate,setup_for_secant,get_root >*/
/*     Local variables */
/* SOURCE imptrap.for:1410 */
/*<       integeri,state,sub,sup,ycrit_yes,inc >*/
/* SOURCE imptrap.for:1411 */
/*<       parameter(sub=0,sup=2) >*/
/* SOURCE imptrap.for:1413 */
/*<        >*/
/* *********************************************************************** */
/* SOURCE imptrap.for:1422 */
/*<       rflag=1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> ynvec(feq_storage_ynvec, 1);

    feq::IndexedPointer<doublereal> ycvec(feq_storage_ycvec, 1);

    feq::IndexedPointer<doublereal> yvec(feq_storage_yvec, 1);

    feq::IndexedPointer<doublereal> xvec(feq_storage_xvec, 1);

    /* Function Body */
    *rflag = 1;
/* SOURCE imptrap.for:1423 */
/*<       i=n >*/
    feq_gen_i_d_ = *n;
/*     Set the initial step length and set the sign of the maximum step. */
/* SOURCE imptrap.for:1426 */
/*<       if(xe.gt.xs)then >*/
    if (*xe > *xs) {
/*        H = YS*YSFAC */
/* SOURCE imptrap.for:1428 */
/*<       h=hmaxa >*/
	feq_gen_h_d_ = *hmaxa;
/* SOURCE imptrap.for:1429 */
/*<       hmax=hmaxa >*/
	hmax = *hmaxa;
/* SOURCE imptrap.for:1430 */
/*<       hmin=hmina >*/
	hmin = *hmina;
/* SOURCE imptrap.for:1431 */
/*<       inc=1 >*/
	inc = 1;
/* SOURCE imptrap.for:1432 */
/*<       else >*/
    } else {
/*        H = -YS*YSFAC */
/* SOURCE imptrap.for:1434 */
/*<       h=-hmaxa >*/
	feq_gen_h_d_ = -(*hmaxa);
/* SOURCE imptrap.for:1435 */
/*<       hmax=-hmaxa >*/
	hmax = -(*hmaxa);
/* SOURCE imptrap.for:1436 */
/*<       hmin=-hmina >*/
	hmin = -(*hmina);
/* SOURCE imptrap.for:1437 */
/*<       inc=-1 >*/
	inc = -1;
/* SOURCE imptrap.for:1438 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1440 */
/*<       if((i.eq.1.and.inc.eq.1).or.(i.eq.nmax.and.inc.eq.-1))then >*/
    if (feq_gen_i_d_ == 1 && inc == 1 || feq_gen_i_d_ == *nmax && inc == -1) {
/*       Store the starting values */
/* SOURCE imptrap.for:1443 */
/*<       xvec(i)=xs >*/
	xvec[feq_gen_i_d_] = *xs;
/* SOURCE imptrap.for:1444 */
/*<       yvec(i)=ys >*/
	yvec[feq_gen_i_d_] = *ys;
/* SOURCE imptrap.for:1445 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' Initial H=',H,' YS=',YS */
/*     Initialize the local values */
/* SOURCE imptrap.for:1450 */
/*<       x1=xs >*/
    x1 = *xs;
/* SOURCE imptrap.for:1451 */
/*<       y1=ys >*/
    y1 = *ys;
/* SOURCE imptrap.for:1452 */
/*<       ycrit2=ycrita >*/
    ycrit2 = *ycrita;
/* SOURCE imptrap.for:1453 */
/*<       ynorm2=ynorma >*/
    ynorm2 = *ynorma;
/* SOURCE imptrap.for:1454 */
/*<       ymax2=ymaxa >*/
    ymax2 = *ymaxa;
/* SOURCE imptrap.for:1455 */
/*<       ycvec(i)=ycrit2 >*/
    ycvec[feq_gen_i_d_] = ycrit2;
/* SOURCE imptrap.for:1456 */
/*<       ynvec(i)=ynorm2 >*/
    ynvec[feq_gen_i_d_] = ynorm2;
/*      WRITE(STDOUT,*) ' YCRIT2=',YCRIT2,' YNORM2=',YNORM2, */
/*     A                 ' YMAX2=',YMAX2 */
/* SOURCE imptrap.for:1460 */
/*<       ycrit_mid=ycrit2 >*/
    feq_gen_ycrit_mid_d_ = ycrit2;
/* SOURCE imptrap.for:1461 */
/*<       ynorm_mid=ynorm2 >*/
    feq_gen_ynorm_mid_d_ = ynorm2;
/* SOURCE imptrap.for:1462 */
/*<       ymax_mid=ymax2 >*/
    feq_gen_ymax_mid_d_ = ymax2;
/*     Establish the state for the solution */
/* SOURCE imptrap.for:1465 */
/*<       if(ys.lt.ycrit2)then >*/
    if (*ys < ycrit2) {
/* SOURCE imptrap.for:1466 */
/*<       state=sup >*/
	state = 2;
/* SOURCE imptrap.for:1467 */
/*<       elseif(ys.gt.ycrit2)then >*/
    } else if (*ys > ycrit2) {
/* SOURCE imptrap.for:1468 */
/*<       state=sub >*/
	state = 0;
/* SOURCE imptrap.for:1469 */
/*<       else >*/
    } else {
/*       Error-not known which profile is desired. */
/* SOURCE imptrap.for:1471 */
/*<       rflag=-8 >*/
	*rflag = -8;
/* SOURCE imptrap.for:1472 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:1473 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' STATE=',STATE */
/*     Establish the upper and lower bounds for the solution. */
/*     Applies at each point for a prismatic channel but will */
/*     be over ridden at each point for a non-prismatic channel. */
/* SOURCE imptrap.for:1481 */
/*<       y2=y1 >*/
    y2 = y1;
/* SOURCE imptrap.for:1482 */
/*<        >*/
    feq_gen_set_limits_and_estimate_d_(&state, &feq_gen_c_d_0, &feq_gen_c_d_2, &ycrit2, &ynorm2, &ymax2, 
	    &y2, &yup2, &ydn2, &feq_gen_ycrit_yes_d_);
/* SOURCE imptrap.for:1488 */
/*<       yup_mid=yup2 >*/
    feq_gen_yup_mid_d_ = yup2;
/* SOURCE imptrap.for:1489 */
/*<       ydn_mid=ydn2 >*/
    feq_gen_ydn_mid_d_ = ydn2;
/*      WRITE(STDOUT,*) ' YUP2=',YUP2,' YDN2=',YDN2 */
/*     Start loop over steps until XE is reached, critical depth */
/*     is approached, minimum step is reached, or non-linear */
/*     equation solution convergence failure occurs. */
/* SOURCE imptrap.for:1497 */
/*<   100 continue >*/
L100:
/* SOURCE imptrap.for:1498 */
/*<       f1=f(x1,y1) >*/
    f1 = (*f)(&x1, &y1);
/* SOURCE imptrap.for:1499 */
/*<       p1=p(x1,y1) >*/
    p1 = (*p)(&x1, &y1);
/*       Start loop within the step until the local error tolerance */
/*       is met or some computational failure occurs. */
/* SOURCE imptrap.for:1503 */
/*<   200 continue >*/
L200:
/* SOURCE imptrap.for:1505 */
/*<       x2=x1+h >*/
    x2 = x1 + feq_gen_h_d_;
/*         Check for the last step. */
/* SOURCE imptrap.for:1508 */
/*<       if(h.gt.0)then >*/
    if (feq_gen_h_d_ > 0.) {
/* SOURCE imptrap.for:1509 */
/*<       if(x2.ge.xe)then >*/
	if (x2 >= *xe) {
/* SOURCE imptrap.for:1510 */
/*<       x2=xe >*/
	    x2 = *xe;
/* SOURCE imptrap.for:1511 */
/*<       h=x2-x1 >*/
	    feq_gen_h_d_ = x2 - x1;
/* SOURCE imptrap.for:1512 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1513 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:1514 */
/*<       if(x2.le.xe)then >*/
	if (x2 <= *xe) {
/* SOURCE imptrap.for:1515 */
/*<       x2=xe >*/
	    x2 = *xe;
/* SOURCE imptrap.for:1516 */
/*<       h=x2-x1 >*/
	    feq_gen_h_d_ = x2 - x1;
/* SOURCE imptrap.for:1517 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1518 */
/*<       endif >*/
    }
/*         If the channel is non-prismatic, we must compute */
/*         new values of critical and normal depths. */
/* SOURCE imptrap.for:1522 */
/*<       if(prismatic.eq.0)then >*/
    if (*prismatic == 0) {
/* SOURCE imptrap.for:1523 */
/*<        >*/
	(*feq_gen_find_ycynym_d_)(stdout, &x2, epsarg, epsf, epsabs, &ycrit2, &ynorm2, 
		&ymax2, rflag);
/* SOURCE imptrap.for:1527 */
/*<       if(rflag.ne.1)then >*/
	if (*rflag != 1) {
/*             Computational failure */
/* SOURCE imptrap.for:1529 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1530 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1531 */
/*<       if(rflag.ne.1)then >*/
	if (*rflag != 1) {
/*             Computational failure when normal depth is known to */
/*             exist. */
/* SOURCE imptrap.for:1534 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1535 */
/*<       endif >*/
	}
/*           Compute the new profile limits and adjust the estimate. */
/* SOURCE imptrap.for:1537 */
/*<        >*/
	feq_gen_set_limits_and_estimate_d_(&state, &feq_gen_c_d_0, &feq_gen_c_d_2, &ycrit2, &ynorm2, &
		ymax2, &y2, &yup2, &ydn2, &feq_gen_ycrit_yes_d_);
/* SOURCE imptrap.for:1542 */
/*<       endif >*/
    }
/*         Make an estimate of the root to start the root finding */
/*         process. Y2 is a good estimate (we hope!) but we need to set a */
/*         nearby point that is valid for starting the secant */
/*         method for finding the root. Any new root must */
/*         be between YUP and YDN.  At this point we know that */
/*         Y2 is in the proper range.  The upper and lower limits */
/*         could be close therefore we must choose the increment */
/*         to stay within the solution interval. */
/* SOURCE imptrap.for:1552 */
/*<       yt=y2 >*/
    yt = y2;
/* SOURCE imptrap.for:1553 */
/*<       callsetup_for_secant(yt,yup2,ydn2,y2,root) >*/
    feq_gen_setup_for_secant_d_(&yt, &yup2, &ydn2, &y2, &root);
/*         Find the solution at X2 with a step of H. */
/* SOURCE imptrap.for:1559 */
/*<        >*/
    feq_gen_get_root_d_(&feq_gen_h_d_, &f1, &p1, &x2, &y2, f, p, epsf, epsarg, 
	    epsabs, &yup2, &ydn2, &root, rflag);
/* SOURCE imptrap.for:1564 */
/*<       y2=root >*/
    y2 = root;
/*          WRITE(STDOUT,*) ' Y2=',Y2,' RFLAG=',RFLAG */
/* SOURCE imptrap.for:1567 */
/*<       if(rflag.eq.0)then >*/
    if (*rflag == 0) {
/*           No solution found or invalid solution found. */
/*           Reduce the step and try again. */
/* SOURCE imptrap.for:1570 */
/*<       h=0.9d0*h >*/
	feq_gen_h_d_ *= .9;
/* SOURCE imptrap.for:1571 */
/*<       if(abs(h).gt.abs(hmin))then >*/
	if (abs(feq_gen_h_d_) > abs(hmin)) {
/* SOURCE imptrap.for:1572 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE imptrap.for:1573 */
/*<       else >*/
	} else {
/* SOURCE imptrap.for:1574 */
/*<       rflag=-2 >*/
	    *rflag = -2;
/* SOURCE imptrap.for:1575 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1576 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1577 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1579 */
/*<       p2=p(x2,y2) >*/
    p2 = (*p)(&x2, &y2);
/*         Now half the step and take two steps to X2. */
/* SOURCE imptrap.for:1583 */
/*<       h2=0.5d0*h >*/
    h2 = feq_gen_h_d_ * .5;
/* SOURCE imptrap.for:1584 */
/*<       xmid=x1+h2 >*/
    xmid = x1 + h2;
/*         Make estimate of the root at the new location. */
/* SOURCE imptrap.for:1588 */
/*<       ymid=0.5d0*(y1+y2) >*/
    ymid = (y1 + y2) * .5;
/* SOURCE imptrap.for:1590 */
/*<       if(prismatic.eq.0)then >*/
    if (*prismatic == 0) {
/* SOURCE imptrap.for:1591 */
/*<       ycrit_mid=ycrit2 >*/
	feq_gen_ycrit_mid_d_ = ycrit2;
/* SOURCE imptrap.for:1592 */
/*<       ynorm_mid=ynorm2 >*/
	feq_gen_ynorm_mid_d_ = ynorm2;
/* SOURCE imptrap.for:1593 */
/*<        >*/
	(*feq_gen_find_ycynym_d_)(stdout, &xmid, epsarg, epsf, epsabs, &feq_gen_ycrit_mid_d_, &
		feq_gen_ynorm_mid_d_, &feq_gen_ymax_mid_d_, rflag);
/* SOURCE imptrap.for:1597 */
/*<       if(rflag.ne.1)then >*/
	if (*rflag != 1) {
/*             Computational failure */
/* SOURCE imptrap.for:1599 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1600 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1601 */
/*<       if(rflag.ne.1)then >*/
	if (*rflag != 1) {
/*             Computational failure when normal depth is known to */
/*             exist. */
/* SOURCE imptrap.for:1604 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1605 */
/*<       endif >*/
	}
/*           Compute the new profile limits and adjust the estimate. */
/* SOURCE imptrap.for:1607 */
/*<        >*/
	feq_gen_set_limits_and_estimate_d_(&state, &feq_gen_c_d_0, &feq_gen_c_d_2, &feq_gen_ycrit_mid_d_, &
		feq_gen_ynorm_mid_d_, &feq_gen_ymax_mid_d_, &ymid, &feq_gen_yup_mid_d_, &feq_gen_ydn_mid_d_, &
		feq_gen_ycrit_yes_d_);
/* SOURCE imptrap.for:1612 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1614 */
/*<       yt=ymid >*/
    yt = ymid;
/* SOURCE imptrap.for:1615 */
/*<       callsetup_for_secant(yt,yup_mid,ydn_mid,ymid,root) >*/
    feq_gen_setup_for_secant_d_(&yt, &feq_gen_yup_mid_d_, &feq_gen_ydn_mid_d_, &ymid, &root);
/*         Find solution at XMID with step of H/2 */
/* SOURCE imptrap.for:1620 */
/*<        >*/
    feq_gen_get_root_d_(&h2, &f1, &p1, &xmid, &ymid, f, p, epsf, epsarg, 
	    epsabs, &feq_gen_yup_mid_d_, &feq_gen_ydn_mid_d_, &root, rflag);
/* SOURCE imptrap.for:1625 */
/*<       ymid=root >*/
    ymid = root;
/*          WRITE(STDOUT,*) ' YMID=',YMID,' RFLAG=',RFLAG */
/* SOURCE imptrap.for:1628 */
/*<       if(rflag.eq.0)then >*/
    if (*rflag == 0) {
/*           No solution found.  Reduce the step and try again. */
/* SOURCE imptrap.for:1630 */
/*<       h=0.9d0*h >*/
	feq_gen_h_d_ *= .9;
/* SOURCE imptrap.for:1631 */
/*<       if(abs(h).gt.abs(hmin))then >*/
	if (abs(feq_gen_h_d_) > abs(hmin)) {
/* SOURCE imptrap.for:1632 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE imptrap.for:1633 */
/*<       else >*/
	} else {
/* SOURCE imptrap.for:1634 */
/*<       rflag=-3 >*/
	    *rflag = -3;
/* SOURCE imptrap.for:1635 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1636 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1637 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1639 */
/*<       pmid=p(xmid,ymid) >*/
    pmid = (*p)(&xmid, &ymid);
/* SOURCE imptrap.for:1640 */
/*<       fmid=f(xmid,ymid) >*/
    fmid = (*f)(&xmid, &ymid);
/*         Find solution at X2 with a step of H/2 from XMID */
/*         We already have the limits for this point.  And we */
/*         know that Y2 is within the proper limits. */
/* SOURCE imptrap.for:1645 */
/*<       yt=y2 >*/
    yt = y2;
/* SOURCE imptrap.for:1646 */
/*<       callsetup_for_secant(yt,yup2,ydn2,y2end,root) >*/
    feq_gen_setup_for_secant_d_(&yt, &yup2, &ydn2, &y2end, &root);
/*         Find solution at X2 with second step of H/2 */
/* SOURCE imptrap.for:1651 */
/*<        >*/
    feq_gen_get_root_d_(&h2, &fmid, &pmid, &x2, &y2end, f, p, epsf, epsarg,
	     epsabs, &yup2, &ydn2, &root, rflag);
/* SOURCE imptrap.for:1656 */
/*<       y2end=root >*/
    y2end = root;
/*          WRITE(STDOUT,*) ' Y2END=',Y2END,' RFLAG=',RFLAG */
/* SOURCE imptrap.for:1659 */
/*<       if(rflag.eq.0)then >*/
    if (*rflag == 0) {
/*           No solution found.  Reduce the step and try again. */
/* SOURCE imptrap.for:1661 */
/*<       h=0.9d0*h >*/
	feq_gen_h_d_ *= .9;
/* SOURCE imptrap.for:1662 */
/*<       if(abs(h).gt.abs(hmin))then >*/
	if (abs(feq_gen_h_d_) > abs(hmin)) {
/* SOURCE imptrap.for:1663 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE imptrap.for:1664 */
/*<       else >*/
	} else {
/* SOURCE imptrap.for:1665 */
/*<       rflag=-4 >*/
	    *rflag = -4;
/* SOURCE imptrap.for:1666 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1667 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1668 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1670 */
/*<       p2end=p(x2,y2end) >*/
    p2end = (*p)(&x2, &y2end);
/*         We now have the two estimates at X2: Y2 and Y2 end. */
/* SOURCE imptrap.for:1674 */
/*<       relerr=abs((p2-p2end)/(3.d0*p2end)) >*/
    relerr = (feq_gen_d_d_1 = (p2 - p2end) / (p2end * 3.), abs(feq_gen_d_d_1));
/*          WRITE(STDOUT,*) ' RELERR=',RELERR,' EPS=',EPS */
/*          WRITE(STDOUT,*) ' H=',H */
/*          WRITE(STDOUT,*) ' ' */
/* SOURCE imptrap.for:1680 */
/*<       if(relerr.le.eps)goto300 >*/
    if (relerr <= *eps) {
	goto L300;
    }
/*         Error is too large.  Reduce the step and try again. */
/* SOURCE imptrap.for:1684 */
/*<       h=(0.9d0*(eps/relerr)**0.33333333333333d0)*h >*/
    feq_gen_d_d_1 = *eps / relerr;
    feq_gen_h_d_ = pow_dd(&feq_gen_d_d_1, &c_b113) * .9 * feq_gen_h_d_;
/* SOURCE imptrap.for:1686 */
/*<       if(abs(h).lt.abs(hmin))then >*/
    if (abs(feq_gen_h_d_) < abs(hmin)) {
/* SOURCE imptrap.for:1687 */
/*<       rflag=-9 >*/
	*rflag = -9;
/* SOURCE imptrap.for:1688 */
/*<       write(stdout,*)' Y2=',y2,' Y2END=',y2end >*/
	feq_gen_io_d__182.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__182);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Y2="), (ftnlen)4);
	do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&y2, (ftnlen)sizeof(doublereal));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Y2END="), (ftnlen)7);
	do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&y2end, (ftnlen)sizeof(doublereal));
	e_wsle();
/* SOURCE imptrap.for:1689 */
/*<       write(stdout,*)' YCRIT2=',ycrit2,' YNORM2=',ynorm2 >*/
	feq_gen_io_d__183.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__183);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YCRIT2="), (ftnlen)8);
	do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&ycrit2, (ftnlen)sizeof(doublereal));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YNORM2="), (ftnlen)8);
	do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&ynorm2, (ftnlen)sizeof(doublereal));
	e_wsle();
/* SOURCE imptrap.for:1690 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:1691 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1692 */
/*<       goto200 >*/
    goto L200;
/* SOURCE imptrap.for:1694 */
/*<   300 continue >*/
L300:
/* SOURCE imptrap.for:1697 */
/*<       y2best=y2end >*/
    y2best = y2end;
/*       We have completed a step of H with an estimated value */
/*       of P, P2END, that satisfies the local tolerance for */
/*       truncation error.  The value of Y, Y2END is the */
/*       current best estimate.  Do optional extrapolation correction. */
/* SOURCE imptrap.for:1703 */
/*<       if(extrap.eq.1)then >*/
    if (*extrap == 1) {
/* SOURCE imptrap.for:1704 */
/*<       p2best=p2end+(p2end-p2)/3 >*/
	p2best = p2end + (p2end - p2) / 3;
/*         Solve for the value of Y that matches P2BEST and that */
/*         also falls within the valid limits for a solution. */
/* SOURCE imptrap.for:1709 */
/*<       yt=y2best >*/
	yt = y2best;
/* SOURCE imptrap.for:1710 */
/*<       callsetup_for_secant(yt,yup2,ydn2,y2best,root) >*/
	feq_gen_setup_for_secant_d_(&yt, &yup2, &ydn2, &y2best, &root);
/* SOURCE imptrap.for:1713 */
/*<        >*/
	feq_gen_invert_p_d_(&p2best, &x2, &y2best, p, &yup2, &ydn2, epsf, epsabs,
		 epsarg, &root, rflag);
/* SOURCE imptrap.for:1718 */
/*<       if(rflag.eq.0)then >*/
	if (*rflag == 0) {
/*           No solution found.  Reduce the step and try again. */
/* SOURCE imptrap.for:1720 */
/*<       h=0.9d0*h >*/
	    feq_gen_h_d_ *= .9;
/* SOURCE imptrap.for:1721 */
/*<       if(abs(h).gt.abs(hmin))then >*/
	    if (abs(feq_gen_h_d_) > abs(hmin)) {
/* SOURCE imptrap.for:1723 */
/*<       goto200 >*/
		goto L200;
/* SOURCE imptrap.for:1724 */
/*<       else >*/
	    } else {
/* SOURCE imptrap.for:1725 */
/*<       rflag=-4 >*/
		*rflag = -4;
/* SOURCE imptrap.for:1726 */
/*<       goto1000 >*/
		goto L1000;
/* SOURCE imptrap.for:1727 */
/*<       endif >*/
	    }
/* SOURCE imptrap.for:1728 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1729 */
/*<       y2best=root >*/
	y2best = root;
/* SOURCE imptrap.for:1730 */
/*<       endif >*/
    }
/*       At this point we have found a solution at X2.  Store the */
/*       point and prepare for the next step, if there is one. */
/* SOURCE imptrap.for:1735 */
/*<       i=i+inc >*/
    feq_gen_i_d_ += inc;
/* SOURCE imptrap.for:1736 */
/*<       if(i.gt.nmax)then >*/
    if (feq_gen_i_d_ > *nmax) {
/* SOURCE imptrap.for:1737 */
/*<       rflag=-1 >*/
	*rflag = -1;
/* SOURCE imptrap.for:1738 */
/*<       n=i-1 >*/
	*n = feq_gen_i_d_ - 1;
/* SOURCE imptrap.for:1739 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:1740 */
/*<       elseif(i.lt.1)then >*/
    } else if (feq_gen_i_d_ < 1) {
/* SOURCE imptrap.for:1741 */
/*<       rflag=-1 >*/
	*rflag = -1;
/* SOURCE imptrap.for:1742 */
/*<       n=i+1 >*/
	*n = feq_gen_i_d_ + 1;
/* SOURCE imptrap.for:1743 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE imptrap.for:1744 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1746 */
/*<       n=i >*/
    *n = feq_gen_i_d_;
/* SOURCE imptrap.for:1747 */
/*<       xvec(i)=x2 >*/
    xvec[feq_gen_i_d_] = x2;
/* SOURCE imptrap.for:1748 */
/*<       yvec(i)=y2best >*/
    yvec[feq_gen_i_d_] = y2best;
/* SOURCE imptrap.for:1749 */
/*<       ycvec(i)=ycrit2 >*/
    ycvec[feq_gen_i_d_] = ycrit2;
/* SOURCE imptrap.for:1750 */
/*<       ynvec(i)=ynorm2 >*/
    ynvec[feq_gen_i_d_] = ynorm2;
/* SOURCE imptrap.for:1752 */
/*<       if(h.gt.0)then >*/
    if (feq_gen_h_d_ > 0.) {
/* SOURCE imptrap.for:1753 */
/*<       if(x2.ge.xe)then >*/
	if (x2 >= *xe) {
/* SOURCE imptrap.for:1754 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1755 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1756 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:1757 */
/*<       if(x2.le.xe)then >*/
	if (x2 <= *xe) {
/* SOURCE imptrap.for:1758 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1759 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1760 */
/*<       endif >*/
    }
/*       Check to see if we are close to critical depth but only */
/*       when the course of the computations can attain critical depth. */
/* SOURCE imptrap.for:1765 */
/*<       if(ycrit_yes.eq.1)then >*/
    if (feq_gen_ycrit_yes_d_ == 1) {
/* SOURCE imptrap.for:1766 */
/*<       if(abs(y2best-ycrit2)/ycrit2.lt.0.01d0)then >*/
	if ((feq_gen_d_d_1 = y2best - ycrit2, abs(feq_gen_d_d_1)) / ycrit2 < .01) {
/* SOURCE imptrap.for:1767 */
/*<       rflag=2 >*/
	    *rflag = 2;
/* SOURCE imptrap.for:1768 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE imptrap.for:1769 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1770 */
/*<       endif >*/
    }
/*       Adjust the step */
/* SOURCE imptrap.for:1772 */
/*<       if(relerr.gt.0.d0)then >*/
    if (relerr > 0.) {
/* SOURCE imptrap.for:1773 */
/*<       hfac=0.9*(eps/relerr)**0.3333333333d0 >*/
	feq_gen_d_d_1 = *eps / relerr;
	hfac = pow_dd(&feq_gen_d_d_1, &c_b134) * (float).9;
/* SOURCE imptrap.for:1774 */
/*<       if(hfac.le.dhlim)then >*/
	if (hfac <= *dhlim) {
/* SOURCE imptrap.for:1775 */
/*<       h=hfac*h >*/
	    feq_gen_h_d_ = hfac * feq_gen_h_d_;
/* SOURCE imptrap.for:1776 */
/*<       else >*/
	} else {
/* SOURCE imptrap.for:1777 */
/*<       h=dhlim*h >*/
	    feq_gen_h_d_ = *dhlim * feq_gen_h_d_;
/* SOURCE imptrap.for:1778 */
/*<       endif >*/
	}
/* SOURCE imptrap.for:1779 */
/*<       else >*/
    } else {
/* SOURCE imptrap.for:1780 */
/*<       h=dhlim*h >*/
	feq_gen_h_d_ = *dhlim * feq_gen_h_d_;
/* SOURCE imptrap.for:1781 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1783 */
/*<       if(abs(h).gt.abs(hmax))then >*/
    if (abs(feq_gen_h_d_) > abs(hmax)) {
/* SOURCE imptrap.for:1784 */
/*<       h=hmax >*/
	feq_gen_h_d_ = hmax;
/* SOURCE imptrap.for:1785 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1786 */
/*<       x1=x2 >*/
    x1 = x2;
/* SOURCE imptrap.for:1787 */
/*<       y1=y2best >*/
    y1 = y2best;
/* SOURCE imptrap.for:1788 */
/*<       goto100 >*/
    goto L100;
/* SOURCE imptrap.for:1790 */
/*<  1000 continue >*/
L1000:
/* SOURCE imptrap.for:1791 */
/*<       if(rflag.lt.1)then >*/
    if (*rflag < 1) {
/* SOURCE imptrap.for:1792 */
/*<       callerrors_in_imptrap(stdout,rflag,n,x1,nmax,h,h2) >*/
	feq_gen_errors_in_imptrap_d_(stdout, rflag, n, &x1, nmax, &feq_gen_h_d_, &h2);
/* SOURCE imptrap.for:1794 */
/*<       endif >*/
    }
/* SOURCE imptrap.for:1796 */
/*<       return >*/
    return 0;
/* SOURCE imptrap.for:1797 */
/*<       end >*/
} /* imptrap_ */

#ifdef __cplusplus
	}
#endif
