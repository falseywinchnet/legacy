/* timeman.f -- translated by f2c (version 20240504).
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

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON bnpond_ is declared in common.hpp. */

#define bnpond_1 bnpond_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON gravcm_ is declared in common.hpp. */

#define gravcm_1 gravcm_

/* COMMON dtcom_ is declared in common.hpp. */

#define dtcom_1 dtcom_

/* COMMON wrcom_ is declared in common.hpp. */

#define wrcom_1 wrcom_

/* COMMON wrcomc_ is declared in common.hpp. */

#define wrcomc_1 wrcomc_

/* COMMON wrcomd_ is declared in common.hpp. */

#define wrcomd_1 wrcomd_

/* COMMON timcom_ is declared in common.hpp. */

#define timcom_1 timcom_

/* COMMON namcom_ is declared in common.hpp. */

#define namcom_1 namcom_

/* COMMON genscn_ is declared in common.hpp. */

#define genscn_1 genscn_

/* COMMON tamcom_ is declared in common.hpp. */

#define tamcom_1 tamcom_

/* COMMON timetabc_ is declared in common.hpp. */

#define timetabc_1 timetabc_

/* COMMON timetab_ is declared in common.hpp. */

#define timetab_1 timetab_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer c_n1 = -1;
static integer feq_gen_c_d_3 = 3;

/* Routines used in time keeping and timestep control and management */





/* SOURCE timeman.for:7 */
/*<       integerfunctioniwyr(yr,mn) >*/
integer iwyr_(integer *yr, integer *mn)
{
    /* System generated locals */
    integer ret_val;

/*     + + + PURPOSE + + + */
/*     Return water year for calendar year and month. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE timeman.for:14 */
/*<       integermn,yr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     YR     - calendar year */
/*     MN     - number of month(1-12) */
/* *********************************************************************** */
/* SOURCE timeman.for:20 */
/*<       iwyr=yr >*/
    ret_val = *yr;
/* SOURCE timeman.for:21 */
/*<       if(mn.ge.10)iwyr=yr+1 >*/
    if (*mn >= 10) {
	ret_val = *yr + 1;
    }
/* SOURCE timeman.for:22 */
/*<       return >*/
    return ret_val;
/* SOURCE timeman.for:23 */
/*<       end >*/
} /* iwyr_ */

/*     *********** */
/*     *         * */
/*     * JTIME_OUT  * */
/*     *         * */
/*     *********** */
/* SOURCE timeman.for:30 */
/*<       subroutinejtime_out(stdout,jtime) >*/
/* Subroutine */ int feq_gen_jtime_out_d_(integer *stdout, doublereal *jtime)
{
    /* Format strings */
    static char fmt_50[] = "(\002 JTIME=\002,f20.10,1x,i5,\002/\002,i2,\002\
/\002,i2,\002::\002,i2,\002:\002,i2)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer mn, dy, yr, mjd, ihr, feq_gen_min_d_;
    doublereal hour, dyfrac;
    extern /* Subroutine */ int invmjd_(integer *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__9 = { 0, 0, 0, fmt_50, 0 };


/*     Output JTIME in normal calendar form. */
/* SOURCE timeman.for:34 */
/*<       implicitnone >*/
/* SOURCE timeman.for:35 */
/*<       integerstdout >*/
/* SOURCE timeman.for:37 */
/*<       real*8jtime >*/
/*     Local */
/* SOURCE timeman.for:41 */
/*<       integeryr,mn,dy,ihr,min,mjd >*/
/* SOURCE timeman.for:43 */
/*<       real*8dyfrac,hour >*/
/* *********************************************************************** */
/* SOURCE timeman.for:45 */
/*<       mjd=int(jtime) >*/
    mjd = (integer) (*jtime);
/* SOURCE timeman.for:46 */
/*<       dyfrac=jtime-dble(mjd) >*/
    dyfrac = *jtime - (doublereal) mjd;
/* SOURCE timeman.for:47 */
/*<       callinvmjd(mjd,yr,mn,dy) >*/
    invmjd_(&mjd, &yr, &mn, &dy);
/* SOURCE timeman.for:48 */
/*<       hour=dyfrac*24.d0 >*/
    hour = dyfrac * 24.;
/* SOURCE timeman.for:49 */
/*<       ihr=int(hour) >*/
    ihr = (integer) hour;
/* SOURCE timeman.for:50 */
/*<       min=int((hour-dble(ihr))*60.d0+0.5d0) >*/
    feq_gen_min_d_ = (integer) ((hour - (doublereal) ihr) * 60. + .5);
/* SOURCE timeman.for:51 */
/*<       write(stdout,50)jtime,yr,mn,dy,ihr,min >*/
    feq_gen_io_d__9.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__9);
    do_fio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&mn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&dy, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&ihr, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_min_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE timeman.for:52 */
/*<    50 format(' JTIME=',f20.10,1x,i5,'/',i2,'/',i2,'::',i2,':',i2) >*/
/* SOURCE timeman.for:53 */
/*<       return >*/
    return 0;
/* SOURCE timeman.for:54 */
/*<       end >*/
} /* jtime_out__ */




/* SOURCE timeman.for:58 */
/*<       character*14functionjttoct(jtime) >*/
/* Character */ VOID jttoct_(char *ret_val, ftnlen ret_val_len, doublereal *
	jtime)
{
    /* Format strings */
    static char fmt_50[] = "(i3.2,i2.2,i2.2,\002:\002,f6.3)";

    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    real hr;
    integer mn, dy, yr, mjd;
    doublereal frac;
    extern /* Subroutine */ int invmjd_(integer *, integer *, integer *, 
	    integer *);

/*     + + + PURPOSE + + + */
/*     Convert modified julian time to calendar time. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE timeman.for:65 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JTIME  - current modified julian time in the model */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE timeman.for:71 */
/*<       integerdy,mjd,mn,yr >*/
/* SOURCE timeman.for:72 */
/*<       realhr >*/
/* SOURCE timeman.for:73 */
/*<       real*8frac >*/
/*     + + + INTRINSICS + + + */
/* SOURCE timeman.for:76 */
/*<       intrinsicdble,int >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE timeman.for:79 */
/*<       externalinvmjd >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE timeman.for:82 */
/*<    50 format(i3.2,i2.2,i2.2,':',f6.3) >*/
/* *********************************************************************** */
/* SOURCE timeman.for:84 */
/*<       mjd=int(jtime) >*/
/* L50: */
    mjd = (integer) (*jtime);
/* SOURCE timeman.for:85 */
/*<       frac=jtime-dble(mjd) >*/
    frac = *jtime - (doublereal) mjd;
/* SOURCE timeman.for:86 */
/*<       callinvmjd(mjd,yr,mn,dy) >*/
    invmjd_(&mjd, &yr, &mn, &dy);
/* SOURCE timeman.for:89 */
/*<       hr=sngl(24.d0*frac) >*/
    hr = (real) (frac * 24.);
/*      IF(YR.LT.2000) THEN */
/*        YR = YR - 1900 */
/*      ELSE */
/*        YR = YR - 2000 */
/*      ENDIF */
/* SOURCE timeman.for:96 */
/*<       yr=mod(yr,100) >*/
    yr %= 100;
/* SOURCE timeman.for:97 */
/*<       write(jttoct,50)yr,mn,dy,hr >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 14;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_50;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&mn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&dy, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE timeman.for:98 */
/*<       return >*/
    return ;
/* SOURCE timeman.for:99 */
/*<       end >*/
} /* jttoct_ */




/* SOURCE timeman.for:103 */
/*<        >*/
/* Subroutine */ int mantim_(integer *feq_storage_brpt, integer *bwfdsn, char *diffus, 
	real *vunit, real *feq_storage_dtvec, integer *feq_storage_exnodt, integer *nblk, integer *
	nbn, integer *nbra, char *nodeid, integer *nex, integer *feq_storage_opblk, 
	integer *resnum, integer *feq_storage_resvec, real *sfac, integer *fffdsn, 
	integer *minprt, real *hslot, integer *putdsn, integer *getdsn, 
	integer *bnode, real *qchop, doublereal *bni, doublereal *bnq, 
	doublereal *tai, doublereal *taq, doublereal *taqbn, doublereal *wsi, 
	doublereal *wsq, char *feq_gen_old_summary_d_, integer *cflag, doublereal *dt, 
	doublereal *dtdy, integer *ifrz, real *wt, integer *seflag, integer *
	feq_storage_emc, integer *sumitr, doublereal *s1, doublereal *d1, integer *
	feq_gen_dt_adjust_d_, real *feq_gen_dz_for_output_d_, ftnlen diffus_len, ftnlen 
	nodeid_len, ftnlen old_summary_len)
{
    /* Initialized data */

    static char yes[4+1] = "YES ";
    static integer tflag = 0;

    /* Format strings */
    static char fmt_2000[] = "(/,\002 SIMULATION COMPLETE AT \002,f15.0,\002\
 SECS.\002)";
    static char fmt_2010[] = "(/)";
    static char fmt_2020[] = "(/,\002 SIMULATION ENDING AT \002,i5,\002/\002\
,i3,\002/\002,i3,\002/\002,f7.3)";
    static char fmt_2080[] = "(/,\002 SIMULATION COMPLETED\002)";
    static char fmt_2100[] = "(/,6x,\002Time step reset to\002,f10.2,\002 \
sec\002,\002 WT = \002,f5.3)";
    static char fmt_2110[] = "(6x,\002Time step too small. RUN TERMINATED\
.\002)";
    static char fmt_2120[] = "(/,\002 Time step reset in mantim to\002,f10\
.2,\002 secs to match\002,\002 event end\002)";
    static char fmt_2150[] = "(\002 Balance 1: S1=\002,1pe9.3,\002 S2=\002,1\
pe9.3,\002 BNI=\002,1pe9.3,\002 BNQ=\002,1pe9.3,\002 TAQ=\002,1pe9.3,\002 WS\
I=\002,1pe9.3,\002 WSQ=\002,1pe9.3)";
    static char fmt_2152[] = "(\002 Bal diff=BAL=S2-S1-BNI-TAQ+BNQ-WSI+WSQ\
=\002,1pe10.3,\002 Rel bal=BAL/(S2+BNQ)=\002,1pe10.3)";
    static char fmt_2153[] = "(\002 Balance 2: D1=\002,1pe9.3,\002 D2=\002,1\
pe9.3,\002 TAI=\002,1pe9.3,\002 TAQBN=\002,1pe9.3)";
    static char fmt_2154[] = "(\002 Bal diff=BAL=D2-D1-TAI+TAQ+TAQBN=\002,1p\
e10.3,\002 Rel Bal=BAL/(D2+TAQ+TAQBN)=\002,1pe10.0)";
    static char fmt_2149[] = "(/,\002 Balance for current runoff event:\002)";
    static char fmt_3018[] = "(/,\002 IFRZ = \002,i5)";
    static char fmt_3020[] = "(/,\002 Computation time=\002,f10.2,\002 secs \
or \002,f10.4,\002 mins\002,/,5x,\002Minimum time step=\002,f10.2,\002 sec\
s\002)";
    static char fmt_3021[] = "(/,\002 Comp time=\002,f9.2,\002 secs \002,f8.\
3,\002 mins\002,/,5x,\002Minimum time step=\002,f10.2,\002 secs\002)";

    /* System generated locals */
    real feq_gen_r_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_non_conv_summary_d_(integer *, integer *, 
	    integer *, integer *, integer *);
    doublereal d2, s2;
    extern /* Subroutine */ int feq_gen_spo_close_d_(integer *);
    real et, hr;
    extern /* Subroutine */ int feq_gen_out_genscn_d_(integer *, doublereal *, real *);
    real bal;
    extern /* Subroutine */ int feq_gen_zsumry_old_d_(integer *, integer *, char *, 
	    real *, integer *, integer *, integer *, integer *, real *, real *
	    , real *, real *, ftnlen);
    doublereal dtt;
    extern /* Subroutine */ int feq_gen_hecdss_quit_d_(integer *);
    real rbal, dthr;
    extern /* Subroutine */ int oper_(doublereal *, integer *, integer *, 
	    real *, integer *), feq_gen_genscn_close_d_(integer *, integer *), 
	    feq_gen_find_volumes_d_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , real *, integer *, real *, real *, real *, doublereal *, 
	    doublereal *, real *, real *, doublereal *, doublereal *);
    integer bwrec;
    real wtold;
    doublereal dtold;
    extern /* Subroutine */ int bwput_(integer *, real *, integer *, integer *
	    , integer *, integer *, integer *, integer *), putfc_(integer *, 
	    integer *, char *, real *, integer *, integer *, integer *, 
	    doublereal *, integer *, integer *, real *, doublereal *, integer 
	    *, integer *, ftnlen), bfinit_(doublereal *), nwdtwt_(real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *, integer *, doublereal *, doublereal *, real *, integer 
	    *, doublereal *, doublereal *), resout_(real *, real *, integer *,
	     integer *, char *, integer *, doublereal *, real *, integer *, 
	    integer *, real *, real *, ftnlen), segend_(integer *, doublereal 
	    *, integer *, integer *, integer *, integer *, char *, integer *, 
	    real *, integer *, real *, real *, integer *, integer *, integer *
	    , integer *, real *, real *, integer *, real *, char *, real *, 
	    ftnlen, ftnlen), timinc_(doublereal *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, integer *), wrinit_(
	    doublereal *), wrquit_(integer *, doublereal *), zsumry_(integer *
	    , integer *, char *, real *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, ftnlen), timerl_(
	    integer *), rdquit_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_3018, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_2110, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_3020, 0 };
    static cilist feq_gen_io_d__26 = { 0, 6, 0, fmt_3021, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_2110, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_3020, 0 };
    static cilist feq_gen_io_d__29 = { 0, 6, 0, fmt_3021, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_2100, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_2110, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_3020, 0 };
    static cilist feq_gen_io_d__35 = { 0, 6, 0, fmt_3021, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_2120, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_2149, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_2150, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_2152, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_2153, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_2154, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_2020, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_2080, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_3020, 0 };
    static cilist feq_gen_io_d__54 = { 0, 6, 0, fmt_3021, 0 };


