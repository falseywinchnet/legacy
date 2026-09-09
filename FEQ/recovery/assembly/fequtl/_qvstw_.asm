; _qvstw_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x12c20
00412c20  55                       push      ebp
00412c21  8bec                     mov       ebp, esp
00412c23  b8bc010000               mov       eax, 0x1bc
00412c28  e8d3630d00               call      0x4e9000 ; __alloca_probe
00412c2d  53                       push      ebx
00412c2e  56                       push      esi
00412c2f  57                       push      edi
00412c30  8b4508                   mov       eax, dword ptr [ebp + 8]
00412c33  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00412c36  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
00412c39  898590feffff             mov       dword ptr [ebp - 0x170], eax
00412c3f  898d8cfeffff             mov       dword ptr [ebp - 0x174], ecx
00412c45  d90518ad5500             fld       dword ptr [0x55ad18] ; bits=caf24971, f32=1.0000000150474662e+30
00412c4b  db7d9c                   fstp      xword ptr [ebp - 0x64]
00412c4e  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00412c51  8b00                     mov       eax, dword ptr [eax]
00412c53  d9048564caec00           fld       dword ptr [eax*4 + 0xecca64]
00412c5a  db7d90                   fstp      xword ptr [ebp - 0x70]
00412c5d  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
00412c60  8b00                     mov       eax, dword ptr [eax]
00412c62  890528b6e900             mov       dword ptr [0xe9b628], eax
00412c68  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00412c6e  8b08                     mov       ecx, dword ptr [eax]
00412c70  8b7534                   mov       esi, dword ptr [ebp + 0x34]
00412c73  8b958cfeffff             mov       edx, dword ptr [ebp - 0x174]
00412c79  d906                     fld       dword ptr [esi]
00412c7b  d82a                     fsubr     dword ptr [edx]
00412c7d  8b7d38                   mov       edi, dword ptr [ebp + 0x38]
00412c80  d907                     fld       dword ptr [edi]
00412c82  d802                     fadd      dword ptr [edx]
00412c84  8d3dd4b45500             lea       edi, [0x55b4d4] ; bits=09020000, f32=7.300764999132297e-43
00412c8a  894dfc                   mov       dword ptr [ebp - 4], ecx
00412c8d  8d4dfc                   lea       ecx, [ebp - 4]
00412c90  894f08                   mov       dword ptr [edi + 8], ecx
00412c93  d9c9                     fxch      st(1)
00412c95  d95df8                   fstp      dword ptr [ebp - 8]
00412c98  8d4df8                   lea       ecx, [ebp - 8]
00412c9b  894f28                   mov       dword ptr [edi + 0x28], ecx
00412c9e  d95df4                   fstp      dword ptr [ebp - 0xc]
00412ca1  8d4df4                   lea       ecx, [ebp - 0xc]
00412ca4  894f34                   mov       dword ptr [edi + 0x34], ecx
00412ca7  57                       push      edi
00412ca8  e843f90800               call      0x4a25f0 ; _jwe_isfm
00412cad  83c404                   add       esp, 4
00412cb0  6a08                     push      8
00412cb2  6858b55500               push      0x55b558
00412cb7  68a4f3f200               push      0xf2f3a4
00412cbc  e8efc50300               call      0x44f2b0 ; _var_decimal_
00412cc1  83c40c                   add       esp, 0xc
00412cc4  6a08                     push      8
00412cc6  6860b55500               push      0x55b560
00412ccb  682cbbf400               push      0xf4bb2c
00412cd0  e8dbc50300               call      0x44f2b0 ; _var_decimal_
00412cd5  83c40c                   add       esp, 0xc
00412cd8  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00412cde  8b08                     mov       ecx, dword ptr [eax]
00412ce0  d906                     fld       dword ptr [esi]
00412ce2  d90548b6e900             fld       dword ptr [0xe9b648]
00412ce8  d826                     fsub      dword ptr [esi]
00412cea  db7d84                   fstp      xword ptr [ebp - 0x7c]
00412ced  8b1550b6e900             mov       edx, dword ptr [0xe9b650]
00412cf3  d82da8f4f200             fsubr     dword ptr [0xf2f4a8]
00412cf9  dbbd78ffffff             fstp      xword ptr [ebp - 0x88]
00412cff  db6d90                   fld       xword ptr [ebp - 0x70]
00412d02  d81db0f3f200             fcomp     dword ptr [0xf2f3b0]
00412d08  db6d90                   fld       xword ptr [ebp - 0x70]
00412d0b  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
00412d11  dfe0                     fnstsw    ax
00412d13  66a90041                 test      ax, 0x4100
00412d17  898d88feffff             mov       dword ptr [ebp - 0x178], ecx
00412d1d  899584feffff             mov       dword ptr [ebp - 0x17c], edx
00412d23  750c                     jne       0x412d31
00412d25  d905b0f3f200             fld       dword ptr [0xf2f3b0]
00412d2b  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
00412d31  d905a8f4f200             fld       dword ptr [0xf2f4a8]
00412d37  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00412d3d  d828                     fsubr     dword ptr [eax]
00412d3f  8b4d3c                   mov       ecx, dword ptr [ebp + 0x3c]
00412d42  8b09                     mov       ecx, dword ptr [ecx]
00412d44  8d1554b45500             lea       edx, [0x55b454] ; bits=09020000, f32=7.300764999132297e-43
00412d4a  8bb588feffff             mov       esi, dword ptr [ebp - 0x178]
00412d50  8975fc                   mov       dword ptr [ebp - 4], esi
00412d53  8d75fc                   lea       esi, [ebp - 4]
00412d56  897208                   mov       dword ptr [edx + 8], esi
00412d59  db6d84                   fld       xword ptr [ebp - 0x7c]
00412d5c  d95df8                   fstp      dword ptr [ebp - 8]
00412d5f  8d75f8                   lea       esi, [ebp - 8]
00412d62  897228                   mov       dword ptr [edx + 0x28], esi
00412d65  8bb584feffff             mov       esi, dword ptr [ebp - 0x17c]
00412d6b  8975f4                   mov       dword ptr [ebp - 0xc], esi
00412d6e  8d75f4                   lea       esi, [ebp - 0xc]
00412d71  897234                   mov       dword ptr [edx + 0x34], esi
00412d74  dbad78ffffff             fld       xword ptr [ebp - 0x88]
00412d7a  d95df0                   fstp      dword ptr [ebp - 0x10]
00412d7d  8d75f0                   lea       esi, [ebp - 0x10]
00412d80  897240                   mov       dword ptr [edx + 0x40], esi
00412d83  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00412d89  d95dec                   fstp      dword ptr [ebp - 0x14]
00412d8c  8d75ec                   lea       esi, [ebp - 0x14]
00412d8f  89724c                   mov       dword ptr [edx + 0x4c], esi
00412d92  d95de8                   fstp      dword ptr [ebp - 0x18]
00412d95  8d75e8                   lea       esi, [ebp - 0x18]
00412d98  897258                   mov       dword ptr [edx + 0x58], esi
00412d9b  894de4                   mov       dword ptr [ebp - 0x1c], ecx
00412d9e  8d4de4                   lea       ecx, [ebp - 0x1c]
00412da1  894a64                   mov       dword ptr [edx + 0x64], ecx
00412da4  52                       push      edx
00412da5  e846f80800               call      0x4a25f0 ; _jwe_isfm
00412daa  83c404                   add       esp, 4
00412dad  8b03                     mov       eax, dword ptr [ebx]
00412daf  d9048564caec00           fld       dword ptr [eax*4 + 0xecca64]
00412db6  dbbd60ffffff             fstp      xword ptr [ebp - 0xa0]
00412dbc  890500b6e900             mov       dword ptr [0xe9b600], eax ; _rqvtw_
00412dc2  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00412dc5  8b00                     mov       eax, dword ptr [eax]
00412dc7  890504b6e900             mov       dword ptr [0xe9b604], eax
00412dcd  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00412dd3  8b08                     mov       ecx, dword ptr [eax]
00412dd5  890d14b6e900             mov       dword ptr [0xe9b614], ecx
00412ddb  8b4d20                   mov       ecx, dword ptr [ebp + 0x20]
00412dde  8b09                     mov       ecx, dword ptr [ecx]
00412de0  890d08b6e900             mov       dword ptr [0xe9b608], ecx
00412de6  8d0d30b6e900             lea       ecx, [0xe9b630] ; _rqvtc_
00412dec  8b5524                   mov       edx, dword ptr [ebp + 0x24]
00412def  8d12                     lea       edx, [edx]
00412df1  8a02                     mov       al, byte ptr [edx]
00412df3  8801                     mov       byte ptr [ecx], al
00412df5  8a4201                   mov       al, byte ptr [edx + 1]
00412df8  884101                   mov       byte ptr [ecx + 1], al
00412dfb  8a4202                   mov       al, byte ptr [edx + 2]
00412dfe  884102                   mov       byte ptr [ecx + 2], al
00412e01  8a4203                   mov       al, byte ptr [edx + 3]
00412e04  884103                   mov       byte ptr [ecx + 3], al
00412e07  8a4204                   mov       al, byte ptr [edx + 4]
00412e0a  884104                   mov       byte ptr [ecx + 4], al
00412e0d  8a4205                   mov       al, byte ptr [edx + 5]
00412e10  884105                   mov       byte ptr [ecx + 5], al
00412e13  8a4206                   mov       al, byte ptr [edx + 6]
00412e16  884106                   mov       byte ptr [ecx + 6], al
00412e19  8a4207                   mov       al, byte ptr [edx + 7]
00412e1c  884107                   mov       byte ptr [ecx + 7], al
00412e1f  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00412e22  8b00                     mov       eax, dword ptr [eax]
00412e24  890518b6e900             mov       dword ptr [0xe9b618], eax
00412e2a  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00412e30  8b08                     mov       ecx, dword ptr [eax]
00412e32  890d1cb6e900             mov       dword ptr [0xe9b61c], ecx
00412e38  d905e4f4f200             fld       dword ptr [0xf2f4e4]
00412e3e  d9c0                     fld       st(0)
00412e40  dd1dd8156400             fstp      qword ptr [0x6415d8]
00412e46  d905e8f4f200             fld       dword ptr [0xf2f4e8]
00412e4c  dd1d780c6400             fstp      qword ptr [0x640c78]
00412e52  d825acf3f200             fsub      dword ptr [0xf2f3ac]
00412e58  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00412e5e  d905b0f3f200             fld       dword ptr [0xf2f3b0]
00412e64  db6d90                   fld       xword ptr [ebp - 0x70]
00412e67  d9c9                     fxch      st(1)
00412e69  ded9                     fcompp
00412e6b  dfe0                     fnstsw    ax
00412e6d  9e                       sahf
00412e6e  0f8a0b000000             jp        0x412e7f
00412e74  7609                     jbe       0x412e7f
00412e76  db6d90                   fld       xword ptr [ebp - 0x70]
00412e79  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00412e7f  68f0f3f200               push      0xf2f3f0
00412e84  68d8f3f200               push      0xf2f3d8
00412e89  68d4f3f200               push      0xf2f3d4
00412e8e  68d0f3f200               push      0xf2f3d0
00412e93  68ccf3f200               push      0xf2f3cc
00412e98  68c8f3f200               push      0xf2f3c8
00412e9d  68c4f3f200               push      0xf2f3c4
00412ea2  68c0f3f200               push      0xf2f3c0
00412ea7  68b8f3f200               push      0xf2f3b8
00412eac  68b4f3f200               push      0xf2f3b4
00412eb1  68bcf3f200               push      0xf2f3bc
00412eb6  68b0f3f200               push      0xf2f3b0
00412ebb  68a0f3f200               push      0xf2f3a0 ; _xs3com_
00412ec0  e80b630300               call      0x4491d0 ; _xlkt22_
00412ec5  83c434                   add       esp, 0x34
00412ec8  8b05fcf3f200             mov       eax, dword ptr [0xf2f3fc]
00412ece  890568fe6300             mov       dword ptr [0x63fe68], eax
00412ed4  d90550b6e900             fld       dword ptr [0xe9b650]
00412eda  dd1d881a6400             fstp      qword ptr [0x641a88]
00412ee0  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00412ee6  d900                     fld       dword ptr [eax]
00412ee8  d905e4f4f200             fld       dword ptr [0xf2f4e4]
00412eee  d9c0                     fld       st(0)
00412ef0  d828                     fsubr     dword ptr [eax]
00412ef2  d9c0                     fld       st(0)
00412ef4  dd1d18036400             fstp      qword ptr [0x640318]
00412efa  d9fa                     fsqrt
00412efc  d95df8                   fstp      dword ptr [ebp - 8]
00412eff  d945f8                   fld       dword ptr [ebp - 8]
00412f02  dd1d28116400             fstp      qword ptr [0x641128]
00412f08  8b0de8f4f200             mov       ecx, dword ptr [0xf2f4e8]
00412f0e  890d28b55500             mov       dword ptr [0x55b528], ecx ; bits=00000000, f32=0.0
00412f14  d9c9                     fxch      st(1)
00412f16  dbbd54ffffff             fstp      xword ptr [ebp - 0xac]
00412f1c  dbad54ffffff             fld       xword ptr [ebp - 0xac]
00412f22  dee1                     fsubrp    st(1)
00412f24  dbbd48ffffff             fstp      xword ptr [ebp - 0xb8]
00412f2a  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
00412f30  d81d10ad5500             fcomp     dword ptr [0x55ad10] ; bits=00000000, f32=0.0
00412f36  dfe0                     fnstsw    ax
00412f38  9e                       sahf
00412f39  0f8a3e000000             jp        0x412f7d
00412f3f  773c                     ja        0x412f7d
00412f41  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00412f47  8b08                     mov       ecx, dword ptr [eax]
00412f49  8d0528b45500             lea       eax, [0x55b428] ; bits=09020000, f32=7.300764999132297e-43
00412f4f  894dfc                   mov       dword ptr [ebp - 4], ecx
00412f52  8d4dfc                   lea       ecx, [ebp - 4]
00412f55  894808                   mov       dword ptr [eax + 8], ecx
00412f58  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
00412f5e  d95df8                   fstp      dword ptr [ebp - 8]
00412f61  8d4df8                   lea       ecx, [ebp - 8]
00412f64  894828                   mov       dword ptr [eax + 0x28], ecx
00412f67  50                       push      eax
00412f68  e883f60800               call      0x4a25f0 ; _jwe_isfm
00412f6d  83c404                   add       esp, 4
00412f70  68b0af5500               push      0x55afb0
00412f75  e8c6040900               call      0x4a3440 ; _jwe_xstp
00412f7a  83c404                   add       esp, 4
00412f7d  8b05e4f4f200             mov       eax, dword ptr [0xf2f4e4]
00412f83  8905c0006400             mov       dword ptr [0x6400c0], eax
00412f89  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00412f8c  8b08                     mov       ecx, dword ptr [eax]
00412f8e  8d41ff                   lea       eax, [ecx - 1]
00412f91  8d50ff                   lea       edx, [eax - 1]
00412f94  89d3                     mov       ebx, edx
00412f96  83fb00                   cmp       ebx, 0
00412f99  898580feffff             mov       dword ptr [ebp - 0x180], eax
00412f9f  898d7cfeffff             mov       dword ptr [ebp - 0x184], ecx
00412fa5  899578feffff             mov       dword ptr [ebp - 0x188], edx
00412fab  0f8e78010000             jle       0x413129
00412fb1  b802000000               mov       eax, 2
00412fb6  8b8d80feffff             mov       ecx, dword ptr [ebp - 0x180]
00412fbc  894dfc                   mov       dword ptr [ebp - 4], ecx
00412fbf  d9e8                     fld1
00412fc1  da75fc                   fidiv     dword ptr [ebp - 4]
00412fc4  dbbd3cffffff             fstp      xword ptr [ebp - 0xc4]
00412fca  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00412fcd  8b11                     mov       edx, dword ptr [ecx]
00412fcf  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
00412fd5  8d71fe                   lea       esi, [ecx - 2]
00412fd8  8975fc                   mov       dword ptr [ebp - 4], esi
00412fdb  db45fc                   fild      dword ptr [ebp - 4]
00412fde  dbbd30ffffff             fstp      xword ptr [ebp - 0xd0]
00412fe4  83fb02                   cmp       ebx, 2
00412fe7  898574feffff             mov       dword ptr [ebp - 0x18c], eax
00412fed  899570feffff             mov       dword ptr [ebp - 0x190], edx
00412ff3  0f8ce1000000             jl        0x4130da
00412ff9  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
00412fff  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
00413005  dbad3cffffff             fld       xword ptr [ebp - 0xc4]
0041300b  db7da8                   fstp      xword ptr [ebp - 0x58]
0041300e  db7db4                   fstp      xword ptr [ebp - 0x4c]
00413011  db7dc0                   fstp      xword ptr [ebp - 0x40]
00413014  db6dc0                   fld       xword ptr [ebp - 0x40]
00413017  db6da8                   fld       xword ptr [ebp - 0x58]
0041301a  dec9                     fmulp     st(1)
0041301c  d95df8                   fstp      dword ptr [ebp - 8]
0041301f  8b8570feffff             mov       eax, dword ptr [ebp - 0x190]
00413025  8945f4                   mov       dword ptr [ebp - 0xc], eax
00413028  8d4df4                   lea       ecx, [ebp - 0xc]
0041302b  51                       push      ecx
0041302c  8d4df8                   lea       ecx, [ebp - 8]
0041302f  51                       push      ecx
00413030  e87bd70800               call      0x4a07b0 ; _g_arxr
00413035  83c408                   add       esp, 8
00413038  d82d1cad5500             fsubr     dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
0041303e  db6db4                   fld       xword ptr [ebp - 0x4c]
00413041  dec9                     fmulp     st(1)
00413043  d805e4f4f200             fadd      dword ptr [0xf2f4e4]
00413049  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
0041304f  d91c85bc006400           fstp      dword ptr [eax*4 + 0x6400bc]
00413056  db6dc0                   fld       xword ptr [ebp - 0x40]
00413059  d8251cad5500             fsub      dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
0041305f  db7dcc                   fstp      xword ptr [ebp - 0x34]
00413062  db6dcc                   fld       xword ptr [ebp - 0x34]
00413065  db6da8                   fld       xword ptr [ebp - 0x58]
00413068  dec9                     fmulp     st(1)
0041306a  d95df8                   fstp      dword ptr [ebp - 8]
0041306d  8b8d70feffff             mov       ecx, dword ptr [ebp - 0x190]
00413073  894df4                   mov       dword ptr [ebp - 0xc], ecx
00413076  8d55f4                   lea       edx, [ebp - 0xc]
00413079  52                       push      edx
0041307a  8d55f8                   lea       edx, [ebp - 8]
0041307d  52                       push      edx
0041307e  e82dd70800               call      0x4a07b0 ; _g_arxr
00413083  83c408                   add       esp, 8
00413086  d82d1cad5500             fsubr     dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
0041308c  db6db4                   fld       xword ptr [ebp - 0x4c]
0041308f  dec9                     fmulp     st(1)
00413091  d805e4f4f200             fadd      dword ptr [0xf2f4e4]
00413097  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
0041309d  d91c85c0006400           fstp      dword ptr [eax*4 + 0x6400c0]
004130a4  db6dcc                   fld       xword ptr [ebp - 0x34]
004130a7  d8251cad5500             fsub      dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
004130ad  db6db4                   fld       xword ptr [ebp - 0x4c]
004130b0  db6da8                   fld       xword ptr [ebp - 0x58]
004130b3  83c002                   add       eax, 2
004130b6  83eb02                   sub       ebx, 2
004130b9  83fb02                   cmp       ebx, 2
004130bc  898574feffff             mov       dword ptr [ebp - 0x18c], eax
004130c2  0f8d43ffffff             jge       0x41300b
004130c8  dbbd3cffffff             fstp      xword ptr [ebp - 0xc4]
004130ce  dbbd48ffffff             fstp      xword ptr [ebp - 0xb8]
004130d4  dbbd30ffffff             fstp      xword ptr [ebp - 0xd0]
004130da  85db                     test      ebx, ebx
004130dc  744b                     je        0x413129
004130de  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
004130e4  dbad3cffffff             fld       xword ptr [ebp - 0xc4]
004130ea  dec9                     fmulp     st(1)
004130ec  d95df8                   fstp      dword ptr [ebp - 8]
004130ef  8b8570feffff             mov       eax, dword ptr [ebp - 0x190]
004130f5  8945f4                   mov       dword ptr [ebp - 0xc], eax
004130f8  8d45f4                   lea       eax, [ebp - 0xc]
004130fb  50                       push      eax
004130fc  8d45f8                   lea       eax, [ebp - 8]
004130ff  50                       push      eax
00413100  e8abd60800               call      0x4a07b0 ; _g_arxr
00413105  83c408                   add       esp, 8
00413108  d82d1cad5500             fsubr     dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
0041310e  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
00413114  dec9                     fmulp     st(1)
00413116  d805e4f4f200             fadd      dword ptr [0xf2f4e4]
0041311c  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
00413122  d91c85bc006400           fstp      dword ptr [eax*4 + 0x6400bc]
00413129  8b857cfeffff             mov       eax, dword ptr [ebp - 0x184]
0041312f  dbad54ffffff             fld       xword ptr [ebp - 0xac]
00413135  d91c85bc006400           fstp      dword ptr [eax*4 + 0x6400bc]
0041313c  8b9d78feffff             mov       ebx, dword ptr [ebp - 0x188]
00413142  899d6cfeffff             mov       dword ptr [ebp - 0x194], ebx
00413148  83fb00                   cmp       ebx, 0
0041314b  0f8e24100000             jle       0x414175
00413151  b802000000               mov       eax, 2
00413156  898574feffff             mov       dword ptr [ebp - 0x18c], eax
0041315c  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
00413162  8b0c85bc006400           mov       ecx, dword ptr [eax*4 + 0x6400bc]
00413169  890d34b55500             mov       dword ptr [0x55b534], ecx ; bits=00000000, f32=0.0
0041316f  890de0f3f200             mov       dword ptr [0xf2f3e0], ecx
00413175  d905acf3f200             fld       dword ptr [0xf2f3ac]
0041317b  d82d34b55500             fsubr     dword ptr [0x55b534] ; bits=00000000, f32=0.0
00413181  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00413187  8b0db0f3f200             mov       ecx, dword ptr [0xf2f3b0]
0041318d  890de4f3f200             mov       dword ptr [0xf2f3e4], ecx
00413193  d905b0f3f200             fld       dword ptr [0xf2f3b0]
00413199  db6d90                   fld       xword ptr [ebp - 0x70]
0041319c  d9c9                     fxch      st(1)
0041319e  ded9                     fcompp
004131a0  dfe0                     fnstsw    ax
004131a2  9e                       sahf
004131a3  0f8a0b000000             jp        0x4131b4
004131a9  7609                     jbe       0x4131b4
004131ab  db6d90                   fld       xword ptr [ebp - 0x70]
004131ae  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
004131b4  d90534b55500             fld       dword ptr [0x55b534] ; bits=00000000, f32=0.0
004131ba  d81d08b6e900             fcomp     dword ptr [0xe9b608]
004131c0  dfe0                     fnstsw    ax
004131c2  9e                       sahf
004131c3  0f8adc000000             jp        0x4132a5
004131c9  0f86d6000000             jbe       0x4132a5
004131cf  6a08                     push      8
004131d1  6834bbf400               push      0xf4bb34
004131d6  6830bbf400               push      0xf4bb30
004131db  682cbbf400               push      0xf4bb2c
004131e0  6804bbf400               push      0xf4bb04
004131e5  6864abf400               push      0xf4ab64
004131ea  68c49bf400               push      0xf49bc4
004131ef  68248cf400               push      0xf48c24
004131f4  68847cf400               push      0xf47c84
004131f9  68e46cf400               push      0xf46ce4
004131fe  68445df400               push      0xf45d44
00413203  68a44df400               push      0xf44da4
00413208  68043ef400               push      0xf43e04
0041320d  68642ef400               push      0xf42e64
00413212  68c41ef400               push      0xf41ec4
00413217  68240ff400               push      0xf40f24
0041321c  6884fff300               push      0xf3ff84
00413221  68e4eff300               push      0xf3efe4
00413226  6844e0f300               push      0xf3e044
0041322b  68a4d0f300               push      0xf3d0a4
00413230  6804c1f300               push      0xf3c104
00413235  6864b1f300               push      0xf3b164
0041323a  68c4a1f300               push      0xf3a1c4
0041323f  682492f300               push      0xf39224
00413244  688482f300               push      0xf38284
00413249  68e472f300               push      0xf372e4
0041324e  684463f300               push      0xf36344
00413253  68a453f300               push      0xf353a4
00413258  6898bbf400               push      0xf4bb98
0041325d  68c0f5f200               push      0xf2f5c0 ; _embcmc_
00413262  680015f300               push      0xf31500 ; _embcom_
00413267  681c15f300               push      0xf3151c
0041326c  681815f300               push      0xf31518
00413271  681415f300               push      0xf31514
00413276  681015f300               push      0xf31510
0041327b  680c15f300               push      0xf3150c
00413280  680815f300               push      0xf31508
00413285  6834b55500               push      0x55b534
0041328a  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00413290  8d08                     lea       ecx, [eax]
00413292  51                       push      ecx
00413293  6814b6e900               push      0xe9b614
00413298  e8832e0100               call      0x426120 ; _sbfebc_
0041329d  81c4a0000000             add       esp, 0xa0
004132a3  eb24                     jmp       0x4132c9
004132a5  8b0520bbf400             mov       eax, dword ptr [0xf4bb20] ; _rdfcom_
004132ab  89052cbbf400             mov       dword ptr [0xf4bb2c], eax
004132b1  8b0524bbf400             mov       eax, dword ptr [0xf4bb24]
004132b7  890530bbf400             mov       dword ptr [0xf4bb30], eax
004132bd  8b0528bbf400             mov       eax, dword ptr [0xf4bb28]
004132c3  890534bbf400             mov       dword ptr [0xf4bb34], eax
004132c9  833db8b6e90004           cmp       dword ptr [0xe9b6b8], 4
004132d0  0f8598000000             jne       0x41336e
004132d6  8b05e8f2f200             mov       eax, dword ptr [0xf2f2e8]
004132dc  8905e0f2f200             mov       dword ptr [0xf2f2e0], eax ; _cdcom_
004132e2  8b05bcb6e900             mov       eax, dword ptr [0xe9b6bc]
004132e8  890508f3f200             mov       dword ptr [0xf2f308], eax
004132ee  6848b6e900               push      0xe9b648
004132f3  6828b55500               push      0x55b528
004132f8  68e0f3f200               push      0xf2f3e0
004132fd  6808f3f200               push      0xf2f308
00413302  68e0f2f200               push      0xf2f2e0 ; _cdcom_
00413307  6800f4f200               push      0xf2f400
0041330c  68c0b6e900               push      0xe9b6c0
00413311  68bcb6e900               push      0xe9b6bc
00413316  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
0041331c  8d08                     lea       ecx, [eax]
0041331e  51                       push      ecx
0041331f  8b4d30                   mov       ecx, dword ptr [ebp + 0x30]
00413322  8d09                     lea       ecx, [ecx]
00413324  51                       push      ecx
00413325  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
00413328  8d09                     lea       ecx, [ecx]
0041332a  51                       push      ecx
0041332b  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0041332e  8d09                     lea       ecx, [ecx]
00413330  51                       push      ecx
00413331  8b8d90feffff             mov       ecx, dword ptr [ebp - 0x170]
00413337  8d11                     lea       edx, [ecx]
00413339  52                       push      edx
0041333a  e821260100               call      0x425960 ; _fulbar_
0041333f  83c434                   add       esp, 0x34
00413342  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00413348  d91d50b6e900             fstp      dword ptr [0xe9b650]
0041334e  db6d90                   fld       xword ptr [ebp - 0x70]
00413351  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00413357  d9054cb6e900             fld       dword ptr [0xe9b64c]
0041335d  d82d48b6e900             fsubr     dword ptr [0xe9b648]
00413363  d91dc4b6e900             fstp      dword ptr [0xe9b6c4]
00413369  e9f20b0000               jmp       0x413f60
0041336e  833db8b6e9002a           cmp       dword ptr [0xe9b6b8], 0x2a
00413375  0f8528010000             jne       0x4134a3
0041337b  8b05bcb6e900             mov       eax, dword ptr [0xe9b6bc]
00413381  890508f3f200             mov       dword ptr [0xf2f308], eax
00413387  d905e4f3f200             fld       dword ptr [0xf2f3e4]
0041338d  db6d90                   fld       xword ptr [ebp - 0x70]
00413390  d9c9                     fxch      st(1)
00413392  d8d1                     fcom      st(1)
00413394  ddd9                     fstp      st(1)
00413396  dbbd24ffffff             fstp      xword ptr [ebp - 0xdc]
0041339c  dfe0                     fnstsw    ax
0041339e  9e                       sahf
0041339f  0f8a24000000             jp        0x4133c9
004133a5  7222                     jb        0x4133c9
004133a7  8b05e8f2f200             mov       eax, dword ptr [0xf2f2e8]
004133ad  8905e0f2f200             mov       dword ptr [0xf2f2e0], eax ; _cdcom_
004133b3  c705b8b6e90004000000     mov       dword ptr [0xe9b6b8], 4
004133bd  c70520b6e90004000000     mov       dword ptr [0xe9b620], 4
004133c7  eb5a                     jmp       0x413423
004133c9  833d9cb6e90006           cmp       dword ptr [0xe9b69c], 6
004133d0  750e                     jne       0x4133e0
004133d2  8b05e8f2f200             mov       eax, dword ptr [0xf2f2e8]
004133d8  8905e0f2f200             mov       dword ptr [0xf2f2e0], eax ; _cdcom_
004133de  eb2f                     jmp       0x41340f
004133e0  dbad24ffffff             fld       xword ptr [ebp - 0xdc]
004133e6  d82550bbf400             fsub      dword ptr [0xf4bb50]
004133ec  d90544bbf400             fld       dword ptr [0xf4bb44]
004133f2  d9c0                     fld       st(0)
004133f4  d82de8f2f200             fsubr     dword ptr [0xf2f2e8]
004133fa  deca                     fmulp     st(2)
004133fc  db6d90                   fld       xword ptr [ebp - 0x70]
004133ff  d82550bbf400             fsub      dword ptr [0xf4bb50]
00413405  defa                     fdivp     st(2)
00413407  dec1                     faddp     st(1)
00413409  d91de0f2f200             fstp      dword ptr [0xf2f2e0] ; _cdcom_
0041340f  c705b8b6e9002a000000     mov       dword ptr [0xe9b6b8], 0x2a
00413419  c70520b6e9002a000000     mov       dword ptr [0xe9b620], 0x2a
00413423  6848b6e900               push      0xe9b648
00413428  6828b55500               push      0x55b528
0041342d  68e0f3f200               push      0xf2f3e0
00413432  6808f3f200               push      0xf2f308
00413437  68e0f2f200               push      0xf2f2e0 ; _cdcom_
0041343c  6800f4f200               push      0xf2f400
00413441  68c0b6e900               push      0xe9b6c0
00413446  68bcb6e900               push      0xe9b6bc
0041344b  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00413451  8d08                     lea       ecx, [eax]
00413453  51                       push      ecx
00413454  8b4d30                   mov       ecx, dword ptr [ebp + 0x30]
00413457  8d09                     lea       ecx, [ecx]
00413459  51                       push      ecx
0041345a  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
0041345d  8d09                     lea       ecx, [ecx]
0041345f  51                       push      ecx
00413460  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
00413463  8d09                     lea       ecx, [ecx]
00413465  51                       push      ecx
00413466  8b8d90feffff             mov       ecx, dword ptr [ebp - 0x170]
0041346c  8d11                     lea       edx, [ecx]
0041346e  52                       push      edx
0041346f  e8ec240100               call      0x425960 ; _fulbar_
00413474  83c434                   add       esp, 0x34
00413477  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0041347d  d91d50b6e900             fstp      dword ptr [0xe9b650]
00413483  db6d90                   fld       xword ptr [ebp - 0x70]
00413486  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
0041348c  d9054cb6e900             fld       dword ptr [0xe9b64c]
00413492  d82d48b6e900             fsubr     dword ptr [0xe9b648]
00413498  d91dc4b6e900             fstp      dword ptr [0xe9b6c4]
0041349e  e9bd0a0000               jmp       0x413f60
004134a3  833d9cb6e90006           cmp       dword ptr [0xe9b69c], 6
004134aa  0f85da000000             jne       0x41358a
004134b0  8b05e8f2f200             mov       eax, dword ptr [0xf2f2e8]
004134b6  8905e0f2f200             mov       dword ptr [0xf2f2e0], eax ; _cdcom_
004134bc  8b05bcb6e900             mov       eax, dword ptr [0xe9b6bc]
004134c2  890508f3f200             mov       dword ptr [0xf2f308], eax
004134c8  d905e4f3f200             fld       dword ptr [0xf2f3e4]
004134ce  db6d90                   fld       xword ptr [ebp - 0x70]
004134d1  d9c9                     fxch      st(1)
004134d3  ded9                     fcompp
004134d5  dfe0                     fnstsw    ax
004134d7  9e                       sahf
004134d8  0f8a18000000             jp        0x4134f6
004134de  7216                     jb        0x4134f6
004134e0  c705b8b6e90004000000     mov       dword ptr [0xe9b6b8], 4
004134ea  c70520b6e90004000000     mov       dword ptr [0xe9b620], 4
004134f4  eb14                     jmp       0x41350a
004134f6  c705b8b6e9002a000000     mov       dword ptr [0xe9b6b8], 0x2a
00413500  c70520b6e9002a000000     mov       dword ptr [0xe9b620], 0x2a
0041350a  6848b6e900               push      0xe9b648
0041350f  6828b55500               push      0x55b528
00413514  68e0f3f200               push      0xf2f3e0
00413519  6808f3f200               push      0xf2f308
0041351e  68e0f2f200               push      0xf2f2e0 ; _cdcom_
00413523  6800f4f200               push      0xf2f400
00413528  68c0b6e900               push      0xe9b6c0
0041352d  68bcb6e900               push      0xe9b6bc
00413532  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00413538  8d08                     lea       ecx, [eax]
0041353a  51                       push      ecx
0041353b  8b4d30                   mov       ecx, dword ptr [ebp + 0x30]
0041353e  8d09                     lea       ecx, [ecx]
00413540  51                       push      ecx
00413541  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
00413544  8d09                     lea       ecx, [ecx]
00413546  51                       push      ecx
00413547  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0041354a  8d09                     lea       ecx, [ecx]
0041354c  51                       push      ecx
0041354d  8b8d90feffff             mov       ecx, dword ptr [ebp - 0x170]
00413553  8d11                     lea       edx, [ecx]
00413555  52                       push      edx
00413556  e805240100               call      0x425960 ; _fulbar_
0041355b  83c434                   add       esp, 0x34
0041355e  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00413564  d91d50b6e900             fstp      dword ptr [0xe9b650]
0041356a  db6d90                   fld       xword ptr [ebp - 0x70]
0041356d  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00413573  d9054cb6e900             fld       dword ptr [0xe9b64c]
00413579  d82d48b6e900             fsubr     dword ptr [0xe9b648]
0041357f  d91dc4b6e900             fstp      dword ptr [0xe9b6c4]
00413585  e9d6090000               jmp       0x413f60
0041358a  833d9cb6e9003e           cmp       dword ptr [0xe9b69c], 0x3e
00413591  0f8511010000             jne       0x4136a8
00413597  8b05bcb6e900             mov       eax, dword ptr [0xe9b6bc]
0041359d  890508f3f200             mov       dword ptr [0xf2f308], eax
004135a3  d905e4f3f200             fld       dword ptr [0xf2f3e4]
004135a9  db6d90                   fld       xword ptr [ebp - 0x70]
004135ac  d9c9                     fxch      st(1)
004135ae  d8d1                     fcom      st(1)
004135b0  ddd9                     fstp      st(1)
004135b2  dbbd18ffffff             fstp      xword ptr [ebp - 0xe8]
004135b8  dfe0                     fnstsw    ax
004135ba  9e                       sahf
004135bb  0f8a47000000             jp        0x413608
004135c1  7345                     jae       0x413608
004135c3  dbad18ffffff             fld       xword ptr [ebp - 0xe8]
004135c9  d82550bbf400             fsub      dword ptr [0xf4bb50]
004135cf  d90544bbf400             fld       dword ptr [0xf4bb44]
004135d5  d9c0                     fld       st(0)
004135d7  d82de8f2f200             fsubr     dword ptr [0xf2f2e8]
004135dd  deca                     fmulp     st(2)
004135df  db6d90                   fld       xword ptr [ebp - 0x70]
004135e2  d82550bbf400             fsub      dword ptr [0xf4bb50]
004135e8  defa                     fdivp     st(2)
004135ea  dec1                     faddp     st(1)
004135ec  d91de0f2f200             fstp      dword ptr [0xf2f2e0] ; _cdcom_
004135f2  c705b8b6e9002a000000     mov       dword ptr [0xe9b6b8], 0x2a
004135fc  c70520b6e9002a000000     mov       dword ptr [0xe9b620], 0x2a
00413606  eb20                     jmp       0x413628
00413608  8b05e8f2f200             mov       eax, dword ptr [0xf2f2e8]
0041360e  8905e0f2f200             mov       dword ptr [0xf2f2e0], eax ; _cdcom_
00413614  c705b8b6e90004000000     mov       dword ptr [0xe9b6b8], 4
0041361e  c70520b6e90004000000     mov       dword ptr [0xe9b620], 4
00413628  6848b6e900               push      0xe9b648
0041362d  6828b55500               push      0x55b528
00413632  68e0f3f200               push      0xf2f3e0
00413637  6808f3f200               push      0xf2f308
0041363c  68e0f2f200               push      0xf2f2e0 ; _cdcom_
00413641  6800f4f200               push      0xf2f400
00413646  68c0b6e900               push      0xe9b6c0
0041364b  68bcb6e900               push      0xe9b6bc
00413650  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00413656  8d08                     lea       ecx, [eax]
00413658  51                       push      ecx
00413659  8b4d30                   mov       ecx, dword ptr [ebp + 0x30]
0041365c  8d09                     lea       ecx, [ecx]
0041365e  51                       push      ecx
0041365f  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
00413662  8d09                     lea       ecx, [ecx]
00413664  51                       push      ecx
00413665  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
00413668  8d09                     lea       ecx, [ecx]
0041366a  51                       push      ecx
0041366b  8b8d90feffff             mov       ecx, dword ptr [ebp - 0x170]
00413671  8d11                     lea       edx, [ecx]
00413673  52                       push      edx
00413674  e8e7220100               call      0x425960 ; _fulbar_
00413679  83c434                   add       esp, 0x34
0041367c  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00413682  d91d50b6e900             fstp      dword ptr [0xe9b650]
00413688  db6d90                   fld       xword ptr [ebp - 0x70]
0041368b  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00413691  d9054cb6e900             fld       dword ptr [0xe9b64c]
00413697  d82d48b6e900             fsubr     dword ptr [0xe9b648]
0041369d  d91dc4b6e900             fstp      dword ptr [0xe9b6c4]
004136a3  e9b8080000               jmp       0x413f60
004136a8  833d9cb6e9003d           cmp       dword ptr [0xe9b69c], 0x3d
004136af  0f85c8000000             jne       0x41377d
004136b5  d905e4f3f200             fld       dword ptr [0xf2f3e4]
004136bb  db6d90                   fld       xword ptr [ebp - 0x70]
004136be  d9c9                     fxch      st(1)
004136c0  ded9                     fcompp
004136c2  dfe0                     fnstsw    ax
004136c4  9e                       sahf
004136c5  0f8ab2000000             jp        0x41377d
004136cb  0f82ac000000             jb        0x41377d
004136d1  8b05e8f2f200             mov       eax, dword ptr [0xf2f2e8]
004136d7  8905e0f2f200             mov       dword ptr [0xf2f2e0], eax ; _cdcom_
004136dd  8b05bcb6e900             mov       eax, dword ptr [0xe9b6bc]
004136e3  890508f3f200             mov       dword ptr [0xf2f308], eax
004136e9  c705b8b6e90004000000     mov       dword ptr [0xe9b6b8], 4
004136f3  c70520b6e90004000000     mov       dword ptr [0xe9b620], 4
004136fd  6848b6e900               push      0xe9b648
00413702  6828b55500               push      0x55b528
00413707  68e0f3f200               push      0xf2f3e0
0041370c  6808f3f200               push      0xf2f308
00413711  68e0f2f200               push      0xf2f2e0 ; _cdcom_
00413716  6800f4f200               push      0xf2f400
0041371b  68c0b6e900               push      0xe9b6c0
00413720  68bcb6e900               push      0xe9b6bc
00413725  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
0041372b  8d08                     lea       ecx, [eax]
0041372d  51                       push      ecx
0041372e  8b4d30                   mov       ecx, dword ptr [ebp + 0x30]
00413731  8d09                     lea       ecx, [ecx]
00413733  51                       push      ecx
00413734  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
00413737  8d09                     lea       ecx, [ecx]
00413739  51                       push      ecx
0041373a  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0041373d  8d09                     lea       ecx, [ecx]
0041373f  51                       push      ecx
00413740  8b8d90feffff             mov       ecx, dword ptr [ebp - 0x170]
00413746  8d11                     lea       edx, [ecx]
00413748  52                       push      edx
00413749  e812220100               call      0x425960 ; _fulbar_
0041374e  83c434                   add       esp, 0x34
00413751  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00413757  d91d50b6e900             fstp      dword ptr [0xe9b650]
0041375d  db6d90                   fld       xword ptr [ebp - 0x70]
00413760  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00413766  d9054cb6e900             fld       dword ptr [0xe9b64c]
0041376c  d82d48b6e900             fsubr     dword ptr [0xe9b648]
00413772  d91dc4b6e900             fstp      dword ptr [0xe9b6c4]
00413778  e9e3070000               jmp       0x413f60
0041377d  833d9cb6e90005           cmp       dword ptr [0xe9b69c], 5
00413784  7416                     je        0x41379c
00413786  833d9cb6e90033           cmp       dword ptr [0xe9b69c], 0x33
0041378d  740d                     je        0x41379c
0041378f  833d9cb6e90034           cmp       dword ptr [0xe9b69c], 0x34
00413796  0f8511010000             jne       0x4138ad
0041379c  8b05bcb6e900             mov       eax, dword ptr [0xe9b6bc]
004137a2  890508f3f200             mov       dword ptr [0xf2f308], eax
004137a8  d905e4f3f200             fld       dword ptr [0xf2f3e4]
004137ae  db6d90                   fld       xword ptr [ebp - 0x70]
004137b1  d9c9                     fxch      st(1)
004137b3  d8d1                     fcom      st(1)
004137b5  ddd9                     fstp      st(1)
004137b7  dbbd0cffffff             fstp      xword ptr [ebp - 0xf4]
004137bd  dfe0                     fnstsw    ax
004137bf  9e                       sahf
004137c0  0f8a47000000             jp        0x41380d
004137c6  7345                     jae       0x41380d
004137c8  dbad0cffffff             fld       xword ptr [ebp - 0xf4]
004137ce  d82550bbf400             fsub      dword ptr [0xf4bb50]
004137d4  d90544bbf400             fld       dword ptr [0xf4bb44]
004137da  d9c0                     fld       st(0)
004137dc  d82de8f2f200             fsubr     dword ptr [0xf2f2e8]
004137e2  deca                     fmulp     st(2)
004137e4  db6d90                   fld       xword ptr [ebp - 0x70]
004137e7  d82550bbf400             fsub      dword ptr [0xf4bb50]
004137ed  defa                     fdivp     st(2)
004137ef  dec1                     faddp     st(1)
004137f1  d91de0f2f200             fstp      dword ptr [0xf2f2e0] ; _cdcom_
004137f7  c705b8b6e9002a000000     mov       dword ptr [0xe9b6b8], 0x2a
00413801  c70520b6e9002a000000     mov       dword ptr [0xe9b620], 0x2a
0041380b  eb20                     jmp       0x41382d
0041380d  8b05e8f2f200             mov       eax, dword ptr [0xf2f2e8]
00413813  8905e0f2f200             mov       dword ptr [0xf2f2e0], eax ; _cdcom_
00413819  c705b8b6e90004000000     mov       dword ptr [0xe9b6b8], 4
00413823  c70520b6e90004000000     mov       dword ptr [0xe9b620], 4
0041382d  6848b6e900               push      0xe9b648
00413832  6828b55500               push      0x55b528
00413837  68e0f3f200               push      0xf2f3e0
0041383c  6808f3f200               push      0xf2f308
00413841  68e0f2f200               push      0xf2f2e0 ; _cdcom_
00413846  6800f4f200               push      0xf2f400
0041384b  68c0b6e900               push      0xe9b6c0
00413850  68bcb6e900               push      0xe9b6bc
00413855  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
0041385b  8d08                     lea       ecx, [eax]
0041385d  51                       push      ecx
0041385e  8b4d30                   mov       ecx, dword ptr [ebp + 0x30]
00413861  8d09                     lea       ecx, [ecx]
00413863  51                       push      ecx
00413864  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
00413867  8d09                     lea       ecx, [ecx]
00413869  51                       push      ecx
0041386a  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0041386d  8d09                     lea       ecx, [ecx]
0041386f  51                       push      ecx
00413870  8b8d90feffff             mov       ecx, dword ptr [ebp - 0x170]
00413876  8d11                     lea       edx, [ecx]
00413878  52                       push      edx
00413879  e8e2200100               call      0x425960 ; _fulbar_
0041387e  83c434                   add       esp, 0x34
00413881  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00413887  d91d50b6e900             fstp      dword ptr [0xe9b650]
0041388d  db6d90                   fld       xword ptr [ebp - 0x70]
00413890  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00413896  d9054cb6e900             fld       dword ptr [0xe9b64c]
0041389c  d82d48b6e900             fsubr     dword ptr [0xe9b648]
004138a2  d91dc4b6e900             fstp      dword ptr [0xe9b6c4]
004138a8  e9b3060000               jmp       0x413f60
004138ad  b800000000               mov       eax, 0
004138b2  c7052cb5550000000000     mov       dword ptr [0x55b52c], 0 ; bits=00000000, f32=0.0
004138bc  8b9574feffff             mov       edx, dword ptr [ebp - 0x18c]
004138c2  89d1                     mov       ecx, edx
004138c4  89d3                     mov       ebx, edx
004138c6  f7db                     neg       ebx
004138c8  899d50feffff             mov       dword ptr [ebp - 0x1b0], ebx
004138ce  89cb                     mov       ebx, ecx
004138d0  89854cfeffff             mov       dword ptr [ebp - 0x1b4], eax
004138d6  899d48feffff             mov       dword ptr [ebp - 0x1b8], ebx
004138dc  8b0534b55500             mov       eax, dword ptr [0x55b534] ; bits=00000000, f32=0.0
004138e2  89050cb6e900             mov       dword ptr [0xe9b60c], eax
004138e8  d905acf3f200             fld       dword ptr [0xf2f3ac]
004138ee  d82d34b55500             fsubr     dword ptr [0x55b534] ; bits=00000000, f32=0.0
004138f4  d91de4f3f200             fstp      dword ptr [0xf2f3e4]
004138fa  bb00000000               mov       ebx, 0
004138ff  89d8                     mov       eax, ebx
00413901  c70530b5550000000000     mov       dword ptr [0x55b530], 0 ; bits=00000000, f32=0.0
0041390b  d90520ad5500             fld       dword ptr [0x55ad20] ; bits=6666863f, f32=1.0499999523162842
00413911  d9ee                     fldz
00413913  dbbd00ffffff             fstp      xword ptr [ebp - 0x100]
00413919  d9051cb6e900             fld       dword ptr [0xe9b61c]
0041391f  d82d34b55500             fsubr     dword ptr [0x55b534] ; bits=00000000, f32=0.0
00413925  dbbdf4feffff             fstp      xword ptr [ebp - 0x10c]
0041392b  898544feffff             mov       dword ptr [ebp - 0x1bc], eax
00413931  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00413937  40                       inc       eax
00413938  3d64000000               cmp       eax, 0x64
0041393d  898544feffff             mov       dword ptr [ebp - 0x1bc], eax
00413943  7e1c                     jle       0x413961
00413945  ddd8                     fstp      st(0)
00413947  68fcb35500               push      0x55b3fc
0041394c  e82ff50800               call      0x4a2e80 ; _jwe_ilst
00413951  83c404                   add       esp, 4
00413954  68a4af5500               push      0x55afa4
00413959  e8e2fa0800               call      0x4a3440 ; _jwe_xstp
0041395e  83c404                   add       esp, 4
00413961  db7dcc                   fstp      xword ptr [ebp - 0x34]
00413964  6828b55500               push      0x55b528
00413969  e842a10100               call      0x42dab0 ; _rqvstw_
0041396e  db6dcc                   fld       xword ptr [ebp - 0x34]
00413971  d9c9                     fxch      st(1)
00413973  83c404                   add       esp, 4
00413976  83fb06                   cmp       ebx, 6
00413979  7e17                     jle       0x413992
0041397b  833d10b6e900ff           cmp       dword ptr [0xe9b610], -1
00413982  0f8532010000             jne       0x413aba
00413988  c70510b6e900feffffff     mov       dword ptr [0xe9b610], 0xfffffffe
00413992  833d10b6e900ff           cmp       dword ptr [0xe9b610], -1
00413999  0f851b010000             jne       0x413aba
0041399f  833d9cb6e90001           cmp       dword ptr [0xe9b69c], 1
004139a6  7413                     je        0x4139bb
004139a8  833d9cb6e90005           cmp       dword ptr [0xe9b69c], 5
004139af  740a                     je        0x4139bb
004139b1  c70510b6e900feffffff     mov       dword ptr [0xe9b610], 0xfffffffe
004139bb  833d10b6e900ff           cmp       dword ptr [0xe9b610], -1
004139c2  0f85f2000000             jne       0x413aba
004139c8  ddd8                     fstp      st(0)
004139ca  833d9cb6e90001           cmp       dword ptr [0xe9b69c], 1
004139d1  0f85b6000000             jne       0x413a8d
004139d7  d8151cad5500             fcom      dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
004139dd  dfe0                     fnstsw    ax
004139df  9e                       sahf
004139e0  0f8a10000000             jp        0x4139f6
004139e6  760e                     jbe       0x4139f6
004139e8  d9c0                     fld       st(0)
004139ea  d83d28b55500             fdivr     dword ptr [0x55b528] ; bits=00000000, f32=0.0
004139f0  d91d28b55500             fstp      dword ptr [0x55b528] ; bits=00000000, f32=0.0
004139f6  85db                     test      ebx, ebx
004139f8  750a                     jne       0x413a04
004139fa  ddd8                     fstp      st(0)
004139fc  d90524ad5500             fld       dword ptr [0x55ad24] ; bits=ae47813f, f32=1.0099999904632568
00413a02  eb12                     jmp       0x413a16
00413a04  d8251cad5500             fsub      dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
00413a0a  d80d28ad5500             fmul      dword ptr [0x55ad28] ; bits=0000003f, f32=0.5
00413a10  d8051cad5500             fadd      dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
00413a16  db7dcc                   fstp      xword ptr [ebp - 0x34]
00413a19  db6dcc                   fld       xword ptr [ebp - 0x34]
00413a1c  d80d28b55500             fmul      dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413a22  d91d28b55500             fstp      dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413a28  68d0b35500               push      0x55b3d0
00413a2d  e84ef40800               call      0x4a2e80 ; _jwe_ilst
00413a32  83c404                   add       esp, 4
00413a35  8b0528b55500             mov       eax, dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413a3b  8d0d68b35500             lea       ecx, [0x55b368] ; bits=09820000, f32=4.664782457890884e-41
00413a41  895dfc                   mov       dword ptr [ebp - 4], ebx
00413a44  8d55fc                   lea       edx, [ebp - 4]
00413a47  895134                   mov       dword ptr [ecx + 0x34], edx
00413a4a  8945f8                   mov       dword ptr [ebp - 8], eax
00413a4d  8d45f8                   lea       eax, [ebp - 8]
00413a50  89414c                   mov       dword ptr [ecx + 0x4c], eax
00413a53  db6dcc                   fld       xword ptr [ebp - 0x34]
00413a56  d95df4                   fstp      dword ptr [ebp - 0xc]
00413a59  8d45f4                   lea       eax, [ebp - 0xc]
00413a5c  894164                   mov       dword ptr [ecx + 0x64], eax
00413a5f  51                       push      ecx
00413a60  e81bf40800               call      0x4a2e80 ; _jwe_ilst
00413a65  db6dcc                   fld       xword ptr [ebp - 0x34]
00413a68  83c404                   add       esp, 4
00413a6b  43                       inc       ebx
00413a6c  83fb06                   cmp       ebx, 6
00413a6f  0f8ebcfeffff             jle       0x413931
00413a75  db7dcc                   fstp      xword ptr [ebp - 0x34]
00413a78  6848b35500               push      0x55b348
00413a7d  e86eeb0800               call      0x4a25f0 ; _jwe_isfm
00413a82  db6dcc                   fld       xword ptr [ebp - 0x34]
00413a85  83c404                   add       esp, 4
00413a88  e9a4feffff               jmp       0x413931
00413a8d  ddd8                     fstp      st(0)
00413a8f  8b059cb6e900             mov       eax, dword ptr [0xe9b69c]
00413a95  8d0d10b35500             lea       ecx, [0x55b310] ; bits=09820000, f32=4.664782457890884e-41
00413a9b  8945fc                   mov       dword ptr [ebp - 4], eax
00413a9e  8d45fc                   lea       eax, [ebp - 4]
00413aa1  894134                   mov       dword ptr [ecx + 0x34], eax
00413aa4  51                       push      ecx
00413aa5  e8d6f30800               call      0x4a2e80 ; _jwe_ilst
00413aaa  83c404                   add       esp, 4
00413aad  6898af5500               push      0x55af98
00413ab2  e889f90800               call      0x4a3440 ; _jwe_xstp
00413ab7  83c404                   add       esp, 4
00413aba  833d10b6e900fe           cmp       dword ptr [0xe9b610], -2
00413ac1  0f8506010000             jne       0x413bcd
00413ac7  ddd8                     fstp      st(0)
00413ac9  ddd8                     fstp      st(0)
00413acb  8b854cfeffff             mov       eax, dword ptr [ebp - 0x1b4]
00413ad1  40                       inc       eax
00413ad2  3d14000000               cmp       eax, 0x14
00413ad7  89854cfeffff             mov       dword ptr [ebp - 0x1b4], eax
00413add  7e1a                     jle       0x413af9
00413adf  68f0b25500               push      0x55b2f0
00413ae4  e807eb0800               call      0x4a25f0 ; _jwe_isfm
00413ae9  83c404                   add       esp, 4
00413aec  688caf5500               push      0x55af8c
00413af1  e84af90800               call      0x4a3440 ; _jwe_xstp
00413af6  83c404                   add       esp, 4
00413af9  8b0534b55500             mov       eax, dword ptr [0x55b534] ; bits=00000000, f32=0.0
00413aff  8d0dc4b25500             lea       ecx, [0x55b2c4] ; bits=09020000, f32=7.300764999132297e-43
00413b05  8945f8                   mov       dword ptr [ebp - 8], eax
00413b08  8d45f8                   lea       eax, [ebp - 8]
00413b0b  894128                   mov       dword ptr [ecx + 0x28], eax
00413b0e  51                       push      ecx
00413b0f  e8dcea0800               call      0x4a25f0 ; _jwe_isfm
00413b14  83c404                   add       esp, 4
00413b17  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00413b1a  8b10                     mov       edx, dword ptr [eax]
00413b1c  039550feffff             add       edx, dword ptr [ebp - 0x1b0]
00413b22  83fa00                   cmp       edx, 0
00413b25  7e76                     jle       0x413b9d
00413b27  8b8548feffff             mov       eax, dword ptr [ebp - 0x1b8]
00413b2d  89c1                     mov       ecx, eax
00413b2f  83fa02                   cmp       edx, 2
00413b32  7c4a                     jl        0x413b7e
00413b34  eb07                     jmp       0x413b3d
00413b36  d91c8db8006400           fstp      dword ptr [ecx*4 + 0x6400b8]
00413b3d  d9048dc0006400           fld       dword ptr [ecx*4 + 0x6400c0]
00413b44  d8048dbc006400           fadd      dword ptr [ecx*4 + 0x6400bc]
00413b4b  d80d28ad5500             fmul      dword ptr [0x55ad28] ; bits=0000003f, f32=0.5
00413b51  d91c8dbc006400           fstp      dword ptr [ecx*4 + 0x6400bc]
00413b58  d9048dc4006400           fld       dword ptr [ecx*4 + 0x6400c4]
00413b5f  d8048dc0006400           fadd      dword ptr [ecx*4 + 0x6400c0]
00413b66  d80d28ad5500             fmul      dword ptr [0x55ad28] ; bits=0000003f, f32=0.5
00413b6c  83c102                   add       ecx, 2
00413b6f  83ea02                   sub       edx, 2
00413b72  83fa02                   cmp       edx, 2
00413b75  7dbf                     jge       0x413b36
00413b77  d91c8db8006400           fstp      dword ptr [ecx*4 + 0x6400b8]
00413b7e  85d2                     test      edx, edx
00413b80  741b                     je        0x413b9d
00413b82  d9048dc0006400           fld       dword ptr [ecx*4 + 0x6400c0]
00413b89  d8048dbc006400           fadd      dword ptr [ecx*4 + 0x6400bc]
00413b90  d80d28ad5500             fmul      dword ptr [0x55ad28] ; bits=0000003f, f32=0.5
00413b96  d91c8dbc006400           fstp      dword ptr [ecx*4 + 0x6400bc]
00413b9d  8b8d74feffff             mov       ecx, dword ptr [ebp - 0x18c]
00413ba3  8b048dbc006400           mov       eax, dword ptr [ecx*4 + 0x6400bc]
00413baa  890534b55500             mov       dword ptr [0x55b534], eax ; bits=00000000, f32=0.0
00413bb0  8d158cb25500             lea       edx, [0x55b28c] ; bits=09820000, f32=4.664782457890884e-41
00413bb6  8945f8                   mov       dword ptr [ebp - 8], eax
00413bb9  8d45f8                   lea       eax, [ebp - 8]
00413bbc  894234                   mov       dword ptr [edx + 0x34], eax
00413bbf  52                       push      edx
00413bc0  e8bbf20800               call      0x4a2e80 ; _jwe_ilst
00413bc5  83c404                   add       esp, 4
00413bc8  e90ffdffff               jmp       0x4138dc
00413bcd  d9c0                     fld       st(0)
00413bcf  d9e1                     fabs
00413bd1  d81d78f70e04             fcomp     dword ptr [0x40ef778]
00413bd7  dfe0                     fnstsw    ax
00413bd9  9e                       sahf
00413bda  0f8a06000000             jp        0x413be6
00413be0  0f8646020000             jbe       0x413e2c
00413be6  dbadf4feffff             fld       xword ptr [ebp - 0x10c]
00413bec  d8e9                     fsubr     st(1)
00413bee  dbad00ffffff             fld       xword ptr [ebp - 0x100]
00413bf4  d82d28b55500             fsubr     dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413bfa  def9                     fdivp     st(1)
00413bfc  d81d10ad5500             fcomp     dword ptr [0x55ad10] ; bits=00000000, f32=0.0
00413c02  dfe0                     fnstsw    ax
00413c04  9e                       sahf
00413c05  0f8a24000000             jp        0x413c2f
00413c0b  7622                     jbe       0x413c2f
00413c0d  d9e8                     fld1
00413c0f  d9ca                     fxch      st(2)
00413c11  d8151cad5500             fcom      dword ptr [0x55ad1c] ; bits=0000803f, f32=1.0
00413c17  d9ca                     fxch      st(2)
00413c19  dfe0                     fnstsw    ax
00413c1b  9e                       sahf
00413c1c  0f8ab2000000             jp        0x413cd4
00413c22  0f83ac000000             jae       0x413cd4
00413c28  def2                     fdivrp    st(2)
00413c2a  e9a7000000               jmp       0x413cd6
00413c2f  ddd8                     fstp      st(0)
00413c31  db7dcc                   fstp      xword ptr [ebp - 0x34]
00413c34  6854b25500               push      0x55b254
00413c39  e842f20800               call      0x4a2e80 ; _jwe_ilst
00413c3e  83c404                   add       esp, 4
00413c41  d90530b55500             fld       dword ptr [0x55b530] ; bits=00000000, f32=0.0
00413c47  d9ee                     fldz
00413c49  d9c9                     fxch      st(1)
00413c4b  dae9                     fucompp
00413c4d  db6dcc                   fld       xword ptr [ebp - 0x34]
00413c50  dfe0                     fnstsw    ax
00413c52  9e                       sahf
00413c53  0f8a54000000             jp        0x413cad
00413c59  7552                     jne       0x413cad
00413c5b  ddd8                     fstp      st(0)
00413c5d  d9051cb6e900             fld       dword ptr [0xe9b61c]
00413c63  d82d34b55500             fsubr     dword ptr [0x55b534] ; bits=00000000, f32=0.0
00413c69  d91d20b55500             fstp      dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413c6f  d90578f70e04             fld       dword ptr [0x40ef778]
00413c75  d9c0                     fld       st(0)
00413c77  d9e0                     fchs
00413c79  d90520b55500             fld       dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413c7f  ded9                     fcompp
00413c81  dfe0                     fnstsw    ax
00413c83  9e                       sahf
00413c84  0f8a0e000000             jp        0x413c98
00413c8a  760c                     jbe       0x413c98
00413c8c  d8c0                     fadd      st(0)
00413c8e  d9e0                     fchs
00413c90  d91d20b55500             fstp      dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413c96  eb02                     jmp       0x413c9a
00413c98  ddd8                     fstp      st(0)
00413c9a  d90520b55500             fld       dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413ca0  d9e1                     fabs
00413ca2  d91d30b55500             fstp      dword ptr [0x55b530] ; bits=00000000, f32=0.0
00413ca8  e9f6000000               jmp       0x413da3
00413cad  db7dcc                   fstp      xword ptr [ebp - 0x34]
00413cb0  6828b25500               push      0x55b228
00413cb5  e8c6f10800               call      0x4a2e80 ; _jwe_ilst
00413cba  83c404                   add       esp, 4
00413cbd  db6dcc                   fld       xword ptr [ebp - 0x34]
00413cc0  d80d28b55500             fmul      dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413cc6  d91d28b55500             fstp      dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413ccc  db6dcc                   fld       xword ptr [ebp - 0x34]
00413ccf  e95dfcffff               jmp       0x413931
00413cd4  ddd8                     fstp      st(0)
00413cd6  d9c0                     fld       st(0)
00413cd8  dbbdf4feffff             fstp      xword ptr [ebp - 0x10c]
00413cde  d90528b55500             fld       dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413ce4  dbbd00ffffff             fstp      xword ptr [ebp - 0x100]
00413cea  d9ee                     fldz
00413cec  d9c9                     fxch      st(1)
00413cee  d81510ad5500             fcom      dword ptr [0x55ad10] ; bits=00000000, f32=0.0
00413cf4  d9c9                     fxch      st(1)
00413cf6  dfe0                     fnstsw    ax
00413cf8  9e                       sahf
00413cf9  0f8a6a000000             jp        0x413d69
00413cff  7268                     jb        0x413d69
00413d01  ddd8                     fstp      st(0)
00413d03  ddd9                     fstp      st(1)
00413d05  8b0528b55500             mov       eax, dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413d0b  89052cb55500             mov       dword ptr [0x55b52c], eax ; bits=00000000, f32=0.0
00413d11  d91d24b55500             fstp      dword ptr [0x55b524] ; bits=00000000, f32=0.0
00413d17  d90530b55500             fld       dword ptr [0x55b530] ; bits=00000000, f32=0.0
00413d1d  d81d10ad5500             fcomp     dword ptr [0x55ad10] ; bits=00000000, f32=0.0
00413d23  dfe0                     fnstsw    ax
00413d25  9e                       sahf
00413d26  0f8a02000000             jp        0x413d2e
00413d2c  7775                     ja        0x413da3
00413d2e  d9051cb6e900             fld       dword ptr [0xe9b61c]
00413d34  d82d34b55500             fsubr     dword ptr [0x55b534] ; bits=00000000, f32=0.0
00413d3a  d91d20b55500             fstp      dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413d40  d90578f70e04             fld       dword ptr [0x40ef778]
00413d46  d9c0                     fld       st(0)
00413d48  d9e0                     fchs
00413d4a  d90520b55500             fld       dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413d50  ded9                     fcompp
00413d52  dfe0                     fnstsw    ax
00413d54  9e                       sahf
00413d55  0f8a46000000             jp        0x413da1
00413d5b  7644                     jbe       0x413da1
00413d5d  d8c0                     fadd      st(0)
00413d5f  d9e0                     fchs
00413d61  d91d20b55500             fstp      dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413d67  eb3a                     jmp       0x413da3
00413d69  8b0528b55500             mov       eax, dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413d6f  890530b55500             mov       dword ptr [0x55b530], eax ; bits=00000000, f32=0.0
00413d75  d9c9                     fxch      st(1)
00413d77  d91d20b55500             fstp      dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413d7d  d8d8                     fcomp     st(0)
00413d7f  dfe0                     fnstsw    ax
00413d81  9e                       sahf
00413d82  0f8a02000000             jp        0x413d8a
00413d88  7713                     ja        0x413d9d
00413d8a  dbad00ffffff             fld       xword ptr [ebp - 0x100]
00413d90  d8c9                     fmul      st(1)
00413d92  d91d28b55500             fstp      dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413d98  e994fbffff               jmp       0x413931
00413d9d  ddd8                     fstp      st(0)
00413d9f  eb02                     jmp       0x413da3
00413da1  ddd8                     fstp      st(0)
00413da3  6818b55500               push      0x55b518
00413da8  6828b55500               push      0x55b528
00413dad  6824b55500               push      0x55b524
00413db2  6820b55500               push      0x55b520
00413db7  682cb55500               push      0x55b52c
00413dbc  6830b55500               push      0x55b530
00413dc1  68b0da4200               push      0x42dab0 ; _rqvstw_
00413dc6  6878f70e04               push      0x40ef778
00413dcb  6810ad5500               push      0x55ad10
00413dd0  e86bf10500               call      0x472f40 ; _rgf3_
00413dd5  83c424                   add       esp, 0x24
00413dd8  d90520b55500             fld       dword ptr [0x55b520] ; bits=00000000, f32=0.0
00413dde  d9e1                     fabs
00413de0  dbbde8feffff             fstp      xword ptr [ebp - 0x118]
00413de6  dbade8feffff             fld       xword ptr [ebp - 0x118]
00413dec  d81d7cf70e04             fcomp     dword ptr [0x40ef77c]
00413df2  dfe0                     fnstsw    ax
00413df4  9e                       sahf
00413df5  0f8a35000000             jp        0x413e30
00413dfb  7633                     jbe       0x413e30
00413dfd  8b057cf70e04             mov       eax, dword ptr [0x40ef77c]
00413e03  8d0dd8b15500             lea       ecx, [0x55b1d8] ; bits=09820000, f32=4.664782457890884e-41
00413e09  dbade8feffff             fld       xword ptr [ebp - 0x118]
00413e0f  d95df8                   fstp      dword ptr [ebp - 8]
00413e12  8d55f8                   lea       edx, [ebp - 8]
00413e15  895134                   mov       dword ptr [ecx + 0x34], edx
00413e18  8945f4                   mov       dword ptr [ebp - 0xc], eax
00413e1b  8d45f4                   lea       eax, [ebp - 0xc]
00413e1e  89414c                   mov       dword ptr [ecx + 0x4c], eax
00413e21  51                       push      ecx
00413e22  e859f00800               call      0x4a2e80 ; _jwe_ilst
00413e27  83c404                   add       esp, 4
00413e2a  eb04                     jmp       0x413e30
00413e2c  ddd8                     fstp      st(0)
00413e2e  ddd8                     fstp      st(0)
00413e30  d905e4f3f200             fld       dword ptr [0xf2f3e4]
00413e36  db6d90                   fld       xword ptr [ebp - 0x70]
00413e39  d9c9                     fxch      st(1)
00413e3b  ded9                     fcompp
00413e3d  dfe0                     fnstsw    ax
00413e3f  9e                       sahf
00413e40  0f8a35000000             jp        0x413e7b
00413e46  7333                     jae       0x413e7b
00413e48  d90550b6e900             fld       dword ptr [0xe9b650]
00413e4e  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00413e54  d9c9                     fxch      st(1)
00413e56  ded9                     fcompp
00413e58  dfe0                     fnstsw    ax
00413e5a  9e                       sahf
00413e5b  0f8a0e000000             jp        0x413e6f
00413e61  730c                     jae       0x413e6f
00413e63  c70520b6e90003000000     mov       dword ptr [0xe9b620], 3
00413e6d  eb3d                     jmp       0x413eac
00413e6f  c70520b6e90029000000     mov       dword ptr [0xe9b620], 0x29
00413e79  eb31                     jmp       0x413eac
00413e7b  d90550b6e900             fld       dword ptr [0xe9b650]
00413e81  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00413e87  d9c9                     fxch      st(1)
00413e89  ded9                     fcompp
00413e8b  dfe0                     fnstsw    ax
00413e8d  9e                       sahf
00413e8e  0f8a0e000000             jp        0x413ea2
00413e94  730c                     jae       0x413ea2
00413e96  c70520b6e9001f000000     mov       dword ptr [0xe9b620], 0x1f
00413ea0  eb0a                     jmp       0x413eac
00413ea2  c70520b6e90004000000     mov       dword ptr [0xe9b620], 4
00413eac  8b0520b6e900             mov       eax, dword ptr [0xe9b620]
00413eb2  8905b8b6e900             mov       dword ptr [0xe9b6b8], eax
00413eb8  8b0518ad5500             mov       eax, dword ptr [0x55ad18] ; bits=caf24971, f32=1.0000000150474662e+30
00413ebe  8905c4b6e900             mov       dword ptr [0xe9b6c4], eax
00413ec4  833d20b6e90004           cmp       dword ptr [0xe9b620], 4
00413ecb  0f858f000000             jne       0x413f60
00413ed1  6848b6e900               push      0xe9b648
00413ed6  6828b55500               push      0x55b528
00413edb  68e0f3f200               push      0xf2f3e0
00413ee0  68bcb6e900               push      0xe9b6bc
00413ee5  68e8f2f200               push      0xf2f2e8
00413eea  6800f4f200               push      0xf2f400
00413eef  68c0b6e900               push      0xe9b6c0
00413ef4  68bcb6e900               push      0xe9b6bc
00413ef9  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00413eff  8d08                     lea       ecx, [eax]
00413f01  51                       push      ecx
00413f02  8b4d30                   mov       ecx, dword ptr [ebp + 0x30]
00413f05  8d09                     lea       ecx, [ecx]
00413f07  51                       push      ecx
00413f08  8b4d2c                   mov       ecx, dword ptr [ebp + 0x2c]
00413f0b  8d09                     lea       ecx, [ecx]
00413f0d  51                       push      ecx
00413f0e  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
00413f11  8d09                     lea       ecx, [ecx]
00413f13  51                       push      ecx
00413f14  8b8d90feffff             mov       ecx, dword ptr [ebp - 0x170]
00413f1a  8d11                     lea       edx, [ecx]
00413f1c  52                       push      edx
00413f1d  e83e1a0100               call      0x425960 ; _fulbar_
00413f22  83c434                   add       esp, 0x34
00413f25  c705b8b6e90004000000     mov       dword ptr [0xe9b6b8], 4
00413f2f  c70520b6e90004000000     mov       dword ptr [0xe9b620], 4
00413f39  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00413f3f  d91d50b6e900             fstp      dword ptr [0xe9b650]
00413f45  db6d90                   fld       xword ptr [ebp - 0x70]
00413f48  d91db0f3f200             fstp      dword ptr [0xf2f3b0]
00413f4e  d9054cb6e900             fld       dword ptr [0xe9b64c]
00413f54  d82d48b6e900             fsubr     dword ptr [0xe9b648]
00413f5a  d91dc4b6e900             fstp      dword ptr [0xe9b6c4]
00413f60  d9052cbbf400             fld       dword ptr [0xf4bb2c]
00413f66  d80528b55500             fadd      dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413f6c  d91da4f1f200             fstp      dword ptr [0xf2f1a4]
00413f72  8b0528b55500             mov       eax, dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413f78  890544b6e900             mov       dword ptr [0xe9b644], eax
00413f7e  8905a4f3f200             mov       dword ptr [0xf2f3a4], eax
00413f84  68f0f3f200               push      0xf2f3f0
00413f89  68d8f3f200               push      0xf2f3d8
00413f8e  68d4f3f200               push      0xf2f3d4
00413f93  68d0f3f200               push      0xf2f3d0
00413f98  68ccf3f200               push      0xf2f3cc
00413f9d  68c8f3f200               push      0xf2f3c8
00413fa2  68c4f3f200               push      0xf2f3c4
00413fa7  68c0f3f200               push      0xf2f3c0
00413fac  68b8f3f200               push      0xf2f3b8
00413fb1  68b4f3f200               push      0xf2f3b4
00413fb6  68bcf3f200               push      0xf2f3bc
00413fbb  68b0f3f200               push      0xf2f3b0
00413fc0  68a0f3f200               push      0xf2f3a0 ; _xs3com_
00413fc5  e806520300               call      0x4491d0 ; _xlkt22_
00413fca  83c434                   add       esp, 0x34
00413fcd  d905acf3f200             fld       dword ptr [0xf2f3ac]
00413fd3  d805b0f3f200             fadd      dword ptr [0xf2f3b0]
00413fd9  d91da8f3f200             fstp      dword ptr [0xf2f3a8]
00413fdf  d90534b55500             fld       dword ptr [0x55b534] ; bits=00000000, f32=0.0
00413fe5  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
00413feb  d9c0                     fld       st(0)
00413fed  dd1cc5d0156400           fstp      qword ptr [eax*8 + 0x6415d0]
00413ff4  d90528b55500             fld       dword ptr [0x55b528] ; bits=00000000, f32=0.0
00413ffa  8b8d8cfeffff             mov       ecx, dword ptr [ebp - 0x174]
00414000  dd1cc5700c6400           fstp      qword ptr [eax*8 + 0x640c70]
00414007  d829                     fsubr     dword ptr [ecx]
00414009  d9c0                     fld       st(0)
0041400b  dd1cc510036400           fstp      qword ptr [eax*8 + 0x640310]
00414012  d9fa                     fsqrt
00414014  d95df8                   fstp      dword ptr [ebp - 8]
00414017  d945f8                   fld       dword ptr [ebp - 8]
0041401a  dd1cc520116400           fstp      qword ptr [eax*8 + 0x641120]
00414021  8b15b0f3f200             mov       edx, dword ptr [0xf2f3b0]
00414027  89148564fe6300           mov       dword ptr [eax*4 + 0x63fe64], edx
0041402e  d90550b6e900             fld       dword ptr [0xe9b650]
00414034  dd1cc5801a6400           fstp      qword ptr [eax*8 + 0x641a80]
0041403b  6a08                     push      8
0041403d  6858b55500               push      0x55b558
00414042  6828b55500               push      0x55b528
00414047  e864b20300               call      0x44f2b0 ; _var_decimal_
0041404c  83c40c                   add       esp, 0xc
0041404f  6a08                     push      8
00414051  6860b55500               push      0x55b560
00414056  682cbbf400               push      0xf4bb2c
0041405b  e850b20300               call      0x44f2b0 ; _var_decimal_
00414060  83c40c                   add       esp, 0xc
00414063  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00414069  8b18                     mov       ebx, dword ptr [eax]
0041406b  8b4d34                   mov       ecx, dword ptr [ebp + 0x34]
0041406e  d90548b6e900             fld       dword ptr [0xe9b648]
00414074  d821                     fsub      dword ptr [ecx]
00414076  8b1550b6e900             mov       edx, dword ptr [0xe9b650]
0041407c  d90534b55500             fld       dword ptr [0x55b534] ; bits=00000000, f32=0.0
00414082  d9c0                     fld       st(0)
00414084  d821                     fsub      dword ptr [ecx]
00414086  8b0db0f3f200             mov       ecx, dword ptr [0xf2f3b0]
0041408c  8bb58cfeffff             mov       esi, dword ptr [ebp - 0x174]
00414092  d9c9                     fxch      st(1)
00414094  d82e                     fsubr     dword ptr [esi]
00414096  8b3d20b6e900             mov       edi, dword ptr [0xe9b620]
0041409c  8d0558b15500             lea       eax, [0x55b158] ; bits=09020000, f32=7.300764999132297e-43
004140a2  895dfc                   mov       dword ptr [ebp - 4], ebx
004140a5  899568feffff             mov       dword ptr [ebp - 0x198], edx
004140ab  8d55fc                   lea       edx, [ebp - 4]
004140ae  895008                   mov       dword ptr [eax + 8], edx
004140b1  d9ca                     fxch      st(2)
004140b3  d95df8                   fstp      dword ptr [ebp - 8]
004140b6  8d55f8                   lea       edx, [ebp - 8]
004140b9  895028                   mov       dword ptr [eax + 0x28], edx
004140bc  8b9568feffff             mov       edx, dword ptr [ebp - 0x198]
004140c2  8955f4                   mov       dword ptr [ebp - 0xc], edx
004140c5  8d55f4                   lea       edx, [ebp - 0xc]
004140c8  895034                   mov       dword ptr [eax + 0x34], edx
004140cb  d95df0                   fstp      dword ptr [ebp - 0x10]
004140ce  8d55f0                   lea       edx, [ebp - 0x10]
004140d1  895040                   mov       dword ptr [eax + 0x40], edx
004140d4  894dec                   mov       dword ptr [ebp - 0x14], ecx
004140d7  8d4dec                   lea       ecx, [ebp - 0x14]
004140da  89484c                   mov       dword ptr [eax + 0x4c], ecx
004140dd  d95de8                   fstp      dword ptr [ebp - 0x18]
004140e0  8d4de8                   lea       ecx, [ebp - 0x18]
004140e3  894858                   mov       dword ptr [eax + 0x58], ecx
004140e6  897de4                   mov       dword ptr [ebp - 0x1c], edi
004140e9  8d4de4                   lea       ecx, [ebp - 0x1c]
004140ec  894864                   mov       dword ptr [eax + 0x64], ecx
004140ef  50                       push      eax
004140f0  e8fbe40800               call      0x4a25f0 ; _jwe_isfm
004140f5  83c404                   add       esp, 4
004140f8  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
004140fe  dd04c510036400           fld       qword ptr [eax*8 + 0x640310]
00414105  dc1d08ad5500             fcomp     qword ptr [0x55ad08] ; bits=0000000000000000, f64=0.0
0041410b  dfe0                     fnstsw    ax
0041410d  9e                       sahf
0041410e  0f8a28000000             jp        0x41413c
00414114  7726                     ja        0x41413c
00414116  8d0538b15500             lea       eax, [0x55b138] ; bits=69020000, f32=8.646011524884121e-43
0041411c  895dfc                   mov       dword ptr [ebp - 4], ebx
0041411f  8d4dfc                   lea       ecx, [ebp - 4]
00414122  894808                   mov       dword ptr [eax + 8], ecx
00414125  50                       push      eax
00414126  e8c5e40800               call      0x4a25f0 ; _jwe_isfm
0041412b  83c404                   add       esp, 4
0041412e  8b4540                   mov       eax, dword ptr [ebp + 0x40]
00414131  c70001000000             mov       dword ptr [eax], 1
00414137  e953080000               jmp       0x41498f
0041413c  d905c4b6e900             fld       dword ptr [0xe9b6c4]
00414142  db6d9c                   fld       xword ptr [ebp - 0x64]
00414145  d81dc4b6e900             fcomp     dword ptr [0xe9b6c4]
0041414b  dbbddcfeffff             fstp      xword ptr [ebp - 0x124]
00414151  dfe0                     fnstsw    ax
00414153  66a90041                 test      ax, 0x4100
00414157  7509                     jne       0x414162
00414159  dbaddcfeffff             fld       xword ptr [ebp - 0x124]
0041415f  db7d9c                   fstp      xword ptr [ebp - 0x64]
00414162  ff8574feffff             inc       dword ptr [ebp - 0x18c]
00414168  83ad6cfeffff01           sub       dword ptr [ebp - 0x194], 1
0041416f  0f85e7efffff             jne       0x41315c
00414175  6a08                     push      8
00414177  6858b55500               push      0x55b558
0041417c  8d1d88ad5500             lea       ebx, [0x55ad88] ; bits=405a0b00, f32=1.0425660574576639e-39
00414182  8d4388                   lea       eax, [ebx - 0x78]
00414185  50                       push      eax
00414186  e825b10300               call      0x44f2b0 ; _var_decimal_
0041418b  83c40c                   add       esp, 0xc
0041418e  6a08                     push      8
00414190  6860b55500               push      0x55b560
00414195  8d5b88                   lea       ebx, [ebx - 0x78]
00414198  53                       push      ebx
00414199  e812b10300               call      0x44f2b0 ; _var_decimal_
0041419e  83c40c                   add       esp, 0xc
004141a1  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
004141a7  8b958cfeffff             mov       edx, dword ptr [ebp - 0x174]
004141ad  8b08                     mov       ecx, dword ptr [eax]
004141af  d902                     fld       dword ptr [edx]
004141b1  8b5d34                   mov       ebx, dword ptr [ebp + 0x34]
004141b4  d903                     fld       dword ptr [ebx]
004141b6  d82a                     fsubr     dword ptr [edx]
004141b8  dbbdd0feffff             fstp      xword ptr [ebp - 0x130]
004141be  d8254cb6e900             fsub      dword ptr [0xe9b64c]
004141c4  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004141ca  d9c9                     fxch      st(1)
004141cc  d8d1                     fcom      st(1)
004141ce  ddd9                     fstp      st(1)
004141d0  dfe0                     fnstsw    ax
004141d2  66a90041                 test      ax, 0x4100
004141d6  7508                     jne       0x4141e0
004141d8  ddd8                     fstp      st(0)
004141da  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004141e0  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
004141e6  dbbdc4feffff             fstp      xword ptr [ebp - 0x13c]
004141ec  d900                     fld       dword ptr [eax]
004141ee  8b5534                   mov       edx, dword ptr [ebp + 0x34]
004141f1  d902                     fld       dword ptr [edx]
004141f3  d828                     fsubr     dword ptr [eax]
004141f5  dbbdb8feffff             fstp      xword ptr [ebp - 0x148]
004141fb  d825acf3f200             fsub      dword ptr [0xf2f3ac]
00414201  db6d90                   fld       xword ptr [ebp - 0x70]
00414204  d9c9                     fxch      st(1)
00414206  d8d1                     fcom      st(1)
00414208  ddd9                     fstp      st(1)
0041420a  dfe0                     fnstsw    ax
0041420c  66a90041                 test      ax, 0x4100
00414210  7505                     jne       0x414217
00414212  ddd8                     fstp      st(0)
00414214  db6d90                   fld       xword ptr [ebp - 0x70]
00414217  8b0520b6e900             mov       eax, dword ptr [0xe9b620]
0041421d  8d15b8b05500             lea       edx, [0x55b0b8] ; bits=09020000, f32=7.300764999132297e-43
00414223  894dfc                   mov       dword ptr [ebp - 4], ecx
00414226  8d75fc                   lea       esi, [ebp - 4]
00414229  897208                   mov       dword ptr [edx + 8], esi
0041422c  dbadd0feffff             fld       xword ptr [ebp - 0x130]
00414232  d95df8                   fstp      dword ptr [ebp - 8]
00414235  8d75f8                   lea       esi, [ebp - 8]
00414238  897228                   mov       dword ptr [edx + 0x28], esi
0041423b  dbadc4feffff             fld       xword ptr [ebp - 0x13c]
00414241  d95df4                   fstp      dword ptr [ebp - 0xc]
00414244  8d75f4                   lea       esi, [ebp - 0xc]
00414247  897234                   mov       dword ptr [edx + 0x34], esi
0041424a  dbadb8feffff             fld       xword ptr [ebp - 0x148]
00414250  d95df0                   fstp      dword ptr [ebp - 0x10]
00414253  8d75f0                   lea       esi, [ebp - 0x10]
00414256  897240                   mov       dword ptr [edx + 0x40], esi
00414259  d95dec                   fstp      dword ptr [ebp - 0x14]
0041425c  8d75ec                   lea       esi, [ebp - 0x14]
0041425f  89724c                   mov       dword ptr [edx + 0x4c], esi
00414262  8945e4                   mov       dword ptr [ebp - 0x1c], eax
00414265  8d45e4                   lea       eax, [ebp - 0x1c]
00414268  894264                   mov       dword ptr [edx + 0x64], eax
0041426b  52                       push      edx
0041426c  e87fe30800               call      0x4a25f0 ; _jwe_isfm
00414271  83c404                   add       esp, 4
00414274  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
0041427a  8b10                     mov       edx, dword ptr [eax]
0041427c  899564feffff             mov       dword ptr [ebp - 0x19c], edx
00414282  8d3580b05500             lea       esi, [0x55b080] ; bits=09020000, f32=7.300764999132297e-43
00414288  8955fc                   mov       dword ptr [ebp - 4], edx
0041428b  8d7dfc                   lea       edi, [ebp - 4]
0041428e  897e08                   mov       dword ptr [esi + 8], edi
00414291  db6d90                   fld       xword ptr [ebp - 0x70]
00414294  d95df8                   fstp      dword ptr [ebp - 8]
00414297  8d7df8                   lea       edi, [ebp - 8]
0041429a  897e28                   mov       dword ptr [esi + 0x28], edi
0041429d  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004142a3  d95df4                   fstp      dword ptr [ebp - 0xc]
004142a6  8d7df4                   lea       edi, [ebp - 0xc]
004142a9  897e34                   mov       dword ptr [esi + 0x34], edi
004142ac  56                       push      esi
004142ad  e83ee30800               call      0x4a25f0 ; _jwe_isfm
004142b2  83c404                   add       esp, 4
004142b5  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004142bb  db6d9c                   fld       xword ptr [ebp - 0x64]
004142be  dee9                     fsubp     st(1)
004142c0  dbbdacfeffff             fstp      xword ptr [ebp - 0x154]
004142c6  8b4538                   mov       eax, dword ptr [ebp + 0x38]
004142c9  d9054cb6e900             fld       dword ptr [0xe9b64c]
004142cf  d800                     fadd      dword ptr [eax]
004142d1  8d1d88ad5500             lea       ebx, [0x55ad88] ; bits=405a0b00, f32=1.0425660574576639e-39
004142d7  d84bac                   fmul      dword ptr [ebx - 0x54]
004142da  d86ba8                   fsubr     dword ptr [ebx - 0x58]
004142dd  dbadacfeffff             fld       xword ptr [ebp - 0x154]
004142e3  ded9                     fcompp
004142e5  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
004142eb  dfe0                     fnstsw    ax
004142ed  9e                       sahf
004142ee  0f8a87000000             jp        0x41437b
004142f4  0f8681000000             jbe       0x41437b
004142fa  8d0554b05500             lea       eax, [0x55b054] ; bits=09020000, f32=7.300764999132297e-43
00414300  8b8d64feffff             mov       ecx, dword ptr [ebp - 0x19c]
00414306  894dfc                   mov       dword ptr [ebp - 4], ecx
00414309  8d55fc                   lea       edx, [ebp - 4]
0041430c  895008                   mov       dword ptr [eax + 8], edx
0041430f  dbadacfeffff             fld       xword ptr [ebp - 0x154]
00414315  d95df8                   fstp      dword ptr [ebp - 8]
00414318  8d55f8                   lea       edx, [ebp - 8]
0041431b  895028                   mov       dword ptr [eax + 0x28], edx
0041431e  50                       push      eax
0041431f  e8cce20800               call      0x4a25f0 ; _jwe_isfm
00414324  83c404                   add       esp, 4
00414327  d9054cb6e900             fld       dword ptr [0xe9b64c]
0041432d  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00414333  d800                     fadd      dword ptr [eax]
00414335  d84bac                   fmul      dword ptr [ebx - 0x54]
00414338  d86bb0                   fsubr     dword ptr [ebx - 0x50]
0041433b  dbadacfeffff             fld       xword ptr [ebp - 0x154]
00414341  ded9                     fcompp
00414343  dfe0                     fnstsw    ax
00414345  9e                       sahf
00414346  0f8a2f000000             jp        0x41437b
0041434c  762d                     jbe       0x41437b
0041434e  8d0528b05500             lea       eax, [0x55b028] ; bits=09020000, f32=7.300764999132297e-43
00414354  8b8d64feffff             mov       ecx, dword ptr [ebp - 0x19c]
0041435a  894dfc                   mov       dword ptr [ebp - 4], ecx
0041435d  8d4dfc                   lea       ecx, [ebp - 4]
00414360  894808                   mov       dword ptr [eax + 8], ecx
00414363  dbadacfeffff             fld       xword ptr [ebp - 0x154]
00414369  d95df8                   fstp      dword ptr [ebp - 8]
0041436c  8d4df8                   lea       ecx, [ebp - 8]
0041436f  894828                   mov       dword ptr [eax + 0x28], ecx
00414372  50                       push      eax
00414373  e878e20800               call      0x4a25f0 ; _jwe_isfm
00414378  83c404                   add       esp, 4
0041437b  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0041437e  8b08                     mov       ecx, dword ptr [eax]
00414380  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
00414386  d900                     fld       dword ptr [eax]
00414388  dd1ccdd0156400           fstp      qword ptr [ecx*8 + 0x6415d0]
0041438f  c704cd700c640000000000   mov       dword ptr [ecx*8 + 0x640c70], 0
0041439a  c704cd740c640000000000   mov       dword ptr [ecx*8 + 0x640c74], 0
004143a5  c704cd1003640000000000   mov       dword ptr [ecx*8 + 0x640310], 0
004143b0  c704cd1403640000000000   mov       dword ptr [ecx*8 + 0x640314], 0
004143bb  c704cd2011640000000000   mov       dword ptr [ecx*8 + 0x641120], 0
004143c6  c704cd2411640000000000   mov       dword ptr [ecx*8 + 0x641124], 0
004143d1  d905acf3f200             fld       dword ptr [0xf2f3ac]
004143d7  d82d1cb6e900             fsubr     dword ptr [0xe9b61c]
004143dd  db6d90                   fld       xword ptr [ebp - 0x70]
004143e0  d9c9                     fxch      st(1)
004143e2  d8d1                     fcom      st(1)
004143e4  ddd9                     fstp      st(1)
004143e6  dbbda0feffff             fstp      xword ptr [ebp - 0x160]
004143ec  dfe0                     fnstsw    ax
004143ee  9e                       sahf
004143ef  0f8a11000000             jp        0x414406
004143f5  730f                     jae       0x414406
004143f7  dbada0feffff             fld       xword ptr [ebp - 0x160]
004143fd  d91c8d64fe6300           fstp      dword ptr [ecx*4 + 0x63fe64]
00414404  eb0a                     jmp       0x414410
00414406  db6d90                   fld       xword ptr [ebp - 0x70]
00414409  d91c8d64fe6300           fstp      dword ptr [ecx*4 + 0x63fe64]
00414410  d9054cb6e900             fld       dword ptr [0xe9b64c]
00414416  d82d1cb6e900             fsubr     dword ptr [0xe9b61c]
0041441c  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00414422  d9c9                     fxch      st(1)
00414424  d8d1                     fcom      st(1)
00414426  ddd9                     fstp      st(1)
00414428  dbbd94feffff             fstp      xword ptr [ebp - 0x16c]
0041442e  dfe0                     fnstsw    ax
00414430  9e                       sahf
00414431  0f8a11000000             jp        0x414448
00414437  770f                     ja        0x414448
00414439  dbad94feffff             fld       xword ptr [ebp - 0x16c]
0041443f  dd1ccd801a6400           fstp      qword ptr [ecx*8 + 0x641a80]
00414446  eb0d                     jmp       0x414455
00414448  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0041444e  dd1ccd801a6400           fstp      qword ptr [ecx*8 + 0x641a80]
00414455  dd04cd18116400           fld       qword ptr [ecx*8 + 0x641118]
0041445c  dc3ccd680c6400           fdivr     qword ptr [ecx*8 + 0x640c68]
00414463  dd1d10b55500             fstp      qword ptr [0x55b510] ; bits=0000000000000000, f64=0.0
00414469  6a01                     push      1
0041446b  6868b55500               push      0x55b568
00414470  68c8076400               push      0x6407c8
00414475  6810b55500               push      0x55b510
0041447a  8d0588ad5500             lea       eax, [0x55ad88] ; bits=405a0b00, f32=1.0425660574576639e-39
00414480  8d50b8                   lea       edx, [eax - 0x48]
00414483  52                       push      edx
00414484  8d5080                   lea       edx, [eax - 0x80]
00414487  52                       push      edx
00414488  8d40bc                   lea       eax, [eax - 0x44]
0041448b  50                       push      eax
0041448c  68780c6400               push      0x640c78
00414491  6828116400               push      0x641128
00414496  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00414499  89855cfeffff             mov       dword ptr [ebp - 0x1a4], eax
0041449f  8d10                     lea       edx, [eax]
004144a1  52                       push      edx
004144a2  8b9590feffff             mov       edx, dword ptr [ebp - 0x170]
004144a8  8d32                     lea       esi, [edx]
004144aa  56                       push      esi
004144ab  e8e0320500               call      0x467790 ; _vlchpp_
004144b0  83c42c                   add       esp, 0x2c
004144b3  bb00000000               mov       ebx, 0
004144b8  8b855cfeffff             mov       eax, dword ptr [ebp - 0x1a4]
004144be  8b08                     mov       ecx, dword ptr [eax]
004144c0  89c8                     mov       eax, ecx
004144c2  3d00000000               cmp       eax, 0
004144c7  898558feffff             mov       dword ptr [ebp - 0x1a8], eax
004144cd  898d54feffff             mov       dword ptr [ebp - 0x1ac], ecx
004144d3  0f8e95000000             jle       0x41456e
004144d9  b801000000               mov       eax, 1
004144de  898574feffff             mov       dword ptr [ebp - 0x18c], eax
004144e4  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
004144ea  8d8867b55500             lea       ecx, [eax + 0x55b567]
004144f0  803920                   cmp       byte ptr [ecx], 0x20
004144f3  7466                     je        0x41455b
004144f5  85db                     test      ebx, ebx
004144f7  7525                     jne       0x41451e
004144f9  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
004144ff  8b08                     mov       ecx, dword ptr [eax]
00414501  8d1508b05500             lea       edx, [0x55b008] ; bits=69020000, f32=8.646011524884121e-43
00414507  894dfc                   mov       dword ptr [ebp - 4], ecx
0041450a  8d4dfc                   lea       ecx, [ebp - 4]
0041450d  894a08                   mov       dword ptr [edx + 8], ecx
00414510  52                       push      edx
00414511  e8dae00800               call      0x4a25f0 ; _jwe_isfm
00414516  83c404                   add       esp, 4
00414519  bb01000000               mov       ebx, 1
0041451e  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00414524  8b9574feffff             mov       edx, dword ptr [ebp - 0x18c]
0041452a  8b08                     mov       ecx, dword ptr [eax]
0041452c  dd04d520116400           fld       qword ptr [edx*8 + 0x641120]
00414533  dc0cd520116400           fmul      qword ptr [edx*8 + 0x641120]
0041453a  8d35dcaf5500             lea       esi, [0x55afdc] ; bits=09020000, f32=7.300764999132297e-43
00414540  894dfc                   mov       dword ptr [ebp - 4], ecx
00414543  8d4dfc                   lea       ecx, [ebp - 4]
00414546  894e08                   mov       dword ptr [esi + 8], ecx
00414549  dd5dd8                   fstp      qword ptr [ebp - 0x28]
0041454c  8d4dd8                   lea       ecx, [ebp - 0x28]
0041454f  894e28                   mov       dword ptr [esi + 0x28], ecx
00414552  56                       push      esi
00414553  e898e00800               call      0x4a25f0 ; _jwe_isfm
00414558  83c404                   add       esp, 4
0041455b  ff8574feffff             inc       dword ptr [ebp - 0x18c]
00414561  83ad58feffff01           sub       dword ptr [ebp - 0x1a8], 1
00414568  0f8576ffffff             jne       0x4144e4
0041456e  85db                     test      ebx, ebx
00414570  7520                     jne       0x414592
00414572  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00414578  8b08                     mov       ecx, dword ptr [eax]
0041457a  8d15bcaf5500             lea       edx, [0x55afbc] ; bits=69020000, f32=8.646011524884121e-43
00414580  894dfc                   mov       dword ptr [ebp - 4], ecx
00414583  8d4dfc                   lea       ecx, [ebp - 4]
00414586  894a08                   mov       dword ptr [edx + 8], ecx
00414589  52                       push      edx
0041458a  e861e00800               call      0x4a25f0 ; _jwe_isfm
0041458f  83c404                   add       esp, 4
00414592  8b8554feffff             mov       eax, dword ptr [ebp - 0x1ac]
00414598  89c3                     mov       ebx, eax
0041459a  3d00000000               cmp       eax, 0
0041459f  0f8e01010000             jle       0x4146a6
004145a5  b801000000               mov       eax, 1
004145aa  8bb554feffff             mov       esi, dword ptr [ebp - 0x1ac]
004145b0  4e                       dec       esi
004145b1  89f1                     mov       ecx, esi
004145b3  89ca                     mov       edx, ecx
004145b5  83fb02                   cmp       ebx, 2
004145b8  898574feffff             mov       dword ptr [ebp - 0x18c], eax
004145be  0f8c9c000000             jl        0x414660
004145c4  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
004145ca  dd04c520116400           fld       qword ptr [eax*8 + 0x641120]
004145d1  d95df8                   fstp      dword ptr [ebp - 8]
004145d4  8b75f8                   mov       esi, dword ptr [ebp - 8]
004145d7  8d3de0f76300             lea       edi, [0x63f7e0]
004145dd  89748f80                 mov       dword ptr [edi + ecx*4 - 0x80], esi
004145e1  dd04c5700c6400           fld       qword ptr [eax*8 + 0x640c70]
004145e8  d95df8                   fstp      dword ptr [ebp - 8]
004145eb  8b75f8                   mov       esi, dword ptr [ebp - 8]
004145ee  89348db8f96300           mov       dword ptr [ecx*4 + 0x63f9b8], esi
004145f5  dd04c5c0076400           fld       qword ptr [eax*8 + 0x6407c0]
004145fc  d95df8                   fstp      dword ptr [ebp - 8]
004145ff  8b75f8                   mov       esi, dword ptr [ebp - 8]
00414602  89349510fc6300           mov       dword ptr [edx*4 + 0x63fc10], esi
00414609  dd04c528116400           fld       qword ptr [eax*8 + 0x641128]
00414610  d95df8                   fstp      dword ptr [ebp - 8]
00414613  8b75f8                   mov       esi, dword ptr [ebp - 8]
00414616  89b48f7cffffff           mov       dword ptr [edi + ecx*4 - 0x84], esi
0041461d  dd04c5780c6400           fld       qword ptr [eax*8 + 0x640c78]
00414624  d95df8                   fstp      dword ptr [ebp - 8]
00414627  8b75f8                   mov       esi, dword ptr [ebp - 8]
0041462a  89348db4f96300           mov       dword ptr [ecx*4 + 0x63f9b4], esi
00414631  dd04c5c8076400           fld       qword ptr [eax*8 + 0x6407c8]
00414638  d95df8                   fstp      dword ptr [ebp - 8]
0041463b  8b75f8                   mov       esi, dword ptr [ebp - 8]
0041463e  8934950cfc6300           mov       dword ptr [edx*4 + 0x63fc0c], esi
00414645  83e902                   sub       ecx, 2
00414648  83ea02                   sub       edx, 2
0041464b  83c002                   add       eax, 2
0041464e  83eb02                   sub       ebx, 2
00414651  83fb02                   cmp       ebx, 2
00414654  898574feffff             mov       dword ptr [ebp - 0x18c], eax
0041465a  0f8d64ffffff             jge       0x4145c4
00414660  85db                     test      ebx, ebx
00414662  7442                     je        0x4146a6
00414664  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
0041466a  dd04c520116400           fld       qword ptr [eax*8 + 0x641120]
00414671  d95df8                   fstp      dword ptr [ebp - 8]
00414674  8b5df8                   mov       ebx, dword ptr [ebp - 8]
00414677  891c8d60f76300           mov       dword ptr [ecx*4 + 0x63f760], ebx
0041467e  dd04c5700c6400           fld       qword ptr [eax*8 + 0x640c70]
00414685  d95df8                   fstp      dword ptr [ebp - 8]
00414688  8b5df8                   mov       ebx, dword ptr [ebp - 8]
0041468b  891c8db8f96300           mov       dword ptr [ecx*4 + 0x63f9b8], ebx
00414692  dd04c5c0076400           fld       qword ptr [eax*8 + 0x6407c0]
00414699  d95df8                   fstp      dword ptr [ebp - 8]
0041469c  8b45f8                   mov       eax, dword ptr [ebp - 8]
0041469f  89049510fc6300           mov       dword ptr [edx*4 + 0x63fc10], eax
004146a6  8b4548                   mov       eax, dword ptr [ebp + 0x48]
004146a9  8d00                     lea       eax, [eax]
004146ab  50                       push      eax
004146ac  8b4544                   mov       eax, dword ptr [ebp + 0x44]
004146af  8d00                     lea       eax, [eax]
004146b1  50                       push      eax
004146b2  6810fc6300               push      0x63fc10
004146b7  68b8f96300               push      0x63f9b8
004146bc  6860f76300               push      0x63f760
004146c1  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
004146c4  8d03                     lea       eax, [ebx]
004146c6  50                       push      eax
004146c7  6848ad5500               push      0x55ad48
004146cc  6830ae5500               push      0x55ae30
004146d1  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
004146d7  8d08                     lea       ecx, [eax]
004146d9  51                       push      ecx
004146da  e8f19e0200               call      0x43e5d0 ; _put1d_
004146df  83c424                   add       esp, 0x24
004146e2  8b0b                     mov       ecx, dword ptr [ebx]
004146e4  83f900                   cmp       ecx, 0
004146e7  0f8ebb000000             jle       0x4147a8
004146ed  b801000000               mov       eax, 1
004146f2  83f902                   cmp       ecx, 2
004146f5  898574feffff             mov       dword ptr [ebp - 0x18c], eax
004146fb  7c74                     jl        0x414771
004146fd  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
00414703  dd04c5d0156400           fld       qword ptr [eax*8 + 0x6415d0]
0041470a  d95df8                   fstp      dword ptr [ebp - 8]
0041470d  8b55f8                   mov       edx, dword ptr [ebp - 8]
00414710  8d1de0f76300             lea       ebx, [0x63f7e0]
00414716  8994837cffffff           mov       dword ptr [ebx + eax*4 - 0x84], edx
0041471d  8b148564fe6300           mov       edx, dword ptr [eax*4 + 0x63fe64]
00414724  891485b4f96300           mov       dword ptr [eax*4 + 0x63f9b4], edx
0041472b  c704850cfc630000000000   mov       dword ptr [eax*4 + 0x63fc0c], 0
00414736  dd04c5d8156400           fld       qword ptr [eax*8 + 0x6415d8]
0041473d  d95df8                   fstp      dword ptr [ebp - 8]
00414740  8b55f8                   mov       edx, dword ptr [ebp - 8]
00414743  89548380                 mov       dword ptr [ebx + eax*4 - 0x80], edx
00414747  8b148568fe6300           mov       edx, dword ptr [eax*4 + 0x63fe68]
0041474e  891485b8f96300           mov       dword ptr [eax*4 + 0x63f9b8], edx
00414755  c7048510fc630000000000   mov       dword ptr [eax*4 + 0x63fc10], 0
00414760  83c002                   add       eax, 2
00414763  83e902                   sub       ecx, 2
00414766  83f902                   cmp       ecx, 2
00414769  898574feffff             mov       dword ptr [ebp - 0x18c], eax
0041476f  7d8c                     jge       0x4146fd
00414771  85c9                     test      ecx, ecx
00414773  7433                     je        0x4147a8
00414775  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
0041477b  dd04c5d0156400           fld       qword ptr [eax*8 + 0x6415d0]
00414782  d95df8                   fstp      dword ptr [ebp - 8]
00414785  8b4df8                   mov       ecx, dword ptr [ebp - 8]
00414788  890c855cf76300           mov       dword ptr [eax*4 + 0x63f75c], ecx
0041478f  8b0c8564fe6300           mov       ecx, dword ptr [eax*4 + 0x63fe64]
00414796  890c85b4f96300           mov       dword ptr [eax*4 + 0x63f9b4], ecx
0041479d  c704850cfc630000000000   mov       dword ptr [eax*4 + 0x63fc0c], 0
004147a8  8b454c                   mov       eax, dword ptr [ebp + 0x4c]
004147ab  8d00                     lea       eax, [eax]
004147ad  50                       push      eax
004147ae  8b4544                   mov       eax, dword ptr [ebp + 0x44]
004147b1  8d00                     lea       eax, [eax]
004147b3  50                       push      eax
004147b4  6810fc6300               push      0x63fc10
004147b9  68b8f96300               push      0x63f9b8
004147be  6860f76300               push      0x63f760
004147c3  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
004147c6  8d03                     lea       eax, [ebx]
004147c8  50                       push      eax
004147c9  8d3588ad5500             lea       esi, [0x55ad88] ; bits=405a0b00, f32=1.0425660574576639e-39
004147cf  8d46bc                   lea       eax, [esi - 0x44]
004147d2  50                       push      eax
004147d3  6830ae5500               push      0x55ae30
004147d8  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
004147de  8d08                     lea       ecx, [eax]
004147e0  51                       push      ecx
004147e1  e8ea9d0200               call      0x43e5d0 ; _put1d_
004147e6  83c424                   add       esp, 0x24
004147e9  8b03                     mov       eax, dword ptr [ebx]
004147eb  dd04c5801a6400           fld       qword ptr [eax*8 + 0x641a80]
004147f2  dc2cc5781a6400           fsubr     qword ptr [eax*8 + 0x641a78]
004147f9  dc34c508036400           fdiv      qword ptr [eax*8 + 0x640308]
00414800  dd1d10b55500             fstp      qword ptr [0x55b510] ; bits=0000000000000000, f64=0.0
00414806  6a01                     push      1
00414808  6868b55500               push      0x55b568
0041480d  68c8076400               push      0x6407c8
00414812  6810b55500               push      0x55b510
00414817  8d46b8                   lea       eax, [esi - 0x48]
0041481a  50                       push      eax
0041481b  8d4680                   lea       eax, [esi - 0x80]
0041481e  50                       push      eax
0041481f  8d76bc                   lea       esi, [esi - 0x44]
00414822  56                       push      esi
00414823  68881a6400               push      0x641a88
00414828  6818036400               push      0x640318
0041482d  8d03                     lea       eax, [ebx]
0041482f  50                       push      eax
00414830  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00414836  8d08                     lea       ecx, [eax]
00414838  51                       push      ecx
00414839  e8522f0500               call      0x467790 ; _vlchpp_
0041483e  83c42c                   add       esp, 0x2c
00414841  8b1b                     mov       ebx, dword ptr [ebx]
00414843  83fb00                   cmp       ebx, 0
00414846  0f8efb000000             jle       0x414947
0041484c  b801000000               mov       eax, 1
00414851  8d4bff                   lea       ecx, [ebx - 1]
00414854  89ca                     mov       edx, ecx
00414856  83fb02                   cmp       ebx, 2
00414859  898574feffff             mov       dword ptr [ebp - 0x18c], eax
0041485f  0f8c9c000000             jl        0x414901
00414865  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
0041486b  dd04c510036400           fld       qword ptr [eax*8 + 0x640310]
00414872  d95df8                   fstp      dword ptr [ebp - 8]
00414875  8b75f8                   mov       esi, dword ptr [ebp - 8]
00414878  8d3de0f76300             lea       edi, [0x63f7e0]
0041487e  89748f80                 mov       dword ptr [edi + ecx*4 - 0x80], esi
00414882  dd04c5801a6400           fld       qword ptr [eax*8 + 0x641a80]
00414889  d95df8                   fstp      dword ptr [ebp - 8]
0041488c  8b75f8                   mov       esi, dword ptr [ebp - 8]
0041488f  89348db8f96300           mov       dword ptr [ecx*4 + 0x63f9b8], esi
00414896  dd04c5c0076400           fld       qword ptr [eax*8 + 0x6407c0]
0041489d  d95df8                   fstp      dword ptr [ebp - 8]
004148a0  8b75f8                   mov       esi, dword ptr [ebp - 8]
004148a3  89349510fc6300           mov       dword ptr [edx*4 + 0x63fc10], esi
004148aa  dd04c518036400           fld       qword ptr [eax*8 + 0x640318]
004148b1  d95df8                   fstp      dword ptr [ebp - 8]
004148b4  8b75f8                   mov       esi, dword ptr [ebp - 8]
004148b7  89b48f7cffffff           mov       dword ptr [edi + ecx*4 - 0x84], esi
004148be  dd04c5881a6400           fld       qword ptr [eax*8 + 0x641a88]
004148c5  d95df8                   fstp      dword ptr [ebp - 8]
004148c8  8b75f8                   mov       esi, dword ptr [ebp - 8]
004148cb  89348db4f96300           mov       dword ptr [ecx*4 + 0x63f9b4], esi
004148d2  dd04c5c8076400           fld       qword ptr [eax*8 + 0x6407c8]
004148d9  d95df8                   fstp      dword ptr [ebp - 8]
004148dc  8b75f8                   mov       esi, dword ptr [ebp - 8]
004148df  8934950cfc6300           mov       dword ptr [edx*4 + 0x63fc0c], esi
004148e6  83e902                   sub       ecx, 2
004148e9  83ea02                   sub       edx, 2
004148ec  83c002                   add       eax, 2
004148ef  83eb02                   sub       ebx, 2
004148f2  83fb02                   cmp       ebx, 2
004148f5  898574feffff             mov       dword ptr [ebp - 0x18c], eax
004148fb  0f8d64ffffff             jge       0x414865
00414901  85db                     test      ebx, ebx
00414903  7442                     je        0x414947
00414905  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
0041490b  dd04c510036400           fld       qword ptr [eax*8 + 0x640310]
00414912  d95df8                   fstp      dword ptr [ebp - 8]
00414915  8b5df8                   mov       ebx, dword ptr [ebp - 8]
00414918  891c8d60f76300           mov       dword ptr [ecx*4 + 0x63f760], ebx
0041491f  dd04c5801a6400           fld       qword ptr [eax*8 + 0x641a80]
00414926  d95df8                   fstp      dword ptr [ebp - 8]
00414929  8b5df8                   mov       ebx, dword ptr [ebp - 8]
0041492c  891c8db8f96300           mov       dword ptr [ecx*4 + 0x63f9b8], ebx
00414933  dd04c5c0076400           fld       qword ptr [eax*8 + 0x6407c0]
0041493a  d95df8                   fstp      dword ptr [ebp - 8]
0041493d  8b45f8                   mov       eax, dword ptr [ebp - 8]
00414940  89049510fc6300           mov       dword ptr [edx*4 + 0x63fc10], eax
00414947  8b4550                   mov       eax, dword ptr [ebp + 0x50]
0041494a  8d00                     lea       eax, [eax]
0041494c  50                       push      eax
0041494d  8b4544                   mov       eax, dword ptr [ebp + 0x44]
00414950  8d00                     lea       eax, [eax]
00414952  50                       push      eax
00414953  6810fc6300               push      0x63fc10
00414958  68b8f96300               push      0x63f9b8
0041495d  6860f76300               push      0x63f760
00414962  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00414965  8d00                     lea       eax, [eax]
00414967  50                       push      eax
00414968  6848ad5500               push      0x55ad48
0041496d  6830ae5500               push      0x55ae30
00414972  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00414978  8d08                     lea       ecx, [eax]
0041497a  51                       push      ecx
0041497b  e8509c0200               call      0x43e5d0 ; _put1d_
00414980  83c424                   add       esp, 0x24
00414983  dd05d8156400             fld       qword ptr [0x6415d8]
00414989  d91decf4f200             fstp      dword ptr [0xf2f4ec]
0041498f  b800000000               mov       eax, 0
00414994  5f                       pop       edi
00414995  5e                       pop       esi
00414996  5b                       pop       ebx
00414997  8be5                     mov       esp, ebp
00414999  5d                       pop       ebp
0041499a  c3                       ret
0041499b  0500000000               add       eax, 0
