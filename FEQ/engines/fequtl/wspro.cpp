#include "../support/format.hpp"
/* wspro.f -- translated by f2c (version 20240504).
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

/* COMMON wxprox_ is declared in common.hpp. */

#define wxprox_1 wxprox_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON nrdzcm_ is declared in common.hpp. */

#define nrdzcm_1 nrdzcm_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON xtadd_ is declared in common.hpp. */

#define xtadd_1 xtadd_

/* COMMON xtaddc_ is declared in common.hpp. */

#define xtaddc_1 xtaddc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_35 = 35;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_4 = 4;
static real c_b44 = (float)-1e30;
static real c_b45 = (float)1e30;
static integer feq_gen_c_d_40 = 40;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_16 = 16;
static integer feq_gen_c_d_14 = 14;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_20 = 20;
static integer feq_gen_c_d_200 = 200;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_2 = 2;




/* SOURCE wspro.for:4 */
/*<        >*/
/* Subroutine */ int scnpro_(integer *in, integer *stdout, integer *mxpntu, 
	real *stadir, real *stattb, integer *feq_storage_sbu, real *feq_storage_lsnu, integer *lnflag,
	 integer *xflag, char *oldid, integer *first, real *statl, real *
	statr, integer *npntu, integer *nsubu, real *feq_storage_xu, real *feq_storage_zu, real *feq_storage_nu, 
	integer *feq_storage_nvaru, real *feq_storage_natyu, real *feq_storage_yatnu, integer *feq_storage_nnyu, integer *
	eflag, real *left, real *right, char *xsname, integer *ncon, real *
	feq_storage_xfline, ftnlen oldid_len, ftnlen xsname_len)
{
    /* Initialized data */

    static char ridtab[2*35+1] = "* ABASBDBLBPBRCCCDCGCVEREXFLGRGTHPJ1J3KDN \
NDPWPXQ SASDSKT1T2T3WSXRXSXT";
    static integer ridcat[35] = { 2,5,1,5,5,5,1,6,5,6,1,2,2,3,3,3,2,2,2,5,3,3,
	    5,2,4,3,1,4,2,2,2,4,1,1,1 };

    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:536* Record id=\002,a2,\002 unknown\
.\002)";
    static char fmt_51[] = "(\002 *ERR:541* X and Y value count=\002,i5,\002\
 is odd. Both \002,\002values \002,/,11x,\002must be on the same input recor\
d.\002)";
    static char fmt_52[] = "(\002 *ERR:542* Section id= \002,a5,\002 has no \
station value.\002)";
    static char fmt_53[] = "(\002 *ERR:521* Number of subareas=\002,i5,\002 \
inconsistent with\002,\002 number of n values=\002,i5)";
    static char fmt_54[] = "(\002 *ERR:522* Number of n values=\002,i5,\002 \
inconsistent with\002,\002 number of breakpoints on ND.\002)";
    static char fmt_56[] = "(\002 *ERR:523* No GR cards found following XT c\
ard.\002)";
    static char fmt_58[] = "(\002 *ERR:524* There are\002,i3,\002 items for \
flow-line data.\002,\002 Only 1, 3, or 5 items are valid.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double cos(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, ip;
    real xe, xs, fac;
    integer cat, npi, opt, clen[40];
    char cval[256*40];
    static char line[80];
    integer ival[40];
    real dely, xarg[20], rval[40];
    char term[1*40];
    integer feq_gen_type_d_[40];
    real xeps;
    char recid[2], secid[5];
    real leftl;
    doublereal dpval[40];
    static real dstat;
    real axisl;
    integer terml[40];
    real cossk;
    extern /* Subroutine */ int inspt_(integer *, integer *, real *, integer *
	    , integer *, real *, real *, integer *, real *, integer *);
    char headid[2];
    extern doublereal fdcnmn_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     binser_(char *, integer *, char *, integer *, ftnlen, ftnlen);
    real rightl;
    extern /* Subroutine */ int getval_(integer *, char *, integer *, integer 
	    *, integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    integer numval;
    real xinvar;
    integer option, termcls[40];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__26 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Scan WSPRO input in the file, IN, and get the next */
/*     cross section and return the values needed for computing */
/*     a cross section table. */
/* SOURCE wspro.for:17 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE wspro.for:20 */
/*<       integereflag,first,in,lnflag,mxpntu,ncon,npntu,nsubu,stdout,xflag >*/
/* SOURCE wspro.for:22 */
/*<       integernnyu(20),nvaru(20),sbu(mxpntu) >*/
/* SOURCE wspro.for:23 */
/*<        >*/
/* SOURCE wspro.for:26 */
/*<       characteroldid*2,xsname*5 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     MXPNTU - Maximum number of points on a cross section boundary */
/*     STADIR - Direction of stationing */
/*     STATTB - stationing for the axis */
/*     SBU    - Subsection numbers for the line segments */
/*     LSNU   - Line segment Manning's n value */
/*     LNFLAG - Flag to signal the state of the current line buffer */
/*     XFLAG  - cross section processing flag */
/*     OLDID  - identification value for the previous card */
/*     FIRST  - flag to detect the first header */
/*     STATL  - stationing for the flow path to the left */
/*     STATR  - stationing for the flow path to the right */
/*     NPNTU  - Number of points on boundary of a cross section */
/*     NSUBU  - Number of subsections */
/*     XU     - Offsets for points on boundary of cross section */
/*     ZU     - Elevation of points on boundary of cross section */
/*     NU     - Vector for Manning's n values */
/*     NVARU  - Flag for variation of Manning's n in each subsection */
/*     NATYU  - Mannings's n value at depth in YATNU */
/*     YATNU  - Depth values for the Manning's n values in NATYU */
/*     NNYU   - Number of values for Manning's n variation with depth */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     XSNAME - WSPRO name for the cross section */
/*     NCON   - flag for variation of Manning's n in the vertical */
/*     XFLINE - offsets assigned to flow lines */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE wspro.for:62 */
/*     Common block for the variables needed to process WSPRO */
/*     cross sections. */
/*     Parameters for dimensions */
/* SOURCE wsproxs.cmn:6 */
/*<       integermxnfl,mxngp,mxnsa >*/
/* SOURCE wsproxs.cmn:8 */
/*<       parameter(mxnfl=3,mxngp=100,mxnsa=20) >*/
/*     AS record variables */
/* SOURCE wsproxs.cmn:12 */
/*<       integerasflag >*/
/* SOURCE wsproxs.cmn:14 */
/*<       realsrd,skew,ek,ck,vslope >*/
/*     FL record variables */
/* SOURCE wsproxs.cmn:18 */
/*<       integerflflag,ihfno,nfl >*/
/* SOURCE wsproxs.cmn:20 */
/*<       realfldat(2*mxnfl),flen(mxnfl),xfl(mxnfl),yfl(mxnfl) >*/
/*     GR Record */
/* SOURCE wsproxs.cmn:24 */
/*<       integergrflag,ngp >*/
/* SOURCE wsproxs.cmn:26 */
/*<       realgrsrd,xgr(mxngp),ygr(mxngp),x(mxngp),y(mxngp) >*/
/*     GT Record */
/* SOURCE wsproxs.cmn:30 */
/*<       integergtflag >*/
/* SOURCE wsproxs.cmn:32 */
/*<       realyshift,xliml,xlimr,scale,xorig >*/
/*     N Record */
/* SOURCE wsproxs.cmn:36 */
/*<       integernflag,nn >*/
/* SOURCE wsproxs.cmn:38 */
/*<       realnval(2*mxnsa),botn(mxnsa),topn(mxnsa) >*/
/*     ND Record */
/* SOURCE wsproxs.cmn:42 */
/*<       integerndflag,nnd >*/
/* SOURCE wsproxs.cmn:44 */
/*<       realnndbrk(2*mxnsa),botd(mxnsa),topd(mxnsa) >*/
/*     SA Record */
/* SOURCE wsproxs.cmn:49 */
/*<       integersaflag,nsa,nsat >*/
/* SOURCE wsproxs.cmn:51 */
/*<       realxsa(mxnsa),xsat(mxnsa) >*/
/*     XR Record */
/* SOURCE wsproxs.cmn:55 */
/*<       integerxrflag,ipave >*/
/* SOURCE wsproxs.cmn:57 */
/*<       realembwid,usercf >*/
/*     XS Record */
/* SOURCE wsproxs.cmn:61 */
/*<       integerxsflag >*/
/*     XT Record */
/* SOURCE wsproxs.cmn:65 */
/*<       integerxtflag,xtngp,xtnsa >*/
/* SOURCE wsproxs.cmn:67 */
/*<       realxtsrd,xtxgr(mxngp),xtygr(mxngp),xtxsa(mxnsa) >*/
/* SOURCE wsproxs.cmn:69 */
/*<        >*/
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE wspro.for:65 */
/*<       integermxnval,nrid,header,cntrl,xsd,icd,bdd,cvd >*/
/* SOURCE wspro.for:66 */
/*<       realdefalt,dgtord >*/
/* SOURCE wspro.for:67 */
/*<        >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE wspro.for:71 */
/*<       integerridcat(nrid) >*/
/* SOURCE wspro.for:72 */
/*<       realdstat >*/
/* SOURCE wspro.for:73 */
/*<       characterline*80,ridtab(nrid)*2 >*/
/* SOURCE wspro.for:74 */
/*<       savedstat,line,ridcat,ridtab >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE wspro.for:77 */
/*<       integercat,i,ip,j,npi,numval,opt,option >*/
/* SOURCE wspro.for:78 */
/*<        >*/
/* SOURCE wspro.for:80 */
/*<        >*/
/* SOURCE wspro.for:82 */
/*<       doubleprecisiondpval(mxnval) >*/
/* SOURCE wspro.for:83 */
/*<       charactercval(mxnval)*256,headid*2,recid*2,secid*5,term(mxnval)*1 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE wspro.for:87 */
/*<       intrinsiccos,mod >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE wspro.for:90 */
/*<       realfdcnmn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE wspro.for:93 */
/*<       externalbinser,fdcnmn,getval,inline,inspt >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE wspro.for:96 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> zu(feq_storage_zu, 1);

    feq::IndexedPointer<real> xu(feq_storage_xu, 1);

    feq::IndexedPointer<real> lsnu(feq_storage_lsnu, 1);

    feq::IndexedPointer<integer> sbu(feq_storage_sbu, 1);

    feq::IndexedPointer<real> nu(feq_storage_nu, 1);

    feq::IndexedPointer<integer> nvaru(feq_storage_nvaru, 1);

    feq::IndexedPointer<real> natyu(feq_storage_natyu, 10);

    feq::IndexedPointer<real> yatnu(feq_storage_yatnu, 10);

    feq::IndexedPointer<integer> nnyu(feq_storage_nnyu, 1);

    feq::IndexedPointer<real> xfline(feq_storage_xfline, 1);

    /* Function Body */
/* SOURCE wspro.for:113 */
/*<    50 format(' *ERR:536* Record id=',a2,' unknown.') >*/
/* L50: */
/* SOURCE wspro.for:114 */
/*<    51  >*/
/* L51: */
/* SOURCE wspro.for:116 */
/*<    52 format(' *ERR:542* Section id= ',a5,' has no station value.') >*/
/* L52: */
/* SOURCE wspro.for:117 */
/*<    53  >*/
/* L53: */
/* SOURCE wspro.for:119 */
/*<    54  >*/
/* L54: */
/* SOURCE wspro.for:121 */
/*<    56 format(' *ERR:523* No GR cards found following XT card.') >*/
/* L56: */
/* SOURCE wspro.for:122 */
/*<    58  >*/
/* L58: */
/* *********************************************************************** */
/*     GET THE NEXT LINE FROM THE WSPRO INPUT FILE */
/* SOURCE wspro.for:127 */
/*<    90 continue >*/
L90:
/* SOURCE wspro.for:128 */
/*<       if(lnflag.eq.0)then >*/
    if (*lnflag == 0) {
/* SOURCE wspro.for:129 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:132 */
/*<       else >*/
    } else {
/*         CLEAR THE LINE BUFFER FLAG TO SIGNAL THAT THE BUFFER WILL */
/*         HAVE BEEN PROCESSED UPON EXIT FROM THIS ROUTINE. */
/* SOURCE wspro.for:135 */
/*<       lnflag=0 >*/
	*lnflag = 0;
/* SOURCE wspro.for:136 */
/*<       endif >*/
    }
/*       Get the fixed-field part of the record with an internal */
/*       read from a character string.   The value of the */
/*       record id and the state of various flags determines the */
/*       action to take. */
/* SOURCE wspro.for:144 */
/*<       read(line(1:10),'(A2,1X,I1,1X,A5)')recid,option,secid >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 10;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A2,1X,I1,1X,A5)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, recid, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, (char *)&option, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, secid, (ftnlen)5);
    e_rsfi();
/*        WRITE(STDOUT,*)' RECID=',RECID,' SECID=',SECID */
/*       If the record id is a header record, it means that the */
/*       cross section we are processing is complete, if there is */
/*       a cross section.  XFLAG is the indicator for cross section */
/*       processing.  XFLAG=0 means no cross section is */
/*       underway,  XFLAG=1 means there is a cross section in */
/*       process. */
/*       Find the category of the record id. HEADER-header record, */
/*       CNTRL-control record, XSD-cross section data, ICD-initial */
/*       condition data, BDD-bridge data, and CVD-culvert data. */
/* SOURCE wspro.for:159 */
/*<       callbinser(recid,nrid,ridtab,ip) >*/
    binser_(recid, &feq_gen_c_d_35, ridtab, &ip, (ftnlen)2, (ftnlen)2);
/* SOURCE wspro.for:162 */
/*<       if(ip.eq.0)then >*/
    if (ip == 0) {
/* SOURCE wspro.for:163 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE wspro.for:164 */
/*<       write(stdout,50)recid >*/
	feq_gen_io_d__8.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__8);
	do_fio(&feq_gen_c_d_1, recid, (ftnlen)2);
	e_wsfe();
/* SOURCE wspro.for:165 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:166 */
/*<       endif >*/
    }
/* SOURCE wspro.for:167 */
/*<       if(recid.eq.'ER')then >*/
    if (s_cmp(recid, const_cast<char*>("ER"), (ftnlen)2, (ftnlen)2) == 0) {
/* SOURCE wspro.for:168 */
/*<       if(xflag.eq.0)then >*/
	if (*xflag == 0) {
/*           All information in the file has been processed. */
/* SOURCE wspro.for:170 */
/*<       xflag=-1 >*/
	    *xflag = -1;
/* SOURCE wspro.for:171 */
/*<       return >*/
	    return 0;
/* SOURCE wspro.for:172 */
/*<       endif >*/
	}
/* SOURCE wspro.for:173 */
/*<       endif >*/
    }
/* SOURCE wspro.for:174 */
/*<       cat=ridcat(ip) >*/
    cat = ridcat[ip - 1];
/*        WRITE(STDOUT,*) ' FOR RECID=',RECID,' CAT=',CAT,' XFLAG=',XFLAG */
/* SOURCE wspro.for:178 */
/*<       if(cat.ne.xsd)then >*/
    if (cat != 3) {
/* SOURCE wspro.for:179 */
/*<       if(xflag.eq.1)then >*/
	if (*xflag == 1) {
/*           We now have the description of a cross section in */
/*           hand.  Convert it to FEQXEXT form and return the values. */
/*           Remember that there are good values in LINE waiting to be */
/*           processed. */
/* SOURCE wspro.for:184 */
/*<       lnflag=1 >*/
	    *lnflag = 1;
/*           Request that the whole cross section be processed. */
/* SOURCE wspro.for:188 */
/*<       left=0.0 >*/
	    *left = (float)0.;
/* SOURCE wspro.for:189 */
/*<       right=0.0 >*/
	    *right = (float)0.;
/*           Determine the description for the current cross section. */
/*           There are many choices to make here.  The description */
/*           could have been input with the current header, part or */
/*           all of the description could come from the last description */
/*           read for a previous header, or part of the description */
/*           could come from a template section that was stored */
/*           earlier.  Ground points must be input with a template */
/*           header and SA points may be input with a template header. */
/*           If the header record is XT then this section stores the */
/*           current ground and if present, SA information. */
/*           No cross section data should be returned.  Processing */
/*           of the WSPRO input should continue. */
/* SOURCE wspro.for:203 */
/*<       if(headid.ne.'XT')then >*/
	    if (s_cmp(headid, const_cast<char*>("XT"), (ftnlen)2, (ftnlen)2) != 0) {
/*             Compute the skew factor */
/* SOURCE wspro.for:205 */
/*<       cossk=cos(skew*dgtord) >*/
		cossk = cos(static_cast<double>(wxprox_1.skew) * (float).01745329);
/* SOURCE wspro.for:207 */
/*<       if(gtflag.eq.1)then >*/
		if (wxprox_1.gtflag == 1) {
/*               We have a current GT record. Do not allow GT values to */
/*               propagate. */
/* SOURCE wspro.for:211 */
/*<       gtflag=0 >*/
		    wxprox_1.gtflag = 0;
/*               Get the limits to use.  Note that the retained cross */
/*               section does not retain the truncation limits. */
/* SOURCE wspro.for:216 */
/*<       left=xliml >*/
		    *left = wxprox_1.xliml;
/* SOURCE wspro.for:217 */
/*<       right=xlimr >*/
		    *right = wxprox_1.xlimr;
/*               It appears that the definition of ground points using */
/*               GT is treated as if it were input of GR cards.  Thus */
/*               a subsequent cross section heading without a GT or GR */
/*               takes its ground points from the most recent previous */
/*               occurrence of GT or GR. */
/* SOURCE wspro.for:225 */
/*<       grsrd=srd >*/
		    wxprox_1.grsrd = wxprox_1.srd;
/* SOURCE wspro.for:227 */
/*<       if(yshift.eq.defalt)then >*/
		    if (wxprox_1.yshift == (float)-1e30) {
/*                 No vertical shift given.  Use the value of */
/*                 VSLOPE and the difference in stations for any */
/*                 vertical adjustment. */
/* SOURCE wspro.for:232 */
/*<       dely=(srd-xtsrd)*vslope >*/
			dely = static_cast<double>((static_cast<double>(wxprox_1.srd) - wxprox_1.xtsrd)) * 
				wxprox_1.vslope;
/* SOURCE wspro.for:233 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:234 */
/*<       dely=yshift >*/
			dely = wxprox_1.yshift;
/* SOURCE wspro.for:235 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:236 */
/*<       ngp=xtngp >*/
		    wxprox_1.ngp = wxprox_1.xtngp;
/* SOURCE wspro.for:237 */
/*<       do210i=1,ngp >*/
		    feq_gen_i_d_1 = wxprox_1.ngp;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:238 */
/*<       y(i)=xtygr(i)+dely >*/
			wxprox_1.y[feq_gen_i_d_ - 1] = static_cast<double>(wxprox_1.xtygr[feq_gen_i_d_ - 1]) + dely;
/* SOURCE wspro.for:239 */
/*<       ygr(i)=y(i) >*/
			wxprox_1.ygr[feq_gen_i_d_ - 1] = wxprox_1.y[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:240 */
/*<   210 continue >*/
/* L210: */
		    }
/*               Do the horizontal adjustments.  Find the invariant */
/*               point.  Combine with skew adjustment. */
/* SOURCE wspro.for:244 */
/*<       fac=cossk*scale >*/
		    fac = static_cast<double>(cossk) * wxprox_1.scale;
/* SOURCE wspro.for:245 */
/*<       if(xorig.gt.defalt)then >*/
		    if (wxprox_1.xorig > (float)-1e30) {
/* SOURCE wspro.for:246 */
/*<       xinvar=xorig >*/
			xinvar = wxprox_1.xorig;
/* SOURCE wspro.for:247 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:248 */
/*<       xinvar=0.0 >*/
			xinvar = (float)0.;
/* SOURCE wspro.for:249 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:250 */
/*<       do220i=1,ngp >*/
		    feq_gen_i_d_1 = wxprox_1.ngp;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:251 */
/*<       x(i)=fac*(xtxgr(i)-xinvar)+xinvar >*/
			wxprox_1.x[feq_gen_i_d_ - 1] = static_cast<double>(static_cast<double>(fac) * (static_cast<double>(wxprox_1.xtxgr[feq_gen_i_d_ - 1]) 
				- xinvar)) + xinvar;
/* SOURCE wspro.for:252 */
/*<       xgr(i)=x(i) >*/
			wxprox_1.xgr[feq_gen_i_d_ - 1] = wxprox_1.x[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:253 */
/*<   220 continue >*/
/* L220: */
		    }
/*               Now find the subarea limits for the ground points */
/*               taken from the template section. */
/* SOURCE wspro.for:257 */
/*<       if(saflag.eq.1)then >*/
		    if (wxprox_1.saflag == 1) {
/*                 The user has input the SA under the same header as */
/*                 the GT record. */
/* SOURCE wspro.for:260 */
/*<       nsa=nsat+1 >*/
			wxprox_1.nsa = wxprox_1.nsat + 1;
/* SOURCE wspro.for:261 */
/*<       do225i=1,nsat >*/
			feq_gen_i_d_1 = wxprox_1.nsat;
			for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:262 */
/*<       xsa(i)=cossk*xsat(i) >*/
			    wxprox_1.xsa[feq_gen_i_d_ - 1] = static_cast<double>(cossk) * wxprox_1.xsat[feq_gen_i_d_ 
				    - 1];
/* SOURCE wspro.for:263 */
/*<       xsat(i)=xsa(i) >*/
			    wxprox_1.xsat[feq_gen_i_d_ - 1] = wxprox_1.xsa[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:264 */
/*<   225 continue >*/
/* L225: */
			}
/* SOURCE wspro.for:265 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:266 */
/*<       if(xtnsa.gt.0)then >*/
			if (wxprox_1.xtnsa > 0) {
/*                   User has ommitted the SA record but it exists */
/*                   in the template record. */
/* SOURCE wspro.for:269 */
/*<       nsa=xtnsa+1 >*/
			    wxprox_1.nsa = wxprox_1.xtnsa + 1;
/* SOURCE wspro.for:270 */
/*<       nsat=xtnsa >*/
			    wxprox_1.nsat = wxprox_1.xtnsa;
/* SOURCE wspro.for:271 */
/*<       do230i=1,xtnsa >*/
			    feq_gen_i_d_1 = wxprox_1.xtnsa;
			    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:272 */
/*<       xsa(i)=fac*(xtxsa(i)-xinvar)+xinvar >*/
				wxprox_1.xsa[feq_gen_i_d_ - 1] = static_cast<double>(static_cast<double>(fac) * (static_cast<double>(wxprox_1.xtxsa[
					feq_gen_i_d_ - 1]) - xinvar)) + xinvar;
/* SOURCE wspro.for:273 */
/*<       xsat(i)=xsa(i) >*/
				wxprox_1.xsat[feq_gen_i_d_ - 1] = wxprox_1.xsa[feq_gen_i_d_ - 1]
					;
/* SOURCE wspro.for:274 */
/*<   230 continue >*/
/* L230: */
			    }
/* SOURCE wspro.for:275 */
/*<       else >*/
			} else {
/*                   User has ommitted the SA record and it does not */
/*                   exist in the template record.  Use the most recent */
/*                   value available. */
/* SOURCE wspro.for:280 */
/*<       nsa=nsat+1 >*/
			    wxprox_1.nsa = wxprox_1.nsat + 1;
/* SOURCE wspro.for:281 */
/*<       do235i=1,nsat >*/
			    feq_gen_i_d_1 = wxprox_1.nsat;
			    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:282 */
/*<       xsa(i)=cossk*xsat(i) >*/
				wxprox_1.xsa[feq_gen_i_d_ - 1] = static_cast<double>(cossk) * wxprox_1.xsat[
					feq_gen_i_d_ - 1];
/* SOURCE wspro.for:283 */
/*<       xsat(i)=xsa(i) >*/
				wxprox_1.xsat[feq_gen_i_d_ - 1] = wxprox_1.xsa[feq_gen_i_d_ - 1]
					;
/* SOURCE wspro.for:284 */
/*<   235 continue >*/
/* L235: */
			    }
/* SOURCE wspro.for:285 */
/*<       endif >*/
			}
/* SOURCE wspro.for:286 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:287 */
/*<       else >*/
		} else {
/*               Source of ground points is not the template section. */
/*               Take from the most recent value of ground points */
/*               and adjust for any non-zero valley slope.  The adjustment */
/*               affects the retained ground point values just as if */
/*               the ground points had been input directly. */
/*                WRITE(STDOUT,*) ' SRD=',SRD,' GRSRD=',GRSRD, */
/*     A                   ' VSLOPE=',VSLOPE */
/* SOURCE wspro.for:297 */
/*<       dely=(srd-grsrd)*vslope >*/
		    dely = static_cast<double>((static_cast<double>(wxprox_1.srd) - wxprox_1.grsrd)) * wxprox_1.vslope;
/* SOURCE wspro.for:298 */
/*<       write(stdout,*)' DELY=',dely >*/
		    feq_gen_io_d__16.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__16);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DELY="), (ftnlen)6);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&dely, (ftnlen)sizeof(real));
		    e_wsle();
/* SOURCE wspro.for:300 */
/*<       do240i=1,ngp >*/
		    feq_gen_i_d_1 = wxprox_1.ngp;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:301 */
/*<       y(i)=ygr(i)+dely >*/
			wxprox_1.y[feq_gen_i_d_ - 1] = static_cast<double>(wxprox_1.ygr[feq_gen_i_d_ - 1]) + dely;
/* SOURCE wspro.for:302 */
/*<       x(i)=cossk*xgr(i) >*/
			wxprox_1.x[feq_gen_i_d_ - 1] = static_cast<double>(cossk) * wxprox_1.xgr[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:303 */
/*<       ygr(i)=y(i) >*/
			wxprox_1.ygr[feq_gen_i_d_ - 1] = wxprox_1.y[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:304 */
/*<       xgr(i)=x(i) >*/
			wxprox_1.xgr[feq_gen_i_d_ - 1] = wxprox_1.x[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:305 */
/*<   240 continue >*/
/* L240: */
		    }
/* SOURCE wspro.for:307 */
/*<       nsa=nsat+1 >*/
		    wxprox_1.nsa = wxprox_1.nsat + 1;
/* SOURCE wspro.for:308 */
/*<       do245i=1,nsat >*/
		    feq_gen_i_d_1 = wxprox_1.nsat;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:309 */
/*<       xsa(i)=cossk*xsat(i) >*/
			wxprox_1.xsa[feq_gen_i_d_ - 1] = static_cast<double>(cossk) * wxprox_1.xsat[feq_gen_i_d_ - 1]
				;
/* SOURCE wspro.for:310 */
/*<       xsat(i)=xsa(i) >*/
			wxprox_1.xsat[feq_gen_i_d_ - 1] = wxprox_1.xsa[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:311 */
/*<   245 continue >*/
/* L245: */
		    }
/* SOURCE wspro.for:312 */
/*<       endif >*/
		}
/*             Update the station of the most recent ground points. */
/* SOURCE wspro.for:315 */
/*<       grsrd=srd >*/
		wxprox_1.grsrd = wxprox_1.srd;
/*             Now the ground points and the subarea limits are */
/*             defined in all cases.  Decipher the meaning of the */
/*             the N  and ND records.  If the number of */
/*             values on the N record is the same as NSA, it means that */
/*             the values on the N record represent values of n that do */
/*             not vary with depth.  If the number of values on the N */
/*             record is 2*NSA, then they represent the break-point values */
/*             of Manning's n.  These are only valid if ND has set the */
/*             breakpoints. */
/* SOURCE wspro.for:326 */
/*<       if(nn.eq.nsa)then >*/
		if (wxprox_1.nn == wxprox_1.nsa) {
/*               Constant values of Manning's n.  Values are already */
/*               in NVAL(*). */
/* SOURCE wspro.for:329 */
/*<       elseif(nn.eq.nsa+nsa)then >*/
		} else if (wxprox_1.nn == wxprox_1.nsa + wxprox_1.nsa) {
/*               Breakpoint variation of n in the vertical */
/* SOURCE wspro.for:331 */
/*<       do200i=1,nsa >*/
		    feq_gen_i_d_1 = wxprox_1.nsa;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:332 */
/*<       j=i+i >*/
			j = feq_gen_i_d_ + feq_gen_i_d_;
/* SOURCE wspro.for:333 */
/*<       topn(i)=nval(j) >*/
			wxprox_1.topn[feq_gen_i_d_ - 1] = wxprox_1.nval[j - 1];
/* SOURCE wspro.for:334 */
/*<       botn(i)=nval(j-1) >*/
			wxprox_1.botn[feq_gen_i_d_ - 1] = wxprox_1.nval[j - 2];
/* SOURCE wspro.for:335 */
/*<   200 continue >*/
/* L200: */
		    }
/*               Transfer the breakpoint depths. */
/* SOURCE wspro.for:337 */
/*<       if(nn.ne.nnd)then >*/
		    if (wxprox_1.nn != wxprox_1.nnd) {
/* SOURCE wspro.for:338 */
/*<       write(stdout,54)nn,nnd >*/
			feq_gen_io_d__18.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__18);
			do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.nn, (ftnlen)sizeof(
				integer));
			do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.nnd, (ftnlen)sizeof(
				integer));
			e_wsfe();
/* SOURCE wspro.for:339 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE wspro.for:340 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:341 */
/*<       do205i=1,nsa >*/
			feq_gen_i_d_1 = wxprox_1.nsa;
			for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:342 */
/*<       j=i+i >*/
			    j = feq_gen_i_d_ + feq_gen_i_d_;
/* SOURCE wspro.for:343 */
/*<       topd(i)=nndbrk(j) >*/
			    wxprox_1.topd[feq_gen_i_d_ - 1] = wxprox_1.nndbrk[j - 1];
/* SOURCE wspro.for:344 */
/*<       botd(i)=nndbrk(j-1) >*/
			    wxprox_1.botd[feq_gen_i_d_ - 1] = wxprox_1.nndbrk[j - 2];
/* SOURCE wspro.for:345 */
/*<   205 continue >*/
/* L205: */
			}
/* SOURCE wspro.for:346 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:347 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:348 */
/*<       write(stdout,53)nsa,nn >*/
		    feq_gen_io_d__19.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__19);
		    do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.nsa, (ftnlen)sizeof(
			    integer));
		    do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.nn, (ftnlen)sizeof(
			    integer));
		    e_wsfe();
