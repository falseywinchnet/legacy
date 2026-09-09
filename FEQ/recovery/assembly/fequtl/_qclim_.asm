; _qclim_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x9bc0
00409bc0  55                       push      ebp
00409bc1  8bec                     mov       ebp, esp
00409bc3  b834000000               mov       eax, 0x34
00409bc8  e833f40d00               call      0x4e9000 ; __alloca_probe
00409bcd  53                       push      ebx
00409bce  56                       push      esi
00409bcf  57                       push      edi
00409bd0  8b4508                   mov       eax, dword ptr [ebp + 8]
00409bd3  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00409bd6  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00409bd9  8945e0                   mov       dword ptr [ebp - 0x20], eax
00409bdc  894ddc                   mov       dword ptr [ebp - 0x24], ecx
00409bdf  8955d8                   mov       dword ptr [ebp - 0x28], edx
00409be2  d90530bcf400             fld       dword ptr [0xf4bc30] ; _grvcom_
00409be8  8d1d985d5500             lea       ebx, [0x555d98] ; bits=fa000000, f32=3.5032461608120427e-43
00409bee  d85b88                   fcomp     dword ptr [ebx - 0x78]
00409bf1  dfe0                     fnstsw    ax
00409bf3  9e                       sahf
00409bf4  0f8a07000000             jp        0x409c01
00409bfa  7605                     jbe       0x409c01
00409bfc  d9438c                   fld       dword ptr [ebx - 0x74]
00409bff  eb05                     jmp       0x409c06
00409c01  89d8                     mov       eax, ebx
00409c03  d94090                   fld       dword ptr [eax - 0x70]
00409c06  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409c09  6a50                     push      0x50
00409c0b  68c8605500               push      0x5560c8
00409c10  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00409c13  8d08                     lea       ecx, [eax]
00409c15  51                       push      ecx
00409c16  8b4de0                   mov       ecx, dword ptr [ebp - 0x20]
00409c19  8d11                     lea       edx, [ecx]
00409c1b  52                       push      edx
00409c1c  e8bf2c0400               call      0x44c8e0 ; _inline_
00409c21  83c410                   add       esp, 0x10
00409c24  6878605500               push      0x556078
00409c29  e8227f0900               call      0x4a1b50 ; _jwe_iinf
00409c2e  db6de4                   fld       xword ptr [ebp - 0x1c]
00409c31  83c404                   add       esp, 4
00409c34  85c0                     test      eax, eax
00409c36  0f85d5030000             jne       0x40a011
00409c3c  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409c3f  686c605500               push      0x55606c
00409c44  e8077f0900               call      0x4a1b50 ; _jwe_iinf
00409c49  db6de4                   fld       xword ptr [ebp - 0x1c]
00409c4c  83c404                   add       esp, 4
00409c4f  85c0                     test      eax, eax
00409c51  0f85ba030000             jne       0x40a011
00409c57  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409c5a  6a10                     push      0x10
00409c5c  6820615500               push      0x556120
00409c61  e84a5a0400               call      0x44f6b0 ; _strip_l_blanks_
00409c66  83c408                   add       esp, 8
00409c69  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00409c6c  8b18                     mov       ebx, dword ptr [eax]
00409c6e  6a10                     push      0x10
00409c70  6820615500               push      0x556120
00409c75  e8d65d0400               call      0x44fa50 ; _lenstr_
00409c7a  83c408                   add       esp, 8
00409c7d  89c2                     mov       edx, eax
00409c7f  c1fa1f                   sar       edx, 0x1f
00409c82  f7d2                     not       edx
00409c84  21d0                     and       eax, edx
00409c86  8d0d40605500             lea       ecx, [0x556040] ; bits=09020000, f32=7.300764999132297e-43
00409c8c  895dfc                   mov       dword ptr [ebp - 4], ebx
00409c8f  8d55fc                   lea       edx, [ebp - 4]
00409c92  895108                   mov       dword ptr [ecx + 8], edx
00409c95  894124                   mov       dword ptr [ecx + 0x24], eax
00409c98  51                       push      ecx
00409c99  e852890900               call      0x4a25f0 ; _jwe_isfm
00409c9e  83c404                   add       esp, 4
00409ca1  6a10                     push      0x10
00409ca3  6898605500               push      0x556098
00409ca8  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00409cab  8d08                     lea       ecx, [eax]
00409cad  51                       push      ecx
00409cae  6820615500               push      0x556120
00409cb3  8b4ddc                   mov       ecx, dword ptr [ebp - 0x24]
00409cb6  8d11                     lea       edx, [ecx]
00409cb8  52                       push      edx
00409cb9  e882d60600               call      0x477340 ; _get_internal_tab_number_
00409cbe  db6de4                   fld       xword ptr [ebp - 0x1c]
00409cc1  83c414                   add       esp, 0x14
00409cc4  8b0598605500             mov       eax, dword ptr [0x556098] ; bits=00000000, f32=0.0
00409cca  833c85ec5a0e0400         cmp       dword ptr [eax*4 + 0x40e5aec], 0
00409cd2  7f47                     jg        0x409d1b
00409cd4  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00409cd7  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409cda  8b18                     mov       ebx, dword ptr [eax]
00409cdc  6a10                     push      0x10
00409cde  6820615500               push      0x556120
00409ce3  e8685d0400               call      0x44fa50 ; _lenstr_
00409ce8  83c408                   add       esp, 8
00409ceb  89c2                     mov       edx, eax
00409ced  c1fa1f                   sar       edx, 0x1f
00409cf0  f7d2                     not       edx
00409cf2  21d0                     and       eax, edx
00409cf4  8d0d14605500             lea       ecx, [0x556014] ; bits=09020000, f32=7.300764999132297e-43
00409cfa  895dfc                   mov       dword ptr [ebp - 4], ebx
00409cfd  8d55fc                   lea       edx, [ebp - 4]
00409d00  895108                   mov       dword ptr [ecx + 8], edx
00409d03  894124                   mov       dword ptr [ecx + 0x24], eax
00409d06  51                       push      ecx
00409d07  e8e4880900               call      0x4a25f0 ; _jwe_isfm
00409d0c  db6de4                   fld       xword ptr [ebp - 0x1c]
00409d0f  83c404                   add       esp, 4
00409d12  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00409d15  c70001000000             mov       dword ptr [eax], 1
00409d1b  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409d1e  6a50                     push      0x50
00409d20  68c8605500               push      0x5560c8
00409d25  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00409d28  8d08                     lea       ecx, [eax]
00409d2a  51                       push      ecx
00409d2b  8b4de0                   mov       ecx, dword ptr [ebp - 0x20]
00409d2e  8d11                     lea       edx, [ecx]
00409d30  52                       push      edx
00409d31  e8aa2b0400               call      0x44c8e0 ; _inline_
00409d36  83c410                   add       esp, 0x10
00409d39  68f45f5500               push      0x555ff4
00409d3e  e80d7e0900               call      0x4a1b50 ; _jwe_iinf
00409d43  db6de4                   fld       xword ptr [ebp - 0x1c]
00409d46  83c404                   add       esp, 4
00409d49  85c0                     test      eax, eax
00409d4b  0f85c0020000             jne       0x40a011
00409d51  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409d54  68dc5f5500               push      0x555fdc
00409d59  e8f27d0900               call      0x4a1b50 ; _jwe_iinf
00409d5e  db6de4                   fld       xword ptr [ebp - 0x1c]
00409d61  83c404                   add       esp, 4
00409d64  85c0                     test      eax, eax
00409d66  0f85a5020000             jne       0x40a011
00409d6c  d9059c605500             fld       dword ptr [0x55609c] ; bits=00000000, f32=0.0
00409d72  d9ee                     fldz
00409d74  d9c9                     fxch      st(1)
00409d76  dae9                     fucompp
00409d78  dfe0                     fnstsw    ax
00409d7a  9e                       sahf
00409d7b  0f8a0a000000             jp        0x409d8b
00409d81  7508                     jne       0x409d8b
00409d83  d9e8                     fld1
00409d85  d91d9c605500             fstp      dword ptr [0x55609c] ; bits=00000000, f32=0.0
00409d8b  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00409d8e  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409d91  8b08                     mov       ecx, dword ptr [eax]
00409d93  894dd4                   mov       dword ptr [ebp - 0x2c], ecx
00409d96  8b159c605500             mov       edx, dword ptr [0x55609c] ; bits=00000000, f32=0.0
00409d9c  8d1da45f5500             lea       ebx, [0x555fa4] ; bits=09020000, f32=7.300764999132297e-43
00409da2  894dfc                   mov       dword ptr [ebp - 4], ecx
00409da5  8d75fc                   lea       esi, [ebp - 4]
00409da8  897308                   mov       dword ptr [ebx + 8], esi
00409dab  8955f8                   mov       dword ptr [ebp - 8], edx
00409dae  8d55f8                   lea       edx, [ebp - 8]
00409db1  895334                   mov       dword ptr [ebx + 0x34], edx
00409db4  53                       push      ebx
00409db5  e836880900               call      0x4a25f0 ; _jwe_isfm
00409dba  db6de4                   fld       xword ptr [ebp - 0x1c]
00409dbd  83c404                   add       esp, 4
00409dc0  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00409dc3  833800                   cmp       dword ptr [eax], 0
00409dc6  0f8f8b020000             jg        0x40a057
00409dcc  8b0598605500             mov       eax, dword ptr [0x556098] ; bits=00000000, f32=0.0
00409dd2  8b0c85ec5a0e04           mov       ecx, dword ptr [eax*4 + 0x40e5aec]
00409dd9  890d98605500             mov       dword ptr [0x556098], ecx ; bits=00000000, f32=0.0
00409ddf  8b1c8dc8e5f400           mov       ebx, dword ptr [ecx*4 + 0xf4e5c8]
00409de6  83fb16                   cmp       ebx, 0x16
00409de9  7438                     je        0x409e23
00409deb  83fb19                   cmp       ebx, 0x19
00409dee  7433                     je        0x409e23
00409df0  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409df3  8d05785f5500             lea       eax, [0x555f78] ; bits=09020000, f32=7.300764999132297e-43
00409df9  8b4dd4                   mov       ecx, dword ptr [ebp - 0x2c]
00409dfc  894dfc                   mov       dword ptr [ebp - 4], ecx
00409dff  8d55fc                   lea       edx, [ebp - 4]
00409e02  895008                   mov       dword ptr [eax + 8], edx
00409e05  895df4                   mov       dword ptr [ebp - 0xc], ebx
00409e08  8d55f4                   lea       edx, [ebp - 0xc]
00409e0b  895028                   mov       dword ptr [eax + 0x28], edx
00409e0e  50                       push      eax
00409e0f  e8dc870900               call      0x4a25f0 ; _jwe_isfm
00409e14  db6de4                   fld       xword ptr [ebp - 0x1c]
00409e17  83c404                   add       esp, 4
00409e1a  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00409e1d  c70001000000             mov       dword ptr [eax], 1
00409e23  8b349d445b5700           mov       esi, dword ptr [ebx*4 + 0x575b44]
00409e2a  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00409e2d  833800                   cmp       dword ptr [eax], 0
00409e30  0f8f25020000             jg        0x40a05b
00409e36  8b0598605500             mov       eax, dword ptr [0x556098] ; bits=00000000, f32=0.0
00409e3c  8d4820                   lea       ecx, [eax + 0x20]
00409e3f  8b3c85c0e5f400           mov       edi, dword ptr [eax*4 + 0xf4e5c0]
00409e46  89fb                     mov       ebx, edi
00409e48  d904bdc4e5f400           fld       dword ptr [edi*4 + 0xf4e5c4]
00409e4f  d8d1                     fcom      st(1)
00409e51  d9c9                     fxch      st(1)
00409e53  dfe0                     fnstsw    ax
00409e55  9e                       sahf
00409e56  894dd0                   mov       dword ptr [ebp - 0x30], ecx
00409e59  0f8a3c000000             jp        0x409e9b
00409e5f  763a                     jbe       0x409e9b
00409e61  d9c9                     fxch      st(1)
00409e63  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409e66  8d05405f5500             lea       eax, [0x555f40] ; bits=09020000, f32=7.300764999132297e-43
00409e6c  8b4dd4                   mov       ecx, dword ptr [ebp - 0x2c]
00409e6f  894dfc                   mov       dword ptr [ebp - 4], ecx
00409e72  8d4dfc                   lea       ecx, [ebp - 4]
00409e75  894808                   mov       dword ptr [eax + 8], ecx
00409e78  db6de4                   fld       xword ptr [ebp - 0x1c]
00409e7b  d95df8                   fstp      dword ptr [ebp - 8]
00409e7e  8d4df8                   lea       ecx, [ebp - 8]
00409e81  894828                   mov       dword ptr [eax + 0x28], ecx
00409e84  d95df0                   fstp      dword ptr [ebp - 0x10]
00409e87  8d4df0                   lea       ecx, [ebp - 0x10]
00409e8a  894834                   mov       dword ptr [eax + 0x34], ecx
00409e8d  50                       push      eax
00409e8e  e85d870900               call      0x4a25f0 ; _jwe_isfm
00409e93  db6de4                   fld       xword ptr [ebp - 0x1c]
00409e96  83c404                   add       esp, 4
00409e99  eb02                     jmp       0x409e9d
00409e9b  ddd8                     fstp      st(0)
00409e9d  29f3                     sub       ebx, esi
00409e9f  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
00409ea2  39c3                     cmp       ebx, eax
00409ea4  752d                     jne       0x409ed3
00409ea6  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00409ea9  ddd8                     fstp      st(0)
00409eab  8b08                     mov       ecx, dword ptr [eax]
00409ead  8d05205f5500             lea       eax, [0x555f20] ; bits=69020000, f32=8.646011524884121e-43
00409eb3  894dfc                   mov       dword ptr [ebp - 4], ecx
00409eb6  8d4dfc                   lea       ecx, [ebp - 4]
00409eb9  894808                   mov       dword ptr [eax + 8], ecx
00409ebc  50                       push      eax
00409ebd  e82e870900               call      0x4a25f0 ; _jwe_isfm
00409ec2  83c404                   add       esp, 4
00409ec5  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00409ec8  c70001000000             mov       dword ptr [eax], 1
00409ece  e98a010000               jmp       0x40a05d
00409ed3  d9c0                     fld       st(0)
00409ed5  d82c9dc4e5f400           fsubr     dword ptr [ebx*4 + 0xf4e5c4]
00409edc  d8f1                     fdiv      st(1)
00409ede  d81d305d5500             fcomp     dword ptr [0x555d30] ; bits=0ad7233c, f32=0.009999999776482582
00409ee4  dfe0                     fnstsw    ax
00409ee6  9e                       sahf
00409ee7  0f8ab0ffffff             jp        0x409e9d
00409eed  76ae                     jbe       0x409e9d
00409eef  ddd8                     fstp      st(0)
00409ef1  d9049ddce5f400           fld       dword ptr [ebx*4 + 0xf4e5dc]
00409ef8  d9049dc0e5f400           fld       dword ptr [ebx*4 + 0xf4e5c0]
00409eff  8d4307                   lea       eax, [ebx + 7]
00409f02  29f0                     sub       eax, esi
00409f04  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
00409f0b  89d8                     mov       eax, ebx
00409f0d  29f0                     sub       eax, esi
00409f0f  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
00409f16  8d0c1e                   lea       ecx, [esi + ebx]
00409f19  d9048dc0e5f400           fld       dword ptr [ecx*4 + 0xf4e5c0]
00409f20  d83485c0e5f400           fdiv      dword ptr [eax*4 + 0xf4e5c0]
00409f27  d9ed                     fldln2
00409f29  d9c0                     fld       st(0)
00409f2b  d9c9                     fxch      st(1)
00409f2d  d9ca                     fxch      st(2)
00409f2f  d9f1                     fyl2x
00409f31  d95df8                   fstp      dword ptr [ebp - 8]
00409f34  d945f8                   fld       dword ptr [ebp - 8]
00409f37  d9cd                     fxch      st(5)
00409f39  d8f3                     fdiv      st(3)
00409f3b  d9c1                     fld       st(1)
00409f3d  d9c9                     fxch      st(1)
00409f3f  d9f1                     fyl2x
00409f41  d95df8                   fstp      dword ptr [ebp - 8]
00409f44  d9cc                     fxch      st(4)
00409f46  d84df8                   fmul      dword ptr [ebp - 8]
00409f49  d9cb                     fxch      st(3)
00409f4b  def1                     fdivrp    st(1)
00409f4d  d9cb                     fxch      st(3)
00409f4f  d9c9                     fxch      st(1)
00409f51  d9cb                     fxch      st(3)
00409f53  d9f1                     fyl2x
00409f55  d95df8                   fstp      dword ptr [ebp - 8]
00409f58  d875f8                   fdiv      dword ptr [ebp - 8]
00409f5b  d91da4605500             fstp      dword ptr [0x5560a4] ; bits=00000000, f32=0.0
00409f61  d9ea                     fldl2e
00409f63  d80da4605500             fmul      dword ptr [0x5560a4] ; bits=00000000, f32=0.0
00409f69  d9c0                     fld       st(0)
00409f6b  d9fc                     frndint
00409f6d  dce9                     fsub      st(1), st(0)
00409f6f  d9c9                     fxch      st(1)
00409f71  d9f0                     f2xm1
00409f73  d8052c5d5500             fadd      dword ptr [0x555d2c] ; bits=0000803f, f32=1.0
00409f79  d9fd                     fscale
00409f7b  ddd9                     fstp      st(1)
00409f7d  d95df8                   fstp      dword ptr [ebp - 8]
00409f80  d84df8                   fmul      dword ptr [ebp - 8]
00409f83  d80d9c605500             fmul      dword ptr [0x55609c] ; bits=00000000, f32=0.0
00409f89  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00409f8c  db7de4                   fstp      xword ptr [ebp - 0x1c]
00409f8f  8b08                     mov       ecx, dword ptr [eax]
00409f91  894dcc                   mov       dword ptr [ebp - 0x34], ecx
00409f94  8d05f45e5500             lea       eax, [0x555ef4] ; bits=09020000, f32=7.300764999132297e-43
00409f9a  894dfc                   mov       dword ptr [ebp - 4], ecx
00409f9d  8d55fc                   lea       edx, [ebp - 4]
00409fa0  895008                   mov       dword ptr [eax + 8], edx
00409fa3  db6de4                   fld       xword ptr [ebp - 0x1c]
00409fa6  d95df8                   fstp      dword ptr [ebp - 8]
00409fa9  8d55f8                   lea       edx, [ebp - 8]
00409fac  895028                   mov       dword ptr [eax + 0x28], edx
00409faf  50                       push      eax
00409fb0  e83b860900               call      0x4a25f0 ; _jwe_isfm
00409fb5  83c404                   add       esp, 4
00409fb8  8d4303                   lea       eax, [ebx + 3]
00409fbb  01f0                     add       eax, esi
00409fbd  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
00409fc4  db6de4                   fld       xword ptr [ebp - 0x1c]
00409fc7  db6de4                   fld       xword ptr [ebp - 0x1c]
00409fca  dec9                     fmulp     st(1)
00409fcc  d9c9                     fxch      st(1)
00409fce  d80c85c0e5f400           fmul      dword ptr [eax*4 + 0xf4e5c0]
00409fd5  d8c8                     fmul      st(0)
00409fd7  def9                     fdivp     st(1)
00409fd9  8d05c85e5500             lea       eax, [0x555ec8] ; bits=09020000, f32=7.300764999132297e-43
00409fdf  8b4dcc                   mov       ecx, dword ptr [ebp - 0x34]
00409fe2  894dfc                   mov       dword ptr [ebp - 4], ecx
00409fe5  8d4dfc                   lea       ecx, [ebp - 4]
00409fe8  894808                   mov       dword ptr [eax + 8], ecx
00409feb  d95df8                   fstp      dword ptr [ebp - 8]
00409fee  8d4df8                   lea       ecx, [ebp - 8]
00409ff1  894828                   mov       dword ptr [eax + 0x28], ecx
00409ff4  50                       push      eax
00409ff5  e8f6850900               call      0x4a25f0 ; _jwe_isfm
00409ffa  db6de4                   fld       xword ptr [ebp - 0x1c]
00409ffd  83c404                   add       esp, 4
0040a000  01f3                     add       ebx, esi
0040a002  d9149ddce5f400           fst       dword ptr [ebx*4 + 0xf4e5dc]
0040a009  39fb                     cmp       ebx, edi
0040a00b  7cf3                     jl        0x40a000
0040a00d  ddd8                     fstp      st(0)
0040a00f  eb4c                     jmp       0x40a05d
0040a011  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
0040a014  ddd8                     fstp      st(0)
0040a016  8b18                     mov       ebx, dword ptr [eax]
0040a018  8d059c5e5500             lea       eax, [0x555e9c] ; bits=09820000, f32=4.664782457890884e-41
0040a01e  895dfc                   mov       dword ptr [ebp - 4], ebx
0040a021  8d4dfc                   lea       ecx, [ebp - 4]
0040a024  894808                   mov       dword ptr [eax + 8], ecx
0040a027  50                       push      eax
0040a028  e8538e0900               call      0x4a2e80 ; _jwe_ilst
0040a02d  83c404                   add       esp, 4
0040a030  8d05705e5500             lea       eax, [0x555e70] ; bits=09820000, f32=4.664782457890884e-41
0040a036  895dfc                   mov       dword ptr [ebp - 4], ebx
0040a039  8d4dfc                   lea       ecx, [ebp - 4]
0040a03c  894808                   mov       dword ptr [eax + 8], ecx
0040a03f  50                       push      eax
0040a040  e83b8e0900               call      0x4a2e80 ; _jwe_ilst
0040a045  83c404                   add       esp, 4
0040a048  684c5e5500               push      0x555e4c
0040a04d  e8ee930900               call      0x4a3440 ; _jwe_xstp
0040a052  83c404                   add       esp, 4
0040a055  eb06                     jmp       0x40a05d
0040a057  ddd8                     fstp      st(0)
0040a059  eb02                     jmp       0x40a05d
0040a05b  ddd8                     fstp      st(0)
0040a05d  b800000000               mov       eax, 0
0040a062  5f                       pop       edi
0040a063  5e                       pop       esi
0040a064  5b                       pop       ebx
0040a065  8be5                     mov       esp, ebp
0040a067  5d                       pop       ebp
0040a068  c3                       ret
0040a069  8da42400000000           lea       esp, [esp]
