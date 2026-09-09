/* schematic.f -- translated by f2c (version 20240504).
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

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* COMMON homec_ is declared in common.hpp. */

#define homec_1 homec_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_0 = 0;

/*     Routines used to create the IntelliCAD 2000 script file */
/*     that defines the schematic for the model. */



/* SOURCE schematic.for:7 */
/*<       subroutinestrip_all_blanks(string,n) >*/
/* Subroutine */ int feq_gen_strip_all_blanks_d_(char *string, integer *n, ftnlen 
	string_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, knt;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Strip all blanks from the given string and return */
/* SOURCE schematic.for:13 */
/*<       implicitnone >*/
/* SOURCE schematic.for:14 */
/*<       character*(*)string >*/
/*     Local */
/* SOURCE schematic.for:18 */
/*<       integeri,knt,n >*/
/* *********************************************************************** */
/* SOURCE schematic.for:7 */
/*<       integer feq_len_trim >*/
/* SOURCE schematic.for:7 */
/*<       external feq_len_trim >*/
/* SOURCE schematic.for:20 */
/*<       n=feq_len_trim(string) >*/
    *n = feq_gen_feq_len_trim_d_(string, string_len);
/* SOURCE schematic.for:21 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE schematic.for:22 */
/*<       do100i=1,n >*/
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE schematic.for:23 */
/*<       if(string(i:i).ne.' ')then >*/
	if (*(unsigned char *)&string[feq_gen_i_d_ - 1] != ' ') {
/* SOURCE schematic.for:24 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE schematic.for:25 */
/*<       string(knt:knt)=string(i:i) >*/
	    *(unsigned char *)&string[knt - 1] = *(unsigned char *)&string[
		    feq_gen_i_d_ - 1];
/* SOURCE schematic.for:26 */
/*<       endif >*/
	}
/* SOURCE schematic.for:27 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE schematic.for:28 */
/*<       n=knt >*/
    *n = knt;
/* SOURCE schematic.for:29 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:30 */
/*<       end >*/
} /* strip_all_blanks__ */




/* SOURCE schematic.for:34 */
/*<        >*/
/* Subroutine */ int feq_gen_do_dummy_branches_d_(integer *stdout, integer *scmunit, 
	integer *nbra, integer *nex, integer *feq_storage_brpt, integer *feq_storage_exnodt, integer *
	feq_storage_emc, doublereal *feq_gen_half_l_d_)
{
    /* Initialized data */

    static integer null = -2147483647;
    static doublereal feq_gen_label_length_d_ = 220.;

    /* Format strings */
    static char fmt_52[] = "(\002;\002,\002 Dummy branch with free nodes:\
 \002,a5,\002, \002,a5)";
    static char fmt_54[] = "(\002Dummy branches not drawn in schematic\002\
,/,\002 Dummy Branch Ups                     Dummy Branch Dns\002,/,\002  No\
de     X-location     Y-location \002,\002  Node     X-location     Y-locati\
on\002)";
    static char fmt_56[] = "(\002 \002,a5,a15,a15,2x,a5,a15,a15)";

    /* System generated locals */
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[5];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_seek_free_node_location_d_(integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , doublereal *, doublereal *);
    char dnnlabel[5];
    integer feq_gen_node_knt_d_;
    char upnlabel[5];
    extern /* Subroutine */ int feq_gen_strip_all_blanks_d_(char *, integer *, ftnlen);
    doublereal m, x[2], y[2], aa, bb, cc, le, dx, xe, ye, dy, ls, xs, ys;
    integer dnn, upn;
    char feq_gen_dumbr_label_d_[11];
    integer out;
    extern /* Subroutine */ int feq_gen_draw_branch_graphic_d_(integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *);
    doublereal feq_gen_temp_length_d_;
    integer code, mode;
    char line[80];
    integer slen;
    doublereal dnnx;
    integer ipnt;
    doublereal dnny, upnx, upny, shift;
    extern /* Subroutine */ int feq_gen_find_line_coef_d_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    doublereal length;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer ientry, dnnflag, upnflag;
    char dnnxloc[15], dnnyloc[15], upnxloc[15], upnyloc[15];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__5 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__24 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, 0, 0 };


/*     Do dummy branches in a schematic */
/* SOURCE schematic.for:39 */
/*<       implicitnone >*/
/* INCLUDE schematic.for:40 */
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
/* SOURCE schematic.for:41 */
/*<        >*/
/* SOURCE schematic.for:44 */
/*<       real*8half_l >*/
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
/* INCLUDE schematic.for:72 */
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
/* INCLUDE schematic.for:73 */
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
/*     Called program units */
/* SOURCE schematic.for:77 */
/*<       charactergetusn*5 >*/
/* SOURCE schematic.for:78 */
/*<       externalgetusn,strip_all_blanks,find_perpendicular,find_line_coef >*/
/*     Local */
/* SOURCE schematic.for:82 */
/*<        >*/
/* SOURCE schematic.for:85 */
/*<        >*/
/* SOURCE schematic.for:89 */
/*<        >*/
/*     **************************FORMATS********************************* */
/* SOURCE schematic.for:93 */
/*<       datanull/-2147483647/,label_length/220.d0/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE schematic.for:96 */
/*<    52 format(';',' Dummy branch with free nodes: ',a5,', ',a5) >*/
/* L52: */
/* SOURCE schematic.for:97 */
/*<    54  >*/
/* L54: */
/* SOURCE schematic.for:101 */
/*<    56 format(' ',a5,a15,a15,2x,a5,a15,a15) >*/
/* L56: */
/* *********************************************************************** */
/* SOURCE schematic.for:103 */
/*<       label_length=2.d0*label_length >*/
    feq_gen_label_length_d_ = 2. * feq_gen_label_length_d_;
/*     General approach: */
/*     1. Scan EMC for dummy branches. */
/*     2. For each dummy branch extract the ups and dns node numbers */
/*     2.1 Check in EXNODT, in rows 6 and 7 to see if (x,y) is known for */
/*         this dummy branch from this source.   If not  goto 3 */
/*         otherwise */
/*     3. Scan EMC for code 2 (sum of flows = 0) and find */
/*        the one that containes the ups node (if any). */

/*     4. If found, then search for the other nodes in the junction */
/*        for information of (x,y). As any are found, compute the sum */
/*        of each coordinate value and count so that we can compute */
/*        an average location. */
/*     5. Do this for each end of the dummy branch. */
/*     6.  If both ends have (x,y) info, then we can plot the DumBr. */
/*     7. Plot like a branch but shift to a layer than creates dashed */
/*        lines. */
/*     8. Get the user values for the free-node and place them at the */
/*        appropriate end of the dummy branch dashed line. */
/*     Write heading for dummy branches not drawn */
/* SOURCE schematic.for:125 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__5.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__5);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE schematic.for:126 */
/*<       write(stdout,54) >*/
    feq_gen_io_d__6.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__6);
    e_wsfe();
/*     Start loop seaching for Dummy Branches.  CODE=15 */
/* SOURCE schematic.for:130 */
/*<       ientry=0 >*/
    ientry = 0;
