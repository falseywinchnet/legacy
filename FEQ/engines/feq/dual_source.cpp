/* dual_source.f -- translated by f2c (version 20240504).
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

/* COMMON homec_ is declared in common.hpp. */

#define homec_1 homec_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_20 = 20;
static integer feq_gen_c_d_30 = 30;
static integer feq_gen_c_d_7 = 7;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_9 = 9;

/*     File containing the code for handling the dual-source input */
/*     block. */
/* SOURCE dual_source.for:3 */
/*<       subroutinedual_source(in,stdout,eflag) >*/
/* Subroutine */ int feq_gen_dual_source_d_(integer *in, integer *stdout, integer *
	eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *WRN:443* Equal sign missing in line dis\
played.\002,\002  Terminating character found is used.\002)";
    static char fmt_52[] = "(/,\002 *ERR:132* Cannot open file named:\002,/,\
5x,a,/,5x,\002 Check path for file name.\002)";
    static char fmt_54[] = "(\002 Writing header to dual_source file:\002,a)";
    static char fmt_56[] = "(/,\002 *ERR:133* Value for hour:\002,f12.2,\002\
 is out of range.\002)";
    static char fmt_58[] = "(/,\002 *ERR:203* Expected to find FILE, TABLE, \
HOME, or \002,\002TRAN_TAB but found:\002,/,a,/,5x,\002 instead.\002)";
    static char fmt_60[] = "(/,\002 *ERR:204* DEFINE block end-name: \002,a,\
/,11x,\002does not match start name: \002,a)";
    static char fmt_62[] = "(/,\002 *ERR:434 Apparent end of dual-source blo\
ck but DUAL\002,\002 SOURCE not found following END.\002)";
    static char fmt_64[] = "(/,\002 *ERR:435* Expected: \002,a,\002 but foun\
d: \002,a,\002 instead.\002)";
    static char fmt_66[] = "(/,\002 *ERR:436* TRAN_START is already known as\
: \002,i5,\002/\002,i2,\002/\002,i3,\002:\002,f14.4)";
    static char fmt_68[] = "(/,\002 *ERR:437* TRAN_END  is already known a\
s: \002,i5,\002/\002,i2,\002/\002,i3,\002:\002,f14.4)";
    static char fmt_70[] = "(/,\002 *ERR:438* Number of sources > 2.\002)";
    static char fmt_72[] = "(/,\002 *ERR:439* Transistion table not found\
.\002)";
    static char fmt_74[] = "(/,\002 *ERR:440*  Transition-start jtime=\002,f\
18.7,\002 > first source end jtime=\002,f18.7)";
    static char fmt_5701[] = "(2x,a,i5,\002/\002,i2,\002/\002,i3,\002:\002,f\
14.4)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_back(alist *), s_wsfe(
	    cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), f_open(
	    olist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue(), 
	    s_rdue(cilist *), e_rdue(), s_rsfi(icilist *), e_rsfi(), s_wsle(
	    cilist *), do_lio(integer *, integer *, char *, ftnlen), e_wsle(),
	     f_clos(cllist *);

    /* Local variables */
    char feq_gen_blk_name_d_[128];
    integer feq_gen_end_adrs_d_[2], stdfinal, feq_gen_item_knt_d_;
    extern integer feq_gen_get_unit_d_(integer *);
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_find_internal_tab_number_d_(char *, integer *, 
	    ftnlen);
    doublereal feq_gen_tran_start_jtime_d_, feq_gen_end_jtime_d_[2];
    extern /* Subroutine */ int feq_gen_get_items_d_(integer *, char *, integer *, 
	    integer *, char *, integer *, integer *, integer *, integer *, 
	    ftnlen, ftnlen), feq_gen_free_unit_d_(integer *, integer *);
    integer feq_gen_item_type_d_[20], is, it;
    char feq_gen_final_file_d_[256];
    extern /* Subroutine */ int feq_gen_clear_home_d_();
    char feq_gen_tran_tabid_d_[16];
    integer feq_gen_term_class_d_[20], feq_gen_start_adrs_d_[2];
    extern integer mjd_(integer *, integer *, integer *);
    doublereal feq_gen_jtime_break_d_, feq_gen_tran_end_hr_d_;
    integer feq_gen_tran_end_mn_d_, feq_gen_tran_end_dy_d_, feq_gen_item_length_d_[20], feq_gen_tran_end_yr_d_, 
	    feq_gen_source_adrs_d_[2];
    doublereal feq_gen_start_jtime_d_[2];
    char feq_gen_source_type_d_[5*2];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer irec;
    char line[196], what[1];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    char char16[16];
    real value;
    doublereal jtime;
    char items[128*20], tfile[256];
    real dummy;
    integer feq_gen_tran_tab_adrs_d_, feq_gen_record_length_d_;
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen);
    doublereal feq_gen_tran_start_hr_d_;
    integer feq_gen_tran_start_mn_d_, feq_gen_tran_start_dy_d_, feq_gen_tran_start_yr_d_;
    extern /* Subroutine */ int chkdat_(integer *, integer *, integer *, 
	    integer *, integer *), chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    integer ioflag;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     feq_gen_maybe_add_home_d_(char *, ftnlen);
    doublereal feq_gen_tran_end_jtime_d_;
    char unused[1], source[128*2];
    shortint feq_gen_file_structure_version_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, 0, 30 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, 0, 29 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__55 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__56 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__67 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__68 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__69 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_5701, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_5701, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__79 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, 0, 29 };
    static cilist feq_gen_io_d__92 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_62, 0 };


/*     Process dual-source time-series block.  User defines two or more */
/*     time series to be concatenated or merged to create a single time */
/*     series for use in a forced boundary condition. */
/* SOURCE dual_source.for:11 */
/*<       implicitnone >*/
/* SOURCE dual_source.for:12 */
/*<       integerin,stdout,eflag >*/
/* INCLUDE dual_source.for:14 */
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
/* INCLUDE dual_source.for:15 */
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
/* INCLUDE dual_source.for:16 */
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
/*     Called units */
/* SOURCE dual_source.for:19 */
/*<       integerget_unit,mjd >*/
/* SOURCE dual_source.for:20 */
/*<       externalget_unit,mjd >*/
/* SOURCE dual_source.for:21 */
/*<       characterjttoct*14 >*/
/*     Local */
/* SOURCE dual_source.for:25 */
/*<       integerchrval,intval,reaval,dprval >*/
/* SOURCE dual_source.for:26 */
/*<       parameter(intval=1,reaval=2,dprval=3,chrval=4) >*/
/* SOURCE dual_source.for:28 */
/*<       integermax_knt >*/
/* SOURCE dual_source.for:29 */
/*<       parameter(max_knt=20) >*/
/* SOURCE dual_source.for:31 */
/*<        >*/
/* SOURCE dual_source.for:35 */
/*<        >*/
/* SOURCE dual_source.for:42 */
/*<       integer*2file_structure_version >*/
/* SOURCE dual_source.for:43 */
/*<        >*/
/* SOURCE dual_source.for:47 */
/*<        >*/
/* SOURCE dual_source.for:51 */
/*<       realdummy,value >*/
/* SOURCE dual_source.for:53 */
/*<        >*/
/* SOURCE dual_source.for:56 */
/*<       characterwhat*1,unused*1 >*/
/* SOURCE dual_source.for:57 */
/*<        >*/
/*     *************************Formats********************************* */
/* SOURCE dual_source.for:3 */
/*<       integer feq_len_trim >*/
/* SOURCE dual_source.for:3 */
/*<       external feq_len_trim >*/
/* SOURCE dual_source.for:62 */
/*<    50  >*/
/* SOURCE dual_source.for:64 */
/*<    52  >*/
/* SOURCE dual_source.for:67 */
/*<    54 format(' Writing header to dual_source file:',a) >*/
/* SOURCE dual_source.for:68 */
/*<    56 format(/,' *ERR:133* Value for hour:',f12.2,' is out of range.') >*/
/* SOURCE dual_source.for:69 */
/*<    58  >*/
/* SOURCE dual_source.for:72 */
/*<    60  >*/
/* SOURCE dual_source.for:74 */
/*<    62  >*/
/* SOURCE dual_source.for:76 */
/*<    64 format(/,' *ERR:435* Expected: ',a,' but found: ',a,' instead.') >*/
/* SOURCE dual_source.for:77 */
/*<    66  >*/
/* SOURCE dual_source.for:79 */
/*<    68  >*/
/* SOURCE dual_source.for:81 */
/*<    70 format(/,' *ERR:438* Number of sources > 2.') >*/
/* SOURCE dual_source.for:82 */
/*<    72 format(/,' *ERR:439* Transistion table not found.') >*/
/* SOURCE dual_source.for:83 */
/*<    74  >*/
/* *********************************************************************** */
/*     Set some standard values */
/* SOURCE dual_source.for:87 */
/*<       file_structure_version=1 >*/
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
/* L66: */
/* L68: */
/* L70: */
/* L72: */
/* L74: */
    feq_gen_file_structure_version_d_ = 1;
