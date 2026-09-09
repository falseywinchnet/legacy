; _grule_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x67c70
00467c70  55                       push      ebp
00467c71  8bec                     mov       ebp, esp
00467c73  b810000000               mov       eax, 0x10
00467c78  e883130800               call      0x4e9000 ; __alloca_probe
00467c7d  53                       push      ebx
00467c7e  56                       push      esi
00467c7f  57                       push      edi
00467c80  8b4508                   mov       eax, dword ptr [ebp + 8]
00467c83  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00467c86  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
00467c89  8945fc                   mov       dword ptr [ebp - 4], eax
00467c8c  894df8                   mov       dword ptr [ebp - 8], ecx
00467c8f  8b45fc                   mov       eax, dword ptr [ebp - 4]
00467c92  8b08                     mov       ecx, dword ptr [eax]
00467c94  8d51ff                   lea       edx, [ecx - 1]
00467c97  894df4                   mov       dword ptr [ebp - 0xc], ecx
00467c9a  8955f0                   mov       dword ptr [ebp - 0x10], edx
00467c9d  8b45f0                   mov       eax, dword ptr [ebp - 0x10]
00467ca0  89c2                     mov       edx, eax
00467ca2  3d00000000               cmp       eax, 0
00467ca7  0f8eb4000000             jle       0x467d61
00467cad  b901000000               mov       ecx, 1
00467cb2  d9e8                     fld1
00467cb4  83fa02                   cmp       edx, 2
00467cb7  7c72                     jl        0x467d2b
00467cb9  8b45f8                   mov       eax, dword ptr [ebp - 8]
00467cbc  c744c8f800000000         mov       dword ptr [eax + ecx*8 - 8], 0
00467cc4  c744c8fc00000000         mov       dword ptr [eax + ecx*8 - 4], 0
00467ccc  8d35209e5900             lea       esi, [0x599e20] ; bits=00000000, f32=0.0
00467cd2  d9c0                     fld       st(0)
00467cd4  dc4e80                   fmul      qword ptr [esi - 0x80]
00467cd7  d8c9                     fmul      st(1)
00467cd9  8d3d38548300             lea       edi, [0x835438]
00467cdf  dc25a89d5900             fsub      qword ptr [0x599da8] ; bits=000000000000f03f, f64=1.0
00467ce5  d9fa                     fsqrt
00467ce7  d8f9                     fdivr     st(1)
00467ce9  dd9ccf78ffffff           fstp      qword ptr [edi + ecx*8 - 0x88]
00467cf0  c704c800000000           mov       dword ptr [eax + ecx*8], 0
00467cf7  c744c80400000000         mov       dword ptr [eax + ecx*8 + 4], 0
00467cff  dc05a89d5900             fadd      qword ptr [0x599da8] ; bits=000000000000f03f, f64=1.0
00467d05  d9c0                     fld       st(0)
00467d07  dc4e80                   fmul      qword ptr [esi - 0x80]
00467d0a  d8c9                     fmul      st(1)
00467d0c  dc25a89d5900             fsub      qword ptr [0x599da8] ; bits=000000000000f03f, f64=1.0
00467d12  d9fa                     fsqrt
00467d14  d8f9                     fdivr     st(1)
00467d16  dd5ccf80                 fstp      qword ptr [edi + ecx*8 - 0x80]
00467d1a  dc05a89d5900             fadd      qword ptr [0x599da8] ; bits=000000000000f03f, f64=1.0
00467d20  83c102                   add       ecx, 2
00467d23  83ea02                   sub       edx, 2
00467d26  83fa02                   cmp       edx, 2
00467d29  7d8e                     jge       0x467cb9
00467d2b  85d2                     test      edx, edx
00467d2d  7430                     je        0x467d5f
00467d2f  8b45f8                   mov       eax, dword ptr [ebp - 8]
00467d32  c744c8f800000000         mov       dword ptr [eax + ecx*8 - 8], 0
00467d3a  c744c8fc00000000         mov       dword ptr [eax + ecx*8 - 4], 0
00467d42  d9c0                     fld       st(0)
00467d44  dc0da09d5900             fmul      qword ptr [0x599da0] ; bits=0000000000001040, f64=4.0
00467d4a  d8c9                     fmul      st(1)
00467d4c  dc25a89d5900             fsub      qword ptr [0x599da8] ; bits=000000000000f03f, f64=1.0
00467d52  d9fa                     fsqrt
00467d54  def9                     fdivp     st(1)
00467d56  dd1ccdb0538300           fstp      qword ptr [ecx*8 + 0x8353b0]
00467d5d  eb02                     jmp       0x467d61
00467d5f  ddd8                     fstp      st(0)
00467d61  8b4df8                   mov       ecx, dword ptr [ebp - 8]
00467d64  8b45f4                   mov       eax, dword ptr [ebp - 0xc]
00467d67  c744c1f800000000         mov       dword ptr [ecx + eax*8 - 8], 0
00467d6f  c744c1fc00000000         mov       dword ptr [ecx + eax*8 - 4], 0
00467d77  c70300000000             mov       dword ptr [ebx], 0
00467d7d  c743040000f03f           mov       dword ptr [ebx + 4], 0x3ff00000
00467d84  8b45f4                   mov       eax, dword ptr [ebp - 0xc]
00467d87  83c0ff                   add       eax, -1
00467d8a  89c2                     mov       edx, eax
00467d8c  83fa00                   cmp       edx, 0
00467d8f  7e48                     jle       0x467dd9
00467d91  b902000000               mov       ecx, 2
00467d96  83fa02                   cmp       edx, 2
00467d99  7c2a                     jl        0x467dc5
00467d9b  c744cbf800000000         mov       dword ptr [ebx + ecx*8 - 8], 0
00467da3  c744cbfc00000000         mov       dword ptr [ebx + ecx*8 - 4], 0
00467dab  c704cb00000000           mov       dword ptr [ebx + ecx*8], 0
00467db2  c744cb0400000000         mov       dword ptr [ebx + ecx*8 + 4], 0
00467dba  83c102                   add       ecx, 2
00467dbd  83ea02                   sub       edx, 2
00467dc0  83fa02                   cmp       edx, 2
00467dc3  7dd6                     jge       0x467d9b
00467dc5  85d2                     test      edx, edx
00467dc7  7410                     je        0x467dd9
00467dc9  c744cbf800000000         mov       dword ptr [ebx + ecx*8 - 8], 0
00467dd1  c744cbfc00000000         mov       dword ptr [ebx + ecx*8 - 4], 0
00467dd9  68e09d5900               push      0x599de0
00467dde  68b8538300               push      0x8353b8
00467de3  8d03                     lea       eax, [ebx]
00467de5  50                       push      eax
00467de6  8b45f8                   mov       eax, dword ptr [ebp - 8]
00467de9  8d08                     lea       ecx, [eax]
00467deb  8b45fc                   mov       eax, dword ptr [ebp - 4]
00467dee  51                       push      ecx
00467def  8d08                     lea       ecx, [eax]
00467df1  51                       push      ecx
00467df2  e829faffff               call      0x467820 ; _imtql2_
00467df7  83c414                   add       esp, 0x14
00467dfa  8b45fc                   mov       eax, dword ptr [ebp - 4]
00467dfd  8b10                     mov       edx, dword ptr [eax]
00467dff  83fa00                   cmp       edx, 0
00467e02  7e4d                     jle       0x467e51
00467e04  b901000000               mov       ecx, 1
00467e09  83fa02                   cmp       edx, 2
00467e0c  7c2f                     jl        0x467e3d
00467e0e  eb04                     jmp       0x467e14
00467e10  dd5ccbf0                 fstp      qword ptr [ebx + ecx*8 - 0x10]
00467e14  dd44cbf8                 fld       qword ptr [ebx + ecx*8 - 8]
00467e18  d9c0                     fld       st(0)
00467e1a  dc44cbf8                 fadd      qword ptr [ebx + ecx*8 - 8]
00467e1e  dec9                     fmulp     st(1)
00467e20  dd5ccbf8                 fstp      qword ptr [ebx + ecx*8 - 8]
00467e24  dd04cb                   fld       qword ptr [ebx + ecx*8]
00467e27  d9c0                     fld       st(0)
00467e29  dc04cb                   fadd      qword ptr [ebx + ecx*8]
00467e2c  dec9                     fmulp     st(1)
00467e2e  83c102                   add       ecx, 2
00467e31  83ea02                   sub       edx, 2
00467e34  83fa02                   cmp       edx, 2
00467e37  7dd7                     jge       0x467e10
00467e39  dd5ccbf0                 fstp      qword ptr [ebx + ecx*8 - 0x10]
00467e3d  85d2                     test      edx, edx
00467e3f  7410                     je        0x467e51
00467e41  dd44cbf8                 fld       qword ptr [ebx + ecx*8 - 8]
00467e45  d9c0                     fld       st(0)
00467e47  dc44cbf8                 fadd      qword ptr [ebx + ecx*8 - 8]
00467e4b  dec9                     fmulp     st(1)
00467e4d  dd5ccbf8                 fstp      qword ptr [ebx + ecx*8 - 8]
00467e51  b800000000               mov       eax, 0
00467e56  5f                       pop       edi
00467e57  5e                       pop       esi
00467e58  5b                       pop       ebx
00467e59  8be5                     mov       esp, ebp
00467e5b  5d                       pop       ebp
00467e5c  c3                       ret
00467e5d  8d4900                   lea       ecx, [ecx]
