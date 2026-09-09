; _bdyflw_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x74e60
00474e60  83ec08                   sub       esp, 8
00474e63  53                       push      ebx
00474e64  56                       push      esi
00474e65  57                       push      edi
00474e66  8b4c2418                 mov       ecx, dword ptr [esp + 0x18]
00474e6a  8b44241c                 mov       eax, dword ptr [esp + 0x1c]
00474e6e  8b5c2420                 mov       ebx, dword ptr [esp + 0x20]
00474e72  8944240c                 mov       dword ptr [esp + 0xc], eax
00474e76  d9ee                     fldz
00474e78  d9c0                     fld       st(0)
00474e7a  d9c9                     fxch      st(1)
00474e7c  8b11                     mov       edx, dword ptr [ecx]
00474e7e  83fa00                   cmp       edx, 0
00474e81  0f8e1b010000             jle       0x474fa2
00474e87  b901000000               mov       ecx, 1
00474e8c  8b442430                 mov       eax, dword ptr [esp + 0x30]
00474e90  d900                     fld       dword ptr [eax]
00474e92  83fa02                   cmp       edx, 2
00474e95  0f8cb4000000             jl        0x474f4f
00474e9b  8b442434                 mov       eax, dword ptr [esp + 0x34]
00474e9f  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
00474ea3  8b74242c                 mov       esi, dword ptr [esp + 0x2c]
00474ea7  8b7c2428                 mov       edi, dword ptr [esp + 0x28]
00474eab  d94487fc                 fld       dword ptr [edi + eax*4 - 4]
00474eaf  d9c0                     fld       st(0)
00474eb1  d86c86fc                 fsubr     dword ptr [esi + eax*4 - 4]
00474eb5  d8ca                     fmul      st(2)
00474eb7  dec1                     faddp     st(1)
00474eb9  8d04c0                   lea       eax, [eax + eax*8]
00474ebc  8b4483dc                 mov       eax, dword ptr [ebx + eax*4 - 0x24]
00474ec0  89442410                 mov       dword ptr [esp + 0x10], eax
00474ec4  da4c2410                 fimul     dword ptr [esp + 0x10]
00474ec8  d9e0                     fchs
00474eca  d9ee                     fldz
00474ecc  dff1                     fcompi    st(1)
00474ece  d9cb                     fxch      st(3)
00474ed0  d9ca                     fxch      st(2)
00474ed2  d9c9                     fxch      st(1)
00474ed4  0f8a0c000000             jp        0x474ee6
00474eda  730a                     jae       0x474ee6
00474edc  d9cb                     fxch      st(3)
00474ede  dec1                     faddp     st(1)
00474ee0  d9c9                     fxch      st(1)
00474ee2  d9ca                     fxch      st(2)
00474ee4  eb08                     jmp       0x474eee
00474ee6  d9cb                     fxch      st(3)
00474ee8  dec2                     faddp     st(2)
00474eea  d9c9                     fxch      st(1)
00474eec  d9ca                     fxch      st(2)
00474eee  8b442434                 mov       eax, dword ptr [esp + 0x34]
00474ef2  8b0488                   mov       eax, dword ptr [eax + ecx*4]
00474ef5  8b74242c                 mov       esi, dword ptr [esp + 0x2c]
00474ef9  8b7c2428                 mov       edi, dword ptr [esp + 0x28]
00474efd  d94487fc                 fld       dword ptr [edi + eax*4 - 4]
00474f01  d9c0                     fld       st(0)
00474f03  d86c86fc                 fsubr     dword ptr [esi + eax*4 - 4]
00474f07  d8ca                     fmul      st(2)
00474f09  dec1                     faddp     st(1)
00474f0b  8d04c0                   lea       eax, [eax + eax*8]
00474f0e  8b4483dc                 mov       eax, dword ptr [ebx + eax*4 - 0x24]
00474f12  89442410                 mov       dword ptr [esp + 0x10], eax
00474f16  da4c2410                 fimul     dword ptr [esp + 0x10]
00474f1a  d9e0                     fchs
00474f1c  d9ee                     fldz
00474f1e  dff1                     fcompi    st(1)
00474f20  d9cb                     fxch      st(3)
00474f22  d9ca                     fxch      st(2)
00474f24  d9c9                     fxch      st(1)
00474f26  0f8a0c000000             jp        0x474f38
00474f2c  730a                     jae       0x474f38
00474f2e  d9cb                     fxch      st(3)
00474f30  dec1                     faddp     st(1)
00474f32  d9c9                     fxch      st(1)
00474f34  d9ca                     fxch      st(2)
00474f36  eb08                     jmp       0x474f40
00474f38  d9cb                     fxch      st(3)
00474f3a  dec2                     faddp     st(2)
00474f3c  d9c9                     fxch      st(1)
00474f3e  d9ca                     fxch      st(2)
00474f40  83c102                   add       ecx, 2
00474f43  83ea02                   sub       edx, 2
00474f46  83fa02                   cmp       edx, 2
00474f49  0f8d4cffffff             jge       0x474e9b
00474f4f  85d2                     test      edx, edx
00474f51  744d                     je        0x474fa0
00474f53  8b442434                 mov       eax, dword ptr [esp + 0x34]
00474f57  8b4488fc                 mov       eax, dword ptr [eax + ecx*4 - 4]
00474f5b  8b54242c                 mov       edx, dword ptr [esp + 0x2c]
00474f5f  8b742428                 mov       esi, dword ptr [esp + 0x28]
00474f63  d94486fc                 fld       dword ptr [esi + eax*4 - 4]
00474f67  d9c0                     fld       st(0)
00474f69  d86c82fc                 fsubr     dword ptr [edx + eax*4 - 4]
00474f6d  deca                     fmulp     st(2)
00474f6f  dec1                     faddp     st(1)
00474f71  8d04c0                   lea       eax, [eax + eax*8]
00474f74  8b4483dc                 mov       eax, dword ptr [ebx + eax*4 - 0x24]
00474f78  89442410                 mov       dword ptr [esp + 0x10], eax
00474f7c  da4c2410                 fimul     dword ptr [esp + 0x10]
00474f80  d9e0                     fchs
00474f82  d9ee                     fldz
00474f84  dff1                     fcompi    st(1)
00474f86  d9ca                     fxch      st(2)
00474f88  d9c9                     fxch      st(1)
00474f8a  0f8a08000000             jp        0x474f98
00474f90  7306                     jae       0x474f98
00474f92  dec2                     faddp     st(2)
00474f94  d9c9                     fxch      st(1)
00474f96  eb0a                     jmp       0x474fa2
00474f98  d9ca                     fxch      st(2)
00474f9a  dec1                     faddp     st(1)
00474f9c  d9c9                     fxch      st(1)
00474f9e  eb02                     jmp       0x474fa2
00474fa0  ddd8                     fstp      st(0)
00474fa2  8b44240c                 mov       eax, dword ptr [esp + 0xc]
00474fa6  dd00                     fld       qword ptr [eax]
00474fa8  d9c9                     fxch      st(1)
00474faa  dc08                     fmul      qword ptr [eax]
00474fac  8b442438                 mov       eax, dword ptr [esp + 0x38]
00474fb0  dc00                     fadd      qword ptr [eax]
00474fb2  dd18                     fstp      qword ptr [eax]
00474fb4  dcc9                     fmul      st(1), st(0)
00474fb6  8b44243c                 mov       eax, dword ptr [esp + 0x3c]
00474fba  d9c9                     fxch      st(1)
00474fbc  dc28                     fsubr     qword ptr [eax]
00474fbe  dd18                     fstp      qword ptr [eax]
00474fc0  d9c0                     fld       st(0)
00474fc2  dc0d00401d05             fmul      qword ptr [0x51d4000] ; _tamcom_
00474fc8  8b442440                 mov       eax, dword ptr [esp + 0x40]
00474fcc  dc00                     fadd      qword ptr [eax]
00474fce  dd18                     fstp      qword ptr [eax]
00474fd0  d9c0                     fld       st(0)
00474fd2  dc0d08401d05             fmul      qword ptr [0x51d4008]
00474fd8  8b442444                 mov       eax, dword ptr [esp + 0x44]
00474fdc  dc00                     fadd      qword ptr [eax]
00474fde  dd18                     fstp      qword ptr [eax]
00474fe0  d9c0                     fld       st(0)
00474fe2  dc0d10401d05             fmul      qword ptr [0x51d4010]
00474fe8  8b442448                 mov       eax, dword ptr [esp + 0x48]
00474fec  dc00                     fadd      qword ptr [eax]
00474fee  dd18                     fstp      qword ptr [eax]
00474ff0  d9c0                     fld       st(0)
00474ff2  dc0d18401d05             fmul      qword ptr [0x51d4018]
00474ff8  8b44244c                 mov       eax, dword ptr [esp + 0x4c]
00474ffc  dc00                     fadd      qword ptr [eax]
00474ffe  dd18                     fstp      qword ptr [eax]
00475000  dc0d20401d05             fmul      qword ptr [0x51d4020]
00475006  8b442450                 mov       eax, dword ptr [esp + 0x50]
0047500a  dc00                     fadd      qword ptr [eax]
0047500c  dd18                     fstp      qword ptr [eax]
0047500e  b800000000               mov       eax, 0
00475013  5f                       pop       edi
00475014  5e                       pop       esi
00475015  5b                       pop       ebx
00475016  83c408                   add       esp, 8
00475019  c3                       ret
0047501a  8d9b00000000             lea       ebx, [ebx]
