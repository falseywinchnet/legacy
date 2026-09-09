; _lktab_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x35d40
00435d40  83ec28                   sub       esp, 0x28
00435d43  53                       push      ebx
00435d44  56                       push      esi
00435d45  57                       push      edi
00435d46  8b442438                 mov       eax, dword ptr [esp + 0x38]
00435d4a  8b4c243c                 mov       ecx, dword ptr [esp + 0x3c]
00435d4e  8b542440                 mov       edx, dword ptr [esp + 0x40]
00435d52  89442420                 mov       dword ptr [esp + 0x20], eax
00435d56  894c241c                 mov       dword ptr [esp + 0x1c], ecx
00435d5a  89542418                 mov       dword ptr [esp + 0x18], edx
00435d5e  8b442420                 mov       eax, dword ptr [esp + 0x20]
00435d62  8b10                     mov       edx, dword ptr [eax]
00435d64  8b1c95602e0302           mov       ebx, dword ptr [edx*4 + 0x2032e60]
00435d6b  8d7216                   lea       esi, [edx + 0x16]
00435d6e  8b0c956c2e0302           mov       ecx, dword ptr [edx*4 + 0x2032e6c]
00435d75  8b3c95682e0302           mov       edi, dword ptr [edx*4 + 0x2032e68]
00435d7c  8b1495642e0302           mov       edx, dword ptr [edx*4 + 0x2032e64]
00435d83  8b442448                 mov       eax, dword ptr [esp + 0x48]
00435d87  8910                     mov       dword ptr [eax], edx
00435d89  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
00435d8d  8b10                     mov       edx, dword ptr [eax]
00435d8f  89154c005300             mov       dword ptr [0x53004c], edx ; bits=00000000, f32=0.0
00435d95  83ff04                   cmp       edi, 4
00435d98  895c2414                 mov       dword ptr [esp + 0x14], ebx
00435d9c  89742410                 mov       dword ptr [esp + 0x10], esi
00435da0  897c240c                 mov       dword ptr [esp + 0xc], edi
00435da4  7e07                     jle       0x435dad
00435da6  bb03000000               mov       ebx, 3
00435dab  eb0b                     jmp       0x435db8
00435dad  8b44240c                 mov       eax, dword ptr [esp + 0xc]
00435db1  8b1c85b4005300           mov       ebx, dword ptr [eax*4 + 0x5300b4]
00435db8  837c240c05               cmp       dword ptr [esp + 0xc], 5
00435dbd  751c                     jne       0x435ddb
00435dbf  8b054c005300             mov       eax, dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435dc5  890550005300             mov       dword ptr [0x530050], eax ; bits=00000000, f32=0.0
00435dcb  d9ed                     fldln2
00435dcd  d9054c005300             fld       dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435dd3  d9f1                     fyl2x
00435dd5  d91d4c005300             fstp      dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435ddb  d9054c005300             fld       dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435de1  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
00435de8  d9ee                     fldz
00435dea  dbf1                     fcomi     st(1)
00435dec  d9c9                     fxch      st(1)
00435dee  0f8a06000000             jp        0x435dfa
00435df4  0f82cc000000             jb        0x435ec6
00435dfa  dfe9                     fucompi   st(1)
00435dfc  ddd8                     fstp      st(0)
00435dfe  0f8a06000000             jp        0x435e0a
00435e04  0f8468010000             je        0x435f72
00435e0a  8b442410                 mov       eax, dword ptr [esp + 0x10]
00435e0e  39c1                     cmp       ecx, eax
00435e10  0f8d8c000000             jge       0x435ea2
00435e16  8b442418                 mov       eax, dword ptr [esp + 0x18]
00435e1a  833800                   cmp       dword ptr [eax], 0
00435e1d  7414                     je        0x435e33
00435e1f  01d9                     add       ecx, ebx
00435e21  8b048d602e0302           mov       eax, dword ptr [ecx*4 + 0x2032e60]
00435e28  89054c005300             mov       dword ptr [0x53004c], eax ; bits=00000000, f32=0.0
00435e2e  e93f010000               jmp       0x435f72
00435e33  8b442420                 mov       eax, dword ptr [esp + 0x20]
00435e37  8b08                     mov       ecx, dword ptr [eax]
00435e39  8d0c8d642e0302           lea       ecx, [ecx*4 + 0x2032e64]
00435e40  51                       push      ecx
00435e41  6a10                     push      0x10
00435e43  6888005300               push      0x530088
00435e48  e823550600               call      0x49b370 ; _get_tabid_
00435e4d  83c40c                   add       esp, 0xc
00435e50  8b05a00e6c01             mov       eax, dword ptr [0x16c0ea0] ; _xscom_
00435e56  8b0da40e6c01             mov       ecx, dword ptr [0x16c0ea4]
00435e5c  8b154c005300             mov       edx, dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435e62  8d1df0ff5200             lea       ebx, [0x52fff0] ; bits=09020000, f32=7.300764999132297e-43
00435e68  8944242c                 mov       dword ptr [esp + 0x2c], eax
00435e6c  894c2430                 mov       dword ptr [esp + 0x30], ecx
00435e70  8d44242c                 lea       eax, [esp + 0x2c]
00435e74  894334                   mov       dword ptr [ebx + 0x34], eax
00435e77  89542428                 mov       dword ptr [esp + 0x28], edx
00435e7b  8d442428                 lea       eax, [esp + 0x28]
00435e7f  894340                   mov       dword ptr [ebx + 0x40], eax
00435e82  53                       push      ebx
00435e83  e8386d0800               call      0x4bcbc0 ; _jwe_isfm
00435e88  83c404                   add       esp, 4
00435e8b  c705a80e6c0101000000     mov       dword ptr [0x16c0ea8], 1
00435e95  6868ff5200               push      0x52ff68
00435e9a  e8b1750800               call      0x4bd450 ; _jwe_xstp
00435e9f  83c404                   add       esp, 4
00435ea2  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
00435ea9  d9054c005300             fld       dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435eaf  dff1                     fcompi    st(1)
00435eb1  ddd8                     fstp      st(0)
00435eb3  0f8a06000000             jp        0x435ebf
00435eb9  0f83b3000000             jae       0x435f72
00435ebf  29d9                     sub       ecx, ebx
00435ec1  e944ffffff               jmp       0x435e0a
00435ec6  ddd8                     fstp      st(0)
00435ec8  ddd8                     fstp      st(0)
00435eca  8d1419                   lea       edx, [ecx + ebx]
00435ecd  8b442414                 mov       eax, dword ptr [esp + 0x14]
00435ed1  39c1                     cmp       ecx, eax
00435ed3  7c7b                     jl        0x435f50
00435ed5  8b442420                 mov       eax, dword ptr [esp + 0x20]
00435ed9  8b10                     mov       edx, dword ptr [eax]
00435edb  8d1495642e0302           lea       edx, [edx*4 + 0x2032e64]
00435ee2  52                       push      edx
00435ee3  6a10                     push      0x10
00435ee5  6898005300               push      0x530098
00435eea  e881540600               call      0x49b370 ; _get_tabid_
00435eef  83c40c                   add       esp, 0xc
00435ef2  8b05a00e6c01             mov       eax, dword ptr [0x16c0ea0] ; _xscom_
00435ef8  8b15a40e6c01             mov       edx, dword ptr [0x16c0ea4]
00435efe  8b354c005300             mov       esi, dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435f04  8d3dacff5200             lea       edi, [0x52ffac] ; bits=09020000, f32=7.300764999132297e-43
00435f0a  8944242c                 mov       dword ptr [esp + 0x2c], eax
00435f0e  89542430                 mov       dword ptr [esp + 0x30], edx
00435f12  8d44242c                 lea       eax, [esp + 0x2c]
00435f16  894734                   mov       dword ptr [edi + 0x34], eax
00435f19  89742428                 mov       dword ptr [esp + 0x28], esi
00435f1d  8d442428                 lea       eax, [esp + 0x28]
00435f21  894740                   mov       dword ptr [edi + 0x40], eax
00435f24  57                       push      edi
00435f25  e8966c0800               call      0x4bcbc0 ; _jwe_isfm
00435f2a  83c404                   add       esp, 4
00435f2d  c705a80e6c0101000000     mov       dword ptr [0x16c0ea8], 1
00435f37  8b442414                 mov       eax, dword ptr [esp + 0x14]
00435f3b  89c2                     mov       edx, eax
00435f3d  29da                     sub       edx, ebx
00435f3f  89d1                     mov       ecx, edx
00435f41  8b1485602e0302           mov       edx, dword ptr [eax*4 + 0x2032e60]
00435f48  89154c005300             mov       dword ptr [0x53004c], edx ; bits=00000000, f32=0.0
00435f4e  eb22                     jmp       0x435f72
00435f50  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
00435f57  d9054c005300             fld       dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435f5d  dff1                     fcompi    st(1)
00435f5f  ddd8                     fstp      st(0)
00435f61  0f8a02000000             jp        0x435f69
00435f67  7609                     jbe       0x435f72
00435f69  01d9                     add       ecx, ebx
00435f6b  01da                     add       edx, ebx
00435f6d  e95bffffff               jmp       0x435ecd
00435f72  837c240c0c               cmp       dword ptr [esp + 0xc], 0xc
00435f77  730d                     jae       0x435f86
00435f79  8b44240c                 mov       eax, dword ptr [esp + 0xc]
00435f7d  8b148500025300           mov       edx, dword ptr [eax*4 + 0x530200]
00435f84  ffe2                     jmp       edx
00435f86  8b442448                 mov       eax, dword ptr [esp + 0x48]
00435f8a  8d00                     lea       eax, [eax]
00435f8c  50                       push      eax
00435f8d  6a10                     push      0x10
00435f8f  68a8005300               push      0x5300a8
00435f94  e8d7530600               call      0x49b370 ; _get_tabid_
00435f99  83c40c                   add       esp, 0xc
00435f9c  8d0574ff5200             lea       eax, [0x52ff74] ; bits=09020000, f32=7.300764999132297e-43
00435fa2  8b4c240c                 mov       ecx, dword ptr [esp + 0xc]
00435fa6  894c2424                 mov       dword ptr [esp + 0x24], ecx
00435faa  8d4c2424                 lea       ecx, [esp + 0x24]
00435fae  894828                   mov       dword ptr [eax + 0x28], ecx
00435fb1  50                       push      eax
00435fb2  e8096c0800               call      0x4bcbc0 ; _jwe_isfm
00435fb7  83c404                   add       esp, 4
00435fba  685cff5200               push      0x52ff5c
00435fbf  e88c740800               call      0x4bd450 ; _jwe_xstp
00435fc4  83c404                   add       esp, 4
00435fc7  d9048d682e0302           fld       dword ptr [ecx*4 + 0x2032e68]
00435fce  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
00435fd5  d9054c005300             fld       dword ptr [0x53004c] ; bits=00000000, f32=0.0
00435fdb  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
00435fe2  d9ca                     fxch      st(2)
00435fe4  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
00435feb  dcfa                     fdiv      st(2), st(0)
00435fed  d9c9                     fxch      st(1)
00435fef  d8248d642e0302           fsub      dword ptr [ecx*4 + 0x2032e64]
00435ff6  dcca                     fmul      st(2), st(0)
00435ff8  d9ca                     fxch      st(2)
00435ffa  d8048d642e0302           fadd      dword ptr [ecx*4 + 0x2032e64]
00436001  8b442444                 mov       eax, dword ptr [esp + 0x44]
00436005  d918                     fstp      dword ptr [eax]
00436007  def9                     fdivp     st(1)
00436009  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
0043600d  d918                     fstp      dword ptr [eax]
0043600f  e97f010000               jmp       0x436193
00436014  d9048d642e0302           fld       dword ptr [ecx*4 + 0x2032e64]
0043601b  d9048d682e0302           fld       dword ptr [ecx*4 + 0x2032e68]
00436022  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
00436029  d9048d742e0302           fld       dword ptr [ecx*4 + 0x2032e74]
00436030  d9054c005300             fld       dword ptr [0x53004c] ; bits=00000000, f32=0.0
00436036  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
0043603d  d9ca                     fxch      st(2)
0043603f  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
00436046  d8fa                     fdivr     st(2)
00436048  d9c9                     fxch      st(1)
0043604a  d8248d682e0302           fsub      dword ptr [ecx*4 + 0x2032e68]
00436051  dec9                     fmulp     st(1)
00436053  d8048d682e0302           fadd      dword ptr [ecx*4 + 0x2032e68]
0043605a  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
0043605e  d910                     fst       dword ptr [eax]
00436060  d9c9                     fxch      st(1)
00436062  d80d68fe5200             fmul      dword ptr [0x52fe68] ; bits=0000003f, f32=0.5
00436068  d9c9                     fxch      st(1)
0043606a  dec2                     faddp     st(2)
0043606c  dec9                     fmulp     st(1)
0043606e  dec1                     faddp     st(1)
00436070  8b442444                 mov       eax, dword ptr [esp + 0x44]
00436074  d918                     fstp      dword ptr [eax]
00436076  e918010000               jmp       0x436193
0043607b  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
00436082  d9048d702e0302           fld       dword ptr [ecx*4 + 0x2032e70]
00436089  d9054c005300             fld       dword ptr [0x53004c] ; bits=00000000, f32=0.0
0043608f  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
00436096  d9ca                     fxch      st(2)
00436098  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
0043609f  d9c2                     fld       st(2)
004360a1  d8f1                     fdiv      st(1)
004360a3  d9ca                     fxch      st(2)
004360a5  d8248d642e0302           fsub      dword ptr [ecx*4 + 0x2032e64]
004360ac  d9c0                     fld       st(0)
004360ae  d80d6cfe5200             fmul      dword ptr [0x52fe6c] ; bits=00004040, f32=3.0
004360b4  d9048d682e0302           fld       dword ptr [ecx*4 + 0x2032e68]
004360bb  d8048d682e0302           fadd      dword ptr [ecx*4 + 0x2032e68]
004360c2  d8048d742e0302           fadd      dword ptr [ecx*4 + 0x2032e74]
004360c9  d8cb                     fmul      st(3)
004360cb  dee9                     fsubp     st(1)
004360cd  d9048d682e0302           fld       dword ptr [ecx*4 + 0x2032e68]
004360d4  d8048d742e0302           fadd      dword ptr [ecx*4 + 0x2032e74]
004360db  d8cb                     fmul      st(3)
004360dd  d9ca                     fxch      st(2)
004360df  d8c0                     fadd      st(0)
004360e1  deea                     fsubp     st(2)
004360e3  d9c0                     fld       st(0)
004360e5  d8c0                     fadd      st(0)
004360e7  d9c2                     fld       st(2)
004360e9  d80d6cfe5200             fmul      dword ptr [0x52fe6c] ; bits=00004040, f32=3.0
004360ef  d8cd                     fmul      st(5)
004360f1  dec1                     faddp     st(1)
004360f3  d8cc                     fmul      st(4)
004360f5  def3                     fdivrp    st(3)
004360f7  d9ca                     fxch      st(2)
004360f9  d8048d682e0302           fadd      dword ptr [ecx*4 + 0x2032e68]
00436100  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
00436104  d918                     fstp      dword ptr [eax]
00436106  d9cb                     fxch      st(3)
00436108  d80c8d682e0302           fmul      dword ptr [ecx*4 + 0x2032e68]
0043610f  d8048d642e0302           fadd      dword ptr [ecx*4 + 0x2032e64]
00436116  d9c2                     fld       st(2)
00436118  d8c8                     fmul      st(0)
0043611a  d9cb                     fxch      st(3)
0043611c  decc                     fmulp     st(4)
0043611e  d9cb                     fxch      st(3)
00436120  dec1                     faddp     st(1)
00436122  dec9                     fmulp     st(1)
00436124  dec1                     faddp     st(1)
00436126  8b442444                 mov       eax, dword ptr [esp + 0x44]
0043612a  d918                     fstp      dword ptr [eax]
0043612c  eb65                     jmp       0x436193
0043612e  8b442410                 mov       eax, dword ptr [esp + 0x10]
00436132  39c1                     cmp       ecx, eax
00436134  7509                     jne       0x43613f
00436136  8b442410                 mov       eax, dword ptr [esp + 0x10]
0043613a  83c003                   add       eax, 3
0043613d  89c1                     mov       ecx, eax
0043613f  d9048d682e0302           fld       dword ptr [ecx*4 + 0x2032e68]
00436146  d9054c005300             fld       dword ptr [0x53004c] ; bits=00000000, f32=0.0
0043614c  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
00436153  d80c8d682e0302           fmul      dword ptr [ecx*4 + 0x2032e68]
0043615a  d8048d642e0302           fadd      dword ptr [ecx*4 + 0x2032e64]
00436161  d9ea                     fldl2e
00436163  dec9                     fmulp     st(1)
00436165  d9c0                     fld       st(0)
00436167  d9fc                     frndint
00436169  dce9                     fsub      st(1), st(0)
0043616b  d9c9                     fxch      st(1)
0043616d  d9f0                     f2xm1
0043616f  d9e8                     fld1
00436171  dec1                     faddp     st(1)
00436173  d9fd                     fscale
00436175  ddd9                     fstp      st(1)
00436177  d95c2428                 fstp      dword ptr [esp + 0x28]
0043617b  d9442428                 fld       dword ptr [esp + 0x28]
0043617f  8b442444                 mov       eax, dword ptr [esp + 0x44]
00436183  d910                     fst       dword ptr [eax]
00436185  dec9                     fmulp     st(1)
00436187  d83550005300             fdiv      dword ptr [0x530050] ; bits=00000000, f32=0.0
0043618d  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
00436191  d918                     fstp      dword ptr [eax]
00436193  8b442420                 mov       eax, dword ptr [esp + 0x20]
00436197  8b10                     mov       edx, dword ptr [eax]
00436199  890c956c2e0302           mov       dword ptr [edx*4 + 0x2032e6c], ecx
004361a0  b800000000               mov       eax, 0
004361a5  5f                       pop       edi
004361a6  5e                       pop       esi
004361a7  5b                       pop       ebx
004361a8  83c428                   add       esp, 0x28
004361ab  c3                       ret
004361ac  8d642400                 lea       esp, [esp]