/* SOURCE wspro.for:349 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE wspro.for:350 */
/*<       endif >*/
		}
/*             Now decipher any flow length data.   Friction slope */
/*             averaging is ignored. */
/* SOURCE wspro.for:354 */
/*<       xs=xgr(1) >*/
		xs = wxprox_1.xgr[0];
/* SOURCE wspro.for:355 */
/*<       xe=xgr(ngp) >*/
		xe = wxprox_1.xgr[wxprox_1.ngp - 1];
/* SOURCE wspro.for:356 */
/*<       xeps=0.001*(xe-xs) >*/
		xeps = static_cast<double>((static_cast<double>(xe) - xs)) * (float).001;
/* SOURCE wspro.for:357 */
/*<       if(xeps.gt.1.0)xeps=1.0 >*/
		if (xeps > (float)1.) {
		    xeps = (float)1.;
		}
/* SOURCE wspro.for:358 */
/*<       if(flflag.eq.1.and.nfl.gt.0)then >*/
		if (wxprox_1.flflag == 1 && wxprox_1.nfl > 0) {
/*               There is flow length data present. */
/* SOURCE wspro.for:360 */
/*<       if(nfl.eq.1)then >*/
		    if (wxprox_1.nfl == 1) {
/* SOURCE wspro.for:361 */
/*<       flen(1)=fldat(1) >*/
			wxprox_1.flen[0] = wxprox_1.fldat[0];
/*                 There is only one flow length.  Therefore it is the */
/*                 lenght for all points. */
/* SOURCE wspro.for:364 */
/*<       leftl=flen(1) >*/
			leftl = wxprox_1.flen[0];
/* SOURCE wspro.for:365 */
/*<       axisl=flen(1) >*/
			axisl = wxprox_1.flen[0];
/* SOURCE wspro.for:366 */
/*<       rightl=flen(1) >*/
			rightl = wxprox_1.flen[0];
/*                 Set the offsets for sinuousity computation.  There */
/*                 are always 6 offsets because there will always be */
/*                 6 flow lines. */
/* SOURCE wspro.for:370 */
/*<       xfline(1)=xs-2.*xeps >*/
			xfline[1] = static_cast<double>(xs) - static_cast<double>(xeps) * (float)2.;
/* SOURCE wspro.for:371 */
/*<       xfline(2)=xs-xeps >*/
			xfline[2] = static_cast<double>(xs) - xeps;
/* SOURCE wspro.for:372 */
/*<       xfline(3)=xs >*/
			xfline[3] = xs;
/* SOURCE wspro.for:373 */
/*<       xfline(4)=xe >*/
			xfline[4] = xe;
/* SOURCE wspro.for:374 */
/*<       xfline(5)=xe+xeps >*/
			xfline[5] = static_cast<double>(xe) + xeps;
/* SOURCE wspro.for:375 */
/*<       xfline(6)=xe+2.*xeps >*/
			xfline[6] = static_cast<double>(xe) + static_cast<double>(xeps) * (float)2.;
/* SOURCE wspro.for:376 */
/*<       elseif(nfl.eq.3)then >*/
		    } else if (wxprox_1.nfl == 3) {
/* SOURCE wspro.for:377 */
/*<       flen(1)=fldat(1) >*/
			wxprox_1.flen[0] = wxprox_1.fldat[0];
/* SOURCE wspro.for:378 */
/*<       xfl(1)=cossk*fldat(2) >*/
			wxprox_1.xfl[0] = static_cast<double>(cossk) * wxprox_1.fldat[1];
/* SOURCE wspro.for:379 */
/*<       yfl(1)=fdcnmn(ngp,x,y,defalt,xfl(1)) >*/
			wxprox_1.yfl[0] = fdcnmn_(&wxprox_1.ngp, wxprox_1.x, 
				wxprox_1.y, &c_b44, wxprox_1.xfl);
/* SOURCE wspro.for:380 */
/*<       flen(2)=fldat(3) >*/
			wxprox_1.flen[1] = wxprox_1.fldat[2];
/* SOURCE wspro.for:381 */
/*<       yfl(2)=fdcnmn(ngp,x,y,xfl(1),-defalt) >*/
			wxprox_1.yfl[1] = fdcnmn_(&wxprox_1.ngp, wxprox_1.x, 
				wxprox_1.y, wxprox_1.xfl, &c_b45);
/* SOURCE wspro.for:382 */
/*<       nfl=2 >*/
			wxprox_1.nfl = 2;
/* SOURCE wspro.for:383 */
/*<       if(yfl(1).lt.yfl(2))then >*/
			if (wxprox_1.yfl[0] < wxprox_1.yfl[1]) {
/*                   Assume axis is for first flow length. */
/* SOURCE wspro.for:385 */
/*<       leftl=flen(1) >*/
			    leftl = wxprox_1.flen[0];
/* SOURCE wspro.for:386 */
/*<       axisl=flen(1) >*/
			    axisl = wxprox_1.flen[0];
/* SOURCE wspro.for:387 */
/*<       rightl=flen(2) >*/
			    rightl = wxprox_1.flen[1];
/* SOURCE wspro.for:388 */
/*<       xfline(1)=xs-2.*xeps >*/
			    xfline[1] = static_cast<double>(xs) - static_cast<double>(xeps) * (float)2.;
/* SOURCE wspro.for:389 */
/*<       xfline(2)=xs-xeps >*/
			    xfline[2] = static_cast<double>(xs) - xeps;
/* SOURCE wspro.for:390 */
/*<       xfline(3)=xs >*/
			    xfline[3] = xs;
/* SOURCE wspro.for:391 */
/*<       xfline(4)=xfl(1) >*/
			    xfline[4] = wxprox_1.xfl[0];
/* SOURCE wspro.for:392 */
/*<       xfline(5)=xfl(1)+xeps >*/
			    xfline[5] = static_cast<double>(wxprox_1.xfl[0]) + xeps;
/* SOURCE wspro.for:393 */
/*<       xfline(6)=xe >*/
			    xfline[6] = xe;
/* SOURCE wspro.for:394 */
/*<       else >*/
			} else {
/* SOURCE wspro.for:395 */
/*<       leftl=flen(1) >*/
			    leftl = wxprox_1.flen[0];
/* SOURCE wspro.for:396 */
/*<       axisl=flen(2) >*/
			    axisl = wxprox_1.flen[1];
/* SOURCE wspro.for:397 */
/*<       rightl=flen(2) >*/
			    rightl = wxprox_1.flen[1];
/* SOURCE wspro.for:398 */
/*<       xfline(1)=xs >*/
			    xfline[1] = xs;
/* SOURCE wspro.for:399 */
/*<       xfline(2)=xfl(1)-xeps >*/
			    xfline[2] = static_cast<double>(wxprox_1.xfl[0]) - xeps;
/* SOURCE wspro.for:400 */
/*<       xfline(3)=xfl(1) >*/
			    xfline[3] = wxprox_1.xfl[0];
/* SOURCE wspro.for:401 */
/*<       xfline(4)=xe >*/
			    xfline[4] = xe;
/* SOURCE wspro.for:402 */
/*<       xfline(5)=xe+xeps >*/
			    xfline[5] = static_cast<double>(xe) + xeps;
/* SOURCE wspro.for:403 */
/*<       xfline(6)=xe+2.*xeps >*/
			    xfline[6] = static_cast<double>(xe) + static_cast<double>(xeps) * (float)2.;
/* SOURCE wspro.for:404 */
/*<       endif >*/
			}
/* SOURCE wspro.for:405 */
/*<       elseif(nfl.eq.5)then >*/
		    } else if (wxprox_1.nfl == 5) {
/* SOURCE wspro.for:406 */
/*<       flen(1)=fldat(1) >*/
			wxprox_1.flen[0] = wxprox_1.fldat[0];
/* SOURCE wspro.for:407 */
/*<       xfl(1)=cossk*fldat(2) >*/
			wxprox_1.xfl[0] = static_cast<double>(cossk) * wxprox_1.fldat[1];
/* SOURCE wspro.for:408 */
/*<       yfl(1)=fdcnmn(ngp,x,y,defalt,xfl(1)) >*/
			wxprox_1.yfl[0] = fdcnmn_(&wxprox_1.ngp, wxprox_1.x, 
				wxprox_1.y, &c_b44, wxprox_1.xfl);
/* SOURCE wspro.for:409 */
/*<       flen(2)=fldat(3) >*/
			wxprox_1.flen[1] = wxprox_1.fldat[2];
/* SOURCE wspro.for:410 */
/*<       xfl(2)=cossk*fldat(4) >*/
			wxprox_1.xfl[1] = static_cast<double>(cossk) * wxprox_1.fldat[3];
/* SOURCE wspro.for:411 */
/*<       yfl(2)=fdcnmn(ngp,x,y,xfl(1),xfl(2)) >*/
			wxprox_1.yfl[1] = fdcnmn_(&wxprox_1.ngp, wxprox_1.x, 
				wxprox_1.y, wxprox_1.xfl, &wxprox_1.xfl[1]);
/* SOURCE wspro.for:412 */
/*<       flen(3)=fldat(5) >*/
			wxprox_1.flen[2] = wxprox_1.fldat[4];
/* SOURCE wspro.for:413 */
/*<       yfl(3)=fdcnmn(ngp,x,y,xfl(2),-defalt) >*/
			wxprox_1.yfl[2] = fdcnmn_(&wxprox_1.ngp, wxprox_1.x, 
				wxprox_1.y, &wxprox_1.xfl[1], &c_b45);
/* SOURCE wspro.for:414 */
/*<       nfl=3 >*/
			wxprox_1.nfl = 3;
/* SOURCE wspro.for:415 */
/*<       leftl=flen(1) >*/
			leftl = wxprox_1.flen[0];
/* SOURCE wspro.for:416 */
/*<       axisl=flen(2) >*/
			axisl = wxprox_1.flen[1];
/* SOURCE wspro.for:417 */
/*<       rightl=flen(3) >*/
			rightl = wxprox_1.flen[2];
/* SOURCE wspro.for:418 */
/*<       xfline(1)=xs >*/
			xfline[1] = xs;
/* SOURCE wspro.for:419 */
/*<       xfline(2)=xfl(1)-xeps >*/
			xfline[2] = static_cast<double>(wxprox_1.xfl[0]) - xeps;
/* SOURCE wspro.for:420 */
/*<       xfline(3)=xfl(1) >*/
			xfline[3] = wxprox_1.xfl[0];
/* SOURCE wspro.for:421 */
/*<       xfline(4)=xfl(2) >*/
			xfline[4] = wxprox_1.xfl[1];
/* SOURCE wspro.for:422 */
/*<       xfline(5)=xfl(2)+xeps >*/
			xfline[5] = static_cast<double>(wxprox_1.xfl[1]) + xeps;
/* SOURCE wspro.for:423 */
/*<       xfline(6)=xe >*/
			xfline[6] = xe;
/* SOURCE wspro.for:424 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:425 */
/*<       write(stdout,58)nfl >*/
			feq_gen_io_d__26.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__26);
			do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.nfl, (ftnlen)sizeof(
				integer));
			e_wsfe();
/* SOURCE wspro.for:426 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE wspro.for:427 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:428 */
/*<       if(stadir.ge.0.0)then >*/
		    if (*stadir >= (float)0.) {
/* SOURCE wspro.for:429 */
/*<       statl=statl+leftl >*/
			*statl += leftl;
/* SOURCE wspro.for:430 */
/*<       stattb=stattb+axisl >*/
			*stattb += axisl;
/* SOURCE wspro.for:431 */
/*<       statr=statr+rightl >*/
			*statr += rightl;
/* SOURCE wspro.for:432 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:433 */
/*<       statl=statl-leftl >*/
			*statl -= leftl;
/* SOURCE wspro.for:434 */
/*<       stattb=stattb-axisl >*/
			*stattb -= axisl;
/* SOURCE wspro.for:435 */
/*<       statr=statr-rightl >*/
			*statr -= rightl;
/* SOURCE wspro.for:436 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:437 */
/*<       else >*/
		} else {
/*               No flow line lengths given.  Thus SRD must give the */
/*               stations for all flow lengths. */
/* SOURCE wspro.for:440 */
/*<       statl=srd+dstat >*/
		    *statl = static_cast<double>(wxprox_1.srd) + dstat;
/* SOURCE wspro.for:441 */
/*<       stattb=srd+dstat >*/
		    *stattb = static_cast<double>(wxprox_1.srd) + dstat;
/* SOURCE wspro.for:442 */
/*<       statr=srd+dstat >*/
		    *statr = static_cast<double>(wxprox_1.srd) + dstat;
/* SOURCE wspro.for:443 */
/*<       xfline(1)=xs-2.*xeps >*/
		    xfline[1] = static_cast<double>(xs) - static_cast<double>(xeps) * (float)2.;
/* SOURCE wspro.for:444 */
/*<       xfline(2)=xs-xeps >*/
		    xfline[2] = static_cast<double>(xs) - xeps;
/* SOURCE wspro.for:445 */
/*<       xfline(3)=xs >*/
		    xfline[3] = xs;
/* SOURCE wspro.for:446 */
/*<       xfline(4)=xe >*/
		    xfline[4] = xe;
/* SOURCE wspro.for:447 */
/*<       xfline(5)=xe+xeps >*/
		    xfline[5] = static_cast<double>(xe) + xeps;
/* SOURCE wspro.for:448 */
/*<       xfline(6)=xe+2.*xeps >*/
		    xfline[6] = static_cast<double>(xe) + static_cast<double>(xeps) * (float)2.;
/* SOURCE wspro.for:449 */
/*<       endif >*/
		}
/*             WSPRO cross section is defined here.  Convert the */
/*             description to FEQXEXT form and return. */
/*             Set the number of sub areas(subsections) */
/* SOURCE wspro.for:455 */
/*<       nsubu=nsa >*/
		*nsubu = wxprox_1.nsa;
/*             Establish the variation of n for each subsection. */
/* SOURCE wspro.for:458 */
/*<       if(nn.eq.nsa)then >*/
		if (wxprox_1.nn == wxprox_1.nsa) {
/*               n is constant in each subsection */
/* SOURCE wspro.for:460 */
/*<       do300i=1,nsa >*/
		    feq_gen_i_d_1 = wxprox_1.nsa;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:461 */
/*<       nvaru(i)=0 >*/
			nvaru[feq_gen_i_d_] = 0;
/* SOURCE wspro.for:462 */
/*<       nu(i)=nval(i) >*/
			nu[feq_gen_i_d_] = wxprox_1.nval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:463 */
/*<   300 continue >*/
/* L300: */
		    }
/* SOURCE wspro.for:464 */
/*<       ncon=1 >*/
		    *ncon = 1;
/* SOURCE wspro.for:465 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:466 */
/*<       ncon=0 >*/
		    *ncon = 0;
/*               n varies with hydraulic depth in each subsection */
/* SOURCE wspro.for:468 */
/*<       do305i=1,nsa >*/
		    feq_gen_i_d_1 = wxprox_1.nsa;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:469 */
/*<       nu(i)=nval(2*i-1) >*/
			nu[feq_gen_i_d_] = wxprox_1.nval[(feq_gen_i_d_ << 1) - 2];
/* SOURCE wspro.for:470 */
/*<       nvaru(i)=1 >*/
			nvaru[feq_gen_i_d_] = 1;
/* SOURCE wspro.for:471 */
/*<       nnyu(i)=3 >*/
			nnyu[feq_gen_i_d_] = 3;
/* SOURCE wspro.for:472 */
/*<       yatnu(1,i)=0.0 >*/
			yatnu[feq_gen_i_d_ * 9 + 1] = (float)0.;
