extern "C" void feq_interpolate_ritter_section_interval(int,int,float,float,float*,float*,float*,float*,float*);
#include <feq/section_interpolation.hpp>
#include <feq/section_interpolation.hpp>
/* tablook.f -- translated by f2c (version 20240504).
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

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;

/*     Table lookup not in comprog.for */



/* SOURCE tablook.for:6 */
/*<       subroutinefndelv(num,lout,eflag,elev) >*/
/* Subroutine */ int fndelv_(integer *num, integer *lout, integer *eflag, 
	real *elev)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:198* Cross sec. tab. num.=\002,i5\
,\002 not found for\002,\002 elevation.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer adrs;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__4 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the elevation of the cross section from the table */
/*     given by the table number in NUM. */
/* SOURCE tablook.for:14 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tablook.for:17 */
/*<       integereflag,lout,num >*/
/* SOURCE tablook.for:18 */
/*<       realelev >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NUM    - Cross section index number */
/*     LOUT   - Fortran unit number for user output and messages */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     ELEV   - Elevation of minimum point in the cross section function */
/*               table */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tablook.for:28 */
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
/* INCLUDE tablook.for:29 */
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
/* SOURCE tablook.for:32 */
/*<       integeradrs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tablook.for:35 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE tablook.for:38 */
/*<       if(num.le.0)then >*/
/* L50: */
    if (*num <= 0) {
/* SOURCE tablook.for:39 */
/*<       write(lout,50)num >*/
	feq_gen_io_d__4.ciunit = *lout;
	s_wsfe(&feq_gen_io_d__4);
	do_fio(&feq_gen_c_d_1, (char *)&(*num), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE tablook.for:40 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE tablook.for:41 */
/*<       elev=0.0 >*/
	*elev = (float)0.;
/* SOURCE tablook.for:42 */
/*<       else >*/
    } else {
/* SOURCE tablook.for:43 */
/*<       adrs=ftpnt(num) >*/
	adrs = ftablea_1.ftpnt[*num - 1];
/* SOURCE tablook.for:44 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/* SOURCE tablook.for:45 */
/*<       elev=ftab(adrs+5) >*/
	    *elev = ftab[adrs + 5];
/* SOURCE tablook.for:46 */
/*<       else >*/
	} else {
/*         TABLE DOES NOT EXIST */
/* SOURCE tablook.for:49 */
/*<       write(lout,50)num >*/
	    feq_gen_io_d__6.ciunit = *lout;
	    s_wsfe(&feq_gen_io_d__6);
	    do_fio(&feq_gen_c_d_1, (char *)&(*num), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE tablook.for:50 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE tablook.for:51 */
/*<       elev=0.0 >*/
	    *elev = (float)0.;
/* SOURCE tablook.for:52 */
/*<       endif >*/
	}
/* SOURCE tablook.for:53 */
/*<       endif >*/
    }
/* SOURCE tablook.for:54 */
/*<       return >*/
    return 0;
/* SOURCE tablook.for:55 */
/*<       end >*/
} /* fndelv_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tablook.for:59 */
/*<       subroutinexlookw(adrs,xoff,adepth,area,top,dtop,c,w) >*/
/* Subroutine */ int xlookw_(integer *adrs, integer *xoff, real *adepth, real 
	*area, real *top, real *dtop, real *feq_gen_c_d_, real *w)
{
    /* Format strings */
    static char fmt_2000[] = "(\0020\002,\002*WRN:522* ESCOF. TABLE BELOW RA\
NGE IN XLOOKW\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER =\
 \002,e10.3,/,1x,\002 DEPTH          = \002,f10.2)";
    static char fmt_2010[] = "(\0020\002,\002*WRN:523* ESCOF. TABLE ABOVE RA\
NGE IN XLOOKW\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER =\
 \002,e10.3,/,1x,\002 DEPTH          = \002,f10.2)";

    /* System generated locals */
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    double sqrt(doublereal);

    /* Local variables */
    real feq_gen_h_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer ha, la;
    real dy, dtp;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    real fact;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer lsta;
    real tone, yone;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real ydiff, depth, azero, czero, tzero, wzero, yzero;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_2010, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth find area, top-width, first moment, celerity, and */
/*     escoffier stage variable. */
/* SOURCE tablook.for:67 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tablook.for:70 */
/*<       integeradrs,xoff >*/
/* SOURCE tablook.for:71 */
/*<       realadepth,area,c,dtop,top,w >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - Address of function table */
/*     XOFF   - Offset between successive depth values for cross section */
/*               function table */
/*     ADEPTH - Depth argument */
/*     AREA   - Flow area */
/*     TOP    - Top width for the cross section */
/*     DTOP   - derivative of the top width with respect to depth */
/*     C      - Celerity */
/*     W      - Value of the Escoffier stage variable */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tablook.for:85 */
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
/* INCLUDE tablook.for:86 */
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
/* INCLUDE tablook.for:87 */
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
/* INCLUDE tablook.for:88 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/*     Called subprograms */
/* SOURCE tablook.for:91 */
/*<       character*16get_tabid >*/
/* SOURCE tablook.for:92 */
/*<       externalget_tabid >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tablook.for:95 */
/*<       integerha,la,lsta >*/
/* SOURCE tablook.for:96 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE tablook.for:100 */
/*<       intrinsicabs,sqrt >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tablook.for:103 */
/*<  2000  >*/
/* SOURCE tablook.for:107 */
/*<  2010  >*/
/* *********************************************************************** */
/* SOURCE tablook.for:112 */
/*<       depth=adepth >*/
/* L2000: */
/* L2010: */
    depth = *adepth;
/* SOURCE tablook.for:113 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE tablook.for:114 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE tablook.for:115 */
/*<       lsta=itab(adrs+3) >*/
    lsta = itab[*adrs + 3];
/* SOURCE tablook.for:117 */
/*<       ydiff=depth-ftab(lsta) >*/
    ydiff = static_cast<double>(depth) - ftab[lsta];
/* SOURCE tablook.for:118 */
/*<       if(ydiff)100,300,200 >*/
    if (ydiff < (float)0.) {
	goto L100;
    } else if (ydiff == 0) {
	goto L300;
    } else {
	goto L200;
    }
/*     DEPTH PASSED LESS THAN AT PREVIOUS ACCESS TO TABLE */
/* SOURCE tablook.for:122 */
/*<   100 if(lsta.ge.la)goto110 >*/
L100:
    if (lsta >= la) {
	goto L110;
    }
/* SOURCE tablook.for:123 */
/*<       write(lout,2000)get_tabid(itab(adrs+1)),ftab(adrs+4),depth >*/
    feq_gen_io_d__15.ciunit = xscom_1.lout;
    s_wsfe(&feq_gen_io_d__15);
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&depth, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE tablook.for:124 */
/*<       lsta=la >*/
    lsta = la;
/* SOURCE tablook.for:125 */
/*<       depth=ftab(la+xoff) >*/
    depth = ftab[la + *xoff];
/* SOURCE tablook.for:126 */
/*<       goto300 >*/
    goto L300;
/* SOURCE tablook.for:128 */
/*<   110 if(depth.ge.ftab(lsta))goto300 >*/
L110:
    if (depth >= ftab[lsta]) {
	goto L300;
    }
/* SOURCE tablook.for:129 */
/*<       lsta=lsta-xoff >*/
    lsta -= *xoff;
/* SOURCE tablook.for:130 */
/*<       goto100 >*/
    goto L100;
/*     DEPTH PASSED GREATER THAN AT PREVIOUS ACCESS TO TABLE */
/* SOURCE tablook.for:134 */
/*<   200 if(lsta.lt.ha)goto210 >*/
L200:
    if (lsta < ha) {
	goto L210;
    }
/* SOURCE tablook.for:135 */
/*<       if(abs(depth-ftab(ha)).gt.0.0051)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(depth) - ftab[ha], dabs(feq_gen_r_d_1)) > (float).0051) {
/* SOURCE tablook.for:136 */
/*<       write(lout,2010)get_tabid(itab(adrs+1)),ftab(adrs+4),depth >*/
	feq_gen_io_d__16.ciunit = xscom_1.lout;
	s_wsfe(&feq_gen_io_d__16);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&depth, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE tablook.for:137 */
/*<       endif >*/
    }
