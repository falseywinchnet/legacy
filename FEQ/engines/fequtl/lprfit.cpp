/* lprfit.f -- translated by f2c (version 20240504).
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

/* COMMON lprfititem_com__ is declared in common.hpp. */

#define feq_gen_lprfititem_com_d_1 feq_gen_lprfititem_com_d_

/* COMMON lprfititem_comc__ is declared in common.hpp. */

#define feq_gen_lprfititem_comc_d_1 feq_gen_lprfititem_comc_d_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON grid_datum__ is declared in common.hpp. */

#define feq_gen_grid_datum_d_1 feq_gen_grid_datum_d_

/* Table of constant values */

static integer feq_gen_c_d_23 = 23;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_11 = 11;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_8 = 8;
static integer feq_gen_c_d_1000 = 1000;
static integer c_n1 = -1;
static integer feq_gen_c_d_0 = 0;




/* SOURCE lprfit.for:4 */
/*<       subroutineset_lprfit_item_defaults() >*/
/* Subroutine */ int feq_gen_set_lprfit_item_defaults_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to */
/* SOURCE lprfit.for:7 */
/*<       implicitnone >*/
/* INCLUDE lprfit.for:8 */
/* SOURCE lprfititem.cmn:1 */
/*<       integermaxr_lprfititem,maxc_lprfititem,maxdp_lprfititem >*/
/* SOURCE lprfititem.cmn:2 */
/*<       parameter(maxr_lprfititem=3,maxc_lprfititem=11,maxdp_lprfititem=4) >*/
/* SOURCE lprfititem.cmn:4 */
/*<       integerlprfititemitab(maxr_lprfititem) >*/
/* SOURCE lprfititem.cmn:5 */
/*<       reallprfititemftab(maxr_lprfititem) >*/
/* SOURCE lprfititem.cmn:6 */
/*<       real*8lprfititemdtab(maxdp_lprfititem) >*/
/* SOURCE lprfititem.cmn:7 */
/*<       character*64lprfititemctab(maxc_lprfititem) >*/
/* SOURCE lprfititem.cmn:9 */
/*<       common/lprfititem_com/lprfititemdtab,lprfititemitab,lprfititemftab >*/
/* SOURCE lprfititem.cmn:12 */
/*<       common/lprfititem_comc/lprfititemctab >*/
/* *********************************************************************** */
/*     Default for: TABID */
/* SOURCE lprfit.for:12 */
/*<       lprfititemctab(1)='    ' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/*     Default for: TABLE - note # is ignored in the standard scanner */
/* SOURCE lprfit.for:14 */
/*<       lprfititemctab(2)='    ' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 64, const_cast<char*>("    "), (ftnlen)64, (
	    ftnlen)4);
/*     Default for: FIT_WITH */
/* SOURCE lprfit.for:16 */
/*<       lprfititemctab(3)='VLSPLINE' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 128, const_cast<char*>("VLSPLINE"), (ftnlen)64, (
	    ftnlen)8);
/*     Default for: CHK_OPTION */
/* SOURCE lprfit.for:18 */
/*<       lprfititemctab(4)='NATURAL' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 192, const_cast<char*>("NATURAL"), (ftnlen)64, (
	    ftnlen)7);
/*     Default for: LEFT_SLOPE */
/* SOURCE lprfit.for:20 */
/*<       lprfititemctab(5)='LINEAR' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 256, const_cast<char*>("LINEAR"), (ftnlen)64, (
	    ftnlen)6);
/*     Default for: RIGHT_SLOPE */
/* SOURCE lprfit.for:22 */
/*<       lprfititemctab(6)='LINEAR' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 320, const_cast<char*>("LINEAR"), (ftnlen)64, (
	    ftnlen)6);
/*     Default for:ARGFAC */
/* SOURCE lprfit.for:25 */
/*<       lprfititemftab(1)=1.0 >*/
    feq_gen_lprfititem_com_d_1.lprfititemftab[0] = (float)1.;
/*     Default for:INFAC */
/* SOURCE lprfit.for:27 */
/*<       lprfititemftab(2)=27.0 >*/
    feq_gen_lprfititem_com_d_1.lprfititemftab[1] = (float)27.;
/*     Default for:OUTFAC */
/* SOURCE lprfit.for:29 */
/*<       lprfititemftab(3)=43560.0 >*/
    feq_gen_lprfititem_com_d_1.lprfititemftab[2] = (float)43560.;
/*     Default for: ZONE */
/* SOURCE lprfit.for:32 */
/*<       lprfititemctab(7)='NONE' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 384, const_cast<char*>("NONE"), (ftnlen)64, (
	    ftnlen)4);
/*     Default for: HGRID */
/* SOURCE lprfit.for:34 */
/*<       lprfititemctab(8)='NONE' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 448, const_cast<char*>("NONE"), (ftnlen)64, (
	    ftnlen)4);
/*     Default for: VDATUM */
/* SOURCE lprfit.for:36 */
/*<       lprfititemctab(9)='NONE' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 512, const_cast<char*>("NONE"), (ftnlen)64, (
	    ftnlen)4);
/*     Default for: UNITSYS */
/* SOURCE lprfit.for:38 */
/*<       lprfititemctab(10)='NONE' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 576, const_cast<char*>("NONE"), (ftnlen)64, (
	    ftnlen)4);
/*     Default for: BASIS */
/* SOURCE lprfit.for:40 */
/*<       lprfititemctab(11)='NONE' >*/
    s_copy(feq_gen_lprfititem_comc_d_1.lprfititemctab + 640, const_cast<char*>("NONE"), (ftnlen)64, (
	    ftnlen)4);
/*     Default for: EASTING */
/* SOURCE lprfit.for:43 */
/*<       lprfititemdtab(3)=-33d6 >*/
    feq_gen_lprfititem_com_d_1.lprfititemdtab[2] = -3.3e7;
/*     Default for: NORTHING */
/* SOURCE lprfit.for:45 */
/*<       lprfititemdtab(4)=-33d6 >*/
    feq_gen_lprfititem_com_d_1.lprfititemdtab[3] = -3.3e7;
/* SOURCE lprfit.for:48 */
/*<       return >*/
    return 0;
/* SOURCE lprfit.for:49 */
/*<       end >*/
} /* set_lprfit_item_defaults__ */