/* SOURCE wspro.for:473 */
/*<       natyu(1,i)=botn(i) >*/
			natyu[feq_gen_i_d_ * 9 + 1] = wxprox_1.botn[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:474 */
/*<       yatnu(2,i)=botd(i) >*/
			yatnu[feq_gen_i_d_ * 9 + 2] = wxprox_1.botd[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:475 */
/*<       natyu(2,i)=botn(i) >*/
			natyu[feq_gen_i_d_ * 9 + 2] = wxprox_1.botn[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:476 */
/*<       yatnu(3,i)=topd(i) >*/
			yatnu[feq_gen_i_d_ * 9 + 3] = wxprox_1.topd[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:477 */
/*<       natyu(3,i)=topn(i) >*/
			natyu[feq_gen_i_d_ * 9 + 3] = wxprox_1.topn[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:478 */
/*<   305 continue >*/
/* L305: */
		    }
/* SOURCE wspro.for:479 */
/*<       endif >*/
		}
/*             Transfer the ground points */
/* SOURCE wspro.for:481 */
/*<       do307i=1,ngp >*/
		feq_gen_i_d_1 = wxprox_1.ngp;
		for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:482 */
/*<       xu(i)=x(i) >*/
		    xu[feq_gen_i_d_] = wxprox_1.x[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:483 */
/*<       zu(i)=y(i) >*/
		    zu[feq_gen_i_d_] = wxprox_1.y[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:484 */
/*<   307 continue >*/
/* L307: */
		}
/* SOURCE wspro.for:485 */
/*<       npntu=ngp >*/
		*npntu = wxprox_1.ngp;
/*             Add the points in XSA to the ground points if needed. */
/*             Set the sinuousity variation to 1 and leave off the */
/*             the first and last values in XARG to be consistent */
/*             with other usage.  Points are not added if they */
/*             exactly match a point already in the boundary */
/*             specification. */
/* SOURCE wspro.for:494 */
/*<       do310i=1,nsa-1 >*/
		feq_gen_i_d_1 = wxprox_1.nsa - 1;
		for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:495 */
/*<       xarg(i+1)=xsa(i) >*/
		    xarg[feq_gen_i_d_] = wxprox_1.xsa[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:496 */
/*<   310 continue >*/
/* L310: */
		}
/* SOURCE wspro.for:497 */
/*<       npi=nsa+1 >*/
		npi = wxprox_1.nsa + 1;
/* SOURCE wspro.for:498 */
/*<       callinspt(stdout,npi,xarg,1,npntu,xu,zu,sbu,lsnu,eflag) >*/
		inspt_(stdout, &npi, xarg, &feq_gen_c_d_1, npntu, &xu[1], &zu[1], &sbu[
			1], &lsnu[1], eflag);
/*             Assign the subsections to the ground points.  Add a */
/*             large offset to the end of XSA.  If no SA record */
/*             ever appears in the input NSAT is 0 and NSA becomes 1. */
/* SOURCE wspro.for:507 */
/*<       xsa(nsa)=-defalt >*/
		wxprox_1.xsa[wxprox_1.nsa - 1] = (float)1e30;
/* SOURCE wspro.for:508 */
/*<       j=1 >*/
		j = 1;
/* SOURCE wspro.for:509 */
/*<       do315i=1,npntu-1 >*/
		feq_gen_i_d_1 = *npntu - 1;
		for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:510 */
/*<       if(xu(i).lt.xsa(j))then >*/
		    if (xu[feq_gen_i_d_] < wxprox_1.xsa[j - 1]) {
/* SOURCE wspro.for:511 */
/*<       sbu(i)=j >*/
			sbu[feq_gen_i_d_] = j;
/* SOURCE wspro.for:512 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:513 */
/*<       j=j+1 >*/
			++j;
/* SOURCE wspro.for:514 */
/*<       sbu(i)=j >*/
			sbu[feq_gen_i_d_] = j;
/* SOURCE wspro.for:515 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:516 */
/*<   315 continue >*/
/* L315: */
		}
/* SOURCE wspro.for:517 */
/*<       sbu(npntu)=-1 >*/
		sbu[*npntu] = -1;
/*             Now, mark some cross section data flags as being */
/*             old input. */
/* SOURCE wspro.for:521 */
/*<       if(ndflag.eq.1)ndflag=2 >*/
		if (wxprox_1.ndflag == 1) {
		    wxprox_1.ndflag = 2;
		}
/* SOURCE wspro.for:522 */
/*<       if(nflag.eq.1)nflag=2 >*/
		if (wxprox_1.nflag == 1) {
		    wxprox_1.nflag = 2;
		}
/* SOURCE wspro.for:523 */
/*<       if(saflag.eq.1)saflag=2 >*/
		if (wxprox_1.saflag == 1) {
		    wxprox_1.saflag = 2;
		}
/* SOURCE wspro.for:524 */
/*<       if(grflag.eq.1)grflag=2 >*/
		if (wxprox_1.grflag == 1) {
		    wxprox_1.grflag = 2;
		}
/* SOURCE wspro.for:525 */
/*<       flflag=0 >*/
		wxprox_1.flflag = 0;
/* SOURCE wspro.for:526 */
/*<       nfl=0 >*/
		wxprox_1.nfl = 0;
/* SOURCE wspro.for:527 */
/*<       return >*/
		return 0;
/* SOURCE wspro.for:528 */
/*<       else >*/
	    } else {
/*             XT header here.  Transfer the user input to the template */
/*             section for later use. */
/* SOURCE wspro.for:531 */
/*<       if(grflag.eq.1)then >*/
		if (wxprox_1.grflag == 1) {
/*               Ground points have been input with the XT header */
/*               record.   Transfer them to the XT storage. */
/* SOURCE wspro.for:534 */
/*<       xtngp=ngp >*/
		    wxprox_1.xtngp = wxprox_1.ngp;
/* SOURCE wspro.for:535 */
/*<       do207i=1,ngp >*/
		    feq_gen_i_d_1 = wxprox_1.ngp;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:536 */
/*<       xtxgr(i)=xgr(i) >*/
			wxprox_1.xtxgr[feq_gen_i_d_ - 1] = wxprox_1.xgr[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:537 */
/*<       xtygr(i)=ygr(i) >*/
			wxprox_1.xtygr[feq_gen_i_d_ - 1] = wxprox_1.ygr[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:538 */
/*<   207 continue >*/
/* L207: */
		    }
/* SOURCE wspro.for:539 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:540 */
/*<       write(stdout,56) >*/
		    feq_gen_io_d__30.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__30);
		    e_wsfe();
/* SOURCE wspro.for:541 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE wspro.for:542 */
/*<       endif >*/
		}
/* SOURCE wspro.for:543 */
/*<       if(saflag.eq.1)then >*/
		if (wxprox_1.saflag == 1) {
/*               SA record has been input with XT. */
/* SOURCE wspro.for:545 */
/*<       xtnsa=nsat >*/
		    wxprox_1.xtnsa = wxprox_1.nsat;
/* SOURCE wspro.for:546 */
/*<       do208i=1,nsat >*/
		    feq_gen_i_d_1 = wxprox_1.nsat;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:547 */
/*<       xtxsa(i)=xsat(i) >*/
			wxprox_1.xtxsa[feq_gen_i_d_ - 1] = wxprox_1.xsat[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:548 */
/*<   208 continue >*/
/* L208: */
		    }
/* SOURCE wspro.for:549 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:550 */
/*<       xtnsa=0 >*/
		    wxprox_1.xtnsa = 0;
/* SOURCE wspro.for:551 */
/*<       endif >*/
		}
/*             Signal a fresh start for cross sections. */
/* SOURCE wspro.for:553 */
/*<       xflag=0 >*/
		*xflag = 0;
/* SOURCE wspro.for:554 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:555 */
/*<       elseif(cat.eq.header)then >*/
	} else if (cat == 1) {
/*           Remember the name */
/* SOURCE wspro.for:557 */
/*<       xsname=secid >*/
	    s_copy(xsname, secid, (ftnlen)5, (ftnlen)5);
/*           Get the values from the remainder of the record. */
/* SOURCE wspro.for:559 */
/*<       opt=0 >*/
	    opt = 0;
/* SOURCE wspro.for:560 */
/*<       do101i=1,mxnval >*/
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 40; ++feq_gen_i_d_) {
/* SOURCE wspro.for:561 */
/*<       type(i)=2 >*/
		feq_gen_type_d_[feq_gen_i_d_ - 1] = 2;
/*             Set the default value. */
/* SOURCE wspro.for:563 */
/*<       rval(i)=defalt >*/
		rval[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE wspro.for:564 */
/*<   101 continue >*/
/* L101: */
	    }
/*            CALL GETVAL */
/*     I                 (STDOUT, LINE(11:80), MXNVAL, OPT, */
/*     O                  TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG, */
/*     O                  NUMVAL) */
/* SOURCE wspro.for:570 */
/*<        >*/
	    getval_(stdout, line + 10, &feq_gen_c_d_40, &opt, feq_gen_type_d_, ival, rval, 
		    dpval, cval, clen, eflag, term, terml, termcls, &numval, (
		    ftnlen)70, (ftnlen)256, (ftnlen)1);
/* SOURCE wspro.for:576 */
/*<       if(numval.lt.1)then >*/
	    if (numval < 1) {
/* SOURCE wspro.for:577 */
/*<       write(stdout,52)secid >*/
		feq_gen_io_d__42.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__42);
		do_fio(&feq_gen_c_d_1, secid, (ftnlen)5);
		e_wsfe();
/* SOURCE wspro.for:578 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE wspro.for:579 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:581 */
/*<       headid=recid >*/
	    s_copy(headid, recid, (ftnlen)2, (ftnlen)2);
/* SOURCE wspro.for:582 */
/*<       srd=rval(1) >*/
	    wxprox_1.srd = rval[0];
/* SOURCE wspro.for:583 */
/*<       if(first.eq.1)then >*/
	    if (*first == 1) {
/*             Compute the change in station required. */
/* SOURCE wspro.for:585 */
/*<       dstat=stattb-srd >*/
		dstat = static_cast<double>(*stattb) - wxprox_1.srd;
/* SOURCE wspro.for:586 */
/*<       first=0 >*/
		*first = 0;
/* SOURCE wspro.for:587 */
/*<       endif >*/
	    }
/*           Process the header records of interest */
/* SOURCE wspro.for:589 */
/*<       if(recid.eq.'XS'.or.recid.eq.'AS'.or.recid.eq.'BR')then >*/
	    if (s_cmp(recid, const_cast<char*>("XS"), (ftnlen)2, (ftnlen)2) == 0 || s_cmp(recid, 
		    const_cast<char*>("AS"), (ftnlen)2, (ftnlen)2) == 0 || s_cmp(recid, const_cast<char*>("BR"), (
		    ftnlen)2, (ftnlen)2) == 0) {
/* SOURCE wspro.for:590 */
/*<       if(rval(2).gt.defalt)then >*/
		if (rval[1] > (float)-1e30) {
/* SOURCE wspro.for:591 */
/*<       skew=rval(2) >*/
		    wxprox_1.skew = rval[1];
/* SOURCE wspro.for:592 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:593 */
/*<       skew=0.0 >*/
		    wxprox_1.skew = (float)0.;
/* SOURCE wspro.for:594 */
/*<       endif >*/
		}
/* SOURCE wspro.for:595 */
/*<       if(rval(5).gt.defalt.and.recid.ne.'BR')then >*/
		if (rval[4] > (float)-1e30 && s_cmp(recid, const_cast<char*>("BR"), (ftnlen)2, (
			ftnlen)2) != 0) {
/* SOURCE wspro.for:596 */
/*<       vslope=rval(5) >*/
		    wxprox_1.vslope = rval[4];
/* SOURCE wspro.for:597 */
/*<       endif >*/
		}
/* SOURCE wspro.for:598 */
/*<       xflag=1 >*/
		*xflag = 1;
/* SOURCE wspro.for:599 */
/*<       elseif(recid.eq.'XT')then >*/
	    } else if (s_cmp(recid, const_cast<char*>("XT"), (ftnlen)2, (ftnlen)2) == 0) {
/*             Remember the station for the template. */
/* SOURCE wspro.for:601 */
/*<       xtsrd=srd >*/
		wxprox_1.xtsrd = wxprox_1.srd;
/* SOURCE wspro.for:602 */
/*<       if(rval(2).gt.defalt)then >*/
		if (rval[1] > (float)-1e30) {
/* SOURCE wspro.for:603 */
/*<       vslope=rval(2) >*/
		    wxprox_1.vslope = rval[1];
/* SOURCE wspro.for:604 */
/*<       endif >*/
		}
/* SOURCE wspro.for:605 */
/*<       xflag=1 >*/
		*xflag = 1;
/* SOURCE wspro.for:606 */
/*<       elseif(recid.eq.'XR')then >*/
	    } else if (s_cmp(recid, const_cast<char*>("XR"), (ftnlen)2, (ftnlen)2) == 0) {
/* SOURCE wspro.for:607 */
/*<       if(rval(5).gt.defalt)then >*/
		if (rval[4] > (float)-1e30) {
/* SOURCE wspro.for:608 */
/*<       skew=rval(5) >*/
		    wxprox_1.skew = rval[4];
/* SOURCE wspro.for:609 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:610 */
/*<       skew=0.0 >*/
		    wxprox_1.skew = (float)0.;
/* SOURCE wspro.for:611 */
/*<       endif >*/
		}
/* SOURCE wspro.for:612 */
/*<       xflag=1 >*/
		*xflag = 1;
/* SOURCE wspro.for:613 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:614 */
/*<       endif >*/
	}
/* SOURCE wspro.for:615 */
/*<       else >*/
    } else {
/* SOURCE wspro.for:616 */
/*<       if(xflag.eq.1)then >*/
	if (*xflag == 1) {
/*           Cross section data records here. Use subroutine GETVAL to */
/*           get the free-form portion of the record. */
/*           MXNVAL gives the maximun number of values that can be */
/*           returned.  GETOPT=1 has GETVAL return the variable */
/*           type found in the vector, TYPE.  NUMVAL gives the number of */
/*           values found including those given by dual commas or by */
/*           the asterisk place holder.  We set a standard value, not */
/*           expected in the input, into each of the four vectors, */
/*           IVAL-integer value, RVAL-real value, DPVAL-double precision */
/*           value, and CVAL-an identifier value.  Here we treat all values */
/*           as real.   GETVAL will complain if any item in the remainder */
/*           of LINE is not a number. */
/* SOURCE wspro.for:630 */
/*<       opt=0 >*/
	    opt = 0;
/* SOURCE wspro.for:631 */
/*<       do100i=1,mxnval >*/
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 40; ++feq_gen_i_d_) {
/* SOURCE wspro.for:632 */
/*<       type(i)=2 >*/
		feq_gen_type_d_[feq_gen_i_d_ - 1] = 2;
/*             Set the default value. */
/* SOURCE wspro.for:634 */
/*<       rval(i)=defalt >*/
		rval[feq_gen_i_d_ - 1] = (float)-1e30;
/* SOURCE wspro.for:635 */
/*<   100 continue >*/
/* L100: */
	    }
/*            CALL GETVAL */
/*     I                 (STDOUT, LINE(11:80), MXNVAL, OPT, */
/*     O                  TYPE, IVAL, RVAL, DPVAL, CVAL, CLEN, EFLAG, */
/*     O                  NUMVAL) */
/* SOURCE wspro.for:641 */
/*<        >*/
	    getval_(stdout, line + 10, &feq_gen_c_d_40, &opt, feq_gen_type_d_, ival, rval, 
		    dpval, cval, clen, eflag, term, terml, termcls, &numval, (
		    ftnlen)70, (ftnlen)256, (ftnlen)1);
/* SOURCE wspro.for:647 */
/*<       if(recid.eq.'GR')then >*/
	    if (s_cmp(recid, const_cast<char*>("GR"), (ftnlen)2, (ftnlen)2) == 0) {
/*             Number of values should be even. */
/* SOURCE wspro.for:649 */
/*<       if(mod(numval,2).ne.0)then >*/
		if (numval % 2 != 0) {
/* SOURCE wspro.for:650 */
/*<       write(stdout,51)numval >*/
		    feq_gen_io_d__43.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__43);
		    do_fio(&feq_gen_c_d_1, (char *)&numval, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE wspro.for:651 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE wspro.for:652 */
/*<       endif >*/
		}
/*             Ground point data.  Is this the first card or is */
/*             it a continuation card? */
/* SOURCE wspro.for:656 */
/*<       if(oldid.ne.'GR')then >*/
		if (s_cmp(oldid, const_cast<char*>("GR"), (ftnlen)2, (ftnlen)2) != 0) {
/*               This is the first card.  Set the ground point counter */
/*               and set the ground point data flag. */
/* SOURCE wspro.for:659 */
/*<       ngp=numval/2 >*/
		    wxprox_1.ngp = numval / 2;
/* SOURCE wspro.for:660 */
/*<       grflag=1 >*/
		    wxprox_1.grflag = 1;
/*               Remember the station of the GR data for use with VSLOPE */
/* SOURCE wspro.for:662 */
/*<       grsrd=srd >*/
		    wxprox_1.grsrd = wxprox_1.srd;
/* SOURCE wspro.for:664 */
/*<       do105i=1,ngp >*/
		    feq_gen_i_d_1 = wxprox_1.ngp;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:665 */
/*<       j=i+i >*/
			j = feq_gen_i_d_ + feq_gen_i_d_;
/* SOURCE wspro.for:666 */
/*<       ygr(i)=rval(j) >*/
			wxprox_1.ygr[feq_gen_i_d_ - 1] = rval[j - 1];
/* SOURCE wspro.for:667 */
/*<       xgr(i)=rval(j-1) >*/
			wxprox_1.xgr[feq_gen_i_d_ - 1] = rval[j - 2];
/* SOURCE wspro.for:668 */
/*<   105 continue >*/
/* L105: */
		    }
/* SOURCE wspro.for:669 */
/*<       else >*/
		} else {
/*               This is a continuation record.  Add */
/*               to the ground point information. */
/* SOURCE wspro.for:673 */
/*<       do110i=1,numval/2 >*/
		    feq_gen_i_d_1 = numval / 2;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:674 */
/*<       ngp=ngp+1 >*/
			++wxprox_1.ngp;
/* SOURCE wspro.for:675 */
/*<       j=i+i >*/
			j = feq_gen_i_d_ + feq_gen_i_d_;
/* SOURCE wspro.for:676 */
/*<       ygr(ngp)=rval(j) >*/
			wxprox_1.ygr[wxprox_1.ngp - 1] = rval[j - 1];
/* SOURCE wspro.for:677 */
/*<       xgr(ngp)=rval(j-1) >*/
			wxprox_1.xgr[wxprox_1.ngp - 1] = rval[j - 2];
/* SOURCE wspro.for:678 */
/*<   110 continue >*/
/* L110: */
		    }
/* SOURCE wspro.for:679 */
/*<       endif >*/
		}
/* SOURCE wspro.for:680 */
/*<       elseif(recid.eq.'N ')then >*/
	    } else if (s_cmp(recid, const_cast<char*>("N "), (ftnlen)2, (ftnlen)2) == 0) {
/*             Manning's n record. */
/* SOURCE wspro.for:682 */
/*<       if(oldid.ne.'N ')then >*/
		if (s_cmp(oldid, const_cast<char*>("N "), (ftnlen)2, (ftnlen)2) != 0) {
/*               This is the first record. */
/* SOURCE wspro.for:684 */
/*<       nn=numval >*/
		    wxprox_1.nn = numval;
/* SOURCE wspro.for:685 */
/*<       nflag=1 >*/
		    wxprox_1.nflag = 1;
/*               Not yet known what the values on the N record mean. */
/*               Place them in NVAL(*) for later processing. */
/* SOURCE wspro.for:688 */
/*<       do115i=1,numval >*/
		    feq_gen_i_d_1 = numval;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:689 */
/*<       nval(i)=rval(i) >*/
			wxprox_1.nval[feq_gen_i_d_ - 1] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:690 */
/*<   115 continue >*/
/* L115: */
		    }
/* SOURCE wspro.for:691 */
/*<       else >*/
		} else {
/*               This is a continuation record. */
/* SOURCE wspro.for:693 */
/*<       do120i=1,numval >*/
		    feq_gen_i_d_1 = numval;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:694 */
/*<       nn=nn+1 >*/
			++wxprox_1.nn;
/* SOURCE wspro.for:695 */
/*<       nval(nn)=rval(i) >*/
			wxprox_1.nval[wxprox_1.nn - 1] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:696 */
/*<   120 continue >*/
/* L120: */
		    }
/* SOURCE wspro.for:697 */
/*<       endif >*/
		}
/* SOURCE wspro.for:698 */
/*<       elseif(recid.eq.'ND')then >*/
	    } else if (s_cmp(recid, const_cast<char*>("ND"), (ftnlen)2, (ftnlen)2) == 0) {
/*             Depth breakpoints for vertical variation of n */
/* SOURCE wspro.for:700 */
/*<       if(oldid.ne.'ND')then >*/
		if (s_cmp(oldid, const_cast<char*>("ND"), (ftnlen)2, (ftnlen)2) != 0) {
/*               This is the first record. */
/* SOURCE wspro.for:702 */
/*<       nnd=numval >*/
		    wxprox_1.nnd = numval;
/* SOURCE wspro.for:703 */
/*<       ndflag=1 >*/
		    wxprox_1.ndflag = 1;
/*               Transfer and process later when all have been input. */
/* SOURCE wspro.for:705 */
/*<       do125i=1,numval >*/
		    feq_gen_i_d_1 = numval;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:706 */
/*<       nndbrk(i)=rval(i) >*/
			wxprox_1.nndbrk[feq_gen_i_d_ - 1] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:707 */
/*<   125 continue >*/
/* L125: */
		    }
/* SOURCE wspro.for:708 */
/*<       else >*/
		} else {
/*               This is a continuation record. */
/* SOURCE wspro.for:710 */
/*<       do130i=1,numval >*/
		    feq_gen_i_d_1 = numval;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:711 */
/*<       nnd=nnd+1 >*/
			++wxprox_1.nnd;
/* SOURCE wspro.for:712 */
/*<       nndbrk(nnd)=rval(i) >*/
			wxprox_1.nndbrk[wxprox_1.nnd - 1] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:713 */
/*<   130 continue >*/
/* L130: */
		    }
/* SOURCE wspro.for:714 */
/*<       endif >*/
		}
/* SOURCE wspro.for:715 */
/*<       elseif(recid.eq.'GT')then >*/
	    } else if (s_cmp(recid, const_cast<char*>("GT"), (ftnlen)2, (ftnlen)2) == 0) {
/*             Adjustment values for converting previous ground points */
/*             to the current ground points. */
/* SOURCE wspro.for:718 */
/*<       gtflag=1 >*/
		wxprox_1.gtflag = 1;
/* SOURCE wspro.for:719 */
/*<       yshift=rval(1) >*/
		wxprox_1.yshift = rval[0];
/* SOURCE wspro.for:720 */
/*<       if(rval(2).gt.defalt)then >*/
		if (rval[1] > (float)-1e30) {
/* SOURCE wspro.for:721 */
/*<       xliml=rval(2) >*/
		    wxprox_1.xliml = rval[1];
/* SOURCE wspro.for:722 */
/*<       endif >*/
		}
/* SOURCE wspro.for:723 */
/*<       if(rval(3).gt.defalt)then >*/
		if (rval[2] > (float)-1e30) {
/* SOURCE wspro.for:724 */
/*<       xlimr=rval(3) >*/
		    wxprox_1.xlimr = rval[2];
/* SOURCE wspro.for:725 */
/*<       endif >*/
		}
/* SOURCE wspro.for:726 */
/*<       if(rval(4).gt.defalt)then >*/
		if (rval[3] > (float)-1e30) {
/* SOURCE wspro.for:727 */
/*<       scale=rval(4) >*/
		    wxprox_1.scale = rval[3];
/* SOURCE wspro.for:728 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:729 */
/*<       scale=1.0 >*/
		    wxprox_1.scale = (float)1.;
/* SOURCE wspro.for:730 */
/*<       endif >*/
		}
/* SOURCE wspro.for:731 */
/*<       xorig=rval(5) >*/
		wxprox_1.xorig = rval[4];
/* SOURCE wspro.for:732 */
/*<       elseif(recid.eq.'SA')then >*/
	    } else if (s_cmp(recid, const_cast<char*>("SA"), (ftnlen)2, (ftnlen)2) == 0) {
/*             Subarea limits. */
/* SOURCE wspro.for:734 */
/*<       saflag=1 >*/
		wxprox_1.saflag = 1;
/* SOURCE wspro.for:735 */
/*<       if(oldid.ne.'SA')then >*/
		if (s_cmp(oldid, const_cast<char*>("SA"), (ftnlen)2, (ftnlen)2) != 0) {
/*               This is the first record.  Use NSAT as a counter and */
/*                 adjust later. Save in a temp location and make */
/*                 the selection of source later. */
/* SOURCE wspro.for:739 */
/*<       nsat=numval >*/
		    wxprox_1.nsat = numval;
/* SOURCE wspro.for:740 */
/*<       do135i=1,numval >*/
		    feq_gen_i_d_1 = numval;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:741 */
/*<       xsat(i)=rval(i) >*/
			wxprox_1.xsat[feq_gen_i_d_ - 1] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:742 */
/*<   135 continue >*/
/* L135: */
		    }
/* SOURCE wspro.for:743 */
/*<       else >*/
		} else {
/*               This is a continuation record. */
/* SOURCE wspro.for:745 */
/*<       do140i=1,numval >*/
		    feq_gen_i_d_1 = numval;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:746 */
/*<       nsat=nsat+1 >*/
			++wxprox_1.nsat;
/* SOURCE wspro.for:747 */
/*<       xsat(nsat)=rval(i) >*/
			wxprox_1.xsat[wxprox_1.nsat - 1] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:748 */
/*<   140 continue >*/
/* L140: */
		    }
/* SOURCE wspro.for:749 */
/*<       endif >*/
		}
/* SOURCE wspro.for:750 */
/*<       elseif(recid.eq.'FL')then >*/
	    } else if (s_cmp(recid, const_cast<char*>("FL"), (ftnlen)2, (ftnlen)2) == 0) {
/*             Flow line information.  Store information and process */
/*             when all data for a cross section is in hand. */
/* SOURCE wspro.for:753 */
/*<       flflag=1 >*/
		wxprox_1.flflag = 1;
/* SOURCE wspro.for:754 */
/*<       if(oldid.ne.'FL')then >*/
		if (s_cmp(oldid, const_cast<char*>("FL"), (ftnlen)2, (ftnlen)2) != 0) {
/*               First record. */
/* SOURCE wspro.for:756 */
/*<       nfl=numval >*/
		    wxprox_1.nfl = numval;
/* SOURCE wspro.for:757 */
/*<       do145i=1,numval >*/
		    feq_gen_i_d_1 = numval;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:758 */
/*<       fldat(i)=rval(i) >*/
			wxprox_1.fldat[feq_gen_i_d_ - 1] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:759 */
/*<   145 continue >*/
/* L145: */
		    }
/* SOURCE wspro.for:760 */
/*<       else >*/
		} else {
/*               This is a continuation record. */
/* SOURCE wspro.for:762 */
/*<       do150i=1,numval >*/
		    feq_gen_i_d_1 = numval;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:763 */
/*<       nfl=nfl+1 >*/
			++wxprox_1.nfl;
/* SOURCE wspro.for:764 */
/*<       fldat(nfl)=rval(i) >*/
			wxprox_1.fldat[wxprox_1.nfl - 1] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:765 */
/*<   150 continue >*/
/* L150: */
		    }
/* SOURCE wspro.for:766 */
/*<       endif >*/
		}
/* SOURCE wspro.for:767 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:768 */
/*<       endif >*/
	}
/* SOURCE wspro.for:769 */
/*<       endif >*/
    }
/* SOURCE wspro.for:771 */
/*<       oldid=recid >*/
    s_copy(oldid, recid, (ftnlen)2, (ftnlen)2);
/* SOURCE wspro.for:773 */
/*<       goto90 >*/
    goto L90;
/* SOURCE wspro.for:775 */
/*<       end >*/
} /* scnpro_ */




/* SOURCE wspro.for:779 */
/*<       subroutineproint() >*/
/* Subroutine */ int proint_()
{
/*     + + + PURPOSE + + + */
/*     Initialize the values in the WSPRO common block to */
/*     starting values. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE wspro.for:786 */
/*     Common block for the variables needed to process WSPRO */
/*     cross sections. */
/*     Parameters for dimensions */
/* SOURCE wsproxs.cmn:6 */
/*<       integermxnfl,mxngp,mxnsa >*/
/* SOURCE wsproxs.cmn:8 */
/*<       parameter(mxnfl=3,mxngp=100,mxnsa=20) >*/
/*     AS record variables */
/* SOURCE wsproxs.cmn:12 */
/*<       integerasflag >*/
/* SOURCE wsproxs.cmn:14 */
/*<       realsrd,skew,ek,ck,vslope >*/
/*     FL record variables */
/* SOURCE wsproxs.cmn:18 */
/*<       integerflflag,ihfno,nfl >*/
/* SOURCE wsproxs.cmn:20 */
/*<       realfldat(2*mxnfl),flen(mxnfl),xfl(mxnfl),yfl(mxnfl) >*/
/*     GR Record */
/* SOURCE wsproxs.cmn:24 */
/*<       integergrflag,ngp >*/
/* SOURCE wsproxs.cmn:26 */
/*<       realgrsrd,xgr(mxngp),ygr(mxngp),x(mxngp),y(mxngp) >*/
/*     GT Record */
/* SOURCE wsproxs.cmn:30 */
/*<       integergtflag >*/
/* SOURCE wsproxs.cmn:32 */
/*<       realyshift,xliml,xlimr,scale,xorig >*/
/*     N Record */
/* SOURCE wsproxs.cmn:36 */
/*<       integernflag,nn >*/
/* SOURCE wsproxs.cmn:38 */
/*<       realnval(2*mxnsa),botn(mxnsa),topn(mxnsa) >*/
/*     ND Record */
/* SOURCE wsproxs.cmn:42 */
/*<       integerndflag,nnd >*/
/* SOURCE wsproxs.cmn:44 */
/*<       realnndbrk(2*mxnsa),botd(mxnsa),topd(mxnsa) >*/
/*     SA Record */
/* SOURCE wsproxs.cmn:49 */
/*<       integersaflag,nsa,nsat >*/
/* SOURCE wsproxs.cmn:51 */
/*<       realxsa(mxnsa),xsat(mxnsa) >*/
/*     XR Record */
/* SOURCE wsproxs.cmn:55 */
/*<       integerxrflag,ipave >*/
/* SOURCE wsproxs.cmn:57 */
/*<       realembwid,usercf >*/
/*     XS Record */
/* SOURCE wsproxs.cmn:61 */
/*<       integerxsflag >*/
/*     XT Record */
/* SOURCE wsproxs.cmn:65 */
/*<       integerxtflag,xtngp,xtnsa >*/
/* SOURCE wsproxs.cmn:67 */
/*<       realxtsrd,xtxgr(mxngp),xtygr(mxngp),xtxsa(mxnsa) >*/
/* SOURCE wsproxs.cmn:69 */
/*<        >*/
/* *********************************************************************** */
/* SOURCE wspro.for:788 */
/*<       asflag=0 >*/
    wxprox_1.asflag = 0;
/* SOURCE wspro.for:789 */
/*<       flflag=0 >*/
    wxprox_1.flflag = 0;
/* SOURCE wspro.for:790 */
/*<       grflag=0 >*/
    wxprox_1.grflag = 0;
/* SOURCE wspro.for:791 */
/*<       gtflag=0 >*/
    wxprox_1.gtflag = 0;
/* SOURCE wspro.for:792 */
/*<       nflag=0 >*/
    wxprox_1.nflag = 0;
/* SOURCE wspro.for:793 */
/*<       ndflag=0 >*/
    wxprox_1.ndflag = 0;
/* SOURCE wspro.for:794 */
/*<       saflag=0 >*/
    wxprox_1.saflag = 0;
/* SOURCE wspro.for:795 */
/*<       xrflag=0 >*/
    wxprox_1.xrflag = 0;
/* SOURCE wspro.for:796 */
/*<       xsflag=0 >*/
    wxprox_1.xsflag = 0;
/* SOURCE wspro.for:797 */
/*<       xtflag=0 >*/
    wxprox_1.xtflag = 0;
/* SOURCE wspro.for:798 */
/*<       nsat=0 >*/
    wxprox_1.nsat = 0;
/* SOURCE wspro.for:799 */
/*<       nsa=0 >*/
    wxprox_1.nsa = 0;
/* SOURCE wspro.for:800 */
/*<       nfl=0 >*/
    wxprox_1.nfl = 0;
/* SOURCE wspro.for:801 */
/*<       xtnsa=0 >*/
    wxprox_1.xtnsa = 0;
/* SOURCE wspro.for:802 */
/*<       return >*/
    return 0;
/* SOURCE wspro.for:803 */
/*<       end >*/
} /* proint_ */




/* SOURCE wspro.for:807 */
/*<       subroutinewpro14(stdin,stdout,stdtab,tabdir,eflag) >*/
/* Subroutine */ int wpro14_(integer *stdin, integer *stdout, integer *stdtab,
	 integer *feq_storage_tabdir, integer *eflag)
{
    /* Format strings */
    static char fmt_2[] = "(6x,a)";
    static char fmt_3[] = "(a)";
    static char fmt_24[] = "(a80)";
    static char fmt_25[] = "(4x,5x,13x,f8.0,f8.0)";
    static char fmt_50[] = "(/,\002 Table id for 2-D table of type 14= \002,\
a)";
    static char fmt_51[] = "(/,\002 Label for 2-D table: \002,a)";
    static char fmt_54[] = "(/,\002 \002,a80)";
    static char fmt_56[] = "(\002 Current file name is:\002,a)";
    static char fmt_58[] = "(/,\002 *ERR:519* Expected Q card but found:\002\
,a2)";
    static char fmt_60[] = "(/,\002 *WRN:510* Froude number=\002,f7.2,\002 >\
 1.0 at XSID=\002,a5)";
    static char fmt_62[] = "(\002 Not enough user tables.  One or more profi\
les\002,\002 failed in WSPRO.\002)";
    static char fmt_96[] = "(/,\002 FILE NAMED:\002,a,\002 NOT FOUND.  CHECK\
 SPELLING OF\002,\002 FILE NAME.\002)";
    static char fmt_98[] = "(/,\002 Found \002,i3,\002 downstream elevations\
 and \002,i3,\002 partial maximum flows.\002)";
    static char fmt_99[] = "(/,\002 All files have been processed.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[5];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, ftnlen, ftnlen)
	    , f_inqu(inlist *), f_open(olist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsfe(cilist *), e_rsfe(), i_indx(char *, char *, ftnlen, ftnlen)
	    , s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen),
	     e_rsli(), s_wsle(cilist *), e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_clos(cllist *);

    /* Local variables */
    doublereal northing;
    integer feq_gen_i_d_;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_q(53001);
    real *q = feq_heap_q.data()	/* was [151][351] */;
    integer it;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    integer tab, nzd, knt, opt, nzd2;
    char head[80];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char feq_gen_name_d_[64];
    integer clen[16];
    char cval[256*16], line[80];
    integer ival[16], mval, nzdf;
    real rval[16];
    integer nzdl;
    real maxq, wsel;
    char term[1*16], xsid[5], zone[8];
    integer feq_gen_type_d_[16];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char line1[81], label[50], tabid[16];
    integer nfrac;
    real hdvec[151];
    char hgrid[8], basis[8];
    real qfvec[151];
    integer terml[16];
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_humat(53001);
    real *humat = feq_heap_humat.data()	/* was [151][351] */;
    doublereal dpval[16];
    logical there;
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen), tabchk_(
	    integer *, integer *, integer *, integer *, integer *), inline_(
	    integer *, integer *, char *, ftnlen), feq_gen_maybe_add_home_d_(char *, 
	    ftnlen);
    real hdatum;
    extern /* Subroutine */ int getval_(integer *, char *, integer *, integer 
	    *, integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    real froude, pfqvec[351], zrhufd;
    char vdatum[8];
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int twdout_(integer *, integer *, integer *, char 
	    *, integer *, integer *, real *, real *, real *, real *, real *, 
	    integer *, char *, real *, char *, char *, char *, char *, char *,
	     doublereal *, doublereal *, integer *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), feq_gen_get_lctn_items_d_(integer *, 
	    integer *, integer *), feq_gen_set_lctn_items_d_(char *, char *, char *, 
	    char *, char *, doublereal *, doublereal *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen), inlineb_(integer *, integer *, char *, 
	    ftnlen);
    doublereal easting;
    integer termcls[16];
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__50 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__67 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__69 = { 0, 0, 1, fmt_24, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__92 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 1, fmt_24, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Construct a table of type 14 from one or more .prt files from */
/*     WSPRO.  These files will have user specified output that will */
/*     contain the values needed and in the proper order.  The */
/*     order is established by the WSPROQZ command implemented in */
/*     subroutine WPROQZ. */
/* SOURCE wspro.for:818 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE wspro.for:821 */
/*<       integereflag,stdin,stdout,stdtab >*/
/* SOURCE wspro.for:822 */
/*<       integertabdir(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE wspro.for:832 */
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
/* INCLUDE wspro.for:833 */
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
/* INCLUDE wspro.for:834 */
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
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE wspro.for:837 */
/*<       integermaxn >*/
/* SOURCE wspro.for:838 */
/*<       parameter(maxn=16) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE wspro.for:841 */
/*<       integeri,it,knt,mval,nfrac,nzd,nzd2,nzdf,nzdl,opt,tab >*/
/* SOURCE wspro.for:842 */
/*<       integerclen(maxn),ival(maxn),terml(maxn),termcls(maxn),type(maxn) >*/
/* SOURCE wspro.for:844 */
/*<        >*/
/* SOURCE wspro.for:847 */
/*<       real*8dpval(maxn),easting,northing >*/
/* SOURCE wspro.for:849 */
/*<        >*/
/* SOURCE wspro.for:853 */
/*<       logicalthere >*/
/* SOURCE wspro.for:855 */
/*<       charactergettok*5,tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE wspro.for:858 */
/*<       externalgettok,getval,inline,tabchk,twdout,os_file_style >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE wspro.for:861 */
/*<     1 format(7x,i5) >*/
/* SOURCE wspro.for:862 */
/*<     2 format(6x,a) >*/
/* SOURCE wspro.for:863 */
/*<     3 format(a) >*/
/* SOURCE wspro.for:864 */
/*<    24 format(a80) >*/
/* SOURCE wspro.for:865 */
/*<    25 format(4x,5x,13x,f8.0,f8.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE wspro.for:868 */
/*<    50 format(/,' Table id for 2-D table of type 14= ',a) >*/
/* SOURCE wspro.for:869 */
/*<    51 format(/,' Label for 2-D table: ',a) >*/
/* SOURCE wspro.for:870 */
/*<    54 format(/,' ',a80) >*/
/* SOURCE wspro.for:871 */
/*<    56 format(' Current file name is:',a) >*/
/* SOURCE wspro.for:872 */
/*<    58 format(/,' *ERR:519* Expected Q card but found:',a2) >*/
/* SOURCE wspro.for:873 */
/*<    60 format(/,' *WRN:510* Froude number=',f7.2,' > 1.0 at XSID=',a5) >*/
/* SOURCE wspro.for:874 */
/*<    62  >*/
/* SOURCE wspro.for:876 */
/*<    96  >*/
/* SOURCE wspro.for:878 */
/*<    98  >*/
/* SOURCE wspro.for:880 */
/*<    99 format(/,' All files have been processed.') >*/
/* *********************************************************************** */
/*     Get the table number to be used by the two-D table. */
/* SOURCE wspro.for:883 */
/*<       callinline(stdin,stdout,line) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L3: */
/* L24: */
/* L25: */
/* L50: */
/* L51: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L96: */
/* L98: */
/* L99: */
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:886 */
/*<       callread_tabid(stdout,line,'TAB',eflag,tabid,tab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("TAB"), eflag, tabid, &tab, (ftnlen)80, (ftnlen)
	    3, (ftnlen)16);
/*      READ(LINE,1,ERR=991) TABID */
/* SOURCE wspro.for:890 */
/*<       write(stdout,50)tabid >*/
    feq_gen_io_d__50.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__50);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    e_wsfe();
/* SOURCE wspro.for:891 */
/*<       calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE wspro.for:898 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE wspro.for:900 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     Get the label for the 2-D table. */
/* SOURCE wspro.for:906 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:909 */
/*<       read(line,2,err=991)label >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:910 */
/*<       write(stdout,51)label >*/
    feq_gen_io_d__59.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__59);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/* SOURCE wspro.for:912 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:915 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
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
/* SOURCE wspro.for:916 */
/*<       write(stdout,54)head >*/
    feq_gen_io_d__61.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__61);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/*     Input each file name and process in order. */
