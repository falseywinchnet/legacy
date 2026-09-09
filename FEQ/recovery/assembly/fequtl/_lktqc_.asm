; _lktqc_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x4b610
0044b610  55                       push      ebp
0044b611  8bec                     mov       ebp, esp
0044b613  b84c000000               mov       eax, 0x4c
0044b618  e8e3d90900               call      0x4e9000 ; __alloca_probe
0044b61d  53                       push      ebx
0044b61e  56                       push      esi
0044b61f  57                       push      edi
0044b620  8b4508                   mov       eax, dword ptr [ebp + 8]
0044b623  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
0044b626  8b5510                   mov       edx, dword ptr [ebp + 0x10]
0044b629  8945dc                   mov       dword ptr [ebp - 0x24], eax
0044b62c  894dd8                   mov       dword ptr [ebp - 0x28], ecx
0044b62f  8955d4                   mov       dword ptr [ebp - 0x2c], edx
0044b632  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
0044b635  d900                     fld       dword ptr [eax]
0044b637  8b75dc                   mov       esi, dword ptr [ebp - 0x24]
0044b63a  8b16                     mov       edx, dword ptr [esi]
0044b63c  8b3c95c0e5f400           mov       edi, dword ptr [edx*4 + 0xf4e5c0]
0044b643  8d4220                   lea       eax, [edx + 0x20]
0044b646  8b0c95cce5f400           mov       ecx, dword ptr [edx*4 + 0xf4e5cc]
0044b64d  8b3495c8e5f400           mov       esi, dword ptr [edx*4 + 0xf4e5c8]
0044b654  8b1cb5445b5700           mov       ebx, dword ptr [esi*4 + 0x575b44]
0044b65b  833cb59433580000         cmp       dword ptr [esi*4 + 0x583394], 0
0044b663  8945d0                   mov       dword ptr [ebp - 0x30], eax
0044b666  897dcc                   mov       dword ptr [ebp - 0x34], edi
0044b669  7527                     jne       0x44b692
0044b66b  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
0044b66e  ddd8                     fstp      st(0)
0044b670  8d08                     lea       ecx, [eax]
0044b672  51                       push      ecx
0044b673  6898335800               push      0x583398
0044b678  686095b700               push      0xb79560
0044b67d  e8fe0e0000               call      0x44c580 ; _xstype_
0044b682  83c40c                   add       esp, 0xc
0044b685  68b0325800               push      0x5832b0
0044b68a  e8b17d0500               call      0x4a3440 ; _jwe_xstp
0044b68f  83c404                   add       esp, 4
0044b692  d8148dc0e5f400           fcom      dword ptr [ecx*4 + 0xf4e5c0]
0044b699  dfe0                     fnstsw    ax
0044b69b  9e                       sahf
0044b69c  0f8a36010000             jp        0x44b7d8
0044b6a2  0f8230010000             jb        0x44b7d8
0044b6a8  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
0044b6ab  d81485c0e5f400           fcom      dword ptr [eax*4 + 0xf4e5c0]
0044b6b2  dfe0                     fnstsw    ax
0044b6b4  9e                       sahf
0044b6b5  0f8afe000000             jp        0x44b7b9
0044b6bb  0f86f8000000             jbe       0x44b7b9
0044b6c1  db7de0                   fstp      xword ptr [ebp - 0x20]
0044b6c4  89d0                     mov       eax, edx
0044b6c6  83c010                   add       eax, 0x10
0044b6c9  8945fc                   mov       dword ptr [ebp - 4], eax
0044b6cc  8d45fc                   lea       eax, [ebp - 4]
0044b6cf  50                       push      eax
0044b6d0  6a10                     push      0x10
0044b6d2  6878335800               push      0x583378
0044b6d7  e87434ffff               call      0x43eb50 ; _get_string_from_ft_
0044b6dc  83c40c                   add       esp, 0xc
0044b6df  8d0568335800             lea       eax, [0x583368] ; bits=00000000, f32=0.0
0044b6e5  8d3578335800             lea       esi, [0x583378] ; bits=00000000, f32=0.0
0044b6eb  50                       push      eax
0044b6ec  8a06                     mov       al, byte ptr [esi]
0044b6ee  5f                       pop       edi
0044b6ef  8807                     mov       byte ptr [edi], al
0044b6f1  8a4601                   mov       al, byte ptr [esi + 1]
0044b6f4  884701                   mov       byte ptr [edi + 1], al
0044b6f7  8a4602                   mov       al, byte ptr [esi + 2]
0044b6fa  884702                   mov       byte ptr [edi + 2], al
0044b6fd  8a4603                   mov       al, byte ptr [esi + 3]
0044b700  884703                   mov       byte ptr [edi + 3], al
0044b703  8a4604                   mov       al, byte ptr [esi + 4]
0044b706  884704                   mov       byte ptr [edi + 4], al
0044b709  8a4605                   mov       al, byte ptr [esi + 5]
0044b70c  884705                   mov       byte ptr [edi + 5], al
0044b70f  8a4606                   mov       al, byte ptr [esi + 6]
0044b712  884706                   mov       byte ptr [edi + 6], al
0044b715  8a4607                   mov       al, byte ptr [esi + 7]
0044b718  884707                   mov       byte ptr [edi + 7], al
0044b71b  8a4608                   mov       al, byte ptr [esi + 8]
0044b71e  884708                   mov       byte ptr [edi + 8], al
0044b721  8a4609                   mov       al, byte ptr [esi + 9]
0044b724  884709                   mov       byte ptr [edi + 9], al
0044b727  8a460a                   mov       al, byte ptr [esi + 0xa]
0044b72a  88470a                   mov       byte ptr [edi + 0xa], al
0044b72d  8a460b                   mov       al, byte ptr [esi + 0xb]
0044b730  88470b                   mov       byte ptr [edi + 0xb], al
0044b733  8a460c                   mov       al, byte ptr [esi + 0xc]
0044b736  88470c                   mov       byte ptr [edi + 0xc], al
0044b739  8a460d                   mov       al, byte ptr [esi + 0xd]
0044b73c  88470d                   mov       byte ptr [edi + 0xd], al
0044b73f  8a460e                   mov       al, byte ptr [esi + 0xe]
0044b742  88470e                   mov       byte ptr [edi + 0xe], al
0044b745  8a460f                   mov       al, byte ptr [esi + 0xf]
0044b748  88470f                   mov       byte ptr [edi + 0xf], al
0044b74b  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
0044b74e  8b30                     mov       esi, dword ptr [eax]
0044b750  8b34b5d0e5f400           mov       esi, dword ptr [esi*4 + 0xf4e5d0]
0044b757  8b3d4095b700             mov       edi, dword ptr [0xb79540] ; _xscom_
0044b75d  8b054495b700             mov       eax, dword ptr [0xb79544]
0044b763  8975c4                   mov       dword ptr [ebp - 0x3c], esi
0044b766  8d350c335800             lea       esi, [0x58330c] ; bits=09020000, f32=7.300764999132297e-43
0044b76c  897dc0                   mov       dword ptr [ebp - 0x40], edi
0044b76f  8b7dc4                   mov       edi, dword ptr [ebp - 0x3c]
0044b772  897df8                   mov       dword ptr [ebp - 8], edi
0044b775  8d7df8                   lea       edi, [ebp - 8]
0044b778  897e34                   mov       dword ptr [esi + 0x34], edi
0044b77b  8b7dc0                   mov       edi, dword ptr [ebp - 0x40]
0044b77e  897df0                   mov       dword ptr [ebp - 0x10], edi
0044b781  8945f4                   mov       dword ptr [ebp - 0xc], eax
0044b784  8d45f0                   lea       eax, [ebp - 0x10]
0044b787  894640                   mov       dword ptr [esi + 0x40], eax
0044b78a  db6de0                   fld       xword ptr [ebp - 0x20]
0044b78d  d95dec                   fstp      dword ptr [ebp - 0x14]
0044b790  8d45ec                   lea       eax, [ebp - 0x14]
0044b793  89464c                   mov       dword ptr [esi + 0x4c], eax
0044b796  56                       push      esi
0044b797  e8546e0500               call      0x4a25f0 ; _jwe_isfm
0044b79c  83c404                   add       esp, 4
0044b79f  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
0044b7a2  89c6                     mov       esi, eax
0044b7a4  29de                     sub       esi, ebx
0044b7a6  89f1                     mov       ecx, esi
0044b7a8  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
0044b7af  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
0044b7b2  d910                     fst       dword ptr [eax]
0044b7b4  e940010000               jmp       0x44b8f9
0044b7b9  8d140b                   lea       edx, [ebx + ecx]
0044b7bc  d81495c0e5f400           fcom      dword ptr [edx*4 + 0xf4e5c0]
0044b7c3  dfe0                     fnstsw    ax
0044b7c5  9e                       sahf
0044b7c6  0f8a2d010000             jp        0x44b8f9
0044b7cc  0f8627010000             jbe       0x44b8f9
0044b7d2  01d9                     add       ecx, ebx
0044b7d4  01da                     add       edx, ebx
0044b7d6  ebe4                     jmp       0x44b7bc
0044b7d8  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
0044b7db  d81485c0e5f400           fcom      dword ptr [eax*4 + 0xf4e5c0]
0044b7e2  dfe0                     fnstsw    ax
0044b7e4  9e                       sahf
0044b7e5  0f8afa000000             jp        0x44b8e5
0044b7eb  0f83f4000000             jae       0x44b8e5
0044b7f1  db7de0                   fstp      xword ptr [ebp - 0x20]
0044b7f4  89d0                     mov       eax, edx
0044b7f6  83c010                   add       eax, 0x10
0044b7f9  8945fc                   mov       dword ptr [ebp - 4], eax
0044b7fc  8d45fc                   lea       eax, [ebp - 4]
0044b7ff  50                       push      eax
0044b800  6a10                     push      0x10
0044b802  6888335800               push      0x583388
0044b807  e84433ffff               call      0x43eb50 ; _get_string_from_ft_
0044b80c  83c40c                   add       esp, 0xc
0044b80f  8d0568335800             lea       eax, [0x583368] ; bits=00000000, f32=0.0
0044b815  8d3588335800             lea       esi, [0x583388] ; bits=00000000, f32=0.0
0044b81b  50                       push      eax
0044b81c  8a06                     mov       al, byte ptr [esi]
0044b81e  5f                       pop       edi
0044b81f  8807                     mov       byte ptr [edi], al
0044b821  8a4601                   mov       al, byte ptr [esi + 1]
0044b824  884701                   mov       byte ptr [edi + 1], al
0044b827  8a4602                   mov       al, byte ptr [esi + 2]
0044b82a  884702                   mov       byte ptr [edi + 2], al
0044b82d  8a4603                   mov       al, byte ptr [esi + 3]
0044b830  884703                   mov       byte ptr [edi + 3], al
0044b833  8a4604                   mov       al, byte ptr [esi + 4]
0044b836  884704                   mov       byte ptr [edi + 4], al
0044b839  8a4605                   mov       al, byte ptr [esi + 5]
0044b83c  884705                   mov       byte ptr [edi + 5], al
0044b83f  8a4606                   mov       al, byte ptr [esi + 6]
0044b842  884706                   mov       byte ptr [edi + 6], al
0044b845  8a4607                   mov       al, byte ptr [esi + 7]
0044b848  884707                   mov       byte ptr [edi + 7], al
0044b84b  8a4608                   mov       al, byte ptr [esi + 8]
0044b84e  884708                   mov       byte ptr [edi + 8], al
0044b851  8a4609                   mov       al, byte ptr [esi + 9]
0044b854  884709                   mov       byte ptr [edi + 9], al
0044b857  8a460a                   mov       al, byte ptr [esi + 0xa]
0044b85a  88470a                   mov       byte ptr [edi + 0xa], al
0044b85d  8a460b                   mov       al, byte ptr [esi + 0xb]
0044b860  88470b                   mov       byte ptr [edi + 0xb], al
0044b863  8a460c                   mov       al, byte ptr [esi + 0xc]
0044b866  88470c                   mov       byte ptr [edi + 0xc], al
0044b869  8a460d                   mov       al, byte ptr [esi + 0xd]
0044b86c  88470d                   mov       byte ptr [edi + 0xd], al
0044b86f  8a460e                   mov       al, byte ptr [esi + 0xe]
0044b872  88470e                   mov       byte ptr [edi + 0xe], al
0044b875  8a460f                   mov       al, byte ptr [esi + 0xf]
0044b878  88470f                   mov       byte ptr [edi + 0xf], al
0044b87b  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
0044b87e  8b30                     mov       esi, dword ptr [eax]
0044b880  8b34b5d0e5f400           mov       esi, dword ptr [esi*4 + 0xf4e5d0]
0044b887  8b3d4095b700             mov       edi, dword ptr [0xb79540] ; _xscom_
0044b88d  8b054495b700             mov       eax, dword ptr [0xb79544]
0044b893  8975b8                   mov       dword ptr [ebp - 0x48], esi
0044b896  8d35bc325800             lea       esi, [0x5832bc] ; bits=09020000, f32=7.300764999132297e-43
0044b89c  897db4                   mov       dword ptr [ebp - 0x4c], edi
0044b89f  8b7db8                   mov       edi, dword ptr [ebp - 0x48]
0044b8a2  897df8                   mov       dword ptr [ebp - 8], edi
0044b8a5  8d7df8                   lea       edi, [ebp - 8]
0044b8a8  897e34                   mov       dword ptr [esi + 0x34], edi
0044b8ab  8b7db4                   mov       edi, dword ptr [ebp - 0x4c]
0044b8ae  897df0                   mov       dword ptr [ebp - 0x10], edi
0044b8b1  8945f4                   mov       dword ptr [ebp - 0xc], eax
0044b8b4  8d45f0                   lea       eax, [ebp - 0x10]
0044b8b7  894640                   mov       dword ptr [esi + 0x40], eax
0044b8ba  db6de0                   fld       xword ptr [ebp - 0x20]
0044b8bd  d95dec                   fstp      dword ptr [ebp - 0x14]
0044b8c0  8d45ec                   lea       eax, [ebp - 0x14]
0044b8c3  89464c                   mov       dword ptr [esi + 0x4c], eax
0044b8c6  56                       push      esi
0044b8c7  e8246d0500               call      0x4a25f0 ; _jwe_isfm
0044b8cc  83c404                   add       esp, 4
0044b8cf  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
0044b8d2  89c1                     mov       ecx, eax
0044b8d4  8d3403                   lea       esi, [ebx + eax]
0044b8d7  d904b5c0e5f400           fld       dword ptr [esi*4 + 0xf4e5c0]
0044b8de  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
0044b8e1  d910                     fst       dword ptr [eax]
0044b8e3  eb14                     jmp       0x44b8f9
0044b8e5  29d9                     sub       ecx, ebx
0044b8e7  d8148dc0e5f400           fcom      dword ptr [ecx*4 + 0xf4e5c0]
0044b8ee  dfe0                     fnstsw    ax
0044b8f0  9e                       sahf
0044b8f1  0f8a02000000             jp        0x44b8f9
0044b8f7  72ec                     jb        0x44b8e5
0044b8f9  8b45dc                   mov       eax, dword ptr [ebp - 0x24]
0044b8fc  8b30                     mov       esi, dword ptr [eax]
0044b8fe  890cb5cce5f400           mov       dword ptr [esi*4 + 0xf4e5cc], ecx
0044b905  d9048dc0e5f400           fld       dword ptr [ecx*4 + 0xf4e5c0]
0044b90c  8d140b                   lea       edx, [ebx + ecx]
0044b90f  d90495c0e5f400           fld       dword ptr [edx*4 + 0xf4e5c0]
0044b916  d90495dce5f400           fld       dword ptr [edx*4 + 0xf4e5dc]
0044b91d  d9ee                     fldz
0044b91f  d9cb                     fxch      st(3)
0044b921  dde3                     fucom     st(3)
0044b923  dddb                     fstp      st(3)
0044b925  d9ca                     fxch      st(2)
0044b927  dfe0                     fnstsw    ax
0044b929  9e                       sahf
0044b92a  0f8a1e000000             jp        0x44b94e
0044b930  751c                     jne       0x44b94e
0044b932  ddd8                     fstp      st(0)
0044b934  89d8                     mov       eax, ebx
0044b936  01d0                     add       eax, edx
0044b938  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
0044b93f  d90485dce5f400           fld       dword ptr [eax*4 + 0xf4e5dc]
0044b946  d9cb                     fxch      st(3)
0044b948  d9c9                     fxch      st(1)
0044b94a  d9ca                     fxch      st(2)
0044b94c  eb09                     jmp       0x44b957
0044b94e  d9048ddce5f400           fld       dword ptr [ecx*4 + 0xf4e5dc]
0044b955  d9c9                     fxch      st(1)
0044b957  dcfc                     fdiv      st(4), st(0)
0044b959  d9ed                     fldln2
0044b95b  d9c0                     fld       st(0)
0044b95d  d9c9                     fxch      st(1)
0044b95f  d9ce                     fxch      st(6)
0044b961  d9f1                     fyl2x
0044b963  d95df8                   fstp      dword ptr [ebp - 8]
0044b966  d945f8                   fld       dword ptr [ebp - 8]
0044b969  d9cc                     fxch      st(4)
0044b96b  d8f2                     fdiv      st(2)
0044b96d  d9c5                     fld       st(5)
0044b96f  d9c9                     fxch      st(1)
0044b971  d9f1                     fyl2x
0044b973  d95df8                   fstp      dword ptr [ebp - 8]
0044b976  d9cb                     fxch      st(3)
0044b978  d84df8                   fmul      dword ptr [ebp - 8]
0044b97b  d9ca                     fxch      st(2)
0044b97d  def3                     fdivrp    st(3)
0044b97f  d9cb                     fxch      st(3)
0044b981  d9c9                     fxch      st(1)
0044b983  d9ca                     fxch      st(2)
0044b985  d9f1                     fyl2x
0044b987  d95df8                   fstp      dword ptr [ebp - 8]
0044b98a  d875f8                   fdiv      dword ptr [ebp - 8]
0044b98d  d91d60335800             fstp      dword ptr [0x583360] ; bits=00000000, f32=0.0
0044b993  d9ea                     fldl2e
0044b995  d80d60335800             fmul      dword ptr [0x583360] ; bits=00000000, f32=0.0
0044b99b  d9c0                     fld       st(0)
0044b99d  d9fc                     frndint
0044b99f  dce9                     fsub      st(1), st(0)
0044b9a1  d9c9                     fxch      st(1)
0044b9a3  d9f0                     f2xm1
0044b9a5  d9e8                     fld1
0044b9a7  dec1                     faddp     st(1)
0044b9a9  d9fd                     fscale
0044b9ab  ddd9                     fstp      st(1)
0044b9ad  d95df8                   fstp      dword ptr [ebp - 8]
0044b9b0  d84df8                   fmul      dword ptr [ebp - 8]
0044b9b3  8b45d4                   mov       eax, dword ptr [ebp - 0x2c]
0044b9b6  d918                     fstp      dword ptr [eax]
0044b9b8  b800000000               mov       eax, 0
0044b9bd  5f                       pop       edi
0044b9be  5e                       pop       esi
0044b9bf  5b                       pop       ebx
0044b9c0  8be5                     mov       esp, ebp
0044b9c2  5d                       pop       ebp
0044b9c3  c3                       ret
0044b9c4  0500000000               add       eax, 0
0044b9c9  8da42400000000           lea       esp, [esp]
