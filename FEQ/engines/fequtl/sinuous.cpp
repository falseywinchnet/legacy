/* sinuous.f -- translated by f2c (version 20240504).
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

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_22 = 22;
static integer feq_gen_c_d_400 = 400;
static integer feq_gen_c_d_11 = 11;




/* SOURCE sinuous.for:4 */
/*<       subroutineadjsin(maxnfl,vartyp,numsec,offset,sinu,numoff) >*/
/* Subroutine */ int adjsin_(integer *feq_storage_maxnfl, integer *vartyp, integer *
	numsec, real *feq_storage_offset, real *feq_storage_sinu, integer *feq_storage_numoff)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    integer feq_gen_i_d_, j, m, n;
    real off[11], feq_gen_sin_d_[11];
    extern /* Subroutine */ int sort2r_(integer *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Adjust the offset and sinuosity values to make later */
/*     operations simpler.  We will extend the definition of */
/*     sinuosity to practival infinity in both directions. */
/*     Infinity for this purpose is defined as 1.E7.  This is far larger */
/*     than any offset in either english or metric units should */
/*     ever be. */
/* SOURCE sinuous.for:17 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE sinuous.for:20 */
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
/* SOURCE sinuous.for:23 */
/*<       integernumsec,vartyp >*/
/* SOURCE sinuous.for:24 */
/*<       integermaxnfl(pmxsec),numoff(pmxsec) >*/
/* SOURCE sinuous.for:25 */
/*<       realoffset(pmxsec,pmxnfl),sinu(pmxsec,pmxnfl) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     MAXNFL - Maximum number of flow lines at each section */
/*     VARTYP - If VARTYP=1 then piecewise linear variation of sinuousity */
/*               with offset in a cross section is assumed; else */
/*               if VARTYP=2 then piecewise constant variation of */
/*               sinuousity with offset in a cross section is assumed. */
/*     NUMSEC - Number of cross sections in sequence */
/*     OFFSET - Offsets for the sinuousity values */
/*     SINU   - Table of sinuousities */
/*     NUMOFF - Number of offsets */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sinuous.for:39 */
/*<       integeri,j,m,n >*/
/* SOURCE sinuous.for:40 */
/*<       realoff(pmxnfl),sin(pmxnfl) >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE sinuous.for:43 */
/*<       externalsort2r >*/
/* *********************************************************************** */
/* SOURCE sinuous.for:45 */
/*<       if(vartyp.eq.1)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> numoff(feq_storage_numoff, 1);

    feq::IndexedPointer<real> sinu(feq_storage_sinu, 401);

    feq::IndexedPointer<real> offset(feq_storage_offset, 401);

    feq::IndexedPointer<integer> maxnfl(feq_storage_maxnfl, 1);

    /* Function Body */
    if (*vartyp == 1) {
/*       PIECEWISE LINEAR VARIATION.  THE SAME NUMBER OF OFFSETS AS */
/*       FLOW LINES(SINUOUSITIES) EXISTS.  COLLECT THE VALUES FROM */
/*       THE ARRAYS, SORT THEM, THEN TRANSFER THEM BACK TO */
/*       THE ARRAYS ADDING THE EXTRA POINTS AND ADJUST THE VALUE OF */
/*       NUMOFF(). */
/* SOURCE sinuous.for:52 */
/*<       do500i=1,numsec >*/
	feq_gen_i_d_1 = *numsec;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*         TRANSFER THE OFFSETS AND SINUOSITIES TO WORK SPACE */
/* SOURCE sinuous.for:54 */
/*<       n=0 >*/
	    n = 0;
/* SOURCE sinuous.for:55 */
/*<       do100j=1,pmxnfl >*/
	    for (j = 1; j <= 11; ++j) {
/* SOURCE sinuous.for:56 */
/*<       if(offset(i,j).gt.-1.e29)then >*/
		if (offset[feq_gen_i_d_ + j * 400] > (float)-1e29) {
/*             A VALUE EXISTS */
/* SOURCE sinuous.for:58 */
/*<       n=n+1 >*/
		    ++n;
/* SOURCE sinuous.for:59 */
/*<       off(n)=offset(i,j) >*/
		    off[n - 1] = offset[feq_gen_i_d_ + j * 400];
/* SOURCE sinuous.for:60 */
/*<       sin(n)=sinu(i,j) >*/
		    feq_gen_sin_d_[n - 1] = sinu[feq_gen_i_d_ + j * 400];
/* SOURCE sinuous.for:61 */
/*<       if(n.eq.maxnfl(i))goto101 >*/
		    if (n == maxnfl[feq_gen_i_d_]) {
			goto L101;
		    }
/* SOURCE sinuous.for:62 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:63 */
/*<   100 continue >*/
/* L100: */
	    }
/* SOURCE sinuous.for:64 */
/*<   101 continue >*/
L101:
/*         NOW SORT THE VALUES TO MAKE SURE THEY ARE IN ASCENDING ORDER */
/*         OF OFFSET. */
/* SOURCE sinuous.for:68 */
/*<       callsort2r(n,off,sin) >*/
	    sort2r_(&n, off, feq_gen_sin_d_);
/*         TRANSFER THEM BACK TO THE ARRAYS. */
/*         ADD A FIRST POINT, SMALLER THAN ANY THE USER WILL USE. */
/* SOURCE sinuous.for:74 */
/*<       m=1 >*/
	    m = 1;
/* SOURCE sinuous.for:75 */
/*<       offset(i,m)=-1.e7 >*/
	    offset[feq_gen_i_d_ + m * 400] = (float)-1e7;
/* SOURCE sinuous.for:76 */
/*<        >*/
	    sinu[feq_gen_i_d_ + m * 400] = static_cast<double>(feq_gen_sin_d_[0]) + static_cast<double>(static_cast<double>((static_cast<double>(offset[feq_gen_i_d_ + m * 400]) - off[0])) 
		    * (static_cast<double>(feq_gen_sin_d_[1]) - feq_gen_sin_d_[0])) / (static_cast<double>(off[1]) - off[0]);
/* SOURCE sinuous.for:78 */
/*<       if(sinu(i,m).lt.0.0)then >*/
	    if (sinu[feq_gen_i_d_ + m * 400] < (float)0.) {
/* SOURCE sinuous.for:79 */
/*<       sinu(i,m)=0.1 >*/
		sinu[feq_gen_i_d_ + m * 400] = (float).1;
/* SOURCE sinuous.for:80 */
/*<       elseif(sinu(i,m).gt.10.0)then >*/
	    } else if (sinu[feq_gen_i_d_ + m * 400] > (float)10.) {
/* SOURCE sinuous.for:81 */
/*<       sinu(i,m)=10.0 >*/
		sinu[feq_gen_i_d_ + m * 400] = (float)10.;
/* SOURCE sinuous.for:82 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:83 */
/*<       do200j=1,n >*/
	    feq_gen_i_d_2 = n;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE sinuous.for:84 */
/*<       m=m+1 >*/
		++m;
/* SOURCE sinuous.for:85 */
/*<       offset(i,m)=off(j) >*/
		offset[feq_gen_i_d_ + m * 400] = off[j - 1];
/* SOURCE sinuous.for:86 */
/*<       sinu(i,m)=sin(j) >*/
		sinu[feq_gen_i_d_ + m * 400] = feq_gen_sin_d_[j - 1];
/* SOURCE sinuous.for:87 */
/*<   200 continue >*/
/* L200: */
	    }
/*         ADD A LAST POINT LARGER THAN ANY THE USER WILL USE */
/* SOURCE sinuous.for:89 */
/*<       m=m+1 >*/
	    ++m;
/* SOURCE sinuous.for:90 */
/*<       offset(i,m)=1.e7 >*/
	    offset[feq_gen_i_d_ + m * 400] = (float)1e7;
/* SOURCE sinuous.for:91 */
/*<        >*/
	    sinu[feq_gen_i_d_ + m * 400] = static_cast<double>(feq_gen_sin_d_[n - 1]) + static_cast<double>(static_cast<double>((static_cast<double>(offset[feq_gen_i_d_ + m * 400]) - off[
		    n - 1])) * (static_cast<double>(feq_gen_sin_d_[n - 1]) - feq_gen_sin_d_[n - 2])) / (static_cast<double>(off[n - 1]) - 
		    off[n - 2]);
/* SOURCE sinuous.for:93 */
/*<       if(sinu(i,m).lt.0.0)then >*/
	    if (sinu[feq_gen_i_d_ + m * 400] < (float)0.) {
/* SOURCE sinuous.for:94 */
/*<       sinu(i,m)=0.1 >*/
		sinu[feq_gen_i_d_ + m * 400] = (float).1;
/* SOURCE sinuous.for:95 */
/*<       elseif(sinu(i,m).gt.10.0)then >*/
	    } else if (sinu[feq_gen_i_d_ + m * 400] > (float)10.) {
/* SOURCE sinuous.for:96 */
/*<       sinu(i,m)=10.0 >*/
		sinu[feq_gen_i_d_ + m * 400] = (float)10.;
/* SOURCE sinuous.for:97 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:98 */
/*<       numoff(i)=m >*/
	    numoff[feq_gen_i_d_] = m;
/* SOURCE sinuous.for:99 */
/*<   500 continue >*/
/* L500: */
	}
/* SOURCE sinuous.for:100 */
/*<       elseif(vartyp.eq.2)then >*/
    } else if (*vartyp == 2) {
/*       PIECEWISE CONSTANT VARIATION OF SINUOSITY. */
/*       THE NUMBER OF OFFSETS IS ONE LESS THAN THE NUMBER OF */
/*       SINUOUSITIES.  THE OFFSET FOR THE SINUOSITY NOT HAVING */
/*       A OFFSET SHOULD BE SET TO 1.E7.  WE THEN ADD A FIRST POINT */
/*       AS FOR PIECEWISE LINEAR BUT WE DO NOT NEED TO INTERPOLATE */
/*       FOR SINUOSITY. */
/* SOURCE sinuous.for:108 */
/*<       do1000i=1,numsec >*/
	feq_gen_i_d_1 = *numsec;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*         TRANSFER THE VALUES TO WORK SPACE AND SET THE MISSING OFFSET. */
/* SOURCE sinuous.for:110 */
/*<       n=0 >*/
	    n = 0;
/* SOURCE sinuous.for:111 */
/*<       do600j=1,pmxnfl >*/
	    for (j = 1; j <= 11; ++j) {
/* SOURCE sinuous.for:112 */
/*<       if(sinu(i,j).gt.-1.e27)then >*/
		if (sinu[feq_gen_i_d_ + j * 400] > (float)-1e27) {
/*             FOUND A VALUE */
/* SOURCE sinuous.for:114 */
/*<       n=n+1 >*/
		    ++n;
/* SOURCE sinuous.for:115 */
/*<       sin(n)=sinu(i,j) >*/
		    feq_gen_sin_d_[n - 1] = sinu[feq_gen_i_d_ + j * 400];
/* SOURCE sinuous.for:116 */
/*<       if(offset(i,j).lt.-1.e29)then >*/
		    if (offset[feq_gen_i_d_ + j * 400] < (float)-1e29) {
/*               VALUE IS MISSING */
/* SOURCE sinuous.for:118 */
/*<       off(n)=1.e7 >*/
			off[n - 1] = (float)1e7;
/* SOURCE sinuous.for:119 */
/*<       else >*/
		    } else {
/* SOURCE sinuous.for:120 */
/*<       off(n)=offset(i,j) >*/
			off[n - 1] = offset[feq_gen_i_d_ + j * 400];
/* SOURCE sinuous.for:121 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:122 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:123 */
/*<   600 continue >*/
/* L600: */
	    }
/*         SORT ON OFFSET */
/* SOURCE sinuous.for:126 */
/*<       callsort2r(n,off,sin) >*/
	    sort2r_(&n, off, feq_gen_sin_d_);
/*         TRANSFER THEM BACK TO THE ARRAYS. */
/*         ADD A FIRST POINT, SMALLER THAN ANY THE USER WILL USE. */
/* SOURCE sinuous.for:132 */
/*<       m=1 >*/
	    m = 1;
/* SOURCE sinuous.for:133 */
/*<       offset(i,m)=-1.e7 >*/
	    offset[feq_gen_i_d_ + m * 400] = (float)-1e7;
/* SOURCE sinuous.for:134 */
/*<       sinu(i,m)=sin(1) >*/
	    sinu[feq_gen_i_d_ + m * 400] = feq_gen_sin_d_[0];
/* SOURCE sinuous.for:135 */
/*<       do700j=1,n >*/
	    feq_gen_i_d_2 = n;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE sinuous.for:136 */
/*<       m=m+1 >*/
		++m;
/* SOURCE sinuous.for:137 */
/*<       offset(i,m)=off(j) >*/
		offset[feq_gen_i_d_ + m * 400] = off[j - 1];
/* SOURCE sinuous.for:138 */
/*<       sinu(i,m)=sin(j) >*/
		sinu[feq_gen_i_d_ + m * 400] = feq_gen_sin_d_[j - 1];
/* SOURCE sinuous.for:139 */
/*<   700 continue >*/
/* L700: */
	    }
/* SOURCE sinuous.for:140 */
/*<       numoff(i)=m >*/
	    numoff[feq_gen_i_d_] = m;
/* SOURCE sinuous.for:142 */
/*<  1000 continue >*/
/* L1000: */
	}
/* SOURCE sinuous.for:143 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:145 */
/*<       return >*/
    return 0;
/* SOURCE sinuous.for:146 */
/*<       end >*/
} /* adjsin_ */




/* SOURCE sinuous.for:150 */
/*<       subroutinecpsinu(stdout,numsec,jaxis,flntab,stl,nflnam,sinu,eflag) >*/
/* Subroutine */ int cpsinu_(integer *stdout, integer *numsec, integer *jaxis,
	 char *feq_storage_flntab, real *feq_storage_stl, integer *nflnam, real *feq_storage_sinu, integer *eflag,
	 ftnlen flntab_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    integer feq_gen_i_d_, iend, jcol, valid, istart;
    extern /* Subroutine */ int prsrun_(integer *, integer *, integer *, char 
	    *, integer *, integer *, real *, integer *, real *, integer *, 
	    ftnlen);

/*     + + + PURPOSE + + + */
/*     Compute the sinuosities not yet known in the sinuosity matrix. */
/* SOURCE sinuous.for:158 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE sinuous.for:161 */
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
/* SOURCE sinuous.for:164 */
/*<       integereflag,jaxis,nflnam,numsec,stdout >*/
/* SOURCE sinuous.for:165 */
/*<       realsinu(pmxsec,pmxnfl),stl(pmxsec,pmxnfl) >*/
/* SOURCE sinuous.for:166 */
/*<       characterflntab(nflnam)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NUMSEC - Number of cross sections in sequence */
/*     JAXIS  - Column in which the values for the channel axis are */
/*               stored */
/*     FLNTAB - Flow line name table */
/*     STL    - Table for flow line stations */
/*     NFLNAM - Number of flow line names */
/*     SINU   - Table of sinuousities */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sinuous.for:180 */
/*<       integeri,iend,istart,jcol,valid >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE sinuous.for:183 */
/*<       externalprsrun >*/
/* *********************************************************************** */
/*     FOR EACH NON-AXIS COLUMN, SCAN FOR CONSECUTIVE RUNS OF */
/*     STATION VALUES.  THEN FOR EACH RUN OF STATION VALUES */
/*     DEFINE THE LOCAL VALUES AND SCAN FOR CUBIC SPLINE REQUESTS. */
/*     IF CUBIC SPLINE REQUEST IS FOUND, RESCAN THE RUN OF STATION */
/*     VALUES AND COMPUTE THE SPLINE VALUES.  THERE MAY BE SPECIFIED */
/*     SINUOUSITIES INTERIOR TO THE RUN OF STATIONS. */
/* SOURCE sinuous.for:192 */
/*<       do1000jcol=1,nflnam >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> stl(feq_storage_stl, 401);

    feq::IndexedPointer<char> flntab(feq_storage_flntab, 8);

    feq::IndexedPointer<real> sinu(feq_storage_sinu, 401);

    /* Function Body */
    feq_gen_i_d_1 = *nflnam;
    for (jcol = 1; jcol <= feq_gen_i_d_1; ++jcol) {
/* SOURCE sinuous.for:193 */
/*<       if(jcol.ne.jaxis)then >*/
	if (jcol != *jaxis) {
/*         NON-AXIS COLUMN. */
/*         CLEAR THE FLAG FOR A VALID RUN OF STATIONS */
/* SOURCE sinuous.for:197 */
/*<       valid=0 >*/
	    valid = 0;
/* SOURCE sinuous.for:199 */
/*<       do900i=1,numsec >*/
	    feq_gen_i_d_2 = *numsec;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/*           SEARCH FOR A CONSECUTIVE RUN OF STATIONS IN THE CURRENT */
/*           COLUMN */
/* SOURCE sinuous.for:203 */
/*<       if(stl(i,jcol).gt.-1.e29)then >*/
		if (stl[feq_gen_i_d_ + jcol * 400] > (float)-1e29) {
/*             A VALID STATION VALUE EXISTS */
/* SOURCE sinuous.for:205 */
/*<       if(valid.eq.0)then >*/
		    if (valid == 0) {
/*               NO RUN IN PROGRESS.  START ONE. */
/* SOURCE sinuous.for:207 */
/*<       istart=i >*/
			istart = feq_gen_i_d_;
/* SOURCE sinuous.for:208 */
/*<       valid=1 >*/
			valid = 1;
/* SOURCE sinuous.for:209 */
/*<       else >*/
		    } else {
/*               RUN IN PROGRESS.  SEE IF WE ARE AT THE END OF THE */
/*               CURRENT COLUMN. */
/* SOURCE sinuous.for:212 */
/*<       if(i.eq.numsec)then >*/
			if (feq_gen_i_d_ == *numsec) {
/*                 WE ARE AT THE END OF THE COLUMN. END THE RUN */
/*                 AND PROCESS IT. */
/* SOURCE sinuous.for:216 */
/*<       iend=i >*/
			    iend = feq_gen_i_d_;
/* SOURCE sinuous.for:218 */
/*<        >*/
			    prsrun_(stdout, jaxis, &jcol, flntab + 8, &istart,
				     &iend, &stl[401], nflnam, &sinu[401], 
				    eflag, (ftnlen)8);
/* SOURCE sinuous.for:223 */
/*<       endif >*/
			}
/* SOURCE sinuous.for:224 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:225 */
/*<       else >*/
		} else {
/*             VALID STATION VALUE DOES NOT EXIST */
/* SOURCE sinuous.for:227 */
/*<       if(valid.eq.1)then >*/
		    if (valid == 1) {
/*               RUN IN PROGRESS.  END OF A RUN.  END IT AND PROCESS IT. */
/* SOURCE sinuous.for:229 */
/*<       iend=i-1 >*/
			iend = feq_gen_i_d_ - 1;
/* SOURCE sinuous.for:230 */
/*<       valid=0 >*/
			valid = 0;
/* SOURCE sinuous.for:232 */
/*<        >*/
			prsrun_(stdout, jaxis, &jcol, flntab + 8, &istart, &
				iend, &stl[401], nflnam, &sinu[401], eflag, (
				ftnlen)8);
/* SOURCE sinuous.for:238 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:239 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:240 */
/*<   900 continue >*/
/* L900: */
	    }
/* SOURCE sinuous.for:241 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:242 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE sinuous.for:244 */
/*<       return >*/
    return 0;
/* SOURCE sinuous.for:245 */
/*<       end >*/
} /* cpsinu_ */




/* SOURCE sinuous.for:249 */
/*<       subroutinelkupsn(loc,npnt,x,vartyp,sinu,offset,noff,snvec) >*/
/* Subroutine */ int lkupsn_(integer *loc, integer *npnt, real *feq_storage_x, integer *
	vartyp, real *feq_storage_sinu, real *feq_storage_offset, integer *noff, real *feq_storage_snvec)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer j, k, l;
    real arg, off[11], feq_gen_sin_d_[11];

/*     + + + PURPOSE + + + */
/*     Lookup the values of sinuosity at the given location. */
/* SOURCE sinuous.for:256 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE sinuous.for:259 */
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
/* SOURCE sinuous.for:262 */
/*<       integerloc,noff,npnt,vartyp >*/
/* SOURCE sinuous.for:263 */
/*<       realoffset(pmxsec,pmxnfl),sinu(pmxsec,pmxnfl),snvec(npnt),x(npnt) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     LOC    - Index giving location of the current sinuousity data */
/*     NPNT   - Number of points on boundary of a cross section */
/*     X      - Offsets of points on cross section boundary */
/*     VARTYP - If VARTYP=1 then piecewise linear variation of sinuousity */
/*               with offset in a cross section is assumed; else */
/*               if VARTYP=2 then piecewise constant variation of */
/*               sinuousity with offset in a cross section is assumed. */
/*     SINU   - Table of sinuousities */
/*     OFFSET - Offsets for the sinuousity values */
/*     NOFF   - Number of offsets */
/*     SNVEC  - Sinuousity at a point on a cross section boundary */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sinuous.for:280 */
/*<       integerj,k,l >*/
/* SOURCE sinuous.for:281 */
/*<       realarg,off(pmxnfl),sin(pmxnfl) >*/
/* *********************************************************************** */
/*     TRANSFER DATA TO LOCAL WORKSPACE */
/* SOURCE sinuous.for:284 */
/*<       do100j=1,noff >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> snvec(feq_storage_snvec, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> sinu(feq_storage_sinu, 401);

    feq::IndexedPointer<real> offset(feq_storage_offset, 401);

    /* Function Body */
    feq_gen_i_d_1 = *noff;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE sinuous.for:285 */
/*<       off(j)=offset(loc,j) >*/
	off[j - 1] = offset[*loc + j * 400];
/* SOURCE sinuous.for:286 */
/*<       sin(j)=sinu(loc,j) >*/
	feq_gen_sin_d_[j - 1] = sinu[*loc + j * 400];
/* SOURCE sinuous.for:287 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE sinuous.for:289 */
/*<       l=1 >*/
    l = 1;
/* SOURCE sinuous.for:290 */
/*<       if(vartyp.eq.2)then >*/
    if (*vartyp == 2) {
/*       PIECEWISE CONSTANT SINUOSITY */
/* SOURCE sinuous.for:292 */
/*<       do200k=1,npnt-1 >*/
	feq_gen_i_d_1 = *npnt - 1;
	for (k = 1; k <= feq_gen_i_d_1; ++k) {
/*         USE THE MID-POINT OF THE LINE SEGMENT TO AVOID PROBLEMS AT */
/*         THE BOUNDARY BETWEEN SUBAREAS */
/* SOURCE sinuous.for:296 */
/*<       arg=0.5*(x(k)+x(k+1)) >*/
	    arg = static_cast<double>((static_cast<double>(x[k]) + x[k + 1])) * (float).5;
/* SOURCE sinuous.for:297 */
/*<       if(arg.ge.off(l))then >*/
	    if (arg >= off[l - 1]) {
/* SOURCE sinuous.for:298 */
/*<   210 continue >*/
L210:
/* SOURCE sinuous.for:299 */
/*<       if(arg.gt.off(l+1))then >*/
		if (arg > off[l]) {
/* SOURCE sinuous.for:300 */
/*<       l=l+1 >*/
		    ++l;
/* SOURCE sinuous.for:301 */
/*<       goto210 >*/
		    goto L210;
/* SOURCE sinuous.for:302 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:303 */
/*<       else >*/
	    } else {
/* SOURCE sinuous.for:304 */
/*<   220 continue >*/
L220:
/* SOURCE sinuous.for:305 */
/*<       l=l-1 >*/
		--l;
/* SOURCE sinuous.for:306 */
/*<       if(arg.lt.off(l))goto220 >*/
		if (arg < off[l - 1]) {
		    goto L220;
		}
/* SOURCE sinuous.for:307 */
/*<       endif >*/
	    }
/*         L POINTS TO THE LEFT END OF THE INTERVAL THAT CONTAINS ARG. */
/*         FOR PIECEWISE CONSTANT VARIATION THE SINUOSITY VALUE IS */
/*         GIVEN BY INDEX L+1 */
/* SOURCE sinuous.for:312 */
/*<       snvec(k)=sin(l+1) >*/
	    snvec[k] = feq_gen_sin_d_[l];
/* SOURCE sinuous.for:313 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE sinuous.for:314 */
/*<       snvec(npnt)=snvec(npnt-1) >*/
	snvec[*npnt] = snvec[*npnt - 1];
/* SOURCE sinuous.for:315 */
/*<       else >*/
    } else {
/*       PIECEWISE LINEAR SINUOSITY */
/* SOURCE sinuous.for:317 */
/*<       do300k=1,npnt >*/
	feq_gen_i_d_1 = *npnt;
	for (k = 1; k <= feq_gen_i_d_1; ++k) {
/* SOURCE sinuous.for:318 */
/*<       arg=x(k) >*/
	    arg = x[k];
/* SOURCE sinuous.for:319 */
/*<       if(arg.ge.off(l))then >*/
	    if (arg >= off[l - 1]) {
/* SOURCE sinuous.for:320 */
/*<   310 continue >*/
L310:
/* SOURCE sinuous.for:321 */
/*<       if(arg.gt.off(l+1))then >*/
		if (arg > off[l]) {
/* SOURCE sinuous.for:322 */
/*<       l=l+1 >*/
		    ++l;
/* SOURCE sinuous.for:323 */
/*<       goto310 >*/
		    goto L310;
/* SOURCE sinuous.for:324 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:325 */
/*<       else >*/
	    } else {
/* SOURCE sinuous.for:326 */
/*<   320 continue >*/
L320:
/* SOURCE sinuous.for:327 */
/*<       l=l-1 >*/
		--l;
/* SOURCE sinuous.for:328 */
/*<       if(arg.lt.off(l))goto320 >*/
		if (arg < off[l - 1]) {
		    goto L320;
		}
/* SOURCE sinuous.for:329 */
/*<       endif >*/
	    }
/*         L POINTS TO THE LEFT END OF THE INTERVAL THAT CONTAINS ARG. */
/*         INTERPOLATE FOR THE SINUOSITY */
/* SOURCE sinuous.for:333 */
/*<       snvec(k)=sin(l)+(arg-off(l))*(sin(l+1)-sin(l))/(off(l+1)-off(l)) >*/
	    snvec[k] = static_cast<double>(feq_gen_sin_d_[l - 1]) + static_cast<double>(static_cast<double>((static_cast<double>(arg) - off[l - 1])) * (static_cast<double>(feq_gen_sin_d_[l]) - feq_gen_sin_d_[
		    l - 1])) / (static_cast<double>(off[l]) - off[l - 1]);
/* SOURCE sinuous.for:336 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE sinuous.for:337 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:338 */
/*<       return >*/
    return 0;
/* SOURCE sinuous.for:339 */
/*<       end >*/
} /* lkupsn_ */




/* SOURCE sinuous.for:343 */
/*<       subroutinefstdec(stat,jaxis,stl,eps,l,i) >*/
/* Subroutine */ int fstdec_(real *stat, integer *jaxis, real *feq_storage_stl, real *eps,
	 integer *l, integer *feq_gen_i_d_)
{
/*     + + + PURPOSE + + + */
/*     Find station when STL has stations in descending order. */
/* SOURCE sinuous.for:351 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE sinuous.for:354 */
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
/* SOURCE sinuous.for:357 */
/*<       integeri,jaxis,l >*/
/* SOURCE sinuous.for:358 */
/*<       realeps,stat,stl(pmxsec,pmxnfl) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STAT   - Station being sought */
/*     JAXIS  - Column in which the values for the channel axis are */
/*               stored */
/*     STL    - Table for flow line stations */
/*     EPS    - Tolerance for matching stations */
/*     L      - Starting index for search */
/*     I      - Index value for the station */
/* *********************************************************************** */
/* SOURCE sinuous.for:369 */
/*<       if(stat.le.stl(l,jaxis))then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> stl(feq_storage_stl, 401);

    /* Function Body */
    if (*stat <= stl[*l + *jaxis * 400]) {
/* SOURCE sinuous.for:370 */
/*<   100 continue >*/
L100:
/* SOURCE sinuous.for:371 */
/*<       if(stat.lt.stl(l+1,jaxis))then >*/
	if (*stat < stl[*l + 1 + *jaxis * 400]) {
/* SOURCE sinuous.for:372 */
/*<       l=l+1 >*/
	    ++(*l);
/* SOURCE sinuous.for:373 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE sinuous.for:374 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:375 */
/*<       else >*/
    } else {
/* SOURCE sinuous.for:376 */
/*<   110 continue >*/
L110:
/* SOURCE sinuous.for:377 */
/*<       l=l-1 >*/
	--(*l);
/* SOURCE sinuous.for:378 */
/*<       if(stat.gt.stl(l,jaxis))goto110 >*/
	if (*stat > stl[*l + *jaxis * 400]) {
	    goto L110;
	}
/* SOURCE sinuous.for:379 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:381 */
/*<       if(stat.le.stl(l+1,jaxis)+eps.and.stat.ge.stl(l+1,jaxis)-eps)then >*/
    if (*stat <= static_cast<double>(stl[*l + 1 + *jaxis * 400]) + *eps && *stat >= static_cast<double>(stl[*l + 1 + *
	    jaxis * 400]) - *eps) {
/* SOURCE sinuous.for:382 */
/*<       i=l+1 >*/
	*feq_gen_i_d_ = *l + 1;
/* SOURCE sinuous.for:383 */
/*<       else >*/
    } else {
/* SOURCE sinuous.for:384 */
/*<       if(stat.le.stl(l,jaxis)+eps.and.stat.ge.stl(l,jaxis)-eps)then >*/
	if (*stat <= static_cast<double>(stl[*l + *jaxis * 400]) + *eps && *stat >= static_cast<double>(stl[*l + *
		jaxis * 400]) - *eps) {
/* SOURCE sinuous.for:385 */
/*<       i=l >*/
	    *feq_gen_i_d_ = *l;
/* SOURCE sinuous.for:386 */
/*<       else >*/
	} else {
/* SOURCE sinuous.for:387 */
/*<       i=0 >*/
	    *feq_gen_i_d_ = 0;
/* SOURCE sinuous.for:388 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:389 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:390 */
/*<       return >*/
    return 0;
/* SOURCE sinuous.for:391 */
/*<       end >*/
} /* fstdec_ */




/* SOURCE sinuous.for:395 */
/*<       subroutinefstinc(stat,jaxis,stl,eps,l,i) >*/
/* Subroutine */ int fstinc_(real *stat, integer *jaxis, real *feq_storage_stl, real *eps,
	 integer *l, integer *feq_gen_i_d_)
{
/*     + + + PURPOSE + + + */
/*     Find station when STL has stations in ascending order. */
/* SOURCE sinuous.for:403 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE sinuous.for:406 */
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
/* SOURCE sinuous.for:409 */
/*<       integeri,jaxis,l >*/
/* SOURCE sinuous.for:410 */
/*<       realeps,stat,stl(pmxsec,pmxnfl) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STAT   - Station being sought */
/*     JAXIS  - Column in which the values for the channel axis are */
/*               stored */
/*     STL    - Table for flow line stations */
/*     EPS    - Tolerance for matching stations */
/*     L      - Starting index for search */
/*     I      - Index value for the station */
/* *********************************************************************** */
/* SOURCE sinuous.for:421 */
/*<       if(stat.ge.stl(l,jaxis))then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> stl(feq_storage_stl, 401);

    /* Function Body */
    if (*stat >= stl[*l + *jaxis * 400]) {
/* SOURCE sinuous.for:422 */
/*<   100 continue >*/
L100:
/* SOURCE sinuous.for:423 */
/*<       if(stat.gt.stl(l+1,jaxis))then >*/
	if (*stat > stl[*l + 1 + *jaxis * 400]) {
/* SOURCE sinuous.for:424 */
/*<       l=l+1 >*/
	    ++(*l);
/* SOURCE sinuous.for:425 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE sinuous.for:426 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:427 */
/*<       else >*/
    } else {
/* SOURCE sinuous.for:428 */
/*<   110 continue >*/
L110:
/* SOURCE sinuous.for:429 */
/*<       l=l-1 >*/
	--(*l);
/* SOURCE sinuous.for:430 */
/*<       if(stat.lt.stl(l,jaxis))goto110 >*/
	if (*stat < stl[*l + *jaxis * 400]) {
	    goto L110;
	}
/* SOURCE sinuous.for:431 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:433 */
/*<       if(stat.le.stl(l,jaxis)+eps.and.stat.ge.stl(l,jaxis)-eps)then >*/
    if (*stat <= static_cast<double>(stl[*l + *jaxis * 400]) + *eps && *stat >= static_cast<double>(stl[*l + *jaxis * 
	    400]) - *eps) {
/* SOURCE sinuous.for:434 */
/*<       i=l >*/
	*feq_gen_i_d_ = *l;
/* SOURCE sinuous.for:435 */
/*<       else >*/
    } else {
/* SOURCE sinuous.for:436 */
/*<       l=l+1 >*/
	++(*l);
/* SOURCE sinuous.for:437 */
/*<       if(stat.le.stl(l,jaxis)+eps.and.stat.ge.stl(l,jaxis)-eps)then >*/
	if (*stat <= static_cast<double>(stl[*l + *jaxis * 400]) + *eps && *stat >= static_cast<double>(stl[*l + *
		jaxis * 400]) - *eps) {
/* SOURCE sinuous.for:438 */
/*<       i=l >*/
	    *feq_gen_i_d_ = *l;
/* SOURCE sinuous.for:439 */
/*<       else >*/
	} else {
/* SOURCE sinuous.for:440 */
/*<       i=0 >*/
	    *feq_gen_i_d_ = 0;
/* SOURCE sinuous.for:441 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:442 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:443 */
/*<       return >*/
    return 0;
/* SOURCE sinuous.for:444 */
/*<       end >*/
} /* fstinc_ */




/* SOURCE sinuous.for:448 */
/*<        >*/
/* Subroutine */ int prsrun_(integer *stdout, integer *jaxis, integer *jcol, 
	char *feq_storage_flntab, integer *istart, integer *iend, real *feq_storage_stl, integer *
	nflnam, real *feq_storage_sinu, integer *eflag, ftnlen flntab_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:568* Only one station exists for fl\
ow line:\002,a8,\002at station:\002,f10.4)";
    static char fmt_52[] = "(/,\002 *ERR:606* Upstream-linear sinuosity impo\
ssible for \002,\002 flow line:\002,a8,/,10x,\002 at station:\002,f10.4,\002\
  No \002,\002 upstream station exists.\002)";
    static char fmt_54[] = "(/,\002 *ERR:649* Down stream-linear sinuosity i\
mpossible\002,\002 for flow line:\002,a8,/,10x,\002 at station:\002,f10.4\
,\002  No \002,\002 down stream station exists.\002)";
    static char fmt_56[] = "(/,\002 *ERR:650* `Parabolic sinuosity impossi\
ble\002,\002 for flow line:\002,a8,/,10x,\002 at station:\002,f10.4,\002 Thr\
ee consecutive stations needed.\002)";
    static char fmt_58[] = "(/,\002 *BUG:XXX* Invalid code for flow line:\
\002,a8,\002 at \002,\002station:\002,f10.4,\002 code=\002,1pe15.7)";
    static char fmt_60[] = "(/,\002 *ERR:697* Negative sinuosity found at st\
ation:\002,f10.4)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j, k, n;
    doublereal x[400], y[400];
    real h1, h2;
    integer kend;
    doublereal lval, rval;
    real hsum;
    doublereal ydot[400];
    integer cubic, lcode, rcode, spflag;
    extern /* Subroutine */ int spline_(integer *, doublereal *, doublereal *,
	     integer *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *);
    integer kstart;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__21 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Process a station run. */
/* SOURCE sinuous.for:457 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE sinuous.for:460 */
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
/* SOURCE sinuous.for:463 */
/*<       integereflag,iend,istart,jaxis,jcol,nflnam,stdout >*/
/* SOURCE sinuous.for:464 */
/*<       realsinu(pmxsec,pmxnfl),stl(pmxsec,pmxnfl) >*/
/* SOURCE sinuous.for:465 */
/*<       characterflntab(nflnam)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     JAXIS  - Column in which the values for the channel axis are */
/*               stored */
/*     JCOL   - Column in which the values for the channel axis are */
/*               stored */
/*     FLNTAB - Flow line name table */
/*     ISTART - Starting index for a station run */
/*     IEND   - Ending index for a station run */
/*     STL    - Table for flow line stations */
/*     NFLNAM - Number of flow line names */
/*     SINU   - Table of sinuousities */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sinuous.for:482 */
/*<       integercubic,j,k,kend,kstart,lcode,n,rcode,spflag >*/
/* SOURCE sinuous.for:483 */
/*<       realh1,h2,hsum >*/
/* SOURCE sinuous.for:484 */
/*<       doubleprecisionlval,rval,x(pmxsec),y(pmxsec),ydot(pmxsec) >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE sinuous.for:487 */
/*<       externalspline >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE sinuous.for:490 */
/*<    50  >*/
/* SOURCE sinuous.for:492 */
/*<    52  >*/
/* SOURCE sinuous.for:495 */
/*<    54  >*/
/* SOURCE sinuous.for:498 */
/*<    56  >*/
/* SOURCE sinuous.for:501 */
/*<    58  >*/
/* SOURCE sinuous.for:503 */
/*<    60 format(/,' *ERR:697* Negative sinuosity found at station:',f10.4) >*/
/* *********************************************************************** */
/*     SCAN FOR LOCAL SINUOSITY DEFINITION REQUESTS AND DO THEM. */
/*     SET THE CUBIC FLAG IF ANY CUBIC SPLINE REQUESTS ARE FOUND. */
/* SOURCE sinuous.for:509 */
/*<       if(istart.eq.iend)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> stl(feq_storage_stl, 401);

    feq::IndexedPointer<char> flntab(feq_storage_flntab, 8);

    feq::IndexedPointer<real> sinu(feq_storage_sinu, 401);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
    if (*istart == *iend) {
/*       INVALID RUN.  ONE POINT IS NOT SUFFICIENT TO DEFINE */
/*       SINUOSITY. */
/* SOURCE sinuous.for:513 */
/*<       write(stdout,50)flntab(jcol),stl(istart,jcol) >*/
	feq_gen_io_d__18.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__18);
	do_fio(&feq_gen_c_d_1, flntab + (*jcol << 3), (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&stl[*istart + *jcol * 400], (ftnlen)sizeof(
		real));
	e_wsfe();
/* SOURCE sinuous.for:514 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE sinuous.for:515 */
/*<       return >*/
	return 0;
/* SOURCE sinuous.for:516 */
/*<       endif >*/
    }
/*     CLEAR THE CUBIC SPLINE REQUEST FLAG */
/* SOURCE sinuous.for:520 */
/*<       cubic=0 >*/
    cubic = 0;
/* SOURCE sinuous.for:522 */
/*<       do1000k=istart,iend >*/
    feq_gen_i_d_1 = *iend;
    for (k = *istart; k <= feq_gen_i_d_1; ++k) {
/* SOURCE sinuous.for:524 */
/*<       if(sinu(k,jcol).eq.-1.e28)then >*/
	if (sinu[k + *jcol * 400] == (float)-1e28) {
/*         REQUEST FOR LINEAR EVALUATION.  TAKE AVERAGE OF LEFT HAND */
/*         AND RIGHT HAND SLOPE AS DEFINED BY THE STRAIGHT LINE SEGMENTS */
/*         ON THE LEFT AND RIGHT OF THE CURRENT POINT.  IF ONLY ONE SEGMENT */
/*         EXISTS DEFINE THE SLOPE AT THE POINT WITH THE SLOPE OF THAT */
/*         LINE SEGMENT. */
/* SOURCE sinuous.for:531 */
/*<       if(k.eq.istart)then >*/
	    if (k == *istart) {
/*           NO LEFT HAND SEGMENT EXISTS. */
/* SOURCE sinuous.for:533 */
/*<        >*/
		sinu[k + *jcol * 400] = static_cast<double>((static_cast<double>(stl[k + 1 + *jcol * 400]) - stl[k + *
			jcol * 400])) / (static_cast<double>(stl[k + 1 + *jaxis * 400]) - stl[k + *
			jaxis * 400]);
/* SOURCE sinuous.for:535 */
/*<       elseif(k.eq.iend)then >*/
	    } else if (k == *iend) {
/*           NO RIGHT HAND SEGMENT EXISTS */
/* SOURCE sinuous.for:537 */
/*<        >*/
		sinu[k + *jcol * 400] = static_cast<double>((static_cast<double>(stl[k + *jcol * 400]) - stl[k - 1 + *
			jcol * 400])) / (static_cast<double>(stl[k + *jaxis * 400]) - stl[k - 1 + *
			jaxis * 400]);
/* SOURCE sinuous.for:539 */
/*<       else >*/
	    } else {
/* SOURCE sinuous.for:540 */
/*<        >*/
		sinu[k + *jcol * 400] = static_cast<double>((static_cast<double>(static_cast<double>((static_cast<double>(stl[k + 1 + *jcol * 400]) - stl[k + *
			jcol * 400])) / (static_cast<double>(stl[k + 1 + *jaxis * 400]) - stl[k + *
			jaxis * 400])) + static_cast<double>((static_cast<double>(stl[k + *jcol * 400]) - stl[k - 1 + *
			jcol * 400])) / (static_cast<double>(stl[k + *jaxis * 400]) - stl[k - 1 + *
			jaxis * 400]))) * (float).5;
/* SOURCE sinuous.for:544 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:545 */
/*<       elseif(sinu(k,jcol).eq.-2.e28)then >*/
	} else if (sinu[k + *jcol * 400] == (float)-2e28) {
/*         REQUEST FOR USING LINE SEGMENT ON THE RIGHT. */
/* SOURCE sinuous.for:547 */
/*<       if(k.eq.iend)then >*/
	    if (k == *iend) {
/* SOURCE sinuous.for:548 */
/*<       write(stdout,54)flntab(jcol),stl(k,jcol) >*/
		feq_gen_io_d__21.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__21);
		do_fio(&feq_gen_c_d_1, flntab + (*jcol << 3), (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&stl[k + *jcol * 400], (ftnlen)sizeof(
			real));
		e_wsfe();
/* SOURCE sinuous.for:549 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE sinuous.for:550 */
/*<       else >*/
	    } else {
/* SOURCE sinuous.for:551 */
/*<        >*/
		sinu[k + *jcol * 400] = static_cast<double>((static_cast<double>(stl[k + 1 + *jcol * 400]) - stl[k + *
			jcol * 400])) / (static_cast<double>(stl[k + 1 + *jaxis * 400]) - stl[k + *
			jaxis * 400]);
/* SOURCE sinuous.for:553 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:554 */
/*<       elseif(sinu(k,jcol).eq.-3.e28)then >*/
	} else if (sinu[k + *jcol * 400] == (float)-3e28) {
/*         REQUEST FOR USING LINE SEGMENT ON THE LEFT */
/* SOURCE sinuous.for:556 */
/*<       if(k.eq.istart)then >*/
	    if (k == *istart) {
/* SOURCE sinuous.for:557 */
/*<       write(stdout,52)flntab(jcol),stl(k,jcol) >*/
		feq_gen_io_d__22.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__22);
		do_fio(&feq_gen_c_d_1, flntab + (*jcol << 3), (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&stl[k + *jcol * 400], (ftnlen)sizeof(
			real));
		e_wsfe();
/* SOURCE sinuous.for:558 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE sinuous.for:559 */
/*<       else >*/
	    } else {
/* SOURCE sinuous.for:560 */
/*<        >*/
		sinu[k + *jcol * 400] = static_cast<double>((static_cast<double>(stl[k + *jcol * 400]) - stl[k - 1 + *
			jcol * 400])) / (static_cast<double>(stl[k + *jaxis * 400]) - stl[k - 1 + *
			jaxis * 400]);
/* SOURCE sinuous.for:562 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:563 */
/*<       elseif(sinu(k,jcol).eq.-4.e28)then >*/
	} else if (sinu[k + *jcol * 400] == (float)-4e28) {
/*         REQUEST TO USE A PARABOLA FITTED TO THREE POINTS TO DEFINE */
/*         THE SINUOSITY. */
/* SOURCE sinuous.for:566 */
/*<       if(iend.lt.istart+2)then >*/
	    if (*iend < *istart + 2) {
/*           TOO FEW POINTS FOR A PARABOLA */
/* SOURCE sinuous.for:568 */
/*<       write(stdout,56)flntab(jcol),stl(k,jcol) >*/
		feq_gen_io_d__23.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__23);
		do_fio(&feq_gen_c_d_1, flntab + (*jcol << 3), (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&stl[k + *jcol * 400], (ftnlen)sizeof(
			real));
		e_wsfe();
/* SOURCE sinuous.for:569 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE sinuous.for:570 */
/*<       else >*/
	    } else {
/*           We have three consecutive points: x0, x0+h1, x0+h1+h2. */
/*           The points used depend on the location of the point */
/*           at which we wish to estimate the sinuousity. */
/* SOURCE sinuous.for:574 */
/*<       if(k.eq.istart)then >*/
		if (k == *istart) {
/*             WE ARE AT X0. */
/* SOURCE sinuous.for:576 */
/*<       h1=stl(k+1,jaxis)-stl(k,jaxis) >*/
		    h1 = static_cast<double>(stl[k + 1 + *jaxis * 400]) - stl[k + *jaxis * 400];
/* SOURCE sinuous.for:577 */
/*<       h2=stl(k+2,jaxis)-stl(k+1,jaxis) >*/
		    h2 = static_cast<double>(stl[k + 2 + *jaxis * 400]) - stl[k + 1 + *jaxis * 400]
			    ;
/* SOURCE sinuous.for:578 */
/*<       hsum=h1+h2 >*/
		    hsum = static_cast<double>(h1) + h2;
/* SOURCE sinuous.for:579 */
/*<        >*/
		    sinu[k + *jcol * 400] = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(-(static_cast<double>(static_cast<double>(h1) * (float)2.) + h2)) * stl[k + *
			    jcol * 400]) / (static_cast<double>(h1) * hsum)) + static_cast<double>(static_cast<double>(hsum) * stl[k + 1 + *
			    jcol * 400]) / (static_cast<double>(h1) * h2)) - static_cast<double>(static_cast<double>(h1) * stl[k + 2 + *jcol *
			     400]) / (static_cast<double>(hsum) * h2);
/* SOURCE sinuous.for:582 */
/*<       elseif(k.eq.iend)then >*/
		} else if (k == *iend) {
/*             WE ARE AT X0+H1+H2 */
/* SOURCE sinuous.for:584 */
/*<       h1=stl(k-1,jaxis)-stl(k-2,jaxis) >*/
		    h1 = static_cast<double>(stl[k - 1 + *jaxis * 400]) - stl[k - 2 + *jaxis * 400]
			    ;
/* SOURCE sinuous.for:585 */
/*<       h2=stl(k,jaxis)-stl(k-1,jaxis) >*/
		    h2 = static_cast<double>(stl[k + *jaxis * 400]) - stl[k - 1 + *jaxis * 400];
/* SOURCE sinuous.for:586 */
/*<       hsum=h1+h2 >*/
		    hsum = static_cast<double>(h1) + h2;
/* SOURCE sinuous.for:587 */
/*<        >*/
		    sinu[k + *jcol * 400] = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(h2) * stl[k - 2 + *jcol * 400]) / (
			    static_cast<double>(h1) * hsum)) - static_cast<double>(static_cast<double>(hsum) * stl[k - 1 + *jcol * 400]) / (
			    static_cast<double>(h1) * h2)) + static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(h2) * (float)2.) + h1)) * stl[k + *jcol *
			     400]) / (static_cast<double>(hsum) * h2);
/* SOURCE sinuous.for:590 */
/*<       else >*/
		} else {
/*             WE ARE AT X0+H1 */
/* SOURCE sinuous.for:592 */
/*<       h1=stl(k,jaxis)-stl(k-1,jaxis) >*/
		    h1 = static_cast<double>(stl[k + *jaxis * 400]) - stl[k - 1 + *jaxis * 400];
/* SOURCE sinuous.for:593 */
/*<       h2=stl(k+1,jaxis)-stl(k,jaxis) >*/
		    h2 = static_cast<double>(stl[k + 1 + *jaxis * 400]) - stl[k + *jaxis * 400];
/* SOURCE sinuous.for:594 */
/*<       hsum=h1+h2 >*/
		    hsum = static_cast<double>(h1) + h2;
/* SOURCE sinuous.for:595 */
/*<        >*/
		    sinu[k + *jcol * 400] = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(-h2) * stl[k - 1 + *jcol * 400]) / (
			    static_cast<double>(h1) * hsum)) + static_cast<double>(static_cast<double>((static_cast<double>(h2) - h1)) * stl[k + *jcol * 400]) / (
			    static_cast<double>(h1) * h2)) + static_cast<double>(static_cast<double>(h1) * stl[k + 1 + *jcol * 400]) / (static_cast<double>(hsum) *
			     h2);
/* SOURCE sinuous.for:598 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:599 */
/*<       if(sinu(k,jcol).le.0.0)then >*/
		if (sinu[k + *jcol * 400] <= (float)0.) {
/* SOURCE sinuous.for:600 */
/*<       write(stdout,60)stl(k,jaxis) >*/
		    feq_gen_io_d__27.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__27);
		    do_fio(&feq_gen_c_d_1, (char *)&stl[k + *jaxis * 400], (ftnlen)
			    sizeof(real));
		    e_wsfe();
/* SOURCE sinuous.for:601 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE sinuous.for:602 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:603 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:604 */
/*<       elseif(sinu(k,jcol).eq.-5.e28)then >*/
	} else if (sinu[k + *jcol * 400] == (float)-5e28) {
/*         REQUEST FOR CUBIC SPLINE.  SET THE CUBIC SPLINE REQUEST FLAG */
/* SOURCE sinuous.for:606 */
/*<       cubic=1 >*/
	    cubic = 1;
/* SOURCE sinuous.for:607 */
/*<       elseif(sinu(k,jcol).lt.-1.e28)then >*/
	} else if (sinu[k + *jcol * 400] < (float)-1e28) {
/* SOURCE sinuous.for:608 */
/*<       write(stdout,58)flntab(jcol),stl(k,jcol),sinu(k,jcol) >*/
	    feq_gen_io_d__28.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__28);
	    do_fio(&feq_gen_c_d_1, flntab + (*jcol << 3), (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&stl[k + *jcol * 400], (ftnlen)sizeof(real))
		    ;
	    do_fio(&feq_gen_c_d_1, (char *)&sinu[k + *jcol * 400], (ftnlen)sizeof(real)
		    );
	    e_wsfe();
/* SOURCE sinuous.for:609 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE sinuous.for:610 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:611 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE sinuous.for:614 */
/*<       if(cubic.eq.1)then >*/
    if (cubic == 1) {
/*       ONE OR MORE REQUESTS FOR A CUBIC SPLINE SLOPE IN THIS */
/*       RUN OF STATIONS.  RESCAN THE RUN AND COMPUTE ONE OR MORE */
/*       CUBIC SPLINES.  THERE MAY BE ONE OR MORE SINUOUSITIES */
/*       SPECIFIED INTERAL TO THE RUN.  THUS WE MUST FIND THE */
/*       BOUNDARY POINTS AND CONDITIONS FOR EACH SPLINE. */
/*         X GIVES THE STATIONS ALONG THE AXIS */
/*         Y GIVES THE STATIONS ALONG THE FLOW LINE AT JCOL */
/*         YDOT GIVES THE DERIVATIVE OF Y WITH RESPECT TO X. */
/*              THIS IS ALSO THE SINUOSITY. */
/*       CLEAR THE SPLINE FLAG */
/* SOURCE sinuous.for:626 */
/*<       spflag=0 >*/
	spflag = 0;
/* SOURCE sinuous.for:627 */
/*<       do2000k=istart,iend >*/
	feq_gen_i_d_1 = *iend;
	for (k = *istart; k <= feq_gen_i_d_1; ++k) {
/* SOURCE sinuous.for:628 */
/*<       if(sinu(k,jcol).eq.-5.e28)then >*/
	    if (sinu[k + *jcol * 400] == (float)-5e28) {
/*           SPLINE REQUEST.  IS ONE IN PROGRESS? */
/* SOURCE sinuous.for:630 */
/*<       if(spflag.eq.0)then >*/
		if (spflag == 0) {
/*             START A SPLINE. */
/* SOURCE sinuous.for:632 */
/*<       spflag=1 >*/
		    spflag = 1;
/*             CLEAR THE VALUE OF THE COUNTER FOR POINTS ON */
/*             THE SPLINE */
/* SOURCE sinuous.for:636 */
/*<       n=0 >*/
		    n = 0;
/*             CHECK AND SET THE END CONDITION ON THE LEFT. */
/* SOURCE sinuous.for:639 */
/*<       if(k.eq.istart)then >*/
		    if (k == *istart) {
/*               NO SINUOSITY GIVEN.  USE DEFAULT END CONDITION */
/*               OF ZERO SECOND DERIVATIVE. */
/* SOURCE sinuous.for:642 */
/*<       lcode=2 >*/
			lcode = 2;
/* SOURCE sinuous.for:643 */
/*<       lval=0.d0 >*/
			lval = 0.;
/*               TRANSFER STATIONS TO WORKSPACE */
/* SOURCE sinuous.for:646 */
/*<       n=n+1 >*/
			++n;
/* SOURCE sinuous.for:647 */
/*<       x(n)=stl(k,jaxis) >*/
			x[n - 1] = stl[k + *jaxis * 400];
/* SOURCE sinuous.for:648 */
/*<       y(n)=stl(k,jcol) >*/
			y[n - 1] = stl[k + *jcol * 400];
/*               SET THE STARTING INDEX FOR THE VALUES OF SINUOSITY */
/*               BEING DEFINED. */
/* SOURCE sinuous.for:653 */
/*<       kstart=k >*/
			kstart = k;
/* SOURCE sinuous.for:654 */
/*<       else >*/
		    } else {
/*               START OF SPLINE NOT AT START OF STATION RUN. */
/*               THE END CONDITION EXISTS AT K-1 AND IS A KNOWN */
/*               VALUE OF SINUOSITY */
/* SOURCE sinuous.for:658 */
/*<       lcode=1 >*/
			lcode = 1;
/* SOURCE sinuous.for:659 */
/*<       lval=sinu(k-1,jcol) >*/
			lval = sinu[k - 1 + *jcol * 400];
/*               SET THE STARTING INDEX FOR THE VALUES OF SINUOSITY */
/*               BEING DEFINED */
/* SOURCE sinuous.for:664 */
/*<       kstart=k-1 >*/
			kstart = k - 1;
/*               TRANSFER TWO STATION VALUES TO THE WORKSPACE */
/* SOURCE sinuous.for:667 */
/*<       n=n+1 >*/
			++n;
/* SOURCE sinuous.for:668 */
/*<       x(n)=stl(k-1,jaxis) >*/
			x[n - 1] = stl[k - 1 + *jaxis * 400];
/* SOURCE sinuous.for:669 */
/*<       y(n)=stl(k-1,jcol) >*/
			y[n - 1] = stl[k - 1 + *jcol * 400];
/* SOURCE sinuous.for:671 */
/*<       n=n+1 >*/
			++n;
/* SOURCE sinuous.for:672 */
/*<       x(n)=stl(k,jaxis) >*/
			x[n - 1] = stl[k + *jaxis * 400];
/* SOURCE sinuous.for:673 */
/*<       y(n)=stl(k,jcol) >*/
			y[n - 1] = stl[k + *jcol * 400];
/* SOURCE sinuous.for:674 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:675 */
/*<       else >*/
		} else {
/*             A SPLINE IS ALREADY IN PROGRESS AND WE HAVE ENCOUNTERED */
/*             ANOTHER SPLINE REQUEST.  CHECK IF WE HAVE REACHED */
/*             THE END OF THE STATION RUN. */
/* SOURCE sinuous.for:679 */
/*<       if(k.eq.iend)then >*/
		    if (k == *iend) {
/*               AT THE END OF THE RUN.  NO END CONDITION GIVEN BY THE */
/*               USER.  USE THE ZERO SECOND DERIVATIVE END CONDITION. */
/* SOURCE sinuous.for:682 */
/*<       rcode=2 >*/
			rcode = 2;
/* SOURCE sinuous.for:683 */
/*<       rval=0.d0 >*/
			rval = 0.;
/* SOURCE sinuous.for:685 */
/*<       n=n+1 >*/
			++n;
/* SOURCE sinuous.for:686 */
/*<       x(n)=stl(k,jaxis) >*/
			x[n - 1] = stl[k + *jaxis * 400];
/* SOURCE sinuous.for:687 */
/*<       y(n)=stl(k,jcol) >*/
			y[n - 1] = stl[k + *jcol * 400];
/*               SET THE INDEX FOR THE LAST SINUOSITY BEING DEFINED */
/* SOURCE sinuous.for:691 */
/*<       kend=k >*/
			kend = k;
/*               COMPUTE THE SPLINE AND STORE THE RESULTS IN SINU(*,*) */
/* SOURCE sinuous.for:695 */
/*<       callspline(stdout,x,y,n,lcode,lval,rcode,rval,ydot) >*/
			spline_(stdout, x, y, &n, &lcode, &lval, &rcode, &
				rval, ydot);
/* SOURCE sinuous.for:699 */
/*<       do1100j=kstart,kend >*/
			feq_gen_i_d_2 = kend;
			for (j = kstart; j <= feq_gen_i_d_2; ++j) {
/* SOURCE sinuous.for:700 */
/*<       if(ydot(j-kstart+1).le.0.0)then >*/
			    if (ydot[j - kstart] <= (float)0.) {
/* SOURCE sinuous.for:701 */
/*<       write(stdout,60)stl(j,jaxis) >*/
				feq_gen_io_d__41.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__41);
				do_fio(&feq_gen_c_d_1, (char *)&stl[j + *jaxis * 400], 
					(ftnlen)sizeof(real));
				e_wsfe();
/* SOURCE sinuous.for:702 */
/*<       eflag=1 >*/
				*eflag = 1;
/* SOURCE sinuous.for:703 */
/*<       endif >*/
			    }
/* SOURCE sinuous.for:704 */
/*<       sinu(j,jcol)=ydot(j-kstart+1) >*/
			    sinu[j + *jcol * 400] = ydot[j - kstart];
/* SOURCE sinuous.for:705 */
/*<  1100 continue >*/
/* L1100: */
			}
/*               CLEAR THE SPLINE REQUEST FLAG */
/* SOURCE sinuous.for:709 */
/*<       spflag=0 >*/
			spflag = 0;
/* SOURCE sinuous.for:710 */
/*<       else >*/
		    } else {
/*               NOT AT END AND SPLINE IS IN PROGRESS.  ADD THE POINTS */
/*               TO THE SPLINE DEFINITION. */
/* SOURCE sinuous.for:713 */
/*<       n=n+1 >*/
			++n;
/* SOURCE sinuous.for:714 */
/*<       x(n)=stl(k,jaxis) >*/
			x[n - 1] = stl[k + *jaxis * 400];
/* SOURCE sinuous.for:715 */
/*<       y(n)=stl(k,jcol) >*/
			y[n - 1] = stl[k + *jcol * 400];
/* SOURCE sinuous.for:716 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:718 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:719 */
/*<       else >*/
	    } else {
/*           KNOWN VALUE OF SINUOSITY ENCOUNTERED.  MAY GIVE AN END */
/*           CONDITION FOR A SPLINE. */
/* SOURCE sinuous.for:722 */
/*<       if(spflag.eq.1)then >*/
		if (spflag == 1) {
/*             GIVES END CONDITION FOR THE CURRENT SPLINE. */
/* SOURCE sinuous.for:725 */
/*<       rcode=1 >*/
		    rcode = 1;
/* SOURCE sinuous.for:726 */
/*<       rval=sinu(k,jcol) >*/
		    rval = sinu[k + *jcol * 400];
/* SOURCE sinuous.for:729 */
/*<       n=n+1 >*/
		    ++n;
/* SOURCE sinuous.for:730 */
/*<       x(n)=stl(k,jaxis) >*/
		    x[n - 1] = stl[k + *jaxis * 400];
/* SOURCE sinuous.for:731 */
/*<       y(n)=stl(k,jcol) >*/
		    y[n - 1] = stl[k + *jcol * 400];
/*             SET THE INDEX FOR THE LAST SINUOSITY VALUE BEING DEFINED. */
/* SOURCE sinuous.for:736 */
/*<       kend=k >*/
		    kend = k;
/*             COMPUTE THE SPLINE AND STORE THE RESULTS IN SINU(*,*) */
/* SOURCE sinuous.for:740 */
/*<       callspline(stdout,x,y,n,lcode,lval,rcode,rval,ydot) >*/
		    spline_(stdout, x, y, &n, &lcode, &lval, &rcode, &rval, 
			    ydot);
/* SOURCE sinuous.for:744 */
/*<       do1200j=kstart,kend >*/
		    feq_gen_i_d_2 = kend;
		    for (j = kstart; j <= feq_gen_i_d_2; ++j) {
/* SOURCE sinuous.for:745 */
/*<       if(ydot(j-kstart+1).le.0.0)then >*/
			if (ydot[j - kstart] <= (float)0.) {
/* SOURCE sinuous.for:746 */
/*<       write(stdout,60)stl(j,jaxis) >*/
			    feq_gen_io_d__42.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__42);
			    do_fio(&feq_gen_c_d_1, (char *)&stl[j + *jaxis * 400], (
				    ftnlen)sizeof(real));
			    e_wsfe();
/* SOURCE sinuous.for:747 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE sinuous.for:748 */
/*<       endif >*/
			}
/* SOURCE sinuous.for:749 */
/*<       sinu(j,jcol)=ydot(j-kstart+1) >*/
			sinu[j + *jcol * 400] = ydot[j - kstart];
/* SOURCE sinuous.for:750 */
/*<  1200 continue >*/
/* L1200: */
		    }
/*             CLEAR THE SPLINE REQUEST FLAG */
/* SOURCE sinuous.for:754 */
/*<       spflag=0 >*/
		    spflag = 0;
/* SOURCE sinuous.for:755 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:756 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:757 */
/*<  2000 continue >*/
/* L2000: */
	}
/* SOURCE sinuous.for:758 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:760 */
/*<       return >*/
    return 0;
/* SOURCE sinuous.for:761 */
/*<       end >*/
} /* prsrun_ */




/* SOURCE sinuous.for:765 */
/*<        >*/
/* Subroutine */ int stbin_(integer *stdin, integer *stdout, real *feq_storage_stl, real *
	feq_storage_offset, integer *feq_storage_numoff, real *feq_storage_sinu, integer *vartyp, integer *numsec,
	 integer *dir, real *eps, integer *jaxis, integer *eflag)
{
    /* Initialized data */

    static char opttab[8*22+1] = "CSPLINE CUBIC   LIN     LIND    LINEAR  LI\
NEARD LINEARU LINU    PARAB   PARABOLAPARABOLIcspline cubic   lin     lind  \
  linear  lineard linearu linu    parab   parabolaparaboli";
    static integer optval[22] = { 5,5,1,2,1,2,3,3,4,4,4,5,5,1,2,1,2,3,3,4,4,4 
	    };

    /* Format strings */
    static char fmt_2[] = "(7x,a8)";
    static char fmt_50[] = "(/,\002 *ERR:654* No values found on input line\
.\002)";
    static char fmt_52[] = "(/,\002 *ERR:655* No heading values available. L\
ines out of\002,\002 order.\002)";
    static char fmt_54[] = "(/,\002 *ERR:656* Number of sections > \002,i5\
,\002 Increase PMXSEC\002,\002 and recompile.\002)";
    static char fmt_56[] = "(/,\002 *ERR:657* LENG specified but no initial \
station\002,\002 found.\002,/,10x,\002Specify an initial station before th\
e\002,\002 first LENG line.\002)";
    static char fmt_58[] = "(/,\002 *ERR:658* Initial station missing for LE\
NG field\002,\002 containing:\002,f10.4)";
    static char fmt_60[] = "(/,\002 *ERR:659* Station missing for offset:\
\002,f10.2)";
    static char fmt_62[] = "(/,\002 *ERR:660* Number of sinuosities:\002,i5\
,\002 does not match\002,\002 number of stations:\002,i5,/,10x,\002Input out\
 of order?\002)";
    static char fmt_64[] = "(/,\002 *ERR:661* Blank heading in field no.:\
\002,i3,\002 invalid.\002)";
    static char fmt_66[] = "(/,\002 *ERR:662* Station missing for sinuosity\
=\002,f10.4)";
    static char fmt_68[] = "(/,\002 *ERR:663* Number of offsets=\002,i5,\002\
 incompatible with\002,/,10x,\002 number of flow lines=\002,i5)";
    static char fmt_70[] = "(/,\002 *ERR:671* Invalid name for an input li\
ne:\002,a4,/,10x,\002  Valid names are:STAT, LENG, OFFS, SINU, HEAD, and END.\
\002)";
    static char fmt_72[] = "(/,\002 *ERR:664* Label for 1-D axis not found\
.\002,\002  Must be AXIS, axis, or Axis.\002)";
    static char fmt_74[] = "(/,\002 *ERR:665* LENG value number\002,i5,\002 \
is undefined.\002)";
    static char fmt_76[] = "(/,\002 *ERR:666* STAT value number\002,i5,\002 \
is undefined.\002)";
    static char fmt_78[] = "(/,\002 *ERR:667* OFFS value number\002,i5,\002 \
is undefined.\002)";
    static char fmt_80[] = "(/,\002 *ERR:668* Sinuousity definition:\002,a8\
,\002 unknown.\002,\002 Assuming CUBIC.\002)";
    static char fmt_82[] = "(/,\002 *ERR:669* Sinuosity option:\002,a8,\002 \
unknown.\002,\002  Assuming LINEAR.\002)";
    static char fmt_84[] = "(/,\002 *BUG:XXX* Invalid option value=\002,i5\
,\002 for:\002,a8,\002 in STBIN\002)";
    static char fmt_86[] = "(/,\002 *ERR:670* There are:\002,i5,\002 values \
on the line\002,\002 but only\002,i5,\002 heading values\002)";
    static char fmt_88[] = "(/,\002 Sinuousity table as defined by input.\
\002)";
    static char fmt_90[] = "(/,\002 Final values of sinuosity.\002)";
    static char fmt_92[] = "(/,\002 *ERR:672 Change in sinuosity variation i\
nvalid.\002,/,10x,\002Check number of offsets or stations.\002)";
    static char fmt_94[] = "(/,\002 *ERR:673* Number of flow lines=\002,i5\
,\002 too small. Must\002,\002 be at least two flow lines.\002)";
    static char fmt_96[] = "(/,\002 *ERR:674* Change in direction of station\
ing at\002,\002 station:\002,f10.4,\002 invalid.\002)";
    static char fmt_97[] = "(/,\002 *ERR:675* Station match at station:\002,\
f10.4,\002 invalid.\002)";
    static char fmt_98[] = "(/,\002 *ERR:676* Inconsistent stationing.  Flow\
 line\002,\002 stations must all\002,10x,\002increase or must all decrease\
.\002)";
    static char fmt_99[] = "(/,\002 *ERR:677* Offset=\002,f10.2,\002 <= prev\
ious offset=\002,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_rsfi(icilist *), e_rsfi();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, k, it, nfl;
    char key[8];
    integer opt, diff[11], clen[11];
    char cval[256*11], line[196];
    integer noff, ival[11], mval;
    real rval[11];
    integer nsin;
    char term[1*11];
    integer nhead;
    real delta;
    integer isdef;
    doublereal dpval[11];
    integer terml[11];
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    integer eflag2, eflag3, vtype[11], hedflg;
    char crdnam[4];
    integer iflnam;
    char flntab[8*11];
    real mindel;
    integer nflnam, hdtocl[11];
    real oldoff;
    char sindef[8];
    extern /* Subroutine */ int adjsin_(integer *, integer *, integer *, real 
	    *, real *, integer *);
    integer maxnfl[400];
    extern /* Subroutine */ int binser_(char *, integer *, char *, integer *, 
	    ftnlen, ftnlen), getval_(integer *, char *, integer *, integer *, 
	    integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    integer mxnsin;
    extern /* Subroutine */ int cpsinu_(integer *, integer *, integer *, char 
	    *, real *, integer *, real *, integer *, ftnlen), inline_(integer 
	    *, integer *, char *, ftnlen), lsatab_(integer *, char *, integer 
	    *, char *, integer *, integer *, integer *, ftnlen, ftnlen), 
	    stbout_(integer *, integer *, real *, real *, real *, integer *, 
	    char *, ftnlen);
    integer termcls[11];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__92 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__106 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__115 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__117 = { 0, 0, 0, fmt_90, 0 };


/*     + + + PURPOSE + + + */
/*     Input the sinuousity definition table, echo results, and */
/*     compute missing sinuousity values. */
/* SOURCE sinuous.for:774 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE sinuous.for:777 */
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
/* SOURCE sinuous.for:780 */
/*<       integerdir,eflag,jaxis,numsec,stdin,stdout,vartyp >*/
/* SOURCE sinuous.for:781 */
/*<       integernumoff(pmxsec) >*/
/* SOURCE sinuous.for:782 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STL    - Table for flow line stations */
/*     OFFSET - Offsets for the sinuousity values */
/*     NUMOFF - Number of offsets */
/*     SINU   - Table of sinuousities */
/*     VARTYP - If VARTYP=1 then piecewise linear variation of sinuousity */
/*               with offset in a cross section is assumed; else */
/*               if VARTYP=2 then piecewise constant variation of */
/*               sinuousity with offset in a cross section is assumed. */
/*     NUMSEC - Number of cross sections in sequence */
/*     DIR    - If DIR > 0 then stations are ascending order, else */
/*               descending order */
/*     EPS    - Tolerance for matching stations */
/*     JAXIS  - Column in which the values for the channel axis are */
/*               stored */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE sinuous.for:805 */
/*<       integernopt >*/
/* SOURCE sinuous.for:806 */
/*<       parameter(nopt=22) >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE sinuous.for:809 */
/*<       integeroptval(nopt) >*/
/* SOURCE sinuous.for:810 */
/*<       characteropttab(nopt)*8 >*/
/* SOURCE sinuous.for:811 */
/*<       saveopttab,optval >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sinuous.for:814 */
/*<        >*/
/* SOURCE sinuous.for:816 */
/*<        >*/
/* SOURCE sinuous.for:819 */
/*<       realdelta,mindel,oldoff,rval(pmxnfl) >*/
/* SOURCE sinuous.for:820 */
/*<       doubleprecisiondpval(pmxnfl) >*/
/* SOURCE sinuous.for:821 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE sinuous.for:825 */
/*<       intrinsicabs,min >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE sinuous.for:828 */
/*<       externaladjsin,binser,cpsinu,getval,inline,lsatab,lstab,stbout >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE sinuous.for:832 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> sinu(feq_storage_sinu, 401);

    feq::IndexedPointer<integer> numoff(feq_storage_numoff, 1);

    feq::IndexedPointer<real> offset(feq_storage_offset, 401);

    feq::IndexedPointer<real> stl(feq_storage_stl, 401);

    /* Function Body */
/* SOURCE sinuous.for:836 */
/*<       dataoptval/5,5,1,2,1,2,3,3,4,4,4,5,5,1,2,1,2,3,3,4,4,4/ >*/
/* SOURCE sinuous.for:839 */
/*<     2 format(7x,a8) >*/
/* L2: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE sinuous.for:842 */
/*<    50 format(/,' *ERR:654* No values found on input line.') >*/
/* L50: */
/* SOURCE sinuous.for:843 */
/*<    52  >*/
/* L52: */
/* SOURCE sinuous.for:845 */
/*<    54  >*/
/* L54: */
/* SOURCE sinuous.for:847 */
/*<    56  >*/
/* L56: */
/* SOURCE sinuous.for:850 */
/*<    58  >*/
/* L58: */
/* SOURCE sinuous.for:852 */
/*<    60 format(/,' *ERR:659* Station missing for offset:',f10.2) >*/
/* L60: */
/* SOURCE sinuous.for:853 */
/*<    62  >*/
/* L62: */
/* SOURCE sinuous.for:855 */
/*<    64 format(/,' *ERR:661* Blank heading in field no.:',i3,' invalid.') >*/
/* L64: */
/* SOURCE sinuous.for:856 */
/*<    66 format(/,' *ERR:662* Station missing for sinuosity=',f10.4) >*/
/* L66: */
/* SOURCE sinuous.for:857 */
/*<    68  >*/
/* L68: */
/* SOURCE sinuous.for:859 */
/*<    70  >*/
/* L70: */
/* SOURCE sinuous.for:861 */
/*<    72  >*/
/* L72: */
/* SOURCE sinuous.for:863 */
/*<    74 format(/,' *ERR:665* LENG value number',i5,' is undefined.') >*/
/* L74: */
/* SOURCE sinuous.for:864 */
/*<    76 format(/,' *ERR:666* STAT value number',i5,' is undefined.') >*/
/* L76: */
/* SOURCE sinuous.for:865 */
/*<    78 format(/,' *ERR:667* OFFS value number',i5,' is undefined.') >*/
/* L78: */
/* SOURCE sinuous.for:866 */
/*<    80  >*/
/* L80: */
/* SOURCE sinuous.for:868 */
/*<    82  >*/
/* L82: */
/* SOURCE sinuous.for:870 */
/*<    84  >*/
/* L84: */
/* SOURCE sinuous.for:872 */
/*<    86  >*/
/* L86: */
/* SOURCE sinuous.for:874 */
/*<    88 format(/,' Sinuousity table as defined by input.') >*/
/* L88: */
/* SOURCE sinuous.for:875 */
/*<    90 format(/,' Final values of sinuosity.') >*/
/* L90: */
/* SOURCE sinuous.for:876 */
/*<    92  >*/
/* L92: */
/* SOURCE sinuous.for:878 */
/*<    94  >*/
/* L94: */
/* SOURCE sinuous.for:880 */
/*<    96  >*/
/* L96: */
/* SOURCE sinuous.for:882 */
/*<    97 format(/,' *ERR:675* Station match at station:',f10.4,' invalid.') >*/
/* L97: */
/* SOURCE sinuous.for:883 */
/*<    98  >*/
/* L98: */
/* SOURCE sinuous.for:885 */
/*<    99 format(/,' *ERR:677* Offset=',f10.2,' <= previous offset=',f10.2) >*/
/* L99: */
/* *********************************************************************** */
/*     GET THE SINUOSITY VALUE: LINEAR, PARABOLIC, OR CUBIC. */
/* SOURCE sinuous.for:888 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE sinuous.for:891 */
/*<       write(stdout,'(1X,A80)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A80)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)196);
    e_wsfe();
/* SOURCE sinuous.for:893 */
/*<       read(line,2)sindef >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, sindef, (ftnlen)8);
    e_rsfi();
/* SOURCE sinuous.for:895 */
/*<       callbinser(sindef,nopt,opttab,i) >*/
    binser_(sindef, &feq_gen_c_d_22, opttab, &feq_gen_i_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE sinuous.for:898 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE sinuous.for:899 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE sinuous.for:900 */
/*<       write(stdout,80)sindef >*/
	feq_gen_io_d__48.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__48);
	do_fio(&feq_gen_c_d_1, sindef, (ftnlen)8);
	e_wsfe();
/* SOURCE sinuous.for:901 */
/*<       isdef=5 >*/
	isdef = 5;
/* SOURCE sinuous.for:902 */
/*<       else >*/
    } else {
/* SOURCE sinuous.for:903 */
/*<       isdef=optval(i) >*/
	isdef = optval[feq_gen_i_d_ - 1];
/* SOURCE sinuous.for:904 */
/*<       endif >*/
    }
/*     INITIALIZE THE NUMBER OF FLOW LINE NAMES CURRENTLY KNOWN */
/* SOURCE sinuous.for:907 */
/*<       nflnam=0 >*/
    nflnam = 0;
/*     CLEAR THE HEADING FLAG. */
/* SOURCE sinuous.for:910 */
/*<       hedflg=0 >*/
    hedflg = 0;
/*     CLEAR THE COUNTER FOR THE NUMBER OF SECTIONS */
/* SOURCE sinuous.for:913 */
/*<       numsec=0 >*/
    *numsec = 0;
/*     CLEAR THE COUNTER FOR THE NUMBER OF HEADING VALUES */
/* SOURCE sinuous.for:916 */
/*<       nhead=0 >*/
    nhead = 0;
/*     CLEAR THE LOCAL ERROR FLAGS */
/* SOURCE sinuous.for:919 */
/*<       eflag2=0 >*/
    eflag2 = 0;
/* SOURCE sinuous.for:920 */
/*<       eflag3=0 >*/
    eflag3 = 0;
/*     SET THE MAXIMUM NUMBER OF USER FLOW LINES */
/* SOURCE sinuous.for:923 */
/*<       mxnsin=pmxnfl-2 >*/
    mxnsin = 9;
/*     SET THE SINUOSITY VARIATION TO UNDEFINED */
/* SOURCE sinuous.for:926 */
/*<       vartyp=-1 >*/
    *vartyp = -1;
/*     SET THE MINIMUM STATION INTERVAL TO INITIAL VALUE */
/* SOURCE sinuous.for:929 */
/*<       mindel=1.e30 >*/
    mindel = (float)1e30;
/*     INITIALIZE THE ARRAYS TO DEFAULT VALUES */
/* SOURCE sinuous.for:932 */
/*<       do110i=1,pmxsec >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 400; ++feq_gen_i_d_) {
/* SOURCE sinuous.for:933 */
/*<       maxnfl(i)=0 >*/
	maxnfl[feq_gen_i_d_ - 1] = 0;
/* SOURCE sinuous.for:934 */
/*<       numoff(i)=0 >*/
	numoff[feq_gen_i_d_] = 0;
/* SOURCE sinuous.for:935 */
/*<       do100j=1,pmxnfl >*/
	for (j = 1; j <= 11; ++j) {
/* SOURCE sinuous.for:936 */
/*<       stl(i,j)=-1.e30 >*/
	    stl[feq_gen_i_d_ + j * 400] = (float)-1e30;
/* SOURCE sinuous.for:937 */
/*<       offset(i,j)=-1.e30 >*/
	    offset[feq_gen_i_d_ + j * 400] = (float)-1e30;
/* SOURCE sinuous.for:938 */
/*<       goto(101,102,103,104,105),isdef >*/
	    switch (isdef) {
		case 1:  goto L101;
		case 2:  goto L102;
		case 3:  goto L103;
		case 4:  goto L104;
		case 5:  goto L105;
	    }
/* SOURCE sinuous.for:939 */
/*<       write(stdout,84)i,sindef >*/
	    feq_gen_io_d__59.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__59);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, sindef, (ftnlen)8);
	    e_wsfe();
/* SOURCE sinuous.for:940 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE sinuous.for:941 */
/*<   101 continue >*/
L101:
/* SOURCE sinuous.for:942 */
/*<   102 continue >*/
L102:
/* SOURCE sinuous.for:943 */
/*<   103 continue >*/
L103:
/*           TAKE AS LINEAR */
/* SOURCE sinuous.for:945 */
/*<       sinu(i,j)=-1.e28 >*/
	    sinu[feq_gen_i_d_ + j * 400] = (float)-1e28;
/* SOURCE sinuous.for:946 */
/*<       goto109 >*/
	    goto L109;
/* SOURCE sinuous.for:947 */
/*<   104 continue >*/
L104:
/*           TAKE AS PARABOLIC */
/* SOURCE sinuous.for:949 */
/*<       sinu(i,j)=-4.e28 >*/
	    sinu[feq_gen_i_d_ + j * 400] = (float)-4e28;
/* SOURCE sinuous.for:950 */
/*<       goto109 >*/
	    goto L109;
/* SOURCE sinuous.for:951 */
/*<   105 continue >*/
L105:
/*           TAKE AS CUBIC */
/* SOURCE sinuous.for:953 */
/*<       sinu(i,j)=-5.e28 >*/
	    sinu[feq_gen_i_d_ + j * 400] = (float)-5e28;
/* SOURCE sinuous.for:954 */
/*<       goto109 >*/
	    goto L109;
/* SOURCE sinuous.for:955 */
/*<   109 continue >*/
L109:
/* SOURCE sinuous.for:956 */
/*<   100 continue >*/
/* L100: */
	    ;
	}
/* SOURCE sinuous.for:957 */
/*<   110 continue >*/
/* L110: */
    }
/*     Clear the station difference flag and the flow line name */
/*     table. */
/* SOURCE sinuous.for:961 */
/*<       do112j=1,pmxnfl >*/
    for (j = 1; j <= 11; ++j) {
/* SOURCE sinuous.for:962 */
/*<       diff(j)=0.0 >*/
	diff[j - 1] = (float)0.;
/* SOURCE sinuous.for:963 */
/*<       flntab(j)=' ' >*/
	s_copy(flntab + (j - 1 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE sinuous.for:964 */
/*<   112 continue >*/
/* L112: */
    }
/* SOURCE sinuous.for:966 */
/*<  9999 continue >*/
L9999:
/* SOURCE sinuous.for:967 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE sinuous.for:970 */
/*<       write(stdout,'(1X,A80)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A80)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)196);
    e_wsfe();
/*       USE THE FIRST FOUR CHARS OF LINE TO DEFINE THE NATURE OF */
/*       THE REMAINDER OF THE LINE. */
/* SOURCE sinuous.for:975 */
/*<       crdnam=line(1:4) >*/
    s_copy(crdnam, line, (ftnlen)4, (ftnlen)4);
/* SOURCE sinuous.for:977 */
/*<       if(crdnam.eq.'    ')then >*/
    if (s_cmp(crdnam, const_cast<char*>("    "), (ftnlen)4, (ftnlen)4) == 0) {
/*         SKIP BLANK LINES */
/* SOURCE sinuous.for:979 */
/*<       goto9999 >*/
	goto L9999;
/* SOURCE sinuous.for:980 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:982 */
/*<        >*/
    if (s_cmp(crdnam, const_cast<char*>("END"), (ftnlen)4, (ftnlen)3) != 0 && s_cmp(crdnam, 
	    const_cast<char*>("end"), (ftnlen)4, (ftnlen)3) != 0 && s_cmp(crdnam, const_cast<char*>("HEAD"), (
	    ftnlen)4, (ftnlen)4) != 0 && s_cmp(crdnam, const_cast<char*>("head"), (ftnlen)4, (
	    ftnlen)4) != 0) {
/*         ALL OTHER OPTIONS HAVE ALL VALUES REAL. */
/* SOURCE sinuous.for:987 */
/*<       if(crdnam.eq.'SINU'.or.crdnam.eq.'sinu')then >*/
	if (s_cmp(crdnam, const_cast<char*>("SINU"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(crdnam, 
		const_cast<char*>("sinu"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE sinuous.for:988 */
/*<       opt=1 >*/
	    opt = 1;
/* SOURCE sinuous.for:989 */
/*<       do201i=1,pmxnfl >*/
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 11; ++feq_gen_i_d_) {
/* SOURCE sinuous.for:990 */
/*<       rval(i)=-1.e30 >*/
		rval[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE sinuous.for:991 */
/*<   201 continue >*/
/* L201: */
	    }
/* SOURCE sinuous.for:992 */
/*<       else >*/
	} else {
/* SOURCE sinuous.for:993 */
/*<       opt=0 >*/
	    opt = 0;
/* SOURCE sinuous.for:995 */
/*<       do200i=1,pmxnfl >*/
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 11; ++feq_gen_i_d_) {
/* SOURCE sinuous.for:996 */
/*<       vtype(i)=2 >*/
		vtype[feq_gen_i_d_ - 1] = 2;
/* SOURCE sinuous.for:997 */
/*<       rval(i)=-1.e30 >*/
		rval[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE sinuous.for:998 */
/*<   200 continue >*/
/* L200: */
	    }
/* SOURCE sinuous.for:999 */
/*<       endif >*/
	}
/*          CALL GETVAL */
/*     I               (STDOUT, LINE(5:80), MXNSIN, OPT, */
/*     O                VTYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG2, */
/*     O                MVAL) */
/* SOURCE sinuous.for:1006 */
/*<        >*/
	getval_(stdout, line + 4, &mxnsin, &opt, vtype, ival, rval, dpval, 
		cval, clen, &eflag2, term, terml, termcls, &mval, (ftnlen)192,
		 (ftnlen)256, (ftnlen)1);
/* SOURCE sinuous.for:1012 */
/*<       if(eflag2.ne.0)then >*/
	if (eflag2 != 0) {
/*           SOME ERROR HAS OCCURRED.  SKIP TO THE NEXT LINE. */
/* SOURCE sinuous.for:1014 */
/*<       eflag3=1 >*/
	    eflag3 = 1;
/* SOURCE sinuous.for:1015 */
/*<       eflag2=0 >*/
	    eflag2 = 0;
/* SOURCE sinuous.for:1016 */
/*<       elseif(mval.eq.0)then >*/
	} else if (mval == 0) {
/*           NO VALUES FOUND. */
/* SOURCE sinuous.for:1018 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__74.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__74);
	    e_wsfe();
/* SOURCE sinuous.for:1019 */
/*<       eflag3=1 >*/
	    eflag3 = 1;
/* SOURCE sinuous.for:1020 */
/*<       elseif(hedflg.eq.0)then >*/
	} else if (hedflg == 0) {
/*           UNABLE TO PROCESS FURTHER.  HEADING LABELS ARE UNDEFINED. */
/* SOURCE sinuous.for:1022 */
/*<       write(stdout,52) >*/
	    feq_gen_io_d__75.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__75);
	    e_wsfe();
/* SOURCE sinuous.for:1023 */
/*<       eflag3=1 >*/
	    eflag3 = 1;
/* SOURCE sinuous.for:1024 */
/*<       elseif(mval.gt.nhead)then >*/
	} else if (mval > nhead) {
/*           MORE VALUES ON A LINE THAN WE HAVE DEFINED HEADINGS FOR */
/*           THE LINE */
/* SOURCE sinuous.for:1027 */
/*<       write(stdout,86)mval,nhead >*/
	    feq_gen_io_d__76.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__76);
	    do_fio(&feq_gen_c_d_1, (char *)&mval, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nhead, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE sinuous.for:1028 */
/*<       eflag3=1 >*/
	    eflag3 = 1;
/* SOURCE sinuous.for:1029 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:1031 */
/*<       if(eflag3.eq.0)then >*/
	if (eflag3 == 0) {
/* SOURCE sinuous.for:1033 */
/*<       if(crdnam.eq.'STAT'.or.crdnam.eq.'stat')then >*/
	    if (s_cmp(crdnam, const_cast<char*>("STAT"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(
		    crdnam, const_cast<char*>("stat"), (ftnlen)4, (ftnlen)4) == 0) {
/*             INPUT OF STATION DATA. */
/* SOURCE sinuous.for:1035 */
/*<       numsec=numsec+1 >*/
		++(*numsec);
/* SOURCE sinuous.for:1036 */
/*<       if(numsec.gt.pmxsec)then >*/
		if (*numsec > 400) {
/* SOURCE sinuous.for:1037 */
/*<       write(stdout,54)pmxsec >*/
		    feq_gen_io_d__77.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__77);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_400, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE sinuous.for:1038 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE sinuous.for:1039 */
/*<       numsec=pmxsec >*/
		    *numsec = 400;
/* SOURCE sinuous.for:1040 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:1041 */
/*<       nfl=0 >*/
		nfl = 0;
/* SOURCE sinuous.for:1042 */
/*<       do210j=1,mval >*/
		feq_gen_i_d_1 = mval;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE sinuous.for:1043 */
/*<       if(rval(j).gt.-1.e29)then >*/
		    if (rval[j - 1] > (float)-1e29) {
/*                 TAKE AS A VALID VALUE GIVEN BY THE USER. */
/* SOURCE sinuous.for:1045 */
/*<       it=hdtocl(j) >*/
			it = hdtocl[j - 1];
/* SOURCE sinuous.for:1046 */
/*<       stl(numsec,it)=rval(j) >*/
			stl[*numsec + it * 400] = rval[j - 1];
/* SOURCE sinuous.for:1047 */
/*<       nfl=nfl+1 >*/
			++nfl;
/* SOURCE sinuous.for:1048 */
/*<       if(numsec.gt.1)then >*/
			if (*numsec > 1) {
/*                   CHECK FOR DIRECTION OF STATIONING */
/* SOURCE sinuous.for:1050 */
/*<       if(stl(numsec-1,it).gt.-1.e29)then >*/
			    if (stl[*numsec - 1 + it * 400] > (float)-1e29) {
/*                     PRECEDING STATION IS DEFINED. */
/* SOURCE sinuous.for:1052 */
/*<       delta=stl(numsec,it)-stl(numsec-1,it) >*/
				delta = static_cast<double>(stl[*numsec + it * 400]) - stl[*numsec 
					- 1 + it * 400];
/* SOURCE sinuous.for:1053 */
/*<       mindel=min(mindel,abs(delta)) >*/
/* Computing MIN */
				feq_gen_r_d_1 = mindel, feq_gen_r_d_2 = dabs(delta);
				mindel = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE sinuous.for:1054 */
/*<       if(delta.gt.0.0)then >*/
				if (delta > (float)0.) {
/*                       STATIONS ARE ASCENDING */
/* SOURCE sinuous.for:1056 */
/*<       if(diff(it).eq.0)then >*/
				    if (diff[it - 1] == 0) {
/*                         FIRST STATION INCREMENT FOR THIS FLOWLINE */
/* SOURCE sinuous.for:1058 */
/*<       diff(it)=1 >*/
					diff[it - 1] = 1;
/* SOURCE sinuous.for:1059 */
/*<       elseif(diff(it).eq.-1)then >*/
				    } else if (diff[it - 1] == -1) {
/*                         ERROR.  CHANGE IN DIRECTION OF STATIONING */
/* SOURCE sinuous.for:1061 */
/*<       write(stdout,96)rval(j) >*/
					feq_gen_io_d__82.ciunit = *stdout;
					s_wsfe(&feq_gen_io_d__82);
					do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (
						ftnlen)sizeof(real));
					e_wsfe();
/* SOURCE sinuous.for:1062 */
/*<       eflag=1 >*/
					*eflag = 1;
/* SOURCE sinuous.for:1063 */
/*<       endif >*/
				    }
/* SOURCE sinuous.for:1064 */
/*<       elseif(delta.lt.0.0)then >*/
				} else if (delta < (float)0.) {
/*                       STATIONS ARE DESCENDING */
/* SOURCE sinuous.for:1066 */
/*<       if(diff(it).eq.0.0)then >*/
				    if ((real) diff[it - 1] == (float)0.) {
/*                         FIRST STATION INCREMENT FOR THIS FLOW LINE */
/* SOURCE sinuous.for:1068 */
/*<       diff(it)=-1 >*/
					diff[it - 1] = -1;
/* SOURCE sinuous.for:1069 */
/*<       elseif(diff(it).eq.1)then >*/
				    } else if (diff[it - 1] == 1) {
/* SOURCE sinuous.for:1070 */
/*<       write(stdout,96)rval(j) >*/
					feq_gen_io_d__83.ciunit = *stdout;
					s_wsfe(&feq_gen_io_d__83);
					do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (
						ftnlen)sizeof(real));
					e_wsfe();
/* SOURCE sinuous.for:1071 */
/*<       endif >*/
				    }
/* SOURCE sinuous.for:1072 */
/*<       else >*/
				} else {
/* SOURCE sinuous.for:1073 */
/*<       write(stdout,97)rval(j) >*/
				    feq_gen_io_d__84.ciunit = *stdout;
				    s_wsfe(&feq_gen_io_d__84);
				    do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (
					    ftnlen)sizeof(real));
				    e_wsfe();
/* SOURCE sinuous.for:1074 */
/*<       eflag=1 >*/
				    *eflag = 1;
/* SOURCE sinuous.for:1075 */
/*<       endif >*/
				}
/* SOURCE sinuous.for:1076 */
/*<       endif >*/
			    }
/* SOURCE sinuous.for:1077 */
/*<       endif >*/
			}
/* SOURCE sinuous.for:1078 */
/*<       else >*/
		    } else {
/* SOURCE sinuous.for:1079 */
/*<       write(stdout,76)j >*/
			feq_gen_io_d__85.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__85);
			do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer));
			e_wsfe();
/* SOURCE sinuous.for:1080 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE sinuous.for:1081 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:1082 */
/*<   210 continue >*/
/* L210: */
		}
/* SOURCE sinuous.for:1084 */
/*<       maxnfl(numsec)=mval >*/
		maxnfl[*numsec - 1] = mval;
/* SOURCE sinuous.for:1085 */
/*<       if(mval.lt.2)then >*/
		if (mval < 2) {
/* SOURCE sinuous.for:1086 */
/*<       write(stdout,94)mval >*/
		    feq_gen_io_d__86.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__86);
		    do_fio(&feq_gen_c_d_1, (char *)&mval, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE sinuous.for:1087 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE sinuous.for:1088 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:1089 */
/*<       elseif(crdnam.eq.'LENG'.or.crdnam.eq.'leng')then >*/
	    } else if (s_cmp(crdnam, const_cast<char*>("LENG"), (ftnlen)4, (ftnlen)4) == 0 || 
		    s_cmp(crdnam, const_cast<char*>("leng"), (ftnlen)4, (ftnlen)4) == 0) {
/*             FOUND A LINE GIVING THE FLOW LINE LENGTHS. */
/* SOURCE sinuous.for:1091 */
/*<       numsec=numsec+1 >*/
		++(*numsec);
/* SOURCE sinuous.for:1092 */
/*<       if(numsec.gt.pmxsec)then >*/
		if (*numsec > 400) {
/* SOURCE sinuous.for:1093 */
/*<       write(stdout,54)pmxsec >*/
		    feq_gen_io_d__87.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__87);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_400, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE sinuous.for:1094 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE sinuous.for:1095 */
/*<       numsec=pmxsec >*/
		    *numsec = 400;
/* SOURCE sinuous.for:1096 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:1098 */
/*<       if(numsec.lt.1.)then >*/
		if ((real) (*numsec) < (float)1.) {
/*               NO STATION VALUE GIVEN.  ERROR: IMPROPER INITIALIZATION */
/* SOURCE sinuous.for:1100 */
/*<       write(stdout,56) >*/
		    feq_gen_io_d__88.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__88);
		    e_wsfe();
/* SOURCE sinuous.for:1101 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE sinuous.for:1102 */
/*<       else >*/
		} else {
/* SOURCE sinuous.for:1104 */
/*<       nfl=0 >*/
		    nfl = 0;
/* SOURCE sinuous.for:1105 */
/*<       do310j=1,mval >*/
		    feq_gen_i_d_1 = mval;
		    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE sinuous.for:1106 */
/*<       if(rval(j).gt.-1.e29)then >*/
			if (rval[j - 1] > (float)-1e29) {
/*                   TAKE AS A VALID VALUE GIVEN BY THE USER. */
/* SOURCE sinuous.for:1108 */
/*<       k=hdtocl(j) >*/
			    k = hdtocl[j - 1];
/* SOURCE sinuous.for:1109 */
/*<       if(stl(numsec-1,k).lt.-1.e29)then >*/
			    if (stl[*numsec - 1 + k * 400] < (float)-1e29) {
/* SOURCE sinuous.for:1110 */
/*<       write(stdout,58)rval(j) >*/
				feq_gen_io_d__90.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__90);
				do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (ftnlen)
					sizeof(real));
				e_wsfe();
/* SOURCE sinuous.for:1111 */
/*<       eflag=1 >*/
				*eflag = 1;
/* SOURCE sinuous.for:1112 */
/*<       stl(numsec-1,k)=0.0 >*/
				stl[*numsec - 1 + k * 400] = (float)0.;
/* SOURCE sinuous.for:1113 */
/*<       endif >*/
			    }
/*                   ADD THE CURRENT LENGTH TO THE PREVIOUS STATION AND */
/*                   STORE AS A STATION VALUE. */
/* SOURCE sinuous.for:1116 */
/*<       stl(numsec,k)=stl(numsec-1,k)+rval(j) >*/
			    stl[*numsec + k * 400] = static_cast<double>(stl[*numsec - 1 + k * 
				    400]) + rval[j - 1];
/* SOURCE sinuous.for:1117 */
/*<       nfl=nfl+1 >*/
			    ++nfl;
/* SOURCE sinuous.for:1120 */
/*<       if(numsec.gt.1)then >*/
			    if (*numsec > 1) {
/*                     CHECK FOR DIRECTION OF STATIONING */
/* SOURCE sinuous.for:1122 */
/*<       if(stl(numsec-1,it).gt.-1.e29)then >*/
				if (stl[*numsec - 1 + it * 400] > (float)
					-1e29) {
/*                       PRECEDING STATION IS DEFINED. */
/* SOURCE sinuous.for:1124 */
/*<       delta=stl(numsec,it)-stl(numsec-1,it) >*/
				    delta = static_cast<double>(stl[*numsec + it * 400]) - stl[*
					    numsec - 1 + it * 400];
/* SOURCE sinuous.for:1125 */
/*<       mindel=min(mindel,abs(delta)) >*/
/* Computing MIN */
				    feq_gen_r_d_1 = mindel, feq_gen_r_d_2 = dabs(delta);
				    mindel = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE sinuous.for:1126 */
/*<       if(delta.gt.0.0)then >*/
				    if (delta > (float)0.) {
/*                         STATIONS ARE ASCENDING */
/* SOURCE sinuous.for:1128 */
/*<       if(diff(it).eq.0)then >*/
					if (diff[it - 1] == 0) {
/*                           FIRST STATION INCREMENT FOR THIS FLOWLINE */
/* SOURCE sinuous.for:1130 */
/*<       diff(it)=1 >*/
					    diff[it - 1] = 1;
/* SOURCE sinuous.for:1131 */
/*<       elseif(diff(it).eq.-1)then >*/
					} else if (diff[it - 1] == -1) {
/*                           ERROR.  CHANGE IN DIRECTION OF STATIONING */
/* SOURCE sinuous.for:1133 */
/*<       write(stdout,96)rval(j) >*/
					    feq_gen_io_d__91.ciunit = *stdout;
					    s_wsfe(&feq_gen_io_d__91);
					    do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1]
						    , (ftnlen)sizeof(real));
					    e_wsfe();
/* SOURCE sinuous.for:1134 */
/*<       eflag=1 >*/
					    *eflag = 1;
/* SOURCE sinuous.for:1135 */
/*<       endif >*/
					}
/* SOURCE sinuous.for:1136 */
/*<       elseif(delta.lt.0.0)then >*/
				    } else if (delta < (float)0.) {
/*                         STATIONS ARE DESCENDING */
/* SOURCE sinuous.for:1138 */
/*<       if(diff(it).eq.0.0)then >*/
					if ((real) diff[it - 1] == (float)0.) 
						{
/*                           FIRST STATION INCREMENT FOR THIS FLOW LINE */
/* SOURCE sinuous.for:1140 */
/*<       diff(it)=-1 >*/
					    diff[it - 1] = -1;
/* SOURCE sinuous.for:1141 */
/*<       elseif(diff(it).eq.1)then >*/
					} else if (diff[it - 1] == 1) {
/* SOURCE sinuous.for:1142 */
/*<       write(stdout,96)rval(j) >*/
					    feq_gen_io_d__92.ciunit = *stdout;
					    s_wsfe(&feq_gen_io_d__92);
					    do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1]
						    , (ftnlen)sizeof(real));
					    e_wsfe();
/* SOURCE sinuous.for:1143 */
/*<       endif >*/
					}
/* SOURCE sinuous.for:1144 */
/*<       else >*/
				    } else {
/* SOURCE sinuous.for:1145 */
/*<       write(stdout,97)rval(j) >*/
					feq_gen_io_d__93.ciunit = *stdout;
					s_wsfe(&feq_gen_io_d__93);
					do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (
						ftnlen)sizeof(real));
					e_wsfe();
/* SOURCE sinuous.for:1146 */
/*<       eflag=1 >*/
					*eflag = 1;
/* SOURCE sinuous.for:1147 */
/*<       endif >*/
				    }
/* SOURCE sinuous.for:1148 */
/*<       endif >*/
				}
/* SOURCE sinuous.for:1149 */
/*<       endif >*/
			    }
/* SOURCE sinuous.for:1151 */
/*<       else >*/
			} else {
/* SOURCE sinuous.for:1152 */
/*<       write(stdout,74)j >*/
			    feq_gen_io_d__94.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__94);
			    do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer))
				    ;
			    e_wsfe();
/* SOURCE sinuous.for:1153 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE sinuous.for:1154 */
/*<       endif >*/
			}
/* SOURCE sinuous.for:1155 */
/*<   310 continue >*/
/* L310: */
		    }
/* SOURCE sinuous.for:1157 */
/*<       maxnfl(numsec)=mval >*/
		    maxnfl[*numsec - 1] = mval;
/* SOURCE sinuous.for:1158 */
/*<       if(mval.lt.2)then >*/
		    if (mval < 2) {
/* SOURCE sinuous.for:1159 */
/*<       write(stdout,94)mval >*/
			feq_gen_io_d__95.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__95);
			do_fio(&feq_gen_c_d_1, (char *)&mval, (ftnlen)sizeof(integer));
			e_wsfe();
/* SOURCE sinuous.for:1160 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE sinuous.for:1161 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:1162 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:1163 */
/*<       elseif(crdnam.eq.'OFFS'.or.crdnam.eq.'offs')then >*/
	    } else if (s_cmp(crdnam, const_cast<char*>("OFFS"), (ftnlen)4, (ftnlen)4) == 0 || 
		    s_cmp(crdnam, const_cast<char*>("offs"), (ftnlen)4, (ftnlen)4) == 0) {
/*             WE HAVE OFFSET VALUES GIVEN. */
/* SOURCE sinuous.for:1165 */
/*<       noff=0 >*/
		noff = 0;
/* SOURCE sinuous.for:1166 */
/*<       oldoff=-1.e30 >*/
		oldoff = (float)-1e30;
/* SOURCE sinuous.for:1167 */
/*<       do410j=1,mval >*/
		feq_gen_i_d_1 = mval;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE sinuous.for:1168 */
/*<       if(rval(j).gt.-1.e29)then >*/
		    if (rval[j - 1] > (float)-1e29) {
/*                 TAKE AS A VALID VALUE GIVEN BY THE USER. */
/* SOURCE sinuous.for:1170 */
/*<       k=hdtocl(j) >*/
			k = hdtocl[j - 1];
/* SOURCE sinuous.for:1171 */
/*<       if(stl(numsec,k).lt.-1.e29)then >*/
			if (stl[*numsec + k * 400] < (float)-1e29) {
/* SOURCE sinuous.for:1172 */
/*<       write(stdout,60)rval(j) >*/
			    feq_gen_io_d__98.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__98);
			    do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (ftnlen)
				    sizeof(real));
			    e_wsfe();
/* SOURCE sinuous.for:1173 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE sinuous.for:1174 */
/*<       endif >*/
			}
/* SOURCE sinuous.for:1175 */
/*<       offset(numsec,k)=rval(j) >*/
			offset[*numsec + k * 400] = rval[j - 1];
/* SOURCE sinuous.for:1176 */
/*<       if(rval(j).le.oldoff)then >*/
			if (rval[j - 1] <= oldoff) {
/* SOURCE sinuous.for:1177 */
/*<       write(stdout,99)rval(j),oldoff >*/
			    feq_gen_io_d__99.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__99);
			    do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (ftnlen)
				    sizeof(real));
			    do_fio(&feq_gen_c_d_1, (char *)&oldoff, (ftnlen)sizeof(
				    real));
			    e_wsfe();
/* SOURCE sinuous.for:1178 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE sinuous.for:1179 */
/*<       endif >*/
			}
/* SOURCE sinuous.for:1180 */
/*<       oldoff=rval(j) >*/
			oldoff = rval[j - 1];
/* SOURCE sinuous.for:1181 */
/*<       noff=noff+1 >*/
			++noff;
/* SOURCE sinuous.for:1182 */
/*<       else >*/
		    } else {
/* SOURCE sinuous.for:1183 */
/*<       write(stdout,78)j >*/
			feq_gen_io_d__100.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__100);
			do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer));
			e_wsfe();
/* SOURCE sinuous.for:1184 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE sinuous.for:1185 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:1186 */
/*<   410 continue >*/
/* L410: */
		}
/* SOURCE sinuous.for:1188 */
/*<       numoff(numsec)=noff >*/
		numoff[*numsec] = noff;
/* SOURCE sinuous.for:1189 */
/*<       if(noff.gt.nfl.or.noff.lt.nfl-1)then >*/
		if (noff > nfl || noff < nfl - 1) {
/*               ERROR */
/* SOURCE sinuous.for:1191 */
/*<       write(stdout,68)noff,nfl >*/
		    feq_gen_io_d__101.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__101);
		    do_fio(&feq_gen_c_d_1, (char *)&noff, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&nfl, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE sinuous.for:1192 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE sinuous.for:1193 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:1195 */
/*<       if(nfl.eq.noff)then >*/
		if (nfl == noff) {
/* SOURCE sinuous.for:1196 */
/*<       if(vartyp.eq.-1)then >*/
		    if (*vartyp == -1) {
/*                 PIECEWISE LINEAR VARIATION */
/* SOURCE sinuous.for:1198 */
/*<       vartyp=1 >*/
			*vartyp = 1;
/* SOURCE sinuous.for:1199 */
/*<       elseif(vartyp.eq.2)then >*/
		    } else if (*vartyp == 2) {
/* SOURCE sinuous.for:1200 */
/*<       write(stdout,92) >*/
			feq_gen_io_d__102.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__102);
			e_wsfe();
/* SOURCE sinuous.for:1201 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE sinuous.for:1202 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:1203 */
/*<       else >*/
		} else {
/* SOURCE sinuous.for:1204 */
/*<       if(vartyp.eq.-1)then >*/
		    if (*vartyp == -1) {
/*                 PIECEWISE CONSTANT VARIATION */
/* SOURCE sinuous.for:1206 */
/*<       vartyp=2 >*/
			*vartyp = 2;
/* SOURCE sinuous.for:1207 */
/*<       elseif(vartyp.eq.1)then >*/
		    } else if (*vartyp == 1) {
/* SOURCE sinuous.for:1208 */
/*<       write(stdout,92) >*/
			feq_gen_io_d__103.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__103);
			e_wsfe();
/* SOURCE sinuous.for:1209 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE sinuous.for:1210 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:1211 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:1212 */
/*<       elseif(crdnam.eq.'SINU'.or.crdnam.eq.'sinu')then >*/
	    } else if (s_cmp(crdnam, const_cast<char*>("SINU"), (ftnlen)4, (ftnlen)4) == 0 || 
		    s_cmp(crdnam, const_cast<char*>("sinu"), (ftnlen)4, (ftnlen)4) == 0) {
/*             A LINE OF SINUOSITY VALUES HAS BEEN FOUND. */
/* SOURCE sinuous.for:1215 */
/*<       nsin=0 >*/
		nsin = 0;
/* SOURCE sinuous.for:1216 */
/*<       do610j=1,mval >*/
		feq_gen_i_d_1 = mval;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
/*               DO THE CONVERSION BASED ON THE TYPE FOUND. */
/* SOURCE sinuous.for:1219 */
/*<       if(vtype(j).eq.4)then >*/
		    if (vtype[j - 1] == 4) {
/*                 CHARACTER VALUE RETURNED.  SEE IF WE KNOW IT! */
/* SOURCE sinuous.for:1221 */
/*<       callbinser(cval(j)(1:8),nopt,opttab,i) >*/
			binser_(cval + (j - 1 << 8), &feq_gen_c_d_22, opttab, &feq_gen_i_d_, (
				ftnlen)8, (ftnlen)8);
/* SOURCE sinuous.for:1224 */
/*<       if(i.eq.0)then >*/
			if (feq_gen_i_d_ == 0) {
/* SOURCE sinuous.for:1225 */
/*<       write(stdout,82)cval(j)(1:8) >*/
			    feq_gen_io_d__105.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__105);
			    do_fio(&feq_gen_c_d_1, cval + (j - 1 << 8), (ftnlen)8);
			    e_wsfe();
/* SOURCE sinuous.for:1226 */
/*<       rval(j)=-1.e28 >*/
			    rval[j - 1] = (float)-1e28;
/* SOURCE sinuous.for:1227 */
/*<       goto609 >*/
			    goto L609;
/* SOURCE sinuous.for:1228 */
/*<       endif >*/
			}
/* SOURCE sinuous.for:1229 */
/*<       i=optval(i) >*/
			feq_gen_i_d_ = optval[feq_gen_i_d_ - 1];
/* SOURCE sinuous.for:1230 */
/*<       goto(601,602,603,604,605),i >*/
			switch (feq_gen_i_d_) {
			    case 1:  goto L601;
			    case 2:  goto L602;
			    case 3:  goto L603;
			    case 4:  goto L604;
			    case 5:  goto L605;
			}
/* SOURCE sinuous.for:1231 */
/*<       write(stdout,84)i,cval(j)(1:8) >*/
			feq_gen_io_d__106.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__106);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
			do_fio(&feq_gen_c_d_1, cval + (j - 1 << 8), (ftnlen)8);
			e_wsfe();
/* SOURCE sinuous.for:1232 */
/*<       stop'Abnormal stop. Errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE sinuous.for:1233 */
/*<   601 continue >*/
L601:
/*                   LINEAR OPTION FOR SINUOSITY AT A POINT */
/* SOURCE sinuous.for:1235 */
/*<       rval(j)=-1.e28 >*/
			rval[j - 1] = (float)-1e28;
/* SOURCE sinuous.for:1236 */
/*<       goto609 >*/
			goto L609;
/* SOURCE sinuous.for:1237 */
/*<   602 continue >*/
L602:
/*                   LINEAR DOWNSTREAM OPTION FOR SINUOSITY AT A POINT */
/* SOURCE sinuous.for:1239 */
/*<       rval(j)=-2.e28 >*/
			rval[j - 1] = (float)-2e28;
/* SOURCE sinuous.for:1240 */
/*<       goto609 >*/
			goto L609;
/* SOURCE sinuous.for:1241 */
/*<   603 continue >*/
L603:
/*                   LINEAR UPSTREAM OPTION FOR SINUOSITY AT A POINT */
/* SOURCE sinuous.for:1243 */
/*<       rval(j)=-3.e28 >*/
			rval[j - 1] = (float)-3e28;
/* SOURCE sinuous.for:1244 */
/*<       goto609 >*/
			goto L609;
/* SOURCE sinuous.for:1245 */
/*<   604 continue >*/
L604:
/*                   PARABOLIC OPTION FOR SINUOSITY AT A POINT */
/* SOURCE sinuous.for:1247 */
/*<       rval(j)=-4.e28 >*/
			rval[j - 1] = (float)-4e28;
/* SOURCE sinuous.for:1248 */
/*<       goto609 >*/
			goto L609;
/* SOURCE sinuous.for:1249 */
/*<   605 continue >*/
L605:
/*                   CUBIC SPLINE OPTION FOR SINUOSITY AT A POINT */
/* SOURCE sinuous.for:1251 */
/*<       rval(j)=-5.e28 >*/
			rval[j - 1] = (float)-5e28;
/* SOURCE sinuous.for:1252 */
/*<       goto609 >*/
			goto L609;
/* SOURCE sinuous.for:1253 */
/*<   609 continue >*/
L609:
/* SOURCE sinuous.for:1254 */
/*<       elseif(vtype(j).eq.-1)then >*/
			;
		    } else if (vtype[j - 1] == -1) {
/*                 ASTERISK OR DUAL COMMAS */
/* SOURCE sinuous.for:1256 */
/*<       rval(j)=-1.e30 >*/
			rval[j - 1] = (float)-1e30;
/* SOURCE sinuous.for:1257 */
/*<       nsin=nsin+1 >*/
			++nsin;
/* SOURCE sinuous.for:1258 */
/*<       else >*/
		    } else {
/*                 SHOULD BE A NUMBER */
/* SOURCE sinuous.for:1260 */
/*<       read(cval(j)(1:15),'(F15.0)')rval(j) >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 15;
			feq_gen_ici_d_1.iciunit = cval + (j - 1 << 8);
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.0)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (ftnlen)sizeof(
				real));
			e_rsfi();
/* SOURCE sinuous.for:1261 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:1262 */
/*<       if(rval(j).gt.-1.e29)then >*/
		    if (rval[j - 1] > (float)-1e29) {
/*                 TAKE AS A VALID VALUE GIVEN BY THE USER. */
/* SOURCE sinuous.for:1264 */
/*<       k=hdtocl(j) >*/
			k = hdtocl[j - 1];
/* SOURCE sinuous.for:1265 */
/*<       if(stl(numsec,k).lt.-1.e29)then >*/
			if (stl[*numsec + k * 400] < (float)-1e29) {
/* SOURCE sinuous.for:1266 */
/*<       write(stdout,66)rval(j) >*/
			    feq_gen_io_d__107.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__107);
			    do_fio(&feq_gen_c_d_1, (char *)&rval[j - 1], (ftnlen)
				    sizeof(real));
			    e_wsfe();
/* SOURCE sinuous.for:1267 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE sinuous.for:1268 */
/*<       endif >*/
			}
/* SOURCE sinuous.for:1269 */
/*<       sinu(numsec,k)=rval(j) >*/
			sinu[*numsec + k * 400] = rval[j - 1];
/* SOURCE sinuous.for:1270 */
/*<       nsin=nsin+1 >*/
			++nsin;
/* SOURCE sinuous.for:1271 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:1272 */
/*<   610 continue >*/
/* L610: */
		}
/* SOURCE sinuous.for:1275 */
/*<       if(nsin.ne.nfl)then >*/
		if (nsin != nfl) {
/*               ERROR */
/* SOURCE sinuous.for:1277 */
/*<       write(stdout,62)nsin,nfl >*/
		    feq_gen_io_d__108.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__108);
		    do_fio(&feq_gen_c_d_1, (char *)&nsin, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&nfl, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE sinuous.for:1278 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE sinuous.for:1279 */
/*<       endif >*/
		}
/* SOURCE sinuous.for:1280 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:1281 */
/*<       else >*/
	} else {
/* SOURCE sinuous.for:1282 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE sinuous.for:1283 */
/*<       eflag3=0 >*/
	    eflag3 = 0;
/* SOURCE sinuous.for:1284 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:1285 */
/*<       else >*/
    } else {
/* SOURCE sinuous.for:1287 */
/*<       if(crdnam.eq.'END'.or.crdnam.eq.'end')then >*/
	if (s_cmp(crdnam, const_cast<char*>("END"), (ftnlen)4, (ftnlen)3) == 0 || s_cmp(crdnam, 
		const_cast<char*>("end"), (ftnlen)4, (ftnlen)3) == 0) {
/*           INPUT OF SINUOSITY DEFINTION COMPLETED. */
/* SOURCE sinuous.for:1289 */
/*<       goto10000 >*/
	    goto L10000;
/* SOURCE sinuous.for:1290 */
/*<       elseif(crdnam.eq.'HEAD'.or.crdnam.eq.'head')then >*/
	} else if (s_cmp(crdnam, const_cast<char*>("HEAD"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(
		crdnam, const_cast<char*>("head"), (ftnlen)4, (ftnlen)4) == 0) {
/*           A HEADING LINE HAS BEEN FOUND.  SET TO IDENTIFIERS */
/* SOURCE sinuous.for:1293 */
/*<       opt=0 >*/
	    opt = 0;
/* SOURCE sinuous.for:1294 */
/*<       do500i=1,pmxnfl >*/
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 11; ++feq_gen_i_d_) {
/* SOURCE sinuous.for:1295 */
/*<       vtype(i)=4 >*/
		vtype[feq_gen_i_d_ - 1] = 4;
/* SOURCE sinuous.for:1296 */
/*<       cval(i)=' ' >*/
		s_copy(cval + (feq_gen_i_d_ - 1 << 8), const_cast<char*>(" "), (ftnlen)256, (ftnlen)1);
/* SOURCE sinuous.for:1297 */
/*<   500 continue >*/
/* L500: */
	    }
/*            CALL GETVAL */
/*     I                 (STDOUT, LINE(5:80), MXNSIN, OPT, */
/*     O                  VTYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG2, */
/*     O                  MVAL) */
/* SOURCE sinuous.for:1302 */
/*<        >*/
	    getval_(stdout, line + 4, &mxnsin, &opt, vtype, ival, rval, dpval,
		     cval, clen, &eflag2, term, terml, termcls, &mval, (
		    ftnlen)192, (ftnlen)256, (ftnlen)1);
/* SOURCE sinuous.for:1308 */
/*<       if(eflag2.ne.0)then >*/
	    if (eflag2 != 0) {
/*             SOME ERROR HAS OCCURRED.  SKIP TO THE NEXT LINE. */
/* SOURCE sinuous.for:1310 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE sinuous.for:1311 */
/*<       eflag2=0 >*/
		eflag2 = 0;
/* SOURCE sinuous.for:1312 */
/*<       elseif(mval.eq.0)then >*/
	    } else if (mval == 0) {
/*             NO VALUES FOUND. */
/* SOURCE sinuous.for:1314 */
/*<       write(stdout,50) >*/
		feq_gen_io_d__109.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__109);
		e_wsfe();
/* SOURCE sinuous.for:1315 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE sinuous.for:1316 */
/*<       else >*/
	    } else {
/*             HERE WE HAVE NO DETECTED ERRORS AND AT LEAST 1 AND NO */
/*             MORE THAN PMXNFL NON-DEFAULT CHARACTER VALUES IN */
/*             CVAL(*). */
/* SOURCE sinuous.for:1322 */
/*<       do510j=1,mval >*/
		feq_gen_i_d_1 = mval;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE sinuous.for:1323 */
/*<       if(cval(j).eq.' ')then >*/
		    if (s_cmp(cval + (j - 1 << 8), const_cast<char*>(" "), (ftnlen)256, (ftnlen)
			    1) == 0) {
/*                 ERROR.  HEADING NAMES MUST BE EXPLICIT-NO DEFAULT */
/*                 NAMES */
/* SOURCE sinuous.for:1326 */
/*<       write(stdout,64)j >*/
			feq_gen_io_d__110.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__110);
			do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer));
			e_wsfe();
/* SOURCE sinuous.for:1327 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE sinuous.for:1328 */
/*<       endif >*/
		    }