/*     Each file must have a descriptive header that agrees exactly with */
/*     its contents.  This means that each file must represent a */
/*     complete series of flows for a given downstream head.  The downstream */
/*     heads must be presented in increasing order and the flows */
/*     must be presented in increasing order.   Zero flow is not included */
/*     in any of the files because the result for zero flow is trivial. */
/*     Initialize the global number of zero depths counter */
/* SOURCE wspro.for:927 */
/*<       nzd=1 >*/
    nzd = 1;
/* SOURCE wspro.for:928 */
/*<       nzd2=1 >*/
    nzd2 = 1;
/* SOURCE wspro.for:929 */
/*<   100 continue >*/
L100:
/* SOURCE wspro.for:930 */
/*<       callinlineb(stdin,stdout,line) >*/
    inlineb_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:933 */
/*<       read(line,3,err=991)name >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_3;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)64);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:935 */
/*<       if(name.ne.' ')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), (ftnlen)64, (ftnlen)1) != 0) {
/* SOURCE wspro.for:936 */
/*<       callmaybe_add_home(name) >*/
	feq_gen_maybe_add_home_d_(feq_gen_name_d_, (ftnlen)64);
/* SOURCE wspro.for:939 */
/*<       callos_file_style(name) >*/
	feq_gen_os_file_style_d_(feq_gen_name_d_, (ftnlen)64);
/* SOURCE wspro.for:941 */
/*<       inquire(file=name,exist=there) >*/
	feq_gen_ioin_d_1.inerr = 0;
	feq_gen_ioin_d_1.infilen = 64;
	feq_gen_ioin_d_1.infile = feq_gen_name_d_;
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
/* SOURCE wspro.for:942 */
/*<       if(there)then >*/
	if (there) {
/* SOURCE wspro.for:943 */
/*<       write(stdout,56)name >*/
	    feq_gen_io_d__66.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__66);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)64);
	    e_wsfe();
/* SOURCE wspro.for:944 */
/*<       open(unit=std48,file=name,status='OLD') >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std48;
	    feq_gen_o_d_1.ofnmlen = 64;
	    feq_gen_o_d_1.ofnm = feq_gen_name_d_;
	    feq_gen_o_d_1.orl = 0;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = 0;
	    feq_gen_o_d_1.ofm = 0;
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE wspro.for:945 */
/*<       else >*/
	} else {
/* SOURCE wspro.for:946 */
/*<       write(stdout,96)name >*/
	    feq_gen_io_d__67.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__67);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)64);
	    e_wsfe();
/* SOURCE wspro.for:947 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:948 */
/*<       endif >*/
	}
/*         Initialize the local number of zero depths counter. */
/* SOURCE wspro.for:951 */
/*<       nzdl=1 >*/
	nzdl = 1;
/* SOURCE wspro.for:952 */
/*<   200 continue >*/
L200:
/* SOURCE wspro.for:953 */
/*<       read(std48,24,end=900)line >*/
	feq_gen_io_d__69.ciunit = feq_gen_stdun_com_d_1.std48;
	feq_gen_i_d_1 = s_rsfe(&feq_gen_io_d__69);
	if (feq_gen_i_d_1 != 0) {
	    goto L900;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	if (feq_gen_i_d_1 != 0) {
	    goto L900;
	}
	feq_gen_i_d_1 = e_rsfe();
	if (feq_gen_i_d_1 != 0) {
	    goto L900;
	}
/* SOURCE wspro.for:954 */
/*<       if(line(14:20).eq.'WSPROZQ')then >*/
	if (s_cmp(line + 13, const_cast<char*>("WSPROZQ"), (ftnlen)7, (ftnlen)7) == 0) {
/*             Found the standard header line.  Read the number of flows, */
/*             number of downstream elevations, and the head datum. */
/* SOURCE wspro.for:957 */
/*<       read(line,'(40X,I5,5X,I5,8X,F10.0)')nfrac,nzdf,hdatum >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(40X,I5,5X,I5,8X,F10.0)");
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nzdf, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
	    e_rsfi();
/*              WRITE(STDOUT,*) ' NFRAC=',NFRAC, ' NZDF=',NZDF, */
/*     A                ' HDATUM=',HDATUM */
/*             Skip over the two lines defining the user output. */
/* SOURCE wspro.for:962 */
/*<       read(std48,24)line >*/
	    feq_gen_io_d__73.ciunit = feq_gen_stdun_com_d_1.std48;
	    s_rsfe(&feq_gen_io_d__73);
	    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	    e_rsfe();
/* SOURCE wspro.for:963 */
/*<       read(std48,24)line >*/
	    feq_gen_io_d__74.ciunit = feq_gen_stdun_com_d_1.std48;
	    s_rsfe(&feq_gen_io_d__74);
	    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	    e_rsfe();
/*             Set GETVAL to get the number of values and return the */
/*             types.  Types must be self defining.  That is, a real */
/*             value must have a decimal point. */
/* SOURCE wspro.for:968 */
/*<       opt=1 >*/
	    opt = 1;
/* SOURCE wspro.for:969 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE wspro.for:970 */
/*<   300 continue >*/
L300:
/* SOURCE wspro.for:971 */
/*<       read(std48,24)line1 >*/
	    feq_gen_io_d__77.ciunit = feq_gen_stdun_com_d_1.std48;
	    s_rsfe(&feq_gen_io_d__77);
	    do_fio(&feq_gen_c_d_1, line1, (ftnlen)81);
	    e_rsfe();
/*               Search for user quote */
/* SOURCE wspro.for:973 */
/*<       it=index(line1,'''') >*/
	    it = i_indx(line1, const_cast<char*>("'"), (ftnlen)81, (ftnlen)1);
/* SOURCE wspro.for:974 */
/*<       if(it.eq.0)then >*/
	    if (it == 0) {
/* SOURCE wspro.for:975 */
/*<       line1(81:81)='''' >*/
		*(unsigned char *)&line1[80] = '\'';
/* SOURCE wspro.for:976 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:978 */
/*<        >*/
	    getval_(stdout, line1, &feq_gen_c_d_16, &opt, feq_gen_type_d_, ival, rval, dpval, 
		    cval, clen, eflag, term, terml, termcls, &mval, (ftnlen)
		    81, (ftnlen)256, (ftnlen)1);
/* SOURCE wspro.for:983 */
/*<       do310i=2,mval >*/
	    feq_gen_i_d_1 = mval;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:984 */
/*<       read(cval(i)(1:clen(i)),*)rval(i) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ - 1];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ - 1 << 8);
		feq_gen_ici_d_1.icifmt = 0;
		s_rsli(&feq_gen_ici_d_1);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_ - 1], (ftnlen)sizeof(
			real));
		e_rsli();
/* SOURCE wspro.for:985 */
/*<   310 continue >*/
/* L310: */
	    }
/* SOURCE wspro.for:986 */
/*<       if(cval(1)(1:1).eq.'Q')then >*/
	    if (*(unsigned char *)&cval[0] == 'Q') {
/*                 Flow definition. */
/* SOURCE wspro.for:988 */
/*<       do400i=2,mval >*/
		feq_gen_i_d_1 = mval;
		for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:989 */
/*<       knt=knt+1 >*/
		    ++knt;
/* SOURCE wspro.for:990 */
/*<       q(nzd,knt)=rval(i) >*/
		    q[nzd + knt * 151 - 152] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:991 */
/*<       if(knt.eq.nfrac)then >*/
		    if (knt == nfrac) {
/*                     Current downstream depth is complete. */
/* SOURCE wspro.for:993 */
/*<       nzd=nzd+1 >*/
			++nzd;
/* SOURCE wspro.for:994 */
/*<       nzdl=nzdl+1 >*/
			++nzdl;
/* SOURCE wspro.for:995 */
/*<       knt=0 >*/
			knt = 0;
/* SOURCE wspro.for:996 */
/*<       if(nzdl.gt.nzdf)then >*/
			if (nzdl > nzdf) {
/*                       Flows from the current file have been completed. */
/* SOURCE wspro.for:998 */
/*<       nzdl=1 >*/
			    nzdl = 1;
/* SOURCE wspro.for:999 */
/*<       write(stdout,*)' Flows completed' >*/
			    feq_gen_io_d__92.ciunit = *stdout;
			    s_wsle(&feq_gen_io_d__92);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Flows completed"), (ftnlen)
				    16);
			    e_wsle();
/* SOURCE wspro.for:1000 */
/*<       goto401 >*/
			    goto L401;
/* SOURCE wspro.for:1001 */
/*<       endif >*/
			}
/* SOURCE wspro.for:1002 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:1003 */
/*<   400 continue >*/
/* L400: */
		}
/* SOURCE wspro.for:1004 */
/*<       else >*/
	    } else {
/* SOURCE wspro.for:1005 */
/*<       write(stdout,58)cval(1)(1:2) >*/
		feq_gen_io_d__93.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__93);
		do_fio(&feq_gen_c_d_1, cval, (ftnlen)2);
		e_wsfe();
/* SOURCE wspro.for:1006 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE wspro.for:1007 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:1008 */
/*<       goto300 >*/
	    goto L300;
/* SOURCE wspro.for:1009 */
/*<   401 continue >*/
L401:
/*             Now look for the string heading the user output. */
/* SOURCE wspro.for:1013 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE wspro.for:1014 */
/*<       nzdl=1 >*/
	    nzdl = 1;
/* SOURCE wspro.for:1015 */
/*<   500 continue >*/
L500:
/* SOURCE wspro.for:1016 */
/*<       read(std48,24,end=910)line >*/
	    feq_gen_io_d__94.ciunit = feq_gen_stdun_com_d_1.std48;
	    feq_gen_i_d_1 = s_rsfe(&feq_gen_io_d__94);
	    if (feq_gen_i_d_1 != 0) {
		goto L910;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	    if (feq_gen_i_d_1 != 0) {
		goto L910;
	    }
	    feq_gen_i_d_1 = e_rsfe();
	    if (feq_gen_i_d_1 != 0) {
		goto L910;
	    }
/* SOURCE wspro.for:1017 */
/*<       if(line(4:13).eq.'FIRST USER')then >*/
	    if (s_cmp(line + 3, const_cast<char*>("FIRST USER"), (ftnlen)10, (ftnlen)10) == 0) {
/*                  WRITE(STDOUT,*) ' FOUND: FIRST USER' */
/*                 Found the line.  Skip over the blank line and heading. */
/* SOURCE wspro.for:1020 */
/*<       read(std48,24)line >*/
		feq_gen_io_d__95.ciunit = feq_gen_stdun_com_d_1.std48;
		s_rsfe(&feq_gen_io_d__95);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		e_rsfe();
/* SOURCE wspro.for:1021 */
/*<       read(std48,24)line >*/
		feq_gen_io_d__96.ciunit = feq_gen_stdun_com_d_1.std48;
		s_rsfe(&feq_gen_io_d__96);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		e_rsfe();
/*                 Read the output lines, and check the Froude number. */
/*                 The downstream elevation is in the line with cross */
/*                 section id EXIT and the upstream elevation is in the */
/*                 line with cross section id APPRO. */
/* SOURCE wspro.for:1026 */
/*<   600 continue >*/
L600:
/* SOURCE wspro.for:1027 */
/*<       read(std48,'(A)')line >*/
		feq_gen_ci_d_1.cierr = 0;
		feq_gen_ci_d_1.ciend = 0;
		feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std48;
		feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
		s_rsfe(&feq_gen_ci_d_1);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		e_rsfe();
/* SOURCE wspro.for:1028 */
/*<       xsid=line(5:9) >*/
		s_copy(xsid, line + 4, (ftnlen)5, (ftnlen)5);
/* SOURCE wspro.for:1029 */
/*<       xsid=gettok(xsid) >*/
		gettok_(feq_gen_ch_d_1, (ftnlen)5, xsid, (ftnlen)5);
		s_copy(xsid, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE wspro.for:1030 */
/*<       if(xsid.eq.'EXIT'.or.xsid.eq.'APPRO')then >*/
		if (s_cmp(xsid, const_cast<char*>("EXIT"), (ftnlen)5, (ftnlen)4) == 0 || s_cmp(
			xsid, const_cast<char*>("APPRO"), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE wspro.for:1031 */
/*<       read(line,25)froude,wsel >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.iciend = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 80;
		    feq_gen_ici_d_1.iciunit = line;
		    feq_gen_ici_d_1.icifmt = fmt_25;
		    s_rsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&froude, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&wsel, (ftnlen)sizeof(real));
		    e_rsfi();
/* SOURCE wspro.for:1032 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:1033 */
/*<       froude=0.0 >*/
		    froude = (float)0.;
/* SOURCE wspro.for:1034 */
/*<       wsel=0.0 >*/
		    wsel = (float)0.;
/* SOURCE wspro.for:1035 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1036 */
/*<       if(froude.gt.1.0)then >*/
		if (froude > (float)1.) {
/* SOURCE wspro.for:1037 */
/*<       write(stdout,60)froude,xsid >*/
		    feq_gen_io_d__100.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__100);
		    do_fio(&feq_gen_c_d_1, (char *)&froude, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, xsid, (ftnlen)5);
		    e_wsfe();
/* SOURCE wspro.for:1038 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1039 */
/*<       if(xsid.eq.'EXIT')then >*/
		if (s_cmp(xsid, const_cast<char*>("EXIT"), (ftnlen)5, (ftnlen)4) == 0) {
/*                     Remember the downstream depth.  Note that this */
/*                     statement is executed NZDF times with the */
/*                     same water surface elevation. */
/* SOURCE wspro.for:1044 */
/*<       hdvec(nzd2)=wsel-hdatum >*/
		    hdvec[nzd2 - 1] = static_cast<double>(wsel) - hdatum;
/* SOURCE wspro.for:1045 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1046 */
/*<       if(xsid.eq.'APPRO')then >*/
		if (s_cmp(xsid, const_cast<char*>("APPRO"), (ftnlen)5, (ftnlen)5) == 0) {
/*                     Get the upstream elevation and save it. */
/* SOURCE wspro.for:1048 */
/*<       knt=knt+1 >*/
		    ++knt;
/*                     Leave space for zero fraction of free flow */
/*                     by adding one to KNT when storing the upstream */
/*                     heads.  Required by TWDOUT. */
/* SOURCE wspro.for:1052 */
/*<       humat(nzd2,knt+1)=wsel-hdatum >*/
		    humat[nzd2 + (knt + 1) * 151 - 152] = static_cast<double>(wsel) - hdatum;
/* SOURCE wspro.for:1053 */
/*<       if(knt.eq.nfrac)then >*/
		    if (knt == nfrac) {
/*                       The current downstream elevation's flows are */
/*                       complete. */
/* SOURCE wspro.for:1056 */
/*<       nzd2=nzd2+1 >*/
			++nzd2;
/* SOURCE wspro.for:1057 */
/*<       nzdl=nzdl+1 >*/
			++nzdl;
/* SOURCE wspro.for:1058 */
/*<       knt=0 >*/
			knt = 0;
/* SOURCE wspro.for:1059 */
/*<       if(nzdl.gt.nzdf)then >*/
			if (nzdl > nzdf) {
/*                         Current file is processed. */
/* SOURCE wspro.for:1061 */
/*<       nzdl=1 >*/
			    nzdl = 1;
/* SOURCE wspro.for:1062 */
/*<       goto101 >*/
			    goto L101;
/* SOURCE wspro.for:1063 */
/*<       endif >*/
			}
/* SOURCE wspro.for:1064 */
/*<       endif >*/
		    }
/*                     APPRO is the last line of interest in the current */
/*                     user output. */
/* SOURCE wspro.for:1067 */
/*<       goto601 >*/
		    goto L601;
/* SOURCE wspro.for:1068 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1069 */
/*<       goto600 >*/
		goto L600;
/* SOURCE wspro.for:1070 */
/*<   601 continue >*/
L601:
/* SOURCE wspro.for:1071 */
/*<       endif >*/
		;
	    }
/* SOURCE wspro.for:1072 */
/*<       goto500 >*/
	    goto L500;
/* SOURCE wspro.for:1073 */
/*<       else >*/
	} else {
/* SOURCE wspro.for:1074 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE wspro.for:1075 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1076 */
/*<   101 continue >*/
L101:
/* SOURCE wspro.for:1077 */
/*<       close(std48) >*/
	feq_gen_cl_d_1.cerr = 0;
	feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std48;
	feq_gen_cl_d_1.csta = 0;
	f_clos(&feq_gen_cl_d_1);
/* SOURCE wspro.for:1078 */
/*<       goto100 >*/
	goto L100;
/* SOURCE wspro.for:1079 */
/*<       endif >*/
    }
/*     All the files have been processed. */
/* SOURCE wspro.for:1082 */
/*<       write(stdout,99) >*/
    feq_gen_io_d__103.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__103);
    e_wsfe();
/* SOURCE wspro.for:1083 */
/*<       nzd=nzd-1 >*/
    --nzd;
/* SOURCE wspro.for:1084 */
/*<       nzd2=nzd2-1 >*/
    --nzd2;
/* SOURCE wspro.for:1085 */
/*<       write(stdout,98)nzd,nfrac >*/
    feq_gen_io_d__104.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__104);
    do_fio(&feq_gen_c_d_1, (char *)&nzd, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
    e_wsfe();
/*     Extract the maximum flows. */
/* SOURCE wspro.for:1087 */
/*<       do700i=1,nzd >*/
    feq_gen_i_d_1 = nzd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1088 */
/*<       qfvec(i)=q(i,nfrac) >*/
	qfvec[feq_gen_i_d_ - 1] = q[feq_gen_i_d_ + nfrac * 151 - 152];
/* SOURCE wspro.for:1089 */
/*<   700 continue >*/
/* L700: */
    }
/*     Compute the partial free flows.  Add the zero point. */
/* SOURCE wspro.for:1092 */
/*<       pfqvec(1)=0.0 >*/
    pfqvec[0] = (float)0.;
/* SOURCE wspro.for:1093 */
/*<       maxq=q(nzd,nfrac) >*/
    maxq = q[nzd + nfrac * 151 - 152];
/* SOURCE wspro.for:1094 */
/*<       do800i=1,nfrac >*/
    feq_gen_i_d_1 = nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1095 */
/*<       pfqvec(i+1)=q(nzd,i)/maxq >*/
	pfqvec[feq_gen_i_d_] = static_cast<double>(q[nzd + feq_gen_i_d_ * 151 - 152]) / maxq;
/* SOURCE wspro.for:1096 */
/*<   800 continue >*/
/* L800: */
    }
/* SOURCE wspro.for:1097 */
/*<       nfrac=nfrac+1 >*/
    ++nfrac;
/* SOURCE wspro.for:1098 */
/*<       zrhufd=0.0 >*/
    zrhufd = (float)0.;
/* SOURCE wspro.for:1099 */
/*<        >*/
    twdout_(stdout, stdtab, &tab, label, &nzd, &nfrac, qfvec, hdvec, pfqvec, 
	    humat, &hdatum, &feq_gen_c_d_14, const_cast<char*>("   WSPRO"), &zrhufd, zone, hgrid, vdatum, 
	    unitsys, basis, &easting, &northing, eflag, (ftnlen)50, (ftnlen)8,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE wspro.for:1107 */
/*<       return >*/
    return 0;
/* SOURCE wspro.for:1108 */
/*<   900 continue >*/
L900:
/* SOURCE wspro.for:1109 */
/*<       write(stdout,*)' END OF FILE SEEKING WSPROZQ HEADER' >*/
    feq_gen_io_d__109.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__109);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" END OF FILE SEEKING WSPROZQ HEADER"), (ftnlen)35);
    e_wsle();
/* SOURCE wspro.for:1110 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:1112 */
/*<   910 continue >*/
L910:
/* SOURCE wspro.for:1113 */
/*<       write(stdout,*)' End of file seeking "FIRST USER"' >*/
    feq_gen_io_d__110.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__110);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" End of file seeking \"FIRST USER\""), (ftnlen)33);
    e_wsle();
/* SOURCE wspro.for:1114 */
/*<       write(stdout,62) >*/
    feq_gen_io_d__111.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__111);
    e_wsfe();
/* SOURCE wspro.for:1115 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:1116 */
/*<   991 continue >*/
L991:
/* SOURCE wspro.for:1117 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__112.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__112);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE wspro.for:1118 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__113.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__113);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE wspro.for:1119 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:1121 */
/*<       end >*/
    return 0;
} /* wpro14_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE wspro.for:1125 */
/*<       subroutinewpro14_new(stdin,stdout,stdtab,tabdir,eflag) >*/
/* Subroutine */ int feq_gen_wpro14_new_d_(integer *stdin, integer *stdout, integer *
	stdtab, integer *feq_storage_tabdir, integer *eflag)
{
    /* Format strings */
    static char fmt_2[] = "(6x,a)";
    static char fmt_3[] = "(a)";
    static char fmt_24[] = "(a80)";
    static char fmt_25[] = "(20x,f10.0,f10.0)";
    static char fmt_50[] = "(/,\002 Table id for 2-D table of type 14= \002,\
a)";
    static char fmt_51[] = "(/,\002 Label for 2-D table: \002,a)";
    static char fmt_54[] = "(/,\002 \002,a80)";
    static char fmt_56[] = "(\002 Current file name is:\002,a)";
    static char fmt_58[] = "(/,\002 *ERR:519* Expected Q card but found:\002\
,a2)";
    static char fmt_60[] = "(/,\002 *WRN:510* Froude number=\002,f7.2,\002 >\
 1.0 at XSID=\002,a7)";
    static char fmt_62[] = "(\002 Not enough user tables.  One or more profi\
les\002,\002 failed in WSPRO.\002)";
    static char fmt_64[] = "(/,\002 *ERR:760* One or more of ERROR or FATA\
L\002,\002 found in WSPRO results.\002,/,4x,\002Line is: \002,a)";
    static char fmt_65[] = "(/,\002*ERR:XXX* Tailwater elevations not consta\
nt when they\002,\002 should be.\002,/,10x,\002  First elevation=\002,f10.3\
,\002 Differing elevation=\002,f10.3)";
    static char fmt_66[] = "(/,\002Errors found prevent output of the type 1\
4 table.\002)";
    static char fmt_96[] = "(/,\002 FILE NAMED:\002,a,\002 NOT FOUND.  CHECK\
 SPELLING OF\002,\002 FILE NAME.\002)";
    static char fmt_98[] = "(/,\002 Found \002,i3,\002 downstream elevations\
 and \002,i3,\002 partial maximum flows.\002)";
    static char fmt_99[] = "(/,\002 All files have been processed.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;
    alist feq_gen_al_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, ftnlen, ftnlen)
	    , f_inqu(inlist *), f_open(olist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsfe(cilist *), e_rsfe(), i_indx(char *, char *, ftnlen, ftnlen)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_rew(alist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle(), s_rsli(icilist *), e_rsli(), f_clos(
	    cllist *);

    /* Local variables */
    doublereal northing;
    integer feq_gen_i_d_;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_q(53001);
    real *q = feq_heap_q.data()	/* was [151][351] */, hd;
    integer it;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    integer tab, nzd, knt, opt, nzd2;
    char head[80];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char feq_gen_name_d_[256];
    integer clen[16];
    char cval[64*16], line[80];
    integer ival[16], mval, nzdf;
    real rval[16];
    integer nzdl;
    real maxq, wsel;
    char term[1*16], xsid[7], zone[8];
    integer feq_gen_type_d_[16];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char line1[81], label[50], tabid[16];
    integer nfrac;
    real hdvec[151];
    char hgrid[8], basis[8];
    real qfvec[151];
    integer terml[16];
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_humat(53001);
    real *humat = feq_heap_humat.data()	/* was [151][351] */;
    doublereal dpval[16];
    integer first;
    logical there;
    char feq_gen_line_in_error_d_[80];
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen), tabchk_(
	    integer *, integer *, integer *, integer *, integer *), inline_(
	    integer *, integer *, char *, ftnlen), feq_gen_maybe_add_home_d_(char *, 
	    ftnlen);
    real hdatum;
    extern /* Subroutine */ int getval_(integer *, char *, integer *, integer 
	    *, integer *, integer *, real *, doublereal *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, ftnlen, 
	    ftnlen, ftnlen);
    real froude, pfqvec[351], zrhufd;
    char vdatum[8];
    extern /* Subroutine */ int twdout_(integer *, integer *, integer *, char 
	    *, integer *, integer *, real *, real *, real *, real *, real *, 
	    integer *, char *, real *, char *, char *, char *, char *, char *,
	     doublereal *, doublereal *, integer *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), feq_gen_get_lctn_items_d_(integer *, 
	    integer *, integer *), feq_gen_set_lctn_items_d_(char *, char *, char *, 
	    char *, char *, doublereal *, doublereal *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    integer hdeflag;
    extern /* Subroutine */ int inlineb_(integer *, integer *, char *, ftnlen)
	    ;
    doublereal easting;
    real hdfirst;
    integer termcls[16];
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__140 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__142 = { 0, 0, 1, fmt_24, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__166 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__167 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 1, fmt_24, 0 };
    static cilist feq_gen_io_d__170 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__172 = { 0, 0, 0, fmt_24, 0 };
    static cilist feq_gen_io_d__176 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__181 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__182 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__189 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__191 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__192 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__193 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Construct a table of type 14 from one or more .lst files from */
/*     WSPRO version V061698.  These files will have user specified output that will */
/*     contain the values needed and in the proper order.  The */
/*     order is established by the WSPROQZ command implemented in */
/*     subroutine WPROQZ. */
/* SOURCE wspro.for:1136 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE wspro.for:1139 */
/*<       integereflag,stdin,stdout,stdtab >*/
/* SOURCE wspro.for:1140 */
/*<       integertabdir(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE wspro.for:1150 */
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
/* INCLUDE wspro.for:1151 */
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
/* INCLUDE wspro.for:1152 */
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
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE wspro.for:1155 */
/*<       integermaxn >*/
/* SOURCE wspro.for:1156 */
/*<       parameter(maxn=16) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE wspro.for:1159 */
/*<        >*/
/* SOURCE wspro.for:1161 */
/*<       integerclen(maxn),ival(maxn),terml(maxn),termcls(maxn),type(maxn) >*/
/* SOURCE wspro.for:1163 */
/*<        >*/
/* SOURCE wspro.for:1166 */
/*<       real*8dpval(maxn),easting,northing >*/
/* SOURCE wspro.for:1168 */
/*<        >*/
/* SOURCE wspro.for:1171 */
/*<       logicalthere >*/
/* SOURCE wspro.for:1173 */
/*<       charactergettok*7,tabid*16,line_in_error*80 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE wspro.for:1176 */
/*<       externalgettok,getval,inline,tabchk,twdout,os_file_style >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE wspro.for:1179 */
/*<     1 format(7x,i5) >*/
/* SOURCE wspro.for:1180 */
/*<     2 format(6x,a) >*/
/* SOURCE wspro.for:1181 */
/*<     3 format(a) >*/
/* SOURCE wspro.for:1182 */
/*<    24 format(a80) >*/
/* SOURCE wspro.for:1183 */
/*<    25 format(20x,f10.0,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE wspro.for:1186 */
/*<    50 format(/,' Table id for 2-D table of type 14= ',a) >*/
/* SOURCE wspro.for:1187 */
/*<    51 format(/,' Label for 2-D table: ',a) >*/
/* SOURCE wspro.for:1188 */
/*<    54 format(/,' ',a80) >*/
/* SOURCE wspro.for:1189 */
/*<    56 format(' Current file name is:',a) >*/
/* SOURCE wspro.for:1190 */
/*<    58 format(/,' *ERR:519* Expected Q card but found:',a2) >*/
/* SOURCE wspro.for:1191 */
/*<    60 format(/,' *WRN:510* Froude number=',f7.2,' > 1.0 at XSID=',a7) >*/
/* SOURCE wspro.for:1192 */
/*<    62  >*/
/* SOURCE wspro.for:1194 */
/*<    64  >*/
/* SOURCE wspro.for:1196 */
/*<    65  >*/
/* SOURCE wspro.for:1199 */
/*<    66 format(/,'Errors found prevent output of the type 14 table.') >*/
/* SOURCE wspro.for:1200 */
/*<    96  >*/
/* SOURCE wspro.for:1202 */
/*<    98  >*/
/* SOURCE wspro.for:1204 */
/*<    99 format(/,' All files have been processed.') >*/
/* *********************************************************************** */
/* SOURCE wspro.for:1206 */
/*<       hdeflag=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L3: */
/* L24: */
/* L25: */
/* L50: */
/* L51: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
/* L65: */
/* L66: */
/* L96: */
/* L98: */
/* L99: */
    hdeflag = 0;
/*     The latest version of WSPRO finally prints results in a user table */
/*     to a precision that allows us to use the elevation and the flow */
/*     in the table.  Previously we could not use the flow because it */
/*     was printed to such a low precision that the small flows */
/*     would not make a valid type 14 table. */
/*     Get the table number to be used by the two-D table. */
/* SOURCE wspro.for:1214 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1217 */
/*<       callread_tabid(stdout,line,'TAB',eflag,tabid,tab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("TAB"), eflag, tabid, &tab, (ftnlen)80, (ftnlen)
	    3, (ftnlen)16);
/*      READ(LINE,1,ERR=991) TABID */
/* SOURCE wspro.for:1221 */
/*<       write(stdout,50)tabid >*/
    feq_gen_io_d__121.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__121);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    e_wsfe();
/* SOURCE wspro.for:1222 */
/*<       calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE wspro.for:1229 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE wspro.for:1231 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     Get the label for the 2-D table. */
/* SOURCE wspro.for:1236 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1239 */
/*<       read(line,2,err=991)label >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:1240 */
/*<       write(stdout,51)label >*/
    feq_gen_io_d__130.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__130);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/* SOURCE wspro.for:1242 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1245 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
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
/* SOURCE wspro.for:1246 */
/*<       write(stdout,54)head >*/
    feq_gen_io_d__132.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__132);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/*     Input each file name and process in order. */
