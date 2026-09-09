/* location.f -- translated by f2c (version 20240504).
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

/* COMMON lctnitm_com__ is declared in common.hpp. */

#define feq_gen_lctnitm_com_d_1 feq_gen_lctnitm_com_d_

/* COMMON lctnitm_comc__ is declared in common.hpp. */

#define feq_gen_lctnitm_comc_d_1 feq_gen_lctnitm_comc_d_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_22 = 22;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_5 = 5;

/*     Routines that relate directly to handling zone, hgrid, vdatum, unitsys, */
/*     easting, and northing, that is, items that define the location of */
/*     a function table or point in space. */
/*     These routines will be called (sooner or later) by the code for the */
/*     the following commands: MULPIPES, MULCON, SEWER, AXIALPUMP, PUMPLOSS, */
/*     CULVERT, ORIFICE, EXPCON, CRITQ, EMBANKQ, */
/*     RISERCLV and maybe more:) */



/* SOURCE location.for:14 */
/*<       subroutineset_lctn_item_defaults() >*/
/* Subroutine */ int feq_gen_set_lctn_item_defaults_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to establish location */
/* SOURCE location.for:17 */
/*<       implicitnone >*/
/* INCLUDE location.for:18 */
/* SOURCE lctnitem.cmn:1 */
/*<       integermaxr_lctnitm,maxc_lctnitm,maxdp_lctnitm >*/
/* SOURCE lctnitem.cmn:2 */
/*<       parameter(maxr_lctnitm=4,maxc_lctnitm=5,maxdp_lctnitm=2) >*/
/* SOURCE lctnitem.cmn:3 */
/*<       integerlctnitmitab(maxr_lctnitm) >*/
/* SOURCE lctnitem.cmn:4 */
/*<       reallctnitmftab(maxr_lctnitm) >*/
/* SOURCE lctnitem.cmn:5 */
/*<       real*8lctnitmdtab(maxdp_lctnitm) >*/
/* SOURCE lctnitem.cmn:6 */
/*<       character*64lctnitmctab(maxc_lctnitm) >*/
/* SOURCE lctnitem.cmn:8 */
/*<       common/lctnitm_com/lctnitmdtab,lctnitmitab,lctnitmftab >*/
/* SOURCE lctnitem.cmn:10 */
/*<       common/lctnitm_comc/lctnitmctab >*/
/* *********************************************************************** */
/*     Default for: ZONE */
/* SOURCE location.for:22 */
/*<       lctnitmctab(1)='NONE' >*/
    s_copy(feq_gen_lctnitm_comc_d_1.lctnitmctab, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4);
/*     Default for: HGRID */
/* SOURCE location.for:24 */
/*<       lctnitmctab(2)='NONE' >*/
    s_copy(feq_gen_lctnitm_comc_d_1.lctnitmctab + 64, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4);
/*     Default for: VDATUM */
/* SOURCE location.for:26 */
/*<       lctnitmctab(3)='NONE' >*/
    s_copy(feq_gen_lctnitm_comc_d_1.lctnitmctab + 128, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4);
/*     Default for: UNITSYS */
/* SOURCE location.for:28 */
/*<       lctnitmctab(4)='NONE' >*/
    s_copy(feq_gen_lctnitm_comc_d_1.lctnitmctab + 192, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4);
/*     Default for: BASIS */
/* SOURCE location.for:30 */
/*<       lctnitmctab(5)='NONE' >*/
    s_copy(feq_gen_lctnitm_comc_d_1.lctnitmctab + 256, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4);
/*     We set the default for the following items to a value thaat */
/*     is negative and smaller than any hgrid value that might make */
/*     sense.  Of course I am assuming that the person defining an hgrid */
/*     uses either feet or meters.  If they choose some stupid unit, */
/*     that is too small, then they deserve to get stupid results:) */
/*     That value is that for 25000/4=6250 miles*5280 ft/mile = 33d6.  Which */
/*     is slightly larger than one fourth the circumference of the */
/*     earth. */
/*     Default for: EASTING */
/* SOURCE location.for:40 */
/*<       lctnitmdtab(1)=-33d6 >*/
    feq_gen_lctnitm_com_d_1.lctnitmdtab[0] = -3.3e7;
/*     Default for: NORTHING */
/* SOURCE location.for:42 */
/*<       lctnitmdtab(2)=-33d6 >*/
    feq_gen_lctnitm_com_d_1.lctnitmdtab[1] = -3.3e7;
/* SOURCE location.for:44 */
/*<       return >*/
    return 0;
