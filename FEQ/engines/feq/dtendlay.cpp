/* dtendlay.f -- translated by f2c (version 20240504).
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

/* COMMON tamcom_ is declared in common.hpp. */

#define tamcom_1 tamcom_

/* COMMON dtendef_ is declared in common.hpp. */

#define dtendef_1 dtendef_

/* COMMON dtendefc_ is declared in common.hpp. */

#define dtendefc_1 dtendefc_

/* COMMON usintp_ is declared in common.hpp. */

#define usintp_1 usintp_

/* COMMON inbr_ is declared in common.hpp. */

#define inbr_1 inbr_

/* COMMON inen_ is declared in common.hpp. */

#define inen_1 inen_

/* COMMON inenc_ is declared in common.hpp. */

#define inenc_1 inenc_

/* COMMON tsfcom_ is declared in common.hpp. */

#define tsfcom_1 tsfcom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_4200 = 4200;
static integer feq_gen_c_d_7 = 7;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_13 = 13;
static integer feq_gen_c_d_20 = 20;
static integer feq_gen_c_d_10 = 10;
static real c_b226 = (float)0.;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_9 = 9;
static doublereal c_b338 = .512;
static doublereal c_b339 = 1.433;

/*     Contains routines for processing the input for delay and */
/*     detention, as well as computing the description for */
/*     detention ponds. */



/* SOURCE dtendlay.for:8 */
/*<        >*/
/* Subroutine */ int feq_gen_copy_trib_description_block_d_(integer *stdout, integer *
	feq_gen_last_ndta_pnt_d_, integer *feq_gen_last_dta_pnt_d_)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:327* Space for tributary area descr\
iption blocks\002,\002 exhausted.\002)";
    static char fmt_52[] = "(/,\002 *ERR:328* Space for tributary area value\
s exhausted.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_ioff_max_d_, feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__2 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__4 = { 0, 0, 0, fmt_52, 0 };


/*     Make a copy of the tributary-area description block */
/*     at LAST_NDTA_PNT and allocate space for the new */
/*     tributary areas.  Return the address of the new block */
/*     in LAST_DTA_PNT. */
/* SOURCE dtendlay.for:17 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:18 */
/*<       integerstdout,last_ndta_pnt,last_dta_pnt >*/
/* INCLUDE dtendlay.for:20 */
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
/* INCLUDE dtendlay.for:21 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/* SOURCE dtendlay.for:25 */
/*<       integeri,ioff_max >*/
/*     *************************Formats********************************** */
/* SOURCE dtendlay.for:28 */
/*<    50  >*/
/* SOURCE dtendlay.for:30 */
/*<    52 format(/,' *ERR:328* Space for tributary area values exhausted.') >*/
/* *********************************************************************** */
/* SOURCE dtendlay.for:32 */
/*<       if(tam_itab(last_ndta_pnt+1).eq.1)then >*/
/* L50: */
/* L52: */
    if (tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_ndta_pnt_d_] == 1) {
/* SOURCE dtendlay.for:33 */
/*<       ioff_max=9 >*/
	feq_gen_ioff_max_d_ = 9;
/* SOURCE dtendlay.for:34 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:35 */
/*<       ioff_max=8 >*/
	feq_gen_ioff_max_d_ = 8;
/* SOURCE dtendlay.for:36 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:37 */
/*<       last_dta_pnt=tam_ipnt >*/
    *feq_gen_last_dta_pnt_d_ = tamcom_1.feq_gen_tam_ipnt_d_;
/* SOURCE dtendlay.for:38 */
/*<       if(tam_ipnt+ioff_max.gt.tam_mxni)then >*/
    if (tamcom_1.feq_gen_tam_ipnt_d_ + feq_gen_ioff_max_d_ > 102000) {
/* SOURCE dtendlay.for:39 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__2.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__2);
	e_wsfe();
/* SOURCE dtendlay.for:40 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:41 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:42 */
/*<       do100i=0,ioff_max >*/
    feq_gen_i_d_1 = feq_gen_ioff_max_d_;
    for (feq_gen_i_d_ = 0; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dtendlay.for:43 */
/*<       tam_itab(last_dta_pnt+i)=tam_itab(last_ndta_pnt+i) >*/
	tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_dta_pnt_d_ + feq_gen_i_d_ - 1] = tamcom_1.feq_gen_tam_itab_d_[*
		feq_gen_last_ndta_pnt_d_ + feq_gen_i_d_ - 1];
/* SOURCE dtendlay.for:44 */
/*<   100 continue >*/
/* L100: */
    }
/*     Count the new block. */
/* SOURCE dtendlay.for:46 */
/*<       tunit_knt=tunit_knt+1 >*/
    ++tamcom_1.feq_gen_tunit_knt_d_;
/*     Update the pointer for space in TAM_ITAB */
/* SOURCE dtendlay.for:48 */
/*<       tam_ipnt=tam_ipnt+ioff_max+1 >*/
    tamcom_1.feq_gen_tam_ipnt_d_ = tamcom_1.feq_gen_tam_ipnt_d_ + feq_gen_ioff_max_d_ + 1;
/* SOURCE dtendlay.for:49 */
/*<       if(tunit_knt.gt.mxr_triba)then >*/
    if (tamcom_1.feq_gen_tunit_knt_d_ > 8400) {
/* SOURCE dtendlay.for:50 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__4.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__4);
	e_wsfe();
/* SOURCE dtendlay.for:51 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:52 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:53 */
/*<       tam_itab(last_dta_pnt+3)=tunit_knt >*/
    tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_dta_pnt_d_ + 2] = tamcom_1.feq_gen_tunit_knt_d_;
/* SOURCE dtendlay.for:56 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:57 */
/*<       end >*/
} /* copy_trib_description_block__ */




/* SOURCE dtendlay.for:61 */
/*<       subroutineset_dten_def(grav) >*/
/* Subroutine */ int feq_gen_set_dten_def_d_(real *grav)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Sets the default detention values. */
/* SOURCE dtendlay.for:65 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:66 */
/*<       realgrav >*/
/* INCLUDE dtendlay.for:68 */
/*     Common block for default detention basin values. */
/* SOURCE dtendef.cmn:3 */
/*<        >*/
/* SOURCE dtendef.cmn:6 */
/*<        >*/
/* SOURCE dtendef.cmn:9 */
/*<       character*16def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/* SOURCE dtendef.cmn:12 */
/*<        >*/
/* SOURCE dtendef.cmn:17 */
/*<       common/dtendefc/def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/* *********************************************************************** */
/* SOURCE dtendlay.for:70 */
/*<       def_dten_lui=1 >*/
    dtendef_1.feq_gen_def_dten_lui_d_ = 1;
/* SOURCE dtendlay.for:71 */
/*<       def_dten_orif_tabid='10001' >*/
    s_copy(dtendefc_1.feq_gen_def_dten_orif_tabid_d_, const_cast<char*>("10001"), (ftnlen)16, (ftnlen)5);
/* SOURCE dtendlay.for:72 */
/*<       def_dten_unit_area_vol_tabid='10000' >*/
    s_copy(dtendefc_1.feq_gen_def_dten_unit_area_vol_tabid_d_, const_cast<char*>("10000"), (ftnlen)16, (
	    ftnlen)5);
/*     Set the internal table numbers to 0. */
/*     They are set if detention is simulated. */
/* SOURCE dtendlay.for:75 */
/*<       def_dten_orif_tab_num=0 >*/
    dtendef_1.feq_gen_def_dten_orif_tab_num_d_ = 0;
/* SOURCE dtendlay.for:76 */
/*<       def_dten_unit_area_vol_tab_num=0 >*/
    dtendef_1.feq_gen_def_dten_unit_area_vol_tab_num_d_ = 0;
/* SOURCE dtendlay.for:78 */
/*<       def_dten_wc=0.9 >*/
    dtendef_1.feq_gen_def_dten_wc_d_ = (float).9;
/* SOURCE dtendlay.for:79 */
/*<       def_dten_wz=50.0 >*/
    dtendef_1.feq_gen_def_dten_wz_d_ = (float)50.;
/* SOURCE dtendlay.for:80 */
/*<       def_dten_bz=4.0 >*/
    dtendef_1.feq_gen_def_dten_bz_d_ = (float)4.;
/* SOURCE dtendlay.for:81 */
/*<       def_dten_orfcd=0.6 >*/
    dtendef_1.feq_gen_def_dten_orfcd_d_ = (float).6;
/* SOURCE dtendlay.for:82 */
/*<       if(grav.gt.16.0)then >*/
    if (*grav > (float)16.) {
/*       US customary units are being used. */
/* SOURCE dtendlay.for:84 */
/*<       def_dten_yd=5.0 >*/
	dtendef_1.feq_gen_def_dten_yd_d_ = (float)5.;
/*       Unit-area flow is in ft^3/s/ft^2= ft/s */
/* SOURCE dtendlay.for:86 */
/*<       def_dten_uaq=0.1/43560. >*/
	dtendef_1.feq_gen_def_dten_uaq_d_ = (float)2.2956841138659321e-6;
/*       Drainage area is in square feet */
/* SOURCE dtendlay.for:88 */
/*<       def_dten_avda=40.0*43560. >*/
	dtendef_1.feq_gen_def_dten_avda_d_ = (float)1742400.;
/* SOURCE dtendlay.for:89 */
/*<       else >*/
    } else {
/*       Metric set of units being used. */
/* SOURCE dtendlay.for:91 */
/*<       def_dten_yd=1.524 >*/
	dtendef_1.feq_gen_def_dten_yd_d_ = (float)1.524;
/*       Unit-area flow is in m^3/s/m^2= m/s */
/* SOURCE dtendlay.for:93 */
/*<       def_dten_uaq=0.69972/1.e6 >*/
	dtendef_1.feq_gen_def_dten_uaq_d_ = (float)6.9971999999999997e-7;
/*       Drainage area is in square meters */
/* SOURCE dtendlay.for:95 */
/*<       def_dten_avda=.161874*1.e6 >*/
	dtendef_1.feq_gen_def_dten_avda_d_ = (float)161874.;
/* SOURCE dtendlay.for:96 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:98 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:99 */
/*<       end >*/
} /* set_dten_def__ */




/* SOURCE dtendlay.for:103 */
/*<       subroutineuse_dten_default(row_pnt) >*/
/* Subroutine */ int feq_gen_use_dten_default_d_(integer *feq_gen_row_pnt_d_)
{
/*     Place the default values for a detention reservoir in the */
/*     row given by ROW_PNT */
/* SOURCE dtendlay.for:108 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:109 */
/*<       integerrow_pnt >*/
/* INCLUDE dtendlay.for:110 */
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
/* INCLUDE dtendlay.for:111 */
/*     Common block for default detention basin values. */
/* SOURCE dtendef.cmn:3 */
/*<        >*/
/* SOURCE dtendef.cmn:6 */
/*<        >*/
/* SOURCE dtendef.cmn:9 */
/*<       character*16def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/* SOURCE dtendef.cmn:12 */
/*<        >*/
/* SOURCE dtendef.cmn:17 */
/*<       common/dtendefc/def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/* INCLUDE dtendlay.for:112 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/* *********************************************************************** */
/* SOURCE dtendlay.for:114 */
/*<       dten_yd(row_pnt)=def_dten_yd >*/
    tamcom_1.feq_gen_dten_yd_d_[*feq_gen_row_pnt_d_ - 1] = dtendef_1.feq_gen_def_dten_yd_d_;
/* SOURCE dtendlay.for:115 */
/*<       dten_bz(row_pnt)=def_dten_bz >*/
    tamcom_1.feq_gen_dten_bz_d_[*feq_gen_row_pnt_d_ - 1] = dtendef_1.feq_gen_def_dten_bz_d_;
/* SOURCE dtendlay.for:116 */
/*<       dten_wz(row_pnt)=def_dten_wz >*/
    tamcom_1.feq_gen_dten_wz_d_[*feq_gen_row_pnt_d_ - 1] = dtendef_1.feq_gen_def_dten_wz_d_;
/* SOURCE dtendlay.for:117 */
/*<       dten_wc(row_pnt)=def_dten_wc >*/
    tamcom_1.feq_gen_dten_wc_d_[*feq_gen_row_pnt_d_ - 1] = dtendef_1.feq_gen_def_dten_wc_d_;
/* SOURCE dtendlay.for:118 */
/*<       dten_uaq(row_pnt)=def_dten_uaq >*/
    tamcom_1.feq_gen_dten_uaq_d_[*feq_gen_row_pnt_d_ - 1] = dtendef_1.feq_gen_def_dten_uaq_d_;
/* SOURCE dtendlay.for:119 */
/*<       dten_orfcd(row_pnt)=def_dten_orfcd >*/
    tamcom_1.feq_gen_dten_orfcd_d_[*feq_gen_row_pnt_d_ - 1] = dtendef_1.feq_gen_def_dten_orfcd_d_;
/* SOURCE dtendlay.for:120 */
/*<       dten_avda(row_pnt)=def_dten_avda >*/
    tamcom_1.feq_gen_dten_avda_d_[*feq_gen_row_pnt_d_ - 1] = dtendef_1.feq_gen_def_dten_avda_d_;
/* SOURCE dtendlay.for:121 */
/*<       dten_uadv_tab(row_pnt)=def_dten_unit_area_vol_tab_num >*/
    tamcom_1.feq_gen_dten_uadv_tab_d_[*feq_gen_row_pnt_d_ - 1] = 
	    dtendef_1.feq_gen_def_dten_unit_area_vol_tab_num_d_;
/* SOURCE dtendlay.for:122 */
/*<       dten_orf_tab(row_pnt)=def_dten_orif_tab_num >*/
    tamcom_1.feq_gen_dten_orf_tab_d_[*feq_gen_row_pnt_d_ - 1] = 
	    dtendef_1.feq_gen_def_dten_orif_tab_num_d_;
/* SOURCE dtendlay.for:123 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:124 */
/*<       end >*/
} /* use_dten_default__ */




/* SOURCE dtendlay.for:130 */
/*<        >*/
/* Subroutine */ int feq_gen_set_trib_areas_d_(integer *stdout, char *feq_storage_cval, integer *
	ngage, integer *gend, integer *gstart, integer *feq_gen_max_nval_d_, real *
	feq_gen_con_fac_d_, integer *nval, integer *feq_gen_back_pnt_d_, real *feq_storage_rval, integer *
	feq_gen_last_ndta_pnt_d_, integer *feq_gen_last_dta_pnt_d_, real *feq_storage_triba, integer *eflag,
	 ftnlen cval_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:329* Detention given with DTEN befo\
re tributary\002,\002 area is given.\002)";
    static char fmt_52[] = "(/,\002 *ERR:330* Detention fraction=\002,f7.4\
,\002 is <= 0 or > 1.\002)";
    static char fmt_54[] = "(/,\002 *ERR:331* Maximum number of detention re\
servoirs=\002,i5,\002 is too small.\002)";
    static char fmt_56[] = "(/,\002 *BUG:XXX* LAST_DTA_PNT=\002,i5,\002 In S\
ET_TRIB_AREAS when\002,\002 it should be 0!\002)";
    static char fmt_58[] = "(/,\002 *ERR:332* Found \002,i3,\002 values afte\
r DTEN.  \002,\002Expected \002,i3,\002 for gage number \002,i3,\002.\002)";
    static char fmt_60[] = "(/,\002 *ERR:333* Inconsistent signs for areas s\
ubject to\002,\002 detention.\002)";
    static char fmt_62[] = "(/,\002 *ERR:334* No detention area given on DTE\
N line.\002)";
    static char fmt_64[] = "(/,\002 *BUG:XXX* BACK_PNT=\002,i10,\002 does no\
t = LAST_NDTA_PNT=\002,i10)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen), s_cmp(char *, char *, ftnlen, 
	    ftnlen);

    /* Local variables */
    real fraction;
    extern /* Subroutine */ int feq_gen_use_dten_default_d_(integer *);
    integer feq_gen_i_d_, feq_gen_triba_row_d_, feq_gen_gage_nluse_d_, gage;
    real rmin, rmax;
    extern /* Subroutine */ int feq_gen_copy_trib_description_block_d_(integer *, 
	    integer *, integer *);
    integer feq_gen_last_ndta_row_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__21 = { 0, 0, 0, fmt_54, 0 };


/*     Dechipher the user instructions and set the tributary */
/*     area values accordingly. */
/* SOURCE dtendlay.for:138 */
/*<       implicitnone >*/
/* INCLUDE dtendlay.for:139 */
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
/* SOURCE dtendlay.for:141 */
/*<        >*/
/* SOURCE dtendlay.for:145 */
/*<       realcon_fac,rval(max_nval),triba(mxr_triba,mxn_lu_g) >*/
/* SOURCE dtendlay.for:147 */
/*<       charactercval(nval)*256 >*/
/* INCLUDE dtendlay.for:149 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/* SOURCE dtendlay.for:153 */
/*<       integerlast_ndta_row,gage,gage_nluse,i,triba_row >*/
/* SOURCE dtendlay.for:156 */
/*<       realfraction,rmax,rmin >*/
/*     *****************************Formats****************************** */
/* SOURCE dtendlay.for:158 */
/*<    50  >*/
/* SOURCE dtendlay.for:160 */
/*<    52 format(/,' *ERR:330* Detention fraction=',f7.4,' is <= 0 or > 1.') >*/
/* SOURCE dtendlay.for:162 */
/*<    54  >*/
/* SOURCE dtendlay.for:164 */
/*<    56  >*/
/* SOURCE dtendlay.for:166 */
/*<    58  >*/
/* SOURCE dtendlay.for:168 */
/*<    60  >*/
/* SOURCE dtendlay.for:170 */
/*<    62 format(/,' *ERR:334* No detention area given on DTEN line.') >*/
/* SOURCE dtendlay.for:171 */
/*<    64  >*/
/* *********************************************************************** */
/*     Check for proper sequence of input.  We must have some trib area */
/*     in TRIBA before we can process a DTEN line of input. */
/*     The LAST_NDTA_PNT should be > 0. */
/* SOURCE dtendlay.for:177 */
/*<       if(last_ndta_pnt.gt.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> rval(feq_storage_rval, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, 256);

    feq::IndexedPointer<real> triba(feq_storage_triba, 8401);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
    if (*feq_gen_last_ndta_pnt_d_ > 0) {
/*       Get the row of TRIBA that contains the last tributrary area */
/*       given by the user. */
/* SOURCE dtendlay.for:180 */
/*<       last_ndta_row=tam_itab(last_ndta_pnt+3) >*/
	feq_gen_last_ndta_row_d_ = tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_ndta_pnt_d_ + 2];
/* SOURCE dtendlay.for:181 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:182 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__6.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__6);
	e_wsfe();
/* SOURCE dtendlay.for:183 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:184 */
/*<       endif >*/
    }
/*     Make sure pointers are not confused */
/* SOURCE dtendlay.for:188 */
/*<       if(last_dta_pnt.ne.0)then >*/
    if (*feq_gen_last_dta_pnt_d_ != 0) {
/*       Bug: LAST_DTA_PNT should be 0! */
/* SOURCE dtendlay.for:190 */
/*<       write(stdout,56)last_dta_pnt >*/
	feq_gen_io_d__7.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__7);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_last_dta_pnt_d_), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE dtendlay.for:191 */
/*<       stop'Abnormal stop. Bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE dtendlay.for:192 */
/*<       endif >*/
    }
/*     Compute the number of land uses for this gage. */
/* SOURCE dtendlay.for:195 */
/*<       gage=tam_itab(last_ndta_pnt+4) >*/
    gage = tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_ndta_pnt_d_ + 3];
/* SOURCE dtendlay.for:196 */
/*<       gage_nluse=gend(gage)-gstart(gage)+1 >*/
    feq_gen_gage_nluse_d_ = gend[gage] - gstart[gage] + 1;