/*     Each file must have a descriptive header that agrees exactly with */
/*     its contents.  This means that each file must represent a */
/*     complete series of flows for a given downstream head.  The downstream */
/*     heads must be presented in increasing order and the flows */
/*     must be presented in increasing order.   Zero flow is not included */
/*     in any of the files because the result for zero flow is trivial. */
/*     Initialize the global number of zero depths counter */
/* SOURCE wspro.for:1257 */
/*<       nzd=1 >*/
    nzd = 1;
/* SOURCE wspro.for:1258 */
/*<       nzd2=1 >*/
    nzd2 = 1;
/* SOURCE wspro.for:1259 */
/*<   100 continue >*/
L100:
/* SOURCE wspro.for:1260 */
/*<       callinlineb(stdin,stdout,line) >*/
    inlineb_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1263 */
/*<       read(line,3,err=991)name >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_3;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:1265 */
/*<       if(name.ne.' ')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1) != 0) {
/* SOURCE wspro.for:1266 */
/*<       callmaybe_add_home(name) >*/
	feq_gen_maybe_add_home_d_(feq_gen_name_d_, (ftnlen)256);
/* SOURCE wspro.for:1268 */
/*<       callos_file_style(name) >*/
	feq_gen_os_file_style_d_(feq_gen_name_d_, (ftnlen)256);
/* SOURCE wspro.for:1270 */
/*<       inquire(file=name,exist=there) >*/
	feq_gen_ioin_d_1.inerr = 0;
	feq_gen_ioin_d_1.infilen = 256;
	feq_gen_ioin_d_1.infile = feq_gen_name_d_;
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
/* SOURCE wspro.for:1271 */
/*<       if(there)then >*/
	if (there) {
/* SOURCE wspro.for:1272 */
/*<       write(stdout,56)name >*/
	    feq_gen_io_d__137.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__137);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
	    e_wsfe();
/* SOURCE wspro.for:1273 */
/*<       open(unit=std48,file=name,status='OLD') >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = feq_gen_stdun_com_d_1.std48;
	    feq_gen_o_d_1.ofnmlen = 256;
	    feq_gen_o_d_1.ofnm = feq_gen_name_d_;
	    feq_gen_o_d_1.orl = 0;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = 0;
	    feq_gen_o_d_1.ofm = 0;
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE wspro.for:1274 */
/*<       else >*/
	} else {
/* SOURCE wspro.for:1275 */
/*<       write(stdout,96)name >*/
	    feq_gen_io_d__138.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__138);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
	    e_wsfe();
/* SOURCE wspro.for:1276 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:1277 */
/*<       endif >*/
	}
/*         Check for problems in the WSPRO output */
/* SOURCE wspro.for:1279 */
/*<       eflag=0 >*/
	*eflag = 0;
/* SOURCE wspro.for:1280 */
/*<   150 continue >*/
L150:
/* SOURCE wspro.for:1281 */
/*<       read(std48,'(A80)',end=160)line >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciend = 1;
	feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std48;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A80)");
	feq_gen_i_d_1 = s_rsfe(&feq_gen_ci_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L160;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	if (feq_gen_i_d_1 != 0) {
	    goto L160;
	}
	feq_gen_i_d_1 = e_rsfe();
	if (feq_gen_i_d_1 != 0) {
	    goto L160;
	}
/* SOURCE wspro.for:1282 */
/*<       if(index(line,'ERROR').gt.0.or.index(line,'FATAL').gt.0)then >*/
	if (i_indx(line, const_cast<char*>("ERROR"), (ftnlen)80, (ftnlen)5) > 0 || i_indx(line, 
		const_cast<char*>("FATAL"), (ftnlen)80, (ftnlen)5) > 0) {
/* SOURCE wspro.for:1284 */
/*<       line_in_error=line >*/
	    s_copy(feq_gen_line_in_error_d_, line, (ftnlen)80, (ftnlen)80);
/* SOURCE wspro.for:1285 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE wspro.for:1286 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1287 */
/*<       goto150 >*/
	goto L150;
/* SOURCE wspro.for:1288 */
/*<   160 continue >*/
L160:
/* SOURCE wspro.for:1289 */
/*<       if(eflag.gt.0)then >*/
	if (*eflag > 0) {
/* SOURCE wspro.for:1290 */
/*<       write(stdout,64)line_in_error >*/
	    feq_gen_io_d__140.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__140);
	    do_fio(&feq_gen_c_d_1, feq_gen_line_in_error_d_, (ftnlen)80);
	    e_wsfe();
/* SOURCE wspro.for:1291 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE wspro.for:1292 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1293 */
/*<       rewind(std48) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = feq_gen_stdun_com_d_1.std48;
	f_rew(&feq_gen_al_d_1);
/*         Initialize the local number of zero depths counter. */
/* SOURCE wspro.for:1298 */
/*<       nzdl=1 >*/
	nzdl = 1;
/* SOURCE wspro.for:1299 */
/*<   200 continue >*/
L200:
/* SOURCE wspro.for:1300 */
/*<       read(std48,24,end=900)line >*/
	feq_gen_io_d__142.ciunit = feq_gen_stdun_com_d_1.std48;
	feq_gen_i_d_1 = s_rsfe(&feq_gen_io_d__142);
	if (feq_gen_i_d_1 != 0) {
	    goto L900;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	if (feq_gen_i_d_1 != 0) {
	    goto L900;
	}
	feq_gen_i_d_1 = e_rsfe();
	if (feq_gen_i_d_1 != 0) {
	    goto L900;
	}
/* SOURCE wspro.for:1301 */
/*<       if(line(14:20).eq.'WSPROZQ')then >*/
	if (s_cmp(line + 13, const_cast<char*>("WSPROZQ"), (ftnlen)7, (ftnlen)7) == 0) {
/*             Found the standard header line.  Read the number of flows, */
/*             number of downstream elevations, and the head datum. */
/* SOURCE wspro.for:1304 */
/*<       read(line,'(40X,I5,5X,I5,8X,F10.0)')nfrac,nzdf,hdatum >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(40X,I5,5X,I5,8X,F10.0)");
	    s_rsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nzdf, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
	    e_rsfi();
/* SOURCE wspro.for:1305 */
/*<       write(stdout,*)' NFRAC=',nfrac,' NZDF=',nzdf,' HDATUM=',hdatum >*/
	    feq_gen_io_d__146.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__146);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NFRAC="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NZDF="), (ftnlen)6);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&nzdf, (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" HDATUM="), (ftnlen)8);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
	    e_wsle();
/*             Skip over the two lines defining the user output. */
/* SOURCE wspro.for:1309 */
/*<       read(std48,24)line >*/
	    feq_gen_io_d__147.ciunit = feq_gen_stdun_com_d_1.std48;
	    s_rsfe(&feq_gen_io_d__147);
	    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	    e_rsfe();
/* SOURCE wspro.for:1310 */
/*<       read(std48,24)line >*/
	    feq_gen_io_d__148.ciunit = feq_gen_stdun_com_d_1.std48;
	    s_rsfe(&feq_gen_io_d__148);
	    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	    e_rsfe();
/*             Set GETVAL to get the number of values and return the */
/*             types.  Types must be self defining.  That is, a real */
/*             value must have a decimal point. */
/* SOURCE wspro.for:1315 */
/*<       opt=1 >*/
	    opt = 1;
/* SOURCE wspro.for:1316 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE wspro.for:1317 */
/*<   300 continue >*/
L300:
/* SOURCE wspro.for:1318 */
/*<       read(std48,24)line1 >*/
	    feq_gen_io_d__151.ciunit = feq_gen_stdun_com_d_1.std48;
	    s_rsfe(&feq_gen_io_d__151);
	    do_fio(&feq_gen_c_d_1, line1, (ftnlen)81);
	    e_rsfe();
/*               Search for user quote */
/* SOURCE wspro.for:1320 */
/*<       it=index(line1,'''') >*/
	    it = i_indx(line1, const_cast<char*>("'"), (ftnlen)81, (ftnlen)1);
/* SOURCE wspro.for:1321 */
/*<       if(it.eq.0)then >*/
	    if (it == 0) {
/* SOURCE wspro.for:1322 */
/*<       line1(81:81)='''' >*/
		*(unsigned char *)&line1[80] = '\'';
/* SOURCE wspro.for:1323 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:1325 */
/*<        >*/
	    getval_(stdout, line1, &feq_gen_c_d_16, &opt, feq_gen_type_d_, ival, rval, dpval, 
		    cval, clen, eflag, term, terml, termcls, &mval, (ftnlen)
		    81, (ftnlen)64, (ftnlen)1);
/* SOURCE wspro.for:1330 */
/*<       do310i=2,mval >*/
	    feq_gen_i_d_1 = mval;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1331 */
/*<       read(cval(i)(1:clen(i)),*)rval(i) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = clen[feq_gen_i_d_ - 1];
		feq_gen_ici_d_1.iciunit = cval + (feq_gen_i_d_ - 1 << 6);
		feq_gen_ici_d_1.icifmt = 0;
		s_rsli(&feq_gen_ici_d_1);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&rval[feq_gen_i_d_ - 1], (ftnlen)sizeof(
			real));
		e_rsli();
/* SOURCE wspro.for:1332 */
/*<   310 continue >*/
/* L310: */
	    }
/* SOURCE wspro.for:1333 */
/*<       if(cval(1)(1:1).eq.'Q')then >*/
	    if (*(unsigned char *)&cval[0] == 'Q') {
/*                 Flow definition. */
/* SOURCE wspro.for:1335 */
/*<       do400i=2,mval >*/
		feq_gen_i_d_1 = mval;
		for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1336 */
/*<       knt=knt+1 >*/
		    ++knt;
/* SOURCE wspro.for:1337 */
/*<       q(nzd,knt)=rval(i) >*/
		    q[nzd + knt * 151 - 152] = rval[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:1338 */
/*<       if(knt.eq.nfrac)then >*/
		    if (knt == nfrac) {
/*                     Current downstream depth is complete. */
/* SOURCE wspro.for:1340 */
/*<       nzd=nzd+1 >*/
			++nzd;
/* SOURCE wspro.for:1341 */
/*<       nzdl=nzdl+1 >*/
			++nzdl;
/* SOURCE wspro.for:1342 */
/*<       knt=0 >*/
			knt = 0;
/* SOURCE wspro.for:1343 */
/*<       if(nzdl.gt.nzdf)then >*/
			if (nzdl > nzdf) {
/*                       Flows from the current file have been completed. */
/* SOURCE wspro.for:1345 */
/*<       nzdl=1 >*/
			    nzdl = 1;
/* SOURCE wspro.for:1346 */
/*<       write(stdout,*)' Flows completed' >*/
			    feq_gen_io_d__166.ciunit = *stdout;
			    s_wsle(&feq_gen_io_d__166);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Flows completed"), (ftnlen)
				    16);
			    e_wsle();
/* SOURCE wspro.for:1347 */
/*<       goto401 >*/
			    goto L401;
/* SOURCE wspro.for:1348 */
/*<       endif >*/
			}
/* SOURCE wspro.for:1349 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:1350 */
/*<   400 continue >*/
/* L400: */
		}
/* SOURCE wspro.for:1351 */
/*<       else >*/
	    } else {
/* SOURCE wspro.for:1352 */
/*<       write(stdout,58)cval(1)(1:2) >*/
		feq_gen_io_d__167.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__167);
		do_fio(&feq_gen_c_d_1, cval, (ftnlen)2);
		e_wsfe();
/* SOURCE wspro.for:1353 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE wspro.for:1354 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:1355 */
/*<       goto300 >*/
	    goto L300;
/* SOURCE wspro.for:1356 */
/*<   401 continue >*/
L401:
/*             Now look for the string heading the user output. */
/* SOURCE wspro.for:1360 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE wspro.for:1361 */
/*<       nzdl=1 >*/
	    nzdl = 1;
/*             Clear the flag to track the sequences of downstream depths. */
/* SOURCE wspro.for:1363 */
/*<       first=0 >*/
	    first = 0;
/* SOURCE wspro.for:1364 */
/*<   500 continue >*/
L500:
/* SOURCE wspro.for:1365 */
/*<       read(std48,24,end=910)line >*/
	    feq_gen_io_d__169.ciunit = feq_gen_stdun_com_d_1.std48;
	    feq_gen_i_d_1 = s_rsfe(&feq_gen_io_d__169);
	    if (feq_gen_i_d_1 != 0) {
		goto L910;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	    if (feq_gen_i_d_1 != 0) {
		goto L910;
	    }
	    feq_gen_i_d_1 = e_rsfe();
	    if (feq_gen_i_d_1 != 0) {
		goto L910;
	    }
/* SOURCE wspro.for:1366 */
/*<       if(line(30:41).eq.'User Defined')then >*/
	    if (s_cmp(line + 29, const_cast<char*>("User Defined"), (ftnlen)12, (ftnlen)12) == 0)
		     {
/*                  WRITE(STDOUT,*) ' FOUND: User Defined' */
/*                 Found the line.  Skip over the blank line and heading. */
/* SOURCE wspro.for:1369 */
/*<       read(std48,24)line >*/
		feq_gen_io_d__170.ciunit = feq_gen_stdun_com_d_1.std48;
		s_rsfe(&feq_gen_io_d__170);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		e_rsfe();
/* SOURCE wspro.for:1370 */
/*<       read(std48,24)line >*/
		feq_gen_io_d__171.ciunit = feq_gen_stdun_com_d_1.std48;
		s_rsfe(&feq_gen_io_d__171);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		e_rsfe();
/* SOURCE wspro.for:1371 */
/*<       read(std48,24)line >*/
		feq_gen_io_d__172.ciunit = feq_gen_stdun_com_d_1.std48;
		s_rsfe(&feq_gen_io_d__172);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		e_rsfe();
/*                 Read the output lines, and check the Froude number. */
/*                 The downstream elevation is in the line with cross */
/*                 section id EXIT and the upstream elevation is in the */
/*                 line with cross section id APPRO.  Note: in the */
/*                 latest version there are two APPRO lines: the */
/*                 first is in the unconstricted case and the */
/*                 second is the one we want.  The new version prepends */
/*                 numbers to the names.  We use those numbers to */
/*                 make sure we get what we want. */
/* SOURCE wspro.for:1381 */
/*<   600 continue >*/
L600:
/* SOURCE wspro.for:1382 */
/*<       read(std48,'(A80)')line >*/
		feq_gen_ci_d_1.cierr = 0;
		feq_gen_ci_d_1.ciend = 0;
		feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std48;
		feq_gen_ci_d_1.cifmt = const_cast<char*>("(A80)");
		s_rsfe(&feq_gen_ci_d_1);
		do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
		e_rsfe();
/* SOURCE wspro.for:1383 */
/*<       xsid=line(2:8) >*/
		s_copy(xsid, line + 1, (ftnlen)7, (ftnlen)7);
/*                          XSID = GETTOK(XSID) */
/* SOURCE wspro.for:1385 */
/*<        >*/
		if (s_cmp(xsid, const_cast<char*>("1 EXIT "), (ftnlen)7, (ftnlen)7) == 0 || 
			s_cmp(xsid, const_cast<char*>("5 APPRO"), (ftnlen)7, (ftnlen)7) == 0 || 
			s_cmp(xsid, const_cast<char*>("6 APPRO"), (ftnlen)7, (ftnlen)7) == 0) {
/* SOURCE wspro.for:1387 */
/*<       read(line,25)froude,wsel >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.iciend = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 80;
		    feq_gen_ici_d_1.iciunit = line;
		    feq_gen_ici_d_1.icifmt = fmt_25;
		    s_rsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&froude, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&wsel, (ftnlen)sizeof(real));
		    e_rsfi();
/* SOURCE wspro.for:1388 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:1389 */
/*<       froude=0.0 >*/
		    froude = (float)0.;
/* SOURCE wspro.for:1390 */
/*<       wsel=0.0 >*/
		    wsel = (float)0.;
/* SOURCE wspro.for:1391 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1392 */
/*<       if(froude.gt.1.0)then >*/
		if (froude > (float)1.) {
/* SOURCE wspro.for:1393 */
/*<       write(stdout,60)froude,xsid >*/
		    feq_gen_io_d__176.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__176);
		    do_fio(&feq_gen_c_d_1, (char *)&froude, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, xsid, (ftnlen)7);
		    e_wsfe();
/* SOURCE wspro.for:1394 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1395 */
/*<       if(xsid.eq.'1 EXIT')then >*/
		if (s_cmp(xsid, const_cast<char*>("1 EXIT"), (ftnlen)7, (ftnlen)6) == 0) {
/*                     Remember the downstream depth.  Note that this */
/*                     statement is executed NZDF times with the */
/*                     same water surface elevation. */
/* SOURCE wspro.for:1400 */
/*<       hd=wsel-hdatum >*/
		    hd = static_cast<double>(wsel) - hdatum;
/* SOURCE wspro.for:1401 */
/*<       hdvec(nzd2)=hd >*/
		    hdvec[nzd2 - 1] = hd;
/* SOURCE wspro.for:1402 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1403 */
/*<       if(xsid.eq.'5 APPRO'.or.xsid.eq.'6 APPRO')then >*/
		if (s_cmp(xsid, const_cast<char*>("5 APPRO"), (ftnlen)7, (ftnlen)7) == 0 || 
			s_cmp(xsid, const_cast<char*>("6 APPRO"), (ftnlen)7, (ftnlen)7) == 0) {
/*                     Get the upstream elevation and save it. */
/* SOURCE wspro.for:1405 */
/*<       knt=knt+1 >*/
		    ++knt;
/*                     Leave space for zero fraction of free flow */
/*                     by adding one to KNT when storing the upstream */
/*                     heads.  Required by TWDOUT. */
/* SOURCE wspro.for:1409 */
/*<       humat(nzd2,knt+1)=wsel-hdatum >*/
		    humat[nzd2 + (knt + 1) * 151 - 152] = static_cast<double>(wsel) - hdatum;
/* SOURCE wspro.for:1410 */
/*<       if(first==0)then >*/
		    if (first == 0) {
/*                       First time through here for the current sequence of downstream */
/*                       heads.  They should all have the same value. */
/* SOURCE wspro.for:1413 */
/*<       first=1 >*/
			first = 1;
/* SOURCE wspro.for:1414 */
/*<       hdfirst=hd >*/
			hdfirst = hd;
/* SOURCE wspro.for:1415 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:1416 */
/*<       if(hd.ne.hdfirst)then >*/
			if (hd != hdfirst) {
/* SOURCE wspro.for:1417 */
/*<       write(stdout,65)hdfirst+hdatum,hd+hdatum >*/
			    feq_gen_io_d__181.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__181);
			    feq_gen_r_d_1 = static_cast<double>(hdfirst) + hdatum;
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real))
				    ;
			    feq_gen_r_d_2 = static_cast<double>(hd) + hdatum;
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real))
				    ;
			    e_wsfe();
/* SOURCE wspro.for:1418 */
/*<       hdeflag=hdeflag+1 >*/
			    ++hdeflag;
/* SOURCE wspro.for:1419 */
/*<       endif >*/
			}
/* SOURCE wspro.for:1420 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:1421 */
/*<       if(knt.eq.nfrac)then >*/
		    if (knt == nfrac) {
/*                       The current downstream elevation's flows are */
/*                       complete. */
/* SOURCE wspro.for:1424 */
/*<       nzd2=nzd2+1 >*/
			++nzd2;
/* SOURCE wspro.for:1425 */
/*<       nzdl=nzdl+1 >*/
			++nzdl;
/* SOURCE wspro.for:1426 */
/*<       knt=0 >*/
			knt = 0;
/* SOURCE wspro.for:1427 */
/*<       first=0 >*/
			first = 0;
/* SOURCE wspro.for:1428 */
/*<       if(nzdl.gt.nzdf)then >*/
			if (nzdl > nzdf) {
/*                         Current file is processed. */
/* SOURCE wspro.for:1430 */
/*<       nzdl=1 >*/
			    nzdl = 1;
/* SOURCE wspro.for:1431 */
/*<       goto101 >*/
			    goto L101;
/* SOURCE wspro.for:1432 */
/*<       endif >*/
			}
/* SOURCE wspro.for:1433 */
/*<       endif >*/
		    }
/*                     APPRO is the last line of interest in the current */
/*                     user output. */
/* SOURCE wspro.for:1436 */
/*<       goto601 >*/
		    goto L601;
/* SOURCE wspro.for:1437 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1438 */
/*<       goto600 >*/
		goto L600;
/* SOURCE wspro.for:1439 */
/*<   601 continue >*/
L601:
/* SOURCE wspro.for:1440 */
/*<       endif >*/
		;
	    }
/* SOURCE wspro.for:1441 */
/*<       goto500 >*/
	    goto L500;
/* SOURCE wspro.for:1442 */
/*<       else >*/
	} else {
/* SOURCE wspro.for:1443 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE wspro.for:1444 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1445 */
/*<   101 continue >*/
L101:
/* SOURCE wspro.for:1446 */
/*<       close(std48) >*/
	feq_gen_cl_d_1.cerr = 0;
	feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std48;
	feq_gen_cl_d_1.csta = 0;
	f_clos(&feq_gen_cl_d_1);
/* SOURCE wspro.for:1447 */
/*<       goto100 >*/
	goto L100;
/* SOURCE wspro.for:1448 */
/*<       endif >*/
    }
/*     All the files have been processed. */
/* SOURCE wspro.for:1451 */
/*<       write(stdout,99) >*/
    feq_gen_io_d__182.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__182);
    e_wsfe();
/* SOURCE wspro.for:1452 */
/*<       nzd=nzd-1 >*/
    --nzd;
/* SOURCE wspro.for:1453 */
/*<       nzd2=nzd2-1 >*/
    --nzd2;
/* SOURCE wspro.for:1454 */
/*<       write(stdout,98)nzd,nfrac >*/
    feq_gen_io_d__183.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__183);
    do_fio(&feq_gen_c_d_1, (char *)&nzd, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
    e_wsfe();
/*     Extract the maximum flows. */
/* SOURCE wspro.for:1456 */
/*<       do700i=1,nzd >*/
    feq_gen_i_d_1 = nzd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1457 */
/*<       qfvec(i)=q(i,nfrac) >*/
	qfvec[feq_gen_i_d_ - 1] = q[feq_gen_i_d_ + nfrac * 151 - 152];
/* SOURCE wspro.for:1458 */
/*<   700 continue >*/
/* L700: */
    }
/*     Compute the partial free flows.  Add the zero point. */
/* SOURCE wspro.for:1461 */
/*<       pfqvec(1)=0.0 >*/
    pfqvec[0] = (float)0.;
/* SOURCE wspro.for:1462 */
/*<       maxq=q(nzd,nfrac) >*/
    maxq = q[nzd + nfrac * 151 - 152];
/* SOURCE wspro.for:1463 */
/*<       do800i=1,nfrac >*/
    feq_gen_i_d_1 = nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1464 */
/*<       pfqvec(i+1)=q(nzd,i)/maxq >*/
	pfqvec[feq_gen_i_d_] = static_cast<double>(q[nzd + feq_gen_i_d_ * 151 - 152]) / maxq;
/* SOURCE wspro.for:1465 */
/*<   800 continue >*/
/* L800: */
    }
/* SOURCE wspro.for:1466 */
/*<       nfrac=nfrac+1 >*/
    ++nfrac;
/* SOURCE wspro.for:1467 */
/*<       zrhufd=0.0 >*/
    zrhufd = (float)0.;
/* SOURCE wspro.for:1468 */
/*<       if(hdeflag==0)then >*/
    if (hdeflag == 0) {
/* SOURCE wspro.for:1469 */
/*<        >*/
	twdout_(stdout, stdtab, &tab, label, &nzd, &nfrac, qfvec, hdvec, 
		pfqvec, humat, &hdatum, &feq_gen_c_d_14, const_cast<char*>("   WSPRO"), &zrhufd, zone, 
		hgrid, vdatum, unitsys, basis, &easting, &northing, eflag, (
		ftnlen)50, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		ftnlen)8, (ftnlen)8);
/* SOURCE wspro.for:1476 */
/*<       else >*/
    } else {
/* SOURCE wspro.for:1477 */
/*<       write(stdout,66) >*/
	feq_gen_io_d__188.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__188);
	e_wsfe();
