/* tabfit.f -- translated by f2c (version 20240504).
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

static integer feq_gen_c_d_152 = 152;

/*     28 Feb 2003:  Start to develop ability to fit existing tables */
/*     with functions that will provide at least a continuous first derivative */
/*     and often a continuous second derivative.  Do this in the hope that */
/*     the Newton numerical solution will be more predictable and controllable. */



/* SOURCE tabfit.for:14 */
/*<        >*/
/* Subroutine */ int twodfit_(integer *stdout, integer *table, integer *nhu, 
	integer *nfrac, real *feq_storage_huvec, real *feq_storage_fdrop, real *feq_storage_pfdvec, real *feq_storage_q, real 
	*hdatum, integer *feq_gen_type_d_, char *source, real *zrhufd, integer *
	verbose, integer *ftp, integer *eflag, integer *ftpup, ftnlen 
	source_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    doublereal freedrop[152];
    integer feq_gen_i_d_, n;
    extern /* Subroutine */ int twodtabfit_(integer *, integer *, integer *, 
	    integer *, integer *, real *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, integer *, integer *, integer 
	    *, integer *, ftnlen);
    doublereal pfd[351];
    integer ihu, ipfd;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<doublereal> feq_heap_qmat(53352);
    doublereal *qmat = feq_heap_qmat.data()	/* was [152][351] */, huall[152];

/*     + + + PURPOSE + + + */
/*     Experiment with fitting 2-d tables of type 13. */
/* SOURCE tabfit.for:24 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE tabfit.for:27 */
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
/* SOURCE tabfit.for:30 */
/*<       integereflag,ftp,ftpup,nfrac,nhu,stdout,table,type,verbose >*/
/* SOURCE tabfit.for:32 */
/*<        >*/
/* SOURCE tabfit.for:34 */
/*<       charactersource*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TABLE  - Table number */
/*     NHU    - Number of upstream heads */
/*     NFRAC  - Number of fractions for defining partial free drop */
/*     HUVEC  - Vector of upstream heads */
/*     FDROP  - Free drop values */
/*     PFDVEC - Partial free drop vector */
/*     Q      - Flowrate */
/*     HDATUM - Datum for measuring head */
/*     TYPE   - Table type. */
/*     SOURCE - source for the table. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + SAVED VALUES + + + */
/* SOURCE tabfit.for:53 */
/*<       integerioff >*/
/* SOURCE tabfit.for:54 */
/*<       saveioff >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tabfit.for:57 */
/*<       integeri,j,k,l,knt,lim,ihu,ipfd,free >*/
/* SOURCE tabfit.for:58 */
/*<       realed,eu,qt,dqted,dqteu,dfl,dfm,dfr,dqpfd,qtl,qtm,qtr,diff,spfd >*/
/* SOURCE tabfit.for:60 */
/*<       characterdummy*7,line(10)*7,tabid*16 >*/
/* SOURCE tabfit.for:62 */
/*<       integern >*/
/* SOURCE tabfit.for:63 */
/*<        >*/
/* *********************************************************************** */
/* SOURCE tabfit.for:68 */
/*<       if(type.eq.13)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> q(feq_storage_q, 152);

    feq::IndexedPointer<real> pfdvec(feq_storage_pfdvec, 1);

    feq::IndexedPointer<real> fdrop(feq_storage_fdrop, 1);

    feq::IndexedPointer<real> huvec(feq_storage_huvec, 1);

    /* Function Body */
    if (*feq_gen_type_d_ == 13) {
/*       Need to add zero upstream head to the mix.  Flow is zero */
/*       but some partial derivatives are not! */
/* SOURCE tabfit.for:72 */
/*<       huall(1)=0.d0 >*/
	huall[0] = 0.;
/* SOURCE tabfit.for:73 */
/*<       freedrop(1)=dble(zrhufd) >*/
	freedrop[0] = (doublereal) (*zrhufd);
/* SOURCE tabfit.for:74 */
/*<       n=nhu+1 >*/
	n = *nhu + 1;
/* SOURCE tabfit.for:75 */
/*<       doi=1,nhu >*/
	feq_gen_i_d_1 = *nhu;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tabfit.for:76 */
/*<       huall(i+1)=huvec(i) >*/
	    huall[feq_gen_i_d_] = huvec[feq_gen_i_d_];
/* SOURCE tabfit.for:77 */
/*<       freedrop(i+1)=fdrop(i) >*/
	    freedrop[feq_gen_i_d_] = fdrop[feq_gen_i_d_];
/* SOURCE tabfit.for:78 */
/*<       enddo >*/
	}
/* SOURCE tabfit.for:80 */
/*<       doipfd=1,nfrac >*/
	feq_gen_i_d_1 = *nfrac;
	for (ipfd = 1; ipfd <= feq_gen_i_d_1; ++ipfd) {
/* SOURCE tabfit.for:81 */
/*<       pfd(ipfd)=dble(pfdvec(ipfd)) >*/
	    pfd[ipfd - 1] = (doublereal) pfdvec[ipfd];
/* SOURCE tabfit.for:82 */
/*<       enddo >*/
	}
/* SOURCE tabfit.for:84 */
/*<       doihu=1,n >*/
	feq_gen_i_d_1 = n;
	for (ihu = 1; ihu <= feq_gen_i_d_1; ++ihu) {
/* SOURCE tabfit.for:85 */
/*<       if(ihu.eq.1)then >*/
	    if (ihu == 1) {
/*           special case. */
/* SOURCE tabfit.for:87 */
/*<       doipfd=1,nfrac >*/
		feq_gen_i_d_2 = *nfrac;
		for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
/* SOURCE tabfit.for:88 */
/*<       qmat(ihu,ipfd)=0.d0 >*/
		    qmat[ihu + ipfd * 152 - 153] = 0.;
/* SOURCE tabfit.for:89 */
/*<       enddo >*/
		}
/* SOURCE tabfit.for:90 */
/*<       else >*/
	    } else {
/* SOURCE tabfit.for:91 */
/*<       doipfd=1,nfrac >*/
		feq_gen_i_d_2 = *nfrac;
		for (ipfd = 1; ipfd <= feq_gen_i_d_2; ++ipfd) {
/* SOURCE tabfit.for:92 */
/*<       qmat(ihu,ipfd)=dble(q(ihu-1,ipfd)) >*/
		    qmat[ihu + ipfd * 152 - 153] = (doublereal) q[ihu - 1 + 
			    ipfd * 151];
/* SOURCE tabfit.for:93 */
/*<       enddo >*/
		}
/* SOURCE tabfit.for:94 */
/*<       endif >*/
	    }
/* SOURCE tabfit.for:95 */
/*<       enddo >*/
	}