/* SOURCE tablook.for:138 */
/*<       depth=ftab(ha) >*/
    depth = ftab[ha];
/* SOURCE tablook.for:139 */
/*<       lsta=ha-xoff >*/
    lsta = ha - *xoff;
/* SOURCE tablook.for:140 */
/*<       goto300 >*/
    goto L300;
/* SOURCE tablook.for:143 */
/*<   210 if(depth.le.ftab(lsta+xoff))goto300 >*/
L210:
    if (depth <= ftab[lsta + *xoff]) {
	goto L300;
    }
/* SOURCE tablook.for:144 */
/*<       lsta=lsta+xoff >*/
    lsta += *xoff;
/* SOURCE tablook.for:145 */
/*<       goto200 >*/
    goto L200;
/* SOURCE tablook.for:147 */
/*<   300 continue >*/
L300:
// Preserve the original interval search, diagnostics and cache.
    feq_interpolate_ritter_section_interval(lsta,lsta+*xoff,depth,grvcom_1.grav,
        area,top,dtop,feq_gen_c_d_,w);
    itab[*adrs + 3] = lsta;
/* SOURCE tablook.for:181 */
/*<       return >*/
    return 0;
/* SOURCE tablook.for:182 */
/*<       end >*/
} /* xlookw_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tablook.for:186 */
/*<       subroutinelktk(adrs,ya,k) >*/
/* Subroutine */ int lktk_(integer *adrs, real *ya, real *k)
{
    /* Initialized data */

    static integer vtype[35] = { 1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,
	    1,1,1,0,0,0,0,1,1,1,1,1,1 };

    /* Format strings */
    static char fmt_2000[] = "(\0020\002,\002*WRN:41* X-SECTION BELOW RANGE \
IN LKTK\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,f1\
0.3/,1x,\002 TIME           = \002,f10.0,/,1x,\002 DEPTH          = \002,f10\
.2)";
    static char fmt_2010[] = "(\0020\002,\002*WRN:42* X-SECTION ABOVE RANGE \
IN LKTK\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,f1\
0.3/,1x,\002 TIME           = \002,f10.0,/,1x,\002 DEPTH          = \002,f10\
.2)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer l;
    real y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real k0, y0;
    integer ha, la;
    real dk, dy;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth lookup conveyance in a cross section table. */
/* SOURCE tablook.for:194 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tablook.for:197 */
/*<       integeradrs >*/
/* SOURCE tablook.for:198 */
/*<       realk,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - Address of function table */
/*     YA     - maximum depth in a cross section */
/*     K      - conveyance */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tablook.for:206 */
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
/* INCLUDE tablook.for:207 */
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
/* INCLUDE tablook.for:208 */
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
/* INCLUDE tablook.for:209 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE tablook.for:212 */
/*<       integervtype(35) >*/
/* SOURCE tablook.for:213 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tablook.for:216 */
/*<       integerha,l,la,type,xoff >*/
/* SOURCE tablook.for:217 */
/*<       realdk,dy,k0,y,y0 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tablook.for:220 */
/*<       character*16get_tabid >*/
/* SOURCE tablook.for:221 */
/*<       externalget_tabid,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tablook.for:224 */
/*<       datavtype/1,10*0,1,7*0,6*1,4*0,6*1/ >*/
/* SOURCE tablook.for:227 */
/*<  2000  >*/
/* L2000: */
/* SOURCE tablook.for:232 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO THIS TABLE */
/* SOURCE tablook.for:242 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE tablook.for:243 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE tablook.for:244 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE tablook.for:245 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE tablook.for:247 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE tablook.for:248 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE tablook.for:249 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE tablook.for:250 */
/*<       callxstype(lout,vtype,itab(adrs+1)) >*/
	xstype_(&xscom_1.lout, vtype, itab.lease(*adrs + 1).data());
/* SOURCE tablook.for:252 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE tablook.for:253 */
/*<       endif >*/
    }
