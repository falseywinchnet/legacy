#ifndef FEQ_PROBE_COMMON_HPP
#define FEQ_PROBE_COMMON_HPP
#include <feq/storage.hpp>
#include <vector>
#include <string>
#include <cmath>
#undef stdin
#undef stdout
#undef stderr
#include "f2c.h"
extern "C" {
struct Common_abslot_ {
    integer feq_gen_slot_present_d_;
    real nslot, wslot, eslot, yslot, rd, tzero, expfac;
};
extern Common_abslot_ abslot_;
struct Common_appcom_ {
    integer apptab;
    real appelv, applen, applos, appexp;
    integer zertab;
    real zerelv;
};
extern Common_appcom_ appcom_;
struct Common_bridge_ {
    integer bscurv;
    real bskew, pskew;
    integer abtype, ptype;
    real plen, adjfac, cntru, cntrd;
    integer ftype, npz, maxnpz;
    real pz[25];
    integer pnum[25];
    real pwidth[25], tpv[25], apv[25];
};
extern Common_bridge_ bridge_;
struct Common_cdcom_ {
    real cd, c123, c46;
    integer ty6sup;
    real c5, cc, krb, kwing, kproj;
    integer ratflg;
    real avh, vhl;
    integer tb6adr, tb7adr, tb8adr;
    real rbval, wwangl;
    integer tb15ad, tb16ad[4];
    real rghfac, hoverd, nbar, rovdlm;
    integer tb5adr, tb21adr, tb22adr, tb24adr, tblpdadr;
    real bvangl, lpovd, afhwa, cfhwa, yfhwa, sfhwa;
};
extern Common_cdcom_ cdcom_;
struct Common_chncom_ {
    integer xsadr;
    real q, qn, l, sbot, yl, yr, qerr, lstres, nddabs, nddrel, frfac;
};
extern Common_chncom_ chncom_;
struct feq_gen_Common_chnrtitm_com_d_ {
    doublereal chnrtitmdtab[6];
    integer chnrtitmitab[7];
    real chnrtitmftab[7];
};
extern feq_gen_Common_chnrtitm_com_d_ feq_gen_chnrtitm_com_d_;
struct feq_gen_Common_chnrtitm_comc_d_ {
    char chnrtitmctab[448];
};
extern feq_gen_Common_chnrtitm_comc_d_ feq_gen_chnrtitm_comc_d_;
struct Common_clcom_ {
    integer iend, nxt, narg;
};
extern Common_clcom_ clcom_;
struct Common_clcomc_ {
    char cl[127], namvec[384];
};
extern Common_clcomc_ clcomc_;
struct Common_crcom_ {
    char cr[1];
};
extern Common_crcom_ crcom_;
struct Common_crqrec_ {
    integer adr;
    real flow;
    integer ef;
};
extern Common_crqrec_ crqrec_;
struct Common_culcom_ {
    doublereal frcfac;
    real xvec[8400];
    integer nsec[8400];
    real zbvec[8400], yvec[8400], yvecsb[8400], yvecsp[8400], dvec[8400];
    integer hltab[8400];
    real ka[8400], kd[8400], ycvec[8400], ynvec[8400], sfvec[8400], evec[8400]
	    ;
    integer iat3d;
    real sevec[8400];
    integer iat6d;
    real l23, avec[8400], kvec[8400], loverd, szero, ty1ytd, ty1htd;
    integer sbkind, sbshape;
    real sbvec[8400], ty5sbf;
};
extern Common_culcom_ culcom_;
struct Common_datetime_ {
    char feq_gen_version_run_date_time_string_d_[95];
};
extern Common_datetime_ datetime_;
struct Common_depcom_ {
    integer deptab, begtab;
    real depelv, begelv, widfac, dsffac;
    integer deptyp;
};
extern Common_depcom_ depcom_;
struct feq_gen_Common_depitm_com_d_ {
    doublereal depitmdtab[1];
    integer depitmitab[2];
    real depitmftab[2];
};
extern feq_gen_Common_depitm_com_d_ feq_gen_depitm_com_d_;
struct feq_gen_Common_depitm_comc_d_ {
    char depitmctab[512];
};
extern feq_gen_Common_depitm_comc_d_ feq_gen_depitm_comc_d_;
struct Common_depmc_ {
    real mfcon, m44, m3;
    integer mcase;
    real e44, e4;
};
extern Common_depmc_ depmc_;
struct Common_dpm26c_ {
    integer outun;
    real rmflux, m43;
};
extern Common_dpm26c_ dpm26c_;
struct Common_embcmc_ {
    char surf[8000];
};
extern Common_embcmc_ embcmc_;
struct Common_embcom_ {
    integer noff, minloc, plcwtb, glcwtb, phcwtb, ghcwtb, psubtb, gsubtb;
    real mincrs, off[1000], crest[1000], width[1000], approc[1000], xrdfl[
	    1000], xrdfr[1000], hrdfl[1000], hrdfm[1000], hrdfr[1000], qrdfl[
	    1000], qrdfm[1000], qrdfr[1000], tothl[1000], tothm[1000], tothr[
	    1000], yfl[1000], yfm[1000], yfr[1000], appl[1000], appm[1000], 
	    appr[1000], wl[1000], wm[1000], wr[1000], aell[1000], aelm[1000], 
	    aelr[1000], rmffac;
};
extern Common_embcom_ embcom_;
struct feq_gen_Common_embkitm_com_d_ {
    doublereal embkitmdtab[1];
    integer embkitmitab[7];
    real embkitmftab[7];
};
extern feq_gen_Common_embkitm_com_d_ feq_gen_embkitm_com_d_;
struct feq_gen_Common_embkitm_comc_d_ {
    char embkitmctab[128];
};
extern feq_gen_Common_embkitm_comc_d_ feq_gen_embkitm_comc_d_;
struct Common_embq_ {
    integer hlflag, hpflag;
    real hlcrit, hlmax;
};
extern Common_embq_ embq_;
struct Common_epscom_ {
    doublereal epsint;
    real epsf, epsarg;
    integer errknd, inthow;
    real epsabs, epsdif;
};
extern Common_epscom_ epscom_;
struct Common_feccom_ {
    real htl, hpl, hpr, yl, yr, al, ar, alphal, alphar, kl, kr;
    integer xtabl, xtabr;
    real zbl, zbr, ka, kd, dx, smooth, grv2, hdatum, q, qcl, qcr;
    integer flg;
    real tgm;
};
extern Common_feccom_ feccom_;
struct Common_flapgate_ {
    real flap;
};
extern Common_flapgate_ flapgate_;
struct Common_fldway_ {
    integer flood;
    real glbelv, glbcon, fldelv[10002], fldlt[10002], fldrt[10002], fldlos[
	    10002], feqbot[10002], fldflow[10002], fldarea[10002];
};
extern Common_fldway_ fldway_;
struct Common_fldwyc_ {
    char fldopt[40008];
};
extern Common_fldwyc_ fldwyc_;
struct Common_flitems_ {
    doublereal feq_gen_rm_origin_d_, feq_gen_s_atrmorg_d_, feq_gen_rm_factor_d_, feq_gen_s_begin_d_, 
	    feq_gen_fl_distance_d_[5000], feq_gen_fl_easting_d_[5000], feq_gen_fl_northing_d_[5000];
    integer feq_gen_fl_present_d_, feq_gen_fl_pnt_knt_d_, l;
};
extern Common_flitems_ flitems_;
struct Common_flotab_ {
    integer nft, maxnft;
    real zft[25], ftable[400]	/* was [20][20] */, qcritv[25];
};
extern Common_flotab_ flotab_;
struct Common_ftable_ {
    doublereal dtab[6500001];
};
extern Common_ftable_ ftable_;
struct Common_ftablea_ {
    doublereal longdummy;
    integer itmp, feq_gen_knt_of_ftabs_d_, ftpnt[10007];
};
extern Common_ftablea_ ftablea_;
struct Common_ftablec_ {
    char feq_gen_ft_loc_status_d_[10002];
};
extern Common_ftablec_ ftablec_;
struct feq_gen_Common_fwcc_c_d_ {
    doublereal econ, efac, m1, m2, hgt, staup;
};
extern feq_gen_Common_fwcc_c_d_ feq_gen_fwcc_c_d_;
struct Common_gnicom_ {
    doublereal wgs[21], xgs[21];
    integer ngs;
};
extern Common_gnicom_ gnicom_;
struct feq_gen_Common_good_brk_d_ {
    integer feq_gen_n_qd_d_, feq_gen_ig_last_d_, feq_gen_qd_pnt_d_[906];
    doublereal igval, feq_gen_xvec_qd_d_[906], igvec[906], fpvec[151], fppvec[151], 
	    feq_gen_xvec_cs_d_[151], feq_gen_fvec_cs_d_[151];
};
extern feq_gen_Common_good_brk_d_ feq_gen_good_brk_d_;
struct feq_gen_Common_grid_datum_d_ {
    char feq_gen_g_zone_d_[8], feq_gen_g_hgrid_d_[8], feq_gen_g_vdatum_d_[8], feq_gen_g_unitsys_d_[8], feq_gen_g_basis_d_[
	    8];
};
extern feq_gen_Common_grid_datum_d_ feq_gen_grid_datum_d_;
struct Common_grvcom_ {
    real grav, grav2, bcwmax, feq_gen_sqrt_grav_d_;
};
extern Common_grvcom_ grvcom_;
struct Common_homec_ {
    char home[128], ghome[128], feq_gen_ghome_out_d_[128], stdext[128];
};
extern Common_homec_ homec_;
struct Common_invgc_ {
    integer feq_gen_gate_res_table_d_, feq_gen_gate_res_stdout_d_;
    real feq_gen_gate_res_flow_d_, feq_gen_gate_res_eup_d_, feq_gen_gate_res_edn_d_, feq_gen_gate_res_hbase_d_;
};
extern Common_invgc_ invgc_;
struct Common_invgcc_ {
    char feq_gen_gate_res_ftype_d_[8];
};
extern Common_invgcc_ invgcc_;
struct Common_isecom_ {
    integer adrst;
    real qt, et, gravt;
    integer feq_gen_type_d_, opunit;
};
extern Common_isecom_ isecom_;
struct Common_itabidnum_ {
    integer feq_gen_kount_of_internal_tabids_d_;
};
extern Common_itabidnum_ itabidnum_;
struct Common_julian_ {
    doublereal jtime, dyfrac, sfrac, sjtime, efrac, ejtime, ujtime, vjtime, 
	    prtime, jtewyr, feq_gen_tab_789_jtbase_d_;
    integer yr, mn, dy, syr, smn, sdy, eyr, emn, edy, reset, leap, dmyear, 
	    dmmn;
};
extern Common_julian_ julian_;
struct feq_gen_Common_lctnitm_com_d_ {
    doublereal lctnitmdtab[2];
    integer lctnitmitab[4];
    real lctnitmftab[4];
};
extern feq_gen_Common_lctnitm_com_d_ feq_gen_lctnitm_com_d_;
struct feq_gen_Common_lctnitm_comc_d_ {
    char lctnitmctab[320];
};
extern feq_gen_Common_lctnitm_comc_d_ feq_gen_lctnitm_comc_d_;
struct feq_gen_Common_lprfititem_com_d_ {
    doublereal lprfititemdtab[4];
    integer lprfititemitab[3];
    real lprfititemftab[3];
};
extern feq_gen_Common_lprfititem_com_d_ feq_gen_lprfititem_com_d_;
struct feq_gen_Common_lprfititem_comc_d_ {
    char lprfititemctab[704];
};
extern feq_gen_Common_lprfititem_comc_d_ feq_gen_lprfititem_comc_d_;
struct Common_mktbindx_ {
    integer feq_gen_ftab_type_d_[10002], feq_gen_data_pnt_d_[10002], feq_gen_index_knt_d_, stdindex;
};
extern Common_mktbindx_ mktbindx_;
struct Common_mktbindxc_ {
    char feq_gen_ftab_fn_d_[2560512], ftabid[160032], feq_gen_make_tab_index_d_[4];
};
extern Common_mktbindxc_ mktbindxc_;
struct Common_ndrsdc_ {
    integer adr;
    real flow, rtsbot;
};
extern Common_ndrsdc_ ndrsdc_;
struct Common_nrdzcm_ {
    real nrzero, dzlim;
    integer nocm;
    real slot;
    integer iusgs, extend, gxtend;
};
extern Common_nrdzcm_ nrdzcm_;
struct Common_offcom_ {
    integer offvec[35];
};
extern Common_offcom_ offcom_;
struct feq_gen_Common_orf_shape_d_ {
    doublereal feq_gen_w_over_d_d_, feq_gen_orf_w_d_[15], feq_gen_orf_x_d_[15];
    integer feq_gen_orf_num_d_, feq_gen_orifice_shape_tab_d_;
};
extern feq_gen_Common_orf_shape_d_ feq_gen_orf_shape_d_;
struct Common_putget_ {
    integer putq, putmf, putmf3, puty2, puty3, getq[51], getmf[51];
};
extern Common_putget_ putget_;
struct Common_rappc_ {
    real cdin;
    integer conf;
    real vhloss;
};
extern Common_rappc_ rappc_;
struct Common_rconc_ {
    real cdis, hoverd, afull, feq_gen_d_d_;
    integer adr;
    real feq_gen_h_d_, dzvc, evc, vhf;
};
extern Common_rconc_ rconc_;
struct Common_rdfcom_ {
    real wfrdf, mfrdf, efrdf, wfrd, mfrd, efrd;
};
extern Common_rdfcom_ rdfcom_;
struct Common_ritcom_ {
    real w1, v1, w, a, q;
    integer wtab, qtab, off, ritout;
};
extern Common_ritcom_ ritcom_;
struct Common_rqvtc_ {
    char feq_gen_class_d_[8];
};
extern Common_rqvtc_ rqvtc_;
struct Common_rqvtw_ {
    integer iup, idn;
    real zsub, z43fix;
    integer sbflag, outun;
    real abase, z1t;
    integer cqtype;
    real qfixed;
    integer fqtype;
};
extern Common_rqvtw_ rqvtw_;
struct Common_rrovdc_ {
    char feq_gen_class_d_[8];
};
extern Common_rrovdc_ rrovdc_;
struct Common_rty0c_ {
    integer outun0;
    real dup0, a1t0, ddn0, z1t0;
    integer iup0, idn0, sflag0;
};
extern Common_rty0c_ rty0c_;
struct Common_rty0cc_ {
    char class0[8];
};
extern Common_rty0cc_ rty0cc_;
struct Common_rty1c_ {
    real du;
    integer ftype, outun1;
    real frsq, dhty1;
};
extern Common_rty1c_ rty1c_;
struct Common_rty1cc_ {
    char class1[8];
};
extern Common_rty1cc_ rty1cc_;
struct Common_rty2c_ {
    integer outun, iup, idn, ef, conf;
    real z1true, a1true;
    integer ns;
    real sbot;
    integer sbflag;
    real alp1tr, maxarg;
};
extern Common_rty2c_ rty2c_;
struct Common_rty2cc_ {
    char feq_gen_class_d_[8];
};
extern Common_rty2cc_ rty2cc_;
struct Common_rty6c_ {
    integer outun;
    real z1true;
    integer iup, idn, ef, conf, sbflag;
    real zdat, aclv, yc, z3pt;
    integer ftype;
    real aexit, ta1, dht;
    integer nsf;
    real yat2;
};
extern Common_rty6c_ rty6c_;
struct Common_rty6cc_ {
    char feq_gen_class_d_[8];
};
extern Common_rty6cc_ rty6cc_;
struct Common_rty7c_ {
    integer outun, ef;
    real z1t, z4t, zsub;
    integer t7flag, q3adr, y3adr;
    real ddn;
};
extern Common_rty7c_ rty7c_;
struct Common_sberc_ {
    real rhs;
    integer adrs;
    real qt, kr, dx, se, kacc, kdec, ar, alpr, feq_gen_d_d_;
};
extern Common_sberc_ sberc_;
struct Common_seqdc_ {
    doublereal mvc, g, qsqr;
};
extern Common_seqdc_ seqdc_;
struct feq_gen_Common_sf_frq_d_ {
    integer gtype, barrel;
    real board, feq_gen_c_d_, cw, feq_gen_d_d_, hwe, inel, k, l, n, outel, swb, swe, w, wb, qa;
};
extern feq_gen_Common_sf_frq_d_ feq_gen_sf_frq_d_;
struct feq_gen_Common_sf_frqc_d_ {
    char code[3];
};
extern feq_gen_Common_sf_frqc_d_ feq_gen_sf_frqc_d_;
struct Common_sincom_ {
    integer dir, jaxis, numsec;
    real eps;
    integer vartyp, numoff[400];
    real stl[4400]	/* was [400][11] */, offset[4400]	/* was [400][
	    11] */, sinu[4400]	/* was [400][11] */;
};
extern Common_sincom_ sincom_;
struct feq_gen_Common_so_flow_d_ {
    doublereal xs, xe, epsd, xvec[500], yvec[500], ycvec[500], ynvec[500], 
	    ajet;
    real afac, div, h1eff, qsqr, g, z3b, z4b, y3, y4, a4, b4, j4, costheta;
    integer dtab, etab, stdouta, rflag, feq_gen_yc_flag_d_;
};
extern feq_gen_Common_so_flow_d_ feq_gen_so_flow_d_;
struct Common_sperc_ {
    real rhs;
    integer adr;
    real qr, ql, kl, dx, al, alpl, kacc, kdec, feq_gen_d_d_, se;
};
extern Common_sperc_ sperc_;
struct feq_gen_Common_stdun_com_d_ {
    integer std5, std6, std7, std10, std48, std49, std50;
};
extern feq_gen_Common_stdun_com_d_ feq_gen_stdun_com_d_;
struct Common_subcom_ {
    real prat, grat;
};
extern Common_subcom_ subcom_;
struct Common_svncom_ {
    integer feq_gen_svn_rev_d_, feq_gen_svn_mod_d_;
};
extern Common_svncom_ svncom_;
struct Common_svncomc_ {
    char url[256], revision[256];
};
extern Common_svncomc_ svncomc_;
struct Common_tabid_ {
    integer feq_gen_num_tabid_d_;
};
extern Common_tabid_ tabid_;
struct Common_tabidc_ {
    char feq_gen_tabid_table_d_[160032];
};
extern Common_tabidc_ tabidc_;
struct Common_typlim_ {
    real q1l, z1l, y1l, t1l, dt1l, a1l, j1l, k1l, dk1l, bet1l, dbet1l, alp1l, 
	    dalp1l, q2l, q3l, a2part, a3part, a2l, a3l, k2l, k3l, y3part, 
	    z3part;
    integer hhtype;
    real z2l, y2l, t2l, dt2l, j2l, dk2l, bet2l, dbet2l, alp2l, dalp2l;
};
extern Common_typlim_ typlim_;
struct Common_typtrn_ {
    real avhf, cdf, betaf, alphaf, y3pf, beta3, alpha3;
};
extern Common_typtrn_ typtrn_;
struct Common_ufcom_ {
    integer apptab, deptab;
    real y1, y2, y3, y4, y5, a1, a4, a5, j3, j4, z1b, z2b, z3b, z4b, yt, tt, 
	    dtt, at, jt, kt, dkt, beta, alpha, qct, qt, alpha1, beta4, hg, ag,
	     bg, cd, cc, g, twog, dalpha, dbeta, qsqr, dz, j4aty3, alpha4;
};
extern Common_ufcom_ ufcom_;
struct Common_ufgated_ {
    doublereal feq_gen_hdatum_d_d_, feq_gen_xe_return_d_, feq_gen_hg_d_d_, feq_gen_qfull_d_d_, feq_gen_xend_d_d_, feq_gen_h1_d_d_, 
	    feq_gen_alpha1_d_d_, feq_gen_a1_d_d_, feq_gen_yvc_return_d_, feq_gen_full_barrel_station_d_, 
	    feq_gen_afull_d_d_, feq_gen_jfull_d_d_, feq_gen_kfull_d_d_, feq_gen_bg_d_d_, feq_gen_z1b_d_d_, feq_gen_cc_d_d_, 
	    feq_gen_concc_d_d_, feq_gen_cd_d_d_, feq_gen_twog_d_d_, feq_gen_eps_d_d_, feq_gen_epsarg_d_d_, feq_gen_epsf_d_d_, 
	    feq_gen_epsabs_d_d_, feq_gen_grav_d_d_, feq_gen_y_return_d_, feq_gen_yc_return_d_, feq_gen_zbex_d_d_, feq_gen_zbvc_d_d_,
	     feq_gen_xe_d_d_, feq_gen_xs_d_d_, feq_gen_fb_ratio_d_, feq_gen_fs_ratio_d_, xvec[2000], yvec[2000], 
	    ycvec[2000], ynvec[2000];
    integer feq_gen_stdout_d_d_, feq_gen_apptab_d_d_, feq_gen_ns_return_d_, feq_gen_ne_return_d_, feq_gen_adrs_yoverd_d_, 
	    feq_gen_rflag_d_d_, feq_gen_full_return_d_, feq_gen_cctab_d_d_;
};
extern Common_ufgated_ ufgated_;
struct Common_ufgc1_ {
    doublereal station[10], feq_gen_invert_z_d_[10], feq_gen_vert_dvec_d_[10], feq_gen_invert_dzdx_d_[10]
	    , feq_gen_sine_theta_d_[9], feq_gen_cosine_theta_d_[9], feq_gen_x_l_d_, feq_gen_z_l_d_, feq_gen_dzdx_l_d_, 
	    feq_gen_ymax_l_d_, feq_gen_x_r_d_, feq_gen_z_r_d_, feq_gen_dzdx_r_d_, feq_gen_ymax_r_d_, feq_gen_sin_theta_d_, feq_gen_vert_d_d_,
	     feq_gen_cos_theta_d_, feq_gen_xsec_ymax_d_[10], qd, xloc;
    integer feq_gen_invert_slope_cat_d_[10], feq_gen_xsec_adrs_d_[10], feq_gen_adrs_l_d_, feq_gen_adrs_r_d_, 
	    feq_gen_channel_variation_d_[9], feq_gen_pris_flag_d_, feq_gen_slope_flag_d_, nxs;
};
extern Common_ufgc1_ ufgc1_;
struct feq_gen_Common_ufgcitm_com_d_ {
    doublereal ufgcitmdtab[1];
    integer ufgcitmitab[1];
    real ufgcitmftab[1];
};
extern feq_gen_Common_ufgcitm_com_d_ feq_gen_ufgcitm_com_d_;
struct feq_gen_Common_ufgcitm_comc_d_ {
    char ufgcitmctab[256];
};
extern feq_gen_Common_ufgcitm_comc_d_ feq_gen_ufgcitm_comc_d_;
struct feq_gen_Common_unit_com_d_ {
    integer feq_gen_unit_knt_d_, feq_gen_unit_status_d_[1024];
};
extern feq_gen_Common_unit_com_d_ feq_gen_unit_com_d_;
struct Common_upgrdc_ {
    char feq_gen_ty13_to_ty43_d_[4], feq_gen_twod_cubic_out_d_[4], feq_gen_upgrade_xsec_tab_d_[4];
};
extern Common_upgrdc_ upgrdc_;
struct Common_version_ {
    real feq_gen_version_number_d_;
};
extern Common_version_ version_;
struct Common_versionc_ {
    char feq_gen_version_date_d_[17];
};
extern Common_versionc_ versionc_;
struct Common_whatos_ {
    integer osis;
};
extern Common_whatos_ whatos_;
struct Common_wxprox_ {
    integer asflag;
    real srd, skew, ek, ck, vslope;
    integer flflag, ihfno, nfl;
    real fldat[6], flen[3], xfl[3], yfl[3];
    integer grflag, ngp;
    real grsrd, xgr[100], ygr[100], x[100], y[100];
    integer gtflag;
    real yshift, xliml, xlimr, scale, xorig;
    integer nflag, nn;
    real nval[40], botn[20], topn[20];
    integer ndflag, nnd;
    real botd[20], topd[20], nndbrk[40];
    integer saflag, nsa, nsat;
    real xsa[20], xsat[20];
    integer xrflag, ipave;
    real embwid, usercf;
    integer xsflag, xtflag;
    real xtsrd;
    integer xtngp, xtnsa;
    real xtxgr[100], xtygr[100], xtxsa[20];
};
extern Common_wxprox_ wxprox_;
struct Common_x43com_ {
    integer adrs43;
    real q43, z43, zb43, y43, t43, dt43, a43, j43, k43, dk43, bet43, dbet43, 
	    alp43, dalp43, ztel43;
    integer stat43;
    real z43old, q43old, z43min;
};
extern Common_x43com_ x43com_;
struct Common_x44com_ {
    integer adrs44;
    real q44, z44, zb44, y44, t44, dt44, a44, j44, k44, dk44, bet44, dbet44, 
	    alp44, dalp44, ztel44;
    integer stat44;
    real y44c;
};
extern Common_x44com_ x44com_;
struct Common_xs0com_ {
    integer adrxs0;
    real q0, z0, zb0, y0, t0, dt0, a0, j0, k0, dk0, bet0, dbet0, alp0, dalp0, 
	    ztel0, vfac, yc0, zc0;
};
extern Common_xs0com_ xs0com_;
struct Common_xs1com_ {
    integer adrxs1;
    real q1, z1, zb1, y1, t1, dt1, a1, j1, k1, dk1, bet1, dbet1, alp1, dalp1, 
	    ztel1, yuptru, z1ty1, z1ty6, z1ty2, z1ty61, z1ty5, z1ty52, z1ty51,
	     z1ty1l;
};
extern Common_xs1com_ xs1com_;
struct Common_xs2com_ {
    integer adrxs2;
    real q2, z2, zb2, y2, t2, dt2, a2, j2, k2, dk2, bet2, dbet2, alp2, dalp2, 
	    ztel2, d2, yclim, yplim, ytrn34, qup61, qup62, y2free;
    integer lftype;
    real q2ty1, y2ty1, q2ty6, y2ty6, z3pty1;
    integer ty6opt, lstype;
    real a2full, k2full, y2p, z2p;
};
extern Common_xs2com_ xs2com_;
struct Common_xs3com_ {
    integer adrxs3;
    real q3, z3, zb3, y3, t3, dt3, a3, j3, k3, dk3, bet3, dbet3, alp3, dalp3, 
	    ztel3, z3p, y3p, y3c, d3, q3c, y3star, q3free, y3free, a3full, 
	    j3z43, cd2t6, ap2t6, bt2t6, cd61t6, ap61t6, bt61t6, cd1, cd2, 
	    cd61, cd6, z3pty6, cd1t6, z3pest, avh2, avh61, bt3atd, ap3atd, 
	    cc2t5, cc5, y3ty52, ycty52, bt2t5, ap2t5, y3ty5, y3lim5, bt3at5, 
	    ap3at5, cd5t4, y3lty2, y3lty5, y3lty1, cc1t5, bt1t5, ap1t5, 
	    y3ty51, ap1t6, bt1t6;
};
extern Common_xs3com_ xs3com_;
struct Common_xs4com_ {
    integer adrxs4;
    real q4, z4, zb4, y4, t4, dt4, a4, j4, k4, dk4, bet4, dbet4, alp4, dalp4, 
	    ztel4, y4c, q4c;
};
extern Common_xs4com_ xs4com_;
struct Common_xscom_ {
    doublereal time;
    integer eflag;
    real sseps;
    integer in, stdout, output, prout, lout;
};
extern Common_xscom_ xscom_;
struct Common_xscomb_ {
    integer npntb, nsubb, navmb, tabb, ndepb, mxpntb, sbb[999];
    real statb, zminb, zmaxb, xb[999], zb[999], nb[200], xstb[21978]	/* 
	    was [999][22] */;
};
extern Common_xscomb_ xscomb_;
struct Common_xscomd_ {
    integer npntd, nsubd, navmd, nvard[200], tabd, ndepd, mxpntd, snflgd, 
	    usgsd, sbd[999];
    real statd, zmind, zmaxd, xd[999], zd[999], nd[200], xstd[21978]	/* 
	    was [999][22] */, snd[999], lsnd[999], natyd[1800]	/* was [9][
	    200] */, yatnd[1800]	/* was [9][200] */;
    integer nnyd[200];
    real ysmxd[200];
};
extern Common_xscomd_ xscomd_;
struct Common_xscomu_ {
    integer npntu, nsubu, navmu, nvaru[200], tabu, ndepu, mxpntu, snflgu, 
	    usgsu, sbu[999];
    real statu, zminu, zmaxu, xu[999], zu[999], nu[200], xstu[21978]	/* 
	    was [999][22] */, snu[999], lsnu[999], natyu[1800]	/* was [9][
	    200] */, yatnu[1800]	/* was [9][200] */;
    integer nnyu[200];
    real ysmxu[200];
};
extern Common_xscomu_ xscomu_;
struct Common_xtadd_ {
    doublereal easting, northing;
    real feq_gen_slot_depth_d_, dinvert;
    integer feq_gen_ws_tab_d_;
};
extern Common_xtadd_ xtadd_;
struct Common_xtaddc_ {
    char gisid[16], tabid[16], feq_gen_ws_tabid_d_[16];
};
extern Common_xtaddc_ xtaddc_;
struct Common_y1gy2_ {
    real zsbrdf;
    integer conf, outun;
    real feq_gen_d_d_;
};
extern Common_y1gy2_ y1gy2_;
struct Common_y1gy2c_ {
    char feq_gen_class_d_[8];
};
extern Common_y1gy2c_ y1gy2c_;
struct feq_gen_Common_y43_to_y4_d_ {
    real mexit, qsqr, g;
    integer tab4, stdouta;
};
extern feq_gen_Common_y43_to_y4_d_ feq_gen_y43_to_y4_d_;
struct feq_gen_Common_y4_to_43_d_ {
    real g, m4, qsqr, zb43, zb3, costheta;
    integer tab43, tabexit;
};
extern feq_gen_Common_y4_to_43_d_ feq_gen_y4_to_43_d_;
struct Common_y4swc_ {
    doublereal hg;
    integer std6, gety2;
    real hdatum, z4b, z1;
};
extern Common_y4swc_ y4swc_;
}
#endif