/* SOURCE tabfit.for:97 */
/*<        >*/
	twodtabfit_(stdout, table, &n, nfrac, &feq_gen_c_d_152, hdatum, huall, 
		freedrop, pfd, qmat, source, verbose, ftp, eflag, ftpup, (
		ftnlen)8);
/* SOURCE tabfit.for:105 */
/*<       endif >*/
    }
/* SOURCE tabfit.for:106 */
/*<       return >*/
    return 0;
/* SOURCE tabfit.for:107 */
/*<       end >*/
} /* twodfit_ */




/* SOURCE tabfit.for:114 */
/*<       subroutinelocate_extreme_point(stdout,yl,yr,ml,mr,h,nex,t_at_ex) >*/
/* Subroutine */ int feq_gen_locate_extreme_point_d_(integer *stdout, doublereal *yl, 
	doublereal *yr, doublereal *ml, doublereal *mr, doublereal *feq_gen_h_d_, 
	integer *nex, doublereal *feq_gen_feq_storage_t_at_ex_d_)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal a, b, feq_gen_c_d_, t1, t2;

/*     Given the function values, yl, yr, and the derivative values, */
/*     ml, mr, at each end of an interval, h, compute the location of */
/*     extreme point for the cubic that matches the four data points. */
/*     Return the extreme point in terms of the relative distance from */
/*     the left end point. */
/* SOURCE tabfit.for:123 */
/*<       implicitnone >*/
/* SOURCE tabfit.for:125 */
/*<       integernex,stdout >*/
/* SOURCE tabfit.for:127 */
/*<       real*8yl,yr,ml,mr,h,t_at_ex(2) >*/
/*     Local */
/* SOURCE tabfit.for:131 */
/*<       real*8a,b,c,t1,t2 >*/
/* *********************************************************************** */
/* SOURCE tabfit.for:135 */
/*<       c=h*ml >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> feq_gen_t_at_ex_d_(feq_gen_feq_storage_t_at_ex_d_, 1);

    /* Function Body */
    feq_gen_c_d_ = *feq_gen_h_d_ * *ml;
/* SOURCE tabfit.for:137 */
/*<       b=2.*((-2.*ml-mr)*h+3.*(yr-yl)) >*/
    b = ((*ml * (float)-2. - *mr) * *feq_gen_h_d_ + (*yr - *yl) * (float)3.) * (float)
	    2.;
/* SOURCE tabfit.for:139 */
/*<       a=3.*(h*(ml+mr)-2.*(yr-yl)) >*/
    a = (*feq_gen_h_d_ * (*ml + *mr) - (*yr - *yl) * (float)2.) * (float)3.;
/* SOURCE tabfit.for:141 */
/*<       if(b*b-4.*a*c.lt.0.d0)then >*/
    if (b * b - a * (float)4. * feq_gen_c_d_ < 0.) {
/*        write(stdout,*) ' Imaginary solution in locate_extreme_point' */
/* SOURCE tabfit.for:143 */
/*<       nex=0 >*/
	*nex = 0;
/* SOURCE tabfit.for:145 */
/*<       return >*/
	return 0;
/* SOURCE tabfit.for:146 */
/*<       endif >*/
    }