/* SOURCE dual_source.for:88 */
/*<       what='Q' >*/
    *(unsigned char *)what = 'Q';
/* SOURCE dual_source.for:89 */
/*<       unused=' ' >*/
    *(unsigned char *)unused = ' ';
/* SOURCE dual_source.for:90 */
/*<       record_length=12 >*/
    feq_gen_record_length_d_ = 12;
/*     Clear the start and end year. If > 0 means user has supplied */
/*     a value. */
/* SOURCE dual_source.for:93 */
/*<       tran_start_yr=0 >*/
    feq_gen_tran_start_yr_d_ = 0;
/* SOURCE dual_source.for:94 */
/*<       tran_end_yr=0 >*/
    feq_gen_tran_end_yr_d_ = 0;
/*     Clear the local home name */
/* SOURCE dual_source.for:97 */
/*<       callclear_home() >*/
    feq_gen_clear_home_d_();
/* SOURCE dual_source.for:98 */
/*<       tran_tabid=' ' >*/
    s_copy(feq_gen_tran_tabid_d_, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/*     Read the next line from the input.  If it does not contain what */
/*     we expect, backspace the input file and return. */
/* SOURCE dual_source.for:103 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)196);
/* SOURCE dual_source.for:106 */
/*<       if(line(1:4).ne.'DUAL')then >*/
    if (s_cmp(line, const_cast<char*>("DUAL"), (ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE dual_source.for:107 */
/*<       backspace(in) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *in;
	f_back(&feq_gen_al_d_1);
/* SOURCE dual_source.for:108 */
/*<       return >*/
	return 0;
/* SOURCE dual_source.for:109 */
/*<       endif >*/
    }
/* SOURCE dual_source.for:111 */
/*<       write(stdout,'(/,a)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,a)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)196);
    e_wsfe();
/* SOURCE dual_source.for:114 */
/*<   100 continue >*/
L100:
/* SOURCE dual_source.for:115 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)196);
/* SOURCE dual_source.for:118 */
/*<       it=feq_len_trim(line) >*/
    it = feq_gen_feq_len_trim_d_(line, (ftnlen)196);
/* SOURCE dual_source.for:119 */
/*<       write(stdout,'(a)')line(1:it) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE dual_source.for:122 */
/*<        >*/
    feq_gen_get_items_d_(stdout, line, &feq_gen_c_d_20, &feq_gen_item_knt_d_, items, feq_gen_item_length_d_, 
	    feq_gen_item_type_d_, feq_gen_term_class_d_, eflag, (ftnlen)196, (ftnlen)128);
/*        write(stdout,5599) */
/*        do i=1,item_knt */
/*          write(stdout, 5600) items(i), item_length(i), item_type(i), */
/*     a                        term_class(i) */
/*        end do */
/* 5599  format('Item',35x,'Length  ','Type    ','Term Cls') */
/* 5600  format(a40,i8,i8,i8) */
/* SOURCE dual_source.for:132 */
/*<       if(items(1)(1:4)=='HOME'.or.items(1)(1:4)=='home')then >*/
    if (s_cmp(items, const_cast<char*>("HOME"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(items, const_cast<char*>("home")
	    , (ftnlen)4, (ftnlen)4) == 0) {
/*         Set the local home name */
/* SOURCE dual_source.for:134 */
/*<       if(term_class(1)/=equal)then >*/
	if (feq_gen_term_class_d_[0] != 8) {
/* SOURCE dual_source.for:135 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__18.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__18);
	    e_wsfe();
/* SOURCE dual_source.for:136 */
/*<       endif >*/
	}
/* SOURCE dual_source.for:137 */
/*<       home=items(2) >*/
	s_copy(homec_1.home, items + 128, (ftnlen)128, (ftnlen)128);
/* SOURCE dual_source.for:138 */
/*<       elseif(items(1)(1:6)=='DEFINE')then >*/
    } else if (s_cmp(items, const_cast<char*>("DEFINE"), (ftnlen)6, (ftnlen)6) == 0) {
/*         Start of a define block. */
/*         Get the file name */
/* SOURCE dual_source.for:142 */
/*<       final_file=items(2) >*/
	s_copy(feq_gen_final_file_d_, items + 128, (ftnlen)256, (ftnlen)128);
/* SOURCE dual_source.for:143 */
/*<       blk_name=final_file >*/
	s_copy(feq_gen_blk_name_d_, feq_gen_final_file_d_, (ftnlen)128, (ftnlen)256);
/* SOURCE dual_source.for:144 */
/*<       callmaybe_add_home(final_file) >*/
	feq_gen_maybe_add_home_d_(feq_gen_final_file_d_, (ftnlen)256);
/* SOURCE dual_source.for:146 */
/*<       callos_file_style(final_file) >*/
	feq_gen_os_file_style_d_(feq_gen_final_file_d_, (ftnlen)256);
/*         Open the file for writing */
/* SOURCE dual_source.for:149 */
/*<       stdfinal=get_unit(stdout) >*/
	stdfinal = feq_gen_get_unit_d_(stdout);
/* SOURCE dual_source.for:151 */
/*<        >*/
	feq_gen_o_d_1.oerr = 1;
	feq_gen_o_d_1.ounit = stdfinal;
	feq_gen_o_d_1.ofnmlen = 256;
	feq_gen_o_d_1.ofnm = feq_gen_final_file_d_;
	feq_gen_o_d_1.orl = feq_gen_record_length_d_;
	feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	feq_gen_o_d_1.oblnk = 0;
	ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE dual_source.for:154 */
/*<       if(ioflag.ne.0)then >*/
	if (ioflag != 0) {
/* SOURCE dual_source.for:155 */
/*<       write(stdout,52)final_file >*/
	    feq_gen_io_d__23.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__23);
	    do_fio(&feq_gen_c_d_1, feq_gen_final_file_d_, (ftnlen)256);
	    e_wsfe();
/* SOURCE dual_source.for:156 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:157 */
/*<       endif >*/
	}
/* SOURCE dual_source.for:159 */
/*<       irec=1 >*/
	irec = 1;
/* SOURCE dual_source.for:160 */
/*<        >*/
	feq_gen_io_d__25.ciunit = stdfinal;
	feq_gen_io_d__25.cirec = irec;
	s_wdue(&feq_gen_io_d__25);
	do_uio(&feq_gen_c_d_1, (char *)&feq_gen_record_length_d_, (ftnlen)sizeof(integer));
	do_uio(&feq_gen_c_d_1, (char *)&feq_gen_file_structure_version_d_, (ftnlen)sizeof(
		shortint));
	do_uio(&feq_gen_c_d_1, what, (ftnlen)1);
	do_uio(&feq_gen_c_d_1, unused, (ftnlen)1);
	do_uio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_30, (ftnlen)sizeof(integer));
	e_wdue();
/*          write(stdout,*) 'stdfinal=',stdfinal, */
/*     a      'record len=',record_length, */
/*     b      ' first data record#=', */
/*     c      DPTSF_REC_AT_FRST_TS_PNT */
/*         Point to the next open record for writing time-series data. */
/* SOURCE dual_source.for:169 */
/*<       irec=irec+1 >*/
	++irec;
/*         Fill unused records with blanks */
/* SOURCE dual_source.for:171 */
/*<       doi=irec,dptsf_rec_at_frst_ts_pnt-1 >*/
	for (feq_gen_i_d_ = irec; feq_gen_i_d_ <= 29; ++feq_gen_i_d_) {
/* SOURCE dual_source.for:172 */
/*<       write(stdfinal,rec=i)'            ' >*/
	    feq_gen_io_d__27.ciunit = stdfinal;
	    feq_gen_io_d__27.cirec = feq_gen_i_d_;
	    s_wdue(&feq_gen_io_d__27);
	    do_uio(&feq_gen_c_d_1, const_cast<char*>("            "), (ftnlen)12);
	    e_wdue();
/* SOURCE dual_source.for:173 */
/*<       enddo >*/
	}
/*         Update pointer to the record for the first time-series value */
/* SOURCE dual_source.for:176 */
/*<       irec=dptsf_rec_at_frst_ts_pnt >*/
	irec = 30;
/*         Tell the user about the successful open. */
/* SOURCE dual_source.for:179 */
/*<       write(stdout,54)final_file >*/
	feq_gen_io_d__28.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__28);
	do_fio(&feq_gen_c_d_1, feq_gen_final_file_d_, (ftnlen)256);
	e_wsfe();
/*         Clear the source pointer */
/* SOURCE dual_source.for:183 */
/*<       is=0 >*/
	is = 0;
/* SOURCE dual_source.for:184 */
/*<   200 continue >*/
L200:
/*           Now get the next line in the current define block. */
/* SOURCE dual_source.for:187 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)196);
/* SOURCE dual_source.for:190 */
/*<       it=feq_len_trim(line) >*/
	it = feq_gen_feq_len_trim_d_(line, (ftnlen)196);
/* SOURCE dual_source.for:191 */
/*<       write(stdout,'(a)')line(1:it) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, it);
	e_wsfe();
/* SOURCE dual_source.for:194 */
/*<        >*/
	feq_gen_get_items_d_(stdout, line, &feq_gen_c_d_20, &feq_gen_item_knt_d_, items, feq_gen_item_length_d_, 
		feq_gen_item_type_d_, feq_gen_term_class_d_, eflag, (ftnlen)196, (ftnlen)128);
/*            write(stdout,5599) */
/*            do i=1,item_knt */
/*              write(stdout, 5600) items(i), item_length(i),item_type(i), */
/*     a                        term_class(i) */
/*            end do */
/* SOURCE dual_source.for:203 */
/*<       if(items(1)=='FILE')then >*/
	if (s_cmp(items, const_cast<char*>("FILE"), (ftnlen)128, (ftnlen)4) == 0) {
/* SOURCE dual_source.for:204 */
/*<       is=is+1 >*/
	    ++is;
/* SOURCE dual_source.for:205 */
/*<       if(is>2)then >*/
	    if (is > 2) {
/* SOURCE dual_source.for:206 */
/*<       write(stdout,70) >*/
		feq_gen_io_d__30.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__30);
		e_wsfe();
/* SOURCE dual_source.for:207 */
/*<       endif >*/
	    }
/*             Get the file name. */
/* SOURCE dual_source.for:209 */
/*<       if(term_class(1)/=equal)then >*/
	    if (feq_gen_term_class_d_[0] != 8) {
/* SOURCE dual_source.for:210 */
/*<       write(stdout,50) >*/
		feq_gen_io_d__31.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__31);
		e_wsfe();
/* SOURCE dual_source.for:211 */
/*<       endif >*/
	    }
/* SOURCE dual_source.for:212 */
/*<       source(is)=items(2) >*/
	    s_copy(source + (is - 1 << 7), items + 128, (ftnlen)128, (ftnlen)
		    128);
/* SOURCE dual_source.for:213 */
/*<       source_type(is)='FILE' >*/
	    s_copy(feq_gen_source_type_d_ + (is - 1) * 5, const_cast<char*>("FILE"), (ftnlen)5, (ftnlen)4)
		    ;
/* SOURCE dual_source.for:214 */
/*<       source_adrs(is)=get_unit(stdout) >*/
	    feq_gen_source_adrs_d_[is - 1] = feq_gen_get_unit_d_(stdout);
/* SOURCE dual_source.for:215 */
/*<       tfile=source(is) >*/
	    s_copy(tfile, source + (is - 1 << 7), (ftnlen)256, (ftnlen)128);
/* SOURCE dual_source.for:216 */
/*<       callmaybe_add_home(tfile) >*/
	    feq_gen_maybe_add_home_d_(tfile, (ftnlen)256);
/* SOURCE dual_source.for:218 */
/*<       callos_file_style(tfile) >*/
	    feq_gen_os_file_style_d_(tfile, (ftnlen)256);
/*             Process the file name here so that home can be changed for each file */
/*             if required. */
/* SOURCE dual_source.for:223 */
/*<        >*/
	    feq_gen_o_d_1.oerr = 1;
	    feq_gen_o_d_1.ounit = feq_gen_source_adrs_d_[is - 1];
	    feq_gen_o_d_1.ofnmlen = 256;
	    feq_gen_o_d_1.ofnm = tfile;
	    feq_gen_o_d_1.orl = feq_gen_record_length_d_;
	    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	    feq_gen_o_d_1.oblnk = 0;
	    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE dual_source.for:226 */
/*<       if(ioflag.ne.0)then >*/
	    if (ioflag != 0) {
/* SOURCE dual_source.for:227 */
/*<       write(stdout,52)tfile >*/
		feq_gen_io_d__36.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__36);
		do_fio(&feq_gen_c_d_1, tfile, (ftnlen)256);
		e_wsfe();
/* SOURCE dual_source.for:228 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:229 */
/*<       endif >*/
	    }
/*             Get the starting and ending values for this file */
/* SOURCE dual_source.for:231 */
/*<       start_adrs(is)=dptsf_rec_at_frst_ts_pnt >*/
	    feq_gen_start_adrs_d_[is - 1] = 30;
/* SOURCE dual_source.for:232 */
/*<        >*/
	    feq_gen_io_d__38.ciunit = feq_gen_source_adrs_d_[is - 1];
	    s_rdue(&feq_gen_io_d__38);
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_start_jtime_d_[is - 1], (ftnlen)sizeof(
		    doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&dummy, (ftnlen)sizeof(real));
	    e_rdue();
/* SOURCE dual_source.for:234 */
/*<        >*/
	    feq_gen_io_d__41.ciunit = feq_gen_source_adrs_d_[is - 1];
	    s_rdue(&feq_gen_io_d__41);
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_end_jtime_d_[is - 1], (ftnlen)sizeof(
		    doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_end_adrs_d_[is - 1], (ftnlen)sizeof(integer)
		    );
	    e_rdue();
/* SOURCE dual_source.for:237 */
/*<       if(item_knt>2)then >*/
	    if (feq_gen_item_knt_d_ > 2) {
/*               More info follows the source name */
/* SOURCE dual_source.for:239 */
/*<       if(items(3)=='TRAN_START')then >*/
		if (s_cmp(items + 256, const_cast<char*>("TRAN_START"), (ftnlen)128, (ftnlen)10) 
			== 0) {
/* SOURCE dual_source.for:240 */
/*<       if(tran_start_yr>0)then >*/
		    if (feq_gen_tran_start_yr_d_ > 0) {
/* SOURCE dual_source.for:241 */
/*<        >*/
			feq_gen_io_d__44.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__44);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_yr_d_, (ftnlen)
				sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_mn_d_, (ftnlen)
				sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_dy_d_, (ftnlen)
				sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_hr_d_, (ftnlen)
				sizeof(doublereal));
			e_wsfe();
/* SOURCE dual_source.for:243 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:244 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:245 */
/*<       if(term_class(3)/=equal)then >*/
		    if (feq_gen_term_class_d_[2] != 8) {
/* SOURCE dual_source.for:246 */
/*<       write(stdout,50) >*/
			feq_gen_io_d__48.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__48);
			e_wsfe();
/* SOURCE dual_source.for:247 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:248 */
/*<       if(eflag==0)then >*/
		    if (*eflag == 0) {
/* SOURCE dual_source.for:249 */
/*<       read(items(4),'(i4)')tran_start_yr >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 384;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i4)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_yr_d_, (ftnlen)
				sizeof(integer));
			e_rsfi();
/* SOURCE dual_source.for:250 */
/*<       read(items(5),'(i2)')tran_start_mn >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 512;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i2)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_mn_d_, (ftnlen)
				sizeof(integer));
			e_rsfi();
/* SOURCE dual_source.for:251 */
/*<       read(items(6),'(i2)')tran_start_dy >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 640;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i2)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_dy_d_, (ftnlen)
				sizeof(integer));
			e_rsfi();
/* SOURCE dual_source.for:252 */
/*<       read(items(7),'(f15.0)')tran_start_hr >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 768;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(f15.0)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_hr_d_, (ftnlen)
				sizeof(doublereal));
			e_rsfi();
/* SOURCE dual_source.for:253 */
/*<       eflag=0 >*/
			*eflag = 0;
/* SOURCE dual_source.for:254 */
/*<       callchkdat(stdout,tran_start_yr,tran_start_mn,tran_start_dy,eflag) >*/
			chkdat_(stdout, &feq_gen_tran_start_yr_d_, &feq_gen_tran_start_mn_d_, &
				feq_gen_tran_start_dy_d_, eflag);
/* SOURCE dual_source.for:258 */
/*<       if(tran_start_hr<0.d0.or.tran_start_hr>24.d0)then >*/
			if (feq_gen_tran_start_hr_d_ < 0. || feq_gen_tran_start_hr_d_ > 24.) {
/* SOURCE dual_source.for:260 */
/*<       write(stdout,56)tran_start_hr >*/
			    feq_gen_io_d__49.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__49);
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_hr_d_, (ftnlen)
				    sizeof(doublereal));
			    e_wsfe();
/* SOURCE dual_source.for:261 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE dual_source.for:262 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:263 */
/*<       if(eflag/=0)then >*/
			if (*eflag != 0) {
/* SOURCE dual_source.for:264 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE dual_source.for:265 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:266 */
/*<        >*/
			feq_gen_tran_start_jtime_d_ = (doublereal) mjd_(&
				feq_gen_tran_start_yr_d_, &feq_gen_tran_start_mn_d_, &
				feq_gen_tran_start_dy_d_) + feq_gen_tran_start_hr_d_ / 24.;
/* SOURCE dual_source.for:270 */
/*<       else >*/
		    } else {
/* SOURCE dual_source.for:271 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:272 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:273 */
/*<       elseif(items(3)=='TRAN_END')then >*/
		} else if (s_cmp(items + 256, const_cast<char*>("TRAN_END"), (ftnlen)128, (
			ftnlen)8) == 0) {
/* SOURCE dual_source.for:274 */
/*<       if(tran_end_yr>0)then >*/
		    if (feq_gen_tran_end_yr_d_ > 0) {
/* SOURCE dual_source.for:275 */
/*<       write(stdout,68)tran_end_yr,tran_end_mn,tran_end_dy,tran_end_hr >*/
			feq_gen_io_d__51.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__51);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_yr_d_, (ftnlen)sizeof(
				integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_mn_d_, (ftnlen)sizeof(
				integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_dy_d_, (ftnlen)sizeof(
				integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_hr_d_, (ftnlen)sizeof(
				doublereal));
			e_wsfe();
/* SOURCE dual_source.for:277 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:278 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:279 */
/*<       if(term_class(3)/=equal)then >*/
		    if (feq_gen_term_class_d_[2] != 8) {
/* SOURCE dual_source.for:280 */
/*<       write(stdout,50) >*/
			feq_gen_io_d__55.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__55);
			e_wsfe();
/* SOURCE dual_source.for:281 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:282 */
/*<       if(eflag==0)then >*/
		    if (*eflag == 0) {
/* SOURCE dual_source.for:283 */
/*<       read(items(4),'(i4)')tran_end_yr >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 384;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i4)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_yr_d_, (ftnlen)sizeof(
				integer));
			e_rsfi();
/* SOURCE dual_source.for:284 */
/*<       read(items(5),'(i2)')tran_end_mn >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 512;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i2)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_mn_d_, (ftnlen)sizeof(
				integer));
			e_rsfi();
/* SOURCE dual_source.for:285 */
/*<       read(items(6),'(i2)')tran_end_dy >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 640;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i2)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_dy_d_, (ftnlen)sizeof(
				integer));
			e_rsfi();
/* SOURCE dual_source.for:286 */
/*<       read(items(7),'(f15.0)')tran_end_hr >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 768;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(f15.0)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_hr_d_, (ftnlen)sizeof(
				doublereal));
			e_rsfi();
/* SOURCE dual_source.for:287 */
/*<       eflag=0 >*/
			*eflag = 0;
/* SOURCE dual_source.for:288 */
/*<       callchkdat(stdout,tran_end_yr,tran_end_mn,tran_end_dy,eflag) >*/
			chkdat_(stdout, &feq_gen_tran_end_yr_d_, &feq_gen_tran_end_mn_d_, &
				feq_gen_tran_end_dy_d_, eflag);
/* SOURCE dual_source.for:292 */
/*<       if(tran_end_hr<0.d0.or.tran_end_hr>24.d0)then >*/
			if (feq_gen_tran_end_hr_d_ < 0. || feq_gen_tran_end_hr_d_ > 24.) {
/* SOURCE dual_source.for:294 */
/*<       write(stdout,56)tran_end_hr >*/
			    feq_gen_io_d__56.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__56);
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_hr_d_, (ftnlen)
				    sizeof(doublereal));
			    e_wsfe();
/* SOURCE dual_source.for:295 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE dual_source.for:296 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:297 */
/*<       if(eflag/=0)then >*/
			if (*eflag != 0) {
/* SOURCE dual_source.for:298 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE dual_source.for:299 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:300 */
/*<        >*/
			feq_gen_tran_end_jtime_d_ = (doublereal) mjd_(&feq_gen_tran_end_yr_d_, &
				feq_gen_tran_end_mn_d_, &feq_gen_tran_end_dy_d_) + 
				feq_gen_tran_end_hr_d_ / 24.;
/* SOURCE dual_source.for:304 */
/*<       else >*/
		    } else {
/* SOURCE dual_source.for:305 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:306 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:307 */
/*<       else >*/
		} else {
/* SOURCE dual_source.for:309 */
/*<        >*/
		    feq_gen_io_d__58.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__58);
		    do_fio(&feq_gen_c_d_1, const_cast<char*>("TRAN_START or TRAN_END"), (ftnlen)22);
		    do_fio(&feq_gen_c_d_1, items + 256, feq_gen_feq_len_trim_d_(items + 256, (
			    ftnlen)128));
		    e_wsfe();
/* SOURCE dual_source.for:311 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:312 */
/*<       endif >*/
		}
/* SOURCE dual_source.for:314 */
/*<       endif >*/
	    }
/* SOURCE dual_source.for:317 */
/*<       elseif(items(1)=='TABLE')then >*/
	} else if (s_cmp(items, const_cast<char*>("TABLE"), (ftnlen)128, (ftnlen)5) == 0) {
/*             Get the table name */
/* SOURCE dual_source.for:319 */
/*<       is=is+1 >*/
	    ++is;
/* SOURCE dual_source.for:320 */
/*<       if(is>2)then >*/
	    if (is > 2) {
/* SOURCE dual_source.for:321 */
/*<       write(stdout,70) >*/
		feq_gen_io_d__59.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__59);
		e_wsfe();
/* SOURCE dual_source.for:322 */
/*<       endif >*/
	    }
/* SOURCE dual_source.for:323 */
/*<       if(term_class(1)/=equal)then >*/
	    if (feq_gen_term_class_d_[0] != 8) {
/* SOURCE dual_source.for:324 */
/*<       write(stdout,50) >*/
		feq_gen_io_d__60.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__60);
		e_wsfe();
/* SOURCE dual_source.for:325 */
/*<       endif >*/
	    }
/* SOURCE dual_source.for:326 */
/*<       source(is)=items(2) >*/
	    s_copy(source + (is - 1 << 7), items + 128, (ftnlen)128, (ftnlen)
		    128);
/* SOURCE dual_source.for:327 */
/*<       source_type(is)='TABLE' >*/
	    s_copy(feq_gen_source_type_d_ + (is - 1) * 5, const_cast<char*>("TABLE"), (ftnlen)5, (ftnlen)
		    5);
/*             find the address for the time-series table */
/* SOURCE dual_source.for:329 */
/*<       char16=source(is) >*/
	    s_copy(char16, source + (is - 1 << 7), (ftnlen)16, (ftnlen)128);
/* SOURCE dual_source.for:330 */
/*<       callfind_internal_tab_number(char16,source_adrs(is)) >*/
	    feq_gen_find_internal_tab_number_d_(char16, &feq_gen_source_adrs_d_[is - 1], (
		    ftnlen)16);
/* SOURCE dual_source.for:334 */
/*<       if(source_adrs(is).gt.0)then >*/
	    if (feq_gen_source_adrs_d_[is - 1] > 0) {
/* SOURCE dual_source.for:335 */
/*<       callchktab(7,stdout,ftpnt,mftnum,source_adrs(is),eflag) >*/
		chktab_(&feq_gen_c_d_7, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &
			feq_gen_source_adrs_d_[is - 1], eflag);
/* SOURCE dual_source.for:339 */
/*<       else >*/
	    } else {
/* SOURCE dual_source.for:340 */
/*<       write(stdout,*)' Time-series table not found.' >*/
		feq_gen_io_d__62.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__62);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Time-series table not found."), (ftnlen)
			29);
		e_wsle();
