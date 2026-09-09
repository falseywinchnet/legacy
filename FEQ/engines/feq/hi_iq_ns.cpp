/* hi_iq_ns.f -- translated by f2c (version 20240504).
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

/* COMMON hiiqnscmn_ is declared in common.hpp. */

#define hiiqnscmn_1 hiiqnscmn_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_100 = 100;

/*     Programs to implement the high iq newton solution */
/*     option in FEQ. */
/*     We will also be experimenting with shifting to lower case */
/*     for the fortran code. */
/*     25 Feb 2003 */
/*     As part of this system we must keep track of internal variable */
/*     numbers on an action list.  These are variables that appear in */
/*     the iteration log(s) in particular patterns that lead us to */
/*     take a partial-newton correction for these variables until */
/*     the problem pattern disappears.  Thus variables will be added */
/*     to the list when problems persist and will eventually be deleted */
/*     from the list when they appear to be over.   Most of the time */
/*     the list should be empty.  Only experimentation will tell if this */
/*     solves certain annoying problems with convergence. */
/*     We use what is called a doubly-linked list for the list of */
/*     variables on the action list.  The operations we need to */
/*     make are: */
/*     1. add a variable to the list and checking to make sure there is */
/*        room on the list.  We will always add at the end of the "top" of */
/*        list. */
/*     2. Scan through the action list from top to bottom making adjustments */
/*        to the partial-newton correction factors as we go.  There will be two */
/*        modes:  when convergence fails we will be making the correction factors */
/*        smaller by some factor until some lower limit is reached; when */
/*        convergence succeeds we will be increasing the correction factors by */
/*        a factor to make them larger.  When the factor exceeds 1.0, the */
/*        variable is removed from the list. */
/*     3. Remove a variable from the list. */
/*     TLhe following subroutines will do most of the work: */
/*     init_list -- initialize a doubley-linked list */
/*     add_to_list  -- adds a given internal variable number to the list */
/*     remove_from_list -- removes the variable at the known location */
/*                         in the list. */
/*     The above subroutines will be written for potential other applications */
/*     and are not specific to the hi_iq_ns processing */
/*     hi_iq_ns_success -- process the hi_iq_ns list when convergence is */
/*                         obtained */
/*     hi_iq_ns_fail -- process the hi_iq_ns list when convergence fails. */
/*     Note: a node on a doubly-linked list consistes of a back pointer, */
/*           the item being stored, and the forward pointer. */



/* SOURCE hi_iq_ns.for:55 */
/*<       subroutineinit_list(mrlist,avail_p,active_p,bp,items,fp) >*/
/* Subroutine */ int feq_gen_init_list_d_(integer *mrlist, integer *feq_gen_avail_p_d_, integer 
	*feq_gen_active_p_d_, integer *feq_storage_bp, integer *feq_storage_items, integer *feq_storage_fp)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;

/*     Initialize a doubly-linked list as outline above. */
/* SOURCE hi_iq_ns.for:60 */
/*<       implicitnone >*/
/* SOURCE hi_iq_ns.for:61 */
/*<       integermrlist,avail_p,active_p >*/
/* SOURCE hi_iq_ns.for:62 */
/*<       integerbp(mrlist),items(mrlist),fp(mrlist) >*/
/*     Local */
/* SOURCE hi_iq_ns.for:65 */
/*<       integeri >*/
/* *********************************************************************** */
/* SOURCE hi_iq_ns.for:68 */
/*<       do100i=1,mrlist >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> fp(feq_storage_fp, 1);

    feq::IndexedPointer<integer> items(feq_storage_items, 1);

    feq::IndexedPointer<integer> bp(feq_storage_bp, 1);

    /* Function Body */
    feq_gen_i_d_1 = *mrlist;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE hi_iq_ns.for:69 */
/*<       bp(i)=i-1 >*/
	bp[feq_gen_i_d_] = feq_gen_i_d_ - 1;
/* SOURCE hi_iq_ns.for:70 */
/*<       fp(i)=i+1 >*/
	fp[feq_gen_i_d_] = feq_gen_i_d_ + 1;
/*       fill items with garbage. */
/* SOURCE hi_iq_ns.for:72 */
/*<       items(i)=-1234 >*/
	items[feq_gen_i_d_] = -1234;
/* SOURCE hi_iq_ns.for:73 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE hi_iq_ns.for:74 */
/*<       fp(mrlist)=0 >*/
    fp[*mrlist] = 0;
/* SOURCE hi_iq_ns.for:75 */
/*<       avail_p=1 >*/
    *feq_gen_avail_p_d_ = 1;
/* SOURCE hi_iq_ns.for:76 */
/*<       active_p=0 >*/
    *feq_gen_active_p_d_ = 0;
/* SOURCE hi_iq_ns.for:77 */
/*<       return >*/
    return 0;
/* SOURCE hi_iq_ns.for:78 */
/*<       end >*/
} /* init_list__ */




