/* feq.f -- translated by f2c (version 20240504).
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

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* COMMON ts_mngt_n__ is declared in common.hpp. */

#define feq_gen_ts_mngt_n_d_1 feq_gen_ts_mngt_n_d_

/* COMMON ts_mngt_c__ is declared in common.hpp. */

#define feq_gen_ts_mngt_c_d_1 feq_gen_ts_mngt_c_d_

/* COMMON version_ is declared in common.hpp. */

#define version_1 version_

/* COMMON versionc_ is declared in common.hpp. */

#define versionc_1 versionc_

/* COMMON homec_ is declared in common.hpp. */

#define homec_1 homec_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON mktbindxc_ is declared in common.hpp. */

#define mktbindxc_1 mktbindxc_

/* COMMON mktbindx_ is declared in common.hpp. */

#define mktbindx_1 mktbindx_

/* COMMON grid_datum__ is declared in common.hpp. */

#define feq_gen_grid_datum_d_1 feq_gen_grid_datum_d_

/* COMMON miscon_ is declared in common.hpp. */

#define miscon_1 miscon_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON bnpond_ is declared in common.hpp. */

#define bnpond_1 bnpond_

/* COMMON bnrslt_ is declared in common.hpp. */

#define bnrslt_1 bnrslt_

/* COMMON difcom_ is declared in common.hpp. */

#define difcom_1 difcom_

/* COMMON dtcom_ is declared in common.hpp. */

#define dtcom_1 dtcom_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON enothr_ is declared in common.hpp. */

#define enothr_1 enothr_

/* COMMON enothc_ is declared in common.hpp. */

#define enothc_1 enothc_

/* COMMON enrslt_ is declared in common.hpp. */

#define enrslt_1 enrslt_

/* COMMON infcom_ is declared in common.hpp. */

#define infcom_1 infcom_

/* COMMON infcmc_ is declared in common.hpp. */

#define infcmc_1 infcmc_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON namcom_ is declared in common.hpp. */

#define namcom_1 namcom_

/* COMMON tsfcom_ is declared in common.hpp. */

#define tsfcom_1 tsfcom_

/* COMMON rdcom_ is declared in common.hpp. */

#define rdcom_1 rdcom_

/* COMMON rdcomc_ is declared in common.hpp. */

#define rdcomc_1 rdcomc_

/* COMMON wrcom_ is declared in common.hpp. */

#define wrcom_1 wrcom_

/* COMMON wrcomc_ is declared in common.hpp. */

#define wrcomc_1 wrcomc_

/* COMMON wrcomd_ is declared in common.hpp. */

#define wrcomd_1 wrcomd_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON gravcm_ is declared in common.hpp. */

#define gravcm_1 gravcm_

/* COMMON clcomc_ is declared in common.hpp. */

#define clcomc_1 clcomc_

/* COMMON clcom_ is declared in common.hpp. */

#define clcom_1 clcom_

/* COMMON timcom_ is declared in common.hpp. */

#define timcom_1 timcom_

/* COMMON inbr_ is declared in common.hpp. */

#define inbr_1 inbr_

/* COMMON inen_ is declared in common.hpp. */

#define inen_1 inen_

/* COMMON inenc_ is declared in common.hpp. */

#define inenc_1 inenc_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON genscn_ is declared in common.hpp. */

#define genscn_1 genscn_

/* COMMON tamcom_ is declared in common.hpp. */

#define tamcom_1 tamcom_

/* COMMON code14_ is declared in common.hpp. */

#define code14_1 code14_

/* COMMON upgrdc_ is declared in common.hpp. */

#define upgrdc_1 upgrdc_

/* COMMON timetabc_ is declared in common.hpp. */

#define timetabc_1 timetabc_

/* COMMON timetab_ is declared in common.hpp. */

#define timetab_1 timetab_

/* COMMON whatos_ is declared in common.hpp. */

#define whatos_1 whatos_

/* COMMON spouta_ is declared in common.hpp. */

#define spouta_1 spouta_

/* COMMON spoutc_ is declared in common.hpp. */

#define spoutc_1 spoutc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_100 = 100;
static integer feq_gen_c_d_4 = 4;




/* SOURCE feq.for:4 */
/*<       subroutineupdate_time_step_tab(stddtout,jtime,dt) >*/
/* Subroutine */ int feq_gen_update_time_step_tab_d_(integer *stddtout, doublereal *
	jtime, doublereal *dt)
{
    /* Format strings */
    static char fmt_50[] = "(i4,i3,i3,f10.6,f10.2)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real hr;
    integer mn, dy, yr, mjd;
    doublereal jtemp, dyfrac;
    extern /* Subroutine */ int invmjd_(integer *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_50, 0 };


/*     Write a value of time step to the file */
/* SOURCE feq.for:8 */
/*<       implicitnone >*/
/* SOURCE feq.for:9 */
/*<       integerstddtout >*/
/* SOURCE feq.for:10 */
/*<       real*8jtime,dt >*/
/*     Local */
/* SOURCE feq.for:13 */
/*<       integermjd,yr,mn,dy >*/
/* SOURCE feq.for:15 */
/*<       realhr >*/
/* SOURCE feq.for:17 */
/*<       real*8jtemp,dyfrac >*/
/*     ***************************formats******************************** */
/* SOURCE feq.for:19 */
/*<    50 format(i4,i3,i3,f10.6,f10.2) >*/
/* *********************************************************************** */
/* SOURCE feq.for:21 */
/*<       jtemp=jtime-dt/86400.d0 >*/
/* L50: */
    jtemp = *jtime - *dt / 86400.;
/* SOURCE feq.for:22 */
/*<       mjd=int(jtemp) >*/
    mjd = (integer) jtemp;
/* SOURCE feq.for:23 */
/*<       dyfrac=jtemp-dble(mjd) >*/
    dyfrac = jtemp - (doublereal) mjd;
/* SOURCE feq.for:24 */
/*<       hr=24.d0*dyfrac >*/
    hr = dyfrac * 24.;
/* SOURCE feq.for:25 */
/*<       callinvmjd(mjd,yr,mn,dy) >*/
    invmjd_(&mjd, &yr, &mn, &dy);
/* SOURCE feq.for:28 */
/*<       write(stddtout,50)yr,mn,dy,hr,dt >*/
    feq_gen_io_d__8.ciunit = *stddtout;
    s_wsfe(&feq_gen_io_d__8);
    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&mn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&dy, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*dt), (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE feq.for:29 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:30 */
/*<       end >*/
} /* update_time_step_tab__ */




/* SOURCE feq.for:34 */
/*<       subroutinereset_hi_iq_ns_fac() >*/
/* Subroutine */ int feq_gen_reset_hi_iq_ns_fac_d_()
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;

/*     Reset the high iq Newton solution factor to 1.0 */
/* SOURCE feq.for:38 */
/*<       implicitnone >*/
/* INCLUDE feq.for:40 */
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
/* INCLUDE feq.for:41 */
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
/*     Local */
/* SOURCE feq.for:45 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE feq.for:47 */
/*<       do100i=1,numeq >*/
    feq_gen_i_d_1 = matcom_1.numeq;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:48 */
/*<       hi_iq_ns_fac(i)=1.00 >*/
	matcom_1.feq_gen_hi_iq_ns_fac_d_[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE feq.for:49 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE feq.for:50 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:51 */
/*<       end >*/
} /* reset_hi_iq_ns_fac__ */




/* SOURCE feq.for:56 */
/*<       subroutinetrim_last_extension(fnamein,fnameout) >*/
/* Subroutine */ int feq_gen_trim_last_extension_d_(char *fnamein, char *fnameout, 
	ftnlen fnamein_len, ftnlen fnameout_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, l, n;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     return the filename in fnamein with its final extension deleted */
/*     in fnameout */
/* SOURCE feq.for:62 */
/*<       implicitnone >*/
/* SOURCE feq.for:64 */
/*<       character*(*)fnamein,fnameout >*/
/*     Local */
/* SOURCE feq.for:68 */
/*<       integeri,n,l >*/
/* *********************************************************************** */
/* SOURCE feq.for:56 */
/*<       integer feq_len_trim >*/
/* SOURCE feq.for:56 */
/*<       external feq_len_trim >*/
/* SOURCE feq.for:70 */
/*<       n=feq_len_trim(fnamein) >*/
    n = feq_gen_feq_len_trim_d_(fnamein, fnamein_len);
/*     Set L for case of no period found */
/* SOURCE feq.for:73 */
/*<       l=n >*/
    l = n;
/* SOURCE feq.for:74 */
/*<       doi=n,1,-1 >*/
    for (feq_gen_i_d_ = n; feq_gen_i_d_ >= 1; --feq_gen_i_d_) {
/* SOURCE feq.for:76 */
/*<       if(fnamein(i:i).eq.'.')then >*/
	if (*(unsigned char *)&fnamein[feq_gen_i_d_ - 1] == '.') {
/* SOURCE feq.for:77 */
/*<       if(i.gt.1)then >*/
	    if (feq_gen_i_d_ > 1) {
/* SOURCE feq.for:78 */
/*<       l=i-1 >*/
		l = feq_gen_i_d_ - 1;
/* SOURCE feq.for:79 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:80 */
/*<       l=n >*/
		l = n;
/* SOURCE feq.for:81 */
/*<       endif >*/
	    }
/* SOURCE feq.for:82 */
/*<       goto99000 >*/
	    goto L99000;
/* SOURCE feq.for:83 */
/*<       endif >*/
	}
/* SOURCE feq.for:85 */
/*<       enddo >*/
    }
/* SOURCE feq.for:85 */
/*< 99000 continue >*/
L99000:
/* SOURCE feq.for:86 */
/*<       fnameout=fnamein(1:l) >*/
    s_copy(fnameout, fnamein, fnameout_len, l);
/* SOURCE feq.for:87 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:88 */
/*<       end >*/
} /* trim_last_extension__ */




/* SOURCE feq.for:94 */
/*<       subroutinemake_standard_file_names(fname,fname2) >*/
/* Subroutine */ int feq_gen_make_standard_file_names_d_(char *fname, char *fname2, 
	ftnlen fname_len, ftnlen fname2_len)
{
    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1[2];

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    integer l;
    extern /* Subroutine */ int feq_gen_trim_last_extension_d_(char *, char *, ftnlen, 
	    ftnlen);
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Given the name for the input file to FEQ form the standard names for */
/*     the remaining file name. */
/* SOURCE feq.for:100 */
/*<       implicitnone >*/
/* SOURCE feq.for:102 */
/*<       character*64fname,fname2 >*/
/*     Local */
/* SOURCE feq.for:107 */
/*<       integeri,l,n >*/
/* *********************************************************************** */
/*     The input file name may or may not have an extension.  Also */
/*     this should work with more than one period in the file name. */
/*     The period closest to the end of the string will be taken to */
/*     be the delimiter for the extension.  If no period is found, */
/*     then the whole name is used for the base name of the remaining */
/*     file names unless the period is in the first position and is */
/*     the only period present. */
/* SOURCE feq.for:94 */
/*<       integer feq_len_trim >*/
/* SOURCE feq.for:94 */
/*<       external feq_len_trim >*/
/* SOURCE feq.for:119 */
/*<       calltrim_last_extension(fname,fname2) >*/
    feq_gen_trim_last_extension_d_(fname, fname2, (ftnlen)64, (ftnlen)64);
/* SOURCE feq.for:121 */
/*<       l=feq_len_trim(fname2) >*/
    l = feq_gen_feq_len_trim_d_(fname2, (ftnlen)64);
/* SOURCE feq.for:122 */
/*<       fname2=fname2(1:l)//'.out' >*/
/* Writing concatenation */
    feq_gen_i_d_1[0] = l, feq_gen_a_d_1[0] = fname2;
    feq_gen_i_d_1[1] = 4, feq_gen_a_d_1[1] = const_cast<char*>(".out");
    s_cat(fname2, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_2, (ftnlen)64);
/* SOURCE feq.for:124 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:125 */
/*<       end >*/
} /* make_standard_file_names__ */




/* SOURCE feq.for:129 */
/*<       subroutinebraxy_to_exnodt(nex,exnodt) >*/
/* Subroutine */ int feq_gen_braxy_to_exnodt_d_(integer *nex, integer *feq_storage_exnodt)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;
    static integer null = -2147483647;

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal x, y;
    integer adrs;
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);

/*     Transfer the node locations to exterior nodes on branches. */
/* SOURCE feq.for:134 */
/*<       implicitnone >*/
/* SOURCE feq.for:136 */
/*<       integernex,exnodt(9,nex) >*/
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
/*     Called program units */
/* SOURCE feq.for:154 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE feq.for:155 */
/*<       externalget_dp_from_ft >*/
/*     Local */
/* SOURCE feq.for:159 */
/*<       integeradrs,i,null >*/
/* SOURCE feq.for:160 */
/*<       real*8x,y,dnull >*/
/* *********************************************************************** */
/* SOURCE feq.for:162 */
/*<       datadnull/-33d6/,null/-2147483647/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
/* SOURCE feq.for:165 */
/*<       do100i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:166 */
/*<       if(exnodt(3,i).gt.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] > 0) {
/*         It is on a branch */
/* SOURCE feq.for:168 */
/*<       adrs=exnodt(4,i) >*/
	    adrs = exnodt[feq_gen_i_d_ * 9 + 4];
/* SOURCE feq.for:169 */
/*<       x=get_dp_from_ft(adrs+8) >*/
	    feq_gen_i_d_2 = adrs + 8;
	    x = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE feq.for:170 */
/*<       y=get_dp_from_ft(adrs+10) >*/
	    feq_gen_i_d_2 = adrs + 10;
	    y = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE feq.for:171 */
/*<       if(x<=dnull)then >*/
	    if (x <= dnull) {
/* SOURCE feq.for:172 */
/*<       exnodt(6,i)=null >*/
		exnodt[feq_gen_i_d_ * 9 + 6] = null;
/* SOURCE feq.for:173 */
/*<       exnodt(7,i)=null >*/
		exnodt[feq_gen_i_d_ * 9 + 7] = null;
/* SOURCE feq.for:174 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:175 */
/*<       exnodt(6,i)=nint(100.d0*x) >*/
		feq_gen_d_d_1 = x * 100.;
		exnodt[feq_gen_i_d_ * 9 + 6] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE feq.for:176 */
/*<       exnodt(7,i)=nint(100.d0*y) >*/
		feq_gen_d_d_1 = y * 100.;
		exnodt[feq_gen_i_d_ * 9 + 7] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE feq.for:177 */
/*<       endif >*/
	    }
/* SOURCE feq.for:178 */
/*<       endif >*/
	}
/* SOURCE feq.for:179 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE feq.for:180 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:181 */
/*<       end >*/
} /* braxy_to_exnodt__ */

/*     *********** */
/*     *         * */
/*     * TS_MNGT_INIT */
/*     *         * */
/*     *********** */
/* SOURCE feq.for:189 */
/*<       subroutinets_mngt_init >*/
/* Subroutine */ int feq_gen_ts_mngt_init_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;

/*     Clear counters in the common blocks. */
/* SOURCE feq.for:193 */
/*<       implicitnone >*/
/* INCLUDE feq.for:194 */
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
/* INCLUDE feq.for:195 */
/*     Common block for management of time series in FEQ.  Keeps track */
/*     of time series references as well as the places where the */
/*     time-series values are needed. */
/* SOURCE ts_mngt.cmn:5 */
/*<       integernum_ts,num_dest,next_link >*/
/* SOURCE ts_mngt.cmn:7 */
/*<        >*/
/* SOURCE ts_mngt.cmn:11 */
/*<       character*16ts_id(mxn_ts) >*/
/* SOURCE ts_mngt.cmn:13 */
/*<        >*/
/* SOURCE ts_mngt.cmn:16 */
/*<       common/ts_mngt_c/ts_id >*/
/* SOURCE ts_mngt.cmn:18 */
/*<       save/ts_mngt_n/,/ts_mngt_c/ >*/
/*     Definitions: */
/*     TS_ID-  unique label used for refering to a time series that will */
/*             be referenced in FEQ. */
/*     SOURCE_CAT- category of the source of the time series: from table */
/*                 or from a file. */
/*     SOURCE_ADDRESS- "address" of the source.  This will contain the */
/*                  index into the time-series file table for time-series */
/*                  found in files.  For time series found in tables it */
/*                  will be the table number and later the address */
/*                  of the table. */
/*     DEST_CAT- category of the destination: level-pool reservoir rainfall/ */
/*              evaporation or branch evaporation/rainfall, forced bdy. */
/*     DEST_LINK- pointer that allows there to be more than one destination */
/*                from a time-series.  If DEST_LINK(i) is 0, then the */
/*                destination in row i is the last one in the list. */
/*                If DEST_LINK(i) > 0, then the next destination is */
/*                described in row DEST_LINK(i).  We reserve one value for each of */
/*                the MXN_TS time series. Therefore MXN_DEST > MXN_TS if */
/*                a time series is to have more than one destination */
/*     NEXT_LINK- Next open link in the destination overflow area. */
/*     The file handling routines will keep track of the different file */
/*     systems that may be used for the time series. */
/*     Local */
/* SOURCE feq.for:199 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE feq.for:201 */
/*<       num_ts=0 >*/
    feq_gen_ts_mngt_n_d_1.feq_gen_num_ts_d_ = 0;
/* SOURCE feq.for:202 */
/*<       num_dest=0 >*/
    feq_gen_ts_mngt_n_d_1.feq_gen_num_dest_d_ = 0;
/* SOURCE feq.for:203 */
/*<       next_link=mxn_ts+1 >*/
    feq_gen_ts_mngt_n_d_1.feq_gen_next_link_d_ = 201;
/*     Clear the time-series id table as well as the */
/*     link pointer, and the table contents.  We must be able to decide */
/*     if a destination has already been established. */
/* SOURCE feq.for:208 */
/*<       do100i=1,mxn_ts >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 200; ++feq_gen_i_d_) {
/* SOURCE feq.for:209 */
/*<       ts_id(i)=' ' >*/
	s_copy(feq_gen_ts_mngt_c_d_1.feq_gen_ts_id_d_ + (feq_gen_i_d_ - 1 << 4), const_cast<char*>(" "), (ftnlen)16, (
		ftnlen)1);
/* SOURCE feq.for:210 */
/*<       dest_cat(i)=0 >*/
	feq_gen_ts_mngt_n_d_1.feq_gen_dest_cat_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE feq.for:211 */
/*<       dest_pnt(i)=0 >*/
	feq_gen_ts_mngt_n_d_1.feq_gen_dest_pnt_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE feq.for:212 */
/*<       dest_link(i)=0 >*/
	feq_gen_ts_mngt_n_d_1.feq_gen_dest_link_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE feq.for:213 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE feq.for:215 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:216 */
/*<       end >*/
} /* ts_mngt_init__ */




/* SOURCE feq.for:220 */
/*<       subroutineset_version() >*/
/* Subroutine */ int feq_gen_set_version_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Sets the current version number and date in the version */
/*     common block */
/* SOURCE feq.for:224 */
/*<       implicitnone >*/
/* INCLUDE feq.for:226 */
/*     Common block to allow version and date to be output */
/*     at more than one point in the code. */
/* SOURCE version.cmn:4 */
/*<       characterversion_date*17 >*/
/* SOURCE version.cmn:6 */
/*<       realversion_number >*/
/* SOURCE version.cmn:8 */
/*<       common/version/version_number >*/
/* SOURCE version.cmn:10 */
/*<       common/versionc/version_date >*/
/* *********************************************************************** */
/* SOURCE feq.for:228 */
/*<       version_number=10.61 >*/
    version_1.feq_gen_version_number_d_ = (float)10.61;
/* SOURCE feq.for:229 */
/*<       version_date='15 October 2008' >*/
    s_copy(versionc_1.feq_gen_version_date_d_, const_cast<char*>("15 October 2008"), (ftnlen)17, (ftnlen)
	    15);
/* SOURCE feq.for:230 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:231 */
/*<       end >*/
} /* set_version__ */




/* SOURCE feq.for:236 */
/*<       subroutinereset_standard_output_ext(name) >*/
/* Subroutine */ int feq_gen_reset_standard_output_ext_d_(char *feq_gen_name_d_, ftnlen 
	name_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, iend;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Get the final extension from name and store in the standard */
/*     output extension.  A period is the delimiter used between parts */
/*     of a name and the string that follows the last period in the */
/*     name when scanning left to right is the extension. If the name */
/*     begins with a period, then the name is not treated as an extension. */
/* SOURCE feq.for:244 */
/*<       implicitnone >*/
/* SOURCE feq.for:245 */
/*<       character*(*)name >*/
/* INCLUDE feq.for:247 */
/*     Values of local and global home directory names */
/* 	7 dec 2005:  Add an output extension value */
/* SOURCE home.cmn:3 */
/*<       character*128stdext >*/
/* SOURCE home.cmn:4 */
/*<       character*128home,ghome,ghome_out >*/
/* SOURCE home.cmn:5 */
/*<       common/homec/home,ghome,ghome_out,stdext >*/
/* SOURCE home.cmn:6 */
/*<       save/homec/ >*/
/*     Local */
/* SOURCE feq.for:250 */
/*<       integeri,iend >*/
/* *********************************************************************** */
/* SOURCE feq.for:236 */
/*<       integer feq_len_trim >*/
/* SOURCE feq.for:236 */
/*<       external feq_len_trim >*/
/* SOURCE feq.for:253 */
/*<       iend=feq_len_trim(name) >*/
    iend = feq_gen_feq_len_trim_d_(feq_gen_name_d_, name_len);
/* SOURCE feq.for:254 */
/*<       doi=iend,1,-1 >*/
    for (feq_gen_i_d_ = iend; feq_gen_i_d_ >= 1; --feq_gen_i_d_) {
/* SOURCE feq.for:255 */
/*<       if(name(i:i)=='.')then >*/
	if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] == '.') {
/* SOURCE feq.for:256 */
/*<       goto99000 >*/
	    goto L99000;
/* SOURCE feq.for:257 */
/*<       endif >*/
	}
/* SOURCE feq.for:258 */
/*<       enddo >*/
    }
