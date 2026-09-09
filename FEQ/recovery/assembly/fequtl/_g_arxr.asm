; _g_arxr
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xa07b0
004a07b0  55                       push      ebp
004a07b1  8bec                     mov       ebp, esp
004a07b3  83ec64                   sub       esp, 0x64
004a07b6  8b4508                   mov       eax, dword ptr [ebp + 8]
004a07b9  8b08                     mov       ecx, dword ptr [eax]
004a07bb  894dd0                   mov       dword ptr [ebp - 0x30], ecx
004a07be  8b550c                   mov       edx, dword ptr [ebp + 0xc]
004a07c1  8b02                     mov       eax, dword ptr [edx]
004a07c3  8945cc                   mov       dword ptr [ebp - 0x34], eax
004a07c6  d945cc                   fld       dword ptr [ebp - 0x34]
004a07c9  d81d6cdc5400             fcomp     dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a07cf  dfe0                     fnstsw    ax
004a07d1  f6c444                   test      ah, 0x44
004a07d4  7a0b                     jp        0x4a07e1
004a07d6  d90568dc5400             fld       dword ptr [0x54dc68] ; __real@3f800000, bits=0000803f, f32=1.0
004a07dc  e915060000               jmp       0x4a0df6
004a07e1  817dcc00000041           cmp       dword ptr [ebp - 0x34], 0x41000000
004a07e8  7358                     jae       0x4a0842
004a07ea  8b4dcc                   mov       ecx, dword ptr [ebp - 0x34]
004a07ed  81e1ffff1f00             and       ecx, 0x1fffff
004a07f3  85c9                     test      ecx, ecx
004a07f5  754b                     jne       0x4a0842
004a07f7  d945cc                   fld       dword ptr [ebp - 0x34]
004a07fa  e859890400               call      0x4e9158 ; __ftol
004a07ff  8945f8                   mov       dword ptr [ebp - 8], eax
004a0802  db45f8                   fild      dword ptr [ebp - 8]
004a0805  d85dcc                   fcomp     dword ptr [ebp - 0x34]
004a0808  dfe0                     fnstsw    ax
004a080a  f6c444                   test      ah, 0x44
004a080d  7a33                     jp        0x4a0842
004a080f  8b55d0                   mov       edx, dword ptr [ebp - 0x30]
004a0812  8955e0                   mov       dword ptr [ebp - 0x20], edx
004a0815  c745f001000000           mov       dword ptr [ebp - 0x10], 1
004a081c  eb09                     jmp       0x4a0827
004a081e  8b45f0                   mov       eax, dword ptr [ebp - 0x10]
004a0821  83c001                   add       eax, 1
004a0824  8945f0                   mov       dword ptr [ebp - 0x10], eax
004a0827  8b4df0                   mov       ecx, dword ptr [ebp - 0x10]
004a082a  3b4df8                   cmp       ecx, dword ptr [ebp - 8]
004a082d  7d0b                     jge       0x4a083a
004a082f  d945e0                   fld       dword ptr [ebp - 0x20]
004a0832  d84dd0                   fmul      dword ptr [ebp - 0x30]
004a0835  d95de0                   fstp      dword ptr [ebp - 0x20]
004a0838  ebe4                     jmp       0x4a081e
004a083a  d945e0                   fld       dword ptr [ebp - 0x20]
004a083d  e9b4050000               jmp       0x4a0df6
004a0842  d945d0                   fld       dword ptr [ebp - 0x30]
004a0845  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a084b  dfe0                     fnstsw    ax
004a084d  f6c405                   test      ah, 5
004a0850  0f8a25020000             jp        0x4a0a7b
004a0856  8d55cc                   lea       edx, [ebp - 0x34]
004a0859  52                       push      edx
004a085a  e831640500               call      0x4f6c90 ; _f_aint
004a085f  83c404                   add       esp, 4
004a0862  d955c8                   fst       dword ptr [ebp - 0x38]
004a0865  d85dcc                   fcomp     dword ptr [ebp - 0x34]
004a0868  dfe0                     fnstsw    ax
004a086a  f6c444                   test      ah, 0x44
004a086d  7a64                     jp        0x4a08d3
004a086f  d945d0                   fld       dword ptr [ebp - 0x30]
004a0872  d9e0                     fchs
004a0874  d95dc0                   fstp      dword ptr [ebp - 0x40]
004a0877  8d45ec                   lea       eax, [ebp - 0x14]
004a087a  50                       push      eax
004a087b  8b4dcc                   mov       ecx, dword ptr [ebp - 0x34]
004a087e  51                       push      ecx
004a087f  8b55c0                   mov       edx, dword ptr [ebp - 0x40]
004a0882  52                       push      edx
004a0883  e872050000               call      0x4a0dfa ; _jwe_gpow
004a0888  83c40c                   add       esp, 0xc
004a088b  d95de8                   fstp      dword ptr [ebp - 0x18]
004a088e  837dec00                 cmp       dword ptr [ebp - 0x14], 0
004a0892  7405                     je        0x4a0899
004a0894  e9bc030000               jmp       0x4a0c55
004a0899  d945cc                   fld       dword ptr [ebp - 0x34]
004a089c  dc3558dc5400             fdiv      qword ptr [0x54dc58] ; __real@4000000000000000, bits=0000000000000040, f64=2.0
004a08a2  d95dfc                   fstp      dword ptr [ebp - 4]
004a08a5  8d45fc                   lea       eax, [ebp - 4]
004a08a8  50                       push      eax
004a08a9  e8e2630500               call      0x4f6c90 ; _f_aint
004a08ae  83c404                   add       esp, 4
004a08b1  d95df4                   fstp      dword ptr [ebp - 0xc]
004a08b4  d945fc                   fld       dword ptr [ebp - 4]
004a08b7  d85df4                   fcomp     dword ptr [ebp - 0xc]
004a08ba  dfe0                     fnstsw    ax
004a08bc  f6c444                   test      ah, 0x44
004a08bf  7a08                     jp        0x4a08c9
004a08c1  d945e8                   fld       dword ptr [ebp - 0x18]
004a08c4  e92d050000               jmp       0x4a0df6
004a08c9  d945e8                   fld       dword ptr [ebp - 0x18]
004a08cc  d9e0                     fchs
004a08ce  e923050000               jmp       0x4a0df6
004a08d3  833d2828b30000           cmp       dword ptr [0xb32828], 0 ; _jwe_x_init
004a08da  752b                     jne       0x4a0907
004a08dc  c7052828b30002000000     mov       dword ptr [0xb32828], 2 ; _jwe_x_init
004a08e6  c745b400000000           mov       dword ptr [ebp - 0x4c], 0
004a08ed  c745b800000000           mov       dword ptr [ebp - 0x48], 0
004a08f4  c745bc00000000           mov       dword ptr [ebp - 0x44], 0
004a08fb  8d4db4                   lea       ecx, [ebp - 0x4c]
004a08fe  51                       push      ecx
004a08ff  e84ca70000               call      0x4ab050 ; _jwe_xint
004a0904  83c404                   add       esp, 4
004a0907  9b                       wait
004a0908  33d2                     xor       edx, edx
004a090a  8a155aef5b00             mov       dl, byte ptr [0x5bef5a]
004a0910  83fa01                   cmp       edx, 1
004a0913  0f8543010000             jne       0x4a0a5c
004a0919  0fbe05c4ec5b00           movsx     eax, byte ptr [0x5becc4]
004a0920  85c0                     test      eax, eax
004a0922  0f8534010000             jne       0x4a0a5c
004a0928  8b4dd0                   mov       ecx, dword ptr [ebp - 0x30]
004a092b  894dd8                   mov       dword ptr [ebp - 0x28], ecx
004a092e  8b55cc                   mov       edx, dword ptr [ebp - 0x34]
004a0931  8955d4                   mov       dword ptr [ebp - 0x2c], edx
004a0934  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
004a0937  8945dc                   mov       dword ptr [ebp - 0x24], eax
004a093a  8b4dcc                   mov       ecx, dword ptr [ebp - 0x34]
004a093d  894dc4                   mov       dword ptr [ebp - 0x3c], ecx
004a0940  c745e478ea5b00           mov       dword ptr [ebp - 0x1c], 0x5bea78 ; _jwe_lca
004a0947  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a094a  81c21c030000             add       edx, 0x31c
004a0950  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0953  8990b0020000             mov       dword ptr [eax + 0x2b0], edx
004a0959  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a095c  8d55dc                   lea       edx, [ebp - 0x24]
004a095f  8991b8020000             mov       dword ptr [ecx + 0x2b8], edx
004a0965  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0968  8d4dc4                   lea       ecx, [ebp - 0x3c]
004a096b  8988bc020000             mov       dword ptr [eax + 0x2bc], ecx
004a0971  c745e478ea5b00           mov       dword ptr [ebp - 0x1c], 0x5bea78 ; _jwe_lca
004a0978  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a097b  c782cc02000007010000     mov       dword ptr [edx + 0x2cc], 0x107
004a0985  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0988  c680d002000000           mov       byte ptr [eax + 0x2d0], 0
004a098f  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0992  c681d102000000           mov       byte ptr [ecx + 0x2d1], 0
004a0999  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a099c  c782d402000000000000     mov       dword ptr [edx + 0x2d4], 0
004a09a6  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a09a9  c780dc02000000000000     mov       dword ptr [eax + 0x2dc], 0
004a09b3  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a09b6  c681e002000000           mov       byte ptr [ecx + 0x2e0], 0
004a09bd  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a09c0  c682e102000000           mov       byte ptr [edx + 0x2e1], 0
004a09c7  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a09ca  c780e802000000000000     mov       dword ptr [eax + 0x2e8], 0
004a09d4  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a09d7  c781f002000002000000     mov       dword ptr [ecx + 0x2f0], 2
004a09e1  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a09e4  8d45d8                   lea       eax, [ebp - 0x28]
004a09e7  8982f4020000             mov       dword ptr [edx + 0x2f4], eax
004a09ed  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a09f0  66c781f80200000900       mov       word ptr [ecx + 0x2f8], 9
004a09f9  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a09fc  66c782fa0200000000       mov       word ptr [edx + 0x2fa], 0
004a0a05  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0a08  8d4dd4                   lea       ecx, [ebp - 0x2c]
004a0a0b  8988fc020000             mov       dword ptr [eax + 0x2fc], ecx
004a0a11  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0a14  66c782000300000900       mov       word ptr [edx + 0x300], 9
004a0a1d  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0a20  66c780020300000000       mov       word ptr [eax + 0x302], 0
004a0a29  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0a2c  81c1cc020000             add       ecx, 0x2cc
004a0a32  51                       push      ecx
004a0a33  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0a36  ff92fc080000             call      dword ptr [edx + 0x8fc]
004a0a3c  83c404                   add       esp, 4
004a0a3f  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0a42  83b81c03000000           cmp       dword ptr [eax + 0x31c], 0
004a0a49  7411                     je        0x4a0a5c
004a0a4b  8b4ddc                   mov       ecx, dword ptr [ebp - 0x24]
004a0a4e  894dd0                   mov       dword ptr [ebp - 0x30], ecx
004a0a51  8b55c4                   mov       edx, dword ptr [ebp - 0x3c]
004a0a54  8955cc                   mov       dword ptr [ebp - 0x34], edx
004a0a57  e96afdffff               jmp       0x4a07c6
004a0a5c  0fbe05c5ec5b00           movsx     eax, byte ptr [0x5becc5]
004a0a63  83f801                   cmp       eax, 1
004a0a66  750b                     jne       0x4a0a73
004a0a68  d90510db5400             fld       dword ptr [0x54db10] ; _NaN_F, bits=0000c07f, f32=nan
004a0a6e  e983030000               jmp       0x4a0df6
004a0a73  d945d0                   fld       dword ptr [ebp - 0x30]
004a0a76  d9e0                     fchs
004a0a78  d95dd0                   fstp      dword ptr [ebp - 0x30]
004a0a7b  d945d0                   fld       dword ptr [ebp - 0x30]
004a0a7e  d81d6cdc5400             fcomp     dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a0a84  dfe0                     fnstsw    ax
004a0a86  2500410000               and       eax, 0x4100
004a0a8b  752a                     jne       0x4a0ab7
004a0a8d  8d4dec                   lea       ecx, [ebp - 0x14]
004a0a90  51                       push      ecx
004a0a91  8b55cc                   mov       edx, dword ptr [ebp - 0x34]
004a0a94  52                       push      edx
004a0a95  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
004a0a98  50                       push      eax
004a0a99  e85c030000               call      0x4a0dfa ; _jwe_gpow
004a0a9e  83c40c                   add       esp, 0xc
004a0aa1  d95de8                   fstp      dword ptr [ebp - 0x18]
004a0aa4  837dec00                 cmp       dword ptr [ebp - 0x14], 0
004a0aa8  7405                     je        0x4a0aaf
004a0aaa  e9a6010000               jmp       0x4a0c55
004a0aaf  d945e8                   fld       dword ptr [ebp - 0x18]
004a0ab2  e93f030000               jmp       0x4a0df6
004a0ab7  d945cc                   fld       dword ptr [ebp - 0x34]
004a0aba  d81d6cdc5400             fcomp     dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a0ac0  dfe0                     fnstsw    ax
004a0ac2  2500410000               and       eax, 0x4100
004a0ac7  750b                     jne       0x4a0ad4
004a0ac9  d9056cdc5400             fld       dword ptr [0x54dc6c] ; __real@00000000, bits=00000000, f32=0.0
004a0acf  e922030000               jmp       0x4a0df6
004a0ad4  833d2828b30000           cmp       dword ptr [0xb32828], 0 ; _jwe_x_init
004a0adb  752b                     jne       0x4a0b08
004a0add  c7052828b30002000000     mov       dword ptr [0xb32828], 2 ; _jwe_x_init
004a0ae7  c745a800000000           mov       dword ptr [ebp - 0x58], 0
004a0aee  c745ac00000000           mov       dword ptr [ebp - 0x54], 0
004a0af5  c745b000000000           mov       dword ptr [ebp - 0x50], 0
004a0afc  8d4da8                   lea       ecx, [ebp - 0x58]
004a0aff  51                       push      ecx
004a0b00  e84ba50000               call      0x4ab050 ; _jwe_xint
004a0b05  83c404                   add       esp, 4
004a0b08  9b                       wait
004a0b09  33d2                     xor       edx, edx
004a0b0b  8a155aef5b00             mov       dl, byte ptr [0x5bef5a]
004a0b11  83fa01                   cmp       edx, 1
004a0b14  0f8519010000             jne       0x4a0c33
004a0b1a  0fbe05c4ec5b00           movsx     eax, byte ptr [0x5becc4]
004a0b21  85c0                     test      eax, eax
004a0b23  0f850a010000             jne       0x4a0c33
004a0b29  8b4dcc                   mov       ecx, dword ptr [ebp - 0x34]
004a0b2c  894dd4                   mov       dword ptr [ebp - 0x2c], ecx
004a0b2f  8b55d0                   mov       edx, dword ptr [ebp - 0x30]
004a0b32  8955dc                   mov       dword ptr [ebp - 0x24], edx
004a0b35  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
004a0b38  8945c4                   mov       dword ptr [ebp - 0x3c], eax
004a0b3b  c745e478ea5b00           mov       dword ptr [ebp - 0x1c], 0x5bea78 ; _jwe_lca
004a0b42  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0b45  81c11c030000             add       ecx, 0x31c
004a0b4b  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0b4e  898ab0020000             mov       dword ptr [edx + 0x2b0], ecx
004a0b54  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0b57  8d4ddc                   lea       ecx, [ebp - 0x24]
004a0b5a  8988b8020000             mov       dword ptr [eax + 0x2b8], ecx
004a0b60  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0b63  8d45c4                   lea       eax, [ebp - 0x3c]
004a0b66  8982bc020000             mov       dword ptr [edx + 0x2bc], eax
004a0b6c  c745e478ea5b00           mov       dword ptr [ebp - 0x1c], 0x5bea78 ; _jwe_lca
004a0b73  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0b76  c781cc02000006010000     mov       dword ptr [ecx + 0x2cc], 0x106
004a0b80  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0b83  c682d002000000           mov       byte ptr [edx + 0x2d0], 0
004a0b8a  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0b8d  c680d102000000           mov       byte ptr [eax + 0x2d1], 0
004a0b94  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0b97  c781d402000000000000     mov       dword ptr [ecx + 0x2d4], 0
004a0ba1  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0ba4  c782dc02000000000000     mov       dword ptr [edx + 0x2dc], 0
004a0bae  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0bb1  c680e002000000           mov       byte ptr [eax + 0x2e0], 0
004a0bb8  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0bbb  c681e102000000           mov       byte ptr [ecx + 0x2e1], 0
004a0bc2  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0bc5  c782e802000000000000     mov       dword ptr [edx + 0x2e8], 0
004a0bcf  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0bd2  c780f002000001000000     mov       dword ptr [eax + 0x2f0], 1
004a0bdc  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0bdf  8d55d4                   lea       edx, [ebp - 0x2c]
004a0be2  8991f4020000             mov       dword ptr [ecx + 0x2f4], edx
004a0be8  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0beb  66c780f80200000900       mov       word ptr [eax + 0x2f8], 9
004a0bf4  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0bf7  66c781fa0200000000       mov       word ptr [ecx + 0x2fa], 0
004a0c00  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0c03  81c2cc020000             add       edx, 0x2cc
004a0c09  52                       push      edx
004a0c0a  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0c0d  ff90fc080000             call      dword ptr [eax + 0x8fc]
004a0c13  83c404                   add       esp, 4
004a0c16  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0c19  83b91c03000000           cmp       dword ptr [ecx + 0x31c], 0
004a0c20  7411                     je        0x4a0c33
004a0c22  8b55dc                   mov       edx, dword ptr [ebp - 0x24]
004a0c25  8955d0                   mov       dword ptr [ebp - 0x30], edx
004a0c28  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
004a0c2b  8945cc                   mov       dword ptr [ebp - 0x34], eax
004a0c2e  e993fbffff               jmp       0x4a07c6
004a0c33  0fbe0dc5ec5b00           movsx     ecx, byte ptr [0x5becc5]
004a0c3a  83f901                   cmp       ecx, 1
004a0c3d  750b                     jne       0x4a0c4a
004a0c3f  d90518db5400             fld       dword ptr [0x54db18] ; _Inf_F, bits=0000807f, f32=inf
004a0c45  e9ac010000               jmp       0x4a0df6
004a0c4a  d90550dc5400             fld       dword ptr [0x54dc50] ; __real@7f7fffee, bits=eeff7f7f, f32=3.402820018375656e+38
004a0c50  e9a1010000               jmp       0x4a0df6
004a0c55  833d2828b30000           cmp       dword ptr [0xb32828], 0 ; _jwe_x_init
004a0c5c  752b                     jne       0x4a0c89
004a0c5e  c7052828b30002000000     mov       dword ptr [0xb32828], 2 ; _jwe_x_init
004a0c68  c7459c00000000           mov       dword ptr [ebp - 0x64], 0
004a0c6f  c745a000000000           mov       dword ptr [ebp - 0x60], 0
004a0c76  c745a400000000           mov       dword ptr [ebp - 0x5c], 0
004a0c7d  8d559c                   lea       edx, [ebp - 0x64]
004a0c80  52                       push      edx
004a0c81  e8caa30000               call      0x4ab050 ; _jwe_xint
004a0c86  83c404                   add       esp, 4
004a0c89  9b                       wait
004a0c8a  33c0                     xor       eax, eax
004a0c8c  a05aef5b00               mov       al, byte ptr [0x5bef5a]
004a0c91  83f801                   cmp       eax, 1
004a0c94  0f8542010000             jne       0x4a0ddc
004a0c9a  0fbe0dc4ec5b00           movsx     ecx, byte ptr [0x5becc4]
004a0ca1  85c9                     test      ecx, ecx
004a0ca3  0f8533010000             jne       0x4a0ddc
004a0ca9  8b55d0                   mov       edx, dword ptr [ebp - 0x30]
004a0cac  8955d8                   mov       dword ptr [ebp - 0x28], edx
004a0caf  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
004a0cb2  8945d4                   mov       dword ptr [ebp - 0x2c], eax
004a0cb5  8b4dd0                   mov       ecx, dword ptr [ebp - 0x30]
004a0cb8  894ddc                   mov       dword ptr [ebp - 0x24], ecx
004a0cbb  8b55cc                   mov       edx, dword ptr [ebp - 0x34]
004a0cbe  8955c4                   mov       dword ptr [ebp - 0x3c], edx
004a0cc1  c745e478ea5b00           mov       dword ptr [ebp - 0x1c], 0x5bea78 ; _jwe_lca
004a0cc8  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0ccb  051c030000               add       eax, 0x31c
004a0cd0  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0cd3  8981b0020000             mov       dword ptr [ecx + 0x2b0], eax
004a0cd9  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0cdc  8d45dc                   lea       eax, [ebp - 0x24]
004a0cdf  8982b8020000             mov       dword ptr [edx + 0x2b8], eax
004a0ce5  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0ce8  8d55c4                   lea       edx, [ebp - 0x3c]
004a0ceb  8991bc020000             mov       dword ptr [ecx + 0x2bc], edx
004a0cf1  c745e478ea5b00           mov       dword ptr [ebp - 0x1c], 0x5bea78 ; _jwe_lca
004a0cf8  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0cfb  c780cc02000088050000     mov       dword ptr [eax + 0x2cc], 0x588
004a0d05  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0d08  c681d002000000           mov       byte ptr [ecx + 0x2d0], 0
004a0d0f  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0d12  c682d102000000           mov       byte ptr [edx + 0x2d1], 0
004a0d19  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0d1c  c780d402000000000000     mov       dword ptr [eax + 0x2d4], 0
004a0d26  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0d29  c781dc02000000000000     mov       dword ptr [ecx + 0x2dc], 0
004a0d33  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0d36  c682e002000000           mov       byte ptr [edx + 0x2e0], 0
004a0d3d  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0d40  c680e102000000           mov       byte ptr [eax + 0x2e1], 0
004a0d47  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0d4a  c781e802000000000000     mov       dword ptr [ecx + 0x2e8], 0
004a0d54  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0d57  c782f002000002000000     mov       dword ptr [edx + 0x2f0], 2
004a0d61  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0d64  8d4dd8                   lea       ecx, [ebp - 0x28]
004a0d67  8988f4020000             mov       dword ptr [eax + 0x2f4], ecx
004a0d6d  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0d70  66c782f80200000900       mov       word ptr [edx + 0x2f8], 9
004a0d79  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0d7c  66c780fa0200000000       mov       word ptr [eax + 0x2fa], 0
004a0d85  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0d88  8d55d4                   lea       edx, [ebp - 0x2c]
004a0d8b  8991fc020000             mov       dword ptr [ecx + 0x2fc], edx
004a0d91  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0d94  66c780000300000900       mov       word ptr [eax + 0x300], 9
004a0d9d  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0da0  66c781020300000000       mov       word ptr [ecx + 0x302], 0
004a0da9  8b55e4                   mov       edx, dword ptr [ebp - 0x1c]
004a0dac  81c2cc020000             add       edx, 0x2cc
004a0db2  52                       push      edx
004a0db3  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004a0db6  ff90fc080000             call      dword ptr [eax + 0x8fc]
004a0dbc  83c404                   add       esp, 4
004a0dbf  8b4de4                   mov       ecx, dword ptr [ebp - 0x1c]
004a0dc2  83b91c03000000           cmp       dword ptr [ecx + 0x31c], 0
004a0dc9  7411                     je        0x4a0ddc
004a0dcb  8b55dc                   mov       edx, dword ptr [ebp - 0x24]
004a0dce  8955d0                   mov       dword ptr [ebp - 0x30], edx
004a0dd1  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
004a0dd4  8945cc                   mov       dword ptr [ebp - 0x34], eax
004a0dd7  e9eaf9ffff               jmp       0x4a07c6
004a0ddc  0fbe0dc5ec5b00           movsx     ecx, byte ptr [0x5becc5]
004a0de3  83f901                   cmp       ecx, 1
004a0de6  7508                     jne       0x4a0df0
004a0de8  d90518db5400             fld       dword ptr [0x54db18] ; _Inf_F, bits=0000807f, f32=inf
004a0dee  eb06                     jmp       0x4a0df6
004a0df0  d90550dc5400             fld       dword ptr [0x54dc50] ; __real@7f7fffee, bits=eeff7f7f, f32=3.402820018375656e+38
004a0df6  8be5                     mov       esp, ebp
004a0df8  5d                       pop       ebp
004a0df9  c3                       ret
