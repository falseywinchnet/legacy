; _jwe_iroc
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0xe3fd0
004e3fd0  55                       push      ebp
004e3fd1  8bec                     mov       ebp, esp
004e3fd3  83ec34                   sub       esp, 0x34
004e3fd6  53                       push      ebx
004e3fd7  8b5d08                   mov       ebx, dword ptr [ebp + 8]
004e3fda  668b03                   mov       ax, word ptr [ebx]
004e3fdd  663d0400                 cmp       ax, 4
004e3fe1  0f857a030000             jne       0x4e4361
004e3fe7  8b4b04                   mov       ecx, dword ptr [ebx + 4]
004e3fea  56                       push      esi
004e3feb  8b31                     mov       esi, dword ptr [ecx]
004e3fed  8bc6                     mov       eax, esi
004e3fef  250000807f               and       eax, 0x7f800000
004e3ff4  3d0000807f               cmp       eax, 0x7f800000
004e3ff9  754b                     jne       0x4e4046
004e3ffb  8b4308                   mov       eax, dword ptr [ebx + 8]
004e3ffe  81e6ffffff7f             and       esi, 0x7fffffff
004e4004  81fe0000807f             cmp       esi, 0x7f800000
004e400a  751d                     jne       0x4e4029
004e400c  c60049                   mov       byte ptr [eax], 0x49
004e400f  40                       inc       eax
004e4010  5e                       pop       esi
004e4011  c6006e                   mov       byte ptr [eax], 0x6e
004e4014  c6400166                 mov       byte ptr [eax + 1], 0x66
004e4018  c7430c03000000           mov       dword ptr [ebx + 0xc], 3
004e401f  b804000000               mov       eax, 4
004e4024  5b                       pop       ebx
004e4025  8be5                     mov       esp, ebp
004e4027  5d                       pop       ebp
004e4028  c3                       ret
004e4029  c6004e                   mov       byte ptr [eax], 0x4e
004e402c  40                       inc       eax
004e402d  5e                       pop       esi
004e402e  c60061                   mov       byte ptr [eax], 0x61
004e4031  c640014e                 mov       byte ptr [eax + 1], 0x4e
004e4035  c7430c03000000           mov       dword ptr [ebx + 0xc], 3
004e403c  b804000000               mov       eax, 4
004e4041  5b                       pop       ebx
004e4042  8be5                     mov       esp, ebp
004e4044  5d                       pop       ebp
004e4045  c3                       ret
004e4046  d901                     fld       dword ptr [ecx]
004e4048  8bc6                     mov       eax, esi
004e404a  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e404d  c1f817                   sar       eax, 0x17
004e4050  25ff000000               and       eax, 0xff
004e4055  83e87f                   sub       eax, 0x7f
004e4058  83f881                   cmp       eax, -0x7f
004e405b  8945f8                   mov       dword ptr [ebp - 8], eax
004e405e  7521                     jne       0x4e4081
004e4060  dd45ec                   fld       qword ptr [ebp - 0x14]
004e4063  dc0d685a5100             fmul      qword ptr [0x515a68] ; __real@4180000000000000, bits=0000000000008041, f64=33554432.0
004e4069  d95df8                   fstp      dword ptr [ebp - 8]
004e406c  8b4df8                   mov       ecx, dword ptr [ebp - 8]
004e406f  c1e917                   shr       ecx, 0x17
004e4072  81e1ff000000             and       ecx, 0xff
004e4078  81e998000000             sub       ecx, 0x98
004e407e  894df8                   mov       dword ptr [ebp - 8], ecx
004e4081  db45f8                   fild      dword ptr [ebp - 8]
004e4084  57                       push      edi
004e4085  dd5ddc                   fstp      qword ptr [ebp - 0x24]
004e4088  dd45dc                   fld       qword ptr [ebp - 0x24]
004e408b  dc0d00d65800             fmul      qword ptr [0x58d600] ; ?lg10_2@?1??jwe_irocf@@9@9, bits=527b9f501344d33f, f64=0.301029995664
004e4091  e882040200               call      0x504518 ; __ftol
004e4096  8bf8                     mov       edi, eax
004e4098  85f6                     test      esi, esi
004e409a  897dfc                   mov       dword ptr [ebp - 4], edi
004e409d  7d08                     jge       0x4e40a7
004e409f  dd45ec                   fld       qword ptr [ebp - 0x14]
004e40a2  d9e0                     fchs
004e40a4  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e40a7  be38000000               mov       esi, 0x38
004e40ac  2bf7                     sub       esi, edi
004e40ae  8975f8                   mov       dword ptr [ebp - 8], esi
004e40b1  db45f8                   fild      dword ptr [ebp - 8]
004e40b4  dd5ddc                   fstp      qword ptr [ebp - 0x24]
004e40b7  dd45dc                   fld       qword ptr [ebp - 0x24]
004e40ba  dc0d405a5100             fmul      qword ptr [0x515a40] ; __real@3fb2492492492492, bits=922449922449b23f, f64=0.07142857142857142
004e40c0  e853040200               call      0x504518 ; __ftol
004e40c5  8d14c500000000           lea       edx, [eax*8]
004e40cc  2bd0                     sub       edx, eax
004e40ce  03d2                     add       edx, edx
004e40d0  2bf2                     sub       esi, edx
004e40d2  dd04f588c45800           fld       qword ptr [esi*8 + 0x58c488]
004e40d9  dc0cc500c55800           fmul      qword ptr [eax*8 + 0x58c500]
004e40e0  dc4dec                   fmul      qword ptr [ebp - 0x14]
004e40e3  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e40e6  dd45ec                   fld       qword ptr [ebp - 0x14]
004e40e9  dc1d48535100             fcomp     qword ptr [0x515348] ; __real@3ff0000000000000, bits=000000000000f03f, f64=1.0
004e40ef  dfe0                     fnstsw    ax
004e40f1  2500010000               and       eax, 0x100
004e40f6  7532                     jne       0x4e412a
004e40f8  dd45ec                   fld       qword ptr [ebp - 0x14]
004e40fb  dc0dc8585100             fmul      qword ptr [0x5158c8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004e4101  47                       inc       edi
004e4102  897dfc                   mov       dword ptr [ebp - 4], edi
004e4105  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e4108  dd45ec                   fld       qword ptr [ebp - 0x14]
004e410b  dc1d48535100             fcomp     qword ptr [0x515348] ; __real@3ff0000000000000, bits=000000000000f03f, f64=1.0
004e4111  dfe0                     fnstsw    ax
004e4113  2500010000               and       eax, 0x100
004e4118  7510                     jne       0x4e412a
004e411a  dd45ec                   fld       qword ptr [ebp - 0x14]
004e411d  dc0dc8585100             fmul      qword ptr [0x5158c8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004e4123  47                       inc       edi
004e4124  897dfc                   mov       dword ptr [ebp - 4], edi
004e4127  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e412a  6a09                     push      9
004e412c  57                       push      edi
004e412d  53                       push      ebx
004e412e  e86d140000               call      0x4e55a0 ; _jwe_igetfig
004e4133  8bd8                     mov       ebx, eax
004e4135  b830303030               mov       eax, 0x30303030
004e413a  8945cc                   mov       dword ptr [ebp - 0x34], eax
004e413d  83c40c                   add       esp, 0xc
004e4140  8945d0                   mov       dword ptr [ebp - 0x30], eax
004e4143  8945d4                   mov       dword ptr [ebp - 0x2c], eax
004e4146  85db                     test      ebx, ebx
004e4148  8945d8                   mov       dword ptr [ebp - 0x28], eax
004e414b  0f8cfa000000             jl        0x4e424b
004e4151  8b4dec                   mov       ecx, dword ptr [ebp - 0x14]
004e4154  8b55f0                   mov       edx, dword ptr [ebp - 0x10]
004e4157  894de4                   mov       dword ptr [ebp - 0x1c], ecx
004e415a  8955e8                   mov       dword ptr [ebp - 0x18], edx
004e415d  33f6                     xor       esi, esi
004e415f  dd45e4                   fld       qword ptr [ebp - 0x1c]
004e4162  dc0d485a5100             fmul      qword ptr [0x515a48] ; __real@4024000000000000, bits=0000000000002440, f64=10.0
004e4168  dd5de4                   fstp      qword ptr [ebp - 0x1c]
004e416b  dd45e4                   fld       qword ptr [ebp - 0x1c]
004e416e  e8a5030200               call      0x504518 ; __ftol
004e4173  8945f8                   mov       dword ptr [ebp - 8], eax
004e4176  0430                     add       al, 0x30
004e4178  db45f8                   fild      dword ptr [ebp - 8]
004e417b  83fe08                   cmp       esi, 8
004e417e  884435cc                 mov       byte ptr [ebp + esi - 0x34], al
004e4182  dd5df4                   fstp      qword ptr [ebp - 0xc]
004e4185  dd45e4                   fld       qword ptr [ebp - 0x1c]
004e4188  dc65f4                   fsub      qword ptr [ebp - 0xc]
004e418b  dd5de4                   fstp      qword ptr [ebp - 0x1c]
004e418e  750c                     jne       0x4e419c
004e4190  8b45e4                   mov       eax, dword ptr [ebp - 0x1c]
004e4193  8b4de8                   mov       ecx, dword ptr [ebp - 0x18]
004e4196  8945dc                   mov       dword ptr [ebp - 0x24], eax
004e4199  894de0                   mov       dword ptr [ebp - 0x20], ecx
004e419c  46                       inc       esi
004e419d  83fe10                   cmp       esi, 0x10
004e41a0  7cbd                     jl        0x4e415f
004e41a2  dd45dc                   fld       qword ptr [ebp - 0x24]
004e41a5  dc0d485a5100             fmul      qword ptr [0x515a48] ; __real@4024000000000000, bits=0000000000002440, f64=10.0
004e41ab  d95df8                   fstp      dword ptr [ebp - 8]
004e41ae  d945f8                   fld       dword ptr [ebp - 8]
004e41b1  e862030200               call      0x504518 ; __ftol
004e41b6  83f80a                   cmp       eax, 0xa
004e41b9  7545                     jne       0x4e4200
004e41bb  b80f000000               mov       eax, 0xf
004e41c0  807c05cc39               cmp       byte ptr [ebp + eax - 0x34], 0x39
004e41c5  7503                     jne       0x4e41ca
004e41c7  48                       dec       eax
004e41c8  79f6                     jns       0x4e41c0
004e41ca  83f8ff                   cmp       eax, -1
004e41cd  7431                     je        0x4e4200
004e41cf  8a4c05cc                 mov       cl, byte ptr [ebp + eax - 0x34]
004e41d3  fec1                     inc       cl
004e41d5  884c05cc                 mov       byte ptr [ebp + eax - 0x34], cl
004e41d9  40                       inc       eax
004e41da  83f80f                   cmp       eax, 0xf
004e41dd  7f21                     jg        0x4e4200
004e41df  b910000000               mov       ecx, 0x10
004e41e4  8d7c05cc                 lea       edi, [ebp + eax - 0x34]
004e41e8  2bc8                     sub       ecx, eax
004e41ea  b830303030               mov       eax, 0x30303030
004e41ef  8bd1                     mov       edx, ecx
004e41f1  c1e902                   shr       ecx, 2
004e41f4  f3ab                     rep stosd dword ptr es:[edi], eax
004e41f6  8bca                     mov       ecx, edx
004e41f8  83e103                   and       ecx, 3
004e41fb  f3aa                     rep stosb byte ptr es:[edi], al
004e41fd  8b7dfc                   mov       edi, dword ptr [ebp - 4]
004e4200  807c1dcc35               cmp       byte ptr [ebp + ebx - 0x34], 0x35
004e4205  7537                     jne       0x4e423e
004e4207  8d4301                   lea       eax, [ebx + 1]
004e420a  83f810                   cmp       eax, 0x10
004e420d  7d0d                     jge       0x4e421c
004e420f  807c05cc30               cmp       byte ptr [ebp + eax - 0x34], 0x30
004e4214  7528                     jne       0x4e423e
004e4216  40                       inc       eax
004e4217  83f810                   cmp       eax, 0x10
004e421a  7cf3                     jl        0x4e420f
004e421c  85db                     test      ebx, ebx
004e421e  7506                     jne       0x4e4226
004e4220  85ff                     test      edi, edi
004e4222  751a                     jne       0x4e423e
004e4224  eb25                     jmp       0x4e424b
004e4226  8a441dcb                 mov       al, byte ptr [ebp + ebx - 0x35]
004e422a  3c30                     cmp       al, 0x30
004e422c  741d                     je        0x4e424b
004e422e  3c32                     cmp       al, 0x32
004e4230  7419                     je        0x4e424b
004e4232  3c34                     cmp       al, 0x34
004e4234  7415                     je        0x4e424b
004e4236  3c36                     cmp       al, 0x36
004e4238  7411                     je        0x4e424b
004e423a  3c38                     cmp       al, 0x38
004e423c  740d                     je        0x4e424b
004e423e  dd45ec                   fld       qword ptr [ebp - 0x14]
004e4241  dc04dde8c55800           fadd      qword ptr [ebx*8 + 0x58c5e8]
004e4248  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e424b  dd45ec                   fld       qword ptr [ebp - 0x14]
004e424e  dc1d48535100             fcomp     qword ptr [0x515348] ; __real@3ff0000000000000, bits=000000000000f03f, f64=1.0
004e4254  8b7508                   mov       esi, dword ptr [ebp + 8]
004e4257  dfe0                     fnstsw    ax
004e4259  2500010000               and       eax, 0x100
004e425e  7536                     jne       0x4e4296
004e4260  dd45ec                   fld       qword ptr [ebp - 0x14]
004e4263  dc0dc8585100             fmul      qword ptr [0x5158c8] ; __real@3fb999999999999a, bits=9a9999999999b93f, f64=0.1
004e4269  8a4614                   mov       al, byte ptr [esi + 0x14]
004e426c  47                       inc       edi
004e426d  3c04                     cmp       al, 4
004e426f  897dfc                   mov       dword ptr [ebp - 4], edi
004e4272  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e4275  750d                     jne       0x4e4284
004e4277  43                       inc       ebx
004e4278  83fb09                   cmp       ebx, 9
004e427b  7e19                     jle       0x4e4296
004e427d  bb09000000               mov       ebx, 9
004e4282  eb12                     jmp       0x4e4296
004e4284  84c0                     test      al, al
004e4286  740e                     je        0x4e4296
004e4288  6a09                     push      9
004e428a  57                       push      edi
004e428b  56                       push      esi
004e428c  e80f130000               call      0x4e55a0 ; _jwe_igetfig
004e4291  83c40c                   add       esp, 0xc
004e4294  8bd8                     mov       ebx, eax
004e4296  8b7e08                   mov       edi, dword ptr [esi + 8]
004e4299  33f6                     xor       esi, esi
004e429b  3bde                     cmp       ebx, esi
004e429d  7f11                     jg        0x4e42b0
004e429f  8b4508                   mov       eax, dword ptr [ebp + 8]
004e42a2  8b4dfc                   mov       ecx, dword ptr [ebp - 4]
004e42a5  89700c                   mov       dword ptr [eax + 0xc], esi
004e42a8  894810                   mov       dword ptr [eax + 0x10], ecx
004e42ab  e997000000               jmp       0x4e4347
004e42b0  dd45ec                   fld       qword ptr [ebp - 0x14]
004e42b3  dc0d485a5100             fmul      qword ptr [0x515a48] ; __real@4024000000000000, bits=0000000000002440, f64=10.0
004e42b9  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e42bc  dd45ec                   fld       qword ptr [ebp - 0x14]
004e42bf  e854020200               call      0x504518 ; __ftol
004e42c4  8945f8                   mov       dword ptr [ebp - 8], eax
004e42c7  0430                     add       al, 0x30
004e42c9  db45f8                   fild      dword ptr [ebp - 8]
004e42cc  88043e                   mov       byte ptr [esi + edi], al
004e42cf  46                       inc       esi
004e42d0  3bf3                     cmp       esi, ebx
004e42d2  dd5ddc                   fstp      qword ptr [ebp - 0x24]
004e42d5  dd45ec                   fld       qword ptr [ebp - 0x14]
004e42d8  dc65dc                   fsub      qword ptr [ebp - 0x24]
004e42db  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e42de  7cd0                     jl        0x4e42b0
004e42e0  dd45ec                   fld       qword ptr [ebp - 0x14]
004e42e3  dc0d485a5100             fmul      qword ptr [0x515a48] ; __real@4024000000000000, bits=0000000000002440, f64=10.0
004e42e9  dd5dec                   fstp      qword ptr [ebp - 0x14]
004e42ec  dd45ec                   fld       qword ptr [ebp - 0x14]
004e42ef  d95df8                   fstp      dword ptr [ebp - 8]
004e42f2  d945f8                   fld       dword ptr [ebp - 8]
004e42f5  e81e020200               call      0x504518 ; __ftol
004e42fa  83f80a                   cmp       eax, 0xa
004e42fd  753c                     jne       0x4e433b
004e42ff  8d4bff                   lea       ecx, [ebx - 1]
004e4302  8bc1                     mov       eax, ecx
004e4304  85c0                     test      eax, eax
004e4306  7c09                     jl        0x4e4311
004e4308  803c3839                 cmp       byte ptr [eax + edi], 0x39
004e430c  7503                     jne       0x4e4311
004e430e  48                       dec       eax
004e430f  79f7                     jns       0x4e4308
004e4311  83f8ff                   cmp       eax, -1
004e4314  7425                     je        0x4e433b
004e4316  8a1438                   mov       dl, byte ptr [eax + edi]
004e4319  fec2                     inc       dl
004e431b  881438                   mov       byte ptr [eax + edi], dl
004e431e  40                       inc       eax
004e431f  3bc1                     cmp       eax, ecx
004e4321  7f18                     jg        0x4e433b
004e4323  2bc8                     sub       ecx, eax
004e4325  03f8                     add       edi, eax
004e4327  41                       inc       ecx
004e4328  b830303030               mov       eax, 0x30303030
004e432d  8bd1                     mov       edx, ecx
004e432f  c1e902                   shr       ecx, 2
004e4332  f3ab                     rep stosd dword ptr es:[edi], eax
004e4334  8bca                     mov       ecx, edx
004e4336  83e103                   and       ecx, 3
004e4339  f3aa                     rep stosb byte ptr es:[edi], al
004e433b  8b4508                   mov       eax, dword ptr [ebp + 8]
004e433e  8b4dfc                   mov       ecx, dword ptr [ebp - 4]
004e4341  89580c                   mov       dword ptr [eax + 0xc], ebx
004e4344  894810                   mov       dword ptr [eax + 0x10], ecx
004e4347  8a5014                   mov       dl, byte ptr [eax + 0x14]
004e434a  5f                       pop       edi
004e434b  80fa0c                   cmp       dl, 0xc
004e434e  7509                     jne       0x4e4359
004e4350  0fbf5018                 movsx     edx, word ptr [eax + 0x18]
004e4354  2bca                     sub       ecx, edx
004e4356  894810                   mov       dword ptr [eax + 0x10], ecx
004e4359  5e                       pop       esi
004e435a  33c0                     xor       eax, eax
004e435c  5b                       pop       ebx
004e435d  8be5                     mov       esp, ebp
004e435f  5d                       pop       ebp
004e4360  c3                       ret
004e4361  663d0800                 cmp       ax, 8
004e4365  53                       push      ebx
004e4366  750d                     jne       0x4e4375
004e4368  e823000000               call      0x4e4390 ; _jwe_irocd
004e436d  83c404                   add       esp, 4
004e4370  5b                       pop       ebx
004e4371  8be5                     mov       esp, ebp
004e4373  5d                       pop       ebp
004e4374  c3                       ret
004e4375  e826090000               call      0x4e4ca0 ; _jwe_irocq
004e437a  83c404                   add       esp, 4
004e437d  5b                       pop       ebx
004e437e  8be5                     mov       esp, ebp
004e4380  5d                       pop       ebp
004e4381  c3                       ret
004e4382  90                       nop
004e4383  90                       nop
004e4384  90                       nop
004e4385  90                       nop
004e4386  90                       nop
004e4387  90                       nop
004e4388  90                       nop
004e4389  90                       nop
004e438a  90                       nop
004e438b  90                       nop
004e438c  90                       nop
004e438d  90                       nop
004e438e  90                       nop
004e438f  90                       nop