/* SOURCE wspro.for:1478 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE wspro.for:1479 */
/*<       endif >*/
    }
/* SOURCE wspro.for:1480 */
/*<       return >*/
    return 0;
/* SOURCE wspro.for:1481 */
/*<   900 continue >*/
L900:
/* SOURCE wspro.for:1482 */
/*<       write(stdout,*)' END OF FILE SEEKING WSPROZQ HEADER' >*/
    feq_gen_io_d__189.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__189);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" END OF FILE SEEKING WSPROZQ HEADER"), (ftnlen)35);
    e_wsle();
/* SOURCE wspro.for:1483 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:1485 */
/*<   910 continue >*/
L910:
/* SOURCE wspro.for:1486 */
/*<       write(stdout,*)' End of file seeking "FIRST USER"' >*/
    feq_gen_io_d__190.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__190);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" End of file seeking \"FIRST USER\""), (ftnlen)33);
    e_wsle();
/* SOURCE wspro.for:1487 */
/*<       write(stdout,62) >*/
    feq_gen_io_d__191.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__191);
    e_wsfe();
/* SOURCE wspro.for:1488 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:1489 */
/*<   991 continue >*/
L991:
/* SOURCE wspro.for:1490 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__192.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__192);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE wspro.for:1491 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__193.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__193);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE wspro.for:1492 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:1494 */
/*<       end >*/
    return 0;
} /* wpro14_new__ */

#undef rtmp
#undef itab
#undef ftab


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



/* SOURCE wspro.for:1523 */
/*<       subroutinewproqz(stdin,stdout,eflag) >*/
/* Subroutine */ int wproqz_(integer *stdin, integer *stdout, integer *eflag)
{
    /* Format strings */
    static char fmt_2[] = "(7x,f10.0)";
    static char fmt_3[] = "(4f10.0)";
    static char fmt_16[] = "(a5,1x,f10.0)";
    static char fmt_24[] = "(a80)";
    static char fmt_25[] = "(7x,i5)";
    static char fmt_26[] = "(a5,1x,i5)";
    static char fmt_50[] = "(/,\002 Cross section table id for normal flow=\
 \002,a)";
    static char fmt_51[] = "(/,\002 Cross section table id for critical fl\
ow=\002,a)";
    static char fmt_52[] = "(/,\002 Elevation of datum for computing heads\
=\002,f10.3)";
    static char fmt_53[] = "(/,\002 Minimum fraction of maximum flow=\002,f1\
0.3)";
    static char fmt_54[] = "(/,\002 *ERR:520* Negative depth=\002,f8.2,\002 \
at normal-flow\002,\002 section.\002)";
    static char fmt_55[] = "(/,\002 *ERR:526* Negative depth=\002,f8.2,\002 \
at critical-flow\002,\002 section.\002)";
    static char fmt_56[] = "(/,\002 *ERR:527* Flow undefined at dsn elevatio\
n=\002,f10.3)";
    static char fmt_58[] = "(/,\002*         WSPROZQ from FEQUTL. NFRAC=\002\
,i5,\002 NZD=\002,i5,\002 HDATUM=\002,f10.3)";
    static char fmt_60[] = "(\002*                 Q FR#  WSEL\002)";
    static char fmt_61[] = "(\002UT                7  27    5\002)";
    static char fmt_62[] = "(\002Q \002,8x,f12.2,f12.2,f12.2,f12.2,f12.2)";
    static char fmt_63[] = "(\002Q \002,8x,f12.2,f12.2,f12.2,f12.2,f12.2,\
\002,\002)";
    static char fmt_64[] = "(\002WS\002,8x,f12.4,f12.4,f12.4,f12.4,f12.4)";
    static char fmt_65[] = "(\002WS\002,8x,f12.4,f12.4,f12.4,f12.4,f12.4,\
\002,\002)";
    static char fmt_66[] = "(\002 Power for spacing of partial maximum flo\
ws=\002,f6.2)";
    static char fmt_75[] = "(/,\002 Profile limit for WSPRO program=\002,i5)";
    static char fmt_76[] = "(/,\002 *ERR:535* NFRAC=\002,i5,\002 > MAXPRO\
=\002,i5,\002.  Unable\002,\002 to continue.\002)";
    static char fmt_92[] = "(/,\002 \002,a80)";
    static char fmt_94[] = "(/,\002 Number of partial maximum flows=\002,i5)";
    static char fmt_95[] = "(\002 \002,f10.3,f10.1,f10.7,f10.3)";
    static char fmt_96[] = "(/,\002 WSPRO must be run \002,i3,\002 times.  O\
nce for each\002,\002 input block below.\002)";
    static char fmt_97[] = "(/,\002 Vertical shift=\002,f10.3)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi()
	    , f_back(alist *);
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal northing;
    integer feq_gen_i_d_, j;
    real k;
    integer n;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_q(53001);
    real *q = feq_heap_q.data(), y;
    integer je, js;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    integer tab, lim, nzd, knt, knt2;
    char head[80];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char line[80];
    real zbqc;
    extern /* Subroutine */ int lktk_(integer *, real *, real *);
    real maxq;
    integer kntl;
    real zbqn;
    char zone[8];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char char5[5];
    integer nfrac, qctab;
    real qcoff;
    char hgrid[8], basis[8];
    integer qntab, total;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_zdmat(53001);
    real oldzd, qcrit, *zdmat = feq_heap_zdmat.data(), zdvec[151], maxqs;
    doublereal shift;
    real power, qnorm;
    extern /* Subroutine */ int lktqc_(integer *, real *, real *);
    integer leflag;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), fndelv_(integer *, integer *, 
	    integer *, real *), inline_(integer *, integer *, char *, ftnlen);
    real hdatum, pfqmin;
    integer maxpro, nzdmax;
    real dnswse;
    char vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_get_lctn_items_d_(integer *, integer *, 
	    integer *), feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char 
	    *, doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);
    char qctabid[16], qntabid[16];
    doublereal easting;
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__200 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__215 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__217 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__219 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__222 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__224 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__226 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__227 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__229 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__240 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__243 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__245 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__246 = { 0, 0, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__253 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__258 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__259 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__260 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__262 = { 0, 0, 0, fmt_63, 0 };
    static cilist feq_gen_io_d__264 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__265 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__266 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__267 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__268 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the flow and elevation cards for input to WSPRO in order */
/*     to produce the output needed to create a table of type 14 to */
/*     describe the structure being modeled in WSPRO.  The command */
/*     WSPROT14 is then used to read the .prt file from WSPRO and */
/*     create a table of type 14 */
/* SOURCE wspro.for:1534 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE wspro.for:1537 */
/*<       integereflag,stdin,stdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE wspro.for:1545 */
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
/* INCLUDE wspro.for:1546 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE wspro.for:1549 */
/*<        >*/
/* SOURCE wspro.for:1551 */
/*<        >*/
/* SOURCE wspro.for:1554 */
/*<       characterchar5*5,head*80,line*80,qntabid*16,qctabid*16 >*/
/* SOURCE wspro.for:1555 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/* SOURCE wspro.for:1556 */
/*<       real*8easting,northing,shift >*/
/*     + + + INTRINSICS + + + */
/* SOURCE wspro.for:1559 */
/*<       intrinsicfloat,max,min,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE wspro.for:1562 */
/*<       integerlenstr >*/
/* SOURCE wspro.for:1563 */
/*<       externalchktab,fndelv,inline,lktk,lktqc,lenstr >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE wspro.for:1566 */
/*<     1 format(6x,i5) >*/
/* SOURCE wspro.for:1567 */
/*<     2 format(7x,f10.0) >*/
/* SOURCE wspro.for:1568 */
/*<     3 format(4f10.0) >*/
/* SOURCE wspro.for:1569 */
/*<    16 format(a5,1x,f10.0) >*/
/* SOURCE wspro.for:1570 */
/*<    24 format(a80) >*/
/* SOURCE wspro.for:1571 */
/*<    25 format(7x,i5) >*/
/* SOURCE wspro.for:1572 */
/*<    26 format(a5,1x,i5) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE wspro.for:1575 */
/*<    50 format(/,' Cross section table id for normal flow= ',a) >*/
/* SOURCE wspro.for:1576 */
/*<    51 format(/,' Cross section table id for critical flow=',a) >*/
/* SOURCE wspro.for:1577 */
/*<    52 format(/,' Elevation of datum for computing heads=',f10.3) >*/
/* SOURCE wspro.for:1578 */
/*<    53 format(/,' Minimum fraction of maximum flow=',f10.3) >*/
/* SOURCE wspro.for:1579 */
/*<    54  >*/
/* SOURCE wspro.for:1581 */
/*<    55  >*/
/* SOURCE wspro.for:1583 */
/*<    56 format(/,' *ERR:527* Flow undefined at dsn elevation=',f10.3) >*/
/* SOURCE wspro.for:1584 */
/*<    58  >*/
/* SOURCE wspro.for:1586 */
/*<    60 format('*                 Q FR#  WSEL') >*/
/* 61   FORMAT('J3                5  14    3') */
/* SOURCE wspro.for:1588 */
/*<    61 format('UT                7  27    5') >*/
/* SOURCE wspro.for:1589 */
/*<    62 format('Q ',8x,f12.2,f12.2,f12.2,f12.2,f12.2) >*/
/* SOURCE wspro.for:1590 */
/*<    63 format('Q ',8x,f12.2,f12.2,f12.2,f12.2,f12.2,',') >*/
/* SOURCE wspro.for:1591 */
/*<    64 format('WS',8x,f12.4,f12.4,f12.4,f12.4,f12.4) >*/
/* SOURCE wspro.for:1592 */
/*<    65 format('WS',8x,f12.4,f12.4,f12.4,f12.4,f12.4,',') >*/
/* SOURCE wspro.for:1593 */
/*<    66 format(' Power for spacing of partial maximum flows=',f6.2) >*/
/* SOURCE wspro.for:1594 */
/*<    75 format(/,' Profile limit for WSPRO program=',i5) >*/
/* SOURCE wspro.for:1595 */
/*<    76  >*/
/* SOURCE wspro.for:1597 */
/*<    92 format(/,' ',a80) >*/
/* SOURCE wspro.for:1598 */
/*<    94 format(/,' Number of partial maximum flows=',i5) >*/
/* SOURCE wspro.for:1599 */
/*<    95 format(' ',f10.3,f10.1,f10.7,f10.3) >*/
/* SOURCE wspro.for:1600 */
/*<    96  >*/
/* SOURCE wspro.for:1602 */
/*<    97 format(/,' Vertical shift=',f10.3) >*/
/* *********************************************************************** */
/*     Get the table number of the cross section that may be used */
/*     to define the maximum flow using an estimated water-surface slope. */
/* SOURCE wspro.for:1606 */
/*<       callinline(stdin,stdout,line) >*/
/* L1: */
/* L2: */
/* L3: */
/* L16: */
/* L24: */
/* L25: */
/* L26: */
/* L50: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
/* L56: */
/* L58: */
/* L60: */
/* L61: */
/* L62: */
/* L63: */
/* L64: */
/* L65: */
/* L66: */
/* L75: */
/* L76: */
/* L92: */
/* L94: */
/* L95: */
/* L96: */
/* L97: */
    inline_(stdin, stdout, line, (ftnlen)80);
/*      READ(LINE,1,ERR=991) QNTAB */
/* SOURCE wspro.for:1610 */
/*<       callread_tabid(stdout,line,'QNTAB',eflag,qntabid,qntab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("QNTAB"), eflag, qntabid, &qntab, (ftnlen)80, (
	    ftnlen)5, (ftnlen)16);
/* SOURCE wspro.for:1613 */
/*<       write(stdout,50)qntabid(1:lenstr(qntabid)) >*/
    feq_gen_io_d__200.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__200);
    do_fio(&feq_gen_c_d_1, qntabid, lenstr_(qntabid, (ftnlen)16));
    e_wsfe();
/*     Remember the internal table number because CHKTAB converts */
/*     QNTAB to the address and FNDELV needs the table number! */
/* SOURCE wspro.for:1616 */
/*<       tab=qntab >*/
    tab = qntab;
/* SOURCE wspro.for:1617 */
/*<       callchktab(20,stdout,ftpnt,pmxtab,qntab,eflag) >*/
    chktab_(&feq_gen_c_d_20, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &qntab, eflag);
/* SOURCE wspro.for:1621 */
/*<       if(qntab.gt.0.and.eflag.eq.0)then >*/
    if (qntab > 0 && *eflag == 0) {
/*       Find the bottom elevation for the normal flow cross section */
/*       table. */
/* SOURCE wspro.for:1624 */
/*<       callfndelv(tab,stdout,eflag,zbqn) >*/
	fndelv_(&tab, stdout, eflag, &zbqn);
/* SOURCE wspro.for:1627 */
/*<       endif >*/
    }
/*     Get the table number of the cross section that defines critical */
/*     flow in the structure opening using a user-supplied offset */
/*     in elevation from the downstream water-surface elevation. */
/* SOURCE wspro.for:1632 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/*      READ(LINE,1,ERR=991) QCTAB */
/* SOURCE wspro.for:1636 */
/*<       callread_tabid(stdout,line,'QCTAB',eflag,qctabid,qctab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("QCTAB"), eflag, qctabid, &qctab, (ftnlen)80, (
	    ftnlen)5, (ftnlen)16);
/* SOURCE wspro.for:1639 */
/*<       write(stdout,51)qctabid(1:lenstr(qctabid)) >*/
    feq_gen_io_d__205.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__205);
    do_fio(&feq_gen_c_d_1, qctabid, lenstr_(qctabid, (ftnlen)16));
    e_wsfe();
/* SOURCE wspro.for:1640 */
/*<       tab=qctab >*/
    tab = qctab;
/* SOURCE wspro.for:1641 */
/*<       callchktab(20,stdout,ftpnt,pmxtab,qctab,eflag) >*/
    chktab_(&feq_gen_c_d_20, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &qctab, eflag);
/* SOURCE wspro.for:1645 */
/*<       if(qctab.gt.0.and.eflag.eq.0)then >*/
    if (qctab > 0 && *eflag == 0) {
/*       Find the bottom elevation for the critical-flow cross section */
/*       table. */
/* SOURCE wspro.for:1648 */
/*<       callfndelv(tab,stdout,eflag,zbqc) >*/
	fndelv_(&tab, stdout, eflag, &zbqc);
/* SOURCE wspro.for:1651 */
/*<       endif >*/
    }
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE wspro.for:1655 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE wspro.for:1657 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE wspro.for:1660 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1663 */
/*<       shift=0.d0 >*/
    shift = 0.;
/* SOURCE wspro.for:1664 */
/*<       if(line(1:5)=='SHIFT')then >*/
    if (s_cmp(line, const_cast<char*>("SHIFT"), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE wspro.for:1665 */
/*<       read(line,'(6x,f10)',err=991)shift >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(6x,f10)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(doublereal));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE wspro.for:1666 */
/*<       else >*/
    } else {
/* SOURCE wspro.for:1667 */
/*<       backspace(stdin) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE wspro.for:1668 */
/*<       endif >*/
    }
/* SOURCE wspro.for:1669 */
/*<       write(stdout,97)shift >*/
    feq_gen_io_d__215.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__215);
    do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(doublereal));
    e_wsfe();
/*     Get the elevation of the datum for computing heads */
/* SOURCE wspro.for:1673 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1676 */
/*<       read(line,2,err=991)hdatum >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:1677 */
/*<       hdatum=hdatum+shift >*/
    hdatum += shift;
/* SOURCE wspro.for:1678 */
/*<       write(stdout,52)hdatum >*/
    feq_gen_io_d__217.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__217);
    do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the minimum value of partial maximum flow to use in the */
/*     code 14 table. */
/* SOURCE wspro.for:1682 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1685 */
/*<       read(line,2,err=991)pfqmin >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&pfqmin, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:1686 */
/*<       write(stdout,53)pfqmin >*/
    feq_gen_io_d__219.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__219);
    do_fio(&feq_gen_c_d_1, (char *)&pfqmin, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the values defining the distribution of partial free flows. */
/* SOURCE wspro.for:1689 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1692 */
/*<       read(line,26,err=991)char5,nfrac >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_26;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:1693 */
/*<       write(stdout,94)nfrac >*/
    feq_gen_io_d__222.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__222);
    do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE wspro.for:1695 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1698 */
/*<       read(line,16,err=991)char5,power >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_16;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&power, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:1699 */
/*<       write(stdout,66)power >*/
    feq_gen_io_d__224.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__224);
    do_fio(&feq_gen_c_d_1, (char *)&power, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE wspro.for:1701 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1704 */
/*<       read(line,25,err=991)maxpro >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_25;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&maxpro, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:1705 */
/*<       write(stdout,75)maxpro >*/
    feq_gen_io_d__226.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__226);
    do_fio(&feq_gen_c_d_1, (char *)&maxpro, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE wspro.for:1707 */
/*<       if(nfrac.gt.maxpro)then >*/
    if (nfrac > maxpro) {
/* SOURCE wspro.for:1708 */
/*<       write(stdout,76)nfrac,maxpro >*/
	feq_gen_io_d__227.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__227);
	do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&maxpro, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE wspro.for:1709 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE wspro.for:1710 */
/*<       return >*/
	return 0;
/* SOURCE wspro.for:1711 */
/*<       endif >*/
    }
/* SOURCE wspro.for:1713 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1716 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
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
/* SOURCE wspro.for:1717 */
/*<       write(stdout,92)head >*/
    feq_gen_io_d__229.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__229);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/*     Input the defining the downstream heads and the maximum and minimum */
/*     flows to use for each downstream head. */
/* SOURCE wspro.for:1722 */
/*<       oldzd=-1.e30 >*/
    oldzd = (float)-1e30;
/* SOURCE wspro.for:1723 */
/*<       nzd=0 >*/
    nzd = 0;
/* SOURCE wspro.for:1724 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE wspro.for:1725 */
/*<   100 continue >*/
L100:
/* SOURCE wspro.for:1726 */
/*<       leflag=0 >*/
    leflag = 0;
/* SOURCE wspro.for:1727 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE wspro.for:1730 */
/*<       read(line,3,err=991)dnswse,maxq,maxqs,qcoff >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_3;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&dnswse, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&maxq, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&maxqs, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&qcoff, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE wspro.for:1731 */
/*<       dnswse=dnswse+shift >*/
    dnswse += shift;
/* SOURCE wspro.for:1732 */
/*<       if(dnswse.gt.oldzd)then >*/
    if (dnswse > oldzd) {
/* SOURCE wspro.for:1733 */
/*<       nzd=nzd+1 >*/
	++nzd;
/* SOURCE wspro.for:1734 */
/*<       zdvec(nzd)=dnswse >*/
	zdvec[nzd - 1] = dnswse;
/*         Compute and output the flow and water-surface elevation */
/*         lines for WSPRO.  These must be transfered by the user */
/*         to the WSPRO input prepared by the user. */
/* SOURCE wspro.for:1740 */
/*<       if(maxq.eq.0.0)then >*/
	if (maxq == (float)0.) {
/*           No value supplied by the user.  Try to use the water- */
/*           surface slope. */
/* SOURCE wspro.for:1743 */
/*<       if(qntab.gt.0)then >*/
	    if (qntab > 0) {
/*             Cross section table exists. */
/* SOURCE wspro.for:1745 */
/*<       if(maxqs.gt.0.0)then >*/
		if (maxqs > (float)0.) {
/*               Slope exists. Make the flow estimate. */
/* SOURCE wspro.for:1747 */
/*<       y=dnswse-zbqn >*/
		    y = static_cast<double>(dnswse) - zbqn;
/* SOURCE wspro.for:1748 */
/*<       if(y.le.0.0)then >*/
		    if (y <= (float)0.) {
/* SOURCE wspro.for:1749 */
/*<       write(stdout,54)y >*/
			feq_gen_io_d__240.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__240);
			do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE wspro.for:1750 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE wspro.for:1751 */
/*<       leflag=1 >*/
			leflag = 1;
/* SOURCE wspro.for:1752 */
/*<       qnorm=0.0 >*/
			qnorm = (float)0.;
/* SOURCE wspro.for:1753 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:1754 */
/*<       calllktk(qntab,y,k) >*/
			lktk_(&qntab, &y, &k);
/* SOURCE wspro.for:1758 */
/*<       qnorm=k*sqrt(maxqs) >*/
			qnorm = k * sqrt(maxqs);
/* SOURCE wspro.for:1759 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:1760 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:1761 */
/*<       qnorm=0.0 >*/
		    qnorm = (float)0.;
/* SOURCE wspro.for:1762 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1763 */
/*<       else >*/
	    } else {
/* SOURCE wspro.for:1764 */
/*<       qnorm=0.0 >*/
		qnorm = (float)0.;
/* SOURCE wspro.for:1765 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:1766 */
/*<       if(qctab.gt.0)then >*/
	    if (qctab > 0) {
/*             Critical flow table exists. */
/* SOURCE wspro.for:1768 */
/*<       y=dnswse+qcoff-zbqc >*/
		y = static_cast<double>(static_cast<double>(dnswse) + qcoff) - zbqc;
/* SOURCE wspro.for:1769 */
/*<       if(y.le.0.0)then >*/
		if (y <= (float)0.) {
/* SOURCE wspro.for:1770 */
/*<       write(stdout,55)y >*/
		    feq_gen_io_d__243.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__243);
		    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE wspro.for:1771 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE wspro.for:1772 */
/*<       leflag=1 >*/
		    leflag = 1;
/* SOURCE wspro.for:1773 */
/*<       qcrit=0.0 >*/
		    qcrit = (float)0.;
/* SOURCE wspro.for:1774 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:1775 */
/*<       calllktqc(qctab,y,qcrit) >*/
		    lktqc_(&qctab, &y, &qcrit);
/* SOURCE wspro.for:1779 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1780 */
/*<       else >*/
	    } else {
/* SOURCE wspro.for:1781 */
/*<       qcrit=0.0 >*/
		qcrit = (float)0.;
/* SOURCE wspro.for:1782 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:1783 */
/*<       if(qcrit.eq.0.0.and.qnorm.eq.0.0)then >*/
	    if (qcrit == (float)0. && qnorm == (float)0.) {
/* SOURCE wspro.for:1784 */
/*<       write(stdout,56)dnswse >*/
		feq_gen_io_d__245.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__245);
		do_fio(&feq_gen_c_d_1, (char *)&dnswse, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE wspro.for:1785 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE wspro.for:1786 */
/*<       leflag=1 >*/
		leflag = 1;
/* SOURCE wspro.for:1787 */
/*<       else >*/
	    } else {
/* SOURCE wspro.for:1788 */
/*<       if(qcrit.gt.0.0.and.qnorm.gt.0.0)then >*/
		if (qcrit > (float)0. && qnorm > (float)0.) {
/* SOURCE wspro.for:1789 */
/*<       maxq=min(qcrit,qnorm) >*/
		    maxq = dmin(qcrit,qnorm);
/* SOURCE wspro.for:1790 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:1791 */
/*<       maxq=max(qcrit,qnorm) >*/
		    maxq = dmax(qcrit,qnorm);
/* SOURCE wspro.for:1792 */
/*<       endif >*/
		}
/* SOURCE wspro.for:1793 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:1794 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1795 */
/*<       write(stdout,95)dnswse,maxq,maxqs,qcoff >*/
	feq_gen_io_d__246.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__246);
	do_fio(&feq_gen_c_d_1, (char *)&dnswse, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&maxq, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&maxqs, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&qcoff, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE wspro.for:1796 */
/*<       if(leflag.eq.0)then >*/
	if (leflag == 0) {
/* SOURCE wspro.for:1797 */
/*<       do200i=1,nfrac >*/
	    feq_gen_i_d_1 = nfrac;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1798 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE wspro.for:1799 */
/*<        >*/
		feq_gen_d_d_1 = (doublereal) (static_cast<double>((real) (feq_gen_i_d_ - 1)) / (real) (nfrac - 1));
		feq_gen_d_d_2 = (doublereal) power;
		q[knt - 1] = maxq * (pfqmin + (static_cast<double>((float)1.) - pfqmin) * pow_dd(&
			feq_gen_d_d_1, &feq_gen_d_d_2));
/* SOURCE wspro.for:1801 */
/*<   200 continue >*/
/* L200: */
	    }
/* SOURCE wspro.for:1802 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1804 */
/*<       oldzd=dnswse >*/
	oldzd = dnswse;
/* SOURCE wspro.for:1805 */
/*<       goto100 >*/
	goto L100;
/* SOURCE wspro.for:1806 */
/*<       endif >*/
    }
/*     Create the same pattern in ZDMAT as in Q */
/* SOURCE wspro.for:1809 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE wspro.for:1810 */
/*<       do500i=1,nzd >*/
    feq_gen_i_d_1 = nzd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1811 */
/*<       do400j=1,nfrac >*/
	feq_gen_i_d_2 = nfrac;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE wspro.for:1812 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE wspro.for:1813 */
/*<       zdmat(knt)=zdvec(i) >*/
	    zdmat[knt - 1] = zdvec[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:1814 */
/*<   400 continue >*/
/* L400: */
	}
/* SOURCE wspro.for:1815 */
/*<   500 continue >*/
/* L500: */
    }
/*     All values have been computed here.  Dump in format required by */
/*     WSPRO.  Output in groups to accommodate limited profile storage */
/*     that exists in many WSPRO versions. */
/* SOURCE wspro.for:1821 */
/*<       nzdmax=maxpro/nfrac >*/
    nzdmax = maxpro / nfrac;
/* SOURCE wspro.for:1822 */
/*<       n=nzd/nzdmax >*/
    n = nzd / nzdmax;
/* SOURCE wspro.for:1823 */
/*<       if(n*nzdmax.lt.nzd)then >*/
    if (n * nzdmax < nzd) {
/*       Catch the fractional part if it exists. */
/* SOURCE wspro.for:1825 */
/*<       n=n+1 >*/
	++n;
/* SOURCE wspro.for:1826 */
/*<       endif >*/
    }
/* SOURCE wspro.for:1827 */
/*<       write(stdout,96)n >*/
    feq_gen_io_d__253.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__253);
    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE wspro.for:1828 */
/*<       if(n.eq.1)nzdmax=nzd >*/
    if (n == 1) {
	nzdmax = nzd;
    }
/* SOURCE wspro.for:1829 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE wspro.for:1830 */
/*<       knt2=0 >*/
    knt2 = 0;
/* SOURCE wspro.for:1831 */
/*<       do1000i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:1832 */
/*<       js=1+(i-1)*nzdmax >*/
	js = (feq_gen_i_d_ - 1) * nzdmax + 1;
/* SOURCE wspro.for:1833 */
/*<       je=js+nzdmax-1 >*/
	je = js + nzdmax - 1;
/* SOURCE wspro.for:1834 */
/*<       if(je.gt.nzd)then >*/
	if (je > nzd) {
/*         Last block of values may not have NZDMAX values of */
/*         downstream elevation.  Adjust value to match. */
/* SOURCE wspro.for:1837 */
/*<       nzdmax=nzd-js+1 >*/
	    nzdmax = nzd - js + 1;
/* SOURCE wspro.for:1838 */
/*<       je=nzd >*/
	    je = nzd;
/* SOURCE wspro.for:1839 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1841 */
/*<       kntl=0 >*/
	kntl = 0;
/*       Output the standard request for output with a standard heading */
/* SOURCE wspro.for:1843 */
/*<       write(stdout,58)nfrac,nzdmax,hdatum >*/
	feq_gen_io_d__258.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__258);
	do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&nzdmax, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE wspro.for:1844 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__259.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__259);
	e_wsfe();
/* SOURCE wspro.for:1845 */
/*<       write(stdout,61) >*/
	feq_gen_io_d__260.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__260);
	e_wsfe();
/* SOURCE wspro.for:1847 */
/*<       total=nzdmax*nfrac >*/
	total = nzdmax * nfrac;
/* SOURCE wspro.for:1848 */
/*<   300 continue >*/
L300:
/* SOURCE wspro.for:1849 */
/*<       if(kntl+5.lt.total)then >*/
	if (kntl + 5 < total) {
/*           Output five values with a trailing comma */
/* SOURCE wspro.for:1851 */
/*<       write(stdout,63)(q(knt+j),j=1,5) >*/
	    feq_gen_io_d__262.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__262);
	    for (j = 1; j <= 5; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&q[knt + j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* SOURCE wspro.for:1852 */
/*<       knt=knt+5 >*/
	    knt += 5;
/* SOURCE wspro.for:1853 */
/*<       kntl=kntl+5 >*/
	    kntl += 5;
/* SOURCE wspro.for:1854 */
/*<       goto300 >*/
	    goto L300;
/* SOURCE wspro.for:1855 */
/*<       else >*/
	} else {
/*           Output the last record without a trailing comma. */
/* SOURCE wspro.for:1857 */
/*<       lim=min(5,total-kntl) >*/
/* Computing MIN */
	    feq_gen_i_d_2 = 5, feq_gen_i_d_3 = total - kntl;
	    lim = min(feq_gen_i_d_2,feq_gen_i_d_3);
/* SOURCE wspro.for:1858 */
/*<       write(stdout,62)(q(knt+j),j=1,lim) >*/
	    feq_gen_io_d__264.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__264);
	    feq_gen_i_d_2 = lim;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&q[knt + j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* SOURCE wspro.for:1859 */
/*<       knt=knt+lim >*/
	    knt += lim;
/* SOURCE wspro.for:1860 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1863 */
/*<       kntl=0 >*/
	kntl = 0;
/* SOURCE wspro.for:1864 */
/*<   600 continue >*/
L600:
/* SOURCE wspro.for:1865 */
/*<       if(kntl+5.lt.total)then >*/
	if (kntl + 5 < total) {
/*           Output five values with a trailing comma */
/* SOURCE wspro.for:1867 */
/*<       write(stdout,65)(zdmat(knt2+j),j=1,5) >*/
	    feq_gen_io_d__265.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__265);
	    for (j = 1; j <= 5; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&zdmat[knt2 + j - 1], (ftnlen)sizeof(
			real));
	    }
	    e_wsfe();
/* SOURCE wspro.for:1868 */
/*<       knt2=knt2+5 >*/
	    knt2 += 5;
/* SOURCE wspro.for:1869 */
/*<       kntl=kntl+5 >*/
	    kntl += 5;
/* SOURCE wspro.for:1870 */
/*<       goto600 >*/
	    goto L600;
/* SOURCE wspro.for:1871 */
/*<       else >*/
	} else {
/*           Output the last record without a trailing comma. */
/* SOURCE wspro.for:1873 */
/*<       lim=min(5,total-kntl) >*/
/* Computing MIN */
	    feq_gen_i_d_2 = 5, feq_gen_i_d_3 = total - kntl;
	    lim = min(feq_gen_i_d_2,feq_gen_i_d_3);
/* SOURCE wspro.for:1874 */
/*<       write(stdout,64)(zdmat(knt2+j),j=1,lim) >*/
	    feq_gen_io_d__266.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__266);
	    feq_gen_i_d_2 = lim;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&zdmat[knt2 + j - 1], (ftnlen)sizeof(
			real));
	    }
	    e_wsfe();
