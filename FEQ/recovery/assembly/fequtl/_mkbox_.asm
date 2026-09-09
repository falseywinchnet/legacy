; _mkbox_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xf730
0040f730  55                       push      ebp
0040f731  8bec                     mov       ebp, esp
0040f733  b828000000               mov       eax, 0x28
0040f738  e8c3980d00               call      0x4e9000 ; __alloca_probe
0040f73d  53                       push      ebx
0040f73e  56                       push      esi
0040f73f  57                       push      edi
0040f740  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0040f743  8b550c                   mov       edx, dword ptr [ebp + 0xc]
0040f746  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
0040f749  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0040f74c  d900                     fld       dword ptr [eax]
0040f74e  8d35c8945500             lea       esi, [0x5594c8] ; bits=00000000, f32=0.0
0040f754  d94694                   fld       dword ptr [esi - 0x6c]
0040f757  d9c0                     fld       st(0)
0040f759  d808                     fmul      dword ptr [eax]
0040f75b  d901                     fld       dword ptr [ecx]
0040f75d  d9c1                     fld       st(1)
0040f75f  d829                     fsubr     dword ptr [ecx]
0040f761  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040f764  d910                     fst       dword ptr [eax]
0040f766  8b7d1c                   mov       edi, dword ptr [ebp + 0x1c]
0040f769  d94698                   fld       dword ptr [esi - 0x68]
0040f76c  d807                     fadd      dword ptr [edi]
0040f76e  8b7528                   mov       esi, dword ptr [ebp + 0x28]
0040f771  d91e                     fstp      dword ptr [esi]
0040f773  d95804                   fstp      dword ptr [eax + 4]
0040f776  8b3f                     mov       edi, dword ptr [edi]
0040f778  897e04                   mov       dword ptr [esi + 4], edi
0040f77b  dce1                     fsubr     st(1), st(0)
0040f77d  d9c9                     fxch      st(1)
0040f77f  d95808                   fstp      dword ptr [eax + 8]
0040f782  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0040f785  d900                     fld       dword ptr [eax]
0040f787  d9c3                     fld       st(3)
0040f789  d800                     fadd      dword ptr [eax]
0040f78b  d902                     fld       dword ptr [edx]
0040f78d  d9c9                     fxch      st(1)
0040f78f  d802                     fadd      dword ptr [edx]
0040f791  d95e08                   fstp      dword ptr [esi + 8]
0040f794  d9c9                     fxch      st(1)
0040f796  d8e4                     fsub      st(4)
0040f798  db7df0                   fstp      xword ptr [ebp - 0x10]
0040f79b  d9c9                     fxch      st(1)
0040f79d  db7de4                   fstp      xword ptr [ebp - 0x1c]
0040f7a0  d9ca                     fxch      st(2)
0040f7a2  db7dd8                   fstp      xword ptr [ebp - 0x28]
0040f7a5  d9c9                     fxch      st(1)
0040f7a7  b901000000               mov       ecx, 1
0040f7ac  d9c9                     fxch      st(1)
0040f7ae  d80b                     fmul      dword ptr [ebx]
0040f7b0  d9e0                     fchs
0040f7b2  d9ee                     fldz
0040f7b4  db6df0                   fld       xword ptr [ebp - 0x10]
0040f7b7  d9c9                     fxch      st(1)
0040f7b9  d9cb                     fxch      st(3)
0040f7bb  d9c9                     fxch      st(1)
0040f7bd  d9ca                     fxch      st(2)
0040f7bf  d9c9                     fxch      st(1)
0040f7c1  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040f7c4  d9c9                     fxch      st(1)
0040f7c6  d9548808                 fst       dword ptr [eax + ecx*4 + 8]
0040f7ca  d9c3                     fld       st(3)
0040f7cc  d80d48945500             fmul      dword ptr [0x559448] ; bits=f1f0703d, f32=0.05882352963089943
0040f7d2  d9fa                     fsqrt
0040f7d4  d95dfc                   fstp      dword ptr [ebp - 4]
0040f7d7  d9e8                     fld1
0040f7d9  d9c0                     fld       st(0)
0040f7db  d865fc                   fsub      dword ptr [ebp - 4]
0040f7de  d8cc                     fmul      st(4)
0040f7e0  d8c3                     fadd      st(3)
0040f7e2  8b5528                   mov       edx, dword ptr [ebp + 0x28]
0040f7e5  d95c8a08                 fstp      dword ptr [edx + ecx*4 + 8]
0040f7e9  dcc4                     fadd      st(4), st(0)
0040f7eb  d9c9                     fxch      st(1)
0040f7ed  d954880c                 fst       dword ptr [eax + ecx*4 + 0xc]
0040f7f1  d9c4                     fld       st(4)
0040f7f3  d80d48945500             fmul      dword ptr [0x559448] ; bits=f1f0703d, f32=0.05882352963089943
0040f7f9  d9fa                     fsqrt
0040f7fb  d95dfc                   fstp      dword ptr [ebp - 4]
0040f7fe  d9c1                     fld       st(1)
0040f800  d865fc                   fsub      dword ptr [ebp - 4]
0040f803  d8cc                     fmul      st(4)
0040f805  d8c3                     fadd      st(3)
0040f807  d95c8a0c                 fstp      dword ptr [edx + ecx*4 + 0xc]
0040f80b  d9cc                     fxch      st(4)
0040f80d  d8c1                     fadd      st(1)
0040f80f  d9cc                     fxch      st(4)
0040f811  d9548810                 fst       dword ptr [eax + ecx*4 + 0x10]
0040f815  d9c4                     fld       st(4)
0040f817  d80d48945500             fmul      dword ptr [0x559448] ; bits=f1f0703d, f32=0.05882352963089943
0040f81d  d9fa                     fsqrt
0040f81f  d95dfc                   fstp      dword ptr [ebp - 4]
0040f822  d9c1                     fld       st(1)
0040f824  d865fc                   fsub      dword ptr [ebp - 4]
0040f827  d8cc                     fmul      st(4)
0040f829  d8c3                     fadd      st(3)
0040f82b  d95c8a10                 fstp      dword ptr [edx + ecx*4 + 0x10]
0040f82f  d9cc                     fxch      st(4)
0040f831  d8c1                     fadd      st(1)
0040f833  d9cc                     fxch      st(4)
0040f835  d9548814                 fst       dword ptr [eax + ecx*4 + 0x14]
0040f839  d9c4                     fld       st(4)
0040f83b  d80d48945500             fmul      dword ptr [0x559448] ; bits=f1f0703d, f32=0.05882352963089943
0040f841  d9fa                     fsqrt
0040f843  d95dfc                   fstp      dword ptr [ebp - 4]
0040f846  d9c1                     fld       st(1)
0040f848  d865fc                   fsub      dword ptr [ebp - 4]
0040f84b  d8cc                     fmul      st(4)
0040f84d  d8c3                     fadd      st(3)
0040f84f  d95c8a14                 fstp      dword ptr [edx + ecx*4 + 0x14]
0040f853  d9cc                     fxch      st(4)
0040f855  d8c1                     fadd      st(1)
0040f857  d9cc                     fxch      st(4)
0040f859  d9548818                 fst       dword ptr [eax + ecx*4 + 0x18]
0040f85d  d9c4                     fld       st(4)
0040f85f  d80d48945500             fmul      dword ptr [0x559448] ; bits=f1f0703d, f32=0.05882352963089943
0040f865  d9fa                     fsqrt
0040f867  d95dfc                   fstp      dword ptr [ebp - 4]
0040f86a  d9c1                     fld       st(1)
0040f86c  d865fc                   fsub      dword ptr [ebp - 4]
0040f86f  d8cc                     fmul      st(4)
0040f871  d8c3                     fadd      st(3)
0040f873  d95c8a18                 fstp      dword ptr [edx + ecx*4 + 0x18]
0040f877  d9cc                     fxch      st(4)
0040f879  d8c1                     fadd      st(1)
0040f87b  d9cc                     fxch      st(4)
0040f87d  d954881c                 fst       dword ptr [eax + ecx*4 + 0x1c]
0040f881  d9c4                     fld       st(4)
0040f883  d80d48945500             fmul      dword ptr [0x559448] ; bits=f1f0703d, f32=0.05882352963089943
0040f889  d9fa                     fsqrt
0040f88b  d95dfc                   fstp      dword ptr [ebp - 4]
0040f88e  d9c1                     fld       st(1)
0040f890  d865fc                   fsub      dword ptr [ebp - 4]
0040f893  d8cc                     fmul      st(4)
0040f895  d8c3                     fadd      st(3)
0040f897  d95c8a1c                 fstp      dword ptr [edx + ecx*4 + 0x1c]
0040f89b  d9cc                     fxch      st(4)
0040f89d  dec1                     faddp     st(1)
0040f89f  d9cb                     fxch      st(3)
0040f8a1  d9c9                     fxch      st(1)
0040f8a3  83c106                   add       ecx, 6
0040f8a6  83f913                   cmp       ecx, 0x13
0040f8a9  0f8c12ffffff             jl        0x40f7c1
0040f8af  ddd8                     fstp      st(0)
0040f8b1  ddd8                     fstp      st(0)
0040f8b3  ddd8                     fstp      st(0)
0040f8b5  ddd8                     fstp      st(0)
0040f8b7  db6de4                   fld       xword ptr [ebp - 0x1c]
0040f8ba  b915000000               mov       ecx, 0x15
0040f8bf  ba13000000               mov       edx, 0x13
0040f8c4  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040f8c7  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
0040f8cb  d9e0                     fchs
0040f8cd  8b5d28                   mov       ebx, dword ptr [ebp + 0x28]
0040f8d0  8b748bfc                 mov       esi, dword ptr [ebx + ecx*4 - 4]
0040f8d4  89749308                 mov       dword ptr [ebx + edx*4 + 8], esi
0040f8d8  d8c1                     fadd      st(1)
0040f8da  d95c9008                 fstp      dword ptr [eax + edx*4 + 8]
0040f8de  d9c0                     fld       st(0)
0040f8e0  d84488fc                 fadd      dword ptr [eax + ecx*4 - 4]
0040f8e4  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0040f8e8  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
0040f8ec  d9e0                     fchs
0040f8ee  8b748bf8                 mov       esi, dword ptr [ebx + ecx*4 - 8]
0040f8f2  8974930c                 mov       dword ptr [ebx + edx*4 + 0xc], esi
0040f8f6  d8c1                     fadd      st(1)
0040f8f8  d95c900c                 fstp      dword ptr [eax + edx*4 + 0xc]
0040f8fc  d9c0                     fld       st(0)
0040f8fe  d84488f8                 fadd      dword ptr [eax + ecx*4 - 8]
0040f902  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
0040f906  d94488f4                 fld       dword ptr [eax + ecx*4 - 0xc]
0040f90a  d9e0                     fchs
0040f90c  8b748bf4                 mov       esi, dword ptr [ebx + ecx*4 - 0xc]
0040f910  89749310                 mov       dword ptr [ebx + edx*4 + 0x10], esi
0040f914  d8c1                     fadd      st(1)
0040f916  d95c9010                 fstp      dword ptr [eax + edx*4 + 0x10]
0040f91a  d9c0                     fld       st(0)
0040f91c  d84488f4                 fadd      dword ptr [eax + ecx*4 - 0xc]
0040f920  d95c88f4                 fstp      dword ptr [eax + ecx*4 - 0xc]
0040f924  83e903                   sub       ecx, 3
0040f927  83c203                   add       edx, 3
0040f92a  83fa25                   cmp       edx, 0x25
0040f92d  7c95                     jl        0x40f8c4
0040f92f  ddd8                     fstp      st(0)
0040f931  db6dd8                   fld       xword ptr [ebp - 0x28]
0040f934  d80d5c945500             fmul      dword ptr [0x55945c] ; bits=0000003f, f32=0.5
0040f93a  db6de4                   fld       xword ptr [ebp - 0x1c]
0040f93d  dec1                     faddp     st(1)
0040f93f  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040f942  d9909c000000             fst       dword ptr [eax + 0x9c]
0040f948  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0040f94b  8b5108                   mov       edx, dword ptr [ecx + 8]
0040f94e  89919c000000             mov       dword ptr [ecx + 0x9c], edx
0040f954  d998a0000000             fstp      dword ptr [eax + 0xa0]
0040f95a  8b4104                   mov       eax, dword ptr [ecx + 4]
0040f95d  8981a0000000             mov       dword ptr [ecx + 0xa0], eax
0040f963  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0040f966  c70029000000             mov       dword ptr [eax], 0x29
0040f96c  b800000000               mov       eax, 0
0040f971  5f                       pop       edi
0040f972  5e                       pop       esi
0040f973  5b                       pop       ebx
0040f974  8be5                     mov       esp, ebp
0040f976  5d                       pop       ebp
0040f977  c3                       ret
0040f978  90                       nop
0040f979  8da42400000000           lea       esp, [esp]