/* SOURCE lprfit.for:53 */
/*<        >*/
/* Subroutine */ int feq_gen_set_lprfit_items_d_(integer *eflag, integer *tab, char *
	feq_gen_fit_with_d_, char *feq_gen_chk_option_d_, char *feq_gen_left_slope_d_, char *
	feq_gen_right_slope_d_, real *argfac, real *infac, real *outfac, char *zone, 
	char *hgrid, char *vdatum, char *unitsys, char *basis, doublereal *
	easting, doublereal *northing, ftnlen fit_with_len, ftnlen 
	chk_option_len, ftnlen left_slope_len, ftnlen right_slope_len, ftnlen 
	zone_len, ftnlen hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, 
	ftnlen basis_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char key1[16], key2[16];

/*     Set items in LPRFIT */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE lprfit.for:63 */
/*<       implicitnone >*/
/* SOURCE lprfit.for:65 */
/*<       integereflag,tab >*/
/* SOURCE lprfit.for:66 */
/*<       realargfac,infac,outfac >*/
/* SOURCE lprfit.for:67 */
/*<       character*16fit_with,chk_option,left_slope,right_slope >*/
/* SOURCE lprfit.for:68 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/* SOURCE lprfit.for:69 */
/*<       real*8easting,northing >*/
/*     Local */
/* SOURCE lprfit.for:73 */
/*<       character*16key1,key2 >*/
/* INCLUDE lprfit.for:75 */
/* SOURCE lprfititem.cmn:1 */
/*<       integermaxr_lprfititem,maxc_lprfititem,maxdp_lprfititem >*/
/* SOURCE lprfititem.cmn:2 */
/*<       parameter(maxr_lprfititem=3,maxc_lprfititem=11,maxdp_lprfititem=4) >*/
/* SOURCE lprfititem.cmn:4 */
/*<       integerlprfititemitab(maxr_lprfititem) >*/
/* SOURCE lprfititem.cmn:5 */
/*<       reallprfititemftab(maxr_lprfititem) >*/
/* SOURCE lprfititem.cmn:6 */
/*<       real*8lprfititemdtab(maxdp_lprfititem) >*/
/* SOURCE lprfititem.cmn:7 */
/*<       character*64lprfititemctab(maxc_lprfititem) >*/
/* SOURCE lprfititem.cmn:9 */
/*<       common/lprfititem_com/lprfititemdtab,lprfititemitab,lprfititemftab >*/
/* SOURCE lprfititem.cmn:12 */
/*<       common/lprfititem_comc/lprfititemctab >*/
/* INCLUDE lprfit.for:76 */
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
/* *********************************************************************** */
/*     Set the table id.  There  are two strings allowed as the variable name: */
/*     TABID or TABLE */
/* SOURCE lprfit.for:80 */
/*<       key1=lprfititemctab(1) >*/
    s_copy(key1, feq_gen_lprfititem_comc_d_1.lprfititemctab, (ftnlen)16, (ftnlen)64);
/* SOURCE lprfit.for:81 */
/*<       key2=lprfititemctab(2) >*/
    s_copy(key2, feq_gen_lprfititem_comc_d_1.lprfititemctab + 64, (ftnlen)16, (ftnlen)
	    64);
/* SOURCE lprfit.for:82 */
/*<       if(key1.ne.' ')then >*/
    if (s_cmp(key1, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE lprfit.for:83 */
/*<       callget_internal_tab_number(std6,key1,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key1, eflag, tab, (
		ftnlen)16);
/* SOURCE lprfit.for:87 */
/*<       elseif(key2.ne.' ')then >*/
    } else if (s_cmp(key2, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE lprfit.for:88 */
/*<       callget_internal_tab_number(std6,key2,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key2, eflag, tab, (
		ftnlen)16);
/* SOURCE lprfit.for:92 */
/*<       else >*/
    } else {
/* SOURCE lprfit.for:93 */
/*<       tab=0 >*/
	*tab = 0;
/* SOURCE lprfit.for:94 */
/*<       endif >*/
    }
/*     Valuet for: FIT_WITH */
/* SOURCE lprfit.for:96 */
/*<       fit_with=lprfititemctab(3) >*/
    s_copy(feq_gen_fit_with_d_, feq_gen_lprfititem_comc_d_1.lprfititemctab + 128, (ftnlen)16, (
	    ftnlen)64);
/*     Value for: CHK_OPTION */
/* SOURCE lprfit.for:98 */
/*<       chk_option=lprfititemctab(4) >*/
    s_copy(feq_gen_chk_option_d_, feq_gen_lprfititem_comc_d_1.lprfititemctab + 192, (ftnlen)16, 
	    (ftnlen)64);
/*     Value for: LEFT_SLOPE */
/* SOURCE lprfit.for:100 */
/*<       left_slope=lprfititemctab(5) >*/
    s_copy(feq_gen_left_slope_d_, feq_gen_lprfititem_comc_d_1.lprfititemctab + 256, (ftnlen)16, 
	    (ftnlen)64);
/*     Value for: RIGHT_SLOPE */
/* SOURCE lprfit.for:102 */
/*<       right_slope=lprfititemctab(6) >*/
    s_copy(feq_gen_right_slope_d_, feq_gen_lprfititem_comc_d_1.lprfititemctab + 320, (ftnlen)16,
	     (ftnlen)64);
/*     Value for:ARGFAC */
/* SOURCE lprfit.for:105 */
/*<       argfac=lprfititemftab(1) >*/
    *argfac = feq_gen_lprfititem_com_d_1.lprfititemftab[0];
/*     Value for:INFAC */
/* SOURCE lprfit.for:107 */
/*<       infac=lprfititemftab(2) >*/
    *infac = feq_gen_lprfititem_com_d_1.lprfititemftab[1];
/*     Value for:OUTFAC */
/* SOURCE lprfit.for:109 */
/*<       outfac=lprfititemftab(3) >*/
    *outfac = feq_gen_lprfititem_com_d_1.lprfititemftab[2];
/*     value for: ZONE */
/* SOURCE lprfit.for:111 */
/*<       zone=lprfititemctab(7) >*/
    s_copy(zone, feq_gen_lprfititem_comc_d_1.lprfititemctab + 384, (ftnlen)8, (ftnlen)
	    64);
/*     value for: HGRID */
/* SOURCE lprfit.for:113 */
/*<       hgrid=lprfititemctab(8) >*/
    s_copy(hgrid, feq_gen_lprfititem_comc_d_1.lprfititemctab + 448, (ftnlen)8, (ftnlen)
	    64);
/*     value for: VDATUM */
/* SOURCE lprfit.for:115 */
/*<       vdatum=lprfititemctab(9) >*/
    s_copy(vdatum, feq_gen_lprfititem_comc_d_1.lprfititemctab + 512, (ftnlen)8, (
	    ftnlen)64);
/*     value for: UNITSYS */
/* SOURCE lprfit.for:117 */
/*<       unitsys=lprfititemctab(10) >*/
    s_copy(unitsys, feq_gen_lprfititem_comc_d_1.lprfititemctab + 576, (ftnlen)8, (
	    ftnlen)64);
/*     value for: BASIS */
/* SOURCE lprfit.for:119 */
/*<       basis=lprfititemctab(11) >*/
    s_copy(basis, feq_gen_lprfititem_comc_d_1.lprfititemctab + 640, (ftnlen)8, (ftnlen)
	    64);
/*     value for: EASTING */
/* SOURCE lprfit.for:122 */
/*<       easting=lprfititemdtab(3) >*/
    *easting = feq_gen_lprfititem_com_d_1.lprfititemdtab[2];
/*     value for: northing */
/* SOURCE lprfit.for:124 */
/*<       northing=lprfititemdtab(4) >*/
    *northing = feq_gen_lprfititem_com_d_1.lprfititemdtab[3];
/* SOURCE lprfit.for:127 */
/*<       return >*/
    return 0;
/* SOURCE lprfit.for:128 */
/*<       end >*/
} /* set_lprfit_items__ */




/* SOURCE lprfit.for:132 */
/*<       subroutineget_lprfit_items(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_lprfit_items_d_(integer *stdin, integer *stdout, 
	integer *eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*23+1] = "TABID           TABLE           F\
IT_WITH        CHK_OPTION      LEFT_SLOPE      RIGHT_SLOPE     ARGFAC       \
   INFAC           OUTFAC          DATA            ARGUMENT        Argument \
       ELEVATION       Elevation       DEPTH           Depth           ZONE \
           HGRID           VDATUM          UNITSYS         EASTING         N\
ORTHING        BASIS           ";
    static integer group[23] = { 1,1,1,1,1,1,0,0,0,3,2,2,2,2,2,2,1,1,1,1,0,0,
	    1 };
    static integer feq_gen_group_index_d_[23] = { 1,2,3,4,5,6,1,2,3,0,0,0,0,0,0,0,7,8,
	    9,10,5,7,11 };
    static integer feq_gen_response_type_d_[23] = { 4,4,4,4,4,4,2,2,2,0,0,0,0,0,0,0,4,
	    4,4,4,3,3,4 };
    static integer feq_gen_convert_rule_d_[23] = { 0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,
	    1,1,1,1,1 };

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_lprfit_item_defaults_d_(), 
	    feq_gen_get_named_items_d_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, char *, integer *, real *, doublereal *, 
	    char *, integer *, ftnlen, ftnlen, ftnlen);

/*     Get the table id and various options for EMBANKQ command */
/* SOURCE lprfit.for:137 */
/*<       implicitnone >*/
/* INCLUDE lprfit.for:139 */
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
/* SOURCE lprfit.for:141 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE lprfit.for:143 */
/* SOURCE lprfititem.cmn:1 */
/*<       integermaxr_lprfititem,maxc_lprfititem,maxdp_lprfititem >*/
/* SOURCE lprfititem.cmn:2 */
/*<       parameter(maxr_lprfititem=3,maxc_lprfititem=11,maxdp_lprfititem=4) >*/
/* SOURCE lprfititem.cmn:4 */
/*<       integerlprfititemitab(maxr_lprfititem) >*/
/* SOURCE lprfititem.cmn:5 */
/*<       reallprfititemftab(maxr_lprfititem) >*/
/* SOURCE lprfititem.cmn:6 */
/*<       real*8lprfititemdtab(maxdp_lprfititem) >*/
/* SOURCE lprfititem.cmn:7 */
/*<       character*64lprfititemctab(maxc_lprfititem) >*/
/* SOURCE lprfititem.cmn:9 */
/*<       common/lprfititem_com/lprfititemdtab,lprfititemitab,lprfititemftab >*/
/* SOURCE lprfititem.cmn:12 */
/*<       common/lprfititem_comc/lprfititemctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE lprfit.for:148 */
/*<        >*/
/* SOURCE lprfit.for:150 */
/*<        >*/
/* SOURCE lprfit.for:155 */
/*<       integermax_line >*/
/* SOURCE lprfit.for:158 */
/*<       externalget_named_items,set_lprfit_item_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE lprfit.for:161 */
/*<        >*/
/* SOURCE lprfit.for:163 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE lprfit.for:165 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE lprfit.for:168 */
/*<        >*/
/* SOURCE lprfit.for:175 */
/*<       datagroup/6*char,3*numeric,endsig,6*nxtblk,4*char,2*numeric,char/ >*/
/* SOURCE lprfit.for:178 */
/*<       datagroup_index/1,2,3,4,5,6,1,2,3,7*0,7,8,9,10,5,7,11/ >*/
/* SOURCE lprfit.for:182 */
/*<        >*/
/* SOURCE lprfit.for:185 */
/*<        >*/
/* SOURCE lprfit.for:191 */
/*<       callset_lprfit_item_defaults() >*/
    feq_gen_set_lprfit_item_defaults_d_();
/* SOURCE lprfit.for:193 */
/*<       max_line=14 >*/
    feq_gen_max_line_d_ = 14;
/* SOURCE lprfit.for:194 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_23, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_3, &feq_gen_c_d_4, &feq_gen_c_d_11, const_cast<char*>("LPRFIT items"), 
	    feq_gen_lprfititem_com_d_1.lprfititemitab, 
	    feq_gen_lprfititem_com_d_1.lprfititemftab, 
	    feq_gen_lprfititem_com_d_1.lprfititemdtab, 
	    feq_gen_lprfititem_comc_d_1.lprfititemctab, eflag, (ftnlen)16, (ftnlen)12, 
	    (ftnlen)64);
/* SOURCE lprfit.for:202 */
/*<       return >*/
    return 0;
/* SOURCE lprfit.for:204 */
/*<       end >*/
} /* get_lprfit_items__ */




/* SOURCE lprfit.for:209 */
/*<        >*/
/* Subroutine */ int feq_gen_read_lprfit_items_d_(integer *stdout, char *line, integer 
	*nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *eflag, 
	doublereal *arg, integer *nf, doublereal *feq_storage_fvec, ftnlen line_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:763* Only \002,i3,\002 items given \
in \002,\002an LPRFIT input line.  Need at least 2 items.\002)";
    static char fmt_52[] = "(/,\002 *ERR:753* Conversion error in field \002\
,i2,\002 in:\002,/,a)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli(), s_rsfi(icilist *), e_rsfi();

    /* Local variables */
    integer feq_gen_i_d_, n, ie, is;
    char tpc[20];
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__9 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_52, 0 };