/* SOURCE dual_source.for:341 */
/*<       stop'Abnormal stop.  Missing time-series table.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Missing time-series table."), (ftnlen)
			42);
/* SOURCE dual_source.for:342 */
/*<       endif >*/
	    }
/* SOURCE dual_source.for:343 */
/*<       if(item_knt>2)then >*/
	    if (feq_gen_item_knt_d_ > 2) {
/*               More info follows the source name */
/* SOURCE dual_source.for:345 */
/*<       if(items(3)=='TRAN_START')then >*/
		if (s_cmp(items + 256, const_cast<char*>("TRAN_START"), (ftnlen)128, (ftnlen)10) 
			== 0) {
/* SOURCE dual_source.for:346 */
/*<       if(tran_start_yr>0)then >*/
		    if (feq_gen_tran_start_yr_d_ > 0) {
/* SOURCE dual_source.for:347 */
/*<        >*/
			feq_gen_io_d__63.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__63);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_yr_d_, (ftnlen)
				sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_mn_d_, (ftnlen)
				sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_dy_d_, (ftnlen)
				sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_hr_d_, (ftnlen)
				sizeof(doublereal));
			e_wsfe();
/* SOURCE dual_source.for:349 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:350 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:351 */
/*<       if(term_class(3)/=equal)then >*/
		    if (feq_gen_term_class_d_[2] != 8) {
/* SOURCE dual_source.for:352 */
/*<       write(stdout,50) >*/
			feq_gen_io_d__64.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__64);
			e_wsfe();
/* SOURCE dual_source.for:353 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:354 */
/*<       if(eflag==0)then >*/
		    if (*eflag == 0) {
/* SOURCE dual_source.for:355 */
/*<       read(items(4),'(i4)')tran_start_yr >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 384;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i4)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_yr_d_, (ftnlen)
				sizeof(integer));
			e_rsfi();
/* SOURCE dual_source.for:356 */
/*<       read(items(5),'(i2)')tran_start_mn >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 512;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i2)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_mn_d_, (ftnlen)
				sizeof(integer));
			e_rsfi();
/* SOURCE dual_source.for:357 */
/*<       read(items(6),'(i2)')tran_start_dy >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 640;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i2)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_dy_d_, (ftnlen)
				sizeof(integer));
			e_rsfi();
/* SOURCE dual_source.for:358 */
/*<       read(items(7),'(f15.0)')tran_start_hr >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 768;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(f15.0)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_hr_d_, (ftnlen)
				sizeof(doublereal));
			e_rsfi();
/* SOURCE dual_source.for:359 */
/*<       eflag=0 >*/
			*eflag = 0;
/* SOURCE dual_source.for:360 */
/*<       callchkdat(stdout,tran_start_yr,tran_start_mn,tran_start_dy,eflag) >*/
			chkdat_(stdout, &feq_gen_tran_start_yr_d_, &feq_gen_tran_start_mn_d_, &
				feq_gen_tran_start_dy_d_, eflag);
/* SOURCE dual_source.for:364 */
/*<       if(tran_start_hr<0.d0.or.tran_start_hr>24.d0)then >*/
			if (feq_gen_tran_start_hr_d_ < 0. || feq_gen_tran_start_hr_d_ > 24.) {
/* SOURCE dual_source.for:366 */
/*<       write(stdout,56)tran_start_hr >*/
			    feq_gen_io_d__65.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__65);
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_hr_d_, (ftnlen)
				    sizeof(doublereal));
			    e_wsfe();
/* SOURCE dual_source.for:367 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE dual_source.for:368 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:369 */
/*<       if(eflag/=0)then >*/
			if (*eflag != 0) {
/* SOURCE dual_source.for:370 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE dual_source.for:371 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:372 */
/*<        >*/
			feq_gen_tran_start_jtime_d_ = (doublereal) mjd_(&
				feq_gen_tran_start_yr_d_, &feq_gen_tran_start_mn_d_, &
				feq_gen_tran_start_dy_d_) + feq_gen_tran_start_hr_d_ / 24.;
/* SOURCE dual_source.for:376 */
/*<       else >*/
		    } else {
/* SOURCE dual_source.for:377 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:378 */
/*<       endif >*/
		    }
/*                 Get starting and ending */
/* SOURCE dual_source.for:380 */
/*<       elseif(items(3)=='TRAN_END')then >*/
		} else if (s_cmp(items + 256, const_cast<char*>("TRAN_END"), (ftnlen)128, (
			ftnlen)8) == 0) {
/* SOURCE dual_source.for:381 */
/*<       if(tran_end_yr>0)then >*/
		    if (feq_gen_tran_end_yr_d_ > 0) {
/* SOURCE dual_source.for:382 */
/*<       write(stdout,68)tran_end_yr,tran_end_mn,tran_end_dy,tran_end_hr >*/
			feq_gen_io_d__66.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__66);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_yr_d_, (ftnlen)sizeof(
				integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_mn_d_, (ftnlen)sizeof(
				integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_dy_d_, (ftnlen)sizeof(
				integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_hr_d_, (ftnlen)sizeof(
				doublereal));
			e_wsfe();
/* SOURCE dual_source.for:384 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:385 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:386 */
/*<       if(term_class(3)/=equal)then >*/
		    if (feq_gen_term_class_d_[2] != 8) {
/* SOURCE dual_source.for:387 */
/*<       write(stdout,50) >*/
			feq_gen_io_d__67.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__67);
			e_wsfe();
/* SOURCE dual_source.for:388 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:389 */
/*<       if(eflag==0)then >*/
		    if (*eflag == 0) {
/* SOURCE dual_source.for:390 */
/*<       read(items(4),'(i4)')tran_end_yr >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 384;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i4)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_yr_d_, (ftnlen)sizeof(
				integer));
			e_rsfi();
/* SOURCE dual_source.for:391 */
/*<       read(items(5),'(i2)')tran_end_mn >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 512;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i2)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_mn_d_, (ftnlen)sizeof(
				integer));
			e_rsfi();
/* SOURCE dual_source.for:392 */
/*<       read(items(6),'(i2)')tran_end_dy >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 640;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(i2)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_dy_d_, (ftnlen)sizeof(
				integer));
			e_rsfi();
/* SOURCE dual_source.for:393 */
/*<       read(items(7),'(f15.0)')tran_end_hr >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.iciend = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 128;
			feq_gen_ici_d_1.iciunit = items + 768;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(f15.0)");
			s_rsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_hr_d_, (ftnlen)sizeof(
				doublereal));
			e_rsfi();
/* SOURCE dual_source.for:394 */
/*<       eflag=0 >*/
			*eflag = 0;
/* SOURCE dual_source.for:395 */
/*<       callchkdat(stdout,tran_end_yr,tran_end_mn,tran_end_dy,eflag) >*/
			chkdat_(stdout, &feq_gen_tran_end_yr_d_, &feq_gen_tran_end_mn_d_, &
				feq_gen_tran_end_dy_d_, eflag);
/* SOURCE dual_source.for:399 */
/*<       if(tran_end_hr<0.d0.or.tran_end_hr>24.d0)then >*/
			if (feq_gen_tran_end_hr_d_ < 0. || feq_gen_tran_end_hr_d_ > 24.) {
/* SOURCE dual_source.for:401 */
/*<       write(stdout,56)tran_end_hr >*/
			    feq_gen_io_d__68.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__68);
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_hr_d_, (ftnlen)
				    sizeof(doublereal));
			    e_wsfe();
/* SOURCE dual_source.for:402 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE dual_source.for:403 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:404 */
/*<       if(eflag/=0)then >*/
			if (*eflag != 0) {
/* SOURCE dual_source.for:405 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE dual_source.for:406 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:407 */
/*<        >*/
			feq_gen_tran_end_jtime_d_ = (doublereal) mjd_(&feq_gen_tran_end_yr_d_, &
				feq_gen_tran_end_mn_d_, &feq_gen_tran_end_dy_d_) + 
				feq_gen_tran_end_hr_d_ / 24.;
/* SOURCE dual_source.for:411 */
/*<       else >*/
		    } else {
/* SOURCE dual_source.for:412 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:413 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:414 */
/*<       else >*/
		} else {
/* SOURCE dual_source.for:416 */
/*<        >*/
		    feq_gen_io_d__69.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__69);
		    do_fio(&feq_gen_c_d_1, const_cast<char*>("TRAN_START or TRAN_END"), (ftnlen)22);
		    do_fio(&feq_gen_c_d_1, items + 256, feq_gen_feq_len_trim_d_(items + 256, (
			    ftnlen)128));
		    e_wsfe();
/* SOURCE dual_source.for:418 */
/*<       endif >*/
		}
/* SOURCE dual_source.for:420 */
/*<       endif >*/
	    }
/*             Get starging and ending info for this table. */
/* SOURCE dual_source.for:423 */
/*<       start_adrs(is)=(source_adrs(is)+off234)/2 >*/
	    feq_gen_start_adrs_d_[is - 1] = (feq_gen_source_adrs_d_[is - 1] + 22) / 2;
/* SOURCE dual_source.for:424 */
/*<       start_jtime(is)=dtab(start_adrs(is)) >*/
	    feq_gen_start_jtime_d_[is - 1] = ftable_1.dtab[feq_gen_start_adrs_d_[is - 1]];
/* SOURCE dual_source.for:426 */
/*<       end_adrs(is)=itab(source_adrs(is)) >*/
	    feq_gen_end_adrs_d_[is - 1] = itab[feq_gen_source_adrs_d_[is - 1]];
/* SOURCE dual_source.for:427 */
/*<       end_jtime(is)=dtab(end_adrs(is)) >*/
	    feq_gen_end_jtime_d_[is - 1] = ftable_1.dtab[feq_gen_end_adrs_d_[is - 1]];
/* SOURCE dual_source.for:429 */
/*<       elseif(items(1)(1:10)=='TRAN_TAB')then >*/
	} else if (s_cmp(items, const_cast<char*>("TRAN_TAB"), (ftnlen)10, (ftnlen)8) == 0) {
/*             process the transition table */
/* SOURCE dual_source.for:431 */
/*<       if(term_class(1)/=equal)then >*/
	    if (feq_gen_term_class_d_[0] != 8) {
/* SOURCE dual_source.for:432 */
/*<       write(stdout,50) >*/
		feq_gen_io_d__70.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__70);
		e_wsfe();
/* SOURCE dual_source.for:433 */
/*<       endif >*/
	    }