/*      WRITE(STDOUT,*) ' SET_TRIB_AREA: GAGE=',GAGE, */
/*     A   ' GEND(GAGE)=',GEND(GAGE),' GSTART(GAGE)=',GSTART(GAGE) */
/*     Now dechipher the user input.  There are three valid patterns: */
/*     1. DTEN followed by a series of REAL values that are >= 0. */
/*     2. DTEN followed by a series of REAL values that are <= 0. */
/*     3. DTEN followed by: FRACTION= a positive real number <= 1.0 */
/*     We already know that the first value is DTEN because that is */
/*     how we got to this routine. */
/* SOURCE dtendlay.for:206 */
/*<       if(cval(2).eq.'FRACTION')then >*/
    if (s_cmp(cval + 512, const_cast<char*>("FRACTION"), (ftnlen)256, (ftnlen)8) == 0) {
/*       Pattern 3 here.  The response value is in RVAL(3). */
/* SOURCE dtendlay.for:208 */
/*<       fraction=rval(3) >*/
	fraction = rval[3];
/*        WRITE(STDOUT,*) ' SET_TRIB_AREAS: FRACTION=',FRACTION */
/* SOURCE dtendlay.for:210 */
/*<       if(fraction.le.0.0.or.fraction.gt.1.0)then >*/
	if (fraction <= (float)0. || fraction > (float)1.) {
/*         Invalid value given for fraction. */
/* SOURCE dtendlay.for:212 */
/*<       write(stdout,52)fraction >*/
	    feq_gen_io_d__11.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__11);
	    do_fio(&feq_gen_c_d_1, (char *)&fraction, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE dtendlay.for:213 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE dtendlay.for:214 */
/*<       fraction=0.5 >*/
	    fraction = (float).5;
/* SOURCE dtendlay.for:215 */
/*<       endif >*/
	}
/*       If all the area is subject to detention then we need */
/*       not add a new tributary area unit. */
/* SOURCE dtendlay.for:218 */
/*<       if(abs(fraction-1.0).le.1.0e-5)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(fraction) - (float)1., dabs(feq_gen_r_d_1)) <= (float)1e-5) {
/*         Treat FRACTION as 1.0.  Set it to exactly 1.0 so */
/*         that this case will be distinguished from the case */
/*         with FRACTION < 1.0 below. */
/* SOURCE dtendlay.for:222 */
/*<       fraction=1.0 >*/
	    fraction = (float)1.;
/*         The area is already in current tributary area description block. */
/*         Switch the last trib area pointer. */
/* SOURCE dtendlay.for:225 */
/*<       last_dta_pnt=last_ndta_pnt >*/
	    *feq_gen_last_dta_pnt_d_ = *feq_gen_last_ndta_pnt_d_;
/* SOURCE dtendlay.for:226 */
/*<       last_ndta_pnt=0 >*/
	    *feq_gen_last_ndta_pnt_d_ = 0;
/*         Assign a location and set the parameters for this */
/*         detention reservoir.  Default values used here. */
/* SOURCE dtendlay.for:229 */
/*<       dten_knt=dten_knt+1 >*/
	    ++tamcom_1.feq_gen_dten_knt_d_;
/* SOURCE dtendlay.for:230 */
/*<       if(dten_knt.gt.mxn_dten)then >*/
	    if (tamcom_1.feq_gen_dten_knt_d_ > 4200) {
/* SOURCE dtendlay.for:231 */
/*<       write(stdout,54)mxn_dten >*/
		feq_gen_io_d__12.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__12);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_4200, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE dtendlay.for:232 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:233 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:234 */
/*<       tam_itab(last_dta_pnt+5)=dten_knt >*/
	    tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_dta_pnt_d_ + 4] = tamcom_1.feq_gen_dten_knt_d_;
/* SOURCE dtendlay.for:235 */
/*<       calluse_dten_default(dten_knt) >*/
	    feq_gen_use_dten_default_d_(&tamcom_1.feq_gen_dten_knt_d_);
/* SOURCE dtendlay.for:236 */
/*<       else >*/
	} else {
/*         Compute the value of RVAL to make this option */
/*         look like the DTEN line with negative areas. */
/* SOURCE dtendlay.for:239 */
/*<       nval=gage_nluse+1 >*/
	    *nval = feq_gen_gage_nluse_d_ + 1;
/*          WRITE(STDOUT,*)' SET_TRIB_AREA: GAGE_NLUSE=',GAGE_NLUSE, */
/*     A       ' LAST_NDTA_ROW=',LAST_NDTA_ROW, */
/*     B       ' LAST_NDTA_PNT=',LAST_NDTA_PNT, */
/*     C       ' NVAL=',NVAL */
/* SOURCE dtendlay.for:244 */
/*<       do98i=2,nval >*/
	    feq_gen_i_d_1 = *nval;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dtendlay.for:245 */
/*<       rval(i)=-fraction*triba(last_ndta_row,i-1) >*/
		rval[feq_gen_i_d_] = static_cast<double>(-fraction) * triba[feq_gen_last_ndta_row_d_ + (feq_gen_i_d_ - 1) * 
			8400];
/* SOURCE dtendlay.for:246 */
/*<    98 continue >*/
/* L98: */
	    }
/* SOURCE dtendlay.for:247 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:248 */
/*<       else >*/
    } else {
/*       Force a value on FRACTION < 1.0 so that patterns 1 and 2 */
/*       and the DTEN  FRACTION < 1.0 patterns are all done */
/*       the same way. */
/* SOURCE dtendlay.for:252 */
/*<       fraction=0.1 >*/
	fraction = (float).1;
/*       Also convert the user trib area units to the internal units. */
/* SOURCE dtendlay.for:254 */
/*<       do99i=2,nval >*/
	feq_gen_i_d_1 = *nval;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dtendlay.for:255 */
/*<       rval(i)=con_fac*rval(i) >*/
	    rval[feq_gen_i_d_] = static_cast<double>(*feq_gen_con_fac_d_) * rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:256 */
/*<    99 continue >*/
/* L99: */
	}
/* SOURCE dtendlay.for:257 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:258 */
/*<       if(fraction.lt.1.0)then >*/
    if (fraction < (float)1.) {
/*       Patterns 1, 2, and part of 3.  Must create a new tributary */
/*       area description block.  Copy the old block to */
/*       the new and allocate space for the new tributary */
/*       areas.   The forward-linked series of pointers for */
/*       trib area control blocks must be maintained.  At this */
/*       point BACK_PNT should be the same as LAST_NDTA_PNT */
/*       because that is the last trib area we have seen. */
/*       When we allocate a new trib-area control block its */
/*       address must be placed in the forwared pointer location */
/*       in the LAST_NDTA_PNT block, and BACK_PNT must be */
/*       reset to the newly allocated address. */
/* SOURCE dtendlay.for:270 */
/*<       if(back_pnt.ne.last_ndta_pnt)then >*/
	if (*feq_gen_back_pnt_d_ != *feq_gen_last_ndta_pnt_d_) {
/* SOURCE dtendlay.for:271 */
/*<       write(stdout,64)back_pnt,last_ndta_pnt >*/
	    feq_gen_io_d__14.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__14);
	    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_back_pnt_d_), (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_last_ndta_pnt_d_), (ftnlen)sizeof(integer)
		    );
	    e_wsfe();
/* SOURCE dtendlay.for:272 */
/*<       stop'Abnormal stop. Bug found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE dtendlay.for:273 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' Calling COPY_TRIB_DESCRIPTION_BLOCK' */
/*        WRITE(STDOUT,*) ' LAST_NDTA_PNT=',LAST_NDTA_PNT */
/* SOURCE dtendlay.for:276 */
/*<       callcopy_trib_description_block(stdout,last_ndta_pnt,last_dta_pnt) >*/
	feq_gen_copy_trib_description_block_d_(stdout, feq_gen_last_ndta_pnt_d_, feq_gen_last_dta_pnt_d_)
		;
/*        WRITE(STDOUT,*) ' Return from COPY_T...: TUNIT_KNT=', */
/*     A              TUNIT_KNT,' LAST_DTA_PNT=',LAST_DTA_PNT */
/*       Adjust the pointer chain for trib-area control blocks. */
/*       Point to the just allocated block for the area subject to */
/*       detention. */
/* SOURCE dtendlay.for:285 */
/*<       tam_itab(last_ndta_pnt+2)=last_dta_pnt >*/
	tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_ndta_pnt_d_ + 1] = *feq_gen_last_dta_pnt_d_;
/*       Update the back pointer so that we can make the connection */
/*       the next trib area unit that will be input from the user. */
/* SOURCE dtendlay.for:288 */
/*<       back_pnt=last_dta_pnt >*/
	*feq_gen_back_pnt_d_ = *feq_gen_last_dta_pnt_d_;
/*       Set the forward pointer in the just allocated trib area block */
/*       to the end of list signal in case this is the last block in */
/*       the chain of blocks. */
/* SOURCE dtendlay.for:292 */
/*<       tam_itab(last_dta_pnt+2)=0 >*/
	tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_dta_pnt_d_ + 1] = 0;
/*       Now dechipher the user input.  Check to make sure that */
/*       the correct number of values have been given. */
/* SOURCE dtendlay.for:296 */
/*<       if(nval-1.ne.gage_nluse)then >*/
	if (*nval - 1 != feq_gen_gage_nluse_d_) {
/* SOURCE dtendlay.for:297 */
/*<       write(stdout,58)nval-1,gage_nluse,gage >*/
	    feq_gen_io_d__15.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__15);
	    feq_gen_i_d_1 = *nval - 1;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_gage_nluse_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&gage, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE dtendlay.for:298 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:299 */
/*<       endif >*/
	}
/*       Check that the signs of the values are consistent. */
/* SOURCE dtendlay.for:301 */
/*<       rmin=1.e30 >*/
	rmin = (float)1e30;
/* SOURCE dtendlay.for:302 */
/*<       rmax=-1.e30 >*/
	rmax = (float)-1e30;
/* SOURCE dtendlay.for:303 */
/*<       do100i=2,nval >*/
	feq_gen_i_d_1 = *nval;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dtendlay.for:304 */
/*<       if(rval(i).gt.rmax)rmax=rval(i) >*/
	    if (rval[feq_gen_i_d_] > rmax) {
		rmax = rval[feq_gen_i_d_];
	    }
/* SOURCE dtendlay.for:305 */
/*<       if(rval(i).lt.rmin)rmin=rval(i) >*/
	    if (rval[feq_gen_i_d_] < rmin) {
		rmin = rval[feq_gen_i_d_];
	    }
/* SOURCE dtendlay.for:306 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE dtendlay.for:307 */
/*<       if(rmin.ne.0.0.and.rmax.ne.0.0)then >*/
	if (rmin != (float)0. && rmax != (float)0.) {
/*         Both are non-zero. */
/* SOURCE dtendlay.for:309 */
/*<       if(rmin*rmax.lt.0.0)then >*/
	    if (static_cast<double>(rmin) * rmax < (float)0.) {
/*           Inconsistent signs */
/* SOURCE dtendlay.for:311 */
/*<       write(stdout,60) >*/
		feq_gen_io_d__18.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__18);
		e_wsfe();
/* SOURCE dtendlay.for:312 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:313 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:314 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:315 */
/*<       if(rmin.eq.0.0.and.rmax.eq.0.0)then >*/
	    if (rmin == (float)0. && rmax == (float)0.) {
/*           No detention area given on DTEN line */
/* SOURCE dtendlay.for:317 */
/*<       write(stdout,62) >*/
		feq_gen_io_d__19.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__19);
		e_wsfe();
/* SOURCE dtendlay.for:318 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:319 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:320 */
/*<       endif >*/
	}
/*       Get the row in TRIBA allocated to the area */
/*       subject to detention. */
/* SOURCE dtendlay.for:323 */
/*<       triba_row=tam_itab(last_dta_pnt+3) >*/
	feq_gen_triba_row_d_ = tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_dta_pnt_d_ + 2];
/* SOURCE dtendlay.for:324 */
/*<       if(rmax.gt.0.0)then >*/
	if (rmax > (float)0.) {
/*         User has given the non-detention area in */
/*         the trib area input and the detention area */
/*         on the DTEN line. Store the values in the */
/*         TRIBA slot for the detention area. */
/* SOURCE dtendlay.for:329 */
/*<       do110i=2,nval >*/
	    feq_gen_i_d_1 = *nval;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dtendlay.for:330 */
/*<       triba(triba_row,i-1)=rval(i) >*/
		triba[feq_gen_triba_row_d_ + (feq_gen_i_d_ - 1) * 8400] = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:331 */
/*<   110 continue >*/
/* L110: */
	    }
/* SOURCE dtendlay.for:332 */
/*<       else >*/
	} else {
/*         User has given the total trib area in the trib */
/*         area input and the negative of the detention area on the */
/*         DTEN line.  Add the values in RVAL to the */
/*         non-detention areas and then place the */
/*         absolute values into the detention area. */
/* SOURCE dtendlay.for:338 */
/*<       do120i=2,nval >*/
	    feq_gen_i_d_1 = *nval;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dtendlay.for:339 */
/*<       triba(last_ndta_row,i-1)=triba(last_ndta_row,i-1)+rval(i) >*/
		triba[feq_gen_last_ndta_row_d_ + (feq_gen_i_d_ - 1) * 8400] += static_cast<double>(rval[feq_gen_i_d_]);
/* SOURCE dtendlay.for:341 */
/*<       triba(triba_row,i-1)=abs(rval(i)) >*/
		triba[feq_gen_triba_row_d_ + (feq_gen_i_d_ - 1) * 8400] = (feq_gen_r_d_1 = rval[feq_gen_i_d_], 
			dabs(feq_gen_r_d_1));
/* SOURCE dtendlay.for:342 */
/*<   120 continue >*/
/* L120: */
	    }
/* SOURCE dtendlay.for:343 */
/*<       endif >*/
	}
/*       Establish the detention parameters */
/* SOURCE dtendlay.for:345 */
/*<       dten_knt=dten_knt+1 >*/
	++tamcom_1.feq_gen_dten_knt_d_;
/* SOURCE dtendlay.for:346 */
/*<       if(dten_knt.gt.mxn_dten)then >*/
	if (tamcom_1.feq_gen_dten_knt_d_ > 4200) {
/* SOURCE dtendlay.for:347 */
/*<       write(stdout,54)mxn_dten >*/
	    feq_gen_io_d__21.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__21);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_4200, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE dtendlay.for:348 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:349 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:350 */
/*<       tam_itab(last_dta_pnt+5)=dten_knt >*/
	tamcom_1.feq_gen_tam_itab_d_[*feq_gen_last_dta_pnt_d_ + 4] = tamcom_1.feq_gen_dten_knt_d_;
/* SOURCE dtendlay.for:351 */
/*<       calluse_dten_default(dten_knt) >*/
	feq_gen_use_dten_default_d_(&tamcom_1.feq_gen_dten_knt_d_);
/* SOURCE dtendlay.for:352 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:353 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:354 */
/*<       end >*/
} /* set_trib_areas__ */




/* SOURCE dtendlay.for:358 */
/*<       subroutineallocate_dlay_space(stdout,ta_block_pnt,dlay_pnt) >*/
/* Subroutine */ int feq_gen_allocate_dlay_space_d_(integer *stdout, integer *
	feq_gen_ta_block_pnt_d_, integer *feq_gen_dlay_pnt_d_)
{
    /* Format strings */
    static char fmt_62[] = "(/,\002 *ERR:335* Delay values set more than onc\
e for a\002,\002 tributary area unit.\002)";
    static char fmt_64[] = "(/,\002 *ERR:336* Maximum number of delay reserv\
oirs=\002,i5,\002 is too small.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_64, 0 };


/*     Allocate space for a delay specification for the trib */
/*     area block given by TA_BLOCK_PNT, and return the */
/*     pointer to the space, DLAY_PNT. */
/* SOURCE dtendlay.for:365 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:366 */
/*<       integerta_block_pnt,dlay_pnt,stdout >*/
/* INCLUDE dtendlay.for:368 */
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
/* INCLUDE dtendlay.for:369 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     *********************************Formats************************** */
/* SOURCE dtendlay.for:371 */
/*<    62  >*/
/* SOURCE dtendlay.for:373 */
/*<    64  >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' ALLOCATE_DLAY_SPACE: TA_BLOCK_PNT=', */
/*     A                TA_BLOCK_PNT */
/* SOURCE dtendlay.for:380 */
/*<       if(ta_block_pnt.gt.0)then >*/
/* L62: */
/* L64: */
    if (*feq_gen_ta_block_pnt_d_ > 0) {
/*       Check for duplicate specifications. */
/* SOURCE dtendlay.for:382 */
/*<       if(tam_itab(ta_block_pnt+6).ne.0)then >*/
	if (tamcom_1.feq_gen_tam_itab_d_[*feq_gen_ta_block_pnt_d_ + 5] != 0) {
/* SOURCE dtendlay.for:383 */
/*<       write(stdout,62) >*/
	    feq_gen_io_d__22.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__22);
	    e_wsfe();
/* SOURCE dtendlay.for:384 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:385 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:386 */
/*<       dlay_knt=dlay_knt+1 >*/
	++tamcom_1.feq_gen_dlay_knt_d_;
/* SOURCE dtendlay.for:387 */
/*<       if(dlay_knt.gt.mxn_dlay)then >*/
	if (tamcom_1.feq_gen_dlay_knt_d_ > 4200) {
/* SOURCE dtendlay.for:388 */
/*<       write(stdout,64)mxn_dlay >*/
	    feq_gen_io_d__23.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__23);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_4200, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE dtendlay.for:389 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:390 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:391 */
/*<       dlay_pnt=dlay_knt >*/
	*feq_gen_dlay_pnt_d_ = tamcom_1.feq_gen_dlay_knt_d_;
/* SOURCE dtendlay.for:392 */
/*<       tam_itab(ta_block_pnt+6)=dlay_pnt >*/
	tamcom_1.feq_gen_tam_itab_d_[*feq_gen_ta_block_pnt_d_ + 5] = *feq_gen_dlay_pnt_d_;
/* SOURCE dtendlay.for:393 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:394 */
/*<       dlay_pnt=0 >*/
	*feq_gen_dlay_pnt_d_ = 0;
/* SOURCE dtendlay.for:395 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:396 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:397 */
/*<       end >*/
} /* allocate_dlay_space__ */

/*     *********** */
/*     *         * */
/*     * SET_DLAY_PARAMETERS */
/*     *         * */
/*     *********** */
/* SOURCE dtendlay.for:406 */
/*<        >*/
/* Subroutine */ int feq_gen_set_dlay_parameters_d_(integer *stdout, char *which, 
	integer *feq_gen_item_knt_d_, integer *feq_storage_clen, integer *feq_storage_terml, integer *feq_storage_termcls, 
	integer *feq_gen_feq_storage_item_type_d_, char *feq_storage_cval, char *feq_storage_term, integer *feq_storage_ival, real *
	feq_storage_rval, doublereal *feq_storage_dpval, integer *feq_gen_last_ndta_pnt_d_, integer *
	feq_gen_last_dta_pnt_d_, integer *eflag, ftnlen which_len, ftnlen cval_len, 
	ftnlen term_len)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*7+1] = "NLR             K               KE\
Q             DLAY            DELAY           DLAY_DTA        DLAY_NDTA     \
  ";
    static integer feq_gen_symbol_value_d_[7] = { 1,2,3,4,4,4,4 };
    static integer feq_gen_response_type_d_[7] = { 1,2,4,0,0,0,0 };
    static integer feq_gen_convert_rule_d_[7] = { 0,1,0,0,0,0,0 };
    static char feq_gen_eq_name_d_[16*2+1] = "PURDUE          Purdue          ";
    static real feq_gen_eq_id_d_[2] = { (float)-1.,(float)-1. };

    /* Format strings */
    static char fmt_52[] = "(/,\002 *BUG:XXX* Invalid index=\002,i5,\002 for\
 name=\002,a,\002 in\002,\002 subroutine SET_DLAY_PARAMETERS.\002)";
    static char fmt_54[] = "(/,\002 *ERR:337* Name=\002,a8,\002 is unknown i\
n a delay\002,\002 description.\002)";
    static char fmt_62[] = "(/,\002 *WRN:54* Number of linear reservoirs=\
\002,i5,\002 not yet\002,\002 supported.  NLR=1 assumed.\002)";
    static char fmt_64[] = "(/,\002 ERR:338* Delay-time constant=\002,f7.4\
,\002 <= 0.0 invalid.\002)";
    static char fmt_66[] = "(/,\002 *ERR:339* Name=\002,a16,\002 is unknown \
as a lag\002,\002-equation name.\002)";
    static char fmt_68[] = "(/,\002 Processing stopped.  Errors encountered\
.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    real k;
    extern /* Subroutine */ int feq_gen_chk_and_convert_response_d_(integer *, integer 
	    *, char *, integer *, integer *, integer *, integer *, char *, 
	    integer *, integer *, integer *, real *, doublereal *, ftnlen, 
	    ftnlen);
    integer selection, ip;
    char key[16];
    integer nlr;
    extern /* Subroutine */ int feq_gen_allocate_dlay_space_d_(integer *, integer *, 
	    integer *);
    integer feq_gen_dta_dlay_pnt_d_;
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    integer feq_gen_ndta_dlay_pnt_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_66, 0 };


