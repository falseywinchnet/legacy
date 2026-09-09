#include "f2c.h"
#include "fio.h"
#undef getc

int feq_compat_getc(FILE* stream) {
    int value = getc(stream);
    if (value == '\r' && f__curunit && f__curunit->ufmt) {
        int next = getc(stream);
        if (next == '\n') return '\n';
        if (next != EOF) ungetc(next, stream);
    }
    return value;
}