/*     + + + PURPOSE + + + */
/*     Subroutine to manage time, time step, and time-integrating */
/*     factor.  It also detects end of run conditions. */
/* SOURCE timeman.for:116 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE timeman.for:118 */
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
/* SOURCE timeman.for:121 */
/*<        >*/
/* SOURCE timeman.for:124 */
/*<        >*/
/* SOURCE timeman.for:126 */
/*<       realdtvec(mnfrdt),hslot,qchop,sfac,vunit,wt,dz_for_output >*/
/* SOURCE timeman.for:127 */
/*<       real*8d1,dt,dtdy,s1,bni,bnq,tai,taq,taqbn,wsi,wsq >*/
/* SOURCE timeman.for:128 */
/*<       characterdiffus*4,nodeid*4,old_summary*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
/*     BWFDSN - unit number for the initial conditions file */
/*     DIFFUS - indicator if tributary area is present. */
/*     VUNIT  - conversion factor for volumes on output */
/*     DTVEC  - sequence of time steps for frozen time simulation */
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
/*     NBLK   - number of operation blocks */
/*     NBN    - total number on nodes on branches in the model */
/*     NBRA   - number of branches in the model */
/*     NODEID - user node identification string */
/*     NEX    - number of exterior nodes in the model */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     RESNUM - number of level-pool reservoirs */
/*              number of level-pool reservoirs */
/*     RESVEC - index into area vector for each level-pool reservoir */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     FFFDSN - unit number for output of the flood frequency file */
/*     MINPRT - flag to select minimum print out to the user message */
/*               file when DIFFUS=YES */
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
/*     PUTDSN - unit number for storing final conditions */
/*     BNODE  - boundary node number at which to start defining the */
/*               coefficient matrix */

/*     QCHOP  - chopping value for output of flow */
/*     BNI  - inflows to the stream system from boundary nodes and */
/*              from tributary area. */
/*     BNQ - outflow from the stream system at boundary nodes */
/*     TAI -  total inflow to tributary area */
/*     TAQ - total outflow from trib area into branches and LPR's */
/*           excluding boundary nodes */
/*     TAQBN - total outflow from trib area to boundary nodes */
/*     OLD_SUMMARY - if YES summary of extremes is in per-version 10 format, */
/*                   otherwise it is in version 10 format. */
/*     CFLAG  - convergence flag: 1- convergence; 0-no convergence */
/*     DT     - time step in seconds */
/*     IFRZ   - count of frozen time steps */
/*     WT     - weight factor for approximating time integrals */
/*     SEFLAG - segment end flag */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     SUMITR - cumulative sum of iterations to convergence */
/*     S1  - initial storage of water in the model in */
/*           level-pool reservoirs and branches */
/*     D1  - initial storage of water in the model in detention and delay */
/*           reservoirs */
/*     dt_adjust - pass value of TFLAG to FEQ so that small time steps */
/*                 resulting from adjustment to synchronize time with */
/*                 even increments of the hour do not get used in */
/*                 computing the minimum time step for the run. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE timeman.for:205 */
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
/* INCLUDE timeman.for:206 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE timeman.for:207 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE timeman.for:208 */
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
/* INCLUDE timeman.for:209 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE timeman.for:210 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE timeman.for:211 */
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
/* INCLUDE timeman.for:212 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/* INCLUDE timeman.for:213 */
/* ********************************************************************** */
/* SOURCE dtcom.cmn:3 */
/*<        >*/
/* SOURCE dtcom.cmn:6 */
/*<       realauto,siter,high,low,maxdt,mindt,hfac,lfac,bwt,dwt,isiter >*/
/* ********************************************************************** */
/* INCLUDE timeman.for:214 */
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
/* INCLUDE timeman.for:215 */
/* SOURCE timcom.cmn:2 */
/*<        >*/
/* SOURCE timcom.cmn:5 */
/*<       integeritick,itick0,itick1,itick2,cmpext,cmpint,slvext,slvint >*/
/* SOURCE timcom.cmn:8 */
/*<       realmin_time_step >*/
/* INCLUDE timeman.for:216 */
/*     NAMES FOR VARIOUS OPTIONAL FILES AND SPECIAL OUTPUT FILE */
/*     HEADINGS */
/* SOURCE namcom.cmn:5 */
/*<       character*7sphead(mnsout,2) >*/
/* SOURCE namcom.cmn:7 */
/*<       character*256bwfnam,fffnam,tsfnam,putnam,getnam >*/
/* SOURCE namcom.cmn:9 */
/*<       common/namcom/bwfnam,fffnam,tsfnam,sphead,putnam,getnam >*/
/* INCLUDE timeman.for:217 */
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
/* INCLUDE timeman.for:218 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE timeman.for:221 */
/*<       integertflag >*/
/* SOURCE timeman.for:222 */
/*<       characteryes*4 >*/
/* SOURCE timeman.for:223 */
/*<       savetflag,yes >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE timeman.for:226 */
/*<       integerbwrec >*/
/* SOURCE timeman.for:227 */
/*<       realbal,dthr,et,hr,rbal,wtold >*/
/* SOURCE timeman.for:228 */
/*<       real*8d2,dtold,dtt,s2 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE timeman.for:231 */
/*<       intrinsicabs,float,sngl >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE timeman.for:234 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE timeman.for:239 */
/*<       datayes/'YES'/,tflag/0/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> dtvec(feq_storage_dtvec, 1);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> resvec(feq_storage_resvec, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE timeman.for:242 */
/*<  2000 format(/,' SIMULATION COMPLETE AT ',f15.0,' SECS.') >*/
/* L2000: */
/* SOURCE timeman.for:243 */
/*<  2010 format(/) >*/
/* L2010: */
/* SOURCE timeman.for:244 */
/*<  2020 format(/,' SIMULATION ENDING AT ',i5,'/',i3,'/',i3,'/',f7.3) >*/
/* L2020: */
/* SOURCE timeman.for:245 */
/*<  2080 format(/,' SIMULATION COMPLETED') >*/
/* L2080: */
/* SOURCE timeman.for:246 */
/*<  2100 format(/,6x,'Time step reset to',f10.2,' sec',' WT = ',f5.3) >*/
/* L2100: */
/* SOURCE timeman.for:247 */
/*<  2110 format(6x,'Time step too small. RUN TERMINATED.') >*/
/* L2110: */
/* SOURCE timeman.for:248 */
/*<  2120  >*/
/* L2120: */
/* SOURCE timeman.for:250 */
/*<  2150  >*/
/* L2150: */
/* SOURCE timeman.for:253 */
/*<  2152  >*/
/* L2152: */
/* SOURCE timeman.for:255 */
/*<  2153  >*/
/* L2153: */
/* SOURCE timeman.for:257 */
/*<  2154  >*/
/* L2154: */
/* SOURCE timeman.for:259 */
/*<  2149 format(/,' Balance for current runoff event:') >*/
/* L2149: */
/* SOURCE timeman.for:260 */
/*<  3018 format(/,' IFRZ = ',i5) >*/
/* L3018: */
/* SOURCE timeman.for:261 */
/*<  3020  >*/
/* L3020: */
/* SOURCE timeman.for:263 */
/*<  3021  >*/
/* L3021: */
/* 3022 FORMAT(' TIME IN COMPUTING NETWORK MATRIX=',F10.2,' SECS.') */
/* 3023 FORMAT(' TIME IN SOLVING NETWORK MATRIX=',F10.2,' SECS.') */
/* *********************************************************************** */
/*       set signal for non-computational adjustment of time step */
/* SOURCE timeman.for:269 */
/*<       dt_adjust=tflag >*/
    *feq_gen_dt_adjust_d_ = tflag;
/*       SAVE THE OLD TIME STEP FOR POSSIBLE USE LATER */
/* SOURCE timeman.for:271 */
/*<       dtold=dt >*/
    dtold = *dt;
/* SOURCE timeman.for:272 */
/*<       wtold=wt >*/
    wtold = *wt;