/*     Set the parameter values for a delay option for */
/*     a tributary area unit */
/* SOURCE dtendlay.for:415 */
/*<       implicitnone >*/
/* INCLUDE dtendlay.for:416 */
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
/* SOURCE dtendlay.for:418 */
/*<        >*/
/* SOURCE dtendlay.for:423 */
/*<       realrval(item_knt) >*/
/* SOURCE dtendlay.for:425 */
/*<       real*8dpval(item_knt) >*/
/* SOURCE dtendlay.for:427 */
/*<       charactercval(item_knt)*256,term(item_knt)*1,which*4 >*/
/* INCLUDE dtendlay.for:429 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE dtendlay.for:434 */
/*<        >*/
/* SOURCE dtendlay.for:437 */
/*<        >*/
/* SOURCE dtendlay.for:441 */
/*<       integeri,ip,selection,dta_dlay_pnt,ndta_dlay_pnt,nlr >*/
/* SOURCE dtendlay.for:444 */
/*<       realk >*/
/* SOURCE dtendlay.for:446 */
/*<       characterkey*16 >*/
/* SOURCE dtendlay.for:448 */
/*<       integerlenstr >*/
/* SOURCE dtendlay.for:450 */
/*<       externallenstr >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE dtendlay.for:453 */
/*<        >*/
/* SOURCE dtendlay.for:455 */
/*<       charactersymbol_table(n_symbol)*16,eq_name(n_eq_name)*16 >*/
/* SOURCE dtendlay.for:457 */
/*<       realeq_id(n_eq_name) >*/
/* SOURCE dtendlay.for:459 */
/*<       savesymbol_value,symbol_table,response_type,convert_rule,eq_id >*/
/*     *****************************FORMATS****************************** */
/* SOURCE dtendlay.for:463 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> dpval(feq_storage_dpval, 1);

    feq::IndexedPointer<real> rval(feq_storage_rval, 1);

    feq::IndexedPointer<integer> ival(feq_storage_ival, 1);

    feq::IndexedPointer<char> term(feq_storage_term, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, 256);

    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    feq::IndexedPointer<integer> termcls(feq_storage_termcls, 1);

    feq::IndexedPointer<integer> terml(feq_storage_terml, 1);

    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    /* Function Body */
/* SOURCE dtendlay.for:467 */
/*<       datasymbol_value/1,2,3,4,4,4,4/ >*/
/* SOURCE dtendlay.for:471 */
/*<       dataresponse_type/intval,reaval,chrval,4*0/ >*/
/* SOURCE dtendlay.for:473 */
/*<       dataconvert_rule/exact_type,lower_type,exact_type,4*0/ >*/
/* SOURCE dtendlay.for:476 */
/*<       dataeq_name/'PURDUE','Purdue'/ >*/
/* SOURCE dtendlay.for:477 */
/*<       dataeq_id/-1.0,-1.0/ >*/
/* SOURCE dtendlay.for:479 */
/*<    52  >*/
/* L52: */
/* SOURCE dtendlay.for:481 */
/*<    54  >*/
/* L54: */
/* SOURCE dtendlay.for:483 */
/*<    56 format(/,' Unable to continue due to previous errors.') >*/
/* L56: */
/* SOURCE dtendlay.for:484 */
/*<    60 format(/,' Processing:',a) >*/
/* L60: */
/* SOURCE dtendlay.for:485 */
/*<    62  >*/
/* L62: */
/* SOURCE dtendlay.for:487 */
/*<    64 format(/,' ERR:338* Delay-time constant=',f7.4,' <= 0.0 invalid.') >*/
/* L64: */
/* SOURCE dtendlay.for:488 */
/*<    66  >*/
/* L66: */
/* SOURCE dtendlay.for:490 */
/*<    68 format(/,' Processing stopped.  Errors encountered.') >*/
/* L68: */
/* *********************************************************************** */
/* SOURCE dtendlay.for:492 */
/*<        >*/
    feq_gen_chk_and_convert_response_d_(stdout, &feq_gen_c_d_7, feq_gen_symbol_table_d_, feq_gen_response_type_d_,
	     feq_gen_convert_rule_d_, feq_gen_item_knt_d_, &feq_gen_item_type_d_[1], cval + 256, &clen[1]
	    , eflag, &ival[1], &rval[1], &dpval[1], (ftnlen)16, (ftnlen)256);
/* SOURCE dtendlay.for:497 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE dtendlay.for:498 */
/*<       write(stdout,68) >*/
	feq_gen_io_d__30.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__30);
	e_wsfe();
/* SOURCE dtendlay.for:499 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:500 */
/*<       endif >*/
    }
