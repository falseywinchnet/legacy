/* home_name.f -- translated by f2c (version 20240504).
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

/* Table of constant values */

static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_2 = 2;

/*     Program units relating to processing of home names */



/* SOURCE home_name.for:6 */
/*<       subroutinemaybe_add_ext(name) >*/
/* Subroutine */ int feq_gen_maybe_add_ext_d_(char *feq_gen_name_d_, ftnlen name_len)
{
    /* System generated locals */
    address feq_gen_a_d_1[3], feq_gen_a_d_2[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2[3], feq_gen_i_d_3[2];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    char ext[128];
    integer iend;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     if stdext is non-blank, add it to the end of name as */
/*     an additional extension. The standard extension is */
/*     already stored with a leading period. */
/* SOURCE home_name.for:12 */
/*<       implicitnone >*/
/* SOURCE home_name.for:14 */
/*<       character*(*)name >*/
/* INCLUDE home_name.for:16 */
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
/* SOURCE home_name.for:19 */
/*<       integeri,iend >*/
/* SOURCE home_name.for:20 */
/*<       character*128ext >*/
/* *********************************************************************** */
/* SOURCE home_name.for:6 */
/*<       integer feq_len_trim >*/
/* SOURCE home_name.for:6 */
/*<       external feq_len_trim >*/
/* SOURCE home_name.for:23 */
/*<       if(name/=' ')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), name_len, (ftnlen)1) != 0) {
/* SOURCE home_name.for:24 */
/*<       if(stdext/=' ')then >*/
	if (s_cmp(homec_1.stdext, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1) != 0) {
/*         Cut the last extension from name, including the period, */
/*         then add the standard extension from the master-output file, */
/*         and then add in the original extension */
/* SOURCE home_name.for:28 */
/*<       iend=feq_len_trim(name) >*/
	    iend = feq_gen_feq_len_trim_d_(feq_gen_name_d_, name_len);
/* SOURCE home_name.for:29 */
/*<       doi=iend,1,-1 >*/
	    for (feq_gen_i_d_ = iend; feq_gen_i_d_ >= 1; --feq_gen_i_d_) {
/* SOURCE home_name.for:30 */
/*<       if(name(i:i)=='.')then >*/
		if (*(unsigned char *)&feq_gen_name_d_[feq_gen_i_d_ - 1] == '.') {
/* SOURCE home_name.for:31 */
/*<       goto99000 >*/
		    goto L99000;
/* SOURCE home_name.for:32 */
/*<       endif >*/
		}
/* SOURCE home_name.for:33 */
/*<       enddo >*/
	    }
/* SOURCE home_name.for:33 */
/*< 99000 continue >*/
L99000:
/* SOURCE home_name.for:34 */
/*<       if(i>1)then >*/
	    if (feq_gen_i_d_ > 1) {
/*           There was a period found during the reverse search. Thus name */
/*           had an extension */
/* SOURCE home_name.for:37 */
/*<       ext=name(i:iend) >*/
		s_copy(ext, feq_gen_name_d_ + (feq_gen_i_d_ - 1), (ftnlen)128, iend - (feq_gen_i_d_ - 1))
			;
/*           In at least one case, special output file, it is possible that */
/* `          the information file already has the master-output file extension */
/*           added.  This may well happen in the future.  Thus, take action here */
/*           to prevent such duplication.  If the master-output file extension */
/*           is already present, we should then find it at the end */
/*           of name(1:i-1). */
/* SOURCE home_name.for:44 */
/*<       iend=feq_len_trim(stdext) >*/
		iend = feq_gen_feq_len_trim_d_(homec_1.stdext, (ftnlen)128);
/* SOURCE home_name.for:45 */
/*<       if(name(i-1-iend+1:i-1)/=stdext)then >*/
		feq_gen_i_d_1 = feq_gen_i_d_ - 1 - iend;
		if (s_cmp(feq_gen_name_d_ + feq_gen_i_d_1, homec_1.stdext, feq_gen_i_d_ - 1 - feq_gen_i_d_1, (
			ftnlen)128) != 0) {
/* SOURCE home_name.for:46 */
/*<        >*/
/* Writing concatenation */
		    feq_gen_i_d_2[0] = feq_gen_i_d_ - 1, feq_gen_a_d_1[0] = feq_gen_name_d_;
		    feq_gen_i_d_2[1] = feq_gen_feq_len_trim_d_(homec_1.stdext, (ftnlen)128), 
			    feq_gen_a_d_1[1] = homec_1.stdext;
		    feq_gen_i_d_2[2] = feq_gen_feq_len_trim_d_(ext, (ftnlen)128), feq_gen_a_d_1[2] = ext;
		    s_cat(feq_gen_name_d_, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_3, name_len);
/* SOURCE home_name.for:47 */
/*<       else >*/
		} else {
/* SOURCE home_name.for:48 */
/*<       name=name(1:i-1)//ext(1:feq_len_trim(ext)) >*/
/* Writing concatenation */
		    feq_gen_i_d_3[0] = feq_gen_i_d_ - 1, feq_gen_a_d_2[0] = feq_gen_name_d_;
		    feq_gen_i_d_3[1] = feq_gen_feq_len_trim_d_(ext, (ftnlen)128), feq_gen_a_d_2[1] = ext;
		    s_cat(feq_gen_name_d_, feq_gen_a_d_2, feq_gen_i_d_3, &feq_gen_c_d_2, name_len);
/* SOURCE home_name.for:49 */
/*<       endif >*/
		}
/* SOURCE home_name.for:50 */
/*<       else >*/
	    } else {
/*           No period was found.  We exclude an initial period in a name.  Such */
/*           a period does not denote an extension but is part of the file name. */
/* SOURCE home_name.for:53 */
/*<       name=name(1:feq_len_trim(name))//stdext(1:feq_len_trim(stdext)) >*/
/* Writing concatenation */
		feq_gen_i_d_3[0] = feq_gen_feq_len_trim_d_(feq_gen_name_d_, name_len), feq_gen_a_d_2[0] = feq_gen_name_d_;
		feq_gen_i_d_3[1] = feq_gen_feq_len_trim_d_(homec_1.stdext, (ftnlen)128), feq_gen_a_d_2[1]
			 = homec_1.stdext;
		s_cat(feq_gen_name_d_, feq_gen_a_d_2, feq_gen_i_d_3, &feq_gen_c_d_2, name_len);
/* SOURCE home_name.for:54 */
/*<       endif >*/
	    }
/* SOURCE home_name.for:55 */
/*<       endif >*/
	}
/* SOURCE home_name.for:56 */
/*<       endif >*/
    }
/* SOURCE home_name.for:57 */
/*<       return >*/
    return 0;
/* SOURCE home_name.for:58 */
/*<       end >*/
} /* maybe_add_ext__ */