/* SOURCE timeman.for:273 */
/*<       if(cflag.eq.1)then >*/
    if (*cflag == 1) {
/*         CONVERGENCE ON TIME POINT JUST COMPLETED- CONTINUE  IN */
/*         TIME */
/*         CLEAR CONVERGENCE FLAG */
/* SOURCE timeman.for:280 */
/*<       cflag=0 >*/
	*cflag = 0;
/* SOURCE timeman.for:282 */
/*<       if(ifrz.gt.0)then >*/
	if (*ifrz > 0) {
/*           FROZEN TIME STILL IN EFFECT. */
/* SOURCE timeman.for:286 */
/*<       ifrz=ifrz-1 >*/
	    --(*ifrz);
/* SOURCE timeman.for:287 */
/*<       write(stdout,3018)ifrz >*/
	    feq_gen_io_d__20.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__20);
	    do_fio(&feq_gen_c_d_1, (char *)&(*ifrz), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE timeman.for:289 */
/*<       if(ifrz.eq.0)then >*/
	    if (*ifrz == 0) {
/*             FROZEN TIME OVER. SAVE STATE OF SYSTEM AS NEEDED. */
/* SOURCE timeman.for:293 */
/*<       if(diffus.eq.yes)then >*/
		if (s_cmp(diffus, yes, (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE timeman.for:294 */
/*<       if(getdsn+putdsn==0)then >*/
		    if (*getdsn + *putdsn == 0) {
/* SOURCE timeman.for:295 */
/*<       bwrec=1 >*/
			bwrec = 1;
/* SOURCE timeman.for:296 */
/*<       callbwput(bwfdsn,wt,nbra,nbn,nex,nblk,opblk,bwrec) >*/
			bwput_(bwfdsn, wt, nbra, nbn, nex, nblk, &opblk[1], &
				bwrec);
/* SOURCE timeman.for:299 */
/*<       write(std6,*)' BWF being written at IFRZ=0 in MANTIM' >*/
			feq_gen_io_d__22.ciunit = feq_gen_stdun_com_d_1.std6;
			s_wsle(&feq_gen_io_d__22);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BWF being written at IFRZ=0 i\
n MANTIM"), (ftnlen)38);
			e_wsle();
/* SOURCE timeman.for:300 */
/*<       endif >*/
		    }
/* SOURCE timeman.for:301 */
/*<       endif >*/
		}
/* SOURCE timeman.for:303 */
/*<       if(nfout.gt.0)callwrinit(sjtime) >*/
		if (wrcom_1.nfout > 0) {
		    wrinit_(&julian_1.sjtime);
		}
/*             COMPUTE INITIAL SYSTEM VOLUME */
/* SOURCE timeman.for:308 */
/*<        >*/
		feq_gen_find_volumes_d_(nbra, nbn, nex, resnum, &tamcom_1.feq_gen_dlay_knt_d_, &
			tamcom_1.feq_gen_dten_knt_d_, &brpt[9], &resvec[1], 
			bnelem_1.dxvec, bnelem_1.a1, enelem_1.ae1, 
			bnpond_1.pond1, bnothr_1.geqvec, bnelem_1.q1, 
			bnelem_1.wxvec1, bnelem_1.ma1, tamcom_1.feq_gen_dlay_q1_d_, 
			tamcom_1.feq_gen_dlay_k_d_, tamcom_1.feq_gen_dten_s1_d_, 
			tamcom_1.feq_gen_dten_avda_d_, s1, d1);
/* SOURCE timeman.for:314 */
/*<       if(feo_unit.gt.0)then >*/
		if (genscn_1.feq_gen_feo_unit_d_ > 0) {
/* SOURCE timeman.for:315 */
/*<       callout_genscn(stdout,sjtime,dz_for_output) >*/
		    feq_gen_out_genscn_d_(&xscom_1.stdout, &julian_1.sjtime, 
			    feq_gen_dz_for_output_d_);
/* SOURCE timeman.for:317 */
/*<       endif >*/
		}
/* SOURCE timeman.for:318 */
/*<        >*/
		nwdtwt_(&dtcom_1.siter, &dtcom_1.maxdt, &dtcom_1.mindt, &
			dtcom_1.low, &dtcom_1.high, &dtcom_1.lfac, &
			dtcom_1.hfac, &dtcom_1.bwt, &dtcom_1.dwt, &
			xscom_1.stdout, minprt, &julian_1.jtime, &
			xscom_1.time, wt, &tflag, dt, dtdy);
/* SOURCE timeman.for:324 */
/*<       if(dt.lt.mindt)then >*/
		if (*dt < dtcom_1.mindt) {
/*               Close any GENSCN files. -1 signals normal termination */
/* SOURCE timeman.for:326 */
/*<       callgenscn_close(stdout,-1) >*/
		    feq_gen_genscn_close_d_(&xscom_1.stdout, &c_n1);
/*               Close any special output file and its description file */
/* SOURCE timeman.for:328 */
/*<       callspo_close(stdout) >*/
		    feq_gen_spo_close_d_(&xscom_1.stdout);
/* SOURCE timeman.for:330 */
/*<       write(stdout,2110) >*/
		    feq_gen_io_d__23.ciunit = xscom_1.stdout;
		    s_wsfe(&feq_gen_io_d__23);
		    e_wsfe();
/* SOURCE timeman.for:331 */
/*<       callnon_conv_summary(stdout,nex,nbn,nbra,brpt) >*/
		    feq_gen_non_conv_summary_d_(&xscom_1.stdout, nex, nbn, nbra, &brpt[
			    9]);
/* SOURCE timeman.for:332 */
/*<       calltimerl(itick1) >*/
		    timerl_(&timcom_1.itick1);
/* SOURCE timeman.for:333 */
/*<       if(itick1.lt.itick0)then >*/
		    if (timcom_1.itick1 < timcom_1.itick0) {
/* SOURCE timeman.for:334 */
/*<       itick1=itick1+100*86400 >*/
			timcom_1.itick1 += 8640000;
/* SOURCE timeman.for:335 */
/*<       endif >*/
		    }
/* SOURCE timeman.for:336 */
/*<       et=float(itick1-itick0)/100.0 >*/
		    et = static_cast<double>((real) (timcom_1.itick1 - timcom_1.itick0)) / (float)
			    100.;
/* SOURCE timeman.for:337 */
/*<       write(stdout,3020)et,et/60.,min_time_step >*/
		    feq_gen_io_d__25.ciunit = xscom_1.stdout;
		    s_wsfe(&feq_gen_io_d__25);
		    do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&timcom_1.feq_gen_min_time_step_d_, (ftnlen)
			    sizeof(real));
		    e_wsfe();
/* SOURCE timeman.for:338 */
/*<       write(*,3021)et,et/60.,min_time_step >*/
		    s_wsfe(&feq_gen_io_d__26);
		    do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&timcom_1.feq_gen_min_time_step_d_, (ftnlen)
			    sizeof(real));
		    e_wsfe();
/* SOURCE timeman.for:340 */
/*<       stop'Abnormal stop: time step too small.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: time step too small."), (ftnlen)35);
/* SOURCE timeman.for:341 */
/*<       endif >*/
		}
/*             UPDATE THE TIME */
/* SOURCE timeman.for:345 */
/*<       time=time+dt >*/
		xscom_1.time += *dt;
/* SOURCE timeman.for:346 */
/*<       calltiminc(dt,jtime,yr,mn,dy,dyfrac,leap) >*/
		timinc_(dt, &julian_1.jtime, &julian_1.yr, &julian_1.mn, &
			julian_1.dy, &julian_1.dyfrac, &julian_1.leap);
/* SOURCE timeman.for:349 */
/*<       sumitr=0 >*/
		*sumitr = 0;
/* SOURCE timeman.for:350 */
/*<       else >*/
	    } else {
/*             FROZEN TIME STILL ACTIVE */
/* SOURCE timeman.for:354 */
/*<       dt=dtvec(ifrz) >*/
		*dt = dtvec[*ifrz];
/* SOURCE timeman.for:355 */
/*<       dtdy=dt/86400.d0 >*/
		*dtdy = *dt / 86400.;
/* SOURCE timeman.for:356 */
/*<       endif >*/
	    }
/* SOURCE timeman.for:357 */
/*<       else >*/
	} else {
/*           FROZEN TIME OVER AND CONVERGENCE ON THE LAST TIME POINT */
/* SOURCE timeman.for:361 */
/*<        >*/
	    nwdtwt_(&dtcom_1.siter, &dtcom_1.maxdt, &dtcom_1.mindt, &
		    dtcom_1.low, &dtcom_1.high, &dtcom_1.lfac, &dtcom_1.hfac, 
		    &dtcom_1.bwt, &dtcom_1.dwt, &xscom_1.stdout, minprt, &
		    julian_1.jtime, &xscom_1.time, wt, &tflag, dt, dtdy);
/* SOURCE timeman.for:367 */
/*<       if(dt.lt.mindt.and.seflag.eq.0)then >*/
	    if (*dt < dtcom_1.mindt && *seflag == 0) {
/*             Close any GENSCN files. -1 signals normal termination */
/* SOURCE timeman.for:369 */
/*<       callgenscn_close(stdout,-1) >*/
		feq_gen_genscn_close_d_(&xscom_1.stdout, &c_n1);
/*             Close any special output file and its description file */
/* SOURCE timeman.for:371 */
/*<       callspo_close(stdout) >*/
		feq_gen_spo_close_d_(&xscom_1.stdout);
/* SOURCE timeman.for:372 */
/*<       write(stdout,2110) >*/
		feq_gen_io_d__27.ciunit = xscom_1.stdout;
		s_wsfe(&feq_gen_io_d__27);
		e_wsfe();
/* SOURCE timeman.for:373 */
/*<       callnon_conv_summary(stdout,nex,nbn,nbra,brpt) >*/
		feq_gen_non_conv_summary_d_(&xscom_1.stdout, nex, nbn, nbra, &brpt[9]);
/* SOURCE timeman.for:374 */
/*<       calltimerl(itick1) >*/
		timerl_(&timcom_1.itick1);
/* SOURCE timeman.for:375 */
/*<       if(itick1.lt.itick0)then >*/
		if (timcom_1.itick1 < timcom_1.itick0) {
/* SOURCE timeman.for:376 */
/*<       itick1=itick1+100*86400 >*/
		    timcom_1.itick1 += 8640000;
/* SOURCE timeman.for:377 */
/*<       endif >*/
		}
/* SOURCE timeman.for:378 */
/*<       et=float(itick1-itick0)/100.0 >*/
		et = static_cast<double>((real) (timcom_1.itick1 - timcom_1.itick0)) / (float)100.;
/* SOURCE timeman.for:379 */
/*<       write(stdout,3020)et,et/60.,min_time_step >*/
		feq_gen_io_d__28.ciunit = xscom_1.stdout;
		s_wsfe(&feq_gen_io_d__28);
		do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&timcom_1.feq_gen_min_time_step_d_, (ftnlen)
			sizeof(real));
		e_wsfe();
/* SOURCE timeman.for:380 */
/*<       write(*,3021)et,et/60.,min_time_step >*/
		s_wsfe(&feq_gen_io_d__29);
		do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&timcom_1.feq_gen_min_time_step_d_, (ftnlen)
			sizeof(real));
		e_wsfe();
/* SOURCE timeman.for:381 */
/*<       stop'Abnormal stop: time step too small.' >*/
		s_stop(const_cast<char*>("Abnormal stop: time step too small."), (ftnlen)35);
/* SOURCE timeman.for:383 */
/*<       endif >*/
	    }
