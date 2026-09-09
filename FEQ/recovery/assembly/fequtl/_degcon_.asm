; _degcon_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x291d0
004291d0  55                       push      ebp
004291d1  8bec                     mov       ebp, esp
004291d3  53                       push      ebx
004291d4  8b5508                   mov       edx, dword ptr [ebp + 8]
004291d7  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
004291da  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
004291dd  d901                     fld       dword ptr [ecx]
004291df  d83b                     fdivr     dword ptr [ebx]
004291e1  d82d98985600             fsubr     dword ptr [0x569898] ; bits=0000803f, f32=1.0
004291e7  d9ee                     fldz
004291e9  d9c9                     fxch      st(1)
004291eb  d8158c985600             fcom      dword ptr [0x56988c] ; bits=00000000, f32=0.0
004291f1  d9c9                     fxch      st(1)
004291f3  dfe0                     fnstsw    ax
004291f5  9e                       sahf
004291f6  0f8a06000000             jp        0x429202
004291fc  7304                     jae       0x429202
004291fe  ddd9                     fstp      st(1)
00429200  eb02                     jmp       0x429204
00429202  ddd8                     fstp      st(0)
00429204  8d0d08995600             lea       ecx, [0x569908] ; bits=0000c040, f32=6.0
0042920a  d8518c                   fcom      dword ptr [ecx - 0x74]
0042920d  dfe0                     fnstsw    ax
0042920f  9e                       sahf
00429210  0f8a08000000             jp        0x42921e
00429216  7606                     jbe       0x42921e
00429218  ddd8                     fstp      st(0)
0042921a  d902                     fld       dword ptr [edx]
0042921c  eb10                     jmp       0x42922e
0042921e  d94194                   fld       dword ptr [ecx - 0x6c]
00429221  d9c0                     fld       st(0)
00429223  d822                     fsub      dword ptr [edx]
00429225  deca                     fmulp     st(2)
00429227  d9c9                     fxch      st(1)
00429229  d84980                   fmul      dword ptr [ecx - 0x80]
0042922c  dee9                     fsubp     st(1)
0042922e  5b                       pop       ebx
0042922f  8be5                     mov       esp, ebp
00429231  5d                       pop       ebp
00429232  c3                       ret
00429233  8d9b00000000             lea       ebx, [ebx]
00429239  8da42400000000           lea       esp, [esp]
