#include <cmath>
extern "C" void feq_interpolate_critical_flow_interval(int,int,float,float*);
extern "C" void feq_interpolate_energy_section_interval(int,int,int,int,float,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*);
extern "C" void feq_interpolate_section_interval(int,int,int,float,float*,float*,float*,float*,float*,float*,float*);
extern "C" void feq_interpolate_section_interval_moment(int,int,int,float,float*,float*,float*,float*,float*,float*,float*,float*);
extern "C" void feq_interpolate_function_interval(int,int,int,float,float*,float*);
/* brnmat.f -- translated by f2c (version 20240504).
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

/* COMMON tsfcom_ is declared in common.hpp. */

#define tsfcom_1 tsfcom_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON dssdif_ is declared in common.hpp. */

#define dssdif_1 dssdif_

/* COMMON dssdifc_ is declared in common.hpp. */

#define dssdifc_1 dssdifc_

/* COMMON tamcom_ is declared in common.hpp. */

#define tamcom_1 tamcom_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON difcom_ is declared in common.hpp. */

#define difcom_1 difcom_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON wincom_ is declared in common.hpp. */

#define wincom_1 wincom_

/* COMMON ts_mngt_n__ is declared in common.hpp. */

#define feq_gen_ts_mngt_n_d_1 feq_gen_ts_mngt_n_d_

/* COMMON ts_mngt_c__ is declared in common.hpp. */

#define feq_gen_ts_mngt_c_d_1 feq_gen_ts_mngt_c_d_

/* COMMON miscon_ is declared in common.hpp. */

#define miscon_1 miscon_

/* COMMON irrig_ is declared in common.hpp. */

#define irrig_1 irrig_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* COMMON bnpond_ is declared in common.hpp. */

#define bnpond_1 bnpond_

/* COMMON gravcm_ is declared in common.hpp. */

#define gravcm_1 gravcm_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_0 = 0;
static real c_b107 = (float)1.;
static integer feq_gen_c_d_43 = 43;
static integer feq_gen_c_d_13 = 13;
static integer feq_gen_c_d_6 = 6;

/* Routines used in creating the network matrix entries for the branch nodes. */





/* SOURCE brnmat.for:7 */
/*<        >*/
/* Subroutine */ int insnod_(integer *stdout, integer *addnod, integer *mnbn, 
	integer *first, integer *last, integer *feq_storage_nsec, real *feq_storage_xvec, real *feq_storage_zvec, 
	real *feq_storage_ka, real *feq_storage_kd, integer *feq_storage_hltab, real *feq_storage_uvx, real *feq_storage_uvy, real *
	feq_storage_coefin, real *feq_storage_ycut, real *feq_storage_stdfld, real *feq_storage_kadjvec, char *feq_storage_bnodid, 
	integer *nbn, ftnlen bnodid_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:182 No space to add nodes.  Increas\
e MNBN in \002,\002ARSIZE.PRM and recompile.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, k, je, js, xtab;
    real katmp, kdtmp;
    integer numadd, newnum;
    real ycuttp, uvxtmp, uvytmp;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__4 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Add one or more nodes per element input by the user.  An */
/*     element with a head loss or drag force table will not have any */
/*     nodes added because we do not know which of the new elements */
/*     should receive the table.  Also the values of KA, KD, UVX, UVY, */
/*     and YCUT will be transfered unchanged to the new elements. */
/*     The stations, Bottom profile, and STDFLD will be interpolated */
/*     in the standard manner.  This routine changes the various */
/*     vectors as if the additional nodes had been input by the user. */
/*     The interpolations are done with pre-existing code in BRIN. */
/* SOURCE brnmat.for:25 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE brnmat.for:27 */
/*<       integeraddnod,first,last,mnbn,nbn,stdout >*/
/* SOURCE brnmat.for:28 */
/*<       integerhltab(mnbn),nsec(mnbn) >*/
/* SOURCE brnmat.for:29 */
/*<        >*/
/* SOURCE brnmat.for:32 */
/*<       characterbnodid(mnbn)*16 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     ADDNOD - the number of nodes to be added to each element in the */
/*               branch for all elements that can be subdivided. */
/*     MNBN   - maximum number of branch nodes */
/*     FIRST  - address of the first node on a branch */
/*     LAST   - address of last node on a branch */
/*     NSEC   - number and also address of cross section table at a node */
/*               on a branch */
/*     XVEC   - station values for each node on a branch */
/*     ZVEC   - bottom profile elevations for nodes on a branch */
/*     KA     - velocity head factor for contraction loss */
/*     KD     - velocity head factor for expansions loss */
/*     HLTAB  - addresses of point loss tables.  0 if none present */
/*     UVX    - sine of azimuth angle for each element. */
/*     UVY    - cosine of azimuth angle for each element */
/*     COEFIN - effective discharge coefficient for storm sewer inflow */
/*     YCUT   - distance from invert of storm sewer to ground surface */
/*     STDFLD - standard flood elevation */
/*     KADJVEC _ adjustment factor on conveyance */
/*     BNODID - branch-node identification string */
/*     NBN    - total number on nodes on branches in the model */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:58 */
/*<       integeri,j,je,js,k,newnum,numadd,xtab >*/
/* SOURCE brnmat.for:59 */
/*<       realkatmp,kdtmp,uvxtmp,uvytmp,ycuttp >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE brnmat.for:62 */
/*<    50  >*/
/* *********************************************************************** */
/*     COMPUTE THE NUMBER OF NODES THAT WILL BE ADDED TO THE BRANCH */
/* SOURCE brnmat.for:67 */
/*<       numadd=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> bnodid(feq_storage_bnodid, 16);

    feq::IndexedPointer<real> kadjvec(feq_storage_kadjvec, 1);

    feq::IndexedPointer<real> stdfld(feq_storage_stdfld, 1);

    feq::IndexedPointer<real> ycut(feq_storage_ycut, 1);

    feq::IndexedPointer<real> coefin(feq_storage_coefin, 1);

    feq::IndexedPointer<real> uvy(feq_storage_uvy, 1);

    feq::IndexedPointer<real> uvx(feq_storage_uvx, 1);

    feq::IndexedPointer<integer> hltab(feq_storage_hltab, 1);

    feq::IndexedPointer<real> kd(feq_storage_kd, 1);

    feq::IndexedPointer<real> ka(feq_storage_ka, 1);

    feq::IndexedPointer<real> zvec(feq_storage_zvec, 1);

    feq::IndexedPointer<real> xvec(feq_storage_xvec, 1);

    feq::IndexedPointer<integer> nsec(feq_storage_nsec, 1);

    /* Function Body */
/* L50: */
    numadd = 0;
/* SOURCE brnmat.for:68 */
/*<       do100i=first+1,last >*/
    feq_gen_i_d_1 = *last;
    for (feq_gen_i_d_ = *first + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:69 */
/*<       if(hltab(i).eq.0)then >*/
	if (hltab[feq_gen_i_d_] == 0) {
/* SOURCE brnmat.for:70 */
/*<       numadd=numadd+addnod >*/
	    numadd += *addnod;
/* SOURCE brnmat.for:72 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:73 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE brnmat.for:75 */
/*<       newnum=last-first+1+numadd >*/
    newnum = *last - *first + 1 + numadd;
/* SOURCE brnmat.for:77 */
/*<       if(last+newnum.gt.mnbn)then >*/
    if (*last + newnum > *mnbn) {
/* SOURCE brnmat.for:78 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__4.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__4);
	e_wsfe();
/* SOURCE brnmat.for:79 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE brnmat.for:80 */
/*<       endif >*/
    }
/*     TRANSFER THE FIRST NODE TO THE WORK SPACE. COMPUTE THE STARTING AND */
/*     ENDING LOCATIONS IN THE WORKSPACE AT THE END OF THE VECTORS. */
/* SOURCE brnmat.for:85 */
/*<       js=mnbn-newnum+1 >*/
    js = *mnbn - newnum + 1;
/* SOURCE brnmat.for:86 */
/*<       j=js >*/
    j = js;
/* SOURCE brnmat.for:87 */
/*<       je=mnbn >*/
    je = *mnbn;
/* SOURCE brnmat.for:89 */
/*<       nsec(j)=nsec(first) >*/
    nsec[j] = nsec[*first];
/* SOURCE brnmat.for:90 */
/*<       xvec(j)=xvec(first) >*/
    xvec[j] = xvec[*first];
/* SOURCE brnmat.for:91 */
/*<       zvec(j)=zvec(first) >*/
    zvec[j] = zvec[*first];
/* SOURCE brnmat.for:92 */
/*<       ka(j)=ka(first) >*/
    ka[j] = ka[*first];
/* SOURCE brnmat.for:93 */
/*<       kd(j)=kd(first) >*/
    kd[j] = kd[*first];
/* SOURCE brnmat.for:94 */
/*<       hltab(j)=hltab(first) >*/
    hltab[j] = hltab[*first];
/* SOURCE brnmat.for:95 */
/*<       uvx(j)=uvx(first) >*/
    uvx[j] = uvx[*first];
/* SOURCE brnmat.for:96 */
/*<       uvy(j)=uvy(first) >*/
    uvy[j] = uvy[*first];
/* SOURCE brnmat.for:97 */
/*<       coefin(j)=coefin(first) >*/
    coefin[j] = coefin[*first];
/* SOURCE brnmat.for:98 */
/*<       ycut(j)=ycut(first) >*/
    ycut[j] = ycut[*first];
/* SOURCE brnmat.for:99 */
/*<       stdfld(j)=stdfld(first) >*/
    stdfld[j] = stdfld[*first];
/* SOURCE brnmat.for:100 */
/*<       kadjvec(j)=kadjvec(first) >*/
    kadjvec[j] = kadjvec[*first];
/* SOURCE brnmat.for:101 */
/*<       bnodid(j)=bnodid(first) >*/
    s_copy(bnodid + (j << 4), bnodid + (*first << 4), (ftnlen)16, (ftnlen)16);
/* SOURCE brnmat.for:103 */
/*<       j=j+1 >*/
    ++j;
/* SOURCE brnmat.for:105 */
/*<       do200i=first+1,last >*/
    feq_gen_i_d_1 = *last;
    for (feq_gen_i_d_ = *first + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:107 */
/*<       if(hltab(i).eq.0)then >*/
	if (hltab[feq_gen_i_d_] == 0) {
/*         ADD NODES TO THE ELEMENT. */
/* SOURCE brnmat.for:110 */
/*<       if(nsec(i-1).eq.nsec(i))then >*/
	    if (nsec[feq_gen_i_d_ - 1] == nsec[feq_gen_i_d_]) {
/*           USE THE SAME TABLE NUMBER.  IT WILL BE CORRECT IN ALL */
/*           CASES */
/* SOURCE brnmat.for:113 */
/*<       xtab=nsec(i) >*/
		xtab = nsec[feq_gen_i_d_];
/* SOURCE brnmat.for:114 */
/*<       else >*/
	    } else {
/*           FORCE AN INTERPOLATED TABLE */
/* SOURCE brnmat.for:116 */
/*<       xtab=-1000000 >*/
		xtab = -1000000;
/* SOURCE brnmat.for:117 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:119 */
/*<       katmp=ka(i) >*/
	    katmp = ka[feq_gen_i_d_];
/* SOURCE brnmat.for:120 */
/*<       kdtmp=kd(i) >*/
	    kdtmp = kd[feq_gen_i_d_];
/* SOURCE brnmat.for:121 */
/*<       uvxtmp=uvx(i) >*/
	    uvxtmp = uvx[feq_gen_i_d_];
/* SOURCE brnmat.for:122 */
/*<       uvytmp=uvy(i) >*/
	    uvytmp = uvy[feq_gen_i_d_];
/* SOURCE brnmat.for:123 */
/*<       ycuttp=ycut(i) >*/
	    ycuttp = ycut[feq_gen_i_d_];
/* SOURCE brnmat.for:124 */
/*<       do120k=1,addnod >*/
	    feq_gen_i_d_2 = *addnod;
	    for (k = 1; k <= feq_gen_i_d_2; ++k) {
/* SOURCE brnmat.for:126 */
/*<       nsec(j)=xtab >*/
		nsec[j] = xtab;
/* SOURCE brnmat.for:127 */
/*<       xvec(j)=-1.e30 >*/
		xvec[j] = (float)-1e30;
/* SOURCE brnmat.for:128 */
/*<       zvec(j)=-1.e30 >*/
		zvec[j] = (float)-1e30;
/* SOURCE brnmat.for:129 */
/*<       ka(j)=katmp >*/
		ka[j] = katmp;
/* SOURCE brnmat.for:130 */
/*<       kd(j)=kdtmp >*/
		kd[j] = kdtmp;
/* SOURCE brnmat.for:131 */
/*<       hltab(j)=0 >*/
		hltab[j] = 0;
/* SOURCE brnmat.for:132 */
/*<       uvx(j)=uvxtmp >*/
		uvx[j] = uvxtmp;
/* SOURCE brnmat.for:133 */
/*<       uvy(j)=uvytmp >*/
		uvy[j] = uvytmp;
/* SOURCE brnmat.for:134 */
/*<       coefin(j)=0.0 >*/
		coefin[j] = (float)0.;
/* SOURCE brnmat.for:135 */
/*<       ycut(j)=ycuttp >*/
		ycut[j] = ycuttp;
/* SOURCE brnmat.for:136 */
/*<       stdfld(j)=0.0 >*/
		stdfld[j] = (float)0.;
/* SOURCE brnmat.for:137 */
/*<       kadjvec(j)=0.0 >*/
		kadjvec[j] = (float)0.;
/* SOURCE brnmat.for:138 */
/*<       bnodid(j)=' ' >*/
		s_copy(bnodid + (j << 4), const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE brnmat.for:139 */
/*<       j=j+1 >*/
		++j;
/* SOURCE brnmat.for:140 */
/*<   120 continue >*/
/* L120: */
	    }
/* SOURCE brnmat.for:142 */
/*<       endif >*/
	}
/*       NOW TRANSFER THE NEXT IN LINE USER VALUE TO THE WORK SPACE */
/* SOURCE brnmat.for:146 */
/*<       nsec(j)=nsec(i) >*/
	nsec[j] = nsec[feq_gen_i_d_];
/* SOURCE brnmat.for:147 */
/*<       xvec(j)=xvec(i) >*/
	xvec[j] = xvec[feq_gen_i_d_];
/* SOURCE brnmat.for:148 */
/*<       zvec(j)=zvec(i) >*/
	zvec[j] = zvec[feq_gen_i_d_];
/* SOURCE brnmat.for:149 */
/*<       ka(j)=ka(i) >*/
	ka[j] = ka[feq_gen_i_d_];
/* SOURCE brnmat.for:150 */
/*<       kd(j)=kd(i) >*/
	kd[j] = kd[feq_gen_i_d_];
/* SOURCE brnmat.for:151 */
/*<       hltab(j)=hltab(i) >*/
	hltab[j] = hltab[feq_gen_i_d_];
/* SOURCE brnmat.for:152 */
/*<       uvx(j)=uvx(i) >*/
	uvx[j] = uvx[feq_gen_i_d_];
/* SOURCE brnmat.for:153 */
/*<       uvy(j)=uvy(i) >*/
	uvy[j] = uvy[feq_gen_i_d_];
/* SOURCE brnmat.for:154 */
/*<       coefin(j)=coefin(i) >*/
	coefin[j] = coefin[feq_gen_i_d_];
/* SOURCE brnmat.for:155 */
/*<       ycut(j)=ycut(i) >*/
	ycut[j] = ycut[feq_gen_i_d_];
/* SOURCE brnmat.for:156 */
/*<       stdfld(j)=stdfld(i) >*/
	stdfld[j] = stdfld[feq_gen_i_d_];
/* SOURCE brnmat.for:157 */
/*<       kadjvec(j)=kadjvec(i) >*/
	kadjvec[j] = kadjvec[feq_gen_i_d_];
/* SOURCE brnmat.for:158 */
/*<       bnodid(j)=bnodid(i) >*/
	s_copy(bnodid + (j << 4), bnodid + (feq_gen_i_d_ << 4), (ftnlen)16, (ftnlen)16)
		;
/* SOURCE brnmat.for:159 */
/*<       j=j+1 >*/
	++j;
/* SOURCE brnmat.for:160 */
/*<   200 continue >*/
/* L200: */
    }
/*     NOW MOVE THE EXPANDED BRANCH DESCRIPTION BACK TO FIRST. ADJUST */
/*     NBN AND LAST TO REFLECT THE CHANGE IN SIZE. */
/* SOURCE brnmat.for:166 */
/*<       i=first >*/
    feq_gen_i_d_ = *first;
/* SOURCE brnmat.for:167 */
/*<       do300j=js,je >*/
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:169 */
/*<       nsec(i)=nsec(j) >*/
	nsec[feq_gen_i_d_] = nsec[j];
/* SOURCE brnmat.for:170 */
/*<       xvec(i)=xvec(j) >*/
	xvec[feq_gen_i_d_] = xvec[j];
/* SOURCE brnmat.for:171 */
/*<       zvec(i)=zvec(j) >*/
	zvec[feq_gen_i_d_] = zvec[j];
/* SOURCE brnmat.for:172 */
/*<       ka(i)=ka(j) >*/
	ka[feq_gen_i_d_] = ka[j];
/* SOURCE brnmat.for:173 */
/*<       kd(i)=kd(j) >*/
	kd[feq_gen_i_d_] = kd[j];
/* SOURCE brnmat.for:174 */
/*<       hltab(i)=hltab(j) >*/
	hltab[feq_gen_i_d_] = hltab[j];
/* SOURCE brnmat.for:175 */
/*<       uvx(i)=uvx(j) >*/
	uvx[feq_gen_i_d_] = uvx[j];
/* SOURCE brnmat.for:176 */
/*<       uvy(i)=uvy(j) >*/
	uvy[feq_gen_i_d_] = uvy[j];
/* SOURCE brnmat.for:177 */
/*<       coefin(i)=coefin(j) >*/
	coefin[feq_gen_i_d_] = coefin[j];
/* SOURCE brnmat.for:178 */
/*<       ycut(i)=ycut(j) >*/
	ycut[feq_gen_i_d_] = ycut[j];
/* SOURCE brnmat.for:179 */
/*<       stdfld(i)=stdfld(j) >*/
	stdfld[feq_gen_i_d_] = stdfld[j];
/* SOURCE brnmat.for:180 */
/*<       kadjvec(i)=kadjvec(j) >*/
	kadjvec[feq_gen_i_d_] = kadjvec[j];
/* SOURCE brnmat.for:181 */
/*<       bnodid(i)=bnodid(j) >*/
	s_copy(bnodid + (feq_gen_i_d_ << 4), bnodid + (j << 4), (ftnlen)16, (ftnlen)16)
		;
/* SOURCE brnmat.for:182 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE brnmat.for:183 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE brnmat.for:185 */
/*<       i=i-1 >*/
    --feq_gen_i_d_;
/* SOURCE brnmat.for:186 */
/*<       nbn=i >*/
    *nbn = feq_gen_i_d_;
/* SOURCE brnmat.for:187 */
/*<       last=i >*/
    *last = feq_gen_i_d_;
/* SOURCE brnmat.for:189 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:190 */
/*<       end >*/
} /* insnod_ */




/* SOURCE brnmat.for:194 */
/*<       subroutinelktsf(stdout,jltime,dt,clsr,wyr) >*/
/* Subroutine */ int lktsf_(integer *stdout, doublereal *jltime, doublereal *
	dt, doublereal *feq_storage_clsr, integer *wyr)
{
    /* Initialized data */

    static doublereal teps = 1e-6;

    /* Format strings */
    static char fmt_54[] = "(\002 *BUG:37* JTIME= 0 IN DTSF IN LKTSF. LOOKUP\
 JTIME=\002,1pd20.12,/,10x,\002 RUN JTIME=\002,1pd20.12,\002 RUN EJTIME=\002\
,1pd20.12)";
    static char fmt_60[] = "(/,\002 *BUG:XXX Need to backspace diffuse file \
system.\002,/,11x,\002Probable cause is diffuse buffer that is too small.\
\002)";
    static char fmt_61[] = "(\002 Above message issued while searching buffe\
r for HECDSS\002,\002 access in LKTSF.\002)";
    static char fmt_62[] = "(/,\002 *BUG:XXX* Times do not match for runoff \
in \002,\002LKTSF.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_rdue(cilist *), do_uio(integer *, char *, ftnlen), e_rdue(), 
	    s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_hecdss_block_d_(integer *, char *, integer 
	    *, integer *, char *, doublereal *, integer *, integer *, 
	    doublereal *, real *, integer *, ftnlen, ftnlen);
    integer feq_gen_i_d_, j;
    doublereal p;
    integer ll;
    doublereal ri[128];
    integer lr, lt, lm1, lp1;
    doublereal dyf;
    integer got, knt, mnt, dyt, yrt, ltm1, need;
    real rate;
    extern integer iwyr_(integer *, integer *);
    real ratel;
    doublereal tsfdt;
    integer lstop;
    doublereal jtbase;
    real runoff[128];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__17 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find values of cumulative land surface runoff and the water */
/*     year corresponding to JLTIME. */
/* SOURCE brnmat.for:202 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE brnmat.for:204 */
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
/* SOURCE brnmat.for:207 */
/*<       integerstdout,wyr >*/
/* SOURCE brnmat.for:208 */
/*<       real*8clsr(mndifa) >*/
/* SOURCE brnmat.for:209 */
/*<       real*8jltime,dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     JLTIME - modified julian time for land surface runoff value */
/*     CLSR   - values of cumulative land surface runoff found */
/*     WYR    - current water year */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE brnmat.for:218 */
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
/* INCLUDE brnmat.for:219 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:220 */
/* *********************************************************************** */
/* SOURCE dssdif.cmn:2 */
/*<        >*/
/* SOURCE dssdif.cmn:5 */
/*<       common/dssdifc/path_name_diff >*/
/* SOURCE dssdif.cmn:7 */
/*<       character*80path_name_diff(mndifa) >*/
/* SOURCE dssdif.cmn:9 */
/*<       integerdss_index_diff(mxn_ts),time_step_diff(mxn_ts) >*/
/* SOURCE dssdif.cmn:12 */
/*<       realtmpvec(mndbuf+1) >*/
/* SOURCE dssdif.cmn:14 */
/*<       doubleprecisionjtvec(mndbuf+1),tsfdt_dss,half_tsfdt_dss,buf_dt >*/
/* *********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:223 */
/*<       integerdyt,i,j,knt,ll,lm1,lp1,lr,lstop,lt,ltm1,mnt,yrt,need,got >*/
/* SOURCE brnmat.for:225 */
/*<       realrate,ratel,runoff(mndifa) >*/
/* SOURCE brnmat.for:226 */
/*<       real*8dyf,p,ri(mndifa),jtbase,teps,tsfdt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE brnmat.for:229 */
/*<       integeriwyr >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE brnmat.for:232 */
/*<       externaliwyr >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE brnmat.for:234 */
/*<       datateps/1.d-6/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> clsr(feq_storage_clsr, 1);

    /* Function Body */
/* SOURCE brnmat.for:236 */
/*<    54  >*/
/* L54: */
/* SOURCE brnmat.for:239 */
/*<    60  >*/
/* L60: */
/* SOURCE brnmat.for:241 */
/*<    61  >*/
/* L61: */
/* SOURCE brnmat.for:243 */
/*<    62 format(/,' *BUG:XXX* Times do not match for runoff in ','LKTSF.') >*/
/* L62: */
/* *********************************************************************** */
/* SOURCE brnmat.for:246 */
/*<       if(jltime.ge.bjtime(lentry))then >*/
    if (*jltime >= tsfcom_1.bjtime[(524288 + (0 + (tsfcom_1.lentry - 1 << 3)) 
	    - 524288) / 8]) {
/*       SEARCH BUFFER CLOCKWISE */
/* SOURCE brnmat.for:248 */
/*<   100 continue >*/
L100:
/* SOURCE brnmat.for:249 */
/*<       lp1=lentry+1 >*/
	lp1 = tsfcom_1.lentry + 1;
/* SOURCE brnmat.for:250 */
/*<       if(lp1.gt.nbuff)lp1=1 >*/
	if (lp1 > tsfcom_1.nbuff) {
	    lp1 = 1;
	}
/* SOURCE brnmat.for:251 */
/*<       if(lp1.eq.lhead)then >*/
	if (lp1 == tsfcom_1.lhead) {
/*           MOVED BEYOND END OF BUFFER-READ NEW RECORD INTO LIST */
/*           HEAD LOCATION. NOTE: LIST HEAD WILL POINT TO OLDEST */
/*           RECORD IN THE BUFFER. */
/* SOURCE brnmat.for:256 */
/*<       if(time_step_diff(1).lt.0)then >*/
	    if (dssdif_1.feq_gen_time_step_diff_d_[0] < 0) {
/* SOURCE brnmat.for:257 */
/*<        >*/
		feq_gen_io_d__17.ciunit = tsfcom_1.tsfdsn;
		feq_gen_io_d__17.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
		s_rdue(&feq_gen_io_d__17);
		do_uio(&feq_gen_c_d_1, (char *)&tsfcom_1.bjtime[tsfcom_1.lhead - 1], (
			ftnlen)sizeof(doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&dyf, (ftnlen)sizeof(doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&yrt, (ftnlen)sizeof(integer));
		do_uio(&feq_gen_c_d_1, (char *)&mnt, (ftnlen)sizeof(integer));
		do_uio(&feq_gen_c_d_1, (char *)&dyt, (ftnlen)sizeof(integer));
		feq_gen_i_d_1 = tsfcom_1.ndfval;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
		    do_uio(&feq_gen_c_d_1, (char *)&runoff[j - 1], (ftnlen)sizeof(real)
			    );
		}
		e_rdue();
/* SOURCE brnmat.for:259 */
/*<       dtsf_rec=dtsf_rec+1 >*/
		++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE brnmat.for:260 */
/*<       do106j=1,ndfval >*/
		feq_gen_i_d_1 = tsfcom_1.ndfval;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:261 */
/*<       ri(j)=runoff(j) >*/
		    ri[j - 1] = runoff[j - 1];
/* SOURCE brnmat.for:262 */
/*<   106 continue >*/
/* L106: */
		}
/* SOURCE brnmat.for:264 */
/*<       if(bjtime(lhead).eq.0.d0)then >*/
		if (tsfcom_1.bjtime[tsfcom_1.lhead - 1] == 0.) {
/* SOURCE brnmat.for:265 */
/*<       write(stdout,54)jltime,jtime,ejtime >*/
		    feq_gen_io_d__25.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__25);
		    do_fio(&feq_gen_c_d_1, (char *)&(*jltime), (ftnlen)sizeof(
			    doublereal));
		    do_fio(&feq_gen_c_d_1, (char *)&julian_1.jtime, (ftnlen)sizeof(
			    doublereal));
		    do_fio(&feq_gen_c_d_1, (char *)&julian_1.ejtime, (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
/* SOURCE brnmat.for:266 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE brnmat.for:267 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:269 */
/*<       bwyr(lhead)=iwyr(yrt,mnt) >*/
		tsfcom_1.bwyr[tsfcom_1.lhead - 1] = iwyr_(&yrt, &mnt);
/*             COMPUTE CUMULATIVE FORM IN THE BUFFER */
/*             LENTRY IS THE LAST UP-TO-DATE VALUE HERE. */
/* SOURCE brnmat.for:274 */
/*<       tsfdt=86400.e0*(bjtime(lhead)-bjtime(lentry)) >*/
		tsfdt = (tsfcom_1.bjtime[tsfcom_1.lhead - 1] - 
			tsfcom_1.bjtime[tsfcom_1.lentry - 1]) * (float)86400.;
/* SOURCE brnmat.for:275 */
/*<       if(lagtsf.eq.0)then >*/
		if (tsfcom_1.lagtsf == 0) {
/* SOURCE brnmat.for:276 */
/*<       do150j=1,ndfval >*/
		    feq_gen_i_d_1 = tsfcom_1.ndfval;
		    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:277 */
/*<       tsfbuf(lhead,j)=tsfbuf(lentry,j)+tsfdt*ri(j) >*/
			tsfcom_1.tsfbuf[tsfcom_1.lhead + (j << 9) - 513] = 
				tsfcom_1.tsfbuf[tsfcom_1.lentry + (j << 9) - 
				513] + tsfdt * ri[j - 1];
/* SOURCE brnmat.for:278 */
/*<   150 continue >*/
/* L150: */
		    }
/* SOURCE brnmat.for:279 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:280 */
/*<       tsfdt=0.5*tsfdt >*/
		    tsfdt *= (float).5;
/* SOURCE brnmat.for:281 */
/*<       do160j=1,ndfval >*/
		    feq_gen_i_d_1 = tsfcom_1.ndfval;
		    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:282 */
/*<       tsfrat(lhead,j)=ri(j) >*/
			tsfcom_1.tsfrat[tsfcom_1.lhead + (j << 9) - 513] = ri[
				j - 1];
/* SOURCE brnmat.for:283 */
/*<       tsfbuf(lhead,j)=tsfbuf(lentry,j)+tsfdt*(ri(j)+tsfrat(lentry,j)) >*/
			tsfcom_1.tsfbuf[tsfcom_1.lhead + (j << 9) - 513] = 
				tsfcom_1.tsfbuf[tsfcom_1.lentry + (j << 9) - 
				513] + tsfdt * (ri[j - 1] + tsfcom_1.tsfrat[
				tsfcom_1.lentry + (j << 9) - 513]);
/* SOURCE brnmat.for:285 */
/*<   160 continue >*/
/* L160: */
		    }
/* SOURCE brnmat.for:286 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:288 */
/*<       lhead=lhead+1 >*/
		++tsfcom_1.lhead;
/* SOURCE brnmat.for:289 */
/*<       if(lhead.gt.nbuff)lhead=1 >*/
		if (tsfcom_1.lhead > tsfcom_1.nbuff) {
		    tsfcom_1.lhead = 1;
		}
/* SOURCE brnmat.for:290 */
/*<       else >*/
	    } else {
/*             Path name in HECDSS.  Find out how many */
/*             values need to be retained in the buffer so that */
/*             time step reductions due to convergence difficulties */
/*             do not require reading data already past. */
/* SOURCE brnmat.for:295 */
/*<       jtbase=jltime-dt/86400.d0-teps >*/
		jtbase = *jltime - *dt / 86400. - teps;
/*              WRITE(STDOUT,*) ' State of buffer before refresh' */
/*              CALL DUMP_DIFF_STATE(1, NBUFF, LHEAD, LENTRY) */
/* SOURCE brnmat.for:299 */
/*<       lt=lhead-1 >*/
		lt = tsfcom_1.lhead - 1;
/* SOURCE brnmat.for:300 */
/*<       if(lt.lt.1)lt=nbuff >*/
		if (lt < 1) {
		    lt = tsfcom_1.nbuff;
		}
/*             LT gives index to the last item placed in the buffer. */
/* SOURCE brnmat.for:302 */
/*<       knt=1 >*/
		knt = 1;
/* SOURCE brnmat.for:303 */
/*<   110 continue >*/
L110:
/* SOURCE brnmat.for:304 */
/*<       if(bjtime(lt).ge.jtbase)then >*/
		if (tsfcom_1.bjtime[lt - 1] >= jtbase) {
/*                 Continue searching backwards. */
/* SOURCE brnmat.for:306 */
/*<       lt=lt-1 >*/
		    --lt;
/* SOURCE brnmat.for:307 */
/*<       if(lt.lt.1)lt=nbuff >*/
		    if (lt < 1) {
			lt = tsfcom_1.nbuff;
		    }
/* SOURCE brnmat.for:308 */
/*<       if(lt.eq.lhead)then >*/
		    if (lt == tsfcom_1.lhead) {
/* SOURCE brnmat.for:309 */
/*<       write(stdout,60) >*/
			feq_gen_io_d__30.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__30);
			e_wsfe();
/* SOURCE brnmat.for:310 */
/*<       write(stdout,61) >*/
			feq_gen_io_d__31.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__31);
			e_wsfe();
/* SOURCE brnmat.for:311 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE brnmat.for:312 */
/*<       endif >*/
		    }
/* SOURCE brnmat.for:314 */
/*<       knt=knt+1 >*/
		    ++knt;
/* SOURCE brnmat.for:315 */
/*<       goto110 >*/
		    goto L110;
/* SOURCE brnmat.for:316 */
/*<       endif >*/
		}
/*             KNT  gives the number of values in the buffer that */
/*             must be retained. */
/* SOURCE brnmat.for:319 */
/*<       need=nbuff-knt >*/
		need = tsfcom_1.nbuff - knt;
/*              WRITE(STDOUT,*) ' LKTSF: KNT=',KNT,' NEED=', */
/*     A                     NEED */
/*             Set the desired julian time so that we do not */
/*             get a value twice.  Add .75 of the buffer time step */
/*             which is constant in time and space, to the julian time */
/*             of the last valid entry in the buffer.  This should */
/*             get the correct value for all valid HECDSS time steps. */
/* SOURCE brnmat.for:327 */
/*<       jtbase=bjtime(lentry)+buf_dt >*/
		jtbase = tsfcom_1.bjtime[tsfcom_1.lentry - 1] + 
			dssdif_1.feq_gen_buf_dt_d_;
/*             Get the data from the pathnames and transfer to the */
/*             columns of the diffuse buffer. */
/* SOURCE brnmat.for:332 */
/*<       do510j=1,nluse >*/
		feq_gen_i_d_1 = tsfcom_1.nluse;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:333 */
/*<        >*/
		    feq_gen_i_d_2 = tsfcom_1.nbuff + 1;
		    feq_gen_get_hecdss_block_d_(stdout, dssdifc_1.feq_gen_path_name_diff_d_ + (
			    j - 1) * 80, &dssdif_1.feq_gen_dss_index_diff_d_[j - 1], &
			    dssdif_1.feq_gen_time_step_diff_d_[j - 1], const_cast<char*>("PER-CUM "), &
			    jtbase, &need, &got, dssdif_1.jtvec, 
			    dssdif_1.tmpvec, &feq_gen_i_d_2, (ftnlen)80, (ftnlen)8);
/*               Transfer to the buffer. Slot at LHEAD is the start */
/*               point. */
/* SOURCE brnmat.for:339 */
/*<       lt=lhead >*/
		    lt = tsfcom_1.lhead;
/* SOURCE brnmat.for:340 */
/*<       if(j.eq.1)then >*/
		    if (j == 1) {
/*                 Transfer both the times and the values. */
/* SOURCE brnmat.for:342 */
/*<       do190i=1,got >*/
			feq_gen_i_d_2 = got;
			for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:343 */
/*<       tsfbuf(lt,j)=tmpvec(i) >*/
			    tsfcom_1.tsfbuf[lt + (j << 9) - 513] = 
				    dssdif_1.tmpvec[feq_gen_i_d_ - 1];
/* SOURCE brnmat.for:344 */
/*<       bjtime(lt)=jtvec(i) >*/
			    tsfcom_1.bjtime[lt - 1] = dssdif_1.jtvec[feq_gen_i_d_ - 1];
/* SOURCE brnmat.for:345 */
/*<       lt=lt+1 >*/
			    ++lt;
/* SOURCE brnmat.for:346 */
/*<       if(lt.gt.nbuff)lt=1 >*/
			    if (lt > tsfcom_1.nbuff) {
				lt = 1;
			    }
/* SOURCE brnmat.for:347 */
/*<   190 continue >*/
/* L190: */
			}
/* SOURCE brnmat.for:348 */
/*<       else >*/
		    } else {
/*                 Transfer the values and compare the times. */
/* SOURCE brnmat.for:350 */
/*<       do205i=1,got >*/
			feq_gen_i_d_2 = got;
			for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:351 */
/*<       tsfbuf(lt,j)=tmpvec(i) >*/
			    tsfcom_1.tsfbuf[lt + (j << 9) - 513] = 
				    dssdif_1.tmpvec[feq_gen_i_d_ - 1];
/* SOURCE brnmat.for:352 */
/*<       if(abs(bjtime(lt)-jtvec(i)).gt.1.d-5)then >*/
			    if ((feq_gen_d_d_1 = tsfcom_1.bjtime[lt - 1] - 
				    dssdif_1.jtvec[feq_gen_i_d_ - 1], abs(feq_gen_d_d_1)) > 
				    1e-5) {
/*                     Problem in time steps. */
/* SOURCE brnmat.for:354 */
/*<       write(stdout,62) >*/
				feq_gen_io_d__35.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__35);
				e_wsfe();
/* SOURCE brnmat.for:355 */
/*<       stop'Abnormal stop: errors found.' >*/
				s_stop(const_cast<char*>("Abnormal stop: errors found."), (
					ftnlen)28);
/* SOURCE brnmat.for:356 */
/*<       endif >*/
			    }
/* SOURCE brnmat.for:357 */
/*<       lt=lt+1 >*/
			    ++lt;
/* SOURCE brnmat.for:358 */
/*<       if(lt.gt.nbuff)lt=1 >*/
			    if (lt > tsfcom_1.nbuff) {
				lt = 1;
			    }
/* SOURCE brnmat.for:359 */
/*<   205 continue >*/
/* L205: */
			}
/* SOURCE brnmat.for:360 */
/*<       endif >*/
		    }
/* SOURCE brnmat.for:361 */
/*<   510 continue >*/
/* L510: */
		}
/* SOURCE brnmat.for:362 */
/*<       lhead=lt >*/
		tsfcom_1.lhead = lt;
/*             COMPUTE CUMULATIVE FORM IN THE BUFFER */
/*             LENTRY IS THE LAST UP-TO-DATE VALUE HERE. */
/* SOURCE brnmat.for:366 */
/*<       lstop=lhead-1 >*/
		lstop = tsfcom_1.lhead - 1;
/* SOURCE brnmat.for:367 */
/*<       if(lstop.lt.1)lstop=nbuff >*/
		if (lstop < 1) {
		    lstop = tsfcom_1.nbuff;
		}
/* SOURCE brnmat.for:368 */
/*<       ltm1=lentry >*/
		ltm1 = tsfcom_1.lentry;
/* SOURCE brnmat.for:369 */
/*<       lt=lentry+1 >*/
		lt = tsfcom_1.lentry + 1;
/* SOURCE brnmat.for:370 */
/*<       if(lt.gt.nbuff)lt=1 >*/
		if (lt > tsfcom_1.nbuff) {
		    lt = 1;
		}
/* SOURCE brnmat.for:372 */
/*<   520 continue >*/
L520:
/* SOURCE brnmat.for:373 */
/*<       if(lagtsf.eq.0)then >*/
		if (tsfcom_1.lagtsf == 0) {
/* SOURCE brnmat.for:374 */
/*<       do151j=1,nluse >*/
		    feq_gen_i_d_1 = tsfcom_1.nluse;
		    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:375 */
/*<       tsfbuf(lt,j)=tsfbuf(ltm1,j)+tsfdt_dss*tsfbuf(lt,j) >*/
			tsfcom_1.tsfbuf[lt + (j << 9) - 513] = 
				tsfcom_1.tsfbuf[ltm1 + (j << 9) - 513] + 
				dssdif_1.feq_gen_tsfdt_dss_d_ * tsfcom_1.tsfbuf[lt + (
				j << 9) - 513];
/* SOURCE brnmat.for:377 */
/*<   151 continue >*/
/* L151: */
		    }
/* SOURCE brnmat.for:378 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:379 */
/*<       do161j=1,ndfval >*/
		    feq_gen_i_d_1 = tsfcom_1.ndfval;
		    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:380 */
/*<       tsfrat(lt,j)=tsfbuf(lt,j) >*/
			tsfcom_1.tsfrat[lt + (j << 9) - 513] = 
				tsfcom_1.tsfbuf[lt + (j << 9) - 513];
/* SOURCE brnmat.for:381 */
/*<        >*/
			tsfcom_1.tsfbuf[lt + (j << 9) - 513] = 
				tsfcom_1.tsfbuf[ltm1 + (j << 9) - 513] + 
				dssdif_1.feq_gen_half_tsfdt_dss_d_ * (tsfcom_1.tsfbuf[
				lt + (j << 9) - 513] + tsfcom_1.tsfrat[ltm1 + 
				(j << 9) - 513]);
/* SOURCE brnmat.for:383 */
/*<   161 continue >*/
/* L161: */
		    }
/* SOURCE brnmat.for:384 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:385 */
/*<       if(lt.ne.lstop)then >*/
		if (lt != lstop) {
/* SOURCE brnmat.for:386 */
/*<       ltm1=ltm1+1 >*/
		    ++ltm1;
/* SOURCE brnmat.for:387 */
/*<       if(ltm1.gt.nbuff)ltm1=1 >*/
		    if (ltm1 > tsfcom_1.nbuff) {
			ltm1 = 1;
		    }
/* SOURCE brnmat.for:388 */
/*<       lt=lt+1 >*/
		    ++lt;
/* SOURCE brnmat.for:389 */
/*<       if(lt.gt.nbuff)lt=1 >*/
		    if (lt > tsfcom_1.nbuff) {
			lt = 1;
		    }
/* SOURCE brnmat.for:390 */
/*<       goto520 >*/
		    goto L520;
/* SOURCE brnmat.for:391 */
/*<       endif >*/
		}
/*              WRITE(STDOUT,*) ' State of buffer after refresh' */
/*              CALL DUMP_DIFF_STATE(1, NBUFF, LHEAD, LENTRY) */
/* SOURCE brnmat.for:397 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:398 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:399 */
/*<       if(jltime.le.bjtime(lp1))then >*/
	if (*jltime <= tsfcom_1.bjtime[lp1 - 1]) {
/*           FOUND THE INTERVAL-SET THE LEFT AND RIGHT TIME POINTERS */
/* SOURCE brnmat.for:401 */
/*<       ll=lentry >*/
	    ll = tsfcom_1.lentry;
/* SOURCE brnmat.for:402 */
/*<       lr=lp1 >*/
	    lr = lp1;
/* SOURCE brnmat.for:403 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE brnmat.for:404 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:405 */
/*<       lentry=lp1 >*/
	    tsfcom_1.lentry = lp1;
/* SOURCE brnmat.for:406 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE brnmat.for:407 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:408 */
/*<       else >*/
    } else {
/*         SEARCH COUNTER CLOCKWISE. PASSING THE LIST HEAD IS A */
/*         BUG BECAUSE IT SHOULD NOT HAPPEN. */
/* SOURCE brnmat.for:412 */
/*<   200 continue >*/
L200:
/* SOURCE brnmat.for:413 */
/*<       if(lentry.eq.lhead)then >*/
	if (tsfcom_1.lentry == tsfcom_1.lhead) {
/* SOURCE brnmat.for:414 */
/*<        >*/
	    feq_gen_io_d__40.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__40);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:34 SUBROUTINE LKTSF-PASSING LIST HEAD")
		    , (ftnlen)43);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" COUNTER CLOCKWISE. JTIME = "), (ftnlen)28);
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&(*jltime), (ftnlen)sizeof(
		    doublereal));
	    e_wsle();
/* SOURCE brnmat.for:417 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE brnmat.for:418 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:420 */
/*<       lm1=lentry-1 >*/
	lm1 = tsfcom_1.lentry - 1;
/* SOURCE brnmat.for:421 */
/*<       if(lm1.lt.1)lm1=nbuff >*/
	if (lm1 < 1) {
	    lm1 = tsfcom_1.nbuff;
	}
/* SOURCE brnmat.for:422 */
/*<       if(jltime.ge.bjtime(lm1))then >*/
	if (*jltime >= tsfcom_1.bjtime[lm1 - 1]) {
/*               FOUND INTERVAL */
/* SOURCE brnmat.for:424 */
/*<       ll=lm1 >*/
	    ll = lm1;
/* SOURCE brnmat.for:425 */
/*<       lr=lentry >*/
	    lr = tsfcom_1.lentry;
/* SOURCE brnmat.for:426 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE brnmat.for:427 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:428 */
/*<       lentry=lm1 >*/
	    tsfcom_1.lentry = lm1;
/* SOURCE brnmat.for:429 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE brnmat.for:430 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:431 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:433 */
/*<  1000 continue >*/
L1000:
/*     INTERPOLATE FOR THE VALUE */
/* SOURCE brnmat.for:436 */
/*<       tsfdt=jltime-bjtime(ll) >*/
    tsfdt = *jltime - tsfcom_1.bjtime[ll - 1];
/* SOURCE brnmat.for:437 */
/*<       p=tsfdt/(bjtime(lr)-bjtime(ll)) >*/
    p = tsfdt / (tsfcom_1.bjtime[lr - 1] - tsfcom_1.bjtime[ll - 1]);
/* SOURCE brnmat.for:438 */
/*<       wyr=bwyr(lr) >*/
    *wyr = tsfcom_1.bwyr[lr - 1];
/* SOURCE brnmat.for:440 */
/*<       if(lagtsf.eq.0)then >*/
    if (tsfcom_1.lagtsf == 0) {
/* SOURCE brnmat.for:441 */
/*<       do600j=1,ndfval >*/
	feq_gen_i_d_1 = tsfcom_1.ndfval;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:442 */
/*<       clsr(j)=tsfbuf(ll,j)+p*(tsfbuf(lr,j)-tsfbuf(ll,j)) >*/
	    clsr[j] = tsfcom_1.tsfbuf[ll + (j << 9) - 513] + p * (
		    tsfcom_1.tsfbuf[lr + (j << 9) - 513] - tsfcom_1.tsfbuf[ll 
		    + (j << 9) - 513]);
/* SOURCE brnmat.for:443 */
/*<   600 continue >*/
/* L600: */
	}
/* SOURCE brnmat.for:444 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:445 */
/*<       tsfdt=43200.d0*tsfdt >*/
	tsfdt *= 43200.;
/* SOURCE brnmat.for:446 */
/*<       do610j=1,ndfval >*/
	feq_gen_i_d_1 = tsfcom_1.ndfval;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:447 */
/*<       ratel=tsfrat(ll,j) >*/
	    ratel = tsfcom_1.tsfrat[ll + (j << 9) - 513];
/* SOURCE brnmat.for:448 */
/*<       rate=ratel+p*(tsfrat(lr,j)-ratel) >*/
	    rate = ratel + p * (static_cast<double>(tsfcom_1.tsfrat[lr + (j << 9) - 513]) - ratel);
/* SOURCE brnmat.for:449 */
/*<       clsr(j)=tsfbuf(ll,j)+tsfdt*(rate+ratel) >*/
	    clsr[j] = tsfcom_1.tsfbuf[ll + (j << 9) - 513] + tsfdt * (static_cast<double>(rate) + 
		    ratel);
/* SOURCE brnmat.for:450 */
/*<   610 continue >*/
/* L610: */
	}
/* SOURCE brnmat.for:451 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:453 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:455 */
/*<       end >*/
} /* lktsf_ */




/* SOURCE brnmat.for:459 */
/*<       subroutinerecompute_dlay_routing(dt) >*/
/* Subroutine */ int feq_gen_recompute_dlay_routing_d_(doublereal *dt)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    double exp(doublereal);

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal feq_gen_dt_over_k_d_;

/*     Recompute the coefficients for routing through the delay */
/*     reservoirs. */
/* SOURCE brnmat.for:464 */
/*<       implicitnone >*/
/* SOURCE brnmat.for:465 */
/*<       real*8dt >*/
/* INCLUDE brnmat.for:467 */
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
/* INCLUDE brnmat.for:468 */
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
/* SOURCE brnmat.for:472 */
/*<       integeri >*/
/* SOURCE brnmat.for:474 */
/*<       real*8dt_over_k >*/
/* *********************************************************************** */
/* SOURCE brnmat.for:477 */
/*<       do100i=1,dlay_knt >*/
    feq_gen_i_d_1 = tamcom_1.feq_gen_dlay_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:478 */
/*<       dt_over_k=dt/dlay_k(i) >*/
	feq_gen_dt_over_k_d_ = *dt / tamcom_1.feq_gen_dlay_k_d_[feq_gen_i_d_];
/* SOURCE brnmat.for:479 */
/*<       dlay_exp_of_dt_over_k(i)=exp(-dt_over_k) >*/
	tamcom_1.feq_gen_dlay_exp_of_dt_over_k_d_[feq_gen_i_d_ - 1] = exp(-feq_gen_dt_over_k_d_);
/* SOURCE brnmat.for:480 */
/*<       dlay_k_over_dt(i)=1.d0/dt_over_k >*/
	tamcom_1.feq_gen_dlay_k_over_dt_d_[feq_gen_i_d_ - 1] = 1. / feq_gen_dt_over_k_d_;
/* SOURCE brnmat.for:481 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE brnmat.for:482 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:483 */
/*<       end >*/
} /* recompute_dlay_routing__ */




/* SOURCE brnmat.for:487 */
/*<        >*/
/* Subroutine */ int load_(char *diffus, integer *feq_storage_brpt, integer *nbra, 
	integer *stdout, integer *lpnt, integer *mlpnt, integer *nbn, integer 
	*output, char *point, char *wind, integer *feq_storage_pfpnt, integer *qpn, 
	doublereal *dt, doublereal *dtdy, doublereal *dtload, doublereal *
	dtdyload, doublereal *djload, integer *feq_storage_emc, integer *eflag, integer *
	wyr, ftnlen diffus_len, ftnlen point_len, ftnlen wind_len)
{
    /* Initialized data */

    static char yes[4+1] = "YES ";
    static char no[4+1] = "NO  ";
    static doublereal feq_gen_past_dt_d_ = 0.;
    static doublereal feq_gen_dt_tolerance_d_ = 1e-7;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* Invalid CAT_CODE=\002,i5,\002 \
in sub. LOAD\002)";
    static char fmt_52[] = "(/,\002 DIFFUSE, POINT & WIND LOADINGS AT \002\
,\002JTIME \002,f16.4,/,1x,\002  ELEMENT  \002,\002   DISCHARGE  \002,\002  \
WIND SHEAR  \002)";
    static char fmt_54[] = "(4x,i5,2(2x,1pe12.5))";
    static char fmt_56[] = "(/,\002*ERR:161* Unable to set up vectors QPVE\
C, \002,\002 WSVEC or forced boundary in SUBROUTINE LOAD\002)";
    static char fmt_60[] = "(/,\002 *ERR:324* Detention reservoir failed to \
converge.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    doublereal feq_gen_d_d_1;
    static real equiv_2[1];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer feq_gen_cat_code_d_, feq_gen_dlay_pnt_d_, feq_gen_dten_pnt_d_, feq_gen_rout_tab_d_;
    real fraction, feq_gen_ts_value_d_;
    integer feq_gen_unit_pnt_d_, feq_gen_i_d_, j, k;
    doublereal feq_gen_dt_over_12_d_;
    integer feq_gen_triba_pnt_d_;
    real s1, s2, df;
    integer ke;
    real dq, ri[128];
    integer it, ks;
    real wx, wy, qq1, qq2, q1p, q2p, s2t, pdv, res;
    integer knt, pnt;
    doublereal sum;
    integer gage;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer ibra;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab, node, adrs;
    real elev;
    doublereal qbar;
#define idum (feq::BitView<integer>(equiv_2, sizeof(equiv_2)))
    doublereal qend;
    real temp;
#define rdum (equiv_2)
    doublereal suma;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer feq_gen_fraction_pnt_d_, fnode, lnode;
    real shear;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *), lktsf_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *), rdget_(integer *, integer *, doublereal 
	    *, doublereal *, real *);
    doublereal jtime1, fbtime;
    integer feq_gen_qp_pnt_d_;
    doublereal retime, feq_gen_half_dt_d_, dftime;
    extern /* Subroutine */ int wshear_(doublereal *, real *, real *, real *),
	     lktstab_(integer *, doublereal *, real *, integer *, real *), 
	    feq_gen_recompute_dlay_routing_d_(doublereal *);
    real feq_gen_number_of_ponds_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__95 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     Set up values in vectors QPVEC & WSVEC for current time step. */
/* SOURCE brnmat.for:497 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE brnmat.for:499 */
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
/* SOURCE brnmat.for:502 */
/*<       integereflag,stdout,lpnt,mlpnt,nbn,nbra,output,qpn,wyr >*/
/* SOURCE brnmat.for:504 */
/*<       integerbrpt(8,nbra),emc(mremc),pfpnt(3,mlpnt) >*/
/* SOURCE brnmat.for:505 */
/*<       real*8djload,dt,dtload,dtdy,dtdyload >*/
/* SOURCE brnmat.for:506 */
/*<       characterdiffus*4,point*4,wind*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DIFFUS - indicator if tributary area is present.  YES if so */
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
/*     NBRA   - number of branches in the model */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     LPNT   - length of the point load point load array */
/*     MLPNT  - maximum length of the point load pointer arrays */
/*     NBN    - total number on nodes on branches in the model */
/*     OUTPUT - output level for diagnostic work */
/*     POINT  - if YES then point inflows to a branch are present */
/*     WIND   - flag for presence of wind stress simulation */
/*     PFPNT  - point flow pointer array */
/*     QPN    - number of lateral inflows */
/*     DT     - time step in seconds */
/*     DTLOAD - special value of time step for frozen time */
/*     DJLOAD - time adjustment offset to prevent problems during frozen */
/*               time computations */
/*     DTIMLD - special value of time step for frozen time */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     WYR    - current water year */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE brnmat.for:540 */
/*     Parameter defintion for time-series management in FEQ */
/* SOURCE ts_mngt.prm:3 */
/*<        >*/
/* SOURCE ts_mngt.prm:5 */
/*<        >*/
/* INCLUDE brnmat.for:541 */
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
/* INCLUDE brnmat.for:542 */
/* ********************************************************************** */
/* SOURCE difcom.cmn:3 */
/*<       common/difcom/clsr1,clsr2 >*/
/* SOURCE difcom.cmn:5 */
/*<       real*8clsr1(mndifa),clsr2(mndifa) >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:543 */
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
/* INCLUDE brnmat.for:544 */
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
/* INCLUDE brnmat.for:545 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:546 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:547 */
/* SOURCE wincom.cmn:2 */
/*<        >*/
/* SOURCE wincom.cmn:5 */
/*<       integerwintab >*/
/* SOURCE wincom.cmn:7 */
/*<       realairwat,vamin,cdmin,vamax,cdmax,vadif,cddif >*/
/* SOURCE wincom.cmn:9 */
/*<       realwdfvec(mnbra) >*/
/* INCLUDE brnmat.for:548 */
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
/* INCLUDE brnmat.for:549 */
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
/* INCLUDE brnmat.for:550 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE brnmat.for:551 */
/*     Contains items used to control irrigation withdrawals from */
/*     a LPR or branch to simulate use of near-surface water supplies */
/*     for irrigation. */
/* SOURCE irrig.cmn:5 */
/*<       integerirrig_knt >*/
/* SOURCE irrig.cmn:7 */
/*<        >*/
/* SOURCE irrig.cmn:14 */
/*<        >*/
/*     IRRIG_KNT-  number of tributary area units subject to */
/*                  dual-source irrigation. */
/*     IRRIG_TRIBA(*)- points to the row in TRIBA(*,*) that */
/*                     contains the land use areas for */
/*                     the tributary area unit.  The tributary */
/*                     area unit is that attached to a LPR */
/*                     or an entire branch.  The input will */
/*                     be in terms of the branch number or */
/*                     the free node number for the reservoir. */
/*                     This will then define the value of the */
/*                     TRIBA row. */
/*     IRRIG_LUI_APPLY(*) - land-use index number of the */
/*                    land use being irrigated.  This give */
/*                    area of land being irrigated. */
/*     IRRIG_LUI_COMPUTE(*) - land-use index number of the */
/*                     land use that will be used to compute */
/*                     the irrigation withdrawal.  The user */
/*                     must provide an additional landuse index */
/*                     for computing the irrigation withdrawal. */
/*     IRRIG_SOURCE(*) - gives the exterior node that represents */
/*                     the source of the irrigation water. */
/*                     The water-surface elevation at this node */
/*                     will be used as the argument to the */
/*                     irrigation control table to determine */
/*                     what fraction of the area will be irrigated */
/*                     from near-surface sources.  The remainder */
/*                     the area will be irrigated from deep ground */
/*                     water sources or from water imported from */
/*                     outside the area being simulated. */
/*     IRRIG_CONTROL_TAB(*) - function-table of type 2, 3, or 4 that */
/*                     taken from near-surface sources as a function */
/*                     of water-surface elevation at the source */
/*                     exterior node.  Typically, if the water-surface */
/*                     elevation at the source node is too low, then */
/*                     near-surface sources have been exhausted and */
/*                     sources of water external to the area being */
/*                     modeled or pumping from deep ground water */
/*                     will supply the irrigation demand. */
/* INCLUDE brnmat.for:552 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + SAVED VALUES + + + */
/* SOURCE brnmat.for:555 */
/*<       real*8past_dt,dt_tolerance >*/
/* SOURCE brnmat.for:556 */
/*<       characterno*4,yes*4 >*/
/* SOURCE brnmat.for:557 */
/*<       saveno,yes >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:560 */
/*<        >*/
/* SOURCE brnmat.for:564 */
/*<        >*/
/* SOURCE brnmat.for:568 */
/*<        >*/
/*     fbtime- julian time for lookup of forced boundary. At the end */
/*             point of the current time step */
/*     retime- julian time for lookup of rainfall-evap. At the mid-pont */
/*             of the current time step. */
/*     dftime- julian time for lookup of diffuse loading from land surface. */
/*             At the end point of the current time step. */
/*     + + + EQUIVALENCES + + + */
/* SOURCE brnmat.for:579 */
/*<       equivalence(rdum,idum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE brnmat.for:582 */
/*<       intrinsicexp >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE brnmat.for:585 */
/*<       externallktab,lktsf,rdget,wshear >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE brnmat.for:588 */
/*<       datayes/'YES'/,no/'NO'/,past_dt/0.d0/,dt_tolerance/1.d-7/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> pfpnt(feq_storage_pfpnt, 4);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE brnmat.for:591 */
/*<    50 format(/,' *BUG:XXX* Invalid CAT_CODE=',i5,' in sub. LOAD') >*/
/* L50: */
/* SOURCE brnmat.for:592 */
/*<    52  >*/
/* L52: */
/* SOURCE brnmat.for:595 */
/*<    54 format(4x,i5,2(2x,1pe12.5)) >*/
/* L54: */
/* SOURCE brnmat.for:596 */
/*<    56  >*/
/* L56: */
/* SOURCE brnmat.for:598 */
/*<    60 format(/,' *ERR:324* Detention reservoir failed to converge.') >*/
/* L60: */
/* *********************************************************************** */
/*     INITIALIZE */
/* SOURCE brnmat.for:601 */
/*<       eflag=0 >*/
    *eflag = 0;
/* SOURCE brnmat.for:602 */
/*<       do10i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:603 */
/*<       wsvec(i)=0. >*/
	bnothr_1.wsvec[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE brnmat.for:604 */
/*<    10 continue >*/
/* L10: */
    }
/* SOURCE brnmat.for:605 */
/*<       do11i=1,qpn >*/
    feq_gen_i_d_1 = *qpn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:606 */
/*<       qpvec(i)=0.0 >*/
	bnothr_1.qpvec[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE brnmat.for:607 */
/*<    11 continue >*/
/* L11: */
    }
/*     Clear the local summation variables for evaporation and */
/*     rainfall */
/* SOURCE brnmat.for:611 */
/*<       l_wsi=0.d0 >*/
    tamcom_1.feq_gen_l_wsi_d_ = 0.;
/* SOURCE brnmat.for:612 */
/*<       l_wsq=0.d0 >*/
    tamcom_1.feq_gen_l_wsq_d_ = 0.;
/*     SET THE TIME VALUES FOR THIS LOOK UP. */
/*     During frozen time we use a time offest of 1 second (1.157407e-5 day) */
/*     on jtime and c     a time step of one second.  However, jtime is */
/*     NOT incremented because frozen time is virtual time. During frozen time, */
/*     ifrz is 0,  DJLOAD = 1.157407e-5, DTLOAD = 1.0, dtdyload = 1.157407e-5. */
/*     For ifrz=0, DJLOAD = 0, DTLOAD = DT, dtdyload= dt/86400.. */
/* SOURCE brnmat.for:620 */
/*<       fbtime=jtime+djload >*/
    fbtime = julian_1.jtime + *djload;
/* SOURCE brnmat.for:621 */
/*<       retime=jtime+djload-0.5*dtdyload >*/
    retime = julian_1.jtime + *djload - *dtdyload * (float).5;
/* SOURCE brnmat.for:622 */
/*<       dftime=jtime+djload >*/
    dftime = julian_1.jtime + *djload;
/*      AJTIME = JTIME + DJLOAD */
/*      JTIME2 = JTIME - 0.5*DTDY */
/*      AJTIME2 = AJTIME - 5.787037037D-6*DTLOAD */
/* SOURCE brnmat.for:628 */
/*<       if(diffus.eq.yes.or.diffus.eq.'DSS ')then >*/
    if (s_cmp(diffus, yes, (ftnlen)4, (ftnlen)4) == 0 || s_cmp(diffus, const_cast<char*>("DSS "),
	     (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE brnmat.for:629 */
/*<       half_dt=0.5d0*dt >*/
	feq_gen_half_dt_d_ = *dt * .5;
/* SOURCE brnmat.for:630 */
/*<       dt_over_12=0.0833333333333333d0*dt >*/
	feq_gen_dt_over_12_d_ = *dt * .0833333333333333;
/* SOURCE brnmat.for:631 */
/*<       calllktsf(stdout,dftime,dt,clsr2,wyr) >*/
	lktsf_(stdout, &dftime, dt, difcom_1.clsr2, wyr);
/*       Check if the time step has changed from the past time */
/*       step.  If so, we must recompute the routing coefficients */
/*       for all delay reservoirs. */
/* SOURCE brnmat.for:639 */
/*<       if(abs(dt-past_dt).gt.dt_tolerance)then >*/
	if ((feq_gen_d_d_1 = *dt - feq_gen_past_dt_d_, abs(feq_gen_d_d_1)) > feq_gen_dt_tolerance_d_) {
/* SOURCE brnmat.for:641 */
/*<       callrecompute_dlay_routing(dt) >*/
	    feq_gen_recompute_dlay_routing_d_(dt);
/* SOURCE brnmat.for:642 */
/*<       past_dt=dt >*/
	    feq_gen_past_dt_d_ = *dt;
/* SOURCE brnmat.for:643 */
/*<       endif >*/
	}
/*       COMPUTE RUNOFF OCCURRING IN THE CURRENT TIME STEP */
/* SOURCE brnmat.for:645 */
/*<       do105j=1,ndfval >*/
	feq_gen_i_d_1 = tsfcom_1.ndfval;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:646 */
/*<       ri(j)=(clsr2(j)-clsr1(j))/dtload >*/
	    ri[j - 1] = (difcom_1.clsr2[j - 1] - difcom_1.clsr1[j - 1]) / *
		    dtload;
/* SOURCE brnmat.for:647 */
/*<   105 continue >*/
/* L105: */
	}
/*       Create the values for dual-source irrigation. */
/* SOURCE brnmat.for:651 */
/*<       if(irrig_knt.gt.0)then >*/
	if (irrig_1.feq_gen_irrig_knt_d_ > 0) {
/*         Dual-source irrigation is active. */
/* SOURCE brnmat.for:653 */
/*<       do110j=1,irrig_knt >*/
	    feq_gen_i_d_1 = irrig_1.feq_gen_irrig_knt_d_;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/*           Find the factor from the control table. */
/* SOURCE brnmat.for:655 */
/*<       adrs=irrig_control_tab(j) >*/
		adrs = irrig_1.feq_gen_irrig_control_tab_d_[j - 1];
/* SOURCE brnmat.for:656 */
/*<       fnode=irrig_source(j) >*/
		fnode = irrig_1.feq_gen_irrig_source_d_[j - 1];
/* SOURCE brnmat.for:657 */
/*<       elev=ze(fnode)+ye1(fnode) >*/
		elev = static_cast<double>(enelem_1.ze[fnode - 1]) + enelem_1.ye1[fnode - 1];
/* SOURCE brnmat.for:658 */
/*<       calllktab(adrs,elev,0,fraction,ntab,df) >*/
		lktab_(&adrs, &elev, &feq_gen_c_d_0, &fraction, &ntab, &df);
/* SOURCE brnmat.for:661 */
/*<       it=irrig_triba_row(j) >*/
		it = irrig_1.feq_gen_irrig_triba_row_d_[j - 1];
/* SOURCE brnmat.for:662 */
/*<        >*/
		tsfcom_1.triba[it + irrig_1.feq_gen_irrig_lui_compute_d_[j - 1] * 8400 
			- 8401] = static_cast<double>(-fraction) * tsfcom_1.triba[it + 
			irrig_1.feq_gen_irrig_lui_apply_d_[j - 1] * 8400 - 8401];
/* SOURCE brnmat.for:664 */
/*<   110 continue >*/
/* L110: */
	    }
/* SOURCE brnmat.for:665 */
/*<       endif >*/
	}
/*       Scan through the tributary-area management vector and */
/*       compute the lateral inflows. */
/* SOURCE brnmat.for:670 */
/*<       unit_pnt=1 >*/
	feq_gen_unit_pnt_d_ = 1;
/*       Clear the sum of outflows to the branches and LPR's */
/*       from tributary areas */
/* SOURCE brnmat.for:674 */
/*<       l_taq=0.d0 >*/
	tamcom_1.feq_gen_l_taq_d_ = 0.;
/*       Clear the sum of outflows to boundary nodes */
/* SOURCE brnmat.for:677 */
/*<       l_taqbn=0.d0 >*/
	tamcom_1.feq_gen_l_taqbn_d_ = 0.;
/*       Clear the sum of inflows to the tributary areas.  This */
/*       should be the runoff total coming from the rainfall-runoff */
/*       computations. */
/* SOURCE brnmat.for:682 */
/*<       l_tai=0.d0 >*/
	tamcom_1.feq_gen_l_tai_d_ = 0.;
/* SOURCE brnmat.for:684 */
/*<  9000 continue >*/
L9000:
/*         All tributary-area unit categories do the computations in the same */
/*         way.  They only differ in how the results are stored in */
/*         QPVEC. */
/* SOURCE brnmat.for:690 */
/*<       cat_code=tam_itab(unit_pnt+1) >*/
	feq_gen_cat_code_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_];
/* SOURCE brnmat.for:691 */
/*<       triba_pnt=tam_itab(unit_pnt+3) >*/
	feq_gen_triba_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 2];
/* SOURCE brnmat.for:692 */
/*<       gage=tam_itab(unit_pnt+4) >*/
	gage = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 3];
/* SOURCE brnmat.for:693 */
/*<       dlay_pnt=tam_itab(unit_pnt+6) >*/
	feq_gen_dlay_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 5];
/* SOURCE brnmat.for:694 */
/*<       dten_pnt=tam_itab(unit_pnt+5) >*/
	feq_gen_dten_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 4];
/* SOURCE brnmat.for:695 */
/*<       sum=0.0d0 >*/
	sum = 0.;
/* SOURCE brnmat.for:696 */
/*<       ks=gstart(gage)-1 >*/
	ks = tsfcom_1.gstart[gage] - 1;
/* SOURCE brnmat.for:697 */
/*<       ke=gend(gage) >*/
	ke = tsfcom_1.gend[gage];
/* SOURCE brnmat.for:698 */
/*<       do1010k=1,ke-ks >*/
	feq_gen_i_d_1 = ke - ks;
	for (k = 1; k <= feq_gen_i_d_1; ++k) {
/* SOURCE brnmat.for:699 */
/*<       ks=ks+1 >*/
	    ++ks;
/* SOURCE brnmat.for:700 */
/*<       sum=sum+triba(triba_pnt,k)*ri(ks) >*/
	    sum += static_cast<double>(tsfcom_1.triba[feq_gen_triba_pnt_d_ + k * 8400 - 8401]) * ri[ks - 1];
/* SOURCE brnmat.for:701 */
/*<  1010 continue >*/
/* L1010: */
	}
/*         Set QBAR in case there is no detention/delay */
/* SOURCE brnmat.for:703 */
/*<       qbar=sum >*/
	qbar = sum;
/*         Update the sum of inflows to tributary area.  This includes */
/*         tributarary area connected to a boundary node. */
/* SOURCE brnmat.for:706 */
/*<       l_tai=l_tai+sum >*/
	tamcom_1.feq_gen_l_tai_d_ += sum;
/*         At this point we have the runoff from the area in */
/*         this trib-area unit. Check for delay or detention. */
/*         If delay is present, it is done first.  Detention */
/*         if any is done next.   The routing coefficients for */
/*         delay have already been computed for the current */
/*         time step. */
/* SOURCE brnmat.for:714 */
/*<       if(dlay_pnt.gt.0)then >*/
	if (feq_gen_dlay_pnt_d_ > 0) {
/*           Flow at end of time step. */
/* SOURCE brnmat.for:716 */
/*<       qend=sum+dlay_exp_of_dt_over_k(dlay_pnt)*(dlay_q1(dlay_pnt)-sum) >*/
	    qend = sum + tamcom_1.feq_gen_dlay_exp_of_dt_over_k_d_[feq_gen_dlay_pnt_d_ - 1] * (
		    tamcom_1.feq_gen_dlay_q1_d_[feq_gen_dlay_pnt_d_ - 1] - sum);
/* SOURCE brnmat.for:718 */
/*<       dlay_q2(dlay_pnt)=qend >*/
	    tamcom_1.feq_gen_dlay_q2_d_[feq_gen_dlay_pnt_d_ - 1] = qend;
/*           Mean flow for the time step. */
/* SOURCE brnmat.for:720 */
/*<       qbar=sum+dlay_k_over_dt(dlay_pnt)*(dlay_q1(dlay_pnt)-qend) >*/
	    qbar = sum + tamcom_1.feq_gen_dlay_k_over_dt_d_[feq_gen_dlay_pnt_d_ - 1] * (
		    tamcom_1.feq_gen_dlay_q1_d_[feq_gen_dlay_pnt_d_ - 1] - qend);
/* SOURCE brnmat.for:722 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:724 */
/*<       if(dten_pnt.gt.0)then >*/
	if (feq_gen_dten_pnt_d_ > 0) {
/*           Detention reservoir is present. Get the address of the */
/*           routing table and the values at the start of the */
/*           time step. */
/* SOURCE brnmat.for:728 */
/*<       rout_tab=dten_rout_tab(dten_pnt) >*/
	    feq_gen_rout_tab_d_ = tamcom_1.feq_gen_dten_rout_tab_d_[feq_gen_dten_pnt_d_ - 1];
/* SOURCE brnmat.for:729 */
/*<       qq1=dten_q1(dten_pnt) >*/
	    qq1 = tamcom_1.feq_gen_dten_q1_d_[feq_gen_dten_pnt_d_ - 1];
/* SOURCE brnmat.for:730 */
/*<       q1p=dten_q1p(dten_pnt) >*/
	    q1p = tamcom_1.feq_gen_dten_q1p_d_[feq_gen_dten_pnt_d_ - 1];
/* SOURCE brnmat.for:731 */
/*<       s1=dten_s1(dten_pnt) >*/
	    s1 = tamcom_1.feq_gen_dten_s1_d_[feq_gen_dten_pnt_d_ - 1];
/* SOURCE brnmat.for:732 */
/*<       number_of_ponds=dten_avda(dten_pnt) >*/
	    feq_gen_number_of_ponds_d_ = tamcom_1.feq_gen_dten_avda_d_[feq_gen_dten_pnt_d_ - 1];
/* SOURCE brnmat.for:733 */
/*<       suma=qbar/number_of_ponds >*/
	    suma = qbar / feq_gen_number_of_ponds_d_;
/* SOURCE brnmat.for:734 */
/*<       knt=0 >*/
	    knt = 0;
/*           Compute the predicted value of the storage at the end */
/*           of the time step. */
/* SOURCE brnmat.for:737 */
/*<       s2=s1+dt*(suma-qq1)/(1.0+half_dt*q1p) >*/
	    s2 = s1 + *dt * (suma - qq1) / (feq_gen_half_dt_d_ * q1p + (float)1.);
/* SOURCE brnmat.for:738 */
/*<       if(s2.lt.0.0)then >*/
	    if (s2 < (float)0.) {
/*             The prediction equation finds that the reservoir */
/*             has no water at some point within the time step. */
/*             Set the end of time step storage to zero. */
/* SOURCE brnmat.for:742 */
/*<       s2=0.0 >*/
		s2 = (float)0.;
/* SOURCE brnmat.for:743 */
/*<       endif >*/
	    }
/*           Now use the predicted value in the correcter equation */
/*           to get an improved value of S2.  Find the flow */
/*           and its derivative wrt to storage at S2.  This begins a */
/*           loop to make more than one correction. */
/* SOURCE brnmat.for:748 */
/*<  1015 continue >*/
L1015:
/* SOURCE brnmat.for:749 */
/*<       calllktab(rout_tab,s2,0,qq2,ntab,q2p) >*/
	    lktab_(&feq_gen_rout_tab_d_, &s2, &feq_gen_c_d_0, &qq2, &ntab, &q2p);
/*             Compute the outflow from the reservoir using the trapezoidal */
/*             rule with derivative end corrections. */
/* SOURCE brnmat.for:754 */
/*<       qbar=0.5*(qq1+qq2)+dt_over_12*(q1p*(suma-qq1)-q2p*(suma-qq2)) >*/
	    qbar = static_cast<double>((static_cast<double>(qq1) + qq2)) * (float).5 + feq_gen_dt_over_12_d_ * (q1p * (suma - 
		    qq1) - q2p * (suma - qq2));
/*              S2T = S1 + DT*(SUMA - QBAR) */
/*             Switch to using Newton's method because linear iteration */
/*             may fail to converge in some cases.  Could happen when */
/*             a detention basin goes way over it design limit. */
/*             In any case the change only required modifying the */
/*             the line at the start of this comment and adding */
/*             one more line.  Note:  The derative is correct for */
/*             the trapezoidal rule and is only approximate for */
/*             the corrected trapezoidal rule we are using.  So */
/*             strictly speaking we are using the modified Newton's */
/*             method.  However, the term we have omitted involves */
/*             the second derivative of the flow vs volume function */
/*             which is not provided by LKTAB.  Testing has shown however, */
/*             that convergence is rapid, 1 to 3 Newton corrections */
/*             reach the criterion set. */
/* SOURCE brnmat.for:772 */
/*<       res=s2t-(s1+dt*(suma-qbar)) >*/
	    res = s2t - (s1 + *dt * (suma - qbar));
/* SOURCE brnmat.for:773 */
/*<       s2t=s2t-res/(1.0+q2p*(half_dt+dt*dt_over_12*q2p)) >*/
	    s2t -= res / (q2p * (feq_gen_half_dt_d_ + *dt * feq_gen_dt_over_12_d_ * q2p) + (
		    float)1.);
/* SOURCE brnmat.for:775 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE brnmat.for:776 */
/*<       if(abs(s2t-s2)/(s2+lprmin).gt.1.0e-6)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(s2t) - s2, dabs(feq_gen_r_d_1)) / (static_cast<double>(s2) + miscon_1.lprmin) > (
		    float)1e-6) {
/* SOURCE brnmat.for:777 */
/*<       if(knt.gt.20)then >*/
		if (knt > 20) {
/* SOURCE brnmat.for:778 */
/*<       write(stdout,60) >*/
		    feq_gen_io_d__95.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__95);
		    e_wsfe();
/* SOURCE brnmat.for:779 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE brnmat.for:780 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:781 */
/*<       s2=s2t >*/
		    s2 = s2t;
/* SOURCE brnmat.for:782 */
/*<       goto1015 >*/
		    goto L1015;
/* SOURCE brnmat.for:783 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:784 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:785 */
/*<       s2=s2t >*/
	    s2 = s2t;
/*           Get the benefit of the last correction! */
/* SOURCE brnmat.for:787 */
/*<       calllktab(rout_tab,s2,0,qq2,ntab,q2p) >*/
	    lktab_(&feq_gen_rout_tab_d_, &s2, &feq_gen_c_d_0, &qq2, &ntab, &q2p);
/* SOURCE brnmat.for:791 */
/*<       if(s2.lt.0.0)then >*/
	    if (s2 < (float)0.) {
/*             The reservoir emptied at some point within the time step. */
/* SOURCE brnmat.for:793 */
/*<       s2=0.0 >*/
		s2 = (float)0.;
/* SOURCE brnmat.for:794 */
/*<       qq2=0.0 >*/
		qq2 = (float)0.;
/* SOURCE brnmat.for:795 */
/*<       q2p=0.0 >*/
		q2p = (float)0.;
/* SOURCE brnmat.for:796 */
/*<       qbar=suma+s1/dt >*/
		qbar = suma + s1 / *dt;
/* SOURCE brnmat.for:797 */
/*<       endif >*/
	    }
/*            write(stdout,9576) knt, qq2, qbar, s2/43560., q2p, */
/*     a                  1.0 + half_dt*q2p + dt*dt_over_12*q2p**2 */
/* 9576  format(' knt=',i5,' Q2=',f10.4,' Qbar=',f10.4,' s2=',f10.4, */
/*     a     ' Q2P=',1pe12.5,' dFhat=',1pe12.5) */
/* SOURCE brnmat.for:802 */
/*<       qend=qq2*number_of_ponds >*/
	    qend = static_cast<double>(qq2) * feq_gen_number_of_ponds_d_;
/* SOURCE brnmat.for:803 */
/*<       qbar=qbar*number_of_ponds >*/
	    qbar *= feq_gen_number_of_ponds_d_;
/* SOURCE brnmat.for:804 */
/*<       dten_s2(dten_pnt)=s2 >*/
	    tamcom_1.feq_gen_dten_s2_d_[feq_gen_dten_pnt_d_ - 1] = s2;
/* SOURCE brnmat.for:805 */
/*<       dten_q2(dten_pnt)=qq2 >*/
	    tamcom_1.feq_gen_dten_q2_d_[feq_gen_dten_pnt_d_ - 1] = qq2;
/* SOURCE brnmat.for:806 */
/*<       dten_q2p(dten_pnt)=q2p >*/
	    tamcom_1.feq_gen_dten_q2p_d_[feq_gen_dten_pnt_d_ - 1] = q2p;
/* SOURCE brnmat.for:807 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:809 */
/*<       goto(1000,2000,3000),cat_code >*/
	switch (feq_gen_cat_code_d_) {
	    case 1:  goto L1000;
	    case 2:  goto L2000;
	    case 3:  goto L3000;
	}
/* SOURCE brnmat.for:810 */
/*<       write(stdout,50)cat_code >*/
	feq_gen_io_d__96.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__96);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_cat_code_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE brnmat.for:811 */
/*<       stop'Abnormal stop. Bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE brnmat.for:813 */
/*<  1000 continue >*/
L1000:
/*             Destination is a branch.  Distribute the flows to the */
/*             elements in proportion to the element lengths. */
/* SOURCE brnmat.for:816 */
/*<       fnode=tam_itab(unit_pnt+7) >*/
	fnode = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 6];
/* SOURCE brnmat.for:817 */
/*<       lnode=tam_itab(unit_pnt+8) >*/
	lnode = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 7];
/* SOURCE brnmat.for:818 */
/*<       fraction_pnt=tam_itab(unit_pnt+9) >*/
	feq_gen_fraction_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 8];
/* SOURCE brnmat.for:819 */
/*<       do1020j=fnode,lnode >*/
	feq_gen_i_d_1 = lnode;
	for (j = fnode; j <= feq_gen_i_d_1; ++j) {
/* SOURCE brnmat.for:820 */
/*<       qpvec(j)=qpvec(j)+qbar*tam_ftab(fraction_pnt+j-fnode) >*/
	    bnothr_1.qpvec[j - 1] += qbar * tamcom_1.feq_gen_tam_ftab_d_[
		    feq_gen_fraction_pnt_d_ + j - fnode - 1];
/* SOURCE brnmat.for:822 */
/*<  1020 continue >*/
/* L1020: */
	}
/* SOURCE brnmat.for:823 */
/*<       l_taq=l_taq+qbar >*/
	tamcom_1.feq_gen_l_taq_d_ += qbar;
/* SOURCE brnmat.for:825 */
/*<       goto9999 >*/
	goto L9999;
/* SOURCE brnmat.for:827 */
/*<  2000 continue >*/
L2000:
/*             Destination is a level-pool reservoir */
/* SOURCE brnmat.for:829 */
/*<       qp_pnt=tam_itab(unit_pnt+7) >*/
	feq_gen_qp_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 6];
/* SOURCE brnmat.for:830 */
/*<       qpvec(qp_pnt)=qpvec(qp_pnt)+qbar >*/
	bnothr_1.qpvec[feq_gen_qp_pnt_d_ - 1] += qbar;
/* SOURCE brnmat.for:831 */
/*<       l_taq=l_taq+qbar >*/
	tamcom_1.feq_gen_l_taq_d_ += qbar;
/* SOURCE brnmat.for:832 */
/*<       goto9999 >*/
	goto L9999;
/* SOURCE brnmat.for:834 */
/*<  3000 continue >*/
L3000:
/*             At boundary nodes we must use the flow at the end of the */
/*             time step. */
/* SOURCE brnmat.for:837 */
/*<       qp_pnt=tam_itab(unit_pnt+7) >*/
	feq_gen_qp_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 6];
/* SOURCE brnmat.for:838 */
/*<       qpvec(qp_pnt)=qpvec(qp_pnt)+qend >*/
	bnothr_1.qpvec[feq_gen_qp_pnt_d_ - 1] += qend;
/* SOURCE brnmat.for:839 */
/*<       rdum=qpvec(qp_pnt) >*/
	*rdum = bnothr_1.qpvec[feq_gen_qp_pnt_d_ - 1];
/*             Stuff the current flow into EMC for the boundary condition. */
/*             The last one done for a node will then contain the sum of the */
/*             flow from detention and non-detention areas. */
/* SOURCE brnmat.for:843 */
/*<       emc(tam_itab(unit_pnt+8))=idum >*/
	emc[tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 7]] = *idum;
/*             The flow at a boundary node must be a value at a point */
/*             in time.  However, we will use the true averaage outflow */
/*             in computing the water balance for the tributary area. */
/*             The water balance for the LPR's and branches will */
/*             not use the current value because the flows at boundary */
/*             nodes are computed elsewhere.  Also there can be a lower */
/*             limit for the flow at a boundary node so that the */
/*             flow computed here will not be used at the boundary if */
/*             it is smaller than the lower limit. */
/* SOURCE brnmat.for:854 */
/*<       l_taqbn=l_taqbn+qbar >*/
	tamcom_1.feq_gen_l_taqbn_d_ += qbar;
/* SOURCE brnmat.for:855 */
/*<       goto9999 >*/
	goto L9999;
/* SOURCE brnmat.for:858 */
/*<  9999 continue >*/
L9999:
/*         Point to the next unit. */
/* SOURCE brnmat.for:860 */
/*<       unit_pnt=tam_itab(unit_pnt+2) >*/
	feq_gen_unit_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 1];
/* SOURCE brnmat.for:861 */
/*<       if(unit_pnt.gt.0)goto9000 >*/
	if (feq_gen_unit_pnt_d_ > 0) {
	    goto L9000;
	}
/* SOURCE brnmat.for:862 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:863 */
/*<       l_tai=0.d0 >*/
	tamcom_1.feq_gen_l_tai_d_ = 0.;
/* SOURCE brnmat.for:864 */
/*<       l_taq=0.d0 >*/
	tamcom_1.feq_gen_l_taq_d_ = 0.;
/* SOURCE brnmat.for:865 */
/*<       l_taqbn=0.d0 >*/
	tamcom_1.feq_gen_l_taqbn_d_ = 0.;
/* SOURCE brnmat.for:866 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:868 */
/*<       do200i=1,num_ts >*/
    feq_gen_i_d_1 = feq_gen_ts_mngt_n_d_1.feq_gen_num_ts_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:869 */
/*<       it=source_address(i) >*/
	it = feq_gen_ts_mngt_n_d_1.feq_gen_source_address_d_[feq_gen_i_d_ - 1];
/* SOURCE brnmat.for:871 */
/*<       if(dest_cat(i).eq.forced_bdy)then >*/
	if (feq_gen_ts_mngt_n_d_1.feq_gen_dest_cat_d_[feq_gen_i_d_ - 1] == 1001) {
/* SOURCE brnmat.for:872 */
/*<       jtime1=fbtime >*/
	    jtime1 = fbtime;
/* SOURCE brnmat.for:873 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:874 */
/*<       jtime1=retime >*/
	    jtime1 = retime;
/* SOURCE brnmat.for:875 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:876 */
/*<       if(source_cat(i).eq.ts_from_table)then >*/
	if (feq_gen_ts_mngt_n_d_1.feq_gen_source_cat_d_[feq_gen_i_d_ - 1] == 1004) {
/*         From time-series table */
/* SOURCE brnmat.for:879 */
/*<       calllktstab(it,jtime1,ts_value,ntab,pdv) >*/
	    lktstab_(&it, &jtime1, &feq_gen_ts_value_d_, &ntab, &pdv);
/* SOURCE brnmat.for:882 */
/*<       else >*/
	} else {
/*         From time-series file */
/* SOURCE brnmat.for:884 */
/*<       callrdget(it,stdout,jtime1,dt,ts_value) >*/
	    rdget_(&it, stdout, &jtime1, dt, &feq_gen_ts_value_d_);
/* SOURCE brnmat.for:887 */
/*<       endif >*/
	}
/*       Now place the result in its destination(s). */
/* SOURCE brnmat.for:889 */
/*<       it=i >*/
	it = feq_gen_i_d_;
/* SOURCE brnmat.for:890 */
/*<   190 continue >*/
L190:
/* SOURCE brnmat.for:891 */
/*<       if(dest_cat(it).eq.forced_bdy)then >*/
	if (feq_gen_ts_mngt_n_d_1.feq_gen_dest_cat_d_[it - 1] == 1001) {
/* SOURCE brnmat.for:892 */
/*<       rdum=ts_value >*/
	    *rdum = feq_gen_ts_value_d_;
/* SOURCE brnmat.for:893 */
/*<       emc(dest_pnt(it))=idum >*/
	    emc[feq_gen_ts_mngt_n_d_1.feq_gen_dest_pnt_d_[it - 1]] = *idum;
/* SOURCE brnmat.for:894 */
/*<       elseif(dest_cat(it).eq.bra_rain)then >*/
	} else if (feq_gen_ts_mngt_n_d_1.feq_gen_dest_cat_d_[it - 1] == 1006) {
/*           Rain on a branch surface. Compute */
/*           surface area for each element and multiply */
/*           by the rainfall intensity to get the */
/*           average inflow rate. */
/* SOURCE brnmat.for:899 */
/*<       ibra=dest_pnt(it) >*/
	    ibra = feq_gen_ts_mngt_n_d_1.feq_gen_dest_pnt_d_[it - 1];
/* SOURCE brnmat.for:900 */
/*<       fnode=brpt(3,ibra)+1 >*/
	    fnode = brpt[(ibra << 3) + 3] + 1;
/* SOURCE brnmat.for:901 */
/*<       lnode=brpt(4,ibra) >*/
	    lnode = brpt[(ibra << 3) + 4];
/* SOURCE brnmat.for:902 */
/*<       do140node=fnode,lnode >*/
	    feq_gen_i_d_2 = lnode;
	    for (node = fnode; node <= feq_gen_i_d_2; ++node) {
/* SOURCE brnmat.for:903 */
/*<       dq=0.5*ts_value*abs(xvec(node)-xvec(node-1))*(t1(node)+t1(node-1)) >*/
		dq = static_cast<double>(feq_gen_ts_value_d_) * (float).5 * (feq_gen_r_d_1 = static_cast<double>(bnelem_1.xvec[node - 1]) 
			- bnelem_1.xvec[node - 2], dabs(feq_gen_r_d_1)) * (static_cast<double>(bnelem_1.t1[
			node - 1]) + bnelem_1.t1[node - 2]);
/* SOURCE brnmat.for:905 */
/*<       qpvec(node)=qpvec(node)+dq >*/
		bnothr_1.qpvec[node - 1] += dq;
/* SOURCE brnmat.for:906 */
/*<       l_wsi=l_wsi+dq >*/
		tamcom_1.feq_gen_l_wsi_d_ += dq;
/* SOURCE brnmat.for:907 */
/*<   140 continue >*/
/* L140: */
	    }
/* SOURCE brnmat.for:908 */
/*<       elseif(dest_cat(it).eq.bra_evap)then >*/
	} else if (feq_gen_ts_mngt_n_d_1.feq_gen_dest_cat_d_[it - 1] == 1002) {
/*           Evaporation on a branch surface. Compute */
/*           surface area for each element and multiply */
/*           by the evaporation intensity to get the */
/*           average outflow rate. */
/* SOURCE brnmat.for:913 */
/*<       ibra=dest_pnt(it) >*/
	    ibra = feq_gen_ts_mngt_n_d_1.feq_gen_dest_pnt_d_[it - 1];
/* SOURCE brnmat.for:914 */
/*<       fnode=brpt(3,ibra)+1 >*/
	    fnode = brpt[(ibra << 3) + 3] + 1;
/* SOURCE brnmat.for:915 */
/*<       lnode=brpt(4,ibra) >*/
	    lnode = brpt[(ibra << 3) + 4];
/* SOURCE brnmat.for:916 */
/*<       do142node=fnode,lnode >*/
	    feq_gen_i_d_2 = lnode;
	    for (node = fnode; node <= feq_gen_i_d_2; ++node) {
/* SOURCE brnmat.for:917 */
/*<       dq=0.5*ts_value*abs(xvec(node)-xvec(node-1))*(t1(node)+t1(node-1)) >*/
		dq = static_cast<double>(feq_gen_ts_value_d_) * (float).5 * (feq_gen_r_d_1 = static_cast<double>(bnelem_1.xvec[node - 1]) 
			- bnelem_1.xvec[node - 2], dabs(feq_gen_r_d_1)) * (static_cast<double>(bnelem_1.t1[
			node - 1]) + bnelem_1.t1[node - 2]);
/* SOURCE brnmat.for:919 */
/*<       qpvec(node)=qpvec(node)-dq >*/
		bnothr_1.qpvec[node - 1] -= dq;
/* SOURCE brnmat.for:920 */
/*<       l_wsq=l_wsq+dq >*/
		tamcom_1.feq_gen_l_wsq_d_ += dq;
/* SOURCE brnmat.for:921 */
/*<   142 continue >*/
/* L142: */
	    }
/* SOURCE brnmat.for:922 */
/*<       elseif(dest_cat(it).eq.lpr_rain)then >*/
	} else if (feq_gen_ts_mngt_n_d_1.feq_gen_dest_cat_d_[it - 1] == 1005) {
/*           Rainfall on a reservoir surface.  Surface area is in */
/*           TE1. */
/* SOURCE brnmat.for:925 */
/*<       pnt=dest_pnt(it) >*/
	    pnt = feq_gen_ts_mngt_n_d_1.feq_gen_dest_pnt_d_[it - 1];
/*           Get the reservoir node number.  At a fixed offset from PNT. */
/* SOURCE brnmat.for:927 */
/*<       node=emc(pnt-7) >*/
	    node = emc[pnt - 7];
/*           Compute the rainfall flux and stuff into EMC as a real. */
/* SOURCE brnmat.for:929 */
/*<       rdum=ts_value*te1(node) >*/
	    *rdum = static_cast<double>(feq_gen_ts_value_d_) * enelem_1.te1[node - 1];
/* SOURCE brnmat.for:930 */
/*<       emc(pnt)=idum >*/
	    emc[pnt] = *idum;
/* SOURCE brnmat.for:931 */
/*<       l_wsi=l_wsi+rdum >*/
	    tamcom_1.feq_gen_l_wsi_d_ += *rdum;
/* SOURCE brnmat.for:932 */
/*<       elseif(dest_cat(it).eq.lpr_evap)then >*/
	} else if (feq_gen_ts_mngt_n_d_1.feq_gen_dest_cat_d_[it - 1] == 1000) {
/*           Evaporation on a reservoir surface.  Surface area is in */
/*           TE1. */
/* SOURCE brnmat.for:935 */
/*<       pnt=dest_pnt(it) >*/
	    pnt = feq_gen_ts_mngt_n_d_1.feq_gen_dest_pnt_d_[it - 1];
/*           Get the reservoir node number.  At a fixed offset from PNT. */
/* SOURCE brnmat.for:937 */
/*<       node=emc(pnt-8) >*/
	    node = emc[pnt - 8];
/*           Compute the evaporation flux and stuff into EMC as a real. */
/* SOURCE brnmat.for:939 */
/*<       rdum=ts_value*te1(node) >*/
	    *rdum = static_cast<double>(feq_gen_ts_value_d_) * enelem_1.te1[node - 1];
/* SOURCE brnmat.for:940 */
/*<       emc(pnt)=idum >*/
	    emc[pnt] = *idum;
/* SOURCE brnmat.for:941 */
/*<       l_wsq=l_wsq+rdum >*/
	    tamcom_1.feq_gen_l_wsq_d_ += *rdum;
/* SOURCE brnmat.for:942 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:943 */
/*<       it=dest_link(it) >*/
	it = feq_gen_ts_mngt_n_d_1.feq_gen_dest_link_d_[it - 1];
/* SOURCE brnmat.for:944 */
/*<       if(it.gt.0)goto190 >*/
	if (it > 0) {
	    goto L190;
	}
/* SOURCE brnmat.for:946 */
/*<   200 continue >*/
/* L200: */
    }
/*     WIND LOADING */
/* SOURCE brnmat.for:952 */
/*<       if(wind.eq.no)goto350 >*/
    if (s_cmp(wind, no, (ftnlen)4, (ftnlen)4) == 0) {
	goto L350;
    }
/* SOURCE brnmat.for:953 */
/*<       callwshear(jtime,shear,wx,wy) >*/
    wshear_(&julian_1.jtime, &shear, &wx, &wy);
/* SOURCE brnmat.for:956 */
/*<       do320ibra=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE brnmat.for:957 */
/*<       fnode=brpt(3,ibra)+1 >*/
	fnode = brpt[(ibra << 3) + 3] + 1;
/* SOURCE brnmat.for:958 */
/*<       lnode=brpt(4,ibra) >*/
	lnode = brpt[(ibra << 3) + 4];
/* SOURCE brnmat.for:959 */
/*<       temp=wdfvec(ibra)*shear >*/
	temp = static_cast<double>(wincom_1.wdfvec[ibra - 1]) * shear;
/* SOURCE brnmat.for:960 */
/*<       do300i=fnode,lnode >*/
	feq_gen_i_d_2 = lnode;
	for (feq_gen_i_d_ = fnode; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:961 */
/*<       wsvec(i)=temp*(uvx(i)*wx+uvy(i)*wy) >*/
	    bnothr_1.wsvec[feq_gen_i_d_ - 1] = static_cast<double>(temp) * (static_cast<double>(static_cast<double>(bnothr_1.uvx[feq_gen_i_d_ - 1]) * wx) + 
		    static_cast<double>(bnothr_1.uvy[feq_gen_i_d_ - 1]) * wy);
/* SOURCE brnmat.for:962 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE brnmat.for:963 */
/*<   320 continue >*/
/* L320: */
    }
/*     WRITE OUT DATA */
/* SOURCE brnmat.for:967 */
/*<   350 continue >*/
L350:
/* SOURCE brnmat.for:968 */
/*<       if(output.lt.3)goto410 >*/
    if (*output < 3) {
	goto L410;
    }
/* SOURCE brnmat.for:969 */
/*<       write(stdout,52)jtime >*/
    feq_gen_io_d__111.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__111);
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.jtime, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE brnmat.for:970 */
/*<       do400i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE brnmat.for:971 */
/*<       write(stdout,54)i,qpvec(i),wsvec(i) >*/
	feq_gen_io_d__112.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__112);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&bnothr_1.qpvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&bnothr_1.wsvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE brnmat.for:972 */
/*<   400 continue >*/
/* L400: */
    }
/* SOURCE brnmat.for:973 */
/*<   410 continue >*/
L410:
/* SOURCE brnmat.for:974 */
/*<       if(eflag.eq.0)goto900 >*/
    if (*eflag == 0) {
	goto L900;
    }
/* SOURCE brnmat.for:975 */
/*<       write(stdout,56) >*/
    feq_gen_io_d__113.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__113);
    e_wsfe();
/* SOURCE brnmat.for:976 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE brnmat.for:977 */
/*<   900 return >*/
L900:
    return 0;
/* SOURCE brnmat.for:978 */
/*<       end >*/
} /* load_ */

#undef rtmp
#undef rdum
#undef idum
#undef itab
#undef ftab





/* SOURCE brnmat.for:982 */
/*<        >*/
/* Subroutine */ int seticw_(doublereal *dt, integer *nbr, integer *nbra, 
	real *wt, integer *feq_storage_brpt, integer *ieq, real *errp, real *errq, 
	integer *berrp, integer *nerrp, integer *berrq, integer *nerrq)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;

    /* Builtin functions */
    double r_sign(real *, real *), sqrt(doublereal);

    /* Local variables */
    real b, c1, c2, c3, c4, s1, s2, s3, cf, dh;
    integer fn;
    real wa;
    integer ln;
    real dv, dx, dy, dz, yc, qp, kp, zi, tp, ym, wx, dv2, dx2, kac, gde, ald, 
	    amd, bld, kdc, ard, brd, kld, kmd;
    integer nnd;
    real krd, alu, amu, blu, dxh, qld, aru, bru, err, qrd, klu, kmu, res, tld,
	     tpa, kru, qlu, tpb, tlu, tpc, tpd, qru, trd, vld, tru, vlu, vrd, 
	    vru, wtc, yld, ylu, yrd, yru, zit, ziy, mald, mard;
    integer ntab, jcol, adrs, ninc;
    real dblu, dbru, khlm, dklu, malu, dxdt, maru, dkru, dtlu, mqld, dtru, 
	    ksum, mqlu, mqrd, pgfu, mqru, qmax, sfmt, sfmu;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real dkhlm, dmalu, dmaru, dmqlu, dmqru, dxhdt, pfqlu, pfqru, pfylu, pfyru;
    extern /* Subroutine */ int xlkt23_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real sgndv2;
    integer elmadr, ubnbas;
    real dqpylu, dqpyru, dyndif, newmom, newsum, newvol, oldflw, oldimp, 
	    oldmom, oldsum, oldvol, oldwnd;

/*     + + + PURPOSE + + + */
/*     Create the portion of the matrix corresponding to the */
/*     given branch number, NBR. IEQ gives the last equation created */
/*     in the matrix.  Used only for branches which have 2 unknowns */
/*     per node. Variable weight in x direction used. */
/*     This routine uses the curvilinear elements MA and MQ. */
/*     Otherwise it is the same as SETINW. */
/* SOURCE brnmat.for:995 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE brnmat.for:997 */
/*<       integerberrp,berrq,ieq,nbr,nbra,nerrp,nerrq >*/
/* SOURCE brnmat.for:998 */
/*<       integerbrpt(8,nbra) >*/
/* SOURCE brnmat.for:999 */
/*<       realerrp,errq,wt >*/
/* SOURCE brnmat.for:1000 */
/*<       real*8dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     NBR    - number of the branch being processed */
/*     NBRA   - number of branches in the model */
/*     WT     - weight factor for approximating time integrals */
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
/*     IEQ    - equation number */
/*     ERRP   - current maximum relative change in surcharge storage */
/*     ERRQ   - maximum value of the ratio of lateral inflow to the */
/*               average flow in the element */
/*     BERRP  - records the branch number(internal) that has the */
/*               greatest absolute value of the change in surcharge */
/*               storage relative to the storage in the storm sewer */
/*     NERRP  - node at which maximum correction to surcharge storage */
/*               occurs */
/*     BERRQ  - records the branch number(internal) that has the */
/*               greatest value of the ratio of lateral inflow */
/*               to average flow in an element */
/*     NERRQ  - node at which maximum relative lateral inflow occurs */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE brnmat.for:1032 */
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
/* INCLUDE brnmat.for:1033 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE brnmat.for:1034 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:1035 */
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
/* INCLUDE brnmat.for:1036 */
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
/* INCLUDE brnmat.for:1037 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:1038 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:1041 */
/*<       integeradrs,elmadr,fn,jcol,ln,ninc,nnd,ntab,ubnbas >*/
/* SOURCE brnmat.for:1042 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE brnmat.for:1055 */
/*<       intrinsicabs,sign,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE brnmat.for:1058 */
/*<       externallktab,xlkt23 >*/
/* *********************************************************************** */
/* SOURCE brnmat.for:1060 */
/*<       wtc=1.0-wt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
    wtc = static_cast<double>((float)1.) - *wt;
/*     SET THE DIRECTION OF PROCESSING FOR THIS BRANCH.  THE SIGN OF THE */
/*     VARIABLE NUMBER FOR THE FIRST VARIABLE ON THE BRANCH SETS THE */
/*     DIRECTION */
/* SOURCE brnmat.for:1066 */
/*<       jcol=brpt(7,nbr) >*/
    jcol = brpt[(*nbr << 3) + 7];
/* SOURCE brnmat.for:1067 */
/*<       if(jcol.gt.0)then >*/
    if (jcol > 0) {
/* SOURCE brnmat.for:1068 */
/*<       fn=brpt(3,nbr) >*/
	fn = brpt[(*nbr << 3) + 3];
/* SOURCE brnmat.for:1069 */
/*<       ln=brpt(4,nbr) >*/
	ln = brpt[(*nbr << 3) + 4];
/* SOURCE brnmat.for:1070 */
/*<       ninc=1 >*/
	ninc = 1;
/*       SET THE USER BRANCH NODE BASE FOR REPORTING NERRQ AND NERRP */
/* SOURCE brnmat.for:1072 */
/*<       ubnbas=brpt(1,nbr)+1 >*/
	ubnbas = brpt[(*nbr << 3) + 1] + 1;
/* SOURCE brnmat.for:1073 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:1074 */
/*<       fn=brpt(4,nbr) >*/
	fn = brpt[(*nbr << 3) + 4];
/* SOURCE brnmat.for:1075 */
/*<       ln=brpt(3,nbr) >*/
	ln = brpt[(*nbr << 3) + 3];
/* SOURCE brnmat.for:1076 */
/*<       ninc=-1 >*/
	ninc = -1;
/* SOURCE brnmat.for:1077 */
/*<       jcol=-jcol >*/
	jcol = -jcol;
/* SOURCE brnmat.for:1078 */
/*<       ubnbas=brpt(2,nbr) >*/
	ubnbas = brpt[(*nbr << 3) + 2];
/* SOURCE brnmat.for:1079 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:1081 */
/*<       zi=zivec(nbr) >*/
    zi = bnothr_1.zivec[*nbr - 1];
/* SOURCE brnmat.for:1082 */
/*<       zit=zi >*/
    zit = zi;
/* SOURCE brnmat.for:1083 */
/*<       ziy=zilim(nbr) >*/
    ziy = bnothr_1.zilim[*nbr - 1];
/* SOURCE brnmat.for:1084 */
/*<       if(stflag.eq.0)then >*/
    if (bnelem_1.stflag == 0) {
/* SOURCE brnmat.for:1085 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:1086 */
/*<       tld=t1(fn) >*/
	    tld = bnelem_1.t1[fn - 1];
/* SOURCE brnmat.for:1087 */
/*<       ald=a1(fn) >*/
	    ald = bnelem_1.a1[fn - 1];
/* SOURCE brnmat.for:1088 */
/*<       yld=y1(fn) >*/
	    yld = bnelem_1.y1[fn - 1];
/* SOURCE brnmat.for:1089 */
/*<       bld=b1(fn) >*/
	    bld = bnelem_1.b1[fn - 1];
/* SOURCE brnmat.for:1090 */
/*<       qld=q1(fn) >*/
	    qld = bnelem_1.q1[fn - 1];
/* SOURCE brnmat.for:1091 */
/*<       kld=k1(fn) >*/
	    kld = bnelem_1.k1[fn - 1];
/* SOURCE brnmat.for:1092 */
/*<       mald=ma1(fn) >*/
	    mald = bnelem_1.ma1[fn - 1];
/* SOURCE brnmat.for:1093 */
/*<       mqld=mq1(fn) >*/
	    mqld = bnelem_1.mq1[fn - 1];
/* SOURCE brnmat.for:1094 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1095 */
/*<       trd=t1(fn) >*/
	    trd = bnelem_1.t1[fn - 1];
/* SOURCE brnmat.for:1096 */
/*<       ard=a1(fn) >*/
	    ard = bnelem_1.a1[fn - 1];
/* SOURCE brnmat.for:1097 */
/*<       yrd=y1(fn) >*/
	    yrd = bnelem_1.y1[fn - 1];
/* SOURCE brnmat.for:1098 */
/*<       brd=b1(fn) >*/
	    brd = bnelem_1.b1[fn - 1];
/* SOURCE brnmat.for:1099 */
/*<       qrd=q1(fn) >*/
	    qrd = bnelem_1.q1[fn - 1];
/* SOURCE brnmat.for:1100 */
/*<       krd=k1(fn) >*/
	    krd = bnelem_1.k1[fn - 1];
/* SOURCE brnmat.for:1101 */
/*<       mard=ma1(fn) >*/
	    mard = bnelem_1.ma1[fn - 1];
/* SOURCE brnmat.for:1102 */
/*<       mqrd=mq1(fn) >*/
	    mqrd = bnelem_1.mq1[fn - 1];
/* SOURCE brnmat.for:1103 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1104 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:1106 */
/*<       if(ninc.gt.0)then >*/
    if (ninc > 0) {
/* SOURCE brnmat.for:1107 */
/*<       qlu=q2(fn) >*/
	qlu = bnelem_1.q2[fn - 1];
/* SOURCE brnmat.for:1108 */
/*<       ylu=y2(fn) >*/
	ylu = bnelem_1.y2[fn - 1];
/* SOURCE brnmat.for:1109 */
/*<        >*/
	xlkt23_(&bnothr_1.nsec[fn - 1], &ylu, &alu, &tlu, &dtlu, &klu, &dklu, 
		&blu, &dblu, &malu, &dmalu, &mqlu, &dmqlu);
/* SOURCE brnmat.for:1114 */
/*<       t2(fn)=tlu >*/
	bnelem_1.t2[fn - 1] = tlu;
/* SOURCE brnmat.for:1115 */
/*<       a2(fn)=alu >*/
	bnelem_1.a2[fn - 1] = alu;
/* SOURCE brnmat.for:1116 */
/*<       b2(fn)=blu >*/
	bnelem_1.b2[fn - 1] = blu;
/* SOURCE brnmat.for:1117 */
/*<       k2(fn)=klu >*/
	bnelem_1.k2[fn - 1] = klu;
/* SOURCE brnmat.for:1118 */
/*<       ma2(fn)=malu >*/
	bnelem_1.ma2[fn - 1] = malu;
/* SOURCE brnmat.for:1119 */
/*<       mq2(fn)=mqlu >*/
	bnelem_1.mq2[fn - 1] = mqlu;
/* SOURCE brnmat.for:1120 */
/*<       fn=fn+1 >*/
	++fn;
/* SOURCE brnmat.for:1121 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:1122 */
/*<       qru=q2(fn) >*/
	qru = bnelem_1.q2[fn - 1];
/* SOURCE brnmat.for:1123 */
/*<       yru=y2(fn) >*/
	yru = bnelem_1.y2[fn - 1];
/* SOURCE brnmat.for:1124 */
/*<        >*/
	xlkt23_(&bnothr_1.nsec[fn - 1], &yru, &aru, &tru, &dtru, &kru, &dkru, 
		&bru, &dbru, &maru, &dmaru, &mqru, &dmqru);
/* SOURCE brnmat.for:1129 */
/*<       t2(fn)=tru >*/
	bnelem_1.t2[fn - 1] = tru;
/* SOURCE brnmat.for:1130 */
/*<       a2(fn)=aru >*/
	bnelem_1.a2[fn - 1] = aru;
/* SOURCE brnmat.for:1131 */
/*<       b2(fn)=bru >*/
	bnelem_1.b2[fn - 1] = bru;
/* SOURCE brnmat.for:1132 */
/*<       k2(fn)=kru >*/
	bnelem_1.k2[fn - 1] = kru;
/* SOURCE brnmat.for:1133 */
/*<       ma2(fn)=maru >*/
	bnelem_1.ma2[fn - 1] = maru;
/* SOURCE brnmat.for:1134 */
/*<       mq2(fn)=mqru >*/
	bnelem_1.mq2[fn - 1] = mqru;
/* SOURCE brnmat.for:1135 */
/*<       fn=fn-1 >*/
	--fn;
/* SOURCE brnmat.for:1136 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:1138 */
/*<       do100nnd=fn,ln,ninc >*/
    feq_gen_i_d_1 = ln;
    feq_gen_i_d_2 = ninc;
    for (nnd = fn; feq_gen_i_d_2 < 0 ? nnd >= feq_gen_i_d_1 : nnd <= feq_gen_i_d_1; nnd += feq_gen_i_d_2) {
/* SOURCE brnmat.for:1139 */
/*<       if(ninc.eq.1)then >*/
	if (ninc == 1) {
/* SOURCE brnmat.for:1140 */
/*<       elmadr=nnd >*/
	    elmadr = nnd;
/* SOURCE brnmat.for:1141 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1142 */
/*<       elmadr=nnd+1 >*/
	    elmadr = nnd + 1;
/* SOURCE brnmat.for:1143 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1144 */
/*<       dx=dxvec(elmadr) >*/
	dx = bnelem_1.dxvec[elmadr - 1];
/* SOURCE brnmat.for:1145 */
/*<       dxh=0.5*dx >*/
	dxh = static_cast<double>(dx) * (float).5;
/* SOURCE brnmat.for:1146 */
/*<       dx2=dx+dx >*/
	dx2 = static_cast<double>(dx) + dx;
/* SOURCE brnmat.for:1147 */
/*<       dxdt=dx/dt >*/
	dxdt = dx / *dt;
/* SOURCE brnmat.for:1148 */
/*<       dxhdt=0.5*dxdt >*/
	dxhdt = static_cast<double>(dxdt) * (float).5;
/* SOURCE brnmat.for:1149 */
/*<       dz=dzvec(elmadr) >*/
	dz = bnelem_1.dzvec[elmadr - 1];
/* SOURCE brnmat.for:1150 */
/*<       kac=ka(elmadr) >*/
	kac = bnelem_1.ka[elmadr - 1];
/* SOURCE brnmat.for:1151 */
/*<       kdc=kd(elmadr) >*/
	kdc = bnelem_1.kd[elmadr - 1];
/* SOURCE brnmat.for:1152 */
/*<       adrs=hltab(elmadr) >*/
	adrs = bnothr_1.hltab[elmadr - 1];
/* SOURCE brnmat.for:1153 */
/*<       if(stflag.eq.0)then >*/
	if (bnelem_1.stflag == 0) {
/* SOURCE brnmat.for:1154 */
/*<       wx=wxvec(elmadr) >*/
	    wx = bnelem_1.wxvec[elmadr - 1];
/* SOURCE brnmat.for:1155 */
/*<       wa=wxvec1(elmadr) >*/
	    wa = bnelem_1.wxvec1[elmadr - 1];
/* SOURCE brnmat.for:1156 */
/*<       if(ninc.gt.0)then >*/
	    if (ninc > 0) {
/* SOURCE brnmat.for:1157 */
/*<       trd=t1(nnd) >*/
		trd = bnelem_1.t1[nnd - 1];
/* SOURCE brnmat.for:1158 */
/*<       ard=a1(nnd) >*/
		ard = bnelem_1.a1[nnd - 1];
/* SOURCE brnmat.for:1159 */
/*<       yrd=y1(nnd) >*/
		yrd = bnelem_1.y1[nnd - 1];
/* SOURCE brnmat.for:1160 */
/*<       brd=b1(nnd) >*/
		brd = bnelem_1.b1[nnd - 1];
/* SOURCE brnmat.for:1161 */
/*<       qrd=q1(nnd) >*/
		qrd = bnelem_1.q1[nnd - 1];
/* SOURCE brnmat.for:1162 */
/*<       krd=k1(nnd) >*/
		krd = bnelem_1.k1[nnd - 1];
/* SOURCE brnmat.for:1163 */
/*<       mard=ma1(nnd) >*/
		mard = bnelem_1.ma1[nnd - 1];
/* SOURCE brnmat.for:1164 */
/*<       mqrd=mq1(nnd) >*/
		mqrd = bnelem_1.mq1[nnd - 1];
/* SOURCE brnmat.for:1165 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1166 */
/*<       tld=t1(nnd) >*/
		tld = bnelem_1.t1[nnd - 1];
/* SOURCE brnmat.for:1167 */
/*<       ald=a1(nnd) >*/
		ald = bnelem_1.a1[nnd - 1];
/* SOURCE brnmat.for:1168 */
/*<       yld=y1(nnd) >*/
		yld = bnelem_1.y1[nnd - 1];
/* SOURCE brnmat.for:1169 */
/*<       bld=b1(nnd) >*/
		bld = bnelem_1.b1[nnd - 1];
/* SOURCE brnmat.for:1170 */
/*<       qld=q1(nnd) >*/
		qld = bnelem_1.q1[nnd - 1];
/* SOURCE brnmat.for:1171 */
/*<       kld=k1(nnd) >*/
		kld = bnelem_1.k1[nnd - 1];
/* SOURCE brnmat.for:1172 */
/*<       mald=ma1(nnd) >*/
		mald = bnelem_1.ma1[nnd - 1];
/* SOURCE brnmat.for:1173 */
/*<       mqld=mq1(nnd) >*/
		mqld = bnelem_1.mq1[nnd - 1];
/* SOURCE brnmat.for:1174 */
/*<       endif >*/
	    }
/*           SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL. */
/* SOURCE brnmat.for:1177 */
/*<       if(yld.lt.ziy.or.yrd.lt.ziy)then >*/
	    if (yld < ziy || yrd < ziy) {
/* SOURCE brnmat.for:1178 */
/*<       zi=0.0 >*/
		zi = (float)0.;
/* SOURCE brnmat.for:1179 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1180 */
/*<       zi=zit >*/
		zi = zit;
/* SOURCE brnmat.for:1181 */
/*<       endif >*/
	    }
/*           COMPUTE VALUES AT THE START OF THE TIME STEP AND STORE */
/* SOURCE brnmat.for:1185 */
/*<       oldsum=qld+qrd >*/
	    oldsum = static_cast<double>(qld) + qrd;
/* SOURCE brnmat.for:1186 */
/*<       oldmom=mqld*qld+mqrd*qrd >*/
	    oldmom = static_cast<double>(static_cast<double>(mqld) * qld) + static_cast<double>(mqrd) * qrd;
/* SOURCE brnmat.for:1187 */
/*<       momvec(elmadr)=oldmom >*/
	    bnelem_1.momvec[elmadr - 1] = oldmom;
/* SOURCE brnmat.for:1189 */
/*<       sumvec(elmadr)=oldsum >*/
	    bnelem_1.sumvec[elmadr - 1] = oldsum;
/* SOURCE brnmat.for:1190 */
/*<       if(oldsum.lt.0.0)then >*/
	    if (oldsum < (float)0.) {
/* SOURCE brnmat.for:1191 */
/*<       wa=1.-wa >*/
		wa = static_cast<double>((float)1.) - wa;
/* SOURCE brnmat.for:1192 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1193 */
/*<       vld=qld/ald >*/
	    vld = static_cast<double>(qld) / ald;
/* SOURCE brnmat.for:1194 */
/*<       vrd=qrd/ard >*/
	    vrd = static_cast<double>(qrd) / ard;
/* SOURCE brnmat.for:1196 */
/*<       gde=0.0 >*/
	    gde = (float)0.;
/* SOURCE brnmat.for:1197 */
/*<       if(kdc.gt.0.0.or.kac.gt.0.0)then >*/
	    if (kdc > (float)0. || kac > (float)0.) {
/*             PROCESS EXPANSION AND CONTRACTION LOSSES */
/* SOURCE brnmat.for:1199 */
/*<       dv=vld-vrd >*/
		dv = static_cast<double>(vld) - vrd;
/* SOURCE brnmat.for:1200 */
/*<       if(dv.gt.0.0)then >*/
		if (dv > (float)0.) {
/*               FLOW IS UNDERGOING NEGATIVE ACCELERATION-TAKEN */
/*               TO INDICATE EXPANSION */
/* SOURCE brnmat.for:1203 */
/*<       kp=kdc >*/
		    kp = kdc;
/* SOURCE brnmat.for:1204 */
/*<       else >*/
		} else {
/*               FLOW IS UNDERGOING POSITIVE ACCELERATION- TAKEN TO */
/*               INDICATE CONTRACTION */
/* SOURCE brnmat.for:1207 */
/*<       kp=kac >*/
		    kp = kac;
/* SOURCE brnmat.for:1208 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:1209 */
/*<       gde=0.5*sign(kp,oldsum)*abs(dv*(vld+vrd)) >*/
		gde = r_sign(&kp, &oldsum) * (float).5 * (feq_gen_r_d_1 = static_cast<double>(dv) * (static_cast<double>(vld) + 
			vrd), dabs(feq_gen_r_d_1));
/* SOURCE brnmat.for:1210 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1212 */
/*<       if(adrs.gt.0)then >*/
	    if (adrs > 0) {
/*             POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT */
/* SOURCE brnmat.for:1214 */
/*<       ym=0.5*(yld+yrd) >*/
		ym = static_cast<double>((static_cast<double>(yld) + yrd)) * (float).5;
/* SOURCE brnmat.for:1215 */
/*<       calllktab(adrs,ym,0,khlm,ntab,dkhlm) >*/
		lktab_(&adrs, &ym, &feq_gen_c_d_0, &khlm, &ntab, &dkhlm);
/* SOURCE brnmat.for:1218 */
/*<       if(oldsum.lt.0.0)then >*/
		if (oldsum < (float)0.) {
/* SOURCE brnmat.for:1219 */
/*<       khlm=-khlm >*/
		    khlm = -khlm;
/* SOURCE brnmat.for:1220 */
/*<       dkhlm=-dkhlm >*/
		    dkhlm = -dkhlm;
/* SOURCE brnmat.for:1221 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:1223 */
/*<       gde=gde+0.5*khlm*(oldsum/(ald+ard))**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(oldsum) / (static_cast<double>(ald) + ard);
		gde += static_cast<double>(static_cast<double>(static_cast<double>(khlm) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE brnmat.for:1224 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1226 */
/*<       dy=yrd-yld >*/
	    dy = static_cast<double>(yrd) - yld;
/* SOURCE brnmat.for:1227 */
/*<       kmd=kld+wx*(krd-kld) >*/
	    kmd = static_cast<double>(kld) + static_cast<double>(wx) * (static_cast<double>(krd) - kld);
/* SOURCE brnmat.for:1228 */
/*<       amd=ald+wa*(ard-ald) >*/
	    amd = static_cast<double>(ald) + static_cast<double>(wa) * (static_cast<double>(ard) - ald);
/* SOURCE brnmat.for:1229 */
/*<        >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = kmd;
	    oldimp = (gravcm_1.grav * (dz + static_cast<double>(oldsum) * (float).25 * dabs(oldsum)
		     * dx / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + dy) + gde) * amd + static_cast<double>(zi) * (static_cast<double>(static_cast<double>(static_cast<double>(brd) * 
		    vrd) * qrd) - static_cast<double>(static_cast<double>(bld) * vld) * qld);
/* SOURCE brnmat.for:1233 */
/*<       impvec(elmadr)=oldimp >*/
	    bnelem_1.impvec[elmadr - 1] = oldimp;
/* SOURCE brnmat.for:1234 */
/*<       if(wsvec(elmadr).ne.0.0)then >*/
	    if (bnothr_1.wsvec[elmadr - 1] != (float)0.) {
/*             COMPUTE THE WIND STRESS TERM.  WSVEC IS USED TO HOLD */
/*             VALUE BECAUSE THE WIND STRESS IS RECOMPUTED FOR EACH */
/*             TIME STEP AT THE START OF THE TIME STEP.  WE USE THE */
/*             EULER APPROXIMATION FOR THE INTEGRAL TO SIMPLIFY THE */
/*             EQUATIONS. */
/* SOURCE brnmat.for:1241 */
/*<       oldwnd=dxh*(tld+trd)*wsvec(elmadr) >*/
		oldwnd = static_cast<double>(static_cast<double>(dxh) * (static_cast<double>(tld) + trd)) * bnothr_1.wsvec[elmadr - 1];
/* SOURCE brnmat.for:1242 */
/*<       wsvec(elmadr)=oldwnd >*/
		bnothr_1.wsvec[elmadr - 1] = oldwnd;
/* SOURCE brnmat.for:1243 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1244 */
/*<       oldwnd=0.0 >*/
		oldwnd = (float)0.;
/* SOURCE brnmat.for:1245 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1247 */
/*<       oldvol=(1.-wa)*mald*ald+wa*mard*ard >*/
	    oldvol = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - wa)) * mald) * ald) + static_cast<double>(static_cast<double>(wa) * mard) * ard;
/* SOURCE brnmat.for:1248 */
/*<       volvec(elmadr)=oldvol >*/
	    bnelem_1.volvec[elmadr - 1] = oldvol;
/* SOURCE brnmat.for:1249 */
/*<       oldflw=qrd-qld >*/
	    oldflw = static_cast<double>(qrd) - qld;
/* SOURCE brnmat.for:1250 */
/*<       flwvec(elmadr)=oldflw >*/
	    bnelem_1.flwvec[elmadr - 1] = oldflw;
/* SOURCE brnmat.for:1252 */
/*<       if(ninc.gt.0)then >*/
	    if (ninc > 0) {
/* SOURCE brnmat.for:1253 */
/*<       yld=yrd >*/
		yld = yrd;
/* SOURCE brnmat.for:1254 */
/*<       tld=trd >*/
		tld = trd;
/* SOURCE brnmat.for:1255 */
/*<       ald=ard >*/
		ald = ard;
/* SOURCE brnmat.for:1256 */
/*<       bld=brd >*/
		bld = brd;
/* SOURCE brnmat.for:1257 */
/*<       kld=krd >*/
		kld = krd;
/* SOURCE brnmat.for:1258 */
/*<       qld=qrd >*/
		qld = qrd;
/* SOURCE brnmat.for:1259 */
/*<       mald=mard >*/
		mald = mard;
/* SOURCE brnmat.for:1260 */
/*<       mqld=mqrd >*/
		mqld = mqrd;
/* SOURCE brnmat.for:1261 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1262 */
/*<       yrd=yld >*/
		yrd = yld;
/* SOURCE brnmat.for:1263 */
/*<       trd=tld >*/
		trd = tld;
/* SOURCE brnmat.for:1264 */
/*<       ard=ald >*/
		ard = ald;
/* SOURCE brnmat.for:1265 */
/*<       brd=bld >*/
		brd = bld;
/* SOURCE brnmat.for:1266 */
/*<       krd=kld >*/
		krd = kld;
/* SOURCE brnmat.for:1267 */
/*<       qrd=qld >*/
		qrd = qld;
/* SOURCE brnmat.for:1268 */
/*<       mard=mald >*/
		mard = mald;
/* SOURCE brnmat.for:1269 */
/*<       mqrd=mqld >*/
		mqrd = mqld;
/* SOURCE brnmat.for:1270 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1271 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1272 */
/*<       oldsum=sumvec(elmadr) >*/
	    oldsum = bnelem_1.sumvec[elmadr - 1];
/* SOURCE brnmat.for:1273 */
/*<       oldmom=momvec(elmadr) >*/
	    oldmom = bnelem_1.momvec[elmadr - 1];
/* SOURCE brnmat.for:1274 */
/*<       oldimp=impvec(elmadr) >*/
	    oldimp = bnelem_1.impvec[elmadr - 1];
/* SOURCE brnmat.for:1275 */
/*<       oldvol=volvec(elmadr) >*/
	    oldvol = bnelem_1.volvec[elmadr - 1];
/* SOURCE brnmat.for:1276 */
/*<       oldflw=flwvec(elmadr) >*/
	    oldflw = bnelem_1.flwvec[elmadr - 1];
/* SOURCE brnmat.for:1277 */
/*<       oldwnd=wsvec(elmadr) >*/
	    oldwnd = bnothr_1.wsvec[elmadr - 1];
/* SOURCE brnmat.for:1278 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1280 */
/*<       wa=wxvec2(elmadr) >*/
	wa = bnelem_1.wxvec2[elmadr - 1];
/* SOURCE brnmat.for:1282 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:1283 */
/*<       qru=q2(nnd) >*/
	    qru = bnelem_1.q2[nnd - 1];
/* SOURCE brnmat.for:1284 */
/*<       yru=y2(nnd) >*/
	    yru = bnelem_1.y2[nnd - 1];
/* SOURCE brnmat.for:1285 */
/*<        >*/
	    xlkt23_(&bnothr_1.nsec[nnd - 1], &yru, &aru, &tru, &dtru, &kru, &
		    dkru, &bru, &dbru, &maru, &dmaru, &mqru, &dmqru);
/* SOURCE brnmat.for:1290 */
/*<       t2(nnd)=tru >*/
	    bnelem_1.t2[nnd - 1] = tru;
/* SOURCE brnmat.for:1291 */
/*<       a2(nnd)=aru >*/
	    bnelem_1.a2[nnd - 1] = aru;
/* SOURCE brnmat.for:1292 */
/*<       b2(nnd)=bru >*/
	    bnelem_1.b2[nnd - 1] = bru;
/* SOURCE brnmat.for:1293 */
/*<       k2(nnd)=kru >*/
	    bnelem_1.k2[nnd - 1] = kru;
/* SOURCE brnmat.for:1294 */
/*<       ma2(nnd)=maru >*/
	    bnelem_1.ma2[nnd - 1] = maru;
/* SOURCE brnmat.for:1295 */
/*<       mq2(nnd)=mqru >*/
	    bnelem_1.mq2[nnd - 1] = mqru;
/* SOURCE brnmat.for:1296 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1297 */
/*<       qlu=q2(nnd) >*/
	    qlu = bnelem_1.q2[nnd - 1];
/* SOURCE brnmat.for:1298 */
/*<       ylu=y2(nnd) >*/
	    ylu = bnelem_1.y2[nnd - 1];
/* SOURCE brnmat.for:1299 */
/*<        >*/
	    xlkt23_(&bnothr_1.nsec[nnd - 1], &ylu, &alu, &tlu, &dtlu, &klu, &
		    dklu, &blu, &dblu, &malu, &dmalu, &mqlu, &dmqlu);
/* SOURCE brnmat.for:1304 */
/*<       t2(nnd)=tlu >*/
	    bnelem_1.t2[nnd - 1] = tlu;
/* SOURCE brnmat.for:1305 */
/*<       a2(nnd)=alu >*/
	    bnelem_1.a2[nnd - 1] = alu;
/* SOURCE brnmat.for:1306 */
/*<       b2(nnd)=blu >*/
	    bnelem_1.b2[nnd - 1] = blu;
/* SOURCE brnmat.for:1307 */
/*<       k2(nnd)=klu >*/
	    bnelem_1.k2[nnd - 1] = klu;
/* SOURCE brnmat.for:1308 */
/*<       ma2(nnd)=malu >*/
	    bnelem_1.ma2[nnd - 1] = malu;
/* SOURCE brnmat.for:1309 */
/*<       mq2(nnd)=mqlu >*/
	    bnelem_1.mq2[nnd - 1] = mqlu;
/* SOURCE brnmat.for:1310 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1311 */
/*<       newsum=qlu+qru >*/
	newsum = static_cast<double>(qlu) + qru;
/* SOURCE brnmat.for:1312 */
/*<       newmom=mqlu*qlu+mqru*qru >*/
	newmom = static_cast<double>(static_cast<double>(mqlu) * qlu) + static_cast<double>(mqru) * qru;
/* SOURCE brnmat.for:1313 */
/*<       if(newsum.lt.0.0)then >*/
	if (newsum < (float)0.) {
/* SOURCE brnmat.for:1314 */
/*<       wa=1.-wa >*/
	    wa = static_cast<double>((float)1.) - wa;
/* SOURCE brnmat.for:1315 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1316 */
/*<       dy=yru-ylu >*/
	dy = static_cast<double>(yru) - ylu;
/*         SELECT NEW VALUE OF WX. */
/* SOURCE brnmat.for:1318 */
/*<       kmu=0.5*(klu+kru) >*/
	kmu = static_cast<double>((static_cast<double>(klu) + kru)) * (float).5;
/* SOURCE brnmat.for:1319 */
/*<       if(newsum.ge.0.0)then >*/
	if (newsum >= (float)0.) {
/*           FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT. */
/*            WRITE(STD6,*) ' CRITERION=',DKRU*(-DY - DZ) - KMU */
/*            WRITE(STD6,*) ' DKRU=',DKRU,'DY+DZ=',DY+DZ,' KMU=',KMU */
/* SOURCE brnmat.for:1323 */
/*<       if(dkru*(-dy-dz)-kmu.ge.0.0)then >*/
	    if (static_cast<double>(static_cast<double>(dkru) * (static_cast<double>(-dy) - dz)) - kmu >= (float)0.) {
/*             SHIFT TO UPSTREAM CONVEYANCE. */
/* SOURCE brnmat.for:1325 */
/*<       wx=0.4*klu/(dkru*(-dy-dz)-0.5*(kru-klu)) >*/
		wx = static_cast<double>(static_cast<double>(klu) * (float).4) / (static_cast<double>(static_cast<double>(dkru) * (static_cast<double>(-dy) - dz)) - static_cast<double>((static_cast<double>(kru) - klu)) * (
			float).5);
/* SOURCE brnmat.for:1326 */
/*<       kmu=klu+wx*(kru-klu) >*/
		kmu = static_cast<double>(klu) + static_cast<double>(wx) * (static_cast<double>(kru) - klu);
/* SOURCE brnmat.for:1327 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1328 */
/*<       wx=0.5 >*/
		wx = (float).5;
/* SOURCE brnmat.for:1329 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1330 */
/*<       else >*/
	} else {
/*           FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT. */
/* SOURCE brnmat.for:1332 */
/*<       if(dklu*(dy+dz)-kmu.ge.0.0)then >*/
	    if (static_cast<double>(static_cast<double>(dklu) * (static_cast<double>(dy) + dz)) - kmu >= (float)0.) {
/*             SHIFT TO UPSTREAM CONVEYANCE */
/* SOURCE brnmat.for:1334 */
/*<       wx=1.0-0.4*kru/(dklu*(dy+dz)-.5*(kru-klu)) >*/
		wx = static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(kru) * (float).4) / (static_cast<double>(static_cast<double>(dklu) * (static_cast<double>(dy) + dz)) - static_cast<double>((static_cast<double>(kru) - 
			klu)) * (float).5);
/* SOURCE brnmat.for:1335 */
/*<       kmu=klu+wx*(kru-klu) >*/
		kmu = static_cast<double>(klu) + static_cast<double>(wx) * (static_cast<double>(kru) - klu);
/* SOURCE brnmat.for:1336 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1337 */
/*<       wx=0.5 >*/
		wx = (float).5;
/* SOURCE brnmat.for:1338 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1339 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1341 */
/*<       amu=alu+wa*(aru-alu) >*/
	amu = static_cast<double>(alu) + static_cast<double>(wa) * (static_cast<double>(aru) - alu);
/* SOURCE brnmat.for:1342 */
/*<       newvol=(1.-wa)*malu*alu+wa*maru*aru >*/
	newvol = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - wa)) * malu) * alu) + static_cast<double>(static_cast<double>(wa) * maru) * aru;
/* SOURCE brnmat.for:1343 */
/*<       wxvec(elmadr)=wx >*/
	bnelem_1.wxvec[elmadr - 1] = wx;
/* SOURCE brnmat.for:1344 */
/*<       ksum=kmu+kmu >*/
	ksum = static_cast<double>(kmu) + kmu;
/*          IF(STFLAG.EQ.0) */
/*     A     WRITE(STD6,'(6H RDVAL,6F10.3)') YRD, TRD, ARD, KRD, BRD, QRD */
/*        WRITE(STD6,'(6H RUVAL,7F10.3)') YRU, TRU, ARU, KRU, BRU, QRU, DKRU */
/*         SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL. */
/* SOURCE brnmat.for:1351 */
/*<       if(ylu.lt.ziy.or.yru.lt.ziy)then >*/
	if (ylu < ziy || yru < ziy) {
/* SOURCE brnmat.for:1352 */
/*<       zi=0.0 >*/
	    zi = (float)0.;
/* SOURCE brnmat.for:1353 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1354 */
/*<       zi=zit >*/
	    zi = zit;
/* SOURCE brnmat.for:1355 */
/*<       endif >*/
	}
/*         CONTINUITY EQUATION */
/*         1) PARTIAL DERIVATIVES */
/*          WRITE(STD6,*) ' DXHDT=',DXHDT,' TLU=',TLU,' TRU=',TRU */
/* SOURCE brnmat.for:1361 */
/*<       c1=dxdt*(1.-wa)*(malu*tlu+alu*dmalu) >*/
	c1 = static_cast<double>(static_cast<double>(dxdt) * (static_cast<double>((float)1.) - wa)) * (static_cast<double>(static_cast<double>(malu) * tlu) + static_cast<double>(alu) * dmalu);
/* SOURCE brnmat.for:1362 */
/*<       c2=-wt >*/
	c2 = -(*wt);
/* SOURCE brnmat.for:1363 */
/*<       c3=dxdt*(wa)*(maru*tru+aru*dmaru) >*/
	c3 = static_cast<double>(static_cast<double>(dxdt) * wa) * (static_cast<double>(static_cast<double>(maru) * tru) + static_cast<double>(aru) * dmaru);
/* SOURCE brnmat.for:1364 */
/*<       c4=wt >*/
	c4 = *wt;
/* SOURCE brnmat.for:1366 */
/*<       qp=qpvec(elmadr) >*/
	qp = bnothr_1.qpvec[elmadr - 1];
/* SOURCE brnmat.for:1367 */
/*<       cf=coefin(elmadr) >*/
	cf = bnpond_1.coefin[elmadr - 1];
/* SOURCE brnmat.for:1368 */
/*<       if(cf.gt.0.0)then >*/
	if (cf > (float)0.) {
/*            PROCESS INFLOW RESTRICTION ON SEWERS */
/* SOURCE brnmat.for:1372 */
/*<       yc=ycut(elmadr) >*/
	    yc = bnpond_1.ycut[elmadr - 1];
/* SOURCE brnmat.for:1373 */
/*<       s1=pond1(elmadr) >*/
	    s1 = bnpond_1.pond1[elmadr - 1];
/* SOURCE brnmat.for:1374 */
/*<       s2=pond2(elmadr) >*/
	    s2 = bnpond_1.pond2[elmadr - 1];
/* SOURCE brnmat.for:1375 */
/*<       ym=0.5*((ylu+yru)) >*/
	    ym = static_cast<double>((static_cast<double>(ylu) + yru)) * (float).5;
/* SOURCE brnmat.for:1376 */
/*<       dh=yc-ym >*/
	    dh = static_cast<double>(yc) - ym;
/* SOURCE brnmat.for:1377 */
/*<       if(abs(dh).le.dhstar)then >*/
	    if (dabs(dh) <= miscon_1.dhstar) {
/* SOURCE brnmat.for:1378 */
/*<       qmax=dh*cf*qpcon >*/
		qmax = static_cast<double>(static_cast<double>(dh) * cf) * miscon_1.qpcon;
/* SOURCE brnmat.for:1379 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1380 */
/*<       qmax=cf*sqrt(twog*abs(dh)) >*/
		qmax = cf * sqrt(gravcm_1.twog * dabs(dh));
/* SOURCE brnmat.for:1381 */
/*<       if(dh.lt.0.0)qmax=-qmax >*/
		if (dh < (float)0.) {
		    qmax = -qmax;
		}
/* SOURCE brnmat.for:1382 */
/*<       endif >*/
	    }
/*            CHECK FOR FLOW ALLOWED */
/* SOURCE brnmat.for:1386 */
/*<       tp=qp+s1/dt >*/
	    tp = qp + s1 / *dt;
/* SOURCE brnmat.for:1387 */
/*<       if(qmax.gt.tp)then >*/
	    if (qmax > tp) {
/* SOURCE brnmat.for:1388 */
/*<       pond2(elmadr)=0.0 >*/
		bnpond_1.pond2[elmadr - 1] = (float)0.;
/* SOURCE brnmat.for:1389 */
/*<       qp=tp >*/
		qp = tp;
/* SOURCE brnmat.for:1390 */
/*<       dqpylu=0.0 >*/
		dqpylu = (float)0.;
/* SOURCE brnmat.for:1391 */
/*<       dqpyru=0.0 >*/
		dqpyru = (float)0.;
/* SOURCE brnmat.for:1392 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1393 */
/*<       s3=s1+dt*(qp-qmax) >*/
		s3 = s1 + *dt * (static_cast<double>(qp) - qmax);
/* SOURCE brnmat.for:1394 */
/*<       b=abs(s2-s3)/(dx*oldvol) >*/
		b = (feq_gen_r_d_1 = static_cast<double>(s2) - s3, dabs(feq_gen_r_d_1)) / (static_cast<double>(dx) * oldvol);
/* SOURCE brnmat.for:1395 */
/*<       if(b.gt.errp)then >*/
		if (b > *errp) {
/* SOURCE brnmat.for:1396 */
/*<       errp=b >*/
		    *errp = b;
/* SOURCE brnmat.for:1397 */
/*<       nerrp=ubnbas+nnd-fn >*/
		    *nerrp = ubnbas + nnd - fn;
/* SOURCE brnmat.for:1398 */
/*<       berrp=nbr >*/
		    *berrp = *nbr;
/* SOURCE brnmat.for:1399 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:1400 */
/*<       pond2(elmadr)=s3 >*/
		bnpond_1.pond2[elmadr - 1] = s3;
/* SOURCE brnmat.for:1401 */
/*<       qp=qmax >*/
		qp = qmax;
/* SOURCE brnmat.for:1402 */
/*<       if(abs(dh).le.dhstar)then >*/
		if (dabs(dh) <= miscon_1.dhstar) {
/* SOURCE brnmat.for:1403 */
/*<       dqpylu=-0.5*cf*qpcon >*/
		    dqpylu = static_cast<double>(static_cast<double>(cf) * (float)-.5) * miscon_1.qpcon;
/* SOURCE brnmat.for:1404 */
/*<       dqpyru=dqpylu >*/
		    dqpyru = dqpylu;
/* SOURCE brnmat.for:1405 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:1406 */
/*<       dqpylu=-halfg*cf*cf/abs(qp) >*/
		    dqpylu = static_cast<double>(static_cast<double>(-gravcm_1.halfg) * cf) * cf / dabs(qp);
/* SOURCE brnmat.for:1407 */
/*<       dqpyru=dqpylu >*/
		    dqpyru = dqpylu;
/* SOURCE brnmat.for:1408 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:1409 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1410 */
/*<       c1=c1-dqpylu >*/
	    c1 -= dqpylu;
/* SOURCE brnmat.for:1411 */
/*<       c3=c3-dqpyru >*/
	    c3 -= dqpyru;
/* SOURCE brnmat.for:1413 */
/*<       endif >*/
	}
/*         2) RESIDUAL */
/* SOURCE brnmat.for:1416 */
/*<       ieq=ieq+1 >*/
	++(*ieq);
/* SOURCE brnmat.for:1418 */
/*<       dyndif=oldflw+wt*(qru-qlu-oldflw)-qp >*/
	dyndif = static_cast<double>(static_cast<double>(oldflw) + static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(qru) - qlu) - oldflw)) - qp;
/* SOURCE brnmat.for:1419 */
/*<       res=-((newvol-oldvol)*dxdt+dyndif) >*/
	res = -(static_cast<double>(static_cast<double>((static_cast<double>(newvol) - oldvol)) * dxdt) + dyndif);
/*        WRITE(STD6,1932) C2, C1, C4, C3, -RES */
/*        RESCALE THE CURRENT EQUATION */
/*        CMAX = 1.0/MAX(ABS(C1), ABS(C2), ABS(C3), ABS(C4)) */
/*         JCOL GIVES THE VARIABLE NUMBER AT THE FIRST COEFFICIENT IN */
/*         THE EQUATIONS. */
/* SOURCE brnmat.for:1430 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:1431 */
/*<       pdavec(r(ieq))=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c2;
/* SOURCE brnmat.for:1432 */
/*<       pdavec(c(jcol+1))=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 1] - 1] = c1;
/* SOURCE brnmat.for:1433 */
/*<       pdavec(c(jcol+2)-1)=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 2] = c4;
/* SOURCE brnmat.for:1434 */
/*<       pdavec(c(jcol+3)-2)=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 3] = c3;
/* SOURCE brnmat.for:1435 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1436 */
/*<       pdavec(r(ieq))=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c4;
/* SOURCE brnmat.for:1437 */
/*<       pdavec(c(jcol+1))=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 1] - 1] = c3;
/* SOURCE brnmat.for:1438 */
/*<       pdavec(c(jcol+2)-1)=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 2] = c2;
/* SOURCE brnmat.for:1439 */
/*<       pdavec(c(jcol+3)-2)=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 3] = c1;
/* SOURCE brnmat.for:1440 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1442 */
/*<       rhs(ieq)=res >*/
	matcom_1.rhs[*ieq - 1] = res;
/* SOURCE brnmat.for:1445 */
/*<       err=abs(qp)/(abs(0.5*oldsum)+0.1) >*/
	err = dabs(qp) / ((feq_gen_r_d_1 = static_cast<double>(oldsum) * (float).5, dabs(feq_gen_r_d_1)) + (float).1)
		;
/* SOURCE brnmat.for:1446 */
/*<       if(err.gt.errq)then >*/
	if (err > *errq) {
/* SOURCE brnmat.for:1447 */
/*<       errq=err >*/
	    *errq = err;
/* SOURCE brnmat.for:1448 */
/*<       berrq=nbr >*/
	    *berrq = *nbr;
/* SOURCE brnmat.for:1449 */
/*<       nerrq=ubnbas+nnd-fn >*/
	    *nerrq = ubnbas + nnd - fn;
/* SOURCE brnmat.for:1450 */
/*<       endif >*/
	}
/*       MOMENTUM EQUATION */
/* SOURCE brnmat.for:1454 */
/*<       sfmt=abs(newsum)/ksum**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ksum;
	sfmt = dabs(newsum) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:1455 */
/*<       sfmu=newsum*sfmt >*/
	sfmu = static_cast<double>(newsum) * sfmt;
/*        WRITE(STD6,*) ' SFMU=', SFMU */
/* SOURCE brnmat.for:1457 */
/*<       pgfu=grav*(dz+sfmu*dx+dy) >*/
	pgfu = static_cast<double>(gravcm_1.grav) * (static_cast<double>(static_cast<double>(dz) + static_cast<double>(sfmu) * dx) + dy);
/* SOURCE brnmat.for:1458 */
/*<       vlu=qlu/alu >*/
	vlu = static_cast<double>(qlu) / alu;
/* SOURCE brnmat.for:1459 */
/*<       vru=qru/aru >*/
	vru = static_cast<double>(qru) / aru;
/* SOURCE brnmat.for:1460 */
/*<       tpa=(dx2+dx2)*sfmu/ksum >*/
	tpa = static_cast<double>(static_cast<double>((static_cast<double>(dx2) + dx2)) * sfmu) / ksum;
/* SOURCE brnmat.for:1461 */
/*<       tpb=amu*grav*dx2*sfmt >*/
	tpb = static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * dx2) * sfmt;
/*       PARTIAL DERIVATIVES */
/* SOURCE brnmat.for:1465 */
/*<        >*/
	c1 = static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * (static_cast<double>(static_cast<double>(static_cast<double>(-tpa) * dklu) * (static_cast<double>((float)1.) - wx)) - (
		float)1.)) + static_cast<double>(static_cast<double>(pgfu) * (static_cast<double>((float)1.) - wa)) * tlu) - static_cast<double>(zi) * (static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(dblu) * qlu) 
		- static_cast<double>(static_cast<double>(tlu) * blu) * vlu)) * vlu) - static_cast<double>(static_cast<double>(dxhdt) * qlu) * dmqlu));
/* SOURCE brnmat.for:1471 */
/*<       c2=zi*mqlu*dxhdt+wt*(tpb-2.*zi*blu*vlu) >*/
	c2 = static_cast<double>(static_cast<double>(static_cast<double>(zi) * mqlu) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(tpb) - static_cast<double>(static_cast<double>(static_cast<double>(zi) * (float)2.) * blu) * vlu);
/* SOURCE brnmat.for:1474 */
/*<        >*/
	c3 = static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * (static_cast<double>(static_cast<double>(static_cast<double>(-tpa) * dkru) * wx) + (float)1.)) + 
		static_cast<double>(static_cast<double>(pgfu) * wa) * tru) + static_cast<double>(zi) * (static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(dbru) * qru) - static_cast<double>(static_cast<double>(tru) * bru) * vru)) * vru) 
		+ static_cast<double>(static_cast<double>(dxhdt) * qru) * dmqru));
/* SOURCE brnmat.for:1479 */
/*<       c4=zi*mqru*dxhdt+wt*(tpb+2.*zi*bru*vru) >*/
	c4 = static_cast<double>(static_cast<double>(static_cast<double>(zi) * mqru) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(tpb) + static_cast<double>(static_cast<double>(static_cast<double>(zi) * (float)2.) * bru) * vru);
/* SOURCE brnmat.for:1482 */
/*<       if(kdc.gt.0.0.or.kac.gt.0.0)then >*/
	if (kdc > (float)0. || kac > (float)0.) {
/*         PROCESS EXPANSION AND CONTRACTION LOSSES */
/* SOURCE brnmat.for:1484 */
/*<       dv2=(vru-vlu)*(vru+vlu) >*/
	    dv2 = static_cast<double>((static_cast<double>(vru) - vlu)) * (static_cast<double>(vru) + vlu);
/*         Establish the sign of the difference in */
/*         the squared velocities. */
/* SOURCE brnmat.for:1487 */
/*<       sgndv2=sign(1.0,dv2) >*/
	    sgndv2 = r_sign(&c_b107, &dv2);
/*         Absolute value of difference of squares is */
/*         needed as well. */
/* SOURCE brnmat.for:1490 */
/*<       dv2=abs(dv2) >*/
	    dv2 = dabs(dv2);
/* SOURCE brnmat.for:1491 */
/*<       if(vlu.ge.vru)then >*/
	    if (vlu >= vru) {
/*           FLOW IS UNDERGOING NEGATIVE ACCELERATION */
/*            idir = -1 */
/* SOURCE brnmat.for:1494 */
/*<       kp=sign(kdc,newsum) >*/
		kp = r_sign(&kdc, &newsum);
/* SOURCE brnmat.for:1495 */
/*<       else >*/
	    } else {
/*           FLOW IS UNDERGOING POSITIVE ACCELERATION */
/*            idir = +1 */
/* SOURCE brnmat.for:1498 */
/*<       kp=sign(kac,newsum) >*/
		kp = r_sign(&kac, &newsum);
/* SOURCE brnmat.for:1499 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1501 */
/*<       pfqlu=-kp*sgndv2*amu*vlu/alu >*/
	    pfqlu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(-kp) * sgndv2) * amu) * vlu) / alu;
/* SOURCE brnmat.for:1502 */
/*<       pfqru=kp*sgndv2*amu*vru/aru >*/
	    pfqru = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(kp) * sgndv2) * amu) * vru) / aru;
/* SOURCE brnmat.for:1503 */
/*<       pfylu=tlu*(0.25*kp*dv2-pfqlu*vlu) >*/
	    pfylu = static_cast<double>(tlu) * (static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).25) * dv2) - static_cast<double>(pfqlu) * vlu);
/* SOURCE brnmat.for:1504 */
/*<       pfyru=tru*(0.25*kp*dv2-pfqru*vru) >*/
	    pfyru = static_cast<double>(tru) * (static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).25) * dv2) - static_cast<double>(pfqru) * vru);
/* SOURCE brnmat.for:1505 */
/*<       gde=0.5*kp*dv2 >*/
	    gde = static_cast<double>(static_cast<double>(kp) * (float).5) * dv2;
/* SOURCE brnmat.for:1507 */
/*<       pgfu=pgfu+gde >*/
	    pgfu += gde;
/* SOURCE brnmat.for:1508 */
/*<       c1=c1+wt*pfylu >*/
	    c1 += static_cast<double>(*wt) * pfylu;
/* SOURCE brnmat.for:1509 */
/*<       c2=c2+wt*pfqlu >*/
	    c2 += static_cast<double>(*wt) * pfqlu;
/* SOURCE brnmat.for:1510 */
/*<       c3=c3+wt*pfyru >*/
	    c3 += static_cast<double>(*wt) * pfyru;
/* SOURCE brnmat.for:1511 */
/*<       c4=c4+wt*pfqru >*/
	    c4 += static_cast<double>(*wt) * pfqru;
/* SOURCE brnmat.for:1513 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1515 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/*         POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT */
/* SOURCE brnmat.for:1517 */
/*<       ym=0.5*(ylu+yru) >*/
	    ym = static_cast<double>((static_cast<double>(ylu) + yru)) * (float).5;
/* SOURCE brnmat.for:1518 */
/*<       calllktab(adrs,ym,0,khlm,ntab,dkhlm) >*/
	    lktab_(&adrs, &ym, &feq_gen_c_d_0, &khlm, &ntab, &dkhlm);
/* SOURCE brnmat.for:1521 */
/*<       if(newsum.lt.0.0)then >*/
	    if (newsum < (float)0.) {
/* SOURCE brnmat.for:1522 */
/*<       khlm=-khlm >*/
		khlm = -khlm;
/* SOURCE brnmat.for:1523 */
/*<       dkhlm=-dkhlm >*/
		dkhlm = -dkhlm;
/* SOURCE brnmat.for:1524 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1526 */
/*<       tpa=newsum/(alu+aru)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(alu) + aru;
	    tpa = static_cast<double>(newsum) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:1527 */
/*<       tpb=tpa*newsum >*/
	    tpb = static_cast<double>(tpa) * newsum;
/* SOURCE brnmat.for:1528 */
/*<       gde=0.5*khlm*tpb >*/
	    gde = static_cast<double>(static_cast<double>(khlm) * (float).5) * tpb;
/* SOURCE brnmat.for:1529 */
/*<       pgfu=pgfu+gde >*/
	    pgfu += gde;
/* SOURCE brnmat.for:1530 */
/*<       tpc=wt*amu >*/
	    tpc = static_cast<double>(*wt) * amu;
/* SOURCE brnmat.for:1531 */
/*<       tpd=khlm*tpa >*/
	    tpd = static_cast<double>(khlm) * tpa;
/* SOURCE brnmat.for:1533 */
/*<       c1=c1-tpc*(tpd*tlu-dkhlm*tpb) >*/
	    c1 -= static_cast<double>(tpc) * (static_cast<double>(static_cast<double>(tpd) * tlu) - static_cast<double>(dkhlm) * tpb);
/* SOURCE brnmat.for:1534 */
/*<       c2=c2+tpc*tpd >*/
	    c2 += static_cast<double>(tpc) * tpd;
/* SOURCE brnmat.for:1535 */
/*<       c3=c3-tpc*(tpd*tru-dkhlm*tpb) >*/
	    c3 -= static_cast<double>(tpc) * (static_cast<double>(static_cast<double>(tpd) * tru) - static_cast<double>(dkhlm) * tpb);
/* SOURCE brnmat.for:1536 */
/*<       c4=c4+tpc*tpd >*/
	    c4 += static_cast<double>(tpc) * tpd;
/* SOURCE brnmat.for:1537 */
/*<       endif >*/
	}
/*        IF(C1.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C1=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C2.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C2=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C3.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C3=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C4.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C4=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*       RESIDUAL */
/* SOURCE brnmat.for:1559 */
/*<        >*/
	res = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(zi) * (static_cast<double>(newmom) - oldmom)) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(pgfu) * amu) + static_cast<double>(zi) * (static_cast<double>(static_cast<double>(static_cast<double>(bru) *
		 qru) * vru) - static_cast<double>(static_cast<double>(blu) * qlu) * vlu))) + static_cast<double>(wtc) * oldimp) - oldwnd;
/* SOURCE brnmat.for:1562 */
/*<       ieq=ieq+1 >*/
	++(*ieq);
/*        WRITE(STD6,1932) C2, C1, C4, C3, RES */
/* 1932    FORMAT(1X,5(1PE11.3)) */
/*         RESCALE THE CURRENT EQUATION */
/*          CMAX = 1.0/MAX(ABS(C1), ABS(C2), ABS(C3), ABS(C4)) */
/* SOURCE brnmat.for:1573 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:1574 */
/*<       pdavec(r(ieq)-1)=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 2] = c2;
/* SOURCE brnmat.for:1575 */
/*<       pdavec(r(ieq))=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c1;
/* SOURCE brnmat.for:1576 */
/*<       pdavec(c(jcol+2))=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 1] = c4;
/* SOURCE brnmat.for:1577 */
/*<       pdavec(c(jcol+3)-1)=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 2] = c3;
/* SOURCE brnmat.for:1578 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1579 */
/*<       pdavec(r(ieq)-1)=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 2] = c4;
/* SOURCE brnmat.for:1580 */
/*<       pdavec(r(ieq))=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c3;
/* SOURCE brnmat.for:1581 */
/*<       pdavec(c(jcol+2))=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 1] = c2;
/* SOURCE brnmat.for:1582 */
/*<       pdavec(c(jcol+3)-1)=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 2] = c1;
/* SOURCE brnmat.for:1583 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1585 */
/*<       rhs(ieq)=-res >*/
	matcom_1.rhs[*ieq - 1] = -res;
/*         TRANSFER VALUES */
/* SOURCE brnmat.for:1589 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:1590 */
/*<       qlu=qru >*/
	    qlu = qru;
/* SOURCE brnmat.for:1591 */
/*<       alu=aru >*/
	    alu = aru;
/* SOURCE brnmat.for:1592 */
/*<       tlu=tru >*/
	    tlu = tru;
/* SOURCE brnmat.for:1593 */
/*<       ylu=yru >*/
	    ylu = yru;
/* SOURCE brnmat.for:1594 */
/*<       klu=kru >*/
	    klu = kru;
/* SOURCE brnmat.for:1595 */
/*<       dklu=dkru >*/
	    dklu = dkru;
/* SOURCE brnmat.for:1596 */
/*<       blu=bru >*/
	    blu = bru;
/* SOURCE brnmat.for:1597 */
/*<       dblu=dbru >*/
	    dblu = dbru;
/* SOURCE brnmat.for:1598 */
/*<       malu=maru >*/
	    malu = maru;
/* SOURCE brnmat.for:1599 */
/*<       mqlu=mqru >*/
	    mqlu = mqru;
/* SOURCE brnmat.for:1600 */
/*<       dmalu=dmaru >*/
	    dmalu = dmaru;
/* SOURCE brnmat.for:1601 */
/*<       dmqlu=dmqru >*/
	    dmqlu = dmqru;
/* SOURCE brnmat.for:1602 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1603 */
/*<       qru=qlu >*/
	    qru = qlu;
/* SOURCE brnmat.for:1604 */
/*<       aru=alu >*/
	    aru = alu;
/* SOURCE brnmat.for:1605 */
/*<       tru=tlu >*/
	    tru = tlu;
/* SOURCE brnmat.for:1606 */
/*<       yru=ylu >*/
	    yru = ylu;
/* SOURCE brnmat.for:1607 */
/*<       kru=klu >*/
	    kru = klu;
/* SOURCE brnmat.for:1608 */
/*<       dkru=dklu >*/
	    dkru = dklu;
/* SOURCE brnmat.for:1609 */
/*<       bru=blu >*/
	    bru = blu;
/* SOURCE brnmat.for:1610 */
/*<       dbru=dblu >*/
	    dbru = dblu;
/* SOURCE brnmat.for:1611 */
/*<       maru=malu >*/
	    maru = malu;
/* SOURCE brnmat.for:1612 */
/*<       mqru=mqlu >*/
	    mqru = mqlu;
/* SOURCE brnmat.for:1613 */
/*<       dmaru=dmalu >*/
	    dmaru = dmalu;
/* SOURCE brnmat.for:1614 */
/*<       dmqru=dmqlu >*/
	    dmqru = dmqlu;
/* SOURCE brnmat.for:1615 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1616 */
/*<       jcol=jcol+2 >*/
	jcol += 2;
/* SOURCE brnmat.for:1618 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE brnmat.for:1621 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:1622 */
/*<       end >*/
} /* seticw_ */




/* SOURCE brnmat.for:1626 */
/*<        >*/
/* Subroutine */ int seticx_(doublereal *dt, integer *nbr, integer *nbra, 
	real *wt, integer *feq_storage_brpt, integer *ieq, real *errp, real *errq, 
	integer *berrp, integer *nerrp, integer *berrq, integer *nerrq)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;

    /* Builtin functions */
    double r_sign(real *, real *), sqrt(doublereal);

    /* Local variables */
    real b, c1, c2, c3, c4, s1, s2, s3, cf, dh;
    integer fn, ln;
    real dv, dx, dz, qp, yc, zi, tp, kp, ym, wx, dv2, dx2, kac, gde, ald, amd,
	     bld, kdc, ard, brd, kld, kmd;
    integer nnd;
    real alu, amu, blu, dxh, aru, bru, err, krd, klu, kmu, dyt, kru, qld, qlu,
	     qrd, res, qru, tld, tlu, tpa, tpb, tpc, tpd, trd, tru, vld, vlu, 
	    vrd, vru, wtc, yld, ylu, yrd, yru, zit, ziy, mald, mard;
    integer ntab, jcol, adrs, ninc;
    real dblu, dbru, dklu, dkru, dtlu, dtru, dxdt, khlm, ksum, malu, maru, 
	    mqld, mqlu, mqrd, mqru, pgfu, qmax, sfmt, sfmu, dkhlm, dmalu, 
	    dmaru, dmqlu, dmqru, dxhdt, pfqlu, pfqru, pfylu, pfyru;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *), xlkt23_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real sgndv2;
    integer elmadr, ubnbas;
    real dqpylu, dqpyru, dyndif, newmom, newsum, newvol, oldflw, oldimp, 
	    oldmom, oldsum, oldvol, oldwnd;

/*     + + + PURPOSE + + + */
/*     Create the portion of the matrix corresponding to the */
/*     given branch number, NBR. IEQ gives the last equation created */
/*     in the matrix.  Used only for branches which have 2 unknowns */
/*     per node.  This routine uses the curvilinear elements MA and MQ. */
/*     Otherwise it is the same as SETINX. */
/* SOURCE brnmat.for:1638 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE brnmat.for:1640 */
/*<       integerberrp,berrq,ieq,nbr,nbra,nerrp,nerrq >*/
/* SOURCE brnmat.for:1641 */
/*<       integerbrpt(8,nbra) >*/
/* SOURCE brnmat.for:1642 */
/*<       realerrp,errq,wt >*/
/* SOURCE brnmat.for:1643 */
/*<       real*8dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     NBR    - number of the branch being processed */
/*     NBRA   - number of branches in the model */
/*     WT     - weight factor for approximating time integrals */
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
/*     IEQ    - equation number */
/*     ERRP   - current maximum relative change in surcharge storage */
/*     ERRQ   - maximum value of the ratio of lateral inflow to the */
/*               average flow in the element */
/*     BERRP  - records the branch number(internal) that has the */
/*               greatest absolute value of the change in surcharge */
/*               storage relative to the storage in the storm sewer */
/*     NERRP  - node at which maximum correction to surcharge storage */
/*               occurs */
/*     BERRQ  - records the branch number(internal) that has the */
/*               greatest value of the ratio of lateral inflow */
/*               to average flow in an element */
/*     NERRQ  - node at which maximum relative lateral inflow occurs */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE brnmat.for:1675 */
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
/* INCLUDE brnmat.for:1676 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE brnmat.for:1677 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:1678 */
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
/* INCLUDE brnmat.for:1679 */
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
/* INCLUDE brnmat.for:1680 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:1681 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:1682 */
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
/* INCLUDE brnmat.for:1683 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:1686 */
/*<       integeradrs,elmadr,fn,jcol,ln,ninc,nnd,ntab,ubnbas,stdout,idir >*/
/* SOURCE brnmat.for:1688 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE brnmat.for:1701 */
/*<       intrinsicabs,sign,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE brnmat.for:1704 */
/*<       externallktab,xlkt23 >*/
/* *********************************************************************** */
/* SOURCE brnmat.for:1706 */
/*<       wtc=1.0-wt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
    wtc = static_cast<double>((float)1.) - *wt;
/* SOURCE brnmat.for:1707 */
/*<       wx=0.5 >*/
    wx = (float).5;
/*     SET THE DIRECTION OF PROCESSING FOR THIS BRANCH.  THE SIGN OF THE */
/*     VARIABLE NUMBER FOR THE FIRST VARIABLE ON THE BRANCH SETS THE */
/*     DIRECTION */
/* SOURCE brnmat.for:1713 */
/*<       jcol=brpt(7,nbr) >*/
    jcol = brpt[(*nbr << 3) + 7];
/* SOURCE brnmat.for:1714 */
/*<       if(jcol.gt.0)then >*/
    if (jcol > 0) {
/* SOURCE brnmat.for:1715 */
/*<       fn=brpt(3,nbr) >*/
	fn = brpt[(*nbr << 3) + 3];
/* SOURCE brnmat.for:1716 */
/*<       ln=brpt(4,nbr) >*/
	ln = brpt[(*nbr << 3) + 4];
/* SOURCE brnmat.for:1717 */
/*<       ninc=1 >*/
	ninc = 1;
/*       SET THE USER BRANCH NODE BASE FOR REPORTING NERRQ AND NERRP */
/* SOURCE brnmat.for:1719 */
/*<       ubnbas=brpt(1,nbr)+1 >*/
	ubnbas = brpt[(*nbr << 3) + 1] + 1;
/* SOURCE brnmat.for:1720 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:1721 */
/*<       fn=brpt(4,nbr) >*/
	fn = brpt[(*nbr << 3) + 4];
/* SOURCE brnmat.for:1722 */
/*<       ln=brpt(3,nbr) >*/
	ln = brpt[(*nbr << 3) + 3];
/* SOURCE brnmat.for:1723 */
/*<       ninc=-1 >*/
	ninc = -1;
/* SOURCE brnmat.for:1724 */
/*<       jcol=-jcol >*/
	jcol = -jcol;
/* SOURCE brnmat.for:1725 */
/*<       ubnbas=brpt(2,nbr) >*/
	ubnbas = brpt[(*nbr << 3) + 2];
/* SOURCE brnmat.for:1726 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:1728 */
/*<       zi=zivec(nbr) >*/
    zi = bnothr_1.zivec[*nbr - 1];
/* SOURCE brnmat.for:1729 */
/*<       zit=zi >*/
    zit = zi;
/* SOURCE brnmat.for:1730 */
/*<       ziy=zilim(nbr) >*/
    ziy = bnothr_1.zilim[*nbr - 1];
/* SOURCE brnmat.for:1731 */
/*<       if(stflag.eq.0)then >*/
    if (bnelem_1.stflag == 0) {
/* SOURCE brnmat.for:1732 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:1733 */
/*<       tld=t1(fn) >*/
	    tld = bnelem_1.t1[fn - 1];
/* SOURCE brnmat.for:1734 */
/*<       ald=a1(fn) >*/
	    ald = bnelem_1.a1[fn - 1];
/* SOURCE brnmat.for:1735 */
/*<       yld=y1(fn) >*/
	    yld = bnelem_1.y1[fn - 1];
/* SOURCE brnmat.for:1736 */
/*<       bld=b1(fn) >*/
	    bld = bnelem_1.b1[fn - 1];
/* SOURCE brnmat.for:1737 */
/*<       qld=q1(fn) >*/
	    qld = bnelem_1.q1[fn - 1];
/* SOURCE brnmat.for:1738 */
/*<       kld=k1(fn) >*/
	    kld = bnelem_1.k1[fn - 1];
/* SOURCE brnmat.for:1739 */
/*<       mald=ma1(fn) >*/
	    mald = bnelem_1.ma1[fn - 1];
/* SOURCE brnmat.for:1740 */
/*<       mqld=mq1(fn) >*/
	    mqld = bnelem_1.mq1[fn - 1];
/* SOURCE brnmat.for:1741 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1742 */
/*<       trd=t1(fn) >*/
	    trd = bnelem_1.t1[fn - 1];
/* SOURCE brnmat.for:1743 */
/*<       ard=a1(fn) >*/
	    ard = bnelem_1.a1[fn - 1];
/* SOURCE brnmat.for:1744 */
/*<       yrd=y1(fn) >*/
	    yrd = bnelem_1.y1[fn - 1];
/* SOURCE brnmat.for:1745 */
/*<       brd=b1(fn) >*/
	    brd = bnelem_1.b1[fn - 1];
/* SOURCE brnmat.for:1746 */
/*<       qrd=q1(fn) >*/
	    qrd = bnelem_1.q1[fn - 1];
/* SOURCE brnmat.for:1747 */
/*<       krd=k1(fn) >*/
	    krd = bnelem_1.k1[fn - 1];
/* SOURCE brnmat.for:1748 */
/*<       mard=ma1(fn) >*/
	    mard = bnelem_1.ma1[fn - 1];
/* SOURCE brnmat.for:1749 */
/*<       mqrd=mq1(fn) >*/
	    mqrd = bnelem_1.mq1[fn - 1];
/* SOURCE brnmat.for:1750 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1751 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:1753 */
/*<       if(ninc.gt.0)then >*/
    if (ninc > 0) {
/* SOURCE brnmat.for:1754 */
/*<       qlu=q2(fn) >*/
	qlu = bnelem_1.q2[fn - 1];
/* SOURCE brnmat.for:1755 */
/*<       ylu=y2(fn) >*/
	ylu = bnelem_1.y2[fn - 1];
/* SOURCE brnmat.for:1756 */
/*<        >*/
	xlkt23_(&bnothr_1.nsec[fn - 1], &ylu, &alu, &tlu, &dtlu, &klu, &dklu, 
		&blu, &dblu, &malu, &dmalu, &mqlu, &dmqlu);
/* SOURCE brnmat.for:1761 */
/*<       t2(fn)=tlu >*/
	bnelem_1.t2[fn - 1] = tlu;
/* SOURCE brnmat.for:1762 */
/*<       a2(fn)=alu >*/
	bnelem_1.a2[fn - 1] = alu;
/* SOURCE brnmat.for:1763 */
/*<       b2(fn)=blu >*/
	bnelem_1.b2[fn - 1] = blu;
/* SOURCE brnmat.for:1764 */
/*<       k2(fn)=klu >*/
	bnelem_1.k2[fn - 1] = klu;
/* SOURCE brnmat.for:1765 */
/*<       ma2(fn)=malu >*/
	bnelem_1.ma2[fn - 1] = malu;
/* SOURCE brnmat.for:1766 */
/*<       mq2(fn)=mqlu >*/
	bnelem_1.mq2[fn - 1] = mqlu;
/* SOURCE brnmat.for:1767 */
/*<       fn=fn+1 >*/
	++fn;
/* SOURCE brnmat.for:1768 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:1769 */
/*<       qru=q2(fn) >*/
	qru = bnelem_1.q2[fn - 1];
/* SOURCE brnmat.for:1770 */
/*<       yru=y2(fn) >*/
	yru = bnelem_1.y2[fn - 1];
/* SOURCE brnmat.for:1771 */
/*<        >*/
	xlkt23_(&bnothr_1.nsec[fn - 1], &yru, &aru, &tru, &dtru, &kru, &dkru, 
		&bru, &dbru, &maru, &dmaru, &mqru, &dmqru);
/* SOURCE brnmat.for:1776 */
/*<       t2(fn)=tru >*/
	bnelem_1.t2[fn - 1] = tru;
/* SOURCE brnmat.for:1777 */
/*<       a2(fn)=aru >*/
	bnelem_1.a2[fn - 1] = aru;
/* SOURCE brnmat.for:1778 */
/*<       b2(fn)=bru >*/
	bnelem_1.b2[fn - 1] = bru;
/* SOURCE brnmat.for:1779 */
/*<       k2(fn)=kru >*/
	bnelem_1.k2[fn - 1] = kru;
/* SOURCE brnmat.for:1780 */
/*<       ma2(fn)=maru >*/
	bnelem_1.ma2[fn - 1] = maru;
/* SOURCE brnmat.for:1781 */
/*<       mq2(fn)=mqru >*/
	bnelem_1.mq2[fn - 1] = mqru;
/* SOURCE brnmat.for:1782 */
/*<       fn=fn-1 >*/
	--fn;
/* SOURCE brnmat.for:1783 */
/*<       endif >*/
    }
/*      WRITE(STD6,*) ' Dump of residual and derivatives' */
/* SOURCE brnmat.for:1786 */
/*<       do100nnd=fn,ln,ninc >*/
    feq_gen_i_d_1 = ln;
    feq_gen_i_d_2 = ninc;
    for (nnd = fn; feq_gen_i_d_2 < 0 ? nnd >= feq_gen_i_d_1 : nnd <= feq_gen_i_d_1; nnd += feq_gen_i_d_2) {
/* SOURCE brnmat.for:1787 */
/*<       if(ninc.eq.1)then >*/
	if (ninc == 1) {
/* SOURCE brnmat.for:1788 */
/*<       elmadr=nnd >*/
	    elmadr = nnd;
/* SOURCE brnmat.for:1789 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1790 */
/*<       elmadr=nnd+1 >*/
	    elmadr = nnd + 1;
/* SOURCE brnmat.for:1791 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1792 */
/*<       dx=dxvec(elmadr) >*/
	dx = bnelem_1.dxvec[elmadr - 1];
/* SOURCE brnmat.for:1793 */
/*<       dxh=0.5*dx >*/
	dxh = static_cast<double>(dx) * (float).5;
/* SOURCE brnmat.for:1794 */
/*<       dx2=dx+dx >*/
	dx2 = static_cast<double>(dx) + dx;
/* SOURCE brnmat.for:1795 */
/*<       dxdt=dx/dt >*/
	dxdt = dx / *dt;
/* SOURCE brnmat.for:1796 */
/*<       dxhdt=0.5*dxdt >*/
	dxhdt = static_cast<double>(dxdt) * (float).5;
/* SOURCE brnmat.for:1797 */
/*<       dz=dzvec(elmadr) >*/
	dz = bnelem_1.dzvec[elmadr - 1];
/* SOURCE brnmat.for:1798 */
/*<       kac=ka(elmadr) >*/
	kac = bnelem_1.ka[elmadr - 1];
/* SOURCE brnmat.for:1799 */
/*<       kdc=kd(elmadr) >*/
	kdc = bnelem_1.kd[elmadr - 1];
/* SOURCE brnmat.for:1800 */
/*<       adrs=hltab(elmadr) >*/
	adrs = bnothr_1.hltab[elmadr - 1];
/* SOURCE brnmat.for:1801 */
/*<       if(stflag.eq.0)then >*/
	if (bnelem_1.stflag == 0) {
/*            WX = WXVEC(ELMADR) */
/* SOURCE brnmat.for:1804 */
/*<       if(ninc.gt.0)then >*/
	    if (ninc > 0) {
/* SOURCE brnmat.for:1805 */
/*<       trd=t1(nnd) >*/
		trd = bnelem_1.t1[nnd - 1];
/* SOURCE brnmat.for:1806 */
/*<       ard=a1(nnd) >*/
		ard = bnelem_1.a1[nnd - 1];
/* SOURCE brnmat.for:1807 */
/*<       yrd=y1(nnd) >*/
		yrd = bnelem_1.y1[nnd - 1];
/* SOURCE brnmat.for:1808 */
/*<       brd=b1(nnd) >*/
		brd = bnelem_1.b1[nnd - 1];
/* SOURCE brnmat.for:1809 */
/*<       qrd=q1(nnd) >*/
		qrd = bnelem_1.q1[nnd - 1];
/* SOURCE brnmat.for:1810 */
/*<       krd=k1(nnd) >*/
		krd = bnelem_1.k1[nnd - 1];
/* SOURCE brnmat.for:1811 */
/*<       mard=ma1(nnd) >*/
		mard = bnelem_1.ma1[nnd - 1];
/* SOURCE brnmat.for:1812 */
/*<       mqrd=mq1(nnd) >*/
		mqrd = bnelem_1.mq1[nnd - 1];
/* SOURCE brnmat.for:1813 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1814 */
/*<       tld=t1(nnd) >*/
		tld = bnelem_1.t1[nnd - 1];
/* SOURCE brnmat.for:1815 */
/*<       ald=a1(nnd) >*/
		ald = bnelem_1.a1[nnd - 1];
/* SOURCE brnmat.for:1816 */
/*<       yld=y1(nnd) >*/
		yld = bnelem_1.y1[nnd - 1];
/* SOURCE brnmat.for:1817 */
/*<       bld=b1(nnd) >*/
		bld = bnelem_1.b1[nnd - 1];
/* SOURCE brnmat.for:1818 */
/*<       qld=q1(nnd) >*/
		qld = bnelem_1.q1[nnd - 1];
/* SOURCE brnmat.for:1819 */
/*<       kld=k1(nnd) >*/
		kld = bnelem_1.k1[nnd - 1];
/* SOURCE brnmat.for:1820 */
/*<       mald=ma1(nnd) >*/
		mald = bnelem_1.ma1[nnd - 1];
/* SOURCE brnmat.for:1821 */
/*<       mqld=mq1(nnd) >*/
		mqld = bnelem_1.mq1[nnd - 1];
/* SOURCE brnmat.for:1822 */
/*<       endif >*/
	    }
/*           SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL. */
/* SOURCE brnmat.for:1825 */
/*<       if(yld.lt.ziy.or.yrd.lt.ziy)then >*/
	    if (yld < ziy || yrd < ziy) {
/* SOURCE brnmat.for:1826 */
/*<       zi=0.0 >*/
		zi = (float)0.;
/* SOURCE brnmat.for:1827 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1828 */
/*<       zi=zit >*/
		zi = zit;
/* SOURCE brnmat.for:1829 */
/*<       endif >*/
	    }
/*           COMPUTE VALUES AT THE START OF THE TIME STEP AND STORE */
/* SOURCE brnmat.for:1833 */
/*<       oldsum=qld+qrd >*/
	    oldsum = static_cast<double>(qld) + qrd;
/* SOURCE brnmat.for:1834 */
/*<       oldmom=mqld*qld+mqrd*qrd >*/
	    oldmom = static_cast<double>(static_cast<double>(mqld) * qld) + static_cast<double>(mqrd) * qrd;
/* SOURCE brnmat.for:1836 */
/*<       sumvec(elmadr)=oldsum >*/
	    bnelem_1.sumvec[elmadr - 1] = oldsum;
/* SOURCE brnmat.for:1837 */
/*<       momvec(elmadr)=oldmom >*/
	    bnelem_1.momvec[elmadr - 1] = oldmom;
/* SOURCE brnmat.for:1838 */
/*<       vld=qld/ald >*/
	    vld = static_cast<double>(qld) / ald;
/* SOURCE brnmat.for:1839 */
/*<       vrd=qrd/ard >*/
	    vrd = static_cast<double>(qrd) / ard;
/* SOURCE brnmat.for:1841 */
/*<       gde=0.0 >*/
	    gde = (float)0.;
/* SOURCE brnmat.for:1842 */
/*<       if(kdc.gt.0.0.or.kac.gt.0.0)then >*/
	    if (kdc > (float)0. || kac > (float)0.) {
/*             PROCESS EXPANSION AND CONTRACTION LOSSES */
/* SOURCE brnmat.for:1844 */
/*<       dv=vld-vrd >*/
		dv = static_cast<double>(vld) - vrd;
/* SOURCE brnmat.for:1845 */
/*<       if(dv.gt.0.0)then >*/
		if (dv > (float)0.) {
/*               FLOW IS UNDERGOING NEGATIVE ACCELERATION-TAKEN */
/*               TO INDICATE EXPANSION */
/* SOURCE brnmat.for:1848 */
/*<       kp=kdc >*/
		    kp = kdc;
/* SOURCE brnmat.for:1849 */
/*<       else >*/
		} else {
/*               FLOW IS UNDERGOING POSITIVE ACCELERATION- TAKEN TO */
/*               INDICATE CONTRACTION */
/* SOURCE brnmat.for:1852 */
/*<       kp=kac >*/
		    kp = kac;
/* SOURCE brnmat.for:1853 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:1854 */
/*<       gde=0.5*sign(kp,oldsum)*abs(dv*(vld+vrd)) >*/
		gde = r_sign(&kp, &oldsum) * (float).5 * (feq_gen_r_d_1 = static_cast<double>(dv) * (static_cast<double>(vld) + 
			vrd), dabs(feq_gen_r_d_1));
/* SOURCE brnmat.for:1855 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1857 */
/*<       if(adrs.gt.0)then >*/
	    if (adrs > 0) {
/*             POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT */
/* SOURCE brnmat.for:1859 */
/*<       ym=0.5*(yld+yrd) >*/
		ym = static_cast<double>((static_cast<double>(yld) + yrd)) * (float).5;
/* SOURCE brnmat.for:1860 */
/*<       calllktab(adrs,ym,0,khlm,ntab,dkhlm) >*/
		lktab_(&adrs, &ym, &feq_gen_c_d_0, &khlm, &ntab, &dkhlm);
/* SOURCE brnmat.for:1863 */
/*<       if(oldsum.lt.0.0)then >*/
		if (oldsum < (float)0.) {
/* SOURCE brnmat.for:1864 */
/*<       khlm=-khlm >*/
		    khlm = -khlm;
/* SOURCE brnmat.for:1865 */
/*<       dkhlm=-dkhlm >*/
		    dkhlm = -dkhlm;
/* SOURCE brnmat.for:1866 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:1868 */
/*<       gde=gde+0.5*khlm*(oldsum/(ald+ard))**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(oldsum) / (static_cast<double>(ald) + ard);
		gde += static_cast<double>(static_cast<double>(static_cast<double>(khlm) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE brnmat.for:1869 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1871 */
/*<       dyt=yrd-yld >*/
	    dyt = static_cast<double>(yrd) - yld;
/* SOURCE brnmat.for:1872 */
/*<       kmd=kld+wx*(krd-kld) >*/
	    kmd = static_cast<double>(kld) + static_cast<double>(wx) * (static_cast<double>(krd) - kld);
/*            AMD = ALD + 0.5*(ARD - ALD) */
/* SOURCE brnmat.for:1874 */
/*<       amd=0.5*(ard+ald) >*/
	    amd = static_cast<double>((static_cast<double>(ard) + ald)) * (float).5;
/* SOURCE brnmat.for:1875 */
/*<        >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = kmd;
	    oldimp = (gravcm_1.grav * (dz + static_cast<double>(oldsum) * (float).25 * dabs(oldsum)
		     * dx / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + dyt) + gde) * amd + static_cast<double>(zi) * (static_cast<double>(static_cast<double>(static_cast<double>(brd) * 
		    vrd) * qrd) - static_cast<double>(static_cast<double>(bld) * vld) * qld);
/* SOURCE brnmat.for:1879 */
/*<       impvec(elmadr)=oldimp >*/
	    bnelem_1.impvec[elmadr - 1] = oldimp;
/* SOURCE brnmat.for:1880 */
/*<       if(wsvec(elmadr).ne.0.0)then >*/
	    if (bnothr_1.wsvec[elmadr - 1] != (float)0.) {
/*             COMPUTE THE WIND STRESS TERM.  WSVEC IS USED TO HOLD */
/*             VALUE BECAUSE THE WIND STRESS IS RECOMPUTED FOR EACH */
/*             TIME STEP AT THE START OF THE TIME STEP.  WE USE THE */
/*             EULER APPROXIMATION FOR THE INTEGRAL TO SIMPLIFY THE */
/*             EQUATIONS. */
/* SOURCE brnmat.for:1887 */
/*<       oldwnd=dxh*(tld+trd)*wsvec(elmadr) >*/
		oldwnd = static_cast<double>(static_cast<double>(dxh) * (static_cast<double>(tld) + trd)) * bnothr_1.wsvec[elmadr - 1];
/* SOURCE brnmat.for:1888 */
/*<       wsvec(elmadr)=oldwnd >*/
		bnothr_1.wsvec[elmadr - 1] = oldwnd;
/* SOURCE brnmat.for:1889 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1890 */
/*<       oldwnd=0.0 >*/
		oldwnd = (float)0.;
/* SOURCE brnmat.for:1891 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1893 */
/*<       oldvol=0.5*(mald*ald+mard*ard) >*/
	    oldvol = static_cast<double>((static_cast<double>(static_cast<double>(mald) * ald) + static_cast<double>(mard) * ard)) * (float).5;
/* SOURCE brnmat.for:1894 */
/*<       volvec(elmadr)=oldvol >*/
	    bnelem_1.volvec[elmadr - 1] = oldvol;
/* SOURCE brnmat.for:1895 */
/*<       oldflw=qrd-qld >*/
	    oldflw = static_cast<double>(qrd) - qld;
/* SOURCE brnmat.for:1896 */
/*<       flwvec(elmadr)=oldflw >*/
	    bnelem_1.flwvec[elmadr - 1] = oldflw;
/* SOURCE brnmat.for:1898 */
/*<       if(ninc.gt.0)then >*/
	    if (ninc > 0) {
/* SOURCE brnmat.for:1899 */
/*<       yld=yrd >*/
		yld = yrd;
/* SOURCE brnmat.for:1900 */
/*<       tld=trd >*/
		tld = trd;
/* SOURCE brnmat.for:1901 */
/*<       ald=ard >*/
		ald = ard;
/* SOURCE brnmat.for:1902 */
/*<       bld=brd >*/
		bld = brd;
/* SOURCE brnmat.for:1903 */
/*<       kld=krd >*/
		kld = krd;
/* SOURCE brnmat.for:1904 */
/*<       qld=qrd >*/
		qld = qrd;
/* SOURCE brnmat.for:1905 */
/*<       mald=mard >*/
		mald = mard;
/* SOURCE brnmat.for:1906 */
/*<       mqld=mqrd >*/
		mqld = mqrd;
/* SOURCE brnmat.for:1907 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:1908 */
/*<       yrd=yld >*/
		yrd = yld;
/* SOURCE brnmat.for:1909 */
/*<       trd=tld >*/
		trd = tld;
/* SOURCE brnmat.for:1910 */
/*<       ard=ald >*/
		ard = ald;
/* SOURCE brnmat.for:1911 */
/*<       brd=bld >*/
		brd = bld;
/* SOURCE brnmat.for:1912 */
/*<       krd=kld >*/
		krd = kld;
/* SOURCE brnmat.for:1913 */
/*<       qrd=qld >*/
		qrd = qld;
/* SOURCE brnmat.for:1914 */
/*<       mard=mald >*/
		mard = mald;
/* SOURCE brnmat.for:1915 */
/*<       mqrd=mqld >*/
		mqrd = mqld;
/* SOURCE brnmat.for:1916 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:1917 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1918 */
/*<       oldsum=sumvec(elmadr) >*/
	    oldsum = bnelem_1.sumvec[elmadr - 1];
/* SOURCE brnmat.for:1919 */
/*<       oldmom=momvec(elmadr) >*/
	    oldmom = bnelem_1.momvec[elmadr - 1];
/* SOURCE brnmat.for:1920 */
/*<       oldimp=impvec(elmadr) >*/
	    oldimp = bnelem_1.impvec[elmadr - 1];
/* SOURCE brnmat.for:1921 */
/*<       oldvol=volvec(elmadr) >*/
	    oldvol = bnelem_1.volvec[elmadr - 1];
/* SOURCE brnmat.for:1922 */
/*<       oldflw=flwvec(elmadr) >*/
	    oldflw = bnelem_1.flwvec[elmadr - 1];
/* SOURCE brnmat.for:1923 */
/*<       oldwnd=wsvec(elmadr) >*/
	    oldwnd = bnothr_1.wsvec[elmadr - 1];
/* SOURCE brnmat.for:1924 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1927 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:1928 */
/*<       qru=q2(nnd) >*/
	    qru = bnelem_1.q2[nnd - 1];
/* SOURCE brnmat.for:1929 */
/*<       yru=y2(nnd) >*/
	    yru = bnelem_1.y2[nnd - 1];
/* SOURCE brnmat.for:1930 */
/*<        >*/
	    xlkt23_(&bnothr_1.nsec[nnd - 1], &yru, &aru, &tru, &dtru, &kru, &
		    dkru, &bru, &dbru, &maru, &dmaru, &mqru, &dmqru);
/* SOURCE brnmat.for:1935 */
/*<       t2(nnd)=tru >*/
	    bnelem_1.t2[nnd - 1] = tru;
/* SOURCE brnmat.for:1936 */
/*<       a2(nnd)=aru >*/
	    bnelem_1.a2[nnd - 1] = aru;
/* SOURCE brnmat.for:1937 */
/*<       b2(nnd)=bru >*/
	    bnelem_1.b2[nnd - 1] = bru;
/* SOURCE brnmat.for:1938 */
/*<       k2(nnd)=kru >*/
	    bnelem_1.k2[nnd - 1] = kru;
/* SOURCE brnmat.for:1939 */
/*<       ma2(nnd)=maru >*/
	    bnelem_1.ma2[nnd - 1] = maru;
/* SOURCE brnmat.for:1940 */
/*<       mq2(nnd)=mqru >*/
	    bnelem_1.mq2[nnd - 1] = mqru;
/* SOURCE brnmat.for:1941 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:1942 */
/*<       qlu=q2(nnd) >*/
	    qlu = bnelem_1.q2[nnd - 1];
/* SOURCE brnmat.for:1943 */
/*<       ylu=y2(nnd) >*/
	    ylu = bnelem_1.y2[nnd - 1];
/* SOURCE brnmat.for:1944 */
/*<        >*/
	    xlkt23_(&bnothr_1.nsec[nnd - 1], &ylu, &alu, &tlu, &dtlu, &klu, &
		    dklu, &blu, &dblu, &malu, &dmalu, &mqlu, &dmqlu);
/* SOURCE brnmat.for:1949 */
/*<       t2(nnd)=tlu >*/
	    bnelem_1.t2[nnd - 1] = tlu;
/* SOURCE brnmat.for:1950 */
/*<       a2(nnd)=alu >*/
	    bnelem_1.a2[nnd - 1] = alu;
/* SOURCE brnmat.for:1951 */
/*<       b2(nnd)=blu >*/
	    bnelem_1.b2[nnd - 1] = blu;
/* SOURCE brnmat.for:1952 */
/*<       k2(nnd)=klu >*/
	    bnelem_1.k2[nnd - 1] = klu;
/* SOURCE brnmat.for:1953 */
/*<       ma2(nnd)=malu >*/
	    bnelem_1.ma2[nnd - 1] = malu;
/* SOURCE brnmat.for:1954 */
/*<       mq2(nnd)=mqlu >*/
	    bnelem_1.mq2[nnd - 1] = mqlu;
/* SOURCE brnmat.for:1955 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:1956 */
/*<       newsum=qlu+qru >*/
	newsum = static_cast<double>(qlu) + qru;
/* SOURCE brnmat.for:1957 */
/*<       newmom=mqlu*qlu+mqru*qru >*/
	newmom = static_cast<double>(static_cast<double>(mqlu) * qlu) + static_cast<double>(mqru) * qru;
/* SOURCE brnmat.for:1959 */
/*<       dyt=yru-ylu >*/
	dyt = static_cast<double>(yru) - ylu;
/*         SELECT NEW VALUE OF WX. */
/*         Debugging test */
/*          WX = 0.5 */
/* SOURCE brnmat.for:1964 */
/*<       kmu=0.5*(klu+kru) >*/
	kmu = static_cast<double>((static_cast<double>(klu) + kru)) * (float).5;
/*         Disable this adjustment.  Feb. 2001 */
/*          GOTO 9125 */
/*          IF(NEWSUM.GE.0.0) THEN */
/* C           FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT. */
/* C            WRITE(STD6,*) ' CRITERION=',DKRU*(-DYT - DZ) - KMU */
/* C            WRITE(STD6,*) ' DKRU=',DKRU,'DYT+DZ=',DYT+DZ,' KMU=',KMU */
/*            IF(DKRU*(-DYT - DZ) - KMU.GE.0.0) THEN */
/* C             SHIFT TO UPSTREAM CONVEYANCE. */
/*              WX = 0.4*KLU/(DKRU*(-DYT-DZ) - 0.5*(KRU - KLU)) */
/*              KMU = KLU + WX*(KRU - KLU) */
/*            ELSE */
/*              WX = 0.5 */
/*            ENDIF */
/*          ELSE */
/* C           FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT. */
/*            IF(DKLU*(DYT + DZ) - KMU.GE.0.0) THEN */
/* C             SHIFT TO UPSTREAM CONVEYANCE */
/*              WX = 1.0 - 0.4*KRU/(DKLU*(DYT + DZ) - .5*(KRU - KLU)) */
/*              KMU = KLU + WX*(KRU - KLU) */
/*            ELSE */
/*              WX = 0.5 */
/*            ENDIF */
/*          ENDIF */

/* 9125      CONTINUE */
/* SOURCE brnmat.for:1991 */
/*<       amu=0.5*(aru+alu) >*/
	amu = static_cast<double>((static_cast<double>(aru) + alu)) * (float).5;
/* SOURCE brnmat.for:1992 */
/*<       newvol=0.5*(malu*alu+maru*aru) >*/
	newvol = static_cast<double>((static_cast<double>(static_cast<double>(malu) * alu) + static_cast<double>(maru) * aru)) * (float).5;
/*          WXVEC(ELMADR) = WX */
/* SOURCE brnmat.for:1994 */
/*<       ksum=kmu+kmu >*/
	ksum = static_cast<double>(kmu) + kmu;
/*          IF(STFLAG.EQ.0) */
/*     A     WRITE(STD6,'(6H RDVAL,6F10.3)') YRD, TRD, ARD, KRD, BRD, QRD */
/*        WRITE(STD6,'(6H RUVAL,7F10.3)') YRU, TRU, ARU, KRU, BRU, QRU, DKRU */
/*         SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL. */
/* SOURCE brnmat.for:2001 */
/*<       if(ylu.lt.ziy.or.yru.lt.ziy)then >*/
	if (ylu < ziy || yru < ziy) {
/* SOURCE brnmat.for:2002 */
/*<       zi=0.0 >*/
	    zi = (float)0.;
/* SOURCE brnmat.for:2003 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2004 */
/*<       zi=zit >*/
	    zi = zit;
/* SOURCE brnmat.for:2005 */
/*<       endif >*/
	}
/*         CONTINUITY EQUATION */
/*         1) PARTIAL DERIVATIVES */
/* SOURCE brnmat.for:2010 */
/*<       c1=dxhdt*(malu*tlu+alu*dmalu) >*/
	c1 = static_cast<double>(dxhdt) * (static_cast<double>(static_cast<double>(malu) * tlu) + static_cast<double>(alu) * dmalu);
/* SOURCE brnmat.for:2011 */
/*<       c2=-wt >*/
	c2 = -(*wt);
/* SOURCE brnmat.for:2012 */
/*<       c3=dxhdt*(maru*tru+aru*dmaru) >*/
	c3 = static_cast<double>(dxhdt) * (static_cast<double>(static_cast<double>(maru) * tru) + static_cast<double>(aru) * dmaru);
/* SOURCE brnmat.for:2013 */
/*<       c4=wt >*/
	c4 = *wt;
/* SOURCE brnmat.for:2015 */
/*<       qp=qpvec(elmadr) >*/
	qp = bnothr_1.qpvec[elmadr - 1];
/* SOURCE brnmat.for:2016 */
/*<       cf=coefin(elmadr) >*/
	cf = bnpond_1.coefin[elmadr - 1];
/* SOURCE brnmat.for:2017 */
/*<       if(cf.gt.0.0)then >*/
	if (cf > (float)0.) {
/*            PROCESS INFLOW RESTRICTION ON SEWERS */
/* SOURCE brnmat.for:2021 */
/*<       yc=ycut(elmadr) >*/
	    yc = bnpond_1.ycut[elmadr - 1];
/* SOURCE brnmat.for:2022 */
/*<       s1=pond1(elmadr) >*/
	    s1 = bnpond_1.pond1[elmadr - 1];
/* SOURCE brnmat.for:2023 */
/*<       s2=pond2(elmadr) >*/
	    s2 = bnpond_1.pond2[elmadr - 1];
/* SOURCE brnmat.for:2024 */
/*<       ym=0.5*((ylu+yru)) >*/
	    ym = static_cast<double>((static_cast<double>(ylu) + yru)) * (float).5;
/* SOURCE brnmat.for:2025 */
/*<       dh=yc-ym >*/
	    dh = static_cast<double>(yc) - ym;
/* SOURCE brnmat.for:2026 */
/*<       if(abs(dh).le.dhstar)then >*/
	    if (dabs(dh) <= miscon_1.dhstar) {
/* SOURCE brnmat.for:2027 */
/*<       qmax=dh*cf*qpcon >*/
		qmax = static_cast<double>(static_cast<double>(dh) * cf) * miscon_1.qpcon;
/* SOURCE brnmat.for:2028 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2029 */
/*<       qmax=cf*sqrt(twog*abs(dh)) >*/
		qmax = cf * sqrt(gravcm_1.twog * dabs(dh));
/* SOURCE brnmat.for:2030 */
/*<       if(dh.lt.0.0)qmax=-qmax >*/
		if (dh < (float)0.) {
		    qmax = -qmax;
		}
/* SOURCE brnmat.for:2031 */
/*<       endif >*/
	    }
/*            CHECK FOR FLOW ALLOWED */
/* SOURCE brnmat.for:2035 */
/*<       tp=qp+s1/dt >*/
	    tp = qp + s1 / *dt;
/* SOURCE brnmat.for:2036 */
/*<       if(qmax.gt.tp)then >*/
	    if (qmax > tp) {
/* SOURCE brnmat.for:2037 */
/*<       pond2(elmadr)=0.0 >*/
		bnpond_1.pond2[elmadr - 1] = (float)0.;
/* SOURCE brnmat.for:2038 */
/*<       qp=tp >*/
		qp = tp;
/* SOURCE brnmat.for:2039 */
/*<       dqpylu=0.0 >*/
		dqpylu = (float)0.;
/* SOURCE brnmat.for:2040 */
/*<       dqpyru=0.0 >*/
		dqpyru = (float)0.;
/* SOURCE brnmat.for:2041 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2042 */
/*<       s3=s1+dt*(qp-qmax) >*/
		s3 = s1 + *dt * (static_cast<double>(qp) - qmax);
/* SOURCE brnmat.for:2043 */
/*<       b=abs(s2-s3)/(dx*oldvol) >*/
		b = (feq_gen_r_d_1 = static_cast<double>(s2) - s3, dabs(feq_gen_r_d_1)) / (static_cast<double>(dx) * oldvol);
/* SOURCE brnmat.for:2044 */
/*<       if(b.gt.errp)then >*/
		if (b > *errp) {
/* SOURCE brnmat.for:2045 */
/*<       errp=b >*/
		    *errp = b;
/* SOURCE brnmat.for:2046 */
/*<       nerrp=ubnbas+nnd-fn >*/
		    *nerrp = ubnbas + nnd - fn;
/* SOURCE brnmat.for:2047 */
/*<       berrp=nbr >*/
		    *berrp = *nbr;
/* SOURCE brnmat.for:2048 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:2049 */
/*<       pond2(elmadr)=s3 >*/
		bnpond_1.pond2[elmadr - 1] = s3;
/* SOURCE brnmat.for:2050 */
/*<       qp=qmax >*/
		qp = qmax;
/* SOURCE brnmat.for:2051 */
/*<       if(abs(dh).le.dhstar)then >*/
		if (dabs(dh) <= miscon_1.dhstar) {
/* SOURCE brnmat.for:2052 */
/*<       dqpylu=-0.5*cf*qpcon >*/
		    dqpylu = static_cast<double>(static_cast<double>(cf) * (float)-.5) * miscon_1.qpcon;
/* SOURCE brnmat.for:2053 */
/*<       dqpyru=dqpylu >*/
		    dqpyru = dqpylu;
/* SOURCE brnmat.for:2054 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:2055 */
/*<       dqpylu=-halfg*cf*cf/abs(qp) >*/
		    dqpylu = static_cast<double>(static_cast<double>(-gravcm_1.halfg) * cf) * cf / dabs(qp);
/* SOURCE brnmat.for:2056 */
/*<       dqpyru=dqpylu >*/
		    dqpyru = dqpylu;
/* SOURCE brnmat.for:2057 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:2058 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2059 */
/*<       c1=c1-dqpylu >*/
	    c1 -= dqpylu;
/* SOURCE brnmat.for:2060 */
/*<       c3=c3-dqpyru >*/
	    c3 -= dqpyru;
/* SOURCE brnmat.for:2062 */
/*<       endif >*/
	}
/*         2) RESIDUAL */
/* SOURCE brnmat.for:2065 */
/*<       ieq=ieq+1 >*/
	++(*ieq);
/* SOURCE brnmat.for:2067 */
/*<       dyndif=oldflw+wt*(qru-qlu-oldflw)-qp >*/
	dyndif = static_cast<double>(static_cast<double>(oldflw) + static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(qru) - qlu) - oldflw)) - qp;
/* SOURCE brnmat.for:2068 */
/*<       res=-((newvol-oldvol)*dxdt+dyndif) >*/
	res = -(static_cast<double>(static_cast<double>((static_cast<double>(newvol) - oldvol)) * dxdt) + dyndif);
/*        WRITE(STD6,2345) ' CON EQ:C1,C2,C3,C4,RES', C1, C2, C3, C4, RES */
/* 2345  FORMAT(A,5(1PE10.3)) */
/*         JCOL GIVES THE VARIABLE NUMBER AT THE FIRST COEFFICIENT IN */
/*         THE EQUATIONS. */
/* SOURCE brnmat.for:2076 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:2077 */
/*<       pdavec(r(ieq))=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c2;
/* SOURCE brnmat.for:2078 */
/*<       pdavec(c(jcol+1))=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 1] - 1] = c1;
/* SOURCE brnmat.for:2079 */
/*<       pdavec(c(jcol+2)-1)=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 2] = c4;
/* SOURCE brnmat.for:2080 */
/*<       pdavec(c(jcol+3)-2)=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 3] = c3;
/* SOURCE brnmat.for:2081 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2082 */
/*<       pdavec(r(ieq))=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c4;
/* SOURCE brnmat.for:2083 */
/*<       pdavec(c(jcol+1))=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 1] - 1] = c3;
/* SOURCE brnmat.for:2084 */
/*<       pdavec(c(jcol+2)-1)=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 2] = c2;
/* SOURCE brnmat.for:2085 */
/*<       pdavec(c(jcol+3)-2)=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 3] = c1;
/* SOURCE brnmat.for:2086 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2088 */
/*<       rhs(ieq)=res >*/
	matcom_1.rhs[*ieq - 1] = res;
/* SOURCE brnmat.for:2091 */
/*<       err=abs(qp)/(abs(0.5*oldsum)+0.1) >*/
	err = dabs(qp) / ((feq_gen_r_d_1 = static_cast<double>(oldsum) * (float).5, dabs(feq_gen_r_d_1)) + (float).1)
		;
/* SOURCE brnmat.for:2092 */
/*<       if(err.gt.errq)then >*/
	if (err > *errq) {
/* SOURCE brnmat.for:2093 */
/*<       errq=err >*/
	    *errq = err;
/* SOURCE brnmat.for:2094 */
/*<       berrq=nbr >*/
	    *berrq = *nbr;
/* SOURCE brnmat.for:2095 */
/*<       nerrq=ubnbas+nnd-fn >*/
	    *nerrq = ubnbas + nnd - fn;
/* SOURCE brnmat.for:2096 */
/*<       endif >*/
	}
/*       MOMENTUM EQUATION */
/* SOURCE brnmat.for:2100 */
/*<       sfmt=abs(newsum)/ksum**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ksum;
	sfmt = dabs(newsum) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:2101 */
/*<       sfmu=newsum*sfmt >*/
	sfmu = static_cast<double>(newsum) * sfmt;
/*        WRITE(STD6,*) ' SFMU=', SFMU */
/* SOURCE brnmat.for:2103 */
/*<       pgfu=grav*(dz+sfmu*dx+dyt) >*/
	pgfu = static_cast<double>(gravcm_1.grav) * (static_cast<double>(static_cast<double>(dz) + static_cast<double>(sfmu) * dx) + dyt);
/* SOURCE brnmat.for:2104 */
/*<       vlu=qlu/alu >*/
	vlu = static_cast<double>(qlu) / alu;
/* SOURCE brnmat.for:2105 */
/*<       vru=qru/aru >*/
	vru = static_cast<double>(qru) / aru;
/* SOURCE brnmat.for:2106 */
/*<       tpa=(dx2+dx2)*sfmu/ksum >*/
	tpa = static_cast<double>(static_cast<double>((static_cast<double>(dx2) + dx2)) * sfmu) / ksum;
/* SOURCE brnmat.for:2107 */
/*<       tpb=amu*grav*dx2*sfmt >*/
	tpb = static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * dx2) * sfmt;
/*       PARTIAL DERIVATIVES */
/* SOURCE brnmat.for:2111 */
/*<        >*/
	c1 = static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * (static_cast<double>(static_cast<double>(static_cast<double>(-tpa) * dklu) * (static_cast<double>((float)1.) - wx)) - (
		float)1.)) + static_cast<double>(static_cast<double>(pgfu) * (float).5) * tlu) - static_cast<double>(zi) * (static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(dblu) * qlu) - static_cast<double>(static_cast<double>(tlu) *
		 blu) * vlu)) * vlu) - static_cast<double>(static_cast<double>(dxhdt) * qlu) * dmqlu));
/* SOURCE brnmat.for:2117 */
/*<       c2=zi*mqlu*dxhdt+wt*(tpb-2.*zi*blu*vlu) >*/
	c2 = static_cast<double>(static_cast<double>(static_cast<double>(zi) * mqlu) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(tpb) - static_cast<double>(static_cast<double>(static_cast<double>(zi) * (float)2.) * blu) * vlu);
/* SOURCE brnmat.for:2120 */
/*<        >*/
	c3 = static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * (static_cast<double>(static_cast<double>(static_cast<double>(-tpa) * dkru) * wx) + (float)1.)) + 
		static_cast<double>(static_cast<double>(pgfu) * (float).5) * tru) + static_cast<double>(zi) * (static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(dbru) * qru) - static_cast<double>(static_cast<double>(tru) * bru) * vru)) 
		* vru) + static_cast<double>(static_cast<double>(dxhdt) * qru) * dmqru));
/* SOURCE brnmat.for:2125 */
/*<       c4=zi*mqru*dxhdt+wt*(tpb+2.*zi*bru*vru) >*/
	c4 = static_cast<double>(static_cast<double>(static_cast<double>(zi) * mqru) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(tpb) + static_cast<double>(static_cast<double>(static_cast<double>(zi) * (float)2.) * bru) * vru);
/* SOURCE brnmat.for:2130 */
/*<       if(kdc.gt.0.0.or.kac.gt.0.0)then >*/
	if (kdc > (float)0. || kac > (float)0.) {
/*         PROCESS EXPANSION AND CONTRACTION LOSSES */
/* SOURCE brnmat.for:2132 */
/*<       dv2=(vru-vlu)*(vru+vlu) >*/
	    dv2 = static_cast<double>((static_cast<double>(vru) - vlu)) * (static_cast<double>(vru) + vlu);
/*         Establish the sign of the difference in */
/*         the squared velocities. */
/* SOURCE brnmat.for:2135 */
/*<       sgndv2=sign(1.0,dv2) >*/
	    sgndv2 = r_sign(&c_b107, &dv2);
/*         Absolute value of difference of squares is */
/*         needed as well. */
/* SOURCE brnmat.for:2138 */
/*<       dv2=abs(dv2) >*/
	    dv2 = dabs(dv2);
/* SOURCE brnmat.for:2139 */
/*<       if(vlu.ge.vru)then >*/
	    if (vlu >= vru) {
/*           FLOW IS UNDERGOING NEGATIVE ACCELERATION */
/*            idir = -1 */
/* SOURCE brnmat.for:2142 */
/*<       kp=sign(kdc,newsum) >*/
		kp = r_sign(&kdc, &newsum);
/* SOURCE brnmat.for:2143 */
/*<       else >*/
	    } else {
/*           FLOW IS UNDERGOING POSITIVE ACCELERATION */
/*            idir = +1 */
/* SOURCE brnmat.for:2146 */
/*<       kp=sign(kac,newsum) >*/
		kp = r_sign(&kac, &newsum);
/* SOURCE brnmat.for:2147 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2149 */
/*<       pfqlu=-kp*sgndv2*amu*vlu/alu >*/
	    pfqlu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(-kp) * sgndv2) * amu) * vlu) / alu;
/* SOURCE brnmat.for:2150 */
/*<       pfylu=tlu*(0.25*kp*dv2-pfqlu*vlu) >*/
	    pfylu = static_cast<double>(tlu) * (static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).25) * dv2) - static_cast<double>(pfqlu) * vlu);
/* SOURCE brnmat.for:2151 */
/*<       pfqru=kp*sgndv2*amu*vru/aru >*/
	    pfqru = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(kp) * sgndv2) * amu) * vru) / aru;
/* SOURCE brnmat.for:2152 */
/*<       pfyru=tru*(0.25*kp*dv2-pfqru*vru) >*/
	    pfyru = static_cast<double>(tru) * (static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).25) * dv2) - static_cast<double>(pfqru) * vru);
/* SOURCE brnmat.for:2154 */
/*<       pgfu=pgfu+0.5*kp*dv2 >*/
	    pgfu += static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).5) * dv2);
/* SOURCE brnmat.for:2155 */
/*<       c1=c1+wt*pfylu >*/
	    c1 += static_cast<double>(*wt) * pfylu;
/* SOURCE brnmat.for:2156 */
/*<       c2=c2+wt*pfqlu >*/
	    c2 += static_cast<double>(*wt) * pfqlu;
/* SOURCE brnmat.for:2157 */
/*<       c3=c3+wt*pfyru >*/
	    c3 += static_cast<double>(*wt) * pfyru;
/* SOURCE brnmat.for:2158 */
/*<       c4=c4+wt*pfqru >*/
	    c4 += static_cast<double>(*wt) * pfqru;
/* SOURCE brnmat.for:2160 */
/*<       endif >*/
	}
/* c       Debugging output */
/*        IF(JTIME.GE.PRTIME) THEN */
/*          IF(IEQ.EQ.8906) THEN */
/*            STDOUT = STD6 */
/* c           Output details for the momentum balance */
/*            WRITE(STDOUT,50)  IEQ + 1 */
/* 50    FORMAT(/,' Detail for Eqno=',I6) */
/*            WRITE(STDOUT,51) */
/* 51    FORMAT('Lctn        Flow       Depth        Area   Top Width', */
/*     A'  Conveyance dConveyance        Beta       dBeta          MA', */
/*     B'         dMA          MQ         dMQ') */

/*            WRITE(STDOUT,52) 'LU  ', QLU, YLU, ALU, TLU, KLU, DKLU, BLU, */
/*     A                       DBLU, MALU, DMALU, MQLU, DMQLU */
/*            WRITE(STDOUT,52) 'RU  ', QRU, YRU, ARU, TRU, KRU, DKRU, BRU, */
/*     A                       DBRU, MARU, DMARU, MQRU, DMQRU */
/* 52    FORMAT(A4,12(1PE12.5)) */

/*            WRITE(STDOUT,53) WT, WX, ZI, DYT, DZ, DX */
/* 53    FORMAT( ' WT=',F5.3,' WX=',F5.3,' ZI=',F5.3, */
/*     A       ' DYT=',1PE12.5,' DZ=',1PE12.5,' DX=',1PE12.5) */

/*            WRITE(STDOUT,54) SFMT, SFMU, PGFU, VLU, VRU, TPA, TPB */
/* 54    FORMAT(' SFMT=',1PE12.5,' SFMU=',1PE12.5,' PGFU=',1PE12.5, */
/*     A' VLU=',1PE12.5,' VRU=',1PE12.5,' TPA=',1PE12.5, */
/*     B' TPB=',1PE12.5) */

/*            WRITE(STDOUT,55) AMU, DXHDT */
/* 55    FORMAT(' AMU=',1PE12.5,' DXHDT=',1PE12.5) */

/*            WRITE(STDOUT,56) 'first: ', C1, C2, C3, C4 */
/* 56    FORMAT(A7,' C1=',1PE12.5,' C2=',1PE12.5,' C3=',1PE12.5, */
/*     A           ' C4=',1PE12.5) */
/*            write(stdout,58) elmadr, oldmom, newmom */
/* 58    format(' ELMADR=',i6,' OLDMOM=',1pe12.5,' NEWMOM=',1pe12.5) */
/*            write(stdout,60) 0.5*kp*dv2, pfylu, pfqlu, pfyru, pfqru */
/* 60    format(' gde=',1pe12.5,' pfylu=',1pe12.5,' pfqlu=',1pe12.5, */
/*     a  ' pfyru=',1pe12.5,' pfqru=',1pe12.5) */
/*            write(stdout,62) idir, kac, kdc, kp */
/* 62    format(' idir=',i5,' kac=',f8.3,' kdc=',f8.3,' kp=',f8.3) */
/*          ENDIF */
/*        ENDIF */
/* SOURCE brnmat.for:2205 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/*         POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT */
/* SOURCE brnmat.for:2207 */
/*<       ym=0.5*(ylu+yru) >*/
	    ym = static_cast<double>((static_cast<double>(ylu) + yru)) * (float).5;
/* SOURCE brnmat.for:2208 */
/*<       calllktab(adrs,ym,0,khlm,ntab,dkhlm) >*/
	    lktab_(&adrs, &ym, &feq_gen_c_d_0, &khlm, &ntab, &dkhlm);
/* SOURCE brnmat.for:2211 */
/*<       if(newsum.lt.0.0)then >*/
	    if (newsum < (float)0.) {
/* SOURCE brnmat.for:2212 */
/*<       khlm=-khlm >*/
		khlm = -khlm;
/* SOURCE brnmat.for:2213 */
/*<       dkhlm=-dkhlm >*/
		dkhlm = -dkhlm;
/* SOURCE brnmat.for:2214 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2216 */
/*<       tpa=newsum/(alu+aru)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(alu) + aru;
	    tpa = static_cast<double>(newsum) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:2217 */
/*<       tpb=tpa*newsum >*/
	    tpb = static_cast<double>(tpa) * newsum;
/* SOURCE brnmat.for:2218 */
/*<       gde=0.5*khlm*tpb >*/
	    gde = static_cast<double>(static_cast<double>(khlm) * (float).5) * tpb;
/* SOURCE brnmat.for:2219 */
/*<       pgfu=pgfu+gde >*/
	    pgfu += gde;
/* SOURCE brnmat.for:2220 */
/*<       tpc=wt*amu >*/
	    tpc = static_cast<double>(*wt) * amu;
/* SOURCE brnmat.for:2221 */
/*<       tpd=khlm*tpa >*/
	    tpd = static_cast<double>(khlm) * tpa;
/* SOURCE brnmat.for:2223 */
/*<       c1=c1-tpc*(tpd*tlu-dkhlm*tpb) >*/
	    c1 -= static_cast<double>(tpc) * (static_cast<double>(static_cast<double>(tpd) * tlu) - static_cast<double>(dkhlm) * tpb);
/* SOURCE brnmat.for:2224 */
/*<       c2=c2+tpc*tpd >*/
	    c2 += static_cast<double>(tpc) * tpd;
/* SOURCE brnmat.for:2225 */
/*<       c3=c3-tpc*(tpd*tru-dkhlm*tpb) >*/
	    c3 -= static_cast<double>(tpc) * (static_cast<double>(static_cast<double>(tpd) * tru) - static_cast<double>(dkhlm) * tpb);
/* SOURCE brnmat.for:2226 */
/*<       c4=c4+tpc*tpd >*/
	    c4 += static_cast<double>(tpc) * tpd;
/* SOURCE brnmat.for:2227 */
/*<       endif >*/
	}
/*        IF(C1.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C1=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C2.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C2=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C3.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C3=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C4.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C4=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*       RESIDUAL */
/* SOURCE brnmat.for:2249 */
/*<        >*/
	res = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(zi) * (static_cast<double>(newmom) - oldmom)) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(pgfu) * amu) + static_cast<double>(zi) * (static_cast<double>(static_cast<double>(static_cast<double>(bru) *
		 qru) * vru) - static_cast<double>(static_cast<double>(blu) * qlu) * vlu))) + static_cast<double>(wtc) * oldimp) - oldwnd;
/* SOURCE brnmat.for:2252 */
/*<       ieq=ieq+1 >*/
	++(*ieq);
/*        IF(JTIME.GE.PRTIME) THEN */
/*          IF(IEQ.EQ.9999) THEN */
/*            WRITE(STDOUT,56) 'scnd : ', C1, C2, C3, C4 */

/*            WRITE(STDOUT,57) RES */
/* 57    FORMAT('RES=',1PE12.5) */
/*          ENDIF */
/*        ENDIF */
/*        WRITE(STD6,2345) ' MOM EQ:C1,C2,C3,C4,RES', C1, C2, C3, C4, RES */
/* SOURCE brnmat.for:2267 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:2268 */
/*<       pdavec(r(ieq)-1)=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 2] = c2;
/* SOURCE brnmat.for:2269 */
/*<       pdavec(r(ieq))=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c1;
/* SOURCE brnmat.for:2270 */
/*<       pdavec(c(jcol+2))=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 1] = c4;
/* SOURCE brnmat.for:2271 */
/*<       pdavec(c(jcol+3)-1)=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 2] = c3;
/* SOURCE brnmat.for:2272 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2273 */
/*<       pdavec(r(ieq)-1)=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 2] = c4;
/* SOURCE brnmat.for:2274 */
/*<       pdavec(r(ieq))=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c3;
/* SOURCE brnmat.for:2275 */
/*<       pdavec(c(jcol+2))=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 1] = c2;
/* SOURCE brnmat.for:2276 */
/*<       pdavec(c(jcol+3)-1)=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 2] = c1;
/* SOURCE brnmat.for:2277 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2279 */
/*<       rhs(ieq)=-res >*/
	matcom_1.rhs[*ieq - 1] = -res;
/*         TRANSFER VALUES */
/* SOURCE brnmat.for:2283 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:2284 */
/*<       qlu=qru >*/
	    qlu = qru;
/* SOURCE brnmat.for:2285 */
/*<       alu=aru >*/
	    alu = aru;
/* SOURCE brnmat.for:2286 */
/*<       tlu=tru >*/
	    tlu = tru;
/* SOURCE brnmat.for:2287 */
/*<       ylu=yru >*/
	    ylu = yru;
/* SOURCE brnmat.for:2288 */
/*<       klu=kru >*/
	    klu = kru;
/* SOURCE brnmat.for:2289 */
/*<       dklu=dkru >*/
	    dklu = dkru;
/* SOURCE brnmat.for:2290 */
/*<       blu=bru >*/
	    blu = bru;
/* SOURCE brnmat.for:2291 */
/*<       dblu=dbru >*/
	    dblu = dbru;
/* SOURCE brnmat.for:2292 */
/*<       malu=maru >*/
	    malu = maru;
/* SOURCE brnmat.for:2293 */
/*<       mqlu=mqru >*/
	    mqlu = mqru;
/* SOURCE brnmat.for:2294 */
/*<       dmalu=dmaru >*/
	    dmalu = dmaru;
/* SOURCE brnmat.for:2295 */
/*<       dmqlu=dmqru >*/
	    dmqlu = dmqru;
/* SOURCE brnmat.for:2296 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2297 */
/*<       qru=qlu >*/
	    qru = qlu;
/* SOURCE brnmat.for:2298 */
/*<       aru=alu >*/
	    aru = alu;
/* SOURCE brnmat.for:2299 */
/*<       tru=tlu >*/
	    tru = tlu;
/* SOURCE brnmat.for:2300 */
/*<       yru=ylu >*/
	    yru = ylu;
/* SOURCE brnmat.for:2301 */
/*<       kru=klu >*/
	    kru = klu;
/* SOURCE brnmat.for:2302 */
/*<       dkru=dklu >*/
	    dkru = dklu;
/* SOURCE brnmat.for:2303 */
/*<       bru=blu >*/
	    bru = blu;
/* SOURCE brnmat.for:2304 */
/*<       dbru=dblu >*/
	    dbru = dblu;
/* SOURCE brnmat.for:2305 */
/*<       maru=malu >*/
	    maru = malu;
/* SOURCE brnmat.for:2306 */
/*<       mqru=mqlu >*/
	    mqru = mqlu;
/* SOURCE brnmat.for:2307 */
/*<       dmaru=dmalu >*/
	    dmaru = dmalu;
/* SOURCE brnmat.for:2308 */
/*<       dmqru=dmqlu >*/
	    dmqru = dmqlu;
/* SOURCE brnmat.for:2309 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2310 */
/*<       jcol=jcol+2 >*/
	jcol += 2;
/* SOURCE brnmat.for:2312 */
/*<   100 continue >*/
/* L100: */
    }
/*      WRITE(STD6,*) ' ' */
/* SOURCE brnmat.for:2317 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:2318 */
/*<       end >*/
} /* seticx_ */




/* SOURCE brnmat.for:2322 */
/*<        >*/
/* Subroutine */ int setinw_(doublereal *dt, integer *nbr, integer *nbra, 
	real *wt, integer *feq_storage_brpt, integer *ieq, real *errp, real *errq, 
	integer *berrp, integer *nerrp, integer *berrq, integer *nerrq)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;

    /* Builtin functions */
    double r_sign(real *, real *), sqrt(doublereal);

    /* Local variables */
    real b, c1, c2, c3, c4, s1, s2, s3, cf, dh;
    integer fn;
    real wa;
    integer ln;
    real dv, dx, dy, dz, yc, qp, kp, zi, tp, ym, wx, dv2, dx2, kac, gde, ald, 
	    amd, bld, kdc, ard, brd, kld, kmd;
    integer nnd;
    real krd, alu, amu, blu, dxh, qld, aru, bru, err, qrd, klu, kmu, res, tld,
	     tpa, kru, qlu, tpb, tlu, tpc, tpd, qru, trd, vld, tru, vlu, vrd, 
	    vru, wtc, yld, ylu, yrd, yru, zit, ziy;
    integer ntab, jcol, adrs, ninc;
    real dblu, dbru, khlm, dklu, pgfu, dxdt, dkru, dtlu, qmax, dtru, ksum, 
	    sfmt, sfmu;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real dkhlm, dxhdt, pfqlu, pfqru, pfylu, pfyru;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    real sgndv2;
    integer elmadr, ubnbas;
    real dqpylu, dqpyru, dyndif, newsum, oldflw, oldimp, oldsum, oldvol, 
	    oldwnd;

/*     + + + PURPOSE + + + */
/*     Create the portion of the matrix corresponding to the */
/*     given branch number, NBR. IEQ gives the last equation created */
/*     in the matrix.  Used only for branches which have 2 unknowns */
/*     per node. Variable weight in x direction used. */
/* SOURCE brnmat.for:2333 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE brnmat.for:2335 */
/*<       integerberrp,berrq,ieq,nbr,nbra,nerrp,nerrq >*/
/* SOURCE brnmat.for:2336 */
/*<       integerbrpt(8,nbra) >*/
/* SOURCE brnmat.for:2337 */
/*<       realerrp,errq,wt >*/
/* SOURCE brnmat.for:2338 */
/*<       real*8dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     NBR    - number of the branch being processed */
/*     NBRA   - number of branches in the model */
/*     WT     - weight factor for approximating time integrals */
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
/*     IEQ    - equation number */
/*     ERRP   - current maximum relative change in surcharge storage */
/*     ERRQ   - maximum value of the ratio of lateral inflow to the */
/*               average flow in the element */
/*     BERRP  - records the branch number(internal) that has the */
/*               greatest absolute value of the change in surcharge */
/*               storage relative to the storage in the storm sewer */
/*     NERRP  - node at which maximum correction to surcharge storage */
/*               occurs */
/*     BERRQ  - records the branch number(internal) that has the */
/*               greatest value of the ratio of lateral inflow */
/*               to average flow in an element */
/*     NERRQ  - node at which maximum relative lateral inflow occurs */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE brnmat.for:2370 */
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
/* INCLUDE brnmat.for:2371 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE brnmat.for:2372 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:2373 */
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
/* INCLUDE brnmat.for:2374 */
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
/* INCLUDE brnmat.for:2375 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:2376 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:2379 */
/*<       integeradrs,elmadr,fn,jcol,ln,ninc,nnd,ntab,ubnbas >*/
/* SOURCE brnmat.for:2380 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE brnmat.for:2392 */
/*<       intrinsicabs,sign,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE brnmat.for:2395 */
/*<       externallktab,xlkt20 >*/
/* *********************************************************************** */
/* SOURCE brnmat.for:2397 */
/*<       wtc=1.0-wt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
    wtc = static_cast<double>((float)1.) - *wt;
/*     SET THE DIRECTION OF PROCESSING FOR THIS BRANCH.  THE SIGN OF THE */
/*     VARIABLE NUMBER FOR THE FIRST VARIABLE ON THE BRANCH SETS THE */
/*     DIRECTION */
/* SOURCE brnmat.for:2403 */
/*<       jcol=brpt(7,nbr) >*/
    jcol = brpt[(*nbr << 3) + 7];
/* SOURCE brnmat.for:2404 */
/*<       if(jcol.gt.0)then >*/
    if (jcol > 0) {
/* SOURCE brnmat.for:2405 */
/*<       fn=brpt(3,nbr) >*/
	fn = brpt[(*nbr << 3) + 3];
/* SOURCE brnmat.for:2406 */
/*<       ln=brpt(4,nbr) >*/
	ln = brpt[(*nbr << 3) + 4];
/* SOURCE brnmat.for:2407 */
/*<       ninc=1 >*/
	ninc = 1;
/*       SET THE USER BRANCH NODE BASE FOR REPORINT NERRQ AND NERRP */
/* SOURCE brnmat.for:2409 */
/*<       ubnbas=brpt(1,nbr)+1 >*/
	ubnbas = brpt[(*nbr << 3) + 1] + 1;
/* SOURCE brnmat.for:2410 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:2411 */
/*<       fn=brpt(4,nbr) >*/
	fn = brpt[(*nbr << 3) + 4];
/* SOURCE brnmat.for:2412 */
/*<       ln=brpt(3,nbr) >*/
	ln = brpt[(*nbr << 3) + 3];
/* SOURCE brnmat.for:2413 */
/*<       ninc=-1 >*/
	ninc = -1;
/* SOURCE brnmat.for:2414 */
/*<       jcol=-jcol >*/
	jcol = -jcol;
/* SOURCE brnmat.for:2415 */
/*<       ubnbas=brpt(2,nbr) >*/
	ubnbas = brpt[(*nbr << 3) + 2];
/* SOURCE brnmat.for:2416 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:2418 */
/*<       zi=zivec(nbr) >*/
    zi = bnothr_1.zivec[*nbr - 1];
/* SOURCE brnmat.for:2419 */
/*<       zit=zi >*/
    zit = zi;
/* SOURCE brnmat.for:2420 */
/*<       ziy=zilim(nbr) >*/
    ziy = bnothr_1.zilim[*nbr - 1];
/* SOURCE brnmat.for:2421 */
/*<       if(stflag.eq.0)then >*/
    if (bnelem_1.stflag == 0) {
/* SOURCE brnmat.for:2422 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:2423 */
/*<       tld=t1(fn) >*/
	    tld = bnelem_1.t1[fn - 1];
/* SOURCE brnmat.for:2424 */
/*<       ald=a1(fn) >*/
	    ald = bnelem_1.a1[fn - 1];
/* SOURCE brnmat.for:2425 */
/*<       yld=y1(fn) >*/
	    yld = bnelem_1.y1[fn - 1];
/* SOURCE brnmat.for:2426 */
/*<       bld=b1(fn) >*/
	    bld = bnelem_1.b1[fn - 1];
/* SOURCE brnmat.for:2427 */
/*<       qld=q1(fn) >*/
	    qld = bnelem_1.q1[fn - 1];
/* SOURCE brnmat.for:2428 */
/*<       kld=k1(fn) >*/
	    kld = bnelem_1.k1[fn - 1];
/* SOURCE brnmat.for:2429 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2430 */
/*<       trd=t1(fn) >*/
	    trd = bnelem_1.t1[fn - 1];
/* SOURCE brnmat.for:2431 */
/*<       ard=a1(fn) >*/
	    ard = bnelem_1.a1[fn - 1];
/* SOURCE brnmat.for:2432 */
/*<       yrd=y1(fn) >*/
	    yrd = bnelem_1.y1[fn - 1];
/* SOURCE brnmat.for:2433 */
/*<       brd=b1(fn) >*/
	    brd = bnelem_1.b1[fn - 1];
/* SOURCE brnmat.for:2434 */
/*<       qrd=q1(fn) >*/
	    qrd = bnelem_1.q1[fn - 1];
/* SOURCE brnmat.for:2435 */
/*<       krd=k1(fn) >*/
	    krd = bnelem_1.k1[fn - 1];
/* SOURCE brnmat.for:2436 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2437 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:2439 */
/*<       if(ninc.gt.0)then >*/
    if (ninc > 0) {
/* SOURCE brnmat.for:2440 */
/*<       qlu=q2(fn) >*/
	qlu = bnelem_1.q2[fn - 1];
/* SOURCE brnmat.for:2441 */
/*<       ylu=y2(fn) >*/
	ylu = bnelem_1.y2[fn - 1];
/* SOURCE brnmat.for:2442 */
/*<       callxlkt20(nsec(fn),ylu,alu,tlu,dtlu,klu,dklu,blu,dblu) >*/
	xlkt20_(&bnothr_1.nsec[fn - 1], &ylu, &alu, &tlu, &dtlu, &klu, &dklu, 
		&blu, &dblu);
/* SOURCE brnmat.for:2446 */
/*<       t2(fn)=tlu >*/
	bnelem_1.t2[fn - 1] = tlu;
/* SOURCE brnmat.for:2447 */
/*<       a2(fn)=alu >*/
	bnelem_1.a2[fn - 1] = alu;
/* SOURCE brnmat.for:2448 */
/*<       b2(fn)=blu >*/
	bnelem_1.b2[fn - 1] = blu;
/* SOURCE brnmat.for:2449 */
/*<       k2(fn)=klu >*/
	bnelem_1.k2[fn - 1] = klu;
/* SOURCE brnmat.for:2450 */
/*<       fn=fn+1 >*/
	++fn;
/* SOURCE brnmat.for:2451 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:2452 */
/*<       qru=q2(fn) >*/
	qru = bnelem_1.q2[fn - 1];
/* SOURCE brnmat.for:2453 */
/*<       yru=y2(fn) >*/
	yru = bnelem_1.y2[fn - 1];
/* SOURCE brnmat.for:2454 */
/*<       callxlkt20(nsec(fn),yru,aru,tru,dtru,kru,dkru,bru,dbru) >*/
	xlkt20_(&bnothr_1.nsec[fn - 1], &yru, &aru, &tru, &dtru, &kru, &dkru, 
		&bru, &dbru);
/* SOURCE brnmat.for:2458 */
/*<       t2(fn)=tru >*/
	bnelem_1.t2[fn - 1] = tru;
/* SOURCE brnmat.for:2459 */
/*<       a2(fn)=aru >*/
	bnelem_1.a2[fn - 1] = aru;
/* SOURCE brnmat.for:2460 */
/*<       b2(fn)=bru >*/
	bnelem_1.b2[fn - 1] = bru;
/* SOURCE brnmat.for:2461 */
/*<       k2(fn)=kru >*/
	bnelem_1.k2[fn - 1] = kru;
/* SOURCE brnmat.for:2462 */
/*<       fn=fn-1 >*/
	--fn;
/* SOURCE brnmat.for:2463 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:2465 */
/*<       do100nnd=fn,ln,ninc >*/
    feq_gen_i_d_1 = ln;
    feq_gen_i_d_2 = ninc;
    for (nnd = fn; feq_gen_i_d_2 < 0 ? nnd >= feq_gen_i_d_1 : nnd <= feq_gen_i_d_1; nnd += feq_gen_i_d_2) {
/* SOURCE brnmat.for:2466 */
/*<       if(ninc.eq.1)then >*/
	if (ninc == 1) {
/* SOURCE brnmat.for:2467 */
/*<       elmadr=nnd >*/
	    elmadr = nnd;
/* SOURCE brnmat.for:2468 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2469 */
/*<       elmadr=nnd+1 >*/
	    elmadr = nnd + 1;
/* SOURCE brnmat.for:2470 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2471 */
/*<       dx=dxvec(elmadr) >*/
	dx = bnelem_1.dxvec[elmadr - 1];
/* SOURCE brnmat.for:2472 */
/*<       dxh=0.5*dx >*/
	dxh = static_cast<double>(dx) * (float).5;
/* SOURCE brnmat.for:2473 */
/*<       dx2=dx+dx >*/
	dx2 = static_cast<double>(dx) + dx;
/* SOURCE brnmat.for:2474 */
/*<       dxdt=dx/dt >*/
	dxdt = dx / *dt;
/* SOURCE brnmat.for:2475 */
/*<       dxhdt=0.5*dxdt >*/
	dxhdt = static_cast<double>(dxdt) * (float).5;
/* SOURCE brnmat.for:2476 */
/*<       dz=dzvec(elmadr) >*/
	dz = bnelem_1.dzvec[elmadr - 1];
/* SOURCE brnmat.for:2477 */
/*<       kac=ka(elmadr) >*/
	kac = bnelem_1.ka[elmadr - 1];
/* SOURCE brnmat.for:2478 */
/*<       kdc=kd(elmadr) >*/
	kdc = bnelem_1.kd[elmadr - 1];
/* SOURCE brnmat.for:2479 */
/*<       adrs=hltab(elmadr) >*/
	adrs = bnothr_1.hltab[elmadr - 1];
/* SOURCE brnmat.for:2480 */
/*<       if(stflag.eq.0)then >*/
	if (bnelem_1.stflag == 0) {
/* SOURCE brnmat.for:2481 */
/*<       wx=wxvec(elmadr) >*/
	    wx = bnelem_1.wxvec[elmadr - 1];
/* SOURCE brnmat.for:2482 */
/*<       wa=wxvec1(elmadr) >*/
	    wa = bnelem_1.wxvec1[elmadr - 1];
/*            WRITE(STD6,3421) NND, ELMADR, WA */
/* 3421  FORMAT(' SETINW: NND=',I5,' ELMADR=',I5,' WA 1=',F10.5) */
/* SOURCE brnmat.for:2485 */
/*<       if(ninc.gt.0)then >*/
	    if (ninc > 0) {
/* SOURCE brnmat.for:2486 */
/*<       trd=t1(nnd) >*/
		trd = bnelem_1.t1[nnd - 1];
/* SOURCE brnmat.for:2487 */
/*<       ard=a1(nnd) >*/
		ard = bnelem_1.a1[nnd - 1];
/* SOURCE brnmat.for:2488 */
/*<       yrd=y1(nnd) >*/
		yrd = bnelem_1.y1[nnd - 1];
/* SOURCE brnmat.for:2489 */
/*<       brd=b1(nnd) >*/
		brd = bnelem_1.b1[nnd - 1];
/* SOURCE brnmat.for:2490 */
/*<       qrd=q1(nnd) >*/
		qrd = bnelem_1.q1[nnd - 1];
/* SOURCE brnmat.for:2491 */
/*<       krd=k1(nnd) >*/
		krd = bnelem_1.k1[nnd - 1];
/* SOURCE brnmat.for:2492 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2493 */
/*<       tld=t1(nnd) >*/
		tld = bnelem_1.t1[nnd - 1];
/* SOURCE brnmat.for:2494 */
/*<       ald=a1(nnd) >*/
		ald = bnelem_1.a1[nnd - 1];
/* SOURCE brnmat.for:2495 */
/*<       yld=y1(nnd) >*/
		yld = bnelem_1.y1[nnd - 1];
/* SOURCE brnmat.for:2496 */
/*<       bld=b1(nnd) >*/
		bld = bnelem_1.b1[nnd - 1];
/* SOURCE brnmat.for:2497 */
/*<       qld=q1(nnd) >*/
		qld = bnelem_1.q1[nnd - 1];
/* SOURCE brnmat.for:2498 */
/*<       kld=k1(nnd) >*/
		kld = bnelem_1.k1[nnd - 1];
/* SOURCE brnmat.for:2499 */
/*<       endif >*/
	    }
/*           SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL. */
/* SOURCE brnmat.for:2502 */
/*<       if(yld.lt.ziy.or.yrd.lt.ziy)then >*/
	    if (yld < ziy || yrd < ziy) {
/* SOURCE brnmat.for:2503 */
/*<       zi=0.0 >*/
		zi = (float)0.;
/* SOURCE brnmat.for:2504 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2505 */
/*<       zi=zit >*/
		zi = zit;
/* SOURCE brnmat.for:2506 */
/*<       endif >*/
	    }
/*           COMPUTE VALUES AT THE START OF THE TIME STEP AND STORE */
/* SOURCE brnmat.for:2510 */
/*<       oldsum=qld+qrd >*/
	    oldsum = static_cast<double>(qld) + qrd;
/* SOURCE brnmat.for:2512 */
/*<       sumvec(elmadr)=oldsum >*/
	    bnelem_1.sumvec[elmadr - 1] = oldsum;
/* SOURCE brnmat.for:2513 */
/*<       if(oldsum.lt.0.0)then >*/
	    if (oldsum < (float)0.) {
/* SOURCE brnmat.for:2514 */
/*<       wa=1.-wa >*/
		wa = static_cast<double>((float)1.) - wa;
/* SOURCE brnmat.for:2515 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2516 */
/*<       vld=qld/ald >*/
	    vld = static_cast<double>(qld) / ald;
/* SOURCE brnmat.for:2517 */
/*<       vrd=qrd/ard >*/
	    vrd = static_cast<double>(qrd) / ard;
/* SOURCE brnmat.for:2519 */
/*<       gde=0.0 >*/
	    gde = (float)0.;
/* SOURCE brnmat.for:2520 */
/*<       if(kdc.gt.0.0.or.kac.gt.0.0)then >*/
	    if (kdc > (float)0. || kac > (float)0.) {
/*             PROCESS EXPANSION AND CONTRACTION LOSSES */
/* SOURCE brnmat.for:2522 */
/*<       dv=vld-vrd >*/
		dv = static_cast<double>(vld) - vrd;
/* SOURCE brnmat.for:2523 */
/*<       if(dv.gt.0.0)then >*/
		if (dv > (float)0.) {
/*               FLOW IS UNDERGOING NEGATIVE ACCELERATION-TAKEN */
/*               TO INDICATE EXPANSION */
/* SOURCE brnmat.for:2526 */
/*<       kp=kdc >*/
		    kp = kdc;
/* SOURCE brnmat.for:2527 */
/*<       else >*/
		} else {
/*               FLOW IS UNDERGOING POSITIVE ACCELERATION- TAKEN TO */
/*               INDICATE CONTRACTION */
/* SOURCE brnmat.for:2530 */
/*<       kp=kac >*/
		    kp = kac;
/* SOURCE brnmat.for:2531 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:2532 */
/*<       gde=0.5*sign(kp,oldsum)*abs(dv*(vld+vrd)) >*/
		gde = r_sign(&kp, &oldsum) * (float).5 * (feq_gen_r_d_1 = static_cast<double>(dv) * (static_cast<double>(vld) + 
			vrd), dabs(feq_gen_r_d_1));
/* SOURCE brnmat.for:2533 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2535 */
/*<       if(adrs.gt.0)then >*/
	    if (adrs > 0) {
/*             POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT */
/* SOURCE brnmat.for:2537 */
/*<       ym=0.5*(yld+yrd) >*/
		ym = static_cast<double>((static_cast<double>(yld) + yrd)) * (float).5;
/* SOURCE brnmat.for:2538 */
/*<       calllktab(adrs,ym,0,khlm,ntab,dkhlm) >*/
		lktab_(&adrs, &ym, &feq_gen_c_d_0, &khlm, &ntab, &dkhlm);
/* SOURCE brnmat.for:2541 */
/*<       if(oldsum.lt.0.0)then >*/
		if (oldsum < (float)0.) {
/* SOURCE brnmat.for:2542 */
/*<       khlm=-khlm >*/
		    khlm = -khlm;
/* SOURCE brnmat.for:2543 */
/*<       dkhlm=-dkhlm >*/
		    dkhlm = -dkhlm;
/* SOURCE brnmat.for:2544 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:2546 */
/*<       gde=gde+0.5*khlm*(oldsum/(ald+ard))**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(oldsum) / (static_cast<double>(ald) + ard);
		gde += static_cast<double>(static_cast<double>(static_cast<double>(khlm) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE brnmat.for:2547 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2549 */
/*<       dy=yrd-yld >*/
	    dy = static_cast<double>(yrd) - yld;
/* SOURCE brnmat.for:2550 */
/*<       kmd=kld+wx*(krd-kld) >*/
	    kmd = static_cast<double>(kld) + static_cast<double>(wx) * (static_cast<double>(krd) - kld);
/* SOURCE brnmat.for:2551 */
/*<       amd=ald+wa*(ard-ald) >*/
	    amd = static_cast<double>(ald) + static_cast<double>(wa) * (static_cast<double>(ard) - ald);
/* SOURCE brnmat.for:2552 */
/*<        >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = kmd;
	    oldimp = (gravcm_1.grav * (dz + static_cast<double>(oldsum) * (float).25 * dabs(oldsum)
		     * dx / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + dy) + gde) * amd + static_cast<double>(zi) * (static_cast<double>(static_cast<double>(static_cast<double>(brd) * 
		    vrd) * qrd) - static_cast<double>(static_cast<double>(bld) * vld) * qld);
/* SOURCE brnmat.for:2556 */
/*<       impvec(elmadr)=oldimp >*/
	    bnelem_1.impvec[elmadr - 1] = oldimp;
/* SOURCE brnmat.for:2557 */
/*<       if(wsvec(elmadr).ne.0.0)then >*/
	    if (bnothr_1.wsvec[elmadr - 1] != (float)0.) {
/*             COMPUTE THE WIND STRESS TERM.  WSVEC IS USED TO HOLD */
/*             VALUE BECAUSE THE WIND STRESS IS RECOMPUTED FOR EACH */
/*             TIME STEP AT THE START OF THE TIME STEP.  WE USE THE */
/*             EULER APPROXIMATION FOR THE INTEGRAL TO SIMPLIFY THE */
/*             EQUATIONS. */
/* SOURCE brnmat.for:2564 */
/*<       oldwnd=dxh*(tld+trd)*wsvec(elmadr) >*/
		oldwnd = static_cast<double>(static_cast<double>(dxh) * (static_cast<double>(tld) + trd)) * bnothr_1.wsvec[elmadr - 1];
/* SOURCE brnmat.for:2565 */
/*<       wsvec(elmadr)=oldwnd >*/
		bnothr_1.wsvec[elmadr - 1] = oldwnd;
/* SOURCE brnmat.for:2566 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2567 */
/*<       oldwnd=0.0 >*/
		oldwnd = (float)0.;
/* SOURCE brnmat.for:2568 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2570 */
/*<       oldvol=amd >*/
	    oldvol = amd;
/* SOURCE brnmat.for:2571 */
/*<       volvec(elmadr)=oldvol >*/
	    bnelem_1.volvec[elmadr - 1] = oldvol;
/* SOURCE brnmat.for:2572 */
/*<       oldflw=qrd-qld >*/
	    oldflw = static_cast<double>(qrd) - qld;
/* SOURCE brnmat.for:2573 */
/*<       flwvec(elmadr)=oldflw >*/
	    bnelem_1.flwvec[elmadr - 1] = oldflw;
/* SOURCE brnmat.for:2575 */
/*<       if(ninc.gt.0)then >*/
	    if (ninc > 0) {
/* SOURCE brnmat.for:2576 */
/*<       yld=yrd >*/
		yld = yrd;
/* SOURCE brnmat.for:2577 */
/*<       tld=trd >*/
		tld = trd;
/* SOURCE brnmat.for:2578 */
/*<       ald=ard >*/
		ald = ard;
/* SOURCE brnmat.for:2579 */
/*<       bld=brd >*/
		bld = brd;
/* SOURCE brnmat.for:2580 */
/*<       kld=krd >*/
		kld = krd;
/* SOURCE brnmat.for:2581 */
/*<       qld=qrd >*/
		qld = qrd;
/* SOURCE brnmat.for:2582 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2583 */
/*<       yrd=yld >*/
		yrd = yld;
/* SOURCE brnmat.for:2584 */
/*<       trd=tld >*/
		trd = tld;
/* SOURCE brnmat.for:2585 */
/*<       ard=ald >*/
		ard = ald;
/* SOURCE brnmat.for:2586 */
/*<       brd=bld >*/
		brd = bld;
/* SOURCE brnmat.for:2587 */
/*<       krd=kld >*/
		krd = kld;
/* SOURCE brnmat.for:2588 */
/*<       qrd=qld >*/
		qrd = qld;
/* SOURCE brnmat.for:2589 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2590 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2591 */
/*<       oldsum=sumvec(elmadr) >*/
	    oldsum = bnelem_1.sumvec[elmadr - 1];
/* SOURCE brnmat.for:2592 */
/*<       oldimp=impvec(elmadr) >*/
	    oldimp = bnelem_1.impvec[elmadr - 1];
/* SOURCE brnmat.for:2593 */
/*<       oldvol=volvec(elmadr) >*/
	    oldvol = bnelem_1.volvec[elmadr - 1];
/* SOURCE brnmat.for:2594 */
/*<       oldflw=flwvec(elmadr) >*/
	    oldflw = bnelem_1.flwvec[elmadr - 1];
/* SOURCE brnmat.for:2595 */
/*<       oldwnd=wsvec(elmadr) >*/
	    oldwnd = bnothr_1.wsvec[elmadr - 1];
/* SOURCE brnmat.for:2596 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2598 */
/*<       wa=wxvec2(elmadr) >*/
	wa = bnelem_1.wxvec2[elmadr - 1];
/*            WRITE(STD6,3423) NND, ELMADR, WA */
/* 3423  FORMAT(' SETINW: NND=',I5,' ELMADR=',I5,' WA 2=',F10.5) */
/* SOURCE brnmat.for:2602 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:2603 */
/*<       qru=q2(nnd) >*/
	    qru = bnelem_1.q2[nnd - 1];
/* SOURCE brnmat.for:2604 */
/*<       yru=y2(nnd) >*/
	    yru = bnelem_1.y2[nnd - 1];
/* SOURCE brnmat.for:2605 */
/*<       callxlkt20(nsec(nnd),yru,aru,tru,dtru,kru,dkru,bru,dbru) >*/
	    xlkt20_(&bnothr_1.nsec[nnd - 1], &yru, &aru, &tru, &dtru, &kru, &
		    dkru, &bru, &dbru);
/* SOURCE brnmat.for:2609 */
/*<       t2(nnd)=tru >*/
	    bnelem_1.t2[nnd - 1] = tru;
/* SOURCE brnmat.for:2610 */
/*<       a2(nnd)=aru >*/
	    bnelem_1.a2[nnd - 1] = aru;
/* SOURCE brnmat.for:2611 */
/*<       b2(nnd)=bru >*/
	    bnelem_1.b2[nnd - 1] = bru;
/* SOURCE brnmat.for:2612 */
/*<       k2(nnd)=kru >*/
	    bnelem_1.k2[nnd - 1] = kru;
/* SOURCE brnmat.for:2613 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2614 */
/*<       qlu=q2(nnd) >*/
	    qlu = bnelem_1.q2[nnd - 1];
/* SOURCE brnmat.for:2615 */
/*<       ylu=y2(nnd) >*/
	    ylu = bnelem_1.y2[nnd - 1];
/* SOURCE brnmat.for:2616 */
/*<       callxlkt20(nsec(nnd),ylu,alu,tlu,dtlu,klu,dklu,blu,dblu) >*/
	    xlkt20_(&bnothr_1.nsec[nnd - 1], &ylu, &alu, &tlu, &dtlu, &klu, &
		    dklu, &blu, &dblu);
/* SOURCE brnmat.for:2620 */
/*<       t2(nnd)=tlu >*/
	    bnelem_1.t2[nnd - 1] = tlu;
/* SOURCE brnmat.for:2621 */
/*<       a2(nnd)=alu >*/
	    bnelem_1.a2[nnd - 1] = alu;
/* SOURCE brnmat.for:2622 */
/*<       b2(nnd)=blu >*/
	    bnelem_1.b2[nnd - 1] = blu;
/* SOURCE brnmat.for:2623 */
/*<       k2(nnd)=klu >*/
	    bnelem_1.k2[nnd - 1] = klu;
/* SOURCE brnmat.for:2624 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2625 */
/*<       newsum=qlu+qru >*/
	newsum = static_cast<double>(qlu) + qru;
/* SOURCE brnmat.for:2626 */
/*<       if(newsum.lt.0.0)then >*/
	if (newsum < (float)0.) {
/* SOURCE brnmat.for:2627 */
/*<       wa=1.-wa >*/
	    wa = static_cast<double>((float)1.) - wa;
/* SOURCE brnmat.for:2628 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2629 */
/*<       dy=yru-ylu >*/
	dy = static_cast<double>(yru) - ylu;
/*         SELECT NEW VALUE OF WX. */
/* SOURCE brnmat.for:2631 */
/*<       kmu=0.5*(klu+kru) >*/
	kmu = static_cast<double>((static_cast<double>(klu) + kru)) * (float).5;
/* SOURCE brnmat.for:2632 */
/*<       if(newsum.ge.0.0)then >*/
	if (newsum >= (float)0.) {
/*           FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT. */
/*            WRITE(STD6,*) ' CRITERION=',DKRU*(-DY - DZ) - KMU */
/*            WRITE(STD6,*) ' DKRU=',DKRU,'DY+DZ=',DY+DZ,' KMU=',KMU */
/* SOURCE brnmat.for:2636 */
/*<       if(dkru*(-dy-dz)-kmu.ge.0.0)then >*/
	    if (static_cast<double>(static_cast<double>(dkru) * (static_cast<double>(-dy) - dz)) - kmu >= (float)0.) {
/*             SHIFT TO UPSTREAM CONVEYANCE. */
/* SOURCE brnmat.for:2638 */
/*<       wx=0.4*klu/(dkru*(-dy-dz)-0.5*(kru-klu)) >*/
		wx = static_cast<double>(static_cast<double>(klu) * (float).4) / (static_cast<double>(static_cast<double>(dkru) * (static_cast<double>(-dy) - dz)) - static_cast<double>((static_cast<double>(kru) - klu)) * (
			float).5);
/* SOURCE brnmat.for:2639 */
/*<       kmu=klu+wx*(kru-klu) >*/
		kmu = static_cast<double>(klu) + static_cast<double>(wx) * (static_cast<double>(kru) - klu);
/* SOURCE brnmat.for:2640 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2641 */
/*<       wx=0.5 >*/
		wx = (float).5;
/* SOURCE brnmat.for:2642 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2643 */
/*<       else >*/
	} else {
/*           FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT. */
/* SOURCE brnmat.for:2645 */
/*<       if(dklu*(dy+dz)-kmu.ge.0.0)then >*/
	    if (static_cast<double>(static_cast<double>(dklu) * (static_cast<double>(dy) + dz)) - kmu >= (float)0.) {
/*             SHIFT TO UPSTREAM CONVEYANCE */
/* SOURCE brnmat.for:2647 */
/*<       wx=1.0-0.4*kru/(dklu*(dy+dz)-.5*(kru-klu)) >*/
		wx = static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(kru) * (float).4) / (static_cast<double>(static_cast<double>(dklu) * (static_cast<double>(dy) + dz)) - static_cast<double>((static_cast<double>(kru) - 
			klu)) * (float).5);
/* SOURCE brnmat.for:2648 */
/*<       kmu=klu+wx*(kru-klu) >*/
		kmu = static_cast<double>(klu) + static_cast<double>(wx) * (static_cast<double>(kru) - klu);
/* SOURCE brnmat.for:2649 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2650 */
/*<       wx=0.5 >*/
		wx = (float).5;
/* SOURCE brnmat.for:2651 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2652 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2654 */
/*<       amu=alu+wa*(aru-alu) >*/
	amu = static_cast<double>(alu) + static_cast<double>(wa) * (static_cast<double>(aru) - alu);
/* SOURCE brnmat.for:2655 */
/*<       wxvec(elmadr)=wx >*/
	bnelem_1.wxvec[elmadr - 1] = wx;
/* SOURCE brnmat.for:2656 */
/*<       ksum=kmu+kmu >*/
	ksum = static_cast<double>(kmu) + kmu;
/*          IF(STFLAG.EQ.0) */
/*     A     WRITE(STD6,'(6H RDVAL,6F10.3)') YRD, TRD, ARD, KRD, BRD, QRD */
/*        WRITE(STD6,'(6H RUVAL,7F10.3)') YRU, TRU, ARU, KRU, BRU, QRU, DKRU */
/*         SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL. */
/* SOURCE brnmat.for:2663 */
/*<       if(ylu.lt.ziy.or.yru.lt.ziy)then >*/
	if (ylu < ziy || yru < ziy) {
/* SOURCE brnmat.for:2664 */
/*<       zi=0.0 >*/
	    zi = (float)0.;
/* SOURCE brnmat.for:2665 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2666 */
/*<       zi=zit >*/
	    zi = zit;
/* SOURCE brnmat.for:2667 */
/*<       endif >*/
	}
/*         CONTINUITY EQUATION */
/*         1) PARTIAL DERIVATIVES */
/*          WRITE(STD6,*) ' DXHDT=',DXHDT,' TLU=',TLU,' TRU=',TRU */
/* SOURCE brnmat.for:2675 */
/*<       c1=dxdt*(1.-wa)*tlu >*/
	c1 = static_cast<double>(static_cast<double>(dxdt) * (static_cast<double>((float)1.) - wa)) * tlu;
/* SOURCE brnmat.for:2676 */
/*<       c2=-wt >*/
	c2 = -(*wt);
/* SOURCE brnmat.for:2677 */
/*<       c3=dxdt*(wa)*tru >*/
	c3 = static_cast<double>(static_cast<double>(dxdt) * wa) * tru;
/* SOURCE brnmat.for:2678 */
/*<       c4=wt >*/
	c4 = *wt;
/* SOURCE brnmat.for:2680 */
/*<       qp=qpvec(elmadr) >*/
	qp = bnothr_1.qpvec[elmadr - 1];
/* SOURCE brnmat.for:2681 */
/*<       cf=coefin(elmadr) >*/
	cf = bnpond_1.coefin[elmadr - 1];
/* SOURCE brnmat.for:2682 */
/*<       if(cf.gt.0.0)then >*/
	if (cf > (float)0.) {
/*            PROCESS INFLOW RESTRICTION ON SEWERS */
/* SOURCE brnmat.for:2686 */
/*<       yc=ycut(elmadr) >*/
	    yc = bnpond_1.ycut[elmadr - 1];
/* SOURCE brnmat.for:2687 */
/*<       s1=pond1(elmadr) >*/
	    s1 = bnpond_1.pond1[elmadr - 1];
/* SOURCE brnmat.for:2688 */
/*<       s2=pond2(elmadr) >*/
	    s2 = bnpond_1.pond2[elmadr - 1];
/* SOURCE brnmat.for:2689 */
/*<       ym=0.5*((ylu+yru)) >*/
	    ym = static_cast<double>((static_cast<double>(ylu) + yru)) * (float).5;
/* SOURCE brnmat.for:2690 */
/*<       dh=yc-ym >*/
	    dh = static_cast<double>(yc) - ym;
/* SOURCE brnmat.for:2691 */
/*<       if(abs(dh).le.dhstar)then >*/
	    if (dabs(dh) <= miscon_1.dhstar) {
/* SOURCE brnmat.for:2692 */
/*<       qmax=dh*cf*qpcon >*/
		qmax = static_cast<double>(static_cast<double>(dh) * cf) * miscon_1.qpcon;
/* SOURCE brnmat.for:2693 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2694 */
/*<       qmax=cf*sqrt(twog*abs(dh)) >*/
		qmax = cf * sqrt(gravcm_1.twog * dabs(dh));
/* SOURCE brnmat.for:2695 */
/*<       if(dh.lt.0.0)qmax=-qmax >*/
		if (dh < (float)0.) {
		    qmax = -qmax;
		}
/* SOURCE brnmat.for:2696 */
/*<       endif >*/
	    }
/*            CHECK FOR FLOW ALLOWED */
/* SOURCE brnmat.for:2700 */
/*<       tp=qp+s1/dt >*/
	    tp = qp + s1 / *dt;
/* SOURCE brnmat.for:2701 */
/*<       if(qmax.gt.tp)then >*/
	    if (qmax > tp) {
/* SOURCE brnmat.for:2702 */
/*<       pond2(elmadr)=0.0 >*/
		bnpond_1.pond2[elmadr - 1] = (float)0.;
/* SOURCE brnmat.for:2703 */
/*<       qp=tp >*/
		qp = tp;
/* SOURCE brnmat.for:2704 */
/*<       dqpylu=0.0 >*/
		dqpylu = (float)0.;
/* SOURCE brnmat.for:2705 */
/*<       dqpyru=0.0 >*/
		dqpyru = (float)0.;
/* SOURCE brnmat.for:2706 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:2707 */
/*<       s3=s1+dt*(qp-qmax) >*/
		s3 = s1 + *dt * (static_cast<double>(qp) - qmax);
/* SOURCE brnmat.for:2708 */
/*<       b=abs(s2-s3)/(dx*oldvol) >*/
		b = (feq_gen_r_d_1 = static_cast<double>(s2) - s3, dabs(feq_gen_r_d_1)) / (static_cast<double>(dx) * oldvol);
/* SOURCE brnmat.for:2709 */
/*<       if(b.gt.errp)then >*/
		if (b > *errp) {
/* SOURCE brnmat.for:2710 */
/*<       errp=b >*/
		    *errp = b;
/* SOURCE brnmat.for:2711 */
/*<       nerrp=ubnbas+nnd-fn >*/
		    *nerrp = ubnbas + nnd - fn;
/* SOURCE brnmat.for:2712 */
/*<       berrp=nbr >*/
		    *berrp = *nbr;
/* SOURCE brnmat.for:2713 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:2714 */
/*<       pond2(elmadr)=s3 >*/
		bnpond_1.pond2[elmadr - 1] = s3;
/* SOURCE brnmat.for:2715 */
/*<       qp=qmax >*/
		qp = qmax;
/* SOURCE brnmat.for:2716 */
/*<       if(abs(dh).le.dhstar)then >*/
		if (dabs(dh) <= miscon_1.dhstar) {
/* SOURCE brnmat.for:2717 */
/*<       dqpylu=-0.5*cf*qpcon >*/
		    dqpylu = static_cast<double>(static_cast<double>(cf) * (float)-.5) * miscon_1.qpcon;
/* SOURCE brnmat.for:2718 */
/*<       dqpyru=dqpylu >*/
		    dqpyru = dqpylu;
/* SOURCE brnmat.for:2719 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:2720 */
/*<       dqpylu=-halfg*cf*cf/abs(qp) >*/
		    dqpylu = static_cast<double>(static_cast<double>(-gravcm_1.halfg) * cf) * cf / dabs(qp);
/* SOURCE brnmat.for:2721 */
/*<       dqpyru=dqpylu >*/
		    dqpyru = dqpylu;
/* SOURCE brnmat.for:2722 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:2723 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2724 */
/*<       c1=c1-dqpylu >*/
	    c1 -= dqpylu;
/* SOURCE brnmat.for:2725 */
/*<       c3=c3-dqpyru >*/
	    c3 -= dqpyru;
/* SOURCE brnmat.for:2727 */
/*<       endif >*/
	}
/*         2) RESIDUAL */
/* SOURCE brnmat.for:2730 */
/*<       ieq=ieq+1 >*/
	++(*ieq);
/* SOURCE brnmat.for:2732 */
/*<       dyndif=oldflw+wt*(qru-qlu-oldflw)-qp >*/
	dyndif = static_cast<double>(static_cast<double>(oldflw) + static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(qru) - qlu) - oldflw)) - qp;
/* SOURCE brnmat.for:2733 */
/*<       res=-((amu-oldvol)*dxdt+dyndif) >*/
	res = -(static_cast<double>(static_cast<double>((static_cast<double>(amu) - oldvol)) * dxdt) + dyndif);
/*        WRITE(STD6,1932) C2, C1, C4, C3, -RES */
/*         RESCALE THE CURRENT EQUATION */
/*          CMAX = 1.0/MAX(ABS(C1), ABS(C2), ABS(C3), ABS(C4)) */
/*         JCOL GIVES THE VARIABLE NUMBER AT THE FIRST COEFFICIENT IN */
/*         THE EQUATIONS. */
/* SOURCE brnmat.for:2745 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:2746 */
/*<       pdavec(r(ieq))=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c2;
/* SOURCE brnmat.for:2747 */
/*<       pdavec(c(jcol+1))=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 1] - 1] = c1;
/* SOURCE brnmat.for:2748 */
/*<       pdavec(c(jcol+2)-1)=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 2] = c4;
/* SOURCE brnmat.for:2749 */
/*<       pdavec(c(jcol+3)-2)=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 3] = c3;
/* SOURCE brnmat.for:2750 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2751 */
/*<       pdavec(r(ieq))=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c4;
/* SOURCE brnmat.for:2752 */
/*<       pdavec(c(jcol+1))=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 1] - 1] = c3;
/* SOURCE brnmat.for:2753 */
/*<       pdavec(c(jcol+2)-1)=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 2] = c2;
/* SOURCE brnmat.for:2754 */
/*<       pdavec(c(jcol+3)-2)=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 3] = c1;
/* SOURCE brnmat.for:2755 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2757 */
/*<       rhs(ieq)=res >*/
	matcom_1.rhs[*ieq - 1] = res;
/* SOURCE brnmat.for:2760 */
/*<       err=abs(qp)/(abs(0.5*oldsum)+0.1) >*/
	err = dabs(qp) / ((feq_gen_r_d_1 = static_cast<double>(oldsum) * (float).5, dabs(feq_gen_r_d_1)) + (float).1)
		;
/* SOURCE brnmat.for:2761 */
/*<       if(err.gt.errq)then >*/
	if (err > *errq) {
/* SOURCE brnmat.for:2762 */
/*<       errq=err >*/
	    *errq = err;
/* SOURCE brnmat.for:2763 */
/*<       berrq=nbr >*/
	    *berrq = *nbr;
/* SOURCE brnmat.for:2764 */
/*<       nerrq=ubnbas+nnd-fn >*/
	    *nerrq = ubnbas + nnd - fn;
/* SOURCE brnmat.for:2765 */
/*<       endif >*/
	}
/*       MOMENTUM EQUATION */
/* SOURCE brnmat.for:2773 */
/*<       sfmt=abs(newsum)/ksum**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ksum;
	sfmt = dabs(newsum) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:2774 */
/*<       sfmu=newsum*sfmt >*/
	sfmu = static_cast<double>(newsum) * sfmt;
/*        WRITE(STD6,*) ' SFMU=', SFMU */
/* SOURCE brnmat.for:2776 */
/*<       pgfu=grav*(dz+sfmu*dx+dy) >*/
	pgfu = static_cast<double>(gravcm_1.grav) * (static_cast<double>(static_cast<double>(dz) + static_cast<double>(sfmu) * dx) + dy);
/* SOURCE brnmat.for:2777 */
/*<       vlu=qlu/alu >*/
	vlu = static_cast<double>(qlu) / alu;
/* SOURCE brnmat.for:2778 */
/*<       vru=qru/aru >*/
	vru = static_cast<double>(qru) / aru;
/* SOURCE brnmat.for:2779 */
/*<       tpa=(dx2+dx2)*sfmu/ksum >*/
	tpa = static_cast<double>(static_cast<double>((static_cast<double>(dx2) + dx2)) * sfmu) / ksum;
/* SOURCE brnmat.for:2780 */
/*<       tpb=amu*grav*dx2*sfmt >*/
	tpb = static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * dx2) * sfmt;
/*       PARTIAL DERIVATIVES */
/* SOURCE brnmat.for:2784 */
/*<        >*/
	c1 = static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * (static_cast<double>(static_cast<double>(static_cast<double>(-tpa) * dklu) * (static_cast<double>((float)1.) - wx)) - (
		float)1.)) + static_cast<double>(static_cast<double>(pgfu) * (static_cast<double>((float)1.) - wa)) * tlu) - static_cast<double>(static_cast<double>(zi) * (static_cast<double>(static_cast<double>(dblu) * qlu) 
		- static_cast<double>(static_cast<double>(tlu) * blu) * vlu)) * vlu);
/* SOURCE brnmat.for:2790 */
/*<       c2=zi*dxhdt+wt*(tpb-2.*zi*blu*vlu) >*/
	c2 = static_cast<double>(static_cast<double>(zi) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(tpb) - static_cast<double>(static_cast<double>(static_cast<double>(zi) * (float)2.) * blu) * vlu);
/* SOURCE brnmat.for:2793 */
/*<        >*/
	c3 = static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * (static_cast<double>(static_cast<double>(static_cast<double>(-tpa) * dkru) * wx) + (float)1.)) + 
		static_cast<double>(static_cast<double>(pgfu) * wa) * tru) + static_cast<double>(static_cast<double>(zi) * (static_cast<double>(static_cast<double>(dbru) * qru) - static_cast<double>(static_cast<double>(tru) * bru) * vru)) * vru);
/* SOURCE brnmat.for:2798 */
/*<       c4=zi*dxhdt+wt*(tpb+2.*zi*bru*vru) >*/
	c4 = static_cast<double>(static_cast<double>(zi) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(tpb) + static_cast<double>(static_cast<double>(static_cast<double>(zi) * (float)2.) * bru) * vru);
/* SOURCE brnmat.for:2801 */
/*<       if(kdc.gt.0.0.or.kac.gt.0.0)then >*/
	if (kdc > (float)0. || kac > (float)0.) {
/*         PROCESS EXPANSION AND CONTRACTION LOSSES */
/* SOURCE brnmat.for:2803 */
/*<       dv2=(vru-vlu)*(vru+vlu) >*/
	    dv2 = static_cast<double>((static_cast<double>(vru) - vlu)) * (static_cast<double>(vru) + vlu);
/*         Establish the sign of the difference in */
/*         the squared velocities. */
/* SOURCE brnmat.for:2806 */
/*<       sgndv2=sign(1.0,dv2) >*/
	    sgndv2 = r_sign(&c_b107, &dv2);
/*         Absolute value of difference of squares is */
/*         needed as well. */
/* SOURCE brnmat.for:2809 */
/*<       dv2=abs(dv2) >*/
	    dv2 = dabs(dv2);
/* SOURCE brnmat.for:2810 */
/*<       if(vlu.ge.vru)then >*/
	    if (vlu >= vru) {
/*           FLOW IS UNDERGOING NEGATIVE ACCELERATION */
/*            idir = -1 */
/* SOURCE brnmat.for:2813 */
/*<       kp=sign(kdc,newsum) >*/
		kp = r_sign(&kdc, &newsum);
/* SOURCE brnmat.for:2814 */
/*<       else >*/
	    } else {
/*           FLOW IS UNDERGOING POSITIVE ACCELERATION */
/*            idir = +1 */
/* SOURCE brnmat.for:2817 */
/*<       kp=sign(kac,newsum) >*/
		kp = r_sign(&kac, &newsum);
/* SOURCE brnmat.for:2818 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2820 */
/*<       pfqlu=-kp*sgndv2*amu*vlu/alu >*/
	    pfqlu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(-kp) * sgndv2) * amu) * vlu) / alu;
/* SOURCE brnmat.for:2821 */
/*<       pfqru=kp*sgndv2*amu*vru/aru >*/
	    pfqru = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(kp) * sgndv2) * amu) * vru) / aru;
/* SOURCE brnmat.for:2822 */
/*<       pfylu=tlu*(0.25*kp*dv2-pfqlu*vlu) >*/
	    pfylu = static_cast<double>(tlu) * (static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).25) * dv2) - static_cast<double>(pfqlu) * vlu);
/* SOURCE brnmat.for:2823 */
/*<       pfyru=tru*(0.25*kp*dv2-pfqru*vru) >*/
	    pfyru = static_cast<double>(tru) * (static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).25) * dv2) - static_cast<double>(pfqru) * vru);
/* SOURCE brnmat.for:2824 */
/*<       gde=0.5*kp*dv2 >*/
	    gde = static_cast<double>(static_cast<double>(kp) * (float).5) * dv2;
/* SOURCE brnmat.for:2826 */
/*<       pgfu=pgfu+gde >*/
	    pgfu += gde;
/* SOURCE brnmat.for:2827 */
/*<       c1=c1+wt*pfylu >*/
	    c1 += static_cast<double>(*wt) * pfylu;
/* SOURCE brnmat.for:2828 */
/*<       c2=c2+wt*pfqlu >*/
	    c2 += static_cast<double>(*wt) * pfqlu;
/* SOURCE brnmat.for:2829 */
/*<       c3=c3+wt*pfyru >*/
	    c3 += static_cast<double>(*wt) * pfyru;
/* SOURCE brnmat.for:2830 */
/*<       c4=c4+wt*pfqru >*/
	    c4 += static_cast<double>(*wt) * pfqru;
/* SOURCE brnmat.for:2832 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2834 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/*         POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT */
/* SOURCE brnmat.for:2836 */
/*<       ym=0.5*(ylu+yru) >*/
	    ym = static_cast<double>((static_cast<double>(ylu) + yru)) * (float).5;
/* SOURCE brnmat.for:2837 */
/*<       calllktab(adrs,ym,0,khlm,ntab,dkhlm) >*/
	    lktab_(&adrs, &ym, &feq_gen_c_d_0, &khlm, &ntab, &dkhlm);
/* SOURCE brnmat.for:2840 */
/*<       if(newsum.lt.0.0)then >*/
	    if (newsum < (float)0.) {
/* SOURCE brnmat.for:2841 */
/*<       khlm=-khlm >*/
		khlm = -khlm;
/* SOURCE brnmat.for:2842 */
/*<       dkhlm=-dkhlm >*/
		dkhlm = -dkhlm;
/* SOURCE brnmat.for:2843 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:2845 */
/*<       tpa=newsum/(alu+aru)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(alu) + aru;
	    tpa = static_cast<double>(newsum) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:2846 */
/*<       tpb=tpa*newsum >*/
	    tpb = static_cast<double>(tpa) * newsum;
/* SOURCE brnmat.for:2847 */
/*<       gde=0.5*khlm*tpb >*/
	    gde = static_cast<double>(static_cast<double>(khlm) * (float).5) * tpb;
/* SOURCE brnmat.for:2848 */
/*<       pgfu=pgfu+gde >*/
	    pgfu += gde;
/* SOURCE brnmat.for:2849 */
/*<       tpc=wt*amu >*/
	    tpc = static_cast<double>(*wt) * amu;
/* SOURCE brnmat.for:2850 */
/*<       tpd=khlm*tpa >*/
	    tpd = static_cast<double>(khlm) * tpa;
/* SOURCE brnmat.for:2852 */
/*<       c1=c1-tpc*(tpd*tlu-dkhlm*tpb) >*/
	    c1 -= static_cast<double>(tpc) * (static_cast<double>(static_cast<double>(tpd) * tlu) - static_cast<double>(dkhlm) * tpb);
/* SOURCE brnmat.for:2853 */
/*<       c2=c2+tpc*tpd >*/
	    c2 += static_cast<double>(tpc) * tpd;
/* SOURCE brnmat.for:2854 */
/*<       c3=c3-tpc*(tpd*tru-dkhlm*tpb) >*/
	    c3 -= static_cast<double>(tpc) * (static_cast<double>(static_cast<double>(tpd) * tru) - static_cast<double>(dkhlm) * tpb);
/* SOURCE brnmat.for:2855 */
/*<       c4=c4+tpc*tpd >*/
	    c4 += static_cast<double>(tpc) * tpd;
/* SOURCE brnmat.for:2856 */
/*<       endif >*/
	}
/*        IF(C1.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C1=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C2.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C2=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C3.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C3=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C4.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C4=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*       RESIDUAL */
/* SOURCE brnmat.for:2878 */
/*<        >*/
	res = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(zi) * (static_cast<double>(newsum) - oldsum)) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(pgfu) * amu) + static_cast<double>(zi) * (static_cast<double>(static_cast<double>(static_cast<double>(bru) *
		 qru) * vru) - static_cast<double>(static_cast<double>(blu) * qlu) * vlu))) + static_cast<double>(wtc) * oldimp) - oldwnd;
/*        WRITE(STD6,1932) ,C2, C1, C4, C3, RES */
/* 1932    FORMAT(1X,5(1PE11.3)) */
/*         RESCALE THE CURRENT EQUATION */
/*          CMAX = 1.0/MAX(ABS(C1), ABS(C2), ABS(C3), ABS(C4)) */
/* SOURCE brnmat.for:2889 */
/*<       ieq=ieq+1 >*/
	++(*ieq);
/* SOURCE brnmat.for:2890 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:2891 */
/*<       pdavec(r(ieq)-1)=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 2] = c2;
/* SOURCE brnmat.for:2892 */
/*<       pdavec(r(ieq))=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c1;
/* SOURCE brnmat.for:2893 */
/*<       pdavec(c(jcol+2))=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 1] = c4;
/* SOURCE brnmat.for:2894 */
/*<       pdavec(c(jcol+3)-1)=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 2] = c3;
/* SOURCE brnmat.for:2895 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2896 */
/*<       pdavec(r(ieq)-1)=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 2] = c4;
/* SOURCE brnmat.for:2897 */
/*<       pdavec(r(ieq))=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c3;
/* SOURCE brnmat.for:2898 */
/*<       pdavec(c(jcol+2))=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 1] = c2;
/* SOURCE brnmat.for:2899 */
/*<       pdavec(c(jcol+3)-1)=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 2] = c1;
/* SOURCE brnmat.for:2900 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2902 */
/*<       rhs(ieq)=-res >*/
	matcom_1.rhs[*ieq - 1] = -res;
/*         TRANSFER VALUES */
/* SOURCE brnmat.for:2906 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:2907 */
/*<       qlu=qru >*/
	    qlu = qru;
/* SOURCE brnmat.for:2908 */
/*<       alu=aru >*/
	    alu = aru;
/* SOURCE brnmat.for:2909 */
/*<       tlu=tru >*/
	    tlu = tru;
/* SOURCE brnmat.for:2910 */
/*<       ylu=yru >*/
	    ylu = yru;
/* SOURCE brnmat.for:2911 */
/*<       klu=kru >*/
	    klu = kru;
/* SOURCE brnmat.for:2912 */
/*<       dklu=dkru >*/
	    dklu = dkru;
/* SOURCE brnmat.for:2913 */
/*<       blu=bru >*/
	    blu = bru;
/* SOURCE brnmat.for:2914 */
/*<       dblu=dbru >*/
	    dblu = dbru;
/* SOURCE brnmat.for:2915 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:2916 */
/*<       qru=qlu >*/
	    qru = qlu;
/* SOURCE brnmat.for:2917 */
/*<       aru=alu >*/
	    aru = alu;
/* SOURCE brnmat.for:2918 */
/*<       tru=tlu >*/
	    tru = tlu;
/* SOURCE brnmat.for:2919 */
/*<       yru=ylu >*/
	    yru = ylu;
/* SOURCE brnmat.for:2920 */
/*<       kru=klu >*/
	    kru = klu;
/* SOURCE brnmat.for:2921 */
/*<       dkru=dklu >*/
	    dkru = dklu;
/* SOURCE brnmat.for:2922 */
/*<       bru=blu >*/
	    bru = blu;
/* SOURCE brnmat.for:2923 */
/*<       dbru=dblu >*/
	    dbru = dblu;
/* SOURCE brnmat.for:2924 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2925 */
/*<       jcol=jcol+2 >*/
	jcol += 2;
/* SOURCE brnmat.for:2927 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE brnmat.for:2930 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:2931 */
/*<       end >*/
} /* setinw_ */




/* SOURCE brnmat.for:2935 */
/*<       subroutinexxlkt20(adrs,ya,a,t,dt,k,dk,b,db) >*/
/* Subroutine */ int xxlkt20_(integer *adrs, real *ya, real *a, real *t, real 
	*dt, real *k, real *dk, real *b, real *db)
{
    /* System generated locals */
    doublereal feq_gen_r_d_1;

    /* Local variables */
    doublereal feq_gen_h_d_;
    integer l;
    doublereal p, y, b0, b1, k0, k1, t0, y0, fl, fr;
    integer it;
    doublereal dy, db0, db1, dk0, dk1, dmf, dlp, flp, dyi, drp, frp;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Experiment with speed up of look up. */
/*     + + + PURPOSE + + + */
/*     Given depth find area, top-width, conveyance, etc. */
/*     using direct linear interpolation for top width. */
/* SOURCE brnmat.for:2945 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE brnmat.for:2947 */
/*<       integeradrs >*/
/* SOURCE brnmat.for:2948 */
/*<       reala,b,db,dk,dt,k,t,ya >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     YA     - depth to use for table look up */
/*     A      - Cross sectional area from the cross section table */
/*     T      - top width of the cross section */
/*     DT     - derivative of the top width with respect to depth */
/*     K      - conveyance */
/*     DK     - derivative of conveyance with respect to depth */
/*     B      - the value of the momentum flux correction coef. from the */
/*               table */
/*     DB     - derivative of B with respect to depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE brnmat.for:2963 */
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
/* INCLUDE brnmat.for:2964 */
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
/* INCLUDE brnmat.for:2965 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:2968 */
/*<       integerit,l,type,xoff,doff >*/
/* SOURCE brnmat.for:2969 */
/*<       realb0,dy,dyi,h,k0,t0,y,y0,b1,k1,db0,db1,dk0,dk1 >*/
/* SOURCE brnmat.for:2971 */
/*<       realflp,frp,fl,fr,dlp,drp,dmf,p >*/
/* *********************************************************************** */
/*     L = ADDRESS FOUND ON THE LAST CALL TO XLKT20 */
/* SOURCE brnmat.for:2975 */
/*<       y=ya >*/
    y = *ya;
/* SOURCE brnmat.for:2976 */
/*<       l=itab(adrs+3) >*/
    l = itab[*adrs + 3];
/* SOURCE brnmat.for:2978 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE brnmat.for:2979 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE brnmat.for:2980 */
/*<       doff=itab(adrs+21) >*/
    doff = itab[*adrs + 21];
/* SOURCE brnmat.for:2982 */
/*<       if(y.ge.ftab(l))then >*/
    if (y >= ftab[l]) {
/* SOURCE brnmat.for:2983 */
/*<   100 continue >*/
L100:
/* SOURCE brnmat.for:2984 */
/*<       if(y.gt.ftab(l+xoff))then >*/
	if (y > ftab[l + xoff]) {
/* SOURCE brnmat.for:2985 */
/*<       l=l+xoff >*/
	    l += xoff;
/* SOURCE brnmat.for:2986 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE brnmat.for:2987 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:2988 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:2989 */
/*<   110 continue >*/
L110:
/* SOURCE brnmat.for:2990 */
/*<       l=l-xoff >*/
	l -= xoff;
/* SOURCE brnmat.for:2991 */
/*<       if(y.lt.ftab(l))goto110 >*/
	if (y < ftab[l]) {
	    goto L110;
	}
/* SOURCE brnmat.for:2992 */
/*<       endif >*/
    }
/*     AT THIS POINT L DEFINES THE LOW ARGUMENT END OF THE */
/*     INTERVAL CONTAINING THE ARGUMENT, PERHAPS ADJUSTED */
/*     FOR ARGUMENT OUT OF RANGE. */
/*     RESET POINTER FOR LAST ADDRESS */
/* SOURCE brnmat.for:2999 */
/*<       itab(adrs+3)=l >*/
    itab[*adrs + 3] = l;
    feq_interpolate_section_interval(l,l+xoff,doff,*ya,a,t,dt,k,dk,b,db);
    return 0;
/* SOURCE brnmat.for:3062 */
/*<       end >*/
} /* xxlkt20_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE brnmat.for:3066 */
/*<        >*/
/* Subroutine */ int setinx_(doublereal *dt, integer *nbr, integer *nbra, 
	real *wt, integer *feq_storage_brpt, integer *ieq, real *errp, real *errq, 
	integer *berrp, integer *nerrp, integer *berrq, integer *nerrq)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_r_d_1;

    /* Builtin functions */
    double r_sign(real *, real *), sqrt(doublereal);

    /* Local variables */
    doublereal b, feq_gen_h_d_;
    integer l;
    doublereal p, c1, c2, c3, c4, b0, k0, s1, s2, s3, t0, y0, cf, dh, fl;
    integer fn;
    doublereal fr;
    integer ln;
    real kp;
    doublereal dv, dx, dy, dz, yc, qp, zi, tp;
    integer it;
    real ym, dv2, kac, kdc;
    doublereal wx, db0, db1, dk0, dk1, kh1, dx2, gde, ald, amd, bld, ard, brd, dmf, kld, kmd;
    integer nnd;
    real alu, blu, aru, bru, klu, kru, tlu, tru, ylu, yru;
    doublereal krd, amu, dxh, qld, err, qrd, kmu, res, tld, tpa, qlu, tpb, tpc, tpd, qru, trd, vld, vlu, vrd, vru, wtc, yld, yrd, zit, ziy, dyi, flp, frp, dlp, drp;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab, jcol, adrs, ninc;
    real dblu, dbru, dklu, khlm, dkru, dtlu, dtru;
    doublereal dxdt;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    doublereal ksum, pgfu, qmax, sfmt, sfmu;
    integer feq_gen_type_d_, xoff;
    doublereal beta1;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real dkhlm;
    doublereal dxhdt, pfqlu, pfqru, pfylu, pfyru, sgndv2;
    integer elmadr, ubnbas;
    // Original SETINX keeps these sums in 53-bit registers across inline SIGN.
    doublereal newsum, oldsum;
    doublereal dqpylu, dqpyru, dyndif, oldflw, oldimp, oldvol, oldwnd;
    extern /* Subroutine */ int xxlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Create the portion of the matrix corresponding to the */
/*     given branch number, NBR. IEQ gives the last equation created */
/*     in the matrix.  Used only for branches which have 2 unknowns */
/*     per node. */
/* SOURCE brnmat.for:3077 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE brnmat.for:3079 */
/*<       integerberrp,berrq,ieq,nbr,nbra,nerrp,nerrq >*/
/* SOURCE brnmat.for:3080 */
/*<       integerbrpt(8,nbra) >*/
/* SOURCE brnmat.for:3081 */
/*<       realerrp,errq,wt >*/
/* SOURCE brnmat.for:3082 */
/*<       real*8dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     NBR    - number of the branch being processed */
/*     NBRA   - number of branches in the model */
/*     WT     - weight factor for approximating time integrals */
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
/*     IEQ    - equation number */
/*     ERRP   - current maximum relative change in surcharge storage */
/*     ERRQ   - maximum value of the ratio of lateral inflow to the */
/*               average flow in the element */
/*     BERRP  - records the branch number(internal) that has the */
/*               greatest absolute value of the change in surcharge */
/*               storage relative to the storage in the storm sewer */
/*     NERRP  - node at which maximum correction to surcharge storage */
/*               occurs */
/*     BERRQ  - records the branch number(internal) that has the */
/*               greatest value of the ratio of lateral inflow */
/*               to average flow in an element */
/*     NERRQ  - node at which maximum relative lateral inflow occurs */
/* INCLUDE brnmat.for:3113 */
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
/* INCLUDE brnmat.for:3114 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE brnmat.for:3115 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:3116 */
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
/* INCLUDE brnmat.for:3117 */
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
/* INCLUDE brnmat.for:3118 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:3119 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/* INCLUDE brnmat.for:3120 */
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
/* INCLUDE brnmat.for:3121 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE brnmat.for:3122 */
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
/* SOURCE brnmat.for:3125 */
/*<       integeradrs,elmadr,fn,jcol,ln,ninc,nnd,ntab,ubnbas >*/
/* SOURCE brnmat.for:3126 */
/*<        >*/
/*     + + + LOCAL VARIABLES for inline table lookup */
/* SOURCE brnmat.for:3137 */
/*<       integerit,l,type,xoff,doff >*/
/* SOURCE brnmat.for:3138 */
/*<       realb0,dyi,h,k0,t0,y0,beta1,kh1,db0,db1,dk0,dk1 >*/
/* SOURCE brnmat.for:3140 */
/*<       realflp,frp,fl,fr,dlp,drp,dmf,p >*/
/*     + + + INTRINSICS + + + */
/* SOURCE brnmat.for:3143 */
/*<       intrinsicabs,sign,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE brnmat.for:3146 */
/*<       externallktab,xxlkt20 >*/
/* *********************************************************************** */
/* SOURCE brnmat.for:3148 */
/*<       wtc=1.0-wt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
    wtc = static_cast<double>((float)1.) - *wt;
/*     SET THE DIRECTION OF PROCESSING FOR THIS BRANCH.  THE SIGN OF THE */
/*     VARIABLE NUMBER FOR THE FIRST VARIABLE ON THE BRANCH SETS THE */
/*     DIRECTION */
/* SOURCE brnmat.for:3154 */
/*<       jcol=brpt(7,nbr) >*/
    jcol = brpt[(*nbr << 3) + 7];
/* SOURCE brnmat.for:3155 */
/*<       if(jcol.gt.0)then >*/
    if (jcol > 0) {
/* SOURCE brnmat.for:3156 */
/*<       fn=brpt(3,nbr) >*/
	fn = brpt[(*nbr << 3) + 3];
/* SOURCE brnmat.for:3157 */
/*<       ln=brpt(4,nbr) >*/
	ln = brpt[(*nbr << 3) + 4];
/* SOURCE brnmat.for:3158 */
/*<       ninc=1 >*/
	ninc = 1;
/*       SET THE USER BRANCH NODE BASE FOR REPORTING NERRQ AND NERRP */
/* SOURCE brnmat.for:3160 */
/*<       ubnbas=brpt(1,nbr)+1 >*/
	ubnbas = brpt[(*nbr << 3) + 1] + 1;
/* SOURCE brnmat.for:3161 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:3162 */
/*<       fn=brpt(4,nbr) >*/
	fn = brpt[(*nbr << 3) + 4];
/* SOURCE brnmat.for:3163 */
/*<       ln=brpt(3,nbr) >*/
	ln = brpt[(*nbr << 3) + 3];
/* SOURCE brnmat.for:3164 */
/*<       ninc=-1 >*/
	ninc = -1;
/* SOURCE brnmat.for:3165 */
/*<       jcol=-jcol >*/
	jcol = -jcol;
/* SOURCE brnmat.for:3166 */
/*<       ubnbas=brpt(2,nbr) >*/
	ubnbas = brpt[(*nbr << 3) + 2];
/* SOURCE brnmat.for:3167 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:3169 */
/*<       zi=zivec(nbr) >*/
    zi = bnothr_1.zivec[*nbr - 1];
/* SOURCE brnmat.for:3170 */
/*<       zit=zi >*/
    zit = zi;
/* SOURCE brnmat.for:3171 */
/*<       ziy=zilim(nbr) >*/
    ziy = bnothr_1.zilim[*nbr - 1];
/* SOURCE brnmat.for:3172 */
/*<       if(stflag.eq.0)then >*/
    if (bnelem_1.stflag == 0) {
/* SOURCE brnmat.for:3173 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:3174 */
/*<       tld=t1(fn) >*/
	    tld = bnelem_1.t1[fn - 1];
/* SOURCE brnmat.for:3175 */
/*<       ald=a1(fn) >*/
	    ald = bnelem_1.a1[fn - 1];
/* SOURCE brnmat.for:3176 */
/*<       yld=y1(fn) >*/
	    yld = bnelem_1.y1[fn - 1];
/* SOURCE brnmat.for:3177 */
/*<       bld=b1(fn) >*/
	    bld = bnelem_1.b1[fn - 1];
/* SOURCE brnmat.for:3178 */
/*<       qld=q1(fn) >*/
	    qld = bnelem_1.q1[fn - 1];
/* SOURCE brnmat.for:3179 */
/*<       kld=k1(fn) >*/
	    kld = bnelem_1.k1[fn - 1];
/* SOURCE brnmat.for:3180 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:3181 */
/*<       trd=t1(fn) >*/
	    trd = bnelem_1.t1[fn - 1];
/* SOURCE brnmat.for:3182 */
/*<       ard=a1(fn) >*/
	    ard = bnelem_1.a1[fn - 1];
/* SOURCE brnmat.for:3183 */
/*<       yrd=y1(fn) >*/
	    yrd = bnelem_1.y1[fn - 1];
/* SOURCE brnmat.for:3184 */
/*<       brd=b1(fn) >*/
	    brd = bnelem_1.b1[fn - 1];
/* SOURCE brnmat.for:3185 */
/*<       qrd=q1(fn) >*/
	    qrd = bnelem_1.q1[fn - 1];
/* SOURCE brnmat.for:3186 */
/*<       krd=k1(fn) >*/
	    krd = bnelem_1.k1[fn - 1];
/* SOURCE brnmat.for:3187 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3188 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:3190 */
/*<       if(ninc.gt.0)then >*/
    if (ninc > 0) {
/* SOURCE brnmat.for:3191 */
/*<       qlu=q2(fn) >*/
	qlu = bnelem_1.q2[fn - 1];
/* SOURCE brnmat.for:3192 */
/*<       ylu=y2(fn) >*/
	ylu = bnelem_1.y2[fn - 1];
/* SOURCE brnmat.for:3193 */
/*<       callxxlkt20(nsec(fn),ylu,alu,tlu,dtlu,klu,dklu,blu,dblu) >*/
	xxlkt20_(&bnothr_1.nsec[fn - 1], &ylu, &alu, &tlu, &dtlu, &klu, &dklu,
		 &blu, &dblu);
/* SOURCE brnmat.for:3197 */
/*<       t2(fn)=tlu >*/
	bnelem_1.t2[fn - 1] = tlu;
/* SOURCE brnmat.for:3198 */
/*<       a2(fn)=alu >*/
	bnelem_1.a2[fn - 1] = alu;
/* SOURCE brnmat.for:3199 */
/*<       b2(fn)=blu >*/
	bnelem_1.b2[fn - 1] = blu;
/* SOURCE brnmat.for:3200 */
/*<       k2(fn)=klu >*/
	bnelem_1.k2[fn - 1] = klu;
/* SOURCE brnmat.for:3201 */
/*<       fn=fn+1 >*/
	++fn;
/* SOURCE brnmat.for:3202 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:3203 */
/*<       qru=q2(fn) >*/
	qru = bnelem_1.q2[fn - 1];
/* SOURCE brnmat.for:3204 */
/*<       yru=y2(fn) >*/
	yru = bnelem_1.y2[fn - 1];
/* SOURCE brnmat.for:3205 */
/*<       callxxlkt20(nsec(fn),yru,aru,tru,dtru,kru,dkru,bru,dbru) >*/
	xxlkt20_(&bnothr_1.nsec[fn - 1], &yru, &aru, &tru, &dtru, &kru, &dkru,
		 &bru, &dbru);
/* SOURCE brnmat.for:3209 */
/*<       t2(fn)=tru >*/
	bnelem_1.t2[fn - 1] = tru;
/* SOURCE brnmat.for:3210 */
/*<       a2(fn)=aru >*/
	bnelem_1.a2[fn - 1] = aru;
/* SOURCE brnmat.for:3211 */
/*<       b2(fn)=bru >*/
	bnelem_1.b2[fn - 1] = bru;
/* SOURCE brnmat.for:3212 */
/*<       k2(fn)=kru >*/
	bnelem_1.k2[fn - 1] = kru;
/* SOURCE brnmat.for:3213 */
/*<       fn=fn-1 >*/
	--fn;
/* SOURCE brnmat.for:3214 */
/*<       endif >*/
    }
/*      WRITE(STD6,*) ' Dump of residual and derivatives' */
/* SOURCE brnmat.for:3217 */
/*<       do100nnd=fn,ln,ninc >*/
    feq_gen_i_d_1 = ln;
    feq_gen_i_d_2 = ninc;
    for (nnd = fn; feq_gen_i_d_2 < 0 ? nnd >= feq_gen_i_d_1 : nnd <= feq_gen_i_d_1; nnd += feq_gen_i_d_2) {
/* SOURCE brnmat.for:3218 */
/*<       if(ninc.eq.1)then >*/
	if (ninc == 1) {
/* SOURCE brnmat.for:3219 */
/*<       elmadr=nnd >*/
	    elmadr = nnd;
/* SOURCE brnmat.for:3220 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:3221 */
/*<       elmadr=nnd+1 >*/
	    elmadr = nnd + 1;
/* SOURCE brnmat.for:3222 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3223 */
/*<       dx=dxvec(elmadr) >*/
	dx = bnelem_1.dxvec[elmadr - 1];
/* SOURCE brnmat.for:3224 */
/*<       dxh=0.5*dx >*/
	dxh = static_cast<double>(dx) * (float).5;
/* SOURCE brnmat.for:3225 */
/*<       dx2=dx+dx >*/
	dx2 = static_cast<double>(dx) + dx;
/* SOURCE brnmat.for:3226 */
/*<       dxdt=dx/dt >*/
	// Original 0x40c5fd forms a double reciprocal; 0x40c680 stores DXDT as binary32.
    dxdt = static_cast<float>(dx * (1.0 / *dt));
/* SOURCE brnmat.for:3227 */
/*<       dxhdt=0.5*dxdt >*/
	dxhdt = static_cast<double>(dxdt) * (float).5;
/* SOURCE brnmat.for:3228 */
/*<       dz=dzvec(elmadr) >*/
	dz = bnelem_1.dzvec[elmadr - 1];
/* SOURCE brnmat.for:3229 */
/*<       kac=ka(elmadr) >*/
	kac = bnelem_1.ka[elmadr - 1];
/* SOURCE brnmat.for:3230 */
/*<       kdc=kd(elmadr) >*/
	kdc = bnelem_1.kd[elmadr - 1];
/* SOURCE brnmat.for:3231 */
/*<       adrs=hltab(elmadr) >*/
	adrs = bnothr_1.hltab[elmadr - 1];
/* SOURCE brnmat.for:3232 */
/*<       if(stflag.eq.0)then >*/
	if (bnelem_1.stflag == 0) {
/* SOURCE brnmat.for:3233 */
/*<       wx=wxvec(elmadr) >*/
	    wx = bnelem_1.wxvec[elmadr - 1];
/* SOURCE brnmat.for:3234 */
/*<       if(ninc.gt.0)then >*/
	    if (ninc > 0) {
/* SOURCE brnmat.for:3235 */
/*<       trd=t1(nnd) >*/
		trd = bnelem_1.t1[nnd - 1];
/* SOURCE brnmat.for:3236 */
/*<       ard=a1(nnd) >*/
		ard = bnelem_1.a1[nnd - 1];
/* SOURCE brnmat.for:3237 */
/*<       yrd=y1(nnd) >*/
		yrd = bnelem_1.y1[nnd - 1];
/* SOURCE brnmat.for:3238 */
/*<       brd=b1(nnd) >*/
		brd = bnelem_1.b1[nnd - 1];
/* SOURCE brnmat.for:3239 */
/*<       qrd=q1(nnd) >*/
		qrd = bnelem_1.q1[nnd - 1];
/* SOURCE brnmat.for:3240 */
/*<       krd=k1(nnd) >*/
		krd = bnelem_1.k1[nnd - 1];
/* SOURCE brnmat.for:3241 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3242 */
/*<       tld=t1(nnd) >*/
		tld = bnelem_1.t1[nnd - 1];
/* SOURCE brnmat.for:3243 */
/*<       ald=a1(nnd) >*/
		ald = bnelem_1.a1[nnd - 1];
/* SOURCE brnmat.for:3244 */
/*<       yld=y1(nnd) >*/
		yld = bnelem_1.y1[nnd - 1];
/* SOURCE brnmat.for:3245 */
/*<       bld=b1(nnd) >*/
		bld = bnelem_1.b1[nnd - 1];
/* SOURCE brnmat.for:3246 */
/*<       qld=q1(nnd) >*/
		qld = bnelem_1.q1[nnd - 1];
/* SOURCE brnmat.for:3247 */
/*<       kld=k1(nnd) >*/
		kld = bnelem_1.k1[nnd - 1];
/* SOURCE brnmat.for:3248 */
/*<       endif >*/
	    }
/*           SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL. */
/* SOURCE brnmat.for:3251 */
/*<       if(yld.lt.ziy.or.yrd.lt.ziy)then >*/
	    if (yld < ziy || yrd < ziy) {
/* SOURCE brnmat.for:3252 */
/*<       zi=0.0 >*/
		zi = (float)0.;
/* SOURCE brnmat.for:3253 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3254 */
/*<       zi=zit >*/
		zi = zit;
/* SOURCE brnmat.for:3255 */
/*<       endif >*/
	    }
/*           COMPUTE VALUES AT THE START OF THE TIME STEP AND STORE */
/* SOURCE brnmat.for:3259 */
/*<       oldsum=qld+qrd >*/
	    oldsum = static_cast<double>(qld) + qrd;
/* SOURCE brnmat.for:3261 */
/*<       sumvec(elmadr)=oldsum >*/
	    bnelem_1.sumvec[elmadr - 1] = oldsum;
/* SOURCE brnmat.for:3262 */
/*<       vld=qld/ald >*/
	    vld = static_cast<double>(qld) / ald;
/* SOURCE brnmat.for:3263 */
/*<       vrd=qrd/ard >*/
	    vrd = static_cast<double>(qrd) / ard;
/* SOURCE brnmat.for:3265 */
/*<       gde=0.0 >*/
	    gde = (float)0.;
/* SOURCE brnmat.for:3266 */
/*<       if(kdc.gt.0.0.or.kac.gt.0.0)then >*/
	    if (kdc > (float)0. || kac > (float)0.) {
/*             PROCESS EXPANSION AND CONTRACTION LOSSES */
/* SOURCE brnmat.for:3268 */
/*<       dv=vld-vrd >*/
		dv = static_cast<double>(vld) - vrd;
/* SOURCE brnmat.for:3269 */
/*<       if(dv.gt.0.0)then >*/
		if (dv > (float)0.) {
/*               FLOW IS UNDERGOING NEGATIVE ACCELERATION-TAKEN */
/*               TO INDICATE EXPANSION */
/* SOURCE brnmat.for:3272 */
/*<       kp=kdc >*/
		    kp = kdc;
/* SOURCE brnmat.for:3273 */
/*<       else >*/
		} else {
/*               FLOW IS UNDERGOING POSITIVE ACCELERATION- TAKEN TO */
/*               INDICATE CONTRACTION */
/* SOURCE brnmat.for:3276 */
/*<       kp=kac >*/
		    kp = kac;
/* SOURCE brnmat.for:3277 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:3278 */
/*<       gde=0.5*sign(kp,oldsum)*abs(dv*(vld+vrd)) >*/
		gde = (oldsum >= 0.0 ? std::fabs(static_cast<double>(kp)) : -std::fabs(static_cast<double>(kp))) * (float).5 * (feq_gen_r_d_1 = static_cast<double>(dv) * (static_cast<double>(vld) + 
			vrd), dabs(feq_gen_r_d_1));
/* SOURCE brnmat.for:3279 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3281 */
/*<       if(adrs.gt.0)then >*/
	    if (adrs > 0) {
/*             POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT */
/* SOURCE brnmat.for:3283 */
/*<       ym=0.5*(yld+yrd) >*/
		ym = static_cast<double>((static_cast<double>(yld) + yrd)) * (float).5;
/* SOURCE brnmat.for:3284 */
/*<       calllktab(adrs,ym,0,khlm,ntab,dkhlm) >*/
		lktab_(&adrs, &ym, &feq_gen_c_d_0, &khlm, &ntab, &dkhlm);
/* SOURCE brnmat.for:3287 */
/*<       if(oldsum.lt.0.0)then >*/
		if (oldsum < (float)0.) {
/* SOURCE brnmat.for:3288 */
/*<       khlm=-khlm >*/
		    khlm = -khlm;
/* SOURCE brnmat.for:3289 */
/*<       dkhlm=-dkhlm >*/
		    dkhlm = -dkhlm;
/* SOURCE brnmat.for:3290 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:3292 */
/*<       gde=gde+0.5*khlm*(oldsum/(ald+ard))**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(oldsum) / (static_cast<double>(ald) + ard);
		gde += static_cast<double>(static_cast<double>(static_cast<double>(khlm) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE brnmat.for:3293 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3295 */
/*<       dy=yrd-yld >*/
	    dy = static_cast<double>(yrd) - yld;
/* SOURCE brnmat.for:3296 */
/*<       kmd=kld+wx*(krd-kld) >*/
	    kmd = static_cast<double>(kld) + static_cast<double>(wx) * (static_cast<double>(krd) - kld);
/* SOURCE brnmat.for:3297 */
/*<       amd=ald+0.5*(ard-ald) >*/
	    amd = static_cast<double>(ald) + static_cast<double>((static_cast<double>(ard) - ald)) * (float).5;
/* SOURCE brnmat.for:3298 */
/*<        >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = kmd;
	    oldimp = (gravcm_1.grav * (dz + static_cast<double>(oldsum) * (float).25 * dabs(oldsum)
		     * dx / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + dy) + gde) * amd + static_cast<double>(zi) * (static_cast<double>(static_cast<double>(static_cast<double>(brd) * 
		    vrd) * qrd) - static_cast<double>(static_cast<double>(bld) * vld) * qld);
/* SOURCE brnmat.for:3302 */
/*<       impvec(elmadr)=oldimp >*/
	    bnelem_1.impvec[elmadr - 1] = oldimp;
/* SOURCE brnmat.for:3303 */
/*<       if(wsvec(elmadr).ne.0.0)then >*/
	    if (bnothr_1.wsvec[elmadr - 1] != (float)0.) {
/*             COMPUTE THE WIND STRESS TERM.  WSVEC IS USED TO HOLD */
/*             VALUE BECAUSE THE WIND STRESS IS RECOMPUTED FOR EACH */
/*             TIME STEP AT THE START OF THE TIME STEP.  WE USE THE */
/*             EULER APPROXIMATION FOR THE INTEGRAL TO SIMPLIFY THE */
/*             EQUATIONS. */
/* SOURCE brnmat.for:3310 */
/*<       oldwnd=dxh*(tld+trd)*wsvec(elmadr) >*/
		oldwnd = static_cast<double>(static_cast<double>(dxh) * (static_cast<double>(tld) + trd)) * bnothr_1.wsvec[elmadr - 1];
/* SOURCE brnmat.for:3311 */
/*<       wsvec(elmadr)=oldwnd >*/
		bnothr_1.wsvec[elmadr - 1] = oldwnd;
/* SOURCE brnmat.for:3312 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3313 */
/*<       oldwnd=0.0 >*/
		oldwnd = (float)0.;
/* SOURCE brnmat.for:3314 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3316 */
/*<       oldvol=amd >*/
	    oldvol = amd;
/* SOURCE brnmat.for:3317 */
/*<       volvec(elmadr)=oldvol >*/
	    bnelem_1.volvec[elmadr - 1] = oldvol;
/* SOURCE brnmat.for:3318 */
/*<       oldflw=qrd-qld >*/
	    oldflw = static_cast<double>(qrd) - qld;
/* SOURCE brnmat.for:3319 */
/*<       flwvec(elmadr)=oldflw >*/
	    bnelem_1.flwvec[elmadr - 1] = oldflw;
/* SOURCE brnmat.for:3321 */
/*<       if(ninc.gt.0)then >*/
	    if (ninc > 0) {
/* SOURCE brnmat.for:3322 */
/*<       yld=yrd >*/
		yld = yrd;
/* SOURCE brnmat.for:3323 */
/*<       tld=trd >*/
		tld = trd;
/* SOURCE brnmat.for:3324 */
/*<       ald=ard >*/
		ald = ard;
/* SOURCE brnmat.for:3325 */
/*<       bld=brd >*/
		bld = brd;
/* SOURCE brnmat.for:3326 */
/*<       kld=krd >*/
		kld = krd;
/* SOURCE brnmat.for:3327 */
/*<       qld=qrd >*/
		qld = qrd;
/* SOURCE brnmat.for:3328 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3329 */
/*<       yrd=yld >*/
		yrd = yld;
/* SOURCE brnmat.for:3330 */
/*<       trd=tld >*/
		trd = tld;
/* SOURCE brnmat.for:3331 */
/*<       ard=ald >*/
		ard = ald;
/* SOURCE brnmat.for:3332 */
/*<       brd=bld >*/
		brd = bld;
/* SOURCE brnmat.for:3333 */
/*<       krd=kld >*/
		krd = kld;
/* SOURCE brnmat.for:3334 */
/*<       qrd=qld >*/
		qrd = qld;
/* SOURCE brnmat.for:3335 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3336 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:3337 */
/*<       oldsum=sumvec(elmadr) >*/
	    oldsum = bnelem_1.sumvec[elmadr - 1];
/* SOURCE brnmat.for:3338 */
/*<       oldimp=impvec(elmadr) >*/
	    oldimp = bnelem_1.impvec[elmadr - 1];
/* SOURCE brnmat.for:3339 */
/*<       oldvol=volvec(elmadr) >*/
	    oldvol = bnelem_1.volvec[elmadr - 1];
/* SOURCE brnmat.for:3340 */
/*<       oldflw=flwvec(elmadr) >*/
	    oldflw = bnelem_1.flwvec[elmadr - 1];
/* SOURCE brnmat.for:3341 */
/*<       oldwnd=wsvec(elmadr) >*/
	    oldwnd = bnothr_1.wsvec[elmadr - 1];
/* SOURCE brnmat.for:3342 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3345 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:3346 */
/*<       qru=q2(nnd) >*/
	    qru = bnelem_1.q2[nnd - 1];
/* SOURCE brnmat.for:3347 */
/*<       yru=y2(nnd) >*/
	    yru = bnelem_1.y2[nnd - 1];
/*            CALL XXLKT20 */
/*     I                 (NSEC(NND), */
/*     M                  YRU, */
/*     O                  ARU, TRU, DTRU, KRU, DKRU, BRU, DBRU) */
/*     Inline lookup code */
/* SOURCE brnmat.for:3355 */
/*<       it=nsec(nnd) >*/
	    it = bnothr_1.nsec[nnd - 1];
/* SOURCE brnmat.for:3356 */
/*<       l=itab(it+3) >*/
	    l = itab[it + 3];
/* SOURCE brnmat.for:3357 */
/*<       doff=itab(it+21) >*/
	    doff = itab[it + 21];
/* SOURCE brnmat.for:3359 */
/*<       type=itab(it+2) >*/
	    feq_gen_type_d_ = itab[it + 2];
/* SOURCE brnmat.for:3360 */
/*<       xoff=offvec(type) >*/
	    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE brnmat.for:3362 */
/*<       if(yru.ge.ftab(l))then >*/
	    if (yru >= ftab[l]) {
/* SOURCE brnmat.for:3363 */
/*<  8100 continue >*/
L8100:
/* SOURCE brnmat.for:3364 */
/*<       if(yru.gt.ftab(l+xoff))then >*/
		if (yru > ftab[l + xoff]) {
/* SOURCE brnmat.for:3365 */
/*<       l=l+xoff >*/
		    l += xoff;
/* SOURCE brnmat.for:3366 */
/*<       goto8100 >*/
		    goto L8100;
/* SOURCE brnmat.for:3367 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:3368 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3369 */
/*<  8110 continue >*/
L8110:
/* SOURCE brnmat.for:3370 */
/*<       l=l-xoff >*/
		l -= xoff;
/* SOURCE brnmat.for:3371 */
/*<       if(yru.lt.ftab(l))goto8110 >*/
		if (yru < ftab[l]) {
		    goto L8110;
		}
/* SOURCE brnmat.for:3372 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3373 */
/*<       itab(it+3)=l >*/
	    itab[it + 3] = l;
/* SOURCE brnmat.for:3375 */
/*<       y0=ftab(l) >*/
	    y0 = ftab[l];
/* SOURCE brnmat.for:3376 */
/*<       t0=ftab(l+1) >*/
	    t0 = ftab[l + 1];
/* SOURCE brnmat.for:3377 */
/*<       k0=ftab(l+3) >*/
	    k0 = ftab[l + 3];
/* SOURCE brnmat.for:3378 */
/*<       b0=ftab(l+4) >*/
	    b0 = ftab[l + 4];
/* SOURCE brnmat.for:3380 */
/*<       it=l+xoff >*/
	    it = l + xoff;
/* SOURCE brnmat.for:3381 */
/*<       kh1=ftab(it+3) >*/
	    kh1 = ftab[it + 3];
/* SOURCE brnmat.for:3382 */
/*<       beta1=ftab(it+4) >*/
	    beta1 = ftab[it + 4];
/* SOURCE brnmat.for:3384 */
/*<       dy=ftab(it)-y0 >*/
	    dy = static_cast<double>(ftab[it]) - y0;
/* SOURCE brnmat.for:3385 */
/*<       h=yru-y0 >*/
	    feq_gen_h_d_ = static_cast<double>(yru) - y0;
/* SOURCE brnmat.for:3386 */
/*<       dyi=1.0/dy >*/
	    dyi = static_cast<double>((float)1.) / dy;
/* SOURCE brnmat.for:3387 */
/*<       dtru=(ftab(it+1)-t0)*dyi >*/
	    dtru = static_cast<double>((static_cast<double>(ftab[it + 1]) - t0)) * dyi;
/* SOURCE brnmat.for:3388 */
/*<       tru=t0+h*dtru >*/
	    tru = static_cast<double>(t0) + static_cast<double>(feq_gen_h_d_) * dtru;
/* SOURCE brnmat.for:3389 */
/*<       aru=ftab(l+2)+0.5*h*(tru+t0) >*/
	    aru = static_cast<double>(ftab[l + 2]) + static_cast<double>(static_cast<double>(feq_gen_h_d_) * (float).5) * (static_cast<double>(tru) + t0);
/* SOURCE brnmat.for:3390 */
/*<       if(doff.eq.0)then >*/
	    if (doff == 0) {
/* SOURCE brnmat.for:3391 */
/*<       dbru=(beta1-b0)*dyi >*/
		dbru = static_cast<double>((static_cast<double>(beta1) - b0)) * dyi;
/* SOURCE brnmat.for:3392 */
/*<       bru=b0+h*dbru >*/
		bru = static_cast<double>(b0) + static_cast<double>(feq_gen_h_d_) * dbru;
/* SOURCE brnmat.for:3393 */
/*<       dkru=(kh1-k0)*dyi >*/
		dkru = static_cast<double>((static_cast<double>(kh1) - k0)) * dyi;
/* SOURCE brnmat.for:3394 */
/*<       kru=k0+h*dkru >*/
		kru = static_cast<double>(k0) + static_cast<double>(feq_gen_h_d_) * dkru;
/* SOURCE brnmat.for:3395 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3396 */
/*<       p=h*dyi >*/
		p = static_cast<double>(feq_gen_h_d_) * dyi;
/*       compute factors on left and right derivative. */
/* SOURCE brnmat.for:3398 */
/*<       flp=(1.0-p)*p*dy >*/
		flp = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * p) * dy;
/* SOURCE brnmat.for:3399 */
/*<       frp=-flp*p >*/
		frp = static_cast<double>(-flp) * p;
/* SOURCE brnmat.for:3400 */
/*<       flp=flp*(1.0-p) >*/
		flp *= static_cast<double>(static_cast<double>((float)1.) - p);
/*       compute factors on left and right function value */
/* SOURCE brnmat.for:3402 */
/*<       fl=2.*p+1.0 >*/
		fl = static_cast<double>(static_cast<double>(p) * (float)2.) + (float)1.;
/* SOURCE brnmat.for:3403 */
/*<       fr=(4.0-fl)*p*p >*/
		fr = static_cast<double>(static_cast<double>((static_cast<double>((float)4.) - fl)) * p) * p;
/* SOURCE brnmat.for:3404 */
/*<       fl=fl*(1.0-p)**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>((float)1.) - p;
		fl *= static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*       compute the factors based on relative interval for computing derivatives. */
/* SOURCE brnmat.for:3406 */
/*<       dlp=1.-3.*p >*/
		dlp = static_cast<double>((float)1.) - static_cast<double>(p) * (float)3.;
/* SOURCE brnmat.for:3407 */
/*<       drp=-(1.+dlp)*p >*/
		drp = static_cast<double>(-(static_cast<double>(dlp) + (float)1.)) * p;
/* SOURCE brnmat.for:3408 */
/*<       dlp=dlp*(1.0-p) >*/
		dlp *= static_cast<double>(static_cast<double>((float)1.) - p);
/* SOURCE brnmat.for:3409 */
/*<       dmf=6.*(1.0-p)*p*dyi >*/
		dmf = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * (float)6.) * p) * dyi;
/* SOURCE brnmat.for:3411 */
/*<       l=l+doff >*/
		l += doff;
/* SOURCE brnmat.for:3412 */
/*<       it=it+doff >*/
		it += doff;
/* SOURCE brnmat.for:3413 */
/*<       dk0=ftab(l) >*/
		dk0 = ftab[l];
/* SOURCE brnmat.for:3414 */
/*<       dk1=ftab(it) >*/
		dk1 = ftab[it];
/* SOURCE brnmat.for:3416 */
/*<       db0=ftab(l+1) >*/
		db0 = ftab[l + 1];
/* SOURCE brnmat.for:3417 */
/*<       db1=ftab(it+1) >*/
		db1 = ftab[it + 1];
/* SOURCE brnmat.for:3419 */
/*<       bru=flp*db0+frp*db1+fl*b0+fr*beta1 >*/
		bru = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * db0) + static_cast<double>(frp) * db1) + static_cast<double>(fl) * b0) + static_cast<double>(fr) * beta1;
/* SOURCE brnmat.for:3420 */
/*<       dbru=dlp*db0+drp*db1+dmf*(beta1-b0) >*/
		dbru = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * db0) + static_cast<double>(drp) * db1) + static_cast<double>(dmf) * (static_cast<double>(beta1) - b0);
/* SOURCE brnmat.for:3422 */
/*<       kru=flp*dk0+frp*dk1+fl*k0+fr*kh1 >*/
		kru = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dk0) + static_cast<double>(frp) * dk1) + static_cast<double>(fl) * k0) + static_cast<double>(fr) * kh1;
/* SOURCE brnmat.for:3423 */
/*<       dkru=dlp*dk0+drp*dk1+dmf*(kh1-k0) >*/
		dkru = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dk0) + static_cast<double>(drp) * dk1) + static_cast<double>(dmf) * (static_cast<double>(kh1) - k0);
/* SOURCE brnmat.for:3424 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3426 */
/*<       dkru=(kru+kru)*dkru >*/
	    dkru = static_cast<double>((static_cast<double>(kru) + kru)) * dkru;
/* SOURCE brnmat.for:3427 */
/*<       kru=kru*kru >*/
	    kru *= kru;
/*     End inline lookup code. */
/* SOURCE brnmat.for:3431 */
/*<       t2(nnd)=tru >*/
	    bnelem_1.t2[nnd - 1] = tru;
/* SOURCE brnmat.for:3432 */
/*<       a2(nnd)=aru >*/
	    bnelem_1.a2[nnd - 1] = aru;
/* SOURCE brnmat.for:3433 */
/*<       b2(nnd)=bru >*/
	    bnelem_1.b2[nnd - 1] = bru;
/* SOURCE brnmat.for:3434 */
/*<       k2(nnd)=kru >*/
	    bnelem_1.k2[nnd - 1] = kru;
/* SOURCE brnmat.for:3435 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:3436 */
/*<       qlu=q2(nnd) >*/
	    qlu = bnelem_1.q2[nnd - 1];
/* SOURCE brnmat.for:3437 */
/*<       ylu=y2(nnd) >*/
	    ylu = bnelem_1.y2[nnd - 1];
/*            CALL XXLKT20 */
/*     I                 (NSEC(NND), */
/*     M                  YLU, */
/*     O                  ALU, TLU, DTLU, KLU, DKLU, BLU, DBLU) */
/*     Inline lookup code */
/* SOURCE brnmat.for:3445 */
/*<       it=nsec(nnd) >*/
	    it = bnothr_1.nsec[nnd - 1];
/* SOURCE brnmat.for:3446 */
/*<       l=itab(it+3) >*/
	    l = itab[it + 3];
/* SOURCE brnmat.for:3447 */
/*<       doff=itab(it+21) >*/
	    doff = itab[it + 21];
/* SOURCE brnmat.for:3449 */
/*<       type=itab(it+2) >*/
	    feq_gen_type_d_ = itab[it + 2];
/* SOURCE brnmat.for:3450 */
/*<       xoff=offvec(type) >*/
	    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE brnmat.for:3452 */
/*<       if(ylu.ge.ftab(l))then >*/
	    if (ylu >= ftab[l]) {
/* SOURCE brnmat.for:3453 */
/*<  9100 continue >*/
L9100:
/* SOURCE brnmat.for:3454 */
/*<       if(ylu.gt.ftab(l+xoff))then >*/
		if (ylu > ftab[l + xoff]) {
/* SOURCE brnmat.for:3455 */
/*<       l=l+xoff >*/
		    l += xoff;
/* SOURCE brnmat.for:3456 */
/*<       goto9100 >*/
		    goto L9100;
/* SOURCE brnmat.for:3457 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:3458 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3459 */
/*<  9110 continue >*/
L9110:
/* SOURCE brnmat.for:3460 */
/*<       l=l-xoff >*/
		l -= xoff;
/* SOURCE brnmat.for:3461 */
/*<       if(ylu.lt.ftab(l))goto9110 >*/
		if (ylu < ftab[l]) {
		    goto L9110;
		}
/* SOURCE brnmat.for:3462 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3463 */
/*<       itab(it+3)=l >*/
	    itab[it + 3] = l;
/* SOURCE brnmat.for:3465 */
/*<       y0=ftab(l) >*/
	    y0 = ftab[l];
/* SOURCE brnmat.for:3466 */
/*<       t0=ftab(l+1) >*/
	    t0 = ftab[l + 1];
/* SOURCE brnmat.for:3467 */
/*<       k0=ftab(l+3) >*/
	    k0 = ftab[l + 3];
/* SOURCE brnmat.for:3468 */
/*<       b0=ftab(l+4) >*/
	    b0 = ftab[l + 4];
/* SOURCE brnmat.for:3470 */
/*<       it=l+xoff >*/
	    it = l + xoff;
/* SOURCE brnmat.for:3471 */
/*<       beta1=ftab(it+4) >*/
	    beta1 = ftab[it + 4];
/* SOURCE brnmat.for:3472 */
/*<       kh1=ftab(it+3) >*/
	    kh1 = ftab[it + 3];
/* SOURCE brnmat.for:3473 */
/*<       dy=ftab(it)-y0 >*/
	    dy = static_cast<double>(ftab[it]) - y0;
/* SOURCE brnmat.for:3474 */
/*<       h=ylu-y0 >*/
	    feq_gen_h_d_ = static_cast<double>(ylu) - y0;
/* SOURCE brnmat.for:3475 */
/*<       dyi=1.0/dy >*/
	    dyi = static_cast<double>((float)1.) / dy;
/* SOURCE brnmat.for:3476 */
/*<       dtlu=(ftab(it+1)-t0)*dyi >*/
	    dtlu = static_cast<double>((static_cast<double>(ftab[it + 1]) - t0)) * dyi;
/* SOURCE brnmat.for:3477 */
/*<       tlu=t0+h*dtlu >*/
	    tlu = static_cast<double>(t0) + static_cast<double>(feq_gen_h_d_) * dtlu;
/* SOURCE brnmat.for:3478 */
/*<       alu=ftab(l+2)+0.5*h*(tlu+t0) >*/
	    alu = static_cast<double>(ftab[l + 2]) + static_cast<double>(static_cast<double>(feq_gen_h_d_) * (float).5) * (static_cast<double>(tlu) + t0);
/* SOURCE brnmat.for:3479 */
/*<       if(doff.eq.0)then >*/
	    if (doff == 0) {
/* SOURCE brnmat.for:3480 */
/*<       dblu=(beta1-b0)*dyi >*/
		dblu = static_cast<double>((static_cast<double>(beta1) - b0)) * dyi;
/* SOURCE brnmat.for:3481 */
/*<       blu=b0+h*dblu >*/
		blu = static_cast<double>(b0) + static_cast<double>(feq_gen_h_d_) * dblu;
/* SOURCE brnmat.for:3482 */
/*<       dklu=(kh1-k0)*dyi >*/
		dklu = static_cast<double>((static_cast<double>(kh1) - k0)) * dyi;
/* SOURCE brnmat.for:3483 */
/*<       klu=k0+h*dklu >*/
		klu = static_cast<double>(k0) + static_cast<double>(feq_gen_h_d_) * dklu;
/* SOURCE brnmat.for:3484 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3485 */
/*<       p=h*dyi >*/
		p = static_cast<double>(feq_gen_h_d_) * dyi;
/*       compute factors on left and right derivative. */
/* SOURCE brnmat.for:3487 */
/*<       flp=(1.0-p)*p*dy >*/
		flp = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * p) * dy;
/* SOURCE brnmat.for:3488 */
/*<       frp=-flp*p >*/
		frp = static_cast<double>(-flp) * p;
/* SOURCE brnmat.for:3489 */
/*<       flp=flp*(1.0-p) >*/
		flp *= static_cast<double>(static_cast<double>((float)1.) - p);
/*       compute factors on left and right function value */
/* SOURCE brnmat.for:3491 */
/*<       fl=2.*p+1.0 >*/
		fl = static_cast<double>(static_cast<double>(p) * (float)2.) + (float)1.;
/* SOURCE brnmat.for:3492 */
/*<       fr=(4.0-fl)*p*p >*/
		fr = static_cast<double>(static_cast<double>((static_cast<double>((float)4.) - fl)) * p) * p;
/* SOURCE brnmat.for:3493 */
/*<       fl=fl*(1.0-p)**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>((float)1.) - p;
		fl *= static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*       compute the factors based on relative interval for computing derivatives. */
/* SOURCE brnmat.for:3495 */
/*<       dlp=1.-3.*p >*/
		dlp = static_cast<double>((float)1.) - static_cast<double>(p) * (float)3.;
/* SOURCE brnmat.for:3496 */
/*<       drp=-(1.+dlp)*p >*/
		drp = static_cast<double>(-(static_cast<double>(dlp) + (float)1.)) * p;
/* SOURCE brnmat.for:3497 */
/*<       dlp=dlp*(1.0-p) >*/
		dlp *= static_cast<double>(static_cast<double>((float)1.) - p);
/* SOURCE brnmat.for:3498 */
/*<       dmf=6.*(1.0-p)*p*dyi >*/
		dmf = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - p)) * (float)6.) * p) * dyi;
/* SOURCE brnmat.for:3500 */
/*<       l=l+doff >*/
		l += doff;
/* SOURCE brnmat.for:3501 */
/*<       it=it+doff >*/
		it += doff;
/* SOURCE brnmat.for:3502 */
/*<       dk0=ftab(l) >*/
		dk0 = ftab[l];
/* SOURCE brnmat.for:3503 */
/*<       dk1=ftab(it) >*/
		dk1 = ftab[it];
/* SOURCE brnmat.for:3505 */
/*<       db0=ftab(l+1) >*/
		db0 = ftab[l + 1];
/* SOURCE brnmat.for:3506 */
/*<       db1=ftab(it+1) >*/
		db1 = ftab[it + 1];
/* SOURCE brnmat.for:3508 */
/*<       blu=flp*db0+frp*db1+fl*b0+fr*beta1 >*/
		blu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * db0) + static_cast<double>(frp) * db1) + static_cast<double>(fl) * b0) + static_cast<double>(fr) * beta1;
/* SOURCE brnmat.for:3509 */
/*<       dblu=dlp*db0+drp*db1+dmf*(beta1-b0) >*/
		dblu = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * db0) + static_cast<double>(drp) * db1) + static_cast<double>(dmf) * (static_cast<double>(beta1) - b0);
/* SOURCE brnmat.for:3511 */
/*<       klu=flp*dk0+frp*dk1+fl*k0+fr*kh1 >*/
		klu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(flp) * dk0) + static_cast<double>(frp) * dk1) + static_cast<double>(fl) * k0) + static_cast<double>(fr) * kh1;
/* SOURCE brnmat.for:3512 */
/*<       dklu=dlp*dk0+drp*dk1+dmf*(kh1-k0) >*/
		dklu = static_cast<double>(static_cast<double>(static_cast<double>(dlp) * dk0) + static_cast<double>(drp) * dk1) + static_cast<double>(dmf) * (static_cast<double>(kh1) - k0);
/* SOURCE brnmat.for:3513 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3515 */
/*<       dklu=(klu+klu)*dklu >*/
	    dklu = static_cast<double>((static_cast<double>(klu) + klu)) * dklu;
/* SOURCE brnmat.for:3516 */
/*<       klu=klu*klu >*/
	    klu *= klu;
/*     End inline lookup code. */
/* SOURCE brnmat.for:3520 */
/*<       t2(nnd)=tlu >*/
	    bnelem_1.t2[nnd - 1] = tlu;
/* SOURCE brnmat.for:3521 */
/*<       a2(nnd)=alu >*/
	    bnelem_1.a2[nnd - 1] = alu;
/* SOURCE brnmat.for:3522 */
/*<       b2(nnd)=blu >*/
	    bnelem_1.b2[nnd - 1] = blu;
/* SOURCE brnmat.for:3523 */
/*<       k2(nnd)=klu >*/
	    bnelem_1.k2[nnd - 1] = klu;
/* SOURCE brnmat.for:3524 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3525 */
/*<       newsum=qlu+qru >*/
	newsum = static_cast<double>(qlu) + qru;
/* SOURCE brnmat.for:3527 */
/*<       dy=yru-ylu >*/
	dy = static_cast<double>(yru) - ylu;
/*         SELECT NEW VALUE OF WX. */
/* SOURCE brnmat.for:3529 */
/*<       kmu=0.5*(klu+kru) >*/
	kmu = static_cast<double>((static_cast<double>(klu) + kru)) * (float).5;
/* SOURCE brnmat.for:3530 */
/*<       if(newsum.ge.0.0)then >*/
	if (newsum >= (float)0.) {
/*           FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT. */
/*            WRITE(STD6,*) ' CRITERION=',DKRU*(-DY - DZ) - KMU */
/*            WRITE(STD6,*) ' DKRU=',DKRU,'DY+DZ=',DY+DZ,' KMU=',KMU */
/* SOURCE brnmat.for:3534 */
/*<       if(dkru*(-dy-dz)-kmu.ge.0.0)then >*/
	    if (static_cast<double>(static_cast<double>(dkru) * (static_cast<double>(-dy) - dz)) - kmu >= (float)0.) {
/*             SHIFT TO UPSTREAM CONVEYANCE. */
/* SOURCE brnmat.for:3536 */
/*<       wx=0.4*klu/(dkru*(-dy-dz)-0.5*(kru-klu)) >*/
		wx = static_cast<double>(static_cast<double>(klu) * (float).4) / (static_cast<double>(static_cast<double>(dkru) * (static_cast<double>(-dy) - dz)) - static_cast<double>((static_cast<double>(kru) - klu)) * (
			float).5);
/* SOURCE brnmat.for:3537 */
/*<       kmu=klu+wx*(kru-klu) >*/
		kmu = static_cast<double>(klu) + static_cast<double>(wx) * (static_cast<double>(kru) - klu);
/* SOURCE brnmat.for:3538 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3539 */
/*<       wx=0.5 >*/
		wx = (float).5;
/* SOURCE brnmat.for:3540 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3541 */
/*<       else >*/
	} else {
/*           FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT. */
/* SOURCE brnmat.for:3543 */
/*<       if(dklu*(dy+dz)-kmu.ge.0.0)then >*/
	    if (static_cast<double>(static_cast<double>(dklu) * (static_cast<double>(dy) + dz)) - kmu >= (float)0.) {
/*             SHIFT TO UPSTREAM CONVEYANCE */
/* SOURCE brnmat.for:3545 */
/*<       wx=1.0-0.4*kru/(dklu*(dy+dz)-.5*(kru-klu)) >*/
		wx = static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(kru) * (float).4) / (static_cast<double>(static_cast<double>(dklu) * (static_cast<double>(dy) + dz)) - static_cast<double>((static_cast<double>(kru) - 
			klu)) * (float).5);
/* SOURCE brnmat.for:3546 */
/*<       kmu=klu+wx*(kru-klu) >*/
		kmu = static_cast<double>(klu) + static_cast<double>(wx) * (static_cast<double>(kru) - klu);
/* SOURCE brnmat.for:3547 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3548 */
/*<       wx=0.5 >*/
		wx = (float).5;
/* SOURCE brnmat.for:3549 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3550 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3552 */
/*<       amu=alu+0.5*(aru-alu) >*/
	amu = static_cast<double>(alu) + static_cast<double>((static_cast<double>(aru) - alu)) * (float).5;
/* SOURCE brnmat.for:3553 */
/*<       wxvec(elmadr)=wx >*/
	bnelem_1.wxvec[elmadr - 1] = wx;
/* SOURCE brnmat.for:3554 */
/*<       ksum=kmu+kmu >*/
	ksum = static_cast<double>(kmu) + kmu;
/*          IF(STFLAG.EQ.0) */
/*     A     WRITE(STD6,'(6H RDVAL,6F10.3)') YRD, TRD, ARD, KRD, BRD, QRD */
/*        WRITE(STD6,'(6H RUVAL,7F10.3)') YRU, TRU, ARU, KRU, BRU, QRU, DKRU */
/*         SUPPRESS INERTIAL TERMS IF DEPTH IS TOO SMALL. */
/* SOURCE brnmat.for:3561 */
/*<       if(ylu.lt.ziy.or.yru.lt.ziy)then >*/
	if (ylu < ziy || yru < ziy) {
/* SOURCE brnmat.for:3562 */
/*<       zi=0.0 >*/
	    zi = (float)0.;
/* SOURCE brnmat.for:3563 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:3564 */
/*<       zi=zit >*/
	    zi = zit;
/* SOURCE brnmat.for:3565 */
/*<       endif >*/
	}
/*         CONTINUITY EQUATION */
/*         1) PARTIAL DERIVATIVES */
/*          WRITE(STD6,*) ' DXHDT=',DXHDT,' TLU=',TLU,' TRU=',TRU */
/* SOURCE brnmat.for:3571 */
/*<       c1=dxhdt*tlu >*/
	c1 = static_cast<double>(dxhdt) * tlu;
/* SOURCE brnmat.for:3572 */
/*<       c2=-wt >*/
	c2 = -(*wt);
/* SOURCE brnmat.for:3573 */
/*<       c3=dxhdt*tru >*/
	c3 = static_cast<double>(dxhdt) * tru;
/* SOURCE brnmat.for:3574 */
/*<       c4=wt >*/
	c4 = *wt;
/* SOURCE brnmat.for:3576 */
/*<       qp=qpvec(elmadr) >*/
	qp = bnothr_1.qpvec[elmadr - 1];
/* SOURCE brnmat.for:3577 */
/*<       cf=coefin(elmadr) >*/
	cf = bnpond_1.coefin[elmadr - 1];
/* SOURCE brnmat.for:3578 */
/*<       if(cf.gt.0.0)then >*/
	if (cf > (float)0.) {
/*            PROCESS INFLOW RESTRICTION ON SEWERS */
/* SOURCE brnmat.for:3582 */
/*<       yc=ycut(elmadr) >*/
	    yc = bnpond_1.ycut[elmadr - 1];
/* SOURCE brnmat.for:3583 */
/*<       s1=pond1(elmadr) >*/
	    s1 = bnpond_1.pond1[elmadr - 1];
/* SOURCE brnmat.for:3584 */
/*<       s2=pond2(elmadr) >*/
	    s2 = bnpond_1.pond2[elmadr - 1];
/* SOURCE brnmat.for:3585 */
/*<       ym=0.5*((ylu+yru)) >*/
	    ym = static_cast<double>((static_cast<double>(ylu) + yru)) * (float).5;
/* SOURCE brnmat.for:3586 */
/*<       dh=yc-ym >*/
	    dh = static_cast<double>(yc) - ym;
/* SOURCE brnmat.for:3587 */
/*<       if(abs(dh).le.dhstar)then >*/
	    if (dabs(dh) <= miscon_1.dhstar) {
/* SOURCE brnmat.for:3588 */
/*<       qmax=dh*cf*qpcon >*/
		qmax = static_cast<double>(static_cast<double>(dh) * cf) * miscon_1.qpcon;
/* SOURCE brnmat.for:3589 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3590 */
/*<       qmax=cf*sqrt(twog*abs(dh)) >*/
		qmax = cf * sqrt(gravcm_1.twog * dabs(dh));
/* SOURCE brnmat.for:3591 */
/*<       if(dh.lt.0.0)qmax=-qmax >*/
		if (dh < (float)0.) {
		    qmax = -qmax;
		}
/* SOURCE brnmat.for:3592 */
/*<       endif >*/
	    }
/*            CHECK FOR FLOW ALLOWED */
/* SOURCE brnmat.for:3596 */
/*<       tp=qp+s1/dt >*/
	    tp = qp + s1 / *dt;
/* SOURCE brnmat.for:3597 */
/*<       if(qmax.gt.tp)then >*/
	    if (qmax > tp) {
/* SOURCE brnmat.for:3598 */
/*<       pond2(elmadr)=0.0 >*/
		bnpond_1.pond2[elmadr - 1] = (float)0.;
/* SOURCE brnmat.for:3599 */
/*<       qp=tp >*/
		qp = tp;
/* SOURCE brnmat.for:3600 */
/*<       dqpylu=0.0 >*/
		dqpylu = (float)0.;
/* SOURCE brnmat.for:3601 */
/*<       dqpyru=0.0 >*/
		dqpyru = (float)0.;
/* SOURCE brnmat.for:3602 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3603 */
/*<       s3=s1+dt*(qp-qmax) >*/
		s3 = s1 + *dt * (static_cast<double>(qp) - qmax);
/* SOURCE brnmat.for:3604 */
/*<       b=abs(s2-s3)/(dx*oldvol) >*/
		b = (feq_gen_r_d_1 = static_cast<double>(s2) - s3, dabs(feq_gen_r_d_1)) / (static_cast<double>(dx) * oldvol);
/* SOURCE brnmat.for:3605 */
/*<       if(b.gt.errp)then >*/
		if (b > *errp) {
/* SOURCE brnmat.for:3606 */
/*<       errp=b >*/
		    *errp = b;
/* SOURCE brnmat.for:3607 */
/*<       nerrp=ubnbas+nnd-fn >*/
		    *nerrp = ubnbas + nnd - fn;
/* SOURCE brnmat.for:3608 */
/*<       berrp=nbr >*/
		    *berrp = *nbr;
/* SOURCE brnmat.for:3609 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:3610 */
/*<       pond2(elmadr)=s3 >*/
		bnpond_1.pond2[elmadr - 1] = s3;
/* SOURCE brnmat.for:3611 */
/*<       qp=qmax >*/
		qp = qmax;
/* SOURCE brnmat.for:3612 */
/*<       if(abs(dh).le.dhstar)then >*/
		if (dabs(dh) <= miscon_1.dhstar) {
/* SOURCE brnmat.for:3613 */
/*<       dqpylu=-0.5*cf*qpcon >*/
		    dqpylu = static_cast<double>(static_cast<double>(cf) * (float)-.5) * miscon_1.qpcon;
/* SOURCE brnmat.for:3614 */
/*<       dqpyru=dqpylu >*/
		    dqpyru = dqpylu;
/* SOURCE brnmat.for:3615 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:3616 */
/*<       dqpylu=-halfg*cf*cf/abs(qp) >*/
		    dqpylu = static_cast<double>(static_cast<double>(-gravcm_1.halfg) * cf) * cf / dabs(qp);
/* SOURCE brnmat.for:3617 */
/*<       dqpyru=dqpylu >*/
		    dqpyru = dqpylu;
/* SOURCE brnmat.for:3618 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:3619 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3620 */
/*<       c1=c1-dqpylu >*/
	    c1 -= dqpylu;
/* SOURCE brnmat.for:3621 */
/*<       c3=c3-dqpyru >*/
	    c3 -= dqpyru;
/* SOURCE brnmat.for:3623 */
/*<       endif >*/
	}
/*         2) RESIDUAL */
/* SOURCE brnmat.for:3626 */
/*<       ieq=ieq+1 >*/
	++(*ieq);
/* SOURCE brnmat.for:3628 */
/*<       dyndif=oldflw+wt*(qru-qlu-oldflw)-qp >*/
	dyndif = static_cast<double>(static_cast<double>(oldflw) + static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(qru) - qlu) - oldflw)) - qp;
/* SOURCE brnmat.for:3629 */
/*<       res=-((amu-oldvol)*dxdt+dyndif) >*/
	res = -(static_cast<double>(static_cast<double>((static_cast<double>(amu) - oldvol)) * dxdt) + dyndif);
/*        WRITE(STD6,2345) ' CON EQ:C1,C2,C3,C4,RES', C1, C2, C3, C4, RES */
/* 2345  FORMAT(A,5(1PE10.3)) */
/*         JCOL GIVES THE VARIABLE NUMBER AT THE FIRST COEFFICIENT IN */
/*         THE EQUATIONS. */
/* SOURCE brnmat.for:3637 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:3638 */
/*<       pdavec(r(ieq))=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c2;
/* SOURCE brnmat.for:3639 */
/*<       pdavec(c(jcol+1))=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 1] - 1] = c1;
/* SOURCE brnmat.for:3640 */
/*<       pdavec(c(jcol+2)-1)=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 2] = c4;
/* SOURCE brnmat.for:3641 */
/*<       pdavec(c(jcol+3)-2)=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 3] = c3;
/* SOURCE brnmat.for:3642 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:3643 */
/*<       pdavec(r(ieq))=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c4;
/* SOURCE brnmat.for:3644 */
/*<       pdavec(c(jcol+1))=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 1] - 1] = c3;
/* SOURCE brnmat.for:3645 */
/*<       pdavec(c(jcol+2)-1)=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 2] = c2;
/* SOURCE brnmat.for:3646 */
/*<       pdavec(c(jcol+3)-2)=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 3] = c1;
/* SOURCE brnmat.for:3647 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3649 */
/*<       rhs(ieq)=res >*/
	matcom_1.rhs[*ieq - 1] = res;
/* SOURCE brnmat.for:3652 */
/*<       err=abs(qp)/(abs(0.5*oldsum)+0.1) >*/
	err = dabs(qp) / ((feq_gen_r_d_1 = static_cast<double>(oldsum) * (float).5, dabs(feq_gen_r_d_1)) + (float).1)
		;
/* SOURCE brnmat.for:3653 */
/*<       if(err.gt.errq)then >*/
	if (err > *errq) {
/* SOURCE brnmat.for:3654 */
/*<       errq=err >*/
	    *errq = err;
/* SOURCE brnmat.for:3655 */
/*<       berrq=nbr >*/
	    *berrq = *nbr;
/* SOURCE brnmat.for:3656 */
/*<       nerrq=ubnbas+nnd-fn >*/
	    *nerrq = ubnbas + nnd - fn;
/* SOURCE brnmat.for:3657 */
/*<       endif >*/
	}
/*       MOMENTUM EQUATION */
/* SOURCE brnmat.for:3661 */
/*<       sfmt=abs(newsum)/ksum**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ksum;
	sfmt = dabs(newsum) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:3662 */
/*<       sfmu=newsum*sfmt >*/
	sfmu = static_cast<double>(newsum) * sfmt;
/*        WRITE(STD6,*) ' SFMU=', SFMU */
/* SOURCE brnmat.for:3664 */
/*<       pgfu=grav*(dz+sfmu*dx+dy) >*/
	pgfu = static_cast<double>(gravcm_1.grav) * (static_cast<double>(static_cast<double>(dz) + static_cast<double>(sfmu) * dx) + dy);
/* SOURCE brnmat.for:3665 */
/*<       vlu=qlu/alu >*/
	vlu = static_cast<double>(qlu) / alu;
/* SOURCE brnmat.for:3666 */
/*<       vru=qru/aru >*/
	vru = static_cast<double>(qru) / aru;
/* SOURCE brnmat.for:3667 */
/*<       tpa=(dx2+dx2)*sfmu/ksum >*/
	tpa = static_cast<double>(static_cast<double>((static_cast<double>(dx2) + dx2)) * sfmu) / ksum;
/* SOURCE brnmat.for:3668 */
/*<       tpb=amu*grav*dx2*sfmt >*/
	tpb = static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * dx2) * sfmt;
/*       PARTIAL DERIVATIVES */
/* SOURCE brnmat.for:3672 */
/*<        >*/
	c1 = static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * (static_cast<double>(static_cast<double>(static_cast<double>(-tpa) * dklu) * (static_cast<double>((float)1.) - wx)) - (
		float)1.)) + static_cast<double>(static_cast<double>(pgfu) * (float).5) * tlu) - static_cast<double>(static_cast<double>(zi) * (static_cast<double>(static_cast<double>(dblu) * qlu) - static_cast<double>(static_cast<double>(tlu) * 
		blu) * vlu)) * vlu);
/* SOURCE brnmat.for:3678 */
/*<       c2=zi*dxhdt+wt*(tpb-2.*zi*blu*vlu) >*/
	c2 = static_cast<double>(static_cast<double>(zi) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(tpb) - static_cast<double>(static_cast<double>(static_cast<double>(zi) * (float)2.) * blu) * vlu);
/* SOURCE brnmat.for:3681 */
/*<        >*/
	c3 = static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(amu) * gravcm_1.grav) * (static_cast<double>(static_cast<double>(static_cast<double>(-tpa) * dkru) * wx) + (float)1.)) + 
		static_cast<double>(static_cast<double>(pgfu) * (float).5) * tru) + static_cast<double>(static_cast<double>(zi) * (static_cast<double>(static_cast<double>(dbru) * qru) - static_cast<double>(static_cast<double>(tru) * bru) * vru)) *
		 vru);
/* SOURCE brnmat.for:3686 */
/*<       c4=zi*dxhdt+wt*(tpb+2.*zi*bru*vru) >*/
	c4 = static_cast<double>(static_cast<double>(zi) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(tpb) + static_cast<double>(static_cast<double>(static_cast<double>(zi) * (float)2.) * bru) * vru);
/* SOURCE brnmat.for:3689 */
/*<       if(kdc.gt.0.0.or.kac.gt.0.0)then >*/
	if (kdc > (float)0. || kac > (float)0.) {
/*         PROCESS EXPANSION AND CONTRACTION LOSSES */
/* SOURCE brnmat.for:3691 */
/*<       dv2=(vru-vlu)*(vru+vlu) >*/
	    dv2 = static_cast<double>((static_cast<double>(vru) - vlu)) * (static_cast<double>(vru) + vlu);
/*         Establish the sign of the difference in */
/*         the squared velocities. */
/* SOURCE brnmat.for:3694 */
/*<       sgndv2=sign(1.0,dv2) >*/
	    sgndv2 = (dv2 >= 0.0 ? std::fabs(static_cast<double>(c_b107)) : -std::fabs(static_cast<double>(c_b107)));
/*         Absolute value of difference of squares is */
/*         needed as well. */
/* SOURCE brnmat.for:3697 */
/*<       dv2=abs(dv2) >*/
	    dv2 = dabs(dv2);
/* SOURCE brnmat.for:3698 */
/*<       if(vlu.ge.vru)then >*/
	    if (vlu >= vru) {
/*           FLOW IS UNDERGOING NEGATIVE ACCELERATION */
/*            idir = -1 */
/* SOURCE brnmat.for:3701 */
/*<       kp=sign(kdc,newsum) >*/
		kp = (newsum >= 0.0 ? std::fabs(static_cast<double>(kdc)) : -std::fabs(static_cast<double>(kdc)));
/* SOURCE brnmat.for:3702 */
/*<       else >*/
	    } else {
/*           FLOW IS UNDERGOING POSITIVE ACCELERATION */
/*            idir = +1 */
/* SOURCE brnmat.for:3705 */
/*<       kp=sign(kac,newsum) >*/
		kp = (newsum >= 0.0 ? std::fabs(static_cast<double>(kac)) : -std::fabs(static_cast<double>(kac)));
/* SOURCE brnmat.for:3706 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3708 */
/*<       pfqlu=-kp*sgndv2*amu*vlu/alu >*/
	    pfqlu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(-kp) * sgndv2) * amu) * vlu) / alu;
/* SOURCE brnmat.for:3709 */
/*<       pfqru=kp*sgndv2*amu*vru/aru >*/
	    pfqru = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(kp) * sgndv2) * amu) * vru) / aru;
/* SOURCE brnmat.for:3710 */
/*<       pfylu=tlu*(0.25*kp*dv2-pfqlu*vlu) >*/
	    pfylu = static_cast<double>(tlu) * (static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).25) * dv2) - static_cast<double>(pfqlu) * vlu);
/* SOURCE brnmat.for:3711 */
/*<       pfyru=tru*(0.25*kp*dv2-pfqru*vru) >*/
	    pfyru = static_cast<double>(tru) * (static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).25) * dv2) - static_cast<double>(pfqru) * vru);
/* SOURCE brnmat.for:3713 */
/*<       pgfu=pgfu+0.5*kp*dv2 >*/
	    pgfu += static_cast<double>(static_cast<double>(static_cast<double>(kp) * (float).5) * dv2);
/* SOURCE brnmat.for:3714 */
/*<       c1=c1+wt*pfylu >*/
	    c1 += static_cast<double>(*wt) * pfylu;
/* SOURCE brnmat.for:3715 */
/*<       c2=c2+wt*pfqlu >*/
	    c2 += static_cast<double>(*wt) * pfqlu;
/* SOURCE brnmat.for:3716 */
/*<       c3=c3+wt*pfyru >*/
	    c3 += static_cast<double>(*wt) * pfyru;
/* SOURCE brnmat.for:3717 */
/*<       c4=c4+wt*pfqru >*/
	    c4 += static_cast<double>(*wt) * pfqru;
/* SOURCE brnmat.for:3719 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3721 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/*         POINT LOSS BASED ON AVERAGE VELOCITY HEAD IN ELEMENT */
/* SOURCE brnmat.for:3723 */
/*<       ym=0.5*(ylu+yru) >*/
	    ym = static_cast<double>((static_cast<double>(ylu) + yru)) * (float).5;
/* SOURCE brnmat.for:3724 */
/*<       calllktab(adrs,ym,0,khlm,ntab,dkhlm) >*/
	    lktab_(&adrs, &ym, &feq_gen_c_d_0, &khlm, &ntab, &dkhlm);
/* SOURCE brnmat.for:3727 */
/*<       if(newsum.lt.0.0)then >*/
	    if (newsum < (float)0.) {
/* SOURCE brnmat.for:3728 */
/*<       khlm=-khlm >*/
		khlm = -khlm;
/* SOURCE brnmat.for:3729 */
/*<       dkhlm=-dkhlm >*/
		dkhlm = -dkhlm;
/* SOURCE brnmat.for:3730 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3732 */
/*<       tpa=newsum/(alu+aru)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(alu) + aru;
	    tpa = static_cast<double>(newsum) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:3733 */
/*<       tpb=tpa*newsum >*/
	    tpb = static_cast<double>(tpa) * newsum;
/* SOURCE brnmat.for:3734 */
/*<       gde=0.5*khlm*tpb >*/
	    gde = static_cast<double>(static_cast<double>(khlm) * (float).5) * tpb;
/* SOURCE brnmat.for:3735 */
/*<       pgfu=pgfu+gde >*/
	    pgfu += gde;
/* SOURCE brnmat.for:3736 */
/*<       tpc=wt*amu >*/
	    tpc = static_cast<double>(*wt) * amu;
/* SOURCE brnmat.for:3737 */
/*<       tpd=khlm*tpa >*/
	    tpd = static_cast<double>(khlm) * tpa;
/* SOURCE brnmat.for:3739 */
/*<       c1=c1-tpc*(tpd*tlu-dkhlm*tpb) >*/
	    c1 -= static_cast<double>(tpc) * (static_cast<double>(static_cast<double>(tpd) * tlu) - static_cast<double>(dkhlm) * tpb);
/* SOURCE brnmat.for:3740 */
/*<       c2=c2+tpc*tpd >*/
	    c2 += static_cast<double>(tpc) * tpd;
/* SOURCE brnmat.for:3741 */
/*<       c3=c3-tpc*(tpd*tru-dkhlm*tpb) >*/
	    c3 -= static_cast<double>(tpc) * (static_cast<double>(static_cast<double>(tpd) * tru) - static_cast<double>(dkhlm) * tpb);
/* SOURCE brnmat.for:3742 */
/*<       c4=c4+tpc*tpd >*/
	    c4 += static_cast<double>(tpc) * tpd;
/* SOURCE brnmat.for:3743 */
/*<       endif >*/
	}
/*        IF(C1.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C1=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C2.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C2=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C3.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C3=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*        IF(C4.EQ.0.0) THEN */
/*          WRITE(STD6,*) ' C4=0.0 AT IEQ=',IEQ */
/*          STOP 'Abnormal stop: errors found.' */
/*        ENDIF */
/*       RESIDUAL */
/* SOURCE brnmat.for:3765 */
/*<        >*/
	res = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(zi) * (static_cast<double>(newsum) - oldsum)) * dxhdt) + static_cast<double>(*wt) * (static_cast<double>(static_cast<double>(pgfu) * amu) + static_cast<double>(zi) * (static_cast<double>(static_cast<double>(static_cast<double>(bru) *
		 qru) * vru) - static_cast<double>(static_cast<double>(blu) * qlu) * vlu))) + static_cast<double>(wtc) * oldimp) - oldwnd;
/* SOURCE brnmat.for:3768 */
/*<       ieq=ieq+1 >*/
	++(*ieq);
/*        WRITE(STD6,2345) ' MOM EQ:C1,C2,C3,C4,RES', C1, C2, C3, C4, RES */
/* SOURCE brnmat.for:3773 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:3774 */
/*<       pdavec(r(ieq)-1)=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 2] = c2;
/* SOURCE brnmat.for:3775 */
/*<       pdavec(r(ieq))=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c1;
/* SOURCE brnmat.for:3776 */
/*<       pdavec(c(jcol+2))=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 1] = c4;
/* SOURCE brnmat.for:3777 */
/*<       pdavec(c(jcol+3)-1)=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 2] = c3;
/* SOURCE brnmat.for:3778 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:3779 */
/*<       pdavec(r(ieq)-1)=c4 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 2] = c4;
/* SOURCE brnmat.for:3780 */
/*<       pdavec(r(ieq))=c3 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[*ieq - 1] - 1] = c3;
/* SOURCE brnmat.for:3781 */
/*<       pdavec(c(jcol+2))=c2 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 2] - 1] = c2;
/* SOURCE brnmat.for:3782 */
/*<       pdavec(c(jcol+3)-1)=c1 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol + 3] - 2] = c1;
/* SOURCE brnmat.for:3783 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3785 */
/*<       rhs(ieq)=-res >*/
	matcom_1.rhs[*ieq - 1] = -res;
/*         TRANSFER VALUES */
/* SOURCE brnmat.for:3789 */
/*<       if(ninc.gt.0)then >*/
	if (ninc > 0) {
/* SOURCE brnmat.for:3790 */
/*<       qlu=qru >*/
	    qlu = qru;
/* SOURCE brnmat.for:3791 */
/*<       alu=aru >*/
	    alu = aru;
/* SOURCE brnmat.for:3792 */
/*<       tlu=tru >*/
	    tlu = tru;
/* SOURCE brnmat.for:3793 */
/*<       ylu=yru >*/
	    ylu = yru;
/* SOURCE brnmat.for:3794 */
/*<       klu=kru >*/
	    klu = kru;
/* SOURCE brnmat.for:3795 */
/*<       dklu=dkru >*/
	    dklu = dkru;
/* SOURCE brnmat.for:3796 */
/*<       blu=bru >*/
	    blu = bru;
/* SOURCE brnmat.for:3797 */
/*<       dblu=dbru >*/
	    dblu = dbru;
/* SOURCE brnmat.for:3798 */
/*<       else >*/
	} else {
/* SOURCE brnmat.for:3799 */
/*<       qru=qlu >*/
	    qru = qlu;
/* SOURCE brnmat.for:3800 */
/*<       aru=alu >*/
	    aru = alu;
/* SOURCE brnmat.for:3801 */
/*<       tru=tlu >*/
	    tru = tlu;
/* SOURCE brnmat.for:3802 */
/*<       yru=ylu >*/
	    yru = ylu;
/* SOURCE brnmat.for:3803 */
/*<       kru=klu >*/
	    kru = klu;
/* SOURCE brnmat.for:3804 */
/*<       dkru=dklu >*/
	    dkru = dklu;
/* SOURCE brnmat.for:3805 */
/*<       bru=blu >*/
	    bru = blu;
/* SOURCE brnmat.for:3806 */
/*<       dbru=dblu >*/
	    dbru = dblu;
/* SOURCE brnmat.for:3807 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3808 */
/*<       jcol=jcol+2 >*/
	jcol += 2;
/* SOURCE brnmat.for:3810 */
/*<   100 continue >*/
/* L100: */
    }
/*      WRITE(STD6,*) ' ' */
/* SOURCE brnmat.for:3813 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:3814 */
/*<       end >*/
} /* setinx_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE brnmat.for:3818 */
/*<        >*/
/* Subroutine */ int sidewr_(integer *ipnt, integer *stdout, doublereal *
	jtime, integer *nex, integer *mremc, integer *feq_storage_emc, integer *feq_storage_exnodt, 
	real *feq_storage_qe2, real *feq_storage_ye2, real *feq_storage_ze, real *res, real *pyl, real *pql, real 
	*pyr, real *pqr, real *pym, real *pqm)
{
    /* System generated locals */
    static real equiv_0[1];

    /* Local variables */
    real feq_gen_fac_comp_d_, feq_gen_dqzm_org_d_, b, p, q, w;
    integer feq_gen_crest_tab_d_;
    real db, cf, dt, wc, qm;
    integer feq_gen_mftab_fail_d_;
    real zm, feq_gen_dqzbar_org_d_, feq_gen_hcrest_org_d_, fac;
    integer mdn, dnn;
    real con, pdv;
    integer unn;
    real head, abar, dcfq;
    integer free;
    real dcon;
    integer ntab;
    real dcfy, qbar, tbar, ybar;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    real zbar, htoe;
#define rdum (equiv_0)
    real dqzm;
    integer feq_gen_type_d_;
    extern /* Subroutine */ int tdlk6_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *);
    integer mftab, dutab, udtab;
    extern /* Subroutine */ int tdlk13_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *), tdlk43_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *);
    real feq_gen_q_org_d_;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *), findcf_(integer *, real *
	    , real *, real *, real *, real *, real *, real *);
    real dqzbar, hcrest;
    extern integer gettyp_(integer *);
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Compute the residual and derivatives for side weir flows when */
/*     flows are defined by water surface elevation. */
/* SOURCE brnmat.for:3827 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE brnmat.for:3829 */
/*<       integeripnt,stdout,mremc,nex >*/
/* SOURCE brnmat.for:3830 */
/*<       integeremc(mremc),exnodt(9,nex) >*/
/* SOURCE brnmat.for:3831 */
/*<       realpql,pqm,pqr,pyl,pym,pyr,qe2(nex),res,ye2(nex),ze(nex) >*/
/* SOURCE brnmat.for:3833 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TIME   - elapsed time in seconds from start of run */
/*     NEX    - number of exterior nodes in the model */
/*     MREMC  - maximum length of EMC(*). Same as LEMC */
/*     EMC    - vector containing coded form of the Matrix Control Input */
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
/*     QE2    - flow at exterior nodes at end of time step */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     PYM    - partial derivative of residual function wrt depth at */
/*               middle node */
/*     PQM    - partial derivative of residual wrt to flow at middle */
/*               node */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:3874 */
/*<        >*/
/* SOURCE brnmat.for:3876 */
/*<        >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE brnmat.for:3882 */
/*<       equivalence(idum,rdum) >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE brnmat.for:3885 */
/*<       integergettyp >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE brnmat.for:3888 */
/*<       externalfindcf,gettyp,lktab,tdlk13,tdlk6,xlkt20 >*/
/* *********************************************************************** */
/*     GET KEY VALUES */
/* SOURCE brnmat.for:3892 */
/*<       unn=emc(ipnt+1) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    unn = emc[*ipnt + 1];
/* SOURCE brnmat.for:3893 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[*ipnt + 2];
/*     THE MIDDLE NODE(MDN) IS ALWAYS THE FLOW NODE FOR A SIDE WEIR */
/* SOURCE brnmat.for:3896 */
/*<       mdn=emc(ipnt+3) >*/
    mdn = emc[*ipnt + 3];
/* SOURCE brnmat.for:3897 */
/*<       udtab=emc(ipnt+4) >*/
    udtab = emc[*ipnt + 4];
/* SOURCE brnmat.for:3898 */
/*<       dutab=emc(ipnt+5) >*/
    dutab = emc[*ipnt + 5];
/* SOURCE brnmat.for:3899 */
/*<       mftab=emc(ipnt+6) >*/
    mftab = emc[*ipnt + 6];
/* SOURCE brnmat.for:3900 */
/*<       crest_tab=emc(ipnt+7) >*/
    feq_gen_crest_tab_d_ = emc[*ipnt + 7];
/* SOURCE brnmat.for:3901 */
/*<       idum=emc(ipnt+8) >*/
    *idum = emc[*ipnt + 8];
/* SOURCE brnmat.for:3902 */
/*<       w=rdum >*/
    w = *rdum;
/* SOURCE brnmat.for:3903 */
/*<       idum=emc(ipnt+9) >*/
    *idum = emc[*ipnt + 9];
/* SOURCE brnmat.for:3904 */
/*<       hcrest=rdum >*/
    hcrest = *rdum;
/* SOURCE brnmat.for:3905 */
/*<       idum=emc(ipnt+10) >*/
    *idum = emc[*ipnt + 10];
/* SOURCE brnmat.for:3906 */
/*<       htoe=rdum >*/
    htoe = *rdum;
/*     Disable special treatment of the flow factor.  Maybe enabled below. */
/* SOURCE brnmat.for:3909 */
/*<       mftab_fail=0 >*/
    feq_gen_mftab_fail_d_ = 0;
/*     Compute current crest elevation. */
/* SOURCE brnmat.for:3912 */
/*<       if(crest_tab.gt.0)then >*/
    if (feq_gen_crest_tab_d_ > 0) {
/* SOURCE brnmat.for:3913 */
/*<       calllktstab(crest_tab,jtime,p,ntab,pdv) >*/
	lktstab_(&feq_gen_crest_tab_d_, jtime, &p, &ntab, &pdv);
/*       P gives the decimal fraction of the distance from */
/*       the original crest to the toe of the overflow structure */
/*       that is added to the original crest elevation.  Thus */
/*       P > 0 represents a flood fight in raising the crest */
/*       and P < 0 represent erosion, settling, or collapse */
/*       during a levee failure. */
/* SOURCE brnmat.for:3923 */
/*<       if(mftab.gt.0)then >*/
	if (mftab > 0) {
/*         We have both a factor and a moving crest.  This changes the */
/*         application of the factor to give the weighted sum of flows */
/*         at the head computed from the original crest and the head */
/*         computed at the current crest.  This approximates flow over */
/*         a levee segment that has part of its length eroding. */
/*         We need to have the potential for flow over the part that is */
/*         not eroded and over the part that is eroding. */
/*         Remember the original crest elevation. */
/* SOURCE brnmat.for:3932 */
/*<       hcrest_org=hcrest >*/
	    feq_gen_hcrest_org_d_ = hcrest;
/*         We also change the point at which the factor on flow is applied. */
/* SOURCE brnmat.for:3935 */
/*<       mftab_fail=mftab >*/
	    feq_gen_mftab_fail_d_ = mftab;
/* SOURCE brnmat.for:3936 */
/*<       mftab=0 >*/
	    mftab = 0;
/* SOURCE brnmat.for:3937 */
/*<       calllktstab(mftab_fail,jtime,fac,ntab,pdv) >*/
	    lktstab_(&feq_gen_mftab_fail_d_, jtime, &fac, &ntab, &pdv);
/* SOURCE brnmat.for:3940 */
/*<       fac_comp=1.-fac >*/
	    feq_gen_fac_comp_d_ = static_cast<double>((float)1.) - fac;
/* SOURCE brnmat.for:3941 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:3943 */
/*<       hcrest=hcrest+p*(hcrest-htoe) >*/
	hcrest += static_cast<double>(p) * (static_cast<double>(hcrest) - htoe);
/* SOURCE brnmat.for:3944 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:3946 */
/*<       wc=1.0-w >*/
    wc = static_cast<double>((float)1.) - w;
/* SOURCE brnmat.for:3948 */
/*<       ybar=w*ye2(unn)+wc*ye2(dnn) >*/
    ybar = static_cast<double>(static_cast<double>(w) * ye2[unn]) + static_cast<double>(wc) * ye2[dnn];
/* SOURCE brnmat.for:3949 */
/*<       zbar=ybar+ze(unn) >*/
    zbar = static_cast<double>(ybar) + ze[unn];
/* SOURCE brnmat.for:3950 */
/*<       zm=ye2(mdn)+ze(mdn) >*/
    zm = static_cast<double>(ye2[mdn]) + ze[mdn];
/* SOURCE brnmat.for:3952 */
/*<       qbar=w*qe2(unn)+wc*qe2(dnn) >*/
    qbar = static_cast<double>(static_cast<double>(w) * qe2[unn]) + static_cast<double>(wc) * qe2[dnn];
/* SOURCE brnmat.for:3953 */
/*<       qm=qe2(mdn) >*/
    qm = qe2[mdn];
/*     BASE FLOW DIRECTION ON WATER SURFACE ELEVATION. */
/* SOURCE brnmat.for:3957 */
/*<       if(zbar.ge.zm)then >*/
    if (zbar >= zm) {
/* SOURCE brnmat.for:3958 */
/*<       if(zbar.gt.hcrest)then >*/
	if (zbar > hcrest) {
/*         OUTFLOW FROM THE SOURCE CHANNEL */
/* SOURCE brnmat.for:3960 */
/*<       type=gettyp(udtab) >*/
	    feq_gen_type_d_ = gettyp_(&udtab);
/* SOURCE brnmat.for:3961 */
/*<       if(type.eq.43)then >*/
	    if (feq_gen_type_d_ == 43) {
/* SOURCE brnmat.for:3962 */
/*<        >*/
		tdlk43_(stdout, &udtab, &feq_gen_c_d_43, &mftab, jtime, &zm, &zbar, &
			hcrest, &q, &dqzm, &dqzbar, &free);
/* SOURCE brnmat.for:3965 */
/*<       elseif(type.eq.13)then >*/
	    } else if (feq_gen_type_d_ == 13) {
/* SOURCE brnmat.for:3966 */
/*<        >*/
		tdlk13_(stdout, &udtab, &feq_gen_c_d_13, &mftab, jtime, &zm, &zbar, &
			hcrest, &q, &dqzm, &dqzbar, &free);
/* SOURCE brnmat.for:3969 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:3970 */
/*<        >*/
		tdlk6_(stdout, &udtab, &feq_gen_c_d_6, &mftab, jtime, &zm, &zbar, &
			hcrest, &q, &dqzm, &dqzbar, &free);
/* SOURCE brnmat.for:3973 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:3975 */
/*<       if(mftab_fail.gt.0)then >*/
	    if (feq_gen_mftab_fail_d_ > 0) {
/*           We have the case with both a moving crest and a flow factor. */
/*           The flow and derivatives we have in hand now are for the */
/*           moving crest. We must compute the values for the original crest */
/*           and then compute a weighted sum. */
/* SOURCE brnmat.for:3980 */
/*<       if(type.eq.43)then >*/
		if (feq_gen_type_d_ == 43) {
/* SOURCE brnmat.for:3981 */
/*<        >*/
		    tdlk43_(stdout, &udtab, &feq_gen_c_d_43, &mftab, jtime, &zm, &zbar,
			     &feq_gen_hcrest_org_d_, &feq_gen_q_org_d_, &feq_gen_dqzm_org_d_, &
			    feq_gen_dqzbar_org_d_, &free);
/* SOURCE brnmat.for:3985 */
/*<       elseif(type.eq.13)then >*/
		} else if (feq_gen_type_d_ == 13) {
/* SOURCE brnmat.for:3986 */
/*<        >*/
		    tdlk13_(stdout, &udtab, &feq_gen_c_d_13, &mftab, jtime, &zm, &zbar,
			     &feq_gen_hcrest_org_d_, &feq_gen_q_org_d_, &feq_gen_dqzm_org_d_, &
			    feq_gen_dqzbar_org_d_, &free);
/* SOURCE brnmat.for:3990 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:3991 */
/*<        >*/
		    tdlk6_(stdout, &udtab, &feq_gen_c_d_6, &mftab, jtime, &zm, &zbar, &
			    feq_gen_hcrest_org_d_, &feq_gen_q_org_d_, &feq_gen_dqzm_org_d_, &
			    feq_gen_dqzbar_org_d_, &free);
/* SOURCE brnmat.for:3995 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:3997 */
/*<       q=fac*q+fac_comp*q_org >*/
		q = static_cast<double>(static_cast<double>(fac) * q) + static_cast<double>(feq_gen_fac_comp_d_) * feq_gen_q_org_d_;
/* SOURCE brnmat.for:3998 */
/*<       dqzm=fac*dqzm+fac_comp*dqzm_org >*/
		dqzm = static_cast<double>(static_cast<double>(fac) * dqzm) + static_cast<double>(feq_gen_fac_comp_d_) * feq_gen_dqzm_org_d_;
/* SOURCE brnmat.for:3999 */
/*<       dqzbar=fac*dqzbar+fac_comp*dqzbar_org >*/
		dqzbar = static_cast<double>(static_cast<double>(fac) * dqzbar) + static_cast<double>(feq_gen_fac_comp_d_) * feq_gen_dqzbar_org_d_;
/* SOURCE brnmat.for:4000 */
/*<       endif >*/
	    }
/*         FIND THE AREA AND TOP WIDTH AT THE MEAN DEPTH IN THE */
/*         SOURCE CHANNEL  to compute the Hager side-weir correction factor. */
/* SOURCE brnmat.for:4005 */
/*<       callxlkt20(exnodt(4,unn),ybar,abar,tbar,dt,con,dcon,b,db) >*/
	    xlkt20_(&exnodt[unn * 9 + 4], &ybar, &abar, &tbar, &dt, &con, &
		    dcon, &b, &db);
/*         FIND THE HAGER SIDE WEIR FUNCTION AT THE MEAN PARAMETERS */
/*         FOR THE SIDE WEIR */
/* SOURCE brnmat.for:4013 */
/*<       head=zbar-hcrest >*/
	    head = static_cast<double>(zbar) - hcrest;
/* SOURCE brnmat.for:4014 */
/*<       if(head>0.0)then >*/
	    if (head > (float)0.) {
/*           There are some cases where head=0 appears here even */
/*           though zbar tests as greater than hcrest!. */
/* SOURCE brnmat.for:4017 */
/*<       callfindcf(stdout,abar,tbar,qbar,head,cf,dcfy,dcfq) >*/
		findcf_(stdout, &abar, &tbar, &qbar, &head, &cf, &dcfy, &dcfq)
			;
/* SOURCE brnmat.for:4020 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:4021 */
/*<       cf=1.0 >*/
		cf = (float)1.;
/* SOURCE brnmat.for:4022 */
/*<       dcfy=0.0 >*/
		dcfy = (float)0.;
/* SOURCE brnmat.for:4023 */
/*<       dcfq=0.0 >*/
		dcfq = (float)0.;
/* SOURCE brnmat.for:4024 */
/*<       endif >*/
	    }
/*         Set the sign of the tabulated flow and derivatives to match what */
/*         the flow direction and the sign of the flow node require.   If the */
/*         sign of the flow node is -1, then the flow out of the source channel */
/*         that we have here dictates positive flow.  That is what we get */
/*         from the table by default.  Thus we need only switch if the */
/*         sign of the flow node is +1. */
/* SOURCE brnmat.for:4032 */
/*<       if(exnodt(1,mdn).eq.1)then >*/
	    if (exnodt[mdn * 9 + 1] == 1) {
/*           flow at flow node should be negative.  The values from the table */
/*           are positive.  The derivatives change sign with the flow in the */
/*           table as well. */
/* SOURCE brnmat.for:4037 */
/*<       q=-q >*/
		q = -q;
/* SOURCE brnmat.for:4038 */
/*<       dqzm=-dqzm >*/
		dqzm = -dqzm;
/* SOURCE brnmat.for:4039 */
/*<       dqzbar=-dqzbar >*/
		dqzbar = -dqzbar;
/* SOURCE brnmat.for:4040 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:4041 */
/*<       else >*/
	} else {
/*         Water below crest on both sides. */
/* SOURCE brnmat.for:4043 */
/*<       q=0.0 >*/
	    q = (float)0.;
/* SOURCE brnmat.for:4044 */
/*<       dqzm=0.0 >*/
	    dqzm = (float)0.;
/* SOURCE brnmat.for:4045 */
/*<       dqzbar=0.0 >*/
	    dqzbar = (float)0.;
/* SOURCE brnmat.for:4046 */
/*<       cf=1.0 >*/
	    cf = (float)1.;
/* SOURCE brnmat.for:4047 */
/*<       dcfy=0.0 >*/
	    dcfy = (float)0.;
/* SOURCE brnmat.for:4048 */
/*<       dcfq=0.0 >*/
	    dcfq = (float)0.;
/* SOURCE brnmat.for:4049 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:4052 */
/*<       pyl=(cf*dqzbar+dcfy*q)*w >*/
	*pyl = static_cast<double>((static_cast<double>(static_cast<double>(cf) * dqzbar) + static_cast<double>(dcfy) * q)) * w;
/* SOURCE brnmat.for:4053 */
/*<       pql=dcfq*w*q >*/
	*pql = static_cast<double>(static_cast<double>(dcfq) * w) * q;
/* SOURCE brnmat.for:4054 */
/*<       pyr=(cf*dqzbar+dcfy*q)*wc >*/
	*pyr = static_cast<double>((static_cast<double>(static_cast<double>(cf) * dqzbar) + static_cast<double>(dcfy) * q)) * wc;
/* SOURCE brnmat.for:4055 */
/*<       pqr=dcfq*wc*q >*/
	*pqr = static_cast<double>(static_cast<double>(dcfq) * wc) * q;
/* SOURCE brnmat.for:4056 */
/*<       pym=cf*dqzm >*/
	*pym = static_cast<double>(cf) * dqzm;
/* SOURCE brnmat.for:4057 */
/*<       pqm=-1. >*/
	*pqm = (float)-1.;
/* SOURCE brnmat.for:4058 */
/*<       res=cf*q-qm >*/
	*res = static_cast<double>(static_cast<double>(cf) * q) - qm;
/* SOURCE brnmat.for:4060 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:4061 */
/*<       if(zm.gt.hcrest)then >*/
	if (zm > hcrest) {
/*         FLOW INTO THE SOURCE CHANNEL.  THE HAGER SIDE WEIR FUNCTION */
/*         NO LONGER APPLIES.  NOW THE MIDDLE NODE IS THE PHYSICALLY */
/*         UPSTREAM NODE. */
/* SOURCE brnmat.for:4066 */
/*<       type=gettyp(dutab) >*/
	    feq_gen_type_d_ = gettyp_(&dutab);
/* SOURCE brnmat.for:4067 */
/*<       if(type.eq.43)then >*/
	    if (feq_gen_type_d_ == 43) {
/* SOURCE brnmat.for:4068 */
/*<        >*/
		tdlk43_(stdout, &dutab, &feq_gen_c_d_43, &mftab, jtime, &zbar, &zm, &
			hcrest, &q, &dqzbar, &dqzm, &free);
/* SOURCE brnmat.for:4071 */
/*<       elseif(type.eq.13)then >*/
	    } else if (feq_gen_type_d_ == 13) {
/* SOURCE brnmat.for:4072 */
/*<        >*/
		tdlk13_(stdout, &dutab, &feq_gen_c_d_13, &mftab, jtime, &zbar, &zm, &
			hcrest, &q, &dqzbar, &dqzm, &free);
/* SOURCE brnmat.for:4075 */
/*<       else >*/
	    } else {
/* SOURCE brnmat.for:4076 */
/*<        >*/
		tdlk6_(stdout, &dutab, &feq_gen_c_d_6, &mftab, jtime, &zbar, &zm, &
			hcrest, &q, &dqzbar, &dqzm, &free);
/* SOURCE brnmat.for:4079 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:4081 */
/*<       if(mftab_fail.gt.0)then >*/
	    if (feq_gen_mftab_fail_d_ > 0) {
/* SOURCE brnmat.for:4082 */
/*<       if(type.eq.43)then >*/
		if (feq_gen_type_d_ == 43) {
/* SOURCE brnmat.for:4083 */
/*<        >*/
		    tdlk43_(stdout, &dutab, &feq_gen_c_d_43, &mftab, jtime, &zbar, &zm,
			     &feq_gen_hcrest_org_d_, &feq_gen_q_org_d_, &feq_gen_dqzbar_org_d_, &
			    feq_gen_dqzm_org_d_, &free);
/* SOURCE brnmat.for:4087 */
/*<       elseif(type.eq.13)then >*/
		} else if (feq_gen_type_d_ == 13) {
/* SOURCE brnmat.for:4088 */
/*<        >*/
		    tdlk13_(stdout, &dutab, &feq_gen_c_d_13, &mftab, jtime, &zbar, &zm,
			     &feq_gen_hcrest_org_d_, &feq_gen_q_org_d_, &feq_gen_dqzbar_org_d_, &
			    feq_gen_dqzm_org_d_, &free);
/* SOURCE brnmat.for:4092 */
/*<       else >*/
		} else {
/* SOURCE brnmat.for:4093 */
/*<        >*/
		    tdlk6_(stdout, &dutab, &feq_gen_c_d_6, &mftab, jtime, &zbar, &zm, &
			    feq_gen_hcrest_org_d_, &feq_gen_q_org_d_, &feq_gen_dqzbar_org_d_, &
			    feq_gen_dqzm_org_d_, &free);
/* SOURCE brnmat.for:4097 */
/*<       endif >*/
		}
/* SOURCE brnmat.for:4098 */
/*<       q=fac*q+fac_comp*q_org >*/
		q = static_cast<double>(static_cast<double>(fac) * q) + static_cast<double>(feq_gen_fac_comp_d_) * feq_gen_q_org_d_;
/* SOURCE brnmat.for:4099 */
/*<       dqzm=fac*dqzm+fac_comp*dqzm_org >*/
		dqzm = static_cast<double>(static_cast<double>(fac) * dqzm) + static_cast<double>(feq_gen_fac_comp_d_) * feq_gen_dqzm_org_d_;
/* SOURCE brnmat.for:4100 */
/*<       dqzbar=fac*dqzbar+fac_comp*dqzbar_org >*/
		dqzbar = static_cast<double>(static_cast<double>(fac) * dqzbar) + static_cast<double>(feq_gen_fac_comp_d_) * feq_gen_dqzbar_org_d_;
/* SOURCE brnmat.for:4101 */
/*<       endif >*/
	    }
/*         Set the sign.  We have flow into the source channel and therefore */
/*         out of the flow node.  Thus if the flow-node sign is -1 we need */
/*         make the flow negative.  The default positive values from the table */
/*         are in accord with a flow-node sign of +1. */
/* SOURCE brnmat.for:4107 */
/*<       if(exnodt(1,mdn).eq.-1)then >*/
	    if (exnodt[mdn * 9 + 1] == -1) {
/* SOURCE brnmat.for:4108 */
/*<       q=-q >*/
		q = -q;
/* SOURCE brnmat.for:4109 */
/*<       dqzm=-dqzm >*/
		dqzm = -dqzm;
/* SOURCE brnmat.for:4110 */
/*<       dqzbar=-dqzbar >*/
		dqzbar = -dqzbar;
/* SOURCE brnmat.for:4111 */
/*<       endif >*/
	    }
/* SOURCE brnmat.for:4112 */
/*<       else >*/
	} else {
/*         No flow.  Both sides below crest */
/* SOURCE brnmat.for:4114 */
/*<       q=0.0 >*/
	    q = (float)0.;
/* SOURCE brnmat.for:4115 */
/*<       dqzm=0.0 >*/
	    dqzm = (float)0.;
/* SOURCE brnmat.for:4116 */
/*<       dqzbar=0.0 >*/
	    dqzbar = (float)0.;
/* SOURCE brnmat.for:4117 */
/*<       endif >*/
	}
/* SOURCE brnmat.for:4119 */
/*<       pyl=dqzbar*w >*/
	*pyl = static_cast<double>(dqzbar) * w;
/* SOURCE brnmat.for:4120 */
/*<       pql=0.0 >*/
	*pql = (float)0.;
/* SOURCE brnmat.for:4121 */
/*<       pyr=dqzbar*wc >*/
	*pyr = static_cast<double>(dqzbar) * wc;
/* SOURCE brnmat.for:4122 */
/*<       pqr=0.0 >*/
	*pqr = (float)0.;
/* SOURCE brnmat.for:4123 */
/*<       pym=dqzm >*/
	*pym = dqzm;
/* SOURCE brnmat.for:4124 */
/*<       pqm=-1. >*/
	*pqm = (float)-1.;
/* SOURCE brnmat.for:4125 */
/*<       res=q-qm >*/
	*res = static_cast<double>(q) - qm;
/* SOURCE brnmat.for:4126 */
/*<       endif >*/
    }
/* c     Debug code */
/*      CALL GETINN */
/*     M           ('F3283', */
/*     O            EFLAG, it) */

/*      if(mdn.eq.it) then */
/*        write(stdout,50) res, pyl, pql, pyr, pqr, pym, pqm */
/* 50    format(/,' Debug:',/,' res=',1pe12.5,' pyl=',1pe12.5, */
/*     a ' pql=',1pe12.5,' pyr=',1pe12.5,' pqr=',1pe12.5, */
/*     b ' pym=',1pe12.5,' pqm=',0pf5.1) */
/*        write(stdout,52) zbar, qbar, zm, qm */
/* 52    format(' zbar=',f10.4,' qbar=',1pe12.5,' zm=',0pf10.4, */
/*     a   ' qm=',1pe12.5) */
/*        write(stdout,54) q, dqzbar, dqzm */
/* 54    format(' q=',1pe12.5,' dqzbar=',1pe12.5,' dqzm=',1pe12.5) */
/*        write(stdout,56) cf, DCFY, DCFQ */
/* 56    format(' cf=',1pe12.5,' dcfy=',1pe12.5,' dcfq=',1pe12.5) */
/*        write(stdout,58) fac, p, hcrest */
/* 58    format(' fac=',1pe12.5,' p=',0pf10.4,'hcrest=',f10.4) */
/*      endif */
/* SOURCE brnmat.for:4150 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:4152 */
/*<       end >*/
} /* sidewr_ */

#undef rdum
#undef idum





/* SOURCE brnmat.for:4156 */
/*<       subroutinewshear(jtime,shear,wx,wy) >*/
/* Subroutine */ int wshear_(doublereal *jtime, real *shear, real *wx, real *
	wy)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    real vp;
    integer ntab;
    real windv, windco, windir;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Compute wind shear and its directional components. */
/* SOURCE brnmat.for:4163 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE brnmat.for:4165 */
/*<       realshear,wx,wy >*/
/* SOURCE brnmat.for:4166 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TIME   - elapsed time in seconds from start of run */
/*     SHEAR  - wind shear value */
/*     WX     - sine of the wind direction */
/*     WY     - cosine of the wind direction */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE brnmat.for:4175 */
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
/* INCLUDE brnmat.for:4176 */
/* SOURCE wincom.cmn:2 */
/*<        >*/
/* SOURCE wincom.cmn:5 */
/*<       integerwintab >*/
/* SOURCE wincom.cmn:7 */
/*<       realairwat,vamin,cdmin,vamax,cdmax,vadif,cddif >*/
/* SOURCE wincom.cmn:9 */
/*<       realwdfvec(mnbra) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE brnmat.for:4179 */
/*<       integerntab >*/
/* SOURCE brnmat.for:4180 */
/*<       realvp,windco,windir,windv >*/
/*     + + + INTRINSICS + + + */
/* SOURCE brnmat.for:4183 */
/*<       intrinsiccos,sin >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE brnmat.for:4186 */
/*<       externallktstab >*/
/* *********************************************************************** */
/* SOURCE brnmat.for:4188 */
/*<       calllktstab(wintab,jtime,windv,ntab,windir) >*/
    lktstab_(&wincom_1.wintab, jtime, &windv, &ntab, &windir);
/* SOURCE brnmat.for:4192 */
/*<       if(windv.ge.vamax)then >*/
    if (windv >= wincom_1.vamax) {
/* SOURCE brnmat.for:4193 */
/*<       windco=cdmax >*/
	windco = wincom_1.cdmax;
/* SOURCE brnmat.for:4194 */
/*<       elseif(windv.le.vamin)then >*/
    } else if (windv <= wincom_1.vamin) {
/* SOURCE brnmat.for:4195 */
/*<       windco=cdmin >*/
	windco = wincom_1.cdmin;
/* SOURCE brnmat.for:4196 */
/*<       else >*/
    } else {
/* SOURCE brnmat.for:4197 */
/*<       vp=(windv-vamin)/vadif >*/
	vp = static_cast<double>((static_cast<double>(windv) - wincom_1.vamin)) / wincom_1.vadif;
/* SOURCE brnmat.for:4199 */
/*<       windco=cdmin-cddif*(vp*(2.0*vp**2-3.0*vp)) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = vp;
	windco = static_cast<double>(wincom_1.cdmin) - static_cast<double>(wincom_1.cddif) * (static_cast<double>(vp) * (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (
		float)2.) - static_cast<double>(vp) * (float)3.));
/* SOURCE brnmat.for:4200 */
/*<       endif >*/
    }
/* SOURCE brnmat.for:4201 */
/*<       shear=windco*airwat*windv**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = windv;
    *shear = static_cast<double>(static_cast<double>(windco) * wincom_1.airwat) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE brnmat.for:4202 */
/*<       wx=sin(windir) >*/
    *wx = sin(windir);
/* SOURCE brnmat.for:4203 */
/*<       wy=cos(windir) >*/
    *wy = cos(windir);
/* SOURCE brnmat.for:4205 */
/*<       return >*/
    return 0;
/* SOURCE brnmat.for:4206 */
/*<       end >*/
} /* wshear_ */

#ifdef __cplusplus
	}
#endif