/* SOURCE hi_iq_ns.for:82 */
/*<        >*/
/* Subroutine */ int feq_gen_add_to_list_d_(integer *mrlist, integer *value, integer *
	feq_gen_avail_p_d_, integer *feq_gen_active_p_d_, integer *feq_storage_bp, integer *feq_storage_items, integer *
	feq_storage_fp, integer *eflag)
{
/*     Add value to a doubly-linked list. */
/*     mrlist- max number of rows in the list */
/*     value - value to be placed on the list */
/*     avail_p- pointer to the bottom of the list of available */
/*              nodes in the list. */
/*     active_p-pointer to the top of the list of active items. It is zero */
/*              active-item list is empty. */
/*     bp(*) - back pointer to the item on a list that is back of, */
/*             below, or to the left of (take your pick of which one */
/*             you like) the item in the current node.  I no such node */
/*             exists, then we put 0 in bp, otherwise the value in bp */
/*             is greater than 0. */
/*     items(*)- the value of interest-depends on the purpose of the list */
/*     fp(*) - forward point to the item on the list that is in front of, */
/*             above, or to the right of the item in the current node. */
/*             If no such node exists, then we put 0 in fp, otherwise the */
/*             value in fp is greater than 0. */
/*     eflag - 0 if there is room on the list.  1 if the list has overflowed. */
/* SOURCE hi_iq_ns.for:106 */
/*<       implicitnone >*/
/* SOURCE hi_iq_ns.for:108 */
/*<       integermrlist,value,avail_p,active_p,eflag >*/
/* SOURCE hi_iq_ns.for:109 */
/*<       integerbp(mrlist),items(mrlist),fp(mrlist) >*/
/*     Local */
/* *********************************************************************** */
/* SOURCE hi_iq_ns.for:115 */
/*<       if(avail_p.gt.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> fp(feq_storage_fp, 1);

    feq::IndexedPointer<integer> items(feq_storage_items, 1);

    feq::IndexedPointer<integer> bp(feq_storage_bp, 1);

    /* Function Body */
    if (*feq_gen_avail_p_d_ > 0) {
/*       There is room on the list.  Set the back pointer for the next */
/*       available node to the top of the current active list. */
/* SOURCE hi_iq_ns.for:118 */
/*<       bp(avail_p)=active_p >*/
	bp[*feq_gen_avail_p_d_] = *feq_gen_active_p_d_;
/*       Set the forward pointer for the current top of list to the */
/*       new top of list-only when the the active list is present */
/* SOURCE hi_iq_ns.for:122 */
/*<       if(active_p.gt.0)then >*/
	if (*feq_gen_active_p_d_ > 0) {
/* SOURCE hi_iq_ns.for:123 */
/*<       fp(active_p)=avail_p >*/
	    fp[*feq_gen_active_p_d_] = *feq_gen_avail_p_d_;
/* SOURCE hi_iq_ns.for:124 */
/*<       endif >*/
	}
/*       Update the top-of-active-list pointer and save the value. */
/* SOURCE hi_iq_ns.for:127 */
/*<       active_p=avail_p >*/
	*feq_gen_active_p_d_ = *feq_gen_avail_p_d_;
/* SOURCE hi_iq_ns.for:128 */
/*<       items(active_p)=value >*/
	items[*feq_gen_active_p_d_] = *value;
/*       Update the available pointer.  Must do before the last */
/*       operation for the active list to avoid loss of information */
/* SOURCE hi_iq_ns.for:132 */
/*<       avail_p=fp(avail_p) >*/
	*feq_gen_avail_p_d_ = fp[*feq_gen_avail_p_d_];
/*       clear the back pointer for the available list */
/* SOURCE hi_iq_ns.for:135 */
/*<       bp(avail_p)=0 >*/
	bp[*feq_gen_avail_p_d_] = 0;
/*       Now clear the forward pointer for the top of active list */
/* SOURCE hi_iq_ns.for:138 */
/*<       fp(active_p)=0 >*/
	fp[*feq_gen_active_p_d_] = 0;
/* SOURCE hi_iq_ns.for:139 */
/*<       eflag=0 >*/
	*eflag = 0;
/* SOURCE hi_iq_ns.for:140 */
/*<       else >*/
    } else {
/* SOURCE hi_iq_ns.for:141 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE hi_iq_ns.for:142 */
/*<       endif >*/
    }
/* SOURCE hi_iq_ns.for:143 */
/*<       return >*/
    return 0;
/* SOURCE hi_iq_ns.for:144 */
/*<       end >*/
} /* add_to_list__ */