/* SOURCE tablook.for:255 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE tablook.for:257 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE tablook.for:258 */
/*<       write(lout,2010)get_tabid(itab(adrs+1)),ftab(adrs+4),time,y >*/
	    feq_gen_io_d__38.ciunit = xscom_1.lout;
	    s_wsfe(&feq_gen_io_d__38);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tablook.for:260 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE tablook.for:261 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE tablook.for:262 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE tablook.for:263 */
/*<       else >*/
	} else {
/* SOURCE tablook.for:264 */
/*<   100 continue >*/
L100:
/* SOURCE tablook.for:265 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE tablook.for:266 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE tablook.for:267 */
/*<       goto100 >*/
		goto L100;
/* SOURCE tablook.for:268 */
/*<       endif >*/
	    }
/* SOURCE tablook.for:269 */
/*<       endif >*/
	}
/* SOURCE tablook.for:270 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE tablook.for:272 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE tablook.for:273 */
/*<       write(lout,2000)get_tabid(itab(adrs+1)),ftab(adrs+4),time,y >*/
	    feq_gen_io_d__39.ciunit = xscom_1.lout;
	    s_wsfe(&feq_gen_io_d__39);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tablook.for:275 */
/*<       l=la >*/
	    l = la;
/* SOURCE tablook.for:276 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE tablook.for:277 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE tablook.for:278 */
/*<       else >*/
	} else {
/* SOURCE tablook.for:279 */
/*<   110 continue >*/
L110:
/* SOURCE tablook.for:280 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE tablook.for:281 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE tablook.for:282 */
/*<       endif >*/
	}
/* SOURCE tablook.for:283 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE tablook.for:290 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
/*     FETCH VALUES FROM FTAB */
/* SOURCE tablook.for:294 */
/*<       y0=ftab(l) >*/
    // Preserve the original interval selection, diagnostics and cached row.
    *k = feq::interpolate_scalar_conveyance(y,ftab[l],ftab[l+3],ftab[l+xoff],ftab[l+xoff+3]);
    return 0;
} /* lktk_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tablook.for:308 */
/*<       integerfunctionlocsta(stdout,stat,dir,jaxis,numsec,stl,eps) >*/
integer locsta_(integer *stdout, real *stat, integer *dir, integer *jaxis, 
	integer *numsec, real *feq_storage_stl, real *eps)
{
    /* Initialized data */

    static integer l = 1;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:678* Cross section station=\002,f10\
.4,\002 not found.\002)";

    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer loc;
    extern /* Subroutine */ int fstdec_(real *, integer *, real *, real *, 
	    integer *, integer *), fstinc_(real *, integer *, real *, real *, 
	    integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find STAT in STL(*,*).  Must agree closely because no */
/*     interpolation is defined.  Return value of index.  DIR */
/*     gives the direction of the station values in STL. */
/* SOURCE tablook.for:317 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE tablook.for:320 */
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
/* SOURCE tablook.for:323 */
/*<       integerdir,jaxis,numsec,stdout >*/
/* SOURCE tablook.for:324 */
/*<       realeps,stat,stl(pmxsec,pmxnfl) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STAT   - Station being sought */
/*     DIR    - If DIR > 0 then stations are ascending order, else */
/*               descending order */
/*     JAXIS  - Column in which the values for the channel axis are */
/*               stored */
/*     NUMSEC - Number of cross sections in sequence */
/*     STL    - Table for flow line stations */
/*     EPS    - Tolerance for matching stations */
/*     + + + SAVED VALUES + + + */
/* SOURCE tablook.for:338 */
/*<       integerl >*/
/* SOURCE tablook.for:339 */
/*<       savel >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tablook.for:342 */
/*<       integerloc >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tablook.for:345 */
/*<       externalfstdec,fstinc >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tablook.for:348 */
/*<       datal/1/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> stl(feq_storage_stl, 401);

    /* Function Body */
/* SOURCE tablook.for:351 */
/*<    50 format(/,' *ERR:678* Cross section station=',f10.4,' not found.') >*/
/* L50: */
/* *********************************************************************** */
/* SOURCE tablook.for:353 */
/*<       if(dir.gt.0)then >*/
    if (*dir > 0) {
/*       STATIONS IN STL ARE ASCENDING */
/*       MAKE SURE L IS IN THE RIGHT RANGE */
/* SOURCE tablook.for:357 */
/*<       if(l.gt.numsec)l=1 >*/
	if (l > *numsec) {
	    l = 1;
	}
/* SOURCE tablook.for:359 */
/*<       if(stat.gt.stl(numsec,jaxis).or.stat.lt.stl(1,jaxis))then >*/
	if (*stat > stl[*numsec + *jaxis * 400] || *stat < stl[*jaxis * 400 + 
		1]) {
/*         REQUESTED STATION FALLS OUTSIDE THE LIMITS OF THE */
/*         DEFINED SINUOUSITIES */
/* SOURCE tablook.for:362 */
/*<       write(stdout,50)stat >*/
	    feq_gen_io_d__45.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__45);
	    do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tablook.for:363 */
/*<       locsta=0 >*/
	    ret_val = 0;
/* SOURCE tablook.for:364 */
/*<       else >*/
	} else {
/* SOURCE tablook.for:365 */
/*<       callfstinc(stat,jaxis,stl,eps,l,loc) >*/
	    fstinc_(stat, jaxis, &stl[401], eps, &l, &loc);
/* SOURCE tablook.for:369 */
/*<       if(loc.eq.0)then >*/
	    if (loc == 0) {
/* SOURCE tablook.for:370 */
/*<       write(stdout,50)stat >*/
		feq_gen_io_d__47.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__47);
		do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE tablook.for:371 */
/*<       locsta=0 >*/
		ret_val = 0;
/* SOURCE tablook.for:372 */
/*<       else >*/
	    } else {
/* SOURCE tablook.for:374 */
/*<       locsta=loc >*/
		ret_val = loc;
/* SOURCE tablook.for:375 */
/*<       endif >*/
	    }
/* SOURCE tablook.for:376 */
/*<       endif >*/
	}
