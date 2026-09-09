; _jwe_ilor
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xbc960
004bc960  55                       push      ebp
004bc961  8bec                     mov       ebp, esp
004bc963  83ec50                   sub       esp, 0x50
004bc966  a160601404               mov       eax, dword ptr [0x4146060] ; _jwe_iuia
004bc96b  53                       push      ebx
004bc96c  8b1d64601404             mov       ebx, dword ptr [0x4146064] ; _jwe_ifca
004bc972  56                       push      esi
004bc973  57                       push      edi
004bc974  8945f0                   mov       dword ptr [ebp - 0x10], eax
004bc977  8b4d08                   mov       ecx, dword ptr [ebp + 8]
004bc97a  8a5101                   mov       dl, byte ptr [ecx + 1]
004bc97d  8893a1000000             mov       byte ptr [ebx + 0xa1], dl
004bc983  8a4102                   mov       al, byte ptr [ecx + 2]
004bc986  2401                     and       al, 1
004bc988  3c01                     cmp       al, 1
004bc98a  7513                     jne       0x4bc99f
004bc98c  8b5104                   mov       edx, dword ptr [ecx + 4]
004bc98f  899368010000             mov       dword ptr [ebx + 0x168], edx
004bc995  8b4104                   mov       eax, dword ptr [ecx + 4]
004bc998  99                       cdq
004bc999  2bc2                     sub       eax, edx
004bc99b  d1f8                     sar       eax, 1
004bc99d  eb09                     jmp       0x4bc9a8
004bc99f  8b4104                   mov       eax, dword ptr [ecx + 4]
004bc9a2  898368010000             mov       dword ptr [ebx + 0x168], eax
004bc9a8  8983a4000000             mov       dword ptr [ebx + 0xa4], eax
004bc9ae  8b4108                   mov       eax, dword ptr [ecx + 8]
004bc9b1  8983a8000000             mov       dword ptr [ebx + 0xa8], eax
004bc9b7  8983ec020000             mov       dword ptr [ebx + 0x2ec], eax
004bc9bd  8a4102                   mov       al, byte ptr [ecx + 2]
004bc9c0  2404                     and       al, 4
004bc9c2  3c04                     cmp       al, 4
004bc9c4  7512                     jne       0x4bc9d8
004bc9c6  8b490c                   mov       ecx, dword ptr [ecx + 0xc]
004bc9c9  c6839501000008           mov       byte ptr [ebx + 0x195], 8
004bc9d0  898b20010000             mov       dword ptr [ebx + 0x120], ecx
004bc9d6  eb11                     jmp       0x4bc9e9
004bc9d8  c7832001000001000000     mov       dword ptr [ebx + 0x120], 1
004bc9e2  c6839501000004           mov       byte ptr [ebx + 0x195], 4
004bc9e9  80bba100000011           cmp       byte ptr [ebx + 0xa1], 0x11
004bc9f0  0f857e020000             jne       0x4bcc74
004bc9f6  8b83a4000000             mov       eax, dword ptr [ebx + 0xa4]
004bc9fc  85c0                     test      eax, eax
004bc9fe  7d0a                     jge       0x4bca0a
004bca00  c783a400000000000000     mov       dword ptr [ebx + 0xa4], 0
004bca0a  8b8320010000             mov       eax, dword ptr [ebx + 0x120]
004bca10  85c0                     test      eax, eax
004bca12  0f8e2a0f0000             jle       0x4bd942
004bca18  8b75f0                   mov       esi, dword ptr [ebp - 0x10]
004bca1b  80beaa01000020           cmp       byte ptr [esi + 0x1aa], 0x20
004bca22  7545                     jne       0x4bca69
004bca24  8b93a4000000             mov       edx, dword ptr [ebx + 0xa4]
004bca2a  8d4df4                   lea       ecx, [ebp - 0xc]
004bca2d  8955f8                   mov       dword ptr [ebp - 8], edx
004bca30  8b83a8000000             mov       eax, dword ptr [ebx + 0xa8]
004bca36  6a00                     push      0
004bca38  8d55f8                   lea       edx, [ebp - 8]
004bca3b  51                       push      ecx
004bca3c  52                       push      edx
004bca3d  8945f4                   mov       dword ptr [ebp - 0xc], eax
004bca40  e8bb100000               call      0x4bdb00 ; _jwe_il_c
004bca45  83c40c                   add       esp, 0xc
004bca48  85c0                     test      eax, eax
004bca4a  0f8432100000             je        0x4bda82
004bca50  a0a5ed5b00               mov       al, byte ptr [0x5beda5]
004bca55  84c0                     test      al, al
004bca57  0f85dc010000             jne       0x4bcc39
004bca5d  c683aa01000001           mov       byte ptr [ebx + 0x1aa], 1
004bca64  e9d0010000               jmp       0x4bcc39
004bca69  8b8388010000             mov       eax, dword ptr [ebx + 0x188]
004bca6f  8bb38c010000             mov       esi, dword ptr [ebx + 0x18c]
004bca75  8bc8                     mov       ecx, eax
004bca77  2bce                     sub       ecx, esi
004bca79  83f901                   cmp       ecx, 1
004bca7c  7d1a                     jge       0x4bca98
004bca7e  6a00                     push      0
004bca80  6a00                     push      0
004bca82  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bca88  e853140000               call      0x4bdee0 ; _jwe_iloc
004bca8d  83c408                   add       esp, 8
004bca90  85c0                     test      eax, eax
004bca92  0f84ea0f0000             je        0x4bda82
004bca98  8b45f0                   mov       eax, dword ptr [ebp - 0x10]
004bca9b  8b938c010000             mov       edx, dword ptr [ebx + 0x18c]
004bcaa1  bf01000000               mov       edi, 1
004bcaa6  33f6                     xor       esi, esi
004bcaa8  8a88aa010000             mov       cl, byte ptr [eax + 0x1aa]
004bcaae  880a                     mov       byte ptr [edx], cl
004bcab0  8b938c010000             mov       edx, dword ptr [ebx + 0x18c]
004bcab6  8b83a8000000             mov       eax, dword ptr [ebx + 0xa8]
004bcabc  42                       inc       edx
004bcabd  89938c010000             mov       dword ptr [ebx + 0x18c], edx
004bcac3  8945f4                   mov       dword ptr [ebp - 0xc], eax
004bcac6  8b8ba4000000             mov       ecx, dword ptr [ebx + 0xa4]
004bcacc  8945ec                   mov       dword ptr [ebp - 0x14], eax
004bcacf  3bcf                     cmp       ecx, edi
004bcad1  0f8ca3000000             jl        0x4bcb7a
004bcad7  8b4df0                   mov       ecx, dword ptr [ebp - 0x10]
004bcada  33d2                     xor       edx, edx
004bcadc  8a91aa010000             mov       dl, byte ptr [ecx + 0x1aa]
004bcae2  0fbe08                   movsx     ecx, byte ptr [eax]
004bcae5  3bca                     cmp       ecx, edx
004bcae7  757e                     jne       0x4bcb67
004bcae9  8bd7                     mov       edx, edi
004bcaeb  8d45f4                   lea       eax, [ebp - 0xc]
004bcaee  6a01                     push      1
004bcaf0  8d4df8                   lea       ecx, [ebp - 8]
004bcaf3  2bd6                     sub       edx, esi
004bcaf5  50                       push      eax
004bcaf6  51                       push      ecx
004bcaf7  8955f8                   mov       dword ptr [ebp - 8], edx
004bcafa  e801100000               call      0x4bdb00 ; _jwe_il_c
004bcaff  83c40c                   add       esp, 0xc
004bcb02  85c0                     test      eax, eax
004bcb04  0f84780f0000             je        0x4bda82
004bcb0a  8b8388010000             mov       eax, dword ptr [ebx + 0x188]
004bcb10  8b8b8c010000             mov       ecx, dword ptr [ebx + 0x18c]
004bcb16  8bd0                     mov       edx, eax
004bcb18  2bd1                     sub       edx, ecx
004bcb1a  83fa01                   cmp       edx, 1
004bcb1d  7d1a                     jge       0x4bcb39
004bcb1f  6a00                     push      0
004bcb21  6a01                     push      1
004bcb23  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bcb29  e8b2130000               call      0x4bdee0 ; _jwe_iloc
004bcb2e  83c408                   add       esp, 8
004bcb31  85c0                     test      eax, eax
004bcb33  0f84490f0000             je        0x4bda82
004bcb39  8b4df0                   mov       ecx, dword ptr [ebp - 0x10]
004bcb3c  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bcb42  8a91aa010000             mov       dl, byte ptr [ecx + 0x1aa]
004bcb48  8810                     mov       byte ptr [eax], dl
004bcb4a  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bcb50  40                       inc       eax
004bcb51  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bcb57  8b45f8                   mov       eax, dword ptr [ebp - 8]
004bcb5a  8b4df4                   mov       ecx, dword ptr [ebp - 0xc]
004bcb5d  03f0                     add       esi, eax
004bcb5f  03c8                     add       ecx, eax
004bcb61  8b45ec                   mov       eax, dword ptr [ebp - 0x14]
004bcb64  894df4                   mov       dword ptr [ebp - 0xc], ecx
004bcb67  8b8ba4000000             mov       ecx, dword ptr [ebx + 0xa4]
004bcb6d  40                       inc       eax
004bcb6e  47                       inc       edi
004bcb6f  8945ec                   mov       dword ptr [ebp - 0x14], eax
004bcb72  3bf9                     cmp       edi, ecx
004bcb74  0f8e5dffffff             jle       0x4bcad7
004bcb7a  8b83a4000000             mov       eax, dword ptr [ebx + 0xa4]
004bcb80  3bf0                     cmp       esi, eax
004bcb82  741f                     je        0x4bcba3
004bcb84  2bc6                     sub       eax, esi
004bcb86  6a01                     push      1
004bcb88  8945f8                   mov       dword ptr [ebp - 8], eax
004bcb8b  8d45f4                   lea       eax, [ebp - 0xc]
004bcb8e  8d4df8                   lea       ecx, [ebp - 8]
004bcb91  50                       push      eax
004bcb92  51                       push      ecx
004bcb93  e8680f0000               call      0x4bdb00 ; _jwe_il_c
004bcb98  83c40c                   add       esp, 0xc
004bcb9b  85c0                     test      eax, eax
004bcb9d  0f84df0e0000             je        0x4bda82
004bcba3  8b8388010000             mov       eax, dword ptr [ebx + 0x188]
004bcba9  8bb38c010000             mov       esi, dword ptr [ebx + 0x18c]
004bcbaf  8bd0                     mov       edx, eax
004bcbb1  2bd6                     sub       edx, esi
004bcbb3  83fa01                   cmp       edx, 1
004bcbb6  7d1a                     jge       0x4bcbd2
004bcbb8  6a00                     push      0
004bcbba  6a01                     push      1
004bcbbc  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bcbc2  e819130000               call      0x4bdee0 ; _jwe_iloc
004bcbc7  83c408                   add       esp, 8
004bcbca  85c0                     test      eax, eax
004bcbcc  0f84b00e0000             je        0x4bda82
004bcbd2  8b4df0                   mov       ecx, dword ptr [ebp - 0x10]
004bcbd5  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bcbdb  8a91aa010000             mov       dl, byte ptr [ecx + 0x1aa]
004bcbe1  8810                     mov       byte ptr [eax], dl
004bcbe3  8bbb8c010000             mov       edi, dword ptr [ebx + 0x18c]
004bcbe9  8b8388010000             mov       eax, dword ptr [ebx + 0x188]
004bcbef  47                       inc       edi
004bcbf0  8bcf                     mov       ecx, edi
004bcbf2  8bd0                     mov       edx, eax
004bcbf4  2bd1                     sub       edx, ecx
004bcbf6  89bb8c010000             mov       dword ptr [ebx + 0x18c], edi
004bcbfc  83fa01                   cmp       edx, 1
004bcbff  7d1a                     jge       0x4bcc1b
004bcc01  6a00                     push      0
004bcc03  6a01                     push      1
004bcc05  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bcc0b  e8d0120000               call      0x4bdee0 ; _jwe_iloc
004bcc10  83c408                   add       esp, 8
004bcc13  85c0                     test      eax, eax
004bcc15  0f84670e0000             je        0x4bda82
004bcc1b  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bcc21  8a8b97010000             mov       cl, byte ptr [ebx + 0x197]
004bcc27  8b75f0                   mov       esi, dword ptr [ebp - 0x10]
004bcc2a  8808                     mov       byte ptr [eax], cl
004bcc2c  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bcc32  40                       inc       eax
004bcc33  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bcc39  8b8e48010000             mov       ecx, dword ptr [esi + 0x148]
004bcc3f  41                       inc       ecx
004bcc40  898e48010000             mov       dword ptr [esi + 0x148], ecx
004bcc46  8b8320010000             mov       eax, dword ptr [ebx + 0x120]
004bcc4c  8b9368010000             mov       edx, dword ptr [ebx + 0x168]
004bcc52  8bbba8000000             mov       edi, dword ptr [ebx + 0xa8]
004bcc58  48                       dec       eax
004bcc59  03fa                     add       edi, edx
004bcc5b  85c0                     test      eax, eax
004bcc5d  898320010000             mov       dword ptr [ebx + 0x120], eax
004bcc63  89bba8000000             mov       dword ptr [ebx + 0xa8], edi
004bcc69  0f8facfdffff             jg        0x4bca1b
004bcc6f  e9ce0c0000               jmp       0x4bd942
004bcc74  80bbaa01000001           cmp       byte ptr [ebx + 0x1aa], 1
004bcc7b  7560                     jne       0x4bccdd
004bcc7d  8b8b88010000             mov       ecx, dword ptr [ebx + 0x188]
004bcc83  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bcc89  8bd1                     mov       edx, ecx
004bcc8b  2bd0                     sub       edx, eax
004bcc8d  83fa01                   cmp       edx, 1
004bcc90  7d2d                     jge       0x4bccbf
004bcc92  8b55f0                   mov       edx, dword ptr [ebp - 0x10]
004bcc95  8a826c010000             mov       al, byte ptr [edx + 0x16c]
004bcc9b  84c0                     test      al, al
004bcc9d  7537                     jne       0x4bccd6
004bcc9f  6a00                     push      0
004bcca1  6a00                     push      0
004bcca3  898b8c010000             mov       dword ptr [ebx + 0x18c], ecx
004bcca9  e832120000               call      0x4bdee0 ; _jwe_iloc
004bccae  83c408                   add       esp, 8
004bccb1  85c0                     test      eax, eax
004bccb3  0f84c90d0000             je        0x4bda82
004bccb9  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bccbf  8a8b97010000             mov       cl, byte ptr [ebx + 0x197]
004bccc5  8808                     mov       byte ptr [eax], cl
004bccc7  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bcccc  84c0                     test      al, al
004bccce  7506                     jne       0x4bccd6
004bccd0  ff838c010000             inc       dword ptr [ebx + 0x18c]
004bccd6  c683aa01000000           mov       byte ptr [ebx + 0x1aa], 0
004bccdd  c645ff00                 mov       byte ptr [ebp - 1], 0
004bcce1  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bcce7  3c0c                     cmp       al, 0xc
004bcce9  722a                     jb        0x4bcd15
004bcceb  3c0e                     cmp       al, 0xe
004bcced  7726                     ja        0x4bcd15
004bccef  8b83a4000000             mov       eax, dword ptr [ebx + 0xa4]
004bccf5  99                       cdq
004bccf6  2bc2                     sub       eax, edx
004bccf8  d1f8                     sar       eax, 1
004bccfa  8983a4000000             mov       dword ptr [ebx + 0xa4], eax
004bcd00  8b8368010000             mov       eax, dword ptr [ebx + 0x168]
004bcd06  99                       cdq
004bcd07  2bc2                     sub       eax, edx
004bcd09  d1f8                     sar       eax, 1
004bcd0b  898368010000             mov       dword ptr [ebx + 0x168], eax
004bcd11  c645ff01                 mov       byte ptr [ebp - 1], 1
004bcd15  8d55b0                   lea       edx, [ebp - 0x50]
004bcd18  8993ac000000             mov       dword ptr [ebx + 0xac], edx
004bcd1e  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bcd23  84c0                     test      al, al
004bcd25  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bcd2b  7573                     jne       0x4bcda0
004bcd2d  3c0b                     cmp       al, 0xb
004bcd2f  7423                     je        0x4bcd54
004bcd31  3c0e                     cmp       al, 0xe
004bcd33  741f                     je        0x4bcd54
004bcd35  25ff000000               and       eax, 0xff
004bcd3a  8db3c0000000             lea       esi, [ebx + 0xc0]
004bcd40  8a881c0a5c00             mov       cl, byte ptr [eax + 0x5c0a1c]
004bcd46  c683c300000000           mov       byte ptr [ebx + 0xc3], 0
004bcd4d  80c111                   add       cl, 0x11
004bcd50  880e                     mov       byte ptr [esi], cl
004bcd52  eb1d                     jmp       0x4bcd71
004bcd54  25ff000000               and       eax, 0xff
004bcd59  8db3c0000000             lea       esi, [ebx + 0xc0]
004bcd5f  8a901c0a5c00             mov       dl, byte ptr [eax + 0x5c0a1c]
004bcd65  c683c300000004           mov       byte ptr [ebx + 0xc3], 4
004bcd6c  80c212                   add       dl, 0x12
004bcd6f  8816                     mov       byte ptr [esi], dl
004bcd71  89b3b0000000             mov       dword ptr [ebx + 0xb0], esi
004bcd77  8a88540a5c00             mov       cl, byte ptr [eax + 0x5c0a54]
004bcd7d  888bc1000000             mov       byte ptr [ebx + 0xc1], cl
004bcd83  8a908c0a5c00             mov       dl, byte ptr [eax + 0x5c0a8c]
004bcd89  8893c2000000             mov       byte ptr [ebx + 0xc2], dl
004bcd8f  660fb6801c0a5c00         movzx     ax, byte ptr [eax + 0x5c0a1c]
004bcd97  668983b6000000           mov       word ptr [ebx + 0xb6], ax
004bcd9e  eb58                     jmp       0x4bcdf8
004bcda0  3c0b                     cmp       al, 0xb
004bcda2  740d                     je        0x4bcdb1
004bcda4  3c0e                     cmp       al, 0xe
004bcda6  7409                     je        0x4bcdb1
004bcda8  c683c300000000           mov       byte ptr [ebx + 0xc3], 0
004bcdaf  eb07                     jmp       0x4bcdb8
004bcdb1  c683c300000004           mov       byte ptr [ebx + 0xc3], 4
004bcdb8  8db3c0000000             lea       esi, [ebx + 0xc0]
004bcdbe  25ff000000               and       eax, 0xff
004bcdc3  89b3b0000000             mov       dword ptr [ebx + 0xb0], esi
004bcdc9  8a88e4095c00             mov       cl, byte ptr [eax + 0x5c09e4]
004bcdcf  880e                     mov       byte ptr [esi], cl
004bcdd1  8a90380a5c00             mov       dl, byte ptr [eax + 0x5c0a38]
004bcdd7  8893c1000000             mov       byte ptr [ebx + 0xc1], dl
004bcddd  8a88700a5c00             mov       cl, byte ptr [eax + 0x5c0a70]
004bcde3  888bc2000000             mov       byte ptr [ebx + 0xc2], cl
004bcde9  660fb690000a5c00         movzx     dx, byte ptr [eax + 0x5c0a00]
004bcdf1  668993b6000000           mov       word ptr [ebx + 0xb6], dx
004bcdf8  8b8320010000             mov       eax, dword ptr [ebx + 0x120]
004bcdfe  85c0                     test      eax, eax
004bce00  0f8e3c0b0000             jle       0x4bd942
004bce06  8a93a1000000             mov       dl, byte ptr [ebx + 0xa1]
004bce0c  80fa09                   cmp       dl, 9
004bce0f  0f82de020000             jb        0x4bd0f3
004bce15  80fa0e                   cmp       dl, 0xe
004bce18  0f87d5020000             ja        0x4bd0f3
004bce1e  8b83a8000000             mov       eax, dword ptr [ebx + 0xa8]
004bce24  8bca                     mov       ecx, edx
004bce26  81e1ff000000             and       ecx, 0xff
004bce2c  8b38                     mov       edi, dword ptr [eax]
004bce2e  8d71f7                   lea       esi, [ecx - 9]
004bce31  83fe05                   cmp       esi, 5
004bce34  7739                     ja        0x4bce6f
004bce36  ff24b5d0da4b00           jmp       dword ptr [esi*4 + 0x4bdad0]
004bce3d  81e70000807f             and       edi, 0x7f800000
004bce43  81ff0000807f             cmp       edi, 0x7f800000
004bce49  0f84a4020000             je        0x4bd0f3
004bce4f  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bce54  fec8                     dec       al
004bce56  f6d8                     neg       al
004bce58  1ac0                     sbb       al, al
004bce5a  24f7                     and       al, 0xf7
004bce5c  0412                     add       al, 0x12
004bce5e  8883c0000000             mov       byte ptr [ebx + 0xc0], al
004bce64  8b83a8000000             mov       eax, dword ptr [ebx + 0xa8]
004bce6a  d900                     fld       dword ptr [eax]
004bce6c  dd5de0                   fstp      qword ptr [ebp - 0x20]
004bce6f  dd45e0                   fld       qword ptr [ebp - 0x20]
004bce72  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bce78  dfe0                     fnstsw    ax
004bce7a  f6c405                   test      ah, 5
004bce7d  7a08                     jp        0x4bce87
004bce7f  dd45e0                   fld       qword ptr [ebp - 0x20]
004bce82  d9e0                     fchs
004bce84  dd5de0                   fstp      qword ptr [ebp - 0x20]
004bce87  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bce8c  84c0                     test      al, al
004bce8e  0f8599010000             jne       0x4bd02d
004bce94  a0a5ed5b00               mov       al, byte ptr [0x5beda5]
004bce99  84c0                     test      al, al
004bce9b  754a                     jne       0x4bcee7
004bce9d  dd45e0                   fld       qword ptr [ebp - 0x20]
004bcea0  dc1db8035500             fcomp     qword ptr [0x5503b8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004bcea6  dfe0                     fnstsw    ax
004bcea8  2500010000               and       eax, 0x100
004bcead  0f854e010000             jne       0x4bd001
004bceb3  33d2                     xor       edx, edx
004bceb5  8a918c0a5c00             mov       dl, byte ptr [ecx + 0x5c0a8c]
004bcebb  8955ec                   mov       dword ptr [ebp - 0x14], edx
004bcebe  db45ec                   fild      dword ptr [ebp - 0x14]
004bcec1  dd5de8                   fstp      qword ptr [ebp - 0x18]
004bcec4  8b45ec                   mov       eax, dword ptr [ebp - 0x14]
004bcec7  8b4de8                   mov       ecx, dword ptr [ebp - 0x18]
004bceca  50                       push      eax
004bcecb  51                       push      ecx
004bcecc  6800002440               push      0x40240000
004bced1  6a00                     push      0
004bced3  e841d10200               call      0x4ea019 ; _pow
004bced8  dc5de0                   fcomp     qword ptr [ebp - 0x20]
004bcedb  83c410                   add       esp, 0x10
004bcede  dfe0                     fnstsw    ax
004bcee0  2500410000               and       eax, 0x4100
004bcee5  7473                     je        0x4bcf5a
004bcee7  803da5ed5b0001           cmp       byte ptr [0x5beda5], 1
004bceee  0f850d010000             jne       0x4bd001
004bcef4  dd45e0                   fld       qword ptr [ebp - 0x20]
004bcef7  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bcefd  dfe0                     fnstsw    ax
004bceff  f6c444                   test      ah, 0x44
004bcf02  7b56                     jnp       0x4bcf5a
004bcf04  dd45e0                   fld       qword ptr [ebp - 0x20]
004bcf07  dc1db8035500             fcomp     qword ptr [0x5503b8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004bcf0d  dfe0                     fnstsw    ax
004bcf0f  2500010000               and       eax, 0x100
004bcf14  0f85e7000000             jne       0x4bd001
004bcf1a  33d2                     xor       edx, edx
004bcf1c  33c0                     xor       eax, eax
004bcf1e  8a93a1000000             mov       dl, byte ptr [ebx + 0xa1]
004bcf24  8a828c0a5c00             mov       al, byte ptr [edx + 0x5c0a8c]
004bcf2a  8945ec                   mov       dword ptr [ebp - 0x14], eax
004bcf2d  db45ec                   fild      dword ptr [ebp - 0x14]
004bcf30  dd5de8                   fstp      qword ptr [ebp - 0x18]
004bcf33  8b4dec                   mov       ecx, dword ptr [ebp - 0x14]
004bcf36  8b55e8                   mov       edx, dword ptr [ebp - 0x18]
004bcf39  51                       push      ecx
004bcf3a  52                       push      edx
004bcf3b  6800002440               push      0x40240000
004bcf40  6a00                     push      0
004bcf42  e8d2d00200               call      0x4ea019 ; _pow
004bcf47  dc5de0                   fcomp     qword ptr [ebp - 0x20]
004bcf4a  83c410                   add       esp, 0x10
004bcf4d  dfe0                     fnstsw    ax
004bcf4f  2500410000               and       eax, 0x4100
004bcf54  0f85a7000000             jne       0x4bd001
004bcf5a  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bcf60  3c0b                     cmp       al, 0xb
004bcf62  7471                     je        0x4bcfd5
004bcf64  3c0e                     cmp       al, 0xe
004bcf66  746d                     je        0x4bcfd5
004bcf68  c683c000000012           mov       byte ptr [ebx + 0xc0], 0x12
004bcf6f  eb6b                     jmp       0x4bcfdc
004bcf71  8b4004                   mov       eax, dword ptr [eax + 4]
004bcf74  250000f07f               and       eax, 0x7ff00000
004bcf79  3d0000f07f               cmp       eax, 0x7ff00000
004bcf7e  0f846f010000             je        0x4bd0f3
004bcf84  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bcf89  fec8                     dec       al
004bcf8b  f6d8                     neg       al
004bcf8d  1ac0                     sbb       al, al
004bcf8f  24f7                     and       al, 0xf7
004bcf91  0412                     add       al, 0x12
004bcf93  8883c0000000             mov       byte ptr [ebx + 0xc0], al
004bcf99  8b83a8000000             mov       eax, dword ptr [ebx + 0xa8]
004bcf9f  8b30                     mov       esi, dword ptr [eax]
004bcfa1  8975e0                   mov       dword ptr [ebp - 0x20], esi
004bcfa4  8b4004                   mov       eax, dword ptr [eax + 4]
004bcfa7  8945e4                   mov       dword ptr [ebp - 0x1c], eax
004bcfaa  e9c0feffff               jmp       0x4bce6f
004bcfaf  8b480c                   mov       ecx, dword ptr [eax + 0xc]
004bcfb2  81e10000ff7f             and       ecx, 0x7fff0000
004bcfb8  81f90000ff7f             cmp       ecx, 0x7fff0000
004bcfbe  0f842f010000             je        0x4bd0f3
004bcfc4  c683c00000000a           mov       byte ptr [ebx + 0xc0], 0xa
004bcfcb  e860110000               call      0x4be130 ; _jwe_illd
004bcfd0  e91e010000               jmp       0x4bd0f3
004bcfd5  c683c000000013           mov       byte ptr [ebx + 0xc0], 0x13
004bcfdc  25ff000000               and       eax, 0xff
004bcfe1  66c783b60000000000       mov       word ptr [ebx + 0xb6], 0
004bcfea  8a88540a5c00             mov       cl, byte ptr [eax + 0x5c0a54]
004bcff0  888bc1000000             mov       byte ptr [ebx + 0xc1], cl
004bcff6  8a908c0a5c00             mov       dl, byte ptr [eax + 0x5c0a8c]
004bcffc  e9ec000000               jmp       0x4bd0ed
004bd001  33c0                     xor       eax, eax
004bd003  66c783b60000000100       mov       word ptr [ebx + 0xb6], 1
004bd00c  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd012  8a88540a5c00             mov       cl, byte ptr [eax + 0x5c0a54]
004bd018  fec9                     dec       cl
004bd01a  888bc1000000             mov       byte ptr [ebx + 0xc1], cl
004bd020  8a908c0a5c00             mov       dl, byte ptr [eax + 0x5c0a8c]
004bd026  feca                     dec       dl
004bd028  e9c0000000               jmp       0x4bd0ed
004bd02d  80fa0b                   cmp       dl, 0xb
004bd030  7405                     je        0x4bd037
004bd032  80fa0e                   cmp       dl, 0xe
004bd035  755d                     jne       0x4bd094
004bd037  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd03a  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bd040  dfe0                     fnstsw    ax
004bd042  f6c444                   test      ah, 0x44
004bd045  7b46                     jnp       0x4bd08d
004bd047  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd04a  dc1db8035500             fcomp     qword ptr [0x5503b8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004bd050  dfe0                     fnstsw    ax
004bd052  2500010000               and       eax, 0x100
004bd057  753b                     jne       0x4bd094
004bd059  33c0                     xor       eax, eax
004bd05b  8a818c0a5c00             mov       al, byte ptr [ecx + 0x5c0a8c]
004bd061  8945ec                   mov       dword ptr [ebp - 0x14], eax
004bd064  db45ec                   fild      dword ptr [ebp - 0x14]
004bd067  dd5de8                   fstp      qword ptr [ebp - 0x18]
004bd06a  8b4dec                   mov       ecx, dword ptr [ebp - 0x14]
004bd06d  8b55e8                   mov       edx, dword ptr [ebp - 0x18]
004bd070  51                       push      ecx
004bd071  52                       push      edx
004bd072  6800002440               push      0x40240000
004bd077  6a00                     push      0
004bd079  e89bcf0200               call      0x4ea019 ; _pow
004bd07e  dc5de0                   fcomp     qword ptr [ebp - 0x20]
004bd081  83c410                   add       esp, 0x10
004bd084  dfe0                     fnstsw    ax
004bd086  2500410000               and       eax, 0x4100
004bd08b  7507                     jne       0x4bd094
004bd08d  c683c000000013           mov       byte ptr [ebx + 0xc0], 0x13
004bd094  8a93a1000000             mov       dl, byte ptr [ebx + 0xa1]
004bd09a  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd09d  8bca                     mov       ecx, edx
004bd09f  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bd0a5  81e1ff000000             and       ecx, 0xff
004bd0ab  660fb681000a5c00         movzx     ax, byte ptr [ecx + 0x5c0a00]
004bd0b3  668983b6000000           mov       word ptr [ebx + 0xb6], ax
004bd0ba  8a81380a5c00             mov       al, byte ptr [ecx + 0x5c0a38]
004bd0c0  8883c1000000             mov       byte ptr [ebx + 0xc1], al
004bd0c6  dfe0                     fnstsw    ax
004bd0c8  f6c444                   test      ah, 0x44
004bd0cb  7a1a                     jp        0x4bd0e7
004bd0cd  80fa09                   cmp       dl, 9
004bd0d0  7215                     jb        0x4bd0e7
004bd0d2  80fa0d                   cmp       dl, 0xd
004bd0d5  7710                     ja        0x4bd0e7
004bd0d7  8a89700a5c00             mov       cl, byte ptr [ecx + 0x5c0a70]
004bd0dd  fec1                     inc       cl
004bd0df  888bc2000000             mov       byte ptr [ebx + 0xc2], cl
004bd0e5  eb0c                     jmp       0x4bd0f3
004bd0e7  8a91700a5c00             mov       dl, byte ptr [ecx + 0x5c0a70]
004bd0ed  8893c2000000             mov       byte ptr [ebx + 0xc2], dl
004bd0f3  ff93d4000000             call      dword ptr [ebx + 0xd4]
004bd0f9  8a156def5b00             mov       dl, byte ptr [0x5bef6d]
004bd0ff  8d75b0                   lea       esi, [ebp - 0x50]
004bd102  33c0                     xor       eax, eax
004bd104  8975f4                   mov       dword ptr [ebp - 0xc], esi
004bd107  8a83c1000000             mov       al, byte ptr [ebx + 0xc1]
004bd10d  80fa01                   cmp       dl, 1
004bd110  8bf8                     mov       edi, eax
004bd112  897df8                   mov       dword ptr [ebp - 8], edi
004bd115  756c                     jne       0x4bd183
004bd117  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd11d  3c0a                     cmp       al, 0xa
004bd11f  7404                     je        0x4bd125
004bd121  3c0d                     cmp       al, 0xd
004bd123  7525                     jne       0x4bd14a
004bd125  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd12b  33c0                     xor       eax, eax
004bd12d  84c9                     test      cl, cl
004bd12f  7219                     jb        0x4bd14a
004bd131  807c05b045               cmp       byte ptr [ebp + eax - 0x50], 0x45
004bd136  7505                     jne       0x4bd13d
004bd138  c64405b044               mov       byte ptr [ebp + eax - 0x50], 0x44
004bd13d  33c9                     xor       ecx, ecx
004bd13f  40                       inc       eax
004bd140  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd146  3bc1                     cmp       eax, ecx
004bd148  7ee7                     jle       0x4bd131
004bd14a  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd150  3c0a                     cmp       al, 0xa
004bd152  7604                     jbe       0x4bd158
004bd154  3c0e                     cmp       al, 0xe
004bd156  7604                     jbe       0x4bd15c
004bd158  3c11                     cmp       al, 0x11
004bd15a  7258                     jb        0x4bd1b4
004bd15c  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd162  b801000000               mov       eax, 1
004bd167  3ac8                     cmp       cl, al
004bd169  7249                     jb        0x4bd1b4
004bd16b  803e20                   cmp       byte ptr [esi], 0x20
004bd16e  753a                     jne       0x4bd1aa
004bd170  46                       inc       esi
004bd171  33c9                     xor       ecx, ecx
004bd173  8975f4                   mov       dword ptr [ebp - 0xc], esi
004bd176  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd17c  40                       inc       eax
004bd17d  3bc1                     cmp       eax, ecx
004bd17f  7eea                     jle       0x4bd16b
004bd181  eb31                     jmp       0x4bd1b4
004bd183  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd189  b801000000               mov       eax, 1
004bd18e  3ac8                     cmp       cl, al
004bd190  7222                     jb        0x4bd1b4
004bd192  803e20                   cmp       byte ptr [esi], 0x20
004bd195  7513                     jne       0x4bd1aa
004bd197  46                       inc       esi
004bd198  33c9                     xor       ecx, ecx
004bd19a  8975f4                   mov       dword ptr [ebp - 0xc], esi
004bd19d  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd1a3  40                       inc       eax
004bd1a4  3bc1                     cmp       eax, ecx
004bd1a6  7eea                     jle       0x4bd192
004bd1a8  eb0a                     jmp       0x4bd1b4
004bd1aa  8d45b0                   lea       eax, [ebp - 0x50]
004bd1ad  2bc6                     sub       eax, esi
004bd1af  03f8                     add       edi, eax
004bd1b1  897df8                   mov       dword ptr [ebp - 8], edi
004bd1b4  33c9                     xor       ecx, ecx
004bd1b6  80fa01                   cmp       dl, 1
004bd1b9  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd1bf  8d440daf                 lea       eax, [ebp + ecx - 0x51]
004bd1c3  8bf0                     mov       esi, eax
004bd1c5  7525                     jne       0x4bd1ec
004bd1c7  8a8ba1000000             mov       cl, byte ptr [ebx + 0xa1]
004bd1cd  80f90b                   cmp       cl, 0xb
004bd1d0  7205                     jb        0x4bd1d7
004bd1d2  80f90e                   cmp       cl, 0xe
004bd1d5  7605                     jbe       0x4bd1dc
004bd1d7  80f912                   cmp       cl, 0x12
004bd1da  721e                     jb        0x4bd1fa
004bd1dc  803820                   cmp       byte ptr [eax], 0x20
004bd1df  7519                     jne       0x4bd1fa
004bd1e1  8a4eff                   mov       cl, byte ptr [esi - 1]
004bd1e4  4e                       dec       esi
004bd1e5  80f920                   cmp       cl, 0x20
004bd1e8  74f7                     je        0x4bd1e1
004bd1ea  eb0e                     jmp       0x4bd1fa
004bd1ec  803820                   cmp       byte ptr [eax], 0x20
004bd1ef  7509                     jne       0x4bd1fa
004bd1f1  8a4eff                   mov       cl, byte ptr [esi - 1]
004bd1f4  4e                       dec       esi
004bd1f5  80f920                   cmp       cl, 0x20
004bd1f8  74f7                     je        0x4bd1f1
004bd1fa  8bce                     mov       ecx, esi
004bd1fc  2bc8                     sub       ecx, eax
004bd1fe  03f9                     add       edi, ecx
004bd200  897df8                   mov       dword ptr [ebp - 8], edi
004bd203  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd209  3c0a                     cmp       al, 0xa
004bd20b  7404                     je        0x4bd211
004bd20d  3c0d                     cmp       al, 0xd
004bd20f  7568                     jne       0x4bd279
004bd211  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd214  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bd21a  dfe0                     fnstsw    ax
004bd21c  f6c444                   test      ah, 0x44
004bd21f  7b58                     jnp       0x4bd279
004bd221  84d2                     test      dl, dl
004bd223  7554                     jne       0x4bd279
004bd225  a0a5ed5b00               mov       al, byte ptr [0x5beda5]
004bd22a  84c0                     test      al, al
004bd22c  754b                     jne       0x4bd279
004bd22e  83bb3003000003           cmp       dword ptr [ebx + 0x330], 3
004bd235  7542                     jne       0x4bd279
004bd237  80bbc000000009           cmp       byte ptr [ebx + 0xc0], 9
004bd23e  7539                     jne       0x4bd279
004bd240  b901000000               mov       ecx, 1
004bd245  3bf9                     cmp       edi, ecx
004bd247  7c30                     jl        0x4bd279
004bd249  8a06                     mov       al, byte ptr [esi]
004bd24b  3c2b                     cmp       al, 0x2b
004bd24d  740c                     je        0x4bd25b
004bd24f  3c2d                     cmp       al, 0x2d
004bd251  7408                     je        0x4bd25b
004bd253  41                       inc       ecx
004bd254  4e                       dec       esi
004bd255  3bcf                     cmp       ecx, edi
004bd257  7ef0                     jle       0x4bd249
004bd259  eb1e                     jmp       0x4bd279
004bd25b  51                       push      ecx
004bd25c  8d5601                   lea       edx, [esi + 1]
004bd25f  56                       push      esi
004bd260  52                       push      edx
004bd261  e85aca0200               call      0x4e9cc0 ; _memmove
004bd266  8b7df8                   mov       edi, dword ptr [ebp - 8]
004bd269  8a156def5b00             mov       dl, byte ptr [0x5bef6d]
004bd26f  83c40c                   add       esp, 0xc
004bd272  47                       inc       edi
004bd273  c60645                   mov       byte ptr [esi], 0x45
004bd276  897df8                   mov       dword ptr [ebp - 8], edi
004bd279  807dff01                 cmp       byte ptr [ebp - 1], 1
004bd27d  0f8594000000             jne       0x4bd317
004bd283  80fa01                   cmp       dl, 1
004bd286  c645fe00                 mov       byte ptr [ebp - 2], 0
004bd28a  7515                     jne       0x4bd2a1
004bd28c  8d45ff                   lea       eax, [ebp - 1]
004bd28f  8d4dfe                   lea       ecx, [ebp - 2]
004bd292  50                       push      eax
004bd293  8d55f4                   lea       edx, [ebp - 0xc]
004bd296  51                       push      ecx
004bd297  8d45f8                   lea       eax, [ebp - 8]
004bd29a  52                       push      edx
004bd29b  50                       push      eax
004bd29c  83c702                   add       edi, 2
004bd29f  eb11                     jmp       0x4bd2b2
004bd2a1  8d4dff                   lea       ecx, [ebp - 1]
004bd2a4  8d55fe                   lea       edx, [ebp - 2]
004bd2a7  51                       push      ecx
004bd2a8  8d45f4                   lea       eax, [ebp - 0xc]
004bd2ab  52                       push      edx
004bd2ac  8d4df8                   lea       ecx, [ebp - 8]
004bd2af  50                       push      eax
004bd2b0  51                       push      ecx
004bd2b1  47                       inc       edi
004bd2b2  57                       push      edi
004bd2b3  e808090000               call      0x4bdbc0 ; _jwe_il_r
004bd2b8  83c414                   add       esp, 0x14
004bd2bb  85c0                     test      eax, eax
004bd2bd  0f84bf070000             je        0x4bda82
004bd2c3  8a45fe                   mov       al, byte ptr [ebp - 2]
004bd2c6  84c0                     test      al, al
004bd2c8  756e                     jne       0x4bd338
004bd2ca  803d6def5b0001           cmp       byte ptr [0x5bef6d], 1
004bd2d1  7528                     jne       0x4bd2fb
004bd2d3  8b938c010000             mov       edx, dword ptr [ebx + 0x18c]
004bd2d9  c60220                   mov       byte ptr [edx], 0x20
004bd2dc  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bd2e2  c6400128                 mov       byte ptr [eax + 1], 0x28
004bd2e6  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bd2ec  83c002                   add       eax, 2
004bd2ef  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bd2f5  c645fe01                 mov       byte ptr [ebp - 2], 1
004bd2f9  eb3d                     jmp       0x4bd338
004bd2fb  8b8b8c010000             mov       ecx, dword ptr [ebx + 0x18c]
004bd301  c60128                   mov       byte ptr [ecx], 0x28
004bd304  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bd30a  40                       inc       eax
004bd30b  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bd311  c645fe01                 mov       byte ptr [ebp - 2], 1
004bd315  eb21                     jmp       0x4bd338
004bd317  8d55ff                   lea       edx, [ebp - 1]
004bd31a  8d45fe                   lea       eax, [ebp - 2]
004bd31d  52                       push      edx
004bd31e  8d4df4                   lea       ecx, [ebp - 0xc]
004bd321  50                       push      eax
004bd322  8d55f8                   lea       edx, [ebp - 8]
004bd325  51                       push      ecx
004bd326  52                       push      edx
004bd327  57                       push      edi
004bd328  e893080000               call      0x4bdbc0 ; _jwe_il_r
004bd32d  83c414                   add       esp, 0x14
004bd330  85c0                     test      eax, eax
004bd332  0f844a070000             je        0x4bda82
004bd338  8b4df8                   mov       ecx, dword ptr [ebp - 8]
004bd33b  8b75f4                   mov       esi, dword ptr [ebp - 0xc]
004bd33e  8bbb8c010000             mov       edi, dword ptr [ebx + 0x18c]
004bd344  8bc1                     mov       eax, ecx
004bd346  c1e902                   shr       ecx, 2
004bd349  f3a5                     rep movsd dword ptr es:[edi], dword ptr [esi]
004bd34b  8bc8                     mov       ecx, eax
004bd34d  83e103                   and       ecx, 3
004bd350  f3a4                     rep movsb byte ptr es:[edi], byte ptr [esi]
004bd352  8b4df8                   mov       ecx, dword ptr [ebp - 8]
004bd355  8b938c010000             mov       edx, dword ptr [ebx + 0x18c]
004bd35b  03d1                     add       edx, ecx
004bd35d  89938c010000             mov       dword ptr [ebx + 0x18c], edx
004bd363  8a45ff                   mov       al, byte ptr [ebp - 1]
004bd366  3c01                     cmp       al, 1
004bd368  8bca                     mov       ecx, edx
004bd36a  0f8535050000             jne       0x4bd8a5
004bd370  8b8388010000             mov       eax, dword ptr [ebx + 0x188]
004bd376  8bd0                     mov       edx, eax
004bd378  2bd1                     sub       edx, ecx
004bd37a  83fa01                   cmp       edx, 1
004bd37d  7d34                     jge       0x4bd3b3
004bd37f  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bd385  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bd38a  3c01                     cmp       al, 1
004bd38c  7511                     jne       0x4bd39f
004bd38e  8b45f0                   mov       eax, dword ptr [ebp - 0x10]
004bd391  8a886f010000             mov       cl, byte ptr [eax + 0x16f]
004bd397  84c9                     test      cl, cl
004bd399  7504                     jne       0x4bd39f
004bd39b  6a01                     push      1
004bd39d  eb02                     jmp       0x4bd3a1
004bd39f  6a00                     push      0
004bd3a1  6a00                     push      0
004bd3a3  e8380b0000               call      0x4bdee0 ; _jwe_iloc
004bd3a8  83c408                   add       esp, 8
004bd3ab  85c0                     test      eax, eax
004bd3ad  0f84cf060000             je        0x4bda82
004bd3b3  8b8b8c010000             mov       ecx, dword ptr [ebx + 0x18c]
004bd3b9  c6012c                   mov       byte ptr [ecx], 0x2c
004bd3bc  8b938c010000             mov       edx, dword ptr [ebx + 0x18c]
004bd3c2  8b8ba8000000             mov       ecx, dword ptr [ebx + 0xa8]
004bd3c8  42                       inc       edx
004bd3c9  89938c010000             mov       dword ptr [ebx + 0x18c], edx
004bd3cf  8b9368010000             mov       edx, dword ptr [ebx + 0x168]
004bd3d5  03ca                     add       ecx, edx
004bd3d7  8a93a1000000             mov       dl, byte ptr [ebx + 0xa1]
004bd3dd  80fa09                   cmp       dl, 9
004bd3e0  898ba8000000             mov       dword ptr [ebx + 0xa8], ecx
004bd3e6  8bf1                     mov       esi, ecx
004bd3e8  0f82d8020000             jb        0x4bd6c6
004bd3ee  80fa0e                   cmp       dl, 0xe
004bd3f1  0f87cf020000             ja        0x4bd6c6
004bd3f7  8b3e                     mov       edi, dword ptr [esi]
004bd3f9  8bca                     mov       ecx, edx
004bd3fb  81e1ff000000             and       ecx, 0xff
004bd401  8d41f7                   lea       eax, [ecx - 9]
004bd404  83f805                   cmp       eax, 5
004bd407  7739                     ja        0x4bd442
004bd409  ff2485e8da4b00           jmp       dword ptr [eax*4 + 0x4bdae8]
004bd410  81e70000807f             and       edi, 0x7f800000
004bd416  81ff0000807f             cmp       edi, 0x7f800000
004bd41c  0f84a4020000             je        0x4bd6c6
004bd422  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bd427  fec8                     dec       al
004bd429  f6d8                     neg       al
004bd42b  1ac0                     sbb       al, al
004bd42d  24f7                     and       al, 0xf7
004bd42f  0412                     add       al, 0x12
004bd431  8883c0000000             mov       byte ptr [ebx + 0xc0], al
004bd437  8b83a8000000             mov       eax, dword ptr [ebx + 0xa8]
004bd43d  d900                     fld       dword ptr [eax]
004bd43f  dd5de0                   fstp      qword ptr [ebp - 0x20]
004bd442  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd445  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bd44b  dfe0                     fnstsw    ax
004bd44d  f6c405                   test      ah, 5
004bd450  7a08                     jp        0x4bd45a
004bd452  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd455  d9e0                     fchs
004bd457  dd5de0                   fstp      qword ptr [ebp - 0x20]
004bd45a  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bd45f  84c0                     test      al, al
004bd461  0f8599010000             jne       0x4bd600
004bd467  a0a5ed5b00               mov       al, byte ptr [0x5beda5]
004bd46c  84c0                     test      al, al
004bd46e  754a                     jne       0x4bd4ba
004bd470  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd473  dc1db8035500             fcomp     qword ptr [0x5503b8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004bd479  dfe0                     fnstsw    ax
004bd47b  2500010000               and       eax, 0x100
004bd480  0f854e010000             jne       0x4bd5d4
004bd486  33d2                     xor       edx, edx
004bd488  8a918c0a5c00             mov       dl, byte ptr [ecx + 0x5c0a8c]
004bd48e  8955ec                   mov       dword ptr [ebp - 0x14], edx
004bd491  db45ec                   fild      dword ptr [ebp - 0x14]
004bd494  dd5de8                   fstp      qword ptr [ebp - 0x18]
004bd497  8b45ec                   mov       eax, dword ptr [ebp - 0x14]
004bd49a  8b4de8                   mov       ecx, dword ptr [ebp - 0x18]
004bd49d  50                       push      eax
004bd49e  51                       push      ecx
004bd49f  6800002440               push      0x40240000
004bd4a4  6a00                     push      0
004bd4a6  e86ecb0200               call      0x4ea019 ; _pow
004bd4ab  dc5de0                   fcomp     qword ptr [ebp - 0x20]
004bd4ae  83c410                   add       esp, 0x10
004bd4b1  dfe0                     fnstsw    ax
004bd4b3  2500410000               and       eax, 0x4100
004bd4b8  7473                     je        0x4bd52d
004bd4ba  803da5ed5b0001           cmp       byte ptr [0x5beda5], 1
004bd4c1  0f850d010000             jne       0x4bd5d4
004bd4c7  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd4ca  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bd4d0  dfe0                     fnstsw    ax
004bd4d2  f6c444                   test      ah, 0x44
004bd4d5  7b56                     jnp       0x4bd52d
004bd4d7  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd4da  dc1db8035500             fcomp     qword ptr [0x5503b8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004bd4e0  dfe0                     fnstsw    ax
004bd4e2  2500010000               and       eax, 0x100
004bd4e7  0f85e7000000             jne       0x4bd5d4
004bd4ed  33d2                     xor       edx, edx
004bd4ef  33c0                     xor       eax, eax
004bd4f1  8a93a1000000             mov       dl, byte ptr [ebx + 0xa1]
004bd4f7  8a828c0a5c00             mov       al, byte ptr [edx + 0x5c0a8c]
004bd4fd  8945ec                   mov       dword ptr [ebp - 0x14], eax
004bd500  db45ec                   fild      dword ptr [ebp - 0x14]
004bd503  dd5de8                   fstp      qword ptr [ebp - 0x18]
004bd506  8b4dec                   mov       ecx, dword ptr [ebp - 0x14]
004bd509  8b55e8                   mov       edx, dword ptr [ebp - 0x18]
004bd50c  51                       push      ecx
004bd50d  52                       push      edx
004bd50e  6800002440               push      0x40240000
004bd513  6a00                     push      0
004bd515  e8ffca0200               call      0x4ea019 ; _pow
004bd51a  dc5de0                   fcomp     qword ptr [ebp - 0x20]
004bd51d  83c410                   add       esp, 0x10
004bd520  dfe0                     fnstsw    ax
004bd522  2500410000               and       eax, 0x4100
004bd527  0f85a7000000             jne       0x4bd5d4
004bd52d  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd533  3c0b                     cmp       al, 0xb
004bd535  7471                     je        0x4bd5a8
004bd537  3c0e                     cmp       al, 0xe
004bd539  746d                     je        0x4bd5a8
004bd53b  c683c000000012           mov       byte ptr [ebx + 0xc0], 0x12
004bd542  eb6b                     jmp       0x4bd5af
004bd544  8b4604                   mov       eax, dword ptr [esi + 4]
004bd547  250000f07f               and       eax, 0x7ff00000
004bd54c  3d0000f07f               cmp       eax, 0x7ff00000
004bd551  0f846f010000             je        0x4bd6c6
004bd557  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bd55c  fec8                     dec       al
004bd55e  f6d8                     neg       al
004bd560  1ac0                     sbb       al, al
004bd562  24f7                     and       al, 0xf7
004bd564  0412                     add       al, 0x12
004bd566  8883c0000000             mov       byte ptr [ebx + 0xc0], al
004bd56c  8b83a8000000             mov       eax, dword ptr [ebx + 0xa8]
004bd572  8b30                     mov       esi, dword ptr [eax]
004bd574  8975e0                   mov       dword ptr [ebp - 0x20], esi
004bd577  8b4004                   mov       eax, dword ptr [eax + 4]
004bd57a  8945e4                   mov       dword ptr [ebp - 0x1c], eax
004bd57d  e9c0feffff               jmp       0x4bd442
004bd582  8b4e0c                   mov       ecx, dword ptr [esi + 0xc]
004bd585  81e10000ff7f             and       ecx, 0x7fff0000
004bd58b  81f90000ff7f             cmp       ecx, 0x7fff0000
004bd591  0f842f010000             je        0x4bd6c6
004bd597  c683c00000000a           mov       byte ptr [ebx + 0xc0], 0xa
004bd59e  e88d0b0000               call      0x4be130 ; _jwe_illd
004bd5a3  e91e010000               jmp       0x4bd6c6
004bd5a8  c683c000000013           mov       byte ptr [ebx + 0xc0], 0x13
004bd5af  25ff000000               and       eax, 0xff
004bd5b4  66c783b60000000000       mov       word ptr [ebx + 0xb6], 0
004bd5bd  8a88540a5c00             mov       cl, byte ptr [eax + 0x5c0a54]
004bd5c3  888bc1000000             mov       byte ptr [ebx + 0xc1], cl
004bd5c9  8a908c0a5c00             mov       dl, byte ptr [eax + 0x5c0a8c]
004bd5cf  e9ec000000               jmp       0x4bd6c0
004bd5d4  33c0                     xor       eax, eax
004bd5d6  66c783b60000000100       mov       word ptr [ebx + 0xb6], 1
004bd5df  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd5e5  8a88540a5c00             mov       cl, byte ptr [eax + 0x5c0a54]
004bd5eb  fec9                     dec       cl
004bd5ed  888bc1000000             mov       byte ptr [ebx + 0xc1], cl
004bd5f3  8a908c0a5c00             mov       dl, byte ptr [eax + 0x5c0a8c]
004bd5f9  feca                     dec       dl
004bd5fb  e9c0000000               jmp       0x4bd6c0
004bd600  80fa0b                   cmp       dl, 0xb
004bd603  7405                     je        0x4bd60a
004bd605  80fa0e                   cmp       dl, 0xe
004bd608  755d                     jne       0x4bd667
004bd60a  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd60d  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bd613  dfe0                     fnstsw    ax
004bd615  f6c444                   test      ah, 0x44
004bd618  7b46                     jnp       0x4bd660
004bd61a  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd61d  dc1db8035500             fcomp     qword ptr [0x5503b8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004bd623  dfe0                     fnstsw    ax
004bd625  2500010000               and       eax, 0x100
004bd62a  753b                     jne       0x4bd667
004bd62c  33c0                     xor       eax, eax
004bd62e  8a818c0a5c00             mov       al, byte ptr [ecx + 0x5c0a8c]
004bd634  8945ec                   mov       dword ptr [ebp - 0x14], eax
004bd637  db45ec                   fild      dword ptr [ebp - 0x14]
004bd63a  dd5de8                   fstp      qword ptr [ebp - 0x18]
004bd63d  8b4dec                   mov       ecx, dword ptr [ebp - 0x14]
004bd640  8b55e8                   mov       edx, dword ptr [ebp - 0x18]
004bd643  51                       push      ecx
004bd644  52                       push      edx
004bd645  6800002440               push      0x40240000
004bd64a  6a00                     push      0
004bd64c  e8c8c90200               call      0x4ea019 ; _pow
004bd651  dc5de0                   fcomp     qword ptr [ebp - 0x20]
004bd654  83c410                   add       esp, 0x10
004bd657  dfe0                     fnstsw    ax
004bd659  2500410000               and       eax, 0x4100
004bd65e  7507                     jne       0x4bd667
004bd660  c683c000000013           mov       byte ptr [ebx + 0xc0], 0x13
004bd667  8a93a1000000             mov       dl, byte ptr [ebx + 0xa1]
004bd66d  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd670  8bca                     mov       ecx, edx
004bd672  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bd678  81e1ff000000             and       ecx, 0xff
004bd67e  660fb681000a5c00         movzx     ax, byte ptr [ecx + 0x5c0a00]
004bd686  668983b6000000           mov       word ptr [ebx + 0xb6], ax
004bd68d  8a81380a5c00             mov       al, byte ptr [ecx + 0x5c0a38]
004bd693  8883c1000000             mov       byte ptr [ebx + 0xc1], al
004bd699  dfe0                     fnstsw    ax
004bd69b  f6c444                   test      ah, 0x44
004bd69e  7a1a                     jp        0x4bd6ba
004bd6a0  80fa09                   cmp       dl, 9
004bd6a3  7215                     jb        0x4bd6ba
004bd6a5  80fa0d                   cmp       dl, 0xd
004bd6a8  7710                     ja        0x4bd6ba
004bd6aa  8a89700a5c00             mov       cl, byte ptr [ecx + 0x5c0a70]
004bd6b0  fec1                     inc       cl
004bd6b2  888bc2000000             mov       byte ptr [ebx + 0xc2], cl
004bd6b8  eb0c                     jmp       0x4bd6c6
004bd6ba  8a91700a5c00             mov       dl, byte ptr [ecx + 0x5c0a70]
004bd6c0  8893c2000000             mov       byte ptr [ebx + 0xc2], dl
004bd6c6  ff93d4000000             call      dword ptr [ebx + 0xd4]
004bd6cc  8a156def5b00             mov       dl, byte ptr [0x5bef6d]
004bd6d2  8d75b0                   lea       esi, [ebp - 0x50]
004bd6d5  33c0                     xor       eax, eax
004bd6d7  8975f4                   mov       dword ptr [ebp - 0xc], esi
004bd6da  8a83c1000000             mov       al, byte ptr [ebx + 0xc1]
004bd6e0  80fa01                   cmp       dl, 1
004bd6e3  8bf8                     mov       edi, eax
004bd6e5  897df8                   mov       dword ptr [ebp - 8], edi
004bd6e8  756c                     jne       0x4bd756
004bd6ea  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd6f0  3c0a                     cmp       al, 0xa
004bd6f2  7404                     je        0x4bd6f8
004bd6f4  3c0d                     cmp       al, 0xd
004bd6f6  7525                     jne       0x4bd71d
004bd6f8  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd6fe  33c0                     xor       eax, eax
004bd700  84c9                     test      cl, cl
004bd702  7219                     jb        0x4bd71d
004bd704  807c05b045               cmp       byte ptr [ebp + eax - 0x50], 0x45
004bd709  7505                     jne       0x4bd710
004bd70b  c64405b044               mov       byte ptr [ebp + eax - 0x50], 0x44
004bd710  33c9                     xor       ecx, ecx
004bd712  40                       inc       eax
004bd713  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd719  3bc1                     cmp       eax, ecx
004bd71b  7ee7                     jle       0x4bd704
004bd71d  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd723  3c0a                     cmp       al, 0xa
004bd725  7604                     jbe       0x4bd72b
004bd727  3c0e                     cmp       al, 0xe
004bd729  7604                     jbe       0x4bd72f
004bd72b  3c11                     cmp       al, 0x11
004bd72d  7258                     jb        0x4bd787
004bd72f  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd735  b801000000               mov       eax, 1
004bd73a  3ac8                     cmp       cl, al
004bd73c  7249                     jb        0x4bd787
004bd73e  803e20                   cmp       byte ptr [esi], 0x20
004bd741  753a                     jne       0x4bd77d
004bd743  46                       inc       esi
004bd744  33c9                     xor       ecx, ecx
004bd746  8975f4                   mov       dword ptr [ebp - 0xc], esi
004bd749  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd74f  40                       inc       eax
004bd750  3bc1                     cmp       eax, ecx
004bd752  7eea                     jle       0x4bd73e
004bd754  eb31                     jmp       0x4bd787
004bd756  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd75c  b801000000               mov       eax, 1
004bd761  3ac8                     cmp       cl, al
004bd763  7222                     jb        0x4bd787
004bd765  803e20                   cmp       byte ptr [esi], 0x20
004bd768  7513                     jne       0x4bd77d
004bd76a  46                       inc       esi
004bd76b  33c9                     xor       ecx, ecx
004bd76d  8975f4                   mov       dword ptr [ebp - 0xc], esi
004bd770  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd776  40                       inc       eax
004bd777  3bc1                     cmp       eax, ecx
004bd779  7eea                     jle       0x4bd765
004bd77b  eb0a                     jmp       0x4bd787
004bd77d  8d45b0                   lea       eax, [ebp - 0x50]
004bd780  2bc6                     sub       eax, esi
004bd782  03f8                     add       edi, eax
004bd784  897df8                   mov       dword ptr [ebp - 8], edi
004bd787  33c9                     xor       ecx, ecx
004bd789  80fa01                   cmp       dl, 1
004bd78c  8a8bc1000000             mov       cl, byte ptr [ebx + 0xc1]
004bd792  8d440daf                 lea       eax, [ebp + ecx - 0x51]
004bd796  8bf0                     mov       esi, eax
004bd798  7525                     jne       0x4bd7bf
004bd79a  8a8ba1000000             mov       cl, byte ptr [ebx + 0xa1]
004bd7a0  80f90b                   cmp       cl, 0xb
004bd7a3  7205                     jb        0x4bd7aa
004bd7a5  80f90e                   cmp       cl, 0xe
004bd7a8  7605                     jbe       0x4bd7af
004bd7aa  80f912                   cmp       cl, 0x12
004bd7ad  721e                     jb        0x4bd7cd
004bd7af  803820                   cmp       byte ptr [eax], 0x20
004bd7b2  7519                     jne       0x4bd7cd
004bd7b4  8a4eff                   mov       cl, byte ptr [esi - 1]
004bd7b7  4e                       dec       esi
004bd7b8  80f920                   cmp       cl, 0x20
004bd7bb  74f7                     je        0x4bd7b4
004bd7bd  eb0e                     jmp       0x4bd7cd
004bd7bf  803820                   cmp       byte ptr [eax], 0x20
004bd7c2  7509                     jne       0x4bd7cd
004bd7c4  8a4eff                   mov       cl, byte ptr [esi - 1]
004bd7c7  4e                       dec       esi
004bd7c8  80f920                   cmp       cl, 0x20
004bd7cb  74f7                     je        0x4bd7c4
004bd7cd  8bce                     mov       ecx, esi
004bd7cf  2bc8                     sub       ecx, eax
004bd7d1  03f9                     add       edi, ecx
004bd7d3  897df8                   mov       dword ptr [ebp - 8], edi
004bd7d6  8a83a1000000             mov       al, byte ptr [ebx + 0xa1]
004bd7dc  3c0a                     cmp       al, 0xa
004bd7de  7404                     je        0x4bd7e4
004bd7e0  3c0d                     cmp       al, 0xd
004bd7e2  7562                     jne       0x4bd846
004bd7e4  dd45e0                   fld       qword ptr [ebp - 0x20]
004bd7e7  dc1d60dc5400             fcomp     qword ptr [0x54dc60] ; __real@0000000000000000, bits=0000000000000000, f64=0.0
004bd7ed  dfe0                     fnstsw    ax
004bd7ef  f6c444                   test      ah, 0x44
004bd7f2  7b52                     jnp       0x4bd846
004bd7f4  84d2                     test      dl, dl
004bd7f6  754e                     jne       0x4bd846
004bd7f8  a0a5ed5b00               mov       al, byte ptr [0x5beda5]
004bd7fd  84c0                     test      al, al
004bd7ff  7545                     jne       0x4bd846
004bd801  83bb3003000003           cmp       dword ptr [ebx + 0x330], 3
004bd808  753c                     jne       0x4bd846
004bd80a  80bbc000000009           cmp       byte ptr [ebx + 0xc0], 9
004bd811  7533                     jne       0x4bd846
004bd813  b901000000               mov       ecx, 1
004bd818  3bf9                     cmp       edi, ecx
004bd81a  7c2a                     jl        0x4bd846
004bd81c  8a06                     mov       al, byte ptr [esi]
004bd81e  3c2b                     cmp       al, 0x2b
004bd820  740c                     je        0x4bd82e
004bd822  3c2d                     cmp       al, 0x2d
004bd824  7408                     je        0x4bd82e
004bd826  41                       inc       ecx
004bd827  4e                       dec       esi
004bd828  3bcf                     cmp       ecx, edi
004bd82a  7ef0                     jle       0x4bd81c
004bd82c  eb18                     jmp       0x4bd846
004bd82e  51                       push      ecx
004bd82f  8d5601                   lea       edx, [esi + 1]
004bd832  56                       push      esi
004bd833  52                       push      edx
004bd834  e887c40200               call      0x4e9cc0 ; _memmove
004bd839  8b7df8                   mov       edi, dword ptr [ebp - 8]
004bd83c  83c40c                   add       esp, 0xc
004bd83f  47                       inc       edi
004bd840  c60645                   mov       byte ptr [esi], 0x45
004bd843  897df8                   mov       dword ptr [ebp - 8], edi
004bd846  8d45ff                   lea       eax, [ebp - 1]
004bd849  8d4dfe                   lea       ecx, [ebp - 2]
004bd84c  50                       push      eax
004bd84d  8d55f4                   lea       edx, [ebp - 0xc]
004bd850  51                       push      ecx
004bd851  8d45f8                   lea       eax, [ebp - 8]
004bd854  52                       push      edx
004bd855  47                       inc       edi
004bd856  50                       push      eax
004bd857  57                       push      edi
004bd858  e863030000               call      0x4bdbc0 ; _jwe_il_r
004bd85d  83c414                   add       esp, 0x14
004bd860  85c0                     test      eax, eax
004bd862  0f841a020000             je        0x4bda82
004bd868  8b4df8                   mov       ecx, dword ptr [ebp - 8]
004bd86b  8b75f4                   mov       esi, dword ptr [ebp - 0xc]
004bd86e  8bbb8c010000             mov       edi, dword ptr [ebx + 0x18c]
004bd874  8bd1                     mov       edx, ecx
004bd876  c1e902                   shr       ecx, 2
004bd879  f3a5                     rep movsd dword ptr es:[edi], dword ptr [esi]
004bd87b  8bca                     mov       ecx, edx
004bd87d  83e103                   and       ecx, 3
004bd880  f3a4                     rep movsb byte ptr es:[edi], byte ptr [esi]
004bd882  8b45f8                   mov       eax, dword ptr [ebp - 8]
004bd885  8b8b8c010000             mov       ecx, dword ptr [ebx + 0x18c]
004bd88b  03c8                     add       ecx, eax
004bd88d  8bc1                     mov       eax, ecx
004bd88f  898b8c010000             mov       dword ptr [ebx + 0x18c], ecx
004bd895  c60029                   mov       byte ptr [eax], 0x29
004bd898  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bd89e  40                       inc       eax
004bd89f  89838c010000             mov       dword ptr [ebx + 0x18c], eax
004bd8a5  8b8b88010000             mov       ecx, dword ptr [ebx + 0x188]
004bd8ab  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bd8b1  8bd1                     mov       edx, ecx
004bd8b3  2bd0                     sub       edx, eax
004bd8b5  83fa01                   cmp       edx, 1
004bd8b8  7d36                     jge       0x4bd8f0
004bd8ba  8b55f0                   mov       edx, dword ptr [ebp - 0x10]
004bd8bd  8a826c010000             mov       al, byte ptr [edx + 0x16c]
004bd8c3  84c0                     test      al, al
004bd8c5  7540                     jne       0x4bd907
004bd8c7  83bb2001000001           cmp       dword ptr [ebx + 0x120], 1
004bd8ce  7e37                     jle       0x4bd907
004bd8d0  6a00                     push      0
004bd8d2  6a00                     push      0
004bd8d4  898b8c010000             mov       dword ptr [ebx + 0x18c], ecx
004bd8da  e801060000               call      0x4bdee0 ; _jwe_iloc
004bd8df  83c408                   add       esp, 8
004bd8e2  85c0                     test      eax, eax
004bd8e4  0f8498010000             je        0x4bda82
004bd8ea  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bd8f0  8a8b97010000             mov       cl, byte ptr [ebx + 0x197]
004bd8f6  8808                     mov       byte ptr [eax], cl
004bd8f8  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bd8fd  84c0                     test      al, al
004bd8ff  7506                     jne       0x4bd907
004bd901  ff838c010000             inc       dword ptr [ebx + 0x18c]
004bd907  8b45f0                   mov       eax, dword ptr [ebp - 0x10]
004bd90a  8b8848010000             mov       ecx, dword ptr [eax + 0x148]
004bd910  41                       inc       ecx
004bd911  898848010000             mov       dword ptr [eax + 0x148], ecx
004bd917  8bbb20010000             mov       edi, dword ptr [ebx + 0x120]
004bd91d  8b9368010000             mov       edx, dword ptr [ebx + 0x168]
004bd923  8bb3a8000000             mov       esi, dword ptr [ebx + 0xa8]
004bd929  4f                       dec       edi
004bd92a  03f2                     add       esi, edx
004bd92c  8bc7                     mov       eax, edi
004bd92e  89bb20010000             mov       dword ptr [ebx + 0x120], edi
004bd934  85c0                     test      eax, eax
004bd936  89b3a8000000             mov       dword ptr [ebx + 0xa8], esi
004bd93c  0f8fc4f4ffff             jg        0x4bce06
004bd942  8b7508                   mov       esi, dword ptr [ebp + 8]
004bd945  8a06                     mov       al, byte ptr [esi]
004bd947  2420                     and       al, 0x20
004bd949  3c20                     cmp       al, 0x20
004bd94b  0f84dd000000             je        0x4bda2e
004bd951  8b7df0                   mov       edi, dword ptr [ebp - 0x10]
004bd954  8a876c010000             mov       al, byte ptr [edi + 0x16c]
004bd95a  84c0                     test      al, al
004bd95c  7560                     jne       0x4bd9be
004bd95e  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bd964  8b8b88010000             mov       ecx, dword ptr [ebx + 0x188]
004bd96a  3bc8                     cmp       ecx, eax
004bd96c  7750                     ja        0x4bd9be
004bd96e  8a48ff                   mov       cl, byte ptr [eax - 1]
004bd971  8a8397010000             mov       al, byte ptr [ebx + 0x197]
004bd977  3ac8                     cmp       cl, al
004bd979  7443                     je        0x4bd9be
004bd97b  6a00                     push      0
004bd97d  6a00                     push      0
004bd97f  e85c050000               call      0x4bdee0 ; _jwe_iloc
004bd984  83c408                   add       esp, 8
004bd987  85c0                     test      eax, eax
004bd989  0f84f3000000             je        0x4bda82
004bd98f  8b938c010000             mov       edx, dword ptr [ebx + 0x18c]
004bd995  8a8397010000             mov       al, byte ptr [ebx + 0x197]
004bd99b  8802                     mov       byte ptr [edx], al
004bd99d  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bd9a2  84c0                     test      al, al
004bd9a4  7518                     jne       0x4bd9be
004bd9a6  80bba100000011           cmp       byte ptr [ebx + 0xa1], 0x11
004bd9ad  7509                     jne       0x4bd9b8
004bd9af  80bfaa01000020           cmp       byte ptr [edi + 0x1aa], 0x20
004bd9b6  7406                     je        0x4bd9be
004bd9b8  ff838c010000             inc       dword ptr [ebx + 0x18c]
004bd9be  f6460204                 test      byte ptr [esi + 2], 4
004bd9c2  7505                     jne       0x4bd9c9
004bd9c4  83c60c                   add       esi, 0xc
004bd9c7  eb03                     jmp       0x4bd9cc
004bd9c9  83c610                   add       esi, 0x10
004bd9cc  8a0e                     mov       cl, byte ptr [esi]
004bd9ce  897508                   mov       dword ptr [ebp + 8], esi
004bd9d1  80e110                   and       cl, 0x10
004bd9d4  80f910                   cmp       cl, 0x10
004bd9d7  0f84e9000000             je        0x4bdac6
004bd9dd  f60610                   test      byte ptr [esi], 0x10
004bd9e0  752b                     jne       0x4bda0d
004bd9e2  807e0112                 cmp       byte ptr [esi + 1], 0x12
004bd9e6  0f858befffff             jne       0x4bc977
004bd9ec  56                       push      esi
004bd9ed  e83e890000               call      0x4c6330 ; _jwe_isdp
004bd9f2  83c404                   add       esp, 4
004bd9f5  83f801                   cmp       eax, 1
004bd9f8  0f84ca000000             je        0x4bdac8
004bd9fe  85c0                     test      eax, eax
004bda00  0f84c2000000             je        0x4bdac8
004bda06  8bf0                     mov       esi, eax
004bda08  897508                   mov       dword ptr [ebp + 8], esi
004bda0b  ebd0                     jmp       0x4bd9dd
004bda0d  56                       push      esi
004bda0e  e8ad820000               call      0x4c5cc0 ; _jwe_irpp
004bda13  83c404                   add       esp, 4
004bda16  83f801                   cmp       eax, 1
004bda19  0f84a9000000             je        0x4bdac8
004bda1f  85c0                     test      eax, eax
004bda21  0f84a1000000             je        0x4bdac8
004bda27  8bf0                     mov       esi, eax
004bda29  897508                   mov       dword ptr [ebp + 8], esi
004bda2c  ebaf                     jmp       0x4bd9dd
004bda2e  8a16                     mov       dl, byte ptr [esi]
004bda30  80e240                   and       dl, 0x40
004bda33  80fa40                   cmp       dl, 0x40
004bda36  7510                     jne       0x4bda48
004bda38  5f                       pop       edi
004bda39  c6437f04                 mov       byte ptr [ebx + 0x7f], 4
004bda3d  5e                       pop       esi
004bda3e  b801000000               mov       eax, 1
004bda43  5b                       pop       ebx
004bda44  8be5                     mov       esp, ebp
004bda46  5d                       pop       ebp
004bda47  c3                       ret
004bda48  8b75f0                   mov       esi, dword ptr [ebp - 0x10]
004bda4b  8a866c010000             mov       al, byte ptr [esi + 0x16c]
004bda51  84c0                     test      al, al
004bda53  7565                     jne       0x4bdaba
004bda55  8b838c010000             mov       eax, dword ptr [ebx + 0x18c]
004bda5b  8b8b88010000             mov       ecx, dword ptr [ebx + 0x188]
004bda61  3bc8                     cmp       ecx, eax
004bda63  7755                     ja        0x4bdaba
004bda65  8a40ff                   mov       al, byte ptr [eax - 1]
004bda68  8a8b97010000             mov       cl, byte ptr [ebx + 0x197]
004bda6e  3ac1                     cmp       al, cl
004bda70  7448                     je        0x4bdaba
004bda72  6a00                     push      0
004bda74  6a00                     push      0
004bda76  e865040000               call      0x4bdee0 ; _jwe_iloc
004bda7b  83c408                   add       esp, 8
004bda7e  85c0                     test      eax, eax
004bda80  7509                     jne       0x4bda8b
004bda82  5f                       pop       edi
004bda83  5e                       pop       esi
004bda84  33c0                     xor       eax, eax
004bda86  5b                       pop       ebx
004bda87  8be5                     mov       esp, ebp
004bda89  5d                       pop       ebp
004bda8a  c3                       ret
004bda8b  8b8b8c010000             mov       ecx, dword ptr [ebx + 0x18c]
004bda91  8a9397010000             mov       dl, byte ptr [ebx + 0x197]
004bda97  8811                     mov       byte ptr [ecx], dl
004bda99  a06def5b00               mov       al, byte ptr [0x5bef6d]
004bda9e  84c0                     test      al, al
004bdaa0  7518                     jne       0x4bdaba
004bdaa2  80bba100000011           cmp       byte ptr [ebx + 0xa1], 0x11
004bdaa9  7509                     jne       0x4bdab4
004bdaab  80beaa01000020           cmp       byte ptr [esi + 0x1aa], 0x20
004bdab2  7406                     je        0x4bdaba
004bdab4  ff838c010000             inc       dword ptr [ebx + 0x18c]
004bdaba  5f                       pop       edi
004bdabb  5e                       pop       esi
004bdabc  b801000000               mov       eax, 1
004bdac1  5b                       pop       ebx
004bdac2  8be5                     mov       esp, ebp
004bdac4  5d                       pop       ebp
004bdac5  c3                       ret
004bdac6  8bc6                     mov       eax, esi
004bdac8  5f                       pop       edi
004bdac9  5e                       pop       esi
004bdaca  5b                       pop       ebx
004bdacb  8be5                     mov       esp, ebp
004bdacd  5d                       pop       ebp
004bdace  c3                       ret
004bdacf  90                       nop
004bdad0  3dce4b0071               cmp       eax, 0x71004bce
004bdad5  cf                       iretd
004bdad6  4b                       dec       ebx
004bdad7  00afcf4b003d             add       byte ptr [edi + 0x3d004bcf], ch
004bdadd  ce                       into
004bdade  4b                       dec       ebx
004bdadf  0071cf                   add       byte ptr [ecx - 0x31], dh
004bdae2  4b                       dec       ebx
004bdae3  00afcf4b0010             add       byte ptr [edi + 0x10004bcf], ch
004bdae9  d44b                     aam       0x4b
004bdaeb  0044d54b                 add       byte ptr [ebp + edx*8 + 0x4b], al
004bdaef  0082d54b0010             add       byte ptr [edx + 0x10004bd5], al
004bdaf5  d44b                     aam       0x4b
004bdaf7  0044d54b                 add       byte ptr [ebp + edx*8 + 0x4b], al