/*     Get the items of data from a LPRFIT line */
/* SOURCE lprfit.for:216 */
/*<       implicitnone >*/
/* SOURCE lprfit.for:217 */
/*<       integerstdout,nitem,item_start(nitem),item_end(nitem),nf,eflag >*/
/* SOURCE lprfit.for:219 */
/*<       real*8arg,fvec(10) >*/
/* SOURCE lprfit.for:220 */
/*<       characterline*120 >*/
/*     Local */
/* SOURCE lprfit.for:224 */
/*<       integeri,ie,is,itab,lkey,n >*/
/* SOURCE lprfit.for:225 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE lprfit.for:228 */
/*<       integernonblank_nonzero,lenstr >*/
/* SOURCE lprfit.for:229 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE lprfit.for:232 */
/*<    50  >*/
/* SOURCE lprfit.for:234 */
/*<    52 format(/,' *ERR:753* Conversion error in field ',i2,' in:',/,a) >*/
/* *********************************************************************** */
/* SOURCE lprfit.for:237 */
/*<       if(nitem.lt.2)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    feq::IndexedPointer<doublereal> fvec(feq_storage_fvec, 1);

    /* Function Body */
/* L50: */
/* L52: */
    if (*nitem < 2) {
/* SOURCE lprfit.for:238 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__9.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__9);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE lprfit.for:239 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE lprfit.for:240 */
/*<       endif >*/
    }
/* SOURCE lprfit.for:242 */
/*<       n=1 >*/
    n = 1;
/*     Process the argument value */
/* SOURCE lprfit.for:244 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE lprfit.for:245 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE lprfit.for:246 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE lprfit.for:247 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE lprfit.for:249 */
/*<       read(tpc,*,err=999)arg >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = 0;
    feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L999;
    }
    feq_gen_i_d_1 = do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&(*arg), (ftnlen)sizeof(doublereal));
    if (feq_gen_i_d_1 != 0) {
	goto L999;
    }
    feq_gen_i_d_1 = e_rsli();
    if (feq_gen_i_d_1 != 0) {
	goto L999;
    }
/*     Process the storage values- one or more */
/* SOURCE lprfit.for:253 */
/*<       nf=nitem-1 >*/
    *nf = *nitem - 1;
/* SOURCE lprfit.for:254 */
/*<       do100i=1,nf >*/
    feq_gen_i_d_1 = *nf;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE lprfit.for:255 */
/*<       n=n+1 >*/
	++n;
/* SOURCE lprfit.for:256 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE lprfit.for:257 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE lprfit.for:258 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE lprfit.for:259 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE lprfit.for:261 */
/*<       read(tpc,'(F18.0)',err=999)fvec(i) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 20;
	feq_gen_ici_d_1.iciunit = tpc;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F18.0)");
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L999;
	}
	feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&fvec[feq_gen_i_d_], (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_2 != 0) {
	    goto L999;
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L999;
	}
/* SOURCE lprfit.for:262 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE lprfit.for:265 */
/*<       return >*/
    return 0;
/* SOURCE lprfit.for:266 */
/*<   999 continue >*/
L999:
/* SOURCE lprfit.for:267 */
/*<       write(stdout,52)n,line >*/
    feq_gen_io_d__15.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__15);
    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
    e_wsfe();
/* SOURCE lprfit.for:268 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE lprfit.for:269 */
/*<       end >*/
    return 0;
} /* read_lprfit_items__ */




