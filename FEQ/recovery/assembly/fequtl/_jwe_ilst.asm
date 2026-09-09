; _jwe_ilst
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xa2e80
004a2e80  55                       push      ebp
004a2e81  8bec                     mov       ebp, esp
004a2e83  83ec10                   sub       esp, 0x10
004a2e86  a12828b300               mov       eax, dword ptr [0xb32828] ; _jwe_x_init
004a2e8b  53                       push      ebx
004a2e8c  56                       push      esi
004a2e8d  57                       push      edi
004a2e8e  33ff                     xor       edi, edi
004a2e90  3bc7                     cmp       eax, edi
004a2e92  897dfc                   mov       dword ptr [ebp - 4], edi
004a2e95  751f                     jne       0x4a2eb6
004a2e97  8d45f0                   lea       eax, [ebp - 0x10]
004a2e9a  c7052828b30002000000     mov       dword ptr [0xb32828], 2 ; _jwe_x_init
004a2ea4  50                       push      eax
004a2ea5  897df0                   mov       dword ptr [ebp - 0x10], edi
004a2ea8  897df4                   mov       dword ptr [ebp - 0xc], edi
004a2eab  897df8                   mov       dword ptr [ebp - 8], edi
004a2eae  e89d810000               call      0x4ab050 ; _jwe_xint
004a2eb3  83c404                   add       esp, 4
004a2eb6  9b                       wait
004a2eb7  8b5d08                   mov       ebx, dword ptr [ebp + 8]
004a2eba  8b3564601404             mov       esi, dword ptr [0x4146064] ; _jwe_ifca
004a2ec0  8a03                     mov       al, byte ptr [ebx]
004a2ec2  8ac8                     mov       cl, al
004a2ec4  80e180                   and       cl, 0x80
004a2ec7  80f980                   cmp       cl, 0x80
004a2eca  7517                     jne       0x4a2ee3
004a2ecc  8a567d                   mov       dl, byte ptr [esi + 0x7d]
004a2ecf  80e201                   and       dl, 1
004a2ed2  80fa01                   cmp       dl, 1
004a2ed5  0f844e050000             je        0x4a3429
004a2edb  8b7e04                   mov       edi, dword ptr [esi + 4]
004a2ede  e976040000               jmp       0x4a3359
004a2ee3  2408                     and       al, 8
004a2ee5  3c08                     cmp       al, 8
004a2ee7  0f8569030000             jne       0x4a3256
004a2eed  6a0b                     push      0xb
004a2eef  53                       push      ebx
004a2ef0  c686aa01000000           mov       byte ptr [esi + 0x1aa], 0
004a2ef7  ff1578f35b00             call      dword ptr [0x5bf378] ; bits=e0b14b00, f32=6.951471738720836e-39
004a2efd  83c408                   add       esp, 8
004a2f00  83f801                   cmp       eax, 1
004a2f03  745b                     je        0x4a2f60
004a2f05  8a567d                   mov       dl, byte ptr [esi + 0x7d]
004a2f08  50                       push      eax
004a2f09  80ca01                   or        dl, 1
004a2f0c  53                       push      ebx
004a2f0d  88567d                   mov       byte ptr [esi + 0x7d], dl
004a2f10  e83b870100               call      0x4bb650 ; _jwe_iist
004a2f15  8a4301                   mov       al, byte ptr [ebx + 1]
004a2f18  83c408                   add       esp, 8
004a2f1b  2404                     and       al, 4
004a2f1d  3c04                     cmp       al, 4
004a2f1f  7533                     jne       0x4a2f54
004a2f21  8b4324                   mov       eax, dword ptr [ebx + 0x24]
004a2f24  3bc7                     cmp       eax, edi
004a2f26  7423                     je        0x4a2f4b
004a2f28  8b08                     mov       ecx, dword ptr [eax]
004a2f2a  c60100                   mov       byte ptr [ecx], 0
004a2f2d  8b5324                   mov       edx, dword ptr [ebx + 0x24]
004a2f30  897a04                   mov       dword ptr [edx + 4], edi
004a2f33  8a03                     mov       al, byte ptr [ebx]
004a2f35  2401                     and       al, 1
004a2f37  3c01                     cmp       al, 1
004a2f39  7508                     jne       0x4a2f43
004a2f3b  8b4b24                   mov       ecx, dword ptr [ebx + 0x24]
004a2f3e  897908                   mov       dword ptr [ecx + 8], edi
004a2f41  eb08                     jmp       0x4a2f4b
004a2f43  8b5324                   mov       edx, dword ptr [ebx + 0x24]
004a2f46  8b4208                   mov       eax, dword ptr [edx + 8]
004a2f49  8938                     mov       dword ptr [eax], edi
004a2f4b  8b5b28                   mov       ebx, dword ptr [ebx + 0x28]
004a2f4e  3bdf                     cmp       ebx, edi
004a2f50  7402                     je        0x4a2f54
004a2f52  893b                     mov       dword ptr [ebx], edi
004a2f54  5f                       pop       edi
004a2f55  5e                       pop       esi
004a2f56  b802000000               mov       eax, 2
004a2f5b  5b                       pop       ebx
004a2f5c  8be5                     mov       esp, ebp
004a2f5e  5d                       pop       ebp
004a2f5f  c3                       ret
004a2f60  8b3d60601404             mov       edi, dword ptr [0x4146060] ; _jwe_iuia
004a2f66  8a8771030000             mov       al, byte ptr [edi + 0x371]
004a2f6c  8a0f                     mov       cl, byte ptr [edi]
004a2f6e  3c01                     cmp       al, 1
004a2f70  884d0b                   mov       byte ptr [ebp + 0xb], cl
004a2f73  7509                     jne       0x4a2f7e
004a2f75  c6877203000001           mov       byte ptr [edi + 0x372], 1
004a2f7c  eb07                     jmp       0x4a2f85
004a2f7e  c6877203000000           mov       byte ptr [edi + 0x372], 0
004a2f85  c60578f15b0001           mov       byte ptr [0x5bf178], 1
004a2f8c  8a4b01                   mov       cl, byte ptr [ebx + 1]
004a2f8f  b003                     mov       al, 3
004a2f91  84c8                     test      al, cl
004a2f93  7516                     jne       0x4a2fab
004a2f95  884701                   mov       byte ptr [edi + 1], al
004a2f98  c6876801000004           mov       byte ptr [edi + 0x168], 4
004a2f9f  c70580f15b0000000000     mov       dword ptr [0x5bf180], 0 ; bits=00000000, f32=0.0
004a2fa9  eb0b                     jmp       0x4a2fb6
004a2fab  c6470107                 mov       byte ptr [edi + 1], 7
004a2faf  c6876801000008           mov       byte ptr [edi + 0x168], 8
004a2fb6  c6879f00000004           mov       byte ptr [edi + 0x9f], 4
004a2fbd  c687ab01000004           mov       byte ptr [edi + 0x1ab], 4
004a2fc4  c687a000000008           mov       byte ptr [edi + 0xa0], 8
004a2fcb  8b530c                   mov       edx, dword ptr [ebx + 0xc]
004a2fce  895760                   mov       dword ptr [edi + 0x60], edx
004a2fd1  8a03                     mov       al, byte ptr [ebx]
004a2fd3  2401                     and       al, 1
004a2fd5  884750                   mov       byte ptr [edi + 0x50], al
004a2fd8  8b4b10                   mov       ecx, dword ptr [ebx + 0x10]
004a2fdb  894f64                   mov       dword ptr [edi + 0x64], ecx
004a2fde  8b5314                   mov       edx, dword ptr [ebx + 0x14]
004a2fe1  895770                   mov       dword ptr [edi + 0x70], edx
004a2fe4  8a4301                   mov       al, byte ptr [ebx + 1]
004a2fe7  2404                     and       al, 4
004a2fe9  3c04                     cmp       al, 4
004a2feb  7506                     jne       0x4a2ff3
004a2fed  8b4b28                   mov       ecx, dword ptr [ebx + 0x28]
004a2ff0  894f7c                   mov       dword ptr [edi + 0x7c], ecx
004a2ff3  53                       push      ebx
004a2ff4  e8a7860100               call      0x4bb6a0 ; _jwe_iscf
004a2ff9  83c404                   add       esp, 4
004a2ffc  85c0                     test      eax, eax
004a2ffe  7512                     jne       0x4a3012
004a3000  804e7d01                 or        byte ptr [esi + 0x7d], 1
004a3004  ff1580f35b00             call      dword ptr [0x5bf380] ; bits=40504c00, f32=7.008285983658421e-39
004a300a  8945fc                   mov       dword ptr [ebp - 4], eax
004a300d  e9f5030000               jmp       0x4a3407
004a3012  c686ba00000000           mov       byte ptr [esi + 0xba], 0
004a3019  8a8771030000             mov       al, byte ptr [edi + 0x371]
004a301f  3c01                     cmp       al, 1
004a3021  0f94c2                   sete      dl
004a3024  889772030000             mov       byte ptr [edi + 0x372], dl
004a302a  a0a027b300               mov       al, byte ptr [0xb327a0] ; ?zeroara1@?1??jwe_ilst@@9@9
004a302f  8886b4000000             mov       byte ptr [esi + 0xb4], al
004a3035  8a0da127b300             mov       cl, byte ptr [0xb327a1] ; ?zeroara3@?1??jwe_ilst@@9@9
004a303b  33c0                     xor       eax, eax
004a303d  888ed9000000             mov       byte ptr [esi + 0xd9], cl
004a3043  668986b6000000           mov       word ptr [esi + 0xb6], ax
004a304a  8886c2000000             mov       byte ptr [esi + 0xc2], al
004a3050  c686a901000004           mov       byte ptr [esi + 0x1a9], 4
004a3057  8b9760010000             mov       edx, dword ptr [edi + 0x160]
004a305d  8996ac000000             mov       dword ptr [esi + 0xac], edx
004a3063  8a567d                   mov       dl, byte ptr [esi + 0x7d]
004a3066  80e2fe                   and       dl, 0xfe
004a3069  88467f                   mov       byte ptr [esi + 0x7f], al
004a306c  88567d                   mov       byte ptr [esi + 0x7d], dl
004a306f  8a8f68010000             mov       cl, byte ptr [edi + 0x168]
004a3075  80f904                   cmp       cl, 4
004a3078  7558                     jne       0x4a30d2
004a307a  898664010000             mov       dword ptr [esi + 0x164], eax
004a3080  8b86ac000000             mov       eax, dword ptr [esi + 0xac]
004a3086  c786a401000060e24b00     mov       dword ptr [esi + 0x1a4], 0x4be260 ; _jwe_ildi
004a3090  c786a001000030334b00     mov       dword ptr [esi + 0x1a0], 0x4b3330 ; _jwe_ilni
004a309a  c786d4000000b07b4b00     mov       dword ptr [esi + 0xd4], 0x4b7bb0 ; _jwe_iedi
004a30a4  c6869401000008           mov       byte ptr [esi + 0x194], 8
004a30ab  c6869601000004           mov       byte ptr [esi + 0x196], 4
004a30b2  c686a80100000c           mov       byte ptr [esi + 0x1a8], 0xc
004a30b9  898678010000             mov       dword ptr [esi + 0x178], eax
004a30bf  8b8f54010000             mov       ecx, dword ptr [edi + 0x154]
004a30c5  03c8                     add       ecx, eax
004a30c7  898e88010000             mov       dword ptr [esi + 0x188], ecx
004a30cd  e9a8000000               jmp       0x4a317a
004a30d2  c786a4010000f0c84b00     mov       dword ptr [esi + 0x1a4], 0x4bc8f0 ; _jwe_ildo
004a30dc  c786d4000000204b4b00     mov       dword ptr [esi + 0xd4], 0x4b4b20 ; _jwe_iedo
004a30e6  8a471b                   mov       al, byte ptr [edi + 0x1b]
004a30e9  b222                     mov       dl, 0x22
004a30eb  3c0c                     cmp       al, 0xc
004a30ed  7509                     jne       0x4a30f8
004a30ef  c687aa01000020           mov       byte ptr [edi + 0x1aa], 0x20
004a30f6  eb13                     jmp       0x4a310b
004a30f8  3c04                     cmp       al, 4
004a30fa  7509                     jne       0x4a3105
004a30fc  c687aa01000027           mov       byte ptr [edi + 0x1aa], 0x27
004a3103  eb06                     jmp       0x4a310b
004a3105  8897aa010000             mov       byte ptr [edi + 0x1aa], dl
004a310b  c6869701000020           mov       byte ptr [esi + 0x197], 0x20
004a3112  a06def5b00               mov       al, byte ptr [0x5bef6d]
004a3117  3c01                     cmp       al, 1
004a3119  7520                     jne       0x4a313b
004a311b  8a876f010000             mov       al, byte ptr [edi + 0x16f]
004a3121  84c0                     test      al, al
004a3123  7516                     jne       0x4a313b
004a3125  8b8f58010000             mov       ecx, dword ptr [edi + 0x158]
004a312b  8b86ac000000             mov       eax, dword ptr [esi + 0xac]
004a3131  83f950                   cmp       ecx, 0x50
004a3134  7c11                     jl        0x4a3147
004a3136  8d4850                   lea       ecx, [eax + 0x50]
004a3139  eb0e                     jmp       0x4a3149
004a313b  8b86ac000000             mov       eax, dword ptr [esi + 0xac]
004a3141  8b8f58010000             mov       ecx, dword ptr [edi + 0x158]
004a3147  03c8                     add       ecx, eax
004a3149  898e88010000             mov       dword ptr [esi + 0x188], ecx
004a314f  8a0d6def5b00             mov       cl, byte ptr [0x5bef6d]
004a3155  80f901                   cmp       cl, 1
004a3158  7406                     je        0x4a3160
004a315a  38550b                   cmp       byte ptr [ebp + 0xb], dl
004a315d  7401                     je        0x4a3160
004a315f  40                       inc       eax
004a3160  89868c010000             mov       dword ptr [esi + 0x18c], eax
004a3166  8bd0                     mov       edx, eax
004a3168  8b86a8000000             mov       eax, dword ptr [esi + 0xa8]
004a316e  899678010000             mov       dword ptr [esi + 0x178], edx
004a3174  8986ec020000             mov       dword ptr [esi + 0x2ec], eax
004a317a  803d5aef5b0001           cmp       byte ptr [0x5bef5a], 1
004a3181  753a                     jne       0x4a31bd
004a3183  a0c4ec5b00               mov       al, byte ptr [0x5becc4]
004a3188  84c0                     test      al, al
004a318a  7531                     jne       0x4a31bd
004a318c  803d59ef5b0001           cmp       byte ptr [0x5bef59], 1
004a3193  7528                     jne       0x4a31bd
004a3195  8b0d60601404             mov       ecx, dword ptr [0x4146060] ; _jwe_iuia
004a319b  80b96801000008           cmp       byte ptr [ecx + 0x168], 8
004a31a2  7519                     jne       0x4a31bd
004a31a4  681f000800               push      0x8001f
004a31a9  6803000800               push      0x80003
004a31ae  e853600400               call      0x4e9206 ; __control87
004a31b3  83c408                   add       esp, 8
004a31b6  c605a227b30001           mov       byte ptr [0xb327a2], 1 ; ?fpflag@?1??jwe_ilst@@9@9
004a31bd  c687ab01000008           mov       byte ptr [edi + 0x1ab], 8
004a31c4  8a03                     mov       al, byte ptr [ebx]
004a31c6  8ad0                     mov       dl, al
004a31c8  80e220                   and       dl, 0x20
004a31cb  80fa20                   cmp       dl, 0x20
004a31ce  7507                     jne       0x4a31d7
004a31d0  a840                     test      al, 0x40
004a31d2  e97c010000               jmp       0x4a3353
004a31d7  8a4301                   mov       al, byte ptr [ebx + 1]
004a31da  2404                     and       al, 4
004a31dc  3c04                     cmp       al, 4
004a31de  8d4330                   lea       eax, [ebx + 0x30]
004a31e1  7403                     je        0x4a31e6
004a31e3  8d4320                   lea       eax, [ebx + 0x20]
004a31e6  50                       push      eax
004a31e7  ff96a4010000             call      dword ptr [esi + 0x1a4]
004a31ed  83c404                   add       esp, 4
004a31f0  85c0                     test      eax, eax
004a31f2  0f8556010000             jne       0x4a334e
004a31f8  8a567d                   mov       dl, byte ptr [esi + 0x7d]
004a31fb  80ca01                   or        dl, 1
004a31fe  88567d                   mov       byte ptr [esi + 0x7d], dl
004a3201  8b8750010000             mov       eax, dword ptr [edi + 0x150]
004a3207  83f801                   cmp       eax, 1
004a320a  0f84e6010000             je        0x4a33f6
004a3210  83f8ff                   cmp       eax, -1
004a3213  0f84dd010000             je        0x4a33f6
004a3219  8a8768010000             mov       al, byte ptr [edi + 0x168]
004a321f  c687ae0100000c           mov       byte ptr [edi + 0x1ae], 0xc
004a3226  3c04                     cmp       al, 4
004a3228  7520                     jne       0x4a324a
004a322a  8b8e78010000             mov       ecx, dword ptr [esi + 0x178]
004a3230  898f60010000             mov       dword ptr [edi + 0x160], ecx
004a3236  ff97e4000000             call      dword ptr [edi + 0xe4]
004a323c  ff1580f35b00             call      dword ptr [0x5bf380] ; bits=40504c00, f32=7.008285983658421e-39
004a3242  8945fc                   mov       dword ptr [ebp - 4], eax
004a3245  e9bd010000               jmp       0x4a3407
004a324a  c6876c01000001           mov       byte ptr [edi + 0x16c], 1
004a3251  e9c4000000               jmp       0x4a331a
004a3256  8a4e7d                   mov       cl, byte ptr [esi + 0x7d]
004a3259  80e101                   and       cl, 1
004a325c  80f901                   cmp       cl, 1
004a325f  0f84c4010000             je        0x4a3429
004a3265  8b7e04                   mov       edi, dword ptr [esi + 4]
004a3268  53                       push      ebx
004a3269  ff96a4010000             call      dword ptr [esi + 0x1a4]
004a326f  83c404                   add       esp, 4
004a3272  85c0                     test      eax, eax
004a3274  0f85d4000000             jne       0x4a334e
004a327a  8a567d                   mov       dl, byte ptr [esi + 0x7d]
004a327d  80ca01                   or        dl, 1
004a3280  88567d                   mov       byte ptr [esi + 0x7d], dl
004a3283  8b8750010000             mov       eax, dword ptr [edi + 0x150]
004a3289  83f801                   cmp       eax, 1
004a328c  0f8464010000             je        0x4a33f6
004a3292  83f8ff                   cmp       eax, -1
004a3295  0f845b010000             je        0x4a33f6
004a329b  8a8768010000             mov       al, byte ptr [edi + 0x168]
004a32a1  c687ae0100000c           mov       byte ptr [edi + 0x1ae], 0xc
004a32a8  3c04                     cmp       al, 4
004a32aa  7520                     jne       0x4a32cc
004a32ac  8b9678010000             mov       edx, dword ptr [esi + 0x178]
004a32b2  899760010000             mov       dword ptr [edi + 0x160], edx
004a32b8  ff97e4000000             call      dword ptr [edi + 0xe4]
004a32be  ff1580f35b00             call      dword ptr [0x5bf380] ; bits=40504c00, f32=7.008285983658421e-39
004a32c4  8945fc                   mov       dword ptr [ebp - 4], eax
004a32c7  e93b010000               jmp       0x4a3407
004a32cc  c6876c01000001           mov       byte ptr [edi + 0x16c], 1
004a32d3  a06def5b00               mov       al, byte ptr [0x5bef6d]
004a32d8  84c0                     test      al, al
004a32da  753e                     jne       0x4a331a
004a32dc  8b868c010000             mov       eax, dword ptr [esi + 0x18c]
004a32e2  8b8e78010000             mov       ecx, dword ptr [esi + 0x178]
004a32e8  3bc1                     cmp       eax, ecx
004a32ea  7510                     jne       0x4a32fc
004a32ec  8b8ea8000000             mov       ecx, dword ptr [esi + 0xa8]
004a32f2  8b96ec020000             mov       edx, dword ptr [esi + 0x2ec]
004a32f8  3bca                     cmp       ecx, edx
004a32fa  741e                     je        0x4a331a
004a32fc  8a48ff                   mov       cl, byte ptr [eax - 1]
004a32ff  48                       dec       eax
004a3300  80f920                   cmp       cl, 0x20
004a3303  7515                     jne       0x4a331a
004a3305  80bea100000011           cmp       byte ptr [esi + 0xa1], 0x11
004a330c  7506                     jne       0x4a3314
004a330e  807f1b0c                 cmp       byte ptr [edi + 0x1b], 0xc
004a3312  7406                     je        0x4a331a
004a3314  89868c010000             mov       dword ptr [esi + 0x18c], eax
004a331a  8b968c010000             mov       edx, dword ptr [esi + 0x18c]
004a3320  8b8760010000             mov       eax, dword ptr [edi + 0x160]
004a3326  2bd0                     sub       edx, eax
004a3328  899754010000             mov       dword ptr [edi + 0x154], edx
004a332e  8b868c010000             mov       eax, dword ptr [esi + 0x18c]
004a3334  898760010000             mov       dword ptr [edi + 0x160], eax
004a333a  ff97e8000000             call      dword ptr [edi + 0xe8]
004a3340  ff1580f35b00             call      dword ptr [0x5bf380] ; bits=40504c00, f32=7.008285983658421e-39
004a3346  8945fc                   mov       dword ptr [ebp - 4], eax
004a3349  e9b9000000               jmp       0x4a3407
004a334e  8a467f                   mov       al, byte ptr [esi + 0x7f]
004a3351  84c0                     test      al, al
004a3353  0f84d0000000             je        0x4a3429
004a3359  8a8768010000             mov       al, byte ptr [edi + 0x168]
004a335f  c687ae0100000c           mov       byte ptr [edi + 0x1ae], 0xc
004a3366  3c08                     cmp       al, 8
004a3368  7576                     jne       0x4a33e0
004a336a  a06def5b00               mov       al, byte ptr [0x5bef6d]
004a336f  84c0                     test      al, al
004a3371  753e                     jne       0x4a33b1
004a3373  8b868c010000             mov       eax, dword ptr [esi + 0x18c]
004a3379  8b8e78010000             mov       ecx, dword ptr [esi + 0x178]
004a337f  3bc1                     cmp       eax, ecx
004a3381  7510                     jne       0x4a3393
004a3383  8b8ea8000000             mov       ecx, dword ptr [esi + 0xa8]
004a3389  8b96ec020000             mov       edx, dword ptr [esi + 0x2ec]
004a338f  3bca                     cmp       ecx, edx
004a3391  741e                     je        0x4a33b1
004a3393  8a48ff                   mov       cl, byte ptr [eax - 1]
004a3396  48                       dec       eax
004a3397  80f920                   cmp       cl, 0x20
004a339a  7515                     jne       0x4a33b1
004a339c  80bea100000011           cmp       byte ptr [esi + 0xa1], 0x11
004a33a3  7506                     jne       0x4a33ab
004a33a5  807f1b0c                 cmp       byte ptr [edi + 0x1b], 0xc
004a33a9  7406                     je        0x4a33b1
004a33ab  89868c010000             mov       dword ptr [esi + 0x18c], eax
004a33b1  8b968c010000             mov       edx, dword ptr [esi + 0x18c]
004a33b7  8b9f60010000             mov       ebx, dword ptr [edi + 0x160]
004a33bd  2bd3                     sub       edx, ebx
004a33bf  899754010000             mov       dword ptr [edi + 0x154], edx
004a33c5  8b868c010000             mov       eax, dword ptr [esi + 0x18c]
004a33cb  898760010000             mov       dword ptr [edi + 0x160], eax
004a33d1  c6876c01000001           mov       byte ptr [edi + 0x16c], 1
004a33d8  ff97e8000000             call      dword ptr [edi + 0xe8]
004a33de  eb12                     jmp       0x4a33f2
004a33e0  8b8e78010000             mov       ecx, dword ptr [esi + 0x178]
004a33e6  898f60010000             mov       dword ptr [edi + 0x160], ecx
004a33ec  ff97e4000000             call      dword ptr [edi + 0xe4]
004a33f2  85c0                     test      eax, eax
004a33f4  750b                     jne       0x4a3401
004a33f6  ff1580f35b00             call      dword ptr [0x5bf380] ; bits=40504c00, f32=7.008285983658421e-39
004a33fc  8945fc                   mov       dword ptr [ebp - 4], eax
004a33ff  eb06                     jmp       0x4a3407
004a3401  ff157cf35b00             call      dword ptr [0x5bf37c] ; bits=c0504c00, f32=7.008465349861855e-39
004a3407  803da227b30001           cmp       byte ptr [0xb327a2], 1 ; ?fpflag@?1??jwe_ilst@@9@9
004a340e  7519                     jne       0x4a3429
004a3410  681f000800               push      0x8001f
004a3415  6801000800               push      0x80001
004a341a  e8e75d0400               call      0x4e9206 ; __control87
004a341f  83c408                   add       esp, 8
004a3422  c605a227b30000           mov       byte ptr [0xb327a2], 0 ; ?fpflag@?1??jwe_ilst@@9@9
004a3429  8b45fc                   mov       eax, dword ptr [ebp - 4]
004a342c  5f                       pop       edi
004a342d  5e                       pop       esi
004a342e  5b                       pop       ebx
004a342f  8be5                     mov       esp, ebp
004a3431  5d                       pop       ebp
004a3432  c3                       ret
004a3433  90                       nop
004a3434  90                       nop
004a3435  90                       nop
004a3436  90                       nop
004a3437  90                       nop
004a3438  90                       nop
004a3439  90                       nop
004a343a  90                       nop
004a343b  90                       nop
004a343c  90                       nop
004a343d  90                       nop
004a343e  90                       nop
004a343f  90                       nop