/* SOURCE dual_source.for:434 */
/*<       tran_tabid=items(2) >*/
	    s_copy(feq_gen_tran_tabid_d_, items + 128, (ftnlen)16, (ftnlen)128);
/*              find the address for the transition table */
/* SOURCE dual_source.for:437 */
/*<       callfind_internal_tab_number(tran_tabid,tran_tab_adrs) >*/
	    feq_gen_find_internal_tab_number_d_(feq_gen_tran_tabid_d_, &feq_gen_tran_tab_adrs_d_, (
		    ftnlen)16);
/* SOURCE dual_source.for:441 */
/*<       if(tran_tab_adrs.gt.0)then >*/
	    if (feq_gen_tran_tab_adrs_d_ > 0) {
/* SOURCE dual_source.for:442 */
/*<       callchktab(7,stdout,ftpnt,mftnum,tran_tab_adrs,eflag) >*/
		chktab_(&feq_gen_c_d_7, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &
			feq_gen_tran_tab_adrs_d_, eflag);
/* SOURCE dual_source.for:446 */
/*<       else >*/
	    } else {
/* SOURCE dual_source.for:447 */
/*<       write(stdout,72) >*/
		feq_gen_io_d__72.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__72);
		e_wsfe();
/* SOURCE dual_source.for:448 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:449 */
/*<       endif >*/
	    }
