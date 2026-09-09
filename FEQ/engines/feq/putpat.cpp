/* putpat.f -- translated by f2c (version 20240504).
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

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;

/* SOURCE putpat.for:2 */
/*<       subroutineputpat(stdout,neq,cmat,nex,exnodt,nbra,brpt) >*/
/* Subroutine */ int putpat_(integer *stdout, integer *neq, char *feq_storage_cmat, 
	integer *nex, integer *feq_storage_exnodt, integer *nbra, integer *feq_storage_brpt, ftnlen 
	cmat_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 EQN\002,1013a1)";
    static char fmt_52[] = "(i4,1013a1)";
    static char fmt_54[] = "(4x,1013a1)";
    static char fmt_56[] = "(\002 BRA\002,1013a1)";
    static char fmt_58[] = "(\002 NOD\002,1013a1)";
    static char fmt_60[] = "(\0020 PATTERN OF THE COEFFICIENT MATRIX\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), e_wsfe(), s_wsfi(icilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    integer feq_gen_i_d_, j, k, je, jl, jr, js;
    char chr3[3];
    integer bran;
    char line1[1*1013], line2[1*1013], line3[1*1013], line4[1*1013], line5[1*
	    1013], line6[1*1013], line7[1*1013], line8[1*1013], line9[1*1013];
    integer nflag, numnd;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__1 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__2 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__3 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__24 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__26 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_52, 0 };


/*     PRINT THE MATRIX PATTERN FOR CHECKING. LIMITED TO 268 EQUATIONS */

/* SOURCE putpat.for:7 */
/*<       integerneq,stdout,nex,nbra >*/
/* SOURCE putpat.for:9 */
/*<       integerbrpt(8,nbra),exnodt(9,nex) >*/
/* SOURCE putpat.for:11 */
/*<       character*1cmat(1013,1013) >*/
/*     LOCAL */
/* SOURCE putpat.for:15 */
/*<        >*/
/* SOURCE putpat.for:19 */
/*<       character*3chr3 >*/
/* SOURCE putpat.for:21 */
/*<       integernflag,numnd,jl,jr,bran,i,j,k,strip >*/
/* SOURCE putpat.for:23 */
/*<       parameter(strip=250) >*/
/*     ********************************FORMATS*************************** */
/* SOURCE putpat.for:26 */
/*<    50 format(' EQN',1013a1) >*/
/* SOURCE putpat.for:27 */
/*<    52 format(i4,1013a1) >*/
/* SOURCE putpat.for:28 */
/*<    54 format(4x,1013a1) >*/
/* SOURCE putpat.for:29 */
/*<    56 format(' BRA',1013a1) >*/
/* SOURCE putpat.for:30 */
/*<    58 format(' NOD',1013a1) >*/
/* SOURCE putpat.for:31 */
/*<    60 format('0 PATTERN OF THE COEFFICIENT MATRIX') >*/
/* *********************************************************************** */
/* SOURCE putpat.for:34 */
/*<       write(stdout,*)' ' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> cmat(feq_storage_cmat, 1014);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
    feq_gen_io_d__1.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__1);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE putpat.for:35 */
/*<       write(stdout,60) >*/
    feq_gen_io_d__2.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__2);
    e_wsfe();
/* SOURCE putpat.for:36 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__3.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__3);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/*     WRITE HEADINGS GIVING THE EXTENT OF VARIBLES INVOLVED IN */
/*     EACH BRANCH.  ALLOW UP TO TWO DIGIT BRANCH NUMBERS.  PLACE */
/*     THE NUMBER AT THE END OF THE  VARIABLE RANGE FOR THE BRANCH. */
/*     IF THE DIRECTION OF VARIABLE ASSIGNMENT IS REVERSED GIVE */
/*     THE BRANCH NUMBER AS NEGATIVE. */
/* SOURCE putpat.for:43 */
/*<       do800i=1,neq >*/
    feq_gen_i_d_1 = *neq;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE putpat.for:44 */
