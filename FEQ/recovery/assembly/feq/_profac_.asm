; _profac_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x6a5d0
0046a5d0  83ec64                   sub       esp, 0x64
0046a5d3  55                       push      ebp
0046a5d4  53                       push      ebx
0046a5d5  56                       push      esi
0046a5d6  57                       push      edi
0046a5d7  8b442478                 mov       eax, dword ptr [esp + 0x78]
0046a5db  89442460                 mov       dword ptr [esp + 0x60], eax
0046a5df  8b0520007501             mov       eax, dword ptr [0x1750020] ; _matcom_
0046a5e5  3d00000000               cmp       eax, 0
0046a5ea  8944245c                 mov       dword ptr [esp + 0x5c], eax
0046a5ee  0f8ee1030000             jle       0x46a9d5
0046a5f4  b801000000               mov       eax, 1
0046a5f9  89442458                 mov       dword ptr [esp + 0x58], eax
0046a5fd  8b442458                 mov       eax, dword ptr [esp + 0x58]
0046a601  8b0c852c0e7b01           mov       ecx, dword ptr [eax*4 + 0x17b0e2c]
0046a608  8b2c85f0527b01           mov       ebp, dword ptr [eax*4 + 0x17b52f0]
0046a60f  8b1485b4977b01           mov       edx, dword ptr [eax*4 + 0x17b97b4]
0046a616  83fa03                   cmp       edx, 3
0046a619  7309                     jae       0x46a624
0046a61b  8b0495f08d5500           mov       eax, dword ptr [edx*4 + 0x558df0]
0046a622  ffe0                     jmp       eax
0046a624  8b442460                 mov       eax, dword ptr [esp + 0x60]
0046a628  8b08                     mov       ecx, dword ptr [eax]
0046a62a  8d05188d5500             lea       eax, [0x558d18] ; bits=09020000, f32=7.300764999132297e-43
0046a630  894c2470                 mov       dword ptr [esp + 0x70], ecx
0046a634  8d4c2470                 lea       ecx, [esp + 0x70]
0046a638  894808                   mov       dword ptr [eax + 8], ecx
0046a63b  8954246c                 mov       dword ptr [esp + 0x6c], edx
0046a63f  8d4c246c                 lea       ecx, [esp + 0x6c]
0046a643  894828                   mov       dword ptr [eax + 0x28], ecx
0046a646  50                       push      eax
0046a647  e874250500               call      0x4bcbc0 ; _jwe_isfm
0046a64c  83c404                   add       esp, 4
0046a64f  68c88c5500               push      0x558cc8
0046a654  e8f72d0500               call      0x4bd450 ; _jwe_xstp
0046a659  83c404                   add       esp, 4
0046a65c  89c8                     mov       eax, ecx
0046a65e  89ea                     mov       edx, ebp
0046a660  29ca                     sub       edx, ecx
0046a662  42                       inc       edx
0046a663  83fa00                   cmp       edx, 0
0046a666  8944244c                 mov       dword ptr [esp + 0x4c], eax
0046a66a  89542448                 mov       dword ptr [esp + 0x48], edx
0046a66e  0f8e52030000             jle       0x46a9c6
0046a674  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
0046a678  89442444                 mov       dword ptr [esp + 0x44], eax
0046a67c  8b442444                 mov       eax, dword ptr [esp + 0x44]
0046a680  8b1485a8837601           mov       edx, dword ptr [eax*4 + 0x17683a8]
0046a687  42                       inc       edx
0046a688  8b1c8528007501           mov       ebx, dword ptr [eax*4 + 0x1750028]
0046a68f  8d48ff                   lea       ecx, [eax - 1]
0046a692  29d9                     sub       ecx, ebx
0046a694  89ce                     mov       esi, ecx
0046a696  01d6                     add       esi, edx
0046a698  89742440                 mov       dword ptr [esp + 0x40], esi
0046a69c  8954243c                 mov       dword ptr [esp + 0x3c], edx
0046a6a0  895c2438                 mov       dword ptr [esp + 0x38], ebx
0046a6a4  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0046a6a8  89c5                     mov       ebp, eax
0046a6aa  8b4c2438                 mov       ecx, dword ptr [esp + 0x38]
0046a6ae  29c1                     sub       ecx, eax
0046a6b0  41                       inc       ecx
0046a6b1  83f900                   cmp       ecx, 0
0046a6b4  894c2430                 mov       dword ptr [esp + 0x30], ecx
0046a6b8  0f8e35010000             jle       0x46a7f3
0046a6be  8b5c2440                 mov       ebx, dword ptr [esp + 0x40]
0046a6c2  8d55ff                   lea       edx, [ebp - 1]
0046a6c5  8b349dac837601           mov       esi, dword ptr [ebx*4 + 0x17683ac]
0046a6cc  8d7eff                   lea       edi, [esi - 1]
0046a6cf  8b049d28007501           mov       eax, dword ptr [ebx*4 + 0x1750028]
0046a6d6  40                       inc       eax
0046a6d7  d9ee                     fldz
0046a6d9  89742428                 mov       dword ptr [esp + 0x28], esi
0046a6dd  89d6                     mov       esi, edx
0046a6df  2b74243c                 sub       esi, dword ptr [esp + 0x3c]
0046a6e3  89fb                     mov       ebx, edi
0046a6e5  29c3                     sub       ebx, eax
0046a6e7  89d9                     mov       ecx, ebx
0046a6e9  39f1                     cmp       ecx, esi
0046a6eb  89542424                 mov       dword ptr [esp + 0x24], edx
0046a6ef  89742420                 mov       dword ptr [esp + 0x20], esi
0046a6f3  897c241c                 mov       dword ptr [esp + 0x1c], edi
0046a6f7  7e06                     jle       0x46a6ff
0046a6f9  8b442420                 mov       eax, dword ptr [esp + 0x20]
0046a6fd  89c1                     mov       ecx, eax
0046a6ff  89c8                     mov       eax, ecx
0046a701  40                       inc       eax
0046a702  89c3                     mov       ebx, eax
0046a704  83fb00                   cmp       ebx, 0
0046a707  7e53                     jle       0x46a75c
0046a709  8b442424                 mov       eax, dword ptr [esp + 0x24]
0046a70d  89c1                     mov       ecx, eax
0046a70f  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
0046a713  89c2                     mov       edx, eax
0046a715  83fb02                   cmp       ebx, 2
0046a718  7c2e                     jl        0x46a748
0046a71a  d90495f8e27c01           fld       dword ptr [edx*4 + 0x17ce2f8]
0046a721  d80c8df8e27c01           fmul      dword ptr [ecx*4 + 0x17ce2f8]
0046a728  dec1                     faddp     st(1)
0046a72a  d90495f4e27c01           fld       dword ptr [edx*4 + 0x17ce2f4]
0046a731  d80c8df4e27c01           fmul      dword ptr [ecx*4 + 0x17ce2f4]
0046a738  dec1                     faddp     st(1)
0046a73a  83e902                   sub       ecx, 2
0046a73d  83ea02                   sub       edx, 2
0046a740  83eb02                   sub       ebx, 2
0046a743  83fb02                   cmp       ebx, 2
0046a746  7dd2                     jge       0x46a71a
0046a748  85db                     test      ebx, ebx
0046a74a  7410                     je        0x46a75c
0046a74c  d90495f8e27c01           fld       dword ptr [edx*4 + 0x17ce2f8]
0046a753  d80c8df8e27c01           fmul      dword ptr [ecx*4 + 0x17ce2f8]
0046a75a  dec1                     faddp     st(1)
0046a75c  8b442428                 mov       eax, dword ptr [esp + 0x28]
0046a760  d90485f8e27c01           fld       dword ptr [eax*4 + 0x17ce2f8]
0046a767  d9ee                     fldz
0046a769  dfe9                     fucompi   st(1)
0046a76b  0f8a60000000             jp        0x46a7d1
0046a771  755e                     jne       0x46a7d1
0046a773  ddd8                     fstp      st(0)
0046a775  8b442460                 mov       eax, dword ptr [esp + 0x60]
0046a779  ddd8                     fstp      st(0)
0046a77b  8b08                     mov       ecx, dword ptr [eax]
0046a77d  8d05d48c5500             lea       eax, [0x558cd4] ; bits=09020000, f32=7.300764999132297e-43
0046a783  894c2470                 mov       dword ptr [esp + 0x70], ecx
0046a787  8d4c2470                 lea       ecx, [esp + 0x70]
0046a78b  894808                   mov       dword ptr [eax + 8], ecx
0046a78e  8b4c2428                 mov       ecx, dword ptr [esp + 0x28]
0046a792  894c246c                 mov       dword ptr [esp + 0x6c], ecx
0046a796  8d4c246c                 lea       ecx, [esp + 0x6c]
0046a79a  894828                   mov       dword ptr [eax + 0x28], ecx
0046a79d  8b4c2440                 mov       ecx, dword ptr [esp + 0x40]
0046a7a1  894c2468                 mov       dword ptr [esp + 0x68], ecx
0046a7a5  8d4c2468                 lea       ecx, [esp + 0x68]
0046a7a9  894834                   mov       dword ptr [eax + 0x34], ecx
0046a7ac  8b4c2444                 mov       ecx, dword ptr [esp + 0x44]
0046a7b0  894c2464                 mov       dword ptr [esp + 0x64], ecx
0046a7b4  8d4c2464                 lea       ecx, [esp + 0x64]
0046a7b8  894840                   mov       dword ptr [eax + 0x40], ecx
0046a7bb  50                       push      eax
0046a7bc  e8ff230500               call      0x4bcbc0 ; _jwe_isfm
0046a7c1  83c404                   add       esp, 4
0046a7c4  68bc8c5500               push      0x558cbc
0046a7c9  e8822c0500               call      0x4bd450 ; _jwe_xstp
0046a7ce  83c404                   add       esp, 4
0046a7d1  d9c9                     fxch      st(1)
0046a7d3  d82cadf8e27c01           fsubr     dword ptr [ebp*4 + 0x17ce2f8]
0046a7da  def1                     fdivrp    st(1)
0046a7dc  d91cadf8e27c01           fstp      dword ptr [ebp*4 + 0x17ce2f8]
0046a7e3  ff442440                 inc       dword ptr [esp + 0x40]
0046a7e7  45                       inc       ebp
0046a7e8  836c243001               sub       dword ptr [esp + 0x30], 1
0046a7ed  0f85cbfeffff             jne       0x46a6be
0046a7f3  8b442438                 mov       eax, dword ptr [esp + 0x38]
0046a7f7  8d4801                   lea       ecx, [eax + 1]
0046a7fa  8b442444                 mov       eax, dword ptr [esp + 0x44]
0046a7fe  8b1485ac837601           mov       edx, dword ptr [eax*4 + 0x17683ac]
0046a805  89c3                     mov       ebx, eax
0046a807  29d3                     sub       ebx, edx
0046a809  01cb                     add       ebx, ecx
0046a80b  894c243c                 mov       dword ptr [esp + 0x3c], ecx
0046a80f  89542438                 mov       dword ptr [esp + 0x38], edx
0046a813  895c2440                 mov       dword ptr [esp + 0x40], ebx
0046a817  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0046a81b  89c5                     mov       ebp, eax
0046a81d  8b4c2438                 mov       ecx, dword ptr [esp + 0x38]
0046a821  29c1                     sub       ecx, eax
0046a823  41                       inc       ecx
0046a824  83f900                   cmp       ecx, 0
0046a827  894c2414                 mov       dword ptr [esp + 0x14], ecx
0046a82b  0f8eb5000000             jle       0x46a8e6
0046a831  8b442440                 mov       eax, dword ptr [esp + 0x40]
0046a835  8b148528007501           mov       edx, dword ptr [eax*4 + 0x1750028]
0046a83c  8d75ff                   lea       esi, [ebp - 1]
0046a83f  8b3c85a8837601           mov       edi, dword ptr [eax*4 + 0x17683a8]
0046a846  47                       inc       edi
0046a847  d9ee                     fldz
0046a849  89d3                     mov       ebx, edx
0046a84b  29fb                     sub       ebx, edi
0046a84d  89f7                     mov       edi, esi
0046a84f  2b7c243c                 sub       edi, dword ptr [esp + 0x3c]
0046a853  89f9                     mov       ecx, edi
0046a855  39d9                     cmp       ecx, ebx
0046a857  89542424                 mov       dword ptr [esp + 0x24], edx
0046a85b  895c2410                 mov       dword ptr [esp + 0x10], ebx
0046a85f  8974241c                 mov       dword ptr [esp + 0x1c], esi
0046a863  7e06                     jle       0x46a86b
0046a865  8b442410                 mov       eax, dword ptr [esp + 0x10]
0046a869  89c1                     mov       ecx, eax
0046a86b  89c8                     mov       eax, ecx
0046a86d  40                       inc       eax
0046a86e  89c3                     mov       ebx, eax
0046a870  83fb00                   cmp       ebx, 0
0046a873  7e53                     jle       0x46a8c8
0046a875  8b442424                 mov       eax, dword ptr [esp + 0x24]
0046a879  89c1                     mov       ecx, eax
0046a87b  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
0046a87f  89c2                     mov       edx, eax
0046a881  83fb02                   cmp       ebx, 2
0046a884  7c2e                     jl        0x46a8b4
0046a886  d90495f8e27c01           fld       dword ptr [edx*4 + 0x17ce2f8]
0046a88d  d80c8df8e27c01           fmul      dword ptr [ecx*4 + 0x17ce2f8]
0046a894  dec1                     faddp     st(1)
0046a896  d90495f4e27c01           fld       dword ptr [edx*4 + 0x17ce2f4]
0046a89d  d80c8df4e27c01           fmul      dword ptr [ecx*4 + 0x17ce2f4]
0046a8a4  dec1                     faddp     st(1)
0046a8a6  83e902                   sub       ecx, 2
0046a8a9  83ea02                   sub       edx, 2
0046a8ac  83eb02                   sub       ebx, 2
0046a8af  83fb02                   cmp       ebx, 2
0046a8b2  7dd2                     jge       0x46a886
0046a8b4  85db                     test      ebx, ebx
0046a8b6  7410                     je        0x46a8c8
0046a8b8  d90495f8e27c01           fld       dword ptr [edx*4 + 0x17ce2f8]
0046a8bf  d80c8df8e27c01           fmul      dword ptr [ecx*4 + 0x17ce2f8]
0046a8c6  dec1                     faddp     st(1)
0046a8c8  d82cadf8e27c01           fsubr     dword ptr [ebp*4 + 0x17ce2f8]
0046a8cf  d91cadf8e27c01           fstp      dword ptr [ebp*4 + 0x17ce2f8]
0046a8d6  ff442440                 inc       dword ptr [esp + 0x40]
0046a8da  45                       inc       ebp
0046a8db  836c241401               sub       dword ptr [esp + 0x14], 1
0046a8e0  0f854bffffff             jne       0x46a831
0046a8e6  ff442444                 inc       dword ptr [esp + 0x44]
0046a8ea  836c244801               sub       dword ptr [esp + 0x48], 1
0046a8ef  0f8587fdffff             jne       0x46a67c
0046a8f5  e9cc000000               jmp       0x46a9c6
0046a8fa  8b0c8d28007501           mov       ecx, dword ptr [ecx*4 + 0x1750028]
0046a901  89c8                     mov       eax, ecx
0046a903  89eb                     mov       ebx, ebp
0046a905  29cb                     sub       ebx, ecx
0046a907  89d9                     mov       ecx, ebx
0046a909  83c108                   add       ecx, 8
0046a90c  89cb                     mov       ebx, ecx
0046a90e  c1fb1f                   sar       ebx, 0x1f
0046a911  83e307                   and       ebx, 7
0046a914  01cb                     add       ebx, ecx
0046a916  c1fb03                   sar       ebx, 3
0046a919  89da                     mov       edx, ebx
0046a91b  83fa00                   cmp       edx, 0
0046a91e  89442450                 mov       dword ptr [esp + 0x50], eax
0046a922  0f8e9e000000             jle       0x46a9c6
0046a928  8b442450                 mov       eax, dword ptr [esp + 0x50]
0046a92c  89c1                     mov       ecx, eax
0046a92e  d9048df4e27c01           fld       dword ptr [ecx*4 + 0x17ce2f4]
0046a935  d83c8df8e27c01           fdivr     dword ptr [ecx*4 + 0x17ce2f8]
0046a93c  d91c8df8e27c01           fstp      dword ptr [ecx*4 + 0x17ce2f8]
0046a943  d9048dece27c01           fld       dword ptr [ecx*4 + 0x17ce2ec]
0046a94a  d80c8dfce27c01           fmul      dword ptr [ecx*4 + 0x17ce2fc]
0046a951  d82c8d00e37c01           fsubr     dword ptr [ecx*4 + 0x17ce300]
0046a958  d9148d00e37c01           fst       dword ptr [ecx*4 + 0x17ce300]
0046a95f  d80c8df8e27c01           fmul      dword ptr [ecx*4 + 0x17ce2f8]
0046a966  d82c8d04e37c01           fsubr     dword ptr [ecx*4 + 0x17ce304]
0046a96d  d91c8d04e37c01           fstp      dword ptr [ecx*4 + 0x17ce304]
0046a974  d9048df4e27c01           fld       dword ptr [ecx*4 + 0x17ce2f4]
0046a97b  d83c8d08e37c01           fdivr     dword ptr [ecx*4 + 0x17ce308]
0046a982  d9148d08e37c01           fst       dword ptr [ecx*4 + 0x17ce308]
0046a989  d80c8d00e37c01           fmul      dword ptr [ecx*4 + 0x17ce300]
0046a990  d82c8d0ce37c01           fsubr     dword ptr [ecx*4 + 0x17ce30c]
0046a997  d8348d04e37c01           fdiv      dword ptr [ecx*4 + 0x17ce304]
0046a99e  d9148d0ce37c01           fst       dword ptr [ecx*4 + 0x17ce30c]
0046a9a5  d80c8d10e37c01           fmul      dword ptr [ecx*4 + 0x17ce310]
0046a9ac  d82c8d14e37c01           fsubr     dword ptr [ecx*4 + 0x17ce314]
0046a9b3  d91c8d14e37c01           fstp      dword ptr [ecx*4 + 0x17ce314]
0046a9ba  83c108                   add       ecx, 8
0046a9bd  83ea01                   sub       edx, 1
0046a9c0  0f8568ffffff             jne       0x46a92e
0046a9c6  ff442458                 inc       dword ptr [esp + 0x58]
0046a9ca  836c245c01               sub       dword ptr [esp + 0x5c], 1
0046a9cf  0f8528fcffff             jne       0x46a5fd
0046a9d5  b800000000               mov       eax, 0
0046a9da  5f                       pop       edi
0046a9db  5e                       pop       esi
0046a9dc  5b                       pop       ebx
0046a9dd  5d                       pop       ebp
0046a9de  83c464                   add       esp, 0x64
0046a9e1  c3                       ret
0046a9e2  8da42400000000           lea       esp, [esp]
0046a9e9  8da42400000000           lea       esp, [esp]