/* SOURCE feq.for:258 */
/*< 99000 continue >*/
L99000:
/* SOURCE feq.for:259 */
/*<       if(i>1)then >*/
    if (feq_gen_i_d_ > 1) {
/*       There was a period found during the reverse search. */
/* SOURCE feq.for:261 */
/*<       stdext=name(i:iend) >*/
	s_copy(homec_1.stdext, feq_gen_name_d_ + (feq_gen_i_d_ - 1), (ftnlen)128, iend - (feq_gen_i_d_ - 
		1));
/* SOURCE feq.for:262 */
/*<       endif >*/
    }
/* SOURCE feq.for:263 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:264 */
/*<       end >*/
} /* reset_standard_output_ext__ */




/* SOURCE feq.for:268 */
/*<       subroutineftab_loc_chk(stdout) >*/
/* Subroutine */ int feq_gen_ftab_loc_chk_d_(integer *stdout)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;

    /* Format strings */
    static char fmt_50[] = "(/,\002List of Function-table status found in \
FEQ\002,/,8x,\002 Table id\002,\002 Type\002,1x,5x,\002Zone\002,1x,4x,\002Hg\
rid\002,1x,9x,\002Easting\0021x,8x,\002Northing\002,1x,3x,\002Vdatum\002,1x,\
2x,\002Unitsys\002,1x,4x,\002Basis\002,2x,\002File-name\002)";
    static char fmt_52[] = "(1x,a16,i5,1x,a8,a1,1x,a8,a1,1x,f15.3,a1,1x,f15.\
3,a1,1x,a8,a1,1x,a8,a1,1x,a8,a1,2x,a)";
    static char fmt_54[] = "(/,\002*ERR:XXX* Unexpected vertical datum found\
 in: \002,i5,\002 function tables.\002,/,5x,\002  Expected to find: \002,a8\
,\002.\002,\002  Vdatum values marked with a trailing dash are in error.\002)"
	    ;
    static char fmt_56[] = "(/,\002*ERR:XXX* Unexpected unit system found in\
: \002,i5,\002 function tables.\002,/,5x,\002  Expected to find: \002,a8,\
\002.\002,\002  Unitsys values marked with a trailing dash are in error.\002)"
	    ;

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    char feq_gen_east_src_d_[1];
    integer feq_gen_tab_type_d_, feq_gen_basis_difference_d_;
    char feq_gen_zone_src_d_[1];
    doublereal northing;
    integer feq_gen_i_d_;
    char tunitsys[8];
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    char feq_gen_hgrid_src_d_[1], feq_gen_basis_src_d_[1], feq_gen_north_src_d_[1];
    integer it;
    char feq_gen_vdatum_src_d_[1];
    integer pnt;
    extern /* Subroutine */ int feq_gen_feq_adjustr_d_(char *, char *, ftnlen, ftnlen);
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char feq_gen_feql_adjust1_d_[16], feq_gen_feql_adjust2_d_[8], feq_gen_feql_adjust3_d_[8], 
	    feq_gen_unitsys_src_d_[1];
    integer tabn;
    char feq_gen_feql_adjust4_d_[8], feq_gen_feql_adjust5_d_[8], feq_gen_feql_adjust6_d_[8];
    integer adrs;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_get_zone_etc_d_(integer *, integer *, char *, 
	    char *, char *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);
    integer feq_gen_vdatum_error_d_;
    char tabid[16], tzone[8];
    extern /* Subroutine */ int binser_(char *, integer *, char *, integer *, 
	    ftnlen, ftnlen);
    char thgrid[8];
    integer feq_gen_unitsys_error_d_;
    char tbasis[8];
    extern /* Subroutine */ int feq_gen_get_east_north_d_(integer *, integer *, 
	    doublereal *, doublereal *);
    doublereal easting;
    char tvdatum[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_56, 0 };


/*     Scan the function table and check for those that have */
/*     the geographic location (easting, northing) known from */
/*     other sources in FEQ but have no information in their */
/*     header block from input. */
/* SOURCE feq.for:276 */
/*<       implicitnone >*/
/* SOURCE feq.for:278 */
/*<       integerstdout >*/
/* INCLUDE feq.for:280 */
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
/* INCLUDE feq.for:281 */
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
/* INCLUDE feq.for:282 */
/* SOURCE maketabindex.cmn:2 */
/*<       character*4make_tab_index >*/
/* SOURCE maketabindex.cmn:4 */
/*<       integerftab_type(mftnum),data_pnt(mftnum),index_knt,stdindex >*/
/* SOURCE maketabindex.cmn:7 */
/*<       characterftabid(mftnum)*16,ftab_fn(mftnum)*256 >*/
/* SOURCE maketabindex.cmn:9 */
/*<       common/mktbindxc/ftab_fn,ftabid,make_tab_index >*/
/* SOURCE maketabindex.cmn:10 */
/*<       common/mktbindx/ftab_type,data_pnt,index_knt,stdindex >*/
/* INCLUDE feq.for:283 */
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
/* SOURCE feq.for:285 */
/*<       character*16get_tabid >*/
/* SOURCE feq.for:286 */
/*<       externalget_east_north,get_tabid,binser >*/
/*     Local */
/* SOURCE feq.for:289 */
/*<        >*/
/* SOURCE feq.for:291 */
/*<       real*8dnull,easting,northing >*/
/* SOURCE feq.for:292 */
/*<       character*8tzone,thgrid,tvdatum,tunitsys,tbasis >*/
/* SOURCE feq.for:293 */
/*<       character*16tabid >*/
/* SOURCE feq.for:294 */
/*<        >*/
/*     *****************Formats****************************************** */
/* SOURCE feq.for:268 */
/*<       character*16 feql_adjust1 >*/
/* SOURCE feq.for:268 */
/*<       character*8 feql_adjust2 >*/
/* SOURCE feq.for:268 */
/*<       character*8 feql_adjust3 >*/
/* SOURCE feq.for:268 */
/*<       character*8 feql_adjust4 >*/
/* SOURCE feq.for:268 */
/*<       character*8 feql_adjust5 >*/
/* SOURCE feq.for:268 */
/*<       character*8 feql_adjust6 >*/
/* SOURCE feq.for:268 */
/*<       integer feq_len_trim >*/
/* SOURCE feq.for:268 */
/*<       external feq_len_trim >*/
/* SOURCE feq.for:298 */
/*<       datadnull/-33d6/ >*/
/* SOURCE feq.for:301 */
/*<    50  >*/
/* L50: */
/* SOURCE feq.for:305 */
/*<    52  >*/
/* L52: */
/* SOURCE feq.for:307 */
/*<    54  >*/
/* L54: */
/* SOURCE feq.for:310 */
/*<    56  >*/
/* L56: */
/* *********************************************************************** */
/* SOURCE feq.for:314 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__27.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__27);
    e_wsfe();
/* SOURCE feq.for:315 */
/*<       vdatum_error=0 >*/
    feq_gen_vdatum_error_d_ = 0;
/* SOURCE feq.for:316 */
/*<       unitsys_error=0 >*/
    feq_gen_unitsys_error_d_ = 0;
/* SOURCE feq.for:317 */
/*<       basis_difference=0 >*/
    feq_gen_basis_difference_d_ = 0;
/* SOURCE feq.for:318 */
/*<       doi=1,knt_of_ftabs >*/
    feq_gen_i_d_1 = ftablea_1.feq_gen_knt_of_ftabs_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:319 */
/*<       zone_src=' ' >*/
	*(unsigned char *)feq_gen_zone_src_d_ = ' ';
/* SOURCE feq.for:320 */
/*<       hgrid_src=' ' >*/
	*(unsigned char *)feq_gen_hgrid_src_d_ = ' ';
/* SOURCE feq.for:321 */
/*<       east_src=' ' >*/
	*(unsigned char *)feq_gen_east_src_d_ = ' ';
/* SOURCE feq.for:322 */
/*<       north_src=' ' >*/
	*(unsigned char *)feq_gen_north_src_d_ = ' ';
/* SOURCE feq.for:323 */
/*<       vdatum_src=' ' >*/
	*(unsigned char *)feq_gen_vdatum_src_d_ = ' ';
/* SOURCE feq.for:324 */
/*<       unitsys_src=' ' >*/
	*(unsigned char *)feq_gen_unitsys_src_d_ = ' ';
/*       Get the table adrs, that is, the index into ftab/itab */
/* SOURCE feq.for:326 */
/*<       adrs=ftpnt(i) >*/
	adrs = ftablea_1.ftpnt[feq_gen_i_d_ - 1];
/*       Get the internal table number. */
/* SOURCE feq.for:328 */
/*<       tabn=itab(adrs+1) >*/
	tabn = itab[adrs + 1];
/* SOURCE feq.for:329 */
/*<       tab_type=itab(adrs+2) >*/
	feq_gen_tab_type_d_ = itab[adrs + 2];
/* SOURCE feq.for:330 */
/*<       tabid=get_tabid(tabn) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tabn);
	s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE feq.for:331 */
/*<       callbinser(tabid,index_knt,ftabid,pnt) >*/
	binser_(tabid, &mktbindx_1.feq_gen_index_knt_d_, mktbindxc_1.ftabid, &pnt, (
		ftnlen)16, (ftnlen)16);
/*       Get the information from the function-table.  Then */
/*       do an array of checks to determine what to output. */
/* SOURCE feq.for:336 */
/*<       callget_east_north(stdout,adrs,easting,northing) >*/
	feq_gen_get_east_north_d_(stdout, &adrs, &easting, &northing);
/*       We need to distinguish between the zone... given in the */
/*       run-control block, and those that are stored with the */
/*       function table.  Thus the prefix "t" denotes the values */
/*       from the function table. */
/* SOURCE feq.for:343 */
/*<       callget_zone_etc(stdout,adrs,tzone,thgrid,tvdatum,tunitsys,tbasis) >*/
	feq_gen_get_zone_etc_d_(stdout, &adrs, tzone, thgrid, tvdatum, tunitsys, 
		tbasis, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8)
		;
/* SOURCE feq.for:346 */
/*<       if(g_zone/='NONE')then >*/
	if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_zone_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0) 
		{
/*         User has given a value for zone in the run-control block. */
/*         These means that hgrid is also given, and that a value */
/*         of easting and northing is meaningful for the function */
/*         table.  The values of easting and northing that appear */
/*         in the table may have been given in the function-table */
/*         input, ft_loc_status = 'I', or they may have been */
/*         supplied by FEQ, ft_loc_status = 'M' AND easting > dnull, */
/*         or they may be unknown, ft_loc_status = 'm' AND */
/*         easting <= dnull. */
/* SOURCE feq.for:357 */
/*<       if(tzone=='MISSING')then >*/
	    if (s_cmp(tzone, const_cast<char*>("MISSING"), (ftnlen)8, (ftnlen)7) == 0) {
/*           Zone, hgrid, where missing from the table.  The easting and */
/*           northing may have been present if the table were a cross-section */
/*           table. */
/* SOURCE feq.for:361 */
/*<       zone_src=' ' >*/
		*(unsigned char *)feq_gen_zone_src_d_ = ' ';
/* SOURCE feq.for:362 */
/*<       hgrid_src=' ' >*/
		*(unsigned char *)feq_gen_hgrid_src_d_ = ' ';
/* SOURCE feq.for:363 */
/*<       endif >*/
	    }
/*         Check the easting and northing status. */
/* SOURCE feq.for:366 */
/*<       if(tzone/='NONE'.and.tzone/='NA')then >*/
	    if (s_cmp(tzone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0 && s_cmp(
		    tzone, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) != 0) {
/*           Easting and northing make sense */
/* SOURCE feq.for:368 */
/*<       if(ft_loc_status(tabn)=='M')then >*/
		if (*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[tabn - 1] == 
			'M') {
/*             Easting and northing were not given for the function-table */
/* SOURCE feq.for:370 */
/*<       if(easting>dnull)then >*/
		    if (easting > dnull) {
/*               FEQ found a location for the table.  Signal update of input sources. */
/* SOURCE feq.for:372 */
/*<       east_src='u' >*/
			*(unsigned char *)feq_gen_east_src_d_ = 'u';
/* SOURCE feq.for:373 */
/*<       north_src='u' >*/
			*(unsigned char *)feq_gen_north_src_d_ = 'u';
/* SOURCE feq.for:374 */
/*<       else >*/
		    } else {
/*               Location is still unknown, that state is in the table either */
/*               explicitly given or implicit in not being present. */
/*               Signal that the value in the function-table input, if, any, should */
/*               not be changed. */
/* SOURCE feq.for:379 */
/*<       east_src=' ' >*/
			*(unsigned char *)feq_gen_east_src_d_ = ' ';
/* SOURCE feq.for:380 */
/*<       north_src=' ' >*/
			*(unsigned char *)feq_gen_north_src_d_ = ' ';
/* SOURCE feq.for:381 */
/*<       endif >*/
		    }
/* SOURCE feq.for:382 */
/*<       elseif(ft_loc_status(tabn)=='I')then >*/
		} else if (*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[tabn 
			- 1] == 'I') {
/*             Location known from input.  Mark as such */
/* SOURCE feq.for:384 */
/*<       east_src=' ' >*/
		    *(unsigned char *)feq_gen_east_src_d_ = ' ';
/* SOURCE feq.for:385 */
/*<       north_src=' ' >*/
		    *(unsigned char *)feq_gen_north_src_d_ = ' ';
/* SOURCE feq.for:386 */
/*<       else >*/
		} else {
/*             Should not get here. */
/* SOURCE feq.for:388 */
/*<        >*/
		    feq_gen_io_d__50.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__50);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("*BUG*1: invalid value of "), (ftnlen)
			    25);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("ft_loc_status(tabn) in subroutine \
ftab_loc_chk="), (ftnlen)47);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, ftablec_1.feq_gen_ft_loc_status_d_ + (tabn - 
			    1), (ftnlen)1);
		    e_wsle();
/* SOURCE feq.for:391 */
/*<       write(stdout,*)' tabid=',tabid >*/
		    feq_gen_io_d__51.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__51);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" tabid="), (ftnlen)7);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, tabid, (ftnlen)16);
		    e_wsle();
/* SOURCE feq.for:392 */
/*<       stop'Abnormal stop.  Bug found' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Bug found"), (ftnlen)25);
/* SOURCE feq.for:393 */
/*<       endif >*/
		}
/* SOURCE feq.for:394 */
/*<       else >*/
	    } else {
/*           Location has no meaning for this function table. */
/* SOURCE feq.for:396 */
/*<       if(ft_loc_status(tabn)/='N')then >*/
		if (*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[tabn - 1] != 
			'N') {
/* SOURCE feq.for:397 */
/*<        >*/
		    feq_gen_io_d__52.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__52);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("*BUG*2: invalid value of "), (ftnlen)
			    25);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("ft_loc_status(tabn) in subroutine \
ftab_loc_chk="), (ftnlen)47);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, ftablec_1.feq_gen_ft_loc_status_d_ + (tabn - 
			    1), (ftnlen)1);
		    e_wsle();
/* SOURCE feq.for:400 */
/*<       write(stdout,*)' tabid=',tabid >*/
		    feq_gen_io_d__53.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__53);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" tabid="), (ftnlen)7);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, tabid, (ftnlen)16);
		    e_wsle();
/* SOURCE feq.for:401 */
/*<       stop'Abnormal stop.  Bug found' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Bug found"), (ftnlen)25);
/* SOURCE feq.for:402 */
/*<       endif >*/
		}
/*           Mark that source is the table itself.  No update of input sources. */
/* SOURCE feq.for:404 */
/*<       east_src=' ' >*/
		*(unsigned char *)feq_gen_east_src_d_ = ' ';
/* SOURCE feq.for:405 */
/*<       north_src=' ' >*/
		*(unsigned char *)feq_gen_north_src_d_ = ' ';
/* SOURCE feq.for:407 */
/*<       endif >*/
	    }
/* SOURCE feq.for:408 */
/*<       else >*/
	} else {
/*         What ever is in the table is OK. */
/* SOURCE feq.for:410 */
/*<       zone_src=' ' >*/
	    *(unsigned char *)feq_gen_zone_src_d_ = ' ';
/* SOURCE feq.for:411 */
/*<       hgrid_src=' ' >*/
	    *(unsigned char *)feq_gen_hgrid_src_d_ = ' ';
/* SOURCE feq.for:412 */
/*<       east_src=' ' >*/
	    *(unsigned char *)feq_gen_east_src_d_ = ' ';
/* SOURCE feq.for:413 */
/*<       north_src=' ' >*/
	    *(unsigned char *)feq_gen_north_src_d_ = ' ';
/* SOURCE feq.for:414 */
/*<       endif >*/
	}
/* SOURCE feq.for:416 */
/*<       if(g_vdatum/='NONE')then >*/
	if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 
		0) {
/* SOURCE feq.for:417 */
/*<       if(tvdatum=='MISSING'.or.tvdatum=='NA')then >*/
	    if (s_cmp(tvdatum, const_cast<char*>("MISSING"), (ftnlen)8, (ftnlen)7) == 0 || s_cmp(
		    tvdatum, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) == 0) {
/* SOURCE feq.for:418 */
/*<       vdatum_src=' ' >*/
		*(unsigned char *)feq_gen_vdatum_src_d_ = ' ';
/* SOURCE feq.for:419 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:420 */
/*<       if(g_vdatum/=tvdatum)then >*/
		if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, tvdatum, (ftnlen)8, (
			ftnlen)8) != 0) {
/* SOURCE feq.for:421 */
/*<       vdatum_error=vdatum_error+1 >*/
		    ++feq_gen_vdatum_error_d_;
/* SOURCE feq.for:422 */
/*<       vdatum_src='-' >*/
		    *(unsigned char *)feq_gen_vdatum_src_d_ = '-';
/* SOURCE feq.for:423 */
/*<       else >*/
		} else {
/* SOURCE feq.for:424 */
/*<       vdatum_src=' ' >*/
		    *(unsigned char *)feq_gen_vdatum_src_d_ = ' ';
/* SOURCE feq.for:425 */
/*<       endif >*/
		}
/* SOURCE feq.for:426 */
/*<       endif >*/
	    }
/* SOURCE feq.for:427 */
/*<       else >*/
	} else {
/*         What ever is in the table is OK. */
/* SOURCE feq.for:429 */
/*<       vdatum_src=' ' >*/
	    *(unsigned char *)feq_gen_vdatum_src_d_ = ' ';
/* SOURCE feq.for:430 */
/*<       endif >*/
	}
/* SOURCE feq.for:432 */
/*<       if(g_unitsys/='NONE')then >*/
	if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 
		0) {
/* SOURCE feq.for:433 */
/*<       if(tunitsys=='MISSING'.or.tunitsys=='NA')then >*/
	    if (s_cmp(tunitsys, const_cast<char*>("MISSING"), (ftnlen)8, (ftnlen)7) == 0 || 
		    s_cmp(tunitsys, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) == 0) {
/* SOURCE feq.for:434 */
/*<       unitsys_src=' ' >*/
		*(unsigned char *)feq_gen_unitsys_src_d_ = ' ';
/* SOURCE feq.for:435 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:436 */
/*<       if(g_unitsys/=tunitsys)then >*/
		if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, tunitsys, (ftnlen)8, (
			ftnlen)8) != 0) {
/* SOURCE feq.for:437 */
/*<       unitsys_error=unitsys_error+1 >*/
		    ++feq_gen_unitsys_error_d_;
/* SOURCE feq.for:438 */
/*<       unitsys_src='-' >*/
		    *(unsigned char *)feq_gen_unitsys_src_d_ = '-';
/* SOURCE feq.for:439 */
/*<       else >*/
		} else {
/* SOURCE feq.for:440 */
/*<       unitsys_src=' ' >*/
		    *(unsigned char *)feq_gen_unitsys_src_d_ = ' ';
/* SOURCE feq.for:441 */
/*<       endif >*/
		}
/* SOURCE feq.for:442 */
/*<       endif >*/
	    }
/* SOURCE feq.for:443 */
/*<       else >*/
	} else {
/*         What ever is in the table is OK. */
/* SOURCE feq.for:445 */
/*<       unitsys_src=' ' >*/
	    *(unsigned char *)feq_gen_unitsys_src_d_ = ' ';
/* SOURCE feq.for:446 */
/*<       endif >*/
	}
/* SOURCE feq.for:448 */
/*<       if(g_basis/='NONE')then >*/
	if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_basis_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0)
		 {
/* SOURCE feq.for:449 */
/*<       if(tbasis=='MISSING'.or.tbasis=='NA')then >*/
	    if (s_cmp(tbasis, const_cast<char*>("MISSING"), (ftnlen)8, (ftnlen)7) == 0 || s_cmp(
		    tbasis, const_cast<char*>("NA"), (ftnlen)8, (ftnlen)2) == 0) {
/* SOURCE feq.for:450 */
/*<       basis_src=' ' >*/
		*(unsigned char *)feq_gen_basis_src_d_ = ' ';
/* SOURCE feq.for:451 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:452 */
/*<       if(g_basis/=tbasis)then >*/
		if (s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_basis_d_, tbasis, (ftnlen)8, (ftnlen)
			8) != 0) {
/* SOURCE feq.for:453 */
/*<       basis_difference=basis_difference+1 >*/
		    ++feq_gen_basis_difference_d_;
/* SOURCE feq.for:454 */
/*<       basis_src='-' >*/
		    *(unsigned char *)feq_gen_basis_src_d_ = '-';
/* SOURCE feq.for:455 */
/*<       else >*/
		} else {
/* SOURCE feq.for:456 */
/*<       basis_src=' ' >*/
		    *(unsigned char *)feq_gen_basis_src_d_ = ' ';
/* SOURCE feq.for:457 */
/*<       endif >*/
		}
/* SOURCE feq.for:458 */
/*<       endif >*/
	    }
/* SOURCE feq.for:459 */
/*<       else >*/
	} else {
/*         What ever is in the table is OK. */
/* SOURCE feq.for:461 */
/*<       basis_src=' ' >*/
	    *(unsigned char *)feq_gen_basis_src_d_ = ' ';
/* SOURCE feq.for:462 */
/*<       endif >*/
	}
/* SOURCE feq.for:464 */
/*<       it=feq_len_trim(ftab_fn(data_pnt(pnt))) >*/
	it = feq_gen_feq_len_trim_d_(mktbindxc_1.feq_gen_ftab_fn_d_ + (mktbindx_1.feq_gen_data_pnt_d_[
		pnt - 1] - 1 << 8), (ftnlen)256);