/*<       line1(i)=' ' >*/
	*(unsigned char *)&line1[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:45 */
/*<       line2(i)=' ' >*/
	*(unsigned char *)&line2[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:46 */
/*<       line3(i)=' ' >*/
	*(unsigned char *)&line3[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:47 */
/*<       line4(i)=' ' >*/
	*(unsigned char *)&line4[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:48 */
/*<       line5(i)=' ' >*/
	*(unsigned char *)&line5[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:49 */
/*<       line6(i)=' ' >*/
	*(unsigned char *)&line6[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:50 */
/*<       line7(i)=' ' >*/
	*(unsigned char *)&line7[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:51 */
/*<       line8(i)=' ' >*/
	*(unsigned char *)&line8[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:52 */
/*<       line9(i)=' ' >*/
	*(unsigned char *)&line9[feq_gen_i_d_ - 1] = ' ';
/* SOURCE putpat.for:53 */
/*<   800 continue >*/
/* L800: */
    }
/* SOURCE putpat.for:55 */
/*<       do700i=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       GET NUMBER OF NODES ON THIS BRANCH. */
/* SOURCE putpat.for:58 */
/*<       numnd=brpt(4,i)-brpt(3,i)+1 >*/
	numnd = brpt[(feq_gen_i_d_ << 3) + 4] - brpt[(feq_gen_i_d_ << 3) + 3] + 1;
/*       GET THE FIRST VARIBLE NUMBER ON THE BRANCH. */
/* SOURCE putpat.for:61 */
/*<       jl=brpt(7,i) >*/
	jl = brpt[(feq_gen_i_d_ << 3) + 7];
/*       SET THE SIGN FOR THE BRANCH */
/* SOURCE putpat.for:63 */
/*<       if(jl.lt.0)then >*/
	if (jl < 0) {
/* SOURCE putpat.for:64 */
/*<       nflag=1 >*/
	    nflag = 1;
/* SOURCE putpat.for:65 */
/*<       jl=-jl >*/
	    jl = -jl;
/* SOURCE putpat.for:66 */
/*<       else >*/
	} else {
/* SOURCE putpat.for:67 */
/*<       nflag=0 >*/
	    nflag = 0;
/* SOURCE putpat.for:68 */
/*<       endif >*/
	}
/*       GET THE LAST VARIABLE NUMBER ON THE BRANCH */
/* SOURCE putpat.for:72 */
/*<       jr=jl+2*numnd-1 >*/
	jr = jl + (numnd << 1) - 1;
/*       CREATE THE UNDERBAR */
/* SOURCE putpat.for:75 */
/*<       do610j=jl,jr-1 >*/
	feq_gen_i_d_2 = jr - 1;
	for (j = jl; j <= feq_gen_i_d_2; ++j) {
/* SOURCE putpat.for:76 */
/*<       line2(j)='-' >*/
	    *(unsigned char *)&line2[j - 1] = '-';
/* SOURCE putpat.for:77 */
/*<   610 continue >*/
/* L610: */
	}
/* SOURCE putpat.for:78 */
/*<       line2(jr)='+' >*/
	*(unsigned char *)&line2[jr - 1] = '+';
/*       CREATE THE BRANCH LABEL */
/* SOURCE putpat.for:82 */
/*<       if(nflag.eq.0)then >*/
	if (nflag == 0) {
/* SOURCE putpat.for:83 */
/*<       bran=i >*/
	    bran = feq_gen_i_d_;
/* SOURCE putpat.for:84 */
/*<       else >*/
	} else {
/* SOURCE putpat.for:85 */
/*<       bran=-i >*/
	    bran = -feq_gen_i_d_;
/* SOURCE putpat.for:86 */
/*<       endif >*/
	}
/* SOURCE putpat.for:87 */
/*<       write(chr3,'(I3)')bran >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 3;
	feq_gen_ici_d_1.iciunit = chr3;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I3)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&bran, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE putpat.for:88 */
/*<       line1(jr)=chr3(3:3) >*/
	*(unsigned char *)&line1[jr - 1] = *(unsigned char *)&chr3[2];
/* SOURCE putpat.for:89 */
/*<       line1(jr-1)=chr3(2:2) >*/
	*(unsigned char *)&line1[jr - 2] = *(unsigned char *)&chr3[1];
/* SOURCE putpat.for:90 */
/*<       line1(jr-2)=chr3(1:1) >*/
	*(unsigned char *)&line1[jr - 3] = *(unsigned char *)chr3;
/* SOURCE putpat.for:91 */
/*<   700 continue >*/
/* L700: */
    }
/* SOURCE putpat.for:93 */
/*<       do750i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       GET VARIBLE NUMBER */
/* SOURCE putpat.for:95 */
/*<       jl=exnodt(5,i) >*/
	jl = exnodt[feq_gen_i_d_ * 9 + 5];
/*       MAKE THE UNDERBAR */
/* SOURCE putpat.for:97 */
/*<       line6(jl)='-' >*/
	*(unsigned char *)&line6[jl - 1] = '-';
/* SOURCE putpat.for:98 */
/*<       line6(jl+1)='+' >*/
	*(unsigned char *)&line6[jl] = '+';
/*       STACK THE NUMBER AT THE END */
/* SOURCE putpat.for:102 */
/*<       write(chr3,'(I3)')i >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 3;
	feq_gen_ici_d_1.iciunit = chr3;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I3)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE putpat.for:103 */
/*<       line3(jl+1)=chr3(1:1) >*/
	*(unsigned char *)&line3[jl] = *(unsigned char *)chr3;
/* SOURCE putpat.for:104 */
/*<       line4(jl+1)=chr3(2:2) >*/
	*(unsigned char *)&line4[jl] = *(unsigned char *)&chr3[1];
/* SOURCE putpat.for:105 */
/*<       line5(jl+1)=chr3(3:3) >*/
	*(unsigned char *)&line5[jl] = *(unsigned char *)&chr3[2];
/* SOURCE putpat.for:106 */
/*<   750 continue >*/
/* L750: */
    }
/*     MARK THE VERTICAL PARTS OF THE PROFILE */
/* SOURCE putpat.for:110 */
/*<       do500i=1,neq >*/
    feq_gen_i_d_1 = *neq;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE putpat.for:111 */
/*<       do400j=i+1,neq >*/
	feq_gen_i_d_2 = *neq;
	for (j = feq_gen_i_d_ + 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE putpat.for:112 */
/*<       if(cmat(i,j).eq.'X'.or.cmat(i,j).eq.'?')then >*/
	    if (*(unsigned char *)&cmat[feq_gen_i_d_ + j * 1013] == 'X' || *(unsigned 
		    char *)&cmat[feq_gen_i_d_ + j * 1013] == '?') {
/* SOURCE putpat.for:113 */
/*<       do350k=i+1,j-1 >*/
		feq_gen_i_d_3 = j - 1;
		for (k = feq_gen_i_d_ + 1; k <= feq_gen_i_d_3; ++k) {
/* SOURCE putpat.for:114 */
/*<       if(cmat(k,j).eq.'.')then >*/
		    if (*(unsigned char *)&cmat[k + j * 1013] == '.') {
/* SOURCE putpat.for:115 */
/*<       cmat(k,j)='0' >*/
			*(unsigned char *)&cmat[k + j * 1013] = '0';
/* SOURCE putpat.for:116 */
/*<       endif >*/
		    }
/* SOURCE putpat.for:117 */
/*<   350 continue >*/
/* L350: */
		}
/* SOURCE putpat.for:118 */
/*<       endif >*/
	    }
/* SOURCE putpat.for:119 */
/*<   400 continue >*/
/* L400: */
	}
/* SOURCE putpat.for:120 */
/*<   500 continue >*/
/* L500: */
    }
/*     MARK THE DIAGONAL */
/* SOURCE putpat.for:123 */
/*<       do300i=1,neq >*/
    feq_gen_i_d_1 = *neq;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE putpat.for:124 */
/*<       if(cmat(i,i).eq.'0'.or.cmat(i,i).eq.'.')then >*/
	if (*(unsigned char *)&cmat[feq_gen_i_d_ + feq_gen_i_d_ * 1013] == '0' || *(unsigned 
		char *)&cmat[feq_gen_i_d_ + feq_gen_i_d_ * 1013] == '.') {
/* SOURCE putpat.for:125 */
/*<       cmat(i,i)='*' >*/
	    *(unsigned char *)&cmat[feq_gen_i_d_ + feq_gen_i_d_ * 1013] = '*';
/* SOURCE putpat.for:126 */
/*<       elseif(cmat(i,i).ne.'?')then >*/
	} else if (*(unsigned char *)&cmat[feq_gen_i_d_ + feq_gen_i_d_ * 1013] != '?') {
/* SOURCE putpat.for:127 */
/*<       cmat(i,i)='N' >*/
	    *(unsigned char *)&cmat[feq_gen_i_d_ + feq_gen_i_d_ * 1013] = 'N';
/* SOURCE putpat.for:128 */
/*<       endif >*/
	}
/* SOURCE putpat.for:129 */
/*<   300 continue >*/
/* L300: */
    }
/*     MAKE THE HEADINGS */
/* SOURCE putpat.for:133 */
/*<       do100i=1,neq >*/
    feq_gen_i_d_1 = *neq;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE putpat.for:134 */
/*<       write(chr3,'(I3)')i >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 3;
	feq_gen_ici_d_1.iciunit = chr3;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I3)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE putpat.for:135 */
/*<       line7(i)=chr3(1:1) >*/
	*(unsigned char *)&line7[feq_gen_i_d_ - 1] = *(unsigned char *)chr3;
/* SOURCE putpat.for:136 */
/*<       line8(i)=chr3(2:2) >*/
	*(unsigned char *)&line8[feq_gen_i_d_ - 1] = *(unsigned char *)&chr3[1];
/* SOURCE putpat.for:137 */
/*<       line9(i)=chr3(3:3) >*/
	*(unsigned char *)&line9[feq_gen_i_d_ - 1] = *(unsigned char *)&chr3[2];
/* SOURCE putpat.for:138 */
/*<   100 continue >*/
/* L100: */
    }
/*     OUTPUT IN WIDTHS THAT CAN BE VIEWED WITH BRIEF */
/* SOURCE putpat.for:143 */
/*<       js=1 >*/
    js = 1;
/* SOURCE putpat.for:144 */
/*<       je=strip >*/
    je = 250;
/* SOURCE putpat.for:145 */
/*<       if(je.gt.neq)je=neq >*/
    if (je > *neq) {
	je = *neq;
    }
/* SOURCE putpat.for:147 */
/*<  9000 continue >*/
L9000:
/*       OUTPUT THE HEADINGS */
/* SOURCE putpat.for:149 */
/*<       write(stdout,56)(line1(j),j=js,je) >*/
    feq_gen_io_d__24.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__24);
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, line1 + (j - 1), (ftnlen)1);
    }
    e_wsfe();