/* SOURCE timeman.for:385 */
/*<       time=time+dt >*/
	    xscom_1.time += *dt;
/* SOURCE timeman.for:386 */
/*<       calltiminc(dt,jtime,yr,mn,dy,dyfrac,leap) >*/
	    timinc_(dt, &julian_1.jtime, &julian_1.yr, &julian_1.mn, &
		    julian_1.dy, &julian_1.dyfrac, &julian_1.leap);
/* SOURCE timeman.for:389 */
/*<       endif >*/
	}
/* SOURCE timeman.for:390 */
/*<       else >*/
    } else {
/*         CLEAR THE TIME ADJUSTMENT FLAG */
/* SOURCE timeman.for:394 */
/*<       tflag=0 >*/
	tflag = 0;
/* SOURCE timeman.for:395 */
/*<       dt_adjust=tflag >*/
	*feq_gen_dt_adjust_d_ = tflag;
/*         NON-CONVERVENCE ON LAST TIME POINT. */
/*         MOVE BACK ANY OPERATED CONTROL STRUCTURES */
/* SOURCE timeman.for:401 */
/*<       if(nblk.gt.0)then >*/
	if (*nblk > 0) {
/* SOURCE timeman.for:402 */
/*<       dthr=sngl(-dt/3600.d0) >*/
	    dthr = (real) (-(*dt) / 3600.);
/* SOURCE timeman.for:403 */
/*<       calloper(jtime,nblk,opblk,dthr,emc) >*/
	    oper_(&julian_1.jtime, nblk, &opblk[1], &dthr, &emc[1]);
/* SOURCE timeman.for:406 */
/*<       endif >*/
	}
/*         MOVE TIME COUNTERS BACK */
/* SOURCE timeman.for:410 */
/*<       if(ifrz.eq.0)then >*/
	if (*ifrz == 0) {
/* SOURCE timeman.for:411 */
/*<       time=time-dt >*/
	    xscom_1.time -= *dt;
/* SOURCE timeman.for:412 */
/*<       dtt=-dt >*/
	    dtt = -(*dt);
/* SOURCE timeman.for:413 */
/*<       calltiminc(dtt,jtime,yr,mn,dy,dyfrac,leap) >*/
	    timinc_(&dtt, &julian_1.jtime, &julian_1.yr, &julian_1.mn, &
		    julian_1.dy, &julian_1.dyfrac, &julian_1.leap);
/* SOURCE timeman.for:416 */
/*<       endif >*/
	}
/*         DECREASE THE TIME STEP */
/* SOURCE timeman.for:420 */
/*<       dt=dt*lfac >*/
	*dt *= dtcom_1.lfac;
/* SOURCE timeman.for:422 */
/*<       seflag=0 >*/
	*seflag = 0;
/* SOURCE timeman.for:424 */
/*<       wt=wt+dwt >*/
	*wt += dtcom_1.dwt;
/* SOURCE timeman.for:425 */
/*<       if(wt.gt.1.0)wt=1.0 >*/
	if (*wt > (float)1.) {
	    *wt = (float)1.;
	}
/* SOURCE timeman.for:427 */
/*<       if(minprt.eq.0)write(stdout,2100)dt,wt >*/
	if (*minprt == 0) {
	    feq_gen_io_d__32.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__32);
	    do_fio(&feq_gen_c_d_1, (char *)&(*dt), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*wt), (ftnlen)sizeof(real));
	    e_wsfe();
	}
/* SOURCE timeman.for:430 */
/*<       if(dt.lt.mindt)then >*/
	if (*dt < dtcom_1.mindt) {
/*           Close any GENSCN files. -1 signals normal termination */
/* SOURCE timeman.for:432 */
/*<       callgenscn_close(stdout,-1) >*/
	    feq_gen_genscn_close_d_(&xscom_1.stdout, &c_n1);
/* SOURCE timeman.for:433 */
/*<       write(stdout,2110) >*/
	    feq_gen_io_d__33.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__33);
	    e_wsfe();
/* SOURCE timeman.for:434 */
/*<       callnon_conv_summary(stdout,nex,nbn,nbra,brpt) >*/
	    feq_gen_non_conv_summary_d_(&xscom_1.stdout, nex, nbn, nbra, &brpt[9]);
/* SOURCE timeman.for:436 */
/*<       calltimerl(itick1) >*/
	    timerl_(&timcom_1.itick1);
/* SOURCE timeman.for:437 */
/*<       if(itick1.lt.itick0)then >*/
	    if (timcom_1.itick1 < timcom_1.itick0) {
/* SOURCE timeman.for:438 */
/*<       itick1=itick1+100*86400 >*/
		timcom_1.itick1 += 8640000;
/* SOURCE timeman.for:439 */
/*<       endif >*/
	    }
/* SOURCE timeman.for:440 */
/*<       et=float(itick1-itick0)/100.0 >*/
	    et = static_cast<double>((real) (timcom_1.itick1 - timcom_1.itick0)) / (float)100.;
/* SOURCE timeman.for:441 */
/*<       write(stdout,3020)et,et/60.,min_time_step >*/
	    feq_gen_io_d__34.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__34);
	    do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&timcom_1.feq_gen_min_time_step_d_, (ftnlen)sizeof(
		    real));
	    e_wsfe();
/* SOURCE timeman.for:442 */
/*<       write(*,3021)et,et/60.,min_time_step >*/
	    s_wsfe(&feq_gen_io_d__35);
	    do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&timcom_1.feq_gen_min_time_step_d_, (ftnlen)sizeof(
		    real));
	    e_wsfe();
/* SOURCE timeman.for:443 */
/*<       stop'Abnormal stop: time step too small.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: time step too small."), (ftnlen)35);
/* SOURCE timeman.for:445 */
/*<       endif >*/
	}
/* SOURCE timeman.for:447 */
/*<       if(ifrz.eq.0)then >*/
	if (*ifrz == 0) {
/* SOURCE timeman.for:448 */
/*<       time=time+dt >*/
	    xscom_1.time += *dt;
/* SOURCE timeman.for:449 */
/*<       calltiminc(dt,jtime,yr,mn,dy,dyfrac,leap) >*/
	    timinc_(dt, &julian_1.jtime, &julian_1.yr, &julian_1.mn, &
		    julian_1.dy, &julian_1.dyfrac, &julian_1.leap);
/* SOURCE timeman.for:452 */
/*<       endif >*/
	}
/* SOURCE timeman.for:453 */
/*<       endif >*/
    }