/* SOURCE lprfit.for:275 */
/*<       subroutinelprfit(stdin,stdout,stdtab,ftp,eflag) >*/
/* Subroutine */ int lprfit_(integer *stdin, integer *stdout, integer *stdtab,
	 integer *ftp, integer *eflag)
{
    /* Initialized data */

    static doublereal ifac[4] = { 4.,2.,4.,1. };

    /* Format strings */
    static char fmt_50[] = "(/,\002 TabId= \002,a)";
    static char fmt_52[] = "(\002 Fitting with a cubic spline.\002)";
    static char fmt_54[] = "(\002 Fitting with a variation limited cubic spl\
ine.\002)";
    static char fmt_56[] = "(\002 Fitting with a piecewise cubic Hermite pol\
ynomial.\002)";
    static char fmt_58[] = "(/,\002*ERR:764* \002,a,\002 is an unknown fitti\
ng option.\002,/,9x,\002 Using VLSPLINE.\002)";
    static char fmt_60[] = "(/,\002 Variation-checking option is: \002,a,/\
,\002 Left-hand slope value or option is: \002,a,/,\002 Right-hand slope val\
ue or option is: \002,a)";
    static char fmt_62[] = "(/,\002 Conversion factor for argument is:\002,f\
10.2,/,\002 Conversion factor for incoming values is:\002,f10.2,/,\002 Conve\
rsion factor for outgoing values is:\002,f10.2)";
    static char fmt_64[] = "(/,\002 *ERR:765* Number of tabulated values in \
LPRFIT=\002,i5,\002 > \002,i5,/,\002 Increase value of MNDEP in file\002,\
\002 arsize.prm and recompile.\002)";
    static char fmt_65[] = "(\002ZONE=\002,a8,\002 HGRID=\002,a8,\002 VDAT\
UM=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8,/,\002EASTING=\002,0pf15.\
3,\002 NORTHING=\002,f15.3)";
    static char fmt_66[] = "(/,\002  Argument        Storage\002)";
    static char fmt_68[] = "(f10.2,10(1pe15.8))";
    static char fmt_70[] = "(/,\002*ERR:766* Unable to read \002,a,\002 for \
left-hand slope value.\002)";
    static char fmt_72[] = "(/,\002*ERR:767* Unable to read \002,a,\002 for \
right-hand slope value.\002)";
    static char fmt_74[] = "(\002TABID=\002,a16,/,\002TYPE=   -4\002)";
    static char fmt_76[] = "(\002REFL=       0.0 FAC=\002,f10.2,/,\002 ELEVA\
TION    VOLUME      AREA\002)";
    static char fmt_80[] = "(/,\002 *ERR:768* Storage=\002,f10.3,\002 <  0.0\
 at argument=\002,f10.3)";
    static char fmt_82[] = "(/,\002 *ERR:769* Area=\002,f10.3,\002 <  0.0 at\
 argument=\002,f10.3)";
    static char fmt_84[] = "(/,\002 *ERR:770* At argument=\002,f10.3,\002 st\
orage=\002,f10.3,\002 does not increase.\002)";
    static char fmt_86[] = "(/,\002 *ERR:771* At argument=\002,f10.3,\002 ar\
ea=\002,f10.3,\002 does not increase.\002)";
    static char fmt_88[] = "(/,\002 *BUG:XXX* Error in area in interval endi\
ng at argument=\002,f10.3)";
    static char fmt_90[] = "(\002  Processing LPRFIT TabId= \002,a)";
    static char fmt_92[] = "(/,\002 Detailed check of tabulated values.\002\
,\002  Three intermediate values are computed for checking.\002)";
    static char fmt_94[] = "(\002  Argument     Storage        Area  Delta A\
rea\002)";
    static char fmt_96[] = "(f10.3,1pe12.4,1pe12.4,1pe12.3)";
    static char fmt_97[] = "(/,\002 Capacity table not checked at user reque\
st.  May be invalid.\002)";
    static char fmt_98[] = "(/,\002 The table for level-pool reservoir capac\
ity appears valid.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;
    char feq_gen_ch_d_1[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsfi(icilist *), e_rsfi();

    /* Local variables */
    integer feq_gen_item_end_d_[8];
    char feq_gen_fit_with_d_[16];
    doublereal northing, a[1000];
    integer feq_gen_i_d_, j;
    extern /* Subroutine */ int feq_gen_get_lprfit_items_d_(integer *, integer *, 
	    integer *);
    integer n;
    doublereal s[1000], y[1000];
    extern /* Subroutine */ int feq_gen_set_lprfit_items_d_(integer *, integer *, char 
	    *, char *, char *, char *, real *, real *, real *, char *, char *,
	     char *, char *, char *, doublereal *, doublereal *, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal h1, h2;
    real da;
    extern /* Subroutine */ int feq_gen_read_lprfit_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, doublereal *, integer 
	    *, doublereal *, ftnlen);
    integer nf;
    real as[1000];
    doublereal ds;
    real dy, ss[1000], ys[1000];
    extern /* Subroutine */ int feq_gen_tab_in_use_d_(char *, integer *, ftnlen);
    char feq_gen_left_slope_d_[16], feq_gen_chk_option_d_[16];
    integer feq_gen_item_start_d_[8];
    doublereal arg, sum;
    extern /* Subroutine */ int feq_gen_chk_vdatum_unitsys_d_(integer *, char *, char *
	    , char *, ftnlen, ftnlen, ftnlen);
    char feq_gen_right_slope_d_[16], area[10];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real aold;
    doublereal fvec[10];
    integer ntab;
    char line[120];
    integer adrs;
    real anew;
    doublereal lval;
    real sold;
    doublereal rval;
    real yold;
    doublereal term;
    char zone[8];
    real snew;
    extern /* Subroutine */ int feq_gen_var_decimald_d_(doublereal *, char *, ftnlen);
    integer next;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real ynew;
    char just[5];
    extern /* Subroutine */ int put1d_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *);
    real infac;
    char tabid[16];
    integer lflag, lcode, table, rcode;
    char hgrid[8];
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    char basis[8];
    integer nitem;
    doublereal ratio;
    real argfac;
    char adjloc[1*1000];
    doublereal oldarg;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    real outfac;
    extern /* Subroutine */ int vlchpp_(integer *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *, char *, ftnlen);
    char volume[10], vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int spline_(integer *, doublereal *, doublereal *,
	     integer *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *);
    doublereal easting;
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__47 = { 0, 6, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_72, 0 };


/*     + + + PURPOSE + + + */
/*     Fit a sequence of storage values to estimate a surface area for */
/*     the capacity table of a level-pool reservoir. */
/* SOURCE lprfit.for:283 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE lprfit.for:285 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     FTP - pointer to next open location in the function-table storage system */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE lprfit.for:295 */
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
/* INCLUDE lprfit.for:296 */
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
/* INCLUDE lprfit.for:297 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE lprfit.for:300 */
/*<       integeradrs,i,j,n,nf,nitem,maxn,table,lcode,rcode,next,ntab,lflag >*/
/* SOURCE lprfit.for:303 */
/*<       parameter(maxn=8) >*/
/* SOURCE lprfit.for:305 */
/*<       integeritem_start(maxn),item_end(maxn) >*/
/* SOURCE lprfit.for:307 */
/*<        >*/
/* SOURCE lprfit.for:310 */
/*<        >*/
/* SOURCE lprfit.for:314 */
/*<       character*16fit_with,chk_option,left_slope,right_slope,tabid >*/
/* SOURCE lprfit.for:316 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE lprfit.for:322 */
/*<       integerlenstr >*/
/* SOURCE lprfit.for:323 */
/*<       characterget_tabid*16,put10d*10 >*/
/* SOURCE lprfit.for:324 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE lprfit.for:328 */
/*<       dataifac/4.d0,2.d0,4.d0,1.d0/ >*/
/* SOURCE lprfit.for:330 */
/*<     8 format(a6,1x,f10.0) >*/
/* L8: */
/* SOURCE lprfit.for:331 */
/*<    16 format(a5,1x,f10.0) >*/
/* L16: */
/* SOURCE lprfit.for:332 */
/*<    26 format(a5,1x,i5) >*/
/* L26: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE lprfit.for:335 */
/*<    50 format(/,' TabId= ',a) >*/
/* L50: */
/* SOURCE lprfit.for:336 */
/*<    52 format(' Fitting with a cubic spline.') >*/
/* L52: */
/* SOURCE lprfit.for:337 */
/*<    54 format(' Fitting with a variation limited cubic spline.') >*/
/* L54: */
/* SOURCE lprfit.for:338 */
/*<    56 format(' Fitting with a piecewise cubic Hermite polynomial.') >*/
/* L56: */
/* SOURCE lprfit.for:339 */
/*<    58  >*/
/* L58: */
/* SOURCE lprfit.for:341 */
/*<    60  >*/
/* L60: */
/* SOURCE lprfit.for:344 */
/*<    62  >*/
/* L62: */
/* SOURCE lprfit.for:347 */
/*<    64  >*/
/* L64: */
/* SOURCE lprfit.for:350 */
/*<    65  >*/
/* L65: */
/* SOURCE lprfit.for:353 */
/*<    66 format(/,'  Argument        Storage') >*/
/* L66: */
/* SOURCE lprfit.for:354 */
/*<    68 format(f10.2,10(1pe15.8)) >*/
/* L68: */
/* SOURCE lprfit.for:355 */
/*<    70  >*/
/* L70: */
/* SOURCE lprfit.for:357 */
/*<    72  >*/
/* L72: */
/* SOURCE lprfit.for:359 */
/*<    74 format('TABID=',a16,/,'TYPE=   -4') >*/
/* L74: */
/* SOURCE lprfit.for:360 */
/*<    76  >*/
/* L76: */
/* SOURCE lprfit.for:362 */
/*<    80 format(/,' *ERR:768* Storage=',f10.3,' <  0.0 at argument=',f10.3) >*/
/* L80: */
/* SOURCE lprfit.for:364 */
/*<    82 format(/,' *ERR:769* Area=',f10.3,' <  0.0 at argument=',f10.3) >*/
/* L82: */
/* SOURCE lprfit.for:366 */
/*<    84  >*/
/* L84: */
/* SOURCE lprfit.for:368 */
/*<    86  >*/
/* L86: */
/* SOURCE lprfit.for:370 */
/*<    88  >*/
/* L88: */
/* SOURCE lprfit.for:372 */
/*<    90 format('  Processing LPRFIT TabId= ',a) >*/
/* L90: */
/* SOURCE lprfit.for:373 */
/*<    92  >*/
/* L92: */
/* SOURCE lprfit.for:375 */
/*<    94 format('  Argument     Storage        Area  Delta Area') >*/
/* L94: */
/* SOURCE lprfit.for:376 */
/*<    96 format(f10.3,1pe12.4,1pe12.4,1pe12.3) >*/
/* L96: */
/* SOURCE lprfit.for:377 */
/*<    97  >*/
/* L97: */
/* SOURCE lprfit.for:379 */
/*<    98  >*/
/* L98: */
/* *********************************************************************** */
/*     Set the value for the temporary storage of function tables */
/* SOURCE lprfit.for:383 */
/*<       next=ftp >*/
    next = *ftp;
/*     Set the justification option for GET_ITEM_LIMITS */
/* SOURCE lprfit.for:386 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/* SOURCE lprfit.for:388 */
/*<       callget_lprfit_items(stdin,stdout,eflag) >*/
    feq_gen_get_lprfit_items_d_(stdin, stdout, eflag);
/* SOURCE lprfit.for:390 */
/*<        >*/
    feq_gen_set_lprfit_items_d_(eflag, &table, feq_gen_fit_with_d_, feq_gen_chk_option_d_, feq_gen_left_slope_d_, 
	    feq_gen_right_slope_d_, &argfac, &infac, &outfac, zone, hgrid, vdatum, 
	    unitsys, basis, &easting, &northing, (ftnlen)16, (ftnlen)16, (
	    ftnlen)16, (ftnlen)16, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8,
	     (ftnlen)8);
/* SOURCE lprfit.for:397 */
/*<        >*/
    feq_gen_chk_vdatum_unitsys_d_(stdout, vdatum, unitsys, const_cast<char*>(" during output of table f\
or LPR capacity"), (ftnlen)8, (ftnlen)8, (ftnlen)40);
/* SOURCE lprfit.for:402 */
/*<       tabid=get_tabid(table) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &table);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE lprfit.for:403 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)) >*/
    feq_gen_io_d__38.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__38);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE lprfit.for:405 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__39.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__39);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE lprfit.for:406 */