/* SOURCE hi_iq_ns.for:150 */
/*<       subroutineremove_from_list(mrlist,i,avail_p,active_p,bp,items,fp) >*/
/* Subroutine */ int feq_gen_remove_from_list_d_(integer *mrlist, integer *feq_gen_i_d_, 
	integer *feq_gen_avail_p_d_, integer *feq_gen_active_p_d_, integer *feq_storage_bp, integer *feq_storage_items, 
	integer *feq_storage_fp)
{
/*     Remove the node at i from the active list and place it on the */
/*     available list.   We assume that node i does exist on the active */
/*     list. */
/* SOURCE hi_iq_ns.for:157 */
/*<       implicitnone >*/
/* SOURCE hi_iq_ns.for:158 */
/*<       integermrlist,i,avail_p,active_p >*/
/* SOURCE hi_iq_ns.for:159 */
/*<       integerbp(mrlist),items(mrlist),fp(mrlist) >*/
/* *********************************************************************** */
/*     What we do depends on where the item is on the list: bottom */
/*     of the list, top of the list, interior to the list, or the only */
/*     node on the list. */
/* SOURCE hi_iq_ns.for:168 */
/*<       if(bp(i).gt.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> fp(feq_storage_fp, 1);

    feq::IndexedPointer<integer> items(feq_storage_items, 1);

    feq::IndexedPointer<integer> bp(feq_storage_bp, 1);

    /* Function Body */
    if (bp[*feq_gen_i_d_] > 0) {
/* SOURCE hi_iq_ns.for:169 */
/*<       if(fp(i).gt.0)then >*/
	if (fp[*feq_gen_i_d_] > 0) {
/*         node is interior to the list.  We adjust pointers to "jump" */
/*         over or around the node. */
/* SOURCE hi_iq_ns.for:172 */
/*<       fp(bp(i))=fp(i) >*/
	    fp[bp[*feq_gen_i_d_]] = fp[*feq_gen_i_d_];
/* SOURCE hi_iq_ns.for:173 */
/*<       bp(fp(i))=bp(i) >*/
	    bp[fp[*feq_gen_i_d_]] = bp[*feq_gen_i_d_];
/* SOURCE hi_iq_ns.for:174 */
/*<       else >*/
	} else {
/*         node is on top of the list.  We have to adjust the active_p */
/* SOURCE hi_iq_ns.for:176 */
/*<       active_p=bp(i) >*/
	    *feq_gen_active_p_d_ = bp[*feq_gen_i_d_];
/* SOURCE hi_iq_ns.for:177 */
/*<       fp(active_p)=0 >*/
	    fp[*feq_gen_active_p_d_] = 0;
/* SOURCE hi_iq_ns.for:178 */
/*<       endif >*/
	}
/* SOURCE hi_iq_ns.for:179 */
/*<       else >*/
    } else {
/* SOURCE hi_iq_ns.for:180 */
/*<       if(fp(i).gt.0)then >*/
	if (fp[*feq_gen_i_d_] > 0) {
/*         node is at the bottom of the list. */
/* SOURCE hi_iq_ns.for:182 */
/*<       bp(fp(i))=0 >*/
	    bp[fp[*feq_gen_i_d_]] = 0;
/* SOURCE hi_iq_ns.for:183 */
/*<       else >*/
	} else {
/*         node is the only node on the list. */
/* SOURCE hi_iq_ns.for:185 */
/*<       active_p=0 >*/
	    *feq_gen_active_p_d_ = 0;
/* SOURCE hi_iq_ns.for:186 */
/*<       endif >*/
	}
/* SOURCE hi_iq_ns.for:187 */
/*<       endif >*/
    }
/*     Now add the freed node to the bottom of the available list. */
/* SOURCE hi_iq_ns.for:190 */
/*<       if(avail_p.gt.0)then >*/
    if (*feq_gen_avail_p_d_ > 0) {
/* SOURCE hi_iq_ns.for:191 */
/*<       bp(avail_p)=i >*/
	bp[*feq_gen_avail_p_d_] = *feq_gen_i_d_;
/* SOURCE hi_iq_ns.for:192 */
/*<       fp(i)=avail_p >*/
	fp[*feq_gen_i_d_] = *feq_gen_avail_p_d_;
/* SOURCE hi_iq_ns.for:193 */
/*<       bp(i)=0 >*/
	bp[*feq_gen_i_d_] = 0;
/* SOURCE hi_iq_ns.for:194 */
/*<       avail_p=i >*/
	*feq_gen_avail_p_d_ = *feq_gen_i_d_;
/* SOURCE hi_iq_ns.for:195 */
/*<       else >*/
    } else {
/* SOURCE hi_iq_ns.for:196 */
/*<       avail_p=i >*/
	*feq_gen_avail_p_d_ = *feq_gen_i_d_;
/* SOURCE hi_iq_ns.for:197 */
/*<       fp(avail_p)=0 >*/
	fp[*feq_gen_avail_p_d_] = 0;
/* SOURCE hi_iq_ns.for:198 */
/*<       bp(avail_p)=0 >*/
	bp[*feq_gen_avail_p_d_] = 0;
/* SOURCE hi_iq_ns.for:199 */
/*<       endif >*/
    }
/*     clear the value to help in debug dumps */
/* SOURCE hi_iq_ns.for:202 */
/*<       items(i)=-1234 >*/
    items[*feq_gen_i_d_] = -1234;
/* SOURCE hi_iq_ns.for:203 */
/*<       return >*/
    return 0;
/* SOURCE hi_iq_ns.for:204 */
/*<       end >*/
} /* remove_from_list__ */




/* SOURCE hi_iq_ns.for:210 */
/*<        >*/
/* Subroutine */ int feq_gen_hi_iq_ns_fail_d_(integer *stdout, integer *kount, real *
	feq_storage_mxrev, integer *feq_storage_ivarv, integer *feq_storage_kntvec, real *feq_gen_hi_iq_ns_dwn_d_, real *
	feq_gen_hi_iq_ns_lmt_d_, char *feq_gen_hi_iq_ns_d_, integer *feq_gen_hi_iq_ns_numgt_d_, integer *
	feq_gen_feq_storage_hi_iq_ns_state_d_, real *feq_gen_feq_storage_hi_iq_ns_fac_d_, integer *eflag, ftnlen 
	hi_iq_ns_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 Adding internal var=\002,i10,\002 to activ\
e list.\002)";
    static char fmt_51[] = "(\002 Removing internal var=\002,i10,\002 Conver\
ged!\002)";
    static char fmt_52[] = "(/,\002 Int. Var#   factor\002)";
    static char fmt_54[] = "(i10,f10.3)";
    static char fmt_55[] = "(\002 Internal var=\002,i10,\002 already on li\
st.\002)";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_remove_from_list_d_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
    integer it;
    extern /* Subroutine */ int feq_gen_add_to_list_d_(integer *, integer *, integer *,
	     integer *, integer *, integer *, integer *, integer *);
    integer inext;
    real factor;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__6 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_54, 0 };


