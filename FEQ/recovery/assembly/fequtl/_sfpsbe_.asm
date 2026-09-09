; _sfpsbe_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x269f0
004269f0  55                       push      ebp
004269f1  8bec                     mov       ebp, esp
004269f3  b880010000               mov       eax, 0x180
004269f8  e803260c00               call      0x4e9000 ; __alloca_probe
004269fd  53                       push      ebx
004269fe  56                       push      esi
004269ff  57                       push      edi
00426a00  8b7508                   mov       esi, dword ptr [ebp + 8]
00426a03  8b450c                   mov       eax, dword ptr [ebp + 0xc]
00426a06  8b7d10                   mov       edi, dword ptr [ebp + 0x10]
00426a09  898598feffff             mov       dword ptr [ebp - 0x168], eax
00426a0f  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00426a12  d900                     fld       dword ptr [eax]
00426a14  d9ee                     fldz
00426a16  d9c9                     fxch      st(1)
00426a18  d81500855600             fcom      dword ptr [0x568500] ; bits=00000000, f32=0.0
00426a1e  db7de0                   fstp      xword ptr [ebp - 0x20]
00426a21  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00426a24  dfe0                     fnstsw    ax
00426a26  9e                       sahf
00426a27  0f8a29000000             jp        0x426a56
00426a2d  7627                     jbe       0x426a56
00426a2f  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00426a35  8b08                     mov       ecx, dword ptr [eax]
00426a37  8b17                     mov       edx, dword ptr [edi]
00426a39  d90495e4b6e900           fld       dword ptr [edx*4 + 0xe9b6e4]
00426a40  d82c8de4b6e900           fsubr     dword ptr [ecx*4 + 0xe9b6e4]
00426a47  d9e1                     fabs
00426a49  db6de0                   fld       xword ptr [ebp - 0x20]
00426a4c  def1                     fdivrp    st(1)
00426a4e  d91d94b2e900             fstp      dword ptr [0xe9b294]
00426a54  eb1f                     jmp       0x426a75
00426a56  db6de0                   fld       xword ptr [ebp - 0x20]
00426a59  db6dd4                   fld       xword ptr [ebp - 0x2c]
00426a5c  d9c9                     fxch      st(1)
00426a5e  dae9                     fucompp
00426a60  dfe0                     fnstsw    ax
00426a62  9e                       sahf
00426a63  0f8a0c000000             jp        0x426a75
00426a69  750a                     jne       0x426a75
00426a6b  c70594b2e90000000000     mov       dword ptr [0xe9b294], 0
00426a75  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00426a78  8b00                     mov       eax, dword ptr [eax]
00426a7a  890588b2e900             mov       dword ptr [0xe9b288], eax
00426a80  8b07                     mov       eax, dword ptr [edi]
00426a82  d9048564bdea00           fld       dword ptr [eax*4 + 0xeabd64]
00426a89  d90485e4b6e900           fld       dword ptr [eax*4 + 0xe9b6e4]
00426a90  d9c0                     fld       st(0)
00426a92  db7dc8                   fstp      xword ptr [ebp - 0x38]
00426a95  d90485e0b6e900           fld       dword ptr [eax*4 + 0xe9b6e0]
00426a9c  db7dbc                   fstp      xword ptr [ebp - 0x44]
00426a9f  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00426aa2  d9c1                     fld       st(1)
00426aa4  d829                     fsubr     dword ptr [ecx]
00426aa6  d91485e4c3eb00           fst       dword ptr [eax*4 + 0xebc3e4]
00426aad  d81500855600             fcom      dword ptr [0x568500] ; bits=00000000, f32=0.0
00426ab3  d9ca                     fxch      st(2)
00426ab5  db7db0                   fstp      xword ptr [ebp - 0x50]
00426ab8  d9c9                     fxch      st(1)
00426aba  db7da4                   fstp      xword ptr [ebp - 0x5c]
00426abd  db7d98                   fstp      xword ptr [ebp - 0x68]
00426ac0  898594feffff             mov       dword ptr [ebp - 0x16c], eax
00426ac6  dfe0                     fnstsw    ax
00426ac8  9e                       sahf
00426ac9  0f8a35000000             jp        0x426b04
00426acf  7733                     ja        0x426b04
00426ad1  8b06                     mov       eax, dword ptr [esi]
00426ad3  8d0df8875600             lea       ecx, [0x5687f8] ; bits=09020000, f32=7.300764999132297e-43
00426ad9  8945fc                   mov       dword ptr [ebp - 4], eax
00426adc  8d45fc                   lea       eax, [ebp - 4]
00426adf  894108                   mov       dword ptr [ecx + 8], eax
00426ae2  db6da4                   fld       xword ptr [ebp - 0x5c]
00426ae5  d95df8                   fstp      dword ptr [ebp - 8]
00426ae8  8d45f8                   lea       eax, [ebp - 8]
00426aeb  894128                   mov       dword ptr [ecx + 0x28], eax
00426aee  51                       push      ecx
00426aef  e8fcba0700               call      0x4a25f0 ; _jwe_isfm
00426af4  83c404                   add       esp, 4
00426af7  68e4865600               push      0x5686e4
00426afc  e83fc90700               call      0x4a3440 ; _jwe_xstp
00426b01  83c404                   add       esp, 4
00426b04  8b8594feffff             mov       eax, dword ptr [ebp - 0x16c]
00426b0a  8b0c85243aea00           mov       ecx, dword ptr [eax*4 + 0xea3a24]
00426b11  890d28885600             mov       dword ptr [0x568828], ecx ; bits=00000000, f32=0.0
00426b17  8b0c8564caec00           mov       ecx, dword ptr [eax*4 + 0xecca64]
00426b1e  890da8b2e900             mov       dword ptr [0xe9b2a8], ecx
00426b24  db6da4                   fld       xword ptr [ebp - 0x5c]
00426b27  d81da8b2e900             fcomp     dword ptr [0xe9b2a8]
00426b2d  db6da4                   fld       xword ptr [ebp - 0x5c]
00426b30  db7d8c                   fstp      xword ptr [ebp - 0x74]
00426b33  dfe0                     fnstsw    ax
00426b35  66a90041                 test      ax, 0x4100
00426b39  7509                     jne       0x426b44
00426b3b  d905a8b2e900             fld       dword ptr [0xe9b2a8]
00426b41  db7d8c                   fstp      xword ptr [ebp - 0x74]
00426b44  db6d8c                   fld       xword ptr [ebp - 0x74]
00426b47  d91da8885600             fstp      dword ptr [0x5688a8] ; bits=00000000, f32=0.0
00426b4d  6880885600               push      0x568880
00426b52  6844885600               push      0x568844
00426b57  68a4b2e900               push      0xe9b2a4
00426b5c  684c885600               push      0x56884c
00426b61  683c885600               push      0x56883c
00426b66  6854885600               push      0x568854
00426b6b  688cb2e900               push      0xe9b28c
00426b70  6870885600               push      0x568870
00426b75  685c885600               push      0x56885c
00426b7a  6890885600               push      0x568890
00426b7f  68a0b2e900               push      0xe9b2a0
00426b84  68a8885600               push      0x5688a8
00426b89  6828885600               push      0x568828
00426b8e  e83d260200               call      0x4491d0 ; _xlkt22_
00426b93  83c434                   add       esp, 0x34
00426b96  8b1f                     mov       ebx, dword ptr [edi]
00426b98  8b05a0b2e900             mov       eax, dword ptr [0xe9b2a0]
00426b9e  89049db067f100           mov       dword ptr [ebx*4 + 0xf167b0], eax
00426ba5  8b058cb2e900             mov       eax, dword ptr [0xe9b28c]
00426bab  89049df0eaf100           mov       dword ptr [ebx*4 + 0xf1eaf0], eax
00426bb2  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00426bb5  d90580885600             fld       dword ptr [0x568880] ; bits=00000000, f32=0.0
00426bbb  d838                     fdivr     dword ptr [eax]
00426bbd  d91d68885600             fstp      dword ptr [0x568868] ; bits=00000000, f32=0.0
00426bc3  d90568885600             fld       dword ptr [0x568868] ; bits=00000000, f32=0.0
00426bc9  d81d08855600             fcomp     dword ptr [0x568508] ; bits=3333833f, f32=1.024999976158142
00426bcf  dfe0                     fnstsw    ax
00426bd1  9e                       sahf
00426bd2  0f8a0b000000             jp        0x426be3
00426bd8  7609                     jbe       0x426be3
00426bda  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00426bdd  c70002000000             mov       dword ptr [eax], 2
00426be3  db6d98                   fld       xword ptr [ebp - 0x68]
00426be6  db6dbc                   fld       xword ptr [ebp - 0x44]
00426be9  dee9                     fsubp     st(1)
00426beb  d9e1                     fabs
00426bed  d91d90b2e900             fstp      dword ptr [0xe9b290]
00426bf3  d9049d60bdea00           fld       dword ptr [ebx*4 + 0xeabd60]
00426bfa  db6db0                   fld       xword ptr [ebp - 0x50]
00426bfd  d82c9d60bdea00           fsubr     dword ptr [ebx*4 + 0xeabd60]
00426c04  d83590b2e900             fdiv      dword ptr [0xe9b290]
00426c0a  d91d88885600             fstp      dword ptr [0x568888] ; bits=00000000, f32=0.0
00426c10  d90568885600             fld       dword ptr [0x568868] ; bits=00000000, f32=0.0
00426c16  8d0580855600             lea       eax, [0x568580] ; bits=31110000, f32=6.16711454149352e-42
00426c1c  d8508c                   fcom      dword ptr [eax - 0x74]
00426c1f  d9c9                     fxch      st(1)
00426c21  db7d80                   fstp      xword ptr [ebp - 0x80]
00426c24  dbbd74ffffff             fstp      xword ptr [ebp - 0x8c]
00426c2a  898590feffff             mov       dword ptr [ebp - 0x170], eax
00426c30  dfe0                     fnstsw    ax
00426c32  9e                       sahf
00426c33  0f8ab7000000             jp        0x426cf0
00426c39  0f86b1000000             jbe       0x426cf0
00426c3f  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00426c45  dbad74ffffff             fld       xword ptr [ebp - 0x8c]
00426c4b  d85888                   fcomp     dword ptr [eax - 0x78]
00426c4e  dfe0                     fnstsw    ax
00426c50  9e                       sahf
00426c51  0f8a99000000             jp        0x426cf0
00426c57  0f8393000000             jae       0x426cf0
00426c5d  d90588885600             fld       dword ptr [0x568888] ; bits=00000000, f32=0.0
00426c63  d9ee                     fldz
00426c65  d9c9                     fxch      st(1)
00426c67  d81500855600             fcom      dword ptr [0x568500] ; bits=00000000, f32=0.0
00426c6d  dbbd68ffffff             fstp      xword ptr [ebp - 0x98]
00426c73  dbbd5cffffff             fstp      xword ptr [ebp - 0xa4]
00426c79  dfe0                     fnstsw    ax
00426c7b  9e                       sahf
00426c7c  0f8a1e000000             jp        0x426ca0
00426c82  761c                     jbe       0x426ca0
00426c84  dbad68ffffff             fld       xword ptr [ebp - 0x98]
00426c8a  d9fa                     fsqrt
00426c8c  d95df8                   fstp      dword ptr [ebp - 8]
00426c8f  d9058cb2e900             fld       dword ptr [0xe9b28c]
00426c95  d84df8                   fmul      dword ptr [ebp - 8]
00426c98  dbbd50ffffff             fstp      xword ptr [ebp - 0xb0]
00426c9e  eb0c                     jmp       0x426cac
00426ca0  dbad5cffffff             fld       xword ptr [ebp - 0xa4]
00426ca6  dbbd50ffffff             fstp      xword ptr [ebp - 0xb0]
00426cac  dbad50ffffff             fld       xword ptr [ebp - 0xb0]
00426cb2  d81d80885600             fcomp     dword ptr [0x568880] ; bits=00000000, f32=0.0
00426cb8  dfe0                     fnstsw    ax
00426cba  9e                       sahf
00426cbb  0f8a2f000000             jp        0x426cf0
00426cc1  762d                     jbe       0x426cf0
00426cc3  8b06                     mov       eax, dword ptr [esi]
00426cc5  8d0dcc875600             lea       ecx, [0x5687cc] ; bits=09820000, f32=4.664782457890884e-41
00426ccb  8945fc                   mov       dword ptr [ebp - 4], eax
00426cce  8d45fc                   lea       eax, [ebp - 4]
00426cd1  894108                   mov       dword ptr [ecx + 8], eax
00426cd4  51                       push      ecx
00426cd5  e8a6c10700               call      0x4a2e80 ; _jwe_ilst
00426cda  83c404                   add       esp, 4
00426cdd  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00426ce0  c70002000000             mov       dword ptr [eax], 2
00426ce6  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00426ce9  8918                     mov       dword ptr [eax], ebx
00426ceb  e9990a0000               jmp       0x427789
00426cf0  db6da4                   fld       xword ptr [ebp - 0x5c]
00426cf3  d91d94885600             fstp      dword ptr [0x568894] ; bits=00000000, f32=0.0
00426cf9  d90588885600             fld       dword ptr [0x568888] ; bits=00000000, f32=0.0
00426cff  d81d00855600             fcomp     dword ptr [0x568500] ; bits=00000000, f32=0.0
00426d05  dfe0                     fnstsw    ax
00426d07  9e                       sahf
00426d08  0f8a35000000             jp        0x426d43
00426d0e  7633                     jbe       0x426d43
00426d10  db6da4                   fld       xword ptr [ebp - 0x5c]
00426d13  d91da0885600             fstp      dword ptr [0x5688a0] ; bits=00000000, f32=0.0
00426d19  68a0885600               push      0x5688a0
00426d1e  8d049d64caec00           lea       eax, [ebx*4 + 0xecca64]
00426d25  50                       push      eax
00426d26  6888885600               push      0x568888
00426d2b  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00426d2e  8d00                     lea       eax, [eax]
00426d30  50                       push      eax
00426d31  6828885600               push      0x568828
00426d36  8d06                     lea       eax, [esi]
00426d38  50                       push      eax
00426d39  e812190000               call      0x428650 ; _fndnd_
00426d3e  83c418                   add       esp, 0x18
00426d41  eb0a                     jmp       0x426d4d
00426d43  c705a088560000000000     mov       dword ptr [0x5688a0], 0 ; bits=00000000, f32=0.0
00426d4d  8b07                     mov       eax, dword ptr [edi]
00426d4f  8b0da0885600             mov       ecx, dword ptr [0x5688a0] ; bits=00000000, f32=0.0
00426d55  890c85a45aef00           mov       dword ptr [eax*4 + 0xef5aa4], ecx
00426d5c  890d9c885600             mov       dword ptr [0x56889c], ecx ; bits=00000000, f32=0.0
00426d62  6894885600               push      0x568894
00426d67  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00426d6a  89858cfeffff             mov       dword ptr [ebp - 0x174], eax
00426d70  8d08                     lea       ecx, [eax]
00426d72  51                       push      ecx
00426d73  6828885600               push      0x568828
00426d78  8d0e                     lea       ecx, [esi]
00426d7a  51                       push      ecx
00426d7b  e8b01d0000               call      0x428b30 ; _fndcde_
00426d80  83c410                   add       esp, 0x10
00426d83  d905a0b2e900             fld       dword ptr [0xe9b2a0]
00426d89  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00426d8f  d838                     fdivr     dword ptr [eax]
00426d91  d8c8                     fmul      st(0)
00426d93  d80da4b2e900             fmul      dword ptr [0xe9b2a4]
00426d99  d83534bcf400             fdiv      dword ptr [0xf4bc34]
00426d9f  db6da4                   fld       xword ptr [ebp - 0x5c]
00426da2  dec1                     faddp     st(1)
00426da4  dbbd44ffffff             fstp      xword ptr [ebp - 0xbc]
00426daa  8b1f                     mov       ebx, dword ptr [edi]
00426dac  d9049d64caec00           fld       dword ptr [ebx*4 + 0xecca64]
00426db3  dbbd38ffffff             fstp      xword ptr [ebp - 0xc8]
00426db9  89d8                     mov       eax, ebx
00426dbb  48                       dec       eax
00426dbc  8b8d98feffff             mov       ecx, dword ptr [ebp - 0x168]
00426dc2  8b11                     mov       edx, dword ptr [ecx]
00426dc4  bf01000000               mov       edi, 1
00426dc9  29d7                     sub       edi, edx
00426dcb  01c7                     add       edi, eax
00426dcd  83ff00                   cmp       edi, 0
00426dd0  898588feffff             mov       dword ptr [ebp - 0x178], eax
00426dd6  89bd84feffff             mov       dword ptr [ebp - 0x17c], edi
00426ddc  0f8e83090000             jle       0x427765
00426de2  8b8588feffff             mov       eax, dword ptr [ebp - 0x178]
00426de8  89c3                     mov       ebx, eax
00426dea  8b049d64caec00           mov       eax, dword ptr [ebx*4 + 0xecca64]
00426df1  8905a8b2e900             mov       dword ptr [0xe9b2a8], eax
00426df7  d905a8b2e900             fld       dword ptr [0xe9b2a8]
00426dfd  dbbd2cffffff             fstp      xword ptr [ebp - 0xd4]
00426e03  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00426e06  8918                     mov       dword ptr [eax], ebx
00426e08  d9049de4b6e900           fld       dword ptr [ebx*4 + 0xe9b6e4]
00426e0f  db6dc8                   fld       xword ptr [ebp - 0x38]
00426e12  d8249de4b6e900           fsub      dword ptr [ebx*4 + 0xe9b6e4]
00426e19  d9e1                     fabs
00426e1b  d91d90b2e900             fstp      dword ptr [0xe9b290]
00426e21  d9049d64bdea00           fld       dword ptr [ebx*4 + 0xeabd64]
00426e28  8b049de8d0ed00           mov       eax, dword ptr [ebx*4 + 0xedd0e8]
00426e2f  890598b2e900             mov       dword ptr [0xe9b298], eax
00426e35  8b049d2854ee00           mov       eax, dword ptr [ebx*4 + 0xee5428]
00426e3c  89059cb2e900             mov       dword ptr [0xe9b29c], eax
00426e42  db6db0                   fld       xword ptr [ebp - 0x50]
00426e45  d82c9d64bdea00           fsubr     dword ptr [ebx*4 + 0xeabd64]
00426e4c  d83590b2e900             fdiv      dword ptr [0xe9b290]
00426e52  d91d84885600             fstp      dword ptr [0x568884] ; bits=00000000, f32=0.0
00426e58  8b049d243aea00           mov       eax, dword ptr [ebx*4 + 0xea3a24]
00426e5f  890524885600             mov       dword ptr [0x568824], eax ; bits=00000000, f32=0.0
00426e65  890584b2e900             mov       dword ptr [0xe9b284], eax
00426e6b  d90584885600             fld       dword ptr [0x568884] ; bits=00000000, f32=0.0
00426e71  d81500855600             fcom      dword ptr [0x568500] ; bits=00000000, f32=0.0
00426e77  d9c9                     fxch      st(1)
00426e79  db7d80                   fstp      xword ptr [ebp - 0x80]
00426e7c  d9c9                     fxch      st(1)
00426e7e  db7dbc                   fstp      xword ptr [ebp - 0x44]
00426e81  dbbd20ffffff             fstp      xword ptr [ebp - 0xe0]
00426e87  dfe0                     fnstsw    ax
00426e89  9e                       sahf
00426e8a  0f8a5b000000             jp        0x426eeb
00426e90  7659                     jbe       0x426eeb
00426e92  dbad20ffffff             fld       xword ptr [ebp - 0xe0]
00426e98  d82588885600             fsub      dword ptr [0x568888] ; bits=00000000, f32=0.0
00426e9e  d9e1                     fabs
00426ea0  d8c0                     fadd      st(0)
00426ea2  dbad20ffffff             fld       xword ptr [ebp - 0xe0]
00426ea8  d80588885600             fadd      dword ptr [0x568888] ; bits=00000000, f32=0.0
00426eae  def9                     fdivp     st(1)
00426eb0  d81d14855600             fcomp     dword ptr [0x568514] ; bits=0ad7a33b, f32=0.004999999888241291
00426eb6  dfe0                     fnstsw    ax
00426eb8  9e                       sahf
00426eb9  0f8a2c000000             jp        0x426eeb
00426ebf  762a                     jbe       0x426eeb
00426ec1  68a0885600               push      0x5688a0
00426ec6  8d049d68caec00           lea       eax, [ebx*4 + 0xecca68]
00426ecd  50                       push      eax
00426ece  6884885600               push      0x568884
00426ed3  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00426ed6  8d00                     lea       eax, [eax]
00426ed8  50                       push      eax
00426ed9  6828885600               push      0x568828
00426ede  8d06                     lea       eax, [esi]
00426ee0  50                       push      eax
00426ee1  e86a170000               call      0x428650 ; _fndnd_
00426ee6  83c418                   add       esp, 0x18
00426ee9  eb0c                     jmp       0x426ef7
00426eeb  8b059c885600             mov       eax, dword ptr [0x56889c] ; bits=00000000, f32=0.0
00426ef1  8905a0885600             mov       dword ptr [0x5688a0], eax ; bits=00000000, f32=0.0
00426ef7  8b0528885600             mov       eax, dword ptr [0x568828] ; bits=00000000, f32=0.0
00426efd  8b0d24885600             mov       ecx, dword ptr [0x568824] ; bits=00000000, f32=0.0
00426f03  39c8                     cmp       eax, ecx
00426f05  7465                     je        0x426f6c
00426f07  6894885600               push      0x568894
00426f0c  8b7d18                   mov       edi, dword ptr [ebp + 0x18]
00426f0f  8d07                     lea       eax, [edi]
00426f11  50                       push      eax
00426f12  6824885600               push      0x568824
00426f17  8d06                     lea       eax, [esi]
00426f19  50                       push      eax
00426f1a  e8111c0000               call      0x428b30 ; _fndcde_
00426f1f  83c410                   add       esp, 0x10
00426f22  d90584885600             fld       dword ptr [0x568884] ; bits=00000000, f32=0.0
00426f28  d81d00855600             fcomp     dword ptr [0x568500] ; bits=00000000, f32=0.0
00426f2e  dfe0                     fnstsw    ax
00426f30  9e                       sahf
00426f31  0f8a29000000             jp        0x426f60
00426f37  7627                     jbe       0x426f60
00426f39  689c885600               push      0x56889c
00426f3e  8d049d64caec00           lea       eax, [ebx*4 + 0xecca64]
00426f45  50                       push      eax
00426f46  6884885600               push      0x568884
00426f4b  8d07                     lea       eax, [edi]
00426f4d  50                       push      eax
00426f4e  6824885600               push      0x568824
00426f53  8d06                     lea       eax, [esi]
00426f55  50                       push      eax
00426f56  e8f5160000               call      0x428650 ; _fndnd_
00426f5b  83c418                   add       esp, 0x18
00426f5e  eb18                     jmp       0x426f78
00426f60  c7059c88560000000000     mov       dword ptr [0x56889c], 0 ; bits=00000000, f32=0.0
00426f6a  eb0c                     jmp       0x426f78
00426f6c  8b05a0885600             mov       eax, dword ptr [0x5688a0] ; bits=00000000, f32=0.0
00426f72  89059c885600             mov       dword ptr [0x56889c], eax ; bits=00000000, f32=0.0
00426f78  db6da4                   fld       xword ptr [ebp - 0x5c]
00426f7b  d81da0885600             fcomp     dword ptr [0x5688a0] ; bits=00000000, f32=0.0
00426f81  dfe0                     fnstsw    ax
00426f83  9e                       sahf
00426f84  0f8a09000000             jp        0x426f93
00426f8a  7207                     jb        0x426f93
00426f8c  bf01000000               mov       edi, 1
00426f91  eb05                     jmp       0x426f98
00426f93  bfffffffff               mov       edi, 0xffffffff
00426f98  db6db0                   fld       xword ptr [ebp - 0x50]
00426f9b  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00426fa1  dec1                     faddp     st(1)
00426fa3  db6d80                   fld       xword ptr [ebp - 0x80]
00426fa6  dee9                     fsubp     st(1)
00426fa8  d91d80b2e900             fstp      dword ptr [0xe9b280] ; _sberc_
00426fae  6824885600               push      0x568824
00426fb3  e8889e0100               call      0x440e40 ; _fmxarg_
00426fb8  db7dec                   fstp      xword ptr [ebp - 0x14]
00426fbb  83c404                   add       esp, 4
00426fbe  8b0594885600             mov       eax, dword ptr [0x568894] ; bits=00000000, f32=0.0
00426fc4  898580feffff             mov       dword ptr [ebp - 0x180], eax
00426fca  8905a8885600             mov       dword ptr [0x5688a8], eax ; bits=00000000, f32=0.0
00426fd0  68a8885600               push      0x5688a8
00426fd5  e846e8ffff               call      0x425820 ; _sber_
00426fda  d91d64885600             fstp      dword ptr [0x568864] ; bits=00000000, f32=0.0
00426fe0  83c404                   add       esp, 4
00426fe3  d90564885600             fld       dword ptr [0x568864] ; bits=00000000, f32=0.0
00426fe9  dbbd14ffffff             fstp      xword ptr [ebp - 0xec]
00426fef  d9ee                     fldz
00426ff1  dbbd08ffffff             fstp      xword ptr [ebp - 0xf8]
00426ff7  dbad14ffffff             fld       xword ptr [ebp - 0xec]
00426ffd  dbad08ffffff             fld       xword ptr [ebp - 0xf8]
00427003  d9c9                     fxch      st(1)
00427005  ded9                     fcompp
00427007  db6dec                   fld       xword ptr [ebp - 0x14]
0042700a  dfe0                     fnstsw    ax
0042700c  9e                       sahf
0042700d  0f8a9a010000             jp        0x4271ad
00427013  0f8794010000             ja        0x4271ad
00427019  d90594885600             fld       dword ptr [0x568894] ; bits=00000000, f32=0.0
0042701f  db6da4                   fld       xword ptr [ebp - 0x5c]
00427022  d81d94885600             fcomp     dword ptr [0x568894] ; bits=00000000, f32=0.0
00427028  dbbdfcfeffff             fstp      xword ptr [ebp - 0x104]
0042702e  dfe0                     fnstsw    ax
00427030  9e                       sahf
00427031  0f8a0d000000             jp        0x427044
00427037  760b                     jbe       0x427044
00427039  db6da4                   fld       xword ptr [ebp - 0x5c]
0042703c  d91da4885600             fstp      dword ptr [0x5688a4] ; bits=00000000, f32=0.0
00427042  eb12                     jmp       0x427056
00427044  dbadfcfeffff             fld       xword ptr [ebp - 0x104]
0042704a  d80d18855600             fmul      dword ptr [0x568518] ; bits=ae47813f, f32=1.0099999904632568
00427050  d91da4885600             fstp      dword ptr [0x5688a4] ; bits=00000000, f32=0.0
00427056  db7dec                   fstp      xword ptr [ebp - 0x14]
00427059  68a4885600               push      0x5688a4
0042705e  e8bde7ffff               call      0x425820 ; _sber_
00427063  d91d68885600             fstp      dword ptr [0x568868] ; bits=00000000, f32=0.0
00427069  d90568885600             fld       dword ptr [0x568868] ; bits=00000000, f32=0.0
0042706f  83c404                   add       esp, 4
00427072  d81d00855600             fcomp     dword ptr [0x568500] ; bits=00000000, f32=0.0
00427078  db6dec                   fld       xword ptr [ebp - 0x14]
0042707b  dfe0                     fnstsw    ax
0042707d  9e                       sahf
0042707e  0f8aab020000             jp        0x42732f
00427084  0f83a5020000             jae       0x42732f
0042708a  8b0568885600             mov       eax, dword ptr [0x568868] ; bits=00000000, f32=0.0
00427090  890564885600             mov       dword ptr [0x568864], eax ; bits=00000000, f32=0.0
00427096  d905a4885600             fld       dword ptr [0x5688a4] ; bits=00000000, f32=0.0
0042709c  8b05a4885600             mov       eax, dword ptr [0x5688a4] ; bits=00000000, f32=0.0
004270a2  d80d1c855600             fmul      dword ptr [0x56851c] ; bits=6666863f, f32=1.0499999523162842
004270a8  8905a8885600             mov       dword ptr [0x5688a8], eax ; bits=00000000, f32=0.0
004270ae  d91da4885600             fstp      dword ptr [0x5688a4] ; bits=00000000, f32=0.0
004270b4  d9c0                     fld       st(0)
004270b6  d825a4885600             fsub      dword ptr [0x5688a4] ; bits=00000000, f32=0.0
004270bc  d9e1                     fabs
004270be  d81d6cf70e04             fcomp     dword ptr [0x40ef76c]
004270c4  dfe0                     fnstsw    ax
004270c6  9e                       sahf
004270c7  0f8a89ffffff             jp        0x427056
004270cd  7787                     ja        0x427056
004270cf  db7dec                   fstp      xword ptr [ebp - 0x14]
004270d2  6824885600               push      0x568824
004270d7  e824b80100               call      0x442900 ; _gettbn_
004270dc  83c404                   add       esp, 4
004270df  8945fc                   mov       dword ptr [ebp - 4], eax
004270e2  8d45fc                   lea       eax, [ebp - 4]
004270e5  50                       push      eax
004270e6  6a10                     push      0x10
004270e8  68c0885600               push      0x5688c0
004270ed  e89e020500               call      0x477390 ; _get_tabid_
004270f2  83c40c                   add       esp, 0xc
004270f5  8d05b0885600             lea       eax, [0x5688b0] ; bits=00000000, f32=0.0
004270fb  8d0dc0885600             lea       ecx, [0x5688c0] ; bits=00000000, f32=0.0
00427101  8a11                     mov       dl, byte ptr [ecx]
00427103  8810                     mov       byte ptr [eax], dl
00427105  8a5101                   mov       dl, byte ptr [ecx + 1]
00427108  885001                   mov       byte ptr [eax + 1], dl
0042710b  8a5102                   mov       dl, byte ptr [ecx + 2]
0042710e  885002                   mov       byte ptr [eax + 2], dl
00427111  8a5103                   mov       dl, byte ptr [ecx + 3]
00427114  885003                   mov       byte ptr [eax + 3], dl
00427117  8a5104                   mov       dl, byte ptr [ecx + 4]
0042711a  885004                   mov       byte ptr [eax + 4], dl
0042711d  8a5105                   mov       dl, byte ptr [ecx + 5]
00427120  885005                   mov       byte ptr [eax + 5], dl
00427123  8a5106                   mov       dl, byte ptr [ecx + 6]
00427126  885006                   mov       byte ptr [eax + 6], dl
00427129  8a5107                   mov       dl, byte ptr [ecx + 7]
0042712c  885007                   mov       byte ptr [eax + 7], dl
0042712f  8a5108                   mov       dl, byte ptr [ecx + 8]
00427132  885008                   mov       byte ptr [eax + 8], dl
00427135  8a5109                   mov       dl, byte ptr [ecx + 9]
00427138  885009                   mov       byte ptr [eax + 9], dl
0042713b  8a510a                   mov       dl, byte ptr [ecx + 0xa]
0042713e  88500a                   mov       byte ptr [eax + 0xa], dl
00427141  8a510b                   mov       dl, byte ptr [ecx + 0xb]
00427144  88500b                   mov       byte ptr [eax + 0xb], dl
00427147  8a510c                   mov       dl, byte ptr [ecx + 0xc]
0042714a  88500c                   mov       byte ptr [eax + 0xc], dl
0042714d  8a510d                   mov       dl, byte ptr [ecx + 0xd]
00427150  88500d                   mov       byte ptr [eax + 0xd], dl
00427153  8a510e                   mov       dl, byte ptr [ecx + 0xe]
00427156  88500e                   mov       byte ptr [eax + 0xe], dl
00427159  8a510f                   mov       dl, byte ptr [ecx + 0xf]
0042715c  88500f                   mov       byte ptr [eax + 0xf], dl
0042715f  8b1e                     mov       ebx, dword ptr [esi]
00427161  6a10                     push      0x10
00427163  68b0885600               push      0x5688b0
00427168  e8e3880200               call      0x44fa50 ; _lenstr_
0042716d  83c408                   add       esp, 8
00427170  89c2                     mov       edx, eax
00427172  c1fa1f                   sar       edx, 0x1f
00427175  f7d2                     not       edx
00427177  21d0                     and       eax, edx
00427179  8d0d94875600             lea       ecx, [0x568794] ; bits=09020000, f32=7.300764999132297e-43
0042717f  895dfc                   mov       dword ptr [ebp - 4], ebx
00427182  8d55fc                   lea       edx, [ebp - 4]
00427185  895108                   mov       dword ptr [ecx + 8], edx
00427188  894124                   mov       dword ptr [ecx + 0x24], eax
0042718b  db6dec                   fld       xword ptr [ebp - 0x14]
0042718e  d95df8                   fstp      dword ptr [ebp - 8]
00427191  8d45f8                   lea       eax, [ebp - 8]
00427194  894134                   mov       dword ptr [ecx + 0x34], eax
00427197  51                       push      ecx
00427198  e853b40700               call      0x4a25f0 ; _jwe_isfm
0042719d  83c404                   add       esp, 4
004271a0  68d8865600               push      0x5686d8
004271a5  e896c20700               call      0x4a3440 ; _jwe_xstp
004271aa  83c404                   add       esp, 4
004271ad  ddd8                     fstp      st(0)
004271af  dbad14ffffff             fld       xword ptr [ebp - 0xec]
004271b5  d9e1                     fabs
004271b7  d81d68f70e04             fcomp     dword ptr [0x40ef768]
004271bd  dfe0                     fnstsw    ax
004271bf  9e                       sahf
004271c0  0f8a64000000             jp        0x42722a
004271c6  7362                     jae       0x42722a
004271c8  8b8580feffff             mov       eax, dword ptr [ebp - 0x180]
004271ce  890598885600             mov       dword ptr [0x568898], eax ; bits=00000000, f32=0.0
004271d4  687c885600               push      0x56887c
004271d9  6840885600               push      0x568840
004271de  6834885600               push      0x568834
004271e3  6848885600               push      0x568848
004271e8  6838885600               push      0x568838
004271ed  6850885600               push      0x568850
004271f2  6874885600               push      0x568874
004271f7  686c885600               push      0x56886c
004271fc  6858885600               push      0x568858
00427201  688c885600               push      0x56888c
00427206  6830885600               push      0x568830
0042720b  6898885600               push      0x568898
00427210  6824885600               push      0x568824
00427215  e8b61f0200               call      0x4491d0 ; _xlkt22_
0042721a  83c434                   add       esp, 0x34
0042721d  d9e8                     fld1
0042721f  dbbdf0feffff             fstp      xword ptr [ebp - 0x110]
00427225  e93e020000               jmp       0x427468
0042722a  d9059c885600             fld       dword ptr [0x56889c] ; bits=00000000, f32=0.0
00427230  dbad08ffffff             fld       xword ptr [ebp - 0xf8]
00427236  d9c9                     fxch      st(1)
00427238  dde1                     fucom     st(1)
0042723a  ddd9                     fstp      st(1)
0042723c  dbbde4feffff             fstp      xword ptr [ebp - 0x11c]
00427242  dfe0                     fnstsw    ax
00427244  9e                       sahf
00427245  0f8a41000000             jp        0x42728c
0042724b  753f                     jne       0x42728c
0042724d  8b1e                     mov       ebx, dword ptr [esi]
0042724f  8d055c875600             lea       eax, [0x56875c] ; bits=09820000, f32=4.664782457890884e-41
00427255  895dfc                   mov       dword ptr [ebp - 4], ebx
00427258  8d4dfc                   lea       ecx, [ebp - 4]
0042725b  894808                   mov       dword ptr [eax + 8], ecx
0042725e  50                       push      eax
0042725f  e81cbc0700               call      0x4a2e80 ; _jwe_ilst
00427264  83c404                   add       esp, 4
00427267  8d0530875600             lea       eax, [0x568730] ; bits=09820000, f32=4.664782457890884e-41
0042726d  895dfc                   mov       dword ptr [ebp - 4], ebx
00427270  8d4dfc                   lea       ecx, [ebp - 4]
00427273  894808                   mov       dword ptr [eax + 8], ecx
00427276  50                       push      eax
00427277  e804bc0700               call      0x4a2e80 ; _jwe_ilst
0042727c  83c404                   add       esp, 4
0042727f  68cc865600               push      0x5686cc
00427284  e8b7c10700               call      0x4a3440 ; _jwe_xstp
00427289  83c404                   add       esp, 4
0042728c  8b059c885600             mov       eax, dword ptr [0x56889c] ; bits=00000000, f32=0.0
00427292  890598885600             mov       dword ptr [0x568898], eax ; bits=00000000, f32=0.0
00427298  dbade4feffff             fld       xword ptr [ebp - 0x11c]
0042729e  d81da8b2e900             fcomp     dword ptr [0xe9b2a8]
004272a4  dbade4feffff             fld       xword ptr [ebp - 0x11c]
004272aa  dbbdd8feffff             fstp      xword ptr [ebp - 0x128]
004272b0  dfe0                     fnstsw    ax
004272b2  66a90041                 test      ax, 0x4100
004272b6  750c                     jne       0x4272c4
004272b8  d905a8b2e900             fld       dword ptr [0xe9b2a8]
004272be  dbbdd8feffff             fstp      xword ptr [ebp - 0x128]
004272c4  dbadd8feffff             fld       xword ptr [ebp - 0x128]
004272ca  d91da8885600             fstp      dword ptr [0x5688a8] ; bits=00000000, f32=0.0
004272d0  687c885600               push      0x56887c
004272d5  6840885600               push      0x568840
004272da  6834885600               push      0x568834
004272df  6848885600               push      0x568848
004272e4  6838885600               push      0x568838
004272e9  6850885600               push      0x568850
004272ee  6874885600               push      0x568874
004272f3  686c885600               push      0x56886c
004272f8  6858885600               push      0x568858
004272fd  688c885600               push      0x56888c
00427302  6830885600               push      0x568830
00427307  68a8885600               push      0x5688a8
0042730c  6824885600               push      0x568824
00427311  e8ba1e0200               call      0x4491d0 ; _xlkt22_
00427316  83c434                   add       esp, 0x34
00427319  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0042731c  d9057c885600             fld       dword ptr [0x56887c] ; bits=00000000, f32=0.0
00427322  d838                     fdivr     dword ptr [eax]
00427324  dbbdf0feffff             fstp      xword ptr [ebp - 0x110]
0042732a  e939010000               jmp       0x427468
0042732f  ddd8                     fstp      st(0)
00427331  682c885600               push      0x56882c
00427336  6898885600               push      0x568898
0042733b  6868885600               push      0x568868
00427340  6864885600               push      0x568864
00427345  68a4885600               push      0x5688a4
0042734a  68a8885600               push      0x5688a8
0042734f  6820584200               push      0x425820 ; _sber_
00427354  8d0580855600             lea       eax, [0x568580] ; bits=31110000, f32=6.16711454149352e-42
0042735a  8d48a4                   lea       ecx, [eax - 0x5c]
0042735d  51                       push      ecx
0042735e  8d4080                   lea       eax, [eax - 0x80]
00427361  50                       push      eax
00427362  e869b20400               call      0x4725d0 ; _regflt_
00427367  83c424                   add       esp, 0x24
0042736a  833d2c88560001           cmp       dword ptr [0x56882c], 1 ; bits=00000000, f32=0.0
00427371  7527                     jne       0x42739a
00427373  8b06                     mov       eax, dword ptr [esi]
00427375  8d0d10875600             lea       ecx, [0x568710] ; bits=69020000, f32=8.646011524884121e-43
0042737b  8945fc                   mov       dword ptr [ebp - 4], eax
0042737e  8d45fc                   lea       eax, [ebp - 4]
00427381  894108                   mov       dword ptr [ecx + 8], eax
00427384  51                       push      ecx
00427385  e866b20700               call      0x4a25f0 ; _jwe_isfm
0042738a  83c404                   add       esp, 4
0042738d  68c0865600               push      0x5686c0
00427392  e8a9c00700               call      0x4a3440 ; _jwe_xstp
00427397  83c404                   add       esp, 4
0042739a  833d2c88560002           cmp       dword ptr [0x56882c], 2 ; bits=00000000, f32=0.0
004273a1  7527                     jne       0x4273ca
004273a3  8b06                     mov       eax, dword ptr [esi]
004273a5  8d0df0865600             lea       ecx, [0x5686f0] ; bits=69020000, f32=8.646011524884121e-43
004273ab  8945fc                   mov       dword ptr [ebp - 4], eax
004273ae  8d45fc                   lea       eax, [ebp - 4]
004273b1  894108                   mov       dword ptr [ecx + 8], eax
004273b4  51                       push      ecx
004273b5  e836b20700               call      0x4a25f0 ; _jwe_isfm
004273ba  83c404                   add       esp, 4
004273bd  68b4865600               push      0x5686b4
004273c2  e879c00700               call      0x4a3440 ; _jwe_xstp
004273c7  83c404                   add       esp, 4
004273ca  d90598885600             fld       dword ptr [0x568898] ; bits=00000000, f32=0.0
004273d0  d815a8b2e900             fcom      dword ptr [0xe9b2a8]
004273d6  dbbdccfeffff             fstp      xword ptr [ebp - 0x134]
004273dc  dfe0                     fnstsw    ax
004273de  66a90041                 test      ax, 0x4100
004273e2  750c                     jne       0x4273f0
004273e4  d905a8b2e900             fld       dword ptr [0xe9b2a8]
004273ea  dbbdccfeffff             fstp      xword ptr [ebp - 0x134]
004273f0  dbadccfeffff             fld       xword ptr [ebp - 0x134]
004273f6  d91da8885600             fstp      dword ptr [0x5688a8] ; bits=00000000, f32=0.0
004273fc  6840885600               push      0x568840
00427401  6834885600               push      0x568834
00427406  6848885600               push      0x568848
0042740b  6838885600               push      0x568838
00427410  6850885600               push      0x568850
00427415  6874885600               push      0x568874
0042741a  686c885600               push      0x56886c
0042741f  6858885600               push      0x568858
00427424  688c885600               push      0x56888c
00427429  6830885600               push      0x568830
0042742e  68a8885600               push      0x5688a8
00427433  6824885600               push      0x568824
00427438  e863410200               call      0x44b5a0 ; _xlktal_
0042743d  83c430                   add       esp, 0x30
00427440  6878885600               push      0x568878
00427445  68a8885600               push      0x5688a8
0042744a  6824885600               push      0x568824
0042744f  e8bc410200               call      0x44b610 ; _lktqc_
00427454  83c40c                   add       esp, 0xc
00427457  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0042745a  d90578885600             fld       dword ptr [0x568878] ; bits=00000000, f32=0.0
00427460  d838                     fdivr     dword ptr [eax]
00427462  dbbdf0feffff             fstp      xword ptr [ebp - 0x110]
00427468  dbadf0feffff             fld       xword ptr [ebp - 0x110]
0042746e  d81d1c855600             fcomp     dword ptr [0x56851c] ; bits=6666863f, f32=1.0499999523162842
00427474  dfe0                     fnstsw    ax
00427476  9e                       sahf
00427477  0f8aa3000000             jp        0x427520
0042747d  0f869d000000             jbe       0x427520
00427483  db6d80                   fld       xword ptr [ebp - 0x80]
00427486  db6db0                   fld       xword ptr [ebp - 0x50]
00427489  dee9                     fsubp     st(1)
0042748b  d83590b2e900             fdiv      dword ptr [0xe9b290]
00427491  d91d84885600             fstp      dword ptr [0x568884] ; bits=00000000, f32=0.0
00427497  8d4301                   lea       eax, [ebx + 1]
0042749a  8b4d20                   mov       ecx, dword ptr [ebp + 0x20]
0042749d  8901                     mov       dword ptr [ecx], eax
0042749f  8b0594885600             mov       eax, dword ptr [0x568894] ; bits=00000000, f32=0.0
004274a5  89049de4c3eb00           mov       dword ptr [ebx*4 + 0xebc3e4], eax
004274ac  d90584885600             fld       dword ptr [0x568884] ; bits=00000000, f32=0.0
004274b2  d81500855600             fcom      dword ptr [0x568500] ; bits=00000000, f32=0.0
004274b8  dbbdc0feffff             fstp      xword ptr [ebp - 0x140]
004274be  dfe0                     fnstsw    ax
004274c0  9e                       sahf
004274c1  0f8a0d000000             jp        0x4274d4
004274c7  770b                     ja        0x4274d4
004274c9  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004274cc  c700feffffff             mov       dword ptr [eax], 0xfffffffe
004274d2  eb39                     jmp       0x42750d
004274d4  dbadc0feffff             fld       xword ptr [ebp - 0x140]
004274da  d9fa                     fsqrt
004274dc  d95df8                   fstp      dword ptr [ebp - 8]
004274df  d90574885600             fld       dword ptr [0x568874] ; bits=00000000, f32=0.0
004274e5  d84df8                   fmul      dword ptr [ebp - 8]
004274e8  d81d78885600             fcomp     dword ptr [0x568878] ; bits=00000000, f32=0.0
004274ee  dfe0                     fnstsw    ax
004274f0  9e                       sahf
004274f1  0f8a0d000000             jp        0x427504
004274f7  760b                     jbe       0x427504
004274f9  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004274fc  c70000000000             mov       dword ptr [eax], 0
00427502  eb09                     jmp       0x42750d
00427504  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00427507  c700feffffff             mov       dword ptr [eax], 0xfffffffe
0042750d  db6d80                   fld       xword ptr [ebp - 0x80]
00427510  d80598885600             fadd      dword ptr [0x568898] ; bits=00000000, f32=0.0
00427516  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00427519  d918                     fstp      dword ptr [eax]
0042751b  e969020000               jmp       0x427789
00427520  d9059c885600             fld       dword ptr [0x56889c] ; bits=00000000, f32=0.0
00427526  dbad2cffffff             fld       xword ptr [ebp - 0xd4]
0042752c  d9c9                     fxch      st(1)
0042752e  d8d1                     fcom      st(1)
00427530  ddd9                     fstp      st(1)
00427532  dbbdb4feffff             fstp      xword ptr [ebp - 0x14c]
00427538  dfe0                     fnstsw    ax
0042753a  9e                       sahf
0042753b  0f8a75010000             jp        0x4276b6
00427541  0f836f010000             jae       0x4276b6
00427547  d905a0885600             fld       dword ptr [0x5688a0] ; bits=00000000, f32=0.0
0042754d  dbad38ffffff             fld       xword ptr [ebp - 0xc8]
00427553  d9c9                     fxch      st(1)
00427555  ded9                     fcompp
00427557  dfe0                     fnstsw    ax
00427559  9e                       sahf
0042755a  0f8a56010000             jp        0x4276b6
00427560  0f8350010000             jae       0x4276b6
00427566  83ff01                   cmp       edi, 1
00427569  0f85a6000000             jne       0x427615
0042756f  d90598885600             fld       dword ptr [0x568898] ; bits=00000000, f32=0.0
00427575  dbadb4feffff             fld       xword ptr [ebp - 0x14c]
0042757b  d9c9                     fxch      st(1)
0042757d  ded9                     fcompp
0042757f  dfe0                     fnstsw    ax
00427581  9e                       sahf
00427582  0f8a2e010000             jp        0x4276b6
00427588  0f8328010000             jae       0x4276b6
0042758e  8b059c885600             mov       eax, dword ptr [0x56889c] ; bits=00000000, f32=0.0
00427594  890598885600             mov       dword ptr [0x568898], eax ; bits=00000000, f32=0.0
0042759a  d9059c885600             fld       dword ptr [0x56889c] ; bits=00000000, f32=0.0
004275a0  d815a8b2e900             fcom      dword ptr [0xe9b2a8]
004275a6  dbbda8feffff             fstp      xword ptr [ebp - 0x158]
004275ac  dfe0                     fnstsw    ax
004275ae  66a90041                 test      ax, 0x4100
004275b2  750c                     jne       0x4275c0
004275b4  d905a8b2e900             fld       dword ptr [0xe9b2a8]
004275ba  dbbda8feffff             fstp      xword ptr [ebp - 0x158]
004275c0  dbada8feffff             fld       xword ptr [ebp - 0x158]
004275c6  d91da8885600             fstp      dword ptr [0x5688a8] ; bits=00000000, f32=0.0
004275cc  6840885600               push      0x568840
004275d1  6834885600               push      0x568834
004275d6  6848885600               push      0x568848
004275db  6838885600               push      0x568838
004275e0  6850885600               push      0x568850
004275e5  6874885600               push      0x568874
004275ea  686c885600               push      0x56886c
004275ef  6858885600               push      0x568858
004275f4  688c885600               push      0x56888c
004275f9  6830885600               push      0x568830
004275fe  68a8885600               push      0x5688a8
00427603  6824885600               push      0x568824
00427608  e8933f0200               call      0x44b5a0 ; _xlktal_
0042760d  83c430                   add       esp, 0x30
00427610  e9a1000000               jmp       0x4276b6
00427615  d90598885600             fld       dword ptr [0x568898] ; bits=00000000, f32=0.0
0042761b  dbadb4feffff             fld       xword ptr [ebp - 0x14c]
00427621  d9c9                     fxch      st(1)
00427623  ded9                     fcompp
00427625  dfe0                     fnstsw    ax
00427627  9e                       sahf
00427628  0f8a88000000             jp        0x4276b6
0042762e  0f8682000000             jbe       0x4276b6
00427634  8b059c885600             mov       eax, dword ptr [0x56889c] ; bits=00000000, f32=0.0
0042763a  890598885600             mov       dword ptr [0x568898], eax ; bits=00000000, f32=0.0
00427640  d9059c885600             fld       dword ptr [0x56889c] ; bits=00000000, f32=0.0
00427646  d815a8b2e900             fcom      dword ptr [0xe9b2a8]
0042764c  dbbd9cfeffff             fstp      xword ptr [ebp - 0x164]
00427652  dfe0                     fnstsw    ax
00427654  66a90041                 test      ax, 0x4100
00427658  750c                     jne       0x427666
0042765a  d905a8b2e900             fld       dword ptr [0xe9b2a8]
00427660  dbbd9cfeffff             fstp      xword ptr [ebp - 0x164]
00427666  dbad9cfeffff             fld       xword ptr [ebp - 0x164]
0042766c  d91da8885600             fstp      dword ptr [0x5688a8] ; bits=00000000, f32=0.0
00427672  6840885600               push      0x568840
00427677  6834885600               push      0x568834
0042767c  6848885600               push      0x568848
00427681  6838885600               push      0x568838
00427686  6850885600               push      0x568850
0042768b  6874885600               push      0x568874
00427690  686c885600               push      0x56886c
00427695  6858885600               push      0x568858
0042769a  688c885600               push      0x56888c
0042769f  6830885600               push      0x568830
004276a4  68a8885600               push      0x5688a8
004276a9  6824885600               push      0x568824
004276ae  e8ed3e0200               call      0x44b5a0 ; _xlktal_
004276b3  83c430                   add       esp, 0x30
004276b6  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004276b9  d90530885600             fld       dword ptr [0x568830] ; bits=00000000, f32=0.0
004276bf  d838                     fdivr     dword ptr [eax]
004276c1  d8c8                     fmul      st(0)
004276c3  d80d34885600             fmul      dword ptr [0x568834] ; bits=00000000, f32=0.0
004276c9  d83534bcf400             fdiv      dword ptr [0xf4bc34]
004276cf  d90598885600             fld       dword ptr [0x568898] ; bits=00000000, f32=0.0
004276d5  d9c9                     fxch      st(1)
004276d7  d80598885600             fadd      dword ptr [0x568898] ; bits=00000000, f32=0.0
004276dd  dbbd44ffffff             fstp      xword ptr [ebp - 0xbc]
004276e3  db6d80                   fld       xword ptr [ebp - 0x80]
004276e6  db7db0                   fstp      xword ptr [ebp - 0x50]
004276e9  db7da4                   fstp      xword ptr [ebp - 0x5c]
004276ec  db6dbc                   fld       xword ptr [ebp - 0x44]
004276ef  db7dc8                   fstp      xword ptr [ebp - 0x38]
004276f2  8b0530885600             mov       eax, dword ptr [0x568830] ; bits=00000000, f32=0.0
004276f8  8905a0b2e900             mov       dword ptr [0xe9b2a0], eax
004276fe  8b0d34885600             mov       ecx, dword ptr [0x568834] ; bits=00000000, f32=0.0
00427704  890da4b2e900             mov       dword ptr [0xe9b2a4], ecx
0042770a  8b0d74885600             mov       ecx, dword ptr [0x568874] ; bits=00000000, f32=0.0
00427710  890d8cb2e900             mov       dword ptr [0xe9b28c], ecx
00427716  8b1524885600             mov       edx, dword ptr [0x568824] ; bits=00000000, f32=0.0
0042771c  891528885600             mov       dword ptr [0x568828], edx ; bits=00000000, f32=0.0
00427722  8b1584885600             mov       edx, dword ptr [0x568884] ; bits=00000000, f32=0.0
00427728  891588885600             mov       dword ptr [0x568888], edx ; bits=00000000, f32=0.0
0042772e  dbad2cffffff             fld       xword ptr [ebp - 0xd4]
00427734  dbbd38ffffff             fstp      xword ptr [ebp - 0xc8]
0042773a  89049db067f100           mov       dword ptr [ebx*4 + 0xf167b0], eax
00427741  890c9df0eaf100           mov       dword ptr [ebx*4 + 0xf1eaf0], ecx
00427748  8b0598885600             mov       eax, dword ptr [0x568898] ; bits=00000000, f32=0.0
0042774e  89049de4c3eb00           mov       dword ptr [ebx*4 + 0xebc3e4], eax
00427755  83c3ff                   add       ebx, -1
00427758  83ad84feffff01           sub       dword ptr [ebp - 0x17c], 1
0042775f  0f8585f6ffff             jne       0x426dea
00427765  db6d80                   fld       xword ptr [ebp - 0x80]
00427768  d80598885600             fadd      dword ptr [0x568898] ; bits=00000000, f32=0.0
0042776e  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00427771  d918                     fstp      dword ptr [eax]
00427773  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00427779  8b08                     mov       ecx, dword ptr [eax]
0042777b  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0042777e  8908                     mov       dword ptr [eax], ecx
00427780  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00427783  c70001000000             mov       dword ptr [eax], 1
00427789  b800000000               mov       eax, 0
0042778e  5f                       pop       edi
0042778f  5e                       pop       esi
00427790  5b                       pop       ebx
00427791  8be5                     mov       esp, ebp
00427793  5d                       pop       ebp
00427794  c3                       ret
00427795  8d642400                 lea       esp, [esp]
00427799  8da42400000000           lea       esp, [esp]
