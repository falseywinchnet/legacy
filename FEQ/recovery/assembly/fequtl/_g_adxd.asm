; _g_adxd
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xa1180
004a1180  55                       push      ebp
004a1181  8bec                     mov       ebp, esp
004a1183  83ec70                   sub       esp, 0x70
004a1186  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
004a1189  8b4508                   mov       eax, dword ptr [ebp + 8]
004a118c  53                       push      ebx
004a118d  33db                     xor       ebx, ebx
004a118f  8b11                     mov       edx, dword ptr [ecx]
004a1191  56                       push      esi
004a1192  dd00                     fld       qword ptr [eax]
004a1194  8b4104                   mov       eax, dword ptr [ecx + 4]
004a1197  8955f4                   mov       dword ptr [ebp - 0xc], edx
004a119a  dd55dc                   fst       qword ptr [ebp - 0x24]
004a119d  8945f8                   mov       dword ptr [ebp - 8], eax
004a11a0  57                       push      edi
004a11a1  dd45f4                   fld       qword ptr [ebp - 0xc]
004a11a4  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a11aa  895dfc                   mov       dword ptr [ebp - 4], ebx
004a11ad  dfe0                     fnstsw    ax
004a11af  f6c444                   test      ah, 0x44
004a11b2  0f8b3a040000             jnp       0x4a15f2
004a11b8  bf94ed5b00               mov       edi, 0x5bed94
004a11bd  be0a000000               mov       esi, 0xa
004a11c2  8b55f8                   mov       edx, dword ptr [ebp - 8]
004a11c5  8b4df4                   mov       ecx, dword ptr [ebp - 0xc]
004a11c8  8bc2                     mov       eax, edx
004a11ca  894dbc                   mov       dword ptr [ebp - 0x44], ecx
004a11cd  3d00002040               cmp       eax, 0x40200000
004a11d2  8955c0                   mov       dword ptr [ebp - 0x40], edx
004a11d5  7209                     jb        0x4a11e0
004a11d7  7525                     jne       0x4a11fe
004a11d9  8bc1                     mov       eax, ecx
004a11db  83f801                   cmp       eax, 1
004a11de  751e                     jne       0x4a11fe
004a11e0  dd45f4                   fld       qword ptr [ebp - 0xc]
004a11e3  e8707f0400               call      0x4e9158 ; __ftol
004a11e8  8bc8                     mov       ecx, eax
004a11ea  894d08                   mov       dword ptr [ebp + 8], ecx
004a11ed  db4508                   fild      dword ptr [ebp + 8]
004a11f0  dc5df4                   fcomp     qword ptr [ebp - 0xc]
004a11f3  dfe0                     fnstsw    ax
004a11f5  f6c444                   test      ah, 0x44
004a11f8  0f8b03040000             jnp       0x4a1601
004a11fe  dc1560dc5400             fcom      qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a1204  dfe0                     fnstsw    ax
004a1206  f6c405                   test      ah, 5
004a1209  0f8a8e010000             jp        0x4a139d
004a120f  8d45f4                   lea       eax, [ebp - 0xc]
004a1212  ddd8                     fstp      st(0)
004a1214  50                       push      eax
004a1215  e8b65a0500               call      0x4f6cd0 ; _f_dint
004a121a  dc5df4                   fcomp     qword ptr [ebp - 0xc]
004a121d  83c404                   add       esp, 4
004a1220  dfe0                     fnstsw    ax
004a1222  f6c444                   test      ah, 0x44
004a1225  7a61                     jp        0x4a1288
004a1227  8b55f8                   mov       edx, dword ptr [ebp - 8]
004a122a  8b45f4                   mov       eax, dword ptr [ebp - 0xc]
004a122d  dd45dc                   fld       qword ptr [ebp - 0x24]
004a1230  8d4dfc                   lea       ecx, [ebp - 4]
004a1233  51                       push      ecx
004a1234  52                       push      edx
004a1235  50                       push      eax
004a1236  d9e0                     fchs
004a1238  83ec08                   sub       esp, 8
004a123b  dd1c24                   fstp      qword ptr [esp]
004a123e  e81d040000               call      0x4a1660 ; _jwe_gpwd
004a1243  8b45fc                   mov       eax, dword ptr [ebp - 4]
004a1246  83c414                   add       esp, 0x14
004a1249  dd5db4                   fstp      qword ptr [ebp - 0x4c]
004a124c  3bc3                     cmp       eax, ebx
004a124e  0f8585010000             jne       0x4a13d9
004a1254  dd45f4                   fld       qword ptr [ebp - 0xc]
004a1257  dc0d88025500             fmul      qword ptr [0x550288] ; __real@3fe0000000000000, bits=000000000000e03f, f64=0.5
004a125d  8d4dc4                   lea       ecx, [ebp - 0x3c]
004a1260  51                       push      ecx
004a1261  dd5dc4                   fstp      qword ptr [ebp - 0x3c]
004a1264  e8675a0500               call      0x4f6cd0 ; _f_dint
004a1269  dd45c4                   fld       qword ptr [ebp - 0x3c]
004a126c  ded9                     fcompp
004a126e  dd45b4                   fld       qword ptr [ebp - 0x4c]
004a1271  83c404                   add       esp, 4
004a1274  dfe0                     fnstsw    ax
004a1276  f6c444                   test      ah, 0x44
004a1279  0f8bcd030000             jnp       0x4a164c
004a127f  5f                       pop       edi
004a1280  5e                       pop       esi
004a1281  d9e0                     fchs
004a1283  5b                       pop       ebx
004a1284  8be5                     mov       esp, ebp
004a1286  5d                       pop       ebp
004a1287  c3                       ret
004a1288  391d2828b300             cmp       dword ptr [0xb32828], ebx ; _jwe_x_init
004a128e  751f                     jne       0x4a12af
004a1290  8d4da8                   lea       ecx, [ebp - 0x58]
004a1293  c7052828b30002000000     mov       dword ptr [0xb32828], 2 ; _jwe_x_init
004a129d  51                       push      ecx
004a129e  895da8                   mov       dword ptr [ebp - 0x58], ebx
004a12a1  895dac                   mov       dword ptr [ebp - 0x54], ebx
004a12a4  895db0                   mov       dword ptr [ebp - 0x50], ebx
004a12a7  e8a49d0000               call      0x4ab050 ; _jwe_xint
004a12ac  83c404                   add       esp, 4
004a12af  9b                       wait
004a12b0  803d5aef5b0001           cmp       byte ptr [0x5bef5a], 1
004a12b7  0f85cb000000             jne       0x4a1388
004a12bd  381dc4ec5b00             cmp       byte ptr [0x5becc4], bl
004a12c3  0f85bf000000             jne       0x4a1388
004a12c9  dd45dc                   fld       qword ptr [ebp - 0x24]
004a12cc  8d55e4                   lea       edx, [ebp - 0x1c]
004a12cf  8d45ec                   lea       eax, [ebp - 0x14]
004a12d2  dd55cc                   fst       qword ptr [ebp - 0x34]
004a12d5  dd45f4                   fld       qword ptr [ebp - 0xc]
004a12d8  891530ed5b00             mov       dword ptr [0x5bed30], edx ; bits=00000000, f32=0.0
004a12de  8d4dcc                   lea       ecx, [ebp - 0x34]
004a12e1  dd55d4                   fst       qword ptr [ebp - 0x2c]
004a12e4  d9c9                     fxch      st(1)
004a12e6  dd5de4                   fstp      qword ptr [ebp - 0x1c]
004a12e9  8d55d4                   lea       edx, [ebp - 0x2c]
004a12ec  6844ed5b00               push      0x5bed44
004a12f1  dd5dec                   fstp      qword ptr [ebp - 0x14]
004a12f4  893d28ed5b00             mov       dword ptr [0x5bed28], edi ; bits=94ed5b00, f32=8.442257122977436e-39
004a12fa  a334ed5b00               mov       dword ptr [0x5bed34], eax ; bits=00000000, f32=0.0
004a12ff  c70544ed5b000b010000     mov       dword ptr [0x5bed44], 0x10b ; bits=00000000, f32=0.0
004a1309  881d48ed5b00             mov       byte ptr [0x5bed48], bl
004a130f  881d49ed5b00             mov       byte ptr [0x5bed49], bl
004a1315  891d4ced5b00             mov       dword ptr [0x5bed4c], ebx ; bits=00000000, f32=0.0
004a131b  891d54ed5b00             mov       dword ptr [0x5bed54], ebx ; bits=00000000, f32=0.0
004a1321  881d58ed5b00             mov       byte ptr [0x5bed58], bl
004a1327  881d59ed5b00             mov       byte ptr [0x5bed59], bl
004a132d  891d60ed5b00             mov       dword ptr [0x5bed60], ebx ; bits=00000000, f32=0.0
004a1333  c70568ed5b0002000000     mov       dword ptr [0x5bed68], 2 ; bits=00000000, f32=0.0
004a133d  890d6ced5b00             mov       dword ptr [0x5bed6c], ecx ; bits=00000000, f32=0.0
004a1343  66893570ed5b00           mov       word ptr [0x5bed70], si ; bits=0000
004a134a  66891d72ed5b00           mov       word ptr [0x5bed72], bx ; bits=0000
004a1351  891574ed5b00             mov       dword ptr [0x5bed74], edx ; bits=00000000, f32=0.0
004a1357  66893578ed5b00           mov       word ptr [0x5bed78], si ; bits=0000
004a135e  66891d7aed5b00           mov       word ptr [0x5bed7a], bx ; bits=0000
004a1365  ff1574f35b00             call      dword ptr [0x5bf374] ; bits=80524c00, f32=7.009093131573872e-39
004a136b  a194ed5b00               mov       eax, dword ptr [0x5bed94] ; bits=00000000, f32=0.0
004a1370  83c404                   add       esp, 4
004a1373  3bc3                     cmp       eax, ebx
004a1375  7411                     je        0x4a1388
004a1377  8b45ec                   mov       eax, dword ptr [ebp - 0x14]
004a137a  8b4df0                   mov       ecx, dword ptr [ebp - 0x10]
004a137d  8945f4                   mov       dword ptr [ebp - 0xc], eax
004a1380  894df8                   mov       dword ptr [ebp - 8], ecx
004a1383  e950020000               jmp       0x4a15d8
004a1388  803dc5ec5b0001           cmp       byte ptr [0x5becc5], 1
004a138f  0f8481020000             je        0x4a1616
004a1395  dd45dc                   fld       qword ptr [ebp - 0x24]
004a1398  d9e0                     fchs
004a139a  dd55dc                   fst       qword ptr [ebp - 0x24]
004a139d  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a13a3  dfe0                     fnstsw    ax
004a13a5  2500410000               and       eax, 0x4100
004a13aa  0f852d010000             jne       0x4a14dd
004a13b0  8b45f8                   mov       eax, dword ptr [ebp - 8]
004a13b3  8b4df4                   mov       ecx, dword ptr [ebp - 0xc]
004a13b6  8d55fc                   lea       edx, [ebp - 4]
004a13b9  52                       push      edx
004a13ba  8b55e0                   mov       edx, dword ptr [ebp - 0x20]
004a13bd  50                       push      eax
004a13be  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
004a13c1  51                       push      ecx
004a13c2  52                       push      edx
004a13c3  50                       push      eax
004a13c4  e897020000               call      0x4a1660 ; _jwe_gpwd
004a13c9  8b45fc                   mov       eax, dword ptr [ebp - 4]
004a13cc  83c414                   add       esp, 0x14
004a13cf  3bc3                     cmp       eax, ebx
004a13d1  0f8475020000             je        0x4a164c
004a13d7  ddd8                     fstp      st(0)
004a13d9  391d2828b300             cmp       dword ptr [0xb32828], ebx ; _jwe_x_init
004a13df  751f                     jne       0x4a1400
004a13e1  8d4d9c                   lea       ecx, [ebp - 0x64]
004a13e4  c7052828b30002000000     mov       dword ptr [0xb32828], 2 ; _jwe_x_init
004a13ee  51                       push      ecx
004a13ef  895d9c                   mov       dword ptr [ebp - 0x64], ebx
004a13f2  895da0                   mov       dword ptr [ebp - 0x60], ebx
004a13f5  895da4                   mov       dword ptr [ebp - 0x5c], ebx
004a13f8  e8539c0000               call      0x4ab050 ; _jwe_xint
004a13fd  83c404                   add       esp, 4
004a1400  9b                       wait
004a1401  803d5aef5b0001           cmp       byte ptr [0x5bef5a], 1
004a1408  0f8522020000             jne       0x4a1630
004a140e  381dc4ec5b00             cmp       byte ptr [0x5becc4], bl
004a1414  0f8516020000             jne       0x4a1630
004a141a  dd45dc                   fld       qword ptr [ebp - 0x24]
004a141d  8d55e4                   lea       edx, [ebp - 0x1c]
004a1420  8d45ec                   lea       eax, [ebp - 0x14]
004a1423  dd55cc                   fst       qword ptr [ebp - 0x34]
004a1426  dd45f4                   fld       qword ptr [ebp - 0xc]
004a1429  891530ed5b00             mov       dword ptr [0x5bed30], edx ; bits=00000000, f32=0.0
004a142f  8d4dcc                   lea       ecx, [ebp - 0x34]
004a1432  dd55d4                   fst       qword ptr [ebp - 0x2c]
004a1435  d9c9                     fxch      st(1)
004a1437  dd5de4                   fstp      qword ptr [ebp - 0x1c]
004a143a  8d55d4                   lea       edx, [ebp - 0x2c]
004a143d  6844ed5b00               push      0x5bed44
004a1442  dd5dec                   fstp      qword ptr [ebp - 0x14]
004a1445  893d28ed5b00             mov       dword ptr [0x5bed28], edi ; bits=94ed5b00, f32=8.442257122977436e-39
004a144b  a334ed5b00               mov       dword ptr [0x5bed34], eax ; bits=00000000, f32=0.0
004a1450  c70544ed5b0089050000     mov       dword ptr [0x5bed44], 0x589 ; bits=00000000, f32=0.0
004a145a  881d48ed5b00             mov       byte ptr [0x5bed48], bl
004a1460  881d49ed5b00             mov       byte ptr [0x5bed49], bl
004a1466  891d4ced5b00             mov       dword ptr [0x5bed4c], ebx ; bits=00000000, f32=0.0
004a146c  891d54ed5b00             mov       dword ptr [0x5bed54], ebx ; bits=00000000, f32=0.0
004a1472  881d58ed5b00             mov       byte ptr [0x5bed58], bl
004a1478  881d59ed5b00             mov       byte ptr [0x5bed59], bl
004a147e  891d60ed5b00             mov       dword ptr [0x5bed60], ebx ; bits=00000000, f32=0.0
004a1484  c70568ed5b0002000000     mov       dword ptr [0x5bed68], 2 ; bits=00000000, f32=0.0
004a148e  890d6ced5b00             mov       dword ptr [0x5bed6c], ecx ; bits=00000000, f32=0.0
004a1494  66893570ed5b00           mov       word ptr [0x5bed70], si ; bits=0000
004a149b  66891d72ed5b00           mov       word ptr [0x5bed72], bx ; bits=0000
004a14a2  891574ed5b00             mov       dword ptr [0x5bed74], edx ; bits=00000000, f32=0.0
004a14a8  66893578ed5b00           mov       word ptr [0x5bed78], si ; bits=0000
004a14af  66891d7aed5b00           mov       word ptr [0x5bed7a], bx ; bits=0000
004a14b6  ff1574f35b00             call      dword ptr [0x5bf374] ; bits=80524c00, f32=7.009093131573872e-39
004a14bc  a194ed5b00               mov       eax, dword ptr [0x5bed94] ; bits=00000000, f32=0.0
004a14c1  83c404                   add       esp, 4
004a14c4  3bc3                     cmp       eax, ebx
004a14c6  0f8464010000             je        0x4a1630
004a14cc  8b45ec                   mov       eax, dword ptr [ebp - 0x14]
004a14cf  8b4df0                   mov       ecx, dword ptr [ebp - 0x10]
004a14d2  8945f4                   mov       dword ptr [ebp - 0xc], eax
004a14d5  894df8                   mov       dword ptr [ebp - 8], ecx
004a14d8  e9fb000000               jmp       0x4a15d8
004a14dd  dd45f4                   fld       qword ptr [ebp - 0xc]
004a14e0  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a14e6  dfe0                     fnstsw    ax
004a14e8  2500410000               and       eax, 0x4100
004a14ed  0f8430010000             je        0x4a1623
004a14f3  391d2828b300             cmp       dword ptr [0xb32828], ebx ; _jwe_x_init
004a14f9  751f                     jne       0x4a151a
004a14fb  8d5590                   lea       edx, [ebp - 0x70]
004a14fe  c7052828b30002000000     mov       dword ptr [0xb32828], 2 ; _jwe_x_init
004a1508  52                       push      edx
004a1509  895d90                   mov       dword ptr [ebp - 0x70], ebx
004a150c  895d94                   mov       dword ptr [ebp - 0x6c], ebx
004a150f  895d98                   mov       dword ptr [ebp - 0x68], ebx
004a1512  e8399b0000               call      0x4ab050 ; _jwe_xint
004a1517  83c404                   add       esp, 4
004a151a  9b                       wait
004a151b  803d5aef5b0001           cmp       byte ptr [0x5bef5a], 1
004a1522  0f8508010000             jne       0x4a1630
004a1528  381dc4ec5b00             cmp       byte ptr [0x5becc4], bl
004a152e  0f85fc000000             jne       0x4a1630
004a1534  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
004a1537  8b4de0                   mov       ecx, dword ptr [ebp - 0x20]
004a153a  dd45f4                   fld       qword ptr [ebp - 0xc]
004a153d  8945e4                   mov       dword ptr [ebp - 0x1c], eax
004a1540  894de8                   mov       dword ptr [ebp - 0x18], ecx
004a1543  dd55d4                   fst       qword ptr [ebp - 0x2c]
004a1546  dd5dec                   fstp      qword ptr [ebp - 0x14]
004a1549  8d55e4                   lea       edx, [ebp - 0x1c]
004a154c  8d45ec                   lea       eax, [ebp - 0x14]
004a154f  8d4dd4                   lea       ecx, [ebp - 0x2c]
004a1552  6844ed5b00               push      0x5bed44
004a1557  893d28ed5b00             mov       dword ptr [0x5bed28], edi ; bits=94ed5b00, f32=8.442257122977436e-39
004a155d  891530ed5b00             mov       dword ptr [0x5bed30], edx ; bits=00000000, f32=0.0
004a1563  a334ed5b00               mov       dword ptr [0x5bed34], eax ; bits=00000000, f32=0.0
004a1568  c70544ed5b000a010000     mov       dword ptr [0x5bed44], 0x10a ; bits=00000000, f32=0.0
004a1572  881d48ed5b00             mov       byte ptr [0x5bed48], bl
004a1578  881d49ed5b00             mov       byte ptr [0x5bed49], bl
004a157e  891d4ced5b00             mov       dword ptr [0x5bed4c], ebx ; bits=00000000, f32=0.0
004a1584  891d54ed5b00             mov       dword ptr [0x5bed54], ebx ; bits=00000000, f32=0.0
004a158a  881d58ed5b00             mov       byte ptr [0x5bed58], bl
004a1590  881d59ed5b00             mov       byte ptr [0x5bed59], bl
004a1596  891d60ed5b00             mov       dword ptr [0x5bed60], ebx ; bits=00000000, f32=0.0
004a159c  c70568ed5b0001000000     mov       dword ptr [0x5bed68], 1 ; bits=00000000, f32=0.0
004a15a6  890d6ced5b00             mov       dword ptr [0x5bed6c], ecx ; bits=00000000, f32=0.0
004a15ac  66893570ed5b00           mov       word ptr [0x5bed70], si ; bits=0000
004a15b3  66891d72ed5b00           mov       word ptr [0x5bed72], bx ; bits=0000
004a15ba  ff1574f35b00             call      dword ptr [0x5bf374] ; bits=80524c00, f32=7.009093131573872e-39
004a15c0  a194ed5b00               mov       eax, dword ptr [0x5bed94] ; bits=00000000, f32=0.0
004a15c5  83c404                   add       esp, 4
004a15c8  3bc3                     cmp       eax, ebx
004a15ca  7464                     je        0x4a1630
004a15cc  8b55ec                   mov       edx, dword ptr [ebp - 0x14]
004a15cf  8b45f0                   mov       eax, dword ptr [ebp - 0x10]
004a15d2  8955f4                   mov       dword ptr [ebp - 0xc], edx
004a15d5  8945f8                   mov       dword ptr [ebp - 8], eax
004a15d8  dd45e4                   fld       qword ptr [ebp - 0x1c]
004a15db  dd55dc                   fst       qword ptr [ebp - 0x24]
004a15de  dd45ec                   fld       qword ptr [ebp - 0x14]
004a15e1  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a15e7  dfe0                     fnstsw    ax
004a15e9  f6c444                   test      ah, 0x44
004a15ec  0f8ad0fbffff             jp        0x4a11c2
004a15f2  ddd8                     fstp      st(0)
004a15f4  dd0580dc5400             fld       qword ptr [0x54dc80] ; __real@3ff0000000000000, bits=000000000000f03f, f64=1.0
004a15fa  5f                       pop       edi
004a15fb  5e                       pop       esi
004a15fc  5b                       pop       ebx
004a15fd  8be5                     mov       esp, ebp
004a15ff  5d                       pop       ebp
004a1600  c3                       ret
004a1601  83f901                   cmp       ecx, 1
004a1604  7e46                     jle       0x4a164c
004a1606  8d41ff                   lea       eax, [ecx - 1]
004a1609  dc4ddc                   fmul      qword ptr [ebp - 0x24]
004a160c  48                       dec       eax
004a160d  75fa                     jne       0x4a1609
004a160f  5f                       pop       edi
004a1610  5e                       pop       esi
004a1611  5b                       pop       ebx
004a1612  8be5                     mov       esp, ebp
004a1614  5d                       pop       ebp
004a1615  c3                       ret
004a1616  dd0550dd5400             fld       qword ptr [0x54dd50] ; _NaN_D, bits=000000000000f87f, f64=nan
004a161c  5f                       pop       edi
004a161d  5e                       pop       esi
004a161e  5b                       pop       ebx
004a161f  8be5                     mov       esp, ebp
004a1621  5d                       pop       ebp
004a1622  c3                       ret
004a1623  dd0560dc5400             fld       qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004a1629  5f                       pop       edi
004a162a  5e                       pop       esi
004a162b  5b                       pop       ebx
004a162c  8be5                     mov       esp, ebp
004a162e  5d                       pop       ebp
004a162f  c3                       ret
004a1630  803dc5ec5b0001           cmp       byte ptr [0x5becc5], 1
004a1637  750d                     jne       0x4a1646
004a1639  dd0560dd5400             fld       qword ptr [0x54dd60] ; _Inf_D, bits=000000000000f07f, f64=inf
004a163f  5f                       pop       edi
004a1640  5e                       pop       esi
004a1641  5b                       pop       ebx
004a1642  8be5                     mov       esp, ebp
004a1644  5d                       pop       ebp
004a1645  c3                       ret
004a1646  dd0580025500             fld       qword ptr [0x550280] ; __real@7fefffffffffffb6, bits=b6ffffffffffef7f, f64=1.7976931348623011e+308
004a164c  5f                       pop       edi
004a164d  5e                       pop       esi
004a164e  5b                       pop       ebx
004a164f  8be5                     mov       esp, ebp
004a1651  5d                       pop       ebp
004a1652  c3                       ret
004a1653  90                       nop
004a1654  90                       nop
004a1655  90                       nop
004a1656  90                       nop
004a1657  90                       nop
004a1658  90                       nop
004a1659  90                       nop
004a165a  90                       nop
004a165b  90                       nop
004a165c  90                       nop
004a165d  90                       nop
004a165e  90                       nop
004a165f  90                       nop