/*     Make adjustments to the high iq newton-solution factor based */
/*     on the active list when convergence has failed. */
/* SOURCE hi_iq_ns.for:220 */
/*<       implicitnone >*/
/* SOURCE hi_iq_ns.for:222 */
/*<       integereflag,hi_iq_ns_numgt,kount,stdout >*/
/* SOURCE hi_iq_ns.for:223 */
/*<       integerivarv(kount),kntvec(kount),hi_iq_ns_state(*) >*/
/* SOURCE hi_iq_ns.for:226 */
/*<       realhi_iq_ns_dwn,hi_iq_ns_lmt,hi_iq_ns_fac(*),mxrev(kount) >*/
/* SOURCE hi_iq_ns.for:229 */
/*<       characterhi_iq_ns*4 >*/
/* INCLUDE hi_iq_ns.for:231 */
/*     common for high iq newton solution */
/* SOURCE hi_iq_ns.cmn:3 */
/*<       integermrlist >*/
/* SOURCE hi_iq_ns.cmn:4 */
/*<       parameter(mrlist=100) >*/
/* SOURCE hi_iq_ns.cmn:6 */
/*<       integerhi_iq_ns_avail_p,hi_iq_ns_active_p >*/
/* SOURCE hi_iq_ns.cmn:7 */
/*<        >*/
/* SOURCE hi_iq_ns.cmn:10 */
/*<        >*/
/*     Local */
/* SOURCE hi_iq_ns.for:234 */
/*<       integeri,inext,it >*/
/* SOURCE hi_iq_ns.for:235 */
/*<       realfactor >*/
/*     ****************************formats******************************* */
/* SOURCE hi_iq_ns.for:237 */
/*<    50 format(' Adding internal var=',i10,' to active list.') >*/
/* SOURCE hi_iq_ns.for:238 */
/*<    51 format(' Removing internal var=',i10,' Converged!') >*/
/* SOURCE hi_iq_ns.for:239 */
/*<    52 format(/,' Int. Var#   factor') >*/
/* SOURCE hi_iq_ns.for:240 */
/*<    54 format(i10,f10.3) >*/
/* SOURCE hi_iq_ns.for:241 */
/*<    55 format(' Internal var=',i10,' already on list.') >*/
/* *********************************************************************** */
/* SOURCE hi_iq_ns.for:243 */
/*<       if(hi_iq_ns.eq.'LEV2')then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> kntvec(feq_storage_kntvec, 1);

    feq::IndexedPointer<integer> ivarv(feq_storage_ivarv, 1);

    feq::IndexedPointer<real> mxrev(feq_storage_mxrev, 1);

    feq::IndexedPointer<integer> feq_gen_hi_iq_ns_state_d_(feq_gen_feq_storage_hi_iq_ns_state_d_, 1);

    feq::IndexedPointer<real> feq_gen_hi_iq_ns_fac_d_(feq_gen_feq_storage_hi_iq_ns_fac_d_, 1);

    /* Function Body */
/* L50: */
/* L51: */
/* L52: */
/* L54: */
/* L55: */
    if (s_cmp(feq_gen_hi_iq_ns_d_, const_cast<char*>("LEV2"), (ftnlen)4, (ftnlen)4) == 0) {
/*       Traverse the list and remove any converged variables. */
/* SOURCE hi_iq_ns.for:245 */
/*<       i=hi_iq_ns_active_p >*/
	feq_gen_i_d_ = hiiqnscmn_1.feq_gen_hi_iq_ns_active_p_d_;
/* SOURCE hi_iq_ns.for:247 */
/*<       dowhile(i>0) >*/
	while(feq_gen_i_d_ > 0) {
/*         get the next node now because when we remove nodes from the list, */
/*         the pointers change. */
/* SOURCE hi_iq_ns.for:250 */
/*<       inext=hi_iq_ns_bp(i) >*/
	    inext = hiiqnscmn_1.feq_gen_hi_iq_ns_bp_d_[feq_gen_i_d_ - 1];
/* SOURCE hi_iq_ns.for:252 */
/*<       it=hi_iq_ns_vars(i) >*/
	    it = hiiqnscmn_1.feq_gen_hi_iq_ns_vars_d_[feq_gen_i_d_ - 1];
/*          it points to the flow value at the node */
/* SOURCE hi_iq_ns.for:254 */
/*<       if(hi_iq_ns_state(it).eq.1.and.hi_iq_ns_state(it+1).eq.1)then >*/
	    if (feq_gen_hi_iq_ns_state_d_[it] == 1 && feq_gen_hi_iq_ns_state_d_[it + 1] == 1) {
/*           both values at the node have converged.  Reset the factors */
/*           and remove the flow value variable number from the active list. */
/* SOURCE hi_iq_ns.for:258 */
/*<       hi_iq_ns_fac(it)=1.0 >*/
		feq_gen_hi_iq_ns_fac_d_[it] = (float)1.;
/* SOURCE hi_iq_ns.for:259 */
/*<       hi_iq_ns_fac(it+1)=1.0 >*/
		feq_gen_hi_iq_ns_fac_d_[it + 1] = (float)1.;
/* SOURCE hi_iq_ns.for:260 */
/*<       write(stdout,51)it >*/
		feq_gen_io_d__5.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__5);
		do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
		e_wsfe();
/*           remove this variable from the active list. */
/* SOURCE hi_iq_ns.for:262 */
/*<        >*/
		feq_gen_remove_from_list_d_(&feq_gen_c_d_100, &feq_gen_i_d_, &
			hiiqnscmn_1.feq_gen_hi_iq_ns_avail_p_d_, &
			hiiqnscmn_1.feq_gen_hi_iq_ns_active_p_d_, 
			hiiqnscmn_1.feq_gen_hi_iq_ns_bp_d_, 
			hiiqnscmn_1.feq_gen_hi_iq_ns_vars_d_, 
			hiiqnscmn_1.feq_gen_hi_iq_ns_fp_d_);
/* SOURCE hi_iq_ns.for:265 */
/*<       endif >*/
	    }
/* SOURCE hi_iq_ns.for:266 */
/*<       i=inext >*/
	    feq_gen_i_d_ = inext;
/* SOURCE hi_iq_ns.for:267 */
/*<       enddo >*/
	}