/* SOURCE sinuous.for:1329 */
/*<       key=cval(j)(1:8) >*/
		    s_copy(key, cval + (j - 1 << 8), (ftnlen)8, (ftnlen)8);
/*               FIND KEY IN TABLE. ADD TO TABLE IF NOT FOUND. */
/* SOURCE sinuous.for:1332 */
/*<       calllsatab(stdout,key,pmxnfl,flntab,nflnam,iflnam,eflag) >*/
		    lsatab_(stdout, key, &feq_gen_c_d_11, flntab, &nflnam, &iflnam, 
			    eflag, (ftnlen)8, (ftnlen)8);
/* SOURCE sinuous.for:1336 */
/*<       hdtocl(j)=iflnam >*/
		    hdtocl[j - 1] = iflnam;
/* SOURCE sinuous.for:1337 */
/*<   510 continue >*/
/* L510: */
		}
/*             SET THE HEADING FLAG */
/* SOURCE sinuous.for:1340 */
/*<       hedflg=1 >*/
		hedflg = 1;
/*             SET THE CURRENT NUMBER OF HEADINGS AVAILABLE */
/* SOURCE sinuous.for:1343 */
/*<       nhead=mval >*/
		nhead = mval;
/* SOURCE sinuous.for:1344 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:1345 */
/*<       else >*/
	} else {
/*           INVALID NAME FOR A LINE */
/* SOURCE sinuous.for:1347 */
/*<       write(stdout,70)crdnam >*/
	    feq_gen_io_d__113.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__113);
	    do_fio(&feq_gen_c_d_1, crdnam, (ftnlen)4);
	    e_wsfe();