/* SOURCE schematic.for:132 */
/*<   100 continue >*/
L100:
/* SOURCE schematic.for:133 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE schematic.for:134 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE schematic.for:135 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE schematic.for:136 */
/*<       if(code.eq.15)then >*/
    if (code == 15) {
/*         Get the ups and dns node numbers */
/* SOURCE schematic.for:138 */
/*<       upn=emc(ipnt+1) >*/
	upn = emc[ipnt + 1];
/* SOURCE schematic.for:139 */
/*<       dnn=emc(ipnt+2) >*/
	dnn = emc[ipnt + 2];
/* SOURCE schematic.for:140 */
/*<       upnlabel=getusn(upn) >*/
	getusn_(feq_gen_ch_d_1, (ftnlen)5, &upn);
	s_copy(upnlabel, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE schematic.for:141 */
/*<       dnnlabel=getusn(dnn) >*/
	getusn_(feq_gen_ch_d_1, (ftnlen)5, &dnn);
	s_copy(dnnlabel, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/*         Clear the location flags */
/* SOURCE schematic.for:144 */
/*<       upnflag=0 >*/
	upnflag = 0;
/* SOURCE schematic.for:145 */
/*<       dnnflag=0 >*/
	dnnflag = 0;
/*         Check to see if these nodes have a location given in EXNODT */
/* SOURCE schematic.for:148 */
/*<       if(exnodt(6,upn).gt.null)then >*/
	if (exnodt[upn * 9 + 6] > null) {
/* SOURCE schematic.for:149 */
/*<       upnflag=1 >*/
	    upnflag = 1;
/* SOURCE schematic.for:150 */
/*<       upnx=dble(exnodt(6,upn))/100.d0 >*/
	    upnx = (doublereal) exnodt[upn * 9 + 6] / 100.;
/* SOURCE schematic.for:151 */
/*<       upny=dble(exnodt(7,upn))/100.d0 >*/
	    upny = (doublereal) exnodt[upn * 9 + 7] / 100.;
/* SOURCE schematic.for:152 */
/*<       endif >*/
	}
/* SOURCE schematic.for:153 */
/*<       if(exnodt(6,dnn).gt.null)then >*/
	if (exnodt[dnn * 9 + 6] > null) {
/* SOURCE schematic.for:154 */
/*<       dnnflag=1 >*/
	    dnnflag = 1;
/* SOURCE schematic.for:155 */
/*<       dnnx=dble(exnodt(6,dnn))/100.d0 >*/
	    dnnx = (doublereal) exnodt[dnn * 9 + 6] / 100.;
/* SOURCE schematic.for:156 */
/*<       dnny=dble(exnodt(7,dnn))/100.d0 >*/
	    dnny = (doublereal) exnodt[dnn * 9 + 7] / 100.;
/* SOURCE schematic.for:157 */
/*<       endif >*/
	}
/*         Do searches for the location if needed */
/* SOURCE schematic.for:161 */
/*<       if(upnflag.eq.0)then >*/
	if (upnflag == 0) {
/*           A search is needed. */
/* SOURCE schematic.for:164 */
/*<        >*/
	    feq_gen_seek_free_node_location_d_(stdout, nbra, nex, &brpt[9], &emc[1], &
		    upn, &exnodt[10], &upnflag, &upnx, &upny);
/* SOURCE schematic.for:168 */
/*<       endif >*/
	}
/* SOURCE schematic.for:169 */
/*<       if(dnnflag.eq.0)then >*/
	if (dnnflag == 0) {
/*           A search is needed. */
/* SOURCE schematic.for:172 */
/*<        >*/
	    feq_gen_seek_free_node_location_d_(stdout, nbra, nex, &brpt[9], &emc[1], &
		    dnn, &exnodt[10], &dnnflag, &dnnx, &dnny);
/* SOURCE schematic.for:176 */
/*<       endif >*/
	}
/* SOURCE schematic.for:178 */
/*<       if(upnflag.eq.1.and.dnnflag.eq.1)then >*/
	if (upnflag == 1 && dnnflag == 1) {
/*           We can draw the dummy branch. */
/*           MODE not now used-maybe later */
/* SOURCE schematic.for:182 */
/*<       mode=1 >*/
	    mode = 1;
/* SOURCE schematic.for:183 */
/*<       x(1)=upnx >*/
	    x[0] = upnx;
/* SOURCE schematic.for:184 */
/*<       y(1)=upny >*/
	    y[0] = upny;
/* SOURCE schematic.for:185 */
/*<       x(2)=dnnx >*/
	    x[1] = dnnx;
/* SOURCE schematic.for:186 */
/*<       y(2)=dnny >*/
	    y[1] = dnny;
/* SOURCE schematic.for:187 */
/*<       node_knt=2 >*/
	    feq_gen_node_knt_d_ = 2;
/* SOURCE schematic.for:188 */
/*<       write(scmunit,52)upnlabel,dnnlabel >*/
	    feq_gen_io_d__24.ciunit = *scmunit;
	    s_wsfe(&feq_gen_io_d__24);
	    do_fio(&feq_gen_c_d_1, upnlabel, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, dnnlabel, (ftnlen)5);
	    e_wsfe();
/* SOURCE schematic.for:189 */
/*<       calldraw_branch_graphic(mode,scmunit,node_knt,x,y,half_l) >*/
	    feq_gen_draw_branch_graphic_d_(&mode, scmunit, &feq_gen_node_knt_d_, x, y, feq_gen_half_l_d_)
		    ;
/*           Do dummy branch labels here. */
/*           Select the layer for Dummy branch labels */
/* SOURCE schematic.for:195 */
/*<       write(scmunit,'(A)')'LAYER','MAKE','DUMBRLAB' >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *scmunit;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("LAYER"), (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("MAKE"), (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("DUMBRLAB"), (ftnlen)8);
	    e_wsfe();
/* SOURCE schematic.for:196 */
/*<       write(scmunit,'( )') >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *scmunit;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
	    s_wsfe(&feq_gen_ci_d_1);
	    e_wsfe();

/*           Find the length of the graphic */
/* SOURCE schematic.for:200 */
/*<       length=sqrt((x(2)-x(1))**2+(y(2)-y(1))**2) >*/
/* Computing 2nd power */
	    feq_gen_d_d_1 = x[1] - x[0];
/* Computing 2nd power */
	    feq_gen_d_d_2 = y[1] - y[0];
	    length = sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/*           Tailor the length to the length of the dummy branch */
/* SOURCE schematic.for:204 */
/*<       if(label_length.gt.0.8d0*length)then >*/
	    if (feq_gen_label_length_d_ > length * .8) {
/* SOURCE schematic.for:205 */
/*<       temp_length=0.8d0*length >*/
		feq_gen_temp_length_d_ = length * .8;
/* SOURCE schematic.for:206 */
/*<       else >*/
	    } else {
/* SOURCE schematic.for:207 */
/*<       temp_length=label_length >*/
		feq_gen_temp_length_d_ = feq_gen_label_length_d_;
/* SOURCE schematic.for:208 */
/*<       endif >*/
	    }
/*           Compute the offsets from the ups node */
/*           for the start and end of the text */
/* SOURCE schematic.for:212 */
/*<       ls=0.5*(length-temp_length) >*/
	    ls = (length - feq_gen_temp_length_d_) * (float).5;
/* SOURCE schematic.for:213 */
/*<       le=0.5*(length+temp_length) >*/
	    le = (length + feq_gen_temp_length_d_) * (float).5;
/* SOURCE schematic.for:215 */
/*<       xs=x(1)+ls*(x(2)-x(1))/length >*/
	    xs = x[0] + ls * (x[1] - x[0]) / length;
/* SOURCE schematic.for:216 */
/*<       ys=y(1)+ls*(y(2)-y(1))/length >*/
	    ys = y[0] + ls * (y[1] - y[0]) / length;
/* SOURCE schematic.for:217 */
/*<       xe=x(1)+le*(x(2)-x(1))/length >*/
	    xe = x[0] + le * (x[1] - x[0]) / length;
/* SOURCE schematic.for:218 */
/*<       ye=y(1)+le*(y(2)-y(1))/length >*/
	    ye = y[0] + le * (y[1] - y[0]) / length;
/*           Shift the label slightly away from the line. */
/* SOURCE schematic.for:222 */
/*<       callfind_line_coef(x(1),y(1),x(2),y(2),aa,bb,cc) >*/
	    feq_gen_find_line_coef_d_(x, y, &x[1], &y[1], &aa, &bb, &cc);
/*           There are 11 chars in the label placed over a distance */
/*           of TEMP_LENGTH.  Make the shift about 1/2 of the average */
/*           character width. */
/* SOURCE schematic.for:227 */
/*<       shift=temp_length/22.d0 >*/
	    shift = feq_gen_temp_length_d_ / 22.;
/* SOURCE schematic.for:228 */
/*<       m=-aa/bb >*/
	    m = -aa / bb;
/* SOURCE schematic.for:229 */
/*<       dx=shift/sqrt(1.d0/m**2+1.d0) >*/
/* Computing 2nd power */
	    feq_gen_d_d_1 = m;
	    dx = shift / sqrt(1. / (feq_gen_d_d_1 * feq_gen_d_d_1) + 1.);
/* SOURCE schematic.for:230 */
/*<       dy=shift/sqrt(m**2+1.d0) >*/
/* Computing 2nd power */
	    feq_gen_d_d_1 = m;
	    dy = shift / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + 1.);
/*           Set signs so that the shift is always on the same side */
/*           of a line considered to be directed from the S to */
/*           E end. */
/* SOURCE schematic.for:235 */
/*<       if(xe.gt.xs)then >*/
	    if (xe > xs) {
/* SOURCE schematic.for:236 */
/*<       if(m.gt.0.d0)then >*/
		if (m > 0.) {
/* SOURCE schematic.for:237 */
/*<       dx=-dx >*/
		    dx = -dx;
/* SOURCE schematic.for:238 */
/*<       endif >*/
		}
/* SOURCE schematic.for:239 */
/*<       else >*/
	    } else {
/* SOURCE schematic.for:240 */
/*<       if(m.lt.0.d0)then >*/
		if (m < 0.) {
/* SOURCE schematic.for:241 */
/*<       dx=-dx >*/
		    dx = -dx;
/* SOURCE schematic.for:242 */
/*<       dy=-dy >*/
		    dy = -dy;
/* SOURCE schematic.for:243 */
/*<       else >*/
		} else {
/* SOURCE schematic.for:244 */
/*<       dy=-dy >*/
		    dy = -dy;
/* SOURCE schematic.for:245 */
/*<       endif >*/
		}
/* SOURCE schematic.for:246 */
/*<       endif >*/
	    }
/* SOURCE schematic.for:249 */
/*<       xs=xs+dx >*/
	    xs += dx;
/* SOURCE schematic.for:250 */
/*<       ys=ys+dy >*/
	    ys += dy;
/* SOURCE schematic.for:251 */
/*<       xe=xe+dx >*/
	    xe += dx;
/* SOURCE schematic.for:252 */
/*<       ye=ye+dy >*/
	    ye += dy;
/*           Now do the text insertion */
/* SOURCE schematic.for:256 */
/*<       write(scmunit,'(A,/A)')'TEXT','A' >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *scmunit;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A,/A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("TEXT"), (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("A"), (ftnlen)1);
	    e_wsfe();
/* SOURCE schematic.for:257 */
/*<       write(line,'(F13.2,'','',F13.2)')xs,ys >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&xs, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&ys, (ftnlen)sizeof(doublereal));
	    e_wsfi();
/* SOURCE schematic.for:258 */
/*<       callstrip_all_blanks(line,slen) >*/
	    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:261 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *scmunit;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, line, slen);
	    e_wsfe();
/* SOURCE schematic.for:262 */
/*<       write(line,'(F13.2,'','',F13.2)')xe,ye >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&xe, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&ye, (ftnlen)sizeof(doublereal));
	    e_wsfi();
/* SOURCE schematic.for:263 */
/*<       callstrip_all_blanks(line,slen) >*/
	    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:266 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *scmunit;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, line, slen);
	    e_wsfe();
/* SOURCE schematic.for:268 */
/*<       dumbr_label(1:5)=upnlabel >*/
	    s_copy(feq_gen_dumbr_label_d_, upnlabel, (ftnlen)5, (ftnlen)5);
/* SOURCE schematic.for:269 */
/*<       dumbr_label(6:6)=':' >*/
	    *(unsigned char *)&feq_gen_dumbr_label_d_[5] = ':';
/* SOURCE schematic.for:270 */
/*<       dumbr_label(7:11)=dnnlabel >*/
	    s_copy(feq_gen_dumbr_label_d_ + 6, dnnlabel, (ftnlen)5, (ftnlen)5);
/* SOURCE schematic.for:271 */
/*<       write(scmunit,'(A11)')dumbr_label >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *scmunit;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A11)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, feq_gen_dumbr_label_d_, (ftnlen)11);
	    e_wsfe();
/*           Select the layer for Dummy branches */
/* SOURCE schematic.for:274 */
/*<       write(scmunit,'(A)')'LAYER','MAKE','DUMBR' >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *scmunit;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("LAYER"), (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("MAKE"), (ftnlen)4);
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("DUMBR"), (ftnlen)5);
	    e_wsfe();
/* SOURCE schematic.for:275 */
/*<       write(scmunit,'( )') >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *scmunit;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
	    s_wsfe(&feq_gen_ci_d_1);
	    e_wsfe();
/* SOURCE schematic.for:278 */
/*<       else >*/
	} else {
/*           Output note to user master output file for dummy branches not */
/*           drawn. */
/*           Clear the output flag. */
/* SOURCE schematic.for:282 */
/*<       out=0 >*/
	    out = 0;
/* SOURCE schematic.for:283 */
/*<       if(upnflag.eq.1)then >*/
	    if (upnflag == 1) {
/*             We have data at the upstream end.  Convert to character */
/* SOURCE schematic.for:285 */
/*<       write(upnxloc,'(F15.2)')upnx >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 15;
		feq_gen_ici_d_1.iciunit = upnxloc;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&upnx, (ftnlen)sizeof(doublereal));
		e_wsfi();
/* SOURCE schematic.for:286 */
/*<       write(upnyloc,'(F15.2)')upny >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 15;
		feq_gen_ici_d_1.iciunit = upnyloc;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&upny, (ftnlen)sizeof(doublereal));
		e_wsfi();
/* SOURCE schematic.for:287 */
/*<       out=1 >*/
		out = 1;
/* SOURCE schematic.for:288 */
/*<       else >*/
	    } else {
/* SOURCE schematic.for:289 */
/*<       upnxloc=' ' >*/
		s_copy(upnxloc, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1);
/* SOURCE schematic.for:290 */
/*<       upnyloc=' ' >*/
		s_copy(upnyloc, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1);
/* SOURCE schematic.for:291 */
/*<       endif >*/
	    }
/* SOURCE schematic.for:292 */
/*<       if(dnnflag.eq.1)then >*/
	    if (dnnflag == 1) {
/*             We have data at the downstream end.  Convert to character */
/* SOURCE schematic.for:294 */
/*<       write(dnnxloc,'(F15.2)')dnnx >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 15;
		feq_gen_ici_d_1.iciunit = dnnxloc;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&dnnx, (ftnlen)sizeof(doublereal));
		e_wsfi();
/* SOURCE schematic.for:295 */
/*<       write(dnnyloc,'(F15.2)')dnny >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 15;
		feq_gen_ici_d_1.iciunit = dnnyloc;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&dnny, (ftnlen)sizeof(doublereal));
		e_wsfi();
/* SOURCE schematic.for:296 */
/*<       out=1 >*/
		out = 1;
/* SOURCE schematic.for:297 */
/*<       else >*/
	    } else {
/* SOURCE schematic.for:298 */
/*<       dnnxloc=' ' >*/
		s_copy(dnnxloc, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1);
/* SOURCE schematic.for:299 */
/*<       dnnyloc=' ' >*/
		s_copy(dnnyloc, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1);
/* SOURCE schematic.for:300 */
/*<       endif >*/
	    }
/* SOURCE schematic.for:301 */
/*<       if(out.eq.1)then >*/
	    if (out == 1) {
/* SOURCE schematic.for:302 */
/*<       write(stdout,56)upnlabel,upnxloc,upnyloc,dnnlabel,dnnxloc,dnnyloc >*/
		feq_gen_io_d__48.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__48);
		do_fio(&feq_gen_c_d_1, upnlabel, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, upnxloc, (ftnlen)15);
		do_fio(&feq_gen_c_d_1, upnyloc, (ftnlen)15);
		do_fio(&feq_gen_c_d_1, dnnlabel, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, dnnxloc, (ftnlen)15);
		do_fio(&feq_gen_c_d_1, dnnyloc, (ftnlen)15);
		e_wsfe();
/* SOURCE schematic.for:304 */
/*<       endif >*/
	    }
/* SOURCE schematic.for:305 */
/*<       endif >*/
	}
/* SOURCE schematic.for:306 */
/*<       endif >*/
    }
/* SOURCE schematic.for:308 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE schematic.for:310 */
/*<       goto100 >*/
	goto L100;
/* SOURCE schematic.for:311 */
/*<       endif >*/
    }
/* SOURCE schematic.for:313 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__49.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__49);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE schematic.for:315 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:316 */
/*<       end >*/
} /* do_dummy_branches__ */




/* SOURCE schematic.for:320 */
/*<        >*/
/* Subroutine */ int feq_gen_seek_free_node_location_d_(integer *stdout, integer *nbra,
	 integer *nex, integer *feq_storage_brpt, integer *feq_storage_emc, integer *node, integer *
	feq_storage_exnodt, integer *nodeflag, doublereal *nodex, doublereal *nodey)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;
    static integer null = -2147483647;

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    integer j, k, n;
    doublereal x, y;
    integer cnn, knt, code, adrs, ipnt;
    doublereal sumx, sumy;
    integer feq_gen_class_d_;
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);
    integer ientry;

/*     Scan EMC seeking to find NODE in a Code 2 relationship that also */
/*     has either branches or free nodes with a known location. */
/* SOURCE schematic.for:328 */
/*<       implicitnone >*/
/* INCLUDE schematic.for:329 */
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
/* SOURCE schematic.for:330 */
/*<        >*/
/* SOURCE schematic.for:333 */
/*<       real*8nodex,nodey >*/
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
/* INCLUDE schematic.for:350 */
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
/* INCLUDE schematic.for:351 */
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
/*     Called program units */
/* SOURCE schematic.for:355 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE schematic.for:356 */
/*<       externalget_dp_from_ft >*/
/*     Local */
/* SOURCE schematic.for:361 */
/*<       integeradrs,code,ientry,ipnt,j,k,knt,n,cnn,class,null >*/
/* SOURCE schematic.for:364 */
/*<       real*8x,y,sumx,sumy,dnull >*/
/* *********************************************************************** */
/*     Scan over all CODE 2 entries and search for NODE */
/* SOURCE schematic.for:366 */
/*<       datadnull/-33.d6/,null/-2147483647/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE schematic.for:370 */
/*<       ientry=0 >*/
    ientry = 0;
