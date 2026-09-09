; _urqte_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x10d00
00410d00  55                       push      ebp
00410d01  8bec                     mov       ebp, esp
00410d03  b888000000               mov       eax, 0x88
00410d08  e8f3820d00               call      0x4e9000 ; __alloca_probe
00410d0d  53                       push      ebx
00410d0e  8b4d08                   mov       ecx, dword ptr [ebp + 8]
00410d11  8b5d0c                   mov       ebx, dword ptr [ebp + 0xc]
00410d14  8b4510                   mov       eax, dword ptr [ebp + 0x10]
00410d17  898578ffffff             mov       dword ptr [ebp - 0x88], eax
00410d1d  d903                     fld       dword ptr [ebx]
00410d1f  8d15a8985500             lea       edx, [0x5598a8] ; bits=00000000, f32=0.0
00410d25  d942ac                   fld       dword ptr [edx - 0x54]
00410d28  d9c0                     fld       st(0)
00410d2a  d80b                     fmul      dword ptr [ebx]
00410d2c  db7df0                   fstp      xword ptr [ebp - 0x10]
00410d2f  d901                     fld       dword ptr [ecx]
00410d31  d9c9                     fxch      st(1)
00410d33  d809                     fmul      dword ptr [ecx]
00410d35  db7de4                   fstp      xword ptr [ebp - 0x1c]
00410d38  d9c9                     fxch      st(1)
00410d3a  db7dd8                   fstp      xword ptr [ebp - 0x28]
00410d3d  8b8578ffffff             mov       eax, dword ptr [ebp - 0x88]
00410d43  db7dcc                   fstp      xword ptr [ebp - 0x34]
00410d46  c7000b000000             mov       dword ptr [eax], 0xb
00410d4c  b901000000               mov       ecx, 1
00410d51  db6de4                   fld       xword ptr [ebp - 0x1c]
00410d54  db6df0                   fld       xword ptr [ebp - 0x10]
00410d57  dec9                     fmulp     st(1)
00410d59  d8c8                     fmul      st(0)
00410d5b  d94294                   fld       dword ptr [edx - 0x6c]
00410d5e  db6df0                   fld       xword ptr [ebp - 0x10]
00410d61  db6de4                   fld       xword ptr [ebp - 0x1c]
00410d64  d9ca                     fxch      st(2)
00410d66  d9cb                     fxch      st(3)
00410d68  d9c9                     fxch      st(1)
00410d6a  d9ca                     fxch      st(2)
00410d6c  d9c9                     fxch      st(1)
00410d6e  db7da8                   fstp      xword ptr [ebp - 0x58]
00410d71  db7d9c                   fstp      xword ptr [ebp - 0x64]
00410d74  db7dc0                   fstp      xword ptr [ebp - 0x40]
00410d77  db7db4                   fstp      xword ptr [ebp - 0x4c]
00410d7a  8d05a8985500             lea       eax, [0x5598a8] ; bits=00000000, f32=0.0
00410d80  d940a0                   fld       dword ptr [eax - 0x60]
00410d83  db6db4                   fld       xword ptr [ebp - 0x4c]
00410d86  d848a0                   fmul      dword ptr [eax - 0x60]
00410d89  d94090                   fld       dword ptr [eax - 0x70]
00410d8c  d9c9                     fxch      st(1)
00410d8e  d84890                   fmul      dword ptr [eax - 0x70]
00410d91  d958e4                   fstp      dword ptr [eax - 0x1c]
00410d94  d940e4                   fld       dword ptr [eax - 0x1c]
00410d97  d9c0                     fld       st(0)
00410d99  d9fb                     fsincos
00410d9b  db6dc0                   fld       xword ptr [ebp - 0x40]
00410d9e  deca                     fmulp     st(2)
00410da0  d9c9                     fxch      st(1)
00410da2  d8c8                     fmul      st(0)
00410da4  db6d9c                   fld       xword ptr [ebp - 0x64]
00410da7  deca                     fmulp     st(2)
00410da9  d9c9                     fxch      st(1)
00410dab  d8c8                     fmul      st(0)
00410dad  dec1                     faddp     st(1)
00410daf  db6da8                   fld       xword ptr [ebp - 0x58]
00410db2  def1                     fdivrp    st(1)
00410db4  d9fa                     fsqrt
00410db6  d95dfc                   fstp      dword ptr [ebp - 4]
00410db9  d945fc                   fld       dword ptr [ebp - 4]
00410dbc  d9c9                     fxch      st(1)
00410dbe  d9fb                     fsincos
00410dc0  d8ca                     fmul      st(2)
00410dc2  8b5514                   mov       edx, dword ptr [ebp + 0x14]
00410dc5  d95c8afc                 fstp      dword ptr [edx + ecx*4 - 4]
00410dc9  dec9                     fmulp     st(1)
00410dcb  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
00410dce  d95c8bfc                 fstp      dword ptr [ebx + ecx*4 - 4]
00410dd2  db6db4                   fld       xword ptr [ebp - 0x4c]
00410dd5  d82558985500             fsub      dword ptr [0x559858] ; bits=0000803f, f32=1.0
00410ddb  d9c0                     fld       st(0)
00410ddd  d8cb                     fmul      st(3)
00410ddf  d8ca                     fmul      st(2)
00410de1  d958e4                   fstp      dword ptr [eax - 0x1c]
00410de4  d940e4                   fld       dword ptr [eax - 0x1c]
00410de7  d9c0                     fld       st(0)
00410de9  d9fb                     fsincos
00410deb  db6dc0                   fld       xword ptr [ebp - 0x40]
00410dee  deca                     fmulp     st(2)
00410df0  d9c9                     fxch      st(1)
00410df2  d8c8                     fmul      st(0)
00410df4  db6d9c                   fld       xword ptr [ebp - 0x64]
00410df7  deca                     fmulp     st(2)
00410df9  d9c9                     fxch      st(1)
00410dfb  d8c8                     fmul      st(0)
00410dfd  dec1                     faddp     st(1)
00410dff  db6da8                   fld       xword ptr [ebp - 0x58]
00410e02  def1                     fdivrp    st(1)
00410e04  d9fa                     fsqrt
00410e06  d95dfc                   fstp      dword ptr [ebp - 4]
00410e09  d945fc                   fld       dword ptr [ebp - 4]
00410e0c  d9c9                     fxch      st(1)
00410e0e  d9fb                     fsincos
00410e10  d8ca                     fmul      st(2)
00410e12  d91c8a                   fstp      dword ptr [edx + ecx*4]
00410e15  dec9                     fmulp     st(1)
00410e17  d91c8b                   fstp      dword ptr [ebx + ecx*4]
00410e1a  d82558985500             fsub      dword ptr [0x559858] ; bits=0000803f, f32=1.0
00410e20  d9c0                     fld       st(0)
00410e22  d8cb                     fmul      st(3)
00410e24  d8ca                     fmul      st(2)
00410e26  d958e4                   fstp      dword ptr [eax - 0x1c]
00410e29  d940e4                   fld       dword ptr [eax - 0x1c]
00410e2c  d9c0                     fld       st(0)
00410e2e  d9fb                     fsincos
00410e30  db6dc0                   fld       xword ptr [ebp - 0x40]
00410e33  deca                     fmulp     st(2)
00410e35  d9c9                     fxch      st(1)
00410e37  d8c8                     fmul      st(0)
00410e39  db6d9c                   fld       xword ptr [ebp - 0x64]
00410e3c  deca                     fmulp     st(2)
00410e3e  d9c9                     fxch      st(1)
00410e40  d8c8                     fmul      st(0)
00410e42  dec1                     faddp     st(1)
00410e44  db6da8                   fld       xword ptr [ebp - 0x58]
00410e47  def1                     fdivrp    st(1)
00410e49  d9fa                     fsqrt
00410e4b  d95dfc                   fstp      dword ptr [ebp - 4]
00410e4e  d945fc                   fld       dword ptr [ebp - 4]
00410e51  d9c9                     fxch      st(1)
00410e53  d9fb                     fsincos
00410e55  d8ca                     fmul      st(2)
00410e57  d95c8a04                 fstp      dword ptr [edx + ecx*4 + 4]
00410e5b  dec9                     fmulp     st(1)
00410e5d  d95c8b04                 fstp      dword ptr [ebx + ecx*4 + 4]
00410e61  d82558985500             fsub      dword ptr [0x559858] ; bits=0000803f, f32=1.0
00410e67  d9c0                     fld       st(0)
00410e69  d8cb                     fmul      st(3)
00410e6b  d8ca                     fmul      st(2)
00410e6d  d958e4                   fstp      dword ptr [eax - 0x1c]
00410e70  d940e4                   fld       dword ptr [eax - 0x1c]
00410e73  d9c0                     fld       st(0)
00410e75  d9fb                     fsincos
00410e77  db6dc0                   fld       xword ptr [ebp - 0x40]
00410e7a  deca                     fmulp     st(2)
00410e7c  d9c9                     fxch      st(1)
00410e7e  d8c8                     fmul      st(0)
00410e80  db6d9c                   fld       xword ptr [ebp - 0x64]
00410e83  deca                     fmulp     st(2)
00410e85  d9c9                     fxch      st(1)
00410e87  d8c8                     fmul      st(0)
00410e89  dec1                     faddp     st(1)
00410e8b  db6da8                   fld       xword ptr [ebp - 0x58]
00410e8e  def1                     fdivrp    st(1)
00410e90  d9fa                     fsqrt
00410e92  d95dfc                   fstp      dword ptr [ebp - 4]
00410e95  d945fc                   fld       dword ptr [ebp - 4]
00410e98  d9c9                     fxch      st(1)
00410e9a  d9fb                     fsincos
00410e9c  d8ca                     fmul      st(2)
00410e9e  d95c8a08                 fstp      dword ptr [edx + ecx*4 + 8]
00410ea2  dec9                     fmulp     st(1)
00410ea4  d95c8b08                 fstp      dword ptr [ebx + ecx*4 + 8]
00410ea8  d82558985500             fsub      dword ptr [0x559858] ; bits=0000803f, f32=1.0
00410eae  dcca                     fmul      st(2), st(0)
00410eb0  d9ca                     fxch      st(2)
00410eb2  dec9                     fmulp     st(1)
00410eb4  d958e4                   fstp      dword ptr [eax - 0x1c]
00410eb7  d940e4                   fld       dword ptr [eax - 0x1c]
00410eba  d9c0                     fld       st(0)
00410ebc  d9fb                     fsincos
00410ebe  db6dc0                   fld       xword ptr [ebp - 0x40]
00410ec1  deca                     fmulp     st(2)
00410ec3  d9c9                     fxch      st(1)
00410ec5  d8c8                     fmul      st(0)
00410ec7  db6d9c                   fld       xword ptr [ebp - 0x64]
00410eca  deca                     fmulp     st(2)
00410ecc  d9c9                     fxch      st(1)
00410ece  d8c8                     fmul      st(0)
00410ed0  dec1                     faddp     st(1)
00410ed2  db6da8                   fld       xword ptr [ebp - 0x58]
00410ed5  def1                     fdivrp    st(1)
00410ed7  d9fa                     fsqrt
00410ed9  d95dfc                   fstp      dword ptr [ebp - 4]
00410edc  d945fc                   fld       dword ptr [ebp - 4]
00410edf  d9c9                     fxch      st(1)
00410ee1  d9fb                     fsincos
00410ee3  d8ca                     fmul      st(2)
00410ee5  d95c8a0c                 fstp      dword ptr [edx + ecx*4 + 0xc]
00410ee9  dec9                     fmulp     st(1)
00410eeb  d95c8b0c                 fstp      dword ptr [ebx + ecx*4 + 0xc]
00410eef  d82558985500             fsub      dword ptr [0x559858] ; bits=0000803f, f32=1.0
00410ef5  db6dc0                   fld       xword ptr [ebp - 0x40]
00410ef8  db6d9c                   fld       xword ptr [ebp - 0x64]
00410efb  db6da8                   fld       xword ptr [ebp - 0x58]
00410efe  83c105                   add       ecx, 5
00410f01  83f90b                   cmp       ecx, 0xb
00410f04  0f8c64feffff             jl        0x410d6e
00410f0a  8d05a8985500             lea       eax, [0x5598a8] ; bits=00000000, f32=0.0
00410f10  d9cb                     fxch      st(3)
00410f12  d848a0                   fmul      dword ptr [eax - 0x60]
00410f15  d84890                   fmul      dword ptr [eax - 0x70]
00410f18  d958e4                   fstp      dword ptr [eax - 0x1c]
00410f1b  d940e4                   fld       dword ptr [eax - 0x1c]
00410f1e  d9c0                     fld       st(0)
00410f20  d9fb                     fsincos
00410f22  d9c9                     fxch      st(1)
00410f24  decc                     fmulp     st(4)
00410f26  d9cb                     fxch      st(3)
00410f28  d8c8                     fmul      st(0)
00410f2a  d9cb                     fxch      st(3)
00410f2c  deca                     fmulp     st(2)
00410f2e  d9c9                     fxch      st(1)
00410f30  d8c8                     fmul      st(0)
00410f32  dec2                     faddp     st(2)
00410f34  d9ca                     fxch      st(2)
00410f36  def1                     fdivrp    st(1)
00410f38  d9fa                     fsqrt
00410f3a  d95dfc                   fstp      dword ptr [ebp - 4]
00410f3d  d945fc                   fld       dword ptr [ebp - 4]
00410f40  d9c9                     fxch      st(1)
00410f42  d9fb                     fsincos
00410f44  d8ca                     fmul      st(2)
00410f46  8b5514                   mov       edx, dword ptr [ebp + 0x14]
00410f49  d95c8afc                 fstp      dword ptr [edx + ecx*4 - 4]
00410f4d  dec9                     fmulp     st(1)
00410f4f  8b5518                   mov       edx, dword ptr [ebp + 0x18]
00410f52  d95c8afc                 fstp      dword ptr [edx + ecx*4 - 4]
00410f56  db6dd8                   fld       xword ptr [ebp - 0x28]
00410f59  db6dcc                   fld       xword ptr [ebp - 0x34]
00410f5c  dec9                     fmulp     st(1)
00410f5e  d848a4                   fmul      dword ptr [eax - 0x5c]
00410f61  d84898                   fmul      dword ptr [eax - 0x68]
00410f64  db7d90                   fstp      xword ptr [ebp - 0x70]
00410f67  d9ee                     fldz
00410f69  dd5d88                   fstp      qword ptr [ebp - 0x78]
00410f6c  b902000000               mov       ecx, 2
00410f71  dd4588                   fld       qword ptr [ebp - 0x78]
00410f74  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00410f77  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00410f7b  d84488fc                 fadd      dword ptr [eax + ecx*4 - 4]
00410f7f  d80d54985500             fmul      dword ptr [0x559854] ; bits=0000003f, f32=0.5
00410f85  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00410f88  d94488f8                 fld       dword ptr [eax + ecx*4 - 8]
00410f8c  d86c88fc                 fsubr     dword ptr [eax + ecx*4 - 4]
00410f90  dec9                     fmulp     st(1)
00410f92  dec1                     faddp     st(1)
00410f94  41                       inc       ecx
00410f95  83f90c                   cmp       ecx, 0xc
00410f98  7cda                     jl        0x410f74
00410f9a  dc0d28985500             fmul      qword ptr [0x559828] ; bits=0000000000001040, f64=4.0
00410fa0  db6d90                   fld       xword ptr [ebp - 0x70]
00410fa3  def1                     fdivrp    st(1)
00410fa5  d9fa                     fsqrt
00410fa7  d95dfc                   fstp      dword ptr [ebp - 4]
00410faa  d945fc                   fld       dword ptr [ebp - 4]
00410fad  dbbd7cffffff             fstp      xword ptr [ebp - 0x84]
00410fb3  8b5514                   mov       edx, dword ptr [ebp + 0x14]
00410fb6  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00410fbc  d80a                     fmul      dword ptr [edx]
00410fbe  d91a                     fstp      dword ptr [edx]
00410fc0  8b5d18                   mov       ebx, dword ptr [ebp + 0x18]
00410fc3  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00410fc9  d80b                     fmul      dword ptr [ebx]
00410fcb  d91b                     fstp      dword ptr [ebx]
00410fcd  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00410fd3  d84a04                   fmul      dword ptr [edx + 4]
00410fd6  d95a04                   fstp      dword ptr [edx + 4]
00410fd9  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00410fdf  d84b04                   fmul      dword ptr [ebx + 4]
00410fe2  d95b04                   fstp      dword ptr [ebx + 4]
00410fe5  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00410feb  d84a08                   fmul      dword ptr [edx + 8]
00410fee  d95a08                   fstp      dword ptr [edx + 8]
00410ff1  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00410ff7  d84b08                   fmul      dword ptr [ebx + 8]
00410ffa  d95b08                   fstp      dword ptr [ebx + 8]
00410ffd  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00411003  d84a0c                   fmul      dword ptr [edx + 0xc]
00411006  d95a0c                   fstp      dword ptr [edx + 0xc]
00411009  dbad7cffffff             fld       xword ptr [ebp - 0x84]
0041100f  d84b0c                   fmul      dword ptr [ebx + 0xc]
00411012  d95b0c                   fstp      dword ptr [ebx + 0xc]
00411015  dbad7cffffff             fld       xword ptr [ebp - 0x84]
0041101b  d84a10                   fmul      dword ptr [edx + 0x10]
0041101e  d95a10                   fstp      dword ptr [edx + 0x10]
00411021  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00411027  d84b10                   fmul      dword ptr [ebx + 0x10]
0041102a  d95b10                   fstp      dword ptr [ebx + 0x10]
0041102d  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00411033  d84a14                   fmul      dword ptr [edx + 0x14]
00411036  d95a14                   fstp      dword ptr [edx + 0x14]
00411039  dbad7cffffff             fld       xword ptr [ebp - 0x84]
0041103f  d84b14                   fmul      dword ptr [ebx + 0x14]
00411042  d95b14                   fstp      dword ptr [ebx + 0x14]
00411045  dbad7cffffff             fld       xword ptr [ebp - 0x84]
0041104b  d84a18                   fmul      dword ptr [edx + 0x18]
0041104e  d95a18                   fstp      dword ptr [edx + 0x18]
00411051  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00411057  d84b18                   fmul      dword ptr [ebx + 0x18]
0041105a  d95b18                   fstp      dword ptr [ebx + 0x18]
0041105d  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00411063  d84a1c                   fmul      dword ptr [edx + 0x1c]
00411066  d95a1c                   fstp      dword ptr [edx + 0x1c]
00411069  dbad7cffffff             fld       xword ptr [ebp - 0x84]
0041106f  d84b1c                   fmul      dword ptr [ebx + 0x1c]
00411072  d95b1c                   fstp      dword ptr [ebx + 0x1c]
00411075  b909000000               mov       ecx, 9
0041107a  dbad7cffffff             fld       xword ptr [ebp - 0x84]
00411080  eb04                     jmp       0x411086
00411082  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
00411086  d9c0                     fld       st(0)
00411088  d84c8afc                 fmul      dword ptr [edx + ecx*4 - 4]
0041108c  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0041108f  d95c8afc                 fstp      dword ptr [edx + ecx*4 - 4]
00411093  d9c0                     fld       st(0)
00411095  d84c8bfc                 fmul      dword ptr [ebx + ecx*4 - 4]
00411099  41                       inc       ecx
0041109a  83f90c                   cmp       ecx, 0xc
0041109d  7ce3                     jl        0x411082
0041109f  d95c88f8                 fstp      dword ptr [eax + ecx*4 - 8]
004110a3  ddd8                     fstp      st(0)
004110a5  b800000000               mov       eax, 0
004110aa  5b                       pop       ebx
004110ab  8be5                     mov       esp, ebp
004110ad  5d                       pop       ebp
004110ae  c3                       ret
004110af  90                       nop