/* SOURCE location.for:45 */
/*<       end >*/
} /* set_lctn_item_defaults__ */




/* SOURCE location.for:49 */
/*<        >*/
/* Subroutine */ int feq_gen_set_lctn_items_d_(char *zone, char *hgrid, char *vdatum, 
	char *unitsys, char *basis, doublereal *easting, doublereal *northing,
	 ftnlen zone_len, ftnlen hgrid_len, ftnlen vdatum_len, ftnlen 
	unitsys_len, ftnlen basis_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_chk_vdatum_unitsys_d_(integer *, char *, char *
	    , char *, ftnlen, ftnlen, ftnlen);

/*     Set items for location for various commands, many in fact:) */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE location.for:56 */
/*<       implicitnone >*/
/* SOURCE location.for:58 */
/*<       real*8easting,northing >*/
/* SOURCE location.for:59 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/* INCLUDE location.for:63 */
/* SOURCE lctnitem.cmn:1 */
/*<       integermaxr_lctnitm,maxc_lctnitm,maxdp_lctnitm >*/
/* SOURCE lctnitem.cmn:2 */
/*<       parameter(maxr_lctnitm=4,maxc_lctnitm=5,maxdp_lctnitm=2) >*/
/* SOURCE lctnitem.cmn:3 */
/*<       integerlctnitmitab(maxr_lctnitm) >*/
/* SOURCE lctnitem.cmn:4 */
/*<       reallctnitmftab(maxr_lctnitm) >*/
/* SOURCE lctnitem.cmn:5 */
/*<       real*8lctnitmdtab(maxdp_lctnitm) >*/
/* SOURCE lctnitem.cmn:6 */
/*<       character*64lctnitmctab(maxc_lctnitm) >*/
/* SOURCE lctnitem.cmn:8 */
/*<       common/lctnitm_com/lctnitmdtab,lctnitmitab,lctnitmftab >*/
/* SOURCE lctnitem.cmn:10 */
/*<       common/lctnitm_comc/lctnitmctab >*/
/* INCLUDE location.for:64 */
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
/*     Set the value for ZONE */
/* SOURCE location.for:67 */
/*<       zone=lctnitmctab(1) >*/
    s_copy(zone, feq_gen_lctnitm_comc_d_1.lctnitmctab, (ftnlen)8, (ftnlen)64);
/*     Set the value for HGRID */
/* SOURCE location.for:69 */
/*<       hgrid=lctnitmctab(2) >*/
    s_copy(hgrid, feq_gen_lctnitm_comc_d_1.lctnitmctab + 64, (ftnlen)8, (ftnlen)64);
/*     Set the value for VDATUM */
/* SOURCE location.for:71 */
/*<       vdatum=lctnitmctab(3) >*/
    s_copy(vdatum, feq_gen_lctnitm_comc_d_1.lctnitmctab + 128, (ftnlen)8, (ftnlen)64);
/*     Set the value for UNITSYS */
/* SOURCE location.for:73 */
/*<       unitsys=lctnitmctab(4) >*/
    s_copy(unitsys, feq_gen_lctnitm_comc_d_1.lctnitmctab + 192, (ftnlen)8, (ftnlen)64);
/*     Set the value for BASIS */
/* SOURCE location.for:75 */
/*<       basis=lctnitmctab(5) >*/
    s_copy(basis, feq_gen_lctnitm_comc_d_1.lctnitmctab + 256, (ftnlen)8, (ftnlen)64);
/*     Set the value for EASTING */
/* SOURCE location.for:77 */
/*<       easting=lctnitmdtab(1) >*/
    *easting = feq_gen_lctnitm_com_d_1.lctnitmdtab[0];
/*     Set the value for NORTHING */
/* SOURCE location.for:79 */
/*<       northing=lctnitmdtab(2) >*/
    *northing = feq_gen_lctnitm_com_d_1.lctnitmdtab[1];
/* SOURCE location.for:81 */
/*<        >*/
    feq_gen_chk_vdatum_unitsys_d_(&feq_gen_stdun_com_d_1.std6, vdatum, unitsys, const_cast<char*>(" during comma\
nd input"), (ftnlen)8, (ftnlen)8, (ftnlen)21);
/* SOURCE location.for:85 */
/*<       return >*/
    return 0;
/* SOURCE location.for:86 */
/*<       end >*/
} /* set_lctn_items__ */




