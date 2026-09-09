; _embsub_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x2fa10
0042fa10  55                       push      ebp
0042fa11  8bec                     mov       ebp, esp
0042fa13  b808000000               mov       eax, 8
0042fa18  e8e3950b00               call      0x4e9000 ; __alloca_probe
0042fa1d  53                       push      ebx
0042fa1e  56                       push      esi
0042fa1f  57                       push      edi
0042fa20  8b5508                   mov       edx, dword ptr [ebp + 8]
0042fa23  8b450c                   mov       eax, dword ptr [ebp + 0xc]
0042fa26  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
0042fa29  8945fc                   mov       dword ptr [ebp - 4], eax
0042fa2c  8b12                     mov       edx, dword ptr [edx]
0042fa2e  83fa01                   cmp       edx, 1
0042fa31  752c                     jne       0x42fa5f
0042fa33  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0042fa36  8d74d0f8                 lea       esi, [eax + edx*8 - 8]
0042fa3a  8d3d28cf5600             lea       edi, [0x56cf28] ; bits=50415645, f32=3428.08203125
0042fa40  b908000000               mov       ecx, 8
0042fa45  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0042fa47  750b                     jne       0x42fa54
0042fa49  d90520b2e900             fld       dword ptr [0xe9b220] ; _subcom_
0042fa4f  e9a0000000               jmp       0x42faf4
0042fa54  d90524b2e900             fld       dword ptr [0xe9b224]
0042fa5a  e995000000               jmp       0x42faf4
0042fa5f  8b03                     mov       eax, dword ptr [ebx]
0042fa61  39c2                     cmp       edx, eax
0042fa63  7526                     jne       0x42fa8b
0042fa65  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0042fa68  8d74d0f0                 lea       esi, [eax + edx*8 - 0x10]
0042fa6c  8d3d28cf5600             lea       edi, [0x56cf28] ; bits=50415645, f32=3428.08203125
0042fa72  b908000000               mov       ecx, 8
0042fa77  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0042fa79  7508                     jne       0x42fa83
0042fa7b  d90520b2e900             fld       dword ptr [0xe9b220] ; _subcom_
0042fa81  eb71                     jmp       0x42faf4
0042fa83  d90524b2e900             fld       dword ptr [0xe9b224]
0042fa89  eb69                     jmp       0x42faf4
0042fa8b  89d0                     mov       eax, edx
0042fa8d  c1e003                   shl       eax, 3
0042fa90  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
0042fa93  8d7401f8                 lea       esi, [ecx + eax - 8]
0042fa97  8d3d28cf5600             lea       edi, [0x56cf28] ; bits=50415645, f32=3428.08203125
0042fa9d  b908000000               mov       ecx, 8
0042faa2  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0042faa4  8945f8                   mov       dword ptr [ebp - 8], eax
0042faa7  7508                     jne       0x42fab1
0042faa9  d90520b2e900             fld       dword ptr [0xe9b220] ; _subcom_
0042faaf  eb06                     jmp       0x42fab7
0042fab1  d90524b2e900             fld       dword ptr [0xe9b224]
0042fab7  8b4df8                   mov       ecx, dword ptr [ebp - 8]
0042faba  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0042fabd  8d7408f0                 lea       esi, [eax + ecx - 0x10]
0042fac1  8d3d28cf5600             lea       edi, [0x56cf28] ; bits=50415645, f32=3428.08203125
0042fac7  b908000000               mov       ecx, 8
0042facc  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0042face  750a                     jne       0x42fada
0042fad0  d90520b2e900             fld       dword ptr [0xe9b220] ; _subcom_
0042fad6  d9c9                     fxch      st(1)
0042fad8  eb08                     jmp       0x42fae2
0042fada  d90524b2e900             fld       dword ptr [0xe9b224]
0042fae0  d9c9                     fxch      st(1)
0042fae2  d8d1                     fcom      st(1)
0042fae4  d9c9                     fxch      st(1)
0042fae6  dfe0                     fnstsw    ax
0042fae8  66a90041                 test      ax, 0x4100
0042faec  7504                     jne       0x42faf2
0042faee  ddd9                     fstp      st(1)
0042faf0  eb02                     jmp       0x42faf4
0042faf2  ddd8                     fstp      st(0)
0042faf4  8b03                     mov       eax, dword ptr [ebx]
0042faf6  39c2                     cmp       edx, eax
0042faf8  7507                     jne       0x42fb01
0042fafa  89d0                     mov       eax, edx
0042fafc  48                       dec       eax
0042fafd  89c2                     mov       edx, eax
0042faff  eb00                     jmp       0x42fb01
0042fb01  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0042fb04  d94490fc                 fld       dword ptr [eax + edx*4 - 4]
0042fb08  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
0042fb0b  d94491fc                 fld       dword ptr [ecx + edx*4 - 4]
0042fb0f  d85490fc                 fcom      dword ptr [eax + edx*4 - 4]
0042fb13  d9c9                     fxch      st(1)
0042fb15  dfe0                     fnstsw    ax
0042fb17  66a90041                 test      ax, 0x4100
0042fb1b  7404                     je        0x42fb21
0042fb1d  ddd9                     fstp      st(1)
0042fb1f  eb02                     jmp       0x42fb23
0042fb21  ddd8                     fstp      st(0)
0042fb23  d9c1                     fld       st(1)
0042fb25  d8c9                     fmul      st(1)
0042fb27  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0042fb2a  d918                     fstp      dword ptr [eax]
0042fb2c  dec9                     fmulp     st(1)
0042fb2e  8b4d20                   mov       ecx, dword ptr [ebp + 0x20]
0042fb31  d901                     fld       dword ptr [ecx]
0042fb33  dee1                     fsubrp    st(1)
0042fb35  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0042fb38  dd19                     fstp      qword ptr [ecx]
0042fb3a  8b4dfc                   mov       ecx, dword ptr [ebp - 4]
0042fb3d  d901                     fld       dword ptr [ecx]
0042fb3f  d800                     fadd      dword ptr [eax]
0042fb41  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
0042fb44  d918                     fstp      dword ptr [eax]
0042fb46  b800000000               mov       eax, 0
0042fb4b  5f                       pop       edi
0042fb4c  5e                       pop       esi
0042fb4d  5b                       pop       ebx
0042fb4e  8be5                     mov       esp, ebp
0042fb50  5d                       pop       ebp
0042fb51  c3                       ret
0042fb52  8da42400000000           lea       esp, [esp]
0042fb59  8da42400000000           lea       esp, [esp]