/* SOURCE sinuous.for:1348 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE sinuous.for:1349 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:1350 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:1351 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE sinuous.for:1354 */
/*< 10000 continue >*/
L10000:
/*     FIND THE AXIS LOCATION */
/* SOURCE sinuous.for:1358 */
/*<       calllstab('AXIS    ',flntab,nflnam,jaxis) >*/
    lstab_(const_cast<char*>("AXIS    "), flntab, &nflnam, jaxis, (ftnlen)8, (ftnlen)8);
/* SOURCE sinuous.for:1361 */
/*<       if(jaxis.eq.0)then >*/
    if (*jaxis == 0) {
/*       TRY ANOTHER SPELLING. */
/* SOURCE sinuous.for:1363 */
/*<       calllstab('axis    ',flntab,nflnam,jaxis) >*/
	lstab_(const_cast<char*>("axis    "), flntab, &nflnam, jaxis, (ftnlen)8, (ftnlen)8);
/* SOURCE sinuous.for:1366 */
/*<       if(jaxis.eq.0)then >*/
	if (*jaxis == 0) {
/*         TRY YET ANOTHER SPELLING */
/* SOURCE sinuous.for:1368 */
/*<       calllstab('Axis    ',flntab,nflnam,jaxis) >*/
	    lstab_(const_cast<char*>("Axis    "), flntab, &nflnam, jaxis, (ftnlen)8, (ftnlen)8);
/* SOURCE sinuous.for:1371 */
/*<       if(jaxis.eq.0)then >*/
	    if (*jaxis == 0) {
/*           GIVE UP AND CALL IT A USER ERROR. */
/* SOURCE sinuous.for:1373 */
/*<       write(stdout,72) >*/
		feq_gen_io_d__114.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__114);
		e_wsfe();
/* SOURCE sinuous.for:1374 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE sinuous.for:1375 */
/*<       endif >*/
	    }
/* SOURCE sinuous.for:1376 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:1377 */
/*<       endif >*/
    }