/*       CHECK FOR COMPLETION OF RUN ON BASIS OF JTIME */
/* SOURCE timeman.for:457 */
/*<       if(jtime.ge.ejtime)then >*/
    if (julian_1.jtime >= julian_1.ejtime) {
/*         RUN IS COMPLETE */
/* SOURCE timeman.for:462 */
/*<       if(seflag.eq.0)then >*/
	if (*seflag == 0) {
/*           WE HAVE NEVER BEEN HERE OR WE WERE HERE AND THE TIME */
/*           STEP WAS SUBSEQUENTLY REDUCED SO THAT WE WOULD NOT MATCH */
/*           EXACTLY THE END TIME. BACKUP THE TIME KEEPING. */
/* SOURCE timeman.for:467 */
/*<       time=time-dt >*/
	    xscom_1.time -= *dt;
/* SOURCE timeman.for:468 */
/*<       calltiminc(-dt,jtime,yr,mn,dy,dyfrac,leap) >*/
	    feq_gen_d_d_1 = -(*dt);
	    timinc_(&feq_gen_d_d_1, &julian_1.jtime, &julian_1.yr, &julian_1.mn, &
		    julian_1.dy, &julian_1.dyfrac, &julian_1.leap);
/*           RECOMPUTE DT SO THAT WE MATCH EXACTLY */
/* SOURCE timeman.for:473 */
/*<       dt=86400.d0*(ejtime-jtime) >*/
	    *dt = (julian_1.ejtime - julian_1.jtime) * 86400.;
/* SOURCE timeman.for:474 */
/*<       if(minprt.eq.0)write(stdout,2120)dt >*/
	    if (*minprt == 0) {
		feq_gen_io_d__36.ciunit = xscom_1.stdout;
		s_wsfe(&feq_gen_io_d__36);
		do_fio(&feq_gen_c_d_1, (char *)&(*dt), (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
/* SOURCE timeman.for:476 */
/*<       time=time+dt >*/
	    xscom_1.time += *dt;
/* SOURCE timeman.for:477 */
/*<       calltiminc(dt,jtime,yr,mn,dy,dyfrac,leap) >*/
	    timinc_(dt, &julian_1.jtime, &julian_1.yr, &julian_1.mn, &
		    julian_1.dy, &julian_1.dyfrac, &julian_1.leap);
/* SOURCE timeman.for:480 */
/*<       seflag=1 >*/
	    *seflag = 1;
/* SOURCE timeman.for:481 */
/*<       if(abs(dt).lt.0.01)then >*/
	    if (abs(*dt) < (float).01) {
/* SOURCE timeman.for:482 */
/*<       goto100 >*/
		goto L100;
/* SOURCE timeman.for:483 */
/*<       endif >*/
	    }
/* SOURCE timeman.for:484 */
/*<       dt_adjust=tflag >*/
	    *feq_gen_dt_adjust_d_ = tflag;
/* SOURCE timeman.for:485 */
/*<       return >*/
	    return 0;
/* SOURCE timeman.for:486 */
/*<       endif >*/
	}
/* SOURCE timeman.for:489 */
/*<   100 continue >*/
L100:
/* SOURCE timeman.for:492 */
/*<       if(jtime.gt.ejtime)then >*/
	if (julian_1.jtime > julian_1.ejtime) {
/* SOURCE timeman.for:493 */
/*<       dtt=86400.d0*(jtime-ejtime) >*/
	    dtt = (julian_1.jtime - julian_1.ejtime) * 86400.;
/* SOURCE timeman.for:494 */
/*<       time=time-dtt >*/
	    xscom_1.time -= dtt;
/* SOURCE timeman.for:495 */
/*<       calltiminc(-dtt,jtime,yr,mn,dy,dyfrac,leap) >*/
	    feq_gen_d_d_1 = -dtt;
	    timinc_(&feq_gen_d_d_1, &julian_1.jtime, &julian_1.yr, &julian_1.mn, &
		    julian_1.dy, &julian_1.dyfrac, &julian_1.leap);
/* SOURCE timeman.for:498 */
/*<       jtime=ejtime >*/
	    julian_1.jtime = julian_1.ejtime;
/* SOURCE timeman.for:499 */
/*<       endif >*/
	}
/*         MAKE SURE THAT THE TIME STEP IS THE LAST ONE USED */
/*         AND NOT THE LAST ONE SET! */
/* SOURCE timeman.for:505 */
/*<       dt=dtold >*/
	*dt = dtold;
/* SOURCE timeman.for:506 */
/*<       dtdy=dt/86400.d0 >*/
	*dtdy = *dt / 86400.;
/* SOURCE timeman.for:507 */
/*<       wt=wtold >*/
	*wt = wtold;
/* SOURCE timeman.for:509 */
/*<       if(diffus.eq.yes)then >*/
	if (s_cmp(diffus, yes, (ftnlen)4, (ftnlen)4) == 0) {
/*           END OF A SEGMENT. INITIALIZE FOR THE NEXT SEGMENT. */
/*           BFINIT SETS RESET = -1 IF THERE IS NO NEXT SEGMENT IN */
/*           THE TSF. RESET = 1 OTHERWISE. */
/* SOURCE timeman.for:514 */
/*<       if(jtime.ge.vjtime)then >*/
	    if (julian_1.jtime >= julian_1.vjtime) {
/*             WE HAVE REACHED THE GLOBAL ENDING TIME.  SIMULATE */
/*             THE END OF THE TSF TO FORCE SEGEND TO FINISH THE */
/*             THE RUN PROPERLY */
/* SOURCE timeman.for:519 */
/*<       reset=-1 >*/
		julian_1.reset = -1;
/* SOURCE timeman.for:520 */
/*<       else >*/
	    } else {
/* SOURCE timeman.for:521 */
/*<       reset=1 >*/
		julian_1.reset = 1;
/* SOURCE timeman.for:522 */
/*<       callbfinit(dt) >*/
		bfinit_(dt);
/* SOURCE timeman.for:523 */
/*<       endif >*/
	    }
/*           Compute a water balance for the segment just ended. */
/* SOURCE timeman.for:527 */
/*<        >*/
	    feq_gen_find_volumes_d_(nbra, nbn, nex, resnum, &tamcom_1.feq_gen_dlay_knt_d_, &
		    tamcom_1.feq_gen_dten_knt_d_, &brpt[9], &resvec[1], bnelem_1.dxvec,
		     bnelem_1.a2, enelem_1.ae2, bnpond_1.pond2, 
		    bnothr_1.geqvec, bnelem_1.q2, bnelem_1.wxvec2, 
		    bnelem_1.ma2, tamcom_1.feq_gen_dlay_q2_d_, tamcom_1.feq_gen_dlay_k_d_, 
		    tamcom_1.feq_gen_dten_s2_d_, tamcom_1.feq_gen_dten_avda_d_, &s2, &d2);
/* SOURCE timeman.for:533 */
/*<       bal=sngl(s2+bnq+wsq-(s1+bni+taq+wsi)) >*/
	    bal = (real) (s2 + *bnq + *wsq - (*s1 + *bni + *taq + *wsi));
/* SOURCE timeman.for:535 */
/*<       rbal=bal/(s2+bnq) >*/
	    rbal = bal / (s2 + *bnq);
/* SOURCE timeman.for:536 */
/*<       write(stdout,2149) >*/
	    feq_gen_io_d__41.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__41);
	    e_wsfe();
/* SOURCE timeman.for:537 */
/*<       write(stdout,2150)s1,s2,bni,bnq,taq,wsi,wsq >*/
	    feq_gen_io_d__42.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__42);
	    do_fio(&feq_gen_c_d_1, (char *)&(*s1), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&s2, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*bni), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*bnq), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*taq), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*wsi), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*wsq), (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE timeman.for:538 */
/*<       write(stdout,2152)bal,rbal >*/
	    feq_gen_io_d__43.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__43);
	    do_fio(&feq_gen_c_d_1, (char *)&bal, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rbal, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE timeman.for:539 */
/*<       write(stdout,2153)d1,d2,tai,taqbn >*/
	    feq_gen_io_d__44.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__44);
	    do_fio(&feq_gen_c_d_1, (char *)&(*d1), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&d2, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*tai), (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&(*taqbn), (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE timeman.for:540 */
/*<       bal=sngl(d2+taq+taqbn-(d1+tai)) >*/
	    bal = (real) (d2 + *taq + *taqbn - (*d1 + *tai));
/* SOURCE timeman.for:541 */
/*<       rbal=bal/(d2+taq+taqbn+1.0) >*/
	    rbal = bal / (d2 + *taq + *taqbn + (float)1.);
/* SOURCE timeman.for:542 */
/*<       write(stdout,2154)bal,rbal >*/
	    feq_gen_io_d__45.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__45);
	    do_fio(&feq_gen_c_d_1, (char *)&bal, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rbal, (ftnlen)sizeof(real));
	    e_wsfe();
/*           PROCESS THE SEGMENT JUST COMPLETED.  SEGEND DOES NOT */
/*           RETURN IF RESET = -1 */
/* SOURCE timeman.for:549 */
/*<        >*/
	    segend_(&brpt[9], dt, &exnodt[10], fffdsn, nbn, nbra, nodeid, nex,
		     sfac, minprt, hslot, vunit, putdsn, &emc[1], nblk, &
		    opblk[1], wt, &dtcom_1.siter, bnode, qchop, feq_gen_old_summary_d_,
		     feq_gen_dz_for_output_d_, (ftnlen)4, (ftnlen)4);
/*           WRITE THE CONDITIONS AT THE END OF THE DUMMY SEGMENT. */
/*           CURRENT YEAR AND MONTH FOR DUMMY SEGMENT IS MONTH: DMMN */
/*           AND YEAR: DMYEAR */
/* SOURCE timeman.for:559 */
/*<       if(yr.eq.dmyear.and.mn.eq.dmmn)then >*/
	    if (julian_1.yr == julian_1.dmyear && julian_1.mn == 
		    julian_1.dmmn) {
/*              REWIND(BWFDSN) */
/* SOURCE timeman.for:561 */
/*<       bwrec=1 >*/
		bwrec = 1;
/* SOURCE timeman.for:562 */
/*<       callbwput(bwfdsn,wt,nbra,nbn,nex,nblk,opblk,bwrec) >*/
		bwput_(bwfdsn, wt, nbra, nbn, nex, nblk, &opblk[1], &bwrec);
/* SOURCE timeman.for:565 */
/*<       write(std6,*)' BWF BEING WRITTEN: YR=',yr,' MN=',mn >*/
		feq_gen_io_d__46.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsle(&feq_gen_io_d__46);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BWF BEING WRITTEN: YR="), (ftnlen)23);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(
			integer));
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" MN="), (ftnlen)4);
		do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(
			integer));
		e_wsle();
/* SOURCE timeman.for:566 */
/*<       endif >*/
	    }
/* SOURCE timeman.for:568 */
/*<       dt_adjust=tflag >*/
	    *feq_gen_dt_adjust_d_ = tflag;
/* SOURCE timeman.for:569 */
/*<       return >*/
	    return 0;
/* SOURCE timeman.for:570 */
/*<       endif >*/
	}
/* SOURCE timeman.for:572 */
/*<       write(stdout,2000)time >*/
	feq_gen_io_d__47.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__47);
	do_fio(&feq_gen_c_d_1, (char *)&xscom_1.time, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE timeman.for:573 */
/*<       write(stdout,2010) >*/
	feq_gen_io_d__48.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__48);
	e_wsfe();
/*         OUTPUT RESULT AND MAX ELEVATION SUMMARY */
/* SOURCE timeman.for:577 */
/*<       if(output.gt.2)write(stdout,2010) >*/
	if (xscom_1.output > 2) {
	    feq_gen_io_d__49.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__49);
	    e_wsfe();
	}
/* SOURCE timeman.for:578 */
/*<       hr=sngl(24.d0*dyfrac) >*/
	hr = (real) (julian_1.dyfrac * 24.);
/* SOURCE timeman.for:579 */
/*<       write(stdout,2020)yr,mn,dy,hr >*/
	feq_gen_io_d__51.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__51);
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE timeman.for:580 */
/*<        >*/
	resout_(&gravcm_1.grav, vunit, &xscom_1.stdout, nbra, nodeid, nex, &
		xscom_1.time, sfac, &brpt[9], &exnodt[10], qchop, 
		feq_gen_dz_for_output_d_, (ftnlen)4);
/* SOURCE timeman.for:584 */
/*<       write(stdout,2080) >*/
	feq_gen_io_d__52.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__52);
	e_wsfe();
/* SOURCE timeman.for:586 */
/*<       if(old_summary.ne.'YES')then >*/
	if (s_cmp(feq_gen_old_summary_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) != 0) {
/* SOURCE timeman.for:587 */
/*<        >*/
	    zsumry_(&xscom_1.stdout, nbra, nodeid, sfac, &emc[1], &brpt[9], &
		    exnodt[10], nex, hslot, vunit, qchop, feq_gen_dz_for_output_d_, (
		    ftnlen)4);
/* SOURCE timeman.for:591 */
/*<       else >*/
	} else {
/* SOURCE timeman.for:592 */
/*<        >*/
	    feq_gen_zsumry_old_d_(&xscom_1.stdout, nbra, nodeid, sfac, &emc[1], &brpt[
		    9], &exnodt[10], nex, hslot, vunit, qchop, 
		    feq_gen_dz_for_output_d_, (ftnlen)4);
/* SOURCE timeman.for:596 */
/*<       endif >*/
	}
/*         Close time series output files. */
/* SOURCE timeman.for:598 */
/*<       if(nfout.gt.0)callwrquit(stdout,jtime) >*/
	if (wrcom_1.nfout > 0) {
	    wrquit_(&xscom_1.stdout, &julian_1.jtime);
	}
/*         Close time series input files. */
/* SOURCE timeman.for:601 */
/*<       callrdquit(stdout) >*/
	rdquit_(&xscom_1.stdout);
/*         Close any HECDSS files. */
/* SOURCE timeman.for:604 */
/*<       callhecdss_quit(stdout) >*/
	feq_gen_hecdss_quit_d_(&xscom_1.stdout);
/*         Close any special output file and its description file */
/* SOURCE timeman.for:607 */
/*<       callspo_close(stdout) >*/
	feq_gen_spo_close_d_(&xscom_1.stdout);
/*         Close any GENSCN files. 1 signals normal termination */
/* SOURCE timeman.for:610 */
/*<       callgenscn_close(stdout,1) >*/
	feq_gen_genscn_close_d_(&xscom_1.stdout, &feq_gen_c_d_1);
/* SOURCE timeman.for:612 */
/*<       if(putdsn.gt.0)then >*/
	if (*putdsn > 0) {
/*           SAVE THE FINAL CONDITIONS IN A FILE */
/* SOURCE timeman.for:614 */
/*<        >*/
	    putfc_(&xscom_1.stdout, putdsn, namcom_1.putnam, wt, nbra, nbn, 
		    nex, &julian_1.vjtime, nblk, &opblk[1], &dtcom_1.siter, 
		    dt, bnode, &exnodt[10], (ftnlen)256);
/* SOURCE timeman.for:617 */
/*<       endif >*/
	}
/* SOURCE timeman.for:619 */
/*<       callnon_conv_summary(stdout,nex,nbn,nbra,brpt) >*/
	feq_gen_non_conv_summary_d_(&xscom_1.stdout, nex, nbn, nbra, &brpt[9]);
/* SOURCE timeman.for:621 */
/*<       calltimerl(itick1) >*/
	timerl_(&timcom_1.itick1);