/* SOURCE feq.for:465 */
/*<       callfeq_adjustr(tabid,feql_adjust1) >*/
	feq_gen_feq_adjustr_d_(tabid, feq_gen_feql_adjust1_d_, (ftnlen)16, (ftnlen)16);
/* SOURCE feq.for:465 */
/*<       callfeq_adjustr(tzone,feql_adjust2) >*/
	feq_gen_feq_adjustr_d_(tzone, feq_gen_feql_adjust2_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE feq.for:465 */
/*<       callfeq_adjustr(thgrid,feql_adjust3) >*/
	feq_gen_feq_adjustr_d_(thgrid, feq_gen_feql_adjust3_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE feq.for:465 */
/*<       callfeq_adjustr(tvdatum,feql_adjust4) >*/
	feq_gen_feq_adjustr_d_(tvdatum, feq_gen_feql_adjust4_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE feq.for:465 */
/*<       callfeq_adjustr(tunitsys,feql_adjust5) >*/
	feq_gen_feq_adjustr_d_(tunitsys, feq_gen_feql_adjust5_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE feq.for:465 */
/*<       callfeq_adjustr(tbasis,feql_adjust6) >*/
	feq_gen_feq_adjustr_d_(tbasis, feq_gen_feql_adjust6_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE feq.for:465 */
/*<        >*/
	feq_gen_io_d__62.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, feq_gen_feql_adjust1_d_, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tab_type_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, feq_gen_feql_adjust2_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_zone_src_d_, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, feq_gen_feql_adjust3_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_hgrid_src_d_, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, feq_gen_east_src_d_, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, feq_gen_north_src_d_, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, feq_gen_feql_adjust4_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_vdatum_src_d_, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, feq_gen_feql_adjust5_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_unitsys_src_d_, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, feq_gen_feql_adjust6_d_, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, feq_gen_basis_src_d_, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, mktbindxc_1.feq_gen_ftab_fn_d_ + (mktbindx_1.feq_gen_data_pnt_d_[pnt - 1] 
		- 1 << 8), it);
	e_wsfe();
/* SOURCE feq.for:472 */
/*<       enddo >*/
    }
/*     Output summary of the state of the function table system. */
/* SOURCE feq.for:476 */
/*<       if(vdatum_error>0)then >*/
    if (feq_gen_vdatum_error_d_ > 0) {
/* SOURCE feq.for:477 */
/*<       write(stdout,54)vdatum_error,g_vdatum >*/
	feq_gen_io_d__63.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__63);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_vdatum_error_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, (ftnlen)8);
	e_wsfe();
/* SOURCE feq.for:478 */
/*<       stop'Abnormal stop. Inconsistent vertical datum values found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Inconsistent vertical datum values found."), (
		ftnlen)56);
/* SOURCE feq.for:479 */
/*<       endif >*/
    }
/* SOURCE feq.for:480 */
/*<       if(unitsys_error>0)then >*/
    if (feq_gen_unitsys_error_d_ > 0) {
/* SOURCE feq.for:481 */
/*<       write(stdout,56)unitsys_error,g_unitsys >*/
	feq_gen_io_d__64.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__64);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_unitsys_error_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, (ftnlen)8);
	e_wsfe();
/* SOURCE feq.for:482 */
/*<       stop'Abnormal stop. Inconsistent unit system values found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Inconsistent unit system values found."), (
		ftnlen)53);
/* SOURCE feq.for:483 */
/*<       endif >*/
    }
/* SOURCE feq.for:486 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:487 */
/*<       end >*/
} /* ftab_loc_chk__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE feq.for:491 */
/*<       subroutineoutput_balance_legend(stdout) >*/
/* Subroutine */ int feq_gen_output_balance_legend_d_(integer *stdout)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Legend for balance checking output:\002,\
/,\002 S1 = initial volume in level-pool reservoirs and branches\002,/,\002 \
S2 = current volume in level-pool reservoirs and branches\002,/,\002 BNI = i\
nflow for boundary nodes\002,/,\002 BNQ = outflow from boundary nodes\002,/\
,\002 TAQ = flow from tributary areas into level-pool reservoirs\002,\002 an\
d branches\002,/,\002      excluding boundary nodes\002,/,\002 WSI = rainfal\
l on water surfaces\002,/,\002 WSQ = evaporation from water surfaces\002,/\
,\002 TAQBN = flow from tributary areas into boundary nodes\002,/,\002 TAI =\
 flow to tributary areas\002,/,\002 D1 = initial volume in detention-delay r\
eservoirs\002,/,\002 D2 = current volume in detention-delay reservoirs\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, 0, 0 };


/*     Output a legend for the balance summary output */
/* SOURCE feq.for:495 */
/*<       implicitnone >*/
/* SOURCE feq.for:496 */
/*<       integerstdout >*/
/*     *****************************FORMATS****************************** */
/* SOURCE feq.for:499 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE feq.for:513 */
/*<       write(stdout,50) >*/
/* L50: */
    feq_gen_io_d__65.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__65);
    e_wsfe();
/* SOURCE feq.for:514 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__66.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__66);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE feq.for:515 */
/*<       return >*/
    return 0;
/* SOURCE feq.for:516 */
/*<       end >*/
} /* output_balance_legend__ */

