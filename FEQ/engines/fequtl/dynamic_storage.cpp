#include "common.hpp"
extern "C" {
int feq_gen_get_item_limits_storage_d_(integer *stdout, char *string, integer *maxn, char *just, integer *n, integer *feq_gen_feq_storage_item_start_d_, integer 
	*feq_gen_feq_storage_item_end_d_, integer *feq_gen_feq_storage_head_start_d_, integer *feq_gen_feq_storage_head_end_d_, ftnlen 
	string_len, ftnlen just_len);
// Dynamic local storage. Source: fqshrlin.for:1453
int feq_gen_get_item_limits_d_(integer *stdout, char *string, integer *maxn, char *just, integer *n, integer *feq_gen_feq_storage_item_start_d_, integer 
	*feq_gen_feq_storage_item_end_d_, ftnlen 
	string_len, ftnlen just_len) {
    std::vector<integer> feq_gen_feq_storage_head_start_d_(feq::checked_extent(static_cast<std::int64_t>(*maxn)));
    std::vector<integer> feq_gen_feq_storage_head_end_d_(feq::checked_extent(static_cast<std::int64_t>(*maxn)));
    return feq_gen_get_item_limits_storage_d_(stdout, string, maxn, just, n, feq_gen_feq_storage_item_start_d_, feq_gen_feq_storage_item_end_d_, feq_gen_feq_storage_head_start_d_.data(), feq_gen_feq_storage_head_end_d_.data(), string_len, just_len);
}
int feq_gen_twodtabfit_storage_d_(integer *stdout, integer *table, integer *nhu, integer *npfd, integer *maxrow, real *hdatum, doublereal *feq_storage_huall, doublereal *feq_storage_freedrop, doublereal *feq_storage_pfd, doublereal *
	feq_storage_qmat, char *source, integer *verbose, integer *ftp, integer *eflag, integer *ftpup, doublereal *feq_storage_pqppfd, doublereal *feq_storage_pqphu, doublereal *
	feq_storage_ppqppfdphu, doublereal *feq_storage_ppqphuppfd, doublereal *feq_storage_pfdropphu, char *
	feq_storage_pqppfdadj, char *feq_storage_pqphuadj, ftnlen source_len, ftnlen pqppfdadj_len, ftnlen pqphuadj_len);
// Dynamic local storage. Source: newlookup.for:658
int twodtabfit_(integer *stdout, integer *table, integer *nhu, integer *npfd, integer *maxrow, real *hdatum, doublereal *feq_storage_huall, doublereal *feq_storage_freedrop, doublereal *feq_storage_pfd, doublereal *
	feq_storage_qmat, char *source, integer *verbose, integer *ftp, integer *eflag, integer *ftpup, ftnlen source_len) {
    std::vector<doublereal> feq_storage_pqppfd(feq::checked_extent(static_cast<std::int64_t>(*maxrow), static_cast<std::int64_t>(*npfd)));
    std::vector<doublereal> feq_storage_pqphu(feq::checked_extent(static_cast<std::int64_t>(*maxrow), static_cast<std::int64_t>(*npfd)));
    std::vector<doublereal> feq_storage_ppqppfdphu(feq::checked_extent(static_cast<std::int64_t>(*maxrow), static_cast<std::int64_t>(*npfd)));
    std::vector<doublereal> feq_storage_ppqphuppfd(feq::checked_extent(static_cast<std::int64_t>(*maxrow), static_cast<std::int64_t>(*npfd)));
    std::vector<doublereal> feq_storage_pfdropphu(feq::checked_extent(static_cast<std::int64_t>(*nhu)));
    std::vector<char> feq_storage_pqppfdadj(feq::checked_extent(static_cast<std::int64_t>(*maxrow), static_cast<std::int64_t>(*npfd)));
    std::vector<char> feq_storage_pqphuadj(feq::checked_extent(static_cast<std::int64_t>(*maxrow), static_cast<std::int64_t>(*npfd)));
    return feq_gen_twodtabfit_storage_d_(stdout, table, nhu, npfd, maxrow, hdatum, feq_storage_huall, feq_storage_freedrop, feq_storage_pfd, feq_storage_qmat, source, verbose, ftp, eflag, ftpup, feq_storage_pqppfd.data(), feq_storage_pqphu.data(), feq_storage_ppqppfdphu.data(), feq_storage_ppqphuppfd.data(), feq_storage_pfdropphu.data(), feq_storage_pqppfdadj.data(), feq_storage_pqphuadj.data(), source_len, 1, 1);
}
}