/* SOURCE putpat.for:150 */
/*<       write(stdout,54)(line2(j),j=js,je) >*/
    feq_gen_io_d__25.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__25);
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, line2 + (j - 1), (ftnlen)1);
    }
    e_wsfe();
/* SOURCE putpat.for:151 */
/*<       write(stdout,58)(line3(j),j=js,je) >*/
    feq_gen_io_d__26.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__26);
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, line3 + (j - 1), (ftnlen)1);
    }
    e_wsfe();
/* SOURCE putpat.for:152 */
/*<       write(stdout,54)(line4(j),j=js,je) >*/
    feq_gen_io_d__27.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__27);
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, line4 + (j - 1), (ftnlen)1);
    }
    e_wsfe();
/* SOURCE putpat.for:153 */
/*<       write(stdout,54)(line5(j),j=js,je) >*/
    feq_gen_io_d__28.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__28);
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, line5 + (j - 1), (ftnlen)1);
    }
    e_wsfe();
/* SOURCE putpat.for:154 */
/*<       write(stdout,54)(line6(j),j=js,je) >*/
    feq_gen_io_d__29.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__29);
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, line6 + (j - 1), (ftnlen)1);
    }
    e_wsfe();
/* SOURCE putpat.for:155 */
/*<       if(neq.ge.100)then >*/
    if (*neq >= 100) {
/* SOURCE putpat.for:156 */
/*<       write(stdout,54)(line7(j),j=js,je) >*/
	feq_gen_io_d__30.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__30);
	feq_gen_i_d_1 = je;
	for (j = js; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, line7 + (j - 1), (ftnlen)1);
	}
	e_wsfe();