/* SOURCE schematic.for:373 */
/*<   100 continue >*/
L100:
/* SOURCE schematic.for:374 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE schematic.for:375 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE schematic.for:376 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE schematic.for:377 */
/*<       if(code.eq.2)then >*/
    if (code == 2) {
/* SOURCE schematic.for:378 */
/*<       n=emc(ipnt+1) >*/
	n = emc[ipnt + 1];
/* SOURCE schematic.for:379 */
/*<       do200j=1,n >*/
	feq_gen_i_d_1 = n;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE schematic.for:380 */
/*<       if(node.eq.emc(ipnt+1+j))then >*/
	    if (*node == emc[ipnt + 1 + j]) {
/*             We have found the junction containing the node. */
/*             Rescan the nodes in the junction seeking */
/*             location values. */
/* SOURCE schematic.for:384 */
/*<       knt=0 >*/
		knt = 0;
/* SOURCE schematic.for:385 */
/*<       sumx=0.d0 >*/
		sumx = 0.;
/* SOURCE schematic.for:386 */
/*<       sumy=0.d0 >*/
		sumy = 0.;
/* SOURCE schematic.for:387 */
/*<       do150k=1,n >*/
		feq_gen_i_d_2 = n;
		for (k = 1; k <= feq_gen_i_d_2; ++k) {
/* SOURCE schematic.for:388 */
/*<       cnn=emc(ipnt+1+k) >*/
		    cnn = emc[ipnt + 1 + k];
/* SOURCE schematic.for:389 */
/*<       if(cnn.ne.node)then >*/
		    if (cnn != *node) {
/* SOURCE schematic.for:390 */
/*<       class=exnodt(3,cnn) >*/
			feq_gen_class_d_ = exnodt[cnn * 9 + 3];
/* SOURCE schematic.for:391 */
/*<       if(class.gt.0)then >*/
			if (feq_gen_class_d_ > 0) {
/*                   We have a branch.  Get the (x,y) from the */
/*                   cross-section-function table */
/* SOURCE schematic.for:394 */
/*<       adrs=exnodt(4,cnn) >*/
			    adrs = exnodt[cnn * 9 + 4];
/* SOURCE schematic.for:395 */
/*<       x=get_dp_from_ft(adrs+8) >*/
			    feq_gen_i_d_3 = adrs + 8;
			    x = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_3);
/* SOURCE schematic.for:396 */
/*<       y=get_dp_from_ft(adrs+10) >*/
			    feq_gen_i_d_3 = adrs + 10;
			    y = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_3);
/* SOURCE schematic.for:397 */
/*<       if(x.gt.dnull)then >*/
			    if (x > dnull) {
/*                     Location is known. */
/* SOURCE schematic.for:399 */
/*<       knt=knt+1 >*/
				++knt;
/* SOURCE schematic.for:400 */
/*<       sumx=sumx+x >*/
				sumx += x;
/* SOURCE schematic.for:401 */
/*<       sumy=sumy+y >*/
				sumy += y;
/* SOURCE schematic.for:402 */
/*<       endif >*/
			    }
/* SOURCE schematic.for:403 */
/*<       elseif(class.le.0)then >*/
			} else if (feq_gen_class_d_ <= 0) {
/*                   We have a free node.  Check to see if its location */
/*                   is known. */
/* SOURCE schematic.for:406 */
/*<       if(exnodt(6,cnn).gt.null)then >*/
			    if (exnodt[cnn * 9 + 6] > null) {
/*                     Location is known */
/* SOURCE schematic.for:408 */
/*<       x=dble(exnodt(6,cnn))/100.d0 >*/
				x = (doublereal) exnodt[cnn * 9 + 6] / 100.;
/* SOURCE schematic.for:409 */
/*<       y=dble(exnodt(7,cnn))/100.d0 >*/
				y = (doublereal) exnodt[cnn * 9 + 7] / 100.;
/* SOURCE schematic.for:410 */
/*<       knt=knt+1 >*/
				++knt;
/* SOURCE schematic.for:411 */
/*<       sumx=sumx+x >*/
				sumx += x;
/* SOURCE schematic.for:412 */
/*<       sumy=sumy+y >*/
				sumy += y;
/* SOURCE schematic.for:413 */
/*<       endif >*/
			    }
/* SOURCE schematic.for:414 */
/*<       endif >*/
			}
/* SOURCE schematic.for:415 */
/*<       endif >*/
		    }
/* SOURCE schematic.for:416 */
/*<   150 continue >*/
/* L150: */
		}
/* SOURCE schematic.for:417 */
/*<       if(knt.gt.0)then >*/
		if (knt > 0) {
/*               Compute the average value for the coordinate */
/* SOURCE schematic.for:420 */
/*<       nodex=sumx/dble(knt) >*/
		    *nodex = sumx / (doublereal) knt;
/* SOURCE schematic.for:421 */
/*<       nodey=sumy/dble(knt) >*/
		    *nodey = sumy / (doublereal) knt;
/* SOURCE schematic.for:422 */
/*<       nodeflag=1 >*/
		    *nodeflag = 1;
/*               Store the known value for the free node into */
/*               EXNODT */
/* SOURCE schematic.for:425 */
/*<       exnodt(6,node)=nint(nodex*100.d0) >*/
		    feq_gen_d_d_1 = *nodex * 100.;
		    exnodt[*node * 9 + 6] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE schematic.for:426 */
/*<       exnodt(7,node)=nint(nodey*100.d0) >*/
		    feq_gen_d_d_1 = *nodey * 100.;
		    exnodt[*node * 9 + 7] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE schematic.for:427 */
/*<       goto300 >*/
		    goto L300;
/* SOURCE schematic.for:428 */
/*<       endif >*/
		}
/* SOURCE schematic.for:429 */
/*<       endif >*/
	    }
/* SOURCE schematic.for:430 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE schematic.for:431 */
/*<       endif >*/
    }
/* SOURCE schematic.for:432 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE schematic.for:434 */
/*<       goto100 >*/
	goto L100;
/* SOURCE schematic.for:435 */
/*<       endif >*/
    }
/* SOURCE schematic.for:437 */
/*<   300 continue >*/
L300:
/* SOURCE schematic.for:438 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:439 */
/*<       end >*/
} /* seek_free_node_location__ */




/* SOURCE schematic.for:443 */
/*<       subroutinedraw_branch_graphic(mode,scmunit,node_knt,x,y,half_l) >*/
/* Subroutine */ int feq_gen_draw_branch_graphic_d_(integer *mode, integer *scmunit, 
	integer *feq_gen_node_knt_d_, doublereal *feq_storage_x, doublereal *feq_storage_y, doublereal *
	feq_gen_half_l_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsfi(icilist *), e_wsfi();
    double sqrt(doublereal);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_strip_all_blanks_d_(char *, integer *, ftnlen);
    doublereal a, b, feq_gen_c_d_;
    integer j;
    doublereal m, ap, bp, cp, dx, dy;
    extern /* Subroutine */ int feq_gen_find_perpendicular_d_(doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    char line[80];
    integer slen;
    doublereal xtick, ytick;
    extern /* Subroutine */ int feq_gen_find_line_coef_d_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);

/*     Draw the graphic for a branch, either real or dummy. */
/* SOURCE schematic.for:448 */
/*<       implicitnone >*/
/* SOURCE schematic.for:449 */
/*<       integermode,scmunit,node_knt >*/
/* SOURCE schematic.for:450 */
/*<       real*8x(node_knt),y(node_knt),half_l >*/
/*     Called program units. */
/* SOURCE schematic.for:453 */
/*<       externalstrip_all_blanks,find_line_coef,find_perpendicular >*/
/*     Local */
/* SOURCE schematic.for:458 */
/*<       integerj,slen >*/
/* SOURCE schematic.for:460 */
/*<       real*8a,b,c,ap,bp,cp,dx,dy,xtick,ytick,m >*/
/* SOURCE schematic.for:462 */
/*<       characterline*80 >*/
/* *********************************************************************** */
/*     Output the polyline command */
/* SOURCE schematic.for:467 */
/*<       write(scmunit,'(A)')'PLINE' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> y(feq_storage_y, 1);

    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("PLINE"), (ftnlen)5);
    e_wsfe();
/*     Output the x,y pairs, one per line */
/* SOURCE schematic.for:469 */
/*<       do110j=1,node_knt >*/
    feq_gen_i_d_1 = *feq_gen_node_knt_d_;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE schematic.for:470 */
/*<       write(line,'(F13.2,'','',F13.2)')x(j),y(j) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&x[j], (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&y[j], (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE schematic.for:471 */
/*<       callstrip_all_blanks(line,slen) >*/
	feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:474 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, slen);
	e_wsfe();
/* SOURCE schematic.for:475 */
/*<   110 continue >*/
/* L110: */
    }
/*     Write a blank line to terminate the polyline command */
/* SOURCE schematic.for:478 */
/*<       write(scmunit,'( )') >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
    s_wsfe(&feq_gen_ci_d_1);
    e_wsfe();
/*     Compute the end points of the polyline that will represent */
/*     the ends of a branch.   We find the coefficents for the general */
/*     equation of a straight line that is perpendicular to the */
/*     a line segment at one end and then at the other end of */
/*     the polyline for the branch.  We then define the end points */
/*     of a line segment on this perpendicular line to establish the */
/*     graphic object that we want, */
/*     Find the coef. of the line that passes through the */
/*     endpoints of the line segement at the upstream end of */
/*     the branch. */
/* SOURCE schematic.for:492 */
/*<       callfind_line_coef(x(1),y(1),x(2),y(2),a,b,c) >*/
    feq_gen_find_line_coef_d_(&x[1], &y[1], &x[2], &y[2], &a, &b, &feq_gen_c_d_);
/*     Find the coef. of the line that is perpendicular to the */
/*     line just found and also passes through [X(1), Y(1)]. */
/* SOURCE schematic.for:498 */
/*<       callfind_perpendicular(x(1),y(1),a,b,c,ap,bp,cp) >*/
    feq_gen_find_perpendicular_d_(&x[1], &y[1], &a, &b, &feq_gen_c_d_, &ap, &bp, &cp);
/*     Compute the slope of the perpendicular line,  The general */
/*     equation for this line is: AP*X + BP*Y + CP = 0.  We solve */
/*     for M in the equation:  Y = M*X + Q, where M is the slope and */
/*     Q is the intercept.  This yields:  M = -AP/BP.  BP may be zero, */
/*     however both LF90 and LF95 include the IEEE floating point extensions */
/*     that include infinity in a logical manner.  Division by zero yields */
/*     infinity of the proper sign assuming the numerator of the ratio is */
/*     not also zero.  If it is zero we get Not a Number as the result. */
/*     Division of any non-zero by infinity yields zero. */
/* SOURCE schematic.for:511 */
/*<       m=-ap/bp >*/
    m = -ap / bp;
/* SOURCE schematic.for:513 */
/*<       write(scmunit,'(A)')'PLINE' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("PLINE"), (ftnlen)5);
    e_wsfe();
/* SOURCE schematic.for:514 */
/*<       dx=half_l/sqrt(1.d0+m**2) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = m;
    dx = *feq_gen_half_l_d_ / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + 1.);
/* SOURCE schematic.for:515 */
/*<       dy=half_l/sqrt(1.d0+1.d0/m**2) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = m;
    dy = *feq_gen_half_l_d_ / sqrt(1. / (feq_gen_d_d_1 * feq_gen_d_d_1) + 1.);
/* SOURCE schematic.for:517 */
/*<       if(m.gt.0.d0)then >*/
    if (m > 0.) {
/* SOURCE schematic.for:518 */
/*<       xtick=x(1)+dx >*/
	xtick = x[1] + dx;
/* SOURCE schematic.for:519 */
/*<       ytick=y(1)+dy >*/
	ytick = y[1] + dy;
/* SOURCE schematic.for:520 */
/*<       else >*/
    } else {
/* SOURCE schematic.for:521 */
/*<       xtick=x(1)+dx >*/
	xtick = x[1] + dx;
/* SOURCE schematic.for:522 */
/*<       ytick=y(1)-dy >*/
	ytick = y[1] - dy;
/* SOURCE schematic.for:523 */
/*<       endif >*/
    }
/* SOURCE schematic.for:525 */
/*<       write(line,'(F13.2,'','',F13.2)')xtick,ytick >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&xtick, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&ytick, (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:526 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:529 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:531 */
/*<       if(m.gt.0.d0)then >*/
    if (m > 0.) {
/* SOURCE schematic.for:532 */
/*<       xtick=x(1)-dx >*/
	xtick = x[1] - dx;
/* SOURCE schematic.for:533 */
/*<       ytick=y(1)-dy >*/
	ytick = y[1] - dy;
/* SOURCE schematic.for:534 */
/*<       else >*/
    } else {
/* SOURCE schematic.for:535 */
/*<       xtick=x(1)-dx >*/
	xtick = x[1] - dx;
/* SOURCE schematic.for:536 */
/*<       ytick=y(1)+dy >*/
	ytick = y[1] + dy;
/* SOURCE schematic.for:537 */
/*<       endif >*/
    }
/* SOURCE schematic.for:538 */
/*<       write(line,'(F13.2,'','',F13.2)')xtick,ytick >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&xtick, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&ytick, (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:539 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:542 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:544 */
/*<       write(scmunit,'( )') >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
    s_wsfe(&feq_gen_ci_d_1);
    e_wsfe();
/*     Do the dns end of the branch */
/* SOURCE schematic.for:547 */
/*<        >*/
    feq_gen_find_line_coef_d_(&x[*feq_gen_node_knt_d_ - 1], &y[*feq_gen_node_knt_d_ - 1], &x[*feq_gen_node_knt_d_]
	    , &y[*feq_gen_node_knt_d_], &a, &b, &feq_gen_c_d_);
/* SOURCE schematic.for:550 */
/*<       callfind_perpendicular(x(node_knt),y(node_knt),a,b,c,ap,bp,cp) >*/
    feq_gen_find_perpendicular_d_(&x[*feq_gen_node_knt_d_], &y[*feq_gen_node_knt_d_], &a, &b, &feq_gen_c_d_, &ap, 
	    &bp, &cp);
/* SOURCE schematic.for:552 */
/*<       m=-ap/bp >*/
    m = -ap / bp;