/*  *********************************************************************** */
/*  *  Warning:  This program is large and complex and  extensive         * */
/*  *  knowledge of its design, purpose, and limitations is required      * */
/*  *  in order to apply it properly.  Application of this program by an  * */
/*  *  unqualified user for any other purpose than an educational one is  * */
/*  *  not only unwise but is also unethical.  The user of this           * */
/*  *  program is totally responsible for its use and application and for * */
/*  *  any actions or events which follow therefrom.  Any user of this    * */
/*  *  program  holds the developer of the program harmless from          * */
/*  *  damages of any kind.                                               * */
/*  *                                                                     * */
/*  *  The developer has used reasonable care in the construction and     * */
/*  *  testing of the program.  However, in a program of this size and    * */
/*  *  complexity, it is impossible to verify more than a minute number of* */
/*  *  possible options or applications.  The developer is continuing to  * */
/*  *  modify and use the program and is interested in information on     * */
/*  *  operational problems encountered in its application.  However, the * */
/*  *  developer gives no assurance that the problem can or will be       * */
/*  *  rectified.                                                         * */
/*  *                                                                     * */
/*  *  This program is not to be sold in any form modified or otherwise.  * */
/*  *********************************************************************** */
/* SOURCE feq.for:541 */
/*<       programfeq >*/
/* Main program */ int feq_gen_MAIN_d_()
{
    /* Initialized data */

    static char yes[4+1] = "YES ";
    static char no[4+1] = "NO  ";

    /* Format strings */
    static char fmt_2010[] = "(/)";
    static char fmt_2020[] = "(/,\002 SIMULATION ending at \002,i5,\002/\002\
,i2,\002/\002,i2,\002:\002,f10.7,\002.  Time step=\002,f9.2,\002 sec\002)";
    static char fmt_2021[] = "(\002 At \002,i4,\002/\002,i2,\002/\002,i2,\
\002:\002,f6.3,\002 DT=\002,f8.2,\002 sec\002)";
    static char fmt_2030[] = "(/,\002 *WRN:24* Non-convergence. Time step wi\
ll be\002,\002 reduced.\002)";
    static char fmt_2150[] = "(\002 Balance 1: S1=\002,1pe9.3,\002 S2=\002,1\
pe9.3,\002 BNI=\002,1pe9.3,\002 BNQ=\002,1pe9.3,\002 TAQ=\002,1pe9.3,\002 WS\
I=\002,1pe9.3,\002 WSQ=\002,1pe9.3)";
    static char fmt_2152[] = "(\002 Bal diff=BAL=S2-S1-BNI-TAQ+BNQ-WSI+WSQ\
=\002,1pe10.3,\002    Rel bal=BAL/(S2+BNQ)=\002,1pe10.3)";
    static char fmt_2153[] = "(\002 Balance 2: D1=\002,1pe9.3,\002 D2=\002,1\
pe9.3,\002 TAI=\002,1pe9.3,\002 TAQBN=\002,1pe9.3)";
    static char fmt_2154[] = "(\002 Bal diff=BAL=D2-D1-TAI+TAQ+TAQBN=\002,1p\
e10.3,\002 Rel Bal=BAL/(D2+TAQ+TAQBN)=\002,1pe10.0)";
    static char fmt_2180[] = "(\002 CSUR=\002,1pe8.1,\002 AT ND=\002,i4\
,\002:\002,i6,\002 RLTQ=\002,1pe8.1,\002 AT ND=\002,i4,\002:\002,i6,\002 DT/\
ITER=\002,0pf8.1,\002 Total iterations=\002,i10)";
    static char fmt_3000[] = "(/,\002 PNC SROLD=\002,1pe9.2,\002 SRNEW=\002,\
1pe9.2,\002 LAMBDA WAS \002,0pf9.6)";
    static char fmt_3022[] = "(/,\002 Initialization time=\002,f10.2,\002 se\
cs or \002,f10.4,\002 mins\002)";
    static char fmt_3023[] = "(\002 Setup time=\002,f10.2,\002 secs or \002,\
f10.4,\002 mins\002)";
    static char fmt_3210[] = "(/,\002 SRLIM=\002,1pe12.5)";
    static char fmt_3220[] = "(\002*ERR:165* Value of MORG wrong in ARSIZE. \
Must be 0 or 1.\002)";
    static char fmt_3230[] = "(/,\002 Processing stopped.  Errors encountere\
d.\002)";
    static char fmt_3240[] = "(/,\002 Master-input file name: \002,a,/,\002 \
Master-output file name: \002,a)";
    static char fmt_95[] = "(/,\002 Invalid number of command-line arguments\
: FEQ\002,/,\002 expects exactly one argument or exactly two arguments.\002,\
/,\002 If one argument is given, FEQ strips the last extension,\002,/,\002 i\
f there is one, and appends .out to create the second\002,/,\002 file name. \
 Otherwise give two file names: (1) master-input\002,/,\002 file, and (2) ma\
ster-output file.\002)";
    static char fmt_96[] = "(/,\002 The operating system cannot open the mas\
ter-output\002,/,\002 file: \002,a,\002.\002,\002  Check for invalid charact\
ers in the\002,/,\002 name.  If part or all of the path is given with the na\
me,\002,/,\002 make sure that all directories exist as spelled.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1;
    cilist feq_gen_ci_d_1;
    olist feq_gen_o_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_inqu(inlist *), f_open(olist *), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(), s_cmp(char *, 
	    char *, ftnlen, ftnlen), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer nmxre, nrwta, ntint, numlim, resnum, sumitr, feq_gen_end_eq_d_, 
	    feq_gen_stdext_option_d_, feq_gen_hi_iq_ns_numgt_d_, bwrec, bmxrev[16], kntvec[16], 
	    lmxrv[16], nmxrev[16], ivarv[16];
    real abstol, hslot, lambda, mxres, mxrev[16], mxssrv[16], nslot, rtafac[
	    4000], srlim, srnew, srold;
    integer feq_gen_dot_flag_d_;
    real vunit, wslot, feq_gen_dz_for_output_d_;
    doublereal djload, dtload, taqbn;
    char fname2[64], nodeid[4], feq_gen_cd14_tab_datum_d_[4], feq_gen_cd5t6_tab_datum_d_[4], 
	    feq_gen_hi_iq_ns_d_[4], feq_gen_frcst_wth_dtsf_d_[4];
    logical there;
    integer feq_gen_start_eq_d_;
    doublereal dtdyload;
    extern integer lpyear_(integer *), feq_gen_get_unit_d_(integer *), feq_gen_what_os_d_();
    extern /* Subroutine */ int bdyflw_(integer *, doublereal *, integer *, 
	    integer *, real *, real *, real *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), bwget_(integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, real *),
	     chkgeo_(integer *, integer *, integer *), cmpcor_(integer *, 
	    integer *, integer *, integer *, real *, real *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), crset2_(integer *, integer *, integer *, integer *), 
	    csmat_(doublereal *, doublereal *, real *, integer *, integer *, 
	    integer *, integer *, real *, integer *, real *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, real *, integer 
	    *, integer *, real *, real *, integer *, real *, real *, integer *
	    , integer *, integer *, integer *), dumpit_(real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     estbn_(doublereal *, integer *, real *), esten_(doublereal *, 
	    integer *, real *, integer *), finchk_(integer *, integer *, 
	    integer *, real *, real *, integer *, char *, char *, integer *, 
	    ftnlen, ftnlen), fmxmn_(integer *, integer *, integer *, integer *
	    , integer *, doublereal *), getarg_(integer *, char *, ftnlen), 
	    makcor_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *), mantim_(integer *, integer *, char *, 
	    real *, real *, integer *, integer *, integer *, integer *, char *
	    , integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, real *, integer *, integer *, integer *, real *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, char *, integer *, 
	    doublereal *, doublereal *, integer *, real *, integer *, integer 
	    *, integer *, doublereal *, doublereal *, integer *, real *, 
	    ftnlen, ftnlen, ftnlen), opinit_(integer *, integer *), outsp_(
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *, integer *, real *, char *, char *, integer *
	    , ftnlen, ftnlen), prtlog_(integer *, integer *, real *, integer *
	    , integer *, real *, integer *, real *, integer *, integer *), 
	    resout_(real *, real *, integer *, integer *, char *, integer *, 
	    doublereal *, real *, integer *, integer *, real *, real *, 
	    ftnlen), rplset_(doublereal *, real *, integer *, integer *), 
	    rstnzd_(integer *, integer *), rststa_(integer *, integer *, 
	    integer *), setsta_(integer *, integer *, real *, integer *, 
	    integer *, integer *);
    integer feq_gen_i_d_, j;
    extern /* Subroutine */ int stint_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, integer *, integer *, integer *, doublereal *, real *, 
	    integer *, integer *, integer *, integer *, char *, char *, 
	    integer *, doublereal *, integer *, integer *, doublereal *, 
	    integer *, integer *, real *, real *, integer *, integer *, real *
	    , real *, ftnlen, ftnlen), wrinit_(doublereal *), wrout_(
	    doublereal *, integer *, real *, doublereal *, real *);
    integer n;
    extern /* Subroutine */ int feq_gen_reset_kount_of_internal_tabids_d_(), xoffin_(),
	     feq_gen_clear_ghome_out_d_(), feq_gen_selector_symbol_init_d_(), timerl_(integer *)
	    , setcr_(), feq_gen_os_file_style_d_(char *, ftnlen), 
	    feq_gen_make_standard_file_names_d_(char *, char *, ftnlen, ftnlen), 
	    feq_gen_side_weir_chk_d_(integer *, real *, integer *, integer *, integer *
	    , integer *), feq_gen_set_initial_oper_blk_d_(integer *, integer *, 
	    doublereal *, integer *, integer *), feq_gen_hi_iq_ns_fail_d_(integer *, 
	    integer *, real *, integer *, integer *, real *, real *, char *, 
	    integer *, integer *, real *, integer *, ftnlen), 
	    feq_gen_update_time_step_tab_d_(integer *, doublereal *, doublereal *), 
	    feq_gen_hi_iq_ns_success_d_(integer *, real *, char *, doublereal *, real *
	    , real *, ftnlen), feq_gen_initialize_units_d_();
    integer feq_gen_bnode_max_d_;
    doublereal d1, d2;
    extern /* Subroutine */ int feq_gen_clear_ext_d_();
    integer feq_gen_dt_adjust_d_;
    doublereal s1;
    real feq_gen_dtmin_out_d_;
    doublereal s2;
    extern /* Subroutine */ int feq_gen_initialize_genscn_d_(), feq_gen_macro_symbol_init_d_();
    doublereal dt;
    real et, hr, wt;
    extern /* Subroutine */ int feq_gen_clear_home_d_();
    doublereal feq_gen_event_base_d_;
    extern /* Subroutine */ int feq_gen_reset_hi_iq_ns_fac_d_(), feq_gen_out_genscn_d_(integer *
	    , doublereal *, real *), feq_gen_spout_init_d_(), 
	    feq_gen_reset_standard_output_ext_d_(char *, ftnlen);
    real bal;
    integer feq_gen_feql_index7_d_;
    extern /* Subroutine */ int feq_gen_hi_iq_ns_list_init_d_();
    doublereal bni;
    integer ibp, ibq;
    doublereal hrd, bnq, tai, taq, feq_gen_last_dt_to_console_d_;
    integer knt, qpn;
    doublereal wsi, wsq;
    real feq_gen_hi_iq_ns_dt_d_;
    integer wyr;
    extern /* Subroutine */ int feq_gen_hecdss_init_d_(integer *);
    real feq_gen_hi_iq_ns_up_d_;
    char feq_gen_old_summary_d_[4];
    extern /* Subroutine */ int feq_gen_set_version_d_();
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer iprt, knta, ivar, feq_gen_hi_iq_ns_knt_d_, rtap[4000], rwta[4000];
    real dthr, errp, errq, mxre, mxrv[16], rbal, feq_gen_hi_iq_ns_dwn_d_, 
	    feq_gen_hi_iq_ns_lmt_d_;
    doublereal dtdy;
    char gchk[4], qout[8*250], zout[8*250];
    extern /* Subroutine */ int info_(char *, char *, integer *, integer *, 
	    integer *, integer *, integer *, char *, integer *, integer *, 
	    integer *, char *, real *, real *, real *, real *, real *, 
	    integer *, integer *, integer *, integer *, real *, char *, char *
	    , char *, integer *, integer *, real *, char *, real *, real *, 
	    real *, char *, char *, char *, char *, integer *, integer *, 
	    real *, char *, char *, real *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen), load_(char *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, char *, char *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    ftnlen, ftnlen, ftnlen), oper_(doublereal *, integer *, integer *,
	     real *, integer *), feq_gen_find_volumes_d_(integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, real *, integer *, real *, real *, real *, 
	    doublereal *, doublereal *, real *, real *, doublereal *, 
	    doublereal *), tbox_(integer *);
    integer cflag;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_ts_mngt_init_d_(), feq_gen_ftab_loc_chk_d_(integer *);
    extern integer iargc_();
    char fname[64];
    integer bnode;
    extern /* Subroutine */ int feq_gen_set_time_step_tables_d_(integer *, integer *);
    integer berrp, berrq, bmxre, itemp, kount, ldcall, nerrp, bdynum, ioflag, 
	    lkount, lmxres, minprt, nerrq, nfree;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__75 = { 0, 6, 0, fmt_3220, 0 };
    static cilist feq_gen_io_d__77 = { 0, 6, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__80 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__81 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__82 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__84 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__85 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__86 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__87 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__88 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__89 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__91 = { 0, 6, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__92 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_3240, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_3210, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_3230, 0 };
    static cilist feq_gen_io_d__135 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__136 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__139 = { 0, 0, 0, fmt_3022, 0 };
    static cilist feq_gen_io_d__140 = { 0, 6, 0, fmt_3023, 0 };
    static cilist feq_gen_io_d__141 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__182 = { 0, 0, 0, fmt_2030, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, fmt_2020, 0 };
    static cilist feq_gen_io_d__192 = { 0, 0, 0, fmt_2180, 0 };
    static cilist feq_gen_io_d__193 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__203 = { 0, 0, 0, fmt_2020, 0 };
    static cilist feq_gen_io_d__204 = { 0, 6, 0, fmt_2021, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_2180, 0 };
    static cilist feq_gen_io_d__210 = { 0, 0, 0, fmt_2150, 0 };
    static cilist feq_gen_io_d__211 = { 0, 0, 0, fmt_2152, 0 };
    static cilist feq_gen_io_d__212 = { 0, 0, 0, fmt_2153, 0 };
    static cilist feq_gen_io_d__213 = { 0, 0, 0, fmt_2154, 0 };
    static cilist feq_gen_io_d__216 = { 0, 0, 0, fmt_3000, 0 };
    static cilist feq_gen_io_d__217 = { 0, 0, 0, 0, 0 };


/* SOURCE feq.for:543 */
/*<       implicitnone >*/
/*     + + + PURPOSE + + + */
/*     Compute unsteady open channel flow in a network of channels. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE feq.for:548 */
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
/* INCLUDE feq.for:549 */
/*     Command-line processing offset for Lahey compilers. */
/* SOURCE morg.prm:2 */
/*<       integermorg >*/
/* SOURCE morg.prm:3 */
/*<       parameter(morg=1) >*/
/*     MORG- offset value for the first command-line argument. */
/*           On PC systems this should be 1 if the supplied */
/*           routines for retrieval of command-line arguments */
/*           are used.  If the compiler differs from Lahey, */
/*           then the value should be set to get the first */
/*           file argument.  On Unix systems MORG=0 is normally */
/*           required. */
/* INCLUDE feq.for:550 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE feq.for:551 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE feq.for:552 */
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
/* INCLUDE feq.for:553 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE feq.for:554 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE feq.for:555 */
/* ********************************************************************** */
/* SOURCE difcom.cmn:3 */
/*<       common/difcom/clsr1,clsr2 >*/
/* SOURCE difcom.cmn:5 */
/*<       real*8clsr1(mndifa),clsr2(mndifa) >*/
/* ********************************************************************** */
/* INCLUDE feq.for:556 */
/* ********************************************************************** */
/* SOURCE dtcom.cmn:3 */
/*<        >*/
/* SOURCE dtcom.cmn:6 */
/*<       realauto,siter,high,low,maxdt,mindt,hfac,lfac,bwt,dwt,isiter >*/
/* ********************************************************************** */
/* INCLUDE feq.for:557 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE feq.for:558 */
/* ********************************************************************** */
/* SOURCE enothr.cmn:3 */
/*<        >*/
/* SOURCE enothr.cmn:6 */
/*<       common/enothc/enodid >*/
/* SOURCE enothr.cmn:8 */
/*<       character*16enodid(mnex) >*/
/* SOURCE enothr.cmn:10 */
/*<       integerbdyvec(mnex),resvec(mnex),non_conv_enode(mnex) >*/
/* SOURCE enothr.cmn:12 */
/*<       realencorq(mnex),encory(mnex),enmaxy(mnex),enminy(mnex) >*/
/* ********************************************************************** */
/* INCLUDE feq.for:559 */
/* ********************************************************************** */
/* SOURCE enrslt.cmn:3 */
/*<        >*/
/* SOURCE enrslt.cmn:7 */
/*<       integertostore(mnex),flownode(mnex),othernode(mnex) >*/
/* SOURCE enrslt.cmn:9 */
/*<        >*/
/* SOURCE enrslt.cmn:12 */
/*<       doubleprecisionftqmax(mnex),ftqmin(mnex),ftzmax(mnex) >*/
/* ********************************************************************** */
/*     Definition of identifiers */
/*     FTQMAX - time of maximum flow at a free node */
/*     FTQMIM - time of minimum flow at a free node */
/*     FTZMAX - time of maximium elevation at a free node */
/*     FNQMAX - maximum flow at a free node */
/*     FNZMAX - maximum elevation at a free node */
/*     FNQMIN - minimum flow at a free node */
/*     FLOWNODE - flow node number (internal) for flow node */
/*     OTHERNODE- other node number (internal) for the other head node */
/*     TOSTORE - vector of pointers (vector indices) to the location */
/*              where the flow at the flow node and the elevation at */
/*              the other node are stored for a 2-D control structure */
/*              using  a Code 5 Type 6 instruction in */
/*              the Network Matrix Control Input. */
/*              Used to check state of 2-D tables  at the end of a run. */
/*     QSTORE - vector of flows at the flow node for the control structure */
/*               of Code 5 Type 6.  This is the flow at the time the maximun */
/*               elevation occurs at the node in FNZMAX */
/*     ZSTORE- vector of elevation at the other node  at the time of */
/*              maximum elevation at the node in FNZMAX. */
/* INCLUDE feq.for:560 */
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
/* INCLUDE feq.for:561 */
/* ********************************************************************** */
/* SOURCE infcom.cmn:3 */
/*<        >*/
/* SOURCE infcom.cmn:10 */
/*<       common/infcmc/diffus,point,wind,soper,underf >*/
/* SOURCE infcom.cmn:12 */
/*<       character*4diffus,point,wind,soper,underf >*/
/* SOURCE infcom.cmn:14 */
/*<        >*/
/* SOURCE infcom.cmn:19 */
/*<        >*/
/* SOURCE infcom.cmn:22 */
/*<       realepsb,epssys,epssy2,qeps,qchop,mre,fac,zi,sfac,taufac >*/
/* SOURCE infcom.cmn:25 */
/*<       realmf(mcpfpt),dtvec(mnfrdt) >*/
/* SOURCE infcom.cmn:27 */
/*<       save/infcom/ >*/
/* ********************************************************************** */
/* INCLUDE feq.for:562 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE feq.for:563 */
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
/* INCLUDE feq.for:564 */
/*     NAMES FOR VARIOUS OPTIONAL FILES AND SPECIAL OUTPUT FILE */
/*     HEADINGS */
/* SOURCE namcom.cmn:5 */
/*<       character*7sphead(mnsout,2) >*/
/* SOURCE namcom.cmn:7 */
/*<       character*256bwfnam,fffnam,tsfnam,putnam,getnam >*/
/* SOURCE namcom.cmn:9 */
/*<       common/namcom/bwfnam,fffnam,tsfnam,sphead,putnam,getnam >*/
/* INCLUDE feq.for:565 */
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
/* INCLUDE feq.for:566 */
/* *********************************************************************** */
/* SOURCE rdcom.cmn:2 */
/*<        >*/
/* SOURCE rdcom.cmn:7 */
/*<       common/rdcomc/namin,ts_id_for_file_table >*/
/* SOURCE rdcom.cmn:9 */
/*<       characternamin(mxn_ts_f)*256,ts_id_for_file_table(mxn_ts)*16 >*/
/* SOURCE rdcom.cmn:11 */
/*<       integernum_ts_f,id_knt >*/
/* SOURCE rdcom.cmn:13 */
/*<        >*/
/* SOURCE rdcom.cmn:18 */
/*<       realvalain(mrrbuf),tmpvec(mrrbuf+5),ts_conversion_factor(mxn_ts) >*/
/* SOURCE rdcom.cmn:21 */
/*<        >*/
/* *********************************************************************** */
/* INCLUDE feq.for:567 */
/* *********************************************************************** */
/* SOURCE wrcom.cmn:2 */
/*<        >*/
/* SOURCE wrcom.cmn:6 */
/*<       common/wrcomc/namout >*/
/* SOURCE wrcom.cmn:7 */
/*<       common/wrcomd/runquad,oldf,quadfactor >*/
/* SOURCE wrcom.cmn:9 */
/*<       character*256namout(mnfout) >*/
/* SOURCE wrcom.cmn:11 */
/*<       integernfout,dss_out_count,irr_dt >*/
/* SOURCE wrcom.cmn:12 */
/*<        >*/
/* SOURCE wrcom.cmn:17 */
/*<       real*8runquad(mnfout),oldf(mnfout),quadfactor >*/
/* *********************************************************************** */
/* INCLUDE feq.for:568 */
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
/* INCLUDE feq.for:569 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/* INCLUDE feq.for:570 */
/*     COMMON BLOCK FOR COMMAND LINE PROCESSING FOR LAHEY COMPILER */
/* SOURCE clcom.cmn:3 */
/*<       common/clcomc/cl,namvec >*/
/* SOURCE clcom.cmn:4 */
/*<       character*127cl >*/
/* SOURCE clcom.cmn:5 */
/*<       character*64namvec(6) >*/
/* SOURCE clcom.cmn:7 */
/*<       common/clcom/iend,nxt,narg >*/
/* SOURCE clcom.cmn:8 */
/*<       integeriend,nxt,narg >*/
/* SOURCE clcom.cmn:10 */
/*<       save/clcom/ >*/
/* SOURCE clcom.cmn:11 */
/*<       save/clcomc/ >*/
/* INCLUDE feq.for:571 */
/* SOURCE timcom.cmn:2 */
/*<        >*/
/* SOURCE timcom.cmn:5 */
/*<       integeritick,itick0,itick1,itick2,cmpext,cmpint,slvext,slvint >*/
/* SOURCE timcom.cmn:8 */
/*<       realmin_time_step >*/
/* INCLUDE feq.for:572 */
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

/* INCLUDE feq.for:573 */
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
/* INCLUDE feq.for:574 */
/*     Common block for items needed for creating files for */
/*     GENSCN */
/* SOURCE genscn.cmn:4 */
/*<       integermngsout,mngsout2 >*/
/* SOURCE genscn.cmn:5 */
/*<       parameter(mngsout=20000,mngsout2=2*mngsout) >*/
/* SOURCE genscn.cmn:7 */
/*<       integerfeo_unit,tsd_unit,ftf_unit,genscn_nout,genscn_record_knt >*/
/* SOURCE genscn.cmn:10 */
/*<       integergenscn_pout(mngsout) >*/
/* SOURCE genscn.cmn:12 */
/*<       realgenscn_out_vec(mngsout2) >*/
/* SOURCE genscn.cmn:14 */
/*<       real*8genscn_jtime >*/
/* SOURCE genscn.cmn:16 */
/*<        >*/
/* INCLUDE feq.for:575 */
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
/* INCLUDE feq.for:576 */
/*     Flag to signal that there are code 14 instructions in the */
/*     network-matrix-control input. */
/* SOURCE code14.cmn:4 */
/*<       integercode14_present >*/
/* SOURCE code14.cmn:6 */
/*<       common/code14/code14_present >*/
/* SOURCE code14.cmn:8 */
/*<       save/code14/ >*/
/* INCLUDE feq.for:577 */
/*     common for passing info for table upgrading-going from one form */
/*     to one that is smoother in its representation */
/* SOURCE tabupgrade.cmn:4 */
/*<       characterty13_to_ty43*4,twod_cubic_out*4,upgrade_xsec_tab*4 >*/
/* SOURCE tabupgrade.cmn:6 */
/*<       common/upgrdc/ty13_to_ty43,twod_cubic_out,upgrade_xsec_tab >*/
/* INCLUDE feq.for:578 */
/*     Common block for handling time-step tables */
/* SOURCE timetab.cmn:2 */
/*<       integerstddtout,tab_for_maxdt >*/
/* SOURCE timetab.cmn:3 */
/*<       charactermake_dt_tab*256,use_maxdt_tab*16 >*/
/* SOURCE timetab.cmn:5 */
/*<       common/timetabc/make_dt_tab,use_maxdt_tab >*/
/* SOURCE timetab.cmn:6 */
/*<       common/timetab/stddtout,tab_for_maxdt >*/
/* SOURCE timetab.cmn:8 */
/*<       save/timetabc/,/timetab/ >*/
/* INCLUDE feq.for:579 */
/*     Common to pass the os flag */
/* SOURCE whatos.cmn:3 */
/*<       integerosis >*/
/* SOURCE whatos.cmn:4 */
/*<       common/whatos/osis >*/
/* SOURCE whatos.cmn:6 */
/*<       save/whatos/ >*/
/* INCLUDE feq.for:580 */
/*     Common block for extending the special output options */
/* SOURCE spout.cmn:3 */
/*<        >*/
/* SOURCE spout.cmn:8 */
/*<        >*/
/* SOURCE spout.cmn:15 */
/*<        >*/
/* SOURCE spout.cmn:21 */
/*<        >*/
/* SOURCE spout.cmn:25 */
/*<        >*/
/* SOURCE spout.cmn:29 */
/*<       common/spoutc/spout_item_label,spout_item_name,extra_buffer >*/
/* SOURCE spout.cmn:33 */
/*<       save/spouta/,/spoutc/ >*/
/* INCLUDE feq.for:581 */
/* SOURCE maketabindex.cmn:2 */
/*<       character*4make_tab_index >*/
/* SOURCE maketabindex.cmn:4 */
/*<       integerftab_type(mftnum),data_pnt(mftnum),index_knt,stdindex >*/
/* SOURCE maketabindex.cmn:7 */
/*<       characterftabid(mftnum)*16,ftab_fn(mftnum)*256 >*/
/* SOURCE maketabindex.cmn:9 */
/*<       common/mktbindxc/ftab_fn,ftabid,make_tab_index >*/
/* SOURCE maketabindex.cmn:10 */
/*<       common/mktbindx/ftab_type,data_pnt,index_knt,stdindex >*/
/* INCLUDE feq.for:582 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE feq.for:585 */
/*<       characterno*4,yes*4 >*/
/* SOURCE feq.for:586 */
/*<       saveno,yes >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE feq.for:589 */
/*<        >*/
/* SOURCE feq.for:596 */
/*<        >*/
/* SOURCE feq.for:599 */
/*<        >*/
/* SOURCE feq.for:603 */
/*<        >*/
/* SOURCE feq.for:605 */
/*<        >*/
/* SOURCE feq.for:608 */
/*<        >*/
/* SOURCE feq.for:611 */
/*<       logicalthere >*/
/*     + + + INTRINSICS + + + */
/* SOURCE feq.for:614 */
/*<       intrinsicfloat,mod,sngl >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE feq.for:617 */
/*<       integeriargc,lpyear,get_unit,what_os >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE feq.for:620 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE feq.for:541 */
/*<       integer feql_index7 >*/
/* SOURCE feq.for:541 */
/*<       integer feq_len_trim >*/
/* SOURCE feq.for:541 */
/*<       external feq_len_trim >*/
/* SOURCE feq.for:631 */
/*<       datayes/'YES'/,no/'NO'/ >*/
/* SOURCE feq.for:634 */
/*<  2010 format(/) >*/
/* L2010: */
/* SOURCE feq.for:635 */
/*<  2020  >*/
/* L2020: */
/* 2021 FORMAT('+At ',I4,'/',I2,'/',I2,':',F6.3,' DT=', F8.2, ' sec') */
/* SOURCE feq.for:638 */
/*<  2021 format(' At ',i4,'/',i2,'/',i2,':',f6.3,' DT=',f8.2,' sec') >*/
/* L2021: */
/* SOURCE feq.for:639 */
/*<  2030  >*/
/* L2030: */
/* SOURCE feq.for:641 */
/*<  2150  >*/
/* L2150: */
/* SOURCE feq.for:644 */
/*<  2152  >*/
/* L2152: */
/* SOURCE feq.for:646 */
/*<  2153  >*/
/* L2153: */
/* SOURCE feq.for:648 */
/*<  2154  >*/
/* L2154: */
/* SOURCE feq.for:650 */
/*<  2180  >*/
/* L2180: */
/* SOURCE feq.for:653 */
/*<  3000  >*/
/* L3000: */
/* SOURCE feq.for:655 */
/*<  3022 format(/,' Initialization time=',f10.2,' secs or ',f10.4,' mins') >*/
/* L3022: */
/* SOURCE feq.for:656 */
/*<  3023 format(' Setup time=',f10.2,' secs or ',f10.4,' mins') >*/
/* L3023: */
/* SOURCE feq.for:657 */
/*<  3210 format(/,' SRLIM=',1pe12.5) >*/
/* L3210: */
/* SOURCE feq.for:658 */
/*<  3220 format('*ERR:165* Value of MORG wrong in ARSIZE. Must be 0 or 1.') >*/
/* L3220: */
/* SOURCE feq.for:659 */
/*<  3230 format(/,' Processing stopped.  Errors encountered.') >*/
/* L3230: */
/* SOURCE feq.for:660 */
/*<  3240  >*/
/* L3240: */
/* SOURCE feq.for:662 */
/*<    95  >*/
/* L95: */
/* SOURCE feq.for:668 */
/*<    96  >*/
/* L96: */
/* *********************************************************************** */
/* c     set the hi iq factors here for initial testing */
/*      hi_iq_ns_dwn = 0.75 */
/*      hi_iq_ns_lmt = 0.25 */
/* c     Increase the factor over more than one time step of convergence */
/* c     Will need to experiment with this */
/*      hi_iq_ns_up = sqrt( 1.0/hi_iq_ns_dwn) */
/*     Clear the location-status flag for function tables. */
/* SOURCE feq.for:681 */
/*<       dofeql_index7=1,mftnum >*/
    for (feq_gen_feql_index7_d_ = 1; feq_gen_feql_index7_d_ <= 10002; ++feq_gen_feql_index7_d_) {
/* SOURCE feq.for:681 */
/*<       ft_loc_status(feql_index7)=' ' >*/
	*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[feq_gen_feql_index7_d_ - 1] = ' ';
/* SOURCE feq.for:681 */
/*<       enddo >*/
    }
/* SOURCE feq.for:683 */
/*<       callhi_iq_ns_list_init() >*/
    feq_gen_hi_iq_ns_list_init_d_();

/*     strings for Unix what command */
/* SOURCE feq.for:687 */
/*<       fname='@(#)FEQ - Full Equations Flow Routing Model' >*/
    s_copy(fname, const_cast<char*>("@(#)FEQ - Full Equations Flow Routing Model"), (ftnlen)64, (
	    ftnlen)43);
/* SOURCE feq.for:689 */
/*<       fname='@(#)FEQ - Franz, D.D., and Melching, C.S., WRIR 96-xxxx' >*/
    s_copy(fname, const_cast<char*>("@(#)FEQ - Franz, D.D., and Melching, C.S., WRIR 96-xxxx"), (
	    ftnlen)64, (ftnlen)55);
/* SOURCE feq.for:690 */
/*<       fname='@(#)FEQ - Contact: h2osoft@usgs.gov' >*/
    s_copy(fname, const_cast<char*>("@(#)FEQ - Contact: h2osoft@usgs.gov"), (ftnlen)64, (ftnlen)
	    35);
/* SOURCE feq.for:691 */
/*<       fname='@(#)FEQ - Version: 8.92 1998/06/01' >*/
    s_copy(fname, const_cast<char*>("@(#)FEQ - Version: 8.92 1998/06/01"), (ftnlen)64, (ftnlen)
	    34);
/*     set string for use with RCS ident command */
/* SOURCE feq.for:693 */
/*<       fname='$Id: feq.f,v 8.5 1996/02/28 18:30:45 rsregan Exp rsregan $' >*/
    s_copy(fname, const_cast<char*>("$Id: feq.f,v 8.5 1996/02/28 18:30:45 rsregan Exp rsregan $")
	    , (ftnlen)64, (ftnlen)58);
/*     Initialize various  labeled common blocks */
/* SOURCE feq.for:697 */
/*<       callspout_init() >*/
    feq_gen_spout_init_d_();
/* SOURCE feq.for:698 */
/*<       callxoffin() >*/
    xoffin_();
/*     Clear the HOME portion of file names for function tables */
/*     and time series. */
/* SOURCE feq.for:702 */
/*<       callclear_home() >*/
    feq_gen_clear_home_d_();
/*     Clear the standard output extension */
/* SOURCE feq.for:705 */
/*<       callclear_ext() >*/
    feq_gen_clear_ext_d_();
/*     Clear the global output home name */
/* SOURCE feq.for:708 */
/*<       callclear_ghome_out() >*/
    feq_gen_clear_ghome_out_d_();
/*     Initialize selector-name processing */
/* SOURCE feq.for:711 */
/*<       callselector_symbol_init() >*/
    feq_gen_selector_symbol_init_d_();

/*     Initialize the mechanism for tracking I/O unit numbers. */
/*     User is not permitted to select any unit number. */
/* SOURCE feq.for:716 */
/*<       callinitialize_units >*/
    feq_gen_initialize_units_d_();
/*     Set the GENSCN values to their defaults */
/* SOURCE feq.for:718 */
/*<       callinitialize_genscn() >*/
    feq_gen_initialize_genscn_d_();
/*     Initialize the count of internal tabids */
/* SOURCE feq.for:721 */
/*<       callreset_kount_of_internal_tabids() >*/
    feq_gen_reset_kount_of_internal_tabids_d_();
/*     Set the version number and date */
/* SOURCE feq.for:724 */
/*<       callset_version() >*/
    feq_gen_set_version_d_();
/*     Clear the count of detention and delay reservoirs */
/* SOURCE feq.for:727 */
/*<       dten_knt=0 >*/
    tamcom_1.feq_gen_dten_knt_d_ = 0;
/* SOURCE feq.for:728 */
/*<       dlay_knt=0 >*/
    tamcom_1.feq_gen_dlay_knt_d_ = 0;
/*     Start the time-keeping */
/* SOURCE feq.for:731 */
/*<       calltimerl(itick) >*/
    timerl_(&timcom_1.itick);
/*     set for the minimum time step */
/* SOURCE feq.for:734 */
/*<       min_time_step=1.e20 >*/
    timcom_1.feq_gen_min_time_step_d_ = (float)1e20;
/*     set the last time step output to the console to an impossible */
/*     vallue */
/* SOURCE feq.for:738 */
/*<       last_dt_to_console=0 >*/
    feq_gen_last_dt_to_console_d_ = 0.;
/*     The values for the standard input and output units are given */
/*     in the file: stdun.cmn.  Set their value here because the */
/*     common block is used in some cases where the normal units */
/*     have not been transferred.  It is assumed that unit 0 is */
/*     output to the current console.  That output only used */
/*     if a bug is detected in GET_UNIT. */
/* SOURCE feq.for:747 */
/*<       std5=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std5 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE feq.for:748 */
/*<       std6=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std6 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE feq.for:750 */
/*<       in=std5 >*/
    xscom_1.in = feq_gen_stdun_com_d_1.std5;
/* SOURCE feq.for:751 */
/*<       stdout=std6 >*/
    xscom_1.stdout = feq_gen_stdun_com_d_1.std6;
/*     Initialize HEC DSS system.  This call may be a dummy if */
/*     the DSS access is detached. */
/* SOURCE feq.for:755 */
/*<       callhecdss_init(stdout) >*/
    feq_gen_hecdss_init_d_(&xscom_1.stdout);
/*     Initialize the time-series file tracking system */
/* SOURCE feq.for:758 */
/*<       callts_mngt_init >*/
    feq_gen_ts_mngt_init_d_();
/* SOURCE feq.for:760 */
/*<       if(morg.lt.0.or.morg.gt.1)then >*/
    if (FALSE_) {
/* SOURCE feq.for:761 */
/*<       write(*,3220) >*/
	s_wsfe(&feq_gen_io_d__75);
	e_wsfe();
/* SOURCE feq.for:762 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE feq.for:763 */
/*<       endif >*/
    }
/*     Set the carriage-return character value */
/* SOURCE feq.for:766 */
/*<       callsetcr() >*/
    setcr_();
/*     PROCESS COMMAND LINE ARGUMENTS */
/* SOURCE feq.for:769 */
/*<       osis=what_os() >*/
    whatos_1.osis = feq_gen_what_os_d_();
/* SOURCE feq.for:770 */
/*<       narg=0 >*/
    clcom_1.narg = 0;
/* SOURCE feq.for:771 */
/*<       nxt=1 >*/
    clcom_1.nxt = 1;
/* SOURCE feq.for:772 */
/*<       narg=iargc() >*/
    clcom_1.narg = iargc_();
/* SOURCE feq.for:774 */
/*<       if(narg.eq.1+morg)then >*/
    if (clcom_1.narg == 2) {
/*       If only one file argument is given we assume that the */
/*       extension, if any, from the file given is stripped and the */
/*       remaining  file name IS formed by adding .out */
/*       to the file name given by the user,  stripped of its extension. */
/* SOURCE feq.for:780 */
/*<       stdext_option=1 >*/
	feq_gen_stdext_option_d_ = 1;
/* SOURCE feq.for:781 */
/*<       elseif(narg-morg.lt.2)then >*/
    } else if (clcom_1.narg - 1 < 2) {
/* SOURCE feq.for:782 */
/*<       write(*,95) >*/
	s_wsfe(&feq_gen_io_d__77);
	e_wsfe();
/* SOURCE feq.for:783 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE feq.for:784 */
/*<       else >*/
    } else {
/* SOURCE feq.for:785 */
/*<       stdext_option=0 >*/
	feq_gen_stdext_option_d_ = 0;
/* SOURCE feq.for:786 */
/*<       endif >*/
    }
/*     GET THE FIRST FILE ARGUMENT */
/* SOURCE feq.for:790 */
/*<       callgetarg(1+morg,fname) >*/
    getarg_(&feq_gen_c_d_2, fname, (ftnlen)64);
/* SOURCE feq.for:793 */
/*<       callos_file_style(fname) >*/
    feq_gen_os_file_style_d_(fname, (ftnlen)64);
/* SOURCE feq.for:795 */
/*<       inquire(file=fname,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 64;
    feq_gen_ioin_d_1.infile = fname;
    feq_gen_ioin_d_1.inex = &there;
    feq_gen_ioin_d_1.inopen = 0;
    feq_gen_ioin_d_1.innum = 0;
    feq_gen_ioin_d_1.innamed = 0;
    feq_gen_ioin_d_1.inname = 0;
    feq_gen_ioin_d_1.inacc = 0;
    feq_gen_ioin_d_1.inseq = 0;
    feq_gen_ioin_d_1.indir = 0;
    feq_gen_ioin_d_1.infmt = 0;
    feq_gen_ioin_d_1.inform = 0;
    feq_gen_ioin_d_1.inunf = 0;
    feq_gen_ioin_d_1.inrecl = 0;
    feq_gen_ioin_d_1.innrec = 0;
    feq_gen_ioin_d_1.inblank = 0;
    f_inqu(&feq_gen_ioin_d_1);
/* SOURCE feq.for:796 */
/*<       if(there)then >*/
    if (there) {
/* SOURCE feq.for:797 */
/*<       open(in,file=fname,status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = xscom_1.in;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = fname;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE feq.for:798 */
/*<       else >*/
    } else {
/* SOURCE feq.for:799 */
/*<       n=feq_len_trim(fname) >*/
	n = feq_gen_feq_len_trim_d_(fname, (ftnlen)64);
/* SOURCE feq.for:800 */
/*<       write(*,*)' ' >*/
	s_wsle(&feq_gen_io_d__80);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE feq.for:801 */
/*<       write(*,*)' File named: ',fname(1:n),' not found.' >*/
	s_wsle(&feq_gen_io_d__81);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" File named: "), (ftnlen)13);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, fname, n);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" not found."), (ftnlen)11);
	e_wsle();