/* SOURCE sinuous.for:1379 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/*     FORCE THE SINUOSITY ON THE AXIS TO BE 1.0 */
/* SOURCE sinuous.for:1382 */
/*<       do11000i=1,numsec >*/
    feq_gen_i_d_1 = *numsec;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE sinuous.for:1383 */
/*<       sinu(i,jaxis)=1.0 >*/
	sinu[feq_gen_i_d_ + *jaxis * 400] = (float)1.;
/* SOURCE sinuous.for:1384 */
/*< 11000 continue >*/
/* L11000: */
    }
/*     OUTPUT THE PART DEFINED BY INPUT */
/* SOURCE sinuous.for:1388 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/* SOURCE sinuous.for:1389 */
/*<       write(stdout,88) >*/
	feq_gen_io_d__115.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__115);
	e_wsfe();
/* SOURCE sinuous.for:1390 */
/*<       callstbout(stdout,numsec,stl,offset,sinu,nflnam,flntab) >*/
	stbout_(stdout, numsec, &stl[401], &offset[401], &sinu[401], &nflnam, 
		flntab, (ftnlen)8);
/* SOURCE sinuous.for:1393 */
/*<       endif >*/
    }
/*     CHECK DIRECTION OF STATIONING AND SET DIRECTION */
/* SOURCE sinuous.for:1396 */
/*<       dir=diff(1) >*/
    *dir = diff[0];
