; _embank_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x310e0
004310e0  55                       push      ebp
004310e1  8bec                     mov       ebp, esp
004310e3  b818010000               mov       eax, 0x118
004310e8  e8137f0b00               call      0x4e9000 ; __alloca_probe
004310ed  53                       push      ebx
004310ee  56                       push      esi
004310ef  57                       push      edi
004310f0  8b4508                   mov       eax, dword ptr [ebp + 8]
004310f3  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
004310f6  8b5510                   mov       edx, dword ptr [ebp + 0x10]
004310f9  898544ffffff             mov       dword ptr [ebp - 0xbc], eax
004310ff  898d40ffffff             mov       dword ptr [ebp - 0xc0], ecx
00431105  89953cffffff             mov       dword ptr [ebp - 0xc4], edx
0043110b  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
0043110e  8d03                     lea       eax, [ebx]
00431110  50                       push      eax
00431111  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431117  8d08                     lea       ecx, [eax]
00431119  51                       push      ecx
0043111a  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
00431120  8d11                     lea       edx, [ecx]
00431122  52                       push      edx
00431123  e8682a0000               call      0x433b90 ; _get_embk_items_
00431128  83c40c                   add       esp, 0xc
0043112b  685ce65600               push      0x56e65c
00431130  6858e65600               push      0x56e658
00431135  6850e65600               push      0x56e650
0043113a  6854e65600               push      0x56e654
0043113f  689cbbf400               push      0xf4bb9c
00431144  6898bbf400               push      0xf4bb98
00431149  680ce65600               push      0x56e60c
0043114e  6808e65600               push      0x56e608
00431153  8d1b                     lea       ebx, [ebx]
00431155  53                       push      ebx
00431156  e815290000               call      0x433a70 ; _set_embk_items_
0043115b  83c424                   add       esp, 0x24
0043115e  d9055ce65600             fld       dword ptr [0x56e65c] ; bits=00000000, f32=0.0
00431164  d9ee                     fldz
00431166  d9c9                     fxch      st(1)
00431168  dae9                     fucompp
0043116a  dfe0                     fnstsw    ax
0043116c  9e                       sahf
0043116d  0f8a0d000000             jp        0x431180
00431173  750b                     jne       0x431180
00431175  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00431178  8b00                     mov       eax, dword ptr [eax]
0043117a  89055ce65600             mov       dword ptr [0x56e65c], eax ; bits=00000000, f32=0.0
00431180  833d0ce6560005           cmp       dword ptr [0x56e60c], 5 ; bits=00000000, f32=0.0
00431187  752a                     jne       0x4311b3
00431189  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
0043118f  8b08                     mov       ecx, dword ptr [eax]
00431191  8d15c8e55600             lea       edx, [0x56e5c8] ; bits=69020000, f32=8.646011524884121e-43
00431197  894dfc                   mov       dword ptr [ebp - 4], ecx
0043119a  8d4dfc                   lea       ecx, [ebp - 4]
0043119d  894a08                   mov       dword ptr [edx + 8], ecx
004311a0  52                       push      edx
004311a1  e84a140700               call      0x4a25f0 ; _jwe_isfm
004311a6  83c404                   add       esp, 4
004311a9  c7050ce656000d000000     mov       dword ptr [0x56e60c], 0xd ; bits=00000000, f32=0.0
004311b3  d90598bbf400             fld       dword ptr [0xf4bb98]
004311b9  d81d48da5600             fcomp     dword ptr [0x56da48] ; bits=00000000, f32=0.0
004311bf  dfe0                     fnstsw    ax
004311c1  9e                       sahf
004311c2  0f8a2e000000             jp        0x4311f6
004311c8  732c                     jae       0x4311f6
004311ca  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004311d0  8b08                     mov       ecx, dword ptr [eax]
004311d2  8d159ce55600             lea       edx, [0x56e59c] ; bits=09820000, f32=4.664782457890884e-41
004311d8  894dfc                   mov       dword ptr [ebp - 4], ecx
004311db  8d4dfc                   lea       ecx, [ebp - 4]
004311de  894a08                   mov       dword ptr [edx + 8], ecx
004311e1  52                       push      edx
004311e2  e8991c0700               call      0x4a2e80 ; _jwe_ilst
004311e7  83c404                   add       esp, 4
004311ea  8b0550da5600             mov       eax, dword ptr [0x56da50] ; bits=9a99193e, f32=0.15000000596046448
004311f0  890598bbf400             mov       dword ptr [0xf4bb98], eax
004311f6  d9059cbbf400             fld       dword ptr [0xf4bb9c]
004311fc  d81d48da5600             fcomp     dword ptr [0x56da48] ; bits=00000000, f32=0.0
00431202  dfe0                     fnstsw    ax
00431204  9e                       sahf
00431205  0f8a2e000000             jp        0x431239
0043120b  732c                     jae       0x431239
0043120d  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431213  8b08                     mov       ecx, dword ptr [eax]
00431215  8d1570e55600             lea       edx, [0x56e570] ; bits=09820000, f32=4.664782457890884e-41
0043121b  894dfc                   mov       dword ptr [ebp - 4], ecx
0043121e  8d4dfc                   lea       ecx, [ebp - 4]
00431221  894a08                   mov       dword ptr [edx + 8], ecx
00431224  52                       push      edx
00431225  e8561c0700               call      0x4a2e80 ; _jwe_ilst
0043122a  83c404                   add       esp, 4
0043122d  8b0554da5600             mov       eax, dword ptr [0x56da54] ; bits=0ad7a33e, f32=0.3199999928474426
00431233  89059cbbf400             mov       dword ptr [0xf4bb9c], eax
00431239  6808e65600               push      0x56e608
0043123e  6a10                     push      0x10
00431240  6828e85600               push      0x56e828
00431245  e846610400               call      0x477390 ; _get_tabid_
0043124a  83c40c                   add       esp, 0xc
0043124d  8d05a0e75600             lea       eax, [0x56e7a0] ; bits=00000000, f32=0.0
00431253  8d0d28e85600             lea       ecx, [0x56e828] ; bits=00000000, f32=0.0
00431259  8a11                     mov       dl, byte ptr [ecx]
0043125b  8810                     mov       byte ptr [eax], dl
0043125d  8a5101                   mov       dl, byte ptr [ecx + 1]
00431260  885001                   mov       byte ptr [eax + 1], dl
00431263  8a5102                   mov       dl, byte ptr [ecx + 2]
00431266  885002                   mov       byte ptr [eax + 2], dl
00431269  8a5103                   mov       dl, byte ptr [ecx + 3]
0043126c  885003                   mov       byte ptr [eax + 3], dl
0043126f  8a5104                   mov       dl, byte ptr [ecx + 4]
00431272  885004                   mov       byte ptr [eax + 4], dl
00431275  8a5105                   mov       dl, byte ptr [ecx + 5]
00431278  885005                   mov       byte ptr [eax + 5], dl
0043127b  8a5106                   mov       dl, byte ptr [ecx + 6]
0043127e  885006                   mov       byte ptr [eax + 6], dl
00431281  8a5107                   mov       dl, byte ptr [ecx + 7]
00431284  885007                   mov       byte ptr [eax + 7], dl
00431287  8a5108                   mov       dl, byte ptr [ecx + 8]
0043128a  885008                   mov       byte ptr [eax + 8], dl
0043128d  8a5109                   mov       dl, byte ptr [ecx + 9]
00431290  885009                   mov       byte ptr [eax + 9], dl
00431293  8a510a                   mov       dl, byte ptr [ecx + 0xa]
00431296  88500a                   mov       byte ptr [eax + 0xa], dl
00431299  8a510b                   mov       dl, byte ptr [ecx + 0xb]
0043129c  88500b                   mov       byte ptr [eax + 0xb], dl
0043129f  8a510c                   mov       dl, byte ptr [ecx + 0xc]
004312a2  88500c                   mov       byte ptr [eax + 0xc], dl
004312a5  8a510d                   mov       dl, byte ptr [ecx + 0xd]
004312a8  88500d                   mov       byte ptr [eax + 0xd], dl
004312ab  8a510e                   mov       dl, byte ptr [ecx + 0xe]
004312ae  88500e                   mov       byte ptr [eax + 0xe], dl
004312b1  8a510f                   mov       dl, byte ptr [ecx + 0xf]
004312b4  88500f                   mov       byte ptr [eax + 0xf], dl
004312b7  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004312bd  8b18                     mov       ebx, dword ptr [eax]
004312bf  6a10                     push      0x10
004312c1  68a0e75600               push      0x56e7a0
004312c6  e885e70100               call      0x44fa50 ; _lenstr_
004312cb  83c408                   add       esp, 8
004312ce  89c2                     mov       edx, eax
004312d0  c1fa1f                   sar       edx, 0x1f
004312d3  f7d2                     not       edx
004312d5  21d0                     and       eax, edx
004312d7  8b0d0ce65600             mov       ecx, dword ptr [0x56e60c] ; bits=00000000, f32=0.0
004312dd  8b1598bbf400             mov       edx, dword ptr [0xf4bb98]
004312e3  8b359cbbf400             mov       esi, dword ptr [0xf4bb9c]
004312e9  8b3d54e65600             mov       edi, dword ptr [0x56e654] ; bits=00000000, f32=0.0
004312ef  899d38ffffff             mov       dword ptr [ebp - 0xc8], ebx
004312f5  8b1d50e65600             mov       ebx, dword ptr [0x56e650] ; bits=00000000, f32=0.0
004312fb  898534ffffff             mov       dword ptr [ebp - 0xcc], eax
00431301  8b0558e65600             mov       eax, dword ptr [0x56e658] ; bits=00000000, f32=0.0
00431307  898d30ffffff             mov       dword ptr [ebp - 0xd0], ecx
0043130d  8b0d5ce65600             mov       ecx, dword ptr [0x56e65c] ; bits=00000000, f32=0.0
00431313  898d24ffffff             mov       dword ptr [ebp - 0xdc], ecx
00431319  89952cffffff             mov       dword ptr [ebp - 0xd4], edx
0043131f  8d15f0e45600             lea       edx, [0x56e4f0] ; bits=09020000, f32=7.300764999132297e-43
00431325  89b528ffffff             mov       dword ptr [ebp - 0xd8], esi
0043132b  8bb538ffffff             mov       esi, dword ptr [ebp - 0xc8]
00431331  8975fc                   mov       dword ptr [ebp - 4], esi
00431334  8d75fc                   lea       esi, [ebp - 4]
00431337  897208                   mov       dword ptr [edx + 8], esi
0043133a  8bb534ffffff             mov       esi, dword ptr [ebp - 0xcc]
00431340  897224                   mov       dword ptr [edx + 0x24], esi
00431343  8bb530ffffff             mov       esi, dword ptr [ebp - 0xd0]
00431349  8975f8                   mov       dword ptr [ebp - 8], esi
0043134c  8d75f8                   lea       esi, [ebp - 8]
0043134f  897234                   mov       dword ptr [edx + 0x34], esi
00431352  8bb52cffffff             mov       esi, dword ptr [ebp - 0xd4]
00431358  8975f4                   mov       dword ptr [ebp - 0xc], esi
0043135b  8d75f4                   lea       esi, [ebp - 0xc]
0043135e  897240                   mov       dword ptr [edx + 0x40], esi
00431361  8bb528ffffff             mov       esi, dword ptr [ebp - 0xd8]
00431367  8975f0                   mov       dword ptr [ebp - 0x10], esi
0043136a  8d75f0                   lea       esi, [ebp - 0x10]
0043136d  89724c                   mov       dword ptr [edx + 0x4c], esi
00431370  897dec                   mov       dword ptr [ebp - 0x14], edi
00431373  8d75ec                   lea       esi, [ebp - 0x14]
00431376  897258                   mov       dword ptr [edx + 0x58], esi
00431379  895de8                   mov       dword ptr [ebp - 0x18], ebx
0043137c  8d5de8                   lea       ebx, [ebp - 0x18]
0043137f  895a64                   mov       dword ptr [edx + 0x64], ebx
00431382  8945e4                   mov       dword ptr [ebp - 0x1c], eax
00431385  8d45e4                   lea       eax, [ebp - 0x1c]
00431388  894270                   mov       dword ptr [edx + 0x70], eax
0043138b  894de0                   mov       dword ptr [ebp - 0x20], ecx
0043138e  8d45e0                   lea       eax, [ebp - 0x20]
00431391  89427c                   mov       dword ptr [edx + 0x7c], eax
00431394  52                       push      edx
00431395  e856120700               call      0x4a25f0 ; _jwe_isfm
0043139a  83c404                   add       esp, 4
0043139d  8b853cffffff             mov       eax, dword ptr [ebp - 0xc4]
004313a3  8b08                     mov       ecx, dword ptr [eax]
004313a5  8d15c4e45600             lea       edx, [0x56e4c4] ; bits=09020000, f32=7.300764999132297e-43
004313ab  894dfc                   mov       dword ptr [ebp - 4], ecx
004313ae  8d4dfc                   lea       ecx, [ebp - 4]
004313b1  894a08                   mov       dword ptr [edx + 8], ecx
004313b4  8b9d24ffffff             mov       ebx, dword ptr [ebp - 0xdc]
004313ba  895df4                   mov       dword ptr [ebp - 0xc], ebx
004313bd  8d4df4                   lea       ecx, [ebp - 0xc]
004313c0  894a28                   mov       dword ptr [edx + 0x28], ecx
004313c3  52                       push      edx
004313c4  e827120700               call      0x4a25f0 ; _jwe_isfm
004313c9  83c404                   add       esp, 4
004313cc  6898e45600               push      0x56e498
004313d1  e81a120700               call      0x4a25f0 ; _jwe_isfm
004313d6  83c404                   add       esp, 4
004313d9  8b0508e65600             mov       eax, dword ptr [0x56e608] ; bits=00000000, f32=0.0
004313df  833c85ec5a0e0400         cmp       dword ptr [eax*4 + 0x40e5aec], 0
004313e7  7415                     je        0x4313fe
004313e9  6a10                     push      0x10
004313eb  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004313ee  8d00                     lea       eax, [eax]
004313f0  50                       push      eax
004313f1  68a0e75600               push      0x56e7a0
004313f6  e855950200               call      0x45a950 ; _tab_in_use_
004313fb  83c40c                   add       esp, 0xc
004313fe  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
00431401  8d03                     lea       eax, [ebx]
00431403  50                       push      eax
00431404  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
0043140a  8d08                     lea       ecx, [eax]
0043140c  51                       push      ecx
0043140d  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
00431413  8d11                     lea       edx, [ecx]
00431415  52                       push      edx
00431416  e865be0200               call      0x45d280 ; _get_lctn_items_
0043141b  83c40c                   add       esp, 0xc
0043141e  6a08                     push      8
00431420  6a08                     push      8
00431422  6a08                     push      8
00431424  6a08                     push      8
00431426  6a08                     push      8
00431428  68f0e55600               push      0x56e5f0
0043142d  68e8e55600               push      0x56e5e8
00431432  6820e85600               push      0x56e820
00431437  6818e85600               push      0x56e818
0043143c  6810e85600               push      0x56e810
00431441  6808e85600               push      0x56e808
00431446  6800e85600               push      0x56e800
0043144b  e850bd0200               call      0x45d1a0 ; _set_lctn_items_
00431450  83c430                   add       esp, 0x30
00431453  681c15f300               push      0xf3151c
00431458  681815f300               push      0xf31518
0043145d  681415f300               push      0xf31514
00431462  681015f300               push      0xf31510
00431467  680c15f300               push      0xf3150c
0043146c  680815f300               push      0xf31508
00431471  8d1b                     lea       ebx, [ebx]
00431473  53                       push      ebx
00431474  68f05a0e04               push      0x40e5af0
00431479  6854db5600               push      0x56db54
0043147e  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431484  8d08                     lea       ecx, [eax]
00431486  51                       push      ecx
00431487  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
0043148d  8d11                     lea       edx, [ecx]
0043148f  52                       push      edx
00431490  e8dbf9ffff               call      0x430e70 ; _etabin_
00431495  83c42c                   add       esp, 0x2c
00431498  833d1815f30000           cmp       dword ptr [0xf31518], 0
0043149f  7409                     je        0x4314aa
004314a1  833d1c15f30000           cmp       dword ptr [0xf3151c], 0
004314a8  750c                     jne       0x4314b6
004314aa  c70504e6560000000000     mov       dword ptr [0x56e604], 0 ; bits=00000000, f32=0.0
004314b4  eb0a                     jmp       0x4314c0
004314b6  c70504e6560001000000     mov       dword ptr [0x56e604], 1 ; bits=00000000, f32=0.0
004314c0  6a78                     push      0x78
004314c2  6818e75600               push      0x56e718
004314c7  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004314cd  8d08                     lea       ecx, [eax]
004314cf  51                       push      ecx
004314d0  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
004314d6  8d11                     lea       edx, [ecx]
004314d8  52                       push      edx
004314d9  e802b40100               call      0x44c8e0 ; _inline_
004314de  83c410                   add       esp, 0x10
004314e1  6878e45600               push      0x56e478
004314e6  e865060700               call      0x4a1b50 ; _jwe_iinf
004314eb  83c404                   add       esp, 4
004314ee  85c0                     test      eax, eax
004314f0  0f859f180000             jne       0x432d95
004314f6  686ce45600               push      0x56e46c
004314fb  e850060700               call      0x4a1b50 ; _jwe_iinf
00431500  83c404                   add       esp, 4
00431503  85c0                     test      eax, eax
00431505  0f858a180000             jne       0x432d95
0043150b  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431511  8b08                     mov       ecx, dword ptr [eax]
00431513  8d1540e45600             lea       edx, [0x56e440] ; bits=09020000, f32=7.300764999132297e-43
00431519  894dfc                   mov       dword ptr [ebp - 4], ecx
0043151c  8d4dfc                   lea       ecx, [ebp - 4]
0043151f  894a08                   mov       dword ptr [edx + 8], ecx
00431522  52                       push      edx
00431523  e8c8100700               call      0x4a25f0 ; _jwe_isfm
00431528  83c404                   add       esp, 4
0043152b  c70534e6560000000000     mov       dword ptr [0x56e634], 0 ; bits=00000000, f32=0.0
00431535  6a08                     push      8
00431537  68c0f5f200               push      0xf2f5c0 ; _embcmc_
0043153c  680444f300               push      0xf34404
00431541  686434f300               push      0xf33464
00431546  68c424f300               push      0xf324c4
0043154b  682415f300               push      0xf31524
00431550  680415f300               push      0xf31504
00431555  682015f300               push      0xf31520
0043155a  680015f300               push      0xf31500 ; _embcom_
0043155f  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00431562  8d00                     lea       eax, [eax]
00431564  50                       push      eax
00431565  6834e65600               push      0x56e634
0043156a  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431570  8d08                     lea       ecx, [eax]
00431572  51                       push      ecx
00431573  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
00431579  8d11                     lea       edx, [ecx]
0043157b  52                       push      edx
0043157c  e83ff3ffff               call      0x4308c0 ; _inprdp_
00431581  83c434                   add       esp, 0x34
00431584  d9052015f300             fld       dword ptr [0xf31520]
0043158a  d80558e65600             fadd      dword ptr [0x56e658] ; bits=00000000, f32=0.0
00431590  d91d2015f300             fstp      dword ptr [0xf31520]
00431596  8b150015f300             mov       edx, dword ptr [0xf31500] ; _embcom_
0043159c  83fa00                   cmp       edx, 0
0043159f  0f8e53010000             jle       0x4316f8
004315a5  b801000000               mov       eax, 1
004315aa  83fa02                   cmp       edx, 2
004315ad  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
004315b3  0f8cd5000000             jl        0x43168e
004315b9  d90558e65600             fld       dword ptr [0x56e658] ; bits=00000000, f32=0.0
004315bf  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
004315c5  d9c0                     fld       st(0)
004315c7  d80485c024f300           fadd      dword ptr [eax*4 + 0xf324c0]
004315ce  d8252015f300             fsub      dword ptr [0xf31520]
004315d4  d904850044f300           fld       dword ptr [eax*4 + 0xf34400]
004315db  d8252015f300             fsub      dword ptr [0xf31520]
004315e1  d9c9                     fxch      st(1)
004315e3  d80d50e65600             fmul      dword ptr [0x56e650] ; bits=00000000, f32=0.0
004315e9  d91c85c024f300           fstp      dword ptr [eax*4 + 0xf324c0]
004315f0  d80d50e65600             fmul      dword ptr [0x56e650] ; bits=00000000, f32=0.0
004315f6  d91c850044f300           fstp      dword ptr [eax*4 + 0xf34400]
004315fd  d90554e65600             fld       dword ptr [0x56e654] ; bits=00000000, f32=0.0
00431603  d9c0                     fld       st(0)
00431605  d80c852015f300           fmul      dword ptr [eax*4 + 0xf31520]
0043160c  d91c852015f300           fstp      dword ptr [eax*4 + 0xf31520]
00431613  d9c0                     fld       st(0)
00431615  d80c856034f300           fmul      dword ptr [eax*4 + 0xf33460]
0043161c  d91c856034f300           fstp      dword ptr [eax*4 + 0xf33460]
00431623  d9c9                     fxch      st(1)
00431625  d80485c424f300           fadd      dword ptr [eax*4 + 0xf324c4]
0043162c  d8252015f300             fsub      dword ptr [0xf31520]
00431632  d904850444f300           fld       dword ptr [eax*4 + 0xf34404]
00431639  d8252015f300             fsub      dword ptr [0xf31520]
0043163f  d9c9                     fxch      st(1)
00431641  d80d50e65600             fmul      dword ptr [0x56e650] ; bits=00000000, f32=0.0
00431647  d91c85c424f300           fstp      dword ptr [eax*4 + 0xf324c4]
0043164e  d80d50e65600             fmul      dword ptr [0x56e650] ; bits=00000000, f32=0.0
00431654  d91c850444f300           fstp      dword ptr [eax*4 + 0xf34404]
0043165b  d9c0                     fld       st(0)
0043165d  d80c852415f300           fmul      dword ptr [eax*4 + 0xf31524]
00431664  d91c852415f300           fstp      dword ptr [eax*4 + 0xf31524]
0043166b  d80c856434f300           fmul      dword ptr [eax*4 + 0xf33464]
00431672  d91c856434f300           fstp      dword ptr [eax*4 + 0xf33464]
00431679  83c002                   add       eax, 2
0043167c  83ea02                   sub       edx, 2
0043167f  83fa02                   cmp       edx, 2
00431682  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431688  0f8d2bffffff             jge       0x4315b9
0043168e  85d2                     test      edx, edx
00431690  7466                     je        0x4316f8
00431692  d90558e65600             fld       dword ptr [0x56e658] ; bits=00000000, f32=0.0
00431698  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
0043169e  d80485c024f300           fadd      dword ptr [eax*4 + 0xf324c0]
004316a5  d8252015f300             fsub      dword ptr [0xf31520]
004316ab  d904850044f300           fld       dword ptr [eax*4 + 0xf34400]
004316b2  d8252015f300             fsub      dword ptr [0xf31520]
004316b8  d9c9                     fxch      st(1)
004316ba  d80d50e65600             fmul      dword ptr [0x56e650] ; bits=00000000, f32=0.0
004316c0  d91c85c024f300           fstp      dword ptr [eax*4 + 0xf324c0]
004316c7  d80d50e65600             fmul      dword ptr [0x56e650] ; bits=00000000, f32=0.0
004316cd  d91c850044f300           fstp      dword ptr [eax*4 + 0xf34400]
004316d4  d90554e65600             fld       dword ptr [0x56e654] ; bits=00000000, f32=0.0
004316da  d9c0                     fld       st(0)
004316dc  d80c852015f300           fmul      dword ptr [eax*4 + 0xf31520]
004316e3  d91c852015f300           fstp      dword ptr [eax*4 + 0xf31520]
004316ea  d80c856034f300           fmul      dword ptr [eax*4 + 0xf33460]
004316f1  d91c856034f300           fstp      dword ptr [eax*4 + 0xf33460]
004316f8  d9052015f300             fld       dword ptr [0xf31520]
004316fe  d80d50e65600             fmul      dword ptr [0x56e650] ; bits=00000000, f32=0.0
00431704  d91d34e65600             fstp      dword ptr [0x56e634] ; bits=00000000, f32=0.0
0043170a  c7052015f30000000000     mov       dword ptr [0xf31520], 0
00431714  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
0043171a  8b08                     mov       ecx, dword ptr [eax]
0043171c  8b1534e65600             mov       edx, dword ptr [0x56e634] ; bits=00000000, f32=0.0
00431722  8d3514e45600             lea       esi, [0x56e414] ; bits=09020000, f32=7.300764999132297e-43
00431728  894dfc                   mov       dword ptr [ebp - 4], ecx
0043172b  8d4dfc                   lea       ecx, [ebp - 4]
0043172e  894e08                   mov       dword ptr [esi + 8], ecx
00431731  8955f4                   mov       dword ptr [ebp - 0xc], edx
00431734  8d4df4                   lea       ecx, [ebp - 0xc]
00431737  894e28                   mov       dword ptr [esi + 0x28], ecx
0043173a  56                       push      esi
0043173b  e8b00e0700               call      0x4a25f0 ; _jwe_isfm
00431740  83c404                   add       esp, 4
00431743  bb00000000               mov       ebx, 0
00431748  c705f8e5560015000000     mov       dword ptr [0x56e5f8], 0x15 ; bits=00000000, f32=0.0
00431752  8b0558da5600             mov       eax, dword ptr [0x56da58] ; bits=00000040, f32=2.0
00431758  89052ce65600             mov       dword ptr [0x56e62c], eax ; bits=00000000, f32=0.0
0043175e  c70538e6560000000000     mov       dword ptr [0x56e638], 0 ; bits=00000000, f32=0.0
00431768  6a78                     push      0x78
0043176a  6818e75600               push      0x56e718
0043176f  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431775  8d08                     lea       ecx, [eax]
00431777  51                       push      ecx
00431778  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
0043177e  8d11                     lea       edx, [ecx]
00431780  52                       push      edx
00431781  e85ab10100               call      0x44c8e0 ; _inline_
00431786  83c410                   add       esp, 0x10
00431789  68f4e35600               push      0x56e3f4
0043178e  e8bd030700               call      0x4a1b50 ; _jwe_iinf
00431793  83c404                   add       esp, 4
00431796  85c0                     test      eax, eax
00431798  0f85f7150000             jne       0x432d95
0043179e  68e8e35600               push      0x56e3e8
004317a3  e8a8030700               call      0x4a1b50 ; _jwe_iinf
004317a8  83c404                   add       esp, 4
004317ab  85c0                     test      eax, eax
004317ad  0f85e2150000             jne       0x432d95
004317b3  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004317b9  8b08                     mov       ecx, dword ptr [eax]
004317bb  8d35bce35600             lea       esi, [0x56e3bc] ; bits=09020000, f32=7.300764999132297e-43
004317c1  894dfc                   mov       dword ptr [ebp - 4], ecx
004317c4  8d4dfc                   lea       ecx, [ebp - 4]
004317c7  894e08                   mov       dword ptr [esi + 8], ecx
004317ca  56                       push      esi
004317cb  e8200e0700               call      0x4a25f0 ; _jwe_isfm
004317d0  83c404                   add       esp, 4
004317d3  6a78                     push      0x78
004317d5  6818e75600               push      0x56e718
004317da  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004317e0  8d08                     lea       ecx, [eax]
004317e2  51                       push      ecx
004317e3  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
004317e9  8d31                     lea       esi, [ecx]
004317eb  56                       push      esi
004317ec  e8efb00100               call      0x44c8e0 ; _inline_
004317f1  83c410                   add       esp, 0x10
004317f4  8d1518e75600             lea       edx, [0x56e718] ; bits=00000000, f32=0.0
004317fa  8d3dc4db5600             lea       edi, [0x56dbc4] ; bits=4e465241, f32=13.14216423034668
00431800  b905000000               mov       ecx, 5
00431805  89d6                     mov       esi, edx
00431807  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00431809  0f85ef010000             jne       0x4319fe
0043180f  689ce35600               push      0x56e39c
00431814  e837030700               call      0x4a1b50 ; _jwe_iinf
00431819  83c404                   add       esp, 4
0043181c  85c0                     test      eax, eax
0043181e  0f8571150000             jne       0x432d95
00431824  6884e35600               push      0x56e384
00431829  e822030700               call      0x4a1b50 ; _jwe_iinf
0043182e  83c404                   add       esp, 4
00431831  85c0                     test      eax, eax
00431833  0f855c150000             jne       0x432d95
00431839  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
0043183f  8b08                     mov       ecx, dword ptr [eax]
00431841  8b15f8e55600             mov       edx, dword ptr [0x56e5f8] ; bits=00000000, f32=0.0
00431847  8d354ce35600             lea       esi, [0x56e34c] ; bits=09020000, f32=7.300764999132297e-43
0043184d  894dfc                   mov       dword ptr [ebp - 4], ecx
00431850  8d4dfc                   lea       ecx, [ebp - 4]
00431853  894e08                   mov       dword ptr [esi + 8], ecx
00431856  8955f8                   mov       dword ptr [ebp - 8], edx
00431859  8d4df8                   lea       ecx, [ebp - 8]
0043185c  894e34                   mov       dword ptr [esi + 0x34], ecx
0043185f  56                       push      esi
00431860  e88b0d0700               call      0x4a25f0 ; _jwe_isfm
00431865  83c404                   add       esp, 4
00431868  6a78                     push      0x78
0043186a  6818e75600               push      0x56e718
0043186f  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431875  8d08                     lea       ecx, [eax]
00431877  51                       push      ecx
00431878  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
0043187e  8d11                     lea       edx, [ecx]
00431880  52                       push      edx
00431881  e85ab00100               call      0x44c8e0 ; _inline_
00431886  83c410                   add       esp, 0x10
00431889  682ce35600               push      0x56e32c
0043188e  e8bd020700               call      0x4a1b50 ; _jwe_iinf
00431893  83c404                   add       esp, 4
00431896  85c0                     test      eax, eax
00431898  0f85f7140000             jne       0x432d95
0043189e  6814e35600               push      0x56e314
004318a3  e8a8020700               call      0x4a1b50 ; _jwe_iinf
004318a8  83c404                   add       esp, 4
004318ab  85c0                     test      eax, eax
004318ad  0f85e2140000             jne       0x432d95
004318b3  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004318b9  8b08                     mov       ecx, dword ptr [eax]
004318bb  8b152ce65600             mov       edx, dword ptr [0x56e62c] ; bits=00000000, f32=0.0
004318c1  8d35dce25600             lea       esi, [0x56e2dc] ; bits=09020000, f32=7.300764999132297e-43
004318c7  894dfc                   mov       dword ptr [ebp - 4], ecx
004318ca  8d4dfc                   lea       ecx, [ebp - 4]
004318cd  894e08                   mov       dword ptr [esi + 8], ecx
004318d0  8955f4                   mov       dword ptr [ebp - 0xc], edx
004318d3  8d4df4                   lea       ecx, [ebp - 0xc]
004318d6  894e34                   mov       dword ptr [esi + 0x34], ecx
004318d9  56                       push      esi
004318da  e8110d0700               call      0x4a25f0 ; _jwe_isfm
004318df  83c404                   add       esp, 4
004318e2  6a78                     push      0x78
004318e4  6818e75600               push      0x56e718
004318e9  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004318ef  8d08                     lea       ecx, [eax]
004318f1  51                       push      ecx
004318f2  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
004318f8  8d11                     lea       edx, [ecx]
004318fa  52                       push      edx
004318fb  e8e0af0100               call      0x44c8e0 ; _inline_
00431900  83c410                   add       esp, 0x10
00431903  8d3518e75600             lea       esi, [0x56e718] ; bits=00000000, f32=0.0
00431909  8d3dccdb5600             lea       edi, [0x56dbcc] ; bits=4c495052, f32=223645728768.0
0043190f  b906000000               mov       ecx, 6
00431914  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00431916  0f85d8000000             jne       0x4319f4
0043191c  68bce25600               push      0x56e2bc
00431921  e82a020700               call      0x4a1b50 ; _jwe_iinf
00431926  83c404                   add       esp, 4
00431929  85c0                     test      eax, eax
0043192b  0f8564140000             jne       0x432d95
00431931  68a4e25600               push      0x56e2a4
00431936  e815020700               call      0x4a1b50 ; _jwe_iinf
0043193b  83c404                   add       esp, 4
0043193e  85c0                     test      eax, eax
00431940  0f854f140000             jne       0x432d95
00431946  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
0043194c  8b08                     mov       ecx, dword ptr [eax]
0043194e  8b1538e65600             mov       edx, dword ptr [0x56e638] ; bits=00000000, f32=0.0
00431954  8d3578e25600             lea       esi, [0x56e278] ; bits=09020000, f32=7.300764999132297e-43
0043195a  894dfc                   mov       dword ptr [ebp - 4], ecx
0043195d  8d4dfc                   lea       ecx, [ebp - 4]
00431960  894e08                   mov       dword ptr [esi + 8], ecx
00431963  8955f4                   mov       dword ptr [ebp - 0xc], edx
00431966  8d4df4                   lea       ecx, [ebp - 0xc]
00431969  894e28                   mov       dword ptr [esi + 0x28], ecx
0043196c  56                       push      esi
0043196d  e87e0c0700               call      0x4a25f0 ; _jwe_isfm
00431972  83c404                   add       esp, 4
00431975  6a78                     push      0x78
00431977  6818e75600               push      0x56e718
0043197c  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431982  8d08                     lea       ecx, [eax]
00431984  51                       push      ecx
00431985  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
0043198b  8d11                     lea       edx, [ecx]
0043198d  52                       push      edx
0043198e  e84daf0100               call      0x44c8e0 ; _inline_
00431993  83c410                   add       esp, 0x10
00431996  6858e25600               push      0x56e258
0043199b  e8b0010700               call      0x4a1b50 ; _jwe_iinf
004319a0  83c404                   add       esp, 4
004319a3  85c0                     test      eax, eax
004319a5  0f85ea130000             jne       0x432d95
004319ab  6840e25600               push      0x56e240
004319b0  e89b010700               call      0x4a1b50 ; _jwe_iinf
004319b5  83c404                   add       esp, 4
004319b8  85c0                     test      eax, eax
004319ba  0f85d5130000             jne       0x432d95
004319c0  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004319c6  8b08                     mov       ecx, dword ptr [eax]
004319c8  8b153ce65600             mov       edx, dword ptr [0x56e63c] ; bits=00000000, f32=0.0
004319ce  8d3514e25600             lea       esi, [0x56e214] ; bits=09020000, f32=7.300764999132297e-43
004319d4  894dfc                   mov       dword ptr [ebp - 4], ecx
004319d7  8d4dfc                   lea       ecx, [ebp - 4]
004319da  894e08                   mov       dword ptr [esi + 8], ecx
004319dd  8955f4                   mov       dword ptr [ebp - 0xc], edx
004319e0  8d4df4                   lea       ecx, [ebp - 0xc]
004319e3  894e28                   mov       dword ptr [esi + 0x28], ecx
004319e6  56                       push      esi
004319e7  e8040c0700               call      0x4a25f0 ; _jwe_isfm
004319ec  83c404                   add       esp, 4
004319ef  e9fd000000               jmp       0x431af1
004319f4  bb01000000               mov       ebx, 1
004319f9  e9f3000000               jmp       0x431af1
004319fe  8d3518e75600             lea       esi, [0x56e718] ; bits=00000000, f32=0.0
00431a04  8d3dccdb5600             lea       edi, [0x56dbcc] ; bits=4c495052, f32=223645728768.0
00431a0a  b906000000               mov       ecx, 6
00431a0f  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00431a11  0f85d5000000             jne       0x431aec
00431a17  68f4e15600               push      0x56e1f4
00431a1c  e82f010700               call      0x4a1b50 ; _jwe_iinf
00431a21  83c404                   add       esp, 4
00431a24  85c0                     test      eax, eax
00431a26  0f8569130000             jne       0x432d95
00431a2c  68dce15600               push      0x56e1dc
00431a31  e81a010700               call      0x4a1b50 ; _jwe_iinf
00431a36  83c404                   add       esp, 4
00431a39  85c0                     test      eax, eax
00431a3b  0f8554130000             jne       0x432d95
00431a41  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431a47  8b08                     mov       ecx, dword ptr [eax]
00431a49  8b1538e65600             mov       edx, dword ptr [0x56e638] ; bits=00000000, f32=0.0
00431a4f  8d35b0e15600             lea       esi, [0x56e1b0] ; bits=09020000, f32=7.300764999132297e-43
00431a55  894dfc                   mov       dword ptr [ebp - 4], ecx
00431a58  8d4dfc                   lea       ecx, [ebp - 4]
00431a5b  894e08                   mov       dword ptr [esi + 8], ecx
00431a5e  8955f4                   mov       dword ptr [ebp - 0xc], edx
00431a61  8d4df4                   lea       ecx, [ebp - 0xc]
00431a64  894e28                   mov       dword ptr [esi + 0x28], ecx
00431a67  56                       push      esi
00431a68  e8830b0700               call      0x4a25f0 ; _jwe_isfm
00431a6d  83c404                   add       esp, 4
00431a70  6a78                     push      0x78
00431a72  6818e75600               push      0x56e718
00431a77  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431a7d  8d08                     lea       ecx, [eax]
00431a7f  51                       push      ecx
00431a80  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
00431a86  8d11                     lea       edx, [ecx]
00431a88  52                       push      edx
00431a89  e852ae0100               call      0x44c8e0 ; _inline_
00431a8e  83c410                   add       esp, 0x10
00431a91  6890e15600               push      0x56e190
00431a96  e8b5000700               call      0x4a1b50 ; _jwe_iinf
00431a9b  83c404                   add       esp, 4
00431a9e  85c0                     test      eax, eax
00431aa0  0f85ef120000             jne       0x432d95
00431aa6  6878e15600               push      0x56e178
00431aab  e8a0000700               call      0x4a1b50 ; _jwe_iinf
00431ab0  83c404                   add       esp, 4
00431ab3  85c0                     test      eax, eax
00431ab5  0f85da120000             jne       0x432d95
00431abb  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431ac1  8b08                     mov       ecx, dword ptr [eax]
00431ac3  8b153ce65600             mov       edx, dword ptr [0x56e63c] ; bits=00000000, f32=0.0
00431ac9  8d354ce15600             lea       esi, [0x56e14c] ; bits=09020000, f32=7.300764999132297e-43
00431acf  894dfc                   mov       dword ptr [ebp - 4], ecx
00431ad2  8d4dfc                   lea       ecx, [ebp - 4]
00431ad5  894e08                   mov       dword ptr [esi + 8], ecx
00431ad8  8955f4                   mov       dword ptr [ebp - 0xc], edx
00431adb  8d4df4                   lea       ecx, [ebp - 0xc]
00431ade  894e28                   mov       dword ptr [esi + 0x28], ecx
00431ae1  56                       push      esi
00431ae2  e8090b0700               call      0x4a25f0 ; _jwe_isfm
00431ae7  83c404                   add       esp, 4
00431aea  eb05                     jmp       0x431af1
00431aec  bb01000000               mov       ebx, 1
00431af1  b801000000               mov       eax, 1
00431af6  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431afc  85db                     test      ebx, ebx
00431afe  7521                     jne       0x431b21
00431b00  6a78                     push      0x78
00431b02  6818e75600               push      0x56e718
00431b07  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431b0d  8d08                     lea       ecx, [eax]
00431b0f  51                       push      ecx
00431b10  8b8d44ffffff             mov       ecx, dword ptr [ebp - 0xbc]
00431b16  8d11                     lea       edx, [ecx]
00431b18  52                       push      edx
00431b19  e8c2ad0100               call      0x44c8e0 ; _inline_
00431b1e  83c410                   add       esp, 0x10
00431b21  bb00000000               mov       ebx, 0
00431b26  682ce15600               push      0x56e12c
00431b2b  e820000700               call      0x4a1b50 ; _jwe_iinf
00431b30  83c404                   add       esp, 4
00431b33  85c0                     test      eax, eax
00431b35  0f855a120000             jne       0x432d95
00431b3b  8b8d20ffffff             mov       ecx, dword ptr [ebp - 0xe0]
00431b41  8d0520e15600             lea       eax, [0x56e120] ; bits=61090000, f32=3.364517612843886e-42
00431b47  8d148d285a6e00           lea       edx, [ecx*4 + 0x6e5a28]
00431b4e  895008                   mov       dword ptr [eax + 8], edx
00431b51  50                       push      eax
00431b52  e8f9ff0600               call      0x4a1b50 ; _jwe_iinf
00431b57  83c404                   add       esp, 4
00431b5a  85c0                     test      eax, eax
00431b5c  0f8533120000             jne       0x432d95
00431b62  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431b68  8b08                     mov       ecx, dword ptr [eax]
00431b6a  8b9520ffffff             mov       edx, dword ptr [ebp - 0xe0]
00431b70  898d1cffffff             mov       dword ptr [ebp - 0xe4], ecx
00431b76  8b3495285a6e00           mov       esi, dword ptr [edx*4 + 0x6e5a28]
00431b7d  8d3df4e05600             lea       edi, [0x56e0f4] ; bits=09020000, f32=7.300764999132297e-43
00431b83  894dfc                   mov       dword ptr [ebp - 4], ecx
00431b86  8d45fc                   lea       eax, [ebp - 4]
00431b89  894708                   mov       dword ptr [edi + 8], eax
00431b8c  8975f4                   mov       dword ptr [ebp - 0xc], esi
00431b8f  8d45f4                   lea       eax, [ebp - 0xc]
00431b92  894728                   mov       dword ptr [edi + 0x28], eax
00431b95  57                       push      edi
00431b96  e8550a0700               call      0x4a25f0 ; _jwe_isfm
00431b9b  83c404                   add       esp, 4
00431b9e  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431ba4  d90485285a6e00           fld       dword ptr [eax*4 + 0x6e5a28]
00431bab  d81d48da5600             fcomp     dword ptr [0x56da48] ; bits=00000000, f32=0.0
00431bb1  dfe0                     fnstsw    ax
00431bb3  9e                       sahf
00431bb4  0f8a11000000             jp        0x431bcb
00431bba  770f                     ja        0x431bcb
00431bbc  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431bc2  48                       dec       eax
00431bc3  890500e65600             mov       dword ptr [0x56e600], eax ; bits=00000000, f32=0.0
00431bc9  eb51                     jmp       0x431c1c
00431bcb  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431bd1  40                       inc       eax
00431bd2  3d97000000               cmp       eax, 0x97
00431bd7  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431bdd  0f8e19ffffff             jle       0x431afc
00431be3  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431be9  8b08                     mov       ecx, dword ptr [eax]
00431beb  8d15c8e05600             lea       edx, [0x56e0c8] ; bits=09020000, f32=7.300764999132297e-43
00431bf1  894dfc                   mov       dword ptr [ebp - 4], ecx
00431bf4  8d4dfc                   lea       ecx, [ebp - 4]
00431bf7  894a08                   mov       dword ptr [edx + 8], ecx
00431bfa  52                       push      edx
00431bfb  e8f0090700               call      0x4a25f0 ; _jwe_isfm
00431c00  83c404                   add       esp, 4
00431c03  b897000000               mov       eax, 0x97
00431c08  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
00431c0b  c70101000000             mov       dword ptr [ecx], 1
00431c11  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431c17  e9e0feffff               jmp       0x431afc
00431c1c  8b1500e65600             mov       edx, dword ptr [0x56e600] ; bits=00000000, f32=0.0
00431c22  83fa00                   cmp       edx, 0
00431c25  7e6d                     jle       0x431c94
00431c27  b801000000               mov       eax, 1
00431c2c  83fa02                   cmp       edx, 2
00431c2f  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431c35  7c3f                     jl        0x431c76
00431c37  d90550e65600             fld       dword ptr [0x56e650] ; bits=00000000, f32=0.0
00431c3d  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431c43  d9c0                     fld       st(0)
00431c45  d80c85285a6e00           fmul      dword ptr [eax*4 + 0x6e5a28]
00431c4c  d9c9                     fxch      st(1)
00431c4e  d80c852c5a6e00           fmul      dword ptr [eax*4 + 0x6e5a2c]
00431c55  d9c9                     fxch      st(1)
00431c57  d91c85285a6e00           fstp      dword ptr [eax*4 + 0x6e5a28]
00431c5e  d91c852c5a6e00           fstp      dword ptr [eax*4 + 0x6e5a2c]
00431c65  83c002                   add       eax, 2
00431c68  83ea02                   sub       edx, 2
00431c6b  83fa02                   cmp       edx, 2
00431c6e  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431c74  7dc1                     jge       0x431c37
00431c76  85d2                     test      edx, edx
00431c78  741a                     je        0x431c94
00431c7a  d90550e65600             fld       dword ptr [0x56e650] ; bits=00000000, f32=0.0
00431c80  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431c86  d80c85285a6e00           fmul      dword ptr [eax*4 + 0x6e5a28]
00431c8d  d91c85285a6e00           fstp      dword ptr [eax*4 + 0x6e5a28]
00431c94  d9e8                     fld1
00431c96  d91d04bbf400             fstp      dword ptr [0xf4bb04]
00431c9c  813df8e556005e010000     cmp       dword ptr [0x56e5f8], 0x15e ; bits=00000000, f32=0.0
00431ca6  7e27                     jle       0x431ccf
00431ca8  8d059ce05600             lea       eax, [0x56e09c] ; bits=09020000, f32=7.300764999132297e-43
00431cae  8b8d1cffffff             mov       ecx, dword ptr [ebp - 0xe4]
00431cb4  894dfc                   mov       dword ptr [ebp - 4], ecx
00431cb7  8d4dfc                   lea       ecx, [ebp - 4]
00431cba  894808                   mov       dword ptr [eax + 8], ecx
00431cbd  50                       push      eax
00431cbe  e82d090700               call      0x4a25f0 ; _jwe_isfm
00431cc3  83c404                   add       esp, 4
00431cc6  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00431cc9  c70001000000             mov       dword ptr [eax], 1
00431ccf  8b5518                   mov       edx, dword ptr [ebp + 0x18]
00431cd2  833a00                   cmp       dword ptr [edx], 0
00431cd5  0f8f03110000             jg        0x432dde
00431cdb  d90538e65600             fld       dword ptr [0x56e638] ; bits=00000000, f32=0.0
00431ce1  d9ee                     fldz
00431ce3  d9c9                     fxch      st(1)
00431ce5  dde9                     fucomp    st(1)
00431ce7  dfe0                     fnstsw    ax
00431ce9  9e                       sahf
00431cea  0f8afa000000             jp        0x431dea
00431cf0  0f85f4000000             jne       0x431dea
00431cf6  8b1df8e55600             mov       ebx, dword ptr [0x56e5f8] ; bits=00000000, f32=0.0
00431cfc  83fb00                   cmp       ebx, 0
00431cff  0f8e25010000             jle       0x431e2a
00431d05  b801000000               mov       eax, 1
00431d0a  89d9                     mov       ecx, ebx
00431d0c  49                       dec       ecx
00431d0d  894dfc                   mov       dword ptr [ebp - 4], ecx
00431d10  d9e8                     fld1
00431d12  da75fc                   fidiv     dword ptr [ebp - 4]
00431d15  db7db0                   fstp      xword ptr [ebp - 0x50]
00431d18  db7da4                   fstp      xword ptr [ebp - 0x5c]
00431d1b  83fb02                   cmp       ebx, 2
00431d1e  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431d24  0f8c91000000             jl        0x431dbb
00431d2a  db6da4                   fld       xword ptr [ebp - 0x5c]
00431d2d  db6db0                   fld       xword ptr [ebp - 0x50]
00431d30  db7dbc                   fstp      xword ptr [ebp - 0x44]
00431d33  db7dc8                   fstp      xword ptr [ebp - 0x38]
00431d36  db6dc8                   fld       xword ptr [ebp - 0x38]
00431d39  db6dbc                   fld       xword ptr [ebp - 0x44]
00431d3c  dec9                     fmulp     st(1)
00431d3e  682ce65600               push      0x56e62c
00431d43  d95df4                   fstp      dword ptr [ebp - 0xc]
00431d46  8d45f4                   lea       eax, [ebp - 0xc]
00431d49  50                       push      eax
00431d4a  e861ea0600               call      0x4a07b0 ; _g_arxr
00431d4f  83c408                   add       esp, 8
00431d52  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431d58  d91c85845c6e00           fstp      dword ptr [eax*4 + 0x6e5c84]
00431d5f  db6dc8                   fld       xword ptr [ebp - 0x38]
00431d62  d80564da5600             fadd      dword ptr [0x56da64] ; bits=0000803f, f32=1.0
00431d68  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00431d6b  db6dd4                   fld       xword ptr [ebp - 0x2c]
00431d6e  db6dbc                   fld       xword ptr [ebp - 0x44]
00431d71  dec9                     fmulp     st(1)
00431d73  d95df4                   fstp      dword ptr [ebp - 0xc]
00431d76  682ce65600               push      0x56e62c
00431d7b  8d4df4                   lea       ecx, [ebp - 0xc]
00431d7e  51                       push      ecx
00431d7f  e82cea0600               call      0x4a07b0 ; _g_arxr
00431d84  83c408                   add       esp, 8
00431d87  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431d8d  d91c85885c6e00           fstp      dword ptr [eax*4 + 0x6e5c88]
00431d94  db6dd4                   fld       xword ptr [ebp - 0x2c]
00431d97  d80564da5600             fadd      dword ptr [0x56da64] ; bits=0000803f, f32=1.0
00431d9d  db6dbc                   fld       xword ptr [ebp - 0x44]
00431da0  83c002                   add       eax, 2
00431da3  83eb02                   sub       ebx, 2
00431da6  83fb02                   cmp       ebx, 2
00431da9  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431daf  0f8d7bffffff             jge       0x431d30
00431db5  db7db0                   fstp      xword ptr [ebp - 0x50]
00431db8  db7da4                   fstp      xword ptr [ebp - 0x5c]
00431dbb  85db                     test      ebx, ebx
00431dbd  746d                     je        0x431e2c
00431dbf  db6da4                   fld       xword ptr [ebp - 0x5c]
00431dc2  db6db0                   fld       xword ptr [ebp - 0x50]
00431dc5  dec9                     fmulp     st(1)
00431dc7  d95df4                   fstp      dword ptr [ebp - 0xc]
00431dca  682ce65600               push      0x56e62c
00431dcf  8d45f4                   lea       eax, [ebp - 0xc]
00431dd2  50                       push      eax
00431dd3  e8d8e90600               call      0x4a07b0 ; _g_arxr
00431dd8  83c408                   add       esp, 8
00431ddb  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431de1  d91c85845c6e00           fstp      dword ptr [eax*4 + 0x6e5c84]
00431de8  eb42                     jmp       0x431e2c
00431dea  ddd8                     fstp      st(0)
00431dec  8d02                     lea       eax, [edx]
00431dee  50                       push      eax
00431def  68885c6e00               push      0x6e5c88
00431df4  68f8e55600               push      0x56e5f8
00431df9  682c5a6e00               push      0x6e5a2c
00431dfe  6800e65600               push      0x56e600
00431e03  685ce65600               push      0x56e65c
00431e08  6804e65600               push      0x56e604
00431e0d  683ce65600               push      0x56e63c
00431e12  6838e65600               push      0x56e638
00431e17  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431e1d  8d08                     lea       ecx, [eax]
00431e1f  51                       push      ecx
00431e20  e8cb0f0000               call      0x432df0 ; _embankq_opt_
00431e25  83c428                   add       esp, 0x28
00431e28  eb02                     jmp       0x431e2c
00431e2a  ddd8                     fstp      st(0)
00431e2c  833d04e6560000           cmp       dword ptr [0x56e604], 0 ; bits=00000000, f32=0.0
00431e33  0f8e07010000             jle       0x431f40
00431e39  8b1df8e55600             mov       ebx, dword ptr [0x56e5f8] ; bits=00000000, f32=0.0
00431e3f  8d041b                   lea       eax, [ebx + ebx]
00431e42  83e802                   sub       eax, 2
00431e45  8905fce55600             mov       dword ptr [0x56e5fc], eax ; bits=00000000, f32=0.0
00431e4b  813dfce556005e010000     cmp       dword ptr [0x56e5fc], 0x15e ; bits=00000000, f32=0.0
00431e55  7e2e                     jle       0x431e85
00431e57  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00431e5d  8b08                     mov       ecx, dword ptr [eax]
00431e5f  8d0570e05600             lea       eax, [0x56e070] ; bits=09020000, f32=7.300764999132297e-43
00431e65  894dfc                   mov       dword ptr [ebp - 4], ecx
00431e68  8d4dfc                   lea       ecx, [ebp - 4]
00431e6b  894808                   mov       dword ptr [eax + 8], ecx
00431e6e  50                       push      eax
00431e6f  e87c070700               call      0x4a25f0 ; _jwe_isfm
00431e74  83c404                   add       esp, 4
00431e77  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00431e7a  c70001000000             mov       dword ptr [eax], 1
00431e80  e9590f0000               jmp       0x432dde
00431e85  8b15fce55600             mov       edx, dword ptr [0x56e5fc] ; bits=00000000, f32=0.0
00431e8b  89d8                     mov       eax, ebx
00431e8d  89d9                     mov       ecx, ebx
00431e8f  83c1fe                   add       ecx, -2
00431e92  89cb                     mov       ebx, ecx
00431e94  83fb00                   cmp       ebx, 0
00431e97  898518ffffff             mov       dword ptr [ebp - 0xe8], eax
00431e9d  0f8ea9000000             jle       0x431f4c
00431ea3  8b8518ffffff             mov       eax, dword ptr [ebp - 0xe8]
00431ea9  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431eaf  83fb02                   cmp       ebx, 2
00431eb2  7c5e                     jl        0x431f12
00431eb4  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431eba  d90485845c6e00           fld       dword ptr [eax*4 + 0x6e5c84]
00431ec1  d91495845c6e00           fst       dword ptr [edx*4 + 0x6e5c84]
00431ec8  d80485805c6e00           fadd      dword ptr [eax*4 + 0x6e5c80]
00431ecf  d80d5cda5600             fmul      dword ptr [0x56da5c] ; bits=0000003f, f32=0.5
00431ed5  d91c95805c6e00           fstp      dword ptr [edx*4 + 0x6e5c80]
00431edc  d90485805c6e00           fld       dword ptr [eax*4 + 0x6e5c80]
00431ee3  d914957c5c6e00           fst       dword ptr [edx*4 + 0x6e5c7c]
00431eea  d804857c5c6e00           fadd      dword ptr [eax*4 + 0x6e5c7c]
00431ef1  d80d5cda5600             fmul      dword ptr [0x56da5c] ; bits=0000003f, f32=0.5
00431ef7  83c0fe                   add       eax, -2
00431efa  d91c95785c6e00           fstp      dword ptr [edx*4 + 0x6e5c78]
00431f01  83ea04                   sub       edx, 4
00431f04  83eb02                   sub       ebx, 2
00431f07  83fb02                   cmp       ebx, 2
00431f0a  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431f10  7da2                     jge       0x431eb4
00431f12  85db                     test      ebx, ebx
00431f14  7436                     je        0x431f4c
00431f16  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431f1c  d90485845c6e00           fld       dword ptr [eax*4 + 0x6e5c84]
00431f23  d91495845c6e00           fst       dword ptr [edx*4 + 0x6e5c84]
00431f2a  d80485805c6e00           fadd      dword ptr [eax*4 + 0x6e5c80]
00431f31  d80d5cda5600             fmul      dword ptr [0x56da5c] ; bits=0000003f, f32=0.5
00431f37  d91c95805c6e00           fstp      dword ptr [edx*4 + 0x6e5c80]
00431f3e  eb0c                     jmp       0x431f4c
00431f40  8b05f8e55600             mov       eax, dword ptr [0x56e5f8] ; bits=00000000, f32=0.0
00431f46  8905fce55600             mov       dword ptr [0x56e5fc], eax ; bits=00000000, f32=0.0
00431f4c  d9ee                     fldz
00431f4e  b800000000               mov       eax, 0
00431f53  898514ffffff             mov       dword ptr [ebp - 0xec], eax
00431f59  898510ffffff             mov       dword ptr [ebp - 0xf0], eax
00431f5f  89850cffffff             mov       dword ptr [ebp - 0xf4], eax
00431f65  d9c0                     fld       st(0)
00431f67  db7d98                   fstp      xword ptr [ebp - 0x68]
00431f6a  d9ee                     fldz
00431f6c  dd5d90                   fstp      qword ptr [ebp - 0x70]
00431f6f  db7d84                   fstp      xword ptr [ebp - 0x7c]
00431f72  898508ffffff             mov       dword ptr [ebp - 0xf8], eax
00431f78  8b0500e65600             mov       eax, dword ptr [0x56e600] ; bits=00000000, f32=0.0
00431f7e  3d00000000               cmp       eax, 0
00431f83  898504ffffff             mov       dword ptr [ebp - 0xfc], eax
00431f89  0f8eee080000             jle       0x43287d
00431f8f  b801000000               mov       eax, 1
00431f94  8b0df8e55600             mov       ecx, dword ptr [0x56e5f8] ; bits=00000000, f32=0.0
00431f9a  8d14c9                   lea       edx, [ecx + ecx*8]
00431f9d  8d1451                   lea       edx, [ecx + edx*2]
00431fa0  c1e203                   shl       edx, 3
00431fa3  29ca                     sub       edx, ecx
00431fa5  899500ffffff             mov       dword ptr [ebp - 0x100], edx
00431fab  db6d84                   fld       xword ptr [ebp - 0x7c]
00431fae  dd4590                   fld       qword ptr [ebp - 0x70]
00431fb1  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00431fb7  c70590bbf40000000000     mov       dword ptr [0xf4bb90], 0 ; _embq_
00431fc1  c70594bbf40000000000     mov       dword ptr [0xf4bb94], 0
00431fcb  c70530e6560000000000     mov       dword ptr [0x56e630], 0 ; bits=00000000, f32=0.0
00431fd5  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00431fdb  8b0c85285a6e00           mov       ecx, dword ptr [eax*4 + 0x6e5a28]
00431fe2  890d24e65600             mov       dword ptr [0x56e624], ecx ; bits=00000000, f32=0.0
00431fe8  c7048500626e0000000000   mov       dword ptr [eax*4 + 0x6e6200], 0
00431ff3  3d01000000               cmp       eax, 1
00431ff8  0f8516010000             jne       0x432114
00431ffe  db7dc8                   fstp      xword ptr [ebp - 0x38]
00432001  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00432004  6a08                     push      8
00432006  6818e65600               push      0x56e618
0043200b  6828e65600               push      0x56e628
00432010  6830e65600               push      0x56e630
00432015  6864abf400               push      0xf4ab64
0043201a  68c49bf400               push      0xf49bc4
0043201f  68248cf400               push      0xf48c24
00432024  68847cf400               push      0xf47c84
00432029  68e46cf400               push      0xf46ce4
0043202e  68445df400               push      0xf45d44
00432033  68a44df400               push      0xf44da4
00432038  68043ef400               push      0xf43e04
0043203d  68642ef400               push      0xf42e64
00432042  68c41ef400               push      0xf41ec4
00432047  68240ff400               push      0xf40f24
0043204c  6884fff300               push      0xf3ff84
00432051  68e4eff300               push      0xf3efe4
00432056  6844e0f300               push      0xf3e044
0043205b  68a4d0f300               push      0xf3d0a4
00432060  6804c1f300               push      0xf3c104
00432065  6864b1f300               push      0xf3b164
0043206a  68c4a1f300               push      0xf3a1c4
0043206f  682492f300               push      0xf39224
00432074  688482f300               push      0xf38284
00432079  68e472f300               push      0xf372e4
0043207e  684463f300               push      0xf36344
00432083  68a453f300               push      0xf353a4
00432088  681ce65600               push      0x56e61c
0043208d  6894bbf400               push      0xf4bb94
00432092  6890bbf400               push      0xf4bb90 ; _embq_
00432097  689cbbf400               push      0xf4bb9c
0043209c  6898bbf400               push      0xf4bb98
004320a1  6804bbf400               push      0xf4bb04
004320a6  68c0f5f200               push      0xf2f5c0 ; _embcmc_
004320ab  680444f300               push      0xf34404
004320b0  686434f300               push      0xf33464
004320b5  68c424f300               push      0xf324c4
004320ba  682415f300               push      0xf31524
004320bf  680015f300               push      0xf31500 ; _embcom_
004320c4  681415f300               push      0xf31514
004320c9  681015f300               push      0xf31510
004320ce  680c15f300               push      0xf3150c
004320d3  680815f300               push      0xf31508
004320d8  682015f300               push      0xf31520
004320dd  6824e65600               push      0x56e624
004320e2  e819dfffff               call      0x430000 ; _frfemb_
004320e7  db6dd4                   fld       xword ptr [ebp - 0x2c]
004320ea  db6dc8                   fld       xword ptr [ebp - 0x38]
004320ed  81c4b4000000             add       esp, 0xb4
004320f3  8b8d00ffffff             mov       ecx, dword ptr [ebp - 0x100]
004320f9  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
004320ff  8d1401                   lea       edx, [ecx + eax]
00432102  8b1d30e65600             mov       ebx, dword ptr [0x56e630] ; bits=00000000, f32=0.0
00432108  891c95a45f6e00           mov       dword ptr [edx*4 + 0x6e5fa4], ebx
0043210f  e978030000               jmp       0x43248c
00432114  db7dbc                   fstp      xword ptr [ebp - 0x44]
00432117  db7dc8                   fstp      xword ptr [ebp - 0x38]
0043211a  d90524e65600             fld       dword ptr [0x56e624] ; bits=00000000, f32=0.0
00432120  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00432126  d80485245a6e00           fadd      dword ptr [eax*4 + 0x6e5a24]
0043212d  8d1dc0da5600             lea       ebx, [0x56dac0] ; bits=31110000, f32=6.16711454149352e-42
00432133  d84b9c                   fmul      dword ptr [ebx - 0x64]
00432136  d91d40e65600             fstp      dword ptr [0x56e640] ; bits=00000000, f32=0.0
0043213c  6a08                     push      8
0043213e  6818e65600               push      0x56e618
00432143  6828e65600               push      0x56e628
00432148  6844e65600               push      0x56e644
0043214d  6864abf400               push      0xf4ab64
00432152  68c49bf400               push      0xf49bc4
00432157  68248cf400               push      0xf48c24
0043215c  68847cf400               push      0xf47c84
00432161  68e46cf400               push      0xf46ce4
00432166  68445df400               push      0xf45d44
0043216b  68a44df400               push      0xf44da4
00432170  68043ef400               push      0xf43e04
00432175  68642ef400               push      0xf42e64
0043217a  68c41ef400               push      0xf41ec4
0043217f  68240ff400               push      0xf40f24
00432184  6884fff300               push      0xf3ff84
00432189  68e4eff300               push      0xf3efe4
0043218e  6844e0f300               push      0xf3e044
00432193  68a4d0f300               push      0xf3d0a4
00432198  6804c1f300               push      0xf3c104
0043219d  6864b1f300               push      0xf3b164
004321a2  68c4a1f300               push      0xf3a1c4
004321a7  682492f300               push      0xf39224
004321ac  688482f300               push      0xf38284
004321b1  68e472f300               push      0xf372e4
004321b6  684463f300               push      0xf36344
004321bb  68a453f300               push      0xf353a4
004321c0  681ce65600               push      0x56e61c
004321c5  6894bbf400               push      0xf4bb94
004321ca  6890bbf400               push      0xf4bb90 ; _embq_
004321cf  689cbbf400               push      0xf4bb9c
004321d4  6898bbf400               push      0xf4bb98
004321d9  6804bbf400               push      0xf4bb04
004321de  68c0f5f200               push      0xf2f5c0 ; _embcmc_
004321e3  680444f300               push      0xf34404
004321e8  686434f300               push      0xf33464
004321ed  68c424f300               push      0xf324c4
004321f2  682415f300               push      0xf31524
004321f7  680015f300               push      0xf31500 ; _embcom_
004321fc  681415f300               push      0xf31514
00432201  681015f300               push      0xf31510
00432206  680c15f300               push      0xf3150c
0043220b  680815f300               push      0xf31508
00432210  682015f300               push      0xf31520
00432215  6840e65600               push      0x56e640
0043221a  e8e1ddffff               call      0x430000 ; _frfemb_
0043221f  81c4b4000000             add       esp, 0xb4
00432225  6a08                     push      8
00432227  6818e65600               push      0x56e618
0043222c  6828e65600               push      0x56e628
00432231  6830e65600               push      0x56e630
00432236  6864abf400               push      0xf4ab64
0043223b  68c49bf400               push      0xf49bc4
00432240  68248cf400               push      0xf48c24
00432245  68847cf400               push      0xf47c84
0043224a  68e46cf400               push      0xf46ce4
0043224f  68445df400               push      0xf45d44
00432254  68a44df400               push      0xf44da4
00432259  68043ef400               push      0xf43e04
0043225e  68642ef400               push      0xf42e64
00432263  68c41ef400               push      0xf41ec4
00432268  68240ff400               push      0xf40f24
0043226d  6884fff300               push      0xf3ff84
00432272  68e4eff300               push      0xf3efe4
00432277  6844e0f300               push      0xf3e044
0043227c  68a4d0f300               push      0xf3d0a4
00432281  6804c1f300               push      0xf3c104
00432286  6864b1f300               push      0xf3b164
0043228b  68c4a1f300               push      0xf3a1c4
00432290  682492f300               push      0xf39224
00432295  688482f300               push      0xf38284
0043229a  68e472f300               push      0xf372e4
0043229f  684463f300               push      0xf36344
004322a4  68a453f300               push      0xf353a4
004322a9  681ce65600               push      0x56e61c
004322ae  6894bbf400               push      0xf4bb94
004322b3  6890bbf400               push      0xf4bb90 ; _embq_
004322b8  689cbbf400               push      0xf4bb9c
004322bd  6898bbf400               push      0xf4bb98
004322c2  6804bbf400               push      0xf4bb04
004322c7  68c0f5f200               push      0xf2f5c0 ; _embcmc_
004322cc  680444f300               push      0xf34404
004322d1  686434f300               push      0xf33464
004322d6  68c424f300               push      0xf324c4
004322db  682415f300               push      0xf31524
004322e0  680015f300               push      0xf31500 ; _embcom_
004322e5  681415f300               push      0xf31514
004322ea  681015f300               push      0xf31510
004322ef  680c15f300               push      0xf3150c
004322f4  680815f300               push      0xf31508
004322f9  682015f300               push      0xf31520
004322fe  6824e65600               push      0x56e624
00432303  e8f8dcffff               call      0x430000 ; _frfemb_
00432308  81c4b4000000             add       esp, 0xb4
0043230e  8b8d00ffffff             mov       ecx, dword ptr [ebp - 0x100]
00432314  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
0043231a  8d1401                   lea       edx, [ecx + eax]
0043231d  8b3530e65600             mov       esi, dword ptr [0x56e630] ; bits=00000000, f32=0.0
00432323  893495a45f6e00           mov       dword ptr [edx*4 + 0x6e5fa4], esi
0043232a  d90530e65600             fld       dword ptr [0x56e630] ; bits=00000000, f32=0.0
00432330  d80495a05f6e00           fadd      dword ptr [edx*4 + 0x6e5fa0]
00432337  d84b9c                   fmul      dword ptr [ebx - 0x64]
0043233a  d82544e65600             fsub      dword ptr [0x56e644] ; bits=00000000, f32=0.0
00432340  d83544e65600             fdiv      dword ptr [0x56e644] ; bits=00000000, f32=0.0
00432346  dbbd78ffffff             fstp      xword ptr [ebp - 0x88]
0043234c  d90524e65600             fld       dword ptr [0x56e624] ; bits=00000000, f32=0.0
00432352  db6d98                   fld       xword ptr [ebp - 0x68]
00432355  d80524e65600             fadd      dword ptr [0x56e624] ; bits=00000000, f32=0.0
0043235b  d90485245a6e00           fld       dword ptr [eax*4 + 0x6e5a24]
00432362  d9c9                     fxch      st(1)
00432364  d82485245a6e00           fsub      dword ptr [eax*4 + 0x6e5a24]
0043236b  db7d98                   fstp      xword ptr [ebp - 0x68]
0043236e  dbad78ffffff             fld       xword ptr [ebp - 0x88]
00432374  dbad78ffffff             fld       xword ptr [ebp - 0x88]
0043237a  dec9                     fmulp     st(1)
0043237c  d84ba0                   fmul      dword ptr [ebx - 0x60]
0043237f  d9ca                     fxch      st(2)
00432381  dee1                     fsubrp    st(1)
00432383  dec9                     fmulp     st(1)
00432385  db6dbc                   fld       xword ptr [ebp - 0x44]
00432388  dec1                     faddp     st(1)
0043238a  8b9540ffffff             mov       edx, dword ptr [ebp - 0xc0]
00432390  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00432393  8b1a                     mov       ebx, dword ptr [edx]
00432395  8b3485245a6e00           mov       esi, dword ptr [eax*4 + 0x6e5a24]
0043239c  8b3d24e65600             mov       edi, dword ptr [0x56e624] ; bits=00000000, f32=0.0
004323a2  8d0d2ce05600             lea       ecx, [0x56e02c] ; bits=09020000, f32=7.300764999132297e-43
004323a8  895dfc                   mov       dword ptr [ebp - 4], ebx
004323ab  8d5dfc                   lea       ebx, [ebp - 4]
004323ae  895908                   mov       dword ptr [ecx + 8], ebx
004323b1  8975f4                   mov       dword ptr [ebp - 0xc], esi
004323b4  8d5df4                   lea       ebx, [ebp - 0xc]
004323b7  895928                   mov       dword ptr [ecx + 0x28], ebx
004323ba  897df0                   mov       dword ptr [ebp - 0x10], edi
004323bd  8d5df0                   lea       ebx, [ebp - 0x10]
004323c0  895934                   mov       dword ptr [ecx + 0x34], ebx
004323c3  dbad78ffffff             fld       xword ptr [ebp - 0x88]
004323c9  d95dec                   fstp      dword ptr [ebp - 0x14]
004323cc  8d5dec                   lea       ebx, [ebp - 0x14]
004323cf  895940                   mov       dword ptr [ecx + 0x40], ebx
004323d2  51                       push      ecx
004323d3  e818020700               call      0x4a25f0 ; _jwe_isfm
004323d8  83c404                   add       esp, 4
004323db  dbad78ffffff             fld       xword ptr [ebp - 0x88]
004323e1  d9e1                     fabs
004323e3  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
004323e9  d90538e65600             fld       dword ptr [0x56e638] ; bits=00000000, f32=0.0
004323ef  dbbd60ffffff             fstp      xword ptr [ebp - 0xa0]
004323f5  dbad6cffffff             fld       xword ptr [ebp - 0x94]
004323fb  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00432401  d9c9                     fxch      st(1)
00432403  ded9                     fcompp
00432405  db6dc8                   fld       xword ptr [ebp - 0x38]
00432408  db6dd4                   fld       xword ptr [ebp - 0x2c]
0043240b  dfe0                     fnstsw    ax
0043240d  9e                       sahf
0043240e  0f8a40000000             jp        0x432454
00432414  763e                     jbe       0x432454
00432416  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0043241c  d81d48da5600             fcomp     dword ptr [0x56da48] ; bits=00000000, f32=0.0
00432422  dfe0                     fnstsw    ax
00432424  9e                       sahf
00432425  0f8a29000000             jp        0x432454
0043242b  7627                     jbe       0x432454
0043242d  ff8510ffffff             inc       dword ptr [ebp - 0xf0]
00432433  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
00432439  d8c0                     fadd      st(0)
0043243b  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00432441  ded9                     fcompp
00432443  dfe0                     fnstsw    ax
00432445  9e                       sahf
00432446  0f8a08000000             jp        0x432454
0043244c  7606                     jbe       0x432454
0043244e  ff850cffffff             inc       dword ptr [ebp - 0xf4]
00432454  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0043245a  d8da                     fcomp     st(2)
0043245c  dfe0                     fnstsw    ax
0043245e  9e                       sahf
0043245f  0f8a27000000             jp        0x43248c
00432465  7625                     jbe       0x43248c
00432467  ddd9                     fstp      st(1)
00432469  dbad6cffffff             fld       xword ptr [ebp - 0x94]
0043246f  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00432475  d9c9                     fxch      st(1)
00432477  8d48ff                   lea       ecx, [eax - 1]
0043247a  8b15fce55600             mov       edx, dword ptr [0x56e5fc] ; bits=00000000, f32=0.0
00432480  898d08ffffff             mov       dword ptr [ebp - 0xf8], ecx
00432486  899514ffffff             mov       dword ptr [ebp - 0xec], edx
0043248c  db7dc8                   fstp      xword ptr [ebp - 0x38]
0043248f  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00432495  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00432498  8b18                     mov       ebx, dword ptr [eax]
0043249a  8b0d24e65600             mov       ecx, dword ptr [0x56e624] ; bits=00000000, f32=0.0
004324a0  8b1530e65600             mov       edx, dword ptr [0x56e630] ; bits=00000000, f32=0.0
004324a6  8d35f4df5600             lea       esi, [0x56dff4] ; bits=09020000, f32=7.300764999132297e-43
004324ac  895dfc                   mov       dword ptr [ebp - 4], ebx
004324af  8d7dfc                   lea       edi, [ebp - 4]
004324b2  897e08                   mov       dword ptr [esi + 8], edi
004324b5  894df4                   mov       dword ptr [ebp - 0xc], ecx
004324b8  8d4df4                   lea       ecx, [ebp - 0xc]
004324bb  894e28                   mov       dword ptr [esi + 0x28], ecx
004324be  8955f0                   mov       dword ptr [ebp - 0x10], edx
004324c1  8d4df0                   lea       ecx, [ebp - 0x10]
004324c4  894e34                   mov       dword ptr [esi + 0x34], ecx
004324c7  56                       push      esi
004324c8  e823010700               call      0x4a25f0 ; _jwe_isfm
004324cd  db6dd4                   fld       xword ptr [ebp - 0x2c]
004324d0  db6dc8                   fld       xword ptr [ebp - 0x38]
004324d3  83c404                   add       esp, 4
004324d6  833d04e6560000           cmp       dword ptr [0x56e604], 0 ; bits=00000000, f32=0.0
004324dd  0f8e81030000             jle       0x432864
004324e3  db7dc8                   fstp      xword ptr [ebp - 0x38]
004324e6  db7dd4                   fstp      xword ptr [ebp - 0x2c]
004324e9  8d05d4df5600             lea       eax, [0x56dfd4] ; bits=69020000, f32=8.646011524884121e-43
004324ef  895dfc                   mov       dword ptr [ebp - 4], ebx
004324f2  8d4dfc                   lea       ecx, [ebp - 4]
004324f5  894808                   mov       dword ptr [eax + 8], ecx
004324f8  50                       push      eax
004324f9  e8f2000700               call      0x4a25f0 ; _jwe_isfm
004324fe  83c404                   add       esp, 4
00432501  6a08                     push      8
00432503  68289e7100               push      0x719e28
00432508  6820e65600               push      0x56e620
0043250d  68885c6e00               push      0x6e5c88
00432512  6830e65600               push      0x56e630
00432517  68847cf400               push      0xf47c84
0043251c  68e46cf400               push      0xf46ce4
00432521  68445df400               push      0xf45d44
00432526  68a44df400               push      0xf44da4
0043252b  68043ef400               push      0xf43e04
00432530  68642ef400               push      0xf42e64
00432535  68e4eff300               push      0xf3efe4
0043253a  6844e0f300               push      0xf3e044
0043253f  68a4d0f300               push      0xf3d0a4
00432544  6804c1f300               push      0xf3c104
00432549  6864b1f300               push      0xf3b164
0043254e  68c4a1f300               push      0xf3a1c4
00432553  682492f300               push      0xf39224
00432558  688482f300               push      0xf38284
0043255d  68e472f300               push      0xf372e4
00432562  684463f300               push      0xf36344
00432567  68a453f300               push      0xf353a4
0043256c  6898bbf400               push      0xf4bb98
00432571  68c0f5f200               push      0xf2f5c0 ; _embcmc_
00432576  680015f300               push      0xf31500 ; _embcom_
0043257b  681c15f300               push      0xf3151c
00432580  681815f300               push      0xf31518
00432585  681415f300               push      0xf31514
0043258a  681015f300               push      0xf31510
0043258f  680c15f300               push      0xf3150c
00432594  680815f300               push      0xf31508
00432599  680415f300               push      0xf31504
0043259e  682015f300               push      0xf31520
004325a3  6824e65600               push      0x56e624
004325a8  681ce65600               push      0x56e61c
004325ad  68fce55600               push      0x56e5fc
004325b2  e8a9d5ffff               call      0x42fb60 ; _sbfemb_
004325b7  81c490000000             add       esp, 0x90
004325bd  8d0550586e00             lea       eax, [0x6e5850]
004325c3  8b8d20ffffff             mov       ecx, dword ptr [ebp - 0xe0]
004325c9  8b3520e65600             mov       esi, dword ptr [0x56e620] ; bits=00000000, f32=0.0
004325cf  89b4887cffffff           mov       dword ptr [eax + ecx*4 - 0x84], esi
004325d6  6a08                     push      8
004325d8  6898e75600               push      0x56e798
004325dd  8b1dfce55600             mov       ebx, dword ptr [0x56e5fc] ; bits=00000000, f32=0.0
004325e3  8d049d249e7100           lea       eax, [ebx*4 + 0x719e24]
004325ea  50                       push      eax
004325eb  e8c0cc0100               call      0x44f2b0 ; _var_decimal_
004325f0  83c40c                   add       esp, 0xc
004325f3  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004325f9  8b08                     mov       ecx, dword ptr [eax]
004325fb  8b149d845c6e00           mov       edx, dword ptr [ebx*4 + 0x6e5c84]
00432602  d90520e65600             fld       dword ptr [0x56e620] ; bits=00000000, f32=0.0
00432608  d82d24e65600             fsubr     dword ptr [0x56e624] ; bits=00000000, f32=0.0
0043260e  8d3d84df5600             lea       edi, [0x56df84] ; bits=09020000, f32=7.300764999132297e-43
00432614  894dfc                   mov       dword ptr [ebp - 4], ecx
00432617  8d4dfc                   lea       ecx, [ebp - 4]
0043261a  894f08                   mov       dword ptr [edi + 8], ecx
0043261d  8955f4                   mov       dword ptr [ebp - 0xc], edx
00432620  8d4df4                   lea       ecx, [ebp - 0xc]
00432623  894f28                   mov       dword ptr [edi + 0x28], ecx
00432626  8975f0                   mov       dword ptr [ebp - 0x10], esi
00432629  8d4df0                   lea       ecx, [ebp - 0x10]
0043262c  894f34                   mov       dword ptr [edi + 0x34], ecx
0043262f  d95dec                   fstp      dword ptr [ebp - 0x14]
00432632  8d4dec                   lea       ecx, [ebp - 0x14]
00432635  894f40                   mov       dword ptr [edi + 0x40], ecx
00432638  57                       push      edi
00432639  e8b2ff0600               call      0x4a25f0 ; _jwe_isfm
0043263e  db6dd4                   fld       xword ptr [ebp - 0x2c]
00432641  db6dc8                   fld       xword ptr [ebp - 0x38]
00432644  83c404                   add       esp, 4
00432647  89d8                     mov       eax, ebx
00432649  c1f81f                   sar       eax, 0x1f
0043264c  89d9                     mov       ecx, ebx
0043264e  29c1                     sub       ecx, eax
00432650  89c8                     mov       eax, ecx
00432652  d1f8                     sar       eax, 1
00432654  8d0cc0                   lea       ecx, [eax + eax*8]
00432657  8d0c48                   lea       ecx, [eax + ecx*2]
0043265a  89ca                     mov       edx, ecx
0043265c  c1e203                   shl       edx, 3
0043265f  29c2                     sub       edx, eax
00432661  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00432667  01c2                     add       edx, eax
00432669  8b0c9d249e7100           mov       ecx, dword ptr [ebx*4 + 0x719e24]
00432670  890c9500626e00           mov       dword ptr [edx*4 + 0x6e6200], ecx
00432677  89d8                     mov       eax, ebx
00432679  83e802                   sub       eax, 2
0043267c  89c2                     mov       edx, eax
0043267e  f7d8                     neg       eax
00432680  89c6                     mov       esi, eax
00432682  c1fe1f                   sar       esi, 0x1f
00432685  29f0                     sub       eax, esi
00432687  d1f8                     sar       eax, 1
00432689  f7d8                     neg       eax
0043268b  3d00000000               cmp       eax, 0
00432690  8985fcfeffff             mov       dword ptr [ebp - 0x104], eax
00432696  0f8ec8010000             jle       0x432864
0043269c  89d3                     mov       ebx, edx
0043269e  d9c9                     fxch      st(1)
004326a0  db7dc8                   fstp      xword ptr [ebp - 0x38]
004326a3  89d8                     mov       eax, ebx
004326a5  c1f81f                   sar       eax, 0x1f
004326a8  89d9                     mov       ecx, ebx
004326aa  29c1                     sub       ecx, eax
004326ac  89c8                     mov       eax, ecx
004326ae  d1f8                     sar       eax, 1
004326b0  8d0cc0                   lea       ecx, [eax + eax*8]
004326b3  8d0c48                   lea       ecx, [eax + ecx*2]
004326b6  89ca                     mov       edx, ecx
004326b8  c1e203                   shl       edx, 3
004326bb  29c2                     sub       edx, eax
004326bd  039520ffffff             add       edx, dword ptr [ebp - 0xe0]
004326c3  d9049d249e7100           fld       dword ptr [ebx*4 + 0x719e24]
004326ca  d9149500626e00           fst       dword ptr [edx*4 + 0x6e6200]
004326d1  d8049d2c9e7100           fadd      dword ptr [ebx*4 + 0x719e2c]
004326d8  8d05c0da5600             lea       eax, [0x56dac0] ; bits=31110000, f32=6.16711454149352e-42
004326de  d8489c                   fmul      dword ptr [eax - 0x64]
004326e1  d8349d289e7100           fdiv      dword ptr [ebx*4 + 0x719e28]
004326e8  d82564da5600             fsub      dword ptr [0x56da64] ; bits=0000803f, f32=1.0
004326ee  dbbd54ffffff             fstp      xword ptr [ebp - 0xac]
004326f4  d9049d845c6e00           fld       dword ptr [ebx*4 + 0x6e5c84]
004326fb  d9c0                     fld       st(0)
004326fd  d82c9d8c5c6e00           fsubr     dword ptr [ebx*4 + 0x6e5c8c]
00432704  d90520e65600             fld       dword ptr [0x56e620] ; bits=00000000, f32=0.0
0043270a  d9c9                     fxch      st(1)
0043270c  d80d20e65600             fmul      dword ptr [0x56e620] ; bits=00000000, f32=0.0
00432712  db6d98                   fld       xword ptr [ebp - 0x68]
00432715  d8c1                     fadd      st(1)
00432717  db7d98                   fstp      xword ptr [ebp - 0x68]
0043271a  dbad54ffffff             fld       xword ptr [ebp - 0xac]
00432720  dbad54ffffff             fld       xword ptr [ebp - 0xac]
00432726  dec9                     fmulp     st(1)
00432728  d848a0                   fmul      dword ptr [eax - 0x60]
0043272b  dec9                     fmulp     st(1)
0043272d  dec3                     faddp     st(3)
0043272f  d9ca                     fxch      st(2)
00432731  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00432734  dec9                     fmulp     st(1)
00432736  dbbd48ffffff             fstp      xword ptr [ebp - 0xb8]
0043273c  6a08                     push      8
0043273e  6898e75600               push      0x56e798
00432743  8d049d249e7100           lea       eax, [ebx*4 + 0x719e24]
0043274a  50                       push      eax
0043274b  e860cb0100               call      0x44f2b0 ; _var_decimal_
00432750  83c40c                   add       esp, 0xc
00432753  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00432759  8b08                     mov       ecx, dword ptr [eax]
0043275b  8b149d845c6e00           mov       edx, dword ptr [ebx*4 + 0x6e5c84]
00432762  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
00432768  d82d24e65600             fsubr     dword ptr [0x56e624] ; bits=00000000, f32=0.0
0043276e  8d3528df5600             lea       esi, [0x56df28] ; bits=09020000, f32=7.300764999132297e-43
00432774  894dfc                   mov       dword ptr [ebp - 4], ecx
00432777  8d4dfc                   lea       ecx, [ebp - 4]
0043277a  894e08                   mov       dword ptr [esi + 8], ecx
0043277d  8955f4                   mov       dword ptr [ebp - 0xc], edx
00432780  8d4df4                   lea       ecx, [ebp - 0xc]
00432783  894e28                   mov       dword ptr [esi + 0x28], ecx
00432786  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
0043278c  d95df0                   fstp      dword ptr [ebp - 0x10]
0043278f  8d4df0                   lea       ecx, [ebp - 0x10]
00432792  894e34                   mov       dword ptr [esi + 0x34], ecx
00432795  d95dec                   fstp      dword ptr [ebp - 0x14]
00432798  8d4dec                   lea       ecx, [ebp - 0x14]
0043279b  894e40                   mov       dword ptr [esi + 0x40], ecx
0043279e  dbad54ffffff             fld       xword ptr [ebp - 0xac]
004327a4  d95de8                   fstp      dword ptr [ebp - 0x18]
004327a7  8d4de8                   lea       ecx, [ebp - 0x18]
004327aa  894e58                   mov       dword ptr [esi + 0x58], ecx
004327ad  56                       push      esi
004327ae  e83dfe0600               call      0x4a25f0 ; _jwe_isfm
004327b3  83c404                   add       esp, 4
004327b6  dbad54ffffff             fld       xword ptr [ebp - 0xac]
004327bc  d9e1                     fabs
004327be  d90538e65600             fld       dword ptr [0x56e638] ; bits=00000000, f32=0.0
004327c4  d9c9                     fxch      st(1)
004327c6  d81538e65600             fcom      dword ptr [0x56e638] ; bits=00000000, f32=0.0
004327cc  db6dc8                   fld       xword ptr [ebp - 0x38]
004327cf  db6dd4                   fld       xword ptr [ebp - 0x2c]
004327d2  d9ca                     fxch      st(2)
004327d4  d9cb                     fxch      st(3)
004327d6  d9ca                     fxch      st(2)
004327d8  dfe0                     fnstsw    ax
004327da  9e                       sahf
004327db  0f8a3c000000             jp        0x43281d
004327e1  763a                     jbe       0x43281d
004327e3  d9ca                     fxch      st(2)
004327e5  d81548da5600             fcom      dword ptr [0x56da48] ; bits=00000000, f32=0.0
004327eb  d9ca                     fxch      st(2)
004327ed  dfe0                     fnstsw    ax
004327ef  9e                       sahf
004327f0  0f8a2d000000             jp        0x432823
004327f6  762b                     jbe       0x432823
004327f8  ff8510ffffff             inc       dword ptr [ebp - 0xf0]
004327fe  d9ca                     fxch      st(2)
00432800  d8c0                     fadd      st(0)
00432802  d9cb                     fxch      st(3)
00432804  d8d3                     fcom      st(3)
00432806  dddb                     fstp      st(3)
00432808  d9c9                     fxch      st(1)
0043280a  dfe0                     fnstsw    ax
0043280c  9e                       sahf
0043280d  0f8a14000000             jp        0x432827
00432813  7612                     jbe       0x432827
00432815  ff850cffffff             inc       dword ptr [ebp - 0xf4]
0043281b  eb0a                     jmp       0x432827
0043281d  ddda                     fstp      st(2)
0043281f  d9c9                     fxch      st(1)
00432821  eb04                     jmp       0x432827
00432823  ddda                     fstp      st(2)
00432825  d9c9                     fxch      st(1)
00432827  d9ca                     fxch      st(2)
00432829  d8d1                     fcom      st(1)
0043282b  d9ca                     fxch      st(2)
0043282d  dfe0                     fnstsw    ax
0043282f  9e                       sahf
00432830  0f8a1a000000             jp        0x432850
00432836  7618                     jbe       0x432850
00432838  ddd9                     fstp      st(1)
0043283a  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00432840  898508ffffff             mov       dword ptr [ebp - 0xf8], eax
00432846  89d9                     mov       ecx, ebx
00432848  898d14ffffff             mov       dword ptr [ebp - 0xec], ecx
0043284e  eb04                     jmp       0x432854
00432850  ddda                     fstp      st(2)
00432852  d9c9                     fxch      st(1)
00432854  83c3fe                   add       ebx, -2
00432857  83adfcfeffff01           sub       dword ptr [ebp - 0x104], 1
0043285e  0f853afeffff             jne       0x43269e
00432864  ff8520ffffff             inc       dword ptr [ebp - 0xe0]
0043286a  83ad04ffffff01           sub       dword ptr [ebp - 0xfc], 1
00432871  0f8540f7ffff             jne       0x431fb7
00432877  dd5d90                   fstp      qword ptr [ebp - 0x70]
0043287a  db7d84                   fstp      xword ptr [ebp - 0x7c]
0043287d  8b05fce55600             mov       eax, dword ptr [0x56e5fc] ; bits=00000000, f32=0.0
00432883  8b8d14ffffff             mov       ecx, dword ptr [ebp - 0xec]
00432889  39c1                     cmp       ecx, eax
0043288b  7554                     jne       0x4328e1
0043288d  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00432893  8b9508ffffff             mov       edx, dword ptr [ebp - 0xf8]
00432899  8b08                     mov       ecx, dword ptr [eax]
0043289b  8b1c95285a6e00           mov       ebx, dword ptr [edx*4 + 0x6e5a28]
004328a2  8b34952c5a6e00           mov       esi, dword ptr [edx*4 + 0x6e5a2c]
004328a9  8d15e4de5600             lea       edx, [0x56dee4] ; bits=09020000, f32=7.300764999132297e-43
004328af  894dfc                   mov       dword ptr [ebp - 4], ecx
004328b2  8d4dfc                   lea       ecx, [ebp - 4]
004328b5  894a08                   mov       dword ptr [edx + 8], ecx
004328b8  db6d84                   fld       xword ptr [ebp - 0x7c]
004328bb  d95df4                   fstp      dword ptr [ebp - 0xc]
004328be  8d4df4                   lea       ecx, [ebp - 0xc]
004328c1  894a28                   mov       dword ptr [edx + 0x28], ecx
004328c4  895df0                   mov       dword ptr [ebp - 0x10], ebx
004328c7  8d4df0                   lea       ecx, [ebp - 0x10]
004328ca  894a34                   mov       dword ptr [edx + 0x34], ecx
004328cd  8975ec                   mov       dword ptr [ebp - 0x14], esi
004328d0  8d4dec                   lea       ecx, [ebp - 0x14]
004328d3  894a40                   mov       dword ptr [edx + 0x40], ecx
004328d6  52                       push      edx
004328d7  e814fd0600               call      0x4a25f0 ; _jwe_isfm
004328dc  83c404                   add       esp, 4
004328df  eb68                     jmp       0x432949
004328e1  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
004328e7  8b9508ffffff             mov       edx, dword ptr [ebp - 0xf8]
004328ed  8b08                     mov       ecx, dword ptr [eax]
004328ef  8b1c95285a6e00           mov       ebx, dword ptr [edx*4 + 0x6e5a28]
004328f6  8b9514ffffff             mov       edx, dword ptr [ebp - 0xec]
004328fc  8b3495845c6e00           mov       esi, dword ptr [edx*4 + 0x6e5c84]
00432903  8b3c958c5c6e00           mov       edi, dword ptr [edx*4 + 0x6e5c8c]
0043290a  8d1594de5600             lea       edx, [0x56de94] ; bits=09020000, f32=7.300764999132297e-43
00432910  894dfc                   mov       dword ptr [ebp - 4], ecx
00432913  8d4dfc                   lea       ecx, [ebp - 4]
00432916  894a08                   mov       dword ptr [edx + 8], ecx
00432919  db6d84                   fld       xword ptr [ebp - 0x7c]
0043291c  d95df4                   fstp      dword ptr [ebp - 0xc]
0043291f  8d4df4                   lea       ecx, [ebp - 0xc]
00432922  894a28                   mov       dword ptr [edx + 0x28], ecx
00432925  895df0                   mov       dword ptr [ebp - 0x10], ebx
00432928  8d4df0                   lea       ecx, [ebp - 0x10]
0043292b  894a34                   mov       dword ptr [edx + 0x34], ecx
0043292e  8975ec                   mov       dword ptr [ebp - 0x14], esi
00432931  8d4dec                   lea       ecx, [ebp - 0x14]
00432934  894a40                   mov       dword ptr [edx + 0x40], ecx
00432937  897de8                   mov       dword ptr [ebp - 0x18], edi
0043293a  8d4de8                   lea       ecx, [ebp - 0x18]
0043293d  894a4c                   mov       dword ptr [edx + 0x4c], ecx
00432940  52                       push      edx
00432941  e8aafc0600               call      0x4a25f0 ; _jwe_isfm
00432946  83c404                   add       esp, 4
00432949  db6d98                   fld       xword ptr [ebp - 0x68]
0043294c  dc7d90                   fdivr     qword ptr [ebp - 0x70]
0043294f  d9fa                     fsqrt
00432951  d95df4                   fstp      dword ptr [ebp - 0xc]
00432954  8b8d40ffffff             mov       ecx, dword ptr [ebp - 0xc0]
0043295a  8b45f4                   mov       eax, dword ptr [ebp - 0xc]
0043295d  8b11                     mov       edx, dword ptr [ecx]
0043295f  8995f8feffff             mov       dword ptr [ebp - 0x108], edx
00432965  8d1d68de5600             lea       ebx, [0x56de68] ; bits=09020000, f32=7.300764999132297e-43
0043296b  8955fc                   mov       dword ptr [ebp - 4], edx
0043296e  8d75fc                   lea       esi, [ebp - 4]
00432971  897308                   mov       dword ptr [ebx + 8], esi
00432974  8945f4                   mov       dword ptr [ebp - 0xc], eax
00432977  8d45f4                   lea       eax, [ebp - 0xc]
0043297a  894328                   mov       dword ptr [ebx + 0x28], eax
0043297d  53                       push      ebx
0043297e  e86dfc0600               call      0x4a25f0 ; _jwe_isfm
00432983  83c404                   add       esp, 4
00432986  d90538e65600             fld       dword ptr [0x56e638] ; bits=00000000, f32=0.0
0043298c  d81d48da5600             fcomp     dword ptr [0x56da48] ; bits=00000000, f32=0.0
00432992  dfe0                     fnstsw    ax
00432994  9e                       sahf
00432995  0f8a88000000             jp        0x432a23
0043299b  0f8682000000             jbe       0x432a23
004329a1  833d04e6560000           cmp       dword ptr [0x56e604], 0 ; bits=00000000, f32=0.0
004329a8  7e19                     jle       0x4329c3
004329aa  8b0500e65600             mov       eax, dword ptr [0x56e600] ; bits=00000000, f32=0.0
004329b0  8d50ff                   lea       edx, [eax - 1]
004329b3  8b0df8e55600             mov       ecx, dword ptr [0x56e5f8] ; bits=00000000, f32=0.0
004329b9  49                       dec       ecx
004329ba  89cb                     mov       ebx, ecx
004329bc  0fafd8                   imul      ebx, eax
004329bf  01da                     add       edx, ebx
004329c1  eb09                     jmp       0x4329cc
004329c3  8b0500e65600             mov       eax, dword ptr [0x56e600] ; bits=00000000, f32=0.0
004329c9  48                       dec       eax
004329ca  89c2                     mov       edx, eax
004329cc  8b8510ffffff             mov       eax, dword ptr [ebp - 0xf0]
004329d2  8945fc                   mov       dword ptr [ebp - 4], eax
004329d5  db45fc                   fild      dword ptr [ebp - 4]
004329d8  8955fc                   mov       dword ptr [ebp - 4], edx
004329db  db45fc                   fild      dword ptr [ebp - 4]
004329de  d9c9                     fxch      st(1)
004329e0  da75fc                   fidiv     dword ptr [ebp - 4]
004329e3  8b850cffffff             mov       eax, dword ptr [ebp - 0xf4]
004329e9  8945fc                   mov       dword ptr [ebp - 4], eax
004329ec  d9c9                     fxch      st(1)
004329ee  da7dfc                   fidivr    dword ptr [ebp - 4]
004329f1  8d0530de5600             lea       eax, [0x56de30] ; bits=09020000, f32=7.300764999132297e-43
004329f7  8b8df8feffff             mov       ecx, dword ptr [ebp - 0x108]
004329fd  894dfc                   mov       dword ptr [ebp - 4], ecx
00432a00  8d4dfc                   lea       ecx, [ebp - 4]
00432a03  894808                   mov       dword ptr [eax + 8], ecx
00432a06  d9c9                     fxch      st(1)
00432a08  d95df4                   fstp      dword ptr [ebp - 0xc]
00432a0b  8d4df4                   lea       ecx, [ebp - 0xc]
00432a0e  894828                   mov       dword ptr [eax + 0x28], ecx
00432a11  d95df0                   fstp      dword ptr [ebp - 0x10]
00432a14  8d4df0                   lea       ecx, [ebp - 0x10]
00432a17  894834                   mov       dword ptr [eax + 0x34], ecx
00432a1a  50                       push      eax
00432a1b  e8d0fb0600               call      0x4a25f0 ; _jwe_isfm
00432a20  83c404                   add       esp, 4
00432a23  833d04e6560001           cmp       dword ptr [0x56e604], 1 ; bits=00000000, f32=0.0
00432a2a  0f85ed010000             jne       0x432c1d
00432a30  8b05fce55600             mov       eax, dword ptr [0x56e5fc] ; bits=00000000, f32=0.0
00432a36  83c0fe                   add       eax, -2
00432a39  89c3                     mov       ebx, eax
00432a3b  c1fb1f                   sar       ebx, 0x1f
00432a3e  29d8                     sub       eax, ebx
00432a40  d1f8                     sar       eax, 1
00432a42  89c2                     mov       edx, eax
00432a44  83fa00                   cmp       edx, 0
00432a47  0f8e83000000             jle       0x432ad0
00432a4d  b804000000               mov       eax, 4
00432a52  83fa02                   cmp       edx, 2
00432a55  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00432a5b  7c4e                     jl        0x432aab
00432a5d  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00432a63  89c3                     mov       ebx, eax
00432a65  c1fb1f                   sar       ebx, 0x1f
00432a68  89c1                     mov       ecx, eax
00432a6a  29d9                     sub       ecx, ebx
00432a6c  89cb                     mov       ebx, ecx
00432a6e  d1fb                     sar       ebx, 1
00432a70  8b0c85845c6e00           mov       ecx, dword ptr [eax*4 + 0x6e5c84]
00432a77  83c002                   add       eax, 2
00432a7a  89c6                     mov       esi, eax
00432a7c  c1fe1f                   sar       esi, 0x1f
00432a7f  89c7                     mov       edi, eax
00432a81  29f7                     sub       edi, esi
00432a83  d1ff                     sar       edi, 1
00432a85  83ea02                   sub       edx, 2
00432a88  890c9d885c6e00           mov       dword ptr [ebx*4 + 0x6e5c88], ecx
00432a8f  8b0c85845c6e00           mov       ecx, dword ptr [eax*4 + 0x6e5c84]
00432a96  83c002                   add       eax, 2
00432a99  83fa02                   cmp       edx, 2
00432a9c  890cbd885c6e00           mov       dword ptr [edi*4 + 0x6e5c88], ecx
00432aa3  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00432aa9  7db2                     jge       0x432a5d
00432aab  85d2                     test      edx, edx
00432aad  7421                     je        0x432ad0
00432aaf  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00432ab5  89c2                     mov       edx, eax
00432ab7  c1fa1f                   sar       edx, 0x1f
00432aba  89c1                     mov       ecx, eax
00432abc  29d1                     sub       ecx, edx
00432abe  89ca                     mov       edx, ecx
00432ac0  d1fa                     sar       edx, 1
00432ac2  8b0c85845c6e00           mov       ecx, dword ptr [eax*4 + 0x6e5c84]
00432ac9  890c95885c6e00           mov       dword ptr [edx*4 + 0x6e5c88], ecx
00432ad0  c70560e6560000000000     mov       dword ptr [0x56e660], 0 ; bits=00000000, f32=0.0
00432ada  d90534e65600             fld       dword ptr [0x56e634] ; bits=00000000, f32=0.0
00432ae0  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00432ae3  db6dd4                   fld       xword ptr [ebp - 0x2c]
00432ae6  d8052015f300             fadd      dword ptr [0xf31520]
00432aec  d95df4                   fstp      dword ptr [ebp - 0xc]
00432aef  6a08                     push      8
00432af1  6a08                     push      8
00432af3  6a08                     push      8
00432af5  6a08                     push      8
00432af7  6a08                     push      8
00432af9  6a08                     push      8
00432afb  6a32                     push      0x32
00432afd  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
00432b00  8d03                     lea       eax, [ebx]
00432b02  50                       push      eax
00432b03  68f0e55600               push      0x56e5f0
00432b08  68e8e55600               push      0x56e5e8
00432b0d  6820e85600               push      0x56e820
00432b12  6818e85600               push      0x56e818
00432b17  6810e85600               push      0x56e810
00432b1c  6808e85600               push      0x56e808
00432b21  6800e85600               push      0x56e800
00432b26  6860e65600               push      0x56e660
00432b2b  68d8db5600               push      0x56dbd8
00432b30  680ce65600               push      0x56e60c
00432b35  8d45f4                   lea       eax, [ebp - 0xc]
00432b38  50                       push      eax
00432b39  6804626e00               push      0x6e6204
00432b3e  68885c6e00               push      0x6e5c88
00432b43  8d0550586e00             lea       eax, [0x6e5850]
00432b49  8985f4feffff             mov       dword ptr [ebp - 0x10c], eax
00432b4f  8d4880                   lea       ecx, [eax - 0x80]
00432b52  51                       push      ecx
00432b53  682c5a6e00               push      0x6e5a2c
00432b58  68f8e55600               push      0x56e5f8
00432b5d  6800e65600               push      0x56e600
00432b62  68e0e65600               push      0x56e6e0
00432b67  6808e65600               push      0x56e608
00432b6c  8b8d3cffffff             mov       ecx, dword ptr [ebp - 0xc4]
00432b72  8d31                     lea       esi, [ecx]
00432b74  8b8d40ffffff             mov       ecx, dword ptr [ebp - 0xc0]
00432b7a  56                       push      esi
00432b7b  8d31                     lea       esi, [ecx]
00432b7d  56                       push      esi
00432b7e  e83d6a0400               call      0x4795c0 ; _twdout_
00432b83  db6dd4                   fld       xword ptr [ebp - 0x2c]
00432b86  83c474                   add       esp, 0x74
00432b89  8d15a4e5f400             lea       edx, [0xf4e5a4]
00432b8f  8d3d28dc5600             lea       edi, [0x56dc28] ; bits=59455320, f32=1.7895340401776134e-19
00432b95  b904000000               mov       ecx, 4
00432b9a  89d6                     mov       esi, edx
00432b9c  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00432b9e  0f8538020000             jne       0x432ddc
00432ba4  c70514e6560001000000     mov       dword ptr [0x56e614], 1 ; bits=00000000, f32=0.0
00432bae  d8052015f300             fadd      dword ptr [0xf31520]
00432bb4  d95df4                   fstp      dword ptr [ebp - 0xc]
00432bb7  6a08                     push      8
00432bb9  6810e65600               push      0x56e610
00432bbe  8d03                     lea       eax, [ebx]
00432bc0  50                       push      eax
00432bc1  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00432bc4  8d00                     lea       eax, [eax]
00432bc6  50                       push      eax
00432bc7  6814e65600               push      0x56e614
00432bcc  6860e65600               push      0x56e660
00432bd1  68d8db5600               push      0x56dbd8
00432bd6  680ce65600               push      0x56e60c
00432bdb  8d45f4                   lea       eax, [ebp - 0xc]
00432bde  50                       push      eax
00432bdf  6804626e00               push      0x6e6204
00432be4  68885c6e00               push      0x6e5c88
00432be9  8b85f4feffff             mov       eax, dword ptr [ebp - 0x10c]
00432bef  8d4880                   lea       ecx, [eax - 0x80]
00432bf2  51                       push      ecx
00432bf3  682c5a6e00               push      0x6e5a2c
00432bf8  68f8e55600               push      0x56e5f8
00432bfd  6800e65600               push      0x56e600
00432c02  6808e65600               push      0x56e608
00432c07  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00432c0d  8d08                     lea       ecx, [eax]
00432c0f  51                       push      ecx
00432c10  e8bb420400               call      0x476ed0 ; _twodfit_
00432c15  83c444                   add       esp, 0x44
00432c18  e9c1010000               jmp       0x432dde
00432c1d  8b853cffffff             mov       eax, dword ptr [ebp - 0xc4]
00432c23  8b18                     mov       ebx, dword ptr [eax]
00432c25  6a10                     push      0x10
00432c27  68a0e75600               push      0x56e7a0
00432c2c  e81fce0100               call      0x44fa50 ; _lenstr_
00432c31  83c408                   add       esp, 8
00432c34  89c2                     mov       edx, eax
00432c36  c1fa1f                   sar       edx, 0x1f
00432c39  f7d2                     not       edx
00432c3b  21d0                     and       eax, edx
00432c3d  8d0d04de5600             lea       ecx, [0x56de04] ; bits=09020000, f32=7.300764999132297e-43
00432c43  895dfc                   mov       dword ptr [ebp - 4], ebx
00432c46  8d55fc                   lea       edx, [ebp - 4]
00432c49  895108                   mov       dword ptr [ecx + 8], edx
00432c4c  894124                   mov       dword ptr [ecx + 0x24], eax
00432c4f  51                       push      ecx
00432c50  e89bf90600               call      0x4a25f0 ; _jwe_isfm
00432c55  83c404                   add       esp, 4
00432c58  8b853cffffff             mov       eax, dword ptr [ebp - 0xc4]
00432c5e  8b08                     mov       ecx, dword ptr [eax]
00432c60  898df0feffff             mov       dword ptr [ebp - 0x110], ecx
00432c66  8d05e4dd5600             lea       eax, [0x56dde4] ; bits=69020000, f32=8.646011524884121e-43
00432c6c  894dfc                   mov       dword ptr [ebp - 4], ecx
00432c6f  8d55fc                   lea       edx, [ebp - 4]
00432c72  895008                   mov       dword ptr [eax + 8], edx
00432c75  50                       push      eax
00432c76  e875f90600               call      0x4a25f0 ; _jwe_isfm
00432c7b  83c404                   add       esp, 4
00432c7e  8d05c4dd5600             lea       eax, [0x56ddc4] ; bits=69020000, f32=8.646011524884121e-43
00432c84  8b8df0feffff             mov       ecx, dword ptr [ebp - 0x110]
00432c8a  894dfc                   mov       dword ptr [ebp - 4], ecx
00432c8d  8d55fc                   lea       edx, [ebp - 4]
00432c90  895008                   mov       dword ptr [eax + 8], edx
00432c93  50                       push      eax
00432c94  e857f90600               call      0x4a25f0 ; _jwe_isfm
00432c99  83c404                   add       esp, 4
00432c9c  8d05a4dd5600             lea       eax, [0x56dda4] ; bits=69020000, f32=8.646011524884121e-43
00432ca2  8b8df0feffff             mov       ecx, dword ptr [ebp - 0x110]
00432ca8  894dfc                   mov       dword ptr [ebp - 4], ecx
00432cab  8d55fc                   lea       edx, [ebp - 4]
00432cae  895008                   mov       dword ptr [eax + 8], edx
00432cb1  50                       push      eax
00432cb2  e839f90600               call      0x4a25f0 ; _jwe_isfm
00432cb7  83c404                   add       esp, 4
00432cba  8d056cdd5600             lea       eax, [0x56dd6c] ; bits=09020000, f32=7.300764999132297e-43
00432cc0  8b8df0feffff             mov       ecx, dword ptr [ebp - 0x110]
00432cc6  894dfc                   mov       dword ptr [ebp - 4], ecx
00432cc9  8d55fc                   lea       edx, [ebp - 4]
00432ccc  895008                   mov       dword ptr [eax + 8], edx
00432ccf  50                       push      eax
00432cd0  e81bf90600               call      0x4a25f0 ; _jwe_isfm
00432cd5  83c404                   add       esp, 4
00432cd8  8b0500e65600             mov       eax, dword ptr [0x56e600] ; bits=00000000, f32=0.0
00432cde  3d00000000               cmp       eax, 0
00432ce3  8985ecfeffff             mov       dword ptr [ebp - 0x114], eax
00432ce9  0f8e86000000             jle       0x432d75
00432cef  b801000000               mov       eax, 1
00432cf4  8b8df0feffff             mov       ecx, dword ptr [ebp - 0x110]
00432cfa  898de8feffff             mov       dword ptr [ebp - 0x118], ecx
00432d00  8b15f8e55600             mov       edx, dword ptr [0x56e5f8] ; bits=00000000, f32=0.0
00432d06  8d34d2                   lea       esi, [edx + edx*8]
00432d09  8d3472                   lea       esi, [edx + esi*2]
00432d0c  c1e603                   shl       esi, 3
00432d0f  29d6                     sub       esi, edx
00432d11  89f3                     mov       ebx, esi
00432d13  43                       inc       ebx
00432d14  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00432d1a  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00432d20  8b0c85285a6e00           mov       ecx, dword ptr [eax*4 + 0x6e5a28]
00432d27  8d1534dd5600             lea       edx, [0x56dd34] ; bits=09020000, f32=7.300764999132297e-43
00432d2d  8bb5e8feffff             mov       esi, dword ptr [ebp - 0x118]
00432d33  8975fc                   mov       dword ptr [ebp - 4], esi
00432d36  8d7dfc                   lea       edi, [ebp - 4]
00432d39  8b049da45f6e00           mov       eax, dword ptr [ebx*4 + 0x6e5fa4]
00432d40  897a08                   mov       dword ptr [edx + 8], edi
00432d43  894df4                   mov       dword ptr [ebp - 0xc], ecx
00432d46  8d4df4                   lea       ecx, [ebp - 0xc]
00432d49  894a28                   mov       dword ptr [edx + 0x28], ecx
00432d4c  8945f0                   mov       dword ptr [ebp - 0x10], eax
00432d4f  8d45f0                   lea       eax, [ebp - 0x10]
00432d52  894234                   mov       dword ptr [edx + 0x34], eax
00432d55  52                       push      edx
00432d56  e895f80600               call      0x4a25f0 ; _jwe_isfm
00432d5b  83c404                   add       esp, 4
00432d5e  43                       inc       ebx
00432d5f  8b8520ffffff             mov       eax, dword ptr [ebp - 0xe0]
00432d65  40                       inc       eax
00432d66  83adecfeffff01           sub       dword ptr [ebp - 0x114], 1
00432d6d  898520ffffff             mov       dword ptr [ebp - 0xe0], eax
00432d73  75a5                     jne       0x432d1a
00432d75  8d05fcdc5600             lea       eax, [0x56dcfc] ; bits=09020000, f32=7.300764999132297e-43
00432d7b  8b8df0feffff             mov       ecx, dword ptr [ebp - 0x110]
00432d81  894dfc                   mov       dword ptr [ebp - 4], ecx
00432d84  8d4dfc                   lea       ecx, [ebp - 4]
00432d87  894808                   mov       dword ptr [eax + 8], ecx
00432d8a  50                       push      eax
00432d8b  e860f80600               call      0x4a25f0 ; _jwe_isfm
00432d90  83c404                   add       esp, 4
00432d93  eb49                     jmp       0x432dde
00432d95  8b8540ffffff             mov       eax, dword ptr [ebp - 0xc0]
00432d9b  8b18                     mov       ebx, dword ptr [eax]
00432d9d  8d05d0dc5600             lea       eax, [0x56dcd0] ; bits=09820000, f32=4.664782457890884e-41
00432da3  895dfc                   mov       dword ptr [ebp - 4], ebx
00432da6  8d4dfc                   lea       ecx, [ebp - 4]
00432da9  894808                   mov       dword ptr [eax + 8], ecx
00432dac  50                       push      eax
00432dad  e8ce000700               call      0x4a2e80 ; _jwe_ilst
00432db2  83c404                   add       esp, 4
00432db5  8d05a4dc5600             lea       eax, [0x56dca4] ; bits=09820000, f32=4.664782457890884e-41
00432dbb  895dfc                   mov       dword ptr [ebp - 4], ebx
00432dbe  8d4dfc                   lea       ecx, [ebp - 4]
00432dc1  894808                   mov       dword ptr [eax + 8], ecx
00432dc4  50                       push      eax
00432dc5  e8b6000700               call      0x4a2e80 ; _jwe_ilst
00432dca  83c404                   add       esp, 4
00432dcd  682cdc5600               push      0x56dc2c
00432dd2  e869060700               call      0x4a3440 ; _jwe_xstp
00432dd7  83c404                   add       esp, 4
00432dda  eb02                     jmp       0x432dde
00432ddc  ddd8                     fstp      st(0)
00432dde  b800000000               mov       eax, 0
00432de3  5f                       pop       edi
00432de4  5e                       pop       esi
00432de5  5b                       pop       ebx
00432de6  8be5                     mov       esp, ebp
00432de8  5d                       pop       ebp
00432de9  c3                       ret
00432dea  8d9b00000000             lea       ebx, [ebx]
