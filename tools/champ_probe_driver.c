/* Research-only host for unmodified CHAMP p-code bodies. Cross-compile with
 * i686-w64-mingw32-gcc -O0 -static ... -loleaut32. The product does not use VB.
 * Runtime initialization follows David Zimmer's VB6 binary-reuse research.
 */
#include <windows.h>
#include <oleauto.h>
#include <stdio.h>
#include <stdint.h>

static uint32_t object_info[20], object_table[30], descriptor[30];
static uint32_t pool[2048], globals[2048], project[64];

static void* routine(const char* filename, unsigned pcode_length) {
    unsigned char* bytes = VirtualAlloc(0, 8192, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    FILE* file = fopen(filename, "rb");
    if (!file || !bytes) exit(2);
    fread(bytes, 1, 4096, file); fclose(file);
    *(uint32_t*)(bytes + pcode_length) = (uint32_t)object_info;
    unsigned char* stub = bytes + 4096;
    stub[0] = 0xba; *(uint32_t*)(stub + 1) = (uint32_t)(bytes + pcode_length);
    stub[5] = 0xb9; *(uint32_t*)(stub + 6) = (uint32_t)GetProcAddress(GetModuleHandleA("msvbvm60.dll"), "ProcCallEngine");
    stub[10] = 0xff; stub[11] = 0xe1;
    return stub;
}

int main(int argc, char** argv) {
    if (argc != 4) return 2;
    HMODULE runtime = LoadLibraryA("msvbvm60.dll");
    if (!runtime) return 3;
    void* (__stdcall *initialize)(int, int, int) = (void*)GetProcAddress(runtime, "CreateIExprSrvObj");
    initialize(0, 4, 0);
    object_info[1] = (uint32_t)object_table;
    object_info[6] = (uint32_t)descriptor;
    object_info[13] = (uint32_t)pool;
    descriptor[4] = (uint32_t)globals;
    object_table[5] = (uint32_t)project;
    FILE* input = fopen(argv[2], "rb");
    FILE* output = fopen(argv[3], "wb");
    if (!input || !output) return 2;
    float v[17];
    if (!strcmp(argv[1], "interpolate")) {
        float (__stdcall *fn)(VARIANT*, VARIANT*, VARIANT*, VARIANT*, VARIANT*) = routine("interpolate.bin", 0x88);
        while (fread(v, 20, 1, input) == 1) {
            VARIANT values[5];
            for (int i = 0; i < 5; ++i) { VariantInit(&values[i]); values[i].vt = VT_R4; values[i].fltVal = v[i]; }
            float value = fn(values, values + 1, values + 2, values + 3, values + 4);
            fwrite(&value, 4, 1, output);
        }
    } else if (!strcmp(argv[1], "line")) {
        void (__stdcall *fn)(float*, float*, float*, float*, float*, float*, float*) = routine("line.bin", 0x68);
        while (fread(v, 16, 1, input) == 1) {
            float result[3]; fn(v, v + 1, v + 2, v + 3, result, result + 1, result + 2);
            fwrite(result, 12, 1, output);
        }
    } else if (!strcmp(argv[1], "intersection")) {
        void (__stdcall *fn)(float*, float*, float*, float*, float*, float*) = routine("intersection.bin", 0x68);
        while (fread(v, 24, 1, input) == 1) {
            fn(v, v + 1, v + 2, v + 3, v + 4, v + 5);
            fwrite((char*)globals + 0x90, 8, 1, output);
        }
    } else if (!strcmp(argv[1], "polygon")) {
        void (__stdcall *fn)(VARIANT*, SAFEARRAY**, SAFEARRAY**, short*) = routine("polygon.bin", 0x98);
        while (fread(v, 68, 1, input) == 1) {
            short count = (short)v[0];
            SAFEARRAY* x = SafeArrayCreateVector(VT_R4, 1, count);
            SAFEARRAY* y = SafeArrayCreateVector(VT_R4, 1, count);
            memcpy(x->pvData, v + 1, count * 4); memcpy(y->pvData, v + 9, count * 4);
            VARIANT result; VariantInit(&result); fn(&result, &x, &y, &count);
            if (result.vt != VT_R8) return 4;
            fwrite(&result.dblVal, 8, 1, output);
            VariantClear(&result); SafeArrayDestroy(x); SafeArrayDestroy(y);
        }
    } else return 2;
    fclose(input); fclose(output); return 0;
}
