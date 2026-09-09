; _fhpl_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x33ee0
00433ee0  55                       push      ebp
00433ee1  8bec                     mov       ebp, esp
00433ee3  b840000000               mov       eax, 0x40
00433ee8  e813510b00               call      0x4e9000 ; __alloca_probe
00433eed  53                       push      ebx
00433eee  8b4d08                   mov       ecx, dword ptr [ebp + 8]
00433ef1  dd01                     fld       qword ptr [ecx]
00433ef3  d91d24aee900             fstp      dword ptr [0xe9ae24]
00433ef9  d90524aee900             fld       dword ptr [0xe9ae24]
00433eff  d80570aee900             fadd      dword ptr [0xe9ae70]
00433f05  d82554aee900             fsub      dword ptr [0xe9ae54]
00433f0b  d91d2caee900             fstp      dword ptr [0xe9ae2c]
00433f11  833d4caee90000           cmp       dword ptr [0xe9ae4c], 0
00433f18  7e70                     jle       0x433f8a
00433f1a  6878aee900               push      0xe9ae78
00433f1f  8d0508f65600             lea       eax, [0x56f608] ; bits=2c000000, f32=6.165713243029195e-44
00433f25  8d4898                   lea       ecx, [eax - 0x68]
00433f28  51                       push      ecx
00433f29  683caee900               push      0xe9ae3c
00433f2e  8d489c                   lea       ecx, [eax - 0x64]
00433f31  51                       push      ecx
00433f32  8d4894                   lea       ecx, [eax - 0x6c]
00433f35  51                       push      ecx
00433f36  8d48a0                   lea       ecx, [eax - 0x60]
00433f39  51                       push      ecx
00433f3a  6844aee900               push      0xe9ae44
00433f3f  8d48a8                   lea       ecx, [eax - 0x58]
00433f42  51                       push      ecx
00433f43  8d48a4                   lea       ecx, [eax - 0x5c]
00433f46  51                       push      ecx
00433f47  8d40ac                   lea       eax, [eax - 0x54]
00433f4a  50                       push      eax
00433f4b  6834aee900               push      0xe9ae34
00433f50  682caee900               push      0xe9ae2c
00433f55  684caee900               push      0xe9ae4c
00433f5a  e871520100               call      0x4491d0 ; _xlkt22_
00433f5f  83c434                   add       esp, 0x34
00433f62  d90534aee900             fld       dword ptr [0xe9ae34]
00433f68  d83d74aee900             fdivr     dword ptr [0xe9ae74]
00433f6e  d8c8                     fmul      st(0)
00433f70  d80d3caee900             fmul      dword ptr [0xe9ae3c]
00433f76  d8356caee900             fdiv      dword ptr [0xe9ae6c]
00433f7c  d80524aee900             fadd      dword ptr [0xe9ae24]
00433f82  d91d20aee900             fstp      dword ptr [0xe9ae20] ; _feccom_
00433f88  eb37                     jmp       0x433fc1
00433f8a  8d0508f65600             lea       eax, [0x56f608] ; bits=2c000000, f32=6.165713243029195e-44
00433f90  8b4888                   mov       ecx, dword ptr [eax - 0x78]
00433f93  890d34aee900             mov       dword ptr [0xe9ae34], ecx
00433f99  c7053caee90000000000     mov       dword ptr [0xe9ae3c], 0
00433fa3  8b4888                   mov       ecx, dword ptr [eax - 0x78]
00433fa6  890d44aee900             mov       dword ptr [0xe9ae44], ecx
00433fac  8b0d24aee900             mov       ecx, dword ptr [0xe9ae24]
00433fb2  890d20aee900             mov       dword ptr [0xe9ae20], ecx ; _feccom_
00433fb8  8b408c                   mov       eax, dword ptr [eax - 0x74]
00433fbb  890578aee900             mov       dword ptr [0xe9ae78], eax
00433fc1  d90540aee900             fld       dword ptr [0xe9ae40]
00433fc7  d9c0                     fld       st(0)
00433fc9  d9fa                     fsqrt
00433fcb  d95dfc                   fstp      dword ptr [ebp - 4]
00433fce  d90538aee900             fld       dword ptr [0xe9ae38]
00433fd4  d9c0                     fld       st(0)
00433fd6  d87dfc                   fdivr     dword ptr [ebp - 4]
00433fd9  d9053caee900             fld       dword ptr [0xe9ae3c]
00433fdf  d9fa                     fsqrt
00433fe1  d95dfc                   fstp      dword ptr [ebp - 4]
00433fe4  d90534aee900             fld       dword ptr [0xe9ae34]
00433fea  d87dfc                   fdivr     dword ptr [ebp - 4]
00433fed  d9c1                     fld       st(1)
00433fef  d8e1                     fsub      st(1)
00433ff1  d90574aee900             fld       dword ptr [0xe9ae74]
00433ff7  d9c9                     fxch      st(1)
00433ff9  d80d74aee900             fmul      dword ptr [0xe9ae74]
00433fff  8d1d08f65600             lea       ebx, [0x56f608] ; bits=2c000000, f32=6.165713243029195e-44
00434005  d95bb0                   fstp      dword ptr [ebx - 0x50]
00434008  d9c9                     fxch      st(1)
0043400a  dec2                     faddp     st(2)
0043400c  dcc9                     fmul      st(1), st(0)
0043400e  d9c9                     fxch      st(1)
00434010  db7df0                   fstp      xword ptr [ebp - 0x10]
00434013  d90528aee900             fld       dword ptr [0xe9ae28]
00434019  d82d20aee900             fsubr     dword ptr [0xe9ae20] ; _feccom_
0043401f  db7de4                   fstp      xword ptr [ebp - 0x1c]
00434022  d8c8                     fmul      st(0)
00434024  db7dd8                   fstp      xword ptr [ebp - 0x28]
00434027  d8c8                     fmul      st(0)
00434029  d80d6caee900             fmul      dword ptr [0xe9ae6c]
0043402f  def9                     fdivp     st(1)
00434031  db7dcc                   fstp      xword ptr [ebp - 0x34]
00434034  6884aee900               push      0xe9ae84
00434039  6848aee900               push      0xe9ae48
0043403e  6844aee900               push      0xe9ae44
00434043  e8f8fdffff               call      0x433e40 ; _gmean_
00434048  83c40c                   add       esp, 0xc
0043404b  d83d64aee900             fdivr     dword ptr [0xe9ae64]
00434051  db6dcc                   fld       xword ptr [ebp - 0x34]
00434054  dec1                     faddp     st(1)
00434056  db6dd8                   fld       xword ptr [ebp - 0x28]
00434059  dec9                     fmulp     st(1)
0043405b  db6de4                   fld       xword ptr [ebp - 0x1c]
0043405e  dee1                     fsubrp    st(1)
00434060  db7dc0                   fstp      xword ptr [ebp - 0x40]
00434063  6860aee900               push      0xe9ae60
00434068  685caee900               push      0xe9ae5c
0043406d  6868aee900               push      0xe9ae68
00434072  8d5bb0                   lea       ebx, [ebx - 0x50]
00434075  53                       push      ebx
00434076  e815fdffff               call      0x433d90 ; _facdc_
0043407b  83c410                   add       esp, 0x10
0043407e  db6df0                   fld       xword ptr [ebp - 0x10]
00434081  dec9                     fmulp     st(1)
00434083  d8356caee900             fdiv      dword ptr [0xe9ae6c]
00434089  db6dc0                   fld       xword ptr [ebp - 0x40]
0043408c  dee1                     fsubrp    st(1)
0043408e  d83520aee900             fdiv      dword ptr [0xe9ae20] ; _feccom_
00434094  5b                       pop       ebx
00434095  8be5                     mov       esp, ebp
00434097  5d                       pop       ebp
00434098  c3                       ret
00434099  8da42400000000           lea       esp, [esp]