/* SOURCE timeman.for:622 */
/*<       if(itick1.lt.itick0)then >*/
	if (timcom_1.itick1 < timcom_1.itick0) {
/* SOURCE timeman.for:623 */
/*<       itick1=itick1+100*86400 >*/
	    timcom_1.itick1 += 8640000;
/* SOURCE timeman.for:624 */
/*<       endif >*/
	}
/* SOURCE timeman.for:625 */
/*<       et=float(itick1-itick0)/100.0 >*/
	et = static_cast<double>((real) (timcom_1.itick1 - timcom_1.itick0)) / (float)100.;
/* SOURCE timeman.for:626 */
/*<       write(stdout,3020)et,et/60.,min_time_step >*/
	feq_gen_io_d__53.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__53);
	do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&timcom_1.feq_gen_min_time_step_d_, (ftnlen)sizeof(real))
		;
	e_wsfe();
/* SOURCE timeman.for:627 */
/*<       write(*,3021)et,et/60.,min_time_step >*/
	s_wsfe(&feq_gen_io_d__54);
	do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&timcom_1.feq_gen_min_time_step_d_, (ftnlen)sizeof(real))
		;
	e_wsfe();
/*          WRITE(STDOUT,3022) FLOAT(CMPEXT)/100. */
/*          WRITE(STDOUT,3023) FLOAT(SLVEXT)/100. */
/*          CLOSE(45) */
/* SOURCE timeman.for:633 */
/*<       stop' Normal stop in MANTIM' >*/
	s_stop(const_cast<char*>(" Normal stop in MANTIM"), (ftnlen)22);
/* SOURCE timeman.for:635 */
/*<       endif >*/
    }
/* SOURCE timeman.for:636 */
/*<       dt_adjust=tflag >*/
    *feq_gen_dt_adjust_d_ = tflag;
/* SOURCE timeman.for:637 */
/*<       return >*/
    return 0;
/* SOURCE timeman.for:638 */
/*<       end >*/
} /* mantim_ */




/* SOURCE timeman.for:642 */
/*<        >*/
/* Subroutine */ int nwdtwt_(real *siter, real *maxdt, real *mindt, real *low,
	 real *high, real *lfac, real *hfac, real *bwt, real *dwt, integer *
	stdout, integer *minprt, doublereal *jtime, doublereal *time, real *
	wt, integer *tflag, doublereal *dt, doublereal *dtdy)
{
    /* Format strings */
    static char fmt_2100[] = "(6x,\002Time step reset to\002,f10.2,\002 se\
c\002,\002 WT = \002,f5.3)";
    static char fmt_2101[] = "(6x,\002Reducing time step to synchronize ti\
me.\002)";

    /* System generated locals */
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double d_mod(doublereal *, doublereal *);

    /* Local variables */
    real df;
    integer ntab;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_2100, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_2100, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_2101, 0 };


/*     + + + PURPOSE + + + */
/*     Adjust time step and time integrating weight factor. */
/* SOURCE timeman.for:651 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE timeman.for:653 */
/*<       integerstdout,minprt,tflag >*/
/* SOURCE timeman.for:654 */
/*<       realbwt,dwt,hfac,high,lfac,low,maxdt,mindt,siter,wt >*/
/* SOURCE timeman.for:655 */
/*<       real*8dt,dtdy,jtime,time >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     SITER  - weighted sum of iterations to convergence */
/*     MAXDT  - maximum time step value in seconds */
/*     MINDT  - minimum value of time step in seconds */
/*     LOW    - lower limit on weighted sum of number of iterations */
/*               to convergence. */
/*     HIGH   - upper limit on weighted sum of number of iterations */
/*               to convergence. */
/*     LFAC   - factor for reducing size of time step */
/*     HFAC   - factor for increasing the time step */
/*     BWT    - base value of the time integrating factor, WT */
/*     DWT    - increment to used in adjusting current value of WT */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     MINPRT - flag to select minimum print out to the user message */
/*               file when DIFFUS=YES */
/*     TIME   - elapsed time in seconds from start of run */
/*     WT     - weight factor for approximating time integrals */
/*     TFLAG  - signal to force maximum type step */
/*     DT     - time step in seconds */
/* INCLUDE timeman.for:677 */
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
/*     + + + INTRINSICS + + + */
/* SOURCE timeman.for:680 */
/*<       intrinsicdble,mod >*/
/*     Local */
/* SOURCE timeman.for:683 */
/*<       integerntab >*/
/* SOURCE timeman.for:684 */
/*<       realdf >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE timeman.for:687 */
/*<  2100 format(6x,'Time step reset to',f10.2,' sec',' WT = ',f5.3) >*/
/* SOURCE timeman.for:688 */
/*<  2101 format(6x,'Reducing time step to synchronize time.') >*/
/* SOURCE timeman.for:689 */
/*<  2110 format(6x,'Time step too samll. RUN TERMINATED.') >*/
/* *********************************************************************** */
/* SOURCE timeman.for:692 */
/*<       if(tab_for_maxdt.gt.0)then >*/
/* L2100: */
/* L2101: */
/* L2110: */
    if (timetab_1.feq_gen_tab_for_maxdt_d_ > 0) {
/* SOURCE timeman.for:693 */
/*<       calllktstab(tab_for_maxdt,jtime,maxdt,ntab,df) >*/
	lktstab_(&timetab_1.feq_gen_tab_for_maxdt_d_, jtime, maxdt, &ntab, &df);
/* SOURCE timeman.for:696 */
/*<       endif >*/
    }
/* SOURCE timeman.for:699 */
/*<       if(siter.le.low)then >*/
    if (*siter <= *low) {
/*       INCREASE THE TIME STEP */
/* SOURCE timeman.for:703 */
/*<       if(tflag.eq.1)then >*/
	if (*tflag == 1) {
/* SOURCE timeman.for:704 */
/*<       dt=maxdt >*/
	    *dt = *maxdt;
/* SOURCE timeman.for:705 */
/*<       tflag=0 >*/
	    *tflag = 0;
/* SOURCE timeman.for:706 */
/*<       endif >*/
	}
/* SOURCE timeman.for:707 */
/*<       dt=dt*hfac >*/
	*dt *= *hfac;
/*        IF(DT.GT.MAXDT) DT = MAXDT */
/*       DECREASE WT */
/* SOURCE timeman.for:712 */
/*<       wt=wt-dwt >*/
	*wt -= *dwt;
/* SOURCE timeman.for:713 */
/*<       if(wt.lt.bwt)wt=bwt >*/
	if (*wt < *bwt) {
	    *wt = *bwt;
	}
/* SOURCE timeman.for:714 */
/*<       if(dt.gt.maxdt)then >*/
	if (*dt > *maxdt) {
/* SOURCE timeman.for:715 */
/*<       dt=maxdt >*/
	    *dt = *maxdt;
/* SOURCE timeman.for:716 */
/*<       else >*/
	} else {
/* SOURCE timeman.for:717 */
/*<       if(minprt.eq.0)write(stdout,2100)dt,wt >*/
	    if (*minprt == 0) {
		feq_gen_io_d__57.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__57);
		do_fio(&feq_gen_c_d_1, (char *)&(*dt), (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&(*wt), (ftnlen)sizeof(real));
		e_wsfe();
	    }
/* SOURCE timeman.for:718 */
/*<       endif >*/
	}
/* SOURCE timeman.for:719 */
/*<       else >*/
    } else {
/* SOURCE timeman.for:720 */
/*<       if(siter.gt.high)then >*/
	if (*siter > *high) {
/*         DECREASE THE TIME STEP */
/* SOURCE timeman.for:724 */
/*<       dt=dt*lfac >*/
	    *dt *= *lfac;
/*         INCREASE WT */
/* SOURCE timeman.for:728 */
/*<       wt=wt+dwt >*/
	    *wt += *dwt;
/* SOURCE timeman.for:729 */
/*<       if(wt.gt.1.0)wt=1.0 >*/
	    if (*wt > (float)1.) {
		*wt = (float)1.;
	    }
/* SOURCE timeman.for:730 */
/*<       if(minprt.eq.0)write(stdout,2100)dt,wt >*/
	    if (*minprt == 0) {
		feq_gen_io_d__58.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__58);
		do_fio(&feq_gen_c_d_1, (char *)&(*dt), (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&(*wt), (ftnlen)sizeof(real));
		e_wsfe();
	    }
/*          IF(DT.LT.MINDT) THEN */
/*           Close any GENSCN files. -1 signals normal termination */
/*            CALL GENSCN_CLOSE(STDOUT, -1) */
/*            WRITE(STDOUT,2110) */
/*            STOP ' Time step too small.' */
/*          ENDIF */
/* SOURCE timeman.for:737 */
/*<       else >*/
	} else {
/*         LEAVE DT UNCHANGED BUT DECREASE WT */
/* SOURCE timeman.for:741 */
/*<       wt=wt-dwt >*/
	    *wt -= *dwt;
/* SOURCE timeman.for:742 */
/*<       if(wt.lt.bwt)wt=bwt >*/
	    if (*wt < *bwt) {
		*wt = *bwt;
	    }
/* SOURCE timeman.for:743 */
/*<       endif >*/
	}
/* SOURCE timeman.for:744 */
/*<       endif >*/
    }
/* SOURCE timeman.for:746 */
/*<       if(dt.eq.maxdt)then >*/
    if (*dt == *maxdt) {
/*       Try to adjust DT to place time at an even multiple */
/*       of MAXDT. */
/* SOURCE timeman.for:749 */
/*<       dt=maxdt-mod(time,dble(maxdt)) >*/
	feq_gen_d_d_1 = (doublereal) (*maxdt);
	*dt = *maxdt - d_mod(time, &feq_gen_d_d_1);
/* SOURCE timeman.for:750 */
/*<       if(dt.le.mindt)then >*/
	if (*dt <= *mindt) {
/* SOURCE timeman.for:751 */
/*<       dt=maxdt >*/
	    *dt = *maxdt;
/* SOURCE timeman.for:752 */
/*<       endif >*/
	}
/* SOURCE timeman.for:753 */
/*<       if(dt.lt.maxdt)then >*/
	if (*dt < *maxdt) {
/* SOURCE timeman.for:754 */
/*<       write(stdout,2101) >*/
	    feq_gen_io_d__59.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__59);
	    e_wsfe();
/* SOURCE timeman.for:755 */
/*<       tflag=1 >*/
	    *tflag = 1;
/* SOURCE timeman.for:756 */
/*<       endif >*/
	}
/* SOURCE timeman.for:757 */
/*<       endif >*/
    }
/* SOURCE timeman.for:759 */
/*<       dtdy=dt/86400.d0 >*/
    *dtdy = *dt / 86400.;
/* SOURCE timeman.for:761 */
/*<       return >*/
    return 0;
/* SOURCE timeman.for:762 */
/*<       end >*/
} /* nwdtwt_ */




