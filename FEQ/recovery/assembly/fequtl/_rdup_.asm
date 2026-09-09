; _rdup_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x4fe80
0044fe80  55                       push      ebp
0044fe81  8bec                     mov       ebp, esp
0044fe83  b808000000               mov       eax, 8
0044fe88  e873910900               call      0x4e9000 ; __alloca_probe
0044fe8d  53                       push      ebx
0044fe8e  8b5508                   mov       edx, dword ptr [ebp + 8]
0044fe91  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
0044fe94  8b4510                   mov       eax, dword ptr [ebp + 0x10]
0044fe97  8945fc                   mov       dword ptr [ebp - 4], eax
0044fe9a  d901                     fld       dword ptr [ecx]
0044fe9c  d9c0                     fld       st(0)
0044fe9e  d9e1                     fabs
0044fea0  8b02                     mov       eax, dword ptr [edx]
0044fea2  d94481fc                 fld       dword ptr [ecx + eax*4 - 4]
0044fea6  d9e1                     fabs
0044fea8  dec1                     faddp     st(1)
0044feaa  d80df47a5800             fmul      dword ptr [0x587af4] ; bits=0000003f, f32=0.5
0044feb0  dee1                     fsubrp    st(1)
0044feb2  ba01000000               mov       edx, 1
0044feb7  89c3                     mov       ebx, eax
0044feb9  83fb02                   cmp       ebx, 2
0044febc  0f8cef000000             jl        0x44ffb1
0044fec2  89d8                     mov       eax, ebx
0044fec4  83c0ff                   add       eax, -1
0044fec7  3d00000000               cmp       eax, 0
0044fecc  8945f8                   mov       dword ptr [ebp - 8], eax
0044fecf  0f8ee0000000             jle       0x44ffb5
0044fed5  bb02000000               mov       ebx, 2
0044feda  d83df07a5800             fdivr     dword ptr [0x587af0] ; bits=0000803f, f32=1.0
0044fee0  837df802                 cmp       dword ptr [ebp - 8], 2
0044fee4  0f8c8a000000             jl        0x44ff74
0044feea  d901                     fld       dword ptr [ecx]
0044feec  d9c0                     fld       st(0)
0044feee  d86c91fc                 fsubr     dword ptr [ecx + edx*4 - 4]
0044fef2  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
0044fef6  d9ca                     fxch      st(2)
0044fef8  d86c99fc                 fsubr     dword ptr [ecx + ebx*4 - 4]
0044fefc  dee9                     fsubp     st(1)
0044fefe  d9e1                     fabs
0044ff00  d8ca                     fmul      st(2)
0044ff02  d81df87a5800             fcomp     dword ptr [0x587af8] ; bits=acc52737, f32=9.999999747378752e-06
0044ff08  dfe0                     fnstsw    ax
0044ff0a  9e                       sahf
0044ff0b  0f8a02000000             jp        0x44ff13
0044ff11  760b                     jbe       0x44ff1e
0044ff13  42                       inc       edx
0044ff14  39da                     cmp       edx, ebx
0044ff16  740a                     je        0x44ff22
0044ff18  d95c91fc                 fstp      dword ptr [ecx + edx*4 - 4]
0044ff1c  eb06                     jmp       0x44ff24
0044ff1e  ddd8                     fstp      st(0)
0044ff20  eb02                     jmp       0x44ff24
0044ff22  ddd8                     fstp      st(0)
0044ff24  43                       inc       ebx
0044ff25  d901                     fld       dword ptr [ecx]
0044ff27  d9c0                     fld       st(0)
0044ff29  d86c91fc                 fsubr     dword ptr [ecx + edx*4 - 4]
0044ff2d  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
0044ff31  d9ca                     fxch      st(2)
0044ff33  d86c99fc                 fsubr     dword ptr [ecx + ebx*4 - 4]
0044ff37  dee9                     fsubp     st(1)
0044ff39  d9e1                     fabs
0044ff3b  d8ca                     fmul      st(2)
0044ff3d  d81df87a5800             fcomp     dword ptr [0x587af8] ; bits=acc52737, f32=9.999999747378752e-06
0044ff43  dfe0                     fnstsw    ax
0044ff45  9e                       sahf
0044ff46  0f8a02000000             jp        0x44ff4e
0044ff4c  760b                     jbe       0x44ff59
0044ff4e  42                       inc       edx
0044ff4f  39da                     cmp       edx, ebx
0044ff51  740a                     je        0x44ff5d
0044ff53  d95c91fc                 fstp      dword ptr [ecx + edx*4 - 4]
0044ff57  eb06                     jmp       0x44ff5f
0044ff59  ddd8                     fstp      st(0)
0044ff5b  eb02                     jmp       0x44ff5f
0044ff5d  ddd8                     fstp      st(0)
0044ff5f  43                       inc       ebx
0044ff60  8b45f8                   mov       eax, dword ptr [ebp - 8]
0044ff63  83e802                   sub       eax, 2
0044ff66  3d02000000               cmp       eax, 2
0044ff6b  8945f8                   mov       dword ptr [ebp - 8], eax
0044ff6e  0f8d76ffffff             jge       0x44feea
0044ff74  8b45f8                   mov       eax, dword ptr [ebp - 8]
0044ff77  85c0                     test      eax, eax
0044ff79  743e                     je        0x44ffb9
0044ff7b  d901                     fld       dword ptr [ecx]
0044ff7d  d9c0                     fld       st(0)
0044ff7f  d86c91fc                 fsubr     dword ptr [ecx + edx*4 - 4]
0044ff83  d94499fc                 fld       dword ptr [ecx + ebx*4 - 4]
0044ff87  d9ca                     fxch      st(2)
0044ff89  d86c99fc                 fsubr     dword ptr [ecx + ebx*4 - 4]
0044ff8d  dee9                     fsubp     st(1)
0044ff8f  d9e1                     fabs
0044ff91  deca                     fmulp     st(2)
0044ff93  d9c9                     fxch      st(1)
0044ff95  d81df87a5800             fcomp     dword ptr [0x587af8] ; bits=acc52737, f32=9.999999747378752e-06
0044ff9b  dfe0                     fnstsw    ax
0044ff9d  9e                       sahf
0044ff9e  0f8a02000000             jp        0x44ffa6
0044ffa4  7617                     jbe       0x44ffbd
0044ffa6  42                       inc       edx
0044ffa7  39da                     cmp       edx, ebx
0044ffa9  7416                     je        0x44ffc1
0044ffab  d95c91fc                 fstp      dword ptr [ecx + edx*4 - 4]
0044ffaf  eb12                     jmp       0x44ffc3
0044ffb1  ddd8                     fstp      st(0)
0044ffb3  eb0e                     jmp       0x44ffc3
0044ffb5  ddd8                     fstp      st(0)
0044ffb7  eb0a                     jmp       0x44ffc3
0044ffb9  ddd8                     fstp      st(0)
0044ffbb  eb06                     jmp       0x44ffc3
0044ffbd  ddd8                     fstp      st(0)
0044ffbf  eb02                     jmp       0x44ffc3
0044ffc1  ddd8                     fstp      st(0)
0044ffc3  8b45fc                   mov       eax, dword ptr [ebp - 4]
0044ffc6  8910                     mov       dword ptr [eax], edx
0044ffc8  b800000000               mov       eax, 0
0044ffcd  5b                       pop       ebx
0044ffce  8be5                     mov       esp, ebp
0044ffd0  5d                       pop       ebp
0044ffd1  c3                       ret
0044ffd2  8da42400000000           lea       esp, [esp]
0044ffd9  8da42400000000           lea       esp, [esp]