/*<       if(fit_with.eq.'CSPLINE')then >*/
    if (s_cmp(feq_gen_fit_with_d_, const_cast<char*>("CSPLINE"), (ftnlen)16, (ftnlen)7) == 0) {
/* SOURCE lprfit.for:407 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__40.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__40);
	e_wsfe();
/* SOURCE lprfit.for:408 */
/*<       elseif(fit_with.eq.'VLSPLINE')then >*/
    } else if (s_cmp(feq_gen_fit_with_d_, const_cast<char*>("VLSPLINE"), (ftnlen)16, (ftnlen)8) == 0) {
/* SOURCE lprfit.for:409 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__41.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__41);
	e_wsfe();
/* SOURCE lprfit.for:410 */
/*<       elseif(fit_with.eq.'PCHERMITE')then >*/
    } else if (s_cmp(feq_gen_fit_with_d_, const_cast<char*>("PCHERMITE"), (ftnlen)16, (ftnlen)9) == 0) {
/* SOURCE lprfit.for:411 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__42.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__42);
	e_wsfe();
/* SOURCE lprfit.for:412 */
/*<       else >*/
    } else {
/* SOURCE lprfit.for:413 */
/*<       write(stdout,58)fit_with(1:lenstr(fit_with)) >*/
	feq_gen_io_d__43.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__43);
	do_fio(&feq_gen_c_d_1, feq_gen_fit_with_d_, lenstr_(feq_gen_fit_with_d_, (ftnlen)16));
	e_wsfe();
/* SOURCE lprfit.for:414 */
/*<       endif >*/
    }
/* SOURCE lprfit.for:416 */
/*<       write(stdout,60)chk_option,left_slope,right_slope >*/
    feq_gen_io_d__44.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__44);
    do_fio(&feq_gen_c_d_1, feq_gen_chk_option_d_, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_left_slope_d_, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_right_slope_d_, (ftnlen)16);
    e_wsfe();
/* SOURCE lprfit.for:418 */
/*<       write(stdout,62)argfac,infac,outfac >*/
    feq_gen_io_d__45.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__45);
    do_fio(&feq_gen_c_d_1, (char *)&argfac, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&infac, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&outfac, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE lprfit.for:419 */
/*<       ratio=infac/outfac >*/
    ratio = static_cast<double>(infac) / outfac;
/* SOURCE lprfit.for:420 */
/*<       write(*,90)tabid >*/
    s_wsfe(&feq_gen_io_d__47);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    e_wsfe();
/*     MAKE SURE TABLE NUMBER IS NOT ALREADY USED IN THIS INPUT */
/* SOURCE lprfit.for:424 */
/*<       if(ftpnt(table).ne.0)calltab_in_use(tabid,eflag) >*/
    if (ftablea_1.ftpnt[table - 1] != 0) {
	feq_gen_tab_in_use_d_(tabid, eflag, (ftnlen)16);
    }
/*     Get the heading line. */
/* SOURCE lprfit.for:429 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE lprfit.for:433 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_8, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)120, (ftnlen)5);
/* SOURCE lprfit.for:438 */
/*<       i=0 >*/
    feq_gen_i_d_ = 0;
/* SOURCE lprfit.for:439 */
/*<       oldarg=-1.d100 >*/
    oldarg = -1e100;
/* SOURCE lprfit.for:440 */
/*<       write(stdout,66) >*/
    feq_gen_io_d__54.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__54);
    e_wsfe();
/* SOURCE lprfit.for:442 */
/*<   100 continue >*/
L100:
/* SOURCE lprfit.for:443 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE lprfit.for:447 */
/*<        >*/
    feq_gen_read_lprfit_items_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, eflag,
	     &arg, &nf, fvec, (ftnlen)120);
/* SOURCE lprfit.for:453 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/* SOURCE lprfit.for:455 */
/*<       if(arg.gt.oldarg)then >*/
	if (arg > oldarg) {
/* SOURCE lprfit.for:456 */
/*<       sum=0.d0 >*/
	    sum = 0.;
/* SOURCE lprfit.for:457 */
/*<       do110j=1,nf >*/
	    feq_gen_i_d_1 = nf;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE lprfit.for:458 */
/*<       sum=sum+fvec(j) >*/
		sum += fvec[j - 1];
/* SOURCE lprfit.for:459 */
/*<   110 continue >*/
/* L110: */
	    }
