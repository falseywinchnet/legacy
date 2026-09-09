; _ufgate_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x7f3c0
0047f3c0  55                       push      ebp
0047f3c1  8bec                     mov       ebp, esp
0047f3c3  b860020000               mov       eax, 0x260
0047f3c8  e8339c0600               call      0x4e9000 ; __alloca_probe
0047f3cd  53                       push      ebx
0047f3ce  56                       push      esi
0047f3cf  57                       push      edi
0047f3d0  8b4508                   mov       eax, dword ptr [ebp + 8]
0047f3d3  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
0047f3d6  8b5510                   mov       edx, dword ptr [ebp + 0x10]
0047f3d9  898580feffff             mov       dword ptr [ebp - 0x180], eax
0047f3df  898d7cfeffff             mov       dword ptr [ebp - 0x184], ecx
0047f3e5  899578feffff             mov       dword ptr [ebp - 0x188], edx
0047f3eb  8d0550a65a00             lea       eax, [0x5aa650] ; bits=00000000, f32=0.0
0047f3f1  c60031                   mov       byte ptr [eax], 0x31
0047f3f4  c6400130                 mov       byte ptr [eax + 1], 0x30
0047f3f8  c6400230                 mov       byte ptr [eax + 2], 0x30
0047f3fc  c6400330                 mov       byte ptr [eax + 3], 0x30
0047f400  c6400431                 mov       byte ptr [eax + 4], 0x31
0047f404  c6400520                 mov       byte ptr [eax + 5], 0x20
0047f408  c6400620                 mov       byte ptr [eax + 6], 0x20
0047f40c  c6400720                 mov       byte ptr [eax + 7], 0x20
0047f410  c6400820                 mov       byte ptr [eax + 8], 0x20
0047f414  c6400920                 mov       byte ptr [eax + 9], 0x20
0047f418  c6400a20                 mov       byte ptr [eax + 0xa], 0x20
0047f41c  c6400b20                 mov       byte ptr [eax + 0xb], 0x20
0047f420  c6400c20                 mov       byte ptr [eax + 0xc], 0x20
0047f424  c6400d20                 mov       byte ptr [eax + 0xd], 0x20
0047f428  c6400e20                 mov       byte ptr [eax + 0xe], 0x20
0047f42c  c6400f20                 mov       byte ptr [eax + 0xf], 0x20
0047f430  6a10                     push      0x10
0047f432  6870a45a00               push      0x5aa470
0047f437  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
0047f43a  8d03                     lea       eax, [ebx]
0047f43c  50                       push      eax
0047f43d  6850a65a00               push      0x5aa650
0047f442  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f448  8d08                     lea       ecx, [eax]
0047f44a  51                       push      ecx
0047f44b  e8f07effff               call      0x477340 ; _get_internal_tab_number_
0047f450  83c414                   add       esp, 0x14
0047f453  8b0570a45a00             mov       eax, dword ptr [0x5aa470] ; bits=00000000, f32=0.0
0047f459  8b0c85ec5a0e04           mov       ecx, dword ptr [eax*4 + 0x40e5aec]
0047f460  890d70a45a00             mov       dword ptr [0x5aa470], ecx ; bits=00000000, f32=0.0
0047f466  8d0550a65a00             lea       eax, [0x5aa650] ; bits=00000000, f32=0.0
0047f46c  c60031                   mov       byte ptr [eax], 0x31
0047f46f  c6400130                 mov       byte ptr [eax + 1], 0x30
0047f473  c6400230                 mov       byte ptr [eax + 2], 0x30
0047f477  c6400330                 mov       byte ptr [eax + 3], 0x30
0047f47b  c6400432                 mov       byte ptr [eax + 4], 0x32
0047f47f  c6400520                 mov       byte ptr [eax + 5], 0x20
0047f483  c6400620                 mov       byte ptr [eax + 6], 0x20
0047f487  c6400720                 mov       byte ptr [eax + 7], 0x20
0047f48b  c6400820                 mov       byte ptr [eax + 8], 0x20
0047f48f  c6400920                 mov       byte ptr [eax + 9], 0x20
0047f493  c6400a20                 mov       byte ptr [eax + 0xa], 0x20
0047f497  c6400b20                 mov       byte ptr [eax + 0xb], 0x20
0047f49b  c6400c20                 mov       byte ptr [eax + 0xc], 0x20
0047f49f  c6400d20                 mov       byte ptr [eax + 0xd], 0x20
0047f4a3  c6400e20                 mov       byte ptr [eax + 0xe], 0x20
0047f4a7  c6400f20                 mov       byte ptr [eax + 0xf], 0x20
0047f4ab  6a10                     push      0x10
0047f4ad  686ca45a00               push      0x5aa46c
0047f4b2  8d03                     lea       eax, [ebx]
0047f4b4  50                       push      eax
0047f4b5  6850a65a00               push      0x5aa650
0047f4ba  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f4c0  8d08                     lea       ecx, [eax]
0047f4c2  51                       push      ecx
0047f4c3  e8787effff               call      0x477340 ; _get_internal_tab_number_
0047f4c8  83c414                   add       esp, 0x14
0047f4cb  8b056ca45a00             mov       eax, dword ptr [0x5aa46c] ; bits=00000000, f32=0.0
0047f4d1  8b0c85ec5a0e04           mov       ecx, dword ptr [eax*4 + 0x40e5aec]
0047f4d8  890d6ca45a00             mov       dword ptr [0x5aa46c], ecx ; bits=00000000, f32=0.0
0047f4de  833d70a45a0001           cmp       dword ptr [0x5aa470], 1 ; bits=00000000, f32=0.0
0047f4e5  7c09                     jl        0x47f4f0
0047f4e7  833d6ca45a0001           cmp       dword ptr [0x5aa46c], 1 ; bits=00000000, f32=0.0
0047f4ee  7d2e                     jge       0x47f51e
0047f4f0  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f4f6  8b08                     mov       ecx, dword ptr [eax]
0047f4f8  8d0518a45a00             lea       eax, [0x5aa418] ; bits=69020000, f32=8.646011524884121e-43
0047f4fe  894dfc                   mov       dword ptr [ebp - 4], ecx
0047f501  8d4dfc                   lea       ecx, [ebp - 4]
0047f504  894808                   mov       dword ptr [eax + 8], ecx
0047f507  50                       push      eax
0047f508  e8e3300200               call      0x4a25f0 ; _jwe_isfm
0047f50d  83c404                   add       esp, 4
0047f510  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047f513  c70001000000             mov       dword ptr [eax], 1
0047f519  e9233c0000               jmp       0x483141
0047f51e  8b8580feffff             mov       eax, dword ptr [ebp - 0x180]
0047f524  8b08                     mov       ecx, dword ptr [eax]
0047f526  890d0878b400             mov       dword ptr [0xb47808], ecx
0047f52c  d9050878b400             fld       dword ptr [0xb47808]
0047f532  d8050878b400             fadd      dword ptr [0xb47808]
0047f538  d91d0c78b400             fstp      dword ptr [0xb4780c]
0047f53e  6a50                     push      0x50
0047f540  68f0a55a00               push      0x5aa5f0
0047f545  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f54b  8d08                     lea       ecx, [eax]
0047f54d  51                       push      ecx
0047f54e  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047f554  8d11                     lea       edx, [ecx]
0047f556  52                       push      edx
0047f557  e884d3fcff               call      0x44c8e0 ; _inline_
0047f55c  83c410                   add       esp, 0x10
0047f55f  6a10                     push      0x10
0047f561  6a03                     push      3
0047f563  6a50                     push      0x50
0047f565  6868a45a00               push      0x5aa468
0047f56a  6860a65a00               push      0x5aa660
0047f56f  8d03                     lea       eax, [ebx]
0047f571  50                       push      eax
0047f572  6818935a00               push      0x5a9318
0047f577  68f0a55a00               push      0x5aa5f0
0047f57c  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f582  8d08                     lea       ecx, [eax]
0047f584  51                       push      ecx
0047f585  e8a6b1fdff               call      0x45a730 ; _read_tabid_
0047f58a  83c424                   add       esp, 0x24
0047f58d  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f593  8b30                     mov       esi, dword ptr [eax]
0047f595  6a10                     push      0x10
0047f597  6860a65a00               push      0x5aa660
0047f59c  e8af04fdff               call      0x44fa50 ; _lenstr_
0047f5a1  83c408                   add       esp, 8
0047f5a4  89c2                     mov       edx, eax
0047f5a6  c1fa1f                   sar       edx, 0x1f
0047f5a9  f7d2                     not       edx
0047f5ab  21d0                     and       eax, edx
0047f5ad  8d0deca35a00             lea       ecx, [0x5aa3ec] ; bits=09020000, f32=7.300764999132297e-43
0047f5b3  8975fc                   mov       dword ptr [ebp - 4], esi
0047f5b6  8d55fc                   lea       edx, [ebp - 4]
0047f5b9  895108                   mov       dword ptr [ecx + 8], edx
0047f5bc  894124                   mov       dword ptr [ecx + 0x24], eax
0047f5bf  51                       push      ecx
0047f5c0  e82b300200               call      0x4a25f0 ; _jwe_isfm
0047f5c5  83c404                   add       esp, 4
0047f5c8  6a10                     push      0x10
0047f5ca  6860a65a00               push      0x5aa660
0047f5cf  e87c04fdff               call      0x44fa50 ; _lenstr_
0047f5d4  83c408                   add       esp, 8
0047f5d7  89c2                     mov       edx, eax
0047f5d9  c1fa1f                   sar       edx, 0x1f
0047f5dc  f7d2                     not       edx
0047f5de  21d0                     and       eax, edx
0047f5e0  8d0dc0a35a00             lea       ecx, [0x5aa3c0] ; bits=09220000, f32=1.220951351966213e-41
0047f5e6  894124                   mov       dword ptr [ecx + 0x24], eax
0047f5e9  51                       push      ecx
0047f5ea  e801300200               call      0x4a25f0 ; _jwe_isfm
0047f5ef  83c404                   add       esp, 4
0047f5f2  8d03                     lea       eax, [ebx]
0047f5f4  50                       push      eax
0047f5f5  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0047f5f8  8d00                     lea       eax, [eax]
0047f5fa  50                       push      eax
0047f5fb  6868a45a00               push      0x5aa468
0047f600  8d0560905a00             lea       eax, [0x5a9060] ; bits=16000000, f32=3.0828566215145976e-44
0047f606  898574feffff             mov       dword ptr [ebp - 0x18c], eax
0047f60c  8d48dc                   lea       ecx, [eax - 0x24]
0047f60f  51                       push      ecx
0047f610  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
0047f616  8d11                     lea       edx, [ecx]
0047f618  52                       push      edx
0047f619  e87282fbff               call      0x437890 ; _tabchk_
0047f61e  83c414                   add       esp, 0x14
0047f621  8d03                     lea       eax, [ebx]
0047f623  50                       push      eax
0047f624  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f62a  8d08                     lea       ecx, [eax]
0047f62c  51                       push      ecx
0047f62d  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047f633  8d11                     lea       edx, [ecx]
0047f635  52                       push      edx
0047f636  e845dcfdff               call      0x45d280 ; _get_lctn_items_
0047f63b  83c40c                   add       esp, 0xc
0047f63e  6a08                     push      8
0047f640  6a08                     push      8
0047f642  6a08                     push      8
0047f644  6a08                     push      8
0047f646  6a08                     push      8
0047f648  6840a45a00               push      0x5aa440
0047f64d  6838a45a00               push      0x5aa438
0047f652  68f8a65a00               push      0x5aa6f8
0047f657  68f0a65a00               push      0x5aa6f0
0047f65c  68e8a65a00               push      0x5aa6e8
0047f661  68e0a65a00               push      0x5aa6e0
0047f666  68d8a65a00               push      0x5aa6d8
0047f66b  e830dbfdff               call      0x45d1a0 ; _set_lctn_items_
0047f670  83c430                   add       esp, 0x30
0047f673  6a50                     push      0x50
0047f675  68f0a55a00               push      0x5aa5f0
0047f67a  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f680  8d08                     lea       ecx, [eax]
0047f682  51                       push      ecx
0047f683  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047f689  8d11                     lea       edx, [ecx]
0047f68b  52                       push      edx
0047f68c  e84fd2fcff               call      0x44c8e0 ; _inline_
0047f691  83c410                   add       esp, 0x10
0047f694  68a0a35a00               push      0x5aa3a0
0047f699  e8b2240200               call      0x4a1b50 ; _jwe_iinf
0047f69e  83c404                   add       esp, 4
0047f6a1  85c0                     test      eax, eax
0047f6a3  0f85533a0000             jne       0x4830fc
0047f6a9  6894a35a00               push      0x5aa394
0047f6ae  e89d240200               call      0x4a1b50 ; _jwe_iinf
0047f6b3  83c404                   add       esp, 4
0047f6b6  85c0                     test      eax, eax
0047f6b8  0f853e3a0000             jne       0x4830fc
0047f6be  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f6c4  8b08                     mov       ecx, dword ptr [eax]
0047f6c6  8d1568a35a00             lea       edx, [0x5aa368] ; bits=09020000, f32=7.300764999132297e-43
0047f6cc  894dfc                   mov       dword ptr [ebp - 4], ecx
0047f6cf  8d4dfc                   lea       ecx, [ebp - 4]
0047f6d2  894a08                   mov       dword ptr [edx + 8], ecx
0047f6d5  52                       push      edx
0047f6d6  e8152f0200               call      0x4a25f0 ; _jwe_isfm
0047f6db  83c404                   add       esp, 4
0047f6de  6a50                     push      0x50
0047f6e0  68f0a55a00               push      0x5aa5f0
0047f6e5  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f6eb  8d08                     lea       ecx, [eax]
0047f6ed  51                       push      ecx
0047f6ee  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047f6f4  8d11                     lea       edx, [ecx]
0047f6f6  52                       push      edx
0047f6f7  e8e4d1fcff               call      0x44c8e0 ; _inline_
0047f6fc  83c410                   add       esp, 0x10
0047f6ff  6a10                     push      0x10
0047f701  6a03                     push      3
0047f703  6a50                     push      0x50
0047f705  688077b400               push      0xb47780 ; _ufcom_
0047f70a  6870a65a00               push      0x5aa670
0047f70f  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
0047f712  8d03                     lea       eax, [ebx]
0047f714  50                       push      eax
0047f715  6820935a00               push      0x5a9320
0047f71a  68f0a55a00               push      0x5aa5f0
0047f71f  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f725  8d08                     lea       ecx, [eax]
0047f727  51                       push      ecx
0047f728  e803b0fdff               call      0x45a730 ; _read_tabid_
0047f72d  83c424                   add       esp, 0x24
0047f730  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f736  8b30                     mov       esi, dword ptr [eax]
0047f738  6a10                     push      0x10
0047f73a  6870a65a00               push      0x5aa670
0047f73f  e80c03fdff               call      0x44fa50 ; _lenstr_
0047f744  83c408                   add       esp, 8
0047f747  89c2                     mov       edx, eax
0047f749  c1fa1f                   sar       edx, 0x1f
0047f74c  f7d2                     not       edx
0047f74e  21d0                     and       eax, edx
0047f750  8d0d3ca35a00             lea       ecx, [0x5aa33c] ; bits=09020000, f32=7.300764999132297e-43
0047f756  8975fc                   mov       dword ptr [ebp - 4], esi
0047f759  8d55fc                   lea       edx, [ebp - 4]
0047f75c  895108                   mov       dword ptr [ecx + 8], edx
0047f75f  894124                   mov       dword ptr [ecx + 0x24], eax
0047f762  51                       push      ecx
0047f763  e8882e0200               call      0x4a25f0 ; _jwe_isfm
0047f768  83c404                   add       esp, 4
0047f76b  833d8077b40000           cmp       dword ptr [0xb47780], 0 ; _ufcom_
0047f772  7f28                     jg        0x47f79c
0047f774  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f77a  8b08                     mov       ecx, dword ptr [eax]
0047f77c  8d151ca35a00             lea       edx, [0x5aa31c] ; bits=69020000, f32=8.646011524884121e-43
0047f782  894dfc                   mov       dword ptr [ebp - 4], ecx
0047f785  8d4dfc                   lea       ecx, [ebp - 4]
0047f788  894a08                   mov       dword ptr [edx + 8], ecx
0047f78b  52                       push      edx
0047f78c  e85f2e0200               call      0x4a25f0 ; _jwe_isfm
0047f791  83c404                   add       esp, 4
0047f794  c70301000000             mov       dword ptr [ebx], 1
0047f79a  eb77                     jmp       0x47f813
0047f79c  c7054ca45a0000000000     mov       dword ptr [0x5aa44c], 0 ; bits=00000000, f32=0.0
0047f7a6  8b058077b400             mov       eax, dword ptr [0xb47780] ; _ufcom_
0047f7ac  890574a45a00             mov       dword ptr [0x5aa474], eax ; bits=00000000, f32=0.0
0047f7b2  684ca45a00               push      0x5aa44c
0047f7b7  688077b400               push      0xb47780 ; _ufcom_
0047f7bc  8b8574feffff             mov       eax, dword ptr [ebp - 0x18c]
0047f7c2  8d48dc                   lea       ecx, [eax - 0x24]
0047f7c5  51                       push      ecx
0047f7c6  68f05a0e04               push      0x40e5af0
0047f7cb  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
0047f7d1  8d11                     lea       edx, [ecx]
0047f7d3  52                       push      edx
0047f7d4  8d5050                   lea       edx, [eax + 0x50]
0047f7d7  52                       push      edx
0047f7d8  e87385fbff               call      0x437d50 ; _chktab_
0047f7dd  83c418                   add       esp, 0x18
0047f7e0  833d4ca45a0000           cmp       dword ptr [0x5aa44c], 0 ; bits=00000000, f32=0.0
0047f7e7  7522                     jne       0x47f80b
0047f7e9  68b077b400               push      0xb477b0
0047f7ee  89d8                     mov       eax, ebx
0047f7f0  8d00                     lea       eax, [eax]
0047f7f2  50                       push      eax
0047f7f3  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f7f9  8d08                     lea       ecx, [eax]
0047f7fb  51                       push      ecx
0047f7fc  6874a45a00               push      0x5aa474
0047f801  e8ea7cffff               call      0x4774f0 ; _fndelv_
0047f806  83c410                   add       esp, 0x10
0047f809  eb08                     jmp       0x47f813
0047f80b  89d8                     mov       eax, ebx
0047f80d  c70001000000             mov       dword ptr [eax], 1
0047f813  6a50                     push      0x50
0047f815  68f0a55a00               push      0x5aa5f0
0047f81a  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f820  8d08                     lea       ecx, [eax]
0047f822  51                       push      ecx
0047f823  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047f829  8d11                     lea       edx, [ecx]
0047f82b  52                       push      edx
0047f82c  e8afd0fcff               call      0x44c8e0 ; _inline_
0047f831  83c410                   add       esp, 0x10
0047f834  6a10                     push      0x10
0047f836  6a03                     push      3
0047f838  6a50                     push      0x50
0047f83a  688477b400               push      0xb47784
0047f83f  6880a65a00               push      0x5aa680
0047f844  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
0047f847  8d03                     lea       eax, [ebx]
0047f849  50                       push      eax
0047f84a  6828935a00               push      0x5a9328
0047f84f  68f0a55a00               push      0x5aa5f0
0047f854  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f85a  8d08                     lea       ecx, [eax]
0047f85c  51                       push      ecx
0047f85d  e8ceaefdff               call      0x45a730 ; _read_tabid_
0047f862  83c424                   add       esp, 0x24
0047f865  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f86b  8b30                     mov       esi, dword ptr [eax]
0047f86d  6a10                     push      0x10
0047f86f  6880a65a00               push      0x5aa680
0047f874  e8d701fdff               call      0x44fa50 ; _lenstr_
0047f879  83c408                   add       esp, 8
0047f87c  89c2                     mov       edx, eax
0047f87e  c1fa1f                   sar       edx, 0x1f
0047f881  f7d2                     not       edx
0047f883  21d0                     and       eax, edx
0047f885  8d0df0a25a00             lea       ecx, [0x5aa2f0] ; bits=09020000, f32=7.300764999132297e-43
0047f88b  8975fc                   mov       dword ptr [ebp - 4], esi
0047f88e  8d55fc                   lea       edx, [ebp - 4]
0047f891  895108                   mov       dword ptr [ecx + 8], edx
0047f894  894124                   mov       dword ptr [ecx + 0x24], eax
0047f897  51                       push      ecx
0047f898  e8532d0200               call      0x4a25f0 ; _jwe_isfm
0047f89d  83c404                   add       esp, 4
0047f8a0  833d8477b40000           cmp       dword ptr [0xb47784], 0
0047f8a7  7f28                     jg        0x47f8d1
0047f8a9  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f8af  8b08                     mov       ecx, dword ptr [eax]
0047f8b1  8d15d0a25a00             lea       edx, [0x5aa2d0] ; bits=69020000, f32=8.646011524884121e-43
0047f8b7  894dfc                   mov       dword ptr [ebp - 4], ecx
0047f8ba  8d4dfc                   lea       ecx, [ebp - 4]
0047f8bd  894a08                   mov       dword ptr [edx + 8], ecx
0047f8c0  52                       push      edx
0047f8c1  e82a2d0200               call      0x4a25f0 ; _jwe_isfm
0047f8c6  83c404                   add       esp, 4
0047f8c9  c70301000000             mov       dword ptr [ebx], 1
0047f8cf  eb77                     jmp       0x47f948
0047f8d1  c7054ca45a0000000000     mov       dword ptr [0x5aa44c], 0 ; bits=00000000, f32=0.0
0047f8db  8b058477b400             mov       eax, dword ptr [0xb47784]
0047f8e1  890574a45a00             mov       dword ptr [0x5aa474], eax ; bits=00000000, f32=0.0
0047f8e7  684ca45a00               push      0x5aa44c
0047f8ec  688477b400               push      0xb47784
0047f8f1  8d0560905a00             lea       eax, [0x5a9060] ; bits=16000000, f32=3.0828566215145976e-44
0047f8f7  8d48dc                   lea       ecx, [eax - 0x24]
0047f8fa  51                       push      ecx
0047f8fb  68f05a0e04               push      0x40e5af0
0047f900  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
0047f906  8d11                     lea       edx, [ecx]
0047f908  52                       push      edx
0047f909  8d40bc                   lea       eax, [eax - 0x44]
0047f90c  50                       push      eax
0047f90d  e83e84fbff               call      0x437d50 ; _chktab_
0047f912  83c418                   add       esp, 0x18
0047f915  833d4ca45a0000           cmp       dword ptr [0x5aa44c], 0 ; bits=00000000, f32=0.0
0047f91c  7522                     jne       0x47f940
0047f91e  68bc77b400               push      0xb477bc
0047f923  89d8                     mov       eax, ebx
0047f925  8d00                     lea       eax, [eax]
0047f927  50                       push      eax
0047f928  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f92e  8d08                     lea       ecx, [eax]
0047f930  51                       push      ecx
0047f931  6874a45a00               push      0x5aa474
0047f936  e8b57bffff               call      0x4774f0 ; _fndelv_
0047f93b  83c410                   add       esp, 0x10
0047f93e  eb08                     jmp       0x47f948
0047f940  89d8                     mov       eax, ebx
0047f942  c70001000000             mov       dword ptr [eax], 1
0047f948  8b05bc77b400             mov       eax, dword ptr [0xb477bc]
0047f94e  8905b877b400             mov       dword ptr [0xb477b8], eax
0047f954  6a50                     push      0x50
0047f956  68f0a55a00               push      0x5aa5f0
0047f95b  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f961  8d08                     lea       ecx, [eax]
0047f963  51                       push      ecx
0047f964  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047f96a  8d11                     lea       edx, [ecx]
0047f96c  52                       push      edx
0047f96d  e86ecffcff               call      0x44c8e0 ; _inline_
0047f972  83c410                   add       esp, 0x10
0047f975  68b0a25a00               push      0x5aa2b0
0047f97a  e8d1210200               call      0x4a1b50 ; _jwe_iinf
0047f97f  83c404                   add       esp, 4
0047f982  85c0                     test      eax, eax
0047f984  0f8572370000             jne       0x4830fc
0047f98a  68a4a25a00               push      0x5aa2a4
0047f98f  e8bc210200               call      0x4a1b50 ; _jwe_iinf
0047f994  83c404                   add       esp, 4
0047f997  85c0                     test      eax, eax
0047f999  0f855d370000             jne       0x4830fc
0047f99f  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047f9a5  8b18                     mov       ebx, dword ptr [eax]
0047f9a7  8b0db477b400             mov       ecx, dword ptr [0xb477b4]
0047f9ad  8d1578a25a00             lea       edx, [0x5aa278] ; bits=09020000, f32=7.300764999132297e-43
0047f9b3  895dfc                   mov       dword ptr [ebp - 4], ebx
0047f9b6  8d75fc                   lea       esi, [ebp - 4]
0047f9b9  897208                   mov       dword ptr [edx + 8], esi
0047f9bc  894df8                   mov       dword ptr [ebp - 8], ecx
0047f9bf  8d4df8                   lea       ecx, [ebp - 8]
0047f9c2  894a28                   mov       dword ptr [edx + 0x28], ecx
0047f9c5  52                       push      edx
0047f9c6  e8252c0200               call      0x4a25f0 ; _jwe_isfm
0047f9cb  83c404                   add       esp, 4
0047f9ce  d905b477b400             fld       dword ptr [0xb477b4]
0047f9d4  d81dbc77b400             fcomp     dword ptr [0xb477bc]
0047f9da  dfe0                     fnstsw    ax
0047f9dc  9e                       sahf
0047f9dd  0f8a41000000             jp        0x47fa24
0047f9e3  733f                     jae       0x47fa24
0047f9e5  8b05b477b400             mov       eax, dword ptr [0xb477b4]
0047f9eb  8b0dbc77b400             mov       ecx, dword ptr [0xb477bc]
0047f9f1  8d1540a25a00             lea       edx, [0x5aa240] ; bits=09020000, f32=7.300764999132297e-43
0047f9f7  895dfc                   mov       dword ptr [ebp - 4], ebx
0047f9fa  8d75fc                   lea       esi, [ebp - 4]
0047f9fd  897208                   mov       dword ptr [edx + 8], esi
0047fa00  8945f8                   mov       dword ptr [ebp - 8], eax
0047fa03  8d45f8                   lea       eax, [ebp - 8]
0047fa06  894228                   mov       dword ptr [edx + 0x28], eax
0047fa09  894df4                   mov       dword ptr [ebp - 0xc], ecx
0047fa0c  8d45f4                   lea       eax, [ebp - 0xc]
0047fa0f  894234                   mov       dword ptr [edx + 0x34], eax
0047fa12  52                       push      edx
0047fa13  e8d82b0200               call      0x4a25f0 ; _jwe_isfm
0047fa18  83c404                   add       esp, 4
0047fa1b  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047fa1e  c70001000000             mov       dword ptr [eax], 1
0047fa24  d905b477b400             fld       dword ptr [0xb477b4]
0047fa2a  d81db077b400             fcomp     dword ptr [0xb477b0]
0047fa30  dfe0                     fnstsw    ax
0047fa32  9e                       sahf
0047fa33  0f8a41000000             jp        0x47fa7a
0047fa39  733f                     jae       0x47fa7a
0047fa3b  8b05b477b400             mov       eax, dword ptr [0xb477b4]
0047fa41  8b0db077b400             mov       ecx, dword ptr [0xb477b0]
0047fa47  8d1508a25a00             lea       edx, [0x5aa208] ; bits=09020000, f32=7.300764999132297e-43
0047fa4d  895dfc                   mov       dword ptr [ebp - 4], ebx
0047fa50  8d75fc                   lea       esi, [ebp - 4]
0047fa53  897208                   mov       dword ptr [edx + 8], esi
0047fa56  8945f8                   mov       dword ptr [ebp - 8], eax
0047fa59  8d45f8                   lea       eax, [ebp - 8]
0047fa5c  894228                   mov       dword ptr [edx + 0x28], eax
0047fa5f  894df4                   mov       dword ptr [ebp - 0xc], ecx
0047fa62  8d45f4                   lea       eax, [ebp - 0xc]
0047fa65  894234                   mov       dword ptr [edx + 0x34], eax
0047fa68  52                       push      edx
0047fa69  e8822b0200               call      0x4a25f0 ; _jwe_isfm
0047fa6e  83c404                   add       esp, 4
0047fa71  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047fa74  c70001000000             mov       dword ptr [eax], 1
0047fa7a  6a50                     push      0x50
0047fa7c  68f0a55a00               push      0x5aa5f0
0047fa81  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fa87  8d08                     lea       ecx, [eax]
0047fa89  51                       push      ecx
0047fa8a  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047fa90  8d11                     lea       edx, [ecx]
0047fa92  52                       push      edx
0047fa93  e848cefcff               call      0x44c8e0 ; _inline_
0047fa98  83c410                   add       esp, 0x10
0047fa9b  68e8a15a00               push      0x5aa1e8
0047faa0  e8ab200200               call      0x4a1b50 ; _jwe_iinf
0047faa5  83c404                   add       esp, 4
0047faa8  85c0                     test      eax, eax
0047faaa  0f854c360000             jne       0x4830fc
0047fab0  68dca15a00               push      0x5aa1dc
0047fab5  e896200200               call      0x4a1b50 ; _jwe_iinf
0047faba  83c404                   add       esp, 4
0047fabd  85c0                     test      eax, eax
0047fabf  0f8537360000             jne       0x4830fc
0047fac5  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047facb  8b18                     mov       ebx, dword ptr [eax]
0047facd  8b0dfc77b400             mov       ecx, dword ptr [0xb477fc]
0047fad3  8d15b0a15a00             lea       edx, [0x5aa1b0] ; bits=09020000, f32=7.300764999132297e-43
0047fad9  895dfc                   mov       dword ptr [ebp - 4], ebx
0047fadc  8d75fc                   lea       esi, [ebp - 4]
0047fadf  897208                   mov       dword ptr [edx + 8], esi
0047fae2  894df8                   mov       dword ptr [ebp - 8], ecx
0047fae5  8d4df8                   lea       ecx, [ebp - 8]
0047fae8  894a28                   mov       dword ptr [edx + 0x28], ecx
0047faeb  52                       push      edx
0047faec  e8ff2a0200               call      0x4a25f0 ; _jwe_isfm
0047faf1  83c404                   add       esp, 4
0047faf4  d905fc77b400             fld       dword ptr [0xb477fc]
0047fafa  d81de08f5a00             fcomp     dword ptr [0x5a8fe0] ; bits=00000000, f32=0.0
0047fb00  dfe0                     fnstsw    ax
0047fb02  9e                       sahf
0047fb03  0f8a32000000             jp        0x47fb3b
0047fb09  7730                     ja        0x47fb3b
0047fb0b  8b05fc77b400             mov       eax, dword ptr [0xb477fc]
0047fb11  8d0d84a15a00             lea       ecx, [0x5aa184] ; bits=09020000, f32=7.300764999132297e-43
0047fb17  895dfc                   mov       dword ptr [ebp - 4], ebx
0047fb1a  8d55fc                   lea       edx, [ebp - 4]
0047fb1d  895108                   mov       dword ptr [ecx + 8], edx
0047fb20  8945f8                   mov       dword ptr [ebp - 8], eax
0047fb23  8d45f8                   lea       eax, [ebp - 8]
0047fb26  894128                   mov       dword ptr [ecx + 0x28], eax
0047fb29  51                       push      ecx
0047fb2a  e8c12a0200               call      0x4a25f0 ; _jwe_isfm
0047fb2f  83c404                   add       esp, 4
0047fb32  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047fb35  c70001000000             mov       dword ptr [eax], 1
0047fb3b  6a50                     push      0x50
0047fb3d  68f0a55a00               push      0x5aa5f0
0047fb42  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fb48  8d08                     lea       ecx, [eax]
0047fb4a  51                       push      ecx
0047fb4b  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047fb51  8d11                     lea       edx, [ecx]
0047fb53  52                       push      edx
0047fb54  e887cdfcff               call      0x44c8e0 ; _inline_
0047fb59  83c410                   add       esp, 0x10
0047fb5c  6864a15a00               push      0x5aa164
0047fb61  e8ea1f0200               call      0x4a1b50 ; _jwe_iinf
0047fb66  83c404                   add       esp, 4
0047fb69  85c0                     test      eax, eax
0047fb6b  0f858b350000             jne       0x4830fc
0047fb71  6858a15a00               push      0x5aa158
0047fb76  e8d51f0200               call      0x4a1b50 ; _jwe_iinf
0047fb7b  83c404                   add       esp, 4
0047fb7e  85c0                     test      eax, eax
0047fb80  0f8576350000             jne       0x4830fc
0047fb86  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fb8c  8b18                     mov       ebx, dword ptr [eax]
0047fb8e  8b0d0078b400             mov       ecx, dword ptr [0xb47800]
0047fb94  8d152ca15a00             lea       edx, [0x5aa12c] ; bits=09020000, f32=7.300764999132297e-43
0047fb9a  895dfc                   mov       dword ptr [ebp - 4], ebx
0047fb9d  8d75fc                   lea       esi, [ebp - 4]
0047fba0  897208                   mov       dword ptr [edx + 8], esi
0047fba3  894df8                   mov       dword ptr [ebp - 8], ecx
0047fba6  8d4df8                   lea       ecx, [ebp - 8]
0047fba9  894a28                   mov       dword ptr [edx + 0x28], ecx
0047fbac  52                       push      edx
0047fbad  e83e2a0200               call      0x4a25f0 ; _jwe_isfm
0047fbb2  83c404                   add       esp, 4
0047fbb5  d9050078b400             fld       dword ptr [0xb47800]
0047fbbb  d815e08f5a00             fcom      dword ptr [0x5a8fe0] ; bits=00000000, f32=0.0
0047fbc1  dfe0                     fnstsw    ax
0047fbc3  9e                       sahf
0047fbc4  0f8a02000000             jp        0x47fbcc
0047fbca  7617                     jbe       0x47fbe3
0047fbcc  d81dec8f5a00             fcomp     dword ptr [0x5a8fec] ; bits=0000803f, f32=1.0
0047fbd2  dfe0                     fnstsw    ax
0047fbd4  9e                       sahf
0047fbd5  0f8a3a000000             jp        0x47fc15
0047fbdb  0f8634000000             jbe       0x47fc15
0047fbe1  eb02                     jmp       0x47fbe5
0047fbe3  ddd8                     fstp      st(0)
0047fbe5  8b050078b400             mov       eax, dword ptr [0xb47800]
0047fbeb  8d0d00a15a00             lea       ecx, [0x5aa100] ; bits=09020000, f32=7.300764999132297e-43
0047fbf1  895dfc                   mov       dword ptr [ebp - 4], ebx
0047fbf4  8d55fc                   lea       edx, [ebp - 4]
0047fbf7  895108                   mov       dword ptr [ecx + 8], edx
0047fbfa  8945f8                   mov       dword ptr [ebp - 8], eax
0047fbfd  8d45f8                   lea       eax, [ebp - 8]
0047fc00  894128                   mov       dword ptr [ecx + 0x28], eax
0047fc03  51                       push      ecx
0047fc04  e8e7290200               call      0x4a25f0 ; _jwe_isfm
0047fc09  83c404                   add       esp, 4
0047fc0c  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047fc0f  c70001000000             mov       dword ptr [eax], 1
0047fc15  6a50                     push      0x50
0047fc17  68f0a55a00               push      0x5aa5f0
0047fc1c  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fc22  8d08                     lea       ecx, [eax]
0047fc24  51                       push      ecx
0047fc25  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047fc2b  8d11                     lea       edx, [ecx]
0047fc2d  52                       push      edx
0047fc2e  e8adccfcff               call      0x44c8e0 ; _inline_
0047fc33  83c410                   add       esp, 0x10
0047fc36  6a10                     push      0x10
0047fc38  6a05                     push      5
0047fc3a  6a50                     push      0x50
0047fc3c  6848a45a00               push      0x5aa448
0047fc41  6890a65a00               push      0x5aa690
0047fc46  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
0047fc49  8d03                     lea       eax, [ebx]
0047fc4b  50                       push      eax
0047fc4c  6830935a00               push      0x5a9330
0047fc51  68f0a55a00               push      0x5aa5f0
0047fc56  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fc5c  8d08                     lea       ecx, [eax]
0047fc5e  51                       push      ecx
0047fc5f  e8ccaafdff               call      0x45a730 ; _read_tabid_
0047fc64  83c424                   add       esp, 0x24
0047fc67  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fc6d  8b30                     mov       esi, dword ptr [eax]
0047fc6f  6a10                     push      0x10
0047fc71  6890a65a00               push      0x5aa690
0047fc76  e8d5fdfcff               call      0x44fa50 ; _lenstr_
0047fc7b  83c408                   add       esp, 8
0047fc7e  89c2                     mov       edx, eax
0047fc80  c1fa1f                   sar       edx, 0x1f
0047fc83  f7d2                     not       edx
0047fc85  21d0                     and       eax, edx
0047fc87  8d0dd4a05a00             lea       ecx, [0x5aa0d4] ; bits=09020000, f32=7.300764999132297e-43
0047fc8d  8975fc                   mov       dword ptr [ebp - 4], esi
0047fc90  8d55fc                   lea       edx, [ebp - 4]
0047fc93  895108                   mov       dword ptr [ecx + 8], edx
0047fc96  894124                   mov       dword ptr [ecx + 0x24], eax
0047fc99  51                       push      ecx
0047fc9a  e851290200               call      0x4a25f0 ; _jwe_isfm
0047fc9f  83c404                   add       esp, 4
0047fca2  833d48a45a0000           cmp       dword ptr [0x5aa448], 0 ; bits=00000000, f32=0.0
0047fca9  7d28                     jge       0x47fcd3
0047fcab  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fcb1  8b08                     mov       ecx, dword ptr [eax]
0047fcb3  8d15b4a05a00             lea       edx, [0x5aa0b4] ; bits=69020000, f32=8.646011524884121e-43
0047fcb9  894dfc                   mov       dword ptr [ebp - 4], ecx
0047fcbc  8d4dfc                   lea       ecx, [ebp - 4]
0047fcbf  894a08                   mov       dword ptr [edx + 8], ecx
0047fcc2  52                       push      edx
0047fcc3  e828290200               call      0x4a25f0 ; _jwe_isfm
0047fcc8  83c404                   add       esp, 4
0047fccb  c70301000000             mov       dword ptr [ebx], 1
0047fcd1  eb37                     jmp       0x47fd0a
0047fcd3  833d48a45a0000           cmp       dword ptr [0x5aa448], 0 ; bits=00000000, f32=0.0
0047fcda  7e2e                     jle       0x47fd0a
0047fcdc  89d8                     mov       eax, ebx
0047fcde  8d00                     lea       eax, [eax]
0047fce0  50                       push      eax
0047fce1  6848a45a00               push      0x5aa448
0047fce6  8d0560905a00             lea       eax, [0x5a9060] ; bits=16000000, f32=3.0828566215145976e-44
0047fcec  8d48dc                   lea       ecx, [eax - 0x24]
0047fcef  51                       push      ecx
0047fcf0  68f05a0e04               push      0x40e5af0
0047fcf5  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
0047fcfb  8d11                     lea       edx, [ecx]
0047fcfd  52                       push      edx
0047fcfe  8d40c0                   lea       eax, [eax - 0x40]
0047fd01  50                       push      eax
0047fd02  e84980fbff               call      0x437d50 ; _chktab_
0047fd07  83c418                   add       esp, 0x18
0047fd0a  6a50                     push      0x50
0047fd0c  68f0a55a00               push      0x5aa5f0
0047fd11  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fd17  8d08                     lea       ecx, [eax]
0047fd19  51                       push      ecx
0047fd1a  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047fd20  8d11                     lea       edx, [ecx]
0047fd22  52                       push      edx
0047fd23  e8b8cbfcff               call      0x44c8e0 ; _inline_
0047fd28  83c410                   add       esp, 0x10
0047fd2b  6894a05a00               push      0x5aa094
0047fd30  e81b1e0200               call      0x4a1b50 ; _jwe_iinf
0047fd35  83c404                   add       esp, 4
0047fd38  85c0                     test      eax, eax
0047fd3a  0f85bc330000             jne       0x4830fc
0047fd40  6888a05a00               push      0x5aa088
0047fd45  e8061e0200               call      0x4a1b50 ; _jwe_iinf
0047fd4a  83c404                   add       esp, 4
0047fd4d  85c0                     test      eax, eax
0047fd4f  0f85a7330000             jne       0x4830fc
0047fd55  d90594a45a00             fld       dword ptr [0x5aa494] ; bits=00000000, f32=0.0
0047fd5b  d9ee                     fldz
0047fd5d  d9c9                     fxch      st(1)
0047fd5f  dae9                     fucompp
0047fd61  dfe0                     fnstsw    ax
0047fd63  9e                       sahf
0047fd64  0f8a0e000000             jp        0x47fd78
0047fd6a  750c                     jne       0x47fd78
0047fd6c  8b05f08f5a00             mov       eax, dword ptr [0x5a8ff0] ; bits=cdcccc3d, f32=0.10000000149011612
0047fd72  890594a45a00             mov       dword ptr [0x5aa494], eax ; bits=00000000, f32=0.0
0047fd78  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fd7e  8b08                     mov       ecx, dword ptr [eax]
0047fd80  8b1594a45a00             mov       edx, dword ptr [0x5aa494] ; bits=00000000, f32=0.0
0047fd86  8d1d5ca05a00             lea       ebx, [0x5aa05c] ; bits=09020000, f32=7.300764999132297e-43
0047fd8c  894dfc                   mov       dword ptr [ebp - 4], ecx
0047fd8f  8d4dfc                   lea       ecx, [ebp - 4]
0047fd92  894b08                   mov       dword ptr [ebx + 8], ecx
0047fd95  8955f8                   mov       dword ptr [ebp - 8], edx
0047fd98  8d4df8                   lea       ecx, [ebp - 8]
0047fd9b  894b28                   mov       dword ptr [ebx + 0x28], ecx
0047fd9e  53                       push      ebx
0047fd9f  e84c280200               call      0x4a25f0 ; _jwe_isfm
0047fda4  83c404                   add       esp, 4
0047fda7  6a50                     push      0x50
0047fda9  68f0a55a00               push      0x5aa5f0
0047fdae  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fdb4  8d08                     lea       ecx, [eax]
0047fdb6  51                       push      ecx
0047fdb7  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047fdbd  8d11                     lea       edx, [ecx]
0047fdbf  52                       push      edx
0047fdc0  e81bcbfcff               call      0x44c8e0 ; _inline_
0047fdc5  83c410                   add       esp, 0x10
0047fdc8  683ca05a00               push      0x5aa03c
0047fdcd  e87e1d0200               call      0x4a1b50 ; _jwe_iinf
0047fdd2  83c404                   add       esp, 4
0047fdd5  85c0                     test      eax, eax
0047fdd7  0f851f330000             jne       0x4830fc
0047fddd  6830a05a00               push      0x5aa030
0047fde2  e8691d0200               call      0x4a1b50 ; _jwe_iinf
0047fde7  83c404                   add       esp, 4
0047fdea  85c0                     test      eax, eax
0047fdec  0f850a330000             jne       0x4830fc
0047fdf2  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fdf8  8b08                     mov       ecx, dword ptr [eax]
0047fdfa  8b15c8a45a00             mov       edx, dword ptr [0x5aa4c8] ; bits=00000000, f32=0.0
0047fe00  8d1d04a05a00             lea       ebx, [0x5aa004] ; bits=09020000, f32=7.300764999132297e-43
0047fe06  894dfc                   mov       dword ptr [ebp - 4], ecx
0047fe09  8d4dfc                   lea       ecx, [ebp - 4]
0047fe0c  894b08                   mov       dword ptr [ebx + 8], ecx
0047fe0f  8955f8                   mov       dword ptr [ebp - 8], edx
0047fe12  8d4df8                   lea       ecx, [ebp - 8]
0047fe15  894b28                   mov       dword ptr [ebx + 0x28], ecx
0047fe18  53                       push      ebx
0047fe19  e8d2270200               call      0x4a25f0 ; _jwe_isfm
0047fe1e  83c404                   add       esp, 4
0047fe21  6a50                     push      0x50
0047fe23  68f0a55a00               push      0x5aa5f0
0047fe28  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fe2e  8d08                     lea       ecx, [eax]
0047fe30  51                       push      ecx
0047fe31  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047fe37  8d11                     lea       edx, [ecx]
0047fe39  52                       push      edx
0047fe3a  e8a1cafcff               call      0x44c8e0 ; _inline_
0047fe3f  83c410                   add       esp, 0x10
0047fe42  68e49f5a00               push      0x5a9fe4
0047fe47  e8041d0200               call      0x4a1b50 ; _jwe_iinf
0047fe4c  83c404                   add       esp, 4
0047fe4f  85c0                     test      eax, eax
0047fe51  0f85a5320000             jne       0x4830fc
0047fe57  68d89f5a00               push      0x5a9fd8
0047fe5c  e8ef1c0200               call      0x4a1b50 ; _jwe_iinf
0047fe61  83c404                   add       esp, 4
0047fe64  85c0                     test      eax, eax
0047fe66  0f8590320000             jne       0x4830fc
0047fe6c  d905cca45a00             fld       dword ptr [0x5aa4cc] ; bits=00000000, f32=0.0
0047fe72  d9ee                     fldz
0047fe74  d9c9                     fxch      st(1)
0047fe76  dae9                     fucompp
0047fe78  dfe0                     fnstsw    ax
0047fe7a  9e                       sahf
0047fe7b  0f8a0e000000             jp        0x47fe8f
0047fe81  750c                     jne       0x47fe8f
0047fe83  8b05f08f5a00             mov       eax, dword ptr [0x5a8ff0] ; bits=cdcccc3d, f32=0.10000000149011612
0047fe89  8905cca45a00             mov       dword ptr [0x5aa4cc], eax ; bits=00000000, f32=0.0
0047fe8f  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fe95  8b08                     mov       ecx, dword ptr [eax]
0047fe97  8b15cca45a00             mov       edx, dword ptr [0x5aa4cc] ; bits=00000000, f32=0.0
0047fe9d  8d1dac9f5a00             lea       ebx, [0x5a9fac] ; bits=09020000, f32=7.300764999132297e-43
0047fea3  894dfc                   mov       dword ptr [ebp - 4], ecx
0047fea6  8d4dfc                   lea       ecx, [ebp - 4]
0047fea9  894b08                   mov       dword ptr [ebx + 8], ecx
0047feac  8955f8                   mov       dword ptr [ebp - 8], edx
0047feaf  8d4df8                   lea       ecx, [ebp - 8]
0047feb2  894b28                   mov       dword ptr [ebx + 0x28], ecx
0047feb5  53                       push      ebx
0047feb6  e835270200               call      0x4a25f0 ; _jwe_isfm
0047febb  83c404                   add       esp, 4
0047febe  6a50                     push      0x50
0047fec0  68f0a55a00               push      0x5aa5f0
0047fec5  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fecb  8d08                     lea       ecx, [eax]
0047fecd  51                       push      ecx
0047fece  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047fed4  8d11                     lea       edx, [ecx]
0047fed6  52                       push      edx
0047fed7  e804cafcff               call      0x44c8e0 ; _inline_
0047fedc  83c410                   add       esp, 0x10
0047fedf  688c9f5a00               push      0x5a9f8c
0047fee4  e8671c0200               call      0x4a1b50 ; _jwe_iinf
0047fee9  83c404                   add       esp, 4
0047feec  85c0                     test      eax, eax
0047feee  0f8508320000             jne       0x4830fc
0047fef4  68809f5a00               push      0x5a9f80
0047fef9  e8521c0200               call      0x4a1b50 ; _jwe_iinf
0047fefe  83c404                   add       esp, 4
0047ff01  85c0                     test      eax, eax
0047ff03  0f85f3310000             jne       0x4830fc
0047ff09  d905c4a45a00             fld       dword ptr [0x5aa4c4] ; bits=00000000, f32=0.0
0047ff0f  d9ee                     fldz
0047ff11  d9c9                     fxch      st(1)
0047ff13  dae9                     fucompp
0047ff15  dfe0                     fnstsw    ax
0047ff17  9e                       sahf
0047ff18  0f8a0e000000             jp        0x47ff2c
0047ff1e  750c                     jne       0x47ff2c
0047ff20  8b05f48f5a00             mov       eax, dword ptr [0x5a8ff4] ; bits=0ad7a33c, f32=0.019999999552965164
0047ff26  8905c4a45a00             mov       dword ptr [0x5aa4c4], eax ; bits=00000000, f32=0.0
0047ff2c  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047ff32  8b08                     mov       ecx, dword ptr [eax]
0047ff34  8b15c4a45a00             mov       edx, dword ptr [0x5aa4c4] ; bits=00000000, f32=0.0
0047ff3a  8d35549f5a00             lea       esi, [0x5a9f54] ; bits=09020000, f32=7.300764999132297e-43
0047ff40  894dfc                   mov       dword ptr [ebp - 4], ecx
0047ff43  8d4dfc                   lea       ecx, [ebp - 4]
0047ff46  894e08                   mov       dword ptr [esi + 8], ecx
0047ff49  8955f8                   mov       dword ptr [ebp - 8], edx
0047ff4c  8d4df8                   lea       ecx, [ebp - 8]
0047ff4f  894e28                   mov       dword ptr [esi + 0x28], ecx
0047ff52  56                       push      esi
0047ff53  e898260200               call      0x4a25f0 ; _jwe_isfm
0047ff58  83c404                   add       esp, 4
0047ff5b  6a50                     push      0x50
0047ff5d  68f0a55a00               push      0x5aa5f0
0047ff62  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047ff68  8d08                     lea       ecx, [eax]
0047ff6a  51                       push      ecx
0047ff6b  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0047ff71  8d11                     lea       edx, [ecx]
0047ff73  52                       push      edx
0047ff74  e867c9fcff               call      0x44c8e0 ; _inline_
0047ff79  83c410                   add       esp, 0x10
0047ff7c  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047ff82  8b30                     mov       esi, dword ptr [eax]
0047ff84  8d0d289f5a00             lea       ecx, [0x5a9f28] ; bits=09820000, f32=4.664782457890884e-41
0047ff8a  8975fc                   mov       dword ptr [ebp - 4], esi
0047ff8d  8d55fc                   lea       edx, [ebp - 4]
0047ff90  895108                   mov       dword ptr [ecx + 8], edx
0047ff93  51                       push      ecx
0047ff94  e8e72e0200               call      0x4a2e80 ; _jwe_ilst
0047ff99  83c404                   add       esp, 4
0047ff9c  8d05fc9e5a00             lea       eax, [0x5a9efc] ; bits=09020000, f32=7.300764999132297e-43
0047ffa2  8975fc                   mov       dword ptr [ebp - 4], esi
0047ffa5  8d4dfc                   lea       ecx, [ebp - 4]
0047ffa8  894808                   mov       dword ptr [eax + 8], ecx
0047ffab  50                       push      eax
0047ffac  e83f260200               call      0x4a25f0 ; _jwe_isfm
0047ffb1  83c404                   add       esp, 4
0047ffb4  8d05a0a65a00             lea       eax, [0x5aa6a0] ; bits=00000000, f32=0.0
0047ffba  c60052                   mov       byte ptr [eax], 0x52
0047ffbd  c6400149                 mov       byte ptr [eax + 1], 0x49
0047ffc1  c6400247                 mov       byte ptr [eax + 2], 0x47
0047ffc5  c6400348                 mov       byte ptr [eax + 3], 0x48
0047ffc9  c6400454                 mov       byte ptr [eax + 4], 0x54
0047ffcd  6a05                     push      5
0047ffcf  6a50                     push      0x50
0047ffd1  6820a85a00               push      0x5aa820
0047ffd6  6810a85a00               push      0x5aa810
0047ffdb  6878a45a00               push      0x5aa478
0047ffe0  68a0a65a00               push      0x5aa6a0
0047ffe5  6824905a00               push      0x5a9024
0047ffea  68f0a55a00               push      0x5aa5f0
0047ffef  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0047fff5  8d08                     lea       ecx, [eax]
0047fff7  51                       push      ecx
0047fff8  e8e3ecfcff               call      0x44ece0 ; _get_item_limits_
0047fffd  83c424                   add       esp, 0x24
00480000  8b0524a85a00             mov       eax, dword ptr [0x5aa824] ; bits=00000000, f32=0.0
00480006  2b0514a85a00             sub       eax, dword ptr [0x5aa814] ; bits=00000000, f32=0.0
0048000c  40                       inc       eax
0048000d  89c3                     mov       ebx, eax
0048000f  d9ee                     fldz
00480011  db7da4                   fstp      xword ptr [ebp - 0x5c]
00480014  b801000000               mov       eax, 1
00480019  c7057ca45a0000000000     mov       dword ptr [0x5aa47c], 0 ; bits=00000000, f32=0.0
00480023  89da                     mov       edx, ebx
00480025  c1fa1f                   sar       edx, 0x1f
00480028  f7d2                     not       edx
0048002a  89d9                     mov       ecx, ebx
0048002c  21d1                     and       ecx, edx
0048002e  898d70feffff             mov       dword ptr [ebp - 0x190], ecx
00480034  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
00480037  8d1548a45a00             lea       edx, [0x5aa448] ; bits=00000000, f32=0.0
0048003d  db6da4                   fld       xword ptr [ebp - 0x5c]
00480040  89856cfeffff             mov       dword ptr [ebp - 0x194], eax
00480046  898d68feffff             mov       dword ptr [ebp - 0x198], ecx
0048004c  899564feffff             mov       dword ptr [ebp - 0x19c], edx
00480052  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00480055  6a50                     push      0x50
00480057  68f0a55a00               push      0x5aa5f0
0048005c  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480062  8d08                     lea       ecx, [eax]
00480064  51                       push      ecx
00480065  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0048006b  8d11                     lea       edx, [ecx]
0048006d  52                       push      edx
0048006e  e86dc8fcff               call      0x44c8e0 ; _inline_
00480073  83c410                   add       esp, 0x10
00480076  6a50                     push      0x50
00480078  8b856cfeffff             mov       eax, dword ptr [ebp - 0x194]
0048007e  8d0c852ca85a00           lea       ecx, [eax*4 + 0x5aa82c]
00480085  51                       push      ecx
00480086  8d0c85cca85a00           lea       ecx, [eax*4 + 0x5aa8cc]
0048008d  51                       push      ecx
0048008e  8d0c856ca75a00           lea       ecx, [eax*4 + 0x5aa76c]
00480095  51                       push      ecx
00480096  8d0c856ca95a00           lea       ecx, [eax*4 + 0x5aa96c]
0048009d  51                       push      ecx
0048009e  687ca45a00               push      0x5aa47c
004800a3  8b8d68feffff             mov       ecx, dword ptr [ebp - 0x198]
004800a9  8d11                     lea       edx, [ecx]
004800ab  52                       push      edx
004800ac  6820a85a00               push      0x5aa820
004800b1  6810a85a00               push      0x5aa810
004800b6  6878a45a00               push      0x5aa478
004800bb  68f0a55a00               push      0x5aa5f0
004800c0  8b9578feffff             mov       edx, dword ptr [ebp - 0x188]
004800c6  8d32                     lea       esi, [edx]
004800c8  56                       push      esi
004800c9  e8b2f0ffff               call      0x47f180 ; _read_ufgate_items_
004800ce  83c430                   add       esp, 0x30
004800d1  8b856cfeffff             mov       eax, dword ptr [ebp - 0x194]
004800d7  c704858cac5a0000000000   mov       dword ptr [eax*4 + 0x5aac8c], 0
004800e2  c70485ecab5a0000000000   mov       dword ptr [eax*4 + 0x5aabec], 0
004800ed  d904856ca95a00           fld       dword ptr [eax*4 + 0x5aa96c]
004800f4  db6dd4                   fld       xword ptr [ebp - 0x2c]
004800f7  d9c9                     fxch      st(1)
004800f9  d8d1                     fcom      st(1)
004800fb  ddd9                     fstp      st(1)
004800fd  dfe0                     fnstsw    ax
004800ff  9e                       sahf
00480100  0f8a0f000000             jp        0x480115
00480106  770d                     ja        0x480115
00480108  ddd8                     fstp      st(0)
0048010a  ff8d6cfeffff             dec       dword ptr [ebp - 0x194]
00480110  e931020000               jmp       0x480346
00480115  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00480118  8b8d6cfeffff             mov       ecx, dword ptr [ebp - 0x194]
0048011e  8b05cca45a00             mov       eax, dword ptr [0x5aa4cc] ; bits=00000000, f32=0.0
00480124  89048d8cac5a00           mov       dword ptr [ecx*4 + 0x5aac8c], eax
0048012b  8b05c4a45a00             mov       eax, dword ptr [0x5aa4c4] ; bits=00000000, f32=0.0
00480131  89048decab5a00           mov       dword ptr [ecx*4 + 0x5aabec], eax
00480138  8d048d6ca75a00           lea       eax, [ecx*4 + 0x5aa76c]
0048013f  50                       push      eax
00480140  6a10                     push      0x10
00480142  6800a75a00               push      0x5aa700
00480147  e84472ffff               call      0x477390 ; _get_tabid_
0048014c  83c40c                   add       esp, 0xc
0048014f  8d05c8a65a00             lea       eax, [0x5aa6c8] ; bits=00000000, f32=0.0
00480155  8d0d00a75a00             lea       ecx, [0x5aa700] ; bits=00000000, f32=0.0
0048015b  8a11                     mov       dl, byte ptr [ecx]
0048015d  8810                     mov       byte ptr [eax], dl
0048015f  8a5101                   mov       dl, byte ptr [ecx + 1]
00480162  885001                   mov       byte ptr [eax + 1], dl
00480165  8a5102                   mov       dl, byte ptr [ecx + 2]
00480168  885002                   mov       byte ptr [eax + 2], dl
0048016b  8a5103                   mov       dl, byte ptr [ecx + 3]
0048016e  885003                   mov       byte ptr [eax + 3], dl
00480171  8a5104                   mov       dl, byte ptr [ecx + 4]
00480174  885004                   mov       byte ptr [eax + 4], dl
00480177  8a5105                   mov       dl, byte ptr [ecx + 5]
0048017a  885005                   mov       byte ptr [eax + 5], dl
0048017d  8a5106                   mov       dl, byte ptr [ecx + 6]
00480180  885006                   mov       byte ptr [eax + 6], dl
00480183  8a5107                   mov       dl, byte ptr [ecx + 7]
00480186  885007                   mov       byte ptr [eax + 7], dl
00480189  8a5108                   mov       dl, byte ptr [ecx + 8]
0048018c  885008                   mov       byte ptr [eax + 8], dl
0048018f  8a5109                   mov       dl, byte ptr [ecx + 9]
00480192  885009                   mov       byte ptr [eax + 9], dl
00480195  8a510a                   mov       dl, byte ptr [ecx + 0xa]
00480198  88500a                   mov       byte ptr [eax + 0xa], dl
0048019b  8a510b                   mov       dl, byte ptr [ecx + 0xb]
0048019e  88500b                   mov       byte ptr [eax + 0xb], dl
004801a1  8a510c                   mov       dl, byte ptr [ecx + 0xc]
004801a4  88500c                   mov       byte ptr [eax + 0xc], dl
004801a7  8a510d                   mov       dl, byte ptr [ecx + 0xd]
004801aa  88500d                   mov       byte ptr [eax + 0xd], dl
004801ad  8a510e                   mov       dl, byte ptr [ecx + 0xe]
004801b0  88500e                   mov       byte ptr [eax + 0xe], dl
004801b3  8a510f                   mov       dl, byte ptr [ecx + 0xf]
004801b6  88500f                   mov       byte ptr [eax + 0xf], dl
004801b9  8d3da8a65a00             lea       edi, [0x5aa6a8] ; bits=00000000, f32=0.0
004801bf  8d3538935a00             lea       esi, [0x5a9338] ; bits=20202020, f32=1.3563156426940112e-19
004801c5  b908000000               mov       ecx, 8
004801ca  f3a5                     rep movsd dword ptr es:[edi], dword ptr [esi]
004801cc  8b057ca45a00             mov       eax, dword ptr [0x5aa47c] ; bits=00000000, f32=0.0
004801d2  89d9                     mov       ecx, ebx
004801d4  29c1                     sub       ecx, eax
004801d6  8d5101                   lea       edx, [ecx + 1]
004801d9  89de                     mov       esi, ebx
004801db  29d6                     sub       esi, edx
004801dd  46                       inc       esi
004801de  89f2                     mov       edx, esi
004801e0  c1fa1f                   sar       edx, 0x1f
004801e3  f7d2                     not       edx
004801e5  21d6                     and       esi, edx
004801e7  89c2                     mov       edx, eax
004801e9  c1fa1f                   sar       edx, 0x1f
004801ec  f7d2                     not       edx
004801ee  21d0                     and       eax, edx
004801f0  8d0c0da8a65a00           lea       ecx, [ecx + 0x5aa6a8]
004801f7  50                       push      eax
004801f8  56                       push      esi
004801f9  68c8a65a00               push      0x5aa6c8
004801fe  51                       push      ecx
004801ff  e8acf00100               call      0x49f2b0 ; _f_scmov
00480204  83c410                   add       esp, 0x10
00480207  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0048020d  8b956cfeffff             mov       edx, dword ptr [ebp - 0x194]
00480213  8b08                     mov       ecx, dword ptr [eax]
00480215  8b34956ca95a00           mov       esi, dword ptr [edx*4 + 0x5aa96c]
0048021c  8b3c95cca85a00           mov       edi, dword ptr [edx*4 + 0x5aa8cc]
00480223  8b04952ca85a00           mov       eax, dword ptr [edx*4 + 0x5aa82c]
0048022a  898da4fdffff             mov       dword ptr [ebp - 0x25c], ecx
00480230  8d0dac9e5a00             lea       ecx, [0x5a9eac] ; bits=09020000, f32=7.300764999132297e-43
00480236  89b5a0fdffff             mov       dword ptr [ebp - 0x260], esi
0048023c  8bb5a4fdffff             mov       esi, dword ptr [ebp - 0x25c]
00480242  8975fc                   mov       dword ptr [ebp - 4], esi
00480245  8d75fc                   lea       esi, [ebp - 4]
00480248  897108                   mov       dword ptr [ecx + 8], esi
0048024b  8bb5a0fdffff             mov       esi, dword ptr [ebp - 0x260]
00480251  8975f8                   mov       dword ptr [ebp - 8], esi
00480254  8d75f8                   lea       esi, [ebp - 8]
00480257  897128                   mov       dword ptr [ecx + 0x28], esi
0048025a  8bb570feffff             mov       esi, dword ptr [ebp - 0x190]
00480260  897130                   mov       dword ptr [ecx + 0x30], esi
00480263  897df4                   mov       dword ptr [ebp - 0xc], edi
00480266  8d7df4                   lea       edi, [ebp - 0xc]
00480269  897940                   mov       dword ptr [ecx + 0x40], edi
0048026c  8945f0                   mov       dword ptr [ebp - 0x10], eax
0048026f  8d45f0                   lea       eax, [ebp - 0x10]
00480272  89414c                   mov       dword ptr [ecx + 0x4c], eax
00480275  51                       push      ecx
00480276  e875230200               call      0x4a25f0 ; _jwe_isfm
0048027b  83c404                   add       esp, 4
0048027e  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00480281  8d00                     lea       eax, [eax]
00480283  50                       push      eax
00480284  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00480287  8d00                     lea       eax, [eax]
00480289  50                       push      eax
0048028a  8b856cfeffff             mov       eax, dword ptr [ebp - 0x194]
00480290  8d0c856ca75a00           lea       ecx, [eax*4 + 0x5aa76c]
00480297  51                       push      ecx
00480298  683c905a00               push      0x5a903c
0048029d  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
004802a3  8d11                     lea       edx, [ecx]
004802a5  52                       push      edx
004802a6  e8e575fbff               call      0x437890 ; _tabchk_
004802ab  83c414                   add       esp, 0x14
004802ae  8b8564feffff             mov       eax, dword ptr [ebp - 0x19c]
004802b4  db00                     fild      dword ptr [eax]
004802b6  d9ee                     fldz
004802b8  d9c9                     fxch      st(1)
004802ba  dde9                     fucomp    st(1)
004802bc  db6dd4                   fld       xword ptr [ebp - 0x2c]
004802bf  dfe0                     fnstsw    ax
004802c1  9e                       sahf
004802c2  0f8a6d000000             jp        0x480335
004802c8  756b                     jne       0x480335
004802ca  8b856cfeffff             mov       eax, dword ptr [ebp - 0x194]
004802d0  d90485cca85a00           fld       dword ptr [eax*4 + 0x5aa8cc]
004802d7  d8d2                     fcom      st(2)
004802d9  ddda                     fstp      st(2)
004802db  d9c9                     fxch      st(1)
004802dd  dfe0                     fnstsw    ax
004802df  9e                       sahf
004802e0  0f8a02000000             jp        0x4802e8
004802e6  7611                     jbe       0x4802f9
004802e8  d815ec8f5a00             fcom      dword ptr [0x5a8fec] ; bits=0000803f, f32=1.0
004802ee  dfe0                     fnstsw    ax
004802f0  9e                       sahf
004802f1  0f8a42000000             jp        0x480339
004802f7  7640                     jbe       0x480339
004802f9  d9c9                     fxch      st(1)
004802fb  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480301  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00480304  8b08                     mov       ecx, dword ptr [eax]
00480306  8d15809e5a00             lea       edx, [0x5a9e80] ; bits=09020000, f32=7.300764999132297e-43
0048030c  894dfc                   mov       dword ptr [ebp - 4], ecx
0048030f  8d4dfc                   lea       ecx, [ebp - 4]
00480312  894a08                   mov       dword ptr [edx + 8], ecx
00480315  d95df8                   fstp      dword ptr [ebp - 8]
00480318  8d4df8                   lea       ecx, [ebp - 8]
0048031b  894a28                   mov       dword ptr [edx + 0x28], ecx
0048031e  52                       push      edx
0048031f  e8cc220200               call      0x4a25f0 ; _jwe_isfm
00480324  db6dd4                   fld       xword ptr [ebp - 0x2c]
00480327  83c404                   add       esp, 4
0048032a  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0048032d  c70001000000             mov       dword ptr [eax], 1
00480333  eb06                     jmp       0x48033b
00480335  ddd9                     fstp      st(1)
00480337  eb02                     jmp       0x48033b
00480339  ddd8                     fstp      st(0)
0048033b  ff856cfeffff             inc       dword ptr [ebp - 0x194]
00480341  e90cfdffff               jmp       0x480052
00480346  83bd6cfeffff02           cmp       dword ptr [ebp - 0x194], 2
0048034d  7d29                     jge       0x480378
0048034f  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480355  8b08                     mov       ecx, dword ptr [eax]
00480357  8d15609e5a00             lea       edx, [0x5a9e60] ; bits=69020000, f32=8.646011524884121e-43
0048035d  894dfc                   mov       dword ptr [ebp - 4], ecx
00480360  8d4dfc                   lea       ecx, [ebp - 4]
00480363  894a08                   mov       dword ptr [edx + 8], ecx
00480366  52                       push      edx
00480367  e884220200               call      0x4a25f0 ; _jwe_isfm
0048036c  83c404                   add       esp, 4
0048036f  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00480372  c70001000000             mov       dword ptr [eax], 1
00480378  6a50                     push      0x50
0048037a  68f0a55a00               push      0x5aa5f0
0048037f  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480385  8d08                     lea       ecx, [eax]
00480387  51                       push      ecx
00480388  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0048038e  8d11                     lea       edx, [ecx]
00480390  52                       push      edx
00480391  e84ac5fcff               call      0x44c8e0 ; _inline_
00480396  83c410                   add       esp, 0x10
00480399  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0048039f  8b18                     mov       ebx, dword ptr [eax]
004803a1  8d0d349e5a00             lea       ecx, [0x5a9e34] ; bits=09820000, f32=4.664782457890884e-41
004803a7  895dfc                   mov       dword ptr [ebp - 4], ebx
004803aa  8d55fc                   lea       edx, [ebp - 4]
004803ad  895108                   mov       dword ptr [ecx + 8], edx
004803b0  51                       push      ecx
004803b1  e8ca2a0200               call      0x4a2e80 ; _jwe_ilst
004803b6  83c404                   add       esp, 4
004803b9  8d05089e5a00             lea       eax, [0x5a9e08] ; bits=09020000, f32=7.300764999132297e-43
004803bf  895dfc                   mov       dword ptr [ebp - 4], ebx
004803c2  8d4dfc                   lea       ecx, [ebp - 4]
004803c5  894808                   mov       dword ptr [eax + 8], ecx
004803c8  50                       push      eax
004803c9  e822220200               call      0x4a25f0 ; _jwe_isfm
004803ce  83c404                   add       esp, 4
004803d1  6a50                     push      0x50
004803d3  68f0a55a00               push      0x5aa5f0
004803d8  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
004803de  8d08                     lea       ecx, [eax]
004803e0  51                       push      ecx
004803e1  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
004803e7  8d11                     lea       edx, [ecx]
004803e9  52                       push      edx
004803ea  e8f1c4fcff               call      0x44c8e0 ; _inline_
004803ef  83c410                   add       esp, 0x10
004803f2  68e89d5a00               push      0x5a9de8
004803f7  e854170200               call      0x4a1b50 ; _jwe_iinf
004803fc  83c404                   add       esp, 4
004803ff  85c0                     test      eax, eax
00480401  0f85f52c0000             jne       0x4830fc
00480407  68dc9d5a00               push      0x5a9ddc
0048040c  e83f170200               call      0x4a1b50 ; _jwe_iinf
00480411  83c404                   add       esp, 4
00480414  85c0                     test      eax, eax
00480416  0f85e02c0000             jne       0x4830fc
0048041c  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480422  8b08                     mov       ecx, dword ptr [eax]
00480424  8b15d0a45a00             mov       edx, dword ptr [0x5aa4d0] ; bits=00000000, f32=0.0
0048042a  8d1db09d5a00             lea       ebx, [0x5a9db0] ; bits=09020000, f32=7.300764999132297e-43
00480430  894dfc                   mov       dword ptr [ebp - 4], ecx
00480433  8d4dfc                   lea       ecx, [ebp - 4]
00480436  894b08                   mov       dword ptr [ebx + 8], ecx
00480439  8955f8                   mov       dword ptr [ebp - 8], edx
0048043c  8d4df8                   lea       ecx, [ebp - 8]
0048043f  894b28                   mov       dword ptr [ebx + 0x28], ecx
00480442  53                       push      ebx
00480443  e8a8210200               call      0x4a25f0 ; _jwe_isfm
00480448  83c404                   add       esp, 4
0048044b  6a50                     push      0x50
0048044d  68f0a55a00               push      0x5aa5f0
00480452  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480458  8d08                     lea       ecx, [eax]
0048045a  51                       push      ecx
0048045b  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
00480461  8d11                     lea       edx, [ecx]
00480463  52                       push      edx
00480464  e877c4fcff               call      0x44c8e0 ; _inline_
00480469  83c410                   add       esp, 0x10
0048046c  68909d5a00               push      0x5a9d90
00480471  e8da160200               call      0x4a1b50 ; _jwe_iinf
00480476  83c404                   add       esp, 4
00480479  85c0                     test      eax, eax
0048047b  0f857b2c0000             jne       0x4830fc
00480481  68849d5a00               push      0x5a9d84
00480486  e8c5160200               call      0x4a1b50 ; _jwe_iinf
0048048b  83c404                   add       esp, 4
0048048e  85c0                     test      eax, eax
00480490  0f85662c0000             jne       0x4830fc
00480496  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0048049c  8b08                     mov       ecx, dword ptr [eax]
0048049e  8b1580a45a00             mov       edx, dword ptr [0x5aa480] ; bits=00000000, f32=0.0
004804a4  8d1d589d5a00             lea       ebx, [0x5a9d58] ; bits=09020000, f32=7.300764999132297e-43
004804aa  894dfc                   mov       dword ptr [ebp - 4], ecx
004804ad  8d4dfc                   lea       ecx, [ebp - 4]
004804b0  894b08                   mov       dword ptr [ebx + 8], ecx
004804b3  8955f8                   mov       dword ptr [ebp - 8], edx
004804b6  8d4df8                   lea       ecx, [ebp - 8]
004804b9  894b28                   mov       dword ptr [ebx + 0x28], ecx
004804bc  53                       push      ebx
004804bd  e82e210200               call      0x4a25f0 ; _jwe_isfm
004804c2  83c404                   add       esp, 4
004804c5  6a50                     push      0x50
004804c7  68f0a55a00               push      0x5aa5f0
004804cc  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
004804d2  8d08                     lea       ecx, [eax]
004804d4  51                       push      ecx
004804d5  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
004804db  8d11                     lea       edx, [ecx]
004804dd  52                       push      edx
004804de  e8fdc3fcff               call      0x44c8e0 ; _inline_
004804e3  83c410                   add       esp, 0x10
004804e6  68389d5a00               push      0x5a9d38
004804eb  e860160200               call      0x4a1b50 ; _jwe_iinf
004804f0  83c404                   add       esp, 4
004804f3  85c0                     test      eax, eax
004804f5  0f85012c0000             jne       0x4830fc
004804fb  682c9d5a00               push      0x5a9d2c
00480500  e84b160200               call      0x4a1b50 ; _jwe_iinf
00480505  83c404                   add       esp, 4
00480508  85c0                     test      eax, eax
0048050a  0f85ec2b0000             jne       0x4830fc
00480510  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480516  8b08                     mov       ecx, dword ptr [eax]
00480518  8b15c0a45a00             mov       edx, dword ptr [0x5aa4c0] ; bits=00000000, f32=0.0
0048051e  8d1d009d5a00             lea       ebx, [0x5a9d00] ; bits=09020000, f32=7.300764999132297e-43
00480524  894dfc                   mov       dword ptr [ebp - 4], ecx
00480527  8d4dfc                   lea       ecx, [ebp - 4]
0048052a  894b08                   mov       dword ptr [ebx + 8], ecx
0048052d  8955f8                   mov       dword ptr [ebp - 8], edx
00480530  8d4df8                   lea       ecx, [ebp - 8]
00480533  894b28                   mov       dword ptr [ebx + 0x28], ecx
00480536  53                       push      ebx
00480537  e8b4200200               call      0x4a25f0 ; _jwe_isfm
0048053c  83c404                   add       esp, 4
0048053f  6a50                     push      0x50
00480541  68f0a55a00               push      0x5aa5f0
00480546  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0048054c  8d08                     lea       ecx, [eax]
0048054e  51                       push      ecx
0048054f  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
00480555  8d11                     lea       edx, [ecx]
00480557  52                       push      edx
00480558  e883c3fcff               call      0x44c8e0 ; _inline_
0048055d  83c410                   add       esp, 0x10
00480560  68e09c5a00               push      0x5a9ce0
00480565  e8e6150200               call      0x4a1b50 ; _jwe_iinf
0048056a  83c404                   add       esp, 4
0048056d  85c0                     test      eax, eax
0048056f  0f85872b0000             jne       0x4830fc
00480575  68d49c5a00               push      0x5a9cd4
0048057a  e8d1150200               call      0x4a1b50 ; _jwe_iinf
0048057f  83c404                   add       esp, 4
00480582  85c0                     test      eax, eax
00480584  0f85722b0000             jne       0x4830fc
0048058a  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480590  8b08                     mov       ecx, dword ptr [eax]
00480592  8b1590a45a00             mov       edx, dword ptr [0x5aa490] ; bits=00000000, f32=0.0
00480598  8d1da89c5a00             lea       ebx, [0x5a9ca8] ; bits=09020000, f32=7.300764999132297e-43
0048059e  894dfc                   mov       dword ptr [ebp - 4], ecx
004805a1  8d4dfc                   lea       ecx, [ebp - 4]
004805a4  894b08                   mov       dword ptr [ebx + 8], ecx
004805a7  8955f8                   mov       dword ptr [ebp - 8], edx
004805aa  8d4df8                   lea       ecx, [ebp - 8]
004805ad  894b28                   mov       dword ptr [ebx + 0x28], ecx
004805b0  53                       push      ebx
004805b1  e83a200200               call      0x4a25f0 ; _jwe_isfm
004805b6  83c404                   add       esp, 4
004805b9  8d0560905a00             lea       eax, [0x5a9060] ; bits=16000000, f32=3.0828566215145976e-44
004805bf  8b4898                   mov       ecx, dword ptr [eax - 0x68]
004805c2  890dd8a45a00             mov       dword ptr [0x5aa4d8], ecx ; bits=00000000, f32=0.0
004805c8  c705d4a45a0000000000     mov       dword ptr [0x5aa4d4], 0 ; bits=00000000, f32=0.0
004805d2  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
004805d5  8d09                     lea       ecx, [ecx]
004805d7  51                       push      ecx
004805d8  6800409800               push      0x984000
004805dd  6860a45a00               push      0x5aa460
004805e2  8d4074                   lea       eax, [eax + 0x74]
004805e5  50                       push      eax
004805e6  68c4a45a00               push      0x5aa4c4
004805eb  6880a45a00               push      0x5aa480
004805f0  68d0a45a00               push      0x5aa4d0
004805f5  68d4a45a00               push      0x5aa4d4
004805fa  68d8a45a00               push      0x5aa4d8
004805ff  686ca45a00               push      0x5aa46c
00480604  6870a45a00               push      0x5aa470
00480609  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0048060f  8d08                     lea       ecx, [eax]
00480611  51                       push      ecx
00480612  e8e9e8ffff               call      0x47ef00 ; _lstopf_
00480617  83c430                   add       esp, 0x30
0048061a  c705843a980000000000     mov       dword ptr [0x983a84], 0
00480624  8b1d60a45a00             mov       ebx, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
0048062a  83fb00                   cmp       ebx, 0
0048062d  7e5b                     jle       0x48068a
0048062f  b801000000               mov       eax, 1
00480634  83fb02                   cmp       ebx, 2
00480637  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
0048063d  7c33                     jl        0x480672
0048063f  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00480645  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
0048064c  890c85843a9800           mov       dword ptr [eax*4 + 0x983a84], ecx
00480653  8b0c8500409800           mov       ecx, dword ptr [eax*4 + 0x984000]
0048065a  890c85883a9800           mov       dword ptr [eax*4 + 0x983a88], ecx
00480661  83c002                   add       eax, 2
00480664  83eb02                   sub       ebx, 2
00480667  83fb02                   cmp       ebx, 2
0048066a  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
00480670  7dcd                     jge       0x48063f
00480672  85db                     test      ebx, ebx
00480674  7414                     je        0x48068a
00480676  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
0048067c  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
00480683  890c85843a9800           mov       dword ptr [eax*4 + 0x983a84], ecx
0048068a  8b0560a45a00             mov       eax, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
00480690  40                       inc       eax
00480691  89855cfeffff             mov       dword ptr [ebp - 0x1a4], eax
00480697  c705d4a45a0000000000     mov       dword ptr [0x5aa4d4], 0 ; bits=00000000, f32=0.0
004806a1  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004806a4  8d00                     lea       eax, [eax]
004806a6  50                       push      eax
004806a7  6800409800               push      0x984000
004806ac  6860a45a00               push      0x5aa460
004806b1  68d4905a00               push      0x5a90d4
004806b6  68c4a45a00               push      0x5aa4c4
004806bb  68c0a45a00               push      0x5aa4c0
004806c0  6880a45a00               push      0x5aa480
004806c5  68d4a45a00               push      0x5aa4d4
004806ca  6890a45a00               push      0x5aa490
004806cf  686ca45a00               push      0x5aa46c
004806d4  6870a45a00               push      0x5aa470
004806d9  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
004806df  8d08                     lea       ecx, [eax]
004806e1  51                       push      ecx
004806e2  e819e8ffff               call      0x47ef00 ; _lstopf_
004806e7  83c430                   add       esp, 0x30
004806ea  8b0560a45a00             mov       eax, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
004806f0  83c0ff                   add       eax, -1
004806f3  3d00000000               cmp       eax, 0
004806f8  898558feffff             mov       dword ptr [ebp - 0x1a8], eax
004806fe  7e7d                     jle       0x48077d
00480700  b802000000               mov       eax, 2
00480705  8b8d5cfeffff             mov       ecx, dword ptr [ebp - 0x1a4]
0048070b  8d5902                   lea       ebx, [ecx + 2]
0048070e  83bd58feffff02           cmp       dword ptr [ebp - 0x1a8], 2
00480715  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
0048071b  7c42                     jl        0x48075f
0048071d  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00480723  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
0048072a  890c9d7c3a9800           mov       dword ptr [ebx*4 + 0x983a7c], ecx
00480731  8b0c8500409800           mov       ecx, dword ptr [eax*4 + 0x984000]
00480738  890c9d803a9800           mov       dword ptr [ebx*4 + 0x983a80], ecx
0048073f  83c302                   add       ebx, 2
00480742  8b8d58feffff             mov       ecx, dword ptr [ebp - 0x1a8]
00480748  83e902                   sub       ecx, 2
0048074b  83c002                   add       eax, 2
0048074e  83f902                   cmp       ecx, 2
00480751  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
00480757  898d58feffff             mov       dword ptr [ebp - 0x1a8], ecx
0048075d  7dbe                     jge       0x48071d
0048075f  8b8558feffff             mov       eax, dword ptr [ebp - 0x1a8]
00480765  85c0                     test      eax, eax
00480767  7414                     je        0x48077d
00480769  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
0048076f  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
00480776  890c9d7c3a9800           mov       dword ptr [ebx*4 + 0x983a7c], ecx
0048077d  8b855cfeffff             mov       eax, dword ptr [ebp - 0x1a4]
00480783  030560a45a00             add       eax, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
00480789  48                       dec       eax
0048078a  c70485843a98000000803f   mov       dword ptr [eax*4 + 0x983a84], 0x3f800000
00480795  40                       inc       eax
00480796  8b0d843a9800             mov       ecx, dword ptr [0x983a84]
0048079c  890de4f89400             mov       dword ptr [0x94f8e4], ecx
004807a2  8b0d883a9800             mov       ecx, dword ptr [0x983a88]
004807a8  890de8f89400             mov       dword ptr [0x94f8e8], ecx
004807ae  bb02000000               mov       ebx, 2
004807b3  89855cfeffff             mov       dword ptr [ebp - 0x1a4], eax
004807b9  8b855cfeffff             mov       eax, dword ptr [ebp - 0x1a4]
004807bf  8d48fd                   lea       ecx, [eax - 3]
004807c2  83f900                   cmp       ecx, 0
004807c5  898d54feffff             mov       dword ptr [ebp - 0x1ac], ecx
004807cb  0f8ebe000000             jle       0x48088f
004807d1  b803000000               mov       eax, 3
004807d6  83bd54feffff02           cmp       dword ptr [ebp - 0x1ac], 2
004807dd  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
004807e3  7c6f                     jl        0x480854
004807e5  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
004807eb  d90485803a9800           fld       dword ptr [eax*4 + 0x983a80]
004807f2  d9c0                     fld       st(0)
004807f4  d804857c3a9800           fadd      dword ptr [eax*4 + 0x983a7c]
004807fb  43                       inc       ebx
004807fc  d80df88f5a00             fmul      dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
00480802  d91c9de0f89400           fstp      dword ptr [ebx*4 + 0x94f8e0]
00480809  43                       inc       ebx
0048080a  d9149de0f89400           fst       dword ptr [ebx*4 + 0x94f8e0]
00480811  d90485843a9800           fld       dword ptr [eax*4 + 0x983a84]
00480818  d9c9                     fxch      st(1)
0048081a  d80485843a9800           fadd      dword ptr [eax*4 + 0x983a84]
00480821  43                       inc       ebx
00480822  d80df88f5a00             fmul      dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
00480828  d91c9de0f89400           fstp      dword ptr [ebx*4 + 0x94f8e0]
0048082f  43                       inc       ebx
00480830  d91c9de0f89400           fstp      dword ptr [ebx*4 + 0x94f8e0]
00480837  83c002                   add       eax, 2
0048083a  8b8d54feffff             mov       ecx, dword ptr [ebp - 0x1ac]
00480840  83e902                   sub       ecx, 2
00480843  83f902                   cmp       ecx, 2
00480846  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
0048084c  898d54feffff             mov       dword ptr [ebp - 0x1ac], ecx
00480852  7d91                     jge       0x4807e5
00480854  8b8554feffff             mov       eax, dword ptr [ebp - 0x1ac]
0048085a  85c0                     test      eax, eax
0048085c  7431                     je        0x48088f
0048085e  43                       inc       ebx
0048085f  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00480865  d904857c3a9800           fld       dword ptr [eax*4 + 0x983a7c]
0048086c  d80485803a9800           fadd      dword ptr [eax*4 + 0x983a80]
00480873  d80df88f5a00             fmul      dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
00480879  d91c9de0f89400           fstp      dword ptr [ebx*4 + 0x94f8e0]
00480880  43                       inc       ebx
00480881  8b0c85803a9800           mov       ecx, dword ptr [eax*4 + 0x983a80]
00480888  890c9de0f89400           mov       dword ptr [ebx*4 + 0x94f8e0], ecx
0048088f  8b855cfeffff             mov       eax, dword ptr [ebp - 0x1a4]
00480895  8b0c85803a9800           mov       ecx, dword ptr [eax*4 + 0x983a80]
0048089c  890c9de4f89400           mov       dword ptr [ebx*4 + 0x94f8e4], ecx
004808a3  89d8                     mov       eax, ebx
004808a5  40                       inc       eax
004808a6  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
004808a9  833900                   cmp       dword ptr [ecx], 0
004808ac  89855cfeffff             mov       dword ptr [ebp - 0x1a4], eax
004808b2  0f8589280000             jne       0x483141
004808b8  8b05b477b400             mov       eax, dword ptr [0xb477b4]
004808be  8905b0a45a00             mov       dword ptr [0x5aa4b0], eax ; bits=00000000, f32=0.0
004808c4  d905b477b400             fld       dword ptr [0xb477b4]
004808ca  d82db877b400             fsubr     dword ptr [0xb477b8]
004808d0  d91d1c78b400             fstp      dword ptr [0xb4781c]
004808d6  d9ee                     fldz
004808d8  d9c0                     fld       st(0)
004808da  db7d98                   fstp      xword ptr [ebp - 0x68]
004808dd  b800000000               mov       eax, 0
004808e2  d9c0                     fld       st(0)
004808e4  db7da4                   fstp      xword ptr [ebp - 0x5c]
004808e7  db7d8c                   fstp      xword ptr [ebp - 0x74]
004808ea  898550feffff             mov       dword ptr [ebp - 0x1b0], eax
004808f0  8b856cfeffff             mov       eax, dword ptr [ebp - 0x194]
004808f6  89854cfeffff             mov       dword ptr [ebp - 0x1b4], eax
004808fc  3d00000000               cmp       eax, 0
00480901  0f8e70250000             jle       0x482e77
00480907  b801000000               mov       eax, 1
0048090c  8b8d5cfeffff             mov       ecx, dword ptr [ebp - 0x1a4]
00480912  8d14c9                   lea       edx, [ecx + ecx*8]
00480915  8d1451                   lea       edx, [ecx + edx*2]
00480918  c1e203                   shl       edx, 3
0048091b  29ca                     sub       edx, ecx
0048091d  899548feffff             mov       dword ptr [ebp - 0x1b8], edx
00480923  8d51ff                   lea       edx, [ecx - 1]
00480926  8d5aff                   lea       ebx, [edx - 1]
00480929  8d34d2                   lea       esi, [edx + edx*8]
0048092c  8d3472                   lea       esi, [edx + esi*2]
0048092f  c1e603                   shl       esi, 3
00480932  29d6                     sub       esi, edx
00480934  8d79fd                   lea       edi, [ecx - 3]
00480937  898544feffff             mov       dword ptr [ebp - 0x1bc], eax
0048093d  89f8                     mov       eax, edi
0048093f  c1f81f                   sar       eax, 0x1f
00480942  29c7                     sub       edi, eax
00480944  d1ff                     sar       edi, 1
00480946  899540feffff             mov       dword ptr [ebp - 0x1c0], edx
0048094c  89b53cfeffff             mov       dword ptr [ebp - 0x1c4], esi
00480952  89f8                     mov       eax, edi
00480954  899d38feffff             mov       dword ptr [ebp - 0x1c8], ebx
0048095a  8b1de4f89400             mov       ebx, dword ptr [0x94f8e4]
00480960  8b0de8f89400             mov       ecx, dword ptr [0x94f8e8]
00480966  899534feffff             mov       dword ptr [ebp - 0x1cc], edx
0048096c  89c2                     mov       edx, eax
0048096e  89b530feffff             mov       dword ptr [ebp - 0x1d0], esi
00480974  8bb55cfeffff             mov       esi, dword ptr [ebp - 0x1a4]
0048097a  89bd2cfeffff             mov       dword ptr [ebp - 0x1d4], edi
00480980  8b3cb5e0f89400           mov       edi, dword ptr [esi*4 + 0x94f8e0]
00480987  899528feffff             mov       dword ptr [ebp - 0x1d8], edx
0048098d  899524feffff             mov       dword ptr [ebp - 0x1dc], edx
00480993  898520feffff             mov       dword ptr [ebp - 0x1e0], eax
00480999  898d1cfeffff             mov       dword ptr [ebp - 0x1e4], ecx
0048099f  899518feffff             mov       dword ptr [ebp - 0x1e8], edx
004809a5  899d14feffff             mov       dword ptr [ebp - 0x1ec], ebx
004809ab  89bd10feffff             mov       dword ptr [ebp - 0x1f0], edi
004809b1  b800000000               mov       eax, 0
004809b6  8b8d44feffff             mov       ecx, dword ptr [ebp - 0x1bc]
004809bc  89850cfeffff             mov       dword ptr [ebp - 0x1f4], eax
004809c2  8b148d6ca95a00           mov       edx, dword ptr [ecx*4 + 0x5aa96c]
004809c9  8915f477b400             mov       dword ptr [0xb477f4], edx
004809cf  8d1d7c9c5a00             lea       ebx, [0x5a9c7c] ; bits=09020000, f32=7.300764999132297e-43
004809d5  8955f8                   mov       dword ptr [ebp - 8], edx
004809d8  8d55f8                   lea       edx, [ebp - 8]
004809db  895328                   mov       dword ptr [ebx + 0x28], edx
004809de  53                       push      ebx
004809df  e86c110200               call      0x4a1b50 ; _jwe_iinf
004809e4  83c404                   add       esp, 4
004809e7  8d05b8a55a00             lea       eax, [0x5aa5b8] ; bits=00000000, f32=0.0
004809ed  8d0d70a55a00             lea       ecx, [0x5aa570] ; bits=00000000, f32=0.0
004809f3  8a11                     mov       dl, byte ptr [ecx]
004809f5  8810                     mov       byte ptr [eax], dl
004809f7  8a5101                   mov       dl, byte ptr [ecx + 1]
004809fa  885001                   mov       byte ptr [eax + 1], dl
004809fd  8a5102                   mov       dl, byte ptr [ecx + 2]
00480a00  885002                   mov       byte ptr [eax + 2], dl
00480a03  8a5103                   mov       dl, byte ptr [ecx + 3]
00480a06  885003                   mov       byte ptr [eax + 3], dl
00480a09  8a5104                   mov       dl, byte ptr [ecx + 4]
00480a0c  885004                   mov       byte ptr [eax + 4], dl
00480a0f  8a5105                   mov       dl, byte ptr [ecx + 5]
00480a12  885005                   mov       byte ptr [eax + 5], dl
00480a15  8a5106                   mov       dl, byte ptr [ecx + 6]
00480a18  885006                   mov       byte ptr [eax + 6], dl
00480a1b  8a5107                   mov       dl, byte ptr [ecx + 7]
00480a1e  885007                   mov       byte ptr [eax + 7], dl
00480a21  8a5108                   mov       dl, byte ptr [ecx + 8]
00480a24  885008                   mov       byte ptr [eax + 8], dl
00480a27  8a5109                   mov       dl, byte ptr [ecx + 9]
00480a2a  885009                   mov       byte ptr [eax + 9], dl
00480a2d  6a32                     push      0x32
00480a2f  6a28                     push      0x28
00480a31  6880a55a00               push      0x5aa580
00480a36  68c2a55a00               push      0x5aa5c2
00480a3b  e870e80100               call      0x49f2b0 ; _f_scmov
00480a40  83c410                   add       esp, 0x10
00480a43  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00480a49  8b0c858cac5a00           mov       ecx, dword ptr [eax*4 + 0x5aac8c]
00480a50  890dcca45a00             mov       dword ptr [0x5aa4cc], ecx ; bits=00000000, f32=0.0
00480a56  8b0c85ecab5a00           mov       ecx, dword ptr [eax*4 + 0x5aabec]
00480a5d  890de0a45a00             mov       dword ptr [0x5aa4e0], ecx ; bits=00000000, f32=0.0
00480a63  8b0c85cca85a00           mov       ecx, dword ptr [eax*4 + 0x5aa8cc]
00480a6a  890d84a45a00             mov       dword ptr [0x5aa484], ecx ; bits=00000000, f32=0.0
00480a70  8d0c856ca75a00           lea       ecx, [eax*4 + 0x5aa76c]
00480a77  51                       push      ecx
00480a78  6a10                     push      0x10
00480a7a  6810a75a00               push      0x5aa710
00480a7f  e80c69ffff               call      0x477390 ; _get_tabid_
00480a84  83c40c                   add       esp, 0xc
00480a87  8d05c8a65a00             lea       eax, [0x5aa6c8] ; bits=00000000, f32=0.0
00480a8d  8d0d10a75a00             lea       ecx, [0x5aa710] ; bits=00000000, f32=0.0
00480a93  8a11                     mov       dl, byte ptr [ecx]
00480a95  8810                     mov       byte ptr [eax], dl
00480a97  8a5101                   mov       dl, byte ptr [ecx + 1]
00480a9a  885001                   mov       byte ptr [eax + 1], dl
00480a9d  8a5102                   mov       dl, byte ptr [ecx + 2]
00480aa0  885002                   mov       byte ptr [eax + 2], dl
00480aa3  8a5103                   mov       dl, byte ptr [ecx + 3]
00480aa6  885003                   mov       byte ptr [eax + 3], dl
00480aa9  8a5104                   mov       dl, byte ptr [ecx + 4]
00480aac  885004                   mov       byte ptr [eax + 4], dl
00480aaf  8a5105                   mov       dl, byte ptr [ecx + 5]
00480ab2  885005                   mov       byte ptr [eax + 5], dl
00480ab5  8a5106                   mov       dl, byte ptr [ecx + 6]
00480ab8  885006                   mov       byte ptr [eax + 6], dl
00480abb  8a5107                   mov       dl, byte ptr [ecx + 7]
00480abe  885007                   mov       byte ptr [eax + 7], dl
00480ac1  8a5108                   mov       dl, byte ptr [ecx + 8]
00480ac4  885008                   mov       byte ptr [eax + 8], dl
00480ac7  8a5109                   mov       dl, byte ptr [ecx + 9]
00480aca  885009                   mov       byte ptr [eax + 9], dl
00480acd  8a510a                   mov       dl, byte ptr [ecx + 0xa]
00480ad0  88500a                   mov       byte ptr [eax + 0xa], dl
00480ad3  8a510b                   mov       dl, byte ptr [ecx + 0xb]
00480ad6  88500b                   mov       byte ptr [eax + 0xb], dl
00480ad9  8a510c                   mov       dl, byte ptr [ecx + 0xc]
00480adc  88500c                   mov       byte ptr [eax + 0xc], dl
00480adf  8a510d                   mov       dl, byte ptr [ecx + 0xd]
00480ae2  88500d                   mov       byte ptr [eax + 0xd], dl
00480ae5  8a510e                   mov       dl, byte ptr [ecx + 0xe]
00480ae8  88500e                   mov       byte ptr [eax + 0xe], dl
00480aeb  8a510f                   mov       dl, byte ptr [ecx + 0xf]
00480aee  88500f                   mov       byte ptr [eax + 0xf], dl
00480af1  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480af7  8b18                     mov       ebx, dword ptr [eax]
00480af9  8b0df477b400             mov       ecx, dword ptr [0xb477f4]
00480aff  898d08feffff             mov       dword ptr [ebp - 0x1f8], ecx
00480b05  6a10                     push      0x10
00480b07  68c8a65a00               push      0x5aa6c8
00480b0c  e83feffcff               call      0x44fa50 ; _lenstr_
00480b11  83c408                   add       esp, 8
00480b14  89c2                     mov       edx, eax
00480b16  c1fa1f                   sar       edx, 0x1f
00480b19  f7d2                     not       edx
00480b1b  21d0                     and       eax, edx
00480b1d  8d0d449c5a00             lea       ecx, [0x5a9c44] ; bits=09020000, f32=7.300764999132297e-43
00480b23  895dfc                   mov       dword ptr [ebp - 4], ebx
00480b26  8d55fc                   lea       edx, [ebp - 4]
00480b29  895108                   mov       dword ptr [ecx + 8], edx
00480b2c  8b9508feffff             mov       edx, dword ptr [ebp - 0x1f8]
00480b32  8955f8                   mov       dword ptr [ebp - 8], edx
00480b35  8d55f8                   lea       edx, [ebp - 8]
00480b38  895128                   mov       dword ptr [ecx + 0x28], edx
00480b3b  894130                   mov       dword ptr [ecx + 0x30], eax
00480b3e  51                       push      ecx
00480b3f  e8ac1a0200               call      0x4a25f0 ; _jwe_isfm
00480b44  83c404                   add       esp, 4
00480b47  d905f477b400             fld       dword ptr [0xb477f4]
00480b4d  d9c0                     fld       st(0)
00480b4f  d80dfc77b400             fmul      dword ptr [0xb477fc]
00480b55  d91df877b400             fstp      dword ptr [0xb477f8]
00480b5b  8b05f477b400             mov       eax, dword ptr [0xb477f4]
00480b61  89058c77b400             mov       dword ptr [0xb4778c], eax
00480b67  d9c0                     fld       st(0)
00480b69  d80d0878b400             fmul      dword ptr [0xb47808]
00480b6f  d9fa                     fsqrt
00480b71  d95df8                   fstp      dword ptr [ebp - 8]
00480b74  d905f877b400             fld       dword ptr [0xb477f8]
00480b7a  d9c0                     fld       st(0)
00480b7c  d84df8                   fmul      dword ptr [ebp - 8]
00480b7f  d91de4a45a00             fstp      dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00480b85  d9c9                     fxch      st(1)
00480b87  d805b477b400             fadd      dword ptr [0xb477b4]
00480b8d  d9c9                     fxch      st(1)
00480b8f  d80d0078b400             fmul      dword ptr [0xb47800]
00480b95  d83de4a45a00             fdivr     dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00480b9b  d8c8                     fmul      st(0)
00480b9d  d8350c78b400             fdiv      dword ptr [0xb4780c]
00480ba3  d8c1                     fadd      st(1)
00480ba5  d825b077b400             fsub      dword ptr [0xb477b0]
00480bab  d91df8a45a00             fstp      dword ptr [0x5aa4f8] ; bits=00000000, f32=0.0
00480bb1  d825b077b400             fsub      dword ptr [0xb477b0]
00480bb7  d91d00a55a00             fstp      dword ptr [0x5aa500] ; bits=00000000, f32=0.0
00480bbd  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00480bc0  898504feffff             mov       dword ptr [ebp - 0x1fc], eax
00480bc6  8d08                     lea       ecx, [eax]
00480bc8  51                       push      ecx
00480bc9  6800a55a00               push      0x5aa500
00480bce  68f8a45a00               push      0x5aa4f8
00480bd3  68e4a45a00               push      0x5aa4e4
00480bd8  6860905a00               push      0x5a9060
00480bdd  688077b400               push      0xb47780 ; _ufcom_
00480be2  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
00480be8  8d11                     lea       edx, [ecx]
00480bea  52                       push      edx
00480beb  680878b400               push      0xb47808
00480bf0  e8db05f9ff               call      0x4111d0 ; _invtse_
00480bf5  83c420                   add       esp, 0x20
00480bf8  d905b077b400             fld       dword ptr [0xb477b0]
00480bfe  d80500a55a00             fadd      dword ptr [0x5aa500] ; bits=00000000, f32=0.0
00480c04  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
00480c0a  d91d9ca45a00             fstp      dword ptr [0x5aa49c] ; bits=00000000, f32=0.0
00480c10  d905f477b400             fld       dword ptr [0xb477f4]
00480c16  d9c0                     fld       st(0)
00480c18  d83d9ca45a00             fdivr     dword ptr [0x5aa49c] ; bits=00000000, f32=0.0
00480c1e  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00480c24  d91c850caa5a00           fstp      dword ptr [eax*4 + 0x5aaa0c]
00480c2b  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
00480c31  d8359ca45a00             fdiv      dword ptr [0x5aa49c] ; bits=00000000, f32=0.0
00480c37  8b11                     mov       edx, dword ptr [ecx]
00480c39  8b1d9ca45a00             mov       ebx, dword ptr [0x5aa49c] ; bits=00000000, f32=0.0
00480c3f  8d350c9c5a00             lea       esi, [0x5a9c0c] ; bits=09020000, f32=7.300764999132297e-43
00480c45  8955fc                   mov       dword ptr [ebp - 4], edx
00480c48  8d55fc                   lea       edx, [ebp - 4]
00480c4b  895608                   mov       dword ptr [esi + 8], edx
00480c4e  895df8                   mov       dword ptr [ebp - 8], ebx
00480c51  8d55f8                   lea       edx, [ebp - 8]
00480c54  895628                   mov       dword ptr [esi + 0x28], edx
00480c57  d95df4                   fstp      dword ptr [ebp - 0xc]
00480c5a  8d55f4                   lea       edx, [ebp - 0xc]
00480c5d  895634                   mov       dword ptr [esi + 0x34], edx
00480c60  56                       push      esi
00480c61  e88a190200               call      0x4a25f0 ; _jwe_isfm
00480c66  83c404                   add       esp, 4
00480c69  d9e8                     fld1
00480c6b  d91d0478b400             fstp      dword ptr [0xb47804]
00480c71  68e8a45a00               push      0x5aa4e8
00480c76  68b0a45a00               push      0x5aa4b0
00480c7b  689ca45a00               push      0x5aa49c
00480c80  e89be1ffff               call      0x47ee20 ; _fndfoq_
00480c85  83c40c                   add       esp, 0xc
00480c88  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480c8e  8b18                     mov       ebx, dword ptr [eax]
00480c90  8b0de4a45a00             mov       ecx, dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00480c96  8d15d49b5a00             lea       edx, [0x5a9bd4] ; bits=09820000, f32=4.664782457890884e-41
00480c9c  895dfc                   mov       dword ptr [ebp - 4], ebx
00480c9f  8d75fc                   lea       esi, [ebp - 4]
00480ca2  897208                   mov       dword ptr [edx + 8], esi
00480ca5  894df8                   mov       dword ptr [ebp - 8], ecx
00480ca8  8d4df8                   lea       ecx, [ebp - 8]
00480cab  894a34                   mov       dword ptr [edx + 0x34], ecx
00480cae  52                       push      edx
00480caf  e8cc210200               call      0x4a2e80 ; _jwe_ilst
00480cb4  83c404                   add       esp, 4
00480cb7  8b05e8a45a00             mov       eax, dword ptr [0x5aa4e8] ; bits=00000000, f32=0.0
00480cbd  8d0d9c9b5a00             lea       ecx, [0x5a9b9c] ; bits=09820000, f32=4.664782457890884e-41
00480cc3  895dfc                   mov       dword ptr [ebp - 4], ebx
00480cc6  8d55fc                   lea       edx, [ebp - 4]
00480cc9  895108                   mov       dword ptr [ecx + 8], edx
00480ccc  8945f8                   mov       dword ptr [ebp - 8], eax
00480ccf  8d45f8                   lea       eax, [ebp - 8]
00480cd2  894134                   mov       dword ptr [ecx + 0x34], eax
00480cd5  51                       push      ecx
00480cd6  e8a5210200               call      0x4a2e80 ; _jwe_ilst
00480cdb  83c404                   add       esp, 4
00480cde  6850a45a00               push      0x5aa450
00480ce3  68a8a45a00               push      0x5aa4a8
00480ce8  68b0a45a00               push      0x5aa4b0
00480ced  68e8a45a00               push      0x5aa4e8
00480cf2  689ca45a00               push      0x5aa49c
00480cf7  e844e0ffff               call      0x47ed40 ; _fotoso_
00480cfc  83c414                   add       esp, 0x14
00480cff  d905f477b400             fld       dword ptr [0xb477f4]
00480d05  d83da8a45a00             fdivr     dword ptr [0x5aa4a8] ; bits=00000000, f32=0.0
00480d0b  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00480d11  d91c85acaa5a00           fstp      dword ptr [eax*4 + 0x5aaaac]
00480d18  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00480d1f  743b                     je        0x480d5c
00480d21  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480d27  8b08                     mov       ecx, dword ptr [eax]
00480d29  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00480d2f  8d1d649b5a00             lea       ebx, [0x5a9b64] ; bits=09020000, f32=7.300764999132297e-43
00480d35  894dfc                   mov       dword ptr [ebp - 4], ecx
00480d38  8d4dfc                   lea       ecx, [ebp - 4]
00480d3b  894b08                   mov       dword ptr [ebx + 8], ecx
00480d3e  8955ec                   mov       dword ptr [ebp - 0x14], edx
00480d41  8d4dec                   lea       ecx, [ebp - 0x14]
00480d44  894b28                   mov       dword ptr [ebx + 0x28], ecx
00480d47  53                       push      ebx
00480d48  e8a3180200               call      0x4a25f0 ; _jwe_isfm
00480d4d  83c404                   add       esp, 4
00480d50  8b8504feffff             mov       eax, dword ptr [ebp - 0x1fc]
00480d56  c70001000000             mov       dword ptr [eax], 1
00480d5c  d905f477b400             fld       dword ptr [0xb477f4]
00480d62  d9c0                     fld       st(0)
00480d64  d80d94a45a00             fmul      dword ptr [0x5aa494] ; bits=00000000, f32=0.0
00480d6a  d8059ca45a00             fadd      dword ptr [0x5aa49c] ; bits=00000000, f32=0.0
00480d70  d91d98a45a00             fstp      dword ptr [0x5aa498] ; bits=00000000, f32=0.0
00480d76  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00480d7c  d904852ca85a00           fld       dword ptr [eax*4 + 0x5aa82c]
00480d83  d9ee                     fldz
00480d85  d9c9                     fxch      st(1)
00480d87  dae9                     fucompp
00480d89  db7d80                   fstp      xword ptr [ebp - 0x80]
00480d8c  dfe0                     fnstsw    ax
00480d8e  9e                       sahf
00480d8f  0f8a2c000000             jp        0x480dc1
00480d95  752a                     jne       0x480dc1
00480d97  db6d80                   fld       xword ptr [ebp - 0x80]
00480d9a  d83598a45a00             fdiv      dword ptr [0x5aa498] ; bits=00000000, f32=0.0
00480da0  d95df8                   fstp      dword ptr [ebp - 8]
00480da3  6848a45a00               push      0x5aa448
00480da8  6884a45a00               push      0x5aa484
00480dad  8d45f8                   lea       eax, [ebp - 8]
00480db0  50                       push      eax
00480db1  e83adfffff               call      0x47ecf0 ; _findcc_
00480db6  dbbd74ffffff             fstp      xword ptr [ebp - 0x8c]
00480dbc  83c40c                   add       esp, 0xc
00480dbf  eb26                     jmp       0x480de7
00480dc1  6848a45a00               push      0x5aa448
00480dc6  6884a45a00               push      0x5aa484
00480dcb  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00480dd1  8d0c852ca85a00           lea       ecx, [eax*4 + 0x5aa82c]
00480dd8  51                       push      ecx
00480dd9  e812dfffff               call      0x47ecf0 ; _findcc_
00480dde  dbbd74ffffff             fstp      xword ptr [ebp - 0x8c]
00480de4  83c40c                   add       esp, 0xc
00480de7  dbad74ffffff             fld       xword ptr [ebp - 0x8c]
00480ded  d91d0478b400             fstp      dword ptr [0xb47804]
00480df3  68eca45a00               push      0x5aa4ec
00480df8  68b0a45a00               push      0x5aa4b0
00480dfd  6898a45a00               push      0x5aa498
00480e02  e819e0ffff               call      0x47ee20 ; _fndfoq_
00480e07  83c40c                   add       esp, 0xc
00480e0a  6850a45a00               push      0x5aa450
00480e0f  68a4a45a00               push      0x5aa4a4
00480e14  68b0a45a00               push      0x5aa4b0
00480e19  68eca45a00               push      0x5aa4ec
00480e1e  6898a45a00               push      0x5aa498
00480e23  e818dfffff               call      0x47ed40 ; _fotoso_
00480e28  83c414                   add       esp, 0x14
00480e2b  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00480e32  7438                     je        0x480e6c
00480e34  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480e3a  8b08                     mov       ecx, dword ptr [eax]
00480e3c  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00480e42  8d1d2c9b5a00             lea       ebx, [0x5a9b2c] ; bits=09020000, f32=7.300764999132297e-43
00480e48  894dfc                   mov       dword ptr [ebp - 4], ecx
00480e4b  8d4dfc                   lea       ecx, [ebp - 4]
00480e4e  894b08                   mov       dword ptr [ebx + 8], ecx
00480e51  8955ec                   mov       dword ptr [ebp - 0x14], edx
00480e54  8d4dec                   lea       ecx, [ebp - 0x14]
00480e57  894b28                   mov       dword ptr [ebx + 0x28], ecx
00480e5a  53                       push      ebx
00480e5b  e890170200               call      0x4a25f0 ; _jwe_isfm
00480e60  83c404                   add       esp, 4
00480e63  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00480e66  c70001000000             mov       dword ptr [eax], 1
00480e6c  d905f477b400             fld       dword ptr [0xb477f4]
00480e72  d8059ca45a00             fadd      dword ptr [0x5aa49c] ; bits=00000000, f32=0.0
00480e78  d80df88f5a00             fmul      dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
00480e7e  d805b0a45a00             fadd      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
00480e84  dbbd68ffffff             fstp      xword ptr [ebp - 0x98]
00480e8a  dbad68ffffff             fld       xword ptr [ebp - 0x98]
00480e90  d825b077b400             fsub      dword ptr [0xb477b0]
00480e96  d91d24a55a00             fstp      dword ptr [0x5aa524] ; bits=00000000, f32=0.0
00480e9c  68e477b400               push      0xb477e4
00480ea1  681078b400               push      0xb47810
00480ea6  68ec77b400               push      0xb477ec
00480eab  681478b400               push      0xb47814
00480eb0  68dc77b400               push      0xb477dc
00480eb5  68d877b400               push      0xb477d8
00480eba  68d477b400               push      0xb477d4
00480ebf  68d077b400               push      0xb477d0
00480ec4  688ca45a00               push      0x5aa48c
00480ec9  68c477b400               push      0xb477c4
00480ece  689c77b400               push      0xb4779c
00480ed3  6824a55a00               push      0x5aa524
00480ed8  688077b400               push      0xb47780 ; _ufcom_
00480edd  e8ee82fcff               call      0x4491d0 ; _xlkt22_
00480ee2  83c434                   add       esp, 0x34
00480ee5  d905f877b400             fld       dword ptr [0xb477f8]
00480eeb  d80d0078b400             fmul      dword ptr [0xb47800]
00480ef1  d9c0                     fld       st(0)
00480ef3  d8c8                     fmul      st(0)
00480ef5  d80d0c78b400             fmul      dword ptr [0xb4780c]
00480efb  dbad68ffffff             fld       xword ptr [ebp - 0x98]
00480f01  d825f477b400             fsub      dword ptr [0xb477f4]
00480f07  d905b477b400             fld       dword ptr [0xb477b4]
00480f0d  d9c9                     fxch      st(1)
00480f0f  d825b477b400             fsub      dword ptr [0xb477b4]
00480f15  deca                     fmulp     st(2)
00480f17  d9ca                     fxch      st(2)
00480f19  d8359c77b400             fdiv      dword ptr [0xb4779c]
00480f1f  d8c8                     fmul      st(0)
00480f21  d80dec77b400             fmul      dword ptr [0xb477ec]
00480f27  d82dec8f5a00             fsubr     dword ptr [0x5a8fec] ; bits=0000803f, f32=1.0
00480f2d  def9                     fdivp     st(1)
00480f2f  d91d1878b400             fstp      dword ptr [0xb47818]
00480f35  d805f477b400             fadd      dword ptr [0xb477f4]
00480f3b  d825b877b400             fsub      dword ptr [0xb477b8]
00480f41  d91d9077b400             fstp      dword ptr [0xb47790]
00480f47  682078b400               push      0xb47820
00480f4c  689077b400               push      0xb47790
00480f51  688477b400               push      0xb47784
00480f56  e80573ffff               call      0x478260 ; _lktj_
00480f5b  83c40c                   add       esp, 0xc
00480f5e  d905b477b400             fld       dword ptr [0xb477b4]
00480f64  d805f477b400             fadd      dword ptr [0xb477f4]
00480f6a  d825bc77b400             fsub      dword ptr [0xb477bc]
00480f70  d91d14a55a00             fstp      dword ptr [0x5aa514] ; bits=00000000, f32=0.0
00480f76  dbad68ffffff             fld       xword ptr [ebp - 0x98]
00480f7c  d825bc77b400             fsub      dword ptr [0xb477bc]
00480f82  d91d18a55a00             fstp      dword ptr [0x5aa518] ; bits=00000000, f32=0.0
00480f88  6850a45a00               push      0x5aa450
00480f8d  6810a55a00               push      0x5aa510
00480f92  6818a55a00               push      0x5aa518
00480f97  6814a55a00               push      0x5aa514
00480f9c  6840ec4700               push      0x47ec40 ; _rswmy4_
00480fa1  6868f70e04               push      0x40ef768
00480fa6  686cf70e04               push      0x40ef76c
00480fab  e84013ffff               call      0x4722f0 ; _regfal_
00480fb0  83c41c                   add       esp, 0x1c
00480fb3  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00480fba  7438                     je        0x480ff4
00480fbc  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00480fc2  8b08                     mov       ecx, dword ptr [eax]
00480fc4  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00480fca  8d1df49a5a00             lea       ebx, [0x5a9af4] ; bits=09020000, f32=7.300764999132297e-43
00480fd0  894dfc                   mov       dword ptr [ebp - 4], ecx
00480fd3  8d4dfc                   lea       ecx, [ebp - 4]
00480fd6  894b08                   mov       dword ptr [ebx + 8], ecx
00480fd9  8955ec                   mov       dword ptr [ebp - 0x14], edx
00480fdc  8d4dec                   lea       ecx, [ebp - 0x14]
00480fdf  894b28                   mov       dword ptr [ebx + 0x28], ecx
00480fe2  53                       push      ebx
00480fe3  e808160200               call      0x4a25f0 ; _jwe_isfm
00480fe8  83c404                   add       esp, 4
00480feb  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00480fee  c70001000000             mov       dword ptr [eax], 1
00480ff4  d905bc77b400             fld       dword ptr [0xb477bc]
00480ffa  d80510a55a00             fadd      dword ptr [0x5aa510] ; bits=00000000, f32=0.0
00481000  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
00481006  d835f477b400             fdiv      dword ptr [0xb477f4]
0048100c  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00481012  d91c854cab5a00           fstp      dword ptr [eax*4 + 0x5aab4c]
00481019  8d0d60905a00             lea       ecx, [0x5a9060] ; bits=16000000, f32=3.0828566215145976e-44
0048101f  8b51a0                   mov       edx, dword ptr [ecx - 0x60]
00481022  8915dca45a00             mov       dword ptr [0x5aa4dc], edx ; bits=00000000, f32=0.0
00481028  c705d4a45a0000000000     mov       dword ptr [0x5aa4d4], 0 ; bits=00000000, f32=0.0
00481032  d905cca45a00             fld       dword ptr [0x5aa4cc] ; bits=00000000, f32=0.0
00481038  d905f477b400             fld       dword ptr [0xb477f4]
0048103e  d9c9                     fxch      st(1)
00481040  d81df477b400             fcomp     dword ptr [0xb477f4]
00481046  dfe0                     fnstsw    ax
00481048  9e                       sahf
00481049  898d00feffff             mov       dword ptr [ebp - 0x200], ecx
0048104f  0f8a13000000             jp        0x481068
00481055  7211                     jb        0x481068
00481057  8b8500feffff             mov       eax, dword ptr [ebp - 0x200]
0048105d  d84898                   fmul      dword ptr [eax - 0x68]
00481060  d91dcca45a00             fstp      dword ptr [0x5aa4cc] ; bits=00000000, f32=0.0
00481066  eb02                     jmp       0x48106a
00481068  ddd8                     fstp      st(0)
0048106a  8b05cca45a00             mov       eax, dword ptr [0x5aa4cc] ; bits=00000000, f32=0.0
00481070  8905bca45a00             mov       dword ptr [0x5aa4bc], eax ; bits=00000000, f32=0.0
00481076  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00481079  8d00                     lea       eax, [eax]
0048107b  50                       push      eax
0048107c  6800409800               push      0x984000
00481081  6860a45a00               push      0x5aa460
00481086  68d0905a00               push      0x5a90d0
0048108b  68e0a45a00               push      0x5aa4e0
00481090  68f477b400               push      0xb477f4
00481095  68bca45a00               push      0x5aa4bc
0048109a  68d4a45a00               push      0x5aa4d4
0048109f  68dca45a00               push      0x5aa4dc
004810a4  686ca45a00               push      0x5aa46c
004810a9  6870a45a00               push      0x5aa470
004810ae  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
004810b4  8d08                     lea       ecx, [eax]
004810b6  51                       push      ecx
004810b7  e844deffff               call      0x47ef00 ; _lstopf_
004810bc  83c430                   add       esp, 0x30
004810bf  8b1d60a45a00             mov       ebx, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
004810c5  83fb00                   cmp       ebx, 0
004810c8  7e5b                     jle       0x481125
004810ca  b801000000               mov       eax, 1
004810cf  83fb02                   cmp       ebx, 2
004810d2  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
004810d8  7c33                     jl        0x48110d
004810da  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
004810e0  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
004810e7  890c8508f19400           mov       dword ptr [eax*4 + 0x94f108], ecx
004810ee  8b0c8500409800           mov       ecx, dword ptr [eax*4 + 0x984000]
004810f5  890c850cf19400           mov       dword ptr [eax*4 + 0x94f10c], ecx
004810fc  83c002                   add       eax, 2
004810ff  83eb02                   sub       ebx, 2
00481102  83fb02                   cmp       ebx, 2
00481105  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
0048110b  7dcd                     jge       0x4810da
0048110d  85db                     test      ebx, ebx
0048110f  7414                     je        0x481125
00481111  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00481117  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
0048111e  890c8508f19400           mov       dword ptr [eax*4 + 0x94f108], ecx
00481125  8b0560a45a00             mov       eax, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
0048112b  890564a45a00             mov       dword ptr [0x5aa464], eax ; bits=00000000, f32=0.0
00481131  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00481134  8d00                     lea       eax, [eax]
00481136  50                       push      eax
00481137  6800409800               push      0x984000
0048113c  6860a45a00               push      0x5aa460
00481141  8d0560905a00             lea       eax, [0x5a9060] ; bits=16000000, f32=3.0828566215145976e-44
00481147  8985fcfdffff             mov       dword ptr [ebp - 0x204], eax
0048114d  8d4870                   lea       ecx, [eax + 0x70]
00481150  51                       push      ecx
00481151  68e0a45a00               push      0x5aa4e0
00481156  689ca45a00               push      0x5aa49c
0048115b  68f477b400               push      0xb477f4
00481160  68d4a45a00               push      0x5aa4d4
00481165  68dca45a00               push      0x5aa4dc
0048116a  686ca45a00               push      0x5aa46c
0048116f  6870a45a00               push      0x5aa470
00481174  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
0048117a  8d11                     lea       edx, [ecx]
0048117c  52                       push      edx
0048117d  e87eddffff               call      0x47ef00 ; _lstopf_
00481182  83c430                   add       esp, 0x30
00481185  833d60a45a0002           cmp       dword ptr [0x5aa460], 2 ; bits=00000000, f32=0.0
0048118c  752b                     jne       0x4811b9
0048118e  d90504409800             fld       dword ptr [0x984004]
00481194  d91508409800             fst       dword ptr [0x984008]
0048119a  d80500409800             fadd      dword ptr [0x984000]
004811a0  8b85fcfdffff             mov       eax, dword ptr [ebp - 0x204]
004811a6  d84898                   fmul      dword ptr [eax - 0x68]
004811a9  d91d04409800             fstp      dword ptr [0x984004]
004811af  c70560a45a0003000000     mov       dword ptr [0x5aa460], 3 ; bits=00000000, f32=0.0
004811b9  8b0560a45a00             mov       eax, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
004811bf  83c0ff                   add       eax, -1
004811c2  3d00000000               cmp       eax, 0
004811c7  8985f8fdffff             mov       dword ptr [ebp - 0x208], eax
004811cd  0f8e93000000             jle       0x481266
004811d3  b802000000               mov       eax, 2
004811d8  83bdf8fdffff02           cmp       dword ptr [ebp - 0x208], 2
004811df  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
004811e5  7c4e                     jl        0x481235
004811e7  8b1d64a45a00             mov       ebx, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
004811ed  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
004811f3  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
004811fa  890c9d0cf19400           mov       dword ptr [ebx*4 + 0x94f10c], ecx
00481201  8b0c8500409800           mov       ecx, dword ptr [eax*4 + 0x984000]
00481208  890c9d10f19400           mov       dword ptr [ebx*4 + 0x94f110], ecx
0048120f  83c302                   add       ebx, 2
00481212  8b8df8fdffff             mov       ecx, dword ptr [ebp - 0x208]
00481218  83e902                   sub       ecx, 2
0048121b  83c002                   add       eax, 2
0048121e  83f902                   cmp       ecx, 2
00481221  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
00481227  898df8fdffff             mov       dword ptr [ebp - 0x208], ecx
0048122d  7dbe                     jge       0x4811ed
0048122f  891d64a45a00             mov       dword ptr [0x5aa464], ebx ; bits=00000000, f32=0.0
00481235  8b85f8fdffff             mov       eax, dword ptr [ebp - 0x208]
0048123b  85c0                     test      eax, eax
0048123d  7427                     je        0x481266
0048123f  8b0564a45a00             mov       eax, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
00481245  40                       inc       eax
00481246  890564a45a00             mov       dword ptr [0x5aa464], eax ; bits=00000000, f32=0.0
0048124c  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00481252  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
00481259  8b0564a45a00             mov       eax, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
0048125f  890c8508f19400           mov       dword ptr [eax*4 + 0x94f108], ecx
00481266  d905f477b400             fld       dword ptr [0xb477f4]
0048126c  d80d0478b400             fmul      dword ptr [0xb47804]
00481272  d9e0                     fchs
00481274  d91dd4a45a00             fstp      dword ptr [0x5aa4d4] ; bits=00000000, f32=0.0
0048127a  8d0560905a00             lea       eax, [0x5a9060] ; bits=16000000, f32=3.0828566215145976e-44
00481280  8985f4fdffff             mov       dword ptr [ebp - 0x20c], eax
00481286  8b48a0                   mov       ecx, dword ptr [eax - 0x60]
00481289  890ddca45a00             mov       dword ptr [0x5aa4dc], ecx ; bits=00000000, f32=0.0
0048128f  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
00481292  8d09                     lea       ecx, [ecx]
00481294  51                       push      ecx
00481295  6800409800               push      0x984000
0048129a  6860a45a00               push      0x5aa460
0048129f  8d4870                   lea       ecx, [eax + 0x70]
004812a2  51                       push      ecx
004812a3  68e0a45a00               push      0x5aa4e0
004812a8  6898a45a00               push      0x5aa498
004812ad  689ca45a00               push      0x5aa49c
004812b2  68d4a45a00               push      0x5aa4d4
004812b7  68dca45a00               push      0x5aa4dc
004812bc  686ca45a00               push      0x5aa46c
004812c1  6870a45a00               push      0x5aa470
004812c6  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
004812cc  8d11                     lea       edx, [ecx]
004812ce  52                       push      edx
004812cf  e82cdcffff               call      0x47ef00 ; _lstopf_
004812d4  83c430                   add       esp, 0x30
004812d7  833d60a45a0002           cmp       dword ptr [0x5aa460], 2 ; bits=00000000, f32=0.0
004812de  752b                     jne       0x48130b
004812e0  d90504409800             fld       dword ptr [0x984004]
004812e6  d91508409800             fst       dword ptr [0x984008]
004812ec  d80500409800             fadd      dword ptr [0x984000]
004812f2  8b85f4fdffff             mov       eax, dword ptr [ebp - 0x20c]
004812f8  d84898                   fmul      dword ptr [eax - 0x68]
004812fb  d91d04409800             fstp      dword ptr [0x984004]
00481301  c70560a45a0003000000     mov       dword ptr [0x5aa460], 3 ; bits=00000000, f32=0.0
0048130b  8b0560a45a00             mov       eax, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
00481311  83c0ff                   add       eax, -1
00481314  3d00000000               cmp       eax, 0
00481319  8985f0fdffff             mov       dword ptr [ebp - 0x210], eax
0048131f  0f8e93000000             jle       0x4813b8
00481325  b802000000               mov       eax, 2
0048132a  83bdf0fdffff02           cmp       dword ptr [ebp - 0x210], 2
00481331  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
00481337  7c4e                     jl        0x481387
00481339  8b1d64a45a00             mov       ebx, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
0048133f  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00481345  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
0048134c  890c9d0cf19400           mov       dword ptr [ebx*4 + 0x94f10c], ecx
00481353  8b0c8500409800           mov       ecx, dword ptr [eax*4 + 0x984000]
0048135a  890c9d10f19400           mov       dword ptr [ebx*4 + 0x94f110], ecx
00481361  83c302                   add       ebx, 2
00481364  8b8df0fdffff             mov       ecx, dword ptr [ebp - 0x210]
0048136a  83e902                   sub       ecx, 2
0048136d  83c002                   add       eax, 2
00481370  83f902                   cmp       ecx, 2
00481373  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
00481379  898df0fdffff             mov       dword ptr [ebp - 0x210], ecx
0048137f  7dbe                     jge       0x48133f
00481381  891d64a45a00             mov       dword ptr [0x5aa464], ebx ; bits=00000000, f32=0.0
00481387  8b85f0fdffff             mov       eax, dword ptr [ebp - 0x210]
0048138d  85c0                     test      eax, eax
0048138f  7427                     je        0x4813b8
00481391  8b0564a45a00             mov       eax, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
00481397  40                       inc       eax
00481398  890564a45a00             mov       dword ptr [0x5aa464], eax ; bits=00000000, f32=0.0
0048139e  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
004813a4  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
004813ab  8b0564a45a00             mov       eax, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
004813b1  890c8508f19400           mov       dword ptr [eax*4 + 0x94f108], ecx
004813b8  db6da4                   fld       xword ptr [ebp - 0x5c]
004813bb  d81de08f5a00             fcomp     dword ptr [0x5a8fe0] ; bits=00000000, f32=0.0
004813c1  dfe0                     fnstsw    ax
004813c3  9e                       sahf
004813c4  0f8a1b000000             jp        0x4813e5
004813ca  7619                     jbe       0x4813e5
004813cc  d905f477b400             fld       dword ptr [0xb477f4]
004813d2  d80dc8a45a00             fmul      dword ptr [0x5aa4c8] ; bits=00000000, f32=0.0
004813d8  db6da4                   fld       xword ptr [ebp - 0x5c]
004813db  def9                     fdivp     st(1)
004813dd  d91db8a45a00             fstp      dword ptr [0x5aa4b8] ; bits=00000000, f32=0.0
004813e3  eb0c                     jmp       0x4813f1
004813e5  8b05c8a45a00             mov       eax, dword ptr [0x5aa4c8] ; bits=00000000, f32=0.0
004813eb  8905b8a45a00             mov       dword ptr [0x5aa4b8], eax ; bits=00000000, f32=0.0
004813f1  d905b8a45a00             fld       dword ptr [0x5aa4b8] ; bits=00000000, f32=0.0
004813f7  d90598a45a00             fld       dword ptr [0x5aa498] ; bits=00000000, f32=0.0
004813fd  d9c9                     fxch      st(1)
004813ff  d81d98a45a00             fcomp     dword ptr [0x5aa498] ; bits=00000000, f32=0.0
00481405  dfe0                     fnstsw    ax
00481407  9e                       sahf
00481408  0f8a10000000             jp        0x48141e
0048140e  770e                     ja        0x48141e
00481410  d80dfc8f5a00             fmul      dword ptr [0x5a8ffc] ; bits=cdcc8c3f, f32=1.100000023841858
00481416  d91db8a45a00             fstp      dword ptr [0x5aa4b8] ; bits=00000000, f32=0.0
0048141c  eb02                     jmp       0x481420
0048141e  ddd8                     fstp      st(0)
00481420  d905f477b400             fld       dword ptr [0xb477f4]
00481426  db7da4                   fstp      xword ptr [ebp - 0x5c]
00481429  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0048142c  8d00                     lea       eax, [eax]
0048142e  50                       push      eax
0048142f  6800409800               push      0x984000
00481434  6860a45a00               push      0x5aa460
00481439  68d0905a00               push      0x5a90d0
0048143e  68e0a45a00               push      0x5aa4e0
00481443  68b8a45a00               push      0x5aa4b8
00481448  6898a45a00               push      0x5aa498
0048144d  68d4a45a00               push      0x5aa4d4
00481452  68dca45a00               push      0x5aa4dc
00481457  686ca45a00               push      0x5aa46c
0048145c  6870a45a00               push      0x5aa470
00481461  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481467  8d08                     lea       ecx, [eax]
00481469  51                       push      ecx
0048146a  e891daffff               call      0x47ef00 ; _lstopf_
0048146f  83c430                   add       esp, 0x30
00481472  8b0560a45a00             mov       eax, dword ptr [0x5aa460] ; bits=00000000, f32=0.0
00481478  83c0ff                   add       eax, -1
0048147b  3d00000000               cmp       eax, 0
00481480  8985ecfdffff             mov       dword ptr [ebp - 0x214], eax
00481486  0f8e93000000             jle       0x48151f
0048148c  b802000000               mov       eax, 2
00481491  83bdecfdffff02           cmp       dword ptr [ebp - 0x214], 2
00481498  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
0048149e  7c4e                     jl        0x4814ee
004814a0  8b1d64a45a00             mov       ebx, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
004814a6  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
004814ac  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
004814b3  890c9d0cf19400           mov       dword ptr [ebx*4 + 0x94f10c], ecx
004814ba  8b0c8500409800           mov       ecx, dword ptr [eax*4 + 0x984000]
004814c1  890c9d10f19400           mov       dword ptr [ebx*4 + 0x94f110], ecx
004814c8  83c302                   add       ebx, 2
004814cb  8b8decfdffff             mov       ecx, dword ptr [ebp - 0x214]
004814d1  83e902                   sub       ecx, 2
004814d4  83c002                   add       eax, 2
004814d7  83f902                   cmp       ecx, 2
004814da  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
004814e0  898decfdffff             mov       dword ptr [ebp - 0x214], ecx
004814e6  7dbe                     jge       0x4814a6
004814e8  891d64a45a00             mov       dword ptr [0x5aa464], ebx ; bits=00000000, f32=0.0
004814ee  8b85ecfdffff             mov       eax, dword ptr [ebp - 0x214]
004814f4  85c0                     test      eax, eax
004814f6  7427                     je        0x48151f
004814f8  8b0564a45a00             mov       eax, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
004814fe  40                       inc       eax
004814ff  890564a45a00             mov       dword ptr [0x5aa464], eax ; bits=00000000, f32=0.0
00481505  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
0048150b  8b0c85fc3f9800           mov       ecx, dword ptr [eax*4 + 0x983ffc]
00481512  8b0564a45a00             mov       eax, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
00481518  890c8508f19400           mov       dword ptr [eax*4 + 0x94f108], ecx
0048151f  8b0564a45a00             mov       eax, dword ptr [0x5aa464] ; bits=00000000, f32=0.0
00481525  3d00000000               cmp       eax, 0
0048152a  8985e8fdffff             mov       dword ptr [ebp - 0x218], eax
00481530  0f8e8b170000             jle       0x482cc1
00481536  b801000000               mov       eax, 1
0048153b  dbad74ffffff             fld       xword ptr [ebp - 0x8c]
00481541  d825ec8f5a00             fsub      dword ptr [0x5a8fec] ; bits=0000803f, f32=1.0
00481547  dbbd5cffffff             fstp      xword ptr [ebp - 0xa4]
0048154d  d9059ca45a00             fld       dword ptr [0x5aa49c] ; bits=00000000, f32=0.0
00481553  d82d98a45a00             fsubr     dword ptr [0x5aa498] ; bits=00000000, f32=0.0
00481559  dbbd50ffffff             fstp      xword ptr [ebp - 0xb0]
0048155f  8b8d20feffff             mov       ecx, dword ptr [ebp - 0x1e0]
00481565  898de4fdffff             mov       dword ptr [ebp - 0x21c], ecx
0048156b  8985e0fdffff             mov       dword ptr [ebp - 0x220], eax
00481571  d905b0a45a00             fld       dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
00481577  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
0048157d  d8048508f19400           fadd      dword ptr [eax*4 + 0x94f108]
00481584  d905b477b400             fld       dword ptr [0xb477b4]
0048158a  d9c9                     fxch      st(1)
0048158c  d825b477b400             fsub      dword ptr [0xb477b4]
00481592  dbbd44ffffff             fstp      xword ptr [ebp - 0xbc]
00481598  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
0048159e  dec1                     faddp     st(1)
004815a0  d9c0                     fld       st(0)
004815a2  d825b077b400             fsub      dword ptr [0xb477b0]
004815a8  8b8d78feffff             mov       ecx, dword ptr [ebp - 0x188]
004815ae  d91d8877b400             fstp      dword ptr [0xb47788]
004815b4  8b19                     mov       ebx, dword ptr [ecx]
004815b6  8b148508f19400           mov       edx, dword ptr [eax*4 + 0x94f108]
004815bd  8b358877b400             mov       esi, dword ptr [0xb47788]
004815c3  8b3df477b400             mov       edi, dword ptr [0xb477f4]
004815c9  8d0da49a5a00             lea       ecx, [0x5a9aa4] ; bits=09020000, f32=7.300764999132297e-43
004815cf  895dfc                   mov       dword ptr [ebp - 4], ebx
004815d2  8d45fc                   lea       eax, [ebp - 4]
004815d5  894108                   mov       dword ptr [ecx + 8], eax
004815d8  8955f8                   mov       dword ptr [ebp - 8], edx
004815db  8d45f8                   lea       eax, [ebp - 8]
004815de  894128                   mov       dword ptr [ecx + 0x28], eax
004815e1  d95df4                   fstp      dword ptr [ebp - 0xc]
004815e4  8d45f4                   lea       eax, [ebp - 0xc]
004815e7  894134                   mov       dword ptr [ecx + 0x34], eax
004815ea  8975f0                   mov       dword ptr [ebp - 0x10], esi
004815ed  8d45f0                   lea       eax, [ebp - 0x10]
004815f0  894140                   mov       dword ptr [ecx + 0x40], eax
004815f3  897de8                   mov       dword ptr [ebp - 0x18], edi
004815f6  8d45e8                   lea       eax, [ebp - 0x18]
004815f9  89414c                   mov       dword ptr [ecx + 0x4c], eax
004815fc  51                       push      ecx
004815fd  e8ee0f0200               call      0x4a25f0 ; _jwe_isfm
00481602  83c404                   add       esp, 4
00481605  8d05849a5a00             lea       eax, [0x5a9a84] ; bits=69020000, f32=8.646011524884121e-43
0048160b  895dfc                   mov       dword ptr [ebp - 4], ebx
0048160e  8d4dfc                   lea       ecx, [ebp - 4]
00481611  894808                   mov       dword ptr [eax + 8], ecx
00481614  50                       push      eax
00481615  e8d60f0200               call      0x4a25f0 ; _jwe_isfm
0048161a  83c404                   add       esp, 4
0048161d  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
00481623  c704855cfe940000000000   mov       dword ptr [eax*4 + 0x94fe5c], 0
0048162e  68e477b400               push      0xb477e4
00481633  681078b400               push      0xb47810
00481638  68ec77b400               push      0xb477ec
0048163d  681478b400               push      0xb47814
00481642  68dc77b400               push      0xb477dc
00481647  68d877b400               push      0xb477d8
0048164c  68d477b400               push      0xb477d4
00481651  68d077b400               push      0xb477d0
00481656  688ca45a00               push      0x5aa48c
0048165b  68c477b400               push      0xb477c4
00481660  689c77b400               push      0xb4779c
00481665  688877b400               push      0xb47788
0048166a  688077b400               push      0xb47780 ; _ufcom_
0048166f  e85c7bfcff               call      0x4491d0 ; _xlkt22_
00481674  83c434                   add       esp, 0x34
00481677  d9059ca45a00             fld       dword ptr [0x5aa49c] ; bits=00000000, f32=0.0
0048167d  dbbd38ffffff             fstp      xword ptr [ebp - 0xc8]
00481683  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00481689  dbad38ffffff             fld       xword ptr [ebp - 0xc8]
0048168f  d9c9                     fxch      st(1)
00481691  ded9                     fcompp
00481693  dfe0                     fnstsw    ax
00481695  9e                       sahf
00481696  0f8a730b0000             jp        0x48220f
0048169c  0f876d0b0000             ja        0x48220f
004816a2  8d056aa55a00             lea       eax, [0x5aa56a] ; bits=00000000, f32=0.0
004816a8  c60046                   mov       byte ptr [eax], 0x46
004816ab  c6400157                 mov       byte ptr [eax + 1], 0x57
004816af  d9ee                     fldz
004816b1  d9c0                     fld       st(0)
004816b3  d9050078b400             fld       dword ptr [0xb47800]
004816b9  d80d0078b400             fmul      dword ptr [0xb47800]
004816bf  d83df88f5a00             fdivr     dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
004816c5  d805ec8f5a00             fadd      dword ptr [0x5a8fec] ; bits=0000803f, f32=1.0
004816cb  dbbd2cffffff             fstp      xword ptr [ebp - 0xd4]
004816d1  d9056cf70e04             fld       dword ptr [0x40ef76c]
004816d7  d9ca                     fxch      st(2)
004816d9  dbbd20ffffff             fstp      xword ptr [ebp - 0xe0]
004816df  dbad20ffffff             fld       xword ptr [ebp - 0xe0]
004816e5  d9ca                     fxch      st(2)
004816e7  dbad2cffffff             fld       xword ptr [ebp - 0xd4]
004816ed  dee3                     fsubrp    st(3)
004816ef  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
004816f5  def3                     fdivrp    st(3)
004816f7  d9c9                     fxch      st(1)
004816f9  d8ea                     fsubr     st(2)
004816fb  d9e1                     fabs
004816fd  d8f2                     fdiv      st(2)
004816ff  d8d9                     fcomp     st(1)
00481701  dfe0                     fnstsw    ax
00481703  9e                       sahf
00481704  0f8a26000000             jp        0x481730
0048170a  7624                     jbe       0x481730
0048170c  d9c1                     fld       st(1)
0048170e  d905ec77b400             fld       dword ptr [0xb477ec]
00481714  d80df88f5a00             fmul      dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
0048171a  d9cb                     fxch      st(3)
0048171c  d80dfc77b400             fmul      dword ptr [0xb477fc]
00481722  d8359c77b400             fdiv      dword ptr [0xb4779c]
00481728  d8c8                     fmul      st(0)
0048172a  decb                     fmulp     st(3)
0048172c  d9c9                     fxch      st(1)
0048172e  ebb7                     jmp       0x4816e7
00481730  ddd8                     fstp      st(0)
00481732  d91d8c77b400             fstp      dword ptr [0xb4778c]
00481738  d9058c77b400             fld       dword ptr [0xb4778c]
0048173e  d9c0                     fld       st(0)
00481740  d80dfc77b400             fmul      dword ptr [0xb477fc]
00481746  d9c1                     fld       st(1)
00481748  d80d0878b400             fmul      dword ptr [0xb47808]
0048174e  d9fa                     fsqrt
00481750  d95df8                   fstp      dword ptr [ebp - 8]
00481753  d84df8                   fmul      dword ptr [ebp - 8]
00481756  d91deca45a00             fstp      dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
0048175c  dbbd14ffffff             fstp      xword ptr [ebp - 0xec]
00481762  d9058877b400             fld       dword ptr [0xb47788]
00481768  d805b077b400             fadd      dword ptr [0xb477b0]
0048176e  d905f477b400             fld       dword ptr [0xb477f4]
00481774  d905b477b400             fld       dword ptr [0xb477b4]
0048177a  d9c0                     fld       st(0)
0048177c  d805f477b400             fadd      dword ptr [0xb477f4]
00481782  d9cb                     fxch      st(3)
00481784  d8d3                     fcom      st(3)
00481786  d9cb                     fxch      st(3)
00481788  dbbd08ffffff             fstp      xword ptr [ebp - 0xf8]
0048178e  dbbdfcfeffff             fstp      xword ptr [ebp - 0x104]
00481794  dbbdf0feffff             fstp      xword ptr [ebp - 0x110]
0048179a  dfe0                     fnstsw    ax
0048179c  9e                       sahf
0048179d  0f8a11010000             jp        0x4818b4
004817a3  0f860b010000             jbe       0x4818b4
004817a9  d905f877b400             fld       dword ptr [0xb477f8]
004817af  d80d0078b400             fmul      dword ptr [0xb47800]
004817b5  d9c0                     fld       st(0)
004817b7  d8c8                     fmul      st(0)
004817b9  d80d0c78b400             fmul      dword ptr [0xb4780c]
004817bf  dbadf0feffff             fld       xword ptr [ebp - 0x110]
004817c5  deeb                     fsubp     st(3)
004817c7  dbadfcfeffff             fld       xword ptr [ebp - 0x104]
004817cd  deeb                     fsubp     st(3)
004817cf  deca                     fmulp     st(2)
004817d1  d8359c77b400             fdiv      dword ptr [0xb4779c]
004817d7  d8c8                     fmul      st(0)
004817d9  d80dec77b400             fmul      dword ptr [0xb477ec]
004817df  d82dec8f5a00             fsubr     dword ptr [0x5a8fec] ; bits=0000803f, f32=1.0
004817e5  def9                     fdivp     st(1)
004817e7  d91d1878b400             fstp      dword ptr [0xb47818]
004817ed  dbad08ffffff             fld       xword ptr [ebp - 0xf8]
004817f3  d825b877b400             fsub      dword ptr [0xb477b8]
004817f9  d91d9077b400             fstp      dword ptr [0xb47790]
004817ff  682078b400               push      0xb47820
00481804  689077b400               push      0xb47790
00481809  688477b400               push      0xb47784
0048180e  e84d6affff               call      0x478260 ; _lktj_
00481813  83c40c                   add       esp, 0xc
00481816  d905b477b400             fld       dword ptr [0xb477b4]
0048181c  d805f477b400             fadd      dword ptr [0xb477f4]
00481822  d825bc77b400             fsub      dword ptr [0xb477bc]
00481828  d91d14a55a00             fstp      dword ptr [0x5aa514] ; bits=00000000, f32=0.0
0048182e  d9058877b400             fld       dword ptr [0xb47788]
00481834  d805b077b400             fadd      dword ptr [0xb477b0]
0048183a  d825bc77b400             fsub      dword ptr [0xb477bc]
00481840  d91d18a55a00             fstp      dword ptr [0x5aa518] ; bits=00000000, f32=0.0
00481846  6850a45a00               push      0x5aa450
0048184b  680ca55a00               push      0x5aa50c
00481850  6818a55a00               push      0x5aa518
00481855  6814a55a00               push      0x5aa514
0048185a  6840ec4700               push      0x47ec40 ; _rswmy4_
0048185f  6868f70e04               push      0x40ef768
00481864  686cf70e04               push      0x40ef76c
00481869  e8820affff               call      0x4722f0 ; _regfal_
0048186e  83c41c                   add       esp, 0x1c
00481871  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00481878  7446                     je        0x4818c0
0048187a  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481880  8b08                     mov       ecx, dword ptr [eax]
00481882  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00481888  8d1d4c9a5a00             lea       ebx, [0x5a9a4c] ; bits=09020000, f32=7.300764999132297e-43
0048188e  894dfc                   mov       dword ptr [ebp - 4], ecx
00481891  8d4dfc                   lea       ecx, [ebp - 4]
00481894  894b08                   mov       dword ptr [ebx + 8], ecx
00481897  8955ec                   mov       dword ptr [ebp - 0x14], edx
0048189a  8d4dec                   lea       ecx, [ebp - 0x14]
0048189d  894b28                   mov       dword ptr [ebx + 0x28], ecx
004818a0  53                       push      ebx
004818a1  e84a0d0200               call      0x4a25f0 ; _jwe_isfm
004818a6  83c404                   add       esp, 4
004818a9  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004818ac  c70001000000             mov       dword ptr [eax], 1
004818b2  eb0c                     jmp       0x4818c0
004818b4  d825bc77b400             fsub      dword ptr [0xb477bc]
004818ba  d91d0ca55a00             fstp      dword ptr [0x5aa50c] ; bits=00000000, f32=0.0
004818c0  dbad14ffffff             fld       xword ptr [ebp - 0xec]
004818c6  d805b477b400             fadd      dword ptr [0xb477b4]
004818cc  d825b877b400             fsub      dword ptr [0xb477b8]
004818d2  d91d9077b400             fstp      dword ptr [0xb47790]
004818d8  8b059077b400             mov       eax, dword ptr [0xb47790]
004818de  8985dcfdffff             mov       dword ptr [ebp - 0x224], eax
004818e4  682078b400               push      0xb47820
004818e9  689077b400               push      0xb47790
004818ee  688477b400               push      0xb47784
004818f3  e86869ffff               call      0x478260 ; _lktj_
004818f8  83c40c                   add       esp, 0xc
004818fb  d905eca45a00             fld       dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
00481901  d80deca45a00             fmul      dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
00481907  d91d1878b400             fstp      dword ptr [0xb47818]
0048190d  dbad14ffffff             fld       xword ptr [ebp - 0xec]
00481913  d805b477b400             fadd      dword ptr [0xb477b4]
00481919  d825bc77b400             fsub      dword ptr [0xb477bc]
0048191f  d91d14a55a00             fstp      dword ptr [0x5aa514] ; bits=00000000, f32=0.0
00481925  d9058877b400             fld       dword ptr [0xb47788]
0048192b  d805b077b400             fadd      dword ptr [0xb477b0]
00481931  d825bc77b400             fsub      dword ptr [0xb477bc]
00481937  d91d18a55a00             fstp      dword ptr [0x5aa518] ; bits=00000000, f32=0.0
0048193d  6850a45a00               push      0x5aa450
00481942  6808a55a00               push      0x5aa508
00481947  6818a55a00               push      0x5aa518
0048194c  6814a55a00               push      0x5aa514
00481951  6840ec4700               push      0x47ec40 ; _rswmy4_
00481956  6868f70e04               push      0x40ef768
0048195b  686cf70e04               push      0x40ef76c
00481960  e88b09ffff               call      0x4722f0 ; _regfal_
00481965  83c41c                   add       esp, 0x1c
00481968  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
0048196f  7e38                     jle       0x4819a9
00481971  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481977  8b08                     mov       ecx, dword ptr [eax]
00481979  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
0048197f  8d1d149a5a00             lea       ebx, [0x5a9a14] ; bits=09020000, f32=7.300764999132297e-43
00481985  894dfc                   mov       dword ptr [ebp - 4], ecx
00481988  8d4dfc                   lea       ecx, [ebp - 4]
0048198b  894b08                   mov       dword ptr [ebx + 8], ecx
0048198e  8955ec                   mov       dword ptr [ebp - 0x14], edx
00481991  8d4dec                   lea       ecx, [ebp - 0x14]
00481994  894b28                   mov       dword ptr [ebx + 0x28], ecx
00481997  53                       push      ebx
00481998  e8530c0200               call      0x4a25f0 ; _jwe_isfm
0048199d  83c404                   add       esp, 4
004819a0  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004819a3  c70001000000             mov       dword ptr [eax], 1
004819a9  d905bc77b400             fld       dword ptr [0xb477bc]
004819af  d80508a55a00             fadd      dword ptr [0x5aa508] ; bits=00000000, f32=0.0
004819b5  d9c0                     fld       st(0)
004819b7  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
004819bd  d9058877b400             fld       dword ptr [0xb47788]
004819c3  d805b077b400             fadd      dword ptr [0xb477b0]
004819c9  dee2                     fsubrp    st(2)
004819cb  d9c9                     fxch      st(1)
004819cd  dbbde4feffff             fstp      xword ptr [ebp - 0x11c]
004819d3  d9059c77b400             fld       dword ptr [0xb4779c]
004819d9  d83deca45a00             fdivr     dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
004819df  d8c8                     fmul      st(0)
004819e1  d80dec77b400             fmul      dword ptr [0xb477ec]
004819e7  d8350c78b400             fdiv      dword ptr [0xb4780c]
004819ed  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
004819f3  dec1                     faddp     st(1)
004819f5  d905a077b400             fld       dword ptr [0xb477a0]
004819fb  d83deca45a00             fdivr     dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
00481a01  d8c8                     fmul      st(0)
00481a03  d80d2478b400             fmul      dword ptr [0xb47824]
00481a09  d8350c78b400             fdiv      dword ptr [0xb4780c]
00481a0f  d8c2                     fadd      st(2)
00481a11  dee9                     fsubp     st(1)
00481a13  d815e08f5a00             fcom      dword ptr [0x5a8fe0] ; bits=00000000, f32=0.0
00481a19  d9c9                     fxch      st(1)
00481a1b  dfe0                     fnstsw    ax
00481a1d  9e                       sahf
00481a1e  0f8a0d000000             jp        0x481a31
00481a24  730b                     jae       0x481a31
00481a26  b801000000               mov       eax, 1
00481a2b  89850cfeffff             mov       dword ptr [ebp - 0x1f4], eax
00481a31  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481a34  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
00481a3a  8b8d48feffff             mov       ecx, dword ptr [ebp - 0x1b8]
00481a40  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481a43  8d1401                   lea       edx, [ecx + eax]
00481a46  8b1deca45a00             mov       ebx, dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
00481a4c  891c9500fc9400           mov       dword ptr [edx*4 + 0x94fc00], ebx
00481a53  dbade4feffff             fld       xword ptr [ebp - 0x11c]
00481a59  d91c85acee9400           fstp      dword ptr [eax*4 + 0x94eeac]
00481a60  8d1564a55a00             lea       edx, [0x5aa564] ; bits=00000000, f32=0.0
00481a66  c60220                   mov       byte ptr [edx], 0x20
00481a69  c6420120                 mov       byte ptr [edx + 1], 0x20
00481a6d  c642022d                 mov       byte ptr [edx + 2], 0x2d
00481a71  c642032d                 mov       byte ptr [edx + 3], 0x2d
00481a75  c642042d                 mov       byte ptr [edx + 4], 0x2d
00481a79  c6420520                 mov       byte ptr [edx + 5], 0x20
00481a7d  68eca45a00               push      0x5aa4ec
00481a82  6a0a                     push      0xa
00481a84  6820a75a00               push      0x5aa720
00481a89  e8c2b3feff               call      0x46ce50 ; _put10_
00481a8e  83c40c                   add       esp, 0xc
00481a91  8d0540a65a00             lea       eax, [0x5aa640] ; bits=00000000, f32=0.0
00481a97  8d0d20a75a00             lea       ecx, [0x5aa720] ; bits=00000000, f32=0.0
00481a9d  8a11                     mov       dl, byte ptr [ecx]
00481a9f  8810                     mov       byte ptr [eax], dl
00481aa1  8a5101                   mov       dl, byte ptr [ecx + 1]
00481aa4  885001                   mov       byte ptr [eax + 1], dl
00481aa7  8a5102                   mov       dl, byte ptr [ecx + 2]
00481aaa  885002                   mov       byte ptr [eax + 2], dl
00481aad  8a5103                   mov       dl, byte ptr [ecx + 3]
00481ab0  885003                   mov       byte ptr [eax + 3], dl
00481ab3  8a5104                   mov       dl, byte ptr [ecx + 4]
00481ab6  885004                   mov       byte ptr [eax + 4], dl
00481ab9  8a5105                   mov       dl, byte ptr [ecx + 5]
00481abc  885005                   mov       byte ptr [eax + 5], dl
00481abf  8a5106                   mov       dl, byte ptr [ecx + 6]
00481ac2  885006                   mov       byte ptr [eax + 6], dl
00481ac5  8a5107                   mov       dl, byte ptr [ecx + 7]
00481ac8  885007                   mov       byte ptr [eax + 7], dl
00481acb  8a5108                   mov       dl, byte ptr [ecx + 8]
00481ace  885008                   mov       byte ptr [eax + 8], dl
00481ad1  8a5109                   mov       dl, byte ptr [ecx + 9]
00481ad4  885009                   mov       byte ptr [eax + 9], dl
00481ad7  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481add  8b08                     mov       ecx, dword ptr [eax]
00481adf  d9059077b400             fld       dword ptr [0xb47790]
00481ae5  d805b877b400             fadd      dword ptr [0xb477b8]
00481aeb  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
00481af1  8d1594995a00             lea       edx, [0x5a9994] ; bits=09020000, f32=7.300764999132297e-43
00481af7  894dfc                   mov       dword ptr [ebp - 4], ecx
00481afa  8d4dfc                   lea       ecx, [ebp - 4]
00481afd  894a08                   mov       dword ptr [edx + 8], ecx
00481b00  dbade4feffff             fld       xword ptr [ebp - 0x11c]
00481b06  d95df8                   fstp      dword ptr [ebp - 8]
00481b09  8d4df8                   lea       ecx, [ebp - 8]
00481b0c  894a34                   mov       dword ptr [edx + 0x34], ecx
00481b0f  d95df4                   fstp      dword ptr [ebp - 0xc]
00481b12  8d4df4                   lea       ecx, [ebp - 0xc]
00481b15  894a40                   mov       dword ptr [edx + 0x40], ecx
00481b18  db6dc8                   fld       xword ptr [ebp - 0x38]
00481b1b  d95df0                   fstp      dword ptr [ebp - 0x10]
00481b1e  8d4df0                   lea       ecx, [ebp - 0x10]
00481b21  894a4c                   mov       dword ptr [edx + 0x4c], ecx
00481b24  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481b27  d95de8                   fstp      dword ptr [ebp - 0x18]
00481b2a  8d4de8                   lea       ecx, [ebp - 0x18]
00481b2d  894a7c                   mov       dword ptr [edx + 0x7c], ecx
00481b30  52                       push      edx
00481b31  e8ba0a0200               call      0x4a25f0 ; _jwe_isfm
00481b36  83c404                   add       esp, 4
00481b39  8b8538feffff             mov       eax, dword ptr [ebp - 0x1c8]
00481b3f  8985d8fdffff             mov       dword ptr [ebp - 0x228], eax
00481b45  3d00000000               cmp       eax, 0
00481b4a  0f8e370e0000             jle       0x482987
00481b50  8b8540feffff             mov       eax, dword ptr [ebp - 0x1c0]
00481b56  89c3                     mov       ebx, eax
00481b58  8b953cfeffff             mov       edx, dword ptr [ebp - 0x1c4]
00481b5e  8b8de0fdffff             mov       ecx, dword ptr [ebp - 0x220]
00481b64  8d340a                   lea       esi, [edx + ecx]
00481b67  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00481b6d  89b5d4fdffff             mov       dword ptr [ebp - 0x22c], esi
00481b73  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481b76  dbade4feffff             fld       xword ptr [ebp - 0x11c]
00481b7c  d80c9de0f89400           fmul      dword ptr [ebx*4 + 0x94f8e0]
00481b83  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481b86  d9058877b400             fld       dword ptr [0xb47788]
00481b8c  d805b077b400             fadd      dword ptr [0xb477b0]
00481b92  db6dc8                   fld       xword ptr [ebp - 0x38]
00481b95  dee9                     fsubp     st(1)
00481b97  d9c0                     fld       st(0)
00481b99  d825bc77b400             fsub      dword ptr [0xb477bc]
00481b9f  d91d9477b400             fstp      dword ptr [0xb47794]
00481ba5  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
00481bab  8b85dcfdffff             mov       eax, dword ptr [ebp - 0x224]
00481bb1  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481bb4  890514a55a00             mov       dword ptr [0x5aa514], eax ; bits=00000000, f32=0.0
00481bba  8b059477b400             mov       eax, dword ptr [0xb47794]
00481bc0  890518a55a00             mov       dword ptr [0x5aa518], eax ; bits=00000000, f32=0.0
00481bc6  68e477b400               push      0xb477e4
00481bcb  681078b400               push      0xb47810
00481bd0  682478b400               push      0xb47824
00481bd5  681478b400               push      0xb47814
00481bda  68f077b400               push      0xb477f0
00481bdf  68d877b400               push      0xb477d8
00481be4  68d477b400               push      0xb477d4
00481be9  68ac77b400               push      0xb477ac
00481bee  688ca45a00               push      0x5aa48c
00481bf3  68c477b400               push      0xb477c4
00481bf8  68a077b400               push      0xb477a0
00481bfd  689477b400               push      0xb47794
00481c02  688477b400               push      0xb47784
00481c07  e8c475fcff               call      0x4491d0 ; _xlkt22_
00481c0c  83c434                   add       esp, 0x34
00481c0f  d9058877b400             fld       dword ptr [0xb47788]
00481c15  d805b077b400             fadd      dword ptr [0xb477b0]
00481c1b  d905b477b400             fld       dword ptr [0xb477b4]
00481c21  d805f477b400             fadd      dword ptr [0xb477f4]
00481c27  d9c9                     fxch      st(1)
00481c29  ded9                     fcompp
00481c2b  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481c2e  db6dc8                   fld       xword ptr [ebp - 0x38]
00481c31  db6dbc                   fld       xword ptr [ebp - 0x44]
00481c34  dfe0                     fnstsw    ax
00481c36  9e                       sahf
00481c37  0f8a4a010000             jp        0x481d87
00481c3d  0f8744010000             ja        0x481d87
00481c43  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481c46  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481c49  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481c4c  8d056aa55a00             lea       eax, [0x5aa56a] ; bits=00000000, f32=0.0
00481c52  c60053                   mov       byte ptr [eax], 0x53
00481c55  c6400157                 mov       byte ptr [eax + 1], 0x57
00481c59  8d0564a55a00             lea       eax, [0x5aa564] ; bits=00000000, f32=0.0
00481c5f  c60020                   mov       byte ptr [eax], 0x20
00481c62  c6400120                 mov       byte ptr [eax + 1], 0x20
00481c66  c640022d                 mov       byte ptr [eax + 2], 0x2d
00481c6a  c640032d                 mov       byte ptr [eax + 3], 0x2d
00481c6e  c640042d                 mov       byte ptr [eax + 4], 0x2d
00481c72  c6400520                 mov       byte ptr [eax + 5], 0x20
00481c76  6850a45a00               push      0x5aa450
00481c7b  6814a55a00               push      0x5aa514
00481c80  6868f70e04               push      0x40ef768
00481c85  6870eb4700               push      0x47eb70 ; _rswmy3_
00481c8a  6818a55a00               push      0x5aa518
00481c8f  e88c01ffff               call      0x471e20 ; _fdroot_
00481c94  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481c97  db6dc8                   fld       xword ptr [ebp - 0x38]
00481c9a  db6dbc                   fld       xword ptr [ebp - 0x44]
00481c9d  83c414                   add       esp, 0x14
00481ca0  833d50a45a0001           cmp       dword ptr [0x5aa450], 1 ; bits=00000000, f32=0.0
00481ca7  753b                     jne       0x481ce4
00481ca9  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481cac  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481caf  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481cb5  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481cb8  8b08                     mov       ecx, dword ptr [eax]
00481cba  8d1568995a00             lea       edx, [0x5a9968] ; bits=09020000, f32=7.300764999132297e-43
00481cc0  894dfc                   mov       dword ptr [ebp - 4], ecx
00481cc3  8d4dfc                   lea       ecx, [ebp - 4]
00481cc6  894a08                   mov       dword ptr [edx + 8], ecx
00481cc9  52                       push      edx
00481cca  e821090200               call      0x4a25f0 ; _jwe_isfm
00481ccf  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481cd2  db6dc8                   fld       xword ptr [ebp - 0x38]
00481cd5  db6dbc                   fld       xword ptr [ebp - 0x44]
00481cd8  83c404                   add       esp, 4
00481cdb  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00481cde  c70001000000             mov       dword ptr [eax], 1
00481ce4  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481ce7  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481cea  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481ced  6850a45a00               push      0x5aa450
00481cf2  689077b400               push      0xb47790
00481cf7  6818a55a00               push      0x5aa518
00481cfc  6814a55a00               push      0x5aa514
00481d01  6870eb4700               push      0x47eb70 ; _rswmy3_
00481d06  6868f70e04               push      0x40ef768
00481d0b  686cf70e04               push      0x40ef76c
00481d10  e8db05ffff               call      0x4722f0 ; _regfal_
00481d15  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481d18  db6dc8                   fld       xword ptr [ebp - 0x38]
00481d1b  db6dbc                   fld       xword ptr [ebp - 0x44]
00481d1e  83c41c                   add       esp, 0x1c
00481d21  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00481d28  744a                     je        0x481d74
00481d2a  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481d2d  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481d30  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481d36  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481d39  8b08                     mov       ecx, dword ptr [eax]
00481d3b  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00481d41  8d3530995a00             lea       esi, [0x5a9930] ; bits=09020000, f32=7.300764999132297e-43
00481d47  894dfc                   mov       dword ptr [ebp - 4], ecx
00481d4a  8d4dfc                   lea       ecx, [ebp - 4]
00481d4d  894e08                   mov       dword ptr [esi + 8], ecx
00481d50  8955ec                   mov       dword ptr [ebp - 0x14], edx
00481d53  8d4dec                   lea       ecx, [ebp - 0x14]
00481d56  894e28                   mov       dword ptr [esi + 0x28], ecx
00481d59  56                       push      esi
00481d5a  e891080200               call      0x4a25f0 ; _jwe_isfm
00481d5f  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481d62  db6dc8                   fld       xword ptr [ebp - 0x38]
00481d65  db6dbc                   fld       xword ptr [ebp - 0x44]
00481d68  83c404                   add       esp, 4
00481d6b  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00481d6e  c70001000000             mov       dword ptr [eax], 1
00481d74  d9051878b400             fld       dword ptr [0xb47818]
00481d7a  d9fa                     fsqrt
00481d7c  d91de4a45a00             fstp      dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00481d82  e9a8020000               jmp       0x48202f
00481d87  d9059477b400             fld       dword ptr [0xb47794]
00481d8d  d81d0ca55a00             fcomp     dword ptr [0x5aa50c] ; bits=00000000, f32=0.0
00481d93  dfe0                     fnstsw    ax
00481d95  9e                       sahf
00481d96  0f8a54010000             jp        0x481ef0
00481d9c  0f864e010000             jbe       0x481ef0
00481da2  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481da5  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481da8  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481dab  d9e8                     fld1
00481dad  d91d0478b400             fstp      dword ptr [0xb47804]
00481db3  d905f877b400             fld       dword ptr [0xb477f8]
00481db9  d80d0078b400             fmul      dword ptr [0xb47800]
00481dbf  d91dcc77b400             fstp      dword ptr [0xb477cc]
00481dc5  8d056aa55a00             lea       eax, [0x5aa56a] ; bits=00000000, f32=0.0
00481dcb  c60053                   mov       byte ptr [eax], 0x53
00481dce  c640014f                 mov       byte ptr [eax + 1], 0x4f
00481dd2  6804995a00               push      0x5a9904
00481dd7  e874fd0100               call      0x4a1b50 ; _jwe_iinf
00481ddc  83c404                   add       esp, 4
00481ddf  6850a45a00               push      0x5aa450
00481de4  6814a55a00               push      0x5aa514
00481de9  6868f70e04               push      0x40ef768
00481dee  6800ea4700               push      0x47ea00 ; _rsomy3_
00481df3  6818a55a00               push      0x5aa518
00481df8  e82300ffff               call      0x471e20 ; _fdroot_
00481dfd  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481e00  db6dc8                   fld       xword ptr [ebp - 0x38]
00481e03  db6dbc                   fld       xword ptr [ebp - 0x44]
00481e06  83c414                   add       esp, 0x14
00481e09  833d50a45a0001           cmp       dword ptr [0x5aa450], 1 ; bits=00000000, f32=0.0
00481e10  753b                     jne       0x481e4d
00481e12  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481e15  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481e18  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481e1e  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481e21  8b08                     mov       ecx, dword ptr [eax]
00481e23  8d15d8985a00             lea       edx, [0x5a98d8] ; bits=09020000, f32=7.300764999132297e-43
00481e29  894dfc                   mov       dword ptr [ebp - 4], ecx
00481e2c  8d4dfc                   lea       ecx, [ebp - 4]
00481e2f  894a08                   mov       dword ptr [edx + 8], ecx
00481e32  52                       push      edx
00481e33  e8b8070200               call      0x4a25f0 ; _jwe_isfm
00481e38  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481e3b  db6dc8                   fld       xword ptr [ebp - 0x38]
00481e3e  db6dbc                   fld       xword ptr [ebp - 0x44]
00481e41  83c404                   add       esp, 4
00481e44  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00481e47  c70001000000             mov       dword ptr [eax], 1
00481e4d  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481e50  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481e53  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481e56  6850a45a00               push      0x5aa450
00481e5b  689077b400               push      0xb47790
00481e60  6818a55a00               push      0x5aa518
00481e65  6814a55a00               push      0x5aa514
00481e6a  6800ea4700               push      0x47ea00 ; _rsomy3_
00481e6f  6868f70e04               push      0x40ef768
00481e74  686cf70e04               push      0x40ef76c
00481e79  e87204ffff               call      0x4722f0 ; _regfal_
00481e7e  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481e81  db6dc8                   fld       xword ptr [ebp - 0x38]
00481e84  db6dbc                   fld       xword ptr [ebp - 0x44]
00481e87  83c41c                   add       esp, 0x1c
00481e8a  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00481e91  744a                     je        0x481edd
00481e93  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481e96  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481e99  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481e9f  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481ea2  8b08                     mov       ecx, dword ptr [eax]
00481ea4  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00481eaa  8d35a0985a00             lea       esi, [0x5a98a0] ; bits=09020000, f32=7.300764999132297e-43
00481eb0  894dfc                   mov       dword ptr [ebp - 4], ecx
00481eb3  8d4dfc                   lea       ecx, [ebp - 4]
00481eb6  894e08                   mov       dword ptr [esi + 8], ecx
00481eb9  8955ec                   mov       dword ptr [ebp - 0x14], edx
00481ebc  8d4dec                   lea       ecx, [ebp - 0x14]
00481ebf  894e28                   mov       dword ptr [esi + 0x28], ecx
00481ec2  56                       push      esi
00481ec3  e828070200               call      0x4a25f0 ; _jwe_isfm
00481ec8  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481ecb  db6dc8                   fld       xword ptr [ebp - 0x38]
00481ece  db6dbc                   fld       xword ptr [ebp - 0x44]
00481ed1  83c404                   add       esp, 4
00481ed4  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00481ed7  c70001000000             mov       dword ptr [eax], 1
00481edd  d9051878b400             fld       dword ptr [0xb47818]
00481ee3  d9fa                     fsqrt
00481ee5  d91de4a45a00             fstp      dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00481eeb  e93f010000               jmp       0x48202f
00481ef0  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481ef3  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481ef6  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481ef9  8d056aa55a00             lea       eax, [0x5aa56a] ; bits=00000000, f32=0.0
00481eff  c60053                   mov       byte ptr [eax], 0x53
00481f02  c6400157                 mov       byte ptr [eax + 1], 0x57
00481f06  8d0564a55a00             lea       eax, [0x5aa564] ; bits=00000000, f32=0.0
00481f0c  c60020                   mov       byte ptr [eax], 0x20
00481f0f  c6400120                 mov       byte ptr [eax + 1], 0x20
00481f13  c640022d                 mov       byte ptr [eax + 2], 0x2d
00481f17  c640032d                 mov       byte ptr [eax + 3], 0x2d
00481f1b  c640042d                 mov       byte ptr [eax + 4], 0x2d
00481f1f  c6400520                 mov       byte ptr [eax + 5], 0x20
00481f23  6850a45a00               push      0x5aa450
00481f28  6814a55a00               push      0x5aa514
00481f2d  6868f70e04               push      0x40ef768
00481f32  6870eb4700               push      0x47eb70 ; _rswmy3_
00481f37  6818a55a00               push      0x5aa518
00481f3c  e8dffefeff               call      0x471e20 ; _fdroot_
00481f41  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481f44  db6dc8                   fld       xword ptr [ebp - 0x38]
00481f47  db6dbc                   fld       xword ptr [ebp - 0x44]
00481f4a  83c414                   add       esp, 0x14
00481f4d  833d50a45a0001           cmp       dword ptr [0x5aa450], 1 ; bits=00000000, f32=0.0
00481f54  753b                     jne       0x481f91
00481f56  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481f59  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481f5c  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481f62  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481f65  8b08                     mov       ecx, dword ptr [eax]
00481f67  8d1574985a00             lea       edx, [0x5a9874] ; bits=09020000, f32=7.300764999132297e-43
00481f6d  894dfc                   mov       dword ptr [ebp - 4], ecx
00481f70  8d4dfc                   lea       ecx, [ebp - 4]
00481f73  894a08                   mov       dword ptr [edx + 8], ecx
00481f76  52                       push      edx
00481f77  e874060200               call      0x4a25f0 ; _jwe_isfm
00481f7c  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481f7f  db6dc8                   fld       xword ptr [ebp - 0x38]
00481f82  db6dbc                   fld       xword ptr [ebp - 0x44]
00481f85  83c404                   add       esp, 4
00481f88  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00481f8b  c70001000000             mov       dword ptr [eax], 1
00481f91  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481f94  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481f97  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481f9a  6850a45a00               push      0x5aa450
00481f9f  689077b400               push      0xb47790
00481fa4  6818a55a00               push      0x5aa518
00481fa9  6814a55a00               push      0x5aa514
00481fae  6870eb4700               push      0x47eb70 ; _rswmy3_
00481fb3  6868f70e04               push      0x40ef768
00481fb8  686cf70e04               push      0x40ef76c
00481fbd  e82e03ffff               call      0x4722f0 ; _regfal_
00481fc2  db6dd4                   fld       xword ptr [ebp - 0x2c]
00481fc5  db6dc8                   fld       xword ptr [ebp - 0x38]
00481fc8  db6dbc                   fld       xword ptr [ebp - 0x44]
00481fcb  83c41c                   add       esp, 0x1c
00481fce  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00481fd5  744a                     je        0x482021
00481fd7  db7dbc                   fstp      xword ptr [ebp - 0x44]
00481fda  db7dc8                   fstp      xword ptr [ebp - 0x38]
00481fdd  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00481fe3  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00481fe6  8b08                     mov       ecx, dword ptr [eax]
00481fe8  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00481fee  8d353c985a00             lea       esi, [0x5a983c] ; bits=09020000, f32=7.300764999132297e-43
00481ff4  894dfc                   mov       dword ptr [ebp - 4], ecx
00481ff7  8d4dfc                   lea       ecx, [ebp - 4]
00481ffa  894e08                   mov       dword ptr [esi + 8], ecx
00481ffd  8955ec                   mov       dword ptr [ebp - 0x14], edx
00482000  8d4dec                   lea       ecx, [ebp - 0x14]
00482003  894e28                   mov       dword ptr [esi + 0x28], ecx
00482006  56                       push      esi
00482007  e8e4050200               call      0x4a25f0 ; _jwe_isfm
0048200c  db6dd4                   fld       xword ptr [ebp - 0x2c]
0048200f  db6dc8                   fld       xword ptr [ebp - 0x38]
00482012  db6dbc                   fld       xword ptr [ebp - 0x44]
00482015  83c404                   add       esp, 4
00482018  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0048201b  c70001000000             mov       dword ptr [eax], 1
00482021  d9051878b400             fld       dword ptr [0xb47818]
00482027  d9fa                     fsqrt
00482029  d91de4a45a00             fstp      dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
0048202f  8b059077b400             mov       eax, dword ptr [0xb47790]
00482035  8b95d4fdffff             mov       edx, dword ptr [ebp - 0x22c]
0048203b  8b0de4a45a00             mov       ecx, dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00482041  890c9500fc9400           mov       dword ptr [edx*4 + 0x94fc00], ecx
00482048  d9059c77b400             fld       dword ptr [0xb4779c]
0048204e  d83de4a45a00             fdivr     dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00482054  d8c8                     fmul      st(0)
00482056  d80dec77b400             fmul      dword ptr [0xb477ec]
0048205c  d8350c78b400             fdiv      dword ptr [0xb4780c]
00482062  d8c1                     fadd      st(1)
00482064  d905a077b400             fld       dword ptr [0xb477a0]
0048206a  d83de4a45a00             fdivr     dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00482070  d8c8                     fmul      st(0)
00482072  d80d2478b400             fmul      dword ptr [0xb47824]
00482078  d8350c78b400             fdiv      dword ptr [0xb4780c]
0048207e  d8c4                     fadd      st(4)
00482080  dee9                     fsubp     st(1)
00482082  d815e08f5a00             fcom      dword ptr [0x5a8fe0] ; bits=00000000, f32=0.0
00482088  d9ca                     fxch      st(2)
0048208a  d9c9                     fxch      st(1)
0048208c  8985dcfdffff             mov       dword ptr [ebp - 0x224], eax
00482092  dfe0                     fnstsw    ax
00482094  9e                       sahf
00482095  0f8a0d000000             jp        0x4820a8
0048209b  730b                     jae       0x4820a8
0048209d  b801000000               mov       eax, 1
004820a2  89850cfeffff             mov       dword ptr [ebp - 0x1f4], eax
004820a8  db7db0                   fstp      xword ptr [ebp - 0x50]
004820ab  db7dbc                   fstp      xword ptr [ebp - 0x44]
004820ae  db7dc8                   fstp      xword ptr [ebp - 0x38]
004820b1  db7dd4                   fstp      xword ptr [ebp - 0x2c]
004820b4  d9059077b400             fld       dword ptr [0xb47790]
004820ba  d805b877b400             fadd      dword ptr [0xb477b8]
004820c0  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
004820c6  dbbdd8feffff             fstp      xword ptr [ebp - 0x128]
004820cc  d905e4a45a00             fld       dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
004820d2  8b85d4fdffff             mov       eax, dword ptr [ebp - 0x22c]
004820d8  d834855cfe9400           fdiv      dword ptr [eax*4 + 0x94fe5c]
004820df  d9ed                     fldln2
004820e1  d9c0                     fld       st(0)
004820e3  d9c9                     fxch      st(1)
004820e5  d9ca                     fxch      st(2)
004820e7  d9f1                     fyl2x
004820e9  d95df8                   fstp      dword ptr [ebp - 8]
004820ec  d945f8                   fld       dword ptr [ebp - 8]
004820ef  d9049de4f89400           fld       dword ptr [ebx*4 + 0x94f8e4]
004820f6  d83c9de0f89400           fdivr     dword ptr [ebx*4 + 0x94f8e0]
004820fd  d9ca                     fxch      st(2)
004820ff  d9c9                     fxch      st(1)
00482101  d9ca                     fxch      st(2)
00482103  d9f1                     fyl2x
00482105  d95df8                   fstp      dword ptr [ebp - 8]
00482108  d875f8                   fdiv      dword ptr [ebp - 8]
0048210b  dbbdccfeffff             fstp      xword ptr [ebp - 0x134]
00482111  68e4a45a00               push      0x5aa4e4
00482116  6a0a                     push      0xa
00482118  6830a75a00               push      0x5aa730
0048211d  e82eadfeff               call      0x46ce50 ; _put10_
00482122  83c40c                   add       esp, 0xc
00482125  8d0540a65a00             lea       eax, [0x5aa640] ; bits=00000000, f32=0.0
0048212b  8d0d30a75a00             lea       ecx, [0x5aa730] ; bits=00000000, f32=0.0
00482131  8a11                     mov       dl, byte ptr [ecx]
00482133  8810                     mov       byte ptr [eax], dl
00482135  8a5101                   mov       dl, byte ptr [ecx + 1]
00482138  885001                   mov       byte ptr [eax + 1], dl
0048213b  8a5102                   mov       dl, byte ptr [ecx + 2]
0048213e  885002                   mov       byte ptr [eax + 2], dl
00482141  8a5103                   mov       dl, byte ptr [ecx + 3]
00482144  885003                   mov       byte ptr [eax + 3], dl
00482147  8a5104                   mov       dl, byte ptr [ecx + 4]
0048214a  885004                   mov       byte ptr [eax + 4], dl
0048214d  8a5105                   mov       dl, byte ptr [ecx + 5]
00482150  885005                   mov       byte ptr [eax + 5], dl
00482153  8a5106                   mov       dl, byte ptr [ecx + 6]
00482156  885006                   mov       byte ptr [eax + 6], dl
00482159  8a5107                   mov       dl, byte ptr [ecx + 7]
0048215c  885007                   mov       byte ptr [eax + 7], dl
0048215f  8a5108                   mov       dl, byte ptr [ecx + 8]
00482162  885008                   mov       byte ptr [eax + 8], dl
00482165  8a5109                   mov       dl, byte ptr [ecx + 9]
00482168  885009                   mov       byte ptr [eax + 9], dl
0048216b  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00482171  8b08                     mov       ecx, dword ptr [eax]
00482173  8b149de0f89400           mov       edx, dword ptr [ebx*4 + 0x94f8e0]
0048217a  8d35b0975a00             lea       esi, [0x5a97b0] ; bits=09020000, f32=7.300764999132297e-43
00482180  894dfc                   mov       dword ptr [ebp - 4], ecx
00482183  8d4dfc                   lea       ecx, [ebp - 4]
00482186  894e08                   mov       dword ptr [esi + 8], ecx
00482189  8955f8                   mov       dword ptr [ebp - 8], edx
0048218c  8d4df8                   lea       ecx, [ebp - 8]
0048218f  894e28                   mov       dword ptr [esi + 0x28], ecx
00482192  db6dbc                   fld       xword ptr [ebp - 0x44]
00482195  d95df4                   fstp      dword ptr [ebp - 0xc]
00482198  8d4df4                   lea       ecx, [ebp - 0xc]
0048219b  894e34                   mov       dword ptr [esi + 0x34], ecx
0048219e  dbadd8feffff             fld       xword ptr [ebp - 0x128]
004821a4  d95df0                   fstp      dword ptr [ebp - 0x10]
004821a7  8d4df0                   lea       ecx, [ebp - 0x10]
004821aa  894e40                   mov       dword ptr [esi + 0x40], ecx
004821ad  db6dd4                   fld       xword ptr [ebp - 0x2c]
004821b0  d95de8                   fstp      dword ptr [ebp - 0x18]
004821b3  8d4de8                   lea       ecx, [ebp - 0x18]
004821b6  894e4c                   mov       dword ptr [esi + 0x4c], ecx
004821b9  dbadccfeffff             fld       xword ptr [ebp - 0x134]
004821bf  d95de4                   fstp      dword ptr [ebp - 0x1c]
004821c2  8d4de4                   lea       ecx, [ebp - 0x1c]
004821c5  894e7c                   mov       dword ptr [esi + 0x7c], ecx
004821c8  db6dc8                   fld       xword ptr [ebp - 0x38]
004821cb  d95de0                   fstp      dword ptr [ebp - 0x20]
004821ce  8d4de0                   lea       ecx, [ebp - 0x20]
004821d1  898e88000000             mov       dword ptr [esi + 0x88], ecx
004821d7  56                       push      esi
004821d8  e813040200               call      0x4a25f0 ; _jwe_isfm
004821dd  db6db0                   fld       xword ptr [ebp - 0x50]
004821e0  83c404                   add       esp, 4
004821e3  83c3ff                   add       ebx, -1
004821e6  8b85d4fdffff             mov       eax, dword ptr [ebp - 0x22c]
004821ec  0569ffffff               add       eax, 0xffffff69
004821f1  83add8fdffff01           sub       dword ptr [ebp - 0x228], 1
004821f8  8985d4fdffff             mov       dword ptr [ebp - 0x22c], eax
004821fe  0f856ff9ffff             jne       0x481b73
00482204  dbbd44ffffff             fstp      xword ptr [ebp - 0xbc]
0048220a  e978070000               jmp       0x482987
0048220f  8d056aa55a00             lea       eax, [0x5aa56a] ; bits=00000000, f32=0.0
00482215  c60046                   mov       byte ptr [eax], 0x46
00482218  c640014f                 mov       byte ptr [eax + 1], 0x4f
0048221c  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00482222  d83df477b400             fdivr     dword ptr [0xb477f4]
00482228  d91df4a45a00             fstp      dword ptr [0x5aa4f4] ; bits=00000000, f32=0.0
0048222e  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00482234  d81d98a45a00             fcomp     dword ptr [0x5aa498] ; bits=00000000, f32=0.0
0048223a  dfe0                     fnstsw    ax
0048223c  9e                       sahf
0048223d  0f8a2e000000             jp        0x482271
00482243  732c                     jae       0x482271
00482245  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
0048224b  dbad38ffffff             fld       xword ptr [ebp - 0xc8]
00482251  dee9                     fsubp     st(1)
00482253  dbad5cffffff             fld       xword ptr [ebp - 0xa4]
00482259  dec9                     fmulp     st(1)
0048225b  dbad50ffffff             fld       xword ptr [ebp - 0xb0]
00482261  def9                     fdivp     st(1)
00482263  d805ec8f5a00             fadd      dword ptr [0x5a8fec] ; bits=0000803f, f32=1.0
00482269  d91d0478b400             fstp      dword ptr [0xb47804]
0048226f  eb63                     jmp       0x4822d4
00482271  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00482277  d904852ca85a00           fld       dword ptr [eax*4 + 0x5aa82c]
0048227e  d81de08f5a00             fcomp     dword ptr [0x5a8fe0] ; bits=00000000, f32=0.0
00482284  dfe0                     fnstsw    ax
00482286  9e                       sahf
00482287  0f8a21000000             jp        0x4822ae
0048228d  771f                     ja        0x4822ae
0048228f  6848a45a00               push      0x5aa448
00482294  6884a45a00               push      0x5aa484
00482299  68f4a45a00               push      0x5aa4f4
0048229e  e84dcaffff               call      0x47ecf0 ; _findcc_
004822a3  d91d0478b400             fstp      dword ptr [0xb47804]
004822a9  83c40c                   add       esp, 0xc
004822ac  eb26                     jmp       0x4822d4
004822ae  6848a45a00               push      0x5aa448
004822b3  6884a45a00               push      0x5aa484
004822b8  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
004822be  8d0c852ca85a00           lea       ecx, [eax*4 + 0x5aa82c]
004822c5  51                       push      ecx
004822c6  e825caffff               call      0x47ecf0 ; _findcc_
004822cb  d91d0478b400             fstp      dword ptr [0xb47804]
004822d1  83c40c                   add       esp, 0xc
004822d4  8b050478b400             mov       eax, dword ptr [0xb47804]
004822da  8d0d84975a00             lea       ecx, [0x5a9784] ; bits=09020000, f32=7.300764999132297e-43
004822e0  8945f8                   mov       dword ptr [ebp - 8], eax
004822e3  8d45f8                   lea       eax, [ebp - 8]
004822e6  894128                   mov       dword ptr [ecx + 0x28], eax
004822e9  51                       push      ecx
004822ea  e861f80100               call      0x4a1b50 ; _jwe_iinf
004822ef  83c404                   add       esp, 4
004822f2  d9050078b400             fld       dword ptr [0xb47800]
004822f8  d80d0478b400             fmul      dword ptr [0xb47804]
004822fe  d80df877b400             fmul      dword ptr [0xb477f8]
00482304  d91dcc77b400             fstp      dword ptr [0xb477cc]
0048230a  d905f477b400             fld       dword ptr [0xb477f4]
00482310  d80d0478b400             fmul      dword ptr [0xb47804]
00482316  d91d8c77b400             fstp      dword ptr [0xb4778c]
0048231c  d9058877b400             fld       dword ptr [0xb47788]
00482322  d805b077b400             fadd      dword ptr [0xb477b0]
00482328  d905b477b400             fld       dword ptr [0xb477b4]
0048232e  d9c9                     fxch      st(1)
00482330  d825b477b400             fsub      dword ptr [0xb477b4]
00482336  d9058c77b400             fld       dword ptr [0xb4778c]
0048233c  d9c9                     fxch      st(1)
0048233e  d8258c77b400             fsub      dword ptr [0xb4778c]
00482344  d80d0c78b400             fmul      dword ptr [0xb4780c]
0048234a  d905cc77b400             fld       dword ptr [0xb477cc]
00482350  d9059c77b400             fld       dword ptr [0xb4779c]
00482356  d83dcc77b400             fdivr     dword ptr [0xb477cc]
0048235c  d8c8                     fmul      st(0)
0048235e  d80dec77b400             fmul      dword ptr [0xb477ec]
00482364  d82dec8f5a00             fsubr     dword ptr [0x5a8fec] ; bits=0000803f, f32=1.0
0048236a  defa                     fdivp     st(2)
0048236c  d9c9                     fxch      st(1)
0048236e  d9fa                     fsqrt
00482370  d95df8                   fstp      dword ptr [ebp - 8]
00482373  d84df8                   fmul      dword ptr [ebp - 8]
00482376  d91deca45a00             fstp      dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
0048237c  dbbdc0feffff             fstp      xword ptr [ebp - 0x140]
00482382  dbadc0feffff             fld       xword ptr [ebp - 0x140]
00482388  dec1                     faddp     st(1)
0048238a  d825b877b400             fsub      dword ptr [0xb477b8]
00482390  d91d9077b400             fstp      dword ptr [0xb47790]
00482396  682078b400               push      0xb47820
0048239b  689077b400               push      0xb47790
004823a0  688477b400               push      0xb47784
004823a5  e8b65effff               call      0x478260 ; _lktj_
004823aa  83c40c                   add       esp, 0xc
004823ad  d905eca45a00             fld       dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
004823b3  d80deca45a00             fmul      dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
004823b9  d91d1878b400             fstp      dword ptr [0xb47818]
004823bf  dbadc0feffff             fld       xword ptr [ebp - 0x140]
004823c5  d805b477b400             fadd      dword ptr [0xb477b4]
004823cb  d825bc77b400             fsub      dword ptr [0xb477bc]
004823d1  d91d14a55a00             fstp      dword ptr [0x5aa514] ; bits=00000000, f32=0.0
004823d7  d9058877b400             fld       dword ptr [0xb47788]
004823dd  d805b077b400             fadd      dword ptr [0xb477b0]
004823e3  d825bc77b400             fsub      dword ptr [0xb477bc]
004823e9  d91d18a55a00             fstp      dword ptr [0x5aa518] ; bits=00000000, f32=0.0
004823ef  6850a45a00               push      0x5aa450
004823f4  6808a55a00               push      0x5aa508
004823f9  6818a55a00               push      0x5aa518
004823fe  6814a55a00               push      0x5aa514
00482403  68c0ea4700               push      0x47eac0 ; _rsomy4_
00482408  6868f70e04               push      0x40ef768
0048240d  686cf70e04               push      0x40ef76c
00482412  e8d9fefeff               call      0x4722f0 ; _regfal_
00482417  83c41c                   add       esp, 0x1c
0048241a  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00482421  7438                     je        0x48245b
00482423  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00482429  8b08                     mov       ecx, dword ptr [eax]
0048242b  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00482431  8d1d4c975a00             lea       ebx, [0x5a974c] ; bits=09020000, f32=7.300764999132297e-43
00482437  894dfc                   mov       dword ptr [ebp - 4], ecx
0048243a  8d4dfc                   lea       ecx, [ebp - 4]
0048243d  894b08                   mov       dword ptr [ebx + 8], ecx
00482440  8955ec                   mov       dword ptr [ebp - 0x14], edx
00482443  8d4dec                   lea       ecx, [ebp - 0x14]
00482446  894b28                   mov       dword ptr [ebx + 0x28], ecx
00482449  53                       push      ebx
0048244a  e8a1010200               call      0x4a25f0 ; _jwe_isfm
0048244f  83c404                   add       esp, 4
00482452  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00482455  c70001000000             mov       dword ptr [eax], 1
0048245b  d905bc77b400             fld       dword ptr [0xb477bc]
00482461  d80508a55a00             fadd      dword ptr [0x5aa508] ; bits=00000000, f32=0.0
00482467  d9c0                     fld       st(0)
00482469  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
0048246f  d9059c77b400             fld       dword ptr [0xb4779c]
00482475  d83deca45a00             fdivr     dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
0048247b  d8c8                     fmul      st(0)
0048247d  d80dec77b400             fmul      dword ptr [0xb477ec]
00482483  d8350c78b400             fdiv      dword ptr [0xb4780c]
00482489  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
0048248f  dec1                     faddp     st(1)
00482491  d905a077b400             fld       dword ptr [0xb477a0]
00482497  d83deca45a00             fdivr     dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
0048249d  d8c8                     fmul      st(0)
0048249f  d80d2478b400             fmul      dword ptr [0xb47824]
004824a5  d8350c78b400             fdiv      dword ptr [0xb4780c]
004824ab  d8c2                     fadd      st(2)
004824ad  dee9                     fsubp     st(1)
004824af  d815e08f5a00             fcom      dword ptr [0x5a8fe0] ; bits=00000000, f32=0.0
004824b5  d9ca                     fxch      st(2)
004824b7  dbbdb4feffff             fstp      xword ptr [ebp - 0x14c]
004824bd  dfe0                     fnstsw    ax
004824bf  9e                       sahf
004824c0  0f8a0d000000             jp        0x4824d3
004824c6  730b                     jae       0x4824d3
004824c8  b801000000               mov       eax, 1
004824cd  89850cfeffff             mov       dword ptr [ebp - 0x1f4], eax
004824d3  db7dc8                   fstp      xword ptr [ebp - 0x38]
004824d6  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
004824dc  8b8d48feffff             mov       ecx, dword ptr [ebp - 0x1b8]
004824e2  db7dd4                   fstp      xword ptr [ebp - 0x2c]
004824e5  8d1401                   lea       edx, [ecx + eax]
004824e8  8b1deca45a00             mov       ebx, dword ptr [0x5aa4ec] ; bits=00000000, f32=0.0
004824ee  891c9500fc9400           mov       dword ptr [edx*4 + 0x94fc00], ebx
004824f5  d9058877b400             fld       dword ptr [0xb47788]
004824fb  d805b077b400             fadd      dword ptr [0xb477b0]
00482501  dbadb4feffff             fld       xword ptr [ebp - 0x14c]
00482507  dee9                     fsubp     st(1)
00482509  dbbde4feffff             fstp      xword ptr [ebp - 0x11c]
0048250f  dbade4feffff             fld       xword ptr [ebp - 0x11c]
00482515  d91c85acee9400           fstp      dword ptr [eax*4 + 0x94eeac]
0048251c  68eca45a00               push      0x5aa4ec
00482521  6a0a                     push      0xa
00482523  6840a75a00               push      0x5aa740
00482528  e823a9feff               call      0x46ce50 ; _put10_
0048252d  83c40c                   add       esp, 0xc
00482530  8d0540a65a00             lea       eax, [0x5aa640] ; bits=00000000, f32=0.0
00482536  8d0d40a75a00             lea       ecx, [0x5aa740] ; bits=00000000, f32=0.0
0048253c  8a11                     mov       dl, byte ptr [ecx]
0048253e  8810                     mov       byte ptr [eax], dl
00482540  8a5101                   mov       dl, byte ptr [ecx + 1]
00482543  885001                   mov       byte ptr [eax + 1], dl
00482546  8a5102                   mov       dl, byte ptr [ecx + 2]
00482549  885002                   mov       byte ptr [eax + 2], dl
0048254c  8a5103                   mov       dl, byte ptr [ecx + 3]
0048254f  885003                   mov       byte ptr [eax + 3], dl
00482552  8a5104                   mov       dl, byte ptr [ecx + 4]
00482555  885004                   mov       byte ptr [eax + 4], dl
00482558  8a5105                   mov       dl, byte ptr [ecx + 5]
0048255b  885005                   mov       byte ptr [eax + 5], dl
0048255e  8a5106                   mov       dl, byte ptr [ecx + 6]
00482561  885006                   mov       byte ptr [eax + 6], dl
00482564  8a5107                   mov       dl, byte ptr [ecx + 7]
00482567  885007                   mov       byte ptr [eax + 7], dl
0048256a  8a5108                   mov       dl, byte ptr [ecx + 8]
0048256d  885008                   mov       byte ptr [eax + 8], dl
00482570  8a5109                   mov       dl, byte ptr [ecx + 9]
00482573  885009                   mov       byte ptr [eax + 9], dl
00482576  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0048257c  8b08                     mov       ecx, dword ptr [eax]
0048257e  d9059077b400             fld       dword ptr [0xb47790]
00482584  d805b877b400             fadd      dword ptr [0xb477b8]
0048258a  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
00482590  8d15cc965a00             lea       edx, [0x5a96cc] ; bits=09020000, f32=7.300764999132297e-43
00482596  894dfc                   mov       dword ptr [ebp - 4], ecx
00482599  8d4dfc                   lea       ecx, [ebp - 4]
0048259c  894a08                   mov       dword ptr [edx + 8], ecx
0048259f  dbade4feffff             fld       xword ptr [ebp - 0x11c]
004825a5  d95df8                   fstp      dword ptr [ebp - 8]
004825a8  8d4df8                   lea       ecx, [ebp - 8]
004825ab  894a34                   mov       dword ptr [edx + 0x34], ecx
004825ae  d95df4                   fstp      dword ptr [ebp - 0xc]
004825b1  8d4df4                   lea       ecx, [ebp - 0xc]
004825b4  894a40                   mov       dword ptr [edx + 0x40], ecx
004825b7  db6dc8                   fld       xword ptr [ebp - 0x38]
004825ba  d95df0                   fstp      dword ptr [ebp - 0x10]
004825bd  8d4df0                   lea       ecx, [ebp - 0x10]
004825c0  894a4c                   mov       dword ptr [edx + 0x4c], ecx
004825c3  db6dd4                   fld       xword ptr [ebp - 0x2c]
004825c6  d95de8                   fstp      dword ptr [ebp - 0x18]
004825c9  8d4de8                   lea       ecx, [ebp - 0x18]
004825cc  894a7c                   mov       dword ptr [edx + 0x7c], ecx
004825cf  52                       push      edx
004825d0  e81b000200               call      0x4a25f0 ; _jwe_isfm
004825d5  83c404                   add       esp, 4
004825d8  8d056aa55a00             lea       eax, [0x5aa56a] ; bits=00000000, f32=0.0
004825de  c60053                   mov       byte ptr [eax], 0x53
004825e1  c640014f                 mov       byte ptr [eax + 1], 0x4f
004825e5  d9050078b400             fld       dword ptr [0xb47800]
004825eb  d80d0478b400             fmul      dword ptr [0xb47804]
004825f1  d80df877b400             fmul      dword ptr [0xb477f8]
004825f7  d91dcc77b400             fstp      dword ptr [0xb477cc]
004825fd  8b8538feffff             mov       eax, dword ptr [ebp - 0x1c8]
00482603  8985acfdffff             mov       dword ptr [ebp - 0x254], eax
00482609  3d00000000               cmp       eax, 0
0048260e  0f8e73030000             jle       0x482987
00482614  8b8534feffff             mov       eax, dword ptr [ebp - 0x1cc]
0048261a  89c3                     mov       ebx, eax
0048261c  8b9530feffff             mov       edx, dword ptr [ebp - 0x1d0]
00482622  8b8de0fdffff             mov       ecx, dword ptr [ebp - 0x220]
00482628  8d340a                   lea       esi, [edx + ecx]
0048262b  89b5a8fdffff             mov       dword ptr [ebp - 0x258], esi
00482631  dbade4feffff             fld       xword ptr [ebp - 0x11c]
00482637  d80c9de0f89400           fmul      dword ptr [ebx*4 + 0x94f8e0]
0048263e  db7dc8                   fstp      xword ptr [ebp - 0x38]
00482641  d9058877b400             fld       dword ptr [0xb47788]
00482647  d805b077b400             fadd      dword ptr [0xb477b0]
0048264d  db6dc8                   fld       xword ptr [ebp - 0x38]
00482650  dee9                     fsubp     st(1)
00482652  d905bc77b400             fld       dword ptr [0xb477bc]
00482658  d9c1                     fld       st(1)
0048265a  d825bc77b400             fsub      dword ptr [0xb477bc]
00482660  d91d9477b400             fstp      dword ptr [0xb47794]
00482666  d9c9                     fxch      st(1)
00482668  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
0048266e  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00482671  d905f477b400             fld       dword ptr [0xb477f4]
00482677  d80d0478b400             fmul      dword ptr [0xb47804]
0048267d  d805b477b400             fadd      dword ptr [0xb477b4]
00482683  dee1                     fsubrp    st(1)
00482685  d91d14a55a00             fstp      dword ptr [0x5aa514] ; bits=00000000, f32=0.0
0048268b  8b059477b400             mov       eax, dword ptr [0xb47794]
00482691  890518a55a00             mov       dword ptr [0x5aa518], eax ; bits=00000000, f32=0.0
00482697  68e477b400               push      0xb477e4
0048269c  681078b400               push      0xb47810
004826a1  682478b400               push      0xb47824
004826a6  6888a45a00               push      0x5aa488
004826ab  68f077b400               push      0xb477f0
004826b0  68d877b400               push      0xb477d8
004826b5  68d477b400               push      0xb477d4
004826ba  68ac77b400               push      0xb477ac
004826bf  688ca45a00               push      0x5aa48c
004826c4  68fca45a00               push      0x5aa4fc
004826c9  68a077b400               push      0xb477a0
004826ce  689477b400               push      0xb47794
004826d3  688477b400               push      0xb47784
004826d8  e8f36afcff               call      0x4491d0 ; _xlkt22_
004826dd  83c434                   add       esp, 0x34
004826e0  6850a45a00               push      0x5aa450
004826e5  6814a55a00               push      0x5aa514
004826ea  6868f70e04               push      0x40ef768
004826ef  6800ea4700               push      0x47ea00 ; _rsomy3_
004826f4  6818a55a00               push      0x5aa518
004826f9  e822f7feff               call      0x471e20 ; _fdroot_
004826fe  db6dd4                   fld       xword ptr [ebp - 0x2c]
00482701  db6dc8                   fld       xword ptr [ebp - 0x38]
00482704  83c414                   add       esp, 0x14
00482707  833d50a45a0001           cmp       dword ptr [0x5aa450], 1 ; bits=00000000, f32=0.0
0048270e  7535                     jne       0x482745
00482710  db7dc8                   fstp      xword ptr [ebp - 0x38]
00482713  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00482719  db7dd4                   fstp      xword ptr [ebp - 0x2c]
0048271c  8b08                     mov       ecx, dword ptr [eax]
0048271e  8d15a0965a00             lea       edx, [0x5a96a0] ; bits=09020000, f32=7.300764999132297e-43
00482724  894dfc                   mov       dword ptr [ebp - 4], ecx
00482727  8d4dfc                   lea       ecx, [ebp - 4]
0048272a  894a08                   mov       dword ptr [edx + 8], ecx
0048272d  52                       push      edx
0048272e  e8bdfe0100               call      0x4a25f0 ; _jwe_isfm
00482733  db6dd4                   fld       xword ptr [ebp - 0x2c]
00482736  db6dc8                   fld       xword ptr [ebp - 0x38]
00482739  83c404                   add       esp, 4
0048273c  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0048273f  c70001000000             mov       dword ptr [eax], 1
00482745  db7dc8                   fstp      xword ptr [ebp - 0x38]
00482748  db7dd4                   fstp      xword ptr [ebp - 0x2c]
0048274b  6850a45a00               push      0x5aa450
00482750  689077b400               push      0xb47790
00482755  6818a55a00               push      0x5aa518
0048275a  6814a55a00               push      0x5aa514
0048275f  6800ea4700               push      0x47ea00 ; _rsomy3_
00482764  6868f70e04               push      0x40ef768
00482769  686cf70e04               push      0x40ef76c
0048276e  e87dfbfeff               call      0x4722f0 ; _regfal_
00482773  db6dd4                   fld       xword ptr [ebp - 0x2c]
00482776  db6dc8                   fld       xword ptr [ebp - 0x38]
00482779  83c41c                   add       esp, 0x1c
0048277c  833d50a45a0000           cmp       dword ptr [0x5aa450], 0 ; bits=00000000, f32=0.0
00482783  7444                     je        0x4827c9
00482785  db7dc8                   fstp      xword ptr [ebp - 0x38]
00482788  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
0048278e  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00482791  8b08                     mov       ecx, dword ptr [eax]
00482793  8b1550a45a00             mov       edx, dword ptr [0x5aa450] ; bits=00000000, f32=0.0
00482799  8d3568965a00             lea       esi, [0x5a9668] ; bits=09020000, f32=7.300764999132297e-43
0048279f  894dfc                   mov       dword ptr [ebp - 4], ecx
004827a2  8d4dfc                   lea       ecx, [ebp - 4]
004827a5  894e08                   mov       dword ptr [esi + 8], ecx
004827a8  8955ec                   mov       dword ptr [ebp - 0x14], edx
004827ab  8d4dec                   lea       ecx, [ebp - 0x14]
004827ae  894e28                   mov       dword ptr [esi + 0x28], ecx
004827b1  56                       push      esi
004827b2  e839fe0100               call      0x4a25f0 ; _jwe_isfm
004827b7  db6dd4                   fld       xword ptr [ebp - 0x2c]
004827ba  db6dc8                   fld       xword ptr [ebp - 0x38]
004827bd  83c404                   add       esp, 4
004827c0  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004827c3  c70001000000             mov       dword ptr [eax], 1
004827c9  d9051878b400             fld       dword ptr [0xb47818]
004827cf  d9fa                     fsqrt
004827d1  d91de4a45a00             fstp      dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
004827d7  8b8da8fdffff             mov       ecx, dword ptr [ebp - 0x258]
004827dd  8b05e4a45a00             mov       eax, dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
004827e3  89048d00fc9400           mov       dword ptr [ecx*4 + 0x94fc00], eax
004827ea  d9059077b400             fld       dword ptr [0xb47790]
004827f0  d805b877b400             fadd      dword ptr [0xb477b8]
004827f6  d825b0a45a00             fsub      dword ptr [0x5aa4b0] ; bits=00000000, f32=0.0
004827fc  d905e4a45a00             fld       dword ptr [0x5aa4e4] ; bits=00000000, f32=0.0
00482802  d9c0                     fld       st(0)
00482804  d8348d5cfe9400           fdiv      dword ptr [ecx*4 + 0x94fe5c]
0048280b  d9ed                     fldln2
0048280d  d9c0                     fld       st(0)
0048280f  d9c9                     fxch      st(1)
00482811  d9ca                     fxch      st(2)
00482813  d9f1                     fyl2x
00482815  d95df8                   fstp      dword ptr [ebp - 8]
00482818  d945f8                   fld       dword ptr [ebp - 8]
0048281b  d9049de4f89400           fld       dword ptr [ebx*4 + 0x94f8e4]
00482822  d83c9de0f89400           fdivr     dword ptr [ebx*4 + 0x94f8e0]
00482829  d9ca                     fxch      st(2)
0048282b  d9c9                     fxch      st(1)
0048282d  d9ca                     fxch      st(2)
0048282f  d9f1                     fyl2x
00482831  d95df8                   fstp      dword ptr [ebp - 8]
00482834  d875f8                   fdiv      dword ptr [ebp - 8]
00482837  dbbda8feffff             fstp      xword ptr [ebp - 0x158]
0048283d  d9c0                     fld       st(0)
0048283f  d8359c77b400             fdiv      dword ptr [0xb4779c]
00482845  d8c8                     fmul      st(0)
00482847  d80dec77b400             fmul      dword ptr [0xb477ec]
0048284d  d8350c78b400             fdiv      dword ptr [0xb4780c]
00482853  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00482859  dec1                     faddp     st(1)
0048285b  d9c9                     fxch      st(1)
0048285d  d835a077b400             fdiv      dword ptr [0xb477a0]
00482863  d8c8                     fmul      st(0)
00482865  d80d2478b400             fmul      dword ptr [0xb47824]
0048286b  d8350c78b400             fdiv      dword ptr [0xb4780c]
00482871  d8c4                     fadd      st(4)
00482873  dee9                     fsubp     st(1)
00482875  d815e08f5a00             fcom      dword ptr [0x5a8fe0] ; bits=00000000, f32=0.0
0048287b  d9ca                     fxch      st(2)
0048287d  d9c9                     fxch      st(1)
0048287f  dfe0                     fnstsw    ax
00482881  9e                       sahf
00482882  0f8a0d000000             jp        0x482895
00482888  730b                     jae       0x482895
0048288a  b801000000               mov       eax, 1
0048288f  89850cfeffff             mov       dword ptr [ebp - 0x1f4], eax
00482895  db7db0                   fstp      xword ptr [ebp - 0x50]
00482898  db7dbc                   fstp      xword ptr [ebp - 0x44]
0048289b  db7dc8                   fstp      xword ptr [ebp - 0x38]
0048289e  db7dd4                   fstp      xword ptr [ebp - 0x2c]
004828a1  68e4a45a00               push      0x5aa4e4
004828a6  6a0a                     push      0xa
004828a8  6850a75a00               push      0x5aa750
004828ad  e89ea5feff               call      0x46ce50 ; _put10_
004828b2  83c40c                   add       esp, 0xc
004828b5  8d0540a65a00             lea       eax, [0x5aa640] ; bits=00000000, f32=0.0
004828bb  8d0d50a75a00             lea       ecx, [0x5aa750] ; bits=00000000, f32=0.0
004828c1  8a11                     mov       dl, byte ptr [ecx]
004828c3  8810                     mov       byte ptr [eax], dl
004828c5  8a5101                   mov       dl, byte ptr [ecx + 1]
004828c8  885001                   mov       byte ptr [eax + 1], dl
004828cb  8a5102                   mov       dl, byte ptr [ecx + 2]
004828ce  885002                   mov       byte ptr [eax + 2], dl
004828d1  8a5103                   mov       dl, byte ptr [ecx + 3]
004828d4  885003                   mov       byte ptr [eax + 3], dl
004828d7  8a5104                   mov       dl, byte ptr [ecx + 4]
004828da  885004                   mov       byte ptr [eax + 4], dl
004828dd  8a5105                   mov       dl, byte ptr [ecx + 5]
004828e0  885005                   mov       byte ptr [eax + 5], dl
004828e3  8a5106                   mov       dl, byte ptr [ecx + 6]
004828e6  885006                   mov       byte ptr [eax + 6], dl
004828e9  8a5107                   mov       dl, byte ptr [ecx + 7]
004828ec  885007                   mov       byte ptr [eax + 7], dl
004828ef  8a5108                   mov       dl, byte ptr [ecx + 8]
004828f2  885008                   mov       byte ptr [eax + 8], dl
004828f5  8a5109                   mov       dl, byte ptr [ecx + 9]
004828f8  885009                   mov       byte ptr [eax + 9], dl
004828fb  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00482901  8b08                     mov       ecx, dword ptr [eax]
00482903  8b149de0f89400           mov       edx, dword ptr [ebx*4 + 0x94f8e0]
0048290a  8d35dc955a00             lea       esi, [0x5a95dc] ; bits=09020000, f32=7.300764999132297e-43
00482910  894dfc                   mov       dword ptr [ebp - 4], ecx
00482913  8d4dfc                   lea       ecx, [ebp - 4]
00482916  894e08                   mov       dword ptr [esi + 8], ecx
00482919  8955f8                   mov       dword ptr [ebp - 8], edx
0048291c  8d4df8                   lea       ecx, [ebp - 8]
0048291f  894e28                   mov       dword ptr [esi + 0x28], ecx
00482922  db6dbc                   fld       xword ptr [ebp - 0x44]
00482925  d95df4                   fstp      dword ptr [ebp - 0xc]
00482928  8d4df4                   lea       ecx, [ebp - 0xc]
0048292b  894e34                   mov       dword ptr [esi + 0x34], ecx
0048292e  db6db0                   fld       xword ptr [ebp - 0x50]
00482931  d95df0                   fstp      dword ptr [ebp - 0x10]
00482934  8d4df0                   lea       ecx, [ebp - 0x10]
00482937  894e40                   mov       dword ptr [esi + 0x40], ecx
0048293a  db6dd4                   fld       xword ptr [ebp - 0x2c]
0048293d  d95de8                   fstp      dword ptr [ebp - 0x18]
00482940  8d4de8                   lea       ecx, [ebp - 0x18]
00482943  894e4c                   mov       dword ptr [esi + 0x4c], ecx
00482946  dbada8feffff             fld       xword ptr [ebp - 0x158]
0048294c  d95de4                   fstp      dword ptr [ebp - 0x1c]
0048294f  8d4de4                   lea       ecx, [ebp - 0x1c]
00482952  894e7c                   mov       dword ptr [esi + 0x7c], ecx
00482955  db6dc8                   fld       xword ptr [ebp - 0x38]
00482958  d95de0                   fstp      dword ptr [ebp - 0x20]
0048295b  8d4de0                   lea       ecx, [ebp - 0x20]
0048295e  898e88000000             mov       dword ptr [esi + 0x88], ecx
00482964  56                       push      esi
00482965  e886fc0100               call      0x4a25f0 ; _jwe_isfm
0048296a  83c404                   add       esp, 4
0048296d  83c3ff                   add       ebx, -1
00482970  8185a8fdffff69ffffff     add       dword ptr [ebp - 0x258], 0xffffff69
0048297a  83adacfdffff01           sub       dword ptr [ebp - 0x254], 1
00482981  0f85aafcffff             jne       0x482631
00482987  8b8524feffff             mov       eax, dword ptr [ebp - 0x1dc]
0048298d  8985d0fdffff             mov       dword ptr [ebp - 0x230], eax
00482993  83bd2cfeffff00           cmp       dword ptr [ebp - 0x1d4], 0
0048299a  0f8e16020000             jle       0x482bb6
004829a0  bb03000000               mov       ebx, 3
004829a5  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
004829ab  8d88c5010000             lea       ecx, [eax + 0x1c5]
004829b1  83bdd0fdffff02           cmp       dword ptr [ebp - 0x230], 2
004829b8  898dccfdffff             mov       dword ptr [ebp - 0x234], ecx
004829be  0f8c69010000             jl        0x482b2d
004829c4  d905b4a45a00             fld       dword ptr [0x5aa4b4] ; bits=00000000, f32=0.0
004829ca  8b0558a45a00             mov       eax, dword ptr [0x5aa458] ; bits=00000000, f32=0.0
004829d0  8b0d54a45a00             mov       ecx, dword ptr [0x5aa454] ; bits=00000000, f32=0.0
004829d6  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
004829dc  dbbd9cfeffff             fstp      xword ptr [ebp - 0x164]
004829e2  8b9544feffff             mov       edx, dword ptr [ebp - 0x1bc]
004829e8  8995c8fdffff             mov       dword ptr [ebp - 0x238], edx
004829ee  db6d8c                   fld       xword ptr [ebp - 0x74]
004829f1  db6d98                   fld       xword ptr [ebp - 0x68]
004829f4  d9c9                     fxch      st(1)
004829f6  d9ca                     fxch      st(2)
004829f8  8985c4fdffff             mov       dword ptr [ebp - 0x23c], eax
004829fe  898dc0fdffff             mov       dword ptr [ebp - 0x240], ecx
00482a04  8b85ccfdffff             mov       eax, dword ptr [ebp - 0x234]
00482a0a  d904855cfe9400           fld       dword ptr [eax*4 + 0x94fe5c]
00482a11  d9c0                     fld       st(0)
00482a13  d80485a4f99400           fadd      dword ptr [eax*4 + 0x94f9a4]
00482a1a  d80df88f5a00             fmul      dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
00482a20  d8248500fc9400           fsub      dword ptr [eax*4 + 0x94fc00]
00482a27  d9e1                     fabs
00482a29  d8348500fc9400           fdiv      dword ptr [eax*4 + 0x94fc00]
00482a30  d9c0                     fld       st(0)
00482a32  d8c8                     fmul      st(0)
00482a34  dec4                     faddp     st(4)
00482a36  ff8550feffff             inc       dword ptr [ebp - 0x1b0]
00482a3c  d8d4                     fcom      st(4)
00482a3e  d9c9                     fxch      st(1)
00482a40  dbbd90feffff             fstp      xword ptr [ebp - 0x170]
00482a46  d9c9                     fxch      st(1)
00482a48  dfe0                     fnstsw    ax
00482a4a  9e                       sahf
00482a4b  0f8a22000000             jp        0x482a73
00482a51  7620                     jbe       0x482a73
00482a53  ddd8                     fstp      st(0)
00482a55  ddda                     fstp      st(2)
00482a57  dbad9cfeffff             fld       xword ptr [ebp - 0x164]
00482a5d  89d8                     mov       eax, ebx
00482a5f  8b8dc8fdffff             mov       ecx, dword ptr [ebp - 0x238]
00482a65  898dc0fdffff             mov       dword ptr [ebp - 0x240], ecx
00482a6b  8985c4fdffff             mov       dword ptr [ebp - 0x23c], eax
00482a71  eb02                     jmp       0x482a75
00482a73  ddd9                     fstp      st(1)
00482a75  83c302                   add       ebx, 2
00482a78  8b85ccfdffff             mov       eax, dword ptr [ebp - 0x234]
00482a7e  dbad90feffff             fld       xword ptr [ebp - 0x170]
00482a84  d8048514039500           fadd      dword ptr [eax*4 + 0x950314]
00482a8b  d80df88f5a00             fmul      dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
00482a91  d82485b8009500           fsub      dword ptr [eax*4 + 0x9500b8]
00482a98  d9e1                     fabs
00482a9a  d83485b8009500           fdiv      dword ptr [eax*4 + 0x9500b8]
00482aa1  d9c0                     fld       st(0)
00482aa3  d8c8                     fmul      st(0)
00482aa5  dec3                     faddp     st(3)
00482aa7  ff8550feffff             inc       dword ptr [ebp - 0x1b0]
00482aad  d8d3                     fcom      st(3)
00482aaf  d9c9                     fxch      st(1)
00482ab1  dfe0                     fnstsw    ax
00482ab3  9e                       sahf
00482ab4  0f8a22000000             jp        0x482adc
00482aba  7620                     jbe       0x482adc
00482abc  ddd8                     fstp      st(0)
00482abe  ddda                     fstp      st(2)
00482ac0  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00482ac6  89d8                     mov       eax, ebx
00482ac8  8b8d44feffff             mov       ecx, dword ptr [ebp - 0x1bc]
00482ace  898dc0fdffff             mov       dword ptr [ebp - 0x240], ecx
00482ad4  8985c4fdffff             mov       dword ptr [ebp - 0x23c], eax
00482ada  eb02                     jmp       0x482ade
00482adc  ddd9                     fstp      st(1)
00482ade  83c302                   add       ebx, 2
00482ae1  8185ccfdffff5c020000     add       dword ptr [ebp - 0x234], 0x25c
00482aeb  8b85d0fdffff             mov       eax, dword ptr [ebp - 0x230]
00482af1  83e802                   sub       eax, 2
00482af4  3d02000000               cmp       eax, 2
00482af9  8985d0fdffff             mov       dword ptr [ebp - 0x230], eax
00482aff  0f8dfffeffff             jge       0x482a04
00482b05  d9c9                     fxch      st(1)
00482b07  db7d98                   fstp      xword ptr [ebp - 0x68]
00482b0a  d9c9                     fxch      st(1)
00482b0c  db7d8c                   fstp      xword ptr [ebp - 0x74]
00482b0f  d91db4a45a00             fstp      dword ptr [0x5aa4b4] ; bits=00000000, f32=0.0
00482b15  8b85c4fdffff             mov       eax, dword ptr [ebp - 0x23c]
00482b1b  890558a45a00             mov       dword ptr [0x5aa458], eax ; bits=00000000, f32=0.0
00482b21  8b85c0fdffff             mov       eax, dword ptr [ebp - 0x240]
00482b27  890554a45a00             mov       dword ptr [0x5aa454], eax ; bits=00000000, f32=0.0
00482b2d  8b85d0fdffff             mov       eax, dword ptr [ebp - 0x230]
00482b33  85c0                     test      eax, eax
00482b35  747f                     je        0x482bb6
00482b37  db6d98                   fld       xword ptr [ebp - 0x68]
00482b3a  8b85ccfdffff             mov       eax, dword ptr [ebp - 0x234]
00482b40  d904855cfe9400           fld       dword ptr [eax*4 + 0x94fe5c]
00482b47  d80485a4f99400           fadd      dword ptr [eax*4 + 0x94f9a4]
00482b4e  d80df88f5a00             fmul      dword ptr [0x5a8ff8] ; bits=0000003f, f32=0.5
00482b54  d8248500fc9400           fsub      dword ptr [eax*4 + 0x94fc00]
00482b5b  d9e1                     fabs
00482b5d  d8348500fc9400           fdiv      dword ptr [eax*4 + 0x94fc00]
00482b64  d9c0                     fld       st(0)
00482b66  d8c8                     fmul      st(0)
00482b68  dec2                     faddp     st(2)
00482b6a  ff8550feffff             inc       dword ptr [ebp - 0x1b0]
00482b70  db6d8c                   fld       xword ptr [ebp - 0x74]
00482b73  d9c9                     fxch      st(1)
00482b75  d8d1                     fcom      st(1)
00482b77  ddd9                     fstp      st(1)
00482b79  d9c9                     fxch      st(1)
00482b7b  db7d98                   fstp      xword ptr [ebp - 0x68]
00482b7e  dbbd84feffff             fstp      xword ptr [ebp - 0x17c]
00482b84  dfe0                     fnstsw    ax
00482b86  9e                       sahf
00482b87  0f8a29000000             jp        0x482bb6
00482b8d  7627                     jbe       0x482bb6
00482b8f  dbad84feffff             fld       xword ptr [ebp - 0x17c]
00482b95  db7d8c                   fstp      xword ptr [ebp - 0x74]
00482b98  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00482b9e  d91db4a45a00             fstp      dword ptr [0x5aa4b4] ; bits=00000000, f32=0.0
00482ba4  891d58a45a00             mov       dword ptr [0x5aa458], ebx ; bits=00000000, f32=0.0
00482baa  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00482bb0  890554a45a00             mov       dword ptr [0x5aa454], eax ; bits=00000000, f32=0.0
00482bb6  c7055ca45a0003000000     mov       dword ptr [0x5aa45c], 3 ; bits=00000000, f32=0.0
00482bc0  8b85e4fdffff             mov       eax, dword ptr [ebp - 0x21c]
00482bc6  8985bcfdffff             mov       dword ptr [ebp - 0x244], eax
00482bcc  83bd20feffff00           cmp       dword ptr [ebp - 0x1e0], 0
00482bd3  0f8ea2000000             jle       0x482c7b
00482bd9  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
00482bdf  8d885c020000             lea       ecx, [eax + 0x25c]
00482be5  8d98c5010000             lea       ebx, [eax + 0x1c5]
00482beb  83bdbcfdffff02           cmp       dword ptr [ebp - 0x244], 2
00482bf2  898db8fdffff             mov       dword ptr [ebp - 0x248], ecx
00482bf8  7c47                     jl        0x482c41
00482bfa  8b85b8fdffff             mov       eax, dword ptr [ebp - 0x248]
00482c00  8b0c8500fc9400           mov       ecx, dword ptr [eax*4 + 0x94fc00]
00482c07  890c9d00fc9400           mov       dword ptr [ebx*4 + 0x94fc00], ecx
00482c0e  8b0c85b8009500           mov       ecx, dword ptr [eax*4 + 0x9500b8]
00482c15  890c9d5cfe9400           mov       dword ptr [ebx*4 + 0x94fe5c], ecx
00482c1c  81c32e010000             add       ebx, 0x12e
00482c22  8b8dbcfdffff             mov       ecx, dword ptr [ebp - 0x244]
00482c28  83e902                   sub       ecx, 2
00482c2b  055c020000               add       eax, 0x25c
00482c30  83f902                   cmp       ecx, 2
00482c33  8985b8fdffff             mov       dword ptr [ebp - 0x248], eax
00482c39  898dbcfdffff             mov       dword ptr [ebp - 0x244], ecx
00482c3f  7db9                     jge       0x482bfa
00482c41  8b85bcfdffff             mov       eax, dword ptr [ebp - 0x244]
00482c47  85c0                     test      eax, eax
00482c49  741a                     je        0x482c65
00482c4b  8b85b8fdffff             mov       eax, dword ptr [ebp - 0x248]
00482c51  8b0c8500fc9400           mov       ecx, dword ptr [eax*4 + 0x94fc00]
00482c58  890c9d00fc9400           mov       dword ptr [ebx*4 + 0x94fc00], ecx
00482c5f  81c397000000             add       ebx, 0x97
00482c65  89d8                     mov       eax, ebx
00482c67  2b85e0fdffff             sub       eax, dword ptr [ebp - 0x220]
00482c6d  b997000000               mov       ecx, 0x97
00482c72  99                       cdq
00482c73  f7f9                     idiv      ecx
00482c75  89055ca45a00             mov       dword ptr [0x5aa45c], eax ; bits=00000000, f32=0.0
00482c7b  8b8d48feffff             mov       ecx, dword ptr [ebp - 0x1b8]
00482c81  8b85e0fdffff             mov       eax, dword ptr [ebp - 0x220]
00482c87  8d1401                   lea       edx, [ecx + eax]
00482c8a  8b355ca45a00             mov       esi, dword ptr [0x5aa45c] ; bits=00000000, f32=0.0
00482c90  8d3cf6                   lea       edi, [esi + esi*8]
00482c93  8d3c7e                   lea       edi, [esi + edi*2]
00482c96  c1e703                   shl       edi, 3
00482c99  29f7                     sub       edi, esi
00482c9b  01c7                     add       edi, eax
00482c9d  89fb                     mov       ebx, edi
00482c9f  8b149500fc9400           mov       edx, dword ptr [edx*4 + 0x94fc00]
00482ca6  89149d00fc9400           mov       dword ptr [ebx*4 + 0x94fc00], edx
00482cad  40                       inc       eax
00482cae  83ade8fdffff01           sub       dword ptr [ebp - 0x218], 1
00482cb5  8985e0fdffff             mov       dword ptr [ebp - 0x220], eax
00482cbb  0f85b0e8ffff             jne       0x481571
00482cc1  8b8514feffff             mov       eax, dword ptr [ebp - 0x1ec]
00482cc7  890568f39400             mov       dword ptr [0x94f368], eax
00482ccd  8b8d1cfeffff             mov       ecx, dword ptr [ebp - 0x1e4]
00482cd3  890d6cf39400             mov       dword ptr [0x94f36c], ecx
00482cd9  c7055ca45a0003000000     mov       dword ptr [0x5aa45c], 3 ; bits=00000000, f32=0.0
00482ce3  8b8528feffff             mov       eax, dword ptr [ebp - 0x1d8]
00482ce9  8985b4fdffff             mov       dword ptr [ebp - 0x24c], eax
00482cef  83bd18feffff00           cmp       dword ptr [ebp - 0x1e8], 0
00482cf6  0f8e8f000000             jle       0x482d8b
00482cfc  bb04000000               mov       ebx, 4
00482d01  83bdb4fdffff02           cmp       dword ptr [ebp - 0x24c], 2
00482d08  7c5c                     jl        0x482d66
00482d0a  8b055ca45a00             mov       eax, dword ptr [0x5aa45c] ; bits=00000000, f32=0.0
00482d10  8985b0fdffff             mov       dword ptr [ebp - 0x250], eax
00482d16  8b8db0fdffff             mov       ecx, dword ptr [ebp - 0x250]
00482d1c  8b049de0f89400           mov       eax, dword ptr [ebx*4 + 0x94f8e0]
00482d23  89048d64f39400           mov       dword ptr [ecx*4 + 0x94f364], eax
00482d2a  8b049de8f89400           mov       eax, dword ptr [ebx*4 + 0x94f8e8]
00482d31  89048d68f39400           mov       dword ptr [ecx*4 + 0x94f368], eax
00482d38  83c102                   add       ecx, 2
00482d3b  8b85b4fdffff             mov       eax, dword ptr [ebp - 0x24c]
00482d41  83e802                   sub       eax, 2
00482d44  83c304                   add       ebx, 4
00482d47  3d02000000               cmp       eax, 2
00482d4c  8985b4fdffff             mov       dword ptr [ebp - 0x24c], eax
00482d52  898db0fdffff             mov       dword ptr [ebp - 0x250], ecx
00482d58  7dbc                     jge       0x482d16
00482d5a  8b85b0fdffff             mov       eax, dword ptr [ebp - 0x250]
00482d60  89055ca45a00             mov       dword ptr [0x5aa45c], eax ; bits=00000000, f32=0.0
00482d66  8b85b4fdffff             mov       eax, dword ptr [ebp - 0x24c]
00482d6c  85c0                     test      eax, eax
00482d6e  741b                     je        0x482d8b
00482d70  8b049de0f89400           mov       eax, dword ptr [ebx*4 + 0x94f8e0]
00482d77  8b0d5ca45a00             mov       ecx, dword ptr [0x5aa45c] ; bits=00000000, f32=0.0
00482d7d  89048d64f39400           mov       dword ptr [ecx*4 + 0x94f364], eax
00482d84  41                       inc       ecx
00482d85  890d5ca45a00             mov       dword ptr [0x5aa45c], ecx ; bits=00000000, f32=0.0
00482d8b  8b055ca45a00             mov       eax, dword ptr [0x5aa45c] ; bits=00000000, f32=0.0
00482d91  8b8d10feffff             mov       ecx, dword ptr [ebp - 0x1f0]
00482d97  890c8564f39400           mov       dword ptr [eax*4 + 0x94f364], ecx
00482d9e  c7052ca55a0000000000     mov       dword ptr [0x5aa52c], 0 ; bits=00000000, f32=0.0
00482da8  6a08                     push      8
00482daa  6a08                     push      8
00482dac  6a08                     push      8
00482dae  6a08                     push      8
00482db0  6a08                     push      8
00482db2  6a08                     push      8
00482db4  6a32                     push      0x32
00482db6  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00482db9  8d00                     lea       eax, [eax]
00482dbb  50                       push      eax
00482dbc  6840a45a00               push      0x5aa440
00482dc1  6838a45a00               push      0x5aa438
00482dc6  68f8a65a00               push      0x5aa6f8
00482dcb  68f0a65a00               push      0x5aa6f0
00482dd0  68e8a65a00               push      0x5aa6e8
00482dd5  68e0a65a00               push      0x5aa6e0
00482dda  68d8a65a00               push      0x5aa6d8
00482ddf  682ca55a00               push      0x5aa52c
00482de4  68a8925a00               push      0x5a92a8
00482de9  68e8905a00               push      0x5a90e8
00482dee  68b0a45a00               push      0x5aa4b0
00482df3  6860fe9400               push      0x94fe60
00482df8  6868f39400               push      0x94f368
00482dfd  68b0ee9400               push      0x94eeb0
00482e02  680cf19400               push      0x94f10c
00482e07  685ca45a00               push      0x5aa45c
00482e0c  6864a45a00               push      0x5aa464
00482e11  68b8a55a00               push      0x5aa5b8
00482e16  8b8544feffff             mov       eax, dword ptr [ebp - 0x1bc]
00482e1c  8d14856ca75a00           lea       edx, [eax*4 + 0x5aa76c]
00482e23  52                       push      edx
00482e24  8b5514                   mov       edx, dword ptr [ebp + 0x14]
00482e27  8d12                     lea       edx, [edx]
00482e29  52                       push      edx
00482e2a  8b9578feffff             mov       edx, dword ptr [ebp - 0x188]
00482e30  8d1a                     lea       ebx, [edx]
00482e32  53                       push      ebx
00482e33  e88867ffff               call      0x4795c0 ; _twdout_
00482e38  83c474                   add       esp, 0x74
00482e3b  83bd0cfeffff00           cmp       dword ptr [ebp - 0x1f4], 0
00482e42  7e20                     jle       0x482e64
00482e44  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00482e4a  8b08                     mov       ecx, dword ptr [eax]
00482e4c  8d15bc955a00             lea       edx, [0x5a95bc] ; bits=69020000, f32=8.646011524884121e-43
00482e52  894dfc                   mov       dword ptr [ebp - 4], ecx
00482e55  8d4dfc                   lea       ecx, [ebp - 4]
00482e58  894a08                   mov       dword ptr [edx + 8], ecx
00482e5b  52                       push      edx
00482e5c  e88ff70100               call      0x4a25f0 ; _jwe_isfm
00482e61  83c404                   add       esp, 4
00482e64  ff8544feffff             inc       dword ptr [ebp - 0x1bc]
00482e6a  83ad4cfeffff01           sub       dword ptr [ebp - 0x1b4], 1
00482e71  0f853adbffff             jne       0x4809b1
00482e77  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00482e7d  8b18                     mov       ebx, dword ptr [eax]
00482e7f  8b0554a45a00             mov       eax, dword ptr [0x5aa454] ; bits=00000000, f32=0.0
00482e85  8b0c856ca95a00           mov       ecx, dword ptr [eax*4 + 0x5aa96c]
00482e8c  8b05b4a45a00             mov       eax, dword ptr [0x5aa4b4] ; bits=00000000, f32=0.0
00482e92  8b1558a45a00             mov       edx, dword ptr [0x5aa458] ; bits=00000000, f32=0.0
00482e98  8b3495e0f89400           mov       esi, dword ptr [edx*4 + 0x94f8e0]
00482e9f  8d156c955a00             lea       edx, [0x5a956c] ; bits=09020000, f32=7.300764999132297e-43
00482ea5  895dfc                   mov       dword ptr [ebp - 4], ebx
00482ea8  8d7dfc                   lea       edi, [ebp - 4]
00482eab  897a08                   mov       dword ptr [edx + 8], edi
00482eae  db6d8c                   fld       xword ptr [ebp - 0x74]
00482eb1  d95df8                   fstp      dword ptr [ebp - 8]
00482eb4  8d7df8                   lea       edi, [ebp - 8]
00482eb7  897a28                   mov       dword ptr [edx + 0x28], edi
00482eba  894df4                   mov       dword ptr [ebp - 0xc], ecx
00482ebd  8d4df4                   lea       ecx, [ebp - 0xc]
00482ec0  894a34                   mov       dword ptr [edx + 0x34], ecx
00482ec3  8945f0                   mov       dword ptr [ebp - 0x10], eax
00482ec6  8d45f0                   lea       eax, [ebp - 0x10]
00482ec9  894240                   mov       dword ptr [edx + 0x40], eax
00482ecc  8975e8                   mov       dword ptr [ebp - 0x18], esi
00482ecf  8d45e8                   lea       eax, [ebp - 0x18]
00482ed2  89424c                   mov       dword ptr [edx + 0x4c], eax
00482ed5  52                       push      edx
00482ed6  e815f70100               call      0x4a25f0 ; _jwe_isfm
00482edb  83c404                   add       esp, 4
00482ede  8b8550feffff             mov       eax, dword ptr [ebp - 0x1b0]
00482ee4  8945fc                   mov       dword ptr [ebp - 4], eax
00482ee7  db6d98                   fld       xword ptr [ebp - 0x68]
00482eea  da75fc                   fidiv     dword ptr [ebp - 4]
00482eed  d9fa                     fsqrt
00482eef  d95df8                   fstp      dword ptr [ebp - 8]
00482ef2  8b4df8                   mov       ecx, dword ptr [ebp - 8]
00482ef5  8d1534955a00             lea       edx, [0x5a9534] ; bits=09020000, f32=7.300764999132297e-43
00482efb  895dfc                   mov       dword ptr [ebp - 4], ebx
00482efe  8d5dfc                   lea       ebx, [ebp - 4]
00482f01  895a08                   mov       dword ptr [edx + 8], ebx
00482f04  894df8                   mov       dword ptr [ebp - 8], ecx
00482f07  8d4df8                   lea       ecx, [ebp - 8]
00482f0a  894a28                   mov       dword ptr [edx + 0x28], ecx
00482f0d  8945ec                   mov       dword ptr [ebp - 0x14], eax
00482f10  8d45ec                   lea       eax, [ebp - 0x14]
00482f13  894234                   mov       dword ptr [edx + 0x34], eax
00482f16  52                       push      edx
00482f17  e8d4f60100               call      0x4a25f0 ; _jwe_isfm
00482f1c  83c404                   add       esp, 4
00482f1f  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00482f22  8b18                     mov       ebx, dword ptr [eax]
00482f24  6a10                     push      0x10
00482f26  6860a65a00               push      0x5aa660
00482f2b  e820cbfcff               call      0x44fa50 ; _lenstr_
00482f30  83c408                   add       esp, 8
00482f33  89c2                     mov       edx, eax
00482f35  c1fa1f                   sar       edx, 0x1f
00482f38  f7d2                     not       edx
00482f3a  21d0                     and       eax, edx
00482f3c  8d0dfc945a00             lea       ecx, [0x5a94fc] ; bits=09020000, f32=7.300764999132297e-43
00482f42  895dfc                   mov       dword ptr [ebp - 4], ebx
00482f45  8d55fc                   lea       edx, [ebp - 4]
00482f48  895108                   mov       dword ptr [ecx + 8], edx
00482f4b  894124                   mov       dword ptr [ecx + 0x24], eax
00482f4e  51                       push      ecx
00482f4f  e89cf60100               call      0x4a25f0 ; _jwe_isfm
00482f54  83c404                   add       esp, 4
00482f57  8b856cfeffff             mov       eax, dword ptr [ebp - 0x194]
00482f5d  89c3                     mov       ebx, eax
00482f5f  3d00000000               cmp       eax, 0
00482f64  0f8e73010000             jle       0x4830dd
00482f6a  b801000000               mov       eax, 1
00482f6f  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
00482f75  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00482f7b  8d0c856ca75a00           lea       ecx, [eax*4 + 0x5aa76c]
00482f82  51                       push      ecx
00482f83  6a10                     push      0x10
00482f85  6860a75a00               push      0x5aa760
00482f8a  e80144ffff               call      0x477390 ; _get_tabid_
00482f8f  8d0560a75a00             lea       eax, [0x5aa760] ; bits=00000000, f32=0.0
00482f95  8a08                     mov       cl, byte ptr [eax]
00482f97  8d15c8a65a00             lea       edx, [0x5aa6c8] ; bits=00000000, f32=0.0
00482f9d  880a                     mov       byte ptr [edx], cl
00482f9f  8a4801                   mov       cl, byte ptr [eax + 1]
00482fa2  884a01                   mov       byte ptr [edx + 1], cl
00482fa5  8a4802                   mov       cl, byte ptr [eax + 2]
00482fa8  884a02                   mov       byte ptr [edx + 2], cl
00482fab  8a4803                   mov       cl, byte ptr [eax + 3]
00482fae  884a03                   mov       byte ptr [edx + 3], cl
00482fb1  8a4804                   mov       cl, byte ptr [eax + 4]
00482fb4  884a04                   mov       byte ptr [edx + 4], cl
00482fb7  8a4805                   mov       cl, byte ptr [eax + 5]
00482fba  884a05                   mov       byte ptr [edx + 5], cl
00482fbd  8a4806                   mov       cl, byte ptr [eax + 6]
00482fc0  884a06                   mov       byte ptr [edx + 6], cl
00482fc3  8a4807                   mov       cl, byte ptr [eax + 7]
00482fc6  884a07                   mov       byte ptr [edx + 7], cl
00482fc9  8a4808                   mov       cl, byte ptr [eax + 8]
00482fcc  884a08                   mov       byte ptr [edx + 8], cl
00482fcf  8a4809                   mov       cl, byte ptr [eax + 9]
00482fd2  884a09                   mov       byte ptr [edx + 9], cl
00482fd5  8a480a                   mov       cl, byte ptr [eax + 0xa]
00482fd8  884a0a                   mov       byte ptr [edx + 0xa], cl
00482fdb  8a480b                   mov       cl, byte ptr [eax + 0xb]
00482fde  884a0b                   mov       byte ptr [edx + 0xb], cl
00482fe1  8a480c                   mov       cl, byte ptr [eax + 0xc]
00482fe4  884a0c                   mov       byte ptr [edx + 0xc], cl
00482fe7  8a480d                   mov       cl, byte ptr [eax + 0xd]
00482fea  884a0d                   mov       byte ptr [edx + 0xd], cl
00482fed  8a480e                   mov       cl, byte ptr [eax + 0xe]
00482ff0  884a0e                   mov       byte ptr [edx + 0xe], cl
00482ff3  8a480f                   mov       cl, byte ptr [eax + 0xf]
00482ff6  884a0f                   mov       byte ptr [edx + 0xf], cl
00482ff9  83c40c                   add       esp, 0xc
00482ffc  6a10                     push      0x10
00482ffe  68c8a65a00               push      0x5aa6c8
00483003  e848cafcff               call      0x44fa50 ; _lenstr_
00483008  8d0d60a65a00             lea       ecx, [0x5aa660] ; bits=00000000, f32=0.0
0048300e  c60120                   mov       byte ptr [ecx], 0x20
00483011  c6410120                 mov       byte ptr [ecx + 1], 0x20
00483015  c6410220                 mov       byte ptr [ecx + 2], 0x20
00483019  c6410320                 mov       byte ptr [ecx + 3], 0x20
0048301d  c6410420                 mov       byte ptr [ecx + 4], 0x20
00483021  c6410520                 mov       byte ptr [ecx + 5], 0x20
00483025  c6410620                 mov       byte ptr [ecx + 6], 0x20
00483029  c6410720                 mov       byte ptr [ecx + 7], 0x20
0048302d  c6410820                 mov       byte ptr [ecx + 8], 0x20
00483031  c6410920                 mov       byte ptr [ecx + 9], 0x20
00483035  c6410a20                 mov       byte ptr [ecx + 0xa], 0x20
00483039  c6410b20                 mov       byte ptr [ecx + 0xb], 0x20
0048303d  c6410c20                 mov       byte ptr [ecx + 0xc], 0x20
00483041  c6410d20                 mov       byte ptr [ecx + 0xd], 0x20
00483045  c6410e20                 mov       byte ptr [ecx + 0xe], 0x20
00483049  c6410f20                 mov       byte ptr [ecx + 0xf], 0x20
0048304d  b910000000               mov       ecx, 0x10
00483052  29c1                     sub       ecx, eax
00483054  8d5101                   lea       edx, [ecx + 1]
00483057  be11000000               mov       esi, 0x11
0048305c  29d6                     sub       esi, edx
0048305e  89f2                     mov       edx, esi
00483060  c1fa1f                   sar       edx, 0x1f
00483063  f7d2                     not       edx
00483065  21d6                     and       esi, edx
00483067  89c2                     mov       edx, eax
00483069  c1fa1f                   sar       edx, 0x1f
0048306c  f7d2                     not       edx
0048306e  21d0                     and       eax, edx
00483070  83c408                   add       esp, 8
00483073  50                       push      eax
00483074  56                       push      esi
00483075  68c8a65a00               push      0x5aa6c8
0048307a  8d0c0d60a65a00           lea       ecx, [ecx + 0x5aa660]
00483081  51                       push      ecx
00483082  e829c20100               call      0x49f2b0 ; _f_scmov
00483087  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0048308a  8b00                     mov       eax, dword ptr [eax]
0048308c  8d0dac945a00             lea       ecx, [0x5a94ac] ; bits=09020000, f32=7.300764999132297e-43
00483092  8945fc                   mov       dword ptr [ebp - 4], eax
00483095  8b9560feffff             mov       edx, dword ptr [ebp - 0x1a0]
0048309b  8d45fc                   lea       eax, [ebp - 4]
0048309e  8b34956ca95a00           mov       esi, dword ptr [edx*4 + 0x5aa96c]
004830a5  894108                   mov       dword ptr [ecx + 8], eax
004830a8  8975f8                   mov       dword ptr [ebp - 8], esi
004830ab  8d45f8                   lea       eax, [ebp - 8]
004830ae  894128                   mov       dword ptr [ecx + 0x28], eax
004830b1  8d04950caa5a00           lea       eax, [edx*4 + 0x5aaa0c]
004830b8  894148                   mov       dword ptr [ecx + 0x48], eax
004830bb  83c410                   add       esp, 0x10
004830be  51                       push      ecx
004830bf  e82cf50100               call      0x4a25f0 ; _jwe_isfm
004830c4  83c404                   add       esp, 4
004830c7  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
004830cd  40                       inc       eax
004830ce  83eb01                   sub       ebx, 1
004830d1  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
004830d7  0f8598feffff             jne       0x482f75
004830dd  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004830e0  8b00                     mov       eax, dword ptr [eax]
004830e2  8d0d80945a00             lea       ecx, [0x5a9480] ; bits=09020000, f32=7.300764999132297e-43
004830e8  8945fc                   mov       dword ptr [ebp - 4], eax
004830eb  8d45fc                   lea       eax, [ebp - 4]
004830ee  894108                   mov       dword ptr [ecx + 8], eax
004830f1  51                       push      ecx
004830f2  e8f9f40100               call      0x4a25f0 ; _jwe_isfm
004830f7  83c404                   add       esp, 4
004830fa  eb45                     jmp       0x483141
004830fc  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00483102  8b18                     mov       ebx, dword ptr [eax]
00483104  8d0554945a00             lea       eax, [0x5a9454] ; bits=09820000, f32=4.664782457890884e-41
0048310a  895dfc                   mov       dword ptr [ebp - 4], ebx
0048310d  8d4dfc                   lea       ecx, [ebp - 4]
00483110  894808                   mov       dword ptr [eax + 8], ecx
00483113  50                       push      eax
00483114  e867fd0100               call      0x4a2e80 ; _jwe_ilst
00483119  83c404                   add       esp, 4
0048311c  8d0528945a00             lea       eax, [0x5a9428] ; bits=09820000, f32=4.664782457890884e-41
00483122  895dfc                   mov       dword ptr [ebp - 4], ebx
00483125  8d4dfc                   lea       ecx, [ebp - 4]
00483128  894808                   mov       dword ptr [eax + 8], ecx
0048312b  50                       push      eax
0048312c  e84ffd0100               call      0x4a2e80 ; _jwe_ilst
00483131  83c404                   add       esp, 4
00483134  6868935a00               push      0x5a9368
00483139  e802030200               call      0x4a3440 ; _jwe_xstp
0048313e  83c404                   add       esp, 4
00483141  b800000000               mov       eax, 0
00483146  5f                       pop       edi
00483147  5e                       pop       esi
00483148  5b                       pop       ebx
00483149  8be5                     mov       esp, ebp
0048314b  5d                       pop       ebp
0048314c  c3                       ret
0048314d  8d4900                   lea       ecx, [ecx]