/* SOURCE hi_iq_ns.for:268 */
/*<       endif >*/
    }
/*     Add the last variable in the iteration log */
/*     to the active list.  Later we may try to get smarter.  12 April 2003> */
/*     We are trying to get smarter because adding a variable appears to work */
/*     in only some cases.  We will try to add both variables at a node */
/*     if only one appears in the critical position.  The flow variable no. at a node */
/*     is always odd with the depth being given by the following even numbered variable. */
/*     Later on 12 april:  Need to add even more smarts!  We must force the addition of */
/*     both values at a node and also keep them both there until both are converged! */
/*     Thus we do the following:  1. Find the flow variable number and use it as the */
/*     id for the node.  2. Only the flow variable is placed on the list.  The depth */
/*     variable is implied.  3. Both will have the same fac value. */
/* SOURCE hi_iq_ns.for:284 */
/*<       if(kntvec(kount).le.hi_iq_ns_numgt)then >*/
    if (kntvec[*kount] <= *feq_gen_hi_iq_ns_numgt_d_) {
/* SOURCE hi_iq_ns.for:285 */
/*<       i=ivarv(kount) >*/
	feq_gen_i_d_ = ivarv[*kount];
/* SOURCE hi_iq_ns.for:286 */
/*<       if(mod(i,2).eq.0)then >*/
	if (feq_gen_i_d_ % 2 == 0) {
/*         the variable number is even.  decrease  by one to get the */
/*         variable number for the associated flow */
/* SOURCE hi_iq_ns.for:289 */
/*<       i=i-1 >*/
	    --feq_gen_i_d_;
/* SOURCE hi_iq_ns.for:290 */
/*<       endif >*/
	}
/* SOURCE hi_iq_ns.for:292 */
/*<       if(hi_iq_ns_fac(i).lt.1.0)then >*/
	if (feq_gen_hi_iq_ns_fac_d_[feq_gen_i_d_] < (float)1.) {
/*         don't add to the list again-already there */
/* SOURCE hi_iq_ns.for:294 */
/*<       write(stdout,55)i >*/
	    feq_gen_io_d__6.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__6);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE hi_iq_ns.for:295 */
/*<       else >*/
	} else {
/*         add to the list */
/* SOURCE hi_iq_ns.for:297 */
/*<       write(stdout,50)i >*/
	    feq_gen_io_d__7.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__7);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE hi_iq_ns.for:298 */
/*<        >*/
	    feq_gen_add_to_list_d_(&feq_gen_c_d_100, &feq_gen_i_d_, &hiiqnscmn_1.feq_gen_hi_iq_ns_avail_p_d_, &
		    hiiqnscmn_1.feq_gen_hi_iq_ns_active_p_d_, 
		    hiiqnscmn_1.feq_gen_hi_iq_ns_bp_d_, hiiqnscmn_1.feq_gen_hi_iq_ns_vars_d_, 
		    hiiqnscmn_1.feq_gen_hi_iq_ns_fp_d_, eflag);
/* SOURCE hi_iq_ns.for:302 */
/*<       endif >*/
	}
/* SOURCE hi_iq_ns.for:303 */
/*<       endif >*/
    }
/*      write(stdout,*) 'dump before LEV2 action' */
/*      call hi_iq_ns_dump(stdout,10) */
/*     Now traverse the active list and adjust the factor. */
/* SOURCE hi_iq_ns.for:311 */
/*<       i=hi_iq_ns_active_p >*/
    feq_gen_i_d_ = hiiqnscmn_1.feq_gen_hi_iq_ns_active_p_d_;
