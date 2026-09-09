; _xlkt21_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x3ae20
0043ae20  81ecec000000             sub       esp, 0xec
0043ae26  53                       push      ebx
0043ae27  56                       push      esi
0043ae28  57                       push      edi
0043ae29  8b8424fc000000           mov       eax, dword ptr [esp + 0xfc]
0043ae30  8b8c2400010000           mov       ecx, dword ptr [esp + 0x100]
0043ae37  8b942404010000           mov       edx, dword ptr [esp + 0x104]
0043ae3e  89442438                 mov       dword ptr [esp + 0x38], eax
0043ae42  894c2434                 mov       dword ptr [esp + 0x34], ecx
0043ae46  89542430                 mov       dword ptr [esp + 0x30], edx
0043ae4a  8b442434                 mov       eax, dword ptr [esp + 0x34]
0043ae4e  d900                     fld       dword ptr [eax]
0043ae50  8b742438                 mov       esi, dword ptr [esp + 0x38]
0043ae54  dbbc24d8000000           fstp      xword ptr [esp + 0xd8]
0043ae5b  8b16                     mov       edx, dword ptr [esi]
0043ae5d  8b3c95602e0302           mov       edi, dword ptr [edx*4 + 0x2032e60]
0043ae64  8d4220                   lea       eax, [edx + 0x20]
0043ae67  8b0c956c2e0302           mov       ecx, dword ptr [edx*4 + 0x2032e6c]
0043ae6e  8b3495b42e0302           mov       esi, dword ptr [edx*4 + 0x2032eb4]
0043ae75  897c242c                 mov       dword ptr [esp + 0x2c], edi
0043ae79  8b3c95682e0302           mov       edi, dword ptr [edx*4 + 0x2032e68]
0043ae80  8b1cbd1ccf3b05           mov       ebx, dword ptr [edi*4 + 0x53bcf1c]
0043ae87  833cbd5c3e530000         cmp       dword ptr [edi*4 + 0x533e5c], 0
0043ae8f  89442428                 mov       dword ptr [esp + 0x28], eax
0043ae93  89742424                 mov       dword ptr [esp + 0x24], esi
0043ae97  7526                     jne       0x43aebf
0043ae99  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043ae9d  8d08                     lea       ecx, [eax]
0043ae9f  51                       push      ecx
0043aea0  68603e5300               push      0x533e60
0043aea5  68b40e6c01               push      0x16c0eb4
0043aeaa  e831410000               call      0x43efe0 ; _xstype_
0043aeaf  83c40c                   add       esp, 0xc
0043aeb2  684c3d5300               push      0x533d4c
0043aeb7  e894250800               call      0x4bd450 ; _jwe_xstp
0043aebc  83c404                   add       esp, 4
0043aebf  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043aec6  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043aecd  dff1                     fcompi    st(1)
0043aecf  ddd8                     fstp      st(0)
0043aed1  0f8a7f010000             jp        0x43b056
0043aed7  0f8279010000             jb        0x43b056
0043aedd  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0043aee1  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043aee8  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043aeef  dff1                     fcompi    st(1)
0043aef1  ddd8                     fstp      st(0)
0043aef3  0f8a38010000             jp        0x43b031
0043aef9  0f8632010000             jbe       0x43b031
0043aeff  89d0                     mov       eax, edx
0043af01  83c010                   add       eax, 0x10
0043af04  898424f4000000           mov       dword ptr [esp + 0xf4], eax
0043af0b  8d8424f4000000           lea       eax, [esp + 0xf4]
0043af12  50                       push      eax
0043af13  6a10                     push      0x10
0043af15  68403e5300               push      0x533e40
0043af1a  e81154ffff               call      0x430330 ; _get_string_from_ft_
0043af1f  83c40c                   add       esp, 0xc
0043af22  8d05303e5300             lea       eax, [0x533e30] ; bits=00000000, f32=0.0
0043af28  8d35403e5300             lea       esi, [0x533e40] ; bits=00000000, f32=0.0
0043af2e  50                       push      eax
0043af2f  8a06                     mov       al, byte ptr [esi]
0043af31  5f                       pop       edi
0043af32  8807                     mov       byte ptr [edi], al
0043af34  8a4601                   mov       al, byte ptr [esi + 1]
0043af37  884701                   mov       byte ptr [edi + 1], al
0043af3a  8a4602                   mov       al, byte ptr [esi + 2]
0043af3d  884702                   mov       byte ptr [edi + 2], al
0043af40  8a4603                   mov       al, byte ptr [esi + 3]
0043af43  884703                   mov       byte ptr [edi + 3], al
0043af46  8a4604                   mov       al, byte ptr [esi + 4]
0043af49  884704                   mov       byte ptr [edi + 4], al
0043af4c  8a4605                   mov       al, byte ptr [esi + 5]
0043af4f  884705                   mov       byte ptr [edi + 5], al
0043af52  8a4606                   mov       al, byte ptr [esi + 6]
0043af55  884706                   mov       byte ptr [edi + 6], al
0043af58  8a4607                   mov       al, byte ptr [esi + 7]
0043af5b  884707                   mov       byte ptr [edi + 7], al
0043af5e  8a4608                   mov       al, byte ptr [esi + 8]
0043af61  884708                   mov       byte ptr [edi + 8], al
0043af64  8a4609                   mov       al, byte ptr [esi + 9]
0043af67  884709                   mov       byte ptr [edi + 9], al
0043af6a  8a460a                   mov       al, byte ptr [esi + 0xa]
0043af6d  88470a                   mov       byte ptr [edi + 0xa], al
0043af70  8a460b                   mov       al, byte ptr [esi + 0xb]
0043af73  88470b                   mov       byte ptr [edi + 0xb], al
0043af76  8a460c                   mov       al, byte ptr [esi + 0xc]
0043af79  88470c                   mov       byte ptr [edi + 0xc], al
0043af7c  8a460d                   mov       al, byte ptr [esi + 0xd]
0043af7f  88470d                   mov       byte ptr [edi + 0xd], al
0043af82  8a460e                   mov       al, byte ptr [esi + 0xe]
0043af85  88470e                   mov       byte ptr [edi + 0xe], al
0043af88  8a460f                   mov       al, byte ptr [esi + 0xf]
0043af8b  88470f                   mov       byte ptr [edi + 0xf], al
0043af8e  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043af92  8b30                     mov       esi, dword ptr [eax]
0043af94  8b34b5702e0302           mov       esi, dword ptr [esi*4 + 0x2032e70]
0043af9b  8b3da00e6c01             mov       edi, dword ptr [0x16c0ea0] ; _xscom_
0043afa1  8b05a40e6c01             mov       eax, dword ptr [0x16c0ea4]
0043afa7  8974241c                 mov       dword ptr [esp + 0x1c], esi
0043afab  8d35a83d5300             lea       esi, [0x533da8] ; bits=09020000, f32=7.300764999132297e-43
0043afb1  897c2418                 mov       dword ptr [esp + 0x18], edi
0043afb5  8b7c241c                 mov       edi, dword ptr [esp + 0x1c]
0043afb9  89bc24f0000000           mov       dword ptr [esp + 0xf0], edi
0043afc0  8dbc24f0000000           lea       edi, [esp + 0xf0]
0043afc7  897e34                   mov       dword ptr [esi + 0x34], edi
0043afca  8b7c2418                 mov       edi, dword ptr [esp + 0x18]
0043afce  89bc24e8000000           mov       dword ptr [esp + 0xe8], edi
0043afd5  898424ec000000           mov       dword ptr [esp + 0xec], eax
0043afdc  8d8424e8000000           lea       eax, [esp + 0xe8]
0043afe3  894640                   mov       dword ptr [esi + 0x40], eax
0043afe6  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043afed  d99c24e4000000           fstp      dword ptr [esp + 0xe4]
0043aff4  8d8424e4000000           lea       eax, [esp + 0xe4]
0043affb  89464c                   mov       dword ptr [esi + 0x4c], eax
0043affe  56                       push      esi
0043afff  e8bc1b0800               call      0x4bcbc0 ; _jwe_isfm
0043b004  83c404                   add       esp, 4
0043b007  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0043b00b  89c6                     mov       esi, eax
0043b00d  29de                     sub       esi, ebx
0043b00f  89f1                     mov       ecx, esi
0043b011  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043b018  dbbc24d8000000           fstp      xword ptr [esp + 0xd8]
0043b01f  8b442434                 mov       eax, dword ptr [esp + 0x34]
0043b023  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043b02a  d918                     fstp      dword ptr [eax]
0043b02c  e99f010000               jmp       0x43b1d0
0043b031  8d140b                   lea       edx, [ebx + ecx]
0043b034  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043b03b  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
0043b042  dff1                     fcompi    st(1)
0043b044  0f8a7f010000             jp        0x43b1c9
0043b04a  0f8379010000             jae       0x43b1c9
0043b050  01d9                     add       ecx, ebx
0043b052  01da                     add       edx, ebx
0043b054  ebe5                     jmp       0x43b03b
0043b056  8b442428                 mov       eax, dword ptr [esp + 0x28]
0043b05a  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043b061  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043b068  dff1                     fcompi    st(1)
0043b06a  ddd8                     fstp      st(0)
0043b06c  0f8a34010000             jp        0x43b1a6
0043b072  0f832e010000             jae       0x43b1a6
0043b078  89d0                     mov       eax, edx
0043b07a  83c010                   add       eax, 0x10
0043b07d  898424f4000000           mov       dword ptr [esp + 0xf4], eax
0043b084  8d8424f4000000           lea       eax, [esp + 0xf4]
0043b08b  50                       push      eax
0043b08c  6a10                     push      0x10
0043b08e  68503e5300               push      0x533e50
0043b093  e89852ffff               call      0x430330 ; _get_string_from_ft_
0043b098  83c40c                   add       esp, 0xc
0043b09b  8d05303e5300             lea       eax, [0x533e30] ; bits=00000000, f32=0.0
0043b0a1  8d35503e5300             lea       esi, [0x533e50] ; bits=00000000, f32=0.0
0043b0a7  50                       push      eax
0043b0a8  8a06                     mov       al, byte ptr [esi]
0043b0aa  5f                       pop       edi
0043b0ab  8807                     mov       byte ptr [edi], al
0043b0ad  8a4601                   mov       al, byte ptr [esi + 1]
0043b0b0  884701                   mov       byte ptr [edi + 1], al
0043b0b3  8a4602                   mov       al, byte ptr [esi + 2]
0043b0b6  884702                   mov       byte ptr [edi + 2], al
0043b0b9  8a4603                   mov       al, byte ptr [esi + 3]
0043b0bc  884703                   mov       byte ptr [edi + 3], al
0043b0bf  8a4604                   mov       al, byte ptr [esi + 4]
0043b0c2  884704                   mov       byte ptr [edi + 4], al
0043b0c5  8a4605                   mov       al, byte ptr [esi + 5]
0043b0c8  884705                   mov       byte ptr [edi + 5], al
0043b0cb  8a4606                   mov       al, byte ptr [esi + 6]
0043b0ce  884706                   mov       byte ptr [edi + 6], al
0043b0d1  8a4607                   mov       al, byte ptr [esi + 7]
0043b0d4  884707                   mov       byte ptr [edi + 7], al
0043b0d7  8a4608                   mov       al, byte ptr [esi + 8]
0043b0da  884708                   mov       byte ptr [edi + 8], al
0043b0dd  8a4609                   mov       al, byte ptr [esi + 9]
0043b0e0  884709                   mov       byte ptr [edi + 9], al
0043b0e3  8a460a                   mov       al, byte ptr [esi + 0xa]
0043b0e6  88470a                   mov       byte ptr [edi + 0xa], al
0043b0e9  8a460b                   mov       al, byte ptr [esi + 0xb]
0043b0ec  88470b                   mov       byte ptr [edi + 0xb], al
0043b0ef  8a460c                   mov       al, byte ptr [esi + 0xc]
0043b0f2  88470c                   mov       byte ptr [edi + 0xc], al
0043b0f5  8a460d                   mov       al, byte ptr [esi + 0xd]
0043b0f8  88470d                   mov       byte ptr [edi + 0xd], al
0043b0fb  8a460e                   mov       al, byte ptr [esi + 0xe]
0043b0fe  88470e                   mov       byte ptr [edi + 0xe], al
0043b101  8a460f                   mov       al, byte ptr [esi + 0xf]
0043b104  88470f                   mov       byte ptr [edi + 0xf], al
0043b107  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043b10b  8b30                     mov       esi, dword ptr [eax]
0043b10d  8b34b5702e0302           mov       esi, dword ptr [esi*4 + 0x2032e70]
0043b114  8b3da00e6c01             mov       edi, dword ptr [0x16c0ea0] ; _xscom_
0043b11a  8b05a40e6c01             mov       eax, dword ptr [0x16c0ea4]
0043b120  89742410                 mov       dword ptr [esp + 0x10], esi
0043b124  8d35583d5300             lea       esi, [0x533d58] ; bits=09020000, f32=7.300764999132297e-43
0043b12a  897c240c                 mov       dword ptr [esp + 0xc], edi
0043b12e  8b7c2410                 mov       edi, dword ptr [esp + 0x10]
0043b132  89bc24f0000000           mov       dword ptr [esp + 0xf0], edi
0043b139  8dbc24f0000000           lea       edi, [esp + 0xf0]
0043b140  897e34                   mov       dword ptr [esi + 0x34], edi
0043b143  8b7c240c                 mov       edi, dword ptr [esp + 0xc]
0043b147  89bc24e8000000           mov       dword ptr [esp + 0xe8], edi
0043b14e  898424ec000000           mov       dword ptr [esp + 0xec], eax
0043b155  8d8424e8000000           lea       eax, [esp + 0xe8]
0043b15c  894640                   mov       dword ptr [esi + 0x40], eax
0043b15f  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043b166  d99c24e4000000           fstp      dword ptr [esp + 0xe4]
0043b16d  8d8424e4000000           lea       eax, [esp + 0xe4]
0043b174  89464c                   mov       dword ptr [esi + 0x4c], eax
0043b177  56                       push      esi
0043b178  e8431a0800               call      0x4bcbc0 ; _jwe_isfm
0043b17d  83c404                   add       esp, 4
0043b180  8b442428                 mov       eax, dword ptr [esp + 0x28]
0043b184  89c1                     mov       ecx, eax
0043b186  8d3403                   lea       esi, [ebx + eax]
0043b189  d904b5602e0302           fld       dword ptr [esi*4 + 0x2032e60]
0043b190  dbbc24d8000000           fstp      xword ptr [esp + 0xd8]
0043b197  8b442434                 mov       eax, dword ptr [esp + 0x34]
0043b19b  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043b1a2  d918                     fstp      dword ptr [eax]
0043b1a4  eb2a                     jmp       0x43b1d0
0043b1a6  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043b1ad  29d9                     sub       ecx, ebx
0043b1af  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043b1b6  dff1                     fcompi    st(1)
0043b1b8  0f8a02000000             jp        0x43b1c0
0043b1be  77ed                     ja        0x43b1ad
0043b1c0  dbbc24d8000000           fstp      xword ptr [esp + 0xd8]
0043b1c7  eb07                     jmp       0x43b1d0
0043b1c9  dbbc24d8000000           fstp      xword ptr [esp + 0xd8]
0043b1d0  8b442438                 mov       eax, dword ptr [esp + 0x38]
0043b1d4  8b30                     mov       esi, dword ptr [eax]
0043b1d6  890cb56c2e0302           mov       dword ptr [esi*4 + 0x2032e6c], ecx
0043b1dd  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043b1e4  d9048d642e0302           fld       dword ptr [ecx*4 + 0x2032e64]
0043b1eb  dbbc2484000000           fstp      xword ptr [esp + 0x84]
0043b1f2  d9048d682e0302           fld       dword ptr [ecx*4 + 0x2032e68]
0043b1f9  dbbc2490000000           fstp      xword ptr [esp + 0x90]
0043b200  d9048d6c2e0302           fld       dword ptr [ecx*4 + 0x2032e6c]
0043b207  dbbc24cc000000           fstp      xword ptr [esp + 0xcc]
0043b20e  d9048d702e0302           fld       dword ptr [ecx*4 + 0x2032e70]
0043b215  db7c246c                 fstp      xword ptr [esp + 0x6c]
0043b219  d9048d742e0302           fld       dword ptr [ecx*4 + 0x2032e74]
0043b220  89d8                     mov       eax, ebx
0043b222  01c8                     add       eax, ecx
0043b224  89c2                     mov       edx, eax
0043b226  d90495702e0302           fld       dword ptr [edx*4 + 0x2032e70]
0043b22d  dbbc24c0000000           fstp      xword ptr [esp + 0xc0]
0043b234  d904956c2e0302           fld       dword ptr [edx*4 + 0x2032e6c]
0043b23b  dbbc24b4000000           fstp      xword ptr [esp + 0xb4]
0043b242  d9c1                     fld       st(1)
0043b244  d82c95602e0302           fsubr     dword ptr [edx*4 + 0x2032e60]
0043b24b  db7c2460                 fstp      xword ptr [esp + 0x60]
0043b24f  dbac24d8000000           fld       xword ptr [esp + 0xd8]
0043b256  dee2                     fsubrp    st(2)
0043b258  d9c9                     fxch      st(1)
0043b25a  db7c2478                 fstp      xword ptr [esp + 0x78]
0043b25e  8d1dc83c5300             lea       ebx, [0x533cc8] ; bits=00020000, f32=7.174648137343064e-43
0043b264  db6c2478                 fld       xword ptr [esp + 0x78]
0043b268  d84b88                   fmul      dword ptr [ebx - 0x78]
0043b26b  d9e8                     fld1
0043b26d  db6c2460                 fld       xword ptr [esp + 0x60]
0043b271  d83d543c5300             fdivr     dword ptr [0x533c54] ; bits=0000803f, f32=1.0
0043b277  dbac2484000000           fld       xword ptr [esp + 0x84]
0043b27e  d82c95642e0302           fsubr     dword ptr [edx*4 + 0x2032e64]
0043b285  d8c9                     fmul      st(1)
0043b287  8b84240c010000           mov       eax, dword ptr [esp + 0x10c]
0043b28e  d910                     fst       dword ptr [eax]
0043b290  db6c2478                 fld       xword ptr [esp + 0x78]
0043b294  dec9                     fmulp     st(1)
0043b296  dbac2484000000           fld       xword ptr [esp + 0x84]
0043b29d  dec1                     faddp     st(1)
0043b29f  8b842408010000           mov       eax, dword ptr [esp + 0x108]
0043b2a6  d910                     fst       dword ptr [eax]
0043b2a8  dbac2484000000           fld       xword ptr [esp + 0x84]
0043b2af  dec1                     faddp     st(1)
0043b2b1  d8cb                     fmul      st(3)
0043b2b3  dbac2490000000           fld       xword ptr [esp + 0x90]
0043b2ba  8b742430                 mov       esi, dword ptr [esp + 0x30]
0043b2be  dec1                     faddp     st(1)
0043b2c0  d916                     fst       dword ptr [esi]
0043b2c2  dbac2490000000           fld       xword ptr [esp + 0x90]
0043b2c9  dec1                     faddp     st(1)
0043b2cb  dbac2484000000           fld       xword ptr [esp + 0x84]
0043b2d2  d828                     fsubr     dword ptr [eax]
0043b2d4  db6c2478                 fld       xword ptr [esp + 0x78]
0043b2d8  dec9                     fmulp     st(1)
0043b2da  d84b98                   fmul      dword ptr [ebx - 0x68]
0043b2dd  dee9                     fsubp     st(1)
0043b2df  decb                     fmulp     st(3)
0043b2e1  d9ca                     fxch      st(2)
0043b2e3  dec3                     faddp     st(3)
0043b2e5  8b842410010000           mov       eax, dword ptr [esp + 0x110]
0043b2ec  d9ca                     fxch      st(2)
0043b2ee  d918                     fstp      dword ptr [eax]
0043b2f0  db6c2478                 fld       xword ptr [esp + 0x78]
0043b2f4  db6c2460                 fld       xword ptr [esp + 0x60]
0043b2f8  dbbc24a8000000           fstp      xword ptr [esp + 0xa8]
0043b2ff  d9ca                     fxch      st(2)
0043b301  dbbc249c000000           fstp      xword ptr [esp + 0x9c]
0043b308  db6c246c                 fld       xword ptr [esp + 0x6c]
0043b30c  d9ca                     fxch      st(2)
0043b30e  8b442424                 mov       eax, dword ptr [esp + 0x24]
0043b312  85c0                     test      eax, eax
0043b314  7557                     jne       0x43b36d
0043b316  dbac24c0000000           fld       xword ptr [esp + 0xc0]
0043b31d  d8e3                     fsub      st(3)
0043b31f  d8ca                     fmul      st(2)
0043b321  8b842420010000           mov       eax, dword ptr [esp + 0x120]
0043b328  d910                     fst       dword ptr [eax]
0043b32a  d8c9                     fmul      st(1)
0043b32c  dec3                     faddp     st(3)
0043b32e  8b84241c010000           mov       eax, dword ptr [esp + 0x11c]
0043b335  d9ca                     fxch      st(2)
0043b337  d918                     fstp      dword ptr [eax]
0043b339  dbac24b4000000           fld       xword ptr [esp + 0xb4]
0043b340  dbac24cc000000           fld       xword ptr [esp + 0xcc]
0043b347  dee9                     fsubp     st(1)
0043b349  dec9                     fmulp     st(1)
0043b34b  8b842418010000           mov       eax, dword ptr [esp + 0x118]
0043b352  d910                     fst       dword ptr [eax]
0043b354  dec9                     fmulp     st(1)
0043b356  dbac24cc000000           fld       xword ptr [esp + 0xcc]
0043b35d  dec1                     faddp     st(1)
0043b35f  8b842414010000           mov       eax, dword ptr [esp + 0x114]
0043b366  d918                     fstp      dword ptr [eax]
0043b368  e987010000               jmp       0x43b4f4
0043b36d  d9ca                     fxch      st(2)
0043b36f  db7c2448                 fstp      xword ptr [esp + 0x48]
0043b373  dcc9                     fmul      st(1), st(0)
0043b375  dbac249c000000           fld       xword ptr [esp + 0x9c]
0043b37c  d8e2                     fsub      st(2)
0043b37e  d9c0                     fld       st(0)
0043b380  d8cb                     fmul      st(3)
0043b382  dbac24a8000000           fld       xword ptr [esp + 0xa8]
0043b389  dec9                     fmulp     st(1)
0043b38b  d9c3                     fld       st(3)
0043b38d  d8c9                     fmul      st(1)
0043b38f  d9e0                     fchs
0043b391  db7c2478                 fstp      xword ptr [esp + 0x78]
0043b395  d8c9                     fmul      st(1)
0043b397  dbbc2484000000           fstp      xword ptr [esp + 0x84]
0043b39e  d9c2                     fld       st(2)
0043b3a0  d8c0                     fadd      st(0)
0043b3a2  dbac249c000000           fld       xword ptr [esp + 0x9c]
0043b3a9  dec1                     faddp     st(1)
0043b3ab  d9c0                     fld       st(0)
0043b3ad  d86b94                   fsubr     dword ptr [ebx - 0x6c]
0043b3b0  d8cc                     fmul      st(4)
0043b3b2  d8cc                     fmul      st(4)
0043b3b4  db7c243c                 fstp      xword ptr [esp + 0x3c]
0043b3b8  d9c1                     fld       st(1)
0043b3ba  d8c8                     fmul      st(0)
0043b3bc  dec9                     fmulp     st(1)
0043b3be  dbbc2490000000           fstp      xword ptr [esp + 0x90]
0043b3c5  d9c2                     fld       st(2)
0043b3c7  d84b9c                   fmul      dword ptr [ebx - 0x64]
0043b3ca  dbac249c000000           fld       xword ptr [esp + 0x9c]
0043b3d1  dee1                     fsubrp    st(1)
0043b3d3  dbac249c000000           fld       xword ptr [esp + 0x9c]
0043b3da  d8c1                     fadd      st(1)
0043b3dc  d8cc                     fmul      st(4)
0043b3de  d9e0                     fchs
0043b3e0  db7c2460                 fstp      xword ptr [esp + 0x60]
0043b3e4  d8c9                     fmul      st(1)
0043b3e6  db7c246c                 fstp      xword ptr [esp + 0x6c]
0043b3ea  d84ba0                   fmul      dword ptr [ebx - 0x60]
0043b3ed  deca                     fmulp     st(2)
0043b3ef  dec9                     fmulp     st(1)
0043b3f1  8b442424                 mov       eax, dword ptr [esp + 0x24]
0043b3f5  db7c2454                 fstp      xword ptr [esp + 0x54]
0043b3f9  8d3408                   lea       esi, [eax + ecx]
0043b3fc  89d7                     mov       edi, edx
0043b3fe  01c7                     add       edi, eax
0043b400  d904b5602e0302           fld       dword ptr [esi*4 + 0x2032e60]
0043b407  d904bd602e0302           fld       dword ptr [edi*4 + 0x2032e60]
0043b40e  d904b5642e0302           fld       dword ptr [esi*4 + 0x2032e64]
0043b415  d904bd642e0302           fld       dword ptr [edi*4 + 0x2032e64]
0043b41c  dbac2484000000           fld       xword ptr [esp + 0x84]
0043b423  d80cb5642e0302           fmul      dword ptr [esi*4 + 0x2032e64]
0043b42a  db6c2478                 fld       xword ptr [esp + 0x78]
0043b42e  d80cbd642e0302           fmul      dword ptr [edi*4 + 0x2032e64]
0043b435  dec1                     faddp     st(1)
0043b437  dbac2490000000           fld       xword ptr [esp + 0x90]
0043b43e  db6c2448                 fld       xword ptr [esp + 0x48]
0043b442  dec9                     fmulp     st(1)
0043b444  dec1                     faddp     st(1)
0043b446  dbac24c0000000           fld       xword ptr [esp + 0xc0]
0043b44d  db6c243c                 fld       xword ptr [esp + 0x3c]
0043b451  dec9                     fmulp     st(1)
0043b453  dec1                     faddp     st(1)
0043b455  8b84241c010000           mov       eax, dword ptr [esp + 0x11c]
0043b45c  d918                     fstp      dword ptr [eax]
0043b45e  db6c246c                 fld       xword ptr [esp + 0x6c]
0043b462  deca                     fmulp     st(2)
0043b464  db6c2460                 fld       xword ptr [esp + 0x60]
0043b468  dec9                     fmulp     st(1)
0043b46a  dec1                     faddp     st(1)
0043b46c  dbac24c0000000           fld       xword ptr [esp + 0xc0]
0043b473  db6c2448                 fld       xword ptr [esp + 0x48]
0043b477  dee9                     fsubp     st(1)
0043b479  db6c2454                 fld       xword ptr [esp + 0x54]
0043b47d  dec9                     fmulp     st(1)
0043b47f  dec1                     faddp     st(1)
0043b481  8b842420010000           mov       eax, dword ptr [esp + 0x120]
0043b488  d918                     fstp      dword ptr [eax]
0043b48a  dbac2484000000           fld       xword ptr [esp + 0x84]
0043b491  d8ca                     fmul      st(2)
0043b493  db6c2478                 fld       xword ptr [esp + 0x78]
0043b497  d8ca                     fmul      st(2)
0043b499  dec1                     faddp     st(1)
0043b49b  dbac24cc000000           fld       xword ptr [esp + 0xcc]
0043b4a2  dbac2490000000           fld       xword ptr [esp + 0x90]
0043b4a9  dec9                     fmulp     st(1)
0043b4ab  dec1                     faddp     st(1)
0043b4ad  dbac24b4000000           fld       xword ptr [esp + 0xb4]
0043b4b4  db6c243c                 fld       xword ptr [esp + 0x3c]
0043b4b8  dec9                     fmulp     st(1)
0043b4ba  dec1                     faddp     st(1)
0043b4bc  8b842414010000           mov       eax, dword ptr [esp + 0x114]
0043b4c3  d918                     fstp      dword ptr [eax]
0043b4c5  db6c246c                 fld       xword ptr [esp + 0x6c]
0043b4c9  deca                     fmulp     st(2)
0043b4cb  db6c2460                 fld       xword ptr [esp + 0x60]
0043b4cf  dec9                     fmulp     st(1)
0043b4d1  dec1                     faddp     st(1)
0043b4d3  dbac24b4000000           fld       xword ptr [esp + 0xb4]
0043b4da  dbac24cc000000           fld       xword ptr [esp + 0xcc]
0043b4e1  dee9                     fsubp     st(1)
0043b4e3  db6c2454                 fld       xword ptr [esp + 0x54]
0043b4e7  dec9                     fmulp     st(1)
0043b4e9  dec1                     faddp     st(1)
0043b4eb  8b842418010000           mov       eax, dword ptr [esp + 0x118]
0043b4f2  d918                     fstp      dword ptr [eax]
0043b4f4  8b842414010000           mov       eax, dword ptr [esp + 0x114]
0043b4fb  d900                     fld       dword ptr [eax]
0043b4fd  d9c0                     fld       st(0)
0043b4ff  d800                     fadd      dword ptr [eax]
0043b501  8b8c2418010000           mov       ecx, dword ptr [esp + 0x118]
0043b508  d809                     fmul      dword ptr [ecx]
0043b50a  d919                     fstp      dword ptr [ecx]
0043b50c  d8c8                     fmul      st(0)
0043b50e  d918                     fstp      dword ptr [eax]
0043b510  b800000000               mov       eax, 0
0043b515  5f                       pop       edi
0043b516  5e                       pop       esi
0043b517  5b                       pop       ebx
0043b518  81c4ec000000             add       esp, 0xec
0043b51e  c3                       ret
0043b51f  90                       nop