/* SOURCE schematic.for:554 */
/*<       write(scmunit,'(A)')'PLINE' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("PLINE"), (ftnlen)5);
    e_wsfe();
/* SOURCE schematic.for:555 */
/*<       dx=half_l/sqrt(1.d0+m**2) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = m;
    dx = *feq_gen_half_l_d_ / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + 1.);
/* SOURCE schematic.for:556 */
/*<       dy=half_l/sqrt(1.d0+1.d0/m**2) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = m;
    dy = *feq_gen_half_l_d_ / sqrt(1. / (feq_gen_d_d_1 * feq_gen_d_d_1) + 1.);
/* SOURCE schematic.for:558 */
/*<       if(m.gt.0.d0)then >*/
    if (m > 0.) {
/* SOURCE schematic.for:559 */
/*<       xtick=x(node_knt)+dx >*/
	xtick = x[*feq_gen_node_knt_d_] + dx;
/* SOURCE schematic.for:560 */
/*<       ytick=y(node_knt)+dy >*/
	ytick = y[*feq_gen_node_knt_d_] + dy;
/* SOURCE schematic.for:561 */
/*<       else >*/
    } else {
/* SOURCE schematic.for:562 */
/*<       xtick=x(node_knt)+dx >*/
	xtick = x[*feq_gen_node_knt_d_] + dx;
/* SOURCE schematic.for:563 */
/*<       ytick=y(node_knt)-dy >*/
	ytick = y[*feq_gen_node_knt_d_] - dy;
/* SOURCE schematic.for:564 */
/*<       endif >*/
    }
/* SOURCE schematic.for:566 */
/*<       write(line,'(F13.2,'','',F13.2)')xtick,ytick >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&xtick, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&ytick, (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:567 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:570 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:571 */
/*<       if(m.gt.0.d0)then >*/
    if (m > 0.) {
/* SOURCE schematic.for:572 */
/*<       xtick=x(node_knt)-dx >*/
	xtick = x[*feq_gen_node_knt_d_] - dx;
/* SOURCE schematic.for:573 */
/*<       ytick=y(node_knt)-dy >*/
	ytick = y[*feq_gen_node_knt_d_] - dy;
/* SOURCE schematic.for:574 */
/*<       else >*/
    } else {
/* SOURCE schematic.for:575 */
/*<       xtick=x(node_knt)-dx >*/
	xtick = x[*feq_gen_node_knt_d_] - dx;
/* SOURCE schematic.for:576 */
/*<       ytick=y(node_knt)+dy >*/
	ytick = y[*feq_gen_node_knt_d_] + dy;
/* SOURCE schematic.for:577 */
/*<       endif >*/
    }
/* SOURCE schematic.for:578 */
/*<       write(line,'(F13.2,'','',F13.2)')xtick,ytick >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&xtick, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&ytick, (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:579 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:582 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:584 */
/*<       write(scmunit,'( )') >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
    s_wsfe(&feq_gen_ci_d_1);
    e_wsfe();
/* SOURCE schematic.for:586 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:587 */
/*<       end >*/
} /* draw_branch_graphic__ */




/* SOURCE schematic.for:592 */
/*<        >*/
/* Subroutine */ int feq_gen_free_node_location_define_d_(integer *stdout, integer *
	nex, integer *feq_gen_feq_storage_base_node_vec_d_, integer *feq_storage_exnodt, integer *eflag)
{
    /* Initialized data */

    static integer null = -2147483647;
    static doublereal dnull = -3.3e7;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:398* Base node= \002,a5,\002 for fr\
ee node= \002,a5,\002 has at least one undefined coordinate value.\002)";
    static char fmt_52[] = "(/,\002 *ERR:399* Free node= \002,a5,\002 has at\
 least one offset value that is unknown.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer i_dnnt(doublereal *);

    /* Local variables */
    integer feq_gen_base_node_number_d_, feq_gen_i_d_;
    char feq_gen_base_node_d_[5];
    integer adrs;
    doublereal xloc, yloc, xbase;
    integer feq_gen_class_d_;
    doublereal ybase;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_52, 0 };


/*     Define the free-node locations for a schematic. */
/* SOURCE schematic.for:598 */
/*<       implicitnone >*/
/* SOURCE schematic.for:600 */
/*<       integerstdout,nex,base_node_vec(nex),exnodt(9,nex),eflag >*/
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
/*               6    X location of the node in a cartesian coordinate system */
/*               7    Y location of the node in a cartesian coordiante system. */
/*                   The (X,Y) are scaled upward by 100.  That is */
/*                   a coordinate value of 1234.51 becomes then integer */
/*                   123451.  If the coordinate value is -(2**31 -1) it */
/*                   indicates that no value for a coordinate exists. */
/*                   The scaling permits a maximum value of 2**31/100 */
/*                   distance units.  When the length unit is feet the */
/*                   maximum coordinate is 21,474,836.48 feet or */
/*                   about 4067 miles.  This appears to be adequate */
/*                   for any reasonable purpose! */
/*     Common blocks and parameters */
/* INCLUDE schematic.for:629 */
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
/* INCLUDE schematic.for:630 */
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
/*     Called program units */
/* SOURCE schematic.for:633 */
/*<       charactergetusn*5 >*/
/* SOURCE schematic.for:634 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE schematic.for:635 */
/*<       externalget_dp_from_ft,getusn >*/
/*     Local */
/* SOURCE schematic.for:639 */
/*<       integeradrs,base_node_number,class,i,null >*/
/* SOURCE schematic.for:640 */
/*<       real*8dnull,xbase,ybase,xloc,yloc >*/
/* SOURCE schematic.for:641 */
/*<       characterbase_node*5 >*/
/*     ****************************************************************** */
/* SOURCE schematic.for:643 */
/*<       datanull/-2147483647/,dnull/-33.d6/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> feq_gen_base_node_vec_d_(feq_gen_feq_storage_base_node_vec_d_, 1);

    /* Function Body */
/* SOURCE schematic.for:646 */
/*<    50  >*/
/* L50: */
/* SOURCE schematic.for:648 */
/*<    52  >*/
/* L52: */
/* *********************************************************************** */
/*     Check all values in BASE_NODE_VEC for a non-zero.  Branch-node */
/*     locations are not given in EXNODT.  Thus they will have a zero value */
/*     for BASE_NODE_VEC and the null value for the offset values.  If */
/*     absolute offsets were given for a free node, the BASE_NODE value */
/*     will also be zero.  Thus the only adjustments made here are for */
/*     non-zero base-node values.   The base-node could be a free node */
/*     or a node on a branch.  The null value for nodes on a branch */
/*     differs because those values are stored in the cross-section */
/*     function table at full double precision.  A reference to a */
/*     base node that has null values for its location is a user */
/*     error. */
/* SOURCE schematic.for:663 */
/*<       do500i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE schematic.for:664 */
/*<       base_node_number=base_node_vec(i) >*/
	feq_gen_base_node_number_d_ = feq_gen_base_node_vec_d_[feq_gen_i_d_];
/* SOURCE schematic.for:665 */
/*<       if(base_node_number.gt.0)then >*/
	if (feq_gen_base_node_number_d_ > 0) {
/*         We have a base node reference. */
/*         Get the user label for this base node and its class: */
/*         on a branch or a free node. */
/* SOURCE schematic.for:669 */
/*<       base_node=getusn(base_node_number) >*/
	    getusn_(feq_gen_ch_d_1, (ftnlen)5, &feq_gen_base_node_number_d_);
	    s_copy(feq_gen_base_node_d_, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE schematic.for:670 */
/*<       class=exnodt(3,base_node_number) >*/
	    feq_gen_class_d_ = exnodt[feq_gen_base_node_number_d_ * 9 + 3];
/* SOURCE schematic.for:671 */
/*<       if(class.gt.0)then >*/
	    if (feq_gen_class_d_ > 0) {
/*           Base node is on the end of a branch.  Get the */
/*           function-table address. */
/* SOURCE schematic.for:674 */
/*<       adrs=exnodt(2,base_node_number) >*/
		adrs = exnodt[feq_gen_base_node_number_d_ * 9 + 2];
/* SOURCE schematic.for:675 */
/*<       xbase=get_dp_from_ft(adrs+8) >*/
		feq_gen_i_d_2 = adrs + 8;
		xbase = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE schematic.for:676 */
/*<       ybase=get_dp_from_ft(adrs+10) >*/
		feq_gen_i_d_2 = adrs + 10;
		ybase = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/*           Check for validity */
/* SOURCE schematic.for:678 */
/*<       if(xbase.le.dnull.or.ybase.le.dnull)then >*/
		if (xbase <= dnull || ybase <= dnull) {
/* SOURCE schematic.for:679 */
/*<       write(stdout,50)base_node,getusn(i) >*/
		    feq_gen_io_d__89.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__89);
		    do_fio(&feq_gen_c_d_1, feq_gen_base_node_d_, (ftnlen)5);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    e_wsfe();
/* SOURCE schematic.for:680 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE schematic.for:681 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE schematic.for:682 */
/*<       endif >*/
		}
/* SOURCE schematic.for:683 */
/*<       else >*/
	    } else {
/*           Base node is a free node. */
/* SOURCE schematic.for:685 */
/*<        >*/
		if (exnodt[feq_gen_base_node_number_d_ * 9 + 6] == null || exnodt[
			feq_gen_base_node_number_d_ * 9 + 7] == null) {
/* SOURCE schematic.for:687 */
/*<       write(stdout,50)base_node,getusn(i) >*/
		    feq_gen_io_d__90.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__90);
		    do_fio(&feq_gen_c_d_1, feq_gen_base_node_d_, (ftnlen)5);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    e_wsfe();
/* SOURCE schematic.for:688 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE schematic.for:689 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE schematic.for:690 */
/*<       endif >*/
		}
/*           Convert to REAL */
/* SOURCE schematic.for:692 */
/*<       xbase=dble(exnodt(6,base_node_number))/100.d0 >*/
		xbase = (doublereal) exnodt[feq_gen_base_node_number_d_ * 9 + 6] / 
			100.;
/* SOURCE schematic.for:693 */
/*<       ybase=dble(exnodt(7,base_node_number))/100.d0 >*/
		ybase = (doublereal) exnodt[feq_gen_base_node_number_d_ * 9 + 7] / 
			100.;
/* SOURCE schematic.for:694 */
/*<       endif >*/
	    }
/*         We now have the base location.  Add the offsets to get */
/*         the final location. */
/* SOURCE schematic.for:698 */
/*<       if(exnodt(6,i).eq.null.or.exnodt(7,i).eq.null)then >*/
	    if (exnodt[feq_gen_i_d_ * 9 + 6] == null || exnodt[feq_gen_i_d_ * 9 + 7] == null) {
/* SOURCE schematic.for:699 */
/*<       write(stdout,52)getusn(i) >*/
		feq_gen_io_d__91.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__91);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		e_wsfe();
/* SOURCE schematic.for:700 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE schematic.for:701 */
/*<       stop'Abnormal stop.  Error(s) found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Error(s) found."), (ftnlen)31);
/* SOURCE schematic.for:702 */
/*<       endif >*/
	    }
/* SOURCE schematic.for:704 */
/*<       xloc=xbase+dble(exnodt(6,i))/100.d0 >*/
	    xloc = xbase + (doublereal) exnodt[feq_gen_i_d_ * 9 + 6] / 100.;
/* SOURCE schematic.for:705 */
/*<       yloc=ybase+dble(exnodt(7,i))/100.d0 >*/
	    yloc = ybase + (doublereal) exnodt[feq_gen_i_d_ * 9 + 7] / 100.;
/*         Rescale and convert to integer again. */
/* SOURCE schematic.for:707 */
/*<       exnodt(6,i)=nint(xloc*100.d0) >*/
	    feq_gen_d_d_1 = xloc * 100.;
	    exnodt[feq_gen_i_d_ * 9 + 6] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE schematic.for:708 */
/*<       exnodt(7,i)=nint(yloc*100.d0) >*/
	    feq_gen_d_d_1 = yloc * 100.;
	    exnodt[feq_gen_i_d_ * 9 + 7] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE schematic.for:709 */
/*<       endif >*/
	}
/* SOURCE schematic.for:710 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE schematic.for:711 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:712 */
/*<       end >*/
} /* free_node_location_define__ */




/* SOURCE schematic.for:716 */
/*<       subroutinedraw_lpr_graphic(scmunit,node_knt,x,y,dnnlabel) >*/
/* Subroutine */ int feq_gen_draw_lpr_graphic_d_(integer *scmunit, integer *feq_gen_node_knt_d_,
	 doublereal *feq_storage_x, doublereal *feq_storage_y, char *dnnlabel, ftnlen dnnlabel_len)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_strip_all_blanks_d_(char *, integer *, ftnlen);
    doublereal a, b, feq_gen_c_d_, feq_gen_d_d_, m, feq_gen_r_d_, ap, bp, cp, xc, dx, dy, yc, xl, yl, xr,
	     yr;
    extern /* Subroutine */ int feq_gen_find_perpendicular_d_(doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    char line[80];
    integer slen;
    doublereal xtick, ytick;
    extern /* Subroutine */ int feq_gen_find_line_coef_d_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);

