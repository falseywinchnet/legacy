; _fcd123_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x29da0
00429da0  55                       push      ebp
00429da1  8bec                     mov       ebp, esp
00429da3  b80c000000               mov       eax, 0xc
00429da8  e853f20b00               call      0x4e9000 ; __alloca_probe
00429dad  53                       push      ebx
00429dae  56                       push      esi
00429daf  57                       push      edi
00429db0  8b4508                   mov       eax, dword ptr [ebp + 8]
00429db3  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00429db6  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00429db9  8945f8                   mov       dword ptr [ebp - 8], eax
00429dbc  894df4                   mov       dword ptr [ebp - 0xc], ecx
00429dbf  8d32                     lea       esi, [edx]
00429dc1  8d1d009e5600             lea       ebx, [0x569e00] ; bits=72726f72, f32=4.7427374873930615e+30
00429dc7  8d7b10                   lea       edi, [ebx + 0x10]
00429dca  b908000000               mov       ecx, 8
00429dcf  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00429dd1  7412                     je        0x429de5
00429dd3  8d32                     lea       esi, [edx]
00429dd5  8d7b18                   lea       edi, [ebx + 0x18]
00429dd8  b908000000               mov       ecx, 8
00429ddd  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00429ddf  0f85b5000000             jne       0x429e9a
00429de5  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00429de8  d9054cb6e900             fld       dword ptr [0xe9b64c]
00429dee  d828                     fsubr     dword ptr [eax]
00429df0  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00429df3  d830                     fdiv      dword ptr [eax]
00429df5  d815809d5600             fcom      dword ptr [0x569d80] ; bits=00000000, f32=0.0
00429dfb  dfe0                     fnstsw    ax
00429dfd  9e                       sahf
00429dfe  0f8a02000000             jp        0x429e06
00429e04  7611                     jbe       0x429e17
00429e06  d815889d5600             fcom      dword ptr [0x569d88] ; bits=cdcccc3f, f32=1.600000023841858
00429e0c  dfe0                     fnstsw    ax
00429e0e  9e                       sahf
00429e0f  0f8a1d000000             jp        0x429e32
00429e15  761b                     jbe       0x429e32
00429e17  ddd8                     fstp      st(0)
00429e19  833d04f3f20000           cmp       dword ptr [0xf2f304], 0
00429e20  750a                     jne       0x429e2c
00429e22  c70504f3f20001000000     mov       dword ptr [0xf2f304], 1
00429e2c  d9058c9d5600             fld       dword ptr [0x569d8c] ; bits=08accc3f, f32=1.5989999771118164
00429e32  8d1d009e5600             lea       ebx, [0x569e00] ; bits=72726f72, f32=4.7427374873930615e+30
00429e38  d85390                   fcom      dword ptr [ebx - 0x70]
00429e3b  dfe0                     fnstsw    ax
00429e3d  9e                       sahf
00429e3e  0f8a09000000             jp        0x429e4d
00429e44  7307                     jae       0x429e4d
00429e46  ddd8                     fstp      st(0)
00429e48  d94394                   fld       dword ptr [ebx - 0x6c]
00429e4b  eb21                     jmp       0x429e6e
00429e4d  89d8                     mov       eax, ebx
00429e4f  d9c0                     fld       st(0)
00429e51  d848a4                   fmul      dword ptr [eax - 0x5c]
00429e54  89d8                     mov       eax, ebx
00429e56  d868a0                   fsubr     dword ptr [eax - 0x60]
00429e59  d8c9                     fmul      st(1)
00429e5b  89d8                     mov       eax, ebx
00429e5d  d840d4                   fadd      dword ptr [eax - 0x2c]
00429e60  d8c9                     fmul      st(1)
00429e62  89d8                     mov       eax, ebx
00429e64  d8409c                   fadd      dword ptr [eax - 0x64]
00429e67  dec9                     fmulp     st(1)
00429e69  89d8                     mov       eax, ebx
00429e6b  d84098                   fadd      dword ptr [eax - 0x68]
00429e6e  8d12                     lea       edx, [edx]
00429e70  8d1d109e5600             lea       ebx, [0x569e10] ; bits=50495045, f32=3332.58203125
00429e76  b908000000               mov       ecx, 8
00429e7b  89d6                     mov       esi, edx
00429e7d  89df                     mov       edi, ebx
00429e7f  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00429e81  0f85d5010000             jne       0x42a05c
00429e87  d905f8f2f200             fld       dword ptr [0xf2f2f8]
00429e8d  d80d00f3f200             fmul      dword ptr [0xf2f300]
00429e93  dec9                     fmulp     st(1)
00429e95  e9c2010000               jmp       0x42a05c
00429e9a  8d32                     lea       esi, [edx]
00429e9c  89d8                     mov       eax, ebx
00429e9e  8d7820                   lea       edi, [eax + 0x20]
00429ea1  b908000000               mov       ecx, 8
00429ea6  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00429ea8  0f85be000000             jne       0x429f6c
00429eae  8b45f4                   mov       eax, dword ptr [ebp - 0xc]
00429eb1  833803                   cmp       dword ptr [eax], 3
00429eb4  0f8593000000             jne       0x429f4d
00429eba  d9055cb6e900             fld       dword ptr [0xe9b65c]
00429ec0  d81dbcf3f200             fcomp     dword ptr [0xf2f3bc]
00429ec6  dfe0                     fnstsw    ax
00429ec8  9e                       sahf
00429ec9  0f8a1c000000             jp        0x429eeb
00429ecf  731a                     jae       0x429eeb
00429ed1  8b0540b6e900             mov       eax, dword ptr [0xe9b640] ; _xs2com_
00429ed7  8d0d009e5600             lea       ecx, [0x569e00] ; bits=72726f72, f32=4.7427374873930615e+30
00429edd  894170                   mov       dword ptr [ecx + 0x70], eax
00429ee0  8b0550b6e900             mov       eax, dword ptr [0xe9b650]
00429ee6  894178                   mov       dword ptr [ecx + 0x78], eax
00429ee9  eb18                     jmp       0x429f03
00429eeb  8b05a0f3f200             mov       eax, dword ptr [0xf2f3a0] ; _xs3com_
00429ef1  8d0d009e5600             lea       ecx, [0x569e00] ; bits=72726f72, f32=4.7427374873930615e+30
00429ef7  894170                   mov       dword ptr [ecx + 0x70], eax
00429efa  8b05b0f3f200             mov       eax, dword ptr [0xf2f3b0]
00429f00  894178                   mov       dword ptr [ecx + 0x78], eax
00429f03  8d1d009e5600             lea       ebx, [0x569e00] ; bits=72726f72, f32=4.7427374873930615e+30
00429f09  8d4374                   lea       eax, [ebx + 0x74]
00429f0c  50                       push      eax
00429f0d  8d4378                   lea       eax, [ebx + 0x78]
00429f10  50                       push      eax
00429f11  8d4370                   lea       eax, [ebx + 0x70]
00429f14  50                       push      eax
00429f15  e8f6160200               call      0x44b610 ; _lktqc_
00429f1a  83c40c                   add       esp, 0xc
00429f1d  d94374                   fld       dword ptr [ebx + 0x74]
00429f20  d83da4f3f200             fdivr     dword ptr [0xf2f3a4]
00429f26  d853a8                   fcom      dword ptr [ebx - 0x58]
00429f29  dfe0                     fnstsw    ax
00429f2b  9e                       sahf
00429f2c  0f8a06000000             jp        0x429f38
00429f32  7604                     jbe       0x429f38
00429f34  ddd8                     fstp      st(0)
00429f36  d9e8                     fld1
00429f38  8d05009e5600             lea       eax, [0x569e00] ; bits=72726f72, f32=4.7427374873930615e+30
00429f3e  d9c0                     fld       st(0)
00429f40  d848b8                   fmul      dword ptr [eax - 0x48]
00429f43  d868b4                   fsubr     dword ptr [eax - 0x4c]
00429f46  dec9                     fmulp     st(1)
00429f48  d840b0                   fadd      dword ptr [eax - 0x50]
00429f4b  eb06                     jmp       0x429f53
00429f4d  d905bc9d5600             fld       dword ptr [0x569dbc] ; bits=3333733f, f32=0.949999988079071
00429f53  d905f8f2f200             fld       dword ptr [0xf2f2f8]
00429f59  d80dfcf2f200             fmul      dword ptr [0xf2f2fc]
00429f5f  d80d00f3f200             fmul      dword ptr [0xf2f300]
00429f65  dec9                     fmulp     st(1)
00429f67  e9f0000000               jmp       0x42a05c
00429f6c  8d32                     lea       esi, [edx]
00429f6e  89d8                     mov       eax, ebx
00429f70  8d5828                   lea       ebx, [eax + 0x28]
00429f73  b908000000               mov       ecx, 8
00429f78  89df                     mov       edi, ebx
00429f7a  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00429f7c  0f8592000000             jne       0x42a014
00429f82  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00429f85  d9054cb6e900             fld       dword ptr [0xe9b64c]
00429f8b  d828                     fsubr     dword ptr [eax]
00429f8d  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00429f90  d830                     fdiv      dword ptr [eax]
00429f92  d815809d5600             fcom      dword ptr [0x569d80] ; bits=00000000, f32=0.0
00429f98  dfe0                     fnstsw    ax
00429f9a  9e                       sahf
00429f9b  0f8a02000000             jp        0x429fa3
00429fa1  7611                     jbe       0x429fb4
00429fa3  d815889d5600             fcom      dword ptr [0x569d88] ; bits=cdcccc3f, f32=1.600000023841858
00429fa9  dfe0                     fnstsw    ax
00429fab  9e                       sahf
00429fac  0f8a1d000000             jp        0x429fcf
00429fb2  761b                     jbe       0x429fcf
00429fb4  ddd8                     fstp      st(0)
00429fb6  833d04f3f20000           cmp       dword ptr [0xf2f304], 0
00429fbd  750a                     jne       0x429fc9
00429fbf  c70504f3f20001000000     mov       dword ptr [0xf2f304], 1
00429fc9  d9058c9d5600             fld       dword ptr [0x569d8c] ; bits=08accc3f, f32=1.5989999771118164
00429fcf  8d15009e5600             lea       edx, [0x569e00] ; bits=72726f72, f32=4.7427374873930615e+30
00429fd5  d85290                   fcom      dword ptr [edx - 0x70]
00429fd8  dfe0                     fnstsw    ax
00429fda  9e                       sahf
00429fdb  0f8a09000000             jp        0x429fea
00429fe1  7307                     jae       0x429fea
00429fe3  ddd8                     fstp      st(0)
00429fe5  d942c0                   fld       dword ptr [edx - 0x40]
00429fe8  eb1a                     jmp       0x42a004
00429fea  89d0                     mov       eax, edx
00429fec  d9c0                     fld       st(0)
00429fee  d848cc                   fmul      dword ptr [eax - 0x34]
00429ff1  89d0                     mov       eax, edx
00429ff3  d840d8                   fadd      dword ptr [eax - 0x28]
00429ff6  d8c9                     fmul      st(1)
00429ff8  89d0                     mov       eax, edx
00429ffa  d840c8                   fadd      dword ptr [eax - 0x38]
00429ffd  dec9                     fmulp     st(1)
00429fff  89d0                     mov       eax, edx
0042a001  d840c4                   fadd      dword ptr [eax - 0x3c]
0042a004  d905f8f2f200             fld       dword ptr [0xf2f2f8]
0042a00a  d80d00f3f200             fmul      dword ptr [0xf2f300]
0042a010  dec9                     fmulp     st(1)
0042a012  eb48                     jmp       0x42a05c
0042a014  8d32                     lea       esi, [edx]
0042a016  8d1d009e5600             lea       ebx, [0x569e00] ; bits=72726f72, f32=4.7427374873930615e+30
0042a01c  8d7b30                   lea       edi, [ebx + 0x30]
0042a01f  b908000000               mov       ecx, 8
0042a024  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0042a026  7505                     jne       0x42a02d
0042a028  d943bc                   fld       dword ptr [ebx - 0x44]
0042a02b  eb2f                     jmp       0x42a05c
0042a02d  8b45f8                   mov       eax, dword ptr [ebp - 8]
0042a030  8b08                     mov       ecx, dword ptr [eax]
0042a032  89d8                     mov       eax, ebx
0042a034  8d4044                   lea       eax, [eax + 0x44]
0042a037  894dfc                   mov       dword ptr [ebp - 4], ecx
0042a03a  8d4dfc                   lea       ecx, [ebp - 4]
0042a03d  894808                   mov       dword ptr [eax + 8], ecx
0042a040  8d0a                     lea       ecx, [edx]
0042a042  894828                   mov       dword ptr [eax + 0x28], ecx
0042a045  50                       push      eax
0042a046  e8a5850700               call      0x4a25f0 ; _jwe_isfm
0042a04b  83c404                   add       esp, 4
0042a04e  89d8                     mov       eax, ebx
0042a050  8d4038                   lea       eax, [eax + 0x38]
0042a053  50                       push      eax
0042a054  e8e7930700               call      0x4a3440 ; _jwe_xstp
0042a059  83c404                   add       esp, 4
0042a05c  d905d09d5600             fld       dword ptr [0x569dd0] ; bits=48e17a3f, f32=0.9800000190734863
0042a062  d9c9                     fxch      st(1)
0042a064  d815d09d5600             fcom      dword ptr [0x569dd0] ; bits=48e17a3f, f32=0.9800000190734863
0042a06a  d9c9                     fxch      st(1)
0042a06c  dfe0                     fnstsw    ax
0042a06e  9e                       sahf
0042a06f  0f8a06000000             jp        0x42a07b
0042a075  7604                     jbe       0x42a07b
0042a077  ddd9                     fstp      st(1)
0042a079  eb02                     jmp       0x42a07d
0042a07b  ddd8                     fstp      st(0)
0042a07d  5f                       pop       edi
0042a07e  5e                       pop       esi
0042a07f  5b                       pop       ebx
0042a080  8be5                     mov       esp, ebp
0042a082  5d                       pop       ebp
0042a083  c3                       ret
0042a084  0500000000               add       eax, 0
0042a089  8da42400000000           lea       esp, [esp]
