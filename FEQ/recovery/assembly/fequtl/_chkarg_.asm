; _chkarg_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x942c0
004942c0  55                       push      ebp
004942c1  8bec                     mov       ebp, esp
004942c3  b850000000               mov       eax, 0x50
004942c8  e8334d0500               call      0x4e9000 ; __alloca_probe
004942cd  53                       push      ebx
004942ce  56                       push      esi
004942cf  57                       push      edi
004942d0  8b4508                   mov       eax, dword ptr [ebp + 8]
004942d3  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
004942d6  8b5510                   mov       edx, dword ptr [ebp + 0x10]
004942d9  8945c8                   mov       dword ptr [ebp - 0x38], eax
004942dc  894dc4                   mov       dword ptr [ebp - 0x3c], ecx
004942df  8955c0                   mov       dword ptr [ebp - 0x40], edx
004942e2  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004942e5  8b08                     mov       ecx, dword ptr [eax]
004942e7  8d1d78755b00             lea       ebx, [0x5b7578] ; bits=00000000, f32=0.0
004942ed  894bec                   mov       dword ptr [ebx - 0x14], ecx
004942f0  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004942f3  d900                     fld       dword ptr [eax]
004942f5  d86804                   fsubr     dword ptr [eax + 4]
004942f8  8b45c0                   mov       eax, dword ptr [ebp - 0x40]
004942fb  d900                     fld       dword ptr [eax]
004942fd  d94380                   fld       dword ptr [ebx - 0x80]
00494300  d808                     fmul      dword ptr [eax]
00494302  d9ca                     fxch      st(2)
00494304  d8da                     fcomp     st(2)
00494306  ddd9                     fstp      st(1)
00494308  dfe0                     fnstsw    ax
0049430a  9e                       sahf
0049430b  894dbc                   mov       dword ptr [ebp - 0x44], ecx
0049430e  0f8a5e000000             jp        0x494372
00494314  775c                     ja        0x494372
00494316  8b43ec                   mov       eax, dword ptr [ebx - 0x14]
00494319  83c0fe                   add       eax, -2
0049431c  89c3                     mov       ebx, eax
0049431e  83fb00                   cmp       ebx, 0
00494321  7e42                     jle       0x494365
00494323  b803000000               mov       eax, 3
00494328  83fb02                   cmp       ebx, 2
0049432b  8945b8                   mov       dword ptr [ebp - 0x48], eax
0049432e  7c23                     jl        0x494353
00494330  8b4db8                   mov       ecx, dword ptr [ebp - 0x48]
00494333  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00494336  8b5488fc                 mov       edx, dword ptr [eax + ecx*4 - 4]
0049433a  895488f8                 mov       dword ptr [eax + ecx*4 - 8], edx
0049433e  8b1488                   mov       edx, dword ptr [eax + ecx*4]
00494341  895488fc                 mov       dword ptr [eax + ecx*4 - 4], edx
00494345  83c102                   add       ecx, 2
00494348  83eb02                   sub       ebx, 2
0049434b  83fb02                   cmp       ebx, 2
0049434e  894db8                   mov       dword ptr [ebp - 0x48], ecx
00494351  7ddd                     jge       0x494330
00494353  85db                     test      ebx, ebx
00494355  740e                     je        0x494365
00494357  8b4db8                   mov       ecx, dword ptr [ebp - 0x48]
0049435a  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0049435d  8b5488fc                 mov       edx, dword ptr [eax + ecx*4 - 4]
00494361  895488f8                 mov       dword ptr [eax + ecx*4 - 8], edx
00494365  8d0578755b00             lea       eax, [0x5b7578] ; bits=00000000, f32=0.0
0049436b  8b48ec                   mov       ecx, dword ptr [eax - 0x14]
0049436e  49                       dec       ecx
0049436f  8948ec                   mov       dword ptr [eax - 0x14], ecx
00494372  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00494375  833800                   cmp       dword ptr [eax], 0
00494378  7579                     jne       0x4943f3
0049437a  8d1d78755b00             lea       ebx, [0x5b7578] ; bits=00000000, f32=0.0
00494380  d9c0                     fld       st(0)
00494382  d84b88                   fmul      dword ptr [ebx - 0x78]
00494385  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00494388  d900                     fld       dword ptr [eax]
0049438a  d9c9                     fxch      st(1)
0049438c  d800                     fadd      dword ptr [eax]
0049438e  d94004                   fld       dword ptr [eax + 4]
00494391  ded9                     fcompp
00494393  d9c9                     fxch      st(1)
00494395  8945b4                   mov       dword ptr [ebp - 0x4c], eax
00494398  dfe0                     fnstsw    ax
0049439a  9e                       sahf
0049439b  0f8a56000000             jp        0x4943f7
004943a1  7654                     jbe       0x4943f7
004943a3  8b43ec                   mov       eax, dword ptr [ebx - 0x14]
004943a6  40                       inc       eax
004943a7  8943ec                   mov       dword ptr [ebx - 0x14], eax
004943aa  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
004943ad  8b08                     mov       ecx, dword ptr [eax]
004943af  8b53ec                   mov       edx, dword ptr [ebx - 0x14]
004943b2  39ca                     cmp       edx, ecx
004943b4  7f10                     jg        0x4943c6
004943b6  dec1                     faddp     st(1)
004943b8  89d8                     mov       eax, ebx
004943ba  8b48ec                   mov       ecx, dword ptr [eax - 0x14]
004943bd  8b45b4                   mov       eax, dword ptr [ebp - 0x4c]
004943c0  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
004943c4  eb35                     jmp       0x4943fb
004943c6  ddd8                     fstp      st(0)
004943c8  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
004943cb  ddd8                     fstp      st(0)
004943cd  8b08                     mov       ecx, dword ptr [eax]
004943cf  89da                     mov       edx, ebx
004943d1  8d52cc                   lea       edx, [edx - 0x34]
004943d4  894dfc                   mov       dword ptr [ebp - 4], ecx
004943d7  8d4dfc                   lea       ecx, [ebp - 4]
004943da  894a08                   mov       dword ptr [edx + 8], ecx
004943dd  52                       push      edx
004943de  e80de20000               call      0x4a25f0 ; _jwe_isfm
004943e3  83c404                   add       esp, 4
004943e6  89d8                     mov       eax, ebx
004943e8  8b40ec                   mov       eax, dword ptr [eax - 0x14]
004943eb  48                       dec       eax
004943ec  89d9                     mov       ecx, ebx
004943ee  8941ec                   mov       dword ptr [ecx - 0x14], eax
004943f1  eb08                     jmp       0x4943fb
004943f3  ddd8                     fstp      st(0)
004943f5  eb04                     jmp       0x4943fb
004943f7  ddd8                     fstp      st(0)
004943f9  ddd8                     fstp      st(0)
004943fb  8b45bc                   mov       eax, dword ptr [ebp - 0x44]
004943fe  83c0ff                   add       eax, -1
00494401  3d00000000               cmp       eax, 0
00494406  8945b0                   mov       dword ptr [ebp - 0x50], eax
00494409  0f8ee2000000             jle       0x4944f1
0049440f  b802000000               mov       eax, 2
00494414  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00494417  d901                     fld       dword ptr [ecx]
00494419  8945b8                   mov       dword ptr [ebp - 0x48], eax
0049441c  8b4db8                   mov       ecx, dword ptr [ebp - 0x48]
0049441f  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00494422  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00494426  d9c0                     fld       st(0)
00494428  d86c88fc                 fsubr     dword ptr [eax + ecx*4 - 4]
0049442c  d8d2                     fcom      st(2)
0049442e  dfe0                     fnstsw    ax
00494430  9e                       sahf
00494431  0f8aa1000000             jp        0x4944d8
00494437  0f869b000000             jbe       0x4944d8
0049443d  d9c0                     fld       st(0)
0049443f  d8f3                     fdiv      st(3)
00494441  d80504755b00             fadd      dword ptr [0x5b7504] ; bits=0000803f, f32=1.0
00494447  d97dfa                   fnstcw    word ptr [ebp - 6]
0049444a  668b45fa                 mov       ax, word ptr [ebp - 6]
0049444e  660d000c                 or        ax, 0xc00
00494452  668945f8                 mov       word ptr [ebp - 8], ax
00494456  d96df8                   fldcw     word ptr [ebp - 8]
00494459  df7df0                   fistp     qword ptr [ebp - 0x10]
0049445c  d96dfa                   fldcw     word ptr [ebp - 6]
0049445f  8b5df0                   mov       ebx, dword ptr [ebp - 0x10]
00494462  895dfc                   mov       dword ptr [ebp - 4], ebx
00494465  da75fc                   fidiv     dword ptr [ebp - 4]
00494468  d9c9                     fxch      st(1)
0049446a  d9ca                     fxch      st(2)
0049446c  d9c9                     fxch      st(1)
0049446e  89d8                     mov       eax, ebx
00494470  48                       dec       eax
00494471  89c6                     mov       esi, eax
00494473  83fe00                   cmp       esi, 0
00494476  7e66                     jle       0x4944de
00494478  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
0049447b  8b38                     mov       edi, dword ptr [eax]
0049447d  8b1d64755b00             mov       ebx, dword ptr [0x5b7564] ; bits=00000000, f32=0.0
00494483  43                       inc       ebx
00494484  dcc2                     fadd      st(2), st(0)
00494486  39fb                     cmp       ebx, edi
00494488  7f0d                     jg        0x494497
0049448a  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0049448d  d9ca                     fxch      st(2)
0049448f  d95498fc                 fst       dword ptr [eax + ebx*4 - 4]
00494493  d9ca                     fxch      st(2)
00494495  eb30                     jmp       0x4944c7
00494497  db7dcc                   fstp      xword ptr [ebp - 0x34]
0049449a  db7dd8                   fstp      xword ptr [ebp - 0x28]
0049449d  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
004944a0  db7de4                   fstp      xword ptr [ebp - 0x1c]
004944a3  8b08                     mov       ecx, dword ptr [eax]
004944a5  8d1524755b00             lea       edx, [0x5b7524] ; bits=69020000, f32=8.646011524884121e-43
004944ab  894dfc                   mov       dword ptr [ebp - 4], ecx
004944ae  8d4dfc                   lea       ecx, [ebp - 4]
004944b1  894a08                   mov       dword ptr [edx + 8], ecx
004944b4  52                       push      edx
004944b5  e836e10000               call      0x4a25f0 ; _jwe_isfm
004944ba  db6de4                   fld       xword ptr [ebp - 0x1c]
004944bd  db6dd8                   fld       xword ptr [ebp - 0x28]
004944c0  db6dcc                   fld       xword ptr [ebp - 0x34]
004944c3  83c404                   add       esp, 4
004944c6  4b                       dec       ebx
004944c7  83ee01                   sub       esi, 1
004944ca  75b7                     jne       0x494483
004944cc  ddd8                     fstp      st(0)
004944ce  ddd9                     fstp      st(1)
004944d0  891d64755b00             mov       dword ptr [0x5b7564], ebx ; bits=00000000, f32=0.0
004944d6  eb0a                     jmp       0x4944e2
004944d8  ddd8                     fstp      st(0)
004944da  ddd8                     fstp      st(0)
004944dc  eb04                     jmp       0x4944e2
004944de  ddd8                     fstp      st(0)
004944e0  ddd9                     fstp      st(1)
004944e2  ff45b8                   inc       dword ptr [ebp - 0x48]
004944e5  836db001                 sub       dword ptr [ebp - 0x50], 1
004944e9  0f852dffffff             jne       0x49441c
004944ef  ddd8                     fstp      st(0)
004944f1  8b5d20                   mov       ebx, dword ptr [ebp + 0x20]
004944f4  8d03                     lea       eax, [ebx]
004944f6  50                       push      eax
004944f7  8d3578755b00             lea       esi, [0x5b7578] ; bits=00000000, f32=0.0
004944fd  8d46ec                   lea       eax, [esi - 0x14]
00494500  50                       push      eax
00494501  e80a27feff               call      0x476c10 ; _sort_
00494506  83c408                   add       esp, 8
00494509  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0049450c  8d00                     lea       eax, [eax]
0049450e  50                       push      eax
0049450f  8d1b                     lea       ebx, [ebx]
00494511  53                       push      ebx
00494512  8d76ec                   lea       esi, [esi - 0x14]
00494515  56                       push      esi
00494516  e865b9fbff               call      0x44fe80 ; _rdup_
0049451b  83c40c                   add       esp, 0xc
0049451e  b800000000               mov       eax, 0
00494523  5f                       pop       edi
00494524  5e                       pop       esi
00494525  5b                       pop       ebx
00494526  8be5                     mov       esp, ebp
00494528  5d                       pop       ebp
00494529  c3                       ret
0049452a  8d9b00000000             lea       ebx, [ebx]