/*     Draw the graphic for a LPR */
/* SOURCE schematic.for:720 */
/*<       implicitnone >*/
/* SOURCE schematic.for:721 */
/*<       integerscmunit,node_knt >*/
/* SOURCE schematic.for:722 */
/*<       real*8x(node_knt),y(node_knt) >*/
/* SOURCE schematic.for:723 */
/*<       characterdnnlabel*5 >*/
/*     Called program units. */
/* SOURCE schematic.for:726 */
/*<       externalstrip_all_blanks,find_line_coef,find_perpendicular >*/
/*     Local */
/* SOURCE schematic.for:731 */
/*<       integerslen >*/
/* SOURCE schematic.for:733 */
/*<       real*8a,b,c,ap,bp,cp,dx,dy,xtick,ytick,m,d,r,xc,yc,xl,yl,xr,yr >*/
/* SOURCE schematic.for:736 */
/*<       characterline*80 >*/
/* *********************************************************************** */
/*     Compute the diameter of the circle. */
/* SOURCE schematic.for:740 */
/*<       d=sqrt((x(2)-x(1))**2+(y(2)-y(1))**2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> y(feq_storage_y, 1);

    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
/* Computing 2nd power */
    feq_gen_d_d_1 = x[2] - x[1];
/* Computing 2nd power */
    feq_gen_d_d_2 = y[2] - y[1];
    feq_gen_d_d_ = sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE schematic.for:741 */
/*<       r=0.4*d >*/
    feq_gen_r_d_ = feq_gen_d_d_ * (float).4;
/*     Issue the 2-point circle command */
/* SOURCE schematic.for:744 */
/*<       write(scmunit,'(A,/,A)')'CIRCLE','2P' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A,/,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("CIRCLE"), (ftnlen)6);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("2P"), (ftnlen)2);
    e_wsfe();
/* SOURCE schematic.for:745 */
/*<       write(line,'(F13.2,'','',F13.2)')x(1),y(1) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&x[1], (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&y[1], (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:746 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:749 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:750 */
/*<       write(line,'(F13.2,'','',F13.2)')x(2),y(2) >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&x[2], (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&y[2], (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:751 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:754 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/*     Find the coef. of the line that passes through the */
/*     diameter line segment. */
/* SOURCE schematic.for:760 */
/*<       callfind_line_coef(x(1),y(1),x(2),y(2),a,b,c) >*/
    feq_gen_find_line_coef_d_(&x[1], &y[1], &x[2], &y[2], &a, &b, &feq_gen_c_d_);
/*     Find the coef. of the line that is perpendicular to the */
/*     line just found and also passes through [X(2), Y(2)], */
/*     the downstream node of the LPR. */
/* SOURCE schematic.for:767 */
/*<       callfind_perpendicular(x(2),y(2),a,b,c,ap,bp,cp) >*/
    feq_gen_find_perpendicular_d_(&x[2], &y[2], &a, &b, &feq_gen_c_d_, &ap, &bp, &cp);
/*     Compute the slope of the perpendicular line,  The general */
/*     equation for this line is: AP*X + BP*Y + CP = 0.  We solve */
/*     for M in the equation:  Y = M*X + Q, where M is the slope and */
/*     Q is the intercept.  This yields:  M = -AP/BP.  BP may be zero, */
/*     however both LF90 and LF95 include the IEEE floating point extensions */
/*     that include infinity in a logical manner.  Division by zero yields */
/*     infinity of the proper sign assuming the numerator of the ratio is */
/*     not also zero.  If it is zero we get Not a Number as the result. */
/*     Division of any non-zero by infinity yields zero. */
/* SOURCE schematic.for:780 */
/*<       m=-ap/bp >*/
    m = -ap / bp;
/* SOURCE schematic.for:782 */
/*<       write(scmunit,'(A)')'PLINE' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("PLINE"), (ftnlen)5);
    e_wsfe();
/* SOURCE schematic.for:783 */
/*<       dx=r/sqrt(1.d0+m**2) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = m;
    dx = feq_gen_r_d_ / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + 1.);
/* SOURCE schematic.for:784 */
/*<       dy=r/sqrt(1.d0+1.d0/m**2) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = m;
    dy = feq_gen_r_d_ / sqrt(1. / (feq_gen_d_d_1 * feq_gen_d_d_1) + 1.);
/* SOURCE schematic.for:786 */
/*<       if(m.gt.0.d0)then >*/
    if (m > 0.) {
/* SOURCE schematic.for:787 */
/*<       xtick=x(2)+dx >*/
	xtick = x[2] + dx;
/* SOURCE schematic.for:788 */
/*<       ytick=y(2)+dy >*/
	ytick = y[2] + dy;
/* SOURCE schematic.for:789 */
/*<       else >*/
    } else {
/* SOURCE schematic.for:790 */
/*<       xtick=x(2)+dx >*/
	xtick = x[2] + dx;
/* SOURCE schematic.for:791 */
/*<       ytick=y(2)-dy >*/
	ytick = y[2] - dy;
/* SOURCE schematic.for:792 */
/*<       endif >*/
    }
/* SOURCE schematic.for:794 */
/*<       write(line,'(F13.2,'','',F13.2)')xtick,ytick >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&xtick, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&ytick, (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:795 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:798 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:800 */
/*<       if(m.gt.0.d0)then >*/
    if (m > 0.) {
/* SOURCE schematic.for:801 */
/*<       xtick=x(2)-dx >*/
	xtick = x[2] - dx;
/* SOURCE schematic.for:802 */
/*<       ytick=y(2)-dy >*/
	ytick = y[2] - dy;
/* SOURCE schematic.for:803 */
/*<       else >*/
    } else {
/* SOURCE schematic.for:804 */
/*<       xtick=x(2)-dx >*/
	xtick = x[2] - dx;
/* SOURCE schematic.for:805 */
/*<       ytick=y(2)+dy >*/
	ytick = y[2] + dy;
/* SOURCE schematic.for:806 */
/*<       endif >*/
    }
/* SOURCE schematic.for:807 */
/*<       write(line,'(F13.2,'','',F13.2)')xtick,ytick >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&xtick, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&ytick, (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:808 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:811 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:813 */
/*<       write(scmunit,'( )') >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
    s_wsfe(&feq_gen_ci_d_1);
    e_wsfe();
/*     Label the LPR with its downstream node label on a horizontal */
/*     line a bit below the center of the circle. */
/* SOURCE schematic.for:817 */
/*<       xc=0.5*(x(1)+x(2)) >*/
    xc = (x[1] + x[2]) * (float).5;
/* SOURCE schematic.for:818 */
/*<       yc=0.5*(y(1)+y(2)) >*/
    yc = (y[1] + y[2]) * (float).5;
/*     Drop the line by a fraction of the diameter */
/* SOURCE schematic.for:820 */
/*<       dy=0.1*d >*/
    dy = feq_gen_d_d_ * (float).1;
/* SOURCE schematic.for:821 */
/*<       dx=0.35*d >*/
    dx = feq_gen_d_d_ * (float).35;
/* SOURCE schematic.for:822 */
/*<       xl=xc-dx >*/
    xl = xc - dx;
/* SOURCE schematic.for:823 */
/*<       yl=yc-dy >*/
    yl = yc - dy;
/* SOURCE schematic.for:824 */
/*<       xr=xc+dx >*/
    xr = xc + dx;
/* SOURCE schematic.for:825 */
/*<       yr=yc-dy >*/
    yr = yc - dy;
/*     Now do the text insertion */
/* SOURCE schematic.for:828 */
/*<       write(scmunit,'(A,/,A)')'TEXT','A' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A,/,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("TEXT"), (ftnlen)4);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("A"), (ftnlen)1);
    e_wsfe();
/* SOURCE schematic.for:829 */
/*<       write(line,'(F13.2,'','',F13.2)')xl,yl >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&xl, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:830 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:833 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:834 */
/*<       write(line,'(F13.2,'','',F13.2)')xr,yr >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&xr, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(doublereal));
    e_wsfi();
/* SOURCE schematic.for:835 */
/*<       callstrip_all_blanks(line,slen) >*/
    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:838 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, slen);
    e_wsfe();
/* SOURCE schematic.for:840 */
/*<       write(scmunit,'(A5)')dnnlabel >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A5)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, dnnlabel, (ftnlen)5);
    e_wsfe();
/* SOURCE schematic.for:843 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:844 */
/*<       end >*/
} /* draw_lpr_graphic__ */




/* SOURCE schematic.for:848 */
/*<       subroutinedo_lprs(stdout,scmunit,nex,exnodt,emc) >*/
/* Subroutine */ int feq_gen_do_lprs_d_(integer *stdout, integer *scmunit, integer *
	nex, integer *feq_storage_exnodt, integer *feq_storage_emc)
{
    /* Initialized data */

    static integer null = -2147483647;

    /* Format strings */
    static char fmt_52[] = "(\002;\002,\002 LPR with free nodes: \002,a5,\
\002, \002,a5)";

    /* System generated locals */
    char feq_gen_ch_d_1[5];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    char dnnlabel[5];
    integer feq_gen_node_knt_d_;
    char upnlabel[5];
    extern /* Subroutine */ int feq_gen_draw_lpr_graphic_d_(integer *, integer *, 
	    doublereal *, doublereal *, char *, ftnlen);
    doublereal x[2], y[2];
    integer dnn, upn, code;
    doublereal dnnx, dnny;
    integer ipnt;
    doublereal upnx, upny;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer ientry, dnnflag, upnflag;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_52, 0 };


/*     Do level-pool reservoirs in a schematic */
/* SOURCE schematic.for:853 */
/*<       implicitnone >*/
/* INCLUDE schematic.for:854 */
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
/* SOURCE schematic.for:855 */
/*<       integernex,stdout,exnodt(9,nex),emc(mremc),scmunit >*/
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
/* INCLUDE schematic.for:874 */
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
/*     Called program units */
/* SOURCE schematic.for:878 */
/*<       charactergetusn*5 >*/
/* SOURCE schematic.for:879 */
/*<       externalgetusn,strip_all_blanks,find_perpendicular,find_line_coef >*/
/*     Local */
/* SOURCE schematic.for:883 */
/*<       integercode,ientry,ipnt,upn,dnn,null,upnflag,dnnflag,node_knt >*/
/* SOURCE schematic.for:886 */
/*<       real*8upnx,upny,dnnx,dnny,x(2),y(2) >*/
/* SOURCE schematic.for:888 */
/*<       characterupnlabel*5,dnnlabel*5 >*/
/*     **************************FORMATS********************************* */
/* SOURCE schematic.for:891 */
/*<       datanull/-2147483647/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE schematic.for:894 */
/*<    52 format(';',' LPR with free nodes: ',a5,', ',a5) >*/
/* L52: */
/* *********************************************************************** */
/*     General approach: */
/*     1. Scan EMC for LPR's */
/*     2. For each LPR extract the ups and dns node numbers */
/*     2.1 Check in EXNODT, in rows 6 and 7 to see if (x,y) is known for */
/*         this LPR.   If not don't draw it! */
/*     Start loop seaching for LPR's.  CODE=7 */
/* SOURCE schematic.for:904 */
/*<       ientry=0 >*/
    ientry = 0;
/* SOURCE schematic.for:906 */
/*<   100 continue >*/
L100:
/* SOURCE schematic.for:907 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE schematic.for:908 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE schematic.for:909 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE schematic.for:910 */
/*<       if(code.eq.7)then >*/
    if (code == 7) {
/*         Get the ups and dns node numbers */
/* SOURCE schematic.for:912 */
/*<       upn=emc(ipnt+5) >*/
	upn = emc[ipnt + 5];
/* SOURCE schematic.for:913 */
/*<       dnn=emc(ipnt+1) >*/
	dnn = emc[ipnt + 1];
/* SOURCE schematic.for:914 */
/*<       upnlabel=getusn(upn) >*/
	getusn_(feq_gen_ch_d_1, (ftnlen)5, &upn);
	s_copy(upnlabel, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE schematic.for:915 */
/*<       dnnlabel=getusn(dnn) >*/
	getusn_(feq_gen_ch_d_1, (ftnlen)5, &dnn);
	s_copy(dnnlabel, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/*         Clear the location flags */
/* SOURCE schematic.for:918 */
/*<       upnflag=0 >*/
	upnflag = 0;
/* SOURCE schematic.for:919 */
/*<       dnnflag=0 >*/
	dnnflag = 0;
/*         Check to see if these nodes have a location given in EXNODT */
/* SOURCE schematic.for:922 */
/*<       if(exnodt(6,upn).gt.null)then >*/
	if (exnodt[upn * 9 + 6] > null) {
/* SOURCE schematic.for:923 */
/*<       upnflag=1 >*/
	    upnflag = 1;
/* SOURCE schematic.for:924 */
/*<       upnx=dble(exnodt(6,upn))/100.d0 >*/
	    upnx = (doublereal) exnodt[upn * 9 + 6] / 100.;
/* SOURCE schematic.for:925 */
/*<       upny=dble(exnodt(7,upn))/100.d0 >*/
	    upny = (doublereal) exnodt[upn * 9 + 7] / 100.;
/* SOURCE schematic.for:926 */
/*<       endif >*/
	}
/* SOURCE schematic.for:927 */
/*<       if(exnodt(6,dnn).gt.null)then >*/
	if (exnodt[dnn * 9 + 6] > null) {
/* SOURCE schematic.for:928 */
/*<       dnnflag=1 >*/
	    dnnflag = 1;
/* SOURCE schematic.for:929 */
/*<       dnnx=dble(exnodt(6,dnn))/100.d0 >*/
	    dnnx = (doublereal) exnodt[dnn * 9 + 6] / 100.;
/* SOURCE schematic.for:930 */
/*<       dnny=dble(exnodt(7,dnn))/100.d0 >*/
	    dnny = (doublereal) exnodt[dnn * 9 + 7] / 100.;
/* SOURCE schematic.for:931 */
/*<       endif >*/
	}
/* SOURCE schematic.for:934 */
/*<       if(upnflag.eq.1.and.dnnflag.eq.1)then >*/
	if (upnflag == 1 && dnnflag == 1) {
/*           We can draw the LPR. */
/* SOURCE schematic.for:937 */
/*<       x(1)=upnx >*/
	    x[0] = upnx;
/* SOURCE schematic.for:938 */
/*<       y(1)=upny >*/
	    y[0] = upny;
/* SOURCE schematic.for:939 */
/*<       x(2)=dnnx >*/
	    x[1] = dnnx;
/* SOURCE schematic.for:940 */
/*<       y(2)=dnny >*/
	    y[1] = dnny;
/* SOURCE schematic.for:941 */
/*<       node_knt=2 >*/
	    feq_gen_node_knt_d_ = 2;
/* SOURCE schematic.for:942 */
/*<       write(scmunit,52)upnlabel,dnnlabel >*/
	    feq_gen_io_d__132.ciunit = *scmunit;
	    s_wsfe(&feq_gen_io_d__132);
	    do_fio(&feq_gen_c_d_1, upnlabel, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, dnnlabel, (ftnlen)5);
	    e_wsfe();
/* SOURCE schematic.for:943 */
/*<       calldraw_lpr_graphic(scmunit,node_knt,x,y,dnnlabel) >*/
	    feq_gen_draw_lpr_graphic_d_(scmunit, &feq_gen_node_knt_d_, x, y, dnnlabel, (ftnlen)
		    5);
/* SOURCE schematic.for:944 */
/*<       endif >*/
	}
/* SOURCE schematic.for:945 */
/*<       endif >*/
    }
/* SOURCE schematic.for:947 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE schematic.for:949 */
/*<       goto100 >*/
	goto L100;
/* SOURCE schematic.for:950 */
/*<       endif >*/
    }
/* SOURCE schematic.for:952 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:953 */
/*<       end >*/
} /* do_lprs__ */