/* SOURCE putpat.for:157 */
/*<       endif >*/
    }
/* SOURCE putpat.for:158 */
/*<       write(stdout,54)(line8(j),j=js,je) >*/
    feq_gen_io_d__31.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__31);
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, line8 + (j - 1), (ftnlen)1);
    }
    e_wsfe();
/* SOURCE putpat.for:159 */
/*<       write(stdout,50)(line9(j),j=js,je) >*/
    feq_gen_io_d__32.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__32);
    feq_gen_i_d_1 = je;
    for (j = js; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, line9 + (j - 1), (ftnlen)1);
    }
    e_wsfe();
/*       OUTPUT THE MATRIX */
/* SOURCE putpat.for:162 */
/*<       do200i=1,neq >*/
    feq_gen_i_d_1 = *neq;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE putpat.for:163 */
/*<       write(stdout,52)i,(cmat(i,j),j=js,je) >*/
	feq_gen_io_d__33.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__33);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, cmat + (feq_gen_i_d_ + j * 1013), (ftnlen)1);
	}
	e_wsfe();
/* SOURCE putpat.for:164 */
/*<   200 continue >*/
/* L200: */
    }
/*       UPDATE THE COLUMN POINTERS */
/* SOURCE putpat.for:166 */
/*<       if(je.eq.neq)return >*/
    if (je == *neq) {
	return 0;
    }
/* SOURCE putpat.for:167 */
/*<       js=je+1 >*/
    js = je + 1;
/* SOURCE putpat.for:168 */
/*<       je=je+strip >*/
    je += 250;
/* SOURCE putpat.for:169 */
/*<       if(je.gt.neq)je=neq >*/
    if (je > *neq) {
	je = *neq;
    }
/* SOURCE putpat.for:170 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE putpat.for:171 */
/*<       end >*/
} /* putpat_ */

#ifdef __cplusplus
	}
#endif
