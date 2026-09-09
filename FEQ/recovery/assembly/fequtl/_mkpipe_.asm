; _mkpipe_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0xedf0
0040edf0  55                       push      ebp
0040edf1  8bec                     mov       ebp, esp
0040edf3  b858000000               mov       eax, 0x58
0040edf8  e803a20d00               call      0x4e9000 ; __alloca_probe
0040edfd  53                       push      ebx
0040edfe  56                       push      esi
0040edff  57                       push      edi
0040ee00  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0040ee03  8b550c                   mov       edx, dword ptr [ebp + 0xc]
0040ee06  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
0040ee09  8b03                     mov       eax, dword ptr [ebx]
0040ee0b  8945fc                   mov       dword ptr [ebp - 4], eax
0040ee0e  8d3530935500             lea       esi, [0x559330] ; bits=202a4255, f32=13342886330368.0
0040ee14  dd4680                   fld       qword ptr [esi - 0x80]
0040ee17  da75fc                   fidiv     dword ptr [ebp - 4]
0040ee1a  dd5ed8                   fstp      qword ptr [esi - 0x28]
0040ee1d  8b7d14                   mov       edi, dword ptr [ebp + 0x14]
0040ee20  d907                     fld       dword ptr [edi]
0040ee22  d9c0                     fld       st(0)
0040ee24  d8c8                     fmul      st(0)
0040ee26  dc4e88                   fmul      qword ptr [esi - 0x78]
0040ee29  89c3                     mov       ebx, eax
0040ee2b  895dfc                   mov       dword ptr [ebp - 4], ebx
0040ee2e  db45fc                   fild      dword ptr [ebp - 4]
0040ee31  dd46d8                   fld       qword ptr [esi - 0x28]
0040ee34  d9c0                     fld       st(0)
0040ee36  d9fb                     fsincos
0040ee38  d9c9                     fxch      st(1)
0040ee3a  decb                     fmulp     st(3)
0040ee3c  d9cb                     fxch      st(3)
0040ee3e  def2                     fdivrp    st(2)
0040ee40  d9c9                     fxch      st(1)
0040ee42  d9fa                     fsqrt
0040ee44  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0040ee47  d946ac                   fld       dword ptr [esi - 0x54]
0040ee4a  d9c0                     fld       st(0)
0040ee4c  d808                     fmul      dword ptr [eax]
0040ee4e  d9e0                     fchs
0040ee50  d9cc                     fxch      st(4)
0040ee52  dc2dc0925500             fsubr     qword ptr [0x5592c0] ; bits=000000000000f03f, f64=1.0
0040ee58  d9c4                     fld       st(4)
0040ee5a  dec9                     fmulp     st(1)
0040ee5c  d9cb                     fxch      st(3)
0040ee5e  d9fe                     fsin
0040ee60  defb                     fdivp     st(3)
0040ee62  d9ca                     fxch      st(2)
0040ee64  d8c1                     fadd      st(1)
0040ee66  d9cc                     fxch      st(4)
0040ee68  deca                     fmulp     st(2)
0040ee6a  d9cb                     fxch      st(3)
0040ee6c  d8c1                     fadd      st(1)
0040ee6e  d902                     fld       dword ptr [edx]
0040ee70  dcc1                     fadd      st(1), st(0)
0040ee72  d9c9                     fxch      st(1)
0040ee74  d95df8                   fstp      dword ptr [ebp - 8]
0040ee77  8b45f8                   mov       eax, dword ptr [ebp - 8]
0040ee7a  d901                     fld       dword ptr [ecx]
0040ee7c  d9c3                     fld       st(3)
0040ee7e  d801                     fadd      dword ptr [ecx]
0040ee80  8b7d24                   mov       edi, dword ptr [ebp + 0x24]
0040ee83  d91f                     fstp      dword ptr [edi]
0040ee85  8975c4                   mov       dword ptr [ebp - 0x3c], esi
0040ee88  8b751c                   mov       esi, dword ptr [ebp + 0x1c]
0040ee8b  8945c0                   mov       dword ptr [ebp - 0x40], eax
0040ee8e  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
0040ee91  d940b0                   fld       dword ptr [eax - 0x50]
0040ee94  d806                     fadd      dword ptr [esi]
0040ee96  897dbc                   mov       dword ptr [ebp - 0x44], edi
0040ee99  8b7d28                   mov       edi, dword ptr [ebp + 0x28]
0040ee9c  d91f                     fstp      dword ptr [edi]
0040ee9e  d9c0                     fld       st(0)
0040eea0  8b45bc                   mov       eax, dword ptr [ebp - 0x44]
0040eea3  d8c4                     fadd      st(4)
0040eea5  d95004                   fst       dword ptr [eax + 4]
0040eea8  57                       push      edi
0040eea9  8b3e                     mov       edi, dword ptr [esi]
0040eeab  5e                       pop       esi
0040eeac  897e04                   mov       dword ptr [esi + 4], edi
0040eeaf  d95808                   fstp      dword ptr [eax + 8]
0040eeb2  d9c9                     fxch      st(1)
0040eeb4  dd5df0                   fstp      qword ptr [ebp - 0x10]
0040eeb7  d9c9                     fxch      st(1)
0040eeb9  dd5de8                   fstp      qword ptr [ebp - 0x18]
0040eebc  db7ddc                   fstp      xword ptr [ebp - 0x24]
0040eebf  db7dd0                   fstp      xword ptr [ebp - 0x30]
0040eec2  8b45c0                   mov       eax, dword ptr [ebp - 0x40]
0040eec5  894608                   mov       dword ptr [esi + 8], eax
0040eec8  8b75c4                   mov       esi, dword ptr [ebp - 0x3c]
0040eecb  897db4                   mov       dword ptr [ebp - 0x4c], edi
0040eece  8b7ed8                   mov       edi, dword ptr [esi - 0x28]
0040eed1  8b46dc                   mov       eax, dword ptr [esi - 0x24]
0040eed4  897ed0                   mov       dword ptr [esi - 0x30], edi
0040eed7  8946d4                   mov       dword ptr [esi - 0x2c], eax
0040eeda  8d53ff                   lea       edx, [ebx - 1]
0040eedd  83fa00                   cmp       edx, 0
0040eee0  0f8eeb000000             jle       0x40efd1
0040eee6  b904000000               mov       ecx, 4
0040eeeb  db6ddc                   fld       xword ptr [ebp - 0x24]
0040eeee  dd45e8                   fld       qword ptr [ebp - 0x18]
0040eef1  dd45f0                   fld       qword ptr [ebp - 0x10]
0040eef4  d9ca                     fxch      st(2)
0040eef6  d9cb                     fxch      st(3)
0040eef8  d9c9                     fxch      st(1)
0040eefa  d9ca                     fxch      st(2)
0040eefc  d9c9                     fxch      st(1)
0040eefe  83fa02                   cmp       edx, 2
0040ef01  0f8c92000000             jl        0x40ef99
0040ef07  d9cb                     fxch      st(3)
0040ef09  dd5dc8                   fstp      qword ptr [ebp - 0x38]
0040ef0c  8d0530935500             lea       eax, [0x559330] ; bits=202a4255, f32=13342886330368.0
0040ef12  dd40d0                   fld       qword ptr [eax - 0x30]
0040ef15  d9c0                     fld       st(0)
0040ef17  d9fb                     fsincos
0040ef19  d9c9                     fxch      st(1)
0040ef1b  d8cd                     fmul      st(5)
0040ef1d  dc6dc8                   fsubr     qword ptr [ebp - 0x38]
0040ef20  d95df8                   fstp      dword ptr [ebp - 8]
0040ef23  8b75f8                   mov       esi, dword ptr [ebp - 8]
0040ef26  8b7d24                   mov       edi, dword ptr [ebp + 0x24]
0040ef29  89748ffc                 mov       dword ptr [edi + ecx*4 - 4], esi
0040ef2d  d8cc                     fmul      st(4)
0040ef2f  d8c3                     fadd      st(3)
0040ef31  d8c2                     fadd      st(2)
0040ef33  d95df8                   fstp      dword ptr [ebp - 8]
0040ef36  8b75f8                   mov       esi, dword ptr [ebp - 8]
0040ef39  8945b0                   mov       dword ptr [ebp - 0x50], eax
0040ef3c  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0040ef3f  897488fc                 mov       dword ptr [eax + ecx*4 - 4], esi
0040ef43  8b75b0                   mov       esi, dword ptr [ebp - 0x50]
0040ef46  dd46d8                   fld       qword ptr [esi - 0x28]
0040ef49  d9c9                     fxch      st(1)
0040ef4b  dc46d8                   fadd      qword ptr [esi - 0x28]
0040ef4e  dd56d0                   fst       qword ptr [esi - 0x30]
0040ef51  d9c0                     fld       st(0)
0040ef53  d9fb                     fsincos
0040ef55  d9c9                     fxch      st(1)
0040ef57  d8ce                     fmul      st(6)
0040ef59  dc6dc8                   fsubr     qword ptr [ebp - 0x38]
0040ef5c  d95df8                   fstp      dword ptr [ebp - 8]
0040ef5f  897dac                   mov       dword ptr [ebp - 0x54], edi
0040ef62  8b7df8                   mov       edi, dword ptr [ebp - 8]
0040ef65  8945a8                   mov       dword ptr [ebp - 0x58], eax
0040ef68  8b45ac                   mov       eax, dword ptr [ebp - 0x54]
0040ef6b  893c88                   mov       dword ptr [eax + ecx*4], edi
0040ef6e  d8cd                     fmul      st(5)
0040ef70  d8c4                     fadd      st(4)
0040ef72  d8c3                     fadd      st(3)
0040ef74  d95df8                   fstp      dword ptr [ebp - 8]
0040ef77  8b7da8                   mov       edi, dword ptr [ebp - 0x58]
0040ef7a  8b45f8                   mov       eax, dword ptr [ebp - 8]
0040ef7d  89048f                   mov       dword ptr [edi + ecx*4], eax
0040ef80  dec1                     faddp     st(1)
0040ef82  dd5ed0                   fstp      qword ptr [esi - 0x30]
0040ef85  dd45c8                   fld       qword ptr [ebp - 0x38]
0040ef88  d9cb                     fxch      st(3)
0040ef8a  83c102                   add       ecx, 2
0040ef8d  83ea02                   sub       edx, 2
0040ef90  83fa02                   cmp       edx, 2
0040ef93  0f8d6effffff             jge       0x40ef07
0040ef99  85d2                     test      edx, edx
0040ef9b  7438                     je        0x40efd5
0040ef9d  dd0500935500             fld       qword ptr [0x559300] ; bits=0000000000000000, f64=0.0
0040efa3  d9fb                     fsincos
0040efa5  d9c9                     fxch      st(1)
0040efa7  d8ca                     fmul      st(2)
0040efa9  deed                     fsubp     st(5)
0040efab  d9cc                     fxch      st(4)
0040efad  d95df8                   fstp      dword ptr [ebp - 8]
0040efb0  8b45f8                   mov       eax, dword ptr [ebp - 8]
0040efb3  8b5524                   mov       edx, dword ptr [ebp + 0x24]
0040efb6  89448afc                 mov       dword ptr [edx + ecx*4 - 4], eax
0040efba  decb                     fmulp     st(3)
0040efbc  d9c9                     fxch      st(1)
0040efbe  dec2                     faddp     st(2)
0040efc0  dec1                     faddp     st(1)
0040efc2  d95df8                   fstp      dword ptr [ebp - 8]
0040efc5  8b45f8                   mov       eax, dword ptr [ebp - 8]
0040efc8  8b5528                   mov       edx, dword ptr [ebp + 0x28]
0040efcb  89448afc                 mov       dword ptr [edx + ecx*4 - 4], eax
0040efcf  eb0c                     jmp       0x40efdd
0040efd1  ddd8                     fstp      st(0)
0040efd3  eb08                     jmp       0x40efdd
0040efd5  ddd8                     fstp      st(0)
0040efd7  ddd8                     fstp      st(0)
0040efd9  ddd8                     fstp      st(0)
0040efdb  ddd8                     fstp      st(0)
0040efdd  db6ddc                   fld       xword ptr [ebp - 0x24]
0040efe0  db6dd0                   fld       xword ptr [ebp - 0x30]
0040efe3  dee9                     fsubp     st(1)
0040efe5  8b4524                   mov       eax, dword ptr [ebp + 0x24]
0040efe8  d9549808                 fst       dword ptr [eax + ebx*4 + 8]
0040efec  8b4d28                   mov       ecx, dword ptr [ebp + 0x28]
0040efef  8b55c0                   mov       edx, dword ptr [ebp - 0x40]
0040eff2  89549908                 mov       dword ptr [ecx + ebx*4 + 8], edx
0040eff6  d95c980c                 fstp      dword ptr [eax + ebx*4 + 0xc]
0040effa  8b45b4                   mov       eax, dword ptr [ebp - 0x4c]
0040effd  8944990c                 mov       dword ptr [ecx + ebx*4 + 0xc], eax
0040f001  89d8                     mov       eax, ebx
0040f003  83c004                   add       eax, 4
0040f006  8b4d20                   mov       ecx, dword ptr [ebp + 0x20]
0040f009  8901                     mov       dword ptr [ecx], eax
0040f00b  b800000000               mov       eax, 0
0040f010  5f                       pop       edi
0040f011  5e                       pop       esi
0040f012  5b                       pop       ebx
0040f013  8be5                     mov       esp, ebp
0040f015  5d                       pop       ebp
0040f016  c3                       ret
0040f017  8bff                     mov       edi, edi
0040f019  8da42400000000           lea       esp, [esp]