/* SOURCE dual_source.for:451 */
/*<       elseif(items(1)(1:4)=='HOME'.or.items(1)(1:4)=='home')then >*/
	} else if (s_cmp(items, const_cast<char*>("HOME"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(
		items, const_cast<char*>("home"), (ftnlen)4, (ftnlen)4) == 0) {
/*              Set the local home name */
/* SOURCE dual_source.for:454 */
/*<       if(term_class(1)/=equal)then >*/
	    if (feq_gen_term_class_d_[0] != 8) {
/* SOURCE dual_source.for:455 */
/*<       write(stdout,50) >*/
		feq_gen_io_d__73.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__73);
		e_wsfe();
/* SOURCE dual_source.for:456 */
/*<       endif >*/
	    }
/* SOURCE dual_source.for:457 */
/*<       home=items(2) >*/
	    s_copy(homec_1.home, items + 128, (ftnlen)128, (ftnlen)128);
/* SOURCE dual_source.for:458 */
/*<       elseif(items(1)=='END')then >*/
	} else if (s_cmp(items, const_cast<char*>("END"), (ftnlen)128, (ftnlen)3) == 0) {
/* SOURCE dual_source.for:459 */
/*<       if(items(2)==blk_name)then >*/
	    if (s_cmp(items + 128, feq_gen_blk_name_d_, (ftnlen)128, (ftnlen)128) == 0)
		     {
/*               We have all basic items in hand.  Create the dual source */
/*               file */
/*                write(stdout,5699) final_file, stdfinal */
/* 5699            format(' Final file name=',a,/, */
/*     b          14x,'Stdfinal=',i5) */
/*                do i=1,2 */
/*                  write(stdout,5700) i, */
/*     a              source(i), source_type(i), source_adrs(i) */
/* 5700            format( i2,' Source Name='a,/, */
/*     b              14x,'Type=',a5,/, */
/*     c               14x,'Address=',i10) */
/*                  write(stdout,5702) start_adrs(i), end_adrs(i) */
/*                  write(stdout,5704) start_jtime(i), end_jtime(i) */
/* 5702              format(14x,' start_adrs=',i10,' end_adrs=',i10) */
/* 5704              format(14x,' start_jtime=',f14.4,' end_jtime=',f14.4) */
/*                enddo */
/* SOURCE dual_source.for:477 */
/*<       if(tran_start_yr>0)then >*/
		if (feq_gen_tran_start_yr_d_ > 0) {
/* SOURCE dual_source.for:478 */
/*<        >*/
		    feq_gen_io_d__74.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__74);
		    do_fio(&feq_gen_c_d_1, const_cast<char*>("Tran_start="), (ftnlen)11);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_yr_d_, (ftnlen)sizeof(
			    integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_mn_d_, (ftnlen)sizeof(
			    integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_dy_d_, (ftnlen)sizeof(
			    integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_hr_d_, (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
/* SOURCE dual_source.for:480 */
/*<  5701 format(2x,a,i5,'/',i2,'/',i3,':',f14.4) >*/
/* SOURCE dual_source.for:481 */
/*<       endif >*/
		}
/* SOURCE dual_source.for:482 */
/*<       if(tran_end_yr>0)then >*/
		if (feq_gen_tran_end_yr_d_ > 0) {
/* SOURCE dual_source.for:483 */
/*<        >*/
		    feq_gen_io_d__75.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__75);
		    do_fio(&feq_gen_c_d_1, const_cast<char*>("Tran_end="), (ftnlen)9);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_yr_d_, (ftnlen)sizeof(
			    integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_mn_d_, (ftnlen)sizeof(
			    integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_dy_d_, (ftnlen)sizeof(
			    integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_end_hr_d_, (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
/* SOURCE dual_source.for:485 */
/*<       endif >*/
		}
/* SOURCE dual_source.for:487 */
/*<       if(tran_start_yr==0)then >*/
		if (feq_gen_tran_start_yr_d_ == 0) {
/*                  tran_end time if given is ignored because the */
/*                  start time is not present. */
/* SOURCE dual_source.for:490 */
/*<       jtime_break=end_jtime(1) >*/
		    feq_gen_jtime_break_d_ = feq_gen_end_jtime_d_[0];
/* SOURCE dual_source.for:491 */
/*<       else >*/
		} else {
/* SOURCE dual_source.for:492 */
/*<       if(tran_end_yr==0)then >*/
		    if (feq_gen_tran_end_yr_d_ == 0) {
/*                   tran_start time was given but no tran_end time */
/* SOURCE dual_source.for:494 */
/*<       if(tran_start_jtime>end_jtime(1))then >*/
			if (feq_gen_tran_start_jtime_d_ > feq_gen_end_jtime_d_[0]) {
/* SOURCE dual_source.for:495 */
/*<       write(stdout,74)tran_start_jtime,end_jtime(1) >*/
			    feq_gen_io_d__77.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__77);
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tran_start_jtime_d_, (
				    ftnlen)sizeof(doublereal));
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_end_jtime_d_[0], (ftnlen)
				    sizeof(doublereal));
			    e_wsfe();
/* SOURCE dual_source.for:496 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE dual_source.for:497 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:499 */
/*<       jtime_break=tran_start_jtime >*/
			feq_gen_jtime_break_d_ = feq_gen_tran_start_jtime_d_;
/* SOURCE dual_source.for:500 */
/*<       else >*/
		    } else {
/* SOURCE dual_source.for:501 */
/*<       write(stdout,*)'Transition region not yet implemented' >*/
			feq_gen_io_d__78.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__78);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("Transition region not yet impl\
emented"), (ftnlen)37);
			e_wsle();
/* SOURCE dual_source.for:503 */
/*<       stop'Unimplemented option requested' >*/
			s_stop(const_cast<char*>("Unimplemented option requested"), (ftnlen)30);
/* SOURCE dual_source.for:504 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:505 */
/*<       endif >*/
		}
/* SOURCE dual_source.for:507 */
/*<       if(source_type(1)=='FILE')then >*/
		if (s_cmp(feq_gen_source_type_d_, const_cast<char*>("FILE"), (ftnlen)5, (ftnlen)4) == 0) {
/* SOURCE dual_source.for:508 */
/*<       doi=start_adrs(1),end_adrs(1) >*/
		    feq_gen_i_d_1 = feq_gen_end_adrs_d_[0];
		    for (feq_gen_i_d_ = feq_gen_start_adrs_d_[0]; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE dual_source.for:509 */
/*<       read(source_adrs(1),rec=i)jtime,value >*/
			feq_gen_io_d__79.ciunit = feq_gen_source_adrs_d_[0];
			feq_gen_io_d__79.cirec = feq_gen_i_d_;
			s_rdue(&feq_gen_io_d__79);
			do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
				doublereal));
			do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(real));
			e_rdue();
/* SOURCE dual_source.for:510 */
/*<       if(jtime<=jtime_break)then >*/
			if (jtime <= feq_gen_jtime_break_d_) {
/* SOURCE dual_source.for:511 */
/*<       write(stdfinal,rec=irec)jtime,value >*/
			    feq_gen_io_d__82.ciunit = stdfinal;
			    feq_gen_io_d__82.cirec = irec;
			    s_wdue(&feq_gen_io_d__82);
			    do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
				    doublereal));
			    do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(real)
				    );
			    e_wdue();
/*                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') */
/*     a                       irec,jttoct(jtime), jtime,value */
/* SOURCE dual_source.for:514 */
/*<       irec=irec+1 >*/
			    ++irec;
/* SOURCE dual_source.for:515 */
/*<       else >*/
			} else {
/*                      write(stdout,'(a)') ' First source ends here' */
/* SOURCE dual_source.for:517 */
/*<       goto98998 >*/
			    goto L98998;
/* SOURCE dual_source.for:518 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:519 */
/*<       enddo >*/
		    }
/* SOURCE dual_source.for:519 */
/*< 98998 continue >*/
L98998:
/* SOURCE dual_source.for:520 */
/*<       callfree_unit(stdout,source_adrs(1)) >*/
		    feq_gen_free_unit_d_(stdout, feq_gen_source_adrs_d_);
/* SOURCE dual_source.for:521 */
/*<       if(source_type(2)=='TABLE')then >*/
		    if (s_cmp(feq_gen_source_type_d_ + 5, const_cast<char*>("TABLE"), (ftnlen)5, (ftnlen)
			    5) == 0) {
/* SOURCE dual_source.for:522 */
/*<       doi=start_adrs(2),end_adrs(2),2 >*/
			feq_gen_i_d_1 = feq_gen_end_adrs_d_[1];
			for (feq_gen_i_d_ = feq_gen_start_adrs_d_[1]; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 2) {
/* SOURCE dual_source.for:523 */
/*<       jtime=dtab(i) >*/
			    jtime = ftable_1.dtab[feq_gen_i_d_];
/* SOURCE dual_source.for:524 */
/*<       value=sngl(dtab(i+1)) >*/
			    value = (real) ftable_1.dtab[feq_gen_i_d_ + 1];
/* SOURCE dual_source.for:525 */
/*<       if(jtime>jtime_break)then >*/
			    if (jtime > feq_gen_jtime_break_d_) {
/* SOURCE dual_source.for:526 */
/*<       write(stdfinal,rec=irec)jtime,value >*/
				feq_gen_io_d__83.ciunit = stdfinal;
				feq_gen_io_d__83.cirec = irec;
				s_wdue(&feq_gen_io_d__83);
				do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
					doublereal));
				do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(
					real));
				e_wdue();
/*                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') */
/*     a                       irec,jttoct(jtime), jtime,value */
/* SOURCE dual_source.for:529 */
/*<       irec=irec+1 >*/
				++irec;
/* SOURCE dual_source.for:530 */
/*<       endif >*/
			    }
/* SOURCE dual_source.for:531 */
/*<       enddo >*/
			}
