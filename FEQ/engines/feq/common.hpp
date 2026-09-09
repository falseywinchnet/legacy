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
struct Common_bnelem_ {
    integer stflag, ftid;
    real a1[8400], a2[8400], b1[8400], b2[8400], dxvec[8400], dzvec[8400], k1[
	    8400], k2[8400], ka[8400], kd[8400], my[8400], mq[8400], q1[8400],
	     q2[8400], q3[8400], t1[8400], t2[8400], xvec[8400], y1[8400], y2[
	    8400], y3[8400], zvec[8400], momvec[8400], impvec[8400], volvec[
	    8400], flwvec[8400], wxvec1[8400], wxvec2[8400], wxvec[8400], ma1[
	    8400], mq1[8400], ma2[8400], mq2[8400], sumvec[8400], sdvec[8400];
};
extern Common_bnelem_ bnelem_;
struct Common_bnothc_ {
    char bnodid[134400];
};
extern Common_bnothc_ bnothc_;
struct Common_bnothr_ {
    real qpvec[8400], uvx[8400], uvy[8400], wsvec[8400];
    integer hltab[8400], nsec[8400];
    real bncorq[8400], bncory[8400], zivec[2200], zilim[2200], stdfld[8400];
    integer geqopt;
    real bnmaxy[8400];
    integer addvec[2200], geqvec[2200], feq_gen_non_conv_bnode_d_[8400];
    real kadjvec[8400];
};
extern Common_bnothr_ bnothr_;
struct Common_bnpond_ {
    real coefin[8400], pond1[8400], pond2[8400], ycut[8400], bpond[2200], 
	    bpmax[2200];
};
extern Common_bnpond_ bnpond_;
struct Common_bnrslt_ {
    doublereal tqmax[8400], tqmin[8400], tzmax[8400];
    real qmax[8400], qmin[8400], zmax[8400], vmax[8400];
};
extern Common_bnrslt_ bnrslt_;
struct feq_gen_Common_brhd_com_d_ {
    doublereal brhddtab[1];
    integer brhditab[5];
    real brhdftab[5];
};
extern feq_gen_Common_brhd_com_d_ feq_gen_brhd_com_d_;
struct feq_gen_Common_brhd_comc_d_ {
    char brhdctab[256];
};
extern feq_gen_Common_brhd_comc_d_ feq_gen_brhd_comc_d_;
struct Common_cb_ {
    real ybmax, ksub, kfree, dkfree, tb, ab, maxab, qrf, dqrf, sbc, dsbc;
    integer sgn;
    real hr, hs;
};
extern Common_cb_ cb_;
struct Common_clcom_ {
    integer iend, nxt, narg;
};
extern Common_clcom_ clcom_;
struct Common_clcomc_ {
    char cl[127], namvec[384];
};
extern Common_clcomc_ clcomc_;
struct Common_code14_ {
    integer feq_gen_code14_present_d_;
};
extern Common_code14_ code14_;
struct Common_crcom_ {
    char cr[1];
};
extern Common_crcom_ crcom_;
struct Common_datetime_ {
    char feq_gen_version_run_date_time_string_d_[95];
};
extern Common_datetime_ datetime_;
struct Common_difcom_ {
    doublereal clsr1[128], clsr2[128];
};
extern Common_difcom_ difcom_;
struct Common_dssdif_ {
    doublereal jtvec[513], feq_gen_tsfdt_dss_d_, feq_gen_half_tsfdt_dss_d_, feq_gen_buf_dt_d_;
    integer feq_gen_dss_index_diff_d_[200], feq_gen_time_step_diff_d_[200];
    real tmpvec[513];
};
extern Common_dssdif_ dssdif_;
struct Common_dssdifc_ {
    char feq_gen_path_name_diff_d_[10240];
};
extern Common_dssdifc_ dssdifc_;
struct Common_dtcom_ {
    real feq_gen_auto_d_, siter, high, low, maxdt, mindt, hfac, lfac, bwt, dwt, isiter;
};
extern Common_dtcom_ dtcom_;
struct Common_dtendef_ {
    integer feq_gen_def_dten_lui_d_;
    real feq_gen_def_dten_yd_d_, feq_gen_def_dten_bz_d_, feq_gen_def_dten_wz_d_, feq_gen_def_dten_wc_d_, 
	    feq_gen_def_dten_uaq_d_, feq_gen_def_dten_avda_d_, feq_gen_def_dten_orfcd_d_;
    integer feq_gen_def_dten_orif_tab_num_d_, feq_gen_def_dten_unit_area_vol_tab_num_d_;
};
extern Common_dtendef_ dtendef_;
struct Common_dtendefc_ {
    char feq_gen_def_dten_orif_tabid_d_[16], feq_gen_def_dten_unit_area_vol_tabid_d_[16];
};
extern Common_dtendefc_ dtendefc_;
struct Common_endrun_ {
    integer feq_gen_jde_run_d_, feq_gen_moff_end_run_d_;
};
extern Common_endrun_ endrun_;
struct Common_enelem_ {
    real ae1[8400], ae2[8400], mye[8400], mqe[8400], qe1[8400], qe2[8400], 
	    qe3[8400], ye1[8400], ye2[8400], ye3[8400], ze[8400], te1[8400], 
	    te2[8400];
};
extern Common_enelem_ enelem_;
struct Common_enothc_ {
    char enodid[134400];
};
extern Common_enothc_ enothc_;
struct Common_enothr_ {
    integer bdyvec[8400], resvec[8400];
    real encorq[8400], encory[8400], enmaxy[8400], enminy[8400];
    integer feq_gen_non_conv_enode_d_[8400];
};
extern Common_enothr_ enothr_;
struct Common_enrslt_ {
    doublereal ftqmax[8400], ftqmin[8400], ftzmax[8400];
    real fnqmax[8400], fnzmax[8400], fnqmin[8400];
    integer tostore[8400], flownode[8400], othernode[8400];
    real qstore[8400], zstore[8400];
};
extern Common_enrslt_ enrslt_;
struct Common_eqsum_ {
    integer feq_gen_eqsum_knt_d_[15];
};
extern Common_eqsum_ eqsum_;
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
struct Common_gate1_ {
    integer ngate;
    real gopen[52];
    integer feq_gen_fclass_code_d_[52];
};
extern Common_gate1_ gate1_;
struct Common_gate2_ {
    char gname[816], fclass[416];
};
extern Common_gate2_ gate2_;
struct Common_genscn_ {
    doublereal feq_gen_genscn_jtime_d_;
    integer feq_gen_feo_unit_d_, feq_gen_tsd_unit_d_, feq_gen_ftf_unit_d_, feq_gen_genscn_nout_d_, 
	    feq_gen_genscn_record_knt_d_, feq_gen_genscn_pout_d_[20000];
    real feq_gen_genscn_out_vec_d_[40000];
};
extern Common_genscn_ genscn_;
struct Common_gravcm_ {
    real grav, twog, halfg;
};
extern Common_gravcm_ gravcm_;
struct feq_gen_Common_grid_datum_d_ {
    char feq_gen_g_zone_d_[8], feq_gen_g_hgrid_d_[8], feq_gen_g_vdatum_d_[8], feq_gen_g_unitsys_d_[8], feq_gen_g_basis_d_[
	    8];
};
extern feq_gen_Common_grid_datum_d_ feq_gen_grid_datum_d_;
struct Common_hiiqnscmn_ {
    integer feq_gen_hi_iq_ns_vars_d_[100], feq_gen_hi_iq_ns_fp_d_[100], feq_gen_hi_iq_ns_bp_d_[100], 
	    feq_gen_hi_iq_ns_avail_p_d_, feq_gen_hi_iq_ns_active_p_d_;
};
extern Common_hiiqnscmn_ hiiqnscmn_;
struct Common_homec_ {
    char home[128], ghome[128], feq_gen_ghome_out_d_[128], stdext[128];
};
extern Common_homec_ homec_;
struct Common_inbr_ {
    integer inbrus[9999];
};
extern Common_inbr_ inbr_;
struct Common_inen_ {
    integer usnsrt[8400];
};
extern Common_inen_ inen_;
struct Common_inenc_ {
    char inenus[42000];
};
extern Common_inenc_ inenc_;
struct Common_infcmc_ {
    char diffus[4], point[4], wind[4], soper[4], underf[4];
};
extern Common_infcmc_ infcmc_;
struct Common_infcom_ {
    integer ftp, lext, lpnt, nbn, nbra, nbra2, nblk, nex, ept;
    real sfac;
    integer brpt[17600]	/* was [8][2200] */, emc[120000], exnodt[75600]	/* 
	    was [9][8400] */;
    real mf[10];
    integer pfpnt[30]	/* was [3][10] */, pout[250], nout, unit, opblk[100];
    real epsb, epssys, epssy2;
    integer maxit, mknt, prtint;
    real qeps, qchop;
    integer ifrz;
    real dtvec[10], taufac, mre, fac;
    integer bwfdsn, fffdsn;
    real zi;
    integer lapd, getdsn, putdsn;
};
extern Common_infcom_ infcom_;
struct Common_irrig_ {
    integer feq_gen_irrig_knt_d_, feq_gen_irrig_triba_row_d_[4200], feq_gen_irrig_lui_apply_d_[4200], 
	    feq_gen_irrig_lui_compute_d_[4200], feq_gen_irrig_source_d_[4200], 
	    feq_gen_irrig_control_tab_d_[4200];
};
extern Common_irrig_ irrig_;
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
struct feq_gen_Common_macro_c_d_ {
    char feq_gen_macro_body_d_[117600], feq_gen_macro_stack_d_[19600], feq_gen_macro_arg_d_[9600];
};
extern feq_gen_Common_macro_c_d_ feq_gen_macro_c_d_;
struct feq_gen_Common_macro_i_d_ {
    integer feq_gen_macro_stack_top_d_, feq_gen_last_macro_d_, feq_gen_last_body_d_, feq_gen_last_arg_d_, 
	    feq_gen_macro_body_pnt_d_[200], feq_gen_macro_body_knt_d_[200], feq_gen_macro_arg_pnt_d_[200]
	    , feq_gen_macro_arg_knt_d_[200], feq_gen_macro_arg_len_d_[600], feq_gen_macro_line_len_d_[
	    600];
};
extern feq_gen_Common_macro_i_d_ feq_gen_macro_i_d_;
struct Common_matcom2_ {
    real pdavec2[744000], rhs2[24800];
};
extern Common_matcom2_ matcom2_;
struct Common_matcom_ {
    integer matblk, numeq, nentry, feq_gen_r_d_[24800], feq_gen_c_d_[24801], eqend[24800], 
	    varid[24800], begrow[4401], endcon[4401], mbtype[4401], add[16800]
	    ;
    real pdavec[744000], rhs[24800], feq_gen_hi_iq_ns_fac_d_[24800];
    integer feq_gen_hi_iq_ns_state_d_[24800];
};
extern Common_matcom_ matcom_;
struct Common_mhenry_ {
    integer typmch;
    real hgmch;
};
extern Common_mhenry_ mhenry_;
struct Common_miscon_ {
    integer pagesp, pndflg;
    real exttol, sqreps, dhstar, qpcon, reseps, c52eps, epsb2, lprdy, lprmin, 
	    mxslot;
};
extern Common_miscon_ miscon_;
struct Common_mktbindx_ {
    integer feq_gen_ftab_type_d_[10002], feq_gen_data_pnt_d_[10002], feq_gen_index_knt_d_, stdindex;
};
extern Common_mktbindx_ mktbindx_;
struct Common_mktbindxc_ {
    char feq_gen_ftab_fn_d_[2560512], ftabid[160032], feq_gen_make_tab_index_d_[4];
};
extern Common_mktbindxc_ mktbindxc_;
struct Common_namcom_ {
    char bwfnam[256], fffnam[256], tsfnam[256], sphead[3500]	/* was [250][
	    2] */, putnam[256], getnam[256];
};
extern Common_namcom_ namcom_;
struct Common_nzdcom_ {
    integer nzdtyp[2200];
    real yatone[2200], yathaf[2200];
};
extern Common_nzdcom_ nzdcom_;
struct Common_offcom_ {
    integer offvec[35];
};
extern Common_offcom_ offcom_;
struct feq_gen_Common_rc_com_d_ {
    doublereal rcbdtab[40];
    integer rcbitab[80];
    real rcbftab[80];
};
extern feq_gen_Common_rc_com_d_ feq_gen_rc_com_d_;
struct feq_gen_Common_rc_comc_d_ {
    char rcbctab[8192];
};
extern feq_gen_Common_rc_comc_d_ feq_gen_rc_comc_d_;
struct Common_rdcom_ {
    doublereal jtin[6000], jtvec[6005], valbin[1], feq_gen_old_cum_d_[160], feq_gen_new_cum_d_[
	    160];
    real valain[6000];
    integer feq_gen_num_ts_f_d_, unin[160], feq_gen_rd_rec_d_[160], lsthd[160], ltry[160], 
	    minrow[160], maxrow[160], feq_gen_dss_index_in_d_[160], feq_gen_time_step_in_d_[160]
	    ;
    real tmpvec[6005], feq_gen_ts_conversion_factor_d_[200];
    integer feq_gen_id_knt_d_, feq_gen_delete_list_d_[160];
};
extern Common_rdcom_ rdcom_;
struct Common_rdcomc_ {
    char namin[40960], feq_gen_ts_id_for_file_table_d_[3200];
};
extern Common_rdcomc_ rdcomc_;
struct feq_gen_Common_select_cmn_d_ {
    integer feq_gen_select_stack_d_[300]	/* was [3][100] */, top;
};
extern feq_gen_Common_select_cmn_d_ feq_gen_select_cmn_d_;
struct feq_gen_Common_select_cmnc_d_ {
    char feq_gen_select_stack_line_d_[19600];
};
extern feq_gen_Common_select_cmnc_d_ feq_gen_select_cmnc_d_;
struct feq_gen_Common_selector_c_d_ {
    char symbol[1600];
};
extern feq_gen_Common_selector_c_d_ feq_gen_selector_c_d_;
struct feq_gen_Common_selector_i_d_ {
    integer feq_gen_symbol_class_d_[100], feq_gen_symbol_value_d_[100], feq_gen_last_symbol_d_;
};
extern feq_gen_Common_selector_i_d_ feq_gen_selector_i_d_;
struct Common_spouta_ {
    integer feq_gen_line_knt_d_, feq_gen_spout_knt_d_, feq_gen_spout_item_d_[8], feq_gen_need_lookup_d_, 
	    feq_gen_spout_item_value_d_[8], feq_gen_spout_main_channel_table_d_[250], 
	    feq_gen_spout_style_d_, stdspo, feq_gen_spo_knt_d_, stdspout;
};
extern Common_spouta_ spouta_;
struct Common_spoutc_ {
    char feq_gen_spout_item_label_d_[80], feq_gen_spout_item_name_d_[64], feq_gen_extra_buffer_d_[16000]	
	    /* was [250][8] */;
};
extern Common_spoutc_ spoutc_;
struct feq_gen_Common_stdun_com_d_ {
    integer std5, std6, std7, std10, std48, std49, std50;
};
extern feq_gen_Common_stdun_com_d_ feq_gen_stdun_com_d_;
struct Common_svncom_ {
    integer feq_gen_svn_rev_d_, feq_gen_svn_mod_d_;
};
extern Common_svncom_ svncom_;
struct Common_svncomc_ {
    char url[256], revision[256];
};
extern Common_svncomc_ svncomc_;
struct feq_gen_Common_symbol_c_d_ {
    char symbol[4000];
};
extern feq_gen_Common_symbol_c_d_ feq_gen_symbol_c_d_;
struct feq_gen_Common_symbol_i_d_ {
    integer feq_gen_symbol_class_d_[250], feq_gen_symbol_value_d_[250], feq_gen_last_symbol_d_;
};
extern feq_gen_Common_symbol_i_d_ feq_gen_symbol_i_d_;
struct feq_gen_Common_tabbrh_com_d_ {
    doublereal tabbrhdtab[1];
    integer tabbrhitab[2];
    real tabbrhftab[2];
};
extern feq_gen_Common_tabbrh_com_d_ feq_gen_tabbrh_com_d_;
struct feq_gen_Common_tabbrh_comc_d_ {
    char tabbrhctab[256];
};
extern feq_gen_Common_tabbrh_comc_d_ feq_gen_tabbrh_comc_d_;
struct feq_gen_Common_tabhd_com_d_ {
    doublereal tabhddtab[1];
    integer tabhditab[2];
    real tabhdftab[2];
};
extern feq_gen_Common_tabhd_com_d_ feq_gen_tabhd_com_d_;
struct feq_gen_Common_tabhd_comc_d_ {
    char tabhdctab[768];
};
extern feq_gen_Common_tabhd_comc_d_ feq_gen_tabhd_comc_d_;
struct Common_tabid_ {
    integer feq_gen_num_tabid_d_;
};
extern Common_tabid_ tabid_;
struct Common_tabidc_ {
    char feq_gen_tabid_table_d_[160032];
};
extern Common_tabidc_ tabidc_;
struct Common_tamcom_ {
    doublereal feq_gen_l_tai_d_, feq_gen_l_taq_d_, feq_gen_l_taqbn_d_, feq_gen_l_wsi_d_, feq_gen_l_wsq_d_, feq_gen_dlay_k_d_[4201], 
	    feq_gen_dlay_q1_d_[4200], feq_gen_dlay_q2_d_[4200], feq_gen_dlay_k_over_dt_d_[4200], 
	    feq_gen_dlay_exp_of_dt_over_k_d_[4200];
    integer feq_gen_tam_ipnt_d_, feq_gen_tam_fpnt_d_, feq_gen_dten_knt_d_, feq_gen_dlay_knt_d_, feq_gen_tunit_knt_d_, 
	    feq_gen_tam_itab_d_[102000];
    real feq_gen_tam_ftab_d_[8400], feq_gen_dten_orfcd_d_[4200];
    integer feq_gen_dten_uadv_tab_d_[4200], feq_gen_dten_orf_tab_d_[4200], feq_gen_dten_rout_tab_d_[4200]
	    ;
    real feq_gen_dten_yd_d_[4200], feq_gen_dten_wz_d_[4200], feq_gen_dten_q1_d_[4200], feq_gen_dten_q1p_d_[4200], 
	    feq_gen_dten_s1_d_[4200], feq_gen_dten_q2_d_[4200], feq_gen_dten_q2p_d_[4200], feq_gen_dten_s2_d_[
	    4200];
    integer feq_gen_dlay_qpnt_d_[4200], feq_gen_dlay_nlr_d_[4201];
    real feq_gen_dten_bz_d_[4200], feq_gen_dten_wc_d_[4200], feq_gen_dten_uaq_d_[4200], feq_gen_dten_avda_d_[4200]
	    ;
    integer feq_gen_dten_orif_tab_num_d_, feq_gen_dten_unit_area_vol_tab_num_d_;
};
extern Common_tamcom_ tamcom_;
struct Common_timcom_ {
    integer itick, itick0, itick1, itick2, cmpext, cmpint, slvext, slvint;
    real feq_gen_min_time_step_d_;
};
extern Common_timcom_ timcom_;
struct Common_timetab_ {
    integer stddtout, feq_gen_tab_for_maxdt_d_;
};
extern Common_timetab_ timetab_;
struct Common_timetabc_ {
    char feq_gen_make_dt_tab_d_[256], feq_gen_use_maxdt_tab_d_[16];
};
extern Common_timetabc_ timetabc_;
struct Common_titlec_ {
    char title[24120];
};
extern Common_titlec_ titlec_;
struct Common_titlei_ {
    integer feq_gen_title_n_d_;
};
extern Common_titlei_ titlei_;
struct feq_gen_Common_ts_mngt_c_d_ {
    char feq_gen_ts_id_d_[3200];
};
extern feq_gen_Common_ts_mngt_c_d_ feq_gen_ts_mngt_c_d_;
struct feq_gen_Common_ts_mngt_n_d_ {
    integer feq_gen_num_ts_d_, feq_gen_num_dest_d_, feq_gen_next_link_d_, feq_gen_source_cat_d_[200], 
	    feq_gen_source_address_d_[200], feq_gen_dest_cat_d_[400], feq_gen_dest_pnt_d_[400], 
	    feq_gen_dest_link_d_[400];
};
extern feq_gen_Common_ts_mngt_n_d_ feq_gen_ts_mngt_n_d_;
struct Common_tsfcom_ {
    doublereal tsfbuf[65536]	/* was [512][128] */, bjtime[512];
    real tsfrat[65536]	/* was [512][128] */;
    integer bwyr[512], bord[512];
    real triba[67200]	/* was [8400][8] */;
    integer lentry, ndfval, tsfdsn, nbuff, nluse, seflag;
    real dtend;
    integer lhead, gstart[17], gend[17], tsftyp, lagtsf;
    real tafac[2200];
    integer feq_gen_dtsf_rec_d_, frcst;
};
extern Common_tsfcom_ tsfcom_;
struct feq_gen_Common_unit_com_d_ {
    integer feq_gen_unit_knt_d_, feq_gen_unit_status_d_[1024];
};
extern feq_gen_Common_unit_com_d_ feq_gen_unit_com_d_;
struct Common_upgrdc_ {
    char feq_gen_ty13_to_ty43_d_[4], feq_gen_twod_cubic_out_d_[4], feq_gen_upgrade_xsec_tab_d_[4];
};
extern Common_upgrdc_ upgrdc_;
struct Common_usintp_ {
    integer usbrin[9999], usenin[29998];
};
extern Common_usintp_ usintp_;
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
struct Common_wincom_ {
    integer wintab;
    real airwat, vamin, cdmin, vamax, cdmax, vadif, cddif, wdfvec[2200];
};
extern Common_wincom_ wincom_;
struct Common_wrcom_ {
    integer nfout, feq_gen_dss_out_count_d_, unout[1200], braout[1200], nodout[1200], 
	    icdout[1200], feq_gen_wr_rec_d_[1200], feq_gen_dss_index_out_d_[1200], 
	    feq_gen_dss_buffer_column_d_[1200], feq_gen_time_step_out_d_[1200], feq_gen_irr_dt_d_, 
	    actout[1200];
};
extern Common_wrcom_ wrcom_;
struct Common_wrcomc_ {
    char namout[307200];
};
extern Common_wrcomc_ wrcomc_;
struct Common_wrcomd_ {
    doublereal runquad[1200], oldf[1200], quadfactor;
};
extern Common_wrcomd_ wrcomd_;
struct Common_xscom_ {
    doublereal time;
    integer eflag;
    real sseps;
    integer in, stdout, output, prout, lout;
};
extern Common_xscom_ xscom_;
}
#endif
