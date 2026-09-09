; _xlkt20_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x3a7f0
0043a7f0  81ecc0000000             sub       esp, 0xc0
0043a7f6  53                       push      ebx
0043a7f7  56                       push      esi
0043a7f8  57                       push      edi
0043a7f9  8b8424d0000000           mov       eax, dword ptr [esp + 0xd0]
0043a800  8b8c24d4000000           mov       ecx, dword ptr [esp + 0xd4]
0043a807  8b9424d8000000           mov       edx, dword ptr [esp + 0xd8]
0043a80e  8944243c                 mov       dword ptr [esp + 0x3c], eax
0043a812  894c2438                 mov       dword ptr [esp + 0x38], ecx
0043a816  89542434                 mov       dword ptr [esp + 0x34], edx
0043a81a  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043a81e  d900                     fld       dword ptr [eax]
0043a820  8b74243c                 mov       esi, dword ptr [esp + 0x3c]
0043a824  8b16                     mov       edx, dword ptr [esi]
0043a826  8b3c95602e0302           mov       edi, dword ptr [edx*4 + 0x2032e60]
0043a82d  8d4220                   lea       eax, [edx + 0x20]
0043a830  8b0c956c2e0302           mov       ecx, dword ptr [edx*4 + 0x2032e6c]
0043a837  8b3495b42e0302           mov       esi, dword ptr [edx*4 + 0x2032eb4]
0043a83e  897c2430                 mov       dword ptr [esp + 0x30], edi
0043a842  8b3c95682e0302           mov       edi, dword ptr [edx*4 + 0x2032e68]
0043a849  8b1cbd1ccf3b05           mov       ebx, dword ptr [edi*4 + 0x53bcf1c]
0043a850  833cbd7c3a530000         cmp       dword ptr [edi*4 + 0x533a7c], 0
0043a858  8944242c                 mov       dword ptr [esp + 0x2c], eax
0043a85c  89742428                 mov       dword ptr [esp + 0x28], esi
0043a860  7528                     jne       0x43a88a
0043a862  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0043a866  ddd8                     fstp      st(0)
0043a868  8d08                     lea       ecx, [eax]
0043a86a  51                       push      ecx
0043a86b  68803a5300               push      0x533a80
0043a870  68b40e6c01               push      0x16c0eb4
0043a875  e866470000               call      0x43efe0 ; _xstype_
0043a87a  83c40c                   add       esp, 0xc
0043a87d  686c395300               push      0x53396c
0043a882  e8c92b0800               call      0x4bd450 ; _jwe_xstp
0043a887  83c404                   add       esp, 4
0043a88a  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043a891  dff1                     fcompi    st(1)
0043a893  0f8a68010000             jp        0x43aa01
0043a899  0f8762010000             ja        0x43aa01
0043a89f  8b442430                 mov       eax, dword ptr [esp + 0x30]
0043a8a3  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043a8aa  dff1                     fcompi    st(1)
0043a8ac  0f8a31010000             jp        0x43a9e3
0043a8b2  0f832b010000             jae       0x43a9e3
0043a8b8  dbbc24ac000000           fstp      xword ptr [esp + 0xac]
0043a8bf  89d0                     mov       eax, edx
0043a8c1  83c010                   add       eax, 0x10
0043a8c4  898424c8000000           mov       dword ptr [esp + 0xc8], eax
0043a8cb  8d8424c8000000           lea       eax, [esp + 0xc8]
0043a8d2  50                       push      eax
0043a8d3  6a10                     push      0x10
0043a8d5  68603a5300               push      0x533a60
0043a8da  e8515affff               call      0x430330 ; _get_string_from_ft_
0043a8df  83c40c                   add       esp, 0xc
0043a8e2  8d05503a5300             lea       eax, [0x533a50] ; bits=00000000, f32=0.0
0043a8e8  8d35603a5300             lea       esi, [0x533a60] ; bits=00000000, f32=0.0
0043a8ee  50                       push      eax
0043a8ef  8a06                     mov       al, byte ptr [esi]
0043a8f1  5f                       pop       edi
0043a8f2  8807                     mov       byte ptr [edi], al
0043a8f4  8a4601                   mov       al, byte ptr [esi + 1]
0043a8f7  884701                   mov       byte ptr [edi + 1], al
0043a8fa  8a4602                   mov       al, byte ptr [esi + 2]
0043a8fd  884702                   mov       byte ptr [edi + 2], al
0043a900  8a4603                   mov       al, byte ptr [esi + 3]
0043a903  884703                   mov       byte ptr [edi + 3], al
0043a906  8a4604                   mov       al, byte ptr [esi + 4]
0043a909  884704                   mov       byte ptr [edi + 4], al
0043a90c  8a4605                   mov       al, byte ptr [esi + 5]
0043a90f  884705                   mov       byte ptr [edi + 5], al
0043a912  8a4606                   mov       al, byte ptr [esi + 6]
0043a915  884706                   mov       byte ptr [edi + 6], al
0043a918  8a4607                   mov       al, byte ptr [esi + 7]
0043a91b  884707                   mov       byte ptr [edi + 7], al
0043a91e  8a4608                   mov       al, byte ptr [esi + 8]
0043a921  884708                   mov       byte ptr [edi + 8], al
0043a924  8a4609                   mov       al, byte ptr [esi + 9]
0043a927  884709                   mov       byte ptr [edi + 9], al
0043a92a  8a460a                   mov       al, byte ptr [esi + 0xa]
0043a92d  88470a                   mov       byte ptr [edi + 0xa], al
0043a930  8a460b                   mov       al, byte ptr [esi + 0xb]
0043a933  88470b                   mov       byte ptr [edi + 0xb], al
0043a936  8a460c                   mov       al, byte ptr [esi + 0xc]
0043a939  88470c                   mov       byte ptr [edi + 0xc], al
0043a93c  8a460d                   mov       al, byte ptr [esi + 0xd]
0043a93f  88470d                   mov       byte ptr [edi + 0xd], al
0043a942  8a460e                   mov       al, byte ptr [esi + 0xe]
0043a945  88470e                   mov       byte ptr [edi + 0xe], al
0043a948  8a460f                   mov       al, byte ptr [esi + 0xf]
0043a94b  88470f                   mov       byte ptr [edi + 0xf], al
0043a94e  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0043a952  8b30                     mov       esi, dword ptr [eax]
0043a954  8b34b5702e0302           mov       esi, dword ptr [esi*4 + 0x2032e70]
0043a95b  8b3da00e6c01             mov       edi, dword ptr [0x16c0ea0] ; _xscom_
0043a961  8b05a40e6c01             mov       eax, dword ptr [0x16c0ea4]
0043a967  89742420                 mov       dword ptr [esp + 0x20], esi
0043a96b  8d35c8395300             lea       esi, [0x5339c8] ; bits=09020000, f32=7.300764999132297e-43
0043a971  897c241c                 mov       dword ptr [esp + 0x1c], edi
0043a975  8b7c2420                 mov       edi, dword ptr [esp + 0x20]
0043a979  89bc24c4000000           mov       dword ptr [esp + 0xc4], edi
0043a980  8dbc24c4000000           lea       edi, [esp + 0xc4]
0043a987  897e34                   mov       dword ptr [esi + 0x34], edi
0043a98a  8b7c241c                 mov       edi, dword ptr [esp + 0x1c]
0043a98e  89bc24bc000000           mov       dword ptr [esp + 0xbc], edi
0043a995  898424c0000000           mov       dword ptr [esp + 0xc0], eax
0043a99c  8d8424bc000000           lea       eax, [esp + 0xbc]
0043a9a3  894640                   mov       dword ptr [esi + 0x40], eax
0043a9a6  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043a9ad  d99c24b8000000           fstp      dword ptr [esp + 0xb8]
0043a9b4  8d8424b8000000           lea       eax, [esp + 0xb8]
0043a9bb  89464c                   mov       dword ptr [esi + 0x4c], eax
0043a9be  56                       push      esi
0043a9bf  e8fc210800               call      0x4bcbc0 ; _jwe_isfm
0043a9c4  83c404                   add       esp, 4
0043a9c7  8b442430                 mov       eax, dword ptr [esp + 0x30]
0043a9cb  89c6                     mov       esi, eax
0043a9cd  29de                     sub       esi, ebx
0043a9cf  89f1                     mov       ecx, esi
0043a9d1  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043a9d8  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043a9dc  d910                     fst       dword ptr [eax]
0043a9de  e971010000               jmp       0x43ab54
0043a9e3  8d140b                   lea       edx, [ebx + ecx]
0043a9e6  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
0043a9ed  dff1                     fcompi    st(1)
0043a9ef  0f8a5f010000             jp        0x43ab54
0043a9f5  0f8359010000             jae       0x43ab54
0043a9fb  01d9                     add       ecx, ebx
0043a9fd  01da                     add       edx, ebx
0043a9ff  ebe5                     jmp       0x43a9e6
0043aa01  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0043aa05  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043aa0c  dff1                     fcompi    st(1)
0043aa0e  0f8a2d010000             jp        0x43ab41
0043aa14  0f8627010000             jbe       0x43ab41
0043aa1a  dbbc24ac000000           fstp      xword ptr [esp + 0xac]
0043aa21  89d0                     mov       eax, edx
0043aa23  83c010                   add       eax, 0x10
0043aa26  898424c8000000           mov       dword ptr [esp + 0xc8], eax
0043aa2d  8d8424c8000000           lea       eax, [esp + 0xc8]
0043aa34  50                       push      eax
0043aa35  6a10                     push      0x10
0043aa37  68703a5300               push      0x533a70
0043aa3c  e8ef58ffff               call      0x430330 ; _get_string_from_ft_
0043aa41  83c40c                   add       esp, 0xc
0043aa44  8d05503a5300             lea       eax, [0x533a50] ; bits=00000000, f32=0.0
0043aa4a  8d35703a5300             lea       esi, [0x533a70] ; bits=00000000, f32=0.0
0043aa50  50                       push      eax
0043aa51  8a06                     mov       al, byte ptr [esi]
0043aa53  5f                       pop       edi
0043aa54  8807                     mov       byte ptr [edi], al
0043aa56  8a4601                   mov       al, byte ptr [esi + 1]
0043aa59  884701                   mov       byte ptr [edi + 1], al
0043aa5c  8a4602                   mov       al, byte ptr [esi + 2]
0043aa5f  884702                   mov       byte ptr [edi + 2], al
0043aa62  8a4603                   mov       al, byte ptr [esi + 3]
0043aa65  884703                   mov       byte ptr [edi + 3], al
0043aa68  8a4604                   mov       al, byte ptr [esi + 4]
0043aa6b  884704                   mov       byte ptr [edi + 4], al
0043aa6e  8a4605                   mov       al, byte ptr [esi + 5]
0043aa71  884705                   mov       byte ptr [edi + 5], al
0043aa74  8a4606                   mov       al, byte ptr [esi + 6]
0043aa77  884706                   mov       byte ptr [edi + 6], al
0043aa7a  8a4607                   mov       al, byte ptr [esi + 7]
0043aa7d  884707                   mov       byte ptr [edi + 7], al
0043aa80  8a4608                   mov       al, byte ptr [esi + 8]
0043aa83  884708                   mov       byte ptr [edi + 8], al
0043aa86  8a4609                   mov       al, byte ptr [esi + 9]
0043aa89  884709                   mov       byte ptr [edi + 9], al
0043aa8c  8a460a                   mov       al, byte ptr [esi + 0xa]
0043aa8f  88470a                   mov       byte ptr [edi + 0xa], al
0043aa92  8a460b                   mov       al, byte ptr [esi + 0xb]
0043aa95  88470b                   mov       byte ptr [edi + 0xb], al
0043aa98  8a460c                   mov       al, byte ptr [esi + 0xc]
0043aa9b  88470c                   mov       byte ptr [edi + 0xc], al
0043aa9e  8a460d                   mov       al, byte ptr [esi + 0xd]
0043aaa1  88470d                   mov       byte ptr [edi + 0xd], al
0043aaa4  8a460e                   mov       al, byte ptr [esi + 0xe]
0043aaa7  88470e                   mov       byte ptr [edi + 0xe], al
0043aaaa  8a460f                   mov       al, byte ptr [esi + 0xf]
0043aaad  88470f                   mov       byte ptr [edi + 0xf], al
0043aab0  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0043aab4  8b30                     mov       esi, dword ptr [eax]
0043aab6  8b34b5702e0302           mov       esi, dword ptr [esi*4 + 0x2032e70]
0043aabd  8b3da00e6c01             mov       edi, dword ptr [0x16c0ea0] ; _xscom_
0043aac3  8b05a40e6c01             mov       eax, dword ptr [0x16c0ea4]
0043aac9  89742410                 mov       dword ptr [esp + 0x10], esi
0043aacd  8d3578395300             lea       esi, [0x533978] ; bits=09020000, f32=7.300764999132297e-43
0043aad3  897c240c                 mov       dword ptr [esp + 0xc], edi
0043aad7  8b7c2410                 mov       edi, dword ptr [esp + 0x10]
0043aadb  89bc24c4000000           mov       dword ptr [esp + 0xc4], edi
0043aae2  8dbc24c4000000           lea       edi, [esp + 0xc4]
0043aae9  897e34                   mov       dword ptr [esi + 0x34], edi
0043aaec  8b7c240c                 mov       edi, dword ptr [esp + 0xc]
0043aaf0  89bc24bc000000           mov       dword ptr [esp + 0xbc], edi
0043aaf7  898424c0000000           mov       dword ptr [esp + 0xc0], eax
0043aafe  8d8424bc000000           lea       eax, [esp + 0xbc]
0043ab05  894640                   mov       dword ptr [esi + 0x40], eax
0043ab08  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043ab0f  d99c24b8000000           fstp      dword ptr [esp + 0xb8]
0043ab16  8d8424b8000000           lea       eax, [esp + 0xb8]
0043ab1d  89464c                   mov       dword ptr [esi + 0x4c], eax
0043ab20  56                       push      esi
0043ab21  e89a200800               call      0x4bcbc0 ; _jwe_isfm
0043ab26  83c404                   add       esp, 4
0043ab29  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0043ab2d  89c1                     mov       ecx, eax
0043ab2f  8d3403                   lea       esi, [ebx + eax]
0043ab32  d904b5602e0302           fld       dword ptr [esi*4 + 0x2032e60]
0043ab39  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043ab3d  d910                     fst       dword ptr [eax]
0043ab3f  eb13                     jmp       0x43ab54
0043ab41  29d9                     sub       ecx, ebx
0043ab43  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043ab4a  dff1                     fcompi    st(1)
0043ab4c  0f8a02000000             jp        0x43ab54
0043ab52  77ed                     ja        0x43ab41
0043ab54  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0043ab58  8b30                     mov       esi, dword ptr [eax]
0043ab5a  890cb56c2e0302           mov       dword ptr [esi*4 + 0x2032e6c], ecx
0043ab61  d9048d642e0302           fld       dword ptr [ecx*4 + 0x2032e64]
0043ab68  dbbc24a0000000           fstp      xword ptr [esp + 0xa0]
0043ab6f  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
0043ab76  d9048d702e0302           fld       dword ptr [ecx*4 + 0x2032e70]
0043ab7d  dbbc2488000000           fstp      xword ptr [esp + 0x88]
0043ab84  89d8                     mov       eax, ebx
0043ab86  01c8                     add       eax, ecx
0043ab88  89c2                     mov       edx, eax
0043ab8a  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
0043ab91  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
0043ab98  dbbc2494000000           fstp      xword ptr [esp + 0x94]
0043ab9f  d9c9                     fxch      st(1)
0043aba1  d8248d602e0302           fsub      dword ptr [ecx*4 + 0x2032e60]
0043aba8  8d05f0385300             lea       eax, [0x5338f0] ; bits=fa000000, f32=3.5032461608120427e-43
0043abae  d9c0                     fld       st(0)
0043abb0  d84888                   fmul      dword ptr [eax - 0x78]
0043abb3  d9e8                     fld1
0043abb5  dbac2494000000           fld       xword ptr [esp + 0x94]
0043abbc  d83d7c385300             fdivr     dword ptr [0x53387c] ; bits=0000803f, f32=1.0
0043abc2  d90495642e0302           fld       dword ptr [edx*4 + 0x2032e64]
0043abc9  d8248d642e0302           fsub      dword ptr [ecx*4 + 0x2032e64]
0043abd0  d8c9                     fmul      st(1)
0043abd2  8bb424e0000000           mov       esi, dword ptr [esp + 0xe0]
0043abd9  d916                     fst       dword ptr [esi]
0043abdb  d8cc                     fmul      st(4)
0043abdd  dbac24a0000000           fld       xword ptr [esp + 0xa0]
0043abe4  dec1                     faddp     st(1)
0043abe6  8bb424dc000000           mov       esi, dword ptr [esp + 0xdc]
0043abed  d916                     fst       dword ptr [esi]
0043abef  dbac24a0000000           fld       xword ptr [esp + 0xa0]
0043abf6  dec1                     faddp     st(1)
0043abf8  decb                     fmulp     st(3)
0043abfa  d9ca                     fxch      st(2)
0043abfc  8b742434                 mov       esi, dword ptr [esp + 0x34]
0043ac00  d8048d682e0302           fadd      dword ptr [ecx*4 + 0x2032e68]
0043ac07  d91e                     fstp      dword ptr [esi]
0043ac09  dbac2494000000           fld       xword ptr [esp + 0x94]
0043ac10  dbac2488000000           fld       xword ptr [esp + 0x88]
0043ac17  d9cd                     fxch      st(5)
0043ac19  d9cb                     fxch      st(3)
0043ac1b  d9cc                     fxch      st(4)
0043ac1d  d9cb                     fxch      st(3)
0043ac1f  d9ca                     fxch      st(2)
0043ac21  d9c9                     fxch      st(1)
0043ac23  8b742428                 mov       esi, dword ptr [esp + 0x28]
0043ac27  85f6                     test      esi, esi
0043ac29  89442418                 mov       dword ptr [esp + 0x18], eax
0043ac2d  754f                     jne       0x43ac7e
0043ac2f  ddd8                     fstp      st(0)
0043ac31  ddd8                     fstp      st(0)
0043ac33  d9c3                     fld       st(3)
0043ac35  d82c95702e0302           fsubr     dword ptr [edx*4 + 0x2032e70]
0043ac3c  d8cb                     fmul      st(3)
0043ac3e  8b8424f0000000           mov       eax, dword ptr [esp + 0xf0]
0043ac45  d910                     fst       dword ptr [eax]
0043ac47  d8ca                     fmul      st(2)
0043ac49  dec4                     faddp     st(4)
0043ac4b  8b8424ec000000           mov       eax, dword ptr [esp + 0xec]
0043ac52  d9cb                     fxch      st(3)
0043ac54  d918                     fstp      dword ptr [eax]
0043ac56  d9c2                     fld       st(2)
0043ac58  d82c956c2e0302           fsubr     dword ptr [edx*4 + 0x2032e6c]
0043ac5f  deca                     fmulp     st(2)
0043ac61  8b8424e8000000           mov       eax, dword ptr [esp + 0xe8]
0043ac68  d9c9                     fxch      st(1)
0043ac6a  d910                     fst       dword ptr [eax]
0043ac6c  dec9                     fmulp     st(1)
0043ac6e  dec1                     faddp     st(1)
0043ac70  8b8424e4000000           mov       eax, dword ptr [esp + 0xe4]
0043ac77  d918                     fstp      dword ptr [eax]
0043ac79  e971010000               jmp       0x43adef
0043ac7e  d9ca                     fxch      st(2)
0043ac80  db7c2464                 fstp      xword ptr [esp + 0x64]
0043ac84  d9cc                     fxch      st(4)
0043ac86  db7c244c                 fstp      xword ptr [esp + 0x4c]
0043ac8a  d9c9                     fxch      st(1)
0043ac8c  d8ca                     fmul      st(2)
0043ac8e  d9c3                     fld       st(3)
0043ac90  d8e1                     fsub      st(1)
0043ac92  d9c0                     fld       st(0)
0043ac94  d8ca                     fmul      st(2)
0043ac96  decb                     fmulp     st(3)
0043ac98  d9c1                     fld       st(1)
0043ac9a  d8cb                     fmul      st(3)
0043ac9c  d9e0                     fchs
0043ac9e  db7c247c                 fstp      xword ptr [esp + 0x7c]
0043aca2  dcca                     fmul      st(2), st(0)
0043aca4  d9ca                     fxch      st(2)
0043aca6  dbbc24a0000000           fstp      xword ptr [esp + 0xa0]
0043acad  d9c0                     fld       st(0)
0043acaf  d8c0                     fadd      st(0)
0043acb1  d8c4                     fadd      st(4)
0043acb3  8b442418                 mov       eax, dword ptr [esp + 0x18]
0043acb7  d9c0                     fld       st(0)
0043acb9  d86894                   fsubr     dword ptr [eax - 0x6c]
0043acbc  d8ca                     fmul      st(2)
0043acbe  d8ca                     fmul      st(2)
0043acc0  dbbc2488000000           fstp      xword ptr [esp + 0x88]
0043acc7  d9c2                     fld       st(2)
0043acc9  d8c8                     fmul      st(0)
0043accb  dec9                     fmulp     st(1)
0043accd  db7c2440                 fstp      xword ptr [esp + 0x40]
0043acd1  d9c0                     fld       st(0)
0043acd3  d84898                   fmul      dword ptr [eax - 0x68]
0043acd6  d8ec                     fsubr     st(4)
0043acd8  dcc4                     fadd      st(4), st(0)
0043acda  d9cc                     fxch      st(4)
0043acdc  d8c9                     fmul      st(1)
0043acde  d9e0                     fchs
0043ace0  db7c2470                 fstp      xword ptr [esp + 0x70]
0043ace4  d9cb                     fxch      st(3)
0043ace6  d8c9                     fmul      st(1)
0043ace8  dbbc2494000000           fstp      xword ptr [esp + 0x94]
0043acef  d8489c                   fmul      dword ptr [eax - 0x64]
0043acf2  deca                     fmulp     st(2)
0043acf4  dec9                     fmulp     st(1)
0043acf6  8b442428                 mov       eax, dword ptr [esp + 0x28]
0043acfa  db7c2458                 fstp      xword ptr [esp + 0x58]
0043acfe  8d1c08                   lea       ebx, [eax + ecx]
0043ad01  01d0                     add       eax, edx
0043ad03  d9049d602e0302           fld       dword ptr [ebx*4 + 0x2032e60]
0043ad0a  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043ad11  d9049d642e0302           fld       dword ptr [ebx*4 + 0x2032e64]
0043ad18  d90485642e0302           fld       dword ptr [eax*4 + 0x2032e64]
0043ad1f  dbac24a0000000           fld       xword ptr [esp + 0xa0]
0043ad26  d80c9d642e0302           fmul      dword ptr [ebx*4 + 0x2032e64]
0043ad2d  db6c247c                 fld       xword ptr [esp + 0x7c]
0043ad31  d80c85642e0302           fmul      dword ptr [eax*4 + 0x2032e64]
0043ad38  dec1                     faddp     st(1)
0043ad3a  db6c2440                 fld       xword ptr [esp + 0x40]
0043ad3e  db6c244c                 fld       xword ptr [esp + 0x4c]
0043ad42  dec9                     fmulp     st(1)
0043ad44  dec1                     faddp     st(1)
0043ad46  dbac2488000000           fld       xword ptr [esp + 0x88]
0043ad4d  d80c95702e0302           fmul      dword ptr [edx*4 + 0x2032e70]
0043ad54  dec1                     faddp     st(1)
0043ad56  8b8424ec000000           mov       eax, dword ptr [esp + 0xec]
0043ad5d  d918                     fstp      dword ptr [eax]
0043ad5f  dbac2494000000           fld       xword ptr [esp + 0x94]
0043ad66  deca                     fmulp     st(2)
0043ad68  db6c2470                 fld       xword ptr [esp + 0x70]
0043ad6c  dec9                     fmulp     st(1)
0043ad6e  dec1                     faddp     st(1)
0043ad70  db6c244c                 fld       xword ptr [esp + 0x4c]
0043ad74  d82c95702e0302           fsubr     dword ptr [edx*4 + 0x2032e70]
0043ad7b  db6c2458                 fld       xword ptr [esp + 0x58]
0043ad7f  dec9                     fmulp     st(1)
0043ad81  dec1                     faddp     st(1)
0043ad83  8b8424f0000000           mov       eax, dword ptr [esp + 0xf0]
0043ad8a  d918                     fstp      dword ptr [eax]
0043ad8c  dbac24a0000000           fld       xword ptr [esp + 0xa0]
0043ad93  d8ca                     fmul      st(2)
0043ad95  db6c247c                 fld       xword ptr [esp + 0x7c]
0043ad99  d8ca                     fmul      st(2)
0043ad9b  dec1                     faddp     st(1)
0043ad9d  db6c2464                 fld       xword ptr [esp + 0x64]
0043ada1  db6c2440                 fld       xword ptr [esp + 0x40]
0043ada5  dec9                     fmulp     st(1)
0043ada7  dec1                     faddp     st(1)
0043ada9  dbac2488000000           fld       xword ptr [esp + 0x88]
0043adb0  d80c956c2e0302           fmul      dword ptr [edx*4 + 0x2032e6c]
0043adb7  dec1                     faddp     st(1)
0043adb9  8b8424e4000000           mov       eax, dword ptr [esp + 0xe4]
0043adc0  d918                     fstp      dword ptr [eax]
0043adc2  dbac2494000000           fld       xword ptr [esp + 0x94]
0043adc9  deca                     fmulp     st(2)
0043adcb  db6c2470                 fld       xword ptr [esp + 0x70]
0043adcf  dec9                     fmulp     st(1)
0043add1  dec1                     faddp     st(1)
0043add3  db6c2464                 fld       xword ptr [esp + 0x64]
0043add7  d82c956c2e0302           fsubr     dword ptr [edx*4 + 0x2032e6c]
0043adde  db6c2458                 fld       xword ptr [esp + 0x58]
0043ade2  dec9                     fmulp     st(1)
0043ade4  dec1                     faddp     st(1)
0043ade6  8b8424e8000000           mov       eax, dword ptr [esp + 0xe8]
0043aded  d918                     fstp      dword ptr [eax]
0043adef  8b8424e4000000           mov       eax, dword ptr [esp + 0xe4]
0043adf6  d900                     fld       dword ptr [eax]
0043adf8  d9c0                     fld       st(0)
0043adfa  d800                     fadd      dword ptr [eax]
0043adfc  8b8c24e8000000           mov       ecx, dword ptr [esp + 0xe8]
0043ae03  d809                     fmul      dword ptr [ecx]
0043ae05  d919                     fstp      dword ptr [ecx]
0043ae07  d8c8                     fmul      st(0)
0043ae09  d918                     fstp      dword ptr [eax]
0043ae0b  b800000000               mov       eax, 0
0043ae10  5f                       pop       edi
0043ae11  5e                       pop       esi
0043ae12  5b                       pop       ebx
0043ae13  81c4c0000000             add       esp, 0xc0
0043ae19  c3                       ret
0043ae1a  8d9b00000000             lea       ebx, [ebx]
