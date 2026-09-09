; _critq_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x112e0
004112e0  55                       push      ebp
004112e1  8bec                     mov       ebp, esp
004112e3  b8b4000000               mov       eax, 0xb4
004112e8  e8137d0d00               call      0x4e9000 ; __alloca_probe
004112ed  53                       push      ebx
004112ee  56                       push      esi
004112ef  57                       push      edi
004112f0  8b4508                   mov       eax, dword ptr [ebp + 8]
004112f3  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
004112f6  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
004112f9  8945a4                   mov       dword ptr [ebp - 0x5c], eax
004112fc  894da0                   mov       dword ptr [ebp - 0x60], ecx
004112ff  8d1508a25500             lea       edx, [0x55a208] ; bits=00000000, f32=0.0
00411305  8d35389b5500             lea       esi, [0x559b38] ; bits=20202020, f32=1.3563156426940112e-19
0041130b  b90f000000               mov       ecx, 0xf
00411310  89d7                     mov       edi, edx
00411312  66f3a5                   rep movsw word ptr es:[edi], word ptr [esi]
00411315  6a50                     push      0x50
00411317  6868a15500               push      0x55a168
0041131c  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
0041131f  8d08                     lea       ecx, [eax]
00411321  51                       push      ecx
00411322  8d0b                     lea       ecx, [ebx]
00411324  51                       push      ecx
00411325  e8b6b50300               call      0x44c8e0 ; _inline_
0041132a  83c410                   add       esp, 0x10
0041132d  6a32                     push      0x32
0041132f  6a10                     push      0x10
00411331  6a50                     push      0x50
00411333  68f8a05500               push      0x55a0f8
00411338  68cca05500               push      0x55a0cc
0041133d  68d8a15500               push      0x55a1d8
00411342  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00411345  89459c                   mov       dword ptr [ebp - 0x64], eax
00411348  8d08                     lea       ecx, [eax]
0041134a  51                       push      ecx
0041134b  6868a15500               push      0x55a168
00411350  8b4da0                   mov       ecx, dword ptr [ebp - 0x60]
00411353  8d31                     lea       esi, [ecx]
00411355  56                       push      esi
00411356  e885910400               call      0x45a4e0 ; _read_tabid_plus_
0041135b  83c424                   add       esp, 0x24
0041135e  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
00411361  8b30                     mov       esi, dword ptr [eax]
00411363  6a10                     push      0x10
00411365  68d8a15500               push      0x55a1d8
0041136a  e8e1e60300               call      0x44fa50 ; _lenstr_
0041136f  83c408                   add       esp, 8
00411372  89c7                     mov       edi, eax
00411374  c1ff1f                   sar       edi, 0x1f
00411377  f7d7                     not       edi
00411379  21f8                     and       eax, edi
0041137b  8b3dcca05500             mov       edi, dword ptr [0x55a0cc] ; bits=00000000, f32=0.0
00411381  8d0d64a05500             lea       ecx, [0x55a064] ; bits=09020000, f32=7.300764999132297e-43
00411387  8975fc                   mov       dword ptr [ebp - 4], esi
0041138a  8d75fc                   lea       esi, [ebp - 4]
0041138d  897108                   mov       dword ptr [ecx + 8], esi
00411390  894124                   mov       dword ptr [ecx + 0x24], eax
00411393  897df8                   mov       dword ptr [ebp - 8], edi
00411396  8d45f8                   lea       eax, [ebp - 8]
00411399  894134                   mov       dword ptr [ecx + 0x34], eax
0041139c  51                       push      ecx
0041139d  e84e120900               call      0x4a25f0 ; _jwe_isfm
004113a2  83c404                   add       esp, 4
004113a5  6a08                     push      8
004113a7  6a08                     push      8
004113a9  6a08                     push      8
004113ab  6a08                     push      8
004113ad  6a32                     push      0x32
004113af  68f0a05500               push      0x55a0f0
004113b4  68b8a15500               push      0x55a1b8
004113b9  68c8a15500               push      0x55a1c8
004113be  68d0a15500               push      0x55a1d0
004113c3  68f8a05500               push      0x55a0f8
004113c8  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
004113cb  8d08                     lea       ecx, [eax]
004113cd  51                       push      ecx
004113ce  e89d370800               call      0x494b70 ; _setopt_
004113d3  83c42c                   add       esp, 0x2c
004113d6  833cbdec5a0e0400         cmp       dword ptr [edi*4 + 0x40e5aec], 0
004113de  7415                     je        0x4113f5
004113e0  6a10                     push      0x10
004113e2  8b459c                   mov       eax, dword ptr [ebp - 0x64]
004113e5  8d08                     lea       ecx, [eax]
004113e7  51                       push      ecx
004113e8  68d8a15500               push      0x55a1d8
004113ed  e85e950400               call      0x45a950 ; _tab_in_use_
004113f2  83c40c                   add       esp, 0xc
004113f5  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004113f8  894598                   mov       dword ptr [ebp - 0x68], eax
004113fb  8d08                     lea       ecx, [eax]
004113fd  51                       push      ecx
004113fe  8b4da0                   mov       ecx, dword ptr [ebp - 0x60]
00411401  8d11                     lea       edx, [ecx]
00411403  52                       push      edx
00411404  8d13                     lea       edx, [ebx]
00411406  52                       push      edx
00411407  e874be0400               call      0x45d280 ; _get_lctn_items_
0041140c  83c40c                   add       esp, 0xc
0041140f  6a08                     push      8
00411411  6a08                     push      8
00411413  6a08                     push      8
00411415  6a08                     push      8
00411417  6a08                     push      8
00411419  68b0a05500               push      0x55a0b0
0041141e  68a8a05500               push      0x55a0a8
00411423  6848a25500               push      0x55a248
00411428  6840a25500               push      0x55a240
0041142d  6838a25500               push      0x55a238
00411432  6830a25500               push      0x55a230
00411437  6828a25500               push      0x55a228
0041143c  e85fbd0400               call      0x45d1a0 ; _set_lctn_items_
00411441  83c430                   add       esp, 0x30
00411444  6a50                     push      0x50
00411446  6868a15500               push      0x55a168
0041144b  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
0041144e  8d08                     lea       ecx, [eax]
00411450  51                       push      ecx
00411451  8d0b                     lea       ecx, [ebx]
00411453  51                       push      ecx
00411454  e887b40300               call      0x44c8e0 ; _inline_
00411459  83c410                   add       esp, 0x10
0041145c  6a10                     push      0x10
0041145e  6a06                     push      6
00411460  6a50                     push      0x50
00411462  68b8a05500               push      0x55a0b8
00411467  68e8a15500               push      0x55a1e8
0041146c  8b4598                   mov       eax, dword ptr [ebp - 0x68]
0041146f  8d08                     lea       ecx, [eax]
00411471  51                       push      ecx
00411472  68589b5500               push      0x559b58
00411477  6868a15500               push      0x55a168
0041147c  8b4da0                   mov       ecx, dword ptr [ebp - 0x60]
0041147f  8d11                     lea       edx, [ecx]
00411481  52                       push      edx
00411482  e8a9920400               call      0x45a730 ; _read_tabid_
00411487  83c424                   add       esp, 0x24
0041148a  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
0041148d  8b08                     mov       ecx, dword ptr [eax]
0041148f  894d94                   mov       dword ptr [ebp - 0x6c], ecx
00411492  8d152ca05500             lea       edx, [0x55a02c] ; bits=09020000, f32=7.300764999132297e-43
00411498  894dfc                   mov       dword ptr [ebp - 4], ecx
0041149b  8d75fc                   lea       esi, [ebp - 4]
0041149e  897208                   mov       dword ptr [edx + 8], esi
004114a1  52                       push      edx
004114a2  e849110900               call      0x4a25f0 ; _jwe_isfm
004114a7  83c404                   add       esp, 4
004114aa  8b05b8a05500             mov       eax, dword ptr [0x55a0b8] ; bits=00000000, f32=0.0
004114b0  833c85ec5a0e0400         cmp       dword ptr [eax*4 + 0x40e5aec], 0
004114b8  7f24                     jg        0x4114de
004114ba  8d0500a05500             lea       eax, [0x55a000] ; bits=09020000, f32=7.300764999132297e-43
004114c0  8b4d94                   mov       ecx, dword ptr [ebp - 0x6c]
004114c3  894dfc                   mov       dword ptr [ebp - 4], ecx
004114c6  8d4dfc                   lea       ecx, [ebp - 4]
004114c9  894808                   mov       dword ptr [eax + 8], ecx
004114cc  50                       push      eax
004114cd  e81e110900               call      0x4a25f0 ; _jwe_isfm
004114d2  83c404                   add       esp, 4
004114d5  8b4598                   mov       eax, dword ptr [ebp - 0x68]
004114d8  c70001000000             mov       dword ptr [eax], 1
004114de  6a50                     push      0x50
004114e0  6868a15500               push      0x55a168
004114e5  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
004114e8  8d08                     lea       ecx, [eax]
004114ea  51                       push      ecx
004114eb  8d0b                     lea       ecx, [ebx]
004114ed  51                       push      ecx
004114ee  e8edb30300               call      0x44c8e0 ; _inline_
004114f3  83c410                   add       esp, 0x10
004114f6  6a10                     push      0x10
004114f8  6a06                     push      6
004114fa  6a50                     push      0x50
004114fc  68c0a05500               push      0x55a0c0
00411501  68f8a15500               push      0x55a1f8
00411506  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00411509  894590                   mov       dword ptr [ebp - 0x70], eax
0041150c  8d08                     lea       ecx, [eax]
0041150e  51                       push      ecx
0041150f  68609b5500               push      0x559b60
00411514  6868a15500               push      0x55a168
00411519  8b4da0                   mov       ecx, dword ptr [ebp - 0x60]
0041151c  8d11                     lea       edx, [ecx]
0041151e  52                       push      edx
0041151f  e80c920400               call      0x45a730 ; _read_tabid_
00411524  83c424                   add       esp, 0x24
00411527  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
0041152a  8b08                     mov       ecx, dword ptr [eax]
0041152c  894d8c                   mov       dword ptr [ebp - 0x74], ecx
0041152f  8d15c89f5500             lea       edx, [0x559fc8] ; bits=09020000, f32=7.300764999132297e-43
00411535  894dfc                   mov       dword ptr [ebp - 4], ecx
00411538  8d75fc                   lea       esi, [ebp - 4]
0041153b  897208                   mov       dword ptr [edx + 8], esi
0041153e  52                       push      edx
0041153f  e8ac100900               call      0x4a25f0 ; _jwe_isfm
00411544  83c404                   add       esp, 4
00411547  8b05c0a05500             mov       eax, dword ptr [0x55a0c0] ; bits=00000000, f32=0.0
0041154d  833c85ec5a0e0400         cmp       dword ptr [eax*4 + 0x40e5aec], 0
00411555  7524                     jne       0x41157b
00411557  8d059c9f5500             lea       eax, [0x559f9c] ; bits=09020000, f32=7.300764999132297e-43
0041155d  8b4d8c                   mov       ecx, dword ptr [ebp - 0x74]
00411560  894dfc                   mov       dword ptr [ebp - 4], ecx
00411563  8d4dfc                   lea       ecx, [ebp - 4]
00411566  894808                   mov       dword ptr [eax + 8], ecx
00411569  50                       push      eax
0041156a  e881100900               call      0x4a25f0 ; _jwe_isfm
0041156f  83c404                   add       esp, 4
00411572  8b4590                   mov       eax, dword ptr [ebp - 0x70]
00411575  c70001000000             mov       dword ptr [eax], 1
0041157b  6a50                     push      0x50
0041157d  6868a15500               push      0x55a168
00411582  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
00411585  8d08                     lea       ecx, [eax]
00411587  51                       push      ecx
00411588  8d0b                     lea       ecx, [ebx]
0041158a  51                       push      ecx
0041158b  e850b30300               call      0x44c8e0 ; _inline_
00411590  83c410                   add       esp, 0x10
00411593  687c9f5500               push      0x559f7c
00411598  e8b3050900               call      0x4a1b50 ; _jwe_iinf
0041159d  83c404                   add       esp, 4
004115a0  85c0                     test      eax, eax
004115a2  0f856c080000             jne       0x411e14
004115a8  68649f5500               push      0x559f64
004115ad  e89e050900               call      0x4a1b50 ; _jwe_iinf
004115b2  83c404                   add       esp, 4
004115b5  85c0                     test      eax, eax
004115b7  0f8557080000             jne       0x411e14
004115bd  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
004115c0  8b08                     mov       ecx, dword ptr [eax]
004115c2  894d88                   mov       dword ptr [ebp - 0x78], ecx
004115c5  8b15d8a05500             mov       edx, dword ptr [0x55a0d8] ; bits=00000000, f32=0.0
004115cb  8d352c9f5500             lea       esi, [0x559f2c] ; bits=09020000, f32=7.300764999132297e-43
004115d1  894dfc                   mov       dword ptr [ebp - 4], ecx
004115d4  8d7dfc                   lea       edi, [ebp - 4]
004115d7  897e08                   mov       dword ptr [esi + 8], edi
004115da  8955f4                   mov       dword ptr [ebp - 0xc], edx
004115dd  8d55f4                   lea       edx, [ebp - 0xc]
004115e0  895634                   mov       dword ptr [esi + 0x34], edx
004115e3  56                       push      esi
004115e4  e807100900               call      0x4a25f0 ; _jwe_isfm
004115e9  83c404                   add       esp, 4
004115ec  d905d8a05500             fld       dword ptr [0x55a0d8] ; bits=00000000, f32=0.0
004115f2  d815f8995500             fcom      dword ptr [0x5599f8] ; bits=0000803f, f32=1.0
004115f8  dfe0                     fnstsw    ax
004115fa  9e                       sahf
004115fb  0f8a02000000             jp        0x411603
00411601  7717                     ja        0x41161a
00411603  d81df0995500             fcomp     dword ptr [0x5599f0] ; bits=00000000, f32=0.0
00411609  dfe0                     fnstsw    ax
0041160b  9e                       sahf
0041160c  0f8a2e000000             jp        0x411640
00411612  0f8728000000             ja        0x411640
00411618  eb02                     jmp       0x41161c
0041161a  ddd8                     fstp      st(0)
0041161c  8d050c9f5500             lea       eax, [0x559f0c] ; bits=69020000, f32=8.646011524884121e-43
00411622  8b4d88                   mov       ecx, dword ptr [ebp - 0x78]
00411625  894dfc                   mov       dword ptr [ebp - 4], ecx
00411628  8d4dfc                   lea       ecx, [ebp - 4]
0041162b  894808                   mov       dword ptr [eax + 8], ecx
0041162e  50                       push      eax
0041162f  e8bc0f0900               call      0x4a25f0 ; _jwe_isfm
00411634  83c404                   add       esp, 4
00411637  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0041163a  c70001000000             mov       dword ptr [eax], 1
00411640  6a50                     push      0x50
00411642  6868a15500               push      0x55a168
00411647  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
0041164a  8d08                     lea       ecx, [eax]
0041164c  51                       push      ecx
0041164d  8d0b                     lea       ecx, [ebx]
0041164f  51                       push      ecx
00411650  e88bb20300               call      0x44c8e0 ; _inline_
00411655  83c410                   add       esp, 0x10
00411658  68ec9e5500               push      0x559eec
0041165d  e8ee040900               call      0x4a1b50 ; _jwe_iinf
00411662  83c404                   add       esp, 4
00411665  85c0                     test      eax, eax
00411667  0f85a7070000             jne       0x411e14
0041166d  68e09e5500               push      0x559ee0
00411672  e8d9040900               call      0x4a1b50 ; _jwe_iinf
00411677  83c404                   add       esp, 4
0041167a  85c0                     test      eax, eax
0041167c  0f8592070000             jne       0x411e14
00411682  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
00411685  8b18                     mov       ebx, dword ptr [eax]
00411687  8d0db49e5500             lea       ecx, [0x559eb4] ; bits=09020000, f32=7.300764999132297e-43
0041168d  895dfc                   mov       dword ptr [ebp - 4], ebx
00411690  8d55fc                   lea       edx, [ebp - 4]
00411693  895108                   mov       dword ptr [ecx + 8], edx
00411696  51                       push      ecx
00411697  e8540f0900               call      0x4a25f0 ; _jwe_isfm
0041169c  83c404                   add       esp, 4
0041169f  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004116a2  833800                   cmp       dword ptr [eax], 0
004116a5  0f8fab070000             jg        0x411e56
004116ab  8b05b8a05500             mov       eax, dword ptr [0x55a0b8] ; bits=00000000, f32=0.0
004116b1  8b0c85ec5a0e04           mov       ecx, dword ptr [eax*4 + 0x40e5aec]
004116b8  890db8a05500             mov       dword ptr [0x55a0b8], ecx ; bits=00000000, f32=0.0
004116be  8b05c0a05500             mov       eax, dword ptr [0x55a0c0] ; bits=00000000, f32=0.0
004116c4  8b0c85ec5a0e04           mov       ecx, dword ptr [eax*4 + 0x40e5aec]
004116cb  890dc0a05500             mov       dword ptr [0x55a0c0], ecx ; bits=00000000, f32=0.0
004116d1  8b05b8a05500             mov       eax, dword ptr [0x55a0b8] ; bits=00000000, f32=0.0
004116d7  8b0c85c8e5f400           mov       ecx, dword ptr [eax*4 + 0xf4e5c8]
004116de  890dbca05500             mov       dword ptr [0x55a0bc], ecx ; bits=00000000, f32=0.0
004116e4  8b05c0a05500             mov       eax, dword ptr [0x55a0c0] ; bits=00000000, f32=0.0
004116ea  8b0c85c8e5f400           mov       ecx, dword ptr [eax*4 + 0xf4e5c8]
004116f1  833dbca0550014           cmp       dword ptr [0x55a0bc], 0x14 ; bits=00000000, f32=0.0
004116f8  894d84                   mov       dword ptr [ebp - 0x7c], ecx
004116fb  7c09                     jl        0x411706
004116fd  833dbca0550019           cmp       dword ptr [0x55a0bc], 0x19 ; bits=00000000, f32=0.0
00411704  7e21                     jle       0x411727
00411706  8d05949e5500             lea       eax, [0x559e94] ; bits=69020000, f32=8.646011524884121e-43
0041170c  895dfc                   mov       dword ptr [ebp - 4], ebx
0041170f  8d4dfc                   lea       ecx, [ebp - 4]
00411712  894808                   mov       dword ptr [eax + 8], ecx
00411715  50                       push      eax
00411716  e8d50e0900               call      0x4a25f0 ; _jwe_isfm
0041171b  83c404                   add       esp, 4
0041171e  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00411721  c70001000000             mov       dword ptr [eax], 1
00411727  837d8414                 cmp       dword ptr [ebp - 0x7c], 0x14
0041172b  7c06                     jl        0x411733
0041172d  837d8419                 cmp       dword ptr [ebp - 0x7c], 0x19
00411731  7e21                     jle       0x411754
00411733  8d05749e5500             lea       eax, [0x559e74] ; bits=69020000, f32=8.646011524884121e-43
00411739  895dfc                   mov       dword ptr [ebp - 4], ebx
0041173c  8d4dfc                   lea       ecx, [ebp - 4]
0041173f  894808                   mov       dword ptr [eax + 8], ecx
00411742  50                       push      eax
00411743  e8a80e0900               call      0x4a25f0 ; _jwe_isfm
00411748  83c404                   add       esp, 4
0041174b  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0041174e  c70001000000             mov       dword ptr [eax], 1
00411754  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00411757  833800                   cmp       dword ptr [eax], 0
0041175a  894580                   mov       dword ptr [ebp - 0x80], eax
0041175d  0f8ff3060000             jg        0x411e56
00411763  6a10                     push      0x10
00411765  68f8a15500               push      0x55a1f8
0041176a  e8e1e20300               call      0x44fa50 ; _lenstr_
0041176f  83c408                   add       esp, 8
00411772  89c2                     mov       edx, eax
00411774  c1fa1f                   sar       edx, 0x1f
00411777  f7d2                     not       edx
00411779  21d0                     and       eax, edx
0041177b  8d0d489e5500             lea       ecx, [0x559e48] ; bits=09020000, f32=7.300764999132297e-43
00411781  895dfc                   mov       dword ptr [ebp - 4], ebx
00411784  8d55fc                   lea       edx, [ebp - 4]
00411787  895108                   mov       dword ptr [ecx + 8], edx
0041178a  894124                   mov       dword ptr [ecx + 0x24], eax
0041178d  51                       push      ecx
0041178e  e85d0e0900               call      0x4a25f0 ; _jwe_isfm
00411793  83c404                   add       esp, 4
00411796  68d0a05500               push      0x55a0d0
0041179b  68c0a05500               push      0x55a0c0
004117a0  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
004117a3  8d08                     lea       ecx, [eax]
004117a5  51                       push      ecx
004117a6  8b4da4                   mov       ecx, dword ptr [ebp - 0x5c]
004117a9  8d11                     lea       edx, [ecx]
004117ab  52                       push      edx
004117ac  e84f610200               call      0x437900 ; _chkcfc_
004117b1  83c410                   add       esp, 0x10
004117b4  8b05b8a05500             mov       eax, dword ptr [0x55a0b8] ; bits=00000000, f32=0.0
004117ba  d90485d4e5f400           fld       dword ptr [eax*4 + 0xf4e5d4]
004117c1  db7dcc                   fstp      xword ptr [ebp - 0x34]
004117c4  8b05c0a05500             mov       eax, dword ptr [0x55a0c0] ; bits=00000000, f32=0.0
004117ca  d90485d4e5f400           fld       dword ptr [eax*4 + 0xf4e5d4]
004117d1  db7dc0                   fstp      xword ptr [ebp - 0x40]
004117d4  db6dcc                   fld       xword ptr [ebp - 0x34]
004117d7  db6dc0                   fld       xword ptr [ebp - 0x40]
004117da  d9c9                     fxch      st(1)
004117dc  ded9                     fcompp
004117de  dfe0                     fnstsw    ax
004117e0  9e                       sahf
004117e1  0f8a28000000             jp        0x41180f
004117e7  7626                     jbe       0x41180f
004117e9  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
004117ec  8b08                     mov       ecx, dword ptr [eax]
004117ee  8d15289e5500             lea       edx, [0x559e28] ; bits=69020000, f32=8.646011524884121e-43
004117f4  894dfc                   mov       dword ptr [ebp - 4], ecx
004117f7  8d4dfc                   lea       ecx, [ebp - 4]
004117fa  894a08                   mov       dword ptr [edx + 8], ecx
004117fd  52                       push      edx
004117fe  e8ed0d0900               call      0x4a25f0 ; _jwe_isfm
00411803  83c404                   add       esp, 4
00411806  8b4580                   mov       eax, dword ptr [ebp - 0x80]
00411809  c70001000000             mov       dword ptr [eax], 1
0041180f  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00411812  833800                   cmp       dword ptr [eax], 0
00411815  0f8f3b060000             jg        0x411e56
0041181b  c705c4e7630000000000     mov       dword ptr [0x63e7c4], 0
00411825  8d05a8d86300             lea       eax, [0x63d8a8]
0041182b  c7408000000000           mov       dword ptr [eax - 0x80], 0
00411832  db6dc0                   fld       xword ptr [ebp - 0x40]
00411835  db6dcc                   fld       xword ptr [ebp - 0x34]
00411838  d9c9                     fxch      st(1)
0041183a  ded9                     fcompp
0041183c  89857cffffff             mov       dword ptr [ebp - 0x84], eax
00411842  dfe0                     fnstsw    ax
00411844  9e                       sahf
00411845  0f8a29000000             jp        0x411874
0041184b  7627                     jbe       0x411874
0041184d  c705c8a0550002000000     mov       dword ptr [0x55a0c8], 2 ; bits=00000000, f32=0.0
00411857  db6dc0                   fld       xword ptr [ebp - 0x40]
0041185a  db6dcc                   fld       xword ptr [ebp - 0x34]
0041185d  dee9                     fsubp     st(1)
0041185f  d91dc8e76300             fstp      dword ptr [0x63e7c8]
00411865  8b857cffffff             mov       eax, dword ptr [ebp - 0x84]
0041186b  c7408400000000           mov       dword ptr [eax - 0x7c], 0
00411872  eb0a                     jmp       0x41187e
00411874  c705c8a0550001000000     mov       dword ptr [0x55a0c8], 1 ; bits=00000000, f32=0.0
0041187e  8b4584                   mov       eax, dword ptr [ebp - 0x7c]
00411881  8b0c85445b5700           mov       ecx, dword ptr [eax*4 + 0x575b44]
00411888  8b55a0                   mov       edx, dword ptr [ebp - 0x60]
0041188b  8d7120                   lea       esi, [ecx + 0x20]
0041188e  8b3a                     mov       edi, dword ptr [edx]
00411890  8d05089e5500             lea       eax, [0x559e08] ; bits=69020000, f32=8.646011524884121e-43
00411896  897dfc                   mov       dword ptr [ebp - 4], edi
00411899  898d78ffffff             mov       dword ptr [ebp - 0x88], ecx
0041189f  8d4dfc                   lea       ecx, [ebp - 4]
004118a2  894808                   mov       dword ptr [eax + 8], ecx
004118a5  50                       push      eax
004118a6  e8450d0900               call      0x4a25f0 ; _jwe_isfm
004118ab  83c404                   add       esp, 4
004118ae  db6dc0                   fld       xword ptr [ebp - 0x40]
004118b1  db6dcc                   fld       xword ptr [ebp - 0x34]
004118b4  dec1                     faddp     st(1)
004118b6  db6dcc                   fld       xword ptr [ebp - 0x34]
004118b9  dee9                     fsubp     st(1)
004118bb  db6dc0                   fld       xword ptr [ebp - 0x40]
004118be  db6dcc                   fld       xword ptr [ebp - 0x34]
004118c1  dee9                     fsubp     st(1)
004118c3  8d05ac9d5500             lea       eax, [0x559dac] ; bits=09020000, f32=7.300764999132297e-43
004118c9  897dfc                   mov       dword ptr [ebp - 4], edi
004118cc  8d4dfc                   lea       ecx, [ebp - 4]
004118cf  894808                   mov       dword ptr [eax + 8], ecx
004118d2  d9c9                     fxch      st(1)
004118d4  d95df4                   fstp      dword ptr [ebp - 0xc]
004118d7  8d4df4                   lea       ecx, [ebp - 0xc]
004118da  894828                   mov       dword ptr [eax + 0x28], ecx
004118dd  d95df0                   fstp      dword ptr [ebp - 0x10]
004118e0  8d4df0                   lea       ecx, [ebp - 0x10]
004118e3  894834                   mov       dword ptr [eax + 0x34], ecx
004118e6  db6dc0                   fld       xword ptr [ebp - 0x40]
004118e9  d95dec                   fstp      dword ptr [ebp - 0x14]
004118ec  8d4dec                   lea       ecx, [ebp - 0x14]
004118ef  894840                   mov       dword ptr [eax + 0x40], ecx
004118f2  50                       push      eax
004118f3  e8f80c0900               call      0x4a25f0 ; _jwe_isfm
004118f8  83c404                   add       esp, 4
004118fb  8b4584                   mov       eax, dword ptr [ebp - 0x7c]
004118fe  8b0c8500a25500           mov       ecx, dword ptr [eax*4 + 0x55a200]
00411905  d905d8a05500             fld       dword ptr [0x55a0d8] ; bits=00000000, f32=0.0
0041190b  d80dd8a05500             fmul      dword ptr [0x55a0d8] ; bits=00000000, f32=0.0
00411911  db7db4                   fstp      xword ptr [ebp - 0x4c]
00411914  0335c0a05500             add       esi, dword ptr [0x55a0c0] ; bits=00000000, f32=0.0
0041191a  89f3                     mov       ebx, esi
0041191c  8b05c8a05500             mov       eax, dword ptr [0x55a0c8] ; bits=00000000, f32=0.0
00411922  8b5518                   mov       edx, dword ptr [ebp + 0x18]
00411925  898574ffffff             mov       dword ptr [ebp - 0x8c], eax
0041192b  898d70ffffff             mov       dword ptr [ebp - 0x90], ecx
00411931  89956cffffff             mov       dword ptr [ebp - 0x94], edx
00411937  d9049dc0e5f400           fld       dword ptr [ebx*4 + 0xf4e5c0]
0041193e  d9049dc4e5f400           fld       dword ptr [ebx*4 + 0xf4e5c4]
00411945  d9049dc8e5f400           fld       dword ptr [ebx*4 + 0xf4e5c8]
0041194c  d9ca                     fxch      st(2)
0041194e  83bd70ffffff01           cmp       dword ptr [ebp - 0x90], 1
00411955  7521                     jne       0x411978
00411957  8b45a4                   mov       eax, dword ptr [ebp - 0x5c]
0041195a  d9c2                     fld       st(2)
0041195c  d808                     fmul      dword ptr [eax]
0041195e  def2                     fdivrp    st(2)
00411960  d9c9                     fxch      st(1)
00411962  d9fa                     fsqrt
00411964  d95df4                   fstp      dword ptr [ebp - 0xc]
00411967  d9c1                     fld       st(1)
00411969  d84df4                   fmul      dword ptr [ebp - 0xc]
0041196c  d91de0a05500             fstp      dword ptr [0x55a0e0] ; bits=00000000, f32=0.0
00411972  d9e8                     fld1
00411974  d9c9                     fxch      st(1)
00411976  eb18                     jmp       0x411990
00411978  ddd9                     fstp      st(1)
0041197a  8b049ddce5f400           mov       eax, dword ptr [ebx*4 + 0xf4e5dc]
00411981  8905e0a05500             mov       dword ptr [0x55a0e0], eax ; bits=00000000, f32=0.0
00411987  d9049dd8e5f400           fld       dword ptr [ebx*4 + 0xf4e5d8]
0041198e  d9c9                     fxch      st(1)
00411990  db7dd8                   fstp      xword ptr [ebp - 0x28]
00411993  db6dc0                   fld       xword ptr [ebp - 0x40]
00411996  db6dd8                   fld       xword ptr [ebp - 0x28]
00411999  dec1                     faddp     st(1)
0041199b  db7da8                   fstp      xword ptr [ebp - 0x58]
0041199e  d80dfc995500             fmul      dword ptr [0x5599fc] ; bits=0000003f, f32=0.5
004119a4  d905e0a05500             fld       dword ptr [0x55a0e0] ; bits=00000000, f32=0.0
004119aa  d80de0a05500             fmul      dword ptr [0x55a0e0] ; bits=00000000, f32=0.0
004119b0  dec9                     fmulp     st(1)
004119b2  d9c9                     fxch      st(1)
004119b4  8b45a4                   mov       eax, dword ptr [ebp - 0x5c]
004119b7  d8c8                     fmul      st(0)
004119b9  d808                     fmul      dword ptr [eax]
004119bb  db6db4                   fld       xword ptr [ebp - 0x4c]
004119be  dec9                     fmulp     st(1)
004119c0  def9                     fdivp     st(1)
004119c2  db6da8                   fld       xword ptr [ebp - 0x58]
004119c5  dec1                     faddp     st(1)
004119c7  db6dcc                   fld       xword ptr [ebp - 0x34]
004119ca  dee9                     fsubp     st(1)
004119cc  d91ddca05500             fstp      dword ptr [0x55a0dc] ; bits=00000000, f32=0.0
004119d2  db6da8                   fld       xword ptr [ebp - 0x58]
004119d5  db6dcc                   fld       xword ptr [ebp - 0x34]
004119d8  dee9                     fsubp     st(1)
004119da  8b8d6cffffff             mov       ecx, dword ptr [ebp - 0x94]
004119e0  d91de4a05500             fstp      dword ptr [0x55a0e4] ; bits=00000000, f32=0.0
004119e6  8d11                     lea       edx, [ecx]
004119e8  52                       push      edx
004119e9  68e4a05500               push      0x55a0e4
004119ee  68dca05500               push      0x55a0dc
004119f3  68e0a05500               push      0x55a0e0
004119f8  68bca05500               push      0x55a0bc
004119fd  68b8a05500               push      0x55a0b8
00411a02  8b55a0                   mov       edx, dword ptr [ebp - 0x60]
00411a05  8d32                     lea       esi, [edx]
00411a07  56                       push      esi
00411a08  8d30                     lea       esi, [eax]
00411a0a  56                       push      esi
00411a0b  e8c0f7ffff               call      0x4111d0 ; _invtse_
00411a10  83c420                   add       esp, 0x20
00411a13  8b8574ffffff             mov       eax, dword ptr [ebp - 0x8c]
00411a19  40                       inc       eax
00411a1a  8b0de4a05500             mov       ecx, dword ptr [0x55a0e4] ; bits=00000000, f32=0.0
00411a20  890c85c0e76300           mov       dword ptr [eax*4 + 0x63e7c0], ecx
00411a27  8d15a8d86300             lea       edx, [0x63d8a8]
00411a2d  8b35e0a05500             mov       esi, dword ptr [0x55a0e0] ; bits=00000000, f32=0.0
00411a33  89b4827cffffff           mov       dword ptr [edx + eax*4 - 0x84], esi
00411a3a  8b55a0                   mov       edx, dword ptr [ebp - 0x60]
00411a3d  8b3a                     mov       edi, dword ptr [edx]
00411a3f  db6dcc                   fld       xword ptr [ebp - 0x34]
00411a42  d805e4a05500             fadd      dword ptr [0x55a0e4] ; bits=00000000, f32=0.0
00411a48  898d68ffffff             mov       dword ptr [ebp - 0x98], ecx
00411a4e  8d0d509d5500             lea       ecx, [0x559d50] ; bits=09020000, f32=7.300764999132297e-43
00411a54  897dfc                   mov       dword ptr [ebp - 4], edi
00411a57  898574ffffff             mov       dword ptr [ebp - 0x8c], eax
00411a5d  8d45fc                   lea       eax, [ebp - 4]
00411a60  894108                   mov       dword ptr [ecx + 8], eax
00411a63  d95df4                   fstp      dword ptr [ebp - 0xc]
00411a66  8d45f4                   lea       eax, [ebp - 0xc]
00411a69  894128                   mov       dword ptr [ecx + 0x28], eax
00411a6c  8b8568ffffff             mov       eax, dword ptr [ebp - 0x98]
00411a72  8945f0                   mov       dword ptr [ebp - 0x10], eax
00411a75  8d45f0                   lea       eax, [ebp - 0x10]
00411a78  894134                   mov       dword ptr [ecx + 0x34], eax
00411a7b  db6da8                   fld       xword ptr [ebp - 0x58]
00411a7e  d95dec                   fstp      dword ptr [ebp - 0x14]
00411a81  8d45ec                   lea       eax, [ebp - 0x14]
00411a84  894140                   mov       dword ptr [ecx + 0x40], eax
00411a87  db6dd8                   fld       xword ptr [ebp - 0x28]
00411a8a  d95de8                   fstp      dword ptr [ebp - 0x18]
00411a8d  8d45e8                   lea       eax, [ebp - 0x18]
00411a90  89414c                   mov       dword ptr [ecx + 0x4c], eax
00411a93  8975e4                   mov       dword ptr [ebp - 0x1c], esi
00411a96  8d45e4                   lea       eax, [ebp - 0x1c]
00411a99  894158                   mov       dword ptr [ecx + 0x58], eax
00411a9c  51                       push      ecx
00411a9d  e84e0b0900               call      0x4a25f0 ; _jwe_isfm
00411aa2  83c404                   add       esp, 4
00411aa5  039d78ffffff             add       ebx, dword ptr [ebp - 0x88]
00411aab  8b05c0a05500             mov       eax, dword ptr [0x55a0c0] ; bits=00000000, f32=0.0
00411ab1  8b0c85c0e5f400           mov       ecx, dword ptr [eax*4 + 0xf4e5c0]
00411ab8  39cb                     cmp       ebx, ecx
00411aba  89bd64ffffff             mov       dword ptr [ebp - 0x9c], edi
00411ac0  0f8e71feffff             jle       0x411937
00411ac6  8b8574ffffff             mov       eax, dword ptr [ebp - 0x8c]
00411acc  8905c8a05500             mov       dword ptr [0x55a0c8], eax ; bits=00000000, f32=0.0
00411ad2  8d15d0a15500             lea       edx, [0x55a1d0] ; bits=00000000, f32=0.0
00411ad8  8d1dec9a5500             lea       ebx, [0x559aec] ; bits=53415645, f32=3428.082763671875
00411ade  b904000000               mov       ecx, 4
00411ae3  89d6                     mov       esi, edx
00411ae5  89df                     mov       edi, ebx
00411ae7  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00411ae9  0f85ba000000             jne       0x411ba9
00411aef  8b05c8a05500             mov       eax, dword ptr [0x55a0c8] ; bits=00000000, f32=0.0
00411af5  83c002                   add       eax, 2
00411af8  89c2                     mov       edx, eax
00411afa  01d0                     add       eax, edx
00411afc  83c016                   add       eax, 0x16
00411aff  89c2                     mov       edx, eax
00411b01  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00411b04  8b18                     mov       ebx, dword ptr [eax]
00411b06  01da                     add       edx, ebx
00411b08  81fa415dc600             cmp       edx, 0xc65d41
00411b0e  7e37                     jle       0x411b47
00411b10  89d0                     mov       eax, edx
00411b12  2d415dc600               sub       eax, 0xc65d41
00411b17  8d0d249d5500             lea       ecx, [0x559d24] ; bits=09020000, f32=7.300764999132297e-43
00411b1d  8bb564ffffff             mov       esi, dword ptr [ebp - 0x9c]
00411b23  8975fc                   mov       dword ptr [ebp - 4], esi
00411b26  8d7dfc                   lea       edi, [ebp - 4]
00411b29  897908                   mov       dword ptr [ecx + 8], edi
00411b2c  8945f8                   mov       dword ptr [ebp - 8], eax
00411b2f  8d45f8                   lea       eax, [ebp - 8]
00411b32  894128                   mov       dword ptr [ecx + 0x28], eax
00411b35  51                       push      ecx
00411b36  e8b50a0900               call      0x4a25f0 ; _jwe_isfm
00411b3b  83c404                   add       esp, 4
00411b3e  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00411b41  c70001000000             mov       dword ptr [eax], 1
00411b47  8b05cca05500             mov       eax, dword ptr [0x55a0cc] ; bits=00000000, f32=0.0
00411b4d  891c85ec5a0e04           mov       dword ptr [eax*4 + 0x40e5aec], ebx
00411b54  89049dc4e5f400           mov       dword ptr [ebx*4 + 0xf4e5c4], eax
00411b5b  c7049dc8e5f40002000000   mov       dword ptr [ebx*4 + 0xf4e5c8], 2
00411b66  8d4316                   lea       eax, [ebx + 0x16]
00411b69  89049dcce5f400           mov       dword ptr [ebx*4 + 0xf4e5cc], eax
00411b70  c7049dd0e5f40000000000   mov       dword ptr [ebx*4 + 0xf4e5d0], 0
00411b7b  c7049dd4e5f4000000803f   mov       dword ptr [ebx*4 + 0xf4e5d4], 0x3f800000
00411b86  c7049d08e6f40000000000   mov       dword ptr [ebx*4 + 0xf4e608], 0
00411b91  c7049d0ce6f40000000000   mov       dword ptr [ebx*4 + 0xf4e60c], 0
00411b9c  8b049dcce5f400           mov       eax, dword ptr [ebx*4 + 0xf4e5cc]
00411ba3  8905c4a05500             mov       dword ptr [0x55a0c4], eax ; bits=00000000, f32=0.0
00411ba9  6a10                     push      0x10
00411bab  68d8a15500               push      0x55a1d8
00411bb0  e89bde0300               call      0x44fa50 ; _lenstr_
00411bb5  83c408                   add       esp, 8
00411bb8  89c2                     mov       edx, eax
00411bba  c1fa1f                   sar       edx, 0x1f
00411bbd  f7d2                     not       edx
00411bbf  21d0                     and       eax, edx
00411bc1  8d0df89c5500             lea       ecx, [0x559cf8] ; bits=09020000, f32=7.300764999132297e-43
00411bc7  8b9564ffffff             mov       edx, dword ptr [ebp - 0x9c]
00411bcd  8955fc                   mov       dword ptr [ebp - 4], edx
00411bd0  8d55fc                   lea       edx, [ebp - 4]
00411bd3  895108                   mov       dword ptr [ecx + 8], edx
00411bd6  894124                   mov       dword ptr [ecx + 0x24], eax
00411bd9  51                       push      ecx
00411bda  e8110a0900               call      0x4a25f0 ; _jwe_isfm
00411bdf  83c404                   add       esp, 4
00411be2  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
00411be5  8b18                     mov       ebx, dword ptr [eax]
00411be7  8d0dd89c5500             lea       ecx, [0x559cd8] ; bits=69020000, f32=8.646011524884121e-43
00411bed  895dfc                   mov       dword ptr [ebp - 4], ebx
00411bf0  8d55fc                   lea       edx, [ebp - 4]
00411bf3  895108                   mov       dword ptr [ecx + 8], edx
00411bf6  51                       push      ecx
00411bf7  e8f4090900               call      0x4a25f0 ; _jwe_isfm
00411bfc  83c404                   add       esp, 4
00411bff  8d05b89c5500             lea       eax, [0x559cb8] ; bits=69020000, f32=8.646011524884121e-43
00411c05  895dfc                   mov       dword ptr [ebp - 4], ebx
00411c08  8d4dfc                   lea       ecx, [ebp - 4]
00411c0b  894808                   mov       dword ptr [eax + 8], ecx
00411c0e  50                       push      eax
00411c0f  e8dc090900               call      0x4a25f0 ; _jwe_isfm
00411c14  83c404                   add       esp, 4
00411c17  8d058c9c5500             lea       eax, [0x559c8c] ; bits=09020000, f32=7.300764999132297e-43
00411c1d  895dfc                   mov       dword ptr [ebp - 4], ebx
00411c20  8d4dfc                   lea       ecx, [ebp - 4]
00411c23  894808                   mov       dword ptr [eax + 8], ecx
00411c26  50                       push      eax
00411c27  e8c4090900               call      0x4a25f0 ; _jwe_isfm
00411c2c  83c404                   add       esp, 4
00411c2f  8d05549c5500             lea       eax, [0x559c54] ; bits=09020000, f32=7.300764999132297e-43
00411c35  895dfc                   mov       dword ptr [ebp - 4], ebx
00411c38  8d4dfc                   lea       ecx, [ebp - 4]
00411c3b  894808                   mov       dword ptr [eax + 8], ecx
00411c3e  50                       push      eax
00411c3f  e8ac090900               call      0x4a25f0 ; _jwe_isfm
00411c44  83c404                   add       esp, 4
00411c47  db6dc0                   fld       xword ptr [ebp - 0x40]
00411c4a  db6dcc                   fld       xword ptr [ebp - 0x34]
00411c4d  d9c9                     fxch      st(1)
00411c4f  ded9                     fcompp
00411c51  dfe0                     fnstsw    ax
00411c53  9e                       sahf
00411c54  0f8a2b000000             jp        0x411c85
00411c5a  7629                     jbe       0x411c85
00411c5c  db6dc0                   fld       xword ptr [ebp - 0x40]
00411c5f  db6dcc                   fld       xword ptr [ebp - 0x34]
00411c62  dee9                     fsubp     st(1)
00411c64  8d051c9c5500             lea       eax, [0x559c1c] ; bits=09020000, f32=7.300764999132297e-43
00411c6a  895dfc                   mov       dword ptr [ebp - 4], ebx
00411c6d  8d4dfc                   lea       ecx, [ebp - 4]
00411c70  894808                   mov       dword ptr [eax + 8], ecx
00411c73  d95df4                   fstp      dword ptr [ebp - 0xc]
00411c76  8d4df4                   lea       ecx, [ebp - 0xc]
00411c79  894828                   mov       dword ptr [eax + 0x28], ecx
00411c7c  50                       push      eax
00411c7d  e86e090900               call      0x4a25f0 ; _jwe_isfm
00411c82  83c404                   add       esp, 4
00411c85  8b05c8a05500             mov       eax, dword ptr [0x55a0c8] ; bits=00000000, f32=0.0
00411c8b  3d00000000               cmp       eax, 0
00411c90  898560ffffff             mov       dword ptr [ebp - 0xa0], eax
00411c96  0f8ec4000000             jle       0x411d60
00411c9c  b801000000               mov       eax, 1
00411ca1  89d9                     mov       ecx, ebx
00411ca3  8b1dc4a05500             mov       ebx, dword ptr [0x55a0c4] ; bits=00000000, f32=0.0
00411ca9  89855cffffff             mov       dword ptr [ebp - 0xa4], eax
00411caf  898d58ffffff             mov       dword ptr [ebp - 0xa8], ecx
00411cb5  8b855cffffff             mov       eax, dword ptr [ebp - 0xa4]
00411cbb  8b0c85c0e76300           mov       ecx, dword ptr [eax*4 + 0x63e7c0]
00411cc2  8d35e49b5500             lea       esi, [0x559be4] ; bits=09020000, f32=7.300764999132297e-43
00411cc8  8bbd58ffffff             mov       edi, dword ptr [ebp - 0xa8]
00411cce  897dfc                   mov       dword ptr [ebp - 4], edi
00411cd1  8d45fc                   lea       eax, [ebp - 4]
00411cd4  898d54ffffff             mov       dword ptr [ebp - 0xac], ecx
00411cda  8b8d5cffffff             mov       ecx, dword ptr [ebp - 0xa4]
00411ce0  56                       push      esi
00411ce1  8b348d24d86300           mov       esi, dword ptr [ecx*4 + 0x63d824]
00411ce8  5f                       pop       edi
00411ce9  894708                   mov       dword ptr [edi + 8], eax
00411cec  8b8554ffffff             mov       eax, dword ptr [ebp - 0xac]
00411cf2  8945f4                   mov       dword ptr [ebp - 0xc], eax
00411cf5  8d4df4                   lea       ecx, [ebp - 0xc]
00411cf8  894f28                   mov       dword ptr [edi + 0x28], ecx
00411cfb  8975f0                   mov       dword ptr [ebp - 0x10], esi
00411cfe  8d4df0                   lea       ecx, [ebp - 0x10]
00411d01  894f34                   mov       dword ptr [edi + 0x34], ecx
00411d04  57                       push      edi
00411d05  e8e6080900               call      0x4a25f0 ; _jwe_isfm
00411d0a  83c404                   add       esp, 4
00411d0d  b904000000               mov       ecx, 4
00411d12  8d15d0a15500             lea       edx, [0x55a1d0] ; bits=00000000, f32=0.0
00411d18  8d3dec9a5500             lea       edi, [0x559aec] ; bits=53415645, f32=3428.082763671875
00411d1e  89b54cffffff             mov       dword ptr [ebp - 0xb4], esi
00411d24  89d6                     mov       esi, edx
00411d26  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00411d28  751d                     jne       0x411d47
00411d2a  8b8554ffffff             mov       eax, dword ptr [ebp - 0xac]
00411d30  89049dc0e5f400           mov       dword ptr [ebx*4 + 0xf4e5c0], eax
00411d37  8b854cffffff             mov       eax, dword ptr [ebp - 0xb4]
00411d3d  89049dc4e5f400           mov       dword ptr [ebx*4 + 0xf4e5c4], eax
00411d44  83c302                   add       ebx, 2
00411d47  ff855cffffff             inc       dword ptr [ebp - 0xa4]
00411d4d  83ad60ffffff01           sub       dword ptr [ebp - 0xa0], 1
00411d54  0f855bffffff             jne       0x411cb5
00411d5a  891dc4a05500             mov       dword ptr [0x55a0c4], ebx ; bits=00000000, f32=0.0
00411d60  c705d4a0550002000000     mov       dword ptr [0x55a0d4], 2 ; bits=00000000, f32=0.0
00411d6a  d9e8                     fld1
00411d6c  d91de8a05500             fstp      dword ptr [0x55a0e8] ; bits=00000000, f32=0.0
00411d72  6a08                     push      8
00411d74  6a08                     push      8
00411d76  6a08                     push      8
00411d78  6a08                     push      8
00411d7a  6a08                     push      8
00411d7c  6a32                     push      0x32
00411d7e  6a1e                     push      0x1e
00411d80  68b0a05500               push      0x55a0b0
00411d85  68a8a05500               push      0x55a0a8
00411d8a  6848a25500               push      0x55a248
00411d8f  6840a25500               push      0x55a240
00411d94  6838a25500               push      0x55a238
00411d99  6830a25500               push      0x55a230
00411d9e  6828a25500               push      0x55a228
00411da3  8d0528d86300             lea       eax, [0x63d828]
00411da9  50                       push      eax
00411daa  50                       push      eax
00411dab  68c4e76300               push      0x63e7c4
00411db0  6830a15500               push      0x55a130
00411db5  6808a25500               push      0x55a208
00411dba  68e8a05500               push      0x55a0e8
00411dbf  68d4a05500               push      0x55a0d4
00411dc4  68cca05500               push      0x55a0cc
00411dc9  68c8a05500               push      0x55a0c8
00411dce  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00411dd1  8d00                     lea       eax, [eax]
00411dd3  50                       push      eax
00411dd4  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
00411dd7  8d08                     lea       ecx, [eax]
00411dd9  51                       push      ecx
00411dda  e861b30500               call      0x46d140 ; _output_type_234_
00411ddf  83c464                   add       esp, 0x64
00411de2  8d15d0a15500             lea       edx, [0x55a1d0] ; bits=00000000, f32=0.0
00411de8  8d1dec9a5500             lea       ebx, [0x559aec] ; bits=53415645, f32=3428.082763671875
00411dee  b904000000               mov       ecx, 4
00411df3  89d6                     mov       esi, edx
00411df5  89df                     mov       edi, ebx
00411df7  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00411df9  755b                     jne       0x411e56
00411dfb  8b05c4a05500             mov       eax, dword ptr [0x55a0c4] ; bits=00000000, f32=0.0
00411e01  8d48fe                   lea       ecx, [eax - 2]
00411e04  8b551c                   mov       edx, dword ptr [ebp + 0x1c]
00411e07  8b1a                     mov       ebx, dword ptr [edx]
00411e09  890c9dc0e5f400           mov       dword ptr [ebx*4 + 0xf4e5c0], ecx
00411e10  8902                     mov       dword ptr [edx], eax
00411e12  eb42                     jmp       0x411e56
00411e14  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
00411e17  8b18                     mov       ebx, dword ptr [eax]
00411e19  8d05b89b5500             lea       eax, [0x559bb8] ; bits=09820000, f32=4.664782457890884e-41
00411e1f  895dfc                   mov       dword ptr [ebp - 4], ebx
00411e22  8d4dfc                   lea       ecx, [ebp - 4]
00411e25  894808                   mov       dword ptr [eax + 8], ecx
00411e28  50                       push      eax
00411e29  e852100900               call      0x4a2e80 ; _jwe_ilst
00411e2e  83c404                   add       esp, 4
00411e31  8d058c9b5500             lea       eax, [0x559b8c] ; bits=09820000, f32=4.664782457890884e-41
00411e37  895dfc                   mov       dword ptr [ebp - 4], ebx
00411e3a  8d4dfc                   lea       ecx, [ebp - 4]
00411e3d  894808                   mov       dword ptr [eax + 8], ecx
00411e40  50                       push      eax
00411e41  e83a100900               call      0x4a2e80 ; _jwe_ilst
00411e46  83c404                   add       esp, 4
00411e49  68689b5500               push      0x559b68
00411e4e  e8ed150900               call      0x4a3440 ; _jwe_xstp
00411e53  83c404                   add       esp, 4
00411e56  b800000000               mov       eax, 0
00411e5b  5f                       pop       edi
00411e5c  5e                       pop       esi
00411e5d  5b                       pop       ebx
00411e5e  8be5                     mov       esp, ebp
00411e60  5d                       pop       ebp
00411e61  c3                       ret
00411e62  8da42400000000           lea       esp, [esp]
00411e69  8da42400000000           lea       esp, [esp]