/* SOURCE timeman.for:766 */
/*<        >*/
/* Subroutine */ int segend_(integer *feq_storage_brpt, doublereal *dt, integer *feq_storage_exnodt, 
	integer *fffdsn, integer *nbn, integer *nbra, char *nodeid, integer *
	nex, real *sfac, integer *minprt, real *hslot, real *vunit, integer *
	putdsn, integer *feq_storage_emc, integer *nblk, integer *feq_storage_opblk, real *wt, real *
	siter, integer *bnode, real *qchop, char *feq_gen_old_summary_d_, real *
	feq_gen_dz_for_output_d_, ftnlen nodeid_len, ftnlen old_summary_len)
{
    /* Format strings */
    static char fmt_2190[] = "(\0021MAXIMA DURING EVENT\002,\002 ENDING AT\
:\002,/,\002 YEAR/MONTH/DAY:HOUR\002,i5,\002/\002,i3,\002/\002,i3,\002:\002,\
f7.3,\002 JTIME = \002,1pd25.16)";
    static char fmt_2240[] = "(\002 EVENT ENDING AT:\002,i4,\002/\002,i2,\
\002/\002,i2,\002:\002,f7.3,\002 JTIME=\002,f14.6,\002 IS COMPLETED\002)";
    static char fmt_3020[] = "(\002 Total elapsed time=\002,f10.2,\002 secs \
or \002,f10.4,\002 mins\002)";
    static char fmt_3021[] = "(\002 Elapsed time=\002,f9.2,\002 secs \002,f8\
.3,\002 mins\002)";
    static char fmt_3022[] = "(/,\002 Event computation time=\002,f10.2,\002\
 secs or \002,f10.4,\002 mins\002)";
    static char fmt_3030[] = "(\002 Elapsed time=\002,f10.2,\002 secs or \
\002,f10.4,\002 mins\002)";

    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_non_conv_summary_d_(integer *, integer *, 
	    integer *, integer *, integer *), feq_gen_free_unit_d_(integer *, integer *
	    ), feq_gen_spo_close_d_(integer *);
    real et, hr;
    extern /* Subroutine */ int feq_gen_zsumry_old_d_(integer *, integer *, char *, 
	    real *, integer *, integer *, integer *, integer *, real *, real *
	    , real *, real *, ftnlen), feq_gen_hecdss_quit_d_(integer *), 
	    feq_gen_genscn_close_d_(integer *, integer *), putfc_(integer *, integer *,
	     char *, real *, integer *, integer *, integer *, doublereal *, 
	    integer *, integer *, real *, doublereal *, integer *, integer *, 
	    ftnlen), wrquit_(integer *, doublereal *), timerl_(integer *), 
	    rdquit_(integer *), zsumry_(integer *, integer *, char *, real *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , real *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_2190, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_2190, 0 };
    static cilist feq_gen_io_d__63 = { 0, 6, 0, fmt_2240, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_2240, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_3022, 0 };
    static cilist feq_gen_io_d__67 = { 0, 6, 0, fmt_3022, 0 };
    static cilist feq_gen_io_d__68 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__69 = { 0, 0, 0, fmt_3030, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_3020, 0 };
    static cilist feq_gen_io_d__71 = { 0, 6, 0, fmt_3021, 0 };


/*     + + + PURPOSE + + + */
/*     Process the end of a time segment when DIFFUS = YES */
/* SOURCE timeman.for:775 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE timeman.for:777 */
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
/* SOURCE timeman.for:780 */
/*<       integerbnode,fffdsn,minprt,nblk,nbn,nbra,nex,putdsn >*/
/* SOURCE timeman.for:781 */
/*<       integerbrpt(8,nbra),emc(mremc),exnodt(9,nex),opblk(1) >*/
/* SOURCE timeman.for:782 */
/*<       realhslot,qchop,sfac,siter,vunit,wt,dz_for_output >*/
/* SOURCE timeman.for:783 */
/*<       real*8dt >*/
/* SOURCE timeman.for:784 */
/*<       characternodeid*4,old_summary*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
/*     DT     - time step in seconds */
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
/*     FFFDSN - unit number for output of the flood frequency file */
/*     NBN    - total number on nodes on branches in the model */
/*     NBRA   - number of branches in the model */
/*     NODEID - user node identification string */
/*     NEX    - number of exterior nodes in the model */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     MINPRT - flag to select minimum print out to the user message */
/*               file when DIFFUS=YES */
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
/*     VUNIT  - conversion factor for volumes on output */
/*     PUTDSN - unit number for storing final conditions */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     WT     - weight factor for approximating time integrals */
/*     SITER  - weighted sum of iterations to convergence */
/*     BNODE  - boundary node number at which to start defining the */
/*               coefficient matrix */
/*     OLD_SUMMARY - if YES summary of extremes is in pre-version 10 format, */
/*                   otherwise it is in version 10 format. */

/*     QCHOP  - chopping value for output of flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE timeman.for:837 */
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
/* INCLUDE timeman.for:838 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE timeman.for:839 */
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
/* INCLUDE timeman.for:840 */
/* SOURCE timcom.cmn:2 */
/*<        >*/
/* SOURCE timcom.cmn:5 */
/*<       integeritick,itick0,itick1,itick2,cmpext,cmpint,slvext,slvint >*/
/* SOURCE timcom.cmn:8 */
/*<       realmin_time_step >*/
/* INCLUDE timeman.for:841 */
/*     NAMES FOR VARIOUS OPTIONAL FILES AND SPECIAL OUTPUT FILE */
/*     HEADINGS */
/* SOURCE namcom.cmn:5 */
/*<       character*7sphead(mnsout,2) >*/
/* SOURCE namcom.cmn:7 */
/*<       character*256bwfnam,fffnam,tsfnam,putnam,getnam >*/
/* SOURCE namcom.cmn:9 */
/*<       common/namcom/bwfnam,fffnam,tsfnam,sphead,putnam,getnam >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE timeman.for:844 */
/*<       realet,hr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE timeman.for:847 */
/*<       intrinsicfloat,sngl >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE timeman.for:850 */
/*<       externalputfc,wrquit,zsumry,free_unit,non_conv_summary,zsumry_old >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE timeman.for:854 */
/*<  2190  >*/
/* SOURCE timeman.for:857 */
/*<  2240  >*/
/* SOURCE timeman.for:859 */
/*<  3020 format(' Total elapsed time=',f10.2,' secs or ',f10.4,' mins') >*/
/* SOURCE timeman.for:860 */
/*<  3021 format(' Elapsed time=',f9.2,' secs ',f8.3,' mins') >*/
/* SOURCE timeman.for:861 */
/*<  3022  >*/
/* 3024 FORMAT(' Time in computing network matrix=',F10.2,' secs.') */
/* 3025 FORMAT(' Time in solving network matrix=',F10.2,' secs.') */
/* SOURCE timeman.for:865 */
/*<  3030 format(' Elapsed time=',f10.2,' secs or ',f10.4,' mins') >*/
/* *********************************************************************** */
/*         CURRENT TIME SEGMENT IS COMPLETE. THE TIME POINT REQUESTED */
/*         WAS NOT DONE BECAUSE THE END OF TIME SEGMENT WAS */
/*         ENCOUNTERED. THEREFORE, DECREASE TIME. */
/*          TIME = TIME - DT */
/*          CALL TIMINC(-DT, JTIME, YR, MN, DY, DYFRAC, LEAP) */
/* SOURCE timeman.for:873 */
/*<       hr=sngl(24.d0*dyfrac) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    /* Function Body */
/* L2190: */
/* L2240: */
/* L3020: */
/* L3021: */
/* L3022: */
/* L3030: */
    hr = (real) (julian_1.dyfrac * 24.);
/* SOURCE timeman.for:874 */
/*<       if(fffdsn.gt.0)then >*/
    if (*fffdsn > 0) {
/* SOURCE timeman.for:875 */
/*<       write(fffdsn,2190)yr,mn,dy,hr,jtime >*/
	feq_gen_io_d__61.ciunit = *fffdsn;
	s_wsfe(&feq_gen_io_d__61);
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.jtime, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE timeman.for:876 */
/*<       if(old_summary.ne.'YES')then >*/
	if (s_cmp(feq_gen_old_summary_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) != 0) {
/* SOURCE timeman.for:877 */
/*<        >*/
	    zsumry_(fffdsn, nbra, nodeid, sfac, &emc[1], &brpt[9], &exnodt[10]
		    , nex, hslot, vunit, qchop, feq_gen_dz_for_output_d_, (ftnlen)4);
/* SOURCE timeman.for:881 */
/*<       else >*/
	} else {
/* SOURCE timeman.for:882 */
/*<        >*/
	    feq_gen_zsumry_old_d_(fffdsn, nbra, nodeid, sfac, &emc[1], &brpt[9], &
		    exnodt[10], nex, hslot, vunit, qchop, feq_gen_dz_for_output_d_, (
		    ftnlen)4);
/* SOURCE timeman.for:886 */
/*<       endif >*/
	}
/* SOURCE timeman.for:887 */
/*<       endif >*/
    }
/* SOURCE timeman.for:888 */
/*<       if(minprt.eq.0)then >*/
    if (*minprt == 0) {
/* SOURCE timeman.for:889 */
/*<       write(stdout,2190)yr,mn,dy,hr,jtime >*/
	feq_gen_io_d__62.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.jtime, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE timeman.for:890 */
/*<       if(old_summary.ne.'YES')then >*/
	if (s_cmp(feq_gen_old_summary_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) != 0) {
/* SOURCE timeman.for:891 */
/*<        >*/
	    zsumry_(&xscom_1.stdout, nbra, nodeid, sfac, &emc[1], &brpt[9], &
		    exnodt[10], nex, hslot, vunit, qchop, feq_gen_dz_for_output_d_, (
		    ftnlen)4);
/* SOURCE timeman.for:895 */
/*<       else >*/
	} else {
/* SOURCE timeman.for:896 */
/*<        >*/
	    feq_gen_zsumry_old_d_(&xscom_1.stdout, nbra, nodeid, sfac, &emc[1], &brpt[
		    9], &exnodt[10], nex, hslot, vunit, qchop, 
		    feq_gen_dz_for_output_d_, (ftnlen)4);
/* SOURCE timeman.for:900 */
/*<       endif >*/
	}
/* SOURCE timeman.for:901 */
/*<       endif >*/
    }
/* SOURCE timeman.for:904 */
/*<       if(minprt.eq.1.or.minprt.eq.2)then >*/
    if (*minprt == 1 || *minprt == 2) {
/* SOURCE timeman.for:905 */
/*<       write(*,2240)yr,mn,dy,hr,jtime >*/
	s_wsfe(&feq_gen_io_d__63);
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.jtime, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE timeman.for:906 */
/*<       write(stdout,2240)yr,mn,dy,hr,jtime >*/
	feq_gen_io_d__64.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__64);
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&julian_1.jtime, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE timeman.for:907 */
/*<       endif >*/
    }
/*         COMPUTE THE EVENT COMPUTATION TIME */
/* SOURCE timeman.for:911 */
/*<       calltimerl(itick1) >*/
    timerl_(&timcom_1.itick1);
/* SOURCE timeman.for:912 */
/*<       if(itick1.lt.itick0)then >*/
    if (timcom_1.itick1 < timcom_1.itick0) {
/* SOURCE timeman.for:913 */
/*<       itick1=itick1+100*86400 >*/
	timcom_1.itick1 += 8640000;
/* SOURCE timeman.for:914 */
/*<       endif >*/
    }
