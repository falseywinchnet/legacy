; _chntab_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x7150
00407150  55                       push      ebp
00407151  8bec                     mov       ebp, esp
00407153  b8a0010000               mov       eax, 0x1a0
00407158  e8a31e0e00               call      0x4e9000 ; __alloca_probe
0040715d  53                       push      ebx
0040715e  56                       push      esi
0040715f  57                       push      edi
00407160  8b4508                   mov       eax, dword ptr [ebp + 8]
00407163  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00407166  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00407169  8985a8feffff             mov       dword ptr [ebp - 0x158], eax
0040716f  898da4feffff             mov       dword ptr [ebp - 0x15c], ecx
00407175  8995a0feffff             mov       dword ptr [ebp - 0x160], edx
0040717b  d9ee                     fldz
0040717d  db7db0                   fstp      xword ptr [ebp - 0x50]
00407180  c7051c4b550000000000     mov       dword ptr [0x554b1c], 0 ; bits=00000000, f32=0.0
0040718a  8b5d20                   mov       ebx, dword ptr [ebp + 0x20]
0040718d  8d03                     lea       eax, [ebx]
0040718f  50                       push      eax
00407190  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407196  8d08                     lea       ecx, [eax]
00407198  51                       push      ecx
00407199  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
0040719f  8d11                     lea       edx, [ecx]
004071a1  52                       push      edx
004071a2  e889290000               call      0x409b30 ; _get_chnrt_items_
004071a7  83c40c                   add       esp, 0xc
004071aa  6a08                     push      8
004071ac  6a08                     push      8
004071ae  6a08                     push      8
004071b0  6a08                     push      8
004071b2  6a08                     push      8
004071b4  68b04a5500               push      0x554ab0
004071b9  68a84a5500               push      0x554aa8
004071be  68904c5500               push      0x554c90
004071c3  68884c5500               push      0x554c88
004071c8  68804c5500               push      0x554c80
004071cd  68784c5500               push      0x554c78
004071d2  68704c5500               push      0x554c70
004071d7  682c4b5500               push      0x554b2c
004071dc  68a8f70e04               push      0x40ef7a8
004071e1  68a4f70e04               push      0x40ef7a4
004071e6  68344b5500               push      0x554b34
004071eb  6874f70e04               push      0x40ef774
004071f0  6870f70e04               push      0x40ef770
004071f5  68c84a5500               push      0x554ac8
004071fa  68c44a5500               push      0x554ac4
004071ff  8d1b                     lea       ebx, [ebx]
00407201  53                       push      ebx
00407202  e869270000               call      0x409970 ; _set_chnrt_items_
00407207  83c454                   add       esp, 0x54
0040720a  d905344b5500             fld       dword ptr [0x554b34] ; bits=00000000, f32=0.0
00407210  dd1d60f70e04             fstp      qword ptr [0x40ef760] ; _epscom_
00407216  d9052c4b5500             fld       dword ptr [0x554b2c] ; bits=00000000, f32=0.0
0040721c  d9ee                     fldz
0040721e  d9c9                     fxch      st(1)
00407220  dae9                     fucompp
00407222  dfe0                     fnstsw    ax
00407224  9e                       sahf
00407225  0f8a0d000000             jp        0x407238
0040722b  750b                     jne       0x407238
0040722d  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00407230  8b00                     mov       eax, dword ptr [eax]
00407232  89052c4b5500             mov       dword ptr [0x554b2c], eax ; bits=00000000, f32=0.0
00407238  833dc84a550005           cmp       dword ptr [0x554ac8], 5 ; bits=00000000, f32=0.0
0040723f  752a                     jne       0x40726b
00407241  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407247  8b08                     mov       ecx, dword ptr [eax]
00407249  8d15844a5500             lea       edx, [0x554a84] ; bits=69020000, f32=8.646011524884121e-43
0040724f  894dfc                   mov       dword ptr [ebp - 4], ecx
00407252  8d4dfc                   lea       ecx, [ebp - 4]
00407255  894a08                   mov       dword ptr [edx + 8], ecx
00407258  52                       push      edx
00407259  e892b30900               call      0x4a25f0 ; _jwe_isfm
0040725e  83c404                   add       esp, 4
00407261  c705c84a55000d000000     mov       dword ptr [0x554ac8], 0xd ; bits=00000000, f32=0.0
0040726b  833dc84a55000d           cmp       dword ptr [0x554ac8], 0xd ; bits=00000000, f32=0.0
00407272  7432                     je        0x4072a6
00407274  833dc84a550006           cmp       dword ptr [0x554ac8], 6 ; bits=00000000, f32=0.0
0040727b  7429                     je        0x4072a6
0040727d  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407283  8b08                     mov       ecx, dword ptr [eax]
00407285  8d15644a5500             lea       edx, [0x554a64] ; bits=69020000, f32=8.646011524884121e-43
0040728b  894dfc                   mov       dword ptr [ebp - 4], ecx
0040728e  8d4dfc                   lea       ecx, [ebp - 4]
00407291  894a08                   mov       dword ptr [edx + 8], ecx
00407294  52                       push      edx
00407295  e856b30900               call      0x4a25f0 ; _jwe_isfm
0040729a  83c404                   add       esp, 4
0040729d  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004072a0  c70001000000             mov       dword ptr [eax], 1
004072a6  833d70f70e0400           cmp       dword ptr [0x40ef770], 0
004072ad  7c09                     jl        0x4072b8
004072af  833d70f70e0401           cmp       dword ptr [0x40ef770], 1
004072b6  7e38                     jle       0x4072f0
004072b8  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004072be  8b08                     mov       ecx, dword ptr [eax]
004072c0  8b1570f70e04             mov       edx, dword ptr [0x40ef770]
004072c6  8d1d384a5500             lea       ebx, [0x554a38] ; bits=09020000, f32=7.300764999132297e-43
004072cc  894dfc                   mov       dword ptr [ebp - 4], ecx
004072cf  8d4dfc                   lea       ecx, [ebp - 4]
004072d2  894b08                   mov       dword ptr [ebx + 8], ecx
004072d5  8955f8                   mov       dword ptr [ebp - 8], edx
004072d8  8d4df8                   lea       ecx, [ebp - 8]
004072db  894b28                   mov       dword ptr [ebx + 0x28], ecx
004072de  53                       push      ebx
004072df  e80cb30900               call      0x4a25f0 ; _jwe_isfm
004072e4  83c404                   add       esp, 4
004072e7  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004072ea  c70001000000             mov       dword ptr [eax], 1
004072f0  dd0560f70e04             fld       qword ptr [0x40ef760] ; _epscom_
004072f6  dc1d003e5500             fcomp     qword ptr [0x553e00] ; bits=0000000000000000, f64=0.0
004072fc  dfe0                     fnstsw    ax
004072fe  9e                       sahf
004072ff  0f8a43000000             jp        0x407348
00407305  7741                     ja        0x407348
00407307  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0040730a  d900                     fld       dword ptr [eax]
0040730c  8d15503e5500             lea       edx, [0x553e50] ; bits=01000000, f32=1.401298464324817e-45
00407312  d85ad0                   fcomp     dword ptr [edx - 0x30]
00407315  dfe0                     fnstsw    ax
00407317  9e                       sahf
00407318  0f8a16000000             jp        0x407334
0040731e  7614                     jbe       0x407334
00407320  8b4288                   mov       eax, dword ptr [edx - 0x78]
00407323  8b4a8c                   mov       ecx, dword ptr [edx - 0x74]
00407326  890560f70e04             mov       dword ptr [0x40ef760], eax ; _epscom_
0040732c  890d64f70e04             mov       dword ptr [0x40ef764], ecx
00407332  eb14                     jmp       0x407348
00407334  89d0                     mov       eax, edx
00407336  8b4890                   mov       ecx, dword ptr [eax - 0x70]
00407339  8b4094                   mov       eax, dword ptr [eax - 0x6c]
0040733c  890d60f70e04             mov       dword ptr [0x40ef760], ecx ; _epscom_
00407342  890564f70e04             mov       dword ptr [0x40ef764], eax
00407348  d905a4f70e04             fld       dword ptr [0x40ef7a4]
0040734e  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
00407354  dfe0                     fnstsw    ax
00407356  9e                       sahf
00407357  0f8a31000000             jp        0x40738e
0040735d  772f                     ja        0x40738e
0040735f  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00407362  d900                     fld       dword ptr [eax]
00407364  8d15503e5500             lea       edx, [0x553e50] ; bits=01000000, f32=1.401298464324817e-45
0040736a  d85ad0                   fcomp     dword ptr [edx - 0x30]
0040736d  dfe0                     fnstsw    ax
0040736f  9e                       sahf
00407370  0f8a0d000000             jp        0x407383
00407376  760b                     jbe       0x407383
00407378  8b42d4                   mov       eax, dword ptr [edx - 0x2c]
0040737b  8905a4f70e04             mov       dword ptr [0x40ef7a4], eax
00407381  eb0b                     jmp       0x40738e
00407383  89d0                     mov       eax, edx
00407385  8b40d8                   mov       eax, dword ptr [eax - 0x28]
00407388  8905a4f70e04             mov       dword ptr [0x40ef7a4], eax
0040738e  68c44a5500               push      0x554ac4
00407393  6a10                     push      0x10
00407395  68984c5500               push      0x554c98
0040739a  e8f1ff0600               call      0x477390 ; _get_tabid_
0040739f  83c40c                   add       esp, 0xc
004073a2  8d05404c5500             lea       eax, [0x554c40] ; bits=00000000, f32=0.0
004073a8  8d0d984c5500             lea       ecx, [0x554c98] ; bits=00000000, f32=0.0
004073ae  8a11                     mov       dl, byte ptr [ecx]
004073b0  8810                     mov       byte ptr [eax], dl
004073b2  8a5101                   mov       dl, byte ptr [ecx + 1]
004073b5  885001                   mov       byte ptr [eax + 1], dl
004073b8  8a5102                   mov       dl, byte ptr [ecx + 2]
004073bb  885002                   mov       byte ptr [eax + 2], dl
004073be  8a5103                   mov       dl, byte ptr [ecx + 3]
004073c1  885003                   mov       byte ptr [eax + 3], dl
004073c4  8a5104                   mov       dl, byte ptr [ecx + 4]
004073c7  885004                   mov       byte ptr [eax + 4], dl
004073ca  8a5105                   mov       dl, byte ptr [ecx + 5]
004073cd  885005                   mov       byte ptr [eax + 5], dl
004073d0  8a5106                   mov       dl, byte ptr [ecx + 6]
004073d3  885006                   mov       byte ptr [eax + 6], dl
004073d6  8a5107                   mov       dl, byte ptr [ecx + 7]
004073d9  885007                   mov       byte ptr [eax + 7], dl
004073dc  8a5108                   mov       dl, byte ptr [ecx + 8]
004073df  885008                   mov       byte ptr [eax + 8], dl
004073e2  8a5109                   mov       dl, byte ptr [ecx + 9]
004073e5  885009                   mov       byte ptr [eax + 9], dl
004073e8  8a510a                   mov       dl, byte ptr [ecx + 0xa]
004073eb  88500a                   mov       byte ptr [eax + 0xa], dl
004073ee  8a510b                   mov       dl, byte ptr [ecx + 0xb]
004073f1  88500b                   mov       byte ptr [eax + 0xb], dl
004073f4  8a510c                   mov       dl, byte ptr [ecx + 0xc]
004073f7  88500c                   mov       byte ptr [eax + 0xc], dl
004073fa  8a510d                   mov       dl, byte ptr [ecx + 0xd]
004073fd  88500d                   mov       byte ptr [eax + 0xd], dl
00407400  8a510e                   mov       dl, byte ptr [ecx + 0xe]
00407403  88500e                   mov       byte ptr [eax + 0xe], dl
00407406  8a510f                   mov       dl, byte ptr [ecx + 0xf]
00407409  88500f                   mov       byte ptr [eax + 0xf], dl
0040740c  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407412  8b18                     mov       ebx, dword ptr [eax]
00407414  6a10                     push      0x10
00407416  68404c5500               push      0x554c40
0040741b  e830860400               call      0x44fa50 ; _lenstr_
00407420  83c408                   add       esp, 8
00407423  89c2                     mov       edx, eax
00407425  c1fa1f                   sar       edx, 0x1f
00407428  f7d2                     not       edx
0040742a  21d0                     and       eax, edx
0040742c  8b0dc84a5500             mov       ecx, dword ptr [0x554ac8] ; bits=00000000, f32=0.0
00407432  8d15004a5500             lea       edx, [0x554a00] ; bits=09020000, f32=7.300764999132297e-43
00407438  895dfc                   mov       dword ptr [ebp - 4], ebx
0040743b  8d5dfc                   lea       ebx, [ebp - 4]
0040743e  895a08                   mov       dword ptr [edx + 8], ebx
00407441  894224                   mov       dword ptr [edx + 0x24], eax
00407444  894df8                   mov       dword ptr [ebp - 8], ecx
00407447  8d45f8                   lea       eax, [ebp - 8]
0040744a  894234                   mov       dword ptr [edx + 0x34], eax
0040744d  52                       push      edx
0040744e  e89db10900               call      0x4a25f0 ; _jwe_isfm
00407453  83c404                   add       esp, 4
00407456  8b05c44a5500             mov       eax, dword ptr [0x554ac4] ; bits=00000000, f32=0.0
0040745c  833c85ec5a0e0400         cmp       dword ptr [eax*4 + 0x40e5aec], 0
00407464  7415                     je        0x40747b
00407466  6a10                     push      0x10
00407468  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0040746b  8d00                     lea       eax, [eax]
0040746d  50                       push      eax
0040746e  68404c5500               push      0x554c40
00407473  e8d8340500               call      0x45a950 ; _tab_in_use_
00407478  83c40c                   add       esp, 0xc
0040747b  833d74f70e0401           cmp       dword ptr [0x40ef774], 1
00407482  7522                     jne       0x4074a6
00407484  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
0040748a  8b08                     mov       ecx, dword ptr [eax]
0040748c  8d15e0495500             lea       edx, [0x5549e0] ; bits=69020000, f32=8.646011524884121e-43
00407492  894dfc                   mov       dword ptr [ebp - 4], ecx
00407495  8d4dfc                   lea       ecx, [ebp - 4]
00407498  894a08                   mov       dword ptr [edx + 8], ecx
0040749b  52                       push      edx
0040749c  e84fb10900               call      0x4a25f0 ; _jwe_isfm
004074a1  83c404                   add       esp, 4
004074a4  eb2a                     jmp       0x4074d0
004074a6  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004074ac  8b08                     mov       ecx, dword ptr [eax]
004074ae  8d15c0495500             lea       edx, [0x5549c0] ; bits=69020000, f32=8.646011524884121e-43
004074b4  894dfc                   mov       dword ptr [ebp - 4], ecx
004074b7  8d4dfc                   lea       ecx, [ebp - 4]
004074ba  894a08                   mov       dword ptr [edx + 8], ecx
004074bd  52                       push      edx
004074be  e82db10900               call      0x4a25f0 ; _jwe_isfm
004074c3  83c404                   add       esp, 4
004074c6  c70574f70e0401000000     mov       dword ptr [0x40ef774], 1
004074d0  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004074d6  8b18                     mov       ebx, dword ptr [eax]
004074d8  8b0d60f70e04             mov       ecx, dword ptr [0x40ef760] ; _epscom_
004074de  8b1564f70e04             mov       edx, dword ptr [0x40ef764]
004074e4  8d3594495500             lea       esi, [0x554994] ; bits=09020000, f32=7.300764999132297e-43
004074ea  895dfc                   mov       dword ptr [ebp - 4], ebx
004074ed  8d7dfc                   lea       edi, [ebp - 4]
004074f0  897e08                   mov       dword ptr [esi + 8], edi
004074f3  894df0                   mov       dword ptr [ebp - 0x10], ecx
004074f6  8955f4                   mov       dword ptr [ebp - 0xc], edx
004074f9  8d4df0                   lea       ecx, [ebp - 0x10]
004074fc  894e28                   mov       dword ptr [esi + 0x28], ecx
004074ff  56                       push      esi
00407500  e8ebb00900               call      0x4a25f0 ; _jwe_isfm
00407505  83c404                   add       esp, 4
00407508  8b05a4f70e04             mov       eax, dword ptr [0x40ef7a4]
0040750e  8b0da8f70e04             mov       ecx, dword ptr [0x40ef7a8]
00407514  8d155c495500             lea       edx, [0x55495c] ; bits=09020000, f32=7.300764999132297e-43
0040751a  895dfc                   mov       dword ptr [ebp - 4], ebx
0040751d  8d75fc                   lea       esi, [ebp - 4]
00407520  897208                   mov       dword ptr [edx + 8], esi
00407523  8945ec                   mov       dword ptr [ebp - 0x14], eax
00407526  8d45ec                   lea       eax, [ebp - 0x14]
00407529  894228                   mov       dword ptr [edx + 0x28], eax
0040752c  894de8                   mov       dword ptr [ebp - 0x18], ecx
0040752f  8d45e8                   lea       eax, [ebp - 0x18]
00407532  894234                   mov       dword ptr [edx + 0x34], eax
00407535  52                       push      edx
00407536  e8b5b00900               call      0x4a25f0 ; _jwe_isfm
0040753b  83c404                   add       esp, 4
0040753e  8b352c4b5500             mov       esi, dword ptr [0x554b2c] ; bits=00000000, f32=0.0
00407544  8d0530495500             lea       eax, [0x554930] ; bits=09020000, f32=7.300764999132297e-43
0040754a  895dfc                   mov       dword ptr [ebp - 4], ebx
0040754d  8d4dfc                   lea       ecx, [ebp - 4]
00407550  894808                   mov       dword ptr [eax + 8], ecx
00407553  8975ec                   mov       dword ptr [ebp - 0x14], esi
00407556  8d4dec                   lea       ecx, [ebp - 0x14]
00407559  894828                   mov       dword ptr [eax + 0x28], ecx
0040755c  50                       push      eax
0040755d  e88eb00900               call      0x4a25f0 ; _jwe_isfm
00407562  83c404                   add       esp, 4
00407565  8b85a0feffff             mov       eax, dword ptr [ebp - 0x160]
0040756b  8b08                     mov       ecx, dword ptr [eax]
0040756d  8d1504495500             lea       edx, [0x554904] ; bits=09020000, f32=7.300764999132297e-43
00407573  894dfc                   mov       dword ptr [ebp - 4], ecx
00407576  8d4dfc                   lea       ecx, [ebp - 4]
00407579  894a08                   mov       dword ptr [edx + 8], ecx
0040757c  8975ec                   mov       dword ptr [ebp - 0x14], esi
0040757f  8d4dec                   lea       ecx, [ebp - 0x14]
00407582  894a28                   mov       dword ptr [edx + 0x28], ecx
00407585  52                       push      edx
00407586  e865b00900               call      0x4a25f0 ; _jwe_isfm
0040758b  83c404                   add       esp, 4
0040758e  6a50                     push      0x50
00407590  68e04b5500               push      0x554be0
00407595  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
0040759b  8d08                     lea       ecx, [eax]
0040759d  51                       push      ecx
0040759e  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
004075a4  8d11                     lea       edx, [ecx]
004075a6  52                       push      edx
004075a7  e834530400               call      0x44c8e0 ; _inline_
004075ac  83c410                   add       esp, 0x10
004075af  68e4485500               push      0x5548e4
004075b4  e897a50900               call      0x4a1b50 ; _jwe_iinf
004075b9  83c404                   add       esp, 4
004075bc  85c0                     test      eax, eax
004075be  0f859a160000             jne       0x408c5e
004075c4  68cc485500               push      0x5548cc
004075c9  e882a50900               call      0x4a1b50 ; _jwe_iinf
004075ce  83c404                   add       esp, 4
004075d1  85c0                     test      eax, eax
004075d3  0f8585160000             jne       0x408c5e
004075d9  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004075df  8b08                     mov       ecx, dword ptr [eax]
004075e1  8d1594485500             lea       edx, [0x554894] ; bits=09020000, f32=7.300764999132297e-43
004075e7  894dfc                   mov       dword ptr [ebp - 4], ecx
004075ea  8d4dfc                   lea       ecx, [ebp - 4]
004075ed  894a08                   mov       dword ptr [edx + 8], ecx
004075f0  52                       push      edx
004075f1  e8faaf0900               call      0x4a25f0 ; _jwe_isfm
004075f6  83c404                   add       esp, 4
004075f9  6a50                     push      0x50
004075fb  68e04b5500               push      0x554be0
00407600  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407606  8d08                     lea       ecx, [eax]
00407608  51                       push      ecx
00407609  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
0040760f  8d11                     lea       edx, [ecx]
00407611  52                       push      edx
00407612  e8c9520400               call      0x44c8e0 ; _inline_
00407617  83c410                   add       esp, 0x10
0040761a  6a10                     push      0x10
0040761c  6a05                     push      5
0040761e  6a50                     push      0x50
00407620  68d04a5500               push      0x554ad0
00407625  68504c5500               push      0x554c50
0040762a  8b5d20                   mov       ebx, dword ptr [ebp + 0x20]
0040762d  8d03                     lea       eax, [ebx]
0040762f  50                       push      eax
00407630  68b03f5500               push      0x553fb0
00407635  68e04b5500               push      0x554be0
0040763a  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407640  8d08                     lea       ecx, [eax]
00407642  51                       push      ecx
00407643  e8e8300500               call      0x45a730 ; _read_tabid_
00407648  83c424                   add       esp, 0x24
0040764b  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407651  8b30                     mov       esi, dword ptr [eax]
00407653  6a10                     push      0x10
00407655  68504c5500               push      0x554c50
0040765a  e8f1830400               call      0x44fa50 ; _lenstr_
0040765f  83c408                   add       esp, 8
00407662  89c2                     mov       edx, eax
00407664  c1fa1f                   sar       edx, 0x1f
00407667  f7d2                     not       edx
00407669  21d0                     and       eax, edx
0040766b  8d0d68485500             lea       ecx, [0x554868] ; bits=09020000, f32=7.300764999132297e-43
00407671  8975fc                   mov       dword ptr [ebp - 4], esi
00407674  8d55fc                   lea       edx, [ebp - 4]
00407677  895108                   mov       dword ptr [ecx + 8], edx
0040767a  894124                   mov       dword ptr [ecx + 0x24], eax
0040767d  51                       push      ecx
0040767e  e86daf0900               call      0x4a25f0 ; _jwe_isfm
00407683  83c404                   add       esp, 4
00407686  8b05d04a5500             mov       eax, dword ptr [0x554ad0] ; bits=00000000, f32=0.0
0040768c  8905dc4a5500             mov       dword ptr [0x554adc], eax ; bits=00000000, f32=0.0
00407692  833dd04a550000           cmp       dword ptr [0x554ad0], 0 ; bits=00000000, f32=0.0
00407699  7f28                     jg        0x4076c3
0040769b  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004076a1  8b08                     mov       ecx, dword ptr [eax]
004076a3  8d1548485500             lea       edx, [0x554848] ; bits=69020000, f32=8.646011524884121e-43
004076a9  894dfc                   mov       dword ptr [ebp - 4], ecx
004076ac  8d4dfc                   lea       ecx, [ebp - 4]
004076af  894a08                   mov       dword ptr [edx + 8], ecx
004076b2  52                       push      edx
004076b3  e838af0900               call      0x4a25f0 ; _jwe_isfm
004076b8  83c404                   add       esp, 4
004076bb  c70301000000             mov       dword ptr [ebx], 1
004076c1  eb63                     jmp       0x407726
004076c3  89d8                     mov       eax, ebx
004076c5  8d00                     lea       eax, [eax]
004076c7  50                       push      eax
004076c8  68d04a5500               push      0x554ad0
004076cd  8d35503e5500             lea       esi, [0x553e50] ; bits=01000000, f32=1.401298464324817e-45
004076d3  8d4620                   lea       eax, [esi + 0x20]
004076d6  50                       push      eax
004076d7  68f05a0e04               push      0x40e5af0
004076dc  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004076e2  8d08                     lea       ecx, [eax]
004076e4  51                       push      ecx
004076e5  68e43e5500               push      0x553ee4
004076ea  e861060300               call      0x437d50 ; _chktab_
004076ef  83c418                   add       esp, 0x18
004076f2  dd05a84a5500             fld       qword ptr [0x554aa8] ; bits=0000000000000000, f64=0.0
004076f8  dc5ea8                   fcomp     qword ptr [esi - 0x58]
004076fb  dfe0                     fnstsw    ax
004076fd  9e                       sahf
004076fe  0f8a22000000             jp        0x407726
00407704  7720                     ja        0x407726
00407706  68b04a5500               push      0x554ab0
0040770b  68a84a5500               push      0x554aa8
00407710  68d04a5500               push      0x554ad0
00407715  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
0040771b  8d08                     lea       ecx, [eax]
0040771d  51                       push      ecx
0040771e  e81d7c0300               call      0x43f340 ; _get_east_north_
00407723  83c410                   add       esp, 0x10
00407726  6a50                     push      0x50
00407728  68e04b5500               push      0x554be0
0040772d  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407733  8d08                     lea       ecx, [eax]
00407735  51                       push      ecx
00407736  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
0040773c  8d11                     lea       edx, [ecx]
0040773e  52                       push      edx
0040773f  e89c510400               call      0x44c8e0 ; _inline_
00407744  83c410                   add       esp, 0x10
00407747  6828485500               push      0x554828
0040774c  e8ffa30900               call      0x4a1b50 ; _jwe_iinf
00407751  83c404                   add       esp, 4
00407754  85c0                     test      eax, eax
00407756  0f8502150000             jne       0x408c5e
0040775c  6810485500               push      0x554810
00407761  e8eaa30900               call      0x4a1b50 ; _jwe_iinf
00407766  83c404                   add       esp, 4
00407769  85c0                     test      eax, eax
0040776b  0f85ed140000             jne       0x408c5e
00407771  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407777  8b08                     mov       ecx, dword ptr [eax]
00407779  8b15e84a5500             mov       edx, dword ptr [0x554ae8] ; bits=00000000, f32=0.0
0040777f  8d1dd8475500             lea       ebx, [0x5547d8] ; bits=09020000, f32=7.300764999132297e-43
00407785  894dfc                   mov       dword ptr [ebp - 4], ecx
00407788  8d4dfc                   lea       ecx, [ebp - 4]
0040778b  894b08                   mov       dword ptr [ebx + 8], ecx
0040778e  8955ec                   mov       dword ptr [ebp - 0x14], edx
00407791  8d4dec                   lea       ecx, [ebp - 0x14]
00407794  894b34                   mov       dword ptr [ebx + 0x34], ecx
00407797  53                       push      ebx
00407798  e853ae0900               call      0x4a25f0 ; _jwe_isfm
0040779d  83c404                   add       esp, 4
004077a0  6a50                     push      0x50
004077a2  68e04b5500               push      0x554be0
004077a7  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004077ad  8d08                     lea       ecx, [eax]
004077af  51                       push      ecx
004077b0  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
004077b6  8d11                     lea       edx, [ecx]
004077b8  52                       push      edx
004077b9  e822510400               call      0x44c8e0 ; _inline_
004077be  83c410                   add       esp, 0x10
004077c1  68b8475500               push      0x5547b8
004077c6  e885a30900               call      0x4a1b50 ; _jwe_iinf
004077cb  83c404                   add       esp, 4
004077ce  85c0                     test      eax, eax
004077d0  0f8588140000             jne       0x408c5e
004077d6  6894475500               push      0x554794
004077db  e870a30900               call      0x4a1b50 ; _jwe_iinf
004077e0  83c404                   add       esp, 4
004077e3  85c0                     test      eax, eax
004077e5  0f8573140000             jne       0x408c5e
004077eb  6a0a                     push      0xa
004077ed  68604c5500               push      0x554c60
004077f2  e8b97e0400               call      0x44f6b0 ; _strip_l_blanks_
004077f7  83c408                   add       esp, 8
004077fa  8d15604c5500             lea       edx, [0x554c60] ; bits=00000000, f32=0.0
00407800  8d3db83f5500             lea       edi, [0x553fb8] ; bits=54414220, f32=1.6454054440115203e-19
00407806  b90a000000               mov       ecx, 0xa
0040780b  89d6                     mov       esi, edx
0040780d  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
0040780f  7417                     je        0x407828
00407811  8d15604c5500             lea       edx, [0x554c60] ; bits=00000000, f32=0.0
00407817  8d3dc83f5500             lea       edi, [0x553fc8] ; bits=74616220, f32=1.917518914220027e-19
0040781d  b90a000000               mov       ecx, 0xa
00407822  89d6                     mov       esi, edx
00407824  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00407826  7523                     jne       0x40784b
00407828  68ec4a5500               push      0x554aec
0040782d  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00407830  8d00                     lea       eax, [eax]
00407832  50                       push      eax
00407833  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407839  8d08                     lea       ecx, [eax]
0040783b  51                       push      ecx
0040783c  68dc4a5500               push      0x554adc
00407841  e8aafc0600               call      0x4774f0 ; _fndelv_
00407846  83c410                   add       esp, 0x10
00407849  eb2a                     jmp       0x407875
0040784b  6874475500               push      0x554774
00407850  e8fba20900               call      0x4a1b50 ; _jwe_iinf
00407855  83c404                   add       esp, 4
00407858  85c0                     test      eax, eax
0040785a  0f85fe130000             jne       0x408c5e
00407860  6868475500               push      0x554768
00407865  e8e6a20900               call      0x4a1b50 ; _jwe_iinf
0040786a  83c404                   add       esp, 4
0040786d  85c0                     test      eax, eax
0040786f  0f85e9130000             jne       0x408c5e
00407875  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
0040787b  8b08                     mov       ecx, dword ptr [eax]
0040787d  898d9cfeffff             mov       dword ptr [ebp - 0x164], ecx
00407883  8b15fc4a5500             mov       edx, dword ptr [0x554afc] ; bits=00000000, f32=0.0
00407889  8b1dec4a5500             mov       ebx, dword ptr [0x554aec] ; bits=00000000, f32=0.0
0040788f  8d3524475500             lea       esi, [0x554724] ; bits=09020000, f32=7.300764999132297e-43
00407895  894dfc                   mov       dword ptr [ebp - 4], ecx
00407898  8d7dfc                   lea       edi, [ebp - 4]
0040789b  897e08                   mov       dword ptr [esi + 8], edi
0040789e  8955ec                   mov       dword ptr [ebp - 0x14], edx
004078a1  8d55ec                   lea       edx, [ebp - 0x14]
004078a4  895634                   mov       dword ptr [esi + 0x34], edx
004078a7  895de8                   mov       dword ptr [ebp - 0x18], ebx
004078aa  8d55e8                   lea       edx, [ebp - 0x18]
004078ad  895640                   mov       dword ptr [esi + 0x40], edx
004078b0  56                       push      esi
004078b1  e83aad0900               call      0x4a25f0 ; _jwe_isfm
004078b6  83c404                   add       esp, 4
004078b9  d905fc4a5500             fld       dword ptr [0x554afc] ; bits=00000000, f32=0.0
004078bf  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
004078c5  dfe0                     fnstsw    ax
004078c7  9e                       sahf
004078c8  0f8a29000000             jp        0x4078f7
004078ce  7727                     ja        0x4078f7
004078d0  8d0504475500             lea       eax, [0x554704] ; bits=69020000, f32=8.646011524884121e-43
004078d6  8b8d9cfeffff             mov       ecx, dword ptr [ebp - 0x164]
004078dc  894dfc                   mov       dword ptr [ebp - 4], ecx
004078df  8d4dfc                   lea       ecx, [ebp - 4]
004078e2  894808                   mov       dword ptr [eax + 8], ecx
004078e5  50                       push      eax
004078e6  e805ad0900               call      0x4a25f0 ; _jwe_isfm
004078eb  83c404                   add       esp, 4
004078ee  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004078f1  c70001000000             mov       dword ptr [eax], 1
004078f7  8b05e84a5500             mov       eax, dword ptr [0x554ae8] ; bits=00000000, f32=0.0
004078fd  890590f70e04             mov       dword ptr [0x40ef790], eax
00407903  8b05fc4a5500             mov       eax, dword ptr [0x554afc] ; bits=00000000, f32=0.0
00407909  89058cf70e04             mov       dword ptr [0x40ef78c], eax
0040790f  8b05d04a5500             mov       eax, dword ptr [0x554ad0] ; bits=00000000, f32=0.0
00407915  890580f70e04             mov       dword ptr [0x40ef780], eax ; _chncom_
0040791b  6a50                     push      0x50
0040791d  68e04b5500               push      0x554be0
00407922  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407928  8d08                     lea       ecx, [eax]
0040792a  51                       push      ecx
0040792b  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
00407931  8d11                     lea       edx, [ecx]
00407933  52                       push      edx
00407934  e8a74f0400               call      0x44c8e0 ; _inline_
00407939  83c410                   add       esp, 0x10
0040793c  68e4465500               push      0x5546e4
00407941  e80aa20900               call      0x4a1b50 ; _jwe_iinf
00407946  83c404                   add       esp, 4
00407949  85c0                     test      eax, eax
0040794b  0f850d130000             jne       0x408c5e
00407951  68d8465500               push      0x5546d8
00407956  e8f5a10900               call      0x4a1b50 ; _jwe_iinf
0040795b  83c404                   add       esp, 4
0040795e  85c0                     test      eax, eax
00407960  0f85f8120000             jne       0x408c5e
00407966  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
0040796c  8b08                     mov       ecx, dword ptr [eax]
0040796e  8d15ac465500             lea       edx, [0x5546ac] ; bits=09020000, f32=7.300764999132297e-43
00407974  894dfc                   mov       dword ptr [ebp - 4], ecx
00407977  8d4dfc                   lea       ecx, [ebp - 4]
0040797a  894a08                   mov       dword ptr [edx + 8], ecx
0040797d  52                       push      edx
0040797e  e86dac0900               call      0x4a25f0 ; _jwe_isfm
00407983  83c404                   add       esp, 4
00407986  6a50                     push      0x50
00407988  68e04b5500               push      0x554be0
0040798d  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407993  8d08                     lea       ecx, [eax]
00407995  51                       push      ecx
00407996  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
0040799c  8d11                     lea       edx, [ecx]
0040799e  52                       push      edx
0040799f  e83c4f0400               call      0x44c8e0 ; _inline_
004079a4  83c410                   add       esp, 0x10
004079a7  688c465500               push      0x55468c
004079ac  e89fa10900               call      0x4a1b50 ; _jwe_iinf
004079b1  83c404                   add       esp, 4
004079b4  85c0                     test      eax, eax
004079b6  0f85a2120000             jne       0x408c5e
004079bc  6874465500               push      0x554674
004079c1  e88aa10900               call      0x4a1b50 ; _jwe_iinf
004079c6  83c404                   add       esp, 4
004079c9  85c0                     test      eax, eax
004079cb  0f858d120000             jne       0x408c5e
004079d1  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004079d7  8b08                     mov       ecx, dword ptr [eax]
004079d9  8b15bc4a5500             mov       edx, dword ptr [0x554abc] ; bits=00000000, f32=0.0
004079df  8d1d3c465500             lea       ebx, [0x55463c] ; bits=09020000, f32=7.300764999132297e-43
004079e5  894dfc                   mov       dword ptr [ebp - 4], ecx
004079e8  8d4dfc                   lea       ecx, [ebp - 4]
004079eb  894b08                   mov       dword ptr [ebx + 8], ecx
004079ee  8955f8                   mov       dword ptr [ebp - 8], edx
004079f1  8d4df8                   lea       ecx, [ebp - 8]
004079f4  894b34                   mov       dword ptr [ebx + 0x34], ecx
004079f7  53                       push      ebx
004079f8  e8f3ab0900               call      0x4a25f0 ; _jwe_isfm
004079fd  83c404                   add       esp, 4
00407a00  6a50                     push      0x50
00407a02  68e04b5500               push      0x554be0
00407a07  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407a0d  8d08                     lea       ecx, [eax]
00407a0f  51                       push      ecx
00407a10  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
00407a16  8d11                     lea       edx, [ecx]
00407a18  52                       push      edx
00407a19  e8c24e0400               call      0x44c8e0 ; _inline_
00407a1e  83c410                   add       esp, 0x10
00407a21  681c465500               push      0x55461c
00407a26  e825a10900               call      0x4a1b50 ; _jwe_iinf
00407a2b  83c404                   add       esp, 4
00407a2e  85c0                     test      eax, eax
00407a30  0f8528120000             jne       0x408c5e
00407a36  6804465500               push      0x554604
00407a3b  e810a10900               call      0x4a1b50 ; _jwe_iinf
00407a40  83c404                   add       esp, 4
00407a43  85c0                     test      eax, eax
00407a45  0f8513120000             jne       0x408c5e
00407a4b  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407a51  8b08                     mov       ecx, dword ptr [eax]
00407a53  8b15004b5500             mov       edx, dword ptr [0x554b00] ; bits=00000000, f32=0.0
00407a59  8d1dcc455500             lea       ebx, [0x5545cc] ; bits=09020000, f32=7.300764999132297e-43
00407a5f  894dfc                   mov       dword ptr [ebp - 4], ecx
00407a62  8d4dfc                   lea       ecx, [ebp - 4]
00407a65  894b08                   mov       dword ptr [ebx + 8], ecx
00407a68  8955ec                   mov       dword ptr [ebp - 0x14], edx
00407a6b  8d4dec                   lea       ecx, [ebp - 0x14]
00407a6e  894b34                   mov       dword ptr [ebx + 0x34], ecx
00407a71  53                       push      ebx
00407a72  e879ab0900               call      0x4a25f0 ; _jwe_isfm
00407a77  83c404                   add       esp, 4
00407a7a  b801000000               mov       eax, 1
00407a7f  d905443e5500             fld       dword ptr [0x553e44] ; bits=000080bf, f32=-1.0
00407a85  db7da4                   fstp      xword ptr [ebp - 0x5c]
00407a88  db6da4                   fld       xword ptr [ebp - 0x5c]
00407a8b  898598feffff             mov       dword ptr [ebp - 0x168], eax
00407a91  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407a94  6a50                     push      0x50
00407a96  68e04b5500               push      0x554be0
00407a9b  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407aa1  8d08                     lea       ecx, [eax]
00407aa3  51                       push      ecx
00407aa4  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
00407aaa  8d31                     lea       esi, [ecx]
00407aac  56                       push      esi
00407aad  e82e4e0400               call      0x44c8e0 ; _inline_
00407ab2  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407ab5  83c410                   add       esp, 0x10
00407ab8  8d15e04b5500             lea       edx, [0x554be0] ; bits=00000000, f32=0.0
00407abe  8d1d343f5500             lea       ebx, [0x553f34] ; bits=4c495052, f32=223645728768.0
00407ac4  b906000000               mov       ecx, 6
00407ac9  89d6                     mov       esi, edx
00407acb  89df                     mov       edi, ebx
00407acd  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00407acf  0f85f6000000             jne       0x407bcb
00407ad5  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407ad8  68ac455500               push      0x5545ac
00407add  e86ea00900               call      0x4a1b50 ; _jwe_iinf
00407ae2  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407ae5  83c404                   add       esp, 4
00407ae8  85c0                     test      eax, eax
00407aea  0f8558110000             jne       0x408c48
00407af0  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407af3  6894455500               push      0x554594
00407af8  e853a00900               call      0x4a1b50 ; _jwe_iinf
00407afd  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407b00  83c404                   add       esp, 4
00407b03  85c0                     test      eax, eax
00407b05  0f8545110000             jne       0x408c50
00407b0b  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407b11  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407b14  8b08                     mov       ecx, dword ptr [eax]
00407b16  8b151c4b5500             mov       edx, dword ptr [0x554b1c] ; bits=00000000, f32=0.0
00407b1c  8d1d68455500             lea       ebx, [0x554568] ; bits=09020000, f32=7.300764999132297e-43
00407b22  894dfc                   mov       dword ptr [ebp - 4], ecx
00407b25  8d4dfc                   lea       ecx, [ebp - 4]
00407b28  894b08                   mov       dword ptr [ebx + 8], ecx
00407b2b  8955ec                   mov       dword ptr [ebp - 0x14], edx
00407b2e  8d4dec                   lea       ecx, [ebp - 0x14]
00407b31  894b28                   mov       dword ptr [ebx + 0x28], ecx
00407b34  53                       push      ebx
00407b35  e8b6aa0900               call      0x4a25f0 ; _jwe_isfm
00407b3a  83c404                   add       esp, 4
00407b3d  6a50                     push      0x50
00407b3f  68e04b5500               push      0x554be0
00407b44  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407b4a  8d08                     lea       ecx, [eax]
00407b4c  51                       push      ecx
00407b4d  8b8da8feffff             mov       ecx, dword ptr [ebp - 0x158]
00407b53  8d11                     lea       edx, [ecx]
00407b55  52                       push      edx
00407b56  e8854d0400               call      0x44c8e0 ; _inline_
00407b5b  83c410                   add       esp, 0x10
00407b5e  6848455500               push      0x554548
00407b63  e8e89f0900               call      0x4a1b50 ; _jwe_iinf
00407b68  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407b6b  83c404                   add       esp, 4
00407b6e  85c0                     test      eax, eax
00407b70  0f85e2100000             jne       0x408c58
00407b76  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407b79  6830455500               push      0x554530
00407b7e  e8cd9f0900               call      0x4a1b50 ; _jwe_iinf
00407b83  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407b86  83c404                   add       esp, 4
00407b89  85c0                     test      eax, eax
00407b8b  0f85cb100000             jne       0x408c5c
00407b91  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407b97  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407b9a  8b08                     mov       ecx, dword ptr [eax]
00407b9c  8b15204b5500             mov       edx, dword ptr [0x554b20] ; bits=00000000, f32=0.0
00407ba2  8d1d04455500             lea       ebx, [0x554504] ; bits=09020000, f32=7.300764999132297e-43
00407ba8  894dfc                   mov       dword ptr [ebp - 4], ecx
00407bab  8d4dfc                   lea       ecx, [ebp - 4]
00407bae  894b08                   mov       dword ptr [ebx + 8], ecx
00407bb1  8955ec                   mov       dword ptr [ebp - 0x14], edx
00407bb4  8d4dec                   lea       ecx, [ebp - 0x14]
00407bb7  894b28                   mov       dword ptr [ebx + 0x28], ecx
00407bba  53                       push      ebx
00407bbb  e830aa0900               call      0x4a25f0 ; _jwe_isfm
00407bc0  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407bc3  83c404                   add       esp, 4
00407bc6  e9c6feffff               jmp       0x407a91
00407bcb  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407bce  68e4445500               push      0x5544e4
00407bd3  e8789f0900               call      0x4a1b50 ; _jwe_iinf
00407bd8  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407bdb  83c404                   add       esp, 4
00407bde  85c0                     test      eax, eax
00407be0  0f8566100000             jne       0x408c4c
00407be6  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407be9  8b8d98feffff             mov       ecx, dword ptr [ebp - 0x168]
00407bef  8d05d8445500             lea       eax, [0x5544d8] ; bits=61090000, f32=3.364517612843886e-42
00407bf5  8d148d38216000           lea       edx, [ecx*4 + 0x602138]
00407bfc  895008                   mov       dword ptr [eax + 8], edx
00407bff  50                       push      eax
00407c00  e84b9f0900               call      0x4a1b50 ; _jwe_iinf
00407c05  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407c08  83c404                   add       esp, 4
00407c0b  85c0                     test      eax, eax
00407c0d  0f8541100000             jne       0x408c54
00407c13  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407c19  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407c1c  8b8d98feffff             mov       ecx, dword ptr [ebp - 0x168]
00407c22  8b18                     mov       ebx, dword ptr [eax]
00407c24  8b148d38216000           mov       edx, dword ptr [ecx*4 + 0x602138]
00407c2b  8d35ac445500             lea       esi, [0x5544ac] ; bits=09020000, f32=7.300764999132297e-43
00407c31  895dfc                   mov       dword ptr [ebp - 4], ebx
00407c34  8d7dfc                   lea       edi, [ebp - 4]
00407c37  897e08                   mov       dword ptr [esi + 8], edi
00407c3a  8955ec                   mov       dword ptr [ebp - 0x14], edx
00407c3d  8d55ec                   lea       edx, [ebp - 0x14]
00407c40  895628                   mov       dword ptr [esi + 0x28], edx
00407c43  56                       push      esi
00407c44  e8a7a90900               call      0x4a25f0 ; _jwe_isfm
00407c49  83c404                   add       esp, 4
00407c4c  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00407c52  d9048538216000           fld       dword ptr [eax*4 + 0x602138]
00407c59  d815183e5500             fcom      dword ptr [0x553e18] ; bits=00000000, f32=0.0
00407c5f  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407c62  dfe0                     fnstsw    ax
00407c64  9e                       sahf
00407c65  0f8a18000000             jp        0x407c83
00407c6b  7716                     ja        0x407c83
00407c6d  ddd8                     fstp      st(0)
00407c6f  ddd8                     fstp      st(0)
00407c71  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00407c77  48                       dec       eax
00407c78  8905c04a5500             mov       dword ptr [0x554ac0], eax ; bits=00000000, f32=0.0
00407c7e  e993000000               jmp       0x407d16
00407c83  d9c9                     fxch      st(1)
00407c85  d8d1                     fcom      st(1)
00407c87  ddd9                     fstp      st(1)
00407c89  dfe0                     fnstsw    ax
00407c8b  9e                       sahf
00407c8c  0f8a35000000             jp        0x407cc7
00407c92  7733                     ja        0x407cc7
00407c94  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407c97  8d0580445500             lea       eax, [0x554480] ; bits=09020000, f32=7.300764999132297e-43
00407c9d  895dfc                   mov       dword ptr [ebp - 4], ebx
00407ca0  8d4dfc                   lea       ecx, [ebp - 4]
00407ca3  894808                   mov       dword ptr [eax + 8], ecx
00407ca6  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407ca9  d95dec                   fstp      dword ptr [ebp - 0x14]
00407cac  8d4dec                   lea       ecx, [ebp - 0x14]
00407caf  894828                   mov       dword ptr [eax + 0x28], ecx
00407cb2  50                       push      eax
00407cb3  e838a90900               call      0x4a25f0 ; _jwe_isfm
00407cb8  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407cbb  83c404                   add       esp, 4
00407cbe  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00407cc1  c70001000000             mov       dword ptr [eax], 1
00407cc7  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00407ccd  40                       inc       eax
00407cce  3d97000000               cmp       eax, 0x97
00407cd3  898598feffff             mov       dword ptr [ebp - 0x168], eax
00407cd9  0f8eb2fdffff             jle       0x407a91
00407cdf  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407ce2  8d0554445500             lea       eax, [0x554454] ; bits=09020000, f32=7.300764999132297e-43
00407ce8  895dfc                   mov       dword ptr [ebp - 4], ebx
00407ceb  8d4dfc                   lea       ecx, [ebp - 4]
00407cee  894808                   mov       dword ptr [eax + 8], ecx
00407cf1  50                       push      eax
00407cf2  e8f9a80900               call      0x4a25f0 ; _jwe_isfm
00407cf7  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407cfa  83c404                   add       esp, 4
00407cfd  b897000000               mov       eax, 0x97
00407d02  8b4d20                   mov       ecx, dword ptr [ebp + 0x20]
00407d05  c70101000000             mov       dword ptr [ecx], 1
00407d0b  898598feffff             mov       dword ptr [ebp - 0x168], eax
00407d11  e97bfdffff               jmp       0x407a91
00407d16  813dbc4a55005e010000     cmp       dword ptr [0x554abc], 0x15e ; bits=00000000, f32=0.0
00407d20  7e21                     jle       0x407d43
00407d22  8d0528445500             lea       eax, [0x554428] ; bits=09020000, f32=7.300764999132297e-43
00407d28  895dfc                   mov       dword ptr [ebp - 4], ebx
00407d2b  8d4dfc                   lea       ecx, [ebp - 4]
00407d2e  894808                   mov       dword ptr [eax + 8], ecx
00407d31  50                       push      eax
00407d32  e8b9a80900               call      0x4a25f0 ; _jwe_isfm
00407d37  83c404                   add       esp, 4
00407d3a  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00407d3d  c70001000000             mov       dword ptr [eax], 1
00407d43  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00407d46  833800                   cmp       dword ptr [eax], 0
00407d49  0f85540f0000             jne       0x408ca3
00407d4f  d9051c4b5500             fld       dword ptr [0x554b1c] ; bits=00000000, f32=0.0
00407d55  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
00407d5b  dfe0                     fnstsw    ax
00407d5d  9e                       sahf
00407d5e  0f8a62000000             jp        0x407dc6
00407d64  7660                     jbe       0x407dc6
00407d66  dd0560f70e04             fld       qword ptr [0x40ef760] ; _epscom_
00407d6c  8d15503e5500             lea       edx, [0x553e50] ; bits=01000000, f32=1.401298464324817e-45
00407d72  dd4288                   fld       qword ptr [edx - 0x78]
00407d75  dc2d60f70e04             fsubr     qword ptr [0x40ef760] ; _epscom_
00407d7b  d9e1                     fabs
00407d7d  dc4ab8                   fmul      qword ptr [edx - 0x48]
00407d80  dd4298                   fld       qword ptr [edx - 0x68]
00407d83  d9c9                     fxch      st(1)
00407d85  dc5a98                   fcomp     qword ptr [edx - 0x68]
00407d88  dd5d98                   fstp      qword ptr [ebp - 0x68]
00407d8b  dfe0                     fnstsw    ax
00407d8d  9e                       sahf
00407d8e  0f8a02000000             jp        0x407d96
00407d94  761c                     jbe       0x407db2
00407d96  dc6290                   fsub      qword ptr [edx - 0x70]
00407d99  d9e1                     fabs
00407d9b  dc4a80                   fmul      qword ptr [edx - 0x80]
00407d9e  dc5d98                   fcomp     qword ptr [ebp - 0x68]
00407da1  dfe0                     fnstsw    ax
00407da3  9e                       sahf
00407da4  0f8a1c000000             jp        0x407dc6
00407daa  0f8716000000             ja        0x407dc6
00407db0  eb02                     jmp       0x407db4
00407db2  ddd8                     fstp      st(0)
00407db4  dd05103e5500             fld       qword ptr [0x553e10] ; bits=000000000000e03f, f64=0.5
00407dba  dc0d60f70e04             fmul      qword ptr [0x40ef760] ; _epscom_
00407dc0  dd1d60f70e04             fstp      qword ptr [0x40ef760] ; _epscom_
00407dc6  8d0508445500             lea       eax, [0x554408] ; bits=69020000, f32=8.646011524884121e-43
00407dcc  895dfc                   mov       dword ptr [ebp - 4], ebx
00407dcf  8d4dfc                   lea       ecx, [ebp - 4]
00407dd2  894808                   mov       dword ptr [eax + 8], ecx
00407dd5  50                       push      eax
00407dd6  e815a80900               call      0x4a25f0 ; _jwe_isfm
00407ddb  83c404                   add       esp, 4
00407dde  68cc4a5500               push      0x554acc
00407de3  68d04a5500               push      0x554ad0
00407de8  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407dee  8d08                     lea       ecx, [eax]
00407df0  51                       push      ecx
00407df1  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00407df4  8d09                     lea       ecx, [ecx]
00407df6  51                       push      ecx
00407df7  e804fb0200               call      0x437900 ; _chkcfc_
00407dfc  83c410                   add       esp, 0x10
00407dff  833dcc4a550000           cmp       dword ptr [0x554acc], 0 ; bits=00000000, f32=0.0
00407e06  7420                     je        0x407e28
00407e08  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407e0e  8b08                     mov       ecx, dword ptr [eax]
00407e10  8d15e8435500             lea       edx, [0x5543e8] ; bits=69020000, f32=8.646011524884121e-43
00407e16  894dfc                   mov       dword ptr [ebp - 4], ecx
00407e19  8d4dfc                   lea       ecx, [ebp - 4]
00407e1c  894a08                   mov       dword ptr [edx + 8], ecx
00407e1f  52                       push      edx
00407e20  e8cba70900               call      0x4a25f0 ; _jwe_isfm
00407e25  83c404                   add       esp, 4
00407e28  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407e2e  8b18                     mov       ebx, dword ptr [eax]
00407e30  8d0dc8435500             lea       ecx, [0x5543c8] ; bits=69020000, f32=8.646011524884121e-43
00407e36  895dfc                   mov       dword ptr [ebp - 4], ebx
00407e39  8d55fc                   lea       edx, [ebp - 4]
00407e3c  895108                   mov       dword ptr [ecx + 8], edx
00407e3f  51                       push      ecx
00407e40  e8aba70900               call      0x4a25f0 ; _jwe_isfm
00407e45  83c404                   add       esp, 4
00407e48  d905e84a5500             fld       dword ptr [0x554ae8] ; bits=00000000, f32=0.0
00407e4e  d80d2c3e5500             fmul      dword ptr [0x553e2c] ; bits=0000003f, f32=0.5
00407e54  d80dfc4a5500             fmul      dword ptr [0x554afc] ; bits=00000000, f32=0.0
00407e5a  d9c0                     fld       st(0)
00407e5c  d805ec4a5500             fadd      dword ptr [0x554aec] ; bits=00000000, f32=0.0
00407e62  d91d0c4b5500             fstp      dword ptr [0x554b0c] ; bits=00000000, f32=0.0
00407e68  d82dec4a5500             fsubr     dword ptr [0x554aec] ; bits=00000000, f32=0.0
00407e6e  d91d144b5500             fstp      dword ptr [0x554b14] ; bits=00000000, f32=0.0
00407e74  d905144b5500             fld       dword ptr [0x554b14] ; bits=00000000, f32=0.0
00407e7a  d82d0c4b5500             fsubr     dword ptr [0x554b0c] ; bits=00000000, f32=0.0
00407e80  d91d304b5500             fstp      dword ptr [0x554b30] ; bits=00000000, f32=0.0
00407e86  d905304b5500             fld       dword ptr [0x554b30] ; bits=00000000, f32=0.0
00407e8c  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
00407e92  dfe0                     fnstsw    ax
00407e94  9e                       sahf
00407e95  0f8a0c000000             jp        0x407ea7
00407e9b  730a                     jae       0x407ea7
00407e9d  c705304b550000000000     mov       dword ptr [0x554b30], 0 ; bits=00000000, f32=0.0
00407ea7  d905144b5500             fld       dword ptr [0x554b14] ; bits=00000000, f32=0.0
00407ead  d8150c4b5500             fcom      dword ptr [0x554b0c] ; bits=00000000, f32=0.0
00407eb3  dfe0                     fnstsw    ax
00407eb5  66a90041                 test      ax, 0x4100
00407eb9  7408                     je        0x407ec3
00407ebb  ddd8                     fstp      st(0)
00407ebd  d9050c4b5500             fld       dword ptr [0x554b0c] ; bits=00000000, f32=0.0
00407ec3  d91df44a5500             fstp      dword ptr [0x554af4] ; bits=00000000, f32=0.0
00407ec9  8b05f44a5500             mov       eax, dword ptr [0x554af4] ; bits=00000000, f32=0.0
00407ecf  8d0d9c435500             lea       ecx, [0x55439c] ; bits=09020000, f32=7.300764999132297e-43
00407ed5  895dfc                   mov       dword ptr [ebp - 4], ebx
00407ed8  8d55fc                   lea       edx, [ebp - 4]
00407edb  895108                   mov       dword ptr [ecx + 8], edx
00407ede  8945ec                   mov       dword ptr [ebp - 0x14], eax
00407ee1  8d45ec                   lea       eax, [ebp - 0x14]
00407ee4  894128                   mov       dword ptr [ecx + 0x28], eax
00407ee7  51                       push      ecx
00407ee8  e803a70900               call      0x4a25f0 ; _jwe_isfm
00407eed  83c404                   add       esp, 4
00407ef0  d9051c4b5500             fld       dword ptr [0x554b1c] ; bits=00000000, f32=0.0
00407ef6  d9ee                     fldz
00407ef8  d9c9                     fxch      st(1)
00407efa  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
00407f00  dfe0                     fnstsw    ax
00407f02  9e                       sahf
00407f03  0f8a63000000             jp        0x407f6c
00407f09  7661                     jbe       0x407f6c
00407f0b  ddd8                     fstp      st(0)
00407f0d  8b5d20                   mov       ebx, dword ptr [ebp + 0x20]
00407f10  8d03                     lea       eax, [ebx]
00407f12  50                       push      eax
00407f13  6898236000               push      0x602398
00407f18  68bc4a5500               push      0x554abc
00407f1d  683c216000               push      0x60213c
00407f22  68c04a5500               push      0x554ac0
00407f27  682c4b5500               push      0x554b2c
00407f2c  68144b5500               push      0x554b14
00407f31  680c4b5500               push      0x554b0c
00407f36  68f44a5500               push      0x554af4
00407f3b  68204b5500               push      0x554b20
00407f40  681c4b5500               push      0x554b1c
00407f45  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00407f4b  8d08                     lea       ecx, [eax]
00407f4d  51                       push      ecx
00407f4e  e85d0d0000               call      0x408cb0 ; _chanrat_opt_
00407f53  83c430                   add       esp, 0x30
00407f56  833b00                   cmp       dword ptr [ebx], 0
00407f59  0f8e03010000             jle       0x408062
00407f5f  68e43f5500               push      0x553fe4
00407f64  e8d7b40900               call      0x4a3440 ; _jwe_xstp
00407f69  83c404                   add       esp, 4
00407f6c  8b1dbc4a5500             mov       ebx, dword ptr [0x554abc] ; bits=00000000, f32=0.0
00407f72  83fb00                   cmp       ebx, 0
00407f75  0f8ee5000000             jle       0x408060
00407f7b  b801000000               mov       eax, 1
00407f80  89d9                     mov       ecx, ebx
00407f82  49                       dec       ecx
00407f83  894dfc                   mov       dword ptr [ebp - 4], ecx
00407f86  d9e8                     fld1
00407f88  da75fc                   fidiv     dword ptr [ebp - 4]
00407f8b  db7d8c                   fstp      xword ptr [ebp - 0x74]
00407f8e  db7d80                   fstp      xword ptr [ebp - 0x80]
00407f91  83fb02                   cmp       ebx, 2
00407f94  898598feffff             mov       dword ptr [ebp - 0x168], eax
00407f9a  0f8c91000000             jl        0x408031
00407fa0  db6d80                   fld       xword ptr [ebp - 0x80]
00407fa3  db6d8c                   fld       xword ptr [ebp - 0x74]
00407fa6  db7dbc                   fstp      xword ptr [ebp - 0x44]
00407fa9  db7dc8                   fstp      xword ptr [ebp - 0x38]
00407fac  db6dc8                   fld       xword ptr [ebp - 0x38]
00407faf  db6dbc                   fld       xword ptr [ebp - 0x44]
00407fb2  dec9                     fmulp     st(1)
00407fb4  68004b5500               push      0x554b00
00407fb9  d95dec                   fstp      dword ptr [ebp - 0x14]
00407fbc  8d45ec                   lea       eax, [ebp - 0x14]
00407fbf  50                       push      eax
00407fc0  e8eb870900               call      0x4a07b0 ; _g_arxr
00407fc5  83c408                   add       esp, 8
00407fc8  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00407fce  d91c8594236000           fstp      dword ptr [eax*4 + 0x602394]
00407fd5  db6dc8                   fld       xword ptr [ebp - 0x38]
00407fd8  d805343e5500             fadd      dword ptr [0x553e34] ; bits=0000803f, f32=1.0
00407fde  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00407fe1  db6dd4                   fld       xword ptr [ebp - 0x2c]
00407fe4  db6dbc                   fld       xword ptr [ebp - 0x44]
00407fe7  dec9                     fmulp     st(1)
00407fe9  d95dec                   fstp      dword ptr [ebp - 0x14]
00407fec  68004b5500               push      0x554b00
00407ff1  8d4dec                   lea       ecx, [ebp - 0x14]
00407ff4  51                       push      ecx
00407ff5  e8b6870900               call      0x4a07b0 ; _g_arxr
00407ffa  83c408                   add       esp, 8
00407ffd  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00408003  d91c8598236000           fstp      dword ptr [eax*4 + 0x602398]
0040800a  db6dd4                   fld       xword ptr [ebp - 0x2c]
0040800d  d805343e5500             fadd      dword ptr [0x553e34] ; bits=0000803f, f32=1.0
00408013  db6dbc                   fld       xword ptr [ebp - 0x44]
00408016  83c002                   add       eax, 2
00408019  83eb02                   sub       ebx, 2
0040801c  83fb02                   cmp       ebx, 2
0040801f  898598feffff             mov       dword ptr [ebp - 0x168], eax
00408025  0f8d7bffffff             jge       0x407fa6
0040802b  db7d8c                   fstp      xword ptr [ebp - 0x74]
0040802e  db7d80                   fstp      xword ptr [ebp - 0x80]
00408031  85db                     test      ebx, ebx
00408033  742d                     je        0x408062
00408035  db6d80                   fld       xword ptr [ebp - 0x80]
00408038  db6d8c                   fld       xword ptr [ebp - 0x74]
0040803b  dec9                     fmulp     st(1)
0040803d  d95dec                   fstp      dword ptr [ebp - 0x14]
00408040  68004b5500               push      0x554b00
00408045  8d45ec                   lea       eax, [ebp - 0x14]
00408048  50                       push      eax
00408049  e862870900               call      0x4a07b0 ; _g_arxr
0040804e  83c408                   add       esp, 8
00408051  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00408057  d91c8594236000           fstp      dword ptr [eax*4 + 0x602394]
0040805e  eb02                     jmp       0x408062
00408060  ddd8                     fstp      st(0)
00408062  8b052c3e5500             mov       eax, dword ptr [0x553e2c] ; bits=0000003f, f32=0.5
00408068  8905104b5500             mov       dword ptr [0x554b10], eax ; bits=00000000, f32=0.0
0040806e  d9ee                     fldz
00408070  dd9d78ffffff             fstp      qword ptr [ebp - 0x88]
00408076  d9ee                     fldz
00408078  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
0040807e  b800000000               mov       eax, 0
00408083  898594feffff             mov       dword ptr [ebp - 0x16c], eax
00408089  898590feffff             mov       dword ptr [ebp - 0x170], eax
0040808f  8b05c04a5500             mov       eax, dword ptr [0x554ac0] ; bits=00000000, f32=0.0
00408095  3d00000000               cmp       eax, 0
0040809a  89858cfeffff             mov       dword ptr [ebp - 0x174], eax
004080a0  0f8ef5080000             jle       0x40899b
004080a6  b801000000               mov       eax, 1
004080ab  8b0dbc4a5500             mov       ecx, dword ptr [0x554abc] ; bits=00000000, f32=0.0
004080b1  8d14c9                   lea       edx, [ecx + ecx*8]
004080b4  8d1451                   lea       edx, [ecx + edx*2]
004080b7  c1e203                   shl       edx, 3
004080ba  29ca                     sub       edx, ecx
004080bc  899588feffff             mov       dword ptr [ebp - 0x178], edx
004080c2  49                       dec       ecx
004080c3  8d59ff                   lea       ebx, [ecx - 1]
004080c6  8d34c9                   lea       esi, [ecx + ecx*8]
004080c9  8d3471                   lea       esi, [ecx + esi*2]
004080cc  c1e603                   shl       esi, 3
004080cf  29ce                     sub       esi, ecx
004080d1  89b584feffff             mov       dword ptr [ebp - 0x17c], esi
004080d7  898598feffff             mov       dword ptr [ebp - 0x168], eax
004080dd  898d80feffff             mov       dword ptr [ebp - 0x180], ecx
004080e3  89957cfeffff             mov       dword ptr [ebp - 0x184], edx
004080e9  899d78feffff             mov       dword ptr [ebp - 0x188], ebx
004080ef  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
004080f5  8b0c8538216000           mov       ecx, dword ptr [eax*4 + 0x602138]
004080fc  890df84a5500             mov       dword ptr [0x554af8], ecx ; bits=00000000, f32=0.0
00408102  3d01000000               cmp       eax, 1
00408107  7579                     jne       0x408182
00408109  68f04a5500               push      0x554af0
0040810e  68044b5500               push      0x554b04
00408113  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00408116  8d00                     lea       eax, [eax]
00408118  50                       push      eax
00408119  68104b5500               push      0x554b10
0040811e  68144b5500               push      0x554b14
00408123  680c4b5500               push      0x554b0c
00408128  68f44a5500               push      0x554af4
0040812d  68f84a5500               push      0x554af8
00408132  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00408138  8d08                     lea       ecx, [eax]
0040813a  51                       push      ecx
0040813b  e8a0ecffff               call      0x406de0 ; _frfchn_
00408140  83c424                   add       esp, 0x24
00408143  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00408149  c704851029600000000000   mov       dword ptr [eax*4 + 0x602910], 0
00408154  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
0040815a  8d1401                   lea       edx, [ecx + eax]
0040815d  8b1d044b5500             mov       ebx, dword ptr [0x554b04] ; bits=00000000, f32=0.0
00408163  891c95b4266000           mov       dword ptr [edx*4 + 0x6026b4], ebx
0040816a  8d15601f6000             lea       edx, [0x601f60]
00408170  8b1df04a5500             mov       ebx, dword ptr [0x554af0] ; bits=00000000, f32=0.0
00408176  899c827cffffff           mov       dword ptr [edx + eax*4 - 0x84], ebx
0040817d  e956020000               jmp       0x4083d8
00408182  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00408188  d9048534216000           fld       dword ptr [eax*4 + 0x602134]
0040818f  dbbd60ffffff             fstp      xword ptr [ebp - 0xa0]
00408195  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
0040819b  d805f84a5500             fadd      dword ptr [0x554af8] ; bits=00000000, f32=0.0
004081a1  8d1d503e5500             lea       ebx, [0x553e50] ; bits=01000000, f32=1.401298464324817e-45
004081a7  d84bdc                   fmul      dword ptr [ebx - 0x24]
004081aa  d91d284b5500             fstp      dword ptr [0x554b28] ; bits=00000000, f32=0.0
004081b0  68f04a5500               push      0x554af0
004081b5  68244b5500               push      0x554b24
004081ba  8b7520                   mov       esi, dword ptr [ebp + 0x20]
004081bd  8d0e                     lea       ecx, [esi]
004081bf  51                       push      ecx
004081c0  68104b5500               push      0x554b10
004081c5  68144b5500               push      0x554b14
004081ca  680c4b5500               push      0x554b0c
004081cf  68f44a5500               push      0x554af4
004081d4  68284b5500               push      0x554b28
004081d9  8b8da4feffff             mov       ecx, dword ptr [ebp - 0x15c]
004081df  8d11                     lea       edx, [ecx]
004081e1  52                       push      edx
004081e2  e8f9ebffff               call      0x406de0 ; _frfchn_
004081e7  83c424                   add       esp, 0x24
004081ea  68f04a5500               push      0x554af0
004081ef  68044b5500               push      0x554b04
004081f4  8d36                     lea       esi, [esi]
004081f6  56                       push      esi
004081f7  68104b5500               push      0x554b10
004081fc  68144b5500               push      0x554b14
00408201  680c4b5500               push      0x554b0c
00408206  68f44a5500               push      0x554af4
0040820b  68f84a5500               push      0x554af8
00408210  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00408216  8d08                     lea       ecx, [eax]
00408218  51                       push      ecx
00408219  e8c2ebffff               call      0x406de0 ; _frfchn_
0040821e  83c424                   add       esp, 0x24
00408221  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00408227  c704851029600000000000   mov       dword ptr [eax*4 + 0x602910], 0
00408232  8b8d7cfeffff             mov       ecx, dword ptr [ebp - 0x184]
00408238  8d1401                   lea       edx, [ecx + eax]
0040823b  8b35044b5500             mov       esi, dword ptr [0x554b04] ; bits=00000000, f32=0.0
00408241  893495b4266000           mov       dword ptr [edx*4 + 0x6026b4], esi
00408248  8d15601f6000             lea       edx, [0x601f60]
0040824e  8b35f04a5500             mov       esi, dword ptr [0x554af0] ; bits=00000000, f32=0.0
00408254  89b4827cffffff           mov       dword ptr [edx + eax*4 - 0x84], esi
0040825b  8b5520                   mov       edx, dword ptr [ebp + 0x20]
0040825e  833a00                   cmp       dword ptr [edx], 0
00408261  0f853c0a0000             jne       0x408ca3
00408267  8b8d88feffff             mov       ecx, dword ptr [ebp - 0x178]
0040826d  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00408273  8d1401                   lea       edx, [ecx + eax]
00408276  d905044b5500             fld       dword ptr [0x554b04] ; bits=00000000, f32=0.0
0040827c  d80495b0266000           fadd      dword ptr [edx*4 + 0x6026b0]
00408283  d84bdc                   fmul      dword ptr [ebx - 0x24]
00408286  d825244b5500             fsub      dword ptr [0x554b24] ; bits=00000000, f32=0.0
0040828c  d835244b5500             fdiv      dword ptr [0x554b24] ; bits=00000000, f32=0.0
00408292  dbbd54ffffff             fstp      xword ptr [ebp - 0xac]
00408298  d905f84a5500             fld       dword ptr [0x554af8] ; bits=00000000, f32=0.0
0040829e  dbad6cffffff             fld       xword ptr [ebp - 0x94]
004082a4  d805f84a5500             fadd      dword ptr [0x554af8] ; bits=00000000, f32=0.0
004082aa  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004082b0  dee9                     fsubp     st(1)
004082b2  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
004082b8  dbad54ffffff             fld       xword ptr [ebp - 0xac]
004082be  dbad54ffffff             fld       xword ptr [ebp - 0xac]
004082c4  dec9                     fmulp     st(1)
004082c6  d84be0                   fmul      dword ptr [ebx - 0x20]
004082c9  dbad60ffffff             fld       xword ptr [ebp - 0xa0]
004082cf  deea                     fsubp     st(2)
004082d1  dec9                     fmulp     st(1)
004082d3  dc8578ffffff             fadd      qword ptr [ebp - 0x88]
004082d9  8b95a4feffff             mov       edx, dword ptr [ebp - 0x15c]
004082df  dd9d78ffffff             fstp      qword ptr [ebp - 0x88]
004082e5  8b32                     mov       esi, dword ptr [edx]
004082e7  8b3c8534216000           mov       edi, dword ptr [eax*4 + 0x602134]
004082ee  8b0df84a5500             mov       ecx, dword ptr [0x554af8] ; bits=00000000, f32=0.0
004082f4  8d1558435500             lea       edx, [0x554358] ; bits=09020000, f32=7.300764999132297e-43
004082fa  8975fc                   mov       dword ptr [ebp - 4], esi
004082fd  8d75fc                   lea       esi, [ebp - 4]
00408300  897208                   mov       dword ptr [edx + 8], esi
00408303  897dec                   mov       dword ptr [ebp - 0x14], edi
00408306  8d75ec                   lea       esi, [ebp - 0x14]
00408309  897228                   mov       dword ptr [edx + 0x28], esi
0040830c  894de8                   mov       dword ptr [ebp - 0x18], ecx
0040830f  8d4de8                   lea       ecx, [ebp - 0x18]
00408312  894a34                   mov       dword ptr [edx + 0x34], ecx
00408315  dbad54ffffff             fld       xword ptr [ebp - 0xac]
0040831b  d95de4                   fstp      dword ptr [ebp - 0x1c]
0040831e  8d4de4                   lea       ecx, [ebp - 0x1c]
00408321  894a40                   mov       dword ptr [edx + 0x40], ecx
00408324  52                       push      edx
00408325  e8c6a20900               call      0x4a25f0 ; _jwe_isfm
0040832a  83c404                   add       esp, 4
0040832d  dbad54ffffff             fld       xword ptr [ebp - 0xac]
00408333  d9e1                     fabs
00408335  dbbd48ffffff             fstp      xword ptr [ebp - 0xb8]
0040833b  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
00408341  db6db0                   fld       xword ptr [ebp - 0x50]
00408344  d9c9                     fxch      st(1)
00408346  ded9                     fcompp
00408348  dfe0                     fnstsw    ax
0040834a  9e                       sahf
0040834b  0f8a26000000             jp        0x408377
00408351  7624                     jbe       0x408377
00408353  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
00408359  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
0040835f  db7db0                   fstp      xword ptr [ebp - 0x50]
00408362  8d48ff                   lea       ecx, [eax - 1]
00408365  890dd44a5500             mov       dword ptr [0x554ad4], ecx ; bits=00000000, f32=0.0
0040836b  8b0dbc4a5500             mov       ecx, dword ptr [0x554abc] ; bits=00000000, f32=0.0
00408371  890dd84a5500             mov       dword ptr [0x554ad8], ecx ; bits=00000000, f32=0.0
00408377  d9051c4b5500             fld       dword ptr [0x554b1c] ; bits=00000000, f32=0.0
0040837d  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
00408383  d81d1c4b5500             fcomp     dword ptr [0x554b1c] ; bits=00000000, f32=0.0
00408389  dbbd3cffffff             fstp      xword ptr [ebp - 0xc4]
0040838f  dfe0                     fnstsw    ax
00408391  9e                       sahf
00408392  0f8a40000000             jp        0x4083d8
00408398  763e                     jbe       0x4083d8
0040839a  dbad3cffffff             fld       xword ptr [ebp - 0xc4]
004083a0  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
004083a6  dfe0                     fnstsw    ax
004083a8  9e                       sahf
004083a9  0f8a29000000             jp        0x4083d8
004083af  7627                     jbe       0x4083d8
004083b1  ff8590feffff             inc       dword ptr [ebp - 0x170]
004083b7  dbad3cffffff             fld       xword ptr [ebp - 0xc4]
004083bd  d8c0                     fadd      st(0)
004083bf  dbad48ffffff             fld       xword ptr [ebp - 0xb8]
004083c5  ded9                     fcompp
004083c7  dfe0                     fnstsw    ax
004083c9  9e                       sahf
004083ca  0f8a08000000             jp        0x4083d8
004083d0  7606                     jbe       0x4083d8
004083d2  ff8594feffff             inc       dword ptr [ebp - 0x16c]
004083d8  d90590f70e04             fld       dword ptr [0x40ef790]
004083de  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
004083e4  dfe0                     fnstsw    ax
004083e6  9e                       sahf
004083e7  0f8a7e000000             jp        0x40846b
004083ed  767c                     jbe       0x40846b
004083ef  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004083f5  8b18                     mov       ebx, dword ptr [eax]
004083f7  8b0df84a5500             mov       ecx, dword ptr [0x554af8] ; bits=00000000, f32=0.0
004083fd  8b15f04a5500             mov       edx, dword ptr [0x554af0] ; bits=00000000, f32=0.0
00408403  8b3588f70e04             mov       esi, dword ptr [0x40ef788]
00408409  8d3d14435500             lea       edi, [0x554314] ; bits=09020000, f32=7.300764999132297e-43
0040840f  895dfc                   mov       dword ptr [ebp - 4], ebx
00408412  8d45fc                   lea       eax, [ebp - 4]
00408415  894708                   mov       dword ptr [edi + 8], eax
00408418  894dec                   mov       dword ptr [ebp - 0x14], ecx
0040841b  8d45ec                   lea       eax, [ebp - 0x14]
0040841e  894728                   mov       dword ptr [edi + 0x28], eax
00408421  8955e8                   mov       dword ptr [ebp - 0x18], edx
00408424  8d45e8                   lea       eax, [ebp - 0x18]
00408427  894734                   mov       dword ptr [edi + 0x34], eax
0040842a  8975e4                   mov       dword ptr [ebp - 0x1c], esi
0040842d  8d45e4                   lea       eax, [ebp - 0x1c]
00408430  894740                   mov       dword ptr [edi + 0x40], eax
00408433  57                       push      edi
00408434  e8b7a10900               call      0x4a25f0 ; _jwe_isfm
00408439  83c404                   add       esp, 4
0040843c  d905f44a5500             fld       dword ptr [0x554af4] ; bits=00000000, f32=0.0
00408442  d805f84a5500             fadd      dword ptr [0x554af8] ; bits=00000000, f32=0.0
00408448  8d05e8425500             lea       eax, [0x5542e8] ; bits=09020000, f32=7.300764999132297e-43
0040844e  895dfc                   mov       dword ptr [ebp - 4], ebx
00408451  8d4dfc                   lea       ecx, [ebp - 4]
00408454  894808                   mov       dword ptr [eax + 8], ecx
00408457  d95dec                   fstp      dword ptr [ebp - 0x14]
0040845a  8d4dec                   lea       ecx, [ebp - 0x14]
0040845d  894828                   mov       dword ptr [eax + 0x28], ecx
00408460  50                       push      eax
00408461  e88aa10900               call      0x4a25f0 ; _jwe_isfm
00408466  83c404                   add       esp, 4
00408469  eb6b                     jmp       0x4084d6
0040846b  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00408471  8b18                     mov       ebx, dword ptr [eax]
00408473  8b0df84a5500             mov       ecx, dword ptr [0x554af8] ; bits=00000000, f32=0.0
00408479  8b15f04a5500             mov       edx, dword ptr [0x554af0] ; bits=00000000, f32=0.0
0040847f  8d35b0425500             lea       esi, [0x5542b0] ; bits=09020000, f32=7.300764999132297e-43
00408485  895dfc                   mov       dword ptr [ebp - 4], ebx
00408488  8d7dfc                   lea       edi, [ebp - 4]
0040848b  897e08                   mov       dword ptr [esi + 8], edi
0040848e  894dec                   mov       dword ptr [ebp - 0x14], ecx
00408491  8d4dec                   lea       ecx, [ebp - 0x14]
00408494  894e28                   mov       dword ptr [esi + 0x28], ecx
00408497  8955e8                   mov       dword ptr [ebp - 0x18], edx
0040849a  8d4de8                   lea       ecx, [ebp - 0x18]
0040849d  894e34                   mov       dword ptr [esi + 0x34], ecx
004084a0  56                       push      esi
004084a1  e84aa10900               call      0x4a25f0 ; _jwe_isfm
004084a6  83c404                   add       esp, 4
004084a9  d905f44a5500             fld       dword ptr [0x554af4] ; bits=00000000, f32=0.0
004084af  d805f84a5500             fadd      dword ptr [0x554af8] ; bits=00000000, f32=0.0
004084b5  8d0584425500             lea       eax, [0x554284] ; bits=09020000, f32=7.300764999132297e-43
004084bb  895dfc                   mov       dword ptr [ebp - 4], ebx
004084be  8d4dfc                   lea       ecx, [ebp - 4]
004084c1  894808                   mov       dword ptr [eax + 8], ecx
004084c4  d95dec                   fstp      dword ptr [ebp - 0x14]
004084c7  8d4dec                   lea       ecx, [ebp - 0x14]
004084ca  894828                   mov       dword ptr [eax + 0x28], ecx
004084cd  50                       push      eax
004084ce  e81da10900               call      0x4a25f0 ; _jwe_isfm
004084d3  83c404                   add       esp, 4
004084d6  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004084dc  8b08                     mov       ecx, dword ptr [eax]
004084de  8d1d64425500             lea       ebx, [0x554264] ; bits=69020000, f32=8.646011524884121e-43
004084e4  894dfc                   mov       dword ptr [ebp - 4], ecx
004084e7  8d4dfc                   lea       ecx, [ebp - 4]
004084ea  894b08                   mov       dword ptr [ebx + 8], ecx
004084ed  53                       push      ebx
004084ee  e8fda00900               call      0x4a25f0 ; _jwe_isfm
004084f3  83c404                   add       esp, 4
004084f6  6a08                     push      8
004084f8  68384c5500               push      0x554c38
004084fd  68044b5500               push      0x554b04
00408502  e8a96d0400               call      0x44f2b0 ; _var_decimal_
00408507  83c40c                   add       esp, 0xc
0040850a  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00408510  8b08                     mov       ecx, dword ptr [eax]
00408512  8b1dbc4a5500             mov       ebx, dword ptr [0x554abc] ; bits=00000000, f32=0.0
00408518  8b349d94236000           mov       esi, dword ptr [ebx*4 + 0x602394]
0040851f  d905f84a5500             fld       dword ptr [0x554af8] ; bits=00000000, f32=0.0
00408525  d905f04a5500             fld       dword ptr [0x554af0] ; bits=00000000, f32=0.0
0040852b  dbbd30ffffff             fstp      xword ptr [ebp - 0xd0]
00408531  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
00408537  dee9                     fsubp     st(1)
00408539  8b1d9cf70e04             mov       ebx, dword ptr [0x40ef79c]
0040853f  8d3d14425500             lea       edi, [0x554214] ; bits=09020000, f32=7.300764999132297e-43
00408545  894dfc                   mov       dword ptr [ebp - 4], ecx
00408548  8d4dfc                   lea       ecx, [ebp - 4]
0040854b  894f08                   mov       dword ptr [edi + 8], ecx
0040854e  8975ec                   mov       dword ptr [ebp - 0x14], esi
00408551  8d4dec                   lea       ecx, [ebp - 0x14]
00408554  894f28                   mov       dword ptr [edi + 0x28], ecx
00408557  d95de8                   fstp      dword ptr [ebp - 0x18]
0040855a  8d4de8                   lea       ecx, [ebp - 0x18]
0040855d  894f34                   mov       dword ptr [edi + 0x34], ecx
00408560  895de4                   mov       dword ptr [ebp - 0x1c], ebx
00408563  8d4de4                   lea       ecx, [ebp - 0x1c]
00408566  894f4c                   mov       dword ptr [edi + 0x4c], ecx
00408569  57                       push      edi
0040856a  e881a00900               call      0x4a25f0 ; _jwe_isfm
0040856f  83c404                   add       esp, 4
00408572  8d15503e5500             lea       edx, [0x553e50] ; bits=01000000, f32=1.401298464324817e-45
00408578  8b42ec                   mov       eax, dword ptr [edx - 0x14]
0040857b  8905084b5500             mov       dword ptr [0x554b08], eax ; bits=00000000, f32=0.0
00408581  8b8578feffff             mov       eax, dword ptr [ebp - 0x188]
00408587  898574feffff             mov       dword ptr [ebp - 0x18c], eax
0040858d  3d00000000               cmp       eax, 0
00408592  0f8ef0030000             jle       0x408988
00408598  8b8580feffff             mov       eax, dword ptr [ebp - 0x180]
0040859e  89c3                     mov       ebx, eax
004085a0  dbad30ffffff             fld       xword ptr [ebp - 0xd0]
004085a6  d84adc                   fmul      dword ptr [edx - 0x24]
004085a9  dbbd24ffffff             fstp      xword ptr [ebp - 0xdc]
004085af  8bb584feffff             mov       esi, dword ptr [ebp - 0x17c]
004085b5  8b8d98feffff             mov       ecx, dword ptr [ebp - 0x168]
004085bb  8d3c0e                   lea       edi, [esi + ecx]
004085be  8b05d84a5500             mov       eax, dword ptr [0x554ad8] ; bits=00000000, f32=0.0
004085c4  8b0dd44a5500             mov       ecx, dword ptr [0x554ad4] ; bits=00000000, f32=0.0
004085ca  898570feffff             mov       dword ptr [ebp - 0x190], eax
004085d0  898d6cfeffff             mov       dword ptr [ebp - 0x194], ecx
004085d6  89bd68feffff             mov       dword ptr [ebp - 0x198], edi
004085dc  d9049d94236000           fld       dword ptr [ebx*4 + 0x602394]
004085e3  d9049d98236000           fld       dword ptr [ebx*4 + 0x602398]
004085ea  d9c0                     fld       st(0)
004085ec  d8049d94236000           fadd      dword ptr [ebx*4 + 0x602394]
004085f3  dbad24ffffff             fld       xword ptr [ebp - 0xdc]
004085f9  dec9                     fmulp     st(1)
004085fb  d90594f70e04             fld       dword ptr [0x40ef794]
00408601  d9c0                     fld       st(0)
00408603  d8050c4b5500             fadd      dword ptr [0x554b0c] ; bits=00000000, f32=0.0
00408609  dee2                     fsubrp    st(2)
0040860b  d9c9                     fxch      st(1)
0040860d  d825144b5500             fsub      dword ptr [0x554b14] ; bits=00000000, f32=0.0
00408613  d91d98f70e04             fstp      dword ptr [0x40ef798]
00408619  d90590f70e04             fld       dword ptr [0x40ef790]
0040861f  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
00408625  d9c9                     fxch      st(1)
00408627  dbbd18ffffff             fstp      xword ptr [ebp - 0xe8]
0040862d  dbbd0cffffff             fstp      xword ptr [ebp - 0xf4]
00408633  dfe0                     fnstsw    ax
00408635  9e                       sahf
00408636  0f8a75000000             jp        0x4086b1
0040863c  7673                     jbe       0x4086b1
0040863e  dbad0cffffff             fld       xword ptr [ebp - 0xf4]
00408644  d82598f70e04             fsub      dword ptr [0x40ef798]
0040864a  d9e1                     fabs
0040864c  dbbd00ffffff             fstp      xword ptr [ebp - 0x100]
00408652  d9056cf70e04             fld       dword ptr [0x40ef76c]
00408658  d9c0                     fld       st(0)
0040865a  d805a4f70e04             fadd      dword ptr [0x40ef7a4]
00408660  d9c9                     fxch      st(1)
00408662  d805a8f70e04             fadd      dword ptr [0x40ef7a8]
00408668  dbad0cffffff             fld       xword ptr [ebp - 0xf4]
0040866e  dec9                     fmulp     st(1)
00408670  d8d1                     fcom      st(1)
00408672  d9c9                     fxch      st(1)
00408674  dbbdf4feffff             fstp      xword ptr [ebp - 0x10c]
0040867a  d9c9                     fxch      st(1)
0040867c  dfe0                     fnstsw    ax
0040867e  66a90041                 test      ax, 0x4100
00408682  750a                     jne       0x40868e
00408684  ddd9                     fstp      st(1)
00408686  dbadf4feffff             fld       xword ptr [ebp - 0x10c]
0040868c  d9c9                     fxch      st(1)
0040868e  dbad00ffffff             fld       xword ptr [ebp - 0x100]
00408694  d8da                     fcomp     st(2)
00408696  ddd9                     fstp      st(1)
00408698  dfe0                     fnstsw    ax
0040869a  9e                       sahf
0040869b  0f8a10000000             jp        0x4086b1
004086a1  730e                     jae       0x4086b1
004086a3  8b0588f70e04             mov       eax, dword ptr [0x40ef788]
004086a9  8905244b5500             mov       dword ptr [0x554b24], eax ; bits=00000000, f32=0.0
004086af  eb2e                     jmp       0x4086df
004086b1  db7dd4                   fstp      xword ptr [ebp - 0x2c]
004086b4  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004086b7  8d00                     lea       eax, [eax]
004086b9  50                       push      eax
004086ba  68084b5500               push      0x554b08
004086bf  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004086c5  8d08                     lea       ecx, [eax]
004086c7  51                       push      ecx
004086c8  e873e3ffff               call      0x406a40 ; _sbfchn_
004086cd  db6dd4                   fld       xword ptr [ebp - 0x2c]
004086d0  83c40c                   add       esp, 0xc
004086d3  8b0584f70e04             mov       eax, dword ptr [0x40ef784]
004086d9  8905244b5500             mov       dword ptr [0x554b24], eax ; bits=00000000, f32=0.0
004086df  d9c0                     fld       st(0)
004086e1  d80df04a5500             fmul      dword ptr [0x554af0] ; bits=00000000, f32=0.0
004086e7  d90594f70e04             fld       dword ptr [0x40ef794]
004086ed  d9c0                     fld       st(0)
004086ef  d8050c4b5500             fadd      dword ptr [0x554b0c] ; bits=00000000, f32=0.0
004086f5  d8e2                     fsub      st(2)
004086f7  d825144b5500             fsub      dword ptr [0x554b14] ; bits=00000000, f32=0.0
004086fd  d91d98f70e04             fstp      dword ptr [0x40ef798]
00408703  d90590f70e04             fld       dword ptr [0x40ef790]
00408709  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
0040870f  d9c9                     fxch      st(1)
00408711  dbbde8feffff             fstp      xword ptr [ebp - 0x118]
00408717  dbbddcfeffff             fstp      xword ptr [ebp - 0x124]
0040871d  dfe0                     fnstsw    ax
0040871f  9e                       sahf
00408720  0f8a75000000             jp        0x40879b
00408726  7673                     jbe       0x40879b
00408728  dbaddcfeffff             fld       xword ptr [ebp - 0x124]
0040872e  d82598f70e04             fsub      dword ptr [0x40ef798]
00408734  d9e1                     fabs
00408736  dbbdd0feffff             fstp      xword ptr [ebp - 0x130]
0040873c  d9056cf70e04             fld       dword ptr [0x40ef76c]
00408742  d9c0                     fld       st(0)
00408744  d805a4f70e04             fadd      dword ptr [0x40ef7a4]
0040874a  d9c9                     fxch      st(1)
0040874c  d805a8f70e04             fadd      dword ptr [0x40ef7a8]
00408752  dbaddcfeffff             fld       xword ptr [ebp - 0x124]
00408758  dec9                     fmulp     st(1)
0040875a  d8d1                     fcom      st(1)
0040875c  d9c9                     fxch      st(1)
0040875e  dbbdc4feffff             fstp      xword ptr [ebp - 0x13c]
00408764  d9c9                     fxch      st(1)
00408766  dfe0                     fnstsw    ax
00408768  66a90041                 test      ax, 0x4100
0040876c  750a                     jne       0x408778
0040876e  ddd9                     fstp      st(1)
00408770  dbadc4feffff             fld       xword ptr [ebp - 0x13c]
00408776  d9c9                     fxch      st(1)
00408778  dbadd0feffff             fld       xword ptr [ebp - 0x130]
0040877e  d8da                     fcomp     st(2)
00408780  ddd9                     fstp      st(1)
00408782  dfe0                     fnstsw    ax
00408784  9e                       sahf
00408785  0f8a10000000             jp        0x40879b
0040878b  730e                     jae       0x40879b
0040878d  8b0588f70e04             mov       eax, dword ptr [0x40ef788]
00408793  890584f70e04             mov       dword ptr [0x40ef784], eax
00408799  eb22                     jmp       0x4087bd
0040879b  db7dd4                   fstp      xword ptr [ebp - 0x2c]
0040879e  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004087a1  8d00                     lea       eax, [eax]
004087a3  50                       push      eax
004087a4  68084b5500               push      0x554b08
004087a9  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004087af  8d08                     lea       ecx, [eax]
004087b1  51                       push      ecx
004087b2  e889e2ffff               call      0x406a40 ; _sbfchn_
004087b7  db6dd4                   fld       xword ptr [ebp - 0x2c]
004087ba  83c40c                   add       esp, 0xc
004087bd  8b8d68feffff             mov       ecx, dword ptr [ebp - 0x198]
004087c3  8b0584f70e04             mov       eax, dword ptr [0x40ef784]
004087c9  89048db4266000           mov       dword ptr [ecx*4 + 0x6026b4], eax
004087d0  d90584f70e04             fld       dword ptr [0x40ef784]
004087d6  d8048d10296000           fadd      dword ptr [ecx*4 + 0x602910]
004087dd  d80d2c3e5500             fmul      dword ptr [0x553e2c] ; bits=0000003f, f32=0.5
004087e3  d825244b5500             fsub      dword ptr [0x554b24] ; bits=00000000, f32=0.0
004087e9  d835244b5500             fdiv      dword ptr [0x554b24] ; bits=00000000, f32=0.0
004087ef  d9c0                     fld       st(0)
004087f1  d9e1                     fabs
004087f3  db6db0                   fld       xword ptr [ebp - 0x50]
004087f6  d9c9                     fxch      st(1)
004087f8  d8d1                     fcom      st(1)
004087fa  ddd9                     fstp      st(1)
004087fc  dbbdb8feffff             fstp      xword ptr [ebp - 0x148]
00408802  dbbdacfeffff             fstp      xword ptr [ebp - 0x154]
00408808  dfe0                     fnstsw    ax
0040880a  9e                       sahf
0040880b  0f8a1f000000             jp        0x408830
00408811  761d                     jbe       0x408830
00408813  dbadb8feffff             fld       xword ptr [ebp - 0x148]
00408819  db7db0                   fstp      xword ptr [ebp - 0x50]
0040881c  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00408822  89856cfeffff             mov       dword ptr [ebp - 0x194], eax
00408828  89d9                     mov       ecx, ebx
0040882a  898d70feffff             mov       dword ptr [ebp - 0x190], ecx
00408830  d9051c4b5500             fld       dword ptr [0x554b1c] ; bits=00000000, f32=0.0
00408836  dbadb8feffff             fld       xword ptr [ebp - 0x148]
0040883c  d81d1c4b5500             fcomp     dword ptr [0x554b1c] ; bits=00000000, f32=0.0
00408842  dfe0                     fnstsw    ax
00408844  9e                       sahf
00408845  0f8a36000000             jp        0x408881
0040884b  7634                     jbe       0x408881
0040884d  d815183e5500             fcom      dword ptr [0x553e18] ; bits=00000000, f32=0.0
00408853  dfe0                     fnstsw    ax
00408855  9e                       sahf
00408856  0f8a29000000             jp        0x408885
0040885c  7627                     jbe       0x408885
0040885e  ff8590feffff             inc       dword ptr [ebp - 0x170]
00408864  d8c0                     fadd      st(0)
00408866  dbadb8feffff             fld       xword ptr [ebp - 0x148]
0040886c  ded9                     fcompp
0040886e  dfe0                     fnstsw    ax
00408870  9e                       sahf
00408871  0f8a10000000             jp        0x408887
00408877  760e                     jbe       0x408887
00408879  ff8594feffff             inc       dword ptr [ebp - 0x16c]
0040887f  eb06                     jmp       0x408887
00408881  ddd8                     fstp      st(0)
00408883  eb02                     jmp       0x408887
00408885  ddd8                     fstp      st(0)
00408887  dbadacfeffff             fld       xword ptr [ebp - 0x154]
0040888d  dbadacfeffff             fld       xword ptr [ebp - 0x154]
00408893  dec9                     fmulp     st(1)
00408895  d80d403e5500             fmul      dword ptr [0x553e40] ; bits=b0aa2a3f, f32=0.6666669845581055
0040889b  d905f04a5500             fld       dword ptr [0x554af0] ; bits=00000000, f32=0.0
004088a1  d9c9                     fxch      st(1)
004088a3  d80df04a5500             fmul      dword ptr [0x554af0] ; bits=00000000, f32=0.0
004088a9  dbad18ffffff             fld       xword ptr [ebp - 0xe8]
004088af  dee3                     fsubrp    st(3)
004088b1  deca                     fmulp     st(2)
004088b3  d9c9                     fxch      st(1)
004088b5  dc8578ffffff             fadd      qword ptr [ebp - 0x88]
004088bb  dd9d78ffffff             fstp      qword ptr [ebp - 0x88]
004088c1  d9049d94236000           fld       dword ptr [ebx*4 + 0x602394]
004088c8  d82c9d98236000           fsubr     dword ptr [ebx*4 + 0x602398]
004088cf  dec9                     fmulp     st(1)
004088d1  dbad6cffffff             fld       xword ptr [ebp - 0x94]
004088d7  dec1                     faddp     st(1)
004088d9  dbbd6cffffff             fstp      xword ptr [ebp - 0x94]
004088df  6a08                     push      8
004088e1  68384c5500               push      0x554c38
004088e6  6884f70e04               push      0x40ef784
004088eb  e8c0690400               call      0x44f2b0 ; _var_decimal_
004088f0  83c40c                   add       esp, 0xc
004088f3  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004088f9  8b08                     mov       ecx, dword ptr [eax]
004088fb  8b149d94236000           mov       edx, dword ptr [ebx*4 + 0x602394]
00408902  dbade8feffff             fld       xword ptr [ebp - 0x118]
00408908  d82df84a5500             fsubr     dword ptr [0x554af8] ; bits=00000000, f32=0.0
0040890e  8b359cf70e04             mov       esi, dword ptr [0x40ef79c]
00408914  8d3db8415500             lea       edi, [0x5541b8] ; bits=09020000, f32=7.300764999132297e-43
0040891a  894dfc                   mov       dword ptr [ebp - 4], ecx
0040891d  8d4dfc                   lea       ecx, [ebp - 4]
00408920  894f08                   mov       dword ptr [edi + 8], ecx
00408923  8955ec                   mov       dword ptr [ebp - 0x14], edx
00408926  8d4dec                   lea       ecx, [ebp - 0x14]
00408929  894f28                   mov       dword ptr [edi + 0x28], ecx
0040892c  d95de8                   fstp      dword ptr [ebp - 0x18]
0040892f  8d4de8                   lea       ecx, [ebp - 0x18]
00408932  894f34                   mov       dword ptr [edi + 0x34], ecx
00408935  8975e4                   mov       dword ptr [ebp - 0x1c], esi
00408938  8d4de4                   lea       ecx, [ebp - 0x1c]
0040893b  894f4c                   mov       dword ptr [edi + 0x4c], ecx
0040893e  dbadacfeffff             fld       xword ptr [ebp - 0x154]
00408944  d95de0                   fstp      dword ptr [ebp - 0x20]
00408947  8d4de0                   lea       ecx, [ebp - 0x20]
0040894a  894f58                   mov       dword ptr [edi + 0x58], ecx
0040894d  57                       push      edi
0040894e  e89d9c0900               call      0x4a25f0 ; _jwe_isfm
00408953  83c404                   add       esp, 4
00408956  83c3ff                   add       ebx, -1
00408959  818568feffff69ffffff     add       dword ptr [ebp - 0x198], 0xffffff69
00408963  83ad74feffff01           sub       dword ptr [ebp - 0x18c], 1
0040896a  0f856cfcffff             jne       0x4085dc
00408970  8b8570feffff             mov       eax, dword ptr [ebp - 0x190]
00408976  8905d84a5500             mov       dword ptr [0x554ad8], eax ; bits=00000000, f32=0.0
0040897c  8b856cfeffff             mov       eax, dword ptr [ebp - 0x194]
00408982  8905d44a5500             mov       dword ptr [0x554ad4], eax ; bits=00000000, f32=0.0
00408988  ff8598feffff             inc       dword ptr [ebp - 0x168]
0040898e  83ad8cfeffff01           sub       dword ptr [ebp - 0x174], 1
00408995  0f8554f7ffff             jne       0x4080ef
0040899b  8b15d84a5500             mov       edx, dword ptr [0x554ad8] ; bits=00000000, f32=0.0
004089a1  8b05bc4a5500             mov       eax, dword ptr [0x554abc] ; bits=00000000, f32=0.0
004089a7  39c2                     cmp       edx, eax
004089a9  7554                     jne       0x4089ff
004089ab  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
004089b1  8b08                     mov       ecx, dword ptr [eax]
004089b3  8b15d44a5500             mov       edx, dword ptr [0x554ad4] ; bits=00000000, f32=0.0
004089b9  8b1c9538216000           mov       ebx, dword ptr [edx*4 + 0x602138]
004089c0  8b34953c216000           mov       esi, dword ptr [edx*4 + 0x60213c]
004089c7  8d1574415500             lea       edx, [0x554174] ; bits=09020000, f32=7.300764999132297e-43
004089cd  894dfc                   mov       dword ptr [ebp - 4], ecx
004089d0  8d4dfc                   lea       ecx, [ebp - 4]
004089d3  894a08                   mov       dword ptr [edx + 8], ecx
004089d6  db6db0                   fld       xword ptr [ebp - 0x50]
004089d9  d95dec                   fstp      dword ptr [ebp - 0x14]
004089dc  8d4dec                   lea       ecx, [ebp - 0x14]
004089df  894a28                   mov       dword ptr [edx + 0x28], ecx
004089e2  895de8                   mov       dword ptr [ebp - 0x18], ebx
004089e5  8d4de8                   lea       ecx, [ebp - 0x18]
004089e8  894a34                   mov       dword ptr [edx + 0x34], ecx
004089eb  8975e4                   mov       dword ptr [ebp - 0x1c], esi
004089ee  8d4de4                   lea       ecx, [ebp - 0x1c]
004089f1  894a40                   mov       dword ptr [edx + 0x40], ecx
004089f4  52                       push      edx
004089f5  e8f69b0900               call      0x4a25f0 ; _jwe_isfm
004089fa  83c404                   add       esp, 4
004089fd  eb62                     jmp       0x408a61
004089ff  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00408a05  8b08                     mov       ecx, dword ptr [eax]
00408a07  8b1dd44a5500             mov       ebx, dword ptr [0x554ad4] ; bits=00000000, f32=0.0
00408a0d  8b349d38216000           mov       esi, dword ptr [ebx*4 + 0x602138]
00408a14  8b1c9594236000           mov       ebx, dword ptr [edx*4 + 0x602394]
00408a1b  8b3c9598236000           mov       edi, dword ptr [edx*4 + 0x602398]
00408a22  8d0524415500             lea       eax, [0x554124] ; bits=09020000, f32=7.300764999132297e-43
00408a28  894dfc                   mov       dword ptr [ebp - 4], ecx
00408a2b  8d4dfc                   lea       ecx, [ebp - 4]
00408a2e  894808                   mov       dword ptr [eax + 8], ecx
00408a31  db6db0                   fld       xword ptr [ebp - 0x50]
00408a34  d95dec                   fstp      dword ptr [ebp - 0x14]
00408a37  8d4dec                   lea       ecx, [ebp - 0x14]
00408a3a  894828                   mov       dword ptr [eax + 0x28], ecx
00408a3d  8975e8                   mov       dword ptr [ebp - 0x18], esi
00408a40  8d4de8                   lea       ecx, [ebp - 0x18]
00408a43  894834                   mov       dword ptr [eax + 0x34], ecx
00408a46  895de4                   mov       dword ptr [ebp - 0x1c], ebx
00408a49  8d4de4                   lea       ecx, [ebp - 0x1c]
00408a4c  894840                   mov       dword ptr [eax + 0x40], ecx
00408a4f  897de0                   mov       dword ptr [ebp - 0x20], edi
00408a52  8d4de0                   lea       ecx, [ebp - 0x20]
00408a55  89484c                   mov       dword ptr [eax + 0x4c], ecx
00408a58  50                       push      eax
00408a59  e8929b0900               call      0x4a25f0 ; _jwe_isfm
00408a5e  83c404                   add       esp, 4
00408a61  dbad6cffffff             fld       xword ptr [ebp - 0x94]
00408a67  dcbd78ffffff             fdivr     qword ptr [ebp - 0x88]
00408a6d  d9fa                     fsqrt
00408a6f  d95dec                   fstp      dword ptr [ebp - 0x14]
00408a72  8b8da4feffff             mov       ecx, dword ptr [ebp - 0x15c]
00408a78  8b45ec                   mov       eax, dword ptr [ebp - 0x14]
00408a7b  8b11                     mov       edx, dword ptr [ecx]
00408a7d  899564feffff             mov       dword ptr [ebp - 0x19c], edx
00408a83  8d1df8405500             lea       ebx, [0x5540f8] ; bits=09020000, f32=7.300764999132297e-43
00408a89  8955fc                   mov       dword ptr [ebp - 4], edx
00408a8c  8d75fc                   lea       esi, [ebp - 4]
00408a8f  897308                   mov       dword ptr [ebx + 8], esi
00408a92  8945ec                   mov       dword ptr [ebp - 0x14], eax
00408a95  8d45ec                   lea       eax, [ebp - 0x14]
00408a98  894328                   mov       dword ptr [ebx + 0x28], eax
00408a9b  53                       push      ebx
00408a9c  e84f9b0900               call      0x4a25f0 ; _jwe_isfm
00408aa1  83c404                   add       esp, 4
00408aa4  d9051c4b5500             fld       dword ptr [0x554b1c] ; bits=00000000, f32=0.0
00408aaa  d81d183e5500             fcomp     dword ptr [0x553e18] ; bits=00000000, f32=0.0
00408ab0  dfe0                     fnstsw    ax
00408ab2  9e                       sahf
00408ab3  0f8a6e000000             jp        0x408b27
00408ab9  766c                     jbe       0x408b27
00408abb  8b05c04a5500             mov       eax, dword ptr [0x554ac0] ; bits=00000000, f32=0.0
00408ac1  8d48ff                   lea       ecx, [eax - 1]
00408ac4  8b15bc4a5500             mov       edx, dword ptr [0x554abc] ; bits=00000000, f32=0.0
00408aca  4a                       dec       edx
00408acb  0fafd0                   imul      edx, eax
00408ace  01ca                     add       edx, ecx
00408ad0  8b8590feffff             mov       eax, dword ptr [ebp - 0x170]
00408ad6  8945fc                   mov       dword ptr [ebp - 4], eax
00408ad9  db45fc                   fild      dword ptr [ebp - 4]
00408adc  8955fc                   mov       dword ptr [ebp - 4], edx
00408adf  db45fc                   fild      dword ptr [ebp - 4]
00408ae2  d9c9                     fxch      st(1)
00408ae4  da75fc                   fidiv     dword ptr [ebp - 4]
00408ae7  8b8594feffff             mov       eax, dword ptr [ebp - 0x16c]
00408aed  8945fc                   mov       dword ptr [ebp - 4], eax
00408af0  d9c9                     fxch      st(1)
00408af2  da7dfc                   fidivr    dword ptr [ebp - 4]
00408af5  8d05c0405500             lea       eax, [0x5540c0] ; bits=09020000, f32=7.300764999132297e-43
00408afb  8b8d64feffff             mov       ecx, dword ptr [ebp - 0x19c]
00408b01  894dfc                   mov       dword ptr [ebp - 4], ecx
00408b04  8d4dfc                   lea       ecx, [ebp - 4]
00408b07  894808                   mov       dword ptr [eax + 8], ecx
00408b0a  d9c9                     fxch      st(1)
00408b0c  d95dec                   fstp      dword ptr [ebp - 0x14]
00408b0f  8d4dec                   lea       ecx, [ebp - 0x14]
00408b12  894828                   mov       dword ptr [eax + 0x28], ecx
00408b15  d95de8                   fstp      dword ptr [ebp - 0x18]
00408b18  8d4de8                   lea       ecx, [ebp - 0x18]
00408b1b  894834                   mov       dword ptr [eax + 0x34], ecx
00408b1e  50                       push      eax
00408b1f  e8cc9a0900               call      0x4a25f0 ; _jwe_isfm
00408b24  83c404                   add       esp, 4
00408b27  6a08                     push      8
00408b29  6a08                     push      8
00408b2b  6a08                     push      8
00408b2d  6a08                     push      8
00408b2f  6a08                     push      8
00408b31  6a08                     push      8
00408b33  6a32                     push      0x32
00408b35  8b5d20                   mov       ebx, dword ptr [ebp + 0x20]
00408b38  8d03                     lea       eax, [ebx]
00408b3a  50                       push      eax
00408b3b  68b04a5500               push      0x554ab0
00408b40  68a84a5500               push      0x554aa8
00408b45  68904c5500               push      0x554c90
00408b4a  68884c5500               push      0x554c88
00408b4f  68804c5500               push      0x554c80
00408b54  68784c5500               push      0x554c78
00408b59  68704c5500               push      0x554c70
00408b5e  68304b5500               push      0x554b30
00408b63  68603f5500               push      0x553f60
00408b68  68c84a5500               push      0x554ac8
00408b6d  68f44a5500               push      0x554af4
00408b72  6814296000               push      0x602914
00408b77  6898236000               push      0x602398
00408b7c  8d05601f6000             lea       eax, [0x601f60]
00408b82  898560feffff             mov       dword ptr [ebp - 0x1a0], eax
00408b88  8d4880                   lea       ecx, [eax - 0x80]
00408b8b  51                       push      ecx
00408b8c  683c216000               push      0x60213c
00408b91  68bc4a5500               push      0x554abc
00408b96  68c04a5500               push      0x554ac0
00408b9b  68a84b5500               push      0x554ba8
00408ba0  68c44a5500               push      0x554ac4
00408ba5  8b8da0feffff             mov       ecx, dword ptr [ebp - 0x160]
00408bab  8d31                     lea       esi, [ecx]
00408bad  8b8da4feffff             mov       ecx, dword ptr [ebp - 0x15c]
00408bb3  56                       push      esi
00408bb4  8d31                     lea       esi, [ecx]
00408bb6  56                       push      esi
00408bb7  e8040a0700               call      0x4795c0 ; _twdout_
00408bbc  83c474                   add       esp, 0x74
00408bbf  8d15a4e5f400             lea       edx, [0xf4e5a4]
00408bc5  8d3dd43f5500             lea       edi, [0x553fd4] ; bits=59455320, f32=1.7895340401776134e-19
00408bcb  b904000000               mov       ecx, 4
00408bd0  89d6                     mov       esi, edx
00408bd2  f3a6                     repe cmpsb byte ptr [esi], byte ptr es:[edi]
00408bd4  0f85c9000000             jne       0x408ca3
00408bda  c705e44a550001000000     mov       dword ptr [0x554ae4], 1 ; bits=00000000, f32=0.0
00408be4  6a08                     push      8
00408be6  68e04a5500               push      0x554ae0
00408beb  8d03                     lea       eax, [ebx]
00408bed  50                       push      eax
00408bee  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00408bf1  8d00                     lea       eax, [eax]
00408bf3  50                       push      eax
00408bf4  68e44a5500               push      0x554ae4
00408bf9  68304b5500               push      0x554b30
00408bfe  68603f5500               push      0x553f60
00408c03  68c84a5500               push      0x554ac8
00408c08  68f44a5500               push      0x554af4
00408c0d  6814296000               push      0x602914
00408c12  6898236000               push      0x602398
00408c17  8b8560feffff             mov       eax, dword ptr [ebp - 0x1a0]
00408c1d  8d4880                   lea       ecx, [eax - 0x80]
00408c20  51                       push      ecx
00408c21  683c216000               push      0x60213c
00408c26  68bc4a5500               push      0x554abc
00408c2b  68c04a5500               push      0x554ac0
00408c30  68c44a5500               push      0x554ac4
00408c35  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00408c3b  8d08                     lea       ecx, [eax]
00408c3d  51                       push      ecx
00408c3e  e88de20600               call      0x476ed0 ; _twodfit_
00408c43  83c444                   add       esp, 0x44
00408c46  eb5b                     jmp       0x408ca3
00408c48  ddd8                     fstp      st(0)
00408c4a  eb12                     jmp       0x408c5e
00408c4c  ddd8                     fstp      st(0)
00408c4e  eb0e                     jmp       0x408c5e
00408c50  ddd8                     fstp      st(0)
00408c52  eb0a                     jmp       0x408c5e
00408c54  ddd8                     fstp      st(0)
00408c56  eb06                     jmp       0x408c5e
00408c58  ddd8                     fstp      st(0)
00408c5a  eb02                     jmp       0x408c5e
00408c5c  ddd8                     fstp      st(0)
00408c5e  8b85a4feffff             mov       eax, dword ptr [ebp - 0x15c]
00408c64  8b18                     mov       ebx, dword ptr [eax]
00408c66  8d0594405500             lea       eax, [0x554094] ; bits=09820000, f32=4.664782457890884e-41
00408c6c  895dfc                   mov       dword ptr [ebp - 4], ebx
00408c6f  8d4dfc                   lea       ecx, [ebp - 4]
00408c72  894808                   mov       dword ptr [eax + 8], ecx
00408c75  50                       push      eax
00408c76  e805a20900               call      0x4a2e80 ; _jwe_ilst
00408c7b  83c404                   add       esp, 4
00408c7e  8d0568405500             lea       eax, [0x554068] ; bits=09820000, f32=4.664782457890884e-41
00408c84  895dfc                   mov       dword ptr [ebp - 4], ebx
00408c87  8d4dfc                   lea       ecx, [ebp - 4]
00408c8a  894808                   mov       dword ptr [eax + 8], ecx
00408c8d  50                       push      eax
00408c8e  e8eda10900               call      0x4a2e80 ; _jwe_ilst
00408c93  83c404                   add       esp, 4
00408c96  68d83f5500               push      0x553fd8
00408c9b  e8a0a70900               call      0x4a3440 ; _jwe_xstp
00408ca0  83c404                   add       esp, 4
00408ca3  b800000000               mov       eax, 0
00408ca8  5f                       pop       edi
00408ca9  5e                       pop       esi
00408caa  5b                       pop       ebx
00408cab  8be5                     mov       esp, ebp
00408cad  5d                       pop       ebp
00408cae  c3                       ret
00408caf  90                       nop