/* SOURCE feq.for:802 */
/*<       write(*,*)' Please check spelling of master-input file.' >*/
	s_wsle(&feq_gen_io_d__82);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Please check spelling of master-input file."), (
		ftnlen)44);
	e_wsle();
/* SOURCE feq.for:803 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE feq.for:804 */
/*<       endif >*/
    }
/* SOURCE feq.for:806 */
/*<       if(stdext_option.eq.1)then >*/
    if (feq_gen_stdext_option_d_ == 1) {
/*       Form the other file name */
/* SOURCE feq.for:808 */
/*<       callmake_standard_file_names(fname,fname2) >*/
	feq_gen_make_standard_file_names_d_(fname, fname2, (ftnlen)64, (ftnlen)64);
/* SOURCE feq.for:810 */
/*<       else >*/
    } else {
/*       GET THE SECOND FILE ARGUMENT */
/* SOURCE feq.for:814 */
/*<       callgetarg(2+morg,fname2) >*/
	getarg_(&feq_gen_c_d_3, fname2, (ftnlen)64);
/* SOURCE feq.for:817 */
/*<       endif >*/
    }
/* SOURCE feq.for:818 */
/*<       callos_file_style(fname2) >*/
    feq_gen_os_file_style_d_(fname2, (ftnlen)64);
/* SOURCE feq.for:820 */
/*<       write(*,*)' ' >*/
    s_wsle(&feq_gen_io_d__84);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE feq.for:821 */
/*<       if(fname.eq.fname2)then >*/
    if (s_cmp(fname, fname2, (ftnlen)64, (ftnlen)64) == 0) {
/* SOURCE feq.for:822 */
/*<       write(*,*)' The names given for the two command-line' >*/
	s_wsle(&feq_gen_io_d__85);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" The names given for the two command-line"), (
		ftnlen)41);
	e_wsle();
/* SOURCE feq.for:823 */
/*<       write(*,*)' arguments are the same.  They must be different.' >*/
	s_wsle(&feq_gen_io_d__86);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" arguments are the same.  They must be differe\
nt."), (ftnlen)49);
	e_wsle();
/* SOURCE feq.for:824 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE feq.for:825 */
/*<       elseif(fname2=='feqin'.or.fname2=='FEQIN')then >*/
    } else if (s_cmp(fname2, const_cast<char*>("feqin"), (ftnlen)64, (ftnlen)5) == 0 || s_cmp(
	    fname2, const_cast<char*>("FEQIN"), (ftnlen)64, (ftnlen)5) == 0) {
/* SOURCE feq.for:827 */
/*<       write(*,*)' Master-output file cannot be: feqin or FEQIN.' >*/
	s_wsle(&feq_gen_io_d__87);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Master-output file cannot be: feqin or FEQIN."),
		 (ftnlen)46);
	e_wsle();
/* SOURCE feq.for:828 */
/*<       write(*,*)' These file names are reserved for the standard' >*/
	s_wsle(&feq_gen_io_d__88);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" These file names are reserved for the standard")
		, (ftnlen)47);
	e_wsle();
/* SOURCE feq.for:829 */
/*<       write(*,*)' master-input file.' >*/
	s_wsle(&feq_gen_io_d__89);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" master-input file."), (ftnlen)19);
	e_wsle();
/* SOURCE feq.for:830 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE feq.for:831 */
/*<       endif >*/
    }
/* SOURCE feq.for:832 */
/*<       open(stdout,file=fname2,status='UNKNOWN',iostat=ioflag) >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = xscom_1.stdout;
    feq_gen_o_d_1.ofnmlen = 64;
    feq_gen_o_d_1.ofnm = fname2;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE feq.for:834 */
/*<       if(ioflag.ne.0)then >*/
    if (ioflag != 0) {
/* SOURCE feq.for:835 */
/*<       n=feq_len_trim(fname2) >*/
	n = feq_gen_feq_len_trim_d_(fname2, (ftnlen)64);
/* SOURCE feq.for:836 */
/*<       write(*,96)fname2(1:n) >*/
	s_wsfe(&feq_gen_io_d__91);
	do_fio(&feq_gen_c_d_1, fname2, n);
	e_wsfe();
/* SOURCE feq.for:837 */
/*<       write(*,*)'iostat=',ioflag >*/
	s_wsle(&feq_gen_io_d__92);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("iostat="), (ftnlen)7);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ioflag, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE feq.for:838 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE feq.for:839 */
/*<       endif >*/
    }
/*     Get the extension on the master output file, if any, and */
/*     place in the standard extension for output.  If non-blank, */
/*     it will be appended to all output files. */
/* SOURCE feq.for:844 */
/*<       callreset_standard_output_ext(fname2) >*/
    feq_gen_reset_standard_output_ext_d_(fname2, (ftnlen)64);
/*     Open the file we will use for checking.  Do not make part of */
/*     the standard package.  Comment out after testing */
/*      OPEN(UNIT=45, FILE='fromfeq.d',STATUS='UNKNOWN', */
/*     A          FORM='UNFORMATTED') */
/*     Output the header to the standard output */
/* SOURCE feq.for:855 */
/*<       calltbox(stdout) >*/
    tbox_(&xscom_1.stdout);
/*     Output the names of the standard input file */
/* SOURCE feq.for:859 */
/*<       write(stdout,3240)fname,fname2 >*/
    feq_gen_io_d__93.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__93);
    do_fio(&feq_gen_c_d_1, fname, (ftnlen)64);
    do_fio(&feq_gen_c_d_1, fname2, (ftnlen)64);
    e_wsfe();
/*     Initialize the macro facility and the symbol table. */
/* SOURCE feq.for:862 */
/*<       callmacro_symbol_init() >*/
    feq_gen_macro_symbol_init_d_();
/* SOURCE feq.for:864 */
/*<       lpnt=0 >*/
    infcom_1.lpnt = 0;
/* SOURCE feq.for:865 */
/*<       ntint=0 >*/
    ntint = 0;
/* SOURCE feq.for:866 */
/*<       iprt=1 >*/
    iprt = 1;
/* SOURCE feq.for:869 */
/*<        >*/
    info_(fname2, fname, &qpn, &nrwta, rtap, rwta, &ldcall, nodeid, &minprt, &
	    tsfcom_1.lagtsf, &nfree, gchk, &vunit, &abstol, &hslot, &wslot, &
	    nslot, &numlim, &bnode, &bdynum, &resnum, rtafac, feq_gen_old_summary_d_, 
	    feq_gen_cd14_tab_datum_d_, feq_gen_cd5t6_tab_datum_d_, &feq_gen_start_eq_d_, &feq_gen_end_eq_d_, &
	    feq_gen_dtmin_out_d_, feq_gen_hi_iq_ns_d_, &feq_gen_hi_iq_ns_dwn_d_, &feq_gen_hi_iq_ns_up_d_, &
	    feq_gen_hi_iq_ns_lmt_d_, upgrdc_1.feq_gen_ty13_to_ty43_d_, 
	    upgrdc_1.feq_gen_upgrade_xsec_tab_d_, timetabc_1.feq_gen_make_dt_tab_d_, 
	    timetabc_1.feq_gen_use_maxdt_tab_d_, &feq_gen_hi_iq_ns_numgt_d_, &feq_gen_hi_iq_ns_knt_d_, &
	    feq_gen_hi_iq_ns_dt_d_, feq_gen_frcst_wth_dtsf_d_, mktbindxc_1.feq_gen_make_tab_index_d_, &
	    feq_gen_dz_for_output_d_, (ftnlen)64, (ftnlen)64, (ftnlen)4, (ftnlen)4, (
	    ftnlen)4, (ftnlen)4, (ftnlen)4, (ftnlen)4, (ftnlen)4, (ftnlen)4, (
	    ftnlen)256, (ftnlen)16, (ftnlen)4, (ftnlen)4);
/*     set the option for forecasting with dtsf present */
/* SOURCE feq.for:882 */
/*<       if(frcst_wth_dtsf=='YES')then >*/
    if (s_cmp(feq_gen_frcst_wth_dtsf_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE feq.for:883 */
/*<       frcst=1 >*/
	tsfcom_1.frcst = 1;
/* SOURCE feq.for:884 */
/*<       else >*/
    } else {
/* SOURCE feq.for:885 */
/*<       frcst=0 >*/
	tsfcom_1.frcst = 0;
/* SOURCE feq.for:886 */
/*<       endif >*/
    }
/*     Set values for time-step tables. */
/* SOURCE feq.for:890 */
/*<       callset_time_step_tables(stdout,eflag) >*/
    feq_gen_set_time_step_tables_d_(&xscom_1.stdout, &xscom_1.eflag);
/*     Assign the formats for detailed branch output.  FTID is in common */
/*     group file name bnelem.cmn */
/* SOURCE feq.for:894 */
/*<       if(grav.gt.15.0)then >*/
    if (gravcm_1.grav > (float)15.) {
/* SOURCE feq.for:895 */
/*<       if(sfac.le.1.0)then >*/
	if (infcom_1.sfac <= (float)1.) {
/* SOURCE feq.for:896 */
/*<       ftid=1 >*/
	    bnelem_1.ftid = 1;
/* SOURCE feq.for:897 */
/*<       elseif(sfac.le.10.0)then >*/
	} else if (infcom_1.sfac <= (float)10.) {
/* SOURCE feq.for:898 */
/*<       ftid=2 >*/
	    bnelem_1.ftid = 2;
/* SOURCE feq.for:899 */
/*<       elseif(sfac.le.100.0)then >*/
	} else if (infcom_1.sfac <= (float)100.) {
/* SOURCE feq.for:900 */
/*<       ftid=3 >*/
	    bnelem_1.ftid = 3;
/* SOURCE feq.for:901 */
/*<       elseif(sfac.le.1000.0)then >*/
	} else if (infcom_1.sfac <= (float)1e3) {
/* SOURCE feq.for:902 */
/*<       ftid=4 >*/
	    bnelem_1.ftid = 4;
/* SOURCE feq.for:903 */
/*<       else >*/
	} else {
/* SOURCE feq.for:904 */
/*<       ftid=5 >*/
	    bnelem_1.ftid = 5;
/* SOURCE feq.for:905 */
/*<       endif >*/
	}
/* SOURCE feq.for:906 */
/*<       else >*/
    } else {
/* SOURCE feq.for:907 */
/*<       if(sfac.le.1.0)then >*/
	if (infcom_1.sfac <= (float)1.) {
/* SOURCE feq.for:908 */
/*<       ftid=6 >*/
	    bnelem_1.ftid = 6;
/* SOURCE feq.for:909 */
/*<       elseif(sfac.le.10.0)then >*/
	} else if (infcom_1.sfac <= (float)10.) {
/* SOURCE feq.for:910 */
/*<       ftid=7 >*/
	    bnelem_1.ftid = 7;
/* SOURCE feq.for:911 */
/*<       elseif(sfac.le.100.0)then >*/
	} else if (infcom_1.sfac <= (float)100.) {
/* SOURCE feq.for:912 */
/*<       ftid=8 >*/
	    bnelem_1.ftid = 8;
/* SOURCE feq.for:913 */
/*<       elseif(sfac.le.1000.0)then >*/
	} else if (infcom_1.sfac <= (float)1e3) {
/* SOURCE feq.for:914 */
/*<       ftid=9 >*/
	    bnelem_1.ftid = 9;
/* SOURCE feq.for:915 */
/*<       else >*/
	} else {
/* SOURCE feq.for:916 */
/*<       ftid=10 >*/
	    bnelem_1.ftid = 10;
/* SOURCE feq.for:917 */
/*<       endif >*/
	}
/* SOURCE feq.for:918 */
/*<       endif >*/
    }
/*     Assign the conversion factor for quadrature in the Output Files Block */
/*     If English units are used, convert from cubic feet to acre-feet */
/*     and if metric unit are used, convert from cubic meters to 1,000 cubic meters */
/* SOURCE feq.for:923 */
/*<       if(grav.gt.15.0)then >*/
    if (gravcm_1.grav > (float)15.) {
/* SOURCE feq.for:924 */
/*<       quadfactor=1.d0/43560.d0 >*/
	wrcomd_1.quadfactor = 2.295684113865932e-5;
/* SOURCE feq.for:925 */
/*<       else >*/
    } else {
/* SOURCE feq.for:926 */
/*<       quadfactor=1.d0/1000.d0 >*/
	wrcomd_1.quadfactor = .001;
/* SOURCE feq.for:927 */
/*<       endif >*/
    }
/* SOURCE feq.for:931 */
/*<       wt=bwt >*/
    wt = dtcom_1.bwt;
/* SOURCE feq.for:933 */
/*<       if(sqreps.lt.0.0)then >*/
    if (miscon_1.sqreps < (float)0.) {
/* SOURCE feq.for:934 */
/*<       srlim=1.e30 >*/
	srlim = (float)1e30;
/* SOURCE feq.for:935 */
/*<       else >*/
    } else {
/* SOURCE feq.for:936 */
/*<       srlim=sqreps >*/
	srlim = miscon_1.sqreps;
/* SOURCE feq.for:937 */
/*<       endif >*/
    }
/* SOURCE feq.for:938 */
/*<       write(stdout,3210)srlim >*/
    feq_gen_io_d__132.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__132);
    do_fio(&feq_gen_c_d_1, (char *)&srlim, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE feq.for:939 */
/*<       if(eflag.ne.0)then >*/
    if (xscom_1.eflag != 0) {
/* SOURCE feq.for:940 */
/*<       write(stdout,3230) >*/
	feq_gen_io_d__133.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__133);
	e_wsfe();
/* SOURCE feq.for:941 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE feq.for:942 */
/*<       endif >*/
    }
