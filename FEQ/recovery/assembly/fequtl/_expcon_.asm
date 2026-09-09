; _expcon_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x35670
00435670  55                       push      ebp
00435671  8bec                     mov       ebp, esp
00435673  b828010000               mov       eax, 0x128
00435678  e883390b00               call      0x4e9000 ; __alloca_probe
0043567d  53                       push      ebx
0043567e  56                       push      esi
0043567f  57                       push      edi
00435680  8b4508                   mov       eax, dword ptr [ebp + 8]
00435683  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00435686  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00435689  898548ffffff             mov       dword ptr [ebp - 0xb8], eax
0043568f  898d44ffffff             mov       dword ptr [ebp - 0xbc], ecx
00435695  899540ffffff             mov       dword ptr [ebp - 0xc0], edx
0043569b  c7057c0e57000e000000     mov       dword ptr [0x570e7c], 0xe ; bits=00000000, f32=0.0
004356a5  8d05f80f5700             lea       eax, [0x570ff8] ; bits=00000000, f32=0.0
004356ab  c60052                   mov       byte ptr [eax], 0x52
004356ae  c6400149                 mov       byte ptr [eax + 1], 0x49
004356b2  c6400247                 mov       byte ptr [eax + 2], 0x47
004356b6  c6400348                 mov       byte ptr [eax + 3], 0x48
004356ba  c6400454                 mov       byte ptr [eax + 4], 0x54
004356be  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004356c1  89853cffffff             mov       dword ptr [ebp - 0xc4], eax
004356c7  8d08                     lea       ecx, [eax]
004356c9  51                       push      ecx
004356ca  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
004356d0  8d31                     lea       esi, [ecx]
004356d2  56                       push      esi
004356d3  8bb548ffffff             mov       esi, dword ptr [ebp - 0xb8]
004356d9  8d3e                     lea       edi, [esi]
004356db  57                       push      edi
004356dc  e89f7b0200               call      0x45d280 ; _get_lctn_items_
004356e1  83c40c                   add       esp, 0xc
004356e4  6a08                     push      8
004356e6  6a08                     push      8
004356e8  6a08                     push      8
004356ea  6a08                     push      8
004356ec  6a08                     push      8
004356ee  68480e5700               push      0x570e48
004356f3  68400e5700               push      0x570e40
004356f8  6870105700               push      0x571070
004356fd  6868105700               push      0x571068
00435702  6860105700               push      0x571060
00435707  6858105700               push      0x571058
0043570c  6850105700               push      0x571050
00435711  e88a7a0200               call      0x45d1a0 ; _set_lctn_items_
00435716  83c430                   add       esp, 0x30
00435719  6a50                     push      0x50
0043571b  68a80f5700               push      0x570fa8
00435720  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435726  8d08                     lea       ecx, [eax]
00435728  51                       push      ecx
00435729  8d0e                     lea       ecx, [esi]
0043572b  51                       push      ecx
0043572c  e8af710100               call      0x44c8e0 ; _inline_
00435731  83c410                   add       esp, 0x10
00435734  68100e5700               push      0x570e10
00435739  e812c40600               call      0x4a1b50 ; _jwe_iinf
0043573e  83c404                   add       esp, 4
00435741  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435747  8b08                     mov       ecx, dword ptr [eax]
00435749  8d3de40d5700             lea       edi, [0x570de4] ; bits=09020000, f32=7.300764999132297e-43
0043574f  894dfc                   mov       dword ptr [ebp - 4], ecx
00435752  8d4dfc                   lea       ecx, [ebp - 4]
00435755  894f08                   mov       dword ptr [edi + 8], ecx
00435758  57                       push      edi
00435759  e892ce0600               call      0x4a25f0 ; _jwe_isfm
0043575e  83c404                   add       esp, 4
00435761  6a50                     push      0x50
00435763  68a80f5700               push      0x570fa8
00435768  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
0043576e  8d08                     lea       ecx, [eax]
00435770  51                       push      ecx
00435771  8d0e                     lea       ecx, [esi]
00435773  51                       push      ecx
00435774  e867710100               call      0x44c8e0 ; _inline_
00435779  83c410                   add       esp, 0x10
0043577c  68b80d5700               push      0x570db8
00435781  e8cac30600               call      0x4a1b50 ; _jwe_iinf
00435786  83c404                   add       esp, 4
00435789  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
0043578f  8b08                     mov       ecx, dword ptr [eax]
00435791  8d3d8c0d5700             lea       edi, [0x570d8c] ; bits=09020000, f32=7.300764999132297e-43
00435797  894dfc                   mov       dword ptr [ebp - 4], ecx
0043579a  8d4dfc                   lea       ecx, [ebp - 4]
0043579d  894f08                   mov       dword ptr [edi + 8], ecx
004357a0  57                       push      edi
004357a1  e84ace0600               call      0x4a25f0 ; _jwe_isfm
004357a6  83c404                   add       esp, 4
004357a9  6a05                     push      5
004357ab  6a50                     push      0x50
004357ad  680c115700               push      0x57110c
004357b2  68f8105700               push      0x5710f8
004357b7  68940e5700               push      0x570e94
004357bc  68f80f5700               push      0x570ff8
004357c1  8d0560015700             lea       eax, [0x570160] ; bits=64000000, f32=1.401298464324817e-43
004357c7  898538ffffff             mov       dword ptr [ebp - 0xc8], eax
004357cd  8d4870                   lea       ecx, [eax + 0x70]
004357d0  51                       push      ecx
004357d1  68e80e5700               push      0x570ee8
004357d6  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
004357dc  8d39                     lea       edi, [ecx]
004357de  57                       push      edi
004357df  e8fc940100               call      0x44ece0 ; _get_item_limits_
004357e4  83c424                   add       esp, 0x24
004357e7  8b0510115700             mov       eax, dword ptr [0x571110] ; bits=00000000, f32=0.0
004357ed  2b05fc105700             sub       eax, dword ptr [0x5710fc] ; bits=00000000, f32=0.0
004357f3  40                       inc       eax
004357f4  89c3                     mov       ebx, eax
004357f6  6a50                     push      0x50
004357f8  68a80f5700               push      0x570fa8
004357fd  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435803  8d08                     lea       ecx, [eax]
00435805  51                       push      ecx
00435806  8d0e                     lea       ecx, [esi]
00435808  51                       push      ecx
00435809  e8d2700100               call      0x44c8e0 ; _inline_
0043580e  83c410                   add       esp, 0x10
00435811  c705900e570000000000     mov       dword ptr [0x570e90], 0 ; bits=00000000, f32=0.0
0043581b  6a04                     push      4
0043581d  6a50                     push      0x50
0043581f  68c40e5700               push      0x570ec4
00435824  68bc0e5700               push      0x570ebc
00435829  68880e5700               push      0x570e88
0043582e  68dc0e5700               push      0x570edc
00435833  68900e5700               push      0x570e90
00435838  8b853cffffff             mov       eax, dword ptr [ebp - 0xc4]
0043583e  8d08                     lea       ecx, [eax]
00435840  51                       push      ecx
00435841  680c115700               push      0x57110c
00435846  68f8105700               push      0x5710f8
0043584b  68940e5700               push      0x570e94
00435850  68a80f5700               push      0x570fa8
00435855  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
0043585b  8d39                     lea       edi, [ecx]
0043585d  57                       push      edi
0043585e  e83df9ffff               call      0x4351a0 ; _read_expcon_items1_
00435863  83c434                   add       esp, 0x34
00435866  68880e5700               push      0x570e88
0043586b  6a10                     push      0x10
0043586d  6878105700               push      0x571078
00435872  e8191b0400               call      0x477390 ; _get_tabid_
00435877  83c40c                   add       esp, 0xc
0043587a  8d0500105700             lea       eax, [0x571000] ; bits=00000000, f32=0.0
00435880  8d0d78105700             lea       ecx, [0x571078] ; bits=00000000, f32=0.0
00435886  50                       push      eax
00435887  8a01                     mov       al, byte ptr [ecx]
00435889  5f                       pop       edi
0043588a  8807                     mov       byte ptr [edi], al
0043588c  8a4101                   mov       al, byte ptr [ecx + 1]
0043588f  884701                   mov       byte ptr [edi + 1], al
00435892  8a4102                   mov       al, byte ptr [ecx + 2]
00435895  884702                   mov       byte ptr [edi + 2], al
00435898  8a4103                   mov       al, byte ptr [ecx + 3]
0043589b  884703                   mov       byte ptr [edi + 3], al
0043589e  8a4104                   mov       al, byte ptr [ecx + 4]
004358a1  884704                   mov       byte ptr [edi + 4], al
004358a4  8a4105                   mov       al, byte ptr [ecx + 5]
004358a7  884705                   mov       byte ptr [edi + 5], al
004358aa  8a4106                   mov       al, byte ptr [ecx + 6]
004358ad  884706                   mov       byte ptr [edi + 6], al
004358b0  8a4107                   mov       al, byte ptr [ecx + 7]
004358b3  884707                   mov       byte ptr [edi + 7], al
004358b6  8a4108                   mov       al, byte ptr [ecx + 8]
004358b9  884708                   mov       byte ptr [edi + 8], al
004358bc  8a4109                   mov       al, byte ptr [ecx + 9]
004358bf  884709                   mov       byte ptr [edi + 9], al
004358c2  8a410a                   mov       al, byte ptr [ecx + 0xa]
004358c5  88470a                   mov       byte ptr [edi + 0xa], al
004358c8  8a410b                   mov       al, byte ptr [ecx + 0xb]
004358cb  88470b                   mov       byte ptr [edi + 0xb], al
004358ce  8a410c                   mov       al, byte ptr [ecx + 0xc]
004358d1  88470c                   mov       byte ptr [edi + 0xc], al
004358d4  8a410d                   mov       al, byte ptr [ecx + 0xd]
004358d7  88470d                   mov       byte ptr [edi + 0xd], al
004358da  8a410e                   mov       al, byte ptr [ecx + 0xe]
004358dd  88470e                   mov       byte ptr [edi + 0xe], al
004358e0  8a410f                   mov       al, byte ptr [ecx + 0xf]
004358e3  88470f                   mov       byte ptr [edi + 0xf], al
004358e6  8d1510105700             lea       edx, [0x571010] ; bits=00000000, f32=0.0
004358ec  8d0558035700             lea       eax, [0x570358] ; bits=20202020, f32=1.3563156426940112e-19
004358f2  b908000000               mov       ecx, 8
004358f7  89d7                     mov       edi, edx
004358f9  89c6                     mov       esi, eax
004358fb  f3a5                     rep movsd dword ptr es:[edi], dword ptr [esi]
004358fd  8b05900e5700             mov       eax, dword ptr [0x570e90] ; bits=00000000, f32=0.0
00435903  89d9                     mov       ecx, ebx
00435905  29c1                     sub       ecx, eax
00435907  8d7101                   lea       esi, [ecx + 1]
0043590a  89df                     mov       edi, ebx
0043590c  29f7                     sub       edi, esi
0043590e  47                       inc       edi
0043590f  89fe                     mov       esi, edi
00435911  c1fe1f                   sar       esi, 0x1f
00435914  f7d6                     not       esi
00435916  21f7                     and       edi, esi
00435918  89c6                     mov       esi, eax
0043591a  c1fe1f                   sar       esi, 0x1f
0043591d  f7d6                     not       esi
0043591f  21f0                     and       eax, esi
00435921  8d0c0d10105700           lea       ecx, [ecx + 0x571010]
00435928  50                       push      eax
00435929  57                       push      edi
0043592a  6800105700               push      0x571000
0043592f  51                       push      ecx
00435930  e87b990600               call      0x49f2b0 ; _f_scmov
00435935  83c410                   add       esp, 0x10
00435938  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
0043593e  8b08                     mov       ecx, dword ptr [eax]
00435940  89de                     mov       esi, ebx
00435942  c1fe1f                   sar       esi, 0x1f
00435945  f7d6                     not       esi
00435947  89df                     mov       edi, ebx
00435949  21f7                     and       edi, esi
0043594b  8b35bc0e5700             mov       esi, dword ptr [0x570ebc] ; bits=00000000, f32=0.0
00435951  8b05c40e5700             mov       eax, dword ptr [0x570ec4] ; bits=00000000, f32=0.0
00435957  898d30ffffff             mov       dword ptr [ebp - 0xd0], ecx
0043595d  8d0d3c0d5700             lea       ecx, [0x570d3c] ; bits=09020000, f32=7.300764999132297e-43
00435963  89bd2cffffff             mov       dword ptr [ebp - 0xd4], edi
00435969  8bbd30ffffff             mov       edi, dword ptr [ebp - 0xd0]
0043596f  897dfc                   mov       dword ptr [ebp - 4], edi
00435972  8d7dfc                   lea       edi, [ebp - 4]
00435975  897908                   mov       dword ptr [ecx + 8], edi
00435978  8bbd2cffffff             mov       edi, dword ptr [ebp - 0xd4]
0043597e  897930                   mov       dword ptr [ecx + 0x30], edi
00435981  8975f8                   mov       dword ptr [ebp - 8], esi
00435984  8d75f8                   lea       esi, [ebp - 8]
00435987  897140                   mov       dword ptr [ecx + 0x40], esi
0043598a  8945f4                   mov       dword ptr [ebp - 0xc], eax
0043598d  8d45f4                   lea       eax, [ebp - 0xc]
00435990  89414c                   mov       dword ptr [ecx + 0x4c], eax
00435993  51                       push      ecx
00435994  e857cc0600               call      0x4a25f0 ; _jwe_isfm
00435999  83c404                   add       esp, 4
0043599c  6a04                     push      4
0043599e  68dc0e5700               push      0x570edc
004359a3  6a04                     push      4
004359a5  6888105700               push      0x571088
004359aa  e801a00100               call      0x44f9b0 ; _gettok_
004359af  83c410                   add       esp, 0x10
004359b2  8d058c105700             lea       eax, [0x57108c] ; bits=00000000, f32=0.0
004359b8  8d0d88105700             lea       ecx, [0x571088] ; bits=00000000, f32=0.0
004359be  50                       push      eax
004359bf  8a01                     mov       al, byte ptr [ecx]
004359c1  5e                       pop       esi
004359c2  8806                     mov       byte ptr [esi], al
004359c4  8a4101                   mov       al, byte ptr [ecx + 1]
004359c7  884601                   mov       byte ptr [esi + 1], al
004359ca  8a4102                   mov       al, byte ptr [ecx + 2]
004359cd  884602                   mov       byte ptr [esi + 2], al
004359d0  8a4103                   mov       al, byte ptr [ecx + 3]
004359d3  884603                   mov       byte ptr [esi + 3], al
004359d6  8d05dc0e5700             lea       eax, [0x570edc] ; bits=00000000, f32=0.0
004359dc  8d0d8c105700             lea       ecx, [0x57108c] ; bits=00000000, f32=0.0
004359e2  50                       push      eax
004359e3  8a01                     mov       al, byte ptr [ecx]
004359e5  5e                       pop       esi
004359e6  8806                     mov       byte ptr [esi], al
004359e8  8a4101                   mov       al, byte ptr [ecx + 1]
004359eb  884601                   mov       byte ptr [esi + 1], al
004359ee  8a4102                   mov       al, byte ptr [ecx + 2]
004359f1  884602                   mov       byte ptr [esi + 2], al
004359f4  8a4103                   mov       al, byte ptr [ecx + 3]
004359f7  884603                   mov       byte ptr [esi + 3], al
004359fa  8d15dc0e5700             lea       edx, [0x570edc] ; bits=00000000, f32=0.0
00435a00  8d0578035700             lea       eax, [0x570378] ; bits=55502020, f32=1.3579106795595607e-19
00435a06  b904000000               mov       ecx, 4
00435a0b  89d6                     mov       esi, edx
00435a0d  89c7                     mov       edi, eax
00435a0f  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00435a11  742e                     je        0x435a41
00435a13  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435a19  8b08                     mov       ecx, dword ptr [eax]
00435a1b  8d151c0d5700             lea       edx, [0x570d1c] ; bits=69020000, f32=8.646011524884121e-43
00435a21  894dfc                   mov       dword ptr [ebp - 4], ecx
00435a24  8d4dfc                   lea       ecx, [ebp - 4]
00435a27  894a08                   mov       dword ptr [edx + 8], ecx
00435a2a  52                       push      edx
00435a2b  e8c0cb0600               call      0x4a25f0 ; _jwe_isfm
00435a30  83c404                   add       esp, 4
00435a33  8b853cffffff             mov       eax, dword ptr [ebp - 0xc4]
00435a39  c70001000000             mov       dword ptr [eax], 1
00435a3f  eb32                     jmp       0x435a73
00435a41  8b853cffffff             mov       eax, dword ptr [ebp - 0xc4]
00435a47  8d00                     lea       eax, [eax]
00435a49  50                       push      eax
00435a4a  68880e5700               push      0x570e88
00435a4f  8b8538ffffff             mov       eax, dword ptr [ebp - 0xc8]
00435a55  8d48c4                   lea       ecx, [eax - 0x3c]
00435a58  51                       push      ecx
00435a59  68f05a0e04               push      0x40e5af0
00435a5e  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
00435a64  8d11                     lea       edx, [ecx]
00435a66  52                       push      edx
00435a67  8d5038                   lea       edx, [eax + 0x38]
00435a6a  52                       push      edx
00435a6b  e8e0220000               call      0x437d50 ; _chktab_
00435a70  83c418                   add       esp, 0x18
00435a73  6a50                     push      0x50
00435a75  68a80f5700               push      0x570fa8
00435a7a  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435a80  8d08                     lea       ecx, [eax]
00435a82  51                       push      ecx
00435a83  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
00435a89  8d31                     lea       esi, [ecx]
00435a8b  56                       push      esi
00435a8c  e84f6e0100               call      0x44c8e0 ; _inline_
00435a91  83c410                   add       esp, 0x10
00435a94  c705900e570000000000     mov       dword ptr [0x570e90], 0 ; bits=00000000, f32=0.0
00435a9e  6a04                     push      4
00435aa0  6a50                     push      0x50
00435aa2  68c80e5700               push      0x570ec8
00435aa7  68c00e5700               push      0x570ec0
00435aac  688c0e5700               push      0x570e8c
00435ab1  68dc0e5700               push      0x570edc
00435ab6  68900e5700               push      0x570e90
00435abb  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00435abe  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00435ac4  8d08                     lea       ecx, [eax]
00435ac6  51                       push      ecx
00435ac7  680c115700               push      0x57110c
00435acc  68f8105700               push      0x5710f8
00435ad1  68940e5700               push      0x570e94
00435ad6  68a80f5700               push      0x570fa8
00435adb  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
00435ae1  8d31                     lea       esi, [ecx]
00435ae3  56                       push      esi
00435ae4  e8b7f6ffff               call      0x4351a0 ; _read_expcon_items1_
00435ae9  83c434                   add       esp, 0x34
00435aec  688c0e5700               push      0x570e8c
00435af1  6a10                     push      0x10
00435af3  6890105700               push      0x571090
00435af8  e893180400               call      0x477390 ; _get_tabid_
00435afd  83c40c                   add       esp, 0xc
00435b00  8d0500105700             lea       eax, [0x571000] ; bits=00000000, f32=0.0
00435b06  8d0d90105700             lea       ecx, [0x571090] ; bits=00000000, f32=0.0
00435b0c  50                       push      eax
00435b0d  8a01                     mov       al, byte ptr [ecx]
00435b0f  5e                       pop       esi
00435b10  8806                     mov       byte ptr [esi], al
00435b12  8a4101                   mov       al, byte ptr [ecx + 1]
00435b15  884601                   mov       byte ptr [esi + 1], al
00435b18  8a4102                   mov       al, byte ptr [ecx + 2]
00435b1b  884602                   mov       byte ptr [esi + 2], al
00435b1e  8a4103                   mov       al, byte ptr [ecx + 3]
00435b21  884603                   mov       byte ptr [esi + 3], al
00435b24  8a4104                   mov       al, byte ptr [ecx + 4]
00435b27  884604                   mov       byte ptr [esi + 4], al
00435b2a  8a4105                   mov       al, byte ptr [ecx + 5]
00435b2d  884605                   mov       byte ptr [esi + 5], al
00435b30  8a4106                   mov       al, byte ptr [ecx + 6]
00435b33  884606                   mov       byte ptr [esi + 6], al
00435b36  8a4107                   mov       al, byte ptr [ecx + 7]
00435b39  884607                   mov       byte ptr [esi + 7], al
00435b3c  8a4108                   mov       al, byte ptr [ecx + 8]
00435b3f  884608                   mov       byte ptr [esi + 8], al
00435b42  8a4109                   mov       al, byte ptr [ecx + 9]
00435b45  884609                   mov       byte ptr [esi + 9], al
00435b48  8a410a                   mov       al, byte ptr [ecx + 0xa]
00435b4b  88460a                   mov       byte ptr [esi + 0xa], al
00435b4e  8a410b                   mov       al, byte ptr [ecx + 0xb]
00435b51  88460b                   mov       byte ptr [esi + 0xb], al
00435b54  8a410c                   mov       al, byte ptr [ecx + 0xc]
00435b57  88460c                   mov       byte ptr [esi + 0xc], al
00435b5a  8a410d                   mov       al, byte ptr [ecx + 0xd]
00435b5d  88460d                   mov       byte ptr [esi + 0xd], al
00435b60  8a410e                   mov       al, byte ptr [ecx + 0xe]
00435b63  88460e                   mov       byte ptr [esi + 0xe], al
00435b66  8a410f                   mov       al, byte ptr [ecx + 0xf]
00435b69  88460f                   mov       byte ptr [esi + 0xf], al
00435b6c  8d1510105700             lea       edx, [0x571010] ; bits=00000000, f32=0.0
00435b72  8d3558035700             lea       esi, [0x570358] ; bits=20202020, f32=1.3563156426940112e-19
00435b78  b908000000               mov       ecx, 8
00435b7d  89d7                     mov       edi, edx
00435b7f  f3a5                     rep movsd dword ptr es:[edi], dword ptr [esi]
00435b81  8b05900e5700             mov       eax, dword ptr [0x570e90] ; bits=00000000, f32=0.0
00435b87  89d9                     mov       ecx, ebx
00435b89  29c1                     sub       ecx, eax
00435b8b  8d7101                   lea       esi, [ecx + 1]
00435b8e  89df                     mov       edi, ebx
00435b90  29f7                     sub       edi, esi
00435b92  47                       inc       edi
00435b93  89fe                     mov       esi, edi
00435b95  c1fe1f                   sar       esi, 0x1f
00435b98  f7d6                     not       esi
00435b9a  21f7                     and       edi, esi
00435b9c  89c6                     mov       esi, eax
00435b9e  c1fe1f                   sar       esi, 0x1f
00435ba1  f7d6                     not       esi
00435ba3  21f0                     and       eax, esi
00435ba5  8d0c0d10105700           lea       ecx, [ecx + 0x571010]
00435bac  50                       push      eax
00435bad  57                       push      edi
00435bae  6800105700               push      0x571000
00435bb3  51                       push      ecx
00435bb4  e8f7960600               call      0x49f2b0 ; _f_scmov
00435bb9  83c410                   add       esp, 0x10
00435bbc  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435bc2  8b08                     mov       ecx, dword ptr [eax]
00435bc4  8b35c00e5700             mov       esi, dword ptr [0x570ec0] ; bits=00000000, f32=0.0
00435bca  8b3dc80e5700             mov       edi, dword ptr [0x570ec8] ; bits=00000000, f32=0.0
00435bd0  8d05cc0c5700             lea       eax, [0x570ccc] ; bits=09020000, f32=7.300764999132297e-43
00435bd6  894dfc                   mov       dword ptr [ebp - 4], ecx
00435bd9  8d4dfc                   lea       ecx, [ebp - 4]
00435bdc  894808                   mov       dword ptr [eax + 8], ecx
00435bdf  8b8d2cffffff             mov       ecx, dword ptr [ebp - 0xd4]
00435be5  894830                   mov       dword ptr [eax + 0x30], ecx
00435be8  8975f8                   mov       dword ptr [ebp - 8], esi
00435beb  8d4df8                   lea       ecx, [ebp - 8]
00435bee  894840                   mov       dword ptr [eax + 0x40], ecx
00435bf1  897df4                   mov       dword ptr [ebp - 0xc], edi
00435bf4  8d4df4                   lea       ecx, [ebp - 0xc]
00435bf7  89484c                   mov       dword ptr [eax + 0x4c], ecx
00435bfa  50                       push      eax
00435bfb  e8f0c90600               call      0x4a25f0 ; _jwe_isfm
00435c00  83c404                   add       esp, 4
00435c03  6a04                     push      4
00435c05  68dc0e5700               push      0x570edc
00435c0a  6a04                     push      4
00435c0c  68a0105700               push      0x5710a0
00435c11  e89a9d0100               call      0x44f9b0 ; _gettok_
00435c16  83c410                   add       esp, 0x10
00435c19  8d05a4105700             lea       eax, [0x5710a4] ; bits=00000000, f32=0.0
00435c1f  8d0da0105700             lea       ecx, [0x5710a0] ; bits=00000000, f32=0.0
00435c25  50                       push      eax
00435c26  8a01                     mov       al, byte ptr [ecx]
00435c28  5e                       pop       esi
00435c29  8806                     mov       byte ptr [esi], al
00435c2b  8a4101                   mov       al, byte ptr [ecx + 1]
00435c2e  884601                   mov       byte ptr [esi + 1], al
00435c31  8a4102                   mov       al, byte ptr [ecx + 2]
00435c34  884602                   mov       byte ptr [esi + 2], al
00435c37  8a4103                   mov       al, byte ptr [ecx + 3]
00435c3a  884603                   mov       byte ptr [esi + 3], al
00435c3d  8d05dc0e5700             lea       eax, [0x570edc] ; bits=00000000, f32=0.0
00435c43  8d0da4105700             lea       ecx, [0x5710a4] ; bits=00000000, f32=0.0
00435c49  50                       push      eax
00435c4a  8a01                     mov       al, byte ptr [ecx]
00435c4c  5e                       pop       esi
00435c4d  8806                     mov       byte ptr [esi], al
00435c4f  8a4101                   mov       al, byte ptr [ecx + 1]
00435c52  884601                   mov       byte ptr [esi + 1], al
00435c55  8a4102                   mov       al, byte ptr [ecx + 2]
00435c58  884602                   mov       byte ptr [esi + 2], al
00435c5b  8a4103                   mov       al, byte ptr [ecx + 3]
00435c5e  884603                   mov       byte ptr [esi + 3], al
00435c61  8d15dc0e5700             lea       edx, [0x570edc] ; bits=00000000, f32=0.0
00435c67  8d1d7c035700             lea       ebx, [0x57037c] ; bits=444e2020, f32=1.3578423079120544e-19
00435c6d  b904000000               mov       ecx, 4
00435c72  89d6                     mov       esi, edx
00435c74  89df                     mov       edi, ebx
00435c76  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00435c78  7419                     je        0x435c93
00435c7a  8d15dc0e5700             lea       edx, [0x570edc] ; bits=00000000, f32=0.0
00435c80  8d1df4015700             lea       ebx, [0x5701f4] ; bits=444f574e, f32=903074048.0
00435c86  b904000000               mov       ecx, 4
00435c8b  89d6                     mov       esi, edx
00435c8d  89df                     mov       edi, ebx
00435c8f  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00435c91  7531                     jne       0x435cc4
00435c93  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00435c96  8d00                     lea       eax, [eax]
00435c98  50                       push      eax
00435c99  688c0e5700               push      0x570e8c
00435c9e  8d0560015700             lea       eax, [0x570160] ; bits=64000000, f32=1.401298464324817e-43
00435ca4  8d48c4                   lea       ecx, [eax - 0x3c]
00435ca7  51                       push      ecx
00435ca8  68f05a0e04               push      0x40e5af0
00435cad  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
00435cb3  8d11                     lea       edx, [ecx]
00435cb5  52                       push      edx
00435cb6  8d4038                   lea       eax, [eax + 0x38]
00435cb9  50                       push      eax
00435cba  e891200000               call      0x437d50 ; _chktab_
00435cbf  83c418                   add       esp, 0x18
00435cc2  eb2c                     jmp       0x435cf0
00435cc4  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435cca  8b08                     mov       ecx, dword ptr [eax]
00435ccc  8d15ac0c5700             lea       edx, [0x570cac] ; bits=69020000, f32=8.646011524884121e-43
00435cd2  894dfc                   mov       dword ptr [ebp - 4], ecx
00435cd5  8d4dfc                   lea       ecx, [ebp - 4]
00435cd8  894a08                   mov       dword ptr [edx + 8], ecx
00435cdb  52                       push      edx
00435cdc  e80fc90600               call      0x4a25f0 ; _jwe_isfm
00435ce1  83c404                   add       esp, 4
00435ce4  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00435cea  c70001000000             mov       dword ptr [eax], 1
00435cf0  833d880e570000           cmp       dword ptr [0x570e88], 0 ; bits=00000000, f32=0.0
00435cf7  7532                     jne       0x435d2b
00435cf9  833d8c0e570000           cmp       dword ptr [0x570e8c], 0 ; bits=00000000, f32=0.0
00435d00  7529                     jne       0x435d2b
00435d02  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435d08  8b08                     mov       ecx, dword ptr [eax]
00435d0a  8d158c0c5700             lea       edx, [0x570c8c] ; bits=69020000, f32=8.646011524884121e-43
00435d10  894dfc                   mov       dword ptr [ebp - 4], ecx
00435d13  8d4dfc                   lea       ecx, [ebp - 4]
00435d16  894a08                   mov       dword ptr [edx + 8], ecx
00435d19  52                       push      edx
00435d1a  e8d1c80600               call      0x4a25f0 ; _jwe_isfm
00435d1f  83c404                   add       esp, 4
00435d22  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00435d25  c70001000000             mov       dword ptr [eax], 1
00435d2b  6a50                     push      0x50
00435d2d  68a80f5700               push      0x570fa8
00435d32  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435d38  8d08                     lea       ecx, [eax]
00435d3a  51                       push      ecx
00435d3b  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
00435d41  8d31                     lea       esi, [ecx]
00435d43  56                       push      esi
00435d44  e8976b0100               call      0x44c8e0 ; _inline_
00435d49  83c410                   add       esp, 0x10
00435d4c  68600c5700               push      0x570c60
00435d51  e8fabd0600               call      0x4a1b50 ; _jwe_iinf
00435d56  83c404                   add       esp, 4
00435d59  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435d5f  8b08                     mov       ecx, dword ptr [eax]
00435d61  8d35340c5700             lea       esi, [0x570c34] ; bits=09020000, f32=7.300764999132297e-43
00435d67  894dfc                   mov       dword ptr [ebp - 4], ecx
00435d6a  8d4dfc                   lea       ecx, [ebp - 4]
00435d6d  894e08                   mov       dword ptr [esi + 8], ecx
00435d70  56                       push      esi
00435d71  e87ac80600               call      0x4a25f0 ; _jwe_isfm
00435d76  83c404                   add       esp, 4
00435d79  6a50                     push      0x50
00435d7b  68a80f5700               push      0x570fa8
00435d80  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435d86  8d08                     lea       ecx, [eax]
00435d88  51                       push      ecx
00435d89  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
00435d8f  8d31                     lea       esi, [ecx]
00435d91  56                       push      esi
00435d92  e8496b0100               call      0x44c8e0 ; _inline_
00435d97  83c410                   add       esp, 0x10
00435d9a  68080c5700               push      0x570c08
00435d9f  e8acbd0600               call      0x4a1b50 ; _jwe_iinf
00435da4  83c404                   add       esp, 4
00435da7  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435dad  8b08                     mov       ecx, dword ptr [eax]
00435daf  8d35dc0b5700             lea       esi, [0x570bdc] ; bits=09020000, f32=7.300764999132297e-43
00435db5  894dfc                   mov       dword ptr [ebp - 4], ecx
00435db8  8d4dfc                   lea       ecx, [ebp - 4]
00435dbb  894e08                   mov       dword ptr [esi + 8], ecx
00435dbe  56                       push      esi
00435dbf  e82cc80600               call      0x4a25f0 ; _jwe_isfm
00435dc4  83c404                   add       esp, 4
00435dc7  6a05                     push      5
00435dc9  6a50                     push      0x50
00435dcb  680c115700               push      0x57110c
00435dd0  68f8105700               push      0x5710f8
00435dd5  68940e5700               push      0x570e94
00435dda  68f80f5700               push      0x570ff8
00435ddf  8d3560015700             lea       esi, [0x570160] ; bits=64000000, f32=1.401298464324817e-43
00435de5  8d4670                   lea       eax, [esi + 0x70]
00435de8  50                       push      eax
00435de9  68e80e5700               push      0x570ee8
00435dee  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435df4  8d08                     lea       ecx, [eax]
00435df6  51                       push      ecx
00435df7  e8e48e0100               call      0x44ece0 ; _get_item_limits_
00435dfc  83c424                   add       esp, 0x24
00435dff  8b0510115700             mov       eax, dword ptr [0x571110] ; bits=00000000, f32=0.0
00435e05  2b05fc105700             sub       eax, dword ptr [0x5710fc] ; bits=00000000, f32=0.0
00435e0b  40                       inc       eax
00435e0c  89c3                     mov       ebx, eax
00435e0e  6a50                     push      0x50
00435e10  68a80f5700               push      0x570fa8
00435e15  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435e1b  8d08                     lea       ecx, [eax]
00435e1d  51                       push      ecx
00435e1e  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
00435e24  8d39                     lea       edi, [ecx]
00435e26  57                       push      edi
00435e27  e8b46a0100               call      0x44c8e0 ; _inline_
00435e2c  83c410                   add       esp, 0x10
00435e2f  c705900e570000000000     mov       dword ptr [0x570e90], 0 ; bits=00000000, f32=0.0
00435e39  6a32                     push      0x32
00435e3b  6a04                     push      4
00435e3d  6a50                     push      0x50
00435e3f  68700f5700               push      0x570f70
00435e44  68ac0e5700               push      0x570eac
00435e49  68a40e5700               push      0x570ea4
00435e4e  68800e5700               push      0x570e80
00435e53  68dc0e5700               push      0x570edc
00435e58  68900e5700               push      0x570e90
00435e5d  8b7d1c                   mov       edi, dword ptr [ebp + 0x1c]
00435e60  8d07                     lea       eax, [edi]
00435e62  50                       push      eax
00435e63  680c115700               push      0x57110c
00435e68  68f8105700               push      0x5710f8
00435e6d  68940e5700               push      0x570e94
00435e72  68a80f5700               push      0x570fa8
00435e77  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435e7d  8d08                     lea       ecx, [eax]
00435e7f  51                       push      ecx
00435e80  e85bf5ffff               call      0x4353e0 ; _read_expcon_items2_
00435e85  83c43c                   add       esp, 0x3c
00435e88  68800e5700               push      0x570e80
00435e8d  6a10                     push      0x10
00435e8f  68a8105700               push      0x5710a8
00435e94  e8f7140400               call      0x477390 ; _get_tabid_
00435e99  83c40c                   add       esp, 0xc
00435e9c  8d0530105700             lea       eax, [0x571030] ; bits=00000000, f32=0.0
00435ea2  8d0da8105700             lea       ecx, [0x5710a8] ; bits=00000000, f32=0.0
00435ea8  898510ffffff             mov       dword ptr [ebp - 0xf0], eax
00435eae  8a01                     mov       al, byte ptr [ecx]
00435eb0  89b50cffffff             mov       dword ptr [ebp - 0xf4], esi
00435eb6  8bb510ffffff             mov       esi, dword ptr [ebp - 0xf0]
00435ebc  8806                     mov       byte ptr [esi], al
00435ebe  8a4101                   mov       al, byte ptr [ecx + 1]
00435ec1  884601                   mov       byte ptr [esi + 1], al
00435ec4  8a4102                   mov       al, byte ptr [ecx + 2]
00435ec7  884602                   mov       byte ptr [esi + 2], al
00435eca  8a4103                   mov       al, byte ptr [ecx + 3]
00435ecd  884603                   mov       byte ptr [esi + 3], al
00435ed0  8a4104                   mov       al, byte ptr [ecx + 4]
00435ed3  884604                   mov       byte ptr [esi + 4], al
00435ed6  8a4105                   mov       al, byte ptr [ecx + 5]
00435ed9  884605                   mov       byte ptr [esi + 5], al
00435edc  8a4106                   mov       al, byte ptr [ecx + 6]
00435edf  884606                   mov       byte ptr [esi + 6], al
00435ee2  8a4107                   mov       al, byte ptr [ecx + 7]
00435ee5  884607                   mov       byte ptr [esi + 7], al
00435ee8  8a4108                   mov       al, byte ptr [ecx + 8]
00435eeb  884608                   mov       byte ptr [esi + 8], al
00435eee  8a4109                   mov       al, byte ptr [ecx + 9]
00435ef1  884609                   mov       byte ptr [esi + 9], al
00435ef4  8a410a                   mov       al, byte ptr [ecx + 0xa]
00435ef7  88460a                   mov       byte ptr [esi + 0xa], al
00435efa  8a410b                   mov       al, byte ptr [ecx + 0xb]
00435efd  88460b                   mov       byte ptr [esi + 0xb], al
00435f00  8a410c                   mov       al, byte ptr [ecx + 0xc]
00435f03  88460c                   mov       byte ptr [esi + 0xc], al
00435f06  8a410d                   mov       al, byte ptr [ecx + 0xd]
00435f09  88460d                   mov       byte ptr [esi + 0xd], al
00435f0c  8a410e                   mov       al, byte ptr [ecx + 0xe]
00435f0f  88460e                   mov       byte ptr [esi + 0xe], al
00435f12  8a410f                   mov       al, byte ptr [ecx + 0xf]
00435f15  88460f                   mov       byte ptr [esi + 0xf], al
00435f18  8d1510105700             lea       edx, [0x571010] ; bits=00000000, f32=0.0
00435f1e  8d3558035700             lea       esi, [0x570358] ; bits=20202020, f32=1.3563156426940112e-19
00435f24  b908000000               mov       ecx, 8
00435f29  89bd08ffffff             mov       dword ptr [ebp - 0xf8], edi
00435f2f  89d7                     mov       edi, edx
00435f31  f3a5                     rep movsd dword ptr es:[edi], dword ptr [esi]
00435f33  8b05900e5700             mov       eax, dword ptr [0x570e90] ; bits=00000000, f32=0.0
00435f39  89d9                     mov       ecx, ebx
00435f3b  29c1                     sub       ecx, eax
00435f3d  8d7101                   lea       esi, [ecx + 1]
00435f40  89df                     mov       edi, ebx
00435f42  29f7                     sub       edi, esi
00435f44  47                       inc       edi
00435f45  89fe                     mov       esi, edi
00435f47  c1fe1f                   sar       esi, 0x1f
00435f4a  f7d6                     not       esi
00435f4c  21f7                     and       edi, esi
00435f4e  89c6                     mov       esi, eax
00435f50  c1fe1f                   sar       esi, 0x1f
00435f53  f7d6                     not       esi
00435f55  21f0                     and       eax, esi
00435f57  8d0c0d10105700           lea       ecx, [ecx + 0x571010]
00435f5e  50                       push      eax
00435f5f  57                       push      edi
00435f60  6830105700               push      0x571030
00435f65  51                       push      ecx
00435f66  e845930600               call      0x49f2b0 ; _f_scmov
00435f6b  83c410                   add       esp, 0x10
00435f6e  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00435f74  8b08                     mov       ecx, dword ptr [eax]
00435f76  89de                     mov       esi, ebx
00435f78  c1fe1f                   sar       esi, 0x1f
00435f7b  f7d6                     not       esi
00435f7d  89df                     mov       edi, ebx
00435f7f  21f7                     and       edi, esi
00435f81  8b35a40e5700             mov       esi, dword ptr [0x570ea4] ; bits=00000000, f32=0.0
00435f87  8b05ac0e5700             mov       eax, dword ptr [0x570eac] ; bits=00000000, f32=0.0
00435f8d  898d04ffffff             mov       dword ptr [ebp - 0xfc], ecx
00435f93  8d0d800b5700             lea       ecx, [0x570b80] ; bits=09020000, f32=7.300764999132297e-43
00435f99  89bd00ffffff             mov       dword ptr [ebp - 0x100], edi
00435f9f  8bbd04ffffff             mov       edi, dword ptr [ebp - 0xfc]
00435fa5  897dfc                   mov       dword ptr [ebp - 4], edi
00435fa8  8d7dfc                   lea       edi, [ebp - 4]
00435fab  897908                   mov       dword ptr [ecx + 8], edi
00435fae  8bbd00ffffff             mov       edi, dword ptr [ebp - 0x100]
00435fb4  897930                   mov       dword ptr [ecx + 0x30], edi
00435fb7  8975f8                   mov       dword ptr [ebp - 8], esi
00435fba  8d75f8                   lea       esi, [ebp - 8]
00435fbd  897140                   mov       dword ptr [ecx + 0x40], esi
00435fc0  8945f4                   mov       dword ptr [ebp - 0xc], eax
00435fc3  8d45f4                   lea       eax, [ebp - 0xc]
00435fc6  89414c                   mov       dword ptr [ecx + 0x4c], eax
00435fc9  51                       push      ecx
00435fca  e821c60600               call      0x4a25f0 ; _jwe_isfm
00435fcf  83c404                   add       esp, 4
00435fd2  6a04                     push      4
00435fd4  68dc0e5700               push      0x570edc
00435fd9  6a04                     push      4
00435fdb  68b8105700               push      0x5710b8
00435fe0  e8cb990100               call      0x44f9b0 ; _gettok_
00435fe5  83c410                   add       esp, 0x10
00435fe8  8d05bc105700             lea       eax, [0x5710bc] ; bits=00000000, f32=0.0
00435fee  8d0db8105700             lea       ecx, [0x5710b8] ; bits=00000000, f32=0.0
00435ff4  50                       push      eax
00435ff5  8a01                     mov       al, byte ptr [ecx]
00435ff7  5e                       pop       esi
00435ff8  8806                     mov       byte ptr [esi], al
00435ffa  8a4101                   mov       al, byte ptr [ecx + 1]
00435ffd  884601                   mov       byte ptr [esi + 1], al
00436000  8a4102                   mov       al, byte ptr [ecx + 2]
00436003  884602                   mov       byte ptr [esi + 2], al
00436006  8a4103                   mov       al, byte ptr [ecx + 3]
00436009  884603                   mov       byte ptr [esi + 3], al
0043600c  8d05dc0e5700             lea       eax, [0x570edc] ; bits=00000000, f32=0.0
00436012  8d0dbc105700             lea       ecx, [0x5710bc] ; bits=00000000, f32=0.0
00436018  50                       push      eax
00436019  8a01                     mov       al, byte ptr [ecx]
0043601b  5e                       pop       esi
0043601c  8806                     mov       byte ptr [esi], al
0043601e  8a4101                   mov       al, byte ptr [ecx + 1]
00436021  884601                   mov       byte ptr [esi + 1], al
00436024  8a4102                   mov       al, byte ptr [ecx + 2]
00436027  884602                   mov       byte ptr [esi + 2], al
0043602a  8a4103                   mov       al, byte ptr [ecx + 3]
0043602d  884603                   mov       byte ptr [esi + 3], al
00436030  8bb508ffffff             mov       esi, dword ptr [ebp - 0xf8]
00436036  8d36                     lea       esi, [esi]
00436038  56                       push      esi
00436039  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0043603c  8d00                     lea       eax, [eax]
0043603e  50                       push      eax
0043603f  68800e5700               push      0x570e80
00436044  8bb50cffffff             mov       esi, dword ptr [ebp - 0xf4]
0043604a  8d76c4                   lea       esi, [esi - 0x3c]
0043604d  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436053  56                       push      esi
00436054  8d08                     lea       ecx, [eax]
00436056  51                       push      ecx
00436057  e834180000               call      0x437890 ; _tabchk_
0043605c  83c414                   add       esp, 0x14
0043605f  d905a40e5700             fld       dword ptr [0x570ea4] ; bits=00000000, f32=0.0
00436065  db7dc0                   fstp      xword ptr [ebp - 0x40]
00436068  db6dc0                   fld       xword ptr [ebp - 0x40]
0043606b  d81df8005700             fcomp     dword ptr [0x5700f8] ; bits=0000803f, f32=1.0
00436071  dfe0                     fnstsw    ax
00436073  9e                       sahf
00436074  0f8a02000000             jp        0x43607c
0043607a  7714                     ja        0x436090
0043607c  db6dc0                   fld       xword ptr [ebp - 0x40]
0043607f  d81df0005700             fcomp     dword ptr [0x5700f0] ; bits=00000000, f32=0.0
00436085  dfe0                     fnstsw    ax
00436087  9e                       sahf
00436088  0f8a3a000000             jp        0x4360c8
0043608e  7338                     jae       0x4360c8
00436090  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436096  8b08                     mov       ecx, dword ptr [eax]
00436098  8b15a40e5700             mov       edx, dword ptr [0x570ea4] ; bits=00000000, f32=0.0
0043609e  8d35540b5700             lea       esi, [0x570b54] ; bits=09020000, f32=7.300764999132297e-43
004360a4  894dfc                   mov       dword ptr [ebp - 4], ecx
004360a7  8d4dfc                   lea       ecx, [ebp - 4]
004360aa  894e08                   mov       dword ptr [esi + 8], ecx
004360ad  8955f8                   mov       dword ptr [ebp - 8], edx
004360b0  8d4df8                   lea       ecx, [ebp - 8]
004360b3  894e28                   mov       dword ptr [esi + 0x28], ecx
004360b6  56                       push      esi
004360b7  e834c50600               call      0x4a25f0 ; _jwe_isfm
004360bc  83c404                   add       esp, 4
004360bf  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004360c2  c70001000000             mov       dword ptr [eax], 1
004360c8  d905ac0e5700             fld       dword ptr [0x570eac] ; bits=00000000, f32=0.0
004360ce  d815f8005700             fcom      dword ptr [0x5700f8] ; bits=0000803f, f32=1.0
004360d4  db7db4                   fstp      xword ptr [ebp - 0x4c]
004360d7  dfe0                     fnstsw    ax
004360d9  9e                       sahf
004360da  0f8a02000000             jp        0x4360e2
004360e0  7714                     ja        0x4360f6
004360e2  db6db4                   fld       xword ptr [ebp - 0x4c]
004360e5  d81df0005700             fcomp     dword ptr [0x5700f0] ; bits=00000000, f32=0.0
004360eb  dfe0                     fnstsw    ax
004360ed  9e                       sahf
004360ee  0f8a3a000000             jp        0x43612e
004360f4  7338                     jae       0x43612e
004360f6  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004360fc  8b08                     mov       ecx, dword ptr [eax]
004360fe  8b15ac0e5700             mov       edx, dword ptr [0x570eac] ; bits=00000000, f32=0.0
00436104  8d35280b5700             lea       esi, [0x570b28] ; bits=09020000, f32=7.300764999132297e-43
0043610a  894dfc                   mov       dword ptr [ebp - 4], ecx
0043610d  8d4dfc                   lea       ecx, [ebp - 4]
00436110  894e08                   mov       dword ptr [esi + 8], ecx
00436113  8955f8                   mov       dword ptr [ebp - 8], edx
00436116  8d4df8                   lea       ecx, [ebp - 8]
00436119  894e28                   mov       dword ptr [esi + 0x28], ecx
0043611c  56                       push      esi
0043611d  e8cec40600               call      0x4a25f0 ; _jwe_isfm
00436122  83c404                   add       esp, 4
00436125  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00436128  c70001000000             mov       dword ptr [eax], 1
0043612e  8d15dc0e5700             lea       edx, [0x570edc] ; bits=00000000, f32=0.0
00436134  8d3d84035700             lea       edi, [0x570384] ; bits=55442020, f32=1.3575136328655352e-19
0043613a  b904000000               mov       ecx, 4
0043613f  89d6                     mov       esi, edx
00436141  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00436143  7440                     je        0x436185
00436145  8d15dc0e5700             lea       edx, [0x570edc] ; bits=00000000, f32=0.0
0043614b  8d3dfc015700             lea       edi, [0x5701fc] ; bits=55544f44, f32=829.3176879882812
00436151  b904000000               mov       ecx, 4
00436156  89d6                     mov       esi, edx
00436158  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0043615a  7429                     je        0x436185
0043615c  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436162  8b08                     mov       ecx, dword ptr [eax]
00436164  8d15080b5700             lea       edx, [0x570b08] ; bits=69020000, f32=8.646011524884121e-43
0043616a  894dfc                   mov       dword ptr [ebp - 4], ecx
0043616d  8d4dfc                   lea       ecx, [ebp - 4]
00436170  894a08                   mov       dword ptr [edx + 8], ecx
00436173  52                       push      edx
00436174  e877c40600               call      0x4a25f0 ; _jwe_isfm
00436179  83c404                   add       esp, 4
0043617c  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0043617f  c70001000000             mov       dword ptr [eax], 1
00436185  6a50                     push      0x50
00436187  68a80f5700               push      0x570fa8
0043618c  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436192  8d08                     lea       ecx, [eax]
00436194  51                       push      ecx
00436195  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
0043619b  8d11                     lea       edx, [ecx]
0043619d  52                       push      edx
0043619e  e83d670100               call      0x44c8e0 ; _inline_
004361a3  83c410                   add       esp, 0x10
004361a6  c705900e570000000000     mov       dword ptr [0x570e90], 0 ; bits=00000000, f32=0.0
004361b0  6a32                     push      0x32
004361b2  6a04                     push      4
004361b4  6a50                     push      0x50
004361b6  68380f5700               push      0x570f38
004361bb  68a80e5700               push      0x570ea8
004361c0  68a00e5700               push      0x570ea0
004361c5  68700e5700               push      0x570e70
004361ca  68dc0e5700               push      0x570edc
004361cf  68900e5700               push      0x570e90
004361d4  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004361d7  8985f4feffff             mov       dword ptr [ebp - 0x10c], eax
004361dd  8d08                     lea       ecx, [eax]
004361df  51                       push      ecx
004361e0  680c115700               push      0x57110c
004361e5  68f8105700               push      0x5710f8
004361ea  68940e5700               push      0x570e94
004361ef  68a80f5700               push      0x570fa8
004361f4  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
004361fa  8d11                     lea       edx, [ecx]
004361fc  52                       push      edx
004361fd  e8def1ffff               call      0x4353e0 ; _read_expcon_items2_
00436202  83c43c                   add       esp, 0x3c
00436205  68700e5700               push      0x570e70
0043620a  6a10                     push      0x10
0043620c  68c0105700               push      0x5710c0
00436211  e87a110400               call      0x477390 ; _get_tabid_
00436216  83c40c                   add       esp, 0xc
00436219  8d0540105700             lea       eax, [0x571040] ; bits=00000000, f32=0.0
0043621f  8d0dc0105700             lea       ecx, [0x5710c0] ; bits=00000000, f32=0.0
00436225  8a11                     mov       dl, byte ptr [ecx]
00436227  8810                     mov       byte ptr [eax], dl
00436229  8a5101                   mov       dl, byte ptr [ecx + 1]
0043622c  885001                   mov       byte ptr [eax + 1], dl
0043622f  8a5102                   mov       dl, byte ptr [ecx + 2]
00436232  885002                   mov       byte ptr [eax + 2], dl
00436235  8a5103                   mov       dl, byte ptr [ecx + 3]
00436238  885003                   mov       byte ptr [eax + 3], dl
0043623b  8a5104                   mov       dl, byte ptr [ecx + 4]
0043623e  885004                   mov       byte ptr [eax + 4], dl
00436241  8a5105                   mov       dl, byte ptr [ecx + 5]
00436244  885005                   mov       byte ptr [eax + 5], dl
00436247  8a5106                   mov       dl, byte ptr [ecx + 6]
0043624a  885006                   mov       byte ptr [eax + 6], dl
0043624d  8a5107                   mov       dl, byte ptr [ecx + 7]
00436250  885007                   mov       byte ptr [eax + 7], dl
00436253  8a5108                   mov       dl, byte ptr [ecx + 8]
00436256  885008                   mov       byte ptr [eax + 8], dl
00436259  8a5109                   mov       dl, byte ptr [ecx + 9]
0043625c  885009                   mov       byte ptr [eax + 9], dl
0043625f  8a510a                   mov       dl, byte ptr [ecx + 0xa]
00436262  88500a                   mov       byte ptr [eax + 0xa], dl
00436265  8a510b                   mov       dl, byte ptr [ecx + 0xb]
00436268  88500b                   mov       byte ptr [eax + 0xb], dl
0043626b  8a510c                   mov       dl, byte ptr [ecx + 0xc]
0043626e  88500c                   mov       byte ptr [eax + 0xc], dl
00436271  8a510d                   mov       dl, byte ptr [ecx + 0xd]
00436274  88500d                   mov       byte ptr [eax + 0xd], dl
00436277  8a510e                   mov       dl, byte ptr [ecx + 0xe]
0043627a  88500e                   mov       byte ptr [eax + 0xe], dl
0043627d  8a510f                   mov       dl, byte ptr [ecx + 0xf]
00436280  88500f                   mov       byte ptr [eax + 0xf], dl
00436283  8d3d10105700             lea       edi, [0x571010] ; bits=00000000, f32=0.0
00436289  8d3558035700             lea       esi, [0x570358] ; bits=20202020, f32=1.3563156426940112e-19
0043628f  b908000000               mov       ecx, 8
00436294  f3a5                     rep movsd dword ptr es:[edi], dword ptr [esi]
00436296  8b05900e5700             mov       eax, dword ptr [0x570e90] ; bits=00000000, f32=0.0
0043629c  89d9                     mov       ecx, ebx
0043629e  29c1                     sub       ecx, eax
004362a0  8d5101                   lea       edx, [ecx + 1]
004362a3  89de                     mov       esi, ebx
004362a5  29d6                     sub       esi, edx
004362a7  46                       inc       esi
004362a8  89f2                     mov       edx, esi
004362aa  c1fa1f                   sar       edx, 0x1f
004362ad  f7d2                     not       edx
004362af  21d6                     and       esi, edx
004362b1  89c2                     mov       edx, eax
004362b3  c1fa1f                   sar       edx, 0x1f
004362b6  f7d2                     not       edx
004362b8  21d0                     and       eax, edx
004362ba  8d0c0d10105700           lea       ecx, [ecx + 0x571010]
004362c1  50                       push      eax
004362c2  56                       push      esi
004362c3  6840105700               push      0x571040
004362c8  51                       push      ecx
004362c9  e8e28f0600               call      0x49f2b0 ; _f_scmov
004362ce  83c410                   add       esp, 0x10
004362d1  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004362d7  8b08                     mov       ecx, dword ptr [eax]
004362d9  8b15a00e5700             mov       edx, dword ptr [0x570ea0] ; bits=00000000, f32=0.0
004362df  8b35a80e5700             mov       esi, dword ptr [0x570ea8] ; bits=00000000, f32=0.0
004362e5  8d3dac0a5700             lea       edi, [0x570aac] ; bits=09020000, f32=7.300764999132297e-43
004362eb  894dfc                   mov       dword ptr [ebp - 4], ecx
004362ee  8d4dfc                   lea       ecx, [ebp - 4]
004362f1  894f08                   mov       dword ptr [edi + 8], ecx
004362f4  8b8d00ffffff             mov       ecx, dword ptr [ebp - 0x100]
004362fa  894f30                   mov       dword ptr [edi + 0x30], ecx
004362fd  8955f8                   mov       dword ptr [ebp - 8], edx
00436300  8d4df8                   lea       ecx, [ebp - 8]
00436303  894f40                   mov       dword ptr [edi + 0x40], ecx
00436306  8975f4                   mov       dword ptr [ebp - 0xc], esi
00436309  8d4df4                   lea       ecx, [ebp - 0xc]
0043630c  894f4c                   mov       dword ptr [edi + 0x4c], ecx
0043630f  57                       push      edi
00436310  e8dbc20600               call      0x4a25f0 ; _jwe_isfm
00436315  83c404                   add       esp, 4
00436318  6a04                     push      4
0043631a  68dc0e5700               push      0x570edc
0043631f  6a04                     push      4
00436321  68d0105700               push      0x5710d0
00436326  e885960100               call      0x44f9b0 ; _gettok_
0043632b  83c410                   add       esp, 0x10
0043632e  8d05d4105700             lea       eax, [0x5710d4] ; bits=00000000, f32=0.0
00436334  8d0dd0105700             lea       ecx, [0x5710d0] ; bits=00000000, f32=0.0
0043633a  8a11                     mov       dl, byte ptr [ecx]
0043633c  8810                     mov       byte ptr [eax], dl
0043633e  8a5101                   mov       dl, byte ptr [ecx + 1]
00436341  885001                   mov       byte ptr [eax + 1], dl
00436344  8a5102                   mov       dl, byte ptr [ecx + 2]
00436347  885002                   mov       byte ptr [eax + 2], dl
0043634a  8a5103                   mov       dl, byte ptr [ecx + 3]
0043634d  885003                   mov       byte ptr [eax + 3], dl
00436350  8d05dc0e5700             lea       eax, [0x570edc] ; bits=00000000, f32=0.0
00436356  8d0dd4105700             lea       ecx, [0x5710d4] ; bits=00000000, f32=0.0
0043635c  8a11                     mov       dl, byte ptr [ecx]
0043635e  8810                     mov       byte ptr [eax], dl
00436360  8a5101                   mov       dl, byte ptr [ecx + 1]
00436363  885001                   mov       byte ptr [eax + 1], dl
00436366  8a5102                   mov       dl, byte ptr [ecx + 2]
00436369  885002                   mov       byte ptr [eax + 2], dl
0043636c  8a5103                   mov       dl, byte ptr [ecx + 3]
0043636f  885003                   mov       byte ptr [eax + 3], dl
00436372  833d700e570000           cmp       dword ptr [0x570e70], 0 ; bits=00000000, f32=0.0
00436379  0f8e50010000             jle       0x4364cf
0043637f  8b85f4feffff             mov       eax, dword ptr [ebp - 0x10c]
00436385  8d08                     lea       ecx, [eax]
00436387  51                       push      ecx
00436388  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0043638b  8d00                     lea       eax, [eax]
0043638d  50                       push      eax
0043638e  68700e5700               push      0x570e70
00436393  6824015700               push      0x570124
00436398  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
0043639e  8d08                     lea       ecx, [eax]
004363a0  51                       push      ecx
004363a1  e8ea140000               call      0x437890 ; _tabchk_
004363a6  83c414                   add       esp, 0x14
004363a9  d905a00e5700             fld       dword ptr [0x570ea0] ; bits=00000000, f32=0.0
004363af  db7da8                   fstp      xword ptr [ebp - 0x58]
004363b2  db6da8                   fld       xword ptr [ebp - 0x58]
004363b5  d81df8005700             fcomp     dword ptr [0x5700f8] ; bits=0000803f, f32=1.0
004363bb  dfe0                     fnstsw    ax
004363bd  9e                       sahf
004363be  0f8a02000000             jp        0x4363c6
004363c4  7714                     ja        0x4363da
004363c6  db6da8                   fld       xword ptr [ebp - 0x58]
004363c9  d81df0005700             fcomp     dword ptr [0x5700f0] ; bits=00000000, f32=0.0
004363cf  dfe0                     fnstsw    ax
004363d1  9e                       sahf
004363d2  0f8a3a000000             jp        0x436412
004363d8  7338                     jae       0x436412
004363da  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004363e0  8b08                     mov       ecx, dword ptr [eax]
004363e2  8b15a00e5700             mov       edx, dword ptr [0x570ea0] ; bits=00000000, f32=0.0
004363e8  8d1d800a5700             lea       ebx, [0x570a80] ; bits=09020000, f32=7.300764999132297e-43
004363ee  894dfc                   mov       dword ptr [ebp - 4], ecx
004363f1  8d4dfc                   lea       ecx, [ebp - 4]
004363f4  894b08                   mov       dword ptr [ebx + 8], ecx
004363f7  8955f8                   mov       dword ptr [ebp - 8], edx
004363fa  8d4df8                   lea       ecx, [ebp - 8]
004363fd  894b28                   mov       dword ptr [ebx + 0x28], ecx
00436400  53                       push      ebx
00436401  e8eac10600               call      0x4a25f0 ; _jwe_isfm
00436406  83c404                   add       esp, 4
00436409  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0043640c  c70001000000             mov       dword ptr [eax], 1
00436412  d905a80e5700             fld       dword ptr [0x570ea8] ; bits=00000000, f32=0.0
00436418  d815f8005700             fcom      dword ptr [0x5700f8] ; bits=0000803f, f32=1.0
0043641e  db7d9c                   fstp      xword ptr [ebp - 0x64]
00436421  dfe0                     fnstsw    ax
00436423  9e                       sahf
00436424  0f8a02000000             jp        0x43642c
0043642a  7714                     ja        0x436440
0043642c  db6d9c                   fld       xword ptr [ebp - 0x64]
0043642f  d81df0005700             fcomp     dword ptr [0x5700f0] ; bits=00000000, f32=0.0
00436435  dfe0                     fnstsw    ax
00436437  9e                       sahf
00436438  0f8a3a000000             jp        0x436478
0043643e  7338                     jae       0x436478
00436440  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436446  8b08                     mov       ecx, dword ptr [eax]
00436448  8b15a80e5700             mov       edx, dword ptr [0x570ea8] ; bits=00000000, f32=0.0
0043644e  8d1d540a5700             lea       ebx, [0x570a54] ; bits=09020000, f32=7.300764999132297e-43
00436454  894dfc                   mov       dword ptr [ebp - 4], ecx
00436457  8d4dfc                   lea       ecx, [ebp - 4]
0043645a  894b08                   mov       dword ptr [ebx + 8], ecx
0043645d  8955f8                   mov       dword ptr [ebp - 8], edx
00436460  8d4df8                   lea       ecx, [ebp - 8]
00436463  894b28                   mov       dword ptr [ebx + 0x28], ecx
00436466  53                       push      ebx
00436467  e884c10600               call      0x4a25f0 ; _jwe_isfm
0043646c  83c404                   add       esp, 4
0043646f  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00436472  c70001000000             mov       dword ptr [eax], 1
00436478  8d15dc0e5700             lea       edx, [0x570edc] ; bits=00000000, f32=0.0
0043647e  8d3d80035700             lea       edi, [0x570380] ; bits=44552020, f32=1.3580739184835692e-19
00436484  b904000000               mov       ecx, 4
00436489  89d6                     mov       esi, edx
0043648b  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0043648d  7440                     je        0x4364cf
0043648f  8d15dc0e5700             lea       edx, [0x570edc] ; bits=00000000, f32=0.0
00436495  8d3df8015700             lea       edi, [0x5701f8] ; bits=44544f55, f32=14247551565824.0
0043649b  b904000000               mov       ecx, 4
004364a0  89d6                     mov       esi, edx
004364a2  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
004364a4  7429                     je        0x4364cf
004364a6  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004364ac  8b08                     mov       ecx, dword ptr [eax]
004364ae  8d15340a5700             lea       edx, [0x570a34] ; bits=69020000, f32=8.646011524884121e-43
004364b4  894dfc                   mov       dword ptr [ebp - 4], ecx
004364b7  8d4dfc                   lea       ecx, [ebp - 4]
004364ba  894a08                   mov       dword ptr [edx + 8], ecx
004364bd  52                       push      edx
004364be  e82dc10600               call      0x4a25f0 ; _jwe_isfm
004364c3  83c404                   add       esp, 4
004364c6  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004364c9  c70001000000             mov       dword ptr [eax], 1
004364cf  6a10                     push      0x10
004364d1  6830105700               push      0x571030
004364d6  e875950100               call      0x44fa50 ; _lenstr_
004364db  83c408                   add       esp, 8
004364de  89c2                     mov       edx, eax
004364e0  c1fa1f                   sar       edx, 0x1f
004364e3  f7d2                     not       edx
004364e5  21d0                     and       eax, edx
004364e7  8985f0feffff             mov       dword ptr [ebp - 0x110], eax
004364ed  6a10                     push      0x10
004364ef  6840105700               push      0x571040
004364f4  e857950100               call      0x44fa50 ; _lenstr_
004364f9  83c408                   add       esp, 8
004364fc  89c2                     mov       edx, eax
004364fe  c1fa1f                   sar       edx, 0x1f
00436501  f7d2                     not       edx
00436503  21d0                     and       eax, edx
00436505  8d0dfc095700             lea       ecx, [0x5709fc] ; bits=09220000, f32=1.220951351966213e-41
0043650b  8b9df0feffff             mov       ebx, dword ptr [ebp - 0x110]
00436511  895924                   mov       dword ptr [ecx + 0x24], ebx
00436514  894130                   mov       dword ptr [ecx + 0x30], eax
00436517  51                       push      ecx
00436518  e8d3c00600               call      0x4a25f0 ; _jwe_isfm
0043651d  83c404                   add       esp, 4
00436520  6a50                     push      0x50
00436522  68a80f5700               push      0x570fa8
00436527  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
0043652d  8d08                     lea       ecx, [eax]
0043652f  51                       push      ecx
00436530  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
00436536  8d11                     lea       edx, [ecx]
00436538  52                       push      edx
00436539  e8a2630100               call      0x44c8e0 ; _inline_
0043653e  83c410                   add       esp, 0x10
00436541  68dc095700               push      0x5709dc
00436546  e805b60600               call      0x4a1b50 ; _jwe_iinf
0043654b  83c404                   add       esp, 4
0043654e  85c0                     test      eax, eax
00436550  0f85ab0c0000             jne       0x437201
00436556  68d0095700               push      0x5709d0
0043655b  e8f0b50600               call      0x4a1b50 ; _jwe_iinf
00436560  83c404                   add       esp, 4
00436563  85c0                     test      eax, eax
00436565  0f85960c0000             jne       0x437201
0043656b  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436571  8b08                     mov       ecx, dword ptr [eax]
00436573  8b15b40e5700             mov       edx, dword ptr [0x570eb4] ; bits=00000000, f32=0.0
00436579  8d1da4095700             lea       ebx, [0x5709a4] ; bits=09020000, f32=7.300764999132297e-43
0043657f  894dfc                   mov       dword ptr [ebp - 4], ecx
00436582  8d4dfc                   lea       ecx, [ebp - 4]
00436585  894b08                   mov       dword ptr [ebx + 8], ecx
00436588  8955f8                   mov       dword ptr [ebp - 8], edx
0043658b  8d4df8                   lea       ecx, [ebp - 8]
0043658e  894b28                   mov       dword ptr [ebx + 0x28], ecx
00436591  53                       push      ebx
00436592  e859c00600               call      0x4a25f0 ; _jwe_isfm
00436597  83c404                   add       esp, 4
0043659a  6a50                     push      0x50
0043659c  68a80f5700               push      0x570fa8
004365a1  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004365a7  8d08                     lea       ecx, [eax]
004365a9  51                       push      ecx
004365aa  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
004365b0  8d11                     lea       edx, [ecx]
004365b2  52                       push      edx
004365b3  e828630100               call      0x44c8e0 ; _inline_
004365b8  83c410                   add       esp, 0x10
004365bb  6884095700               push      0x570984
004365c0  e88bb50600               call      0x4a1b50 ; _jwe_iinf
004365c5  83c404                   add       esp, 4
004365c8  85c0                     test      eax, eax
004365ca  0f85310c0000             jne       0x437201
004365d0  6878095700               push      0x570978
004365d5  e876b50600               call      0x4a1b50 ; _jwe_iinf
004365da  83c404                   add       esp, 4
004365dd  85c0                     test      eax, eax
004365df  0f851c0c0000             jne       0x437201
004365e5  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004365eb  8b18                     mov       ebx, dword ptr [eax]
004365ed  8b0db80e5700             mov       ecx, dword ptr [0x570eb8] ; bits=00000000, f32=0.0
004365f3  8d154c095700             lea       edx, [0x57094c] ; bits=09020000, f32=7.300764999132297e-43
004365f9  895dfc                   mov       dword ptr [ebp - 4], ebx
004365fc  8d75fc                   lea       esi, [ebp - 4]
004365ff  897208                   mov       dword ptr [edx + 8], esi
00436602  894df8                   mov       dword ptr [ebp - 8], ecx
00436605  8d4df8                   lea       ecx, [ebp - 8]
00436608  894a28                   mov       dword ptr [edx + 0x28], ecx
0043660b  52                       push      edx
0043660c  e8dfbf0600               call      0x4a25f0 ; _jwe_isfm
00436611  83c404                   add       esp, 4
00436614  d905b80e5700             fld       dword ptr [0x570eb8] ; bits=00000000, f32=0.0
0043661a  d905fc005700             fld       dword ptr [0x5700fc] ; bits=000080bf, f32=-1.0
00436620  db7d90                   fstp      xword ptr [ebp - 0x70]
00436623  db6d90                   fld       xword ptr [ebp - 0x70]
00436626  d9c9                     fxch      st(1)
00436628  d8d1                     fcom      st(1)
0043662a  ddd9                     fstp      st(1)
0043662c  dfe0                     fnstsw    ax
0043662e  9e                       sahf
0043662f  0f8a21000000             jp        0x436656
00436635  731f                     jae       0x436656
00436637  ddd8                     fstp      st(0)
00436639  8d0520095700             lea       eax, [0x570920] ; bits=09820000, f32=4.664782457890884e-41
0043663f  895dfc                   mov       dword ptr [ebp - 4], ebx
00436642  8d4dfc                   lea       ecx, [ebp - 4]
00436645  894808                   mov       dword ptr [eax + 8], ecx
00436648  50                       push      eax
00436649  e832c80600               call      0x4a2e80 ; _jwe_ilst
0043664e  83c404                   add       esp, 4
00436651  e92c010000               jmp       0x436782
00436656  db6d90                   fld       xword ptr [ebp - 0x70]
00436659  d9c9                     fxch      st(1)
0043665b  dde1                     fucom     st(1)
0043665d  ddd9                     fstp      st(1)
0043665f  dfe0                     fnstsw    ax
00436661  9e                       sahf
00436662  0f8a21000000             jp        0x436689
00436668  751f                     jne       0x436689
0043666a  ddd8                     fstp      st(0)
0043666c  8d05f4085700             lea       eax, [0x5708f4] ; bits=09820000, f32=4.664782457890884e-41
00436672  895dfc                   mov       dword ptr [ebp - 4], ebx
00436675  8d4dfc                   lea       ecx, [ebp - 4]
00436678  894808                   mov       dword ptr [eax + 8], ecx
0043667b  50                       push      eax
0043667c  e8ffc70600               call      0x4a2e80 ; _jwe_ilst
00436681  83c404                   add       esp, 4
00436684  e9f9000000               jmp       0x436782
00436689  d9c0                     fld       st(0)
0043668b  d9ee                     fldz
0043668d  d9c9                     fxch      st(1)
0043668f  d81df0005700             fcomp     dword ptr [0x5700f0] ; bits=00000000, f32=0.0
00436695  db7d84                   fstp      xword ptr [ebp - 0x7c]
00436698  dfe0                     fnstsw    ax
0043669a  9e                       sahf
0043669b  0f8a21000000             jp        0x4366c2
004366a1  731f                     jae       0x4366c2
004366a3  ddd8                     fstp      st(0)
004366a5  8d05c8085700             lea       eax, [0x5708c8] ; bits=09820000, f32=4.664782457890884e-41
004366ab  895dfc                   mov       dword ptr [ebp - 4], ebx
004366ae  8d4dfc                   lea       ecx, [ebp - 4]
004366b1  894808                   mov       dword ptr [eax + 8], ecx
004366b4  50                       push      eax
004366b5  e8c6c70600               call      0x4a2e80 ; _jwe_ilst
004366ba  83c404                   add       esp, 4
004366bd  e9c0000000               jmp       0x436782
004366c2  db6d84                   fld       xword ptr [ebp - 0x7c]
004366c5  d9c9                     fxch      st(1)
004366c7  dae9                     fucompp
004366c9  dfe0                     fnstsw    ax
004366cb  9e                       sahf
004366cc  0f8a1f000000             jp        0x4366f1
004366d2  751d                     jne       0x4366f1
004366d4  8d059c085700             lea       eax, [0x57089c] ; bits=09820000, f32=4.664782457890884e-41
004366da  895dfc                   mov       dword ptr [ebp - 4], ebx
004366dd  8d4dfc                   lea       ecx, [ebp - 4]
004366e0  894808                   mov       dword ptr [eax + 8], ecx
004366e3  50                       push      eax
004366e4  e897c70600               call      0x4a2e80 ; _jwe_ilst
004366e9  83c404                   add       esp, 4
004366ec  e991000000               jmp       0x436782
004366f1  d905b80e5700             fld       dword ptr [0x570eb8] ; bits=00000000, f32=0.0
004366f7  d9e8                     fld1
004366f9  d9c9                     fxch      st(1)
004366fb  d815f8005700             fcom      dword ptr [0x5700f8] ; bits=0000803f, f32=1.0
00436701  d9c9                     fxch      st(1)
00436703  dfe0                     fnstsw    ax
00436705  9e                       sahf
00436706  0f8a20000000             jp        0x43672c
0043670c  731e                     jae       0x43672c
0043670e  ddd8                     fstp      st(0)
00436710  ddd8                     fstp      st(0)
00436712  8d0564085700             lea       eax, [0x570864] ; bits=09820000, f32=4.664782457890884e-41
00436718  895dfc                   mov       dword ptr [ebp - 4], ebx
0043671b  8d4dfc                   lea       ecx, [ebp - 4]
0043671e  894808                   mov       dword ptr [eax + 8], ecx
00436721  50                       push      eax
00436722  e859c70600               call      0x4a2e80 ; _jwe_ilst
00436727  83c404                   add       esp, 4
0043672a  eb56                     jmp       0x436782
0043672c  d9c9                     fxch      st(1)
0043672e  dde1                     fucom     st(1)
00436730  d9c9                     fxch      st(1)
00436732  dfe0                     fnstsw    ax
00436734  9e                       sahf
00436735  0f8a20000000             jp        0x43675b
0043673b  751e                     jne       0x43675b
0043673d  ddd8                     fstp      st(0)
0043673f  ddd8                     fstp      st(0)
00436741  8d0538085700             lea       eax, [0x570838] ; bits=09820000, f32=4.664782457890884e-41
00436747  895dfc                   mov       dword ptr [ebp - 4], ebx
0043674a  8d4dfc                   lea       ecx, [ebp - 4]
0043674d  894808                   mov       dword ptr [eax + 8], ecx
00436750  50                       push      eax
00436751  e82ac70600               call      0x4a2e80 ; _jwe_ilst
00436756  83c404                   add       esp, 4
00436759  eb27                     jmp       0x436782
0043675b  d9c9                     fxch      st(1)
0043675d  ded9                     fcompp
0043675f  dfe0                     fnstsw    ax
00436761  9e                       sahf
00436762  0f8a1a000000             jp        0x436782
00436768  7618                     jbe       0x436782
0043676a  8d050c085700             lea       eax, [0x57080c] ; bits=09820000, f32=4.664782457890884e-41
00436770  895dfc                   mov       dword ptr [ebp - 4], ebx
00436773  8d4dfc                   lea       ecx, [ebp - 4]
00436776  894808                   mov       dword ptr [eax + 8], ecx
00436779  50                       push      eax
0043677a  e801c70600               call      0x4a2e80 ; _jwe_ilst
0043677f  83c404                   add       esp, 4
00436782  8d05e0075700             lea       eax, [0x5707e0] ; bits=09820000, f32=4.664782457890884e-41
00436788  895dfc                   mov       dword ptr [ebp - 4], ebx
0043678b  8d4dfc                   lea       ecx, [ebp - 4]
0043678e  894808                   mov       dword ptr [eax + 8], ecx
00436791  50                       push      eax
00436792  e8e9c60600               call      0x4a2e80 ; _jwe_ilst
00436797  83c404                   add       esp, 4
0043679a  6a50                     push      0x50
0043679c  68a80f5700               push      0x570fa8
004367a1  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004367a7  8d08                     lea       ecx, [eax]
004367a9  51                       push      ecx
004367aa  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
004367b0  8d11                     lea       edx, [ecx]
004367b2  52                       push      edx
004367b3  e828610100               call      0x44c8e0 ; _inline_
004367b8  83c410                   add       esp, 0x10
004367bb  68c0075700               push      0x5707c0
004367c0  e88bb30600               call      0x4a1b50 ; _jwe_iinf
004367c5  83c404                   add       esp, 4
004367c8  85c0                     test      eax, eax
004367ca  0f85310a0000             jne       0x437201
004367d0  68b4075700               push      0x5707b4
004367d5  e876b30600               call      0x4a1b50 ; _jwe_iinf
004367da  83c404                   add       esp, 4
004367dd  85c0                     test      eax, eax
004367df  0f851c0a0000             jne       0x437201
004367e5  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004367eb  8b08                     mov       ecx, dword ptr [eax]
004367ed  8d1588075700             lea       edx, [0x570788] ; bits=09020000, f32=7.300764999132297e-43
004367f3  894dfc                   mov       dword ptr [ebp - 4], ecx
004367f6  8d4dfc                   lea       ecx, [ebp - 4]
004367f9  894a08                   mov       dword ptr [edx + 8], ecx
004367fc  52                       push      edx
004367fd  e8eebd0600               call      0x4a25f0 ; _jwe_isfm
00436802  83c404                   add       esp, 4
00436805  6a50                     push      0x50
00436807  68a80f5700               push      0x570fa8
0043680c  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436812  8d08                     lea       ecx, [eax]
00436814  51                       push      ecx
00436815  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
0043681b  8d11                     lea       edx, [ecx]
0043681d  52                       push      edx
0043681e  e8bd600100               call      0x44c8e0 ; _inline_
00436823  83c410                   add       esp, 0x10
00436826  6868075700               push      0x570768
0043682b  e820b30600               call      0x4a1b50 ; _jwe_iinf
00436830  83c404                   add       esp, 4
00436833  85c0                     test      eax, eax
00436835  0f85c6090000             jne       0x437201
0043683b  6850075700               push      0x570750
00436840  e80bb30600               call      0x4a1b50 ; _jwe_iinf
00436845  83c404                   add       esp, 4
00436848  85c0                     test      eax, eax
0043684a  0f85b1090000             jne       0x437201
00436850  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436856  8b08                     mov       ecx, dword ptr [eax]
00436858  8b1d740e5700             mov       ebx, dword ptr [0x570e74] ; bits=00000000, f32=0.0
0043685e  8d1518075700             lea       edx, [0x570718] ; bits=09020000, f32=7.300764999132297e-43
00436864  894dfc                   mov       dword ptr [ebp - 4], ecx
00436867  8d4dfc                   lea       ecx, [ebp - 4]
0043686a  894a08                   mov       dword ptr [edx + 8], ecx
0043686d  895df0                   mov       dword ptr [ebp - 0x10], ebx
00436870  8d4df0                   lea       ecx, [ebp - 0x10]
00436873  894a34                   mov       dword ptr [edx + 0x34], ecx
00436876  52                       push      edx
00436877  e874bd0600               call      0x4a25f0 ; _jwe_isfm
0043687c  83c404                   add       esp, 4
0043687f  6a50                     push      0x50
00436881  68a80f5700               push      0x570fa8
00436886  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
0043688c  8d08                     lea       ecx, [eax]
0043688e  51                       push      ecx
0043688f  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
00436895  8d11                     lea       edx, [ecx]
00436897  52                       push      edx
00436898  e843600100               call      0x44c8e0 ; _inline_
0043689d  83c410                   add       esp, 0x10
004368a0  68f8065700               push      0x5706f8
004368a5  e8a6b20600               call      0x4a1b50 ; _jwe_iinf
004368aa  83c404                   add       esp, 4
004368ad  85c0                     test      eax, eax
004368af  0f854c090000             jne       0x437201
004368b5  68e0065700               push      0x5706e0
004368ba  e891b20600               call      0x4a1b50 ; _jwe_iinf
004368bf  83c404                   add       esp, 4
004368c2  85c0                     test      eax, eax
004368c4  0f8537090000             jne       0x437201
004368ca  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004368d0  8b08                     mov       ecx, dword ptr [eax]
004368d2  8b15b00e5700             mov       edx, dword ptr [0x570eb0] ; bits=00000000, f32=0.0
004368d8  8d35a8065700             lea       esi, [0x5706a8] ; bits=09020000, f32=7.300764999132297e-43
004368de  894dfc                   mov       dword ptr [ebp - 4], ecx
004368e1  8d4dfc                   lea       ecx, [ebp - 4]
004368e4  894e08                   mov       dword ptr [esi + 8], ecx
004368e7  8955f8                   mov       dword ptr [ebp - 8], edx
004368ea  8d4df8                   lea       ecx, [ebp - 8]
004368ed  894e34                   mov       dword ptr [esi + 0x34], ecx
004368f0  56                       push      esi
004368f1  e8fabc0600               call      0x4a25f0 ; _jwe_isfm
004368f6  83c404                   add       esp, 4
004368f9  89d8                     mov       eax, ebx
004368fb  3d00000000               cmp       eax, 0
00436900  8985ecfeffff             mov       dword ptr [ebp - 0x114], eax
00436906  0f8efb000000             jle       0x436a07
0043690c  bb01000000               mov       ebx, 1
00436911  8b05740e5700             mov       eax, dword ptr [0x570e74] ; bits=00000000, f32=0.0
00436917  48                       dec       eax
00436918  8945fc                   mov       dword ptr [ebp - 4], eax
0043691b  d9e8                     fld1
0043691d  da75fc                   fidiv     dword ptr [ebp - 4]
00436920  dbbd78ffffff             fstp      xword ptr [ebp - 0x88]
00436926  d9ee                     fldz
00436928  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
0043692e  83bdecfeffff02           cmp       dword ptr [ebp - 0x114], 2
00436935  0f8c99000000             jl        0x4369d4
0043693b  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00436941  dbad78ffffff             fld       xword ptr [ebp - 0x88]
00436947  db7dcc                   fstp      xword ptr [ebp - 0x34]
0043694a  db7dd8                   fstp      xword ptr [ebp - 0x28]
0043694d  db6dd8                   fld       xword ptr [ebp - 0x28]
00436950  db6dcc                   fld       xword ptr [ebp - 0x34]
00436953  dec9                     fmulp     st(1)
00436955  68b00e5700               push      0x570eb0
0043695a  d95df8                   fstp      dword ptr [ebp - 8]
0043695d  8d45f8                   lea       eax, [ebp - 8]
00436960  50                       push      eax
00436961  e84a9e0600               call      0x4a07b0 ; _g_arxr
00436966  83c408                   add       esp, 8
00436969  d91c9d08f57400           fstp      dword ptr [ebx*4 + 0x74f508]
00436970  db6dd8                   fld       xword ptr [ebp - 0x28]
00436973  d805f8005700             fadd      dword ptr [0x5700f8] ; bits=0000803f, f32=1.0
00436979  db7de4                   fstp      xword ptr [ebp - 0x1c]
0043697c  db6de4                   fld       xword ptr [ebp - 0x1c]
0043697f  db6dcc                   fld       xword ptr [ebp - 0x34]
00436982  dec9                     fmulp     st(1)
00436984  d95df8                   fstp      dword ptr [ebp - 8]
00436987  68b00e5700               push      0x570eb0
0043698c  8d45f8                   lea       eax, [ebp - 8]
0043698f  50                       push      eax
00436990  e81b9e0600               call      0x4a07b0 ; _g_arxr
00436995  83c408                   add       esp, 8
00436998  d91c9d0cf57400           fstp      dword ptr [ebx*4 + 0x74f50c]
0043699f  db6de4                   fld       xword ptr [ebp - 0x1c]
004369a2  d805f8005700             fadd      dword ptr [0x5700f8] ; bits=0000803f, f32=1.0
004369a8  db6dcc                   fld       xword ptr [ebp - 0x34]
004369ab  83c302                   add       ebx, 2
004369ae  8b85ecfeffff             mov       eax, dword ptr [ebp - 0x114]
004369b4  83e802                   sub       eax, 2
004369b7  3d02000000               cmp       eax, 2
004369bc  8985ecfeffff             mov       dword ptr [ebp - 0x114], eax
004369c2  0f8d7fffffff             jge       0x436947
004369c8  dbbd78ffffff             fstp      xword ptr [ebp - 0x88]
004369ce  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
004369d4  8b85ecfeffff             mov       eax, dword ptr [ebp - 0x114]
004369da  85c0                     test      eax, eax
004369dc  7429                     je        0x436a07
004369de  dbad6cffffff             fld       xword ptr [ebp - 0x94]
004369e4  dbad78ffffff             fld       xword ptr [ebp - 0x88]
004369ea  dec9                     fmulp     st(1)
004369ec  d95df8                   fstp      dword ptr [ebp - 8]
004369ef  68b00e5700               push      0x570eb0
004369f4  8d45f8                   lea       eax, [ebp - 8]
004369f7  50                       push      eax
004369f8  e8b39d0600               call      0x4a07b0 ; _g_arxr
004369fd  83c408                   add       esp, 8
00436a00  d91c9d08f57400           fstp      dword ptr [ebx*4 + 0x74f508]
00436a07  bb01000000               mov       ebx, 1
00436a0c  d905fc005700             fld       dword ptr [0x5700fc] ; bits=000080bf, f32=-1.0
00436a12  db7de4                   fstp      xword ptr [ebp - 0x1c]
00436a15  6a50                     push      0x50
00436a17  68a80f5700               push      0x570fa8
00436a1c  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436a22  8d08                     lea       ecx, [eax]
00436a24  51                       push      ecx
00436a25  8b8d48ffffff             mov       ecx, dword ptr [ebp - 0xb8]
00436a2b  8d11                     lea       edx, [ecx]
00436a2d  52                       push      edx
00436a2e  e8ad5e0100               call      0x44c8e0 ; _inline_
00436a33  83c410                   add       esp, 0x10
00436a36  6888065700               push      0x570688
00436a3b  e810b10600               call      0x4a1b50 ; _jwe_iinf
00436a40  db6de4                   fld       xword ptr [ebp - 0x1c]
00436a43  83c404                   add       esp, 4
00436a46  85c0                     test      eax, eax
00436a48  0f85ad070000             jne       0x4371fb
00436a4e  db7de4                   fstp      xword ptr [ebp - 0x1c]
00436a51  8d057c065700             lea       eax, [0x57067c] ; bits=61090000, f32=3.364517612843886e-42
00436a57  8d0db0b47100             lea       ecx, [0x71b4b0]
00436a5d  898de8feffff             mov       dword ptr [ebp - 0x118], ecx
00436a63  8d94997cffffff           lea       edx, [ecx + ebx*4 - 0x84]
00436a6a  895008                   mov       dword ptr [eax + 8], edx
00436a6d  50                       push      eax
00436a6e  e8ddb00600               call      0x4a1b50 ; _jwe_iinf
00436a73  db6de4                   fld       xword ptr [ebp - 0x1c]
00436a76  83c404                   add       esp, 4
00436a79  85c0                     test      eax, eax
00436a7b  0f857e070000             jne       0x4371ff
00436a81  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436a87  db7de4                   fstp      xword ptr [ebp - 0x1c]
00436a8a  8b08                     mov       ecx, dword ptr [eax]
00436a8c  8b95e8feffff             mov       edx, dword ptr [ebp - 0x118]
00436a92  898de4feffff             mov       dword ptr [ebp - 0x11c], ecx
00436a98  8bb49a7cffffff           mov       esi, dword ptr [edx + ebx*4 - 0x84]
00436a9f  8d3d50065700             lea       edi, [0x570650] ; bits=09020000, f32=7.300764999132297e-43
00436aa5  894dfc                   mov       dword ptr [ebp - 4], ecx
00436aa8  8d45fc                   lea       eax, [ebp - 4]
00436aab  894708                   mov       dword ptr [edi + 8], eax
00436aae  8975f8                   mov       dword ptr [ebp - 8], esi
00436ab1  8d45f8                   lea       eax, [ebp - 8]
00436ab4  894728                   mov       dword ptr [edi + 0x28], eax
00436ab7  57                       push      edi
00436ab8  e833bb0600               call      0x4a25f0 ; _jwe_isfm
00436abd  83c404                   add       esp, 4
00436ac0  8b85e8feffff             mov       eax, dword ptr [ebp - 0x118]
00436ac6  d984987cffffff           fld       dword ptr [eax + ebx*4 - 0x84]
00436acd  d815f0005700             fcom      dword ptr [0x5700f0] ; bits=00000000, f32=0.0
00436ad3  db6de4                   fld       xword ptr [ebp - 0x1c]
00436ad6  dfe0                     fnstsw    ax
00436ad8  9e                       sahf
00436ad9  0f8a14000000             jp        0x436af3
00436adf  7712                     ja        0x436af3
00436ae1  ddd8                     fstp      st(0)
00436ae3  ddd8                     fstp      st(0)
00436ae5  89d8                     mov       eax, ebx
00436ae7  48                       dec       eax
00436ae8  8905780e5700             mov       dword ptr [0x570e78], eax ; bits=00000000, f32=0.0
00436aee  e990000000               jmp       0x436b83
00436af3  d9c9                     fxch      st(1)
00436af5  d8d1                     fcom      st(1)
00436af7  ddd9                     fstp      st(1)
00436af9  dfe0                     fnstsw    ax
00436afb  9e                       sahf
00436afc  0f8a3b000000             jp        0x436b3d
00436b02  7739                     ja        0x436b3d
00436b04  db7de4                   fstp      xword ptr [ebp - 0x1c]
00436b07  8d0524065700             lea       eax, [0x570624] ; bits=09020000, f32=7.300764999132297e-43
00436b0d  8b8de4feffff             mov       ecx, dword ptr [ebp - 0x11c]
00436b13  894dfc                   mov       dword ptr [ebp - 4], ecx
00436b16  8d4dfc                   lea       ecx, [ebp - 4]
00436b19  894808                   mov       dword ptr [eax + 8], ecx
00436b1c  db6de4                   fld       xword ptr [ebp - 0x1c]
00436b1f  d95df8                   fstp      dword ptr [ebp - 8]
00436b22  8d4df8                   lea       ecx, [ebp - 8]
00436b25  894828                   mov       dword ptr [eax + 0x28], ecx
00436b28  50                       push      eax
00436b29  e8c2ba0600               call      0x4a25f0 ; _jwe_isfm
00436b2e  db6de4                   fld       xword ptr [ebp - 0x1c]
00436b31  83c404                   add       esp, 4
00436b34  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00436b37  c70001000000             mov       dword ptr [eax], 1
00436b3d  43                       inc       ebx
00436b3e  81fb97000000             cmp       ebx, 0x97
00436b44  0f8ec8feffff             jle       0x436a12
00436b4a  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436b50  db7de4                   fstp      xword ptr [ebp - 0x1c]
00436b53  8b08                     mov       ecx, dword ptr [eax]
00436b55  8d15f8055700             lea       edx, [0x5705f8] ; bits=09020000, f32=7.300764999132297e-43
00436b5b  894dfc                   mov       dword ptr [ebp - 4], ecx
00436b5e  8d4dfc                   lea       ecx, [ebp - 4]
00436b61  894a08                   mov       dword ptr [edx + 8], ecx
00436b64  52                       push      edx
00436b65  e886ba0600               call      0x4a25f0 ; _jwe_isfm
00436b6a  db6de4                   fld       xword ptr [ebp - 0x1c]
00436b6d  83c404                   add       esp, 4
00436b70  bb97000000               mov       ebx, 0x97
00436b75  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00436b78  c70001000000             mov       dword ptr [eax], 1
00436b7e  e98ffeffff               jmp       0x436a12
00436b83  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00436b86  833800                   cmp       dword ptr [eax], 0
00436b89  0f85b7060000             jne       0x437246
00436b8f  8d05d8055700             lea       eax, [0x5705d8] ; bits=69020000, f32=8.646011524884121e-43
00436b95  8b8de4feffff             mov       ecx, dword ptr [ebp - 0x11c]
00436b9b  894dfc                   mov       dword ptr [ebp - 4], ecx
00436b9e  8d4dfc                   lea       ecx, [ebp - 4]
00436ba1  894808                   mov       dword ptr [eax + 8], ecx
00436ba4  50                       push      eax
00436ba5  e846ba0600               call      0x4a25f0 ; _jwe_isfm
00436baa  83c404                   add       esp, 4
00436bad  833d880e570000           cmp       dword ptr [0x570e88], 0 ; bits=00000000, f32=0.0
00436bb4  7e6d                     jle       0x436c23
00436bb6  68840e5700               push      0x570e84
00436bbb  68880e5700               push      0x570e88
00436bc0  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436bc6  8d08                     lea       ecx, [eax]
00436bc8  51                       push      ecx
00436bc9  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00436bcc  8d09                     lea       ecx, [ecx]
00436bce  51                       push      ecx
00436bcf  e82c0d0000               call      0x437900 ; _chkcfc_
00436bd4  83c410                   add       esp, 0x10
00436bd7  833d840e570000           cmp       dword ptr [0x570e84], 0 ; bits=00000000, f32=0.0
00436bde  7443                     je        0x436c23
00436be0  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436be6  8b18                     mov       ebx, dword ptr [eax]
00436be8  68880e5700               push      0x570e88
00436bed  e80ebd0000               call      0x442900 ; _gettbn_
00436bf2  83c404                   add       esp, 4
00436bf5  8945fc                   mov       dword ptr [ebp - 4], eax
00436bf8  8d45fc                   lea       eax, [ebp - 4]
00436bfb  50                       push      eax
00436bfc  6a10                     push      0x10
00436bfe  68d8105700               push      0x5710d8
00436c03  e888070400               call      0x477390 ; _get_tabid_
00436c08  83c40c                   add       esp, 0xc
00436c0b  8d05ac055700             lea       eax, [0x5705ac] ; bits=09020000, f32=7.300764999132297e-43
00436c11  895dfc                   mov       dword ptr [ebp - 4], ebx
00436c14  8d4dfc                   lea       ecx, [ebp - 4]
00436c17  894808                   mov       dword ptr [eax + 8], ecx
00436c1a  50                       push      eax
00436c1b  e8d0b90600               call      0x4a25f0 ; _jwe_isfm
00436c20  83c404                   add       esp, 4
00436c23  833d8c0e570000           cmp       dword ptr [0x570e8c], 0 ; bits=00000000, f32=0.0
00436c2a  7e6d                     jle       0x436c99
00436c2c  68840e5700               push      0x570e84
00436c31  688c0e5700               push      0x570e8c
00436c36  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436c3c  8d08                     lea       ecx, [eax]
00436c3e  51                       push      ecx
00436c3f  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00436c42  8d09                     lea       ecx, [ecx]
00436c44  51                       push      ecx
00436c45  e8b60c0000               call      0x437900 ; _chkcfc_
00436c4a  83c410                   add       esp, 0x10
00436c4d  833d840e570000           cmp       dword ptr [0x570e84], 0 ; bits=00000000, f32=0.0
00436c54  7443                     je        0x436c99
00436c56  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436c5c  8b18                     mov       ebx, dword ptr [eax]
00436c5e  688c0e5700               push      0x570e8c
00436c63  e898bc0000               call      0x442900 ; _gettbn_
00436c68  83c404                   add       esp, 4
00436c6b  8945fc                   mov       dword ptr [ebp - 4], eax
00436c6e  8d45fc                   lea       eax, [ebp - 4]
00436c71  50                       push      eax
00436c72  6a10                     push      0x10
00436c74  68e8105700               push      0x5710e8
00436c79  e812070400               call      0x477390 ; _get_tabid_
00436c7e  83c40c                   add       esp, 0xc
00436c81  8d0580055700             lea       eax, [0x570580] ; bits=09020000, f32=7.300764999132297e-43
00436c87  895dfc                   mov       dword ptr [ebp - 4], ebx
00436c8a  8d4dfc                   lea       ecx, [ebp - 4]
00436c8d  894808                   mov       dword ptr [eax + 8], ecx
00436c90  50                       push      eax
00436c91  e85ab90600               call      0x4a25f0 ; _jwe_isfm
00436c96  83c404                   add       esp, 4
00436c99  dd05400e5700             fld       qword ptr [0x570e40] ; bits=0000000000000000, f64=0.0
00436c9f  8d1d60015700             lea       ebx, [0x570160] ; bits=64000000, f32=1.401298464324817e-43
00436ca5  dc5b88                   fcomp     qword ptr [ebx - 0x78]
00436ca8  dfe0                     fnstsw    ax
00436caa  9e                       sahf
00436cab  0f8a24010000             jp        0x436dd5
00436cb1  0f871e010000             ja        0x436dd5
00436cb7  68580e5700               push      0x570e58
00436cbc  68500e5700               push      0x570e50
00436cc1  68880e5700               push      0x570e88
00436cc6  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436ccc  8d08                     lea       ecx, [eax]
00436cce  51                       push      ecx
00436ccf  e86c860000               call      0x43f340 ; _get_east_north_
00436cd4  83c410                   add       esp, 0x10
00436cd7  68680e5700               push      0x570e68
00436cdc  68600e5700               push      0x570e60
00436ce1  688c0e5700               push      0x570e8c
00436ce6  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436cec  8d08                     lea       ecx, [eax]
00436cee  51                       push      ecx
00436cef  e84c860000               call      0x43f340 ; _get_east_north_
00436cf4  83c410                   add       esp, 0x10
00436cf7  dd05500e5700             fld       qword ptr [0x570e50] ; bits=0000000000000000, f64=0.0
00436cfd  dd9560ffffff             fst       qword ptr [ebp - 0xa0]
00436d03  dc5b88                   fcomp     qword ptr [ebx - 0x78]
00436d06  dfe0                     fnstsw    ax
00436d08  9e                       sahf
00436d09  0f8a80000000             jp        0x436d8f
00436d0f  767e                     jbe       0x436d8f
00436d11  dd05600e5700             fld       qword ptr [0x570e60] ; bits=0000000000000000, f64=0.0
00436d17  89d8                     mov       eax, ebx
00436d19  dc5088                   fcom      qword ptr [eax - 0x78]
00436d1c  dd9d58ffffff             fstp      qword ptr [ebp - 0xa8]
00436d22  dfe0                     fnstsw    ax
00436d24  9e                       sahf
00436d25  0f8a32000000             jp        0x436d5d
00436d2b  7630                     jbe       0x436d5d
00436d2d  dd8560ffffff             fld       qword ptr [ebp - 0xa0]
00436d33  dc8558ffffff             fadd      qword ptr [ebp - 0xa8]
00436d39  89d8                     mov       eax, ebx
00436d3b  dc4880                   fmul      qword ptr [eax - 0x80]
00436d3e  dd1d400e5700             fstp      qword ptr [0x570e40] ; bits=0000000000000000, f64=0.0
00436d44  dd05580e5700             fld       qword ptr [0x570e58] ; bits=0000000000000000, f64=0.0
00436d4a  dc05680e5700             fadd      qword ptr [0x570e68] ; bits=0000000000000000, f64=0.0
00436d50  89d8                     mov       eax, ebx
00436d52  dc4880                   fmul      qword ptr [eax - 0x80]
00436d55  dd1d480e5700             fstp      qword ptr [0x570e48] ; bits=0000000000000000, f64=0.0
00436d5b  eb78                     jmp       0x436dd5
00436d5d  8b05500e5700             mov       eax, dword ptr [0x570e50] ; bits=00000000, f32=0.0
00436d63  8b0d540e5700             mov       ecx, dword ptr [0x570e54] ; bits=00000000, f32=0.0
00436d69  8905400e5700             mov       dword ptr [0x570e40], eax ; bits=00000000, f32=0.0
00436d6f  890d440e5700             mov       dword ptr [0x570e44], ecx ; bits=00000000, f32=0.0
00436d75  8b05580e5700             mov       eax, dword ptr [0x570e58] ; bits=00000000, f32=0.0
00436d7b  8b0d5c0e5700             mov       ecx, dword ptr [0x570e5c] ; bits=00000000, f32=0.0
00436d81  8905480e5700             mov       dword ptr [0x570e48], eax ; bits=00000000, f32=0.0
00436d87  890d4c0e5700             mov       dword ptr [0x570e4c], ecx ; bits=00000000, f32=0.0
00436d8d  eb46                     jmp       0x436dd5
00436d8f  dd05600e5700             fld       qword ptr [0x570e60] ; bits=0000000000000000, f64=0.0
00436d95  89d8                     mov       eax, ebx
00436d97  dc5888                   fcomp     qword ptr [eax - 0x78]
00436d9a  dfe0                     fnstsw    ax
00436d9c  9e                       sahf
00436d9d  0f8a32000000             jp        0x436dd5
00436da3  7630                     jbe       0x436dd5
00436da5  8b05600e5700             mov       eax, dword ptr [0x570e60] ; bits=00000000, f32=0.0
00436dab  8b0d640e5700             mov       ecx, dword ptr [0x570e64] ; bits=00000000, f32=0.0
00436db1  8905400e5700             mov       dword ptr [0x570e40], eax ; bits=00000000, f32=0.0
00436db7  890d440e5700             mov       dword ptr [0x570e44], ecx ; bits=00000000, f32=0.0
00436dbd  8b05680e5700             mov       eax, dword ptr [0x570e68] ; bits=00000000, f32=0.0
00436dc3  8b0d6c0e5700             mov       ecx, dword ptr [0x570e6c] ; bits=00000000, f32=0.0
00436dc9  8905480e5700             mov       dword ptr [0x570e48], eax ; bits=00000000, f32=0.0
00436dcf  890d4c0e5700             mov       dword ptr [0x570e4c], ecx ; bits=00000000, f32=0.0
00436dd5  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436ddb  8b18                     mov       ebx, dword ptr [eax]
00436ddd  8d0d60055700             lea       ecx, [0x570560] ; bits=69020000, f32=8.646011524884121e-43
00436de3  895dfc                   mov       dword ptr [ebp - 4], ebx
00436de6  8d55fc                   lea       edx, [ebp - 4]
00436de9  895108                   mov       dword ptr [ecx + 8], edx
00436dec  51                       push      ecx
00436ded  e8feb70600               call      0x4a25f0 ; _jwe_isfm
00436df2  83c404                   add       esp, 4
00436df5  d905c80e5700             fld       dword ptr [0x570ec8] ; bits=00000000, f32=0.0
00436dfb  d815c40e5700             fcom      dword ptr [0x570ec4] ; bits=00000000, f32=0.0
00436e01  dfe0                     fnstsw    ax
00436e03  66a90041                 test      ax, 0x4100
00436e07  7408                     je        0x436e11
00436e09  ddd8                     fstp      st(0)
00436e0b  d905c40e5700             fld       dword ptr [0x570ec4] ; bits=00000000, f32=0.0
00436e11  d91d9c0e5700             fstp      dword ptr [0x570e9c] ; bits=00000000, f32=0.0
00436e17  8b059c0e5700             mov       eax, dword ptr [0x570e9c] ; bits=00000000, f32=0.0
00436e1d  8d0d34055700             lea       ecx, [0x570534] ; bits=09020000, f32=7.300764999132297e-43
00436e23  895dfc                   mov       dword ptr [ebp - 4], ebx
00436e26  8d55fc                   lea       edx, [ebp - 4]
00436e29  895108                   mov       dword ptr [ecx + 8], edx
00436e2c  8945f8                   mov       dword ptr [ebp - 8], eax
00436e2f  8d45f8                   lea       eax, [ebp - 8]
00436e32  894128                   mov       dword ptr [ecx + 0x28], eax
00436e35  51                       push      ecx
00436e36  e8b5b70600               call      0x4a25f0 ; _jwe_isfm
00436e3b  83c404                   add       esp, 4
00436e3e  d905c00e5700             fld       dword ptr [0x570ec0] ; bits=00000000, f32=0.0
00436e44  d82dbc0e5700             fsubr     dword ptr [0x570ebc] ; bits=00000000, f32=0.0
00436e4a  d9e1                     fabs
00436e4c  d91d980e5700             fstp      dword ptr [0x570e98] ; bits=00000000, f32=0.0
00436e52  d905980e5700             fld       dword ptr [0x570e98] ; bits=00000000, f32=0.0
00436e58  d9ee                     fldz
00436e5a  d9c9                     fxch      st(1)
00436e5c  dae9                     fucompp
00436e5e  dfe0                     fnstsw    ax
00436e60  9e                       sahf
00436e61  0f8a1a000000             jp        0x436e81
00436e67  7518                     jne       0x436e81
00436e69  8d0514055700             lea       eax, [0x570514] ; bits=69020000, f32=8.646011524884121e-43
00436e6f  895dfc                   mov       dword ptr [ebp - 4], ebx
00436e72  8d4dfc                   lea       ecx, [ebp - 4]
00436e75  894808                   mov       dword ptr [eax + 8], ecx
00436e78  50                       push      eax
00436e79  e872b70600               call      0x4a25f0 ; _jwe_isfm
00436e7e  83c404                   add       esp, 4
00436e81  8d05f4045700             lea       eax, [0x5704f4] ; bits=69020000, f32=8.646011524884121e-43
00436e87  895dfc                   mov       dword ptr [ebp - 4], ebx
00436e8a  8d4dfc                   lea       ecx, [ebp - 4]
00436e8d  894808                   mov       dword ptr [eax + 8], ecx
00436e90  50                       push      eax
00436e91  e85ab70600               call      0x4a25f0 ; _jwe_isfm
00436e96  83c404                   add       esp, 4
00436e99  6888fa7400               push      0x74fa88
00436e9e  68e8b87100               push      0x71b8e8
00436ea3  688cb67100               push      0x71b68c
00436ea8  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00436eab  8d00                     lea       eax, [eax]
00436ead  50                       push      eax
00436eae  680cf57400               push      0x74f50c
00436eb3  68740e5700               push      0x570e74
00436eb8  6830b47100               push      0x71b430
00436ebd  689c0e5700               push      0x570e9c
00436ec2  68780e5700               push      0x570e78
00436ec7  68ac0e5700               push      0x570eac
00436ecc  68a40e5700               push      0x570ea4
00436ed1  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00436ed4  8d00                     lea       eax, [eax]
00436ed6  50                       push      eax
00436ed7  68b80e5700               push      0x570eb8
00436edc  68b40e5700               push      0x570eb4
00436ee1  68980e5700               push      0x570e98
00436ee6  68c80e5700               push      0x570ec8
00436eeb  688c0e5700               push      0x570e8c
00436ef0  68c40e5700               push      0x570ec4
00436ef5  68880e5700               push      0x570e88
00436efa  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436f00  8d08                     lea       ecx, [eax]
00436f02  51                       push      ecx
00436f03  e8a8ddffff               call      0x434cb0 ; _fndect_
00436f08  83c450                   add       esp, 0x50
00436f0b  d9ee                     fldz
00436f0d  dbbd4cffffff             fstp      xword ptr [ebp - 0xb4]
00436f13  8b05780e5700             mov       eax, dword ptr [0x570e78] ; bits=00000000, f32=0.0
00436f19  3d00000000               cmp       eax, 0
00436f1e  8985e0feffff             mov       dword ptr [ebp - 0x120], eax
00436f24  7e6f                     jle       0x436f95
00436f26  bb01000000               mov       ebx, 1
00436f2b  dbad4cffffff             fld       xword ptr [ebp - 0xb4]
00436f31  d9049d84fa7400           fld       dword ptr [ebx*4 + 0x74fa84]
00436f38  d8d1                     fcom      st(1)
00436f3a  ddd9                     fstp      st(1)
00436f3c  dfe0                     fnstsw    ax
00436f3e  9e                       sahf
00436f3f  0f8a44000000             jp        0x436f89
00436f45  7342                     jae       0x436f89
00436f47  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00436f4d  db7de4                   fstp      xword ptr [ebp - 0x1c]
00436f50  8b08                     mov       ecx, dword ptr [eax]
00436f52  8b149d2cb47100           mov       edx, dword ptr [ebx*4 + 0x71b42c]
00436f59  8d35bc045700             lea       esi, [0x5704bc] ; bits=09020000, f32=7.300764999132297e-43
00436f5f  894dfc                   mov       dword ptr [ebp - 4], ecx
00436f62  8d4dfc                   lea       ecx, [ebp - 4]
00436f65  894e08                   mov       dword ptr [esi + 8], ecx
00436f68  db6de4                   fld       xword ptr [ebp - 0x1c]
00436f6b  d95df8                   fstp      dword ptr [ebp - 8]
00436f6e  8d4df8                   lea       ecx, [ebp - 8]
00436f71  894e28                   mov       dword ptr [esi + 0x28], ecx
00436f74  8955f4                   mov       dword ptr [ebp - 0xc], edx
00436f77  8d4df4                   lea       ecx, [ebp - 0xc]
00436f7a  894e34                   mov       dword ptr [esi + 0x34], ecx
00436f7d  56                       push      esi
00436f7e  e86db60600               call      0x4a25f0 ; _jwe_isfm
00436f83  db6de4                   fld       xword ptr [ebp - 0x1c]
00436f86  83c404                   add       esp, 4
00436f89  43                       inc       ebx
00436f8a  83ade0feffff01           sub       dword ptr [ebp - 0x120], 1
00436f91  759e                     jne       0x436f31
00436f93  ddd8                     fstp      st(0)
00436f95  c705cc0e570000000000     mov       dword ptr [0x570ecc], 0 ; bits=00000000, f32=0.0
00436f9f  6a08                     push      8
00436fa1  6a08                     push      8
00436fa3  6a08                     push      8
00436fa5  6a08                     push      8
00436fa7  6a08                     push      8
00436fa9  6a08                     push      8
00436fab  6a32                     push      0x32
00436fad  8b5d1c                   mov       ebx, dword ptr [ebp + 0x1c]
00436fb0  8d03                     lea       eax, [ebx]
00436fb2  50                       push      eax
00436fb3  68480e5700               push      0x570e48
00436fb8  68400e5700               push      0x570e40
00436fbd  6870105700               push      0x571070
00436fc2  6868105700               push      0x571068
00436fc7  6860105700               push      0x571060
00436fcc  6858105700               push      0x571058
00436fd1  6850105700               push      0x571050
00436fd6  68cc0e5700               push      0x570ecc
00436fdb  6808035700               push      0x570308
00436fe0  687c0e5700               push      0x570e7c
00436fe5  689c0e5700               push      0x570e9c
00436fea  68e8b87100               push      0x71b8e8
00436fef  680cf57400               push      0x74f50c
00436ff4  8d05b0b47100             lea       eax, [0x71b4b0]
00436ffa  8985dcfeffff             mov       dword ptr [ebp - 0x124], eax
00437000  8d4880                   lea       ecx, [eax - 0x80]
00437003  51                       push      ecx
00437004  6888fa7400               push      0x74fa88
00437009  68740e5700               push      0x570e74
0043700e  68780e5700               push      0x570e78
00437013  68700f5700               push      0x570f70
00437018  68800e5700               push      0x570e80
0043701d  8b8d40ffffff             mov       ecx, dword ptr [ebp - 0xc0]
00437023  8d11                     lea       edx, [ecx]
00437025  52                       push      edx
00437026  8b9544ffffff             mov       edx, dword ptr [ebp - 0xbc]
0043702c  8d32                     lea       esi, [edx]
0043702e  56                       push      esi
0043702f  e88c250400               call      0x4795c0 ; _twdout_
00437034  83c474                   add       esp, 0x74
00437037  833d700e570000           cmp       dword ptr [0x570e70], 0 ; bits=00000000, f32=0.0
0043703e  0f8e02020000             jle       0x437246
00437044  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
0043704a  8b08                     mov       ecx, dword ptr [eax]
0043704c  8d159c045700             lea       edx, [0x57049c] ; bits=69020000, f32=8.646011524884121e-43
00437052  894dfc                   mov       dword ptr [ebp - 4], ecx
00437055  8d4dfc                   lea       ecx, [ebp - 4]
00437058  894a08                   mov       dword ptr [edx + 8], ecx
0043705b  52                       push      edx
0043705c  e88fb50600               call      0x4a25f0 ; _jwe_isfm
00437061  83c404                   add       esp, 4
00437064  6888fa7400               push      0x74fa88
00437069  68e8b87100               push      0x71b8e8
0043706e  688cb67100               push      0x71b68c
00437073  8d03                     lea       eax, [ebx]
00437075  50                       push      eax
00437076  680cf57400               push      0x74f50c
0043707b  68740e5700               push      0x570e74
00437080  8b85dcfeffff             mov       eax, dword ptr [ebp - 0x124]
00437086  8d4880                   lea       ecx, [eax - 0x80]
00437089  51                       push      ecx
0043708a  689c0e5700               push      0x570e9c
0043708f  68780e5700               push      0x570e78
00437094  68a80e5700               push      0x570ea8
00437099  68a00e5700               push      0x570ea0
0043709e  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004370a1  8d00                     lea       eax, [eax]
004370a3  50                       push      eax
004370a4  68b80e5700               push      0x570eb8
004370a9  68b40e5700               push      0x570eb4
004370ae  68980e5700               push      0x570e98
004370b3  68c40e5700               push      0x570ec4
004370b8  68880e5700               push      0x570e88
004370bd  68c80e5700               push      0x570ec8
004370c2  688c0e5700               push      0x570e8c
004370c7  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004370cd  8d08                     lea       ecx, [eax]
004370cf  51                       push      ecx
004370d0  e8dbdbffff               call      0x434cb0 ; _fndect_
004370d5  83c450                   add       esp, 0x50
004370d8  d9ee                     fldz
004370da  dbbd4cffffff             fstp      xword ptr [ebp - 0xb4]
004370e0  8b05780e5700             mov       eax, dword ptr [0x570e78] ; bits=00000000, f32=0.0
004370e6  3d00000000               cmp       eax, 0
004370eb  8985d8feffff             mov       dword ptr [ebp - 0x128], eax
004370f1  7e6f                     jle       0x437162
004370f3  bb01000000               mov       ebx, 1
004370f8  dbad4cffffff             fld       xword ptr [ebp - 0xb4]
004370fe  d9049d84fa7400           fld       dword ptr [ebx*4 + 0x74fa84]
00437105  d8d1                     fcom      st(1)
00437107  ddd9                     fstp      st(1)
00437109  dfe0                     fnstsw    ax
0043710b  9e                       sahf
0043710c  0f8a44000000             jp        0x437156
00437112  7342                     jae       0x437156
00437114  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
0043711a  db7de4                   fstp      xword ptr [ebp - 0x1c]
0043711d  8b08                     mov       ecx, dword ptr [eax]
0043711f  8b149d2cb47100           mov       edx, dword ptr [ebx*4 + 0x71b42c]
00437126  8d3564045700             lea       esi, [0x570464] ; bits=09020000, f32=7.300764999132297e-43
0043712c  894dfc                   mov       dword ptr [ebp - 4], ecx
0043712f  8d4dfc                   lea       ecx, [ebp - 4]
00437132  894e08                   mov       dword ptr [esi + 8], ecx
00437135  db6de4                   fld       xword ptr [ebp - 0x1c]
00437138  d95df8                   fstp      dword ptr [ebp - 8]
0043713b  8d4df8                   lea       ecx, [ebp - 8]
0043713e  894e28                   mov       dword ptr [esi + 0x28], ecx
00437141  8955f4                   mov       dword ptr [ebp - 0xc], edx
00437144  8d4df4                   lea       ecx, [ebp - 0xc]
00437147  894e34                   mov       dword ptr [esi + 0x34], ecx
0043714a  56                       push      esi
0043714b  e8a0b40600               call      0x4a25f0 ; _jwe_isfm
00437150  db6de4                   fld       xword ptr [ebp - 0x1c]
00437153  83c404                   add       esp, 4
00437156  43                       inc       ebx
00437157  83add8feffff01           sub       dword ptr [ebp - 0x128], 1
0043715e  759e                     jne       0x4370fe
00437160  ddd8                     fstp      st(0)
00437162  c705cc0e570000000000     mov       dword ptr [0x570ecc], 0 ; bits=00000000, f32=0.0
0043716c  6a08                     push      8
0043716e  6a08                     push      8
00437170  6a08                     push      8
00437172  6a08                     push      8
00437174  6a08                     push      8
00437176  6a08                     push      8
00437178  6a32                     push      0x32
0043717a  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0043717d  8d00                     lea       eax, [eax]
0043717f  50                       push      eax
00437180  68480e5700               push      0x570e48
00437185  68400e5700               push      0x570e40
0043718a  6870105700               push      0x571070
0043718f  6868105700               push      0x571068
00437194  6860105700               push      0x571060
00437199  6858105700               push      0x571058
0043719e  6850105700               push      0x571050
004371a3  68cc0e5700               push      0x570ecc
004371a8  6808035700               push      0x570308
004371ad  687c0e5700               push      0x570e7c
004371b2  689c0e5700               push      0x570e9c
004371b7  68e8b87100               push      0x71b8e8
004371bc  680cf57400               push      0x74f50c
004371c1  6830b47100               push      0x71b430
004371c6  6888fa7400               push      0x74fa88
004371cb  68740e5700               push      0x570e74
004371d0  68780e5700               push      0x570e78
004371d5  68380f5700               push      0x570f38
004371da  68700e5700               push      0x570e70
004371df  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004371e5  8d08                     lea       ecx, [eax]
004371e7  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
004371ed  51                       push      ecx
004371ee  8d08                     lea       ecx, [eax]
004371f0  51                       push      ecx
004371f1  e8ca230400               call      0x4795c0 ; _twdout_
004371f6  83c474                   add       esp, 0x74
004371f9  eb4b                     jmp       0x437246
004371fb  ddd8                     fstp      st(0)
004371fd  eb02                     jmp       0x437201
004371ff  ddd8                     fstp      st(0)
00437201  8b8544ffffff             mov       eax, dword ptr [ebp - 0xbc]
00437207  8b18                     mov       ebx, dword ptr [eax]
00437209  8d0538045700             lea       eax, [0x570438] ; bits=09820000, f32=4.664782457890884e-41
0043720f  895dfc                   mov       dword ptr [ebp - 4], ebx
00437212  8d4dfc                   lea       ecx, [ebp - 4]
00437215  894808                   mov       dword ptr [eax + 8], ecx
00437218  50                       push      eax
00437219  e862bc0600               call      0x4a2e80 ; _jwe_ilst
0043721e  83c404                   add       esp, 4
00437221  8d050c045700             lea       eax, [0x57040c] ; bits=09820000, f32=4.664782457890884e-41
00437227  895dfc                   mov       dword ptr [ebp - 4], ebx
0043722a  8d4dfc                   lea       ecx, [ebp - 4]
0043722d  894808                   mov       dword ptr [eax + 8], ecx
00437230  50                       push      eax
00437231  e84abc0600               call      0x4a2e80 ; _jwe_ilst
00437236  83c404                   add       esp, 4
00437239  6888035700               push      0x570388
0043723e  e8fdc10600               call      0x4a3440 ; _jwe_xstp
00437243  83c404                   add       esp, 4
00437246  b800000000               mov       eax, 0
0043724b  5f                       pop       edi
0043724c  5e                       pop       esi
0043724d  5b                       pop       ebx
0043724e  8be5                     mov       esp, ebp
00437250  5d                       pop       ebp
00437251  c3                       ret
00437252  8da42400000000           lea       esp, [esp]
00437259  8da42400000000           lea       esp, [esp]
