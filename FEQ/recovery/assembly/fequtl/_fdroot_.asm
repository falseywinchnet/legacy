; _fdroot_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x71e20
00471e20  55                       push      ebp
00471e21  8bec                     mov       ebp, esp
00471e23  b83c000000               mov       eax, 0x3c
00471e28  e8d3710700               call      0x4e9000 ; __alloca_probe
00471e2d  53                       push      ebx
00471e2e  56                       push      esi
00471e2f  8b4508                   mov       eax, dword ptr [ebp + 8]
00471e32  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
00471e35  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
00471e38  8945cc                   mov       dword ptr [ebp - 0x34], eax
00471e3b  894dc8                   mov       dword ptr [ebp - 0x38], ecx
00471e3e  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00471e41  8945c4                   mov       dword ptr [ebp - 0x3c], eax
00471e44  8d08                     lea       ecx, [eax]
00471e46  51                       push      ecx
00471e47  ffd3                     call      ebx
00471e49  db7df4                   fstp      xword ptr [ebp - 0xc]
00471e4c  83c404                   add       esp, 4
00471e4f  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
00471e52  8d08                     lea       ecx, [eax]
00471e54  51                       push      ecx
00471e55  ffd3                     call      ebx
00471e57  83c404                   add       esp, 4
00471e5a  db6df4                   fld       xword ptr [ebp - 0xc]
00471e5d  d8c9                     fmul      st(1)
00471e5f  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00471e65  db6df4                   fld       xword ptr [ebp - 0xc]
00471e68  dfe0                     fnstsw    ax
00471e6a  9e                       sahf
00471e6b  0f8a06000000             jp        0x471e77
00471e71  0f865e040000             jbe       0x4722d5
00471e77  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
00471e7a  d9e1                     fabs
00471e7c  d900                     fld       dword ptr [eax]
00471e7e  d9c9                     fxch      st(1)
00471e80  d818                     fcomp     dword ptr [eax]
00471e82  dfe0                     fnstsw    ax
00471e84  9e                       sahf
00471e85  0f8a06000000             jp        0x471e91
00471e8b  0f864a040000             jbe       0x4722db
00471e91  d9c1                     fld       st(1)
00471e93  d9e1                     fabs
00471e95  ded9                     fcompp
00471e97  dfe0                     fnstsw    ax
00471e99  9e                       sahf
00471e9a  0f8a06000000             jp        0x471ea6
00471ea0  0f863b040000             jbe       0x4722e1
00471ea6  be03000000               mov       esi, 3
00471eab  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
00471eae  d900                     fld       dword ptr [eax]
00471eb0  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
00471eb3  d9c0                     fld       st(0)
00471eb5  d828                     fsubr     dword ptr [eax]
00471eb7  d90588f25900             fld       dword ptr [0x59f288] ; bits=000000c1, f32=-8.0
00471ebd  d9cb                     fxch      st(3)
00471ebf  d9ca                     fxch      st(2)
00471ec1  d9c9                     fxch      st(1)
00471ec3  d9c3                     fld       st(3)
00471ec5  d8c9                     fmul      st(1)
00471ec7  8d0d08f35900             lea       ecx, [0x59f308] ; bits=03000000, f32=4.203895392974451e-45
00471ecd  d84984                   fmul      dword ptr [ecx - 0x7c]
00471ed0  d8c2                     fadd      st(2)
00471ed2  d959b0                   fstp      dword ptr [ecx - 0x50]
00471ed5  d941b0                   fld       dword ptr [ecx - 0x50]
00471ed8  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00471ede  dfe0                     fnstsw    ax
00471ee0  9e                       sahf
00471ee1  0f8a02000000             jp        0x471ee9
00471ee7  764f                     jbe       0x471f38
00471ee9  db7dd0                   fstp      xword ptr [ebp - 0x30]
00471eec  db7ddc                   fstp      xword ptr [ebp - 0x24]
00471eef  db7de8                   fstp      xword ptr [ebp - 0x18]
00471ef2  db7df4                   fstp      xword ptr [ebp - 0xc]
00471ef5  8d41b0                   lea       eax, [ecx - 0x50]
00471ef8  50                       push      eax
00471ef9  ffd3                     call      ebx
00471efb  83c404                   add       esp, 4
00471efe  db6de8                   fld       xword ptr [ebp - 0x18]
00471f01  dec9                     fmulp     st(1)
00471f03  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00471f09  db6df4                   fld       xword ptr [ebp - 0xc]
00471f0c  db6de8                   fld       xword ptr [ebp - 0x18]
00471f0f  db6ddc                   fld       xword ptr [ebp - 0x24]
00471f12  db6dd0                   fld       xword ptr [ebp - 0x30]
00471f15  dfe0                     fnstsw    ax
00471f17  9e                       sahf
00471f18  0f8a1a000000             jp        0x471f38
00471f1e  7718                     ja        0x471f38
00471f20  ddd8                     fstp      st(0)
00471f22  ddd8                     fstp      st(0)
00471f24  ddd8                     fstp      st(0)
00471f26  ddd8                     fstp      st(0)
00471f28  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00471f2b  8b0db8f25900             mov       ecx, dword ptr [0x59f2b8] ; bits=00000000, f32=0.0
00471f31  8908                     mov       dword ptr [eax], ecx
00471f33  e9ab030000               jmp       0x4722e3
00471f38  d9cb                     fxch      st(3)
00471f3a  d80590f25900             fadd      dword ptr [0x59f290] ; bits=0000803f, f32=1.0
00471f40  d9c0                     fld       st(0)
00471f42  d8cc                     fmul      st(4)
00471f44  8d0d08f35900             lea       ecx, [0x59f308] ; bits=03000000, f32=4.203895392974451e-45
00471f4a  d84984                   fmul      dword ptr [ecx - 0x7c]
00471f4d  d8c2                     fadd      st(2)
00471f4f  d959b0                   fstp      dword ptr [ecx - 0x50]
00471f52  d941b0                   fld       dword ptr [ecx - 0x50]
00471f55  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00471f5b  d9cb                     fxch      st(3)
00471f5d  dfe0                     fnstsw    ax
00471f5f  9e                       sahf
00471f60  0f8a02000000             jp        0x471f68
00471f66  764f                     jbe       0x471fb7
00471f68  db7dd0                   fstp      xword ptr [ebp - 0x30]
00471f6b  db7ddc                   fstp      xword ptr [ebp - 0x24]
00471f6e  db7de8                   fstp      xword ptr [ebp - 0x18]
00471f71  db7df4                   fstp      xword ptr [ebp - 0xc]
00471f74  8d41b0                   lea       eax, [ecx - 0x50]
00471f77  50                       push      eax
00471f78  ffd3                     call      ebx
00471f7a  83c404                   add       esp, 4
00471f7d  db6de8                   fld       xword ptr [ebp - 0x18]
00471f80  dec9                     fmulp     st(1)
00471f82  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00471f88  db6df4                   fld       xword ptr [ebp - 0xc]
00471f8b  db6de8                   fld       xword ptr [ebp - 0x18]
00471f8e  db6ddc                   fld       xword ptr [ebp - 0x24]
00471f91  db6dd0                   fld       xword ptr [ebp - 0x30]
00471f94  dfe0                     fnstsw    ax
00471f96  9e                       sahf
00471f97  0f8a1a000000             jp        0x471fb7
00471f9d  7718                     ja        0x471fb7
00471f9f  ddd8                     fstp      st(0)
00471fa1  ddd8                     fstp      st(0)
00471fa3  ddd8                     fstp      st(0)
00471fa5  ddd8                     fstp      st(0)
00471fa7  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00471faa  8b0db8f25900             mov       ecx, dword ptr [0x59f2b8] ; bits=00000000, f32=0.0
00471fb0  8908                     mov       dword ptr [eax], ecx
00471fb2  e92c030000               jmp       0x4722e3
00471fb7  d9cb                     fxch      st(3)
00471fb9  d80590f25900             fadd      dword ptr [0x59f290] ; bits=0000803f, f32=1.0
00471fbf  d9c0                     fld       st(0)
00471fc1  d8cc                     fmul      st(4)
00471fc3  8d0d08f35900             lea       ecx, [0x59f308] ; bits=03000000, f32=4.203895392974451e-45
00471fc9  d84984                   fmul      dword ptr [ecx - 0x7c]
00471fcc  d8c2                     fadd      st(2)
00471fce  d959b0                   fstp      dword ptr [ecx - 0x50]
00471fd1  d941b0                   fld       dword ptr [ecx - 0x50]
00471fd4  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00471fda  d9cb                     fxch      st(3)
00471fdc  dfe0                     fnstsw    ax
00471fde  9e                       sahf
00471fdf  0f8a02000000             jp        0x471fe7
00471fe5  764f                     jbe       0x472036
00471fe7  db7dd0                   fstp      xword ptr [ebp - 0x30]
00471fea  db7ddc                   fstp      xword ptr [ebp - 0x24]
00471fed  db7de8                   fstp      xword ptr [ebp - 0x18]
00471ff0  db7df4                   fstp      xword ptr [ebp - 0xc]
00471ff3  8d41b0                   lea       eax, [ecx - 0x50]
00471ff6  50                       push      eax
00471ff7  ffd3                     call      ebx
00471ff9  83c404                   add       esp, 4
00471ffc  db6de8                   fld       xword ptr [ebp - 0x18]
00471fff  dec9                     fmulp     st(1)
00472001  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472007  db6df4                   fld       xword ptr [ebp - 0xc]
0047200a  db6de8                   fld       xword ptr [ebp - 0x18]
0047200d  db6ddc                   fld       xword ptr [ebp - 0x24]
00472010  db6dd0                   fld       xword ptr [ebp - 0x30]
00472013  dfe0                     fnstsw    ax
00472015  9e                       sahf
00472016  0f8a1a000000             jp        0x472036
0047201c  7718                     ja        0x472036
0047201e  ddd8                     fstp      st(0)
00472020  ddd8                     fstp      st(0)
00472022  ddd8                     fstp      st(0)
00472024  ddd8                     fstp      st(0)
00472026  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00472029  8b0db8f25900             mov       ecx, dword ptr [0x59f2b8] ; bits=00000000, f32=0.0
0047202f  8908                     mov       dword ptr [eax], ecx
00472031  e9ad020000               jmp       0x4722e3
00472036  d9cb                     fxch      st(3)
00472038  d80590f25900             fadd      dword ptr [0x59f290] ; bits=0000803f, f32=1.0
0047203e  d9c0                     fld       st(0)
00472040  d8cc                     fmul      st(4)
00472042  8d0d08f35900             lea       ecx, [0x59f308] ; bits=03000000, f32=4.203895392974451e-45
00472048  d84984                   fmul      dword ptr [ecx - 0x7c]
0047204b  d8c2                     fadd      st(2)
0047204d  d959b0                   fstp      dword ptr [ecx - 0x50]
00472050  d941b0                   fld       dword ptr [ecx - 0x50]
00472053  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472059  d9cb                     fxch      st(3)
0047205b  dfe0                     fnstsw    ax
0047205d  9e                       sahf
0047205e  0f8a02000000             jp        0x472066
00472064  764f                     jbe       0x4720b5
00472066  db7dd0                   fstp      xword ptr [ebp - 0x30]
00472069  db7ddc                   fstp      xword ptr [ebp - 0x24]
0047206c  db7de8                   fstp      xword ptr [ebp - 0x18]
0047206f  db7df4                   fstp      xword ptr [ebp - 0xc]
00472072  8d41b0                   lea       eax, [ecx - 0x50]
00472075  50                       push      eax
00472076  ffd3                     call      ebx
00472078  83c404                   add       esp, 4
0047207b  db6de8                   fld       xword ptr [ebp - 0x18]
0047207e  dec9                     fmulp     st(1)
00472080  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472086  db6df4                   fld       xword ptr [ebp - 0xc]
00472089  db6de8                   fld       xword ptr [ebp - 0x18]
0047208c  db6ddc                   fld       xword ptr [ebp - 0x24]
0047208f  db6dd0                   fld       xword ptr [ebp - 0x30]
00472092  dfe0                     fnstsw    ax
00472094  9e                       sahf
00472095  0f8a1a000000             jp        0x4720b5
0047209b  7718                     ja        0x4720b5
0047209d  ddd8                     fstp      st(0)
0047209f  ddd8                     fstp      st(0)
004720a1  ddd8                     fstp      st(0)
004720a3  ddd8                     fstp      st(0)
004720a5  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004720a8  8b0db8f25900             mov       ecx, dword ptr [0x59f2b8] ; bits=00000000, f32=0.0
004720ae  8908                     mov       dword ptr [eax], ecx
004720b0  e92e020000               jmp       0x4722e3
004720b5  d9cb                     fxch      st(3)
004720b7  d80590f25900             fadd      dword ptr [0x59f290] ; bits=0000803f, f32=1.0
004720bd  d9c0                     fld       st(0)
004720bf  d8cc                     fmul      st(4)
004720c1  8d0d08f35900             lea       ecx, [0x59f308] ; bits=03000000, f32=4.203895392974451e-45
004720c7  d84984                   fmul      dword ptr [ecx - 0x7c]
004720ca  d8c2                     fadd      st(2)
004720cc  d959b0                   fstp      dword ptr [ecx - 0x50]
004720cf  d941b0                   fld       dword ptr [ecx - 0x50]
004720d2  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
004720d8  d9cb                     fxch      st(3)
004720da  dfe0                     fnstsw    ax
004720dc  9e                       sahf
004720dd  0f8a02000000             jp        0x4720e5
004720e3  764f                     jbe       0x472134
004720e5  db7dd0                   fstp      xword ptr [ebp - 0x30]
004720e8  db7ddc                   fstp      xword ptr [ebp - 0x24]
004720eb  db7de8                   fstp      xword ptr [ebp - 0x18]
004720ee  db7df4                   fstp      xword ptr [ebp - 0xc]
004720f1  8d41b0                   lea       eax, [ecx - 0x50]
004720f4  50                       push      eax
004720f5  ffd3                     call      ebx
004720f7  83c404                   add       esp, 4
004720fa  db6de8                   fld       xword ptr [ebp - 0x18]
004720fd  dec9                     fmulp     st(1)
004720ff  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472105  db6df4                   fld       xword ptr [ebp - 0xc]
00472108  db6de8                   fld       xword ptr [ebp - 0x18]
0047210b  db6ddc                   fld       xword ptr [ebp - 0x24]
0047210e  db6dd0                   fld       xword ptr [ebp - 0x30]
00472111  dfe0                     fnstsw    ax
00472113  9e                       sahf
00472114  0f8a1a000000             jp        0x472134
0047211a  7718                     ja        0x472134
0047211c  ddd8                     fstp      st(0)
0047211e  ddd8                     fstp      st(0)
00472120  ddd8                     fstp      st(0)
00472122  ddd8                     fstp      st(0)
00472124  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00472127  8b0db8f25900             mov       ecx, dword ptr [0x59f2b8] ; bits=00000000, f32=0.0
0047212d  8908                     mov       dword ptr [eax], ecx
0047212f  e9af010000               jmp       0x4722e3
00472134  d9cb                     fxch      st(3)
00472136  d80590f25900             fadd      dword ptr [0x59f290] ; bits=0000803f, f32=1.0
0047213c  d9c0                     fld       st(0)
0047213e  d8cc                     fmul      st(4)
00472140  8d0d08f35900             lea       ecx, [0x59f308] ; bits=03000000, f32=4.203895392974451e-45
00472146  d84984                   fmul      dword ptr [ecx - 0x7c]
00472149  d8c2                     fadd      st(2)
0047214b  d959b0                   fstp      dword ptr [ecx - 0x50]
0047214e  d941b0                   fld       dword ptr [ecx - 0x50]
00472151  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472157  d9cb                     fxch      st(3)
00472159  dfe0                     fnstsw    ax
0047215b  9e                       sahf
0047215c  0f8a02000000             jp        0x472164
00472162  764f                     jbe       0x4721b3
00472164  db7dd0                   fstp      xword ptr [ebp - 0x30]
00472167  db7ddc                   fstp      xword ptr [ebp - 0x24]
0047216a  db7de8                   fstp      xword ptr [ebp - 0x18]
0047216d  db7df4                   fstp      xword ptr [ebp - 0xc]
00472170  8d41b0                   lea       eax, [ecx - 0x50]
00472173  50                       push      eax
00472174  ffd3                     call      ebx
00472176  83c404                   add       esp, 4
00472179  db6de8                   fld       xword ptr [ebp - 0x18]
0047217c  dec9                     fmulp     st(1)
0047217e  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472184  db6df4                   fld       xword ptr [ebp - 0xc]
00472187  db6de8                   fld       xword ptr [ebp - 0x18]
0047218a  db6ddc                   fld       xword ptr [ebp - 0x24]
0047218d  db6dd0                   fld       xword ptr [ebp - 0x30]
00472190  dfe0                     fnstsw    ax
00472192  9e                       sahf
00472193  0f8a1a000000             jp        0x4721b3
00472199  7718                     ja        0x4721b3
0047219b  ddd8                     fstp      st(0)
0047219d  ddd8                     fstp      st(0)
0047219f  ddd8                     fstp      st(0)
004721a1  ddd8                     fstp      st(0)
004721a3  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004721a6  8b0db8f25900             mov       ecx, dword ptr [0x59f2b8] ; bits=00000000, f32=0.0
004721ac  8908                     mov       dword ptr [eax], ecx
004721ae  e930010000               jmp       0x4722e3
004721b3  d9cb                     fxch      st(3)
004721b5  d80590f25900             fadd      dword ptr [0x59f290] ; bits=0000803f, f32=1.0
004721bb  d9c0                     fld       st(0)
004721bd  d8cc                     fmul      st(4)
004721bf  8d0d08f35900             lea       ecx, [0x59f308] ; bits=03000000, f32=4.203895392974451e-45
004721c5  d84984                   fmul      dword ptr [ecx - 0x7c]
004721c8  d8c2                     fadd      st(2)
004721ca  d959b0                   fstp      dword ptr [ecx - 0x50]
004721cd  d941b0                   fld       dword ptr [ecx - 0x50]
004721d0  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
004721d6  d9cb                     fxch      st(3)
004721d8  dfe0                     fnstsw    ax
004721da  9e                       sahf
004721db  0f8a02000000             jp        0x4721e3
004721e1  764f                     jbe       0x472232
004721e3  db7dd0                   fstp      xword ptr [ebp - 0x30]
004721e6  db7ddc                   fstp      xword ptr [ebp - 0x24]
004721e9  db7de8                   fstp      xword ptr [ebp - 0x18]
004721ec  db7df4                   fstp      xword ptr [ebp - 0xc]
004721ef  8d41b0                   lea       eax, [ecx - 0x50]
004721f2  50                       push      eax
004721f3  ffd3                     call      ebx
004721f5  83c404                   add       esp, 4
004721f8  db6de8                   fld       xword ptr [ebp - 0x18]
004721fb  dec9                     fmulp     st(1)
004721fd  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472203  db6df4                   fld       xword ptr [ebp - 0xc]
00472206  db6de8                   fld       xword ptr [ebp - 0x18]
00472209  db6ddc                   fld       xword ptr [ebp - 0x24]
0047220c  db6dd0                   fld       xword ptr [ebp - 0x30]
0047220f  dfe0                     fnstsw    ax
00472211  9e                       sahf
00472212  0f8a1a000000             jp        0x472232
00472218  7718                     ja        0x472232
0047221a  ddd8                     fstp      st(0)
0047221c  ddd8                     fstp      st(0)
0047221e  ddd8                     fstp      st(0)
00472220  ddd8                     fstp      st(0)
00472222  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00472225  8b0db8f25900             mov       ecx, dword ptr [0x59f2b8] ; bits=00000000, f32=0.0
0047222b  8908                     mov       dword ptr [eax], ecx
0047222d  e9b1000000               jmp       0x4722e3
00472232  d9cb                     fxch      st(3)
00472234  d80590f25900             fadd      dword ptr [0x59f290] ; bits=0000803f, f32=1.0
0047223a  d9c0                     fld       st(0)
0047223c  d8cc                     fmul      st(4)
0047223e  8d0d08f35900             lea       ecx, [0x59f308] ; bits=03000000, f32=4.203895392974451e-45
00472244  d84984                   fmul      dword ptr [ecx - 0x7c]
00472247  d8c2                     fadd      st(2)
00472249  d959b0                   fstp      dword ptr [ecx - 0x50]
0047224c  d941b0                   fld       dword ptr [ecx - 0x50]
0047224f  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472255  d9cb                     fxch      st(3)
00472257  dfe0                     fnstsw    ax
00472259  9e                       sahf
0047225a  0f8a02000000             jp        0x472262
00472260  764c                     jbe       0x4722ae
00472262  db7dd0                   fstp      xword ptr [ebp - 0x30]
00472265  db7ddc                   fstp      xword ptr [ebp - 0x24]
00472268  db7de8                   fstp      xword ptr [ebp - 0x18]
0047226b  db7df4                   fstp      xword ptr [ebp - 0xc]
0047226e  8d41b0                   lea       eax, [ecx - 0x50]
00472271  50                       push      eax
00472272  ffd3                     call      ebx
00472274  83c404                   add       esp, 4
00472277  db6de8                   fld       xword ptr [ebp - 0x18]
0047227a  dec9                     fmulp     st(1)
0047227c  d81d94f25900             fcomp     dword ptr [0x59f294] ; bits=00000000, f32=0.0
00472282  db6df4                   fld       xword ptr [ebp - 0xc]
00472285  db6de8                   fld       xword ptr [ebp - 0x18]
00472288  db6ddc                   fld       xword ptr [ebp - 0x24]
0047228b  db6dd0                   fld       xword ptr [ebp - 0x30]
0047228e  dfe0                     fnstsw    ax
00472290  9e                       sahf
00472291  0f8a17000000             jp        0x4722ae
00472297  7715                     ja        0x4722ae
00472299  ddd8                     fstp      st(0)
0047229b  ddd8                     fstp      st(0)
0047229d  ddd8                     fstp      st(0)
0047229f  ddd8                     fstp      st(0)
004722a1  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004722a4  8b0db8f25900             mov       ecx, dword ptr [0x59f2b8] ; bits=00000000, f32=0.0
004722aa  8908                     mov       dword ptr [eax], ecx
004722ac  eb35                     jmp       0x4722e3
004722ae  d9cb                     fxch      st(3)
004722b0  d80590f25900             fadd      dword ptr [0x59f290] ; bits=0000803f, f32=1.0
004722b6  d9cb                     fxch      st(3)
004722b8  4e                       dec       esi
004722b9  83fe01                   cmp       esi, 1
004722bc  0f8d01fcffff             jge       0x471ec3
004722c2  ddd8                     fstp      st(0)
004722c4  ddd8                     fstp      st(0)
004722c6  ddd8                     fstp      st(0)
004722c8  ddd8                     fstp      st(0)
004722ca  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004722cd  c70001000000             mov       dword ptr [eax], 1
004722d3  eb0e                     jmp       0x4722e3
004722d5  ddd8                     fstp      st(0)
004722d7  ddd8                     fstp      st(0)
004722d9  eb08                     jmp       0x4722e3
004722db  ddd8                     fstp      st(0)
004722dd  ddd8                     fstp      st(0)
004722df  eb02                     jmp       0x4722e3
004722e1  ddd8                     fstp      st(0)
004722e3  b800000000               mov       eax, 0
004722e8  5e                       pop       esi
004722e9  5b                       pop       ebx
004722ea  8be5                     mov       esp, ebp
004722ec  5d                       pop       ebp
004722ed  c3                       ret
004722ee  8bff                     mov       edi, edi
