; _fndhpl_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x340a0
004340a0  55                       push      ebp
004340a1  8bec                     mov       ebp, esp
004340a3  b840000000               mov       eax, 0x40
004340a8  e8534f0b00               call      0x4e9000 ; __alloca_probe
004340ad  53                       push      ebx
004340ae  56                       push      esi
004340af  d90538aee900             fld       dword ptr [0xe9ae38]
004340b5  d83d74aee900             fdivr     dword ptr [0xe9ae74]
004340bb  d8c8                     fmul      st(0)
004340bd  d80d40aee900             fmul      dword ptr [0xe9ae40]
004340c3  d8356caee900             fdiv      dword ptr [0xe9ae6c]
004340c9  d80528aee900             fadd      dword ptr [0xe9ae28]
004340cf  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
004340d5  d95b7c                   fstp      dword ptr [ebx + 0x7c]
004340d8  833d4caee90000           cmp       dword ptr [0xe9ae4c], 0
004340df  7571                     jne       0x434152
004340e1  d9437c                   fld       dword ptr [ebx + 0x7c]
004340e4  d84b94                   fmul      dword ptr [ebx - 0x6c]
004340e7  d91d24aee900             fstp      dword ptr [0xe9ae24]
004340ed  8b437c                   mov       eax, dword ptr [ebx + 0x7c]
004340f0  894370                   mov       dword ptr [ebx + 0x70], eax
004340f3  6880aee900               push      0xe9ae80
004340f8  6824aee900               push      0xe9ae24
004340fd  68e03e4300               push      0x433ee0 ; _fhpl_
00434102  8d4398                   lea       eax, [ebx - 0x68]
00434105  50                       push      eax
00434106  8d437c                   lea       eax, [ebx + 0x7c]
00434109  50                       push      eax
0043410a  8d43b8                   lea       eax, [ebx - 0x48]
0043410d  50                       push      eax
0043410e  6878f70e04               push      0x40ef778
00434113  6868f70e04               push      0x40ef768
00434118  686cf70e04               push      0x40ef76c
0043411d  8d4370                   lea       eax, [ebx + 0x70]
00434120  50                       push      eax
00434121  e87af30300               call      0x4734a0 ; _secant_
00434126  83c428                   add       esp, 0x28
00434129  833d80aee90000           cmp       dword ptr [0xe9ae80], 0
00434130  0f8e2d050000             jle       0x434663
00434136  89d8                     mov       eax, ebx
00434138  8d4028                   lea       eax, [eax + 0x28]
0043413b  50                       push      eax
0043413c  e83fed0600               call      0x4a2e80 ; _jwe_ilst
00434141  83c404                   add       esp, 4
00434144  89d8                     mov       eax, ebx
00434146  8d401c                   lea       eax, [eax + 0x1c]
00434149  50                       push      eax
0043414a  e8f1f20600               call      0x4a3440 ; _jwe_xstp
0043414f  83c404                   add       esp, 4
00434152  684caee900               push      0xe9ae4c
00434157  e8e4cc0000               call      0x440e40 ; _fmxarg_
0043415c  83c404                   add       esp, 4
0043415f  d80554aee900             fadd      dword ptr [0xe9ae54]
00434165  d82570aee900             fsub      dword ptr [0xe9ae70]
0043416b  89d8                     mov       eax, ebx
0043416d  d95874                   fstp      dword ptr [eax + 0x74]
00434170  89d8                     mov       eax, ebx
00434172  89d9                     mov       ecx, ebx
00434174  d9417c                   fld       dword ptr [ecx + 0x7c]
00434177  d8407c                   fadd      dword ptr [eax + 0x7c]
0043417a  db7dd8                   fstp      xword ptr [ebp - 0x28]
0043417d  89d8                     mov       eax, ebx
0043417f  d94074                   fld       dword ptr [eax + 0x74]
00434182  db6dd8                   fld       xword ptr [ebp - 0x28]
00434185  d9c9                     fxch      st(1)
00434187  ded9                     fcompp
00434189  dfe0                     fnstsw    ax
0043418b  9e                       sahf
0043418c  0f8a0a000000             jp        0x43419c
00434192  7608                     jbe       0x43419c
00434194  89d8                     mov       eax, ebx
00434196  db6dd8                   fld       xword ptr [ebp - 0x28]
00434199  d95874                   fstp      dword ptr [eax + 0x74]
0043419c  d90570aee900             fld       dword ptr [0xe9ae70]
004341a2  d82d54aee900             fsubr     dword ptr [0xe9ae54]
004341a8  8d0d40f65600             lea       ecx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
004341ae  d95978                   fstp      dword ptr [ecx + 0x78]
004341b1  d94178                   fld       dword ptr [ecx + 0x78]
004341b4  d81dccf55600             fcomp     dword ptr [0x56f5cc] ; bits=00000000, f32=0.0
004341ba  dfe0                     fnstsw    ax
004341bc  9e                       sahf
004341bd  0f8a09000000             jp        0x4341cc
004341c3  7307                     jae       0x4341cc
004341c5  c7417800000000           mov       dword ptr [ecx + 0x78], 0
004341cc  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
004341d2  d94374                   fld       dword ptr [ebx + 0x74]
004341d5  dd5b60                   fstp      qword ptr [ebx + 0x60]
004341d8  8d4360                   lea       eax, [ebx + 0x60]
004341db  50                       push      eax
004341dc  e8fffcffff               call      0x433ee0 ; _fhpl_
004341e1  83c404                   add       esp, 4
004341e4  d94378                   fld       dword ptr [ebx + 0x78]
004341e7  d86b74                   fsubr     dword ptr [ebx + 0x74]
004341ea  d84b88                   fmul      dword ptr [ebx - 0x78]
004341ed  dd5dd0                   fstp      qword ptr [ebp - 0x30]
004341f0  d943a4                   fld       dword ptr [ebx - 0x5c]
004341f3  be05000000               mov       esi, 5
004341f8  db7de4                   fstp      xword ptr [ebp - 0x1c]
004341fb  db7df0                   fstp      xword ptr [ebp - 0x10]
004341fe  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
00434204  dd4360                   fld       qword ptr [ebx + 0x60]
00434207  dd5dc8                   fstp      qword ptr [ebp - 0x38]
0043420a  dd45d0                   fld       qword ptr [ebp - 0x30]
0043420d  dc6dc8                   fsubr     qword ptr [ebp - 0x38]
00434210  dd5b58                   fstp      qword ptr [ebx + 0x58]
00434213  8d4358                   lea       eax, [ebx + 0x58]
00434216  50                       push      eax
00434217  e8c4fcffff               call      0x433ee0 ; _fhpl_
0043421c  83c404                   add       esp, 4
0043421f  db6df0                   fld       xword ptr [ebp - 0x10]
00434222  d8c9                     fmul      st(1)
00434224  dc1dc0f55600             fcomp     qword ptr [0x56f5c0] ; bits=0000000000000000, f64=0.0
0043422a  db6df0                   fld       xword ptr [ebp - 0x10]
0043422d  db6de4                   fld       xword ptr [ebp - 0x1c]
00434230  dfe0                     fnstsw    ax
00434232  9e                       sahf
00434233  0f8a06000000             jp        0x43423f
00434239  0f8690030000             jbe       0x4345cf
0043423f  d9c2                     fld       st(2)
00434241  d9e1                     fabs
00434243  d9ca                     fxch      st(2)
00434245  d9e1                     fabs
00434247  dec2                     faddp     st(2)
00434249  d9c9                     fxch      st(1)
0043424b  d95dfc                   fstp      dword ptr [ebp - 4]
0043424e  d945fc                   fld       dword ptr [ebp - 4]
00434251  d8d1                     fcom      st(1)
00434253  dfe0                     fnstsw    ax
00434255  9e                       sahf
00434256  0f8a12000000             jp        0x43426e
0043425c  7310                     jae       0x43426e
0043425e  ddd9                     fstp      st(1)
00434260  dd4358                   fld       qword ptr [ebx + 0x58]
00434263  d95b68                   fstp      dword ptr [ebx + 0x68]
00434266  dd45c8                   fld       qword ptr [ebp - 0x38]
00434269  d95b6c                   fstp      dword ptr [ebx + 0x6c]
0043426c  eb02                     jmp       0x434270
0043426e  ddd8                     fstp      st(0)
00434270  db7de4                   fstp      xword ptr [ebp - 0x1c]
00434273  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
00434279  8b4358                   mov       eax, dword ptr [ebx + 0x58]
0043427c  8b4b5c                   mov       ecx, dword ptr [ebx + 0x5c]
0043427f  894360                   mov       dword ptr [ebx + 0x60], eax
00434282  894b64                   mov       dword ptr [ebx + 0x64], ecx
00434285  db7df0                   fstp      xword ptr [ebp - 0x10]
00434288  dd45d0                   fld       qword ptr [ebp - 0x30]
0043428b  dc6b58                   fsubr     qword ptr [ebx + 0x58]
0043428e  dd5b58                   fstp      qword ptr [ebx + 0x58]
00434291  8d4358                   lea       eax, [ebx + 0x58]
00434294  50                       push      eax
00434295  e846fcffff               call      0x433ee0 ; _fhpl_
0043429a  83c404                   add       esp, 4
0043429d  db6df0                   fld       xword ptr [ebp - 0x10]
004342a0  d8c9                     fmul      st(1)
004342a2  dc1dc0f55600             fcomp     qword ptr [0x56f5c0] ; bits=0000000000000000, f64=0.0
004342a8  db6df0                   fld       xword ptr [ebp - 0x10]
004342ab  db6de4                   fld       xword ptr [ebp - 0x1c]
004342ae  dfe0                     fnstsw    ax
004342b0  9e                       sahf
004342b1  0f8a06000000             jp        0x4342bd
004342b7  0f8612030000             jbe       0x4345cf
004342bd  d9c2                     fld       st(2)
004342bf  d9e1                     fabs
004342c1  d9ca                     fxch      st(2)
004342c3  d9e1                     fabs
004342c5  dec2                     faddp     st(2)
004342c7  d9c9                     fxch      st(1)
004342c9  d95dfc                   fstp      dword ptr [ebp - 4]
004342cc  d945fc                   fld       dword ptr [ebp - 4]
004342cf  d8d1                     fcom      st(1)
004342d1  dfe0                     fnstsw    ax
004342d3  9e                       sahf
004342d4  0f8a12000000             jp        0x4342ec
004342da  7310                     jae       0x4342ec
004342dc  ddd9                     fstp      st(1)
004342de  dd4358                   fld       qword ptr [ebx + 0x58]
004342e1  d95b68                   fstp      dword ptr [ebx + 0x68]
004342e4  dd4360                   fld       qword ptr [ebx + 0x60]
004342e7  d95b6c                   fstp      dword ptr [ebx + 0x6c]
004342ea  eb02                     jmp       0x4342ee
004342ec  ddd8                     fstp      st(0)
004342ee  db7de4                   fstp      xword ptr [ebp - 0x1c]
004342f1  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
004342f7  8b4358                   mov       eax, dword ptr [ebx + 0x58]
004342fa  8b4b5c                   mov       ecx, dword ptr [ebx + 0x5c]
004342fd  894360                   mov       dword ptr [ebx + 0x60], eax
00434300  894b64                   mov       dword ptr [ebx + 0x64], ecx
00434303  db7df0                   fstp      xword ptr [ebp - 0x10]
00434306  dd45d0                   fld       qword ptr [ebp - 0x30]
00434309  dc6b58                   fsubr     qword ptr [ebx + 0x58]
0043430c  dd5b58                   fstp      qword ptr [ebx + 0x58]
0043430f  8d4358                   lea       eax, [ebx + 0x58]
00434312  50                       push      eax
00434313  e8c8fbffff               call      0x433ee0 ; _fhpl_
00434318  83c404                   add       esp, 4
0043431b  db6df0                   fld       xword ptr [ebp - 0x10]
0043431e  d8c9                     fmul      st(1)
00434320  dc1dc0f55600             fcomp     qword ptr [0x56f5c0] ; bits=0000000000000000, f64=0.0
00434326  db6df0                   fld       xword ptr [ebp - 0x10]
00434329  db6de4                   fld       xword ptr [ebp - 0x1c]
0043432c  dfe0                     fnstsw    ax
0043432e  9e                       sahf
0043432f  0f8a06000000             jp        0x43433b
00434335  0f8694020000             jbe       0x4345cf
0043433b  d9c2                     fld       st(2)
0043433d  d9e1                     fabs
0043433f  d9ca                     fxch      st(2)
00434341  d9e1                     fabs
00434343  dec2                     faddp     st(2)
00434345  d9c9                     fxch      st(1)
00434347  d95dfc                   fstp      dword ptr [ebp - 4]
0043434a  d945fc                   fld       dword ptr [ebp - 4]
0043434d  d8d1                     fcom      st(1)
0043434f  dfe0                     fnstsw    ax
00434351  9e                       sahf
00434352  0f8a12000000             jp        0x43436a
00434358  7310                     jae       0x43436a
0043435a  ddd9                     fstp      st(1)
0043435c  dd4358                   fld       qword ptr [ebx + 0x58]
0043435f  d95b68                   fstp      dword ptr [ebx + 0x68]
00434362  dd4360                   fld       qword ptr [ebx + 0x60]
00434365  d95b6c                   fstp      dword ptr [ebx + 0x6c]
00434368  eb02                     jmp       0x43436c
0043436a  ddd8                     fstp      st(0)
0043436c  db7de4                   fstp      xword ptr [ebp - 0x1c]
0043436f  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
00434375  8b4358                   mov       eax, dword ptr [ebx + 0x58]
00434378  8b4b5c                   mov       ecx, dword ptr [ebx + 0x5c]
0043437b  894360                   mov       dword ptr [ebx + 0x60], eax
0043437e  894b64                   mov       dword ptr [ebx + 0x64], ecx
00434381  db7df0                   fstp      xword ptr [ebp - 0x10]
00434384  dd45d0                   fld       qword ptr [ebp - 0x30]
00434387  dc6b58                   fsubr     qword ptr [ebx + 0x58]
0043438a  dd5b58                   fstp      qword ptr [ebx + 0x58]
0043438d  8d4358                   lea       eax, [ebx + 0x58]
00434390  50                       push      eax
00434391  e84afbffff               call      0x433ee0 ; _fhpl_
00434396  83c404                   add       esp, 4
00434399  db6df0                   fld       xword ptr [ebp - 0x10]
0043439c  d8c9                     fmul      st(1)
0043439e  dc1dc0f55600             fcomp     qword ptr [0x56f5c0] ; bits=0000000000000000, f64=0.0
004343a4  db6df0                   fld       xword ptr [ebp - 0x10]
004343a7  db6de4                   fld       xword ptr [ebp - 0x1c]
004343aa  dfe0                     fnstsw    ax
004343ac  9e                       sahf
004343ad  0f8a06000000             jp        0x4343b9
004343b3  0f8616020000             jbe       0x4345cf
004343b9  d9c2                     fld       st(2)
004343bb  d9e1                     fabs
004343bd  d9ca                     fxch      st(2)
004343bf  d9e1                     fabs
004343c1  dec2                     faddp     st(2)
004343c3  d9c9                     fxch      st(1)
004343c5  d95dfc                   fstp      dword ptr [ebp - 4]
004343c8  d945fc                   fld       dword ptr [ebp - 4]
004343cb  d8d1                     fcom      st(1)
004343cd  dfe0                     fnstsw    ax
004343cf  9e                       sahf
004343d0  0f8a12000000             jp        0x4343e8
004343d6  7310                     jae       0x4343e8
004343d8  ddd9                     fstp      st(1)
004343da  dd4358                   fld       qword ptr [ebx + 0x58]
004343dd  d95b68                   fstp      dword ptr [ebx + 0x68]
004343e0  dd4360                   fld       qword ptr [ebx + 0x60]
004343e3  d95b6c                   fstp      dword ptr [ebx + 0x6c]
004343e6  eb02                     jmp       0x4343ea
004343e8  ddd8                     fstp      st(0)
004343ea  db7de4                   fstp      xword ptr [ebp - 0x1c]
004343ed  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
004343f3  8b4358                   mov       eax, dword ptr [ebx + 0x58]
004343f6  8b4b5c                   mov       ecx, dword ptr [ebx + 0x5c]
004343f9  894360                   mov       dword ptr [ebx + 0x60], eax
004343fc  894b64                   mov       dword ptr [ebx + 0x64], ecx
004343ff  db7df0                   fstp      xword ptr [ebp - 0x10]
00434402  dd45d0                   fld       qword ptr [ebp - 0x30]
00434405  dc6b58                   fsubr     qword ptr [ebx + 0x58]
00434408  dd5b58                   fstp      qword ptr [ebx + 0x58]
0043440b  8d4358                   lea       eax, [ebx + 0x58]
0043440e  50                       push      eax
0043440f  e8ccfaffff               call      0x433ee0 ; _fhpl_
00434414  83c404                   add       esp, 4
00434417  db6df0                   fld       xword ptr [ebp - 0x10]
0043441a  d8c9                     fmul      st(1)
0043441c  dc1dc0f55600             fcomp     qword ptr [0x56f5c0] ; bits=0000000000000000, f64=0.0
00434422  db6df0                   fld       xword ptr [ebp - 0x10]
00434425  db6de4                   fld       xword ptr [ebp - 0x1c]
00434428  dfe0                     fnstsw    ax
0043442a  9e                       sahf
0043442b  0f8a06000000             jp        0x434437
00434431  0f8698010000             jbe       0x4345cf
00434437  d9c2                     fld       st(2)
00434439  d9e1                     fabs
0043443b  d9ca                     fxch      st(2)
0043443d  d9e1                     fabs
0043443f  dec2                     faddp     st(2)
00434441  d9c9                     fxch      st(1)
00434443  d95dfc                   fstp      dword ptr [ebp - 4]
00434446  d945fc                   fld       dword ptr [ebp - 4]
00434449  d8d1                     fcom      st(1)
0043444b  dfe0                     fnstsw    ax
0043444d  9e                       sahf
0043444e  0f8a12000000             jp        0x434466
00434454  7310                     jae       0x434466
00434456  ddd9                     fstp      st(1)
00434458  dd4358                   fld       qword ptr [ebx + 0x58]
0043445b  d95b68                   fstp      dword ptr [ebx + 0x68]
0043445e  dd4360                   fld       qword ptr [ebx + 0x60]
00434461  d95b6c                   fstp      dword ptr [ebx + 0x6c]
00434464  eb02                     jmp       0x434468
00434466  ddd8                     fstp      st(0)
00434468  db7de4                   fstp      xword ptr [ebp - 0x1c]
0043446b  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
00434471  8b4358                   mov       eax, dword ptr [ebx + 0x58]
00434474  8b4b5c                   mov       ecx, dword ptr [ebx + 0x5c]
00434477  894360                   mov       dword ptr [ebx + 0x60], eax
0043447a  894b64                   mov       dword ptr [ebx + 0x64], ecx
0043447d  db7df0                   fstp      xword ptr [ebp - 0x10]
00434480  dd45d0                   fld       qword ptr [ebp - 0x30]
00434483  dc6b58                   fsubr     qword ptr [ebx + 0x58]
00434486  dd5b58                   fstp      qword ptr [ebx + 0x58]
00434489  8d4358                   lea       eax, [ebx + 0x58]
0043448c  50                       push      eax
0043448d  e84efaffff               call      0x433ee0 ; _fhpl_
00434492  83c404                   add       esp, 4
00434495  db6df0                   fld       xword ptr [ebp - 0x10]
00434498  d8c9                     fmul      st(1)
0043449a  dc1dc0f55600             fcomp     qword ptr [0x56f5c0] ; bits=0000000000000000, f64=0.0
004344a0  db6df0                   fld       xword ptr [ebp - 0x10]
004344a3  db6de4                   fld       xword ptr [ebp - 0x1c]
004344a6  dfe0                     fnstsw    ax
004344a8  9e                       sahf
004344a9  0f8a06000000             jp        0x4344b5
004344af  0f861a010000             jbe       0x4345cf
004344b5  d9c2                     fld       st(2)
004344b7  d9e1                     fabs
004344b9  d9ca                     fxch      st(2)
004344bb  d9e1                     fabs
004344bd  dec2                     faddp     st(2)
004344bf  d9c9                     fxch      st(1)
004344c1  d95dfc                   fstp      dword ptr [ebp - 4]
004344c4  d945fc                   fld       dword ptr [ebp - 4]
004344c7  d8d1                     fcom      st(1)
004344c9  dfe0                     fnstsw    ax
004344cb  9e                       sahf
004344cc  0f8a12000000             jp        0x4344e4
004344d2  7310                     jae       0x4344e4
004344d4  ddd9                     fstp      st(1)
004344d6  dd4358                   fld       qword ptr [ebx + 0x58]
004344d9  d95b68                   fstp      dword ptr [ebx + 0x68]
004344dc  dd4360                   fld       qword ptr [ebx + 0x60]
004344df  d95b6c                   fstp      dword ptr [ebx + 0x6c]
004344e2  eb02                     jmp       0x4344e6
004344e4  ddd8                     fstp      st(0)
004344e6  8d0540f65600             lea       eax, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
004344ec  8b4858                   mov       ecx, dword ptr [eax + 0x58]
004344ef  8b505c                   mov       edx, dword ptr [eax + 0x5c]
004344f2  894860                   mov       dword ptr [eax + 0x60], ecx
004344f5  895064                   mov       dword ptr [eax + 0x64], edx
004344f8  4e                       dec       esi
004344f9  83fe01                   cmp       esi, 1
004344fc  0f8df6fcffff             jge       0x4341f8
00434502  db7de4                   fstp      xword ptr [ebp - 0x1c]
00434505  db7df0                   fstp      xword ptr [ebp - 0x10]
00434508  8d1d40f65600             lea       ebx, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
0043450e  dd4360                   fld       qword ptr [ebx + 0x60]
00434511  dd5dc0                   fstp      qword ptr [ebp - 0x40]
00434514  dd45d0                   fld       qword ptr [ebp - 0x30]
00434517  dc6dc0                   fsubr     qword ptr [ebp - 0x40]
0043451a  dd5b58                   fstp      qword ptr [ebx + 0x58]
0043451d  8d4358                   lea       eax, [ebx + 0x58]
00434520  50                       push      eax
00434521  e8baf9ffff               call      0x433ee0 ; _fhpl_
00434526  83c404                   add       esp, 4
00434529  db6df0                   fld       xword ptr [ebp - 0x10]
0043452c  d8c9                     fmul      st(1)
0043452e  dc1dc0f55600             fcomp     qword ptr [0x56f5c0] ; bits=0000000000000000, f64=0.0
00434534  db6df0                   fld       xword ptr [ebp - 0x10]
00434537  db6de4                   fld       xword ptr [ebp - 0x1c]
0043453a  dfe0                     fnstsw    ax
0043453c  9e                       sahf
0043453d  0f8a06000000             jp        0x434549
00434543  0f8686000000             jbe       0x4345cf
00434549  d9ca                     fxch      st(2)
0043454b  d9e1                     fabs
0043454d  d9c9                     fxch      st(1)
0043454f  d9e1                     fabs
00434551  dec1                     faddp     st(1)
00434553  d95dfc                   fstp      dword ptr [ebp - 4]
00434556  d945fc                   fld       dword ptr [ebp - 4]
00434559  ded9                     fcompp
0043455b  dfe0                     fnstsw    ax
0043455d  9e                       sahf
0043455e  0f8a0e000000             jp        0x434572
00434564  730c                     jae       0x434572
00434566  dd4358                   fld       qword ptr [ebx + 0x58]
00434569  d95b68                   fstp      dword ptr [ebx + 0x68]
0043456c  dd45c0                   fld       qword ptr [ebp - 0x40]
0043456f  d95b6c                   fstp      dword ptr [ebx + 0x6c]
00434572  8d0540f65600             lea       eax, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
00434578  8b486c                   mov       ecx, dword ptr [eax + 0x6c]
0043457b  890d24aee900             mov       dword ptr [0xe9ae24], ecx
00434581  6880aee900               push      0xe9ae80
00434586  6824aee900               push      0xe9ae24
0043458b  68e03e4300               push      0x433ee0 ; _fhpl_
00434590  8d4874                   lea       ecx, [eax + 0x74]
00434593  51                       push      ecx
00434594  8d4878                   lea       ecx, [eax + 0x78]
00434597  51                       push      ecx
00434598  8d48b8                   lea       ecx, [eax - 0x48]
0043459b  51                       push      ecx
0043459c  6878f70e04               push      0x40ef778
004345a1  6868f70e04               push      0x40ef768
004345a6  686cf70e04               push      0x40ef76c
004345ab  8d4068                   lea       eax, [eax + 0x68]
004345ae  50                       push      eax
004345af  e8ecee0300               call      0x4734a0 ; _secant_
004345b4  83c428                   add       esp, 0x28
004345b7  833d80aee90000           cmp       dword ptr [0xe9ae80], 0
004345be  7e73                     jle       0x434633
004345c0  c70580aee90003000000     mov       dword ptr [0xe9ae80], 3
004345ca  e994000000               jmp       0x434663
004345cf  ddd8                     fstp      st(0)
004345d1  ddd8                     fstp      st(0)
004345d3  ddd8                     fstp      st(0)
004345d5  8d0540f65600             lea       eax, [0x56f640] ; bits=41626e6f, f32=7.377621402162375e+28
004345db  dd4060                   fld       qword ptr [eax + 0x60]
004345de  d91d24aee900             fstp      dword ptr [0xe9ae24]
004345e4  dd4058                   fld       qword ptr [eax + 0x58]
004345e7  d95dfc                   fstp      dword ptr [ebp - 4]
004345ea  6880aee900               push      0xe9ae80
004345ef  6824aee900               push      0xe9ae24
004345f4  68e03e4300               push      0x433ee0 ; _fhpl_
004345f9  8d4874                   lea       ecx, [eax + 0x74]
004345fc  51                       push      ecx
004345fd  8d4878                   lea       ecx, [eax + 0x78]
00434600  51                       push      ecx
00434601  8d40b8                   lea       eax, [eax - 0x48]
00434604  50                       push      eax
00434605  6878f70e04               push      0x40ef778
0043460a  6868f70e04               push      0x40ef768
0043460f  686cf70e04               push      0x40ef76c
00434614  8d45fc                   lea       eax, [ebp - 4]
00434617  50                       push      eax
00434618  e883ee0300               call      0x4734a0 ; _secant_
0043461d  83c428                   add       esp, 0x28
00434620  833d80aee90000           cmp       dword ptr [0xe9ae80], 0
00434627  7e0a                     jle       0x434633
00434629  c70580aee90004000000     mov       dword ptr [0xe9ae80], 4
00434633  833d80aee90000           cmp       dword ptr [0xe9ae80], 0
0043463a  7527                     jne       0x434663
0043463c  d90578aee900             fld       dword ptr [0xe9ae78]
00434642  d83d74aee900             fdivr     dword ptr [0xe9ae74]
00434648  d81de8f55600             fcomp     dword ptr [0x56f5e8] ; bits=0000803f, f32=1.0
0043464e  dfe0                     fnstsw    ax
00434650  9e                       sahf
00434651  0f8a0c000000             jp        0x434663
00434657  720a                     jb        0x434663
00434659  c70580aee90005000000     mov       dword ptr [0xe9ae80], 5
00434663  b800000000               mov       eax, 0
00434668  5e                       pop       esi
00434669  5b                       pop       ebx
0043466a  8be5                     mov       esp, ebp
0043466c  5d                       pop       ebp
0043466d  c3                       ret
0043466e  8bff                     mov       edi, edi