/* SOURCE schematic.for:957 */
/*<       subroutineconnect_distant_items(stdout,scmunit,nex,exnodt,emc) >*/
/* Subroutine */ int feq_gen_connect_distant_items_d_(integer *stdout, integer *
	scmunit, integer *nex, integer *feq_storage_exnodt, integer *feq_storage_emc)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;
    static integer null = -2147483647;

    /* Format strings */
    static char fmt_52[] = "(\002;\002,\002 Connection between nodes: \002,a\
5,\002, \002,a5,\002 D=\002,f10.1)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[5];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    char dnnlabel[5], upnlabel[5];
    extern /* Subroutine */ int feq_gen_strip_all_blanks_d_(char *, integer *, ftnlen);
    integer feq_gen_i_d_, j, n;
    doublereal xi, yi, xj, yj;
    integer knt, code, node, loci, locj, adrs;
    char line[80];
    integer slen;
    doublereal dist;
    integer ipnt, nodei, nodej, classi, classj;
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer ientry;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_52, 0 };


/*     Connect items that are distant from one another so that */
/*     the flow of water between them is evident.  Only applies */
/*     to nodes on reservoirs and branches.  Nodes on dummy */
/*     branches are excluded. */
/* SOURCE schematic.for:966 */
/*<       implicitnone >*/
/* INCLUDE schematic.for:967 */
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
/* SOURCE schematic.for:968 */
/*<       integernex,stdout,exnodt(9,nex),emc(mremc),scmunit >*/
/* INCLUDE schematic.for:973 */
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
/* INCLUDE schematic.for:974 */
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
/*     Called program units */
/* SOURCE schematic.for:978 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE schematic.for:979 */
/*<       character*5getusn >*/
/* SOURCE schematic.for:980 */
/*<       externalget_dp_from_ft,strip_all_blanks,getusn >*/
/*     Local */
/* SOURCE schematic.for:985 */
/*<        >*/
/* SOURCE schematic.for:989 */
/*<       real*8dist,xi,yi,xj,yj,dnull >*/
/* SOURCE schematic.for:991 */
/*<       characterline*80,upnlabel*5,dnnlabel*5 >*/
/*     ***************************FORMATS******************************** */
/* SOURCE schematic.for:993 */
/*<       datadnull/-33d6/,null/-2147483647/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE schematic.for:995 */
/*<    52 format(';',' Connection between nodes: ',a5,', ',a5,' D=',f10.1) >*/
/* L52: */
/* *********************************************************************** */
/*     Scan over all CODE 2 entries and check all unique pairs of nodes */
/*     in the junction */
/*     Select the layer */
/* SOURCE schematic.for:1001 */
/*<       write(scmunit,'(A)')'LAYER','MAKE','DOT_CNCT' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("LAYER"), (ftnlen)5);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("MAKE"), (ftnlen)4);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("DOT_CNCT"), (ftnlen)8);
    e_wsfe();
/* SOURCE schematic.for:1002 */
/*<       write(scmunit,'( )') >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
    s_wsfe(&feq_gen_ci_d_1);
    e_wsfe();
/* SOURCE schematic.for:1004 */
/*<       ientry=0 >*/
    ientry = 0;
/* SOURCE schematic.for:1006 */
/*<   100 continue >*/
L100:
/* SOURCE schematic.for:1007 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE schematic.for:1008 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE schematic.for:1009 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE schematic.for:1010 */
/*<       if(code.eq.2)then >*/
    if (code == 2) {
/* SOURCE schematic.for:1011 */
/*<       n=emc(ipnt+1) >*/
	n = emc[ipnt + 1];
/*         If there is only one upstream node in a junction */
/*         and all other nodes are downstream, then we connect */
/*         that upstream node to any other node that is far enough */
/*         away.  If there is more than one upstream node, then */
/*         check to see if there is only a single downstream node in */
/*         the junction. */
/* SOURCE schematic.for:1018 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE schematic.for:1020 */
/*<       do150i=1,n >*/
	feq_gen_i_d_1 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*           Search for an upstream node in the junction. */
/* SOURCE schematic.for:1022 */
/*<       node=emc(ipnt+1+i) >*/
	    node = emc[ipnt + 1 + feq_gen_i_d_];
/* SOURCE schematic.for:1023 */
/*<       if(exnodt(1,node).lt.0)then >*/
	    if (exnodt[node * 9 + 1] < 0) {
/*             We have one. */
/* SOURCE schematic.for:1025 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE schematic.for:1026 */
/*<       nodei=node >*/
		nodei = node;
/* SOURCE schematic.for:1027 */
/*<       endif >*/
	    }
/* SOURCE schematic.for:1028 */
/*<   150 continue >*/
/* L150: */
	}
/* SOURCE schematic.for:1030 */
/*<       if(knt.gt.1)then >*/
	if (knt > 1) {
/*           See if there is a single downstream node */
/* SOURCE schematic.for:1032 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE schematic.for:1033 */
/*<       do160i=1,n >*/
	    feq_gen_i_d_1 = n;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*             Search for a downstream node in the junction. */
/* SOURCE schematic.for:1035 */
/*<       node=emc(ipnt+1+i) >*/
		node = emc[ipnt + 1 + feq_gen_i_d_];
/* SOURCE schematic.for:1036 */
/*<       if(exnodt(1,node).gt.0)then >*/
		if (exnodt[node * 9 + 1] > 0) {
/*               We have one. */
/* SOURCE schematic.for:1038 */
/*<       knt=knt+1 >*/
		    ++knt;
/* SOURCE schematic.for:1039 */
/*<       nodei=node >*/
		    nodei = node;
/* SOURCE schematic.for:1040 */
/*<       endif >*/
		}
/* SOURCE schematic.for:1041 */
/*<   160 continue >*/
/* L160: */
	    }
/* SOURCE schematic.for:1042 */
/*<       endif >*/
	}
/* SOURCE schematic.for:1043 */
/*<       if(knt.eq.1)then >*/
	if (knt == 1) {
/*           Draw connections only if there is exactly one downstream or */
/*           one upstream node. */
/*           Get the location for this node. */
/* SOURCE schematic.for:1047 */
/*<       classi=exnodt(3,nodei) >*/
	    classi = exnodt[nodei * 9 + 3];
/* SOURCE schematic.for:1048 */
/*<       if(classi.gt.0)then >*/
	    if (classi > 0) {
/*             We have a branch.  Get the (x,y) from the */
/*             cross-section-function table */
/* SOURCE schematic.for:1051 */
/*<       adrs=exnodt(4,nodei) >*/
		adrs = exnodt[nodei * 9 + 4];
/* SOURCE schematic.for:1052 */
/*<       xi=get_dp_from_ft(adrs+8) >*/
		feq_gen_i_d_1 = adrs + 8;
		xi = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE schematic.for:1053 */
/*<       yi=get_dp_from_ft(adrs+10) >*/
		feq_gen_i_d_1 = adrs + 10;
		yi = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_1);
/* SOURCE schematic.for:1054 */
/*<       if(xi.gt.dnull)then >*/
		if (xi > dnull) {
/*               Location is known. */
/* SOURCE schematic.for:1056 */
/*<       loci=1 >*/
		    loci = 1;
/* SOURCE schematic.for:1057 */
/*<       else >*/
		} else {
/* SOURCE schematic.for:1058 */
/*<       loci=0 >*/
		    loci = 0;
/* SOURCE schematic.for:1059 */
/*<       endif >*/
		}
/* SOURCE schematic.for:1060 */
/*<       else >*/
	    } else {
/*             We have a free node.  Check to see if its location */
/*             is known. */
/* SOURCE schematic.for:1063 */
/*<       if(exnodt(6,nodei).gt.null)then >*/
		if (exnodt[nodei * 9 + 6] > null) {
/*               Location is known */
/* SOURCE schematic.for:1065 */
/*<       xi=dble(exnodt(6,nodei))/100.d0 >*/
		    xi = (doublereal) exnodt[nodei * 9 + 6] / 100.;
/* SOURCE schematic.for:1066 */
/*<       yi=dble(exnodt(7,nodei))/100.d0 >*/
		    yi = (doublereal) exnodt[nodei * 9 + 7] / 100.;
/* SOURCE schematic.for:1067 */
/*<       loci=1 >*/
		    loci = 1;
/* SOURCE schematic.for:1068 */
/*<       else >*/
		} else {
/* SOURCE schematic.for:1069 */
/*<       loci=0 >*/
		    loci = 0;
/* SOURCE schematic.for:1070 */
/*<       endif >*/
		}
/* SOURCE schematic.for:1071 */
/*<       endif >*/
	    }
/* SOURCE schematic.for:1074 */
/*<       do190j=1,n >*/
	    feq_gen_i_d_1 = n;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE schematic.for:1075 */
/*<       nodej=emc(ipnt+1+j) >*/
		nodej = emc[ipnt + 1 + j];
