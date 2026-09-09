; _xlkt22_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x3b520
0043b520  81ec98010000             sub       esp, 0x198
0043b526  53                       push      ebx
0043b527  56                       push      esi
0043b528  57                       push      edi
0043b529  8b8424a8010000           mov       eax, dword ptr [esp + 0x1a8]
0043b530  8b8c24ac010000           mov       ecx, dword ptr [esp + 0x1ac]
0043b537  8b9424b0010000           mov       edx, dword ptr [esp + 0x1b0]
0043b53e  8944243c                 mov       dword ptr [esp + 0x3c], eax
0043b542  894c2438                 mov       dword ptr [esp + 0x38], ecx
0043b546  89542434                 mov       dword ptr [esp + 0x34], edx
0043b54a  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043b54e  d900                     fld       dword ptr [eax]
0043b550  8b74243c                 mov       esi, dword ptr [esp + 0x3c]
0043b554  dbbc2484010000           fstp      xword ptr [esp + 0x184]
0043b55b  8b16                     mov       edx, dword ptr [esi]
0043b55d  8b3c95602e0302           mov       edi, dword ptr [edx*4 + 0x2032e60]
0043b564  8d4220                   lea       eax, [edx + 0x20]
0043b567  8b0c956c2e0302           mov       ecx, dword ptr [edx*4 + 0x2032e6c]
0043b56e  8b3495b42e0302           mov       esi, dword ptr [edx*4 + 0x2032eb4]
0043b575  897c2430                 mov       dword ptr [esp + 0x30], edi
0043b579  8b3c95682e0302           mov       edi, dword ptr [edx*4 + 0x2032e68]
0043b580  8b1cbd1ccf3b05           mov       ebx, dword ptr [edi*4 + 0x53bcf1c]
0043b587  833cbd1c42530000         cmp       dword ptr [edi*4 + 0x53421c], 0
0043b58f  8944242c                 mov       dword ptr [esp + 0x2c], eax
0043b593  89742428                 mov       dword ptr [esp + 0x28], esi
0043b597  897c2424                 mov       dword ptr [esp + 0x24], edi
0043b59b  7526                     jne       0x43b5c3
0043b59d  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0043b5a1  8d08                     lea       ecx, [eax]
0043b5a3  51                       push      ecx
0043b5a4  6820425300               push      0x534220
0043b5a9  68b40e6c01               push      0x16c0eb4
0043b5ae  e82d3a0000               call      0x43efe0 ; _xstype_
0043b5b3  83c40c                   add       esp, 0xc
0043b5b6  682c415300               push      0x53412c
0043b5bb  e8901e0800               call      0x4bd450 ; _jwe_xstp
0043b5c0  83c404                   add       esp, 4
0043b5c3  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043b5ca  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b5d1  dff1                     fcompi    st(1)
0043b5d3  ddd8                     fstp      st(0)
0043b5d5  0f8a7f010000             jp        0x43b75a
0043b5db  0f8279010000             jb        0x43b75a
0043b5e1  8b442430                 mov       eax, dword ptr [esp + 0x30]
0043b5e5  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043b5ec  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b5f3  dff1                     fcompi    st(1)
0043b5f5  ddd8                     fstp      st(0)
0043b5f7  0f8a38010000             jp        0x43b735
0043b5fd  0f8632010000             jbe       0x43b735
0043b603  89d0                     mov       eax, edx
0043b605  83c010                   add       eax, 0x10
0043b608  898424a0010000           mov       dword ptr [esp + 0x1a0], eax
0043b60f  8d8424a0010000           lea       eax, [esp + 0x1a0]
0043b616  50                       push      eax
0043b617  6a10                     push      0x10
0043b619  6800425300               push      0x534200
0043b61e  e80d4dffff               call      0x430330 ; _get_string_from_ft_
0043b623  83c40c                   add       esp, 0xc
0043b626  8d05f0415300             lea       eax, [0x5341f0] ; bits=00000000, f32=0.0
0043b62c  8d3500425300             lea       esi, [0x534200] ; bits=00000000, f32=0.0
0043b632  50                       push      eax
0043b633  8a06                     mov       al, byte ptr [esi]
0043b635  5f                       pop       edi
0043b636  8807                     mov       byte ptr [edi], al
0043b638  8a4601                   mov       al, byte ptr [esi + 1]
0043b63b  884701                   mov       byte ptr [edi + 1], al
0043b63e  8a4602                   mov       al, byte ptr [esi + 2]
0043b641  884702                   mov       byte ptr [edi + 2], al
0043b644  8a4603                   mov       al, byte ptr [esi + 3]
0043b647  884703                   mov       byte ptr [edi + 3], al
0043b64a  8a4604                   mov       al, byte ptr [esi + 4]
0043b64d  884704                   mov       byte ptr [edi + 4], al
0043b650  8a4605                   mov       al, byte ptr [esi + 5]
0043b653  884705                   mov       byte ptr [edi + 5], al
0043b656  8a4606                   mov       al, byte ptr [esi + 6]
0043b659  884706                   mov       byte ptr [edi + 6], al
0043b65c  8a4607                   mov       al, byte ptr [esi + 7]
0043b65f  884707                   mov       byte ptr [edi + 7], al
0043b662  8a4608                   mov       al, byte ptr [esi + 8]
0043b665  884708                   mov       byte ptr [edi + 8], al
0043b668  8a4609                   mov       al, byte ptr [esi + 9]
0043b66b  884709                   mov       byte ptr [edi + 9], al
0043b66e  8a460a                   mov       al, byte ptr [esi + 0xa]
0043b671  88470a                   mov       byte ptr [edi + 0xa], al
0043b674  8a460b                   mov       al, byte ptr [esi + 0xb]
0043b677  88470b                   mov       byte ptr [edi + 0xb], al
0043b67a  8a460c                   mov       al, byte ptr [esi + 0xc]
0043b67d  88470c                   mov       byte ptr [edi + 0xc], al
0043b680  8a460d                   mov       al, byte ptr [esi + 0xd]
0043b683  88470d                   mov       byte ptr [edi + 0xd], al
0043b686  8a460e                   mov       al, byte ptr [esi + 0xe]
0043b689  88470e                   mov       byte ptr [edi + 0xe], al
0043b68c  8a460f                   mov       al, byte ptr [esi + 0xf]
0043b68f  88470f                   mov       byte ptr [edi + 0xf], al
0043b692  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0043b696  8b30                     mov       esi, dword ptr [eax]
0043b698  8b34b5702e0302           mov       esi, dword ptr [esi*4 + 0x2032e70]
0043b69f  8b3da00e6c01             mov       edi, dword ptr [0x16c0ea0] ; _xscom_
0043b6a5  8b05a40e6c01             mov       eax, dword ptr [0x16c0ea4]
0043b6ab  8974241c                 mov       dword ptr [esp + 0x1c], esi
0043b6af  8d3588415300             lea       esi, [0x534188] ; bits=09020000, f32=7.300764999132297e-43
0043b6b5  897c2418                 mov       dword ptr [esp + 0x18], edi
0043b6b9  8b7c241c                 mov       edi, dword ptr [esp + 0x1c]
0043b6bd  89bc249c010000           mov       dword ptr [esp + 0x19c], edi
0043b6c4  8dbc249c010000           lea       edi, [esp + 0x19c]
0043b6cb  897e34                   mov       dword ptr [esi + 0x34], edi
0043b6ce  8b7c2418                 mov       edi, dword ptr [esp + 0x18]
0043b6d2  89bc2494010000           mov       dword ptr [esp + 0x194], edi
0043b6d9  89842498010000           mov       dword ptr [esp + 0x198], eax
0043b6e0  8d842494010000           lea       eax, [esp + 0x194]
0043b6e7  894640                   mov       dword ptr [esi + 0x40], eax
0043b6ea  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b6f1  d99c2490010000           fstp      dword ptr [esp + 0x190]
0043b6f8  8d842490010000           lea       eax, [esp + 0x190]
0043b6ff  89464c                   mov       dword ptr [esi + 0x4c], eax
0043b702  56                       push      esi
0043b703  e8b8140800               call      0x4bcbc0 ; _jwe_isfm
0043b708  83c404                   add       esp, 4
0043b70b  8b442430                 mov       eax, dword ptr [esp + 0x30]
0043b70f  89c6                     mov       esi, eax
0043b711  29de                     sub       esi, ebx
0043b713  89f1                     mov       ecx, esi
0043b715  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043b71c  dbbc2484010000           fstp      xword ptr [esp + 0x184]
0043b723  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043b727  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b72e  d918                     fstp      dword ptr [eax]
0043b730  e99f010000               jmp       0x43b8d4
0043b735  8d140b                   lea       edx, [ebx + ecx]
0043b738  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b73f  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
0043b746  dff1                     fcompi    st(1)
0043b748  0f8a7f010000             jp        0x43b8cd
0043b74e  0f8379010000             jae       0x43b8cd
0043b754  01d9                     add       ecx, ebx
0043b756  01da                     add       edx, ebx
0043b758  ebe5                     jmp       0x43b73f
0043b75a  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0043b75e  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043b765  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b76c  dff1                     fcompi    st(1)
0043b76e  ddd8                     fstp      st(0)
0043b770  0f8a34010000             jp        0x43b8aa
0043b776  0f832e010000             jae       0x43b8aa
0043b77c  89d0                     mov       eax, edx
0043b77e  83c010                   add       eax, 0x10
0043b781  898424a0010000           mov       dword ptr [esp + 0x1a0], eax
0043b788  8d8424a0010000           lea       eax, [esp + 0x1a0]
0043b78f  50                       push      eax
0043b790  6a10                     push      0x10
0043b792  6810425300               push      0x534210
0043b797  e8944bffff               call      0x430330 ; _get_string_from_ft_
0043b79c  83c40c                   add       esp, 0xc
0043b79f  8d05f0415300             lea       eax, [0x5341f0] ; bits=00000000, f32=0.0
0043b7a5  8d3510425300             lea       esi, [0x534210] ; bits=00000000, f32=0.0
0043b7ab  50                       push      eax
0043b7ac  8a06                     mov       al, byte ptr [esi]
0043b7ae  5f                       pop       edi
0043b7af  8807                     mov       byte ptr [edi], al
0043b7b1  8a4601                   mov       al, byte ptr [esi + 1]
0043b7b4  884701                   mov       byte ptr [edi + 1], al
0043b7b7  8a4602                   mov       al, byte ptr [esi + 2]
0043b7ba  884702                   mov       byte ptr [edi + 2], al
0043b7bd  8a4603                   mov       al, byte ptr [esi + 3]
0043b7c0  884703                   mov       byte ptr [edi + 3], al
0043b7c3  8a4604                   mov       al, byte ptr [esi + 4]
0043b7c6  884704                   mov       byte ptr [edi + 4], al
0043b7c9  8a4605                   mov       al, byte ptr [esi + 5]
0043b7cc  884705                   mov       byte ptr [edi + 5], al
0043b7cf  8a4606                   mov       al, byte ptr [esi + 6]
0043b7d2  884706                   mov       byte ptr [edi + 6], al
0043b7d5  8a4607                   mov       al, byte ptr [esi + 7]
0043b7d8  884707                   mov       byte ptr [edi + 7], al
0043b7db  8a4608                   mov       al, byte ptr [esi + 8]
0043b7de  884708                   mov       byte ptr [edi + 8], al
0043b7e1  8a4609                   mov       al, byte ptr [esi + 9]
0043b7e4  884709                   mov       byte ptr [edi + 9], al
0043b7e7  8a460a                   mov       al, byte ptr [esi + 0xa]
0043b7ea  88470a                   mov       byte ptr [edi + 0xa], al
0043b7ed  8a460b                   mov       al, byte ptr [esi + 0xb]
0043b7f0  88470b                   mov       byte ptr [edi + 0xb], al
0043b7f3  8a460c                   mov       al, byte ptr [esi + 0xc]
0043b7f6  88470c                   mov       byte ptr [edi + 0xc], al
0043b7f9  8a460d                   mov       al, byte ptr [esi + 0xd]
0043b7fc  88470d                   mov       byte ptr [edi + 0xd], al
0043b7ff  8a460e                   mov       al, byte ptr [esi + 0xe]
0043b802  88470e                   mov       byte ptr [edi + 0xe], al
0043b805  8a460f                   mov       al, byte ptr [esi + 0xf]
0043b808  88470f                   mov       byte ptr [edi + 0xf], al
0043b80b  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0043b80f  8b30                     mov       esi, dword ptr [eax]
0043b811  8b34b5702e0302           mov       esi, dword ptr [esi*4 + 0x2032e70]
0043b818  8b3da00e6c01             mov       edi, dword ptr [0x16c0ea0] ; _xscom_
0043b81e  8b05a40e6c01             mov       eax, dword ptr [0x16c0ea4]
0043b824  89742410                 mov       dword ptr [esp + 0x10], esi
0043b828  8d3538415300             lea       esi, [0x534138] ; bits=09020000, f32=7.300764999132297e-43
0043b82e  897c240c                 mov       dword ptr [esp + 0xc], edi
0043b832  8b7c2410                 mov       edi, dword ptr [esp + 0x10]
0043b836  89bc249c010000           mov       dword ptr [esp + 0x19c], edi
0043b83d  8dbc249c010000           lea       edi, [esp + 0x19c]
0043b844  897e34                   mov       dword ptr [esi + 0x34], edi
0043b847  8b7c240c                 mov       edi, dword ptr [esp + 0xc]
0043b84b  89bc2494010000           mov       dword ptr [esp + 0x194], edi
0043b852  89842498010000           mov       dword ptr [esp + 0x198], eax
0043b859  8d842494010000           lea       eax, [esp + 0x194]
0043b860  894640                   mov       dword ptr [esi + 0x40], eax
0043b863  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b86a  d99c2490010000           fstp      dword ptr [esp + 0x190]
0043b871  8d842490010000           lea       eax, [esp + 0x190]
0043b878  89464c                   mov       dword ptr [esi + 0x4c], eax
0043b87b  56                       push      esi
0043b87c  e83f130800               call      0x4bcbc0 ; _jwe_isfm
0043b881  83c404                   add       esp, 4
0043b884  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0043b888  89c1                     mov       ecx, eax
0043b88a  8d3403                   lea       esi, [ebx + eax]
0043b88d  d904b5602e0302           fld       dword ptr [esi*4 + 0x2032e60]
0043b894  dbbc2484010000           fstp      xword ptr [esp + 0x184]
0043b89b  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043b89f  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b8a6  d918                     fstp      dword ptr [eax]
0043b8a8  eb2a                     jmp       0x43b8d4
0043b8aa  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b8b1  29d9                     sub       ecx, ebx
0043b8b3  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043b8ba  dff1                     fcompi    st(1)
0043b8bc  0f8a02000000             jp        0x43b8c4
0043b8c2  77ed                     ja        0x43b8b1
0043b8c4  dbbc2484010000           fstp      xword ptr [esp + 0x184]
0043b8cb  eb07                     jmp       0x43b8d4
0043b8cd  dbbc2484010000           fstp      xword ptr [esp + 0x184]
0043b8d4  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
0043b8d8  8b30                     mov       esi, dword ptr [eax]
0043b8da  890cb56c2e0302           mov       dword ptr [esi*4 + 0x2032e6c], ecx
0043b8e1  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043b8e8  dbbc24f4000000           fstp      xword ptr [esp + 0xf4]
0043b8ef  d9048d642e0302           fld       dword ptr [ecx*4 + 0x2032e64]
0043b8f6  dbbc2400010000           fstp      xword ptr [esp + 0x100]
0043b8fd  d9048d682e0302           fld       dword ptr [ecx*4 + 0x2032e68]
0043b904  dbbc240c010000           fstp      xword ptr [esp + 0x10c]
0043b90b  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
0043b912  dbbc2478010000           fstp      xword ptr [esp + 0x178]
0043b919  d9048d702e0302           fld       dword ptr [ecx*4 + 0x2032e70]
0043b920  dbbc246c010000           fstp      xword ptr [esp + 0x16c]
0043b927  d9048d742e0302           fld       dword ptr [ecx*4 + 0x2032e74]
0043b92e  dbbc2418010000           fstp      xword ptr [esp + 0x118]
0043b935  d9048d782e0302           fld       dword ptr [ecx*4 + 0x2032e78]
0043b93c  dbbc24e8000000           fstp      xword ptr [esp + 0xe8]
0043b943  8d140b                   lea       edx, [ebx + ecx]
0043b946  d904956c2e0302           fld       dword ptr [edx*4 + 0x2032e6c]
0043b94d  dbbc2460010000           fstp      xword ptr [esp + 0x160]
0043b954  d90495702e0302           fld       dword ptr [edx*4 + 0x2032e70]
0043b95b  dbbc2454010000           fstp      xword ptr [esp + 0x154]
0043b962  d90495782e0302           fld       dword ptr [edx*4 + 0x2032e78]
0043b969  dbbc2448010000           fstp      xword ptr [esp + 0x148]
0043b970  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
0043b977  dbac24f4000000           fld       xword ptr [esp + 0xf4]
0043b97e  d82c95602e0302           fsubr     dword ptr [edx*4 + 0x2032e60]
0043b985  dbac2484010000           fld       xword ptr [esp + 0x184]
0043b98c  dbac24f4000000           fld       xword ptr [esp + 0xf4]
0043b993  dee9                     fsubp     st(1)
0043b995  8d05a8405300             lea       eax, [0x5340a8] ; bits=00020000, f32=7.174648137343064e-43
0043b99b  d9c0                     fld       st(0)
0043b99d  d84888                   fmul      dword ptr [eax - 0x78]
0043b9a0  dbac2400010000           fld       xword ptr [esp + 0x100]
0043b9a7  d82c95642e0302           fsubr     dword ptr [edx*4 + 0x2032e64]
0043b9ae  d8f3                     fdiv      st(3)
0043b9b0  8bb424b8010000           mov       esi, dword ptr [esp + 0x1b8]
0043b9b7  d916                     fst       dword ptr [esi]
0043b9b9  d904957c2e0302           fld       dword ptr [edx*4 + 0x2032e7c]
0043b9c0  d9c9                     fxch      st(1)
0043b9c2  d8cb                     fmul      st(3)
0043b9c4  dbac2400010000           fld       xword ptr [esp + 0x100]
0043b9cb  dec1                     faddp     st(1)
0043b9cd  8bb424b4010000           mov       esi, dword ptr [esp + 0x1b4]
0043b9d4  d916                     fst       dword ptr [esi]
0043b9d6  dbac2400010000           fld       xword ptr [esp + 0x100]
0043b9dd  dec1                     faddp     st(1)
0043b9df  d8ca                     fmul      st(2)
0043b9e1  dbac240c010000           fld       xword ptr [esp + 0x10c]
0043b9e8  8b7c2434                 mov       edi, dword ptr [esp + 0x34]
0043b9ec  dec1                     faddp     st(1)
0043b9ee  d917                     fst       dword ptr [edi]
0043b9f0  dbac240c010000           fld       xword ptr [esp + 0x10c]
0043b9f7  dec1                     faddp     st(1)
0043b9f9  dbac2400010000           fld       xword ptr [esp + 0x100]
0043ba00  d82e                     fsubr     dword ptr [esi]
0043ba02  d8cc                     fmul      st(4)
0043ba04  d84898                   fmul      dword ptr [eax - 0x68]
0043ba07  dee9                     fsubp     st(1)
0043ba09  deca                     fmulp     st(2)
0043ba0b  dbac2418010000           fld       xword ptr [esp + 0x118]
0043ba12  dec2                     faddp     st(2)
0043ba14  8b8424bc010000           mov       eax, dword ptr [esp + 0x1bc]
0043ba1b  d9c9                     fxch      st(1)
0043ba1d  d918                     fstp      dword ptr [eax]
0043ba1f  d9ee                     fldz
0043ba21  dbac24f4000000           fld       xword ptr [esp + 0xf4]
0043ba28  dfe9                     fucompi   st(1)
0043ba2a  ddd8                     fstp      st(0)
0043ba2c  dbac24f4000000           fld       xword ptr [esp + 0xf4]
0043ba33  dbbc243c010000           fstp      xword ptr [esp + 0x13c]
0043ba3a  d9c9                     fxch      st(1)
0043ba3c  dbbc2430010000           fstp      xword ptr [esp + 0x130]
0043ba43  d9c9                     fxch      st(1)
0043ba45  dbbc2424010000           fstp      xword ptr [esp + 0x124]
0043ba4c  dbac24e8000000           fld       xword ptr [esp + 0xe8]
0043ba53  d9c9                     fxch      st(1)
0043ba55  d9ca                     fxch      st(2)
0043ba57  d9c9                     fxch      st(1)
0043ba59  0f8a2c000000             jp        0x43ba8b
0043ba5f  752a                     jne       0x43ba8b
0043ba61  d9c9                     fxch      st(1)
0043ba63  dbbc243c010000           fstp      xword ptr [esp + 0x13c]
0043ba6a  89d8                     mov       eax, ebx
0043ba6c  01d0                     add       eax, edx
0043ba6e  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043ba75  d9ca                     fxch      st(2)
0043ba77  dbbc24dc000000           fstp      xword ptr [esp + 0xdc]
0043ba7e  d904857c2e0302           fld       dword ptr [eax*4 + 0x2032e7c]
0043ba85  d9ca                     fxch      st(2)
0043ba87  d9c9                     fxch      st(1)
0043ba89  eb0e                     jmp       0x43ba99
0043ba8b  d9048d7c2e0302           fld       dword ptr [ecx*4 + 0x2032e7c]
0043ba92  dbbc24dc000000           fstp      xword ptr [esp + 0xdc]
0043ba99  d9ee                     fldz
0043ba9b  dbac2484010000           fld       xword ptr [esp + 0x184]
0043baa2  dff1                     fcompi    st(1)
0043baa4  ddd8                     fstp      st(0)
0043baa6  0f8ab2000000             jp        0x43bb5e
0043baac  0f86ac000000             jbe       0x43bb5e
0043bab2  dbac2484010000           fld       xword ptr [esp + 0x184]
0043bab9  dbac243c010000           fld       xword ptr [esp + 0x13c]
0043bac0  def9                     fdivp     st(1)
0043bac2  d9ed                     fldln2
0043bac4  d9c0                     fld       st(0)
0043bac6  d9c9                     fxch      st(1)
0043bac8  d9ca                     fxch      st(2)
0043baca  d9f1                     fyl2x
0043bacc  d99c249c010000           fstp      dword ptr [esp + 0x19c]
0043bad3  d984249c010000           fld       dword ptr [esp + 0x19c]
0043bada  dbac24dc000000           fld       xword ptr [esp + 0xdc]
0043bae1  defd                     fdivp     st(5)
0043bae3  d9c1                     fld       st(1)
0043bae5  d9c9                     fxch      st(1)
0043bae7  d9cd                     fxch      st(5)
0043bae9  d9f1                     fyl2x
0043baeb  d99c249c010000           fstp      dword ptr [esp + 0x19c]
0043baf2  d9cb                     fxch      st(3)
0043baf4  d88c249c010000           fmul      dword ptr [esp + 0x19c]
0043bafb  dbac243c010000           fld       xword ptr [esp + 0x13c]
0043bb02  defb                     fdivp     st(3)
0043bb04  d9cb                     fxch      st(3)
0043bb06  d9c9                     fxch      st(1)
0043bb08  d9ca                     fxch      st(2)
0043bb0a  d9f1                     fyl2x
0043bb0c  d99c249c010000           fstp      dword ptr [esp + 0x19c]
0043bb13  d9c9                     fxch      st(1)
0043bb15  d8b4249c010000           fdiv      dword ptr [esp + 0x19c]
0043bb1c  d91de4415300             fstp      dword ptr [0x5341e4] ; bits=00000000, f32=0.0
0043bb22  d9ea                     fldl2e
0043bb24  d80de4415300             fmul      dword ptr [0x5341e4] ; bits=00000000, f32=0.0
0043bb2a  d9c0                     fld       st(0)
0043bb2c  d9fc                     frndint
0043bb2e  dce9                     fsub      st(1), st(0)
0043bb30  d9c9                     fxch      st(1)
0043bb32  d9f0                     f2xm1
0043bb34  d80534405300             fadd      dword ptr [0x534034] ; bits=0000803f, f32=1.0
0043bb3a  d9fd                     fscale
0043bb3c  ddd9                     fstp      st(1)
0043bb3e  d99c249c010000           fstp      dword ptr [esp + 0x19c]
0043bb45  dbac24dc000000           fld       xword ptr [esp + 0xdc]
0043bb4c  d88c249c010000           fmul      dword ptr [esp + 0x19c]
0043bb53  8b8424d8010000           mov       eax, dword ptr [esp + 0x1d8]
0043bb5a  d918                     fstp      dword ptr [eax]
0043bb5c  eb11                     jmp       0x43bb6f
0043bb5e  ddd9                     fstp      st(1)
0043bb60  ddd9                     fstp      st(1)
0043bb62  8b8424d8010000           mov       eax, dword ptr [esp + 0x1d8]
0043bb69  c70000000000             mov       dword ptr [eax], 0
0043bb6f  8b442428                 mov       eax, dword ptr [esp + 0x28]
0043bb73  85c0                     test      eax, eax
0043bb75  0f85ae000000             jne       0x43bc29
0043bb7b  dbac2454010000           fld       xword ptr [esp + 0x154]
0043bb82  dbac246c010000           fld       xword ptr [esp + 0x16c]
0043bb89  dee9                     fsubp     st(1)
0043bb8b  dbac2424010000           fld       xword ptr [esp + 0x124]
0043bb92  def9                     fdivp     st(1)
0043bb94  8b8424cc010000           mov       eax, dword ptr [esp + 0x1cc]
0043bb9b  d910                     fst       dword ptr [eax]
0043bb9d  dbac2430010000           fld       xword ptr [esp + 0x130]
0043bba4  dec9                     fmulp     st(1)
0043bba6  dbac246c010000           fld       xword ptr [esp + 0x16c]
0043bbad  dec1                     faddp     st(1)
0043bbaf  8b8424c8010000           mov       eax, dword ptr [esp + 0x1c8]
0043bbb6  d918                     fstp      dword ptr [eax]
0043bbb8  dbac2448010000           fld       xword ptr [esp + 0x148]
0043bbbf  d8e1                     fsub      st(1)
0043bbc1  dbac2424010000           fld       xword ptr [esp + 0x124]
0043bbc8  def9                     fdivp     st(1)
0043bbca  8b8424d4010000           mov       eax, dword ptr [esp + 0x1d4]
0043bbd1  d910                     fst       dword ptr [eax]
0043bbd3  dbac2430010000           fld       xword ptr [esp + 0x130]
0043bbda  dec9                     fmulp     st(1)
0043bbdc  dec1                     faddp     st(1)
0043bbde  8b8424d0010000           mov       eax, dword ptr [esp + 0x1d0]
0043bbe5  d918                     fstp      dword ptr [eax]
0043bbe7  dbac2460010000           fld       xword ptr [esp + 0x160]
0043bbee  dbac2478010000           fld       xword ptr [esp + 0x178]
0043bbf5  dee9                     fsubp     st(1)
0043bbf7  dbac2424010000           fld       xword ptr [esp + 0x124]
0043bbfe  def9                     fdivp     st(1)
0043bc00  8b8424c4010000           mov       eax, dword ptr [esp + 0x1c4]
0043bc07  d910                     fst       dword ptr [eax]
0043bc09  dbac2430010000           fld       xword ptr [esp + 0x130]
0043bc10  dec9                     fmulp     st(1)
0043bc12  dbac2478010000           fld       xword ptr [esp + 0x178]
0043bc19  dec1                     faddp     st(1)
0043bc1b  8b8424c0010000           mov       eax, dword ptr [esp + 0x1c0]
0043bc22  d918                     fstp      dword ptr [eax]
0043bc24  e99d020000               jmp       0x43bec6
0043bc29  dbac2430010000           fld       xword ptr [esp + 0x130]
0043bc30  dbac2424010000           fld       xword ptr [esp + 0x124]
0043bc37  def9                     fdivp     st(1)
0043bc39  d9c0                     fld       st(0)
0043bc3b  d82d34405300             fsubr     dword ptr [0x534034] ; bits=0000803f, f32=1.0
0043bc41  d9c0                     fld       st(0)
0043bc43  d8ca                     fmul      st(2)
0043bc45  dbac2424010000           fld       xword ptr [esp + 0x124]
0043bc4c  dec9                     fmulp     st(1)
0043bc4e  d9c0                     fld       st(0)
0043bc50  d8cb                     fmul      st(3)
0043bc52  d9e0                     fchs
0043bc54  dbbc24d0000000           fstp      xword ptr [esp + 0xd0]
0043bc5b  d8c9                     fmul      st(1)
0043bc5d  d9c2                     fld       st(2)
0043bc5f  d8c0                     fadd      st(0)
0043bc61  d80534405300             fadd      dword ptr [0x534034] ; bits=0000803f, f32=1.0
0043bc67  8d05a8405300             lea       eax, [0x5340a8] ; bits=00020000, f32=7.174648137343064e-43
0043bc6d  d9c0                     fld       st(0)
0043bc6f  d86894                   fsubr     dword ptr [eax - 0x6c]
0043bc72  d8cc                     fmul      st(4)
0043bc74  d8cc                     fmul      st(4)
0043bc76  dbbc24c4000000           fstp      xword ptr [esp + 0xc4]
0043bc7d  d9c2                     fld       st(2)
0043bc7f  d8c8                     fmul      st(0)
0043bc81  dec9                     fmulp     st(1)
0043bc83  d9c3                     fld       st(3)
0043bc85  d8489c                   fmul      dword ptr [eax - 0x64]
0043bc88  d82d34405300             fsubr     dword ptr [0x534034] ; bits=0000803f, f32=1.0
0043bc8e  d9c0                     fld       st(0)
0043bc90  d80534405300             fadd      dword ptr [0x534034] ; bits=0000803f, f32=1.0
0043bc96  d8cd                     fmul      st(5)
0043bc98  d9e0                     fchs
0043bc9a  dbbc24b8000000           fstp      xword ptr [esp + 0xb8]
0043bca1  d8cb                     fmul      st(3)
0043bca3  d9cb                     fxch      st(3)
0043bca5  d848a0                   fmul      dword ptr [eax - 0x60]
0043bca8  decc                     fmulp     st(4)
0043bcaa  dbac2424010000           fld       xword ptr [esp + 0x124]
0043bcb1  defc                     fdivp     st(4)
0043bcb3  d9cb                     fxch      st(3)
0043bcb5  dbbc24ac000000           fstp      xword ptr [esp + 0xac]
0043bcbc  8b442428                 mov       eax, dword ptr [esp + 0x28]
0043bcc0  01c1                     add       ecx, eax
0043bcc2  89d3                     mov       ebx, edx
0043bcc4  01c3                     add       ebx, eax
0043bcc6  89da                     mov       edx, ebx
0043bcc8  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043bccf  dbbc24a0000000           fstp      xword ptr [esp + 0xa0]
0043bcd6  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
0043bcdd  dbbc2494000000           fstp      xword ptr [esp + 0x94]
0043bce4  d9048d642e0302           fld       dword ptr [ecx*4 + 0x2032e64]
0043bceb  dbbc2488000000           fstp      xword ptr [esp + 0x88]
0043bcf2  d90495642e0302           fld       dword ptr [edx*4 + 0x2032e64]
0043bcf9  db7c247c                 fstp      xword ptr [esp + 0x7c]
0043bcfd  d9c9                     fxch      st(1)
0043bcff  db7c2470                 fstp      xword ptr [esp + 0x70]
0043bd03  d9c9                     fxch      st(1)
0043bd05  db7c2464                 fstp      xword ptr [esp + 0x64]
0043bd09  db7c2458                 fstp      xword ptr [esp + 0x58]
0043bd0d  837c242420               cmp       dword ptr [esp + 0x24], 0x20
0043bd12  7518                     jne       0x43bd2c
0043bd14  d9048d682e0302           fld       dword ptr [ecx*4 + 0x2032e68]
0043bd1b  db7c244c                 fstp      xword ptr [esp + 0x4c]
0043bd1f  d90495682e0302           fld       dword ptr [edx*4 + 0x2032e68]
0043bd26  db7c2440                 fstp      xword ptr [esp + 0x40]
0043bd2a  eb16                     jmp       0x43bd42
0043bd2c  d9048d702e0302           fld       dword ptr [ecx*4 + 0x2032e70]
0043bd33  db7c244c                 fstp      xword ptr [esp + 0x4c]
0043bd37  d90495702e0302           fld       dword ptr [edx*4 + 0x2032e70]
0043bd3e  db7c2440                 fstp      xword ptr [esp + 0x40]
0043bd42  db6c2458                 fld       xword ptr [esp + 0x58]
0043bd46  dbac2488000000           fld       xword ptr [esp + 0x88]
0043bd4d  dec9                     fmulp     st(1)
0043bd4f  dbac24d0000000           fld       xword ptr [esp + 0xd0]
0043bd56  db6c247c                 fld       xword ptr [esp + 0x7c]
0043bd5a  dec9                     fmulp     st(1)
0043bd5c  dec1                     faddp     st(1)
0043bd5e  db6c2464                 fld       xword ptr [esp + 0x64]
0043bd62  dbac246c010000           fld       xword ptr [esp + 0x16c]
0043bd69  dec9                     fmulp     st(1)
0043bd6b  dec1                     faddp     st(1)
0043bd6d  dbac24c4000000           fld       xword ptr [esp + 0xc4]
0043bd74  dbac2454010000           fld       xword ptr [esp + 0x154]
0043bd7b  dec9                     fmulp     st(1)
0043bd7d  dec1                     faddp     st(1)
0043bd7f  8b8424c8010000           mov       eax, dword ptr [esp + 0x1c8]
0043bd86  d918                     fstp      dword ptr [eax]
0043bd88  db6c2470                 fld       xword ptr [esp + 0x70]
0043bd8c  dbac2488000000           fld       xword ptr [esp + 0x88]
0043bd93  dec9                     fmulp     st(1)
0043bd95  dbac24b8000000           fld       xword ptr [esp + 0xb8]
0043bd9c  db6c247c                 fld       xword ptr [esp + 0x7c]
0043bda0  dec9                     fmulp     st(1)
0043bda2  dec1                     faddp     st(1)
0043bda4  dbac2454010000           fld       xword ptr [esp + 0x154]
0043bdab  dbac246c010000           fld       xword ptr [esp + 0x16c]
0043bdb2  dee9                     fsubp     st(1)
0043bdb4  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043bdbb  dec9                     fmulp     st(1)
0043bdbd  dec1                     faddp     st(1)
0043bdbf  8b8424cc010000           mov       eax, dword ptr [esp + 0x1cc]
0043bdc6  d918                     fstp      dword ptr [eax]
0043bdc8  db6c2458                 fld       xword ptr [esp + 0x58]
0043bdcc  db6c244c                 fld       xword ptr [esp + 0x4c]
0043bdd0  dec9                     fmulp     st(1)
0043bdd2  dbac24d0000000           fld       xword ptr [esp + 0xd0]
0043bdd9  db6c2440                 fld       xword ptr [esp + 0x40]
0043bddd  dec9                     fmulp     st(1)
0043bddf  dec1                     faddp     st(1)
0043bde1  db6c2464                 fld       xword ptr [esp + 0x64]
0043bde5  d8ca                     fmul      st(2)
0043bde7  dec1                     faddp     st(1)
0043bde9  dbac24c4000000           fld       xword ptr [esp + 0xc4]
0043bdf0  dbac2448010000           fld       xword ptr [esp + 0x148]
0043bdf7  dec9                     fmulp     st(1)
0043bdf9  dec1                     faddp     st(1)
0043bdfb  8b8424d0010000           mov       eax, dword ptr [esp + 0x1d0]
0043be02  d918                     fstp      dword ptr [eax]
0043be04  db6c2470                 fld       xword ptr [esp + 0x70]
0043be08  db6c244c                 fld       xword ptr [esp + 0x4c]
0043be0c  dec9                     fmulp     st(1)
0043be0e  dbac24b8000000           fld       xword ptr [esp + 0xb8]
0043be15  db6c2440                 fld       xword ptr [esp + 0x40]
0043be19  dec9                     fmulp     st(1)
0043be1b  dec1                     faddp     st(1)
0043be1d  dbac2448010000           fld       xword ptr [esp + 0x148]
0043be24  dee2                     fsubrp    st(2)
0043be26  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043be2d  deca                     fmulp     st(2)
0043be2f  dec1                     faddp     st(1)
0043be31  8b8424d4010000           mov       eax, dword ptr [esp + 0x1d4]
0043be38  d918                     fstp      dword ptr [eax]
0043be3a  db6c2458                 fld       xword ptr [esp + 0x58]
0043be3e  dbac24a0000000           fld       xword ptr [esp + 0xa0]
0043be45  dec9                     fmulp     st(1)
0043be47  dbac24d0000000           fld       xword ptr [esp + 0xd0]
0043be4e  dbac2494000000           fld       xword ptr [esp + 0x94]
0043be55  dec9                     fmulp     st(1)
0043be57  dec1                     faddp     st(1)
0043be59  db6c2464                 fld       xword ptr [esp + 0x64]
0043be5d  dbac2478010000           fld       xword ptr [esp + 0x178]
0043be64  dec9                     fmulp     st(1)
0043be66  dec1                     faddp     st(1)
0043be68  dbac24c4000000           fld       xword ptr [esp + 0xc4]
0043be6f  dbac2460010000           fld       xword ptr [esp + 0x160]
0043be76  dec9                     fmulp     st(1)
0043be78  dec1                     faddp     st(1)
0043be7a  8b8424c0010000           mov       eax, dword ptr [esp + 0x1c0]
0043be81  d918                     fstp      dword ptr [eax]
0043be83  db6c2470                 fld       xword ptr [esp + 0x70]
0043be87  dbac24a0000000           fld       xword ptr [esp + 0xa0]
0043be8e  dec9                     fmulp     st(1)
0043be90  dbac24b8000000           fld       xword ptr [esp + 0xb8]
0043be97  dbac2494000000           fld       xword ptr [esp + 0x94]
0043be9e  dec9                     fmulp     st(1)
0043bea0  dec1                     faddp     st(1)
0043bea2  dbac2460010000           fld       xword ptr [esp + 0x160]
0043bea9  dbac2478010000           fld       xword ptr [esp + 0x178]
0043beb0  dee9                     fsubp     st(1)
0043beb2  dbac24ac000000           fld       xword ptr [esp + 0xac]
0043beb9  dec9                     fmulp     st(1)
0043bebb  dec1                     faddp     st(1)
0043bebd  8b8424c4010000           mov       eax, dword ptr [esp + 0x1c4]
0043bec4  d918                     fstp      dword ptr [eax]
0043bec6  8b8424c0010000           mov       eax, dword ptr [esp + 0x1c0]
0043becd  d900                     fld       dword ptr [eax]
0043becf  d9c0                     fld       st(0)
0043bed1  d800                     fadd      dword ptr [eax]
0043bed3  8b8c24c4010000           mov       ecx, dword ptr [esp + 0x1c4]
0043beda  d809                     fmul      dword ptr [ecx]
0043bedc  d919                     fstp      dword ptr [ecx]
0043bede  d8c8                     fmul      st(0)
0043bee0  d918                     fstp      dword ptr [eax]
0043bee2  b800000000               mov       eax, 0
0043bee7  5f                       pop       edi
0043bee8  5e                       pop       esi
0043bee9  5b                       pop       ebx
0043beea  81c498010000             add       esp, 0x198
0043bef0  c3                       ret
0043bef1  90                       nop
0043bef2  8da42400000000           lea       esp, [esp]
0043bef9  8da42400000000           lea       esp, [esp]
