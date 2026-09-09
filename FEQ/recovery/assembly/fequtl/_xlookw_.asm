; _xlookw_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x775b0
004775b0  55                       push      ebp
004775b1  8bec                     mov       ebp, esp
004775b3  b858000000               mov       eax, 0x58
004775b8  e8431a0700               call      0x4e9000 ; __alloca_probe
004775bd  53                       push      ebx
004775be  56                       push      esi
004775bf  57                       push      edi
004775c0  8b4508                   mov       eax, dword ptr [ebp + 8]
004775c3  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
004775c6  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
004775c9  8945b8                   mov       dword ptr [ebp - 0x48], eax
004775cc  894db4                   mov       dword ptr [ebp - 0x4c], ecx
004775cf  8b45b4                   mov       eax, dword ptr [ebp - 0x4c]
004775d2  8b55b8                   mov       edx, dword ptr [ebp - 0x48]
004775d5  d900                     fld       dword ptr [eax]
004775d7  8b32                     mov       esi, dword ptr [edx]
004775d9  8b3cb5c0e5f400           mov       edi, dword ptr [esi*4 + 0xf4e5c0]
004775e0  8d4620                   lea       eax, [esi + 0x20]
004775e3  8b0cb5cce5f400           mov       ecx, dword ptr [esi*4 + 0xf4e5cc]
004775ea  8b75b4                   mov       esi, dword ptr [ebp - 0x4c]
004775ed  d9048dc0e5f400           fld       dword ptr [ecx*4 + 0xf4e5c0]
004775f4  d82e                     fsubr     dword ptr [esi]
004775f6  d9ee                     fldz
004775f8  d9c9                     fxch      st(1)
004775fa  d81510185a00             fcom      dword ptr [0x5a1810] ; bits=00000000, f32=0.0
00477600  d9ca                     fxch      st(2)
00477602  db7dec                   fstp      xword ptr [ebp - 0x14]
00477605  d9c9                     fxch      st(1)
00477607  8945b0                   mov       dword ptr [ebp - 0x50], eax
0047760a  dfe0                     fnstsw    ax
0047760c  9e                       sahf
0047760d  897dac                   mov       dword ptr [ebp - 0x54], edi
00477610  0f8a06000000             jp        0x47761c
00477616  0f879f000000             ja        0x4776bb
0047761c  dae9                     fucompp
0047761e  dfe0                     fnstsw    ax
00477620  9e                       sahf
00477621  0f8a06000000             jp        0x47762d
00477627  0f8451010000             je        0x47777e
0047762d  db6dec                   fld       xword ptr [ebp - 0x14]
00477630  8b45b0                   mov       eax, dword ptr [ebp - 0x50]
00477633  39c1                     cmp       ecx, eax
00477635  7d67                     jge       0x47769e
00477637  8b45b8                   mov       eax, dword ptr [ebp - 0x48]
0047763a  db7dec                   fstp      xword ptr [ebp - 0x14]
0047763d  8b10                     mov       edx, dword ptr [eax]
0047763f  8d1495c4e5f400           lea       edx, [edx*4 + 0xf4e5c4]
00477646  52                       push      edx
00477647  6a10                     push      0x10
00477649  6890195a00               push      0x5a1990
0047764e  e83dfdffff               call      0x477390 ; _get_tabid_
00477653  83c40c                   add       esp, 0xc
00477656  8b45b8                   mov       eax, dword ptr [ebp - 0x48]
00477659  8b10                     mov       edx, dword ptr [eax]
0047765b  8b1495d0e5f400           mov       edx, dword ptr [edx*4 + 0xf4e5d0]
00477662  8d3528195a00             lea       esi, [0x5a1928] ; bits=09020000, f32=7.300764999132297e-43
00477668  8955fc                   mov       dword ptr [ebp - 4], edx
0047766b  8d55fc                   lea       edx, [ebp - 4]
0047766e  895634                   mov       dword ptr [esi + 0x34], edx
00477671  db6dec                   fld       xword ptr [ebp - 0x14]
00477674  d95df8                   fstp      dword ptr [ebp - 8]
00477677  8d55f8                   lea       edx, [ebp - 8]
0047767a  895640                   mov       dword ptr [esi + 0x40], edx
0047767d  56                       push      esi
0047767e  e86daf0200               call      0x4a25f0 ; _jwe_isfm
00477683  83c404                   add       esp, 4
00477686  8b45b0                   mov       eax, dword ptr [ebp - 0x50]
00477689  89c1                     mov       ecx, eax
0047768b  8b13                     mov       edx, dword ptr [ebx]
0047768d  01c2                     add       edx, eax
0047768f  d90495c0e5f400           fld       dword ptr [edx*4 + 0xf4e5c0]
00477696  db7dec                   fstp      xword ptr [ebp - 0x14]
00477699  e9e0000000               jmp       0x47777e
0047769e  d8148dc0e5f400           fcom      dword ptr [ecx*4 + 0xf4e5c0]
004776a5  dfe0                     fnstsw    ax
004776a7  9e                       sahf
004776a8  0f8a06000000             jp        0x4776b4
004776ae  0f83c7000000             jae       0x47777b
004776b4  2b0b                     sub       ecx, dword ptr [ebx]
004776b6  e975ffffff               jmp       0x477630
004776bb  ddd8                     fstp      st(0)
004776bd  ddd8                     fstp      st(0)
004776bf  db6dec                   fld       xword ptr [ebp - 0x14]
004776c2  8b45ac                   mov       eax, dword ptr [ebp - 0x54]
004776c5  39c1                     cmp       ecx, eax
004776c7  0f8c8a000000             jl        0x477757
004776cd  db7dec                   fstp      xword ptr [ebp - 0x14]
004776d0  8b45ac                   mov       eax, dword ptr [ebp - 0x54]
004776d3  db6dec                   fld       xword ptr [ebp - 0x14]
004776d6  d82485c0e5f400           fsub      dword ptr [eax*4 + 0xf4e5c0]
004776dd  d9e1                     fabs
004776df  8d0d90185a00             lea       ecx, [0x5a1890] ; bits=70170000, f32=8.407790785948902e-42
004776e5  d85988                   fcomp     dword ptr [ecx - 0x78]
004776e8  dfe0                     fnstsw    ax
004776ea  9e                       sahf
004776eb  894da8                   mov       dword ptr [ebp - 0x58], ecx
004776ee  0f8a4e000000             jp        0x477742
004776f4  764c                     jbe       0x477742
004776f6  8b45b8                   mov       eax, dword ptr [ebp - 0x48]
004776f9  8b08                     mov       ecx, dword ptr [eax]
004776fb  8d0c8dc4e5f400           lea       ecx, [ecx*4 + 0xf4e5c4]
00477702  51                       push      ecx
00477703  6a10                     push      0x10
00477705  68a0195a00               push      0x5a19a0
0047770a  e881fcffff               call      0x477390 ; _get_tabid_
0047770f  83c40c                   add       esp, 0xc
00477712  8b45b8                   mov       eax, dword ptr [ebp - 0x48]
00477715  8b08                     mov       ecx, dword ptr [eax]
00477717  8b55a8                   mov       edx, dword ptr [ebp - 0x58]
0047771a  8b0c8dd0e5f400           mov       ecx, dword ptr [ecx*4 + 0xf4e5d0]
00477721  8d7254                   lea       esi, [edx + 0x54]
00477724  894dfc                   mov       dword ptr [ebp - 4], ecx
00477727  8d4dfc                   lea       ecx, [ebp - 4]
0047772a  894e34                   mov       dword ptr [esi + 0x34], ecx
0047772d  db6dec                   fld       xword ptr [ebp - 0x14]
00477730  d95df8                   fstp      dword ptr [ebp - 8]
00477733  8d4df8                   lea       ecx, [ebp - 8]
00477736  894e40                   mov       dword ptr [esi + 0x40], ecx
00477739  56                       push      esi
0047773a  e8b1ae0200               call      0x4a25f0 ; _jwe_isfm
0047773f  83c404                   add       esp, 4
00477742  8b45ac                   mov       eax, dword ptr [ebp - 0x54]
00477745  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
0047774c  db7dec                   fstp      xword ptr [ebp - 0x14]
0047774f  8b13                     mov       edx, dword ptr [ebx]
00477751  29d0                     sub       eax, edx
00477753  89c1                     mov       ecx, eax
00477755  eb27                     jmp       0x47777e
00477757  8b03                     mov       eax, dword ptr [ebx]
00477759  01c8                     add       eax, ecx
0047775b  89c2                     mov       edx, eax
0047775d  d81495c0e5f400           fcom      dword ptr [edx*4 + 0xf4e5c0]
00477764  dfe0                     fnstsw    ax
00477766  9e                       sahf
00477767  0f8a02000000             jp        0x47776f
0047776d  7607                     jbe       0x477776
0047776f  89d1                     mov       ecx, edx
00477771  e94cffffff               jmp       0x4776c2
00477776  db7dec                   fstp      xword ptr [ebp - 0x14]
00477779  eb03                     jmp       0x47777e
0047777b  db7dec                   fstp      xword ptr [ebp - 0x14]
0047777e  d9048dc0e5f400           fld       dword ptr [ecx*4 + 0xf4e5c0]
00477785  d9048dc4e5f400           fld       dword ptr [ecx*4 + 0xf4e5c4]
0047778c  d9048dc8e5f400           fld       dword ptr [ecx*4 + 0xf4e5c8]
00477793  d9048dcce5f400           fld       dword ptr [ecx*4 + 0xf4e5cc]
0047779a  d9048dd0e5f400           fld       dword ptr [ecx*4 + 0xf4e5d0]
004777a1  db7de0                   fstp      xword ptr [ebp - 0x20]
004777a4  8b13                     mov       edx, dword ptr [ebx]
004777a6  01ca                     add       edx, ecx
004777a8  d9c3                     fld       st(3)
004777aa  d82c95c0e5f400           fsubr     dword ptr [edx*4 + 0xf4e5c0]
004777b1  db6dec                   fld       xword ptr [ebp - 0x14]
004777b4  dee5                     fsubrp    st(5)
004777b6  d9c3                     fld       st(3)
004777b8  d82c95c4e5f400           fsubr     dword ptr [edx*4 + 0xf4e5c4]
004777bf  d9c5                     fld       st(5)
004777c1  d8f2                     fdiv      st(2)
004777c3  d8c9                     fmul      st(1)
004777c5  d8c5                     fadd      st(5)
004777c7  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004777ca  d910                     fst       dword ptr [eax]
004777cc  d9c9                     fxch      st(1)
004777ce  def2                     fdivrp    st(2)
004777d0  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004777d3  d9c9                     fxch      st(1)
004777d5  d918                     fstp      dword ptr [eax]
004777d7  d9c4                     fld       st(4)
004777d9  d80d1c185a00             fmul      dword ptr [0x5a181c] ; bits=0000003f, f32=0.5
004777df  d9cc                     fxch      st(4)
004777e1  d8c1                     fadd      st(1)
004777e3  decc                     fmulp     st(4)
004777e5  d9cb                     fxch      st(3)
004777e7  dec2                     faddp     st(2)
004777e9  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004777ec  d9c9                     fxch      st(1)
004777ee  d910                     fst       dword ptr [eax]
004777f0  d9ee                     fldz
004777f2  db6dec                   fld       xword ptr [ebp - 0x14]
004777f5  dae9                     fucompp
004777f7  d9ca                     fxch      st(2)
004777f9  db7dd4                   fstp      xword ptr [ebp - 0x2c]
004777fc  d9c9                     fxch      st(1)
004777fe  db7dc8                   fstp      xword ptr [ebp - 0x38]
00477801  d9c9                     fxch      st(1)
00477803  db7dbc                   fstp      xword ptr [ebp - 0x44]
00477806  dfe0                     fnstsw    ax
00477808  9e                       sahf
00477809  0f8a18000000             jp        0x477827
0047780f  7516                     jne       0x477827
00477811  ddd8                     fstp      st(0)
00477813  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00477816  c70000000000             mov       dword ptr [eax], 0
0047781c  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0047781f  c70000000000             mov       dword ptr [eax], 0
00477825  eb3a                     jmp       0x477861
00477827  d90530bcf400             fld       dword ptr [0xf4bc30] ; _grvcom_
0047782d  db6dc8                   fld       xword ptr [ebp - 0x38]
00477830  d80d30bcf400             fmul      dword ptr [0xf4bc30] ; _grvcom_
00477836  db6dd4                   fld       xword ptr [ebp - 0x2c]
00477839  def9                     fdivp     st(1)
0047783b  d9fa                     fsqrt
0047783d  d95dfc                   fstp      dword ptr [ebp - 4]
00477840  d945fc                   fld       dword ptr [ebp - 4]
00477843  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00477846  d910                     fst       dword ptr [eax]
00477848  d9c9                     fxch      st(1)
0047784a  d8c0                     fadd      st(0)
0047784c  db6dbc                   fld       xword ptr [ebp - 0x44]
0047784f  dec9                     fmulp     st(1)
00477851  d9c9                     fxch      st(1)
00477853  dec2                     faddp     st(2)
00477855  def1                     fdivrp    st(1)
00477857  db6de0                   fld       xword ptr [ebp - 0x20]
0047785a  dec1                     faddp     st(1)
0047785c  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0047785f  d918                     fstp      dword ptr [eax]
00477861  8b45b8                   mov       eax, dword ptr [ebp - 0x48]
00477864  8b10                     mov       edx, dword ptr [eax]
00477866  890c95cce5f400           mov       dword ptr [edx*4 + 0xf4e5cc], ecx
0047786d  b800000000               mov       eax, 0
00477872  5f                       pop       edi
00477873  5e                       pop       esi
00477874  5b                       pop       ebx
00477875  8be5                     mov       esp, ebp
00477877  5d                       pop       ebp
00477878  c3                       ret
00477879  8da42400000000           lea       esp, [esp]
