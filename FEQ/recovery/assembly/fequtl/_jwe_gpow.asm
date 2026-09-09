; _jwe_gpow
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xa0dfa
004a0dfa  55                       push      ebp
004a0dfb  8bec                     mov       ebp, esp
004a0dfd  83ec48                   sub       esp, 0x48
004a0e00  8b4510                   mov       eax, dword ptr [ebp + 0x10]
004a0e03  c70000000000             mov       dword ptr [eax], 0
004a0e09  d94508                   fld       dword ptr [ebp + 8]
004a0e0c  dd5df8                   fstp      qword ptr [ebp - 8]
004a0e0f  8b4dfc                   mov       ecx, dword ptr [ebp - 4]
004a0e12  230d80db5400             and       ecx, dword ptr [0x54db80] ; ?maske@?1??jwe_gpow@@9@9, bits=0000f0ff, f32=nan
004a0e18  894dc0                   mov       dword ptr [ebp - 0x40], ecx
004a0e1b  8b55c0                   mov       edx, dword ptr [ebp - 0x40]
004a0e1e  81ea0000e03f             sub       edx, 0x3fe00000
004a0e24  8b45fc                   mov       eax, dword ptr [ebp - 4]
004a0e27  2d9ea00600               sub       eax, 0x6a09e
004a0e2c  2b45c0                   sub       eax, dword ptr [ebp - 0x40]
004a0e2f  2500001000               and       eax, 0x100000
004a0e34  2bd0                     sub       edx, eax
004a0e36  8955c0                   mov       dword ptr [ebp - 0x40], edx
004a0e39  8b4dc0                   mov       ecx, dword ptr [ebp - 0x40]
004a0e3c  c1f914                   sar       ecx, 0x14
004a0e3f  894dbc                   mov       dword ptr [ebp - 0x44], ecx
004a0e42  db45bc                   fild      dword ptr [ebp - 0x44]
004a0e45  dd5df0                   fstp      qword ptr [ebp - 0x10]
004a0e48  8b55fc                   mov       edx, dword ptr [ebp - 4]
004a0e4b  2b55c0                   sub       edx, dword ptr [ebp - 0x40]
004a0e4e  8955fc                   mov       dword ptr [ebp - 4], edx
004a0e51  dd45f8                   fld       qword ptr [ebp - 8]
004a0e54  dc2580dc5400             fsub      qword ptr [0x54dc80] ; __real@3ff0000000000000, bits=000000000000f03f, f64=1.0
004a0e5a  dd5de0                   fstp      qword ptr [ebp - 0x20]
004a0e5d  dd45f8                   fld       qword ptr [ebp - 8]
004a0e60  dc0580dc5400             fadd      qword ptr [0x54dc80] ; __real@3ff0000000000000, bits=000000000000f03f, f64=1.0
004a0e66  dc7de0                   fdivr     qword ptr [ebp - 0x20]
004a0e69  dd55d8                   fst       qword ptr [ebp - 0x28]
004a0e6c  dc4dd8                   fmul      qword ptr [ebp - 0x28]
004a0e6f  dd5dd0                   fstp      qword ptr [ebp - 0x30]
004a0e72  dd0520dc5400             fld       qword ptr [0x54dc20] ; ?p3@?1??jwe_gpow@@9@9, bits=710b90c30427d33f, f64=0.2992565069
004a0e78  dc4dd0                   fmul      qword ptr [ebp - 0x30]
004a0e7b  dc0518dc5400             fadd      qword ptr [0x54dc18] ; ?p2@?1??jwe_gpow@@9@9, bits=603a546c7895d93f, f64=0.3997479494
004a0e81  dc4dd0                   fmul      qword ptr [ebp - 0x30]
004a0e84  dc0510dc5400             fadd      qword ptr [0x54dc10] ; ?p1@?1??jwe_gpow@@9@9, bits=cdc8ca765855e53f, f64=0.6666681595
004a0e8a  dd45d0                   fld       qword ptr [ebp - 0x30]
004a0e8d  dc4dd8                   fmul      qword ptr [ebp - 0x28]
004a0e90  d9450c                   fld       dword ptr [ebp + 0xc]
004a0e93  dc0d28dc5400             fmul      qword ptr [0x54dc28] ; ?lg2e@?1??jwe_gpow@@9@9, bits=fc822b654715f73f, f64=1.442695040888963
004a0e99  dec9                     fmulp     st(1)
004a0e9b  dec9                     fmulp     st(1)
004a0e9d  dd45e0                   fld       qword ptr [ebp - 0x20]
004a0ea0  dc4dd8                   fmul      qword ptr [ebp - 0x28]
004a0ea3  dc65e0                   fsub      qword ptr [ebp - 0x20]
004a0ea6  d9450c                   fld       dword ptr [ebp + 0xc]
004a0ea9  dc0d28dc5400             fmul      qword ptr [0x54dc28] ; ?lg2e@?1??jwe_gpow@@9@9, bits=fc822b654715f73f, f64=1.442695040888963
004a0eaf  dec9                     fmulp     st(1)
004a0eb1  d9450c                   fld       dword ptr [ebp + 0xc]
004a0eb4  dc4df0                   fmul      qword ptr [ebp - 0x10]
004a0eb7  dee9                     fsubp     st(1)
004a0eb9  dee9                     fsubp     st(1)
004a0ebb  dd55e0                   fst       qword ptr [ebp - 0x20]
004a0ebe  dc1d78dc5400             fcomp     qword ptr [0x54dc78] ; __real@c05fc00000000000, bits=0000000000c05fc0, f64=-127.0
004a0ec4  dfe0                     fnstsw    ax
004a0ec6  f6c441                   test      ah, 0x41
004a0ec9  7a0b                     jp        0x4a0ed6
004a0ecb  d9056cdc5400             fld       dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a0ed1  e9b3000000               jmp       0x4a0f89
004a0ed6  dd45e0                   fld       qword ptr [ebp - 0x20]
004a0ed9  dc1d70dc5400             fcomp     qword ptr [0x54dc70] ; __real@4060000000000000, bits=0000000000006040, f64=128.0
004a0edf  dfe0                     fnstsw    ax
004a0ee1  2500010000               and       eax, 0x100
004a0ee6  7514                     jne       0x4a0efc
004a0ee8  8b4510                   mov       eax, dword ptr [ebp + 0x10]
004a0eeb  c70088050000             mov       dword ptr [eax], 0x588
004a0ef1  d90550dc5400             fld       dword ptr [0x54dc50] ; __real@7f7fffee, bits=eeff7f7f, f32=3.402820018375656e+38
004a0ef7  e98d000000               jmp       0x4a0f89
004a0efc  dd45e0                   fld       qword ptr [ebp - 0x20]
004a0eff  dc0588db5400             fadd      qword ptr [0x54db88] ; ?bg@?1??jwe_gpow@@9@9, bits=000000000000f842, f64=422212465065984.0
004a0f05  dd5df8                   fstp      qword ptr [ebp - 8]
004a0f08  8b4df8                   mov       ecx, dword ptr [ebp - 8]
004a0f0b  230d84db5400             and       ecx, dword ptr [0x54db84] ; ?mask@?1??jwe_gpow@@9@9, bits=0f000000, f32=2.1019476964872256e-44
004a0f11  894dc4                   mov       dword ptr [ebp - 0x3c], ecx
004a0f14  dd0588db5400             fld       qword ptr [0x54db88] ; ?bg@?1??jwe_gpow@@9@9, bits=000000000000f842, f64=422212465065984.0
004a0f1a  dc65f8                   fsub      qword ptr [ebp - 8]
004a0f1d  dc45e0                   fadd      qword ptr [ebp - 0x20]
004a0f20  dd5de0                   fstp      qword ptr [ebp - 0x20]
004a0f23  8b55f8                   mov       edx, dword ptr [ebp - 8]
004a0f26  2b55c4                   sub       edx, dword ptr [ebp - 0x3c]
004a0f29  c1e210                   shl       edx, 0x10
004a0f2c  81c20000f03f             add       edx, 0x3ff00000
004a0f32  8955ec                   mov       dword ptr [ebp - 0x14], edx
004a0f35  c745e800000000           mov       dword ptr [ebp - 0x18], 0
004a0f3c  dd0548dc5400             fld       qword ptr [0x54dc48] ; ?a4@?1??jwe_gpow@@9@9, bits=d413b93392b2833f, f64=0.009617941096744
004a0f42  dc4de0                   fmul      qword ptr [ebp - 0x20]
004a0f45  dc0540dc5400             fadd      qword ptr [0x54dc40] ; ?a3@?1??jwe_gpow@@9@9, bits=77681c743f6bac3f, f64=0.05550573627825
004a0f4b  dd45e0                   fld       qword ptr [ebp - 0x20]
004a0f4e  dc4de0                   fmul      qword ptr [ebp - 0x20]
004a0f51  dec9                     fmulp     st(1)
004a0f53  dd0538dc5400             fld       qword ptr [0x54dc38] ; ?a2@?1??jwe_gpow@@9@9, bits=69683300bebfce3f, f64=0.2402265072804
004a0f59  dc4de0                   fmul      qword ptr [ebp - 0x20]
004a0f5c  dc0530dc5400             fadd      qword ptr [0x54dc30] ; ?a1@?1??jwe_gpow@@9@9, bits=979dc3fe422ee63f, f64=0.6931471801626
004a0f62  dec1                     faddp     st(1)
004a0f64  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
004a0f67  dd45e0                   fld       qword ptr [ebp - 0x20]
004a0f6a  dc0cc590db5400           fmul      qword ptr [eax*8 + 0x54db90]
004a0f71  dec9                     fmulp     st(1)
004a0f73  8b4dc4                   mov       ecx, dword ptr [ebp - 0x3c]
004a0f76  dc04cd90db5400           fadd      qword ptr [ecx*8 + 0x54db90]
004a0f7d  dd55c8                   fst       qword ptr [ebp - 0x38]
004a0f80  dc4de8                   fmul      qword ptr [ebp - 0x18]
004a0f83  dd55c8                   fst       qword ptr [ebp - 0x38]
004a0f86  d955b8                   fst       dword ptr [ebp - 0x48]
004a0f89  8be5                     mov       esp, ebp
004a0f8b  5d                       pop       ebp
004a0f8c  c3                       ret
004a0f8d  cc                       int3
004a0f8e  cc                       int3
004a0f8f  cc                       int3