/* SOURCE home_name.for:62 */
/*<       subroutinemaybe_add_home(name) >*/
/* Subroutine */ int feq_gen_maybe_add_home_d_(char *feq_gen_name_d_, ftnlen name_len)
{
    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1[2];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);

    /* Local variables */
    integer n;
    char feq_gen_temp_line_d_[256];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

/*     Add home to front of file names that start with */
/*     a / or \ but only if HOME or GHOME are not blank. */
/*     Also set local home to global home if local home is blank. */
/* SOURCE home_name.for:69 */
/*<       implicitnone >*/
/* SOURCE home_name.for:71 */
/*<       character*(*)name >*/
/* INCLUDE home_name.for:73 */
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
/*     Called program units */
/* SOURCE home_name.for:76 */
/*<       externalstrip_l_blanks >*/
/*     Local */
/* SOURCE home_name.for:78 */
/*<       integern >*/
/* SOURCE home_name.for:79 */
/*<       character*256temp_line >*/
/* *********************************************************************** */
/* SOURCE home_name.for:62 */
/*<       integer feq_len_trim >*/
/* SOURCE home_name.for:62 */
/*<       external feq_len_trim >*/
/* SOURCE home_name.for:81 */
/*<       if(name.ne.' ')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), name_len, (ftnlen)1) != 0) {
/* SOURCE home_name.for:82 */
/*<       callstrip_l_blanks(name) >*/
	feq_gen_strip_l_blanks_d_(feq_gen_name_d_, name_len);