/* SOURCE dual_source.for:532 */
/*<       else >*/
		    } else {
/*                   Source type is FILE here */
/* SOURCE dual_source.for:534 */
/*<       doi=start_adrs(2),end_adrs(2),2 >*/
			feq_gen_i_d_1 = feq_gen_end_adrs_d_[1];
			for (feq_gen_i_d_ = feq_gen_start_adrs_d_[1]; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 2) {
/* SOURCE dual_source.for:535 */
/*<       read(source_adrs(2),rec=i)jtime,value >*/
			    feq_gen_io_d__84.ciunit = feq_gen_source_adrs_d_[1];
			    feq_gen_io_d__84.cirec = feq_gen_i_d_;
			    s_rdue(&feq_gen_io_d__84);
			    do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
				    doublereal));
			    do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(real)
				    );
			    e_rdue();
/* SOURCE dual_source.for:536 */
/*<       if(jtime>jtime_break)then >*/
			    if (jtime > feq_gen_jtime_break_d_) {
/* SOURCE dual_source.for:537 */
/*<       write(stdfinal,rec=irec)jtime,value >*/
				feq_gen_io_d__85.ciunit = stdfinal;
				feq_gen_io_d__85.cirec = irec;
				s_wdue(&feq_gen_io_d__85);
				do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
					doublereal));
				do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(
					real));
				e_wdue();