/* SOURCE tablook.for:377 */
/*<       else >*/
    } else {
/*       STATIONS IN STL ARE DESCENDING */
/*       MAKE SURE L IS IN THE RIGHT RANGE */
/* SOURCE tablook.for:381 */
/*<       if(l.gt.numsec)l=1 >*/
	if (l > *numsec) {
	    l = 1;
	}
/* SOURCE tablook.for:383 */
/*<       if(stat.lt.stl(numsec,jaxis).or.stat.gt.stl(1,jaxis))then >*/
	if (*stat < stl[*numsec + *jaxis * 400] || *stat > stl[*jaxis * 400 + 
		1]) {
/*         REQUESTED STATION FALLS OUTSIDE THE LIMITS OF THE */
/*         DEFINED SINUOUSITIES */
/* SOURCE tablook.for:386 */
/*<       write(stdout,50)stat >*/
	    feq_gen_io_d__48.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__48);
	    do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tablook.for:387 */
/*<       locsta=0 >*/
	    ret_val = 0;
/* SOURCE tablook.for:388 */
/*<       else >*/
	} else {
/* SOURCE tablook.for:389 */
/*<       callfstdec(stat,jaxis,stl,eps,l,loc) >*/
	    fstdec_(stat, jaxis, &stl[401], eps, &l, &loc);
/* SOURCE tablook.for:393 */
/*<       if(loc.eq.0)then >*/
	    if (loc == 0) {
/* SOURCE tablook.for:394 */
/*<       write(stdout,50)stat >*/
		feq_gen_io_d__49.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__49);
		do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE tablook.for:395 */
/*<       locsta=0 >*/
		ret_val = 0;
/* SOURCE tablook.for:396 */
/*<       else >*/
	    } else {
/* SOURCE tablook.for:397 */
/*<       locsta=loc >*/
		ret_val = loc;
/* SOURCE tablook.for:398 */
/*<       endif >*/
	    }
/* SOURCE tablook.for:399 */
/*<       endif >*/
	}
/* SOURCE tablook.for:400 */
/*<       endif >*/
    }
/* SOURCE tablook.for:401 */
/*<       return >*/
    return ret_val;
/* SOURCE tablook.for:402 */
/*<       end >*/
} /* locsta_ */




/* SOURCE tablook.for:406 */
/*<       subroutinexlka(y,nd,yv,tv,av,t,a) >*/
/* Subroutine */ int xlka_(real *y, integer *nd, real *feq_storage_yv, real *feq_storage_tv, real *feq_storage_av,
	 real *t, real *a)
{
    real feq_gen_h_d_;
    integer l;
    real p;
    integer ll;
    real ph;

/*     + + + PURPOSE + + + */
/*     Find T and A in a table. */
/* SOURCE tablook.for:413 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tablook.for:416 */
/*<       integernd >*/
/* SOURCE tablook.for:417 */
/*<       reala,av(nd),t,tv(nd),y,yv(nd) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - ordinate values on boundary of conduit */
/*     ND     - Number of tabulated values */
/*     YV     - Vector of depth values */
/*     TV     - Vector of top width values */
/*     AV     - Vector of areas */
/*     T      - top width of the cross section */
/*     A      - Cross sectional area */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tablook.for:429 */
/*<       integerl,ll >*/
/* SOURCE tablook.for:430 */
/*<       realh,p,ph >*/
/* *********************************************************************** */
/* SOURCE tablook.for:432 */
/*<       l=1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> av(feq_storage_av, 1);

    feq::IndexedPointer<real> tv(feq_storage_tv, 1);

    feq::IndexedPointer<real> yv(feq_storage_yv, 1);

    /* Function Body */
    l = 1;
/* SOURCE tablook.for:433 */
/*<   100 continue >*/
L100:
/* SOURCE tablook.for:435 */
/*<       if(y.ge.yv(l))then >*/
    if (*y >= yv[l]) {
/* SOURCE tablook.for:436 */
/*<       ll=l+1 >*/
	ll = l + 1;
/* SOURCE tablook.for:437 */
/*<       if(ll.gt.nd)then >*/
	if (ll > *nd) {
/* SOURCE tablook.for:438 */
/*<       t=tv(nd) >*/
	    *t = tv[*nd];
/* SOURCE tablook.for:439 */
/*<       a=av(nd) >*/
	    *a = av[*nd];
/* SOURCE tablook.for:440 */
/*<       l=nd-1 >*/
	    l = *nd - 1;
/* SOURCE tablook.for:441 */
/*<       return >*/
	    return 0;
/* SOURCE tablook.for:442 */
/*<       endif >*/
	}
/* SOURCE tablook.for:443 */
/*<       if(y.le.yv(ll))goto200 >*/
	if (*y <= yv[ll]) {
	    goto L200;
	}
/* SOURCE tablook.for:444 */
/*<       l=ll >*/
	l = ll;
/* SOURCE tablook.for:445 */
/*<       goto100 >*/
	goto L100;
/* SOURCE tablook.for:446 */
/*<       else >*/
    } else {
/* SOURCE tablook.for:447 */
/*<       l=l-1 >*/
	--l;
/* SOURCE tablook.for:448 */
/*<       if(l.lt.1)then >*/
	if (l < 1) {
/* SOURCE tablook.for:449 */
/*<       t=tv(1) >*/
	    *t = tv[1];
/* SOURCE tablook.for:450 */
/*<       a=av(1) >*/
	    *a = av[1];
/* SOURCE tablook.for:451 */
/*<       l=1 >*/
	    l = 1;
/* SOURCE tablook.for:452 */
/*<       return >*/
	    return 0;
/* SOURCE tablook.for:453 */
/*<       endif >*/
	}
/* SOURCE tablook.for:454 */
/*<       goto100 >*/
	goto L100;
/* SOURCE tablook.for:455 */
/*<       endif >*/
    }
/* SOURCE tablook.for:457 */
/*<   200 continue >*/
L200:
/*     INTERPOLATE */
/* SOURCE tablook.for:462 */
/*<       h=yv(l+1)-yv(l) >*/
    feq_gen_h_d_ = static_cast<double>(yv[l + 1]) - yv[l];
/* SOURCE tablook.for:463 */
/*<       ph=y-yv(l) >*/
    ph = static_cast<double>(*y) - yv[l];
/* SOURCE tablook.for:464 */
/*<       p=ph/h >*/
    p = static_cast<double>(ph) / feq_gen_h_d_;
/* SOURCE tablook.for:465 */
/*<       t=tv(l)+p*(tv(l+1)-tv(l)) >*/
    *t = static_cast<double>(tv[l]) + static_cast<double>(p) * (static_cast<double>(tv[l + 1]) - tv[l]);
/* SOURCE tablook.for:466 */
/*<       a=av(l)+ph*(t+tv(l))/2. >*/
    *a = static_cast<double>(av[l]) + static_cast<double>(static_cast<double>(ph) * (static_cast<double>(*t) + tv[l])) / (float)2.;
/* SOURCE tablook.for:467 */
/*<       return >*/
    return 0;
/* SOURCE tablook.for:468 */
/*<       end >*/
} /* xlka_ */