/* SOURCE home_name.for:85 */
/*<       if(name(1:1).eq.'/'.or.name(1:1).eq.'\')then >*/
	if (*(unsigned char *)feq_gen_name_d_ == '/' || *(unsigned char *)feq_gen_name_d_ == 
		'\\') {
/*         Check for global home if HOME is blank */
/* SOURCE home_name.for:87 */
/*<       if(home.eq.' ')then >*/
	    if (s_cmp(homec_1.home, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1) == 0) {
/* SOURCE home_name.for:88 */
/*<       if(ghome.ne.' ')then >*/
		if (s_cmp(homec_1.ghome, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1) != 0) {
/* SOURCE home_name.for:89 */
/*<       home=ghome >*/
		    s_copy(homec_1.home, homec_1.ghome, (ftnlen)128, (ftnlen)
			    128);
/* SOURCE home_name.for:90 */
/*<       endif >*/
		}
/* SOURCE home_name.for:91 */
/*<       endif >*/
	    }
/* SOURCE home_name.for:92 */
/*<       if(home.ne.' ')then >*/
	    if (s_cmp(homec_1.home, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1) != 0) {
/* SOURCE home_name.for:93 */
/*<       n=feq_len_trim(home) >*/
		n = feq_gen_feq_len_trim_d_(homec_1.home, (ftnlen)128);
/*           Check to see if a home name already exists at */
/*           the start of the file name.  It is invalid to have */
/*           a home name appear twice.  It is also assumed that the */
/*           style will be identical. */
/* SOURCE home_name.for:98 */
/*<       if(home(1:n)/=name(1:n))then >*/
		if (s_cmp(homec_1.home, feq_gen_name_d_, n, n) != 0) {
/* SOURCE home_name.for:99 */
/*<       temp_line=home(1:n)//name >*/
/* Writing concatenation */
		    feq_gen_i_d_1[0] = n, feq_gen_a_d_1[0] = homec_1.home;
		    feq_gen_i_d_1[1] = name_len, feq_gen_a_d_1[1] = feq_gen_name_d_;
		    s_cat(feq_gen_temp_line_d_, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_2, (ftnlen)256);
/* SOURCE home_name.for:100 */
/*<       name=temp_line >*/
		    s_copy(feq_gen_name_d_, feq_gen_temp_line_d_, name_len, (ftnlen)256);
/* SOURCE home_name.for:101 */
/*<       endif >*/
		}
/* SOURCE home_name.for:102 */
/*<       else >*/
	    } else {
/* SOURCE home_name.for:106 */
/*<       name=name(2:) >*/
		s_copy(feq_gen_name_d_, feq_gen_name_d_ + 1, name_len, name_len - 1);
/* SOURCE home_name.for:107 */
/*<       endif >*/
	    }
/* SOURCE home_name.for:108 */
/*<       endif >*/
	}
/* SOURCE home_name.for:109 */
/*<       endif >*/
    }
/* SOURCE home_name.for:110 */
/*<       return >*/
    return 0;
/* SOURCE home_name.for:111 */
/*<       end >*/
} /* maybe_add_home__ */




/* SOURCE home_name.for:115 */
/*<       subroutinemaybe_add_ghome_out(name) >*/
/* Subroutine */ int feq_gen_maybe_add_ghome_out_d_(char *feq_gen_name_d_, ftnlen name_len)
{
    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1[2];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer n;
    char feq_gen_temp_line_d_[256];
    extern /* Subroutine */ int feq_gen_feq_adjustl_d_(char *, char *, ftnlen, ftnlen);
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Add output home name to front of file names that start with */
/*     a / or \ but only if GHOME_OUT is not blank. */
/* SOURCE home_name.for:121 */
/*<       implicitnone >*/
/* SOURCE home_name.for:123 */
/*<       character*(*)name >*/
/* INCLUDE home_name.for:125 */
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
/*     Called program units */
/*     Local */
/* SOURCE home_name.for:130 */
/*<       integern >*/
/* SOURCE home_name.for:131 */
/*<       character*256temp_line >*/
/* *********************************************************************** */
/* SOURCE home_name.for:115 */
/*<       integer feq_len_trim >*/
/* SOURCE home_name.for:115 */
/*<       external feq_len_trim >*/
/* SOURCE home_name.for:133 */
/*<       if(name.ne.' ')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), name_len, (ftnlen)1) != 0) {
/* SOURCE home_name.for:134 */
/*<       callfeq_adjustl(name,name) >*/
	feq_gen_feq_adjustl_d_(feq_gen_name_d_, feq_gen_name_d_, name_len, name_len);
/* SOURCE home_name.for:136 */
/*<       if(name(1:1).eq.'/'.or.name(1:1).eq.'\')then >*/
	if (*(unsigned char *)feq_gen_name_d_ == '/' || *(unsigned char *)feq_gen_name_d_ == 
		'\\') {
/* SOURCE home_name.for:137 */
/*<       if(ghome_out/=' ')then >*/
	    if (s_cmp(homec_1.feq_gen_ghome_out_d_, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1) != 0) 
		    {
/* SOURCE home_name.for:138 */
/*<       n=feq_len_trim(ghome_out) >*/
		n = feq_gen_feq_len_trim_d_(homec_1.feq_gen_ghome_out_d_, (ftnlen)128);
/*           Check to see if a home name already exists at */
/*           the start of the file name.  It is invalid to have */
/*           a home name appear twice.  It is also assumed that the */
/*           style will be identical. */
/* SOURCE home_name.for:143 */
/*<       if(ghome_out(1:n)/=name(1:n))then >*/
		if (s_cmp(homec_1.feq_gen_ghome_out_d_, feq_gen_name_d_, n, n) != 0) {
/* SOURCE home_name.for:144 */
/*<       temp_line=ghome_out(1:n)//name >*/
/* Writing concatenation */
		    feq_gen_i_d_1[0] = n, feq_gen_a_d_1[0] = homec_1.feq_gen_ghome_out_d_;
		    feq_gen_i_d_1[1] = name_len, feq_gen_a_d_1[1] = feq_gen_name_d_;
		    s_cat(feq_gen_temp_line_d_, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_2, (ftnlen)256);
/* SOURCE home_name.for:145 */
/*<       name=temp_line >*/
		    s_copy(feq_gen_name_d_, feq_gen_temp_line_d_, name_len, (ftnlen)256);
/* SOURCE home_name.for:146 */
/*<       endif >*/
		}
/* SOURCE home_name.for:147 */
/*<       else >*/
	    } else {
/* SOURCE home_name.for:150 */
/*<       name=name(2:) >*/
		s_copy(feq_gen_name_d_, feq_gen_name_d_ + 1, name_len, name_len - 1);
/* SOURCE home_name.for:151 */
/*<       endif >*/
	    }
/* SOURCE home_name.for:152 */
/*<       endif >*/
	}
/* SOURCE home_name.for:153 */
/*<       endif >*/
    }
