; _urqmak_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x10980
00410980  55                       push      ebp
00410981  8bec                     mov       ebp, esp
00410983  b8a4000000               mov       eax, 0xa4
00410988  e873860d00               call      0x4e9000 ; __alloca_probe
0041098d  53                       push      ebx
0041098e  56                       push      esi
0041098f  57                       push      edi
00410990  8b5d08                   mov       ebx, dword ptr [ebp + 8]
00410993  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00410996  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00410999  8d0578985500             lea       eax, [0x559878] ; bits=02000000, f32=2.802596928649634e-45
0041099f  d94080                   fld       dword ptr [eax - 0x80]
004109a2  d80b                     fmul      dword ptr [ebx]
004109a4  8b7520                   mov       esi, dword ptr [ebp + 0x20]
004109a7  d906                     fld       dword ptr [esi]
004109a9  d9c0                     fld       st(0)
004109ab  d86e04                   fsubr     dword ptr [esi + 4]
004109ae  d8ca                     fmul      st(2)
004109b0  8b751c                   mov       esi, dword ptr [ebp + 0x1c]
004109b3  d87604                   fdiv      dword ptr [esi + 4]
004109b6  dec1                     faddp     st(1)
004109b8  8b7514                   mov       esi, dword ptr [ebp + 0x14]
004109bb  d906                     fld       dword ptr [esi]
004109bd  d9c2                     fld       st(2)
004109bf  d82e                     fsubr     dword ptr [esi]
004109c1  8b7524                   mov       esi, dword ptr [ebp + 0x24]
004109c4  d91e                     fstp      dword ptr [esi]
004109c6  d94090                   fld       dword ptr [eax - 0x70]
004109c9  d801                     fadd      dword ptr [ecx]
004109cb  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004109ce  d918                     fstp      dword ptr [eax]
004109d0  d9c0                     fld       st(0)
004109d2  d8e3                     fsub      st(3)
004109d4  d95604                   fst       dword ptr [esi + 4]
004109d7  8b39                     mov       edi, dword ptr [ecx]
004109d9  897804                   mov       dword ptr [eax + 4], edi
004109dc  d95e08                   fstp      dword ptr [esi + 8]
004109df  d902                     fld       dword ptr [edx]
004109e1  d9ca                     fxch      st(2)
004109e3  d802                     fadd      dword ptr [edx]
004109e5  d95008                   fst       dword ptr [eax + 8]
004109e8  d9ca                     fxch      st(2)
004109ea  db7df4                   fstp      xword ptr [ebp - 0xc]
004109ed  db7de8                   fstp      xword ptr [ebp - 0x18]
004109f0  db7ddc                   fstp      xword ptr [ebp - 0x24]
004109f3  db7dd0                   fstp      xword ptr [ebp - 0x30]
004109f6  b904000000               mov       ecx, 4
004109fb  89bd6cffffff             mov       dword ptr [ebp - 0x94], edi
00410a01  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00410a04  8b10                     mov       edx, dword ptr [eax]
00410a06  8d42ff                   lea       eax, [edx - 1]
00410a09  89c3                     mov       ebx, eax
00410a0b  83fb00                   cmp       ebx, 0
00410a0e  898568ffffff             mov       dword ptr [ebp - 0x98], eax
00410a14  899564ffffff             mov       dword ptr [ebp - 0x9c], edx
00410a1a  0f8e90000000             jle       0x410ab0
00410a20  ba02000000               mov       edx, 2
00410a25  db6de8                   fld       xword ptr [ebp - 0x18]
00410a28  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00410a2b  db6df4                   fld       xword ptr [ebp - 0xc]
00410a2e  db7db8                   fstp      xword ptr [ebp - 0x48]
00410a31  83fb02                   cmp       ebx, 2
00410a34  7c53                     jl        0x410a89
00410a36  db6db8                   fld       xword ptr [ebp - 0x48]
00410a39  db6dc4                   fld       xword ptr [ebp - 0x3c]
00410a3c  eb04                     jmp       0x410a42
00410a3e  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410a42  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410a45  d9c0                     fld       st(0)
00410a47  d86490fc                 fsub      dword ptr [eax + edx*4 - 4]
00410a4b  8b7524                   mov       esi, dword ptr [ebp + 0x24]
00410a4e  d95c8efc                 fstp      dword ptr [esi + ecx*4 - 4]
00410a52  8b7d20                   mov       edi, dword ptr [ebp + 0x20]
00410a55  d9c0                     fld       st(0)
00410a57  d82490                   fsub      dword ptr [eax + edx*4]
00410a5a  d9c2                     fld       st(2)
00410a5c  d84497fc                 fadd      dword ptr [edi + edx*4 - 4]
00410a60  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410a63  d9c9                     fxch      st(1)
00410a65  d91c8e                   fstp      dword ptr [esi + ecx*4]
00410a68  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410a6c  d9c1                     fld       st(1)
00410a6e  d80497                   fadd      dword ptr [edi + edx*4]
00410a71  83c202                   add       edx, 2
00410a74  83c102                   add       ecx, 2
00410a77  83eb02                   sub       ebx, 2
00410a7a  83fb02                   cmp       ebx, 2
00410a7d  7dbf                     jge       0x410a3e
00410a7f  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410a83  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00410a86  db7db8                   fstp      xword ptr [ebp - 0x48]
00410a89  85db                     test      ebx, ebx
00410a8b  7423                     je        0x410ab0
00410a8d  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410a90  db6dc4                   fld       xword ptr [ebp - 0x3c]
00410a93  d86490fc                 fsub      dword ptr [eax + edx*4 - 4]
00410a97  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00410a9a  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410a9e  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00410aa1  db6db8                   fld       xword ptr [ebp - 0x48]
00410aa4  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410aa8  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410aab  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410aaf  41                       inc       ecx
00410ab0  8b8564ffffff             mov       eax, dword ptr [ebp - 0x9c]
00410ab6  48                       dec       eax
00410ab7  89c3                     mov       ebx, eax
00410ab9  83fb00                   cmp       ebx, 0
00410abc  898560ffffff             mov       dword ptr [ebp - 0xa0], eax
00410ac2  0f8e8f000000             jle       0x410b57
00410ac8  89da                     mov       edx, ebx
00410aca  db6de8                   fld       xword ptr [ebp - 0x18]
00410acd  db7dac                   fstp      xword ptr [ebp - 0x54]
00410ad0  db6df4                   fld       xword ptr [ebp - 0xc]
00410ad3  db7da0                   fstp      xword ptr [ebp - 0x60]
00410ad6  83fb02                   cmp       ebx, 2
00410ad9  7c55                     jl        0x410b30
00410adb  db6da0                   fld       xword ptr [ebp - 0x60]
00410ade  db6dac                   fld       xword ptr [ebp - 0x54]
00410ae1  eb04                     jmp       0x410ae7
00410ae3  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410ae7  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410aea  d9c0                     fld       st(0)
00410aec  d86490fc                 fsub      dword ptr [eax + edx*4 - 4]
00410af0  8b7524                   mov       esi, dword ptr [ebp + 0x24]
00410af3  d95c8efc                 fstp      dword ptr [esi + ecx*4 - 4]
00410af7  8b7d20                   mov       edi, dword ptr [ebp + 0x20]
00410afa  d9c0                     fld       st(0)
00410afc  d86490f8                 fsub      dword ptr [eax + edx*4 - 8]
00410b00  d9c2                     fld       st(2)
00410b02  d86497fc                 fsub      dword ptr [edi + edx*4 - 4]
00410b06  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410b09  d9c9                     fxch      st(1)
00410b0b  d91c8e                   fstp      dword ptr [esi + ecx*4]
00410b0e  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410b12  d9c1                     fld       st(1)
00410b14  d86497f8                 fsub      dword ptr [edi + edx*4 - 8]
00410b18  83c2fe                   add       edx, -2
00410b1b  83c102                   add       ecx, 2
00410b1e  83eb02                   sub       ebx, 2
00410b21  83fb02                   cmp       ebx, 2
00410b24  7dbd                     jge       0x410ae3
00410b26  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410b2a  db7dac                   fstp      xword ptr [ebp - 0x54]
00410b2d  db7da0                   fstp      xword ptr [ebp - 0x60]
00410b30  85db                     test      ebx, ebx
00410b32  7423                     je        0x410b57
00410b34  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410b37  db6dac                   fld       xword ptr [ebp - 0x54]
00410b3a  d86490fc                 fsub      dword ptr [eax + edx*4 - 4]
00410b3e  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00410b41  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410b45  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00410b48  db6da0                   fld       xword ptr [ebp - 0x60]
00410b4b  d86490fc                 fsub      dword ptr [eax + edx*4 - 4]
00410b4f  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410b52  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410b56  41                       inc       ecx
00410b57  8b8568ffffff             mov       eax, dword ptr [ebp - 0x98]
00410b5d  89c3                     mov       ebx, eax
00410b5f  3d00000000               cmp       eax, 0
00410b64  0f8e90000000             jle       0x410bfa
00410b6a  ba02000000               mov       edx, 2
00410b6f  db6de8                   fld       xword ptr [ebp - 0x18]
00410b72  db7d94                   fstp      xword ptr [ebp - 0x6c]
00410b75  db6df4                   fld       xword ptr [ebp - 0xc]
00410b78  db7d88                   fstp      xword ptr [ebp - 0x78]
00410b7b  83fb02                   cmp       ebx, 2
00410b7e  7c53                     jl        0x410bd3
00410b80  db6d88                   fld       xword ptr [ebp - 0x78]
00410b83  db6d94                   fld       xword ptr [ebp - 0x6c]
00410b86  eb04                     jmp       0x410b8c
00410b88  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410b8c  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410b8f  d9c0                     fld       st(0)
00410b91  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410b95  8b7524                   mov       esi, dword ptr [ebp + 0x24]
00410b98  d95c8efc                 fstp      dword ptr [esi + ecx*4 - 4]
00410b9c  8b7d20                   mov       edi, dword ptr [ebp + 0x20]
00410b9f  d9c0                     fld       st(0)
00410ba1  d80490                   fadd      dword ptr [eax + edx*4]
00410ba4  d9c2                     fld       st(2)
00410ba6  d86497fc                 fsub      dword ptr [edi + edx*4 - 4]
00410baa  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410bad  d9c9                     fxch      st(1)
00410baf  d91c8e                   fstp      dword ptr [esi + ecx*4]
00410bb2  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410bb6  d9c1                     fld       st(1)
00410bb8  d82497                   fsub      dword ptr [edi + edx*4]
00410bbb  83c202                   add       edx, 2
00410bbe  83c102                   add       ecx, 2
00410bc1  83eb02                   sub       ebx, 2
00410bc4  83fb02                   cmp       ebx, 2
00410bc7  7dbf                     jge       0x410b88
00410bc9  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410bcd  db7d94                   fstp      xword ptr [ebp - 0x6c]
00410bd0  db7d88                   fstp      xword ptr [ebp - 0x78]
00410bd3  85db                     test      ebx, ebx
00410bd5  7423                     je        0x410bfa
00410bd7  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410bda  db6d94                   fld       xword ptr [ebp - 0x6c]
00410bdd  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410be1  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00410be4  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410be8  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00410beb  db6d88                   fld       xword ptr [ebp - 0x78]
00410bee  d86490fc                 fsub      dword ptr [eax + edx*4 - 4]
00410bf2  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410bf5  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410bf9  41                       inc       ecx
00410bfa  8b8560ffffff             mov       eax, dword ptr [ebp - 0xa0]
00410c00  89855cffffff             mov       dword ptr [ebp - 0xa4], eax
00410c06  83c0ff                   add       eax, -1
00410c09  89c3                     mov       ebx, eax
00410c0b  83fb00                   cmp       ebx, 0
00410c0e  0f8ead000000             jle       0x410cc1
00410c14  8b855cffffff             mov       eax, dword ptr [ebp - 0xa4]
00410c1a  89c2                     mov       edx, eax
00410c1c  db6de8                   fld       xword ptr [ebp - 0x18]
00410c1f  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
00410c25  db6df4                   fld       xword ptr [ebp - 0xc]
00410c28  dbbd70ffffff             fstp      xword ptr [ebp - 0x90]
00410c2e  83fb02                   cmp       ebx, 2
00410c31  7c61                     jl        0x410c94
00410c33  dbad70ffffff             fld       xword ptr [ebp - 0x90]
00410c39  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00410c3f  eb04                     jmp       0x410c45
00410c41  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410c45  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410c48  d9c0                     fld       st(0)
00410c4a  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410c4e  8b7524                   mov       esi, dword ptr [ebp + 0x24]
00410c51  d95c8efc                 fstp      dword ptr [esi + ecx*4 - 4]
00410c55  8b7d20                   mov       edi, dword ptr [ebp + 0x20]
00410c58  d9c0                     fld       st(0)
00410c5a  d84490f8                 fadd      dword ptr [eax + edx*4 - 8]
00410c5e  d9c2                     fld       st(2)
00410c60  d84497fc                 fadd      dword ptr [edi + edx*4 - 4]
00410c64  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410c67  d9c9                     fxch      st(1)
00410c69  d91c8e                   fstp      dword ptr [esi + ecx*4]
00410c6c  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410c70  d9c1                     fld       st(1)
00410c72  d84497f8                 fadd      dword ptr [edi + edx*4 - 8]
00410c76  83c2fe                   add       edx, -2
00410c79  83c102                   add       ecx, 2
00410c7c  83eb02                   sub       ebx, 2
00410c7f  83fb02                   cmp       ebx, 2
00410c82  7dbd                     jge       0x410c41
00410c84  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410c88  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
00410c8e  dbbd70ffffff             fstp      xword ptr [ebp - 0x90]
00410c94  85db                     test      ebx, ebx
00410c96  7429                     je        0x410cc1
00410c98  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410c9b  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00410ca1  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410ca5  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00410ca8  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410cac  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00410caf  dbad70ffffff             fld       xword ptr [ebp - 0x90]
00410cb5  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410cb9  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410cbc  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410cc0  41                       inc       ecx
00410cc1  db6de8                   fld       xword ptr [ebp - 0x18]
00410cc4  db6dd0                   fld       xword ptr [ebp - 0x30]
00410cc7  dec1                     faddp     st(1)
00410cc9  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00410ccc  d95488fc                 fst       dword ptr [eax + ecx*4 - 4]
00410cd0  8b5528                   mov       edx, dword ptr [ebp + 0x28]
00410cd3  db6ddc                   fld       xword ptr [ebp - 0x24]
00410cd6  d95c8afc                 fstp      dword ptr [edx + ecx*4 - 4]
00410cda  d91c88                   fstp      dword ptr [eax + ecx*4]
00410cdd  8b856cffffff             mov       eax, dword ptr [ebp - 0x94]
00410ce3  89048a                   mov       dword ptr [edx + ecx*4], eax
00410ce6  89c8                     mov       eax, ecx
00410ce8  40                       inc       eax
00410ce9  8b552c                   mov       edx, dword ptr [ebp + 0x2c]
00410cec  8902                     mov       dword ptr [edx], eax
00410cee  b800000000               mov       eax, 0
00410cf3  5f                       pop       edi
00410cf4  5e                       pop       esi
00410cf5  5b                       pop       ebx
00410cf6  8be5                     mov       esp, ebp
00410cf8  5d                       pop       ebp
00410cf9  c3                       ret
00410cfa  8d9b00000000             lea       ebx, [ebx]