/* SOURCE tablook.for:472 */
/*<       subroutinexlkall(ndep,maxpnt,xst,xsv) >*/
/* Subroutine */ int xlkall_(integer *ndep, integer *maxpnt, real *feq_storage_xst, real *
	feq_storage_xsv)
{
    /* Initialized data */

    static integer l = 1;

    /* System generated locals */
    integer xst_dim1, xst_offset;

    /* Local variables */
    real feq_gen_h_d_;
    integer j;
    real k, p, ph;

/*     + + + PURPOSE + + + */
/*     Find elements in table. */
/* SOURCE tablook.for:479 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tablook.for:482 */
/*<       integermaxpnt,ndep >*/
/* SOURCE tablook.for:483 */
/*<       realxst(maxpnt,*),xsv(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NDEP   - Number of depth values */
/*     MAXPNT - Maximum number of tabulated values in a cross section */
/*               function table */
/*     XST    - Storage table for various elements of cross section */
/*     XSV    - Vector of various elements of cross section */
/*     + + + SAVED VALUES + + + */
/* SOURCE tablook.for:493 */
/*<       integerl >*/
/* SOURCE tablook.for:494 */
/*<       savel >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tablook.for:497 */
/*<       integerj >*/
/* SOURCE tablook.for:498 */
/*<       realh,k,p,ph >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/* SOURCE tablook.for:501 */
/*<       datal/1/ >*/
    /* Parameter adjustments */
    xst_dim1 = *maxpnt;
    xst_offset = 1 + xst_dim1;

    feq::IndexedPointer<real> xst(feq_storage_xst, xst_offset);

    feq::IndexedPointer<real> xsv(feq_storage_xsv, 1);

    /* Function Body */
/* SOURCE tablook.for:503 */
/*<       if(l.gt.ndep)l=1 >*/
    if (l > *ndep) {
	l = 1;
    }
/* SOURCE tablook.for:504 */
/*<   100 continue >*/
L100:
/* SOURCE tablook.for:505 */
/*<       if(xsv(1).ge.xst(l,1))goto120 >*/
    if (xsv[1] >= xst[l + xst_dim1]) {
	goto L120;
    }
/* SOURCE tablook.for:506 */
/*<       if(l.gt.1)goto110 >*/
    if (l > 1) {
	goto L110;
    }
/* SOURCE tablook.for:507 */
/*<       do102j=2,7 >*/
    for (j = 2; j <= 7; ++j) {
/* SOURCE tablook.for:508 */
/*<       xsv(j)=xst(1,j) >*/
	xsv[j] = xst[j * xst_dim1 + 1];
/* SOURCE tablook.for:509 */
/*<   102 continue >*/
/* L102: */
    }
/* SOURCE tablook.for:510 */
/*<       return >*/
    return 0;
/* SOURCE tablook.for:511 */
/*<   110 continue >*/
L110:
/* SOURCE tablook.for:512 */
/*<       l=l-1 >*/
    --l;
/* SOURCE tablook.for:513 */
/*<       goto100 >*/
    goto L100;
/* SOURCE tablook.for:514 */
/*<   120 continue >*/
L120:
/* SOURCE tablook.for:516 */
/*<   130 continue >*/
L130:
/* SOURCE tablook.for:517 */
/*<       if(xsv(1).lt.xst(l+1,1))goto150 >*/
    if (xsv[1] < xst[l + 1 + xst_dim1]) {
	goto L150;
    }
/* SOURCE tablook.for:518 */
/*<       if(l+1.lt.ndep)goto140 >*/
    if (l + 1 < *ndep) {
	goto L140;
    }
/* SOURCE tablook.for:519 */
/*<       do132j=2,7 >*/
    for (j = 2; j <= 7; ++j) {
/* SOURCE tablook.for:520 */
/*<       xsv(j)=xst(ndep,j) >*/
	xsv[j] = xst[*ndep + j * xst_dim1];
/* SOURCE tablook.for:521 */
/*<   132 continue >*/
/* L132: */
    }
/* SOURCE tablook.for:522 */
/*<       return >*/
    return 0;
/* SOURCE tablook.for:523 */
/*<   140 continue >*/
L140:
/* SOURCE tablook.for:524 */
/*<       l=l+1 >*/
    ++l;
/* SOURCE tablook.for:525 */
/*<       goto130 >*/
    goto L130;
/* SOURCE tablook.for:526 */
/*<   150 continue >*/
L150:
/*      INTERPOLATE FOR THE VALUES */
/* SOURCE tablook.for:530 */
/*<       h=xst(l+1,1)-xst(l,1) >*/
    feq_gen_h_d_ = static_cast<double>(xst[l + 1 + xst_dim1]) - xst[l + xst_dim1];
/* SOURCE tablook.for:531 */
/*<       ph=xsv(1)-xst(l,1) >*/
    ph = static_cast<double>(xsv[1]) - xst[l + xst_dim1];
/* SOURCE tablook.for:532 */
/*<       p=ph/h >*/
    p = static_cast<double>(ph) / feq_gen_h_d_;
/* SOURCE tablook.for:534 */
/*<       xsv(2)=xst(l,2)+p*(xst(l+1,2)-xst(l,2)) >*/
    xsv[2] = static_cast<double>(xst[l + (xst_dim1 << 1)]) + static_cast<double>(p) * (static_cast<double>(xst[l + 1 + (xst_dim1 << 1)]) - 
	    xst[l + (xst_dim1 << 1)]);
/* SOURCE tablook.for:535 */
/*<       xsv(3)=xst(l,3)+ph*(xst(l,2)+xsv(2))/2. >*/
    xsv[3] = static_cast<double>(xst[l + xst_dim1 * 3]) + static_cast<double>(static_cast<double>(ph) * (static_cast<double>(xst[l + (xst_dim1 << 1)]) + xsv[2])) 
	    / (float)2.;
/* SOURCE tablook.for:536 */
/*<       xsv(4)=xst(l,4)+ph*((xst(l,3)+xsv(3))/2.-ph*(xsv(2)-xst(l,2))/12.) >*/
    xsv[4] = static_cast<double>(xst[l + (xst_dim1 << 2)]) + static_cast<double>(ph) * (static_cast<double>(static_cast<double>((static_cast<double>(xst[l + xst_dim1 * 3]) + xsv[3]))
	     / (float)2.) - static_cast<double>(static_cast<double>(ph) * (static_cast<double>(xsv[2]) - xst[l + (xst_dim1 << 1)])) / (float)
	    12.);
/* SOURCE tablook.for:537 */
/*<       k=xst(l,5)+p*(xst(l+1,5)-xst(l,5)) >*/
    k = static_cast<double>(xst[l + xst_dim1 * 5]) + static_cast<double>(p) * (static_cast<double>(xst[l + 1 + xst_dim1 * 5]) - xst[l + 
	    xst_dim1 * 5]);
/* SOURCE tablook.for:538 */
/*<       xsv(5)=k*k >*/
    xsv[5] = static_cast<double>(k) * k;
/* SOURCE tablook.for:539 */
/*<       xsv(6)=xst(l,6)+p*(xst(l+1,6)-xst(l,6)) >*/
    xsv[6] = static_cast<double>(xst[l + xst_dim1 * 6]) + static_cast<double>(p) * (static_cast<double>(xst[l + 1 + xst_dim1 * 6]) - xst[l + 
	    xst_dim1 * 6]);
/* SOURCE tablook.for:540 */
/*<       xsv(7)=xst(l,7)+p*(xst(l+1,7)-xst(l,7)) >*/
    xsv[7] = static_cast<double>(xst[l + xst_dim1 * 7]) + static_cast<double>(p) * (static_cast<double>(xst[l + 1 + xst_dim1 * 7]) - xst[l + 
	    xst_dim1 * 7]);
/* SOURCE tablook.for:541 */
/*<       return >*/
    return 0;
/* SOURCE tablook.for:542 */
/*<       end >*/
} /* xlkall_ */




