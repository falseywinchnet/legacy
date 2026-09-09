; _r4to44_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2b150
0042b150  55                       push      ebp
0042b151  8bec                     mov       ebp, esp
0042b153  53                       push      ebx
0042b154  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0042b157  8b01                     mov       eax, dword ptr [ecx]
0042b159  8d1da8a65600             lea       ebx, [0x56a6a8] ; bits=31110000, f32=6.16711454149352e-42
0042b15f  894380                   mov       dword ptr [ebx - 0x80], eax
0042b162  6838f5f200               push      0xf2f538
0042b167  6834f5f200               push      0xf2f534
0042b16c  6830f5f200               push      0xf2f530
0042b171  682cf5f200               push      0xf2f52c
0042b176  6828f5f200               push      0xf2f528
0042b17b  6824f5f200               push      0xf2f524
0042b180  6820f5f200               push      0xf2f520
0042b185  6818f5f200               push      0xf2f518
0042b18a  6814f5f200               push      0xf2f514
0042b18f  681cf5f200               push      0xf2f51c
0042b194  8d4380                   lea       eax, [ebx - 0x80]
0042b197  50                       push      eax
0042b198  6800f5f200               push      0xf2f500 ; _x44com_
0042b19d  e8fe030200               call      0x44b5a0 ; _xlktal_
0042b1a2  83c430                   add       esp, 0x30
0042b1a5  d9051cf5f200             fld       dword ptr [0xf2f51c]
0042b1ab  d83d04f5f200             fdivr     dword ptr [0xf2f504]
0042b1b1  d8c8                     fmul      st(0)
0042b1b3  d80d34f5f200             fmul      dword ptr [0xf2f534]
0042b1b9  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042b1bf  d84380                   fadd      dword ptr [ebx - 0x80]
0042b1c2  d825f0b1e900             fsub      dword ptr [0xe9b1f0]
0042b1c8  5b                       pop       ebx
0042b1c9  8be5                     mov       esp, ebp
0042b1cb  5d                       pop       ebp
0042b1cc  c3                       ret
0042b1cd  8d4900                   lea       ecx, [ecx]
