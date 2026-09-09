; _fndrit_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x71710
00471710  55                       push      ebp
00471711  8bec                     mov       ebp, esp
00471713  b810000000               mov       eax, 0x10
00471718  e8e3780700               call      0x4e9000 ; __alloca_probe
0047171d  53                       push      ebx
0047171e  56                       push      esi
0047171f  57                       push      edi
00471720  8b4508                   mov       eax, dword ptr [ebp + 8]
00471723  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00471726  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00471729  8945f0                   mov       dword ptr [ebp - 0x10], eax
0047172c  8b01                     mov       eax, dword ptr [ecx]
0047172e  8905544db600             mov       dword ptr [0xb64d54], eax
00471734  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00471737  8b00                     mov       eax, dword ptr [eax]
00471739  8905584db600             mov       dword ptr [0xb64d58], eax
0047173f  8b02                     mov       eax, dword ptr [edx]
00471741  89055c4db600             mov       dword ptr [0xb64d5c], eax
00471747  8b45f0                   mov       eax, dword ptr [ebp - 0x10]
0047174a  8b30                     mov       esi, dword ptr [eax]
0047174c  8935604db600             mov       dword ptr [0xb64d60], esi
00471752  68404db600               push      0xb64d40 ; _ritcom_
00471757  8d1de0e95900             lea       ebx, [0x59e9e0] ; bits=4f4d4d41, f32=12.831374168395996
0047175d  8d73cc                   lea       esi, [ebx - 0x34]
00471760  56                       push      esi
00471761  8d73d0                   lea       esi, [ebx - 0x30]
00471764  56                       push      esi
00471765  8d73d4                   lea       esi, [ebx - 0x2c]
00471768  56                       push      esi
00471769  8d73c8                   lea       esi, [ebx - 0x38]
0047176c  56                       push      esi
0047176d  8b7518                   mov       esi, dword ptr [ebp + 0x18]
00471770  8d3e                     lea       edi, [esi]
00471772  57                       push      edi
00471773  8d3a                     lea       edi, [edx]
00471775  57                       push      edi
00471776  8d39                     lea       edi, [ecx]
00471778  57                       push      edi
00471779  e8325e0000               call      0x4775b0 ; _xlookw_
0047177e  83c420                   add       esp, 0x20
00471781  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00471784  d943c8                   fld       dword ptr [ebx - 0x38]
00471787  d838                     fdivr     dword ptr [eax]
00471789  d91d444db600             fstp      dword ptr [0xb64d44]
0047178f  d906                     fld       dword ptr [esi]
00471791  d94380                   fld       dword ptr [ebx - 0x80]
00471794  d80e                     fmul      dword ptr [esi]
00471796  d95bd8                   fstp      dword ptr [ebx - 0x28]
00471799  d95bdc                   fstp      dword ptr [ebx - 0x24]
0047179c  8d43c4                   lea       eax, [ebx - 0x3c]
0047179f  50                       push      eax
004717a0  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004717a3  8d00                     lea       eax, [eax]
004717a5  50                       push      eax
004717a6  8d43dc                   lea       eax, [ebx - 0x24]
004717a9  50                       push      eax
004717aa  8d43d8                   lea       eax, [ebx - 0x28]
004717ad  50                       push      eax
004717ae  6860164700               push      0x471660 ; _frit_
004717b3  6868f70e04               push      0x40ef768
004717b8  686cf70e04               push      0x40ef76c
004717bd  e82e0b0000               call      0x4722f0 ; _regfal_
004717c2  83c41c                   add       esp, 0x1c
004717c5  837bc401                 cmp       dword ptr [ebx - 0x3c], 1
004717c9  7c34                     jl        0x4717ff
004717cb  8b45f0                   mov       eax, dword ptr [ebp - 0x10]
004717ce  8b08                     mov       ecx, dword ptr [eax]
004717d0  8b43d8                   mov       eax, dword ptr [ebx - 0x28]
004717d3  8b53dc                   mov       edx, dword ptr [ebx - 0x24]
004717d6  8d738c                   lea       esi, [ebx - 0x74]
004717d9  894dfc                   mov       dword ptr [ebp - 4], ecx
004717dc  8d4dfc                   lea       ecx, [ebp - 4]
004717df  894e08                   mov       dword ptr [esi + 8], ecx
004717e2  8945f8                   mov       dword ptr [ebp - 8], eax
004717e5  8d45f8                   lea       eax, [ebp - 8]
004717e8  894628                   mov       dword ptr [esi + 0x28], eax
004717eb  8955f4                   mov       dword ptr [ebp - 0xc], edx
004717ee  8d45f4                   lea       eax, [ebp - 0xc]
004717f1  894634                   mov       dword ptr [esi + 0x34], eax
004717f4  56                       push      esi
004717f5  e8f60d0300               call      0x4a25f0 ; _jwe_isfm
004717fa  83c404                   add       esp, 4
004717fd  eb0b                     jmp       0x47180a
004717ff  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00471802  8b0d504db600             mov       ecx, dword ptr [0xb64d50]
00471808  8908                     mov       dword ptr [eax], ecx
0047180a  b800000000               mov       eax, 0
0047180f  5f                       pop       edi
00471810  5e                       pop       esi
00471811  5b                       pop       ebx
00471812  8be5                     mov       esp, ebp
00471814  5d                       pop       ebp
00471815  c3                       ret
00471816  8d4900                   lea       ecx, [ecx]
00471819  8da42400000000           lea       esp, [esp]
