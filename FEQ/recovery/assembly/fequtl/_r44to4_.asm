; _r44to4_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2b0d0
0042b0d0  55                       push      ebp
0042b0d1  8bec                     mov       ebp, esp
0042b0d3  53                       push      ebx
0042b0d4  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0042b0d7  8b01                     mov       eax, dword ptr [ecx]
0042b0d9  8d1da0a65600             lea       ebx, [0x56a6a0] ; bits=e0600000, f32=3.4752201915255463e-41
0042b0df  894380                   mov       dword ptr [ebx - 0x80], eax
0042b0e2  6898f5f200               push      0xf2f598
0042b0e7  6894f5f200               push      0xf2f594
0042b0ec  6890f5f200               push      0xf2f590
0042b0f1  688cf5f200               push      0xf2f58c
0042b0f6  6888f5f200               push      0xf2f588
0042b0fb  6884f5f200               push      0xf2f584
0042b100  6880f5f200               push      0xf2f580
0042b105  6878f5f200               push      0xf2f578
0042b10a  6874f5f200               push      0xf2f574
0042b10f  687cf5f200               push      0xf2f57c
0042b114  8d4380                   lea       eax, [ebx - 0x80]
0042b117  50                       push      eax
0042b118  6860f5f200               push      0xf2f560 ; _xs4com_
0042b11d  e87e040200               call      0x44b5a0 ; _xlktal_
0042b122  83c430                   add       esp, 0x30
0042b125  d9057cf5f200             fld       dword ptr [0xf2f57c]
0042b12b  d83d64f5f200             fdivr     dword ptr [0xf2f564]
0042b131  d8c8                     fmul      st(0)
0042b133  d80d94f5f200             fmul      dword ptr [0xf2f594]
0042b139  d83534bcf400             fdiv      dword ptr [0xf4bc34]
0042b13f  d84380                   fadd      dword ptr [ebx - 0x80]
0042b142  d825f4b1e900             fsub      dword ptr [0xe9b1f4]
0042b148  5b                       pop       ebx
0042b149  8be5                     mov       esp, ebp
0042b14b  5d                       pop       ebp
0042b14c  c3                       ret
0042b14d  8d4900                   lea       ecx, [ecx]
