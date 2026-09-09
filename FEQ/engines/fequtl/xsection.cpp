#include <feq/section_sinuosity.hpp>
void feq_section_sinuosity(float,int,int,const float*,const float*,const int*,const float*,const int*,const float*,const float*,float,float,int,int,int,const double*,const double*,double*,double*,double*,double*,double*,double*,double*,double*,float*,float*);
#include <feq/section_extension.hpp>
extern "C" int feq_elevation_arguments(int,int*,float,float,int,float*);
extern "C" int feq_section_properties(int,int,int,const char*,float,float,float,int,int,int*,const float*,const float*,const double*,const double*,const float*,const float*,const float*,const float*,double,double,double,double,double,double,double,double,float*,float*,float*,int*,int*,float*);
extern "C" void feq_section_geometry(float,int,int,const float*,const float*,const int*,const float*,const int*,float*,float*,double*,double*,float*,float*,float*,int*,int*);
extern "C" void feq_section_flux(float,int,int,const float*,const float*,const int*,const float*,const int*,const float*,const float*,int,float,double*,double*,double*,double*,double*,double*,float*);
/* xsection.f -- translated by f2c (version 20240504).
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

/* COMMON flitems_ is declared in common.hpp. */

#define flitems_1 flitems_

/* COMMON xtadd_ is declared in common.hpp. */

#define xtadd_1 xtadd_

/* COMMON xtaddc_ is declared in common.hpp. */

#define xtaddc_1 xtaddc_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON xscomd_ is declared in common.hpp. */

#define xscomd_1 xscomd_

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON nrdzcm_ is declared in common.hpp. */

#define nrdzcm_1 nrdzcm_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON gnicom_ is declared in common.hpp. */

#define gnicom_1 gnicom_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON abslot_ is declared in common.hpp. */

#define abslot_1 abslot_

/* COMMON sincom_ is declared in common.hpp. */

#define sincom_1 sincom_

/* COMMON fldway_ is declared in common.hpp. */

#define fldway_1 fldway_

/* COMMON fldwyc_ is declared in common.hpp. */

#define fldwyc_1 fldwyc_

/* COMMON culcom_ is declared in common.hpp. */

#define culcom_1 culcom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_200 = 200;
static integer feq_gen_c_d_62 = 62;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_999 = 999;
static integer feq_gen_c_d_26 = 26;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_20 = 20;
static doublereal c_b554 = 2.;
static doublereal c_b581 = .083333333333333;
static doublereal c_b582 = 1.5;
static doublereal c_b660 = 1.666666666666666;
static doublereal c_b661 = .33333333333333;
static doublereal c_b662 = 1.3333333333333;
static doublereal c_b681 = .666667;
static integer c_n1 = -1;
static integer feq_gen_c_d_8400 = 8400;
static integer c_b1134 = 13000001;
static integer feq_gen_c_d_25 = 25;

/*     Program units for computing cross section tables, checking */
/*     cross section tables for this or that, interpolating, etc. */



/* SOURCE xsection.for:8 */
/*<       subroutineadj_invert(stdout,npnt,stat,ws_tab,dinvert,z,eflag) >*/
/* Subroutine */ int feq_gen_adj_invert_d_(integer *stdout, integer *npnt, real *stat, 
	integer *feq_gen_ws_tab_d_, real *dinvert, real *feq_gen_feq_storage_z_d_, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 Adjusting section below approximate time-o\
f-flight\002,\002 water surface\002)";
    static char fmt_52[] = "(\002 Relative change in area below water surfac\
e is about: \002,f6.2)";
    static char fmt_54[] = "(\002 *ERR:XXX* DINVERT=\002,f8.2,\002 > \002\
,\002 max. local depth=\002,f8.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real feq_gen_h_d_;
    integer feq_gen_i_d_;
    real df;
    integer il, ir, ntab;
    real hmax, zmin;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real feq_gen_ws_elev_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__4 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__11 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__15 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_54, 0 };


/*     Make adjustments to the "below-water" portion of the cross section. */
/*     Only makes sense for certain cross sections.  This only applies */
/*     in detail to the current main-channel cross sections on the */
/*     Nooksack River in Whatcom County, Washington.  However, it can be */
/*     used on any river if the pattern is followed.  3 June 2003. */
/* SOURCE xsection.for:18 */
/*<       implicitnone >*/
/* SOURCE xsection.for:20 */
/*<       integerstdout,npnt,eflag,ws_tab >*/
/* SOURCE xsection.for:21 */
/*<       realstat,dinvert,z(npnt) >*/
/*     Local */
/* SOURCE xsection.for:25 */
/*<       integeri,il,ir,ntab >*/
/* SOURCE xsection.for:26 */
/*<       realws_elev,zmin,hmax,h,df >*/
/*     ***************************formats******************************** */
/* SOURCE xsection.for:28 */
/*<    50  >*/
/* SOURCE xsection.for:30 */
/*<    52  >*/
/* SOURCE xsection.for:32 */
/*<    54 format(' *ERR:XXX* DINVERT=',f8.2,' > ',' max. local depth=',f8.2) >*/
/* *********************************************************************** */
/*     Lookup the water-surface elevation to use. */
/* SOURCE xsection.for:36 */
/*<       calllktab(ws_tab,stat,1,ws_elev,ntab,df) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    lktab_(feq_gen_ws_tab_d_, stat, &feq_gen_c_d_1, &feq_gen_ws_elev_d_, &ntab, &df);
/* SOURCE xsection.for:40 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__4.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__4);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE xsection.for:41 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__5.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__5);
    e_wsfe();
/* SOURCE xsection.for:42 */
/*<       write(stdout,*)' Time-of-flight surface elevation=',ws_elev >*/
    feq_gen_io_d__6.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__6);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Time-of-flight surface elevation="), (ftnlen)34);
    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_ws_elev_d_, (ftnlen)sizeof(real));
    e_wsle();
/*     Now search z(*) from left to right seeking the first interval */
/*     of elevation there that contains ws_elev.  The first point with */
/*     an elev below ws_elev is remembered as il. */
/* SOURCE xsection.for:48 */
/*<       il=-1 >*/
    il = -1;
/* SOURCE xsection.for:49 */
/*<       doi=2,npnt >*/
    feq_gen_i_d_1 = *npnt;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:50 */
/*<       if(ws_elev.le.z(i-1).and.ws_elev.ge.z(i))then >*/
	if (feq_gen_ws_elev_d_ <= feq_gen_z_d_[feq_gen_i_d_ - 1] && feq_gen_ws_elev_d_ >= feq_gen_z_d_[feq_gen_i_d_]) {
/* SOURCE xsection.for:51 */
/*<       il=i >*/
	    il = feq_gen_i_d_;
/* SOURCE xsection.for:52 */
/*<       goto99000 >*/
	    goto L99000;
/* SOURCE xsection.for:53 */
/*<       endif >*/
	}
/* SOURCE xsection.for:54 */
/*<       enddo >*/
    }
/* SOURCE xsection.for:54 */
/*< 99000 continue >*/
L99000:
/* SOURCE xsection.for:55 */
/*<       if(il.eq.-1)then >*/
    if (il == -1) {
/* SOURCE xsection.for:56 */
/*<       write(stdout,*)' il undefined in adj_invert' >*/
	feq_gen_io_d__9.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__9);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" il undefined in adj_invert"), (ftnlen)27);
	e_wsle();
/* SOURCE xsection.for:57 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE xsection.for:58 */
/*<       endif >*/
    }
/*     Now search z(*) from right to left finding the first point below */
/*     the water surface again. */
/* SOURCE xsection.for:63 */
/*<       ir=-1 >*/
    ir = -1;
/* SOURCE xsection.for:64 */
/*<       doi=npnt,2,-1 >*/
    for (feq_gen_i_d_ = *npnt; feq_gen_i_d_ >= 2; --feq_gen_i_d_) {
/* SOURCE xsection.for:65 */
/*<       if(ws_elev.le.z(i).and.ws_elev.ge.z(i-1))then >*/
	if (feq_gen_ws_elev_d_ <= feq_gen_z_d_[feq_gen_i_d_] && feq_gen_ws_elev_d_ >= feq_gen_z_d_[feq_gen_i_d_ - 1]) {
/* SOURCE xsection.for:66 */
/*<       ir=i-1 >*/
	    ir = feq_gen_i_d_ - 1;
/* SOURCE xsection.for:67 */
/*<       goto98998 >*/
	    goto L98998;
/* SOURCE xsection.for:68 */
/*<       endif >*/
	}
/* SOURCE xsection.for:69 */
/*<       enddo >*/
    }
/* SOURCE xsection.for:69 */
/*< 98998 continue >*/
L98998:
/* SOURCE xsection.for:70 */
/*<       if(ir.eq.-1)then >*/
    if (ir == -1) {
/* SOURCE xsection.for:71 */
/*<       write(stdout,*)' ir undefined in adj_invert' >*/
	feq_gen_io_d__11.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__11);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ir undefined in adj_invert"), (ftnlen)27);
	e_wsle();
/* SOURCE xsection.for:72 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE xsection.for:73 */
/*<       endif >*/
    }
/* SOURCE xsection.for:75 */
/*<       if(ir.le.il)then >*/
    if (ir <= il) {
/* SOURCE xsection.for:76 */
/*<       write(stdout,*)' ir <= il in adj_invert' >*/
	feq_gen_io_d__12.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__12);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ir <= il in adj_invert"), (ftnlen)23);
	e_wsle();
/* SOURCE xsection.for:77 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE xsection.for:78 */
/*<       endif >*/
    }
/*     Find the min elevation. */
/* SOURCE xsection.for:82 */
/*<       zmin=1.e30 >*/
    zmin = (float)1e30;
/* SOURCE xsection.for:83 */
/*<       doi=il,ir >*/
    feq_gen_i_d_1 = ir;
    for (feq_gen_i_d_ = il; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:84 */
/*<       zmin=min(zmin,z(i)) >*/
/* Computing MIN */
	feq_gen_r_d_1 = zmin, feq_gen_r_d_2 = feq_gen_z_d_[feq_gen_i_d_];
	zmin = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE xsection.for:85 */
/*<       enddo >*/
    }
/* SOURCE xsection.for:87 */
/*<       write(stdout,*)' il=',il,' z(il)=',z(il) >*/
    feq_gen_io_d__14.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__14);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" il="), (ftnlen)4);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&il, (ftnlen)sizeof(integer));
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" z(il)="), (ftnlen)7);
    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_z_d_[il], (ftnlen)sizeof(real));
    e_wsle();
/* SOURCE xsection.for:88 */
/*<       write(stdout,*)' ir=',ir,' z(ir)=',z(ir) >*/
    feq_gen_io_d__15.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__15);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ir="), (ftnlen)4);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ir, (ftnlen)sizeof(integer));
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" z(ir)="), (ftnlen)7);
    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_z_d_[ir], (ftnlen)sizeof(real));
    e_wsle();
/*     Define the max local depth */
/* SOURCE xsection.for:91 */
/*<       hmax=ws_elev-zmin >*/
    hmax = static_cast<double>(feq_gen_ws_elev_d_) - zmin;
/* SOURCE xsection.for:92 */
/*<       if(hmax.le.0.0)then >*/
    if (hmax <= (float)0.) {
/* SOURCE xsection.for:93 */
/*<       write(stdout,*)' hmax <= 0.0 in adj_invert' >*/
	feq_gen_io_d__17.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__17);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" hmax <= 0.0 in adj_invert"), (ftnlen)26);
	e_wsle();
/* SOURCE xsection.for:94 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE xsection.for:95 */
/*<       endif >*/
    }
/* SOURCE xsection.for:97 */
/*<       write(stdout,*)' Maximum local depth=',hmax >*/
    feq_gen_io_d__18.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__18);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Maximum local depth="), (ftnlen)21);
    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
    e_wsle();
/* SOURCE xsection.for:98 */
/*<       write(stdout,52)-dinvert/hmax >*/
    feq_gen_io_d__19.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__19);
    feq_gen_r_d_1 = static_cast<double>(-(*dinvert)) / hmax;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:100 */
/*<       if(dinvert.ge.hmax)then >*/
    if (*dinvert >= hmax) {
/* SOURCE xsection.for:101 */
/*<       write(stdout,54)dinvert,hmax >*/
	feq_gen_io_d__20.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__20);
	do_fio(&feq_gen_c_d_1, (char *)&(*dinvert), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:102 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE xsection.for:103 */
/*<       endif >*/
    }
/*     Make the adjustments. */
/* SOURCE xsection.for:106 */
/*<       doi=il,ir >*/
    feq_gen_i_d_1 = ir;
    for (feq_gen_i_d_ = il; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:107 */
/*<       h=ws_elev-z(i) >*/
	feq_gen_h_d_ = static_cast<double>(feq_gen_ws_elev_d_) - feq_gen_z_d_[feq_gen_i_d_];
/* SOURCE xsection.for:108 */
/*<       if(h.gt.0.0)then >*/
	if (feq_gen_h_d_ > (float)0.) {
/*         Only adjust the part of the cross section that is below */
/*         the estimated time of flight water level.  We allow whatever */
/*         changes take place in the line segements that penetrate the water */
/*         surface.  The typical vertical increment between boundary points */
/*         from the DTM is so small as to negate any benefit of inserting */
/*         additional points to make the water surface come out exactly. */
/*         Remember that the water surface is only a rough estimate, the */
/*         below-water cross section is even more rough so that any noise */
/*         we introduce by not interpolating to the exact water surface */
/*         is minor compared to the large uncertainty we have in the */
/*         points on the cross section itself. */
/*         The adjustment applies the relative shift at the maximum local */
/*         depth to all other positive local depths.  We then get a smooth */
/*         transition near the water surface at the time of flight.  The */
/*         below-water shape, whatever the DTM TIM makes it, is retained. */
/*         It is approximately a symmetrical triangle but the vagaries of the */
/*         TIN consruction and the pattern of points on breaklines near the */
/*         Nksk  cause there to be enough deviation from that form to make it */
/*         difficult to detect the water level at time of flight from the */
/*         pattern of points in the cross section. */
/* SOURCE xsection.for:131 */
/*<       z(i)=z(i)+dinvert*h/hmax >*/
	    feq_gen_z_d_[feq_gen_i_d_] += static_cast<double>(static_cast<double>(static_cast<double>(*dinvert) * feq_gen_h_d_) / hmax);
/* SOURCE xsection.for:132 */
/*<       endif >*/
	}
/* SOURCE xsection.for:133 */
/*<       enddo >*/
    }
/* SOURCE xsection.for:135 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:136 */
/*<       end >*/
} /* adj_invert__ */




/* SOURCE xsection.for:141 */
/*<       subroutineprocess_flname(stdout,flname,flfile) >*/
/* Subroutine */ int feq_gen_process_flname_d_(integer *stdout, char *flname, char *
	flfile, ftnlen flname_len, ftnlen flfile_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*ERR:761* Flow-line Name= \002,a,\002 not\
 found in file named:\002,a)";
    static char fmt_52[] = "(/,\002 RM_ORIGIN=\002,f10.4,\002 S_ATRMORG=\002\
,f10.1,\002 RM_FACTOR=\002,f10.1,\002 S_BEGIN=\002,f10.1)";
    static char fmt_60[] = "(f10.4,f13.2,f13.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer f_inqu(inlist *), f_open(olist *), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), do_fio(
	    integer *, char *, ftnlen), e_rsfi(), s_wsfe(cilist *), e_wsfe();
    double sqrt(doublereal);

    /* Local variables */
    extern integer feq_gen_get_unit_d_(integer *);
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    integer feq_gen_feql_index1_d_, feq_gen_feql_index2_d_;
    doublereal sum;
    char line[80];
    logical there;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    integer flunit;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__24 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, 0, 0 };


/*     Find and input information on a flow line to be used in XSINTERP */
/*     to define the Easting and Northing fields in an interpolated */
/*     cross section. */
/* SOURCE xsection.for:147 */
/*<       implicitnone >*/
/* SOURCE xsection.for:148 */
/*<       integerstdout >*/
/* SOURCE xsection.for:149 */
/*<       characterflname*6,flfile*64 >*/
/* INCLUDE xsection.for:151 */
/*     Data structures and parameters for handling assignment */
/*     of Easting and Northing values to cross section tables */
/*     interpolated by XSINTERP. */
/* SOURCE flowline.cmn:5 */
/*<       integerfl_point_max >*/
/* SOURCE flowline.cmn:7 */
/*<       parameter(fl_point_max=5000) >*/
/* SOURCE flowline.cmn:9 */
/*<       integerfl_present,fl_pnt_knt,l >*/
/* SOURCE flowline.cmn:11 */
/*<       real*8rm_origin,s_atrmorg,rm_factor,s_begin >*/
/* SOURCE flowline.cmn:13 */
/*<        >*/
/* SOURCE flowline.cmn:17 */
/*<        >*/
/*     Definitions */
/*     L - initial pointer in search. */
/*     FL_PNT_KNT - number of points on the current flow line. */
/*     RM_ORIGIN - distance along the flow line at the point */
/*                 defining the stationing to be used in FEQ. */
/*                 This is often in miles, called river miles */
/*                 but it need not be.  This is any convenient */
/*                 point that has a given or assigned value of */
/*                 stationing.  It need not be zero! */
/*     S_ATRMORG-  Distance along the flow line at RM_ORIGIN in the units used */
/*                 for the coordinate points that define the polyline */
/*                 representing the flow line. */
/*     RM_FACTOR-  number used to multiply the units used */
/*                 for RM_ORIGIN to get the units used in S_ATRMORG. */
/*                 If the stationing in FEQ is in miles and the */
/*                 coordinate points on the flow line are given in */
/*                 feet then RM_FACTOR = 5280. */
/*     S_BEGIN- initial value to use for the cumulative distance along */
/*              flow line in its coordinate units. */
/*     FL_PRESENT- 1 if a flow line is known, 0 otherwise */
/*     FL_DISTANCE(*)-distance along the flow line at each coordinate point */
/*                     on the polyline in FEQ stationing units. */
/*     FL_EASTING(*)- the x-coordinate for a flow-line point */
/*     FL_NORTHING(*)- the y-coordinate for a flow-line point */
/*     Called program units */
/* SOURCE xsection.for:154 */
/*<       integerget_unit >*/
/* SOURCE xsection.for:155 */
/*<       externalget_unit,free_unit >*/
/*     Local */
/* SOURCE xsection.for:158 */
/*<       integeri,flunit >*/
/* SOURCE xsection.for:159 */
/*<       logicalthere >*/
/* SOURCE xsection.for:160 */
/*<       real*8sum >*/
/* SOURCE xsection.for:161 */
/*<       characterline*80 >*/
/*     ******************************FORMATS***************************** */
/* SOURCE xsection.for:141 */
/*<       integer feql_index1 >*/
/* SOURCE xsection.for:141 */
/*<       integer feql_index2 >*/
/* SOURCE xsection.for:163 */
/*<    50  >*/
/* SOURCE xsection.for:165 */
/*<    52  >*/
/* *********************************************************************** */
/* SOURCE xsection.for:168 */
/*<       flunit=get_unit(0) >*/
/* L50: */
/* L52: */
    flunit = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE xsection.for:169 */
/*<       inquire(file=flfile,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 64;
    feq_gen_ioin_d_1.infile = flfile;
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
/* SOURCE xsection.for:170 */
/*<       if(there)then >*/
    if (there) {
/* SOURCE xsection.for:171 */
/*<       open(unit=flunit,file=flfile,status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = flunit;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = flfile;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE xsection.for:172 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:173 */
/*<       write(stdout,*)' FILE named:',flfile,' not found.' >*/
	feq_gen_io_d__24.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__24);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FILE named:"), (ftnlen)12);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, flfile, (ftnlen)64);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" not found."), (ftnlen)11);
	e_wsle();
/* SOURCE xsection.for:174 */
/*<       write(stdout,*)' check flow-line file (FLFILE). ' >*/
	feq_gen_io_d__25.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__25);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" check flow-line file (FLFILE). "), (ftnlen)32);
	e_wsle();
/* SOURCE xsection.for:175 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:176 */
/*<       endif >*/
    }
/* SOURCE xsection.for:178 */
/*<       dofeql_index1=1,fl_point_max >*/
    for (feq_gen_feql_index1_d_ = 1; feq_gen_feql_index1_d_ <= 5000; ++feq_gen_feql_index1_d_) {
/* SOURCE xsection.for:178 */
/*<       fl_easting(feql_index1)=0.d0 >*/
	flitems_1.feq_gen_fl_easting_d_[feq_gen_feql_index1_d_ - 1] = 0.;
/* SOURCE xsection.for:178 */
/*<       enddo >*/
    }
/* SOURCE xsection.for:179 */
/*<       dofeql_index2=1,fl_point_max >*/
    for (feq_gen_feql_index2_d_ = 1; feq_gen_feql_index2_d_ <= 5000; ++feq_gen_feql_index2_d_) {
/* SOURCE xsection.for:179 */
/*<       fl_northing(feql_index2)=0.d0 >*/
	flitems_1.feq_gen_fl_northing_d_[feq_gen_feql_index2_d_ - 1] = 0.;
/* SOURCE xsection.for:179 */
/*<       enddo >*/
    }
/*     Scan the file seeking the FLNAME starting in column 1. */
/* SOURCE xsection.for:182 */
/*<   100 continue >*/
L100:
/* SOURCE xsection.for:183 */
/*<       callinline(flunit,stdout,line) >*/
    inline_(&flunit, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:186 */
/*<       if(line(1:6).ne.'FINISH')then >*/
    if (s_cmp(line, const_cast<char*>("FINISH"), (ftnlen)6, (ftnlen)6) != 0) {
/* SOURCE xsection.for:187 */
/*<       if(line(1:6).eq.flname)then >*/
	if (s_cmp(line, flname, (ftnlen)6, (ftnlen)6) == 0) {
/*           Found the flow-line name.  Now look for */
/*           RM_ORIGIN starting in column 2 */
/* SOURCE xsection.for:190 */
/*<   200 continue >*/
L200:
/* SOURCE xsection.for:191 */
/*<       callinline(flunit,stdout,line) >*/
	    inline_(&flunit, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:194 */
/*<       if(line(2:10).eq.'RM_ORIGIN')then >*/
	    if (s_cmp(line + 1, const_cast<char*>("RM_ORIGIN"), (ftnlen)9, (ftnlen)9) == 0) {
/*               Now we can begin to read the information. */
/* SOURCE xsection.for:196 */
/*<       callinline(flunit,stdout,line) >*/
		inline_(&flunit, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:199 */
/*<        >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 80;
		feq_gen_ici_d_1.iciunit = line;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0,F10.0,F10.0, F10.0)");
		s_rsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_rm_origin_d_, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_s_atrmorg_d_, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_rm_factor_d_, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_s_begin_d_, (ftnlen)sizeof(
			doublereal));
		e_rsfi();
/* SOURCE xsection.for:201 */
/*<       write(stdout,52)rm_origin,s_atrmorg,rm_factor,s_begin >*/
		feq_gen_io_d__29.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__29);
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_rm_origin_d_, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_s_atrmorg_d_, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_rm_factor_d_, (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_s_begin_d_, (ftnlen)sizeof(
			doublereal));
		e_wsfe();
/* SOURCE xsection.for:205 */
/*<       fl_pnt_knt=1 >*/
		flitems_1.feq_gen_fl_pnt_knt_d_ = 1;
/* SOURCE xsection.for:206 */
/*<       sum=s_begin >*/
		sum = flitems_1.feq_gen_s_begin_d_;
/* SOURCE xsection.for:207 */
/*<       callinline(flunit,stdout,line) >*/
		inline_(&flunit, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:210 */
/*<        >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 80;
		feq_gen_ici_d_1.iciunit = line;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(12X,2F13.0)");
		s_rsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_fl_easting_d_[
			flitems_1.feq_gen_fl_pnt_knt_d_ - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_fl_northing_d_[
			flitems_1.feq_gen_fl_pnt_knt_d_ - 1], (ftnlen)sizeof(
			doublereal));
		e_rsfi();
/* SOURCE xsection.for:212 */
/*<       fl_distance(fl_pnt_knt)=rm_origin+(sum-s_atrmorg)/rm_factor >*/
		flitems_1.feq_gen_fl_distance_d_[flitems_1.feq_gen_fl_pnt_knt_d_ - 1] = 
			flitems_1.feq_gen_rm_origin_d_ + (sum - flitems_1.feq_gen_s_atrmorg_d_) 
			/ flitems_1.feq_gen_rm_factor_d_;
/* SOURCE xsection.for:214 */
/*<   300 continue >*/
L300:
/* SOURCE xsection.for:215 */
/*<       callinline(flunit,stdout,line) >*/
		inline_(&flunit, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:218 */
/*<       if(line(1:3).ne.'END')then >*/
		if (s_cmp(line, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) != 0) {
/* SOURCE xsection.for:219 */
/*<       fl_pnt_knt=fl_pnt_knt+1 >*/
		    ++flitems_1.feq_gen_fl_pnt_knt_d_;
/* SOURCE xsection.for:221 */
/*<        >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.iciend = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 80;
		    feq_gen_ici_d_1.iciunit = line;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(12X,2F13.0)");
		    s_rsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_fl_easting_d_[
			    flitems_1.feq_gen_fl_pnt_knt_d_ - 1], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_fl_northing_d_[
			    flitems_1.feq_gen_fl_pnt_knt_d_ - 1], (ftnlen)sizeof(
			    doublereal));
		    e_rsfi();
/* SOURCE xsection.for:224 */
/*<        >*/
/* Computing 2nd power */
		    feq_gen_d_d_1 = flitems_1.feq_gen_fl_easting_d_[flitems_1.feq_gen_fl_pnt_knt_d_ - 1] 
			    - flitems_1.feq_gen_fl_easting_d_[flitems_1.feq_gen_fl_pnt_knt_d_ - 
			    2];
/* Computing 2nd power */
		    feq_gen_d_d_2 = flitems_1.feq_gen_fl_northing_d_[flitems_1.feq_gen_fl_pnt_knt_d_ - 1]
			     - flitems_1.feq_gen_fl_northing_d_[flitems_1.feq_gen_fl_pnt_knt_d_ 
			    - 2];
		    sum += sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE xsection.for:228 */
/*<       fl_distance(fl_pnt_knt)=rm_origin+(sum-s_atrmorg)/rm_factor >*/
		    flitems_1.feq_gen_fl_distance_d_[flitems_1.feq_gen_fl_pnt_knt_d_ - 1] = 
			    flitems_1.feq_gen_rm_origin_d_ + (sum - 
			    flitems_1.feq_gen_s_atrmorg_d_) / flitems_1.feq_gen_rm_factor_d_;
/* SOURCE xsection.for:230 */
/*<       goto300 >*/
		    goto L300;
/* SOURCE xsection.for:231 */
/*<       else >*/
		} else {
/* SOURCE xsection.for:232 */
/*<       goto400 >*/
		    goto L400;
/* SOURCE xsection.for:233 */
/*<       endif >*/
		}
/* SOURCE xsection.for:234 */
/*<       else >*/
	    } else {
/* SOURCE xsection.for:235 */
/*<       goto200 >*/
		goto L200;
/* SOURCE xsection.for:236 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:237 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:238 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE xsection.for:239 */
/*<       endif >*/
	}
/* SOURCE xsection.for:240 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:241 */
/*<       write(stdout,50)flname,flfile >*/
	feq_gen_io_d__31.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__31);
	do_fio(&feq_gen_c_d_1, flname, (ftnlen)6);
	do_fio(&feq_gen_c_d_1, flfile, (ftnlen)64);
	e_wsfe();
/* SOURCE xsection.for:242 */
/*<       stop'Abnormal stop,  Error found.' >*/
	s_stop(const_cast<char*>("Abnormal stop,  Error found."), (ftnlen)28);
/* SOURCE xsection.for:243 */
/*<       endif >*/
    }
/* SOURCE xsection.for:245 */
/*<   400 continue >*/
L400:
/* SOURCE xsection.for:248 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__32.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__32);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE xsection.for:249 */
/*<       write(stdout,*)'Debug dump for x,y location' >*/
    feq_gen_io_d__33.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__33);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("Debug dump for x,y location"), (ftnlen)27);
    e_wsle();
/* SOURCE xsection.for:250 */
/*<       do500i=1,fl_pnt_knt >*/
    feq_gen_i_d_1 = flitems_1.feq_gen_fl_pnt_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:251 */
/*<       write(stdout,60)fl_distance(i),fl_easting(i),fl_northing(i) >*/
	feq_gen_io_d__35.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__35);
	do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_fl_distance_d_[feq_gen_i_d_ - 1], (ftnlen)
		sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_fl_easting_d_[feq_gen_i_d_ - 1], (ftnlen)
		sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&flitems_1.feq_gen_fl_northing_d_[feq_gen_i_d_ - 1], (ftnlen)
		sizeof(doublereal));
	e_wsfe();
/* SOURCE xsection.for:252 */
/*<    60 format(f10.4,f13.2,f13.2) >*/
/* SOURCE xsection.for:253 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE xsection.for:254 */
/*<       callfree_unit(stdout,flunit) >*/
    feq_gen_free_unit_d_(stdout, &flunit);
/* SOURCE xsection.for:255 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__36.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__36);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE xsection.for:257 */
/*<       fl_present=1 >*/
    flitems_1.feq_gen_fl_present_d_ = 1;
/* SOURCE xsection.for:259 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:260 */
/*<       end >*/
} /* process_flname__ */

/*     *********** */
/*     *         * */
/*     * CHK_FOR_GIVEN_TYPE */
/*     *         * */
/*     *********** */
/* SOURCE xsection.for:270 */
/*<       subroutinechk_for_given_type(is,ie,type_values,type,eflag) >*/
/* Subroutine */ int feq_gen_chk_for_given_type_d_(integer *is, integer *ie, integer *
	feq_gen_feq_storage_type_values_d_, integer *feq_gen_type_d_, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;

/*     Check that all types at and between indices IS and IE in the */
/*     TYPE_VAULES(*) match TYPE. */
/* SOURCE xsection.for:276 */
/*<       implicitnone >*/
/* SOURCE xsection.for:277 */
/*<       integeris,ie,type_values(ie),type,eflag >*/
/*     Local */
/* SOURCE xsection.for:281 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE xsection.for:283 */
/*<       do100i=is,ie >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_type_values_d_(feq_gen_feq_storage_type_values_d_, 1);

    /* Function Body */
    feq_gen_i_d_1 = *ie;
    for (feq_gen_i_d_ = *is; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:284 */
/*<       if(type_values(i).ne.type)then >*/
	if (feq_gen_type_values_d_[feq_gen_i_d_] != *feq_gen_type_d_) {
/* SOURCE xsection.for:285 */
/*<       eflag=eflag+1 >*/
	    ++(*eflag);
/* SOURCE xsection.for:286 */
/*<       endif >*/
	}
/* SOURCE xsection.for:287 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE xsection.for:288 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:289 */
/*<       end >*/
} /* chk_for_given_type__ */

/*     *********** */
/*     *         * */
/*     * GET_XSEC_HEADER */
/*     *         * */
/*     *********** */
/* SOURCE xsection.for:298 */
/*<        >*/
/* Subroutine */ int feq_gen_get_xsec_header_d_(integer *stdin, integer *stdout, 
	integer *eflag, integer *tab, char *savopt, char *outopt, char *
	monton, char *betopt, integer *extend, real *stat, real *left, real *
	right, char *varn, integer *navm, real *scale, real *shift, real *
	vscale, real *hshift, integer *nsub, real *feq_storage_n, char *zone, char *hgrid,
	 char *vdatum, char *unitsys, char *basis, ftnlen savopt_len, ftnlen 
	outopt_len, ftnlen monton_len, ftnlen betopt_len, ftnlen varn_len, 
	ftnlen zone_len, ftnlen hgrid_len, ftnlen vdatum_len, ftnlen 
	unitsys_len, ftnlen basis_len)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*62+1] = "EXTEND          MONOTONE        N\
EWBETA         NEWBETAE        NEWBETAM        NOEXTEND        NOOUT        \
   NOSAVE          OLDBETA         OUT1            OUT12           OUT20    \
       OUT21           OUT22           OUT23           OUT24           OUT25\
           SAVE            SAVE1           SAVE12          SAVE20          S\
AVE21          SAVE22          SAVE23          SAVE24          SAVE25       \
   TABLE           STATION         LEFT            RIGHT           VARN     \
       NAVM            SCALE           SHIFT           VSCALE          HSHIF\
T          NSUB            GISID           GIS             EASTING         N\
ORTHING        TABID           NEWBETAX        OUT30           OUT31        \
   OUT32           OUT33           OUT34           OUT35           SAVE30   \
       SAVE31          SAVE32          SAVE33          SAVE34          SAVE3\
5          DINVERT         WS_TABID        ZONE            HGRID           V\
DATUM          UNITSYS         BASIS           ";
    static integer feq_gen_symbol_value_d_[62] = { 6,5,4,4,4,7,3,1,4,3,3,3,3,3,3,3,3,2,
	    1,1,1,1,1,1,1,1,8,9,10,11,12,13,14,15,16,17,18,19,19,20,21,8,4,3,
	    3,3,3,3,3,1,1,1,1,1,1,22,23,24,25,26,27,28 };
    static integer feq_gen_response_type_d_[62] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,4,2,2,2,4,1,2,2,2,2,-1,4,4,3,3,4,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,2,4,4,4,4,4,4 };
    static integer feq_gen_convert_rule_d_[62] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,1,1,1,1,1,1,1 };
    static doublereal dnull = -3.3e7;

    /* Format strings */
    static char fmt_52[] = "(/,\002 *BUG:XXX* Invalid index=\002,i5,\002 for\
 name=\002,a,\002 in\002,\002 subroutine GET_XSEC_HEADER.\002)";
    static char fmt_54[] = "(/,\002 *ERR:734* Name=\002,a8,\002 is unknown i\
n a cross section\002,\002 description.\002)";
    static char fmt_56[] = "(/,\002 Unable to continue due to previous error\
s.\002)";
    static char fmt_60[] = "(/,\002 Processing:\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_item_knt_d_, feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_chk_and_convert_response_d_(integer *, integer 
	    *, char *, integer *, integer *, integer *, integer *, char *, 
	    integer *, integer *, integer *, real *, doublereal *, ftnlen, 
	    ftnlen), feq_gen_get_multiple_real_values_d_(integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, real *, doublereal *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, integer *, real *, 
	    ftnlen, ftnlen, ftnlen);
    integer selection, feq_gen_item_type_d_[200], ip, it;
    char key[16];
    integer opt, clen[200];
    char cval[256*200], line[120];
    integer ival[200];
    real rval[200];
    char term[1*200];
    doublereal dpval[200];
    integer terml[200];
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    integer eflag2;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     getval_(integer *, char *, integer *, integer *, integer *, 
	    integer *, real *, doublereal *, char *, integer *, integer *, 
	    char *, integer *, integer *, integer *, ftnlen, ftnlen, ftnlen);
    extern integer lenstr_(char *, ftnlen);
    integer termcls[200];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_52, 0 };


/* SOURCE xsection.for:305 */
/*<       implicitnone >*/
/*     Get the header information for the FEQX and FEQXEXT */
/*     commands for processing cross sections. */
/* INCLUDE xsection.for:309 */
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
/* SOURCE xsection.for:311 */
/*<       integerstdin,stdout,eflag,tab,extend,nsub,navm >*/
/* SOURCE xsection.for:313 */
/*<       realstat,left,right,scale,shift,vscale,hshift,n(pmxsub) >*/
/* SOURCE xsection.for:316 */
/*<        >*/
/* INCLUDE xsection.for:321 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE xsection.for:326 */
/*<        >*/
/* SOURCE xsection.for:329 */
/*<        >*/
/* SOURCE xsection.for:333 */
/*<       integereflag2,i,is,ie,it,j,knt,opt,ip,selection,item_knt >*/
/* SOURCE xsection.for:335 */
/*<        >*/
/* SOURCE xsection.for:337 */
/*<       realrval(nval) >*/
/* SOURCE xsection.for:338 */
/*<       real*8dpval(nval),dnull >*/
/* SOURCE xsection.for:339 */
/*<       charactercval(nval)*256,term(nval)*1,line*120,key*16 >*/
/* SOURCE xsection.for:342 */
/*<       integerlenstr >*/
/* SOURCE xsection.for:344 */
/*<       externallenstr,get_multiple_real_values,get_internal_tab_number >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE xsection.for:348 */
/*<        >*/
/* SOURCE xsection.for:350 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE xsection.for:352 */
/*<       savesymbol_value,symbol_table >*/
/*     *****************************FORMATS****************************** */
/* SOURCE xsection.for:355 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> n(feq_storage_n, 1);

    /* Function Body */
/* SOURCE xsection.for:370 */
/*<        >*/
/* SOURCE xsection.for:385 */
/*<        >*/
/* SOURCE xsection.for:390 */
/*<        >*/
/* SOURCE xsection.for:394 */
/*<       datadnull/-33d6/ >*/
/* SOURCE xsection.for:396 */
/*<    52  >*/
/* L52: */
/* SOURCE xsection.for:398 */
/*<    54  >*/
/* L54: */
/* SOURCE xsection.for:400 */
/*<    56 format(/,' Unable to continue due to previous errors.') >*/
/* L56: */
/* SOURCE xsection.for:401 */
/*<    58 format(' *ERR:504* Number of subsections=',i5,' > ',i5) >*/
/* L58: */
/* SOURCE xsection.for:402 */
/*<    60 format(/,' Processing:',a) >*/
/* L60: */
/* SOURCE xsection.for:403 */
/*<    62 format(/,' Seeking additional roughness values.') >*/
/* L62: */
/* *********************************************************************** */
/*     Clear the local error flag for subroutine GETVAL and GET_MULTIPLE */
/*     _REAL_VALUES */
/* SOURCE xsection.for:407 */
/*<       eflag2=0 >*/
    eflag2 = 0;
/*     Read lines of input and process each one until the expected number */
/*     of lines or an end of header signal is found. */
/*     SET DEFAULTS */
/* SOURCE xsection.for:414 */
/*<       savopt='NOSAVE' >*/
    s_copy(savopt, const_cast<char*>("NOSAVE"), (ftnlen)8, (ftnlen)6);
/* SOURCE xsection.for:415 */
/*<       outopt='OUT21' >*/
    s_copy(outopt, const_cast<char*>("OUT21"), (ftnlen)8, (ftnlen)5);
/* SOURCE xsection.for:416 */
/*<       monton=' ' >*/
    s_copy(monton, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE xsection.for:417 */
/*<       betopt='OLDBETA' >*/
    s_copy(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7);
/* SOURCE xsection.for:418 */
/*<       left=1.e30 >*/
    *left = (float)1e30;
/* SOURCE xsection.for:419 */
/*<       right=-1.e30 >*/
    *right = (float)-1e30;
/* SOURCE xsection.for:420 */
/*<       scale=1.0 >*/
    *scale = (float)1.;
/* SOURCE xsection.for:421 */
/*<       vscale=1.0 >*/
    *vscale = (float)1.;
/* SOURCE xsection.for:422 */
/*<       shift=0.0 >*/
    *shift = (float)0.;
/* SOURCE xsection.for:423 */
/*<       hshift=0.0 >*/
    *hshift = (float)0.;
/* SOURCE xsection.for:424 */
/*<       navm=0 >*/
    *navm = 0;
/* SOURCE xsection.for:425 */
/*<       varn='NCON' >*/
    s_copy(varn, const_cast<char*>("NCON"), (ftnlen)4, (ftnlen)4);
/* SOURCE xsection.for:426 */
/*<       stat=0.0 >*/
    *stat = (float)0.;
/* SOURCE xsection.for:427 */
/*<       gisid=' ' >*/
    s_copy(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE xsection.for:428 */
/*<       tabid=' ' >*/
    s_copy(xtaddc_1.tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE xsection.for:429 */
/*<       tab=0 >*/
    *tab = 0;
/* SOURCE xsection.for:430 */
/*<       easting=dnull >*/
    xtadd_1.easting = dnull;
/* SOURCE xsection.for:431 */
/*<       northing=dnull >*/
    xtadd_1.northing = dnull;
/* SOURCE xsection.for:433 */
/*<       dinvert=0.0 >*/
    xtadd_1.dinvert = (float)0.;
/* SOURCE xsection.for:434 */
/*<       ws_tabid=' ' >*/
    s_copy(xtaddc_1.feq_gen_ws_tabid_d_, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE xsection.for:435 */
/*<       zone='NONE' >*/
    s_copy(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE xsection.for:436 */
/*<       hgrid='NONE' >*/
    s_copy(hgrid, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE xsection.for:437 */
/*<       vdatum='NONE' >*/
    s_copy(vdatum, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE xsection.for:438 */
/*<       unitsys='NONE' >*/
    s_copy(unitsys, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE xsection.for:439 */
/*<       basis='NONE' >*/
    s_copy(basis, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/*     Select option for GETVAL to return BOTH the string value */
/*     and the converted value for numeric responses. */
/*     In some cases the value will be recomputed. */
/* SOURCE xsection.for:444 */
/*<       opt=2 >*/
    opt = 2;
/*     Start a loop over input lines */
/* SOURCE xsection.for:446 */
/*<   100 continue >*/
L100:
/* SOURCE xsection.for:449 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE xsection.for:453 */
/*<       it=lenstr(line) >*/
    it = lenstr_(line, (ftnlen)120);
/* SOURCE xsection.for:454 */
/*<       write(stdout,60)line(1:it) >*/
    feq_gen_io_d__47.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__47);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE xsection.for:456 */
/*<       line(it+1:it+1)='''' >*/
    feq_gen_i_d_1 = it;
    s_copy(line + feq_gen_i_d_1, const_cast<char*>("'"), it + 1 - feq_gen_i_d_1, (ftnlen)1);
/* SOURCE xsection.for:458 */
/*<        >*/
    getval_(stdout, line, &feq_gen_c_d_200, &opt, feq_gen_item_type_d_, ival, rval, dpval, cval,
	     clen, &eflag2, term, terml, termcls, &feq_gen_item_knt_d_, (ftnlen)120, (
	    ftnlen)256, (ftnlen)1);
/*      WRITE(STDOUT,*) */
/*     A  ' Return from GETVAL in GET_XSEC_HEADER: ITEM_KNT=',ITEM_KNT */
/*      WRITE(STDOUT,97) */
/* 97    FORMAT(1X,12X,'ITEM','   LEN  TYPE T  TCLS') */
/*      DO 9213 I=1,ITEM_KNT */
/*        WRITE(STDOUT,99) CVAL(I), CLEN(I), ITEM_TYPE(I), TERM(I), */
/*     A                  TERMCLS(I) */
/* 99    FORMAT(' ',A16,' ',I5,' ',I5,' ',A1,' ',I5) */
/* 9213  CONTINUE */
/* SOURCE xsection.for:473 */
/*<       if(eflag2.ne.0)then >*/
    if (eflag2 != 0) {
/*         Error in parsing the line of input. */
/* SOURCE xsection.for:476 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__58.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__58);
	e_wsfe();
/* SOURCE xsection.for:477 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE xsection.for:478 */
/*<       else >*/
    } else {
/*         No errors reported.  Process the items found on the current */
/*         line. */
/* SOURCE xsection.for:482 */
/*<        >*/
	feq_gen_chk_and_convert_response_d_(stdout, &feq_gen_c_d_62, feq_gen_symbol_table_d_, 
		feq_gen_response_type_d_, feq_gen_convert_rule_d_, &feq_gen_item_knt_d_, feq_gen_item_type_d_, 
		cval, clen, eflag, ival, rval, dpval, (ftnlen)16, (ftnlen)256)
		;
/* SOURCE xsection.for:488 */
/*<       i=1 >*/
	feq_gen_i_d_ = 1;
/* SOURCE xsection.for:489 */
/*<   110 continue >*/
L110:
/*           Find the value for the next item from the */
/*           symbol table. */
/* SOURCE xsection.for:492 */
/*<       key=cval(i)(1:clen(i)) >*/
	s_copy(key, cval + (feq_gen_i_d_ - 1 << 8), (ftnlen)16, clen[feq_gen_i_d_ - 1]);
/* SOURCE xsection.for:493 */
/*<       calllstab(key,symbol_table,n_symbol,ip) >*/
	lstab_(key, feq_gen_symbol_table_d_, &feq_gen_c_d_62, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE xsection.for:496 */
/*<       if(ip.eq.0)then >*/
	if (ip == 0) {
/*             error-symbol not found */
/* SOURCE xsection.for:498 */
/*<       write(stdout,54)key >*/
	    feq_gen_io_d__62.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__62);
	    do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	    e_wsfe();
/* SOURCE xsection.for:499 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:501 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:502 */
/*<       selection=symbol_value(ip) >*/
	    selection = feq_gen_symbol_value_d_[ip - 1];
/* SOURCE xsection.for:503 */
/*<       endif >*/
	}
/* SOURCE xsection.for:505 */
/*<        >*/
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
	    case 12:  goto L12;
	    case 13:  goto L13;
	    case 14:  goto L14;
	    case 15:  goto L15;
	    case 16:  goto L16;
	    case 17:  goto L17;
	    case 18:  goto L18;
	    case 19:  goto L19;
	    case 20:  goto L20;
	    case 21:  goto L21;
	    case 22:  goto L22;
	    case 23:  goto L23;
	    case 24:  goto L24;
	    case 25:  goto L25;
	    case 26:  goto L26;
	    case 27:  goto L27;
	    case 28:  goto L28;
	}
/* SOURCE xsection.for:509 */
/*<       write(stdout,52)i,key >*/
	feq_gen_io_d__64.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__64);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, key, (ftnlen)16);
	e_wsfe();
/* SOURCE xsection.for:510 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:512 */
/*<     1 continue >*/
L1:
/*             MOST OF THE SAVE OPTIONS. */
/* SOURCE xsection.for:514 */
/*<       savopt=key >*/
	s_copy(savopt, key, (ftnlen)8, (ftnlen)16);
/* SOURCE xsection.for:515 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE xsection.for:516 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:517 */
/*<     2 continue >*/
L2:
/*             SAVE BY ITSELF WITHOUT A SUFFIX NUMBER */
/* SOURCE xsection.for:519 */
/*<       savopt='SAVE21' >*/
	s_copy(savopt, const_cast<char*>("SAVE21"), (ftnlen)8, (ftnlen)6);
/* SOURCE xsection.for:520 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE xsection.for:521 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:522 */
/*<     3 continue >*/
L3:
/*             OUTPUT OPTIONS */
/* SOURCE xsection.for:524 */
/*<       outopt=key >*/
	s_copy(outopt, key, (ftnlen)8, (ftnlen)16);
/* SOURCE xsection.for:525 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE xsection.for:526 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:527 */
/*<     4 continue >*/
L4:
/*             VELOCITY COEFFICIENT FLAGS */
/* SOURCE xsection.for:529 */
/*<       betopt=key >*/
	s_copy(betopt, key, (ftnlen)8, (ftnlen)16);
/* SOURCE xsection.for:530 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE xsection.for:531 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:532 */
/*<     5 continue >*/
L5:
/*             MONOTONICITY FLAG */
/* SOURCE xsection.for:534 */
/*<       monton=key >*/
	s_copy(monton, key, (ftnlen)8, (ftnlen)16);
/* SOURCE xsection.for:535 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE xsection.for:536 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:537 */
/*<     6 continue >*/
L6:
/*             SET EXTEND OPTION */
/* SOURCE xsection.for:539 */
/*<       extend=1 >*/
	*extend = 1;
/* SOURCE xsection.for:540 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE xsection.for:541 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:542 */
/*<     7 continue >*/
L7:
/*             CLEAR THE EXTEND OPTION */
/* SOURCE xsection.for:544 */
/*<       extend=0 >*/
	*extend = 0;
/* SOURCE xsection.for:545 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE xsection.for:546 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:547 */
/*<     8 continue >*/
L8:
/*             Set the value for the TABLE id. */
/* SOURCE xsection.for:549 */
/*<       tabid=cval(i+1)(1:clen(i+1)) >*/
	s_copy(xtaddc_1.tabid, cval + (feq_gen_i_d_ << 8), (ftnlen)16, clen[feq_gen_i_d_]);
/* SOURCE xsection.for:550 */
/*<       callget_internal_tab_number(stdout,tabid,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, xtaddc_1.tabid, eflag, tab, (ftnlen)
		16);
/* SOURCE xsection.for:555 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:556 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:557 */
/*<     9 continue >*/
L9:
/* SOURCE xsection.for:558 */
/*<       stat=rval(i+1) >*/
	*stat = rval[feq_gen_i_d_];
/* SOURCE xsection.for:559 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:560 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:561 */
/*<    10 continue >*/
L10:
/* SOURCE xsection.for:562 */
/*<       left=rval(i+1) >*/
	*left = rval[feq_gen_i_d_];
/* SOURCE xsection.for:563 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:564 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:565 */
/*<    11 continue >*/
L11:
/* SOURCE xsection.for:566 */
/*<       right=rval(i+1) >*/
	*right = rval[feq_gen_i_d_];
/* SOURCE xsection.for:567 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:568 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:569 */
/*<    12 continue >*/
L12:
/* SOURCE xsection.for:570 */
/*<       varn=cval(i+1)(1:clen(i)) >*/
	s_copy(varn, cval + (feq_gen_i_d_ << 8), (ftnlen)4, clen[feq_gen_i_d_ - 1]);
/* SOURCE xsection.for:571 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:572 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:573 */
/*<    13 continue >*/
L13:
/* SOURCE xsection.for:574 */
/*<       navm=ival(i+1) >*/
	*navm = ival[feq_gen_i_d_];
/* SOURCE xsection.for:575 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:576 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:577 */
/*<    14 continue >*/
L14:
/* SOURCE xsection.for:578 */
/*<       scale=rval(i+1) >*/
	*scale = rval[feq_gen_i_d_];
/* SOURCE xsection.for:579 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:580 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:581 */
/*<    15 continue >*/
L15:
/* SOURCE xsection.for:582 */
/*<       shift=rval(i+1) >*/
	*shift = rval[feq_gen_i_d_];
/* SOURCE xsection.for:583 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:584 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:585 */
/*<    16 continue >*/
L16:
/* SOURCE xsection.for:586 */
/*<       vscale=rval(i+1) >*/
	*vscale = rval[feq_gen_i_d_];
/* SOURCE xsection.for:587 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:588 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:589 */
/*<    17 continue >*/
L17:
/* SOURCE xsection.for:590 */
/*<       hshift=rval(i+1) >*/
	*hshift = rval[feq_gen_i_d_];
/* SOURCE xsection.for:591 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:592 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:593 */
/*<    18 continue >*/
L18:
/*             Process the number of subsections and the values of Manning's */
/*             n for each.  NSUB must be the last entry in the header. */
/*             There are two options: the number of subsections is given */
/*             or the number of subsections is omitted.  When the number of */
/*             subsections is omitted, the continuation signal must be given */
/*             for all lines required for the roughness values but for the */
/*             last. */
/* SOURCE xsection.for:602 */
/*<        >*/
	feq_gen_get_multiple_real_values_d_(stdin, stdout, &feq_gen_c_d_1, &feq_gen_c_d_2, &feq_gen_c_d_5, &opt, &
		feq_gen_c_d_200, line, feq_gen_item_type_d_, ival, rval, dpval, cval, clen, &
		eflag2, term, terml, termcls, &feq_gen_item_knt_d_, nsub, &n[1], (
		ftnlen)120, (ftnlen)256, (ftnlen)1);
/* SOURCE xsection.for:609 */
/*<       goto200 >*/
	goto L200;
/* SOURCE xsection.for:610 */
/*<    19 continue >*/
L19:
/* SOURCE xsection.for:611 */
/*<       gisid=cval(i+1)(1:clen(i+1)) >*/
	s_copy(xtaddc_1.gisid, cval + (feq_gen_i_d_ << 8), (ftnlen)16, clen[feq_gen_i_d_]);
/* SOURCE xsection.for:612 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:613 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:614 */
/*<    20 continue >*/
L20:
/* SOURCE xsection.for:615 */
/*<       easting=dpval(i+1) >*/
	xtadd_1.easting = dpval[feq_gen_i_d_];
/* SOURCE xsection.for:616 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:617 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:618 */
/*<    21 continue >*/
L21:
/* SOURCE xsection.for:619 */
/*<       northing=dpval(i+1) >*/
	xtadd_1.northing = dpval[feq_gen_i_d_];
/* SOURCE xsection.for:620 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:621 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:622 */
/*<    22 continue >*/
L22:
/* SOURCE xsection.for:623 */
/*<       dinvert=rval(i+1) >*/
	xtadd_1.dinvert = rval[feq_gen_i_d_];
/* SOURCE xsection.for:624 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:625 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:626 */
/*<    23 continue >*/
L23:
/* SOURCE xsection.for:627 */
/*<       ws_tabid=cval(i+1)(1:clen(i+1)) >*/
	s_copy(xtaddc_1.feq_gen_ws_tabid_d_, cval + (feq_gen_i_d_ << 8), (ftnlen)16, clen[feq_gen_i_d_]);
/* SOURCE xsection.for:628 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:629 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:630 */
/*<    24 continue >*/
L24:
/* SOURCE xsection.for:631 */
/*<       zone=cval(i+1)(1:clen(i+1)) >*/
	s_copy(zone, cval + (feq_gen_i_d_ << 8), (ftnlen)8, clen[feq_gen_i_d_]);
/* SOURCE xsection.for:632 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:633 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:634 */
/*<    25 continue >*/
L25:
/* SOURCE xsection.for:635 */
/*<       hgrid=cval(i+1)(1:clen(i+1)) >*/
	s_copy(hgrid, cval + (feq_gen_i_d_ << 8), (ftnlen)8, clen[feq_gen_i_d_]);
/* SOURCE xsection.for:636 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:637 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:638 */
/*<    26 continue >*/
L26:
/* SOURCE xsection.for:639 */
/*<       vdatum=cval(i+1)(1:clen(i+1)) >*/
	s_copy(vdatum, cval + (feq_gen_i_d_ << 8), (ftnlen)8, clen[feq_gen_i_d_]);
/* SOURCE xsection.for:640 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:641 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:642 */
/*<    27 continue >*/
L27:
/* SOURCE xsection.for:643 */
/*<       unitsys=cval(i+1)(1:clen(i+1)) >*/
	s_copy(unitsys, cval + (feq_gen_i_d_ << 8), (ftnlen)8, clen[feq_gen_i_d_]);
/* SOURCE xsection.for:644 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:645 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:646 */
/*<    28 continue >*/
L28:
/* SOURCE xsection.for:647 */
/*<       basis=cval(i+1)(1:clen(i+1)) >*/
	s_copy(basis, cval + (feq_gen_i_d_ << 8), (ftnlen)8, clen[feq_gen_i_d_]);
/* SOURCE xsection.for:648 */
/*<       i=i+2 >*/
	feq_gen_i_d_ += 2;
/* SOURCE xsection.for:649 */
/*<       goto149 >*/
	goto L149;
/* SOURCE xsection.for:651 */
/*<   149 continue >*/
L149:
/* SOURCE xsection.for:652 */
/*<       if(i.gt.item_knt)then >*/
	if (feq_gen_i_d_ > feq_gen_item_knt_d_) {
/*               Get the next line from the input */
/* SOURCE xsection.for:654 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE xsection.for:655 */
/*<       else >*/
	} else {
/*               Get the next item from the current line */
/* SOURCE xsection.for:657 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE xsection.for:658 */
/*<       endif >*/
	}
/* SOURCE xsection.for:659 */
/*<       endif >*/
    }
/* SOURCE xsection.for:661 */
/*<   200 continue >*/
L200:
/* SOURCE xsection.for:662 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:663 */
/*<       end >*/
} /* get_xsec_header__ */




/* SOURCE xsection.for:668 */
/*<       subroutineextrap(type,xoff,mlft,eflag,ext,ftp) >*/
/* Subroutine */ int extrap_(integer *feq_gen_type_d_, integer *xoff, integer *mlft, 
	integer *eflag, real *ext, integer *ftp)
{
    /* Initialized data */

    static integer jid[25] = { 1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,
	    1,1 };
    static integer qcid[25] = { 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,
	    0,1 };

    /* Format strings */
    static char fmt_1[] = "(/,\002 *WRN:01* EXTRAPOLATION NOT DONE. TOP WI\
DTH\002,\002 < 0. EXT = \002,f10.2)";
    static char fmt_50[] = "(/,\002  *WRN:571 Extrapolation not done.\002\
,\002  Section is slotted.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real a2, a3, b2, b3, t2, t3, y2, y3, da, db, dt;
    integer it;
    real dy, ma2, ma3, kh2, kh3, qc2, qc3, yb2, yb3, mq2, mq3, dma, dkh, dqc;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    real dmq, alp2, alp3, dbda;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real dalp;
    integer ioff;
    real dtdy;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real dmada, dkhda, dqcda, dmqda, daext, dalpda, mxslot;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_1, 0 };


/*     + + + PURPOSE + + + */
/*     Extend a cross-section table by extrapolation */
/*     PARAMTERS */
/* SOURCE xsection.for:677 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:680 */
/*<       integereflag,ftp,mlft,type,xoff >*/
/* SOURCE xsection.for:681 */
/*<       realext >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TYPE   - Table type */
/*     XOFF   - Offset between successive depth values for cross section */
/*               function table */
/*     MLFT   - maximum length of FTAB/ITAB */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     EXT    - extent and nature of extrapolation of the table */
/*     FTP    - next open location in the function table storage */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:693 */
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
/* INCLUDE xsection.for:694 */
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
/* INCLUDE xsection.for:695 */
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
/* INCLUDE xsection.for:696 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE xsection.for:699 */
/*<       integerjid(25),qcid(25) >*/
/* SOURCE xsection.for:700 */
/*<       savejid,qcid >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:703 */
/*<       integerioff,it >*/
/* SOURCE xsection.for:704 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE xsection.for:710 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:713 */
/*<       externalkil >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:716 */
/*<       datajid/1,10*0,1,8*0,1,1,0,1,1/ >*/
/* SOURCE xsection.for:717 */
/*<       dataqcid/11*0,1,9*0,1,0,0,1/ >*/
/* SOURCE xsection.for:720 */
/*<     1  >*/
/* L1: */
/* SOURCE xsection.for:722 */
/*<    50  >*/
/* L50: */
/* *********************************************************************** */
/* SOURCE xsection.for:725 */
/*<       if(grav.gt.15.0)then >*/
    if (grvcom_1.grav > (float)15.) {
/* SOURCE xsection.for:726 */
/*<       mxslot=0.07 >*/
	mxslot = (float).07;
/* SOURCE xsection.for:727 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:728 */
/*<       mxslot=0.02134 >*/
	mxslot = (float).02134;
/* SOURCE xsection.for:729 */
/*<       endif >*/
    }
/*     ON ENTRY FTP POINTS TO THE NEXT OPEN LOCATION IN */
/*     (FTAB,ITAB).  ON EXIT FTP SHOULD POINT TO THE NEW */
/*     NEXT OPEN LOCATION IN (FTAB,ITAB). */
/*     DO THE VALUES THAT ARE COMMON TO ALL OF THE 14 TABLE TYPES. */
/*     THEN BRANCH TO SPECIAL SECTIONS TO FINISH TABLES THAT */
/*     HAVE MORE TABULATED VALUES IN THEM THAN THE BARE MINIMUM */
/*     GET THE LAST LEVEL IN THE TABLE JUST ADDED TO FTAB/ITAB */
/* SOURCE xsection.for:740 */
/*<       y2=ftab(ftp-xoff) >*/
    y2 = ftab[*ftp - *xoff];
/* SOURCE xsection.for:741 */
/*<       t2=ftab(ftp-xoff+1) >*/
    t2 = ftab[*ftp - *xoff + 1];
/* SOURCE xsection.for:742 */
/*<       a2=ftab(ftp-xoff+2) >*/
    a2 = ftab[*ftp - *xoff + 2];
/* SOURCE xsection.for:743 */
/*<       kh2=ftab(ftp-xoff+3) >*/
    kh2 = ftab[*ftp - *xoff + 3];
/* SOURCE xsection.for:744 */
/*<       b2=ftab(ftp-xoff+4) >*/
    b2 = ftab[*ftp - *xoff + 4];
/*     Do not do extrapolation on slotted cross section tables. */
/* SOURCE xsection.for:747 */
/*<       if(t2.lt.mxslot)then >*/
    if (t2 < mxslot) {
/* SOURCE xsection.for:748 */
/*<       write(std6,50) >*/
	feq_gen_io_d__76.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__76);
	e_wsfe();
/* SOURCE xsection.for:749 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:750 */
/*<       endif >*/
    }
/*     COMPUTE THE RATE OF CHANGE OF T, KH AND B */
/* SOURCE xsection.for:753 */
/*<       ioff=2*xoff >*/
    ioff = *xoff << 1;
/* SOURCE xsection.for:754 */
/*<       dy=y2-ftab(ftp-ioff) >*/
    dy = static_cast<double>(y2) - ftab[*ftp - ioff];
/* SOURCE xsection.for:755 */
/*<       dt=t2-ftab(ftp-ioff+1) >*/
    dt = static_cast<double>(t2) - ftab[*ftp - ioff + 1];
/* SOURCE xsection.for:756 */
/*<       da=a2-ftab(ftp-ioff+2) >*/
    da = static_cast<double>(a2) - ftab[*ftp - ioff + 2];
/* SOURCE xsection.for:757 */
/*<       dkh=kh2-ftab(ftp-ioff+3) >*/
    dkh = static_cast<double>(kh2) - ftab[*ftp - ioff + 3];
/* SOURCE xsection.for:758 */
/*<       db=b2-ftab(ftp-ioff+4) >*/
    db = static_cast<double>(b2) - ftab[*ftp - ioff + 4];
/* SOURCE xsection.for:759 */
/*<       dtdy=dt/dy >*/
    dtdy = static_cast<double>(dt) / dy;
/* SOURCE xsection.for:760 */
/*<       dkhda=dkh/da >*/
    dkhda = static_cast<double>(dkh) / da;
/* SOURCE xsection.for:761 */
/*<       dbda=db/da >*/
    dbda = static_cast<double>(db) / da;
/*     CHECK FOR MODE OF TOP WIDTH EXTRAPOLATION. */
/* SOURCE xsection.for:765 */
/*<       if(ext.lt.0)dtdy=0.0 >*/
    if (*ext < (float)0.) {
	dtdy = (float)0.;
    }
/* SOURCE xsection.for:766 */
/*<       ext=abs(ext) >*/
    *ext = dabs(*ext);
/*     NOW COMPUTE THE NEW LEVEL */
/* SOURCE xsection.for:770 */
/*<       y3=y2+ext >*/
    y3 = static_cast<double>(y2) + *ext;
/* SOURCE xsection.for:771 */
/*<       t3=t2+dtdy*ext >*/
    t3 = static_cast<double>(t2) + static_cast<double>(dtdy) * *ext;
/* SOURCE xsection.for:772 */
/*<       if(t3.le.0.0)then >*/
    if (t3 <= (float)0.) {
/*       EXTRAPOLATION OF TOP WIDTH LEADS TO NON-POSITIVE VALUE. */
/* SOURCE xsection.for:774 */
/*<       write(std6,1)ext >*/
	feq_gen_io_d__88.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__88);
	do_fio(&feq_gen_c_d_1, (char *)&(*ext), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:775 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:776 */
/*<       endif >*/
    }
/* SOURCE xsection.for:778 */
/*<       daext=0.5*ext*(t2+t3) >*/
    daext = static_cast<double>(static_cast<double>(*ext) * (float).5) * (static_cast<double>(t2) + t3);
/* SOURCE xsection.for:779 */
/*<       a3=a2+daext >*/
    a3 = static_cast<double>(a2) + daext;
/* SOURCE xsection.for:780 */
/*<       kh3=kh2+dkhda*daext >*/
    kh3 = static_cast<double>(kh2) + static_cast<double>(dkhda) * daext;
/* SOURCE xsection.for:781 */
/*<       b3=b2+dbda*daext >*/
    b3 = static_cast<double>(b2) + static_cast<double>(dbda) * daext;
/* SOURCE xsection.for:782 */
/*<       if(b3.lt.1.0)b3=1.0 >*/
    if (b3 < (float)1.) {
	b3 = (float)1.;
    }
/*     NOW STORE AWAY THE VALUES */
/* SOURCE xsection.for:786 */
/*<       if((ftp+xoff).ge.mlft)callkil(10,ftp,eflag) >*/
    if (*ftp + *xoff >= *mlft) {
	kil_(&feq_gen_c_d_10, ftp, eflag);
    }
/* SOURCE xsection.for:789 */
/*<       ftab(ftp)=y3 >*/
    ftab[*ftp] = y3;
/* SOURCE xsection.for:790 */
/*<       ftab(ftp+1)=t3 >*/
    ftab[*ftp + 1] = t3;
/* SOURCE xsection.for:791 */
/*<       ftab(ftp+2)=a3 >*/
    ftab[*ftp + 2] = a3;
/* SOURCE xsection.for:792 */
/*<       ftab(ftp+3)=kh3 >*/
    ftab[*ftp + 3] = kh3;
/* SOURCE xsection.for:793 */
/*<       ftab(ftp+4)=b3 >*/
    ftab[*ftp + 4] = b3;
/*     THE CORE SET HAS BEEN DONE.  NOW DO THE TABLES THAT CONTAIN */
/*     ADDITIONAL ELEMENTS */
/* SOURCE xsection.for:799 */
/*<       if(type.gt.25)then >*/
    if (*feq_gen_type_d_ > 25) {
/* SOURCE xsection.for:800 */
/*<       it=type-10 >*/
	it = *feq_gen_type_d_ - 10;
/* SOURCE xsection.for:801 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:802 */
/*<       it=type >*/
	it = *feq_gen_type_d_;
/* SOURCE xsection.for:803 */
/*<       endif >*/
    }
/* SOURCE xsection.for:804 */
/*<       if(jid(it).eq.1)then >*/
    if (jid[it - 1] == 1) {
/*       FIRST MOMENT EXISTS IN THESE TABLES. */
/* SOURCE xsection.for:806 */
/*<       yb2=ftab(ftp-xoff+5) >*/
	yb2 = ftab[*ftp - *xoff + 5];
/* SOURCE xsection.for:807 */
/*<       yb3=yb2+0.5*ext*(a2+a3)-ext*ext*(t3-t2)/12. >*/
	yb3 = static_cast<double>(static_cast<double>(yb2) + static_cast<double>(static_cast<double>(*ext) * (float).5) * (static_cast<double>(a2) + a3)) - static_cast<double>(static_cast<double>(static_cast<double>(*ext) * *ext) * (static_cast<double>(t3) - t2)) / (
		float)12.;
/* SOURCE xsection.for:808 */
/*<       ftab(ftp+5)=yb3 >*/
	ftab[*ftp + 5] = yb3;
/* SOURCE xsection.for:809 */
/*<       endif >*/
    }
/* SOURCE xsection.for:811 */
/*<       if(qcid(it).eq.1)then >*/
    if (qcid[it - 1] == 1) {
/*       ALP AND QC EXISTS IN THESE TABLES. */
/* SOURCE xsection.for:813 */
/*<       alp2=ftab(ftp-xoff+6) >*/
	alp2 = ftab[*ftp - *xoff + 6];
/* SOURCE xsection.for:814 */
/*<       qc2=ftab(ftp-xoff+7) >*/
	qc2 = ftab[*ftp - *xoff + 7];
/* SOURCE xsection.for:815 */
/*<       dalp=alp2-ftab(ftp-ioff+6) >*/
	dalp = static_cast<double>(alp2) - ftab[*ftp - ioff + 6];
/* SOURCE xsection.for:816 */
/*<       dqc=qc2-ftab(ftp-ioff+7) >*/
	dqc = static_cast<double>(qc2) - ftab[*ftp - ioff + 7];
/* SOURCE xsection.for:817 */
/*<       dalpda=dalp/da >*/
	dalpda = static_cast<double>(dalp) / da;
/* SOURCE xsection.for:818 */
/*<       dqcda=dqc/da >*/
	dqcda = static_cast<double>(dqc) / da;
/* SOURCE xsection.for:819 */
/*<       alp3=alp2+dalpda*daext >*/
	alp3 = static_cast<double>(alp2) + static_cast<double>(dalpda) * daext;
/* SOURCE xsection.for:820 */
/*<       qc3=qc2+dqcda*daext >*/
	qc3 = static_cast<double>(qc2) + static_cast<double>(dqcda) * daext;
/* SOURCE xsection.for:821 */
/*<       if(qc3.lt.qc2)qc3=qc2 >*/
	if (qc3 < qc2) {
	    qc3 = qc2;
	}
/* SOURCE xsection.for:822 */
/*<       if(alp3.lt.1.0)alp3=1.0 >*/
	if (alp3 < (float)1.) {
	    alp3 = (float)1.;
	}
/* SOURCE xsection.for:823 */
/*<       ftab(ftp+6)=alp3 >*/
	ftab[*ftp + 6] = alp3;
/* SOURCE xsection.for:824 */
/*<       ftab(ftp+7)=qc3 >*/
	ftab[*ftp + 7] = qc3;
/* SOURCE xsection.for:825 */
/*<       endif >*/
    }
/* SOURCE xsection.for:827 */
/*<       if(it.ge.23)then >*/
    if (it >= 23) {
/*       WE HAVE THE WEIGHT COEFFICIENTS TO EXTRAPOLATE.  THESE */
/*       VARY IN POSITION AND MUST BE DONE INDIVIDUALLY.  COMPUTE */
/*       THE RATES OF CHANGE FOR EACH TYPE.  THEN EXTRAPOLATE */
/*       AND THEN STORE FOR EACH TYPE */
/* SOURCE xsection.for:833 */
/*<       if(it.eq.23)then >*/
	if (it == 23) {
/*         MA AND MQ ARE AT OFFSETS OF 5 AND 6 */
/* SOURCE xsection.for:835 */
/*<       ma2=ftab(ftp-xoff+5) >*/
	    ma2 = ftab[*ftp - *xoff + 5];
/* SOURCE xsection.for:836 */
/*<       dma=ma2-ftab(ftp-ioff+5) >*/
	    dma = static_cast<double>(ma2) - ftab[*ftp - ioff + 5];
/* SOURCE xsection.for:837 */
/*<       dmada=dma/da >*/
	    dmada = static_cast<double>(dma) / da;
/* SOURCE xsection.for:838 */
/*<       ma3=ma2+dmada*daext >*/
	    ma3 = static_cast<double>(ma2) + static_cast<double>(dmada) * daext;
/* SOURCE xsection.for:840 */
/*<       mq2=ftab(ftp-xoff+6) >*/
	    mq2 = ftab[*ftp - *xoff + 6];
/* SOURCE xsection.for:841 */
/*<       dmq=mq2-ftab(ftp-ioff+6) >*/
	    dmq = static_cast<double>(mq2) - ftab[*ftp - ioff + 6];
/* SOURCE xsection.for:842 */
/*<       dmqda=dmq/da >*/
	    dmqda = static_cast<double>(dmq) / da;
/* SOURCE xsection.for:843 */
/*<       mq3=mq2+dmqda*daext >*/
	    mq3 = static_cast<double>(mq2) + static_cast<double>(dmqda) * daext;
/* SOURCE xsection.for:844 */
/*<       ftab(ftp+5)=ma3 >*/
	    ftab[*ftp + 5] = ma3;
/* SOURCE xsection.for:845 */
/*<       ftab(ftp+6)=mq3 >*/
	    ftab[*ftp + 6] = mq3;
/* SOURCE xsection.for:846 */
/*<       elseif(it.eq.24)then >*/
	} else if (it == 24) {
/*         MA AND MQ ARE AT OFFSETS OF 6 AND 7 */
/* SOURCE xsection.for:848 */
/*<       ma2=ftab(ftp-xoff+6) >*/
	    ma2 = ftab[*ftp - *xoff + 6];
/* SOURCE xsection.for:849 */
/*<       dma=ma2-ftab(ftp-ioff+6) >*/
	    dma = static_cast<double>(ma2) - ftab[*ftp - ioff + 6];
/* SOURCE xsection.for:850 */
/*<       dmada=dma/da >*/
	    dmada = static_cast<double>(dma) / da;
/* SOURCE xsection.for:851 */
/*<       ma3=ma2+dmada*daext >*/
	    ma3 = static_cast<double>(ma2) + static_cast<double>(dmada) * daext;
/* SOURCE xsection.for:853 */
/*<       mq2=ftab(ftp-xoff+7) >*/
	    mq2 = ftab[*ftp - *xoff + 7];
/* SOURCE xsection.for:854 */
/*<       dmq=mq2-ftab(ftp-ioff+7) >*/
	    dmq = static_cast<double>(mq2) - ftab[*ftp - ioff + 7];
/* SOURCE xsection.for:855 */
/*<       dmqda=dmq/da >*/
	    dmqda = static_cast<double>(dmq) / da;
/* SOURCE xsection.for:856 */
/*<       mq3=mq2+dmqda*daext >*/
	    mq3 = static_cast<double>(mq2) + static_cast<double>(dmqda) * daext;
/* SOURCE xsection.for:857 */
/*<       ftab(ftp+6)=ma3 >*/
	    ftab[*ftp + 6] = ma3;
/* SOURCE xsection.for:858 */
/*<       ftab(ftp+7)=mq3 >*/
	    ftab[*ftp + 7] = mq3;
/* SOURCE xsection.for:859 */
/*<       elseif(it.eq.25)then >*/
	} else if (it == 25) {
/*         MA AND MQ ARE AT OFFSETS OF 8 AND 9 */
/* SOURCE xsection.for:861 */
/*<       ma2=ftab(ftp-xoff+8) >*/
	    ma2 = ftab[*ftp - *xoff + 8];
/* SOURCE xsection.for:862 */
/*<       dma=ma2-ftab(ftp-ioff+8) >*/
	    dma = static_cast<double>(ma2) - ftab[*ftp - ioff + 8];
/* SOURCE xsection.for:863 */
/*<       dmada=dma/da >*/
	    dmada = static_cast<double>(dma) / da;
/* SOURCE xsection.for:864 */
/*<       ma3=ma2+dmada*daext >*/
	    ma3 = static_cast<double>(ma2) + static_cast<double>(dmada) * daext;
/* SOURCE xsection.for:866 */
/*<       mq2=ftab(ftp-xoff+9) >*/
	    mq2 = ftab[*ftp - *xoff + 9];
/* SOURCE xsection.for:867 */
/*<       dmq=mq2-ftab(ftp-ioff+9) >*/
	    dmq = static_cast<double>(mq2) - ftab[*ftp - ioff + 9];
/* SOURCE xsection.for:868 */
/*<       dmqda=dmq/da >*/
	    dmqda = static_cast<double>(dmq) / da;
/* SOURCE xsection.for:869 */
/*<       mq3=mq2+dmqda*daext >*/
	    mq3 = static_cast<double>(mq2) + static_cast<double>(dmqda) * daext;
/* SOURCE xsection.for:870 */
/*<       ftab(ftp+8)=ma3 >*/
	    ftab[*ftp + 8] = ma3;
/* SOURCE xsection.for:871 */
/*<       ftab(ftp+9)=mq3 >*/
	    ftab[*ftp + 9] = mq3;
/* SOURCE xsection.for:872 */
/*<       endif >*/
	}
/* SOURCE xsection.for:873 */
/*<       endif >*/
    }
/*     Make adjustments to the derivatives wrt depth if 30 <= type <=35 */
/* SOURCE xsection.for:876 */
/*<       if(type.eq.30)then >*/
    if (*feq_gen_type_d_ == 30) {
/* SOURCE xsection.for:877 */
/*<       ftab(ftp+5)=(kh3-kh2)/(y3-y2) >*/
	ftab[*ftp + 5] = static_cast<double>((static_cast<double>(kh3) - kh2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:878 */
/*<       ftab(ftp+6)=(b3-b2)/(y3-y2) >*/
	ftab[*ftp + 6] = static_cast<double>((static_cast<double>(b3) - b2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:879 */
/*<       elseif(type.eq.31)then >*/
    } else if (*feq_gen_type_d_ == 31) {
/* SOURCE xsection.for:880 */
/*<       ftab(ftp+6)=(kh3-kh2)/(y3-y2) >*/
	ftab[*ftp + 6] = static_cast<double>((static_cast<double>(kh3) - kh2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:881 */
/*<       ftab(ftp+7)=(b3-b2)/(y3-y2) >*/
	ftab[*ftp + 7] = static_cast<double>((static_cast<double>(b3) - b2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:882 */
/*<       elseif(type.eq.32)then >*/
    } else if (*feq_gen_type_d_ == 32) {
/* SOURCE xsection.for:883 */
/*<       ftab(ftp+8)=(kh3-kh2)/(y3-y2) >*/
	ftab[*ftp + 8] = static_cast<double>((static_cast<double>(kh3) - kh2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:884 */
/*<       ftab(ftp+9)=(b3-b2)/(y3-y2) >*/
	ftab[*ftp + 9] = static_cast<double>((static_cast<double>(b3) - b2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:885 */
/*<       ftab(ftp+10)=(alp3-alp2)/(y3-y2) >*/
	ftab[*ftp + 10] = static_cast<double>((static_cast<double>(alp3) - alp2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:886 */
/*<       elseif(type.eq.33)then >*/
    } else if (*feq_gen_type_d_ == 33) {
/* SOURCE xsection.for:887 */
/*<       ftab(ftp+7)=(kh3-kh2)/(y3-y2) >*/
	ftab[*ftp + 7] = static_cast<double>((static_cast<double>(kh3) - kh2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:888 */
/*<       ftab(ftp+8)=(b3-b2)/(y3-y2) >*/
	ftab[*ftp + 8] = static_cast<double>((static_cast<double>(b3) - b2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:889 */
/*<       ftab(ftp+9)=(ma3-ma2)/(y3-y2) >*/
	ftab[*ftp + 9] = static_cast<double>((static_cast<double>(ma3) - ma2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:890 */
/*<       ftab(ftp+10)=(mq3-mq2)/(y3-y2) >*/
	ftab[*ftp + 10] = static_cast<double>((static_cast<double>(mq3) - mq2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:891 */
/*<       elseif(type.eq.34)then >*/
    } else if (*feq_gen_type_d_ == 34) {
/* SOURCE xsection.for:892 */
/*<       ftab(ftp+8)=(kh3-kh2)/(y3-y2) >*/
	ftab[*ftp + 8] = static_cast<double>((static_cast<double>(kh3) - kh2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:893 */
/*<       ftab(ftp+9)=(b3-b2)/(y3-y2) >*/
	ftab[*ftp + 9] = static_cast<double>((static_cast<double>(b3) - b2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:894 */
/*<       ftab(ftp+10)=(ma3-ma2)/(y3-y2) >*/
	ftab[*ftp + 10] = static_cast<double>((static_cast<double>(ma3) - ma2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:895 */
/*<       ftab(ftp+11)=(mq3-mq2)/(y3-y2) >*/
	ftab[*ftp + 11] = static_cast<double>((static_cast<double>(mq3) - mq2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:896 */
/*<       elseif(type.eq.35)then >*/
    } else if (*feq_gen_type_d_ == 35) {
/* SOURCE xsection.for:897 */
/*<       ftab(ftp+10)=(kh3-kh2)/(y3-y2) >*/
	ftab[*ftp + 10] = static_cast<double>((static_cast<double>(kh3) - kh2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:898 */
/*<       ftab(ftp+11)=(b3-b2)/(y3-y2) >*/
	ftab[*ftp + 11] = static_cast<double>((static_cast<double>(b3) - b2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:899 */
/*<       ftab(ftp+12)=(ma3-ma2)/(y3-y2) >*/
	ftab[*ftp + 12] = static_cast<double>((static_cast<double>(ma3) - ma2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:900 */
/*<       ftab(ftp+13)=(mq3-mq2)/(y3-y2) >*/
	ftab[*ftp + 13] = static_cast<double>((static_cast<double>(mq3) - mq2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:901 */
/*<       ftab(ftp+14)=(alp3-alp2)/(y3-y2) >*/
	ftab[*ftp + 14] = static_cast<double>((static_cast<double>(alp3) - alp2)) / (static_cast<double>(y3) - y2);
/* SOURCE xsection.for:902 */
/*<       endif >*/
    }
/* SOURCE xsection.for:908 */
/*<       ftp=ftp+xoff >*/
    *ftp += *xoff;
/* SOURCE xsection.for:910 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:912 */
/*<       end >*/
} /* extrap_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE xsection.for:916 */
/*<       realfunctionfndydn(depth,m,yvec,nvec) >*/
doublereal fndydn_(real *depth, integer *m, real *feq_storage_yvec, real *feq_storage_nvec)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    integer feq_gen_i_d_;

/*     + + + PURPOSE + + + */
/*     Find depth-dependent value of Manning's n. */
/* SOURCE xsection.for:922 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:925 */
/*<       integerm >*/
/* SOURCE xsection.for:926 */
/*<       realdepth,nvec(m),yvec(m) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DEPTH  - Depth argument for variation of Manning's n with */
/*               depth(maximum depth or hydraulic depth) */
/*     M      - Number of defined depth-dependent Manning's n values */
/*     YVEC   - Depth values for depth dependent Manning's n values */
/*     NVEC   - Values of Manning's n at each depth */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:936 */
/*<       integeri >*/
/* *********************************************************************** */
/*     FIND THE EXTREME VALUES. TABLE UNDERFLOW AND TABLE OVERFLOW ARE */
/*     NOT ERRORS.  WE ASSIGN THE VALUE AT DEPTH 0.0 TO TABLE UNDERFLOW */
/*     AND VALUE AT YVEC(M) TO TABLE OVERFLOW. */
/* SOURCE xsection.for:942 */
/*<       if(depth.le.0.)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> nvec(feq_storage_nvec, 1);

    feq::IndexedPointer<real> yvec(feq_storage_yvec, 1);

    /* Function Body */
    if (*depth <= (float)0.) {
/* SOURCE xsection.for:943 */
/*<       fndydn=nvec(1) >*/
	ret_val = nvec[1];
/* SOURCE xsection.for:944 */
/*<       elseif(depth.ge.yvec(m))then >*/
    } else if (*depth >= yvec[*m]) {
/* SOURCE xsection.for:945 */
/*<       fndydn=nvec(m) >*/
	ret_val = nvec[*m];
/* SOURCE xsection.for:946 */
/*<       else >*/
    } else {
/*       DO LINEAR SEARCH FOR INTERVAL AND LINEAR INTERPOLATE */
/* SOURCE xsection.for:948 */
/*<       i=1 >*/
	feq_gen_i_d_ = 1;
/* SOURCE xsection.for:949 */
/*<   100 continue >*/
L100:
/* SOURCE xsection.for:950 */
/*<       if(depth.le.yvec(i+1))then >*/
	if (*depth <= yvec[feq_gen_i_d_ + 1]) {
/*           FOUND INTERVAL. */
/* SOURCE xsection.for:953 */
/*<        >*/
	    ret_val = static_cast<double>(nvec[feq_gen_i_d_]) + static_cast<double>(static_cast<double>((static_cast<double>(*depth) - yvec[feq_gen_i_d_])) * (static_cast<double>(nvec[feq_gen_i_d_ + 1]) - 
		    nvec[feq_gen_i_d_])) / (static_cast<double>(yvec[feq_gen_i_d_ + 1]) - yvec[feq_gen_i_d_]);
/* SOURCE xsection.for:955 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:956 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE xsection.for:957 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE xsection.for:958 */
/*<       endif >*/
	}
/* SOURCE xsection.for:959 */
/*<       endif >*/
    }
/* SOURCE xsection.for:960 */
/*<       return >*/
    return ret_val;
/* SOURCE xsection.for:961 */
/*<       end >*/
} /* fndydn_ */




/* SOURCE xsection.for:965 */
/*<       subroutinecuttab(ndep,xst) >*/
/* Subroutine */ int cuttab_(integer *ndep, real *feq_storage_xst)
{
    // Original CUTTAB: slot detection, retained wide area, and complete table stores.
    // The released XST column stride is PMXPNT=999; CUTTAB accesses 13 columns.
    *ndep = static_cast<integer>(feq::cut_section_slot(
        std::span<float>(feq_storage_xst,999*13),999,static_cast<std::size_t>(*ndep),grvcom_1.grav));
    return 0;
} /* cuttab_ */




/* SOURCE xsection.for:1027 */
/*<       subroutinechktaj(stdout,ndep,xst,flag) >*/
/* Subroutine */ int chktaj_(integer *stdout, integer *ndep, real *feq_storage_xst, 
	integer *feq_gen_flag_d_)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX* Change in area between depths\
 \002,f10.4,\002 and \002,f10.4,\002 is inconsistent.  Rerr=\002,1pe10.4)";
    static char fmt_52[] = "(\002 *BUG:XXX* Change in first moment between d\
epths \002,f10.4,\002 and \002,f10.4,\002 is inconsistent.  Rerr=\002,1pe10.\
4)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal da, al, dj, ar, dy, tl, yl, tr, yr, diff;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__127 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__128 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__134 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Check consistency of top width, area, and first moment of area */
/*     for a cross section. */
/* SOURCE xsection.for:1035 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE xsection.for:1038 */
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
/* SOURCE xsection.for:1041 */
/*<       integerflag,ndep,stdout >*/
/* SOURCE xsection.for:1042 */
/*<       realxst(pmxpnt,pmxelm) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NDEP   - Number of depth values */
/*     XST    - Storage table for various elements of cross section */
/*     FLAG   - Result flag */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1051 */
/*<       integeri >*/
/* SOURCE xsection.for:1052 */
/*<       doubleprecisional,ar,da,diff,dj,dy,tl,tr,yl,yr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE xsection.for:1055 */
/*<       intrinsicabs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:1058 */
/*<    50  >*/
/* SOURCE xsection.for:1060 */
/*<    52  >*/
/* *********************************************************************** */
/* SOURCE xsection.for:1063 */
/*<       flag=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> xst(feq_storage_xst, 1000);

    /* Function Body */
/* L50: */
/* L52: */
    *feq_gen_flag_d_ = 0;
/* SOURCE xsection.for:1064 */
/*<       yl=0.0 >*/
    yl = (float)0.;
/* SOURCE xsection.for:1065 */
/*<       tl=xst(1,2) >*/
    tl = xst[1999];
/* SOURCE xsection.for:1066 */
/*<       al=0.d0 >*/
    al = 0.;
/* SOURCE xsection.for:1067 */
/*<       do100i=2,ndep >*/
    feq_gen_i_d_1 = *ndep;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:1068 */
/*<       yr=xst(i,1) >*/
	yr = xst[feq_gen_i_d_ + 999];
/* SOURCE xsection.for:1069 */
/*<       tr=xst(i,2) >*/
	tr = xst[feq_gen_i_d_ + 1998];
/* SOURCE xsection.for:1070 */
/*<       dy=yr-yl >*/
	dy = yr - yl;
/* SOURCE xsection.for:1071 */
/*<       da=0.5*dy*(tl+tr) >*/
	da = dy * (float).5 * (tl + tr);
/* SOURCE xsection.for:1072 */
/*<       if(da.eq.0.0)then >*/
	if (da == (float)0.) {
/* SOURCE xsection.for:1073 */
/*<       write(stdout,*)' PROBLEM IN CHKTAJ: DA = 0.0' >*/
	    feq_gen_io_d__127.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__127);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PROBLEM IN CHKTAJ: DA = 0.0"), (ftnlen)28);
	    e_wsle();
/* SOURCE xsection.for:1074 */
/*<       write(stdout,*)' YL=',yl,' YR=',yr,' DY=',dy >*/
	    feq_gen_io_d__128.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__128);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YL="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(doublereal));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YR="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(doublereal));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DY="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&dy, (ftnlen)sizeof(doublereal));
	    e_wsle();
/* SOURCE xsection.for:1075 */
/*<       write(stdout,*)' TL=',tl,' TR=',tr >*/
	    feq_gen_io_d__129.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__129);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TL="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&tl, (ftnlen)sizeof(doublereal));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TR="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&tr, (ftnlen)sizeof(doublereal));
	    e_wsle();
/* SOURCE xsection.for:1076 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:1077 */
/*<       endif >*/
	}
/* SOURCE xsection.for:1078 */
/*<       ar=al+da >*/
	ar = al + da;
/* SOURCE xsection.for:1079 */
/*<       dj=0.5*(dy*(ar+al-dy*(tr-tl)/6.0)) >*/
	dj = dy * (ar + al - dy * (tr - tl) / (float)6.) * (float).5;
/*       TEST FOR CLOSENESS */
/* SOURCE xsection.for:1082 */
/*<       diff=abs(da-(xst(i,3)-xst(i-1,3))) >*/
	diff = (feq_gen_d_d_1 = da - (static_cast<double>(xst[feq_gen_i_d_ + 2997]) - xst[feq_gen_i_d_ + 2996]), abs(feq_gen_d_d_1));
/* SOURCE xsection.for:1083 */
/*<       if(diff/da.gt.5.e-2.and.da.gt.5.e-1.and.tl.gt.2.0)then >*/
	if (diff / da > (float).05 && da > (float).5 && tl > (float)2.) {
/*         FLAG DISCREPANCY */
/* SOURCE xsection.for:1085 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE xsection.for:1086 */
/*<       write(stdout,50)yl,yr,diff/da >*/
	    feq_gen_io_d__133.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__133);
	    do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(doublereal));
	    feq_gen_d_d_1 = diff / da;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE xsection.for:1087 */
/*<       endif >*/
	}
/* SOURCE xsection.for:1089 */
/*<       diff=abs(dj-(xst(i,4)-xst(i-1,4))) >*/
	diff = (feq_gen_d_d_1 = dj - (static_cast<double>(xst[feq_gen_i_d_ + 3996]) - xst[feq_gen_i_d_ + 3995]), abs(feq_gen_d_d_1));
/* SOURCE xsection.for:1090 */
/*<       if(diff/dj.gt.8.e-2.and.dj.gt.5.e-1.and.tl.gt.2.0)then >*/
	if (diff / dj > (float).08 && dj > (float).5 && tl > (float)2.) {
/*         FLAG DISCREPANCY */
/* SOURCE xsection.for:1092 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE xsection.for:1093 */
/*<       write(stdout,52)yl,yr,diff/dj >*/
	    feq_gen_io_d__134.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__134);
	    do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(doublereal));
	    feq_gen_d_d_1 = diff / dj;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE xsection.for:1094 */
/*<       endif >*/
	}
/* SOURCE xsection.for:1096 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE xsection.for:1097 */
/*<       tl=tr >*/
	tl = tr;
/* SOURCE xsection.for:1098 */
/*<       al=ar >*/
	al = ar;
/* SOURCE xsection.for:1099 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE xsection.for:1101 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:1102 */
/*<       end >*/
} /* chktaj_ */




/* SOURCE xsection.for:1106 */
/*<        >*/
/* Subroutine */ int subset_(integer *stdout, integer *npnt, real *feq_storage_x, real *
	feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real *zmax, real *feq_storage_sn, real *feq_storage_lsn, real *xl, real *xr,
	 integer *eflag, integer *npnts, real *feq_storage_xs, real *feq_storage_zs, integer *feq_storage_sbs, 
	real *feq_storage_sns, real *feq_storage_lsns)
{
    /* Format strings */
    static char fmt_51[] = "(\0020*ERR:518* Subset and section are disjoin\
t\002)";
    static char fmt_52[] = "(\0020*WRN:524* Left-hand subset request of\002,\
f10.2,\002 is left\002,/,10x,\002of cross section boundary of\002,f10.2)";
    static char fmt_53[] = "(10x,\002Subset request set to the cross section\
 boundary\002)";
    static char fmt_54[] = "(\0020*WRN:525* Right hand subset request of\002\
,f10.2,\002 is\002,\002 right\002,/,10x,\002of cross section boundary of\002\
,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, il, ir;
    real zl, zr, snl, snr;
    integer ilp1, irm1;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__135 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__136 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__139 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Extract the part of a cross section contained between */
/*     offsets XL and XR. */
/* SOURCE xsection.for:1115 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:1118 */
/*<       integereflag,npnt,npnts,stdout >*/
/* SOURCE xsection.for:1119 */
/*<       integersb(npnt),sbs(npnts) >*/
/* SOURCE xsection.for:1120 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NPNT   - Number of points on boundary of a cross section */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     ZMAX   - Maximum elevation */
/*     SN     - Sinuousity at a point on a cross section boundary */
/*     LSN    - Line segment Manning's n value */
/*     XL     - Offset at left hand end of segment */
/*     XR     - Offset at right hand end of segment */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     NPNTS  - Number of points on boundary of a cross section */
/*     XS     - Offsets for subset of a cross section */
/*     ZS     - Elevation of boundary points in subset */
/*     SBS    - Subsection numbers for the line segments in the subset */
/*     SNS    - Sinuousity at a point on a subset of a cross section */
/*     LSNS   - Line segment Manning's n value for the subset */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1143 */
/*<       integeri,il,ilp1,ir,irm1 >*/
/* SOURCE xsection.for:1144 */
/*<       realsnl,snr,zl,zr >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:1147 */
/*<    51 format('0*ERR:518* Subset and section are disjoint') >*/
/* SOURCE xsection.for:1148 */
/*<    52  >*/
/* SOURCE xsection.for:1150 */
/*<    53 format(10x,'Subset request set to the cross section boundary') >*/
/* SOURCE xsection.for:1151 */
/*<    54  >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' ' */
/*      WRITE(STDOUT,*) ' Entering SUBSET' */
/*      WRITE(STDOUT,*) ' XL=',XL,' XR=',XR */
/*     CHECK FOR XL AND XR BEING OUTSIDE THE BOUNDS OF THE */
/*     CROSS SECTION */
/* SOURCE xsection.for:1161 */
/*<       if(xl.lt.x(1))then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> lsns(feq_storage_lsns, 1);

    feq::IndexedPointer<real> sns(feq_storage_sns, 1);

    feq::IndexedPointer<integer> sbs(feq_storage_sbs, 1);

    feq::IndexedPointer<real> zs(feq_storage_zs, 1);

    feq::IndexedPointer<real> xs(feq_storage_xs, 1);

    /* Function Body */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
    if (*xl < x[1]) {
/*       ISSUE WARNING AND RESET TO THE LIMIT OF THE CROSS SECTION */
/* SOURCE xsection.for:1164 */
/*<       write(stdout,52)xl,x(1) >*/
	feq_gen_io_d__135.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__135);
	do_fio(&feq_gen_c_d_1, (char *)&(*xl), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&x[1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:1165 */
/*<       write(stdout,53) >*/
	feq_gen_io_d__136.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__136);
	e_wsfe();
/* SOURCE xsection.for:1166 */
/*<       xl=x(1) >*/
	*xl = x[1];
/* SOURCE xsection.for:1167 */
/*<       endif >*/
    }
/* SOURCE xsection.for:1169 */
/*<       if(xr.gt.x(npnt))then >*/
    if (*xr > x[*npnt]) {
/* SOURCE xsection.for:1170 */
/*<       write(stdout,54)xr,x(npnt) >*/
	feq_gen_io_d__137.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__137);
	do_fio(&feq_gen_c_d_1, (char *)&(*xr), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:1171 */
/*<       write(stdout,53) >*/
	feq_gen_io_d__138.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__138);
	e_wsfe();
/* SOURCE xsection.for:1172 */
/*<       xr=x(npnt) >*/
	*xr = x[*npnt];
/* SOURCE xsection.for:1173 */
/*<       endif >*/
    }
/* SOURCE xsection.for:1174 */
/*<       if(xl.lt.x(npnt).and.xr.gt.x(1))goto100 >*/
    if (*xl < x[*npnt] && *xr > x[1]) {
	goto L100;
    }
/* SOURCE xsection.for:1175 */
/*<       write(stdout,51) >*/
    feq_gen_io_d__139.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__139);
    e_wsfe();
/* SOURCE xsection.for:1176 */
/*<       eflag=eflag+1 >*/
    ++(*eflag);
/* SOURCE xsection.for:1177 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:1178 */
/*<   100 continue >*/
L100:
/*     IL is the index of the point that is at or to the left */
/*     of XL.  In other words the line segment on the cross section */
/*     boundary between IL  and IL + 1 will contain XL. */
/*     IR is the index of the point that is at or to the right */
/*     of XR.  In other words the line segment on the cross section */
/*     boundary between IR - 1 and IR will contain XR. */
/* SOURCE xsection.for:1188 */
/*<       il=0 >*/
    il = 0;
/* SOURCE xsection.for:1189 */
/*<       ir=0 >*/
    ir = 0;
/* SOURCE xsection.for:1190 */
/*<       do200i=2,npnt >*/
    feq_gen_i_d_1 = *npnt;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:1191 */
/*<       if(xl.ge.x(i-1).and.xl.lt.x(i))il=i-1 >*/
	if (*xl >= x[feq_gen_i_d_ - 1] && *xl < x[feq_gen_i_d_]) {
	    il = feq_gen_i_d_ - 1;
	}
/* SOURCE xsection.for:1192 */
/*<       if(xr.le.x(i).and.xr.gt.x(i-1))ir=i >*/
	if (*xr <= x[feq_gen_i_d_] && *xr > x[feq_gen_i_d_ - 1]) {
	    ir = feq_gen_i_d_;
	}
/* SOURCE xsection.for:1193 */
/*<       if(ir.gt.0.and.il.gt.0)goto250 >*/
	if (ir > 0 && il > 0) {
	    goto L250;
	}
/* SOURCE xsection.for:1194 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE xsection.for:1195 */
/*<   250 continue >*/
L250:
/* SOURCE xsection.for:1197 */
/*<       zl=z(il)+(xl-x(il))*(z(il+1)-z(il))/(x(il+1)-x(il)) >*/
    zl = static_cast<double>(feq_gen_z_d_[il]) + static_cast<double>(static_cast<double>((static_cast<double>(*xl) - x[il])) * (static_cast<double>(feq_gen_z_d_[il + 1]) - feq_gen_z_d_[il])) / (static_cast<double>(x[il + 1]) - x[
	    il]);
/* SOURCE xsection.for:1198 */
/*<       snl=sn(il)+(xl-x(il))*(sn(il+1)-sn(il))/(x(il+1)-x(il)) >*/
    snl = static_cast<double>(sn[il]) + static_cast<double>(static_cast<double>((static_cast<double>(*xl) - x[il])) * (static_cast<double>(sn[il + 1]) - sn[il])) / (static_cast<double>(x[il + 1]) - x[il])
	    ;
/* SOURCE xsection.for:1199 */
/*<       zr=z(ir-1)+(xr-x(ir-1))*(z(ir)-z(ir-1))/(x(ir)-x(ir-1)) >*/
    zr = static_cast<double>(feq_gen_z_d_[ir - 1]) + static_cast<double>(static_cast<double>((static_cast<double>(*xr) - x[ir - 1])) * (static_cast<double>(feq_gen_z_d_[ir]) - feq_gen_z_d_[ir - 1])) / (static_cast<double>(x[ir]) - 
	    x[ir - 1]);
/* SOURCE xsection.for:1200 */
/*<       snr=sn(ir-1)+(xr-x(ir-1))*(sn(ir)-sn(ir-1))/(x(ir)-x(ir-1)) >*/
    snr = static_cast<double>(sn[ir - 1]) + static_cast<double>(static_cast<double>((static_cast<double>(*xr) - x[ir - 1])) * (static_cast<double>(sn[ir]) - sn[ir - 1])) / (static_cast<double>(x[ir]) - x[
	    ir - 1]);
/*     Transfer the subset.  We add vertical walls at each limit. */
/*     If these walls are to have resistance, they must be part of */
/*     a subsection that includes non-sero area.  Thus if we */
/*     wish to make the walls have zero resistance, we add two */
/*     additional subsections and make sure that each vertical */
/*     end line segment has a unique subsection.  This subsection */
/*     will then have zero area, the signal to subsequent processing */
/*     that the line segement contributes no resistance to the flow. */
/*     January 29, 2002:  Added walls are frictionless.  Code will need */
/*     significant revision to allow this to be user selected! */
/*     Add the two points required to define the vertical wall at */
/*     the left-hand extremity of the subset. */
/* SOURCE xsection.for:1217 */
/*<       xs(1)=xl >*/
    xs[1] = *xl;
/* SOURCE xsection.for:1218 */
/*<       zs(1)=zmax >*/
    zs[1] = *zmax;
/* SOURCE xsection.for:1219 */
/*<       sns(1)=snl >*/
    sns[1] = snl;
/* SOURCE xsection.for:1220 */
/*<       sbs(1)=sb(il) >*/
    sbs[1] = sb[il];
/* SOURCE xsection.for:1221 */
/*<       lsns(1)=lsn(il) >*/
    lsns[1] = lsn[il];
/* SOURCE xsection.for:1223 */
/*<       xs(2)=xl >*/
    xs[2] = *xl;
/* SOURCE xsection.for:1224 */
/*<       zs(2)=zl >*/
    zs[2] = zl;
/* SOURCE xsection.for:1225 */
/*<       sns(2)=snl >*/
    sns[2] = snl;
/* SOURCE xsection.for:1226 */
/*<       sbs(2)=sb(il) >*/
    sbs[2] = sb[il];
/* SOURCE xsection.for:1227 */
/*<       lsns(2)=lsn(il) >*/
    lsns[2] = lsn[il];
/* SOURCE xsection.for:1229 */
/*<       npnts=2 >*/
    *npnts = 2;
/*     IL is the index of the point on the boundary that is at */
/*     or to the left of XL.  We have already added the point at */
/*     XL to the subset.  Thus we want the point just beyond IL */
/*     to be the next point on the subset boundary. */
/* SOURCE xsection.for:1235 */
/*<       ilp1=il+1 >*/
    ilp1 = il + 1;
/*     IR is the index of the point on the boundary that is at or */
/*     to the right of XR.  Thus in order to add XR and possibly change */
/*     its subsection number, we need to stop the transfer of points */
/*     just before IR. */
/* SOURCE xsection.for:1241 */
/*<       irm1=ir-1 >*/
    irm1 = ir - 1;
/* SOURCE xsection.for:1242 */
/*<       do310i=ilp1,irm1 >*/
    feq_gen_i_d_1 = irm1;
    for (feq_gen_i_d_ = ilp1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:1243 */
/*<       npnts=npnts+1 >*/
	++(*npnts);
/* SOURCE xsection.for:1244 */
/*<       xs(npnts)=x(i) >*/
	xs[*npnts] = x[feq_gen_i_d_];
/* SOURCE xsection.for:1245 */
/*<       zs(npnts)=z(i) >*/
	zs[*npnts] = feq_gen_z_d_[feq_gen_i_d_];
/* SOURCE xsection.for:1246 */
/*<       sns(npnts)=sn(i) >*/
	sns[*npnts] = sn[feq_gen_i_d_];
/* SOURCE xsection.for:1247 */
/*<       sbs(npnts)=sb(i) >*/
	sbs[*npnts] = sb[feq_gen_i_d_];
/* SOURCE xsection.for:1248 */
/*<       lsns(npnts)=lsn(i) >*/
	lsns[*npnts] = lsn[feq_gen_i_d_];
/* SOURCE xsection.for:1249 */
/*<   310 continue >*/
/* L310: */
    }
/*     Now add the vertical wall at XR. */
/* SOURCE xsection.for:1252 */
/*<       npnts=npnts+1 >*/
    ++(*npnts);
/* SOURCE xsection.for:1253 */
/*<       xs(npnts)=xr >*/
    xs[*npnts] = *xr;
/* SOURCE xsection.for:1254 */
/*<       zs(npnts)=zr >*/
    zs[*npnts] = zr;
/* SOURCE xsection.for:1255 */
/*<       sns(npnts)=snr >*/
    sns[*npnts] = snr;
/* SOURCE xsection.for:1256 */
/*<       sbs(npnts)=sb(irm1) >*/
    sbs[*npnts] = sb[irm1];
/* SOURCE xsection.for:1257 */
/*<       lsns(npnts)=lsns(npnts-1) >*/
    lsns[*npnts] = lsns[*npnts - 1];
/* SOURCE xsection.for:1259 */
/*<       npnts=npnts+1 >*/
    ++(*npnts);
/* SOURCE xsection.for:1260 */
/*<       xs(npnts)=xr >*/
    xs[*npnts] = *xr;
/* SOURCE xsection.for:1261 */
/*<       zs(npnts)=zmax >*/
    zs[*npnts] = *zmax;
/* SOURCE xsection.for:1262 */
/*<       sns(npnts)=snr >*/
    sns[*npnts] = snr;
/* SOURCE xsection.for:1263 */
/*<       sbs(npnts)=0 >*/
    sbs[*npnts] = 0;
/* SOURCE xsection.for:1264 */
/*<       lsns(npnts)=0.0 >*/
    lsns[*npnts] = (float)0.;
/*      WRITE(STDOUT,93) XL,XR */
/* 93    FORMAT('SUBSET results:',/,' XL=',F10.2,' XR=',F10.2) */
/*      DO 500 I=1,NPNTS */
/*        WRITE(STDOUT,92) XS(I),ZS(I),SBS(I) */
/* 92      FORMAT(2F10.2,I5) */
/* 500   CONTINUE */
/* SOURCE xsection.for:1273 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:1274 */
/*<       end >*/
} /* subset_ */




/* SOURCE xsection.for:1278 */
/*<       subroutinechkarg(stdout,mxndep,nrzero,dzlim,added,ndep,z) >*/
/* Subroutine */ int chkarg_(integer *stdout, integer *mxndep, real *nrzero, 
	real *dzlim, integer *added, integer *ndep, real *feq_gen_feq_storage_z_d_)
{
    /* Format strings */
    static char fmt_50[] = "(\0020*ERR:525*SPACE FOR ELEVATION ARGUMENTS EXH\
AUSTED\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, j, m, n;
    real dz, tp, delz;
    extern /* Subroutine */ int rdup_(integer *, real *, integer *), sort_(
	    integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Checks and modifies argument sequence in Z(*) to ensure that */
/*     a near zero point is present and that the argument spacing is */
/*     not larger than DZLIM. */
/* SOURCE xsection.for:1287 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:1290 */
/*<       integeradded,mxndep,ndep,stdout >*/
/* SOURCE xsection.for:1291 */
/*<       realdzlim,nrzero,z(mxndep) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NDEP   - Number of depth values */
/*     MXNDEP - Maximum number of depth values allowed */
/*     NRZERO - Value of depth near zero */
/*     DZLIM  - Maximum value of elevation difference permitted between */
/*              adjacent entries in a cross section function table */
/*     Z      - Distinct values of elevation at points on a cross */
/*               section boundary */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1304 */
/*<       integeri,j,m,n >*/
/* SOURCE xsection.for:1305 */
/*<       realdelz,dz,tp >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:1308 */
/*<       externalrdup,sort >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:1311 */
/*<    50 format('0*ERR:525*SPACE FOR ELEVATION ARGUMENTS EXHAUSTED') >*/
/* *********************************************************************** */
/* SOURCE xsection.for:1313 */
/*<       n=ndep >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    /* Function Body */
/* L50: */
    
    // Original-verified CHKARG register precision, stable sort, and RDUP.
    const int feq_exhausted = feq_elevation_arguments(*mxndep,ndep,*nrzero,*dzlim,*added,&feq_gen_z_d_[1]);
    for (int feq_event = 0; feq_event < feq_exhausted; ++feq_event) {
        feq_gen_io_d__151.ciunit = *stdout;
        s_wsfe(&feq_gen_io_d__151);
        e_wsfe();
    }
    return 0;
/* SOURCE xsection.for:1381 */
/*<       end >*/
} /* chkarg_ */




/* SOURCE xsection.for:1385 */
/*<       subroutinexchk(stdout,npnt,zmin,x,nfac,z) >*/
/* Subroutine */ int xchk_(integer *stdout, integer *npnt, real *zmin, real *
	feq_storage_x, real *nfac, real *feq_gen_feq_storage_z_d_)
{
    /* Format strings */
    static char fmt_2[] = "(/,\002 *WRN:504*Line segment ending at (\002,f10\
.2,f10.2,\002) is horizontal and not\002,/,5x,\002 at minimum elevation.\002,\
\002  Right hand end incremented by\002,f7.3)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_;
    real dz;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__160 = { 0, 0, 0, fmt_2, 0 };


/*     + + + PURPOSE + + + */
/*     Check for horizontal segments which are not at ZMIN. */
/* SOURCE xsection.for:1392 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:1395 */
/*<       integernpnt,stdout >*/
/* SOURCE xsection.for:1396 */
/*<       realnfac,x(npnt),z(npnt),zmin >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NPNT   - Number of points on boundary of a cross section */
/*     ZMIN   - Minimum elevation */
/*     X      - Offsets of points on cross section boundary */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     Z      - Elevation at points on cross section boundary */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1407 */
/*<       integeri >*/
/* SOURCE xsection.for:1408 */
/*<       realdz >*/
/*     + + + INTRINSICS + + + */
/* SOURCE xsection.for:1411 */
/*<       intrinsicabs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:1414 */
/*<     2  >*/
/* *********************************************************************** */
/*     ESTABLISH STANDARD INCREMENT */
/* SOURCE xsection.for:1420 */
/*<       if(nfac.gt.1.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* L2: */
    if (*nfac > (float)1.) {
/*       English system */
/* SOURCE xsection.for:1422 */
/*<       dz=0.053 >*/
	dz = (float).053;
/* SOURCE xsection.for:1423 */
/*<       else >*/
    } else {
/*       Metric sytem */
/* SOURCE xsection.for:1425 */
/*<       dz=0.0161544 >*/
	dz = (float).0161544;
/* SOURCE xsection.for:1426 */
/*<       endif >*/
    }
/*     SCAN ALL LINE SEGMENTS */
/* SOURCE xsection.for:1430 */
/*<       do100i=2,npnt >*/
    feq_gen_i_d_1 = *npnt;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:1431 */
/*<       if(abs(z(i)-z(i-1)).ge.0.001)goto100 >*/
	if ((feq_gen_r_d_1 = static_cast<double>(feq_gen_z_d_[feq_gen_i_d_]) - feq_gen_z_d_[feq_gen_i_d_ - 1], dabs(feq_gen_r_d_1)) >= (float).001) {
	    goto L100;
	}
/* SOURCE xsection.for:1432 */
/*<       if(abs(zmin-z(i)).lt.0.001)goto100 >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*zmin) - feq_gen_z_d_[feq_gen_i_d_], dabs(feq_gen_r_d_1)) < (float).001) {
	    goto L100;
	}
/* SOURCE xsection.for:1433 */
/*<       write(stdout,2)x(i),z(i),dz >*/
	feq_gen_io_d__160.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__160);
	do_fio(&feq_gen_c_d_1, (char *)&x[feq_gen_i_d_], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[feq_gen_i_d_], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:1434 */
/*<       z(i)=z(i)+dz >*/
	feq_gen_z_d_[feq_gen_i_d_] += static_cast<double>(dz);
/* SOURCE xsection.for:1435 */
/*<   100 continue >*/
L100:
	;
    }
/* SOURCE xsection.for:1436 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:1437 */
/*<       end >*/
} /* xchk_ */




/* SOURCE xsection.for:1441 */
/*<       subroutinereasub(stdout,npnt,nsub,n,sb,eflag) >*/
/* Subroutine */ int reasub_(integer *stdout, integer *npnt, integer *nsub, 
	real *feq_storage_n, integer *feq_storage_sb, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:614* MAXIMUM NUMBER OF SUBSECTIONS\
=\002,i5,\002 EXCEEDED IN REASUB.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer j, run[200], seen[200], oldsub, cursub, newsub, nxtsub;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__166 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Reassign subsections so that no subsection number is */
/*     repeated after it has been used one or more times in */
/*     consecutive sequence. */
/* SOURCE xsection.for:1451 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:1454 */
/*<       integereflag,npnt,nsub,stdout >*/
/* SOURCE xsection.for:1455 */
/*<       integersb(*) >*/
/* SOURCE xsection.for:1456 */
/*<       realn(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NPNT   - Number of points on boundary of a cross section */
/*     NSUB   - Number of subsections */
/*     N      - Manning's n values */
/*     SB     - Subsection numbers for the line segments */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:1467 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1470 */
/*<       integercursub,j,newsub,nxtsub,oldsub >*/
/* SOURCE xsection.for:1471 */
/*<       integerrun(pmxsub),seen(pmxsub) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:1474 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE xsection.for:1477 */
/*<       do100j=1,nsub >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    /* Function Body */
/* L50: */
    feq_gen_i_d_1 = *nsub;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:1478 */
/*<       run(j)=0 >*/
	run[j - 1] = 0;
/* SOURCE xsection.for:1479 */
/*<       seen(j)=0 >*/
	seen[j - 1] = 0;
/* SOURCE xsection.for:1480 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE xsection.for:1482 */
/*<       oldsub=-1 >*/
    oldsub = -1;
/* SOURCE xsection.for:1483 */
/*<       nxtsub=nsub+1 >*/
    nxtsub = *nsub + 1;
/* SOURCE xsection.for:1484 */
/*<       if(nxtsub.gt.pmxsub)then >*/
    if (nxtsub > 200) {
/* SOURCE xsection.for:1485 */
/*<       write(stdout,50)pmxsub >*/
	feq_gen_io_d__166.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__166);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_200, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE xsection.for:1486 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE xsection.for:1487 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:1488 */
/*<       endif >*/
    }
/* SOURCE xsection.for:1490 */
/*<       do200j=1,npnt-1 >*/
    feq_gen_i_d_1 = *npnt - 1;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:1491 */
/*<       cursub=sb(j) >*/
	cursub = sb[j];
/* SOURCE xsection.for:1492 */
/*<       if(run(cursub).eq.0)then >*/
	if (run[cursub - 1] == 0) {
/* SOURCE xsection.for:1493 */
/*<       if(oldsub.ne.-1)then >*/
	    if (oldsub != -1) {
/*           RUN OF OLDSUB HAS ENDED */
/* SOURCE xsection.for:1495 */
/*<       seen(oldsub)=seen(oldsub)+1 >*/
		++seen[oldsub - 1];
/* SOURCE xsection.for:1496 */
/*<       run(oldsub)=0 >*/
		run[oldsub - 1] = 0;
/* SOURCE xsection.for:1497 */
/*<       endif >*/
	    }
/*         INITIATE NEXT RUN OF CURSUB */
/* SOURCE xsection.for:1500 */
/*<       run(cursub)=1 >*/
	    run[cursub - 1] = 1;
/* SOURCE xsection.for:1501 */
/*<       oldsub=cursub >*/
	    oldsub = cursub;
/* SOURCE xsection.for:1502 */
/*<       if(seen(cursub).eq.0)then >*/
	    if (seen[cursub - 1] == 0) {
/* SOURCE xsection.for:1503 */
/*<       seen(cursub)=1 >*/
		seen[cursub - 1] = 1;
/* SOURCE xsection.for:1504 */
/*<       else >*/
	    } else {
/*           ASSIGN NEXT SUBSECTION- START NEW RUN OF CURSUB */
/* SOURCE xsection.for:1506 */
/*<       sb(j)=nxtsub >*/
		sb[j] = nxtsub;
/* SOURCE xsection.for:1507 */
/*<       n(nxtsub)=n(cursub) >*/
		n[nxtsub] = n[cursub];
/* SOURCE xsection.for:1508 */
/*<       newsub=nxtsub >*/
		newsub = nxtsub;
/* SOURCE xsection.for:1509 */
/*<       nxtsub=nxtsub+1 >*/
		++nxtsub;
/* SOURCE xsection.for:1510 */
/*<       if(nxtsub.gt.pmxsub)then >*/
		if (nxtsub > 200) {
/* SOURCE xsection.for:1511 */
/*<       write(stdout,50)pmxsub >*/
		    feq_gen_io_d__169.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__169);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_200, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE xsection.for:1512 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE xsection.for:1513 */
/*<       return >*/
		    return 0;
/* SOURCE xsection.for:1514 */
/*<       endif >*/
		}
/* SOURCE xsection.for:1515 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:1516 */
/*<       else >*/
	} else {
/*         RUN OF CURSUB IS IN PROGRESS */
/* SOURCE xsection.for:1518 */
/*<       if(seen(cursub).gt.1)then >*/
	    if (seen[cursub - 1] > 1) {
/* SOURCE xsection.for:1519 */
/*<       sb(j)=newsub >*/
		sb[j] = newsub;
/* SOURCE xsection.for:1520 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:1521 */
/*<       endif >*/
	}
/* SOURCE xsection.for:1522 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE xsection.for:1524 */
/*<       nsub=nxtsub-1 >*/
    *nsub = nxtsub - 1;
/* SOURCE xsection.for:1525 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:1526 */
/*<       end >*/
} /* reasub_ */




/* SOURCE xsection.for:1530 */
/*<       subroutineinspt(stdout,npi,xarg,vartyp,npnt,x,z,sb,lsn,eflag) >*/
/* Subroutine */ int inspt_(integer *stdout, integer *npi, real *feq_storage_xarg, 
	integer *vartyp, integer *npnt, real *feq_storage_x, real *feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real 
	*feq_storage_lsn, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:652* Cross section space full in IN\
SPT. Need\002,i5,\002 points but\002,/,10x,\002only\002,i5,\002 available\
.\002)";
    static char fmt_52[] = "(/,\002 *ERR:653* PWC sinuosity offset=\002,f10.\
2,\002 not in the\002,\002 offsets\002,/,10x,\002 for this cross section.\
\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, j, k;
    real p;
    integer is, js;
    real zval;
    integer sbval;
    real lsnval;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__170 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__175 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Add one or more offsets to the cross section description, */
/*     interpolating for the elevation, adjust the line segment n, */
/*     and adjust the subsection number.  The sinuousity is not */
/*     yet defined.  The line segment n may not be defined in */
/*     some cases but is adjusted anyway. */
/* SOURCE xsection.for:1542 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE xsection.for:1545 */
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
/* SOURCE xsection.for:1548 */
/*<       integereflag,npi,npnt,stdout,vartyp >*/
/* SOURCE xsection.for:1549 */
/*<       integersb(pmxpnt) >*/
/* SOURCE xsection.for:1550 */
/*<       reallsn(pmxpnt),x(pmxpnt),xarg(npi),z(pmxpnt) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NPI    - Number of points to insert */
/*     XARG   - Vector of offsets of points to be inserted */
/*     VARTYP - If VARTYP=1 then piecewise linear variation of sinuousity */
/*               with offset in a cross section is assumed; else */
/*               if VARTYP=2 then piecewise constant variation of */
/*               sinuousity with offset in a cross section is assumed. */
/*     NPNT   - Number of points on boundary of a cross section */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     LSN    - Line segment Manning's n value */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1568 */
/*<       integeri,is,j,js,k,sbval >*/
/* SOURCE xsection.for:1569 */
/*<       reallsnval,p,zval >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:1572 */
/*<    50  >*/
/* SOURCE xsection.for:1574 */
/*<    52  >*/
/* *********************************************************************** */
/* SOURCE xsection.for:1577 */
/*<       if(npnt+npi-2.gt.pmxpnt)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> xarg(feq_storage_xarg, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    /* Function Body */
/* L50: */
/* L52: */
    if (*npnt + *npi - 2 > 999) {
/* SOURCE xsection.for:1578 */
/*<       write(stdout,50)pmxpnt,pmxpnt+npi >*/
	feq_gen_io_d__170.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__170);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_999, (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = *npi + 999;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE xsection.for:1579 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE xsection.for:1580 */
/*<       else >*/
    } else {
/*       WE HAVE ROOM FOR THE ADDED OFFSETS.  THE OFFSETS ARE GIVEN */
/*       IN ASCENDING ORDER.  THEREFORE SHORTEN THE SEARCH AS WE */
/*       FIND THE OFFSETS. */
/* SOURCE xsection.for:1585 */
/*<       is=1 >*/
	is = 1;
/*       THE FIRST AND LAST OFFSET HAVE BEEN ADDED IN ADJSIN.  DO */
/*       NOT TRY TO ADD THESE */
/* SOURCE xsection.for:1589 */
/*<       do500k=2,npi-1 >*/
	feq_gen_i_d_1 = *npi - 1;
	for (k = 2; k <= feq_gen_i_d_1; ++k) {
/*          WRITE(STDOUT,*) ' K=',K,' XARG(K)=',XARG(K) */
/* SOURCE xsection.for:1592 */
/*<       do200i=is+1,npnt >*/
	    feq_gen_i_d_2 = *npnt;
	    for (feq_gen_i_d_ = is + 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE xsection.for:1593 */
/*<       if(xarg(k).ge.x(i-1).and.xarg(k).le.x(i))then >*/
		if (xarg[k] >= x[feq_gen_i_d_ - 1] && xarg[k] <= x[feq_gen_i_d_]) {
/*             FOUND INTERVAL CONTAINING THE OFFSET. REMEMBER WHERE */
/*             WE ARE.  START NEXT SEARCH WHERE WE ARE NOW. */
/* SOURCE xsection.for:1597 */
/*<       is=i >*/
		    is = feq_gen_i_d_;
/* SOURCE xsection.for:1598 */
/*<       js=i >*/
		    js = feq_gen_i_d_;
/*              WRITE(STDOUT,*) ' FOUND CONTAINING INTERVAL. I=',I */
/*             DO WE NEED TO ADD THE POINT. */
/* SOURCE xsection.for:1603 */
/*<       if(xarg(k).ne.x(i-1).and.xarg(k).ne.x(i))then >*/
		    if (xarg[k] != x[feq_gen_i_d_ - 1] && xarg[k] != x[feq_gen_i_d_]) {
/*               ADD THE POINT.  FIND THE NEW VALUES. */
/* SOURCE xsection.for:1605 */
/*<       if(vartyp.eq.2)then >*/
			if (*vartyp == 2) {
/*                 PIECEWISE CONSTANT SINUOUSITY SHOULD NOT BE HERE. */
/*                 FOR PWC THE OFFSETS IN THE SINUOUSITY TABLE SHOULD */
/*                 BE ON A SUBSECTION BOUNDARY.  ALL SUBSECTION */
/*                 BOUNDARY POINTS SHOULD BE IN X(*). */
/* SOURCE xsection.for:1610 */
/*<       write(stdout,52)xarg(k) >*/
			    feq_gen_io_d__175.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__175);
			    do_fio(&feq_gen_c_d_1, (char *)&xarg[k], (ftnlen)sizeof(
				    real));
			    e_wsfe();
/* SOURCE xsection.for:1612 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE xsection.for:1613 */
/*<       return >*/
			    return 0;
/* SOURCE xsection.for:1614 */
/*<       endif >*/
			}
/* SOURCE xsection.for:1616 */
/*<       p=(xarg(k)-x(js-1))/(x(js)-x(js-1)) >*/
			p = static_cast<double>((static_cast<double>(xarg[k]) - x[js - 1])) / (static_cast<double>(x[js]) - x[js - 1]);
/* SOURCE xsection.for:1617 */
/*<       zval=z(js-1)+p*(z(js)-z(js-1)) >*/
			zval = static_cast<double>(feq_gen_z_d_[js - 1]) + static_cast<double>(p) * (static_cast<double>(feq_gen_z_d_[js]) - feq_gen_z_d_[js - 1]);
/*                WRITE(STDOUT,*) ' ADDING POINT AT P=',P,' ZVAL=',ZVAL */
/*               THE SUBSECTION IS THE SAME AS THAT FOR THE */
/*               LEFT-MOST POINT ON THE LINE.  THIS IS TRUE FOR */
/*               THE LINE SEGMENT N ALSO. */
/* SOURCE xsection.for:1624 */
/*<       sbval=sb(js-1) >*/
			sbval = sb[js - 1];
/* SOURCE xsection.for:1625 */
/*<       lsnval=lsn(js-1) >*/
			lsnval = lsn[js - 1];
/*               MOVE VALUES OUT OF THE WAY TO MAKE ROOM FOR THE INSERTION */
/* SOURCE xsection.for:1628 */
/*<       do100j=npnt,js,-1 >*/
			feq_gen_i_d_3 = js;
			for (j = *npnt; j >= feq_gen_i_d_3; --j) {
/* SOURCE xsection.for:1629 */
/*<       x(j+1)=x(j) >*/
			    x[j + 1] = x[j];
/* SOURCE xsection.for:1630 */
/*<       z(j+1)=z(j) >*/
			    feq_gen_z_d_[j + 1] = feq_gen_z_d_[j];
/* SOURCE xsection.for:1631 */
/*<       sb(j+1)=sb(j) >*/
			    sb[j + 1] = sb[j];
/* SOURCE xsection.for:1632 */
/*<       lsn(j+1)=lsn(j) >*/
			    lsn[j + 1] = lsn[j];
/* SOURCE xsection.for:1633 */
/*<   100 continue >*/
/* L100: */
			}
/* SOURCE xsection.for:1634 */
/*<       npnt=npnt+1 >*/
			++(*npnt);
/*               NOW STORE THE VALUES */
/* SOURCE xsection.for:1638 */
/*<       x(js)=xarg(k) >*/
			x[js] = xarg[k];
/* SOURCE xsection.for:1639 */
/*<       z(js)=zval >*/
			feq_gen_z_d_[js] = zval;
/* SOURCE xsection.for:1640 */
/*<       sb(js)=sbval >*/
			sb[js] = sbval;
/* SOURCE xsection.for:1641 */
/*<       lsn(js)=lsnval >*/
			lsn[js] = lsnval;
/*               JUMP OUT OF THE LOOP AND GO TO THE NEXT OFFSET */
/*               TO ADD */
/* SOURCE xsection.for:1645 */
/*<       goto500 >*/
			goto L500;
/* SOURCE xsection.for:1646 */
/*<       else >*/
		    } else {
/*               JUMP OUT OF THE LOOP AND GO TO THE NEXT OFFSET */
/*               TO ADD */
/* SOURCE xsection.for:1649 */
/*<       goto500 >*/
			goto L500;
/* SOURCE xsection.for:1650 */
/*<       endif >*/
		    }
/* SOURCE xsection.for:1651 */
/*<       endif >*/
		}
/* SOURCE xsection.for:1652 */
/*<   200 continue >*/
/* L200: */
	    }
/* SOURCE xsection.for:1654 */
/*<   500 continue >*/
L500:
	    ;
	}
/*        do i=1,npnt */
/*          write(stdout,54) i, x(i), z(i), sb(i), lsn(i) */
/* 54    format(i5,f12.3,f12.3,i5,f10.3) */
/*        enddo */
/* SOURCE xsection.for:1661 */
/*<       endif >*/
    }
/* SOURCE xsection.for:1662 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:1663 */
/*<       end >*/
} /* inspt_ */




/* SOURCE xsection.for:1667 */
/*<       subroutinetran() >*/
/* Subroutine */ int tran_()
{
    /* Local variables */
    integer j;
#define dvec (feq::BitView<integer>(&xscomd_1, sizeof(xscomd_1)))
#define uvec (feq::BitView<integer>(&xscomu_1, sizeof(xscomu_1)))

/*     + + + PURPOSE + + + */
/*     Transfer contents of XSCOMU to XSCOMD */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:1673 */
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
/* INCLUDE xsection.for:1674 */
/*     COMMON FOR THE DOWNSTREAM CROSS SECTION */

/* SOURCE xscomd.cmn:3 */
/*<       integernpntd,nsubd,navmd,tabd,ndepd,mxpntd,usgsd,snflgd >*/
/* SOURCE xscomd.cmn:4 */
/*<       integersbd(pmxpnt),nvard(pmxsub),nnyd(pmxsub) >*/
/* SOURCE xscomd.cmn:5 */
/*<       realstatd,zmind,zmaxd >*/
/* SOURCE xscomd.cmn:6 */
/*<        >*/

/* SOURCE xscomd.cmn:10 */
/*<        >*/
/*     SNFLGD- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points.  For piecewise */
/*             constant variation, the value of sinuousity for the line */
/*             segment is given at the start point for the line segment. */
/*     SND- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSND- LINE SEGMENT N VALUE */
/*     NVARD- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: N IS CONSTANT, */
/*           N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*     NATYD-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATND- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYD- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS. */
/*     YSMXD- MAXIMUM DEPTH IN EACH SUBSECTION */
/* INCLUDE xsection.for:1675 */
/*     COMMON FOR THE UPSTREAM CROSS SECTION */

/* SOURCE xscomu.cmn:3 */
/*<       integernpntu,nsubu,navmu,tabu,ndepu,mxpntu,usgsu,snflgu >*/
/* SOURCE xscomu.cmn:4 */
/*<       integersbu(pmxpnt),nvaru(pmxsub),nnyu(pmxsub) >*/
/* SOURCE xscomu.cmn:5 */
/*<       realstatu,zminu,zmaxu >*/
/* SOURCE xscomu.cmn:6 */
/*<        >*/

/* SOURCE xscomu.cmn:10 */
/*<        >*/
/*     SNFLGU- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points. */
/*     SNU- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSNU- LINE SEGMENT N VALUE */
/*     NVARU- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: 0-N IS CONSTANT, */
/*           1-N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           2-N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*           IF N VARIES WITH DEPTH, THE N VALUE APPLIES TO THE WHOLE */
/*           SUBSECTION.  NO VARIATION OF ROUGHNESS PERMITTED ON LINE SEGMENTS */
/*           IN THE SUBSECTION. */
/*     NATYU-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATNU- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYU- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS.  VALUE IS ZERO IF NVARU FOR THE */
/*          SUBSECTION IS ZERO.  THE N DEPTH PAIR AT ZERO DEPTH IS STORED */
/*          AND COUNTED WITH NVARU > 0 FOR THE SUBSECTION. */
/*     YSMXU- MAXIMUM DEPTH IN EACH SUBSECTION. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1678 */
/*<       integerj >*/
/* SOURCE xsection.for:1679 */
/*<       integerdvec(xscoml),uvec(xscoml) >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE xsection.for:1682 */
/*<       equivalence(npntu,uvec(1)),(npntd,dvec(1)) >*/
/* *********************************************************************** */
/* SOURCE xsection.for:1684 */
/*<       do100j=1,xscoml >*/
    for (j = 1; j <= 22791; ++j) {
/* SOURCE xsection.for:1685 */
/*<       dvec(j)=uvec(j) >*/
	dvec[j - 1] = uvec[j - 1];
/* SOURCE xsection.for:1686 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE xsection.for:1687 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:1688 */
/*<       end >*/
} /* tran_ */

#undef uvec
#undef dvec





/* SOURCE xsection.for:1692 */
/*<       subroutinesetopt(stdout,cin,savopt,outopt,monton,betopt) >*/
/* Subroutine */ int setopt_(integer *stdout, char *cin, char *savopt, char *
	outopt, char *monton, char *betopt, ftnlen cin_len, ftnlen savopt_len,
	 ftnlen outopt_len, ftnlen monton_len, ftnlen betopt_len)
{
    /* Initialized data */

    static char tab[8*26+1] = "EXTEND  MONOTONENEWBETA NEWBETAENEWBETAMNOEXT\
ENDNOOUT   NOSAVE  OLDBETA OUT1    OUT12   OUT20   OUT21   OUT22   OUT23   O\
UT24   OUT25   SAVE    SAVE1   SAVE12  SAVE20  SAVE21  SAVE22  SAVE23  SAVE2\
4  SAVE25  ";
    static integer tabval[26] = { 6,5,4,4,4,7,3,1,4,3,3,3,3,3,3,3,3,2,1,1,1,1,
	    1,1,1,1 };

    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:591* \002,a8,\002 is a bad cross sect\
ion option.\002)";
    static char fmt_52[] = "(/,\002 *BUG:XXX* Invalid index=\002,i5,\002 for\
 name=\002,a8,\002 in\002,\002 subroutine SETOPT.\002)";

    /* Builtin functions */
    integer i_len(char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, is, it, iend;
    char feq_gen_name_d_[8];
    extern /* Subroutine */ int binser_(char *, integer *, char *, integer *, 
	    ftnlen, ftnlen), getnxt_(char *, integer *, integer *, char *, 
	    ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__191 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__192 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Set the options for the output and saving of the cross section */
/*     tables. */
/* SOURCE xsection.for:1700 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:1703 */
/*<       integerstdout >*/
/* SOURCE xsection.for:1704 */
/*<       characterbetopt*8,cin*(*),monton*8,outopt*8,savopt*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CIN    - Character string containing options for cross section */
/*              function table processing */
/*     SAVOPT - Function table saving option */
/*     OUTOPT - Output option for the table file for cross section function */
/*               tables */
/*     MONTON - Monotonicity flag value */
/*     BETOPT - Option for computing flux coefficients and critical flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:1717 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE xsection.for:1720 */
/*<       integernopt >*/
/* SOURCE xsection.for:1721 */
/*<       parameter(nopt=26) >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE xsection.for:1724 */
/*<       integertabval(nopt) >*/
/* SOURCE xsection.for:1725 */
/*<       charactertab(nopt)*8 >*/
/* SOURCE xsection.for:1726 */
/*<       savetab,tabval >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1729 */
/*<       integeri,iend,is,it >*/
/* SOURCE xsection.for:1730 */
/*<       charactername*8 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE xsection.for:1733 */
/*<       intrinsiclen >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:1736 */
/*<       externalbinser,getnxt >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:1739 */
/*<        >*/
/* SOURCE xsection.for:1746 */
/*<       datatabval/6,5,4,4,4,7,3,1,4,3,3,3,3,3,3,3,3,2,1,1,1,1,1,1,1,1/ >*/
/* SOURCE xsection.for:1755 */
/*<    50 format(' *ERR:591* ',a8,' is a bad cross section option.') >*/
/* L50: */
/* SOURCE xsection.for:1756 */
/*<    52  >*/
/* L52: */
/* *********************************************************************** */
/* SOURCE xsection.for:1759 */
/*<       iend=len(cin) >*/
    iend = i_len(cin, cin_len);
/* SOURCE xsection.for:1760 */
/*<       is=1 >*/
    is = 1;
/*     SET DEFAULTS */
/* SOURCE xsection.for:1764 */
/*<       savopt='NOSAVE' >*/
    s_copy(savopt, const_cast<char*>("NOSAVE"), (ftnlen)8, (ftnlen)6);
/* SOURCE xsection.for:1765 */
/*<       outopt='OUT1' >*/
    s_copy(outopt, const_cast<char*>("OUT1"), (ftnlen)8, (ftnlen)4);
/* SOURCE xsection.for:1766 */
/*<       monton=' ' >*/
    s_copy(monton, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE xsection.for:1767 */
/*<       betopt='OLDBETA' >*/
    s_copy(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7);
/* SOURCE xsection.for:1769 */
/*<   100 continue >*/
L100:
/* SOURCE xsection.for:1770 */
/*<       callgetnxt(cin,is,it,name) >*/
    getnxt_(cin, &is, &it, feq_gen_name_d_, cin_len, (ftnlen)8);
/* SOURCE xsection.for:1773 */
/*<       is=it >*/
    is = it;
/* SOURCE xsection.for:1774 */
/*<       if(name.ne.' ')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) != 0) {
/*         LOOKUP THE OPTION NAME AND USE THE TABULATED VALUE */
/*         TO TAKE AN ACTION. */
/* SOURCE xsection.for:1778 */
/*<       callbinser(name,nopt,tab,i) >*/
	binser_(feq_gen_name_d_, &feq_gen_c_d_26, tab, &feq_gen_i_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:1781 */
/*<       if(i.eq.0)then >*/
	if (feq_gen_i_d_ == 0) {
/* SOURCE xsection.for:1782 */
/*<       write(stdout,50)name >*/
	    feq_gen_io_d__191.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__191);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)8);
	    e_wsfe();
/* SOURCE xsection.for:1783 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:1784 */
/*<       i=tabval(i) >*/
	    feq_gen_i_d_ = tabval[feq_gen_i_d_ - 1];
/* SOURCE xsection.for:1785 */
/*<       goto(1,2,3,4,5,6,7),i >*/
	    switch (feq_gen_i_d_) {
		case 1:  goto L1;
		case 2:  goto L2;
		case 3:  goto L3;
		case 4:  goto L4;
		case 5:  goto L5;
		case 6:  goto L6;
		case 7:  goto L7;
	    }
/* SOURCE xsection.for:1786 */
/*<       write(stdout,52)i,name >*/
	    feq_gen_io_d__192.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__192);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)8);
	    e_wsfe();
/* SOURCE xsection.for:1787 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:1789 */
/*<     1 continue >*/
L1:
/*             MOST OF THE SAVE OPTIONS. */
/* SOURCE xsection.for:1791 */
/*<       savopt=name >*/
	    s_copy(savopt, feq_gen_name_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:1792 */
/*<       goto49 >*/
	    goto L49;
/* SOURCE xsection.for:1794 */
/*<     2 continue >*/
L2:
/*             SAVE BY ITSELF WITHOUT A SUFFIX NUMBER */
/* SOURCE xsection.for:1796 */
/*<       savopt='SAVE1' >*/
	    s_copy(savopt, const_cast<char*>("SAVE1"), (ftnlen)8, (ftnlen)5);
/* SOURCE xsection.for:1797 */
/*<       goto49 >*/
	    goto L49;
/* SOURCE xsection.for:1799 */
/*<     3 continue >*/
L3:
/*             OUTPUT OPTIONS */
/* SOURCE xsection.for:1801 */
/*<       outopt=name >*/
	    s_copy(outopt, feq_gen_name_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:1802 */
/*<       goto49 >*/
	    goto L49;
/* SOURCE xsection.for:1804 */
/*<     4 continue >*/
L4:
/*             VELOCITY COEFFICIENT FLAGS */
/* SOURCE xsection.for:1806 */
/*<       betopt=name >*/
	    s_copy(betopt, feq_gen_name_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:1807 */
/*<       goto49 >*/
	    goto L49;
/* SOURCE xsection.for:1809 */
/*<     5 continue >*/
L5:
/*             MONOTONICITY FLAG */
/* SOURCE xsection.for:1811 */
/*<       monton=name >*/
	    s_copy(monton, feq_gen_name_d_, (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:1812 */
/*<       goto49 >*/
	    goto L49;
/* SOURCE xsection.for:1814 */
/*<     6 continue >*/
L6:
/*             SET EXTEND OPTION */
/* SOURCE xsection.for:1816 */
/*<       extend=1 >*/
	    nrdzcm_1.extend = 1;
/* SOURCE xsection.for:1817 */
/*<       goto49 >*/
	    goto L49;
/* SOURCE xsection.for:1819 */
/*<     7 continue >*/
L7:
/*             CLEAR THE EXTEND OPTION */
/* SOURCE xsection.for:1821 */
/*<       extend=0 >*/
	    nrdzcm_1.extend = 0;
/* SOURCE xsection.for:1822 */
/*<       goto49 >*/
	    goto L49;
/* SOURCE xsection.for:1824 */
/*<    49 continue >*/
L49:
/* SOURCE xsection.for:1825 */
/*<       endif >*/
	    ;
	}
/* SOURCE xsection.for:1826 */
/*<       endif >*/
    }
/* SOURCE xsection.for:1827 */
/*<       if(is.ge.iend)goto200 >*/
    if (is >= iend) {
	goto L200;
    }
/* SOURCE xsection.for:1828 */
/*<       goto100 >*/
    goto L100;
/* SOURCE xsection.for:1829 */
/*<   200 continue >*/
L200:
/* SOURCE xsection.for:1831 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:1832 */
/*<       end >*/
} /* setopt_ */




/* SOURCE xsection.for:1836 */
/*<        >*/
/* Subroutine */ int infqxe_(integer *stdin, integer *stdout, integer *feq_storage_tabdir,
	 integer *eflag, integer *tab, real *stat, integer *npnt, integer *
	nsub, real *feq_storage_x, real *feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real *feq_storage_n, real *left, real *
	right, char *savopt, char *outopt, char *betopt, real *zmax, real *
	feq_storage_lsn, integer *feq_storage_nvar, real *feq_storage_naty, real *feq_storage_yatn, integer *feq_storage_nny, char *zone, 
	char *hgrid, char *vdatum, char *unitsys, char *basis, ftnlen 
	savopt_len, ftnlen outopt_len, ftnlen betopt_len, ftnlen zone_len, 
	ftnlen hgrid_len, ftnlen vdatum_len, ftnlen unitsys_len, ftnlen 
	basis_len)
{
    /* Initialized data */

    static integer vtype[20] = { 2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
    static integer basnum = 2;

    /* Format strings */
    static char fmt_4[] = "(a80)";
    static char fmt_51[] = "(/,\002 TABID=\002,a,5(1x,a8))";
    static char fmt_52[] = "(\002 VARN=\002,a4,\002  Hor. scale factor=\002,\
f10.3,\002 Vert. shift=\002,f10.3,/,\002  Vert. scale factor=\002,f10.3,\002\
 Hor. shift=\002,f10.3)";
    static char fmt_53[] = "(\002 STATION=\002,f10.3,\002 LEFT=\002,f10.1\
,\002 RIGHT=\002,f10.1)";
    static char fmt_54[] = "(\002 STATION=\002,f10.3)";
    static char fmt_55[] = "(1x,a4,i5,6f6.3,1x,/,(10x,6f6.3))";
    static char fmt_56[] = "(1x,a80)";
    static char fmt_57[] = "(1x,f10.3,f10.2,i5,f6.3)";
    static char fmt_59[] = "(\002 *ERR:505* SUBSECTION NUMBER TOO LARGE AT O\
FFSET=\002,f10.1)";
    static char fmt_60[] = "(\002 *WRN:501* SUBSECTION VALUE FOR FIRST POINT\
 IS\002,\002 MISSING.  SUBSECTION=1 ASSUMED.\002)";
    static char fmt_61[] = "(\002 *ERR:506* ONLY ONE POINT GIVEN ON BOUNDARY\
 OF THE\002,\002 CROSS SECTION.\002)";
    static char fmt_62[] = "(\002 *ERR:507* NUMBER OF POINTS IN CROSS SECTIO\
N >\002,i5)";
    static char fmt_63[] = "(\002 Invert shift=\002,f10.3,\002 Water-surface\
 tabid=\002,a)";
    static char fmt_65[] = "(\002 ZONE=\002,a8,\002 HGRID=\002,a8,\002 VDATU\
M=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8)";
    static char fmt_67[] = "(/,\002 *WRN:554* Extending left end of cross se\
ction\002,\002 by \002,f8.3)";
    static char fmt_68[] = "(/,\002 *WRN:555* Extending right end of cross s\
ection\002,\002 by \002,f8.3)";
    static char fmt_69[] = "(/,\002 *WRN:556* Some point in cross section hi\
gher than\002,\002 either end.\002,/,10x,\002All area above minimum end elev\
ation\002,\002 is ignored.\002)";
    static char fmt_70[] = "(/,\002 *ERR:647* Manning's N = 0 in subsectio\
n\002,i5,/,11x,\002Value set to 1.0.  Please correct and recompute.\002)";
    static char fmt_72[] = "(/,\002 *ERR:556* Found only\002,i3,\002 values \
on line but \002,\002expected\002,i3)";
    static char fmt_74[] = "(/,\002 *ERR:557* Vertical variation of rougness\
 coef.\002,\002 already defined\002,/,10x,\002 in subsection number\002,i4)";
    static char fmt_76[] = "(/,\002 *ERR:564* Missing n-value at depth numbe\
r \002,i3)";
    static char fmt_78[] = "(/,\002 *ERR:567*\002,a4,\002 is invalid option \
for vertical \002,\002variation of roughness.\002)";
    static char fmt_80[] = "(1x,f10.3,f10.2,i5,f6.3,5(f6.2,f6.3))";
    static char fmt_82[] = "(1x,f10.3,f10.2,i5)";
    static char fmt_84[] = "(1x,\002    OFFSET ELEVATION SUBS    N0    Y1   \
 N1    Y2\002,\002    N2    Y3    N3    Y4    N4    Y5    N5\002)";
    static char fmt_86[] = "(\002 GISID=\002,a16,\002 EASTING=\002,f15.3,\
\002 NORTHING=\002,f15.3)";
    static char fmt_87[] = "(\002  Processing FEQXEXT TabId= \002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[16];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi()
	    , s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_i_d_, j, l;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer nn;
    extern /* Subroutine */ int feq_gen_adj_invert_d_(integer *, integer *, real *, 
	    integer *, real *, real *, integer *);
    integer opt;
    char head[80];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer clen[20];
    char cval[256*20], line[80];
    integer ival[20], mval, navm, isub;
    real rval[20], xold;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char term[1*20], varn[4];
    real scale;
    doublereal dpval[20];
    integer ivarn, ntemp, terml[20];
    real shift;
    integer eflag2;
    char feq_gen_extend_string_d_[8];
    extern /* Subroutine */ int tabchk_(integer *, integer *, integer *, 
	    integer *, integer *), chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    real vscale;
    extern /* Subroutine */ int getval_(integer *, char *, integer *, integer 
	    *, integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    integer oldsub;
    real hshift;
    char monton[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     reasub_(integer *, integer *, integer *, real *, integer *, 
	    integer *), feq_gen_get_xsec_header_d_(integer *, integer *, integer *, 
	    integer *, char *, char *, char *, char *, integer *, real *, 
	    real *, real *, char *, integer *, real *, real *, real *, real *,
	     integer *, real *, char *, char *, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen);
    integer termcls[20];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__208 = { 0, 6, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__209 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__210 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__212 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__213 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__214 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__215 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__216 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__217 = { 0, 0, 0, fmt_63, 0 };
    static cilist feq_gen_io_d__218 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__220 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__223 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__227 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__238 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__239 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__240 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__241 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__242 = { 0, 0, 0, fmt_59, 0 };
    static cilist feq_gen_io_d__244 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__246 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__247 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__248 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__249 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__250 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__251 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__252 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__253 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__254 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__255 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__256 = { 0, 0, 0, fmt_67, 0 };
    static cilist feq_gen_io_d__257 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__258 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__260 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__261 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__262 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__263 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__264 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__265 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__266 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__267 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__268 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input cross section in FEQ extended format */
/* SOURCE xsection.for:1847 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE xsection.for:1850 */
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
/* SOURCE xsection.for:1853 */
/*<       integereflag,npnt,nsub,stdin,stdout,tab >*/
/* SOURCE xsection.for:1854 */
/*<       integernny(pmxsub),nvar(pmxsub),sb(pmxpnt),tabdir(*) >*/
/* SOURCE xsection.for:1855 */
/*<        >*/
/* SOURCE xsection.for:1857 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TAB    - Table number */
/*     STAT   - Station value */
/*     NPNT   - Number of points on boundary of a cross section */
/*     NSUB   - Number of subsections */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     N      - Manning's n values */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     SAVOPT - Function table saving option */
/*     OUTOPT - Output option for the table file for cross section function */
/*               tables */
/*     BETOPT - Option for computing flux coefficients and critical flow */
/*     ZMAX   - Maximum elevation */
/*     LSN    - Line segment Manning's n value */
/*     NVAR   - Flag for variation of Manning's n in each subsection */
/*     NATY   - Mannings's n value at depth in YATN */
/*     YATN   - Depth values for the Manning's n values in NATY */
/*     NNY    - Number of values for Manning's n variation with depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:1890 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE xsection.for:1891 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE xsection.for:1892 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/* INCLUDE xsection.for:1893 */
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
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE xsection.for:1896 */
/*<       integernval >*/
/* SOURCE xsection.for:1897 */
/*<       parameter(nval=20) >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE xsection.for:1900 */
/*<       integerbasnum,vtype(nval) >*/
/* SOURCE xsection.for:1901 */
/*<       savebasnum,vtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:1904 */
/*<       integereflag2,i,isub,ivarn,j,mval,nn,ntemp,oldsub,opt,navm,l >*/
/* SOURCE xsection.for:1906 */
/*<       integerclen(nval),ival(nval),terml(nval),termcls(nval) >*/
/* SOURCE xsection.for:1907 */
/*<       realrval(nval),hshift,scale,shift,xold,vscale >*/
/* SOURCE xsection.for:1908 */
/*<       doubleprecisiondpval(nval) >*/
/* SOURCE xsection.for:1909 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE xsection.for:1913 */
/*<       intrinsicabs,max,min,mod >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:1916 */
/*<       integerlenstr >*/
/* SOURCE xsection.for:1917 */
/*<       characterget_tabid*16 >*/
/* SOURCE xsection.for:1918 */
/*<       externalgetval,inline,reasub,setopt,tabchk,get_tabid,lenstr >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE xsection.for:1921 */
/*<       datavtype/2*2,1,17*2/,basnum/2/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> nny(feq_storage_nny, 1);

    feq::IndexedPointer<real> yatn(feq_storage_yatn, 10);

    feq::IndexedPointer<real> naty(feq_storage_naty, 10);

    feq::IndexedPointer<integer> nvar(feq_storage_nvar, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* SOURCE xsection.for:1924 */
/*<     1 format(7x,i5,a) >*/
/* L1: */
/* SOURCE xsection.for:1925 */
/*<     2 format(8x,f10.0,6x,f10.0,7x,f10.0) >*/
/* L2: */
/* SOURCE xsection.for:1926 */
/*<     3 format(a4,i5,6f10.0) >*/
/* L3: */
/* SOURCE xsection.for:1927 */
/*<     4 format(a80) >*/
/* L4: */
/* 6    FORMAT(5X,A4,7X,F10.0,7X,F10.0) */
/* SOURCE xsection.for:1929 */
/*<     6 format(5x,a4,7x,f10.0,7x,f10.0,8x,f10.0,8x,f10.0) >*/
/* L6: */
/* SOURCE xsection.for:1930 */
/*<    31 format(9x,6f10.0) >*/
/* L31: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:1933 */
/*<    51 format(/,' TABID=',a,5(1x,a8)) >*/
/* L51: */
/* SOURCE xsection.for:1934 */
/*<    52  >*/
/* L52: */
/* SOURCE xsection.for:1937 */
/*<    53 format(' STATION=',f10.3,' LEFT=',f10.1,' RIGHT=',f10.1) >*/
/* L53: */
/* SOURCE xsection.for:1938 */
/*<    54 format(' STATION=',f10.3) >*/
/* L54: */
/* SOURCE xsection.for:1939 */
/*<    55 format(1x,a4,i5,6f6.3,1x,/,(10x,6f6.3)) >*/
/* L55: */
/* SOURCE xsection.for:1940 */
/*<    56 format(1x,a80) >*/
/* L56: */
/* SOURCE xsection.for:1941 */
/*<    57 format(1x,f10.3,f10.2,i5,f6.3) >*/
/* L57: */
/* SOURCE xsection.for:1942 */
/*<    58 format(' *ERR:504* NUMBER OF SUBSECTIONS=',i5,' > ',i5) >*/
/* L58: */
/* SOURCE xsection.for:1943 */
/*<    59 format(' *ERR:505* SUBSECTION NUMBER TOO LARGE AT OFFSET=',f10.1) >*/
/* L59: */
/* SOURCE xsection.for:1945 */
/*<    60  >*/
/* L60: */
/* SOURCE xsection.for:1947 */
/*<    61  >*/
/* L61: */
/* SOURCE xsection.for:1949 */
/*<    62 format(' *ERR:507* NUMBER OF POINTS IN CROSS SECTION >',i5) >*/
/* L62: */
/* SOURCE xsection.for:1950 */
/*<    63 format(' Invert shift=',f10.3,' Water-surface tabid=',a) >*/
/* L63: */
/* SOURCE xsection.for:1951 */
/*<    65  >*/
/* L65: */
/* SOURCE xsection.for:1953 */
/*<    66  >*/
/* L66: */
/* SOURCE xsection.for:1955 */
/*<    67  >*/
/* L67: */
/* SOURCE xsection.for:1957 */
/*<    68  >*/
/* L68: */
/* SOURCE xsection.for:1959 */
/*<    69  >*/
/* L69: */
/* SOURCE xsection.for:1962 */
/*<    70  >*/
/* L70: */
/* SOURCE xsection.for:1964 */
/*<    72  >*/
/* L72: */
/* SOURCE xsection.for:1966 */
/*<    74  >*/
/* L74: */
/* SOURCE xsection.for:1968 */
/*<    76 format(/,' *ERR:564* Missing n-value at depth number ',i3) >*/
/* L76: */
/* SOURCE xsection.for:1969 */
/*<    78  >*/
/* L78: */
/* SOURCE xsection.for:1971 */
/*<    80 format(1x,f10.3,f10.2,i5,f6.3,5(f6.2,f6.3)) >*/
/* L80: */
/* SOURCE xsection.for:1972 */
/*<    82 format(1x,f10.3,f10.2,i5) >*/
/* L82: */
/* SOURCE xsection.for:1973 */
/*<    84  >*/
/* L84: */
/* SOURCE xsection.for:1975 */
/*<    86 format(' GISID=',a16,' EASTING=',f15.3,' NORTHING=',f15.3) >*/
/* L86: */
/* SOURCE xsection.for:1976 */
/*<    87 format('  Processing FEQXEXT TabId= ',a) >*/
/* L87: */
/* *********************************************************************** */
/*     CLEAR THE LOCAL ERROR FLAG FOR THE GETVAL SUBROUTINE */
/* SOURCE xsection.for:1979 */
/*<       eflag2=0 >*/
    eflag2 = 0;
/* SOURCE xsection.for:1981 */
/*<        >*/
    feq_gen_get_xsec_header_d_(stdin, stdout, eflag, tab, savopt, outopt, monton, 
	    betopt, &nrdzcm_1.extend, stat, left, right, varn, &navm, &scale, 
	    &shift, &vscale, &hshift, nsub, &n[1], zone, hgrid, vdatum, 
	    unitsys, basis, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)4, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:1986 */
/*<       if(extend.eq.0)then >*/
    if (nrdzcm_1.extend == 0) {
/* SOURCE xsection.for:1987 */
/*<       extend_string='NOEXTEND' >*/
	s_copy(feq_gen_extend_string_d_, const_cast<char*>("NOEXTEND"), (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:1988 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:1989 */
/*<       extend_string='EXTEND' >*/
	s_copy(feq_gen_extend_string_d_, const_cast<char*>("EXTEND"), (ftnlen)8, (ftnlen)6);
/* SOURCE xsection.for:1990 */
/*<       endif >*/
    }
/* SOURCE xsection.for:1991 */
/*<       tabid=get_tabid(abs(tab)) >*/
    feq_gen_i_d_1 = abs(*tab);
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
    s_copy(xtaddc_1.tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE xsection.for:1992 */
/*<       l=lenstr(tabid) >*/
    l = lenstr_(xtaddc_1.tabid, (ftnlen)16);
/* SOURCE xsection.for:1993 */
/*<       write(*,87)tabid(1:l) >*/
    s_wsfe(&feq_gen_io_d__208);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
    e_wsfe();
/* SOURCE xsection.for:1994 */
/*<        >*/
    feq_gen_io_d__209.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__209);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, l);
    do_fio(&feq_gen_c_d_1, savopt, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, outopt, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, betopt, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, feq_gen_extend_string_d_, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, monton, (ftnlen)8);
    e_wsfe();
/* SOURCE xsection.for:1996 */
/*<       if(zone/='NONE')then >*/
    if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0) {
/* SOURCE xsection.for:1997 */
/*<       write(stdout,65)zone,hgrid,vdatum,unitsys,basis >*/
	feq_gen_io_d__210.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__210);
	do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	e_wsfe();
/* SOURCE xsection.for:1998 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2000 */
/*<       if(tab.lt.0)then >*/
    if (*tab < 0) {
/* SOURCE xsection.for:2001 */
/*<       slot=0.03 >*/
	nrdzcm_1.slot = (float).03;
/* SOURCE xsection.for:2002 */
/*<       tab=-tab >*/
	*tab = -(*tab);
/* SOURCE xsection.for:2003 */
/*<       nocm=1 >*/
	nrdzcm_1.nocm = 1;
/* SOURCE xsection.for:2004 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:2005 */
/*<       nocm=0 >*/
	nrdzcm_1.nocm = 0;
/* SOURCE xsection.for:2006 */
/*<       slot=0.0 >*/
	nrdzcm_1.slot = (float)0.;
/* SOURCE xsection.for:2007 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2008 */
/*<       if(tab.ge.0)calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    if (*tab >= 0) {
	tabchk_(stdout, &feq_gen_c_d_10002, tab, &tabdir[1], eflag);
    }
/* SOURCE xsection.for:2012 */
/*<       left=scale*left >*/
    *left = static_cast<double>(scale) * *left;
/* SOURCE xsection.for:2013 */
/*<       right=scale*right >*/
    *right = static_cast<double>(scale) * *right;
/* SOURCE xsection.for:2014 */
/*<       if(varn.eq.' ')then >*/
    if (s_cmp(varn, const_cast<char*>(" "), (ftnlen)4, (ftnlen)1) == 0) {
/* SOURCE xsection.for:2015 */
/*<       varn='HYDY' >*/
	s_copy(varn, const_cast<char*>("HYDY"), (ftnlen)4, (ftnlen)4);
/* SOURCE xsection.for:2016 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2017 */
/*<       if(varn.eq.'HYDY')then >*/
    if (s_cmp(varn, const_cast<char*>("HYDY"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE xsection.for:2018 */
/*<       ivarn=1 >*/
	ivarn = 1;
/* SOURCE xsection.for:2019 */
/*<       elseif(varn.eq.'MAXY')then >*/
    } else if (s_cmp(varn, const_cast<char*>("MAXY"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE xsection.for:2020 */
/*<       ivarn=2 >*/
	ivarn = 2;
/* SOURCE xsection.for:2021 */
/*<       elseif(varn.eq.'NCON')then >*/
    } else if (s_cmp(varn, const_cast<char*>("NCON"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE xsection.for:2022 */
/*<       ivarn=0 >*/
	ivarn = 0;
/* SOURCE xsection.for:2023 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:2024 */
/*<       write(stdout,78)varn >*/
	feq_gen_io_d__212.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__212);
	do_fio(&feq_gen_c_d_1, varn, (ftnlen)4);
	e_wsfe();
/* SOURCE xsection.for:2025 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE xsection.for:2026 */
/*<       ivarn=1 >*/
	ivarn = 1;
/* SOURCE xsection.for:2027 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2028 */
/*<       if(gisid.ne.' ')then >*/
    if (s_cmp(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE xsection.for:2029 */
/*<       write(stdout,86)gisid,easting,northing >*/
	feq_gen_io_d__213.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__213);
	do_fio(&feq_gen_c_d_1, xtaddc_1.gisid, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.easting, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.northing, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE xsection.for:2030 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2031 */
/*<       if(left.ge.right)then >*/
    if (*left >= *right) {
/* SOURCE xsection.for:2032 */
/*<       write(stdout,54)stat >*/
	feq_gen_io_d__214.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__214);
	do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:2033 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:2034 */
/*<       write(stdout,53)stat,left,right >*/
	feq_gen_io_d__215.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__215);
	do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&(*left), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&(*right), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:2035 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2036 */
/*<       write(stdout,52)varn,scale,shift,vscale,hshift >*/
    feq_gen_io_d__216.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__216);
    do_fio(&feq_gen_c_d_1, varn, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, (char *)&scale, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&vscale, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&hshift, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:2037 */
/*<       if(dinvert.ne.0.0)then >*/
    if (xtadd_1.dinvert != (float)0.) {
/* SOURCE xsection.for:2038 */
/*<       write(stdout,63)dinvert,ws_tabid >*/
	feq_gen_io_d__217.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__217);
	do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.dinvert, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, xtaddc_1.feq_gen_ws_tabid_d_, (ftnlen)16);
	e_wsfe();
/* SOURCE xsection.for:2039 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2040 */
/*<       write(stdout,55)'NSUB',nsub,(n(j),j=1,nsub) >*/
    feq_gen_io_d__218.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__218);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("NSUB"), (ftnlen)4);
    do_fio(&feq_gen_c_d_1, (char *)&(*nsub), (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = *nsub;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&n[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* SOURCE xsection.for:2042 */
/*<       do131j=1,nsub >*/
    feq_gen_i_d_1 = *nsub;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:2043 */
/*<       if(n(j).le.0.0)then >*/
	if (n[j] <= (float)0.) {
/* SOURCE xsection.for:2044 */
/*<       write(stdout,70)j >*/
	    feq_gen_io_d__220.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__220);
	    do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE xsection.for:2045 */
/*<       n(j)=1.0 >*/
	    n[j] = (float)1.;
/* SOURCE xsection.for:2046 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:2047 */
/*<       endif >*/
	}
/*       SET THE VARIATION OF MANNING'S N FLAG TO INITIAL VALUE */
/*       Initial value assumes that n is constant with changes in */
/*       depth. */
/* SOURCE xsection.for:2051 */
/*<       nvar(j)=0 >*/
	nvar[j] = 0;
/* SOURCE xsection.for:2052 */
/*<   131 continue >*/
/* L131: */
    }
/* SOURCE xsection.for:2054 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:2057 */
/*<       read(line,4,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*      WRITE(STDOUT,56) HEAD */
/* SOURCE xsection.for:2059 */
/*<       write(stdout,84) >*/
    feq_gen_io_d__223.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__223);
    e_wsfe();
/*     GET THE CO-ORDINATES ON THE BOUNDARY OF THE CROSS SECTION */
/*     SET THE VALUE FOR CHECKING FOR MONOTONE VARIATION OF OFFSET */
/* SOURCE xsection.for:2065 */
/*<       xold=-1.e30 >*/
    xold = (float)-1e30;
/* SOURCE xsection.for:2067 */
/*<       npnt=0 >*/
    *npnt = 0;
/* SOURCE xsection.for:2068 */
/*<       zmax=-1.e30 >*/
    *zmax = (float)-1e30;
/*     SET THE SUB SECTION NUMBER DEFAULT */
/* SOURCE xsection.for:2071 */
/*<       do100i=1,pmxpnt >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 999; ++feq_gen_i_d_) {
/* SOURCE xsection.for:2072 */
/*<       sb(i)=0 >*/
	sb[feq_gen_i_d_] = 0;
/* SOURCE xsection.for:2073 */
/*<   100 continue >*/
/* L100: */
    }
/*     THE OLD SUBSECTION FLAG TO USE DURING OUTPUT */
/* SOURCE xsection.for:2076 */
/*<       oldsub=0 >*/
    oldsub = 0;
/*     START LOOP OVER INPUT LINES DEFINING THE BOUNDARY OF THE */
/*     CROSS SECTION */
/* SOURCE xsection.for:2081 */
/*<   135 continue >*/
L135:
/* SOURCE xsection.for:2082 */
/*<       npnt=npnt+1 >*/
    ++(*npnt);
/* SOURCE xsection.for:2083 */
/*<       if(npnt.gt.pmxpnt)then >*/
    if (*npnt > 999) {
/* SOURCE xsection.for:2084 */
/*<       write(stdout,62)pmxpnt >*/
	feq_gen_io_d__227.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__227);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_999, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE xsection.for:2085 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE xsection.for:2086 */
/*<       npnt=pmxpnt >*/
	*npnt = 999;
/* SOURCE xsection.for:2087 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:2088 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2090 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/*       SET THE DEFAULT VALUES FOR THE CURRENT LINE */
/* SOURCE xsection.for:2095 */
/*<       do137i=1,nval >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 20; ++feq_gen_i_d_) {
/* SOURCE xsection.for:2096 */
/*<       rval(i)=-1.e30 >*/
	rval[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE xsection.for:2097 */
/*<   137 continue >*/
/* L137: */
    }
/* SOURCE xsection.for:2098 */
/*<       ival(3)=-2147483647 >*/
    ival[2] = -2147483647;
/* SOURCE xsection.for:2100 */
/*<       opt=0 >*/
    opt = 0;
/* SOURCE xsection.for:2101 */
/*<        >*/
    getval_(stdout, line, &feq_gen_c_d_20, &opt, vtype, ival, rval, dpval, cval, clen, 
	    &eflag2, term, terml, termcls, &mval, (ftnlen)80, (ftnlen)256, (
	    ftnlen)1);
/*       MVAL GIVES THE NUMBER OF VALUES GIVEN BY THE USER.  THIS */
/*       COUNT INCLUDES THE ASTERISK FOR A DEFAULT VALUE IN THE FIELD */
/*       AS WELL AS COMMAS USED TO DEFAULT A FIELD.  THE COUNT GIVES */
/*       THE NUMBER OF ITEMS, ACTUAL OR DEFAULT UP UNTIL THE END OF LINE */
/*       CHARACTER OR UNTIL THE END OF LINE.  MVAL GIVES MUCH OF THE */
/*       INFORMATION ABOUT WHAT THE USER HAS STATED AND INTENDED. */
/*       THERE MUST ALWAYS BE AT LEAST BASNUM VALUES INPUT.  THE EXCESS */
/*       OVER BASNUM IS THEN USED TO DECIDE WHAT TO DO WITH THE NUMBERS. */
/*       GETVAL WILL COMPLAIN ABOUT CONVERSION ERRORS.  EFLAG WILL BE */
/*       SET IF ANY ERROR CONDITION HAS BEEN FOUND. */
/*       FIRST, CHECK FOR ERRORS IN GETVAL. IF FOUND GO TO THE NEXT LINE */
/*       OF USER INPUT. */
/* SOURCE xsection.for:2121 */
/*<       if(eflag2.ne.0)then >*/
    if (eflag2 != 0) {
/*         CLEAR THE LOCAL FLAG */
/* SOURCE xsection.for:2123 */
/*<       eflag2=0 >*/
	eflag2 = 0;
/* SOURCE xsection.for:2124 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE xsection.for:2125 */
/*<       npnt=npnt-1 >*/
	--(*npnt);
/* SOURCE xsection.for:2126 */
/*<       goto135 >*/
	goto L135;
/* SOURCE xsection.for:2127 */
/*<       endif >*/
    }
/*       NOW CHECK TO MAKE SURE THAT THERE IS THE PROPER MINIMUM NUMBER OF */
/*       VALUES. */
/* SOURCE xsection.for:2133 */
/*<       if(mval.lt.basnum)then >*/
    if (mval < basnum) {
/* SOURCE xsection.for:2134 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE xsection.for:2135 */
/*<       write(stdout,72)mval,basnum >*/
	feq_gen_io_d__238.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__238);
	do_fio(&feq_gen_c_d_1, (char *)&mval, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&basnum, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE xsection.for:2136 */
/*<       eflag2=0 >*/
	eflag2 = 0;
/* SOURCE xsection.for:2137 */
/*<       npnt=npnt-1 >*/
	--(*npnt);
/* SOURCE xsection.for:2138 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:2139 */
/*<       endif >*/
    }
/*       NO ERRORS DETECTED AT THIS POINT. NOW PROCESS THE VALUES */
/*       THAT MUST ALWAYS APPEAR */
/* SOURCE xsection.for:2144 */
/*<       if(basnum.eq.2)then >*/
    if (basnum == 2) {
/*         WE HAVE ONLY OFFSET AND ELEVATION */
/* SOURCE xsection.for:2147 */
/*<       x(npnt)=scale*rval(1)+hshift >*/
	x[*npnt] = static_cast<double>(static_cast<double>(scale) * rval[0]) + hshift;
/* SOURCE xsection.for:2148 */
/*<       z(npnt)=vscale*rval(2)+shift >*/
	feq_gen_z_d_[*npnt] = static_cast<double>(static_cast<double>(vscale) * rval[1]) + shift;
/* SOURCE xsection.for:2150 */
/*<       else >*/
    } else {
/*         WE HAVE PLANE COORDINATES PLUS ELEVATION */
/* SOURCE xsection.for:2152 */
/*<       write(stdout,*)' PLANE CO-ORDINATE OPTION MISSING' >*/
	feq_gen_io_d__239.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__239);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PLANE CO-ORDINATE OPTION MISSING"), (ftnlen)33);
	e_wsle();
/* SOURCE xsection.for:2153 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:2154 */
/*<       endif >*/
    }
/*       FIND MAXIMUM ELEVATION IN CROSS SECTION FOR LATER CHECKING */
/* SOURCE xsection.for:2158 */
/*<       zmax=max(z(npnt),zmax) >*/
/* Computing MAX */
    feq_gen_r_d_1 = feq_gen_z_d_[*npnt];
    *zmax = dmax(feq_gen_r_d_1,*zmax);
/*       CHECK FOR MONOTONICITY OF TOP WIDTH.  THIS REQUIRES THAT */
/*       THE OFFSET NEVER DECREASE. */
/* SOURCE xsection.for:2163 */
/*<       if(monton.eq.'MONOTONE')then >*/
    if (s_cmp(monton, const_cast<char*>("MONOTONE"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE xsection.for:2164 */
/*<       if(x(npnt).lt.xold)then >*/
	if (x[*npnt] < xold) {
/* SOURCE xsection.for:2165 */
/*<        >*/
	    feq_gen_io_d__240.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__240);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:508* SECTION VIOLATES MONOTONICITY A\
T OFFSET="), (ftnlen)51);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	    e_wsle();
/* SOURCE xsection.for:2167 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:2168 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2169 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2170 */
/*<       xold=x(npnt) >*/
    xold = x[*npnt];
/*       NOW, CHECK THE VARIOUS VALUES AND TAKE THE ACTIONS AS REQUIRED. */
/*       THE KEY VALUES ARE: SUBSECTION NUMBER, N0 VALUE, AND THE FIRST */
/*       DEPTH(THAT IS THE FIRST NON-ZERO DEPTH) FOR VERTICAL VARIATION */
/*       OF MANNING'S N IN A SUBSECTION. */
/* SOURCE xsection.for:2177 */
/*<       if(ival(basnum+1).lt.-1.or.ival(basnum+1).eq.0)then >*/
    if (ival[basnum] < -1 || ival[basnum] == 0) {
/*         USER OMITTED THE SUBSECTION NUMBER.  GET THE PREVIOUS */
/*         NUMBER AND USE IT IF IT EXISTS. */
/* SOURCE xsection.for:2181 */
/*<       if(npnt.eq.1)then >*/
	if (*npnt == 1) {
/*           DOES NOT EXIST.  WRITE WARNING AND FORCE SUBSECTION 1. */
/* SOURCE xsection.for:2183 */
/*<       write(stdout,60) >*/
	    feq_gen_io_d__241.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__241);
	    e_wsfe();
/* SOURCE xsection.for:2184 */
/*<       sb(1)=1 >*/
	    sb[1] = 1;
/* SOURCE xsection.for:2185 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:2186 */
/*<       sb(npnt)=sb(npnt-1) >*/
	    sb[*npnt] = sb[*npnt - 1];
/* SOURCE xsection.for:2187 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2188 */
/*<       elseif(ival(basnum+1).gt.0)then >*/
    } else if (ival[basnum] > 0) {
/*         STORE THE VALUE. */
/* SOURCE xsection.for:2191 */
/*<       if(ival(basnum+1).gt.nsub)then >*/
	if (ival[basnum] > *nsub) {
/* SOURCE xsection.for:2192 */
/*<       write(stdout,59)x(npnt) >*/
	    feq_gen_io_d__242.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__242);
	    do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE xsection.for:2193 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:2194 */
/*<       ival(basnum+1)=nsub >*/
	    ival[basnum] = *nsub;
/* SOURCE xsection.for:2195 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2196 */
/*<       sb(npnt)=ival(basnum+1) >*/
	sb[*npnt] = ival[basnum];
/* SOURCE xsection.for:2198 */
/*<       elseif(ival(basnum+1).eq.-1)then >*/
    } else if (ival[basnum] == -1) {
/*         BOUNDARY DEFINITION TERMINATED.  NO OTHER INFORMATION */
/*         MAY APPEAR ON THE LINE OF THE FINAL POINT. */
/* SOURCE xsection.for:2202 */
/*<       sb(npnt)=-1 >*/
	sb[*npnt] = -1;
/* SOURCE xsection.for:2203 */
/*<       goto145 >*/
	goto L145;
/* SOURCE xsection.for:2204 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2206 */
/*<       isub=sb(npnt) >*/
    isub = sb[*npnt];
/*       NOW CHECK VALUES FOR THE VALUE OF N0.  IF OMITTED BY THE */
/*       USER IT TAKES ON THE VALUE OF THE MANNING'S N GIVEN FOR THE */
/*       SUBSECTION.  ANY NON-NEGATIVE VALUE IS VALID. */
/* SOURCE xsection.for:2212 */
/*<       if(rval(basnum+2).lt.0.0)then >*/
    if (rval[basnum + 1] < (float)0.) {
/*         TAKE USER NEGATIVE VALUES TO MEAN THE SAME THING AS */
/*         OMITTING THE VALUE.  ASSIGN THE LINE SEGMENT N VALUE */
/*         FROM THE SUBSECTION. */
/* SOURCE xsection.for:2217 */
/*<       lsn(npnt)=n(isub) >*/
	lsn[*npnt] = n[isub];
/* SOURCE xsection.for:2218 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:2219 */
/*<       lsn(npnt)=rval(basnum+2) >*/
	lsn[*npnt] = rval[basnum + 1];
/* SOURCE xsection.for:2220 */
/*<       endif >*/
    }
/*       CHECK THE FIRST DEPTH FOR VERTICAL VARIATION OF MANNING'S N. */
/*       THESE VALUES CAN APPEAR ONLY ONCE PER SUBSECTION. */
/* SOURCE xsection.for:2225 */
/*<       if(rval(basnum+3).gt.0.0)then >*/
    if (rval[basnum + 2] > (float)0.) {
/*         A NON-NEGATIVE VALUE HAS BEEN GIVEN.  USER IS GIVING DATA */
/*         ON VERTICAL VARIATION OF ROUGHNESS IN A SUBSECTION. */
/*         HAS THIS BEEN DONE ALREADY FOR THIS SUBSECTION? */
/* SOURCE xsection.for:2229 */
/*<       if(nvar(isub).gt.0)then >*/
	if (nvar[isub] > 0) {
/*           YES. OUTPUT ERROR AND IGNORE THE NEW DATA. */
/* SOURCE xsection.for:2231 */
/*<       write(stdout,74)isub >*/
	    feq_gen_io_d__244.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__244);
	    do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE xsection.for:2232 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:2233 */
/*<       else >*/
	} else {
/*           GET THE NUMBER OF VALUES GIVEN FOR VARIATION OF ROUGHNESS IN */
/*           THE VERTICAL.  COUNTING FROM THE FIRST DEPTH THE NUMBER OF */
/*           VALUES MUST BE EVEN AND NOT GREATER THAN 8. */
/* SOURCE xsection.for:2239 */
/*<       nn=mval-(basnum+2) >*/
	    nn = mval - (basnum + 2);
/* SOURCE xsection.for:2240 */
/*<       if(mod(nn,2).ne.0)then >*/
	    if (nn % 2 != 0) {
/*             VALUE OF ROUGHNESS IS MISSING. */
/* SOURCE xsection.for:2242 */
/*<       write(stdout,76)nn/2 >*/
		feq_gen_io_d__246.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__246);
		feq_gen_i_d_1 = nn / 2;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE xsection.for:2243 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE xsection.for:2244 */
/*<       nn=nn-1 >*/
		--nn;
/* SOURCE xsection.for:2245 */
/*<       endif >*/
	    }
/*           STORE THE VALUES IN THE SUBSECTION NUMBER INDEXED ARRAYS */
/* SOURCE xsection.for:2248 */
/*<       if(nn.gt.0)then >*/
	    if (nn > 0) {
/* SOURCE xsection.for:2249 */
/*<       nny(isub)=nn/2+1 >*/
		nny[isub] = nn / 2 + 1;
/* SOURCE xsection.for:2250 */
/*<       yatn(1,isub)=0.0 >*/
		yatn[isub * 9 + 1] = (float)0.;
/* SOURCE xsection.for:2251 */
/*<       naty(1,isub)=lsn(npnt) >*/
		naty[isub * 9 + 1] = lsn[*npnt];
/* SOURCE xsection.for:2252 */
/*<       do138i=1,nn/2 >*/
		feq_gen_i_d_1 = nn / 2;
		for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:2253 */
/*<       yatn(i+1,isub)=rval(basnum+3+2*(i-1)) >*/
		    yatn[feq_gen_i_d_ + 1 + isub * 9] = rval[basnum + 3 + (feq_gen_i_d_ - 1 << 
			    1) - 1];
/* SOURCE xsection.for:2254 */
/*<       naty(i+1,isub)=rval(basnum+4+2*(i-1)) >*/
		    naty[feq_gen_i_d_ + 1 + isub * 9] = rval[basnum + 4 + (feq_gen_i_d_ - 1 << 
			    1) - 1];
/* SOURCE xsection.for:2255 */
/*<   138 continue >*/
/* L138: */
		}
/*             SET THE NATURE OF THE VARIATION IN THE VERTICAL */
/* SOURCE xsection.for:2259 */
/*<       nvar(isub)=ivarn >*/
		nvar[isub] = ivarn;
/* SOURCE xsection.for:2260 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:2261 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2262 */
/*<       endif >*/
    }
/*       OUTPUT THE VALUES FOR THE CURRENT LINE */
/* SOURCE xsection.for:2268 */
/*<       if(nvar(isub).eq.0)then >*/
    if (nvar[isub] == 0) {
/* SOURCE xsection.for:2269 */
/*<       write(stdout,57)x(npnt),z(npnt),isub,lsn(npnt) >*/
	feq_gen_io_d__247.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__247);
	do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[*npnt], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&lsn[*npnt], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:2270 */
/*<       else >*/
    } else {
/*         VERTICAL VARIATION OF N.  OUTPUT DETAILS ONLY FOR FIRST */
/*         POINT IN EACH SUBSECTION HAVING SUCH VARIATION */
/* SOURCE xsection.for:2273 */
/*<       if(isub.ne.oldsub)then >*/
	if (isub != oldsub) {
/*           FIRST LINE OF A NEW SUB-SECTION */
/* SOURCE xsection.for:2275 */
/*<       oldsub=isub >*/
	    oldsub = isub;
/* SOURCE xsection.for:2276 */
/*<        >*/
	    feq_gen_io_d__248.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__248);
	    do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[*npnt], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&lsn[*npnt], (ftnlen)sizeof(real));
	    feq_gen_i_d_1 = nny[isub];
	    for (j = 2; j <= feq_gen_i_d_1; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&yatn[j + isub * 9], (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, (char *)&naty[j + isub * 9], (ftnlen)sizeof(
			real));
	    }
	    e_wsfe();
/* SOURCE xsection.for:2278 */
/*<       else >*/
	} else {
/*           NOT FIRST LINE OF A NEW SUB-SECTION */
/* SOURCE xsection.for:2280 */
/*<       write(stdout,82)x(npnt),z(npnt),isub >*/
	    feq_gen_io_d__249.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__249);
	    do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[*npnt], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE xsection.for:2281 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2282 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2285 */
/*<       goto135 >*/
    goto L135;
/* SOURCE xsection.for:2287 */
/*<   145 continue >*/
L145:
/*     OUTPUT THE FINAL LINE */
/* SOURCE xsection.for:2289 */
/*<       write(stdout,82)x(npnt),z(npnt),sb(npnt) >*/
    feq_gen_io_d__250.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__250);
    do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[*npnt], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&sb[*npnt], (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE xsection.for:2292 */
/*<       if(npnt.gt.1)goto170 >*/
    if (*npnt > 1) {
	goto L170;
    }
/* SOURCE xsection.for:2293 */
/*<       write(stdout,61) >*/
    feq_gen_io_d__251.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__251);
    e_wsfe();
/* SOURCE xsection.for:2294 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE xsection.for:2295 */
/*<   170 continue >*/
L170:
/*     CHECK THE CROSS SECTION FOR NONSENSE BEHAVIOR AT THE END */
/* SOURCE xsection.for:2299 */
/*<       if(z(1).le.z(2).and.x(2).gt.x(1))then >*/
    if (feq_gen_z_d_[1] <= feq_gen_z_d_[2] && x[2] > x[1]) {
/*       THE LEFT MOST LINE SEGMENT HAS UPWARD SLOPE, THEREFORE HIGH */
/*       POINT IS NOT AT THE LEFT LIMIT. */
/* SOURCE xsection.for:2303 */
/*<       write(stdout,*)' *WRN:502* UNEXPECTED SLOPE',' AT LEFT END.' >*/
	feq_gen_io_d__252.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__252);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *WRN:502* UNEXPECTED SLOPE"), (ftnlen)27);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" AT LEFT END."), (ftnlen)13);
	e_wsle();
/* SOURCE xsection.for:2305 */
/*<       write(stdout,*)'  SLOPE EXPECTED TO BE < 0  AT LEFT BOUNDARY' >*/
	feq_gen_io_d__253.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__253);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  SLOPE EXPECTED TO BE < 0  AT LEFT BOUNDARY"), (
		ftnlen)44);
	e_wsle();
/* SOURCE xsection.for:2306 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2307 */
/*<       if(z(npnt).le.z(npnt-1).and.x(npnt).gt.x(npnt-1))then >*/
    if (feq_gen_z_d_[*npnt] <= feq_gen_z_d_[*npnt - 1] && x[*npnt] > x[*npnt - 1]) {
/*       THE RIGHT MOST LINE SEGMENT HAS DOWNWARD SLOPE */
/* SOURCE xsection.for:2310 */
/*<       write(stdout,*)' *WRN:503* UNEXPECTED SLOPE',' AT RIGHT END.' >*/
	feq_gen_io_d__254.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__254);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *WRN:503* UNEXPECTED SLOPE"), (ftnlen)27);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" AT RIGHT END."), (ftnlen)14);
	e_wsle();
/* SOURCE xsection.for:2312 */
/*<       write(stdout,*)'  SLOPE EXPECTED TO BE > 0 AT RIGHT BOUNDARY' >*/
	feq_gen_io_d__255.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__255);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  SLOPE EXPECTED TO BE > 0 AT RIGHT BOUNDARY"), (
		ftnlen)44);
	e_wsle();
/* SOURCE xsection.for:2313 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2315 */
/*<       if(extend.eq.1)then >*/
    if (nrdzcm_1.extend == 1) {
/*       CHECK FOR ONE END BEING HIGHER THAN THE OTHER */
/* SOURCE xsection.for:2318 */
/*<       if(abs(zmax-z(1)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[1], dabs(feq_gen_r_d_1)) > epscom_1.epsdif) {
/* SOURCE xsection.for:2319 */
/*<       write(stdout,67)zmax-z(1) >*/
	    feq_gen_io_d__256.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__256);
	    feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[1];
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE xsection.for:2320 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2321 */
/*<       if(abs(zmax-z(npnt)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[*npnt], dabs(feq_gen_r_d_1)) > epscom_1.epsdif) {
/* SOURCE xsection.for:2322 */
/*<       write(stdout,68)zmax-z(npnt) >*/
	    feq_gen_io_d__257.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__257);
	    feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[*npnt];
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE xsection.for:2323 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2324 */
/*<       else >*/
    } else {
/*       CHECK FOR AN INTERMEDIATE POINT BEING HIGHER THAN EITHER */
/*       END */
/* SOURCE xsection.for:2327 */
/*<       if(abs(zmax-z(1)).gt.epsdif.and.abs(zmax-z(npnt)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[1], dabs(feq_gen_r_d_1)) > epscom_1.epsdif && (feq_gen_r_d_2 = static_cast<double>(*
		zmax) - feq_gen_z_d_[*npnt], dabs(feq_gen_r_d_2)) > epscom_1.epsdif) {
/* SOURCE xsection.for:2329 */
/*<       write(stdout,69) >*/
	    feq_gen_io_d__258.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__258);
	    e_wsfe();
/* SOURCE xsection.for:2330 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2332 */
/*<       zmax=min(z(1),z(npnt)) >*/
/* Computing MIN */
	feq_gen_r_d_1 = feq_gen_z_d_[1], feq_gen_r_d_2 = feq_gen_z_d_[*npnt];
	*zmax = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE xsection.for:2333 */
/*<       endif >*/
    }
/*     CHECK TO SEE IF SUBSECTION NUMBERS HAVE BEEN REPEATED IN */
/*     SEPARATE RUNS. */
/* SOURCE xsection.for:2338 */
/*<       ntemp=nsub >*/
    ntemp = *nsub;
/* SOURCE xsection.for:2339 */
/*<       callreasub(stdout,npnt,nsub,n,sb,eflag) >*/
    reasub_(stdout, npnt, nsub, &n[1], &sb[1], eflag);
/* SOURCE xsection.for:2343 */
/*<       if(nsub.ne.ntemp)then >*/
    if (*nsub != ntemp) {
/*       OUTPUT THE NEW ASSIGNMENTS */
/* SOURCE xsection.for:2345 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__260.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__260);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE xsection.for:2346 */
/*<       write(stdout,*)' *WRN:548* Unwise use of subsection numbers.' >*/
	feq_gen_io_d__261.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__261);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *WRN:548* Unwise use of subsection numbers."), (
		ftnlen)44);
	e_wsle();
/* SOURCE xsection.for:2347 */
/*<        >*/
	feq_gen_io_d__262.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__262);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("     Subsections have been added to avoid"), (
		ftnlen)41);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" repeated usage."), (ftnlen)16);
	e_wsle();
/* SOURCE xsection.for:2349 */
/*<        >*/
	feq_gen_io_d__263.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__263);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("     Old NSUB="), (ftnlen)14);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ntemp, (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" New NSUB="), (ftnlen)10);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*nsub), (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Please check for validity."), (ftnlen)27);
	e_wsle();
/* SOURCE xsection.for:2351 */
/*<       write(stdout,55)'NSUB',nsub,(n(j),j=1,nsub) >*/
	feq_gen_io_d__264.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__264);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("NSUB"), (ftnlen)4);
	do_fio(&feq_gen_c_d_1, (char *)&(*nsub), (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = *nsub;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&n[j], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE xsection.for:2352 */
/*<       write(stdout,56)head >*/
	feq_gen_io_d__265.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__265);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_wsfe();
/* SOURCE xsection.for:2353 */
/*<       do200j=1,npnt >*/
	feq_gen_i_d_1 = *npnt;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:2354 */
/*<       write(stdout,57)x(j),z(j),sb(j) >*/
	    feq_gen_io_d__266.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__266);
	    do_fio(&feq_gen_c_d_1, (char *)&x[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&sb[j], (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE xsection.for:2355 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE xsection.for:2356 */
/*<       endif >*/
    }
/*     Optionally adjust part of the boundary in elevation. */
/* SOURCE xsection.for:2360 */
/*<       if(dinvert.ne.0.0)then >*/
    if (xtadd_1.dinvert != (float)0.) {
/*       Make an adjustment.  Requires a table of type 2 that defines */
/*       the elevation below which we make an adjustment. */
/* SOURCE xsection.for:2364 */
/*<       callget_internal_tab_number(stdout,ws_tabid,eflag,ws_tab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, xtaddc_1.feq_gen_ws_tabid_d_, eflag, &
		xtadd_1.feq_gen_ws_tab_d_, (ftnlen)16);
/* SOURCE xsection.for:2368 */
/*<       callchktab(2,stdout,ftpnt,mftnum,ws_tab,eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &xtadd_1.feq_gen_ws_tab_d_, 
		eflag);
/* SOURCE xsection.for:2372 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/* SOURCE xsection.for:2373 */
/*<       calladj_invert(stdout,npnt,stat,ws_tab,dinvert,z,eflag) >*/
	    feq_gen_adj_invert_d_(stdout, npnt, stat, &xtadd_1.feq_gen_ws_tab_d_, &
		    xtadd_1.dinvert, &feq_gen_z_d_[1], eflag);
/* SOURCE xsection.for:2376 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2377 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2379 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:2380 */
/*<   991 continue >*/
L991:
/* SOURCE xsection.for:2381 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__267.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__267);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE xsection.for:2382 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__268.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__268);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE xsection.for:2383 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:2384 */
/*<       end >*/
    return 0;
} /* infqxe_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE xsection.for:2388 */
/*<        >*/
/* Subroutine */ int fbasel_(integer *snflg, real *zi, integer *npnt, integer 
	*nsub, real *feq_storage_x, real *feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real *feq_storage_lsn, integer *feq_storage_nvar, 
	real *feq_storage_sn, real *feq_storage_naty, real *feq_storage_yatn, integer *feq_storage_nny, real *nfac, char *
	betopt, real *feq_storage_n, real *feq_storage_ts, real *feq_storage_ps, doublereal *feq_storage_as, doublereal *feq_storage_ybs, 
	real *feq_storage_ns, doublereal *sumq, doublereal *sumfm, doublereal *sumfe, 
	doublereal *sumdq, doublereal *sumdfm, doublereal *sumdfe, doublereal 
	*summa, doublereal *summq, real *feq_storage_ysmx, real *feq_storage_sbsn, real *feq_storage_qs, real *feq_storage_ks,
	 ftnlen betopt_len)
{
    /* Initialized data */

    static real t1d3 = (float).3333333;
    static real t2d3 = (float).6666667;
    static real t4d3 = (float)1.333333;
    static real t5d3 = (float)1.666667;
    static real t7d3 = (float)2.333333;
    static real t8d3 = (float)2.666667;
    static real t10d3 = (float)3.333333;

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2, feq_gen_d_d_3, feq_gen_d_d_4, feq_gen_d_d_5;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal feq_gen_c_d_, feq_gen_h_d_;
    integer j;
    doublereal k, m;
    real p;
    doublereal q, s;
    real v;
    doublereal w, c1, c2, c3, c4, da, fe, fm;
    integer is;
    real dx, dz, xi, xl, yl, xr, yr, zl, zr;
    doublereal mu, dfe, dfm;
    integer igs, nbx;
    real sni, snl, snr;
    doublereal aloc, bloc;
    integer jmin;
    real pvec[999];
    integer jmax;
    real xmid;
    doublereal daloc, dbloc;
    real depth;
    doublereal snloc;
    integer nbflag;
    real halfdx;
    extern doublereal fndydn_(real *, integer *, real *, real *);
    doublereal sqrtsn;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__295 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__296 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__313 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__314 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__315 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__316 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__317 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__318 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__319 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Find basic elements for cross section at a given elevation. */
/*     the only horizontal lines segments which should be present */
/*     are at the minimum elevation  of the cross section. */
/* SOURCE xsection.for:2400 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:2403 */
/*<       integernpnt,nsub,snflg >*/
/* SOURCE xsection.for:2404 */
/*<       integernny(nsub),nvar(nsub),sb(npnt) >*/
/* SOURCE xsection.for:2405 */
/*<        >*/
/* SOURCE xsection.for:2408 */
/*<       doubleprecisionas(nsub),ybs(nsub) >*/
/* SOURCE xsection.for:2409 */
/*<       doubleprecisionsumdfe,sumdfm,sumdq,sumfe,sumfm,summa,summq,sumq >*/
/* SOURCE xsection.for:2411 */
/*<       characterbetopt*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     SNFLG  - Flag for sinuousity computations */
/*     ZI     - Current water surface elevation for computing elements */
/*     NPNT   - Number of points on boundary of a cross section */
/*     NSUB   - Number of subsections */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     LSN    - Line segment Manning's n value */
/*     NVAR   - Flag for variation of Manning's n in each subsection */
/*     SN     - Sinuousity at a point on a cross section boundary */
/*     NATY   - Mannings's n value at depth in YATN */
/*     YATN   - Depth values for the Manning's n values in NATY */
/*     NNY    - Number of values for Manning's n variation with depth */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     BETOPT - Option for computing flux coefficients and critical flow */
/*     N      - Manning's n values */
/*     TS     - Top width in each subsection */
/*     PS     - Wetted perimeter for each subsection */
/*     AS     - Area for each subsection in the cross section */
/*     YBS    - First moment of area about surface for each subsection */
/*     NS     - Manning's n for a subsection */
/*     SUMQ   - Flow(water flux) */
/*     SUMFM  - Momentum flux */
/*     SUMFE  - Energy flux */
/*     SUMDQ  - Derivative w. r. t. depth of the flow(water flux) */
/*     SUMDFM - Derivative w. r. t. depth of the momentum flux */
/*     SUMDFE - Derivative w. r. t. depth of the energy flux */
/*     SUMMA  - Area weighted sinuousity integral */
/*     SUMMQ  - Flow weighted sinuousity integral */
/*     YSMX   - Maximum local depth in each subsection */
/*     SBSN   - Subsection sinuousity */
/*     QS     - Flow distribution value in a subsection to account for */
/*               flow path length variations */
/*     KS     - Conveyance for each subsection */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:2450 */
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
/* INCLUDE xsection.for:2451 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE xsection.for:2452 */
/*     COMMON FOR GAUSSIAN NUMERICAL INTEGRATION RULE */
/* SOURCE gnicom.cmn:3 */
/*<       integerpmxngs >*/
/* SOURCE gnicom.cmn:4 */
/*<       parameter(pmxngs=21) >*/
/* SOURCE gnicom.cmn:6 */
/*<       integerngs >*/
/* SOURCE gnicom.cmn:8 */
/*<       doubleprecisionwgs(pmxngs),xgs(pmxngs) >*/
/* SOURCE gnicom.cmn:11 */
/*<       common/gnicom/wgs,xgs,ngs >*/
/* SOURCE gnicom.cmn:14 */
/*<       save/gnicom/ >*/
/* INCLUDE xsection.for:2453 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE xsection.for:2456 */
/*<       realt10d3,t1d3,t2d3,t4d3,t5d3,t7d3,t8d3 >*/
/* SOURCE xsection.for:2457 */
/*<       savet10d3,t1d3,t2d3,t4d3,t5d3,t7d3,t8d3 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:2460 */
/*<       integerigs,is,j,jmax,jmin,nbflag,nbx >*/
/* SOURCE xsection.for:2461 */
/*<        >*/
/* SOURCE xsection.for:2463 */
/*<       doubleprecisionda >*/
/* SOURCE xsection.for:2464 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE xsection.for:2468 */
/*<       intrinsicabs,dble,max,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE xsection.for:2471 */
/*<       realfndydn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:2474 */
/*<       externalfndydn >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/*     To accomodate n varying with depth of water, we must make two passes */
/*     over the cross section boundary.  The first pass computes the */
/*     pure geometric elements: top width, area, first moment of area, and */
/*     wetted perimeter.  Once these values are known, the value of n in */
/*     those subsections having a variable n can be computed.  The second */
/*     pass computes the values that depend in some way on roughness.  These */
/*     include the sinuosity elements and the NEWBETA computation of the */
/*     velocity distribution coefficients. */
/*      write(STD6,*) 'In FBASEL ZI=',ZI */
/*     SET A LOCAL FLAG FOR THE NEW BETA OPTION TO MAKE DECISIONS IN */
/*     A LOOP FASTER */
/* SOURCE xsection.for:2477 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> ks(feq_storage_ks, 1);

    feq::IndexedPointer<real> qs(feq_storage_qs, 1);

    feq::IndexedPointer<real> sbsn(feq_storage_sbsn, 1);

    feq::IndexedPointer<real> ysmx(feq_storage_ysmx, 1);

    feq::IndexedPointer<real> ns(feq_storage_ns, 1);

    feq::IndexedPointer<doublereal> ybs(feq_storage_ybs, 1);

    feq::IndexedPointer<doublereal> as(feq_storage_as, 1);

    feq::IndexedPointer<real> ps(feq_storage_ps, 1);

    feq::IndexedPointer<real> ts(feq_storage_ts, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    feq::IndexedPointer<integer> nny(feq_storage_nny, 1);

    feq::IndexedPointer<real> yatn(feq_storage_yatn, 10);

    feq::IndexedPointer<real> naty(feq_storage_naty, 10);

    feq::IndexedPointer<integer> nvar(feq_storage_nvar, 1);

    /* Function Body */
/* SOURCE xsection.for:2495 */
/*<       if(betopt(1:7).eq.'NEWBETA')then >*/
    if (s_cmp(betopt, const_cast<char*>("NEWBETA"), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE xsection.for:2496 */
/*<       nbflag=1 >*/
	nbflag = 1;
/* SOURCE xsection.for:2497 */
/*<       if(betopt(8:8).eq.'X')then >*/
	if (*(unsigned char *)&betopt[7] == 'X') {
/* SOURCE xsection.for:2498 */
/*<       nbx=1 >*/
	    nbx = 1;
/* SOURCE xsection.for:2499 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:2500 */
/*<       nbx=0 >*/
	    nbx = 0;
/* SOURCE xsection.for:2501 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2502 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:2503 */
/*<       nbflag=0 >*/
	nbflag = 0;
/* SOURCE xsection.for:2504 */
/*<       nbx=0 >*/
	nbx = 0;
/* SOURCE xsection.for:2505 */
/*<       endif >*/
    }
/*     CLEAR THE SUMMING VARIABLES */
/* SOURCE xsection.for:2509 */
/*<       sumq=0.0 >*/
    *sumq = (float)0.;
/* SOURCE xsection.for:2510 */
/*<       sumfm=0.0 >*/
    *sumfm = (float)0.;
/* SOURCE xsection.for:2511 */
/*<       sumfe=0.0 >*/
    *sumfe = (float)0.;
/* SOURCE xsection.for:2512 */
/*<       sumdq=0.0 >*/
    *sumdq = (float)0.;
/* SOURCE xsection.for:2513 */
/*<       sumdfm=0.0 >*/
    *sumdfm = (float)0.;
/* SOURCE xsection.for:2514 */
/*<       sumdfe=0.0 >*/
    *sumdfe = (float)0.;
/* SOURCE xsection.for:2515 */
/*<       summa=0.0 >*/
    *summa = (float)0.;
/* SOURCE xsection.for:2516 */
/*<       summq=0.0 >*/
    *summq = (float)0.;
/* SOURCE xsection.for:2518 */
/*<       do100j=1,nsub >*/
    feq_gen_i_d_1 = *nsub;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:2519 */
/*<       ts(j)=0. >*/
	ts[j] = (float)0.;
/* SOURCE xsection.for:2520 */
/*<       as(j)=0.d0 >*/
	as[j] = 0.;
/* SOURCE xsection.for:2521 */
/*<       ps(j)=0. >*/
	ps[j] = (float)0.;
/* SOURCE xsection.for:2522 */
/*<       ybs(j)=0.d0 >*/
	ybs[j] = 0.;
/* SOURCE xsection.for:2523 */
/*<       ns(j)=0. >*/
	ns[j] = (float)0.;
/* SOURCE xsection.for:2524 */
/*<       ysmx(j)=0. >*/
	ysmx[j] = (float)0.;
/* SOURCE xsection.for:2525 */
/*<       sbsn(j)=0. >*/
	sbsn[j] = (float)0.;
/* SOURCE xsection.for:2526 */
/*<       qs(j)=0. >*/
	qs[j] = (float)0.;
/* SOURCE xsection.for:2527 */
/*<       ks(j)=0. >*/
	ks[j] = (float)0.;
/* SOURCE xsection.for:2528 */
/*<   100 continue >*/
/* L100: */
    }
/*     CLEAR THE INDICES FOR REMEMBERING THE RANGE OF BOUNDARY POINTS FOR */
/*     THE CURRENT ELEVATION, ZI */
/* SOURCE xsection.for:2533 */
/*<       jmin=0 >*/
    // FBASEL geometry: original-verified mixed binary32/binary64 accumulations.
    feq_section_geometry(*zi,*npnt,*nsub,&x[1],&feq_gen_z_d_[1],&sb[1],&lsn[1],
        &nvar[1],&ts[1],&ps[1],&as[1],&ybs[1],&ns[1],&ysmx[1],pvec,&jmin,&jmax);
    feq_gen_i_d_1 = *nsub;
    for (is = 1; is <= feq_gen_i_d_1; ++is) {
/* SOURCE xsection.for:2630 */
/*<       if(nvar(is).eq.1)then >*/
	if (nvar[is] == 1) {
/*           N DEPENDS ON HYDRAULIC DEPTH IN THE SUBSECTION */
/* SOURCE xsection.for:2632 */
/*<       if(ts(is).gt.0.0)then >*/
	    if (ts[is] > (float)0.) {
/* SOURCE xsection.for:2633 */
/*<       depth=as(is)/ts(is) >*/
		depth = as[is] / ts[is];
/* SOURCE xsection.for:2634 */
/*<       else >*/
	    } else {
/* SOURCE xsection.for:2635 */
/*<       if(as(is).gt.0.0)then >*/
		if (as[is] > (float)0.) {
/* SOURCE xsection.for:2636 */
/*<        >*/
		    feq_gen_io_d__295.ciunit = feq_gen_stdun_com_d_1.std6;
		    s_wsle(&feq_gen_io_d__295);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* AREA OR TOP WIDTH INVAL\
ID"), (ftnlen)36);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN SUB. FBASEL"), (ftnlen)15);
		    e_wsle();
/* SOURCE xsection.for:2638 */
/*<       write(std6,*)' IS=',is,' T=',ts(is),' A=',as(is) >*/
		    feq_gen_io_d__296.ciunit = feq_gen_stdun_com_d_1.std6;
		    s_wsle(&feq_gen_io_d__296);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IS="), (ftnlen)4);
		    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&is, (ftnlen)sizeof(integer))
			    ;
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" T="), (ftnlen)3);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&ts[is], (ftnlen)sizeof(real)
			    );
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" A="), (ftnlen)3);
		    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&as[is], (ftnlen)sizeof(
			    doublereal));
		    e_wsle();
/* SOURCE xsection.for:2639 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:2640 */
/*<       else >*/
		} else {
/* SOURCE xsection.for:2641 */
/*<       depth=0. >*/
		    depth = (float)0.;
/* SOURCE xsection.for:2642 */
/*<       endif >*/
		}
/* SOURCE xsection.for:2643 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:2644 */
/*<       n(is)=fndydn(depth,nny(is),yatn(1,is),naty(1,is)) >*/
	    n[is] = fndydn_(&depth, &nny[is], &yatn[is * 9 + 1], &naty[is * 9 
		    + 1]);
/* SOURCE xsection.for:2645 */
/*<       elseif(nvar(is).eq.2)then >*/
	} else if (nvar[is] == 2) {
/*         N DEPENDS ON MAXIMUM DEPTH IN THE SUBSECTION */
/* SOURCE xsection.for:2647 */
/*<       depth=ysmx(is) >*/
	    depth = ysmx[is];
/* SOURCE xsection.for:2648 */
/*<       n(is)=fndydn(depth,nny(is),yatn(1,is),naty(1,is)) >*/
	    n[is] = fndydn_(&depth, &nny[is], &yatn[is * 9 + 1], &naty[is * 9 
		    + 1]);
/* SOURCE xsection.for:2649 */
/*<       else >*/
	} else {
/*         COMPUTE COMPOSITE N AND USE IT IN THE SUBSECTION. */
/* SOURCE xsection.for:2651 */
/*<       if(ps(is).gt.0.0)then >*/
	    if (ps[is] > (float)0.) {
/* SOURCE xsection.for:2652 */
/*<       n(is)=ns(is)/ps(is) >*/
		n[is] = static_cast<double>(ns[is]) / ps[is];
/* SOURCE xsection.for:2654 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:2655 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2656 */
/*<   600 continue >*/
/* L600: */
    }
    // Independently verified analytical NEWBETA pass (sinuosity modes 0/2).
    // Independently verified complete Gaussian sinuosity pass.
    if (*snflg == 1) {
        try {
            feq_section_sinuosity(*zi,*npnt,*nsub,&x[1],&feq_gen_z_d_[1],&sb[1],&lsn[1],&nvar[1],
                &n[1],&sn[1],*nfac,grvcom_1.grav,nbflag,nbx,gnicom_1.ngs,gnicom_1.xgs,gnicom_1.wgs,
                sumq,sumfm,sumfe,sumdq,sumdfm,sumdfe,summa,summq,&qs[1],&ks[1]);
            return 0;
        } catch (const feq::SinuosityDepthError& error) {
            // The original diagnostic writes REAL copies of retained positions.
            feq_gen_h_d_ = error.state.depth;
            igs = static_cast<integer>(error.state.quadrature_index+1);
            xr = static_cast<float>(error.state.right_offset);
            xl = static_cast<float>(error.state.left_offset);
            zr = static_cast<float>(error.state.right_elevation);
            zl = static_cast<float>(error.state.left_elevation);
            s = error.state.station;
            yl = error.state.left_depth;
            m = error.state.slope;
            xmid = error.state.midpoint;
            dx = static_cast<float>(error.state.width);
            halfdx = error.state.half_width;

/* SOURCE xsection.for:2786 */
/*<       write(std6,*)' H=',h,' <0' >*/
			    feq_gen_io_d__313.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__313);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" H="), (ftnlen)3);
			    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_h_d_, (ftnlen)sizeof(
				    doublereal));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" <0"), (ftnlen)3);
			    e_wsle();
/* SOURCE xsection.for:2787 */
/*<       write(std6,*)' NGS=',ngs,' IGS=',igs,' XGS(IGS)=',xgs(igs) >*/
			    feq_gen_io_d__314.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__314);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NGS="), (ftnlen)5);
			    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&gnicom_1.ngs, (
				    ftnlen)sizeof(integer));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IGS="), (ftnlen)5);
			    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&igs, (ftnlen)sizeof(
				    integer));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XGS(IGS)="), (ftnlen)10);
			    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&gnicom_1.xgs[igs - 
				    1], (ftnlen)sizeof(doublereal));
			    e_wsle();
/* SOURCE xsection.for:2789 */
/*<       write(std6,*)' XR=',xr,' XL=',xl >*/
			    feq_gen_io_d__315.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__315);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XR="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xr, (ftnlen)sizeof(
				    real));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XL="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xl, (ftnlen)sizeof(
				    real));
			    e_wsle();
/* SOURCE xsection.for:2790 */
/*<       write(std6,*)' ZR=',zr,' ZL=',zl >*/
			    feq_gen_io_d__316.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__316);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ZR="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&zr, (ftnlen)sizeof(
				    real));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ZL="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&zl, (ftnlen)sizeof(
				    real));
			    e_wsle();
/* SOURCE xsection.for:2791 */
/*<       write(std6,*)' S=',s,' YL=',yl >*/
			    feq_gen_io_d__317.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__317);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" S="), (ftnlen)3);
			    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&s, (ftnlen)sizeof(
				    doublereal));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YL="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(
				    real));
			    e_wsle();
/* SOURCE xsection.for:2792 */
/*<       write(std6,*)' M=',m,' XMID=',xmid >*/
			    feq_gen_io_d__318.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__318);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" M="), (ftnlen)3);
			    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&m, (ftnlen)sizeof(
				    doublereal));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XMID="), (ftnlen)6);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xmid, (ftnlen)
				    sizeof(real));
			    e_wsle();
/* SOURCE xsection.for:2793 */
/*<       write(std6,*)' DX=',dx,' HALFDX=',halfdx >*/
			    feq_gen_io_d__319.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__319);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DX="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(
				    real));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" HALFDX="), (ftnlen)8);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&halfdx, (ftnlen)
				    sizeof(real));
			    e_wsle();
/* SOURCE xsection.for:2794 */
/*<       stop'Abnormal stop.  Error? found' >*/
			    s_stop(const_cast<char*>("Abnormal stop.  Error? found"), (ftnlen)28)
				    ;
/* SOURCE xsection.for:2795 */
/*<       endif >*/
			
            return 0;
        }
    }
    if (nbflag == 1 && *snflg != 1) {
        feq_section_flux(*zi,*npnt,*nsub,&x[1],&feq_gen_z_d_[1],&sb[1],&lsn[1],
            &nvar[1],&n[1],&sn[1],*snflg,*nfac,sumq,sumfm,sumfe,sumdq,sumdfm,sumdfe,&sbsn[1]);
        return 0;
    }

/* SOURCE xsection.for:2659 */
/*<       if(jmin.lt.2)jmin=2 >*/
    if (jmin < 2) {
	jmin = 2;
    }
/*     START THE SECOND PASS */
/* SOURCE xsection.for:2661 */
/*<       do900j=jmin,jmax >*/
    feq_gen_i_d_1 = jmax;
    for (j = jmin; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:2662 */
/*<       zl=z(j-1) >*/
	zl = feq_gen_z_d_[j - 1];
/* SOURCE xsection.for:2663 */
/*<       zr=z(j) >*/
	zr = feq_gen_z_d_[j];
/* SOURCE xsection.for:2664 */
/*<       if(zi.lt.zl.and.zi.lt.zr)goto900 >*/
	if (*zi < zl && *zi < zr) {
	    goto L900;
	}
/* SOURCE xsection.for:2665 */
/*<       xl=x(j-1) >*/
	xl = x[j - 1];
/* SOURCE xsection.for:2666 */
/*<       xr=x(j) >*/
	xr = x[j];
/* SOURCE xsection.for:2667 */
/*<       snl=sn(j-1) >*/
	snl = sn[j - 1];
/* SOURCE xsection.for:2668 */
/*<       snr=sn(j) >*/
	snr = sn[j];
/* SOURCE xsection.for:2669 */
/*<       is=sb(j-1) >*/
	is = sb[j - 1];
/* SOURCE xsection.for:2671 */
/*<       if(zi.ge.zl.and.zi.ge.zr)goto700 >*/
	if (*zi >= zl && *zi >= zr) {
	    goto L700;
	}
/*           INTERSECTION BETWEEN WATER SURFACE AND CURRENT */
/*           BOUNDARY LINE SEGMENT.  FIND OFFSET OF POINT OF */
/*           INTERSECTION. */
/* SOURCE xsection.for:2677 */
/*<       xi=xl+(zi-zl)*(xr-xl)/(zr-zl) >*/
	xi = static_cast<double>(xl) + static_cast<double>(static_cast<double>((static_cast<double>(*zi) - zl)) * (static_cast<double>(xr) - xl)) / (static_cast<double>(zr) - zl);
/* SOURCE xsection.for:2678 */
/*<       if(snflg.eq.1)then >*/
	if (*snflg == 1) {
/* SOURCE xsection.for:2679 */
/*<       if(xr.gt.xl)then >*/
	    if (xr > xl) {
/* SOURCE xsection.for:2680 */
/*<       sni=snl+(xi-xl)*(snr-snl)/(xr-xl) >*/
		sni = static_cast<double>(snl) + static_cast<double>(static_cast<double>((static_cast<double>(xi) - xl)) * (static_cast<double>(snr) - snl)) / (static_cast<double>(xr) - xl);
/* SOURCE xsection.for:2681 */
/*<       else >*/
	    } else {
/*               OVERHANGING BANK? */
/* SOURCE xsection.for:2683 */
/*<       sni=1.0 >*/
		sni = (float)1.;
/* SOURCE xsection.for:2684 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:2685 */
/*<       else >*/
	} else {
/*             IN THIS CASE THE SINUOSITY APPLIES TO THE WHOLE */
/*             LINE SEGMENT.  ALSO THE SINUOSITY OF THE LINE */
/*             SEGMENT IS GIVEN BY THE SINUOSITY OF ITS LEFT POINT. */
/* SOURCE xsection.for:2690 */
/*<       sni=snl >*/
	    sni = snl;
/* SOURCE xsection.for:2691 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2692 */
/*<       if(zl.le.zr)then >*/
	if (zl <= zr) {
/* SOURCE xsection.for:2693 */
/*<       dx=xi-xl >*/
	    dx = static_cast<double>(xi) - xl;
/* SOURCE xsection.for:2694 */
/*<       xr=xi >*/
	    xr = xi;
/* SOURCE xsection.for:2695 */
/*<       snr=sni >*/
	    snr = sni;
/* SOURCE xsection.for:2696 */
/*<       zr=zi >*/
	    zr = *zi;
/* SOURCE xsection.for:2697 */
/*<       dz=zi-zl >*/
	    dz = static_cast<double>(*zi) - zl;
/* SOURCE xsection.for:2698 */
/*<       yr=0.0 >*/
	    yr = (float)0.;
/* SOURCE xsection.for:2699 */
/*<       yl=dz >*/
	    yl = dz;
/* SOURCE xsection.for:2700 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:2701 */
/*<       dx=xr-xi >*/
	    dx = static_cast<double>(xr) - xi;
/* SOURCE xsection.for:2702 */
/*<       xl=xi >*/
	    xl = xi;
/* SOURCE xsection.for:2703 */
/*<       snl=sni >*/
	    snl = sni;
/* SOURCE xsection.for:2704 */
/*<       zl=zi >*/
	    zl = *zi;
/* SOURCE xsection.for:2705 */
/*<       dz=zi-zr >*/
	    dz = static_cast<double>(*zi) - zr;
/* SOURCE xsection.for:2706 */
/*<       yl=0.0 >*/
	    yl = (float)0.;
/* SOURCE xsection.for:2707 */
/*<       yr=dz >*/
	    yr = dz;
/* SOURCE xsection.for:2708 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2709 */
/*<       p=pvec(j-1) >*/
	p = pvec[j - 2];
/* SOURCE xsection.for:2710 */
/*<       goto890 >*/
	goto L890;
/* SOURCE xsection.for:2711 */
/*<   700 continue >*/
L700:
/*           LINE SEGMENT BELOW WATER SURFACE */
/* SOURCE xsection.for:2715 */
/*<       dx=xr-xl >*/
	dx = static_cast<double>(xr) - xl;
/* SOURCE xsection.for:2716 */
/*<       dz=zr-zl >*/
	dz = static_cast<double>(zr) - zl;
/* SOURCE xsection.for:2717 */
/*<       yl=zi-zl >*/
	yl = static_cast<double>(*zi) - zl;
/* SOURCE xsection.for:2718 */
/*<       yr=zi-zr >*/
	yr = static_cast<double>(*zi) - zr;
/* SOURCE xsection.for:2719 */
/*<       p=pvec(j-1) >*/
	p = pvec[j - 2];
/* SOURCE xsection.for:2720 */
/*<   890 continue >*/
L890:
/*         COMPUTE THE SINUOSITY VALUES IF NEEDED. */
/*         The following options exist: 0- no sinuousity elements computed, */
/*           1- a sinuosity value is given at each point on the boundary */
/*              and linear variation is assumed between adjacent points. */
/*           2- a sinuosity value is given at each point on the boundary */
/*              and the value is a constant for each line segment following */
/*              the point.  Piecewise constant variation.  This option */
/*              is computed in COMPEL. */

/* SOURCE xsection.for:2733 */
/*<       if(snflg.eq.1)then >*/
	if (*snflg == 1) {
/* SOURCE xsection.for:2734 */
/*<       if(dx.gt.0.0.and.max(yl,yr).gt.0.0)then >*/
	    if (dx > (float)0. && dmax(yl,yr) > (float)0.) {
/* SOURCE xsection.for:2735 */
/*<       m=(zr-zl)/dx >*/
		m = static_cast<double>((static_cast<double>(zr) - zl)) / dx;
/* SOURCE xsection.for:2736 */
/*<       if(nvar(is).gt.0)then >*/
		if (nvar[is] > 0) {
/*               N DEFINED ON SUBSECTION BASIS */
/* SOURCE xsection.for:2738 */
/*<       c=nfac/(n(is)*(1.+m**2)**t1d3) >*/
/* Computing 2nd power */
		    feq_gen_d_d_2 = m;
		    feq_gen_d_d_1 = feq_gen_d_d_2 * feq_gen_d_d_2 + (float)1.;
		    feq_gen_d_d_3 = (doublereal) t1d3;
		    feq_gen_c_d_ = *nfac / (n[is] * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_3));
/* SOURCE xsection.for:2739 */
/*<       if(nbx.eq.1)then >*/
		    if (nbx == 1) {
/*                 COMPUTE THE CONSTANTS FOR LOCAL FLUX COEF. */
/* SOURCE xsection.for:2741 */
/*<       c1=nfac/(n(is)*(1.+m**2)**0.083333333333333d0) >*/
/* Computing 2nd power */
			feq_gen_d_d_2 = m;
			feq_gen_d_d_1 = feq_gen_d_d_2 * feq_gen_d_d_2 + (float)1.;
			c1 = *nfac / (n[is] * pow_dd(&feq_gen_d_d_1, &c_b581));
/* SOURCE xsection.for:2742 */
/*<       c2=75.*grav/(4.*c1**2) >*/
/* Computing 2nd power */
			feq_gen_d_d_1 = c1;
			c2 = static_cast<double>(grvcom_1.grav) * (float)75. / (feq_gen_d_d_1 * feq_gen_d_d_1 * (
				float)4.);
/* SOURCE xsection.for:2743 */
/*<       c3=-125.*grav**1.5/(4.*c1**3) >*/
			feq_gen_d_d_1 = (doublereal) grvcom_1.grav;
/* Computing 3rd power */
			feq_gen_d_d_2 = c1;
			c3 = pow_dd(&feq_gen_d_d_1, &c_b582) * (float)-125. / (feq_gen_d_d_2 * (
				feq_gen_d_d_2 * feq_gen_d_d_2) * (float)4.);
/* SOURCE xsection.for:2744 */
/*<       c4=6.251*grav/c1**2 >*/
/* Computing 2nd power */
			feq_gen_d_d_1 = c1;
			c4 = static_cast<double>(grvcom_1.grav) * (float)6.251 / (feq_gen_d_d_1 * feq_gen_d_d_1);
/* SOURCE xsection.for:2745 */
/*<       endif >*/
		    }
/* SOURCE xsection.for:2746 */
/*<       else >*/
		} else {
/* SOURCE xsection.for:2747 */
/*<       c=nfac/(lsn(j-1)*(1.+m**2)**t1d3) >*/
/* Computing 2nd power */
		    feq_gen_d_d_2 = m;
		    feq_gen_d_d_1 = feq_gen_d_d_2 * feq_gen_d_d_2 + (float)1.;
		    feq_gen_d_d_3 = (doublereal) t1d3;
		    feq_gen_c_d_ = *nfac / (lsn[j - 1] * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_3));
/* SOURCE xsection.for:2748 */
/*<       if(nbx.eq.1)then >*/
		    if (nbx == 1) {
/*                 COMPUTE THE CONSTANTS FOR LOCAL FLUX COEF. */
/* SOURCE xsection.for:2750 */
/*<       c1=nfac/(lsn(j-1)*(1.+m**2)**0.083333333333333d0) >*/
/* Computing 2nd power */
			feq_gen_d_d_2 = m;
			feq_gen_d_d_1 = feq_gen_d_d_2 * feq_gen_d_d_2 + (float)1.;
			c1 = *nfac / (lsn[j - 1] * pow_dd(&feq_gen_d_d_1, &c_b581));
/* SOURCE xsection.for:2751 */
/*<       c2=75.*grav/(4.*c1**2) >*/
/* Computing 2nd power */
			feq_gen_d_d_1 = c1;
			c2 = static_cast<double>(grvcom_1.grav) * (float)75. / (feq_gen_d_d_1 * feq_gen_d_d_1 * (
				float)4.);
/* SOURCE xsection.for:2752 */
/*<       c3=-125.*grav**1.5/(4.*c1**3) >*/
			feq_gen_d_d_1 = (doublereal) grvcom_1.grav;
/* Computing 3rd power */
			feq_gen_d_d_2 = c1;
			c3 = pow_dd(&feq_gen_d_d_1, &c_b582) * (float)-125. / (feq_gen_d_d_2 * (
				feq_gen_d_d_2 * feq_gen_d_d_2) * (float)4.);
/* SOURCE xsection.for:2753 */
/*<       c4=6.251*grav/c1**2 >*/
/* Computing 2nd power */
			feq_gen_d_d_1 = c1;
			c4 = static_cast<double>(grvcom_1.grav) * (float)6.251 / (feq_gen_d_d_1 * feq_gen_d_d_1);
/* SOURCE xsection.for:2754 */
/*<       endif >*/
		    }
/* SOURCE xsection.for:2756 */
/*<       endif >*/
		}
/*             COMPUTE THE SUM FOR MA */
/* SOURCE xsection.for:2760 */
/*<       summa=summa+(xr-xl)*(snl*yl+0.5*(snl*yr+snr*yl)+snr*yr)/3.0 >*/
		*summa += static_cast<double>(static_cast<double>((static_cast<double>(xr) - xl)) * (static_cast<double>(static_cast<double>(static_cast<double>(snl) * yl) + static_cast<double>((static_cast<double>(static_cast<double>(snl) * yr) + static_cast<double>(snr) * yl)) * (
			float).5) + static_cast<double>(snr) * yr)) / (float)3.;
/* SOURCE xsection.for:2763 */
/*<       mu=(snr-snl)/dx >*/
		mu = static_cast<double>((static_cast<double>(snr) - snl)) / dx;
/*             SIMPLE CLOSED FORM EXPRESSIONS FOR THE OTHER INTEGRALS */
/*             ARE NOT AVAILABLE WHEN THE SINUOUSITY VARIATION IS */
/*             PIECEWISE LINEAR.  THEREFORE USE NUMERICAL INTEGRATION. */
/*             WE USE A GAUSSIAN RULE. */
/* SOURCE xsection.for:2770 */
/*<       xmid=.5d0*(dble(xl)+xr) >*/
		xmid = ((doublereal) xl + xr) * .5;
/* SOURCE xsection.for:2771 */
/*<       halfdx=.5d0*dble(dx) >*/
		halfdx = (doublereal) dx * .5;
/*              WRITE(STD6,*) ' M=',M,' MU=',MU */
/* SOURCE xsection.for:2775 */
/*<       do200igs=1,ngs >*/
		feq_gen_i_d_2 = gnicom_1.ngs;
		for (igs = 1; igs <= feq_gen_i_d_2; ++igs) {
/* SOURCE xsection.for:2776 */
/*<       w=halfdx*wgs(igs) >*/
		    w = halfdx * gnicom_1.wgs[igs - 1];
/*               COMPUTE THE BASIC VALUES FOR THE CURRENT LINE SEGMENT. */
/* SOURCE xsection.for:2780 */
/*<       s=halfdx*xgs(igs)+xmid >*/
		    s = halfdx * gnicom_1.xgs[igs - 1] + xmid;
/* SOURCE xsection.for:2781 */
/*<       h=yl-m*(s-xl) >*/
		    feq_gen_h_d_ = yl - m * (s - xl);
/* SOURCE xsection.for:2782 */
/*<       if(h.lt.0.d0)then >*/
		    if (feq_gen_h_d_ < 0.) {
/* SOURCE xsection.for:2783 */
/*<       if(abs(dx).lt.0.10)then >*/
			if (dabs(dx) < (float).1) {
/* SOURCE xsection.for:2784 */
/*<       h=0.d0 >*/
			    feq_gen_h_d_ = 0.;
/* SOURCE xsection.for:2785 */
/*<       else >*/
			} else {
/* SOURCE xsection.for:2786 */
/*<       write(std6,*)' H=',h,' <0' >*/
			    feq_gen_io_d__313.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__313);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" H="), (ftnlen)3);
			    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_h_d_, (ftnlen)sizeof(
				    doublereal));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" <0"), (ftnlen)3);
			    e_wsle();
/* SOURCE xsection.for:2787 */
/*<       write(std6,*)' NGS=',ngs,' IGS=',igs,' XGS(IGS)=',xgs(igs) >*/
			    feq_gen_io_d__314.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__314);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NGS="), (ftnlen)5);
			    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&gnicom_1.ngs, (
				    ftnlen)sizeof(integer));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IGS="), (ftnlen)5);
			    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&igs, (ftnlen)sizeof(
				    integer));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XGS(IGS)="), (ftnlen)10);
			    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&gnicom_1.xgs[igs - 
				    1], (ftnlen)sizeof(doublereal));
			    e_wsle();
/* SOURCE xsection.for:2789 */
/*<       write(std6,*)' XR=',xr,' XL=',xl >*/
			    feq_gen_io_d__315.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__315);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XR="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xr, (ftnlen)sizeof(
				    real));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XL="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xl, (ftnlen)sizeof(
				    real));
			    e_wsle();
/* SOURCE xsection.for:2790 */
/*<       write(std6,*)' ZR=',zr,' ZL=',zl >*/
			    feq_gen_io_d__316.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__316);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ZR="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&zr, (ftnlen)sizeof(
				    real));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ZL="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&zl, (ftnlen)sizeof(
				    real));
			    e_wsle();
/* SOURCE xsection.for:2791 */
/*<       write(std6,*)' S=',s,' YL=',yl >*/
			    feq_gen_io_d__317.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__317);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" S="), (ftnlen)3);
			    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&s, (ftnlen)sizeof(
				    doublereal));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YL="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(
				    real));
			    e_wsle();
/* SOURCE xsection.for:2792 */
/*<       write(std6,*)' M=',m,' XMID=',xmid >*/
			    feq_gen_io_d__318.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__318);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" M="), (ftnlen)3);
			    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&m, (ftnlen)sizeof(
				    doublereal));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XMID="), (ftnlen)6);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xmid, (ftnlen)
				    sizeof(real));
			    e_wsle();
/* SOURCE xsection.for:2793 */
/*<       write(std6,*)' DX=',dx,' HALFDX=',halfdx >*/
			    feq_gen_io_d__319.ciunit = feq_gen_stdun_com_d_1.std6;
			    s_wsle(&feq_gen_io_d__319);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DX="), (ftnlen)4);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(
				    real));
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" HALFDX="), (ftnlen)8);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&halfdx, (ftnlen)
				    sizeof(real));
			    e_wsle();
/* SOURCE xsection.for:2794 */
/*<       stop'Abnormal stop.  Error? found' >*/
			    s_stop(const_cast<char*>("Abnormal stop.  Error? found"), (ftnlen)28)
				    ;
/* SOURCE xsection.for:2795 */
/*<       endif >*/
			}
/* SOURCE xsection.for:2796 */
/*<       endif >*/
		    }
/* SOURCE xsection.for:2797 */
/*<       snloc=snl+mu*(s-xl) >*/
		    snloc = snl + mu * (s - xl);
/* SOURCE xsection.for:2798 */
/*<       sqrtsn=sqrt(snloc) >*/
		    sqrtsn = sqrt(snloc);
/* SOURCE xsection.for:2799 */
/*<       k=c*h**1.666666666666666d0 >*/
		    k = feq_gen_c_d_ * pow_dd(&feq_gen_h_d_, &c_b660);
/* SOURCE xsection.for:2800 */
/*<       q=k/sqrtsn >*/
		    q = k / sqrtsn;
/*                WRITE(STD6,*) ' S=',S,' H=',H,' SN=',SNLOC */
/*                WRITE(STD6,*) ' K=',K,' Q=',Q */
/*               DO SUMS FOR COMPUTATION OF MQ */
/* SOURCE xsection.for:2807 */
/*<       summq=summq+w*snloc*q >*/
		    *summq += w * snloc * q;
/* SOURCE xsection.for:2808 */
/*<       sumq=sumq+w*q >*/
		    *sumq += w * q;
/*               DO SUMS FOR COMPUTATION OF SUBSECTION CONVEYANCE */
/*               ADJUSTMENT FOR SINUOUSITY */
/* SOURCE xsection.for:2813 */
/*<       qs(is)=qs(is)+w*q >*/
		    qs[is] += w * q;
/* SOURCE xsection.for:2814 */
/*<       ks(is)=ks(is)+w*k >*/
		    ks[is] += w * k;
/* SOURCE xsection.for:2816 */
/*<       if(nbflag.eq.1)then >*/
		    if (nbflag == 1) {
/*                 COMPUTE THE ADDITIONAL SUMS REQUIRED FOR THE */
/*                 NEWBETA OPTION.  NOTE THAT CONSTANT FACTORS ON */
/*                 THE DERIVATIVES ARE APPLIED TO THE COMPLETED */
/*                 SUM OUTSIDE THE LOOP */
/* SOURCE xsection.for:2821 */
/*<       if(h.gt.0.d0)then >*/
			if (feq_gen_h_d_ > 0.) {
/* SOURCE xsection.for:2822 */
/*<       v=q/h >*/
			    v = q / feq_gen_h_d_;
/* SOURCE xsection.for:2823 */
/*<       else >*/
			} else {
/* SOURCE xsection.for:2824 */
/*<       v=0.0 >*/
			    v = (float)0.;
/* SOURCE xsection.for:2825 */
/*<       endif >*/
			}
/*                  WRITE(STD6,*) ' V=',V */
/* SOURCE xsection.for:2827 */
/*<       if(nbx.eq.0.or.h.eq.0.d0)then >*/
			if (nbx == 0 || feq_gen_h_d_ == 0.) {
/*                   ASSUME LOCAL FLUX COEFFICIENTS = 1.0 */
/* SOURCE xsection.for:2829 */
/*<       fm=q*v >*/
			    fm = q * v;
/* SOURCE xsection.for:2830 */
/*<       fe=fm*v >*/
			    fe = fm * v;
/* SOURCE xsection.for:2831 */
/*<       dfm=v*v >*/
			    dfm = static_cast<double>(v) * v;
/* SOURCE xsection.for:2832 */
/*<       dfe=dfm*v >*/
			    dfe = dfm * v;
/* SOURCE xsection.for:2833 */
/*<       else >*/
			} else {
/*                   ESTIMATE LOCAL FLUX COEFFICIENTS */
/* SOURCE xsection.for:2836 */
/*<       aloc=1.+c2/h**0.33333333333333d0+c3/sqrt(h) >*/
			    aloc = c2 / pow_dd(&feq_gen_h_d_, &c_b661) + (float)1. + 
				    c3 / sqrt(feq_gen_h_d_);
/* SOURCE xsection.for:2838 */
/*<       daloc=-c2/(3.*h**1.3333333333333d0)-c2/(2.*h**1.50) >*/
			    daloc = -c2 / (pow_dd(&feq_gen_h_d_, &c_b662) * (float)3.) 
				    - c2 / (pow_dd(&feq_gen_h_d_, &c_b582) * (float)2.)
				    ;
/* SOURCE xsection.for:2841 */
/*<       bloc=1.+c4/(h**0.33333333333333d0) >*/
			    bloc = c4 / pow_dd(&feq_gen_h_d_, &c_b661) + (float)1.;
/* SOURCE xsection.for:2842 */
/*<       dbloc=-c4/(3.*h**1.3333333333333d0) >*/
			    dbloc = -c4 / (pow_dd(&feq_gen_h_d_, &c_b662) * (float)3.);
/* SOURCE xsection.for:2844 */
/*<       fm=q*v >*/
			    fm = q * v;
/* SOURCE xsection.for:2845 */
/*<       fe=fm*v >*/
			    fe = fm * v;
/* SOURCE xsection.for:2846 */
/*<       dfm=v*v >*/
			    dfm = static_cast<double>(v) * v;
/* SOURCE xsection.for:2847 */
/*<       dfe=dfm*v >*/
			    dfe = dfm * v;
/* SOURCE xsection.for:2849 */
/*<       dfm=dbloc*fm+dfm*bloc >*/
			    dfm = dbloc * fm + dfm * bloc;
/* SOURCE xsection.for:2850 */
/*<       dfe=daloc*fe+dfe*aloc >*/
			    dfe = daloc * fe + dfe * aloc;
/* SOURCE xsection.for:2851 */
/*<       fm=fm*bloc >*/
			    fm *= bloc;
/* SOURCE xsection.for:2852 */
/*<       fe=fe*aloc >*/
			    fe *= aloc;
/* SOURCE xsection.for:2853 */
/*<       endif >*/
			}
/* SOURCE xsection.for:2855 */
/*<       sumdq=sumdq+w*v >*/
			*sumdq += w * v;
/* SOURCE xsection.for:2856 */
/*<       sumfm=sumfm+w*fm >*/
			*sumfm += w * fm;
/* SOURCE xsection.for:2857 */
/*<       sumfe=sumfe+w*fe >*/
			*sumfe += w * fe;
/* SOURCE xsection.for:2858 */
/*<       sumdfm=sumdfm+w*dfm >*/
			*sumdfm += w * dfm;
/* SOURCE xsection.for:2859 */
/*<       sumdfe=sumdfe+w*dfe >*/
			*sumdfe += w * dfe;
/* SOURCE xsection.for:2860 */
/*<       endif >*/
		    }
/* SOURCE xsection.for:2862 */
/*<   200 continue >*/
/* L200: */
		}
/* SOURCE xsection.for:2864 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:2865 */
/*<       elseif(snflg.eq.2)then >*/
	} else if (*snflg == 2) {
/*           PICK VALUES OF SINUOSITY AND ASSIGN TO SUBSECTIONS. */
/* SOURCE xsection.for:2868 */
/*<       sbsn(is)=snl >*/
	    sbsn[is] = snl;
/* SOURCE xsection.for:2869 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2872 */
/*<       if(betopt(1:7).eq.'NEWBETA'.and.snflg.ne.1)then >*/
	if (s_cmp(betopt, const_cast<char*>("NEWBETA"), (ftnlen)7, (ftnlen)7) == 0 && *snflg != 
		1) {
/*           COMPUTE THE VALUES FOR THE NEW METHOD FOR ESTIMATING */
/*           BETA AND ALPHA FOR AN OPEN CHANNEL CROSS SECTION. */
/* SOURCE xsection.for:2876 */
/*<       dx=xr-xl >*/
	    dx = static_cast<double>(xr) - xl;
/* SOURCE xsection.for:2877 */
/*<       if(dx.gt.0.0)then >*/
	    if (dx > (float)0.) {
/* SOURCE xsection.for:2878 */
/*<       m=(zr-zl)/dx >*/
		m = static_cast<double>((static_cast<double>(zr) - zl)) / dx;
/* SOURCE xsection.for:2879 */
/*<       if(nvar(is).gt.0)then >*/
		if (nvar[is] > 0) {
/*               N DEFINED ON SUBSECTION BASIS */
/* SOURCE xsection.for:2881 */
/*<       c=nfac/(n(is)*(1.+m**2)**t1d3) >*/
/* Computing 2nd power */
		    feq_gen_d_d_2 = m;
		    feq_gen_d_d_1 = feq_gen_d_d_2 * feq_gen_d_d_2 + (float)1.;
		    feq_gen_d_d_3 = (doublereal) t1d3;
		    feq_gen_c_d_ = *nfac / (n[is] * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_3));
/* SOURCE xsection.for:2882 */
/*<       else >*/
		} else {
/* SOURCE xsection.for:2883 */
/*<       c=nfac/(lsn(j-1)*(1.+m**2)**t1d3) >*/
/* Computing 2nd power */
		    feq_gen_d_d_2 = m;
		    feq_gen_d_d_1 = feq_gen_d_d_2 * feq_gen_d_d_2 + (float)1.;
		    feq_gen_d_d_3 = (doublereal) t1d3;
		    feq_gen_c_d_ = *nfac / (lsn[j - 1] * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_3));
/* SOURCE xsection.for:2884 */
/*<       endif >*/
		}
/* SOURCE xsection.for:2885 */
/*<       if(snflg.eq.2)then >*/
		if (*snflg == 2) {
/*               WE HAVE POSSIBLY NON-UNITARY VALUES OF SINUOUSITY. */
/*               THE VALUE FOR THE LINE SEGMENT IS AT THE LEFT END. */
/*               ADJUST C SO THAT THE LOCAL VELOCITY WILL TAKE INTO */
/*               ACCOUNT THE SINUOSITY */
/* SOURCE xsection.for:2890 */
/*<       c=c/sqrt(snl) >*/
		    feq_gen_c_d_ /= sqrt(snl);
/* SOURCE xsection.for:2891 */
/*<       endif >*/
		}
/* SOURCE xsection.for:2893 */
/*<       if(abs(m).gt.1.e-6)then >*/
		if (abs(m) > (float)1e-6) {
/* SOURCE xsection.for:2894 */
/*<       sumq=sumq-3.*c*(dble(yr)**t8d3-dble(yl)**t8d3)/(8.*m) >*/
		    feq_gen_d_d_1 = (doublereal) yr;
		    feq_gen_d_d_2 = (doublereal) t8d3;
		    feq_gen_d_d_3 = (doublereal) yl;
		    feq_gen_d_d_4 = (doublereal) t8d3;
		    *sumq -= feq_gen_c_d_ * (float)3. * (pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2) - pow_dd(
			    &feq_gen_d_d_3, &feq_gen_d_d_4)) / (m * (float)8.);
/* SOURCE xsection.for:2897 */
/*<       sumfm=sumfm-c**2*(0.3*(dble(yr)**t10d3-dble(yl)**t10d3))/m >*/
/* Computing 2nd power */
		    feq_gen_d_d_1 = feq_gen_c_d_;
		    feq_gen_d_d_2 = (doublereal) yr;
		    feq_gen_d_d_3 = (doublereal) t10d3;
		    feq_gen_d_d_4 = (doublereal) yl;
		    feq_gen_d_d_5 = (doublereal) t10d3;
		    *sumfm -= feq_gen_d_d_1 * feq_gen_d_d_1 * ((pow_dd(&feq_gen_d_d_2, &feq_gen_d_d_3) - pow_dd(&
			    feq_gen_d_d_4, &feq_gen_d_d_5)) * (float).3) / m;
/* SOURCE xsection.for:2900 */
/*<       sumfe=sumfe-c**3*(0.25*(dble(yr)**4-dble(yl)**4))/m >*/
/* Computing 3rd power */
		    feq_gen_d_d_1 = feq_gen_c_d_;
/* Computing 4th power */
		    feq_gen_d_d_2 = (doublereal) yr, feq_gen_d_d_2 *= feq_gen_d_d_2;
/* Computing 4th power */
		    feq_gen_d_d_3 = (doublereal) yl, feq_gen_d_d_3 *= feq_gen_d_d_3;
		    *sumfe -= feq_gen_d_d_1 * (feq_gen_d_d_1 * feq_gen_d_d_1) * ((feq_gen_d_d_2 * feq_gen_d_d_2 - feq_gen_d_d_3 * 
			    feq_gen_d_d_3) * (float).25) / m;
/* SOURCE xsection.for:2903 */
/*<       sumdq=sumdq-c*(dble(yr)**t5d3-dble(yl)**t5d3)/m >*/
		    feq_gen_d_d_1 = (doublereal) yr;
		    feq_gen_d_d_2 = (doublereal) t5d3;
		    feq_gen_d_d_3 = (doublereal) yl;
		    feq_gen_d_d_4 = (doublereal) t5d3;
		    *sumdq -= feq_gen_c_d_ * (pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2) - pow_dd(&feq_gen_d_d_3, &
			    feq_gen_d_d_4)) / m;
/* SOURCE xsection.for:2904 */
/*<       sumdfm=sumdfm-c**2*(dble(yr)**t7d3-dble(yl)**t7d3)/m >*/
/* Computing 2nd power */
		    feq_gen_d_d_1 = feq_gen_c_d_;
		    feq_gen_d_d_2 = (doublereal) yr;
		    feq_gen_d_d_3 = (doublereal) t7d3;
		    feq_gen_d_d_4 = (doublereal) yl;
		    feq_gen_d_d_5 = (doublereal) t7d3;
		    *sumdfm -= feq_gen_d_d_1 * feq_gen_d_d_1 * (pow_dd(&feq_gen_d_d_2, &feq_gen_d_d_3) - pow_dd(&
			    feq_gen_d_d_4, &feq_gen_d_d_5)) / m;
/* SOURCE xsection.for:2906 */
/*<       sumdfe=sumdfe-c**3*(dble(yr)**3-dble(yl)**3)/m >*/
/* Computing 3rd power */
		    feq_gen_d_d_1 = feq_gen_c_d_;
/* Computing 3rd power */
		    feq_gen_d_d_2 = (doublereal) yr;
/* Computing 3rd power */
		    feq_gen_d_d_3 = (doublereal) yl;
		    *sumdfe -= feq_gen_d_d_1 * (feq_gen_d_d_1 * feq_gen_d_d_1) * (feq_gen_d_d_2 * (feq_gen_d_d_2 * feq_gen_d_d_2) - 
			    feq_gen_d_d_3 * (feq_gen_d_d_3 * feq_gen_d_d_3)) / m;
/* SOURCE xsection.for:2907 */
/*<       else >*/
		} else {
/* SOURCE xsection.for:2908 */
/*<       sumq=sumq+dx*c*yl**t5d3 >*/
		    feq_gen_d_d_1 = (doublereal) yl;
		    feq_gen_d_d_2 = (doublereal) t5d3;
		    *sumq += dx * feq_gen_c_d_ * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2);
/* SOURCE xsection.for:2909 */
/*<       sumfm=sumfm+dx*c**2*yl**t7d3 >*/
/* Computing 2nd power */
		    feq_gen_d_d_1 = feq_gen_c_d_;
		    feq_gen_d_d_2 = (doublereal) yl;
		    feq_gen_d_d_3 = (doublereal) t7d3;
		    *sumfm += dx * (feq_gen_d_d_1 * feq_gen_d_d_1) * pow_dd(&feq_gen_d_d_2, &feq_gen_d_d_3);
/* SOURCE xsection.for:2910 */
/*<       sumfe=sumfe+dx*c**3*yl**3 >*/
/* Computing 3rd power */
		    feq_gen_d_d_1 = feq_gen_c_d_;
/* Computing 3rd power */
		    feq_gen_r_d_1 = yl;
		    *sumfe += dx * (feq_gen_d_d_1 * (feq_gen_d_d_1 * feq_gen_d_d_1)) * (static_cast<double>(feq_gen_r_d_1) * (static_cast<double>(feq_gen_r_d_1) * 
			    feq_gen_r_d_1));
/* SOURCE xsection.for:2911 */
/*<       sumdq=sumdq+dx*c*t5d3*yl**t2d3 >*/
		    feq_gen_d_d_1 = (doublereal) yl;
		    feq_gen_d_d_2 = (doublereal) t2d3;
		    *sumdq += dx * feq_gen_c_d_ * t5d3 * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2);
/* SOURCE xsection.for:2912 */
/*<       sumdfm=sumdfm+dx*c**2*t7d3*yl**t4d3 >*/
/* Computing 2nd power */
		    feq_gen_d_d_1 = feq_gen_c_d_;
		    feq_gen_d_d_2 = (doublereal) yl;
		    feq_gen_d_d_3 = (doublereal) t4d3;
		    *sumdfm += dx * (feq_gen_d_d_1 * feq_gen_d_d_1) * t7d3 * pow_dd(&feq_gen_d_d_2, &
			    feq_gen_d_d_3);
/* SOURCE xsection.for:2913 */
/*<       sumdfe=sumdfe+dx*c**3*3*yl**2 >*/
/* Computing 3rd power */
		    feq_gen_d_d_1 = feq_gen_c_d_;
/* Computing 2nd power */
		    feq_gen_r_d_1 = yl;
		    *sumdfe += dx * (feq_gen_d_d_1 * (feq_gen_d_d_1 * feq_gen_d_d_1)) * 3 * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)
			    ;
/* SOURCE xsection.for:2914 */
/*<       endif >*/
		}
/* SOURCE xsection.for:2915 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:2916 */
/*<       endif >*/
	}
/* SOURCE xsection.for:2917 */
/*<   900 continue >*/
L900:
	;
    }
/*     ADJUST SUMS WHEN SNFLG = 1 AND NBFLAG = 1 */
/* SOURCE xsection.for:2922 */
/*<       if(snflg.eq.1.and.nbflag.eq.1)then >*/
    if (*snflg == 1 && nbflag == 1) {
/* SOURCE xsection.for:2924 */
/*<       sumdq=t5d3*sumdq >*/
	*sumdq = t5d3 * *sumdq;
/* SOURCE xsection.for:2925 */
/*<       sumdfm=t7d3*sumdfm >*/
	*sumdfm = t7d3 * *sumdfm;
/* SOURCE xsection.for:2926 */
/*<       sumdfe=3*sumdfe >*/
	*sumdfe *= 3;
/* SOURCE xsection.for:2927 */
/*<       endif >*/
    }
/* SOURCE xsection.for:2929 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:2930 */
/*<       end >*/
} /* fbasel_ */




/* SOURCE xsection.for:2934 */
/*<        >*/
/* Subroutine */ int compel_(real *zi, integer *npnt, integer *nsub, integer *
	navm, real *feq_storage_x, real *feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real *nfac, char *betopt, 
	integer *snflg, real *feq_storage_lsn, integer *feq_storage_nvar, real *feq_storage_naty, real *feq_storage_yatn, 
	integer *feq_storage_nny, real *feq_storage_sn, integer *wrn557, real *feq_storage_kold, real *feq_storage_tsold, 
	real *feq_storage_n, real *feq_storage_xsv, ftnlen betopt_len)
{
    /* Format strings */
    static char fmt_10[] = "(/,\002 *WRN:505* Decrease in conveyance in subs\
ection\002,i4,\002 at elevation=\002,f10.3,/,11x,\002 decrease=\002,f6.1,\
\002 per cent\002)";
    static char fmt_11[] = "(\002 *ERR:632* At elevation=\002,f10.3,\002 sub\
section area <= 0\002,/,11x,\002 in subsection number=\002,i5,/,11x,\002 Che\
ck for input error or switch to NAVM= 1.\002)";
    static char fmt_12[] = "(/,\002 *WRN:557* At elevation=\002,f10.3,\002 s\
ubsection=\002,i3,\002 is a single vertical\002,/,11x,\002 line segment.  Ac\
ts as a\002,\002 frictionless wall.\002)";
    static char fmt_50[] = "(10x,\002Above warning given only once but may a\
pply\002,\002 many times.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2, feq_gen_d_d_3;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();

    /* Local variables */
    integer feq_gen_i_d_, j;
    real feq_gen_r_d_;
    doublereal as[200];
    real ks[200], kt, ns[200], ps[200], qs[200], wn, ts[200], den;
    doublereal ybs[200];
    real beta, kvec[200], drop, asum, sbsn[200], temp, ksum, psum;
    doublereal sumq;
    real tsum, ysmx[200], alpha;
    doublereal sumfe, sumfm, summa, sumdq, summq;
    real tslot;
    extern /* Subroutine */ int fbasel_(integer *, real *, integer *, integer 
	    *, real *, real *, integer *, real *, integer *, real *, real *, 
	    real *, integer *, real *, char *, real *, real *, real *, 
	    doublereal *, doublereal *, real *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, real *, real *, real *, real *, 
	    ftnlen);
    doublereal sumdfe;
    real alpsum, betsum, ybasum, mxslot;
    doublereal sumdfm;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__362 = { 0, 0, 0, fmt_11, 0 };
    static cilist feq_gen_io_d__363 = { 0, 0, 0, fmt_12, 0 };
    static cilist feq_gen_io_d__364 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__372 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__374 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute cross sectional elements at a given elevation. */
/* SOURCE xsection.for:2943 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE xsection.for:2946 */
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
/* SOURCE xsection.for:2949 */
/*<       integernavm,npnt,nsub,snflg,wrn557 >*/
/* SOURCE xsection.for:2950 */
/*<       integernny(nsub),nvar(nsub),sb(npnt) >*/
/* SOURCE xsection.for:2951 */
/*<        >*/
/* SOURCE xsection.for:2953 */
/*<       characterbetopt*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ZI     - Current water surface elevation for computing elements */
/*     NPNT   - Number of points on boundary of a cross section */
/*     NSUB   - Number of subsections */
/*     NAVM   - Flag for averaging roughness */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     BETOPT - Option for computing flux coefficients and critical flow */
/*     SNFLG  - Flag for sinuousity computations */
/*     LSN    - Line segment Manning's n value */
/*     NVAR   - Flag for variation of Manning's n in each subsection */
/*     NATY   - Mannings's n value at depth in YATN */
/*     YATN   - Depth values for the Manning's n values in NATY */
/*     NNY    - Number of values for Manning's n variation with depth */
/*     SN     - Sinuousity at a point on a cross section boundary */
/*     WRN557 - flag to suppress WRN:557 after first time */
/*     KOLD   - Previous value of conveyance */
/*     TSOLD  - Old top width in each subsection */
/*     N      - Manning's n values */
/*     XSV    - Vector of various elements of cross section */
/*     Added May 22, 1998: definition of XSV(*) contents */
/*     Extended 13 March 2003 */
/*     Offset    Value */
/*     1         Maximum depth-y */
/*     2         Top width */
/*     3         Area */
/*     4         First moment of area about water surface */
/*     5         Square root of conveyance- kh */
/*     6         Beta */
/*     7         Alpha */
/*     8         dBeta/dy */
/*     9         dAlpha/dy */
/*     10        Critical flow from momentum */
/*     11        Critical flow from energy */
/*     12        Critcal flow assuming Alpha=beta=1 */
/*     13        Critical flow that is selected by user: 10, 11, or 12 */
/*     14        MA- correction of volumes for sinuousity */
/*     15        MQ- correction of momentum for sinuosity */
/*     16        Total wetted perimeter- added May 22, 1998 */
/*     17        Average Manning's n value for the cross section */
/*     18        dkh/dy computed by cubic-spline fit */
/*     19        dalpha/dy computed by cubic-spline fit */
/*     20        dbeta/dy computed by cubic-spline fit */
/*     21        dma/dy computed by cubic-spline fit */
/*     22        dmq/dy computed by cubic-spline fit */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:3005 */
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
/* INCLUDE xsection.for:3006 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE xsection.for:3007 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE xsection.for:3008 */
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
/* SOURCE xsection.for:3011 */
/*<       integeri,j >*/
/* SOURCE xsection.for:3012 */
/*<        >*/
/* SOURCE xsection.for:3016 */
/*<       doubleprecisionas(pmxsub),ybs(pmxsub) >*/
/* SOURCE xsection.for:3017 */
/*<       doubleprecisionsumdfe,sumdfm,sumdq,sumfe,sumfm,summa,summq,sumq >*/
/*     + + + INTRINSICS + + + */
/* SOURCE xsection.for:3021 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:3024 */
/*<       externalfbasel >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:3027 */
/*<    10  >*/
/* SOURCE xsection.for:3029 */
/*<    11  >*/
/* SOURCE xsection.for:3032 */
/*<    12  >*/
/* SOURCE xsection.for:3035 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE xsection.for:3038 */
/*<       if(grav.gt.15.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    feq::IndexedPointer<real> tsold(feq_storage_tsold, 1);

    feq::IndexedPointer<real> kold(feq_storage_kold, 1);

    feq::IndexedPointer<integer> nny(feq_storage_nny, 1);

    feq::IndexedPointer<real> yatn(feq_storage_yatn, 10);

    feq::IndexedPointer<real> naty(feq_storage_naty, 10);

    feq::IndexedPointer<integer> nvar(feq_storage_nvar, 1);

    feq::IndexedPointer<real> xsv(feq_storage_xsv, 1);

    /* Function Body */
/* L10: */
/* L11: */
/* L12: */
/* L50: */
    if (grvcom_1.grav > (float)15.) {
/* SOURCE xsection.for:3039 */
/*<       mxslot=0.07 >*/
	mxslot = (float).07;
/* SOURCE xsection.for:3040 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:3041 */
/*<       mxslot=0.02134 >*/
	mxslot = (float).02134;
/* SOURCE xsection.for:3042 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3043 */
/*<       tslot=1.0001*slot >*/
    tslot = static_cast<double>(nrdzcm_1.slot) * (float)1.0001;
/*     FIND BASIC ELEMENTS AT THE GIVEN ELEVATION */
/* SOURCE xsection.for:3046 */
/*<        >*/
    fbasel_(snflg, zi, npnt, nsub, &x[1], &feq_gen_z_d_[1], &sb[1], &lsn[1], &nvar[1], 
	    &sn[1], &naty[10], &yatn[10], &nny[1], nfac, betopt, &n[1], ts, 
	    ps, as, ybs, ns, &sumq, &sumfm, &sumfe, &sumdq, &sumdfm, &sumdfe, 
	    &summa, &summq, ysmx, sbsn, qs, ks, (ftnlen)8);
    // COMPEL totals: independently verified original arithmetic and state updates.
    int feq_diagnostic_kind[401];
    int feq_diagnostic_subsection[401];
    float feq_diagnostic_percentage[401];
    const int feq_diagnostic_count = feq_section_properties(*nsub,*navm,*snflg,betopt,*nfac,
        grvcom_1.grav,nrdzcm_1.slot,nrdzcm_1.iusgs,nrdzcm_1.nocm,wrn557,
        ts,ps,as,ybs,&n[1],sbsn,qs,ks,sumq,sumfm,sumfe,sumdq,sumdfm,sumdfe,summa,summq,
        &kold[1],&tsold[1],&xsv[1],feq_diagnostic_kind,feq_diagnostic_subsection,feq_diagnostic_percentage);
    for (int feq_event = 0; feq_event < feq_diagnostic_count; ++feq_event) {
        j = feq_diagnostic_subsection[feq_event];
        if (feq_diagnostic_kind[feq_event] == 1) {
            feq_gen_io_d__362.ciunit = xscom_1.lout;
            s_wsfe(&feq_gen_io_d__362);
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(zi), static_cast<ftnlen>(sizeof(real)));
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(&j), static_cast<ftnlen>(sizeof(integer)));
            e_wsfe();
            xscom_1.eflag = 1;
        } else if (feq_diagnostic_kind[feq_event] == 2) {
            feq_gen_io_d__363.ciunit = xscom_1.lout;
            s_wsfe(&feq_gen_io_d__363);
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(zi), static_cast<ftnlen>(sizeof(real)));
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(&j), static_cast<ftnlen>(sizeof(integer)));
            e_wsfe();
            feq_gen_io_d__364.ciunit = xscom_1.lout;
            s_wsfe(&feq_gen_io_d__364);
            e_wsfe();
        } else if (feq_diagnostic_kind[feq_event] == 3) {
            feq_gen_io_d__372.ciunit = feq_gen_stdun_com_d_1.std6;
            s_wsfe(&feq_gen_io_d__372);
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(&j), static_cast<ftnlen>(sizeof(integer)));
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(zi), static_cast<ftnlen>(sizeof(real)));
            do_fio(&feq_gen_c_d_1, reinterpret_cast<char*>(&feq_diagnostic_percentage[feq_event]), static_cast<ftnlen>(sizeof(real)));
            e_wsfe();
        } else if (feq_diagnostic_kind[feq_event] == 4) {
            feq_gen_io_d__374.ciunit = feq_gen_stdun_com_d_1.std6;
            s_wsle(&feq_gen_io_d__374);
            do_lio(&feq_gen_c_d_9,&feq_gen_c_d_1,const_cast<char*>(" *ERR:615* NEWBETA FAILURE. VALUE < 1"),static_cast<ftnlen>(37));
            e_wsle();
        }
    }
    return 0;
/* SOURCE xsection.for:3327 */
/*<       end >*/
} /* compel_ */




/* SOURCE xsection.for:3332 */
/*<       subroutinefind_gen_st_line(x1,y1,x2,y2,a,b,c) >*/
/* Subroutine */ int feq_gen_find_gen_st_line_d_(real *x1, real *y1, real *x2, real *
	y2, real *a, real *b, real *feq_gen_c_d_)
{
/*     Find the general equation of a straight line. */
/* SOURCE xsection.for:3338 */
/*<       realx1,y1,x2,y2,a,b,c >*/
/* *********************************************************************** */
/* SOURCE xsection.for:3341 */
/*<       if(x2.ne.x1)then >*/
    if (*x2 != *x1) {
/* SOURCE xsection.for:3342 */
/*<       if(y2.ne.y1)then >*/
	if (*y2 != *y1) {
/*         General case here.  Line is neither horizontal nor vertical. */
/* SOURCE xsection.for:3345 */
/*<       a=y2-y1 >*/
	    *a = static_cast<double>(*y2) - *y1;
/* SOURCE xsection.for:3346 */
/*<       b=x1-x2 >*/
	    *b = static_cast<double>(*x1) - *x2;
/* SOURCE xsection.for:3347 */
/*<       c=x2*y1-x1*y2 >*/
	    *feq_gen_c_d_ = static_cast<double>(static_cast<double>(*x2) * *y1) - static_cast<double>(*x1) * *y2;
/* SOURCE xsection.for:3348 */
/*<       else >*/
	} else {
/*         Line is horizontal. */
/* SOURCE xsection.for:3350 */
/*<       a=0.0 >*/
	    *a = (float)0.;
/* SOURCE xsection.for:3351 */
/*<       b=1.0 >*/
	    *b = (float)1.;
/* SOURCE xsection.for:3352 */
/*<       c=-y1 >*/
	    *feq_gen_c_d_ = -(*y1);
/* SOURCE xsection.for:3353 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3354 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:3355 */
/*<       if(y2.ne.y1)then >*/
	if (*y2 != *y1) {
/*         The line is vertical */
/* SOURCE xsection.for:3357 */
/*<       a=1.0 >*/
	    *a = (float)1.;
/* SOURCE xsection.for:3358 */
/*<       b=0.0 >*/
	    *b = (float)0.;
/* SOURCE xsection.for:3359 */
/*<       c=-x1 >*/
	    *feq_gen_c_d_ = -(*x1);
/* SOURCE xsection.for:3360 */
/*<       else >*/
	} else {
/*         The line does not exist! */
/* SOURCE xsection.for:3362 */
/*<       a=0.0 >*/
	    *a = (float)0.;
/* SOURCE xsection.for:3363 */
/*<       b=0.0 >*/
	    *b = (float)0.;
/* SOURCE xsection.for:3364 */
/*<       c=0.0 >*/
	    *feq_gen_c_d_ = (float)0.;
/* SOURCE xsection.for:3365 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3366 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3367 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:3368 */
/*<       end >*/
} /* find_gen_st_line__ */




/* SOURCE xsection.for:3373 */
/*<       subroutineline_intersect(a1,b1,c1,a2,b2,c2,exist,x,y) >*/
/* Subroutine */ int feq_gen_line_intersect_d_(real *a1, real *b1, real *c1, real *a2, 
	real *b2, real *c2, integer *exist, real *x, real *y)
{
    real tp;

/*     Find the intersection point of two straigt lines given */
/*     in general linear equation form. */
/* SOURCE xsection.for:3380 */
/*<       integerexist >*/
/* SOURCE xsection.for:3382 */
/*<       reala1,b1,c1,a2,b2,c2,x,y,tp >*/
/* *********************************************************************** */
/* SOURCE xsection.for:3385 */
/*<       tp=a1*b2-a2*b1 >*/
    tp = static_cast<double>(static_cast<double>(*a1) * *b2) - static_cast<double>(*a2) * *b1;
/* SOURCE xsection.for:3386 */
/*<       if(tp.ne.0.0)then >*/
    if (tp != (float)0.) {
/* SOURCE xsection.for:3388 */
/*<       exist=1 >*/
	*exist = 1;
/* SOURCE xsection.for:3389 */
/*<       x=(c2*b1-c1*b2)/tp >*/
	*x = static_cast<double>((static_cast<double>(static_cast<double>(*c2) * *b1) - static_cast<double>(*c1) * *b2)) / tp;
/* SOURCE xsection.for:3390 */
/*<       y=(c1*a2-c2*a1)/tp >*/
	*y = static_cast<double>((static_cast<double>(static_cast<double>(*c1) * *a2) - static_cast<double>(*c2) * *a1)) / tp;
/* SOURCE xsection.for:3391 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:3392 */
/*<       exist=0 >*/
	*exist = 0;
/* SOURCE xsection.for:3393 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3394 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:3395 */
/*<       end >*/
} /* line_intersect__ */




/* SOURCE xsection.for:3399 */
/*<        >*/
/* Subroutine */ int feq_gen_find_cross_d_(integer *stdout, integer *npnt, integer *
	feq_gen_min_at_d_, integer *dir, integer *nlim, real *feq_storage_x, real *feq_gen_feq_storage_z_d_, real *
	feq_gen_slot_xm_d_, real *feq_gen_slot_zm_d_, real *feq_gen_slot_x_d_, real *feq_gen_slot_z_d_, integer *
	itype, integer *ilcross, real *xcross, real *zcross)
{
    /* Initialized data */

    static real eps = (float)5e-4;

    extern /* Subroutine */ int feq_gen_find_gen_st_line_d_(real *, real *, real *, 
	    real *, real *, real *, real *);
    real a, b, feq_gen_c_d_;
    integer feq_gen_i_d_, j;
    real x1, x2, z1, z2, xc, zc, aslot, bslot, cslot;
    integer exist;
    extern /* Subroutine */ int feq_gen_line_intersect_d_(real *, real *, real *, real 
	    *, real *, real *, integer *, real *, real *);

/*     Seek an intersection between the cross section boundary and */
/*     the given slot boundary. */
/* SOURCE xsection.for:3408 */
/*<       integeritype,min_at,nlim,npnt,dir,ilcross,stdout >*/
/* SOURCE xsection.for:3410 */
/*<       realx(npnt),z(npnt),slot_xm,slot_zm,slot_x,slot_z,xcross,zcross >*/
/*     Local */
/* SOURCE xsection.for:3416 */
/*<       integeri,j,exist >*/
/* SOURCE xsection.for:3418 */
/*<       realx1,z1,x2,z2,aslot,bslot,cslot,a,b,c,xc,zc,eps >*/
/* ********************************************************************** */
/*     Find general equation for the bounding line of the slot. */
/* SOURCE xsection.for:3421 */
/*<       dataeps/0.0005/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* SOURCE xsection.for:3425 */
/*<        >*/
    feq_gen_find_gen_st_line_d_(feq_gen_slot_xm_d_, feq_gen_slot_zm_d_, feq_gen_slot_x_d_, feq_gen_slot_z_d_, &aslot, &
	    bslot, &cslot);
/*      WRITE(STDOUT,*) ' SLOT_XM=',SLOT_XM,' SLOT_ZM=',SLOT_ZM */
/*      WRITE(STDOUT,*) ' SLOT_X=',SLOT_X,' SLOT_Z=',SLOT_Z */
/*      WRITE(STDOUT,*) ' ASLOT=',ASLOT,' BSLOT=',BSLOT,' CSLOT=',CSLOT */
/*     Set the intersection type to: no intersection found. */
/*      WRITE(STDOUT,*) ' FIND_CROSS: MIN_AT=',MIN_AT,' NPNT=',NPNT */
/* SOURCE xsection.for:3434 */
/*<       itype=0 >*/
    *itype = 0;
/* SOURCE xsection.for:3435 */
/*<       i=min_at >*/
    feq_gen_i_d_ = *feq_gen_min_at_d_;
/* SOURCE xsection.for:3436 */
/*<       x1=x(i) >*/
    x1 = x[feq_gen_i_d_];
/* SOURCE xsection.for:3437 */
/*<       z1=z(i) >*/
    z1 = feq_gen_z_d_[feq_gen_i_d_];
/* SOURCE xsection.for:3438 */
/*<       j=i >*/
    j = feq_gen_i_d_;
/* SOURCE xsection.for:3439 */
/*<   100 continue >*/
L100:
/* SOURCE xsection.for:3441 */
/*<       j=j+dir >*/
    j += *dir;
/* SOURCE xsection.for:3442 */
/*<       if(j.lt.1.or.j.gt.npnt)goto500 >*/
    if (j < 1 || j > *npnt) {
	goto L500;
    }
/* SOURCE xsection.for:3443 */
/*<       x2=x(j) >*/
    x2 = x[j];
/* SOURCE xsection.for:3444 */
/*<       z2=z(j) >*/
    z2 = feq_gen_z_d_[j];
/*       Find general equation for the line segment on the boundary. */
/*        WRITE(STDOUT,*) ' J=',J */
/*        WRITE(STDOUT,*) 'X1=',X1,' Z1=',Z1 */
/*        WRITE(STDOUT,*) 'X2=',X2,' Z2=',Z2 */
/* SOURCE xsection.for:3452 */
/*<       callfind_gen_st_line(x1,z1,x2,z2,a,b,c) >*/
    feq_gen_find_gen_st_line_d_(&x1, &z1, &x2, &z2, &a, &b, &feq_gen_c_d_);
/*        WRITE(STDOUT,*) ' A=',A,' B=',B,' C=',C */
/* SOURCE xsection.for:3458 */
/*<       callline_intersect(aslot,bslot,cslot,a,b,c,exist,xc,zc) >*/
    feq_gen_line_intersect_d_(&aslot, &bslot, &cslot, &a, &b, &feq_gen_c_d_, &exist, &xc, &zc);
/*        WRITE(STDOUT,*) ' EXIST=',EXIST,' XC=',XC,' ZC=',ZC */
/* SOURCE xsection.for:3463 */
/*<       if(exist.eq.0)then >*/
    if (exist == 0) {
/*         No useful intersection. */
/* SOURCE xsection.for:3466 */
/*<       itype=0 >*/
	*itype = 0;
/* SOURCE xsection.for:3467 */
/*<       else >*/
    } else {
/*         Is the intersection on the boundary line segment? */
/* SOURCE xsection.for:3469 */
/*<       if(min(x1,x2)-eps.le.xc.and.xc.le.max(x1,x2)+eps)then >*/
	if (dmin(x1,x2) - eps <= xc && xc <= dmax(x1,x2) + eps) {
/* SOURCE xsection.for:3470 */
/*<       if(min(z1,z2)-eps.le.zc.and.zc.le.max(z1,z2)+eps)then >*/
	    if (dmin(z1,z2) - eps <= zc && zc <= dmax(z1,z2) + eps) {
/* SOURCE xsection.for:3471 */
/*<       itype=1 >*/
		*itype = 1;
/* SOURCE xsection.for:3472 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3473 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3474 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3476 */
/*<       if(itype.eq.1)then >*/
    if (*itype == 1) {
/* SOURCE xsection.for:3477 */
/*<       xcross=xc >*/
	*xcross = xc;
/* SOURCE xsection.for:3478 */
/*<       zcross=zc >*/
	*zcross = zc;
/*         Set the index to the left end of the boundary line */
/*         segment. */
/* SOURCE xsection.for:3481 */
/*<       if(dir.gt.0)then >*/
	if (*dir > 0) {
/* SOURCE xsection.for:3482 */
/*<       ilcross=j-1 >*/
	    *ilcross = j - 1;
/* SOURCE xsection.for:3483 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:3484 */
/*<       ilcross=j >*/
	    *ilcross = j;
/* SOURCE xsection.for:3485 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3486 */
/*<       goto500 >*/
	goto L500;
/* SOURCE xsection.for:3487 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3488 */
/*<       x1=x2 >*/
    x1 = x2;
/* SOURCE xsection.for:3489 */
/*<       z1=z2 >*/
    z1 = z2;
/* SOURCE xsection.for:3490 */
/*<       goto100 >*/
    goto L100;
/* SOURCE xsection.for:3492 */
/*<   500 continue >*/
L500:
/* SOURCE xsection.for:3493 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:3494 */
/*<       end >*/
} /* find_cross__ */




/* SOURCE xsection.for:3499 */
/*<       subroutineshift_values(stdout,iold,inew,npnt,x,z,sb,lsn,sn) >*/
/* Subroutine */ int feq_gen_shift_values_d_(integer *stdout, integer *iold, integer *
	inew, integer *npnt, real *feq_storage_x, real *feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real *feq_storage_lsn, real 
	*feq_storage_sn)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:723* Maximum number of points on cr\
oss section\002,\002 boundary=\002,i5,\002 exceeded in adding invert slot\
.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, ie, is, inc, idiff;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__397 = { 0, 0, 0, fmt_50, 0 };


/*     Shift cross section boundary items to make room for inserting */
/*     the slot description. */
/*     iold  -  index into x(*) for the starting point of the sequence */
/*              of points that is to be shifted. */
/*     inew =  index of the location where the contents at iold are to */
/*             be after the shift. */
/*     npnt -  index to the last point in x(*) on entry.  On exit */
/*             index to the new location of the last point. */
/*     x, z, sb, lsn, and sn -- contain the section boundary descriptive */
/*            data. */
/* INCLUDE xsection.for:3515 */
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
/* SOURCE xsection.for:3517 */
/*<       integerstdout,iold,inew,npnt,sb(pmxpnt) >*/
/* SOURCE xsection.for:3519 */
/*<       realx(pmxpnt),z(pmxpnt),lsn(pmxpnt),sn(pmxpnt) >*/
/*     Local */
/* SOURCE xsection.for:3524 */
/*<       integeri,idiff,inc >*/
/*     ****************************FORMATS******************************* */
/* SOURCE xsection.for:3526 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE xsection.for:3530 */
/*<       idiff=inew-iold >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* L50: */
    idiff = *inew - *iold;
/* SOURCE xsection.for:3531 */
/*<       if(idiff.gt.0)then >*/
    if (idiff > 0) {
/* SOURCE xsection.for:3532 */
/*<       is=npnt >*/
	is = *npnt;
/* SOURCE xsection.for:3533 */
/*<       ie=iold >*/
	ie = *iold;
/* SOURCE xsection.for:3534 */
/*<       inc=-1 >*/
	inc = -1;
/* SOURCE xsection.for:3535 */
/*<       elseif(idiff.lt.0)then >*/
    } else if (idiff < 0) {
/* SOURCE xsection.for:3536 */
/*<       is=iold >*/
	is = *iold;
/* SOURCE xsection.for:3537 */
/*<       ie=npnt >*/
	ie = *npnt;
/* SOURCE xsection.for:3538 */
/*<       inc=1 >*/
	inc = 1;
/* SOURCE xsection.for:3539 */
/*<       else >*/
    } else {
/*       Force loop to be skipped. */
/* SOURCE xsection.for:3541 */
/*<       is=npnt+1 >*/
	is = *npnt + 1;
/* SOURCE xsection.for:3542 */
/*<       ie=iold >*/
	ie = *iold;
/* SOURCE xsection.for:3543 */
/*<       inc=1 >*/
	inc = 1;
/* SOURCE xsection.for:3544 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3545 */
/*<       do100i=is,ie,inc >*/
    feq_gen_i_d_1 = ie;
    feq_gen_i_d_2 = inc;
    for (feq_gen_i_d_ = is; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE xsection.for:3546 */
/*<       x(i+idiff)=x(i) >*/
	x[feq_gen_i_d_ + idiff] = x[feq_gen_i_d_];
/* SOURCE xsection.for:3547 */
/*<       z(i+idiff)=z(i) >*/
	feq_gen_z_d_[feq_gen_i_d_ + idiff] = feq_gen_z_d_[feq_gen_i_d_];
/* SOURCE xsection.for:3548 */
/*<       sb(i+idiff)=sb(i) >*/
	sb[feq_gen_i_d_ + idiff] = sb[feq_gen_i_d_];
/* SOURCE xsection.for:3549 */
/*<       lsn(i+idiff)=lsn(i) >*/
	lsn[feq_gen_i_d_ + idiff] = lsn[feq_gen_i_d_];
/* SOURCE xsection.for:3550 */
/*<       sn(i+idiff)=sn(i) >*/
	sn[feq_gen_i_d_ + idiff] = sn[feq_gen_i_d_];
/* SOURCE xsection.for:3551 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE xsection.for:3553 */
/*<       npnt=npnt+idiff >*/
    *npnt += idiff;
/* SOURCE xsection.for:3554 */
/*<       if(npnt.gt.pmxpnt)then >*/
    if (*npnt > 999) {
/* SOURCE xsection.for:3555 */
/*<       write(stdout,50)pmxpnt >*/
	feq_gen_io_d__397.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__397);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_999, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE xsection.for:3556 */
/*<       stop'Abnormal stop' >*/
	s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:3557 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3558 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:3559 */
/*<       end >*/
} /* shift_values__ */




/* SOURCE xsection.for:3563 */
/*<        >*/
/* Subroutine */ int feq_gen_add_slot_d_(integer *stdout, integer *feq_gen_in_ss_nvar_d_, 
	integer *npnt, integer *nsub, real *feq_storage_n, real *zmin, real *feq_storage_x, real *feq_gen_feq_storage_z_d_,
	 integer *feq_storage_sb, real *feq_storage_lsn, real *feq_storage_sn, integer *added)
{
    /* Initialized data */

    static real eps = (float)5e-4;

    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:724* Maximum number of subsections\
=\002,i5,\002 exceeded in adding an invert slot.\002)";
    static char fmt_54[] = "(/,\002*PROBLEM* Subset operations on cross sect\
ions with\002,\002 roughness varying with depth not yet supported.\002)";
    static char fmt_89[] = "(\002  Check of min search:\002,/,\002    Pointe\
r     Width\002)";
    static char fmt_90[] = "(\002 \002,i10,f10.3)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, feq_gen_saved_sub_d_, ie, is;
    real xl, xm, zl, zm, xr, zr;
    extern /* Subroutine */ int feq_gen_find_cross_d_(integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, real *, real *, 
	    real *, integer *, integer *, real *, real *);
    integer iold, inew;
    extern /* Subroutine */ int feq_gen_shift_values_d_(integer *, integer *, integer *
	    , integer *, real *, real *, integer *, real *, real *);
    integer eflag;
    real width[999];
    integer itype;
    char ematch[1];
    integer feq_gen_min_at_d_;
    char smatch[1];
    real minoff, maxoff;
    extern /* Subroutine */ int reasub_(integer *, integer *, integer *, real 
	    *, integer *, integer *);
    real bottom;
    integer feq_gen_min_knt_d_, feq_gen_min_pnt_d_[999], ilcross;
    real feq_gen_slot_xl_d_, feq_gen_slot_xm_d_, feq_gen_slot_zl_d_, feq_gen_slot_zm_d_;
    integer ircross;
    real feq_gen_slot_xr_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__399 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__406 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__407 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__408 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__409 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__415 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__429 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__430 = { 0, 0, 0, 0, 0 };


/*     Potentially add a bottom slot to a cross section description. */
/*     The slot size is in common block ABSLOT. */
/*     See CXSTAB for definition of arguments. */
/* INCLUDE xsection.for:3573 */
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
/* SOURCE xsection.for:3575 */
/*<       integeradded,stdout,nsub,sb(pmxpnt),in_ss_nvar >*/
/* SOURCE xsection.for:3577 */
/*<       realx(pmxpnt),z(pmxpnt),lsn(pmxpnt),sn(pmxpnt),n(pmxsub) >*/
/* INCLUDE xsection.for:3580 */
/*     Values used to keep track of a bottom slot in a cross section. */
/* SOURCE abslot.cmn:3 */
/*<       integerslot_present >*/
/* SOURCE abslot.cmn:5 */
/*<       realnslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:7 */
/*<       common/abslot/slot_present,nslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:10 */
/*<       save/abslot/ >*/
/*     SLOT_PRESENT: 0 no slot. 1 triangular slot, 2 exponential slot */
/*     NSLOT:  Manning's n for the slot if nslot > 0.  If nslot < 0.0 */
/*             use the average of the Manning's n's at the edges of the slot */
/*             and multiply by abs(nslot).  E. g. -1.2 computes the average value */
/*             of manning's n from the two bounding values in the cross section */
/*             and multiplies this averge by 1.2 to get the manning's n for the slot */
/*     WSLOT: width of the slot at the invert elevation of the cross section for a triangular */
/*            slot.  For the default exponential slot, it also gives the width of the slot */
/*            at the section invert.  If non-default values of rd are used, then the */
/*            meaning may differ. */
/*     ESLOT: elevation of the invert of the slot. */
/*     YSLOT: distance from slot invert to the cross section invert. */
/*     RD - factor on yslot to compute the y0 value for the exponential slot. */
/*          default value= 0.379376194959581.  This value together with the default */
/*          value of tzero has some convenient properties. */
/*     TZERO - width of the triangular section that forms the bottom portion of the */
/*             exponential slot.  Default value = 0.1*rd*wslot.  This default gives */
/*             an exponential slot with a width at the top of WSLOT.   A value of */
/*             wslot = 1/rd gives an area equal to the triangular slot with a */
/*             top width of 1.0. */
/*     EXPFAC - factor on the exponent in the exponential channel. Default value=1.0 */
/*              expfac > 1 gives a top-width increase larger than the default. */

/*     Only one of ESLOT or YSLOT is used.  YSLOT is the better choice for consistent */
/*     interpolation between sections. */
/* INCLUDE xsection.for:3581 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/*     Local */
/* SOURCE xsection.for:3585 */
/*<       character*1smatch,ematch >*/
/* SOURCE xsection.for:3587 */
/*<        >*/
/* SOURCE xsection.for:3590 */
/*<        >*/
/*     ********************************FORMATS************************** */
/* SOURCE xsection.for:3594 */
/*<       dataeps/0.0005/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    /* Function Body */
/* SOURCE xsection.for:3596 */
/*<    50  >*/
/* L50: */
/* SOURCE xsection.for:3598 */
/*<    54  >*/
/* L54: */
/* ********************************************************************** */
/* SOURCE xsection.for:3602 */
/*<       if(slot_present.eq.0)then >*/
    if (abslot_1.feq_gen_slot_present_d_ == 0) {
/* SOURCE xsection.for:3603 */
/*<       slot_depth=0.0 >*/
	xtadd_1.feq_gen_slot_depth_d_ = (float)0.;
/* SOURCE xsection.for:3604 */
/*<       added=0 >*/
	*added = 0;
/* SOURCE xsection.for:3605 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:3606 */
/*<       elseif(slot_present.ne.1)then >*/
    } else if (abslot_1.feq_gen_slot_present_d_ != 1) {
/*       Exponential slot being processed. */
/* SOURCE xsection.for:3608 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:3609 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3611 */
/*<       if(in_ss_nvar/=0)then >*/
    if (*feq_gen_in_ss_nvar_d_ != 0) {
/* SOURCE xsection.for:3612 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__399.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__399);
	e_wsfe();
/* SOURCE xsection.for:3613 */
/*<       stop'Abnormal stop. Feature not yet supported.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Feature not yet supported."), (ftnlen)41);
/* SOURCE xsection.for:3614 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3616 */
/*<       added=1 >*/
    *added = 1;
/*     Compute the slot vertical extent. */
/* SOURCE xsection.for:3618 */
/*<       if(yslot.gt.0.0)then >*/
    if (abslot_1.yslot > (float)0.) {
/*       Add a fixed size slot to the bottom of each cross section. */
/*       Redefine ESLOT to be the new invert. */
/* SOURCE xsection.for:3621 */
/*<       eslot=zmin-yslot >*/
	abslot_1.eslot = static_cast<double>(*zmin) - abslot_1.yslot;
/* SOURCE xsection.for:3622 */
/*<       slot_depth=yslot >*/
	xtadd_1.feq_gen_slot_depth_d_ = abslot_1.yslot;
/* SOURCE xsection.for:3623 */
/*<       else >*/
    } else {
/*       Add a slot that has an invert at a fixed elevation to */
/*       each cross section. */
/* SOURCE xsection.for:3626 */
/*<       slot_depth=zmin-eslot >*/
	xtadd_1.feq_gen_slot_depth_d_ = static_cast<double>(*zmin) - abslot_1.eslot;
/* SOURCE xsection.for:3627 */
/*<       if(slot_depth.lt.0.0)then >*/
	if (xtadd_1.feq_gen_slot_depth_d_ < (float)0.) {
/*         No slot needed */
/* SOURCE xsection.for:3629 */
/*<       slot_depth=0.0 >*/
	    xtadd_1.feq_gen_slot_depth_d_ = (float)0.;
/* SOURCE xsection.for:3630 */
/*<       return >*/
	    return 0;
/* SOURCE xsection.for:3631 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3632 */
/*<       endif >*/
    }
/*     Change sign of slot so that we can add to get the result. */
/*     SLOT is now the distance to the bottom of the slot from the min */
/*     elevation in the cross section. */
/* SOURCE xsection.for:3636 */
/*<       slot_depth=-slot_depth >*/
    xtadd_1.feq_gen_slot_depth_d_ = -xtadd_1.feq_gen_slot_depth_d_;
/*     We know the minimum elevation on entry.  Do another search to */
/*     describe the various extremes. */
/*      WRITE(STDOUT,*) ' In ADD_SLOT: ZMIN=',ZMIN */
/* SOURCE xsection.for:3642 */
/*<       min_knt=0 >*/
    feq_gen_min_knt_d_ = 0;
/* SOURCE xsection.for:3643 */
/*<       minoff=1.e20 >*/
    minoff = (float)1e20;
/* SOURCE xsection.for:3644 */
/*<       maxoff=-1.e30 >*/
    maxoff = (float)-1e30;
/* SOURCE xsection.for:3645 */
/*<       do100i=1,npnt >*/
    feq_gen_i_d_1 = *npnt;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:3646 */
/*<       if(abs(z(i)-zmin).le.eps)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(feq_gen_z_d_[feq_gen_i_d_]) - *zmin, dabs(feq_gen_r_d_1)) <= eps) {
/*         We have a match. */
/* SOURCE xsection.for:3648 */
/*<       min_knt=min_knt+1 >*/
	    ++feq_gen_min_knt_d_;
/* SOURCE xsection.for:3649 */
/*<       min_pnt(min_knt)=i >*/
	    feq_gen_min_pnt_d_[feq_gen_min_knt_d_ - 1] = feq_gen_i_d_;
/*         Does the point to the right, if it exists, have essentially */
/*         the same elevation? */
/* SOURCE xsection.for:3652 */
/*<       if(i.lt.npnt)then >*/
	    if (feq_gen_i_d_ < *npnt) {
/* SOURCE xsection.for:3653 */
/*<       if(abs(z(i+1)-zmin).le.eps)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(feq_gen_z_d_[feq_gen_i_d_ + 1]) - *zmin, dabs(feq_gen_r_d_1)) <= eps) {
/*             Yes.  We have an essentially horizontal segment at */
/*             the minimum elevation. */
/* SOURCE xsection.for:3656 */
/*<       width(min_knt)=x(i+1)-x(i) >*/
		    width[feq_gen_min_knt_d_ - 1] = static_cast<double>(x[feq_gen_i_d_ + 1]) - x[feq_gen_i_d_];
/* SOURCE xsection.for:3657 */
/*<       else >*/
		} else {
/*             Bottom width to right is zero. */
/* SOURCE xsection.for:3659 */
/*<       width(min_knt)=0.0 >*/
		    width[feq_gen_min_knt_d_ - 1] = (float)0.;
/* SOURCE xsection.for:3660 */
/*<       endif >*/
		}
/* SOURCE xsection.for:3661 */
/*<       else >*/
	    } else {
/*           Point to the right does not exist.  Bottom width to */
/*           right of point is zero. */
/* SOURCE xsection.for:3665 */
/*<       width(min_knt)=0.0 >*/
		width[feq_gen_min_knt_d_ - 1] = (float)0.;
/* SOURCE xsection.for:3666 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3667 */
/*<       endif >*/
	}
/*       Find the extreme offsets. */
/* SOURCE xsection.for:3669 */
/*<       maxoff=max(maxoff,x(i)) >*/
/* Computing MAX */
	feq_gen_r_d_1 = maxoff, feq_gen_r_d_2 = x[feq_gen_i_d_];
	maxoff = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE xsection.for:3670 */
/*<       minoff=min(minoff,x(i)) >*/
/* Computing MIN */
	feq_gen_r_d_1 = minoff, feq_gen_r_d_2 = x[feq_gen_i_d_];
	minoff = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE xsection.for:3672 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE xsection.for:3673 */
/*<       if(min_knt.eq.0)then >*/
    if (feq_gen_min_knt_d_ == 0) {
/* SOURCE xsection.for:3674 */
/*<       write(stdout,*)' BUG in ADD_SLOT.  No minimum match found' >*/
	feq_gen_io_d__406.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__406);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG in ADD_SLOT.  No minimum match found"), (
		ftnlen)41);
	e_wsle();
/* SOURCE xsection.for:3675 */
/*<       stop'Abnormal stop' >*/
	s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:3676 */
/*<       endif >*/
    }
/* SOURCE xsection.for:3678 */
/*<       write(stdout,89) >*/
    feq_gen_io_d__407.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__407);
    e_wsfe();
/* SOURCE xsection.for:3679 */
/*<    89 format('  Check of min search:',/,'    Pointer     Width') >*/
/* SOURCE xsection.for:3680 */
/*<       do1234i=1,min_knt >*/
    feq_gen_i_d_1 = feq_gen_min_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:3681 */
/*<       write(stdout,90)min_pnt(i),width(i) >*/
	feq_gen_io_d__408.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__408);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_min_pnt_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&width[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:3682 */
/*<  1234 continue >*/
/* L1234: */
    }
/* SOURCE xsection.for:3683 */
/*<    90 format(' ',i10,f10.3) >*/
/* SOURCE xsection.for:3685 */
/*<       if(wslot.ge.maxoff-minoff)then >*/
    if (abslot_1.wslot >= static_cast<double>(maxoff) - minoff) {
/* SOURCE xsection.for:3686 */
/*<       write(stdout,*)' *ERR:725*  Bottom slot wider than section!' >*/
	feq_gen_io_d__409.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__409);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:725*  Bottom slot wider than section!"), (
		ftnlen)43);
	e_wsle();
/* SOURCE xsection.for:3687 */
/*<       stop'Abnormal stop' >*/
	s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:3688 */
/*<       endif >*/
    }
/*     Now select the point at which to place the slot.  We have no */
/*     choice if MIN_KNT = 1! */
/* SOURCE xsection.for:3693 */
/*<       if(min_knt.eq.1)then >*/
    if (feq_gen_min_knt_d_ == 1) {
/* SOURCE xsection.for:3694 */
/*<       min_at=min_pnt(1) >*/
	feq_gen_min_at_d_ = feq_gen_min_pnt_d_[0];
/* SOURCE xsection.for:3695 */
/*<       bottom=width(1) >*/
	bottom = width[0];
/* SOURCE xsection.for:3696 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:3697 */
/*<       bottom=-1.e30 >*/
	bottom = (float)-1e30;
/* SOURCE xsection.for:3698 */
/*<       do110j=1,min_knt >*/
	feq_gen_i_d_1 = feq_gen_min_knt_d_;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:3699 */
/*<       if(width(j).gt.bottom)then >*/
	    if (width[j - 1] > bottom) {
/* SOURCE xsection.for:3700 */
/*<       min_at=min_pnt(j) >*/
		feq_gen_min_at_d_ = feq_gen_min_pnt_d_[j - 1];
/* SOURCE xsection.for:3701 */
/*<       bottom=width(j) >*/
		bottom = width[j - 1];
/* SOURCE xsection.for:3702 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3703 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE xsection.for:3704 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' MIN_AT=',MIN_AT,' BOTTOM=',BOTTOM */
/* SOURCE xsection.for:3708 */
/*<       xm=x(min_at) >*/
    xm = x[feq_gen_min_at_d_];
/* SOURCE xsection.for:3709 */
/*<       zm=z(min_at) >*/
    zm = feq_gen_z_d_[feq_gen_min_at_d_];
/*     Now add the new subsection and adjust the vectors. */
/* SOURCE xsection.for:3712 */
/*<       nsub=nsub+1 >*/
    ++(*nsub);
/* SOURCE xsection.for:3713 */
/*<       if(nsub.gt.pmxsub)then >*/
    if (*nsub > 200) {
/* SOURCE xsection.for:3714 */
/*<       write(stdout,50)pmxsub >*/
	feq_gen_io_d__415.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__415);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_200, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE xsection.for:3715 */
/*<       stop'Abnormal stop' >*/
	s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:3716 */
/*<       endif >*/
    }
/*     Set the new minimum to the slot invert elevation. */
/* SOURCE xsection.for:3720 */
/*<       zmin=eslot >*/
    *zmin = abslot_1.eslot;
/* SOURCE xsection.for:3722 */
/*<       if(bottom.gt.wslot)then >*/
    if (bottom > abslot_1.wslot) {
/*       If BOTTOM is > WSLOT put the slot to the right of the */
/*       selected minimum point.  It will always fit.  Also the */
/*       bottom of the cross section is known to be essentially */
/*       horizontal. */
/*       Save the subsection value at the min point because */
/*       it will be needed after the slot is inserted. */
/* SOURCE xsection.for:3730 */
/*<       saved_sub=sb(min_at) >*/
	feq_gen_saved_sub_d_ = sb[feq_gen_min_at_d_];
/* SOURCE xsection.for:3733 */
/*<       callshift_values(stdout,min_at+1,min_at+3,npnt,x,z,sb,lsn,sn) >*/
	feq_gen_i_d_1 = feq_gen_min_at_d_ + 1;
	feq_gen_i_d_2 = feq_gen_min_at_d_ + 3;
	feq_gen_shift_values_d_(stdout, &feq_gen_i_d_1, &feq_gen_i_d_2, npnt, &x[1], &feq_gen_z_d_[1], &sb[1], &
		lsn[1], &sn[1]);
/* SOURCE xsection.for:3738 */
/*<       sb(min_at)=nsub >*/
	sb[feq_gen_min_at_d_] = *nsub;
/* SOURCE xsection.for:3739 */
/*<       lsn(min_at)=n(nsub) >*/
	lsn[feq_gen_min_at_d_] = n[*nsub];
/* SOURCE xsection.for:3741 */
/*<       x(min_at+1)=xm+0.5*wslot >*/
	x[feq_gen_min_at_d_ + 1] = static_cast<double>(xm) + static_cast<double>(abslot_1.wslot) * (float).5;
/* SOURCE xsection.for:3742 */
/*<       z(min_at+1)=eslot >*/
	feq_gen_z_d_[feq_gen_min_at_d_ + 1] = abslot_1.eslot;
/* SOURCE xsection.for:3743 */
/*<       sb(min_at+1)=nsub >*/
	sb[feq_gen_min_at_d_ + 1] = *nsub;
/* SOURCE xsection.for:3744 */
/*<       sn(min_at+1)=1. >*/
	sn[feq_gen_min_at_d_ + 1] = (float)1.;
/* SOURCE xsection.for:3745 */
/*<       lsn(min_at+1)=n(nsub) >*/
	lsn[feq_gen_min_at_d_ + 1] = n[*nsub];
/* SOURCE xsection.for:3747 */
/*<       x(min_at+2)=xm+wslot >*/
	x[feq_gen_min_at_d_ + 2] = static_cast<double>(xm) + abslot_1.wslot;
/* SOURCE xsection.for:3748 */
/*<       z(min_at+2)=zm >*/
	feq_gen_z_d_[feq_gen_min_at_d_ + 2] = zm;
/* SOURCE xsection.for:3749 */
/*<       sb(min_at+2)=saved_sub >*/
	sb[feq_gen_min_at_d_ + 2] = feq_gen_saved_sub_d_;
/* SOURCE xsection.for:3750 */
/*<       sn(min_at+2)=1. >*/
	sn[feq_gen_min_at_d_ + 2] = (float)1.;
/* SOURCE xsection.for:3751 */
/*<       lsn(min_at+2)=n(saved_sub) >*/
	lsn[feq_gen_min_at_d_ + 2] = n[feq_gen_saved_sub_d_];
/* SOURCE xsection.for:3754 */
/*<       else >*/
    } else {
/*       The bottom is either not horizontal or horizontal and */
/*       too short to fit the slot requested.  We use a bit of */
/*       trial and error to fit the slot to the cross section. */
/*       Start by placing the slot centerline at the minimum */
/*       point.  Get the  min point local values. */
/* SOURCE xsection.for:3762 */
/*<       slot_zm=eslot >*/
	feq_gen_slot_zm_d_ = abslot_1.eslot;
/* SOURCE xsection.for:3763 */
/*<       slot_xm=xm >*/
	feq_gen_slot_xm_d_ = xm;
/* SOURCE xsection.for:3765 */
/*<       slot_xl=xm-0.5*wslot >*/
	feq_gen_slot_xl_d_ = static_cast<double>(xm) - static_cast<double>(abslot_1.wslot) * (float).5;
/* SOURCE xsection.for:3766 */
/*<       slot_zl=zm >*/
	feq_gen_slot_zl_d_ = zm;
/*       Seek an intersection of the slot boundary with the cross */
/*       section boundary on the left. */
/*        WRITE(STDOUT,*) ' CALLING FIND_CROSS 1' */
/* SOURCE xsection.for:3774 */
/*<        >*/
	feq_gen_find_cross_d_(stdout, npnt, &feq_gen_min_at_d_, &c_n1, &feq_gen_c_d_1, &x[1], &feq_gen_z_d_[1], &
		feq_gen_slot_xm_d_, &feq_gen_slot_zm_d_, &feq_gen_slot_xl_d_, &feq_gen_slot_zl_d_, &itype, &
		ilcross, &xl, &zl);
/*        WRITE(STDOUT,*) ' Left cross=',ILCROSS,' ITYPE=',ITYPE */
/* SOURCE xsection.for:3781 */
/*<       if(itype.eq.0)then >*/
	if (itype == 0) {
/*         No intersection.  Move slot to the right so that its */
/*         left point matches the minimum point and then seek */
/*         an intersection on the right. */
/* SOURCE xsection.for:3786 */
/*<       xl=xm >*/
	    xl = xm;
/* SOURCE xsection.for:3787 */
/*<       zl=zm >*/
	    zl = zm;
/* SOURCE xsection.for:3788 */
/*<       ilcross=min_at >*/
	    ilcross = feq_gen_min_at_d_;
/* SOURCE xsection.for:3790 */
/*<       slot_xm=xm+0.5*wslot >*/
	    feq_gen_slot_xm_d_ = static_cast<double>(xm) + static_cast<double>(abslot_1.wslot) * (float).5;
/* SOURCE xsection.for:3791 */
/*<       slot_xr=xm+wslot >*/
	    feq_gen_slot_xr_d_ = static_cast<double>(xm) + abslot_1.wslot;
/* SOURCE xsection.for:3793 */
/*<        >*/
	    feq_gen_find_cross_d_(stdout, npnt, &feq_gen_min_at_d_, &feq_gen_c_d_1, npnt, &x[1], &feq_gen_z_d_[1],
		     &feq_gen_slot_xm_d_, &feq_gen_slot_zm_d_, &feq_gen_slot_xr_d_, &feq_gen_slot_zl_d_, &itype, &
		    ircross, &xr, &zr);
/* SOURCE xsection.for:3798 */
/*<       if(itype.eq.0)then >*/
	    if (itype == 0) {
/* SOURCE xsection.for:3799 */
/*<        >*/
		feq_gen_io_d__429.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__429);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG: No intersection found on right"), (
			ftnlen)36);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" when one must exist."), (ftnlen)21);
		e_wsle();
/* SOURCE xsection.for:3801 */
/*<       stop' Abnormal stop' >*/
		s_stop(const_cast<char*>(" Abnormal stop"), (ftnlen)14);
/* SOURCE xsection.for:3802 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3804 */
/*<       else >*/
	} else {
/*         Intersection found on the left.  Seek one on the right */
/*         with the slot centerline on the minimum point. */
/* SOURCE xsection.for:3807 */
/*<       slot_xr=xm+0.5*wslot >*/
	    feq_gen_slot_xr_d_ = static_cast<double>(xm) + static_cast<double>(abslot_1.wslot) * (float).5;
/* SOURCE xsection.for:3808 */
/*<        >*/
	    feq_gen_find_cross_d_(stdout, npnt, &feq_gen_min_at_d_, &feq_gen_c_d_1, npnt, &x[1], &feq_gen_z_d_[1],
		     &feq_gen_slot_xm_d_, &feq_gen_slot_zm_d_, &feq_gen_slot_xr_d_, &feq_gen_slot_zl_d_, &itype, &
		    ircross, &xr, &zr);
/* SOURCE xsection.for:3813 */
/*<       if(itype.eq.0)then >*/
	    if (itype == 0) {
/*           No intersection on the right when there was one on */
/*           the left.  Move the the slot to the left so that */
/*           its right point matches the minimum and then */
/*           seek a new intersection on the left. */
/* SOURCE xsection.for:3819 */
/*<       xr=xm >*/
		xr = xm;
/* SOURCE xsection.for:3820 */
/*<       zr=zm >*/
		zr = zm;
/* SOURCE xsection.for:3821 */
/*<       ircross=min_at >*/
		ircross = feq_gen_min_at_d_;
/* SOURCE xsection.for:3823 */
/*<       slot_xm=xm-0.5*wslot >*/
		feq_gen_slot_xm_d_ = static_cast<double>(xm) - static_cast<double>(abslot_1.wslot) * (float).5;
/* SOURCE xsection.for:3824 */
/*<       slot_xl=xm-wslot >*/
		feq_gen_slot_xl_d_ = static_cast<double>(xm) - abslot_1.wslot;
/* SOURCE xsection.for:3825 */
/*<        >*/
		feq_gen_find_cross_d_(stdout, npnt, &feq_gen_min_at_d_, &c_n1, &feq_gen_c_d_1, &x[1], &
			feq_gen_z_d_[1], &feq_gen_slot_xm_d_, &feq_gen_slot_zm_d_, &feq_gen_slot_xl_d_, &
			feq_gen_slot_zl_d_, &itype, &ilcross, &xl, &zl);
/* SOURCE xsection.for:3830 */
/*<       if(itype.eq.0)then >*/
		if (itype == 0) {
/* SOURCE xsection.for:3831 */
/*<        >*/
		    feq_gen_io_d__430.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__430);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG: No intersection found on left")
			    , (ftnlen)35);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" when one must exist."), (ftnlen)21);
		    e_wsle();
/* SOURCE xsection.for:3833 */
/*<       stop' Abnormal stop' >*/
		    s_stop(const_cast<char*>(" Abnormal stop"), (ftnlen)14);
/* SOURCE xsection.for:3834 */
/*<       endif >*/
		}
/* SOURCE xsection.for:3836 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3837 */
/*<       endif >*/
	}
/*       Set the starting and ending values with flags to denote */
/*       essentially exact matches with a boundary point. */
/* SOURCE xsection.for:3842 */
/*<       if(abs(x(ilcross)-xl).le.eps)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(x[ilcross]) - xl, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:3843 */
/*<       is=ilcross >*/
	    is = ilcross;
/* SOURCE xsection.for:3844 */
/*<       smatch='Y' >*/
	    *(unsigned char *)smatch = 'Y';
/* SOURCE xsection.for:3845 */
/*<       elseif(abs(x(ilcross+1)-xl).le.eps)then >*/
	} else if ((feq_gen_r_d_1 = static_cast<double>(x[ilcross + 1]) - xl, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:3846 */
/*<       is=ilcross+1 >*/
	    is = ilcross + 1;
/* SOURCE xsection.for:3847 */
/*<       smatch='Y' >*/
	    *(unsigned char *)smatch = 'Y';
/* SOURCE xsection.for:3848 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:3849 */
/*<       is=ilcross >*/
	    is = ilcross;
/* SOURCE xsection.for:3850 */
/*<       smatch='N' >*/
	    *(unsigned char *)smatch = 'N';
/* SOURCE xsection.for:3851 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3852 */
/*<       if(abs(x(ircross)-xr).le.eps)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(x[ircross]) - xr, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:3853 */
/*<       ie=ircross >*/
	    ie = ircross;
/* SOURCE xsection.for:3854 */
/*<       ematch='Y' >*/
	    *(unsigned char *)ematch = 'Y';
/* SOURCE xsection.for:3855 */
/*<       elseif(abs(x(ircross+1)-xr).le.eps)then >*/
	} else if ((feq_gen_r_d_1 = static_cast<double>(x[ircross + 1]) - xr, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:3856 */
/*<       ie=ircross+1 >*/
	    ie = ircross + 1;
/* SOURCE xsection.for:3857 */
/*<       ematch='Y' >*/
	    *(unsigned char *)ematch = 'Y';
/* SOURCE xsection.for:3858 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:3859 */
/*<       ie=ircross >*/
	    ie = ircross;
/* SOURCE xsection.for:3860 */
/*<       ematch='N' >*/
	    *(unsigned char *)ematch = 'N';
/* SOURCE xsection.for:3861 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' ADD_SLOT: IS=',IS,' IE=',IE */
/*        WRITE(STDOUT,*) ' SMATCH=',SMATCH,' EMATCH=',EMATCH */
/* SOURCE xsection.for:3867 */
/*<       saved_sub=sb(ie) >*/
	feq_gen_saved_sub_d_ = sb[ie];
/*        WRITE(STDOUT,*) ' SAVED_SUB=',SAVED_SUB, 'N(SAVED_SUB)=', */
/*     A                  N(SAVED_SUB) */
/*     Select the manning's n for the slot: */
/*     nslot > 0.0 -- use nslot for manning's n in the slot */
/*     nslot = 0  -- use the mean value of the existing n at the */
/*                   start and end points. */
/*     nslot < 0.0 -- use the mean value of the existing n at the */
/*                    start and end point multiplied by abs(nslot). */
/* SOURCE xsection.for:3878 */
/*<       if(nslot.gt.0.0)then >*/
	if (abslot_1.nslot > (float)0.) {
/* SOURCE xsection.for:3879 */
/*<       n(nsub)=nslot >*/
	    n[*nsub] = abslot_1.nslot;
/* SOURCE xsection.for:3880 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:3881 */
/*<       if(ematch.eq.'Y')then >*/
	    if (*(unsigned char *)ematch == 'Y') {
/* SOURCE xsection.for:3882 */
/*<       i=ie-1 >*/
		feq_gen_i_d_ = ie - 1;
/* SOURCE xsection.for:3883 */
/*<       if(i.lt.is)i=is >*/
		if (feq_gen_i_d_ < is) {
		    feq_gen_i_d_ = is;
		}
/* SOURCE xsection.for:3884 */
/*<       else >*/
	    } else {
/* SOURCE xsection.for:3885 */
/*<       i=ie >*/
		feq_gen_i_d_ = ie;
/* SOURCE xsection.for:3886 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3887 */
/*<       n(nsub)=0.5*(lsn(is)+lsn(i)) >*/
	    n[*nsub] = static_cast<double>((static_cast<double>(lsn[is]) + lsn[feq_gen_i_d_])) * (float).5;
/* SOURCE xsection.for:3888 */
/*<       if(nslot.lt.0.0)then >*/
	    if (abslot_1.nslot < (float)0.) {
/* SOURCE xsection.for:3889 */
/*<       n(nsub)=n(nsub)*abs(nslot) >*/
		n[*nsub] *= dabs(abslot_1.nslot);
/* SOURCE xsection.for:3890 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3891 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3893 */
/*<       if(smatch.eq.'Y')then >*/
	if (*(unsigned char *)smatch == 'Y') {
/* SOURCE xsection.for:3894 */
/*<       sb(is)=nsub >*/
	    sb[is] = *nsub;
/* SOURCE xsection.for:3895 */
/*<       lsn(is)=n(nsub) >*/
	    lsn[is] = n[*nsub];
/* SOURCE xsection.for:3896 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3897 */
/*<       if(ematch.eq.'Y')then >*/
	if (*(unsigned char *)ematch == 'Y') {
/* SOURCE xsection.for:3898 */
/*<       if(smatch.eq.'Y')then >*/
	    if (*(unsigned char *)smatch == 'Y') {
/* SOURCE xsection.for:3899 */
/*<       iold=ie >*/
		iold = ie;
/* SOURCE xsection.for:3900 */
/*<       inew=is+2 >*/
		inew = is + 2;
/* SOURCE xsection.for:3901 */
/*<       callshift_values(stdout,iold,inew,npnt,x,z,sb,lsn,sn) >*/
		feq_gen_shift_values_d_(stdout, &iold, &inew, npnt, &x[1], &feq_gen_z_d_[1], &
			sb[1], &lsn[1], &sn[1]);
/* SOURCE xsection.for:3904 */
/*<       x(is+1)=slot_xm >*/
		x[is + 1] = feq_gen_slot_xm_d_;
/* SOURCE xsection.for:3905 */
/*<       z(is+1)=slot_zm >*/
		feq_gen_z_d_[is + 1] = feq_gen_slot_zm_d_;
/* SOURCE xsection.for:3906 */
/*<       sb(is+1)=nsub >*/
		sb[is + 1] = *nsub;
/* SOURCE xsection.for:3907 */
/*<       sn(is+1)=1.0 >*/
		sn[is + 1] = (float)1.;
/* SOURCE xsection.for:3908 */
/*<       lsn(is+1)=n(nsub) >*/
		lsn[is + 1] = n[*nsub];
/* SOURCE xsection.for:3909 */
/*<       else >*/
	    } else {
/* SOURCE xsection.for:3910 */
/*<       iold=ie >*/
		iold = ie;
/* SOURCE xsection.for:3911 */
/*<       inew=is+3 >*/
		inew = is + 3;
/* SOURCE xsection.for:3912 */
/*<       callshift_values(stdout,iold,inew,npnt,x,z,sb,lsn,sn) >*/
		feq_gen_shift_values_d_(stdout, &iold, &inew, npnt, &x[1], &feq_gen_z_d_[1], &
			sb[1], &lsn[1], &sn[1]);
/* SOURCE xsection.for:3915 */
/*<       x(is+1)=xl >*/
		x[is + 1] = xl;
/* SOURCE xsection.for:3916 */
/*<       z(is+1)=zl >*/
		feq_gen_z_d_[is + 1] = zl;
/* SOURCE xsection.for:3917 */
/*<       sb(is+1)=nsub >*/
		sb[is + 1] = *nsub;
/* SOURCE xsection.for:3918 */
/*<       sn(is+1)=1. >*/
		sn[is + 1] = (float)1.;
/* SOURCE xsection.for:3919 */
/*<       lsn(is+1)=n(nsub) >*/
		lsn[is + 1] = n[*nsub];
/* SOURCE xsection.for:3921 */
/*<       x(is+2)=slot_xm >*/
		x[is + 2] = feq_gen_slot_xm_d_;
/* SOURCE xsection.for:3922 */
/*<       z(is+2)=slot_zm >*/
		feq_gen_z_d_[is + 2] = feq_gen_slot_zm_d_;
/* SOURCE xsection.for:3923 */
/*<       sb(is+2)=nsub >*/
		sb[is + 2] = *nsub;
/* SOURCE xsection.for:3924 */
/*<       sn(is+2)=1. >*/
		sn[is + 2] = (float)1.;
/* SOURCE xsection.for:3925 */
/*<       lsn(is+2)=n(nsub) >*/
		lsn[is + 2] = n[*nsub];
/* SOURCE xsection.for:3926 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3927 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:3928 */
/*<       if(smatch.eq.'Y')then >*/
	    if (*(unsigned char *)smatch == 'Y') {
/* SOURCE xsection.for:3929 */
/*<       iold=ie+1 >*/
		iold = ie + 1;
/* SOURCE xsection.for:3930 */
/*<       inew=is+3 >*/
		inew = is + 3;
/* SOURCE xsection.for:3931 */
/*<       callshift_values(stdout,iold,inew,npnt,x,z,sb,lsn,sn) >*/
		feq_gen_shift_values_d_(stdout, &iold, &inew, npnt, &x[1], &feq_gen_z_d_[1], &
			sb[1], &lsn[1], &sn[1]);
/* SOURCE xsection.for:3934 */
/*<       x(is+1)=slot_xm >*/
		x[is + 1] = feq_gen_slot_xm_d_;
/* SOURCE xsection.for:3935 */
/*<       z(is+1)=slot_zm >*/
		feq_gen_z_d_[is + 1] = feq_gen_slot_zm_d_;
/* SOURCE xsection.for:3936 */
/*<       sb(is+1)=nsub >*/
		sb[is + 1] = *nsub;
/* SOURCE xsection.for:3937 */
/*<       sn(is+1)=1. >*/
		sn[is + 1] = (float)1.;
/* SOURCE xsection.for:3938 */
/*<       lsn(is+1)=n(nsub) >*/
		lsn[is + 1] = n[*nsub];
/* SOURCE xsection.for:3940 */
/*<       x(is+2)=xr >*/
		x[is + 2] = xr;
/* SOURCE xsection.for:3941 */
/*<       z(is+2)=zr >*/
		feq_gen_z_d_[is + 2] = zr;
/* SOURCE xsection.for:3942 */
/*<       sb(is+2)=saved_sub >*/
		sb[is + 2] = feq_gen_saved_sub_d_;
/* SOURCE xsection.for:3943 */
/*<       sn(is+2)=1. >*/
		sn[is + 2] = (float)1.;
/* SOURCE xsection.for:3944 */
/*<       lsn(is+2)=n(saved_sub) >*/
		lsn[is + 2] = n[feq_gen_saved_sub_d_];
/* SOURCE xsection.for:3945 */
/*<       else >*/
	    } else {
/* SOURCE xsection.for:3946 */
/*<       iold=ie+1 >*/
		iold = ie + 1;
/* SOURCE xsection.for:3947 */
/*<       inew=is+4 >*/
		inew = is + 4;
/* SOURCE xsection.for:3948 */
/*<       callshift_values(stdout,iold,inew,npnt,x,z,sb,lsn,sn) >*/
		feq_gen_shift_values_d_(stdout, &iold, &inew, npnt, &x[1], &feq_gen_z_d_[1], &
			sb[1], &lsn[1], &sn[1]);
/* SOURCE xsection.for:3951 */
/*<       x(is+1)=xl >*/
		x[is + 1] = xl;
/* SOURCE xsection.for:3952 */
/*<       z(is+1)=zl >*/
		feq_gen_z_d_[is + 1] = zl;
/* SOURCE xsection.for:3953 */
/*<       sb(is+1)=nsub >*/
		sb[is + 1] = *nsub;
/* SOURCE xsection.for:3954 */
/*<       sn(is+1)=1. >*/
		sn[is + 1] = (float)1.;
/* SOURCE xsection.for:3955 */
/*<       lsn(is+1)=n(nsub) >*/
		lsn[is + 1] = n[*nsub];
/* SOURCE xsection.for:3957 */
/*<       x(is+2)=slot_xm >*/
		x[is + 2] = feq_gen_slot_xm_d_;
/* SOURCE xsection.for:3958 */
/*<       z(is+2)=slot_zm >*/
		feq_gen_z_d_[is + 2] = feq_gen_slot_zm_d_;
/* SOURCE xsection.for:3959 */
/*<       sb(is+2)=nsub >*/
		sb[is + 2] = *nsub;
/* SOURCE xsection.for:3960 */
/*<       sn(is+2)=1. >*/
		sn[is + 2] = (float)1.;
/* SOURCE xsection.for:3961 */
/*<       lsn(is+2)=n(nsub) >*/
		lsn[is + 2] = n[*nsub];
/* SOURCE xsection.for:3963 */
/*<       x(is+3)=xr >*/
		x[is + 3] = xr;
/* SOURCE xsection.for:3964 */
/*<       z(is+3)=zr >*/
		feq_gen_z_d_[is + 3] = zr;
/* SOURCE xsection.for:3965 */
/*<       sb(is+3)=saved_sub >*/
		sb[is + 3] = feq_gen_saved_sub_d_;
/* SOURCE xsection.for:3966 */
/*<       sn(is+3)=1. >*/
		sn[is + 3] = (float)1.;
/* SOURCE xsection.for:3967 */
/*<       lsn(is+3)=n(saved_sub) >*/
		lsn[is + 3] = n[feq_gen_saved_sub_d_];
/* SOURCE xsection.for:3968 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:3969 */
/*<       endif >*/
	}
/* SOURCE xsection.for:3970 */
/*<       endif >*/
    }
/*     Adjust the subsection assignments */
/* SOURCE xsection.for:3973 */
/*<       callreasub(stdout,npnt,nsub,n,sb,eflag) >*/
    reasub_(stdout, npnt, nsub, &n[1], &sb[1], &eflag);
/* SOURCE xsection.for:3978 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:3979 */
/*<       end >*/
} /* add_slot__ */




/* SOURCE xsection.for:3984 */
/*<       subroutineset_slot(stdin,stdout,stdtab) >*/
/* Subroutine */ int feq_gen_set_slot_d_(integer *stdin, integer *stdout, integer *
	stdtab)
{
    /* Format strings */
    static char fmt_2[] = "(6x,f10.0)";
    static char fmt_4[] = "(6x,f10.0)";
    static char fmt_6[] = "(a5,1x,f10.0)";
    static char fmt_52[] = "(/,\002 Slot width for cross section invert=\002\
,f10.3)";
    static char fmt_54[] = "(/,\002 Slot n for cross section invert=\002,f10\
.3)";
    static char fmt_56[] = "(/,\002 Elevation of cross section slot invert\
=\002,f10.3)";
    static char fmt_58[] = "(/,\002 Depth of cross section slot invert=\002,\
f10.3)";
    static char fmt_60[] = "(\002; \002,a5,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char feq_gen_name_d_[5], line[80];
    real slot;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__439 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__440 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__443 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__444 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__445 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__446 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__447 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__448 = { 0, 0, 0, 0, 0 };


/*     Set the cross section slot values for the triangular slot */
/* SOURCE xsection.for:3988 */
/*<       integerstdin,stdout,stdtab >*/
/* INCLUDE xsection.for:3990 */
/*     Values used to keep track of a bottom slot in a cross section. */
/* SOURCE abslot.cmn:3 */
/*<       integerslot_present >*/
/* SOURCE abslot.cmn:5 */
/*<       realnslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:7 */
/*<       common/abslot/slot_present,nslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:10 */
/*<       save/abslot/ >*/
/*     SLOT_PRESENT: 0 no slot. 1 triangular slot, 2 exponential slot */
/*     NSLOT:  Manning's n for the slot if nslot > 0.  If nslot < 0.0 */
/*             use the average of the Manning's n's at the edges of the slot */
/*             and multiply by abs(nslot).  E. g. -1.2 computes the average value */
/*             of manning's n from the two bounding values in the cross section */
/*             and multiplies this averge by 1.2 to get the manning's n for the slot */
/*     WSLOT: width of the slot at the invert elevation of the cross section for a triangular */
/*            slot.  For the default exponential slot, it also gives the width of the slot */
/*            at the section invert.  If non-default values of rd are used, then the */
/*            meaning may differ. */
/*     ESLOT: elevation of the invert of the slot. */
/*     YSLOT: distance from slot invert to the cross section invert. */
/*     RD - factor on yslot to compute the y0 value for the exponential slot. */
/*          default value= 0.379376194959581.  This value together with the default */
/*          value of tzero has some convenient properties. */
/*     TZERO - width of the triangular section that forms the bottom portion of the */
/*             exponential slot.  Default value = 0.1*rd*wslot.  This default gives */
/*             an exponential slot with a width at the top of WSLOT.   A value of */
/*             wslot = 1/rd gives an area equal to the triangular slot with a */
/*             top width of 1.0. */
/*     EXPFAC - factor on the exponent in the exponential channel. Default value=1.0 */
/*              expfac > 1 gives a top-width increase larger than the default. */

/*     Only one of ESLOT or YSLOT is used.  YSLOT is the better choice for consistent */
/*     interpolation between sections. */
/*     Local */
/* SOURCE xsection.for:3994 */
/*<       realslot >*/
/* SOURCE xsection.for:3995 */
/*<       characterline*80,name*5 >*/
/*     *******************************FORMATS**************************** */
/* SOURCE xsection.for:3998 */
/*<     2 format(6x,f10.0) >*/
/* SOURCE xsection.for:3999 */
/*<     4 format(6x,f10.0) >*/
/* SOURCE xsection.for:4000 */
/*<     6 format(a5,1x,f10.0) >*/
/* SOURCE xsection.for:4002 */
/*<    52 format(/,' Slot width for cross section invert=',f10.3) >*/
/* SOURCE xsection.for:4003 */
/*<    54 format(/,' Slot n for cross section invert=',f10.3) >*/
/* SOURCE xsection.for:4004 */
/*<    56 format(/,' Elevation of cross section slot invert=',f10.3) >*/
/* SOURCE xsection.for:4005 */
/*<    58 format(/,' Depth of cross section slot invert=',f10.3) >*/
/* SOURCE xsection.for:4006 */
/*<    60 format('; ',a5,f10.2) >*/
/* *********************************************************************** */
/* SOURCE xsection.for:4008 */
/*<       callinline(stdin,stdout,line) >*/
/* L2: */
/* L4: */
/* L6: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4011 */
/*<       read(line,2,err=991)wslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&abslot_1.wslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:4012 */
/*<       write(stdout,52)wslot >*/
    feq_gen_io_d__439.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__439);
    do_fio(&feq_gen_c_d_1, (char *)&abslot_1.wslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:4013 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4016 */
/*<       read(line,4,err=991)nslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&abslot_1.nslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:4017 */
/*<       write(stdout,54)nslot >*/
    feq_gen_io_d__440.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__440);
    do_fio(&feq_gen_c_d_1, (char *)&abslot_1.nslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:4018 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4021 */
/*<       read(line,6,err=991)name,slot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&slot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:4022 */
/*<       if(name.eq.'ESLOT')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>("ESLOT"), (ftnlen)5, (ftnlen)5) == 0) {
/*       Set the fixed invert elevation. */
/* SOURCE xsection.for:4024 */
/*<       eslot=slot >*/
	abslot_1.eslot = slot;
/*       Set fixed slot depth to invalid negative */
/*       value */
/* SOURCE xsection.for:4027 */
/*<       yslot=-1.0 >*/
	abslot_1.yslot = (float)-1.;
/* SOURCE xsection.for:4028 */
/*<       else >*/
    } else {
/*       Set the fixed slot depth */
/* SOURCE xsection.for:4030 */
/*<       yslot=slot >*/
	abslot_1.yslot = slot;
/* SOURCE xsection.for:4031 */
/*<       eslot=0.0 >*/
	abslot_1.eslot = (float)0.;
/* SOURCE xsection.for:4032 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4033 */
/*<       if(yslot.lt.0.0)then >*/
    if (abslot_1.yslot < (float)0.) {
/* SOURCE xsection.for:4034 */
/*<       write(stdout,56)eslot >*/
	feq_gen_io_d__443.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__443);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.eslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4035 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4036 */
/*<       write(stdout,58)yslot >*/
	feq_gen_io_d__444.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__444);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.yslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4037 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4039 */
/*<       slot_present=1 >*/
    abslot_1.feq_gen_slot_present_d_ = 1;
/*     Output signal as a comment in the table file. */
/* SOURCE xsection.for:4042 */
/*<       if(yslot.lt.0.0)then >*/
    if (abslot_1.yslot < (float)0.) {
/* SOURCE xsection.for:4043 */
/*<       write(stdtab,60)name,eslot >*/
	feq_gen_io_d__445.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__445);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.eslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4044 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4045 */
/*<       write(stdtab,60)name,yslot >*/
	feq_gen_io_d__446.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__446);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.yslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4046 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4048 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:4050 */
/*<   991 continue >*/
L991:
/* SOURCE xsection.for:4051 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__447.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__447);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE xsection.for:4052 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__448.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__448);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE xsection.for:4053 */
/*<       stop'Abnormal stop' >*/
    s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:4055 */
/*<       end >*/
    return 0;
} /* set_slot__ */




/* SOURCE xsection.for:4060 */
/*<       subroutineset_slote(stdin,stdout,stdtab) >*/
/* Subroutine */ int feq_gen_set_slote_d_(integer *stdin, integer *stdout, integer *
	stdtab)
{
    /* Format strings */
    static char fmt_2[] = "(6x,f10.0)";
    static char fmt_4[] = "(6x,f10.0)";
    static char fmt_6[] = "(a5,1x,f10.0)";
    static char fmt_52[] = "(/,\002 Slot width for cross section invert=\002\
,f10.3)";
    static char fmt_54[] = "(/,\002 Slot n for cross section invert=\002,f10\
.3)";
    static char fmt_56[] = "(/,\002 Elevation of cross section slot invert\
=\002,f10.3)";
    static char fmt_58[] = "(/,\002 Depth of cross section slot invert=\002,\
f10.3)";
    static char fmt_60[] = "(\002; \002,a5,f10.2,\002 Exponential slot.\002)";
    static char fmt_62[] = "(/,\002 Relative depth parameter=\002,f10.7)";
    static char fmt_64[] = "(/,\002 Top width of base section=\002,f10.6)";
    static char fmt_66[] = "(/,\002 Factor on exponent=\002,f10.6)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen),
	     f_back(alist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char feq_gen_name_d_[5], line[80];
    real slot;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__450 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__451 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__454 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__455 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__456 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__457 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__458 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__459 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__460 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__461 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__462 = { 0, 0, 0, 0, 0 };


/*     Set the cross section slot values for the exponential slot */
/* SOURCE xsection.for:4064 */
/*<       integerstdin,stdout,stdtab >*/
/* INCLUDE xsection.for:4066 */
/*     Values used to keep track of a bottom slot in a cross section. */
/* SOURCE abslot.cmn:3 */
/*<       integerslot_present >*/
/* SOURCE abslot.cmn:5 */
/*<       realnslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:7 */
/*<       common/abslot/slot_present,nslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:10 */
/*<       save/abslot/ >*/
/*     SLOT_PRESENT: 0 no slot. 1 triangular slot, 2 exponential slot */
/*     NSLOT:  Manning's n for the slot if nslot > 0.  If nslot < 0.0 */
/*             use the average of the Manning's n's at the edges of the slot */
/*             and multiply by abs(nslot).  E. g. -1.2 computes the average value */
/*             of manning's n from the two bounding values in the cross section */
/*             and multiplies this averge by 1.2 to get the manning's n for the slot */
/*     WSLOT: width of the slot at the invert elevation of the cross section for a triangular */
/*            slot.  For the default exponential slot, it also gives the width of the slot */
/*            at the section invert.  If non-default values of rd are used, then the */
/*            meaning may differ. */
/*     ESLOT: elevation of the invert of the slot. */
/*     YSLOT: distance from slot invert to the cross section invert. */
/*     RD - factor on yslot to compute the y0 value for the exponential slot. */
/*          default value= 0.379376194959581.  This value together with the default */
/*          value of tzero has some convenient properties. */
/*     TZERO - width of the triangular section that forms the bottom portion of the */
/*             exponential slot.  Default value = 0.1*rd*wslot.  This default gives */
/*             an exponential slot with a width at the top of WSLOT.   A value of */
/*             wslot = 1/rd gives an area equal to the triangular slot with a */
/*             top width of 1.0. */
/*     EXPFAC - factor on the exponent in the exponential channel. Default value=1.0 */
/*              expfac > 1 gives a top-width increase larger than the default. */

/*     Only one of ESLOT or YSLOT is used.  YSLOT is the better choice for consistent */
/*     interpolation between sections. */
/*     Local */
/* SOURCE xsection.for:4070 */
/*<       realslot >*/
/* SOURCE xsection.for:4071 */
/*<       characterline*80,name*5 >*/
/*     *******************************FORMATS**************************** */
/* SOURCE xsection.for:4074 */
/*<     2 format(6x,f10.0) >*/
/* SOURCE xsection.for:4075 */
/*<     4 format(6x,f10.0) >*/
/* SOURCE xsection.for:4076 */
/*<     6 format(a5,1x,f10.0) >*/
/* SOURCE xsection.for:4078 */
/*<    52 format(/,' Slot width for cross section invert=',f10.3) >*/
/* SOURCE xsection.for:4079 */
/*<    54 format(/,' Slot n for cross section invert=',f10.3) >*/
/* SOURCE xsection.for:4080 */
/*<    56 format(/,' Elevation of cross section slot invert=',f10.3) >*/
/* SOURCE xsection.for:4081 */
/*<    58 format(/,' Depth of cross section slot invert=',f10.3) >*/
/* SOURCE xsection.for:4082 */
/*<    60 format('; ',a5,f10.2,' Exponential slot.') >*/
/* SOURCE xsection.for:4083 */
/*<    62 format(/,' Relative depth parameter=',f10.7) >*/
/* SOURCE xsection.for:4084 */
/*<    64 format(/,' Top width of base section=',f10.6) >*/
/* SOURCE xsection.for:4085 */
/*<    66 format(/,' Factor on exponent=',f10.6) >*/
/* *********************************************************************** */
/*     Set default values */
/* SOURCE xsection.for:4088 */
/*<       rd=0.37937619 >*/
/* L2: */
/* L4: */
/* L6: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
/* L66: */
    abslot_1.rd = (float).37937619;
/* SOURCE xsection.for:4089 */
/*<       expfac=1.0 >*/
    abslot_1.expfac = (float)1.;
/*     Set  base top width to signal use of default */
/* SOURCE xsection.for:4091 */
/*<       tzero=-1.0 >*/
    abslot_1.tzero = (float)-1.;
/* SOURCE xsection.for:4093 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4096 */
/*<       read(line,2,err=991)wslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&abslot_1.wslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:4097 */
/*<       write(stdout,52)wslot >*/
    feq_gen_io_d__450.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__450);
    do_fio(&feq_gen_c_d_1, (char *)&abslot_1.wslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:4100 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4103 */
/*<       read(line,4,err=991)nslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&abslot_1.nslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:4104 */
/*<       write(stdout,54)nslot >*/
    feq_gen_io_d__451.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__451);
    do_fio(&feq_gen_c_d_1, (char *)&abslot_1.nslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:4105 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4108 */
/*<       read(line,6,err=991)name,slot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&slot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:4109 */
/*<       if(name.eq.'ESLOT')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>("ESLOT"), (ftnlen)5, (ftnlen)5) == 0) {
/*       Set the fixed invert elevation. */
/* SOURCE xsection.for:4111 */
/*<       eslot=slot >*/
	abslot_1.eslot = slot;
/*       Set fixed slot depth to invalid negative */
/*       value */
/* SOURCE xsection.for:4114 */
/*<       yslot=-1.0 >*/
	abslot_1.yslot = (float)-1.;
/* SOURCE xsection.for:4115 */
/*<       else >*/
    } else {
/*       Set the fixed slot depth */
/* SOURCE xsection.for:4117 */
/*<       yslot=slot >*/
	abslot_1.yslot = slot;
/* SOURCE xsection.for:4118 */
/*<       eslot=0.0 >*/
	abslot_1.eslot = (float)0.;
/* SOURCE xsection.for:4119 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4120 */
/*<       if(yslot.lt.0.0)then >*/
    if (abslot_1.yslot < (float)0.) {
/* SOURCE xsection.for:4121 */
/*<       write(stdout,56)eslot >*/
	feq_gen_io_d__454.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__454);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.eslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4122 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4123 */
/*<       write(stdout,58)yslot >*/
	feq_gen_io_d__455.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__455);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.yslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4124 */
/*<       endif >*/
    }
/*     Get the optional parameter input values. */
/* SOURCE xsection.for:4127 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4131 */
/*<       if(line(1:6).eq.'RDEPTH')then >*/
    if (s_cmp(line, const_cast<char*>("RDEPTH"), (ftnlen)6, (ftnlen)6) == 0) {
/* SOURCE xsection.for:4132 */
/*<       read(line(8:),'(f10.0)')rd >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 73;
	feq_gen_ici_d_1.iciunit = line + 7;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(f10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.rd, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE xsection.for:4133 */
/*<       write(stdout,62)rd >*/
	feq_gen_io_d__456.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__456);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.rd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4134 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4135 */
/*<       backspace(stdin) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE xsection.for:4136 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4137 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4141 */
/*<       if(line(1:5).eq.'TZERO')then >*/
    if (s_cmp(line, const_cast<char*>("TZERO"), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE xsection.for:4142 */
/*<       read(line(7:),'(f10.0)')tzero >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 74;
	feq_gen_ici_d_1.iciunit = line + 6;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(f10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.tzero, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE xsection.for:4143 */
/*<       write(stdout,64)tzero >*/
	feq_gen_io_d__457.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__457);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.tzero, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4144 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4145 */
/*<       backspace(stdin) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE xsection.for:4146 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4147 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4151 */
/*<       if(line(1:6).eq.'EXPFAC')then >*/
    if (s_cmp(line, const_cast<char*>("EXPFAC"), (ftnlen)6, (ftnlen)6) == 0) {
/* SOURCE xsection.for:4152 */
/*<       read(line(8:),'(f10.0)')expfac >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 73;
	feq_gen_ici_d_1.iciunit = line + 7;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(f10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.expfac, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE xsection.for:4153 */
/*<       write(stdout,66)expfac >*/
	feq_gen_io_d__458.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__458);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.expfac, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4154 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4155 */
/*<       backspace(stdin) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE xsection.for:4156 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4158 */
/*<       slot_present=2 >*/
    abslot_1.feq_gen_slot_present_d_ = 2;
/*     Output signal as a comment in the table file. */
/* SOURCE xsection.for:4161 */
/*<       if(yslot.lt.0.0)then >*/
    if (abslot_1.yslot < (float)0.) {
/* SOURCE xsection.for:4162 */
/*<       write(stdtab,60)name,eslot >*/
	feq_gen_io_d__459.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__459);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.eslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4163 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4164 */
/*<       write(stdtab,60)name,yslot >*/
	feq_gen_io_d__460.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__460);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&abslot_1.yslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4165 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4167 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:4169 */
/*<   991 continue >*/
L991:
/* SOURCE xsection.for:4170 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__461.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__461);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE xsection.for:4171 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__462.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__462);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE xsection.for:4172 */
/*<       stop'Abnormal stop' >*/
    s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:4174 */
/*<       end >*/
    return 0;
} /* set_slote__ */




/* SOURCE xsection.for:4179 */
/*<       subroutineclear_slot(stdtab) >*/
/* Subroutine */ int feq_gen_clear_slot_d_(integer *stdtab)
{
    /* Format strings */
    static char fmt_50[] = "(\002; CLRSLOT\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__463 = { 0, 0, 0, fmt_50, 0 };


/*     Clear the slot values for cross section inverts. */
/* SOURCE xsection.for:4183 */
/*<       implicitnone >*/
/* SOURCE xsection.for:4184 */
/*<       integerstdtab >*/
/* INCLUDE xsection.for:4185 */
/*     Values used to keep track of a bottom slot in a cross section. */
/* SOURCE abslot.cmn:3 */
/*<       integerslot_present >*/
/* SOURCE abslot.cmn:5 */
/*<       realnslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:7 */
/*<       common/abslot/slot_present,nslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:10 */
/*<       save/abslot/ >*/
/*     SLOT_PRESENT: 0 no slot. 1 triangular slot, 2 exponential slot */
/*     NSLOT:  Manning's n for the slot if nslot > 0.  If nslot < 0.0 */
/*             use the average of the Manning's n's at the edges of the slot */
/*             and multiply by abs(nslot).  E. g. -1.2 computes the average value */
/*             of manning's n from the two bounding values in the cross section */
/*             and multiplies this averge by 1.2 to get the manning's n for the slot */
/*     WSLOT: width of the slot at the invert elevation of the cross section for a triangular */
/*            slot.  For the default exponential slot, it also gives the width of the slot */
/*            at the section invert.  If non-default values of rd are used, then the */
/*            meaning may differ. */
/*     ESLOT: elevation of the invert of the slot. */
/*     YSLOT: distance from slot invert to the cross section invert. */
/*     RD - factor on yslot to compute the y0 value for the exponential slot. */
/*          default value= 0.379376194959581.  This value together with the default */
/*          value of tzero has some convenient properties. */
/*     TZERO - width of the triangular section that forms the bottom portion of the */
/*             exponential slot.  Default value = 0.1*rd*wslot.  This default gives */
/*             an exponential slot with a width at the top of WSLOT.   A value of */
/*             wslot = 1/rd gives an area equal to the triangular slot with a */
/*             top width of 1.0. */
/*     EXPFAC - factor on the exponent in the exponential channel. Default value=1.0 */
/*              expfac > 1 gives a top-width increase larger than the default. */

/*     Only one of ESLOT or YSLOT is used.  YSLOT is the better choice for consistent */
/*     interpolation between sections. */
/*     *****************************FORMATS****************************** */
/* SOURCE xsection.for:4187 */
/*<    50 format('; CLRSLOT') >*/
/* *********************************************************************** */
/* SOURCE xsection.for:4189 */
/*<       slot_present=0 >*/
/* L50: */
    abslot_1.feq_gen_slot_present_d_ = 0;
/* SOURCE xsection.for:4190 */
/*<       wslot=0.0 >*/
    abslot_1.wslot = (float)0.;
/* SOURCE xsection.for:4191 */
/*<       nslot=0.0 >*/
    abslot_1.nslot = (float)0.;
/* SOURCE xsection.for:4192 */
/*<       eslot=-999999. >*/
    abslot_1.eslot = (float)-999999.;
/* SOURCE xsection.for:4193 */
/*<       yslot=-1.0 >*/
    abslot_1.yslot = (float)-1.;
/* SOURCE xsection.for:4194 */
/*<       write(stdtab,50) >*/
    feq_gen_io_d__463.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__463);
    e_wsfe();
/* SOURCE xsection.for:4195 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:4196 */
/*<       end >*/
} /* clear_slot__ */




/* SOURCE xsection.for:4201 */
/*<        >*/
/* Subroutine */ int cxstab_(integer *stdout, integer *nsuba, integer *navm, 
	real *nfac, integer *maxpnt, real *left, real *right, char *betopt, 
	integer *snflg, integer *feq_storage_nvar, real *feq_storage_naty, real *feq_storage_yatn, integer *feq_storage_nny, 
	integer *npnt, real *zmin, real *zmax, real *feq_storage_x, real *feq_gen_feq_storage_z_d_, integer *
	feq_storage_sb, integer *eflag, real *feq_storage_lsn, real *feq_storage_sn, real *feq_storage_n, integer *ndep, real 
	*feq_storage_xst, ftnlen betopt_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Subset request being processed\002)";
    static char fmt_52[] = "(/,\002 *ERR:633* Only one point remains on the \
cross section.\002,/,10x,\002 Automatic extension required to compute.\002)";
    static char fmt_54[] = "(/,\002*PROBLEM* Subset operations on cross sect\
ions with\002,\002 roughness varying with depth not yet supported.\002)";

    /* System generated locals */
    integer xst_dim1, xst_offset, feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_add_slot_d_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, integer *, real *, 
	    real *, integer *);
    integer feq_gen_i_d_, j;
    extern /* Subroutine */ int feq_gen_add_slote_d_(integer *, real *, integer *, 
	    integer *, integer *, real *, real *, real *, real *, integer *, 
	    real *, real *, integer *);
    integer jj;
    real zt[999];
    integer lim;
    real sns[1001], xsv[22], kold[200];
    extern /* Subroutine */ int xchk_(integer *, integer *, real *, real *, 
	    real *, real *);
    integer nsub;
    extern /* Subroutine */ int rdup_(integer *, real *, integer *);
    real lsns[1001], xsub[1001], zsub[1001];
    extern /* Subroutine */ int sort_(integer *, real *);
    integer added, wrn557, sbsub[1001];
    real tsold[200];
    integer npnts;
    extern /* Subroutine */ int chkarg_(integer *, integer *, real *, real *, 
	    integer *, integer *, real *), compel_(real *, integer *, integer 
	    *, integer *, real *, real *, integer *, real *, char *, integer *
	    , real *, integer *, real *, real *, integer *, real *, integer *,
	     real *, real *, real *, real *, ftnlen);
    real submin;
    extern /* Subroutine */ int subset_(integer *, integer *, real *, real *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    integer *, real *, real *, integer *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__465 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__473 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__476 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Compute cross section table from basic information. */
/* SOURCE xsection.for:4210 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE xsection.for:4213 */
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
/* SOURCE xsection.for:4216 */
/*<       integereflag,maxpnt,navm,ndep,npnt,nsuba,snflg,stdout >*/
/* SOURCE xsection.for:4217 */
/*<       integernny(pmxsub),nvar(pmxsub),sb(pmxpnt) >*/
/* SOURCE xsection.for:4218 */
/*<        >*/
/* SOURCE xsection.for:4222 */
/*<       characterbetopt*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NSUBA  - Number of subsections */
/*     NAVM   - Flag for averaging roughness */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     MAXPNT - Maximum number of tabulated values in a cross section */
/*               function table */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     BETOPT - Option for computing flux coefficients and critical flow */
/*     SNFLG  - Flag for sinuousity computations */
/*     NVAR   - Flag for variation of Manning's n in each subsection */
/*     NATY   - Mannings's n value at depth in YATN */
/*     YATN   - Depth values for the Manning's n values in NATY */
/*     NNY    - Number of values for Manning's n variation with depth */
/*     NPNT   - Number of points on boundary of a cross section */
/*     ZMIN   - Minimum elevation */
/*     ZMAX   - Maximum elevation */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     LSN    - Line segment Manning's n value */
/*     SN     - Sinuousity at a point on a cross section boundary */
/*     N      - Manning's n values */
/*     NDEP   - Number of depth values */
/*     XST    - Storage table for various elements of cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:4256 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:4259 */
/*<       integeradded,i,j,jj,lim,npnts,nsub,wrn557 >*/
/* SOURCE xsection.for:4260 */
/*<       integersbsub(pmxpnt+2) >*/
/* SOURCE xsection.for:4261 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:4266 */
/*<       externalchkarg,compel,rdup,sort,subset,xchk >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:4269 */
/*<    50 format(/,' Subset request being processed') >*/
/* SOURCE xsection.for:4270 */
/*<    52  >*/
/* SOURCE xsection.for:4273 */
/*<    54  >*/
/* *********************************************************************** */
/* SOURCE xsection.for:4276 */
/*<       nsub=nsuba >*/
    /* Parameter adjustments */
    xst_dim1 = *maxpnt;
    xst_offset = 1 + xst_dim1;

    feq::IndexedPointer<real> xst(feq_storage_xst, xst_offset);

    feq::IndexedPointer<integer> nvar(feq_storage_nvar, 1);

    feq::IndexedPointer<real> naty(feq_storage_naty, 10);

    feq::IndexedPointer<real> yatn(feq_storage_yatn, 10);

    feq::IndexedPointer<integer> nny(feq_storage_nny, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    nsub = *nsuba;
/*     Check for a subset operation before doing anything else: Jan.22, 2001 */
/* SOURCE xsection.for:4278 */
/*<       if(left.lt.right)then >*/
    if (*left < *right) {
/*       WE HAVE A SUBSET REQUEST */
/* SOURCE xsection.for:4281 */
/*<       if(nvar(1)==0)then >*/
	if (nvar[1] == 0) {
/* SOURCE xsection.for:4282 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__465.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__465);
	    e_wsfe();
/* SOURCE xsection.for:4283 */
/*<       npnts=npnt+2 >*/
	    npnts = *npnt + 2;
/* SOURCE xsection.for:4284 */
/*<        >*/
	    subset_(stdout, npnt, &x[1], &feq_gen_z_d_[1], &sb[1], zmax, &sn[1], &lsn[
		    1], left, right, eflag, &npnts, xsub, zsub, sbsub, sns, 
		    lsns);
/*         Change the number of subsections to force the walls added in */
/*         SUBSET to be frictionless. */
/* SOURCE xsection.for:4291 */
/*<       sbsub(1)=nsub+1 >*/
	    sbsub[0] = nsub + 1;
/* SOURCE xsection.for:4292 */
/*<       sbsub(npnts-1)=nsub+2 >*/
	    sbsub[npnts - 2] = nsub + 2;
/* SOURCE xsection.for:4293 */
/*<       nsub=nsub+2 >*/
	    nsub += 2;
/* SOURCE xsection.for:4295 */
/*<       doj=1,npnts >*/
	    feq_gen_i_d_1 = npnts;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:4296 */
/*<       x(j)=xsub(j) >*/
		x[j] = xsub[j - 1];
/* SOURCE xsection.for:4297 */
/*<       z(j)=zsub(j) >*/
		feq_gen_z_d_[j] = zsub[j - 1];
/* SOURCE xsection.for:4298 */
/*<       sb(j)=sbsub(j) >*/
		sb[j] = sbsub[j - 1];
/* SOURCE xsection.for:4299 */
/*<       sn(j)=sns(j) >*/
		sn[j] = sns[j - 1];
/* SOURCE xsection.for:4300 */
/*<       lsn(j)=lsns(j) >*/
		lsn[j] = lsns[j - 1];
/* SOURCE xsection.for:4301 */
/*<       enddo >*/
	    }
/* SOURCE xsection.for:4302 */
/*<       npnt=npnts >*/
	    *npnt = npnts;
/* SOURCE xsection.for:4303 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:4304 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__473.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__473);
	    e_wsfe();
/* SOURCE xsection.for:4305 */
/*<       stop'Abnormal stop. Feature not yet supported.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Feature not yet supported."), (ftnlen)41);
/* SOURCE xsection.for:4306 */
/*<       endif >*/
	}
/* SOURCE xsection.for:4307 */
/*<       endif >*/
    }
/*     Each subroutine checks data to determine which should work */
/* SOURCE xsection.for:4311 */
/*<       calladd_slot(stdout,nvar(1),npnt,nsub,n,zmin,x,z,sb,lsn,sn,added) >*/
    feq_gen_add_slot_d_(stdout, &nvar[1], npnt, &nsub, &n[1], zmin, &x[1], &feq_gen_z_d_[1], &
	    sb[1], &lsn[1], &sn[1], &added);
/* SOURCE xsection.for:4316 */
/*<        >*/
    feq_gen_add_slote_d_(stdout, nfac, &nvar[1], npnt, &nsub, &n[1], zmin, &x[1], &feq_gen_z_d_[
	    1], &sb[1], &lsn[1], &sn[1], &added);
/*     Set all values of nvar to 0, to indicate constant Manning's n in each */
/*     subsection.  This is the only option supported for slot insertion */
/*     as of 31 August 2007.  If the computations reach here, then the */
/*     variation of Manning's n IS constant, so we make sure that all */
/*     values in nvar say that! */
/*      BUG FIX, commented out below line on 03.23.2009 per email from Delbert */
/*      Franz, documented in fixlist for version 5.93 */
/*      nvar = 0 */
/*      WRITE(STDOUT,*) ' ' */
/*      WRITE(STDOUT,*) ' Check of adjusted cross section boundary.' */
/*      WRITE(STDOUT,*) ' NPNT=',NPNT */
/*      write(stdout,*) ' nsub=',nsub */
/*      WRITE(STDOUT,89) */
/* 89    FORMAT(' Index     Offset  Elevation Subs       Lsn        Sn') */
/*      DO 1234 I=1,NPNT */
/*        WRITE(STDOUT,90) I, X(I), Z(I), SB(I), LSN(I), SN(I) */
/* 90    FORMAT(' ',I5,2F11.4,I5,2F10.3) */
/* 1234  CONTINUE */
/*      WRITE(STDOUT,*) ' ' */
/*     CHECK FOR INVALID HORIZONTAL LINE SEGMENTS */
/* SOURCE xsection.for:4344 */
/*<       callxchk(stdout,npnt,zmin,x,nfac,z) >*/
    xchk_(stdout, npnt, zmin, &x[1], nfac, &feq_gen_z_d_[1]);
/*     TRANSFER ELEVATIONS TO WORK SPACE, SORT,AND REMOVE DUPLICATES */
/* SOURCE xsection.for:4350 */
/*<       do100j=1,npnt >*/
    feq_gen_i_d_1 = *npnt;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:4351 */
/*<       zt(j)=z(j) >*/
	zt[j - 1] = feq_gen_z_d_[j];
/* SOURCE xsection.for:4352 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE xsection.for:4354 */
/*<       callsort(npnt,zt) >*/
    sort_(npnt, zt);
/* SOURCE xsection.for:4357 */
/*<       callrdup(npnt,zt,ndep) >*/
    rdup_(npnt, zt, ndep);
/* SOURCE xsection.for:4362 */
/*<       if(extend.eq.0)then >*/
    if (nrdzcm_1.extend == 0) {
/*       SUPPRESS AUTOMATIC EXTENSION OF LOWER END OF CROSS SECTION. */
/*       ZMAX, ON ENTRY, GIVES THE DESIRED MAXIMUM. */
/* SOURCE xsection.for:4366 */
/*<       do110j=ndep,1,-1 >*/
	for (j = *ndep; j >= 1; --j) {
/* SOURCE xsection.for:4367 */
/*<       if(zmax.gt.zt(j))goto111 >*/
	    if (*zmax > zt[j - 1]) {
		goto L111;
	    }
/* SOURCE xsection.for:4368 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE xsection.for:4369 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__476.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__476);
	e_wsfe();
/* SOURCE xsection.for:4370 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE xsection.for:4371 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:4373 */
/*<   111 continue >*/
L111:
/* SOURCE xsection.for:4374 */
/*<       ndep=j+1 >*/
	*ndep = j + 1;
/* SOURCE xsection.for:4375 */
/*<       endif >*/
    }
/*     CHECK THE ARGUMENT SPACING FOR CONVEYANCE INTERPOLATION ACCURACY */
/* SOURCE xsection.for:4380 */
/*<       callchkarg(stdout,pmxpnt,nrzero,dzlim,added,ndep,zt) >*/
    chkarg_(stdout, &feq_gen_c_d_999, &nrdzcm_1.nrzero, &nrdzcm_1.dzlim, &added, ndep, 
	    zt);
/* SOURCE xsection.for:4383 */
/*<       zmin=zt(1) >*/
    *zmin = zt[0];
/* SOURCE xsection.for:4384 */
/*<       zmax=zt(ndep) >*/
    *zmax = zt[*ndep - 1];
/* SOURCE xsection.for:4387 */
/*<       submin=zmin >*/
    submin = *zmin;
/*      WRITE(STDOUT,*) ' BEFORE CALL TO COMPEL NDEP=',NDEP */
/* SOURCE xsection.for:4390 */
/*<       jj=0 >*/
    jj = 0;
/* SOURCE xsection.for:4391 */
/*<       do195j=1,nsub >*/
    feq_gen_i_d_1 = nsub;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:4392 */
/*<       kold(j)=0.0 >*/
	kold[j - 1] = (float)0.;
/* SOURCE xsection.for:4393 */
/*<       tsold(j)=1.e30 >*/
	tsold[j - 1] = (float)1e30;
/* SOURCE xsection.for:4394 */
/*<   195 continue >*/
/* L195: */
    }
/* SOURCE xsection.for:4395 */
/*<       wrn557=1 >*/
    wrn557 = 1;
/* SOURCE xsection.for:4396 */
/*<       do200j=1,ndep >*/
    feq_gen_i_d_1 = *ndep;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:4397 */
/*<       if(zt(j).ge.submin)then >*/
	if (zt[j - 1] >= submin) {
/* SOURCE xsection.for:4398 */
/*<       jj=jj+1 >*/
	    ++jj;
/* SOURCE xsection.for:4400 */
/*<        >*/
	    compel_(&zt[j - 1], npnt, &nsub, navm, &x[1], &feq_gen_z_d_[1], &sb[1], 
		    nfac, betopt, snflg, &lsn[1], &nvar[1], &naty[10], &yatn[
		    10], &nny[1], &sn[1], &wrn557, kold, tsold, &n[1], xsv, (
		    ftnlen)8);
/* SOURCE xsection.for:4406 */
/*<       xsv(1)=zt(j)-submin >*/
	    xsv[0] = static_cast<double>(zt[j - 1]) - submin;
/* SOURCE xsection.for:4407 */
/*<       lim=17 >*/
	    lim = 17;
/*          IF(BETOPT(1:7).EQ.'NEWBETA') THEN */
/*            LIM = 13 */
/*          ELSE */
/*            LIM = 7 */
/*            XST(JJ,13) = XSV(13) */
/*          ENDIF */
/* SOURCE xsection.for:4414 */
/*<       do150i=1,lim >*/
	    feq_gen_i_d_2 = lim;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE xsection.for:4415 */
/*<       xst(jj,i)=xsv(i) >*/
		xst[jj + feq_gen_i_d_ * xst_dim1] = xsv[feq_gen_i_d_ - 1];
/* SOURCE xsection.for:4416 */
/*<   150 continue >*/
/* L150: */
	    }
/*          XST(J,14) = XSV(14) */
/*          XST(J,15) = XSV(15) */
/* SOURCE xsection.for:4419 */
/*<       endif >*/
	}
/* SOURCE xsection.for:4420 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE xsection.for:4421 */
/*<       ndep=jj >*/
    *ndep = jj;
/* SOURCE xsection.for:4422 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:4423 */
/*<       end >*/
} /* cxstab_ */




/* SOURCE xsection.for:4427 */
/*<        >*/
/* Subroutine */ int infeqx_(integer *stdin, integer *stdout, integer *maxpnt,
	 integer *mode, integer *feq_storage_tabdir, integer *eflag, integer *tab, real *
	stat, integer *npnt, integer *nsub, integer *navm, real *feq_storage_x, real *feq_gen_feq_storage_z_d_,
	 integer *feq_storage_sb, real *feq_storage_n, real *left, real *right, char *savopt, char *
	outopt, char *betopt, real *zmax, char *zone, char *hgrid, char *
	vdatum, char *unitsys, char *basis, ftnlen savopt_len, ftnlen 
	outopt_len, ftnlen betopt_len, ftnlen zone_len, ftnlen hgrid_len, 
	ftnlen vdatum_len, ftnlen unitsys_len, ftnlen basis_len)
{
    /* Format strings */
    static char fmt_4[] = "(a80)";
    static char fmt_5[] = "(2f10.0,i5)";
    static char fmt_51[] = "(/,\002 TabId= \002,a,5(1x,a8))";
    static char fmt_52[] = "(\002 NAVM=\002,i5,\002  Hor. scale factor=\002,\
f10.3,\002 Vert. shift=\002,f10.3,/,\002  Vert. scale factor=\002,f10.3,\002\
 Hor. shift=\002,f10.3)";
    static char fmt_53[] = "(\002 STATION=\002,f10.3,\002 LEFT=\002,f10.1\
,\002 RIGHT=\002,f10.1)";
    static char fmt_54[] = "(\002 STATION=\002,f10.3)";
    static char fmt_55[] = "(1x,a4,i5,6f6.3,1x,/,(10x,6f6.3))";
    static char fmt_56[] = "(1x,a80)";
    static char fmt_57[] = "(1x,f10.1,f10.2,i5)";
    static char fmt_59[] = "(\002 *ERR:505* SUBSECTION NUMBER TOO LARGE AT O\
FFSET=\002,f10.1)";
    static char fmt_60[] = "(\002 *WRN:501* SUBSECTION VALUE FOR FIRST POINT\
 IS\002,\002 MISSING.  SUBSECTION=1 ASSUMED.\002)";
    static char fmt_61[] = "(\002 *ERR:506* ONLY ONE POINT GIVEN ON BOUNDARY\
 OF THE\002,\002 CROSS SECTION.\002)";
    static char fmt_62[] = "(\002 *ERR:507* NUMBER OF POINTS IN CROSS SECTIO\
N >\002,i5)";
    static char fmt_65[] = "(\002 ZONE=\002,a8,\002 HGRID=\002,a8,\002 VDATU\
M=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8)";
    static char fmt_67[] = "(/,\002 *WRN:554* Extending left end of cross se\
ction\002,\002 by \002,f8.3)";
    static char fmt_68[] = "(/,\002 *WRN:555* Extending right end of cross s\
ection\002,\002 by \002,f8.3)";
    static char fmt_69[] = "(/,\002 *WRN:556* Some point in cross section hi\
gher than\002,\002 either end.\002,/,10x,\002All area above minimum end elev\
ation\002,\002 is ignored.\002)";
    static char fmt_70[] = "(/,\002 *ERR:647* Manning's N = 0 in subsectio\
n\002,i5,/,11x,\002Value set to 1.0.  Please correct and recompute.\002)";
    static char fmt_72[] = "(\002 GISID=\002,a16,\002 EASTING=\002,f15.3,\
\002 NORTHING=\002,f15.3)";
    static char fmt_73[] = "(\002  Processing FEQX TabId= \002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi()
	    , s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j, ie, is;
    char head[80], chr10[10], line[80];
    real xold;
    char varn[4];
    real scale;
    integer ntemp;
    real shift;
    char feq_gen_extend_string_d_[8];
    extern /* Subroutine */ int tabchk_(integer *, integer *, integer *, 
	    integer *, integer *);
    real vscale;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    real hshift;
    extern /* Subroutine */ int reasub_(integer *, integer *, integer *, real 
	    *, integer *, integer *);
    char monton[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int getnxt_(char *, integer *, integer *, char *, 
	    ftnlen, ftnlen), feq_gen_get_xsec_header_d_(integer *, integer *, integer *
	    , integer *, char *, char *, char *, char *, integer *, real *, 
	    real *, real *, char *, integer *, real *, real *, real *, real *,
	     integer *, real *, char *, char *, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__492 = { 0, 6, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__493 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__494 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__495 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__496 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__497 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__498 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__499 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__501 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__504 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__506 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__510 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__511 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__512 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__513 = { 0, 0, 0, fmt_59, 0 };
    static cilist feq_gen_io_d__514 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__515 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__516 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__517 = { 0, 0, 0, fmt_67, 0 };
    static cilist feq_gen_io_d__518 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__519 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__521 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__522 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__523 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__524 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__525 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__526 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__527 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__528 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__529 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input cross section in FEQX or FEQXLST format. */
/* SOURCE xsection.for:4437 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:4440 */
/*<       integereflag,maxpnt,mode,navm,npnt,nsub,stdin,stdout,tab >*/
/* SOURCE xsection.for:4441 */
/*<       integersb(*),tabdir(*) >*/
/* SOURCE xsection.for:4442 */
/*<       realleft,n(*),right,stat,x(*),z(*),zmax >*/
/* SOURCE xsection.for:4443 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     MAXPNT - Maximum number of tabulated values in a cross section */
/*               function table */
/*     MODE   - Mode of processing cross section boundary specification: */
/*               MODE=1: fixed format.  MODE=2: list format. */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TAB    - Table number */
/*     STAT   - Station value */
/*     NPNT   - Number of points on boundary of a cross section */
/*     NSUB   - Number of subsections */
/*     NAVM   - Flag for averaging roughness */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     N      - Manning's n values */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     SAVOPT - Function table saving option */
/*     OUTOPT - Output option for the table file for cross section function */
/*               tables */
/*     BETOPT - Option for computing flux coefficients and critical flow */
/*     ZMAX   - Maximum elevation */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:4476 */
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
/* INCLUDE xsection.for:4477 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE xsection.for:4478 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE xsection.for:4479 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:4482 */
/*<       integerie,is,j,ntemp >*/
/* SOURCE xsection.for:4483 */
/*<       realhshift,scale,shift,xold,vscale >*/
/* SOURCE xsection.for:4484 */
/*<       characterchr10*10,head*80,line*80,monton*8,extend_string*8,varn*4 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE xsection.for:4488 */
/*<       intrinsicabs,max,min >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:4491 */
/*<       integerlenstr >*/
/* SOURCE xsection.for:4492 */
/*<       externalgetnxt,inline,reasub,setopt,tabchk,lenstr >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE xsection.for:4495 */
/*<     1 format(7x,i5,a) >*/
/* SOURCE xsection.for:4496 */
/*<     2 format(8x,f10.0,6x,f10.0,7x,f10.0) >*/
/* SOURCE xsection.for:4497 */
/*<     3 format(a4,i5,6f10.0) >*/
/* SOURCE xsection.for:4498 */
/*<     4 format(a80) >*/
/* SOURCE xsection.for:4499 */
/*<     5 format(2f10.0,i5) >*/
/* SOURCE xsection.for:4500 */
/*<     6 format(5x,i5,7x,f10.0,7x,f10.0,8x,f10.0,8x,f10.0) >*/
/* SOURCE xsection.for:4501 */
/*<    31 format(9x,6f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:4504 */
/*<    51 format(/,' TabId= ',a,5(1x,a8)) >*/
/* SOURCE xsection.for:4505 */
/*<    52  >*/
/* SOURCE xsection.for:4508 */
/*<    53 format(' STATION=',f10.3,' LEFT=',f10.1,' RIGHT=',f10.1) >*/
/* SOURCE xsection.for:4509 */
/*<    54 format(' STATION=',f10.3) >*/
/* SOURCE xsection.for:4510 */
/*<    55 format(1x,a4,i5,6f6.3,1x,/,(10x,6f6.3)) >*/
/* SOURCE xsection.for:4511 */
/*<    56 format(1x,a80) >*/
/* SOURCE xsection.for:4512 */
/*<    57 format(1x,f10.1,f10.2,i5) >*/
/* SOURCE xsection.for:4513 */
/*<    58 format(' *ERR:504* NUMBER OF SUBSECTIONS=',i5,' > ',i5) >*/
/* SOURCE xsection.for:4514 */
/*<    59 format(' *ERR:505* SUBSECTION NUMBER TOO LARGE AT OFFSET=',f10.1) >*/
/* SOURCE xsection.for:4516 */
/*<    60  >*/
/* SOURCE xsection.for:4518 */
/*<    61  >*/
/* SOURCE xsection.for:4520 */
/*<    62 format(' *ERR:507* NUMBER OF POINTS IN CROSS SECTION >',i5) >*/
/* SOURCE xsection.for:4521 */
/*<    65  >*/
/* SOURCE xsection.for:4523 */
/*<    66  >*/
/* SOURCE xsection.for:4525 */
/*<    67  >*/
/* SOURCE xsection.for:4527 */
/*<    68  >*/
/* SOURCE xsection.for:4529 */
/*<    69  >*/
/* SOURCE xsection.for:4532 */
/*<    70  >*/
/* SOURCE xsection.for:4534 */
/*<    72 format(' GISID=',a16,' EASTING=',f15.3,' NORTHING=',f15.3) >*/
/* SOURCE xsection.for:4535 */
/*<    73 format('  Processing FEQX TabId= ',a) >*/
/* *********************************************************************** */
/* SOURCE xsection.for:4538 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> n(feq_storage_n, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L6: */
/* L31: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
/* L56: */
/* L57: */
/* L58: */
/* L59: */
/* L60: */
/* L61: */
/* L62: */
/* L65: */
/* L66: */
/* L67: */
/* L68: */
/* L69: */
/* L70: */
/* L72: */
/* L73: */
    feq_gen_get_xsec_header_d_(stdin, stdout, eflag, tab, savopt, outopt, monton, 
	    betopt, &nrdzcm_1.extend, stat, left, right, varn, navm, &scale, &
	    shift, &vscale, &hshift, nsub, &n[1], zone, hgrid, vdatum, 
	    unitsys, basis, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)4, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:4543 */
/*<       if(extend.eq.0)then >*/
    if (nrdzcm_1.extend == 0) {
/* SOURCE xsection.for:4544 */
/*<       extend_string='NOEXTEND' >*/
	s_copy(feq_gen_extend_string_d_, const_cast<char*>("NOEXTEND"), (ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:4545 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4546 */
/*<       extend_string='EXTEND' >*/
	s_copy(feq_gen_extend_string_d_, const_cast<char*>("EXTEND"), (ftnlen)8, (ftnlen)6);
/* SOURCE xsection.for:4547 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4548 */
/*<       write(*,73)tabid(1:lenstr(tabid)) >*/
    s_wsfe(&feq_gen_io_d__492);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, lenstr_(xtaddc_1.tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE xsection.for:4549 */
/*<        >*/
    feq_gen_io_d__493.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__493);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, lenstr_(xtaddc_1.tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, savopt, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, outopt, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, betopt, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, feq_gen_extend_string_d_, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, monton, (ftnlen)8);
    e_wsfe();
/* SOURCE xsection.for:4551 */
/*<       if(tab.lt.0)then >*/
    if (*tab < 0) {
/* SOURCE xsection.for:4552 */
/*<       slot=0.03 >*/
	nrdzcm_1.slot = (float).03;
/* SOURCE xsection.for:4553 */
/*<       tab=-tab >*/
	*tab = -(*tab);
/* SOURCE xsection.for:4554 */
/*<       nocm=1 >*/
	nrdzcm_1.nocm = 1;
/* SOURCE xsection.for:4555 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4556 */
/*<       nocm=0 >*/
	nrdzcm_1.nocm = 0;
/* SOURCE xsection.for:4557 */
/*<       slot=0.0 >*/
	nrdzcm_1.slot = (float)0.;
/* SOURCE xsection.for:4558 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4560 */
/*<       if(zone/='NONE')then >*/
    if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0) {
/* SOURCE xsection.for:4561 */
/*<       write(stdout,65)zone,hgrid,vdatum,unitsys,basis >*/
	feq_gen_io_d__494.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__494);
	do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	e_wsfe();
/* SOURCE xsection.for:4562 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4563 */
/*<       if(tab.ge.0)calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    if (*tab >= 0) {
	tabchk_(stdout, &feq_gen_c_d_10002, tab, &tabdir[1], eflag);
    }
/* SOURCE xsection.for:4567 */
/*<       left=scale*left >*/
    *left = static_cast<double>(scale) * *left;
/* SOURCE xsection.for:4568 */
/*<       right=scale*right >*/
    *right = static_cast<double>(scale) * *right;
/* SOURCE xsection.for:4569 */
/*<       if(gisid.ne.' ')then >*/
    if (s_cmp(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE xsection.for:4570 */
/*<       write(stdout,72)gisid,easting,northing >*/
	feq_gen_io_d__495.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__495);
	do_fio(&feq_gen_c_d_1, xtaddc_1.gisid, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.easting, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&xtadd_1.northing, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE xsection.for:4571 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4572 */
/*<       if(left.ge.right)then >*/
    if (*left >= *right) {
/* SOURCE xsection.for:4573 */
/*<       write(stdout,54)stat >*/
	feq_gen_io_d__496.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__496);
	do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4574 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4575 */
/*<       write(stdout,53)stat,left,right >*/
	feq_gen_io_d__497.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__497);
	do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&(*left), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&(*right), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:4576 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4577 */
/*<       write(stdout,52)navm,scale,shift,vscale,hshift >*/
    feq_gen_io_d__498.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__498);
    do_fio(&feq_gen_c_d_1, (char *)&(*navm), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&scale, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&vscale, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&hshift, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:4578 */
/*<       write(stdout,55)'NSUB',nsub,(n(j),j=1,nsub) >*/
    feq_gen_io_d__499.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__499);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("NSUB"), (ftnlen)4);
    do_fio(&feq_gen_c_d_1, (char *)&(*nsub), (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = *nsub;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&n[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* SOURCE xsection.for:4580 */
/*<       do131j=1,nsub >*/
    feq_gen_i_d_1 = *nsub;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:4581 */
/*<       if(n(j).le.0.0)then >*/
	if (n[j] <= (float)0.) {
/* SOURCE xsection.for:4582 */
/*<       write(stdout,70)j >*/
	    feq_gen_io_d__501.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__501);
	    do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE xsection.for:4583 */
/*<       n(j)=1.0 >*/
	    n[j] = (float)1.;
/* SOURCE xsection.for:4584 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:4585 */
/*<       endif >*/
	}
/* SOURCE xsection.for:4586 */
/*<   131 continue >*/
/* L131: */
    }
/* SOURCE xsection.for:4587 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4590 */
/*<       read(line,4,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:4591 */
/*<       write(stdout,56)head >*/
    feq_gen_io_d__504.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__504);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/*     GET THE CO-ORDINATES ON THE BOUNDARY OF THE CROSS SECTION */
/* SOURCE xsection.for:4595 */
/*<       xold=-1.e30 >*/
    xold = (float)-1e30;
/* SOURCE xsection.for:4596 */
/*<       npnt=0 >*/
    *npnt = 0;
/* SOURCE xsection.for:4597 */
/*<       zmax=-1.e30 >*/
    *zmax = (float)-1e30;
/* SOURCE xsection.for:4598 */
/*<   135 continue >*/
L135:
/* SOURCE xsection.for:4599 */
/*<       npnt=npnt+1 >*/
    ++(*npnt);
/* SOURCE xsection.for:4600 */
/*<       if(npnt.le.maxpnt)goto137 >*/
    if (*npnt <= *maxpnt) {
	goto L137;
    }
/* SOURCE xsection.for:4601 */
/*<       write(stdout,62)maxpnt >*/
    feq_gen_io_d__506.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__506);
    do_fio(&feq_gen_c_d_1, (char *)&(*maxpnt), (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE xsection.for:4602 */
/*<       eflag=eflag+1 >*/
    ++(*eflag);
/* SOURCE xsection.for:4603 */
/*<       npnt=maxpnt >*/
    *npnt = *maxpnt;
/* SOURCE xsection.for:4604 */
/*<   137 continue >*/
L137:
/* SOURCE xsection.for:4606 */
/*<       if(mode.eq.2)then >*/
    if (*mode == 2) {
/* SOURCE xsection.for:4607 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/*         EMULATE LIST PROCESSING OF ITEMS IN LINE. */
/* SOURCE xsection.for:4612 */
/*<       is=1 >*/
	is = 1;
/* SOURCE xsection.for:4613 */
/*<       callgetnxt(line,is,ie,chr10) >*/
	getnxt_(line, &is, &ie, chr10, (ftnlen)80, (ftnlen)10);
/* SOURCE xsection.for:4616 */
/*<       read(chr10,'(F10.0)',err=991)x(npnt) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = chr10;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE xsection.for:4618 */
/*<       is=ie >*/
	is = ie;
/* SOURCE xsection.for:4619 */
/*<       callgetnxt(line,is,ie,chr10) >*/
	getnxt_(line, &is, &ie, chr10, (ftnlen)80, (ftnlen)10);
/* SOURCE xsection.for:4622 */
/*<       read(chr10,'(F10.0)',err=991)z(npnt) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = chr10;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[*npnt], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE xsection.for:4624 */
/*<       is=ie >*/
	is = ie;
/* SOURCE xsection.for:4625 */
/*<       callgetnxt(line,is,ie,chr10) >*/
	getnxt_(line, &is, &ie, chr10, (ftnlen)80, (ftnlen)10);
/* SOURCE xsection.for:4628 */
/*<       read(chr10,'(I10)',err=991)sb(npnt) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = chr10;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I10)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&sb[*npnt], (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/*          READ(LINE,*,ERR=991) X(NPNT),Z(NPNT),SB(NPNT) */
/*          WRITE(STDOUT,*) X(NPNT), Z(NPNT), SB(NPNT) */
/* SOURCE xsection.for:4633 */
/*<       elseif(mode.eq.1)then >*/
    } else if (*mode == 1) {
/* SOURCE xsection.for:4634 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4637 */
/*<       read(line,5,err=991)x(npnt),z(npnt),sb(npnt) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_5;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[*npnt], (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&sb[*npnt], (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE xsection.for:4638 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4639 */
/*<       x(npnt)=x(npnt)*scale+hshift >*/
    x[*npnt] = static_cast<double>(static_cast<double>(x[*npnt]) * scale) + hshift;
/* SOURCE xsection.for:4640 */
/*<       z(npnt)=z(npnt)*vscale+shift >*/
    feq_gen_z_d_[*npnt] = static_cast<double>(static_cast<double>(feq_gen_z_d_[*npnt]) * vscale) + shift;
/*       FIND MAXIMUM ELEVATION IN CROSS SECTION FOR LATER CHECKING */
/* SOURCE xsection.for:4643 */
/*<       zmax=max(z(npnt),zmax) >*/
/* Computing MAX */
    feq_gen_r_d_1 = feq_gen_z_d_[*npnt];
    *zmax = dmax(feq_gen_r_d_1,*zmax);
/*       CHECK FOR MONOTONICITY OF TOP WIDTH.  THIS REQUIRES THAT */
/*       THE OFFSET NEVER DECREASE. */
/* SOURCE xsection.for:4648 */
/*<       if(monton.eq.'MONOTONE')then >*/
    if (s_cmp(monton, const_cast<char*>("MONOTONE"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE xsection.for:4649 */
/*<       if(x(npnt).lt.xold)then >*/
	if (x[*npnt] < xold) {
/* SOURCE xsection.for:4650 */
/*<        >*/
	    feq_gen_io_d__510.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__510);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:508* SECTION VIOLATES MONOTONICITY A\
T OFFSET="), (ftnlen)51);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
	    e_wsle();
/* SOURCE xsection.for:4652 */
/*<       eflag=eflag+1 >*/
	    ++(*eflag);
/* SOURCE xsection.for:4653 */
/*<       endif >*/
	}
/* SOURCE xsection.for:4654 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4656 */
/*<       xold=x(npnt) >*/
    xold = x[*npnt];
/* SOURCE xsection.for:4658 */
/*<       if(npnt.gt.1)goto160 >*/
    if (*npnt > 1) {
	goto L160;
    }
/* SOURCE xsection.for:4659 */
/*<       if(sb(1).gt.0)goto150 >*/
    if (sb[1] > 0) {
	goto L150;
    }
/* SOURCE xsection.for:4660 */
/*<       write(stdout,60) >*/
    feq_gen_io_d__511.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__511);
    e_wsfe();
/* SOURCE xsection.for:4661 */
/*<       sb(1)=1 >*/
    sb[1] = 1;
/* SOURCE xsection.for:4662 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE xsection.for:4663 */
/*<   150 continue >*/
L150:
/* SOURCE xsection.for:4664 */
/*<   160 continue >*/
L160:
/*       PROPAGATE SUBSECTION ASSIGNMENTS INTO ZERO VALUES */
/* SOURCE xsection.for:4667 */
/*<       if(sb(npnt).eq.0)sb(npnt)=sb(npnt-1) >*/
    if (sb[*npnt] == 0) {
	sb[*npnt] = sb[*npnt - 1];
    }
/* SOURCE xsection.for:4669 */
/*<       write(stdout,57)x(npnt),z(npnt),sb(npnt) >*/
    feq_gen_io_d__512.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__512);
    do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[*npnt], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&sb[*npnt], (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE xsection.for:4671 */
/*<       if(sb(npnt).le.nsub)goto140 >*/
    if (sb[*npnt] <= *nsub) {
	goto L140;
    }
/* SOURCE xsection.for:4672 */
/*<       write(stdout,59)x(npnt) >*/
    feq_gen_io_d__513.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__513);
    do_fio(&feq_gen_c_d_1, (char *)&x[*npnt], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:4673 */
/*<       sb(npnt)=nsub >*/
    sb[*npnt] = *nsub;
/* SOURCE xsection.for:4674 */
/*<       eflag=eflag+1 >*/
    ++(*eflag);
/* SOURCE xsection.for:4675 */
/*<   140 continue >*/
L140:
/* SOURCE xsection.for:4679 */
/*<       if(sb(npnt).gt.0)goto135 >*/
    if (sb[*npnt] > 0) {
	goto L135;
    }
/*     NOTE THAT A NEGATIVE VALUE OF SB(NPNT) TERMINATES INPUT */
/* SOURCE xsection.for:4683 */
/*<       if(npnt.gt.1)goto170 >*/
    if (*npnt > 1) {
	goto L170;
    }
/* SOURCE xsection.for:4684 */
/*<       write(stdout,61) >*/
    feq_gen_io_d__514.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__514);
    e_wsfe();
/* SOURCE xsection.for:4685 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE xsection.for:4686 */
/*<   170 continue >*/
L170:
/*     CHECK THE CROSS SECTION FOR NONSENSE BEHAVIOR AT THE END */
/* SOURCE xsection.for:4690 */
/*<       if(z(1).le.z(2).and.x(2).gt.x(1))then >*/
    if (feq_gen_z_d_[1] <= feq_gen_z_d_[2] && x[2] > x[1]) {
/*       THE LEFT MOST LINE SEGMENT HAS UPWARD SLOPE, THEREFORE HIGH */
/*       POINT IS NOT AT THE LEFT LIMIT. */
/* SOURCE xsection.for:4694 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" *WRN:502* UNEXPECTED SLOPE"), (ftnlen)27);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" AT LEFT END."), (ftnlen)13);
	e_wsfe();
/* SOURCE xsection.for:4696 */
/*<       write(stdout,*)'  SLOPE EXPECTED TO BE < 0  AT LEFT BOUNDARY' >*/
	feq_gen_io_d__515.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__515);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  SLOPE EXPECTED TO BE < 0  AT LEFT BOUNDARY"), (
		ftnlen)44);
	e_wsle();
/* SOURCE xsection.for:4697 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4698 */
/*<       if(z(npnt).le.z(npnt-1).and.x(npnt).gt.x(npnt-1))then >*/
    if (feq_gen_z_d_[*npnt] <= feq_gen_z_d_[*npnt - 1] && x[*npnt] > x[*npnt - 1]) {
/*       THE RIGHT MOST LINE SEGMENT HAS DOWNWARD SLOPE */
/* SOURCE xsection.for:4701 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" *WRN:503* UNEXPECTED SLOPE"), (ftnlen)27);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" AT RIGHT END."), (ftnlen)14);
	e_wsfe();
/* SOURCE xsection.for:4703 */
/*<       write(stdout,*)'  SLOPE EXPECTED TO BE > 0 AT RIGHT BOUNDARY' >*/
	feq_gen_io_d__516.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__516);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  SLOPE EXPECTED TO BE > 0 AT RIGHT BOUNDARY"), (
		ftnlen)44);
	e_wsle();
/* SOURCE xsection.for:4704 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4706 */
/*<       if(extend.eq.1)then >*/
    if (nrdzcm_1.extend == 1) {
/*       CHECK FOR ONE END BEING HIGHER THAN THE OTHER */
/* SOURCE xsection.for:4709 */
/*<       if(abs(zmax-z(1)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[1], dabs(feq_gen_r_d_1)) > epscom_1.epsdif) {
/* SOURCE xsection.for:4710 */
/*<       write(stdout,67)zmax-z(1) >*/
	    feq_gen_io_d__517.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__517);
	    feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[1];
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE xsection.for:4711 */
/*<       endif >*/
	}
/* SOURCE xsection.for:4712 */
/*<       if(abs(zmax-z(npnt)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[*npnt], dabs(feq_gen_r_d_1)) > epscom_1.epsdif) {
/* SOURCE xsection.for:4713 */
/*<       write(stdout,68)zmax-z(npnt) >*/
	    feq_gen_io_d__518.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__518);
	    feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[*npnt];
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE xsection.for:4714 */
/*<       endif >*/
	}
/* SOURCE xsection.for:4715 */
/*<       else >*/
    } else {
/*       CHECK FOR AN INTERMEDIATE POINT BEING HIGHER THAN EITHER */
/*       END */
/* SOURCE xsection.for:4718 */
/*<       if(abs(zmax-z(1)).gt.epsdif.and.abs(zmax-z(npnt)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*zmax) - feq_gen_z_d_[1], dabs(feq_gen_r_d_1)) > epscom_1.epsdif && (feq_gen_r_d_2 = static_cast<double>(*
		zmax) - feq_gen_z_d_[*npnt], dabs(feq_gen_r_d_2)) > epscom_1.epsdif) {
/* SOURCE xsection.for:4720 */
/*<       write(stdout,69) >*/
	    feq_gen_io_d__519.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__519);
	    e_wsfe();
/* SOURCE xsection.for:4721 */
/*<       endif >*/
	}
/* SOURCE xsection.for:4723 */
/*<       zmax=min(z(1),z(npnt)) >*/
/* Computing MIN */
	feq_gen_r_d_1 = feq_gen_z_d_[1], feq_gen_r_d_2 = feq_gen_z_d_[*npnt];
	*zmax = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE xsection.for:4724 */
/*<       endif >*/
    }
/*     CHECK TO SEE IF SUBSECTION NUMBERS HAVE BEEN REPEATED IN */
/*     SEPERATE RUNS. */
/* SOURCE xsection.for:4729 */
/*<       ntemp=nsub >*/
    ntemp = *nsub;
/* SOURCE xsection.for:4730 */
/*<       callreasub(stdout,npnt,nsub,n,sb,eflag) >*/
    reasub_(stdout, npnt, nsub, &n[1], &sb[1], eflag);
/* SOURCE xsection.for:4734 */
/*<       if(nsub.ne.ntemp)then >*/
    if (*nsub != ntemp) {
/*       OUTPUT THE NEW ASSIGNMENTS */
/* SOURCE xsection.for:4736 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__521.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__521);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE xsection.for:4737 */
/*<       write(stdout,*)' *WRN:548* Unwise use of subsection numbers' >*/
	feq_gen_io_d__522.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__522);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *WRN:548* Unwise use of subsection numbers"), (
		ftnlen)43);
	e_wsle();
/* SOURCE xsection.for:4738 */
/*<        >*/
	feq_gen_io_d__523.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__523);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("     Subsections have been added to avoid"), (
		ftnlen)41);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" repeated usages."), (ftnlen)17);
	e_wsle();
/* SOURCE xsection.for:4740 */
/*<        >*/
	feq_gen_io_d__524.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__524);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("     Old NSUB="), (ftnlen)14);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ntemp, (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" New NSUB="), (ftnlen)10);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*nsub), (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Please check for validity"), (ftnlen)26);
	e_wsle();
/* SOURCE xsection.for:4742 */
/*<       write(stdout,55)'NSUB',nsub,(n(j),j=1,nsub) >*/
	feq_gen_io_d__525.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__525);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("NSUB"), (ftnlen)4);
	do_fio(&feq_gen_c_d_1, (char *)&(*nsub), (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = *nsub;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&n[j], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE xsection.for:4743 */
/*<       write(stdout,56)head >*/
	feq_gen_io_d__526.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__526);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_wsfe();
/* SOURCE xsection.for:4744 */
/*<       do200j=1,npnt >*/
	feq_gen_i_d_1 = *npnt;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:4745 */
/*<       write(stdout,57)x(j),z(j),sb(j) >*/
	    feq_gen_io_d__527.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__527);
	    do_fio(&feq_gen_c_d_1, (char *)&x[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&sb[j], (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE xsection.for:4746 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE xsection.for:4747 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4750 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:4751 */
/*<   991 continue >*/
L991:
/* SOURCE xsection.for:4752 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__528.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__528);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE xsection.for:4753 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__529.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__529);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE xsection.for:4754 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:4755 */
/*<       end >*/
    return 0;
} /* infeqx_ */




/* SOURCE xsection.for:4759 */
/*<       subroutinechanel(stdin,stdout,stdtab,nfac,tabdir,ftp,eflag,mode) >*/
/* Subroutine */ int chanel_(integer *stdin, integer *stdout, integer *stdtab,
	 real *nfac, integer *feq_storage_tabdir, integer *ftp, integer *eflag, integer *
	mode)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:679* Invalid cross section command\
:\002,a8,\002 in \002,\002the CHANNEL command.\002)";
    static char fmt_52[] = "(1x,a)";
    static char fmt_54[] = "(/,\002 *ERR:680* CHANNEL command ended improper\
ly.  FINISH\002,\002 encountered before ENDCHAN.\002)";
    static char fmt_56[] = "(/,\002 Errors prevent CHANNEL command completio\
n.\002)";
    static char fmt_58[] = "(/,\002 End of file found.  Missing ENDCHAN or F\
INISH.\002)";

    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen), 
	    s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, ftnlen, ftnlen)
	    ;
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_set_slot_d_(integer *, integer *, integer *), 
	    feq_gen_set_slote_d_(integer *, integer *, integer *), feq_gen_clear_slot_d_(
	    integer *);
    integer eflg;
    char line[80];
    extern /* Subroutine */ int feqx_(integer *, integer *, integer *, real *,
	     integer *, integer *, integer *, integer *), fqxe_(integer *, 
	    integer *, integer *, real *, integer *, integer *, integer *), 
	    stbin_(integer *, integer *, real *, real *, integer *, real *, 
	    integer *, integer *, integer *, real *, integer *, integer *), 
	    inline_(integer *, integer *, char *, ftnlen);
    char nxtcmd[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__530 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__532 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__534 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__535 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__536 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__538 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__539 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Compute cross sections including the sinuosity elements. */
/* SOURCE xsection.for:4767 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE xsection.for:4770 */
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
/* SOURCE xsection.for:4773 */
/*<       integereflag,ftp,mode,stdin,stdout,stdtab >*/
/* SOURCE xsection.for:4774 */
/*<       integertabdir(pmxtab) >*/
/* SOURCE xsection.for:4775 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     TABDIR - Table directory to remember table numbers */
/*     FTP    - next open location in the function table storage */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     MODE   - Mode of processing cross section boundary specification: */
/*               MODE=1: fixed format.  MODE=2: list format. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:4789 */
/*     COMMON FOR THE UPSTREAM CROSS SECTION */

/* SOURCE xscomu.cmn:3 */
/*<       integernpntu,nsubu,navmu,tabu,ndepu,mxpntu,usgsu,snflgu >*/
/* SOURCE xscomu.cmn:4 */
/*<       integersbu(pmxpnt),nvaru(pmxsub),nnyu(pmxsub) >*/
/* SOURCE xscomu.cmn:5 */
/*<       realstatu,zminu,zmaxu >*/
/* SOURCE xscomu.cmn:6 */
/*<        >*/

/* SOURCE xscomu.cmn:10 */
/*<        >*/
/*     SNFLGU- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points. */
/*     SNU- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSNU- LINE SEGMENT N VALUE */
/*     NVARU- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: 0-N IS CONSTANT, */
/*           1-N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           2-N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*           IF N VARIES WITH DEPTH, THE N VALUE APPLIES TO THE WHOLE */
/*           SUBSECTION.  NO VARIATION OF ROUGHNESS PERMITTED ON LINE SEGMENTS */
/*           IN THE SUBSECTION. */
/*     NATYU-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATNU- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYU- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS.  VALUE IS ZERO IF NVARU FOR THE */
/*          SUBSECTION IS ZERO.  THE N DEPTH PAIR AT ZERO DEPTH IS STORED */
/*          AND COUNTED WITH NVARU > 0 FOR THE SUBSECTION. */
/*     YSMXU- MAXIMUM DEPTH IN EACH SUBSECTION. */
/* INCLUDE xsection.for:4790 */
/*     COMMON FOR THE SINUOUSITY TABLE IN THE CHANNEL COMMAND. */
/*     USED TO REMEMBER THE VALUES THAT ARE FINALLY NEEDED TO */
/*     DEFINE THE SINUOUSITY VALUES ON THE CROSS SECTION BOUNDARY */
/* SOURCE sincom.cmn:5 */
/*<       integernumoff(pmxsec),numsec,jaxis,dir,vartyp >*/
/* SOURCE sincom.cmn:8 */
/*<        >*/
/* SOURCE sincom.cmn:13 */
/*<       common/sincom/dir,jaxis,numsec,eps,vartyp,numoff,stl,offset,sinu >*/
/* SOURCE sincom.cmn:18 */
/*<       save/sincom/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:4793 */
/*<       integereflg >*/
/* SOURCE xsection.for:4794 */
/*<       characterline*80,nxtcmd*8 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:4797 */
/*<       externalfeqx,fqxe,inline,stbin >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:4800 */
/*<    50  >*/
/* SOURCE xsection.for:4802 */
/*<    52 format(1x,a) >*/
/* SOURCE xsection.for:4803 */
/*<    54  >*/
/* SOURCE xsection.for:4805 */
/*<    56 format(/,' Errors prevent CHANNEL command completion.') >*/
/* SOURCE xsection.for:4806 */
/*<    58 format(/,' End of file found.  Missing ENDCHAN or FINISH.') >*/
/* *********************************************************************** */
/*     DEFINE THE SINUOSITY VALUES FROM THE USER SPECIFICATION. */
/* SOURCE xsection.for:4810 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
    stbin_(stdin, stdout, sincom_1.stl, sincom_1.offset, sincom_1.numoff, 
	    sincom_1.sinu, &sincom_1.vartyp, &sincom_1.numsec, &sincom_1.dir, 
	    &sincom_1.eps, &sincom_1.jaxis, eflag);
/* SOURCE xsection.for:4815 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/*       FLUSH THE REST OF THE CHANNEL INPUT TO AVOID FURTHER ERRORS. */
/* SOURCE xsection.for:4817 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__530.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__530);
	e_wsfe();
/* SOURCE xsection.for:4818 */
/*<   100 continue >*/
L100:
/* SOURCE xsection.for:4819 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4822 */
/*<       write(stdout,52)line >*/
	feq_gen_io_d__532.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__532);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	e_wsfe();
/* SOURCE xsection.for:4823 */
/*<       read(line,'(A8)')nxtcmd >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(A8)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, nxtcmd, (ftnlen)8);
	e_rsfi();
/* SOURCE xsection.for:4824 */
/*<       if(nxtcmd.eq.'FINISH')then >*/
	if (s_cmp(nxtcmd, const_cast<char*>("FINISH"), (ftnlen)8, (ftnlen)6) == 0) {
/* SOURCE xsection.for:4825 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__534.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__534);
	    e_wsfe();
/* SOURCE xsection.for:4826 */
/*<       return >*/
	    return 0;
/* SOURCE xsection.for:4827 */
/*<       elseif(nxtcmd.eq.'ENDFILE')then >*/
	} else if (s_cmp(nxtcmd, const_cast<char*>("ENDFILE"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE xsection.for:4828 */
/*<       write(stdout,58) >*/
	    feq_gen_io_d__535.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__535);
	    e_wsfe();
/* SOURCE xsection.for:4829 */
/*<       return >*/
	    return 0;
/* SOURCE xsection.for:4830 */
/*<       endif >*/
	}
/* SOURCE xsection.for:4831 */
/*<       if(nxtcmd.ne.'ENDCHAN')goto100 >*/
	if (s_cmp(nxtcmd, const_cast<char*>("ENDCHAN"), (ftnlen)8, (ftnlen)7) != 0) {
	    goto L100;
	}
/* SOURCE xsection.for:4832 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:4833 */
/*<       endif >*/
    }
/*     READ THE CROSS SECTION INPUT AND PROCESS.  ANY ONE OF THREE */
/*     COMMANDS IS POSSIBLE: FEQX, FEQXLST, OR FEQXEXT. */
/* SOURCE xsection.for:4838 */
/*<   200 continue >*/
L200:
/* SOURCE xsection.for:4840 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:4843 */
/*<       write(stdout,52)line >*/
    feq_gen_io_d__536.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__536);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE xsection.for:4844 */
/*<       read(line,'(A8)')nxtcmd >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A8)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, nxtcmd, (ftnlen)8);
    e_rsfi();
/* SOURCE xsection.for:4846 */
/*<       if(nxtcmd.eq.'FEQX    ')then >*/
    if (s_cmp(nxtcmd, const_cast<char*>("FEQX    "), (ftnlen)8, (ftnlen)8) == 0) {
/*         PROCESS FEQX FORMAT CROSS SECTION WITH SINUOSITY. */
/* SOURCE xsection.for:4849 */
/*<       mode=2 >*/
	*mode = 2;
/* SOURCE xsection.for:4850 */
/*<       snflgu=vartyp >*/
	xscomu_1.snflgu = sincom_1.vartyp;
/* SOURCE xsection.for:4851 */
/*<       callfeqx(stdin,stdout,stdtab,nfac,mode,tabdir,ftp,eflg) >*/
	feqx_(stdin, stdout, stdtab, nfac, mode, &tabdir[1], ftp, &eflg);
/* SOURCE xsection.for:4856 */
/*<       eflag=eflag+eflg >*/
	*eflag += eflg;
/* SOURCE xsection.for:4858 */
/*<       elseif(nxtcmd.eq.'FEQXLST ')then >*/
    } else if (s_cmp(nxtcmd, const_cast<char*>("FEQXLST "), (ftnlen)8, (ftnlen)8) == 0) {
/*         PROCESS FEQX FORMAT IN LIST FORM */
/* SOURCE xsection.for:4861 */
/*<       mode=1 >*/
	*mode = 1;
/* SOURCE xsection.for:4862 */
/*<       snflgu=vartyp >*/
	xscomu_1.snflgu = sincom_1.vartyp;
/* SOURCE xsection.for:4863 */
/*<       callfeqx(stdin,stdout,stdtab,nfac,mode,tabdir,ftp,eflg) >*/
	feqx_(stdin, stdout, stdtab, nfac, mode, &tabdir[1], ftp, &eflg);
/* SOURCE xsection.for:4867 */
/*<       eflag=eflag+eflg >*/
	*eflag += eflg;
/* SOURCE xsection.for:4868 */
/*<       elseif(nxtcmd.eq.'FEQXEXT')then >*/
    } else if (s_cmp(nxtcmd, const_cast<char*>("FEQXEXT"), (ftnlen)8, (ftnlen)7) == 0) {
/*         PROCESS THE EXTENDED FEQX FORMAT */
/* SOURCE xsection.for:4871 */
/*<       snflgu=vartyp >*/
	xscomu_1.snflgu = sincom_1.vartyp;
/* SOURCE xsection.for:4872 */
/*<       callfqxe(stdin,stdout,stdtab,nfac,tabdir,ftp,eflg) >*/
	fqxe_(stdin, stdout, stdtab, nfac, &tabdir[1], ftp, &eflg);
/* SOURCE xsection.for:4876 */
/*<       eflag=eflag+eflg >*/
	*eflag += eflg;
/* SOURCE xsection.for:4878 */
/*<       elseif(nxtcmd.eq.'ENDCHAN')then >*/
    } else if (s_cmp(nxtcmd, const_cast<char*>("ENDCHAN"), (ftnlen)8, (ftnlen)7) == 0) {
/*         END THE CHANNEL COMMAND */
/* SOURCE xsection.for:4880 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:4881 */
/*<       elseif(nxtcmd.eq.'        ')then >*/
    } else if (s_cmp(nxtcmd, const_cast<char*>("        "), (ftnlen)8, (ftnlen)8) == 0) {
/*         OK. SKIP BLANK LINES */
/* SOURCE xsection.for:4884 */
/*<       elseif(nxtcmd.eq.'FINISH  ')then >*/
    } else if (s_cmp(nxtcmd, const_cast<char*>("FINISH  "), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE xsection.for:4885 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__538.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__538);
	e_wsfe();
/* SOURCE xsection.for:4886 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:4887 */
/*<       elseif(nxtcmd.eq.'SETSLOT')then >*/
    } else if (s_cmp(nxtcmd, const_cast<char*>("SETSLOT"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE xsection.for:4888 */
/*<       callset_slot(stdin,stdout,stdtab) >*/
	feq_gen_set_slot_d_(stdin, stdout, stdtab);
/* SOURCE xsection.for:4889 */
/*<       elseif(nxtcmd.eq.'SETSLOTE')then >*/
    } else if (s_cmp(nxtcmd, const_cast<char*>("SETSLOTE"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE xsection.for:4890 */
/*<       callset_slote(stdin,stdout,stdtab) >*/
	feq_gen_set_slote_d_(stdin, stdout, stdtab);
/* SOURCE xsection.for:4891 */
/*<       elseif(nxtcmd.eq.'CLRSLOT')then >*/
    } else if (s_cmp(nxtcmd, const_cast<char*>("CLRSLOT"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE xsection.for:4892 */
/*<       callclear_slot(stdtab) >*/
	feq_gen_clear_slot_d_(stdtab);
/* SOURCE xsection.for:4893 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4894 */
/*<       write(stdout,50)nxtcmd >*/
	feq_gen_io_d__539.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__539);
	do_fio(&feq_gen_c_d_1, nxtcmd, (ftnlen)8);
	e_wsfe();
/* SOURCE xsection.for:4895 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE xsection.for:4896 */
/*<       endif >*/
    }
/* SOURCE xsection.for:4898 */
/*<       goto200 >*/
    goto L200;
/* SOURCE xsection.for:4899 */
/*<       end >*/
} /* chanel_ */




/* SOURCE xsection.for:4903 */
/*<       subroutinefeqx(stdin,stdout,stdtab,nfac,mode,tabdir,ftp,eflag) >*/
/* Subroutine */ int feqx_(integer *stdin, integer *stdout, integer *stdtab, 
	real *nfac, integer *mode, integer *feq_storage_tabdir, integer *ftp, integer *
	eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* NAVM > 0 incompatible with cur\
vilinear\002,\002 element computation.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    char betaflag[1*999];
    integer feq_gen_i_d_, j;
    char alphaflag[1*999];
    integer loc, npi;
    real area;
    integer mesg;
    real left, xarg[11];
    extern /* Subroutine */ int tran_();
    char zone[8];
    real zmax;
    char hgrid[8], basis[8];
    real right;
    extern /* Subroutine */ int inspt_(integer *, integer *, real *, integer *
	    , integer *, real *, real *, integer *, real *, integer *);
    char maflag[1*999], khflag[1*999], mqflag[1*999];
    extern integer locsta_(integer *, real *, integer *, integer *, integer *,
	     real *, real *);
    char betopt[8], outopt[8], savopt[8], vdatum[8];
    extern /* Subroutine */ int cxstab_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, char *, integer *, integer *, real *
	    , real *, integer *, integer *, real *, real *, real *, real *, 
	    integer *, integer *, real *, real *, real *, integer *, real *, 
	    ftnlen), fndway_(integer *, integer *, integer *, real *, real *, 
	    real *, real *), infeqx_(integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, real *, integer *, integer *, 
	    integer *, real *, real *, integer *, real *, real *, real *, 
	    char *, char *, char *, real *, char *, char *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), lkupsn_(integer *, integer *, real *, integer *, real *, 
	    real *, integer *, real *), tabout_(integer *, integer *, integer 
	    *, real *, real *, integer *, char *, char *, char *, char *, 
	    char *, char *, char *, char *, char *, char *, char *, char *, 
	    char *, integer *, real *, integer *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen), xsecfit_(integer *, integer *, integer *, real *,
	     char *, char *, char *, char *, char *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__551 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__553 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Process a cross section in FEQ format. */
/* SOURCE xsection.for:4911 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:4914 */
/*<       integereflag,ftp,mode,stdin,stdout,stdtab >*/
/* SOURCE xsection.for:4915 */
/*<       integertabdir(*) >*/
/* SOURCE xsection.for:4916 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     MODE   - Mode of processing cross section boundary specification: */
/*               MODE=1: fixed format.  MODE=2: list format. */
/*     TABDIR - Table directory to remember table numbers */
/*     FTP    - next open location in the function table storage */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:4930 */
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
/* INCLUDE xsection.for:4931 */
/*     COMMON FOR THE UPSTREAM CROSS SECTION */

/* SOURCE xscomu.cmn:3 */
/*<       integernpntu,nsubu,navmu,tabu,ndepu,mxpntu,usgsu,snflgu >*/
/* SOURCE xscomu.cmn:4 */
/*<       integersbu(pmxpnt),nvaru(pmxsub),nnyu(pmxsub) >*/
/* SOURCE xscomu.cmn:5 */
/*<       realstatu,zminu,zmaxu >*/
/* SOURCE xscomu.cmn:6 */
/*<        >*/

/* SOURCE xscomu.cmn:10 */
/*<        >*/
/*     SNFLGU- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points. */
/*     SNU- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSNU- LINE SEGMENT N VALUE */
/*     NVARU- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: 0-N IS CONSTANT, */
/*           1-N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           2-N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*           IF N VARIES WITH DEPTH, THE N VALUE APPLIES TO THE WHOLE */
/*           SUBSECTION.  NO VARIATION OF ROUGHNESS PERMITTED ON LINE SEGMENTS */
/*           IN THE SUBSECTION. */
/*     NATYU-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATNU- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYU- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS.  VALUE IS ZERO IF NVARU FOR THE */
/*          SUBSECTION IS ZERO.  THE N DEPTH PAIR AT ZERO DEPTH IS STORED */
/*          AND COUNTED WITH NVARU > 0 FOR THE SUBSECTION. */
/*     YSMXU- MAXIMUM DEPTH IN EACH SUBSECTION. */
/* INCLUDE xsection.for:4932 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/* INCLUDE xsection.for:4933 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE xsection.for:4934 */
/*     COMMON FOR THE SINUOUSITY TABLE IN THE CHANNEL COMMAND. */
/*     USED TO REMEMBER THE VALUES THAT ARE FINALLY NEEDED TO */
/*     DEFINE THE SINUOUSITY VALUES ON THE CROSS SECTION BOUNDARY */
/* SOURCE sincom.cmn:5 */
/*<       integernumoff(pmxsec),numsec,jaxis,dir,vartyp >*/
/* SOURCE sincom.cmn:8 */
/*<        >*/
/* SOURCE sincom.cmn:13 */
/*<       common/sincom/dir,jaxis,numsec,eps,vartyp,numoff,stl,offset,sinu >*/
/* SOURCE sincom.cmn:18 */
/*<       save/sincom/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:4937 */
/*<       integeri,j,loc,mesg,npi >*/
/* SOURCE xsection.for:4938 */
/*<       realleft,right,xarg(pmxnfl),zmax,area >*/
/* SOURCE xsection.for:4939 */
/*<        >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE xsection.for:4946 */
/*<       integerlocsta >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:4949 */
/*<       externalcxstab,fndway,infeqx,inspt,lkupsn,locsta,tabout,tran >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:4953 */
/*<    50  >*/
/* *********************************************************************** */
/*     ENABLE WARNINGS ABOUT SUBSECTION CONVEYANCE VARIATION */
/* SOURCE xsection.for:4957 */
/*<       nocm=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L50: */
    nrdzcm_1.nocm = 0;
/* SOURCE xsection.for:4958 */
/*<       slot=1.e30 >*/
    nrdzcm_1.slot = (float)1e30;
/* SOURCE xsection.for:4959 */
/*<       eflag=0 >*/
    *eflag = 0;
/* SOURCE xsection.for:4960 */
/*<       if(npntu.eq.0)goto100 >*/
    if (xscomu_1.npntu == 0) {
	goto L100;
    }
/* SOURCE xsection.for:4961 */
/*<       calltran >*/
    tran_();
/* SOURCE xsection.for:4962 */
/*<   100 continue >*/
L100:
/*     INPUT NEW CROSS SECTION */
/* SOURCE xsection.for:4966 */
/*<       if(mode.ne.3)then >*/
    if (*mode != 3) {
/* SOURCE xsection.for:4967 */
/*<        >*/
	infeqx_(stdin, stdout, &xscomu_1.mxpntu, mode, &tabdir[1], eflag, &
		xscomu_1.tabu, &xscomu_1.statu, &xscomu_1.npntu, &
		xscomu_1.nsubu, &xscomu_1.navmu, xscomu_1.xu, xscomu_1.zu, 
		xscomu_1.sbu, xscomu_1.nu, &left, &right, savopt, outopt, 
		betopt, &zmax, zone, hgrid, vdatum, unitsys, basis, (ftnlen)8,
		 (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		ftnlen)8, (ftnlen)8);
/* SOURCE xsection.for:4973 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:4974 */
/*<       write(stdout,*)' *ERR:558* DIGITIZED INPUT NOT SUPPORTED' >*/
	feq_gen_io_d__551.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__551);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:558* DIGITIZED INPUT NOT SUPPORTED"), (
		ftnlen)40);
	e_wsle();
/* SOURCE xsection.for:4975 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:4977 */
/*<       endif >*/
    }
/*     CLEAR AND SET ITEMS USED IN THE COMPUTATION BUT NOT DEFINED BY */
/*     FEQX INPUT */
/* SOURCE xsection.for:4982 */
/*<       do95i=1,nsubu >*/
    feq_gen_i_d_1 = xscomu_1.nsubu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:4983 */
/*<       nvaru(i)=0 >*/
	xscomu_1.nvaru[feq_gen_i_d_ - 1] = 0;
/* SOURCE xsection.for:4984 */
/*<       nnyu(i)=0 >*/
	xscomu_1.nnyu[feq_gen_i_d_ - 1] = 0;
/* SOURCE xsection.for:4985 */
/*<    95 continue >*/
/* L95: */
    }
/*     SET DEFAULT FOR  SINUOSITY */
/* SOURCE xsection.for:4988 */
/*<       do96i=1,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:4989 */
/*<       snu(i)=1.0 >*/
	xscomu_1.snu[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE xsection.for:4990 */
/*<    96 continue >*/
/* L96: */
    }
/* SOURCE xsection.for:4992 */
/*<       if(snflgu.gt.0)then >*/
    if (xscomu_1.snflgu > 0) {
/* SOURCE xsection.for:4993 */
/*<       if(navmu.ne.0)then >*/
	if (xscomu_1.navmu != 0) {
/* SOURCE xsection.for:4994 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__553.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__553);
	    e_wsfe();
/* SOURCE xsection.for:4995 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:4996 */
/*<       endif >*/
	}
/*       LOCATE THE CURRENT STATION IN THE SINUOUSITY TABLE. */
/* SOURCE xsection.for:4999 */
/*<       loc=locsta(stdout,statu,dir,jaxis,numsec,stl,eps) >*/
	loc = locsta_(stdout, &xscomu_1.statu, &sincom_1.dir, &sincom_1.jaxis,
		 &sincom_1.numsec, sincom_1.stl, &sincom_1.eps);
/* SOURCE xsection.for:5002 */
/*<       if(loc.le.0)then >*/
	if (loc <= 0) {
/* SOURCE xsection.for:5003 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:5004 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5005 */
/*<       if(eflag.ne.0)return >*/
	if (*eflag != 0) {
	    return 0;
	}
/*       INSERT THE OFFSETS FOR SINUOUSITY DEFINITION INTO THOSE */
/*       ALREADY DEFINING THE BOUNDARY. */
/* SOURCE xsection.for:5009 */
/*<       npi=numoff(loc) >*/
	npi = sincom_1.numoff[loc - 1];
/* SOURCE xsection.for:5011 */
/*<       do98i=1,npi >*/
	feq_gen_i_d_1 = npi;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:5012 */
/*<       xarg(i)=offset(loc,i) >*/
	    xarg[feq_gen_i_d_ - 1] = sincom_1.offset[loc + feq_gen_i_d_ * 400 - 401];
/* SOURCE xsection.for:5013 */
/*<    98 continue >*/
/* L98: */
	}
/* SOURCE xsection.for:5014 */
/*<       callinspt(stdout,npi,xarg,vartyp,npntu,xu,zu,sbu,lsnu,eflag) >*/
	inspt_(stdout, &npi, xarg, &sincom_1.vartyp, &xscomu_1.npntu, 
		xscomu_1.xu, xscomu_1.zu, xscomu_1.sbu, xscomu_1.lsnu, eflag);
/* SOURCE xsection.for:5019 */
/*<       if(eflag.ne.0)return >*/
	if (*eflag != 0) {
	    return 0;
	}
/*       FIND THE SINUOSITY FOR EACH POINT ON THE CROSS SECTION */
/*       BOUNDARY */
/* SOURCE xsection.for:5024 */
/*<       calllkupsn(loc,npntu,xu,vartyp,sinu,offset,npi,snu) >*/
	lkupsn_(&loc, &xscomu_1.npntu, xscomu_1.xu, &sincom_1.vartyp, 
		sincom_1.sinu, sincom_1.offset, &npi, xscomu_1.snu);
/*        WRITE(STDOUT,*) ' ' */
/*        WRITE(STDOUT,*) ' CHECK OF SINUOSITY ASSIGNMENTS' */
/*        WRITE(STDOUT,1234) */
/* 1234  FORMAT(1X,4X,'OFFSET ELEVATION SUBS SINUOSITY') */
/*        DO 1235 I=1,NPNTU */
/*          WRITE(STDOUT,1236) XU(I), ZU(I), SBU(I), SNU(I) */
/* 1236  FORMAT(1X,F10.2,F10.2,I5,F10.6) */
/* 1235    CONTINUE */
/* SOURCE xsection.for:5036 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5038 */
/*<       do97i=1,npntu-1 >*/
    feq_gen_i_d_1 = xscomu_1.npntu - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:5039 */
/*<       lsnu(i)=nu(sbu(i)) >*/
	xscomu_1.lsnu[feq_gen_i_d_ - 1] = xscomu_1.nu[xscomu_1.sbu[feq_gen_i_d_ - 1] - 1];
/*        WRITE(STDOUT,*) 'I=',I,' LSNU=',LSNU(I) */
/* SOURCE xsection.for:5041 */
/*<    97 continue >*/
/* L97: */
    }
/*     COMPUTE ELEMENTS FOR CURRENT CROSS SECTION */
/* SOURCE xsection.for:5045 */
/*<       if(npntu.gt.1)then >*/
    if (xscomu_1.npntu > 1) {
/*       FIND THE MAXIMUM AND MINIMUM ARGUMENT VALUES */
/* SOURCE xsection.for:5047 */
/*<       zminu=9999999. >*/
	xscomu_1.zminu = (float)9999999.;
/* SOURCE xsection.for:5048 */
/*<       zmaxu=-9999999. >*/
	xscomu_1.zmaxu = (float)-9999999.;
/* SOURCE xsection.for:5049 */
/*<       do150j=1,npntu >*/
	feq_gen_i_d_1 = xscomu_1.npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:5050 */
/*<       if(zu(j).gt.zmaxu)zmaxu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] > xscomu_1.zmaxu) {
		xscomu_1.zmaxu = xscomu_1.zu[j - 1];
	    }
/* SOURCE xsection.for:5051 */
/*<       if(zu(j).lt.zminu)zminu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] < xscomu_1.zminu) {
		xscomu_1.zminu = xscomu_1.zu[j - 1];
	    }
/* SOURCE xsection.for:5052 */
/*<   150 continue >*/
/* L150: */
	}
/* SOURCE xsection.for:5054 */
/*<       if(extend.eq.0)zmaxu=zmax >*/
	if (nrdzcm_1.extend == 0) {
	    xscomu_1.zmaxu = zmax;
	}
/*       FIND THE VALUE OF RIGHT AND LEFT IF FLOOD WAY OPTION */
/*       IS ACTIVE */
/* SOURCE xsection.for:5059 */
/*<       if(flood.eq.1)then >*/
	if (fldway_1.flood == 1) {
/* SOURCE xsection.for:5060 */
/*<       callfndway(tabu,stdout,eflag,nfac,left,right,area) >*/
	    fndway_(&xscomu_1.tabu, stdout, eflag, nfac, &left, &right, &area)
		    ;
/* SOURCE xsection.for:5063 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5065 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/* SOURCE xsection.for:5066 */
/*<        >*/
	    cxstab_(stdout, &xscomu_1.nsubu, &xscomu_1.navmu, nfac, &
		    xscomu_1.mxpntu, &left, &right, betopt, &xscomu_1.snflgu, 
		    xscomu_1.nvaru, xscomu_1.natyu, xscomu_1.yatnu, 
		    xscomu_1.nnyu, &xscomu_1.npntu, &xscomu_1.zminu, &
		    xscomu_1.zmaxu, xscomu_1.xu, xscomu_1.zu, xscomu_1.sbu, 
		    eflag, xscomu_1.lsnu, xscomu_1.snu, xscomu_1.nu, &
		    xscomu_1.ndepu, xscomu_1.xstu, (ftnlen)8);
/* SOURCE xsection.for:5073 */
/*<       if(flood.eq.1)then >*/
	    if (fldway_1.flood == 1) {
/*           STORE LEFT AND RIGHT AGAIN TO */
/*           REFLECT CHANGES MADE IN CSXTAB */
/* SOURCE xsection.for:5076 */
/*<       fldlt(tabu)=left >*/
		fldway_1.fldlt[xscomu_1.tabu - 1] = left;
/* SOURCE xsection.for:5077 */
/*<       fldrt(tabu)=right >*/
		fldway_1.fldrt[xscomu_1.tabu - 1] = right;
/* SOURCE xsection.for:5078 */
/*<       fldarea(tabu)=area >*/
		fldway_1.fldarea[xscomu_1.tabu - 1] = area;
/* SOURCE xsection.for:5079 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5080 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5081 */
/*<       endif >*/
    }
/*     compute derivatives of square root of conveyance, alpha, beta, */
/*     da, and dq */
/* SOURCE xsection.for:5086 */
/*<        >*/
    xsecfit_(stdout, &feq_gen_c_d_0, &xscomu_1.ndepu, xscomu_1.xstu, khflag, alphaflag,
	     betaflag, maflag, mqflag, (ftnlen)1, (ftnlen)1, (ftnlen)1, (
	    ftnlen)1, (ftnlen)1);
/*     OUTPUT THE TABLE IF NO ERRORS AND IF OUTPUT IS REQUESTED */
/* SOURCE xsection.for:5093 */
/*<       if(eflag.ne.0.or.tabu.eq.0)goto200 >*/
    if (*eflag != 0 || xscomu_1.tabu == 0) {
	goto L200;
    }
/* SOURCE xsection.for:5094 */
/*<       if(nocm.eq.1)then >*/
    if (nrdzcm_1.nocm == 1) {
/* SOURCE xsection.for:5095 */
/*<       mesg=0 >*/
	mesg = 0;
/* SOURCE xsection.for:5096 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:5097 */
/*<       mesg=1 >*/
	mesg = 1;
/* SOURCE xsection.for:5098 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5099 */
/*<        >*/
    tabout_(stdout, stdtab, &xscomu_1.tabu, &xscomu_1.statu, &xscomu_1.zminu, 
	    &mesg, savopt, outopt, betopt, zone, hgrid, vdatum, unitsys, 
	    basis, khflag, alphaflag, betaflag, maflag, mqflag, &
	    xscomu_1.ndepu, xscomu_1.xstu, ftp, (ftnlen)8, (ftnlen)8, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
	    1, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE xsection.for:5104 */
/*<   200 continue >*/
L200:
/* SOURCE xsection.for:5106 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:5107 */
/*<       end >*/
} /* feqx_ */




/* SOURCE xsection.for:5111 */
/*<       subroutinexstmak(stdin,stdout,stdtab,eflag,ftp,ftknt) >*/
/* Subroutine */ int xstmak_(integer *stdin, integer *stdout, integer *stdtab,
	 integer *eflag, integer *ftp, integer *ftknt)
{
    /* Initialized data */

    static integer nbra = 1;

    /* Format strings */
    static char fmt_2[] = "(5x,f10.0)";
    static char fmt_4[] = "(7x,a4)";
    static char fmt_6[] = "(7x,a)";
    static char fmt_8[] = "(7x,a)";
    static char fmt_50[] = "(/,\002 Interpolation of cross section tables no\
t done.\002,\002  Errors found.\002)";
    static char fmt_52[] = "(/,\002 STATION FACTOR=\002,f10.2)";
    static char fmt_54[] = "(/,\002 NODE ID PRESENT: \002,a4)";
    static char fmt_56[] = "(/,\002 Flow-line name= \002,a,\002 will be soug\
ht in file name: \002,/,5x,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen),
	     f_back(alist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, ie, ng, is, nbn;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    real sfac;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char line[80];
    integer brpt[8]	/* was [8][1] */;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int clvin_(real *, integer *, integer *, integer *
	    , integer *, char *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, real *, real *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen, 
	    ftnlen), feq_gen_os_file_style_d_(char *, ftnlen);
    integer begtab, chkbar, endtab, negtab[8400], bshape;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<char> feq_heap_bnodid(67200);
    char *bnodid = feq_heap_bnodid.data(), nodeid[4], flname[6], flfile[64];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     feq_gen_maybe_add_home_d_(char *, ftnlen);
    extern integer gettbn_(integer *);
    integer typflg;
    extern /* Subroutine */ int ixtout_(integer *, integer *, integer *, 
	    integer *, integer *), feq_gen_process_flname_d_(integer *, char *, char *,
	     ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__571 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__573 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__576 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__577 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__592 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__593 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__594 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input a branch like structure and output every interpolated */
/*     cross section table requested by the user. */
/* SOURCE xsection.for:5119 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:5122 */
/*<       integereflag,ftknt,ftp,stdin,stdout,stdtab >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTP    - next open location in the function table storage */
/*     FTKNT  - function table counter */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:5133 */
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
/* INCLUDE xsection.for:5134 */
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
/* INCLUDE xsection.for:5135 */
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
/* INCLUDE xsection.for:5136 */
/*     Data structures and parameters for handling assignment */
/*     of Easting and Northing values to cross section tables */
/*     interpolated by XSINTERP. */
/* SOURCE flowline.cmn:5 */
/*<       integerfl_point_max >*/
/* SOURCE flowline.cmn:7 */
/*<       parameter(fl_point_max=5000) >*/
/* SOURCE flowline.cmn:9 */
/*<       integerfl_present,fl_pnt_knt,l >*/
/* SOURCE flowline.cmn:11 */
/*<       real*8rm_origin,s_atrmorg,rm_factor,s_begin >*/
/* SOURCE flowline.cmn:13 */
/*<        >*/
/* SOURCE flowline.cmn:17 */
/*<        >*/
/*     Definitions */
/*     L - initial pointer in search. */
/*     FL_PNT_KNT - number of points on the current flow line. */
/*     RM_ORIGIN - distance along the flow line at the point */
/*                 defining the stationing to be used in FEQ. */
/*                 This is often in miles, called river miles */
/*                 but it need not be.  This is any convenient */
/*                 point that has a given or assigned value of */
/*                 stationing.  It need not be zero! */
/*     S_ATRMORG-  Distance along the flow line at RM_ORIGIN in the units used */
/*                 for the coordinate points that define the polyline */
/*                 representing the flow line. */
/*     RM_FACTOR-  number used to multiply the units used */
/*                 for RM_ORIGIN to get the units used in S_ATRMORG. */
/*                 If the stationing in FEQ is in miles and the */
/*                 coordinate points on the flow line are given in */
/*                 feet then RM_FACTOR = 5280. */
/*     S_BEGIN- initial value to use for the cumulative distance along */
/*              flow line in its coordinate units. */
/*     FL_PRESENT- 1 if a flow line is known, 0 otherwise */
/*     FL_DISTANCE(*)-distance along the flow line at each coordinate point */
/*                     on the polyline in FEQ stationing units. */
/*     FL_EASTING(*)- the x-coordinate for a flow-line point */
/*     FL_NORTHING(*)- the y-coordinate for a flow-line point */
/*     + + + SAVED VALUES + + + */
/* SOURCE xsection.for:5139 */
/*<       integernbra >*/
/* SOURCE xsection.for:5140 */
/*<       savenbra >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:5143 */
/*<       integerbegtab,bshape,chkbar,endtab,i,ie,is,j,nbn,ng,typflg >*/
/* SOURCE xsection.for:5145 */
/*<       integerbrpt(8,1),negtab(mnbn) >*/
/* SOURCE xsection.for:5146 */
/*<       realsfac >*/
/* SOURCE xsection.for:5147 */
/*<       characterbnodid(mnbn)*8,line*80,nodeid*4,flname*6,flfile*64 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE xsection.for:5150 */
/*<       integergettbn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:5153 */
/*<       externalclvin,gettbn,inline,ixtout,os_file_style >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE xsection.for:5156 */
/*<       datanbra/1/ >*/
/* SOURCE xsection.for:5159 */
/*<     2 format(5x,f10.0) >*/
/* L2: */
/* SOURCE xsection.for:5160 */
/*<     4 format(7x,a4) >*/
/* L4: */
/* SOURCE xsection.for:5161 */
/*<     6 format(7x,a) >*/
/* L6: */
/* SOURCE xsection.for:5162 */
/*<     8 format(7x,a) >*/
/* L8: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE xsection.for:5165 */
/*<    50  >*/
/* L50: */
/* SOURCE xsection.for:5167 */
/*<    52 format(/,' STATION FACTOR=',f10.2) >*/
/* L52: */
/* SOURCE xsection.for:5168 */
/*<    54 format(/,' NODE ID PRESENT: ',a4) >*/
/* L54: */
/* SOURCE xsection.for:5169 */
/*<    56  >*/
/* L56: */
/* *********************************************************************** */
/*     Clear the flag for flow-line data */
/* SOURCE xsection.for:5173 */
/*<       fl_present=0 >*/
    flitems_1.feq_gen_fl_present_d_ = 0;
/*     Reset the initial index for searching */
/* SOURCE xsection.for:5175 */
/*<       l=1 >*/
    flitems_1.l = 1;
/*     Get the station factor */
/* SOURCE xsection.for:5177 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:5180 */
/*<       read(line,2,err=991)sfac >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&sfac, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:5181 */
/*<       write(stdout,52)sfac >*/
    feq_gen_io_d__571.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__571);
    do_fio(&feq_gen_c_d_1, (char *)&sfac, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the nodeid option string */
/* SOURCE xsection.for:5184 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:5187 */
/*<       read(line,4,err=991)nodeid >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, nodeid, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE xsection.for:5188 */
/*<       write(stdout,54)nodeid >*/
    feq_gen_io_d__573.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__573);
    do_fio(&feq_gen_c_d_1, nodeid, (ftnlen)4);
    e_wsfe();
/*     Check for the optional input of a river-mile line that */
/*     will define the location in plan of the cross-section. */
/*     Used to establish the intersection between the flow line */
/*     and the interpolated cross section. */
/* SOURCE xsection.for:5194 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:5197 */
/*<       if(line(1:6).ne.'FLNAME')then >*/
    if (s_cmp(line, const_cast<char*>("FLNAME"), (ftnlen)6, (ftnlen)6) != 0) {
/*       Put the line back!  Optional input is missing! */
/* SOURCE xsection.for:5199 */
/*<       backspace(stdin) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE xsection.for:5200 */
/*<       else >*/
    } else {
/*       Optional input is present */
/* SOURCE xsection.for:5202 */
/*<       read(line,6)flname >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_6;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, flname, (ftnlen)6);
	e_rsfi();
/* SOURCE xsection.for:5203 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE xsection.for:5206 */
/*<       read(line,8)flfile >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_8;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, flfile, (ftnlen)64);
	e_rsfi();
/* SOURCE xsection.for:5207 */
/*<       callmaybe_add_home(flfile) >*/
	feq_gen_maybe_add_home_d_(flfile, (ftnlen)64);
/* SOURCE xsection.for:5209 */
/*<       callos_file_style(flfile) >*/
	feq_gen_os_file_style_d_(flfile, (ftnlen)64);
/* SOURCE xsection.for:5212 */
/*<       write(stdout,56)flname,flfile >*/
	feq_gen_io_d__576.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__576);
	do_fio(&feq_gen_c_d_1, flname, (ftnlen)6);
	do_fio(&feq_gen_c_d_1, flfile, (ftnlen)64);
	e_wsfe();
/* SOURCE xsection.for:5213 */
/*<       callprocess_flname(stdout,flname,flfile) >*/
	feq_gen_process_flname_d_(stdout, flname, flfile, (ftnlen)6, (ftnlen)64);
/* SOURCE xsection.for:5214 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5217 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__577.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__577);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/*     Set the type flag to a non-culvert case.  TYPFLG is 1 */
/*     if a culvert barrel is involved.  Note: CHKBAR is set */
/*     here even though it is an output value because if TYPFLG is */
/*     0, CLVIN does not set CHKBAR.  CHKBAR is only used in the */
/*     CULVERT code.   NEGTAB is only used here and not in the */
/*     CULVERT code. We use HLTAB here because it is never used */
/*     in XSINTERP.  It supports a special means of giving the location */
/*     of an interpolated cross section that is needed to support the */
/*     processing of input for FEQUTL created by the stand alone */
/*     utility OVERFLOW.  HLTAB is used as work space in this case */
/*     and does not return useful information here. */
/* SOURCE xsection.for:5230 */
/*<       typflg=0 >*/
    typflg = 0;
/* SOURCE xsection.for:5231 */
/*<       chkbar=0 >*/
    chkbar = 0;
/* SOURCE xsection.for:5232 */
/*<        >*/
    clvin_(&sfac, stdin, stdout, &feq_gen_c_d_8400, &nbra, nodeid, &feq_gen_c_d_10002, &c_b1134,
	     ftablea_1.ftpnt, &typflg, eflag, ftknt, ftp, &nbn, brpt, 
	    culcom_1.nsec, culcom_1.xvec, culcom_1.zbvec, culcom_1.ka, 
	    culcom_1.kd, culcom_1.hltab, bnodid, negtab, &chkbar, &
	    culcom_1.iat3d, &culcom_1.iat6d, &bshape, &culcom_1.sbkind, (
	    ftnlen)4, (ftnlen)8);
/* SOURCE xsection.for:5239 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/*       ON RETURN THE INTERPOLATION REQUESTS HAVE BEEN DONE AND */
/*       THE TABLES ARE STORED IN FTAB() AND NODES AT WHICH */
/*       INTERPOLATION TABLES BEEN CREATED HAVE A NON-ZERO ENTRY IN */
/*       NEGTAB.  HOWEVER, NEGTAB DOES NOT  GIVE THE CURRENT */
/*       TABLE NUMBER.  NSEC() CONTAINS THE TABLE ADDRESS FOR THE */
/*       TABLE. */
/*       SCAN NEGTAB() FINDING THE REAL TABLES THAT BRACKET ANY */
/*       INTERPOLATED TABLES, AND OUTPUT THE INTERPOLATED TABLES */
/*       TO THE STANDARD TABLE FILE. */
/*       CLEAR THE NEGATIVE TABLE FLAG */
/* SOURCE xsection.for:5252 */
/*<       ng=0 >*/
	ng = 0;
/* SOURCE xsection.for:5254 */
/*<       i=1 >*/
	feq_gen_i_d_ = 1;
/* SOURCE xsection.for:5255 */
/*<   100 continue >*/
L100:
/* SOURCE xsection.for:5256 */
/*<       if(ng.eq.0)then >*/
	if (ng == 0) {
/*           WE HAVE NOT SEEN A NEGATIVE TABLE NUMBER YET */
/* SOURCE xsection.for:5258 */
/*<       if(negtab(i).eq.0)then >*/
	    if (negtab[feq_gen_i_d_ - 1] == 0) {
/*             REMEMBER THIS LOCATION IN CASE IT IS THE INITIAL */
/*             POINT FOR INTERPOLATION */
/* SOURCE xsection.for:5261 */
/*<       is=i >*/
		is = feq_gen_i_d_;
/* SOURCE xsection.for:5262 */
/*<       else >*/
	    } else {
/*             WE HAVE A NEGATIVE TABLE NUMBER. SET THE FLAG */
/* SOURCE xsection.for:5264 */
/*<       ng=1 >*/
		ng = 1;
/* SOURCE xsection.for:5265 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5266 */
/*<       else >*/
	} else {
/*           WE HAVE SEEN AT LEAST ONE NEGATIVE TABLE NUMBER */
/* SOURCE xsection.for:5268 */
/*<       if(negtab(i).eq.0)then >*/
	    if (negtab[feq_gen_i_d_ - 1] == 0) {
/*             FOUND THE FINAL POINT FOR THE INTERPOLATION */
/* SOURCE xsection.for:5270 */
/*<       ie=i >*/
		ie = feq_gen_i_d_;
/*             OUTPUT THE TABLES FROM IS+1 TO IE-1 */
/* SOURCE xsection.for:5274 */
/*<       begtab=gettbn(nsec(is)) >*/
		begtab = gettbn_(&culcom_1.nsec[is - 1]);
/* SOURCE xsection.for:5275 */
/*<       endtab=gettbn(nsec(ie)) >*/
		endtab = gettbn_(&culcom_1.nsec[ie - 1]);
/*             USE THE BEGINNING AND ENDING TABLE NUMBERS AS A */
/*             LABEL ON THE TABLE */
/* SOURCE xsection.for:5280 */
/*<       do200j=is+1,ie-1 >*/
		feq_gen_i_d_1 = ie - 1;
		for (j = is + 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:5281 */
/*<       callixtout(stdtab,stdout,nsec(j),begtab,endtab) >*/
		    ixtout_(stdtab, stdout, &culcom_1.nsec[j - 1], &begtab, &
			    endtab);
/* SOURCE xsection.for:5283 */
/*<   200 continue >*/
/* L200: */
		}
/*             CLEAR THE NEGATIVE TABLE FLAG */
/* SOURCE xsection.for:5285 */
/*<       ng=0 >*/
		ng = 0;
/* SOURCE xsection.for:5286 */
/*<       is=ie >*/
		is = ie;
/* SOURCE xsection.for:5287 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5288 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5290 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE xsection.for:5291 */
/*<       if(i.le.nbn)goto100 >*/
	if (feq_gen_i_d_ <= nbn) {
	    goto L100;
	}
/*       ALL TABLES HAVE BEEN OUTPUT */
/* SOURCE xsection.for:5294 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:5295 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__592.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__592);
	e_wsfe();
/* SOURCE xsection.for:5296 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5297 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:5298 */
/*<   991 continue >*/
L991:
/* SOURCE xsection.for:5299 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__593.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__593);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE xsection.for:5300 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__594.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__594);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE xsection.for:5301 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE xsection.for:5303 */
/*<       end >*/
    return 0;
} /* xstmak_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE xsection.for:5307 */
/*<       subroutinefqxe(stdin,stdout,stdtab,nfac,tabdir,ftp,eflag) >*/
/* Subroutine */ int fqxe_(integer *stdin, integer *stdout, integer *stdtab, 
	real *nfac, integer *feq_storage_tabdir, integer *ftp, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    char betaflag[1*999];
    integer feq_gen_i_d_, j;
    char alphaflag[1*999];
    integer loc, npi;
    real area;
    integer mesg;
    real left, xarg[11];
    char zone[8];
    real zmax;
    char hgrid[8], basis[8];
    real right;
    extern /* Subroutine */ int inspt_(integer *, integer *, real *, integer *
	    , integer *, real *, real *, integer *, real *, integer *);
    char maflag[1*999], khflag[1*999], mqflag[1*999];
    extern integer locsta_(integer *, real *, integer *, integer *, integer *,
	     real *, real *);
    char betopt[8], outopt[8], savopt[8], vdatum[8];
    extern /* Subroutine */ int cxstab_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, char *, integer *, integer *, real *
	    , real *, integer *, integer *, real *, real *, real *, real *, 
	    integer *, integer *, real *, real *, real *, integer *, real *, 
	    ftnlen), fndway_(integer *, integer *, integer *, real *, real *, 
	    real *, real *), infqxe_(integer *, integer *, integer *, integer 
	    *, integer *, real *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, real *, char *, char *, char *, real *,
	     real *, integer *, real *, real *, integer *, char *, char *, 
	    char *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen), lkupsn_(integer *, integer *, real *, 
	    integer *, real *, real *, integer *, real *), tabout_(integer *, 
	    integer *, integer *, real *, real *, integer *, char *, char *, 
	    char *, char *, char *, char *, char *, char *, char *, char *, 
	    char *, char *, char *, integer *, real *, integer *, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), feq_gen_replace_eslot_elements_d_(integer 
	    *, integer *, integer *, real *), xsecfit_(integer *, integer *, 
	    integer *, real *, char *, char *, char *, char *, char *, ftnlen,
	     ftnlen, ftnlen, ftnlen, ftnlen);
    char unitsys[8];

/*     + + + PURPOSE + + + */
/*     Process a cross section in FEQ extended format */
/* SOURCE xsection.for:5315 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE xsection.for:5318 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE xsection.for:5319 */
/*<       integertabdir(*) >*/
/* SOURCE xsection.for:5320 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     TABDIR - Table directory to remember table numbers */
/*     FTP    - next open location in the function table storage */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE xsection.for:5332 */
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
/* INCLUDE xsection.for:5333 */
/*     COMMON FOR THE UPSTREAM CROSS SECTION */

/* SOURCE xscomu.cmn:3 */
/*<       integernpntu,nsubu,navmu,tabu,ndepu,mxpntu,usgsu,snflgu >*/
/* SOURCE xscomu.cmn:4 */
/*<       integersbu(pmxpnt),nvaru(pmxsub),nnyu(pmxsub) >*/
/* SOURCE xscomu.cmn:5 */
/*<       realstatu,zminu,zmaxu >*/
/* SOURCE xscomu.cmn:6 */
/*<        >*/

/* SOURCE xscomu.cmn:10 */
/*<        >*/
/*     SNFLGU- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points. */
/*     SNU- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSNU- LINE SEGMENT N VALUE */
/*     NVARU- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: 0-N IS CONSTANT, */
/*           1-N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           2-N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*           IF N VARIES WITH DEPTH, THE N VALUE APPLIES TO THE WHOLE */
/*           SUBSECTION.  NO VARIATION OF ROUGHNESS PERMITTED ON LINE SEGMENTS */
/*           IN THE SUBSECTION. */
/*     NATYU-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATNU- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYU- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS.  VALUE IS ZERO IF NVARU FOR THE */
/*          SUBSECTION IS ZERO.  THE N DEPTH PAIR AT ZERO DEPTH IS STORED */
/*          AND COUNTED WITH NVARU > 0 FOR THE SUBSECTION. */
/*     YSMXU- MAXIMUM DEPTH IN EACH SUBSECTION. */
/* INCLUDE xsection.for:5334 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/* INCLUDE xsection.for:5335 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE xsection.for:5336 */
/*     COMMON FOR THE SINUOUSITY TABLE IN THE CHANNEL COMMAND. */
/*     USED TO REMEMBER THE VALUES THAT ARE FINALLY NEEDED TO */
/*     DEFINE THE SINUOUSITY VALUES ON THE CROSS SECTION BOUNDARY */
/* SOURCE sincom.cmn:5 */
/*<       integernumoff(pmxsec),numsec,jaxis,dir,vartyp >*/
/* SOURCE sincom.cmn:8 */
/*<        >*/
/* SOURCE sincom.cmn:13 */
/*<       common/sincom/dir,jaxis,numsec,eps,vartyp,numoff,stl,offset,sinu >*/
/* SOURCE sincom.cmn:18 */
/*<       save/sincom/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE xsection.for:5339 */
/*<       integeri,j,loc,mesg,npi >*/
/* SOURCE xsection.for:5340 */
/*<       realleft,right,xarg(pmxnfl),zmax,area >*/
/* SOURCE xsection.for:5341 */
/*<        >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE xsection.for:5348 */
/*<       integerlocsta >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE xsection.for:5351 */
/*<       externalcxstab,fndway,infqxe,inspt,lkupsn,locsta,tabout >*/
/* *********************************************************************** */
/*     ENABLE WARNINGS ABOUT SUBSECTION CONVEYANCE VARIATION */
/* SOURCE xsection.for:5354 */
/*<       nocm=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
    nrdzcm_1.nocm = 0;
/* SOURCE xsection.for:5355 */
/*<       slot=1.e30 >*/
    nrdzcm_1.slot = (float)1e30;
/* SOURCE xsection.for:5356 */
/*<       eflag=0 >*/
    *eflag = 0;
/*     INPUT NEW CROSS SECTION */
/* SOURCE xsection.for:5360 */
/*<        >*/
    infqxe_(stdin, stdout, &tabdir[1], eflag, &xscomu_1.tabu, &xscomu_1.statu,
	     &xscomu_1.npntu, &xscomu_1.nsubu, xscomu_1.xu, xscomu_1.zu, 
	    xscomu_1.sbu, xscomu_1.nu, &left, &right, savopt, outopt, betopt, 
	    &zmax, xscomu_1.lsnu, xscomu_1.nvaru, xscomu_1.natyu, 
	    xscomu_1.yatnu, xscomu_1.nnyu, zone, hgrid, vdatum, unitsys, 
	    basis, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     SET DEFAULT FOR SINUOUSITY VALUES */
/* SOURCE xsection.for:5369 */
/*<       do96i=1,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:5370 */
/*<       snu(i)=1.0 >*/
	xscomu_1.snu[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE xsection.for:5371 */
/*<    96 continue >*/
/* L96: */
    }
/* SOURCE xsection.for:5372 */
/*<       if(snflgu.gt.0)then >*/
    if (xscomu_1.snflgu > 0) {
/*       LOCATE THE CURRENT STATION IN THE SINUOUSITY TABLE. */
/* SOURCE xsection.for:5374 */
/*<       loc=locsta(stdout,statu,dir,jaxis,numsec,stl,eps) >*/
	loc = locsta_(stdout, &xscomu_1.statu, &sincom_1.dir, &sincom_1.jaxis,
		 &sincom_1.numsec, sincom_1.stl, &sincom_1.eps);
/* SOURCE xsection.for:5376 */
/*<       if(loc.le.0)then >*/
	if (loc <= 0) {
/* SOURCE xsection.for:5377 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE xsection.for:5378 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5380 */
/*<       if(eflag.ne.0)return >*/
	if (*eflag != 0) {
	    return 0;
	}
/*       INSERT THE OFFSETS FOR SINUOUSITY DEFINITION INTO THOSE */
/*       ALREADY DEFINING THE BOUNDARY. */
/* SOURCE xsection.for:5384 */
/*<       npi=numoff(loc) >*/
	npi = sincom_1.numoff[loc - 1];
/* SOURCE xsection.for:5385 */
/*<       do98i=1,npi >*/
	feq_gen_i_d_1 = npi;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:5386 */
/*<       xarg(i)=offset(loc,i) >*/
	    xarg[feq_gen_i_d_ - 1] = sincom_1.offset[loc + feq_gen_i_d_ * 400 - 401];
/* SOURCE xsection.for:5387 */
/*<    98 continue >*/
/* L98: */
	}
/* SOURCE xsection.for:5388 */
/*<       callinspt(stdout,npi,xarg,vartyp,npntu,xu,zu,sbu,lsnu,eflag) >*/
	inspt_(stdout, &npi, xarg, &sincom_1.vartyp, &xscomu_1.npntu, 
		xscomu_1.xu, xscomu_1.zu, xscomu_1.sbu, xscomu_1.lsnu, eflag);
/* SOURCE xsection.for:5394 */
/*<       if(eflag.ne.0)return >*/
	if (*eflag != 0) {
	    return 0;
	}
/*       FIND THE SINUOSITY FOR EACH POINT ON THE CROSS SECTION */
/*       BOUNDARY */
/*       ELEMENTS */
/* SOURCE xsection.for:5399 */
/*<       calllkupsn(loc,npntu,xu,vartyp,sinu,offset,npi,snu) >*/
	lkupsn_(&loc, &xscomu_1.npntu, xscomu_1.xu, &sincom_1.vartyp, 
		sincom_1.sinu, sincom_1.offset, &npi, xscomu_1.snu);
/*        WRITE(STDOUT,*) ' ' */
/*        WRITE(STDOUT,*) ' CHECK OF SINUOSITY ASSIGNMENTS' */
/*        WRITE(STDOUT,1234) */
/* 1234  FORMAT(1X,4X,'OFFSET ELEVATION SUBS SINUOSITY') */
/*        DO 1235 I=1,NPNTU */
/*          WRITE(STDOUT,1236) XU(I), ZU(I), SBU(I), SNU(I) */
/* 1236  FORMAT(1X,F10.2,F10.2,I5,F10.6) */
/* 1235    CONTINUE */
/* SOURCE xsection.for:5411 */
/*<       endif >*/
    }
/*     COMPUTE ELEMENTS FOR CURRENT CROSS SECTION */
/* SOURCE xsection.for:5416 */
/*<       if(npntu.gt.1)then >*/
    if (xscomu_1.npntu > 1) {
/*       FIND THE MAXIMUM AND MINIMUM ARGUMENT VALUES */
/* SOURCE xsection.for:5418 */
/*<       zminu=9999999. >*/
	xscomu_1.zminu = (float)9999999.;
/* SOURCE xsection.for:5419 */
/*<       zmaxu=-9999999. >*/
	xscomu_1.zmaxu = (float)-9999999.;
/* SOURCE xsection.for:5420 */
/*<       do150j=1,npntu >*/
	feq_gen_i_d_1 = xscomu_1.npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:5421 */
/*<       if(zu(j).gt.zmaxu)zmaxu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] > xscomu_1.zmaxu) {
		xscomu_1.zmaxu = xscomu_1.zu[j - 1];
	    }
/* SOURCE xsection.for:5422 */
/*<       if(zu(j).lt.zminu)zminu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] < xscomu_1.zminu) {
		xscomu_1.zminu = xscomu_1.zu[j - 1];
	    }
/* SOURCE xsection.for:5423 */
/*<   150 continue >*/
/* L150: */
	}
/* SOURCE xsection.for:5425 */
/*<       if(extend.eq.0)zmaxu=zmax >*/
	if (nrdzcm_1.extend == 0) {
	    xscomu_1.zmaxu = zmax;
	}
/*       FIND THE VALUE OF RIGHT AND LEFT IF FLOOD WAY OPTION */
/*       IS ACTIVE */
/* SOURCE xsection.for:5430 */
/*<       if(flood.eq.1)then >*/
	if (fldway_1.flood == 1) {
/* SOURCE xsection.for:5431 */
/*<       callfndway(tabu,stdout,eflag,nfac,left,right,area) >*/
	    fndway_(&xscomu_1.tabu, stdout, eflag, nfac, &left, &right, &area)
		    ;
/* SOURCE xsection.for:5434 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5435 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/* SOURCE xsection.for:5436 */
/*<       navmu=0 >*/
	    xscomu_1.navmu = 0;
/* SOURCE xsection.for:5437 */
/*<        >*/
	    cxstab_(stdout, &xscomu_1.nsubu, &xscomu_1.navmu, nfac, &
		    xscomu_1.mxpntu, &left, &right, betopt, &xscomu_1.snflgu, 
		    xscomu_1.nvaru, xscomu_1.natyu, xscomu_1.yatnu, 
		    xscomu_1.nnyu, &xscomu_1.npntu, &xscomu_1.zminu, &
		    xscomu_1.zmaxu, xscomu_1.xu, xscomu_1.zu, xscomu_1.sbu, 
		    eflag, xscomu_1.lsnu, xscomu_1.snu, xscomu_1.nu, &
		    xscomu_1.ndepu, xscomu_1.xstu, (ftnlen)8);
/* SOURCE xsection.for:5445 */
/*<       if(flood.eq.1)then >*/
	    if (fldway_1.flood == 1) {
/*           STORE LEFT AND RIGHT AGAIN TO */
/*           REFLECT CHANGES MADE IN CSXTAB */
/* SOURCE xsection.for:5448 */
/*<       fldlt(tabu)=left >*/
		fldway_1.fldlt[xscomu_1.tabu - 1] = left;
/* SOURCE xsection.for:5449 */
/*<       fldrt(tabu)=right >*/
		fldway_1.fldrt[xscomu_1.tabu - 1] = right;
/* SOURCE xsection.for:5450 */
/*<       fldarea(tabu)=area >*/
		fldway_1.fldarea[xscomu_1.tabu - 1] = area;
/* SOURCE xsection.for:5451 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5452 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5453 */
/*<       endif >*/
    }
/*     Check if an exponential slot is present and  optionally replace alpha, */
/*     beta, ma, and mq from a function table supplied by the user.  The */
/*     id for this table is the current table id with a lower case a appended */
/*     to it.  If such a table is not present, then the element values remain */
/*     as computed. */
/* SOURCE xsection.for:5461 */
/*<       callreplace_eslot_elements(stdout,tabu,ndepu,xstu) >*/
    feq_gen_replace_eslot_elements_d_(stdout, &xscomu_1.tabu, &xscomu_1.ndepu, 
	    xscomu_1.xstu);
/*     compute derivatives of square root of conveyance, alpha, beta, */
/*     da, and dq */
/* SOURCE xsection.for:5467 */
/*<        >*/
    xsecfit_(stdout, &feq_gen_c_d_0, &xscomu_1.ndepu, xscomu_1.xstu, khflag, alphaflag,
	     betaflag, maflag, mqflag, (ftnlen)1, (ftnlen)1, (ftnlen)1, (
	    ftnlen)1, (ftnlen)1);
/*     OUTPUT THE TABLE IF NO ERRORS AND IF OUTPUT IS REQUESTED */
/* SOURCE xsection.for:5474 */
/*<       if(eflag.ne.0.or.tabu.eq.0)goto200 >*/
    if (*eflag != 0 || xscomu_1.tabu == 0) {
	goto L200;
    }
/* SOURCE xsection.for:5475 */
/*<       if(nocm.eq.1)then >*/
    if (nrdzcm_1.nocm == 1) {
/* SOURCE xsection.for:5476 */
/*<       mesg=0 >*/
	mesg = 0;
/* SOURCE xsection.for:5477 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:5478 */
/*<       mesg=1 >*/
	mesg = 1;
/* SOURCE xsection.for:5479 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5480 */
/*<        >*/
    tabout_(stdout, stdtab, &xscomu_1.tabu, &xscomu_1.statu, &xscomu_1.zminu, 
	    &mesg, savopt, outopt, betopt, zone, hgrid, vdatum, unitsys, 
	    basis, khflag, alphaflag, betaflag, maflag, mqflag, &
	    xscomu_1.ndepu, xscomu_1.xstu, ftp, (ftnlen)8, (ftnlen)8, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
	    1, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE xsection.for:5485 */
/*<   200 continue >*/
L200:
/* SOURCE xsection.for:5488 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:5489 */
/*<       end >*/
} /* fqxe_ */




/* SOURCE xsection.for:5494 */
/*<        >*/
/* Subroutine */ int feq_gen_add_slote_d_(integer *stdout, real *nfac, integer *
	feq_gen_in_ss_nvar_d_, integer *npnt, integer *nsub, real *feq_storage_n, real *zmin, real 
	*feq_storage_x, real *feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real *feq_storage_lsn, real *feq_storage_sn, integer *added)
{
    /* Initialized data */

    static real feq_gen_eps_base_d_ = (float)5e-4;
    static real pi = (float)3.14159265;
    static real feq_gen_shift_base_d_ = (float).053;

    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:724* Maximum number of subsections\
=\002,i5,\002 exceeded in adding an invert slot.\002)";
    static char fmt_52[] = "(/,\002*ERR:* Minimum line-segment length=\002,1\
pe12.4,\002 in slot is smaller\002,/,5x,\002 than the point tolerance in add\
_slote=\002,1pe12.4)";
    static char fmt_54[] = "(/,\002*PROBLEM* Subset operations on cross sect\
ions with\002,\002 roughness varying with depth not yet supported.\002)";
    static char fmt_89[] = "(\002  Check of min search in add_slote:\002,/\
,\002    Pointer     Width\002)";
    static char fmt_90[] = "(\002 \002,i10,f10.3)";
    static char fmt_2530[] = "(\002index sltoffset elevation\002)";
    static char fmt_2351[] = "(i5,f10.6,f10.5)";
    static char fmt_145[] = "(\002 i_xs_left=\002,i5,\002 i_xs_right=\002,\
i5,\002 i_start_slot=\002,i5,\002 i_end_slot=\002,i5,\002 n_cross=\002,i5)";
    static char fmt_146[] = "(\002 xl=\002,1pe12.4,\002 xr=\002,1pe12.4)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), do_fio(integer *, char *, ftnlen);
    double cos(doublereal), exp(doublereal), sqrt(doublereal);

    /* Local variables */
    real feq_gen_zmin_new_d_;
    integer feq_gen_i_d_, j;
    char feq_gen_change_sb_d_[1];
    real y;
    char feq_gen_retain_sb_d_[1];
    integer feq_gen_i_xs_left_d_;
    real t0, y0;
    integer is, nn;
    real ls, xl, xm, zl, zm, ym, xr, zr;
    integer feq_gen_i_end_slot_d_;
    extern /* Subroutine */ int feq_gen_find_cross_d_(integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, real *, real *, 
	    real *, integer *, integer *, real *, real *);
    integer feq_gen_retain_sub_d_, feq_gen_i_xs_right_d_;
    real eps;
    char feq_gen_e_cls_match_d_[1];
    real top;
    char feq_gen_s_cls_match_d_[1], feq_gen_remember_sb_d_[1], feq_gen_e_cls_short_d_[1], feq_gen_s_cls_short_d_[
	    1];
    real feq_gen_slot_offset_d_[23];
    integer imid, iold, inew;
    char feq_gen_e_slot_match_d_[1];
    integer feq_gen_remember_sub_d_;
    char feq_gen_s_slot_match_d_[1];
    extern /* Subroutine */ int feq_gen_shift_values_d_(integer *, integer *, integer *
	    , integer *, real *, real *, integer *, real *, real *);
    integer feq_gen_i_start_slot_d_, eflag, feq_gen_i_e_cls_match_d_;
    real width[999], shift;
    integer feq_gen_i_s_cls_match_d_, itype;
    real xslot;
    integer feq_gen_min_at_d_;
    real minoff, maxoff, feq_gen_min_ls_d_;
    extern /* Subroutine */ int reasub_(integer *, integer *, integer *, real 
	    *, integer *, integer *);
    integer feq_gen_i_e_slot_match_d_;
    real bottom;
    integer feq_gen_i_s_slot_match_d_;
    real feq_gen_sum_ls_d_, feq_gen_slot_y_d_[23];
    integer feq_gen_min_knt_d_, feq_gen_min_pnt_d_[999], feq_gen_n_cross_d_, ilcross;
    real feq_gen_sum_nls_d_;
    integer ircross;
    real feq_gen_slot_xl_d_, feq_gen_slot_zl_d_, feq_gen_slot_xm_d_, feq_gen_slot_zm_d_, feq_gen_slot_xr_d_, feq_gen_slot_zr_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__623 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__631 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__632 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__633 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__644 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__645 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__646 = { 0, 0, 0, fmt_2530, 0 };
    static cilist feq_gen_io_d__647 = { 0, 0, 0, fmt_2351, 0 };
    static cilist feq_gen_io_d__650 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__651 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__652 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__657 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__681 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__683 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__694 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__695 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__696 = { 0, 0, 0, fmt_145, 0 };
    static cilist feq_gen_io_d__697 = { 0, 0, 0, fmt_146, 0 };
    static cilist feq_gen_io_d__698 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__704 = { 0, 0, 0, 0, 0 };


/*     Potentially add a bottom slot to a cross section description. */
/*     This is a slot with sides expanding as an exponential above */
/*     a certain depth such that the hydraulic depth is a constant. */
/*     See CXSTAB for definition of arguments. */
/* SOURCE xsection.for:5505 */
/*<       implicitnone >*/
/* INCLUDE xsection.for:5506 */
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
/* SOURCE xsection.for:5508 */
/*<       integeradded,stdout,nsub,sb(pmxpnt),npnt,in_ss_nvar >*/
/* SOURCE xsection.for:5510 */
/*<       realnfac,zmin >*/
/* SOURCE xsection.for:5512 */
/*<       realx(pmxpnt),z(pmxpnt),lsn(pmxpnt),sn(pmxpnt),n(pmxsub) >*/
/* INCLUDE xsection.for:5515 */
/*     Values used to keep track of a bottom slot in a cross section. */
/* SOURCE abslot.cmn:3 */
/*<       integerslot_present >*/
/* SOURCE abslot.cmn:5 */
/*<       realnslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:7 */
/*<       common/abslot/slot_present,nslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:10 */
/*<       save/abslot/ >*/
/*     SLOT_PRESENT: 0 no slot. 1 triangular slot, 2 exponential slot */
/*     NSLOT:  Manning's n for the slot if nslot > 0.  If nslot < 0.0 */
/*             use the average of the Manning's n's at the edges of the slot */
/*             and multiply by abs(nslot).  E. g. -1.2 computes the average value */
/*             of manning's n from the two bounding values in the cross section */
/*             and multiplies this averge by 1.2 to get the manning's n for the slot */
/*     WSLOT: width of the slot at the invert elevation of the cross section for a triangular */
/*            slot.  For the default exponential slot, it also gives the width of the slot */
/*            at the section invert.  If non-default values of rd are used, then the */
/*            meaning may differ. */
/*     ESLOT: elevation of the invert of the slot. */
/*     YSLOT: distance from slot invert to the cross section invert. */
/*     RD - factor on yslot to compute the y0 value for the exponential slot. */
/*          default value= 0.379376194959581.  This value together with the default */
/*          value of tzero has some convenient properties. */
/*     TZERO - width of the triangular section that forms the bottom portion of the */
/*             exponential slot.  Default value = 0.1*rd*wslot.  This default gives */
/*             an exponential slot with a width at the top of WSLOT.   A value of */
/*             wslot = 1/rd gives an area equal to the triangular slot with a */
/*             top width of 1.0. */
/*     EXPFAC - factor on the exponent in the exponential channel. Default value=1.0 */
/*              expfac > 1 gives a top-width increase larger than the default. */

/*     Only one of ESLOT or YSLOT is used.  YSLOT is the better choice for consistent */
/*     interpolation between sections. */
/* INCLUDE xsection.for:5516 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/* SOURCE xsection.for:5518 */
/*<       integernp >*/
/* SOURCE xsection.for:5519 */
/*<       parameter(np=23) >*/
/* SOURCE xsection.for:5520 */
/*<        >*/
/* SOURCE xsection.for:5525 */
/*<        >*/
/* SOURCE xsection.for:5531 */
/*<        >*/
/* SOURCE xsection.for:5537 */
/*<       realslot_y(np),slot_offset(np) >*/
/*     ********************************FORMATS************************** */
/* SOURCE xsection.for:5539 */
/*<       dataeps_base/0.0005/,pi/3.14159265/,shift_base/0.053/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    /* Function Body */
/* SOURCE xsection.for:5541 */
/*<    50  >*/
/* L50: */
/* SOURCE xsection.for:5543 */
/*<    52  >*/
/* L52: */
/* SOURCE xsection.for:5546 */
/*<    54  >*/
/* L54: */
/* ********************************************************************** */
/*     Set tolerance based on nfac */
/* SOURCE xsection.for:5550 */
/*<       if(nfac.lt.1.2)then >*/
    if (*nfac < (float)1.2) {
/*       metric (si more or less) */
/* SOURCE xsection.for:5552 */
/*<       eps=0.3048*eps_base >*/
	eps = static_cast<double>(feq_gen_eps_base_d_) * (float).3048;
/* SOURCE xsection.for:5553 */
/*<       shift=0.3048*shift_base >*/
	shift = static_cast<double>(feq_gen_shift_base_d_) * (float).3048;
/* SOURCE xsection.for:5554 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:5555 */
/*<       eps=eps_base >*/
	eps = feq_gen_eps_base_d_;
/* SOURCE xsection.for:5556 */
/*<       shift=shift_base >*/
	shift = feq_gen_shift_base_d_;
/* SOURCE xsection.for:5557 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5559 */
/*<       if(slot_present.eq.0)then >*/
    if (abslot_1.feq_gen_slot_present_d_ == 0) {
/* SOURCE xsection.for:5560 */
/*<       slot_depth=0.0 >*/
	xtadd_1.feq_gen_slot_depth_d_ = (float)0.;
/* SOURCE xsection.for:5561 */
/*<       added=0 >*/
	*added = 0;
/* SOURCE xsection.for:5562 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:5563 */
/*<       elseif(slot_present.ne.2)then >*/
    } else if (abslot_1.feq_gen_slot_present_d_ != 2) {
/*       Triangular slot is present. */
/* SOURCE xsection.for:5565 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:5566 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5568 */
/*<       if(in_ss_nvar/=0)then >*/
    if (*feq_gen_in_ss_nvar_d_ != 0) {
/* SOURCE xsection.for:5569 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__623.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__623);
	e_wsfe();
/* SOURCE xsection.for:5570 */
/*<       stop'Abnormal stop. Feature not yet supported.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Feature not yet supported."), (ftnlen)41);
/* SOURCE xsection.for:5571 */
/*<       endif >*/
    }
/*     We know the minimum elevation on entry.  Do another search to */
/*     locate and describe the various extremes, e. g. the width of the */
/*     section at the one or more minimum points. */
/*     Processing a horizontal bottom becomes messy when adding a bottom slot. */
/*     Especially messy are horizontal bottoms represented by more then one */
/*     line segment.  The additional point may be there because there is a change */
/*     in sub-section number or it may just be an extra point not really needed. */
/*     We will try to find these horizontal segments at the current zmin and */
/*     adjust them slightly to be non-horizontal. */
/* SOURCE xsection.for:5584 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE xsection.for:5585 */
/*<       zmin_new=-1.e30 >*/
    feq_gen_zmin_new_d_ = (float)-1e30;
/* SOURCE xsection.for:5586 */
/*<   500 continue >*/
L500:
/* SOURCE xsection.for:5587 */
/*<       if(abs(z(i)-zmin).le.eps)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(feq_gen_z_d_[feq_gen_i_d_]) - *zmin, dabs(feq_gen_r_d_1)) <= eps) {
/*         we have a point at min elevation. */
/* SOURCE xsection.for:5589 */
/*<       if(abs(z(i+1)-zmin).le.eps)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(feq_gen_z_d_[feq_gen_i_d_ + 1]) - *zmin, dabs(feq_gen_r_d_1)) <= eps) {
/*           we have a horizontal line segment. */
/*           decrement the right end. */
/* SOURCE xsection.for:5592 */
/*<       z(i+1)=z(i+1)-shift >*/
	    feq_gen_z_d_[feq_gen_i_d_ + 1] -= static_cast<double>(shift);
/* SOURCE xsection.for:5593 */
/*<       zmin_new=z(i+1) >*/
	    feq_gen_zmin_new_d_ = feq_gen_z_d_[feq_gen_i_d_ + 1];
/* SOURCE xsection.for:5595 */
/*<       i=i+2 >*/
	    feq_gen_i_d_ += 2;
/* SOURCE xsection.for:5596 */
/*<       if(i.lt.npnt)goto500 >*/
	    if (feq_gen_i_d_ < *npnt) {
		goto L500;
	    }
/* SOURCE xsection.for:5597 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5598 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5599 */
/*<       i=i+1 >*/
    ++feq_gen_i_d_;
/* SOURCE xsection.for:5600 */
/*<       if(i.lt.npnt)goto500 >*/
    if (feq_gen_i_d_ < *npnt) {
	goto L500;
    }
/* SOURCE xsection.for:5602 */
/*<       if(zmin_new.gt.-1.e30)then >*/
    if (feq_gen_zmin_new_d_ > (float)-1e30) {
/* SOURCE xsection.for:5603 */
/*<       zmin=zmin_new >*/
	*zmin = feq_gen_zmin_new_d_;
/* SOURCE xsection.for:5604 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' In ADD_SLOT: ZMIN=',ZMIN */
/* SOURCE xsection.for:5607 */
/*<       min_knt=0 >*/
    feq_gen_min_knt_d_ = 0;
/* SOURCE xsection.for:5608 */
/*<       minoff=1.e30 >*/
    minoff = (float)1e30;
/* SOURCE xsection.for:5609 */
/*<       maxoff=-1.e30 >*/
    maxoff = (float)-1e30;
/* SOURCE xsection.for:5610 */
/*<       do100i=1,npnt >*/
    feq_gen_i_d_1 = *npnt;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:5611 */
/*<       if(abs(z(i)-zmin).le.eps)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(feq_gen_z_d_[feq_gen_i_d_]) - *zmin, dabs(feq_gen_r_d_1)) <= eps) {
/*         We have a match. */
/* SOURCE xsection.for:5613 */
/*<       min_knt=min_knt+1 >*/
	    ++feq_gen_min_knt_d_;
/* SOURCE xsection.for:5614 */
/*<       min_pnt(min_knt)=i >*/
	    feq_gen_min_pnt_d_[feq_gen_min_knt_d_ - 1] = feq_gen_i_d_;
/*         Does the point to the right, if it exists, have essentially */
/*         the same elevation? */
/* SOURCE xsection.for:5617 */
/*<       if(i.lt.npnt)then >*/
	    if (feq_gen_i_d_ < *npnt) {
/* SOURCE xsection.for:5618 */
/*<       if(abs(z(i+1)-zmin).le.eps)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(feq_gen_z_d_[feq_gen_i_d_ + 1]) - *zmin, dabs(feq_gen_r_d_1)) <= eps) {
/*             Yes.  We have an essentially horizontal segment at */
/*             the minimum elevation. */
/* SOURCE xsection.for:5621 */
/*<       width(min_knt)=x(i+1)-x(i) >*/
		    width[feq_gen_min_knt_d_ - 1] = static_cast<double>(x[feq_gen_i_d_ + 1]) - x[feq_gen_i_d_];
/* SOURCE xsection.for:5622 */
/*<       else >*/
		} else {
/*             Bottom width to right is zero. */
/* SOURCE xsection.for:5624 */
/*<       width(min_knt)=0.0 >*/
		    width[feq_gen_min_knt_d_ - 1] = (float)0.;
/* SOURCE xsection.for:5625 */
/*<       endif >*/
		}
/* SOURCE xsection.for:5626 */
/*<       else >*/
	    } else {
/*           Point to the right does not exist.  Bottom width to */
/*           right of point is zero. */
/* SOURCE xsection.for:5630 */
/*<       width(min_knt)=0.0 >*/
		width[feq_gen_min_knt_d_ - 1] = (float)0.;
/* SOURCE xsection.for:5631 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5632 */
/*<       endif >*/
	}
/*       Find the extreme offsets. */
/* SOURCE xsection.for:5634 */
/*<       maxoff=max(maxoff,x(i)) >*/
/* Computing MAX */
	feq_gen_r_d_1 = maxoff, feq_gen_r_d_2 = x[feq_gen_i_d_];
	maxoff = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE xsection.for:5635 */
/*<       minoff=min(minoff,x(i)) >*/
/* Computing MIN */
	feq_gen_r_d_1 = minoff, feq_gen_r_d_2 = x[feq_gen_i_d_];
	minoff = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE xsection.for:5637 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE xsection.for:5638 */
/*<       if(min_knt.eq.0)then >*/
    if (feq_gen_min_knt_d_ == 0) {
/* SOURCE xsection.for:5639 */
/*<       write(stdout,*)' BUG in ADD_SLOTE.  No minimum match found' >*/
	feq_gen_io_d__631.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__631);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG in ADD_SLOTE.  No minimum match found"), (
		ftnlen)42);
	e_wsle();
/* SOURCE xsection.for:5640 */
/*<       stop'Abnormal stop' >*/
	s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:5641 */
/*<       endif >*/
    }
/* SOURCE xsection.for:5643 */
/*<       write(stdout,89) >*/
    feq_gen_io_d__632.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__632);
    e_wsfe();
/* SOURCE xsection.for:5644 */
/*<    89  >*/
/* SOURCE xsection.for:5646 */
/*<       do1234i=1,min_knt >*/
    feq_gen_i_d_1 = feq_gen_min_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:5647 */
/*<       write(stdout,90)min_pnt(i),width(i) >*/
	feq_gen_io_d__633.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__633);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_min_pnt_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&width[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:5648 */
/*<  1234 continue >*/
/* L1234: */
    }
/* SOURCE xsection.for:5649 */
/*<    90 format(' ',i10,f10.3) >*/
/* SOURCE xsection.for:5652 */
/*<       added=1 >*/
    *added = 1;
/*     Compute the slot vertical extent. */
/* SOURCE xsection.for:5654 */
/*<       if(yslot.gt.0.0)then >*/
    if (abslot_1.yslot > (float)0.) {
/*       Add a fixed size slot to the bottom of each cross section. */
/*       Redefine ESLOT to be the new invert. */
/* SOURCE xsection.for:5657 */
/*<       eslot=zmin-yslot >*/
	abslot_1.eslot = static_cast<double>(*zmin) - abslot_1.yslot;
/* SOURCE xsection.for:5658 */
/*<       slot_depth=yslot >*/
	xtadd_1.feq_gen_slot_depth_d_ = abslot_1.yslot;
/* SOURCE xsection.for:5659 */
/*<       else >*/
    } else {
/*       Add a slot that has an invert at a fixed elevation to */
/*       each cross section. */
/* SOURCE xsection.for:5662 */
/*<       slot_depth=zmin-eslot >*/
	xtadd_1.feq_gen_slot_depth_d_ = static_cast<double>(*zmin) - abslot_1.eslot;
/* SOURCE xsection.for:5663 */
/*<       yslot=slot_depth >*/
	abslot_1.yslot = xtadd_1.feq_gen_slot_depth_d_;
/* SOURCE xsection.for:5664 */
/*<       if(slot_depth.lt.0.0)then >*/
	if (xtadd_1.feq_gen_slot_depth_d_ < (float)0.) {
/*         No slot needed */
/* SOURCE xsection.for:5666 */
/*<       slot_depth=0.0 >*/
	    xtadd_1.feq_gen_slot_depth_d_ = (float)0.;
/* SOURCE xsection.for:5667 */
/*<       return >*/
	    return 0;
/* SOURCE xsection.for:5668 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5669 */
/*<       endif >*/
    }
/*     Save positive value of slot depth. */
/* SOURCE xsection.for:5672 */
/*<       ym=slot_depth >*/
    ym = xtadd_1.feq_gen_slot_depth_d_;
/*     Set the values for this slot.  The default value of rd has been defined */
/*     so that we will get a width at the top of the slot equal to WSLOT, */
/*     the same as for the triangular slot supported earlier.  The */
/*     area of the exponential slot is then also rd of the area of the */
/*     triangular slot.  These ratios hold for all values of ym. */
/*     A value of WSLOT of 1/rd = 2.6359, gives us about the same */
/*     area as the triangular slot with a unit top width. */
/*     compute the depth of the base cross section */
/* SOURCE xsection.for:5683 */
/*<       y0=rd*ym >*/
    y0 = static_cast<double>(abslot_1.rd) * ym;
/*     compute the top width of the base cross section */
/* SOURCE xsection.for:5686 */
/*<       if(tzero.lt.0.0)then >*/
    if (abslot_1.tzero < (float)0.) {
/*       use default value */
/* SOURCE xsection.for:5688 */
/*<       t0=rd*wslot/10.0 >*/
	t0 = static_cast<double>(static_cast<double>(abslot_1.rd) * abslot_1.wslot) / (float)10.;
/* SOURCE xsection.for:5689 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:5690 */
/*<       t0=tzero >*/
	t0 = abslot_1.tzero;
/* SOURCE xsection.for:5691 */
/*<       endif >*/
    }
/*      write(stdout,*) ' y0=',y0,' t0=',t0 */
/*     compute the slot shape relative to the zero depth point. */
/*     find the middle index for the points on the slot boundary. */
/*     Note the number of points must always be odd so that there is */
/*     a unique middle point. */
/* SOURCE xsection.for:5700 */
/*<       nn=(np-1)/2 >*/
    nn = 11;
/* SOURCE xsection.for:5701 */
/*<       imid=nn+1 >*/
    imid = nn + 1;
/* SOURCE xsection.for:5702 */
/*<       slot_y(imid)=0.0 >*/
    feq_gen_slot_y_d_[imid - 1] = (float)0.;
/* SOURCE xsection.for:5703 */
/*<       slot_offset(imid)=0.0 >*/
    feq_gen_slot_offset_d_[imid - 1] = (float)0.;
/* SOURCE xsection.for:5704 */
/*<       doi=1,nn >*/
    feq_gen_i_d_1 = nn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       use the upper half of the expanded Chebyshev points */
/* SOURCE xsection.for:5707 */
/*<       j=nn+i-1 >*/
	j = nn + feq_gen_i_d_ - 1;
/* SOURCE xsection.for:5708 */
/*<        >*/
	y = y0 - (static_cast<double>(ym) - y0) * cos(static_cast<double>(static_cast<double>(pi) * (real) ((j << 1) - 1)) / (float)42.) / 
		cos(static_cast<double>(pi) / (float)42.);
/*        y = y0 + real(i-1)*(ym - y0)/real(nn-1) */
/* SOURCE xsection.for:5711 */
/*<       top=t0*exp(2.*expfac*(y/y0-1.0)) >*/
	top = t0 * exp(static_cast<double>(static_cast<double>(abslot_1.expfac) * (float)2.) * (static_cast<double>(static_cast<double>(y) / y0) - (float)1.));
/* SOURCE xsection.for:5712 */
/*<       slot_y(imid-i)=y >*/
	feq_gen_slot_y_d_[imid - feq_gen_i_d_ - 1] = y;
/* SOURCE xsection.for:5713 */
/*<       slot_offset(imid-i)=-top/2.0 >*/
	feq_gen_slot_offset_d_[imid - feq_gen_i_d_ - 1] = static_cast<double>(-top) / (float)2.;
/* SOURCE xsection.for:5714 */
/*<       slot_y(imid+i)=y >*/
	feq_gen_slot_y_d_[imid + feq_gen_i_d_ - 1] = y;
/* SOURCE xsection.for:5715 */
/*<       slot_offset(imid+i)=top/2.0 >*/
	feq_gen_slot_offset_d_[imid + feq_gen_i_d_ - 1] = static_cast<double>(top) / (float)2.;
/* SOURCE xsection.for:5716 */
/*<       enddo >*/
    }
/* SOURCE xsection.for:5718 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__644.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__644);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE xsection.for:5719 */
/*<       write(stdout,*)' Dump of slot boundary' >*/
    feq_gen_io_d__645.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__645);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Dump of slot boundary"), (ftnlen)22);
    e_wsle();
/* SOURCE xsection.for:5720 */
/*<       write(stdout,2530) >*/
    feq_gen_io_d__646.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__646);
    e_wsfe();
/* SOURCE xsection.for:5721 */
/*<  2530 format('index sltoffset elevation') >*/
/* SOURCE xsection.for:5722 */
/*<       doi=1,np >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 23; ++feq_gen_i_d_) {
/* SOURCE xsection.for:5723 */
/*<       write(stdout,2351)i,slot_offset(i),slot_y(i) >*/
	feq_gen_io_d__647.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__647);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_slot_offset_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_slot_y_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:5724 */
/*<  2351 format(i5,f10.6,f10.5) >*/
/* SOURCE xsection.for:5725 */
/*<       enddo >*/
    }
/*     Find the smallest line segment length on the slot boundary. */
/* SOURCE xsection.for:5728 */
/*<       min_ls=1.e30 >*/
    feq_gen_min_ls_d_ = (float)1e30;
/* SOURCE xsection.for:5729 */
/*<       doi=imid+1,np >*/
    for (feq_gen_i_d_ = imid + 1; feq_gen_i_d_ <= 23; ++feq_gen_i_d_) {
/* SOURCE xsection.for:5730 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(feq_gen_slot_y_d_[feq_gen_i_d_ - 1]) - feq_gen_slot_y_d_[feq_gen_i_d_ - 2];
/* Computing 2nd power */
	feq_gen_r_d_2 = static_cast<double>(feq_gen_slot_offset_d_[feq_gen_i_d_ - 1]) - feq_gen_slot_offset_d_[feq_gen_i_d_ - 2];
	ls = sqrt(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2);
/* SOURCE xsection.for:5732 */
/*<       min_ls=min(ls,min_ls) >*/
	feq_gen_min_ls_d_ = dmin(ls,feq_gen_min_ls_d_);
/* SOURCE xsection.for:5733 */
/*<       enddo >*/
    }
/* SOURCE xsection.for:5734 */
/*<        >*/
    feq_gen_io_d__650.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__650);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Minimum-length slot line segment has length="), (
	    ftnlen)45);
    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_min_ls_d_, (ftnlen)sizeof(real));
    e_wsle();
/*     Use half of smallest line segment as the tolerance below */
/* SOURCE xsection.for:5738 */
/*<       min_ls=0.5*min_ls >*/
    feq_gen_min_ls_d_ *= static_cast<double>((float).5);
/* SOURCE xsection.for:5739 */
/*<       if(min_ls.le.eps)then >*/
    if (feq_gen_min_ls_d_ <= eps) {
/* SOURCE xsection.for:5740 */
/*<       write(stdout,52)min_ls,eps >*/
	feq_gen_io_d__651.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__651);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_min_ls_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&eps, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE xsection.for:5741 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE xsection.for:5742 */
/*<       endif >*/
    }
/*     Change sign of slot so that we can add to get the result. */
/*     SLOT is now the distance to the bottom of the slot from the min */
/*     elevation in the cross section. */
/* SOURCE xsection.for:5747 */
/*<       slot_depth=-slot_depth >*/
    xtadd_1.feq_gen_slot_depth_d_ = -xtadd_1.feq_gen_slot_depth_d_;
/* SOURCE xsection.for:5750 */
/*<       if(wslot.ge.maxoff-minoff)then >*/
    if (abslot_1.wslot >= static_cast<double>(maxoff) - minoff) {
/* SOURCE xsection.for:5751 */
/*<       write(stdout,*)' *ERR:725*  Bottom slot wider than section!' >*/
	feq_gen_io_d__652.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__652);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:725*  Bottom slot wider than section!"), (
		ftnlen)43);
	e_wsle();
/* SOURCE xsection.for:5752 */
/*<       stop'Abnormal stop' >*/
	s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:5753 */
/*<       endif >*/
    }
/*     Now select the point at which to place the slot.  We have no */
/*     choice if MIN_KNT = 1! */
/* SOURCE xsection.for:5758 */
/*<       if(min_knt.eq.1)then >*/
    if (feq_gen_min_knt_d_ == 1) {
/* SOURCE xsection.for:5759 */
/*<       min_at=min_pnt(1) >*/
	feq_gen_min_at_d_ = feq_gen_min_pnt_d_[0];
/* SOURCE xsection.for:5760 */
/*<       bottom=width(1) >*/
	bottom = width[0];
/* SOURCE xsection.for:5761 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:5762 */
/*<       bottom=-1.e30 >*/
	bottom = (float)-1e30;
/* SOURCE xsection.for:5763 */
/*<       do110j=1,min_knt >*/
	feq_gen_i_d_1 = feq_gen_min_knt_d_;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE xsection.for:5764 */
/*<       if(width(j).gt.bottom)then >*/
	    if (width[j - 1] > bottom) {
/* SOURCE xsection.for:5765 */
/*<       min_at=min_pnt(j) >*/
		feq_gen_min_at_d_ = feq_gen_min_pnt_d_[j - 1];
/* SOURCE xsection.for:5766 */
/*<       bottom=width(j) >*/
		bottom = width[j - 1];
/* SOURCE xsection.for:5767 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5768 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE xsection.for:5769 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' MIN_AT=',MIN_AT,' BOTTOM=',BOTTOM */
/* SOURCE xsection.for:5773 */
/*<       xm=x(min_at) >*/
    xm = x[feq_gen_min_at_d_];
/* SOURCE xsection.for:5774 */
/*<       zm=z(min_at) >*/
    zm = feq_gen_z_d_[feq_gen_min_at_d_];
/*     Now add the new subsection and adjust the vectors. */
/* SOURCE xsection.for:5777 */
/*<       nsub=nsub+1 >*/
    ++(*nsub);
/* SOURCE xsection.for:5778 */
/*<       if(nsub.gt.pmxsub)then >*/
    if (*nsub > 200) {
/* SOURCE xsection.for:5779 */
/*<       write(stdout,50)pmxsub >*/
	feq_gen_io_d__657.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__657);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_200, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE xsection.for:5780 */
/*<       stop'Abnormal stop' >*/
	s_stop(const_cast<char*>("Abnormal stop"), (ftnlen)13);
/* SOURCE xsection.for:5781 */
/*<       endif >*/
    }
/*     Set the new minimum to the slot invert elevation. */
/* SOURCE xsection.for:5785 */
/*<       zmin=eslot >*/
    *zmin = abslot_1.eslot;
/*     clear the various flags for the variety of conditions that may */
/*     exist at each end of the slot insertion.  cls-- connecting line segment! */
/*     s - start, e - end */
/* SOURCE xsection.for:5790 */
/*<       s_slot_match='N' >*/
    *(unsigned char *)feq_gen_s_slot_match_d_ = 'N';
/* SOURCE xsection.for:5791 */
/*<       s_cls_match='N' >*/
    *(unsigned char *)feq_gen_s_cls_match_d_ = 'N';
/* SOURCE xsection.for:5792 */
/*<       s_cls_short='N' >*/
    *(unsigned char *)feq_gen_s_cls_short_d_ = 'N';
/* SOURCE xsection.for:5793 */
/*<       e_slot_match='N' >*/
    *(unsigned char *)feq_gen_e_slot_match_d_ = 'N';
/* SOURCE xsection.for:5794 */
/*<       e_cls_match='N' >*/
    *(unsigned char *)feq_gen_e_cls_match_d_ = 'N';
/* SOURCE xsection.for:5795 */
/*<       e_cls_short='N' >*/
    *(unsigned char *)feq_gen_e_cls_short_d_ = 'N';
/* SOURCE xsection.for:5797 */
/*<       if(bottom.gt.wslot)then >*/
    if (bottom > abslot_1.wslot) {
/*       If BOTTOM is > WSLOT put the slot at the midpoint of */
/*       of the bottom and then go to the next section to fit */
/*       the slot. */
/* SOURCE xsection.for:5802 */
/*<       xm=xm+0.5*bottom >*/
	xm += static_cast<double>(static_cast<double>(bottom) * (float).5);
/* SOURCE xsection.for:5804 */
/*<       endif >*/
    }
/*     The bottom is either not horizontal or horizontal and */
/*     too short to fit the slot requested.  We use a bit of */
/*     trial and error to fit the slot to the cross section. */
/*     Start by placing the slot centerline at the minimum */
/*     point.  Find the coordinates at the end points of the */
/*     left-hand line segment at the start of the slot. */
/* SOURCE xsection.for:5813 */
/*<       slot_xl=xm+slot_offset(1) >*/
    feq_gen_slot_xl_d_ = static_cast<double>(xm) + feq_gen_slot_offset_d_[0];
/* SOURCE xsection.for:5814 */
/*<       slot_zl=eslot+slot_y(1) >*/
    feq_gen_slot_zl_d_ = static_cast<double>(abslot_1.eslot) + feq_gen_slot_y_d_[0];
/* SOURCE xsection.for:5816 */
/*<       slot_xm=xm+slot_offset(2) >*/
    feq_gen_slot_xm_d_ = static_cast<double>(xm) + feq_gen_slot_offset_d_[1];
/* SOURCE xsection.for:5817 */
/*<       slot_zm=eslot+slot_y(2) >*/
    feq_gen_slot_zm_d_ = static_cast<double>(abslot_1.eslot) + feq_gen_slot_y_d_[1];
/* SOURCE xsection.for:5819 */
/*<       xslot=xm >*/
    xslot = xm;
/*     Seek an intersection of the slot boundary with the cross */
/*     section boundary on the left. */
/*      WRITE(STDOUT,*) ' CALLING FIND_CROSS 1' */
/* SOURCE xsection.for:5824 */
/*<        >*/
    feq_gen_find_cross_d_(stdout, npnt, &feq_gen_min_at_d_, &c_n1, &feq_gen_c_d_1, &x[1], &feq_gen_z_d_[1], &
	    feq_gen_slot_xm_d_, &feq_gen_slot_zm_d_, &feq_gen_slot_xl_d_, &feq_gen_slot_zl_d_, &itype, &ilcross, &
	    xl, &zl);
/* SOURCE xsection.for:5829 */
/*<       if(itype.gt.0)then >*/
    if (itype > 0) {
/*       WRITE(STDOUT,*) ' Left cross=',ILCROSS,' ITYPE=',ITYPE */
/*       Establish the various conditions at this intersection. */
/*       The line segment between  the leftmost point of the slot, */
/*       (slot_xl, slot_zl) and the point of intersection on the */
/*       cross-section boundary, (xl, zl) may be shorter than */
/*       we want to bother with.  Also the point of intersection may be */
/*       so close to an existing point on the boundary as may be the */
/*       leftmost point on the slot boundary. */
/*       Establish match status of the connecting line segment */
/*       with respect to points on the cross section boundary. */
/* SOURCE xsection.for:5841 */
/*<       if(abs(x(ilcross)-xl).le.eps)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(x[ilcross]) - xl, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:5842 */
/*<       i_s_cls_match=ilcross >*/
	    feq_gen_i_s_cls_match_d_ = ilcross;
/* SOURCE xsection.for:5843 */
/*<       s_cls_match='Y' >*/
	    *(unsigned char *)feq_gen_s_cls_match_d_ = 'Y';
/* SOURCE xsection.for:5844 */
/*<       elseif(abs(x(ilcross+1)-xl).le.eps)then >*/
	} else if ((feq_gen_r_d_1 = static_cast<double>(x[ilcross + 1]) - xl, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:5845 */
/*<       i_s_cls_match=ilcross+1 >*/
	    feq_gen_i_s_cls_match_d_ = ilcross + 1;
/* SOURCE xsection.for:5846 */
/*<       s_cls_match='Y' >*/
	    *(unsigned char *)feq_gen_s_cls_match_d_ = 'Y';
/* SOURCE xsection.for:5847 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:5848 */
/*<       s_cls_match='N' >*/
	    *(unsigned char *)feq_gen_s_cls_match_d_ = 'N';
/* SOURCE xsection.for:5849 */
/*<       i_s_cls_match=ilcross >*/
	    feq_gen_i_s_cls_match_d_ = ilcross;
/* SOURCE xsection.for:5850 */
/*<       endif >*/
	}
/*       find length of the connecting line segment. */
/* SOURCE xsection.for:5853 */
/*<       ls=sqrt((xl-slot_xl)**2+(zl-slot_zl)**2) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xl) - feq_gen_slot_xl_d_;
/* Computing 2nd power */
	feq_gen_r_d_2 = static_cast<double>(zl) - feq_gen_slot_zl_d_;
	ls = sqrt(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2);
/* SOURCE xsection.for:5854 */
/*<       if(ls.le.min_ls)then >*/
	if (ls <= feq_gen_min_ls_d_) {
/* SOURCE xsection.for:5855 */
/*<       s_cls_short='Y' >*/
	    *(unsigned char *)feq_gen_s_cls_short_d_ = 'Y';
/* SOURCE xsection.for:5856 */
/*<       endif >*/
	}
/*       Intersection found on the left.  Seek one on the right */
/*       with the slot centerline on the minimum point. */
/* SOURCE xsection.for:5861 */
/*<       slot_xr=xslot+slot_offset(np) >*/
	feq_gen_slot_xr_d_ = static_cast<double>(xslot) + feq_gen_slot_offset_d_[22];
/* SOURCE xsection.for:5862 */
/*<       slot_zr=slot_zl >*/
	feq_gen_slot_zr_d_ = feq_gen_slot_zl_d_;
/* SOURCE xsection.for:5863 */
/*<       slot_xm=xslot+slot_offset(np-1) >*/
	feq_gen_slot_xm_d_ = static_cast<double>(xslot) + feq_gen_slot_offset_d_[21];
/*        write(stdout,*) ' slot_xr=',slot_xr,' slot_xm=',slot_xm */
/* SOURCE xsection.for:5865 */
/*<        >*/
	feq_gen_find_cross_d_(stdout, npnt, &feq_gen_min_at_d_, &feq_gen_c_d_1, npnt, &x[1], &feq_gen_z_d_[1], &
		feq_gen_slot_xm_d_, &feq_gen_slot_zm_d_, &feq_gen_slot_xr_d_, &feq_gen_slot_zr_d_, &itype, &
		ircross, &xr, &zr);
/* SOURCE xsection.for:5869 */
/*<       if(itype.gt.0)then >*/
	if (itype > 0) {
/*         Establish conditions for the ending connecting line segment */
/* SOURCE xsection.for:5871 */
/*<       if(abs(x(ircross)-xr).le.eps)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(x[ircross]) - xr, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:5872 */
/*<       i_e_cls_match=ircross >*/
		feq_gen_i_e_cls_match_d_ = ircross;
/* SOURCE xsection.for:5873 */
/*<       e_cls_match='Y' >*/
		*(unsigned char *)feq_gen_e_cls_match_d_ = 'Y';
/* SOURCE xsection.for:5874 */
/*<       elseif(abs(x(ircross+1)-xr).le.eps)then >*/
	    } else if ((feq_gen_r_d_1 = static_cast<double>(x[ircross + 1]) - xr, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:5875 */
/*<       i_e_cls_match=ircross+1 >*/
		feq_gen_i_e_cls_match_d_ = ircross + 1;
/* SOURCE xsection.for:5876 */
/*<       e_cls_match='Y' >*/
		*(unsigned char *)feq_gen_e_cls_match_d_ = 'Y';
/* SOURCE xsection.for:5877 */
/*<       else >*/
	    } else {
/* SOURCE xsection.for:5878 */
/*<       e_cls_match='N' >*/
		*(unsigned char *)feq_gen_e_cls_match_d_ = 'N';
/* SOURCE xsection.for:5879 */
/*<       i_e_cls_match=ircross+1 >*/
		feq_gen_i_e_cls_match_d_ = ircross + 1;
/* SOURCE xsection.for:5880 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5881 */
/*<       ls=sqrt((xr-slot_xr)**2+(zr-slot_zr)**2) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(xr) - feq_gen_slot_xr_d_;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(zr) - feq_gen_slot_zr_d_;
	    ls = sqrt(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2);
/* SOURCE xsection.for:5882 */
/*<       if(ls.le.min_ls)then >*/
	    if (ls <= feq_gen_min_ls_d_) {
/* SOURCE xsection.for:5883 */
/*<       e_cls_short='Y' >*/
		*(unsigned char *)feq_gen_e_cls_short_d_ = 'Y';
/* SOURCE xsection.for:5884 */
/*<       endif >*/
	    }
/*         WRITE(STDOUT,*) */
/*     a    ' right cross after left found=',IRCROSS,' ITYPE=',ITYPE */
/* SOURCE xsection.for:5888 */
/*<       else >*/
	} else {
/*         No intersection on the right when there was one on */
/*         the left.  Move the the slot to the left so that */
/*         its right point matches the minimum and then */
/*         seek a new intersection on the left. */
/* SOURCE xsection.for:5894 */
/*<       xr=xm >*/
	    xr = xm;
/* SOURCE xsection.for:5895 */
/*<       zr=zm >*/
	    zr = zm;
/* SOURCE xsection.for:5896 */
/*<       ircross=min_at >*/
	    ircross = feq_gen_min_at_d_;
/* SOURCE xsection.for:5897 */
/*<       e_slot_match='Y' >*/
	    *(unsigned char *)feq_gen_e_slot_match_d_ = 'Y';
/* SOURCE xsection.for:5898 */
/*<       i_e_slot_match=ircross >*/
	    feq_gen_i_e_slot_match_d_ = ircross;
/* SOURCE xsection.for:5900 */
/*<       xslot=xm+slot_offset(1) >*/
	    xslot = static_cast<double>(xm) + feq_gen_slot_offset_d_[0];
/* SOURCE xsection.for:5902 */
/*<       slot_xl=xslot+slot_offset(1) >*/
	    feq_gen_slot_xl_d_ = static_cast<double>(xslot) + feq_gen_slot_offset_d_[0];
/* SOURCE xsection.for:5903 */
/*<       slot_xm=xslot+slot_offset(2) >*/
	    feq_gen_slot_xm_d_ = static_cast<double>(xslot) + feq_gen_slot_offset_d_[1];
/* SOURCE xsection.for:5906 */
/*<        >*/
	    feq_gen_find_cross_d_(stdout, npnt, &feq_gen_min_at_d_, &c_n1, &feq_gen_c_d_1, &x[1], &feq_gen_z_d_[1]
		    , &feq_gen_slot_xm_d_, &feq_gen_slot_zm_d_, &feq_gen_slot_xl_d_, &feq_gen_slot_zl_d_, &itype, 
		    &ilcross, &xl, &zl);
/* SOURCE xsection.for:5910 */
/*<       if(itype.gt.0)then >*/
	    if (itype > 0) {
/*           Establish conditions for the starting connecting line segment */
/* SOURCE xsection.for:5912 */
/*<       if(abs(x(ilcross)-xl).le.eps)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(x[ilcross]) - xl, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:5913 */
/*<       i_s_cls_match=ilcross >*/
		    feq_gen_i_s_cls_match_d_ = ilcross;
/* SOURCE xsection.for:5914 */
/*<       s_cls_match='Y' >*/
		    *(unsigned char *)feq_gen_s_cls_match_d_ = 'Y';
/* SOURCE xsection.for:5915 */
/*<       elseif(abs(x(ilcross+1)-xl).le.eps)then >*/
		} else if ((feq_gen_r_d_1 = static_cast<double>(x[ilcross + 1]) - xl, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:5916 */
/*<       i_s_cls_match=ilcross+1 >*/
		    feq_gen_i_s_cls_match_d_ = ilcross + 1;
/* SOURCE xsection.for:5917 */
/*<       s_cls_match='Y' >*/
		    *(unsigned char *)feq_gen_s_cls_match_d_ = 'Y';
/* SOURCE xsection.for:5918 */
/*<       else >*/
		} else {
/* SOURCE xsection.for:5919 */
/*<       s_cls_match='N' >*/
		    *(unsigned char *)feq_gen_s_cls_match_d_ = 'N';
/* SOURCE xsection.for:5920 */
/*<       i_s_cls_match=ilcross >*/
		    feq_gen_i_s_cls_match_d_ = ilcross;
/* SOURCE xsection.for:5921 */
/*<       endif >*/
		}
/*           find length of the connecting line segment. */
/* SOURCE xsection.for:5924 */
/*<       ls=sqrt((xl-slot_xl)**2+(zl-slot_zl)**2) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(xl) - feq_gen_slot_xl_d_;
/* Computing 2nd power */
		feq_gen_r_d_2 = static_cast<double>(zl) - feq_gen_slot_zl_d_;
		ls = sqrt(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2);
/* SOURCE xsection.for:5925 */
/*<       if(ls.le.min_ls)then >*/
		if (ls <= feq_gen_min_ls_d_) {
/* SOURCE xsection.for:5926 */
/*<       s_cls_short='Y' >*/
		    *(unsigned char *)feq_gen_s_cls_short_d_ = 'Y';
/* SOURCE xsection.for:5927 */
/*<       endif >*/
		}
/* SOURCE xsection.for:5928 */
/*<       else >*/
	    } else {
/* SOURCE xsection.for:5929 */
/*<        >*/
		feq_gen_io_d__681.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__681);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG: No intersection found on left"), (
			ftnlen)35);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" when one must exist."), (ftnlen)21);
		e_wsle();
/* SOURCE xsection.for:5931 */
/*<       stop' Abnormal stop' >*/
		s_stop(const_cast<char*>(" Abnormal stop"), (ftnlen)14);
/* SOURCE xsection.for:5932 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5934 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5935 */
/*<       else >*/
    } else {
/*       No intersection on the left.  Move slot to the right so that its */
/*       left point matches the minimum point and then seek */
/*       an intersection on the right. */
/* SOURCE xsection.for:5940 */
/*<       xl=xm >*/
	xl = xm;
/* SOURCE xsection.for:5941 */
/*<       zl=zm >*/
	zl = zm;
/* SOURCE xsection.for:5942 */
/*<       ilcross=min_at >*/
	ilcross = feq_gen_min_at_d_;
/* SOURCE xsection.for:5943 */
/*<       s_slot_match='Y' >*/
	*(unsigned char *)feq_gen_s_slot_match_d_ = 'Y';
/* SOURCE xsection.for:5944 */
/*<       i_s_slot_match=ilcross >*/
	feq_gen_i_s_slot_match_d_ = ilcross;
/* SOURCE xsection.for:5947 */
/*<       xslot=xm+slot_offset(np) >*/
	xslot = static_cast<double>(xm) + feq_gen_slot_offset_d_[22];
/* SOURCE xsection.for:5949 */
/*<       slot_xm=xslot+slot_offset(np-1) >*/
	feq_gen_slot_xm_d_ = static_cast<double>(xslot) + feq_gen_slot_offset_d_[21];
/* SOURCE xsection.for:5950 */
/*<       slot_xr=xslot+slot_offset(np) >*/
	feq_gen_slot_xr_d_ = static_cast<double>(xslot) + feq_gen_slot_offset_d_[22];
/* SOURCE xsection.for:5951 */
/*<       slot_zr=slot_zl >*/
	feq_gen_slot_zr_d_ = feq_gen_slot_zl_d_;
/* SOURCE xsection.for:5952 */
/*<        >*/
	feq_gen_find_cross_d_(stdout, npnt, &feq_gen_min_at_d_, &feq_gen_c_d_1, npnt, &x[1], &feq_gen_z_d_[1], &
		feq_gen_slot_xm_d_, &feq_gen_slot_zm_d_, &feq_gen_slot_xr_d_, &feq_gen_slot_zr_d_, &itype, &
		ircross, &xr, &zr);
/* SOURCE xsection.for:5956 */
/*<       if(itype.gt.0)then >*/
	if (itype > 0) {
/*         Establish conditions for the ending connecting line segment */
/* SOURCE xsection.for:5958 */
/*<       if(abs(x(ircross)-xr).le.eps)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(x[ircross]) - xr, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:5959 */
/*<       i_e_cls_match=ircross >*/
		feq_gen_i_e_cls_match_d_ = ircross;
/* SOURCE xsection.for:5960 */
/*<       e_cls_match='Y' >*/
		*(unsigned char *)feq_gen_e_cls_match_d_ = 'Y';
/* SOURCE xsection.for:5961 */
/*<       elseif(abs(x(ircross+1)-xr).le.eps)then >*/
	    } else if ((feq_gen_r_d_1 = static_cast<double>(x[ircross + 1]) - xr, dabs(feq_gen_r_d_1)) <= eps) {
/* SOURCE xsection.for:5962 */
/*<       i_e_cls_match=ircross+1 >*/
		feq_gen_i_e_cls_match_d_ = ircross + 1;
/* SOURCE xsection.for:5963 */
/*<       e_cls_match='Y' >*/
		*(unsigned char *)feq_gen_e_cls_match_d_ = 'Y';
/* SOURCE xsection.for:5964 */
/*<       else >*/
	    } else {
/* SOURCE xsection.for:5965 */
/*<       e_cls_match='N' >*/
		*(unsigned char *)feq_gen_e_cls_match_d_ = 'N';
/* SOURCE xsection.for:5966 */
/*<       i_e_cls_match=ircross+1 >*/
		feq_gen_i_e_cls_match_d_ = ircross + 1;
/* SOURCE xsection.for:5967 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5968 */
/*<       ls=sqrt((xr-slot_xr)**2+(zr-slot_zr)**2) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(xr) - feq_gen_slot_xr_d_;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(zr) - feq_gen_slot_zr_d_;
	    ls = sqrt(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2);
/* SOURCE xsection.for:5969 */
/*<       if(ls.le.min_ls)then >*/
	    if (ls <= feq_gen_min_ls_d_) {
/* SOURCE xsection.for:5970 */
/*<       e_cls_short='Y' >*/
		*(unsigned char *)feq_gen_e_cls_short_d_ = 'Y';
/* SOURCE xsection.for:5971 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:5972 */
/*<       else >*/
	} else {
/* SOURCE xsection.for:5973 */
/*<        >*/
	    feq_gen_io_d__683.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__683);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BUG: No intersection found on right"), (
		    ftnlen)36);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" when one must exist."), (ftnlen)21);
	    e_wsle();
/* SOURCE xsection.for:5975 */
/*<       stop' Abnormal stop' >*/
	    s_stop(const_cast<char*>(" Abnormal stop"), (ftnlen)14);
/* SOURCE xsection.for:5976 */
/*<       endif >*/
	}
/* SOURCE xsection.for:5978 */
/*<       endif >*/
    }
/*     Now setup the various values we need to make room for the slot and to */
/*     insert the slot properly. */
/*     i_xs_left - index to the last retained point on cross section boundary to the left */
/*                 of the slot */
/*     i_xs_right - index to the first retained point on the cross-section boundary to the right */
/*                  slot. */
/*      both of above refer to the indices as they exist at this point.  Adjustments may have been */
/*      made to make better sense of a horizontal bottom. */
/*     i_start_slot - starting index for the points in the slot to transfer */
/*     i_end_slot - ending index for the points in the slot to transfer */
/*     n_cross - number of intersection points to be added.  can be 0, 1, or 2 */
/* SOURCE xsection.for:5997 */
/*<       retain_sb='N' >*/
    *(unsigned char *)feq_gen_retain_sb_d_ = 'N';
/* SOURCE xsection.for:5998 */
/*<       change_sb='N' >*/
    *(unsigned char *)feq_gen_change_sb_d_ = 'N';
/* SOURCE xsection.for:5999 */
/*<       remember_sb='N' >*/
    *(unsigned char *)feq_gen_remember_sb_d_ = 'N';
/* SOURCE xsection.for:6001 */
/*<       n_cross=0 >*/
    feq_gen_n_cross_d_ = 0;
/* SOURCE xsection.for:6002 */
/*<       if(s_slot_match.eq.'Y')then >*/
    if (*(unsigned char *)feq_gen_s_slot_match_d_ == 'Y') {
/*       The start point of the slot matches a boundary point exactly. */
/* SOURCE xsection.for:6004 */
/*<       i_xs_left=i_s_slot_match >*/
	feq_gen_i_xs_left_d_ = feq_gen_i_s_slot_match_d_;
/*       sb and lsn must be changed to slot values at i_xs_left */
/* SOURCE xsection.for:6007 */
/*<       change_sb='Y' >*/
	*(unsigned char *)feq_gen_change_sb_d_ = 'Y';
/*       intersection point is not used */
/* SOURCE xsection.for:6010 */
/*<       xl=-1.e30 >*/
	xl = (float)-1e30;
/*       skip first point on slot because it is already on the boundary */
/* SOURCE xsection.for:6013 */
/*<       i_start_slot=2 >*/
	feq_gen_i_start_slot_d_ = 2;
/* SOURCE xsection.for:6015 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:6016 */
/*<       if(s_cls_match.eq.'Y')then >*/
	if (*(unsigned char *)feq_gen_s_cls_match_d_ == 'Y') {
/*         starting connecting line segment matches a boundary point. */
/* SOURCE xsection.for:6018 */
/*<       if(s_cls_short.eq.'N')then >*/
	    if (*(unsigned char *)feq_gen_s_cls_short_d_ == 'N') {
/*           starting connecting line segment has ok length */
/* SOURCE xsection.for:6020 */
/*<       i_xs_left=i_s_cls_match >*/
		feq_gen_i_xs_left_d_ = feq_gen_i_s_cls_match_d_;
/*           sb and lsn must be changed to the slot value at i_xs_left */
/* SOURCE xsection.for:6023 */
/*<       change_sb='Y' >*/
		*(unsigned char *)feq_gen_change_sb_d_ = 'Y';
/*           intersection point is not used */
/* SOURCE xsection.for:6026 */
/*<       xl=-1.e30 >*/
		xl = (float)-1e30;
/* SOURCE xsection.for:6028 */
/*<       i_start_slot=1 >*/
		feq_gen_i_start_slot_d_ = 1;
/* SOURCE xsection.for:6029 */
/*<       else >*/
	    } else {
/*           starting connecting line segment is too short.  last retained point shifts 1 to left */
/* SOURCE xsection.for:6031 */
/*<       i_xs_left=i_s_cls_match-1 >*/
		feq_gen_i_xs_left_d_ = feq_gen_i_s_cls_match_d_ - 1;
/*           sb and lsn are to be unchanged at i_xs_left */
/* SOURCE xsection.for:6034 */
/*<       change_sb='N' >*/
		*(unsigned char *)feq_gen_change_sb_d_ = 'N';
/* SOURCE xsection.for:6036 */
/*<       xl=-1.e30 >*/
		xl = (float)-1e30;
/* SOURCE xsection.for:6037 */
/*<       i_start_slot=1 >*/
		feq_gen_i_start_slot_d_ = 1;
/* SOURCE xsection.for:6038 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:6039 */
/*<       else >*/
	} else {
/*         Starting connection line segment does not match a boundary point. */
/* SOURCE xsection.for:6041 */
/*<       if(s_cls_short.eq.'N')then >*/
	    if (*(unsigned char *)feq_gen_s_cls_short_d_ == 'N') {
/*           Starting connecting line segment has ok length */
/* SOURCE xsection.for:6043 */
/*<       i_xs_left=i_s_cls_match >*/
		feq_gen_i_xs_left_d_ = feq_gen_i_s_cls_match_d_;
/*           sb and lsn are not changed */
/* SOURCE xsection.for:6046 */
/*<       change_sb='N' >*/
		*(unsigned char *)feq_gen_change_sb_d_ = 'N';
/*           intersection point is used.  Gets slot n. */
/* SOURCE xsection.for:6049 */
/*<       n_cross=n_cross+1 >*/
		++feq_gen_n_cross_d_;
/* SOURCE xsection.for:6051 */
/*<       i_start_slot=1 >*/
		feq_gen_i_start_slot_d_ = 1;
/* SOURCE xsection.for:6052 */
/*<       else >*/
	    } else {
/*           Starting connecting line segment is too short */
/* SOURCE xsection.for:6054 */
/*<       i_xs_left=i_s_cls_match >*/
		feq_gen_i_xs_left_d_ = feq_gen_i_s_cls_match_d_;
/*           sb and lsn are not changed */
/* SOURCE xsection.for:6057 */
/*<       change_sb='N' >*/
		*(unsigned char *)feq_gen_change_sb_d_ = 'N';
/*           intersection point is not used. */
/* SOURCE xsection.for:6060 */
/*<       xl=-1.e30 >*/
		xl = (float)-1e30;
/* SOURCE xsection.for:6062 */
/*<       i_start_slot=1 >*/
		feq_gen_i_start_slot_d_ = 1;
/* SOURCE xsection.for:6063 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:6064 */
/*<       endif >*/
	}
/* SOURCE xsection.for:6065 */
/*<       endif >*/
    }
/* SOURCE xsection.for:6067 */
/*<       if(e_slot_match.eq.'Y')then >*/
    if (*(unsigned char *)feq_gen_e_slot_match_d_ == 'Y') {
/*       The end point of the slot matches a boundary point exactly. */
/* SOURCE xsection.for:6069 */
/*<       i_xs_right=i_e_slot_match >*/
	feq_gen_i_xs_right_d_ = feq_gen_i_e_slot_match_d_;
/*       sb and lsn must be retained  at i_xs_right */
/* SOURCE xsection.for:6072 */
/*<       retain_sb='Y' >*/
	*(unsigned char *)feq_gen_retain_sb_d_ = 'Y';
/*       intersection point is not used */
/* SOURCE xsection.for:6075 */
/*<       xr=1.e30 >*/
	xr = (float)1e30;
/*       skip last point on slot because it is already on the boundary */
/* SOURCE xsection.for:6078 */
/*<       i_end_slot=np-1 >*/
	feq_gen_i_end_slot_d_ = 22;
/* SOURCE xsection.for:6080 */
/*<       else >*/
    } else {
/* SOURCE xsection.for:6081 */
/*<       if(e_cls_match.eq.'Y')then >*/
	if (*(unsigned char *)feq_gen_e_cls_match_d_ == 'Y') {
/*         ending connecting line segment matches a boundary point. */
/* SOURCE xsection.for:6083 */
/*<       if(e_cls_short.eq.'N')then >*/
	    if (*(unsigned char *)feq_gen_e_cls_short_d_ == 'N') {
/*           ending connecting line segment has ok length */
/* SOURCE xsection.for:6085 */
/*<       i_xs_right=i_e_cls_match >*/
		feq_gen_i_xs_right_d_ = feq_gen_i_e_cls_match_d_;
/*           sb and lsn must be retained at i_xs_right */
/* SOURCE xsection.for:6088 */
/*<       retain_sb='Y' >*/
		*(unsigned char *)feq_gen_retain_sb_d_ = 'Y';
/*           intersection point is not used */
/* SOURCE xsection.for:6091 */
/*<       xr=1.e30 >*/
		xr = (float)1e30;
/* SOURCE xsection.for:6093 */
/*<       i_end_slot=np >*/
		feq_gen_i_end_slot_d_ = 23;
/* SOURCE xsection.for:6094 */
/*<       else >*/
	    } else {
/*           ending connecting line segment is too short.   retained point shifts 1 to right */
/* SOURCE xsection.for:6096 */
/*<       i_xs_right=i_e_cls_match+1 >*/
		feq_gen_i_xs_right_d_ = feq_gen_i_e_cls_match_d_ + 1;
/*           remember sb and lsn  at i_xs_right - 1 */
/* SOURCE xsection.for:6099 */
/*<       remember_sb='Y' >*/
		*(unsigned char *)feq_gen_remember_sb_d_ = 'Y';
/* SOURCE xsection.for:6101 */
/*<       xr=1.e30 >*/
		xr = (float)1e30;
/* SOURCE xsection.for:6102 */
/*<       i_end_slot=np >*/
		feq_gen_i_end_slot_d_ = 23;
/* SOURCE xsection.for:6103 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:6104 */
/*<       else >*/
	} else {
/*         ending connection line segment does not match a boundary point. */
/* SOURCE xsection.for:6106 */
/*<       if(e_cls_short.eq.'N')then >*/
	    if (*(unsigned char *)feq_gen_e_cls_short_d_ == 'N') {
/*           ending connecting line segment has ok length */
/* SOURCE xsection.for:6108 */
/*<       i_xs_right=i_e_cls_match >*/
		feq_gen_i_xs_right_d_ = feq_gen_i_e_cls_match_d_;
/*           remember sb and lsn at i_xs_right - 1 */
/* SOURCE xsection.for:6111 */
/*<       remember_sb='Y' >*/
		*(unsigned char *)feq_gen_remember_sb_d_ = 'Y';
/*           intersection point is used. */
/* SOURCE xsection.for:6114 */
/*<       n_cross=n_cross+1 >*/
		++feq_gen_n_cross_d_;
/* SOURCE xsection.for:6116 */
/*<       i_end_slot=np >*/
		feq_gen_i_end_slot_d_ = 23;
/* SOURCE xsection.for:6117 */
/*<       else >*/
	    } else {
/*           ending connecting line segment is too short */
/* SOURCE xsection.for:6119 */
/*<       i_xs_right=i_e_cls_match >*/
		feq_gen_i_xs_right_d_ = feq_gen_i_e_cls_match_d_;
/*           remember sb and lsn at i_xs_right - 1 */
/* SOURCE xsection.for:6122 */
/*<       remember_sb='Y' >*/
		*(unsigned char *)feq_gen_remember_sb_d_ = 'Y';
/*           intersection point is not used. */
/* SOURCE xsection.for:6125 */
/*<       xr=1.e30 >*/
		xr = (float)1e30;
/* SOURCE xsection.for:6127 */
/*<       i_end_slot=np >*/
		feq_gen_i_end_slot_d_ = 23;
/* SOURCE xsection.for:6128 */
/*<       endif >*/
	    }
/* SOURCE xsection.for:6129 */
/*<       endif >*/
	}
/* SOURCE xsection.for:6130 */
/*<       endif >*/
    }
/*     Select the manning's n for the slot: */
/*     nslot > 0.0 -- use nslot for manning's n in the slot */
/*     nslot = 0  -- use the mean value of the existing n at the */
/*                   start and end points. */
/*     nslot < 0.0 -- use the mean value of the existing n at the */
/*                    start and end point multiplied by abs(nslot). */
/* SOURCE xsection.for:6142 */
/*<       if(nslot.gt.0.0)then >*/
    if (abslot_1.nslot > (float)0.) {
/* SOURCE xsection.for:6143 */
/*<       n(nsub)=nslot >*/
	n[*nsub] = abslot_1.nslot;
/* SOURCE xsection.for:6144 */
/*<       else >*/
    } else {
/*       compute perimeter-weighted n in the vicinity of the slot */
/* SOURCE xsection.for:6146 */
/*<       sum_ls=0.0 >*/
	feq_gen_sum_ls_d_ = (float)0.;
/* SOURCE xsection.for:6147 */
/*<       sum_nls=0.0 >*/
	feq_gen_sum_nls_d_ = (float)0.;
/* SOURCE xsection.for:6148 */
/*<       if(i_xs_right-1.lt.i_xs_left)then >*/
	if (feq_gen_i_xs_right_d_ - 1 < feq_gen_i_xs_left_d_) {
/* SOURCE xsection.for:6149 */
/*<       write(stdout,*)' problem in computing aver n in add_slote' >*/
	    feq_gen_io_d__694.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__694);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" problem in computing aver n in add_slote"), 
		    (ftnlen)41);
	    e_wsle();
/* SOURCE xsection.for:6150 */
/*<       write(stdout,*)' i_xs_left=',i_xs_left,' i_xs_right=',i_xs_right >*/
	    feq_gen_io_d__695.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__695);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" i_xs_left="), (ftnlen)11);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_xs_left_d_, (ftnlen)sizeof(integer)
		    );
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" i_xs_right="), (ftnlen)12);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_xs_right_d_, (ftnlen)sizeof(
		    integer));
	    e_wsle();
/* SOURCE xsection.for:6152 */
/*<       stop'Abnormal stop.  Bug!' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Bug!"), (ftnlen)20);
/* SOURCE xsection.for:6153 */
/*<       endif >*/
	}
/* SOURCE xsection.for:6154 */
/*<       doi=i_xs_left,i_xs_right-1 >*/
	feq_gen_i_d_1 = feq_gen_i_xs_right_d_ - 1;
	for (feq_gen_i_d_ = feq_gen_i_xs_left_d_; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:6155 */
/*<       ls=sqrt((x(i+1)-x(i))**2+(z(i+1)-z(i))**2) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(x[feq_gen_i_d_ + 1]) - x[feq_gen_i_d_];
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(feq_gen_z_d_[feq_gen_i_d_ + 1]) - feq_gen_z_d_[feq_gen_i_d_];
	    ls = sqrt(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) + static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2);
/* SOURCE xsection.for:6156 */
/*<       sum_ls=sum_ls+ls >*/
	    feq_gen_sum_ls_d_ += ls;
/* SOURCE xsection.for:6157 */
/*<       sum_nls=sum_nls+ls*n(sb(i)) >*/
	    feq_gen_sum_nls_d_ += static_cast<double>(static_cast<double>(ls) * n[sb[feq_gen_i_d_]]);
/* SOURCE xsection.for:6158 */
/*<       enddo >*/
	}
/* SOURCE xsection.for:6159 */
/*<       n(nsub)=sum_nls/sum_ls >*/
	n[*nsub] = static_cast<double>(feq_gen_sum_nls_d_) / feq_gen_sum_ls_d_;
/* SOURCE xsection.for:6160 */
/*<       if(nslot.lt.0.0)then >*/
	if (abslot_1.nslot < (float)0.) {
/* SOURCE xsection.for:6161 */
/*<       n(nsub)=n(nsub)*abs(nslot) >*/
	    n[*nsub] *= dabs(abslot_1.nslot);
/* SOURCE xsection.for:6162 */
/*<       endif >*/
	}
/* SOURCE xsection.for:6163 */
/*<       endif >*/
    }
/* SOURCE xsection.for:6166 */
/*<        >*/
    feq_gen_io_d__696.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__696);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_xs_left_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_xs_right_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_start_slot_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_end_slot_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_n_cross_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE xsection.for:6168 */
/*<   145  >*/
/* SOURCE xsection.for:6170 */
/*<       write(stdout,146)xl,xr >*/
    feq_gen_io_d__697.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__697);
    do_fio(&feq_gen_c_d_1, (char *)&xl, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&xr, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE xsection.for:6171 */
/*<   146 format(' xl=',1pe12.4,' xr=',1pe12.4) >*/
/*     Compute the space needed for the points to be added to the boundary. */
/*     we will be adding  (i_end_slot - i_start_slot + 1) + n_cross points */
/*     to the boundary.  We have to the contents of x(*), etc. with */
/*     iold being i_xs_right.  This point will be the first one to the right */
/*     slot that is kept.  We make enough room to place the additional points */
/*     starting at  the location after i_xs_left.  It should always be true that */
/*     i_xs_right is larger than i_xs_left. */
/* SOURCE xsection.for:6181 */
/*<       if(i_xs_right.le.i_xs_left)then >*/
    if (feq_gen_i_xs_right_d_ <= feq_gen_i_xs_left_d_) {
/* SOURCE xsection.for:6182 */
/*<        >*/
	feq_gen_io_d__698.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__698);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" i_xs_right="), (ftnlen)12);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_xs_right_d_, (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" <="), (ftnlen)3);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" i_xs_left="), (ftnlen)11);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_xs_left_d_, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE xsection.for:6184 */
/*<       stop'Abnormal stop.  Bug.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Bug."), (ftnlen)20);
/* SOURCE xsection.for:6185 */
/*<       endif >*/
    }
/*     Remember the sb on the right in certain cases. */
/* SOURCE xsection.for:6189 */
/*<       if(remember_sb.eq.'Y')then >*/
    if (*(unsigned char *)feq_gen_remember_sb_d_ == 'Y') {
/* SOURCE xsection.for:6190 */
/*<       remember_sub=sb(i_xs_right-1) >*/
	feq_gen_remember_sub_d_ = sb[feq_gen_i_xs_right_d_ - 1];
/* SOURCE xsection.for:6191 */
/*<       endif >*/
    }
/*     Retain sub in certain cases */
/* SOURCE xsection.for:6194 */
/*<       if(retain_sb.eq.'Y')then >*/
    if (*(unsigned char *)feq_gen_retain_sb_d_ == 'Y') {
/* SOURCE xsection.for:6195 */
/*<       retain_sub=sb(i_xs_right) >*/
	feq_gen_retain_sub_d_ = sb[feq_gen_i_xs_right_d_];
/* SOURCE xsection.for:6196 */
/*<       endif >*/
    }
/*     We know that iold must be i_xs_right.  We will add some points and */
/*     in some cases points will be deleted.  Thus */
/*     inew = i_xs_right + */
/*             number of points added                    -     number of points deleted */
/* SOURCE xsection.for:6203 */
/*<        >*/
    inew = feq_gen_i_xs_right_d_ + (feq_gen_i_end_slot_d_ - feq_gen_i_start_slot_d_ + 1) + feq_gen_n_cross_d_ - (
	    feq_gen_i_xs_right_d_ - feq_gen_i_xs_left_d_ - 1);
/* SOURCE xsection.for:6206 */
/*<       iold=i_xs_right >*/
    iold = feq_gen_i_xs_right_d_;
/* SOURCE xsection.for:6207 */
/*<       callshift_values(stdout,iold,inew,npnt,x,z,sb,lsn,sn) >*/
    feq_gen_shift_values_d_(stdout, &iold, &inew, npnt, &x[1], &feq_gen_z_d_[1], &sb[1], &lsn[1]
	    , &sn[1]);
/* SOURCE xsection.for:6211 */
/*<       if(change_sb.eq.'Y')then >*/
    if (*(unsigned char *)feq_gen_change_sb_d_ == 'Y') {
/* SOURCE xsection.for:6212 */
/*<       sb(i_xs_left)=nsub >*/
	sb[feq_gen_i_xs_left_d_] = *nsub;
/* SOURCE xsection.for:6213 */
/*<       lsn(i_xs_left)=n(nsub) >*/
	lsn[feq_gen_i_xs_left_d_] = n[*nsub];
/* SOURCE xsection.for:6214 */
/*<       endif >*/
    }
/* SOURCE xsection.for:6215 */
/*<       is=i_xs_left+1 >*/
    is = feq_gen_i_xs_left_d_ + 1;
/* SOURCE xsection.for:6216 */
/*<       if(xl.gt.-1.e29)then >*/
    if (xl > (float)-1e29) {
/*       We use the left intersection point. It gets the slot n values */
/* SOURCE xsection.for:6218 */
/*<       x(is)=xl >*/
	x[is] = xl;
/* SOURCE xsection.for:6219 */
/*<       z(is)=zl >*/
	feq_gen_z_d_[is] = zl;
/* SOURCE xsection.for:6220 */
/*<       sn(is)=1.0 >*/
	sn[is] = (float)1.;
/* SOURCE xsection.for:6221 */
/*<       sb(is)=nsub >*/
	sb[is] = *nsub;
/* SOURCE xsection.for:6222 */
/*<       lsn(is)=n(nsub) >*/
	lsn[is] = n[*nsub];
/* SOURCE xsection.for:6223 */
/*<       is=is+1 >*/
	++is;
/* SOURCE xsection.for:6224 */
/*<       endif >*/
    }
/*     transfer the points on the slot boundary */
/* SOURCE xsection.for:6227 */
/*<       doi=i_start_slot,i_end_slot >*/
    feq_gen_i_d_1 = feq_gen_i_end_slot_d_;
    for (feq_gen_i_d_ = feq_gen_i_start_slot_d_; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE xsection.for:6228 */
/*<       x(is+i-i_start_slot)=slot_offset(i)+xslot >*/
	x[is + feq_gen_i_d_ - feq_gen_i_start_slot_d_] = static_cast<double>(feq_gen_slot_offset_d_[feq_gen_i_d_ - 1]) + xslot;
/* SOURCE xsection.for:6229 */
/*<       z(is+i-i_start_slot)=slot_y(i)+eslot >*/
	feq_gen_z_d_[is + feq_gen_i_d_ - feq_gen_i_start_slot_d_] = static_cast<double>(feq_gen_slot_y_d_[feq_gen_i_d_ - 1]) + abslot_1.eslot;
/* SOURCE xsection.for:6230 */
/*<       sn(is+i-i_start_slot)=1.0 >*/
	sn[is + feq_gen_i_d_ - feq_gen_i_start_slot_d_] = (float)1.;
/* SOURCE xsection.for:6231 */
/*<       sb(is+i-i_start_slot)=nsub >*/
	sb[is + feq_gen_i_d_ - feq_gen_i_start_slot_d_] = *nsub;
/* SOURCE xsection.for:6232 */
/*<       lsn(is+i-i_start_slot)=n(nsub) >*/
	lsn[is + feq_gen_i_d_ - feq_gen_i_start_slot_d_] = n[*nsub];
/* SOURCE xsection.for:6233 */
/*<       enddo >*/
    }
/*     compute index to the last slot point transfered */
/* SOURCE xsection.for:6235 */
/*<       is=is+i_end_slot-i_start_slot >*/
    is = is + feq_gen_i_end_slot_d_ - feq_gen_i_start_slot_d_;
/*     If the intersection point is used it gets the remembered subsection. */
/*     if the intersection point is not used any rememberd subsection is assigned */
/*     to the last point on the slot.   Retained subsection values are supossed */
/*     to happen without additional action!! */
/* SOURCE xsection.for:6241 */
/*<       if(remember_sb.eq.'Y')then >*/
    if (*(unsigned char *)feq_gen_remember_sb_d_ == 'Y') {
/* SOURCE xsection.for:6242 */
/*<       if(xr.gt.1.e29)then >*/
	if (xr > (float)1e29) {
/*         intersection point is not used */
/* SOURCE xsection.for:6244 */
/*<       sb(is)=remember_sub >*/
	    sb[is] = feq_gen_remember_sub_d_;
/* SOURCE xsection.for:6245 */
/*<       lsn(is)=n(sb(is)) >*/
	    lsn[is] = n[sb[is]];
/* SOURCE xsection.for:6246 */
/*<       endif >*/
	}
/* SOURCE xsection.for:6247 */
/*<       endif >*/
    }
/* SOURCE xsection.for:6249 */
/*<       if(xr.lt.1.e30)then >*/
    if (xr < (float)1e30) {
/*       add the intersection point.  Always gets the remembered subsection */
/* SOURCE xsection.for:6251 */
/*<       is=is+1 >*/
	++is;
/* SOURCE xsection.for:6252 */
/*<       x(is)=xr >*/
	x[is] = xr;
/* SOURCE xsection.for:6253 */
/*<       z(is)=zr >*/
	feq_gen_z_d_[is] = zr;
/* SOURCE xsection.for:6254 */
/*<       sn(is)=1.0 >*/
	sn[is] = (float)1.;
/* SOURCE xsection.for:6255 */
/*<       sb(is)=remember_sub >*/
	sb[is] = feq_gen_remember_sub_d_;
/* SOURCE xsection.for:6256 */
/*<       lsn(is)=n(sb(is)) >*/
	lsn[is] = n[sb[is]];
/* SOURCE xsection.for:6257 */
/*<       endif >*/
    }
/* SOURCE xsection.for:6259 */
/*<       if(is+1.ne.inew)then >*/
    if (is + 1 != inew) {
/* SOURCE xsection.for:6260 */
/*<        >*/
	feq_gen_io_d__704.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__704);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Wrong count during transfer. is+1="), (ftnlen)
		35);
	feq_gen_i_d_1 = is + 1;
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" inew="), (ftnlen)6);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&inew, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE xsection.for:6262 */
/*<       stop'Abnormal stop. Bug.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Bug."), (ftnlen)19);
/* SOURCE xsection.for:6263 */
/*<       endif >*/
    }
/*     Adjust the subsection assignments */
/* SOURCE xsection.for:6268 */
/*<       callreasub(stdout,npnt,nsub,n,sb,eflag) >*/
    reasub_(stdout, npnt, nsub, &n[1], &sb[1], &eflag);
/* SOURCE xsection.for:6273 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:6274 */
/*<       end >*/
} /* add_slote__ */




/* SOURCE xsection.for:6279 */
/*<       subroutinereplace_eslot_elements(stdout,tab,ndep,xst) >*/
/* Subroutine */ int feq_gen_replace_eslot_elements_d_(integer *stdout, integer *tab, 
	integer *ndep, real *feq_storage_xst)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Table id: \002,a,\002 with slot depth\
=\002,f10.3,\002 has its\002,\002 values of alpha,\002,/,\002      beta, ma,\
 and mq\002,\002 reset to match those in the unsloted table given in FTABIN\
.\002)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1[2], feq_gen_i_d_2;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen), s_cat(char *, char **, 
	    integer *, integer *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real b;
    integer feq_gen_i_d_;
    real j, k;
    extern /* Subroutine */ int feq_gen_find_internal_tab_number_d_(char *, integer *, 
	    ftnlen);
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real db, ma, dk, qc, dt, mq, dma, alp, dmq, top;
    integer taba;
    real area;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real dalp, yarg;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer eflag;
    char tabid[16];
    integer adrsa;
    extern /* Subroutine */ int xlkt25_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    real yzero;
    char tabida[16];
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__712 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__716 = { 0, 0, 0, fmt_50, 0 };


/*     If the cross-section table with internal number, tab, has an */
/*     exponential slot, then seek a stored cross section table with the */
/*     a tabid that matches the one for tab but with a trailing lower case */
/*     a appended.  If no such table is available, return without doing */
/*     anything.  Otherwise, */
/*     1. Replace all values of alpha, beta, ma, and mq in the table */
/*        tab, at an above the true invert by looking up values in */
/*        the stored cross-section function table. */
/*     2. Change all values of these elements in the slot to match the */
/*        value at that top of the slot. */
/*        Write a message to the master output file noting that this */
/*        operation has been done.  This operation will produce inconsistent */
/*        values in the display for the critical flow computations.   However, the */
/*        critical flow values will be left unchanged. */
/* SOURCE xsection.for:6300 */
/*<       implicitnone >*/
/* INCLUDE xsection.for:6302 */
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
/* INCLUDE xsection.for:6303 */
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
/* INCLUDE xsection.for:6304 */
/*     Values used to keep track of a bottom slot in a cross section. */
/* SOURCE abslot.cmn:3 */
/*<       integerslot_present >*/
/* SOURCE abslot.cmn:5 */
/*<       realnslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:7 */
/*<       common/abslot/slot_present,nslot,wslot,eslot,yslot,rd,tzero,expfac >*/
/* SOURCE abslot.cmn:10 */
/*<       save/abslot/ >*/
/*     SLOT_PRESENT: 0 no slot. 1 triangular slot, 2 exponential slot */
/*     NSLOT:  Manning's n for the slot if nslot > 0.  If nslot < 0.0 */
/*             use the average of the Manning's n's at the edges of the slot */
/*             and multiply by abs(nslot).  E. g. -1.2 computes the average value */
/*             of manning's n from the two bounding values in the cross section */
/*             and multiplies this averge by 1.2 to get the manning's n for the slot */
/*     WSLOT: width of the slot at the invert elevation of the cross section for a triangular */
/*            slot.  For the default exponential slot, it also gives the width of the slot */
/*            at the section invert.  If non-default values of rd are used, then the */
/*            meaning may differ. */
/*     ESLOT: elevation of the invert of the slot. */
/*     YSLOT: distance from slot invert to the cross section invert. */
/*     RD - factor on yslot to compute the y0 value for the exponential slot. */
/*          default value= 0.379376194959581.  This value together with the default */
/*          value of tzero has some convenient properties. */
/*     TZERO - width of the triangular section that forms the bottom portion of the */
/*             exponential slot.  Default value = 0.1*rd*wslot.  This default gives */
/*             an exponential slot with a width at the top of WSLOT.   A value of */
/*             wslot = 1/rd gives an area equal to the triangular slot with a */
/*             top width of 1.0. */
/*     EXPFAC - factor on the exponent in the exponential channel. Default value=1.0 */
/*              expfac > 1 gives a top-width increase larger than the default. */

/*     Only one of ESLOT or YSLOT is used.  YSLOT is the better choice for consistent */
/*     interpolation between sections. */
/* SOURCE xsection.for:6306 */
/*<       integerstdout,tab,ndep >*/
/* SOURCE xsection.for:6308 */
/*<       realxst(pmxpnt,pmxelm) >*/
/*     Called routines */
/* SOURCE xsection.for:6312 */
/*<       character*16get_tabid >*/
/* SOURCE xsection.for:6313 */
/*<       externalget_tabid,find_internal_tab_number,xlkt25,chktab >*/
/*     Local */
/* SOURCE xsection.for:6317 */
/*<       integereflag,i,taba,adrsa >*/
/* SOURCE xsection.for:6319 */
/*<       realyzero,area,top,dt,j,k,dk,b,db,alp,dalp,qc,ma,dma,mq,dmq,yarg >*/
/* SOURCE xsection.for:6322 */
/*<       charactertabid*16,tabida*16 >*/
/*     *********************************formatss************************* */
/* SOURCE xsection.for:6279 */
/*<       integer feq_len_trim >*/
/* SOURCE xsection.for:6279 */
/*<       external feq_len_trim >*/
/* SOURCE xsection.for:6324 */
/*<    50  >*/
/* *********************************************************************** */
/*     Check on slot type. */
/* SOURCE xsection.for:6329 */
/*<       if(slot_present.ne.2)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> xst(feq_storage_xst, 1000);

    /* Function Body */
/* L50: */
    if (abslot_1.feq_gen_slot_present_d_ != 2) {
/* SOURCE xsection.for:6330 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:6331 */
/*<       endif >*/
    }
/*     Construct the name of the table that might have been stored. */
/*     Get the tabid of the current table, then append a to it, and see */
/*     if it exists. */
/* SOURCE xsection.for:6335 */
/*<       eflag=0 >*/
    eflag = 0;
/* SOURCE xsection.for:6336 */
/*<       tabid=get_tabid(tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, tab);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE xsection.for:6337 */
/*<       i=feq_len_trim(tabid) >*/
    feq_gen_i_d_ = feq_gen_feq_len_trim_d_(tabid, (ftnlen)16);
/* SOURCE xsection.for:6338 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE xsection.for:6339 */
/*<       write(stdout,*)' Bug: tabid not found for table being processd' >*/
	feq_gen_io_d__712.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__712);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Bug: tabid not found for table being processd"),
		 (ftnlen)46);
	e_wsle();
/* SOURCE xsection.for:6340 */
/*<       stop'Abnormal stop. Bug.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Bug."), (ftnlen)19);
/* SOURCE xsection.for:6341 */
/*<       endif >*/
    }
/* SOURCE xsection.for:6343 */
/*<       tabida=tabid(1:i)//'a' >*/
/* Writing concatenation */
    feq_gen_i_d_1[0] = feq_gen_i_d_, feq_gen_a_d_1[0] = tabid;
    feq_gen_i_d_1[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>("a");
    s_cat(tabida, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_2, (ftnlen)16);
/*     Now seek the internal table number for tabida */
/* SOURCE xsection.for:6346 */
/*<       callfind_internal_tab_number(tabida,taba) >*/
    feq_gen_find_internal_tab_number_d_(tabida, &taba, (ftnlen)16);
/* SOURCE xsection.for:6350 */
/*<       if(taba.eq.0)then >*/
    if (taba == 0) {
/*       User has not input a table of that name using FTABIN. */
/* SOURCE xsection.for:6352 */
/*<       return >*/
	return 0;
/* SOURCE xsection.for:6353 */
/*<       endif >*/
    }
/*     Check to make sure the table is of the correct type.  We now only */
/*     support type 25-anything else will not do- maybe later? */
/* SOURCE xsection.for:6358 */
/*<       adrsa=taba >*/
    adrsa = taba;
/* SOURCE xsection.for:6359 */
/*<       callchktab(25,stdout,ftpnt,mftnum,adrsa,eflag) >*/
    chktab_(&feq_gen_c_d_25, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &adrsa, &eflag);
/* SOURCE xsection.for:6364 */
/*<       if(eflag.ne.0)then >*/
    if (eflag != 0) {
/* SOURCE xsection.for:6365 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE xsection.for:6366 */
/*<       endif >*/
    }
/* SOURCE xsection.for:6369 */
/*<       write(stdout,50)tabid,yslot >*/
    feq_gen_io_d__716.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__716);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, (char *)&abslot_1.yslot, (ftnlen)sizeof(real));
    e_wsfe();
/*     Find the initial values from tabida */
/* SOURCE xsection.for:6373 */
/*<       yzero=0.0 >*/
    yzero = (float)0.;
/* SOURCE xsection.for:6374 */
/*<        >*/
    xlkt25_(&adrsa, &yzero, &area, &top, &dt, &j, &k, &dk, &b, &db, &alp, &
	    dalp, &qc, &ma, &dma, &mq, &dmq);
/*     Added May 22, 1998: definition of XST(i,*) contents */
/*     Extended 13 March 2003 */
/*     Offset    Value */
/*     1         Maximum depth-y */
/*     2         Top width */
/*     3         Area */
/*     4         First moment of area about water surface */
/*     5         Square root of conveyance- kh */
/*     6         Beta */
/*     7         Alpha */
/*     8         dBeta/dy */
/*     9         dAlpha/dy */
/*     10        Critical flow from momentum */
/*     11        Critical flow from energy */
/*     12        Critcal flow assuming Alpha=beta=1 */
/*     13        Critical flow that is selected by user: 10, 11, or 12 */
/*     14        MA- correction of volumes for sinuousity */
/*     15        MQ- correction of momentum for sinuosity */
/*     16        Total wetted perimeter- added May 22, 1998 */
/*     17        Average Manning's n value for the cross section */
/*     18        dkh/dy computed by cubic-spline fit */
/*     19        dalpha/dy computed by cubic-spline fit */
/*     20        dbeta/dy computed by cubic-spline fit */
/*     21        dma/dy computed by cubic-spline fit */
/*     22        dmq/dy computed by cubic-spline fit */
/* SOURCE xsection.for:6408 */
/*<       doi=1,ndep >*/
    feq_gen_i_d_2 = *ndep;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE xsection.for:6409 */
/*<       yarg=xst(i,1) >*/
	yarg = xst[feq_gen_i_d_ + 999];
/* SOURCE xsection.for:6410 */
/*<       if(yarg.le.yslot)then >*/
	if (yarg <= abslot_1.yslot) {
/*         we are in the slot. */
/* SOURCE xsection.for:6413 */
/*<       xst(i,6)=b >*/
	    xst[feq_gen_i_d_ + 5994] = b;
/* SOURCE xsection.for:6414 */
/*<       xst(i,7)=alp >*/
	    xst[feq_gen_i_d_ + 6993] = alp;
/* SOURCE xsection.for:6415 */
/*<       xst(i,14)=ma >*/
	    xst[feq_gen_i_d_ + 13986] = ma;
/* SOURCE xsection.for:6416 */
/*<       xst(i,15)=mq >*/
	    xst[feq_gen_i_d_ + 14985] = mq;
/* SOURCE xsection.for:6417 */
/*<       else >*/
	} else {
/*         we are out of the slot.  Redefine the values. */
/* SOURCE xsection.for:6419 */
/*<       yarg=yarg-yslot >*/
	    yarg -= abslot_1.yslot;
/* SOURCE xsection.for:6420 */
/*<        >*/
	    xlkt25_(&adrsa, &yarg, &area, &top, &dt, &j, &k, &dk, &b, &db, &
		    alp, &dalp, &qc, &ma, &dma, &mq, &dmq);
/* SOURCE xsection.for:6426 */
/*<       xst(i,6)=b >*/
	    xst[feq_gen_i_d_ + 5994] = b;
/* SOURCE xsection.for:6427 */
/*<       xst(i,7)=alp >*/
	    xst[feq_gen_i_d_ + 6993] = alp;
/* SOURCE xsection.for:6428 */
/*<       xst(i,14)=ma >*/
	    xst[feq_gen_i_d_ + 13986] = ma;
/* SOURCE xsection.for:6429 */
/*<       xst(i,15)=mq >*/
	    xst[feq_gen_i_d_ + 14985] = mq;
/* SOURCE xsection.for:6431 */
/*<       endif >*/
	}
/* SOURCE xsection.for:6432 */
/*<       enddo >*/
    }
/* SOURCE xsection.for:6434 */
/*<       return >*/
    return 0;
/* SOURCE xsection.for:6435 */
/*<       end >*/
} /* replace_eslot_elements__ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
