; _rapp_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2b1d0
0042b1d0  55                       push      ebp
0042b1d1  8bec                     mov       ebp, esp
0042b1d3  b818000000               mov       eax, 0x18
0042b1d8  e823de0b00               call      0x4e9000 ; __alloca_probe
0042b1dd  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0042b1e0  8b01                     mov       eax, dword ptr [ecx]
0042b1e2  8905b0f1f200             mov       dword ptr [0xf2f1b0], eax
0042b1e8  68d8f1f200               push      0xf2f1d8
0042b1ed  68d4f1f200               push      0xf2f1d4
0042b1f2  68d0f1f200               push      0xf2f1d0
0042b1f7  68ccf1f200               push      0xf2f1cc
0042b1fc  68c8f1f200               push      0xf2f1c8
0042b201  68c4f1f200               push      0xf2f1c4
0042b206  68c0f1f200               push      0xf2f1c0
0042b20b  68b8f1f200               push      0xf2f1b8
0042b210  68b4f1f200               push      0xf2f1b4
0042b215  68bcf1f200               push      0xf2f1bc
0042b21a  68b0f1f200               push      0xf2f1b0
0042b21f  68a0f1f200               push      0xf2f1a0 ; _xs1com_
0042b224  e877030200               call      0x44b5a0 ; _xlktal_
0042b229  83c430                   add       esp, 0x30
0042b22c  d905b0f1f200             fld       dword ptr [0xf2f1b0]
0042b232  db7de8                   fstp      xword ptr [ebp - 0x18]
0042b235  d905acf1f200             fld       dword ptr [0xf2f1ac]
0042b23b  d9c0                     fld       st(0)
0042b23d  d805b0f1f200             fadd      dword ptr [0xf2f1b0]
0042b243  d91da8f1f200             fstp      dword ptr [0xf2f1a8]
0042b249  d905a4f1f200             fld       dword ptr [0xf2f1a4]
0042b24f  d905bcf1f200             fld       dword ptr [0xf2f1bc]
0042b255  d9c0                     fld       st(0)
0042b257  d83da4f1f200             fdivr     dword ptr [0xf2f1a4]
0042b25d  d8c8                     fmul      st(0)
0042b25f  d90534bcf400             fld       dword ptr [0xf4bc34]
0042b265  d9c9                     fxch      st(1)
0042b267  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042b26d  d90544b6e900             fld       dword ptr [0xe9b644]
0042b273  d9055cb6e900             fld       dword ptr [0xe9b65c]
0042b279  db7df4                   fstp      xword ptr [ebp - 0xc]
0042b27c  db6df4                   fld       xword ptr [ebp - 0xc]
0042b27f  d8f9                     fdivr     st(1)
0042b281  d8c8                     fmul      st(0)
0042b283  def3                     fdivrp    st(3)
0042b285  db6df4                   fld       xword ptr [ebp - 0xc]
0042b288  d9cc                     fxch      st(4)
0042b28a  d8d4                     fcom      st(4)
0042b28c  dddc                     fstp      st(4)
0042b28e  db6de8                   fld       xword ptr [ebp - 0x18]
0042b291  d9ca                     fxch      st(2)
0042b293  d9ce                     fxch      st(6)
0042b295  d9cb                     fxch      st(3)
0042b297  d9cd                     fxch      st(5)
0042b299  d9c9                     fxch      st(1)
0042b29b  d9cb                     fxch      st(3)
0042b29d  d9c9                     fxch      st(1)
0042b29f  d9ca                     fxch      st(2)
0042b2a1  d9c9                     fxch      st(1)
0042b2a3  dfe0                     fnstsw    ax
0042b2a5  9e                       sahf
0042b2a6  0f8afd000000             jp        0x42b3a9
0042b2ac  0f87f7000000             ja        0x42b3a9
0042b2b2  ddd8                     fstp      st(0)
0042b2b4  ddd8                     fstp      st(0)
0042b2b6  ddd8                     fstp      st(0)
0042b2b8  ddd8                     fstp      st(0)
0042b2ba  db6df4                   fld       xword ptr [ebp - 0xc]
0042b2bd  def9                     fdivp     st(1)
0042b2bf  8d0db0a65600             lea       ecx, [0x56a6b0] ; bits=64000000, f32=1.401298464324817e-43
0042b2c5  d85188                   fcom      dword ptr [ecx - 0x78]
0042b2c8  dfe0                     fnstsw    ax
0042b2ca  9e                       sahf
0042b2cb  0f8a24000000             jp        0x42b2f5
0042b2d1  7622                     jbe       0x42b2f5
0042b2d3  d82d40a65600             fsubr     dword ptr [0x56a640] ; bits=0000803f, f32=1.0
0042b2d9  d8498c                   fmul      dword ptr [ecx - 0x74]
0042b2dc  d905d0b1e900             fld       dword ptr [0xe9b1d0] ; _rappc_
0042b2e2  d9c0                     fld       st(0)
0042b2e4  d86994                   fsubr     dword ptr [ecx - 0x6c]
0042b2e7  d8ca                     fmul      st(2)
0042b2e9  dec1                     faddp     st(1)
0042b2eb  d9c9                     fxch      st(1)
0042b2ed  d80dd0f2f200             fmul      dword ptr [0xf2f2d0]
0042b2f3  eb0d                     jmp       0x42b302
0042b2f5  ddd8                     fstp      st(0)
0042b2f7  89c8                     mov       eax, ecx
0042b2f9  d94094                   fld       dword ptr [eax - 0x6c]
0042b2fc  d905d0f2f200             fld       dword ptr [0xf2f2d0]
0042b302  c705d4b1e90000000000     mov       dword ptr [0xe9b1d4], 0
0042b30c  d9c3                     fld       st(3)
0042b30e  d80dd4f1f200             fmul      dword ptr [0xf2f1d4]
0042b314  d9cb                     fxch      st(3)
0042b316  d80d74b6e900             fmul      dword ptr [0xe9b674]
0042b31c  dceb                     fsub      st(3), st(0)
0042b31e  d9cb                     fxch      st(3)
0042b320  dec9                     fmulp     st(1)
0042b322  d9ee                     fldz
0042b324  d9c9                     fxch      st(1)
0042b326  d81530a65600             fcom      dword ptr [0x56a630] ; bits=00000000, f32=0.0
0042b32c  d9cb                     fxch      st(3)
0042b32e  d9c9                     fxch      st(1)
0042b330  dfe0                     fnstsw    ax
0042b332  9e                       sahf
0042b333  0f8a06000000             jp        0x42b33f
0042b339  7304                     jae       0x42b33f
0042b33b  dddb                     fstp      st(3)
0042b33d  eb02                     jmp       0x42b341
0042b33f  ddd8                     fstp      st(0)
0042b341  d905ccf2f200             fld       dword ptr [0xf2f2cc]
0042b347  d82dd4f1f200             fsubr     dword ptr [0xf2f1d4]
0042b34d  decc                     fmulp     st(4)
0042b34f  d9cb                     fxch      st(3)
0042b351  d805acf1f200             fadd      dword ptr [0xf2f1ac]
0042b357  d805b0f1f200             fadd      dword ptr [0xf2f1b0]
0042b35d  d9cb                     fxch      st(3)
0042b35f  d8054cb6e900             fadd      dword ptr [0xe9b64c]
0042b365  d80550b6e900             fadd      dword ptr [0xe9b650]
0042b36b  d905a4f1f200             fld       dword ptr [0xf2f1a4]
0042b371  d80dc8f2f200             fmul      dword ptr [0xf2f2c8]
0042b377  d80d44b6e900             fmul      dword ptr [0xe9b644]
0042b37d  d905c4f1f200             fld       dword ptr [0xf2f1c4]
0042b383  d80d64b6e900             fmul      dword ptr [0xe9b664]
0042b389  def9                     fdivp     st(1)
0042b38b  dec1                     faddp     st(1)
0042b38d  dec2                     faddp     st(2)
0042b38f  d8c8                     fmul      st(0)
0042b391  d83d40a65600             fdivr     dword ptr [0x56a640] ; bits=0000803f, f32=1.0
0042b397  d82540a65600             fsub      dword ptr [0x56a640] ; bits=0000803f, f32=1.0
0042b39d  d80dd8b1e900             fmul      dword ptr [0xe9b1d8]
0042b3a3  dec1                     faddp     st(1)
0042b3a5  dee9                     fsubp     st(1)
0042b3a7  eb72                     jmp       0x42b41b
0042b3a9  dddc                     fstp      st(4)
0042b3ab  c705d4b1e90001000000     mov       dword ptr [0xe9b1d4], 1
0042b3b5  d9c5                     fld       st(5)
0042b3b7  d80dd4f1f200             fmul      dword ptr [0xf2f1d4]
0042b3bd  dec4                     faddp     st(4)
0042b3bf  dec3                     faddp     st(3)
0042b3c1  d9cb                     fxch      st(3)
0042b3c3  d80d74b6e900             fmul      dword ptr [0xe9b674]
0042b3c9  d8054cb6e900             fadd      dword ptr [0xe9b64c]
0042b3cf  d80550b6e900             fadd      dword ptr [0xe9b650]
0042b3d5  d9cb                     fxch      st(3)
0042b3d7  d80dc8f2f200             fmul      dword ptr [0xf2f2c8]
0042b3dd  dec9                     fmulp     st(1)
0042b3df  d905c4f1f200             fld       dword ptr [0xf2f1c4]
0042b3e5  d80d64b6e900             fmul      dword ptr [0xe9b664]
0042b3eb  def9                     fdivp     st(1)
0042b3ed  dec2                     faddp     st(2)
0042b3ef  d9ca                     fxch      st(2)
0042b3f1  d80dccf2f200             fmul      dword ptr [0xf2f2cc]
0042b3f7  dec1                     faddp     st(1)
0042b3f9  d905d0b1e900             fld       dword ptr [0xe9b1d0] ; _rappc_
0042b3ff  d80dd0b1e900             fmul      dword ptr [0xe9b1d0] ; _rappc_
0042b405  d83d40a65600             fdivr     dword ptr [0x56a640] ; bits=0000803f, f32=1.0
0042b40b  d82540a65600             fsub      dword ptr [0x56a640] ; bits=0000803f, f32=1.0
0042b411  d80dd8b1e900             fmul      dword ptr [0xe9b1d8]
0042b417  dec1                     faddp     st(1)
0042b419  dee9                     fsubp     st(1)
0042b41b  8be5                     mov       esp, ebp
0042b41d  5d                       pop       ebp
0042b41e  c3                       ret
0042b41f  90                       nop