/* SOURCE wspro.for:1875 */
/*<       knt2=knt2+lim >*/
	    knt2 += lim;
/* SOURCE wspro.for:1876 */
/*<       endif >*/
	}
/* SOURCE wspro.for:1877 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE wspro.for:1878 */
/*<       return >*/
    return 0;
/* SOURCE wspro.for:1879 */
/*<   991 continue >*/
L991:
/* SOURCE wspro.for:1880 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__267.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__267);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE wspro.for:1881 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__268.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__268);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE wspro.for:1882 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE wspro.for:1884 */
/*<       end >*/
    return 0;
} /* wproqz_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE wspro.for:1888 */
/*<       subroutinewprox(stdin,stdout,stdtab,nfac,tabdir,ftp,eflag) >*/
/* Subroutine */ int wprox_(integer *stdin, integer *stdout, integer *stdtab, 
	real *nfac, integer *feq_storage_tabdir, integer *ftp, integer *eflag)
{
    /* Initialized data */

    static char staout[18+1] = "('STATION=',      ";

    /* Format strings */
    static char fmt_50[] = "(//)";
    static char fmt_51[] = "(/,\002 TABID=\002,i8)";
    static char fmt_52[] = "(\002 NAVM=\002,a5,\002  SCALE=\002,f10.3,\002 S\
HIFT=\002,f10.3)";
    static char fmt_53[] = "(\002 STATION=\002,f10.3,\002 LEFT=\002,f10.1\
,\002 RIGHT=\002,f10.1)";
    static char fmt_54[] = "(\002 STATION=\002,f10.3)";
    static char fmt_55[] = "(1x,\002NSUB\002,i5,6f6.3,1x,/,(10x,6f6.3))";
    static char fmt_58[] = "(\002 *ERR:504* NUMBER OF SUBSECTIONS=\002,i5\
,\002 > \002,i5)";
    static char fmt_61[] = "(\002 *ERR:506* ONLY ONE POINT GIVEN ON BOUNDARY\
 OF THE\002,\002 CROSS SECTION.\002)";
    static char fmt_67[] = "(/,\002*WRN:554* Extending left end of cross sec\
tion\002,\002 by \002,f8.3)";
    static char fmt_68[] = "(/,\002 *WRN:555* Extending right end of cross s\
ection\002,\002 by \002,f8.3)";
    static char fmt_69[] = "(/,\002 *WRN:556* Some point in cross section hi\
gher than\002,\002 either end.\002,/,10x,\002All area above minimum end elev\
ation\002,\002 is ignored.\002)";
    static char fmt_70[] = "(\002     OFFSET ELEVATION SUBS\002,3x,a8)";
    static char fmt_72[] = "(\002 \002,f10.2,f10.2,i5)";
    static char fmt_73[] = "(\002 \002,f10.2,f10.2,i5,f6.3,8(f5.1,f6.3))";
    static char fmt_75[] = "(\002TABID=\002,i8,2x,a8,1x,a8,1x,a8,1x,a8)";
    static char fmt_76[] = "(\002TABID=\002,i8,\002  EXTEND\002,2x,a8,1x,a8,\
1x,a8,1x,a8)";
    static char fmt_77[] = "(\002FEQXEXT\002)";
    static char fmt_78[] = "(\002VARN=HYDY\002)";
    static char fmt_79[] = "(\002VARN=NCON\002)";
    static char fmt_80[] = "(\002NSUB\002,i5,6f10.3,/,(9x,6f10.3))";
    static char fmt_81[] = "(\002    OFFSET ELEVATION SUBS\002,2x,a8)";
    static char fmt_82[] = "(f10.2,f10.2,i5,f6.3,8(f5.1,f6.3))";
    static char fmt_84[] = "(\002CHANNEL\002,/,\002SINDEF=LINEAR\002,/,\002H\
EAD      Left     Leftr      Axis     Axisr    Rightl    \002,\002 Right\002)"
	    ;
    static char fmt_86[] = "(\002STAT\002,6f10.4)";
    static char fmt_88[] = "(\002OFFS\002,6f10.2)";
    static char fmt_90[] = "(i10)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3[2];
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    cllist feq_gen_cl_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_clos(cllist *), s_wsfe(
	    cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen), f_rew(
	    alist *), s_rsfe(cilist *), e_rsfe(), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(), s_wsfi(icilist *)
	    , e_wsfi();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    char betaflag[1*999];
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_i_d_, j, k;
    char alphaflag[1*999];
    integer in;
    real tp;
    char f10x[5];
    integer knt;
    real sfac;
    char mode[8], line[120];
    integer idsn, isub, mesg, ncon, sfpn;
    real left, stat[1200]	/* was [400][3] */, xold, zmax;
    char zone[8], oldid[2];
    real floff[2400]	/* was [400][6] */;
    char hgrid[8];
    integer xflag;
    char basis[8];
    integer first, itemp;
    real right, statl, statr, statt;
    extern /* Subroutine */ int mkfmt_(real *, integer *, char *, ftnlen);
    integer begtab, chflag;
    char maflag[1*999];
    integer tabinc, lnflag;
    real begsta;
    integer endstr, oldsub;
    real stadir, xfline[6];
    char betopt[8], monflg[8], outopt[8], savopt[8], sfpnam[8], xsname[5], 
	    khflag[1*999], mqflag[1*999], vdatum[8];
    extern integer strlen_(char *, ftnlen);
    extern /* Subroutine */ int cxstab_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, char *, integer *, integer *, real *
	    , real *, integer *, integer *, real *, real *, real *, real *, 
	    integer *, integer *, real *, real *, real *, integer *, real *, 
	    ftnlen), insfpx_(integer *, integer *, char *, integer *, char *, 
	    char *, char *, char *, integer *, char *, integer *, integer *, 
	    real *, real *, real *, char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), proint_()
	    , scnpro_(integer *, integer *, integer *, real *, real *, 
	    integer *, real *, integer *, integer *, char *, integer *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *,
	     real *, real *, integer *, integer *, real *, real *, char *, 
	    integer *, real *, ftnlen, ftnlen), tabchk_(integer *, integer *, 
	    integer *, integer *, integer *), tabout_(integer *, integer *, 
	    integer *, real *, real *, integer *, char *, char *, char *, 
	    char *, char *, char *, char *, char *, char *, char *, char *, 
	    char *, char *, integer *, real *, integer *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen), feq_gen_strip_l_blanks_d_(char *, ftnlen), 
	    xsecfit_(integer *, integer *, integer *, real *, char *, char *, 
	    char *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__303 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__304 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__306 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__311 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__312 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__313 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__314 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__315 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__316 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__317 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__318 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__321 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__324 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__325 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__326 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__328 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__329 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__330 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__331 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__332 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__333 = { 0, 0, 0, fmt_67, 0 };
    static cilist feq_gen_io_d__334 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__335 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__344 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__345 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__346 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__349 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__350 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__351 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__352 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__353 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__354 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__355 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__356 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__357 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Abstract WPRO cross sections from a WPRO input deck. */
/*     Two options:  Compute the cross section tables directly or */
/*     compute the FEQX input form for later editing before the */
/*     cross section tables are computed. */
/* SOURCE wspro.for:1899 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE wspro.for:1902 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE wspro.for:1903 */
/*<       integertabdir(*) >*/
/* SOURCE wspro.for:1904 */
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
/* INCLUDE wspro.for:1916 */
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
/* INCLUDE wspro.for:1917 */
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
/* INCLUDE wspro.for:1918 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE wspro.for:1919 */
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
/* INCLUDE wspro.for:1920 */
/*     Common block for the variables needed to process WSPRO */
/*     cross sections. */
/*     Parameters for dimensions */
/* SOURCE wsproxs.cmn:6 */
/*<       integermxnfl,mxngp,mxnsa >*/
/* SOURCE wsproxs.cmn:8 */
/*<       parameter(mxnfl=3,mxngp=100,mxnsa=20) >*/
/*     AS record variables */
/* SOURCE wsproxs.cmn:12 */
/*<       integerasflag >*/
/* SOURCE wsproxs.cmn:14 */
/*<       realsrd,skew,ek,ck,vslope >*/
/*     FL record variables */
/* SOURCE wsproxs.cmn:18 */
/*<       integerflflag,ihfno,nfl >*/
/* SOURCE wsproxs.cmn:20 */
/*<       realfldat(2*mxnfl),flen(mxnfl),xfl(mxnfl),yfl(mxnfl) >*/
/*     GR Record */
/* SOURCE wsproxs.cmn:24 */
/*<       integergrflag,ngp >*/
/* SOURCE wsproxs.cmn:26 */
/*<       realgrsrd,xgr(mxngp),ygr(mxngp),x(mxngp),y(mxngp) >*/
/*     GT Record */
/* SOURCE wsproxs.cmn:30 */
/*<       integergtflag >*/
/* SOURCE wsproxs.cmn:32 */
/*<       realyshift,xliml,xlimr,scale,xorig >*/
/*     N Record */
/* SOURCE wsproxs.cmn:36 */
/*<       integernflag,nn >*/
/* SOURCE wsproxs.cmn:38 */
/*<       realnval(2*mxnsa),botn(mxnsa),topn(mxnsa) >*/
/*     ND Record */
/* SOURCE wsproxs.cmn:42 */
/*<       integerndflag,nnd >*/
/* SOURCE wsproxs.cmn:44 */
/*<       realnndbrk(2*mxnsa),botd(mxnsa),topd(mxnsa) >*/
/*     SA Record */
/* SOURCE wsproxs.cmn:49 */
/*<       integersaflag,nsa,nsat >*/
/* SOURCE wsproxs.cmn:51 */
/*<       realxsa(mxnsa),xsat(mxnsa) >*/
/*     XR Record */
/* SOURCE wsproxs.cmn:55 */
/*<       integerxrflag,ipave >*/
/* SOURCE wsproxs.cmn:57 */
/*<       realembwid,usercf >*/
/*     XS Record */
/* SOURCE wsproxs.cmn:61 */
/*<       integerxsflag >*/
/*     XT Record */
/* SOURCE wsproxs.cmn:65 */
/*<       integerxtflag,xtngp,xtnsa >*/
/* SOURCE wsproxs.cmn:67 */
/*<       realxtsrd,xtxgr(mxngp),xtygr(mxngp),xtxsa(mxnsa) >*/
/* SOURCE wsproxs.cmn:69 */
/*<        >*/
/* INCLUDE wspro.for:1921 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE wspro.for:1922 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE wspro.for:1925 */
/*<       characterstaout*18 >*/
/* SOURCE wspro.for:1926 */
/*<       savestaout >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE wspro.for:1929 */
/*<        >*/
/* SOURCE wspro.for:1932 */
/*<        >*/
/* SOURCE wspro.for:1935 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE wspro.for:1944 */
/*<       intrinsicabs,max,min >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE wspro.for:1947 */
/*<       integerstrlen >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE wspro.for:1950 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE wspro.for:1954 */
/*<       datastaout/'(''STATION='','/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* SOURCE wspro.for:1957 */
/*<    50 format(//) >*/
/* L50: */
/* SOURCE wspro.for:1958 */
/*<    51 format(/,' TABID=',i8) >*/
/* L51: */
/* SOURCE wspro.for:1959 */
/*<    52 format(' NAVM=',a5,'  SCALE=',f10.3,' SHIFT=',f10.3) >*/
/* L52: */
/* SOURCE wspro.for:1960 */
/*<    53 format(' STATION=',f10.3,' LEFT=',f10.1,' RIGHT=',f10.1) >*/
/* L53: */
/* SOURCE wspro.for:1961 */
/*<    54 format(' STATION=',f10.3) >*/
/* L54: */
/* SOURCE wspro.for:1962 */
/*<    55 format(1x,'NSUB',i5,6f6.3,1x,/,(10x,6f6.3)) >*/
/* L55: */
/* SOURCE wspro.for:1963 */
/*<    58 format(' *ERR:504* NUMBER OF SUBSECTIONS=',i5,' > ',i5) >*/
/* L58: */
/* SOURCE wspro.for:1964 */
/*<    61  >*/
/* L61: */
/* SOURCE wspro.for:1966 */
/*<    67  >*/
/* L67: */
/* SOURCE wspro.for:1968 */
/*<    68  >*/
/* L68: */
/* SOURCE wspro.for:1970 */
/*<    69  >*/
/* L69: */
/* SOURCE wspro.for:1973 */
/*<    70 format('     OFFSET ELEVATION SUBS',3x,a8) >*/
/* L70: */
/* SOURCE wspro.for:1974 */
/*<    72 format(' ',f10.2,f10.2,i5) >*/
/* L72: */
/* SOURCE wspro.for:1975 */
/*<    73 format(' ',f10.2,f10.2,i5,f6.3,8(f5.1,f6.3)) >*/
/* L73: */
/* SOURCE wspro.for:1976 */
/*<    75 format('TABID=',i8,2x,a8,1x,a8,1x,a8,1x,a8) >*/
/* L75: */
/* SOURCE wspro.for:1977 */
/*<    76 format('TABID=',i8,'  EXTEND',2x,a8,1x,a8,1x,a8,1x,a8) >*/
/* L76: */
/* SOURCE wspro.for:1978 */
/*<    77 format('FEQXEXT') >*/
/* L77: */
/* SOURCE wspro.for:1979 */
/*<    78 format('VARN=HYDY') >*/
/* L78: */
/* SOURCE wspro.for:1980 */
/*<    79 format('VARN=NCON') >*/
/* L79: */
/* SOURCE wspro.for:1981 */
/*<    80 format('NSUB',i5,6f10.3,/,(9x,6f10.3)) >*/
/* L80: */
/* SOURCE wspro.for:1982 */
/*<    81 format('    OFFSET ELEVATION SUBS',2x,a8) >*/
/* L81: */
/* SOURCE wspro.for:1983 */
/*<    82 format(f10.2,f10.2,i5,f6.3,8(f5.1,f6.3)) >*/
/* L82: */
/* SOURCE wspro.for:1984 */
/*<    84  >*/
/* L84: */
/* SOURCE wspro.for:1987 */
/*<    86 format('STAT',6f10.4) >*/
/* L86: */
/* SOURCE wspro.for:1988 */
/*<    88 format('OFFS',6f10.2) >*/
/* L88: */
/* SOURCE wspro.for:1989 */
/*<    90 format(i10) >*/
/* L90: */
/* *********************************************************************** */
/* SOURCE wspro.for:1991 */
/*<       zone='NONE' >*/
    s_copy(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE wspro.for:1992 */
/*<       hgrid='NONE' >*/
    s_copy(hgrid, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE wspro.for:1993 */
/*<       vdatum='NONE' >*/
    s_copy(vdatum, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE wspro.for:1994 */
/*<       unitsys='NONE' >*/
    s_copy(unitsys, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE wspro.for:1995 */
/*<       basis='NONE' >*/
    s_copy(basis, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/*     Clear values not set */
/* SOURCE wspro.for:1997 */
/*<       gisid=' ' >*/
    s_copy(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE wspro.for:1998 */
/*<       northing=0.d0 >*/
    xtadd_1.northing = 0.;
/* SOURCE wspro.for:1999 */
/*<       easting=0.d0 >*/
    xtadd_1.easting = 0.;
/*     CLEAR THE ERROR FLAG.  USED TO DETECT PROBLEMS THAT REQUIRE */
/*     EARLY EXITS FROM PROCESSING */
/* SOURCE wspro.for:2004 */
/*<       eflag=0 >*/
    *eflag = 0;
/*     CLEAR THE VALUES that may not be needed to represent the */
/*     cross section but are  USED IN THE COMPUTATION OF THE TABLE. */
/* SOURCE wspro.for:2009 */
/*<       do95i=1,pmxsub >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 200; ++feq_gen_i_d_) {
/* SOURCE wspro.for:2010 */
/*<       nnyu(i)=0 >*/
	xscomu_1.nnyu[feq_gen_i_d_ - 1] = 0;
/* SOURCE wspro.for:2011 */
/*<       nvaru(i)=0 >*/
	xscomu_1.nvaru[feq_gen_i_d_ - 1] = 0;
/* SOURCE wspro.for:2012 */
/*<    95 continue >*/
/* L95: */
    }
/* SOURCE wspro.for:2014 */
/*<       do96i=1,pmxpnt >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 999; ++feq_gen_i_d_) {
/* SOURCE wspro.for:2015 */
/*<       snu(i)=1.0 >*/
	xscomu_1.snu[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE wspro.for:2016 */
/*<       lsnu(i)=0.0 >*/
	xscomu_1.lsnu[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE wspro.for:2017 */
/*<    96 continue >*/
/* L96: */
    }
/* SOURCE wspro.for:2019 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/*     Set the value of the command being processed with its length */
/* SOURCE wspro.for:2022 */
/*<       sfpnam='WSPRO' >*/
    s_copy(sfpnam, const_cast<char*>("WSPRO"), (ftnlen)8, (ftnlen)5);
/* SOURCE wspro.for:2023 */
/*<       sfpn=5 >*/
    sfpn = 5;
/*     INPUT THE CONTROLLING DATA */
/* SOURCE wspro.for:2026 */
/*<        >*/
    insfpx_(stdin, stdout, sfpnam, &sfpn, savopt, outopt, betopt, monflg, 
	    eflag, mode, &begtab, &tabinc, &begsta, &stadir, &sfac, zone, 
	    hgrid, vdatum, unitsys, basis, &xtadd_1.easting, &
	    xtadd_1.northing, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8);
/* SOURCE wspro.for:2032 */
/*<       if(eflag.eq.1)return >*/
    if (*eflag == 1) {
	return 0;
    }
/*     SET THE INPUT UNIT NUMBER */
/* SOURCE wspro.for:2036 */
/*<       in=std48 >*/
    in = feq_gen_stdun_com_d_1.std48;
/* SOURCE wspro.for:2038 */
/*<       if(mode.eq.'CHANNEL'.or.mode.eq.'channel')then >*/
    if (s_cmp(mode, const_cast<char*>("CHANNEL"), (ftnlen)8, (ftnlen)7) == 0 || s_cmp(mode, 
	    const_cast<char*>("channel"), (ftnlen)8, (ftnlen)7) == 0) {
/*       Set flag for convenience */
/* SOURCE wspro.for:2040 */
/*<       chflag=1 >*/
	chflag = 1;
/* SOURCE wspro.for:2041 */
/*<       idsn=std50 >*/
	idsn = feq_gen_stdun_com_d_1.std50;
/* SOURCE wspro.for:2042 */
/*<       else >*/
    } else {
/* SOURCE wspro.for:2043 */
/*<       chflag=0 >*/
	chflag = 0;
/* SOURCE wspro.for:2044 */
/*<       idsn=std49 >*/
	idsn = feq_gen_stdun_com_d_1.std49;
/* SOURCE wspro.for:2045 */
/*<       endif >*/
    }
/*     GET THE NEXT CROSS SECTION FROM THE WPRO INPUT.  WHEN A */
/*     COMPLETE CROSS SECTION HAS BEEN DEFINED, RETURN WITH */
/*     THE FEQX INPUT AND PROCESS.  RETURN A FLAG WHEN NO */
/*     CROSS SECTION HAS BEEN FOUND.  THIS TERMINATES THE PROCESSING */
/*     OF THE FILE. */
/*     START THE TABLE NUMBERS */
/* SOURCE wspro.for:2055 */
/*<       tabu=begtab >*/
    xscomu_1.tabu = begtab;
/*     ENABLE CONVEYANCE WARNING MESSAGES */
/* SOURCE wspro.for:2059 */
/*<       nocm=0 >*/
    nrdzcm_1.nocm = 0;
/* SOURCE wspro.for:2060 */
/*<       slot=0.0 >*/
    nrdzcm_1.slot = (float)0.;
/*     Set the initial station value.  Should be in the same scale */
/*     as the stations on the WSPRO records. */
/* SOURCE wspro.for:2065 */
/*<       statu=begsta >*/
    xscomu_1.statu = begsta;
/*     Initialize the values in common for processing WSPRO input */
/* SOURCE wspro.for:2069 */
/*<       callproint >*/
    proint_();
/*     Clear the flag for the input line being present */
/* SOURCE wspro.for:2072 */
/*<       lnflag=0 >*/
    lnflag = 0;
/* SOURCE wspro.for:2074 */
/*<       oldid='  ' >*/
    s_copy(oldid, const_cast<char*>("  "), (ftnlen)2, (ftnlen)2);
/*     Set the flag for the first call */
/* SOURCE wspro.for:2077 */
/*<       first=1 >*/
    first = 1;
/*     Clear the open channel cross section counter. */
/* SOURCE wspro.for:2079 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE wspro.for:2080 */
/*<   100 continue >*/
L100:
/*       Check the table number. */
/* SOURCE wspro.for:2084 */
/*<       if(tabu.ge.0)calltabchk(stdout,pmxtab,tabu,tabdir,eflag) >*/
    if (xscomu_1.tabu >= 0) {
	tabchk_(stdout, &feq_gen_c_d_10002, &xscomu_1.tabu, &tabdir[1], eflag);
    }
/*       Clear the flag for cross section presence. */
/* SOURCE wspro.for:2089 */
/*<       xflag=0 >*/
    xflag = 0;
/* SOURCE wspro.for:2091 */
/*<        >*/
    scnpro_(&in, stdout, &xscomu_1.mxpntu, &stadir, &xscomu_1.statu, 
	    xscomu_1.sbu, xscomu_1.lsnu, &lnflag, &xflag, oldid, &first, &
	    statl, &statr, &xscomu_1.npntu, &xscomu_1.nsubu, xscomu_1.xu, 
	    xscomu_1.zu, xscomu_1.nu, xscomu_1.nvaru, xscomu_1.natyu, 
	    xscomu_1.yatnu, xscomu_1.nnyu, eflag, &left, &right, xsname, &
	    ncon, xfline, (ftnlen)2, (ftnlen)5);
/* SOURCE wspro.for:2098 */
/*<       if(xflag.eq.-1)then >*/
    if (xflag == -1) {
/* SOURCE wspro.for:2099 */
/*<       close(std48) >*/
	feq_gen_cl_d_1.cerr = 0;
	feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std48;
	feq_gen_cl_d_1.csta = 0;
	f_clos(&feq_gen_cl_d_1);
/* SOURCE wspro.for:2100 */
/*<       if(mode.eq.'indirect'.or.mode.eq.'INDIRECT')then >*/
	if (s_cmp(mode, const_cast<char*>("indirect"), (ftnlen)8, (ftnlen)8) == 0 || s_cmp(mode, 
		const_cast<char*>("INDIRECT"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE wspro.for:2101 */
/*<       close(std49) >*/
	    feq_gen_cl_d_1.cerr = 0;
	    feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std49;
	    feq_gen_cl_d_1.csta = 0;
	    f_clos(&feq_gen_cl_d_1);
/* SOURCE wspro.for:2102 */
/*<       elseif(mode.eq.'CHANNEL'.or.mode.eq.'channel')then >*/
	} else if (s_cmp(mode, const_cast<char*>("CHANNEL"), (ftnlen)8, (ftnlen)7) == 0 || s_cmp(
		mode, const_cast<char*>("channel"), (ftnlen)8, (ftnlen)7) == 0) {
/*           Output the sinuousity information to the file */
/*           on STD49 and append to it the material in the */
/*           file on STD50.  Output the command and the */
/*           heading information. */
/* SOURCE wspro.for:2107 */
/*<       write(std49,84) >*/
	    feq_gen_io_d__303.ciunit = feq_gen_stdun_com_d_1.std49;
	    s_wsfe(&feq_gen_io_d__303);
	    e_wsfe();
/* SOURCE wspro.for:2108 */
/*<       do102i=1,knt >*/
	    feq_gen_i_d_1 = knt;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:2109 */
/*<        >*/
		feq_gen_io_d__304.ciunit = feq_gen_stdun_com_d_1.std49;
		s_wsfe(&feq_gen_io_d__304);
		do_fio(&feq_gen_c_d_1, (char *)&stat[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&stat[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&stat[feq_gen_i_d_ + 399], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&stat[feq_gen_i_d_ + 399], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&stat[feq_gen_i_d_ + 799], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&stat[feq_gen_i_d_ + 799], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE wspro.for:2111 */
/*<       write(std49,88)(floff(i,j),j=1,6) >*/
		feq_gen_io_d__306.ciunit = feq_gen_stdun_com_d_1.std49;
		s_wsfe(&feq_gen_io_d__306);
		for (j = 1; j <= 6; ++j) {
		    do_fio(&feq_gen_c_d_1, (char *)&floff[feq_gen_i_d_ + j * 400 - 401], (
			    ftnlen)sizeof(real));
		}
		e_wsfe();
/* SOURCE wspro.for:2112 */
/*<   102 continue >*/
/* L102: */
	    }
/* SOURCE wspro.for:2113 */
/*<       write(std49,'(A)')'END' >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std49;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("END"), (ftnlen)3);
	    e_wsfe();
/* SOURCE wspro.for:2114 */
/*<       rewind(std50) >*/
	    feq_gen_al_d_1.aerr = 0;
	    feq_gen_al_d_1.aunit = feq_gen_stdun_com_d_1.std50;
	    f_rew(&feq_gen_al_d_1);
/* SOURCE wspro.for:2115 */
/*<   103 continue >*/
L103:
/* SOURCE wspro.for:2116 */
/*<       read(std50,'(A)',end=104)line >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciend = 1;
	    feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std50;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    feq_gen_i_d_1 = s_rsfe(&feq_gen_ci_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L104;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
	    if (feq_gen_i_d_1 != 0) {
		goto L104;
	    }
	    feq_gen_i_d_1 = e_rsfe();
	    if (feq_gen_i_d_1 != 0) {
		goto L104;
	    }
/* SOURCE wspro.for:2117 */
/*<       endstr=strlen(line) >*/
	    endstr = strlen_(line, (ftnlen)120);
/* SOURCE wspro.for:2118 */
/*<       write(std49,'(A)')line(1:endstr) >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std49;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, line, endstr);
	    e_wsfe();
/* SOURCE wspro.for:2119 */
/*<       goto103 >*/
	    goto L103;
/* SOURCE wspro.for:2120 */
/*<   104 continue >*/
L104:
/* SOURCE wspro.for:2121 */
/*<       write(std49,'(A)')'ENDCHAN' >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = feq_gen_stdun_com_d_1.std49;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("ENDCHAN"), (ftnlen)7);
	    e_wsfe();
/* SOURCE wspro.for:2122 */
/*<       close(std49) >*/
	    feq_gen_cl_d_1.cerr = 0;
	    feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std49;
	    feq_gen_cl_d_1.csta = 0;
	    f_clos(&feq_gen_cl_d_1);
/* SOURCE wspro.for:2123 */
/*<       close(std50) >*/
	    feq_gen_cl_d_1.cerr = 0;
	    feq_gen_cl_d_1.cunit = feq_gen_stdun_com_d_1.std50;
	    feq_gen_cl_d_1.csta = 0;
	    f_clos(&feq_gen_cl_d_1);
/* SOURCE wspro.for:2124 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2125 */
/*<       return >*/
	return 0;
/* SOURCE wspro.for:2126 */
/*<       endif >*/
    }
/* SOURCE wspro.for:2127 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/* SOURCE wspro.for:2129 */
/*<       if(chflag.eq.1.and.xu(1).lt.xu(npntu))then >*/
    if (chflag == 1 && xscomu_1.xu[0] < xscomu_1.xu[xscomu_1.npntu - 1]) {
/*         Making a CHANNEL command.  Save the sinuousity-defining */
/*         data. */
/* SOURCE wspro.for:2132 */
/*<       knt=knt+1 >*/
	++knt;
/* SOURCE wspro.for:2133 */
/*<       stat(knt,1)=statl/sfac >*/
	stat[knt - 1] = static_cast<double>(statl) / sfac;
/* SOURCE wspro.for:2134 */
/*<       stat(knt,2)=statu/sfac >*/
	stat[knt + 399] = static_cast<double>(xscomu_1.statu) / sfac;
/* SOURCE wspro.for:2135 */
/*<       stat(knt,3)=statr/sfac >*/
	stat[knt + 799] = static_cast<double>(statr) / sfac;
/* SOURCE wspro.for:2136 */
/*<       do105i=1,6 >*/
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 6; ++feq_gen_i_d_) {
/* SOURCE wspro.for:2137 */
/*<       floff(knt,i)=xfline(i) >*/
	    floff[knt + feq_gen_i_d_ * 400 - 401] = xfline[feq_gen_i_d_ - 1];
/* SOURCE wspro.for:2138 */
/*<   105 continue >*/
/* L105: */
	}
/* SOURCE wspro.for:2139 */
/*<       endif >*/
    }
/* SOURCE wspro.for:2140 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__311.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__311);
    e_wsfe();
/* SOURCE wspro.for:2141 */
/*<       write(stdout,51)tabu >*/
    feq_gen_io_d__312.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__312);
    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.tabu, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE wspro.for:2142 */
/*<       if(left.ge.right)then >*/
    if (left >= right) {
/* SOURCE wspro.for:2143 */
/*<       write(stdout,54)statu/sfac >*/
	feq_gen_io_d__313.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__313);
	feq_gen_r_d_1 = static_cast<double>(xscomu_1.statu) / sfac;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE wspro.for:2144 */
/*<       else >*/
    } else {
/* SOURCE wspro.for:2145 */
/*<       write(stdout,53)statu/sfac,left,right >*/
	feq_gen_io_d__314.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__314);
	feq_gen_r_d_1 = static_cast<double>(xscomu_1.statu) / sfac;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&left, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&right, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE wspro.for:2146 */
/*<       endif >*/
    }
/* SOURCE wspro.for:2147 */
/*<       if(ncon.eq.1)then >*/
    if (ncon == 1) {
/* SOURCE wspro.for:2148 */
/*<       write(stdout,52)'    0',scale,yshift >*/
	feq_gen_io_d__315.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__315);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("    0"), (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.scale, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.yshift, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE wspro.for:2149 */
/*<       else >*/
    } else {
/* SOURCE wspro.for:2150 */
/*<       write(stdout,52)'HYDY ',scale,yshift >*/
	feq_gen_io_d__316.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__316);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("HYDY "), (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.scale, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&wxprox_1.yshift, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE wspro.for:2151 */
/*<       endif >*/
    }
/* SOURCE wspro.for:2153 */
/*<       if(nsubu.gt.pmxsub)then >*/
    if (xscomu_1.nsubu > 200) {
/* SOURCE wspro.for:2154 */
/*<       write(stdout,58)nsubu,pmxsub >*/
	feq_gen_io_d__317.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__317);
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nsubu, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_200, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE wspro.for:2155 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE wspro.for:2156 */
/*<       nsubu=pmxsub >*/
	xscomu_1.nsubu = 200;
/* SOURCE wspro.for:2157 */
/*<       endif >*/
    }
/* SOURCE wspro.for:2159 */
/*<       write(stdout,55)nsubu,(nu(j),j=1,nsubu) >*/
    feq_gen_io_d__318.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__318);
    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nsubu, (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = xscomu_1.nsubu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nu[j - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
/*       CHECK FOR MONOTONICITY */
/* SOURCE wspro.for:2162 */
/*<       zmax=-9999999. >*/
    zmax = (float)-9999999.;
/* SOURCE wspro.for:2163 */
/*<       xold=-1.e20 >*/
    xold = (float)-1e20;
/* SOURCE wspro.for:2165 */
/*<       write(stdout,70)xsname >*/
    feq_gen_io_d__321.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__321);
    do_fio(&feq_gen_c_d_1, xsname, (ftnlen)5);
    e_wsfe();
/* SOURCE wspro.for:2167 */
/*<       oldsub=0 >*/
    oldsub = 0;
/* SOURCE wspro.for:2168 */
/*<       do110j=1,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE wspro.for:2170 */
/*<       isub=sbu(j) >*/
	isub = xscomu_1.sbu[j - 1];
/* SOURCE wspro.for:2171 */
/*<       if(isub.lt.0)then >*/
	if (isub < 0) {
/* SOURCE wspro.for:2172 */
/*<       write(stdout,72)xu(j),zu(j),isub >*/
	    feq_gen_io_d__324.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__324);
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE wspro.for:2173 */
/*<       else >*/
	} else {
/* SOURCE wspro.for:2174 */
/*<       if(isub.eq.oldsub)then >*/
	    if (isub == oldsub) {
/* SOURCE wspro.for:2175 */
/*<       write(stdout,72)xu(j),zu(j),isub >*/
		feq_gen_io_d__325.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__325);
		do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE wspro.for:2176 */
/*<       else >*/
	    } else {
/* SOURCE wspro.for:2178 */
/*<       if(nvaru(isub).gt.0)then >*/
		if (xscomu_1.nvaru[isub - 1] > 0) {
/*               n varies with depth.  Output the details. */
/* SOURCE wspro.for:2180 */
/*<        >*/
		    feq_gen_io_d__326.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__326);
		    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.sbu[j - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.natyu[isub * 9 - 9], (
			    ftnlen)sizeof(real));
		    feq_gen_i_d_2 = xscomu_1.nnyu[isub - 1];
		    for (k = 2; k <= feq_gen_i_d_2; ++k) {
			do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.yatnu[k + isub * 9 - 
				10], (ftnlen)sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.natyu[k + isub * 9 - 
				10], (ftnlen)sizeof(real));
		    }
		    e_wsfe();
/* SOURCE wspro.for:2182 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:2183 */
/*<       write(stdout,72)xu(j),zu(j),isub >*/
		    feq_gen_io_d__328.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__328);
		    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE wspro.for:2184 */
/*<       endif >*/
		}
/* SOURCE wspro.for:2185 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:2186 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2187 */
/*<       oldsub=isub >*/
	oldsub = isub;
/*         FIND MAXIMUM ELEVATION IN CROSS SECTION FOR LATER CHECKING */
/* SOURCE wspro.for:2191 */
/*<       zmax=max(zu(j),zmax) >*/
/* Computing MAX */
	feq_gen_r_d_1 = xscomu_1.zu[j - 1];
	zmax = dmax(feq_gen_r_d_1,zmax);
/*         CHECK FOR MONOTONICITY OF TOP WIDTH.  THIS REQUIRES THAT */
/*         THE OFFSET NEVER DECREASE. */
/* SOURCE wspro.for:2196 */
/*<       if(monflg.eq.'MONOTONE')then >*/
	if (s_cmp(monflg, const_cast<char*>("MONOTONE"), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE wspro.for:2197 */
/*<       if(xu(j).lt.xold)then >*/
	    if (xscomu_1.xu[j - 1] < xold) {
/* SOURCE wspro.for:2198 */
/*<        >*/
		feq_gen_io_d__329.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__329);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:508* SECTION VIOLATES MONOTONICI\
TY AT OFFSET="), (ftnlen)51);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)
			sizeof(real));
		e_wsle();
/* SOURCE wspro.for:2200 */
/*<       eflag=eflag+1 >*/
		++(*eflag);
/* SOURCE wspro.for:2201 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:2202 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2204 */
/*<       xold=xu(j) >*/
	xold = xscomu_1.xu[j - 1];
/* SOURCE wspro.for:2206 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE wspro.for:2209 */
/*<       if(npntu.le.1)then >*/
    if (xscomu_1.npntu <= 1) {
/* SOURCE wspro.for:2210 */
/*<       write(stdout,61) >*/
	feq_gen_io_d__330.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__330);
	e_wsfe();
/* SOURCE wspro.for:2211 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE wspro.for:2212 */
/*<       endif >*/
    }
/*       CHECK THE CROSS SECTION FOR NONSENSE BEHAVIOR AT THE END */
/* SOURCE wspro.for:2216 */
/*<       if(zu(1).le.zu(2).and.xu(2).gt.xu(1))then >*/
    if (xscomu_1.zu[0] <= xscomu_1.zu[1] && xscomu_1.xu[1] > xscomu_1.xu[0]) {
/*         THE LEFT MOST LINE SEGMENT HAS UPWARD SLOPE, THEREFORE HIGH */
/*         POINT IS NOT AT THE LEFT LIMIT. */
/* SOURCE wspro.for:2220 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" *WRN:502* UNEXPECTED SLOPE"), (ftnlen)27);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" AT LEFT END."), (ftnlen)13);
	e_wsfe();
/* SOURCE wspro.for:2222 */
/*<       write(stdout,*)'  SLOPE EXPECTED TO BE < 0  AT LEFT BOUNDARY' >*/
	feq_gen_io_d__331.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__331);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  SLOPE EXPECTED TO BE < 0  AT LEFT BOUNDARY"), (
		ftnlen)44);
	e_wsle();
/* SOURCE wspro.for:2223 */
/*<       endif >*/
    }
/* SOURCE wspro.for:2224 */
/*<       if(zu(npntu).le.zu(npntu-1).and.xu(npntu).gt.xu(npntu-1))then >*/
    if (xscomu_1.zu[xscomu_1.npntu - 1] <= xscomu_1.zu[xscomu_1.npntu - 2] && 
	    xscomu_1.xu[xscomu_1.npntu - 1] > xscomu_1.xu[xscomu_1.npntu - 2])
	     {
/*         THE RIGHT MOST LINE SEGMENT HAS DOWNWARD SLOPE */
/* SOURCE wspro.for:2227 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" *WRN:503* UNEXPECTED SLOPE"), (ftnlen)27);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" AT RIGHT END."), (ftnlen)14);
	e_wsfe();
/* SOURCE wspro.for:2229 */
/*<       write(stdout,*)'  SLOPE EXPECTED TO BE > 0 AT RIGHT BOUNDARY' >*/
	feq_gen_io_d__332.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__332);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  SLOPE EXPECTED TO BE > 0 AT RIGHT BOUNDARY"), (
		ftnlen)44);
	e_wsle();