/* SOURCE tablook.for:546 */
/*<       subroutinelkta(adrs,ya,a) >*/
/* Subroutine */ int lkta_(integer *adrs, real *ya, real *a)
{
    /* Initialized data */

    static integer vtype[35] = { 1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,
	    1,1,1,0,0,0,0,1,1,1,1,1,1 };

    /* Format strings */
    static char fmt_2000[] = "(\0020\002,\002*WRN:41* X-SECTION BELOW RANGE \
IN LKTA\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,f1\
0.3/,1x,\002 TIME           = \002,f10.0,/,1x,\002 DEPTH          = \002,f10\
.2)";
    static char fmt_2010[] = "(\0020\002,\002*WRN:42* X-SECTION ABOVE RANGE \
IN LKTA\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,f1\
0.3/,1x,\002 TIME           = \002,f10.0,/,1x,\002 DEPTH          = \002,f10\
.2)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real feq_gen_h_d_;
    integer l;
    real t, y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real a0, t0, y0;
    integer ha, la;
    real dt, dy;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__71 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth lookup area in a cross section table. */
/* SOURCE tablook.for:554 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tablook.for:557 */
/*<       integeradrs >*/
/* SOURCE tablook.for:558 */
/*<       reala,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - Address of function table */
/*     YA     - depth argument */
/*     A      - Cross sectional area */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tablook.for:566 */
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
/* INCLUDE tablook.for:567 */
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
/* INCLUDE tablook.for:568 */
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
/* INCLUDE tablook.for:569 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE tablook.for:572 */
/*<       integervtype(35) >*/
/* SOURCE tablook.for:573 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tablook.for:576 */
/*<       integerha,l,la,type,xoff >*/
/* SOURCE tablook.for:577 */
/*<       reala0,dt,dy,h,t,t0,y,y0 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tablook.for:580 */
/*<       character*16get_tabid >*/
/* SOURCE tablook.for:581 */
/*<       externalget_tabid,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tablook.for:584 */
/*<       datavtype/1,10*0,1,7*0,6*1,4*0,6*1/ >*/
/* SOURCE tablook.for:587 */
/*<  2000  >*/
/* L2000: */
/* SOURCE tablook.for:592 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO THIS TABLE */
/* SOURCE tablook.for:602 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE tablook.for:603 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE tablook.for:604 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE tablook.for:605 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE tablook.for:607 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE tablook.for:608 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE tablook.for:609 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE tablook.for:610 */
/*<       callxstype(lout,vtype,itab(adrs+1)) >*/
	xstype_(&xscom_1.lout, vtype, itab.lease(*adrs + 1).data());
/* SOURCE tablook.for:612 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE tablook.for:613 */
/*<       endif >*/
    }