/* SOURCE timeman.for:915 */
/*<       et=float(itick1-itick0)/100.0 >*/
    et = static_cast<double>((real) (timcom_1.itick1 - timcom_1.itick0)) / (float)100.;
/* SOURCE timeman.for:916 */
/*<       write(stdout,3022)et,et/60. >*/
    feq_gen_io_d__66.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__66);
    do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
    feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE timeman.for:917 */
/*<       write(*,3022)et,et/60. >*/
    s_wsfe(&feq_gen_io_d__67);
    do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
    feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE timeman.for:918 */
/*<       write(*,*)' ' >*/
    s_wsle(&feq_gen_io_d__68);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE timeman.for:919 */
/*<       et=float(itick1-itick)/100.0 >*/
    et = static_cast<double>((real) (timcom_1.itick1 - timcom_1.itick)) / (float)100.;
/* SOURCE timeman.for:920 */
/*<       write(stdout,3030)et,et/60. >*/
    feq_gen_io_d__69.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__69);
    do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
    feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE timeman.for:921 */
/*<       itick0=itick1 >*/
    timcom_1.itick0 = timcom_1.itick1;
/* SOURCE timeman.for:924 */
/*<       if(reset.lt.0)then >*/
    if (julian_1.reset < 0) {
/* SOURCE timeman.for:926 */
/*<       if(fffdsn.gt.0)callfree_unit(stdout,fffdsn) >*/
	if (*fffdsn > 0) {
	    feq_gen_free_unit_d_(&xscom_1.stdout, fffdsn);
	}
/*           CLOSE ANY OUTPUT PTSF FILES. MUST WRITE THE TERMINATING */
/*           RECORD */
/* SOURCE timeman.for:931 */
/*<       if(nfout.gt.0)callwrquit(stdout,jtime) >*/
	if (wrcom_1.nfout > 0) {
	    wrquit_(&xscom_1.stdout, &julian_1.jtime);
	}
/*           Close any time series input files. */
/* SOURCE timeman.for:934 */
/*<       callrdquit(stdout) >*/
	rdquit_(&xscom_1.stdout);
/*           Close any HECDSS files */
/* SOURCE timeman.for:937 */
/*<       callhecdss_quit(stdout) >*/
	feq_gen_hecdss_quit_d_(&xscom_1.stdout);
/*           Close any GENSCN files. 1 signals normal termination */
/* SOURCE timeman.for:940 */
/*<       callgenscn_close(stdout,1) >*/
	feq_gen_genscn_close_d_(&xscom_1.stdout, &feq_gen_c_d_1);
/*           Close any special output file and its description file */
/* SOURCE timeman.for:943 */
/*<       callspo_close(stdout) >*/
	feq_gen_spo_close_d_(&xscom_1.stdout);
/* SOURCE timeman.for:945 */
/*<       if(putdsn.gt.0)then >*/
	if (*putdsn > 0) {
/*             SAVE FINAL CONDITION TO FILE */
/* SOURCE timeman.for:947 */
/*<        >*/
	    putfc_(&xscom_1.stdout, putdsn, namcom_1.putnam, wt, nbra, nbn, 
		    nex, &julian_1.vjtime, nblk, &opblk[1], siter, dt, bnode, 
		    &exnodt[10], (ftnlen)256);
/* SOURCE timeman.for:950 */
/*<       endif >*/
	}
/* SOURCE timeman.for:952 */
/*<       callnon_conv_summary(stdout,nex,nbn,nbra,brpt) >*/
	feq_gen_non_conv_summary_d_(&xscom_1.stdout, nex, nbn, nbra, &brpt[9]);
/*           COMPUTE TOTAL COMPUTATION TIME */
/* SOURCE timeman.for:955 */
/*<       calltimerl(itick1) >*/
	timerl_(&timcom_1.itick1);
/* SOURCE timeman.for:956 */
/*<       if(itick1.lt.itick0)then >*/
	if (timcom_1.itick1 < timcom_1.itick0) {
/* SOURCE timeman.for:957 */
/*<       itick1=itick1+100*86400 >*/
	    timcom_1.itick1 += 8640000;
/* SOURCE timeman.for:958 */
/*<       endif >*/
	}
/* SOURCE timeman.for:959 */
/*<       et=float(itick1-itick)/100.0 >*/
	et = static_cast<double>((real) (timcom_1.itick1 - timcom_1.itick)) / (float)100.;
/* SOURCE timeman.for:960 */
/*<       write(stdout,3020)et,et/60. >*/
	feq_gen_io_d__70.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__70);
	do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE timeman.for:961 */
/*<       write(*,3021)et,et/60. >*/
	s_wsfe(&feq_gen_io_d__71);
	do_fio(&feq_gen_c_d_1, (char *)&et, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(et) / (float)60.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/*            WRITE(STDOUT,3024) FLOAT(CMPEXT)/100. */
/*            WRITE(STDOUT,3025) FLOAT(SLVEXT)/100. */
/* SOURCE timeman.for:966 */
/*<       stop'Normal stop in SEGEND' >*/
	s_stop(const_cast<char*>("Normal stop in SEGEND"), (ftnlen)21);
/* SOURCE timeman.for:967 */
/*<       endif >*/
    }
/* SOURCE timeman.for:969 */
/*<       return >*/
    return 0;
/* SOURCE timeman.for:971 */
/*<       end >*/
} /* segend_ */




/* SOURCE timeman.for:975 */
/*<       subroutinetiminc(dt,jtime,yr,mn,dy,dyfrac,leap) >*/
/* Subroutine */ int timinc_(doublereal *dt, doublereal *jtime, integer *yr, 
	integer *mn, integer *dy, doublereal *dyfrac, integer *leap)
{
    /* Initialized data */

    static integer dpm[24]	/* was [12][2] */ = { 31,28,31,30,31,30,31,31,
	    30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };

    doublereal dtemp;
    extern integer lpyear_(integer *);

/*     + + + PURPOSE + + + */
/*     Change the time by DT. ABS(DT) < 1 day. DT in seconds. */
/* SOURCE timeman.for:982 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE timeman.for:984 */
/*<       integerdy,leap,mn,yr >*/
/* SOURCE timeman.for:985 */
/*<       real*8dt,dyfrac,jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     JTIME  - current modified julian time in the model */
/*     YR     - calendar year */
/*     MN     - number of month(1-12) */
/*     DY     - day in the month */
/*     DYFRAC - fraction of day */
/*     LEAP   - flag to signal leap year */
/*     + + + SAVED VALUES + + + */
/* SOURCE timeman.for:997 */
/*<       integerdpm(12,2) >*/
/* SOURCE timeman.for:998 */
/*<       savedpm >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE timeman.for:1001 */
/*<       real*8dtemp >*/
/*     + + + INTRINSICS + + + */
/* SOURCE timeman.for:1004 */
/*<       intrinsicdble >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE timeman.for:1007 */
/*<       integerlpyear >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE timeman.for:1010 */
/*<       externallpyear >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/*     UPDATE THE JULIAN TIME */
/* SOURCE timeman.for:1013 */
/*<        >*/
/* SOURCE timeman.for:1018 */
/*<       dtemp=dble(dt)/86400.d0 >*/
    dtemp = *dt / 86400.;
/* SOURCE timeman.for:1019 */
/*<       jtime=jtime+dtemp >*/
    *jtime += dtemp;
/*     UPDATE THE FRACTION OF THE DAY */
/* SOURCE timeman.for:1023 */
/*<       dyfrac=dyfrac+dtemp >*/
    *dyfrac += dtemp;
/* SOURCE timeman.for:1024 */
/*<       if(dyfrac.ge.0.d0.and.dyfrac.lt.1.d0)return >*/
    if (*dyfrac >= 0. && *dyfrac < 1.) {
	return 0;
    }
/* SOURCE timeman.for:1026 */
/*<       if(dyfrac.lt.0.d0)goto100 >*/
    if (*dyfrac < 0.) {
	goto L100;
    }
/*       UPDATE THE DATE. LEAP MUST BE DEFINED ON ENTRY. */
/* SOURCE timeman.for:1030 */
/*<       dyfrac=dyfrac-1.d0 >*/
    *dyfrac += -1.;
/* SOURCE timeman.for:1031 */
/*<       dy=dy+1 >*/
    ++(*dy);
/* SOURCE timeman.for:1032 */
/*<       if(dy.le.dpm(mn,leap))return >*/
    if (*dy <= dpm[*mn + *leap * 12 - 13]) {
	return 0;
    }
/* SOURCE timeman.for:1033 */
/*<       dy=1 >*/
    *dy = 1;
/* SOURCE timeman.for:1034 */
/*<       mn=mn+1 >*/
    ++(*mn);
/* SOURCE timeman.for:1035 */
/*<       if(mn.le.12)return >*/
    if (*mn <= 12) {
	return 0;
    }
/* SOURCE timeman.for:1036 */
/*<       mn=1 >*/
    *mn = 1;
/* SOURCE timeman.for:1037 */
/*<       yr=yr+1 >*/
    ++(*yr);
/* SOURCE timeman.for:1038 */
/*<       leap=lpyear(yr) >*/
    *leap = lpyear_(yr);
/* SOURCE timeman.for:1039 */
/*<       return >*/
    return 0;
/* SOURCE timeman.for:1041 */
/*<   100 continue >*/
L100:
/*       DECREMENT HERE. */
/* SOURCE timeman.for:1045 */
/*<       dyfrac=dyfrac+1.d0 >*/
    *dyfrac += 1.;
/* SOURCE timeman.for:1046 */
/*<       dy=dy-1 >*/
    --(*dy);
/* SOURCE timeman.for:1047 */
/*<       if(dy.ge.1)return >*/
    if (*dy >= 1) {
	return 0;
    }
/* SOURCE timeman.for:1048 */
/*<       mn=mn-1 >*/
    --(*mn);
/* SOURCE timeman.for:1049 */
/*<       if(mn.lt.1)goto200 >*/
    if (*mn < 1) {
	goto L200;
    }
/* SOURCE timeman.for:1050 */
/*<       dy=dpm(mn,leap) >*/
    *dy = dpm[*mn + *leap * 12 - 13];
/* SOURCE timeman.for:1051 */
/*<       return >*/
    return 0;
/* SOURCE timeman.for:1052 */
/*<   200 continue >*/
L200:
/* SOURCE timeman.for:1053 */
/*<       dy=31 >*/
    *dy = 31;
/* SOURCE timeman.for:1054 */
/*<       mn=12 >*/
    *mn = 12;
/* SOURCE timeman.for:1055 */
/*<       yr=yr-1 >*/
    --(*yr);
/* SOURCE timeman.for:1056 */
/*<       leap=lpyear(yr) >*/
    *leap = lpyear_(yr);
/* SOURCE timeman.for:1057 */
/*<       return >*/
    return 0;
/* SOURCE timeman.for:1058 */
/*<       end >*/
} /* timinc_ */

#ifdef __cplusplus
	}
#endif