/* SOURCE location.for:91 */
/*<       subroutineget_lctn_items(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_lctn_items_d_(integer *stdin, integer *stdout, 
	integer *eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*22+1] = "ZONE            HGRID           V\
DATUM          UNITSYS         EASTING         NORTHING        NSIDES       \
   WSLOT           DIAMETER        QUNIT           QUNIT           MODE     \
       FIT_WITH        LABEL           CROSS           APPTAB          PKCWT\
B          PLCWTB          BASIS           SHIFT           WIDTH           H\
DATUM          ";
    static integer group[22] = { 1,1,1,1,0,0,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2 }
	    ;
    static integer feq_gen_group_index_d_[22] = { 1,2,3,4,1,3,0,0,0,0,0,0,0,0,0,0,0,0,
	    5,0,0,0 };
    static integer feq_gen_response_type_d_[22] = { 4,4,4,4,3,3,0,0,0,0,0,0,0,0,0,0,0,
	    0,4,0,0,0 };
    static integer feq_gen_convert_rule_d_[22] = { 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
	    1,0,0,0 };

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_lctn_item_defaults_d_(), feq_gen_get_named_items_d_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, integer *, real *, doublereal *, char *, integer *, 
	    ftnlen, ftnlen, ftnlen);

/*     Get the location items from those commands that do */
/*     not easily support them now. */
/* SOURCE location.for:97 */
/*<       implicitnone >*/
/* INCLUDE location.for:99 */
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
/* SOURCE location.for:101 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE location.for:103 */
/* SOURCE lctnitem.cmn:1 */
/*<       integermaxr_lctnitm,maxc_lctnitm,maxdp_lctnitm >*/
/* SOURCE lctnitem.cmn:2 */
/*<       parameter(maxr_lctnitm=4,maxc_lctnitm=5,maxdp_lctnitm=2) >*/
/* SOURCE lctnitem.cmn:3 */
/*<       integerlctnitmitab(maxr_lctnitm) >*/
/* SOURCE lctnitem.cmn:4 */
/*<       reallctnitmftab(maxr_lctnitm) >*/
/* SOURCE lctnitem.cmn:5 */
/*<       real*8lctnitmdtab(maxdp_lctnitm) >*/
/* SOURCE lctnitem.cmn:6 */
/*<       character*64lctnitmctab(maxc_lctnitm) >*/
/* SOURCE lctnitem.cmn:8 */
/*<       common/lctnitm_com/lctnitmdtab,lctnitmitab,lctnitmftab >*/
/* SOURCE lctnitem.cmn:10 */
/*<       common/lctnitm_comc/lctnitmctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE location.for:108 */
/*<        >*/
/* SOURCE location.for:111 */
/*<        >*/
/* SOURCE location.for:115 */
/*<       integermax_line >*/
/* SOURCE location.for:118 */
/*<       externalget_named_items,set_lctn_item_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE location.for:121 */
/*<        >*/
/* SOURCE location.for:123 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE location.for:125 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE location.for:128 */
/*<        >*/
/* SOURCE location.for:134 */
/*<       datagroup/4*char,2*numeric,12*nxtblk,char,3*nxtblk/ >*/
/* SOURCE location.for:137 */
/*<       datagroup_index/1,2,3,4,1,3,12*0,5,3*0/ >*/
/* SOURCE location.for:140 */
/*<       dataresponse_type/4*chrval,2*dprval,12*none,chrval,3*none/ >*/
/* SOURCE location.for:143 */
/*<       dataconvert_rule/4*lower,2*lower,12*exact,lower,3*exact/ >*/
/* SOURCE location.for:149 */
/*<       callset_lctn_item_defaults() >*/
    feq_gen_set_lctn_item_defaults_d_();
/* SOURCE location.for:151 */
/*<       max_line=6 >*/
    feq_gen_max_line_d_ = 6;
/* SOURCE location.for:152 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_22, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_4, &feq_gen_c_d_2, &feq_gen_c_d_5, const_cast<char*>("Location items"), feq_gen_lctnitm_com_d_1.lctnitmitab, 
	    feq_gen_lctnitm_com_d_1.lctnitmftab, feq_gen_lctnitm_com_d_1.lctnitmdtab, 
	    feq_gen_lctnitm_comc_d_1.lctnitmctab, eflag, (ftnlen)16, (ftnlen)14, (
	    ftnlen)64);
/* SOURCE location.for:159 */
/*<       return >*/
    return 0;
/* SOURCE location.for:161 */
/*<       end >*/
} /* get_lctn_items__ */

#ifdef __cplusplus
	}
#endif
