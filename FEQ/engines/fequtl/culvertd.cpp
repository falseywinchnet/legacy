#include <feq/steady_residual.hpp>
#include <feq/steady_residual.hpp>
#include <feq/approach_residual.hpp>
#include <feq/culvert_loss.hpp>
#include "callbacks.hpp"
/* culvertd.f -- translated by f2c (version 20240504).
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

/* COMMON ndrsdc_ is declared in common.hpp. */

#define ndrsdc_1 ndrsdc_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON crqrec_ is declared in common.hpp. */

#define crqrec_1 crqrec_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON cdcom_ is declared in common.hpp. */

#define cdcom_1 cdcom_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* COMMON xs2com_ is declared in common.hpp. */

#define xs2com_1 xs2com_

/* COMMON xs3com_ is declared in common.hpp. */

#define xs3com_1 xs3com_

/* COMMON culcom_ is declared in common.hpp. */

#define culcom_1 culcom_

/* COMMON xs4com_ is declared in common.hpp. */

#define xs4com_1 xs4com_

/* COMMON depmc_ is declared in common.hpp. */

#define depmc_1 depmc_

/* COMMON x44com_ is declared in common.hpp. */

#define x44com_1 x44com_

/* COMMON xs1com_ is declared in common.hpp. */

#define xs1com_1 xs1com_

/* COMMON appcom_ is declared in common.hpp. */

#define appcom_1 appcom_

/* COMMON rappc_ is declared in common.hpp. */

#define rappc_1 rappc_

/* COMMON rconc_ is declared in common.hpp. */

#define rconc_1 rconc_

/* COMMON dpm26c_ is declared in common.hpp. */

#define dpm26c_1 dpm26c_

/* COMMON rrovdc_ is declared in common.hpp. */

#define rrovdc_1 rrovdc_

/* COMMON typlim_ is declared in common.hpp. */

#define typlim_1 typlim_

/* COMMON x43com_ is declared in common.hpp. */

#define x43com_1 x43com_

/* COMMON typtrn_ is declared in common.hpp. */

#define typtrn_1 typtrn_

/* COMMON rdfcom_ is declared in common.hpp. */

#define rdfcom_1 rdfcom_

/* COMMON rqvtw_ is declared in common.hpp. */

#define rqvtw_1 rqvtw_

/* COMMON rqvtc_ is declared in common.hpp. */

#define rqvtc_1 rqvtc_

/* COMMON rty0c_ is declared in common.hpp. */

#define rty0c_1 rty0c_

/* COMMON rty0cc_ is declared in common.hpp. */

#define rty0cc_1 rty0cc_

/* COMMON rty2c_ is declared in common.hpp. */

#define rty2c_1 rty2c_

/* COMMON rty2cc_ is declared in common.hpp. */

#define rty2cc_1 rty2cc_

/* COMMON embcmc_ is declared in common.hpp. */

#define embcmc_1 embcmc_

/* COMMON embcom_ is declared in common.hpp. */

#define embcom_1 embcom_

/* COMMON embq_ is declared in common.hpp. */

#define embq_1 embq_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static real c_b45 = (float)0.;
static doublereal c_b51 = .3333333;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_4 = 4;
static doublereal c_b78 = 2.5;
static doublereal c_b79 = .80925;
static doublereal c_b80 = 1.546;
static integer feq_gen_c_d_10 = 10;
static real c_b179 = (float)1e-6;
static integer feq_gen_c_d_3 = 3;




/* SOURCE culvertd.for:4 */
/*<       realfunctionndrsd(y) >*/
doublereal ndrsd_(real *y)
{
    // Preserve the private lookup copy: LKTK may clamp YLOC, not the root argument.
    float yloc = *y;
    float k;
    extern int lktk_(int*,float*,float*);
    lktk_(&ndrsdc_1.adr,&yloc,&k);
    return feq::normal_flow_residual(ndrsdc_1.rtsbot,k,ndrsdc_1.flow);
} /* ndrsd_ */




/* SOURCE culvertd.for:42 */
/*<       subroutinefndnd(stdout,adrs,q,sbot,d,ye) >*/
/* Subroutine */ int fndnd_(integer *stdout, integer *adrs, real *q, real *
	sbot, real *feq_gen_d_d_, real *ye)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:625* TABID=\002,a,\002 overflow seeki\
ng norm. depth for\002,\002 flow=\002,f10.2,11x,\002 Table MaxArg=\002,f10.2)"
	    ;
    static char fmt_52[] = "(\002 *ERR:626* TABID=\002,a,\002 underflow seek\
ing norm. depth for\002,\002 flow=\002,f10.3)";
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 FNDND.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT ITERATION>100 IN FNDND\
\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real k, y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real fl, fr, yl, yr;
    integer feq_gen_flag_d_;
    extern /* Subroutine */ int lktk_(integer *, real *, real *);
    real qmax, ymax;
    char tabid[16];
    extern doublereal ndrsd_(real *);
    extern integer gettbn_(integer *);
    extern doublereal fmxarg_(integer *);
    extern /* Subroutine */ int regflt_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Find normal depth for the given bottom slope */
/* SOURCE culvertd.for:50 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:52 */
/*<       integeradrs,stdout >*/
/* SOURCE culvertd.for:53 */
/*<       reald,q,sbot,ye >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     ADRS   - Address of function table */
/*     Q      - Flowrate */
/*     SBOT   - Bottom slope for normal depth */
/*     D      - Maximum vertical extent of a closed conduit */
/*     YE     - Normal depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:64 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertd.for:65 */
/*     Common for function NDRSD in FEQUTL */
/* SOURCE ndrsdc.cmn:3 */
/*<       common/ndrsdc/adr,flow,rtsbot >*/
/* SOURCE ndrsdc.cmn:4 */
/*<       integeradr >*/
/* SOURCE ndrsdc.cmn:5 */
/*<       realflow,rtsbot >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:68 */
/*<       integerflag >*/
/* SOURCE culvertd.for:69 */
/*<       realfl,fr,k,qmax,y,yl,ymax,yr >*/
/* SOURCE culvertd.for:70 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:73 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:76 */
/*<       integergettbn,lenstr >*/
/* SOURCE culvertd.for:77 */
/*<       realfmxarg,ndrsd >*/
/* SOURCE culvertd.for:78 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:81 */
/*<       externalfmxarg,gettbn,lktk,ndrsd,regflt,lenstr,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:84 */
/*<    50  >*/
/* SOURCE culvertd.for:86 */
/*<    52  >*/
/* SOURCE culvertd.for:88 */
/*<    54  >*/
/* SOURCE culvertd.for:90 */
/*<    60 format(' *BUG:XXX* REGFLT ITERATION>100 IN FNDND') >*/
/* *********************************************************************** */
/*     SET THE VALUES FOR THE FUNCTION, NDRSD */
/* SOURCE culvertd.for:93 */
/*<       adr=adrs >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
    ndrsdc_1.adr = *adrs;
/* SOURCE culvertd.for:94 */
/*<       flow=q >*/
    ndrsdc_1.flow = *q;
/* SOURCE culvertd.for:95 */
/*<       rtsbot=sqrt(sbot) >*/
    ndrsdc_1.rtsbot = sqrt(*sbot);
/* SOURCE culvertd.for:96 */
/*<       calllktk(adr,d,k) >*/
    lktk_(&ndrsdc_1.adr, feq_gen_d_d_, &k);
/*     COMPUTE THE MAXIMUM FLOW IN THE CONDUIT FOR THE GIVEN SLOPE */
/* SOURCE culvertd.for:101 */
/*<       qmax=k*rtsbot >*/
    qmax = static_cast<double>(k) * ndrsdc_1.rtsbot;
/*     GET THE MAXIMUM DEPTH IN THE TABLE */
/* SOURCE culvertd.for:104 */
/*<       ymax=fmxarg(adrs) >*/
    ymax = fmxarg_(adrs);
/* SOURCE culvertd.for:105 */
/*<       if(q.ge.qmax)then >*/
    if (*q >= qmax) {
/* SOURCE culvertd.for:106 */
/*<       ye=ymax >*/
	*ye = ymax;
/*       WRITE(STDOUT,*) ' NORMAL DEPTH=',YMAX,' D=',D,' K=',K */
/* SOURCE culvertd.for:108 */
/*<       return >*/
	return 0;
/* SOURCE culvertd.for:109 */
/*<       endif >*/
    }
/*     SEARCH FOR A POSITIVE RESIDUAL */
/* SOURCE culvertd.for:112 */
/*<       yr=ye >*/
    yr = *ye;
/* SOURCE culvertd.for:113 */
/*<       yl=-1.0 >*/
    yl = (float)-1.;
/* SOURCE culvertd.for:114 */
/*<   100 continue >*/
L100:
/* SOURCE culvertd.for:115 */
/*<       fr=ndrsd(yr) >*/
    fr = ndrsd_(&yr);
