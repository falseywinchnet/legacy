; _contrl_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x22ba0
00422ba0  83ec34                   sub       esp, 0x34
00422ba3  53                       push      ebx
00422ba4  56                       push      esi
00422ba5  57                       push      edi
00422ba6  8b442444                 mov       eax, dword ptr [esp + 0x44]
00422baa  8b4c2448                 mov       ecx, dword ptr [esp + 0x48]
00422bae  89442420                 mov       dword ptr [esp + 0x20], eax
00422bb2  894c241c                 mov       dword ptr [esp + 0x1c], ecx
00422bb6  8b442420                 mov       eax, dword ptr [esp + 0x20]
00422bba  8b08                     mov       ecx, dword ptr [eax]
00422bbc  8b542460                 mov       edx, dword ptr [esp + 0x60]
00422bc0  8b748a04                 mov       esi, dword ptr [edx + ecx*4 + 4]
00422bc4  89359c625200             mov       dword ptr [0x52629c], esi ; bits=00000000, f32=0.0
00422bca  8b748a08                 mov       esi, dword ptr [edx + ecx*4 + 8]
00422bce  8b1d9c625200             mov       ebx, dword ptr [0x52629c] ; bits=00000000, f32=0.0
00422bd4  8b3c9d1c9e0002           mov       edi, dword ptr [ebx*4 + 0x2009e1c]
00422bdb  893de4625200             mov       dword ptr [0x5262e4], edi ; bits=00000000, f32=0.0
00422be1  8b3c8a                   mov       edi, dword ptr [edx + ecx*4]
00422be4  83ff07                   cmp       edi, 7
00422be7  89742418                 mov       dword ptr [esp + 0x18], esi
00422beb  897c2414                 mov       dword ptr [esp + 0x14], edi
00422bef  730d                     jae       0x422bfe
00422bf1  8b442414                 mov       eax, dword ptr [esp + 0x14]
00422bf5  8b348568645200           mov       esi, dword ptr [eax*4 + 0x526468]
00422bfc  ffe6                     jmp       esi
00422bfe  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
00422c02  8b08                     mov       ecx, dword ptr [eax]
00422c04  8d0550625200             lea       eax, [0x526250] ; bits=09820000, f32=4.664782457890884e-41
00422c0a  894c243c                 mov       dword ptr [esp + 0x3c], ecx
00422c0e  8d4c243c                 lea       ecx, [esp + 0x3c]
00422c12  894808                   mov       dword ptr [eax + 8], ecx
00422c15  8b4c2414                 mov       ecx, dword ptr [esp + 0x14]
00422c19  894c2438                 mov       dword ptr [esp + 0x38], ecx
00422c1d  8d4c2438                 lea       ecx, [esp + 0x38]
00422c21  894834                   mov       dword ptr [eax + 0x34], ecx
00422c24  50                       push      eax
00422c25  e8d6990900               call      0x4bc600 ; _jwe_ilst
00422c2a  83c404                   add       esp, 4
00422c2d  68a8615200               push      0x5261a8
00422c32  e819a80900               call      0x4bd450 ; _jwe_xstp
00422c37  83c404                   add       esp, 4
00422c3a  89d0                     mov       eax, edx
00422c3c  8b448810                 mov       eax, dword ptr [eax + ecx*4 + 0x10]
00422c40  890588625200             mov       dword ptr [0x526288], eax ; bits=00000000, f32=0.0
00422c46  89d0                     mov       eax, edx
00422c48  8b448814                 mov       eax, dword ptr [eax + ecx*4 + 0x14]
00422c4c  890510635200             mov       dword ptr [0x526310], eax ; bits=00000000, f32=0.0
00422c52  d90510635200             fld       dword ptr [0x526310] ; bits=00000000, f32=0.0
00422c58  89d0                     mov       eax, edx
00422c5a  8b448818                 mov       eax, dword ptr [eax + ecx*4 + 0x18]
00422c5e  890510635200             mov       dword ptr [0x526310], eax ; bits=00000000, f32=0.0
00422c64  d90510635200             fld       dword ptr [0x526310] ; bits=00000000, f32=0.0
00422c6a  89d8                     mov       eax, ebx
00422c6c  d905e4625200             fld       dword ptr [0x5262e4] ; bits=00000000, f32=0.0
00422c72  d804859ca40102           fadd      dword ptr [eax*4 + 0x201a49c]
00422c79  dee2                     fsubrp    st(2)
00422c7b  d9c9                     fxch      st(1)
00422c7d  d91dc4625200             fstp      dword ptr [0x5262c4] ; bits=00000000, f32=0.0
00422c83  d905c4625200             fld       dword ptr [0x5262c4] ; bits=00000000, f32=0.0
00422c89  d9ee                     fldz
00422c8b  dff1                     fcompi    st(1)
00422c8d  ddd8                     fstp      st(0)
00422c8f  0f8a02000000             jp        0x422c97
00422c95  721b                     jb        0x422cb2
00422c97  ddd8                     fstp      st(0)
00422c99  8b442474                 mov       eax, dword ptr [esp + 0x74]
00422c9d  c70000000000             mov       dword ptr [eax], 0
00422ca3  8b442478                 mov       eax, dword ptr [esp + 0x78]
00422ca7  c70000000000             mov       dword ptr [eax], 0
00422cad  e985050000               jmp       0x423237
00422cb2  db7c2424                 fstp      xword ptr [esp + 0x24]
00422cb6  68d0625200               push      0x5262d0
00422cbb  6894625200               push      0x526294
00422cc0  68e0625200               push      0x5262e0
00422cc5  8d1dc8605200             lea       ebx, [0x5260c8] ; bits=b0040000, f32=1.6815581571897805e-42
00422ccb  8d4394                   lea       eax, [ebx - 0x6c]
00422cce  50                       push      eax
00422ccf  68c4625200               push      0x5262c4
00422cd4  6888625200               push      0x526288
00422cd9  e862300100               call      0x435d40 ; _lktab_
00422cde  83c418                   add       esp, 0x18
00422ce1  d905e0625200             fld       dword ptr [0x5262e0] ; bits=00000000, f32=0.0
00422ce7  db6c2424                 fld       xword ptr [esp + 0x24]
00422ceb  d80de0625200             fmul      dword ptr [0x5262e0] ; bits=00000000, f32=0.0
00422cf1  d905c4625200             fld       dword ptr [0x5262c4] ; bits=00000000, f32=0.0
00422cf7  d9c9                     fxch      st(1)
00422cf9  d80dc4625200             fmul      dword ptr [0x5262c4] ; bits=00000000, f32=0.0
00422cff  d9c1                     fld       st(1)
00422d01  d9fa                     fsqrt
00422d03  d95c2434                 fstp      dword ptr [esp + 0x34]
00422d07  d9442434                 fld       dword ptr [esp + 0x34]
00422d0b  d9c9                     fxch      st(1)
00422d0d  d84c2434                 fmul      dword ptr [esp + 0x34]
00422d11  8b442478                 mov       eax, dword ptr [esp + 0x78]
00422d15  d918                     fstp      dword ptr [eax]
00422d17  d9c9                     fxch      st(1)
00422d19  d80dd0625200             fmul      dword ptr [0x5262d0] ; bits=00000000, f32=0.0
00422d1f  d9ca                     fxch      st(2)
00422d21  d84b88                   fmul      dword ptr [ebx - 0x78]
00422d24  dec2                     faddp     st(2)
00422d26  dec9                     fmulp     st(1)
00422d28  db6c2424                 fld       xword ptr [esp + 0x24]
00422d2c  dec9                     fmulp     st(1)
00422d2e  8b442474                 mov       eax, dword ptr [esp + 0x74]
00422d32  d918                     fstp      dword ptr [eax]
00422d34  e9fe040000               jmp       0x423237
00422d39  89d0                     mov       eax, edx
00422d3b  8b448810                 mov       eax, dword ptr [eax + ecx*4 + 0x10]
00422d3f  890588625200             mov       dword ptr [0x526288], eax ; bits=00000000, f32=0.0
00422d45  89d0                     mov       eax, edx
00422d47  8b448814                 mov       eax, dword ptr [eax + ecx*4 + 0x14]
00422d4b  890510635200             mov       dword ptr [0x526310], eax ; bits=00000000, f32=0.0
00422d51  89d8                     mov       eax, ebx
00422d53  d905e4625200             fld       dword ptr [0x5262e4] ; bits=00000000, f32=0.0
00422d59  d804859ca40102           fadd      dword ptr [eax*4 + 0x201a49c]
00422d60  d82510635200             fsub      dword ptr [0x526310] ; bits=00000000, f32=0.0
00422d66  d91dc4625200             fstp      dword ptr [0x5262c4] ; bits=00000000, f32=0.0
00422d6c  8b442474                 mov       eax, dword ptr [esp + 0x74]
00422d70  8d00                     lea       eax, [eax]
00422d72  50                       push      eax
00422d73  6894625200               push      0x526294
00422d78  8b842480000000           mov       eax, dword ptr [esp + 0x80]
00422d7f  8d00                     lea       eax, [eax]
00422d81  50                       push      eax
00422d82  685c605200               push      0x52605c
00422d87  68c4625200               push      0x5262c4
00422d8c  6888625200               push      0x526288
00422d91  e8aa2f0100               call      0x435d40 ; _lktab_
00422d96  83c418                   add       esp, 0x18
00422d99  e999040000               jmp       0x423237
00422d9e  89d0                     mov       eax, edx
00422da0  8b748810                 mov       esi, dword ptr [eax + ecx*4 + 0x10]
00422da4  89d0                     mov       eax, edx
00422da6  8b448814                 mov       eax, dword ptr [eax + ecx*4 + 0x14]
00422daa  890510635200             mov       dword ptr [0x526310], eax ; bits=00000000, f32=0.0
00422db0  d90510635200             fld       dword ptr [0x526310] ; bits=00000000, f32=0.0
00422db6  89d8                     mov       eax, ebx
00422db8  8d0cc0                   lea       ecx, [eax + eax*8]
00422dbb  8b44245c                 mov       eax, dword ptr [esp + 0x5c]
00422dbf  8b7c88e8                 mov       edi, dword ptr [eax + ecx*4 - 0x18]
00422dc3  893da0625200             mov       dword ptr [0x5262a0], edi ; bits=00000000, f32=0.0
00422dc9  83feff                   cmp       esi, -1
00422dcc  89442410                 mov       dword ptr [esp + 0x10], eax
00422dd0  8974240c                 mov       dword ptr [esp + 0xc], esi
00422dd4  744f                     je        0x422e25
00422dd6  8b442410                 mov       eax, dword ptr [esp + 0x10]
00422dda  8b4c88e0                 mov       ecx, dword ptr [eax + ecx*4 - 0x20]
00422dde  8b44240c                 mov       eax, dword ptr [esp + 0xc]
00422de2  85c0                     test      eax, eax
00422de4  7516                     jne       0x422dfc
00422de6  ddd8                     fstp      st(0)
00422de8  8b442468                 mov       eax, dword ptr [esp + 0x68]
00422dec  d94488fc                 fld       dword ptr [eax + ecx*4 - 4]
00422df0  d86c88f8                 fsubr     dword ptr [eax + ecx*4 - 8]
00422df4  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
00422df8  d87488fc                 fdiv      dword ptr [eax + ecx*4 - 4]
00422dfc  837c240c01               cmp       dword ptr [esp + 0xc], 1
00422e01  7522                     jne       0x422e25
00422e03  ddd8                     fstp      st(0)
00422e05  8b442464                 mov       eax, dword ptr [esp + 0x64]
00422e09  8b542468                 mov       edx, dword ptr [esp + 0x68]
00422e0d  d9448af8                 fld       dword ptr [edx + ecx*4 - 8]
00422e11  d84488f8                 fadd      dword ptr [eax + ecx*4 - 8]
00422e15  d86488fc                 fsub      dword ptr [eax + ecx*4 - 4]
00422e19  d8648afc                 fsub      dword ptr [edx + ecx*4 - 4]
00422e1d  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
00422e21  d87488fc                 fdiv      dword ptr [eax + ecx*4 - 4]
00422e25  db7c2424                 fstp      xword ptr [esp + 0x24]
00422e29  68b4625200               push      0x5262b4
00422e2e  68a8625200               push      0x5262a8
00422e33  68b8625200               push      0x5262b8
00422e38  68b0625200               push      0x5262b0
00422e3d  68bc625200               push      0x5262bc
00422e42  68dc625200               push      0x5262dc
00422e47  68a4625200               push      0x5262a4
00422e4c  68e4625200               push      0x5262e4
00422e51  68a0625200               push      0x5262a0
00422e56  e895790100               call      0x43a7f0 ; _xlkt20_
00422e5b  83c424                   add       esp, 0x24
00422e5e  d9ee                     fldz
00422e60  db6c2424                 fld       xword ptr [esp + 0x24]
00422e64  dff1                     fcompi    st(1)
00422e66  ddd8                     fstp      st(0)
00422e68  db6c2424                 fld       xword ptr [esp + 0x24]
00422e6c  0f8a45000000             jp        0x422eb7
00422e72  7743                     ja        0x422eb7
00422e74  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
00422e78  ddd8                     fstp      st(0)
00422e7a  8b18                     mov       ebx, dword ptr [eax]
00422e7c  689c625200               push      0x52629c
00422e81  6a05                     push      5
00422e83  68f8625200               push      0x5262f8
00422e88  e833a40400               call      0x46d2c0 ; _getusn_
00422e8d  83c40c                   add       esp, 0xc
00422e90  8d0524625200             lea       eax, [0x526224] ; bits=09020000, f32=7.300764999132297e-43
00422e96  895c243c                 mov       dword ptr [esp + 0x3c], ebx
00422e9a  8d4c243c                 lea       ecx, [esp + 0x3c]
00422e9e  894808                   mov       dword ptr [eax + 8], ecx
00422ea1  50                       push      eax
00422ea2  e8199d0900               call      0x4bcbc0 ; _jwe_isfm
00422ea7  83c404                   add       esp, 4
00422eaa  689c615200               push      0x52619c
00422eaf  e89ca50900               call      0x4bd450 ; _jwe_xstp
00422eb4  83c404                   add       esp, 4
00422eb7  d9fa                     fsqrt
00422eb9  d95c2434                 fstp      dword ptr [esp + 0x34]
00422ebd  d9442434                 fld       dword ptr [esp + 0x34]
00422ec1  d905b0625200             fld       dword ptr [0x5262b0] ; bits=00000000, f32=0.0
00422ec7  d84c2434                 fmul      dword ptr [esp + 0x34]
00422ecb  8b442478                 mov       eax, dword ptr [esp + 0x78]
00422ecf  d918                     fstp      dword ptr [eax]
00422ed1  d80db8625200             fmul      dword ptr [0x5262b8] ; bits=00000000, f32=0.0
00422ed7  8b442474                 mov       eax, dword ptr [esp + 0x74]
00422edb  d918                     fstp      dword ptr [eax]
00422edd  e955030000               jmp       0x423237
00422ee2  89d0                     mov       eax, edx
00422ee4  8b448810                 mov       eax, dword ptr [eax + ecx*4 + 0x10]
00422ee8  890588625200             mov       dword ptr [0x526288], eax ; bits=00000000, f32=0.0
00422eee  89d0                     mov       eax, edx
00422ef0  8b448818                 mov       eax, dword ptr [eax + ecx*4 + 0x18]
00422ef4  890510635200             mov       dword ptr [0x526310], eax ; bits=00000000, f32=0.0
00422efa  89d8                     mov       eax, ebx
00422efc  d905e4625200             fld       dword ptr [0x5262e4] ; bits=00000000, f32=0.0
00422f02  d804859ca40102           fadd      dword ptr [eax*4 + 0x201a49c]
00422f09  d82510635200             fsub      dword ptr [0x526310] ; bits=00000000, f32=0.0
00422f0f  d91dc4625200             fstp      dword ptr [0x5262c4] ; bits=00000000, f32=0.0
00422f15  d905c4625200             fld       dword ptr [0x5262c4] ; bits=00000000, f32=0.0
00422f1b  d9ee                     fldz
00422f1d  d9c9                     fxch      st(1)
00422f1f  dff1                     fcompi    st(1)
00422f21  0f8a02000000             jp        0x422f29
00422f27  731b                     jae       0x422f44
00422f29  ddd8                     fstp      st(0)
00422f2b  8b442474                 mov       eax, dword ptr [esp + 0x74]
00422f2f  c70000000000             mov       dword ptr [eax], 0
00422f35  8b442478                 mov       eax, dword ptr [esp + 0x78]
00422f39  c70000000000             mov       dword ptr [eax], 0
00422f3f  e9f3020000               jmp       0x423237
00422f44  db7c2424                 fstp      xword ptr [esp + 0x24]
00422f48  8b442474                 mov       eax, dword ptr [esp + 0x74]
00422f4c  8d00                     lea       eax, [eax]
00422f4e  50                       push      eax
00422f4f  6894625200               push      0x526294
00422f54  8b842480000000           mov       eax, dword ptr [esp + 0x80]
00422f5b  8d00                     lea       eax, [eax]
00422f5d  50                       push      eax
00422f5e  685c605200               push      0x52605c
00422f63  68c4625200               push      0x5262c4
00422f68  6888625200               push      0x526288
00422f6d  e8ce2d0100               call      0x435d40 ; _lktab_
00422f72  db6c243c                 fld       xword ptr [esp + 0x3c]
00422f76  83c418                   add       esp, 0x18
00422f79  837c241405               cmp       dword ptr [esp + 0x14], 5
00422f7e  0f84a2000000             je        0x423026
00422f84  8b442420                 mov       eax, dword ptr [esp + 0x20]
00422f88  ddd8                     fstp      st(0)
00422f8a  8b08                     mov       ecx, dword ptr [eax]
00422f8c  8b442460                 mov       eax, dword ptr [esp + 0x60]
00422f90  8b448814                 mov       eax, dword ptr [eax + ecx*4 + 0x14]
00422f94  890588625200             mov       dword ptr [0x526288], eax ; bits=00000000, f32=0.0
00422f9a  68c4625200               push      0x5262c4
00422f9f  6894625200               push      0x526294
00422fa4  68c8625200               push      0x5262c8
00422fa9  8b442464                 mov       eax, dword ptr [esp + 0x64]
00422fad  8d00                     lea       eax, [eax]
00422faf  50                       push      eax
00422fb0  6888625200               push      0x526288
00422fb5  e8f6310100               call      0x4361b0 ; _lktstab_
00422fba  83c414                   add       esp, 0x14
00422fbd  d905c8625200             fld       dword ptr [0x5262c8] ; bits=00000000, f32=0.0
00422fc3  d9ee                     fldz
00422fc5  dff1                     fcompi    st(1)
00422fc7  0f8a02000000             jp        0x422fcf
00422fcd  7714                     ja        0x422fe3
00422fcf  d9e8                     fld1
00422fd1  dff1                     fcompi    st(1)
00422fd3  ddd8                     fstp      st(0)
00422fd5  0f8a33010000             jp        0x42310e
00422fdb  0f832d010000             jae       0x42310e
00422fe1  eb02                     jmp       0x422fe5
00422fe3  ddd8                     fstp      st(0)
00422fe5  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
00422fe9  8b18                     mov       ebx, dword ptr [eax]
00422feb  6894625200               push      0x526294
00422ff0  6a10                     push      0x10
00422ff2  6800635200               push      0x526300
00422ff7  e874830700               call      0x49b370 ; _get_tabid_
00422ffc  83c40c                   add       esp, 0xc
00422fff  8d05f8615200             lea       eax, [0x5261f8] ; bits=09020000, f32=7.300764999132297e-43
00423005  895c243c                 mov       dword ptr [esp + 0x3c], ebx
00423009  8d4c243c                 lea       ecx, [esp + 0x3c]
0042300d  894808                   mov       dword ptr [eax + 8], ecx
00423010  50                       push      eax
00423011  e8aa9b0900               call      0x4bcbc0 ; _jwe_isfm
00423016  83c404                   add       esp, 4
00423019  6890615200               push      0x526190
0042301e  e82da40900               call      0x4bd450 ; _jwe_xstp
00423023  83c404                   add       esp, 4
00423026  8b442420                 mov       eax, dword ptr [esp + 0x20]
0042302a  8b10                     mov       edx, dword ptr [eax]
0042302c  8b442460                 mov       eax, dword ptr [esp + 0x60]
00423030  8b5c901c                 mov       ebx, dword ptr [eax + edx*4 + 0x1c]
00423034  891d10635200             mov       dword ptr [0x526310], ebx ; bits=00000000, f32=0.0
0042303a  8b4c9024                 mov       ecx, dword ptr [eax + edx*4 + 0x24]
0042303e  8b0510635200             mov       eax, dword ptr [0x526310] ; bits=00000000, f32=0.0
00423044  8905c8625200             mov       dword ptr [0x5262c8], eax ; bits=00000000, f32=0.0
0042304a  89048da4946901           mov       dword ptr [ecx*4 + 0x16994a4], eax
00423051  d90510635200             fld       dword ptr [0x526310] ; bits=00000000, f32=0.0
00423057  dfe9                     fucompi   st(1)
00423059  ddd8                     fstp      st(0)
0042305b  0f8a35000000             jp        0x423096
00423061  7533                     jne       0x423096
00423063  8d04cd90996901           lea       eax, [ecx*8 + 0x1699990]
0042306a  c60020                   mov       byte ptr [eax], 0x20
0042306d  c6400120                 mov       byte ptr [eax + 1], 0x20
00423071  c6400243                 mov       byte ptr [eax + 2], 0x43
00423075  c640036c                 mov       byte ptr [eax + 3], 0x6c
00423079  c640046f                 mov       byte ptr [eax + 4], 0x6f
0042307d  c6400573                 mov       byte ptr [eax + 5], 0x73
00423081  c6400665                 mov       byte ptr [eax + 6], 0x65
00423085  c6400764                 mov       byte ptr [eax + 7], 0x64
00423089  c7048d7495690104000000   mov       dword ptr [ecx*4 + 0x1699574], 4
00423094  eb78                     jmp       0x42310e
00423096  d905c8625200             fld       dword ptr [0x5262c8] ; bits=00000000, f32=0.0
0042309c  d9e8                     fld1
0042309e  dff1                     fcompi    st(1)
004230a0  ddd8                     fstp      st(0)
004230a2  0f8a35000000             jp        0x4230dd
004230a8  7633                     jbe       0x4230dd
004230aa  8d04cd90996901           lea       eax, [ecx*8 + 0x1699990]
004230b1  c60020                   mov       byte ptr [eax], 0x20
004230b4  c6400120                 mov       byte ptr [eax + 1], 0x20
004230b8  c6400220                 mov       byte ptr [eax + 2], 0x20
004230bc  c6400320                 mov       byte ptr [eax + 3], 0x20
004230c0  c640044f                 mov       byte ptr [eax + 4], 0x4f
004230c4  c6400570                 mov       byte ptr [eax + 5], 0x70
004230c8  c6400665                 mov       byte ptr [eax + 6], 0x65
004230cc  c640076e                 mov       byte ptr [eax + 7], 0x6e
004230d0  c7048d7495690105000000   mov       dword ptr [ecx*4 + 0x1699574], 5
004230db  eb31                     jmp       0x42310e
004230dd  8d04cd90996901           lea       eax, [ecx*8 + 0x1699990]
004230e4  c6004d                   mov       byte ptr [eax], 0x4d
004230e7  c6400161                 mov       byte ptr [eax + 1], 0x61
004230eb  c6400278                 mov       byte ptr [eax + 2], 0x78
004230ef  c6400320                 mov       byte ptr [eax + 3], 0x20
004230f3  c640044f                 mov       byte ptr [eax + 4], 0x4f
004230f7  c6400570                 mov       byte ptr [eax + 5], 0x70
004230fb  c6400665                 mov       byte ptr [eax + 6], 0x65
004230ff  c640076e                 mov       byte ptr [eax + 7], 0x6e
00423103  c7048d7495690106000000   mov       dword ptr [ecx*4 + 0x1699574], 6
0042310e  8b442478                 mov       eax, dword ptr [esp + 0x78]
00423112  d905c8625200             fld       dword ptr [0x5262c8] ; bits=00000000, f32=0.0
00423118  d9c0                     fld       st(0)
0042311a  d808                     fmul      dword ptr [eax]
0042311c  d918                     fstp      dword ptr [eax]
0042311e  8b442474                 mov       eax, dword ptr [esp + 0x74]
00423122  d808                     fmul      dword ptr [eax]
00423124  d918                     fstp      dword ptr [eax]
00423126  e90c010000               jmp       0x423237
0042312b  8b448a10                 mov       eax, dword ptr [edx + ecx*4 + 0x10]
0042312f  890598625200             mov       dword ptr [0x526298], eax ; bits=00000000, f32=0.0
00423135  8b448a14                 mov       eax, dword ptr [edx + ecx*4 + 0x14]
00423139  89058c625200             mov       dword ptr [0x52628c], eax ; bits=00000000, f32=0.0
0042313f  8b448a18                 mov       eax, dword ptr [edx + ecx*4 + 0x18]
00423143  890590625200             mov       dword ptr [0x526290], eax ; bits=00000000, f32=0.0
00423149  8b448a1c                 mov       eax, dword ptr [edx + ecx*4 + 0x1c]
0042314d  890510635200             mov       dword ptr [0x526310], eax ; bits=00000000, f32=0.0
00423153  d905e4625200             fld       dword ptr [0x5262e4] ; bits=00000000, f32=0.0
00423159  d8049d9ca40102           fadd      dword ptr [ebx*4 + 0x201a49c]
00423160  d82510635200             fsub      dword ptr [0x526310] ; bits=00000000, f32=0.0
00423166  d91dc4625200             fstp      dword ptr [0x5262c4] ; bits=00000000, f32=0.0
0042316c  d905c4625200             fld       dword ptr [0x5262c4] ; bits=00000000, f32=0.0
00423172  d9ee                     fldz
00423174  dff1                     fcompi    st(1)
00423176  ddd8                     fstp      st(0)
00423178  0f8a0c000000             jp        0x42318a
0042317e  760a                     jbe       0x42318a
00423180  c705c462520000000000     mov       dword ptr [0x5262c4], 0 ; bits=00000000, f32=0.0
0042318a  8b5c2474                 mov       ebx, dword ptr [esp + 0x74]
0042318e  8d03                     lea       eax, [ebx]
00423190  50                       push      eax
00423191  6894625200               push      0x526294
00423196  68d4625200               push      0x5262d4
0042319b  8d35c8605200             lea       esi, [0x5260c8] ; bits=b0040000, f32=1.6815581571897805e-42
004231a1  8d4694                   lea       eax, [esi - 0x6c]
004231a4  50                       push      eax
004231a5  68c4625200               push      0x5262c4
004231aa  6898625200               push      0x526298
004231af  e88c2b0100               call      0x435d40 ; _lktab_
004231b4  83c418                   add       esp, 0x18
004231b7  68cc625200               push      0x5262cc
004231bc  6894625200               push      0x526294
004231c1  68ac625200               push      0x5262ac
004231c6  8b442464                 mov       eax, dword ptr [esp + 0x64]
004231ca  8d00                     lea       eax, [eax]
004231cc  50                       push      eax
004231cd  688c625200               push      0x52628c
004231d2  e8d92f0100               call      0x4361b0 ; _lktstab_
004231d7  83c414                   add       esp, 0x14
004231da  68cc625200               push      0x5262cc
004231df  6894625200               push      0x526294
004231e4  68d8625200               push      0x5262d8
004231e9  8d7694                   lea       esi, [esi - 0x6c]
004231ec  56                       push      esi
004231ed  68ac625200               push      0x5262ac
004231f2  6890625200               push      0x526290
004231f7  e8442b0100               call      0x435d40 ; _lktab_
004231fc  83c418                   add       esp, 0x18
004231ff  d905d4625200             fld       dword ptr [0x5262d4] ; bits=00000000, f32=0.0
00423205  d905d8625200             fld       dword ptr [0x5262d8] ; bits=00000000, f32=0.0
0042320b  dff1                     fcompi    st(1)
0042320d  ddd8                     fstp      st(0)
0042320f  0f8a10000000             jp        0x423225
00423215  720e                     jb        0x423225
00423217  8b442478                 mov       eax, dword ptr [esp + 0x78]
0042321b  8b0dd4625200             mov       ecx, dword ptr [0x5262d4] ; bits=00000000, f32=0.0
00423221  8908                     mov       dword ptr [eax], ecx
00423223  eb12                     jmp       0x423237
00423225  8b442478                 mov       eax, dword ptr [esp + 0x78]
00423229  8b0dd8625200             mov       ecx, dword ptr [0x5262d8] ; bits=00000000, f32=0.0
0042322f  8908                     mov       dword ptr [eax], ecx
00423231  c70300000000             mov       dword ptr [ebx], 0
00423237  837c241800               cmp       dword ptr [esp + 0x18], 0
0042323c  7d14                     jge       0x423252
0042323e  8b442478                 mov       eax, dword ptr [esp + 0x78]
00423242  d900                     fld       dword ptr [eax]
00423244  d9e0                     fchs
00423246  d918                     fstp      dword ptr [eax]
00423248  8b442474                 mov       eax, dword ptr [esp + 0x74]
0042324c  d900                     fld       dword ptr [eax]
0042324e  d9e0                     fchs
00423250  d918                     fstp      dword ptr [eax]
00423252  8b442454                 mov       eax, dword ptr [esp + 0x54]
00423256  833804                   cmp       dword ptr [eax], 4
00423259  7e53                     jle       0x4232ae
0042325b  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
0042325f  8b08                     mov       ecx, dword ptr [eax]
00423261  8b059c625200             mov       eax, dword ptr [0x52629c] ; bits=00000000, f32=0.0
00423267  8b542474                 mov       edx, dword ptr [esp + 0x74]
0042326b  8b12                     mov       edx, dword ptr [edx]
0042326d  8b5c2478                 mov       ebx, dword ptr [esp + 0x78]
00423271  8b1b                     mov       ebx, dword ptr [ebx]
00423273  8d35b4615200             lea       esi, [0x5261b4] ; bits=09020000, f32=7.300764999132297e-43
00423279  894c243c                 mov       dword ptr [esp + 0x3c], ecx
0042327d  8d4c243c                 lea       ecx, [esp + 0x3c]
00423281  894e08                   mov       dword ptr [esi + 8], ecx
00423284  89442438                 mov       dword ptr [esp + 0x38], eax
00423288  8d442438                 lea       eax, [esp + 0x38]
0042328c  894628                   mov       dword ptr [esi + 0x28], eax
0042328f  89542434                 mov       dword ptr [esp + 0x34], edx
00423293  8d442434                 lea       eax, [esp + 0x34]
00423297  894634                   mov       dword ptr [esi + 0x34], eax
0042329a  895c2430                 mov       dword ptr [esp + 0x30], ebx
0042329e  8d442430                 lea       eax, [esp + 0x30]
004232a2  894640                   mov       dword ptr [esi + 0x40], eax
004232a5  56                       push      esi
004232a6  e815990900               call      0x4bcbc0 ; _jwe_isfm
004232ab  83c404                   add       esp, 4
004232ae  b800000000               mov       eax, 0
004232b3  5f                       pop       edi
004232b4  5e                       pop       esi
004232b5  5b                       pop       ebx
004232b6  83c434                   add       esp, 0x34
004232b9  c3                       ret
004232ba  8d9b00000000             lea       ebx, [ebx]