/* SOURCE tablook.for:615 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE tablook.for:617 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE tablook.for:618 */
/*<       write(lout,2010)get_tabid(itab(adrs+1)),ftab(adrs+4),time,y >*/
	    feq_gen_io_d__71.ciunit = xscom_1.lout;
	    s_wsfe(&feq_gen_io_d__71);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tablook.for:620 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE tablook.for:621 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/*          YA = Y */
/* SOURCE tablook.for:623 */
/*<       else >*/
	} else {
/* SOURCE tablook.for:624 */
/*<   100 continue >*/
L100:
/* SOURCE tablook.for:625 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE tablook.for:626 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE tablook.for:627 */
/*<       goto100 >*/
		goto L100;
/* SOURCE tablook.for:628 */
/*<       endif >*/
	    }
/* SOURCE tablook.for:629 */
/*<       endif >*/
	}
/* SOURCE tablook.for:630 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE tablook.for:632 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE tablook.for:633 */
/*<       write(lout,2000)get_tabid(itab(adrs+1)),ftab(adrs+4),time,y >*/
	    feq_gen_io_d__72.ciunit = xscom_1.lout;
	    s_wsfe(&feq_gen_io_d__72);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tablook.for:635 */
/*<       l=la >*/
	    l = la;
/* SOURCE tablook.for:636 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/*          YA = Y */
/* SOURCE tablook.for:638 */
/*<       else >*/
	} else {
/* SOURCE tablook.for:639 */
/*<   110 continue >*/
L110:
/* SOURCE tablook.for:640 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE tablook.for:641 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE tablook.for:642 */
/*<       endif >*/
	}
/* SOURCE tablook.for:643 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE tablook.for:650 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
/*     FETCH VALUES FROM FTAB */
/* SOURCE tablook.for:654 */
/*<       y0=ftab(l) >*/
    y0 = ftab[l];
/* SOURCE tablook.for:655 */
/*<       t0=ftab(l+1) >*/
    t0 = ftab[l + 1];
/* SOURCE tablook.for:656 */
/*<       a0=ftab(l+2) >*/
    a0 = ftab[l + 2];
/* SOURCE tablook.for:659 */
/*<       dy=ftab(l+xoff)-y0 >*/
    dy = static_cast<double>(ftab[l + xoff]) - y0;
/* SOURCE tablook.for:660 */
/*<       h=y-y0 >*/
    feq_gen_h_d_ = static_cast<double>(y) - y0;
/* SOURCE tablook.for:661 */
/*<       dt=(ftab(l+xoff+1)-t0)/dy >*/
    dt = static_cast<double>((static_cast<double>(ftab[l + xoff + 1]) - t0)) / dy;
/* SOURCE tablook.for:662 */
/*<       t=t0+h*dt >*/
    t = static_cast<double>(t0) + static_cast<double>(feq_gen_h_d_) * dt;
/* SOURCE tablook.for:663 */
/*<       a=a0+0.5*h*(t+t0) >*/
    *a = static_cast<double>(a0) + static_cast<double>(static_cast<double>(feq_gen_h_d_) * (float).5) * (static_cast<double>(t) + t0);
/* SOURCE tablook.for:665 */
/*<       return >*/
    return 0;
/* SOURCE tablook.for:666 */
/*<       end >*/
} /* lkta_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tablook.for:670 */
/*<       subroutinelktj(adrs,ya,j) >*/
/* Subroutine */ int lktj_(integer *adrs, real *ya, real *j)
{
    /* Initialized data */

    static integer vtype[35] = { 1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,
	    0,1,1,0,0,0,0,0,1,1,0,1,1 };

    /* Format strings */
    static char fmt_2000[] = "(\0020\002,\002*WRN:41* X-SECTION BELOW RANGE \
IN LKTJ\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,f1\
0.3/,1x,\002 TIME           = \002,f10.0,/,1x,\002 DEPTH          = \002,f10\
.2)";
    static char fmt_2010[] = "(\0020\002,\002*WRN:42* X-SECTION ABOVE RANGE \
IN LKTJ\002,/,1x,\002 TABLE ID   = \002,a,/,1x,\002 STATION NUMBER = \002,f1\
0.3/,1x,\002 TIME           = \002,f10.0,/,1x,\002 DEPTH          = \002,f10\
.2)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real a, feq_gen_h_d_;
    integer l;
    real t, y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real a0, j0, t0, y0;
    integer ha, la;
    real hh, dt, dy;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int xstype_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_2000, 0 };