/*      write(stdout,*) 'dump before adjusting list' */
/*      call hi_iq_ns_dump(stdout,10) */
/* SOURCE hi_iq_ns.for:315 */
/*<       if(i>0)then >*/
    if (feq_gen_i_d_ > 0) {
/* SOURCE hi_iq_ns.for:316 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__8.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__8);
	e_wsfe();
/* SOURCE hi_iq_ns.for:317 */
/*<       endif >*/
    }
/* SOURCE hi_iq_ns.for:318 */
/*<       dowhile(i>0) >*/
    while(feq_gen_i_d_ > 0) {
/* SOURCE hi_iq_ns.for:319 */
/*<       it=hi_iq_ns_vars(i) >*/
	it = hiiqnscmn_1.feq_gen_hi_iq_ns_vars_d_[feq_gen_i_d_ - 1];
/*       Do the flow value */
/* SOURCE hi_iq_ns.for:321 */
/*<       factor=hi_iq_ns_fac(it) >*/
	factor = feq_gen_hi_iq_ns_fac_d_[it];
/* SOURCE hi_iq_ns.for:322 */
/*<       factor=factor*hi_iq_ns_dwn >*/
	factor *= *feq_gen_hi_iq_ns_dwn_d_;
/* SOURCE hi_iq_ns.for:323 */
/*<       if(factor.lt.hi_iq_ns_lmt)then >*/
	if (factor < *feq_gen_hi_iq_ns_lmt_d_) {
/* SOURCE hi_iq_ns.for:324 */
/*<       factor=hi_iq_ns_lmt >*/
	    factor = *feq_gen_hi_iq_ns_lmt_d_;
/* SOURCE hi_iq_ns.for:325 */
/*<       endif >*/
	}
/* SOURCE hi_iq_ns.for:326 */
/*<       hi_iq_ns_fac(it)=factor >*/
	feq_gen_hi_iq_ns_fac_d_[it] = factor;
/* SOURCE hi_iq_ns.for:327 */
/*<       write(stdout,54)it,factor >*/
	feq_gen_io_d__10.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__10);
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&factor, (ftnlen)sizeof(real));
	e_wsfe();
/*       Do the depth value */
/* SOURCE hi_iq_ns.for:329 */
/*<       hi_iq_ns_fac(it+1)=factor >*/
	feq_gen_hi_iq_ns_fac_d_[it + 1] = factor;
/*       do the next node-we are moving from top to bottom of the */
/*       active list. */
/* SOURCE hi_iq_ns.for:333 */
/*<       i=hi_iq_ns_bp(i) >*/
	feq_gen_i_d_ = hiiqnscmn_1.feq_gen_hi_iq_ns_bp_d_[feq_gen_i_d_ - 1];
/* SOURCE hi_iq_ns.for:334 */
/*<       enddo >*/
    }
/*      write(stdout,'(a)') ' ' */
/*      write(stdout,*) ' hi_iq_ns_active_p=', hi_iq_ns_active_p, */
/*     a               ' after adjusting list' */
/* SOURCE hi_iq_ns.for:338 */
/*<       return >*/
    return 0;
/* SOURCE hi_iq_ns.for:339 */
/*<       end >*/
} /* hi_iq_ns_fail__ */




/* SOURCE hi_iq_ns.for:345 */
/*<        >*/
/* Subroutine */ int feq_gen_hi_iq_ns_success_d_(integer *stdout, real *feq_gen_hi_iq_ns_up_d_, 
	char *feq_gen_hi_iq_ns_d_, doublereal *dt, real *feq_gen_hi_iq_ns_dt_d_, real *
	feq_gen_feq_storage_hi_iq_ns_fac_d_, ftnlen hi_iq_ns_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 Removing internal var=\002,i10,\002 from a\
ctive list.\002)";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_remove_from_list_d_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
    integer it;
    real force;
    integer inext;
    real factor;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_50, 0 };


/*     Make adjustments to the high iq newton-solution factor based */
/*     on the active list when we have convergence */
/* SOURCE hi_iq_ns.for:352 */
/*<       implicitnone >*/
/* SOURCE hi_iq_ns.for:354 */
/*<       integerstdout >*/
/* SOURCE hi_iq_ns.for:356 */
/*<       realhi_iq_ns_up,hi_iq_ns_fac(*),hi_iq_ns_dt >*/
/* SOURCE hi_iq_ns.for:358 */
/*<       real*8dt >*/
/* SOURCE hi_iq_ns.for:360 */
/*<       characterhi_iq_ns*4 >*/
/* INCLUDE hi_iq_ns.for:362 */
/*     common for high iq newton solution */
/* SOURCE hi_iq_ns.cmn:3 */
/*<       integermrlist >*/
/* SOURCE hi_iq_ns.cmn:4 */
/*<       parameter(mrlist=100) >*/
/* SOURCE hi_iq_ns.cmn:6 */
/*<       integerhi_iq_ns_avail_p,hi_iq_ns_active_p >*/
/* SOURCE hi_iq_ns.cmn:7 */
/*<        >*/
/* SOURCE hi_iq_ns.cmn:10 */
/*<        >*/
/*     Local */
/* SOURCE hi_iq_ns.for:365 */
/*<       integeri,inext,it >*/
/* SOURCE hi_iq_ns.for:366 */
/*<       realfactor,force >*/
/*     *****************************formats****************************** */
/* SOURCE hi_iq_ns.for:368 */
/*<    50 format(' Removing internal var=',i10,' from active list.') >*/
/* *********************************************************************** */
/*     Traverse the active list multiplying the factors by hi_iq_ns_up. */
/*     If the factor for a variable becomes >= 1.0, set the factor to 1.0 */
/*     and remove the variable from the active list. */
/* SOURCE hi_iq_ns.for:374 */
/*<       if(hi_iq_ns.eq.'LEV2'.and.dt.gt.hi_iq_ns_dt)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_hi_iq_ns_fac_d_(feq_gen_feq_storage_hi_iq_ns_fac_d_, 1);

    /* Function Body */