/*                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') */
/*     a                       irec,jttoct(jtime), jtime,value */
/* SOURCE dual_source.for:540 */
/*<       irec=irec+1 >*/
				++irec;
/* SOURCE dual_source.for:541 */
/*<       endif >*/
			    }
/* SOURCE dual_source.for:542 */
/*<       enddo >*/
			}
/* SOURCE dual_source.for:543 */
/*<       callfree_unit(stdout,source_adrs(2)) >*/
			feq_gen_free_unit_d_(stdout, &feq_gen_source_adrs_d_[1]);
/* SOURCE dual_source.for:544 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:545 */
/*<       else >*/
		} else {
/*                 First source is a ts table. */
/* SOURCE dual_source.for:547 */
/*<       doi=start_adrs(1),end_adrs(1),2 >*/
		    feq_gen_i_d_1 = feq_gen_end_adrs_d_[0];
		    for (feq_gen_i_d_ = feq_gen_start_adrs_d_[0]; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 2) {
/* SOURCE dual_source.for:548 */
/*<       jtime=dtab(i) >*/
			jtime = ftable_1.dtab[feq_gen_i_d_];
/* SOURCE dual_source.for:549 */
/*<       value=sngl(dtab(i+1)) >*/
			value = (real) ftable_1.dtab[feq_gen_i_d_ + 1];
/* SOURCE dual_source.for:550 */
/*<       if(jtime<=jtime_break)then >*/
			if (jtime <= feq_gen_jtime_break_d_) {
/* SOURCE dual_source.for:551 */
/*<       write(stdfinal,rec=irec)jtime,value >*/
			    feq_gen_io_d__86.ciunit = stdfinal;
			    feq_gen_io_d__86.cirec = irec;
			    s_wdue(&feq_gen_io_d__86);
			    do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
				    doublereal));
			    do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(real)
				    );
			    e_wdue();
/*                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') */
/*     a                       irec,jttoct(jtime), jtime,value */
/* SOURCE dual_source.for:554 */
/*<       irec=irec+1 >*/
			    ++irec;
/* SOURCE dual_source.for:555 */
/*<       else >*/
			} else {
/*                      write(stdout,'(a)') ' First source ends here' */
/* SOURCE dual_source.for:557 */
/*<       goto98992 >*/
			    goto L98992;
/* SOURCE dual_source.for:558 */
/*<       endif >*/
			}
