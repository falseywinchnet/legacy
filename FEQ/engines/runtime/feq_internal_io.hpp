// Internal and external record descriptors have different layouts on 64-bit
// hosts. Copy their shared meanings into a real cilist object; never alias one
// descriptor type as the other. The runtime executes one statement at a time.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_INTERNAL_IO_HPP
#define FEQ_INTERNAL_IO_HPP
#include "f2c.h"
inline cilist* feq_internal_list(const icilist* input) {
    static cilist list{};
    list.cierr = input->icierr;
    list.ciunit = 0;
    list.ciend = input->iciend;
    list.cifmt = input->icifmt;
    list.cirec = 0;
    return &list;
}
#endif