/* L50: */
    if (s_cmp(feq_gen_hi_iq_ns_d_, const_cast<char*>("LEV2"), (ftnlen)4, (ftnlen)4) == 0 && *dt > *
	    feq_gen_hi_iq_ns_dt_d_) {
/* SOURCE hi_iq_ns.for:375 */
/*<       force=1.e10 >*/
	force = (float)1e10;
/* SOURCE hi_iq_ns.for:376 */
/*<       else >*/
    } else {
/* SOURCE hi_iq_ns.for:377 */
/*<       force=hi_iq_ns_up >*/
	force = *feq_gen_hi_iq_ns_up_d_;
/* SOURCE hi_iq_ns.for:378 */
/*<       endif >*/
    }
/*        write(stdout,*) 'dump before list-node removal' */
/*        call hi_iq_ns_dump(stdout,10) */
/* SOURCE hi_iq_ns.for:383 */
/*<       i=hi_iq_ns_active_p >*/
    feq_gen_i_d_ = hiiqnscmn_1.feq_gen_hi_iq_ns_active_p_d_;
/* SOURCE hi_iq_ns.for:385 */
/*<       dowhile(i>0) >*/
    while(feq_gen_i_d_ > 0) {
/*       get the next node now because when we remove nodes from the list, */
/*       the pointers change. */
/* SOURCE hi_iq_ns.for:388 */
/*<       inext=hi_iq_ns_bp(i) >*/
	inext = hiiqnscmn_1.feq_gen_hi_iq_ns_bp_d_[feq_gen_i_d_ - 1];
/*       adjust the factor for the current variable */
/* SOURCE hi_iq_ns.for:391 */
/*<       it=hi_iq_ns_vars(i) >*/
	it = hiiqnscmn_1.feq_gen_hi_iq_ns_vars_d_[feq_gen_i_d_ - 1];
/*         it points to the flow value */
/* SOURCE hi_iq_ns.for:393 */
/*<       factor=hi_iq_ns_fac(it) >*/
	factor = feq_gen_hi_iq_ns_fac_d_[it];
/* SOURCE hi_iq_ns.for:394 */
/*<       factor=factor*force >*/
	factor *= force;
/* SOURCE hi_iq_ns.for:395 */
/*<       if(factor.ge.1.0)then >*/
	if (factor >= (float)1.) {
/* SOURCE hi_iq_ns.for:396 */
/*<       write(stdout,50)it >*/
	    feq_gen_io_d__16.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__16);
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE hi_iq_ns.for:397 */
/*<       factor=1.0 >*/
	    factor = (float)1.;
/*         remove this variable from the active list. */
/* SOURCE hi_iq_ns.for:399 */
/*<        >*/
	    feq_gen_remove_from_list_d_(&feq_gen_c_d_100, &feq_gen_i_d_, &hiiqnscmn_1.feq_gen_hi_iq_ns_avail_p_d_,
		     &hiiqnscmn_1.feq_gen_hi_iq_ns_active_p_d_, 
		    hiiqnscmn_1.feq_gen_hi_iq_ns_bp_d_, hiiqnscmn_1.feq_gen_hi_iq_ns_vars_d_, 
		    hiiqnscmn_1.feq_gen_hi_iq_ns_fp_d_);
/* SOURCE hi_iq_ns.for:402 */
/*<       endif >*/
	}
/* SOURCE hi_iq_ns.for:403 */
/*<       hi_iq_ns_fac(it)=factor >*/
	feq_gen_hi_iq_ns_fac_d_[it] = factor;
/* SOURCE hi_iq_ns.for:404 */
/*<       hi_iq_ns_fac(it+1)=factor >*/
	feq_gen_hi_iq_ns_fac_d_[it + 1] = factor;
/* SOURCE hi_iq_ns.for:405 */
/*<       i=inext >*/
	feq_gen_i_d_ = inext;
/* SOURCE hi_iq_ns.for:406 */
/*<       enddo >*/
    }
/*        write(stdout,*) 'dump after list-node removal' */
/*        call hi_iq_ns_dump(stdout,10) */
/* SOURCE hi_iq_ns.for:411 */
/*<       return >*/
    return 0;
/* SOURCE hi_iq_ns.for:412 */
/*<       end >*/
} /* hi_iq_ns_success__ */




/* SOURCE hi_iq_ns.for:417 */
/*<       subroutinehi_iq_ns_list_init() >*/
/* Subroutine */ int feq_gen_hi_iq_ns_list_init_d_()
{
    extern /* Subroutine */ int feq_gen_init_list_d_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);