/* SOURCE schematic.for:1076 */
/*<       if(nodej.ne.nodei)then >*/
		if (nodej != nodei) {
/* SOURCE schematic.for:1077 */
/*<       classj=exnodt(3,nodej) >*/
		    classj = exnodt[nodej * 9 + 3];
/* SOURCE schematic.for:1078 */
/*<       if(classj.gt.0)then >*/
		    if (classj > 0) {
/*                 We have a branch.  Get the (x,y) from the */
/*                 cross-section-function table */
/* SOURCE schematic.for:1081 */
/*<       adrs=exnodt(4,nodej) >*/
			adrs = exnodt[nodej * 9 + 4];
/* SOURCE schematic.for:1082 */
/*<       xj=get_dp_from_ft(adrs+8) >*/
			feq_gen_i_d_2 = adrs + 8;
			xj = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE schematic.for:1083 */
/*<       yj=get_dp_from_ft(adrs+10) >*/
			feq_gen_i_d_2 = adrs + 10;
			yj = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE schematic.for:1084 */
/*<       if(xj.gt.dnull)then >*/
			if (xj > dnull) {
/*                   Location is known. */
/* SOURCE schematic.for:1086 */
/*<       locj=1 >*/
			    locj = 1;
/* SOURCE schematic.for:1087 */
/*<       else >*/
			} else {
/* SOURCE schematic.for:1088 */
/*<       locj=0 >*/
			    locj = 0;
/* SOURCE schematic.for:1089 */
/*<       endif >*/
			}
/* SOURCE schematic.for:1090 */
/*<       else >*/
		    } else {
/*                 We have a free node.  Check to see if its location */
/*                 is known. */
/* SOURCE schematic.for:1093 */
/*<       if(exnodt(6,nodej).gt.null)then >*/
			if (exnodt[nodej * 9 + 6] > null) {
/*                   Location is known */
/* SOURCE schematic.for:1095 */
/*<       xj=dble(exnodt(6,nodej))/100.d0 >*/
			    xj = (doublereal) exnodt[nodej * 9 + 6] / 100.;
/* SOURCE schematic.for:1096 */
/*<       yj=dble(exnodt(7,nodej))/100.d0 >*/
			    yj = (doublereal) exnodt[nodej * 9 + 7] / 100.;
/* SOURCE schematic.for:1097 */
/*<       locj=1 >*/
			    locj = 1;
/* SOURCE schematic.for:1098 */
/*<       else >*/
			} else {
/* SOURCE schematic.for:1099 */
/*<       locj=0 >*/
			    locj = 0;
/* SOURCE schematic.for:1100 */
/*<       endif >*/
			}
/* SOURCE schematic.for:1101 */
/*<       endif >*/
		    }
/* SOURCE schematic.for:1102 */
/*<       if(loci.eq.1.and.locj.eq.1)then >*/
		    if (loci == 1 && locj == 1) {
/*                 We have locations for both nodes.  Compute */
/*                 distance between them. */
/* SOURCE schematic.for:1105 */
/*<       dist=sqrt((xi-xj)**2+(yi-yj)**2) >*/
/* Computing 2nd power */
			feq_gen_d_d_1 = xi - xj;
/* Computing 2nd power */
			feq_gen_d_d_2 = yi - yj;
			dist = sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE schematic.for:1106 */
/*<       if(dist.gt.150.d0)then >*/
			if (dist > 150.) {
/*                   We have a case for drawing a dotted line to */
/*                   indicate a connection. */
/* SOURCE schematic.for:1109 */
/*<       upnlabel=getusn(nodei) >*/
			    getusn_(feq_gen_ch_d_1, (ftnlen)5, &nodei);
			    s_copy(upnlabel, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE schematic.for:1110 */
/*<       dnnlabel=getusn(nodej) >*/
			    getusn_(feq_gen_ch_d_1, (ftnlen)5, &nodej);
			    s_copy(dnnlabel, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE schematic.for:1111 */
/*<       write(scmunit,52)upnlabel,dnnlabel,dist >*/
			    feq_gen_io_d__157.ciunit = *scmunit;
			    s_wsfe(&feq_gen_io_d__157);
			    do_fio(&feq_gen_c_d_1, upnlabel, (ftnlen)5);
			    do_fio(&feq_gen_c_d_1, dnnlabel, (ftnlen)5);
			    do_fio(&feq_gen_c_d_1, (char *)&dist, (ftnlen)sizeof(
				    doublereal));
			    e_wsfe();
/* SOURCE schematic.for:1113 */
/*<       write(scmunit,'(A)')'PLINE' >*/
			    feq_gen_ci_d_1.cierr = 0;
			    feq_gen_ci_d_1.ciunit = *scmunit;
			    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
			    s_wsfe(&feq_gen_ci_d_1);
			    do_fio(&feq_gen_c_d_1, const_cast<char*>("PLINE"), (ftnlen)5);
			    e_wsfe();
/* SOURCE schematic.for:1114 */
/*<       write(line,'(F13.2,'','',F13.2)')xi,yi >*/
			    feq_gen_ici_d_1.icierr = 0;
			    feq_gen_ici_d_1.icirnum = 1;
			    feq_gen_ici_d_1.icirlen = 80;
			    feq_gen_ici_d_1.iciunit = line;
			    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
			    s_wsfi(&feq_gen_ici_d_1);
			    do_fio(&feq_gen_c_d_1, (char *)&xi, (ftnlen)sizeof(
				    doublereal));
			    do_fio(&feq_gen_c_d_1, (char *)&yi, (ftnlen)sizeof(
				    doublereal));
			    e_wsfi();
/* SOURCE schematic.for:1115 */
/*<       callstrip_all_blanks(line,slen) >*/
			    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:1118 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
			    feq_gen_ci_d_1.cierr = 0;
			    feq_gen_ci_d_1.ciunit = *scmunit;
			    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
			    s_wsfe(&feq_gen_ci_d_1);
			    do_fio(&feq_gen_c_d_1, line, slen);
			    e_wsfe();
/* SOURCE schematic.for:1120 */
/*<       write(line,'(F13.2,'','',F13.2)')xj,yj >*/
			    feq_gen_ici_d_1.icierr = 0;
			    feq_gen_ici_d_1.icirnum = 1;
			    feq_gen_ici_d_1.icirlen = 80;
			    feq_gen_ici_d_1.iciunit = line;
			    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
			    s_wsfi(&feq_gen_ici_d_1);
			    do_fio(&feq_gen_c_d_1, (char *)&xj, (ftnlen)sizeof(
				    doublereal));
			    do_fio(&feq_gen_c_d_1, (char *)&yj, (ftnlen)sizeof(
				    doublereal));
			    e_wsfi();
/* SOURCE schematic.for:1121 */
/*<       callstrip_all_blanks(line,slen) >*/
			    feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:1124 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
			    feq_gen_ci_d_1.cierr = 0;
			    feq_gen_ci_d_1.ciunit = *scmunit;
			    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
			    s_wsfe(&feq_gen_ci_d_1);
			    do_fio(&feq_gen_c_d_1, line, slen);
			    e_wsfe();
/* SOURCE schematic.for:1126 */
/*<       write(scmunit,'( )') >*/
			    feq_gen_ci_d_1.cierr = 0;
			    feq_gen_ci_d_1.ciunit = *scmunit;
			    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
			    s_wsfe(&feq_gen_ci_d_1);
			    e_wsfe();
/* SOURCE schematic.for:1127 */
/*<       endif >*/
			}
/* SOURCE schematic.for:1128 */
/*<       endif >*/
		    }
/* SOURCE schematic.for:1129 */
/*<       endif >*/
		}
/* SOURCE schematic.for:1131 */
/*<   190 continue >*/
/* L190: */
	    }
/* SOURCE schematic.for:1132 */
/*<       endif >*/
	}
/* SOURCE schematic.for:1133 */
/*<       endif >*/
    }
/* SOURCE schematic.for:1134 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE schematic.for:1136 */
/*<       goto100 >*/
	goto L100;
/* SOURCE schematic.for:1137 */
/*<       endif >*/
    }
/* SOURCE schematic.for:1139 */
/*<   300 continue >*/
/* L300: */
/* SOURCE schematic.for:1140 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:1141 */
/*<       end >*/
} /* connect_distant_items__ */




/* SOURCE schematic.for:1147 */
/*<       subroutineoutput_schematic_script(stdout,nbra,nex,brpt,exnodt,emc) >*/
/* Subroutine */ int feq_gen_output_schematic_script_d_(integer *stdout, integer *nbra,
	 integer *nex, integer *feq_storage_brpt, integer *feq_storage_exnodt, integer *feq_storage_emc)
{
    /* Initialized data */

    static doublereal feq_gen_half_l_d_ = 25.;
    static doublereal lf = 2.;
    static doublereal hf = 5.;

    /* Format strings */
    static char fmt_50[] = "(\002; Branch number is:\002,i6)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_open(olist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(), s_wsfi(icilist *), e_wsfi();
    double sqrt(doublereal);

    /* Local variables */
    integer feq_gen_node_knt_d_;
    extern integer feq_gen_get_unit_d_(integer *);
    extern /* Subroutine */ int feq_gen_strip_all_blanks_d_(char *, integer *, ftnlen);
    doublereal a, b, feq_gen_c_d_;
    integer feq_gen_i_d_, j;
    doublereal m, x[8400], y[8400];
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *), 
	    feq_gen_do_dummy_branches_d_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *);
    doublereal bl, ap, bp, cp, dx, dy, xe, ye, xs, ys;
    extern /* Subroutine */ int feq_gen_clear_home_d_();
    doublereal feq_gen_minor_axis_d_;
    extern /* Subroutine */ int feq_gen_find_perpendicular_d_(doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    doublereal ddx, ddy;
    integer usb;
    extern /* Subroutine */ int feq_gen_draw_branch_graphic_d_(integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *), 
	    feq_gen_maybe_add_ghome_out_d_(char *, ftnlen);
    char bran[4];
    integer mode;
    char line[80];
    integer adrs, slen;
    doublereal xmid, ymid, hltmp, shift;
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen);
    doublereal factor;
    extern /* Subroutine */ int feq_gen_find_line_coef_d_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), feq_gen_connect_distant_items_d_(integer *, integer *, 
	    integer *, integer *, integer *);
    extern integer getusb_(integer *);
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);
    integer dnsnode;
    extern /* Subroutine */ int feq_gen_do_lprs_d_(integer *, integer *, integer *, 
	    integer *, integer *);
    integer upsnode, scmunit;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__176 = { 0, 0, 0, fmt_50, 0 };


/*     Create an IntelliCAD 2000 script to create a draft schematic */
/*     of the model. */
/* SOURCE schematic.for:1153 */
/*<       implicitnone >*/
/* INCLUDE schematic.for:1154 */
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
/* SOURCE schematic.for:1155 */
/*<       integernbra,nex,stdout,brpt(8,nbra),exnodt(9,nex),emc(mremc) >*/
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
/*     Called program units */
/* SOURCE schematic.for:1171 */
/*<       integerget_unit,getusb >*/
/* SOURCE schematic.for:1172 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE schematic.for:1173 */
/*<        >*/
/* INCLUDE schematic.for:1176 */
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
/* INCLUDE schematic.for:1177 */
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
/* SOURCE schematic.for:1181 */
/*<       integeradrs,i,j,upsnode,dnsnode,node_knt,scmunit,slen,usb,mode >*/
/* SOURCE schematic.for:1184 */
/*<        >*/
/* SOURCE schematic.for:1187 */
/*<       characterline*80,bran*4 >*/
/*     ****************************FORMATS******************************* */
/* SOURCE schematic.for:1189 */
/*<       datahalf_l/25.d0/,lf/2.d0/,hf/5.d0/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE schematic.for:1191 */
/*<    50 format('; Branch number is:',i6) >*/
/* L50: */
/* *********************************************************************** */
/*     Make sure the local home-directory name is cleared.  Otherwise */
/*     we might end up putting schematic.scr in the home directory for */
/*     the function-table files! */
/* SOURCE schematic.for:1196 */
/*<       callclear_home() >*/
    feq_gen_clear_home_d_();
/*     Try scaling to get better results for less detailed schematics */
/* SOURCE schematic.for:1199 */
/*<       factor=1.5d0 >*/
    factor = 1.5;
/* SOURCE schematic.for:1200 */
/*<       half_l=factor*half_l >*/
    feq_gen_half_l_d_ = factor * feq_gen_half_l_d_;
/* SOURCE schematic.for:1201 */
/*<       lf=factor*lf >*/
    lf = factor * lf;
/* SOURCE schematic.for:1202 */
/*<       hf=factor*hf >*/
    hf = factor * hf;
/* SOURCE schematic.for:1204 */
/*<       scmunit=get_unit(0) >*/
    scmunit = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE schematic.for:1205 */
/*<       if(ghome_out.ne.' ')then >*/
    if (s_cmp(homec_1.feq_gen_ghome_out_d_, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1) != 0) {
/*       A global home directory name exists.  Put the script file there. */
/* SOURCE schematic.for:1207 */
/*<       line='/schematic.scr' >*/
	s_copy(line, const_cast<char*>("/schematic.scr"), (ftnlen)80, (ftnlen)14);
/* SOURCE schematic.for:1208 */
/*<       callmaybe_add_ghome_out(line) >*/
	feq_gen_maybe_add_ghome_out_d_(line, (ftnlen)80);
/* SOURCE schematic.for:1210 */
/*<       else >*/
    } else {
/*       No global home directory exists.  Put script in the current directory. */
/* SOURCE schematic.for:1212 */
/*<       line='schematic.scr' >*/
	s_copy(line, const_cast<char*>("schematic.scr"), (ftnlen)80, (ftnlen)13);
/* SOURCE schematic.for:1213 */
/*<       endif >*/
    }
/* SOURCE schematic.for:1215 */
/*<       callos_file_style(line) >*/
    feq_gen_os_file_style_d_(line, (ftnlen)80);
/* SOURCE schematic.for:1217 */
/*<       open(unit=scmunit,file=line,status='UNKNOWN') >*/
    feq_gen_o_d_1.oerr = 0;
    feq_gen_o_d_1.ounit = scmunit;
    feq_gen_o_d_1.ofnmlen = 80;
    feq_gen_o_d_1.ofnm = line;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    f_open(&feq_gen_o_d_1);
/*     Set the line-type-scale */
/* SOURCE schematic.for:1220 */
/*<       write(scmunit,'(A)')'ltscale','500.0' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("ltscale"), (ftnlen)7);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("500.0"), (ftnlen)5);
    e_wsfe();
/*     Select the layer for branches */
/* SOURCE schematic.for:1223 */
/*<       write(scmunit,'(A)')'LAYER','MAKE','BRANCHES' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("LAYER"), (ftnlen)5);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("MAKE"), (ftnlen)4);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("BRANCHES"), (ftnlen)8);
    e_wsfe();
/* SOURCE schematic.for:1224 */
/*<       write(scmunit,'( )') >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
    s_wsfe(&feq_gen_ci_d_1);
    e_wsfe();
/*     Scan all branches and output the trace of each */
/* SOURCE schematic.for:1228 */
/*<       do500i=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE schematic.for:1229 */
/*<       usb=getusb(i) >*/
	usb = getusb_(&feq_gen_i_d_);
/* SOURCE schematic.for:1230 */
/*<       write(bran,'(I4)')usb >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 4;
	feq_gen_ici_d_1.iciunit = bran;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I4)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&usb, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE schematic.for:1231 */
/*<       upsnode=brpt(3,i) >*/
	upsnode = brpt[(feq_gen_i_d_ << 3) + 3];
/* SOURCE schematic.for:1232 */
/*<       dnsnode=brpt(4,i) >*/
	dnsnode = brpt[(feq_gen_i_d_ << 3) + 4];
/* SOURCE schematic.for:1233 */
/*<       node_knt=0 >*/
	feq_gen_node_knt_d_ = 0;
