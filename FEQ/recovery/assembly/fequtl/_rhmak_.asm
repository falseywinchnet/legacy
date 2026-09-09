; _rhmak_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x10740
00410740  55                       push      ebp
00410741  8bec                     mov       ebp, esp
00410743  b86c000000               mov       eax, 0x6c
00410748  e8b3880d00               call      0x4e9000 ; __alloca_probe
0041074d  53                       push      ebx
0041074e  56                       push      esi
0041074f  57                       push      edi
00410750  8b5d08                   mov       ebx, dword ptr [ebp + 8]
00410753  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00410756  8b5510                   mov       edx, dword ptr [ebp + 0x10]
00410759  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0041075c  d94004                   fld       dword ptr [eax + 4]
0041075f  d9ee                     fldz
00410761  d9c9                     fxch      st(1)
00410763  dde1                     fucom     st(1)
00410765  ddd9                     fstp      st(1)
00410767  dfe0                     fnstsw    ax
00410769  9e                       sahf
0041076a  0f8a22000000             jp        0x410792
00410770  7520                     jne       0x410792
00410772  ddd8                     fstp      st(0)
00410774  8d1dd8975500             lea       ebx, [0x5597d8] ; bits=00000000, f32=0.0
0041077a  8d43f0                   lea       eax, [ebx - 0x10]
0041077d  50                       push      eax
0041077e  e8fd260900               call      0x4a2e80 ; _jwe_ilst
00410783  83c404                   add       esp, 4
00410786  8d5be4                   lea       ebx, [ebx - 0x1c]
00410789  53                       push      ebx
0041078a  e8b12c0900               call      0x4a3440 ; _jwe_xstp
0041078f  83c404                   add       esp, 4
00410792  8d05d8975500             lea       eax, [0x5597d8] ; bits=00000000, f32=0.0
00410798  d94080                   fld       dword ptr [eax - 0x80]
0041079b  d80b                     fmul      dword ptr [ebx]
0041079d  8b7520                   mov       esi, dword ptr [ebp + 0x20]
004107a0  d906                     fld       dword ptr [esi]
004107a2  d9c0                     fld       st(0)
004107a4  d86e04                   fsubr     dword ptr [esi + 4]
004107a7  d8ca                     fmul      st(2)
004107a9  def3                     fdivrp    st(3)
004107ab  dec2                     faddp     st(2)
004107ad  8b7514                   mov       esi, dword ptr [ebp + 0x14]
004107b0  d906                     fld       dword ptr [esi]
004107b2  d9c1                     fld       st(1)
004107b4  d82e                     fsubr     dword ptr [esi]
004107b6  8b7524                   mov       esi, dword ptr [ebp + 0x24]
004107b9  d91e                     fstp      dword ptr [esi]
004107bb  d94090                   fld       dword ptr [eax - 0x70]
004107be  d801                     fadd      dword ptr [ecx]
004107c0  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004107c3  d918                     fstp      dword ptr [eax]
004107c5  d9c0                     fld       st(0)
004107c7  d8e2                     fsub      st(2)
004107c9  d95604                   fst       dword ptr [esi + 4]
004107cc  8b39                     mov       edi, dword ptr [ecx]
004107ce  897804                   mov       dword ptr [eax + 4], edi
004107d1  d95e08                   fstp      dword ptr [esi + 8]
004107d4  d902                     fld       dword ptr [edx]
004107d6  d9cb                     fxch      st(3)
004107d8  d802                     fadd      dword ptr [edx]
004107da  d95008                   fst       dword ptr [eax + 8]
004107dd  d9cb                     fxch      st(3)
004107df  db7df4                   fstp      xword ptr [ebp - 0xc]
004107e2  db7de8                   fstp      xword ptr [ebp - 0x18]
004107e5  d9c9                     fxch      st(1)
004107e7  db7ddc                   fstp      xword ptr [ebp - 0x24]
004107ea  db7dd0                   fstp      xword ptr [ebp - 0x30]
004107ed  b904000000               mov       ecx, 4
004107f2  897d9c                   mov       dword ptr [ebp - 0x64], edi
004107f5  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004107f8  8b10                     mov       edx, dword ptr [eax]
004107fa  8d5aff                   lea       ebx, [edx - 1]
004107fd  83fb00                   cmp       ebx, 0
00410800  895598                   mov       dword ptr [ebp - 0x68], edx
00410803  0f8e90000000             jle       0x410899
00410809  ba02000000               mov       edx, 2
0041080e  db6de8                   fld       xword ptr [ebp - 0x18]
00410811  db7dc4                   fstp      xword ptr [ebp - 0x3c]
00410814  db6df4                   fld       xword ptr [ebp - 0xc]
00410817  db7db8                   fstp      xword ptr [ebp - 0x48]
0041081a  83fb02                   cmp       ebx, 2
0041081d  7c53                     jl        0x410872
0041081f  db6db8                   fld       xword ptr [ebp - 0x48]
00410822  db6dc4                   fld       xword ptr [ebp - 0x3c]
00410825  eb04                     jmp       0x41082b
00410827  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
0041082b  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0041082e  d9c0                     fld       st(0)
00410830  d86490fc                 fsub      dword ptr [eax + edx*4 - 4]
00410834  8b7524                   mov       esi, dword ptr [ebp + 0x24]
00410837  d95c8efc                 fstp      dword ptr [esi + ecx*4 - 4]
0041083b  8b7d20                   mov       edi, dword ptr [ebp + 0x20]
0041083e  d9c0                     fld       st(0)
00410840  d82490                   fsub      dword ptr [eax + edx*4]
00410843  d9c2                     fld       st(2)
00410845  d84497fc                 fadd      dword ptr [edi + edx*4 - 4]
00410849  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0041084c  d9c9                     fxch      st(1)
0041084e  d91c8e                   fstp      dword ptr [esi + ecx*4]
00410851  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410855  d9c1                     fld       st(1)
00410857  d80497                   fadd      dword ptr [edi + edx*4]
0041085a  83c202                   add       edx, 2
0041085d  83c102                   add       ecx, 2
00410860  83eb02                   sub       ebx, 2
00410863  83fb02                   cmp       ebx, 2
00410866  7dbf                     jge       0x410827
00410868  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
0041086c  db7dc4                   fstp      xword ptr [ebp - 0x3c]
0041086f  db7db8                   fstp      xword ptr [ebp - 0x48]
00410872  85db                     test      ebx, ebx
00410874  7423                     je        0x410899
00410876  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00410879  db6dc4                   fld       xword ptr [ebp - 0x3c]
0041087c  d86490fc                 fsub      dword ptr [eax + edx*4 - 4]
00410880  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00410883  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410887  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0041088a  db6db8                   fld       xword ptr [ebp - 0x48]
0041088d  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410891  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410894  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
00410898  41                       inc       ecx
00410899  8b4598                   mov       eax, dword ptr [ebp - 0x68]
0041089c  48                       dec       eax
0041089d  8d58ff                   lea       ebx, [eax - 1]
004108a0  83fb00                   cmp       ebx, 0
004108a3  894594                   mov       dword ptr [ebp - 0x6c], eax
004108a6  0f8e92000000             jle       0x41093e
004108ac  8b4594                   mov       eax, dword ptr [ebp - 0x6c]
004108af  89c2                     mov       edx, eax
004108b1  db6de8                   fld       xword ptr [ebp - 0x18]
004108b4  db7dac                   fstp      xword ptr [ebp - 0x54]
004108b7  db6df4                   fld       xword ptr [ebp - 0xc]
004108ba  db7da0                   fstp      xword ptr [ebp - 0x60]
004108bd  83fb02                   cmp       ebx, 2
004108c0  7c55                     jl        0x410917
004108c2  db6da0                   fld       xword ptr [ebp - 0x60]
004108c5  db6dac                   fld       xword ptr [ebp - 0x54]
004108c8  eb04                     jmp       0x4108ce
004108ca  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
004108ce  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004108d1  d9c0                     fld       st(0)
004108d3  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
004108d7  8b7524                   mov       esi, dword ptr [ebp + 0x24]
004108da  d95c8efc                 fstp      dword ptr [esi + ecx*4 - 4]
004108de  8b7d20                   mov       edi, dword ptr [ebp + 0x20]
004108e1  d9c0                     fld       st(0)
004108e3  d84490f8                 fadd      dword ptr [eax + edx*4 - 8]
004108e7  d9c2                     fld       st(2)
004108e9  d84497fc                 fadd      dword ptr [edi + edx*4 - 4]
004108ed  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004108f0  d9c9                     fxch      st(1)
004108f2  d91c8e                   fstp      dword ptr [esi + ecx*4]
004108f5  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
004108f9  d9c1                     fld       st(1)
004108fb  d84497f8                 fadd      dword ptr [edi + edx*4 - 8]
004108ff  83c2fe                   add       edx, -2
00410902  83c102                   add       ecx, 2
00410905  83eb02                   sub       ebx, 2
00410908  83fb02                   cmp       ebx, 2
0041090b  7dbd                     jge       0x4108ca
0041090d  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00410911  db7dac                   fstp      xword ptr [ebp - 0x54]
00410914  db7da0                   fstp      xword ptr [ebp - 0x60]
00410917  85db                     test      ebx, ebx
00410919  7423                     je        0x41093e
0041091b  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0041091e  db6dac                   fld       xword ptr [ebp - 0x54]
00410921  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410925  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00410928  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0041092c  8b4520                   mov       eax, dword ptr [ebp + 0x20]
0041092f  db6da0                   fld       xword ptr [ebp - 0x60]
00410932  d84490fc                 fadd      dword ptr [eax + edx*4 - 4]
00410936  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00410939  d95c88fc                 fstp      dword ptr [eax + ecx*4 - 4]
0041093d  41                       inc       ecx
0041093e  db6de8                   fld       xword ptr [ebp - 0x18]
00410941  db6dd0                   fld       xword ptr [ebp - 0x30]
00410944  dec1                     faddp     st(1)
00410946  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00410949  d95488fc                 fst       dword ptr [eax + ecx*4 - 4]
0041094d  8b5528                   mov       edx, dword ptr [ebp + 0x28]
00410950  db6ddc                   fld       xword ptr [ebp - 0x24]
00410953  d95c8afc                 fstp      dword ptr [edx + ecx*4 - 4]
00410957  d91c88                   fstp      dword ptr [eax + ecx*4]
0041095a  8b459c                   mov       eax, dword ptr [ebp - 0x64]
0041095d  89048a                   mov       dword ptr [edx + ecx*4], eax
00410960  89c8                     mov       eax, ecx
00410962  40                       inc       eax
00410963  8b552c                   mov       edx, dword ptr [ebp + 0x2c]
00410966  8902                     mov       dword ptr [edx], eax
00410968  b800000000               mov       eax, 0
0041096d  5f                       pop       edi
0041096e  5e                       pop       esi
0041096f  5b                       pop       ebx
00410970  8be5                     mov       esp, ebp
00410972  5d                       pop       ebp
00410973  c3                       ret
00410974  0500000000               add       eax, 0
00410979  8da42400000000           lea       esp, [esp]