/*     + + + PURPOSE + + + */
/*     Given depth lookup first moment of area in a cross section table. */
/* SOURCE tablook.for:678 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tablook.for:681 */
/*<       integeradrs >*/
/* SOURCE tablook.for:682 */
/*<       realj,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - Address of function table */
/*     YA     - depth argument */
/*     J      - first moment of area about water surface */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tablook.for:690 */
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
/* INCLUDE tablook.for:691 */
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
/* INCLUDE tablook.for:692 */
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
/* INCLUDE tablook.for:693 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE tablook.for:696 */
/*<       integervtype(35) >*/
/* SOURCE tablook.for:697 */
/*<       savevtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tablook.for:700 */
/*<       integerha,l,la,type,xoff >*/
/* SOURCE tablook.for:701 */
/*<       reala,a0,dt,dy,h,hh,j0,t,t0,y,y0 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tablook.for:704 */
/*<       character*16get_tabid >*/
/* SOURCE tablook.for:705 */
/*<       externalget_tabid,xstype >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tablook.for:708 */
/*<       datavtype/1,10*0,1,7*0,0,1,1,0,1,1,4*0,0,1,1,0,1,1/ >*/
/* SOURCE tablook.for:711 */
/*<  2000  >*/
/* L2000: */
/* SOURCE tablook.for:716 */
/*<  2010  >*/
/* L2010: */
/* *********************************************************************** */
/*     HA = HIGH ADDRESS */
/*     LA = LOW ADDRESS */
/*     L = ADDRESS FOUND ON THE LAST CALL TO THIS TABLE */
/* SOURCE tablook.for:726 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE tablook.for:727 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE tablook.for:728 */
/*<       la=adrs+xtioff >*/
    la = *adrs + 32;
/* SOURCE tablook.for:729 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE tablook.for:731 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE tablook.for:732 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE tablook.for:733 */
/*<       if(vtype(type).eq.0)then >*/
    if (vtype[feq_gen_type_d_ - 1] == 0) {
/* SOURCE tablook.for:734 */
/*<       callxstype(lout,vtype,itab(adrs+1)) >*/
	xstype_(&xscom_1.lout, vtype, itab.lease(*adrs + 1).data());
/* SOURCE tablook.for:736 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE tablook.for:737 */
/*<       endif >*/
    }
/* SOURCE tablook.for:739 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/*       CHECK FOR ARGUMENT ABOVE MAX ARG IN THE TABLE */
/* SOURCE tablook.for:741 */
/*<       if(y.gt.ftab(ha))then >*/
	if (y > ftab[ha]) {
/* SOURCE tablook.for:742 */
/*<       write(lout,2010)get_tabid(itab(adrs+1)),ftab(adrs+4),time,y >*/
	    feq_gen_io_d__90.ciunit = xscom_1.lout;
	    s_wsfe(&feq_gen_io_d__90);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tablook.for:744 */
/*<       l=ha-xoff >*/
	    l = ha - xoff;
/* SOURCE tablook.for:745 */
/*<       y=ftab(ha) >*/
	    y = ftab[ha];
/* SOURCE tablook.for:746 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE tablook.for:747 */
/*<       else >*/
	} else {
/* SOURCE tablook.for:748 */
/*<   100 continue >*/
L100:
/* SOURCE tablook.for:749 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	    if (y > ftab[l + xoff]) {
/* SOURCE tablook.for:750 */
/*<       l=l+xoff >*/
		l += xoff;
/* SOURCE tablook.for:751 */
/*<       goto100 >*/
		goto L100;
/* SOURCE tablook.for:752 */
/*<       endif >*/
	    }
/* SOURCE tablook.for:753 */
/*<       endif >*/
	}
/* SOURCE tablook.for:754 */
/*<       else >*/
    } else {
/*       CHECK FOR ARGUMENT BELOW MIN ARG IN THE TABLE */
/* SOURCE tablook.for:756 */
/*<       if(y.lt.ftab(la))then >*/
	if (y < ftab[la]) {
/* SOURCE tablook.for:757 */
/*<       write(lout,2000)get_tabid(itab(adrs+1)),ftab(adrs+4),time,y >*/
	    feq_gen_io_d__91.ciunit = xscom_1.lout;
	    s_wsfe(&feq_gen_io_d__91);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(*adrs + 4).data(), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE tablook.for:759 */
/*<       l=la >*/
	    l = la;
/* SOURCE tablook.for:760 */
/*<       y=ftab(l+xoff) >*/
	    y = ftab[l + xoff];
/* SOURCE tablook.for:761 */
/*<       ya=y >*/
	    *ya = y;
/* SOURCE tablook.for:762 */
/*<       else >*/
	} else {
/* SOURCE tablook.for:763 */
/*<   110 continue >*/
L110:
/* SOURCE tablook.for:764 */
/*<       l=l-xoff >*/
	    l -= xoff;
/* SOURCE tablook.for:765 */
/*<       if(y.lt.ftab(l))goto110 >*/
	    if (y < ftab[l]) {
		goto L110;
	    }
/* SOURCE tablook.for:766 */
/*<       endif >*/
	}
/* SOURCE tablook.for:767 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE tablook.for:774 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
/*     FETCH VALUES FROM FTAB */
/* SOURCE tablook.for:778 */
/*<       y0=ftab(l) >*/
    // Keep the original interval selection, diagnostics and cached row.
    *j = feq::interpolate_scalar_first_moment(y,ftab[l],ftab[l+1],ftab[l+2],ftab[l+5],
        ftab[l+xoff],ftab[l+xoff+1]);
    return 0;
} /* lktj_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