/* SOURCE sinuous.for:1397 */
/*<       do11010j=2,nflnam >*/
    feq_gen_i_d_1 = nflnam;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE sinuous.for:1398 */
/*<       if(diff(j).ne.dir)then >*/
	if (diff[j - 1] != *dir) {
/* SOURCE sinuous.for:1399 */
/*<       write(stdout,98) >*/
	    feq_gen_io_d__116.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__116);
	    e_wsfe();
/* SOURCE sinuous.for:1400 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE sinuous.for:1401 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:1402 */
/*< 11010 continue >*/
/* L11010: */
    }
/*     COMPUTE THE SINUOSITIES NOT DEFINED BY THE USER INPUT */
/* SOURCE sinuous.for:1407 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/* SOURCE sinuous.for:1408 */
/*<       callcpsinu(stdout,numsec,jaxis,flntab,stl,nflnam,sinu,eflag) >*/
	cpsinu_(stdout, numsec, jaxis, flntab, &stl[401], &nflnam, &sinu[401],
		 eflag, (ftnlen)8);
/*       OUTPUT THE FINAL SINUOSITY VALUES */
/* SOURCE sinuous.for:1415 */
/*<       write(stdout,90) >*/
	feq_gen_io_d__117.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__117);
	e_wsfe();
/* SOURCE sinuous.for:1416 */
/*<       callstbout(stdout,numsec,stl,offset,sinu,nflnam,flntab) >*/
	stbout_(stdout, numsec, &stl[401], &offset[401], &sinu[401], &nflnam, 
		flntab, (ftnlen)8);
/* SOURCE sinuous.for:1419 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/*         EXTEND THE SINUOSITY DEFINITION IN CONCORDANCE WITH THE */
/*         TYPE OF VARIATION.  WE ADD EXTRA POINTS */
/*         TO MAKE LATER LOOKUP EASIER. */
/* SOURCE sinuous.for:1426 */
/*<       calladjsin(maxnfl,vartyp,numsec,offset,sinu,numoff) >*/
	    adjsin_(maxnfl, vartyp, numsec, &offset[401], &sinu[401], &numoff[
		    1]);
/* SOURCE sinuous.for:1430 */
/*<       endif >*/
	}
/* SOURCE sinuous.for:1431 */
/*<       endif >*/
    }
/*     COMPUTE THE TOLERANCE FOR FINDING STATIONS. */
/* SOURCE sinuous.for:1435 */
/*<       eps=0.1*mindel >*/
    *eps = static_cast<double>(mindel) * (float).1;
/* SOURCE sinuous.for:1437 */
/*<       end >*/
    return 0;
} /* stbin_ */

#ifdef __cplusplus
	}
#endif