/*     Allocate space for the delay values.  If the */
/*     trib area unit does not exist the delay pointer is */
/*     returned as 0. */
/* SOURCE dtendlay.for:505 */
/*<       if(which.eq.'BOTH')then >*/
    if (s_cmp(which, const_cast<char*>("BOTH"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE dtendlay.for:506 */
/*<       callallocate_dlay_space(stdout,last_ndta_pnt,ndta_dlay_pnt) >*/
	feq_gen_allocate_dlay_space_d_(stdout, feq_gen_last_ndta_pnt_d_, &feq_gen_ndta_dlay_pnt_d_);
/* SOURCE dtendlay.for:508 */
/*<       callallocate_dlay_space(stdout,last_dta_pnt,dta_dlay_pnt) >*/
	feq_gen_allocate_dlay_space_d_(stdout, feq_gen_last_dta_pnt_d_, &feq_gen_dta_dlay_pnt_d_);
/* SOURCE dtendlay.for:510 */
/*<       elseif(which.eq.'DTA')then >*/
    } else if (s_cmp(which, const_cast<char*>("DTA"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE dtendlay.for:511 */
/*<       callallocate_dlay_space(stdout,last_dta_pnt,dta_dlay_pnt) >*/
	feq_gen_allocate_dlay_space_d_(stdout, feq_gen_last_dta_pnt_d_, &feq_gen_dta_dlay_pnt_d_);
/* SOURCE dtendlay.for:513 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:514 */
/*<       callallocate_dlay_space(stdout,last_ndta_pnt,ndta_dlay_pnt) >*/
	feq_gen_allocate_dlay_space_d_(stdout, feq_gen_last_ndta_pnt_d_, &feq_gen_ndta_dlay_pnt_d_);
/* SOURCE dtendlay.for:516 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:517 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE dtendlay.for:518 */
/*<   110 continue >*/
L110:
/*       Find the value for the next item from the */
/*       symbol table. */
/* SOURCE dtendlay.for:521 */
/*<       key=cval(i)(1:clen(i)) >*/
    s_copy(key, cval + (feq_gen_i_d_ << 8), (ftnlen)16, clen[feq_gen_i_d_]);
/*        WRITE(STDOUT,*) ' SET_DELAY_PARM...: I=',I, */
/*     A      ' KEY=',KEY */
/* SOURCE dtendlay.for:524 */
/*<       calllstab(key,symbol_table,n_symbol,ip) >*/
    lstab_(key, feq_gen_symbol_table_d_, &feq_gen_c_d_7, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE dtendlay.for:527 */
/*<       if(ip.eq.0)then >*/
    if (ip == 0) {
/*         error-symbol not found */
/* SOURCE dtendlay.for:529 */
/*<       write(stdout,54)key >*/
	feq_gen_io_d__36.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__36);
	do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	e_wsfe();
/* SOURCE dtendlay.for:530 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE dtendlay.for:532 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:533 */
/*<       selection=symbol_value(ip) >*/
	selection = feq_gen_symbol_value_d_[ip - 1];
/* SOURCE dtendlay.for:534 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:536 */
/*<       goto(1,2,3,4,4),selection >*/
    switch (selection) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L4;
    }
/* SOURCE dtendlay.for:538 */
/*<       write(stdout,52)i,key >*/
    feq_gen_io_d__38.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__38);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
    e_wsfe();
/* SOURCE dtendlay.for:539 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:541 */
/*<     1 continue >*/
L1:
/*         Number of linear reserviors.  Currently limited  to 1. */
/* SOURCE dtendlay.for:543 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:544 */
/*<       nlr=ival(i) >*/
    nlr = ival[feq_gen_i_d_];
/* SOURCE dtendlay.for:545 */
/*<       if(nlr.ne.1)then >*/
    if (nlr != 1) {
/* SOURCE dtendlay.for:546 */
/*<       write(stdout,62)nlr >*/
	feq_gen_io_d__40.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__40);
	do_fio(&feq_gen_c_d_1, (char *)&nlr, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE dtendlay.for:547 */
/*<       nlr=1 >*/
	nlr = 1;
/* SOURCE dtendlay.for:548 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:549 */
/*<       if(which.eq.'BOTH')then >*/
    if (s_cmp(which, const_cast<char*>("BOTH"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE dtendlay.for:550 */
/*<       dlay_nlr(ndta_dlay_pnt)=nlr >*/
	tamcom_1.feq_gen_dlay_nlr_d_[feq_gen_ndta_dlay_pnt_d_] = nlr;
/* SOURCE dtendlay.for:551 */
/*<       dlay_nlr(dta_dlay_pnt)=nlr >*/
	tamcom_1.feq_gen_dlay_nlr_d_[feq_gen_dta_dlay_pnt_d_] = nlr;
/* SOURCE dtendlay.for:552 */
/*<       elseif(which.eq.'DTA')then >*/
    } else if (s_cmp(which, const_cast<char*>("DTA"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE dtendlay.for:553 */
/*<       dlay_nlr(dta_dlay_pnt)=nlr >*/
	tamcom_1.feq_gen_dlay_nlr_d_[feq_gen_dta_dlay_pnt_d_] = nlr;
/* SOURCE dtendlay.for:554 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:555 */
/*<       dlay_nlr(ndta_dlay_pnt)=nlr >*/
	tamcom_1.feq_gen_dlay_nlr_d_[feq_gen_ndta_dlay_pnt_d_] = nlr;
/* SOURCE dtendlay.for:556 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:557 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:558 */
/*<     2 continue >*/
L2:
/*         Explict storage constant value.  Given by the user in */
/*         hours. Convert to seconds, the needed internal unit. */
/* SOURCE dtendlay.for:561 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:562 */
/*<       k=rval(i) >*/
    k = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:563 */
/*<       if(k.le.0.0)then >*/
    if (k <= (float)0.) {
/* SOURCE dtendlay.for:564 */
/*<       write(stdout,64)k >*/
	feq_gen_io_d__42.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__42);
	do_fio(&feq_gen_c_d_1, (char *)&k, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE dtendlay.for:565 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:566 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:567 */
/*<       k=k*3600. >*/
    k *= static_cast<double>((float)3600.);
/*         We set the number of reservoirs to 1 also.  Only value */
/*         supported at this time. */
/* SOURCE dtendlay.for:570 */
/*<       if(which.eq.'BOTH')then >*/
    if (s_cmp(which, const_cast<char*>("BOTH"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE dtendlay.for:571 */
/*<       dlay_k(ndta_dlay_pnt)=k >*/
	tamcom_1.feq_gen_dlay_k_d_[feq_gen_ndta_dlay_pnt_d_] = k;
/* SOURCE dtendlay.for:572 */
/*<       dlay_k(dta_dlay_pnt)=k >*/
	tamcom_1.feq_gen_dlay_k_d_[feq_gen_dta_dlay_pnt_d_] = k;
/* SOURCE dtendlay.for:573 */
/*<       dlay_nlr(ndta_dlay_pnt)=1 >*/
	tamcom_1.feq_gen_dlay_nlr_d_[feq_gen_ndta_dlay_pnt_d_] = 1;
/* SOURCE dtendlay.for:574 */
/*<       dlay_nlr(dta_dlay_pnt)=1 >*/
	tamcom_1.feq_gen_dlay_nlr_d_[feq_gen_dta_dlay_pnt_d_] = 1;
/* SOURCE dtendlay.for:575 */
/*<       elseif(which.eq.'DTA')then >*/
    } else if (s_cmp(which, const_cast<char*>("DTA"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE dtendlay.for:576 */
/*<       dlay_nlr(dta_dlay_pnt)=1 >*/
	tamcom_1.feq_gen_dlay_nlr_d_[feq_gen_dta_dlay_pnt_d_] = 1;
/* SOURCE dtendlay.for:577 */
/*<       dlay_k(dta_dlay_pnt)=k >*/
	tamcom_1.feq_gen_dlay_k_d_[feq_gen_dta_dlay_pnt_d_] = k;
/* SOURCE dtendlay.for:578 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:579 */
/*<       dlay_k(ndta_dlay_pnt)=k >*/
	tamcom_1.feq_gen_dlay_k_d_[feq_gen_ndta_dlay_pnt_d_] = k;
/* SOURCE dtendlay.for:580 */
/*<       dlay_nlr(ndta_dlay_pnt)=1 >*/
	tamcom_1.feq_gen_dlay_nlr_d_[feq_gen_ndta_dlay_pnt_d_] = 1;
/* SOURCE dtendlay.for:581 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:582 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:583 */
/*<     3 continue >*/
L3:
/*         Equation request here.  We cannot compute the */
/*         the values now because all the tables for the */
/*         the computation may not be available.  Thus */
/*         give each equation a negative number as an */
/*         id and store in the K slot.    We then compute */
/*         equation values later. */
/* SOURCE dtendlay.for:590 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:591 */
/*<       key=cval(i) >*/
    s_copy(key, cval + (feq_gen_i_d_ << 8), (ftnlen)16, (ftnlen)256);
/* SOURCE dtendlay.for:592 */
/*<       calllstab(key,eq_name,n_eq_name,ip) >*/
    lstab_(key, feq_gen_eq_name_d_, &feq_gen_c_d_2, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE dtendlay.for:595 */
/*<       if(ip.eq.0)then >*/
    if (ip == 0) {
/*           error-symbol not found */
/* SOURCE dtendlay.for:597 */
/*<       write(stdout,66)key >*/
	feq_gen_io_d__43.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__43);
	do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	e_wsfe();
/* SOURCE dtendlay.for:598 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE dtendlay.for:599 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:600 */
/*<       if(which.eq.'BOTH')then >*/
	if (s_cmp(which, const_cast<char*>("BOTH"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE dtendlay.for:601 */
/*<       dlay_k(ndta_dlay_pnt)=eq_id(ip) >*/
	    tamcom_1.feq_gen_dlay_k_d_[feq_gen_ndta_dlay_pnt_d_] = feq_gen_eq_id_d_[ip - 1];
/* SOURCE dtendlay.for:602 */
/*<       dlay_k(dta_dlay_pnt)=eq_id(ip) >*/
	    tamcom_1.feq_gen_dlay_k_d_[feq_gen_dta_dlay_pnt_d_] = feq_gen_eq_id_d_[ip - 1];
/* SOURCE dtendlay.for:603 */
/*<       elseif(which.eq.'DTA')then >*/
	} else if (s_cmp(which, const_cast<char*>("DTA"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE dtendlay.for:604 */
/*<       dlay_k(dta_dlay_pnt)=eq_id(ip) >*/
	    tamcom_1.feq_gen_dlay_k_d_[feq_gen_dta_dlay_pnt_d_] = feq_gen_eq_id_d_[ip - 1];
/* SOURCE dtendlay.for:605 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:606 */
/*<       dlay_k(ndta_dlay_pnt)=eq_id(ip) >*/
	    tamcom_1.feq_gen_dlay_k_d_[feq_gen_ndta_dlay_pnt_d_] = feq_gen_eq_id_d_[ip - 1];
/* SOURCE dtendlay.for:607 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:608 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:610 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:612 */
/*<     4 continue >*/
L4:
/*         Catch the line name and its aliases.  They are ignored */
/*         but they are present. */
/* SOURCE dtendlay.for:615 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:617 */
/*<   149 continue >*/
L149:
/* SOURCE dtendlay.for:618 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:619 */
/*<       if(i.gt.item_knt)return >*/
    if (feq_gen_i_d_ > *feq_gen_item_knt_d_) {
	return 0;
    }
/* SOURCE dtendlay.for:620 */
/*<       goto110 >*/
    goto L110;
/* SOURCE dtendlay.for:622 */
/*<       end >*/
} /* set_dlay_parameters__ */




/* SOURCE dtendlay.for:627 */
/*<        >*/
/* Subroutine */ int feq_gen_reset_detention_values_d_(integer *stdout, char *which, 
	real *grav, integer *feq_gen_item_knt_d_, integer *feq_storage_clen, integer *feq_storage_terml, 
	integer *feq_storage_termcls, integer *feq_gen_feq_storage_item_type_d_, char *feq_storage_cval, char *feq_storage_term, 
	integer *feq_storage_ival, real *feq_storage_rval, doublereal *feq_storage_dpval, integer *feq_gen_dta_pnt_d_, 
	integer *eflag, ftnlen which_len, ftnlen cval_len, ftnlen term_len)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*13+1] = "DEF             DEFAULT         U\
AQ             YD              AVDA            OFWC            BSS          \
   WS              UADV_TAB        ORIFICE_TAB     LUI             ORIFICE_C\
D      PARM            ";
    static integer feq_gen_symbol_value_d_[13] = { 1,1,2,3,4,5,6,7,8,9,10,11,1 };
    static integer feq_gen_response_type_d_[13] = { 0,0,2,2,2,2,2,2,4,4,1,2,0 };
    static integer feq_gen_convert_rule_d_[13] = { 0,0,1,1,1,1,1,1,1,1,0,0,0 };

    /* Format strings */
    static char fmt_52[] = "(/,\002 *BUG:XXX* Invalid index=\002,i5,\002 for\
 name=\002,a,\002 in\002,\002 subroutine RESET_DEFAULT_PARAMETERS.\002)";
    static char fmt_54[] = "(/,\002 *ERR:340* Name=\002,a8,\002 is unknown a\
s a default\002,\002 value.\002)";
    static char fmt_64[] = "(/,\002 *ERR:341* Average drainage area=\002,f10\
.1,\002 invalid.\002)";
    static char fmt_66[] = "(/,\002 *ERR:342* Design depth =\002,f10.1,\002 \
invalid.\002)";
    static char fmt_68[] = "(/,\002 *ERR:343* Unit-area flow =\002,f10.1,\
\002 invalid. Value\002,\002 must be\002,/,11x,\002>= 0.05 and <= 0.30\002)";
    static char fmt_69[] = "(/,\002 *ERR:344* Unit-area flow =\002,f10.1,\
\002 invalid. Value\002,\002 must be\002,/,11x,\002>= 0.35 and <= 2.099\002)";
    static char fmt_70[] = "(/,\002 *ERR:345* Overflow-weir coef=\002,f10.2\
,\002 invalid. Value\002,\002 must be > 0.0 and < 1.10\002)";
    static char fmt_72[] = "(/,\002 *ERR:346* Basin side slope =\002,f10.1\
,\002 invalid.\002)";
    static char fmt_74[] = "(/,\002 *ERR:347* Weir slope =\002,f10.1,\002 in\
valid.\002)";
    static char fmt_80[] = "(/,\002 *ERR:350* Impervious area land use ind\
ex=\002,i3,\002 invalid.\002)";
    static char fmt_82[] = "(/,\002 *ERR:351* Orifice discharge coef=\002,f7\
.3,\002 invalid.\002,\002 Value must be > 0.0 and < 1.0\002)";
    static char fmt_84[] = "(/,\002 Processing stopped.  Errors encountered\
.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_dten_pnt_d_, feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_chk_and_convert_response_d_(integer *, integer 
	    *, char *, integer *, integer *, integer *, integer *, char *, 
	    integer *, integer *, integer *, real *, doublereal *, ftnlen, 
	    ftnlen);
    integer selection, ip;
    char key[16];
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__55 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__56 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_82, 0 };


/*     Process the requests on a DEF line.  Resets one or more */
/*     of the default values for detention. */
/* SOURCE dtendlay.for:635 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:636 */
/*<        >*/
/* SOURCE dtendlay.for:640 */
/*<       realgrav,rval(item_knt) >*/
/* SOURCE dtendlay.for:642 */
/*<       real*8dpval(item_knt) >*/
/* SOURCE dtendlay.for:644 */
/*<       charactercval(item_knt)*256,term(item_knt)*1,which*4 >*/
/* INCLUDE dtendlay.for:646 */
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
/* INCLUDE dtendlay.for:647 */
/*     Common block for default detention basin values. */
/* SOURCE dtendef.cmn:3 */
/*<        >*/
/* SOURCE dtendef.cmn:6 */
/*<        >*/
/* SOURCE dtendef.cmn:9 */
/*<       character*16def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/* SOURCE dtendef.cmn:12 */
/*<        >*/
/* SOURCE dtendef.cmn:17 */
/*<       common/dtendefc/def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/* INCLUDE dtendlay.for:648 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE dtendlay.for:653 */
/*<        >*/
/* SOURCE dtendlay.for:656 */
/*<        >*/
/* SOURCE dtendlay.for:660 */
/*<       integeri,ip,selection,dten_pnt >*/
/* SOURCE dtendlay.for:662 */
/*<       characterkey*16 >*/
/*     External names */
/* SOURCE dtendlay.for:665 */
/*<       integerlenstr >*/
/* SOURCE dtendlay.for:667 */
/*<       externallenstr,get_internal_tab_number >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE dtendlay.for:670 */
/*<        >*/
/* SOURCE dtendlay.for:672 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE dtendlay.for:674 */
/*<       savesymbol_value,symbol_table >*/
/*     *****************************FORMATS****************************** */
/* SOURCE dtendlay.for:677 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> dpval(feq_storage_dpval, 1);

    feq::IndexedPointer<real> rval(feq_storage_rval, 1);

    feq::IndexedPointer<integer> ival(feq_storage_ival, 1);

    feq::IndexedPointer<char> term(feq_storage_term, 1);

    feq::IndexedPointer<char> cval(feq_storage_cval, 256);

    feq::IndexedPointer<integer> feq_gen_item_type_d_(feq_gen_feq_storage_item_type_d_, 1);

    feq::IndexedPointer<integer> termcls(feq_storage_termcls, 1);

    feq::IndexedPointer<integer> terml(feq_storage_terml, 1);

    feq::IndexedPointer<integer> clen(feq_storage_clen, 1);

    /* Function Body */
/* SOURCE dtendlay.for:683 */
/*<       datasymbol_value/1,1,2,3,4,5,6,7,8,9,10,11,1/ >*/
/* SOURCE dtendlay.for:688 */
/*<       dataresponse_type/2*0,6*reaval,2*chrval,intval,reaval,0/ >*/
/* SOURCE dtendlay.for:690 */
/*<        >*/
/* SOURCE dtendlay.for:693 */
/*<    52  >*/
/* L52: */
/* SOURCE dtendlay.for:695 */
/*<    54  >*/
/* L54: */
/* SOURCE dtendlay.for:697 */
/*<    56 format(/,' Unable to continue due to previous errors.') >*/
/* L56: */
/* SOURCE dtendlay.for:698 */
/*<    60 format(/,' Processing:',a) >*/
/* L60: */
/* SOURCE dtendlay.for:699 */
/*<    64 format(/,' *ERR:341* Average drainage area=',f10.1,' invalid.') >*/
/* L64: */
/* SOURCE dtendlay.for:700 */
/*<    66 format(/,' *ERR:342* Design depth =',f10.1,' invalid.') >*/
/* L66: */
/* SOURCE dtendlay.for:701 */
/*<    68  >*/
/* L68: */
/* SOURCE dtendlay.for:703 */
/*<    69  >*/
/* L69: */
/* SOURCE dtendlay.for:705 */
/*<    70  >*/
/* L70: */
/* SOURCE dtendlay.for:707 */
/*<    72 format(/,' *ERR:346* Basin side slope =',f10.1,' invalid.') >*/
/* L72: */
/* SOURCE dtendlay.for:708 */
/*<    74 format(/,' *ERR:347* Weir slope =',f10.1,' invalid.') >*/
/* L74: */
/* SOURCE dtendlay.for:709 */
/*<    80  >*/
/* L80: */
/* SOURCE dtendlay.for:711 */
/*<    82  >*/
/* L82: */
/* SOURCE dtendlay.for:713 */
/*<    84 format(/,' Processing stopped.  Errors encountered.') >*/
/* L84: */
/* *********************************************************************** */
/* SOURCE dtendlay.for:715 */
/*<        >*/
    feq_gen_chk_and_convert_response_d_(stdout, &feq_gen_c_d_13, feq_gen_symbol_table_d_, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_item_knt_d_, &feq_gen_item_type_d_[1], 
	    cval + 256, &clen[1], eflag, &ival[1], &rval[1], &dpval[1], (
	    ftnlen)16, (ftnlen)256);
/* SOURCE dtendlay.for:720 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE dtendlay.for:721 */
/*<       write(stdout,84) >*/
	feq_gen_io_d__48.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__48);
	e_wsfe();
/* SOURCE dtendlay.for:722 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:723 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:724 */
/*<       if(which.eq.'PARM')then >*/
    if (s_cmp(which, const_cast<char*>("PARM"), (ftnlen)4, (ftnlen)4) == 0) {
/*       Get the address for the detention parameters */
/* SOURCE dtendlay.for:726 */
/*<       dten_pnt=tam_itab(dta_pnt+5) >*/
	feq_gen_dten_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[*feq_gen_dta_pnt_d_ + 4];
/* SOURCE dtendlay.for:727 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:728 */
/*<       dten_pnt=0 >*/
	feq_gen_dten_pnt_d_ = 0;
/* SOURCE dtendlay.for:729 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:730 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE dtendlay.for:731 */
/*<   110 continue >*/
L110:
/*       Find the value for the next item from the */
/*       symbol table. */
/* SOURCE dtendlay.for:734 */
/*<       key=cval(i)(1:clen(i)) >*/
    s_copy(key, cval + (feq_gen_i_d_ << 8), (ftnlen)16, clen[feq_gen_i_d_]);
/*        WRITE(STDOUT,*) ' RESET_DEFAULT...: I=',I, */
/*     A      ' KEY=',KEY */
/* SOURCE dtendlay.for:737 */
/*<       calllstab(key,symbol_table,n_symbol,ip) >*/
    lstab_(key, feq_gen_symbol_table_d_, &feq_gen_c_d_13, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE dtendlay.for:740 */
/*<       if(ip.eq.0)then >*/
    if (ip == 0) {
/*         error-symbol not found */
/* SOURCE dtendlay.for:742 */
/*<       write(stdout,54)key >*/
	feq_gen_io_d__53.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__53);
	do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	e_wsfe();
/* SOURCE dtendlay.for:743 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE dtendlay.for:745 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:746 */
/*<       selection=symbol_value(ip) >*/
	selection = feq_gen_symbol_value_d_[ip - 1];
/* SOURCE dtendlay.for:747 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:749 */
/*<       goto(1,2,3,4,5,6,7,8,9,10,11),selection >*/
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
    }
/* SOURCE dtendlay.for:751 */
/*<       write(stdout,52)i,key >*/
    feq_gen_io_d__55.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__55);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
    e_wsfe();
/* SOURCE dtendlay.for:752 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:754 */
/*<     1 continue >*/
L1:
/*         Catch the line name and its aliases.  They are ignored */
/*         but they are present. */
/* SOURCE dtendlay.for:757 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:759 */
/*<     2 continue >*/
L2:
/*       Unit area flow. */
/* SOURCE dtendlay.for:761 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:762 */
/*<       if(grav.gt.15.0)then >*/
    if (*grav > (float)15.) {
/* SOURCE dtendlay.for:763 */
/*<       if(rval(i).lt.0.05.or.rval(i).gt.0.30)then >*/
	if (rval[feq_gen_i_d_] < (float).05 || rval[feq_gen_i_d_] > (float).3) {
/* SOURCE dtendlay.for:764 */
/*<       write(stdout,68)rval(i) >*/
	    feq_gen_io_d__56.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__56);
	    do_fio(&feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE dtendlay.for:765 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:766 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:767 */
/*<       if(dten_pnt.eq.0)then >*/
	if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:768 */
/*<       def_dten_uaq=rval(i)/43560. >*/
	    dtendef_1.feq_gen_def_dten_uaq_d_ = static_cast<double>(rval[feq_gen_i_d_]) / (float)43560.;
/* SOURCE dtendlay.for:769 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:770 */
/*<       dten_uaq(dten_pnt)=rval(i)/43560. >*/
	    tamcom_1.feq_gen_dten_uaq_d_[feq_gen_dten_pnt_d_ - 1] = static_cast<double>(rval[feq_gen_i_d_]) / (float)43560.;
/* SOURCE dtendlay.for:771 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:772 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:773 */
/*<       if(rval(i).lt.0.35.or.rval(i).gt.2.099)then >*/
	if (rval[feq_gen_i_d_] < (float).35 || rval[feq_gen_i_d_] > (float)2.099) {
/* SOURCE dtendlay.for:774 */
/*<       write(stdout,69)rval(i) >*/
	    feq_gen_io_d__57.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__57);
	    do_fio(&feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE dtendlay.for:775 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:776 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:777 */
/*<       if(dten_pnt.eq.0)then >*/
	if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:778 */
/*<       def_dten_uaq=rval(i)/1.e6 >*/
	    dtendef_1.feq_gen_def_dten_uaq_d_ = static_cast<double>(rval[feq_gen_i_d_]) / (float)1e6;
/* SOURCE dtendlay.for:779 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:780 */
/*<       dten_uaq(dten_pnt)=rval(i)/1.e6 >*/
	    tamcom_1.feq_gen_dten_uaq_d_[feq_gen_dten_pnt_d_ - 1] = static_cast<double>(rval[feq_gen_i_d_]) / (float)1e6;
/* SOURCE dtendlay.for:781 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:782 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:783 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:784 */
/*<     3 continue >*/
L3:
/*         Design depth */
/* SOURCE dtendlay.for:786 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:787 */
/*<       if(rval(i).le.0.0)then >*/
    if (rval[feq_gen_i_d_] <= (float)0.) {
/* SOURCE dtendlay.for:788 */
/*<       write(stdout,66)rval(i) >*/
	feq_gen_io_d__58.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__58);
	do_fio(&feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE dtendlay.for:789 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:790 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:791 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:792 */
/*<       def_dten_yd=rval(i) >*/
	dtendef_1.feq_gen_def_dten_yd_d_ = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:793 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:794 */
/*<       dten_yd(dten_pnt)=rval(i) >*/
	tamcom_1.feq_gen_dten_yd_d_[feq_gen_dten_pnt_d_ - 1] = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:795 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:796 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:798 */
/*<     4 continue >*/
L4:
/*         Average drainage area for a detention basin */
/* SOURCE dtendlay.for:800 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:801 */
/*<       if(rval(i).le.0.0)then >*/
    if (rval[feq_gen_i_d_] <= (float)0.) {
/* SOURCE dtendlay.for:802 */
/*<       write(stdout,64)rval(i) >*/
	feq_gen_io_d__59.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__59);
	do_fio(&feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE dtendlay.for:803 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:804 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:805 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:806 */
/*<       if(grav.gt.15.)then >*/
	if (*grav > (float)15.) {
/* SOURCE dtendlay.for:807 */
/*<       def_dten_avda=rval(i)*43560. >*/
	    dtendef_1.feq_gen_def_dten_avda_d_ = static_cast<double>(rval[feq_gen_i_d_]) * (float)43560.;
/* SOURCE dtendlay.for:808 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:809 */
/*<       def_dten_avda=rval(i)*1.e6 >*/
	    dtendef_1.feq_gen_def_dten_avda_d_ = static_cast<double>(rval[feq_gen_i_d_]) * (float)1e6;
/* SOURCE dtendlay.for:810 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:811 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:812 */
/*<       if(grav.gt.15.)then >*/
	if (*grav > (float)15.) {
/* SOURCE dtendlay.for:813 */
/*<       dten_avda(dten_pnt)=rval(i)*43560. >*/
	    tamcom_1.feq_gen_dten_avda_d_[feq_gen_dten_pnt_d_ - 1] = static_cast<double>(rval[feq_gen_i_d_]) * (float)43560.;
/* SOURCE dtendlay.for:814 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:815 */
/*<       dten_avda(dten_pnt)=rval(i)*1.e6 >*/
	    tamcom_1.feq_gen_dten_avda_d_[feq_gen_dten_pnt_d_ - 1] = static_cast<double>(rval[feq_gen_i_d_]) * (float)1e6;
/* SOURCE dtendlay.for:816 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:817 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:818 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:819 */
/*<     5 continue >*/
L5:
/*         Overflow-weir coefficient */
/* SOURCE dtendlay.for:821 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:822 */
/*<       if(rval(i).le.0.0.or.rval(i).gt.1.0)then >*/
    if (rval[feq_gen_i_d_] <= (float)0. || rval[feq_gen_i_d_] > (float)1.) {
/* SOURCE dtendlay.for:823 */
/*<       write(stdout,70)rval(i) >*/
	feq_gen_io_d__60.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__60);
	do_fio(&feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE dtendlay.for:824 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:825 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:826 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:827 */
/*<       def_dten_wc=rval(i) >*/
	dtendef_1.feq_gen_def_dten_wc_d_ = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:828 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:829 */
/*<       dten_wc(dten_pnt)=rval(i) >*/
	tamcom_1.feq_gen_dten_wc_d_[feq_gen_dten_pnt_d_ - 1] = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:830 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:831 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:832 */
/*<     6 continue >*/
L6:
/*         Basin side slope */
/* SOURCE dtendlay.for:834 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:835 */
/*<       if(rval(i).lt.0.0)then >*/
    if (rval[feq_gen_i_d_] < (float)0.) {
/* SOURCE dtendlay.for:836 */
/*<       write(stdout,72)rval(i) >*/
	feq_gen_io_d__61.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__61);
	do_fio(&feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE dtendlay.for:837 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:838 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:839 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:840 */
/*<       def_dten_bz=rval(i) >*/
	dtendef_1.feq_gen_def_dten_bz_d_ = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:841 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:842 */
/*<       dten_bz(dten_pnt)=rval(i) >*/
	tamcom_1.feq_gen_dten_bz_d_[feq_gen_dten_pnt_d_ - 1] = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:843 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:844 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:845 */
/*<     7 continue >*/
L7:
/*         Weir slope */
/* SOURCE dtendlay.for:847 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:848 */
/*<       if(rval(i).le.0.0)then >*/
    if (rval[feq_gen_i_d_] <= (float)0.) {
/* SOURCE dtendlay.for:849 */
/*<       write(stdout,74)rval(i) >*/
	feq_gen_io_d__62.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE dtendlay.for:850 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:851 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:852 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:853 */
/*<       def_dten_wz=rval(i) >*/
	dtendef_1.feq_gen_def_dten_wz_d_ = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:854 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:855 */
/*<       dten_wz(dten_pnt)=rval(i) >*/
	tamcom_1.feq_gen_dten_wz_d_[feq_gen_dten_pnt_d_ - 1] = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:856 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:857 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:858 */
/*<     8 continue >*/
L8:
/*         Unit-area detention volume table number */
/* SOURCE dtendlay.for:860 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:861 */
/*<       key=cval(i)(1:16) >*/
    s_copy(key, cval + (feq_gen_i_d_ << 8), (ftnlen)16, (ftnlen)16);
/* SOURCE dtendlay.for:862 */
/*<       callget_internal_tab_number(stdout,key,eflag,ival(i)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &ival[feq_gen_i_d_], (ftnlen)16);
/* SOURCE dtendlay.for:867 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:868 */
/*<       def_dten_unit_area_vol_tab_num=ival(i) >*/
	dtendef_1.feq_gen_def_dten_unit_area_vol_tab_num_d_ = ival[feq_gen_i_d_];
/* SOURCE dtendlay.for:869 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:870 */
/*<       dten_uadv_tab(dten_pnt)=ival(i) >*/
	tamcom_1.feq_gen_dten_uadv_tab_d_[feq_gen_dten_pnt_d_ - 1] = ival[feq_gen_i_d_];
/* SOURCE dtendlay.for:871 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:873 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:874 */
/*<     9 continue >*/
L9:
/*         Orifice table */
/* SOURCE dtendlay.for:876 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:877 */
/*<       key=cval(i)(1:16) >*/
    s_copy(key, cval + (feq_gen_i_d_ << 8), (ftnlen)16, (ftnlen)16);
/* SOURCE dtendlay.for:878 */
/*<       callget_internal_tab_number(stdout,key,eflag,ival(i)) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &ival[feq_gen_i_d_], (ftnlen)16);
/* SOURCE dtendlay.for:882 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:883 */
/*<       def_dten_orif_tab_num=ival(i) >*/
	dtendef_1.feq_gen_def_dten_orif_tab_num_d_ = ival[feq_gen_i_d_];
/* SOURCE dtendlay.for:884 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:885 */
/*<       dten_orf_tab(dten_pnt)=ival(i) >*/
	tamcom_1.feq_gen_dten_orf_tab_d_[feq_gen_dten_pnt_d_ - 1] = ival[feq_gen_i_d_];
/* SOURCE dtendlay.for:886 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:887 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:888 */
/*<    10 continue >*/
L10:
/*         Index for the impervious area in the land use sequence. */
/* SOURCE dtendlay.for:890 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:891 */
/*<       if(ival(i).le.0.or.ival(i).gt.mxn_lu_g)then >*/
    if (ival[feq_gen_i_d_] <= 0 || ival[feq_gen_i_d_] > 8) {
/* SOURCE dtendlay.for:892 */
/*<       write(stdout,80)ival(i) >*/
	feq_gen_io_d__63.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__63);
	do_fio(&feq_gen_c_d_1, (char *)&ival[feq_gen_i_d_], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE dtendlay.for:893 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:894 */
/*<       endif >*/
    }
/*         Land use index for impervious area is always global. */
/* SOURCE dtendlay.for:896 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:897 */
/*<       def_dten_lui=ival(i) >*/
	dtendef_1.feq_gen_def_dten_lui_d_ = ival[feq_gen_i_d_];
/* SOURCE dtendlay.for:898 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:899 */
/*<       def_dten_lui=ival(i) >*/
	dtendef_1.feq_gen_def_dten_lui_d_ = ival[feq_gen_i_d_];
/* SOURCE dtendlay.for:900 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:902 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:904 */
/*<    11 continue >*/
L11:
/*         Orifice discharge coeff */
/* SOURCE dtendlay.for:906 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:907 */
/*<       if(rval(i).le.0.9.or.rval(i).gt.1.0)then >*/
    if (rval[feq_gen_i_d_] <= (float).9 || rval[feq_gen_i_d_] > (float)1.) {
/* SOURCE dtendlay.for:908 */
/*<       write(stdout,82)rval(i) >*/
	feq_gen_io_d__64.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__64);
	do_fio(&feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE dtendlay.for:909 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:910 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:911 */
/*<       if(dten_pnt.eq.0)then >*/
    if (feq_gen_dten_pnt_d_ == 0) {
/* SOURCE dtendlay.for:912 */
/*<       def_dten_orfcd=rval(i) >*/
	dtendef_1.feq_gen_def_dten_orfcd_d_ = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:913 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:914 */
/*<       dten_orfcd(dten_pnt)=rval(i) >*/
	tamcom_1.feq_gen_dten_orfcd_d_[feq_gen_dten_pnt_d_ - 1] = rval[feq_gen_i_d_];
/* SOURCE dtendlay.for:915 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:917 */
/*<       goto149 >*/
    goto L149;
/* SOURCE dtendlay.for:919 */
/*<   149 continue >*/
L149:
/* SOURCE dtendlay.for:920 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE dtendlay.for:921 */
/*<       if(i.gt.item_knt)return >*/
    if (feq_gen_i_d_ > *feq_gen_item_knt_d_) {
	return 0;
    }
/* SOURCE dtendlay.for:922 */
/*<       goto110 >*/
    goto L110;
/* SOURCE dtendlay.for:924 */
/*<       end >*/
} /* reset_detention_values__ */

/*     *********** */
/*     *         * */
/*     * PROCESS_DETENTION_DELAY_OPTIONS */
/*     *         * */
/*     *********** */
/* SOURCE dtendlay.for:935 */
/*<        >*/
/* Subroutine */ int feq_gen_process_detention_delay_options_d_(integer *stdout, real *
	grav, real *feq_gen_con_fac_d_, char *line112, integer *ngage, integer *gstart,
	 integer *gend, integer *feq_gen_last_ndta_pnt_d_, integer *feq_gen_last_dta_pnt_d_, 
	integer *feq_gen_back_pnt_d_, real *feq_storage_triba, integer *eflag, ftnlen line112_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:352* Option:\002,a16,\002 unknown f\
or delay/detention.\002)";
    static char fmt_56[] = "(/,\002 Unable to continue due to previous error\
s.\002)";

    /* System generated locals */
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_item_knt_d_, feq_gen_i_d_, n, feq_gen_item_type_d_[20], opt, clen[20];
    extern /* Subroutine */ int feq_gen_set_dlay_parameters_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, char *, 
	    char *, integer *, real *, doublereal *, integer *, integer *, 
	    integer *, ftnlen, ftnlen, ftnlen);
    char cval[256*20], line[113];
    integer ival[20];
    real rval[20];
    char term[1*20];
    doublereal dpval[20];
    integer terml[20];
    extern /* Subroutine */ int getval_(integer *, char *, integer *, integer 
	    *, integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_set_trib_areas_d_(integer *, char *, integer *,
	     integer *, integer *, integer *, real *, integer *, integer *, 
	    real *, integer *, integer *, real *, integer *, ftnlen);
    char feq_gen_line_id_d_[16];
    extern /* Subroutine */ int feq_gen_reset_detention_values_d_(integer *, char *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    char *, char *, integer *, real *, doublereal *, integer *, 
	    integer *, ftnlen, ftnlen, ftnlen);
    integer termcls[20];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__79 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_50, 0 };


/*     Dechipher the lines of input specifying the detention and */
/*     delay characteristics. */
/*     Parameters */
/* SOURCE dtendlay.for:946 */
/*<       implicitnone >*/
/* INCLUDE dtendlay.for:947 */
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
/* SOURCE dtendlay.for:949 */
/*<        >*/
/* SOURCE dtendlay.for:953 */
/*<       realcon_fac,grav,triba(mxr_triba,mxn_lu_g) >*/
/* SOURCE dtendlay.for:955 */
/*<       characterline112*112 >*/
/* INCLUDE dtendlay.for:957 */
/*     COMMON FOR TRANSLATION OF USER NODES AND BRANCHS TO THE INTERNAL */
/*     VALUES FOR THESE BRANCHES.  ONLY USED DURING PROCESSING OF */
/*     INPUT.  THUS DO NOT PUT COMMON BLOCK IN SAVE.  IT SHOULD BE */
/*     RELEASED FROM STORAGE WHEN SUBROUTINE INFO IS LEFT. */
/* SOURCE usintp.cmn:6 */
/*<       common/usintp/usbrin,usenin >*/
/* SOURCE usintp.cmn:8 */
/*<       integerusbrin(9999),usenin(-9999:19998) >*/

/* INCLUDE dtendlay.for:958 */
/*     COMMON BLOCKS FOR THE TRANSLATION FROM INTERNAL NODE AND BRANCH */
/*     NUMBERS TO THEIR USER DESIGINATION.  NEED TWO BLOCKS BECAUSE */
/*     OF FORTRAN RESTRICTIONS ON CHARACTER VARIABLES IN COMMON WITH */
/*     NON-CHARACTER VARIABLES. */
/*     ALSO INCLUDE THE MAPPING VECTOR SO THE OLD STYLE INPUT WILL */
/*     OUTPUT EXTERIOR NODES IN ASCENDING NUMERICAL ORDER. */
/* SOURCE inusnb.cmn:10 */
/*<       integerinbrus(9999),usnsrt(mnex) >*/
/* SOURCE inusnb.cmn:12 */
/*<       character*5inenus(mnex) >*/
/* SOURCE inusnb.cmn:14 */
/*<       common/inbr/inbrus >*/
/* SOURCE inusnb.cmn:16 */
/*<       common/inen/usnsrt >*/
/* SOURCE inusnb.cmn:18 */
/*<       common/inenc/inenus >*/

/* INCLUDE dtendlay.for:959 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/* SOURCE dtendlay.for:965 */
/*<       integermax_item_knt >*/
/* SOURCE dtendlay.for:966 */
/*<       parameter(max_item_knt=20) >*/
/* SOURCE dtendlay.for:968 */
/*<       integeri,item_knt,opt,n >*/
/* SOURCE dtendlay.for:969 */
/*<        >*/
/* SOURCE dtendlay.for:972 */
/*<       realrval(max_item_knt) >*/
/* SOURCE dtendlay.for:973 */
/*<       real*8dpval(max_item_knt) >*/
/* SOURCE dtendlay.for:974 */
/*<        >*/
/* SOURCE dtendlay.for:977 */
/*<       integerlenstr >*/
/* SOURCE dtendlay.for:979 */
/*<       externalgetval,set_trib_areas,lenstr >*/
/*     *****************************Formats****************************** */
/* SOURCE dtendlay.for:981 */
/*<    50 format(/,' *ERR:352* Option:',a16,' unknown for delay/detention.') >*/
/* SOURCE dtendlay.for:982 */
/*<    56 format(/,' Unable to continue due to previous errors.') >*/
/* *********************************************************************** */
/* SOURCE dtendlay.for:985 */
/*<       n=lenstr(line112) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> triba(feq_storage_triba, 8401);

    /* Function Body */
/* L50: */
/* L56: */
    n = lenstr_(line112, (ftnlen)112);
/* SOURCE dtendlay.for:986 */
/*<       write(stdout,'(A)')line112(1:n) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line112, n);
    e_wsfe();
/* SOURCE dtendlay.for:988 */
/*<       line=line112 >*/
    s_copy(line, line112, (ftnlen)113, (ftnlen)112);
/*     Search for user given quote. */
/* SOURCE dtendlay.for:991 */
/*<       i=index(line,'''') >*/
    feq_gen_i_d_ = i_indx(line, const_cast<char*>("'"), (ftnlen)113, (ftnlen)1);
/* SOURCE dtendlay.for:992 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/*       Put one in to end the line. */
/* SOURCE dtendlay.for:994 */
/*<       line(113:113)='''' >*/
	*(unsigned char *)&line[112] = '\'';
/* SOURCE dtendlay.for:995 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:997 */
/*<       opt=2 >*/
    opt = 2;
/* SOURCE dtendlay.for:998 */
/*<        >*/
    getval_(stdout, line, &feq_gen_c_d_20, &opt, feq_gen_item_type_d_, ival, rval, dpval, cval, 
	    clen, eflag, term, terml, termcls, &feq_gen_item_knt_d_, (ftnlen)113, (
	    ftnlen)256, (ftnlen)1);
/*      WRITE(STDOUT,*) */
/*     A ' Return from GETVAL in PROCESS_DETENTION_DELAY_OPTIONS:', */
/*     B ' ITEM_KNT=',ITEM_KNT */
/*      DO 9213 I=1,ITEM_KNT */
/*        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I) */
/* 99    FORMAT(' ',A12,' ',I5,' ',I5,' ',A1) */
/* 9213  CONTINUE */
/* SOURCE dtendlay.for:1009 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE dtendlay.for:1010 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__79.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__79);
	e_wsfe();
/* SOURCE dtendlay.for:1011 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:1012 */
/*<       else >*/
    } else {
/*       The first item on the line should be the line identifier. */
/*       Branch on this identifier. */
/* SOURCE dtendlay.for:1016 */
/*<       line_id=cval(1) >*/
	s_copy(feq_gen_line_id_d_, cval, (ftnlen)16, (ftnlen)256);
/* SOURCE dtendlay.for:1017 */
/*<       if(line_id.eq.'DTEN')then >*/
	if (s_cmp(feq_gen_line_id_d_, const_cast<char*>("DTEN"), (ftnlen)16, (ftnlen)4) == 0) {
/* SOURCE dtendlay.for:1018 */
/*<        >*/
	    feq_gen_set_trib_areas_d_(stdout, cval, ngage, gend, gstart, &feq_gen_c_d_20, 
		    feq_gen_con_fac_d_, &feq_gen_item_knt_d_, feq_gen_back_pnt_d_, rval, feq_gen_last_ndta_pnt_d_,
		     feq_gen_last_dta_pnt_d_, &triba[8401], eflag, (ftnlen)256);
/* SOURCE dtendlay.for:1024 */
/*<       elseif(line_id.eq.'DLAY'.or.line_id.eq.'DELAY')then >*/
	} else if (s_cmp(feq_gen_line_id_d_, const_cast<char*>("DLAY"), (ftnlen)16, (ftnlen)4) == 0 || 
		s_cmp(feq_gen_line_id_d_, const_cast<char*>("DELAY"), (ftnlen)16, (ftnlen)5) == 0) {
/* SOURCE dtendlay.for:1025 */
/*<        >*/
	    feq_gen_set_dlay_parameters_d_(stdout, const_cast<char*>("BOTH"), &feq_gen_item_knt_d_, clen, terml, 
		    termcls, feq_gen_item_type_d_, cval, term, ival, rval, dpval, 
		    feq_gen_last_ndta_pnt_d_, feq_gen_last_dta_pnt_d_, eflag, (ftnlen)4, (
		    ftnlen)256, (ftnlen)1);
/* SOURCE dtendlay.for:1030 */
/*<       elseif(line_id.eq.'DLAY_NDTA')then >*/
	} else if (s_cmp(feq_gen_line_id_d_, const_cast<char*>("DLAY_NDTA"), (ftnlen)16, (ftnlen)9) == 0) 
		{
/* SOURCE dtendlay.for:1031 */
/*<        >*/
	    feq_gen_set_dlay_parameters_d_(stdout, const_cast<char*>("NDTA"), &feq_gen_item_knt_d_, clen, terml, 
		    termcls, feq_gen_item_type_d_, cval, term, ival, rval, dpval, 
		    feq_gen_last_ndta_pnt_d_, feq_gen_last_dta_pnt_d_, eflag, (ftnlen)4, (
		    ftnlen)256, (ftnlen)1);
/* SOURCE dtendlay.for:1037 */
/*<       elseif(line_id.eq.'DLAY_DTA')then >*/
	} else if (s_cmp(feq_gen_line_id_d_, const_cast<char*>("DLAY_DTA"), (ftnlen)16, (ftnlen)8) == 0) {
/* SOURCE dtendlay.for:1038 */
/*<        >*/
	    feq_gen_set_dlay_parameters_d_(stdout, const_cast<char*>("DTA "), &feq_gen_item_knt_d_, clen, terml, 
		    termcls, feq_gen_item_type_d_, cval, term, ival, rval, dpval, 
		    feq_gen_last_ndta_pnt_d_, feq_gen_last_dta_pnt_d_, eflag, (ftnlen)4, (
		    ftnlen)256, (ftnlen)1);
/* SOURCE dtendlay.for:1044 */
/*<       elseif(line_id.eq.'DEF')then >*/
	} else if (s_cmp(feq_gen_line_id_d_, const_cast<char*>("DEF"), (ftnlen)16, (ftnlen)3) == 0) {
/* SOURCE dtendlay.for:1045 */
/*<        >*/
	    feq_gen_reset_detention_values_d_(stdout, const_cast<char*>("DEF "), grav, &feq_gen_item_knt_d_, clen, 
		    terml, termcls, feq_gen_item_type_d_, cval, term, ival, rval, 
		    dpval, feq_gen_last_dta_pnt_d_, eflag, (ftnlen)4, (ftnlen)256, (
		    ftnlen)1);
/* SOURCE dtendlay.for:1049 */
/*<       elseif(line_id.eq.'PARM')then >*/
	} else if (s_cmp(feq_gen_line_id_d_, const_cast<char*>("PARM"), (ftnlen)16, (ftnlen)4) == 0) {
/* SOURCE dtendlay.for:1050 */
/*<        >*/
	    feq_gen_reset_detention_values_d_(stdout, const_cast<char*>("PARM"), grav, &feq_gen_item_knt_d_, clen, 
		    terml, termcls, feq_gen_item_type_d_, cval, term, ival, rval, 
		    dpval, feq_gen_last_dta_pnt_d_, eflag, (ftnlen)4, (ftnlen)256, (
		    ftnlen)1);
/* SOURCE dtendlay.for:1055 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:1056 */
/*<       write(stdout,50)line_id >*/
	    feq_gen_io_d__81.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__81);
	    do_fio(&feq_gen_c_d_1, feq_gen_line_id_d_, (ftnlen)16);
	    e_wsfe();
/* SOURCE dtendlay.for:1057 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:1058 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1059 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:1061 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1062 */
/*<       end >*/
} /* process_detention_delay_options__ */




/* SOURCE dtendlay.for:1066 */
/*<        >*/
/* Subroutine */ int feq_gen_compute_dten_pond_volume_d_(integer *stdout, integer *
	feq_gen_dten_pnt_d_, integer *feq_gen_uadv_tab_d_, integer *feq_gen_unit_pnt_d_, real *grav, 
	real *feq_gen_pond_volume_d_, real *feq_gen_total_area_d_, real *qfac, real *
	feq_gen_imp_fraction_d_)
{
    real feq_gen_uaq_look_d_, feq_gen_unit_area_volume_d_, dfdc, dfdr;
    extern /* Subroutine */ int tdlk10_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *), 
	    feq_gen_compute_area_and_imp_fraction_d_(integer *, integer *, real *, 
	    real *);

/*     Compute the volume for a detention pond. */
/* SOURCE dtendlay.for:1072 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:1073 */
/*<       integerstdout,dten_pnt,unit_pnt,uadv_tab >*/
/* SOURCE dtendlay.for:1075 */
/*<       realgrav,pond_volume,total_area,qfac,imp_fraction >*/
/* INCLUDE dtendlay.for:1077 */
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
/* INCLUDE dtendlay.for:1078 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/* INCLUDE dtendlay.for:1079 */
/* *********************************************************************** */
/* SOURCE tsfcom.cmn:2 */
/*<        >*/
/* SOURCE tsfcom.cmn:6 */
/*<        >*/
/* SOURCE tsfcom.cmn:8 */
/*<       integerbwyr(mndbuf),bord(mndbuf),gend(0:mxgage),gstart(0:mxgage) >*/
/* SOURCE tsfcom.cmn:10 */
/*<       realdtend >*/
/* SOURCE tsfcom.cmn:11 */
/*<       realtriba(mxr_triba,mxn_lu_g),tsfrat(mndbuf,mndifa),tafac(mnbra) >*/
/* SOURCE tsfcom.cmn:14 */
/*<       real*8tsfbuf(mndbuf,mndifa),bjtime(mndbuf) >*/
/* *********************************************************************** */
/*     Local */
/* SOURCE dtendlay.for:1084 */
/*<       realunit_area_volume,dfdr,dfdc,uaq_look >*/
/* *********************************************************************** */
/*     Compute the total area and the impervious area fraction. */
/* SOURCE dtendlay.for:1088 */
/*<        >*/
    feq_gen_compute_area_and_imp_fraction_d_(stdout, feq_gen_unit_pnt_d_, feq_gen_total_area_d_, 
	    feq_gen_imp_fraction_d_);
/* SOURCE dtendlay.for:1091 */
/*<       if(grav.gt.15.0)then >*/
    if (*grav > (float)15.) {
/* SOURCE dtendlay.for:1092 */
/*<       uaq_look=dten_uaq(dten_pnt)*43560. >*/
	feq_gen_uaq_look_d_ = static_cast<double>(tamcom_1.feq_gen_dten_uaq_d_[*feq_gen_dten_pnt_d_ - 1]) * (float)43560.;
/* SOURCE dtendlay.for:1093 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:1094 */
/*<       uaq_look=dten_uaq(dten_pnt)*1.e6 >*/
	feq_gen_uaq_look_d_ = static_cast<double>(tamcom_1.feq_gen_dten_uaq_d_[*feq_gen_dten_pnt_d_ - 1]) * (float)1e6;
/* SOURCE dtendlay.for:1095 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:1096 */
/*<        >*/
    tdlk10_(stdout, feq_gen_uadv_tab_d_, &feq_gen_c_d_10, feq_gen_imp_fraction_d_, &feq_gen_uaq_look_d_, &
	    feq_gen_unit_area_volume_d_, &dfdr, &dfdc);
/* SOURCE dtendlay.for:1100 */
/*<       pond_volume=unit_area_volume*dten_avda(dten_pnt) >*/
    *feq_gen_pond_volume_d_ = static_cast<double>(feq_gen_unit_area_volume_d_) * tamcom_1.feq_gen_dten_avda_d_[*feq_gen_dten_pnt_d_ - 
	    1];
/*     Compute how many average drainage areas fit into the total area */
/* SOURCE dtendlay.for:1103 */
/*<       qfac=total_area/dten_avda(dten_pnt) >*/
    *qfac = static_cast<double>(*feq_gen_total_area_d_) / tamcom_1.feq_gen_dten_avda_d_[*feq_gen_dten_pnt_d_ - 1];
/* SOURCE dtendlay.for:1104 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1105 */
/*<       end >*/
} /* compute_dten_pond_volume__ */




/* SOURCE dtendlay.for:1109 */
/*<        >*/
/* Subroutine */ int feq_gen_find_volume_coefficients_d_(integer *stdout, integer *
	feq_gen_dten_pnt_d_, real *grav, real *feq_gen_pond_volume_d_, integer *eflag, real *c1,
	 real *c2, real *c3, real *feq_gen_design_a_d_)
{
    /* Initialized data */

    static real pi = (float)3.1415927;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:353* Pond volume=\002,1pe10.3,\002 \
acre-feet <= \002,\002minimum\002,/,11x,\002 possible pond volume of:\002,1p\
e10.3,\002 acre-feet.\002)";
    static char fmt_52[] = "(/,\002 *ERR:354* Pond volume=\002,1pe10.3,\002 \
meter^3 <= \002,\002minimum\002,/,11x,\002 possible pond volume of:\002,1pe1\
0.3,\002 meter^3.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double sqrt(doublereal);

    /* Local variables */
    real r0, bz, yd, feq_gen_min_volume_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_52, 0 };


/*     Find the polynomial coefficients defining the pond */
/*     volume as a function of depth in the pond.  We assume */
/*     that there is always a conservation pool, that is, that */
/*     the area at zero depth is greater than zero. */
/* SOURCE dtendlay.for:1119 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:1120 */
/*<       integerstdout,dten_pnt,eflag >*/
/* SOURCE dtendlay.for:1122 */
/*<       realc1,c2,c3,grav,pond_volume,design_a >*/
/* INCLUDE dtendlay.for:1124 */
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
/* INCLUDE dtendlay.for:1125 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/* SOURCE dtendlay.for:1129 */
/*<       realr0,pi,bz,yd,min_volume >*/
/*     *******************************FORMATS**************************** */
/* SOURCE dtendlay.for:1132 */
/*<       datapi/3.1415927/ >*/
/* SOURCE dtendlay.for:1134 */
/*<    50  >*/
/* L50: */
/* SOURCE dtendlay.for:1137 */
/*<    52  >*/
/* L52: */
/* *********************************************************************** */
/*     Extract items from the detention storage data structure */
/* SOURCE dtendlay.for:1142 */
/*<       yd=dten_yd(dten_pnt) >*/
    yd = tamcom_1.feq_gen_dten_yd_d_[(676868 + (0 + (*feq_gen_dten_pnt_d_ - 1 << 2)) - 676868) /
	     4];
/* SOURCE dtendlay.for:1143 */
/*<       bz=dten_bz(dten_pnt) >*/
    bz = tamcom_1.feq_gen_dten_bz_d_[*feq_gen_dten_pnt_d_ - 1];
/*     Check that the base area is > 0. The volume is given by */
/*     V(Y) = PI*(R0^2*Y + R0*BZ*Y^2 + BZ^2*Y^3/3) where R0 is */
/*     the radius of the assumed circular base.  Thus if we */
/*     set R0 to zero and Y to YD and find that the computed */
/*     volume is larger than POND_VOLUME, then we KNOW that */
/*     the area of the base cannot be > than zero and the */
/*     given values, YD, BZ, and POND_VOLUME and the assumption */
/*     of the pond being a frustrum of a cone are inconsistent. */
/* SOURCE dtendlay.for:1154 */
/*<       min_volume=pi*bz**2*yd**3/3.0 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = bz;
/* Computing 3rd power */
    feq_gen_r_d_2 = yd;
    feq_gen_min_volume_d_ = static_cast<double>(static_cast<double>(static_cast<double>(pi) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / (float)3.;
/* SOURCE dtendlay.for:1155 */
/*<       if(min_volume.ge.pond_volume)then >*/
    if (feq_gen_min_volume_d_ >= *feq_gen_pond_volume_d_) {
/*       Inconsistent specification. */
/* SOURCE dtendlay.for:1157 */
/*<       if(grav.gt.15.0)then >*/
	if (*grav > (float)15.) {
/* SOURCE dtendlay.for:1158 */
/*<       write(stdout,50)pond_volume/43560.,min_volume/43560. >*/
	    feq_gen_io_d__90.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__90);
	    feq_gen_r_d_1 = static_cast<double>(*feq_gen_pond_volume_d_) / (float)43560.;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    feq_gen_r_d_2 = static_cast<double>(feq_gen_min_volume_d_) / (float)43560.;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE dtendlay.for:1159 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:1160 */
/*<       write(stdout,52)pond_volume,min_volume >*/
	    feq_gen_io_d__91.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__91);
	    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_pond_volume_d_), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_min_volume_d_, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE dtendlay.for:1161 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1162 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE dtendlay.for:1163 */
/*<       else >*/
    } else {
/*       Compute the coefficients. The value of R0 is given as one root */
/*       of the quadratic equation when the volume, depth, and */
/*       basin side slope are given. */
/* SOURCE dtendlay.for:1168 */
/*<       r0=-0.5*bz*yd+sqrt(pond_volume/(pi*yd)-(bz*yd)**2/12) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(bz) * yd;
	r0 = static_cast<double>(static_cast<double>(bz) * (float)-.5) * yd + sqrt(static_cast<double>(static_cast<double>(*feq_gen_pond_volume_d_) / (static_cast<double>(pi) * yd)) - static_cast<double>(static_cast<double>(feq_gen_r_d_1) * 
		feq_gen_r_d_1) / 12);
/*       Compute the coefficients of the polynomial. */
/* SOURCE dtendlay.for:1173 */
/*<       c1=pi*r0**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = r0;
	*c1 = static_cast<double>(pi) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE dtendlay.for:1174 */
/*<       c2=pi*r0*bz >*/
	*c2 = static_cast<double>(static_cast<double>(pi) * r0) * bz;
/* SOURCE dtendlay.for:1175 */
/*<       c3=pi*bz**2/3. >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = bz;
	*c3 = static_cast<double>(static_cast<double>(pi) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / (float)3.;
/* SOURCE dtendlay.for:1177 */
/*<       design_a=c1+yd*(2.*c2+yd*3.*c3) >*/
	*feq_gen_design_a_d_ = static_cast<double>(*c1) + static_cast<double>(yd) * (static_cast<double>(static_cast<double>(*c2) * (float)2.) + static_cast<double>(static_cast<double>(yd) * (float)3.) * *c3);
/* SOURCE dtendlay.for:1178 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:1179 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1180 */
/*<       end >*/
} /* find_volume_coefficients__ */




/* SOURCE dtendlay.for:1184 */
/*<        >*/
/* Subroutine */ int feq_gen_find_orifice_diameter_d_(integer *stdout, integer *
	feq_gen_dten_pnt_d_, integer *feq_gen_orf_tab_d_, real *grav, real *feq_gen_trib_area_d_, real *
	feq_gen_orifice_d_d_, real *feq_gen_design_q_d_, real *orfcon)
{
    /* Initialized data */

    static real pi = (float)3.1415927;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:110* Orifice diameter not found aft\
er 20 tries.\002)";

    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real feq_gen_d_d_, f, df, qd, td, yd, con, uaq, orf;
    integer knt, ntab;
    real dorf, orfcd;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real rootd, hoverd, feq_gen_delta_d_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_50, 0 };


/*     Find the orifice diameter that will pass the design flow */
/*     at the design depth. */
/* SOURCE dtendlay.for:1191 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:1192 */
/*<       integerstdout,dten_pnt,orf_tab >*/
/* SOURCE dtendlay.for:1194 */
/*<       realgrav,trib_area,orfcon,orifice_d,design_q >*/
/* INCLUDE dtendlay.for:1196 */
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
/* INCLUDE dtendlay.for:1197 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/* SOURCE dtendlay.for:1201 */
/*<       integerknt,ntab >*/
/* SOURCE dtendlay.for:1203 */
/*<       realuaq,qd,orfcd,d,pi,yd,f,df,orf,dorf,con,hoverd,rootd,delta_d,td >*/
/*     ****************************FORMATS******************************* */
/* SOURCE dtendlay.for:1206 */
/*<       datapi/3.1415927/ >*/
/* SOURCE dtendlay.for:1209 */
/*<    50 format(/,' *ERR:110* Orifice diameter not found after 20 tries.') >*/
/* L50: */
/* *********************************************************************** */
/*     Get the unit-area flow permitted. */
/* SOURCE dtendlay.for:1213 */
/*<       uaq=dten_uaq(dten_pnt) >*/
    uaq = tamcom_1.feq_gen_dten_uaq_d_[(878472 + (0 + (*feq_gen_dten_pnt_d_ - 1 << 2)) - 878472)
	     / 4];
/* SOURCE dtendlay.for:1214 */
/*<       qd=uaq*dten_avda(dten_pnt) >*/
    qd = static_cast<double>(uaq) * tamcom_1.feq_gen_dten_avda_d_[*feq_gen_dten_pnt_d_ - 1];
/* SOURCE dtendlay.for:1215 */
/*<       design_q=qd >*/
    *feq_gen_design_q_d_ = qd;
/*     Get the orifice discharge coefficient and design depth */
/* SOURCE dtendlay.for:1217 */
/*<       orfcd=dten_orfcd(dten_pnt) >*/
    orfcd = tamcom_1.feq_gen_dten_orfcd_d_[*feq_gen_dten_pnt_d_ - 1];
/* SOURCE dtendlay.for:1218 */
/*<       yd=dten_yd(dten_pnt) >*/
    yd = tamcom_1.feq_gen_dten_yd_d_[*feq_gen_dten_pnt_d_ - 1];
/*     Estimate the diameter of the orifice.  This estimate will be too */
/*     large since the base of the orifice is at depth zero and we */
/*     assume for estimation that the center of the orifice is at */
/*     depth zero. */
/* SOURCE dtendlay.for:1225 */
/*<       d=sqrt(4.*qd/(pi*orfcd*sqrt(2.*grav*yd))) >*/
    feq_gen_d_d_ = sqrt(static_cast<double>(qd) * (float)4. / (static_cast<double>(pi) * orfcd * sqrt(static_cast<double>(static_cast<double>(*grav) * (float)2.) * yd)));
/*     Now use Newton's method to find the final value of orifice */
/*     diameter. Compute the constant factor in the orfice flow */
/*     computation. */
/* SOURCE dtendlay.for:1232 */
/*<       con=orfcd*sqrt(2.*grav) >*/
    con = orfcd * sqrt(static_cast<double>(*grav) * (float)2.);
/* SOURCE dtendlay.for:1233 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE dtendlay.for:1234 */
/*<   100 continue >*/
L100:
/*       Compute flow through the orifice.  Get orifice flow */
/*       function values. */
/* SOURCE dtendlay.for:1239 */
/*<       hoverd=yd/d >*/
    hoverd = static_cast<double>(yd) / feq_gen_d_d_;
/* SOURCE dtendlay.for:1241 */
/*<       calllktab(orf_tab,hoverd,1,orf,ntab,dorf) >*/
    lktab_(feq_gen_orf_tab_d_, &hoverd, &feq_gen_c_d_1, &orf, &ntab, &dorf);
/*       Compute the residual function and its derivative with respect */
/*       to D.  We compute relative to QD to make convergence testing */
/*       easier.  Note that the value: 2.5*ORF - HOVERD*DORF proves */
/*       to be always  > 0 if D > 0.  This means that DF is < 0. */
/* SOURCE dtendlay.for:1250 */
/*<       rootd=sqrt(d) >*/
    rootd = sqrt(feq_gen_d_d_);
/* SOURCE dtendlay.for:1251 */
/*<       f=1.0-con*rootd*d**2*orf/qd >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = feq_gen_d_d_;
    f = static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(con) * rootd) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) * orf) / qd;
/* SOURCE dtendlay.for:1254 */
/*<       if(abs(f).gt.1.e-4)then >*/
    if (dabs(f) > (float)1e-4) {
/* SOURCE dtendlay.for:1255 */
/*<       df=-con*rootd*d*(2.5*orf-hoverd*dorf)/qd >*/
	df = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(-con) * rootd) * feq_gen_d_d_) * (static_cast<double>(static_cast<double>(orf) * (float)2.5) - static_cast<double>(hoverd) * dorf)) / qd;
/*         Compute a correction to D */
/* SOURCE dtendlay.for:1259 */
/*<       delta_d=-f/df >*/
	feq_gen_delta_d_d_ = static_cast<double>(-f) / df;
/* SOURCE dtendlay.for:1260 */
/*<       if(abs(delta_d/d).gt.1.e-4)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(feq_gen_delta_d_d_) / feq_gen_d_d_, dabs(feq_gen_r_d_1)) > (float)1e-4) {
/*           Compute the next value of D */
/* SOURCE dtendlay.for:1262 */
/*<       td=d+delta_d >*/
	    td = static_cast<double>(feq_gen_d_d_) + feq_gen_delta_d_d_;
/* SOURCE dtendlay.for:1263 */
/*<       if(td.le.0.0)then >*/
	    if (td <= (float)0.) {
/* SOURCE dtendlay.for:1264 */
/*<       td=0.5*d >*/
		td = static_cast<double>(feq_gen_d_d_) * (float).5;
/* SOURCE dtendlay.for:1265 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:1266 */
/*<       d=td >*/
	    feq_gen_d_d_ = td;
/* SOURCE dtendlay.for:1267 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE dtendlay.for:1268 */
/*<       if(knt.gt.20)then >*/
	    if (knt > 20) {
/* SOURCE dtendlay.for:1269 */
/*<       write(stdout,50) >*/
		feq_gen_io_d__110.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__110);
		e_wsfe();
/* SOURCE dtendlay.for:1270 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:1271 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:1272 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE dtendlay.for:1273 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1274 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:1276 */
/*<       orifice_d=d >*/
    *feq_gen_orifice_d_d_ = feq_gen_d_d_;
/* SOURCE dtendlay.for:1277 */
/*<       orfcon=orfcd*sqrt(d*2.*grav)*d**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = feq_gen_d_d_;
    *orfcon = orfcd * sqrt(static_cast<double>(static_cast<double>(feq_gen_d_d_) * (float)2.) * *grav) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE dtendlay.for:1278 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1279 */
/*<       end >*/
} /* find_orifice_diameter__ */




/* SOURCE dtendlay.for:1284 */
/*<       subroutinefind_chebyshev_points(n,a,b,y) >*/
/* Subroutine */ int feq_gen_find_chebyshev_points_d_(integer *n, real *a, real *b, 
	real *feq_storage_y)
{
    /* Initialized data */

    static real pi = (float)3.1415927;

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    double cos(doublereal);

    /* Local variables */
    integer j;
    real fn, cona, conb, aplusb;

/*     For the interval [A, B] compute the N expanded Chebyshev */
/*     points. */
/* SOURCE dtendlay.for:1290 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:1291 */
/*<       integern >*/
/* SOURCE dtendlay.for:1293 */
/*<       reala,b,y(n) >*/
/*     Local */
/* SOURCE dtendlay.for:1297 */
/*<       integerj >*/
/* SOURCE dtendlay.for:1298 */
/*<       realpi,cona,conb,fn,aplusb >*/
/* *********************************************************************** */
/*     Avoid roundoff at the end points. */
/* SOURCE dtendlay.for:1300 */
/*<       datapi/3.1415927/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> y(feq_storage_y, 1);

    /* Function Body */
/* SOURCE dtendlay.for:1303 */
/*<       if(n.lt.2)then >*/
    if (*n < 2) {
/* SOURCE dtendlay.for:1304 */
/*<       stop' Abnormal stop. Bug found by FIND_CHEBYSHEV_POINTS' >*/
	s_stop(const_cast<char*>(" Abnormal stop. Bug found by FIND_CHEBYSHEV_POINTS"), (ftnlen)
		50);
/* SOURCE dtendlay.for:1305 */
/*<       elseif(n.eq.2)then >*/
    } else if (*n == 2) {
/* SOURCE dtendlay.for:1306 */
/*<       y(1)=a >*/
	y[1] = *a;
/* SOURCE dtendlay.for:1307 */
/*<       y(2)=b >*/
	y[2] = *b;
/* SOURCE dtendlay.for:1308 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:1309 */
/*<       y(1)=a >*/
	y[1] = *a;
/* SOURCE dtendlay.for:1310 */
/*<       y(n)=b >*/
	y[*n] = *b;
/* SOURCE dtendlay.for:1311 */
/*<       fn=real(n) >*/
	fn = (real) (*n);
/* SOURCE dtendlay.for:1312 */
/*<       cona=pi/(fn+fn) >*/
	cona = static_cast<double>(pi) / (static_cast<double>(fn) + fn);
/* SOURCE dtendlay.for:1313 */
/*<       aplusb=a+b >*/
	aplusb = static_cast<double>(*a) + *b;
/* SOURCE dtendlay.for:1314 */
/*<       conb=(b-a)/cos(cona) >*/
	conb = (static_cast<double>(*b) - *a) / cos(cona);
/* SOURCE dtendlay.for:1315 */
/*<       do100j=2,n-1 >*/
	feq_gen_i_d_1 = *n - 1;
	for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE dtendlay.for:1316 */
/*<       y(j)=0.5*(aplusb-conb*cos(real(2*j-1)*cona)) >*/
	    y[j] = (aplusb - conb * cos(static_cast<double>((real) ((j << 1) - 1)) * cona)) * (
		    float).5;
/* SOURCE dtendlay.for:1317 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE dtendlay.for:1318 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:1319 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1320 */
/*<       end >*/
} /* find_chebyshev_points__ */




/* SOURCE dtendlay.for:1324 */
/*<        >*/
/* Subroutine */ int feq_gen_find_pond_routing_table_d_(integer *stdout, integer *
	feq_gen_dten_pnt_d_, integer *feq_gen_orf_tab_d_, real *grav, real *feq_gen_orifice_d_d_, real *
	orfcon, real *c1, real *c2, real *c3, integer *ftp, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real a, feq_gen_h_d_;
    integer j, m;
    real q[50], v, y[55];
    integer n1, n2, n3;
    real dq[50], ya, wc, yd, yt[50], wz;
    integer feq_gen_tab_number_d_;
    real arg[50], orf;
    integer feq_gen_tab_address_d_, ntab;
    real dorf, qorf;
    extern /* Subroutine */ int put1d_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *), lktab_(
	    integer *, real *, integer *, real *, integer *, real *);
    real dqorf;
    extern integer nextn_();
    extern /* Subroutine */ int feq_gen_find_chebyshev_points_d_(integer *, real *, 
	    real *, real *);
    real hoverd, qspill, weircon, dqspill;

/*     Compute the routing table for the detention basin.  The table */
/*     is of type 4 with an argument of basin volume, and with function */
/*     values of flow and the derivative of flow wrt volume. */
/* SOURCE dtendlay.for:1332 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:1333 */
/*<       integerstdout,dten_pnt,ftp,orf_tab,eflag >*/
/* SOURCE dtendlay.for:1335 */
/*<       realorifice_d,orfcon,c1,c2,c3,grav >*/
/* INCLUDE dtendlay.for:1337 */
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
/* INCLUDE dtendlay.for:1338 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/* SOURCE dtendlay.for:1342 */
/*<       integerj,m,n1,n2,n3,ntab,tab_number,tab_address >*/
/* SOURCE dtendlay.for:1344 */
/*<        >*/
/*     Called program units */
/* SOURCE dtendlay.for:1351 */
/*<       integernextn >*/
/* SOURCE dtendlay.for:1353 */
/*<       externalnextn >*/
/*     *******************************Formats**************************** */
/* SOURCE dtendlay.for:1355 */
/*<    50 format(1x,1pe14.6,1pe14.6,1pe14.6,1pe14.6) >*/
/* SOURCE dtendlay.for:1356 */
/*<    52 format(1x,'    Pond Depth   Pond Volume  Pond Outflow    DQ/DV') >*/
/* *********************************************************************** */
/*     Get values from data structure */
/* SOURCE dtendlay.for:1359 */
/*<       yd=dten_yd(dten_pnt) >*/
/* L50: */
/* L52: */
    yd = tamcom_1.feq_gen_dten_yd_d_[*feq_gen_dten_pnt_d_ - 1];
/* SOURCE dtendlay.for:1360 */
/*<       wc=dten_wc(dten_pnt) >*/
    wc = tamcom_1.feq_gen_dten_wc_d_[*feq_gen_dten_pnt_d_ - 1];
/* SOURCE dtendlay.for:1361 */
/*<       wz=dten_wz(dten_pnt) >*/
    wz = tamcom_1.feq_gen_dten_wz_d_[*feq_gen_dten_pnt_d_ - 1];
/*     Compute the weir coefficient. See page 32 of Bos.  We ignore velocity */
/*     of approach since this is an overflow from a basin of some depth. */
/*     Overflow depths are proabably small, maybe less than 10 per cent of */
/*     the design depth. */
/* SOURCE dtendlay.for:1368 */
/*<       weircon=0.64*wc*wz*sqrt(.4*grav) >*/
    weircon = static_cast<double>(static_cast<double>(wc) * (float).64) * wz * sqrt(static_cast<double>(*grav) * (float).4);
/*     The table will be constructed from a series of depth values designed */
/*     to fairly represent the relationship between storage in the pond and */
/*     outflow from the pond.  We will use three different applications */
/*     of the expanded Chebyshev point set.  The first set will be applied */
/*     in the depth range 0 to ORIFICE_D, the second set will be */
/*     applied from ORIFICE_D to YD, the final set will apply from YD to */
/*     1.5*YD. */
/*     We will place 11 points across [0,ORIFICE_D] */
/* SOURCE dtendlay.for:1380 */
/*<       n1=11 >*/
    n1 = 11;
/* SOURCE dtendlay.for:1381 */
/*<       callfind_chebyshev_points(n1,0.0,orifice_d,y) >*/
    feq_gen_find_chebyshev_points_d_(&n1, &c_b226, feq_gen_orifice_d_d_, y);
/*     Use 21 points across [ORIFICE_D, YD].  The first point will */
/*     be the same as the last point in the previous interval. */
/* SOURCE dtendlay.for:1386 */
/*<       n2=21 >*/
    n2 = 21;
/* SOURCE dtendlay.for:1387 */
/*<       callfind_chebyshev_points(n2,orifice_d,yd,yt) >*/
    feq_gen_find_chebyshev_points_d_(&n2, feq_gen_orifice_d_d_, &yd, yt);
/* SOURCE dtendlay.for:1389 */
/*<       do100j=2,n2 >*/
    feq_gen_i_d_1 = n2;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE dtendlay.for:1390 */
/*<       y(j+n1-1)=yt(j) >*/
	y[j + n1 - 2] = yt[j - 1];
/* SOURCE dtendlay.for:1391 */
/*<   100 continue >*/
/* L100: */
    }
/*     Flow over the spillway begins and increases rapidly.  Use */
/*     extra points and then go only halfway into the interval. */
/* SOURCE dtendlay.for:1395 */
/*<       n3=39 >*/
    n3 = 39;
/* SOURCE dtendlay.for:1396 */
/*<       callfind_chebyshev_points(n3,yd,2.*yd,yt) >*/
    feq_gen_r_d_1 = static_cast<double>(yd) * (float)2.;
    feq_gen_find_chebyshev_points_d_(&n3, &yd, &feq_gen_r_d_1, yt);
/* SOURCE dtendlay.for:1398 */
/*<       do110j=2,n3/2+1 >*/
    feq_gen_i_d_1 = n3 / 2 + 1;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE dtendlay.for:1399 */
/*<       y(j+n2+n1-2)=yt(j) >*/
	y[j + n2 + n1 - 3] = yt[j - 1];
/* SOURCE dtendlay.for:1400 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE dtendlay.for:1401 */
/*<       m=n1+n2-1+n3/2 >*/
    m = n1 + n2 - 1 + n3 / 2;
/*      WRITE(STDOUT,*) ' CHECK POINT SET FOR ROUTING TABLE. M=',M */
/*      DO 130 J=1,M */

/*        WRITE(STDOUT,*) 'J=',J,' Y(J)=',Y(J) */
/* 130   CONTINUE */
/*      WRITE(STDOUT,52) */
/*     Now we can finally compute the table values. */
/* SOURCE dtendlay.for:1410 */
/*<       do150j=1,m >*/
    feq_gen_i_d_1 = m;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE dtendlay.for:1411 */
/*<       ya=y(j) >*/
	ya = y[j - 1];
/*       Get the volume at this depth */
/* SOURCE dtendlay.for:1413 */
/*<       v=ya*(c1+ya*(c2+c3*ya)) >*/
	v = static_cast<double>(ya) * (static_cast<double>(*c1) + static_cast<double>(ya) * (static_cast<double>(*c2) + static_cast<double>(*c3) * ya));
/*       Get the surface area at this depth */
/* SOURCE dtendlay.for:1415 */
/*<       a=c1+ya*(2.0*c2+ya*3.0*c3) >*/
	a = static_cast<double>(*c1) + static_cast<double>(ya) * (static_cast<double>(static_cast<double>(*c2) * (float)2.) + static_cast<double>(static_cast<double>(ya) * (float)3.) * *c3);
/*       Compute the flow and its derivative with respect */
/*       to depth. We always have flow through the orifice. */
/* SOURCE dtendlay.for:1419 */
/*<       hoverd=ya/orifice_d >*/
	hoverd = static_cast<double>(ya) / *feq_gen_orifice_d_d_;
/* SOURCE dtendlay.for:1420 */
/*<       calllktab(orf_tab,hoverd,1,orf,ntab,dorf) >*/
	lktab_(feq_gen_orf_tab_d_, &hoverd, &feq_gen_c_d_1, &orf, &ntab, &dorf);
/* SOURCE dtendlay.for:1423 */
/*<       qorf=orfcon*orf >*/
	qorf = static_cast<double>(*orfcon) * orf;
/* SOURCE dtendlay.for:1424 */
/*<       dqorf=orfcon*dorf/orifice_d >*/
	dqorf = static_cast<double>(static_cast<double>(*orfcon) * dorf) / *feq_gen_orifice_d_d_;
/* SOURCE dtendlay.for:1425 */
/*<       if(ya.gt.yd)then >*/
	if (ya > yd) {
/*         Compute flow over spillway. */
/* SOURCE dtendlay.for:1427 */
/*<       h=ya-yd >*/
	    feq_gen_h_d_ = static_cast<double>(ya) - yd;
/* SOURCE dtendlay.for:1428 */
/*<       qspill=weircon*sqrt(h)*h**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = feq_gen_h_d_;
	    qspill = weircon * sqrt(feq_gen_h_d_) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE dtendlay.for:1429 */
/*<       dqspill=2.5*weircon*sqrt(h)*h >*/
	    dqspill = static_cast<double>(weircon) * (float)2.5 * sqrt(feq_gen_h_d_) * feq_gen_h_d_;
/* SOURCE dtendlay.for:1431 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:1432 */
/*<       qspill=0.0 >*/
	    qspill = (float)0.;
/* SOURCE dtendlay.for:1433 */
/*<       dqspill=0.0 >*/
	    dqspill = (float)0.;
/* SOURCE dtendlay.for:1434 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1436 */
/*<       q(j)=qorf+qspill >*/
	q[j - 1] = static_cast<double>(qorf) + qspill;
/*       Convert derivative wrt y to wrt volume. */
/* SOURCE dtendlay.for:1439 */
/*<       dq(j)=(dqorf+dqspill)/a >*/
	dq[j - 1] = static_cast<double>((static_cast<double>(dqorf) + dqspill)) / a;
/* SOURCE dtendlay.for:1441 */
/*<       arg(j)=v >*/
	arg[j - 1] = v;
/*        WRITE(STDOUT,50) Y(J), ARG(J), Q(J), DQ(J) */
/* SOURCE dtendlay.for:1443 */
/*<   150 continue >*/
/* L150: */
    }
/*     Get an available table number for the table. */
/* SOURCE dtendlay.for:1447 */
/*<       tab_number=nextn() >*/
    feq_gen_tab_number_d_ = nextn_();
/* SOURCE dtendlay.for:1448 */
/*<       callput1d(stdout,tab_number,4,m,arg,q,dq,ftp,tab_address) >*/
    put1d_(stdout, &feq_gen_tab_number_d_, &feq_gen_c_d_4, &m, arg, q, dq, ftp, &feq_gen_tab_address_d_);
/*     Store the routing table address. */
/* SOURCE dtendlay.for:1454 */
/*<       dten_rout_tab(dten_pnt)=tab_address >*/
    tamcom_1.feq_gen_dten_rout_tab_d_[*feq_gen_dten_pnt_d_ - 1] = feq_gen_tab_address_d_;
/* SOURCE dtendlay.for:1455 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1456 */
/*<       end >*/
} /* find_pond_routing_table__ */




/* SOURCE dtendlay.for:1460 */
/*<        >*/
/* Subroutine */ int feq_gen_compute_detention_description_d_(integer *stdout, real *
	grav, integer *feq_storage_ftpnt, integer *nbra, integer *feq_storage_brpt, integer *ftp, 
	integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:98* Orifice-flow table id= \002,a\
,\002 is type=\002,i3,\002.  Expected type 4.\002)";
    static char fmt_52[] = "(/,\002 Summary of Detention Basins\002,//,\002 \
 Trib    Ups    Dsn      Imp.    Design    Design      Base\002,\002    Desi\
gn    Design   Orifice Routing   Basin\002,/,\002 to ID   node   node  fract\
ion     depth    volume      area\002,\002      area      flow  diameter tab\
le#    count\002,/,34x,a6,2x,a8,2x,a8,2x,a8,2x,a8,4x,a6,/,\002 ----- ------ \
------ --------- --------- --------- ---------\002,\002 --------- --------- \
--------- ------- -------\002)";
    static char fmt_54[] = "(i6,2i7,f10.3,f10.1,1pe10.3,1pe10.3,1pe10.3,0pf1\
0.2,f10.3,i8,f8.2)";
    static char fmt_56[] = "(i6,2i7,f10.3,f10.2,1pe10.3,1pe10.3,1pe10.3,0pf1\
0.3,f10.4,i8,f8.2)";
    static char fmt_58[] = "(1x,a5,14x,f10.3,f10.1,1pe10.3,1pe10.3,1pe10.3,0\
pf10.2,f10.3,i8,f8.2)";
    static char fmt_60[] = "(1x,a5,14x,f10.3,f10.1,1pe10.3,0pf10.3,1pe10.3,1\
pe10.3,f10.4,i8,f8.2)";
    static char fmt_62[] = "(/,\002  Unit-area detention volume table is mis\
sing.\002,\002  Make sure DETAIN.TAB is in the list of files \002,\002for fu\
nction tables.\002)";
    static char fmt_64[] = "(/,\002 Orifice-flow table missing.\002,\002  Ma\
ke sure DETAIN.TAB is in the list of files \002,\002for function tables.\002)"
	    ;

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3, feq_gen_i_d_4;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    real feq_gen_design_a_d_;
    extern /* Subroutine */ int feq_gen_find_pond_routing_table_d_(integer *, integer *
	    , integer *, real *, real *, real *, real *, real *, real *, 
	    integer *, integer *);
    integer feq_gen_uadv_tab_d_;
    real feq_gen_design_q_d_;
    integer feq_gen_dten_pnt_d_;
    real feq_gen_conv_out_d_;
    integer feq_gen_unit_pnt_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real feq_gen_orifice_d_d_;
    extern /* Subroutine */ int feq_gen_find_volume_coefficients_d_(integer *, integer 
	    *, real *, real *, integer *, real *, real *, real *, real *);
    real feq_gen_trib_area_d_, c1, c2, c3;
    char feq_gen_area_unit_d_[8];
    extern /* Subroutine */ int feq_gen_compute_dten_pond_volume_d_(integer *, integer 
	    *, integer *, integer *, real *, real *, real *, real *, real *);
    char feq_gen_flow_unit_d_[8], feq_gen_length_unit_d_[6];
    real feq_gen_pond_volume_d_;
    char feq_gen_volume_unit_d_[8];
    real qfac;
    integer ibra;
    real feq_gen_imp_fraction_d_;
    integer feq_gen_node_convert_d_, fnode, lnode;
    extern /* Subroutine */ int feq_gen_find_orifice_diameter_d_(integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *), chktab_(
	    integer *, integer *, integer *, integer *, integer *, integer *);
    extern integer gettbn_(integer *);
    real orfcon;
    extern integer getusb_(integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern integer gettyp_(integer *);
    integer feq_gen_orf_tab_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__150 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__173 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__174 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__175 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__176 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__177 = { 0, 0, 0, 0, 0 };


/*     Compute the description for each detention pond.  In */
/*     that process the validity of the input will be checked */
/*     and errors reported. */
/* SOURCE dtendlay.for:1468 */
/*<       implicitnone >*/
/* INCLUDE dtendlay.for:1469 */
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
/* SOURCE dtendlay.for:1470 */
/*<       integerstdout,eflag,ftp,nbra >*/
/* SOURCE dtendlay.for:1471 */
/*<       integerftpnt(mftnum),brpt(8,nbra) >*/
/* SOURCE dtendlay.for:1473 */
/*<       realgrav >*/
/* INCLUDE dtendlay.for:1475 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Called program units */
/* SOURCE dtendlay.for:1478 */
/*<       charactergetusn*5,get_tabid*16 >*/
/* SOURCE dtendlay.for:1479 */
/*<       integergettyp,gettbn,getusb >*/
/* SOURCE dtendlay.for:1481 */
/*<        >*/
/*     Local */
/* SOURCE dtendlay.for:1486 */
/*<        >*/
/* SOURCE dtendlay.for:1489 */
/*<        >*/
/* SOURCE dtendlay.for:1492 */
/*<        >*/
/*     *****************************FORMATS****************************** */
/* SOURCE dtendlay.for:1498 */
/*<    50  >*/
/* SOURCE dtendlay.for:1501 */
/*<    52  >*/
/* SOURCE dtendlay.for:1509 */
/*<    54  >*/
/* SOURCE dtendlay.for:1511 */
/*<    56  >*/
/* SOURCE dtendlay.for:1513 */
/*<    58  >*/
/* SOURCE dtendlay.for:1515 */
/*<    60  >*/
/* SOURCE dtendlay.for:1517 */
/*<    62  >*/
/* SOURCE dtendlay.for:1520 */
/*<    64  >*/
/* *********************************************************************** */
/* SOURCE dtendlay.for:1525 */
/*<       if(dten_knt.gt.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
    if (tamcom_1.feq_gen_dten_knt_d_ > 0) {
/* SOURCE dtendlay.for:1526 */
/*<       if(grav.gt.15.0)then >*/
	if (*grav > (float)15.) {
/* SOURCE dtendlay.for:1527 */
/*<       conv_out=43560. >*/
	    feq_gen_conv_out_d_ = (float)43560.;
/* SOURCE dtendlay.for:1528 */
/*<       length_unit=' (ft)' >*/
	    s_copy(feq_gen_length_unit_d_, const_cast<char*>(" (ft)"), (ftnlen)6, (ftnlen)5);
/* SOURCE dtendlay.for:1529 */
/*<       volume_unit=' (ac-ft)' >*/
	    s_copy(feq_gen_volume_unit_d_, const_cast<char*>(" (ac-ft)"), (ftnlen)8, (ftnlen)8);
/* SOURCE dtendlay.for:1530 */
/*<       area_unit=' (acres)' >*/
	    s_copy(feq_gen_area_unit_d_, const_cast<char*>(" (acres)"), (ftnlen)8, (ftnlen)8);
/* SOURCE dtendlay.for:1531 */
/*<       flow_unit='(ft^3/s)' >*/
	    s_copy(feq_gen_flow_unit_d_, const_cast<char*>("(ft^3/s)"), (ftnlen)8, (ftnlen)8);
/* SOURCE dtendlay.for:1532 */
/*<       else >*/
	} else {
/* SOURCE dtendlay.for:1533 */
/*<       conv_out=1.0 >*/
	    feq_gen_conv_out_d_ = (float)1.;
/* SOURCE dtendlay.for:1534 */
/*<       length_unit=' (m)  ' >*/
	    s_copy(feq_gen_length_unit_d_, const_cast<char*>(" (m)  "), (ftnlen)6, (ftnlen)6);
/* SOURCE dtendlay.for:1535 */
/*<       volume_unit='  (m^3) ' >*/
	    s_copy(feq_gen_volume_unit_d_, const_cast<char*>("  (m^3) "), (ftnlen)8, (ftnlen)8);
/* SOURCE dtendlay.for:1536 */
/*<       area_unit='  (m^2) ' >*/
	    s_copy(feq_gen_area_unit_d_, const_cast<char*>("  (m^2) "), (ftnlen)8, (ftnlen)8);
/* SOURCE dtendlay.for:1537 */
/*<       flow_unit=' (m^3/s)' >*/
	    s_copy(feq_gen_flow_unit_d_, const_cast<char*>(" (m^3/s)"), (ftnlen)8, (ftnlen)8);
/* SOURCE dtendlay.for:1538 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1539 */
/*<        >*/
	feq_gen_io_d__150.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__150);
	do_fio(&feq_gen_c_d_1, feq_gen_length_unit_d_, (ftnlen)6);
	do_fio(&feq_gen_c_d_1, feq_gen_volume_unit_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_area_unit_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_area_unit_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_flow_unit_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_length_unit_d_, (ftnlen)6);
	e_wsfe();
/*       Traverse the trib-area management structure and check and compute */
/*       the values needed for modeling detention ponds.  All ponds are */
/*       assumed free of downstream influence on flow. */
/* SOURCE dtendlay.for:1545 */
/*<       unit_pnt=1 >*/
	feq_gen_unit_pnt_d_ = 1;
/* SOURCE dtendlay.for:1547 */
/*<   100 continue >*/
L100:
/* SOURCE dtendlay.for:1548 */
/*<       dten_pnt=tam_itab(unit_pnt+5) >*/
	feq_gen_dten_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 4];
/* SOURCE dtendlay.for:1549 */
/*<       if(dten_pnt.gt.0)then >*/
	if (feq_gen_dten_pnt_d_ > 0) {
/*           There are detention ponds in this unit.  Do the following: */
/*           1. Check that the unit-area-detention volume table exists */
/*              and is the correct type. */
/*           2. Check that the orifice flow table exists and is the */
/*              correct type. */
/*           If both of these are ok then */
/*           3. Compute the description of the detention storage. */
/*           This description will consist of an internally generated */
/*           table of type 4 with argument of detention storage and */
/*           function values of outflow and rate of change of outflow */
/*           with respect to storage. Upon succesful completion, */
/*           the pointer to detention storage will be replaced */
/*           by the address of this table. */
/* SOURCE dtendlay.for:1565 */
/*<       uadv_tab=dten_uadv_tab(dten_pnt) >*/
	    feq_gen_uadv_tab_d_ = tamcom_1.feq_gen_dten_uadv_tab_d_[feq_gen_dten_pnt_d_ - 1];
/*            WRITE(KEY,'(I10)') UADV_TAB */
/*            CALL STRIP_L_BLANKS( */
/*     M                          KEY) */
/*            CALL GET_INTERNAL_TAB_NUMBER */
/*     I                                  (STDOUT, KEY, */
/*     M                                   EFLAG, */
/*     O                                   UADV_TAB) */
/* SOURCE dtendlay.for:1573 */
/*<       orf_tab=dten_orf_tab(dten_pnt) >*/
	    feq_gen_orf_tab_d_ = tamcom_1.feq_gen_dten_orf_tab_d_[feq_gen_dten_pnt_d_ - 1];
/*            WRITE(KEY,'(I10)') ORF_TAB */
/*            CALL STRIP_L_BLANKS( */
/*     M                          KEY) */
/*            CALL GET_INTERNAL_TAB_NUMBER */
/*     I                                  (STDOUT, KEY, */
/*     M                                   EFLAG, */
/*     O                                   ORF_TAB) */
/* SOURCE dtendlay.for:1582 */
/*<       callchktab(10,stdout,ftpnt,mftnum,uadv_tab,eflag) >*/
	    chktab_(&feq_gen_c_d_10, stdout, &ftpnt[1], &feq_gen_c_d_10002, &feq_gen_uadv_tab_d_, eflag);
/* SOURCE dtendlay.for:1585 */
/*<       if(eflag.gt.0)then >*/
	    if (*eflag > 0) {
/* SOURCE dtendlay.for:1586 */
/*<       write(stdout,62) >*/
		feq_gen_io_d__155.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__155);
		e_wsfe();
/* SOURCE dtendlay.for:1587 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:1588 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:1589 */
/*<       callchktab(2,stdout,ftpnt,mftnum,orf_tab,eflag) >*/
	    chktab_(&feq_gen_c_d_2, stdout, &ftpnt[1], &feq_gen_c_d_10002, &feq_gen_orf_tab_d_, eflag);
/* SOURCE dtendlay.for:1592 */
/*<       if(eflag.eq.0)then >*/
	    if (*eflag == 0) {
/*             Must have type 4. */
/* SOURCE dtendlay.for:1594 */
/*<       if(gettyp(orf_tab).ne.4)then >*/
		if (gettyp_(&feq_gen_orf_tab_d_) != 4) {
/* SOURCE dtendlay.for:1595 */
/*<       write(stdout,50)get_tabid(gettbn(orf_tab)),gettyp(orf_tab) >*/
		    feq_gen_io_d__156.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__156);
		    feq_gen_i_d_1 = gettbn_(&feq_gen_orf_tab_d_);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_1);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		    feq_gen_i_d_2 = gettyp_(&feq_gen_orf_tab_d_);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE dtendlay.for:1597 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:1598 */
/*<       endif >*/
		}
/* SOURCE dtendlay.for:1599 */
/*<       else >*/
	    } else {
/* SOURCE dtendlay.for:1600 */
/*<       write(stdout,64) >*/
		feq_gen_io_d__157.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__157);
		e_wsfe();
/* SOURCE dtendlay.for:1601 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:1602 */
/*<       endif >*/
	    }
/*           Compute the reqired pond volume. */
/* SOURCE dtendlay.for:1606 */
/*<        >*/
	    feq_gen_compute_dten_pond_volume_d_(stdout, &feq_gen_dten_pnt_d_, &feq_gen_uadv_tab_d_, &
		    feq_gen_unit_pnt_d_, grav, &feq_gen_pond_volume_d_, &feq_gen_trib_area_d_, &qfac, &
		    feq_gen_imp_fraction_d_);
/*           Given the pond volume, the design depth, and the basin */
/*           side slope and the assumption that the pond is an */
/*           inverted frustrum of a cone, compute the coefficients */
/*           that define the variation of volume from zero at */
/*           a depth of zero to POND_VOLUME at the design depth. */
/* SOURCE dtendlay.for:1616 */
/*<        >*/
	    feq_gen_find_volume_coefficients_d_(stdout, &feq_gen_dten_pnt_d_, grav, &
		    feq_gen_pond_volume_d_, eflag, &c1, &c2, &c3, &feq_gen_design_a_d_);
/*           Compute the orifice diameter. */
/* SOURCE dtendlay.for:1622 */
/*<        >*/
	    feq_gen_find_orifice_diameter_d_(stdout, &feq_gen_dten_pnt_d_, &feq_gen_orf_tab_d_, grav, &
		    feq_gen_trib_area_d_, &feq_gen_orifice_d_d_, &feq_gen_design_q_d_, &orfcon);
/*           Compute the type 4 table with storage volume as argument */
/*           and flow and its derivative as the two values tabulated. */
/* SOURCE dtendlay.for:1628 */
/*<        >*/
	    feq_gen_find_pond_routing_table_d_(stdout, &feq_gen_dten_pnt_d_, &feq_gen_orf_tab_d_, grav, &
		    feq_gen_orifice_d_d_, &orfcon, &c1, &c2, &c3, ftp, eflag);
/*           Compute the average number of ponds. Reuse DTEN_AVDA for */
/*           this. */
/* SOURCE dtendlay.for:1634 */
/*<       dten_avda(dten_pnt)=qfac >*/
	    tamcom_1.feq_gen_dten_avda_d_[feq_gen_dten_pnt_d_ - 1] = qfac;
/*           Output a summary for this unit. */
/* SOURCE dtendlay.for:1637 */
/*<       if(tam_itab(unit_pnt+1).eq.1)then >*/
	    if (tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_] == 1) {
/*             Tributary to a branch. */
/* SOURCE dtendlay.for:1639 */
/*<       fnode=tam_itab(unit_pnt+7) >*/
		fnode = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 6];
/* SOURCE dtendlay.for:1640 */
/*<       lnode=tam_itab(unit_pnt+8) >*/
		lnode = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 7];
/*             Get offset to convert from internal node number to */
/*             the user node number. */
/* SOURCE dtendlay.for:1643 */
/*<       ibra=tam_itab(unit_pnt) >*/
		ibra = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ - 1];
/* SOURCE dtendlay.for:1644 */
/*<       node_convert=brpt(1,ibra)-brpt(3,ibra) >*/
		feq_gen_node_convert_d_ = brpt[(ibra << 3) + 1] - brpt[(ibra << 3) + 3]
			;
/* SOURCE dtendlay.for:1646 */
/*<       if(grav.gt.15.0)then >*/
		if (*grav > (float)15.) {
/* SOURCE dtendlay.for:1647 */
/*<        >*/
		    feq_gen_io_d__173.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__173);
		    feq_gen_i_d_1 = getusb_(&ibra);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		    feq_gen_i_d_2 = fnode + feq_gen_node_convert_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		    feq_gen_i_d_3 = lnode + feq_gen_node_convert_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_imp_fraction_d_, (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_yd_d_[feq_gen_dten_pnt_d_ - 1],
			     (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(feq_gen_pond_volume_d_) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    feq_gen_r_d_2 = static_cast<double>(c1) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
		    feq_gen_r_d_3 = static_cast<double>(feq_gen_design_a_d_) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_design_q_d_, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_orifice_d_d_, (ftnlen)sizeof(real));
		    feq_gen_i_d_4 = gettbn_(&tamcom_1.feq_gen_dten_rout_tab_d_[feq_gen_dten_pnt_d_ - 1]);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_4, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&qfac, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE dtendlay.for:1654 */
/*<       else >*/
		} else {
/* SOURCE dtendlay.for:1655 */
/*<        >*/
		    feq_gen_io_d__174.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__174);
		    feq_gen_i_d_1 = getusb_(&tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ - 1]);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		    feq_gen_i_d_2 = fnode + feq_gen_node_convert_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		    feq_gen_i_d_3 = lnode + feq_gen_node_convert_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_imp_fraction_d_, (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_yd_d_[feq_gen_dten_pnt_d_ - 1],
			     (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(feq_gen_pond_volume_d_) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    feq_gen_r_d_2 = static_cast<double>(c1) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
		    feq_gen_r_d_3 = static_cast<double>(feq_gen_design_a_d_) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_design_q_d_, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_orifice_d_d_, (ftnlen)sizeof(real));
		    feq_gen_i_d_4 = gettbn_(&tamcom_1.feq_gen_dten_rout_tab_d_[feq_gen_dten_pnt_d_ - 1]);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_4, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&qfac, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE dtendlay.for:1662 */
/*<       endif >*/
		}
/* SOURCE dtendlay.for:1664 */
/*<       elseif(tam_itab(unit_pnt+1).eq.2)then >*/
	    } else if (tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_] == 2) {
/*             Tributary to a level-pool reservoir. */
/* SOURCE dtendlay.for:1666 */
/*<       if(grav.gt.15.0)then >*/
		if (*grav > (float)15.) {
/* SOURCE dtendlay.for:1667 */
/*<        >*/
		    feq_gen_io_d__175.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__175);
		    getusn_(feq_gen_ch_d_4, (ftnlen)5, &tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ 
			    - 1]);
		    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_imp_fraction_d_, (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_yd_d_[feq_gen_dten_pnt_d_ - 1],
			     (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(feq_gen_pond_volume_d_) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    feq_gen_r_d_2 = static_cast<double>(c1) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
		    feq_gen_r_d_3 = static_cast<double>(feq_gen_design_a_d_) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_design_q_d_, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_orifice_d_d_, (ftnlen)sizeof(real));
		    feq_gen_i_d_1 = gettbn_(&tamcom_1.feq_gen_dten_rout_tab_d_[feq_gen_dten_pnt_d_ - 1]);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&qfac, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE dtendlay.for:1674 */
/*<       else >*/
		} else {
/* SOURCE dtendlay.for:1675 */
/*<        >*/
		    feq_gen_io_d__176.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__176);
		    getusn_(feq_gen_ch_d_4, (ftnlen)5, &tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ 
			    - 1]);
		    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_imp_fraction_d_, (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_yd_d_[feq_gen_dten_pnt_d_ - 1],
			     (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(feq_gen_pond_volume_d_) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    feq_gen_r_d_2 = static_cast<double>(c1) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
		    feq_gen_r_d_3 = static_cast<double>(feq_gen_design_a_d_) / feq_gen_conv_out_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_design_q_d_, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_orifice_d_d_, (ftnlen)sizeof(real));
		    feq_gen_i_d_1 = gettbn_(&tamcom_1.feq_gen_dten_rout_tab_d_[feq_gen_dten_pnt_d_ - 1]);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&qfac, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE dtendlay.for:1681 */
/*<       endif >*/
		}
/* SOURCE dtendlay.for:1682 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:1684 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1685 */
/*<       unit_pnt=tam_itab(unit_pnt+2) >*/
	feq_gen_unit_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 1];
/* SOURCE dtendlay.for:1686 */
/*<       if(unit_pnt.gt.0)then >*/
	if (feq_gen_unit_pnt_d_ > 0) {
/*           There is another tributary area unit */
/* SOURCE dtendlay.for:1688 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE dtendlay.for:1689 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1691 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__177.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__177);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE dtendlay.for:1692 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:1693 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1695 */
/*<       end >*/
} /* compute_detention_description__ */




/* SOURCE dtendlay.for:1700 */
/*<        >*/
/* Subroutine */ int feq_gen_compute_area_and_imp_fraction_d_(integer *stdout, integer 
	*feq_gen_unit_pnt_d_, real *feq_gen_trib_area_d_, real *feq_gen_imp_fraction_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, n, feq_gen_triba_pnt_d_;
    real feq_gen_total_area_d_;
    integer gage;

/*     Compute the volume for a detention pond. */
/* SOURCE dtendlay.for:1705 */
/*<       implicitnone >*/
/* SOURCE dtendlay.for:1706 */
/*<       integerstdout,unit_pnt >*/
/* SOURCE dtendlay.for:1708 */
/*<       realtrib_area,imp_fraction >*/
/* INCLUDE dtendlay.for:1710 */
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
/* INCLUDE dtendlay.for:1711 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/* INCLUDE dtendlay.for:1712 */
/* *********************************************************************** */
/* SOURCE tsfcom.cmn:2 */
/*<        >*/
/* SOURCE tsfcom.cmn:6 */
/*<        >*/
/* SOURCE tsfcom.cmn:8 */
/*<       integerbwyr(mndbuf),bord(mndbuf),gend(0:mxgage),gstart(0:mxgage) >*/
/* SOURCE tsfcom.cmn:10 */
/*<       realdtend >*/
/* SOURCE tsfcom.cmn:11 */
/*<       realtriba(mxr_triba,mxn_lu_g),tsfrat(mndbuf,mndifa),tafac(mnbra) >*/
/* SOURCE tsfcom.cmn:14 */
/*<       real*8tsfbuf(mndbuf,mndifa),bjtime(mndbuf) >*/
/* *********************************************************************** */
/* INCLUDE dtendlay.for:1713 */
/*     Common block for default detention basin values. */
/* SOURCE dtendef.cmn:3 */
/*<        >*/
/* SOURCE dtendef.cmn:6 */
/*<        >*/
/* SOURCE dtendef.cmn:9 */
/*<       character*16def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/* SOURCE dtendef.cmn:12 */
/*<        >*/
/* SOURCE dtendef.cmn:17 */
/*<       common/dtendefc/def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/*     Local */
/* SOURCE dtendlay.for:1716 */
/*<       integeri,gage,n,triba_pnt >*/
/* SOURCE dtendlay.for:1718 */
/*<       realtotal_area >*/
/* *********************************************************************** */
/*     Compute the area in this unit. */
/* SOURCE dtendlay.for:1722 */
/*<       total_area=0.0 >*/
    feq_gen_total_area_d_ = (float)0.;
/* SOURCE dtendlay.for:1723 */
/*<       gage=tam_itab(unit_pnt+4) >*/
    gage = tamcom_1.feq_gen_tam_itab_d_[*feq_gen_unit_pnt_d_ + 3];
/* SOURCE dtendlay.for:1724 */
/*<       n=gend(gage)-gstart(gage)+1 >*/
    n = tsfcom_1.gend[gage] - tsfcom_1.gstart[gage] + 1;
/* SOURCE dtendlay.for:1725 */
/*<       triba_pnt=tam_itab(unit_pnt+3) >*/
    feq_gen_triba_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[*feq_gen_unit_pnt_d_ + 2];
/* SOURCE dtendlay.for:1726 */
/*<       do100i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dtendlay.for:1727 */
/*<       if(triba(triba_pnt,i).gt.0.0)then >*/
	if (tsfcom_1.triba[feq_gen_triba_pnt_d_ + feq_gen_i_d_ * 8400 - 8401] > (float)0.) {
/*         Skip negative areas.  Used for special purposes in some models. */
/* SOURCE dtendlay.for:1729 */
/*<       total_area=total_area+triba(triba_pnt,i) >*/
	    feq_gen_total_area_d_ += tsfcom_1.triba[feq_gen_triba_pnt_d_ + feq_gen_i_d_ * 8400 - 8401];
/* SOURCE dtendlay.for:1730 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1731 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE dtendlay.for:1732 */
/*<       trib_area=total_area >*/
    *feq_gen_trib_area_d_ = feq_gen_total_area_d_;
/*     Get the impervious area and compute the impervious fraction. */
/* SOURCE dtendlay.for:1734 */
/*<       if(total_area.gt.0.0)then >*/
    if (feq_gen_total_area_d_ > (float)0.) {
/* SOURCE dtendlay.for:1735 */
/*<       imp_fraction=triba(triba_pnt,def_dten_lui)/total_area >*/
	*feq_gen_imp_fraction_d_ = static_cast<double>(tsfcom_1.triba[feq_gen_triba_pnt_d_ + 
		dtendef_1.feq_gen_def_dten_lui_d_ * 8400 - 8401]) / feq_gen_total_area_d_;
/* SOURCE dtendlay.for:1736 */
/*<       else >*/
    } else {
/* SOURCE dtendlay.for:1737 */
/*<       imp_fraction=0.0 >*/
	*feq_gen_imp_fraction_d_ = (float)0.;
/* SOURCE dtendlay.for:1738 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:1739 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1740 */
/*<       end >*/
} /* compute_area_and_imp_fraction__ */




/* SOURCE dtendlay.for:1745 */
/*<        >*/
/* Subroutine */ int feq_gen_compute_delay_equations_d_(integer *stdout, real *grav, 
	integer *feq_storage_ftpnt, integer *nbra, integer *feq_storage_brpt, integer *eflag)
{
    /* Initialized data */

    static integer feq_gen_convert_tab_d_ = 10002;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:177* Imp. area conversion table is \
missing.\002)";
    static char fmt_52[] = "(/,\002 *ERR:371* Lag equation requested does no\
t yet exist.\002)";
    static char fmt_54[] = "(/,\002 Summary of Delay Times\002,//,\002  Trib\
    Ups    Dsn      Imp.     Trib.     Delay\002,/,\002 to ID   node   node \
 fraction      area  time(hr)\002,/,\002 ----- ------ ------ --------- -----\
---- ---------\002)";
    static char fmt_56[] = "(i6,2i7,f10.3,f10.4,f10.2)";
    static char fmt_58[] = "(1x,a5,14x,f10.3,f10.4,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double pow_dd(doublereal *, doublereal *);
    integer do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    integer feq_gen_dlay_pnt_d_, feq_gen_unit_pnt_d_;
    real feq_gen_trib_area_d_, dd, tba;
    integer key, feq_gen_convert_tab_address_d_, ibra, ntab;
    real feq_gen_imp_fraction_d_;
    integer feq_gen_node_convert_d_, fnode;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer lnode;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    real itfrac;
    extern /* Subroutine */ int feq_gen_compute_area_and_imp_fraction_d_(integer *, 
	    integer *, real *, real *);
    extern integer getusb_(integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__184 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__201 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__203 = { 0, 0, 0, 0, 0 };


/*     Compute the delay for any delay equation requests */
/* SOURCE dtendlay.for:1751 */
/*<       implicitnone >*/
/* INCLUDE dtendlay.for:1752 */
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
/* SOURCE dtendlay.for:1753 */
/*<       integerstdout,eflag,nbra >*/
/* SOURCE dtendlay.for:1754 */
/*<       integerftpnt(mftnum),brpt(8,nbra) >*/
/* SOURCE dtendlay.for:1756 */
/*<       realgrav >*/
/* INCLUDE dtendlay.for:1758 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     Local */
/* SOURCE dtendlay.for:1762 */
/*<        >*/
/* SOURCE dtendlay.for:1765 */
/*<       realtrib_area,imp_fraction,itfrac,dd,tba >*/
/*     Called functions */
/* SOURCE dtendlay.for:1769 */
/*<       charactergetusn*5 >*/
/* SOURCE dtendlay.for:1770 */
/*<       integergetusb >*/
/* SOURCE dtendlay.for:1772 */
/*<       externalgetusb,getusn >*/
/*     *****************************FORMATS****************************** */
/* SOURCE dtendlay.for:1766 */
/*<       dataconvert_tab/10002/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* SOURCE dtendlay.for:1775 */
/*<    50 format(/,' *ERR:177* Imp. area conversion table is missing.') >*/
/* L50: */
/* SOURCE dtendlay.for:1776 */
/*<    52 format(/,' *ERR:371* Lag equation requested does not yet exist.') >*/
/* L52: */
/* SOURCE dtendlay.for:1777 */
/*<    54  >*/
/* L54: */
/* SOURCE dtendlay.for:1781 */
/*<    56 format(i6,2i7,f10.3,f10.4,f10.2) >*/
/* L56: */
/* SOURCE dtendlay.for:1782 */
/*<    58 format(1x,a5,14x,f10.3,f10.4,f10.2) >*/
/* L58: */
/* *********************************************************************** */
/* SOURCE dtendlay.for:1785 */
/*<       if(dlay_knt.gt.0)then >*/
    if (tamcom_1.feq_gen_dlay_knt_d_ > 0) {
/*       Find internal number for the impervious-area conversion table */
/* SOURCE dtendlay.for:1788 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__184.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__184);
	e_wsfe();
/*       Traverse the trib-area management structure and check and compute */
/*       the lag times defined by equations.  The value of K for these */
/*       will be negative and the negative value selects among the equations. */
/* SOURCE dtendlay.for:1793 */
/*<       unit_pnt=1 >*/
	feq_gen_unit_pnt_d_ = 1;
/* SOURCE dtendlay.for:1795 */
/*<   100 continue >*/
L100:
/* SOURCE dtendlay.for:1796 */
/*<       dlay_pnt=tam_itab(unit_pnt+6) >*/
	feq_gen_dlay_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 5];
/* SOURCE dtendlay.for:1797 */
/*<       if(dlay_pnt.gt.0)then >*/
	if (feq_gen_dlay_pnt_d_ > 0) {
/*           Compute the total trib area and the impervious fraction */
/* SOURCE dtendlay.for:1799 */
/*<        >*/
	    feq_gen_compute_area_and_imp_fraction_d_(stdout, &feq_gen_unit_pnt_d_, &feq_gen_trib_area_d_,
		     &feq_gen_imp_fraction_d_);
/* SOURCE dtendlay.for:1801 */
/*<       if(dlay_k(dlay_pnt).lt.0.0)then >*/
	    if (tamcom_1.feq_gen_dlay_k_d_[feq_gen_dlay_pnt_d_] < (float)0.) {
/* SOURCE dtendlay.for:1803 */
/*<       convert_tab_address=convert_tab >*/
		feq_gen_convert_tab_address_d_ = feq_gen_convert_tab_d_;
/* SOURCE dtendlay.for:1804 */
/*<       callchktab(2,stdout,ftpnt,mftnum,convert_tab_address,eflag) >*/
		chktab_(&feq_gen_c_d_2, stdout, &ftpnt[1], &feq_gen_c_d_10002, &
			feq_gen_convert_tab_address_d_, eflag);
/* SOURCE dtendlay.for:1807 */
/*<       if(eflag.ne.0)then >*/
		if (*eflag != 0) {
/* SOURCE dtendlay.for:1808 */
/*<       write(stdout,50) >*/
		    feq_gen_io_d__190.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__190);
		    e_wsfe();
/* SOURCE dtendlay.for:1809 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:1810 */
/*<       endif >*/
		}
/*             Convert the impervious area from directly connected to */
/*             total. */
/* SOURCE dtendlay.for:1815 */
/*<       calllktab(convert_tab_address,imp_fraction,1,itfrac,ntab,dd) >*/
		lktab_(&feq_gen_convert_tab_address_d_, &feq_gen_imp_fraction_d_, &feq_gen_c_d_1, &
			itfrac, &ntab, &dd);
/*             Now select the equation and compute the lag value. */
/* SOURCE dtendlay.for:1821 */
/*<       key=int(abs(dlay_k(dlay_pnt))+.1) >*/
		key = (integer) ((feq_gen_d_d_1 = tamcom_1.feq_gen_dlay_k_d_[feq_gen_dlay_pnt_d_], abs(
			feq_gen_d_d_1)) + (float).1);
/* SOURCE dtendlay.for:1823 */
/*<       if(key.eq.1)then >*/
		if (key == 1) {
/*               Equation from 1972 Purdue study. Area is mi^2, */
/*               imp fraction is a decimal fraction, and the */
/*               delay time is in hours. */
/* SOURCE dtendlay.for:1828 */
/*<       if(grav.gt.15.0)then >*/
		    if (*grav > (float)15.) {
/* SOURCE dtendlay.for:1829 */
/*<       tba=trib_area/(5280.**2) >*/
			tba = static_cast<double>(feq_gen_trib_area_d_) / (float)27878400.;
/* SOURCE dtendlay.for:1830 */
/*<       else >*/
		    } else {
/*                 Convert square meters to mi^2 */
/* SOURCE dtendlay.for:1832 */
/*<       tba=trib_area/(1609.344**2) >*/
			tba = static_cast<double>(feq_gen_trib_area_d_) / (float)2589988.1103360001;
/* SOURCE dtendlay.for:1833 */
/*<       endif >*/
		    }
/* SOURCE dtendlay.for:1834 */
/*<       itfrac=itfrac+1.0 >*/
		    itfrac += static_cast<double>((float)1.);
/* SOURCE dtendlay.for:1835 */
/*<       dlay_k(dlay_pnt)=3600.*0.803*tba**0.512/itfrac**1.433 >*/
		    feq_gen_d_d_1 = (doublereal) tba;
		    feq_gen_d_d_2 = (doublereal) itfrac;
		    tamcom_1.feq_gen_dlay_k_d_[feq_gen_dlay_pnt_d_] = pow_dd(&feq_gen_d_d_1, &c_b338) * (
			    float)2890.8000000000002 / pow_dd(&feq_gen_d_d_2, &c_b339);
/* SOURCE dtendlay.for:1837 */
/*<       else >*/
		} else {
/* SOURCE dtendlay.for:1838 */
/*<       write(stdout,52) >*/
		    feq_gen_io_d__196.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__196);
		    e_wsfe();
/* SOURCE dtendlay.for:1839 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE dtendlay.for:1840 */
/*<       endif >*/
		}
/* SOURCE dtendlay.for:1841 */
/*<       endif >*/
	    }
/*           Output a summary for this unit. */
/* SOURCE dtendlay.for:1843 */
/*<       if(grav.gt.15.0)then >*/
	    if (*grav > (float)15.) {
/* SOURCE dtendlay.for:1844 */
/*<       tba=trib_area/(5280.**2) >*/
		tba = static_cast<double>(feq_gen_trib_area_d_) / (float)27878400.;
/* SOURCE dtendlay.for:1845 */
/*<       else >*/
	    } else {
/* SOURCE dtendlay.for:1846 */
/*<       tba=trib_area/1.e6 >*/
		tba = static_cast<double>(feq_gen_trib_area_d_) / (float)1e6;
/* SOURCE dtendlay.for:1847 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:1848 */
/*<       if(tam_itab(unit_pnt+1).eq.1)then >*/
	    if (tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_] == 1) {
/*             Tributary to a branch. */
/* SOURCE dtendlay.for:1850 */
/*<       fnode=tam_itab(unit_pnt+7) >*/
		fnode = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 6];
/* SOURCE dtendlay.for:1851 */
/*<       lnode=tam_itab(unit_pnt+8) >*/
		lnode = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 7];
/*             Get offset to convert from internal node number to */
/*             the user node number. */
/* SOURCE dtendlay.for:1854 */
/*<       ibra=tam_itab(unit_pnt) >*/
		ibra = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ - 1];
/* SOURCE dtendlay.for:1855 */
/*<       node_convert=brpt(1,ibra)-brpt(3,ibra) >*/
		feq_gen_node_convert_d_ = brpt[(ibra << 3) + 1] - brpt[(ibra << 3) + 3]
			;
/* SOURCE dtendlay.for:1857 */
/*<        >*/
		feq_gen_io_d__201.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__201);
		feq_gen_i_d_1 = getusb_(&ibra);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		feq_gen_i_d_2 = fnode + feq_gen_node_convert_d_;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		feq_gen_i_d_3 = lnode + feq_gen_node_convert_d_;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_imp_fraction_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&tba, (ftnlen)sizeof(real));
		feq_gen_d_d_1 = tamcom_1.feq_gen_dlay_k_d_[feq_gen_dlay_pnt_d_] / (float)3600.;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
		e_wsfe();
/* SOURCE dtendlay.for:1860 */
/*<       elseif(tam_itab(unit_pnt+1).eq.2)then >*/
	    } else if (tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_] == 2) {
/*             Tributary to a level-pool reservoir. */
/* SOURCE dtendlay.for:1862 */
/*<        >*/
		feq_gen_io_d__202.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__202);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ - 1]
			);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_imp_fraction_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&tba, (ftnlen)sizeof(real));
		feq_gen_d_d_1 = tamcom_1.feq_gen_dlay_k_d_[feq_gen_dlay_pnt_d_] / (float)3600.;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
		e_wsfe();
/* SOURCE dtendlay.for:1864 */
/*<       endif >*/
	    }
/* SOURCE dtendlay.for:1866 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1867 */
/*<       unit_pnt=tam_itab(unit_pnt+2) >*/
	feq_gen_unit_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 1];
/* SOURCE dtendlay.for:1868 */
/*<       if(unit_pnt.gt.0)then >*/
	if (feq_gen_unit_pnt_d_ > 0) {
/*           There is another tributary area unit */
/* SOURCE dtendlay.for:1870 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE dtendlay.for:1871 */
/*<       endif >*/
	}
/* SOURCE dtendlay.for:1872 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__203.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__203);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE dtendlay.for:1873 */
/*<       endif >*/
    }
/* SOURCE dtendlay.for:1874 */
/*<       return >*/
    return 0;
/* SOURCE dtendlay.for:1875 */
/*<       end >*/
} /* compute_delay_equations__ */

#ifdef __cplusplus
	}
#endif