/* SOURCE tabfit.for:148 */
/*<       if(a.eq.0.d0)then >*/
    if (a == 0.) {
/* SOURCE tabfit.for:149 */
/*<       if(b.ne.0.d0)then >*/
	if (b != 0.) {
/* SOURCE tabfit.for:150 */
/*<       t1=-c/b >*/
	    t1 = -feq_gen_c_d_ / b;
/* SOURCE tabfit.for:151 */
/*<       t2=-1.0 >*/
	    t2 = (float)-1.;
/* SOURCE tabfit.for:152 */
/*<       else >*/
	} else {
/*          write(stdout,*) */
/*     a 'both a and b are zero in locate_extreme_point' */
/*          write(stdout,50) yl, yr, ml, mr, h */
/* 50    format(' ql=',1pe12.5,' qr=',1pe12.5,' ml=',1pe12.5, */
/*     a       ' mr=',1pe12.5,' h=',f10.4) */
/*          stop 'Abnormal stop. Bug found.' */
/* SOURCE tabfit.for:159 */
/*<       nex=0 >*/
	    *nex = 0;
/* SOURCE tabfit.for:160 */
/*<       return >*/
	    return 0;
/* SOURCE tabfit.for:161 */
/*<       endif >*/
	}
/* SOURCE tabfit.for:162 */
/*<       else >*/
    } else {
/*       a ne to zero here! */
/* SOURCE tabfit.for:164 */
/*<       if(c.eq.0.d0)then >*/
	if (feq_gen_c_d_ == 0.) {
/* SOURCE tabfit.for:165 */
/*<       t1=-b/a >*/
	    t1 = -b / a;
/* SOURCE tabfit.for:166 */
/*<       t2=0.d0 >*/
	    t2 = 0.;
/* SOURCE tabfit.for:167 */
/*<       else >*/
	} else {
/*         neither a nor c are zero here. */
/* SOURCE tabfit.for:169 */
/*<       if(b.lt.0.d0)then >*/
	    if (b < 0.) {
/* SOURCE tabfit.for:170 */
/*<       t1=(-b+sqrt(b*b-4.*a*c))/(2.*a) >*/
		t1 = (-b + sqrt(b * b - a * (float)4. * feq_gen_c_d_)) / (a * (float)
			2.);
/* SOURCE tabfit.for:171 */
/*<       t2=2.*c/(-b+sqrt(b*b-4.*a*c)) >*/
		t2 = feq_gen_c_d_ * (float)2. / (-b + sqrt(b * b - a * (float)4. * feq_gen_c_d_)
			);
/* SOURCE tabfit.for:172 */
/*<       else >*/
	    } else {
/* SOURCE tabfit.for:173 */
/*<       t1=2.*c/(-b-sqrt(b*b-4.*a*c)) >*/
		t1 = feq_gen_c_d_ * (float)2. / (-b - sqrt(b * b - a * (float)4. * feq_gen_c_d_)
			);
/* SOURCE tabfit.for:174 */
/*<       t2=(-b-sqrt(b*b-4.*a*c))/(2.*a) >*/
		t2 = (-b - sqrt(b * b - a * (float)4. * feq_gen_c_d_)) / (a * (float)
			2.);
/* SOURCE tabfit.for:175 */
/*<       endif >*/
	    }
/* SOURCE tabfit.for:176 */
/*<       endif >*/
	}
/* SOURCE tabfit.for:177 */
/*<       endif >*/
    }
/* SOURCE tabfit.for:178 */
/*<       if(t1.ge.0.d0.and.t1.le.1.0d0)then >*/
    if (t1 >= 0. && t1 <= 1.) {
/* SOURCE tabfit.for:179 */
/*<       nex=1 >*/
	*nex = 1;
/* SOURCE tabfit.for:180 */
/*<       t_at_ex(nex)=t1 >*/
	feq_gen_t_at_ex_d_[*nex] = t1;
/* SOURCE tabfit.for:181 */
/*<       else >*/
    } else {
/* SOURCE tabfit.for:182 */
/*<       nex=0 >*/
	*nex = 0;
/* SOURCE tabfit.for:183 */
/*<       endif >*/
    }
/* SOURCE tabfit.for:184 */
/*<       if(t2.ge.0.d0.and.t2.le.1.0d0)then >*/
    if (t2 >= 0. && t2 <= 1.) {
/* SOURCE tabfit.for:185 */
/*<       nex=nex+1 >*/
	++(*nex);
/* SOURCE tabfit.for:186 */
/*<       t_at_ex(nex)=t2 >*/
	feq_gen_t_at_ex_d_[*nex] = t2;
/* SOURCE tabfit.for:187 */
/*<       endif >*/
    }
/* SOURCE tabfit.for:190 */
/*<       return >*/
    return 0;
/* SOURCE tabfit.for:191 */
/*<       end >*/
} /* locate_extreme_point__ */

#ifdef __cplusplus
	}
#endif
