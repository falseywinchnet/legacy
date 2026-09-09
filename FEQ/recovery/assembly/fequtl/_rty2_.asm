; _rty2_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2e160
0042e160  55                       push      ebp
0042e161  8bec                     mov       ebp, esp
0042e163  b81c000000               mov       eax, 0x1c
0042e168  e893ae0b00               call      0x4e9000 ; __alloca_probe
0042e16d  53                       push      ebx
0042e16e  56                       push      esi
0042e16f  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0042e172  c705e4b2e90000000000     mov       dword ptr [0xe9b2e4], 0
0042e17c  c705b8bc560002000000     mov       dword ptr [0x56bcb8], 2 ; bits=00000000, f32=0.0
0042e186  8b01                     mov       eax, dword ptr [ecx]
0042e188  8905b0f3f200             mov       dword ptr [0xf2f3b0], eax
0042e18e  68f0f3f200               push      0xf2f3f0
0042e193  68d8f3f200               push      0xf2f3d8
0042e198  68d4f3f200               push      0xf2f3d4
0042e19d  68d0f3f200               push      0xf2f3d0
0042e1a2  68ccf3f200               push      0xf2f3cc
0042e1a7  68c8f3f200               push      0xf2f3c8
0042e1ac  68c4f3f200               push      0xf2f3c4
0042e1b1  68c0f3f200               push      0xf2f3c0
0042e1b6  68b8f3f200               push      0xf2f3b8
0042e1bb  68b4f3f200               push      0xf2f3b4
0042e1c0  68bcf3f200               push      0xf2f3bc
0042e1c5  68b0f3f200               push      0xf2f3b0
0042e1ca  68a0f3f200               push      0xf2f3a0 ; _xs3com_
0042e1cf  e8fcaf0100               call      0x4491d0 ; _xlkt22_
0042e1d4  83c434                   add       esp, 0x34
0042e1d7  8b05f0f3f200             mov       eax, dword ptr [0xf2f3f0]
0042e1dd  8905a4f3f200             mov       dword ptr [0xf2f3a4], eax
0042e1e3  890544b6e900             mov       dword ptr [0xe9b644], eax
0042e1e9  d90520bbf400             fld       dword ptr [0xf4bb20] ; _rdfcom_
0042e1ef  d805f0f3f200             fadd      dword ptr [0xf2f3f0]
0042e1f5  d91da4f1f200             fstp      dword ptr [0xf2f1a4]
0042e1fb  d905acf3f200             fld       dword ptr [0xf2f3ac]
0042e201  d805b0f3f200             fadd      dword ptr [0xf2f3b0]
0042e207  d91da8f3f200             fstp      dword ptr [0xf2f3a8]
0042e20d  6a08                     push      8
0042e20f  68d4b2e900               push      0xe9b2d4
0042e214  8b05c4b2e900             mov       eax, dword ptr [0xe9b2c4]
0042e21a  8d148564caec00           lea       edx, [eax*4 + 0xecca64]
0042e221  52                       push      edx
0042e222  68f0b2e900               push      0xe9b2f0 ; _rty2cc_
0042e227  68b8bc5600               push      0x56bcb8
0042e22c  68c0b2e900               push      0xe9b2c0 ; _rty2c_
0042e231  e86abbffff               call      0x429da0 ; _fcd123_
0042e236  d91de4f2f200             fstp      dword ptr [0xf2f2e4]
0042e23c  83c418                   add       esp, 0x18
0042e23f  68bcf3f200               push      0xf2f3bc
0042e244  68d8b2e900               push      0xe9b2d8
0042e249  68e4f2f200               push      0xf2f2e4
0042e24e  e87dafffff               call      0x4291d0 ; _degcon_
0042e253  d91de0f2f200             fstp      dword ptr [0xf2f2e0] ; _cdcom_
0042e259  83c40c                   add       esp, 0xc
0042e25c  d905e0f2f200             fld       dword ptr [0xf2f2e0] ; _cdcom_
0042e262  d80de0f2f200             fmul      dword ptr [0xf2f2e0] ; _cdcom_
0042e268  d9e8                     fld1
0042e26a  db7de4                   fstp      xword ptr [ebp - 0x1c]
0042e26d  db6de4                   fld       xword ptr [ebp - 0x1c]
0042e270  def1                     fdivrp    st(1)
0042e272  db6de4                   fld       xword ptr [ebp - 0x1c]
0042e275  dee9                     fsubp     st(1)
0042e277  d905bcf3f200             fld       dword ptr [0xf2f3bc]
0042e27d  d83da4f3f200             fdivr     dword ptr [0xf2f3a4]
0042e283  d8c8                     fmul      st(0)
0042e285  dec9                     fmulp     st(1)
0042e287  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042e28d  d91dc8bc5600             fstp      dword ptr [0x56bcc8] ; bits=00000000, f32=0.0
0042e293  c7050cf3f20000000000     mov       dword ptr [0xf2f30c], 0
0042e29d  68c4bc5600               push      0x56bcc4
0042e2a2  6848b6e900               push      0xe9b648
0042e2a7  68bcbc5600               push      0x56bcbc
0042e2ac  68a8f3f200               push      0xf2f3a8
0042e2b1  68a4f3f200               push      0xf2f3a4
0042e2b6  68c8bc5600               push      0x56bcc8
0042e2bb  68c8b2e900               push      0xe9b2c8
0042e2c0  68c4b2e900               push      0xe9b2c4
0042e2c5  68c0b2e900               push      0xe9b2c0 ; _rty2c_
0042e2ca  e82187ffff               call      0x4269f0 ; _sfpsbe_
0042e2cf  db6de4                   fld       xword ptr [ebp - 0x1c]
0042e2d2  83c424                   add       esp, 0x24
0042e2d5  8b0dbcbc5600             mov       ecx, dword ptr [0x56bcbc] ; bits=00000000, f32=0.0
0042e2db  8b05c4b2e900             mov       eax, dword ptr [0xe9b2c4]
0042e2e1  39c1                     cmp       ecx, eax
0042e2e3  7463                     je        0x42e348
0042e2e5  833dc4bc560000           cmp       dword ptr [0x56bcc4], 0 ; bits=00000000, f32=0.0
0042e2ec  755a                     jne       0x42e348
0042e2ee  d91d50bb5600             fstp      dword ptr [0x56bb50] ; bits=00000000, f32=0.0
0042e2f4  8b05b0f3f200             mov       eax, dword ptr [0xf2f3b0]
0042e2fa  8b15a4f3f200             mov       edx, dword ptr [0xf2f3a4]
0042e300  8b1dc4bc5600             mov       ebx, dword ptr [0x56bcc4] ; bits=00000000, f32=0.0
0042e306  8d3568bc5600             lea       esi, [0x56bc68] ; bits=09020000, f32=7.300764999132297e-43
0042e30c  8945fc                   mov       dword ptr [ebp - 4], eax
0042e30f  8d45fc                   lea       eax, [ebp - 4]
0042e312  894628                   mov       dword ptr [esi + 0x28], eax
0042e315  8955f8                   mov       dword ptr [ebp - 8], edx
0042e318  8d45f8                   lea       eax, [ebp - 8]
0042e31b  894634                   mov       dword ptr [esi + 0x34], eax
0042e31e  894df4                   mov       dword ptr [ebp - 0xc], ecx
0042e321  8d45f4                   lea       eax, [ebp - 0xc]
0042e324  894640                   mov       dword ptr [esi + 0x40], eax
0042e327  895df0                   mov       dword ptr [ebp - 0x10], ebx
0042e32a  8d45f0                   lea       eax, [ebp - 0x10]
0042e32d  89464c                   mov       dword ptr [esi + 0x4c], eax
0042e330  56                       push      esi
0042e331  e8ba420700               call      0x4a25f0 ; _jwe_isfm
0042e336  83c404                   add       esp, 4
0042e339  c705e4b2e90002000000     mov       dword ptr [0xe9b2e4], 2
0042e343  e92e010000               jmp       0x42e476
0042e348  ddd8                     fstp      st(0)
0042e34a  8b05c4b2e900             mov       eax, dword ptr [0xe9b2c4]
0042e350  8b0c85e4c3eb00           mov       ecx, dword ptr [eax*4 + 0xebc3e4]
0042e357  890d50b6e900             mov       dword ptr [0xe9b650], ecx
0042e35d  d90550b6e900             fld       dword ptr [0xe9b650]
0042e363  d81decb2e900             fcomp     dword ptr [0xe9b2ec]
0042e369  dfe0                     fnstsw    ax
0042e36b  9e                       sahf
0042e36c  0f8a1d000000             jp        0x42e38f
0042e372  721b                     jb        0x42e38f
0042e374  c705e4b2e90003000000     mov       dword ptr [0xe9b2e4], 3
0042e37e  8d05d0bb5600             lea       eax, [0x56bbd0] ; bits=03000000, f32=4.203895392974451e-45
0042e384  8b4894                   mov       ecx, dword ptr [eax - 0x6c]
0042e387  894880                   mov       dword ptr [eax - 0x80], ecx
0042e38a  e9e7000000               jmp       0x42e476
0042e38f  6878b6e900               push      0xe9b678
0042e394  6874b6e900               push      0xe9b674
0042e399  6870b6e900               push      0xe9b670
0042e39e  686cb6e900               push      0xe9b66c
0042e3a3  6868b6e900               push      0xe9b668
0042e3a8  6864b6e900               push      0xe9b664
0042e3ad  6860b6e900               push      0xe9b660
0042e3b2  6858b6e900               push      0xe9b658
0042e3b7  6854b6e900               push      0xe9b654
0042e3bc  685cb6e900               push      0xe9b65c
0042e3c1  6850b6e900               push      0xe9b650
0042e3c6  6840b6e900               push      0xe9b640 ; _xs2com_
0042e3cb  e8d0d10100               call      0x44b5a0 ; _xlktal_
0042e3d0  83c430                   add       esp, 0x30
0042e3d3  68c0bc5600               push      0x56bcc0
0042e3d8  68d0b2e900               push      0xe9b2d0
0042e3dd  6820bbf400               push      0xf4bb20 ; _rdfcom_
0042e3e2  680cf3f200               push      0xf2f30c
0042e3e7  68e0f2f200               push      0xf2f2e0 ; _cdcom_
0042e3ec  68c0b2e900               push      0xe9b2c0 ; _rty2c_
0042e3f1  e85ad9ffff               call      0x42bd50 ; _appro_
0042e3f6  83c418                   add       esp, 0x18
0042e3f9  8b05c0bc5600             mov       eax, dword ptr [0x56bcc0] ; bits=00000000, f32=0.0
0042e3ff  8905dcb2e900             mov       dword ptr [0xe9b2dc], eax
0042e405  833dc0bc560001           cmp       dword ptr [0x56bcc0], 1 ; bits=00000000, f32=0.0
0042e40c  7541                     jne       0x42e44f
0042e40e  d9e8                     fld1
0042e410  8d05d0bb5600             lea       eax, [0x56bbd0] ; bits=03000000, f32=4.203895392974451e-45
0042e416  d95880                   fstp      dword ptr [eax - 0x80]
0042e419  c705e4b2e90002000000     mov       dword ptr [0xe9b2e4], 2
0042e423  8b0db0f3f200             mov       ecx, dword ptr [0xf2f3b0]
0042e429  8b15a4f3f200             mov       edx, dword ptr [0xf2f3a4]
0042e42f  8d4060                   lea       eax, [eax + 0x60]
0042e432  894dfc                   mov       dword ptr [ebp - 4], ecx
0042e435  8d4dfc                   lea       ecx, [ebp - 4]
0042e438  894828                   mov       dword ptr [eax + 0x28], ecx
0042e43b  8955f8                   mov       dword ptr [ebp - 8], edx
0042e43e  8d4df8                   lea       ecx, [ebp - 8]
0042e441  894834                   mov       dword ptr [eax + 0x34], ecx
0042e444  50                       push      eax
0042e445  e8a6410700               call      0x4a25f0 ; _jwe_isfm
0042e44a  83c404                   add       esp, 4
0042e44d  eb27                     jmp       0x42e476
0042e44f  833dc0bc560002           cmp       dword ptr [0x56bcc0], 2 ; bits=00000000, f32=0.0
0042e456  750c                     jne       0x42e464
0042e458  c705e4b2e90003000000     mov       dword ptr [0xe9b2e4], 3
0042e462  eb12                     jmp       0x42e476
0042e464  d905d4b2e900             fld       dword ptr [0xe9b2d4]
0042e46a  d82da8f1f200             fsubr     dword ptr [0xf2f1a8]
0042e470  d91d50bb5600             fstp      dword ptr [0x56bb50] ; bits=00000000, f32=0.0
0042e476  d90550bb5600             fld       dword ptr [0x56bb50] ; bits=00000000, f32=0.0
0042e47c  5e                       pop       esi
0042e47d  5b                       pop       ebx
0042e47e  8be5                     mov       esp, ebp
0042e480  5d                       pop       ebp
0042e481  c3                       ret
0042e482  8da42400000000           lea       esp, [esp]
0042e489  8da42400000000           lea       esp, [esp]