/* SOURCE lprfit.for:461 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE lprfit.for:462 */
/*<       if(i.gt.mndep)then >*/
	    if (feq_gen_i_d_ > 1000) {
/* SOURCE lprfit.for:463 */
/*<       write(stdout,64)i,mndep >*/
		feq_gen_io_d__60.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__60);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE lprfit.for:464 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE lprfit.for:465 */
/*<       endif >*/
	    }
/* SOURCE lprfit.for:466 */
/*<       write(stdout,68)arg,(fvec(j),j=1,nf) >*/
	    feq_gen_io_d__61.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__61);
	    do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(doublereal));
	    feq_gen_i_d_1 = nf;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&fvec[j - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_wsfe();
/* SOURCE lprfit.for:467 */
/*<       y(i)=(arg)*argfac >*/
	    y[feq_gen_i_d_ - 1] = arg * argfac;
/* SOURCE lprfit.for:468 */
/*<       s(i)=sum*ratio >*/
	    s[feq_gen_i_d_ - 1] = sum * ratio;
/* SOURCE lprfit.for:469 */
/*<       oldarg=arg >*/
	    oldarg = arg;
/* SOURCE lprfit.for:470 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE lprfit.for:471 */
/*<       else >*/
	} else {
/* SOURCE lprfit.for:472 */
/*<       n=i >*/
	    n = feq_gen_i_d_;
/* SOURCE lprfit.for:473 */
/*<       endif >*/
	}
/* SOURCE lprfit.for:474 */
/*<       else >*/
    } else {
/* SOURCE lprfit.for:475 */
/*<       return >*/
	return 0;
/* SOURCE lprfit.for:476 */
/*<       endif >*/
    }
/*     Now that we finally have the data in hand, do the computations. */
/*     Compute the end conditions for the fit. */
/* SOURCE lprfit.for:484 */
/*<       lcode=1 >*/
    lcode = 1;
/* SOURCE lprfit.for:485 */
/*<       if(left_slope.eq.'LINEAR')then >*/
    if (s_cmp(feq_gen_left_slope_d_, const_cast<char*>("LINEAR"), (ftnlen)16, (ftnlen)6) == 0) {
/* SOURCE lprfit.for:486 */
/*<       lval=(s(2)-s(1))/(y(2)-y(1)) >*/
	lval = (s[1] - s[0]) / (y[1] - y[0]);
/* SOURCE lprfit.for:487 */
/*<       elseif(left_slope.eq.'PARABOLIC')then >*/
    } else if (s_cmp(feq_gen_left_slope_d_, const_cast<char*>("PARABOLIC"), (ftnlen)16, (ftnlen)9) == 0) {
/* SOURCE lprfit.for:488 */
/*<       h1=y(2)-y(1) >*/
	h1 = y[1] - y[0];
/* SOURCE lprfit.for:489 */
/*<       h2=y(3)-y(2) >*/
	h2 = y[2] - y[1];
/* SOURCE lprfit.for:490 */
/*<        >*/
	lval = -(h1 * 2 + h2) * s[0] / (h1 * (h1 + h2)) + (h1 + h2) * s[1] / (
		h1 * h2) - h1 * s[2] / ((h1 + h2) * h2);
/* SOURCE lprfit.for:494 */
/*<       else >*/
    } else {
/*       Try to read the value to get the slope. */
/* SOURCE lprfit.for:496 */
/*<       read(left_slope,'(F15.0)',err=998)lval >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 16;
	feq_gen_ici_d_1.iciunit = feq_gen_left_slope_d_;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L998;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&lval, (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_1 != 0) {
	    goto L998;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L998;
	}
/* SOURCE lprfit.for:497 */
/*<       endif >*/
    }
/* SOURCE lprfit.for:499 */
/*<       rcode=1 >*/
    rcode = 1;
/* SOURCE lprfit.for:500 */
/*<       if(right_slope.eq.'LINEAR')then >*/
    if (s_cmp(feq_gen_right_slope_d_, const_cast<char*>("LINEAR"), (ftnlen)16, (ftnlen)6) == 0) {
/* SOURCE lprfit.for:501 */
/*<       rval=(s(n)-s(n-1))/(y(n)-y(n-1)) >*/
	rval = (s[n - 1] - s[n - 2]) / (y[n - 1] - y[n - 2]);
/* SOURCE lprfit.for:502 */
/*<       elseif(right_slope.eq.'PARABOLIC')then >*/
    } else if (s_cmp(feq_gen_right_slope_d_, const_cast<char*>("PARABOLIC"), (ftnlen)16, (ftnlen)9) == 0) 
	    {
/* SOURCE lprfit.for:503 */
/*<       h1=y(n-1)-y(n-2) >*/
	h1 = y[n - 2] - y[n - 3];
/* SOURCE lprfit.for:504 */
/*<       h2=y(n)-y(n-1) >*/
	h2 = y[n - 1] - y[n - 2];
/* SOURCE lprfit.for:505 */
/*<        >*/
	rval = h2 * s[n - 3] / (h1 * (h1 + h2)) - (h1 + h2) * s[n - 2] / (h1 *
		 h2) + (h2 * 2 + h1) * s[n - 1] / ((h1 + h2) * h2);
/* SOURCE lprfit.for:509 */
/*<       else >*/
    } else {
/* SOURCE lprfit.for:510 */
/*<       read(right_slope,'(F15.0)',err=999)rval >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 16;
	feq_gen_ici_d_1.iciunit = feq_gen_right_slope_d_;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&rval, (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L999;
	}
/* SOURCE lprfit.for:511 */
/*<       endif >*/
    }
/* SOURCE lprfit.for:513 */
/*<       if(fit_with.eq.'VLSPLINE')then >*/
    if (s_cmp(feq_gen_fit_with_d_, const_cast<char*>("VLSPLINE"), (ftnlen)16, (ftnlen)8) == 0) {
/* SOURCE lprfit.for:514 */
/*<       callvlchpp(stdout,n,y,s,lcode,lval,rcode,rval,a,adjloc) >*/
	vlchpp_(stdout, &n, y, s, &lcode, &lval, &rcode, &rval, a, adjloc, (
		ftnlen)1);
/* SOURCE lprfit.for:517 */
/*<       elseif(fit_with.eq.'CSPLINE')then >*/
    } else if (s_cmp(feq_gen_fit_with_d_, const_cast<char*>("CSPLINE"), (ftnlen)16, (ftnlen)7) == 0) {
/* SOURCE lprfit.for:518 */
/*<       callspline(stdout,y,s,n,lcode,lval,rcode,rval,a) >*/
	spline_(stdout, y, s, &n, &lcode, &lval, &rcode, &rval, a);
/* SOURCE lprfit.for:521 */
/*<       elseif(fit_with.eq.'PCHERMITE')then >*/
    } else if (s_cmp(feq_gen_fit_with_d_, const_cast<char*>("PCHERMITE"), (ftnlen)16, (ftnlen)9) == 0) {
/* SOURCE lprfit.for:522 */
/*<       a(1)=lval >*/
	a[0] = lval;
/* SOURCE lprfit.for:523 */
/*<       a(n)=rval >*/
	a[n - 1] = rval;
/* SOURCE lprfit.for:524 */
/*<       do120i=2,n-1 >*/
	feq_gen_i_d_1 = n - 1;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE lprfit.for:525 */
/*<       h1=y(i)-y(i-1) >*/
	    h1 = y[feq_gen_i_d_ - 1] - y[feq_gen_i_d_ - 2];
/* SOURCE lprfit.for:526 */
/*<       h2=y(i+1)-y(i) >*/
	    h2 = y[feq_gen_i_d_] - y[feq_gen_i_d_ - 1];
/* SOURCE lprfit.for:527 */
/*<        >*/
	    a[feq_gen_i_d_ - 1] = -h2 * s[feq_gen_i_d_ - 2] / (h1 * (h1 + h2)) - (h1 - h2) * s[
		    feq_gen_i_d_ - 1] / (h1 * h2) + h1 * s[feq_gen_i_d_] / ((h1 + h2) * h2);
/* SOURCE lprfit.for:530 */
/*<   120 continue >*/
/* L120: */
	}
