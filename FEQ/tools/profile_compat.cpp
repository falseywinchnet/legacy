// Connect the independently implemented profile solver to the research engine.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/profile_matrix.hpp>
#include "common.hpp"

extern "C" {
#if defined(FEQ_RESEARCH_MATRIX_TRACE)
void feq_research_trace_matrix();
#endif
integer s_wsfe(cilist*);
integer do_fio(integer*, char*, ftnlen);
integer e_wsfe();
[[noreturn]] int s_stop(char*, ftnlen);

int profac_(integer* output_unit) {
#if defined(FEQ_RESEARCH_MATRIX_TRACE)
    feq_research_trace_matrix();
#endif
    if (matcom_.numeq <= 0 || matcom_.numeq > 24800) {
        throw std::invalid_argument("Profile equation count exceeds the released storage.");
    }
    const std::size_t equations = static_cast<std::size_t>(matcom_.numeq);
    try {
        feq::factor_profile(matcom_.matblk,
            feq::IndexedView<const std::int32_t>(matcom_.begrow,4401),
            feq::IndexedView<const std::int32_t>(matcom_.endcon,4401),
            feq::IndexedView<const std::int32_t>(matcom_.mbtype,4401),
            feq::IndexedView<const std::int32_t>(matcom_.feq_gen_c_d_,equations+1,0),
            feq::IndexedView<const std::int32_t>(matcom_.feq_gen_r_d_,equations),
            feq::IndexedView<float>(matcom_.pdavec,744000));
    } catch (const feq::ProfileMatrixError& error) {
        char invalid[] = "(/,'*BUG:XXX* Invalid matrix block type:',I5,' in PROFAC.')";
        char zero[] = "(/,'*ERR/BUG:XXX* Zero pivot in matrix. Offset=',I7,' Row=',I5,' Column=',I5)";
        cilist record = {0,*output_unit,0,error.kind == feq::ProfileMatrixError::invalid_block ? invalid : zero,0};
        integer one = 1;
        integer offset = error.offset;
        integer row = error.row;
        integer column = error.column;
        s_wsfe(&record);
        do_fio(&one,reinterpret_cast<char*>(&offset),sizeof(offset));
        if (error.kind == feq::ProfileMatrixError::zero_pivot) {
            do_fio(&one,reinterpret_cast<char*>(&row),sizeof(row));
            do_fio(&one,reinterpret_cast<char*>(&column),sizeof(column));
        }
        e_wsfe();
        char message[] = "Abnormal stop: errors found.";
        s_stop(message,sizeof(message)-1);
    }
    return 0;
}

int proslv_(integer* count, real* coefficients, integer* diagonal,
             integer* lower, real* rhs) {
    if (*count <= 0 || *count > 24800) {
        throw std::invalid_argument("Profile solve requires a positive equation count.");
    }
    const std::size_t equations = static_cast<std::size_t>(*count);
    if (diagonal[*count] <= 0) {
        throw std::invalid_argument("Profile matrix has no diagonal storage.");
    }
    const std::size_t entries = static_cast<std::size_t>(diagonal[*count]);
    feq::solve_profile(*count,
        feq::IndexedView<const std::int32_t>(diagonal,equations+1,0),
        feq::IndexedView<const std::int32_t>(lower,equations),
        feq::IndexedView<const float>(coefficients,entries),
        feq::IndexedView<float>(rhs,equations));
    return 0;
}

} // extern "C"
