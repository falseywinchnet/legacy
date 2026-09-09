; _jwe_igetfig
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0xe55a0
004e55a0  55                       push      ebp
004e55a1  8bec                     mov       ebp, esp
004e55a3  8b4d08                   mov       ecx, dword ptr [ebp + 8]
004e55a6  33c0                     xor       eax, eax
004e55a8  56                       push      esi
004e55a9  57                       push      edi
004e55aa  8a4115                   mov       al, byte ptr [ecx + 0x15]
004e55ad  0fbf7916                 movsx     edi, word ptr [ecx + 0x16]
004e55b1  8bf0                     mov       esi, eax
004e55b3  0fbe4114                 movsx     eax, byte ptr [ecx + 0x14]
004e55b7  83f80c                   cmp       eax, 0xc
004e55ba  7758                     ja        0x4e5614
004e55bc  33d2                     xor       edx, edx
004e55be  8a9038564e00             mov       dl, byte ptr [eax + 0x4e5638]
004e55c4  ff249524564e00           jmp       dword ptr [edx*4 + 0x4e5624]
004e55cb  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
004e55ce  8d0437                   lea       eax, [edi + esi]
004e55d1  03c1                     add       eax, ecx
004e55d3  eb42                     jmp       0x4e5617
004e55d5  8b450c                   mov       eax, dword ptr [ebp + 0xc]
004e55d8  83f8ff                   cmp       eax, -1
004e55db  7e0e                     jle       0x4e55eb
004e55dd  3bc6                     cmp       eax, esi
004e55df  7f0a                     jg        0x4e55eb
004e55e1  8bc6                     mov       eax, esi
004e55e3  66c741020400             mov       word ptr [ecx + 2], 4
004e55e9  eb2c                     jmp       0x4e5617
004e55eb  66c741020000             mov       word ptr [ecx + 2], 0
004e55f1  8d0437                   lea       eax, [edi + esi]
004e55f4  eb21                     jmp       0x4e5617
004e55f6  8b450c                   mov       eax, dword ptr [ebp + 0xc]
004e55f9  bf03000000               mov       edi, 3
004e55fe  99                       cdq
004e55ff  f7ff                     idiv      edi
004e5601  668b1495d0d65800         mov       dx, word ptr [edx*4 + 0x58d6d0]
004e5609  0fbfc2                   movsx     eax, dx
004e560c  66895118                 mov       word ptr [ecx + 0x18], dx
004e5610  03c6                     add       eax, esi
004e5612  eb03                     jmp       0x4e5617
004e5614  8b450c                   mov       eax, dword ptr [ebp + 0xc]
004e5617  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
004e561a  5f                       pop       edi
004e561b  3bc1                     cmp       eax, ecx
004e561d  5e                       pop       esi
004e561e  7e02                     jle       0x4e5622
004e5620  8bc1                     mov       eax, ecx
004e5622  5d                       pop       ebp
004e5623  c3                       ret
004e5624  f1                       int1
004e5625  55                       push      ebp
004e5626  4e                       dec       esi
004e5627  00cb                     add       bl, cl
004e5629  55                       push      ebp
004e562a  4e                       dec       esi
004e562b  00d5                     add       ch, dl
004e562d  55                       push      ebp
004e562e  4e                       dec       esi
004e562f  00f6                     add       dh, dh
004e5631  55                       push      ebp
004e5632  4e                       dec       esi
004e5633  001456                   add       byte ptr [esi + edx*2], dl
004e5636  4e                       dec       esi
004e5637  0000                     add       byte ptr [eax], al
004e5639  0404                     add       al, 4
004e563b  0401                     add       al, 1
004e563d  0404                     add       al, 4
004e563f  0402                     add       al, 2
004e5641  0404                     add       al, 4
004e5643  0403                     add       al, 3
004e5645  90                       nop
004e5646  90                       nop
004e5647  90                       nop
004e5648  90                       nop
004e5649  90                       nop
004e564a  90                       nop
004e564b  90                       nop
004e564c  90                       nop
004e564d  90                       nop
004e564e  90                       nop
004e564f  90                       nop