/* SOURCE feq.for:943 */
/*<       if(gchk.eq.'YES')then >*/
    if (s_cmp(gchk, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/*       CHECK STREAM CHANNEL GEOMETRY */
/* SOURCE feq.for:946 */
/*<       callchkgeo(stdout,nbra,brpt) >*/
	chkgeo_(&xscom_1.stdout, &infcom_1.nbra, infcom_1.brpt);
/* SOURCE feq.for:948 */
/*<       endif >*/
    }
/*     Set the time to its value at the start of the run. */
/* SOURCE feq.for:951 */
/*<       time=86400.d0*(sjtime-tab_789_jtbase) >*/
    xscom_1.time = (julian_1.sjtime - julian_1.feq_gen_tab_789_jtbase_d_) * 86400.;
/* SOURCE feq.for:953 */
/*<        >*/
    stint_(&tsfcom_1.tsfdsn, &xscom_1.stdout, &infcom_1.nbra, &infcom_1.nex, 
	    infcom_1.brpt, infcom_1.exnodt, &xscom_1.eflag, &infcom_1.epsb, &
	    gravcm_1.grav, &xscom_1.in, &infcom_1.maxit, &infcom_1.nbn, &
	    xscom_1.output, &julian_1.jtime, &infcom_1.sfac, &infcom_1.nblk, 
	    infcom_1.opblk, &infcom_1.bwfdsn, &infcom_1.fffdsn, 
	    infcmc_1.diffus, infcmc_1.underf, &infcom_1.ifrz, &dt, &
	    infcom_1.getdsn, &infcom_1.putdsn, &julian_1.ujtime, &
	    infcom_1.ept, &bnode, &infcom_1.qeps, &feq_gen_dz_for_output_d_, 
	    infcom_1.emc, &tsfcom_1.feq_gen_dtsf_rec_d_, &wt, &dtcom_1.siter, (ftnlen)
	    4, (ftnlen)4);
/* SOURCE feq.for:961 */
/*<       if(eflag.ne.0)then >*/
    if (xscom_1.eflag != 0) {
/* SOURCE feq.for:962 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE feq.for:963 */
/*<       endif >*/
    }
/*     DEBUG OUTPUT HERE */
/*      IF(OUTPUT.NE.0) THEN */

/*        CALL BROUT */
/*     I            (STDOUT, NBN, NBRA, BRPT) */
/*        CALL EXOUT */
/*     I            (STDOUT, EPT, NEX, EMC, EXNODT) */

/*        IF(POINT.EQ.YES.OR.DIFFUS.EQ.YES.OR.WIND.EQ.YES) THEN */
/*          CALL DPWOUT */
/*     I             (DIFFUS, STDOUT, LPNT, MRPFPT, NO, POINT, WIND, MF, */
/*     I              PFPNT) */
/*        ENDIF */

/*        CALL FTOUT */
/*     I            (STDOUT, */
/*     M             OUTPUT) */
/*        CALL INOUT */
/*     I            (STDOUT, NBRA, NEX, BRPT) */
/*      ENDIF */
/*     Check side-weir relationships against initial conditions if the initial */
/*     conditions were not read but computed in BCKWTR */
/* SOURCE feq.for:990 */
/*<       if(getdsn.eq.0)then >*/
    if (infcom_1.getdsn == 0) {
/* SOURCE feq.for:991 */
/*<       if(code14_present.gt.0)then >*/
	if (code14_1.feq_gen_code14_present_d_ > 0) {
/* SOURCE feq.for:992 */
/*<       callside_weir_chk(stdout,grav,nex,exnodt,ept,emc) >*/
	    feq_gen_side_weir_chk_d_(&xscom_1.stdout, &gravcm_1.grav, &infcom_1.nex, 
		    infcom_1.exnodt, &infcom_1.ept, infcom_1.emc);
/* SOURCE feq.for:995 */
/*<       endif >*/
	}
/* SOURCE feq.for:996 */
/*<       endif >*/
    }
/*     MAKE CHECK OF THE INITIAL CONDITIONS AND VALUES WHICH COULD */
/*     NOT BE CHECKED IN INFO2() */
/* SOURCE feq.for:1000 */
/*<        >*/
    finchk_(&xscom_1.stdout, &infcom_1.nex, infcom_1.exnodt, &hslot, &
	    infcom_1.qchop, &infcom_1.ept, feq_gen_cd14_tab_datum_d_, 
	    feq_gen_cd5t6_tab_datum_d_, infcom_1.emc, (ftnlen)4, (ftnlen)4);
/*     Check for locations of function tables known in FEQ but not */
/*     currently defined in the function tables.  Also do various */
/*     checks and report status for vdatum, unitsys, and basis. */

/* SOURCE feq.for:1009 */
/*<       if(make_tab_index=='YES'.and.g_zone/='NONE')then >*/
    if (s_cmp(mktbindxc_1.feq_gen_make_tab_index_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0 
	    && s_cmp(feq_gen_grid_datum_d_1.feq_gen_g_zone_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 
	    0) {
/* SOURCE feq.for:1010 */
/*<       callftab_loc_chk(stdout) >*/
	feq_gen_ftab_loc_chk_d_(&xscom_1.stdout);
/* SOURCE feq.for:1012 */
/*<       endif >*/
    }
/*     RESET OUTPUT */
/* SOURCE feq.for:1015 */
/*<       if(output.eq.0)output=1 >*/
    if (xscom_1.output == 0) {
	xscom_1.output = 1;
    }
/* SOURCE feq.for:1017 */
/*<       if(getdsn.gt.0)then >*/
    if (infcom_1.getdsn > 0) {
/* SOURCE feq.for:1018 */
/*<       isiter=siter >*/
	dtcom_1.isiter = dtcom_1.siter;
/*       OUTPUT CHECK VALUES FOR INITIAL CONDITIONS */
/* SOURCE feq.for:1020 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__135.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__135);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE feq.for:1021 */
/*<       write(stdout,*)' Initial values from GETIC file:',getnam >*/
	feq_gen_io_d__136.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__136);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Initial values from GETIC file:"), (ftnlen)32);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, namcom_1.getnam, (ftnlen)256);
	e_wsle();
/*       CLEAR QPVEC TO AVOID ERRONEOUS OUTPUT FOR THE INITIAL */
/*       CONDITIONS. Also clear the none-convergent node vectors */
/* SOURCE feq.for:1024 */
/*<       do9125i=1,nbn >*/
	feq_gen_i_d_1 = infcom_1.nbn;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1025 */
/*<       qpvec(i)=0.0 >*/
	    bnothr_1.qpvec[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1026 */
/*<       non_conv_bnode(i)=0 >*/
	    bnothr_1.feq_gen_non_conv_bnode_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE feq.for:1027 */
/*<  9125 continue >*/
/* L9125: */
	}
/* SOURCE feq.for:1028 */
/*<       do9120i=1,nex >*/
	feq_gen_i_d_1 = infcom_1.nex;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1029 */
/*<       non_conv_enode(i)=0 >*/
	    enothr_1.feq_gen_non_conv_enode_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE feq.for:1030 */
/*<  9120 continue >*/
/* L9120: */
	}
/* SOURCE feq.for:1031 */
/*<        >*/
	resout_(&gravcm_1.grav, &vunit, &xscom_1.stdout, &infcom_1.nbra, 
		nodeid, &infcom_1.nex, &xscom_1.time, &infcom_1.sfac, 
		infcom_1.brpt, infcom_1.exnodt, &infcom_1.qchop, &
		feq_gen_dz_for_output_d_, (ftnlen)4);
/* SOURCE feq.for:1034 */
/*<       else >*/
    } else {
/*       SET INITIAL PONDING TO ZERO WHEN INITIAL CONDITIONS ARE NOT */
/*       READ FROM A FILE.  CLEAR EXTRAPOLATION VECTORS.  Also clear */
/*       the count of exterior nodes appearing as the last items in */
/*       the iteration log when convergence fails. Clear the counter */
/*       for branch nodes as well. */
/* SOURCE feq.for:1041 */
/*<       do9124i=1,nbn >*/
	feq_gen_i_d_1 = infcom_1.nbn;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1042 */
/*<       my(i)=0.0 >*/
	    bnelem_1.my[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1043 */
/*<       mq(i)=0.0 >*/
	    bnelem_1.mq[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1044 */
/*<       pond1(i)=0.0 >*/
	    bnpond_1.pond1[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1045 */
/*<       non_conv_bnode(i)=0 >*/
	    bnothr_1.feq_gen_non_conv_bnode_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE feq.for:1046 */
/*<  9124 continue >*/
/* L9124: */
	}
/* SOURCE feq.for:1047 */
/*<       do9126i=1,nex >*/
	feq_gen_i_d_1 = infcom_1.nex;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1048 */
/*<       mye(i)=0.0 >*/
	    enelem_1.mye[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1049 */
/*<       mqe(i)=0.0 >*/
	    enelem_1.mqe[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1050 */
/*<       non_conv_enode(i)=0 >*/
	    enothr_1.feq_gen_non_conv_enode_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE feq.for:1051 */
/*<  9126 continue >*/
/* L9126: */
	}
/* SOURCE feq.for:1053 */
/*<       endif >*/
    }
/*     COMPUTE THE INITIALIZATION TIME */
/* SOURCE feq.for:1058 */
/*<       calltimerl(itick0) >*/
    timerl_(&timcom_1.itick0);
/* SOURCE feq.for:1059 */
/*<       if(itick0.lt.itick)then >*/
    if (timcom_1.itick0 < timcom_1.itick) {
/* SOURCE feq.for:1060 */
/*<       itick0=itick0+100*86400 >*/
	timcom_1.itick0 += 8640000;
/* SOURCE feq.for:1061 */
/*<       else >*/
    } else {
/* SOURCE feq.for:1062 */
/*<       et=float(itick0-itick)/100.0 >*/
	et = static_cast<double>((real) (timcom_1.itick0 - timcom_1.itick)) / (float)100.;
/* SOURCE feq.for:1063 */
/*<       write(stdout,3022)et,et/60. >*/
	feq_gen_io_d__139.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__139);
	do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE feq.for:1064 */
/*<       write(*,3023)et,et/60. >*/
	s_wsfe(&feq_gen_io_d__140);
	do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE feq.for:1065 */
/*<       write(*,*)' ' >*/
	s_wsle(&feq_gen_io_d__141);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE feq.for:1066 */
/*<       endif >*/
    }
/*     INITIALIZE FOR THIS SEGMENT OF TIME. MULTIPLE SEGMENTS IF */
/*     DIFFUS = YES.  FOR MULTIPLE SEGMENTS FORCE THE LINE COUNTER */
/*     FOR THE SPECIAL OUTPUT FILE TO BE CONTINUOUS ACROSS SEGMENTS */
/* SOURCE feq.for:1073 */
/*<       lkount=0 >*/
    lkount = 0;
/* SOURCE feq.for:1076 */
/*<  9000 continue >*/
L9000:
/* SOURCE feq.for:1077 */
/*<       reset=0 >*/
    julian_1.reset = 0;
/* SOURCE feq.for:1078 */
/*<       seflag=0 >*/
    tsfcom_1.seflag = 0;
/* SOURCE feq.for:1079 */
/*<       yr=syr >*/
    julian_1.yr = julian_1.syr;
/* SOURCE feq.for:1080 */
/*<       leap=lpyear(yr) >*/
    julian_1.leap = lpyear_(&julian_1.yr);
/* SOURCE feq.for:1081 */
/*<       mn=smn >*/
    julian_1.mn = julian_1.smn;
/* SOURCE feq.for:1082 */
/*<       dy=sdy >*/
    julian_1.dy = julian_1.sdy;
/*        DYFRAC = SFRAC/24.D0 */
/*        dyfrac = sfrac */
/* SOURCE feq.for:1085 */
/*<       hr=sngl(dyfrac*24.d0) >*/
    hr = (real) (julian_1.dyfrac * 24.);
/* SOURCE feq.for:1086 */
/*<       jtime=sjtime >*/
    julian_1.jtime = julian_1.sjtime;
/* SOURCE feq.for:1087 */
/*<       time=86400.d0*(sjtime-tab_789_jtbase) >*/
    xscom_1.time = (julian_1.sjtime - julian_1.feq_gen_tab_789_jtbase_d_) * 86400.;
/* SOURCE feq.for:1088 */
/*<       event_base=time >*/
    feq_gen_event_base_d_ = xscom_1.time;
/* SOURCE feq.for:1089 */
/*<       sumitr=0 >*/
    sumitr = 0;
/* SOURCE feq.for:1090 */
/*<       siter=isiter >*/
    dtcom_1.siter = dtcom_1.isiter;
/* SOURCE feq.for:1091 */
/*<       if(getdsn.eq.0)dt=maxdt >*/
    if (infcom_1.getdsn == 0) {
	dt = dtcom_1.maxdt;
    }
/* SOURCE feq.for:1092 */
/*<       bni=0.d0 >*/
    bni = 0.;
/* SOURCE feq.for:1093 */
/*<       bnq=0.d0 >*/
    bnq = 0.;
/* SOURCE feq.for:1094 */
/*<       tai=0.d0 >*/
    tai = 0.;
/* SOURCE feq.for:1095 */
/*<       taq=0.d0 >*/
    taq = 0.;
/* SOURCE feq.for:1096 */
/*<       taqbn=0.d0 >*/
    taqbn = 0.;
/*       Clear values used in BDYFLW even if there is no diffuse inflow */
/* SOURCE feq.for:1098 */
/*<       l_tai=0.d0 >*/
    tamcom_1.feq_gen_l_tai_d_ = 0.;
/* SOURCE feq.for:1099 */
/*<       l_taq=0.d0 >*/
    tamcom_1.feq_gen_l_taq_d_ = 0.;
/* SOURCE feq.for:1100 */
/*<       l_taqbn=0.d0 >*/
    tamcom_1.feq_gen_l_taqbn_d_ = 0.;
/* SOURCE feq.for:1101 */
/*<       l_wsi=0.d0 >*/
    tamcom_1.feq_gen_l_wsi_d_ = 0.;
/* SOURCE feq.for:1102 */
/*<       l_wsq=0.d0 >*/
    tamcom_1.feq_gen_l_wsq_d_ = 0.;
/*       WSI is the inflow to water surfaces from rainfall and WSQ is */
/*       outflow from water surfaces from evaporation. */
/* SOURCE feq.for:1105 */
/*<       wsi=0.d0 >*/
    wsi = 0.;
/* SOURCE feq.for:1106 */
/*<       wsq=0.d0 >*/
    wsq = 0.;
/* SOURCE feq.for:1107 */
/*<       lambda=1.0 >*/
    lambda = (float)1.;
/*       Start over with time-step checking */
/* SOURCE feq.for:1109 */
/*<       dot_flag=0 >*/
    feq_gen_dot_flag_d_ = 0;
/*     Reset the high iq ns factor to 1.0 for all unknowns */
/* SOURCE feq.for:1112 */
/*<       callreset_hi_iq_ns_fac() >*/
    feq_gen_reset_hi_iq_ns_fac_d_();
/*     Reset extreme values  and initialize various  values. */
/* SOURCE feq.for:1116 */
/*<       do1i=1,nbn >*/
    feq_gen_i_d_1 = infcom_1.nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1117 */
/*<       qpvec(i)=0. >*/
	bnothr_1.qpvec[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1118 */
/*<       wsvec(i)=0. >*/
	bnothr_1.wsvec[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1119 */
/*<       qmin(i)=1.e30 >*/
	bnrslt_1.qmin[feq_gen_i_d_ - 1] = (float)1e30;
/* SOURCE feq.for:1120 */
/*<       zmax(i)=-9999. >*/
	bnrslt_1.zmax[feq_gen_i_d_ - 1] = (float)-9999.;
/* SOURCE feq.for:1121 */
/*<       qmax(i)=-1.e30 >*/
	bnrslt_1.qmax[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE feq.for:1122 */
/*<       vmax(i)=-1.e30 >*/
	bnrslt_1.vmax[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE feq.for:1123 */
/*<       pond2(i)=0.0 >*/
	bnpond_1.pond2[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1124 */
/*<       tzmax(i)=sjtime >*/
	bnrslt_1.tzmax[feq_gen_i_d_ - 1] = julian_1.sjtime;
/* SOURCE feq.for:1125 */
/*<       tqmax(i)=sjtime >*/
	bnrslt_1.tqmax[feq_gen_i_d_ - 1] = julian_1.sjtime;
/* SOURCE feq.for:1126 */
/*<       tqmin(i)=sjtime >*/
	bnrslt_1.tqmin[feq_gen_i_d_ - 1] = julian_1.sjtime;
/* SOURCE feq.for:1127 */
/*<     1 continue >*/
/* L1: */
    }
/*     Initialize the values for any delay reservoirs if diffuse inflows */
/*     are simulated. Also initialize the values for any detention */
/*     reservoirs present. */
/* SOURCE feq.for:1132 */
/*<       if(nluse.gt.0.and.getdsn.eq.0)then >*/
    if (tsfcom_1.nluse > 0 && infcom_1.getdsn == 0) {
/* SOURCE feq.for:1133 */
/*<       do2i=1,dlay_knt >*/
	feq_gen_i_d_1 = tamcom_1.feq_gen_dlay_knt_d_;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1134 */
/*<       dlay_q1(i)=0.d0 >*/
	    tamcom_1.feq_gen_dlay_q1_d_[feq_gen_i_d_ - 1] = 0.;
/* SOURCE feq.for:1135 */
/*<     2 continue >*/
/* L2: */
	}
/* SOURCE feq.for:1136 */
/*<       do3i=1,dten_knt >*/
	feq_gen_i_d_1 = tamcom_1.feq_gen_dten_knt_d_;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1137 */
/*<       dten_s1(i)=0.0 >*/
	    tamcom_1.feq_gen_dten_s1_d_[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1138 */
/*<       dten_q1(i)=0.0 >*/
	    tamcom_1.feq_gen_dten_q1_d_[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1139 */
/*<       dten_q1p(i)=0.0 >*/
	    tamcom_1.feq_gen_dten_q1p_d_[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1140 */
/*<     3 continue >*/
/* L3: */
	}
/* SOURCE feq.for:1141 */
/*<       endif >*/
    }
/* SOURCE feq.for:1144 */
/*<       do4i=1,nbra >*/
    feq_gen_i_d_1 = infcom_1.nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1145 */
/*<       bpmax(i)=0.0 >*/
	bnpond_1.bpmax[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1146 */
/*<       bpond(i)=0.0 >*/
	bnpond_1.bpond[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE feq.for:1147 */
/*<     4 continue >*/
/* L4: */
    }
/* SOURCE feq.for:1148 */
/*<       do5i=1,nex >*/
    feq_gen_i_d_1 = infcom_1.nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1149 */
/*<       fnqmax(i)=-1.e30 >*/
	enrslt_1.fnqmax[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE feq.for:1150 */
/*<       fnqmin(i)=1.e30 >*/
	enrslt_1.fnqmin[feq_gen_i_d_ - 1] = (float)1e30;
/* SOURCE feq.for:1151 */
/*<       fnzmax(i)=-1.e30 >*/
	enrslt_1.fnzmax[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE feq.for:1152 */
/*<       ftzmax(i)=sjtime >*/
	enrslt_1.ftzmax[feq_gen_i_d_ - 1] = julian_1.sjtime;
/* SOURCE feq.for:1153 */
/*<       ftqmax(i)=sjtime >*/
	enrslt_1.ftqmax[feq_gen_i_d_ - 1] = julian_1.sjtime;
/* SOURCE feq.for:1154 */
/*<       ftqmin(i)=sjtime >*/
	enrslt_1.ftqmin[feq_gen_i_d_ - 1] = julian_1.sjtime;
/* SOURCE feq.for:1155 */
/*<     5 continue >*/
/* L5: */
    }
/*     Clear the initial value for cumulation of certain */
/*     time-series files.  We clear all even though none or */
/*     some need cumulative values.  Clear the new values */
/*     as well to avoid errors with checking undefined variables */
/* SOURCE feq.for:1161 */
/*<       do6i=1,num_ts_f >*/
    feq_gen_i_d_1 = rdcom_1.feq_gen_num_ts_f_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1162 */
/*<       old_cum(i)=0.d0 >*/
	rdcom_1.feq_gen_old_cum_d_[feq_gen_i_d_ - 1] = 0.;
/* SOURCE feq.for:1163 */
/*<       new_cum(i)=0.d0 >*/
	rdcom_1.feq_gen_new_cum_d_[feq_gen_i_d_ - 1] = 0.;
/* SOURCE feq.for:1164 */
/*<     6 continue >*/
/* L6: */
    }
/*     INITIALIZE THE SYSTEM. */
/*      IF(DIFFUS.EQ.YES) REWIND BWFDSN */
/* SOURCE feq.for:1168 */
/*<       if(ifrz.eq.0)then >*/
    if (infcom_1.ifrz == 0) {
/* SOURCE feq.for:1169 */
/*<       if(diffus.eq.yes)then >*/
	if (s_cmp(infcmc_1.diffus, yes, (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE feq.for:1170 */
/*<       if(getdsn+putdsn==0)then >*/
	    if (infcom_1.getdsn + infcom_1.putdsn == 0) {
/* SOURCE feq.for:1171 */
/*<       bwrec=1 >*/
		bwrec = 1;
/* SOURCE feq.for:1172 */
/*<       callbwget(bwfdsn,nbra,nbn,nex,mnblk,nblk,opblk,bwrec,wt) >*/
		bwget_(&infcom_1.bwfdsn, &infcom_1.nbra, &infcom_1.nbn, &
			infcom_1.nex, &feq_gen_c_d_100, &infcom_1.nblk, infcom_1.opblk,
			 &bwrec, &wt);
/* SOURCE feq.for:1176 */
/*<       write(stdout,*)' BWF BEING READ WHEN IFRZ=0. WT=',wt >*/
		feq_gen_io_d__156.ciunit = xscom_1.stdout;
		s_wsle(&feq_gen_io_d__156);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BWF BEING READ WHEN IFRZ=0. WT="), (
			ftnlen)32);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&wt, (ftnlen)sizeof(real));
		e_wsle();
/* SOURCE feq.for:1177 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1178 */
/*<       if(nblk.gt.0)then >*/
	    if (infcom_1.nblk > 0) {
/* SOURCE feq.for:1179 */
/*<       callopinit(nblk,opblk) >*/
		opinit_(&infcom_1.nblk, infcom_1.opblk);
/* SOURCE feq.for:1180 */
/*<       callset_initial_oper_blk(nblk,opblk,jtime,ept,emc) >*/
		feq_gen_set_initial_oper_blk_d_(&infcom_1.nblk, infcom_1.opblk, &
			julian_1.jtime, &infcom_1.ept, infcom_1.emc);
/* SOURCE feq.for:1182 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1183 */
/*<       endif >*/
	}
/* SOURCE feq.for:1184 */
/*<       callsetsta(stdout,nex,grav,exnodt,ept,emc) >*/
	setsta_(&xscom_1.stdout, &infcom_1.nex, &gravcm_1.grav, 
		infcom_1.exnodt, &infcom_1.ept, infcom_1.emc);
/*       COMPUTE INITIAL VOLUME OF WATER IN THE SYSTEM */
/* SOURCE feq.for:1191 */
/*<        >*/
	feq_gen_find_volumes_d_(&infcom_1.nbra, &infcom_1.nbn, &infcom_1.nex, &resnum, 
		&tamcom_1.feq_gen_dlay_knt_d_, &tamcom_1.feq_gen_dten_knt_d_, infcom_1.brpt, 
		enothr_1.resvec, bnelem_1.dxvec, bnelem_1.a1, enelem_1.ae1, 
		bnpond_1.pond1, bnothr_1.geqvec, bnelem_1.q1, bnelem_1.wxvec1,
		 bnelem_1.ma1, tamcom_1.feq_gen_dlay_q1_d_, tamcom_1.feq_gen_dlay_k_d_, 
		tamcom_1.feq_gen_dten_s1_d_, tamcom_1.feq_gen_dten_avda_d_, &s1, &d1);
/* SOURCE feq.for:1196 */
/*<       if(nfout.gt.0.and.ifrz==0)callwrinit(sjtime) >*/
	if (wrcom_1.nfout > 0 && infcom_1.ifrz == 0) {
	    wrinit_(&julian_1.sjtime);
	}
/*       CHECK THE INITIAL VALUES FOR EXTREMES */
/* SOURCE feq.for:1201 */
/*<       callfmxmn(nbn,nex,nbra,exnodt,brpt,jtime) >*/
	fmxmn_(&infcom_1.nbn, &infcom_1.nex, &infcom_1.nbra, infcom_1.exnodt, 
		infcom_1.brpt, &julian_1.jtime);
/*       Output the first record to the GENSCN system. */
/* SOURCE feq.for:1205 */
/*<       if(feo_unit.gt.0)then >*/
	if (genscn_1.feq_gen_feo_unit_d_ > 0) {
/* SOURCE feq.for:1206 */
/*<       callout_genscn(stdout,jtime,dz_for_output) >*/
	    feq_gen_out_genscn_d_(&xscom_1.stdout, &julian_1.jtime, &feq_gen_dz_for_output_d_);
/* SOURCE feq.for:1208 */
/*<       endif >*/
	}
/* SOURCE feq.for:1211 */
/*<       endif >*/
    }
/*     *************** SOLUTION SECTION **************************** */
/* SOURCE feq.for:1215 */
/*<       kount=0 >*/
    kount = 0;
/* SOURCE feq.for:1216 */
/*<       ntint=0 >*/
    ntint = 0;
/* SOURCE feq.for:1217 */
/*<       stflag=0 >*/
    bnelem_1.stflag = 0;
/*     SET CONVERGENCE FLAG TO YES AT START OF EACH SEGMENT OF TIME */
/* SOURCE feq.for:1220 */
/*<       cflag=1 >*/
    cflag = 1;
/*     SELECT NEXT TIME STEP AND INCREMENT TIME */
/* SOURCE feq.for:1224 */
/*<  8000 continue >*/
L8000:
/*       FORCE LARGE VALUE OF SRNEW TO PREVENT EARLY TERMINATION */
/* SOURCE feq.for:1228 */
/*<       srnew=1.e30 >*/
    srnew = (float)1e30;
/* SOURCE feq.for:1230 */
/*<        >*/
    mantim_(infcom_1.brpt, &infcom_1.bwfdsn, infcmc_1.diffus, &vunit, 
	    infcom_1.dtvec, infcom_1.exnodt, &infcom_1.nblk, &infcom_1.nbn, &
	    infcom_1.nbra, nodeid, &infcom_1.nex, infcom_1.opblk, &resnum, 
	    enothr_1.resvec, &infcom_1.sfac, &infcom_1.fffdsn, &minprt, &
	    hslot, &infcom_1.putdsn, &infcom_1.getdsn, &bnode, &
	    infcom_1.qchop, &bni, &bnq, &tai, &taq, &taqbn, &wsi, &wsq, 
	    feq_gen_old_summary_d_, &cflag, &dt, &dtdy, &infcom_1.ifrz, &wt, &
	    tsfcom_1.seflag, infcom_1.emc, &sumitr, &s1, &d1, &feq_gen_dt_adjust_d_, &
	    feq_gen_dz_for_output_d_, (ftnlen)4, (ftnlen)4, (ftnlen)4);
/* SOURCE feq.for:1238 */
/*<       if(dt_adjust.eq.0)then >*/
    if (feq_gen_dt_adjust_d_ == 0) {
/* SOURCE feq.for:1239 */
/*<       min_time_step=min(min_time_step,real(dt)) >*/
/* Computing MIN */
	feq_gen_r_d_1 = timcom_1.feq_gen_min_time_step_d_, feq_gen_r_d_2 = (real) dt;
	timcom_1.feq_gen_min_time_step_d_ = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE feq.for:1240 */
/*<       endif >*/
    }
/*       CATCH END OF SEGMENT IN TSF. RESET = 0 ALWAYS IF NO TSF */
/*       SET TO 1 TO SIGNAL END OF A SEGMENT IF TSF IS PRESENT. */
/* SOURCE feq.for:1245 */
/*<       if(reset.eq.1)goto9000 >*/
    if (julian_1.reset == 1) {
	goto L9000;
    }
/*       TIME STEP SELECTED AND MORE TIME REMAINS TO BE DONE */
/*       FIND VALUES DETERMINED FULLY BY THE TIME. */
/* SOURCE feq.for:1250 */
/*<       if(jtime.gt.prtime)then >*/
    if (julian_1.jtime > julian_1.prtime) {
/* SOURCE feq.for:1251 */
/*<       output=prout >*/
	xscom_1.output = xscom_1.prout;
/* SOURCE feq.for:1252 */
/*<       endif >*/
    }
/* SOURCE feq.for:1253 */
/*<       if(nblk.gt.0)then >*/
    if (infcom_1.nblk > 0) {
/* SOURCE feq.for:1254 */
/*<       if(ifrz.eq.0)then >*/
	if (infcom_1.ifrz == 0) {
/* SOURCE feq.for:1255 */
/*<       dthr=dt/3600. >*/
	    dthr = dt / (float)3600.;
/* SOURCE feq.for:1256 */
/*<       else >*/
	} else {
/* SOURCE feq.for:1257 */
/*<       dthr=0.0 >*/
	    dthr = (float)0.;
/* SOURCE feq.for:1258 */
/*<       endif >*/
	}
/* SOURCE feq.for:1259 */
/*<       calloper(jtime,nblk,opblk,dthr,emc) >*/
	oper_(&julian_1.jtime, &infcom_1.nblk, infcom_1.opblk, &dthr, 
		infcom_1.emc);
/* SOURCE feq.for:1261 */
/*<       endif >*/
    }
/* SOURCE feq.for:1264 */
/*<       if(ldcall.gt.0)then >*/
    if (ldcall > 0) {
/* SOURCE feq.for:1266 */
/*<       if(ifrz.gt.0)then >*/
	if (infcom_1.ifrz > 0) {
/*           During frozen time, do lookup in the diffuse inflows with an offset of */
/*           1 second to avoid possible roundoff problems in actually getting the very */
/*           first time point in a diffuse-flow file if the user should start there. */
/*           We also set the time step to 1 second. */
/* SOURCE feq.for:1271 */
/*<       dtload=1.d0 >*/
	    dtload = 1.;
/* SOURCE feq.for:1272 */
/*<       djload=1.157407d-5 >*/
	    djload = 1.157407e-5;
/* SOURCE feq.for:1273 */
/*<       dtdyload=1.157407e-5 >*/
	    dtdyload = (float)1.157407e-5;
/* SOURCE feq.for:1274 */
/*<       else >*/
	} else {
/* SOURCE feq.for:1275 */
/*<       dtload=dt >*/
	    dtload = dt;
/* SOURCE feq.for:1276 */
/*<       djload=0.d0 >*/
	    djload = 0.;
/* SOURCE feq.for:1277 */
/*<       dtdyload=dtdy >*/
	    dtdyload = dtdy;
/* SOURCE feq.for:1278 */
/*<       endif >*/
	}
/* SOURCE feq.for:1280 */
/*<        >*/
	load_(infcmc_1.diffus, infcom_1.brpt, &infcom_1.nbra, &xscom_1.stdout,
		 &infcom_1.lpnt, &feq_gen_c_d_3, &infcom_1.nbn, &xscom_1.output, 
		infcmc_1.point, infcmc_1.wind, infcom_1.pfpnt, &qpn, &dt, &
		dtdy, &dtload, &dtdyload, &djload, infcom_1.emc, &
		xscom_1.eflag, &wyr, (ftnlen)4, (ftnlen)4, (ftnlen)4);
/* SOURCE feq.for:1287 */
/*<       endif >*/
    }
/* SOURCE feq.for:1289 */
/*<       if(geqopt.eq.2)then >*/
    if (bnothr_1.geqopt == 2) {
/*         RESET THE WEIGHT FACTORS FOR DISTANCE INTEGRALS */
/* SOURCE feq.for:1291 */
/*<       callrstnzd(nbra,brpt) >*/
	rstnzd_(&infcom_1.nbra, infcom_1.brpt);
/* SOURCE feq.for:1293 */
/*<       endif >*/
    }
/*       MAKE ESTIMATE OF DEPENDENT VARIABLES FOR NODES ON BRANCH */
/* SOURCE feq.for:1297 */
/*<       callestbn(dt,nbn,mre) >*/
    estbn_(&dt, &infcom_1.nbn, &infcom_1.mre);
/*       MAKE ESTIMATE OF DEPENDENT VARIABLES FOR EXTERIOR NODES */
/* SOURCE feq.for:1302 */
/*<       callesten(dt,nex,mre,exnodt) >*/
    esten_(&dt, &infcom_1.nex, &infcom_1.mre, infcom_1.exnodt);
/*       COMPUTE  MATRIX, UPDATE SROLD, AND SOLVE MATRIX */
/*        write(stdout,*) 'Dump initial values for current time step' */
/*        do i=1,nbn */
/*          write(stdout,'(i6,f12.3,1pe12.5)') i, y2(i), q2(i) */
/*        enddo */
/*        do i=1,nex */
/*          write(stdout,'(i6,f12.3,1pe12.5)') i, ye2(i), qe2(i) */
/*        enddo */
/* SOURCE feq.for:1317 */
/*<       lambda=1.0 >*/
    lambda = (float)1.;
/* SOURCE feq.for:1318 */
/*<       kount=0 >*/
    kount = 0;
/* SOURCE feq.for:1320 */
/*<        >*/
    csmat_(&dt, &dtdy, &wt, &infcom_1.nbn, &infcom_1.nbra, &infcom_1.nex, 
	    infcom_1.brpt, &hslot, &infcom_1.ept, &feq_gen_dtmin_out_d_, &feq_gen_start_eq_d_, &
	    feq_gen_end_eq_d_, &julian_1.jtime, &julian_1.prtime, &kount, &
	    infcom_1.qeps, infcom_1.emc, infcom_1.exnodt, &srold, &mxres, &
	    lmxres, &errp, &errq, &berrq, &nerrq, &nerrp, &berrp);
/*       INITIALIZE FOR ITERATIVE SOLUTION FOR CURRENT TIME POINT. */
/* SOURCE feq.for:1330 */
/*<       mxssrv(kount+1)=srold >*/
    mxssrv[kount] = srold;
/* SOURCE feq.for:1331 */
/*<       mxrv(kount+1)=mxres >*/
    mxrv[kount] = mxres;
/* SOURCE feq.for:1332 */
/*<       lmxrv(kount+1)=lmxres >*/
    lmxrv[kount] = lmxres;
/* SOURCE feq.for:1334 */
/*<  8200 continue >*/
L8200:
/* SOURCE feq.for:1336 */
/*<       kount=kount+1 >*/
    ++kount;
/* SOURCE feq.for:1337 */
/*<       stflag=1 >*/
    bnelem_1.stflag = 1;
/* SOURCE feq.for:1338 */
/*<       if(kount.gt.mknt)then >*/
    if (kount > infcom_1.mknt) {
/* SOURCE feq.for:1339 */
/*<       cflag=0 >*/
	cflag = 0;
/* SOURCE feq.for:1340 */
/*<       stflag=0 >*/
	bnelem_1.stflag = 0;
/* SOURCE feq.for:1341 */
/*<       kount=kount-1 >*/
	--kount;
/* SOURCE feq.for:1342 */
/*<       if(minprt.eq.0.or.minprt.eq.2)then >*/
	if (minprt == 0 || minprt == 2) {
/* SOURCE feq.for:1343 */
/*<       hrd=24.*dyfrac >*/
	    hrd = julian_1.dyfrac * (float)24.;
/* SOURCE feq.for:1344 */
/*<       hr=hrd >*/
	    hr = hrd;
/* SOURCE feq.for:1345 */
/*<       write(stdout,2030) >*/
	    feq_gen_io_d__182.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__182);
	    e_wsfe();
/* SOURCE feq.for:1346 */
/*<       write(stdout,2020)yr,mn,dy,hrd,dt >*/
	    feq_gen_io_d__183.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__183);
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&hrd, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&dt, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE feq.for:1347 */
/*<        >*/
	    prtlog_(&xscom_1.stdout, &kount, mxrev, bmxrev, nmxrev, mxrv, 
		    lmxrv, mxssrv, kntvec, ivarv);
/* SOURCE feq.for:1350 */
/*<       endif >*/
	}
/*           Count the exterior nodes, if any, that appear as */
/*           the last location of maximum relative correction */
/*           when convergence fails. */
/* SOURCE feq.for:1355 */
/*<       if(bmxrev(kount).eq.0)then >*/
	if (bmxrev[kount - 1] == 0) {
/* SOURCE feq.for:1356 */
/*<        >*/
	    enothr_1.feq_gen_non_conv_enode_d_[(feq_gen_i_d_1 = nmxrev[kount - 1], abs(feq_gen_i_d_1)) - 
		    1] = enothr_1.feq_gen_non_conv_enode_d_[(feq_gen_i_d_2 = nmxrev[kount - 1], 
		    abs(feq_gen_i_d_2)) - 1] + 1;
/* SOURCE feq.for:1358 */
/*<       else >*/
	} else {
/* SOURCE feq.for:1359 */
/*<       non_conv_bnode(bnode_max)=non_conv_bnode(bnode_max)+1 >*/
	    ++bnothr_1.feq_gen_non_conv_bnode_d_[feq_gen_bnode_max_d_ - 1];
/* SOURCE feq.for:1361 */
/*<       endif >*/
	}
/* SOURCE feq.for:1363 */
/*<       siter=auto*siter+(1.-auto)*kount >*/
	dtcom_1.siter = static_cast<double>(static_cast<double>(dtcom_1.feq_gen_auto_d_) * dtcom_1.siter) + static_cast<double>((static_cast<double>((float)1.) - 
		dtcom_1.feq_gen_auto_d_)) * kount;
/* SOURCE feq.for:1364 */
/*<       sumitr=sumitr+kount >*/
	sumitr += kount;
/* SOURCE feq.for:1365 */
/*<       if(minprt.eq.0)then >*/
	if (minprt == 0) {
/* SOURCE feq.for:1366 */
/*<       if(berrp.eq.0)then >*/
	    if (berrp == 0) {
/* SOURCE feq.for:1367 */
/*<       ibp=0 >*/
		ibp = 0;
/* SOURCE feq.for:1368 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:1369 */
/*<       ibp=inbrus(berrp) >*/
		ibp = inbr_1.inbrus[berrp - 1];
/* SOURCE feq.for:1370 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1371 */
/*<       if(berrq.eq.0)then >*/
	    if (berrq == 0) {
/* SOURCE feq.for:1372 */
/*<       ibq=0 >*/
		ibq = 0;
/* SOURCE feq.for:1373 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:1374 */
/*<       ibq=inbrus(berrq) >*/
		ibq = inbr_1.inbrus[berrq - 1];
/* SOURCE feq.for:1375 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1376 */
/*<        >*/
	    feq_gen_io_d__192.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__192);
	    do_fio(&feq_gen_c_d_1, (char *)&errp, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ibp, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nerrp, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&errq, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ibq, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nerrq, (ftnlen)sizeof(integer));
	    feq_gen_d_d_1 = (xscom_1.time - feq_gen_event_base_d_) / (real) sumitr;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&sumitr, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE feq.for:1380 */
/*<       endif >*/
	}
/*           Make adjustments to HI_IQ_NS_FAC based on the variables that */
/*           appeared in the iteration log.  We did not get convergence. */
/* SOURCE feq.for:1384 */
/*<       if(hi_iq_ns.ne.'NO')then >*/
	if (s_cmp(feq_gen_hi_iq_ns_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) != 0) {
/* SOURCE feq.for:1385 */
/*<        >*/
	    feq_gen_hi_iq_ns_fail_d_(&xscom_1.stdout, &kount, mxrev, ivarv, kntvec, &
		    feq_gen_hi_iq_ns_dwn_d_, &feq_gen_hi_iq_ns_lmt_d_, feq_gen_hi_iq_ns_d_, &
		    feq_gen_hi_iq_ns_numgt_d_, matcom_1.feq_gen_hi_iq_ns_state_d_, 
		    matcom_1.feq_gen_hi_iq_ns_fac_d_, &xscom_1.eflag, (ftnlen)4);
/* SOURCE feq.for:1392 */
/*<       if(eflag.eq.1)then >*/
	    if (xscom_1.eflag == 1) {
/* SOURCE feq.for:1393 */
/*<       write(stdout,*)' hi_iq_ns list has overflowed!' >*/
		feq_gen_io_d__193.ciunit = xscom_1.stdout;
		s_wsle(&feq_gen_io_d__193);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" hi_iq_ns list has overflowed!"), (
			ftnlen)30);
		e_wsle();
/* SOURCE feq.for:1394 */
/*<       stop'Abnormal stop' >*/
		s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE feq.for:1395 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1396 */
/*<       endif >*/
	}
/* SOURCE feq.for:1398 */
/*<       goto8000 >*/
	goto L8000;
/* SOURCE feq.for:1399 */
/*<       endif >*/
    }
/*         COMPUTE CORRECTIONS AND SAVE IN ENCORY(*), ENCORQ(*), */
/*         BNCORY(*), AND BNCORQ(*) */
/* SOURCE feq.for:1406 */
/*<        >*/
    cmpcor_(&infcom_1.nbra, &infcom_1.nex, infcom_1.brpt, infcom_1.exnodt, &
	    infcom_1.qeps, &infcom_1.epssys, &infcom_1.epssy2, &abstol, &mxre,
	     &bmxre, &nmxre, &ivar, &knt, &knta, &feq_gen_bnode_max_d_);
/* SOURCE feq.for:1411 */
/*<       mxrev(kount)=mxre >*/
    mxrev[kount - 1] = mxre;
/* SOURCE feq.for:1412 */
/*<       bmxrev(kount)=bmxre >*/
    bmxrev[kount - 1] = bmxre;
/* SOURCE feq.for:1413 */
/*<       nmxrev(kount)=nmxre >*/
    nmxrev[kount - 1] = nmxre;
/* SOURCE feq.for:1414 */
/*<       ivarv(kount)=ivar >*/
    ivarv[kount - 1] = ivar;
/* SOURCE feq.for:1415 */
/*<       kntvec(kount)=knt >*/
    kntvec[kount - 1] = knt;
/*         SAVE SET2 IN SET3 */
/* SOURCE feq.for:1421 */
/*<       do303i=1,nbn >*/
    feq_gen_i_d_1 = infcom_1.nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1422 */
/*<       y3(i)=y2(i) >*/
	bnelem_1.y3[feq_gen_i_d_ - 1] = bnelem_1.y2[feq_gen_i_d_ - 1];
/* SOURCE feq.for:1423 */
/*<       q3(i)=q2(i) >*/
	bnelem_1.q3[feq_gen_i_d_ - 1] = bnelem_1.q2[feq_gen_i_d_ - 1];
/* SOURCE feq.for:1424 */
/*<   303 continue >*/
/* L303: */
    }
/* SOURCE feq.for:1425 */
/*<       do307i=1,nex >*/
    feq_gen_i_d_1 = infcom_1.nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1426 */
/*<       ye3(i)=ye2(i) >*/
	enelem_1.ye3[feq_gen_i_d_ - 1] = enelem_1.ye2[feq_gen_i_d_ - 1];
/* SOURCE feq.for:1427 */
/*<       qe3(i)=qe2(i) >*/
	enelem_1.qe3[feq_gen_i_d_ - 1] = enelem_1.qe2[feq_gen_i_d_ - 1];
/* SOURCE feq.for:1428 */
/*<   307 continue >*/
/* L307: */
    }
/*         APPLY A FRACTION OF THE CORRECTION. */
/* SOURCE feq.for:1432 */
/*<  8400 continue >*/
L8400:
/* SOURCE feq.for:1434 */
/*<       callmakcor(nex,nbra,nbn,stdout,exnodt,brpt,lambda,qchop) >*/
    makcor_(&infcom_1.nex, &infcom_1.nbra, &infcom_1.nbn, &xscom_1.stdout, 
	    infcom_1.exnodt, infcom_1.brpt, &lambda, &infcom_1.qchop);
/* SOURCE feq.for:1438 */
/*<        >*/
    if (xscom_1.output > 2) {
	dumpit_(&mxre, &infcom_1.qeps, &kount, &xscom_1.stdout, &
		infcom_1.nbra, &infcom_1.nex, infcom_1.brpt, infcom_1.exnodt);
    }
/*           CHECK FOR CONVERGENCE */
/* SOURCE feq.for:1445 */
/*<       if(geqopt.ge.1)then >*/
    if (bnothr_1.geqopt >= 1) {
/* SOURCE feq.for:1446 */
/*<       if(knta.eq.0)then >*/
	if (knta == 0) {
/* SOURCE feq.for:1447 */
/*<       itemp=knt >*/
	    itemp = knt;
/* SOURCE feq.for:1448 */
/*<       else >*/
	} else {
/* SOURCE feq.for:1449 */
/*<       itemp=1000000 >*/
	    itemp = 1000000;
/* SOURCE feq.for:1450 */
/*<       endif >*/
	}
/* SOURCE feq.for:1451 */
/*<       else >*/
    } else {
/* SOURCE feq.for:1452 */
/*<       itemp=1000000 >*/
	itemp = 1000000;
/* SOURCE feq.for:1453 */
/*<       endif >*/
    }
/* SOURCE feq.for:1454 */
/*<        >*/
    if (mxre < infcom_1.epssys && errp < xscom_1.sseps || itemp <= numlim && 
	    errp < xscom_1.sseps) {
/*             CONVERGENCE */
/* SOURCE feq.for:1459 */
/*<       cflag=1 >*/
	cflag = 1;
/* SOURCE feq.for:1460 */
/*<       stflag=0 >*/
	bnelem_1.stflag = 0;
/* SOURCE feq.for:1462 */
/*<       ntint=ntint+1 >*/
	++ntint;
/* SOURCE feq.for:1463 */
/*<       if(mod(ntint,prtint).eq.0)then >*/
	if (ntint % infcom_1.prtint == 0) {
/* SOURCE feq.for:1464 */
/*<       iprt=1 >*/
	    iprt = 1;
/* SOURCE feq.for:1465 */
/*<       else >*/
	} else {
/* SOURCE feq.for:1466 */
/*<       iprt=0 >*/
	    iprt = 0;
/* SOURCE feq.for:1467 */
/*<       endif >*/
	}
/*             COMPUTE REMAINDER OF SET2 */
/* SOURCE feq.for:1472 */
/*<       callcrset2(nbra,nex,brpt,exnodt) >*/
	crset2_(&infcom_1.nbra, &infcom_1.nex, infcom_1.brpt, infcom_1.exnodt)
		;
/*             UPDATE THE RUNNING ITERATION VALUE */
/* SOURCE feq.for:1479 */
/*<       siter=auto*siter+(1.-auto)*kount >*/
	dtcom_1.siter = static_cast<double>(static_cast<double>(dtcom_1.feq_gen_auto_d_) * dtcom_1.siter) + static_cast<double>((static_cast<double>((float)1.) - 
		dtcom_1.feq_gen_auto_d_)) * kount;
/*             UPDATE CUMULATIVE ITERATION COUNT */
/* SOURCE feq.for:1483 */
/*<       sumitr=sumitr+kount >*/
	sumitr += kount;
/*             COMPUTE THE CUMULATIVE FLOW AT SYSTEM BOUNDARIES */
/* SOURCE feq.for:1487 */
/*<       if(ifrz.eq.0)then >*/
	if (infcom_1.ifrz == 0) {
/* SOURCE feq.for:1488 */
/*<        >*/
	    bdyflw_(&bdynum, &dt, infcom_1.exnodt, &infcom_1.nex, 
		    enelem_1.qe1, enelem_1.qe2, &wt, enothr_1.bdyvec, &bni, &
		    bnq, &tai, &taq, &taqbn, &wsi, &wsq);
/* SOURCE feq.for:1492 */
/*<       endif >*/
	}
/*             WRITE TO ANY OUTPUT FILES OPEN */
/* SOURCE feq.for:1496 */
/*<        >*/
	if (infcom_1.ifrz == 0 && wrcom_1.nfout > 0) {
	    wrout_(&julian_1.jtime, &xscom_1.stdout, &infcom_1.qchop, &dt, &
		    feq_gen_dz_for_output_d_);
	}
/*             UPDATE OPERATION BLOCKS WITH THE OLD SET 1 VALUES */
/* SOURCE feq.for:1502 */
/*<       if(nblk.gt.0)callopinit(nblk,opblk) >*/
	if (infcom_1.nblk > 0) {
	    opinit_(&infcom_1.nblk, infcom_1.opblk);
	}
/*             REPLACE SET 1 VALUES WITH SET 2 VALUES FOR NEXT TIME STEP */
/* SOURCE feq.for:1507 */
/*<       callrplset(dt,fac,nbn,nex) >*/
	rplset_(&dt, &infcom_1.fac, &infcom_1.nbn, &infcom_1.nex);
/*             UPDATE FLOW STATE VALUES */
/* SOURCE feq.for:1512 */
/*<       callrststa(2,stdout,emc) >*/
	rststa_(&feq_gen_c_d_2, &xscom_1.stdout, infcom_1.emc);
/*              Update the delay  and detention reservoirs. */
/* SOURCE feq.for:1517 */
/*<       if(nluse.gt.0)then >*/
	if (tsfcom_1.nluse > 0) {
/* SOURCE feq.for:1518 */
/*<       do223j=1,dlay_knt >*/
	    feq_gen_i_d_1 = tamcom_1.feq_gen_dlay_knt_d_;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE feq.for:1519 */
/*<       dlay_q1(j)=dlay_q2(j) >*/
		tamcom_1.feq_gen_dlay_q1_d_[j - 1] = tamcom_1.feq_gen_dlay_q2_d_[j - 1];
/* SOURCE feq.for:1520 */
/*<   223 continue >*/
/* L223: */
	    }
/* SOURCE feq.for:1521 */
/*<       do224j=1,dten_knt >*/
	    feq_gen_i_d_1 = tamcom_1.feq_gen_dten_knt_d_;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE feq.for:1522 */
/*<       dten_q1(j)=dten_q2(j) >*/
		tamcom_1.feq_gen_dten_q1_d_[j - 1] = tamcom_1.feq_gen_dten_q2_d_[j - 1];
/* SOURCE feq.for:1523 */
/*<       dten_q1p(j)=dten_q2p(j) >*/
		tamcom_1.feq_gen_dten_q1p_d_[j - 1] = tamcom_1.feq_gen_dten_q2p_d_[j - 1];
/* SOURCE feq.for:1524 */
/*<       dten_s1(j)=dten_s2(j) >*/
		tamcom_1.feq_gen_dten_s1_d_[j - 1] = tamcom_1.feq_gen_dten_s2_d_[j - 1];
/* SOURCE feq.for:1525 */
/*<   224 continue >*/
/* L224: */
	    }
/* SOURCE feq.for:1527 */
/*<       endif >*/
	}
/*              Diffuse flow cumulative values */
/* SOURCE feq.for:1529 */
/*<       if(ifrz.eq.0)then >*/
	if (infcom_1.ifrz == 0) {
/* SOURCE feq.for:1530 */
/*<       do225j=1,nluse >*/
	    feq_gen_i_d_1 = tsfcom_1.nluse;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE feq.for:1531 */
/*<       clsr1(j)=clsr2(j) >*/
		difcom_1.clsr1[j - 1] = difcom_1.clsr2[j - 1];
/* SOURCE feq.for:1532 */
/*<   225 continue >*/
/* L225: */
	    }
/*              Time series files that involve cumulative values. */
/*              We do them all-even though only some or none need */
/*              cumulative values */
/* SOURCE feq.for:1538 */
/*<       do226j=1,num_ts_f >*/
	    feq_gen_i_d_1 = rdcom_1.feq_gen_num_ts_f_d_;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE feq.for:1539 */
/*<       old_cum(j)=new_cum(j) >*/
		rdcom_1.feq_gen_old_cum_d_[j - 1] = rdcom_1.feq_gen_new_cum_d_[j - 1];
/* SOURCE feq.for:1540 */
/*<   226 continue >*/
/* L226: */
	    }
/* SOURCE feq.for:1541 */
/*<       endif >*/
	}
/*              FIND MAXIMUM AND MINIMUM FLOWS AND DEPTHS(ELEVATIONS) */
/* SOURCE feq.for:1545 */
/*<       if(ifrz.le.1)callfmxmn(nbn,nex,nbra,exnodt,brpt,jtime) >*/
	if (infcom_1.ifrz <= 1) {
	    fmxmn_(&infcom_1.nbn, &infcom_1.nex, &infcom_1.nbra, 
		    infcom_1.exnodt, infcom_1.brpt, &julian_1.jtime);
	}
/*              Output to time-step file if active */
/* SOURCE feq.for:1551 */
/*<       if(stddtout.gt.0)then >*/
	if (timetab_1.stddtout > 0) {
/* SOURCE feq.for:1552 */
/*<       callupdate_time_step_tab(stddtout,jtime,dt) >*/
	    feq_gen_update_time_step_tab_d_(&timetab_1.stddtout, &julian_1.jtime, &dt);
/* SOURCE feq.for:1554 */
/*<       endif >*/
	}
/*              PRINT OUT RESULTS */
/* SOURCE feq.for:1559 */
/*<       hrd=24.*dyfrac >*/
	hrd = julian_1.dyfrac * (float)24.;
/* SOURCE feq.for:1560 */
/*<       hr=hrd >*/
	hr = hrd;
/* SOURCE feq.for:1561 */
/*<       if(output.gt.2)write(stdout,2010) >*/
	if (xscom_1.output > 2) {
	    feq_gen_io_d__202.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__202);
	    e_wsfe();
	}
/* SOURCE feq.for:1562 */
/*<       if(minprt.eq.0)then >*/
	if (minprt == 0) {
/* SOURCE feq.for:1563 */
/*<       write(stdout,2020)yr,mn,dy,hrd,dt >*/
	    feq_gen_io_d__203.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__203);
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&hrd, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&dt, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE feq.for:1564 */
/*<       if(last_dt_to_console.ne.dt)then >*/
	    if (feq_gen_last_dt_to_console_d_ != dt) {
/* SOURCE feq.for:1565 */
/*<       if(dot_flag.eq.1)then >*/
		if (feq_gen_dot_flag_d_ == 1) {
/* SOURCE feq.for:1566 */
/*<       write(*,'(a1)')' ' >*/
		    feq_gen_ci_d_1.cierr = 0;
		    feq_gen_ci_d_1.ciunit = 6;
		    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a1)");
		    s_wsfe(&feq_gen_ci_d_1);
		    do_fio(&feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
		    e_wsfe();
/* SOURCE feq.for:1567 */
/*<       endif >*/
		}
/* SOURCE feq.for:1568 */
/*<       write(*,2021)yr,mn,dy,hr,dt >*/
		s_wsfe(&feq_gen_io_d__204);
		do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&dt, (ftnlen)sizeof(doublereal));
		e_wsfe();
/* SOURCE feq.for:1569 */
/*<       last_dt_to_console=dt >*/
		feq_gen_last_dt_to_console_d_ = dt;
/* SOURCE feq.for:1570 */
/*<       dot_flag=0 >*/
		feq_gen_dot_flag_d_ = 0;
/* SOURCE feq.for:1571 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:1572 */
/*<       write(*,'(a1,$)')'.' >*/
		feq_gen_ci_d_1.cierr = 0;
		feq_gen_ci_d_1.ciunit = 6;
		feq_gen_ci_d_1.cifmt = const_cast<char*>("(a1,$)");
		s_wsfe(&feq_gen_ci_d_1);
		do_fio(&feq_gen_c_d_1, const_cast<char*>("."), (ftnlen)1);
		e_wsfe();
/* SOURCE feq.for:1573 */
/*<       dot_flag=1 >*/
		feq_gen_dot_flag_d_ = 1;
/* SOURCE feq.for:1574 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1575 */
/*<        >*/
	    prtlog_(&xscom_1.stdout, &kount, mxrev, bmxrev, nmxrev, mxrv, 
		    lmxrv, mxssrv, kntvec, ivarv);
/* SOURCE feq.for:1578 */
/*<       if(berrp.eq.0)then >*/
	    if (berrp == 0) {
/* SOURCE feq.for:1579 */
/*<       ibp=0 >*/
		ibp = 0;
/* SOURCE feq.for:1580 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:1581 */
/*<       ibp=inbrus(berrp) >*/
		ibp = inbr_1.inbrus[berrp - 1];
/* SOURCE feq.for:1582 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1583 */
/*<       if(berrq.eq.0)then >*/
	    if (berrq == 0) {
/* SOURCE feq.for:1584 */
/*<       ibq=0 >*/
		ibq = 0;
/* SOURCE feq.for:1585 */
/*<       else >*/
	    } else {
/* SOURCE feq.for:1586 */
/*<       ibq=inbrus(berrq) >*/
		ibq = inbr_1.inbrus[berrq - 1];
/* SOURCE feq.for:1587 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1588 */
/*<        >*/
	    feq_gen_io_d__205.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__205);
	    do_fio(&feq_gen_c_d_1, (char *)&errp, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ibp, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nerrp, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&errq, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ibq, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nerrq, (ftnlen)sizeof(integer));
	    feq_gen_d_d_1 = (xscom_1.time - feq_gen_event_base_d_) / (real) sumitr;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&sumitr, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE feq.for:1592 */
/*<       endif >*/
	}
/* SOURCE feq.for:1593 */
/*<        >*/
	if (iprt == 1 || julian_1.jtime > julian_1.prtime || dt < feq_gen_dtmin_out_d_)
		 {
	    resout_(&gravcm_1.grav, &vunit, &xscom_1.stdout, &infcom_1.nbra, 
		    nodeid, &infcom_1.nex, &xscom_1.time, &infcom_1.sfac, 
		    infcom_1.brpt, infcom_1.exnodt, &infcom_1.qchop, &
		    feq_gen_dz_for_output_d_, (ftnlen)4);
	}
/* SOURCE feq.for:1598 */
/*<       if(ifrz.eq.0)then >*/
	if (infcom_1.ifrz == 0) {
/* SOURCE feq.for:1600 */
/*<       if(iprt.eq.1.or.jtime.gt.prtime.or.dt.lt.dtmin_out)then >*/
	    if (iprt == 1 || julian_1.jtime > julian_1.prtime || dt < 
		    feq_gen_dtmin_out_d_) {
/*                  COMPUTE FINAL VOLUME AND OUTPUT SUMMARY FOR TIME STEP */
/* SOURCE feq.for:1603 */
/*<        >*/
		feq_gen_find_volumes_d_(&infcom_1.nbra, &infcom_1.nbn, &infcom_1.nex, &
			resnum, &tamcom_1.feq_gen_dlay_knt_d_, &tamcom_1.feq_gen_dten_knt_d_, 
			infcom_1.brpt, enothr_1.resvec, bnelem_1.dxvec, 
			bnelem_1.a2, enelem_1.ae2, bnpond_1.pond2, 
			bnothr_1.geqvec, bnelem_1.q2, bnelem_1.wxvec2, 
			bnelem_1.ma2, tamcom_1.feq_gen_dlay_q2_d_, tamcom_1.feq_gen_dlay_k_d_, 
			tamcom_1.feq_gen_dten_s2_d_, tamcom_1.feq_gen_dten_avda_d_, &s2, &d2);
/* SOURCE feq.for:1609 */
/*<       bal=s2+bnq+wsq-(s1+bni+taq+wsi) >*/
		bal = s2 + bnq + wsq - (s1 + bni + taq + wsi);
/* SOURCE feq.for:1611 */
/*<       rbal=bal/(s2+bnq) >*/
		rbal = bal / (s2 + bnq);
/* SOURCE feq.for:1612 */
/*<       write(stdout,2150)s1,s2,bni,bnq,taq,wsi,wsq >*/
		feq_gen_io_d__210.ciunit = xscom_1.stdout;
		s_wsfe(&feq_gen_io_d__210);
		do_fio(&feq_gen_c_d_1, (char *)&s1, (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&s2, (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&bni, (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&bnq, (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&taq, (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&wsi, (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&wsq, (ftnlen)sizeof(doublereal));
		e_wsfe();
/* SOURCE feq.for:1613 */
/*<       write(stdout,2152)bal,rbal >*/
		feq_gen_io_d__211.ciunit = xscom_1.stdout;
		s_wsfe(&feq_gen_io_d__211);
		do_fio(&feq_gen_c_d_1, (char *)&bal, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&rbal, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE feq.for:1614 */
/*<       if(diffus.ne.no)then >*/
		if (s_cmp(infcmc_1.diffus, no, (ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE feq.for:1615 */
/*<       write(stdout,2153)d1,d2,tai,taqbn >*/
		    feq_gen_io_d__212.ciunit = xscom_1.stdout;
		    s_wsfe(&feq_gen_io_d__212);
		    do_fio(&feq_gen_c_d_1, (char *)&d1, (ftnlen)sizeof(doublereal));
		    do_fio(&feq_gen_c_d_1, (char *)&d2, (ftnlen)sizeof(doublereal));
		    do_fio(&feq_gen_c_d_1, (char *)&tai, (ftnlen)sizeof(doublereal));
		    do_fio(&feq_gen_c_d_1, (char *)&taqbn, (ftnlen)sizeof(doublereal));
		    e_wsfe();
/* SOURCE feq.for:1616 */
/*<       bal=d2+taq+taqbn-(d1+tai) >*/
		    bal = d2 + taq + taqbn - (d1 + tai);
/* SOURCE feq.for:1617 */
/*<       rbal=bal/(d2+taq+taqbn+1.0) >*/
		    rbal = bal / (d2 + taq + taqbn + (float)1.);
/* SOURCE feq.for:1618 */
/*<       write(stdout,2154)bal,rbal >*/
		    feq_gen_io_d__213.ciunit = xscom_1.stdout;
		    s_wsfe(&feq_gen_io_d__213);
		    do_fio(&feq_gen_c_d_1, (char *)&bal, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&rbal, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE feq.for:1619 */
/*<       endif >*/
		}
/*                   SUMIT = 0.0 */
/*                   DO 2134 JK=1,NBN */
/*                    SUMIT = SUMIT + QPVEC(JK) */
/* 2134               CONTINUE */
/*                   SUMIT = SUMIT*DT */
/*                   WRITE(STDOUT,*) ' DIFFUSE INFLOW VOL. AFTER=',SUMIT */
/* SOURCE feq.for:1626 */
/*<       endif >*/
	    }
/*                OUTPUT QPVEC */
/*                 IF(OUTPUT.GT.4) THEN */
/*                   CALL QPVOUT */
/*     I                        (NBRA, NBN, STDOUT, BRPT, QPVEC, NRWTA, */
/*     I                         RWTA, RTAP) */
/*                 ENDIF */
/*                Output to the GENSCN file. */
/* SOURCE feq.for:1637 */
/*<       if(feo_unit.gt.0)then >*/
	    if (genscn_1.feq_gen_feo_unit_d_ > 0) {
/* SOURCE feq.for:1638 */
/*<       callout_genscn(stdout,jtime,dz_for_output) >*/
		feq_gen_out_genscn_d_(&xscom_1.stdout, &julian_1.jtime, &
			feq_gen_dz_for_output_d_);
/* SOURCE feq.for:1640 */
/*<       endif >*/
	    }
/* SOURCE feq.for:1641 */
/*<       endif >*/
	}
/* SOURCE feq.for:1643 */
/*<        >*/
	if (infcom_1.nout > 0 && infcom_1.ifrz <= 1) {
	    outsp_(infcom_1.exnodt, &infcom_1.nex, &julian_1.yr, &julian_1.mn,
		     &julian_1.dy, &hr, &infcom_1.nout, &infcom_1.unit, 
		    infcom_1.pout, &feq_gen_dz_for_output_d_, qout, zout, &lkount, (
		    ftnlen)8, (ftnlen)8);
	}
/*                GOTO NEXT TIME INTERVAL */
/*      CALL MISSVOL(NBRA, NBN, BRPT, DXVEC, A2, GEQVEC, K2, T2, Q2, */
/*     A             0, JTIME) */
/* SOURCE feq.for:1654 */
/*<       if(hi_iq_ns.ne.'NO')then >*/
	if (s_cmp(feq_gen_hi_iq_ns_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) != 0) {
/* SOURCE feq.for:1655 */
/*<        >*/
	    feq_gen_hi_iq_ns_success_d_(&xscom_1.stdout, &feq_gen_hi_iq_ns_up_d_, feq_gen_hi_iq_ns_d_, &
		    dt, &feq_gen_hi_iq_ns_dt_d_, matcom_1.feq_gen_hi_iq_ns_fac_d_, (ftnlen)4);
/* SOURCE feq.for:1658 */
/*<       endif >*/
	}
/* SOURCE feq.for:1661 */
/*<       goto8000 >*/
	goto L8000;
/* SOURCE feq.for:1663 */
/*<       endif >*/
    }
/*           NON-CONVERGENCE FALLS TO HERE */
/*           MAKE EXTERIOR NODES ON BRANCHES SAME VALUE AS THE */
/*           INTERIOR NODE VALUES. */
/* SOURCE feq.for:1671 */
/*<       do400i=1,nbra >*/
    feq_gen_i_d_1 = infcom_1.nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE feq.for:1672 */
/*<       ye2(brpt(5,i))=y2(brpt(3,i)) >*/
	enelem_1.ye2[infcom_1.brpt[(feq_gen_i_d_ << 3) - 4] - 1] = bnelem_1.y2[
		infcom_1.brpt[(feq_gen_i_d_ << 3) - 6] - 1];
/* SOURCE feq.for:1673 */
/*<       te2(brpt(5,i))=t2(brpt(3,i)) >*/
	enelem_1.te2[infcom_1.brpt[(feq_gen_i_d_ << 3) - 4] - 1] = bnelem_1.t2[
		infcom_1.brpt[(feq_gen_i_d_ << 3) - 6] - 1];
/* SOURCE feq.for:1674 */
/*<       ae2(brpt(5,i))=a2(brpt(3,i)) >*/
	enelem_1.ae2[infcom_1.brpt[(feq_gen_i_d_ << 3) - 4] - 1] = bnelem_1.a2[
		infcom_1.brpt[(feq_gen_i_d_ << 3) - 6] - 1];
/* SOURCE feq.for:1675 */
/*<       qe2(brpt(5,i))=q2(brpt(3,i)) >*/
	enelem_1.qe2[infcom_1.brpt[(feq_gen_i_d_ << 3) - 4] - 1] = bnelem_1.q2[
		infcom_1.brpt[(feq_gen_i_d_ << 3) - 6] - 1];
/* SOURCE feq.for:1676 */
/*<       ye2(brpt(6,i))=y2(brpt(4,i)) >*/
	enelem_1.ye2[infcom_1.brpt[(feq_gen_i_d_ << 3) - 3] - 1] = bnelem_1.y2[
		infcom_1.brpt[(feq_gen_i_d_ << 3) - 5] - 1];
/* SOURCE feq.for:1677 */
/*<       te2(brpt(6,i))=t2(brpt(4,i)) >*/
	enelem_1.te2[infcom_1.brpt[(feq_gen_i_d_ << 3) - 3] - 1] = bnelem_1.t2[
		infcom_1.brpt[(feq_gen_i_d_ << 3) - 5] - 1];
/* SOURCE feq.for:1678 */
/*<       ae2(brpt(6,i))=a2(brpt(4,i)) >*/
	enelem_1.ae2[infcom_1.brpt[(feq_gen_i_d_ << 3) - 3] - 1] = bnelem_1.a2[
		infcom_1.brpt[(feq_gen_i_d_ << 3) - 5] - 1];
/* SOURCE feq.for:1679 */
/*<       qe2(brpt(6,i))=q2(brpt(4,i)) >*/
	enelem_1.qe2[infcom_1.brpt[(feq_gen_i_d_ << 3) - 3] - 1] = bnelem_1.q2[
		infcom_1.brpt[(feq_gen_i_d_ << 3) - 5] - 1];
/* SOURCE feq.for:1680 */
/*<   400 continue >*/
/* L400: */
    }
/*           COMPUTE  MATRIX, UPDATE SRNEW, AND SOLVE MATRIX */
/* SOURCE feq.for:1685 */
/*<        >*/
    csmat_(&dt, &dtdy, &wt, &infcom_1.nbn, &infcom_1.nbra, &infcom_1.nex, 
	    infcom_1.brpt, &hslot, &infcom_1.ept, &feq_gen_dtmin_out_d_, &feq_gen_start_eq_d_, &
	    feq_gen_end_eq_d_, &julian_1.jtime, &julian_1.prtime, &kount, &
	    infcom_1.qeps, infcom_1.emc, infcom_1.exnodt, &srnew, &mxres, &
	    lmxres, &errp, &errq, &berrq, &nerrq, &nerrp, &berrp);
/*           HAS THE CORRECTION IMPROVED THE SUM OF SQUARES OF THE */
/*           RESIDUALS? */
/* SOURCE feq.for:1696 */
/*<       mxssrv(kount+1)=srnew >*/
    mxssrv[kount] = srnew;
/* SOURCE feq.for:1697 */
/*<       mxrv(kount+1)=mxres >*/
    mxrv[kount] = mxres;
/* SOURCE feq.for:1698 */
/*<       lmxrv(kount+1)=lmxres >*/
    lmxrv[kount] = lmxres;
/* SOURCE feq.for:1702 */
/*<       if(srnew.le.srold+srlim)then >*/
    if (srnew <= static_cast<double>(srold) + srlim) {
/*            IF(SROLD.EQ.SROLD) THEN */
/*             YES, IMPROVEMENT */
/* SOURCE feq.for:1707 */
/*<       lambda=1.0 >*/
	lambda = (float)1.;
/* SOURCE feq.for:1708 */
/*<       srold=srnew >*/
	srold = srnew;
/*             COMPUTE NEW CORRECTION SET FROM CURRENT RESULT */
/* SOURCE feq.for:1712 */
/*<       goto8200 >*/
	goto L8200;
/* SOURCE feq.for:1714 */
/*<       else >*/
    } else {
/*             NO IMPROVEMENT */
/* SOURCE feq.for:1718 */
/*<       if(minprt.eq.0)write(stdout,3000)srold,srnew,lambda >*/
	if (minprt == 0) {
	    feq_gen_io_d__216.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__216);
	    do_fio(&feq_gen_c_d_1, (char *)&srold, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&srnew, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&lambda, (ftnlen)sizeof(real));
	    e_wsfe();
	}
/* SOURCE feq.for:1719 */
/*<       lambda=0.5*lambda >*/
	lambda *= static_cast<double>((float).5);
/* SOURCE feq.for:1721 */
/*<       sumitr=sumitr+1 >*/
	++sumitr;
/* SOURCE feq.for:1722 */
/*<       if(lambda.lt.0.07)then >*/
	if (lambda < (float).07) {
/* CCCCCCCCCCCCC  IF(SRNEW.LT.SRLIM) THEN */
/* SOURCE feq.for:1725 */
/*<       write(stdout,*)' NO IMPROVEMENT BUT USE ANYWAY' >*/
	    feq_gen_io_d__217.ciunit = xscom_1.stdout;
	    s_wsle(&feq_gen_io_d__217);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NO IMPROVEMENT BUT USE ANYWAY"), (ftnlen)30)
		    ;
	    e_wsle();
/* SOURCE feq.for:1727 */
/*<       lambda=1.0 >*/
	    lambda = (float)1.;
/* SOURCE feq.for:1728 */
/*<       srold=srnew >*/
	    srold = srnew;
/* SOURCE feq.for:1729 */
/*<       goto8200 >*/
	    goto L8200;
/* CCCCCCCCCCCCC  ENDIF */
/* CCCCCCCCCCCCC  CFLAG = 0 */
/*               TRY AGAIN WITH A SMALLER TIME STEP */
/* CCCCCC         IF(MINPRT.EQ.0) THEN */
/* CCCCC            CALL PRTLOG(STDOUT, KOUNT, MXREV, BMXREV, NMXREV, MXRV, */
/* CCC A                        LMXRV, MXSSRV, KNTVEC) */
/* CCCCCC           WRITE(STDOUT,*) 'LAMBDA TOO SMALL. REDUCE TIME STEP' */
/* CCCCCC         ENDIF */
/* CCCCCC         GOTO 8000 */
/* SOURCE feq.for:1743 */
/*<       endif >*/
	}
/* SOURCE feq.for:1745 */
/*<       goto8400 >*/
	goto L8400;
/* SOURCE feq.for:1746 */
/*<       endif >*/
    }
/* SOURCE feq.for:1747 */
/*<       end >*/
    return 0;
} /* MAIN__ */

#undef rtmp
#undef itab
#undef ftab


/* Main program alias */ int feq_ () { feq_gen_MAIN_d_ (); return 0; }
#ifdef __cplusplus
	}
#endif
