; _lktj_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x78260
00478260  55                       push      ebp
00478261  8bec                     mov       ebp, esp
00478263  b844000000               mov       eax, 0x44
00478268  e8930d0700               call      0x4e9000 ; __alloca_probe
0047826d  53                       push      ebx
0047826e  56                       push      esi
0047826f  57                       push      edi
00478270  8b4508                   mov       eax, dword ptr [ebp + 8]
00478273  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00478276  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00478279  8945dc                   mov       dword ptr [ebp - 0x24], eax
0047827c  894dd8                   mov       dword ptr [ebp - 0x28], ecx
0047827f  8955d4                   mov       dword ptr [ebp - 0x2c], edx
00478282  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00478285  d900                     fld       dword ptr [eax]
00478287  8b75dc                   mov       esi, dword ptr [ebp - 0x24]
0047828a  8b16                     mov       edx, dword ptr [esi]
0047828c  8b3c95c0e5f400           mov       edi, dword ptr [edx*4 + 0xf4e5c0]
00478293  8d4220                   lea       eax, [edx + 0x20]
00478296  8b0c95cce5f400           mov       ecx, dword ptr [edx*4 + 0xf4e5cc]
0047829d  8b3495c8e5f400           mov       esi, dword ptr [edx*4 + 0xf4e5c8]
004782a4  8b1cb5445b5700           mov       ebx, dword ptr [esi*4 + 0x575b44]
004782ab  833cb5bc255a0000         cmp       dword ptr [esi*4 + 0x5a25bc], 0
004782b3  8945d0                   mov       dword ptr [ebp - 0x30], eax
004782b6  897dcc                   mov       dword ptr [ebp - 0x34], edi
004782b9  7529                     jne       0x4782e4
004782bb  ddd8                     fstp      st(0)
004782bd  8d0495c4e5f400           lea       eax, [edx*4 + 0xf4e5c4]
004782c4  50                       push      eax
004782c5  68c0255a00               push      0x5a25c0
004782ca  686095b700               push      0xb79560
004782cf  e8ac42fdff               call      0x44c580 ; _xstype_
004782d4  83c40c                   add       esp, 0xc
004782d7  68cc245a00               push      0x5a24cc
004782dc  e85fb10200               call      0x4a3440 ; _jwe_xstp
004782e1  83c404                   add       esp, 4
004782e4  d8148dc0e5f400           fcom      dword ptr [ecx*4 + 0xf4e5c0]
004782eb  dfe0                     fnstsw    ax
004782ed  9e                       sahf
004782ee  0f8ac6000000             jp        0x4783ba
004782f4  0f82c0000000             jb        0x4783ba
004782fa  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
004782fd  d81485c0e5f400           fcom      dword ptr [eax*4 + 0xf4e5c0]
00478304  dfe0                     fnstsw    ax
00478306  9e                       sahf
00478307  0f8a8e000000             jp        0x47839b
0047830d  0f8688000000             jbe       0x47839b
00478313  db7de0                   fstp      xword ptr [ebp - 0x20]
00478316  8d0495c4e5f400           lea       eax, [edx*4 + 0xf4e5c4]
0047831d  50                       push      eax
0047831e  6a10                     push      0x10
00478320  68a0255a00               push      0x5a25a0
00478325  e866f0ffff               call      0x477390 ; _get_tabid_
0047832a  83c40c                   add       esp, 0xc
0047832d  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
00478330  8b30                     mov       esi, dword ptr [eax]
00478332  8b34b5d0e5f400           mov       esi, dword ptr [esi*4 + 0xf4e5d0]
00478339  8b3d4095b700             mov       edi, dword ptr [0xb79540] ; _xscom_
0047833f  8b054495b700             mov       eax, dword ptr [0xb79544]
00478345  8975c8                   mov       dword ptr [ebp - 0x38], esi
00478348  8d3528255a00             lea       esi, [0x5a2528] ; bits=09020000, f32=7.300764999132297e-43
0047834e  897dc4                   mov       dword ptr [ebp - 0x3c], edi
00478351  8b7dc8                   mov       edi, dword ptr [ebp - 0x38]
00478354  897dfc                   mov       dword ptr [ebp - 4], edi
00478357  8d7dfc                   lea       edi, [ebp - 4]
0047835a  897e34                   mov       dword ptr [esi + 0x34], edi
0047835d  8b7dc4                   mov       edi, dword ptr [ebp - 0x3c]
00478360  897df0                   mov       dword ptr [ebp - 0x10], edi
00478363  8945f4                   mov       dword ptr [ebp - 0xc], eax
00478366  8d45f0                   lea       eax, [ebp - 0x10]
00478369  894640                   mov       dword ptr [esi + 0x40], eax
0047836c  db6de0                   fld       xword ptr [ebp - 0x20]
0047836f  d95dec                   fstp      dword ptr [ebp - 0x14]
00478372  8d45ec                   lea       eax, [ebp - 0x14]
00478375  89464c                   mov       dword ptr [esi + 0x4c], eax
00478378  56                       push      esi
00478379  e872a20200               call      0x4a25f0 ; _jwe_isfm
0047837e  83c404                   add       esp, 4
00478381  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
00478384  89c6                     mov       esi, eax
00478386  29de                     sub       esi, ebx
00478388  89f1                     mov       ecx, esi
0047838a  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
00478391  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00478394  d910                     fst       dword ptr [eax]
00478396  e9d0000000               jmp       0x47846b
0047839b  8d140b                   lea       edx, [ebx + ecx]
0047839e  d81495c0e5f400           fcom      dword ptr [edx*4 + 0xf4e5c0]
004783a5  dfe0                     fnstsw    ax
004783a7  9e                       sahf
004783a8  0f8abd000000             jp        0x47846b
004783ae  0f86b7000000             jbe       0x47846b
004783b4  01d9                     add       ecx, ebx
004783b6  01da                     add       edx, ebx
004783b8  ebe4                     jmp       0x47839e
004783ba  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
004783bd  d81485c0e5f400           fcom      dword ptr [eax*4 + 0xf4e5c0]
004783c4  dfe0                     fnstsw    ax
004783c6  9e                       sahf
004783c7  0f8a8a000000             jp        0x478457
004783cd  0f8384000000             jae       0x478457
004783d3  db7de0                   fstp      xword ptr [ebp - 0x20]
004783d6  8d0495c4e5f400           lea       eax, [edx*4 + 0xf4e5c4]
004783dd  50                       push      eax
004783de  6a10                     push      0x10
004783e0  68b0255a00               push      0x5a25b0
004783e5  e8a6efffff               call      0x477390 ; _get_tabid_
004783ea  83c40c                   add       esp, 0xc
004783ed  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
004783f0  8b30                     mov       esi, dword ptr [eax]
004783f2  8b34b5d0e5f400           mov       esi, dword ptr [esi*4 + 0xf4e5d0]
004783f9  8b3d4095b700             mov       edi, dword ptr [0xb79540] ; _xscom_
004783ff  8b054495b700             mov       eax, dword ptr [0xb79544]
00478405  8975c0                   mov       dword ptr [ebp - 0x40], esi
00478408  8d35d8245a00             lea       esi, [0x5a24d8] ; bits=09020000, f32=7.300764999132297e-43
0047840e  897dbc                   mov       dword ptr [ebp - 0x44], edi
00478411  8b7dc0                   mov       edi, dword ptr [ebp - 0x40]
00478414  897dfc                   mov       dword ptr [ebp - 4], edi
00478417  8d7dfc                   lea       edi, [ebp - 4]
0047841a  897e34                   mov       dword ptr [esi + 0x34], edi
0047841d  8b7dbc                   mov       edi, dword ptr [ebp - 0x44]
00478420  897df0                   mov       dword ptr [ebp - 0x10], edi
00478423  8945f4                   mov       dword ptr [ebp - 0xc], eax
00478426  8d45f0                   lea       eax, [ebp - 0x10]
00478429  894640                   mov       dword ptr [esi + 0x40], eax
0047842c  db6de0                   fld       xword ptr [ebp - 0x20]
0047842f  d95dec                   fstp      dword ptr [ebp - 0x14]
00478432  8d45ec                   lea       eax, [ebp - 0x14]
00478435  89464c                   mov       dword ptr [esi + 0x4c], eax
00478438  56                       push      esi
00478439  e8b2a10200               call      0x4a25f0 ; _jwe_isfm
0047843e  83c404                   add       esp, 4
00478441  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
00478444  89c1                     mov       ecx, eax
00478446  8d3403                   lea       esi, [ebx + eax]
00478449  d904b5c0e5f400           fld       dword ptr [esi*4 + 0xf4e5c0]
00478450  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00478453  d910                     fst       dword ptr [eax]
00478455  eb14                     jmp       0x47846b
00478457  29d9                     sub       ecx, ebx
00478459  d8148dc0e5f400           fcom      dword ptr [ecx*4 + 0xf4e5c0]
00478460  dfe0                     fnstsw    ax
00478462  9e                       sahf
00478463  0f8a02000000             jp        0x47846b
00478469  72ec                     jb        0x478457
0047846b  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
0047846e  8b10                     mov       edx, dword ptr [eax]
00478470  890c95cce5f400           mov       dword ptr [edx*4 + 0xf4e5cc], ecx
00478477  89d8                     mov       eax, ebx
00478479  01c8                     add       eax, ecx
0047847b  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
00478482  d8248dc0e5f400           fsub      dword ptr [ecx*4 + 0xf4e5c0]
00478489  d9c9                     fxch      st(1)
0047848b  d8248dc0e5f400           fsub      dword ptr [ecx*4 + 0xf4e5c0]
00478492  8d1560245a00             lea       edx, [0x5a2460] ; bits=80000000, f32=1.793662034335766e-43
00478498  d9c0                     fld       st(0)
0047849a  d84a84                   fmul      dword ptr [edx - 0x7c]
0047849d  d90485c4e5f400           fld       dword ptr [eax*4 + 0xf4e5c4]
004784a4  d8248dc4e5f400           fsub      dword ptr [ecx*4 + 0xf4e5c4]
004784ab  def3                     fdivrp    st(3)
004784ad  d9ca                     fxch      st(2)
004784af  d8c9                     fmul      st(1)
004784b1  d8048dc4e5f400           fadd      dword ptr [ecx*4 + 0xf4e5c4]
004784b8  d9c0                     fld       st(0)
004784ba  d8048dc4e5f400           fadd      dword ptr [ecx*4 + 0xf4e5c4]
004784c1  d8cb                     fmul      st(3)
004784c3  d8048dc8e5f400           fadd      dword ptr [ecx*4 + 0xf4e5c8]
004784ca  d8048dc8e5f400           fadd      dword ptr [ecx*4 + 0xf4e5c8]
004784d1  d9c9                     fxch      st(1)
004784d3  d8248dc4e5f400           fsub      dword ptr [ecx*4 + 0xf4e5c4]
004784da  deca                     fmulp     st(2)
004784dc  d9c9                     fxch      st(1)
004784de  d84a80                   fmul      dword ptr [edx - 0x80]
004784e1  dee9                     fsubp     st(1)
004784e3  dec9                     fmulp     st(1)
004784e5  d8048dd4e5f400           fadd      dword ptr [ecx*4 + 0xf4e5d4]
004784ec  8b45d4                   mov       eax, dword ptr [ebp - 0x2c]
004784ef  d918                     fstp      dword ptr [eax]
004784f1  b800000000               mov       eax, 0
004784f6  5f                       pop       edi
004784f7  5e                       pop       esi
004784f8  5b                       pop       ebx
004784f9  8be5                     mov       esp, ebp
004784fb  5d                       pop       ebp
004784fc  c3                       ret
004784fd  8d4900                   lea       ecx, [ecx]