/* SOURCE lprfit.for:531 */
/*<       endif >*/
    }
/*     Store the table in the function-table system using temporary storage. */
/*     That is, the table is only known in this routine and the storage used */
/*     is released on exit. */
/* SOURCE lprfit.for:536 */
/*<       do125i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE lprfit.for:537 */
/*<       ys(i)=y(i) >*/
	ys[feq_gen_i_d_ - 1] = y[feq_gen_i_d_ - 1];
/* SOURCE lprfit.for:538 */
/*<       ss(i)=s(i) >*/
	ss[feq_gen_i_d_ - 1] = s[feq_gen_i_d_ - 1];
/* SOURCE lprfit.for:539 */
/*<       as(i)=a(i) >*/
	as[feq_gen_i_d_ - 1] = a[feq_gen_i_d_ - 1];
/* SOURCE lprfit.for:540 */
/*<   125 continue >*/
/* L125: */
    }
/* SOURCE lprfit.for:541 */
/*<       callput1d(stdout,-1,4,n,ys,ss,as,next,adrs) >*/
    put1d_(stdout, &c_n1, &feq_gen_c_d_4, &n, ys, ss, as, &next, &adrs);
/*     Scan the table values checking validity for three cases: */
/*     Case 1: NATURAL */
/*           Assumes a natural reservoir site which implies the following: */
/*         1.  Storage is always positive (excluding initial point) */
/*             and increases with increases in argument */
/*         2.  Area is always positive (excluding initial point) */
/*             and increases with increases in argument */
/*     Case 2: CONSTRUCTED */
/*           Assumes a constructed reservoir which implies the following: */
/*         1. Storage is always positive and increases with increase in argument */
/*         2. Area is always positive. */
/*     Case 3: NONE */
/*           No checking for variation. */
/* SOURCE lprfit.for:562 */
/*<       yold=ys(1) >*/
    yold = ys[0];
/* SOURCE lprfit.for:563 */
/*<       calllktab(adrs,yold,0,sold,ntab,aold) >*/
    lktab_(&adrs, &yold, &feq_gen_c_d_0, &sold, &ntab, &aold);
/*     Clear the local error flag */
/* SOURCE lprfit.for:567 */
/*<       lflag=0 >*/
    lflag = 0;
/* SOURCE lprfit.for:568 */
/*<       if(chk_option.eq.'NATURAL')then >*/
    if (s_cmp(feq_gen_chk_option_d_, const_cast<char*>("NATURAL"), (ftnlen)16, (ftnlen)7) == 0) {
/* SOURCE lprfit.for:569 */
/*<       if(sold.lt.0.0)then >*/
	if (sold < (float)0.) {
/* SOURCE lprfit.for:570 */
/*<       write(stdout,80)sold,yold >*/
	    feq_gen_io_d__82.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__82);
	    do_fio(&feq_gen_c_d_1, (char *)&sold, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&yold, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE lprfit.for:571 */
/*<       lflag=1 >*/
	    lflag = 1;
/* SOURCE lprfit.for:572 */
/*<       endif >*/
	}
/* SOURCE lprfit.for:573 */
/*<       if(aold.lt.0.0)then >*/
	if (aold < (float)0.) {
/* SOURCE lprfit.for:574 */
/*<       write(stdout,82)aold,yold >*/
	    feq_gen_io_d__83.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__83);
	    do_fio(&feq_gen_c_d_1, (char *)&aold, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&yold, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE lprfit.for:575 */
/*<       lflag=1 >*/
	    lflag = 1;
/* SOURCE lprfit.for:576 */
/*<       endif >*/
	}
/* SOURCE lprfit.for:577 */
/*<       endif >*/
    }
/* SOURCE lprfit.for:579 */
/*<       write(stdout,92) >*/
    feq_gen_io_d__84.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__84);
    e_wsfe();
/* SOURCE lprfit.for:580 */
/*<       write(stdout,94) >*/
    feq_gen_io_d__85.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__85);
    e_wsfe();
/* SOURCE lprfit.for:581 */
/*<       da=0.0 >*/
    da = (float)0.;
/* SOURCE lprfit.for:582 */
/*<       write(stdout,96)yold,sold,aold,da >*/
    feq_gen_io_d__87.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__87);
    do_fio(&feq_gen_c_d_1, (char *)&yold, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&sold, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&aold, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&da, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE lprfit.for:583 */
/*<       do129i=2,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE lprfit.for:585 */
/*<       dy=ys(i)-ys(i-1) >*/
	dy = static_cast<double>(ys[feq_gen_i_d_ - 1]) - ys[feq_gen_i_d_ - 2];
/* SOURCE lprfit.for:586 */
/*<       ds=ss(i)-ss(i-1) >*/
	ds = static_cast<double>(ss[feq_gen_i_d_ - 1]) - ss[feq_gen_i_d_ - 2];
/* SOURCE lprfit.for:587 */
/*<       sum=aold >*/
	sum = aold;
/* SOURCE lprfit.for:588 */
/*<       do127j=1,4 >*/
	for (j = 1; j <= 4; ++j) {
/* SOURCE lprfit.for:589 */
/*<       ynew=yold+dy*float(j)/4.0 >*/
	    ynew = static_cast<double>(yold) + static_cast<double>(static_cast<double>(dy) * (real) j) / (float)4.;
/* SOURCE lprfit.for:591 */
/*<       calllktab(adrs,ynew,0,snew,ntab,anew) >*/
	    lktab_(&adrs, &ynew, &feq_gen_c_d_0, &snew, &ntab, &anew);
/* SOURCE lprfit.for:593 */
/*<       da=anew-aold >*/
	    da = static_cast<double>(anew) - aold;
/* SOURCE lprfit.for:594 */
/*<       write(stdout,96)ynew,snew,anew,da >*/
	    feq_gen_io_d__93.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__93);
	    do_fio(&feq_gen_c_d_1, (char *)&ynew, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&snew, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&anew, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&da, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE lprfit.for:595 */
/*<       if(chk_option.ne.'NONE')then >*/
	    if (s_cmp(feq_gen_chk_option_d_, const_cast<char*>("NONE"), (ftnlen)16, (ftnlen)4) != 0) {
/*           Check for values */
/* SOURCE lprfit.for:597 */
/*<       if(snew.lt.0.0)then >*/
		if (snew < (float)0.) {
/* SOURCE lprfit.for:598 */
/*<       write(stdout,80)snew,ynew >*/
		    feq_gen_io_d__94.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__94);
		    do_fio(&feq_gen_c_d_1, (char *)&snew, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ynew, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE lprfit.for:599 */
/*<       lflag=1 >*/
		    lflag = 1;
/* SOURCE lprfit.for:600 */
/*<       endif >*/
		}
/* SOURCE lprfit.for:601 */
/*<       if(anew.le.0.0)then >*/
		if (anew <= (float)0.) {
/* SOURCE lprfit.for:602 */
/*<       write(stdout,82)anew,ynew >*/
		    feq_gen_io_d__95.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__95);
		    do_fio(&feq_gen_c_d_1, (char *)&anew, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ynew, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE lprfit.for:603 */
/*<       lflag=1 >*/
		    lflag = 1;
/* SOURCE lprfit.for:604 */
/*<       endif >*/
		}
/* SOURCE lprfit.for:606 */
/*<       if(chk_option.eq.'NATURAL')then >*/
		if (s_cmp(feq_gen_chk_option_d_, const_cast<char*>("NATURAL"), (ftnlen)16, (ftnlen)7) == 
			0) {
/*             Check for variation. */
/* SOURCE lprfit.for:608 */
/*<       if(snew.le.sold)then >*/
		    if (snew <= sold) {
/* SOURCE lprfit.for:609 */
/*<       write(stdout,84)ynew,snew >*/
			feq_gen_io_d__96.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__96);
			do_fio(&feq_gen_c_d_1, (char *)&ynew, (ftnlen)sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&snew, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE lprfit.for:610 */
/*<       lflag=1 >*/
			lflag = 1;
/* SOURCE lprfit.for:611 */
/*<       endif >*/
		    }
/* SOURCE lprfit.for:612 */
/*<       if(anew.le.aold)then >*/
		    if (anew <= aold) {
/* SOURCE lprfit.for:613 */
/*<       write(stdout,86)ynew,anew >*/
			feq_gen_io_d__97.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__97);
			do_fio(&feq_gen_c_d_1, (char *)&ynew, (ftnlen)sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&anew, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE lprfit.for:614 */
/*<       lflag=1 >*/
			lflag = 1;
/* SOURCE lprfit.for:615 */
/*<       endif >*/
		    }
/* SOURCE lprfit.for:616 */
/*<       elseif(chk_option.eq.'CONSTRUCTED')then >*/
		} else if (s_cmp(feq_gen_chk_option_d_, const_cast<char*>("CONSTRUCTED"), (ftnlen)16, (
			ftnlen)11) == 0) {
/*             Check for variation. */
/* SOURCE lprfit.for:618 */
/*<       if(snew.le.sold)then >*/
		    if (snew <= sold) {
/* SOURCE lprfit.for:619 */
/*<       write(stdout,84)ynew,snew >*/
			feq_gen_io_d__98.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__98);
			do_fio(&feq_gen_c_d_1, (char *)&ynew, (ftnlen)sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&snew, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE lprfit.for:620 */
/*<       lflag=1 >*/
			lflag = 1;
/* SOURCE lprfit.for:621 */
/*<       endif >*/
		    }
/* SOURCE lprfit.for:622 */
/*<       endif >*/
		}
/* SOURCE lprfit.for:623 */
/*<       endif >*/
	    }
/*         Update the sum for numerical integration */
/* SOURCE lprfit.for:626 */
/*<       sum=sum+ifac(j)*anew >*/
	    sum += ifac[j - 1] * anew;
/* SOURCE lprfit.for:627 */
/*<       sold=snew >*/
	    sold = snew;
/* SOURCE lprfit.for:628 */
/*<       aold=anew >*/
	    aold = anew;
/* SOURCE lprfit.for:630 */
/*<   127 continue >*/
/* L127: */
	}
/*       Check area by integration */
/* SOURCE lprfit.for:633 */
/*<       sum=sum*dy/12.d0 >*/
	sum = sum * dy / 12.;
/* SOURCE lprfit.for:634 */
/*<       if(abs((sum-ds)/ds).gt.0.001)then >*/
	if ((feq_gen_d_d_1 = (sum - ds) / ds, abs(feq_gen_d_d_1)) > (float).001) {
/* SOURCE lprfit.for:635 */
/*<       write(stdout,88)ynew >*/
	    feq_gen_io_d__99.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__99);
	    do_fio(&feq_gen_c_d_1, (char *)&ynew, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE lprfit.for:636 */
/*<       stop'Abnormal stop.  Bug found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE lprfit.for:637 */
/*<       endif >*/
	}
/* SOURCE lprfit.for:639 */
/*<       yold=ynew >*/
	yold = ynew;
/* SOURCE lprfit.for:640 */
/*<   129 continue >*/
/* L129: */
    }