/* SOURCE dual_source.for:559 */
/*<       enddo >*/
		    }
/* SOURCE dual_source.for:559 */
/*< 98992 continue >*/
L98992:
/* SOURCE dual_source.for:561 */
/*<       if(source_type(2)=='TABLE')then >*/
		    if (s_cmp(feq_gen_source_type_d_ + 5, const_cast<char*>("TABLE"), (ftnlen)5, (ftnlen)
			    5) == 0) {
/* SOURCE dual_source.for:562 */
/*<       doi=start_adrs(2),end_adrs(2),2 >*/
			feq_gen_i_d_1 = feq_gen_end_adrs_d_[1];
			for (feq_gen_i_d_ = feq_gen_start_adrs_d_[1]; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 2) {
/* SOURCE dual_source.for:563 */
/*<       jtime=dtab(i) >*/
			    jtime = ftable_1.dtab[feq_gen_i_d_];
/* SOURCE dual_source.for:564 */
/*<       value=sngl(dtab(i+1)) >*/
			    value = (real) ftable_1.dtab[feq_gen_i_d_ + 1];
/* SOURCE dual_source.for:565 */
/*<       if(jtime>jtime_break)then >*/
			    if (jtime > feq_gen_jtime_break_d_) {
/* SOURCE dual_source.for:566 */
/*<       write(stdfinal,rec=irec)jtime,value >*/
				feq_gen_io_d__87.ciunit = stdfinal;
				feq_gen_io_d__87.cirec = irec;
				s_wdue(&feq_gen_io_d__87);
				do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
					doublereal));
				do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(
					real));
				e_wdue();
/*                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') */
/*     a                       irec,jttoct(jtime), jtime,value */
/* SOURCE dual_source.for:569 */
/*<       irec=irec+1 >*/
				++irec;
/* SOURCE dual_source.for:570 */
/*<       endif >*/
			    }
/* SOURCE dual_source.for:571 */
/*<       enddo >*/
			}
/* SOURCE dual_source.for:572 */
/*<       else >*/
		    } else {
/*                   Source type is FILE here */
/* SOURCE dual_source.for:574 */
/*<       doi=start_adrs(2),end_adrs(2),2 >*/
			feq_gen_i_d_1 = feq_gen_end_adrs_d_[1];
			for (feq_gen_i_d_ = feq_gen_start_adrs_d_[1]; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 2) {
/* SOURCE dual_source.for:575 */
/*<       read(source_adrs(2),rec=i)jtime,value >*/
			    feq_gen_io_d__88.ciunit = feq_gen_source_adrs_d_[1];
			    feq_gen_io_d__88.cirec = feq_gen_i_d_;
			    s_rdue(&feq_gen_io_d__88);
			    do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
				    doublereal));
			    do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(real)
				    );
			    e_rdue();
/* SOURCE dual_source.for:576 */
/*<       if(jtime>jtime_break)then >*/
			    if (jtime > feq_gen_jtime_break_d_) {
/* SOURCE dual_source.for:577 */
/*<       write(stdfinal,rec=irec)jtime,value >*/
				feq_gen_io_d__89.ciunit = stdfinal;
				feq_gen_io_d__89.cirec = irec;
				s_wdue(&feq_gen_io_d__89);
				do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(
					doublereal));
				do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(
					real));
				e_wdue();
/*                write(stdout,'(i10,1x,a,1x,f17.8,f10.2)') */
/*     a                       irec,jttoct(jtime), jtime,value */
/* SOURCE dual_source.for:580 */
/*<       irec=irec+1 >*/
				++irec;
/* SOURCE dual_source.for:581 */
/*<       endif >*/
			    }
/* SOURCE dual_source.for:582 */
/*<       enddo >*/
			}
/* SOURCE dual_source.for:583 */
/*<       callfree_unit(stdout,source_adrs(2)) >*/
			feq_gen_free_unit_d_(stdout, &feq_gen_source_adrs_d_[1]);
/* SOURCE dual_source.for:584 */
/*<       endif >*/
		    }
/* SOURCE dual_source.for:585 */
/*<       endif >*/
		}
/*               write the final record and store the last record */
/*               inforomation. */
/* SOURCE dual_source.for:588 */
/*<       jtime=0.d0 >*/
		jtime = 0.;
/* SOURCE dual_source.for:589 */
/*<       value=0.0 >*/
		value = (float)0.;
/* SOURCE dual_source.for:590 */
/*<       write(stdfinal,rec=irec)jtime,value >*/
		feq_gen_io_d__90.ciunit = stdfinal;
		feq_gen_io_d__90.cirec = irec;
		s_wdue(&feq_gen_io_d__90);
		do_uio(&feq_gen_c_d_1, (char *)&jtime, (ftnlen)sizeof(doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(real));
		e_wdue();
/*                write(stdout,'(i10,f17.8,f10.2)') irec, jtime,value */
/* SOURCE dual_source.for:592 */
/*<        >*/
		feq_gen_io_d__91.ciunit = stdfinal;
		s_wdue(&feq_gen_io_d__91);
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_end_jtime_d_[1], (ftnlen)sizeof(
			doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_end_adrs_d_[1], (ftnlen)sizeof(integer))
			;
		e_wdue();
/* SOURCE dual_source.for:594 */
/*<       close(stdfinal) >*/
		feq_gen_cl_d_1.cerr = 0;
		feq_gen_cl_d_1.cunit = stdfinal;
		feq_gen_cl_d_1.csta = 0;
		f_clos(&feq_gen_cl_d_1);
/* SOURCE dual_source.for:595 */
/*<       callfree_unit(stdout,stdfinal) >*/
		feq_gen_free_unit_d_(stdout, &stdfinal);
/* SOURCE dual_source.for:597 */
/*<       else >*/
	    } else {
/* SOURCE dual_source.for:598 */
/*<       write(stdout,60)items(2),blk_name >*/
		feq_gen_io_d__92.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__92);
		do_fio(&feq_gen_c_d_1, items + 128, (ftnlen)128);
		do_fio(&feq_gen_c_d_1, feq_gen_blk_name_d_, (ftnlen)128);
		e_wsfe();
/* SOURCE dual_source.for:599 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:601 */
/*<       endif >*/
	    }
/*             Go look for the next define block */
/* SOURCE dual_source.for:605 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE dual_source.for:606 */
/*<       else >*/
	} else {
/* SOURCE dual_source.for:607 */
/*<       write(stdout,58)items(1) >*/
	    feq_gen_io_d__93.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__93);
	    do_fio(&feq_gen_c_d_1, items, (ftnlen)128);
	    e_wsfe();
/* SOURCE dual_source.for:608 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:610 */
/*<       endif >*/
	}
/*           Go check for the next line of info in the current define block */
/* SOURCE dual_source.for:614 */
/*<       goto200 >*/
	goto L200;
/* SOURCE dual_source.for:617 */
/*<       elseif(items(1)(1:3)=='END')then >*/
    } else if (s_cmp(items, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE dual_source.for:618 */
/*<       if(items(2)=='DUAL'.and.items(3)=='SOURCE')then >*/
	if (s_cmp(items + 128, const_cast<char*>("DUAL"), (ftnlen)128, (ftnlen)4) == 0 && s_cmp(
		items + 256, const_cast<char*>("SOURCE"), (ftnlen)128, (ftnlen)6) == 0) {
/* SOURCE dual_source.for:620 */
/*<       write(stdout,*)' ' >*/
	    feq_gen_io_d__94.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__94);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE dual_source.for:621 */
/*<       write(stdout,*)' Returning from dual_source' >*/
	    feq_gen_io_d__95.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__95);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Returning from dual_source"), (ftnlen)27);
	    e_wsle();
/* SOURCE dual_source.for:622 */
/*<       return >*/
	    return 0;
/* SOURCE dual_source.for:624 */
/*<       else >*/
	} else {
/* SOURCE dual_source.for:625 */
/*<       write(stdout,62) >*/
	    feq_gen_io_d__96.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__96);
	    e_wsfe();
/* SOURCE dual_source.for:626 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE dual_source.for:627 */
/*<       endif >*/
	}
/* SOURCE dual_source.for:628 */
/*<       endif >*/
    }
/* SOURCE dual_source.for:630 */
/*<       goto100 >*/
    goto L100;
/* SOURCE dual_source.for:632 */
/*<       end >*/
} /* dual_source__ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
