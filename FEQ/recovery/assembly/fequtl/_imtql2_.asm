; _imtql2_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x67820
00467820  55                       push      ebp
00467821  8bec                     mov       ebp, esp
00467823  b880000000               mov       eax, 0x80
00467828  e8d3170800               call      0x4e9000 ; __alloca_probe
0046782d  53                       push      ebx
0046782e  56                       push      esi
0046782f  57                       push      edi
00467830  8b4d08                   mov       ecx, dword ptr [ebp + 8]
00467833  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
00467836  8b4510                   mov       eax, dword ptr [ebp + 0x10]
00467839  8945cc                   mov       dword ptr [ebp - 0x34], eax
0046783c  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0046783f  c70000000000             mov       dword ptr [eax], 0
00467845  8b01                     mov       eax, dword ptr [ecx]
00467847  3d01000000               cmp       eax, 1
0046784c  8945c8                   mov       dword ptr [ebp - 0x38], eax
0046784f  0f8400040000             je        0x467c55
00467855  8b4dc8                   mov       ecx, dword ptr [ebp - 0x38]
00467858  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0046785b  c744c8f800000000         mov       dword ptr [eax + ecx*8 - 8], 0
00467863  c744c8fc00000000         mov       dword ptr [eax + ecx*8 - 4], 0
0046786b  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
0046786e  8945c4                   mov       dword ptr [ebp - 0x3c], eax
00467871  3d00000000               cmp       eax, 0
00467876  0f8eb3020000             jle       0x467b2f
0046787c  b801000000               mov       eax, 1
00467881  8b4dc4                   mov       ecx, dword ptr [ebp - 0x3c]
00467884  894dc0                   mov       dword ptr [ebp - 0x40], ecx
00467887  894dbc                   mov       dword ptr [ebp - 0x44], ecx
0046788a  8945b8                   mov       dword ptr [ebp - 0x48], eax
0046788d  b800000000               mov       eax, 0
00467892  8b4db8                   mov       ecx, dword ptr [ebp - 0x48]
00467895  894db4                   mov       dword ptr [ebp - 0x4c], ecx
00467898  ba01000000               mov       edx, 1
0046789d  29ca                     sub       edx, ecx
0046789f  0355c0                   add       edx, dword ptr [ebp - 0x40]
004678a2  8945b0                   mov       dword ptr [ebp - 0x50], eax
004678a5  8955ac                   mov       dword ptr [ebp - 0x54], edx
004678a8  8b45b4                   mov       eax, dword ptr [ebp - 0x4c]
004678ab  89c2                     mov       edx, eax
004678ad  8b75ac                   mov       esi, dword ptr [ebp - 0x54]
004678b0  89f1                     mov       ecx, esi
004678b2  83fe00                   cmp       esi, 0
004678b5  0f8eb7000000             jle       0x467972
004678bb  83f902                   cmp       ecx, 2
004678be  7c75                     jl        0x467935
004678c0  8b45bc                   mov       eax, dword ptr [ebp - 0x44]
004678c3  39c2                     cmp       edx, eax
004678c5  0f84a7000000             je        0x467972
004678cb  dd44d3f8                 fld       qword ptr [ebx + edx*8 - 8]
004678cf  d9e1                     fabs
004678d1  dd04d3                   fld       qword ptr [ebx + edx*8]
004678d4  d9e1                     fabs
004678d6  dec1                     faddp     st(1)
004678d8  dd05589d5900             fld       qword ptr [0x599d58] ; bits=4f64a14091b4af3c, f64=2.2e-16
004678de  d9c9                     fxch      st(1)
004678e0  dc0d589d5900             fmul      qword ptr [0x599d58] ; bits=4f64a14091b4af3c, f64=2.2e-16
004678e6  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004678e9  dd44d0f8                 fld       qword ptr [eax + edx*8 - 8]
004678ed  d9e1                     fabs
004678ef  ded9                     fcompp
004678f1  8945a8                   mov       dword ptr [ebp - 0x58], eax
004678f4  dfe0                     fnstsw    ax
004678f6  9e                       sahf
004678f7  0f8a02000000             jp        0x4678ff
004678fd  766d                     jbe       0x46796c
004678ff  42                       inc       edx
00467900  8b45bc                   mov       eax, dword ptr [ebp - 0x44]
00467903  39c2                     cmp       edx, eax
00467905  7469                     je        0x467970
00467907  dd44d3f8                 fld       qword ptr [ebx + edx*8 - 8]
0046790b  d9e1                     fabs
0046790d  dd04d3                   fld       qword ptr [ebx + edx*8]
00467910  d9e1                     fabs
00467912  dec1                     faddp     st(1)
00467914  8b45a8                   mov       eax, dword ptr [ebp - 0x58]
00467917  dec9                     fmulp     st(1)
00467919  dd44d0f8                 fld       qword ptr [eax + edx*8 - 8]
0046791d  d9e1                     fabs
0046791f  ded9                     fcompp
00467921  dfe0                     fnstsw    ax
00467923  9e                       sahf
00467924  0f8a02000000             jp        0x46792c
0046792a  7646                     jbe       0x467972
0046792c  42                       inc       edx
0046792d  83e902                   sub       ecx, 2
00467930  83f902                   cmp       ecx, 2
00467933  7d8b                     jge       0x4678c0
00467935  85c9                     test      ecx, ecx
00467937  7439                     je        0x467972
00467939  8b45bc                   mov       eax, dword ptr [ebp - 0x44]
0046793c  39c2                     cmp       edx, eax
0046793e  7432                     je        0x467972
00467940  dd44d3f8                 fld       qword ptr [ebx + edx*8 - 8]
00467944  d9e1                     fabs
00467946  dd04d3                   fld       qword ptr [ebx + edx*8]
00467949  d9e1                     fabs
0046794b  dec1                     faddp     st(1)
0046794d  dc0d589d5900             fmul      qword ptr [0x599d58] ; bits=4f64a14091b4af3c, f64=2.2e-16
00467953  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00467956  dd44d0f8                 fld       qword ptr [eax + edx*8 - 8]
0046795a  d9e1                     fabs
0046795c  ded9                     fcompp
0046795e  dfe0                     fnstsw    ax
00467960  9e                       sahf
00467961  0f8a02000000             jp        0x467969
00467967  7609                     jbe       0x467972
00467969  42                       inc       edx
0046796a  eb06                     jmp       0x467972
0046796c  ddd8                     fstp      st(0)
0046796e  eb02                     jmp       0x467972
00467970  ddd8                     fstp      st(0)
00467972  8b45b8                   mov       eax, dword ptr [ebp - 0x48]
00467975  dd44c3f8                 fld       qword ptr [ebx + eax*8 - 8]
00467979  dd5df8                   fstp      qword ptr [ebp - 8]
0046797c  39c2                     cmp       edx, eax
0046797e  0f849e010000             je        0x467b22
00467984  837db01e                 cmp       dword ptr [ebp - 0x50], 0x1e
00467988  0f84bf020000             je        0x467c4d
0046798e  ff45b0                   inc       dword ptr [ebp - 0x50]
00467991  8b45b8                   mov       eax, dword ptr [ebp - 0x48]
00467994  dd45f8                   fld       qword ptr [ebp - 8]
00467997  dc2cc3                   fsubr     qword ptr [ebx + eax*8]
0046799a  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
0046799d  dd44c1f8                 fld       qword ptr [ecx + eax*8 - 8]
004679a1  dc44c1f8                 fadd      qword ptr [ecx + eax*8 - 8]
004679a5  def9                     fdivp     st(1)
004679a7  d9c0                     fld       st(0)
004679a9  d8c8                     fmul      st(0)
004679ab  dc05609d5900             fadd      qword ptr [0x599d60] ; bits=000000000000f03f, f64=1.0
004679b1  d9fa                     fsqrt
004679b3  dd45f8                   fld       qword ptr [ebp - 8]
004679b6  dc6cd3f8                 fsubr     qword ptr [ebx + edx*8 - 8]
004679ba  d9c9                     fxch      st(1)
004679bc  d9e1                     fabs
004679be  d9ca                     fxch      st(2)
004679c0  dc15709d5900             fcom      qword ptr [0x599d70] ; bits=0000000000000000, f64=0.0
004679c6  dfe0                     fnstsw    ax
004679c8  9e                       sahf
004679c9  0f8a02000000             jp        0x4679d1
004679cf  7306                     jae       0x4679d7
004679d1  d9ca                     fxch      st(2)
004679d3  d9e0                     fchs
004679d5  d9ca                     fxch      st(2)
004679d7  dec2                     faddp     st(2)
004679d9  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004679dc  8b4db8                   mov       ecx, dword ptr [ebp - 0x48]
004679df  d9c9                     fxch      st(1)
004679e1  dc7cc8f8                 fdivr     qword ptr [eax + ecx*8 - 8]
004679e5  dec1                     faddp     st(1)
004679e7  dd5df0                   fstp      qword ptr [ebp - 0x10]
004679ea  d9e8                     fld1
004679ec  d9c0                     fld       st(0)
004679ee  dd5de8                   fstp      qword ptr [ebp - 0x18]
004679f1  d9ee                     fldz
004679f3  dd5df8                   fstp      qword ptr [ebp - 8]
004679f6  dd5de0                   fstp      qword ptr [ebp - 0x20]
004679f9  89d0                     mov       eax, edx
004679fb  29c8                     sub       eax, ecx
004679fd  8945a4                   mov       dword ptr [ebp - 0x5c], eax
00467a00  8b45a4                   mov       eax, dword ptr [ebp - 0x5c]
00467a03  8945a0                   mov       dword ptr [ebp - 0x60], eax
00467a06  3d00000000               cmp       eax, 0
00467a0b  0f8ee4000000             jle       0x467af5
00467a11  8d4aff                   lea       ecx, [edx - 1]
00467a14  dd45e8                   fld       qword ptr [ebp - 0x18]
00467a17  dd45f0                   fld       qword ptr [ebp - 0x10]
00467a1a  dd45e0                   fld       qword ptr [ebp - 0x20]
00467a1d  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00467a20  dc4cc8f8                 fmul      qword ptr [eax + ecx*8 - 8]
00467a24  d9ca                     fxch      st(2)
00467a26  dc4cc8f8                 fmul      qword ptr [eax + ecx*8 - 8]
00467a2a  dd5dd8                   fstp      qword ptr [ebp - 0x28]
00467a2d  d9c1                     fld       st(1)
00467a2f  d9e1                     fabs
00467a31  d9c1                     fld       st(1)
00467a33  d9e1                     fabs
00467a35  d9c9                     fxch      st(1)
00467a37  ded9                     fcompp
00467a39  d9c9                     fxch      st(1)
00467a3b  89459c                   mov       dword ptr [ebp - 0x64], eax
00467a3e  dfe0                     fnstsw    ax
00467a40  9e                       sahf
00467a41  0f8a02000000             jp        0x467a49
00467a47  7222                     jb        0x467a6b
00467a49  dcf9                     fdiv      st(1), st(0)
00467a4b  d9c1                     fld       st(1)
00467a4d  d8c8                     fmul      st(0)
00467a4f  dc05609d5900             fadd      qword ptr [0x599d60] ; bits=000000000000f03f, f64=1.0
00467a55  d9fa                     fsqrt
00467a57  dcc9                     fmul      st(1), st(0)
00467a59  8b459c                   mov       eax, dword ptr [ebp - 0x64]
00467a5c  d9c9                     fxch      st(1)
00467a5e  dd1cc8                   fstp      qword ptr [eax + ecx*8]
00467a61  dc3d609d5900             fdivr     qword ptr [0x599d60] ; bits=000000000000f03f, f64=1.0
00467a67  dcc9                     fmul      st(1), st(0)
00467a69  eb24                     jmp       0x467a8f
00467a6b  d8f1                     fdiv      st(1)
00467a6d  d9c0                     fld       st(0)
00467a6f  d8c8                     fmul      st(0)
00467a71  dc05609d5900             fadd      qword ptr [0x599d60] ; bits=000000000000f03f, f64=1.0
00467a77  d9fa                     fsqrt
00467a79  dcca                     fmul      st(2), st(0)
00467a7b  8b459c                   mov       eax, dword ptr [ebp - 0x64]
00467a7e  d9ca                     fxch      st(2)
00467a80  dd1cc8                   fstp      qword ptr [eax + ecx*8]
00467a83  d9c9                     fxch      st(1)
00467a85  dc3d609d5900             fdivr     qword ptr [0x599d60] ; bits=000000000000f03f, f64=1.0
00467a8b  dcc9                     fmul      st(1), st(0)
00467a8d  d9c9                     fxch      st(1)
00467a8f  dd45f8                   fld       qword ptr [ebp - 8]
00467a92  dc2ccb                   fsubr     qword ptr [ebx + ecx*8]
00467a95  d9c0                     fld       st(0)
00467a97  dc6ccbf8                 fsubr     qword ptr [ebx + ecx*8 - 8]
00467a9b  d8ca                     fmul      st(2)
00467a9d  d9c3                     fld       st(3)
00467a9f  d8c0                     fadd      st(0)
00467aa1  dc4dd8                   fmul      qword ptr [ebp - 0x28]
00467aa4  dec1                     faddp     st(1)
00467aa6  d9c2                     fld       st(2)
00467aa8  d8c9                     fmul      st(1)
00467aaa  dcc2                     fadd      st(2), st(0)
00467aac  d9ca                     fxch      st(2)
00467aae  dd1ccb                   fstp      qword ptr [ebx + ecx*8]
00467ab1  d8cb                     fmul      st(3)
00467ab3  dc65d8                   fsub      qword ptr [ebp - 0x28]
00467ab6  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
00467ab9  dd04c8                   fld       qword ptr [eax + ecx*8]
00467abc  d9c3                     fld       st(3)
00467abe  dc4cc8f8                 fmul      qword ptr [eax + ecx*8 - 8]
00467ac2  d9c5                     fld       st(5)
00467ac4  dc0cc8                   fmul      qword ptr [eax + ecx*8]
00467ac7  dec1                     faddp     st(1)
00467ac9  dd1cc8                   fstp      qword ptr [eax + ecx*8]
00467acc  d9c4                     fld       st(4)
00467ace  dc4cc8f8                 fmul      qword ptr [eax + ecx*8 - 8]
00467ad2  d9c9                     fxch      st(1)
00467ad4  d8cc                     fmul      st(4)
00467ad6  dee9                     fsubp     st(1)
00467ad8  dd5cc8f8                 fstp      qword ptr [eax + ecx*8 - 8]
00467adc  d9c9                     fxch      st(1)
00467ade  dd5df8                   fstp      qword ptr [ebp - 8]
00467ae1  d9c9                     fxch      st(1)
00467ae3  49                       dec       ecx
00467ae4  836da001                 sub       dword ptr [ebp - 0x60], 1
00467ae8  0f852fffffff             jne       0x467a1d
00467aee  ddd8                     fstp      st(0)
00467af0  dd5df0                   fstp      qword ptr [ebp - 0x10]
00467af3  ddd8                     fstp      st(0)
00467af5  8b45b8                   mov       eax, dword ptr [ebp - 0x48]
00467af8  dd45f8                   fld       qword ptr [ebp - 8]
00467afb  dc6cc3f8                 fsubr     qword ptr [ebx + eax*8 - 8]
00467aff  dd5cc3f8                 fstp      qword ptr [ebx + eax*8 - 8]
00467b03  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
00467b06  dd45f0                   fld       qword ptr [ebp - 0x10]
00467b09  dd5cc1f8                 fstp      qword ptr [ecx + eax*8 - 8]
00467b0d  c744d1f800000000         mov       dword ptr [ecx + edx*8 - 8], 0
00467b15  c744d1fc00000000         mov       dword ptr [ecx + edx*8 - 4], 0
00467b1d  e986fdffff               jmp       0x4678a8
00467b22  ff45b8                   inc       dword ptr [ebp - 0x48]
00467b25  836dc401                 sub       dword ptr [ebp - 0x3c], 1
00467b29  0f855efdffff             jne       0x46788d
00467b2f  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
00467b32  8d48ff                   lea       ecx, [eax - 1]
00467b35  83f900                   cmp       ecx, 0
00467b38  894d98                   mov       dword ptr [ebp - 0x68], ecx
00467b3b  0f8e14010000             jle       0x467c55
00467b41  b802000000               mov       eax, 2
00467b46  8b4dc8                   mov       ecx, dword ptr [ebp - 0x38]
00467b49  894d94                   mov       dword ptr [ebp - 0x6c], ecx
00467b4c  894590                   mov       dword ptr [ebp - 0x70], eax
00467b4f  8b4590                   mov       eax, dword ptr [ebp - 0x70]
00467b52  8d48ff                   lea       ecx, [eax - 1]
00467b55  89ca                     mov       edx, ecx
00467b57  dd44cbf8                 fld       qword ptr [ebx + ecx*8 - 8]
00467b5b  d9c0                     fld       st(0)
00467b5d  d9c9                     fxch      st(1)
00467b5f  dd5dd0                   fstp      qword ptr [ebp - 0x30]
00467b62  89558c                   mov       dword ptr [ebp - 0x74], edx
00467b65  8b4590                   mov       eax, dword ptr [ebp - 0x70]
00467b68  894588                   mov       dword ptr [ebp - 0x78], eax
00467b6b  8b7594                   mov       esi, dword ptr [ebp - 0x6c]
00467b6e  29c6                     sub       esi, eax
00467b70  89f2                     mov       edx, esi
00467b72  42                       inc       edx
00467b73  83fa00                   cmp       edx, 0
00467b76  7e7e                     jle       0x467bf6
00467b78  8b4588                   mov       eax, dword ptr [ebp - 0x78]
00467b7b  8945b0                   mov       dword ptr [ebp - 0x50], eax
00467b7e  83fa02                   cmp       edx, 2
00467b81  7c4f                     jl        0x467bd2
00467b83  8b45b0                   mov       eax, dword ptr [ebp - 0x50]
00467b86  dd44c3f8                 fld       qword ptr [ebx + eax*8 - 8]
00467b8a  d8d1                     fcom      st(1)
00467b8c  dfe0                     fnstsw    ax
00467b8e  9e                       sahf
00467b8f  0f8a02000000             jp        0x467b97
00467b95  730a                     jae       0x467ba1
00467b97  ddd9                     fstp      st(1)
00467b99  8b45b0                   mov       eax, dword ptr [ebp - 0x50]
00467b9c  89458c                   mov       dword ptr [ebp - 0x74], eax
00467b9f  eb02                     jmp       0x467ba3
00467ba1  ddd8                     fstp      st(0)
00467ba3  8b45b0                   mov       eax, dword ptr [ebp - 0x50]
00467ba6  40                       inc       eax
00467ba7  dd44c3f8                 fld       qword ptr [ebx + eax*8 - 8]
00467bab  d8d1                     fcom      st(1)
00467bad  8945b0                   mov       dword ptr [ebp - 0x50], eax
00467bb0  dfe0                     fnstsw    ax
00467bb2  9e                       sahf
00467bb3  0f8a02000000             jp        0x467bbb
00467bb9  730a                     jae       0x467bc5
00467bbb  ddd9                     fstp      st(1)
00467bbd  8b45b0                   mov       eax, dword ptr [ebp - 0x50]
00467bc0  89458c                   mov       dword ptr [ebp - 0x74], eax
00467bc3  eb02                     jmp       0x467bc7
00467bc5  ddd8                     fstp      st(0)
00467bc7  ff45b0                   inc       dword ptr [ebp - 0x50]
00467bca  83ea02                   sub       edx, 2
00467bcd  83fa02                   cmp       edx, 2
00467bd0  7db1                     jge       0x467b83
00467bd2  85d2                     test      edx, edx
00467bd4  7420                     je        0x467bf6
00467bd6  8b45b0                   mov       eax, dword ptr [ebp - 0x50]
00467bd9  dd44c3f8                 fld       qword ptr [ebx + eax*8 - 8]
00467bdd  d8d1                     fcom      st(1)
00467bdf  dfe0                     fnstsw    ax
00467be1  9e                       sahf
00467be2  0f8a02000000             jp        0x467bea
00467be8  730a                     jae       0x467bf4
00467bea  ddd9                     fstp      st(1)
00467bec  8b45b0                   mov       eax, dword ptr [ebp - 0x50]
00467bef  89458c                   mov       dword ptr [ebp - 0x74], eax
00467bf2  eb02                     jmp       0x467bf6
00467bf4  ddd8                     fstp      st(0)
00467bf6  8b458c                   mov       eax, dword ptr [ebp - 0x74]
00467bf9  39c8                     cmp       eax, ecx
00467bfb  743f                     je        0x467c3c
00467bfd  8b458c                   mov       eax, dword ptr [ebp - 0x74]
00467c00  dd45d0                   fld       qword ptr [ebp - 0x30]
00467c03  dd5cc3f8                 fstp      qword ptr [ebx + eax*8 - 8]
00467c07  8b55cc                   mov       edx, dword ptr [ebp - 0x34]
00467c0a  dd5ccbf8                 fstp      qword ptr [ebx + ecx*8 - 8]
00467c0e  8b74caf8                 mov       esi, dword ptr [edx + ecx*8 - 8]
00467c12  8b7ccafc                 mov       edi, dword ptr [edx + ecx*8 - 4]
00467c16  897584                   mov       dword ptr [ebp - 0x7c], esi
00467c19  8b74c2f8                 mov       esi, dword ptr [edx + eax*8 - 8]
00467c1d  897d80                   mov       dword ptr [ebp - 0x80], edi
00467c20  8b7cc2fc                 mov       edi, dword ptr [edx + eax*8 - 4]
00467c24  8974caf8                 mov       dword ptr [edx + ecx*8 - 8], esi
00467c28  897ccafc                 mov       dword ptr [edx + ecx*8 - 4], edi
00467c2c  8b7584                   mov       esi, dword ptr [ebp - 0x7c]
00467c2f  8974c2f8                 mov       dword ptr [edx + eax*8 - 8], esi
00467c33  8b7580                   mov       esi, dword ptr [ebp - 0x80]
00467c36  8974c2fc                 mov       dword ptr [edx + eax*8 - 4], esi
00467c3a  eb02                     jmp       0x467c3e
00467c3c  ddd8                     fstp      st(0)
00467c3e  ff4590                   inc       dword ptr [ebp - 0x70]
00467c41  836d9801                 sub       dword ptr [ebp - 0x68], 1
00467c45  0f8504ffffff             jne       0x467b4f
00467c4b  eb08                     jmp       0x467c55
00467c4d  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00467c50  8b4db8                   mov       ecx, dword ptr [ebp - 0x48]
00467c53  8908                     mov       dword ptr [eax], ecx
00467c55  b800000000               mov       eax, 0
00467c5a  5f                       pop       edi
00467c5b  5e                       pop       esi
00467c5c  5b                       pop       ebx
00467c5d  8be5                     mov       esp, ebp
00467c5f  5d                       pop       ebp
00467c60  c3                       ret
00467c61  90                       nop
00467c62  8da42400000000           lea       esp, [esp]
00467c69  8da42400000000           lea       esp, [esp]