/* SOURCE home_name.for:154 */
/*<       return >*/
    return 0;
/* SOURCE home_name.for:155 */
/*<       end >*/
} /* maybe_add_ghome_out__ */




/* SOURCE home_name.for:160 */
/*<       subroutineclear_home() >*/
/* Subroutine */ int feq_gen_clear_home_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Clear the Local HOME part of file names. */
/* SOURCE home_name.for:164 */
/*<       implicitnone >*/
/* INCLUDE home_name.for:166 */
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
/* *********************************************************************** */
/* SOURCE home_name.for:168 */
/*<       home=' ' >*/
    s_copy(homec_1.home, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1);
/* SOURCE home_name.for:169 */
/*<       return >*/
    return 0;
/* SOURCE home_name.for:170 */
/*<       end >*/
} /* clear_home__ */




/* SOURCE home_name.for:174 */
/*<       subroutineclear_ghome_out() >*/
/* Subroutine */ int feq_gen_clear_ghome_out_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Clear the global output home name */
/* SOURCE home_name.for:178 */
/*<       implicitnone >*/
/* INCLUDE home_name.for:180 */
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
/* *********************************************************************** */
/* SOURCE home_name.for:182 */
/*<       ghome_out=' ' >*/
    s_copy(homec_1.feq_gen_ghome_out_d_, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1);
/* SOURCE home_name.for:183 */
/*<       return >*/
    return 0;
/* SOURCE home_name.for:184 */
/*<       end >*/
} /* clear_ghome_out__ */




/* SOURCE home_name.for:188 */
/*<       subroutineclear_ext() >*/
/* Subroutine */ int feq_gen_clear_ext_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Clear the standard output extension */
/* SOURCE home_name.for:192 */
/*<       implicitnone >*/
/* INCLUDE home_name.for:194 */
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
/* *********************************************************************** */
/* SOURCE home_name.for:196 */
/*<       stdext=' ' >*/
    s_copy(homec_1.stdext, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1);
/* SOURCE home_name.for:197 */
/*<       return >*/
    return 0;
/* SOURCE home_name.for:198 */
/*<       end >*/
} /* clear_ext__ */




/* SOURCE home_name.for:202 */
/*<       subroutineset_home(lhome) >*/
/* Subroutine */ int feq_gen_set_home_d_(char *lhome, ftnlen lhome_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the Local HOME part of file names. */
/* SOURCE home_name.for:206 */
/*<       implicitnone >*/
/* SOURCE home_name.for:207 */
/*<       character*(*)lhome >*/
/* INCLUDE home_name.for:209 */
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
/* *********************************************************************** */
/* SOURCE home_name.for:211 */
/*<       home=lhome >*/
    s_copy(homec_1.home, lhome, (ftnlen)128, lhome_len);
/* SOURCE home_name.for:212 */
/*<       return >*/
    return 0;
/* SOURCE home_name.for:213 */
/*<       end >*/
} /* set_home__ */

#ifdef __cplusplus
	}
#endif
