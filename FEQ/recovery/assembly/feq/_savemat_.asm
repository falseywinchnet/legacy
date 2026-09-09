; _savemat_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x75c00
00475c00  53                       push      ebx
00475c01  56                       push      esi
00475c02  57                       push      edi
00475c03  8b442410                 mov       eax, dword ptr [esp + 0x10]
00475c07  8b542414                 mov       edx, dword ptr [esp + 0x14]
00475c0b  8b5c2418                 mov       ebx, dword ptr [esp + 0x18]
00475c0f  8b12                     mov       edx, dword ptr [edx]
00475c11  8d0d48f05500             lea       ecx, [0x55f048] ; bits=00020000, f32=7.174648137343064e-43
00475c17  895190                   mov       dword ptr [ecx - 0x70], edx
00475c1a  8b00                     mov       eax, dword ptr [eax]
00475c1c  894194                   mov       dword ptr [ecx - 0x6c], eax
00475c1f  8b5194                   mov       edx, dword ptr [ecx - 0x6c]
00475c22  83799400                 cmp       dword ptr [ecx - 0x6c], 0
00475c26  7e55                     jle       0x475c7d
00475c28  b900000000               mov       ecx, 0
00475c2d  83fa02                   cmp       edx, 2
00475c30  7c31                     jl        0x475c63
00475c32  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
00475c36  8b34c8                   mov       esi, dword ptr [eax + ecx*8]
00475c39  8b7c2424                 mov       edi, dword ptr [esp + 0x24]
00475c3d  8934cf                   mov       dword ptr [edi + ecx*8], esi
00475c40  8b74c804                 mov       esi, dword ptr [eax + ecx*8 + 4]
00475c44  8974cf04                 mov       dword ptr [edi + ecx*8 + 4], esi
00475c48  8b74c80c                 mov       esi, dword ptr [eax + ecx*8 + 0xc]
00475c4c  8b44c808                 mov       eax, dword ptr [eax + ecx*8 + 8]
00475c50  8944cf08                 mov       dword ptr [edi + ecx*8 + 8], eax
00475c54  8974cf0c                 mov       dword ptr [edi + ecx*8 + 0xc], esi
00475c58  83c102                   add       ecx, 2
00475c5b  83ea02                   sub       edx, 2
00475c5e  83fa02                   cmp       edx, 2
00475c61  7dcf                     jge       0x475c32
00475c63  85d2                     test      edx, edx
00475c65  7416                     je        0x475c7d
00475c67  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
00475c6b  8b14c8                   mov       edx, dword ptr [eax + ecx*8]
00475c6e  8b44c804                 mov       eax, dword ptr [eax + ecx*8 + 4]
00475c72  8b742424                 mov       esi, dword ptr [esp + 0x24]
00475c76  8914ce                   mov       dword ptr [esi + ecx*8], edx
00475c79  8944ce04                 mov       dword ptr [esi + ecx*8 + 4], eax
00475c7d  8d0548f05500             lea       eax, [0x55f048] ; bits=00020000, f32=7.174648137343064e-43
00475c83  8b5090                   mov       edx, dword ptr [eax - 0x70]
00475c86  83789000                 cmp       dword ptr [eax - 0x70], 0
00475c8a  7e4d                     jle       0x475cd9
00475c8c  b900000000               mov       ecx, 0
00475c91  83fa02                   cmp       edx, 2
00475c94  7c2d                     jl        0x475cc3
00475c96  8b04cb                   mov       eax, dword ptr [ebx + ecx*8]
00475c99  8b74cb04                 mov       esi, dword ptr [ebx + ecx*8 + 4]
00475c9d  8b7c2420                 mov       edi, dword ptr [esp + 0x20]
00475ca1  8904cf                   mov       dword ptr [edi + ecx*8], eax
00475ca4  8974cf04                 mov       dword ptr [edi + ecx*8 + 4], esi
00475ca8  8b44cb08                 mov       eax, dword ptr [ebx + ecx*8 + 8]
00475cac  8b74cb0c                 mov       esi, dword ptr [ebx + ecx*8 + 0xc]
00475cb0  8944cf08                 mov       dword ptr [edi + ecx*8 + 8], eax
00475cb4  8974cf0c                 mov       dword ptr [edi + ecx*8 + 0xc], esi
00475cb8  83c102                   add       ecx, 2
00475cbb  83ea02                   sub       edx, 2
00475cbe  83fa02                   cmp       edx, 2
00475cc1  7dd3                     jge       0x475c96
00475cc3  85d2                     test      edx, edx
00475cc5  7412                     je        0x475cd9
00475cc7  8b04cb                   mov       eax, dword ptr [ebx + ecx*8]
00475cca  8b54cb04                 mov       edx, dword ptr [ebx + ecx*8 + 4]
00475cce  8b742420                 mov       esi, dword ptr [esp + 0x20]
00475cd2  8904ce                   mov       dword ptr [esi + ecx*8], eax
00475cd5  8954ce04                 mov       dword ptr [esi + ecx*8 + 4], edx
00475cd9  b800000000               mov       eax, 0
00475cde  5f                       pop       edi
00475cdf  5e                       pop       esi
00475ce0  5b                       pop       ebx
00475ce1  c3                       ret
00475ce2  8da42400000000           lea       esp, [esp]
00475ce9  8da42400000000           lea       esp, [esp]
