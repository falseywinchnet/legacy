; _setinx_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0xc2f0
0040c2f0  81ec84040000             sub       esp, 0x484
0040c2f6  55                       push      ebp
0040c2f7  53                       push      ebx
0040c2f8  56                       push      esi
0040c2f9  57                       push      edi
0040c2fa  8b842498040000           mov       eax, dword ptr [esp + 0x498]
0040c301  8b8c249c040000           mov       ecx, dword ptr [esp + 0x49c]
0040c308  89442468                 mov       dword ptr [esp + 0x68], eax
0040c30c  894c2464                 mov       dword ptr [esp + 0x64], ecx
0040c310  8b8424a4040000           mov       eax, dword ptr [esp + 0x4a4]
0040c317  d900                     fld       dword ptr [eax]
0040c319  d9e8                     fld1
0040c31b  d820                     fsub      dword ptr [eax]
0040c31d  dbbc2454040000           fstp      xword ptr [esp + 0x454]
0040c324  8b442464                 mov       eax, dword ptr [esp + 0x64]
0040c328  dbbc2448040000           fstp      xword ptr [esp + 0x448]
0040c32f  8b08                     mov       ecx, dword ptr [eax]
0040c331  89ca                     mov       edx, ecx
0040c333  c1e202                   shl       edx, 2
0040c336  89d5                     mov       ebp, edx
0040c338  8b9c24a8040000           mov       ebx, dword ptr [esp + 0x4a8]
0040c33f  8b74ebf8                 mov       esi, dword ptr [ebx + ebp*8 - 8]
0040c343  83fe00                   cmp       esi, 0
0040c346  894c2460                 mov       dword ptr [esp + 0x60], ecx
0040c34a  895c2458                 mov       dword ptr [esp + 0x58], ebx
0040c34e  89742454                 mov       dword ptr [esp + 0x54], esi
0040c352  7e28                     jle       0x40c37c
0040c354  8b4c2458                 mov       ecx, dword ptr [esp + 0x58]
0040c358  8b54e9e8                 mov       edx, dword ptr [ecx + ebp*8 - 0x18]
0040c35c  8b5ce9ec                 mov       ebx, dword ptr [ecx + ebp*8 - 0x14]
0040c360  be01000000               mov       esi, 1
0040c365  8b7ce9e0                 mov       edi, dword ptr [ecx + ebp*8 - 0x20]
0040c369  47                       inc       edi
0040c36a  89542450                 mov       dword ptr [esp + 0x50], edx
0040c36e  895c244c                 mov       dword ptr [esp + 0x4c], ebx
0040c372  89742448                 mov       dword ptr [esp + 0x48], esi
0040c376  897c2444                 mov       dword ptr [esp + 0x44], edi
0040c37a  eb33                     jmp       0x40c3af
0040c37c  8b442458                 mov       eax, dword ptr [esp + 0x58]
0040c380  89c1                     mov       ecx, eax
0040c382  8b5ce9ec                 mov       ebx, dword ptr [ecx + ebp*8 - 0x14]
0040c386  89c1                     mov       ecx, eax
0040c388  8b74e9e8                 mov       esi, dword ptr [ecx + ebp*8 - 0x18]
0040c38c  b9ffffffff               mov       ecx, 0xffffffff
0040c391  8b7c2454                 mov       edi, dword ptr [esp + 0x54]
0040c395  f7df                     neg       edi
0040c397  895c2450                 mov       dword ptr [esp + 0x50], ebx
0040c39b  8b5ce8e4                 mov       ebx, dword ptr [eax + ebp*8 - 0x1c]
0040c39f  894c2448                 mov       dword ptr [esp + 0x48], ecx
0040c3a3  895c2444                 mov       dword ptr [esp + 0x44], ebx
0040c3a7  8974244c                 mov       dword ptr [esp + 0x4c], esi
0040c3ab  897c2454                 mov       dword ptr [esp + 0x54], edi
0040c3af  8b442460                 mov       eax, dword ptr [esp + 0x60]
0040c3b3  d90485fc5de401           fld       dword ptr [eax*4 + 0x1e45dfc]
0040c3ba  dbbc243c040000           fstp      xword ptr [esp + 0x43c]
0040c3c1  d904855c80e401           fld       dword ptr [eax*4 + 0x1e4805c]
0040c3c8  dbbc2430040000           fstp      xword ptr [esp + 0x430]
0040c3cf  833da001e90100           cmp       dword ptr [0x1e901a0], 0 ; _bnelem_
0040c3d6  0f85ad000000             jne       0x40c489
0040c3dc  837c244800               cmp       dword ptr [esp + 0x48], 0
0040c3e1  7e54                     jle       0x40c437
0040c3e3  8b442450                 mov       eax, dword ptr [esp + 0x50]
0040c3e7  8b0c8564b2f001           mov       ecx, dword ptr [eax*4 + 0x1f0b264]
0040c3ee  890df4855100             mov       dword ptr [0x5185f4], ecx ; bits=00000000, f32=0.0
0040c3f4  8b0c85a401e901           mov       ecx, dword ptr [eax*4 + 0x1e901a4]
0040c3fb  890d70855100             mov       dword ptr [0x518570], ecx ; bits=00000000, f32=0.0
0040c401  8b0c85243cf201           mov       ecx, dword ptr [eax*4 + 0x1f23c24]
0040c408  890d18865100             mov       dword ptr [0x518618], ecx ; bits=00000000, f32=0.0
0040c40e  8b0c852408ea01           mov       ecx, dword ptr [eax*4 + 0x1ea0824]
0040c415  890d80855100             mov       dword ptr [0x518580], ecx ; bits=00000000, f32=0.0
0040c41b  8b0c85a428ef01           mov       ecx, dword ptr [eax*4 + 0x1ef28a4]
0040c422  890ddc855100             mov       dword ptr [0x5185dc], ecx ; bits=00000000, f32=0.0
0040c428  8b0c852415ec01           mov       ecx, dword ptr [eax*4 + 0x1ec1524]
0040c42f  890db8855100             mov       dword ptr [0x5185b8], ecx ; bits=00000000, f32=0.0
0040c435  eb52                     jmp       0x40c489
0040c437  8b442450                 mov       eax, dword ptr [esp + 0x50]
0040c43b  8b0c8564b2f001           mov       ecx, dword ptr [eax*4 + 0x1f0b264]
0040c442  890d0c865100             mov       dword ptr [0x51860c], ecx ; bits=00000000, f32=0.0
0040c448  8b0c85a401e901           mov       ecx, dword ptr [eax*4 + 0x1e901a4]
0040c44f  890d78855100             mov       dword ptr [0x518578], ecx ; bits=00000000, f32=0.0
0040c455  8b0c85243cf201           mov       ecx, dword ptr [eax*4 + 0x1f23c24]
0040c45c  890d24865100             mov       dword ptr [0x518624], ecx ; bits=00000000, f32=0.0
0040c462  8b0c852408ea01           mov       ecx, dword ptr [eax*4 + 0x1ea0824]
0040c469  890d88855100             mov       dword ptr [0x518588], ecx ; bits=00000000, f32=0.0
0040c46f  8b0c85a428ef01           mov       ecx, dword ptr [eax*4 + 0x1ef28a4]
0040c476  890de4855100             mov       dword ptr [0x5185e4], ecx ; bits=00000000, f32=0.0
0040c47c  8b0c852415ec01           mov       ecx, dword ptr [eax*4 + 0x1ec1524]
0040c483  890dc4855100             mov       dword ptr [0x5185c4], ecx ; bits=00000000, f32=0.0
0040c489  837c244800               cmp       dword ptr [esp + 0x48], 0
0040c48e  0f8e98000000             jle       0x40c52c
0040c494  8b442450                 mov       eax, dword ptr [esp + 0x50]
0040c498  8b0c85e4abef01           mov       ecx, dword ptr [eax*4 + 0x1efabe4]
0040c49f  890de0855100             mov       dword ptr [0x5185e0], ecx ; bits=00000000, f32=0.0
0040c4a5  8b0c8564bff201           mov       ecx, dword ptr [eax*4 + 0x1f2bf64]
0040c4ac  890d1c865100             mov       dword ptr [0x51861c], ecx ; bits=00000000, f32=0.0
0040c4b2  6890855100               push      0x518590
0040c4b7  6884855100               push      0x518584
0040c4bc  68a0855100               push      0x5185a0
0040c4c1  68bc855100               push      0x5185bc
0040c4c6  68a8855100               push      0x5185a8
0040c4cb  68f8855100               push      0x5185f8
0040c4d0  6874855100               push      0x518574
0040c4d5  681c865100               push      0x51861c
0040c4da  8d0c853cd4e201           lea       ecx, [eax*4 + 0x1e2d43c]
0040c4e1  51                       push      ecx
0040c4e2  e889faffff               call      0x40bf70 ; _xxlkt20_
0040c4e7  83c424                   add       esp, 0x24
0040c4ea  8b4c2450                 mov       ecx, dword ptr [esp + 0x50]
0040c4ee  8b05f8855100             mov       eax, dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040c4f4  89048da435f101           mov       dword ptr [ecx*4 + 0x1f135a4], eax
0040c4fb  8b0574855100             mov       eax, dword ptr [0x518574] ; bits=00000000, f32=0.0
0040c501  89048de484e901           mov       dword ptr [ecx*4 + 0x1e984e4], eax
0040c508  8b0584855100             mov       eax, dword ptr [0x518584] ; bits=00000000, f32=0.0
0040c50e  89048d648bea01           mov       dword ptr [ecx*4 + 0x1ea8b64], eax
0040c515  8b05bc855100             mov       eax, dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040c51b  89048d6498ec01           mov       dword ptr [ecx*4 + 0x1ec9864], eax
0040c522  41                       inc       ecx
0040c523  894c2450                 mov       dword ptr [esp + 0x50], ecx
0040c527  e993000000               jmp       0x40c5bf
0040c52c  8b442450                 mov       eax, dword ptr [esp + 0x50]
0040c530  8b0c85e4abef01           mov       ecx, dword ptr [eax*4 + 0x1efabe4]
0040c537  890de8855100             mov       dword ptr [0x5185e8], ecx ; bits=00000000, f32=0.0
0040c53d  8b0c8564bff201           mov       ecx, dword ptr [eax*4 + 0x1f2bf64]
0040c544  890d28865100             mov       dword ptr [0x518628], ecx ; bits=00000000, f32=0.0
0040c54a  6894855100               push      0x518594
0040c54f  688c855100               push      0x51858c
0040c554  68a4855100               push      0x5185a4
0040c559  68c8855100               push      0x5185c8
0040c55e  68ac855100               push      0x5185ac
0040c563  6810865100               push      0x518610
0040c568  687c855100               push      0x51857c
0040c56d  6828865100               push      0x518628
0040c572  8d0c853cd4e201           lea       ecx, [eax*4 + 0x1e2d43c]
0040c579  51                       push      ecx
0040c57a  e8f1f9ffff               call      0x40bf70 ; _xxlkt20_
0040c57f  83c424                   add       esp, 0x24
0040c582  8b4c2450                 mov       ecx, dword ptr [esp + 0x50]
0040c586  8b0510865100             mov       eax, dword ptr [0x518610] ; bits=00000000, f32=0.0
0040c58c  89048da435f101           mov       dword ptr [ecx*4 + 0x1f135a4], eax
0040c593  8b057c855100             mov       eax, dword ptr [0x51857c] ; bits=00000000, f32=0.0
0040c599  89048de484e901           mov       dword ptr [ecx*4 + 0x1e984e4], eax
0040c5a0  8b058c855100             mov       eax, dword ptr [0x51858c] ; bits=00000000, f32=0.0
0040c5a6  89048d648bea01           mov       dword ptr [ecx*4 + 0x1ea8b64], eax
0040c5ad  8b05c8855100             mov       eax, dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040c5b3  89048d6498ec01           mov       dword ptr [ecx*4 + 0x1ec9864], eax
0040c5ba  49                       dec       ecx
0040c5bb  894c2450                 mov       dword ptr [esp + 0x50], ecx
0040c5bf  8b442450                 mov       eax, dword ptr [esp + 0x50]
0040c5c3  89442440                 mov       dword ptr [esp + 0x40], eax
0040c5c7  8b4c2448                 mov       ecx, dword ptr [esp + 0x48]
0040c5cb  894c243c                 mov       dword ptr [esp + 0x3c], ecx
0040c5cf  8b54244c                 mov       edx, dword ptr [esp + 0x4c]
0040c5d3  29c2                     sub       edx, eax
0040c5d5  89d5                     mov       ebp, edx
0040c5d7  01cd                     add       ebp, ecx
0040c5d9  89e8                     mov       eax, ebp
0040c5db  89cb                     mov       ebx, ecx
0040c5dd  99                       cdq
0040c5de  f7fb                     idiv      ebx
0040c5e0  3d00000000               cmp       eax, 0
0040c5e5  89442438                 mov       dword ptr [esp + 0x38], eax
0040c5e9  0f8ed01c0000             jle       0x40e2bf
0040c5ef  8b442440                 mov       eax, dword ptr [esp + 0x40]
0040c5f3  89c5                     mov       ebp, eax
0040c5f5  8b442468                 mov       eax, dword ptr [esp + 0x68]
0040c5f9  dd00                     fld       qword ptr [eax]
0040c5fb  d9e8                     fld1
0040c5fd  dc30                     fdiv      qword ptr [eax]
0040c5ff  dd9c2424040000           fstp      qword ptr [esp + 0x424]
0040c606  dbac2448040000           fld       xword ptr [esp + 0x448]
0040c60d  dbbc2418040000           fstp      xword ptr [esp + 0x418]
0040c614  dbac2448040000           fld       xword ptr [esp + 0x448]
0040c61b  d9e0                     fchs
0040c61d  dbbc240c040000           fstp      xword ptr [esp + 0x40c]
0040c624  dd9c2404040000           fstp      qword ptr [esp + 0x404]
0040c62b  8b442444                 mov       eax, dword ptr [esp + 0x44]
0040c62f  2b442450                 sub       eax, dword ptr [esp + 0x50]
0040c633  89442430                 mov       dword ptr [esp + 0x30], eax
0040c637  837c244801               cmp       dword ptr [esp + 0x48], 1
0040c63c  7506                     jne       0x40c644
0040c63e  896c242c                 mov       dword ptr [esp + 0x2c], ebp
0040c642  eb07                     jmp       0x40c64b
0040c644  8d4d01                   lea       ecx, [ebp + 1]
0040c647  894c242c                 mov       dword ptr [esp + 0x2c], ecx
0040c64b  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040c64f  d90485a40eeb01           fld       dword ptr [eax*4 + 0x1eb0ea4]
0040c656  d90594845100             fld       dword ptr [0x518494] ; bits=0000003f, f32=0.5
0040c65c  d9c0                     fld       st(0)
0040c65e  d80c85a40eeb01           fmul      dword ptr [eax*4 + 0x1eb0ea4]
0040c665  dbbc24f8030000           fstp      xword ptr [esp + 0x3f8]
0040c66c  d9c1                     fld       st(1)
0040c66e  d8c0                     fadd      st(0)
0040c670  dbbc24ec030000           fstp      xword ptr [esp + 0x3ec]
0040c677  d9c1                     fld       st(1)
0040c679  dc8c2424040000           fmul      qword ptr [esp + 0x424]
0040c680  d99c2490040000           fstp      dword ptr [esp + 0x490]
0040c687  d9842490040000           fld       dword ptr [esp + 0x490]
0040c68e  d9c9                     fxch      st(1)
0040c690  d88c2490040000           fmul      dword ptr [esp + 0x490]
0040c697  dbbc24e0030000           fstp      xword ptr [esp + 0x3e0]
0040c69e  d90485e491eb01           fld       dword ptr [eax*4 + 0x1eb91e4]
0040c6a5  dbbc24d4030000           fstp      xword ptr [esp + 0x3d4]
0040c6ac  d90485a41bed01           fld       dword ptr [eax*4 + 0x1ed1ba4]
0040c6b3  dbbc24c8030000           fstp      xword ptr [esp + 0x3c8]
0040c6ba  d90485e49eed01           fld       dword ptr [eax*4 + 0x1ed9ee4]
0040c6c1  dbbc24bc030000           fstp      xword ptr [esp + 0x3bc]
0040c6c8  dbbc24b0030000           fstp      xword ptr [esp + 0x3b0]
0040c6cf  dbbc24a4030000           fstp      xword ptr [esp + 0x3a4]
0040c6d6  8b0c85fc50e201           mov       ecx, dword ptr [eax*4 + 0x1e250fc]
0040c6dd  890d68855100             mov       dword ptr [0x518568], ecx ; bits=00000000, f32=0.0
0040c6e3  833da001e90100           cmp       dword ptr [0x1e901a0], 0 ; _bnelem_
0040c6ea  0f85eb040000             jne       0x40cbdb
0040c6f0  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040c6f4  d90485a45cf701           fld       dword ptr [eax*4 + 0x1f75ca4]
0040c6fb  dbbc2498030000           fstp      xword ptr [esp + 0x398]
0040c702  837c244800               cmp       dword ptr [esp + 0x48], 0
0040c707  7e50                     jle       0x40c759
0040c709  8b0cad64b2f001           mov       ecx, dword ptr [ebp*4 + 0x1f0b264]
0040c710  890d0c865100             mov       dword ptr [0x51860c], ecx ; bits=00000000, f32=0.0
0040c716  8b0cada401e901           mov       ecx, dword ptr [ebp*4 + 0x1e901a4]
0040c71d  890d78855100             mov       dword ptr [0x518578], ecx ; bits=00000000, f32=0.0
0040c723  8b0cad243cf201           mov       ecx, dword ptr [ebp*4 + 0x1f23c24]
0040c72a  890d24865100             mov       dword ptr [0x518624], ecx ; bits=00000000, f32=0.0
0040c730  8b0cad2408ea01           mov       ecx, dword ptr [ebp*4 + 0x1ea0824]
0040c737  890d88855100             mov       dword ptr [0x518588], ecx ; bits=00000000, f32=0.0
0040c73d  8b0cada428ef01           mov       ecx, dword ptr [ebp*4 + 0x1ef28a4]
0040c744  890de4855100             mov       dword ptr [0x5185e4], ecx ; bits=00000000, f32=0.0
0040c74a  8b0cad2415ec01           mov       ecx, dword ptr [ebp*4 + 0x1ec1524]
0040c751  890dc4855100             mov       dword ptr [0x5185c4], ecx ; bits=00000000, f32=0.0
0040c757  eb4e                     jmp       0x40c7a7
0040c759  8b0cad64b2f001           mov       ecx, dword ptr [ebp*4 + 0x1f0b264]
0040c760  890df4855100             mov       dword ptr [0x5185f4], ecx ; bits=00000000, f32=0.0
0040c766  8b0cada401e901           mov       ecx, dword ptr [ebp*4 + 0x1e901a4]
0040c76d  890d70855100             mov       dword ptr [0x518570], ecx ; bits=00000000, f32=0.0
0040c773  8b0cad243cf201           mov       ecx, dword ptr [ebp*4 + 0x1f23c24]
0040c77a  890d18865100             mov       dword ptr [0x518618], ecx ; bits=00000000, f32=0.0
0040c780  8b0cad2408ea01           mov       ecx, dword ptr [ebp*4 + 0x1ea0824]
0040c787  890d80855100             mov       dword ptr [0x518580], ecx ; bits=00000000, f32=0.0
0040c78d  8b0cada428ef01           mov       ecx, dword ptr [ebp*4 + 0x1ef28a4]
0040c794  890ddc855100             mov       dword ptr [0x5185dc], ecx ; bits=00000000, f32=0.0
0040c79a  8b0cad2415ec01           mov       ecx, dword ptr [ebp*4 + 0x1ec1524]
0040c7a1  890db8855100             mov       dword ptr [0x5185b8], ecx ; bits=00000000, f32=0.0
0040c7a7  d90518865100             fld       dword ptr [0x518618] ; bits=00000000, f32=0.0
0040c7ad  dbac2430040000           fld       xword ptr [esp + 0x430]
0040c7b4  dff1                     fcompi    st(1)
0040c7b6  ddd8                     fstp      st(0)
0040c7b8  0f8a02000000             jp        0x40c7c0
0040c7be  7719                     ja        0x40c7d9
0040c7c0  d90524865100             fld       dword ptr [0x518624] ; bits=00000000, f32=0.0
0040c7c6  dbac2430040000           fld       xword ptr [esp + 0x430]
0040c7cd  dff1                     fcompi    st(1)
0040c7cf  ddd8                     fstp      st(0)
0040c7d1  0f8a0d000000             jp        0x40c7e4
0040c7d7  760b                     jbe       0x40c7e4
0040c7d9  d9ee                     fldz
0040c7db  dbbc248c030000           fstp      xword ptr [esp + 0x38c]
0040c7e2  eb0e                     jmp       0x40c7f2
0040c7e4  dbac243c040000           fld       xword ptr [esp + 0x43c]
0040c7eb  dbbc248c030000           fstp      xword ptr [esp + 0x38c]
0040c7f2  d905e4855100             fld       dword ptr [0x5185e4] ; bits=00000000, f32=0.0
0040c7f8  d905dc855100             fld       dword ptr [0x5185dc] ; bits=00000000, f32=0.0
0040c7fe  d9c0                     fld       st(0)
0040c800  d805e4855100             fadd      dword ptr [0x5185e4] ; bits=00000000, f32=0.0
0040c806  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040c80a  d91485e4ecf901           fst       dword ptr [eax*4 + 0x1f9ece4]
0040c811  d9c9                     fxch      st(1)
0040c813  d83570855100             fdiv      dword ptr [0x518570] ; bits=00000000, f32=0.0
0040c819  dbbc2480030000           fstp      xword ptr [esp + 0x380]
0040c820  d9c9                     fxch      st(1)
0040c822  d83578855100             fdiv      dword ptr [0x518578] ; bits=00000000, f32=0.0
0040c828  dbbc2474030000           fstp      xword ptr [esp + 0x374]
0040c82f  d9ee                     fldz
0040c831  d9c0                     fld       st(0)
0040c833  dbac24bc030000           fld       xword ptr [esp + 0x3bc]
0040c83a  dff1                     fcompi    st(1)
0040c83c  ddd8                     fstp      st(0)
0040c83e  d9c9                     fxch      st(1)
0040c840  dbbc2468030000           fstp      xword ptr [esp + 0x368]
0040c847  dbbc245c030000           fstp      xword ptr [esp + 0x35c]
0040c84e  0f8a02000000             jp        0x40c856
0040c854  771e                     ja        0x40c874
0040c856  dbac245c030000           fld       xword ptr [esp + 0x35c]
0040c85d  dbac24c8030000           fld       xword ptr [esp + 0x3c8]
0040c864  dff1                     fcompi    st(1)
0040c866  ddd8                     fstp      st(0)
0040c868  0f8aad000000             jp        0x40c91b
0040c86e  0f86a7000000             jbe       0x40c91b
0040c874  dbac2480030000           fld       xword ptr [esp + 0x380]
0040c87b  dbac2474030000           fld       xword ptr [esp + 0x374]
0040c882  dee9                     fsubp     st(1)
0040c884  d9ee                     fldz
0040c886  dff1                     fcompi    st(1)
0040c888  dbbc2450030000           fstp      xword ptr [esp + 0x350]
0040c88f  0f8a12000000             jp        0x40c8a7
0040c895  7310                     jae       0x40c8a7
0040c897  dbac24bc030000           fld       xword ptr [esp + 0x3bc]
0040c89e  dbbc2444030000           fstp      xword ptr [esp + 0x344]
0040c8a5  eb0e                     jmp       0x40c8b5
0040c8a7  dbac24c8030000           fld       xword ptr [esp + 0x3c8]
0040c8ae  dbbc2444030000           fstp      xword ptr [esp + 0x344]
0040c8b5  dbac2444030000           fld       xword ptr [esp + 0x344]
0040c8bc  d9e1                     fabs
0040c8be  dbbc2438030000           fstp      xword ptr [esp + 0x338]
0040c8c5  d9ee                     fldz
0040c8c7  dbac2468030000           fld       xword ptr [esp + 0x368]
0040c8ce  dff1                     fcompi    st(1)
0040c8d0  ddd8                     fstp      st(0)
0040c8d2  0f8a02000000             jp        0x40c8da
0040c8d8  7310                     jae       0x40c8ea
0040c8da  dbac2438030000           fld       xword ptr [esp + 0x338]
0040c8e1  d9e0                     fchs
0040c8e3  dbbc2438030000           fstp      xword ptr [esp + 0x338]
0040c8ea  dbac2438030000           fld       xword ptr [esp + 0x338]
0040c8f1  d80d94845100             fmul      dword ptr [0x518494] ; bits=0000003f, f32=0.5
0040c8f7  dbac2474030000           fld       xword ptr [esp + 0x374]
0040c8fe  dbac2480030000           fld       xword ptr [esp + 0x380]
0040c905  dec1                     faddp     st(1)
0040c907  dbac2450030000           fld       xword ptr [esp + 0x350]
0040c90e  dec9                     fmulp     st(1)
0040c910  d9e1                     fabs
0040c912  dec9                     fmulp     st(1)
0040c914  dbbc245c030000           fstp      xword ptr [esp + 0x35c]
0040c91b  833d6885510000           cmp       dword ptr [0x518568], 0 ; bits=00000000, f32=0.0
0040c922  0f8ea6000000             jle       0x40c9ce
0040c928  d90518865100             fld       dword ptr [0x518618] ; bits=00000000, f32=0.0
0040c92e  d80524865100             fadd      dword ptr [0x518624] ; bits=00000000, f32=0.0
0040c934  8d05e8845100             lea       eax, [0x5184e8] ; bits=e0600000, f32=3.4752201915255463e-41
0040c93a  d848ac                   fmul      dword ptr [eax - 0x54]
0040c93d  d91d20865100             fstp      dword ptr [0x518620] ; bits=00000000, f32=0.0
0040c943  689c855100               push      0x51859c
0040c948  686c855100               push      0x51856c
0040c94d  68b4855100               push      0x5185b4
0040c952  8d40b4                   lea       eax, [eax - 0x4c]
0040c955  50                       push      eax
0040c956  6820865100               push      0x518620
0040c95b  6868855100               push      0x518568
0040c960  e8db930200               call      0x435d40 ; _lktab_
0040c965  83c418                   add       esp, 0x18
0040c968  d9ee                     fldz
0040c96a  dbac2468030000           fld       xword ptr [esp + 0x368]
0040c971  dff1                     fcompi    st(1)
0040c973  ddd8                     fstp      st(0)
0040c975  0f8a1e000000             jp        0x40c999
0040c97b  731c                     jae       0x40c999
0040c97d  d905b4855100             fld       dword ptr [0x5185b4] ; bits=00000000, f32=0.0
0040c983  d9e0                     fchs
0040c985  d91db4855100             fstp      dword ptr [0x5185b4] ; bits=00000000, f32=0.0
0040c98b  d9059c855100             fld       dword ptr [0x51859c] ; bits=00000000, f32=0.0
0040c991  d9e0                     fchs
0040c993  d91d9c855100             fstp      dword ptr [0x51859c] ; bits=00000000, f32=0.0
0040c999  dbac245c030000           fld       xword ptr [esp + 0x35c]
0040c9a0  d905b4855100             fld       dword ptr [0x5185b4] ; bits=00000000, f32=0.0
0040c9a6  d80d94845100             fmul      dword ptr [0x518494] ; bits=0000003f, f32=0.5
0040c9ac  d90570855100             fld       dword ptr [0x518570] ; bits=00000000, f32=0.0
0040c9b2  d80578855100             fadd      dword ptr [0x518578] ; bits=00000000, f32=0.0
0040c9b8  dbac2468030000           fld       xword ptr [esp + 0x368]
0040c9bf  def1                     fdivrp    st(1)
0040c9c1  d8c8                     fmul      st(0)
0040c9c3  dec9                     fmulp     st(1)
0040c9c5  dec1                     faddp     st(1)
0040c9c7  dbbc245c030000           fstp      xword ptr [esp + 0x35c]
0040c9ce  d90518865100             fld       dword ptr [0x518618] ; bits=00000000, f32=0.0
0040c9d4  d82d24865100             fsubr     dword ptr [0x518624] ; bits=00000000, f32=0.0
0040c9da  d905b8855100             fld       dword ptr [0x5185b8] ; bits=00000000, f32=0.0
0040c9e0  d9c0                     fld       st(0)
0040c9e2  d82dc4855100             fsubr     dword ptr [0x5185c4] ; bits=00000000, f32=0.0
0040c9e8  dbac2498030000           fld       xword ptr [esp + 0x398]
0040c9ef  dec9                     fmulp     st(1)
0040c9f1  dec1                     faddp     st(1)
0040c9f3  d90570855100             fld       dword ptr [0x518570] ; bits=00000000, f32=0.0
0040c9f9  d9c0                     fld       st(0)
0040c9fb  d82d78855100             fsubr     dword ptr [0x518578] ; bits=00000000, f32=0.0
0040ca01  8d05e8845100             lea       eax, [0x5184e8] ; bits=e0600000, f32=3.4752201915255463e-41
0040ca07  d848ac                   fmul      dword ptr [eax - 0x54]
0040ca0a  dec1                     faddp     st(1)
0040ca0c  dbac2468030000           fld       xword ptr [esp + 0x368]
0040ca13  d84894                   fmul      dword ptr [eax - 0x6c]
0040ca16  dbac2468030000           fld       xword ptr [esp + 0x368]
0040ca1d  d9e1                     fabs
0040ca1f  dec9                     fmulp     st(1)
0040ca21  dbac24a4030000           fld       xword ptr [esp + 0x3a4]
0040ca28  dec9                     fmulp     st(1)
0040ca2a  d9ca                     fxch      st(2)
0040ca2c  d8c8                     fmul      st(0)
0040ca2e  defa                     fdivp     st(2)
0040ca30  dbac24d4030000           fld       xword ptr [esp + 0x3d4]
0040ca37  dec2                     faddp     st(2)
0040ca39  d9c9                     fxch      st(1)
0040ca3b  dec2                     faddp     st(2)
0040ca3d  d9c9                     fxch      st(1)
0040ca3f  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0040ca45  dbac245c030000           fld       xword ptr [esp + 0x35c]
0040ca4c  dec1                     faddp     st(1)
0040ca4e  d8c9                     fmul      st(1)
0040ca50  dbac2474030000           fld       xword ptr [esp + 0x374]
0040ca57  d80d88855100             fmul      dword ptr [0x518588] ; bits=00000000, f32=0.0
0040ca5d  d80de4855100             fmul      dword ptr [0x5185e4] ; bits=00000000, f32=0.0
0040ca63  dbac2480030000           fld       xword ptr [esp + 0x380]
0040ca6a  d80d80855100             fmul      dword ptr [0x518580] ; bits=00000000, f32=0.0
0040ca70  d80ddc855100             fmul      dword ptr [0x5185dc] ; bits=00000000, f32=0.0
0040ca76  dee9                     fsubp     st(1)
0040ca78  dbac248c030000           fld       xword ptr [esp + 0x38c]
0040ca7f  dec9                     fmulp     st(1)
0040ca81  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040ca85  dec1                     faddp     st(1)
0040ca87  d9148564ccf401           fst       dword ptr [eax*4 + 0x1f4cc64]
0040ca8e  d90485bccde101           fld       dword ptr [eax*4 + 0x1e1cdbc]
0040ca95  d9ee                     fldz
0040ca97  dbe9                     fucomi    st(1)
0040ca99  d9c9                     fxch      st(1)
0040ca9b  dbbc242c030000           fstp      xword ptr [esp + 0x32c]
0040caa2  d9c9                     fxch      st(1)
0040caa4  dbbc2420030000           fstp      xword ptr [esp + 0x320]
0040caab  d9c9                     fxch      st(1)
0040caad  dbbc2414030000           fstp      xword ptr [esp + 0x314]
0040cab4  dbbc2408030000           fstp      xword ptr [esp + 0x308]
0040cabb  0f8a02000000             jp        0x40cac3
0040cac1  7432                     je        0x40caf5
0040cac3  d905f4855100             fld       dword ptr [0x5185f4] ; bits=00000000, f32=0.0
0040cac9  d8050c865100             fadd      dword ptr [0x51860c] ; bits=00000000, f32=0.0
0040cacf  dbac24f8030000           fld       xword ptr [esp + 0x3f8]
0040cad6  dec9                     fmulp     st(1)
0040cad8  dbac242c030000           fld       xword ptr [esp + 0x32c]
0040cadf  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040cae3  dec9                     fmulp     st(1)
0040cae5  d91485bccde101           fst       dword ptr [eax*4 + 0x1e1cdbc]
0040caec  dbbc24fc020000           fstp      xword ptr [esp + 0x2fc]
0040caf3  eb0e                     jmp       0x40cb03
0040caf5  dbac2408030000           fld       xword ptr [esp + 0x308]
0040cafc  dbbc24fc020000           fstp      xword ptr [esp + 0x2fc]
0040cb03  dbac2414030000           fld       xword ptr [esp + 0x314]
0040cb0a  dbbc24f0020000           fstp      xword ptr [esp + 0x2f0]
0040cb11  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040cb15  dbac2414030000           fld       xword ptr [esp + 0x314]
0040cb1c  d91c85a44ff501           fstp      dword ptr [eax*4 + 0x1f54fa4]
0040cb23  d905dc855100             fld       dword ptr [0x5185dc] ; bits=00000000, f32=0.0
0040cb29  d82de4855100             fsubr     dword ptr [0x5185e4] ; bits=00000000, f32=0.0
0040cb2f  d91485e4d2f501           fst       dword ptr [eax*4 + 0x1f5d2e4]
0040cb36  dbbc24e4020000           fstp      xword ptr [esp + 0x2e4]
0040cb3d  837c244800               cmp       dword ptr [esp + 0x48], 0
0040cb42  7e4d                     jle       0x40cb91
0040cb44  8b0524865100             mov       eax, dword ptr [0x518624] ; bits=00000000, f32=0.0
0040cb4a  890518865100             mov       dword ptr [0x518618], eax ; bits=00000000, f32=0.0
0040cb50  8b050c865100             mov       eax, dword ptr [0x51860c] ; bits=00000000, f32=0.0
0040cb56  8905f4855100             mov       dword ptr [0x5185f4], eax ; bits=00000000, f32=0.0
0040cb5c  8b0578855100             mov       eax, dword ptr [0x518578] ; bits=00000000, f32=0.0
0040cb62  890570855100             mov       dword ptr [0x518570], eax ; bits=00000000, f32=0.0
0040cb68  8b0588855100             mov       eax, dword ptr [0x518588] ; bits=00000000, f32=0.0
0040cb6e  890580855100             mov       dword ptr [0x518580], eax ; bits=00000000, f32=0.0
0040cb74  8b05c4855100             mov       eax, dword ptr [0x5185c4] ; bits=00000000, f32=0.0
0040cb7a  8905b8855100             mov       dword ptr [0x5185b8], eax ; bits=00000000, f32=0.0
0040cb80  8b05e4855100             mov       eax, dword ptr [0x5185e4] ; bits=00000000, f32=0.0
0040cb86  8905dc855100             mov       dword ptr [0x5185dc], eax ; bits=00000000, f32=0.0
0040cb8c  e994000000               jmp       0x40cc25
0040cb91  8b0518865100             mov       eax, dword ptr [0x518618] ; bits=00000000, f32=0.0
0040cb97  890524865100             mov       dword ptr [0x518624], eax ; bits=00000000, f32=0.0
0040cb9d  8b05f4855100             mov       eax, dword ptr [0x5185f4] ; bits=00000000, f32=0.0
0040cba3  89050c865100             mov       dword ptr [0x51860c], eax ; bits=00000000, f32=0.0
0040cba9  8b0570855100             mov       eax, dword ptr [0x518570] ; bits=00000000, f32=0.0
0040cbaf  890578855100             mov       dword ptr [0x518578], eax ; bits=00000000, f32=0.0
0040cbb5  8b0580855100             mov       eax, dword ptr [0x518580] ; bits=00000000, f32=0.0
0040cbbb  890588855100             mov       dword ptr [0x518588], eax ; bits=00000000, f32=0.0
0040cbc1  8b05b8855100             mov       eax, dword ptr [0x5185b8] ; bits=00000000, f32=0.0
0040cbc7  8905c4855100             mov       dword ptr [0x5185c4], eax ; bits=00000000, f32=0.0
0040cbcd  8b05dc855100             mov       eax, dword ptr [0x5185dc] ; bits=00000000, f32=0.0
0040cbd3  8905e4855100             mov       dword ptr [0x5185e4], eax ; bits=00000000, f32=0.0
0040cbd9  eb4a                     jmp       0x40cc25
0040cbdb  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040cbdf  d90485e4ecf901           fld       dword ptr [eax*4 + 0x1f9ece4]
0040cbe6  dbbc2468030000           fstp      xword ptr [esp + 0x368]
0040cbed  d9048564ccf401           fld       dword ptr [eax*4 + 0x1f4cc64]
0040cbf4  dbbc2420030000           fstp      xword ptr [esp + 0x320]
0040cbfb  d90485a44ff501           fld       dword ptr [eax*4 + 0x1f54fa4]
0040cc02  dbbc24f0020000           fstp      xword ptr [esp + 0x2f0]
0040cc09  d90485e4d2f501           fld       dword ptr [eax*4 + 0x1f5d2e4]
0040cc10  dbbc24e4020000           fstp      xword ptr [esp + 0x2e4]
0040cc17  d90485bccde101           fld       dword ptr [eax*4 + 0x1e1cdbc]
0040cc1e  dbbc24fc020000           fstp      xword ptr [esp + 0x2fc]
0040cc25  837c244800               cmp       dword ptr [esp + 0x48], 0
0040cc2a  0f8ee2030000             jle       0x40d012
0040cc30  8b14ade4abef01           mov       edx, dword ptr [ebp*4 + 0x1efabe4]
0040cc37  8915e8855100             mov       dword ptr [0x5185e8], edx ; bits=00000000, f32=0.0
0040cc3d  8b14ad64bff201           mov       edx, dword ptr [ebp*4 + 0x1f2bf64]
0040cc44  891528865100             mov       dword ptr [0x518628], edx ; bits=00000000, f32=0.0
0040cc4a  8b14ad3cd4e201           mov       edx, dword ptr [ebp*4 + 0x1e2d43c]
0040cc51  8b0c956c2e0302           mov       ecx, dword ptr [edx*4 + 0x2032e6c]
0040cc58  8b3495b42e0302           mov       esi, dword ptr [edx*4 + 0x2032eb4]
0040cc5f  8b3c95682e0302           mov       edi, dword ptr [edx*4 + 0x2032e68]
0040cc66  8b1cbd1ccf3b05           mov       ebx, dword ptr [edi*4 + 0x53bcf1c]
0040cc6d  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040cc74  d90528865100             fld       dword ptr [0x518628] ; bits=00000000, f32=0.0
0040cc7a  d9c9                     fxch      st(1)
0040cc7c  dff1                     fcompi    st(1)
0040cc7e  dbbc24d8020000           fstp      xword ptr [esp + 0x2d8]
0040cc85  89542428                 mov       dword ptr [esp + 0x28], edx
0040cc89  89742424                 mov       dword ptr [esp + 0x24], esi
0040cc8d  0f8a23000000             jp        0x40ccb6
0040cc93  7721                     ja        0x40ccb6
0040cc95  8d340b                   lea       esi, [ebx + ecx]
0040cc98  dbac24d8020000           fld       xword ptr [esp + 0x2d8]
0040cc9f  d904b5602e0302           fld       dword ptr [esi*4 + 0x2032e60]
0040cca6  dff1                     fcompi    st(1)
0040cca8  0f8a26000000             jp        0x40ccd4
0040ccae  7324                     jae       0x40ccd4
0040ccb0  01d9                     add       ecx, ebx
0040ccb2  01de                     add       esi, ebx
0040ccb4  ebe9                     jmp       0x40cc9f
0040ccb6  dbac24d8020000           fld       xword ptr [esp + 0x2d8]
0040ccbd  29d9                     sub       ecx, ebx
0040ccbf  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040ccc6  dff1                     fcompi    st(1)
0040ccc8  0f8a02000000             jp        0x40ccd0
0040ccce  77ed                     ja        0x40ccbd
0040ccd0  ddd8                     fstp      st(0)
0040ccd2  eb02                     jmp       0x40ccd6
0040ccd4  ddd8                     fstp      st(0)
0040ccd6  8b442428                 mov       eax, dword ptr [esp + 0x28]
0040ccda  890c856c2e0302           mov       dword ptr [eax*4 + 0x2032e6c], ecx
0040cce1  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040cce8  d9048d642e0302           fld       dword ptr [ecx*4 + 0x2032e64]
0040ccef  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
0040ccf6  dbbc24cc020000           fstp      xword ptr [esp + 0x2cc]
0040ccfd  d9048d702e0302           fld       dword ptr [ecx*4 + 0x2032e70]
0040cd04  dbbc24c0020000           fstp      xword ptr [esp + 0x2c0]
0040cd0b  89d8                     mov       eax, ebx
0040cd0d  01c8                     add       eax, ecx
0040cd0f  d904856c2e0302           fld       dword ptr [eax*4 + 0x2032e6c]
0040cd16  dbbc24b4020000           fstp      xword ptr [esp + 0x2b4]
0040cd1d  d90485702e0302           fld       dword ptr [eax*4 + 0x2032e70]
0040cd24  dbbc24a8020000           fstp      xword ptr [esp + 0x2a8]
0040cd2b  d9c1                     fld       st(1)
0040cd2d  d82c85602e0302           fsubr     dword ptr [eax*4 + 0x2032e60]
0040cd34  d9ca                     fxch      st(2)
0040cd36  d82d28865100             fsubr     dword ptr [0x518628] ; bits=00000000, f32=0.0
0040cd3c  d9e8                     fld1
0040cd3e  d9c3                     fld       st(3)
0040cd40  d83d78845100             fdivr     dword ptr [0x518478] ; bits=0000803f, f32=1.0
0040cd46  d9c3                     fld       st(3)
0040cd48  d82c85642e0302           fsubr     dword ptr [eax*4 + 0x2032e64]
0040cd4f  d8c9                     fmul      st(1)
0040cd51  d91dac855100             fstp      dword ptr [0x5185ac] ; bits=00000000, f32=0.0
0040cd57  d9c2                     fld       st(2)
0040cd59  d80dac855100             fmul      dword ptr [0x5185ac] ; bits=00000000, f32=0.0
0040cd5f  d8c4                     fadd      st(4)
0040cd61  d91d10865100             fstp      dword ptr [0x518610] ; bits=00000000, f32=0.0
0040cd67  8d15e8845100             lea       edx, [0x5184e8] ; bits=e0600000, f32=3.4752201915255463e-41
0040cd6d  d9c2                     fld       st(2)
0040cd6f  d84aac                   fmul      dword ptr [edx - 0x54]
0040cd72  d9cc                     fxch      st(4)
0040cd74  d80510865100             fadd      dword ptr [0x518610] ; bits=00000000, f32=0.0
0040cd7a  decc                     fmulp     st(4)
0040cd7c  d9cb                     fxch      st(3)
0040cd7e  d8048d682e0302           fadd      dword ptr [ecx*4 + 0x2032e68]
0040cd85  d91d7c855100             fstp      dword ptr [0x51857c] ; bits=00000000, f32=0.0
0040cd8b  d9c9                     fxch      st(1)
0040cd8d  dbbc249c020000           fstp      xword ptr [esp + 0x29c]
0040cd94  d9c9                     fxch      st(1)
0040cd96  dbbc2490020000           fstp      xword ptr [esp + 0x290]
0040cd9d  d9c9                     fxch      st(1)
0040cd9f  dbbc2484020000           fstp      xword ptr [esp + 0x284]
0040cda6  dbbc2478020000           fstp      xword ptr [esp + 0x278]
0040cdad  8b742424                 mov       esi, dword ptr [esp + 0x24]
0040cdb1  85f6                     test      esi, esi
0040cdb3  89442428                 mov       dword ptr [esp + 0x28], eax
0040cdb7  89542420                 mov       dword ptr [esp + 0x20], edx
0040cdbb  757b                     jne       0x40ce38
0040cdbd  dbac24a8020000           fld       xword ptr [esp + 0x2a8]
0040cdc4  dbac24c0020000           fld       xword ptr [esp + 0x2c0]
0040cdcb  dee9                     fsubp     st(1)
0040cdcd  dbac2490020000           fld       xword ptr [esp + 0x290]
0040cdd4  dec9                     fmulp     st(1)
0040cdd6  d91d94855100             fstp      dword ptr [0x518594] ; bits=00000000, f32=0.0
0040cddc  dbac249c020000           fld       xword ptr [esp + 0x29c]
0040cde3  d80d94855100             fmul      dword ptr [0x518594] ; bits=00000000, f32=0.0
0040cde9  dbac24c0020000           fld       xword ptr [esp + 0x2c0]
0040cdf0  dec1                     faddp     st(1)
0040cdf2  d91d8c855100             fstp      dword ptr [0x51858c] ; bits=00000000, f32=0.0
0040cdf8  dbac24b4020000           fld       xword ptr [esp + 0x2b4]
0040cdff  dbac24cc020000           fld       xword ptr [esp + 0x2cc]
0040ce06  dee9                     fsubp     st(1)
0040ce08  dbac2490020000           fld       xword ptr [esp + 0x290]
0040ce0f  dec9                     fmulp     st(1)
0040ce11  d91da4855100             fstp      dword ptr [0x5185a4] ; bits=00000000, f32=0.0
0040ce17  dbac249c020000           fld       xword ptr [esp + 0x29c]
0040ce1e  d80da4855100             fmul      dword ptr [0x5185a4] ; bits=00000000, f32=0.0
0040ce24  dbac24cc020000           fld       xword ptr [esp + 0x2cc]
0040ce2b  dec1                     faddp     st(1)
0040ce2d  d91dc8855100             fstp      dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040ce33  e97f010000               jmp       0x40cfb7
0040ce38  dbac249c020000           fld       xword ptr [esp + 0x29c]
0040ce3f  dbac2490020000           fld       xword ptr [esp + 0x290]
0040ce46  dec9                     fmulp     st(1)
0040ce48  dbac2478020000           fld       xword ptr [esp + 0x278]
0040ce4f  d8e1                     fsub      st(1)
0040ce51  d9c0                     fld       st(0)
0040ce53  d8ca                     fmul      st(2)
0040ce55  dbac2484020000           fld       xword ptr [esp + 0x284]
0040ce5c  dec9                     fmulp     st(1)
0040ce5e  d9c2                     fld       st(2)
0040ce60  d8c9                     fmul      st(1)
0040ce62  d9e0                     fchs
0040ce64  dbbc246c020000           fstp      xword ptr [esp + 0x26c]
0040ce6b  d8c9                     fmul      st(1)
0040ce6d  d9c2                     fld       st(2)
0040ce6f  d8c0                     fadd      st(0)
0040ce71  dbac2478020000           fld       xword ptr [esp + 0x278]
0040ce78  dec1                     faddp     st(1)
0040ce7a  8b442420                 mov       eax, dword ptr [esp + 0x20]
0040ce7e  d9c0                     fld       st(0)
0040ce80  d8689c                   fsubr     dword ptr [eax - 0x64]
0040ce83  d8cc                     fmul      st(4)
0040ce85  d8cc                     fmul      st(4)
0040ce87  d9c3                     fld       st(3)
0040ce89  d8c8                     fmul      st(0)
0040ce8b  deca                     fmulp     st(2)
0040ce8d  d9c4                     fld       st(4)
0040ce8f  d848a0                   fmul      dword ptr [eax - 0x60]
0040ce92  dbac2478020000           fld       xword ptr [esp + 0x278]
0040ce99  dee1                     fsubrp    st(1)
0040ce9b  dbac2478020000           fld       xword ptr [esp + 0x278]
0040cea2  d8c1                     fadd      st(1)
0040cea4  d8ce                     fmul      st(6)
0040cea6  d9e0                     fchs
0040cea8  d9c9                     fxch      st(1)
0040ceaa  d8cd                     fmul      st(5)
0040ceac  dbbc2460020000           fstp      xword ptr [esp + 0x260]
0040ceb3  d9cc                     fxch      st(4)
0040ceb5  d848a4                   fmul      dword ptr [eax - 0x5c]
0040ceb8  decd                     fmulp     st(5)
0040ceba  dbac2490020000           fld       xword ptr [esp + 0x290]
0040cec1  decd                     fmulp     st(5)
0040cec3  d9cc                     fxch      st(4)
0040cec5  8b442424                 mov       eax, dword ptr [esp + 0x24]
0040cec9  dbbc2454020000           fstp      xword ptr [esp + 0x254]
0040ced0  8d1408                   lea       edx, [eax + ecx]
0040ced3  03442428                 add       eax, dword ptr [esp + 0x28]
0040ced7  d9c1                     fld       st(1)
0040ced9  d80c95642e0302           fmul      dword ptr [edx*4 + 0x2032e64]
0040cee0  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040cee7  d80c85642e0302           fmul      dword ptr [eax*4 + 0x2032e64]
0040ceee  dec1                     faddp     st(1)
0040cef0  dbac24c0020000           fld       xword ptr [esp + 0x2c0]
0040cef7  d8ca                     fmul      st(2)
0040cef9  dec1                     faddp     st(1)
0040cefb  dbac24a8020000           fld       xword ptr [esp + 0x2a8]
0040cf02  d8cd                     fmul      st(5)
0040cf04  dec1                     faddp     st(1)
0040cf06  d91d8c855100             fstp      dword ptr [0x51858c] ; bits=00000000, f32=0.0
0040cf0c  dbac2460020000           fld       xword ptr [esp + 0x260]
0040cf13  d80c95642e0302           fmul      dword ptr [edx*4 + 0x2032e64]
0040cf1a  d9c3                     fld       st(3)
0040cf1c  d80c85642e0302           fmul      dword ptr [eax*4 + 0x2032e64]
0040cf23  dec1                     faddp     st(1)
0040cf25  dbac24a8020000           fld       xword ptr [esp + 0x2a8]
0040cf2c  dbac24c0020000           fld       xword ptr [esp + 0x2c0]
0040cf33  dee9                     fsubp     st(1)
0040cf35  dbac2454020000           fld       xword ptr [esp + 0x254]
0040cf3c  dec9                     fmulp     st(1)
0040cf3e  dec1                     faddp     st(1)
0040cf40  d91d94855100             fstp      dword ptr [0x518594] ; bits=00000000, f32=0.0
0040cf46  d9c9                     fxch      st(1)
0040cf48  d80c95602e0302           fmul      dword ptr [edx*4 + 0x2032e60]
0040cf4f  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040cf56  d80c85602e0302           fmul      dword ptr [eax*4 + 0x2032e60]
0040cf5d  dec1                     faddp     st(1)
0040cf5f  dbac24cc020000           fld       xword ptr [esp + 0x2cc]
0040cf66  deca                     fmulp     st(2)
0040cf68  dec1                     faddp     st(1)
0040cf6a  dbac24b4020000           fld       xword ptr [esp + 0x2b4]
0040cf71  decb                     fmulp     st(3)
0040cf73  dec2                     faddp     st(2)
0040cf75  d9c9                     fxch      st(1)
0040cf77  d91dc8855100             fstp      dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040cf7d  dbac2460020000           fld       xword ptr [esp + 0x260]
0040cf84  d80c95602e0302           fmul      dword ptr [edx*4 + 0x2032e60]
0040cf8b  d9c9                     fxch      st(1)
0040cf8d  d80c85602e0302           fmul      dword ptr [eax*4 + 0x2032e60]
0040cf94  dec1                     faddp     st(1)
0040cf96  dbac24b4020000           fld       xword ptr [esp + 0x2b4]
0040cf9d  dbac24cc020000           fld       xword ptr [esp + 0x2cc]
0040cfa4  dee9                     fsubp     st(1)
0040cfa6  dbac2454020000           fld       xword ptr [esp + 0x254]
0040cfad  dec9                     fmulp     st(1)
0040cfaf  dec1                     faddp     st(1)
0040cfb1  d91da4855100             fstp      dword ptr [0x5185a4] ; bits=00000000, f32=0.0
0040cfb7  d905c8855100             fld       dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040cfbd  d9c0                     fld       st(0)
0040cfbf  d805c8855100             fadd      dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040cfc5  d80da4855100             fmul      dword ptr [0x5185a4] ; bits=00000000, f32=0.0
0040cfcb  d91da4855100             fstp      dword ptr [0x5185a4] ; bits=00000000, f32=0.0
0040cfd1  d8c8                     fmul      st(0)
0040cfd3  d91dc8855100             fstp      dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040cfd9  8b0510865100             mov       eax, dword ptr [0x518610] ; bits=00000000, f32=0.0
0040cfdf  8904ada435f101           mov       dword ptr [ebp*4 + 0x1f135a4], eax
0040cfe6  8b057c855100             mov       eax, dword ptr [0x51857c] ; bits=00000000, f32=0.0
0040cfec  8904ade484e901           mov       dword ptr [ebp*4 + 0x1e984e4], eax
0040cff3  8b058c855100             mov       eax, dword ptr [0x51858c] ; bits=00000000, f32=0.0
0040cff9  8904ad648bea01           mov       dword ptr [ebp*4 + 0x1ea8b64], eax
0040d000  8b05c8855100             mov       eax, dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040d006  8904ad6498ec01           mov       dword ptr [ebp*4 + 0x1ec9864], eax
0040d00d  e9dd030000               jmp       0x40d3ef
0040d012  8b14ade4abef01           mov       edx, dword ptr [ebp*4 + 0x1efabe4]
0040d019  8915e0855100             mov       dword ptr [0x5185e0], edx ; bits=00000000, f32=0.0
0040d01f  8b14ad64bff201           mov       edx, dword ptr [ebp*4 + 0x1f2bf64]
0040d026  89151c865100             mov       dword ptr [0x51861c], edx ; bits=00000000, f32=0.0
0040d02c  8b14ad3cd4e201           mov       edx, dword ptr [ebp*4 + 0x1e2d43c]
0040d033  8b0c956c2e0302           mov       ecx, dword ptr [edx*4 + 0x2032e6c]
0040d03a  8b3495b42e0302           mov       esi, dword ptr [edx*4 + 0x2032eb4]
0040d041  8b3c95682e0302           mov       edi, dword ptr [edx*4 + 0x2032e68]
0040d048  8b1cbd1ccf3b05           mov       ebx, dword ptr [edi*4 + 0x53bcf1c]
0040d04f  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040d056  d9051c865100             fld       dword ptr [0x51861c] ; bits=00000000, f32=0.0
0040d05c  d9c9                     fxch      st(1)
0040d05e  dff1                     fcompi    st(1)
0040d060  dbbc2448020000           fstp      xword ptr [esp + 0x248]
0040d067  89542428                 mov       dword ptr [esp + 0x28], edx
0040d06b  89742424                 mov       dword ptr [esp + 0x24], esi
0040d06f  0f8a23000000             jp        0x40d098
0040d075  7721                     ja        0x40d098
0040d077  8d340b                   lea       esi, [ebx + ecx]
0040d07a  dbac2448020000           fld       xword ptr [esp + 0x248]
0040d081  d904b5602e0302           fld       dword ptr [esi*4 + 0x2032e60]
0040d088  dff1                     fcompi    st(1)
0040d08a  0f8a26000000             jp        0x40d0b6
0040d090  7324                     jae       0x40d0b6
0040d092  01d9                     add       ecx, ebx
0040d094  01de                     add       esi, ebx
0040d096  ebe9                     jmp       0x40d081
0040d098  dbac2448020000           fld       xword ptr [esp + 0x248]
0040d09f  29d9                     sub       ecx, ebx
0040d0a1  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040d0a8  dff1                     fcompi    st(1)
0040d0aa  0f8a02000000             jp        0x40d0b2
0040d0b0  77ed                     ja        0x40d09f
0040d0b2  ddd8                     fstp      st(0)
0040d0b4  eb02                     jmp       0x40d0b8
0040d0b6  ddd8                     fstp      st(0)
0040d0b8  8b442428                 mov       eax, dword ptr [esp + 0x28]
0040d0bc  890c856c2e0302           mov       dword ptr [eax*4 + 0x2032e6c], ecx
0040d0c3  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0040d0ca  d9048d642e0302           fld       dword ptr [ecx*4 + 0x2032e64]
0040d0d1  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
0040d0d8  dbbc24cc020000           fstp      xword ptr [esp + 0x2cc]
0040d0df  d9048d702e0302           fld       dword ptr [ecx*4 + 0x2032e70]
0040d0e6  dbbc24c0020000           fstp      xword ptr [esp + 0x2c0]
0040d0ed  89d8                     mov       eax, ebx
0040d0ef  01c8                     add       eax, ecx
0040d0f1  d90485702e0302           fld       dword ptr [eax*4 + 0x2032e70]
0040d0f8  dbbc24a8020000           fstp      xword ptr [esp + 0x2a8]
0040d0ff  d904856c2e0302           fld       dword ptr [eax*4 + 0x2032e6c]
0040d106  dbbc24b4020000           fstp      xword ptr [esp + 0x2b4]
0040d10d  d9c1                     fld       st(1)
0040d10f  d82c85602e0302           fsubr     dword ptr [eax*4 + 0x2032e60]
0040d116  d9ca                     fxch      st(2)
0040d118  d82d1c865100             fsubr     dword ptr [0x51861c] ; bits=00000000, f32=0.0
0040d11e  d9e8                     fld1
0040d120  d9c3                     fld       st(3)
0040d122  d83d78845100             fdivr     dword ptr [0x518478] ; bits=0000803f, f32=1.0
0040d128  d9c3                     fld       st(3)
0040d12a  d82c85642e0302           fsubr     dword ptr [eax*4 + 0x2032e64]
0040d131  d8c9                     fmul      st(1)
0040d133  d91da8855100             fstp      dword ptr [0x5185a8] ; bits=00000000, f32=0.0
0040d139  d9c2                     fld       st(2)
0040d13b  d80da8855100             fmul      dword ptr [0x5185a8] ; bits=00000000, f32=0.0
0040d141  d8c4                     fadd      st(4)
0040d143  d91df8855100             fstp      dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040d149  8d15e8845100             lea       edx, [0x5184e8] ; bits=e0600000, f32=3.4752201915255463e-41
0040d14f  d9c2                     fld       st(2)
0040d151  d84aac                   fmul      dword ptr [edx - 0x54]
0040d154  d9cc                     fxch      st(4)
0040d156  d805f8855100             fadd      dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040d15c  decc                     fmulp     st(4)
0040d15e  d9cb                     fxch      st(3)
0040d160  d8048d682e0302           fadd      dword ptr [ecx*4 + 0x2032e68]
0040d167  d91d74855100             fstp      dword ptr [0x518574] ; bits=00000000, f32=0.0
0040d16d  d9c9                     fxch      st(1)
0040d16f  dbbc249c020000           fstp      xword ptr [esp + 0x29c]
0040d176  d9c9                     fxch      st(1)
0040d178  dbbc2490020000           fstp      xword ptr [esp + 0x290]
0040d17f  d9c9                     fxch      st(1)
0040d181  dbbc2484020000           fstp      xword ptr [esp + 0x284]
0040d188  dbbc243c020000           fstp      xword ptr [esp + 0x23c]
0040d18f  8b742424                 mov       esi, dword ptr [esp + 0x24]
0040d193  85f6                     test      esi, esi
0040d195  89442428                 mov       dword ptr [esp + 0x28], eax
0040d199  89542410                 mov       dword ptr [esp + 0x10], edx
0040d19d  757b                     jne       0x40d21a
0040d19f  dbac24a8020000           fld       xword ptr [esp + 0x2a8]
0040d1a6  dbac24c0020000           fld       xword ptr [esp + 0x2c0]
0040d1ad  dee9                     fsubp     st(1)
0040d1af  dbac2490020000           fld       xword ptr [esp + 0x290]
0040d1b6  dec9                     fmulp     st(1)
0040d1b8  d91d90855100             fstp      dword ptr [0x518590] ; bits=00000000, f32=0.0
0040d1be  dbac249c020000           fld       xword ptr [esp + 0x29c]
0040d1c5  d80d90855100             fmul      dword ptr [0x518590] ; bits=00000000, f32=0.0
0040d1cb  dbac24c0020000           fld       xword ptr [esp + 0x2c0]
0040d1d2  dec1                     faddp     st(1)
0040d1d4  d91d84855100             fstp      dword ptr [0x518584] ; bits=00000000, f32=0.0
0040d1da  dbac24b4020000           fld       xword ptr [esp + 0x2b4]
0040d1e1  dbac24cc020000           fld       xword ptr [esp + 0x2cc]
0040d1e8  dee9                     fsubp     st(1)
0040d1ea  dbac2490020000           fld       xword ptr [esp + 0x290]
0040d1f1  dec9                     fmulp     st(1)
0040d1f3  d91da0855100             fstp      dword ptr [0x5185a0] ; bits=00000000, f32=0.0
0040d1f9  dbac249c020000           fld       xword ptr [esp + 0x29c]
0040d200  d80da0855100             fmul      dword ptr [0x5185a0] ; bits=00000000, f32=0.0
0040d206  dbac24cc020000           fld       xword ptr [esp + 0x2cc]
0040d20d  dec1                     faddp     st(1)
0040d20f  d91dbc855100             fstp      dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040d215  e97f010000               jmp       0x40d399
0040d21a  dbac249c020000           fld       xword ptr [esp + 0x29c]
0040d221  dbac2490020000           fld       xword ptr [esp + 0x290]
0040d228  dec9                     fmulp     st(1)
0040d22a  dbac243c020000           fld       xword ptr [esp + 0x23c]
0040d231  d8e1                     fsub      st(1)
0040d233  d9c0                     fld       st(0)
0040d235  d8ca                     fmul      st(2)
0040d237  dbac2484020000           fld       xword ptr [esp + 0x284]
0040d23e  dec9                     fmulp     st(1)
0040d240  d9c2                     fld       st(2)
0040d242  d8c9                     fmul      st(1)
0040d244  d9e0                     fchs
0040d246  dbbc246c020000           fstp      xword ptr [esp + 0x26c]
0040d24d  d8c9                     fmul      st(1)
0040d24f  d9c2                     fld       st(2)
0040d251  d8c0                     fadd      st(0)
0040d253  dbac243c020000           fld       xword ptr [esp + 0x23c]
0040d25a  dec1                     faddp     st(1)
0040d25c  8b442410                 mov       eax, dword ptr [esp + 0x10]
0040d260  d9c0                     fld       st(0)
0040d262  d8689c                   fsubr     dword ptr [eax - 0x64]
0040d265  d8cc                     fmul      st(4)
0040d267  d8cc                     fmul      st(4)
0040d269  d9c3                     fld       st(3)
0040d26b  d8c8                     fmul      st(0)
0040d26d  deca                     fmulp     st(2)
0040d26f  d9c4                     fld       st(4)
0040d271  d848a0                   fmul      dword ptr [eax - 0x60]
0040d274  dbac243c020000           fld       xword ptr [esp + 0x23c]
0040d27b  dee1                     fsubrp    st(1)
0040d27d  dbac243c020000           fld       xword ptr [esp + 0x23c]
0040d284  d8c1                     fadd      st(1)
0040d286  d8ce                     fmul      st(6)
0040d288  d9e0                     fchs
0040d28a  d9c9                     fxch      st(1)
0040d28c  d8cd                     fmul      st(5)
0040d28e  dbbc2460020000           fstp      xword ptr [esp + 0x260]
0040d295  d9cc                     fxch      st(4)
0040d297  d848a4                   fmul      dword ptr [eax - 0x5c]
0040d29a  decd                     fmulp     st(5)
0040d29c  dbac2490020000           fld       xword ptr [esp + 0x290]
0040d2a3  decd                     fmulp     st(5)
0040d2a5  d9cc                     fxch      st(4)
0040d2a7  8b442424                 mov       eax, dword ptr [esp + 0x24]
0040d2ab  dbbc2454020000           fstp      xword ptr [esp + 0x254]
0040d2b2  8d1408                   lea       edx, [eax + ecx]
0040d2b5  03442428                 add       eax, dword ptr [esp + 0x28]
0040d2b9  d9c1                     fld       st(1)
0040d2bb  d80c95642e0302           fmul      dword ptr [edx*4 + 0x2032e64]
0040d2c2  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040d2c9  d80c85642e0302           fmul      dword ptr [eax*4 + 0x2032e64]
0040d2d0  dec1                     faddp     st(1)
0040d2d2  dbac24c0020000           fld       xword ptr [esp + 0x2c0]
0040d2d9  d8ca                     fmul      st(2)
0040d2db  dec1                     faddp     st(1)
0040d2dd  dbac24a8020000           fld       xword ptr [esp + 0x2a8]
0040d2e4  d8cd                     fmul      st(5)
0040d2e6  dec1                     faddp     st(1)
0040d2e8  d91d84855100             fstp      dword ptr [0x518584] ; bits=00000000, f32=0.0
0040d2ee  dbac2460020000           fld       xword ptr [esp + 0x260]
0040d2f5  d80c95642e0302           fmul      dword ptr [edx*4 + 0x2032e64]
0040d2fc  d9c3                     fld       st(3)
0040d2fe  d80c85642e0302           fmul      dword ptr [eax*4 + 0x2032e64]
0040d305  dec1                     faddp     st(1)
0040d307  dbac24a8020000           fld       xword ptr [esp + 0x2a8]
0040d30e  dbac24c0020000           fld       xword ptr [esp + 0x2c0]
0040d315  dee9                     fsubp     st(1)
0040d317  dbac2454020000           fld       xword ptr [esp + 0x254]
0040d31e  dec9                     fmulp     st(1)
0040d320  dec1                     faddp     st(1)
0040d322  d91d90855100             fstp      dword ptr [0x518590] ; bits=00000000, f32=0.0
0040d328  d9c9                     fxch      st(1)
0040d32a  d80c95602e0302           fmul      dword ptr [edx*4 + 0x2032e60]
0040d331  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040d338  d80c85602e0302           fmul      dword ptr [eax*4 + 0x2032e60]
0040d33f  dec1                     faddp     st(1)
0040d341  dbac24cc020000           fld       xword ptr [esp + 0x2cc]
0040d348  deca                     fmulp     st(2)
0040d34a  dec1                     faddp     st(1)
0040d34c  dbac24b4020000           fld       xword ptr [esp + 0x2b4]
0040d353  decb                     fmulp     st(3)
0040d355  dec2                     faddp     st(2)
0040d357  d9c9                     fxch      st(1)
0040d359  d91dbc855100             fstp      dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040d35f  dbac2460020000           fld       xword ptr [esp + 0x260]
0040d366  d80c95602e0302           fmul      dword ptr [edx*4 + 0x2032e60]
0040d36d  d9c9                     fxch      st(1)
0040d36f  d80c85602e0302           fmul      dword ptr [eax*4 + 0x2032e60]
0040d376  dec1                     faddp     st(1)
0040d378  dbac24b4020000           fld       xword ptr [esp + 0x2b4]
0040d37f  dbac24cc020000           fld       xword ptr [esp + 0x2cc]
0040d386  dee9                     fsubp     st(1)
0040d388  dbac2454020000           fld       xword ptr [esp + 0x254]
0040d38f  dec9                     fmulp     st(1)
0040d391  dec1                     faddp     st(1)
0040d393  d91da0855100             fstp      dword ptr [0x5185a0] ; bits=00000000, f32=0.0
0040d399  d905bc855100             fld       dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040d39f  d9c0                     fld       st(0)
0040d3a1  d805bc855100             fadd      dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040d3a7  d80da0855100             fmul      dword ptr [0x5185a0] ; bits=00000000, f32=0.0
0040d3ad  d91da0855100             fstp      dword ptr [0x5185a0] ; bits=00000000, f32=0.0
0040d3b3  d8c8                     fmul      st(0)
0040d3b5  d91dbc855100             fstp      dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040d3bb  8b05f8855100             mov       eax, dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040d3c1  8904ada435f101           mov       dword ptr [ebp*4 + 0x1f135a4], eax
0040d3c8  8b0574855100             mov       eax, dword ptr [0x518574] ; bits=00000000, f32=0.0
0040d3ce  8904ade484e901           mov       dword ptr [ebp*4 + 0x1e984e4], eax
0040d3d5  8b0584855100             mov       eax, dword ptr [0x518584] ; bits=00000000, f32=0.0
0040d3db  8904ad648bea01           mov       dword ptr [ebp*4 + 0x1ea8b64], eax
0040d3e2  8b05bc855100             mov       eax, dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040d3e8  8904ad6498ec01           mov       dword ptr [ebp*4 + 0x1ec9864], eax
0040d3ef  d905e0855100             fld       dword ptr [0x5185e0] ; bits=00000000, f32=0.0
0040d3f5  d805e8855100             fadd      dword ptr [0x5185e8] ; bits=00000000, f32=0.0
0040d3fb  d9051c865100             fld       dword ptr [0x51861c] ; bits=00000000, f32=0.0
0040d401  d82d28865100             fsubr     dword ptr [0x518628] ; bits=00000000, f32=0.0
0040d407  dbbc2484020000           fstp      xword ptr [esp + 0x284]
0040d40e  d905c8855100             fld       dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040d414  d905bc855100             fld       dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040d41a  d9c0                     fld       st(0)
0040d41c  d805c8855100             fadd      dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040d422  8d05e8845100             lea       eax, [0x5184e8] ; bits=e0600000, f32=3.4752201915255463e-41
0040d428  d940ac                   fld       dword ptr [eax - 0x54]
0040d42b  d9c9                     fxch      st(1)
0040d42d  d848ac                   fmul      dword ptr [eax - 0x54]
0040d430  dbbc2430020000           fstp      xword ptr [esp + 0x230]
0040d437  d9ee                     fldz
0040d439  dbf4                     fcomi     st(4)
0040d43b  d9cc                     fxch      st(4)
0040d43d  dbbc2424020000           fstp      xword ptr [esp + 0x224]
0040d444  d9cb                     fxch      st(3)
0040d446  dbbc2418020000           fstp      xword ptr [esp + 0x218]
0040d44d  d9ca                     fxch      st(2)
0040d44f  dbbc240c020000           fstp      xword ptr [esp + 0x20c]
0040d456  dbbc2400020000           fstp      xword ptr [esp + 0x200]
0040d45d  dbbc24f4010000           fstp      xword ptr [esp + 0x1f4]
0040d464  8944241c                 mov       dword ptr [esp + 0x1c], eax
0040d468  0f8aa4000000             jp        0x40d512
0040d46e  0f879e000000             ja        0x40d512
0040d474  dbac2484020000           fld       xword ptr [esp + 0x284]
0040d47b  d9e0                     fchs
0040d47d  dbac24d4030000           fld       xword ptr [esp + 0x3d4]
0040d484  dee9                     fsubp     st(1)
0040d486  d80da4855100             fmul      dword ptr [0x5185a4] ; bits=00000000, f32=0.0
0040d48c  dbac2430020000           fld       xword ptr [esp + 0x230]
0040d493  d8e9                     fsubr     st(1)
0040d495  dbac2418020000           fld       xword ptr [esp + 0x218]
0040d49c  dff1                     fcompi    st(1)
0040d49e  ddd8                     fstp      st(0)
0040d4a0  dbbc24e8010000           fstp      xword ptr [esp + 0x1e8]
0040d4a7  0f8a52000000             jp        0x40d4ff
0040d4ad  7750                     ja        0x40d4ff
0040d4af  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
0040d4b3  dbac24f4010000           fld       xword ptr [esp + 0x1f4]
0040d4ba  d848a8                   fmul      dword ptr [eax - 0x58]
0040d4bd  dbac2400020000           fld       xword ptr [esp + 0x200]
0040d4c4  dbac24f4010000           fld       xword ptr [esp + 0x1f4]
0040d4cb  dee9                     fsubp     st(1)
0040d4cd  dbac240c020000           fld       xword ptr [esp + 0x20c]
0040d4d4  d8c9                     fmul      st(1)
0040d4d6  dbac24e8010000           fld       xword ptr [esp + 0x1e8]
0040d4dd  dee1                     fsubrp    st(1)
0040d4df  defa                     fdivp     st(2)
0040d4e1  d8c9                     fmul      st(1)
0040d4e3  dbac24f4010000           fld       xword ptr [esp + 0x1f4]
0040d4ea  dec1                     faddp     st(1)
0040d4ec  dbbc2430020000           fstp      xword ptr [esp + 0x230]
0040d4f3  dbbc2498030000           fstp      xword ptr [esp + 0x398]
0040d4fa  e9af000000               jmp       0x40d5ae
0040d4ff  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
0040d503  d940ac                   fld       dword ptr [eax - 0x54]
0040d506  dbbc2498030000           fstp      xword ptr [esp + 0x398]
0040d50d  e99c000000               jmp       0x40d5ae
0040d512  dbac24d4030000           fld       xword ptr [esp + 0x3d4]
0040d519  dbac2484020000           fld       xword ptr [esp + 0x284]
0040d520  dec1                     faddp     st(1)
0040d522  d80da0855100             fmul      dword ptr [0x5185a0] ; bits=00000000, f32=0.0
0040d528  dbac2430020000           fld       xword ptr [esp + 0x230]
0040d52f  d8e9                     fsubr     st(1)
0040d531  dbac2418020000           fld       xword ptr [esp + 0x218]
0040d538  dff1                     fcompi    st(1)
0040d53a  ddd8                     fstp      st(0)
0040d53c  dbbc24dc010000           fstp      xword ptr [esp + 0x1dc]
0040d543  0f8a57000000             jp        0x40d5a0
0040d549  7755                     ja        0x40d5a0
0040d54b  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
0040d54f  89c1                     mov       ecx, eax
0040d551  dbac2400020000           fld       xword ptr [esp + 0x200]
0040d558  d849a8                   fmul      dword ptr [ecx - 0x58]
0040d55b  dbac2400020000           fld       xword ptr [esp + 0x200]
0040d562  dbac24f4010000           fld       xword ptr [esp + 0x1f4]
0040d569  dee9                     fsubp     st(1)
0040d56b  d9c0                     fld       st(0)
0040d56d  d848ac                   fmul      dword ptr [eax - 0x54]
0040d570  dbac24dc010000           fld       xword ptr [esp + 0x1dc]
0040d577  dee1                     fsubrp    st(1)
0040d579  defa                     fdivp     st(2)
0040d57b  d9c9                     fxch      st(1)
0040d57d  d82d78845100             fsubr     dword ptr [0x518478] ; bits=0000803f, f32=1.0
0040d583  dcc9                     fmul      st(1), st(0)
0040d585  dbac24f4010000           fld       xword ptr [esp + 0x1f4]
0040d58c  dec2                     faddp     st(2)
0040d58e  d9c9                     fxch      st(1)
0040d590  dbbc2430020000           fstp      xword ptr [esp + 0x230]
0040d597  dbbc2498030000           fstp      xword ptr [esp + 0x398]
0040d59e  eb0e                     jmp       0x40d5ae
0040d5a0  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
0040d5a4  d940ac                   fld       dword ptr [eax - 0x54]
0040d5a7  dbbc2498030000           fstp      xword ptr [esp + 0x398]
0040d5ae  d90574855100             fld       dword ptr [0x518574] ; bits=00000000, f32=0.0
0040d5b4  d9c0                     fld       st(0)
0040d5b6  d82d7c855100             fsubr     dword ptr [0x51857c] ; bits=00000000, f32=0.0
0040d5bc  d80d94845100             fmul      dword ptr [0x518494] ; bits=0000003f, f32=0.5
0040d5c2  dec1                     faddp     st(1)
0040d5c4  dbbc24d0010000           fstp      xword ptr [esp + 0x1d0]
0040d5cb  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040d5cf  dbac2498030000           fld       xword ptr [esp + 0x398]
0040d5d6  d91c85a45cf701           fstp      dword ptr [eax*4 + 0x1f75ca4]
0040d5dd  dbac2430020000           fld       xword ptr [esp + 0x230]
0040d5e4  dbac2430020000           fld       xword ptr [esp + 0x230]
0040d5eb  dec1                     faddp     st(1)
0040d5ed  dbbc24c4010000           fstp      xword ptr [esp + 0x1c4]
0040d5f4  d9051c865100             fld       dword ptr [0x51861c] ; bits=00000000, f32=0.0
0040d5fa  dbac2430040000           fld       xword ptr [esp + 0x430]
0040d601  dff1                     fcompi    st(1)
0040d603  ddd8                     fstp      st(0)
0040d605  0f8a02000000             jp        0x40d60d
0040d60b  7719                     ja        0x40d626
0040d60d  d90528865100             fld       dword ptr [0x518628] ; bits=00000000, f32=0.0
0040d613  dbac2430040000           fld       xword ptr [esp + 0x430]
0040d61a  dff1                     fcompi    st(1)
0040d61c  ddd8                     fstp      st(0)
0040d61e  0f8a0d000000             jp        0x40d631
0040d624  760b                     jbe       0x40d631
0040d626  d9ee                     fldz
0040d628  dbbc248c030000           fstp      xword ptr [esp + 0x38c]
0040d62f  eb0e                     jmp       0x40d63f
0040d631  dbac243c040000           fld       xword ptr [esp + 0x43c]
0040d638  dbbc248c030000           fstp      xword ptr [esp + 0x38c]
0040d63f  dbac24e0030000           fld       xword ptr [esp + 0x3e0]
0040d646  d80df8855100             fmul      dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040d64c  dbac240c040000           fld       xword ptr [esp + 0x40c]
0040d653  dbac24e0030000           fld       xword ptr [esp + 0x3e0]
0040d65a  d80d10865100             fmul      dword ptr [0x518610] ; bits=00000000, f32=0.0
0040d660  dbac2418040000           fld       xword ptr [esp + 0x418]
0040d667  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040d66b  d90485fc43e001           fld       dword ptr [eax*4 + 0x1e043fc]
0040d672  dbbc24b8010000           fstp      xword ptr [esp + 0x1b8]
0040d679  d90485fcc2dd01           fld       dword ptr [eax*4 + 0x1ddc2fc]
0040d680  d9ee                     fldz
0040d682  dbf1                     fcomi     st(1)
0040d684  d9c9                     fxch      st(1)
0040d686  dbbc24ac010000           fstp      xword ptr [esp + 0x1ac]
0040d68d  dbbc24a0010000           fstp      xword ptr [esp + 0x1a0]
0040d694  d9c9                     fxch      st(1)
0040d696  d9ca                     fxch      st(2)
0040d698  d9c9                     fxch      st(1)
0040d69a  0f8a99020000             jp        0x40d939
0040d6a0  0f8393020000             jae       0x40d939
0040d6a6  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040d6aa  d90485bc4cdf01           fld       dword ptr [eax*4 + 0x1df4cbc]
0040d6b1  d904853c46de01           fld       dword ptr [eax*4 + 0x1de463c]
0040d6b8  dbbc2494010000           fstp      xword ptr [esp + 0x194]
0040d6bf  d904857cc9de01           fld       dword ptr [eax*4 + 0x1dec97c]
0040d6c6  dbbc2488010000           fstp      xword ptr [esp + 0x188]
0040d6cd  d9051c865100             fld       dword ptr [0x51861c] ; bits=00000000, f32=0.0
0040d6d3  d80528865100             fadd      dword ptr [0x518628] ; bits=00000000, f32=0.0
0040d6d9  d80d94845100             fmul      dword ptr [0x518494] ; bits=0000003f, f32=0.5
0040d6df  dee9                     fsubp     st(1)
0040d6e1  d9c0                     fld       st(0)
0040d6e3  d9e1                     fabs
0040d6e5  d905b03bfb01             fld       dword ptr [0x1fb3bb0]
0040d6eb  dff1                     fcompi    st(1)
0040d6ed  dbbc247c010000           fstp      xword ptr [esp + 0x17c]
0040d6f4  dbbc2470010000           fstp      xword ptr [esp + 0x170]
0040d6fb  0f8a21000000             jp        0x40d722
0040d701  721f                     jb        0x40d722
0040d703  dbac2470010000           fld       xword ptr [esp + 0x170]
0040d70a  dbac24ac010000           fld       xword ptr [esp + 0x1ac]
0040d711  dec9                     fmulp     st(1)
0040d713  d80db43bfb01             fmul      dword ptr [0x1fb3bb4]
0040d719  dbbc2464010000           fstp      xword ptr [esp + 0x164]
0040d720  eb55                     jmp       0x40d777
0040d722  dbac247c010000           fld       xword ptr [esp + 0x17c]
0040d729  d80dc414e001             fmul      dword ptr [0x1e014c4]
0040d72f  d9fa                     fsqrt
0040d731  d99c2490040000           fstp      dword ptr [esp + 0x490]
0040d738  dbac24ac010000           fld       xword ptr [esp + 0x1ac]
0040d73f  d88c2490040000           fmul      dword ptr [esp + 0x490]
0040d746  dbbc2464010000           fstp      xword ptr [esp + 0x164]
0040d74d  dbac2470010000           fld       xword ptr [esp + 0x170]
0040d754  dbac24a0010000           fld       xword ptr [esp + 0x1a0]
0040d75b  dff1                     fcompi    st(1)
0040d75d  ddd8                     fstp      st(0)
0040d75f  0f8a12000000             jp        0x40d777
0040d765  7610                     jbe       0x40d777
0040d767  dbac2464010000           fld       xword ptr [esp + 0x164]
0040d76e  d9e0                     fchs
0040d770  dbbc2464010000           fstp      xword ptr [esp + 0x164]
0040d777  dbac2494010000           fld       xword ptr [esp + 0x194]
0040d77e  d9c0                     fld       st(0)
0040d780  dcb42404040000           fdiv      qword ptr [esp + 0x404]
0040d787  dbac24b8010000           fld       xword ptr [esp + 0x1b8]
0040d78e  dec1                     faddp     st(1)
0040d790  d99c2490040000           fstp      dword ptr [esp + 0x490]
0040d797  d9842490040000           fld       dword ptr [esp + 0x490]
0040d79e  dbac2464010000           fld       xword ptr [esp + 0x164]
0040d7a5  dff1                     fcompi    st(1)
0040d7a7  d9c9                     fxch      st(1)
0040d7a9  dd9c245c010000           fstp      qword ptr [esp + 0x15c]
0040d7b0  dbbc2450010000           fstp      xword ptr [esp + 0x150]
0040d7b7  0f8a36000000             jp        0x40d7f3
0040d7bd  7634                     jbe       0x40d7f3
0040d7bf  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040d7c3  c704857cc9de0100000000   mov       dword ptr [eax*4 + 0x1dec97c], 0
0040d7ce  dbac2450010000           fld       xword ptr [esp + 0x150]
0040d7d5  dbbc24b8010000           fstp      xword ptr [esp + 0x1b8]
0040d7dc  d9ee                     fldz
0040d7de  d9c0                     fld       st(0)
0040d7e0  dbbc2444010000           fstp      xword ptr [esp + 0x144]
0040d7e7  dbbc2438010000           fstp      xword ptr [esp + 0x138]
0040d7ee  e934010000               jmp       0x40d927
0040d7f3  dbac24b8010000           fld       xword ptr [esp + 0x1b8]
0040d7fa  dbac2464010000           fld       xword ptr [esp + 0x164]
0040d801  dee9                     fsubp     st(1)
0040d803  dc8c2404040000           fmul      qword ptr [esp + 0x404]
0040d80a  dc84245c010000           fadd      qword ptr [esp + 0x15c]
0040d811  d99c2490040000           fstp      dword ptr [esp + 0x490]
0040d818  d9842490040000           fld       dword ptr [esp + 0x490]
0040d81f  dbac24f0020000           fld       xword ptr [esp + 0x2f0]
0040d826  dbac24a4030000           fld       xword ptr [esp + 0x3a4]
0040d82d  dec9                     fmulp     st(1)
0040d82f  dbac2488010000           fld       xword ptr [esp + 0x188]
0040d836  d8a42490040000           fsub      dword ptr [esp + 0x490]
0040d83d  d9e1                     fabs
0040d83f  def1                     fdivrp    st(1)
0040d841  8b8424b0040000           mov       eax, dword ptr [esp + 0x4b0]
0040d848  d900                     fld       dword ptr [eax]
0040d84a  dff1                     fcompi    st(1)
0040d84c  d9c9                     fxch      st(1)
0040d84e  dbbc242c010000           fstp      xword ptr [esp + 0x12c]
0040d855  dbbc2420010000           fstp      xword ptr [esp + 0x120]
0040d85c  89442414                 mov       dword ptr [esp + 0x14], eax
0040d860  0f8a2e000000             jp        0x40d894
0040d866  732c                     jae       0x40d894
0040d868  8b442414                 mov       eax, dword ptr [esp + 0x14]
0040d86c  dbac2420010000           fld       xword ptr [esp + 0x120]
0040d873  d918                     fstp      dword ptr [eax]
0040d875  8b4c2430                 mov       ecx, dword ptr [esp + 0x30]
0040d879  8d1429                   lea       edx, [ecx + ebp]
0040d87c  8b9c24bc040000           mov       ebx, dword ptr [esp + 0x4bc]
0040d883  8913                     mov       dword ptr [ebx], edx
0040d885  8b542464                 mov       edx, dword ptr [esp + 0x64]
0040d889  8b1a                     mov       ebx, dword ptr [edx]
0040d88b  8bb424b8040000           mov       esi, dword ptr [esp + 0x4b8]
0040d892  891e                     mov       dword ptr [esi], ebx
0040d894  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0040d898  dbac242c010000           fld       xword ptr [esp + 0x12c]
0040d89f  d91c857cc9de01           fstp      dword ptr [eax*4 + 0x1dec97c]
0040d8a6  dbac2464010000           fld       xword ptr [esp + 0x164]
0040d8ad  dbbc24b8010000           fstp      xword ptr [esp + 0x1b8]
0040d8b4  d905b03bfb01             fld       dword ptr [0x1fb3bb0]
0040d8ba  dbac247c010000           fld       xword ptr [esp + 0x17c]
0040d8c1  dff1                     fcompi    st(1)
0040d8c3  ddd8                     fstp      st(0)
0040d8c5  0f8a29000000             jp        0x40d8f4
0040d8cb  7727                     ja        0x40d8f4
0040d8cd  dbac24ac010000           fld       xword ptr [esp + 0x1ac]
0040d8d4  d80d94845100             fmul      dword ptr [0x518494] ; bits=0000003f, f32=0.5
0040d8da  d80db43bfb01             fmul      dword ptr [0x1fb3bb4]
0040d8e0  d9e0                     fchs
0040d8e2  d9c0                     fld       st(0)
0040d8e4  dbbc2444010000           fstp      xword ptr [esp + 0x144]
0040d8eb  dbbc2438010000           fstp      xword ptr [esp + 0x138]
0040d8f2  eb33                     jmp       0x40d927
0040d8f4  dbac24ac010000           fld       xword ptr [esp + 0x1ac]
0040d8fb  d80dc814e001             fmul      dword ptr [0x1e014c8]
0040d901  dbac24ac010000           fld       xword ptr [esp + 0x1ac]
0040d908  dec9                     fmulp     st(1)
0040d90a  dbac24b8010000           fld       xword ptr [esp + 0x1b8]
0040d911  d9e1                     fabs
0040d913  def9                     fdivp     st(1)
0040d915  d9e0                     fchs
0040d917  d9c0                     fld       st(0)
0040d919  dbbc2444010000           fstp      xword ptr [esp + 0x144]
0040d920  dbbc2438010000           fstp      xword ptr [esp + 0x138]
0040d927  dbac2438010000           fld       xword ptr [esp + 0x138]
0040d92e  deec                     fsubp     st(4)
0040d930  dbac2444010000           fld       xword ptr [esp + 0x144]
0040d937  deeb                     fsubp     st(3)
0040d939  8b8424ac040000           mov       eax, dword ptr [esp + 0x4ac]
0040d940  8b08                     mov       ecx, dword ptr [eax]
0040d942  41                       inc       ecx
0040d943  8908                     mov       dword ptr [eax], ecx
0040d945  d905e0855100             fld       dword ptr [0x5185e0] ; bits=00000000, f32=0.0
0040d94b  d82de8855100             fsubr     dword ptr [0x5185e8] ; bits=00000000, f32=0.0
0040d951  dbac24e4020000           fld       xword ptr [esp + 0x2e4]
0040d958  dee9                     fsubp     st(1)
0040d95a  dbac2418040000           fld       xword ptr [esp + 0x418]
0040d961  dec9                     fmulp     st(1)
0040d963  dbac24e4020000           fld       xword ptr [esp + 0x2e4]
0040d96a  dec1                     faddp     st(1)
0040d96c  dbac24b8010000           fld       xword ptr [esp + 0x1b8]
0040d973  dee9                     fsubp     st(1)
0040d975  dbac24d0010000           fld       xword ptr [esp + 0x1d0]
0040d97c  dbac24f0020000           fld       xword ptr [esp + 0x2f0]
0040d983  dee9                     fsubp     st(1)
0040d985  dbac24b0030000           fld       xword ptr [esp + 0x3b0]
0040d98c  dec9                     fmulp     st(1)
0040d98e  dec1                     faddp     st(1)
0040d990  d9e0                     fchs
0040d992  dbbc2414010000           fstp      xword ptr [esp + 0x114]
0040d999  837c244800               cmp       dword ptr [esp + 0x48], 0
0040d99e  7e44                     jle       0x40d9e4
0040d9a0  8b048d28007501           mov       eax, dword ptr [ecx*4 + 0x1750028]
0040d9a7  d9c9                     fxch      st(1)
0040d9a9  d91c85f8e27c01           fstp      dword ptr [eax*4 + 0x17ce2f8]
0040d9b0  8b442454                 mov       eax, dword ptr [esp + 0x54]
0040d9b4  8b1485b0837601           mov       edx, dword ptr [eax*4 + 0x17683b0]
0040d9bb  d9ca                     fxch      st(2)
0040d9bd  d91c95f8e27c01           fstp      dword ptr [edx*4 + 0x17ce2f8]
0040d9c4  8b1485b4837601           mov       edx, dword ptr [eax*4 + 0x17683b4]
0040d9cb  d9c9                     fxch      st(1)
0040d9cd  d91c95f4e27c01           fstp      dword ptr [edx*4 + 0x17ce2f4]
0040d9d4  8b1485b8837601           mov       edx, dword ptr [eax*4 + 0x17683b8]
0040d9db  d91c95f0e27c01           fstp      dword ptr [edx*4 + 0x17ce2f0]
0040d9e2  eb3e                     jmp       0x40da22
0040d9e4  8b048d28007501           mov       eax, dword ptr [ecx*4 + 0x1750028]
0040d9eb  d91c85f8e27c01           fstp      dword ptr [eax*4 + 0x17ce2f8]
0040d9f2  8b442454                 mov       eax, dword ptr [esp + 0x54]
0040d9f6  8b1485b0837601           mov       edx, dword ptr [eax*4 + 0x17683b0]
0040d9fd  d9c9                     fxch      st(1)
0040d9ff  d91c95f8e27c01           fstp      dword ptr [edx*4 + 0x17ce2f8]
0040da06  8b1485b4837601           mov       edx, dword ptr [eax*4 + 0x17683b4]
0040da0d  d91c95f4e27c01           fstp      dword ptr [edx*4 + 0x17ce2f4]
0040da14  8b1485b8837601           mov       edx, dword ptr [eax*4 + 0x17683b8]
0040da1b  d91c95f0e27c01           fstp      dword ptr [edx*4 + 0x17ce2f0]
0040da22  dbac2414010000           fld       xword ptr [esp + 0x114]
0040da29  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
0040da30  8d05e8845100             lea       eax, [0x5184e8] ; bits=e0600000, f32=3.4752201915255463e-41
0040da36  dbac2468030000           fld       xword ptr [esp + 0x368]
0040da3d  d848ac                   fmul      dword ptr [eax - 0x54]
0040da40  d9e1                     fabs
0040da42  d840b0                   fadd      dword ptr [eax - 0x50]
0040da45  dbac24b8010000           fld       xword ptr [esp + 0x1b8]
0040da4c  d9e1                     fabs
0040da4e  def1                     fdivrp    st(1)
0040da50  8b8424b4040000           mov       eax, dword ptr [esp + 0x4b4]
0040da57  d900                     fld       dword ptr [eax]
0040da59  dff1                     fcompi    st(1)
0040da5b  dbbc2408010000           fstp      xword ptr [esp + 0x108]
0040da62  89442418                 mov       dword ptr [esp + 0x18], eax
0040da66  0f8a2e000000             jp        0x40da9a
0040da6c  732c                     jae       0x40da9a
0040da6e  8b442418                 mov       eax, dword ptr [esp + 0x18]
0040da72  dbac2408010000           fld       xword ptr [esp + 0x108]
0040da79  d918                     fstp      dword ptr [eax]
0040da7b  8b442464                 mov       eax, dword ptr [esp + 0x64]
0040da7f  8b08                     mov       ecx, dword ptr [eax]
0040da81  8b9424c0040000           mov       edx, dword ptr [esp + 0x4c0]
0040da88  890a                     mov       dword ptr [edx], ecx
0040da8a  8b542430                 mov       edx, dword ptr [esp + 0x30]
0040da8e  8d1c2a                   lea       ebx, [edx + ebp]
0040da91  8bb424c4040000           mov       esi, dword ptr [esp + 0x4c4]
0040da98  891e                     mov       dword ptr [esi], ebx
0040da9a  dbac24c4010000           fld       xword ptr [esp + 0x1c4]
0040daa1  dbac24c4010000           fld       xword ptr [esp + 0x1c4]
0040daa8  dec9                     fmulp     st(1)
0040daaa  dbac2424020000           fld       xword ptr [esp + 0x224]
0040dab1  d9e1                     fabs
0040dab3  def1                     fdivrp    st(1)
0040dab5  dbac2424020000           fld       xword ptr [esp + 0x224]
0040dabc  d8c9                     fmul      st(1)
0040dabe  dbac24a4030000           fld       xword ptr [esp + 0x3a4]
0040dac5  d8c9                     fmul      st(1)
0040dac7  dbac24d4030000           fld       xword ptr [esp + 0x3d4]
0040dace  dec1                     faddp     st(1)
0040dad0  dbac2484020000           fld       xword ptr [esp + 0x284]
0040dad7  dec1                     faddp     st(1)
0040dad9  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0040dadf  dbbc2454020000           fstp      xword ptr [esp + 0x254]
0040dae6  d90574855100             fld       dword ptr [0x518574] ; bits=00000000, f32=0.0
0040daec  d83de0855100             fdivr     dword ptr [0x5185e0] ; bits=00000000, f32=0.0
0040daf2  dbbc2460020000           fstp      xword ptr [esp + 0x260]
0040daf9  d9057c855100             fld       dword ptr [0x51857c] ; bits=00000000, f32=0.0
0040daff  d83de8855100             fdivr     dword ptr [0x5185e8] ; bits=00000000, f32=0.0
0040db05  dbbc246c020000           fstp      xword ptr [esp + 0x26c]
0040db0c  dbac24ec030000           fld       xword ptr [esp + 0x3ec]
0040db13  dbac24ec030000           fld       xword ptr [esp + 0x3ec]
0040db1a  dec1                     faddp     st(1)
0040db1c  dec9                     fmulp     st(1)
0040db1e  dbac24c4010000           fld       xword ptr [esp + 0x1c4]
0040db25  def9                     fdivp     st(1)
0040db27  dbbc24cc000000           fstp      xword ptr [esp + 0xcc]
0040db2e  dbac24d0010000           fld       xword ptr [esp + 0x1d0]
0040db35  d80dc014e001             fmul      dword ptr [0x1e014c0] ; _gravcm_
0040db3b  dbac24ec030000           fld       xword ptr [esp + 0x3ec]
0040db42  d8c9                     fmul      st(1)
0040db44  deca                     fmulp     st(2)
0040db46  d9c9                     fxch      st(1)
0040db48  dbbc24c0000000           fstp      xword ptr [esp + 0xc0]
0040db4f  dbac24cc000000           fld       xword ptr [esp + 0xcc]
0040db56  d80da0855100             fmul      dword ptr [0x5185a0] ; bits=00000000, f32=0.0
0040db5c  dbac2498030000           fld       xword ptr [esp + 0x398]
0040db63  d82d78845100             fsubr     dword ptr [0x518478] ; bits=0000803f, f32=1.0
0040db69  dec9                     fmulp     st(1)
0040db6b  d9e0                     fchs
0040db6d  d82578845100             fsub      dword ptr [0x518478] ; bits=0000803f, f32=1.0
0040db73  d8c9                     fmul      st(1)
0040db75  dbac2454020000           fld       xword ptr [esp + 0x254]
0040db7c  d80d94845100             fmul      dword ptr [0x518494] ; bits=0000003f, f32=0.5
0040db82  d9c0                     fld       st(0)
0040db84  d80df8855100             fmul      dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040db8a  dec2                     faddp     st(2)
0040db8c  d90590855100             fld       dword ptr [0x518590] ; bits=00000000, f32=0.0
0040db92  d80de0855100             fmul      dword ptr [0x5185e0] ; bits=00000000, f32=0.0
0040db98  d90584855100             fld       dword ptr [0x518584] ; bits=00000000, f32=0.0
0040db9e  d9c0                     fld       st(0)
0040dba0  d80df8855100             fmul      dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040dba6  dbac2460020000           fld       xword ptr [esp + 0x260]
0040dbad  dec9                     fmulp     st(1)
0040dbaf  deea                     fsubp     st(2)
0040dbb1  dbac248c030000           fld       xword ptr [esp + 0x38c]
0040dbb8  deca                     fmulp     st(2)
0040dbba  dbac2460020000           fld       xword ptr [esp + 0x260]
0040dbc1  deca                     fmulp     st(2)
0040dbc3  d9cb                     fxch      st(3)
0040dbc5  dee1                     fsubrp    st(1)
0040dbc7  dbac2418040000           fld       xword ptr [esp + 0x418]
0040dbce  dec9                     fmulp     st(1)
0040dbd0  dbac248c030000           fld       xword ptr [esp + 0x38c]
0040dbd7  dbac24e0030000           fld       xword ptr [esp + 0x3e0]
0040dbde  dec9                     fmulp     st(1)
0040dbe0  dbac248c030000           fld       xword ptr [esp + 0x38c]
0040dbe7  dbac248c030000           fld       xword ptr [esp + 0x38c]
0040dbee  dec1                     faddp     st(1)
0040dbf0  dbbc24b4000000           fstp      xword ptr [esp + 0xb4]
0040dbf7  dbac24b4000000           fld       xword ptr [esp + 0xb4]
0040dbfe  decc                     fmulp     st(4)
0040dc00  dbac2460020000           fld       xword ptr [esp + 0x260]
0040dc07  decc                     fmulp     st(4)
0040dc09  dbac24c0000000           fld       xword ptr [esp + 0xc0]
0040dc10  dee4                     fsubrp    st(4)
0040dc12  dbac2418040000           fld       xword ptr [esp + 0x418]
0040dc19  decc                     fmulp     st(4)
0040dc1b  dcc3                     fadd      st(3), st(0)
0040dc1d  dbac24cc000000           fld       xword ptr [esp + 0xcc]
0040dc24  d80da4855100             fmul      dword ptr [0x5185a4] ; bits=00000000, f32=0.0
0040dc2a  dbac2498030000           fld       xword ptr [esp + 0x398]
0040dc31  dec9                     fmulp     st(1)
0040dc33  d82d78845100             fsubr     dword ptr [0x518478] ; bits=0000803f, f32=1.0
0040dc39  decd                     fmulp     st(5)
0040dc3b  d9ca                     fxch      st(2)
0040dc3d  d80d10865100             fmul      dword ptr [0x518610] ; bits=00000000, f32=0.0
0040dc43  dec4                     faddp     st(4)
0040dc45  d9cb                     fxch      st(3)
0040dc47  dbbc24a8000000           fstp      xword ptr [esp + 0xa8]
0040dc4e  d90594855100             fld       dword ptr [0x518594] ; bits=00000000, f32=0.0
0040dc54  d80de8855100             fmul      dword ptr [0x5185e8] ; bits=00000000, f32=0.0
0040dc5a  d9058c855100             fld       dword ptr [0x51858c] ; bits=00000000, f32=0.0
0040dc60  d9c0                     fld       st(0)
0040dc62  d80d10865100             fmul      dword ptr [0x518610] ; bits=00000000, f32=0.0
0040dc68  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040dc6f  dec9                     fmulp     st(1)
0040dc71  deea                     fsubp     st(2)
0040dc73  dbac248c030000           fld       xword ptr [esp + 0x38c]
0040dc7a  deca                     fmulp     st(2)
0040dc7c  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040dc83  deca                     fmulp     st(2)
0040dc85  dbac24a8000000           fld       xword ptr [esp + 0xa8]
0040dc8c  dec2                     faddp     st(2)
0040dc8e  dbac2418040000           fld       xword ptr [esp + 0x418]
0040dc95  deca                     fmulp     st(2)
0040dc97  dbac24b4000000           fld       xword ptr [esp + 0xb4]
0040dc9e  dec9                     fmulp     st(1)
0040dca0  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040dca7  dec9                     fmulp     st(1)
0040dca9  dbac24c0000000           fld       xword ptr [esp + 0xc0]
0040dcb0  dec1                     faddp     st(1)
0040dcb2  dbac2418040000           fld       xword ptr [esp + 0x418]
0040dcb9  dec9                     fmulp     st(1)
0040dcbb  dec2                     faddp     st(2)
0040dcbd  d9ee                     fldz
0040dcbf  dbac24bc030000           fld       xword ptr [esp + 0x3bc]
0040dcc6  dff1                     fcompi    st(1)
0040dcc8  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040dccf  dbbc24fc000000           fstp      xword ptr [esp + 0xfc]
0040dcd6  dbac2460020000           fld       xword ptr [esp + 0x260]
0040dcdd  dbbc24f0000000           fstp      xword ptr [esp + 0xf0]
0040dce4  dbac2454020000           fld       xword ptr [esp + 0x254]
0040dceb  dbbc24e4000000           fstp      xword ptr [esp + 0xe4]
0040dcf2  dbbc24d8000000           fstp      xword ptr [esp + 0xd8]
0040dcf9  d9ca                     fxch      st(2)
0040dcfb  d9c9                     fxch      st(1)
0040dcfd  0f8a02000000             jp        0x40dd05
0040dd03  771e                     ja        0x40dd23
0040dd05  dbac24c8030000           fld       xword ptr [esp + 0x3c8]
0040dd0c  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0040dd13  dff1                     fcompi    st(1)
0040dd15  ddd8                     fstp      st(0)
0040dd17  0f8afe010000             jp        0x40df1b
0040dd1d  0f83f8010000             jae       0x40df1b
0040dd23  dbac24fc000000           fld       xword ptr [esp + 0xfc]
0040dd2a  dbac24f0000000           fld       xword ptr [esp + 0xf0]
0040dd31  dee9                     fsubp     st(1)
0040dd33  dbac24fc000000           fld       xword ptr [esp + 0xfc]
0040dd3a  dbac24f0000000           fld       xword ptr [esp + 0xf0]
0040dd41  dec1                     faddp     st(1)
0040dd43  dec9                     fmulp     st(1)
0040dd45  d9e8                     fld1
0040dd47  d9e1                     fabs
0040dd49  dbbc249c000000           fstp      xword ptr [esp + 0x9c]
0040dd50  d9ee                     fldz
0040dd52  dff1                     fcompi    st(1)
0040dd54  dbbc2490000000           fstp      xword ptr [esp + 0x90]
0040dd5b  0f8a02000000             jp        0x40dd63
0040dd61  7610                     jbe       0x40dd73
0040dd63  dbac249c000000           fld       xword ptr [esp + 0x9c]
0040dd6a  d9e0                     fchs
0040dd6c  dbbc249c000000           fstp      xword ptr [esp + 0x9c]
0040dd73  dbac2490000000           fld       xword ptr [esp + 0x90]
0040dd7a  dbac249c000000           fld       xword ptr [esp + 0x9c]
0040dd81  dbbc2484000000           fstp      xword ptr [esp + 0x84]
0040dd88  d9e1                     fabs
0040dd8a  dbac24f0000000           fld       xword ptr [esp + 0xf0]
0040dd91  dbac24fc000000           fld       xword ptr [esp + 0xfc]
0040dd98  dff1                     fcompi    st(1)
0040dd9a  ddd8                     fstp      st(0)
0040dd9c  dbbc2490000000           fstp      xword ptr [esp + 0x90]
0040dda3  0f8a3b000000             jp        0x40dde4
0040dda9  7739                     ja        0x40dde4
0040ddab  dbac24bc030000           fld       xword ptr [esp + 0x3bc]
0040ddb2  d9e1                     fabs
0040ddb4  db7c2478                 fstp      xword ptr [esp + 0x78]
0040ddb8  d9ee                     fldz
0040ddba  dbac2424020000           fld       xword ptr [esp + 0x224]
0040ddc1  dff1                     fcompi    st(1)
0040ddc3  ddd8                     fstp      st(0)
0040ddc5  0f8a02000000             jp        0x40ddcd
0040ddcb  730a                     jae       0x40ddd7
0040ddcd  db6c2478                 fld       xword ptr [esp + 0x78]
0040ddd1  d9e0                     fchs
0040ddd3  db7c2478                 fstp      xword ptr [esp + 0x78]
0040ddd7  db6c2478                 fld       xword ptr [esp + 0x78]
0040dddb  dbbc2444030000           fstp      xword ptr [esp + 0x344]
0040dde2  eb37                     jmp       0x40de1b
0040dde4  dbac24c8030000           fld       xword ptr [esp + 0x3c8]
0040ddeb  d9e1                     fabs
0040dded  db7c246c                 fstp      xword ptr [esp + 0x6c]
0040ddf1  d9ee                     fldz
0040ddf3  dbac2424020000           fld       xword ptr [esp + 0x224]
0040ddfa  dff1                     fcompi    st(1)
0040ddfc  ddd8                     fstp      st(0)
0040ddfe  0f8a02000000             jp        0x40de06
0040de04  730a                     jae       0x40de10
0040de06  db6c246c                 fld       xword ptr [esp + 0x6c]
0040de0a  d9e0                     fchs
0040de0c  db7c246c                 fstp      xword ptr [esp + 0x6c]
0040de10  db6c246c                 fld       xword ptr [esp + 0x6c]
0040de14  dbbc2444030000           fstp      xword ptr [esp + 0x344]
0040de1b  d9cb                     fxch      st(3)
0040de1d  dbbc24cc000000           fstp      xword ptr [esp + 0xcc]
0040de24  dbbc2460020000           fstp      xword ptr [esp + 0x260]
0040de2b  dbbc2454020000           fstp      xword ptr [esp + 0x254]
0040de32  dbbc246c020000           fstp      xword ptr [esp + 0x26c]
0040de39  dbac24e4000000           fld       xword ptr [esp + 0xe4]
0040de40  dbac2444030000           fld       xword ptr [esp + 0x344]
0040de47  dbac2484000000           fld       xword ptr [esp + 0x84]
0040de4e  dec9                     fmulp     st(1)
0040de50  dbac24d0010000           fld       xword ptr [esp + 0x1d0]
0040de57  dec9                     fmulp     st(1)
0040de59  dbac24f0000000           fld       xword ptr [esp + 0xf0]
0040de60  d8c9                     fmul      st(1)
0040de62  d83574855100             fdiv      dword ptr [0x518574] ; bits=00000000, f32=0.0
0040de68  d9e0                     fchs
0040de6a  dbac24fc000000           fld       xword ptr [esp + 0xfc]
0040de71  deca                     fmulp     st(2)
0040de73  d9c9                     fxch      st(1)
0040de75  d8357c855100             fdiv      dword ptr [0x51857c] ; bits=00000000, f32=0.0
0040de7b  8d05e8845100             lea       eax, [0x5184e8] ; bits=e0600000, f32=3.4752201915255463e-41
0040de81  dbac2444030000           fld       xword ptr [esp + 0x344]
0040de88  d84894                   fmul      dword ptr [eax - 0x6c]
0040de8b  dbac2490000000           fld       xword ptr [esp + 0x90]
0040de92  dec9                     fmulp     st(1)
0040de94  dbac24f0000000           fld       xword ptr [esp + 0xf0]
0040de9b  d8cb                     fmul      st(3)
0040de9d  d8e9                     fsubr     st(1)
0040de9f  d80df8855100             fmul      dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040dea5  dbac24fc000000           fld       xword ptr [esp + 0xfc]
0040deac  d8cb                     fmul      st(3)
0040deae  deea                     fsubp     st(2)
0040deb0  d9c9                     fxch      st(1)
0040deb2  d80d10865100             fmul      dword ptr [0x518610] ; bits=00000000, f32=0.0
0040deb8  dbac2444030000           fld       xword ptr [esp + 0x344]
0040debf  d848ac                   fmul      dword ptr [eax - 0x54]
0040dec2  dbac2490000000           fld       xword ptr [esp + 0x90]
0040dec9  dec9                     fmulp     st(1)
0040decb  dec5                     faddp     st(5)
0040decd  8b8424a4040000           mov       eax, dword ptr [esp + 0x4a4]
0040ded4  d9c9                     fxch      st(1)
0040ded6  d808                     fmul      dword ptr [eax]
0040ded8  dbac24cc000000           fld       xword ptr [esp + 0xcc]
0040dedf  dec1                     faddp     st(1)
0040dee1  d9cb                     fxch      st(3)
0040dee3  d808                     fmul      dword ptr [eax]
0040dee5  dbac2460020000           fld       xword ptr [esp + 0x260]
0040deec  dec1                     faddp     st(1)
0040deee  d9c9                     fxch      st(1)
0040def0  d808                     fmul      dword ptr [eax]
0040def2  dbac2454020000           fld       xword ptr [esp + 0x254]
0040def9  dec1                     faddp     st(1)
0040defb  d9ca                     fxch      st(2)
0040defd  d808                     fmul      dword ptr [eax]
0040deff  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040df06  dec1                     faddp     st(1)
0040df08  d9cc                     fxch      st(4)
0040df0a  dbbc24e4000000           fstp      xword ptr [esp + 0xe4]
0040df11  d9ca                     fxch      st(2)
0040df13  d9cb                     fxch      st(3)
0040df15  d9c9                     fxch      st(1)
0040df17  d9ca                     fxch      st(2)
0040df19  d9c9                     fxch      st(1)
0040df1b  833d6885510000           cmp       dword ptr [0x518568], 0 ; bits=00000000, f32=0.0
0040df22  0f8e65010000             jle       0x40e08d
0040df28  dbbc2460040000           fstp      xword ptr [esp + 0x460]
0040df2f  dbbc246c040000           fstp      xword ptr [esp + 0x46c]
0040df36  dbbc2478040000           fstp      xword ptr [esp + 0x478]
0040df3d  dbbc2484040000           fstp      xword ptr [esp + 0x484]
0040df44  d9051c865100             fld       dword ptr [0x51861c] ; bits=00000000, f32=0.0
0040df4a  d80528865100             fadd      dword ptr [0x518628] ; bits=00000000, f32=0.0
0040df50  8d05e8845100             lea       eax, [0x5184e8] ; bits=e0600000, f32=3.4752201915255463e-41
0040df56  d848ac                   fmul      dword ptr [eax - 0x54]
0040df59  d91d20865100             fstp      dword ptr [0x518620] ; bits=00000000, f32=0.0
0040df5f  689c855100               push      0x51859c
0040df64  686c855100               push      0x51856c
0040df69  68b4855100               push      0x5185b4
0040df6e  8d40b4                   lea       eax, [eax - 0x4c]
0040df71  50                       push      eax
0040df72  6820865100               push      0x518620
0040df77  6868855100               push      0x518568
0040df7c  e8bf7d0200               call      0x435d40 ; _lktab_
0040df81  83c418                   add       esp, 0x18
0040df84  d9ee                     fldz
0040df86  dbac2424020000           fld       xword ptr [esp + 0x224]
0040df8d  dff1                     fcompi    st(1)
0040df8f  ddd8                     fstp      st(0)
0040df91  dbac2484040000           fld       xword ptr [esp + 0x484]
0040df98  dbac2478040000           fld       xword ptr [esp + 0x478]
0040df9f  dbac246c040000           fld       xword ptr [esp + 0x46c]
0040dfa6  dbac2460040000           fld       xword ptr [esp + 0x460]
0040dfad  0f8a1e000000             jp        0x40dfd1
0040dfb3  731c                     jae       0x40dfd1
0040dfb5  d905b4855100             fld       dword ptr [0x5185b4] ; bits=00000000, f32=0.0
0040dfbb  d9e0                     fchs
0040dfbd  d91db4855100             fstp      dword ptr [0x5185b4] ; bits=00000000, f32=0.0
0040dfc3  d9059c855100             fld       dword ptr [0x51859c] ; bits=00000000, f32=0.0
0040dfc9  d9e0                     fchs
0040dfcb  d91d9c855100             fstp      dword ptr [0x51859c] ; bits=00000000, f32=0.0
0040dfd1  d9cb                     fxch      st(3)
0040dfd3  dbbc2460020000           fstp      xword ptr [esp + 0x260]
0040dfda  d9c9                     fxch      st(1)
0040dfdc  dbbc246c020000           fstp      xword ptr [esp + 0x26c]
0040dfe3  d9c9                     fxch      st(1)
0040dfe5  dbbc2454020000           fstp      xword ptr [esp + 0x254]
0040dfec  dbac24e4000000           fld       xword ptr [esp + 0xe4]
0040dff3  d90574855100             fld       dword ptr [0x518574] ; bits=00000000, f32=0.0
0040dff9  d8057c855100             fadd      dword ptr [0x51857c] ; bits=00000000, f32=0.0
0040dfff  d8c8                     fmul      st(0)
0040e001  dbac2424020000           fld       xword ptr [esp + 0x224]
0040e008  def1                     fdivrp    st(1)
0040e00a  dbac2424020000           fld       xword ptr [esp + 0x224]
0040e011  d8c9                     fmul      st(1)
0040e013  d905b4855100             fld       dword ptr [0x5185b4] ; bits=00000000, f32=0.0
0040e019  d9c0                     fld       st(0)
0040e01b  d80d94845100             fmul      dword ptr [0x518494] ; bits=0000003f, f32=0.5
0040e021  d8ca                     fmul      st(2)
0040e023  dec4                     faddp     st(4)
0040e025  8b8424a4040000           mov       eax, dword ptr [esp + 0x4a4]
0040e02c  dbac24d0010000           fld       xword ptr [esp + 0x1d0]
0040e033  d808                     fmul      dword ptr [eax]
0040e035  d9cb                     fxch      st(3)
0040e037  dec9                     fmulp     st(1)
0040e039  d9c0                     fld       st(0)
0040e03b  d80df8855100             fmul      dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040e041  d9ca                     fxch      st(2)
0040e043  d80d9c855100             fmul      dword ptr [0x51859c] ; bits=00000000, f32=0.0
0040e049  dcea                     fsub      st(2), st(0)
0040e04b  d9ca                     fxch      st(2)
0040e04d  d8cb                     fmul      st(3)
0040e04f  dbac2460020000           fld       xword ptr [esp + 0x260]
0040e056  dee1                     fsubrp    st(1)
0040e058  d9c1                     fld       st(1)
0040e05a  d8cc                     fmul      st(4)
0040e05c  dcc6                     fadd      st(6), st(0)
0040e05e  d9ca                     fxch      st(2)
0040e060  d80d10865100             fmul      dword ptr [0x518610] ; bits=00000000, f32=0.0
0040e066  dee3                     fsubrp    st(3)
0040e068  d9ca                     fxch      st(2)
0040e06a  decb                     fmulp     st(3)
0040e06c  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040e073  dee3                     fsubrp    st(3)
0040e075  dbac2454020000           fld       xword ptr [esp + 0x254]
0040e07c  dec1                     faddp     st(1)
0040e07e  d9cb                     fxch      st(3)
0040e080  dbbc24e4000000           fstp      xword ptr [esp + 0xe4]
0040e087  d9cb                     fxch      st(3)
0040e089  d9c9                     fxch      st(1)
0040e08b  d9ca                     fxch      st(2)
0040e08d  d9ca                     fxch      st(2)
0040e08f  dbbc246c020000           fstp      xword ptr [esp + 0x26c]
0040e096  d9ca                     fxch      st(2)
0040e098  dbbc2460020000           fstp      xword ptr [esp + 0x260]
0040e09f  dbac2424020000           fld       xword ptr [esp + 0x224]
0040e0a6  dbac2468030000           fld       xword ptr [esp + 0x368]
0040e0ad  dee9                     fsubp     st(1)
0040e0af  dbac248c030000           fld       xword ptr [esp + 0x38c]
0040e0b6  dec9                     fmulp     st(1)
0040e0b8  dbac24e0030000           fld       xword ptr [esp + 0x3e0]
0040e0bf  dec9                     fmulp     st(1)
0040e0c1  dbac24e4000000           fld       xword ptr [esp + 0xe4]
0040e0c8  dbac24d0010000           fld       xword ptr [esp + 0x1d0]
0040e0cf  dec9                     fmulp     st(1)
0040e0d1  d9058c855100             fld       dword ptr [0x51858c] ; bits=00000000, f32=0.0
0040e0d7  d80de8855100             fmul      dword ptr [0x5185e8] ; bits=00000000, f32=0.0
0040e0dd  dbac24fc000000           fld       xword ptr [esp + 0xfc]
0040e0e4  dec9                     fmulp     st(1)
0040e0e6  d90584855100             fld       dword ptr [0x518584] ; bits=00000000, f32=0.0
0040e0ec  d80de0855100             fmul      dword ptr [0x5185e0] ; bits=00000000, f32=0.0
0040e0f2  dbac24f0000000           fld       xword ptr [esp + 0xf0]
0040e0f9  dec9                     fmulp     st(1)
0040e0fb  dee9                     fsubp     st(1)
0040e0fd  dbac248c030000           fld       xword ptr [esp + 0x38c]
0040e104  dec9                     fmulp     st(1)
0040e106  dec1                     faddp     st(1)
0040e108  dbac2418040000           fld       xword ptr [esp + 0x418]
0040e10f  dec9                     fmulp     st(1)
0040e111  dec1                     faddp     st(1)
0040e113  dbac2454040000           fld       xword ptr [esp + 0x454]
0040e11a  dbac2420030000           fld       xword ptr [esp + 0x320]
0040e121  dec9                     fmulp     st(1)
0040e123  dec1                     faddp     st(1)
0040e125  dbac24fc020000           fld       xword ptr [esp + 0x2fc]
0040e12c  dee9                     fsubp     st(1)
0040e12e  dbbc2414010000           fstp      xword ptr [esp + 0x114]
0040e135  dbac2460020000           fld       xword ptr [esp + 0x260]
0040e13c  dbac246c020000           fld       xword ptr [esp + 0x26c]
0040e143  d9c9                     fxch      st(1)
0040e145  d9cb                     fxch      st(3)
0040e147  d9c9                     fxch      st(1)
0040e149  d9ca                     fxch      st(2)
0040e14b  8b8424ac040000           mov       eax, dword ptr [esp + 0x4ac]
0040e152  8b08                     mov       ecx, dword ptr [eax]
0040e154  41                       inc       ecx
0040e155  8908                     mov       dword ptr [eax], ecx
0040e157  837c244800               cmp       dword ptr [esp + 0x48], 0
0040e15c  0f8ea0000000             jle       0x40e202
0040e162  8b048d28007501           mov       eax, dword ptr [ecx*4 + 0x1750028]
0040e169  d9c9                     fxch      st(1)
0040e16b  d91c85f4e27c01           fstp      dword ptr [eax*4 + 0x17ce2f4]
0040e172  d9ca                     fxch      st(2)
0040e174  d91c85f8e27c01           fstp      dword ptr [eax*4 + 0x17ce2f8]
0040e17b  8b442454                 mov       eax, dword ptr [esp + 0x54]
0040e17f  8b1485b4837601           mov       edx, dword ptr [eax*4 + 0x17683b4]
0040e186  d9c9                     fxch      st(1)
0040e188  d91c95f8e27c01           fstp      dword ptr [edx*4 + 0x17ce2f8]
0040e18f  8b1485b8837601           mov       edx, dword ptr [eax*4 + 0x17683b8]
0040e196  d91c95f4e27c01           fstp      dword ptr [edx*4 + 0x17ce2f4]
0040e19d  8b15e8855100             mov       edx, dword ptr [0x5185e8] ; bits=00000000, f32=0.0
0040e1a3  8915e0855100             mov       dword ptr [0x5185e0], edx ; bits=00000000, f32=0.0
0040e1a9  8b157c855100             mov       edx, dword ptr [0x51857c] ; bits=00000000, f32=0.0
0040e1af  891574855100             mov       dword ptr [0x518574], edx ; bits=00000000, f32=0.0
0040e1b5  8b1510865100             mov       edx, dword ptr [0x518610] ; bits=00000000, f32=0.0
0040e1bb  8915f8855100             mov       dword ptr [0x5185f8], edx ; bits=00000000, f32=0.0
0040e1c1  8b1528865100             mov       edx, dword ptr [0x518628] ; bits=00000000, f32=0.0
0040e1c7  89151c865100             mov       dword ptr [0x51861c], edx ; bits=00000000, f32=0.0
0040e1cd  8b15c8855100             mov       edx, dword ptr [0x5185c8] ; bits=00000000, f32=0.0
0040e1d3  8915bc855100             mov       dword ptr [0x5185bc], edx ; bits=00000000, f32=0.0
0040e1d9  8b15a4855100             mov       edx, dword ptr [0x5185a4] ; bits=00000000, f32=0.0
0040e1df  8915a0855100             mov       dword ptr [0x5185a0], edx ; bits=00000000, f32=0.0
0040e1e5  8b158c855100             mov       edx, dword ptr [0x51858c] ; bits=00000000, f32=0.0
0040e1eb  891584855100             mov       dword ptr [0x518584], edx ; bits=00000000, f32=0.0
0040e1f1  8b1594855100             mov       edx, dword ptr [0x518594] ; bits=00000000, f32=0.0
0040e1f7  891590855100             mov       dword ptr [0x518590], edx ; bits=00000000, f32=0.0
0040e1fd  e997000000               jmp       0x40e299
0040e202  8b048d28007501           mov       eax, dword ptr [ecx*4 + 0x1750028]
0040e209  d91c85f4e27c01           fstp      dword ptr [eax*4 + 0x17ce2f4]
0040e210  d9c9                     fxch      st(1)
0040e212  d91c85f8e27c01           fstp      dword ptr [eax*4 + 0x17ce2f8]
0040e219  8b442454                 mov       eax, dword ptr [esp + 0x54]
0040e21d  8b1485b4837601           mov       edx, dword ptr [eax*4 + 0x17683b4]
0040e224  d91c95f8e27c01           fstp      dword ptr [edx*4 + 0x17ce2f8]
0040e22b  8b1485b8837601           mov       edx, dword ptr [eax*4 + 0x17683b8]
0040e232  d91c95f4e27c01           fstp      dword ptr [edx*4 + 0x17ce2f4]
0040e239  8b15e0855100             mov       edx, dword ptr [0x5185e0] ; bits=00000000, f32=0.0
0040e23f  8915e8855100             mov       dword ptr [0x5185e8], edx ; bits=00000000, f32=0.0
0040e245  8b1574855100             mov       edx, dword ptr [0x518574] ; bits=00000000, f32=0.0
0040e24b  89157c855100             mov       dword ptr [0x51857c], edx ; bits=00000000, f32=0.0
0040e251  8b15f8855100             mov       edx, dword ptr [0x5185f8] ; bits=00000000, f32=0.0
0040e257  891510865100             mov       dword ptr [0x518610], edx ; bits=00000000, f32=0.0
0040e25d  8b151c865100             mov       edx, dword ptr [0x51861c] ; bits=00000000, f32=0.0
0040e263  891528865100             mov       dword ptr [0x518628], edx ; bits=00000000, f32=0.0
0040e269  8b15bc855100             mov       edx, dword ptr [0x5185bc] ; bits=00000000, f32=0.0
0040e26f  8915c8855100             mov       dword ptr [0x5185c8], edx ; bits=00000000, f32=0.0
0040e275  8b15a0855100             mov       edx, dword ptr [0x5185a0] ; bits=00000000, f32=0.0
0040e27b  8915a4855100             mov       dword ptr [0x5185a4], edx ; bits=00000000, f32=0.0
0040e281  8b1584855100             mov       edx, dword ptr [0x518584] ; bits=00000000, f32=0.0
0040e287  89158c855100             mov       dword ptr [0x51858c], edx ; bits=00000000, f32=0.0
0040e28d  8b1590855100             mov       edx, dword ptr [0x518590] ; bits=00000000, f32=0.0
0040e293  891594855100             mov       dword ptr [0x518594], edx ; bits=00000000, f32=0.0
0040e299  dbac2414010000           fld       xword ptr [esp + 0x114]
0040e2a0  d9e0                     fchs
0040e2a2  d91c8df84baa01           fstp      dword ptr [ecx*4 + 0x1aa4bf8]
0040e2a9  8344245402               add       dword ptr [esp + 0x54], 2
0040e2ae  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0040e2b2  01c5                     add       ebp, eax
0040e2b4  836c243801               sub       dword ptr [esp + 0x38], 1
0040e2b9  0f8578e3ffff             jne       0x40c637
0040e2bf  b800000000               mov       eax, 0
0040e2c4  5f                       pop       edi
0040e2c5  5e                       pop       esi
0040e2c6  5b                       pop       ebx
0040e2c7  5d                       pop       ebp
0040e2c8  81c484040000             add       esp, 0x484
0040e2ce  c3                       ret
0040e2cf  90                       nop