/* SOURCE culvertd.for:116 */
/*<       if(fr.ge.0.0)then >*/
    if (fr >= (float)0.) {
/* SOURCE culvertd.for:117 */
/*<       goto110 >*/
	goto L110;
/* SOURCE culvertd.for:118 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:119 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE culvertd.for:120 */
/*<       fl=fr >*/
	fl = fr;
/* SOURCE culvertd.for:121 */
/*<       if(abs(fr).lt.epsf)then >*/
	if (dabs(fr) < epscom_1.epsf) {
/* SOURCE culvertd.for:122 */
/*<       yr=1.01*yr >*/
	    yr *= static_cast<double>((float)1.01);
/* SOURCE culvertd.for:123 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE culvertd.for:124 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:125 */
/*<       yr=0.7*yr+0.3*d >*/
	    yr = static_cast<double>(static_cast<double>(yr) * (float).7) + static_cast<double>(*feq_gen_d_d_) * (float).3;
/* SOURCE culvertd.for:126 */
/*<       if(abs(yr-ymax).le.epsarg)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(yr) - ymax, dabs(feq_gen_r_d_1)) <= epscom_1.epsarg) {
/* SOURCE culvertd.for:127 */
/*<       tabid=get_tabid(gettbn(adrs)) >*/
		feq_gen_i_d_1 = gettbn_(adrs);
		feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
		s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE culvertd.for:128 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),q,ymax >*/
		feq_gen_io_d__11.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__11);
		do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		do_fio(&feq_gen_c_d_1, (char *)&(*q), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertd.for:129 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:130 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:131 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:132 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertd.for:133 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:134 */
/*<   110 continue >*/
L110:
/*     POSITIVE RESIDUAL FOUND- SEARCH FOR NEGATIVE RESIDUAL */
/* SOURCE culvertd.for:137 */
/*<       if(yl.lt.0.0)then >*/
    if (yl < (float)0.) {
/* SOURCE culvertd.for:138 */
/*<       yl=0.6*yr >*/
	yl = static_cast<double>(yr) * (float).6;
/* SOURCE culvertd.for:139 */
/*<   120 continue >*/
L120:
/* SOURCE culvertd.for:140 */
/*<       fl=ndrsd(yl) >*/
	fl = ndrsd_(&yl);
/* SOURCE culvertd.for:141 */
/*<       if(fl.le.0.0)then >*/
	if (fl <= (float)0.) {
/* SOURCE culvertd.for:142 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE culvertd.for:143 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:144 */
/*<       fr=fl >*/
	    fr = fl;
/* SOURCE culvertd.for:145 */
/*<       yr=yl >*/
	    yr = yl;
/* SOURCE culvertd.for:146 */
/*<       yl=0.6*yl >*/
	    yl *= static_cast<double>((float).6);
/* SOURCE culvertd.for:147 */
/*<       if(abs(yl).lt.1.e-6)then >*/
	    if (dabs(yl) < (float)1e-6) {
/* SOURCE culvertd.for:148 */
/*<       tabid=get_tabid(gettbn(adrs)) >*/
		feq_gen_i_d_1 = gettbn_(adrs);
		feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
		s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE culvertd.for:149 */
/*<       write(stdout,52)tabid(1:lenstr(tabid)),q >*/
		feq_gen_io_d__12.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__12);
		do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		do_fio(&feq_gen_c_d_1, (char *)&(*q), (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertd.for:150 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:151 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:152 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE culvertd.for:153 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:154 */
/*<   130 continue >*/
L130:
/* SOURCE culvertd.for:155 */
/*<       endif >*/
	;
    }
/*     WE HAVE A SIGN CHANGE OR ONE OR BOTH POINTS HAVE ZERO RESIDUAL */
/* SOURCE culvertd.for:158 */
/*<       callregflt(epsarg,epsf,ndrsd,yl,yr,fl,fr,y,flag) >*/
    regflt_(&epscom_1.epsarg, &epscom_1.epsf, ndrsd_, &yl, &yr, &fl, &
	    fr, &y, &feq_gen_flag_d_);
/*      WRITE(STDOUT, 56) YL, Y, YR */
/*      WRITE(STDOUT, 62) FL, FR */
/* SOURCE culvertd.for:166 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertd.for:167 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__15.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__15);
	e_wsfe();
/* SOURCE culvertd.for:168 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:169 */
/*<       elseif(flag.eq.2)then >*/
    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertd.for:170 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__16.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__16);
	e_wsfe();
/* SOURCE culvertd.for:171 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:172 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:174 */
/*<       ye=y >*/
    *ye = y;
/* SOURCE culvertd.for:176 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:177 */
/*<       end >*/
} /* fndnd_ */




/* SOURCE culvertd.for:181 */
/*<       realfunctioncrqre(y) >*/
doublereal crqre_(real *y)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real qc, yloc;
    extern /* Subroutine */ int lktqc_(integer *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Find the critical flow residual at depth Y in the cross */
/*     section and with the flow given in the labeled common block */
/*     using energy principles */
/* SOURCE culvertd.for:189 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:192 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:198 */
/*     Common for function CRQRE in FEQUTL */
/* SOURCE crqrec.cmn:3 */
/*<       common/crqrec/adr,flow,ef >*/
/* SOURCE crqrec.cmn:4 */
/*<       integeradr,ef >*/
/* SOURCE crqrec.cmn:5 */
/*<       realflow >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:201 */
/*<       realqc,yloc >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:204 */
/*<       externallktqc >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:206 */
/*<       yloc=y >*/
    yloc = *y;
/* SOURCE culvertd.for:207 */
/*<       calllktqc(adr,yloc,qc) >*/
    lktqc_(&crqrec_1.adr, &yloc, &qc);
/* SOURCE culvertd.for:212 */
/*<       crqre=(qc-flow)/qc >*/
    ret_val = static_cast<double>((static_cast<double>(qc) - crqrec_1.flow)) / qc;
/*      WRITE(STD6,51) FLOW, QC, Y, CRQRE */
/* SOURCE culvertd.for:216 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:217 */
/*<       end >*/
} /* crqre_ */




/* SOURCE culvertd.for:221 */
/*<       subroutinefndcde(stdout,adrs,q,ye) >*/
/* Subroutine */ int fndcde_(integer *stdout, integer *adrs, real *q, real *
	ye)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:595* TABID=\002,a,\002 overflow seeki\
ng crit. depth for\002,\002 flow=\002,f10.2,11x,\002 Table MaxArg=\002,f10.2)"
	    ;
    static char fmt_52[] = "(\002 *ERR:596* TABID=\002,a,\002 underflow seek\
ing crit. depth for\002,\002 flow=\002,f10.3)";
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT RGF5 CLAI\
MS NONE IN\002,\002 FNDCDE.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* RGF5 TAKES MORE THAN 100 ITERATI\
ONS.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real fl, fr, yl, yr, epf;
    extern /* Subroutine */ int rgf5_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    integer feq_gen_flag_d_;
    real ymax;
    char tabid[16];
    extern doublereal crqre_(real *);
    extern integer gettbn_(integer *);
    extern doublereal fmxarg_(integer *);
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__26 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Find critical depth using energy relationship in the cross */
/*     section at ADRS at the flow Q.  YE contains an estimate */
/*     of the critical depth. */
/* SOURCE culvertd.for:230 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:232 */
/*<       integeradrs,stdout >*/
/* SOURCE culvertd.for:233 */
/*<       realq,ye >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     ADRS   - Address of function table */
/*     Q      - Flowrate */
/*     YE     - Critical depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:242 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertd.for:243 */
/*     Common for function CRQRE in FEQUTL */
/* SOURCE crqrec.cmn:3 */
/*<       common/crqrec/adr,flow,ef >*/
/* SOURCE crqrec.cmn:4 */
/*<       integeradr,ef >*/
/* SOURCE crqrec.cmn:5 */
/*<       realflow >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:246 */
/*<       integerflag >*/
/* SOURCE culvertd.for:247 */
/*<       realepf,fl,fr,y,yl,ymax,yr >*/
/* SOURCE culvertd.for:248 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:251 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:254 */
/*<       integergettbn,lenstr >*/
/* SOURCE culvertd.for:255 */
/*<       realcrqre,fmxarg >*/
/* SOURCE culvertd.for:256 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:259 */
/*<       externalcrqre,fmxarg,gettbn,rgf5,lenstr,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:262 */
/*<    50  >*/
/* SOURCE culvertd.for:264 */
/*<    52  >*/
/* SOURCE culvertd.for:266 */
/*<    54  >*/
/* SOURCE culvertd.for:268 */
/*<    60 format(' *BUG:XXX* RGF5 TAKES MORE THAN 100 ITERATIONS.') >*/
/* *********************************************************************** */
/*     SET THE VALUES FOR THE FUNCTION, CRQRE */
/* SOURCE culvertd.for:271 */
/*<       adr=adrs >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
    crqrec_1.adr = *adrs;
/* SOURCE culvertd.for:272 */
/*<       flow=q >*/
    crqrec_1.flow = *q;
/* SOURCE culvertd.for:273 */
/*<       ef=0 >*/
    crqrec_1.ef = 0;
/* SOURCE culvertd.for:275 */
/*<       epf=epsf >*/
    epf = epscom_1.epsf;
/*     GET THE MAXIMUM DEPTH IN THE TABLE */
/* SOURCE culvertd.for:277 */
/*<       ymax=fmxarg(adrs) >*/
    ymax = fmxarg_(adrs);
/*     SEARCH FOR A POSITIVE RESIDUAL */
/* SOURCE culvertd.for:280 */
/*<       yr=ye >*/
    yr = *ye;
/* SOURCE culvertd.for:281 */
/*<       yl=-1 >*/
    yl = (float)-1.;
/* SOURCE culvertd.for:282 */
/*<   100 continue >*/
L100:
/* SOURCE culvertd.for:283 */
/*<       fr=crqre(yr) >*/
    fr = crqre_(&yr);
/* SOURCE culvertd.for:284 */
/*<       if(fr.ge.0.0)then >*/
    if (fr >= (float)0.) {
/* SOURCE culvertd.for:285 */
/*<       goto110 >*/
	goto L110;
/* SOURCE culvertd.for:286 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:287 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE culvertd.for:288 */
/*<       fl=fr >*/
	fl = fr;
/* SOURCE culvertd.for:289 */
/*<       if(abs(fr).lt.epsf)then >*/
	if (dabs(fr) < epscom_1.epsf) {
/* SOURCE culvertd.for:290 */
/*<       yr=1.01*yr >*/
	    yr *= static_cast<double>((float)1.01);
/* SOURCE culvertd.for:291 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE culvertd.for:292 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:293 */
/*<       yr=0.9*yr+0.1*ymax >*/
	    yr = static_cast<double>(static_cast<double>(yr) * (float).9) + static_cast<double>(ymax) * (float).1;
/* SOURCE culvertd.for:294 */
/*<       if(abs(yr-ymax)/ymax.le.1.e-6)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(yr) - ymax, dabs(feq_gen_r_d_1)) / ymax <= (float)1e-6) {
/* SOURCE culvertd.for:295 */
/*<       tabid=get_tabid(gettbn(adrs)) >*/
		feq_gen_i_d_1 = gettbn_(adrs);
		feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
		s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE culvertd.for:296 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),q,ymax >*/
		feq_gen_io_d__26.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__26);
		do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		do_fio(&feq_gen_c_d_1, (char *)&(*q), (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertd.for:297 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:298 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:299 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:300 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertd.for:301 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:302 */
/*<   110 continue >*/
L110:
/*     POSITIVE RESIDUAL FOUND- SEARCH FOR NEGATIVE RESIDUAL */
/* SOURCE culvertd.for:305 */
/*<       if(yl.lt.0.0)then >*/
    if (yl < (float)0.) {
/* SOURCE culvertd.for:306 */
/*<       yl=0.5*ye >*/
	yl = static_cast<double>(*ye) * (float).5;
/* SOURCE culvertd.for:307 */
/*<   120 continue >*/
L120:
/* SOURCE culvertd.for:308 */
/*<       fl=crqre(yl) >*/
	fl = crqre_(&yl);
/* SOURCE culvertd.for:309 */
/*<       if(fl.le.0.0)then >*/
	if (fl <= (float)0.) {
/* SOURCE culvertd.for:310 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE culvertd.for:311 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:312 */
/*<       fr=fl >*/
	    fr = fl;
/* SOURCE culvertd.for:313 */
/*<       yr=yl >*/
	    yr = yl;
/* SOURCE culvertd.for:314 */
/*<       yl=0.5*yl >*/
	    yl *= static_cast<double>((float).5);
/* SOURCE culvertd.for:315 */
/*<       if(abs(yl).lt.epsabs)then >*/
	    if (dabs(yl) < epscom_1.epsabs) {
/* SOURCE culvertd.for:316 */
/*<       tabid=get_tabid(gettbn(adrs)) >*/
		feq_gen_i_d_1 = gettbn_(adrs);
		feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
		s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE culvertd.for:317 */
/*<       write(stdout,52)tabid(1:lenstr(tabid)),q >*/
		feq_gen_io_d__27.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__27);
		do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		do_fio(&feq_gen_c_d_1, (char *)&(*q), (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertd.for:318 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:319 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:320 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE culvertd.for:321 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:322 */
/*<   130 continue >*/
L130:
/* SOURCE culvertd.for:323 */
/*<       endif >*/
	;
    }
/*     WE HAVE A SIGN CHANGE OR ONE OR BOTH POINTS HAVE ZERO RESIDUAL */
/*     FORCE CONVERGENCE ON RESIDUAL ONLY. */
/*      WRITE(STDOUT,*) ' FNDCDE: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE culvertd.for:330 */
/*<       callrgf5(0.0,epf,crqre,yl,yr,fl,fr,y,flag) >*/
    rgf5_(&c_b45, &epf, crqre_, &yl, &yr, &fl, &fr, &y, &feq_gen_flag_d_);
/*      WRITE(STDOUT, 56) YL, Y, YR, Q */
/* SOURCE culvertd.for:337 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertd.for:338 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__30.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__30);
	e_wsfe();
/* SOURCE culvertd.for:339 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:340 */
/*<       elseif(flag.eq.2)then >*/
    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertd.for:341 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__31.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__31);
	e_wsfe();
/* SOURCE culvertd.for:342 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:343 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:345 */
/*<       ye=y >*/
    *ye = y;
/* SOURCE culvertd.for:347 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:348 */
/*<       end >*/
} /* fndcde_ */




/* SOURCE culvertd.for:352 */
/*<       realfunctioninvse(q,e,y) >*/
doublereal invse_(real *q, real *e, real *y)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 More than 100 iterations in INVSE. Q=\
\002,f13.3,\002 E=\002,f10.4,/,5x,\002Y=\002,f10.4,\002 F=\002,f10.4,\002 DY=\
\002,f10.3,\002 YC=\002,f10.4)";

    /* System generated locals */
    real ret_val, feq_gen_r_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real f, fp, yc, dy, yt;
    integer knt;
    real emin, qsqr, vsqr;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__37 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the inverse of the unit width specific energy seeking */
/*     a subcritical solution.  INVSE assumes that a subcritical solution */
/*     exists. */
/* SOURCE culvertd.for:360 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:363 */
/*<       reale,q,y >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Q      - Flowrate */
/*     E      - Specific energy value. */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:371 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:372 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:375 */
/*<       integerknt >*/
/* SOURCE culvertd.for:376 */
/*<       realdy,emin,f,fp,qsqr,vsqr,yc,yt >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:379 */
/*<       intrinsicabs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:382 */
/*<    50  >*/
/* *********************************************************************** */
/*      WRITE(STD6,*) ' INVSE: Q=',Q,' E=',E,' Y=',Y */
/* SOURCE culvertd.for:388 */
/*<       qsqr=q*q >*/
/* L50: */
    qsqr = static_cast<double>(*q) * *q;
/* SOURCE culvertd.for:389 */
/*<       yc=(qsqr/grav)**0.3333333 >*/
    feq_gen_d_d_1 = (doublereal) (static_cast<double>(qsqr) / grvcom_1.grav);
    yc = pow_dd(&feq_gen_d_d_1, &c_b51);
/* SOURCE culvertd.for:390 */
/*<       emin=yc+qsqr/(grav2*yc*yc) >*/
    emin = static_cast<double>(yc) + static_cast<double>(qsqr) / (static_cast<double>(static_cast<double>(grvcom_1.grav2) * yc) * yc);
/* SOURCE culvertd.for:391 */
/*<       if(e.lt.emin)then >*/
    if (*e < emin) {
/*       No solution exists.  Return critical depth. */
/* SOURCE culvertd.for:393 */
/*<       invse=yc >*/
	ret_val = yc;
/* SOURCE culvertd.for:394 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertd.for:395 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:396 */
/*<       if(abs(e-emin)/e.lt.1.e-3)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(*e) - emin, dabs(feq_gen_r_d_1)) / *e < (float).001) {
/*       Take critical depth as the solution */
/* SOURCE culvertd.for:398 */
/*<       invse=yc >*/
	ret_val = yc;
/* SOURCE culvertd.for:399 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertd.for:400 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:401 */
/*<       yt=y >*/
    yt = *y;
/* SOURCE culvertd.for:402 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE culvertd.for:403 */
/*<   100 continue >*/
L100:
/* SOURCE culvertd.for:404 */
/*<       if(yt.eq.0.0)then >*/
    if (yt == (float)0.) {
/* SOURCE culvertd.for:405 */
/*<       write(std6,*)' Y=0 IN INVSE. Q=',q,' E=',e >*/
	feq_gen_io_d__37.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__37);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Y=0 IN INVSE. Q="), (ftnlen)17);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*q), (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" E="), (ftnlen)3);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*e), (ftnlen)sizeof(real));
	e_wsle();
/* SOURCE culvertd.for:406 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:407 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:408 */
/*<       vsqr=qsqr/yt**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = yt;
    vsqr = static_cast<double>(qsqr) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE culvertd.for:409 */
/*<       f=yt+vsqr/grav2-e >*/
    f = static_cast<double>(static_cast<double>(yt) + static_cast<double>(vsqr) / grvcom_1.grav2) - *e;
/* SOURCE culvertd.for:410 */
/*<       if(abs(f/e).lt.5.e-4)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(f) / *e, dabs(feq_gen_r_d_1)) < (float)5e-4) {
/* SOURCE culvertd.for:411 */
/*<       invse=yt >*/
	ret_val = yt;
/* SOURCE culvertd.for:412 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertd.for:413 */
/*<       elseif(abs(yt-yc)/yc.lt.0.001)then >*/
    } else if ((feq_gen_r_d_1 = static_cast<double>(yt) - yc, dabs(feq_gen_r_d_1)) / yc < (float).001) {
/* SOURCE culvertd.for:414 */
/*<       invse=yt >*/
	ret_val = yt;
/* SOURCE culvertd.for:415 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertd.for:416 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:417 */
/*<       fp=1.0-vsqr/(yt*grav) >*/
    fp = static_cast<double>((float)1.) - static_cast<double>(vsqr) / (static_cast<double>(yt) * grvcom_1.grav);
/* SOURCE culvertd.for:418 */
/*<       dy=-f/fp >*/
    dy = static_cast<double>(-f) / fp;
/* SOURCE culvertd.for:419 */
/*<       yt=yt+dy >*/
    yt += dy;
/* SOURCE culvertd.for:420 */
/*<       if(yt.lt.yc)then >*/
    if (yt < yc) {
/* SOURCE culvertd.for:421 */
/*<       yt=yt-dy >*/
	yt -= dy;
/* SOURCE culvertd.for:422 */
/*<       yt=0.5*(yt+yc) >*/
	yt = static_cast<double>((static_cast<double>(yt) + yc)) * (float).5;
/* SOURCE culvertd.for:423 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:424 */
/*<       if(abs(dy/yt).lt.1.e-4)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(dy) / yt, dabs(feq_gen_r_d_1)) < (float)1e-4) {
/* SOURCE culvertd.for:425 */
/*<       invse=yt >*/
	    ret_val = yt;
/* SOURCE culvertd.for:426 */
/*<       return >*/
	    return ret_val;
/* SOURCE culvertd.for:427 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:428 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:429 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE culvertd.for:430 */
/*<       if(knt.gt.100)then >*/
    if (knt > 100) {
/* SOURCE culvertd.for:431 */
/*<       write(std6,50)q,e,yt,f,dy,yc >*/
	feq_gen_io_d__42.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__42);
	do_fio(&feq_gen_c_d_1, (char *)&(*q), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&(*e), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&yt, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dy, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&yc, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertd.for:432 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:433 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:434 */
/*<       goto100 >*/
    goto L100;
/* SOURCE culvertd.for:435 */
/*<       end >*/
} /* invse_ */




/* SOURCE culvertd.for:439 */
/*<       realfunctiondegcon(c123,a1,a) >*/
doublereal degcon_(real *c123, real *a1, real *a)
{
    return feq::culvert_contraction(*c123,*a1,*a);
} /* degcon_ */




/* SOURCE culvertd.for:474 */
/*<       subroutinedislss(iu,id,iat3d,iat6d,dup,ty6lss,xvec,sevec) >*/
/* Subroutine */ int dislss_(integer *iu, integer *id, integer *iat3d, 
	integer *iat6d, real *dup, real *ty6lss, real *feq_storage_xvec, real *feq_storage_sevec)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    real s;

/*     + + + PURPOSE + + + */
/*     Distribute the losses for computation of a type 5 profile */
/*     in a culvert. */
/* SOURCE culvertd.for:482 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:485 */
/*<       integeriat3d,iat6d,id,iu >*/
/* SOURCE culvertd.for:486 */
/*<       realdup,sevec(id),ty6lss,xvec(id) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     IAT3D  - index to vena contracta location */
/*     IAT6D  - index to vena contracta location */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     TY6LSS - estimated type 6 loss */
/*     XVEC   - Stations for nodes on a branch or along a culvert */
/*     SEVEC  - vector or slopes that represent eddy losses */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:499 */
/*<       integeri >*/
/* SOURCE culvertd.for:500 */
/*<       reals >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:503 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:505 */
/*<       do122i=iu,id >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> sevec(feq_storage_sevec, 1);

    feq::IndexedPointer<real> xvec(feq_storage_xvec, 1);

    /* Function Body */
    feq_gen_i_d_1 = *id;
    for (feq_gen_i_d_ = *iu; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertd.for:506 */
/*<       sevec(i)=0.0 >*/
	sevec[feq_gen_i_d_] = (float)0.;
/* SOURCE culvertd.for:507 */
/*<   122 continue >*/
/* L122: */
    }
/* SOURCE culvertd.for:509 */
/*<       if(iat6d.gt.0)then >*/
    if (*iat6d > 0) {
/*       Spread the losses over an approximate 3*DUP distance */
/* SOURCE culvertd.for:511 */
/*<       s=ty6lss/(abs(xvec(iat3d)-xvec(iat6d))) >*/
	s = *ty6lss / (feq_gen_r_d_1 = static_cast<double>(xvec[*iat3d]) - xvec[*iat6d], dabs(feq_gen_r_d_1));
/* SOURCE culvertd.for:512 */
/*<       do125i=iat3d+1,iat6d >*/
	feq_gen_i_d_1 = *iat6d;
	for (feq_gen_i_d_ = *iat3d + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertd.for:513 */
/*<       sevec(i)=s >*/
	    sevec[feq_gen_i_d_] = s;
/* SOURCE culvertd.for:514 */
/*<   125 continue >*/
/* L125: */
	}
/* SOURCE culvertd.for:515 */
/*<       else >*/
    } else {
/*       Spread the losses over 3*DUP distance but allow reduction of */
/*       loss because the culvert is so short. */
/* SOURCE culvertd.for:518 */
/*<       s=ty6lss/(3.*dup) >*/
	s = static_cast<double>(*ty6lss) / (static_cast<double>(*dup) * (float)3.);
/* SOURCE culvertd.for:519 */
/*<       do127i=iat3d+1,id >*/
	feq_gen_i_d_1 = *id;
	for (feq_gen_i_d_ = *iat3d + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertd.for:520 */
/*<       sevec(i)=s >*/
	    sevec[feq_gen_i_d_] = s;
/* SOURCE culvertd.for:521 */
/*<   127 continue >*/
/* L127: */
	}
/* SOURCE culvertd.for:522 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:523 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:524 */
/*<       end >*/
} /* dislss_ */




/* SOURCE culvertd.for:528 */
/*<       realfunctionty6rat(q,class,d,aexit) >*/
doublereal ty6rat_(real *q, char *feq_gen_class_d_, real *feq_gen_d_d_, real *aexit, ftnlen 
	class_len)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    real ne, qe, fac, rat;

/*     + + + PURPOSE + + + */
/*     Compute the piezometric level ratio for a type 6 outlet. */
/* SOURCE culvertd.for:534 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:537 */
/*<       realaexit,d,q >*/
/* SOURCE culvertd.for:538 */
/*<       characterclass*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Q      - Flowrate */
/*     CLASS  - Class for culvert shape, BOX, PIPE, .. */
/*     D      - Maximum vertical extent of a closed conduit */
/*     AEXIT  - exit area for the culvert */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:547 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:548 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:551 */
/*<       realne,qe,rat,fac >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:554 */
/*<       intrinsicsqrt >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:556 */
/*<       if(grav.gt.15.0)then >*/
    if (grvcom_1.grav > (float)15.) {
/* SOURCE culvertd.for:557 */
/*<       fac=1.0 >*/
	fac = (float)1.;
/* SOURCE culvertd.for:558 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:559 */
/*<       fac=1.8113089 >*/
	fac = (float)1.8113089;
/* SOURCE culvertd.for:560 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:561 */
/*<       if(class.eq.'BOX')then >*/
    if (s_cmp(feq_gen_class_d_, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) == 0) {
/* SOURCE culvertd.for:562 */
/*<       rat=q/(aexit*sqrt(grav*d)) >*/
	rat = *q / (*aexit * sqrt(static_cast<double>(grvcom_1.grav) * *feq_gen_d_d_));
/* SOURCE culvertd.for:563 */
/*<       if(rat.lt.1.0)then >*/
	if (rat < (float)1.) {
/* SOURCE culvertd.for:564 */
/*<       ty6rat=1.0-0.2*rat >*/
	    ret_val = static_cast<double>((float)1.) - static_cast<double>(rat) * (float).2;
/* SOURCE culvertd.for:565 */
/*<       elseif(rat.lt.5.0)then >*/
	} else if (rat < (float)5.) {
/* SOURCE culvertd.for:566 */
/*<       ty6rat=0.875-0.075*rat >*/
	    ret_val = static_cast<double>((float).875) - static_cast<double>(rat) * (float).075;
/* SOURCE culvertd.for:567 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:568 */
/*<       ty6rat=0.5 >*/
	    ret_val = (float).5;
/* SOURCE culvertd.for:569 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:570 */
/*<       else >*/
    } else {
/*       ALL OTHER CLASSES TREATED LIKE A PIPE CULVERT */
/*       ESTIMATE THE EQUIVALENT NUMBER OF PIPES OF DIAMETER D */
/*       TO ADJUST THE FLOW RATE */
/* SOURCE culvertd.for:575 */
/*<       ne=4.*aexit/(3.1416*d**2) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = *feq_gen_d_d_;
	ne = static_cast<double>(static_cast<double>(*aexit) * (float)4.) / (static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float)3.1416);
/* SOURCE culvertd.for:576 */
/*<       qe=q/ne >*/
	qe = static_cast<double>(*q) / ne;
/* SOURCE culvertd.for:577 */
/*<       rat=fac*qe/d**2.5 >*/
	feq_gen_d_d_1 = (doublereal) (*feq_gen_d_d_);
	rat = static_cast<double>(fac) * qe / pow_dd(&feq_gen_d_d_1, &c_b78);
/* SOURCE culvertd.for:578 */
/*<       if(rat.lt.1.0)rat=1.0 >*/
	if (rat < (float)1.) {
	    rat = (float)1.;
	}
/* SOURCE culvertd.for:580 */
/*<       if(ty6sup.eq.1)then >*/
	if (cdcom_1.ty6sup == 1) {
/*         Discharge is supported. */
/* SOURCE culvertd.for:582 */
/*<       if(rat.le.2.0)then >*/
	    if (rat <= (float)2.) {
/* SOURCE culvertd.for:583 */
/*<       ty6rat=1.0-0.1*(rat-1.0) >*/
		ret_val = static_cast<double>((float)1.) - static_cast<double>((static_cast<double>(rat) - (float)1.)) * (float).1;
/* SOURCE culvertd.for:584 */
/*<       elseif(rat.le.3.0)then >*/
	    } else if (rat <= (float)3.) {
/* SOURCE culvertd.for:585 */
/*<       ty6rat=1.01-0.055*rat >*/
		ret_val = static_cast<double>((float)1.01) - static_cast<double>(rat) * (float).055;
/* SOURCE culvertd.for:586 */
/*<       elseif(rat.le.4.0)then >*/
	    } else if (rat <= (float)4.) {
/* SOURCE culvertd.for:587 */
/*<       ty6rat=1.061-0.0720*rat >*/
		ret_val = static_cast<double>((float)1.061) - static_cast<double>(rat) * (float).072;
/* SOURCE culvertd.for:588 */
/*<       elseif(rat.le.5.0)then >*/
	    } else if (rat <= (float)5.) {
/* SOURCE culvertd.for:589 */
/*<       ty6rat=1.129-0.089*rat >*/
		ret_val = static_cast<double>((float)1.129) - static_cast<double>(rat) * (float).089;
/* SOURCE culvertd.for:590 */
/*<       elseif(rat.le.6.0)then >*/
	    } else if (rat <= (float)6.) {
/* SOURCE culvertd.for:591 */
/*<       ty6rat=0.899-0.043*rat >*/
		ret_val = static_cast<double>((float).899) - static_cast<double>(rat) * (float).043;
/* SOURCE culvertd.for:592 */
/*<       elseif(rat.le.7.0)then >*/
	    } else if (rat <= (float)7.) {
/* SOURCE culvertd.for:593 */
/*<       ty6rat=0.797-0.026*rat >*/
		ret_val = static_cast<double>((float).797) - static_cast<double>(rat) * (float).026;
/* SOURCE culvertd.for:594 */
/*<       elseif(rat.le.8.0)then >*/
	    } else if (rat <= (float)8.) {
/* SOURCE culvertd.for:595 */
/*<       ty6rat=0.72-0.0152364*rat >*/
		ret_val = static_cast<double>((float).72) - static_cast<double>(rat) * (float).0152364;
/* SOURCE culvertd.for:596 */
/*<       else >*/
	    } else {
/* SOURCE culvertd.for:597 */
/*<       ty6rat=0.5+0.52788/rat**0.80925 >*/
		feq_gen_d_d_1 = (doublereal) rat;
		ret_val = (float).52788 / pow_dd(&feq_gen_d_d_1, &c_b79) + (float).5;
/* SOURCE culvertd.for:598 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:599 */
/*<       else >*/
	} else {
/*         Discharge is unsupported. */
/* SOURCE culvertd.for:601 */
/*<       if(rat.le.2.0)then >*/
	    if (rat <= (float)2.) {
/* SOURCE culvertd.for:602 */
/*<       ty6rat=1.058-0.058*rat >*/
		ret_val = static_cast<double>((float)1.058) - static_cast<double>(rat) * (float).058;
/* SOURCE culvertd.for:603 */
/*<       elseif(rat.le.3.0)then >*/
	    } else if (rat <= (float)3.) {
/* SOURCE culvertd.for:604 */
/*<       ty6rat=1.056-0.057*rat >*/
		ret_val = static_cast<double>((float)1.056) - static_cast<double>(rat) * (float).057;
/* SOURCE culvertd.for:605 */
/*<       elseif(rat.le.4.0)then >*/
	    } else if (rat <= (float)4.) {
/* SOURCE culvertd.for:606 */
/*<       ty6rat=1.188-0.101*rat >*/
		ret_val = static_cast<double>((float)1.188) - static_cast<double>(rat) * (float).101;
/* SOURCE culvertd.for:607 */
/*<       elseif(rat.le.5.0)then >*/
	    } else if (rat <= (float)5.) {
/* SOURCE culvertd.for:608 */
/*<       ty6rat=1.240-0.114*rat >*/
		ret_val = static_cast<double>((float)1.24) - static_cast<double>(rat) * (float).114;
/* SOURCE culvertd.for:609 */
/*<       elseif(rat.le.6.0)then >*/
	    } else if (rat <= (float)6.) {
/* SOURCE culvertd.for:610 */
/*<       ty6rat=0.940-0.054*rat >*/
		ret_val = static_cast<double>((float).94) - static_cast<double>(rat) * (float).054;
/* SOURCE culvertd.for:611 */
/*<       elseif(rat.le.7.0)then >*/
	    } else if (rat <= (float)7.) {
/* SOURCE culvertd.for:612 */
/*<       ty6rat=0.808-0.032*rat >*/
		ret_val = static_cast<double>((float).808) - static_cast<double>(rat) * (float).032;
/* SOURCE culvertd.for:613 */
/*<       elseif(rat.le.8.0)then >*/
	    } else if (rat <= (float)8.) {
/* SOURCE culvertd.for:614 */
/*<       ty6rat=0.85-0.038*rat >*/
		ret_val = static_cast<double>((float).85) - static_cast<double>(rat) * (float).038;
/* SOURCE culvertd.for:615 */
/*<       else >*/
	    } else {
/* SOURCE culvertd.for:616 */
/*<       ty6rat=0.5+1.560/rat**1.546 >*/
		feq_gen_d_d_1 = (doublereal) rat;
		ret_val = (float)1.56 / pow_dd(&feq_gen_d_d_1, &c_b80) + (float).5;
/* SOURCE culvertd.for:617 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:618 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:619 */
/*<       endif >*/
    }
/*      WRITE(STD6,*) ' TY6RAT: RAT=',RAT,' Q=',Q,' TY6RAT=',TY6RAT */
/*      WRITE(STD6,*) ' AEXIT=',AEXIT,' D=',D */
/* SOURCE culvertd.for:623 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:624 */
/*<       end >*/
} /* ty6rat_ */




/* SOURCE culvertd.for:628 */
/*<        >*/
doublereal fndszl_(integer *stdout, char *culcls, real *loverd, real *nbar, 
	real *rghfac, real *rbval, integer *tb15ad, integer *feq_storage_tb16ad, ftnlen 
	culcls_len)
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real f, fl;
    integer il;
    real fr;
    integer ir;
    real rdl, rdr, dfdc, dfdr, lovd;
    extern /* Subroutine */ int tdlk10_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *);
    real roverd;

/*     + + + PURPOSE + + + */
/*     Compute the value of the So limit for type 6 flow.  Uses */
/*     Figures 15 and 16 in the USGS TWRI on culvert flows as */
/*     a basis. */
/* SOURCE culvertd.for:637 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:640 */
/*<       integerstdout,tb15ad >*/
/* SOURCE culvertd.for:641 */
/*<       integertb16ad(4) >*/
/* SOURCE culvertd.for:642 */
/*<       realloverd,nbar,rbval,rghfac >*/
/* SOURCE culvertd.for:643 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     LOVERD - ratio of culvert barrel length to vertical diameter */
/*     NBAR   - average Manning's n */
/*     RGHFAC - roughness factor for pipe culverts */
/*     RBVAL  - rounding/beveling value */
/*     TB15AD - address of function table for figure 15 */
/*     TB16AD - addresses of function tables for figure 16 */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:656 */
/*<       integeril,ir >*/
/* SOURCE culvertd.for:657 */
/*<       realdfdc,dfdr,f,fl,fr,lovd,rdl,rdr,roverd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:660 */
/*<       externaltdlk10 >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:662 */
/*<       lovd=loverd >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tb16ad(feq_storage_tb16ad, 1);

    /* Function Body */
    lovd = *loverd;
/* SOURCE culvertd.for:663 */
/*<       if(lovd.gt.500)then >*/
    if (lovd > (float)500.) {
/* SOURCE culvertd.for:664 */
/*<       lovd=500.0 >*/
	lovd = (float)500.;
/* SOURCE culvertd.for:665 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:666 */
/*<       if(culcls.eq.'BOX'.or.nbar.lt.0.019)then >*/
    if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) == 0 || *nbar < (float)
	    .019) {
/*       Take the barrel to be smooth. */
/* SOURCE culvertd.for:669 */
/*<       if(rbval.gt.0.06)then >*/
	if (*rbval > (float).06) {
/* SOURCE culvertd.for:670 */
/*<       roverd=0.06 >*/
	    roverd = (float).06;
/* SOURCE culvertd.for:671 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:672 */
/*<       roverd=rbval >*/
	    roverd = *rbval;
/* SOURCE culvertd.for:673 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:674 */
/*<       calltdlk10(stdout,tb15ad,10,lovd,roverd,f,dfdr,dfdc) >*/
	tdlk10_(stdout, tb15ad, &feq_gen_c_d_10, &lovd, &roverd, &f, &dfdr, &dfdc);
/* SOURCE culvertd.for:677 */
/*<       fndszl=f >*/
	ret_val = f;
/* SOURCE culvertd.for:678 */
/*<       else >*/
    } else {
/*       Take the barrel to be rough.  Select the pair of tables that */
/*       contain the value of rounding and beveling. */
/* SOURCE culvertd.for:681 */
/*<       if(rbval.gt.0.03)then >*/
	if (*rbval > (float).03) {
/* SOURCE culvertd.for:682 */
/*<       roverd=0.03 >*/
	    roverd = (float).03;
/* SOURCE culvertd.for:683 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:684 */
/*<       roverd=rbval >*/
	    roverd = *rbval;
/* SOURCE culvertd.for:685 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:686 */
/*<       if(roverd.le.0.01)then >*/
	if (roverd <= (float).01) {
/* SOURCE culvertd.for:687 */
/*<       ir=2 >*/
	    ir = 2;
/* SOURCE culvertd.for:688 */
/*<       rdr=0.01 >*/
	    rdr = (float).01;
/* SOURCE culvertd.for:689 */
/*<       elseif(roverd.lt.0.02)then >*/
	} else if (roverd < (float).02) {
/* SOURCE culvertd.for:690 */
/*<       ir=3 >*/
	    ir = 3;
/* SOURCE culvertd.for:691 */
/*<       rdr=0.02 >*/
	    rdr = (float).02;
/* SOURCE culvertd.for:692 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:693 */
/*<       ir=4 >*/
	    ir = 4;
/* SOURCE culvertd.for:694 */
/*<       rdr=0.03 >*/
	    rdr = (float).03;
/* SOURCE culvertd.for:695 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:696 */
/*<       il=ir-1 >*/
	il = ir - 1;
/* SOURCE culvertd.for:697 */
/*<       rdl=rdr-0.01 >*/
	rdl = static_cast<double>(rdr) - (float).01;
/* SOURCE culvertd.for:699 */
/*<       calltdlk10(stdout,tb16ad(il),10,lovd,rghfac,fl,dfdr,dfdc) >*/
	tdlk10_(stdout, &tb16ad[il], &feq_gen_c_d_10, &lovd, rghfac, &fl, &dfdr, &dfdc)
		;
/* SOURCE culvertd.for:702 */
/*<       calltdlk10(stdout,tb16ad(ir),10,lovd,rghfac,fr,dfdr,dfdc) >*/
	tdlk10_(stdout, &tb16ad[ir], &feq_gen_c_d_10, &lovd, rghfac, &fr, &dfdr, &dfdc)
		;
/* SOURCE culvertd.for:706 */
/*<       fndszl=fl+(roverd-rdl)*(fr-fl)/(rdr-rdl) >*/
	ret_val = static_cast<double>(fl) + static_cast<double>(static_cast<double>((static_cast<double>(roverd) - rdl)) * (static_cast<double>(fr) - fl)) / (static_cast<double>(rdr) - rdl);
/* SOURCE culvertd.for:707 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:709 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:710 */
/*<       end >*/
} /* fndszl_ */




/* SOURCE culvertd.for:714 */
/*<       realfunctiongetd(adrs,stdout) >*/
doublereal getd_(integer *adrs, integer *stdout)
{
    /* Format strings */
    static char fmt_50[] = "(\0020*ERR:590* TabId: \002,a,\002 is not of \
a\002,\002 closed conduit.\002)";
    static char fmt_52[] = "(\0020*WRN:529* TabId: \002,a,\002 has slot wddt\
h=\002,f7.3,\002.\002,/,11x,\002may not be of a closed conduit.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real ret_val;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real top;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer lowa, xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real diff1, diff2;
    integer higha;
    real topold;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the maximim vertical diameter of the cross section */
/*     given in the table at address adrs. */
/* SOURCE culvertd.for:721 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:724 */
/*<       integeradrs,stdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - Address of function table */
/*     STDOUT - Fortran unit number for user output and messages */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:731 */
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
/* INCLUDE culvertd.for:732 */
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
/* INCLUDE culvertd.for:733 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE culvertd.for:734 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/*     Called program units */
/* SOURCE culvertd.for:737 */
/*<       characterget_tabid*16 >*/
/* SOURCE culvertd.for:738 */
/*<       externalget_tabid >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:741 */
/*<       integerhigha,i,lowa,type,xoff >*/
/* SOURCE culvertd.for:742 */
/*<       realtop,topold,diff1,diff2 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:745 */
/*<    50 format('0*ERR:590* TabId: ',a,' is not of a',' closed conduit.') >*/
/* SOURCE culvertd.for:747 */
/*<    52  >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:750 */
/*<       if(grav.gt.15.0)then >*/
/* L50: */
/* L52: */
    if (grvcom_1.grav > (float)15.) {
/* SOURCE culvertd.for:751 */
/*<       diff1=0.005 >*/
	diff1 = (float).005;
/* SOURCE culvertd.for:752 */
/*<       diff2=0.15 >*/
	diff2 = (float).15;
/* SOURCE culvertd.for:753 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:754 */
/*<       diff1=0.00152 >*/
	diff1 = (float).00152;
/* SOURCE culvertd.for:755 */
/*<       diff2=0.04572 >*/
	diff2 = (float).04572;
/* SOURCE culvertd.for:756 */
/*<       endif >*/
    }
/*     GET THE BOUNDING ADDRESSES FOR THE DEPTH VALUES */
/*      WRITE(STD6,*) ' SEARCHING TABLE#=',ITAB(ADRS+1) */
/* SOURCE culvertd.for:760 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE culvertd.for:761 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE culvertd.for:763 */
/*<       higha=itab(adrs) >*/
    higha = itab[*adrs];
/* SOURCE culvertd.for:764 */
/*<       lowa=adrs+xtioff >*/
    lowa = *adrs + 32;
/*     SCAN THE TOP WIDTH VALUES FROM THE MAXIMUM DEPTH IN THE TABLE */
/*     DOWNWARD UNTIL THE TOP WIDTH INCREASES BY MORE THAN A PRESET */
/*     TOLERANCE. */
/* SOURCE culvertd.for:770 */
/*<       topold=ftab(higha+1) >*/
    topold = ftab[higha + 1];
/* SOURCE culvertd.for:771 */
/*<       do100i=higha-xoff,lowa,-xoff >*/
    feq_gen_i_d_1 = lowa;
    feq_gen_i_d_2 = -xoff;
    for (feq_gen_i_d_ = higha - xoff; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 
	    feq_gen_i_d_2) {
/* SOURCE culvertd.for:772 */
/*<       top=ftab(i+1) >*/
	top = ftab[feq_gen_i_d_ + 1];
/*        WRITE(STD6,*) 'I =',I,' Y=',FTAB(I),' TOP=',TOP,' TOPOLD=',TOPOLD */
/* SOURCE culvertd.for:774 */
/*<       if(top.gt.topold+diff1)then >*/
	if (top > static_cast<double>(topold) + diff1) {
/*         ASSUME THAT TOP OF CONDUIT IS AT TOPOLD */
/* SOURCE culvertd.for:776 */
/*<       if(topold.gt.diff2)then >*/
	    if (topold > diff2) {
/* SOURCE culvertd.for:777 */
/*<       write(stdout,52)itab(adrs+1),topold >*/
		feq_gen_io_d__73.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__73);
		do_fio(&feq_gen_c_d_1, (char *)itab.lease(*adrs + 1).data(), (ftnlen)sizeof(
			integer));
		do_fio(&feq_gen_c_d_1, (char *)&topold, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertd.for:778 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:779 */
/*<       getd=ftab(i+xoff) >*/
	    ret_val = ftab[feq_gen_i_d_ + xoff];
/* SOURCE culvertd.for:780 */
/*<       return >*/
	    return ret_val;
/* SOURCE culvertd.for:781 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:782 */
/*<       topold=top >*/
	topold = top;
/* SOURCE culvertd.for:783 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE culvertd.for:785 */
/*<       write(stdout,50)get_tabid(itab(adrs+1)) >*/
    feq_gen_io_d__74.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__74);
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adrs + 1).data());
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    e_wsfe();
/* SOURCE culvertd.for:786 */
/*<       getd=-1.0 >*/
    ret_val = (float)-1.;
/* SOURCE culvertd.for:787 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:788 */
/*<       end >*/
} /* getd_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE culvertd.for:792 */
/*<       realfunctionyoverd(adr,d,afull,aratio) >*/
doublereal yoverd_(integer *adr, real *feq_gen_d_d_, real *afull, real *aratio)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX No convergence in YOVERD. A=\
\002,f8.3,\002 P=\002,f8.3)";

    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real a, f, p, t, y, al, fp, dt, dy, tl, pt, yl, tr, yr;
    integer knt, low;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer high, xoff, last;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the ratio of depth to vertical height for a closed conduit */
/*     that corresponds to the ratio of area to full area given by */
/*     ARATIO. */
/* SOURCE culvertd.for:800 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:803 */
/*<       integeradr >*/
/* SOURCE culvertd.for:804 */
/*<       realafull,aratio,d >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADR    - Address of function table */
/*     D      - vertical diameter for the culvert barrel */
/*     AFULL  - full area of conduit */
/*     ARATIO - ratio of partial area to full area */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:813 */
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
/* INCLUDE culvertd.for:814 */
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
/* INCLUDE culvertd.for:815 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE culvertd.for:816 */
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
/* INCLUDE culvertd.for:817 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:820 */
/*<       integerhigh,knt,last,low,xoff >*/
/* SOURCE culvertd.for:821 */
/*<       reala,al,dt,dy,f,fp,p,pt,t,tl,tr,y,yl,yr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:824 */
/*<       intrinsicabs,sqrt >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:827 */
/*<    50 format(/,' *BUG:XXX No convergence in YOVERD. A=',f8.3,' P=',f8.3) >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:829 */
/*<       a=afull*aratio >*/
/* L50: */
    a = static_cast<double>(*afull) * *aratio;
/* SOURCE culvertd.for:831 */
/*<       xoff=offvec(itab(adr+2)) >*/
    xoff = offcom_1.offvec[itab[*adr + 2] - 1];
/*     Get the address of the argument last accessed in the table. */
/* SOURCE culvertd.for:833 */
/*<       last=itab(adr+3) >*/
    last = itab[*adr + 3];
/* SOURCE culvertd.for:835 */
/*<       low=adr+xtioff >*/
    low = *adr + 32;
/*     Get the address of the highest argument of the table. */
/* SOURCE culvertd.for:837 */
/*<       high=itab(adr) >*/
    high = itab[*adr];
/*     Adjust addresses to point to the area and not the depth */
/*     in the table. */
/* SOURCE culvertd.for:842 */
/*<       last=last+2 >*/
    last += 2;
/* SOURCE culvertd.for:843 */
/*<       low=low+2 >*/
    low += 2;
/* SOURCE culvertd.for:844 */
/*<       high=high+2 >*/
    high += 2;
/* SOURCE culvertd.for:845 */
/*<       if(a.ge.ftab(last))then >*/
    if (a >= ftab[last]) {
/* SOURCE culvertd.for:846 */
/*<   100 continue >*/
L100:
/* SOURCE culvertd.for:847 */
/*<       if(a.gt.ftab(last+xoff))then >*/
	if (a > ftab[last + xoff]) {
/* SOURCE culvertd.for:848 */
/*<       last=last+xoff >*/
	    last += xoff;
/* SOURCE culvertd.for:849 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE culvertd.for:850 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:851 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:852 */
/*<   110 continue >*/
L110:
/* SOURCE culvertd.for:853 */
/*<       last=last-xoff >*/
	last -= xoff;
/* SOURCE culvertd.for:854 */
/*<       if(a.lt.ftab(last))goto110 >*/
	if (a < ftab[last]) {
	    goto L110;
	}
/* SOURCE culvertd.for:855 */
/*<       endif >*/
    }
/*     Save the last access location. */
/* SOURCE culvertd.for:858 */
/*<       itab(adr+3)=last-2 >*/
    itab[*adr + 3] = last - 2;
/*     Find the value of depth that would give the area A. */
/* SOURCE culvertd.for:861 */
/*<       al=ftab(last) >*/
    al = ftab[last];
/* SOURCE culvertd.for:862 */
/*<       if(a.eq.al)then >*/
    if (a == al) {
/* SOURCE culvertd.for:863 */
/*<       y=ftab(last-2) >*/
	y = ftab[last - 2];
/* SOURCE culvertd.for:864 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:865 */
/*<       tl=ftab(last-1) >*/
	tl = ftab[last - 1];
/* SOURCE culvertd.for:866 */
/*<       yl=ftab(last-2) >*/
	yl = ftab[last - 2];
/* SOURCE culvertd.for:867 */
/*<       tr=ftab(last+xoff-1) >*/
	tr = ftab[last + xoff - 1];
/* SOURCE culvertd.for:868 */
/*<       yr=ftab(last+xoff-2) >*/
	yr = ftab[last + xoff - 2];
/* SOURCE culvertd.for:869 */
/*<       dt=tr-tl >*/
	dt = static_cast<double>(tr) - tl;
/* SOURCE culvertd.for:870 */
/*<       dy=yr-yl >*/
	dy = static_cast<double>(yr) - yl;
/* SOURCE culvertd.for:871 */
/*<       if(dt.eq.0.0)then >*/
	if (dt == (float)0.) {
/*         Rectangular */
/* SOURCE culvertd.for:873 */
/*<       y=yl+(a-al)/tl >*/
	    y = static_cast<double>(yl) + static_cast<double>((static_cast<double>(a) - al)) / tl;
/* SOURCE culvertd.for:874 */
/*<       elseif(tl.eq.0.0)then >*/
	} else if (tl == (float)0.) {
/*         Triangular. YL  is zero and AL is zero */
/* SOURCE culvertd.for:876 */
/*<       y=sqrt(2.*yr*a/tr) >*/
	    y = sqrt(static_cast<double>(static_cast<double>(static_cast<double>(yr) * (float)2.) * a) / tr);
/* SOURCE culvertd.for:877 */
/*<       else >*/
	} else {
/*         Trapezoidal */
/* SOURCE culvertd.for:879 */
/*<       p=(a-al)/(dy*tl) >*/
	    p = static_cast<double>((static_cast<double>(a) - al)) / (static_cast<double>(dy) * tl);
/* SOURCE culvertd.for:880 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE culvertd.for:881 */
/*<   120 continue >*/
L120:
/* SOURCE culvertd.for:882 */
/*<       t=tl+p*dt >*/
	    t = static_cast<double>(tl) + static_cast<double>(p) * dt;
/* SOURCE culvertd.for:883 */
/*<       f=al+0.5*p*dy*(t+tl)-a >*/
	    f = static_cast<double>(static_cast<double>(al) + static_cast<double>(static_cast<double>(static_cast<double>(p) * (float).5) * dy) * (static_cast<double>(t) + tl)) - a;
/* SOURCE culvertd.for:884 */
/*<       fp=dy*t >*/
	    fp = static_cast<double>(dy) * t;
/* SOURCE culvertd.for:886 */
/*<       pt=p-f/fp >*/
	    pt = static_cast<double>(p) - static_cast<double>(f) / fp;
/* SOURCE culvertd.for:887 */
/*<       if(abs(f)/a.gt.0.1*epsf.and.abs(p-pt).gt.0.1*epsf)then >*/
	    if (dabs(f) / a > static_cast<double>(epscom_1.epsf) * (float).1 && (feq_gen_r_d_1 = static_cast<double>(p) - pt, 
		    dabs(feq_gen_r_d_1)) > static_cast<double>(epscom_1.epsf) * (float).1) {
/* SOURCE culvertd.for:888 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE culvertd.for:889 */
/*<       if(knt.gt.20)then >*/
		if (knt > 20) {
/* SOURCE culvertd.for:890 */
/*<       write(std6,50)a,p >*/
		    feq_gen_io_d__97.ciunit = feq_gen_stdun_com_d_1.std6;
		    s_wsfe(&feq_gen_io_d__97);
		    do_fio(&feq_gen_c_d_1, (char *)&a, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE culvertd.for:891 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:892 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:893 */
/*<       if(pt.gt.1.0)then >*/
		if (pt > (float)1.) {
/* SOURCE culvertd.for:894 */
/*<       pt=0.5*(p+1.) >*/
		    pt = static_cast<double>((static_cast<double>(p) + (float)1.)) * (float).5;
/* SOURCE culvertd.for:895 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:896 */
/*<       if(pt.lt.0.0)then >*/
		if (pt < (float)0.) {
/* SOURCE culvertd.for:897 */
/*<       pt=0.5*p >*/
		    pt = static_cast<double>(p) * (float).5;
/* SOURCE culvertd.for:898 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:899 */
/*<       p=pt >*/
		p = pt;
/* SOURCE culvertd.for:900 */
/*<       goto120 >*/
		goto L120;
/* SOURCE culvertd.for:901 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:902 */
/*<       y=yl+pt*dy >*/
	    y = static_cast<double>(yl) + static_cast<double>(pt) * dy;
/* SOURCE culvertd.for:903 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:904 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:906 */
/*<       yoverd=y/d >*/
    ret_val = static_cast<double>(y) / *feq_gen_d_d_;
/* SOURCE culvertd.for:907 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:908 */
/*<       end >*/
} /* yoverd_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE culvertd.for:912 */
/*<       realfunctionfcd123(stdout,type,culcls,dup,z1true) >*/
doublereal fcd123_(integer *stdout, integer *feq_gen_type_d_, char *culcls, real *dup, 
	real *z1true, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_56[] = "(\002 *BUG:XXX* CULCLS=\002,a8,\002 IS NOT SUPPO\
RTED IN FCD123.\002)";

    /* System generated locals */
    real ret_val;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real feq_gen_r_d_, y, qc, fr;
    extern /* Subroutine */ int lktqc_(integer *, real *, real *);
    integer adrtab;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     Find the coef of discharge for flow types 1, 2, and 3 making */
/*     all adjustments except for the degree of contraction adjustment. */
/* SOURCE culvertd.for:919 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:922 */
/*<       integerstdout,type >*/
/* SOURCE culvertd.for:923 */
/*<       realdup,z1true >*/
/* SOURCE culvertd.for:924 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TYPE   - Culvert flow type */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     Z1TRUE - known elevation at section 1 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:934 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertd.for:935 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertd.for:936 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:939 */
/*<       integeradrtab >*/
/* SOURCE culvertd.for:940 */
/*<       realfr,qc,r,y >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:943 */
/*<       externallktqc >*/
/*     + + + OUTPUT FORMATS + + + */
/* 50   FORMAT(' *WRN:533* Invalid headwater ratio:',F7.3, */
/*     A  ' in FCD123 at Z1=',F10.2,/,11X,' Reset to maximum of:',F5.2) */
/* SOURCE culvertd.for:948 */
/*<    56 format(' *BUG:XXX* CULCLS=',a8,' IS NOT SUPPORTED IN FCD123.') >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:950 */
/*<       if(culcls.eq.'PIPE'.or.culcls.eq.'FLARED')then >*/
/* L56: */
    
    feq::CulvertCoefficientInput feq_input{};
    if (s_cmp(culcls,const_cast<char*>("PIPE"),8,4) == 0) {
        feq_input.shape = feq::CulvertShape::pipe;
    } else if (s_cmp(culcls,const_cast<char*>("FLARED"),8,6) == 0) {
        feq_input.shape = feq::CulvertShape::flared;
    } else if (s_cmp(culcls,const_cast<char*>("BOX"),8,3) == 0) {
        feq_input.shape = feq::CulvertShape::box;
    } else if (s_cmp(culcls,const_cast<char*>("MITER"),8,5) == 0) {
        feq_input.shape = feq::CulvertShape::miter;
    } else if (s_cmp(culcls,const_cast<char*>("RCPTG"),8,5) == 0) {
        feq_input.shape = feq::CulvertShape::rcptg;
    } else {
        feq_gen_io_d__103.ciunit = *stdout;
        s_wsfe(&feq_gen_io_d__103);
        do_fio(&feq_gen_c_d_1,culcls,static_cast<ftnlen>(8));
        e_wsfe();
        s_stop(const_cast<char*>("Abnormal stop. Errors found."),static_cast<ftnlen>(28));
        return 0.0;
    }
    if (feq_input.shape == feq::CulvertShape::box && *feq_gen_type_d_ == 3) {
        if (xs2com_1.a2 < xs3com_1.a3) {
            adrtab = xs2com_1.adrxs2;
            y = xs2com_1.y2;
        } else {
            adrtab = xs3com_1.adrxs3;
            y = xs3com_1.y3;
        }
        lktqc_(&adrtab,&y,&qc);
        feq_input.critical_flow = qc;
    }
    feq_input.flow_type = *feq_gen_type_d_;
    feq_input.upstream_height = *dup;
    feq_input.upstream_level = *z1true;
    feq_input.entrance_bed = xs2com_1.zb2;
    feq_input.flow = xs3com_1.q3;
    feq_input.rounding_factor = cdcom_1.krb;
    feq_input.wing_factor = cdcom_1.kwing;
    feq_input.projection_factor = cdcom_1.kproj;
    return feq::culvert_discharge_coefficient(feq_input,cdcom_1.ratflg);
    
/* SOURCE culvertd.for:1027 */
/*<       end >*/
} /* fcd123_ */




/* SOURCE culvertd.for:1031 */
/*<       realfunctionfdfrfc(iu,id) >*/
doublereal fdfrfc_(integer *iu, integer *id)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    integer feq_gen_i_d_;
    real al, ar, kl, dx, kr;
    doublereal sum;
    extern /* Subroutine */ int lkta_(integer *, real *, real *), lktk_(
	    integer *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Find the factor on square of flow that will yield the */
/*     friction and eddy losses when the culvert barrel is flowing */
/*     full over its length. */
/* SOURCE culvertd.for:1039 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1042 */
/*<       integerid,iu >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1049 */
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
/* INCLUDE culvertd.for:1050 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:1051 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1054 */
/*<       integeri >*/
/* SOURCE culvertd.for:1055 */
/*<       realal,ar,dx,kl,kr >*/
/* SOURCE culvertd.for:1056 */
/*<       doubleprecisionsum >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:1059 */
/*<       intrinsicabs,sngl >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1062 */
/*<       externallkta,lktk >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1064 */
/*<       sum=0.d0 >*/
    sum = 0.;
/* SOURCE culvertd.for:1065 */
/*<       calllkta(nsec(iu),dvec(iu),al) >*/
    lkta_(&culcom_1.nsec[*iu - 1], &culcom_1.dvec[*iu - 1], &al);
/* SOURCE culvertd.for:1069 */
/*<       calllktk(nsec(iu),dvec(iu),kl) >*/
    lktk_(&culcom_1.nsec[*iu - 1], &culcom_1.dvec[*iu - 1], &kl);
/* SOURCE culvertd.for:1073 */
/*<       do200i=iu+1,id >*/
    feq_gen_i_d_1 = *id;
    for (feq_gen_i_d_ = *iu + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertd.for:1074 */
/*<       calllkta(nsec(i),dvec(i),ar) >*/
	lkta_(&culcom_1.nsec[feq_gen_i_d_ - 1], &culcom_1.dvec[feq_gen_i_d_ - 1], &ar);
/* SOURCE culvertd.for:1078 */
/*<       calllktk(nsec(i),dvec(i),kr) >*/
	lktk_(&culcom_1.nsec[feq_gen_i_d_ - 1], &culcom_1.dvec[feq_gen_i_d_ - 1], &kr);
/* SOURCE culvertd.for:1082 */
/*<       dx=abs(xvec(i)-xvec(i-1)) >*/
	dx = (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[feq_gen_i_d_ - 1]) - culcom_1.xvec[feq_gen_i_d_ - 2], dabs(
		feq_gen_r_d_1));
/* SOURCE culvertd.for:1083 */
/*<       if(al.le.ar)then >*/
	if (al <= ar) {
/*         The flow is expanding. */
/* SOURCE culvertd.for:1085 */
/*<       sum=sum+dx/(kl*kr)+kd(i)*(1.0/al**2-1.0/ar**2)/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = al;
/* Computing 2nd power */
	    feq_gen_r_d_2 = ar;
	    sum = sum + static_cast<double>(dx) / (static_cast<double>(kl) * kr) + static_cast<double>(static_cast<double>(culcom_1.kd[feq_gen_i_d_ - 1]) * (static_cast<double>(static_cast<double>((float)1.) / (
		    static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / 
		    grvcom_1.grav2;
/* SOURCE culvertd.for:1087 */
/*<       else >*/
	} else {
/*         The flow is contracting. */
/* SOURCE culvertd.for:1089 */
/*<       sum=sum+dx/(kl*kr)+ka(i)*(1.0/ar**2-1.0/al**2)/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = ar;
/* Computing 2nd power */
	    feq_gen_r_d_2 = al;
	    sum = sum + static_cast<double>(dx) / (static_cast<double>(kl) * kr) + static_cast<double>(static_cast<double>(culcom_1.ka[feq_gen_i_d_ - 1]) * (static_cast<double>(static_cast<double>((float)1.) / (
		    static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / 
		    grvcom_1.grav2;
/* SOURCE culvertd.for:1091 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1092 */
/*<       kl=kr >*/
	kl = kr;
/* SOURCE culvertd.for:1093 */
/*<       al=ar >*/
	al = ar;
/* SOURCE culvertd.for:1094 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE culvertd.for:1095 */
/*<       fdfrfc=sngl(sum) >*/
    ret_val = (real) sum;
/* SOURCE culvertd.for:1096 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:1097 */
/*<       end >*/
} /* fdfrfc_ */




/* SOURCE culvertd.for:1101 */
/*<       subroutinefndcd5(stdout,culcls,hdrat,rbv,cdis) >*/
/* Subroutine */ int fndcd5_(integer *stdout, char *culcls, real *hdrat, real 
	*rbv, real *cdis, ftnlen culcls_len)
{
    /* Builtin functions */
    double sqrt(doublereal);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real df, dfdc, dfdr;
    integer ntab;
    real wwcd;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *), tdlk10_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Find the discharge coefficient for type 5 flow. */
/* SOURCE culvertd.for:1108 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1111 */
/*<       integerstdout >*/
/* SOURCE culvertd.for:1112 */
/*<       realcdis,hdrat,rbv >*/
/* SOURCE culvertd.for:1113 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     HDRAT  - ratio of head to vertical diameter */
/*     RBV    - rounding/beveling value */
/*     CDIS   - discharge coefficient */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1123 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1126 */
/*<       integerntab >*/
/* SOURCE culvertd.for:1127 */
/*<       realdf,dfdc,dfdr,wwcd >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:1130 */
/*<       intrinsicmax >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1133 */
/*<       externallktab,tdlk10 >*/
/* *********************************************************************** */
/*     Get the basic coefficient. */
/* SOURCE culvertd.for:1136 */
/*<       if(cfhwa.gt.0.0)then >*/
    if (cdcom_1.cfhwa > (float)0.) {
/*       User has selected the FHWA definition of the type 5 discharge */
/*       coefficient.  Note that the FHWA coefficient c, CFHWA, has already */
/*       been multiplied by the value of 2g */
/* SOURCE culvertd.for:1140 */
/*<       cdis=sqrt((1.0-(yfhwa-afhwa*sfhwa)/hdrat)/cfhwa) >*/
	*cdis = sqrt(static_cast<double>((static_cast<double>((float)1.) - static_cast<double>((static_cast<double>(cdcom_1.yfhwa) - static_cast<double>(cdcom_1.afhwa) * 
		cdcom_1.sfhwa)) / *hdrat)) / cdcom_1.cfhwa);
/* SOURCE culvertd.for:1141 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:1142 */
/*<       if(culcls.eq.'FLARED')then >*/
	if (s_cmp(culcls, const_cast<char*>("FLARED"), (ftnlen)8, (ftnlen)6) == 0) {
/*         Special 1-D table lookup */
/* SOURCE culvertd.for:1144 */
/*<       calllktab(tb8adr,hdrat,1,cdis,ntab,df) >*/
	    lktab_(&cdcom_1.tb8adr, hdrat, &feq_gen_c_d_1, cdis, &ntab, &df);
/* SOURCE culvertd.for:1147 */
/*<       else >*/
	} else {
/*         Get the basic value for all other types. */
/* SOURCE culvertd.for:1149 */
/*<       calltdlk10(stdout,tb6adr,10,hdrat,rbv,cdis,dfdr,dfdc) >*/
	    tdlk10_(stdout, &cdcom_1.tb6adr, &feq_gen_c_d_10, hdrat, rbv, cdis, &dfdr, 
		    &dfdc);
/* SOURCE culvertd.for:1153 */
/*<       if(culcls.eq.'MITER')then >*/
	    if (s_cmp(culcls, const_cast<char*>("MITER"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE culvertd.for:1154 */
/*<       cdis=0.92*cdis >*/
		*cdis *= static_cast<double>((float).92);
/* SOURCE culvertd.for:1155 */
/*<       elseif(culcls.eq.'BOX')then >*/
	    } else if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) == 0) {
/* SOURCE culvertd.for:1156 */
/*<       if(wwangl.gt.0.0)then >*/
		if (cdcom_1.wwangl > (float)0.) {
/*             Get the coefficient for a box culvert with wing walls. */
/* SOURCE culvertd.for:1159 */
/*<       calltdlk10(stdout,tb7adr,10,hdrat,wwangl,wwcd,dfdr,dfdc) >*/
		    tdlk10_(stdout, &cdcom_1.tb7adr, &feq_gen_c_d_10, hdrat, &
			    cdcom_1.wwangl, &wwcd, &dfdr, &dfdc);
/* SOURCE culvertd.for:1163 */
/*<       cdis=max(cdis,wwcd) >*/
		    *cdis = dmax(*cdis,wwcd);
/* SOURCE culvertd.for:1164 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:1165 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:1166 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1168 */
/*<       if(culcls.ne.'BOX')then >*/
	if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) != 0) {
/* SOURCE culvertd.for:1169 */
/*<       cdis=cdis*kproj >*/
	    *cdis *= cdcom_1.kproj;
/* SOURCE culvertd.for:1170 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1171 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:1172 */
/*<       if(cdis.gt.1.0)then >*/
    if (*cdis > (float)1.) {
/* SOURCE culvertd.for:1173 */
/*<       cdis=0.98 >*/
	*cdis = (float).98;
/* SOURCE culvertd.for:1174 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:1175 */
/*<       cd=cdis >*/
    cdcom_1.cd = *cdis;
/* SOURCE culvertd.for:1176 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:1177 */
/*<       end >*/
} /* fndcd5_ */




/* SOURCE culvertd.for:1181 */
/*<       subroutinefscmat(stdout,adr,sbot,eflag,nscmat,yatmat,satmat) >*/
/* Subroutine */ int fscmat_(integer *stdout, integer *adr, real *sbot, 
	integer *eflag, integer *nscmat, real *feq_storage_yatmat, real *feq_storage_satmat)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* More than seven matches in FSC\
MAT.\002)";
    static char fmt_52[] = "(/,\002 *ERR:688* TabId=\002,a,\002 has type=\
\002,i3,\002 but type=\002,\002 22 or 25 required.\002)";
    static char fmt_54[] = "(/,\002 Smallest critical slope found=\002,f10\
.4,\002 at depth=\002,f10.3,/,\002 Largest critical slope found=\002,f10.4\
,\002 at \002,\002depth=\002,f10.3)";
    static char fmt_56[] = "(/,\002 *WRN:534* No convergence on depth for So\
=Sc.  Last\002,\002 relative correction=\002,1pe12.4,/,11x,\002Continuing wi\
th latest\002,\002 estimate of depth.\002)";
    static char fmt_58[] = "(/,\002 Depths for which critical slope, Sc, mat\
ch, So, invert\002,\002 slope=\002,f10.4)";
    static char fmt_59[] = "(\002      Depth  (Sc-So)/So\002)";
    static char fmt_60[] = "(1x,f10.3,1pe12.4)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double log(doublereal), exp(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    integer feq_gen_i_d_;
    real k, y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real qc, sc, tp, yl, yr, scl, div;
    integer nsc;
    real scr;
    integer knt;
    real num;
    integer low, knt2;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer high, xoff;
    real yhat, yvec[1003];
    extern /* Subroutine */ int lktk_(integer *, real *, real *);
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real schat, scvec[1003], scmax, scmin;
    extern /* Subroutine */ int lktqc_(integer *, real *, real *);
    real dyovyh, yascmn, yascmx;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__120 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__136 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_59, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find the list of matches bewteen critical slope and bottom */
/*     slope for a cross section for a conduit. There may be none, one, */
/*     two, and maybe more matches. */
/* SOURCE culvertd.for:1190 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1193 */
/*<       integeradr,eflag,nscmat,stdout >*/
/* SOURCE culvertd.for:1194 */
/*<       realsatmat(7),sbot,yatmat(7) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     ADR    - Address of function table */
/*     SBOT   - bottom slope */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     NSCMAT - number of critical slope matches */
/*     YATMAT - depth at match between critical slope and bottom slope */
/*     SATMAT - sign of the residual function slope when critical slope */
/*               and bottom slope match */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1207 */
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
/* INCLUDE culvertd.for:1208 */
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
/* INCLUDE culvertd.for:1209 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE culvertd.for:1210 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1213 */
/*<       integerhigh,i,knt,knt2,low,nsc,type,xoff >*/
/* SOURCE culvertd.for:1214 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:1219 */
/*<       intrinsicabs,exp,log >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1222 */
/*<       characterget_tabid*16 >*/
/* SOURCE culvertd.for:1223 */
/*<       externallktk,lktqc,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:1226 */
/*<    50 format(/,' *BUG:XXX* More than seven matches in FSCMAT.') >*/
/* SOURCE culvertd.for:1227 */
/*<    52  >*/
/* SOURCE culvertd.for:1229 */
/*<    54  >*/
/* SOURCE culvertd.for:1232 */
/*<    56  >*/
/* SOURCE culvertd.for:1235 */
/*<    58  >*/
/* SOURCE culvertd.for:1238 */
/*<    59 format('      Depth  (Sc-So)/So') >*/
/* SOURCE culvertd.for:1239 */
/*<    60 format(1x,f10.3,1pe12.4) >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1241 */
/*<       type=itab(adr+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> satmat(feq_storage_satmat, 1);

    feq::IndexedPointer<real> yatmat(feq_storage_yatmat, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L59: */
/* L60: */
    feq_gen_type_d_ = itab[*adr + 2];
/* SOURCE culvertd.for:1242 */
/*<       if(type.ne.22.and.type.ne.25)then >*/
    if (feq_gen_type_d_ != 22 && feq_gen_type_d_ != 25) {
/* SOURCE culvertd.for:1243 */
/*<       write(stdout,52)get_tabid(itab(adr+1)),type >*/
	feq_gen_io_d__120.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__120);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(*adr + 1).data());
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE culvertd.for:1244 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culvertd.for:1245 */
/*<       return >*/
	return 0;
/* SOURCE culvertd.for:1246 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:1247 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE culvertd.for:1249 */
/*<       low=adr+xtioff >*/
    low = *adr + 32;
/*     Get the address of the highest argument of the table. */
/* SOURCE culvertd.for:1251 */
/*<       high=itab(adr) >*/
    high = itab[*adr];
/*     Try to force computation of the critical slope at */
/*     small depths.  Note that the definition of critical flow */
/*     in the table may be inaccurate at this point. */
/*     Compute critical slope for all but the first(zero depth) and */
/*     last(top of slot) depths for the cross section of a closed conduit. */
/*      YMIN = FTAB(LOW + XOFF) */
/* SOURCE culvertd.for:1261 */
/*<       scmax=-1.e30 >*/
    scmax = (float)-1e30;
/* SOURCE culvertd.for:1262 */
/*<       scmin=1.e30 >*/
    scmin = (float)1e30;
/*      DO 90 I=1,3 */
/*        Y = YMIN*FLOAT(I)/4.0 */
/*        CALL LKTK(ADR, Y, K) */
/*        CALL LKTQC(ADR, Y, QC) */
/*        SC = (QC/K)**2 */
/*        SCVEC(I) = SC */
/*        YVEC(I) = Y */
/*        WRITE(STDOUT,*) ' Y=',Y,' SC=',SC */
/*        SCMAX = MAX(SC, SCMAX) */
/*        SCMIN = MIN(SC, SCMIN) */
/* 90    CONTINUE */
/* SOURCE culvertd.for:1274 */
/*<       nsc=0 >*/
    nsc = 0;
/*     Compute the remaining points at the tabulated depths. */
/* SOURCE culvertd.for:1276 */
/*<       do100i=low+xoff,high-xoff,xoff >*/
    feq_gen_i_d_1 = high - xoff;
    feq_gen_i_d_2 = xoff;
    for (feq_gen_i_d_ = low + xoff; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) 
	    {
/* SOURCE culvertd.for:1277 */
/*<       y=ftab(i) >*/
	y = ftab[feq_gen_i_d_];
/* SOURCE culvertd.for:1278 */
/*<       k=ftab(i+3)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ftab[feq_gen_i_d_ + 3];
	k = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertd.for:1279 */
/*<       qc=ftab(i+7) >*/
	qc = ftab[feq_gen_i_d_ + 7];
/* SOURCE culvertd.for:1280 */
/*<       nsc=nsc+1 >*/
	++nsc;
/* SOURCE culvertd.for:1281 */
/*<       sc=(qc/k)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(qc) / k;
	sc = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertd.for:1282 */
/*<       if(sc.gt.scmax)then >*/
	if (sc > scmax) {
/* SOURCE culvertd.for:1283 */
/*<       scmax=sc >*/
	    scmax = sc;
/* SOURCE culvertd.for:1284 */
/*<       yascmx=y >*/
	    yascmx = y;
/* SOURCE culvertd.for:1285 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1286 */
/*<       if(sc.lt.scmin)then >*/
	if (sc < scmin) {
/* SOURCE culvertd.for:1287 */
/*<       scmin=sc >*/
	    scmin = sc;
/* SOURCE culvertd.for:1288 */
/*<       yascmn=y >*/
	    yascmn = y;
/* SOURCE culvertd.for:1289 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1290 */
/*<       scvec(nsc)=sc >*/
	scvec[nsc - 1] = sc;
/* SOURCE culvertd.for:1291 */
/*<       yvec(nsc)=y >*/
	yvec[nsc - 1] = y;
/*        WRITE(STDOUT,*) ' Y=',YVEC(NSC),' SC=',SCVEC(NSC) */
/* SOURCE culvertd.for:1293 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE culvertd.for:1296 */
/*<       write(stdout,54)scmin,yascmn,scmax,yascmx >*/
    feq_gen_io_d__136.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__136);
    do_fio(&feq_gen_c_d_1, (char *)&scmin, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&yascmn, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&scmax, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&yascmx, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culvertd.for:1298 */
/*<       if(sbot.lt.scmin)then >*/
    if (*sbot < scmin) {
/*       There is no match. */
/* SOURCE culvertd.for:1300 */
/*<       nscmat=0 >*/
	*nscmat = 0;
/* SOURCE culvertd.for:1301 */
/*<       elseif(sbot.gt.scmax)then >*/
    } else if (*sbot > scmax) {
/*       There is a match but we need not find it.   Note that critical */
/*       slope approaches infinity  as depth approaches zero and */
/*       as depth approaches D.   Very small depths are of no interest */
/*       and the match above the maximum in the table is not needed. */
/*       Signal that the slope will be steep for any critical flow */
/*       possible in the culvert. */
/* SOURCE culvertd.for:1308 */
/*<       nscmat=-1 >*/
	*nscmat = -1;
/* SOURCE culvertd.for:1309 */
/*<       else >*/
    } else {
/*       Do a search here and find all the matches with their */
/*       depths.  There should be at least one match. */
/* SOURCE culvertd.for:1312 */
/*<       write(stdout,58)sbot >*/
	feq_gen_io_d__137.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__137);
	do_fio(&feq_gen_c_d_1, (char *)&(*sbot), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertd.for:1313 */
/*<       write(stdout,59) >*/
	feq_gen_io_d__138.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__138);
	e_wsfe();
/* SOURCE culvertd.for:1314 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE culvertd.for:1315 */
/*<       scl=scvec(1) >*/
	scl = scvec[0];
/* SOURCE culvertd.for:1316 */
/*<       yl=yvec(1) >*/
	yl = yvec[0];
/* SOURCE culvertd.for:1317 */
/*<       do200i=2,nsc >*/
	feq_gen_i_d_2 = nsc;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE culvertd.for:1318 */
/*<       scr=scvec(i) >*/
	    scr = scvec[feq_gen_i_d_ - 1];
/* SOURCE culvertd.for:1319 */
/*<       yr=yvec(i) >*/
	    yr = yvec[feq_gen_i_d_ - 1];
/* SOURCE culvertd.for:1320 */
/*<       if(scr.le.sbot.and.scl.ge.sbot.or.scl.le.sbot.and.scr.ge.sbot)then >*/
	    if (scr <= *sbot && scl >= *sbot || scl <= *sbot && scr >= *sbot) 
		    {
/*           Interpolate for the value of depth using linear interpolation */
/*           in logarithms. */
/* SOURCE culvertd.for:1324 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE culvertd.for:1325 */
/*<       if(knt.gt.7)then >*/
		if (knt > 7) {
/* SOURCE culvertd.for:1326 */
/*<       write(stdout,50) >*/
		    feq_gen_io_d__144.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__144);
		    e_wsfe();
/* SOURCE culvertd.for:1327 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:1328 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:1329 */
/*<       div=log(scr/scl) >*/
		div = log(static_cast<double>(scr) / scl);
/* SOURCE culvertd.for:1330 */
/*<       num=log(yr/yl) >*/
		num = log(static_cast<double>(yr) / yl);
/* SOURCE culvertd.for:1331 */
/*<       if(div.eq.0.0)then >*/
		if (div == (float)0.) {
/*             The critical slope is constant.  Depth is undefined */
/*             in the interval.  Take the right hand value. */
/* SOURCE culvertd.for:1334 */
/*<       yatmat(knt)=yr >*/
		    yatmat[knt] = yr;
/* SOURCE culvertd.for:1335 */
/*<       satmat(knt)=0.0 >*/
		    satmat[knt] = (float)0.;
/* SOURCE culvertd.for:1336 */
/*<       else >*/
		} else {
/* SOURCE culvertd.for:1337 */
/*<       yhat=yl*exp(log(sbot/scl)*num/div) >*/
		    yhat = yl * exp(log(static_cast<double>(*sbot) / scl) * num / div);
/* SOURCE culvertd.for:1338 */
/*<       if(scr.gt.scl)then >*/
		    if (scr > scl) {
/* SOURCE culvertd.for:1339 */
/*<       satmat(knt)=1.0 >*/
			satmat[knt] = (float)1.;
/* SOURCE culvertd.for:1340 */
/*<       else >*/
		    } else {
/* SOURCE culvertd.for:1341 */
/*<       satmat(knt)=-1.0 >*/
			satmat[knt] = (float)-1.;
/* SOURCE culvertd.for:1342 */
/*<       endif >*/
		    }
/*             Refine the interpolation.  Errors can be large */
/*             enough to cause problems later. */
/* SOURCE culvertd.for:1345 */
/*<       knt2=0 >*/
		    knt2 = 0;
/* SOURCE culvertd.for:1346 */
/*<   150 continue >*/
L150:
/* SOURCE culvertd.for:1347 */
/*<       calllktqc(adr,yhat,qc) >*/
		    lktqc_(adr, &yhat, &qc);
/* SOURCE culvertd.for:1351 */
/*<       calllktk(adr,yhat,k) >*/
		    lktk_(adr, &yhat, &k);
/* SOURCE culvertd.for:1355 */
/*<       schat=(qc/k)**2 >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(qc) / k;
		    schat = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertd.for:1356 */
/*<       dyovyh=-(1.0-sbot/schat)*num/div >*/
		    dyovyh = static_cast<double>(static_cast<double>(-(static_cast<double>((float)1.) - static_cast<double>(*sbot) / schat)) * num) / div;
/* SOURCE culvertd.for:1357 */
/*<       if(abs(dyovyh).gt.epsf)then >*/
		    if (dabs(dyovyh) > epscom_1.epsf) {
/* SOURCE culvertd.for:1358 */
/*<       tp=yhat*(1.0+dyovyh) >*/
			tp = static_cast<double>(yhat) * (static_cast<double>(dyovyh) + (float)1.);
/* SOURCE culvertd.for:1359 */
/*<       if(tp.lt.yl)then >*/
			if (tp < yl) {
/* SOURCE culvertd.for:1360 */
/*<       yhat=0.5*(yhat+yl) >*/
			    yhat = static_cast<double>((static_cast<double>(yhat) + yl)) * (float).5;
/* SOURCE culvertd.for:1361 */
/*<       elseif(tp.gt.yr)then >*/
			} else if (tp > yr) {
/* SOURCE culvertd.for:1362 */
/*<       yhat=0.5*(yhat+yr) >*/
			    yhat = static_cast<double>((static_cast<double>(yhat) + yr)) * (float).5;
/* SOURCE culvertd.for:1363 */
/*<       else >*/
			} else {
/* SOURCE culvertd.for:1364 */
/*<       yhat=tp >*/
			    yhat = tp;
/* SOURCE culvertd.for:1365 */
/*<       endif >*/
			}
/* SOURCE culvertd.for:1366 */
/*<       knt2=knt2+1 >*/
			++knt2;
/* SOURCE culvertd.for:1367 */
/*<       if(knt2.gt.30)then >*/
			if (knt2 > 30) {
/* SOURCE culvertd.for:1368 */
/*<       write(stdout,56)dyovyh >*/
			    feq_gen_io_d__152.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__152);
			    do_fio(&feq_gen_c_d_1, (char *)&dyovyh, (ftnlen)sizeof(
				    real));
			    e_wsfe();
/* SOURCE culvertd.for:1369 */
/*<       goto160 >*/
			    goto L160;
/* SOURCE culvertd.for:1370 */
/*<       endif >*/
			}
/* SOURCE culvertd.for:1371 */
/*<       goto150 >*/
			goto L150;
/* SOURCE culvertd.for:1372 */
/*<       endif >*/
		    }
/* SOURCE culvertd.for:1373 */
/*<   160 continue >*/
L160:
/* SOURCE culvertd.for:1374 */
/*<       write(stdout,60)yhat,(schat-sbot)/sbot >*/
		    feq_gen_io_d__153.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__153);
		    do_fio(&feq_gen_c_d_1, (char *)&yhat, (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>((static_cast<double>(schat) - *sbot)) / *sbot;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE culvertd.for:1375 */
/*<       yatmat(knt)=yhat >*/
		    yatmat[knt] = yhat;
/* SOURCE culvertd.for:1376 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:1377 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:1378 */
/*<       scl=scr >*/
	    scl = scr;
/* SOURCE culvertd.for:1379 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE culvertd.for:1380 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE culvertd.for:1381 */
/*<       if(knt.eq.0)then >*/
	if (knt == 0) {
/* SOURCE culvertd.for:1382 */
/*<        >*/
	    feq_gen_io_d__154.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__154);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX No match found in FSCMAT when"), (
		    ftnlen)39);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" at least one should exist."), (ftnlen)27);
	    e_wsle();
/* SOURCE culvertd.for:1384 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:1385 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:1386 */
/*<       nscmat=knt >*/
	    *nscmat = knt;
/* SOURCE culvertd.for:1387 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1388 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' NSCMAT=',NSCMAT */
/* SOURCE culvertd.for:1390 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:1391 */
/*<       end >*/
} /* fscmat_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE culvertd.for:1395 */
/*<       subroutinemkxvec(loverd,d,nhat,xvec,iat3d,iat6d) >*/
/* Subroutine */ int mkxvec_(real *loverd, real *feq_gen_d_d_, integer *nhat, real *
	feq_storage_xvec, integer *iat3d, integer *iat6d)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal w[8400], x[8400];
    integer ip;
    extern /* Subroutine */ int grule_(integer *, doublereal *, doublereal *);

/*     + + + PURPOSE + + + */
/*     Construct a pattern of points along the culvert barrel to */
/*     make sure that the profile computations are sufficiently */
/*     precise.  Also insert any special fixed locations. */
/* SOURCE culvertd.for:1405 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE culvertd.for:1408 */
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
/* SOURCE culvertd.for:1411 */
/*<       integeriat3d,iat6d,nhat >*/
/* SOURCE culvertd.for:1412 */
/*<       reald,loverd,xvec(mnbn) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     LOVERD - ratio of culvert barrel length to vertical diameter */
/*     D      - vertical diameter of culvert barrel */
/*     NHAT   - number of nodes for culvert barrel */
/*     XVEC   - Stations for nodes on a branch or along a culvert */
/*     IAT3D  - index to vena contracta location */
/*     IAT6D  - index to vena contracta location */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1423 */
/*<       integeri,ip >*/
/* SOURCE culvertd.for:1424 */
/*<       doubleprecisionw(mnbn),x(mnbn) >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1427 */
/*<       externalgrule >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1429 */
/*<       if(nhat.gt.mnbn)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> xvec(feq_storage_xvec, 1);

    /* Function Body */
    if (*nhat > 8400) {
/* SOURCE culvertd.for:1430 */
/*<       nhat=mnbn-3 >*/
	*nhat = 8397;
/* SOURCE culvertd.for:1431 */
/*<       endif >*/
    }
/*     Get the Gauss points. */
/* SOURCE culvertd.for:1435 */
/*<       callgrule(nhat,x,w) >*/
    grule_(nhat, x, w);
/* SOURCE culvertd.for:1439 */
/*<       xvec(1)=0.0 >*/
    xvec[1] = (float)0.;
/* SOURCE culvertd.for:1440 */
/*<       ip=2 >*/
    ip = 2;
/* SOURCE culvertd.for:1441 */
/*<       iat3d=0 >*/
    *iat3d = 0;
/* SOURCE culvertd.for:1442 */
/*<       iat6d=0 >*/
    *iat6d = 0;
/* SOURCE culvertd.for:1443 */
/*<       do100i=1,nhat >*/
    feq_gen_i_d_1 = *nhat;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertd.for:1444 */
/*<       xvec(ip)=0.5d0*(x(i)+1.d0)*loverd >*/
	xvec[ip] = (x[feq_gen_i_d_ - 1] + 1.) * .5 * *loverd;
/* SOURCE culvertd.for:1445 */
/*<       if(xvec(ip).gt.3.1.and.xvec(ip-1).lt.2.9)then >*/
	if (xvec[ip] > (float)3.1 && xvec[ip - 1] < (float)2.9) {
/*         Insert 3.0 */
/* SOURCE culvertd.for:1447 */
/*<       xvec(ip+1)=xvec(ip) >*/
	    xvec[ip + 1] = xvec[ip];
/* SOURCE culvertd.for:1448 */
/*<       xvec(ip)=3.0 >*/
	    xvec[ip] = (float)3.;
/* SOURCE culvertd.for:1449 */
/*<       iat3d=ip >*/
	    *iat3d = ip;
/* SOURCE culvertd.for:1450 */
/*<       ip=ip+1 >*/
	    ++ip;
/* SOURCE culvertd.for:1451 */
/*<       elseif(xvec(ip).ge.2.9.and.xvec(ip).le.3.1)then >*/
	} else if (xvec[ip] >= (float)2.9 && xvec[ip] <= (float)3.1) {
/* SOURCE culvertd.for:1452 */
/*<       iat3d=ip >*/
	    *iat3d = ip;
/* SOURCE culvertd.for:1453 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1454 */
/*<       if(xvec(ip).gt.6.1.and.xvec(ip-1).lt.5.9)then >*/
	if (xvec[ip] > (float)6.1 && xvec[ip - 1] < (float)5.9) {
/*         Insert 6.0 */
/* SOURCE culvertd.for:1456 */
/*<       xvec(ip+1)=xvec(ip) >*/
	    xvec[ip + 1] = xvec[ip];
/* SOURCE culvertd.for:1457 */
/*<       xvec(ip)=6.0 >*/
	    xvec[ip] = (float)6.;
/* SOURCE culvertd.for:1458 */
/*<       iat6d=ip >*/
	    *iat6d = ip;
/* SOURCE culvertd.for:1459 */
/*<       ip=ip+1 >*/
	    ++ip;
/* SOURCE culvertd.for:1460 */
/*<       elseif(xvec(ip).ge.5.9.and.xvec(ip).le.6.1)then >*/
	} else if (xvec[ip] >= (float)5.9 && xvec[ip] <= (float)6.1) {
/* SOURCE culvertd.for:1461 */
/*<       iat6d=ip >*/
	    *iat6d = ip;
/* SOURCE culvertd.for:1462 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1463 */
/*<       ip=ip+1 >*/
	++ip;
/* SOURCE culvertd.for:1464 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE culvertd.for:1465 */
/*<       nhat=ip >*/
    *nhat = ip;
/* SOURCE culvertd.for:1466 */
/*<       xvec(nhat)=loverd >*/
    xvec[*nhat] = *loverd;
/* SOURCE culvertd.for:1468 */
/*<       do200i=2,nhat >*/
    feq_gen_i_d_1 = *nhat;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertd.for:1469 */
/*<       xvec(i)=d*xvec(i) >*/
	xvec[feq_gen_i_d_] = static_cast<double>(*feq_gen_d_d_) * xvec[feq_gen_i_d_];
/* SOURCE culvertd.for:1470 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE culvertd.for:1473 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:1474 */
/*<       end >*/
} /* mkxvec_ */




/* SOURCE culvertd.for:1478 */
/*<       realfunctionr44to4(ya) >*/
doublereal r44to4_(real *ya)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    real y;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Residual function for computing values at section 4 from */
/*     those at section 44. */
/* SOURCE culvertd.for:1485 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1488 */
/*<       realya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     YA     - unknown being sought */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1494 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertd.for:1495 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:1496 */
/*     Common for function DEPM, and F4TO44 in FEQUTL */
/* SOURCE depmc.cmn:3 */
/*<       common/depmc/mfcon,m44,m3,mcase,e44,e4 >*/
/* SOURCE depmc.cmn:4 */
/*<       integermcase >*/
/* SOURCE depmc.cmn:5 */
/*<       realmfcon,m44,m3,e44,e4 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1499 */
/*<       realy >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1502 */
/*<       externalxlktal >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1504 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE culvertd.for:1505 */
/*<       callxlktal(adrxs4,y,a4,t4,dt4,j4,k4,dk4,bet4,dbet4,alp4,dalp4) >*/
    xlktal_(&xs4com_1.adrxs4, &y, &xs4com_1.a4, &xs4com_1.t4, &xs4com_1.dt4, &
	    xs4com_1.j4, &xs4com_1.k4, &xs4com_1.dk4, &xs4com_1.bet4, &
	    xs4com_1.dbet4, &xs4com_1.alp4, &xs4com_1.dalp4);
    // The original lookup clamps its private Y; the root argument stays unchanged.
    return feq::departure_energy_residual(y,xs4com_1.q4,xs4com_1.a4,
        xs4com_1.alp4,grvcom_1.grav2,depmc_1.e4);
} /* r44to4_ */




/* SOURCE culvertd.for:1517 */
/*<       realfunctionr4to44(ya) >*/
doublereal r4to44_(real *ya)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    real y;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Residual function for computing values at section 44 from */
/*     those at section 4. */
/* SOURCE culvertd.for:1524 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1527 */
/*<       realya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     YA     - unknown being sought */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1533 */
/* SOURCE x44com.cmn:2 */
/*<        >*/
/* SOURCE x44com.cmn:6 */
/*<       integeradrs44,stat44 >*/
/* SOURCE x44com.cmn:8 */
/*<        >*/
/* INCLUDE culvertd.for:1534 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:1535 */
/*     Common for function DEPM, and F4TO44 in FEQUTL */
/* SOURCE depmc.cmn:3 */
/*<       common/depmc/mfcon,m44,m3,mcase,e44,e4 >*/
/* SOURCE depmc.cmn:4 */
/*<       integermcase >*/
/* SOURCE depmc.cmn:5 */
/*<       realmfcon,m44,m3,e44,e4 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1538 */
/*<       realy >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1541 */
/*<       externalxlktal >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1543 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE culvertd.for:1544 */
/*<        >*/
    xlktal_(&x44com_1.adrs44, &y, &x44com_1.a44, &x44com_1.t44, &
	    x44com_1.dt44, &x44com_1.j44, &x44com_1.k44, &x44com_1.dk44, &
	    x44com_1.bet44, &x44com_1.dbet44, &x44com_1.alp44, &
	    x44com_1.dalp44);
    // The original lookup clamps its private Y; the root argument stays unchanged.
    return feq::departure_energy_residual(y,x44com_1.q44,x44com_1.a44,
        x44com_1.alp44,grvcom_1.grav2,depmc_1.e44);
} /* r4to44_ */




/* SOURCE culvertd.for:1557 */
/*<       realfunctionrapp(y) >*/
doublereal rapp_(real *y)
{
    extern int xlktal_(int*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*);
    xs1com_1.y1 = *y;
    xlktal_(&xs1com_1.adrxs1,&xs1com_1.y1,&xs1com_1.a1,&xs1com_1.t1,&xs1com_1.dt1,
        &xs1com_1.j1,&xs1com_1.k1,&xs1com_1.dk1,&xs1com_1.bet1,&xs1com_1.dbet1,
        &xs1com_1.alp1,&xs1com_1.dalp1);
    xs1com_1.z1 = static_cast<float>(static_cast<double>(xs1com_1.zb1)+xs1com_1.y1);
    const feq::ApproachResidualInput input{xs1com_1.y1,xs1com_1.a1,xs1com_1.k1,xs1com_1.alp1,
        xs1com_1.q1,xs1com_1.zb1,xs2com_1.q2,xs2com_1.zb2,xs2com_1.y2,xs2com_1.a2,
        xs2com_1.k2,xs2com_1.alp2,appcom_1.applen,appcom_1.applos,appcom_1.appexp,
        rappc_1.cdin,rappc_1.vhloss,grvcom_1.grav2};
    const feq::ApproachResidual result = feq::approach_residual(input);
    rappc_1.conf = result.contracting ? 1 : 0;
    return result.value;
} /* rapp_ */




/* SOURCE culvertd.for:1641 */
/*<       realfunctionrcon(concof) >*/
doublereal rcon_(real *concof)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    extern doublereal yoverd_(integer *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Residual function to find the contraction coefficient for */
/*     type 5 flow. */
/* SOURCE culvertd.for:1648 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1651 */
/*<       realconcof >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     CONCOF - contraction coefficient */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1657 */
/*     Common for finding contraction coefficient for type 5 flow. */
/* SOURCE rconc.cmn:3 */
/*<       integeradr >*/
/* SOURCE rconc.cmn:5 */
/*<       realcdis,hoverd,afull,d,h,dzvc,evc,vhf >*/
/* SOURCE rconc.cmn:7 */
/*<       common/rconc/cdis,hoverd,afull,d,adr,h,dzvc,evc,vhf >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:1660 */
/*<       realyoverd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1663 */
/*<       externalyoverd >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1665 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(*concof) / rconc_1.cdis;
    ret_val = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1 * ((float)1. - yoverd_(&rconc_1.adr, &rconc_1.feq_gen_d_d_, &
	    rconc_1.afull, concof) / rconc_1.hoverd + static_cast<double>(rconc_1.dzvc) / 
	    rconc_1.feq_gen_h_d_) - (float)1.;
/* SOURCE culvertd.for:1667 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:1668 */
/*<       end >*/
} /* rcon_ */




/* SOURCE culvertd.for:1672 */
/*<       realfunctionrcon2(concof) >*/
doublereal rcon2_(real *concof)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    extern doublereal yoverd_(integer *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Residual function to find the contraction coefficient for */
/*     type 5 flow given the conditions at the limit of type 1 or */
/*     type 2 flow. */
/* SOURCE culvertd.for:1680 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1683 */
/*<       realconcof >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     CONCOF - contraction coefficient */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1689 */
/*     Common for finding contraction coefficient for type 5 flow. */
/* SOURCE rconc.cmn:3 */
/*<       integeradr >*/
/* SOURCE rconc.cmn:5 */
/*<       realcdis,hoverd,afull,d,h,dzvc,evc,vhf >*/
/* SOURCE rconc.cmn:7 */
/*<       common/rconc/cdis,hoverd,afull,d,adr,h,dzvc,evc,vhf >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:1692 */
/*<       realyoverd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1695 */
/*<       externalyoverd >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1697 */
/*<       rcon2=(concof**2*(evc-d*yoverd(adr,d,afull,concof))-vhf)/vhf >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *concof;
    ret_val = (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1 * (rconc_1.evc - rconc_1.feq_gen_d_d_ * yoverd_(&
	    rconc_1.adr, &rconc_1.feq_gen_d_d_, &rconc_1.afull, concof)) - rconc_1.vhf)
	     / rconc_1.vhf;
/* SOURCE culvertd.for:1699 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:1700 */
/*<       end >*/
} /* rcon2_ */




/* SOURCE culvertd.for:1704 */
/*<       realfunctionrdpm26(y) >*/
doublereal rdpm26_(real *y)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    real m44;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute residual function for idealized departure reach */
/*     to define the section 44 values given the section 3 and */
/*     roadway flow values for flow types 2 and 6. */
/* SOURCE culvertd.for:1712 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1715 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1721 */
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
/* INCLUDE culvertd.for:1722 */
/* SOURCE x44com.cmn:2 */
/*<        >*/
/* SOURCE x44com.cmn:6 */
/*<       integeradrs44,stat44 >*/
/* SOURCE x44com.cmn:8 */
/*<        >*/
/* INCLUDE culvertd.for:1723 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:1724 */
/*     Common for function DPM26C in FEQUTL */
/* SOURCE dpm26c.cmn:3 */
/*<       common/dpm26c/outun,rmflux,m43 >*/
/* SOURCE dpm26c.cmn:4 */
/*<       integeroutun >*/
/* SOURCE dpm26c.cmn:5 */
/*<       realrmflux,m43 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1727 */
/*<       realm44 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1730 */
/*<       externalxlktal >*/
/* *********************************************************************** */
/*     VARIABLES WITH SUFFIX 43 ARE DEFINED ON ENTRY AND GIVE */
/*     THE CROSS SECTION ELEMENTS FROM THE DEPARTURE SECTION AT */
/*     THE PIEZOMETRIC LEVEL AT THE EXIT OF THE CULVERT FOR FLOW */
/*     TYPES 2 AND 6. VALUES IN THE CULVERT AT THE EXIT OF THE */
/*     CULVERT ARE ALSO DEFINED ON ENTRY. */
/* SOURCE culvertd.for:1738 */
/*<       y44=y >*/
    x44com_1.y44 = *y;
/* SOURCE culvertd.for:1739 */
/*<       z44=zb44+y44 >*/
    x44com_1.z44 = static_cast<double>(x44com_1.zb44) + x44com_1.y44;
/* SOURCE culvertd.for:1741 */
/*<        >*/
    xlktal_(&x44com_1.adrs44, &x44com_1.y44, &x44com_1.a44, &x44com_1.t44, &
	    x44com_1.dt44, &x44com_1.j44, &x44com_1.k44, &x44com_1.dk44, &
	    x44com_1.bet44, &x44com_1.dbet44, &x44com_1.alp44, &
	    x44com_1.dalp44);
/* SOURCE culvertd.for:1747 */
/*<       m44=grav*j44+bet44*q44**2/a44 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = x44com_1.q44;
    m44 = static_cast<double>(static_cast<double>(grvcom_1.grav) * x44com_1.j44) + static_cast<double>(static_cast<double>(x44com_1.bet44) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
	    x44com_1.a44;
/* SOURCE culvertd.for:1748 */
/*<       rdpm26=1.0-m43/m44 >*/
    ret_val = static_cast<double>((float)1.) - static_cast<double>(dpm26c_1.m43) / m44;
/*      WRITE(OUTUN,*) ' AT Y=',Y,' RDPM26 =', RDPM26 */
/*      WRITE(OUTUN,*) ' Q44=',Q44,' Q3=',Q3,' J44=',J44,' J43=',J43, */
/*     A    ' A3=',A3,' A44=',A44,' RMFLUX=',RMFLUX, */
/*     B    ' BET44=',BET44,' BET3=',BET3,' M44=',M44,' M43=',M43, */
/*     C    ' ALP3=',ALP3,' ALP44=',ALP44,' J3=',J3,' J3Z43=', */
/*     D    J3Z43 */
/* SOURCE culvertd.for:1757 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:1758 */
/*<       end >*/
} /* rdpm26_ */




/* SOURCE culvertd.for:1762 */
/*<       realfunctionrrovd(rb) >*/
doublereal rrovd_(real *rb)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real tp, rbv;
    extern doublereal fndszl_(integer *, char *, real *, real *, real *, real 
	    *, integer *, integer *, ftnlen);

/*     + + + PURPOSE + + + */
/*     Residual function for finding the relative rounding/beveling */
/*     that causes the slope of the culvert to become the boundary */
/*     between types 5 and 6. */
/* SOURCE culvertd.for:1770 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1773 */
/*<       realrb >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     RB     - rounding/beveling value */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1779 */
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
/* INCLUDE culvertd.for:1780 */
/*       COMMON FOR FINDING THE MATCHING RELATIVE ROUNDING/BEVELING */
/* SOURCE rrovdc.cmn:3 */
/*<       common/rrovdc/class >*/
/* SOURCE rrovdc.cmn:5 */
/*<       character*8class >*/
/* INCLUDE culvertd.for:1781 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertd.for:1782 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertd.for:1783 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1786 */
/*<       realrbv,tp >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:1789 */
/*<       realfndszl >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1792 */
/*<       externalfndszl >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1794 */
/*<       rbv=rb >*/
    rbv = *rb;
/* SOURCE culvertd.for:1795 */
/*<       tp=fndszl(std6,class,loverd,nbar,rghfac,rbv,tb15ad,tb16ad) >*/
    tp = fndszl_(&feq_gen_stdun_com_d_1.std6, rrovdc_1.feq_gen_class_d_, &culcom_1.loverd, &
	    cdcom_1.nbar, &cdcom_1.rghfac, &rbv, &cdcom_1.tb15ad, 
	    cdcom_1.tb16ad, (ftnlen)8);
/* SOURCE culvertd.for:1798 */
/*<       rrovd=100.0*(tp-szero) >*/
    ret_val = static_cast<double>((static_cast<double>(tp) - culcom_1.szero)) * (float)100.;
/*      WRITE(STD6,*) ' RROVD:AT RB=',RB,' SZERO=',SZERO,' SLIM=',TP, */
/*     A              ' RROVD=',RROVD */
/* SOURCE culvertd.for:1801 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:1802 */
/*<       end >*/
} /* rrovd_ */




/* SOURCE culvertd.for:1806 */
/*<       subroutinefndcc(stdout,cd,dup,adrs,ain,hdrat,head,dz,cc) >*/
/* Subroutine */ int fndcc_(integer *stdout, real *cd, real *dup, integer *
	adrs, real *ain, real *hdrat, real *head, real *dz, real *cc)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real f, fh, fl, cct;
    extern /* Subroutine */ int rgf_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    integer feq_gen_flag_d_;
    extern doublereal rcon_(real *);
    real cclow, cchigh;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__174 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Estimate the contraction coefficient for type 5 flow. */
/* SOURCE culvertd.for:1813 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1816 */
/*<       integeradrs,stdout >*/
/* SOURCE culvertd.for:1817 */
/*<       realain,cc,cd,dup,dz,hdrat,head >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CD     - discharge coefficient */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     ADRS   - Address of function table */
/*     AIN    - full area of conduit */
/*     HDRAT  - ratio of head to vertical diameter */
/*     HEAD   - head at section 1 */
/*     DZ     - change in elevation from entrance to vena contracta */
/*     CC     - contraction coefficient */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1831 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertd.for:1832 */
/*     Common for finding contraction coefficient for type 5 flow. */
/* SOURCE rconc.cmn:3 */
/*<       integeradr >*/
/* SOURCE rconc.cmn:5 */
/*<       realcdis,hoverd,afull,d,h,dzvc,evc,vhf >*/
/* SOURCE rconc.cmn:7 */
/*<       common/rconc/cdis,hoverd,afull,d,adr,h,dzvc,evc,vhf >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1835 */
/*<       integerflag >*/
/* SOURCE culvertd.for:1836 */
/*<       realcchigh,cclow,cct,f,fh,fl >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:1839 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:1842 */
/*<       realrcon >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1845 */
/*<       externalrcon,rgf >*/
/* *********************************************************************** */
/*     Set values in common for finding the contraction coefficient. */
/* SOURCE culvertd.for:1848 */
/*<       cdis=cd >*/
    rconc_1.cdis = *cd;
/* SOURCE culvertd.for:1849 */
/*<       hoverd=hdrat >*/
    rconc_1.hoverd = *hdrat;
/* SOURCE culvertd.for:1850 */
/*<       h=head >*/
    rconc_1.feq_gen_h_d_ = *head;
/* SOURCE culvertd.for:1851 */
/*<       dzvc=dz >*/
    rconc_1.dzvc = *dz;
/* SOURCE culvertd.for:1852 */
/*<       afull=ain >*/
    rconc_1.afull = *ain;
/* SOURCE culvertd.for:1853 */
/*<       d=dup >*/
    rconc_1.feq_gen_d_d_ = *dup;
/* SOURCE culvertd.for:1854 */
/*<       adr=adrs >*/
    rconc_1.adr = *adrs;
/*     Make the first estimate. */
/* SOURCE culvertd.for:1857 */
/*<       cc=0.6 >*/
    *cc = (float).6;
/* SOURCE culvertd.for:1858 */
/*<       cclow=0.0 >*/
    cclow = (float)0.;
/* SOURCE culvertd.for:1859 */
/*<       cchigh=0.0 >*/
    cchigh = (float)0.;
/* SOURCE culvertd.for:1860 */
/*<   100 continue >*/
L100:
/* SOURCE culvertd.for:1861 */
/*<       f=rcon(cc) >*/
    f = rcon_(cc);
/*        WRITE(STDOUT,*) ' FNDCC: CC=',CC,' F=',F */
/* SOURCE culvertd.for:1863 */
/*<       if(abs(f).le.epsf)then >*/
    if (dabs(f) <= epscom_1.epsf) {
/*         Close enough */
/* SOURCE culvertd.for:1865 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:1866 */
/*<       if(f.gt.0.0)then >*/
	if (f > (float)0.) {
/* SOURCE culvertd.for:1867 */
/*<       cchigh=cc >*/
	    cchigh = *cc;
/* SOURCE culvertd.for:1868 */
/*<       fh=f >*/
	    fh = f;
/* SOURCE culvertd.for:1869 */
/*<       if(cclow.eq.0.0)then >*/
	    if (cclow == (float)0.) {
/* SOURCE culvertd.for:1870 */
/*<       cc=0.95*cc >*/
		*cc *= static_cast<double>((float).95);
/* SOURCE culvertd.for:1871 */
/*<       if(cc.le.epsf)then >*/
		if (*cc <= epscom_1.epsf) {
/* SOURCE culvertd.for:1872 */
/*<       write(stdout,*)' FNDCC: NO NEGATIVE RESIDUAL' >*/
		    feq_gen_io_d__174.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__174);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FNDCC: NO NEGATIVE RESIDUAL"), (
			    ftnlen)28);
		    e_wsle();
/* SOURCE culvertd.for:1873 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:1874 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:1875 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertd.for:1876 */
/*<       else >*/
	    } else {
/* SOURCE culvertd.for:1877 */
/*<       goto110 >*/
		goto L110;
/* SOURCE culvertd.for:1878 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:1879 */
/*<       elseif(f.lt.0.0)then >*/
	} else if (f < (float)0.) {
/* SOURCE culvertd.for:1880 */
/*<       cclow=cc >*/
	    cclow = *cc;
/* SOURCE culvertd.for:1881 */
/*<       fl=f >*/
	    fl = f;
/* SOURCE culvertd.for:1882 */
/*<       if(cchigh.eq.0.0)then >*/
	    if (cchigh == (float)0.) {
/* SOURCE culvertd.for:1883 */
/*<       cct=1.05*cc >*/
		cct = static_cast<double>(*cc) * (float)1.05;
/* SOURCE culvertd.for:1884 */
/*<       if(cct.gt.1.0)then >*/
		if (cct > (float)1.) {
/* SOURCE culvertd.for:1885 */
/*<       cct=0.5*(1.0+cc) >*/
		    cct = static_cast<double>((static_cast<double>(*cc) + (float)1.)) * (float).5;
/* SOURCE culvertd.for:1886 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:1887 */
/*<       cc=cct >*/
		*cc = cct;
/* SOURCE culvertd.for:1888 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertd.for:1889 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:1890 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:1891 */
/*<   110 continue >*/
L110:
/* SOURCE culvertd.for:1893 */
/*<       callrgf(1.e-6,epsf,rcon,cclow,cchigh,fl,fh,cc,flag) >*/
	rgf_(&c_b179, &epscom_1.epsf, rcon_, &cclow, &cchigh, &fl, &fh, 
		cc, &feq_gen_flag_d_);
/* SOURCE culvertd.for:1898 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' CC=',CC,' FL=',FL */
/* SOURCE culvertd.for:1902 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:1903 */
/*<       end >*/
} /* fndcc_ */




/* SOURCE culvertd.for:1907 */
/*<       subroutinefndcc2(stdout,dup,zbvc,cc) >*/
/* Subroutine */ int fndcc2_(integer *stdout, real *dup, real *zbvc, real *cc)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real f, fh, fl, cct;
    extern /* Subroutine */ int rgf_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    integer knt, feq_gen_flag_d_;
    extern doublereal rcon2_(real *);
    real cclow, epsfl, cchigh;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__182 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__185 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Estimate the contraction coefficient for type 5 flow at the */
/*     limit of type 1 or type 2 flow.  Results from the limit */
/*     computations are assumed to be in common block TYPLIM. */
/* SOURCE culvertd.for:1916 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:1919 */
/*<       integerstdout >*/
/* SOURCE culvertd.for:1920 */
/*<       realcc,dup,zbvc >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     ZBVC   - bottom elevation at the vena contracta */
/*     CC     - contraction coefficient */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:1929 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertd.for:1930 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertd.for:1931 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertd.for:1932 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertd.for:1933 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:1934 */
/*     Common for finding contraction coefficient for type 5 flow. */
/* SOURCE rconc.cmn:3 */
/*<       integeradr >*/
/* SOURCE rconc.cmn:5 */
/*<       realcdis,hoverd,afull,d,h,dzvc,evc,vhf >*/
/* SOURCE rconc.cmn:7 */
/*<       common/rconc/cdis,hoverd,afull,d,adr,h,dzvc,evc,vhf >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:1937 */
/*<       integerflag,knt >*/
/* SOURCE culvertd.for:1938 */
/*<       realcchigh,cclow,cct,epsfl,f,fh,fl >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:1941 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:1944 */
/*<       realrcon2 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:1947 */
/*<       externalrcon2,rgf >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:1949 */
/*<       epsfl=0.5*epsf >*/
    epsfl = static_cast<double>(epscom_1.epsf) * (float).5;
/*     Set values in common for finding the contraction coefficient. */
/* SOURCE culvertd.for:1951 */
/*<       afull=a2full >*/
    rconc_1.afull = xs2com_1.a2full;
/* SOURCE culvertd.for:1952 */
/*<       d=dup >*/
    rconc_1.feq_gen_d_d_ = *dup;
/* SOURCE culvertd.for:1953 */
/*<       adr=adrxs2 >*/
    rconc_1.adr = xs2com_1.adrxs2;
/*     Compute the specific energy at the vena contracta and the */
/*     full flow velocity head at section 2. */
/*      WRITE(STDOUT,*) ' FNDCC2: Z1L=',Z1L,' Q1L=',Q1L,' A1L=',A1L */
/*      WRITE(STDOUT,*) ' A2FULL=',A2FULL,' Q2L=',Q2L,' ZBVC=',ZBVC */
/*      WRITE(STDOUT,*) ' K1L=',K1L,' K2FULL=',K2FULL */
/* SOURCE culvertd.for:1959 */
/*<       vhf=(q2l/a2full)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(typlim_1.q2l) / xs2com_1.a2full;
    rconc_1.vhf = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/* SOURCE culvertd.for:1960 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / typlim_1.a1l;
    rconc_1.evc = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
	    grvcom_1.grav2) + typlim_1.z1l) - *zbvc) - static_cast<double>(static_cast<double>(appcom_1.applen) * (
	    static_cast<double>(typlim_1.q1l) * typlim_1.q2l)) / (static_cast<double>(typlim_1.k1l) * xs2com_1.k2full);
/*     Make the first estimate. */
/* SOURCE culvertd.for:1964 */
/*<       cc=0.6 >*/
    *cc = (float).6;
/* SOURCE culvertd.for:1965 */
/*<       cclow=0.0 >*/
    cclow = (float)0.;
/* SOURCE culvertd.for:1966 */
/*<       cchigh=0.0 >*/
    cchigh = (float)0.;
/* SOURCE culvertd.for:1967 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE culvertd.for:1968 */
/*<   100 continue >*/
L100:
/* SOURCE culvertd.for:1969 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE culvertd.for:1970 */
/*<       if(knt.gt.100)then >*/
    if (knt > 100) {
/* SOURCE culvertd.for:1971 */
/*<       write(stdout,*)' *BUG:XXX* No convergence in FNDCC2' >*/
	feq_gen_io_d__182.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__182);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* No convergence in FNDCC2"), (ftnlen)
		35);
	e_wsle();
/* SOURCE culvertd.for:1972 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:1973 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:1974 */
/*<       f=rcon2(cc) >*/
    f = rcon2_(cc);
/*        WRITE(STDOUT,*) ' FNDCC2: CC=',CC,' F=',F */
/* SOURCE culvertd.for:1976 */
/*<       if(abs(f).le.epsfl)then >*/
    if (dabs(f) <= epsfl) {
/*         Close enough */
/* SOURCE culvertd.for:1978 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:1979 */
/*<       if(f.gt.0.0)then >*/
	if (f > (float)0.) {
/* SOURCE culvertd.for:1980 */
/*<       cchigh=cc >*/
	    cchigh = *cc;
/* SOURCE culvertd.for:1981 */
/*<       fh=f >*/
	    fh = f;
/* SOURCE culvertd.for:1982 */
/*<       if(cclow.eq.0.0)then >*/
	    if (cclow == (float)0.) {
/* SOURCE culvertd.for:1983 */
/*<       cc=0.95*cc >*/
		*cc *= static_cast<double>((float).95);
/* SOURCE culvertd.for:1984 */
/*<       if(cc.le.epsf)then >*/
		if (*cc <= epscom_1.epsf) {
/* SOURCE culvertd.for:1985 */
/*<       write(stdout,*)' FNDCC2: NO NEGATIVE RESIDUAL.' >*/
		    feq_gen_io_d__185.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__185);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FNDCC2: NO NEGATIVE RESIDUAL."), (
			    ftnlen)30);
		    e_wsle();
/* SOURCE culvertd.for:1986 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:1987 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:1988 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertd.for:1989 */
/*<       else >*/
	    } else {
/* SOURCE culvertd.for:1990 */
/*<       goto110 >*/
		goto L110;
/* SOURCE culvertd.for:1991 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:1992 */
/*<       elseif(f.lt.0.0)then >*/
	} else if (f < (float)0.) {
/* SOURCE culvertd.for:1993 */
/*<       cclow=cc >*/
	    cclow = *cc;
/* SOURCE culvertd.for:1994 */
/*<       fl=f >*/
	    fl = f;
/* SOURCE culvertd.for:1995 */
/*<       if(cchigh.eq.0.0)then >*/
	    if (cchigh == (float)0.) {
/* SOURCE culvertd.for:1996 */
/*<       cct=1.05*cc >*/
		cct = static_cast<double>(*cc) * (float)1.05;
/* SOURCE culvertd.for:1997 */
/*<       if(cct.gt.1.0)then >*/
		if (cct > (float)1.) {
/* SOURCE culvertd.for:1998 */
/*<       cct=0.5*(1.0+cc) >*/
		    cct = static_cast<double>((static_cast<double>(*cc) + (float)1.)) * (float).5;
/* SOURCE culvertd.for:1999 */
/*<       if(cct.ge.1.0-epsf)then >*/
		    if (cct >= static_cast<double>((float)1.) - epscom_1.epsf) {
/* SOURCE culvertd.for:2000 */
/*<       write(stdout,*)' FNDCC2: NO POSITIVE RESIDUAL.' >*/
			feq_gen_io_d__188.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__188);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FNDCC2: NO POSITIVE RESIDUAL."),
				 (ftnlen)30);
			e_wsle();
/* SOURCE culvertd.for:2001 */
/*<       stop'Abnormal stop. Errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2002 */
/*<       endif >*/
		    }
/* SOURCE culvertd.for:2003 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:2004 */
/*<       cc=cct >*/
		*cc = cct;
/* SOURCE culvertd.for:2005 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertd.for:2006 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2007 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2008 */
/*<   110 continue >*/
L110:
/* SOURCE culvertd.for:2010 */
/*<       callrgf(1.e-6,epsfl,rcon2,cclow,cchigh,fl,fh,cc,flag) >*/
	rgf_(&c_b179, &epsfl, rcon2_, &cclow, &cchigh, &fl, &fh, cc, &
		feq_gen_flag_d_);
/* SOURCE culvertd.for:2015 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' CC=',CC,' FL=',FL */
/* SOURCE culvertd.for:2019 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:2020 */
/*<       end >*/
} /* fndcc2_ */




/* SOURCE culvertd.for:2024 */
/*<       subroutinefrovd(stdout,culcls,rovd) >*/
/* Subroutine */ int frovd_(integer *stdout, char *culcls, real *rovd, ftnlen 
	culcls_len)
{
    /* Format strings */
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT RGF CLAIM\
S NONE IN\002,\002 FROVD.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* RGF: MORE THAN 100 ITERATIONS IN\
 FROVD.\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    real f, fl, rb, fr, rbl;
    extern /* Subroutine */ int rgf_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    real rbr;
    integer feq_gen_flag_d_;
    real rbmin, rbmax;
    extern doublereal rrovd_(real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__198 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__200 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__201 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Find the value of relative rounding/beveling that causes */
/*     the type 5/6 limiting slope to match the slope of the culvert. */
/*     Used to assist in estimating the full-flow-inducing condition */
/*     in the culvert for type 5 flow. */
/* SOURCE culvertd.for:2034 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:2037 */
/*<       integerstdout >*/
/* SOURCE culvertd.for:2038 */
/*<       realrovd >*/
/* SOURCE culvertd.for:2039 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     ROVD   - relative rounding/beveling found */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:2047 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertd.for:2048 */
/*       COMMON FOR FINDING THE MATCHING RELATIVE ROUNDING/BEVELING */
/* SOURCE rrovdc.cmn:3 */
/*<       common/rrovdc/class >*/
/* SOURCE rrovdc.cmn:5 */
/*<       character*8class >*/
/* INCLUDE culvertd.for:2049 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:2052 */
/*<       integerflag >*/
/* SOURCE culvertd.for:2053 */
/*<       realf,fl,fr,rb,rbl,rbmax,rbmin,rbr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:2056 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:2059 */
/*<       realrrovd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:2062 */
/*<       externalrgf,rrovd >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:2065 */
/*<    54  >*/
/* SOURCE culvertd.for:2067 */
/*<    60 format(' *BUG:XXX* RGF: MORE THAN 100 ITERATIONS IN FROVD.') >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:2069 */
/*<       class=culcls >*/
/* L54: */
/* L60: */
    s_copy(rrovdc_1.feq_gen_class_d_, culcls, (ftnlen)8, (ftnlen)8);
/*     Since the flow is known to be type 5 it must be true that */
/*     the value of relative rounding/beveling that causes a */
/*     match with the culvert slope is greater than the value */
/*     that currently exists for the culvert.  That is the culvert */
/*     slope is already known to be larger than the limit slope */
/*     for type 6 flow. */
/* SOURCE culvertd.for:2078 */
/*<       rbmin=rbval >*/
    rbmin = cdcom_1.rbval;
/* SOURCE culvertd.for:2080 */
/*<       if(culcls.eq.'BOX')then >*/
    if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) == 0) {
/* SOURCE culvertd.for:2081 */
/*<       rbmax=0.06 >*/
	rbmax = (float).06;
/* SOURCE culvertd.for:2082 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:2083 */
/*<       if(nbar.lt.0.019)then >*/
	if (cdcom_1.nbar < (float).019) {
/*         Barrel is smooth. */
/* SOURCE culvertd.for:2085 */
/*<       rbmax=0.06 >*/
	    rbmax = (float).06;
/* SOURCE culvertd.for:2086 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:2087 */
/*<       rbmax=0.03 >*/
	    rbmax = (float).03;
/* SOURCE culvertd.for:2088 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2089 */
/*<       endif >*/
    }
/*     25 August 2004:  Supply an initial value. */
/* SOURCE culvertd.for:2093 */
/*<       rovd=0.5*(rbmin+rbmax) >*/
    *rovd = static_cast<double>((static_cast<double>(rbmin) + rbmax)) * (float).5;
/* SOURCE culvertd.for:2094 */
/*<       rb=rovd >*/
    rb = *rovd;
/* SOURCE culvertd.for:2096 */
/*<       fl=0.0 >*/
    fl = (float)0.;
/* SOURCE culvertd.for:2097 */
/*<       fr=0.0 >*/
    fr = (float)0.;
/* SOURCE culvertd.for:2098 */
/*<       f=rrovd(rb) >*/
    f = rrovd_(&rb);
/* SOURCE culvertd.for:2099 */
/*<       if(abs(f).le.epsf)then >*/
    if (dabs(f) <= epscom_1.epsf) {
/*       DONE */
/* SOURCE culvertd.for:2101 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:2102 */
/*<       if(f.lt.0.0)then >*/
	if (f < (float)0.) {
/* SOURCE culvertd.for:2103 */
/*<       rbl=rb >*/
	    rbl = rb;
/* SOURCE culvertd.for:2104 */
/*<       fl=f >*/
	    fl = f;
/* SOURCE culvertd.for:2105 */
/*<       if(fr.eq.0.0)then >*/
	    if (fr == (float)0.) {
/* SOURCE culvertd.for:2106 */
/*<       f=rrovd(rbmax) >*/
		f = rrovd_(&rbmax);
/* SOURCE culvertd.for:2107 */
/*<       if(f.lt.0.0)then >*/
		if (f < (float)0.) {
/*             Maximum value reached and no match.  Take maximum value. */
/* SOURCE culvertd.for:2109 */
/*<       rovd=rbmax >*/
		    *rovd = rbmax;
/* SOURCE culvertd.for:2110 */
/*<       return >*/
		    return 0;
/* SOURCE culvertd.for:2111 */
/*<       else >*/
		} else {
/* SOURCE culvertd.for:2112 */
/*<       fr=f >*/
		    fr = f;
/* SOURCE culvertd.for:2113 */
/*<       rbr=rbmax >*/
		    rbr = rbmax;
/* SOURCE culvertd.for:2114 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:2115 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2116 */
/*<       elseif(f.gt.0.0)then >*/
	} else if (f > (float)0.) {
/* SOURCE culvertd.for:2117 */
/*<       rbr=rb >*/
	    rbr = rb;
/* SOURCE culvertd.for:2118 */
/*<       fr=f >*/
	    fr = f;
/* SOURCE culvertd.for:2119 */
/*<       if(fl.eq.0.0)then >*/
	    if (fl == (float)0.) {
/* SOURCE culvertd.for:2120 */
/*<       f=rrovd(rbmin) >*/
		f = rrovd_(&rbmin);
/* SOURCE culvertd.for:2121 */
/*<       if(f.gt.0.0)then >*/
		if (f > (float)0.) {
/*             Minimum value reached.  Should not happen. */
/* SOURCE culvertd.for:2123 */
/*<       write(stdout,*)' *BUG:XXX Min. RB value problem in FROVD' >*/
		    feq_gen_io_d__198.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__198);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX Min. RB value problem in\
 FROVD"), (ftnlen)40);
		    e_wsle();
/* SOURCE culvertd.for:2124 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2125 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:2126 */
/*<       fl=f >*/
		fl = f;
/* SOURCE culvertd.for:2127 */
/*<       rbl=rbmin >*/
		rbl = rbmin;
/* SOURCE culvertd.for:2128 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2129 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' FROVD: RBL=',RBL,' RBR=',RBR */
/*        WRITE(STDOUT,*) ' FROVD: FL=',FL,' FR=',FR */
/* SOURCE culvertd.for:2132 */
/*<       callrgf(epsarg,epsf,rrovd,rbl,rbr,fl,fr,rovd,flag) >*/
	rgf_(&epscom_1.epsarg, &epscom_1.epsf, rrovd_, &rbl, &rbr, &fl, 
		&fr, rovd, &feq_gen_flag_d_);
/* SOURCE culvertd.for:2137 */
/*<       if(flag.eq.1)then >*/
	if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertd.for:2138 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__200.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__200);
	    e_wsfe();
/* SOURCE culvertd.for:2139 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2140 */
/*<       elseif(flag.eq.2)then >*/
	} else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertd.for:2141 */
/*<       write(stdout,60) >*/
	    feq_gen_io_d__201.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__201);
	    e_wsfe();
/* SOURCE culvertd.for:2142 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2143 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2144 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:2145 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:2146 */
/*<       end >*/
} /* frovd_ */




/* SOURCE culvertd.for:2150 */
/*<       subroutineappro(stdout,cd,vhl,qroad,conflg,nsflag) >*/
/* Subroutine */ int appro_(integer *stdout, real *cd, real *vhl, real *qroad,
	 integer *conflg, integer *nsflag)
{
    /* Format strings */
    static char fmt_53[] = "(\002 *WRN:537* TABID=\002,a,\002 overflow seeki\
ng XS1 depth for\002,\002 flow=\002,f10.1,/,10x,\002 in subroutine APPRO.\
\002)";
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 APPRO.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS\
 IN APPRO.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real f, y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real fh, fl, yc, dy;
    integer feq_gen_flag_d_;
    real fold;
    extern doublereal rapp_(real *);
    real yold, ymax, ylow;
    char tabid[16];
    real yhigh;
    extern /* Subroutine */ int fndcde_(integer *, integer *, real *, real *);
    integer minflg;
    extern integer gettbn_(integer *);
    extern doublereal fmxarg_(integer *);
    extern /* Subroutine */ int regflt_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    extern integer lenstr_(char *, ftnlen);
    real ystart;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__214 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__215 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__218 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__220 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__221 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the elevation at section 1 given the flow and the elevation */
/*     at section 2.  We assume that all values at section 2 are known. */
/*     CD gives the discharge coefficient for entrance losses and */
/*     VHL is the velocity head to which it is applied.  Thus APPRO */
/*     can be used for all types of flow.  CD is based on the known */
/*     target area at section 1.  APPRO will be used to compute the */
/*     residual at section 1 between the target elevation and the */
/*     estimated elevation. */
/* SOURCE culvertd.for:2164 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:2166 */
/*<       integerconflg,nsflag,stdout >*/
/* SOURCE culvertd.for:2167 */
/*<       realcd,qroad,vhl >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CD     - Discharge coefficient */
/*     VHL    - Provides the velocity head to use in computed the */
/*               entrance losses */
/*     QROAD  - Flow over the roadway */
/*     CONFLG - CONFLG=0: flow contracts as it enters the culvert and */
/*              CONFLG=1: flow expands as it enters the culver */
/*     NSFLAG - No solution flag */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:2180 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertd.for:2181 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertd.for:2182 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertd.for:2183 */
/*     Common for function RAPP in FEQUTL */
/* SOURCE rappc.cmn:3 */
/*<       common/rappc/cdin,conf,vhloss >*/
/* SOURCE rappc.cmn:4 */
/*<       integerconf >*/
/* SOURCE rappc.cmn:5 */
/*<       realcdin,vhloss >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:2186 */
/*<       integerflag,minflg >*/
/* SOURCE culvertd.for:2187 */
/*<       realdy,f,fh,fl,fold,y,yc,yhigh,ylow,ymax,yold,ystart >*/
/* SOURCE culvertd.for:2188 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:2191 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:2194 */
/*<       integergettbn,lenstr >*/
/* SOURCE culvertd.for:2195 */
/*<       realfmxarg,rapp >*/
/* SOURCE culvertd.for:2196 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:2199 */
/*<       externalfmxarg,fndcde,gettbn,rapp,regflt >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:2202 */
/*<    53  >*/
/* SOURCE culvertd.for:2204 */
/*<    54  >*/
/* SOURCE culvertd.for:2206 */
/*<    60 format(' *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS IN APPRO.') >*/
/* *********************************************************************** */
/*     SET VALUES FOR LOCAL COMMON BLOCK */
/* SOURCE culvertd.for:2209 */
/*<       vhloss=vhl >*/
/* L53: */
/* L54: */
/* L60: */
    rappc_1.vhloss = *vhl;
/* SOURCE culvertd.for:2210 */
/*<       cdin=cd >*/
    rappc_1.cdin = *cd;
/* SOURCE culvertd.for:2212 */
/*<       q1=q2+qroad >*/
    xs1com_1.q1 = static_cast<double>(xs2com_1.q2) + *qroad;
/*     CLEAR NO SOLUTION FLAG INDICATING THAT THERE IS A SOLUTION */
/* SOURCE culvertd.for:2215 */
/*<       nsflag=0 >*/
    *nsflag = 0;
/* SOURCE culvertd.for:2217 */
/*<       ymax=fmxarg(adrxs1) >*/
    ymax = fmxarg_(&xs1com_1.adrxs1);
/* SOURCE culvertd.for:2218 */
/*<       minflg=0 >*/
    minflg = 0;
/*     CHECK FOR A SOLUTION */
/*     Try the value at the known depth */
/* SOURCE culvertd.for:2221 */
/*<       f=rapp(yuptru) >*/
    f = rapp_(&xs1com_1.yuptru);
/*      WRITE(STDOUT,*) ' APPRO: YUPTRU=',YUPTRU,' F=',F,' Q2=',Q2, */
/*     A   ' Y2=',Y2,' CONF=',CONF */
/* SOURCE culvertd.for:2224 */
/*<       if(abs(f).le.epsabs)then >*/
    if (dabs(f) <= epscom_1.epsabs) {
/*       Close enough. */
/*        WRITE(STDOUT,*) ' APPRO: FIRST RETURN. Y1=', Y1 */
/* SOURCE culvertd.for:2227 */
/*<       conflg=conf >*/
	*conflg = rappc_1.conf;
/* SOURCE culvertd.for:2228 */
/*<       return >*/
	return 0;
/* SOURCE culvertd.for:2229 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:2230 */
/*<       if(f.lt.0.0)then >*/
	if (f < (float)0.) {
/*         Start search for sign change from YUPTRU */
/* SOURCE culvertd.for:2232 */
/*<       ystart=yuptru >*/
	    ystart = xs1com_1.yuptru;
/* SOURCE culvertd.for:2233 */
/*<       else >*/
	} else {
/*         Evaluate at the critical depth if critical depth */
/*         differs from YUPTRU. */
/* SOURCE culvertd.for:2236 */
/*<       yc=yuptru >*/
	    yc = xs1com_1.yuptru;
/* SOURCE culvertd.for:2237 */
/*<       callfndcde(stdout,adrxs1,q1,yc) >*/
	    fndcde_(stdout, &xs1com_1.adrxs1, &xs1com_1.q1, &yc);
/* SOURCE culvertd.for:2240 */
/*<       if(abs(yuptru-yc).lt.epsarg)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(xs1com_1.yuptru) - yc, dabs(feq_gen_r_d_1)) < epscom_1.epsarg) {
/*           Start search at YUPTRU and stop at minimum. */
/* SOURCE culvertd.for:2242 */
/*<       minflg=1 >*/
		minflg = 1;
/* SOURCE culvertd.for:2243 */
/*<       ystart=yuptru >*/
		ystart = xs1com_1.yuptru;
/* SOURCE culvertd.for:2244 */
/*<       else >*/
	    } else {
/* SOURCE culvertd.for:2245 */
/*<       f=rapp(yc) >*/
		f = rapp_(&yc);
/*            WRITE(STDOUT,*) ' APPRO: YC=',YC,' F=',F, ' CONF=',CONF */
/* SOURCE culvertd.for:2247 */
/*<       if(f.lt.0.0)then >*/
		if (f < (float)0.) {
/*             Start search at YC */
/* SOURCE culvertd.for:2249 */
/*<       ystart=yc >*/
		    ystart = yc;
/* SOURCE culvertd.for:2250 */
/*<       else >*/
		} else {
/*             Start search at YUPTRU and stop at minimum */
/* SOURCE culvertd.for:2252 */
/*<       minflg=1 >*/
		    minflg = 1;
/* SOURCE culvertd.for:2253 */
/*<       ystart=yuptru >*/
		    ystart = xs1com_1.yuptru;
/* SOURCE culvertd.for:2254 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:2255 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2256 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2257 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:2259 */
/*<       if(minflg.eq.0)then >*/
    if (minflg == 0) {
/*       At least one subcritical solution exists.  Search upward for it. */
/* SOURCE culvertd.for:2261 */
/*<       ylow=0.0 >*/
	ylow = (float)0.;
/* SOURCE culvertd.for:2262 */
/*<       yhigh=0.0 >*/
	yhigh = (float)0.;
/* SOURCE culvertd.for:2263 */
/*<       y=ystart >*/
	y = ystart;
/* SOURCE culvertd.for:2264 */
/*<       dy=yuptru/8.0 >*/
	dy = static_cast<double>(xs1com_1.yuptru) / (float)8.;
/*       SEARCH FOR SIGN CHANGE */
/* SOURCE culvertd.for:2266 */
/*<   100 continue >*/
L100:
/* SOURCE culvertd.for:2267 */
/*<       if(f.lt.0.0)then >*/
	if (f < (float)0.) {
/* SOURCE culvertd.for:2268 */
/*<       fl=f >*/
	    fl = f;
/* SOURCE culvertd.for:2269 */
/*<       ylow=y >*/
	    ylow = y;
/* SOURCE culvertd.for:2270 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:2271 */
/*<       fh=f >*/
	    fh = f;
/* SOURCE culvertd.for:2272 */
/*<       yhigh=y >*/
	    yhigh = y;
/* SOURCE culvertd.for:2273 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2274 */
/*<       if(ylow.eq.0.0.or.yhigh.eq.0.0)then >*/
	if (ylow == (float)0. || yhigh == (float)0.) {
/* SOURCE culvertd.for:2275 */
/*<       y=y+dy >*/
	    y += dy;
/* SOURCE culvertd.for:2276 */
/*<       dy=1.25*dy >*/
	    dy *= static_cast<double>((float)1.25);
/* SOURCE culvertd.for:2277 */
/*<       if(y.gt.ymax)then >*/
	    if (y > ymax) {
/* SOURCE culvertd.for:2278 */
/*<       tabid=get_tabid(gettbn(adrxs1)) >*/
		feq_gen_i_d_1 = gettbn_(&xs1com_1.adrxs1);
		feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
		s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE culvertd.for:2279 */
/*<       write(stdout,53)tabid(1:lenstr(tabid)),q2 >*/
		feq_gen_io_d__214.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__214);
		do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.q2, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertd.for:2280 */
/*<       write(stdout,*)' Maximum depth=',ymax >*/
		feq_gen_io_d__215.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__215);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Maximum depth="), (ftnlen)15);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		e_wsle();
/* SOURCE culvertd.for:2281 */
/*<       nsflag=2 >*/
		*nsflag = 2;
/* SOURCE culvertd.for:2282 */
/*<       conflg=conf >*/
		*conflg = rappc_1.conf;
/* SOURCE culvertd.for:2283 */
/*<       z1=zb1 >*/
		xs1com_1.z1 = xs1com_1.zb1;
/* SOURCE culvertd.for:2284 */
/*<       return >*/
		return 0;
/* SOURCE culvertd.for:2285 */
/*<       else >*/
	    } else {
/* SOURCE culvertd.for:2286 */
/*<       f=rapp(y) >*/
		f = rapp_(&y);
/*              WRITE(STDOUT,*) ' MINFLG=',MINFLG,' Y=',Y,' F=',F */
/* SOURCE culvertd.for:2288 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertd.for:2289 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2290 */
/*<       endif >*/
	}
/*         Change of sign found here. */
/* SOURCE culvertd.for:2292 */
/*<       else >*/
    } else {
/*       There may be no solution.  Search from YSTART and stop */
/*       when there is an increase in the residual.  Then if the */
/*       residual is negative, continue search for a sign change. */
/*       If not negative, there is no subcritical solution. */
/* SOURCE culvertd.for:2297 */
/*<       fold=f >*/
	fold = f;
/* SOURCE culvertd.for:2298 */
/*<       yold=ystart >*/
	yold = ystart;
/*        WRITE(STDOUT,*) ' YOLD=',YOLD,' FOLD=',FOLD */
/* SOURCE culvertd.for:2300 */
/*<       y=ystart >*/
	y = ystart;
/* SOURCE culvertd.for:2301 */
/*<       dy=0.0125 >*/
	dy = (float).0125;
/* SOURCE culvertd.for:2302 */
/*<   200 continue >*/
L200:
/* SOURCE culvertd.for:2303 */
/*<       y=y+dy >*/
	y += dy;
/* SOURCE culvertd.for:2304 */
/*<       f=rapp(y) >*/
	f = rapp_(&y);
/*          WRITE(STDOUT,*) ' MIN. SEARCH. Y=',Y,' F=',F */
/* SOURCE culvertd.for:2306 */
/*<       if(f.gt.fold)then >*/
	if (f > fold) {
/*           Stop the search.  FOLD is the minimum value found. */
/* SOURCE culvertd.for:2308 */
/*<       if(abs(fold).le.epsabs)then >*/
	    if (dabs(fold) <= epscom_1.epsabs) {
/*             Close enough.  Reset the values. */
/* SOURCE culvertd.for:2310 */
/*<       f=rapp(yold) >*/
		f = rapp_(&yold);
/* SOURCE culvertd.for:2311 */
/*<       conflg=conf >*/
		*conflg = rappc_1.conf;
/*              WRITE(STDOUT,*) ' APPRO: SECOND RETURN. Y1=',Y1 */
/* SOURCE culvertd.for:2313 */
/*<       return >*/
		return 0;
/* SOURCE culvertd.for:2314 */
/*<       else >*/
	    } else {
/* SOURCE culvertd.for:2315 */
/*<       if(fold.lt.0.0)then >*/
		if (fold < (float)0.) {
/* SOURCE culvertd.for:2316 */
/*<       ylow=0.0 >*/
		    ylow = (float)0.;
/* SOURCE culvertd.for:2317 */
/*<       yhigh=0.0 >*/
		    yhigh = (float)0.;
/* SOURCE culvertd.for:2318 */
/*<       f=fold >*/
		    f = fold;
/* SOURCE culvertd.for:2319 */
/*<       y=yold >*/
		    y = yold;
/* SOURCE culvertd.for:2320 */
/*<   210 continue >*/
L210:
/* SOURCE culvertd.for:2321 */
/*<       if(f.lt.0.0)then >*/
		    if (f < (float)0.) {
/* SOURCE culvertd.for:2322 */
/*<       ylow=y >*/
			ylow = y;
/* SOURCE culvertd.for:2323 */
/*<       fl=f >*/
			fl = f;
/* SOURCE culvertd.for:2324 */
/*<       else >*/
		    } else {
/* SOURCE culvertd.for:2325 */
/*<       yhigh=y >*/
			yhigh = y;
/* SOURCE culvertd.for:2326 */
/*<       fh=f >*/
			fh = f;
/* SOURCE culvertd.for:2327 */
/*<       endif >*/
		    }
/* SOURCE culvertd.for:2328 */
/*<       if(ylow.eq.0.0.or.yhigh.eq.0.0)then >*/
		    if (ylow == (float)0. || yhigh == (float)0.) {
/* SOURCE culvertd.for:2329 */
/*<       y=y+dy >*/
			y += dy;
/* SOURCE culvertd.for:2330 */
/*<       if(y.gt.ymax)then >*/
			if (y > ymax) {
/* SOURCE culvertd.for:2331 */
/*<       write(stdout,53)gettbn(adrxs1),q2 >*/
			    feq_gen_io_d__218.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__218);
			    feq_gen_i_d_1 = gettbn_(&xs1com_1.adrxs1);
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.q2, (ftnlen)
				    sizeof(real));
			    e_wsfe();
/* SOURCE culvertd.for:2332 */
/*<       nsflag=2 >*/
			    *nsflag = 2;
/* SOURCE culvertd.for:2333 */
/*<       conflg=conf >*/
			    *conflg = rappc_1.conf;
/* SOURCE culvertd.for:2334 */
/*<       z1=zb1 >*/
			    xs1com_1.z1 = xs1com_1.zb1;
/* SOURCE culvertd.for:2335 */
/*<       return >*/
			    return 0;
/* SOURCE culvertd.for:2336 */
/*<       else >*/
			} else {
/* SOURCE culvertd.for:2337 */
/*<       f=rapp(y) >*/
			    f = rapp_(&y);
/*              WRITE(STDOUT,*) ' MINFLG=',MINFLG,' Y=',Y,' F=',F */
/* SOURCE culvertd.for:2339 */
/*<       goto210 >*/
			    goto L210;
/* SOURCE culvertd.for:2340 */
/*<       endif >*/
			}
/* SOURCE culvertd.for:2341 */
/*<       endif >*/
		    }
/* SOURCE culvertd.for:2342 */
/*<       else >*/
		} else {
/*               No subcritical solution. */
/* SOURCE culvertd.for:2344 */
/*<       z1=zb1+0.5*ystart >*/
		    xs1com_1.z1 = static_cast<double>(xs1com_1.zb1) + static_cast<double>(ystart) * (float).5;
/*                WRITE(STDOUT,*) ' APPRO: No solution. Y1=', */
/*     A                      0.5*YSTART */
/* SOURCE culvertd.for:2347 */
/*<       nsflag=1 >*/
		    *nsflag = 1;
/* SOURCE culvertd.for:2348 */
/*<       conflg=conf >*/
		    *conflg = rappc_1.conf;
/* SOURCE culvertd.for:2349 */
/*<       return >*/
		    return 0;
/* SOURCE culvertd.for:2350 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:2351 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2352 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:2353 */
/*<       fold=f >*/
	    fold = f;
/* SOURCE culvertd.for:2354 */
/*<       yold=y >*/
	    yold = y;
/* SOURCE culvertd.for:2355 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE culvertd.for:2356 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2357 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' SIGN CHANGE HERE.' */
/*      WRITE(STDOUT,*) ' YLOW=',YLOW,' FL=',FL */
/*      WRITE(STDOUT,*) ' YHIGH=',YHIGH,' FH=',FH */
/* SOURCE culvertd.for:2363 */
/*<       callregflt(epsarg,epsabs,rapp,ylow,yhigh,fl,fh,y1,flag) >*/
    regflt_(&epscom_1.epsarg, &epscom_1.epsabs, rapp_, &ylow, &yhigh, &
	    fl, &fh, &xs1com_1.y1, &feq_gen_flag_d_);
/* SOURCE culvertd.for:2367 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertd.for:2368 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__220.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__220);
	e_wsfe();
/* SOURCE culvertd.for:2369 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2370 */
/*<       elseif(flag.eq.2)then >*/
    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertd.for:2371 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__221.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__221);
	e_wsfe();
/* SOURCE culvertd.for:2372 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2373 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' APPRO: Y1=',Y1 */
/*     FINAL RESULTS IN XS1COM */
/*      WRITE(STDOUT,*) ' APPRO: CONF=', CONF */
/* SOURCE culvertd.for:2378 */
/*<       conflg=conf >*/
    *conflg = rappc_1.conf;
/* SOURCE culvertd.for:2379 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:2380 */
/*<       end >*/
} /* appro_ */




/* SOURCE culvertd.for:2384 */
/*<       subroutinef44to4(stdout,nsflag) >*/
/* Subroutine */ int f44to4_(integer *stdout, integer *nsflag)
{
    /* Format strings */
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 F44TO4.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS\
 IN F44TO4.\002)";

    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real fl, fr, yc, yl, yr, vh44;
    integer feq_gen_flag_d_;
    extern doublereal r44to4_(real *);
    extern /* Subroutine */ int fndcde_(integer *, integer *, real *, real *),
	     regflt_(real *, real *, FeqCallback3, real *, real *, real *, real *, 
	    real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__229 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__230 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the values at section 4 given values at section 44. */
/*     All values for section 44 in its common block are known. */
/* SOURCE culvertd.for:2392 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:2395 */
/*<       integernsflag,stdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NSFLAG - No solution flag */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:2402 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertd.for:2403 */
/* SOURCE x44com.cmn:2 */
/*<        >*/
/* SOURCE x44com.cmn:6 */
/*<       integeradrs44,stat44 >*/
/* SOURCE x44com.cmn:8 */
/*<        >*/
/* INCLUDE culvertd.for:2404 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:2405 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertd.for:2406 */
/*     Common for function DEPM, and F4TO44 in FEQUTL */
/* SOURCE depmc.cmn:3 */
/*<       common/depmc/mfcon,m44,m3,mcase,e44,e4 >*/
/* SOURCE depmc.cmn:4 */
/*<       integermcase >*/
/* SOURCE depmc.cmn:5 */
/*<       realmfcon,m44,m3,e44,e4 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:2409 */
/*<       integerflag >*/
/* SOURCE culvertd.for:2410 */
/*<       realfl,fr,vh44,yc,yl,yr >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:2413 */
/*<       realr44to4 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:2416 */
/*<       externalfndcde,r44to4,regflt >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:2419 */
/*<    54  >*/
/* SOURCE culvertd.for:2421 */
/*<    60 format(' *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS IN F44TO4.') >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:2423 */
/*<       nsflag=0 >*/
/* L54: */
/* L60: */
    *nsflag = 0;
/*     Flow at the two sections is always the same.  Road flow */
/*     contribution is assumed to take place between sections 43 and */
/*     sections 44 where we use a simple momentum balance. */
/* SOURCE culvertd.for:2428 */
/*<       q4=q44 >*/
    xs4com_1.q4 = x44com_1.q44;
/* SOURCE culvertd.for:2430 */
/*<       if(adrxs4.eq.adrs44.and.zb4.eq.zb44)then >*/
    if (xs4com_1.adrxs4 == x44com_1.adrs44 && xs4com_1.zb4 == x44com_1.zb44) {
/*       The departure reach is horizontal and prismatic.  Transfer */
/*       values from section 44 to section 4. */
/* SOURCE culvertd.for:2433 */
/*<       z4=z44 >*/
	xs4com_1.z4 = x44com_1.z44;
/* SOURCE culvertd.for:2434 */
/*<       y4=y44 >*/
	xs4com_1.y4 = x44com_1.y44;
/* SOURCE culvertd.for:2435 */
/*<       a4=a44 >*/
	xs4com_1.a4 = x44com_1.a44;
/* SOURCE culvertd.for:2436 */
/*<       t4=t44 >*/
	xs4com_1.t4 = x44com_1.t44;
/* SOURCE culvertd.for:2437 */
/*<       j4=j44 >*/
	xs4com_1.j4 = x44com_1.j44;
/* SOURCE culvertd.for:2438 */
/*<       bet4=bet44 >*/
	xs4com_1.bet4 = x44com_1.bet44;
/* SOURCE culvertd.for:2439 */
/*<       alp4=alp44 >*/
	xs4com_1.alp4 = x44com_1.alp44;
/* SOURCE culvertd.for:2440 */
/*<       k4=k44 >*/
	xs4com_1.k4 = x44com_1.k44;
/* SOURCE culvertd.for:2441 */
/*<       else >*/
    } else {
/*       Departure reach is either non-prismatic or non-horizontal. */
/*       Compute values at section 4.   Find critical depth at */
/*       section 4.  Estimate the depth at section 4. */
/* SOURCE culvertd.for:2446 */
/*<       yc=y44+zb44-zb4 >*/
	yc = static_cast<double>(static_cast<double>(x44com_1.y44) + x44com_1.zb44) - xs4com_1.zb4;
/* SOURCE culvertd.for:2447 */
/*<       if(yc.le.0.0)then >*/
	if (yc <= (float)0.) {
/* SOURCE culvertd.for:2448 */
/*<       yc=0.1 >*/
	    yc = (float).1;
/* SOURCE culvertd.for:2449 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2450 */
/*<       callfndcde(stdout,adrxs4,q4,yc) >*/
	fndcde_(stdout, &xs4com_1.adrxs4, &xs4com_1.q4, &yc);
/*       Critical flow at section 4 gives a lower bound for the */
/*       flow depth at section 4.  Estimate the specific energy */
/*       available at section 4. */
/* SOURCE culvertd.for:2459 */
/*<       vh44=alp44*(q44/a44)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(x44com_1.q44) / x44com_1.a44;
	vh44 = static_cast<double>(static_cast<double>(x44com_1.alp44) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertd.for:2460 */
/*<       ztel44=zb44+y44+vh44 >*/
	x44com_1.ztel44 = static_cast<double>(static_cast<double>(x44com_1.zb44) + x44com_1.y44) + vh44;
/* SOURCE culvertd.for:2462 */
/*<       e4=ztel44-zb4 >*/
	depmc_1.e4 = static_cast<double>(x44com_1.ztel44) - xs4com_1.zb4;
/*       Upper bound for depth at section 4 is the specific energy. */
/* SOURCE culvertd.for:2466 */
/*<       y4=e4 >*/
	xs4com_1.y4 = depmc_1.e4;
/* SOURCE culvertd.for:2468 */
/*<       if(y4.le.yc)then >*/
	if (xs4com_1.y4 <= yc) {
/*         No  solution exists. */
/* SOURCE culvertd.for:2470 */
/*<       nsflag=1 >*/
	    *nsflag = 1;
/* SOURCE culvertd.for:2471 */
/*<       y4=0.0 >*/
	    xs4com_1.y4 = (float)0.;
/* SOURCE culvertd.for:2472 */
/*<       else >*/
	} else {
/*         A subcritical solution exists.  Try to find it. */
/* SOURCE culvertd.for:2475 */
/*<       yl=yc >*/
	    yl = yc;
/* SOURCE culvertd.for:2476 */
/*<       fl=r44to4(yl) >*/
	    fl = r44to4_(&yl);
/* SOURCE culvertd.for:2477 */
/*<       yr=y4 >*/
	    yr = xs4com_1.y4;
/* SOURCE culvertd.for:2478 */
/*<       fr=r44to4(yr) >*/
	    fr = r44to4_(&yr);
/* SOURCE culvertd.for:2480 */
/*<       callregflt(epsarg,epsabs,r44to4,yl,yr,fl,fr,y4,flag) >*/
	    regflt_(&epscom_1.epsarg, &epscom_1.epsabs, r44to4_, &yl, &
		    yr, &fl, &fr, &xs4com_1.y4, &feq_gen_flag_d_);
/* SOURCE culvertd.for:2485 */
/*<       z4=y4+zb4 >*/
	    xs4com_1.z4 = static_cast<double>(xs4com_1.y4) + xs4com_1.zb4;
/*          WRITE(STDOUT,*) ' F44TO4: ZB4=',ZB4,' Z4=',Z4 */
/* SOURCE culvertd.for:2488 */
/*<       if(flag.eq.1)then >*/
	    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertd.for:2489 */
/*<       write(stdout,54) >*/
		feq_gen_io_d__229.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__229);
		e_wsfe();
/* SOURCE culvertd.for:2490 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2491 */
/*<       elseif(flag.eq.2)then >*/
	    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertd.for:2492 */
/*<       write(stdout,60) >*/
		feq_gen_io_d__230.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__230);
		e_wsfe();
/* SOURCE culvertd.for:2493 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2494 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2495 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2496 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:2498 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:2499 */
/*<       end >*/
} /* f44to4_ */




/* SOURCE culvertd.for:2503 */
/*<       subroutinef4to44(stdout,nsflag) >*/
/* Subroutine */ int f4to44_(integer *stdout, integer *nsflag)
{
    /* Format strings */
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 F4TO44.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS\
 IN F4TO44.\002)";

    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real fl, fr, yl, yr, vh4, e44c;
    integer feq_gen_flag_d_;
    extern doublereal r4to44_(real *);
    extern /* Subroutine */ int fndcde_(integer *, integer *, real *, real *),
	     regflt_(real *, real *, FeqCallback3, real *, real *, real *, real *, 
	    real *, integer *), xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__238 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__239 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the values at section 44 given values at section 4. */
/*     All values for section 4 in its common block are known. */
/* SOURCE culvertd.for:2511 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:2514 */
/*<       integernsflag,stdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NSFLAG - No solution flag */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:2521 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertd.for:2522 */
/* SOURCE x44com.cmn:2 */
/*<        >*/
/* SOURCE x44com.cmn:6 */
/*<       integeradrs44,stat44 >*/
/* SOURCE x44com.cmn:8 */
/*<        >*/
/* INCLUDE culvertd.for:2523 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:2524 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertd.for:2525 */
/*     Common for function DEPM, and F4TO44 in FEQUTL */
/* SOURCE depmc.cmn:3 */
/*<       common/depmc/mfcon,m44,m3,mcase,e44,e4 >*/
/* SOURCE depmc.cmn:4 */
/*<       integermcase >*/
/* SOURCE depmc.cmn:5 */
/*<       realmfcon,m44,m3,e44,e4 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:2528 */
/*<       integerflag >*/
/* SOURCE culvertd.for:2529 */
/*<       reale44c,fl,fr,vh4,yl,yr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:2532 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:2535 */
/*<       realr4to44 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:2538 */
/*<       externalfndcde,r4to44,regflt,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:2541 */
/*<    54  >*/
/* SOURCE culvertd.for:2543 */
/*<    60 format(' *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS IN F4TO44.') >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:2545 */
/*<       nsflag=0 >*/
/* L54: */
/* L60: */
    *nsflag = 0;
/*     Flow at the two sections is always the same.  Road flow */
/*     contribution is assumed to take place between sections 43 and */
/*     sections 44 where we use a simple momentum balance. */
/* SOURCE culvertd.for:2550 */
/*<       q44=q4 >*/
    x44com_1.q44 = xs4com_1.q4;
/* SOURCE culvertd.for:2552 */
/*<       if(adrxs4.eq.adrs44.and.zb4.eq.zb44)then >*/
    if (xs4com_1.adrxs4 == x44com_1.adrs44 && xs4com_1.zb4 == x44com_1.zb44) {
/*       The departure reach is horizontal and prismatic.  Transfer */
/*       values from section 4 to section 44. */
/* SOURCE culvertd.for:2555 */
/*<       z44=z4 >*/
	x44com_1.z44 = xs4com_1.z4;
/* SOURCE culvertd.for:2556 */
/*<       y44=y4 >*/
	x44com_1.y44 = xs4com_1.y4;
/* SOURCE culvertd.for:2557 */
/*<       a44=a4 >*/
	x44com_1.a44 = xs4com_1.a4;
/* SOURCE culvertd.for:2558 */
/*<       t44=t4 >*/
	x44com_1.t44 = xs4com_1.t4;
/* SOURCE culvertd.for:2559 */
/*<       j44=j4 >*/
	x44com_1.j44 = xs4com_1.j4;
/* SOURCE culvertd.for:2560 */
/*<       bet44=bet4 >*/
	x44com_1.bet44 = xs4com_1.bet4;
/* SOURCE culvertd.for:2561 */
/*<       alp44=alp4 >*/
	x44com_1.alp44 = xs4com_1.alp4;
/* SOURCE culvertd.for:2562 */
/*<       k44=k4 >*/
	x44com_1.k44 = xs4com_1.k4;
/* SOURCE culvertd.for:2563 */
/*<       else >*/
    } else {
/*       Departure reach is either non-prismatic or non-horizontal. */
/*       Compute values at section 44.   Find critical depth at */
/*       section 44.  Estimate starting depth. */
/* SOURCE culvertd.for:2568 */
/*<       y44c=y4+zb4-zb44 >*/
	x44com_1.y44c = static_cast<double>(static_cast<double>(xs4com_1.y4) + xs4com_1.zb4) - x44com_1.zb44;
/* SOURCE culvertd.for:2569 */
/*<       if(y44c.le.0.0)then >*/
	if (x44com_1.y44c <= (float)0.) {
/* SOURCE culvertd.for:2570 */
/*<       y44c=0.1 >*/
	    x44com_1.y44c = (float).1;
/* SOURCE culvertd.for:2571 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2572 */
/*<       callfndcde(stdout,adrs44,q44,y44c) >*/
	fndcde_(stdout, &x44com_1.adrs44, &x44com_1.q44, &x44com_1.y44c);
/*        WRITE(STDOUT,*) ' F4TO44: YC AT 44=',Y44C */
/* SOURCE culvertd.for:2577 */
/*<       y44=y44c >*/
	x44com_1.y44 = x44com_1.y44c;
/* SOURCE culvertd.for:2578 */
/*<        >*/
	xlktal_(&x44com_1.adrs44, &x44com_1.y44, &x44com_1.a44, &x44com_1.t44,
		 &x44com_1.dt44, &x44com_1.j44, &x44com_1.k44, &x44com_1.dk44,
		 &x44com_1.bet44, &x44com_1.dbet44, &x44com_1.alp44, &
		x44com_1.dalp44);
/*       Find the minimum specific energy at section 44, E44C */
/* SOURCE culvertd.for:2586 */
/*<       e44c=y44c+alp44*(q44/a44)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(x44com_1.q44) / x44com_1.a44;
	e44c = static_cast<double>(x44com_1.y44c) + static_cast<double>(static_cast<double>(x44com_1.alp44) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
		grvcom_1.grav2;
/*        WRITE(STDOUT,*) ' E44C=',E44C */
/*       Find the specific energy available at section 44, E44, that */
/*       is, the energy as transfered from section 4. */
/* SOURCE culvertd.for:2593 */
/*<       vh4=alp4*(q4/a4)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs4com_1.q4) / xs4com_1.a4;
	vh4 = static_cast<double>(static_cast<double>(xs4com_1.alp4) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertd.for:2594 */
/*<       ztel4=zb4+y4+vh4 >*/
	xs4com_1.ztel4 = static_cast<double>(static_cast<double>(xs4com_1.zb4) + xs4com_1.y4) + vh4;
/*        WRITE(STDOUT,*) ' ZTEL4=',ZTEL4,' VH4=',VH4,' ZB4=',ZB4 */
/* SOURCE culvertd.for:2598 */
/*<       e44=ztel4-zb44 >*/
	depmc_1.e44 = static_cast<double>(xs4com_1.ztel4) - x44com_1.zb44;
/*        WRITE(STDOUT,*) ' F4TO44: E44=',E44,' ZB44=',ZB44 */
/* SOURCE culvertd.for:2602 */
/*<       if(e44.lt.e44c)then >*/
	if (depmc_1.e44 < e44c) {
/*         No  solution exists. */
/* SOURCE culvertd.for:2604 */
/*<       nsflag=1 >*/
	    *nsflag = 1;
/* SOURCE culvertd.for:2605 */
/*<       y44=0.0 >*/
	    x44com_1.y44 = (float)0.;
/* SOURCE culvertd.for:2606 */
/*<       else >*/
	} else {
/*         A solution exists. */
/* SOURCE culvertd.for:2608 */
/*<       yl=y44c >*/
	    yl = x44com_1.y44c;
/* SOURCE culvertd.for:2609 */
/*<       fl=r4to44(yl) >*/
	    fl = r4to44_(&yl);
/* SOURCE culvertd.for:2610 */
/*<       if(abs(fl).le.epsabs)then >*/
	    if (dabs(fl) <= epscom_1.epsabs) {
/*           Take the solution to be at critical depth at section 44. */
/*           Values already exist in the common block for section 44. */
/* SOURCE culvertd.for:2613 */
/*<       else >*/
	    } else {
/*           A subcritical solution exists.  Try to find it.  Upper */
/*           bound for depth is the specific energy. */
/* SOURCE culvertd.for:2617 */
/*<       yr=e44 >*/
		yr = depmc_1.e44;
/* SOURCE culvertd.for:2618 */
/*<       fr=r4to44(yr) >*/
		fr = r4to44_(&yr);
/*            WRITE(STDOUT,*) ' Before call to REGFLT: YL=',YL, */
/*     A     ' FL=',FL,' YR=',YR,' FR=',FR */
/* SOURCE culvertd.for:2623 */
/*<       callregflt(epsarg,epsabs,r4to44,yl,yr,fl,fr,y44,flag) >*/
		regflt_(&epscom_1.epsarg, &epscom_1.epsabs, r4to44_, &
			yl, &yr, &fl, &fr, &x44com_1.y44, &feq_gen_flag_d_);
/* SOURCE culvertd.for:2628 */
/*<       z44=y44+zb44 >*/
		x44com_1.z44 = static_cast<double>(x44com_1.y44) + x44com_1.zb44;
/* SOURCE culvertd.for:2630 */
/*<       if(flag.eq.1)then >*/
		if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertd.for:2631 */
/*<       write(stdout,54) >*/
		    feq_gen_io_d__238.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__238);
		    e_wsfe();
/* SOURCE culvertd.for:2632 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2633 */
/*<       elseif(flag.eq.2)then >*/
		} else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertd.for:2634 */
/*<       write(stdout,60) >*/
		    feq_gen_io_d__239.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__239);
		    e_wsfe();
/* SOURCE culvertd.for:2635 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2636 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:2637 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2638 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2639 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:2641 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:2642 */
/*<       end >*/
} /* f4to44_ */




/* SOURCE culvertd.for:2646 */
/*<       subroutinedpm26(stdout,qrf,mrf,z3t,expflg) >*/
/* Subroutine */ int dpm26_(integer *stdout, real *qrf, real *mrf, real *z3t, 
	integer *expflg)
{
    /* Format strings */
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT RGF CLAIM\
S NONE IN\002,\002 DPM26.\002)";
    static char fmt_56[] = "(\002 *BUG:XXX* NO POSITIVE RESIDUAL FOR DPM26\
.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* RGF: MORE THAN 100 ITERATIONS IN\
 DPM26.\002)";
    static char fmt_64[] = "(/,\002 *WRN:536* No expansion of flow in depart\
ure reach.\002,\002  Free flow becomes type 7.\002)";
    static char fmt_68[] = "(\002 *BUG:XXX* No solution in F44TO4 in DPM26\
.\002)";
    static char fmt_70[] = "(\002 Negative residual impossible in DPM26. Try\
 increasing\002,\002 momentum flux over roadway.\002)";

    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real fh, fl, tp, yl, yt;
    extern /* Subroutine */ int rgf_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    integer feq_gen_flag_d_;
    extern /* Subroutine */ int lktj_(integer *, real *, real *);
    real ymax, ylow;
    extern /* Subroutine */ int f44to4_(integer *, integer *), f4to44_(
	    integer *, integer *);
    real yhigh;
    extern doublereal rdpm26_(real *);
    extern /* Subroutine */ int fndcde_(integer *, integer *, real *, real *);
    integer nsflag;
    extern doublereal fmxarg_(integer *);
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__244 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__245 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__246 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__248 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__252 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__255 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__256 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__257 = { 0, 0, 0, fmt_68, 0 };


/*     + + + PURPOSE + + + */
/*     Find the section 4 elevation given values at section 3 for */
/*     flow types 0, 1, 2, 5, and 6 using idealized momentum balance. */
/* SOURCE culvertd.for:2654 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:2657 */
/*<       integerexpflg,stdout >*/
/* SOURCE culvertd.for:2658 */
/*<       realmrf,qrf,z3t >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     QRF    - Flow over the roadway */
/*     MRF    - Momentum flux from flow over the road */
/*     Z3T    - Elevation of water surface at section 3 */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:2669 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertd.for:2670 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertd.for:2671 */
/* SOURCE x43com.cmn:2 */
/*<        >*/
/* SOURCE x43com.cmn:6 */
/*<       integeradrs43,stat43 >*/
/* SOURCE x43com.cmn:8 */
/*<        >*/
/* INCLUDE culvertd.for:2672 */
/* SOURCE x44com.cmn:2 */
/*<        >*/
/* SOURCE x44com.cmn:6 */
/*<       integeradrs44,stat44 >*/
/* SOURCE x44com.cmn:8 */
/*<        >*/
/* INCLUDE culvertd.for:2673 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertd.for:2674 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:2675 */
/*     Common block for various parameters to handle transitional */
/*     flow type behavior for the departure reach computations. */
/* SOURCE typtrn.cmn:4 */
/*<       common/typtrn/avhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/* SOURCE typtrn.cmn:6 */
/*<       realavhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/*     AVHF- area used for velocity head in computing losses for the */
/*           transitional free flow */
/*     CDF- coef. of discharge for computing losses for the transitional */
/*          free flow. */
/*     BETAF- value of beta to compensate for false area in the computation */
/*            of the momentum flux from some free flows.  If this */
/*            value is zero it means that the beta from the cross section */
/*            function table should be used.  If it is non-zero it means */
/*            that the free flow type was used as a transition and that */
/*            the flow area of the culvert barrel outlet was falsified in */
/*            the process. */
/*     ALPHAF- value of alpha to use in computing velocity head for */
/*             energy loss computations. */
/*     Y3PF- depth to the piezometric level at the culvert barrel outlet */
/*           for free flow limit. */
/*     BETA3- actual value at section 3 used in departure reach */
/*     ALPHA3- actual value at section 3.  Crudely estimated in some */
/*             cases because better alternative is not available. */
/* INCLUDE culvertd.for:2676 */
/*     Common for function DPM26C in FEQUTL */
/* SOURCE dpm26c.cmn:3 */
/*<       common/dpm26c/outun,rmflux,m43 >*/
/* SOURCE dpm26c.cmn:4 */
/*<       integeroutun >*/
/* SOURCE dpm26c.cmn:5 */
/*<       realrmflux,m43 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:2679 */
/*<       integerflag,nsflag >*/
/* SOURCE culvertd.for:2680 */
/*<       realfh,fl,tp,yhigh,yl,ylow,ymax,yt >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:2683 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:2686 */
/*<       realfmxarg,rdpm26 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:2689 */
/*<       externalf44to4,f4to44,fmxarg,fndcde,lktj,rdpm26,rgf,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:2693 */
/*<    54  >*/
/* SOURCE culvertd.for:2695 */
/*<    56 format(' *BUG:XXX* NO POSITIVE RESIDUAL FOR DPM26.') >*/
/* SOURCE culvertd.for:2696 */
/*<    60 format(' *BUG:XXX* RGF: MORE THAN 100 ITERATIONS IN DPM26.') >*/
/* SOURCE culvertd.for:2697 */
/*<    64  >*/
/* SOURCE culvertd.for:2699 */
/*<    68 format(' *BUG:XXX* No solution in F44TO4 in DPM26.') >*/
/* SOURCE culvertd.for:2700 */
/*<    70  >*/
/* *********************************************************************** */
/*     SET EXPANSION FLAG TO TRUE */
/* SOURCE culvertd.for:2705 */
/*<       expflg=1 >*/
/* L54: */
/* L56: */
/* L60: */
/* L64: */
/* L68: */
/* L70: */
    *expflg = 1;
/*     SET VALUES IN SPECIAL COMMON */
/* SOURCE culvertd.for:2708 */
/*<       outun=stdout >*/
    dpm26c_1.outun = *stdout;
/* SOURCE culvertd.for:2709 */
/*<       rmflux=mrf >*/
    dpm26c_1.rmflux = *mrf;
/*     FIND VALUES IN DEPARTURE REACH AT UPSTREAM END AT THE CRITICAL */
/*     ELEVATION SUPPLIED BY Z3T. */
/* SOURCE culvertd.for:2714 */
/*<       z43=z3t >*/
    x43com_1.z43 = *z3t;
/* SOURCE culvertd.for:2715 */
/*<       y43=z3t-zb43 >*/
    x43com_1.y43 = static_cast<double>(*z3t) - x43com_1.zb43;
/* SOURCE culvertd.for:2717 */
/*<        >*/
    xlktal_(&x43com_1.adrs43, &x43com_1.y43, &x43com_1.a43, &x43com_1.t43, &
	    x43com_1.dt43, &x43com_1.j43, &x43com_1.k43, &x43com_1.dk43, &
	    x43com_1.bet43, &x43com_1.dbet43, &x43com_1.alp43, &
	    x43com_1.dalp43);
/*     Find the first moment of area in the barrel at the */
/*     water level at section 43.  This is often the same as */
/*     the level at section 3 but not for type 5 flow. */
/* SOURCE culvertd.for:2727 */
/*<       tp=z43-zb3 >*/
    tp = static_cast<double>(x43com_1.z43) - xs3com_1.zb3;
/* SOURCE culvertd.for:2728 */
/*<       calllktj(adrxs3,tp,j3z43) >*/
    lktj_(&xs3com_1.adrxs3, &tp, &xs3com_1.j3z43);
/*      WRITE(STDOUT,*) ' DPM26: J3Z43=',J3Z43,' J3=',J3,' J43=',J43 */
/*      WRITE(STDOUT,*) ' Y3=',Y3,' A3=',A3,' Q3=',Q3,' RMFLUX=', */
/*     A                 RMFLUX */
/*      WRITE(STDOUT,*) ' Z43 - ZB3=',Z43 - ZB3 */
/*     Compute the momentum flux + impulse function for section */
/*     43.  Flux always comes from conditions in the barrel and from */
/*     the flow over the roadway(if there is any).  If the piezometric */
/*     levels at section 43 and section 3 are the same, then J3 and */
/*     J3Z43 have the same value. */
/*     There are cases in which the exit area has been falsified in */
/*     order to compute a transition between free flow types. */
/*     If this has been done, then BETAF in TYPTRN.COM will be */
/*     > 0.0. */
/* SOURCE culvertd.for:2746 */
/*<       if(betaf.gt.0.0)then >*/
    if (typtrn_1.betaf > (float)0.) {
/* SOURCE culvertd.for:2747 */
/*<       beta3=betaf >*/
	typtrn_1.beta3 = typtrn_1.betaf;
/* SOURCE culvertd.for:2748 */
/*<       alpha3=alphaf >*/
	typtrn_1.alpha3 = typtrn_1.alphaf;
/* SOURCE culvertd.for:2749 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:2750 */
/*<       beta3=bet3 >*/
	typtrn_1.beta3 = xs3com_1.bet3;
/* SOURCE culvertd.for:2751 */
/*<       alpha3=alp3 >*/
	typtrn_1.alpha3 = xs3com_1.alp3;
/* SOURCE culvertd.for:2752 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:2753 */
/*<       m43=grav*(j43+j3-j3z43)+beta3*q3**2/a3+rmflux >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = xs3com_1.q3;
    dpm26c_1.m43 = static_cast<double>(static_cast<double>(static_cast<double>(grvcom_1.grav) * (static_cast<double>(static_cast<double>(x43com_1.j43) + xs3com_1.j3) - 
	    xs3com_1.j3z43)) + static_cast<double>(static_cast<double>(typtrn_1.beta3) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / xs3com_1.a3) + 
	    dpm26c_1.rmflux;
/*     Remember key values in order to solve for type 7 if that becomes */
/*     necessary. */
/* SOURCE culvertd.for:2757 */
/*<       z43old=z43 >*/
    x43com_1.z43old = x43com_1.z43;
/* SOURCE culvertd.for:2758 */
/*<       q43old=q3 >*/
    x43com_1.q43old = xs3com_1.q3;
/*     COMPUTE THE FLOW AT SECTION 44 */
/* SOURCE culvertd.for:2761 */
/*<       q44=q3+qrf >*/
    x44com_1.q44 = static_cast<double>(xs3com_1.q3) + *qrf;
/* SOURCE culvertd.for:2762 */
/*<       q4=q44 >*/
    xs4com_1.q4 = x44com_1.q44;
/*     WILL CRITICAL DEPTH IN SECTION 4 DROWN THE CONTROL AT SECTION 3? */
/*     FIND CRITICAL DEPTH IN SECTION 4 - GIVE ESTIMATED DEPTH TO */
/*     START PROCESS */
/* SOURCE culvertd.for:2768 */
/*<       y4c=z3t-zb4 >*/
    xs4com_1.y4c = static_cast<double>(*z3t) - xs4com_1.zb4;
/* SOURCE culvertd.for:2769 */
/*<       if(y4c.lt.0.0)then >*/
    if (xs4com_1.y4c < (float)0.) {
/* SOURCE culvertd.for:2770 */
/*<       y4c=0.1 >*/
	xs4com_1.y4c = (float).1;
/* SOURCE culvertd.for:2771 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:2773 */
/*<       callfndcde(stdout,adrxs4,q4,y4c) >*/
    fndcde_(stdout, &xs4com_1.adrxs4, &xs4com_1.q4, &xs4com_1.y4c);
/* SOURCE culvertd.for:2777 */
/*<       z4=zb4+y4c >*/
    xs4com_1.z4 = static_cast<double>(xs4com_1.zb4) + xs4com_1.y4c;
/*      WRITE(STDOUT,*) ' CRIT DEPTH AT 4 IN DPM26=',Y4C,' AT FLOW=',Q4 */
/*     Now compute the values at section 44 given that section 4 is */
/*     critical.  Need to lookup values at section 4 because not all of */
/*     them are defined by FNDCDE. */
/* SOURCE culvertd.for:2785 */
/*<       y4=y4c >*/
    xs4com_1.y4 = xs4com_1.y4c;
/* SOURCE culvertd.for:2786 */
/*<       callxlktal(adrxs4,y4c,a4,t4,dt4,j4,k4,dk4,bet4,dbet4,alp4,dalp4) >*/
    xlktal_(&xs4com_1.adrxs4, &xs4com_1.y4c, &xs4com_1.a4, &xs4com_1.t4, &
	    xs4com_1.dt4, &xs4com_1.j4, &xs4com_1.k4, &xs4com_1.dk4, &
	    xs4com_1.bet4, &xs4com_1.dbet4, &xs4com_1.alp4, &xs4com_1.dalp4);
/*      WRITE(STDOUT,*) ' Y4=',Y4,' ZB4=',ZB4,' ALP4=',ALP4, */
/*     A                 ' A4=',A4 */
/* SOURCE culvertd.for:2793 */
/*<       callf4to44(stdout,nsflag) >*/
    f4to44_(stdout, &nsflag);
/* SOURCE culvertd.for:2797 */
/*<       if(nsflag.eq.1)then >*/
    if (nsflag == 1) {
/*       No solution at section 44.  Therefore, critical depth */
/*       at section 4 will not drown the flow at the exit of the */
/*       culvert.  Search for a negative residual for a depth at */
/*       section 44.  F4TO44 has computed critical depth at section 44. */
/*       Try for negative residual at that depth. */
/* SOURCE culvertd.for:2804 */
/*<       y44=y44c >*/
	x44com_1.y44 = x44com_1.y44c;
/* SOURCE culvertd.for:2805 */
/*<       yl=y44 >*/
	yl = x44com_1.y44;
/* SOURCE culvertd.for:2806 */
/*<       fl=rdpm26(yl) >*/
	fl = rdpm26_(&yl);
/* SOURCE culvertd.for:2807 */
/*<       if(fl.gt.0.0)then >*/
	if (fl > (float)0.) {
/* SOURCE culvertd.for:2808 */
/*<       write(stdout,70) >*/
	    feq_gen_io_d__244.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__244);
	    e_wsfe();
/* SOURCE culvertd.for:2809 */
/*<       write(stdout,*)' No solution in F4TO44 in DPM26:' >*/
	    feq_gen_io_d__245.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__245);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" No solution in F4TO44 in DPM26:"), (ftnlen)
		    32);
	    e_wsle();
/* SOURCE culvertd.for:2810 */
/*<       write(stdout,*)' YL=',yl,' FL=',fl >*/
	    feq_gen_io_d__246.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__246);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YL="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FL="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&fl, (ftnlen)sizeof(real));
	    e_wsle();
/* SOURCE culvertd.for:2811 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2812 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2813 */
/*<       else >*/
    } else {
/*       Solution at section 44.  Now see if the flow at culvert */
/*       exit(section 3) is drowned. */
/* SOURCE culvertd.for:2817 */
/*<       fl=rdpm26(y44) >*/
	fl = rdpm26_(&x44com_1.y44);
/* SOURCE culvertd.for:2818 */
/*<       ylow=y44 >*/
	ylow = x44com_1.y44;
/* SOURCE culvertd.for:2819 */
/*<       if(fl.gt.0.0)then >*/
	if (fl > (float)0.) {
/*         CRITICAL DEPTH AT THE END OF THE DEPARTURE REACH WOULD */
/*         DROWN THE CONTROL.  WE ASSUME THAT THERE IS THEREFORE */
/*         NO EXPANSION OF THE FLOW FROM THE CULVERT TO THE DEPARTURE */
/*         REACH. */
/* SOURCE culvertd.for:2825 */
/*<       write(stdout,64) >*/
	    feq_gen_io_d__248.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__248);
	    e_wsfe();
/* SOURCE culvertd.for:2826 */
/*<       expflg=0 >*/
	    *expflg = 0;
/*          WRITE(STDOUT,*) ' Solution in F4TO44 in DPM26: Y44=',Y44 */
/*          WRITE(STDOUT,*) ' FL at Y44=',FL */
/* SOURCE culvertd.for:2829 */
/*<       return >*/
	    return 0;
/* SOURCE culvertd.for:2830 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2831 */
/*<       endif >*/
    }
/*     CRITICAL DEPTH WILL NOT DROWN THE CONTROL BUT SOME HIGHER ELEVATION */
/*     WILL. */
/*     SEARCH FOR SIGN CHANGE IN THE RESIDUAL FUNCTION */
/*     ALREADY IS <= 0.0 AT Y44 */
/* SOURCE culvertd.for:2840 */
/*<       ymax=fmxarg(adrs44) >*/
    ymax = fmxarg_(&x44com_1.adrs44);
/*     With expansion in the departure reach the water surface elevation */
/*     at section 44 should be at least as high as at section 43. */
/* SOURCE culvertd.for:2845 */
/*<       yhigh=1.1*y44 >*/
    yhigh = static_cast<double>(x44com_1.y44) * (float)1.1;
/* SOURCE culvertd.for:2846 */
/*<       if(yhigh+zb44.lt.z43)then >*/
    if (static_cast<double>(yhigh) + x44com_1.zb44 < x43com_1.z43) {
/* SOURCE culvertd.for:2847 */
/*<       yhigh=z43-zb44 >*/
	yhigh = static_cast<double>(x43com_1.z43) - x44com_1.zb44;
/* SOURCE culvertd.for:2848 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:2849 */
/*<   110 continue >*/
L110:
/* SOURCE culvertd.for:2850 */
/*<       fh=rdpm26(yhigh) >*/
    fh = rdpm26_(&yhigh);
/* SOURCE culvertd.for:2851 */
/*<       if(fh.lt.0.0)then >*/
    if (fh < (float)0.) {
/* SOURCE culvertd.for:2852 */
/*<       fl=fh >*/
	fl = fh;
/* SOURCE culvertd.for:2853 */
/*<       ylow=yhigh >*/
	ylow = yhigh;
/* SOURCE culvertd.for:2854 */
/*<       yhigh=1.2*yhigh >*/
	yhigh *= static_cast<double>((float)1.2);
/* SOURCE culvertd.for:2855 */
/*<       if(yhigh.gt.ymax)then >*/
	if (yhigh > ymax) {
/* SOURCE culvertd.for:2856 */
/*<       yhigh=.5*(ylow+ymax) >*/
	    yhigh = static_cast<double>((static_cast<double>(ylow) + ymax)) * (float).5;
/* SOURCE culvertd.for:2857 */
/*<       if(abs(yhigh-ymax).lt.epsabs)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(yhigh) - ymax, dabs(feq_gen_r_d_1)) < epscom_1.epsabs) {
/* SOURCE culvertd.for:2858 */
/*<       write(stdout,56) >*/
		feq_gen_io_d__252.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__252);
		e_wsfe();
/* SOURCE culvertd.for:2859 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2860 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:2861 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:2862 */
/*<       goto110 >*/
	goto L110;
/* SOURCE culvertd.for:2863 */
/*<       endif >*/
    }
/*     WE HAVE A SIGN CHANGE HERE */
/*      XMIN = YLOW */
/*      XMAX = YHIGH */
/*      CALL SPSCNT(YLOW, YHIGH, EPSARG, EPSF, 100, FLAG, XMIN, */
/*     A                  XMAX, DPM26) */
/*      YT = YHIGH */
/* SOURCE culvertd.for:2872 */
/*<       callrgf(epsarg,epsf,rdpm26,ylow,yhigh,fl,fh,yt,flag) >*/
    rgf_(&epscom_1.epsarg, &epscom_1.epsf, rdpm26_, &ylow, &yhigh, &fl, 
	    &fh, &yt, &feq_gen_flag_d_);
/* SOURCE culvertd.for:2877 */
/*<       y44=yt >*/
    x44com_1.y44 = yt;
/* SOURCE culvertd.for:2878 */
/*<       z44=y44+zb44 >*/
    x44com_1.z44 = static_cast<double>(x44com_1.y44) + x44com_1.zb44;
/*      WRITE(STDOUT,*) ' Solution for Y44 at free flow limit in DPM26:', */
/*     A               ' Y44=',Y44,' A44=',A44 */
/* SOURCE culvertd.for:2882 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertd.for:2883 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__255.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__255);
	e_wsfe();
/* SOURCE culvertd.for:2884 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2885 */
/*<       elseif(flag.eq.2)then >*/
    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertd.for:2886 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__256.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__256);
	e_wsfe();
/* SOURCE culvertd.for:2887 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2888 */
/*<       endif >*/
    }
/*     Now find the values in section 4 given the values in section 44 */
/* SOURCE culvertd.for:2892 */
/*<       callf44to4(stdout,nsflag) >*/
    f44to4_(stdout, &nsflag);
/* SOURCE culvertd.for:2895 */
/*<       if(nsflag.eq.1)then >*/
    if (nsflag == 1) {
/* SOURCE culvertd.for:2896 */
/*<       write(stdout,68) >*/
	feq_gen_io_d__257.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__257);
	e_wsfe();
/* SOURCE culvertd.for:2897 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:2898 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' DPM26: Solution at 4: Y4=',Y4,' Z4=',Z4 */
/* SOURCE culvertd.for:2901 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:2902 */
/*<       end >*/
} /* dpm26_ */




/* SOURCE culvertd.for:2906 */
/*<        >*/
/* Subroutine */ int locjmp_(integer *stdout, integer *iu, integer *id, real *
	yup, real *ydn, real *q, real *dup, real *ty6lss, real *yhigh, 
	integer *jmploc, real *yend, integer *ierr, char *protyp, ftnlen 
	protyp_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX* Invalid case=\002,i5,\002 in sub\
routine LOCJMP.\002)";
    static char fmt_56[] = "(/,\002 *WRN:593* The super critical profile for\
 Type 5 flow\002,\002 is too short.\002,/,\002 This suggests that the\002\
,\002 expansion loss applied after the vena contracta\002,/,\002 is\002,\002\
 too large.  The loss will be reduced one or more times to\002,\002 find\002\
,/,\002 a longer super critical profile.  The value of KD\002,\002, the\002,\
/,\002 expansion loss in the barrel may be too large.\002,\002  Values > 0.4\
 should be avoided.\002)";
    static char fmt_57[] = "(/,\002 Initial expansion loss=\002,f8.3)";
    static char fmt_58[] = "(/,\002 *WRN:594* No super critical profile of a\
dequate \002,\002length exists.\002,/,\002 Culvert barrel may be non-prismat\
ic or have significant\002,/,\002 changes in slope.\002)";
    static char fmt_59[] = "(/,\002 Final expansion loss=\002,f8.3)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();

    /* Local variables */
    integer feq_gen_i_d_;
    real p;
    integer ic;
    real dh, at, jt, kt, tt, yt;
    integer isb;
    real dkt, qct;
    integer isp;
    real dtt;
    integer icsb, icsp, isub;
    real alpt, bett;
    extern /* Subroutine */ int lktj_(integer *, real *, real *);
    integer isup;
    real ysub;
    integer ijump;
    real dalpt, dbett, msubl, msubr, sbzdn, spzdn, msupl, ysubl, sbzup, ysubr;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real msupr, ysupl, spzup, ysupr;
    integer sbflag, spflag;
    extern /* Subroutine */ int sfpsbe_(integer *, integer *, integer *, real 
	    *, real *, real *, integer *, real *, integer *), dislss_(integer 
	    *, integer *, integer *, integer *, real *, real *, real *, real *
	    ), sfpspe_(integer *, integer *, integer *, real *, real *, 
	    integer *, real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__270 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__271 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__272 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__273 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__274 = { 0, 0, 0, fmt_59, 0 };
    static cilist feq_gen_io_d__275 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__302 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Locate a jump, if one exists, in the culvert barrel for the */
/*     given flow and initial depths at the starting node and ending */
/*     node.  Return details about the jump, the exit depth of the */
/*     culvert, and so forth.  JMPLOC= 0 if jump does not exist */
/*     and index of the node downstream of its location otherwise. */
/*     YHIGH gives the estimated depth on the high side of the jump */
/*     and is 0.0 otherwise.  YEND gives the end depth at the culvert */
/*     exit in all cases for which an end depth exists. IERR is 0 */
/*     if the returned values have meaning and > 0 otherwise. */
/* SOURCE culvertd.for:2922 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:2925 */
/*<       integerid,ierr,iu,jmploc,stdout >*/
/* SOURCE culvertd.for:2926 */
/*<       realdup,q,ty6lss,ydn,yend,yhigh,yup >*/
/* SOURCE culvertd.for:2927 */
/*<       characterprotyp*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     YUP    - depth at vena contracta */
/*     YDN    - depth at exit of culvert for defining subcritical profile */
/*     Q      - Flowrate */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     TY6LSS - estimated type 6 loss */
/*     YHIGH  - depth on high side of hydraulic jump */
/*     JMPLOC - index to node below the jump */
/*     YEND   - depth found to exist at the exit of the culvert */
/*     IERR   - error flag */
/*     PROTYP - descripter for the nature of the profile */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:2945 */
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
/* INCLUDE culvertd.for:2946 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertd.for:2947 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:2950 */
/*<       integeri,ic,icsb,icsp,ijump,isb,isp,isub,isup,sbflag,spflag >*/
/* SOURCE culvertd.for:2952 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:2957 */
/*<       intrinsicmin >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:2960 */
/*<       externaldislss,lktj,sfpsbe,sfpspe,xlkt22 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:2963 */
/*<    50 format(' *BUG:XXX* Invalid case=',i5,' in subroutine LOCJMP.') >*/
/* SOURCE culvertd.for:2964 */
/*<    56  >*/
/* SOURCE culvertd.for:2971 */
/*<    57 format(/,' Initial expansion loss=',f8.3) >*/
/* SOURCE culvertd.for:2972 */
/*<    58  >*/
/* SOURCE culvertd.for:2976 */
/*<    59 format(/,' Final expansion loss=',f8.3) >*/
/* *********************************************************************** */
/*     Approach:  Attempt to compute a supercritical profile from the */
/*     starting node with the given depth.  Then attempt to compute */
/*     a subcritical profile from the ending node with the given depth. */
/*     The attempt to compute each profile has three */
/*     outcomes:  1. The profile could not be started, that is , not */
/*     even one distance step was possible.  This is failure. */
/*     2. A partial profile was computed.  3. A complete profile was */
/*     computed.  Thus there are nine outcomes possible. */
/*      Super     Sub-     #          Significance */
/*      critical  critical */
/*      profile   profile */
/*      -------   -------   --------------------------------------------- */
/*      fail      fail     1 Should not happen.  May indicate a strange */
/*                           culvert barrel slope variation.  Reduce the */
/*                           estimated loss, TY6LSS, and try the */
/*                           supercritical profile until the loss is */
/*                           essentially zero. */
/*      fail      partial  2 Should not happen.  May indicate a strange */
/*                           culvert barrel slope variation.  Reduce the */
/*                           estimated loss, TY6LSS, and try the */
/*                           supercritical profile until the loss is */
/*                           essentially zero. */
/*      fail      complete 3 Jump impossible. Profile is subcritical. */

/*      partial   fail     4 Should not happen.  May indicate a strange */
/*                           culvert barrel slope variation.  Reduce the */
/*                           estimated loss, TY6LSS, and try the */
/*                           supercritical profile until the loss is */
/*                           essentially zero. */
/*      partial  partial   5 Two outcomes:  no overlap- should not */
/*                           happen;  overlap-locate jump and estimate */
/*                           high-side depth. */
/*      partial  complete  6 Locate jump and estimate high-side depth. */
/*                           If no jump possible profile is subcritical. */
/*      complete fail      7 No jump possible and profile is supercritical */

/*     complete partial    8 Locate jump and estimate high-side depth. */
/*                           If no jump possible then profile is */
/*                           supercritical. */
/*     complete complete   9 Locate jump and estimate high-side depth. */
/*                           If no jump possible then something is */
/*                           probably wrong! */
/*     Attempt to compute super-critical profile to the end of */
/*     the barrel. */
/* SOURCE culvertd.for:3026 */
/*<       spzup=yup+zbvec(iu) >*/
/* L50: */
/* L56: */
/* L57: */
/* L58: */
/* L59: */
    spzup = static_cast<double>(*yup) + culcom_1.zbvec[*iu - 1];
/*     Distribute losses for computing the supercritical profile. */
/* SOURCE culvertd.for:3029 */
/*<       calldislss(iu,id,iat3d,iat6d,dup,ty6lss,xvec,sevec) >*/
    dislss_(iu, id, &culcom_1.iat3d, &culcom_1.iat6d, dup, ty6lss, 
	    culcom_1.xvec, culcom_1.sevec);
/* SOURCE culvertd.for:3033 */
/*<       callsfpspe(stdout,iu,id,q,spzup,isp,spzdn,spflag) >*/
    sfpspe_(stdout, iu, id, q, &spzup, &isp, &spzdn, &spflag);
/* SOURCE culvertd.for:3036 */
/*<       if(spflag.eq.1)then >*/
    if (spflag == 1) {
/* SOURCE culvertd.for:3037 */
/*<       icsp=2 >*/
	icsp = 2;
/* SOURCE culvertd.for:3038 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:3039 */
/*<       if(isp.gt.iu)then >*/
	if (isp > *iu) {
/* SOURCE culvertd.for:3040 */
/*<       icsp=1 >*/
	    icsp = 1;
/* SOURCE culvertd.for:3041 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:3042 */
/*<       icsp=0 >*/
	    icsp = 0;
/* SOURCE culvertd.for:3043 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:3044 */
/*<       endif >*/
    }
/*     Attempt to compute a subcritical profile. */
/* SOURCE culvertd.for:3047 */
/*<       dh=0.0 >*/
    dh = (float)0.;
/* SOURCE culvertd.for:3048 */
/*<       sbzdn=ydn+zbvec(id) >*/
    sbzdn = static_cast<double>(*ydn) + culcom_1.zbvec[*id - 1];
/* SOURCE culvertd.for:3049 */
/*<       callsfpsbe(stdout,iu,id,dh,q,sbzdn,isb,sbzup,sbflag) >*/
    sfpsbe_(stdout, iu, id, &dh, q, &sbzdn, &isb, &sbzup, &sbflag);
/*      WRITE(STDOUT,*) ' LOCJMP: SBFLAG=',SBFLAG */
/* SOURCE culvertd.for:3053 */
/*<       if(sbflag.eq.1)then >*/
    if (sbflag == 1) {
/* SOURCE culvertd.for:3054 */
/*<       icsb=2 >*/
	icsb = 2;
/* SOURCE culvertd.for:3055 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:3056 */
/*<       if(isb.lt.id)then >*/
	if (isb < *id) {
/* SOURCE culvertd.for:3057 */
/*<       icsb=1 >*/
	    icsb = 1;
/* SOURCE culvertd.for:3058 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:3059 */
/*<       icsb=0 >*/
	    icsb = 0;
/* SOURCE culvertd.for:3060 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:3061 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3063 */
/*<       ic=icsb+3*icsp+1 >*/
    ic = icsb + icsp * 3 + 1;
/*      WRITE(STDOUT,*) ' LOCJMP: ICSB=',ICSB,' ICSP=',ICSP,' IC=',IC */
/* SOURCE culvertd.for:3065 */
/*<       goto(100,100,300,100,500,600,700,800,900),ic >*/
    switch (ic) {
	case 1:  goto L100;
	case 2:  goto L100;
	case 3:  goto L300;
	case 4:  goto L100;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
    }
/* SOURCE culvertd.for:3067 */
/*<       write(stdout,50)ic >*/
    feq_gen_io_d__270.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__270);
    do_fio(&feq_gen_c_d_1, (char *)&ic, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE culvertd.for:3068 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:3070 */
/*<   100 continue >*/
L100:
/*         Error condition- can indicate a bug in the software or */
/*         a condition in the culvert that cannot be computed. */
/* SOURCE culvertd.for:3073 */
/*<       write(stdout,56) >*/
    feq_gen_io_d__271.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__271);
    e_wsfe();
/*         The indications are that the super critical profile should */
/*         have completed because the subcritical profile was either */
/*         a failure or incomplete.  The loss, TY6LSS, can only be */
/*         a rough approximation to the actual loss.  If the culvert */
/*         barrel is steep, the usual cause of failure for the */
/*         subcritical profile, then the supercritical profile should */
/*         be able to complete.  Thus reduce the loss by stages until */
/*         the supercritical profile is complete or the loss is */
/*         reduced to essentially zero. */
/* SOURCE culvertd.for:3084 */
/*<       write(stdout,57)ty6lss >*/
    feq_gen_io_d__272.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__272);
    do_fio(&feq_gen_c_d_1, (char *)&(*ty6lss), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culvertd.for:3085 */
/*<   110 continue >*/
L110:
/* SOURCE culvertd.for:3086 */
/*<       ty6lss=0.95*ty6lss >*/
    *ty6lss *= static_cast<double>((float).95);
/* SOURCE culvertd.for:3087 */
/*<       calldislss(iu,id,iat3d,iat6d,dup,ty6lss,xvec,sevec) >*/
    dislss_(iu, id, &culcom_1.iat3d, &culcom_1.iat6d, dup, ty6lss, 
	    culcom_1.xvec, culcom_1.sevec);
/* SOURCE culvertd.for:3090 */
/*<       callsfpspe(stdout,iu,id,q,spzup,isp,spzdn,spflag) >*/
    sfpspe_(stdout, iu, id, q, &spzup, &isp, &spzdn, &spflag);
/*            WRITE(STDOUT,*) ' TY6LSS=',TY6LSS,' ISP=',ISP,' ID=',ID */
/* SOURCE culvertd.for:3094 */
/*<       if(spflag.eq.1)then >*/
    if (spflag == 1) {
/*             The supercritical profile is complete. */
/* SOURCE culvertd.for:3096 */
/*<       icsp=2 >*/
	icsp = 2;
/* SOURCE culvertd.for:3097 */
/*<       elseif(isp.gt.isb)then >*/
    } else if (isp > isb) {
/*             The profiles overlap. */
/* SOURCE culvertd.for:3099 */
/*<       icsp=1 >*/
	icsp = 1;
/* SOURCE culvertd.for:3100 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:3101 */
/*<       if(ty6lss/yup.lt.0.001)then >*/
	if (static_cast<double>(*ty6lss) / *yup < (float).001) {
/*               Process has failed.  Super critical profile and */
/*               perhaps subcritical profile have major problems. */
/* SOURCE culvertd.for:3104 */
/*<       write(stdout,58) >*/
	    feq_gen_io_d__273.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__273);
	    e_wsfe();
/* SOURCE culvertd.for:3105 */
/*<       ierr=1 >*/
	    *ierr = 1;
/* SOURCE culvertd.for:3106 */
/*<       jmploc=0 >*/
	    *jmploc = 0;
/* SOURCE culvertd.for:3107 */
/*<       yhigh=0.0 >*/
	    *yhigh = (float)0.;
/* SOURCE culvertd.for:3108 */
/*<       yend=0.0 >*/
	    *yend = (float)0.;
/* SOURCE culvertd.for:3109 */
/*<       protyp=' ' >*/
	    s_copy(protyp, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE culvertd.for:3110 */
/*<       goto9000 >*/
	    goto L9000;
/* SOURCE culvertd.for:3111 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:3112 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE culvertd.for:3113 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:3114 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3115 */
/*<       ic=icsb+3*icsp+1 >*/
    ic = icsb + icsp * 3 + 1;
/*            WRITE(STDOUT,*) ' LOCJMP: ICSB=',ICSB,' ICSP=',ICSP, */
/*     A                        ' IC=',IC */
/* SOURCE culvertd.for:3118 */
/*<       write(stdout,59)ty6lss >*/
    feq_gen_io_d__274.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__274);
    do_fio(&feq_gen_c_d_1, (char *)&(*ty6lss), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culvertd.for:3119 */
/*<       goto(100,100,300,100,500,600,700,800,900),ic >*/
    switch (ic) {
	case 1:  goto L100;
	case 2:  goto L100;
	case 3:  goto L300;
	case 4:  goto L100;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
    }
/* SOURCE culvertd.for:3121 */
/*<       write(stdout,50)ic >*/
    feq_gen_io_d__275.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__275);
    do_fio(&feq_gen_c_d_1, (char *)&ic, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE culvertd.for:3122 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:3124 */
/*<   300 continue >*/
L300:
/*         Supercritical profile fails but subcritical is complete. */
/*          WRITE(STDOUT,*) ' LOCJMP: Found option 3' */
/* SOURCE culvertd.for:3127 */
/*<       ierr=0 >*/
    *ierr = 0;
/* SOURCE culvertd.for:3128 */
/*<       jmploc=0 >*/
    *jmploc = 0;
/* SOURCE culvertd.for:3129 */
/*<       yhigh=0.0 >*/
    *yhigh = (float)0.;
/* SOURCE culvertd.for:3130 */
/*<       yend=ydn >*/
    *yend = *ydn;
/* SOURCE culvertd.for:3131 */
/*<       protyp='SUB' >*/
    s_copy(protyp, const_cast<char*>("SUB"), (ftnlen)8, (ftnlen)3);
/* SOURCE culvertd.for:3132 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE culvertd.for:3134 */
/*<   500 continue >*/
L500:
/*         Possible mixed profile. */
/*          WRITE(STDOUT,*) ' LOCJMP: Found option 5' */
/* SOURCE culvertd.for:3137 */
/*<       if(isp.le.isb)then >*/
    if (isp <= isb) {
/*           No overlap.  Unable to connect the two profiles. */
/*           Possible bug or error. */
/* SOURCE culvertd.for:3140 */
/*<       ierr=1 >*/
	*ierr = 1;
/* SOURCE culvertd.for:3141 */
/*<       jmploc=0 >*/
	*jmploc = 0;
/* SOURCE culvertd.for:3142 */
/*<       yhigh=0.0 >*/
	*yhigh = (float)0.;
/* SOURCE culvertd.for:3143 */
/*<       yend=0.0 >*/
	*yend = (float)0.;
/* SOURCE culvertd.for:3144 */
/*<       protyp=' ' >*/
	s_copy(protyp, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE culvertd.for:3145 */
/*<       goto9000 >*/
	goto L9000;
/* SOURCE culvertd.for:3146 */
/*<       else >*/
    } else {
/*           Overlap. Find the jump location and high-side value */
/* SOURCE culvertd.for:3148 */
/*<       protyp='MIXED' >*/
	s_copy(protyp, const_cast<char*>("MIXED"), (ftnlen)8, (ftnlen)5);
/* SOURCE culvertd.for:3149 */
/*<       goto2000 >*/
	goto L2000;
/* SOURCE culvertd.for:3150 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3152 */
/*<   600 continue >*/
L600:
/*         Super critical profile partial and sub-critical complete. */
/*         Set the profile type to correct value if a jump */
/*         fails to exist.  Then find the  jump location and high-side */
/*         value. */
/*          WRITE(STDOUT,*) ' LOCJMP: Found option 6' */
/* SOURCE culvertd.for:3158 */
/*<       protyp='SUB' >*/
    s_copy(protyp, const_cast<char*>("SUB"), (ftnlen)8, (ftnlen)3);
/* SOURCE culvertd.for:3159 */
/*<       yend=ydn >*/
    *yend = *ydn;
/* SOURCE culvertd.for:3160 */
/*<       jmploc=0 >*/
    *jmploc = 0;
/* SOURCE culvertd.for:3161 */
/*<       yhigh=0.0 >*/
    *yhigh = (float)0.;
/* SOURCE culvertd.for:3162 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE culvertd.for:3164 */
/*<   700 continue >*/
L700:
/*         Subcritical profile fails but supercritical is complete. */
/*          WRITE(STDOUT,*) ' LOCJMP: Found option 7' */
/* SOURCE culvertd.for:3167 */
/*<       ierr=0 >*/
    *ierr = 0;
/* SOURCE culvertd.for:3168 */
/*<       jmploc=0 >*/
    *jmploc = 0;
/* SOURCE culvertd.for:3169 */
/*<       yhigh=0.0 >*/
    *yhigh = (float)0.;
/* SOURCE culvertd.for:3170 */
/*<       yend=spzdn-zbvec(id) >*/
    *yend = static_cast<double>(spzdn) - culcom_1.zbvec[*id - 1];
/* SOURCE culvertd.for:3171 */
/*<       protyp='SUP' >*/
    s_copy(protyp, const_cast<char*>("SUP"), (ftnlen)8, (ftnlen)3);
/* SOURCE culvertd.for:3172 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE culvertd.for:3174 */
/*<   800 continue >*/
L800:
/*         Supercritical profile complete but subcritical partial. */
/*         Set the profile type to correct value if a jump fails to */
/*         exist.  Then find the jump location and high-side value. */
/*          WRITE(STDOUT,*) ' LOCJMP: Found option 8' */
/* SOURCE culvertd.for:3179 */
/*<       protyp='SUP' >*/
    s_copy(protyp, const_cast<char*>("SUP"), (ftnlen)8, (ftnlen)3);
/* SOURCE culvertd.for:3180 */
/*<       yend=spzdn-zbvec(id) >*/
    *yend = static_cast<double>(spzdn) - culcom_1.zbvec[*id - 1];
/* SOURCE culvertd.for:3181 */
/*<       yhigh=0 >*/
    *yhigh = (float)0.;
/* SOURCE culvertd.for:3182 */
/*<       jmploc=0 >*/
    *jmploc = 0;
/* SOURCE culvertd.for:3183 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE culvertd.for:3185 */
/*<   900 continue >*/
L900:
/*         Both profiles complete. */
/*          WRITE(STDOUT,*) ' LOCJMP: Found option 9' */
/* SOURCE culvertd.for:3188 */
/*<       protyp='BOTH' >*/
    s_copy(protyp, const_cast<char*>("BOTH"), (ftnlen)8, (ftnlen)4);
/* SOURCE culvertd.for:3189 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE culvertd.for:3191 */
/*<  2000 continue >*/
L2000:
/*     Find the jump location and high-side value here.  ISP points */
/*     to the end of the supercritical profile and ISB points to */
/*     the end of the subcritical profile and ISP > ISB.   Start the */
/*     search at ISB.  Adjust for adding critical depth at end of */
/*     failed profiles. */
/* SOURCE culvertd.for:3198 */
/*<       if(isp.lt.id)then >*/
    if (isp < *id) {
/* SOURCE culvertd.for:3199 */
/*<       isp=isp+1 >*/
	++isp;
/* SOURCE culvertd.for:3200 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3201 */
/*<       if(isb.gt.iu)then >*/
    if (isb > *iu) {
/* SOURCE culvertd.for:3202 */
/*<       isb=isb-1 >*/
	--isb;
/* SOURCE culvertd.for:3203 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3205 */
/*<       isup=0 >*/
    isup = 0;
/* SOURCE culvertd.for:3206 */
/*<       isub=0 >*/
    isub = 0;
/* SOURCE culvertd.for:3207 */
/*<       ysupl=yvecsp(isb) >*/
    ysupl = culcom_1.yvecsp[isb - 1];
/* SOURCE culvertd.for:3208 */
/*<       yt=min(dvec(isb),ysupl) >*/
/* Computing MIN */
    feq_gen_r_d_1 = culcom_1.dvec[isb - 1];
    yt = dmin(feq_gen_r_d_1,ysupl);
/* SOURCE culvertd.for:3209 */
/*<        >*/
    xlkt22_(&culcom_1.nsec[isb - 1], &yt, &at, &tt, &dtt, &jt, &kt, &dkt, &
	    bett, &dbett, &alpt, &dalpt, &qct);
/* SOURCE culvertd.for:3214 */
/*<       msupl=bett*q**2/at+grav*jt >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *q;
    msupl = static_cast<double>(static_cast<double>(static_cast<double>(bett) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / at) + static_cast<double>(grvcom_1.grav) * jt;
/* SOURCE culvertd.for:3216 */
/*<       ysubl=yvecsb(isb) >*/
    ysubl = culcom_1.yvecsb[isb - 1];
/* SOURCE culvertd.for:3217 */
/*<       yt=min(dvec(isb),ysubl) >*/
/* Computing MIN */
    feq_gen_r_d_1 = culcom_1.dvec[isb - 1];
    yt = dmin(feq_gen_r_d_1,ysubl);
/* SOURCE culvertd.for:3218 */
/*<        >*/
    xlkt22_(&culcom_1.nsec[isb - 1], &yt, &at, &tt, &dtt, &jt, &kt, &dkt, &
	    bett, &dbett, &alpt, &dalpt, &qct);
/* SOURCE culvertd.for:3223 */
/*<       calllktj(nsec(isb),yvecsb(isb),jt) >*/
    lktj_(&culcom_1.nsec[isb - 1], &culcom_1.yvecsb[isb - 1], &jt);
/* SOURCE culvertd.for:3227 */
/*<       msubl=bett*q**2/at+grav*jt >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *q;
    msubl = static_cast<double>(static_cast<double>(static_cast<double>(bett) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / at) + static_cast<double>(grvcom_1.grav) * jt;
/* SOURCE culvertd.for:3229 */
/*<       if(msupl.gt.msubl)then >*/
    if (msupl > msubl) {
/* SOURCE culvertd.for:3230 */
/*<       isup=1 >*/
	isup = 1;
/* SOURCE culvertd.for:3231 */
/*<       elseif(msupl.lt.msubl)then >*/
    } else if (msupl < msubl) {
/* SOURCE culvertd.for:3232 */
/*<       isub=1 >*/
	isub = 1;
/* SOURCE culvertd.for:3233 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,52) */
/*      WRITE(STDOUT,54) ISB, YSUPL, MSUPL, YSUBL, MSUBL */
/* SOURCE culvertd.for:3237 */
/*<       ijump=0 >*/
    ijump = 0;
/* SOURCE culvertd.for:3238 */
/*<       do130i=isb+1,isp >*/
    feq_gen_i_d_1 = isp;
    for (feq_gen_i_d_ = isb + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertd.for:3240 */
/*<       ysupr=yvecsp(i) >*/
	ysupr = culcom_1.yvecsp[feq_gen_i_d_ - 1];
/* SOURCE culvertd.for:3241 */
/*<       yt=min(dvec(i),ysupr) >*/
/* Computing MIN */
	feq_gen_r_d_1 = culcom_1.dvec[feq_gen_i_d_ - 1];
	yt = dmin(feq_gen_r_d_1,ysupr);
/* SOURCE culvertd.for:3242 */
/*<        >*/
	xlkt22_(&culcom_1.nsec[feq_gen_i_d_ - 1], &yt, &at, &tt, &dtt, &jt, &kt, &dkt, 
		&bett, &dbett, &alpt, &dalpt, &qct);
/* SOURCE culvertd.for:3247 */
/*<       msupr=bett*q**2/at+grav*jt >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = *q;
	msupr = static_cast<double>(static_cast<double>(static_cast<double>(bett) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / at) + static_cast<double>(grvcom_1.grav) * jt;
/* SOURCE culvertd.for:3249 */
/*<       ysubr=yvecsb(i) >*/
	ysubr = culcom_1.yvecsb[feq_gen_i_d_ - 1];
/* SOURCE culvertd.for:3250 */
/*<       yt=min(dvec(i),ysubr) >*/
/* Computing MIN */
	feq_gen_r_d_1 = culcom_1.dvec[feq_gen_i_d_ - 1];
	yt = dmin(feq_gen_r_d_1,ysubr);
/* SOURCE culvertd.for:3251 */
/*<        >*/
	xlkt22_(&culcom_1.nsec[feq_gen_i_d_ - 1], &yt, &at, &tt, &dtt, &jt, &kt, &dkt, 
		&bett, &dbett, &alpt, &dalpt, &qct);
/* SOURCE culvertd.for:3256 */
/*<       calllktj(nsec(i),ysubr,jt) >*/
	lktj_(&culcom_1.nsec[feq_gen_i_d_ - 1], &ysubr, &jt);
/* SOURCE culvertd.for:3260 */
/*<       msubr=bett*q**2/at+grav*jt >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = *q;
	msubr = static_cast<double>(static_cast<double>(static_cast<double>(bett) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / at) + static_cast<double>(grvcom_1.grav) * jt;
/*        WRITE(STDOUT,54) I, YSUPR, MSUPR, YSUBR, MSUBR */
/* SOURCE culvertd.for:3264 */
/*<       if(msupl.ge.msubl.and.msupr.le.msubr)then >*/
	if (msupl >= msubl && msupr <= msubr) {
/*         There is a jump in the interval. */
/*         Find relative distance from the upstream end of the */
/*         current distance increment */
/* SOURCE culvertd.for:3269 */
/*<       p=(msupl-msubl)/(msupl-msubl-msupr+msubr) >*/
	    p = static_cast<double>((static_cast<double>(msupl) - msubl)) / (static_cast<double>(static_cast<double>(static_cast<double>(msupl) - msubl) - msupr) + msubr);
/* SOURCE culvertd.for:3270 */
/*<       ysub=ysubl+p*(ysubr-ysubl) >*/
	    ysub = static_cast<double>(ysubl) + static_cast<double>(p) * (static_cast<double>(ysubr) - ysubl);
/* SOURCE culvertd.for:3271 */
/*<       ijump=i >*/
	    ijump = feq_gen_i_d_;
/*          GOTO 131 */
/* SOURCE culvertd.for:3273 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:3274 */
/*<       if(msupl.gt.msubl)then >*/
	if (msupl > msubl) {
/* SOURCE culvertd.for:3275 */
/*<       isup=1 >*/
	    isup = 1;
/* SOURCE culvertd.for:3276 */
/*<       elseif(msupl.lt.msubl)then >*/
	} else if (msupl < msubl) {
/* SOURCE culvertd.for:3277 */
/*<       isub=1 >*/
	    isub = 1;
/* SOURCE culvertd.for:3278 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:3280 */
/*<       msupl=msupr >*/
	msupl = msupr;
/* SOURCE culvertd.for:3281 */
/*<       ysupl=ysupr >*/
	ysupl = ysupr;
/* SOURCE culvertd.for:3283 */
/*<       msubl=msubr >*/
	msubl = msubr;
/* SOURCE culvertd.for:3284 */
/*<       ysubl=ysubr >*/
	ysubl = ysubr;
/* SOURCE culvertd.for:3286 */
/*<   130 continue >*/
/* L130: */
    }
/* SOURCE culvertd.for:3287 */
/*<   131 continue >*/
/* L131: */
/* SOURCE culvertd.for:3288 */
/*<       if(ijump.eq.0)then >*/
    if (ijump == 0) {
/*       No jump even with overlap. */
/* SOURCE culvertd.for:3290 */
/*<       if(protyp.eq.'BOTH')then >*/
	if (s_cmp(protyp, const_cast<char*>("BOTH"), (ftnlen)8, (ftnlen)4) == 0) {
/* SOURCE culvertd.for:3291 */
/*<       if(isup.eq.1)then >*/
	    if (isup == 1) {
/* SOURCE culvertd.for:3292 */
/*<       if(isub.eq.0)then >*/
		if (isub == 0) {
/*             Super critical profile always prevails. */
/* SOURCE culvertd.for:3294 */
/*<       protyp='SUP' >*/
		    s_copy(protyp, const_cast<char*>("SUP"), (ftnlen)8, (ftnlen)3);
/* SOURCE culvertd.for:3295 */
/*<       yend=yvecsp(id) >*/
		    *yend = culcom_1.yvecsp[*id - 1];
/* SOURCE culvertd.for:3296 */
/*<       else >*/
		} else {
/*             Pattern does not show a jump but there is a */
/*             change in relationship.  Take supercritical flow */
/*             as prevailing. */
/* SOURCE culvertd.for:3300 */
/*<       protyp='SUP' >*/
		    s_copy(protyp, const_cast<char*>("SUP"), (ftnlen)8, (ftnlen)3);
/* SOURCE culvertd.for:3301 */
/*<       yend=yvecsp(id) >*/
		    *yend = culcom_1.yvecsp[*id - 1];
/* SOURCE culvertd.for:3302 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:3303 */
/*<       else >*/
	    } else {
/* SOURCE culvertd.for:3304 */
/*<       if(isub.eq.0)then >*/
		if (isub == 0) {
/* SOURCE culvertd.for:3305 */
/*<       write(stdout,*)' *BUG:XXX* LOCJMP: ISUB=0 & ISUP=0' >*/
		    feq_gen_io_d__302.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__302);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* LOCJMP: ISUB=0 & ISUP=0"),
			     (ftnlen)34);
		    e_wsle();
/* SOURCE culvertd.for:3306 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:3307 */
/*<       else >*/
		} else {
/*             Subcritical profile always prevails */
/* SOURCE culvertd.for:3309 */
/*<       protyp='SUB' >*/
		    s_copy(protyp, const_cast<char*>("SUB"), (ftnlen)8, (ftnlen)3);
/* SOURCE culvertd.for:3310 */
/*<       yend=yvecsb(id) >*/
		    *yend = culcom_1.yvecsb[*id - 1];
/* SOURCE culvertd.for:3311 */
/*<       endif >*/
		}
/* SOURCE culvertd.for:3312 */
/*<       endif >*/
	    }
/* SOURCE culvertd.for:3313 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:3314 */
/*<       ierr=0 >*/
	*ierr = 0;
/* SOURCE culvertd.for:3315 */
/*<       jmploc=0 >*/
	*jmploc = 0;
/* SOURCE culvertd.for:3316 */
/*<       yhigh=0.0 >*/
	*yhigh = (float)0.;
/* SOURCE culvertd.for:3317 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:3318 */
/*<       jmploc=ijump >*/
	*jmploc = ijump;
/* SOURCE culvertd.for:3319 */
/*<       yhigh=ysub >*/
	*yhigh = ysub;
/* SOURCE culvertd.for:3320 */
/*<       yend=ydn >*/
	*yend = *ydn;
/* SOURCE culvertd.for:3321 */
/*<       ierr=0 >*/
	*ierr = 0;
/* SOURCE culvertd.for:3322 */
/*<       protyp='MIXED' >*/
	s_copy(protyp, const_cast<char*>("MIXED"), (ftnlen)8, (ftnlen)5);
/* SOURCE culvertd.for:3323 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3326 */
/*<  9000 continue >*/
L9000:
/*      WRITE(STDOUT,*) ' LOCJMP at exit: PROTYP=',PROTYP,' YHIGH=',YHIGH, */
/*     A                ' YEND=',YEND,' JMPLOC=',JMPLOC,' IERR=',IERR */
/* SOURCE culvertd.for:3329 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:3330 */
/*<       end >*/
} /* locjmp_ */




/* SOURCE culvertd.for:3334 */
/*<       realfunctionrqvstw(q) >*/
doublereal rqvstw_(real *q)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    real dh;
    integer is;
    real ddn, dup;
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    integer sflag;
    extern /* Subroutine */ int appro_(integer *, real *, real *, real *, 
	    integer *, integer *), fndcde_(integer *, integer *, real *, real 
	    *);
    extern doublereal degcon_(real *, real *, real *);
    integer conflg, nsflag;
    extern /* Subroutine */ int sfpsbe_(integer *, integer *, integer *, real 
	    *, real *, real *, integer *, real *, integer *), xlktal_(integer 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Residual function for finding the flow in the culvert barrel */
/*     given the upstream head and a fixed tailwater level, Z43FIX. */
/* SOURCE culvertd.for:3341 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:3344 */
/*<       realq >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Q      - Flowrate */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:3350 */
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
/* INCLUDE culvertd.for:3351 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertd.for:3352 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertd.for:3353 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertd.for:3354 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertd.for:3355 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:3356 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertd.for:3357 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertd.for:3358 */
/* SOURCE rqvstw.cmn:2 */
/*<       integeriup,idn,sbflag,outun,cqtype,fqtype >*/
/* SOURCE rqvstw.cmn:3 */
/*<       realzsub,z43fix,abase,z1t,qfixed >*/
/* SOURCE rqvstw.cmn:5 */
/*<       character*8class >*/
/* SOURCE rqvstw.cmn:8 */
/*<        >*/
/* SOURCE rqvstw.cmn:11 */
/*<       common/rqvtc/class >*/
/* INCLUDE culvertd.for:3359 */
/*     Common block for various parameters to handle transitional */
/*     flow type behavior for the departure reach computations. */
/* SOURCE typtrn.cmn:4 */
/*<       common/typtrn/avhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/* SOURCE typtrn.cmn:6 */
/*<       realavhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/*     AVHF- area used for velocity head in computing losses for the */
/*           transitional free flow */
/*     CDF- coef. of discharge for computing losses for the transitional */
/*          free flow. */
/*     BETAF- value of beta to compensate for false area in the computation */
/*            of the momentum flux from some free flows.  If this */
/*            value is zero it means that the beta from the cross section */
/*            function table should be used.  If it is non-zero it means */
/*            that the free flow type was used as a transition and that */
/*            the flow area of the culvert barrel outlet was falsified in */
/*            the process. */
/*     ALPHAF- value of alpha to use in computing velocity head for */
/*             energy loss computations. */
/*     Y3PF- depth to the piezometric level at the culvert barrel outlet */
/*           for free flow limit. */
/*     BETA3- actual value at section 3 used in departure reach */
/*     ALPHA3- actual value at section 3.  Crudely estimated in some */
/*             cases because better alternative is not available. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:3362 */
/*<       integerconflg,is,nsflag,sflag >*/
/* SOURCE culvertd.for:3363 */
/*<       realddn,dh,dup >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:3366 */
/*<       realdegcon,fcd123 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:3369 */
/*<       externalappro,degcon,fcd123,fndcde,sfpsbe,xlktal >*/
/* *********************************************************************** */
/*      WRITE(OUTUN,*) ' RQVSTW ENTRY: Q=',Q,' Z43FIX=',Z43FIX */
/* SOURCE culvertd.for:3372 */
/*<       y3p=z43fix-zb3 >*/
    xs3com_1.y3p = static_cast<double>(rqvtw_1.z43fix) - xs3com_1.zb3;
/* SOURCE culvertd.for:3373 */
/*<       dup=dvec(iup) >*/
    dup = culcom_1.dvec[rqvtw_1.iup - 1];
/* SOURCE culvertd.for:3374 */
/*<       ddn=dvec(idn) >*/
    ddn = culcom_1.dvec[rqvtw_1.idn - 1];
/*     Establish the flows */
/* SOURCE culvertd.for:3378 */
/*<       q1=q+wfrd >*/
    xs1com_1.q1 = static_cast<double>(*q) + rdfcom_1.wfrd;
/* SOURCE culvertd.for:3379 */
/*<       q2=q >*/
    xs2com_1.q2 = *q;
/* SOURCE culvertd.for:3380 */
/*<       q3=q >*/
    xs3com_1.q3 = *q;
/*     Assume free surface flow at least part way.  Find solution */
/*     under this assumption.  The calling program unit must then */
/*     decide if that assumption is valid or not.  We cannot make the */
/*     decision here because it may be premature.  That is, this function */
/*     is called as part of an iterative solution.  In that process */
/*     there may be values of flow that cause the entrance soffit */
/*     to be submerged but that flow is not the final flow; it is only */
/*     one of many flows encountered in the process of finding */
/*     the final flow.  This final flow may be such that the entrance */
/*     soffit is free of water. */
/*     Find discharge coefficient without interpolation of any kind. */
/* SOURCE culvertd.for:3394 */
/*<       c123=fcd123(outun,3,class,dup,z1t) >*/
    cdcom_1.c123 = fcd123_(&rqvtw_1.outun, &feq_gen_c_d_3, rqvtc_1.feq_gen_class_d_, &dup, &
	    rqvtw_1.z1t, (ftnlen)8);
/*      WRITE(OUTUN,*) ' RQVSTW: C123=',C123 */
/*      IF(FQTYPE.EQ.1) THEN */
/*        AVH = A2 */
/*      ELSE */
/* SOURCE culvertd.for:3399 */
/*<       avh=a3 >*/
    cdcom_1.avh = xs3com_1.a3;
/*      ENDIF */
/* SOURCE culvertd.for:3401 */
/*<       cd=degcon(c123,abase,avh) >*/
    cdcom_1.cd = degcon_(&cdcom_1.c123, &rqvtw_1.abase, &cdcom_1.avh);
/*      WRITE(OUTUN,*) ' RQVSTW: CD=',CD, ' AVH=',AVH */
/* SOURCE culvertd.for:3404 */
/*<       if(betaf.eq.-1.0)then >*/
    if (typtrn_1.betaf == (float)-1.) {
/*       Computing submergence when the coef. of discharge and the */
/*       area for velocity head vary with the depth in the barrel exit. */
/*       Assumes that the flow is moving toward full flow at the */
/*       exit with full flow at the entrance. */
/* SOURCE culvertd.for:3409 */
/*<       cd=cdf+(y3p-y3pf)*(c46-cdf)/(ddn-y3pf) >*/
	cdcom_1.cd = static_cast<double>(typtrn_1.cdf) + static_cast<double>(static_cast<double>((static_cast<double>(xs3com_1.y3p) - typtrn_1.y3pf)) * (
		static_cast<double>(cdcom_1.c46) - typtrn_1.cdf)) / (static_cast<double>(ddn) - typtrn_1.y3pf);
/* SOURCE culvertd.for:3410 */
/*<       avh=avhf+(y3p-y3pf)*(a2full-avhf)/(ddn-y3pf) >*/
	cdcom_1.avh = static_cast<double>(typtrn_1.avhf) + static_cast<double>(static_cast<double>((static_cast<double>(xs3com_1.y3p) - typtrn_1.y3pf)) * (
		static_cast<double>(xs2com_1.a2full) - typtrn_1.avhf)) / (static_cast<double>(ddn) - typtrn_1.y3pf);
/* SOURCE culvertd.for:3411 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3413 */
/*<       dh=(1.0/cd**2-1.0)*(q/avh)**2/grav2 >*/
/* Computing 2nd power */
    // Original Q/AVH stays wide through its square; DH is the only REAL store.
    dh = feq::culvert_head_loss(cdcom_1.cd,*q,cdcom_1.avh,grvcom_1.grav2);
/*      WRITE(OUTUN,*) ' RQVSTW: DH=',DH,' Q=',Q */
/* SOURCE culvertd.for:3415 */
/*<       vhl=0.0 >*/
    cdcom_1.vhl = (float)0.;
/* SOURCE culvertd.for:3417 */
/*<       callsfpsbe(outun,iup,idn,dh,q3,z43fix,is,z2,sflag) >*/
    sfpsbe_(&rqvtw_1.outun, &rqvtw_1.iup, &rqvtw_1.idn, &dh, &xs3com_1.q3, &
	    rqvtw_1.z43fix, &is, &xs2com_1.z2, &sflag);
/*      WRITE(OUTUN,*) ' RQVSTW: SFPSBE:SFLAG=',SFLAG,' Z2=',Z2,' DH=',DH, */
/*     A             ' IS=',IS,' Z43FIX=',Z43FIX */
/* SOURCE culvertd.for:3423 */
/*<       y2=z2-zb2 >*/
    xs2com_1.y2 = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culvertd.for:3424 */
/*<       callxlktal(adrxs2,y2,a2,t2,dt2,j2,k2,dk2,bet2,dbet2,alp2,dalp2) >*/
    xlktal_(&xs2com_1.adrxs2, &xs2com_1.y2, &xs2com_1.a2, &xs2com_1.t2, &
	    xs2com_1.dt2, &xs2com_1.j2, &xs2com_1.k2, &xs2com_1.dk2, &
	    xs2com_1.bet2, &xs2com_1.dbet2, &xs2com_1.alp2, &xs2com_1.dalp2);
/* SOURCE culvertd.for:3429 */
/*<       if(sflag.eq.1)then >*/
    if (sflag == 1) {
/* SOURCE culvertd.for:3430 */
/*<       sbflag=0 >*/
	rqvtw_1.sbflag = 0;
/* SOURCE culvertd.for:3431 */
/*<       else >*/
    } else {
/*       Try continuing the profile towards critical depth. */
/* SOURCE culvertd.for:3433 */
/*<       callfndcde(outun,adrxs2,q3,y2) >*/
	fndcde_(&rqvtw_1.outun, &xs2com_1.adrxs2, &xs3com_1.q3, &xs2com_1.y2);
/*        YCRIT = Y2 */
/*        YSTART = YVECSB(IDN) */
/*        SLOPE = (ZBVEC(IUP) - ZBVEC(IDN))/ABS(XVEC(IDN) - XVEC(IUP)) */
/*        SE = DH/ABS(XVEC(IUP) - XVEC(IDN)) */
/*        SLOPE = SLOPE - SE */
/*        OFFSET = XVEC(IUP) - XVEC(IDN) */
/*        OFF = OFFSET */
/*        FFAC = 1.0 - KD(IUP+1) */
/*        CALL ENDSFP(OUTUN, ADRXS2, FFAC, YSTART, YCRIT, Q3, OFF, */
/*     A                  SLOPE, Y2) */
/*        WRITE(OUTUN,*) ' OFF=',OFF,' OFFSET=',OFFSET,' Y=',Y2 */
/* SOURCE culvertd.for:3448 */
/*<       z2=y2+zb2 >*/
	xs2com_1.z2 = static_cast<double>(xs2com_1.y2) + xs2com_1.zb2;
/* SOURCE culvertd.for:3449 */
/*<       callxlktal(adrxs2,y2,a2,t2,dt2,j2,k2,dk2,bet2,dbet2,alp2,dalp2) >*/
	xlktal_(&xs2com_1.adrxs2, &xs2com_1.y2, &xs2com_1.a2, &xs2com_1.t2, &
		xs2com_1.dt2, &xs2com_1.j2, &xs2com_1.k2, &xs2com_1.dk2, &
		xs2com_1.bet2, &xs2com_1.dbet2, &xs2com_1.alp2, &
		xs2com_1.dalp2);
/*        SBFLAG = -1 */
/* SOURCE culvertd.for:3454 */
/*<       sbflag=0 >*/
	rqvtw_1.sbflag = 0;
/*        WRITE(OUTUN,*) ' RQVSTW: TEL entrance=', */
/*     A             Z2 + ALP2*(Q2/A2)**2/GRAV2,' IS=',IS,' IUP=',IUP */
/* SOURCE culvertd.for:3457 */
/*<       endif >*/
    }
/*      WRITE(OUTUN,*) ' RQVSTW: Y3P=',Y3P,' Y2=',Y2,' CD=',CD, */
/*     A    ' AVH=',AVH,' VHL=',VHL */
/*     Compute the water level at section 1. */
/* SOURCE culvertd.for:3462 */
/*<       if(sbflag.eq.0)then >*/
    if (rqvtw_1.sbflag == 0) {
/* SOURCE culvertd.for:3463 */
/*<       callappro(outun,cd,vhl,wfrd,conflg,nsflag) >*/
	appro_(&rqvtw_1.outun, &cdcom_1.cd, &cdcom_1.vhl, &rdfcom_1.wfrd, &
		conflg, &nsflag);
/* SOURCE culvertd.for:3466 */
/*<       if(nsflag.eq.1)then >*/
	if (nsflag == 1) {
/*         Take special action in the calling routine.  Flow is */
/*         probably too large. */
/* SOURCE culvertd.for:3469 */
/*<       sbflag=-2 >*/
	    rqvtw_1.sbflag = -2;
/* SOURCE culvertd.for:3470 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:3471 */
/*<       endif >*/
    }
/*     Compute the residual */
/* SOURCE culvertd.for:3474 */
/*<       rqvstw=z1-z1t >*/
    return feq::approach_head_residual(xs1com_1.z1,rqvtw_1.z1t);
/*      WRITE(OUTUN,*) ' AT EXIT RQVSTW=',RQVSTW,' Y2=',Y2, */
/*     A            ' SBFLAG=',SBFLAG */
/*      WRITE(OUTUN,*) ' Z1=',Z1,' Z1T=',Z1T */
/* SOURCE culvertd.for:3478 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:3479 */
/*<       end >*/
} /* rqvstw_ */




/* SOURCE culvertd.for:3483 */
/*<       realfunctionrty0(y) >*/
doublereal rty0_(real *y)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    real dh;
    integer is;
    real yt, vh1, vh2, cdin;
    extern /* Subroutine */ int lkta_(integer *, real *, real *);
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    extern /* Subroutine */ int sfpty1_(integer *, integer *, integer *, real 
	    *, real *, real *, integer *, real *, integer *);
    real appfac;
    extern doublereal degcon_(real *, real *, real *);
    real aratio;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute the residual for the approach reach when */
/*     the conditions at section 1 are given and a sub-critical */
/*     solution at section 2 is sought. */
/* SOURCE culvertd.for:3491 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:3494 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:3500 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertd.for:3501 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertd.for:3502 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertd.for:3503 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertd.for:3504 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:3505 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertd.for:3506 */
/*     Common for function RTY0 in FEQUTL */
/* SOURCE rty0c.cmn:3 */
/*<       common/rty0c/outun0,dup0,a1t0,ddn0,z1t0,iup0,idn0,sflag0 >*/
/* SOURCE rty0c.cmn:4 */
/*<       integeroutun0,iup0,idn0,sflag0 >*/
/* SOURCE rty0c.cmn:5 */
/*<       realdup0,a1t0,ddn0,z1t0 >*/
/* SOURCE rty0c.cmn:6 */
/*<       common/rty0cc/class0 >*/
/* SOURCE rty0c.cmn:7 */
/*<       character*8class0 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:3509 */
/*<       integeris >*/
/* SOURCE culvertd.for:3510 */
/*<       realappfac,aratio,cdin,dh,vh1,vh2,yt >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertd.for:3513 */
/*<       intrinsicmin >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:3516 */
/*<       realdegcon,fcd123 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:3519 */
/*<       externaldegcon,fcd123,lkta,sfpty1,xlktal >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:3521 */
/*<       y2=y >*/
    xs2com_1.y2 = *y;
/* SOURCE culvertd.for:3522 */
/*<       yt=min(y,dup0) >*/
    yt = dmin(*y,rty0c_1.dup0);
/* SOURCE culvertd.for:3523 */
/*<       callxlktal(adrxs2,yt,a2,t2,dt2,j2,k2,dk2,bet2,dbet2,alp2,dalp2) >*/
    xlktal_(&xs2com_1.adrxs2, &yt, &xs2com_1.a2, &xs2com_1.t2, &xs2com_1.dt2, 
	    &xs2com_1.j2, &xs2com_1.k2, &xs2com_1.dk2, &xs2com_1.bet2, &
	    xs2com_1.dbet2, &xs2com_1.alp2, &xs2com_1.dalp2);
/* SOURCE culvertd.for:3528 */
/*<       z2=zb2+y2 >*/
    xs2com_1.z2 = static_cast<double>(xs2com_1.zb2) + xs2com_1.y2;
/* SOURCE culvertd.for:3529 */
/*<       vh1=(q1/a1)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(xs1com_1.q1) / xs1com_1.a1;
    vh1 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/* SOURCE culvertd.for:3530 */
/*<       vh2=(q2/a2)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(xs2com_1.q2) / xs2com_1.a2;
    vh2 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/* SOURCE culvertd.for:3532 */
/*<       c123=fcd123(outun0,3,class0,dup0,z1t0) >*/
    cdcom_1.c123 = fcd123_(&rty0c_1.outun0, &feq_gen_c_d_3, rty0cc_1.class0, &
	    rty0c_1.dup0, &rty0c_1.z1t0, (ftnlen)8);
/* SOURCE culvertd.for:3534 */
/*<       cd=degcon(c123,a1t0,a3) >*/
    cdcom_1.cd = degcon_(&cdcom_1.c123, &rty0c_1.a1t0, &xs3com_1.a3);
/* SOURCE culvertd.for:3536 */
/*<       cdin=cd >*/
    cdin = cdcom_1.cd;
/* SOURCE culvertd.for:3537 */
/*<       if(a1.le.a2)then >*/
    if (xs1com_1.a1 <= xs2com_1.a2) {
/*       EXPANSION(NEGATIVE ACCELERATION) IN FLOW INSTEAD OF CONTRACTION */
/* SOURCE culvertd.for:3539 */
/*<       aratio=a1/a2 >*/
	aratio = static_cast<double>(xs1com_1.a1) / xs2com_1.a2;
/* SOURCE culvertd.for:3540 */
/*<       if(aratio.gt.0.95)then >*/
	if (aratio > (float).95) {
/*         Interpolate coefficients to make the transition between */
/*         the two cases smooth. */
/* SOURCE culvertd.for:3543 */
/*<       cd=cdin+20.0*(1.0-aratio)*(0.98-cdin) >*/
	    cdcom_1.cd = static_cast<double>(cdin) + static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * (static_cast<double>((float)
		    .98) - cdin);
/* SOURCE culvertd.for:3544 */
/*<       appfac=20.0*(1.0-aratio)*appexp >*/
	    appfac = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * appcom_1.appexp;
/* SOURCE culvertd.for:3545 */
/*<       else >*/
	} else {
/* SOURCE culvertd.for:3546 */
/*<       cd=0.98 >*/
	    cdcom_1.cd = (float).98;
/* SOURCE culvertd.for:3547 */
/*<       appfac=appexp >*/
	    appfac = appcom_1.appexp;
/* SOURCE culvertd.for:3548 */
/*<       endif >*/
	}
/*        CONF = 0 */
/* SOURCE culvertd.for:3550 */
/*<        >*/
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) * vh1) + xs1com_1.zb1) + 
		xs1com_1.y1) - (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(xs2com_1.alp2) * vh2) + xs2com_1.zb2) + 
		xs2com_1.y2) + static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * xs1com_1.q1) * xs2com_1.q2) / (
		static_cast<double>(xs1com_1.k1) * xs2com_1.k2)) + static_cast<double>(appfac) * (static_cast<double>(static_cast<double>(xs1com_1.alp1) * vh1) - 
		static_cast<double>(xs2com_1.alp2) * vh2));
/* SOURCE culvertd.for:3553 */
/*<       else >*/
    } else {
/*        CONF = 1 */
/* SOURCE culvertd.for:3555 */
/*<       cd=cdin >*/
	cdcom_1.cd = cdin;
/* SOURCE culvertd.for:3556 */
/*<        >*/
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(xs1com_1.alp1) * vh1) + xs1com_1.zb1) + xs1com_1.y1) - (
		static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(xs2com_1.alp2) * vh2) + xs2com_1.zb2) + xs2com_1.y2) + 
		static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * xs1com_1.q1) * xs2com_1.q2) / (static_cast<double>(xs1com_1.k1) * 
		xs2com_1.k2)) + static_cast<double>(appcom_1.applos) * vh1);
/* SOURCE culvertd.for:3558 */
/*<       endif >*/
    }
/*      WRITE(OUTUN0,*) ' AT Y1=',Y1,' RTY0',RTY0,' CONF=',CONF */
/*     COMPUTE THE PROFILE TO THE END OF THE BARREL */
/* SOURCE culvertd.for:3563 */
/*<       dh=0.0 >*/
    dh = (float)0.;
/* SOURCE culvertd.for:3564 */
/*<       callsfpty1(outun0,iup0,idn0,dh,q2,z2,is,z3,sflag0) >*/
    sfpty1_(&rty0c_1.outun0, &rty0c_1.iup0, &rty0c_1.idn0, &dh, &xs2com_1.q2, 
	    &xs2com_1.z2, &is, &xs3com_1.z3, &rty0c_1.sflag0);
/* SOURCE culvertd.for:3567 */
/*<       if(sflag0.eq.0)then >*/
    if (rty0c_1.sflag0 == 0) {
/* SOURCE culvertd.for:3568 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertd.for:3569 */
/*<       endif >*/
    }
/*     Estimate type 3 losses.  Only rough estimate is possible or */
/*     needed. */
/* SOURCE culvertd.for:3572 */
/*<       y3=z3-zb3 >*/
    xs3com_1.y3 = static_cast<double>(xs3com_1.z3) - xs3com_1.zb3;
/*     Define new value of area at section 3. */
/* SOURCE culvertd.for:3574 */
/*<       yt=min(y3,ddn0) >*/
    yt = dmin(xs3com_1.y3,rty0c_1.ddn0);
/* SOURCE culvertd.for:3575 */
/*<       calllkta(adrxs3,yt,a3) >*/
    lkta_(&xs3com_1.adrxs3, &yt, &xs3com_1.a3);
/* SOURCE culvertd.for:3579 */
/*<       dh=(1.0/cd**2-1.0)*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = cdcom_1.cd;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3;
    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
	    grvcom_1.grav2;
/* SOURCE culvertd.for:3581 */
/*<   100 continue >*/
L100:
/* SOURCE culvertd.for:3582 */
/*<       callsfpty1(outun0,iup0,idn0,dh,q2,z2,is,z3,sflag0) >*/
    sfpty1_(&rty0c_1.outun0, &rty0c_1.iup0, &rty0c_1.idn0, &dh, &xs2com_1.q2, 
	    &xs2com_1.z2, &is, &xs3com_1.z3, &rty0c_1.sflag0);
/* SOURCE culvertd.for:3585 */
/*<       if(sflag0.eq.0)then >*/
    if (rty0c_1.sflag0 == 0) {
/* SOURCE culvertd.for:3586 */
/*<       dh=0.8*dh >*/
	dh *= static_cast<double>((float).8);
/* SOURCE culvertd.for:3587 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertd.for:3588 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3589 */
/*<       y3=z3-zb3 >*/
    xs3com_1.y3 = static_cast<double>(xs3com_1.z3) - xs3com_1.zb3;
/*     Define new value of area at section 3. */
/* SOURCE culvertd.for:3591 */
/*<       yt=min(y3,ddn0) >*/
    yt = dmin(xs3com_1.y3,rty0c_1.ddn0);
/* SOURCE culvertd.for:3592 */
/*<       calllkta(adrxs3,yt,a3) >*/
    lkta_(&xs3com_1.adrxs3, &yt, &xs3com_1.a3);
/* SOURCE culvertd.for:3596 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:3597 */
/*<       end >*/
} /* rty0_ */




/* SOURCE culvertd.for:3601 */
/*<       realfunctionrty2(y) >*/
doublereal rty2_(real *y)
{
    /* Format strings */
    static char fmt_52[] = "(/,\002 *WRN:572* Unable to compute subcritical \
profile for \002,\002Type 2.\002,/,11x,\002Adjusting critical depth and tryi\
ng \002,\002 again.\002,/,11x,\002Y3=\002,f10.3,\002 Q3=\002,f10.2,\002 IS\
=\002,i5,\002 SFLAG=\002,i5)";
    static char fmt_53[] = "(/,\002 *WRN:573*  Unable to compute approach re\
ach for \002,\002Type 2.\002,/,11x,\002Increasing critical depth and trying\
 \002,\002again.\002,/,11x,\002Y3=\002,f10.3,\002 Q3=\002,f10.2)";

    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real dh;
    integer is;
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    integer sflag, ftype;
    extern /* Subroutine */ int appro_(integer *, real *, real *, real *, 
	    integer *, integer *), xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    extern doublereal degcon_(real *, real *, real *);
    integer nsflag;
    extern /* Subroutine */ int sfpsbe_(integer *, integer *, integer *, real 
	    *, real *, real *, integer *, real *, integer *), xlktal_(integer 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__322 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__324 = { 0, 0, 0, fmt_53, 0 };


/*     + + + PURPOSE + + + */
/*     Compute residual for type 2 flow */
/* SOURCE culvertd.for:3607 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:3610 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:3616 */
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
/* INCLUDE culvertd.for:3617 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertd.for:3618 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertd.for:3619 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertd.for:3620 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertd.for:3621 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertd.for:3622 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertd.for:3623 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertd.for:3624 */
/*     Commons for function RTY2 in FEQUTL */
/* SOURCE rty2c.cmn:3 */
/*<        >*/
/* SOURCE rty2c.cmn:5 */
/*<       integeroutun,iup,idn,ef,conf,ns,sbflag >*/
/* SOURCE rty2c.cmn:6 */
/*<       realz1true,a1true,sbot,alp1tr,maxarg >*/
/* SOURCE rty2c.cmn:7 */
/*<       common/rty2cc/class >*/
/* SOURCE rty2c.cmn:8 */
/*<       character*8class >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:3627 */
/*<       integerftype,is,nsflag,sflag >*/
/* SOURCE culvertd.for:3628 */
/*<       realdh >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertd.for:3631 */
/*<       realdegcon,fcd123 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:3634 */
/*<       externalappro,degcon,fcd123,sfpsbe,xlkt22,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertd.for:3637 */
/*<    52  >*/
/* SOURCE culvertd.for:3641 */
/*<    53  >*/
/* *********************************************************************** */
/*      WRITE(STD6,*) ' RTY2: Y=',Y */
/* SOURCE culvertd.for:3646 */
/*<       sbflag=0 >*/
/* L52: */
/* L53: */
    rty2c_1.sbflag = 0;
/* SOURCE culvertd.for:3647 */
/*<       ftype=2 >*/
    ftype = 2;
/* SOURCE culvertd.for:3648 */
/*<       y3=y >*/
    xs3com_1.y3 = *y;
/*     COMPUTE CRITICAL FLOW AT SECTION 3 */
/*     GET VALUES AT SECTION 3 */
/* SOURCE culvertd.for:3651 */
/*<        >*/
    xlkt22_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3, &xs3com_1.t3, &
	    xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
	    xs3com_1.bet3, &xs3com_1.dbet3, &xs3com_1.alp3, &xs3com_1.dalp3, &
	    xs3com_1.q3c);
/* SOURCE culvertd.for:3657 */
/*<       q3=q3c >*/
    xs3com_1.q3 = xs3com_1.q3c;
/* SOURCE culvertd.for:3658 */
/*<       q2=q3 >*/
    xs2com_1.q2 = xs3com_1.q3;
/*      WRITE(STD6,*) ' RTY2: Y3=',Y,' Q3C=',Q3 */
/*     ADD IN THE FREE FLOW OVER THE ROADWAY */
/* SOURCE culvertd.for:3662 */
/*<       q1=q3+wfrdf >*/
    xs1com_1.q1 = static_cast<double>(xs3com_1.q3) + rdfcom_1.wfrdf;
/* SOURCE culvertd.for:3663 */
/*<       z3=zb3+y3 >*/
    xs3com_1.z3 = static_cast<double>(xs3com_1.zb3) + xs3com_1.y3;
/*     DEFINE THE COEF OF DISCHARGE */
/* SOURCE culvertd.for:3667 */
/*<       c123=fcd123(outun,ftype,class,dvec(iup),z1true) >*/
    cdcom_1.c123 = fcd123_(&rty2c_1.outun, &ftype, rty2cc_1.feq_gen_class_d_, &
	    culcom_1.dvec[rty2c_1.iup - 1], &rty2c_1.z1true, (ftnlen)8);
/*     MAKE ADJUSTMENTS TO THE COEF. OF DISCHARGE FOR THE DEGREE OF */
/*     CHANNEL CONTRACTION */
/* SOURCE culvertd.for:3672 */
/*<       cd=degcon(c123,a1true,a3) >*/
    cdcom_1.cd = degcon_(&cdcom_1.c123, &rty2c_1.a1true, &xs3com_1.a3);
/* SOURCE culvertd.for:3673 */
/*<       dh=(1.0/cd**2-1.0)*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
    // RTY2 0x42e25c..0x42e293 retains Q3/A3 until the DH store.
    dh = feq::culvert_head_loss(cdcom_1.cd,xs3com_1.q3,xs3com_1.a3,grvcom_1.grav2);
/* SOURCE culvertd.for:3674 */
/*<       vhl=0.0 >*/
    cdcom_1.vhl = (float)0.;
/*      WRITE(OUTUN,*) ' RTY2: CD=',CD,' A for VH=',A3,' DH=',DH */
/*      WRITE(OUTUN,*) ' RTY2: Q3=',Q3,'  Y3=',Y3 */
/* SOURCE culvertd.for:3678 */
/*<       callsfpsbe(outun,iup,idn,dh,q3,z3,is,z2,sflag) >*/
    sfpsbe_(&rty2c_1.outun, &rty2c_1.iup, &rty2c_1.idn, &dh, &xs3com_1.q3, &
	    xs3com_1.z3, &is, &xs2com_1.z2, &sflag);
/*      WRITE(OUTUN,*) ' RTY2: AFTER SFPSBE: Z2=',Z2,' Z3=',Z3 */
/* SOURCE culvertd.for:3682 */
/*<       if(is.ne.iup)then >*/
    if (is != rty2c_1.iup) {
/*       UNABLE TO COMPUTE SUBCRITICAL PROFILE TO ENTRANCE */
/* SOURCE culvertd.for:3684 */
/*<       if(sflag.eq.0)then >*/
	if (sflag == 0) {
/* SOURCE culvertd.for:3685 */
/*<       rty2=1. >*/
	    ret_val = (float)1.;
/* SOURCE culvertd.for:3686 */
/*<       write(outun,52)y3,q3,is,sflag >*/
	    feq_gen_io_d__322.ciunit = rty2c_1.outun;
	    s_wsfe(&feq_gen_io_d__322);
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.y3, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.q3, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&is, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&sflag, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE culvertd.for:3687 */
/*<       sbflag=2 >*/
	    rty2c_1.sbflag = 2;
/* SOURCE culvertd.for:3688 */
/*<       return >*/
	    return ret_val;
/* SOURCE culvertd.for:3689 */
/*<       endif >*/
	}
/* SOURCE culvertd.for:3690 */
/*<       endif >*/
    }
/*     DEFINE VALUES AT SECTION 2 BECAUSE SFPSBE DOES NOT USE */
/*     XS2COM */
/* SOURCE culvertd.for:3695 */
/*<       y2=yvecsb(iup) >*/
    xs2com_1.y2 = culcom_1.yvecsb[rty2c_1.iup - 1];
/* SOURCE culvertd.for:3696 */
/*<       if(y2.ge.maxarg)then >*/
    if (xs2com_1.y2 >= rty2c_1.maxarg) {
/*       Take type 2 flow to be impossible.  Set flag for the */
/*       RGF routine. */
/* SOURCE culvertd.for:3699 */
/*<       sbflag=3 >*/
	rty2c_1.sbflag = 3;
/* SOURCE culvertd.for:3700 */
/*<       rty2=-1.e31 >*/
	ret_val = (float)-1e31;
/* SOURCE culvertd.for:3701 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertd.for:3702 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3703 */
/*<       callxlktal(adrxs2,y2,a2,t2,dt2,j2,k2,dk2,bet2,dbet2,alp2,dalp2) >*/
    xlktal_(&xs2com_1.adrxs2, &xs2com_1.y2, &xs2com_1.a2, &xs2com_1.t2, &
	    xs2com_1.dt2, &xs2com_1.j2, &xs2com_1.k2, &xs2com_1.dk2, &
	    xs2com_1.bet2, &xs2com_1.dbet2, &xs2com_1.alp2, &xs2com_1.dalp2);
/* SOURCE culvertd.for:3708 */
/*<       callappro(outun,cd,vhl,wfrdf,conf,nsflag) >*/
    appro_(&rty2c_1.outun, &cdcom_1.cd, &cdcom_1.vhl, &rdfcom_1.wfrdf, &
	    rty2c_1.conf, &nsflag);
/*      WRITE(OUTUN,*) ' RTY2: NSFLAG=',NSFLAG */
/* SOURCE culvertd.for:3713 */
/*<       ns=nsflag >*/
    rty2c_1.ns = nsflag;
/* SOURCE culvertd.for:3714 */
/*<       if(nsflag.eq.1)then >*/
    if (nsflag == 1) {
/*       Approach reach problem.  Assume that the flow has been made */
/*       too small. */
/* SOURCE culvertd.for:3717 */
/*<       rty2=1. >*/
	ret_val = (float)1.;
/* SOURCE culvertd.for:3718 */
/*<       sbflag=2 >*/
	rty2c_1.sbflag = 2;
/* SOURCE culvertd.for:3719 */
/*<       write(outun,53)y3,q3 >*/
	feq_gen_io_d__324.ciunit = rty2c_1.outun;
	s_wsfe(&feq_gen_io_d__324);
	do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.y3, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.q3, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertd.for:3720 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertd.for:3721 */
/*<       elseif(nsflag.eq.2)then >*/
    } else if (nsflag == 2) {
/*       Take type 2 flow to be impossible */
/* SOURCE culvertd.for:3723 */
/*<       sbflag=3 >*/
	rty2c_1.sbflag = 3;
/* SOURCE culvertd.for:3724 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertd.for:3725 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3727 */
/*<       rty2=z1-z1true >*/
    ret_val = static_cast<double>(xs1com_1.z1) - rty2c_1.z1true;
/*      WRITE(OUTUN,*) ' AT EXIT RTY2=',RTY2,' Q3=',Q3,' Y3=',Y3, */
/*     A               ' NSFLAG=',NSFLAG */
/* SOURCE culvertd.for:3731 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertd.for:3732 */
/*<       end >*/
} /* rty2_ */




/* SOURCE culvertd.for:3736 */
/*<        >*/
/* Subroutine */ int supsub_(integer *stdout, integer *iu, integer *id, real *
	yup, real *y3lim, real *q, real *dup, real *ycat3, real *ty6lss, real 
	*zat3, real *zat43, char *jmploc, ftnlen jmploc_len)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer ierr;
    real yend, yhigh;
    integer ijump;
    extern /* Subroutine */ int locjmp_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, integer *, real *, 
	    integer *, char *, ftnlen);
    char protyp[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__330 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__331 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find the conditions at the exit of the culvert required to */
/*     estimate drop to free flow for type 5 flow. */
/* SOURCE culvertd.for:3745 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:3748 */
/*<       integerid,iu,stdout >*/
/* SOURCE culvertd.for:3749 */
/*<       realdup,q,ty6lss,y3lim,ycat3,yup,zat3,zat43 >*/
/* SOURCE culvertd.for:3750 */
/*<       characterjmploc*32 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     YUP    - depth at vena contracta */
/*     Y3LIM  - full-flow-inducing depth at culvert exit for type 5 flow */
/*     Q      - Flowrate */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     YCAT3  - critical depth at section 3 */
/*     TY6LSS - estimated type 6 loss */
/*     ZAT3   - elevation of water surface at section 3 */
/*     ZAT43  - elevation of water surface at section 43 */
/*     JMPLOC - character string giving the jump location */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:3767 */
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
/* INCLUDE culvertd.for:3768 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:3771 */
/*<       integerierr,ijump >*/
/* SOURCE culvertd.for:3772 */
/*<       realyend,yhigh >*/
/* SOURCE culvertd.for:3773 */
/*<       characterprotyp*8 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:3776 */
/*<       externallocjmp >*/
/* *********************************************************************** */
/*     Seek jump in the barrel. */
/* SOURCE culvertd.for:3781 */
/*<        >*/
    locjmp_(stdout, iu, id, yup, ycat3, q, dup, ty6lss, &yhigh, &ijump, &yend,
	     &ierr, protyp, (ftnlen)8);
/* SOURCE culvertd.for:3786 */
/*<       if(ierr.ne.0)then >*/
    if (ierr != 0) {
/* SOURCE culvertd.for:3787 */
/*<       write(stdout,*)' *BUG:XXX SUPSUB: Error in locating jump.' >*/
	feq_gen_io_d__330.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__330);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX SUPSUB: Error in locating jump."), (
		ftnlen)41);
	e_wsle();
/* SOURCE culvertd.for:3788 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:3789 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3790 */
/*<       if(protyp.eq.'MIXED')then >*/
    if (s_cmp(protyp, const_cast<char*>("MIXED"), (ftnlen)8, (ftnlen)5) == 0) {
/*       Jump is in the barrel. */
/* SOURCE culvertd.for:3792 */
/*<       jmploc='Jump in the barrel' >*/
	s_copy(jmploc, const_cast<char*>("Jump in the barrel"), (ftnlen)32, (ftnlen)18);
/* SOURCE culvertd.for:3793 */
/*<       zat3=yend+zb3 >*/
	*zat3 = static_cast<double>(yend) + xs3com_1.zb3;
/* SOURCE culvertd.for:3794 */
/*<       zat43=zat3 >*/
	*zat43 = *zat3;
/* SOURCE culvertd.for:3796 */
/*<       elseif(protyp.eq.'SUP')then >*/
    } else if (s_cmp(protyp, const_cast<char*>("SUP"), (ftnlen)8, (ftnlen)3) == 0) {
/*       Jump is in the exit. */
/* SOURCE culvertd.for:3798 */
/*<       jmploc='Jump in the barrel exit' >*/
	s_copy(jmploc, const_cast<char*>("Jump in the barrel exit"), (ftnlen)32, (ftnlen)23);
/* SOURCE culvertd.for:3799 */
/*<       zat3=yend+zb3 >*/
	*zat3 = static_cast<double>(yend) + xs3com_1.zb3;
/* SOURCE culvertd.for:3800 */
/*<       zat43=zb3+y3lim >*/
	*zat43 = static_cast<double>(xs3com_1.zb3) + *y3lim;
/*        WRITE(STDOUT,50) */
/* SOURCE culvertd.for:3803 */
/*<       else >*/
    } else {
/*       Some problem here.  Should not be here. */
/* SOURCE culvertd.for:3805 */
/*<        >*/
	feq_gen_io_d__331.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__331);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* SUPSUB: Invalid profile outcome="), (
		ftnlen)43);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, protyp, (ftnlen)8);
	e_wsle();
/* SOURCE culvertd.for:3807 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertd.for:3808 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3810 */
/*<       end >*/
    return 0;
} /* supsub_ */




/* SOURCE culvertd.for:3814 */
/*<       subroutinegetfrf(z,zsbrdf,fdrdw) >*/
/* Subroutine */ int getfrf_(real *feq_gen_z_d_, real *zsbrdf, real *fdrdw)
{
    doublereal fd;
    real zt, hrdfd, hrdfu;
    extern /* Subroutine */ int frfemb_(real *, real *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, real *, 
	    char *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, ftnlen), embsub_(integer *, real *, integer *, 
	    char *, real *, real *, real *, real *, doublereal *, real *, 
	    ftnlen);

/*     + + + PURPOSE + + + */
/*     Compute the free flow over the road and find its */
/*     submergence limit.   Results are stored in RDFCOM and EMBCOM */
/*     and in ZSBRDF. */
/* SOURCE culvertd.for:3823 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertd.for:3826 */
/*<       realfdrdw,z,zsbrdf >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Z      - elevation at the approach to the roadway */
/*     ZSBRDF - water surface elevation at section 43 that begins */
/*              submergence of flow over the roadway */
/*     FDRDW  - free drop for flow over roadway */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertd.for:3835 */
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
/* INCLUDE culvertd.for:3836 */
/*     COMMOM BLOCK FOR THE DESCRIPTION OF THE FLOW OVER AN EMBANKMENT */
/* SOURCE embcom.cmn:3 */
/*<       character*8surf(pmxoff) >*/
/* SOURCE embcom.cmn:5 */
/*<       integernoff,minloc,plcwtb,glcwtb,phcwtb,ghcwtb,psubtb,gsubtb >*/
/* SOURCE embcom.cmn:8 */
/*<       realmincrs,rmffac >*/
/* SOURCE embcom.cmn:10 */
/*<        >*/
/* SOURCE embcom.cmn:20 */
/*<       common/embcmc/surf >*/
/* SOURCE embcom.cmn:22 */
/*<        >*/
/* INCLUDE culvertd.for:3837 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertd.for:3838 */
/*     Common block for key values describing the nature of weir */
/*     flow. */
/* SOURCE embwrq.cmn:4 */
/*<       integerhlflag,hpflag >*/
/* SOURCE embwrq.cmn:6 */
/*<       realhlcrit,hlmax >*/
/* SOURCE embwrq.cmn:8 */
/*<       common/embq/hlflag,hpflag,hlcrit,hlmax >*/
/* SOURCE embwrq.cmn:10 */
/*<       save/embq/ >*/
/*     HLCRIT  Ratio of piezometric head to crest breadth at boundary */
/*             between low head and high head flow in the USGS */
/*             embankment-shaped weir methodology. */
/*     HLMAX   Maximum value of piezometric head to crest breadth ratio */
/*             above which a warning message is issued. */
/*     HLFLAG  Warning message suppression flag for warnings about the */
/*             piezometric head to crest breadth ratio becoming greater */
/*             than HLMAX */
/*     HPFLAG  Warning message suppression flag for invalid weir flow */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertd.for:3841 */
/*<       realhrdfd,hrdfu,zt >*/
/* SOURCE culvertd.for:3842 */
/*<       real*8fd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertd.for:3845 */
/*<       externalembsub,frfemb >*/
/* *********************************************************************** */
/* SOURCE culvertd.for:3847 */
/*<       if(z.gt.mincrs)then >*/
    if (*feq_gen_z_d_ > embcom_1.mincrs) {
/*       THERE IS FLOW OVER THE ROADWAY. FIND ITS FREE FLOW VALUE AND */
/*       THE DOWNSTREAM ELEVATION AT THE FREE FLOW BOUNDARY */
/*       Remember that FRFEMB was called.  This means that */
/*       road flow values must be reestablished. */
/*       FIND THE HEAD ON THE ROADWAY */
/* SOURCE culvertd.for:3856 */
/*<       hrdfu=z-mincrs >*/
	hrdfu = static_cast<double>(*feq_gen_z_d_) - embcom_1.mincrs;
/* SOURCE culvertd.for:3858 */
/*<        >*/
	frfemb_(&hrdfu, &embcom_1.mincrs, &embcom_1.plcwtb, &embcom_1.glcwtb, 
		&embcom_1.phcwtb, &embcom_1.ghcwtb, &embcom_1.noff, 
		embcom_1.off, embcom_1.crest, embcom_1.width, embcom_1.approc,
		 embcmc_1.surf, &embcom_1.rmffac, &embq_1.hlcrit, &
		embq_1.hlmax, &embq_1.hlflag, &embq_1.hpflag, &zt, 
		embcom_1.xrdfl, embcom_1.xrdfr, embcom_1.hrdfl, 
		embcom_1.hrdfm, embcom_1.hrdfr, embcom_1.qrdfl, 
		embcom_1.qrdfm, embcom_1.qrdfr, embcom_1.tothl, 
		embcom_1.tothm, embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, 
		embcom_1.yfr, embcom_1.appl, embcom_1.appm, embcom_1.appr, 
		embcom_1.wl, embcom_1.wm, embcom_1.wr, embcom_1.aell, 
		embcom_1.aelm, embcom_1.aelr, &rdfcom_1.wfrdf, &
		rdfcom_1.mfrdf, &rdfcom_1.efrdf, (ftnlen)8);
/* SOURCE culvertd.for:3867 */
/*<        >*/
	embsub_(&embcom_1.minloc, &embcom_1.mincrs, &embcom_1.noff, 
		embcmc_1.surf, embcom_1.tothl, embcom_1.tothr, &hrdfu, &hrdfd,
		 &fd, zsbrdf, (ftnlen)8);
/* SOURCE culvertd.for:3870 */
/*<       fdrdw=fd >*/
	*fdrdw = fd;
/*       ZSBRDF GIVES THE TAILWATER ELEVATION WHICH MUST BE */
/*       REACHED FOR SUBMERGENCE OF THE FLOW OVER THE ROADWAY TO OCCUR. */
/* SOURCE culvertd.for:3874 */
/*<       else >*/
    } else {
/* SOURCE culvertd.for:3875 */
/*<       hrdfu=0.0 >*/
	hrdfu = (float)0.;
/* SOURCE culvertd.for:3876 */
/*<       wfrdf=0.0 >*/
	rdfcom_1.wfrdf = (float)0.;
/* SOURCE culvertd.for:3877 */
/*<       mfrdf=0.0 >*/
	rdfcom_1.mfrdf = (float)0.;
/* SOURCE culvertd.for:3878 */
/*<       efrdf=0.0 >*/
	rdfcom_1.efrdf = (float)0.;
/* SOURCE culvertd.for:3879 */
/*<       zsbrdf=mincrs >*/
	*zsbrdf = embcom_1.mincrs;
/* SOURCE culvertd.for:3880 */
/*<       fdrdw=0.0 >*/
	*fdrdw = (float)0.;
/* SOURCE culvertd.for:3881 */
/*<       endif >*/
    }
/* SOURCE culvertd.for:3883 */
/*<       return >*/
    return 0;
/* SOURCE culvertd.for:3884 */
/*<       end >*/
} /* getfrf_ */

#ifdef __cplusplus
	}
#endif