/* SOURCE lprfit.for:642 */
/*<       if(lflag.eq.0)then >*/
    if (lflag == 0) {
/* SOURCE lprfit.for:643 */
/*<       if(chk_option.ne.'NONE')then >*/
	if (s_cmp(feq_gen_chk_option_d_, const_cast<char*>("NONE"), (ftnlen)16, (ftnlen)4) != 0) {
/* SOURCE lprfit.for:644 */
/*<       write(stdout,98) >*/
	    feq_gen_io_d__100.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__100);
	    e_wsfe();
/* SOURCE lprfit.for:645 */
/*<       else >*/
	} else {
/* SOURCE lprfit.for:646 */
/*<       write(stdout,97) >*/
	    feq_gen_io_d__101.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__101);
	    e_wsfe();
/* SOURCE lprfit.for:647 */
/*<       endif >*/
	}
/* SOURCE lprfit.for:648 */
/*<       else >*/
    } else {
/* SOURCE lprfit.for:649 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE lprfit.for:650 */
/*<       endif >*/
    }
/*     Output a table of type 4 */
/* SOURCE lprfit.for:654 */
/*<       write(stdtab,74)tabid >*/
    feq_gen_io_d__102.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__102);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    e_wsfe();
/* SOURCE lprfit.for:656 */
/*<       if(zone/='NONE'.and.zone/='NONE')then >*/
    if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0 && s_cmp(zone, const_cast<char*>("NONE"), 
	    (ftnlen)8, (ftnlen)4) != 0) {
/*       Output the location information. */
/* SOURCE lprfit.for:658 */
/*<       write(stdtab,65)zone,hgrid,vdatum,unitsys,basis,easting,northing >*/
	feq_gen_io_d__103.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__103);
	do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE lprfit.for:660 */
/*<       endif >*/
    }
/* SOURCE lprfit.for:662 */
/*<       write(stdtab,76)outfac >*/
    feq_gen_io_d__104.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__104);
    do_fio(&feq_gen_c_d_1, (char *)&outfac, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE lprfit.for:664 */
/*<       do140i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE lprfit.for:665 */
/*<       callvar_decimald(s(i),volume) >*/
	feq_gen_var_decimald_d_(&s[feq_gen_i_d_ - 1], volume, (ftnlen)10);
/* SOURCE lprfit.for:668 */
/*<       callvar_decimald(a(i),area) >*/
	feq_gen_var_decimald_d_(&a[feq_gen_i_d_ - 1], area, (ftnlen)10);
/* SOURCE lprfit.for:670 */
/*<       write(stdtab,'(F10.3,A10,A10)')y(i),volume,area >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdtab;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(F10.3,A10,A10)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&y[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, volume, (ftnlen)10);
	do_fio(&feq_gen_c_d_1, area, (ftnlen)10);
	e_wsfe();
/* SOURCE lprfit.for:671 */
/*<   140 continue >*/
/* L140: */
    }
/* SOURCE lprfit.for:672 */
/*<       if(y(n).gt.0.d0)then >*/
    if (y[n - 1] > 0.) {
/* SOURCE lprfit.for:673 */
/*<       term=-1.d0 >*/
	term = -1.;
/* SOURCE lprfit.for:674 */
/*<       else >*/
    } else {
/* SOURCE lprfit.for:675 */
/*<       term=y(n)-1.d0 >*/
	term = y[n - 1] - 1.;
/* SOURCE lprfit.for:676 */
/*<       endif >*/
    }
/* SOURCE lprfit.for:677 */
/*<       write(stdtab,'(F10.0)')term >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdtab;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(F10.0)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&term, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE lprfit.for:680 */
/*<       return >*/
    return 0;
/* SOURCE lprfit.for:681 */
/*<   998 continue >*/
L998:
/* SOURCE lprfit.for:682 */
/*<       write(stdout,70)left_slope >*/
    feq_gen_io_d__108.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__108);
    do_fio(&feq_gen_c_d_1, feq_gen_left_slope_d_, (ftnlen)16);
    e_wsfe();
/* SOURCE lprfit.for:683 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE lprfit.for:684 */
/*<   999 continue >*/
L999:
/* SOURCE lprfit.for:685 */
/*<       write(stdout,72)right_slope >*/
    feq_gen_io_d__109.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__109);
    do_fio(&feq_gen_c_d_1, feq_gen_right_slope_d_, (ftnlen)16);
    e_wsfe();
/* SOURCE lprfit.for:686 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE lprfit.for:688 */
/*<       end >*/
    return 0;
} /* lprfit_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
