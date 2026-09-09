; _ftothq_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2f230
0042f230  55                       push      ebp
0042f231  8bec                     mov       ebp, esp
0042f233  b8e0000000               mov       eax, 0xe0
0042f238  e8c39d0b00               call      0x4e9000 ; __alloca_probe
0042f23d  53                       push      ebx
0042f23e  56                       push      esi
0042f23f  57                       push      edi
0042f240  8b7d08                   mov       edi, dword ptr [ebp + 8]
0042f243  8b450c                   mov       eax, dword ptr [ebp + 0xc]
0042f246  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
0042f249  898524ffffff             mov       dword ptr [ebp - 0xdc], eax
0042f24f  898d20ffffff             mov       dword ptr [ebp - 0xe0], ecx
0042f255  bb00000000               mov       ebx, 0
0042f25a  d9053cbcf400             fld       dword ptr [0xf4bc3c]
0042f260  d80de0c75600             fmul      dword ptr [0x56c7e0] ; bits=a19df33e, f32=0.47581198811531067
0042f266  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0042f269  d900                     fld       dword ptr [eax]
0042f26b  d9c9                     fxch      st(1)
0042f26d  d808                     fmul      dword ptr [eax]
0042f26f  d9c1                     fld       st(1)
0042f271  d9fa                     fsqrt
0042f273  d95dfc                   fstp      dword ptr [ebp - 4]
0042f276  d84dfc                   fmul      dword ptr [ebp - 4]
0042f279  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0042f27c  d900                     fld       dword ptr [eax]
0042f27e  d9ee                     fldz
0042f280  d9c9                     fxch      st(1)
0042f282  dde1                     fucom     st(1)
0042f284  ddd9                     fstp      st(1)
0042f286  db7dc4                   fstp      xword ptr [ebp - 0x3c]
0042f289  d9c9                     fxch      st(1)
0042f28b  db7db8                   fstp      xword ptr [ebp - 0x48]
0042f28e  dfe0                     fnstsw    ax
0042f290  9e                       sahf
0042f291  0f8a1e000000             jp        0x42f2b5
0042f297  751c                     jne       0x42f2b5
0042f299  ddd8                     fstp      st(0)
0042f29b  68a4ca5600               push      0x56caa4
0042f2a0  e8db3b0700               call      0x4a2e80 ; _jwe_ilst
0042f2a5  83c404                   add       esp, 4
0042f2a8  6858c95600               push      0x56c958
0042f2ad  e88e410700               call      0x4a3440 ; _jwe_xstp
0042f2b2  83c404                   add       esp, 4
0042f2b5  db6db8                   fld       xword ptr [ebp - 0x48]
0042f2b8  db6dc4                   fld       xword ptr [ebp - 0x3c]
0042f2bb  def9                     fdivp     st(1)
0042f2bd  d91de0ca5600             fstp      dword ptr [0x56cae0] ; bits=00000000, f32=0.0
0042f2c3  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0042f2c6  d9e8                     fld1
0042f2c8  d830                     fdiv      dword ptr [eax]
0042f2ca  db7dac                   fstp      xword ptr [ebp - 0x54]
0042f2cd  db6db8                   fld       xword ptr [ebp - 0x48]
0042f2d0  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
0042f2d6  db7da0                   fstp      xword ptr [ebp - 0x60]
0042f2d9  d900                     fld       dword ptr [eax]
0042f2db  db7d94                   fstp      xword ptr [ebp - 0x6c]
0042f2de  eb02                     jmp       0x42f2e2
0042f2e0  ddd8                     fstp      st(0)
0042f2e2  db6dac                   fld       xword ptr [ebp - 0x54]
0042f2e5  d8c9                     fmul      st(1)
0042f2e7  d8c8                     fmul      st(0)
0042f2e9  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042f2ef  db6da0                   fld       xword ptr [ebp - 0x60]
0042f2f2  dec1                     faddp     st(1)
0042f2f4  d91dd8ca5600             fstp      dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f2fa  d905e0ca5600             fld       dword ptr [0x56cae0] ; bits=00000000, f32=0.0
0042f300  db6d94                   fld       xword ptr [ebp - 0x6c]
0042f303  d9c9                     fxch      st(1)
0042f305  d8d1                     fcom      st(1)
0042f307  ddd9                     fstp      st(1)
0042f309  dfe0                     fnstsw    ax
0042f30b  9e                       sahf
0042f30c  0f8a8b000000             jp        0x42f39d
0042f312  0f8685000000             jbe       0x42f39d
0042f318  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0042f31b  d900                     fld       dword ptr [eax]
0042f31d  d9c9                     fxch      st(1)
0042f31f  d818                     fcomp     dword ptr [eax]
0042f321  dfe0                     fnstsw    ax
0042f323  9e                       sahf
0042f324  0f8a41000000             jp        0x42f36b
0042f32a  763f                     jbe       0x42f36b
0042f32c  8b7528                   mov       esi, dword ptr [ebp + 0x28]
0042f32f  833e00                   cmp       dword ptr [esi], 0
0042f332  753b                     jne       0x42f36f
0042f334  d9c9                     fxch      st(1)
0042f336  db7ddc                   fstp      xword ptr [ebp - 0x24]
0042f339  8b05e0ca5600             mov       eax, dword ptr [0x56cae0] ; bits=00000000, f32=0.0
0042f33f  8d0d6cca5600             lea       ecx, [0x56ca6c] ; bits=09020000, f32=7.300764999132297e-43
0042f345  8945fc                   mov       dword ptr [ebp - 4], eax
0042f348  8d45fc                   lea       eax, [ebp - 4]
0042f34b  894128                   mov       dword ptr [ecx + 0x28], eax
0042f34e  d95df8                   fstp      dword ptr [ebp - 8]
0042f351  8d45f8                   lea       eax, [ebp - 8]
0042f354  894134                   mov       dword ptr [ecx + 0x34], eax
0042f357  51                       push      ecx
0042f358  e893320700               call      0x4a25f0 ; _jwe_isfm
0042f35d  db6ddc                   fld       xword ptr [ebp - 0x24]
0042f360  83c404                   add       esp, 4
0042f363  c70601000000             mov       dword ptr [esi], 1
0042f369  eb06                     jmp       0x42f371
0042f36b  ddd8                     fstp      st(0)
0042f36d  eb02                     jmp       0x42f371
0042f36f  ddd8                     fstp      st(0)
0042f371  db7ddc                   fstp      xword ptr [ebp - 0x24]
0042f374  68dcca5600               push      0x56cadc
0042f379  68d0ca5600               push      0x56cad0
0042f37e  68d4ca5600               push      0x56cad4
0042f383  6800c85600               push      0x56c800
0042f388  68e0ca5600               push      0x56cae0
0042f38d  8d07                     lea       eax, [edi]
0042f38f  50                       push      eax
0042f390  e8ab4c0100               call      0x444040 ; _lktab_
0042f395  db6ddc                   fld       xword ptr [ebp - 0x24]
0042f398  83c418                   add       esp, 0x18
0042f39b  eb32                     jmp       0x42f3cf
0042f39d  ddd8                     fstp      st(0)
0042f39f  db7ddc                   fstp      xword ptr [ebp - 0x24]
0042f3a2  68dcca5600               push      0x56cadc
0042f3a7  68d0ca5600               push      0x56cad0
0042f3ac  68d4ca5600               push      0x56cad4
0042f3b1  6800c85600               push      0x56c800
0042f3b6  68d8ca5600               push      0x56cad8
0042f3bb  8b8524ffffff             mov       eax, dword ptr [ebp - 0xdc]
0042f3c1  8d08                     lea       ecx, [eax]
0042f3c3  51                       push      ecx
0042f3c4  e8774c0100               call      0x444040 ; _lktab_
0042f3c9  db6ddc                   fld       xword ptr [ebp - 0x24]
0042f3cc  83c418                   add       esp, 0x18
0042f3cf  d905d8ca5600             fld       dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f3d5  d905d4ca5600             fld       dword ptr [0x56cad4] ; bits=00000000, f32=0.0
0042f3db  d80dd8ca5600             fmul      dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f3e1  d9c9                     fxch      st(1)
0042f3e3  d9fa                     fsqrt
0042f3e5  d95dfc                   fstp      dword ptr [ebp - 4]
0042f3e8  d84dfc                   fmul      dword ptr [ebp - 4]
0042f3eb  d9c1                     fld       st(1)
0042f3ed  d8c1                     fadd      st(1)
0042f3ef  8d0558c85600             lea       eax, [0x56c858] ; bits=c0d40100, f32=1.6815581571897805e-40
0042f3f5  d8488c                   fmul      dword ptr [eax - 0x74]
0042f3f8  d9ca                     fxch      st(2)
0042f3fa  d8e9                     fsubr     st(1)
0042f3fc  d9e1                     fabs
0042f3fe  def2                     fdivrp    st(2)
0042f400  d9c9                     fxch      st(1)
0042f402  d85890                   fcomp     dword ptr [eax - 0x70]
0042f405  dfe0                     fnstsw    ax
0042f407  9e                       sahf
0042f408  0f8ae9010000             jp        0x42f5f7
0042f40e  0f87e3010000             ja        0x42f5f7
0042f414  db7ddc                   fstp      xword ptr [ebp - 0x24]
0042f417  8b4530                   mov       eax, dword ptr [ebp + 0x30]
0042f41a  db6ddc                   fld       xword ptr [ebp - 0x24]
0042f41d  d918                     fstp      dword ptr [eax]
0042f41f  8b4534                   mov       eax, dword ptr [ebp + 0x34]
0042f422  8b0dd8ca5600             mov       ecx, dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f428  8908                     mov       dword ptr [eax], ecx
0042f42a  d905d4ca5600             fld       dword ptr [0x56cad4] ; bits=00000000, f32=0.0
0042f430  d80dd4ca5600             fmul      dword ptr [0x56cad4] ; bits=00000000, f32=0.0
0042f436  d905d8ca5600             fld       dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f43c  d9c0                     fld       st(0)
0042f43e  d80dd8ca5600             fmul      dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f444  dec9                     fmulp     st(1)
0042f446  dec9                     fmulp     st(1)
0042f448  d83530bcf400             fdiv      dword ptr [0xf4bc30] ; _grvcom_
0042f44e  d95dfc                   fstp      dword ptr [ebp - 4]
0042f451  8d1d58c85600             lea       ebx, [0x56c858] ; bits=c0d40100, f32=1.6815581571897805e-40
0042f457  8d4394                   lea       eax, [ebx - 0x6c]
0042f45a  50                       push      eax
0042f45b  8d45fc                   lea       eax, [ebp - 4]
0042f45e  50                       push      eax
0042f45f  e84c130700               call      0x4a07b0 ; _g_arxr
0042f464  83c408                   add       esp, 8
0042f467  8b4538                   mov       eax, dword ptr [ebp + 0x38]
0042f46a  d910                     fst       dword ptr [eax]
0042f46c  d84b98                   fmul      dword ptr [ebx - 0x68]
0042f46f  d82dd8ca5600             fsubr     dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f475  db7d88                   fstp      xword ptr [ebp - 0x78]
0042f478  d9ee                     fldz
0042f47a  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
0042f480  db6d88                   fld       xword ptr [ebp - 0x78]
0042f483  dbad7cffffff             fld       xword ptr [ebp - 0x84]
0042f489  d9c9                     fxch      st(1)
0042f48b  ded9                     fcompp
0042f48d  db6ddc                   fld       xword ptr [ebp - 0x24]
0042f490  dfe0                     fnstsw    ax
0042f492  9e                       sahf
0042f493  0f8a0b000000             jp        0x42f4a4
0042f499  7309                     jae       0x42f4a4
0042f49b  dbad7cffffff             fld       xword ptr [ebp - 0x84]
0042f4a1  db7d88                   fstp      xword ptr [ebp - 0x78]
0042f4a4  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0042f4a7  d9e8                     fld1
0042f4a9  d820                     fsub      dword ptr [eax]
0042f4ab  d905d8ca5600             fld       dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f4b1  d9c9                     fxch      st(1)
0042f4b3  d80dd8ca5600             fmul      dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f4b9  8b4d24                   mov       ecx, dword ptr [ebp + 0x24]
0042f4bc  d901                     fld       dword ptr [ecx]
0042f4be  8b5520                   mov       edx, dword ptr [ebp + 0x20]
0042f4c1  d902                     fld       dword ptr [edx]
0042f4c3  d9c0                     fld       st(0)
0042f4c5  d829                     fsubr     dword ptr [ecx]
0042f4c7  d9cc                     fxch      st(4)
0042f4c9  d808                     fmul      dword ptr [eax]
0042f4cb  d8c4                     fadd      st(4)
0042f4cd  defd                     fdivp     st(5)
0042f4cf  d9cc                     fxch      st(4)
0042f4d1  d8c8                     fmul      st(0)
0042f4d3  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042f4d9  deea                     fsubp     st(2)
0042f4db  d9ee                     fldz
0042f4dd  d9ca                     fxch      st(2)
0042f4df  d815d8c75600             fcom      dword ptr [0x56c7d8] ; bits=00000000, f32=0.0
0042f4e5  d9c9                     fxch      st(1)
0042f4e7  dbbd70ffffff             fstp      xword ptr [ebp - 0x90]
0042f4ed  d9cb                     fxch      st(3)
0042f4ef  dbbd64ffffff             fstp      xword ptr [ebp - 0x9c]
0042f4f5  d9c9                     fxch      st(1)
0042f4f7  dbbd58ffffff             fstp      xword ptr [ebp - 0xa8]
0042f4fd  d9c9                     fxch      st(1)
0042f4ff  dbbd4cffffff             fstp      xword ptr [ebp - 0xb4]
0042f505  dbbd40ffffff             fstp      xword ptr [ebp - 0xc0]
0042f50b  dfe0                     fnstsw    ax
0042f50d  9e                       sahf
0042f50e  0f8a13000000             jp        0x42f527
0042f514  7311                     jae       0x42f527
0042f516  d9e8                     fld1
0042f518  dbbd4cffffff             fstp      xword ptr [ebp - 0xb4]
0042f51e  dbad40ffffff             fld       xword ptr [ebp - 0xc0]
0042f524  db7d88                   fstp      xword ptr [ebp - 0x78]
0042f527  db6d88                   fld       xword ptr [ebp - 0x78]
0042f52a  dbad4cffffff             fld       xword ptr [ebp - 0xb4]
0042f530  def9                     fdivp     st(1)
0042f532  d815d8c75600             fcom      dword ptr [0x56c7d8] ; bits=00000000, f32=0.0
0042f538  dbbd34ffffff             fstp      xword ptr [ebp - 0xcc]
0042f53e  dfe0                     fnstsw    ax
0042f540  9e                       sahf
0042f541  0f8a0d000000             jp        0x42f554
0042f547  770b                     ja        0x42f554
0042f549  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
0042f54c  c7000ad7a33b             mov       dword ptr [eax], 0x3ba3d70a
0042f552  eb0b                     jmp       0x42f55f
0042f554  8b453c                   mov       eax, dword ptr [ebp + 0x3c]
0042f557  dbad34ffffff             fld       xword ptr [ebp - 0xcc]
0042f55d  d918                     fstp      dword ptr [eax]
0042f55f  dbad64ffffff             fld       xword ptr [ebp - 0x9c]
0042f565  d80dfcc75600             fmul      dword ptr [0x56c7fc] ; bits=0000a03f, f32=1.25
0042f56b  dbad70ffffff             fld       xword ptr [ebp - 0x90]
0042f571  d9c9                     fxch      st(1)
0042f573  ded9                     fcompp
0042f575  dfe0                     fnstsw    ax
0042f577  9e                       sahf
0042f578  0f8a36000000             jp        0x42f5b4
0042f57e  7634                     jbe       0x42f5b4
0042f580  8b5d2c                   mov       ebx, dword ptr [ebp + 0x2c]
0042f583  833b00                   cmp       dword ptr [ebx], 0
0042f586  752c                     jne       0x42f5b4
0042f588  dbad64ffffff             fld       xword ptr [ebp - 0x9c]
0042f58e  dbad58ffffff             fld       xword ptr [ebp - 0xa8]
0042f594  def9                     fdivp     st(1)
0042f596  8d0540ca5600             lea       eax, [0x56ca40] ; bits=09020000, f32=7.300764999132297e-43
0042f59c  d95dfc                   fstp      dword ptr [ebp - 4]
0042f59f  8d4dfc                   lea       ecx, [ebp - 4]
0042f5a2  894828                   mov       dword ptr [eax + 0x28], ecx
0042f5a5  50                       push      eax
0042f5a6  e845300700               call      0x4a25f0 ; _jwe_isfm
0042f5ab  83c404                   add       esp, 4
0042f5ae  c70301000000             mov       dword ptr [ebx], 1
0042f5b4  dbad70ffffff             fld       xword ptr [ebp - 0x90]
0042f5ba  d80d30bcf400             fmul      dword ptr [0xf4bc30] ; _grvcom_
0042f5c0  d9fa                     fsqrt
0042f5c2  d95dfc                   fstp      dword ptr [ebp - 4]
0042f5c5  dbad70ffffff             fld       xword ptr [ebp - 0x90]
0042f5cb  d84dfc                   fmul      dword ptr [ebp - 4]
0042f5ce  8b5d30                   mov       ebx, dword ptr [ebp + 0x30]
0042f5d1  d903                     fld       dword ptr [ebx]
0042f5d3  d8d9                     fcomp     st(1)
0042f5d5  dbbd28ffffff             fstp      xword ptr [ebp - 0xd8]
0042f5db  dfe0                     fnstsw    ax
0042f5dd  9e                       sahf
0042f5de  0f8aa8000000             jp        0x42f68c
0042f5e4  0f86a2000000             jbe       0x42f68c
0042f5ea  dbad28ffffff             fld       xword ptr [ebp - 0xd8]
0042f5f0  d91b                     fstp      dword ptr [ebx]
0042f5f2  e995000000               jmp       0x42f68c
0042f5f7  d9c0                     fld       st(0)
0042f5f9  d9c9                     fxch      st(1)
0042f5fb  43                       inc       ebx
0042f5fc  83fb64                   cmp       ebx, 0x64
0042f5ff  0f8edbfcffff             jle       0x42f2e0
0042f605  db7dd0                   fstp      xword ptr [ebp - 0x30]
0042f608  db7ddc                   fstp      xword ptr [ebp - 0x24]
0042f60b  6814ca5600               push      0x56ca14
0042f610  e86b380700               call      0x4a2e80 ; _jwe_ilst
0042f615  83c404                   add       esp, 4
0042f618  8b05d8ca5600             mov       eax, dword ptr [0x56cad8] ; bits=00000000, f32=0.0
0042f61e  8b4d24                   mov       ecx, dword ptr [ebp + 0x24]
0042f621  8b09                     mov       ecx, dword ptr [ecx]
0042f623  8b15d4ca5600             mov       edx, dword ptr [0x56cad4] ; bits=00000000, f32=0.0
0042f629  8b5d20                   mov       ebx, dword ptr [ebp + 0x20]
0042f62c  8b1b                     mov       ebx, dword ptr [ebx]
0042f62e  8d3564c95600             lea       esi, [0x56c964] ; bits=09820000, f32=4.664782457890884e-41
0042f634  8945fc                   mov       dword ptr [ebp - 4], eax
0042f637  8d45fc                   lea       eax, [ebp - 4]
0042f63a  894634                   mov       dword ptr [esi + 0x34], eax
0042f63d  db6dd0                   fld       xword ptr [ebp - 0x30]
0042f640  d95df8                   fstp      dword ptr [ebp - 8]
0042f643  8d45f8                   lea       eax, [ebp - 8]
0042f646  89464c                   mov       dword ptr [esi + 0x4c], eax
0042f649  db6ddc                   fld       xword ptr [ebp - 0x24]
0042f64c  d95df4                   fstp      dword ptr [ebp - 0xc]
0042f64f  8d45f4                   lea       eax, [ebp - 0xc]
0042f652  894664                   mov       dword ptr [esi + 0x64], eax
0042f655  894df0                   mov       dword ptr [ebp - 0x10], ecx
0042f658  8d45f0                   lea       eax, [ebp - 0x10]
0042f65b  89467c                   mov       dword ptr [esi + 0x7c], eax
0042f65e  8955ec                   mov       dword ptr [ebp - 0x14], edx
0042f661  8d45ec                   lea       eax, [ebp - 0x14]
0042f664  898694000000             mov       dword ptr [esi + 0x94], eax
0042f66a  895de8                   mov       dword ptr [ebp - 0x18], ebx
0042f66d  8d45e8                   lea       eax, [ebp - 0x18]
0042f670  8986ac000000             mov       dword ptr [esi + 0xac], eax
0042f676  56                       push      esi
0042f677  e804380700               call      0x4a2e80 ; _jwe_ilst
0042f67c  83c404                   add       esp, 4
0042f67f  684cc95600               push      0x56c94c
0042f684  e8b73d0700               call      0x4a3440 ; _jwe_xstp
0042f689  83c404                   add       esp, 4
0042f68c  b800000000               mov       eax, 0
0042f691  5f                       pop       edi
0042f692  5e                       pop       esi
0042f693  5b                       pop       ebx
0042f694  8be5                     mov       esp, ebp
0042f696  5d                       pop       ebp
0042f697  c3                       ret
0042f698  90                       nop
0042f699  8da42400000000           lea       esp, [esp]
