; _rty7rf_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x11e70
00411e70  55                       push      ebp
00411e71  8bec                     mov       ebp, esp
00411e73  b81c000000               mov       eax, 0x1c
00411e78  e883710d00               call      0x4e9000 ; __alloca_probe
00411e7d  53                       push      ebx
00411e7e  56                       push      esi
00411e7f  8b7508                   mov       esi, dword ptr [ebp + 8]
00411e82  8b06                     mov       eax, dword ptr [esi]
00411e84  8905a8f4f200             mov       dword ptr [0xf2f4a8], eax
00411e8a  d905acf4f200             fld       dword ptr [0xf2f4ac]
00411e90  d82da8f4f200             fsubr     dword ptr [0xf2f4a8]
00411e96  d91db0f4f200             fstp      dword ptr [0xf2f4b0]
00411e9c  68d8f4f200               push      0xf2f4d8
00411ea1  68d4f4f200               push      0xf2f4d4
00411ea6  68d0f4f200               push      0xf2f4d0
00411eab  68ccf4f200               push      0xf2f4cc
00411eb0  68c8f4f200               push      0xf2f4c8
00411eb5  68c4f4f200               push      0xf2f4c4
00411eba  68c0f4f200               push      0xf2f4c0
00411ebf  68b8f4f200               push      0xf2f4b8
00411ec4  68b4f4f200               push      0xf2f4b4
00411ec9  68bcf4f200               push      0xf2f4bc
00411ece  68b0f4f200               push      0xf2f4b0
00411ed3  68a0f4f200               push      0xf2f4a0 ; _x43com_
00411ed8  e8c3960300               call      0x44b5a0 ; _xlktal_
00411edd  83c430                   add       esp, 0x30
00411ee0  d906                     fld       dword ptr [esi]
00411ee2  d81d70bbf400             fcomp     dword ptr [0xf4bb70]
00411ee8  dfe0                     fnstsw    ax
00411eea  9e                       sahf
00411eeb  0f8ad6000000             jp        0x411fc7
00411ef1  0f86d0000000             jbe       0x411fc7
00411ef7  6a08                     push      8
00411ef9  6834bbf400               push      0xf4bb34
00411efe  6830bbf400               push      0xf4bb30
00411f03  682cbbf400               push      0xf4bb2c
00411f08  6804bbf400               push      0xf4bb04
00411f0d  6864abf400               push      0xf4ab64
00411f12  68c49bf400               push      0xf49bc4
00411f17  68248cf400               push      0xf48c24
00411f1c  68847cf400               push      0xf47c84
00411f21  68e46cf400               push      0xf46ce4
00411f26  68445df400               push      0xf45d44
00411f2b  68a44df400               push      0xf44da4
00411f30  68043ef400               push      0xf43e04
00411f35  68642ef400               push      0xf42e64
00411f3a  68c41ef400               push      0xf41ec4
00411f3f  68240ff400               push      0xf40f24
00411f44  6884fff300               push      0xf3ff84
00411f49  68e4eff300               push      0xf3efe4
00411f4e  6844e0f300               push      0xf3e044
00411f53  68a4d0f300               push      0xf3d0a4
00411f58  6804c1f300               push      0xf3c104
00411f5d  6864b1f300               push      0xf3b164
00411f62  68c4a1f300               push      0xf3a1c4
00411f67  682492f300               push      0xf39224
00411f6c  688482f300               push      0xf38284
00411f71  68e472f300               push      0xf372e4
00411f76  684463f300               push      0xf36344
00411f7b  68a453f300               push      0xf353a4
00411f80  6898bbf400               push      0xf4bb98
00411f85  68c0f5f200               push      0xf2f5c0 ; _embcmc_
00411f8a  680015f300               push      0xf31500 ; _embcom_
00411f8f  681c15f300               push      0xf3151c
00411f94  681815f300               push      0xf31518
00411f99  681415f300               push      0xf31514
00411f9e  681015f300               push      0xf31510
00411fa3  680c15f300               push      0xf3150c
00411fa8  680815f300               push      0xf31508
00411fad  8d06                     lea       eax, [esi]
00411faf  50                       push      eax
00411fb0  6868bbf400               push      0xf4bb68
00411fb5  6860bbf400               push      0xf4bb60 ; _rty7c_
00411fba  e861410100               call      0x426120 ; _sbfebc_
00411fbf  81c4a0000000             add       esp, 0xa0
00411fc5  eb24                     jmp       0x411feb
00411fc7  8b0520bbf400             mov       eax, dword ptr [0xf4bb20] ; _rdfcom_
00411fcd  89052cbbf400             mov       dword ptr [0xf4bb2c], eax
00411fd3  8b0524bbf400             mov       eax, dword ptr [0xf4bb24]
00411fd9  890530bbf400             mov       dword ptr [0xf4bb30], eax
00411fdf  8b0528bbf400             mov       eax, dword ptr [0xf4bb28]
00411fe5  890534bbf400             mov       dword ptr [0xf4bb34], eax
00411feb  d90568bbf400             fld       dword ptr [0xf4bb68]
00411ff1  d826                     fsub      dword ptr [esi]
00411ff3  8d1d80a65500             lea       ebx, [0x55a680] ; bits=3c000000, f32=8.407790785948902e-44
00411ff9  d95b6c                   fstp      dword ptr [ebx + 0x6c]
00411ffc  d9436c                   fld       dword ptr [ebx + 0x6c]
00411fff  d9fa                     fsqrt
00412001  d95b6c                   fstp      dword ptr [ebx + 0x6c]
00412004  8d4368                   lea       eax, [ebx + 0x68]
00412007  50                       push      eax
00412008  8d4364                   lea       eax, [ebx + 0x64]
0041200b  50                       push      eax
0041200c  68a4f3f200               push      0xf2f3a4
00412011  8d439c                   lea       eax, [ebx - 0x64]
00412014  50                       push      eax
00412015  8d436c                   lea       eax, [ebx + 0x6c]
00412018  50                       push      eax
00412019  6878bbf400               push      0xf4bb78
0041201e  e81d200300               call      0x444040 ; _lktab_
00412023  83c418                   add       esp, 0x18
00412026  8d4378                   lea       eax, [ebx + 0x78]
00412029  50                       push      eax
0041202a  8d4364                   lea       eax, [ebx + 0x64]
0041202d  50                       push      eax
0041202e  68b0f3f200               push      0xf2f3b0
00412033  8d439c                   lea       eax, [ebx - 0x64]
00412036  50                       push      eax
00412037  8d06                     lea       eax, [esi]
00412039  50                       push      eax
0041203a  687cbbf400               push      0xf4bb7c
0041203f  e8fc1f0300               call      0x444040 ; _lktab_
00412044  83c418                   add       esp, 0x18
00412047  68f0f3f200               push      0xf2f3f0
0041204c  68d8f3f200               push      0xf2f3d8
00412051  68d4f3f200               push      0xf2f3d4
00412056  68d0f3f200               push      0xf2f3d0
0041205b  68ccf3f200               push      0xf2f3cc
00412060  68c8f3f200               push      0xf2f3c8
00412065  68c4f3f200               push      0xf2f3c4
0041206a  68c0f3f200               push      0xf2f3c0
0041206f  68b8f3f200               push      0xf2f3b8
00412074  68b4f3f200               push      0xf2f3b4
00412079  68bcf3f200               push      0xf2f3bc
0041207e  68b0f3f200               push      0xf2f3b0
00412083  68a0f3f200               push      0xf2f3a0 ; _xs3com_
00412088  e843710300               call      0x4491d0 ; _xlkt22_
0041208d  83c434                   add       esp, 0x34
00412090  d905acf3f200             fld       dword ptr [0xf2f3ac]
00412096  d9c0                     fld       st(0)
00412098  d805b0f3f200             fadd      dword ptr [0xf2f3b0]
0041209e  d91da8f3f200             fstp      dword ptr [0xf2f3a8]
004120a4  d905a4f3f200             fld       dword ptr [0xf2f3a4]
004120aa  d8052cbbf400             fadd      dword ptr [0xf4bb2c]
004120b0  d91d64f5f200             fstp      dword ptr [0xf2f564]
004120b6  d906                     fld       dword ptr [esi]
004120b8  d9c1                     fld       st(1)
004120ba  d82e                     fsubr     dword ptr [esi]
004120bc  d90548bbf400             fld       dword ptr [0xf4bb48]
004120c2  d81500a65500             fcom      dword ptr [0x55a600] ; bits=00000000, f32=0.0
004120c8  d9ca                     fxch      st(2)
004120ca  d9cb                     fxch      st(3)
004120cc  dfe0                     fnstsw    ax
004120ce  9e                       sahf
004120cf  0f8a36010000             jp        0x41220b
004120d5  0f8630010000             jbe       0x41220b
004120db  d90550bbf400             fld       dword ptr [0xf4bb50]
004120e1  d90580bbf400             fld       dword ptr [0xf4bb80]
004120e7  d9c9                     fxch      st(1)
004120e9  d81580bbf400             fcom      dword ptr [0xf4bb80]
004120ef  d9cc                     fxch      st(4)
004120f1  d9cb                     fxch      st(3)
004120f3  d9c9                     fxch      st(1)
004120f5  d9ca                     fxch      st(2)
004120f7  dfe0                     fnstsw    ax
004120f9  9e                       sahf
004120fa  0f8a81000000             jp        0x412181
00412100  737f                     jae       0x412181
00412102  ddd8                     fstp      st(0)
00412104  dddc                     fstp      st(4)
00412106  d9cb                     fxch      st(3)
00412108  d8d3                     fcom      st(3)
0041210a  d9ca                     fxch      st(2)
0041210c  d9cb                     fxch      st(3)
0041210e  d9c9                     fxch      st(1)
00412110  d9ca                     fxch      st(2)
00412112  dfe0                     fnstsw    ax
00412114  9e                       sahf
00412115  0f8a41000000             jp        0x41215c
0041211b  733f                     jae       0x41215c
0041211d  d8e3                     fsub      st(3)
0041211f  d9c2                     fld       st(2)
00412121  d82d44f4f200             fsubr     dword ptr [0xf2f444]
00412127  d8c9                     fmul      st(1)
00412129  d9ca                     fxch      st(2)
0041212b  dee4                     fsubrp    st(4)
0041212d  d9c9                     fxch      st(1)
0041212f  d8f3                     fdiv      st(3)
00412131  dec2                     faddp     st(2)
00412133  d9c9                     fxch      st(1)
00412135  d91d54bbf400             fstp      dword ptr [0xf4bb54]
0041213b  d9054cbbf400             fld       dword ptr [0xf4bb4c]
00412141  d9c0                     fld       st(0)
00412143  d82d48f4f200             fsubr     dword ptr [0xf2f448]
00412149  deca                     fmulp     st(2)
0041214b  d9c9                     fxch      st(1)
0041214d  def2                     fdivrp    st(2)
0041214f  dec1                     faddp     st(1)
00412151  d91d58bbf400             fstp      dword ptr [0xf4bb58]
00412157  e9cf000000               jmp       0x41222b
0041215c  ddd8                     fstp      st(0)
0041215e  ddd8                     fstp      st(0)
00412160  ddd8                     fstp      st(0)
00412162  ddd8                     fstp      st(0)
00412164  8b0544f4f200             mov       eax, dword ptr [0xf2f444]
0041216a  890554bbf400             mov       dword ptr [0xf4bb54], eax
00412170  8b0548f4f200             mov       eax, dword ptr [0xf2f448]
00412176  890558bbf400             mov       dword ptr [0xf4bb58], eax
0041217c  e9aa000000               jmp       0x41222b
00412181  ddd9                     fstp      st(1)
00412183  ddd9                     fstp      st(1)
00412185  dec2                     faddp     st(2)
00412187  d9c1                     fld       st(1)
00412189  d82d68bbf400             fsubr     dword ptr [0xf4bb68]
0041218f  d84b88                   fmul      dword ptr [ebx - 0x78]
00412192  d8c2                     fadd      st(2)
00412194  d9c3                     fld       st(3)
00412196  d8d1                     fcom      st(1)
00412198  d9ca                     fxch      st(2)
0041219a  d9cb                     fxch      st(3)
0041219c  d9ca                     fxch      st(2)
0041219e  dfe0                     fnstsw    ax
004121a0  9e                       sahf
004121a1  0f8a26000000             jp        0x4121cd
004121a7  7224                     jb        0x4121cd
004121a9  ddd8                     fstp      st(0)
004121ab  ddd8                     fstp      st(0)
004121ad  ddd8                     fstp      st(0)
004121af  ddd8                     fstp      st(0)
004121b1  ddd8                     fstp      st(0)
004121b3  8b0544f4f200             mov       eax, dword ptr [0xf2f444]
004121b9  890554bbf400             mov       dword ptr [0xf4bb54], eax
004121bf  8b0548f4f200             mov       eax, dword ptr [0xf2f448]
004121c5  890558bbf400             mov       dword ptr [0xf4bb58], eax
004121cb  eb5e                     jmp       0x41222b
004121cd  d8e2                     fsub      st(2)
004121cf  d9c3                     fld       st(3)
004121d1  d82d44f4f200             fsubr     dword ptr [0xf2f444]
004121d7  dec9                     fmulp     st(1)
004121d9  d9c9                     fxch      st(1)
004121db  d8e2                     fsub      st(2)
004121dd  dcf9                     fdiv      st(1), st(0)
004121df  d9c9                     fxch      st(1)
004121e1  dec3                     faddp     st(3)
004121e3  d9ca                     fxch      st(2)
004121e5  d91d54bbf400             fstp      dword ptr [0xf4bb54]
004121eb  deea                     fsubp     st(2)
004121ed  d9054cbbf400             fld       dword ptr [0xf4bb4c]
004121f3  d9c0                     fld       st(0)
004121f5  d82d48f4f200             fsubr     dword ptr [0xf2f448]
004121fb  decb                     fmulp     st(3)
004121fd  d9ca                     fxch      st(2)
004121ff  def1                     fdivrp    st(1)
00412201  dec1                     faddp     st(1)
00412203  d91d58bbf400             fstp      dword ptr [0xf4bb58]
00412209  eb20                     jmp       0x41222b
0041220b  ddd8                     fstp      st(0)
0041220d  ddd8                     fstp      st(0)
0041220f  ddd8                     fstp      st(0)
00412211  ddd8                     fstp      st(0)
00412213  8b05ccf3f200             mov       eax, dword ptr [0xf2f3cc]
00412219  890554bbf400             mov       dword ptr [0xf4bb54], eax
0041221f  8b05d4f3f200             mov       eax, dword ptr [0xf2f3d4]
00412225  890558bbf400             mov       dword ptr [0xf4bb58], eax
0041222b  d905a4f3f200             fld       dword ptr [0xf2f3a4]
00412231  d9c0                     fld       st(0)
00412233  d80d54bbf400             fmul      dword ptr [0xf4bb54]
00412239  d8c9                     fmul      st(1)
0041223b  d905bcf3f200             fld       dword ptr [0xf2f3bc]
00412241  d9c9                     fxch      st(1)
00412243  d835bcf3f200             fdiv      dword ptr [0xf2f3bc]
00412249  d80530bbf400             fadd      dword ptr [0xf4bb30]
0041224f  d905c0f4f200             fld       dword ptr [0xf2f4c0]
00412255  d80d30bcf400             fmul      dword ptr [0xf4bc30] ; _grvcom_
0041225b  dec1                     faddp     st(1)
0041225d  d9c9                     fxch      st(1)
0041225f  d9ca                     fxch      st(2)
00412261  d9c9                     fxch      st(1)
00412263  833d74bbf40001           cmp       dword ptr [0xf4bb74], 1
0041226a  757b                     jne       0x4122e7
0041226c  ddd9                     fstp      st(1)
0041226e  ddd9                     fstp      st(1)
00412270  d90570f5f200             fld       dword ptr [0xf2f570]
00412276  d9ee                     fldz
00412278  d9c9                     fxch      st(1)
0041227a  dae9                     fucompp
0041227c  dfe0                     fnstsw    ax
0041227e  9e                       sahf
0041227f  0f8a10000000             jp        0x412295
00412285  750e                     jne       0x412295
00412287  8d0580a65500             lea       eax, [0x55a680] ; bits=3c000000, f32=8.407790785948902e-44
0041228d  8b488c                   mov       ecx, dword ptr [eax - 0x74]
00412290  89487c                   mov       dword ptr [eax + 0x7c], ecx
00412293  eb0c                     jmp       0x4122a1
00412295  8b0570f5f200             mov       eax, dword ptr [0xf2f570]
0041229b  8905fca65500             mov       dword ptr [0x55a6fc], eax ; bits=00000000, f32=0.0
004122a1  db7df0                   fstp      xword ptr [ebp - 0x10]
004122a4  8d1d80a65500             lea       ebx, [0x55a680] ; bits=3c000000, f32=8.407790785948902e-44
004122aa  8d437c                   lea       eax, [ebx + 0x7c]
004122ad  50                       push      eax
004122ae  6864f5f200               push      0xf2f564
004122b3  6860f5f200               push      0xf2f560 ; _xs4com_
004122b8  6860bbf400               push      0xf4bb60 ; _rty7c_
004122bd  e86e680100               call      0x428b30 ; _fndcde_
004122c2  83c410                   add       esp, 0x10
004122c5  8b437c                   mov       eax, dword ptr [ebx + 0x7c]
004122c8  890570f5f200             mov       dword ptr [0xf2f570], eax
004122ce  d9056cf5f200             fld       dword ptr [0xf2f56c]
004122d4  d8437c                   fadd      dword ptr [ebx + 0x7c]
004122d7  d91d68f5f200             fstp      dword ptr [0xf2f568]
004122dd  d9ee                     fldz
004122df  db6df0                   fld       xword ptr [ebp - 0x10]
004122e2  e9a9000000               jmp       0x412390
004122e7  8b056cbbf400             mov       eax, dword ptr [0xf4bb6c]
004122ed  890568f5f200             mov       dword ptr [0xf2f568], eax
004122f3  d9056cf5f200             fld       dword ptr [0xf2f56c]
004122f9  d82d6cbbf400             fsubr     dword ptr [0xf4bb6c]
004122ff  d91d70f5f200             fstp      dword ptr [0xf2f570]
00412305  d905a0bbf400             fld       dword ptr [0xf4bba0] ; _flapgate_
0041230b  d9ee                     fldz
0041230d  d9c9                     fxch      st(1)
0041230f  d81500a65500             fcom      dword ptr [0x55a600] ; bits=00000000, f32=0.0
00412315  d9c9                     fxch      st(1)
00412317  d9cc                     fxch      st(4)
00412319  d9c9                     fxch      st(1)
0041231b  d9cb                     fxch      st(3)
0041231d  d9c9                     fxch      st(1)
0041231f  d9ca                     fxch      st(2)
00412321  dfe0                     fnstsw    ax
00412323  9e                       sahf
00412324  0f8a60000000             jp        0x41238a
0041232a  765e                     jbe       0x41238a
0041232c  dddc                     fstp      st(4)
0041232e  d9ca                     fxch      st(2)
00412330  dec9                     fmulp     st(1)
00412332  8d0580a65500             lea       eax, [0x55a680] ; bits=3c000000, f32=8.407790785948902e-44
00412338  d84890                   fmul      dword ptr [eax - 0x70]
0041233b  d90500f4f200             fld       dword ptr [0xf2f400]
00412341  d9c2                     fld       st(2)
00412343  d83500f4f200             fdiv      dword ptr [0xf2f400]
00412349  d8c8                     fmul      st(0)
0041234b  deca                     fmulp     st(2)
0041234d  d9ca                     fxch      st(2)
0041234f  d84894                   fmul      dword ptr [eax - 0x6c]
00412352  d90580bbf400             fld       dword ptr [0xf4bb80]
00412358  d9fa                     fsqrt
0041235a  d95dfc                   fstp      dword ptr [ebp - 4]
0041235d  d9ca                     fxch      st(2)
0041235f  d84dfc                   fmul      dword ptr [ebp - 4]
00412362  defa                     fdivp     st(2)
00412364  d9c9                     fxch      st(1)
00412366  d9e0                     fchs
00412368  d9ea                     fldl2e
0041236a  dec9                     fmulp     st(1)
0041236c  d9c0                     fld       st(0)
0041236e  d9fc                     frndint
00412370  dce9                     fsub      st(1), st(0)
00412372  d9c9                     fxch      st(1)
00412374  d9f0                     f2xm1
00412376  d80518a65500             fadd      dword ptr [0x55a618] ; bits=0000803f, f32=1.0
0041237c  d9fd                     fscale
0041237e  ddd9                     fstp      st(1)
00412380  d95dfc                   fstp      dword ptr [ebp - 4]
00412383  d84dfc                   fmul      dword ptr [ebp - 4]
00412386  d9c9                     fxch      st(1)
00412388  eb06                     jmp       0x412390
0041238a  ddd9                     fstp      st(1)
0041238c  ddd9                     fstp      st(1)
0041238e  ddd9                     fstp      st(1)
00412390  db7de4                   fstp      xword ptr [ebp - 0x1c]
00412393  db7df0                   fstp      xword ptr [ebp - 0x10]
00412396  6898f5f200               push      0xf2f598
0041239b  6894f5f200               push      0xf2f594
004123a0  6890f5f200               push      0xf2f590
004123a5  688cf5f200               push      0xf2f58c
004123aa  6888f5f200               push      0xf2f588
004123af  6884f5f200               push      0xf2f584
004123b4  6880f5f200               push      0xf2f580
004123b9  6878f5f200               push      0xf2f578
004123be  6874f5f200               push      0xf2f574
004123c3  687cf5f200               push      0xf2f57c
004123c8  6870f5f200               push      0xf2f570
004123cd  6860f5f200               push      0xf2f560 ; _xs4com_
004123d2  e8c9910300               call      0x44b5a0 ; _xlktal_
004123d7  83c430                   add       esp, 0x30
004123da  68e0a65500               push      0x55a6e0
004123df  6860bbf400               push      0xf4bb60 ; _rty7c_
004123e4  e827a20100               call      0x42c610 ; _f4to44_
004123e9  83c408                   add       esp, 8
004123ec  d9052cf5f200             fld       dword ptr [0xf2f52c]
004123f2  d80d64f5f200             fmul      dword ptr [0xf2f564]
004123f8  d80d64f5f200             fmul      dword ptr [0xf2f564]
004123fe  d8351cf5f200             fdiv      dword ptr [0xf2f51c]
00412404  d90520f5f200             fld       dword ptr [0xf2f520]
0041240a  d80d30bcf400             fmul      dword ptr [0xf4bc30] ; _grvcom_
00412410  dec1                     faddp     st(1)
00412412  db6de4                   fld       xword ptr [ebp - 0x1c]
00412415  db6df0                   fld       xword ptr [ebp - 0x10]
00412418  dee9                     fsubp     st(1)
0041241a  def1                     fdivrp    st(1)
0041241c  d82518a65500             fsub      dword ptr [0x55a618] ; bits=0000803f, f32=1.0
00412422  5e                       pop       esi
00412423  5b                       pop       ebx
00412424  8be5                     mov       esp, ebp
00412426  5d                       pop       ebp
00412427  c3                       ret
00412428  90                       nop
00412429  8da42400000000           lea       esp, [esp]
