; _proslv_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x6a9f0
0046a9f0  83ec2c                   sub       esp, 0x2c
0046a9f3  55                       push      ebp
0046a9f4  53                       push      ebx
0046a9f5  56                       push      esi
0046a9f6  57                       push      edi
0046a9f7  8b4c2440                 mov       ecx, dword ptr [esp + 0x40]
0046a9fb  8b5c2444                 mov       ebx, dword ptr [esp + 0x44]
0046a9ff  8b442448                 mov       eax, dword ptr [esp + 0x48]
0046aa03  89442438                 mov       dword ptr [esp + 0x38], eax
0046aa07  c705d0ac8d0000000000     mov       dword ptr [0x8dacd0], 0
0046aa11  8b01                     mov       eax, dword ptr [ecx]
0046aa13  8d50ff                   lea       edx, [eax - 1]
0046aa16  83fa00                   cmp       edx, 0
0046aa19  89442434                 mov       dword ptr [esp + 0x34], eax
0046aa1d  89542430                 mov       dword ptr [esp + 0x30], edx
0046aa21  0f8eb7000000             jle       0x46aade
0046aa27  b802000000               mov       eax, 2
0046aa2c  b901000000               mov       ecx, 1
0046aa31  8944242c                 mov       dword ptr [esp + 0x2c], eax
0046aa35  894c2428                 mov       dword ptr [esp + 0x28], ecx
0046aa39  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0046aa3d  c70485ccac8d0000000000   mov       dword ptr [eax*4 + 0x8daccc], 0
0046aa48  8b742438                 mov       esi, dword ptr [esp + 0x38]
0046aa4c  8b4c86fc                 mov       ecx, dword ptr [esi + eax*4 - 4]
0046aa50  41                       inc       ecx
0046aa51  8b7c244c                 mov       edi, dword ptr [esp + 0x4c]
0046aa55  8b6c87fc                 mov       ebp, dword ptr [edi + eax*4 - 4]
0046aa59  8b7c2450                 mov       edi, dword ptr [esp + 0x50]
0046aa5d  d94487fc                 fld       dword ptr [edi + eax*4 - 4]
0046aa61  8b7c2428                 mov       edi, dword ptr [esp + 0x28]
0046aa65  29ef                     sub       edi, ebp
0046aa67  89fa                     mov       edx, edi
0046aa69  01ca                     add       edx, ecx
0046aa6b  89c8                     mov       eax, ecx
0046aa6d  89ee                     mov       esi, ebp
0046aa6f  29ce                     sub       esi, ecx
0046aa71  89f5                     mov       ebp, esi
0046aa73  45                       inc       ebp
0046aa74  83fd00                   cmp       ebp, 0
0046aa77  89442420                 mov       dword ptr [esp + 0x20], eax
0046aa7b  7e41                     jle       0x46aabe
0046aa7d  8b442420                 mov       eax, dword ptr [esp + 0x20]
0046aa81  89c1                     mov       ecx, eax
0046aa83  83fd02                   cmp       ebp, 2
0046aa86  7c24                     jl        0x46aaac
0046aa88  8b442450                 mov       eax, dword ptr [esp + 0x50]
0046aa8c  d94490fc                 fld       dword ptr [eax + edx*4 - 4]
0046aa90  d84c8bfc                 fmul      dword ptr [ebx + ecx*4 - 4]
0046aa94  dee9                     fsubp     st(1)
0046aa96  d90490                   fld       dword ptr [eax + edx*4]
0046aa99  d80c8b                   fmul      dword ptr [ebx + ecx*4]
0046aa9c  dee9                     fsubp     st(1)
0046aa9e  83c102                   add       ecx, 2
0046aaa1  83c202                   add       edx, 2
0046aaa4  83ed02                   sub       ebp, 2
0046aaa7  83fd02                   cmp       ebp, 2
0046aaaa  7ddc                     jge       0x46aa88
0046aaac  85ed                     test      ebp, ebp
0046aaae  740e                     je        0x46aabe
0046aab0  8b442450                 mov       eax, dword ptr [esp + 0x50]
0046aab4  d94490fc                 fld       dword ptr [eax + edx*4 - 4]
0046aab8  d84c8bfc                 fmul      dword ptr [ebx + ecx*4 - 4]
0046aabc  dee9                     fsubp     st(1)
0046aabe  8b4c242c                 mov       ecx, dword ptr [esp + 0x2c]
0046aac2  8b442450                 mov       eax, dword ptr [esp + 0x50]
0046aac6  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0046aaca  41                       inc       ecx
0046aacb  ff442428                 inc       dword ptr [esp + 0x28]
0046aacf  836c243001               sub       dword ptr [esp + 0x30], 1
0046aad4  894c242c                 mov       dword ptr [esp + 0x2c], ecx
0046aad8  0f855bffffff             jne       0x46aa39
0046aade  8b442450                 mov       eax, dword ptr [esp + 0x50]
0046aae2  8b542438                 mov       edx, dword ptr [esp + 0x38]
0046aae6  8b4c2434                 mov       ecx, dword ptr [esp + 0x34]
0046aaea  8b348a                   mov       esi, dword ptr [edx + ecx*4]
0046aaed  d944b3fc                 fld       dword ptr [ebx + esi*4 - 4]
0046aaf1  d87c88fc                 fdivr     dword ptr [eax + ecx*4 - 4]
0046aaf5  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0046aaf9  8b442434                 mov       eax, dword ptr [esp + 0x34]
0046aafd  48                       dec       eax
0046aafe  89c1                     mov       ecx, eax
0046ab00  3d00000000               cmp       eax, 0
0046ab05  89442418                 mov       dword ptr [esp + 0x18], eax
0046ab09  0f8ee2000000             jle       0x46abf1
0046ab0f  8b442418                 mov       eax, dword ptr [esp + 0x18]
0046ab13  8944242c                 mov       dword ptr [esp + 0x2c], eax
0046ab17  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0046ab1b  8b7c2438                 mov       edi, dword ptr [esp + 0x38]
0046ab1f  8d7001                   lea       esi, [eax + 1]
0046ab22  8b0cb7                   mov       ecx, dword ptr [edi + esi*4]
0046ab25  49                       dec       ecx
0046ab26  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
0046ab2a  8b6cb0fc                 mov       ebp, dword ptr [eax + esi*4 - 4]
0046ab2e  45                       inc       ebp
0046ab2f  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0046ab33  89c2                     mov       edx, eax
0046ab35  8b742450                 mov       esi, dword ptr [esp + 0x50]
0046ab39  d90486                   fld       dword ptr [esi + eax*4]
0046ab3c  89c8                     mov       eax, ecx
0046ab3e  be01000000               mov       esi, 1
0046ab43  29ee                     sub       esi, ebp
0046ab45  89f5                     mov       ebp, esi
0046ab47  01cd                     add       ebp, ecx
0046ab49  83fd00                   cmp       ebp, 0
0046ab4c  89442414                 mov       dword ptr [esp + 0x14], eax
0046ab50  7e65                     jle       0x46abb7
0046ab52  8b442414                 mov       eax, dword ptr [esp + 0x14]
0046ab56  89c1                     mov       ecx, eax
0046ab58  83fd02                   cmp       ebp, 2
0046ab5b  7c3c                     jl        0x46ab99
0046ab5d  d9c0                     fld       st(0)
0046ab5f  d84c8bfc                 fmul      dword ptr [ebx + ecx*4 - 4]
0046ab63  8d0550ad8d00             lea       eax, [0x8dad50]
0046ab69  d884907cffffff           fadd      dword ptr [eax + edx*4 - 0x84]
0046ab70  d99c907cffffff           fstp      dword ptr [eax + edx*4 - 0x84]
0046ab77  d9c0                     fld       st(0)
0046ab79  d84c8bf8                 fmul      dword ptr [ebx + ecx*4 - 8]
0046ab7d  d8849078ffffff           fadd      dword ptr [eax + edx*4 - 0x88]
0046ab84  d99c9078ffffff           fstp      dword ptr [eax + edx*4 - 0x88]
0046ab8b  83c1fe                   add       ecx, -2
0046ab8e  83ea02                   sub       edx, 2
0046ab91  83ed02                   sub       ebp, 2
0046ab94  83fd02                   cmp       ebp, 2
0046ab97  7dc4                     jge       0x46ab5d
0046ab99  85ed                     test      ebp, ebp
0046ab9b  741e                     je        0x46abbb
0046ab9d  d84c8bfc                 fmul      dword ptr [ebx + ecx*4 - 4]
0046aba1  8d0550ad8d00             lea       eax, [0x8dad50]
0046aba7  d884907cffffff           fadd      dword ptr [eax + edx*4 - 0x84]
0046abae  d99c907cffffff           fstp      dword ptr [eax + edx*4 - 0x84]
0046abb5  eb06                     jmp       0x46abbd
0046abb7  ddd8                     fstp      st(0)
0046abb9  eb02                     jmp       0x46abbd
0046abbb  ddd8                     fstp      st(0)
0046abbd  8b54242c                 mov       edx, dword ptr [esp + 0x2c]
0046abc1  8b442450                 mov       eax, dword ptr [esp + 0x50]
0046abc5  d90495ccac8d00           fld       dword ptr [edx*4 + 0x8daccc]
0046abcc  8b4c2438                 mov       ecx, dword ptr [esp + 0x38]
0046abd0  d86c90fc                 fsubr     dword ptr [eax + edx*4 - 4]
0046abd4  8b3491                   mov       esi, dword ptr [ecx + edx*4]
0046abd7  d874b3fc                 fdiv      dword ptr [ebx + esi*4 - 4]
0046abdb  d95c90fc                 fstp      dword ptr [eax + edx*4 - 4]
0046abdf  83c2ff                   add       edx, -1
0046abe2  836c241801               sub       dword ptr [esp + 0x18], 1
0046abe7  8954242c                 mov       dword ptr [esp + 0x2c], edx
0046abeb  0f8526ffffff             jne       0x46ab17
0046abf1  b800000000               mov       eax, 0
0046abf6  5f                       pop       edi
0046abf7  5e                       pop       esi
0046abf8  5b                       pop       ebx
0046abf9  5d                       pop       ebp
0046abfa  83c42c                   add       esp, 0x2c
0046abfd  c3                       ret
0046abfe  8bff                     mov       edi, edi