/* SOURCE schematic.for:1234 */
/*<       do100j=upsnode,dnsnode >*/
	feq_gen_i_d_2 = dnsnode;
	for (j = upsnode; j <= feq_gen_i_d_2; ++j) {
/* SOURCE schematic.for:1235 */
/*<       node_knt=node_knt+1 >*/
	    ++feq_gen_node_knt_d_;
/* SOURCE schematic.for:1236 */
/*<       adrs=nsec(j) >*/
	    adrs = bnothr_1.nsec[j - 1];
/* SOURCE schematic.for:1237 */
/*<       x(node_knt)=get_dp_from_ft(adrs+8) >*/
	    feq_gen_i_d_3 = adrs + 8;
	    x[feq_gen_node_knt_d_ - 1] = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_3);
/* SOURCE schematic.for:1238 */
/*<       y(node_knt)=get_dp_from_ft(adrs+10) >*/
	    feq_gen_i_d_3 = adrs + 10;
	    y[feq_gen_node_knt_d_ - 1] = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_3);
/* SOURCE schematic.for:1239 */
/*<   100 continue >*/
/* L100: */
	}
/*       Output a comment giving the external branch number */
/* SOURCE schematic.for:1242 */
/*<       write(scmunit,50)usb >*/
	feq_gen_io_d__176.ciunit = scmunit;
	s_wsfe(&feq_gen_io_d__176);
	do_fio(&feq_gen_c_d_1, (char *)&usb, (ftnlen)sizeof(integer));
	e_wsfe();
/*       MODE not now used-maybe later */
/* SOURCE schematic.for:1245 */
/*<       mode=2 >*/
	mode = 2;
/* SOURCE schematic.for:1246 */
/*<       calldraw_branch_graphic(mode,scmunit,node_knt,x,y,half_l) >*/
	feq_gen_draw_branch_graphic_d_(&mode, &scmunit, &feq_gen_node_knt_d_, x, y, &feq_gen_half_l_d_);
/*       Now label the branch.  Use these rules as a start: */
/*       1. Place branch number in a circle of radius 1.2 * */
/*          the tick length if the tick length is >= the */
/*          straightline distance from start to end of branch. */
/*       2. Place label on line perpendicular to the strightline */
/*          from one end to the other.  Put center of circle at */
/*          twice its diameter from the line. */
/*       Find coef. for line connecting end points of branch */
/* SOURCE schematic.for:1260 */
/*<       callfind_line_coef(x(1),y(1),x(node_knt),y(node_knt),a,b,c) >*/
	feq_gen_find_line_coef_d_(x, y, &x[feq_gen_node_knt_d_ - 1], &y[feq_gen_node_knt_d_ - 1], &a, &b,
		 &feq_gen_c_d_);
/*       Compute midpoint of this line segment */
/* SOURCE schematic.for:1264 */
/*<       xmid=0.5d0*(x(1)+x(node_knt)) >*/
	xmid = (x[0] + x[feq_gen_node_knt_d_ - 1]) * .5;
/* SOURCE schematic.for:1265 */
/*<       ymid=0.5d0*(y(1)+y(node_knt)) >*/
	ymid = (y[0] + y[feq_gen_node_knt_d_ - 1]) * .5;
/*       Find coef. for the line perpendicular to the branch line segment */
/* SOURCE schematic.for:1268 */
/*<       callfind_perpendicular(xmid,ymid,a,b,c,ap,bp,cp) >*/
	feq_gen_find_perpendicular_d_(&xmid, &ymid, &a, &b, &feq_gen_c_d_, &ap, &bp, &cp);
/* SOURCE schematic.for:1271 */
/*<       m=-ap/bp >*/
	m = -ap / bp;
/*       Reduce scale if branch is too short. */
/* SOURCE schematic.for:1274 */
/*<       bl=sqrt((x(1)-x(node_knt))**2+(y(1)-y(node_knt))**2) >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = x[0] - x[feq_gen_node_knt_d_ - 1];
/* Computing 2nd power */
	feq_gen_d_d_2 = y[0] - y[feq_gen_node_knt_d_ - 1];
	bl = sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE schematic.for:1276 */
/*<       if(bl.lt.2.0*half_l)then >*/
	if (bl < feq_gen_half_l_d_ * (float)2.) {
/* SOURCE schematic.for:1277 */
/*<       hltmp=0.5*bl >*/
	    hltmp = bl * (float).5;
/* SOURCE schematic.for:1278 */
/*<       else >*/
	} else {
/* SOURCE schematic.for:1279 */
/*<       hltmp=half_l >*/
	    hltmp = feq_gen_half_l_d_;
/* SOURCE schematic.for:1280 */
/*<       endif >*/
	}
/* SOURCE schematic.for:1282 */
/*<       dx=hltmp/sqrt(1.d0+m**2) >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = m;
	dx = hltmp / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + 1.);
/* SOURCE schematic.for:1283 */
/*<       dy=hltmp/sqrt(1.d0+1.d0/m**2) >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = m;
	dy = hltmp / sqrt(1. / (feq_gen_d_d_1 * feq_gen_d_d_1) + 1.);
/* SOURCE schematic.for:1285 */
/*<       if(m.gt.0.d0)then >*/
	if (m > 0.) {
/* SOURCE schematic.for:1286 */
/*<       xs=xmid+lf*dx >*/
	    xs = xmid + lf * dx;
/* SOURCE schematic.for:1287 */
/*<       ys=ymid+lf*dy >*/
	    ys = ymid + lf * dy;
/* SOURCE schematic.for:1288 */
/*<       xe=xmid+hf*dx >*/
	    xe = xmid + hf * dx;
/* SOURCE schematic.for:1289 */
/*<       ye=ymid+hf*dy >*/
	    ye = ymid + hf * dy;
/* SOURCE schematic.for:1290 */
/*<       else >*/
	} else {
/* SOURCE schematic.for:1291 */
/*<       xs=xmid+lf*dx >*/
	    xs = xmid + lf * dx;
/* SOURCE schematic.for:1292 */
/*<       ys=ymid-lf*dy >*/
	    ys = ymid - lf * dy;
/* SOURCE schematic.for:1293 */
/*<       xe=xmid+hf*dx >*/
	    xe = xmid + hf * dx;
/* SOURCE schematic.for:1294 */
/*<       ye=ymid-hf*dy >*/
	    ye = ymid - hf * dy;
/* SOURCE schematic.for:1295 */
/*<       endif >*/
	}
/*       Now do the text insertion */
/* SOURCE schematic.for:1298 */
/*<       write(scmunit,'(A,/A)')'TEXT','A' >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A,/A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("TEXT"), (ftnlen)4);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("A"), (ftnlen)1);
	e_wsfe();
/* SOURCE schematic.for:1299 */
/*<       write(line,'(F13.2,'','',F13.2)')xs,ys >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&xs, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&ys, (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE schematic.for:1300 */
/*<       callstrip_all_blanks(line,slen) >*/
	feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:1303 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, slen);
	e_wsfe();
/* SOURCE schematic.for:1304 */
/*<       write(line,'(F13.2,'','',F13.2)')xe,ye >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&xe, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&ye, (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE schematic.for:1305 */
/*<       callstrip_all_blanks(line,slen) >*/
	feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:1308 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, slen);
	e_wsfe();
/* SOURCE schematic.for:1310 */
/*<       write(scmunit,'(A4)')bran >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A4)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, bran, (ftnlen)4);
	e_wsfe();
/*       Do an ellipse around the text. */
/*       Shift the midpoint to center around branch label */
/* SOURCE schematic.for:1314 */
/*<       shift=0.18*(hf-lf)*hltmp >*/
	shift = (hf - lf) * (float).18 * hltmp;
/* SOURCE schematic.for:1315 */
/*<       ddx=shift/sqrt(1.d0/m**2+1.d0) >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = m;
	ddx = shift / sqrt(1. / (feq_gen_d_d_1 * feq_gen_d_d_1) + 1.);
/* SOURCE schematic.for:1316 */
/*<       ddy=shift/sqrt(m**2+1.d0) >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = m;
	ddy = shift / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + 1.);
/* SOURCE schematic.for:1318 */
/*<       if(m.gt.0.d0)then >*/
	if (m > 0.) {
/* SOURCE schematic.for:1319 */
/*<       ddx=-ddx >*/
	    ddx = -ddx;
/* SOURCE schematic.for:1320 */
/*<       endif >*/
	}
/* SOURCE schematic.for:1322 */
/*<       xmid=xmid+ddx >*/
	xmid += ddx;
/* SOURCE schematic.for:1323 */
/*<       ymid=ymid+ddy >*/
	ymid += ddy;
/* SOURCE schematic.for:1325 */
/*<       if(m.gt.0.d0)then >*/
	if (m > 0.) {
/* SOURCE schematic.for:1326 */
/*<       xs=xmid+(lf-1.)*dx >*/
	    xs = xmid + (lf - (float)1.) * dx;
/* SOURCE schematic.for:1327 */
/*<       ys=ymid+(lf-1.)*dy >*/
	    ys = ymid + (lf - (float)1.) * dy;
/* SOURCE schematic.for:1328 */
/*<       xe=xmid+(hf+1.)*dx >*/
	    xe = xmid + (hf + (float)1.) * dx;
/* SOURCE schematic.for:1329 */
/*<       ye=ymid+(hf+1.)*dy >*/
	    ye = ymid + (hf + (float)1.) * dy;
/* SOURCE schematic.for:1330 */
/*<       else >*/
	} else {
/* SOURCE schematic.for:1331 */
/*<       xs=xmid+(lf-1.)*dx >*/
	    xs = xmid + (lf - (float)1.) * dx;
/* SOURCE schematic.for:1332 */
/*<       ys=ymid-(lf-1.)*dy >*/
	    ys = ymid - (lf - (float)1.) * dy;
/* SOURCE schematic.for:1333 */
/*<       xe=xmid+(hf+1.)*dx >*/
	    xe = xmid + (hf + (float)1.) * dx;
/* SOURCE schematic.for:1334 */
/*<       ye=ymid-(hf+1.)*dy >*/
	    ye = ymid - (hf + (float)1.) * dy;
/* SOURCE schematic.for:1335 */
/*<       endif >*/
	}
/* SOURCE schematic.for:1337 */
/*<       minor_axis=factor*hltmp >*/
	feq_gen_minor_axis_d_ = factor * hltmp;
/* SOURCE schematic.for:1339 */
/*<       write(scmunit,'(A)')'ELLIPSE' >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>("ELLIPSE"), (ftnlen)7);
	e_wsfe();
/* SOURCE schematic.for:1340 */
/*<       write(line,'(F13.2,'','',F13.2)')xs,ys >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&xs, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&ys, (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE schematic.for:1341 */
/*<       callstrip_all_blanks(line,slen) >*/
	feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:1344 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, slen);
	e_wsfe();
/* SOURCE schematic.for:1345 */
/*<       write(line,'(F13.2,'','',F13.2)')xe,ye >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F13.2,',',F13.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&xe, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&ye, (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE schematic.for:1346 */
/*<       callstrip_all_blanks(line,slen) >*/
	feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:1349 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, slen);
	e_wsfe();
/* SOURCE schematic.for:1350 */
/*<       write(line,'(F10.2)')minor_axis >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.2)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_minor_axis_d_, (ftnlen)sizeof(doublereal));
	e_wsfi();
/* SOURCE schematic.for:1351 */
/*<       callstrip_all_blanks(line,slen) >*/
	feq_gen_strip_all_blanks_d_(line, &slen, (ftnlen)80);
/* SOURCE schematic.for:1354 */
/*<       write(scmunit,'(A)')line(1:slen) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = scmunit;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, line, slen);
	e_wsfe();
/* SOURCE schematic.for:1356 */
/*<   500 continue >*/
/* L500: */
    }
/*     Select the layer for Dummy branches */
/* SOURCE schematic.for:1360 */
/*<       write(scmunit,'(A)')'LAYER','MAKE','DUMBR',' ' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("LAYER"), (ftnlen)5);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("MAKE"), (ftnlen)4);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("DUMBR"), (ftnlen)5);
    do_fio(&feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsfe();
/*     Now do the dummy branches */
/* SOURCE schematic.for:1363 */
/*<        >*/
    feq_gen_do_dummy_branches_d_(stdout, &scmunit, nbra, nex, &brpt[9], &exnodt[10], &
	    emc[1], &feq_gen_half_l_d_);
/*     Select the layer for LPR's */
/* SOURCE schematic.for:1368 */
/*<       write(scmunit,'(A)')'LAYER','MAKE','LPRS' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("LAYER"), (ftnlen)5);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("MAKE"), (ftnlen)4);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("LPRS"), (ftnlen)4);
    e_wsfe();
/* SOURCE schematic.for:1369 */
/*<       write(scmunit,'( )') >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = scmunit;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("( )");
    s_wsfe(&feq_gen_ci_d_1);
    e_wsfe();
/* SOURCE schematic.for:1371 */
/*<       calldo_lprs(stdout,scmunit,nex,exnodt,emc) >*/
    feq_gen_do_lprs_d_(stdout, &scmunit, nex, &exnodt[10], &emc[1]);
/*     Draw dotted lines to connect items that are more than */
/*     about 100 feet apart. */
/* SOURCE schematic.for:1377 */
/*<       callconnect_distant_items(stdout,scmunit,nex,exnodt,emc) >*/
    feq_gen_connect_distant_items_d_(stdout, &scmunit, nex, &exnodt[10], &emc[1]);
/* SOURCE schematic.for:1379 */
/*<       callfree_unit(stdout,scmunit) >*/
    feq_gen_free_unit_d_(stdout, &scmunit);
/* SOURCE schematic.for:1380 */
/*<       return >*/
    return 0;
/* SOURCE schematic.for:1381 */
/*<       end >*/
} /* output_schematic_script__ */

#ifdef __cplusplus
	}
#endif
