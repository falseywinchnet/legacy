; _ecechk_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x33c70
00433c70  55                       push      ebp
00433c71  8bec                     mov       ebp, esp
00433c73  b81c000000               mov       eax, 0x1c
00433c78  e883530b00               call      0x4e9000 ; __alloca_probe
00433c7d  d90574aee900             fld       dword ptr [0xe9ae74]
00433c83  d80d74aee900             fmul      dword ptr [0xe9ae74]
00433c89  d80d64aee900             fmul      dword ptr [0xe9ae64]
00433c8f  db7df0                   fstp      xword ptr [ebp - 0x10]
00433c92  6884aee900               push      0xe9ae84
00433c97  6848aee900               push      0xe9ae48
00433c9c  6844aee900               push      0xe9ae44
00433ca1  e89a010000               call      0x433e40 ; _gmean_
00433ca6  83c40c                   add       esp, 0xc
00433ca9  db6df0                   fld       xword ptr [ebp - 0x10]
00433cac  def1                     fdivrp    st(1)
00433cae  db7de4                   fstp      xword ptr [ebp - 0x1c]
00433cb1  d90540aee900             fld       dword ptr [0xe9ae40]
00433cb7  d9fa                     fsqrt
00433cb9  d95dfc                   fstp      dword ptr [ebp - 4]
00433cbc  d90538aee900             fld       dword ptr [0xe9ae38]
00433cc2  d87dfc                   fdivr     dword ptr [ebp - 4]
00433cc5  d9053caee900             fld       dword ptr [0xe9ae3c]
00433ccb  d9fa                     fsqrt
00433ccd  d95dfc                   fstp      dword ptr [ebp - 4]
00433cd0  d90534aee900             fld       dword ptr [0xe9ae34]
00433cd6  d87dfc                   fdivr     dword ptr [ebp - 4]
00433cd9  dee9                     fsubp     st(1)
00433cdb  d80d74aee900             fmul      dword ptr [0xe9ae74]
00433ce1  d95dfc                   fstp      dword ptr [ebp - 4]
00433ce4  6860aee900               push      0xe9ae60
00433ce9  685caee900               push      0xe9ae5c
00433cee  6868aee900               push      0xe9ae68
00433cf3  8d45fc                   lea       eax, [ebp - 4]
00433cf6  50                       push      eax
00433cf7  e894000000               call      0x433d90 ; _facdc_
00433cfc  83c410                   add       esp, 0x10
00433cff  d90574aee900             fld       dword ptr [0xe9ae74]
00433d05  d9c9                     fxch      st(1)
00433d07  d80d74aee900             fmul      dword ptr [0xe9ae74]
00433d0d  d90540aee900             fld       dword ptr [0xe9ae40]
00433d13  d9c0                     fld       st(0)
00433d15  d9fa                     fsqrt
00433d17  d95dfc                   fstp      dword ptr [ebp - 4]
00433d1a  d90538aee900             fld       dword ptr [0xe9ae38]
00433d20  d9c0                     fld       st(0)
00433d22  d87dfc                   fdivr     dword ptr [ebp - 4]
00433d25  d9053caee900             fld       dword ptr [0xe9ae3c]
00433d2b  d9fa                     fsqrt
00433d2d  d95dfc                   fstp      dword ptr [ebp - 4]
00433d30  d90534aee900             fld       dword ptr [0xe9ae34]
00433d36  d87dfc                   fdivr     dword ptr [ebp - 4]
00433d39  dec1                     faddp     st(1)
00433d3b  decb                     fmulp     st(3)
00433d3d  d9ca                     fxch      st(2)
00433d3f  d8356caee900             fdiv      dword ptr [0xe9ae6c]
00433d45  d9cb                     fxch      st(3)
00433d47  d8c8                     fmul      st(0)
00433d49  dec9                     fmulp     st(1)
00433d4b  d9c9                     fxch      st(1)
00433d4d  d8c8                     fmul      st(0)
00433d4f  d80d6caee900             fmul      dword ptr [0xe9ae6c]
00433d55  def9                     fdivp     st(1)
00433d57  d80528aee900             fadd      dword ptr [0xe9ae28]
00433d5d  d82d20aee900             fsubr     dword ptr [0xe9ae20] ; _feccom_
00433d63  dce1                     fsubr     st(1), st(0)
00433d65  db6de4                   fld       xword ptr [ebp - 0x1c]
00433d68  deea                     fsubp     st(2)
00433d6a  d8157cf70e04             fcom      dword ptr [0x40ef77c]
00433d70  dfe0                     fnstsw    ax
00433d72  66a90041                 test      ax, 0x4100
00433d76  7408                     je        0x433d80
00433d78  ddd8                     fstp      st(0)
00433d7a  d9057cf70e04             fld       dword ptr [0x40ef77c]
00433d80  def9                     fdivp     st(1)
00433d82  8be5                     mov       esp, ebp
00433d84  5d                       pop       ebp
00433d85  c3                       ret
00433d86  8d4900                   lea       ecx, [ecx]
00433d89  8da42400000000           lea       esp, [esp]