/*     Initialize the list for the high iq newton solution */
/* SOURCE hi_iq_ns.for:421 */
/*<       implicitnone >*/
/* INCLUDE hi_iq_ns.for:423 */
/*     common for high iq newton solution */
/* SOURCE hi_iq_ns.cmn:3 */
/*<       integermrlist >*/
/* SOURCE hi_iq_ns.cmn:4 */
/*<       parameter(mrlist=100) >*/
/* SOURCE hi_iq_ns.cmn:6 */
/*<       integerhi_iq_ns_avail_p,hi_iq_ns_active_p >*/
/* SOURCE hi_iq_ns.cmn:7 */
/*<        >*/
/* SOURCE hi_iq_ns.cmn:10 */
/*<        >*/
/* *********************************************************************** */
/* SOURCE hi_iq_ns.for:425 */
/*<        >*/
    feq_gen_init_list_d_(&feq_gen_c_d_100, &hiiqnscmn_1.feq_gen_hi_iq_ns_avail_p_d_, &
	    hiiqnscmn_1.feq_gen_hi_iq_ns_active_p_d_, hiiqnscmn_1.feq_gen_hi_iq_ns_bp_d_, 
	    hiiqnscmn_1.feq_gen_hi_iq_ns_vars_d_, hiiqnscmn_1.feq_gen_hi_iq_ns_fp_d_);
/* SOURCE hi_iq_ns.for:428 */
/*<       return >*/
    return 0;
/* SOURCE hi_iq_ns.for:429 */
/*<       end >*/
} /* hi_iq_ns_list_init__ */




/* SOURCE hi_iq_ns.for:433 */
/*<       subroutinehi_iq_ns_dump(stdout,n) >*/
/* Subroutine */ int feq_gen_hi_iq_ns_dump_d_(integer *stdout, integer *n)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002hi_iq_ns_avail_p=\002,i5,\002 hi_iq_ns_ac\
tive_p=\002,i5)";
    static char fmt_52[] = "(\002     index     backp     value  forwardp\
\002)";
    static char fmt_54[] = "(4i10)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__17 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_54, 0 };


/*     dump the first n values in the current list plus basic pointers. */
/* SOURCE hi_iq_ns.for:437 */
/*<       implicitnone >*/
/* SOURCE hi_iq_ns.for:439 */
/*<       integern,stdout >*/
/* INCLUDE hi_iq_ns.for:440 */
/*     common for high iq newton solution */
/* SOURCE hi_iq_ns.cmn:3 */
/*<       integermrlist >*/
/* SOURCE hi_iq_ns.cmn:4 */
/*<       parameter(mrlist=100) >*/
/* SOURCE hi_iq_ns.cmn:6 */
/*<       integerhi_iq_ns_avail_p,hi_iq_ns_active_p >*/
/* SOURCE hi_iq_ns.cmn:7 */
/*<        >*/
/* SOURCE hi_iq_ns.cmn:10 */
/*<        >*/
/*     Local */
/* SOURCE hi_iq_ns.for:443 */
/*<       integeri >*/
/*     ************************************formats*********************** */
/* SOURCE hi_iq_ns.for:445 */
/*<    50 format(/,'hi_iq_ns_avail_p=',i5,' hi_iq_ns_active_p=',i5) >*/
/* SOURCE hi_iq_ns.for:446 */
/*<    52 format('     index     backp     value  forwardp') >*/
/* SOURCE hi_iq_ns.for:447 */
/*<    54 format(4i10) >*/
/* *********************************************************************** */
/* SOURCE hi_iq_ns.for:449 */
/*<       write(stdout,50)hi_iq_ns_avail_p,hi_iq_ns_active_p >*/
/* L50: */
/* L52: */
/* L54: */
    feq_gen_io_d__17.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__17);
    do_fio(&feq_gen_c_d_1, (char *)&hiiqnscmn_1.feq_gen_hi_iq_ns_avail_p_d_, (ftnlen)sizeof(
	    integer));
    do_fio(&feq_gen_c_d_1, (char *)&hiiqnscmn_1.feq_gen_hi_iq_ns_active_p_d_, (ftnlen)sizeof(
	    integer));
    e_wsfe();
/* SOURCE hi_iq_ns.for:450 */
/*<       write(stdout,52) >*/
    feq_gen_io_d__18.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__18);
    e_wsfe();
/* SOURCE hi_iq_ns.for:451 */
/*<       doi=1,n >*/
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE hi_iq_ns.for:452 */
/*<       write(stdout,54)i,hi_iq_ns_bp(i),hi_iq_ns_vars(i),hi_iq_ns_fp(i) >*/
	feq_gen_io_d__20.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__20);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hiiqnscmn_1.feq_gen_hi_iq_ns_bp_d_[feq_gen_i_d_ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hiiqnscmn_1.feq_gen_hi_iq_ns_vars_d_[feq_gen_i_d_ - 1], (ftnlen)
		sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hiiqnscmn_1.feq_gen_hi_iq_ns_fp_d_[feq_gen_i_d_ - 1], (ftnlen)
		sizeof(integer));
	e_wsfe();
/* SOURCE hi_iq_ns.for:454 */
/*<       enddo >*/
    }
/* SOURCE hi_iq_ns.for:456 */
/*<       return >*/
    return 0;
/* SOURCE hi_iq_ns.for:457 */
/*<       end >*/
} /* hi_iq_ns_dump__ */

#ifdef __cplusplus
	}
#endif
