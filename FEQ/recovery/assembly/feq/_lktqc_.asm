; _lktqc_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x3df10
0043df10  83ec4c                   sub       esp, 0x4c
0043df13  53                       push      ebx
0043df14  56                       push      esi
0043df15  57                       push      edi
0043df16  8b44245c                 mov       eax, dword ptr [esp + 0x5c]
0043df1a  8b4c2460                 mov       ecx, dword ptr [esp + 0x60]
0043df1e  8b542464                 mov       edx, dword ptr [esp + 0x64]
0043df22  89442434                 mov       dword ptr [esp + 0x34], eax
0043df26  894c2430                 mov       dword ptr [esp + 0x30], ecx
0043df2a  8954242c                 mov       dword ptr [esp + 0x2c], edx
0043df2e  8b442430                 mov       eax, dword ptr [esp + 0x30]
0043df32  d900                     fld       dword ptr [eax]
0043df34  8b742434                 mov       esi, dword ptr [esp + 0x34]
0043df38  8b16                     mov       edx, dword ptr [esi]
0043df3a  8b3c95602e0302           mov       edi, dword ptr [edx*4 + 0x2032e60]
0043df41  8d4220                   lea       eax, [edx + 0x20]
0043df44  8b0c956c2e0302           mov       ecx, dword ptr [edx*4 + 0x2032e6c]
0043df4b  8b3495682e0302           mov       esi, dword ptr [edx*4 + 0x2032e68]
0043df52  8b1cb51ccf3b05           mov       ebx, dword ptr [esi*4 + 0x53bcf1c]
0043df59  833cb56c55530000         cmp       dword ptr [esi*4 + 0x53556c], 0
0043df61  89442428                 mov       dword ptr [esp + 0x28], eax
0043df65  897c2424                 mov       dword ptr [esp + 0x24], edi
0043df69  7528                     jne       0x43df93
0043df6b  8b442434                 mov       eax, dword ptr [esp + 0x34]
0043df6f  ddd8                     fstp      st(0)
0043df71  8d08                     lea       ecx, [eax]
0043df73  51                       push      ecx
0043df74  6870555300               push      0x535570
0043df79  68c00e6c01               push      0x16c0ec0
0043df7e  e85d100000               call      0x43efe0 ; _xstype_
0043df83  83c40c                   add       esp, 0xc
0043df86  6888545300               push      0x535488
0043df8b  e8c0f40700               call      0x4bd450 ; _jwe_xstp
0043df90  83c404                   add       esp, 4
0043df93  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043df9a  dff1                     fcompi    st(1)
0043df9c  0f8a47010000             jp        0x43e0e9
0043dfa2  0f8741010000             ja        0x43e0e9
0043dfa8  8b442424                 mov       eax, dword ptr [esp + 0x24]
0043dfac  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043dfb3  dff1                     fcompi    st(1)
0043dfb5  0f8a10010000             jp        0x43e0cb
0043dfbb  0f830a010000             jae       0x43e0cb
0043dfc1  db7c2438                 fstp      xword ptr [esp + 0x38]
0043dfc5  89d0                     mov       eax, edx
0043dfc7  83c010                   add       eax, 0x10
0043dfca  89442454                 mov       dword ptr [esp + 0x54], eax
0043dfce  8d442454                 lea       eax, [esp + 0x54]
0043dfd2  50                       push      eax
0043dfd3  6a10                     push      0x10
0043dfd5  6850555300               push      0x535550
0043dfda  e85123ffff               call      0x430330 ; _get_string_from_ft_
0043dfdf  83c40c                   add       esp, 0xc
0043dfe2  8d0540555300             lea       eax, [0x535540] ; bits=00000000, f32=0.0
0043dfe8  8d3550555300             lea       esi, [0x535550] ; bits=00000000, f32=0.0
0043dfee  50                       push      eax
0043dfef  8a06                     mov       al, byte ptr [esi]
0043dff1  5f                       pop       edi
0043dff2  8807                     mov       byte ptr [edi], al
0043dff4  8a4601                   mov       al, byte ptr [esi + 1]
0043dff7  884701                   mov       byte ptr [edi + 1], al
0043dffa  8a4602                   mov       al, byte ptr [esi + 2]
0043dffd  884702                   mov       byte ptr [edi + 2], al
0043e000  8a4603                   mov       al, byte ptr [esi + 3]
0043e003  884703                   mov       byte ptr [edi + 3], al
0043e006  8a4604                   mov       al, byte ptr [esi + 4]
0043e009  884704                   mov       byte ptr [edi + 4], al
0043e00c  8a4605                   mov       al, byte ptr [esi + 5]
0043e00f  884705                   mov       byte ptr [edi + 5], al
0043e012  8a4606                   mov       al, byte ptr [esi + 6]
0043e015  884706                   mov       byte ptr [edi + 6], al
0043e018  8a4607                   mov       al, byte ptr [esi + 7]
0043e01b  884707                   mov       byte ptr [edi + 7], al
0043e01e  8a4608                   mov       al, byte ptr [esi + 8]
0043e021  884708                   mov       byte ptr [edi + 8], al
0043e024  8a4609                   mov       al, byte ptr [esi + 9]
0043e027  884709                   mov       byte ptr [edi + 9], al
0043e02a  8a460a                   mov       al, byte ptr [esi + 0xa]
0043e02d  88470a                   mov       byte ptr [edi + 0xa], al
0043e030  8a460b                   mov       al, byte ptr [esi + 0xb]
0043e033  88470b                   mov       byte ptr [edi + 0xb], al
0043e036  8a460c                   mov       al, byte ptr [esi + 0xc]
0043e039  88470c                   mov       byte ptr [edi + 0xc], al
0043e03c  8a460d                   mov       al, byte ptr [esi + 0xd]
0043e03f  88470d                   mov       byte ptr [edi + 0xd], al
0043e042  8a460e                   mov       al, byte ptr [esi + 0xe]
0043e045  88470e                   mov       byte ptr [edi + 0xe], al
0043e048  8a460f                   mov       al, byte ptr [esi + 0xf]
0043e04b  88470f                   mov       byte ptr [edi + 0xf], al
0043e04e  8b442434                 mov       eax, dword ptr [esp + 0x34]
0043e052  8b30                     mov       esi, dword ptr [eax]
0043e054  8b34b5702e0302           mov       esi, dword ptr [esi*4 + 0x2032e70]
0043e05b  8b3da00e6c01             mov       edi, dword ptr [0x16c0ea0] ; _xscom_
0043e061  8b05a40e6c01             mov       eax, dword ptr [0x16c0ea4]
0043e067  8974241c                 mov       dword ptr [esp + 0x1c], esi
0043e06b  8d35e4545300             lea       esi, [0x5354e4] ; bits=09020000, f32=7.300764999132297e-43
0043e071  897c2418                 mov       dword ptr [esp + 0x18], edi
0043e075  8b7c241c                 mov       edi, dword ptr [esp + 0x1c]
0043e079  897c2450                 mov       dword ptr [esp + 0x50], edi
0043e07d  8d7c2450                 lea       edi, [esp + 0x50]
0043e081  897e34                   mov       dword ptr [esi + 0x34], edi
0043e084  8b7c2418                 mov       edi, dword ptr [esp + 0x18]
0043e088  897c2448                 mov       dword ptr [esp + 0x48], edi
0043e08c  8944244c                 mov       dword ptr [esp + 0x4c], eax
0043e090  8d442448                 lea       eax, [esp + 0x48]
0043e094  894640                   mov       dword ptr [esi + 0x40], eax
0043e097  db6c2438                 fld       xword ptr [esp + 0x38]
0043e09b  d95c2444                 fstp      dword ptr [esp + 0x44]
0043e09f  8d442444                 lea       eax, [esp + 0x44]
0043e0a3  89464c                   mov       dword ptr [esi + 0x4c], eax
0043e0a6  56                       push      esi
0043e0a7  e814eb0700               call      0x4bcbc0 ; _jwe_isfm
0043e0ac  83c404                   add       esp, 4
0043e0af  8b442424                 mov       eax, dword ptr [esp + 0x24]
0043e0b3  89c6                     mov       esi, eax
0043e0b5  29de                     sub       esi, ebx
0043e0b7  89f1                     mov       ecx, esi
0043e0b9  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043e0c0  8b442430                 mov       eax, dword ptr [esp + 0x30]
0043e0c4  d910                     fst       dword ptr [eax]
0043e0c6  e950010000               jmp       0x43e21b
0043e0cb  8d140b                   lea       edx, [ebx + ecx]
0043e0ce  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
0043e0d5  dff1                     fcompi    st(1)
0043e0d7  0f8a3e010000             jp        0x43e21b
0043e0dd  0f8338010000             jae       0x43e21b
0043e0e3  01d9                     add       ecx, ebx
0043e0e5  01da                     add       edx, ebx
0043e0e7  ebe5                     jmp       0x43e0ce
0043e0e9  8b442428                 mov       eax, dword ptr [esp + 0x28]
0043e0ed  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043e0f4  dff1                     fcompi    st(1)
0043e0f6  0f8a0c010000             jp        0x43e208
0043e0fc  0f8606010000             jbe       0x43e208
0043e102  db7c2438                 fstp      xword ptr [esp + 0x38]
0043e106  89d0                     mov       eax, edx
0043e108  83c010                   add       eax, 0x10
0043e10b  89442454                 mov       dword ptr [esp + 0x54], eax
0043e10f  8d442454                 lea       eax, [esp + 0x54]
0043e113  50                       push      eax
0043e114  6a10                     push      0x10
0043e116  6860555300               push      0x535560
0043e11b  e81022ffff               call      0x430330 ; _get_string_from_ft_
0043e120  83c40c                   add       esp, 0xc
0043e123  8d0540555300             lea       eax, [0x535540] ; bits=00000000, f32=0.0
0043e129  8d3560555300             lea       esi, [0x535560] ; bits=00000000, f32=0.0
0043e12f  50                       push      eax
0043e130  8a06                     mov       al, byte ptr [esi]
0043e132  5f                       pop       edi
0043e133  8807                     mov       byte ptr [edi], al
0043e135  8a4601                   mov       al, byte ptr [esi + 1]
0043e138  884701                   mov       byte ptr [edi + 1], al
0043e13b  8a4602                   mov       al, byte ptr [esi + 2]
0043e13e  884702                   mov       byte ptr [edi + 2], al
0043e141  8a4603                   mov       al, byte ptr [esi + 3]
0043e144  884703                   mov       byte ptr [edi + 3], al
0043e147  8a4604                   mov       al, byte ptr [esi + 4]
0043e14a  884704                   mov       byte ptr [edi + 4], al
0043e14d  8a4605                   mov       al, byte ptr [esi + 5]
0043e150  884705                   mov       byte ptr [edi + 5], al
0043e153  8a4606                   mov       al, byte ptr [esi + 6]
0043e156  884706                   mov       byte ptr [edi + 6], al
0043e159  8a4607                   mov       al, byte ptr [esi + 7]
0043e15c  884707                   mov       byte ptr [edi + 7], al
0043e15f  8a4608                   mov       al, byte ptr [esi + 8]
0043e162  884708                   mov       byte ptr [edi + 8], al
0043e165  8a4609                   mov       al, byte ptr [esi + 9]
0043e168  884709                   mov       byte ptr [edi + 9], al
0043e16b  8a460a                   mov       al, byte ptr [esi + 0xa]
0043e16e  88470a                   mov       byte ptr [edi + 0xa], al
0043e171  8a460b                   mov       al, byte ptr [esi + 0xb]
0043e174  88470b                   mov       byte ptr [edi + 0xb], al
0043e177  8a460c                   mov       al, byte ptr [esi + 0xc]
0043e17a  88470c                   mov       byte ptr [edi + 0xc], al
0043e17d  8a460d                   mov       al, byte ptr [esi + 0xd]
0043e180  88470d                   mov       byte ptr [edi + 0xd], al
0043e183  8a460e                   mov       al, byte ptr [esi + 0xe]
0043e186  88470e                   mov       byte ptr [edi + 0xe], al
0043e189  8a460f                   mov       al, byte ptr [esi + 0xf]
0043e18c  88470f                   mov       byte ptr [edi + 0xf], al
0043e18f  8b442434                 mov       eax, dword ptr [esp + 0x34]
0043e193  8b30                     mov       esi, dword ptr [eax]
0043e195  8b34b5702e0302           mov       esi, dword ptr [esi*4 + 0x2032e70]
0043e19c  8b3da00e6c01             mov       edi, dword ptr [0x16c0ea0] ; _xscom_
0043e1a2  8b05a40e6c01             mov       eax, dword ptr [0x16c0ea4]
0043e1a8  89742410                 mov       dword ptr [esp + 0x10], esi
0043e1ac  8d3594545300             lea       esi, [0x535494] ; bits=09020000, f32=7.300764999132297e-43
0043e1b2  897c240c                 mov       dword ptr [esp + 0xc], edi
0043e1b6  8b7c2410                 mov       edi, dword ptr [esp + 0x10]
0043e1ba  897c2450                 mov       dword ptr [esp + 0x50], edi
0043e1be  8d7c2450                 lea       edi, [esp + 0x50]
0043e1c2  897e34                   mov       dword ptr [esi + 0x34], edi
0043e1c5  8b7c240c                 mov       edi, dword ptr [esp + 0xc]
0043e1c9  897c2448                 mov       dword ptr [esp + 0x48], edi
0043e1cd  8944244c                 mov       dword ptr [esp + 0x4c], eax
0043e1d1  8d442448                 lea       eax, [esp + 0x48]
0043e1d5  894640                   mov       dword ptr [esi + 0x40], eax
0043e1d8  db6c2438                 fld       xword ptr [esp + 0x38]
0043e1dc  d95c2444                 fstp      dword ptr [esp + 0x44]
0043e1e0  8d442444                 lea       eax, [esp + 0x44]
0043e1e4  89464c                   mov       dword ptr [esi + 0x4c], eax
0043e1e7  56                       push      esi
0043e1e8  e8d3e90700               call      0x4bcbc0 ; _jwe_isfm
0043e1ed  83c404                   add       esp, 4
0043e1f0  8b442428                 mov       eax, dword ptr [esp + 0x28]
0043e1f4  89c1                     mov       ecx, eax
0043e1f6  8d3403                   lea       esi, [ebx + eax]
0043e1f9  d904b5602e0302           fld       dword ptr [esi*4 + 0x2032e60]
0043e200  8b442430                 mov       eax, dword ptr [esp + 0x30]
0043e204  d910                     fst       dword ptr [eax]
0043e206  eb13                     jmp       0x43e21b
0043e208  29d9                     sub       ecx, ebx
0043e20a  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043e211  dff1                     fcompi    st(1)
0043e213  0f8a02000000             jp        0x43e21b
0043e219  77ed                     ja        0x43e208
0043e21b  8b442434                 mov       eax, dword ptr [esp + 0x34]
0043e21f  8b30                     mov       esi, dword ptr [eax]
0043e221  890cb56c2e0302           mov       dword ptr [esi*4 + 0x2032e6c], ecx
0043e228  d9048d602e0302           fld       dword ptr [ecx*4 + 0x2032e60]
0043e22f  8d140b                   lea       edx, [ebx + ecx]
0043e232  d90495602e0302           fld       dword ptr [edx*4 + 0x2032e60]
0043e239  d904957c2e0302           fld       dword ptr [edx*4 + 0x2032e7c]
0043e240  d9ee                     fldz
0043e242  dfeb                     fucompi   st(3)
0043e244  d9ca                     fxch      st(2)
0043e246  0f8a1e000000             jp        0x43e26a
0043e24c  751c                     jne       0x43e26a
0043e24e  ddd8                     fstp      st(0)
0043e250  89d8                     mov       eax, ebx
0043e252  01d0                     add       eax, edx
0043e254  d90485602e0302           fld       dword ptr [eax*4 + 0x2032e60]
0043e25b  d904857c2e0302           fld       dword ptr [eax*4 + 0x2032e7c]
0043e262  d9cb                     fxch      st(3)
0043e264  d9c9                     fxch      st(1)
0043e266  d9ca                     fxch      st(2)
0043e268  eb09                     jmp       0x43e273
0043e26a  d9048d7c2e0302           fld       dword ptr [ecx*4 + 0x2032e7c]
0043e271  d9c9                     fxch      st(1)
0043e273  dcfc                     fdiv      st(4), st(0)
0043e275  d9ed                     fldln2
0043e277  d9c0                     fld       st(0)
0043e279  d9c9                     fxch      st(1)
0043e27b  d9ce                     fxch      st(6)
0043e27d  d9f1                     fyl2x
0043e27f  d95c2450                 fstp      dword ptr [esp + 0x50]
0043e283  d9442450                 fld       dword ptr [esp + 0x50]
0043e287  d9cc                     fxch      st(4)
0043e289  d8f2                     fdiv      st(2)
0043e28b  d9c5                     fld       st(5)
0043e28d  d9c9                     fxch      st(1)
0043e28f  d9f1                     fyl2x
0043e291  d95c2450                 fstp      dword ptr [esp + 0x50]
0043e295  d9cb                     fxch      st(3)
0043e297  d84c2450                 fmul      dword ptr [esp + 0x50]
0043e29b  d9ca                     fxch      st(2)
0043e29d  def3                     fdivrp    st(3)
0043e29f  d9cb                     fxch      st(3)
0043e2a1  d9c9                     fxch      st(1)
0043e2a3  d9ca                     fxch      st(2)
0043e2a5  d9f1                     fyl2x
0043e2a7  d95c2450                 fstp      dword ptr [esp + 0x50]
0043e2ab  d8742450                 fdiv      dword ptr [esp + 0x50]
0043e2af  d91d38555300             fstp      dword ptr [0x535538] ; bits=00000000, f32=0.0
0043e2b5  d9ea                     fldl2e
0043e2b7  d80d38555300             fmul      dword ptr [0x535538] ; bits=00000000, f32=0.0
0043e2bd  d9c0                     fld       st(0)
0043e2bf  d9fc                     frndint
0043e2c1  dce9                     fsub      st(1), st(0)
0043e2c3  d9c9                     fxch      st(1)
0043e2c5  d9f0                     f2xm1
0043e2c7  d9e8                     fld1
0043e2c9  dec1                     faddp     st(1)
0043e2cb  d9fd                     fscale
0043e2cd  ddd9                     fstp      st(1)
0043e2cf  d95c2450                 fstp      dword ptr [esp + 0x50]
0043e2d3  d84c2450                 fmul      dword ptr [esp + 0x50]
0043e2d7  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
0043e2db  d918                     fstp      dword ptr [eax]
0043e2dd  b800000000               mov       eax, 0
0043e2e2  5f                       pop       edi
0043e2e3  5e                       pop       esi
0043e2e4  5b                       pop       ebx
0043e2e5  83c44c                   add       esp, 0x4c
0043e2e8  c3                       ret
0043e2e9  8da42400000000           lea       esp, [esp]