/* SOURCE wspro.for:2230 */
/*<       endif >*/
    }
/* SOURCE wspro.for:2232 */
/*<       if(extend.eq.1)then >*/
    if (nrdzcm_1.extend == 1) {
/*         CHECK FOR ONE END BEING HIGHER THAN THE OTHER */
/* SOURCE wspro.for:2235 */
/*<       if(abs(zmax-zu(1)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[0], dabs(feq_gen_r_d_1)) > epscom_1.epsdif) {
/* SOURCE wspro.for:2236 */
/*<       write(stdout,67)zmax-zu(1) >*/
	    feq_gen_io_d__333.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__333);
	    feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[0];
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE wspro.for:2237 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2238 */
/*<       if(abs(zmax-zu(npntu)).gt.epsdif)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[xscomu_1.npntu - 1], dabs(feq_gen_r_d_1)) > 
		epscom_1.epsdif) {
/* SOURCE wspro.for:2239 */
/*<       write(stdout,68)zmax-zu(npntu) >*/
	    feq_gen_io_d__334.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__334);
	    feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[xscomu_1.npntu - 1];
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE wspro.for:2240 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2241 */
/*<       else >*/
    } else {
/*         CHECK FOR AN INTERMEDIATE POINT BEING HIGHER THAN EITHER */
/*         END */
/* SOURCE wspro.for:2244 */
/*<        >*/
	if ((feq_gen_r_d_1 = static_cast<double>(zmax) - xscomu_1.zu[0], dabs(feq_gen_r_d_1)) > epscom_1.epsabs && (
		feq_gen_r_d_2 = static_cast<double>(zmax) - xscomu_1.zu[xscomu_1.npntu - 1], dabs(feq_gen_r_d_2)) > 
		epscom_1.epsabs) {
/* SOURCE wspro.for:2246 */
/*<       write(stdout,69) >*/
	    feq_gen_io_d__335.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__335);
	    e_wsfe();
/* SOURCE wspro.for:2247 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2249 */
/*<       zmax=min(zu(1),zu(npntu)) >*/
/* Computing MIN */
	feq_gen_r_d_1 = xscomu_1.zu[0], feq_gen_r_d_2 = xscomu_1.zu[xscomu_1.npntu - 1];
	zmax = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE wspro.for:2250 */
/*<       endif >*/
    }
/*       ASSIGN THE VALUES OF N FROM THE SUBSECTIONS TO THE LINE SEGMENT */
/*       LOCATIONS. */
/* SOURCE wspro.for:2254 */
/*<       do120i=1,npntu-1 >*/
    feq_gen_i_d_1 = xscomu_1.npntu - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE wspro.for:2255 */
/*<       lsnu(i)=nu(sbu(i)) >*/
	xscomu_1.lsnu[feq_gen_i_d_ - 1] = xscomu_1.nu[xscomu_1.sbu[feq_gen_i_d_ - 1] - 1];
/* SOURCE wspro.for:2256 */
/*<   120 continue >*/
/* L120: */
    }
/* SOURCE wspro.for:2259 */
/*<       if(mode.eq.'DIRECT'.or.mode.eq.'direct')then >*/
    if (s_cmp(mode, const_cast<char*>("DIRECT"), (ftnlen)8, (ftnlen)6) == 0 || s_cmp(mode, const_cast<char*>("dir\
ect"), (ftnlen)8, (ftnlen)6) == 0) {
/*         COMPUTE ELEMENTS FOR CURRENT CROSS SECTION */
/* SOURCE wspro.for:2263 */
/*<       if(npntu.gt.1)then >*/
	if (xscomu_1.npntu > 1) {
/*           FIND THE MAXIMUM AND MINIMUM ARGUMENT VALUES */
/* SOURCE wspro.for:2265 */
/*<       zminu=9999999. >*/
	    xscomu_1.zminu = (float)9999999.;
/* SOURCE wspro.for:2266 */
/*<       zmaxu=-9999999. >*/
	    xscomu_1.zmaxu = (float)-9999999.;
/* SOURCE wspro.for:2267 */
/*<       do150j=1,npntu >*/
	    feq_gen_i_d_1 = xscomu_1.npntu;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE wspro.for:2268 */
/*<       if(zu(j).gt.zmaxu)zmaxu=zu(j) >*/
		if (xscomu_1.zu[j - 1] > xscomu_1.zmaxu) {
		    xscomu_1.zmaxu = xscomu_1.zu[j - 1];
		}
/* SOURCE wspro.for:2269 */
/*<       if(zu(j).lt.zminu)zminu=zu(j) >*/
		if (xscomu_1.zu[j - 1] < xscomu_1.zminu) {
		    xscomu_1.zminu = xscomu_1.zu[j - 1];
		}
/* SOURCE wspro.for:2270 */
/*<   150 continue >*/
/* L150: */
	    }
/* SOURCE wspro.for:2272 */
/*<       if(extend.eq.0)zmaxu=zmax >*/
	    if (nrdzcm_1.extend == 0) {
		xscomu_1.zmaxu = zmax;
	    }
/* SOURCE wspro.for:2274 */
/*<       if(eflag.eq.0)then >*/
	    if (*eflag == 0) {
/* SOURCE wspro.for:2276 */
/*<        >*/
		cxstab_(stdout, &xscomu_1.nsubu, &xscomu_1.navmu, nfac, &
			xscomu_1.mxpntu, &left, &right, betopt, &
			xscomu_1.snflgu, xscomu_1.nvaru, xscomu_1.natyu, 
			xscomu_1.yatnu, xscomu_1.nnyu, &xscomu_1.npntu, &
			xscomu_1.zminu, &xscomu_1.zmaxu, xscomu_1.xu, 
			xscomu_1.zu, xscomu_1.sbu, eflag, xscomu_1.lsnu, 
			xscomu_1.snu, xscomu_1.nu, &xscomu_1.ndepu, 
			xscomu_1.xstu, (ftnlen)8);
/* SOURCE wspro.for:2283 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:2284 */
/*<       endif >*/
	}
/*         OUTPUT THE TABLE IF NO ERRORS AND IF OUTPUT IS REQUESTED */
/* SOURCE wspro.for:2288 */
/*<       if(eflag.ne.0.or.tabu.eq.0)goto200 >*/
	if (*eflag != 0 || xscomu_1.tabu == 0) {
	    goto L200;
	}
/* SOURCE wspro.for:2289 */
/*<       if(nocm.eq.1)then >*/
	if (nrdzcm_1.nocm == 1) {
/* SOURCE wspro.for:2290 */
/*<       mesg=0 >*/
	    mesg = 0;
/* SOURCE wspro.for:2291 */
/*<       else >*/
	} else {
/* SOURCE wspro.for:2292 */
/*<       mesg=1 >*/
	    mesg = 1;
/* SOURCE wspro.for:2293 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2294 */
/*<       statt=statu/sfac >*/
	statt = static_cast<double>(xscomu_1.statu) / sfac;
/*           Change the generated table number to a tabid and get */
/*           an internal table number. */
/* SOURCE wspro.for:2297 */
/*<       write(tabid,90)tabu >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 16;
	feq_gen_ici_d_1.iciunit = xtaddc_1.tabid;
	feq_gen_ici_d_1.icifmt = fmt_90;
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.tabu, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE wspro.for:2298 */
/*<       callstrip_l_blanks(tabid) >*/
	feq_gen_strip_l_blanks_d_(xtaddc_1.tabid, (ftnlen)16);
/* SOURCE wspro.for:2300 */
/*<       callget_internal_tab_number(stdout,tabid,eflag,itemp) >*/
	feq_gen_get_internal_tab_number_d_(stdout, xtaddc_1.tabid, eflag, &itemp, (
		ftnlen)16);
/*     compute derivatives of square root of conveyance, alpha, beta, */
/*     da, and dq */
/* SOURCE wspro.for:2307 */
/*<        >*/
	xsecfit_(stdout, &feq_gen_c_d_0, &xscomu_1.ndepu, xscomu_1.xstu, khflag, 
		alphaflag, betaflag, maflag, mqflag, (ftnlen)1, (ftnlen)1, (
		ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE wspro.for:2312 */
/*<        >*/
	tabout_(stdout, stdtab, &itemp, &statt, &xscomu_1.zminu, &mesg, 
		savopt, outopt, betopt, zone, hgrid, vdatum, unitsys, basis, 
		khflag, alphaflag, betaflag, maflag, mqflag, &xscomu_1.ndepu, 
		xscomu_1.xstu, ftp, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
		8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)1, (
		ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE wspro.for:2318 */
/*<   200 continue >*/
L200:
/* SOURCE wspro.for:2319 */
/*<       else >*/
	;
    } else {
/*         OUTPUT TO A scratch FILE ATTACHED TO UNIT IDSN */
/* SOURCE wspro.for:2322 */
/*<       write(idsn,77) >*/
	feq_gen_io_d__344.ciunit = idsn;
	s_wsfe(&feq_gen_io_d__344);
	e_wsfe();
/* SOURCE wspro.for:2324 */
/*<       if(extend.eq.0)then >*/
	if (nrdzcm_1.extend == 0) {
/* SOURCE wspro.for:2325 */
/*<       write(idsn,75)tabu,monflg,betopt,savopt,outopt >*/
	    feq_gen_io_d__345.ciunit = idsn;
	    s_wsfe(&feq_gen_io_d__345);
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.tabu, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, monflg, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, betopt, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, savopt, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, outopt, (ftnlen)8);
	    e_wsfe();
/* SOURCE wspro.for:2326 */
/*<       else >*/
	} else {
/* SOURCE wspro.for:2327 */
/*<       write(idsn,76)tabu,monflg,betopt,savopt,outopt >*/
	    feq_gen_io_d__346.ciunit = idsn;
	    s_wsfe(&feq_gen_io_d__346);
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.tabu, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, monflg, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, betopt, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, savopt, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, outopt, (ftnlen)8);
	    e_wsfe();
/* SOURCE wspro.for:2328 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2330 */
/*<       tp=statu/sfac >*/
	tp = static_cast<double>(xscomu_1.statu) / sfac;
/* SOURCE wspro.for:2331 */
/*<       callmkfmt(tp,10,f10x) >*/
	mkfmt_(&tp, &feq_gen_c_d_10, f10x, (ftnlen)5);
/* SOURCE wspro.for:2334 */
/*<       staout(13:18)=f10x//')' >*/
/* Writing concatenation */
	feq_gen_i_d_3[0] = 5, feq_gen_a_d_1[0] = f10x;
	feq_gen_i_d_3[1] = 1, feq_gen_a_d_1[1] = const_cast<char*>(")");
	s_cat(staout + 12, feq_gen_a_d_1, feq_gen_i_d_3, &feq_gen_c_d_2, (ftnlen)6);
/* SOURCE wspro.for:2335 */
/*<       write(idsn,staout)tp >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = idsn;
	feq_gen_ci_d_1.cifmt = feq::format_text(staout, sizeof(staout));
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&tp, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE wspro.for:2336 */
/*<       if(ncon.eq.1)then >*/
	if (ncon == 1) {
/* SOURCE wspro.for:2337 */
/*<       write(idsn,79) >*/
	    feq_gen_io_d__349.ciunit = idsn;
	    s_wsfe(&feq_gen_io_d__349);
	    e_wsfe();
/* SOURCE wspro.for:2338 */
/*<       else >*/
	} else {
/* SOURCE wspro.for:2339 */
/*<       write(idsn,78) >*/
	    feq_gen_io_d__350.ciunit = idsn;
	    s_wsfe(&feq_gen_io_d__350);
	    e_wsfe();
/* SOURCE wspro.for:2340 */
/*<       endif >*/
	}
/* SOURCE wspro.for:2341 */
/*<       write(idsn,80)nsubu,(nu(j),j=1,nsubu) >*/
	feq_gen_io_d__351.ciunit = idsn;
	s_wsfe(&feq_gen_io_d__351);
	do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nsubu, (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = xscomu_1.nsubu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.nu[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE wspro.for:2342 */
/*<       write(idsn,81)xsname >*/
	feq_gen_io_d__352.ciunit = idsn;
	s_wsfe(&feq_gen_io_d__352);
	do_fio(&feq_gen_c_d_1, xsname, (ftnlen)5);
	e_wsfe();
/* SOURCE wspro.for:2344 */
/*<       oldsub=0 >*/
	oldsub = 0;
/* SOURCE wspro.for:2345 */
/*<       do300j=1,npntu >*/
	feq_gen_i_d_1 = xscomu_1.npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE wspro.for:2346 */
/*<       isub=sbu(j) >*/
	    isub = xscomu_1.sbu[j - 1];
/* SOURCE wspro.for:2347 */
/*<       if(isub.lt.0)then >*/
	    if (isub < 0) {
/* SOURCE wspro.for:2348 */
/*<       write(idsn,82)xu(j),zu(j),isub >*/
		feq_gen_io_d__353.ciunit = idsn;
		s_wsfe(&feq_gen_io_d__353);
		do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE wspro.for:2349 */
/*<       else >*/
	    } else {
/* SOURCE wspro.for:2350 */
/*<       if(isub.eq.oldsub)then >*/
		if (isub == oldsub) {
/* SOURCE wspro.for:2351 */
/*<       write(idsn,82)xu(j),zu(j),isub >*/
		    feq_gen_io_d__354.ciunit = idsn;
		    s_wsfe(&feq_gen_io_d__354);
		    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE wspro.for:2352 */
/*<       else >*/
		} else {
/* SOURCE wspro.for:2354 */
/*<       if(nvaru(isub).gt.0)then >*/
		    if (xscomu_1.nvaru[isub - 1] > 0) {
/*                 n varies with depth.  Output the details. */
/* SOURCE wspro.for:2356 */
/*<        >*/
			feq_gen_io_d__355.ciunit = idsn;
			s_wsfe(&feq_gen_io_d__355);
			do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)
				sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)
				sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.sbu[j - 1], (ftnlen)
				sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.natyu[isub * 9 - 9], (
				ftnlen)sizeof(real));
			feq_gen_i_d_2 = xscomu_1.nnyu[isub - 1];
			for (k = 2; k <= feq_gen_i_d_2; ++k) {
			    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.yatnu[k + isub * 
				    9 - 10], (ftnlen)sizeof(real));
			    do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.natyu[k + isub * 
				    9 - 10], (ftnlen)sizeof(real));
			}
			e_wsfe();
/* SOURCE wspro.for:2358 */
/*<       else >*/
		    } else {
/* SOURCE wspro.for:2359 */
/*<       write(idsn,82)xu(j),zu(j),isub >*/
			feq_gen_io_d__356.ciunit = idsn;
			s_wsfe(&feq_gen_io_d__356);
			do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.xu[j - 1], (ftnlen)
				sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&xscomu_1.zu[j - 1], (ftnlen)
				sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&isub, (ftnlen)sizeof(integer));
			e_wsfe();
/* SOURCE wspro.for:2360 */
/*<       endif >*/
		    }
/* SOURCE wspro.for:2361 */
/*<       endif >*/
		}
/* SOURCE wspro.for:2362 */
/*<       endif >*/
	    }
/* SOURCE wspro.for:2363 */
/*<       oldsub=isub >*/
	    oldsub = isub;
/* SOURCE wspro.for:2365 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE wspro.for:2366 */
/*<       write(idsn,50) >*/
	feq_gen_io_d__357.ciunit = idsn;
	s_wsfe(&feq_gen_io_d__357);
	e_wsfe();
/* SOURCE wspro.for:2367 */
/*<       endif >*/
    }
/* SOURCE wspro.for:2369 */
/*<       tabu=tabu+tabinc >*/
    xscomu_1.tabu += tabinc;
/* SOURCE wspro.for:2370 */
/*<       goto100 >*/
    goto L100;
/* SOURCE wspro.for:2372 */
/*<       end >*/
} /* wprox_ */

#ifdef __cplusplus
	}
#endif
