; _cmpcor_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x75020
00475020  81ecc4000000             sub       esp, 0xc4
00475026  55                       push      ebp
00475027  53                       push      ebx
00475028  56                       push      esi
00475029  57                       push      edi
0047502a  8b8424d8000000           mov       eax, dword ptr [esp + 0xd8]
00475031  8b8c24dc000000           mov       ecx, dword ptr [esp + 0xdc]
00475038  8b9424e0000000           mov       edx, dword ptr [esp + 0xe0]
0047503f  8944247c                 mov       dword ptr [esp + 0x7c], eax
00475043  894c2478                 mov       dword ptr [esp + 0x78], ecx
00475047  89542474                 mov       dword ptr [esp + 0x74], edx
0047504b  be00000000               mov       esi, 0
00475050  89f5                     mov       ebp, esi
00475052  8b8c24f8000000           mov       ecx, dword ptr [esp + 0xf8]
00475059  c70100000000             mov       dword ptr [ecx], 0
0047505f  8b8c24fc000000           mov       ecx, dword ptr [esp + 0xfc]
00475066  c70100000000             mov       dword ptr [ecx], 0
0047506c  8b8c2400010000           mov       ecx, dword ptr [esp + 0x100]
00475073  c70100000000             mov       dword ptr [ecx], 0
00475079  8b442478                 mov       eax, dword ptr [esp + 0x78]
0047507d  8b08                     mov       ecx, dword ptr [eax]
0047507f  83f900                   cmp       ecx, 0
00475082  894c246c                 mov       dword ptr [esp + 0x6c], ecx
00475086  0f8e00030000             jle       0x47538c
0047508c  c705e4ec550001000000     mov       dword ptr [0x55ece4], 1 ; bits=00000000, f32=0.0
00475096  8b05e4ec5500             mov       eax, dword ptr [0x55ece4] ; bits=00000000, f32=0.0
0047509c  8d0cc0                   lea       ecx, [eax + eax*8]
0047509f  8b9424e4000000           mov       edx, dword ptr [esp + 0xe4]
004750a6  8b5c8ae4                 mov       ebx, dword ptr [edx + ecx*4 - 0x1c]
004750aa  83fb00                   cmp       ebx, 0
004750ad  89442468                 mov       dword ptr [esp + 0x68], eax
004750b1  894c2464                 mov       dword ptr [esp + 0x64], ecx
004750b5  89542460                 mov       dword ptr [esp + 0x60], edx
004750b9  895c245c                 mov       dword ptr [esp + 0x5c], ebx
004750bd  0f8fb1020000             jg        0x475374
004750c3  8b4c2460                 mov       ecx, dword ptr [esp + 0x60]
004750c7  8b442464                 mov       eax, dword ptr [esp + 0x64]
004750cb  8b5c81ec                 mov       ebx, dword ptr [ecx + eax*4 - 0x14]
004750cf  43                       inc       ebx
004750d0  d9049df84baa01           fld       dword ptr [ebx*4 + 0x1aa4bf8]
004750d7  837c245c00               cmp       dword ptr [esp + 0x5c], 0
004750dc  0f8d95000000             jge       0x475177
004750e2  d9c0                     fld       st(0)
004750e4  d9e1                     fabs
004750e6  d905b83bfb01             fld       dword ptr [0x1fb3bb8]
004750ec  dff1                     fcompi    st(1)
004750ee  ddd8                     fstp      st(0)
004750f0  0f8a0b000000             jp        0x475101
004750f6  7609                     jbe       0x475101
004750f8  d9ee                     fldz
004750fa  d9c9                     fxch      st(1)
004750fc  e907010000               jmp       0x475208
00475101  8b442468                 mov       eax, dword ptr [esp + 0x68]
00475105  d904851cab0202           fld       dword ptr [eax*4 + 0x202ab1c]
0047510c  d904855c07fd01           fld       dword ptr [eax*4 + 0x1fd075c]
00475113  d9e1                     fabs
00475115  d905c43bfb01             fld       dword ptr [0x1fb3bc4]
0047511b  d80c851cab0202           fmul      dword ptr [eax*4 + 0x202ab1c]
00475122  d8d1                     fcom      st(1)
00475124  d9c9                     fxch      st(1)
00475126  dbbc24bc000000           fstp      xword ptr [esp + 0xbc]
0047512d  d9c9                     fxch      st(1)
0047512f  dbbc24b0000000           fstp      xword ptr [esp + 0xb0]
00475136  dfe0                     fnstsw    ax
00475138  66a90041                 test      ax, 0x4100
0047513c  7409                     je        0x475147
0047513e  ddd8                     fstp      st(0)
00475140  dbac24bc000000           fld       xword ptr [esp + 0xbc]
00475147  d815c83bfb01             fcom      dword ptr [0x1fb3bc8]
0047514d  dfe0                     fnstsw    ax
0047514f  66a90041                 test      ax, 0x4100
00475153  7408                     je        0x47515d
00475155  ddd8                     fstp      st(0)
00475157  d905c83bfb01             fld       dword ptr [0x1fb3bc8]
0047515d  dbac24b0000000           fld       xword ptr [esp + 0xb0]
00475164  d8ca                     fmul      st(2)
00475166  def1                     fdivrp    st(1)
00475168  d9e1                     fabs
0047516a  d80d98eb5500             fmul      dword ptr [0x55eb98] ; bits=00004040, f32=3.0
00475170  d9c9                     fxch      st(1)
00475172  e991000000               jmp       0x475208
00475177  8b442468                 mov       eax, dword ptr [esp + 0x68]
0047517b  d904851c9e0002           fld       dword ptr [eax*4 + 0x2009e1c]
00475182  d9ee                     fldz
00475184  dbf1                     fcomi     st(1)
00475186  d9c9                     fxch      st(1)
00475188  dbbc24a4000000           fstp      xword ptr [esp + 0xa4]
0047518f  dbbc2498000000           fstp      xword ptr [esp + 0x98]
00475196  0f8a5d000000             jp        0x4751f9
0047519c  725b                     jb        0x4751f9
0047519e  dbbc24c8000000           fstp      xword ptr [esp + 0xc8]
004751a5  68e4ec5500               push      0x55ece4
004751aa  6a05                     push      5
004751ac  6808ed5500               push      0x55ed08
004751b1  e80a81ffff               call      0x46d2c0 ; _getusn_
004751b6  83c40c                   add       esp, 0xc
004751b9  68acec5500               push      0x55ecac
004751be  e83d740400               call      0x4bc600 ; _jwe_ilst
004751c3  83c404                   add       esp, 4
004751c6  dbac24c8000000           fld       xword ptr [esp + 0xc8]
004751cd  d9e1                     fabs
004751cf  d9059ceb5500             fld       dword ptr [0x55eb9c] ; bits=0ad7233c, f32=0.009999999776482582
004751d5  dff1                     fcompi    st(1)
004751d7  ddd8                     fstp      st(0)
004751d9  dbac24c8000000           fld       xword ptr [esp + 0xc8]
004751e0  0f8a0d000000             jp        0x4751f3
004751e6  760b                     jbe       0x4751f3
004751e8  dbac2498000000           fld       xword ptr [esp + 0x98]
004751ef  d9c9                     fxch      st(1)
004751f1  eb15                     jmp       0x475208
004751f3  d9e8                     fld1
004751f5  d9c9                     fxch      st(1)
004751f7  eb0f                     jmp       0x475208
004751f9  d9c0                     fld       st(0)
004751fb  d9e1                     fabs
004751fd  dbac24a4000000           fld       xword ptr [esp + 0xa4]
00475204  def9                     fdivp     st(1)
00475206  d9c9                     fxch      st(1)
00475208  8b8424f8000000           mov       eax, dword ptr [esp + 0xf8]
0047520f  d900                     fld       dword ptr [eax]
00475211  dff2                     fcompi    st(2)
00475213  89442458                 mov       dword ptr [esp + 0x58], eax
00475217  0f8a33000000             jp        0x475250
0047521d  7731                     ja        0x475250
0047521f  8b442458                 mov       eax, dword ptr [esp + 0x58]
00475223  d9c9                     fxch      st(1)
00475225  d910                     fst       dword ptr [eax]
00475227  d9c9                     fxch      st(1)
00475229  8b8424fc000000           mov       eax, dword ptr [esp + 0xfc]
00475230  c70000000000             mov       dword ptr [eax], 0
00475236  8b05e4ec5500             mov       eax, dword ptr [0x55ece4] ; bits=00000000, f32=0.0
0047523c  f7d8                     neg       eax
0047523e  8b8c2400010000           mov       ecx, dword ptr [esp + 0x100]
00475245  8901                     mov       dword ptr [ecx], eax
00475247  8b842404010000           mov       eax, dword ptr [esp + 0x104]
0047524e  8918                     mov       dword ptr [eax], ebx
00475250  8b8424ec000000           mov       eax, dword ptr [esp + 0xec]
00475257  d900                     fld       dword ptr [eax]
00475259  dbf2                     fcomi     st(2)
0047525b  dbbc248c000000           fstp      xword ptr [esp + 0x8c]
00475262  0f8a26000000             jp        0x47528e
00475268  7324                     jae       0x47528e
0047526a  46                       inc       esi
0047526b  8b8424f0000000           mov       eax, dword ptr [esp + 0xf0]
00475272  d900                     fld       dword ptr [eax]
00475274  dff2                     fcompi    st(2)
00475276  ddd9                     fstp      st(1)
00475278  0f8a03000000             jp        0x475281
0047527e  7301                     jae       0x475281
00475280  45                       inc       ebp
00475281  c7049df852ad0100000000   mov       dword ptr [ebx*4 + 0x1ad52f8], 0
0047528c  eb0d                     jmp       0x47529b
0047528e  ddd9                     fstp      st(1)
00475290  c7049df852ad0101000000   mov       dword ptr [ebx*4 + 0x1ad52f8], 1
0047529b  d80c9d78cfab01           fmul      dword ptr [ebx*4 + 0x1abcf78]
004752a2  8b05e4ec5500             mov       eax, dword ptr [0x55ece4] ; bits=00000000, f32=0.0
004752a8  d91c85dc4c2101           fstp      dword ptr [eax*4 + 0x1214cdc]
004752af  d9049df44baa01           fld       dword ptr [ebx*4 + 0x1aa4bf4]
004752b6  d904855c14ff01           fld       dword ptr [eax*4 + 0x1ff145c]
004752bd  d9e1                     fabs
004752bf  8b8c24e8000000           mov       ecx, dword ptr [esp + 0xe8]
004752c6  d801                     fadd      dword ptr [ecx]
004752c8  d83c9df44baa01           fdivr     dword ptr [ebx*4 + 0x1aa4bf4]
004752cf  d9e1                     fabs
004752d1  8b8c24f8000000           mov       ecx, dword ptr [esp + 0xf8]
004752d8  d901                     fld       dword ptr [ecx]
004752da  dff1                     fcompi    st(1)
004752dc  d9c9                     fxch      st(1)
004752de  89442454                 mov       dword ptr [esp + 0x54], eax
004752e2  894c2450                 mov       dword ptr [esp + 0x50], ecx
004752e6  0f8a32000000             jp        0x47531e
004752ec  7730                     ja        0x47531e
004752ee  8b442450                 mov       eax, dword ptr [esp + 0x50]
004752f2  d9c9                     fxch      st(1)
004752f4  d910                     fst       dword ptr [eax]
004752f6  d9c9                     fxch      st(1)
004752f8  8b8424fc000000           mov       eax, dword ptr [esp + 0xfc]
004752ff  c70000000000             mov       dword ptr [eax], 0
00475305  8b842400010000           mov       eax, dword ptr [esp + 0x100]
0047530c  8b4c2454                 mov       ecx, dword ptr [esp + 0x54]
00475310  8908                     mov       dword ptr [eax], ecx
00475312  8d43ff                   lea       eax, [ebx - 1]
00475315  8b8c2404010000           mov       ecx, dword ptr [esp + 0x104]
0047531c  8901                     mov       dword ptr [ecx], eax
0047531e  dbac248c000000           fld       xword ptr [esp + 0x8c]
00475325  dff2                     fcompi    st(2)
00475327  0f8a26000000             jp        0x475353
0047532d  7324                     jae       0x475353
0047532f  46                       inc       esi
00475330  8b8424f0000000           mov       eax, dword ptr [esp + 0xf0]
00475337  d900                     fld       dword ptr [eax]
00475339  dff2                     fcompi    st(2)
0047533b  ddd9                     fstp      st(1)
0047533d  0f8a03000000             jp        0x475346
00475343  7301                     jae       0x475346
00475345  45                       inc       ebp
00475346  c7049df452ad0100000000   mov       dword ptr [ebx*4 + 0x1ad52f4], 0
00475351  eb0d                     jmp       0x475360
00475353  ddd9                     fstp      st(1)
00475355  c7049df452ad0101000000   mov       dword ptr [ebx*4 + 0x1ad52f4], 1
00475360  d80c9d74cfab01           fmul      dword ptr [ebx*4 + 0x1abcf74]
00475367  8b05e4ec5500             mov       eax, dword ptr [0x55ece4] ; bits=00000000, f32=0.0
0047536d  d91c859cc92001           fstp      dword ptr [eax*4 + 0x120c99c]
00475374  8b05e4ec5500             mov       eax, dword ptr [0x55ece4] ; bits=00000000, f32=0.0
0047537a  40                       inc       eax
0047537b  8905e4ec5500             mov       dword ptr [0x55ece4], eax ; bits=00000000, f32=0.0
00475381  836c246c01               sub       dword ptr [esp + 0x6c], 1
00475386  0f850afdffff             jne       0x475096
0047538c  8b44247c                 mov       eax, dword ptr [esp + 0x7c]
00475390  8b08                     mov       ecx, dword ptr [eax]
00475392  83f900                   cmp       ecx, 0
00475395  894c244c                 mov       dword ptr [esp + 0x4c], ecx
00475399  0f8ed6020000             jle       0x475675
0047539f  b801000000               mov       eax, 1
004753a4  89442448                 mov       dword ptr [esp + 0x48], eax
004753a8  8b442448                 mov       eax, dword ptr [esp + 0x48]
004753ac  89c2                     mov       edx, eax
004753ae  c1e202                   shl       edx, 2
004753b1  8b4c2474                 mov       ecx, dword ptr [esp + 0x74]
004753b5  8b5cd1f8                 mov       ebx, dword ptr [ecx + edx*8 - 8]
004753b9  8b7cd1e0                 mov       edi, dword ptr [ecx + edx*8 - 0x20]
004753bd  83fb00                   cmp       ebx, 0
004753c0  89542444                 mov       dword ptr [esp + 0x44], edx
004753c4  897c2440                 mov       dword ptr [esp + 0x40], edi
004753c8  7e27                     jle       0x4753f1
004753ca  b801000000               mov       eax, 1
004753cf  8b542474                 mov       edx, dword ptr [esp + 0x74]
004753d3  8b4c2444                 mov       ecx, dword ptr [esp + 0x44]
004753d7  8b7ccae8                 mov       edi, dword ptr [edx + ecx*8 - 0x18]
004753db  8944243c                 mov       dword ptr [esp + 0x3c], eax
004753df  8b44caec                 mov       eax, dword ptr [edx + ecx*8 - 0x14]
004753e3  897c2438                 mov       dword ptr [esp + 0x38], edi
004753e7  89442434                 mov       dword ptr [esp + 0x34], eax
004753eb  897c2430                 mov       dword ptr [esp + 0x30], edi
004753ef  eb27                     jmp       0x475418
004753f1  b9ffffffff               mov       ecx, 0xffffffff
004753f6  8b542474                 mov       edx, dword ptr [esp + 0x74]
004753fa  8b442444                 mov       eax, dword ptr [esp + 0x44]
004753fe  8b7cc2ec                 mov       edi, dword ptr [edx + eax*8 - 0x14]
00475402  894c243c                 mov       dword ptr [esp + 0x3c], ecx
00475406  8b4cc2e8                 mov       ecx, dword ptr [edx + eax*8 - 0x18]
0047540a  894c2438                 mov       dword ptr [esp + 0x38], ecx
0047540e  f7db                     neg       ebx
00475410  894c2434                 mov       dword ptr [esp + 0x34], ecx
00475414  897c2430                 mov       dword ptr [esp + 0x30], edi
00475418  8b442430                 mov       eax, dword ptr [esp + 0x30]
0047541c  8944242c                 mov       dword ptr [esp + 0x2c], eax
00475420  8b4c243c                 mov       ecx, dword ptr [esp + 0x3c]
00475424  894c2428                 mov       dword ptr [esp + 0x28], ecx
00475428  8b542434                 mov       edx, dword ptr [esp + 0x34]
0047542c  29c2                     sub       edx, eax
0047542e  89d0                     mov       eax, edx
00475430  01c8                     add       eax, ecx
00475432  99                       cdq
00475433  f7f9                     idiv      ecx
00475435  3d00000000               cmp       eax, 0
0047543a  89442424                 mov       dword ptr [esp + 0x24], eax
0047543e  0f8e22020000             jle       0x475666
00475444  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
00475448  89c1                     mov       ecx, eax
0047544a  8b9424f4000000           mov       edx, dword ptr [esp + 0xf4]
00475451  d902                     fld       dword ptr [edx]
00475453  dbbc2480000000           fstp      xword ptr [esp + 0x80]
0047545a  8b542438                 mov       edx, dword ptr [esp + 0x38]
0047545e  89d7                     mov       edi, edx
00475460  8b442440                 mov       eax, dword ptr [esp + 0x40]
00475464  29c7                     sub       edi, eax
00475466  8b9424ec000000           mov       edx, dword ptr [esp + 0xec]
0047546d  d902                     fld       dword ptr [edx]
0047546f  8b9424e8000000           mov       edx, dword ptr [esp + 0xe8]
00475476  d902                     fld       dword ptr [edx]
00475478  8b542438                 mov       edx, dword ptr [esp + 0x38]
0047547c  29d0                     sub       eax, edx
0047547e  8d5301                   lea       edx, [ebx + 1]
00475481  89442420                 mov       dword ptr [esp + 0x20], eax
00475485  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
00475489  29c7                     sub       edi, eax
0047548b  8954241c                 mov       dword ptr [esp + 0x1c], edx
0047548f  8b542420                 mov       edx, dword ptr [esp + 0x20]
00475493  01c2                     add       edx, eax
00475495  89542420                 mov       dword ptr [esp + 0x20], edx
00475499  897c2418                 mov       dword ptr [esp + 0x18], edi
0047549d  d9049dfc4baa01           fld       dword ptr [ebx*4 + 0x1aa4bfc]
004754a4  d9049d7ccfab01           fld       dword ptr [ebx*4 + 0x1abcf7c]
004754ab  d80c9dfc4baa01           fmul      dword ptr [ebx*4 + 0x1aa4bfc]
004754b2  d91c8dbcdae301           fstp      dword ptr [ecx*4 + 0x1e3dabc]
004754b9  d9c0                     fld       st(0)
004754bb  d9e1                     fabs
004754bd  dbac2480000000           fld       xword ptr [esp + 0x80]
004754c4  dff1                     fcompi    st(1)
004754c6  ddd8                     fstp      st(0)
004754c8  d9ca                     fxch      st(2)
004754ca  d9c9                     fxch      st(1)
004754cc  0f8a0a000000             jp        0x4754dc
004754d2  7608                     jbe       0x4754dc
004754d4  ddda                     fstp      st(2)
004754d6  d9ee                     fldz
004754d8  d9ca                     fxch      st(2)
004754da  eb14                     jmp       0x4754f0
004754dc  d9ca                     fxch      st(2)
004754de  d80c8da435f101           fmul      dword ptr [ecx*4 + 0x1f135a4]
004754e5  d8348de484e901           fdiv      dword ptr [ecx*4 + 0x1e984e4]
004754ec  d9e1                     fabs
004754ee  d9ca                     fxch      st(2)
004754f0  8b8424f8000000           mov       eax, dword ptr [esp + 0xf8]
004754f7  d900                     fld       dword ptr [eax]
004754f9  dff3                     fcompi    st(3)
004754fb  89442414                 mov       dword ptr [esp + 0x14], eax
004754ff  0f8a3c000000             jp        0x475541
00475505  773a                     ja        0x475541
00475507  8b442414                 mov       eax, dword ptr [esp + 0x14]
0047550b  d9ca                     fxch      st(2)
0047550d  d910                     fst       dword ptr [eax]
0047550f  d9ca                     fxch      st(2)
00475511  8b8424fc000000           mov       eax, dword ptr [esp + 0xfc]
00475518  8b542448                 mov       edx, dword ptr [esp + 0x48]
0047551c  8910                     mov       dword ptr [eax], edx
0047551e  8b842404010000           mov       eax, dword ptr [esp + 0x104]
00475525  8b7c241c                 mov       edi, dword ptr [esp + 0x1c]
00475529  8938                     mov       dword ptr [eax], edi
0047552b  8b842410010000           mov       eax, dword ptr [esp + 0x110]
00475532  8908                     mov       dword ptr [eax], ecx
00475534  8b842400010000           mov       eax, dword ptr [esp + 0x100]
0047553b  8b542418                 mov       edx, dword ptr [esp + 0x18]
0047553f  8910                     mov       dword ptr [eax], edx
00475541  d9ca                     fxch      st(2)
00475543  dbf1                     fcomi     st(1)
00475545  d9ca                     fxch      st(2)
00475547  0f8a28000000             jp        0x475575
0047554d  7626                     jbe       0x475575
0047554f  46                       inc       esi
00475550  8b8424f0000000           mov       eax, dword ptr [esp + 0xf0]
00475557  d900                     fld       dword ptr [eax]
00475559  dff3                     fcompi    st(3)
0047555b  ddda                     fstp      st(2)
0047555d  d9c9                     fxch      st(1)
0047555f  0f8a03000000             jp        0x475568
00475565  7301                     jae       0x475568
00475567  45                       inc       ebp
00475568  c7049dfc52ad0100000000   mov       dword ptr [ebx*4 + 0x1ad52fc], 0
00475573  eb0f                     jmp       0x475584
00475575  ddda                     fstp      st(2)
00475577  c7049dfc52ad0101000000   mov       dword ptr [ebx*4 + 0x1ad52fc], 1
00475582  d9c9                     fxch      st(1)
00475584  d9049d78cfab01           fld       dword ptr [ebx*4 + 0x1abcf78]
0047558b  d80c9df84baa01           fmul      dword ptr [ebx*4 + 0x1aa4bf8]
00475592  d91c8d7c57e301           fstp      dword ptr [ecx*4 + 0x1e3577c]
00475599  d9048de4abef01           fld       dword ptr [ecx*4 + 0x1efabe4]
004755a0  d9e1                     fabs
004755a2  d8c1                     fadd      st(1)
004755a4  d83c9df84baa01           fdivr     dword ptr [ebx*4 + 0x1aa4bf8]
004755ab  d9e1                     fabs
004755ad  8b8424f8000000           mov       eax, dword ptr [esp + 0xf8]
004755b4  d900                     fld       dword ptr [eax]
004755b6  dff1                     fcompi    st(1)
004755b8  d9ca                     fxch      st(2)
004755ba  d9c9                     fxch      st(1)
004755bc  89442410                 mov       dword ptr [esp + 0x10], eax
004755c0  0f8a38000000             jp        0x4755fe
004755c6  7736                     ja        0x4755fe
004755c8  8b442410                 mov       eax, dword ptr [esp + 0x10]
004755cc  d9ca                     fxch      st(2)
004755ce  d910                     fst       dword ptr [eax]
004755d0  d9ca                     fxch      st(2)
004755d2  8b8424fc000000           mov       eax, dword ptr [esp + 0xfc]
004755d9  8b542448                 mov       edx, dword ptr [esp + 0x48]
004755dd  8910                     mov       dword ptr [eax], edx
004755df  8b842404010000           mov       eax, dword ptr [esp + 0x104]
004755e6  8918                     mov       dword ptr [eax], ebx
004755e8  8b842410010000           mov       eax, dword ptr [esp + 0x110]
004755ef  8908                     mov       dword ptr [eax], ecx
004755f1  8b842400010000           mov       eax, dword ptr [esp + 0x100]
004755f8  8b7c2420                 mov       edi, dword ptr [esp + 0x20]
004755fc  8938                     mov       dword ptr [eax], edi
004755fe  d9ca                     fxch      st(2)
00475600  dbf1                     fcomi     st(1)
00475602  d9ca                     fxch      st(2)
00475604  0f8a28000000             jp        0x475632
0047560a  7626                     jbe       0x475632
0047560c  46                       inc       esi
0047560d  8b8424f0000000           mov       eax, dword ptr [esp + 0xf0]
00475614  d900                     fld       dword ptr [eax]
00475616  dff3                     fcompi    st(3)
00475618  ddda                     fstp      st(2)
0047561a  d9c9                     fxch      st(1)
0047561c  0f8a03000000             jp        0x475625
00475622  7301                     jae       0x475625
00475624  45                       inc       ebp
00475625  c7049df852ad0100000000   mov       dword ptr [ebx*4 + 0x1ad52f8], 0
00475630  eb0f                     jmp       0x475641
00475632  ddda                     fstp      st(2)
00475634  c7049df852ad0101000000   mov       dword ptr [ebx*4 + 0x1ad52f8], 1
0047563f  d9c9                     fxch      st(1)
00475641  83c302                   add       ebx, 2
00475644  8344241c02               add       dword ptr [esp + 0x1c], 2
00475649  8b442428                 mov       eax, dword ptr [esp + 0x28]
0047564d  01c1                     add       ecx, eax
0047564f  01442420                 add       dword ptr [esp + 0x20], eax
00475653  29442418                 sub       dword ptr [esp + 0x18], eax
00475657  836c242401               sub       dword ptr [esp + 0x24], 1
0047565c  0f853bfeffff             jne       0x47549d
00475662  ddd8                     fstp      st(0)
00475664  ddd8                     fstp      st(0)
00475666  ff442448                 inc       dword ptr [esp + 0x48]
0047566a  836c244c01               sub       dword ptr [esp + 0x4c], 1
0047566f  0f8533fdffff             jne       0x4753a8
00475675  8b842408010000           mov       eax, dword ptr [esp + 0x108]
0047567c  8930                     mov       dword ptr [eax], esi
0047567e  8b84240c010000           mov       eax, dword ptr [esp + 0x10c]
00475685  8928                     mov       dword ptr [eax], ebp
00475687  b800000000               mov       eax, 0
0047568c  5f                       pop       edi
0047568d  5e                       pop       esi
0047568e  5b                       pop       ebx
0047568f  5d                       pop       ebp
00475690  81c4c4000000             add       esp, 0xc4
00475696  c3                       ret
00475697  8bff                     mov       edi, edi
00475699  8da42400000000           lea       esp, [esp]
