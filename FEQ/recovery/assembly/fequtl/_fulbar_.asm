; _fulbar_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x25960
00425960  55                       push      ebp
00425961  8bec                     mov       ebp, esp
00425963  b84c000000               mov       eax, 0x4c
00425968  e893360c00               call      0x4e9000 ; __alloca_probe
0042596d  53                       push      ebx
0042596e  56                       push      esi
0042596f  8b550c                   mov       edx, dword ptr [ebp + 0xc]
00425972  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
00425975  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00425978  8b4d30                   mov       ecx, dword ptr [ebp + 0x30]
0042597b  d901                     fld       dword ptr [ecx]
0042597d  d828                     fsubr     dword ptr [eax]
0042597f  d80d34bcf400             fmul      dword ptr [0xf4bc34]
00425985  db7db4                   fstp      xword ptr [ebp - 0x4c]
00425988  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0042598b  d900                     fld       dword ptr [eax]
0042598d  db7dc0                   fstp      xword ptr [ebp - 0x40]
00425990  db6dc0                   fld       xword ptr [ebp - 0x40]
00425993  d808                     fmul      dword ptr [eax]
00425995  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
00425998  d900                     fld       dword ptr [eax]
0042599a  8b4d24                   mov       ecx, dword ptr [ebp + 0x24]
0042599d  d901                     fld       dword ptr [ecx]
0042599f  d838                     fdivr     dword ptr [eax]
004259a1  d8c8                     fmul      st(0)
004259a3  d825c8805600             fsub      dword ptr [0x5680c8] ; bits=0000803f, f32=1.0
004259a9  d903                     fld       dword ptr [ebx]
004259ab  d905ccf2f200             fld       dword ptr [0xf2f2cc]
004259b1  d9c0                     fld       st(0)
004259b3  d82b                     fsubr     dword ptr [ebx]
004259b5  d902                     fld       dword ptr [edx]
004259b7  d838                     fdivr     dword ptr [eax]
004259b9  d8c8                     fmul      st(0)
004259bb  dec9                     fmulp     st(1)
004259bd  deeb                     fsubp     st(3)
004259bf  d9c3                     fld       st(3)
004259c1  d808                     fmul      dword ptr [eax]
004259c3  d80d34bcf400             fmul      dword ptr [0xf4bc34]
004259c9  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004259cc  8b4d20                   mov       ecx, dword ptr [ebp + 0x20]
004259cf  d901                     fld       dword ptr [ecx]
004259d1  d808                     fmul      dword ptr [eax]
004259d3  d83dc8f2f200             fdivr     dword ptr [0xf2f2c8]
004259d9  dc05e0b6e900             fadd      qword ptr [0xe9b6e0] ; _culcom_
004259df  dec9                     fmulp     st(1)
004259e1  dec3                     faddp     st(3)
004259e3  d9cc                     fxch      st(4)
004259e5  deca                     fmulp     st(2)
004259e7  d9c9                     fxch      st(1)
004259e9  dc05b8805600             fadd      qword ptr [0x5680b8] ; bits=000000000000f03f, f64=1.0
004259ef  d95dfc                   fstp      dword ptr [ebp - 4]
004259f2  d945fc                   fld       dword ptr [ebp - 4]
004259f5  db6dc0                   fld       xword ptr [ebp - 0x40]
004259f8  dccb                     fmul      st(3), st(0)
004259fa  db6db4                   fld       xword ptr [ebp - 0x4c]
004259fd  d875fc                   fdiv      dword ptr [ebp - 4]
00425a00  d9fa                     fsqrt
00425a02  d95dfc                   fstp      dword ptr [ebp - 4]
00425a05  d9cb                     fxch      st(3)
00425a07  d84dfc                   fmul      dword ptr [ebp - 4]
00425a0a  8b4534                   mov       eax, dword ptr [ebp + 0x34]
00425a0d  d918                     fstp      dword ptr [eax]
00425a0f  d9052cbbf400             fld       dword ptr [0xf4bb2c]
00425a15  d81dc0805600             fcomp     dword ptr [0x5680c0] ; bits=00000000, f32=0.0
00425a1b  d9ca                     fxch      st(2)
00425a1d  db7df0                   fstp      xword ptr [ebp - 0x10]
00425a20  db6db4                   fld       xword ptr [ebp - 0x4c]
00425a23  db7de4                   fstp      xword ptr [ebp - 0x1c]
00425a26  d9ca                     fxch      st(2)
00425a28  db7dd8                   fstp      xword ptr [ebp - 0x28]
00425a2b  d9c9                     fxch      st(1)
00425a2d  db7dcc                   fstp      xword ptr [ebp - 0x34]
00425a30  dfe0                     fnstsw    ax
00425a32  9e                       sahf
00425a33  0f8aad000000             jp        0x425ae6
00425a39  0f86a7000000             jbe       0x425ae6
00425a3f  db6dcc                   fld       xword ptr [ebp - 0x34]
00425a42  db6dd8                   fld       xword ptr [ebp - 0x28]
00425a45  d9c9                     fxch      st(1)
00425a47  d9ca                     fxch      st(2)
00425a49  d9ca                     fxch      st(2)
00425a4b  db7dc0                   fstp      xword ptr [ebp - 0x40]
00425a4e  db6dc0                   fld       xword ptr [ebp - 0x40]
00425a51  d8e1                     fsub      st(1)
00425a53  8b4d34                   mov       ecx, dword ptr [ebp + 0x34]
00425a56  d901                     fld       dword ptr [ecx]
00425a58  d9052cbbf400             fld       dword ptr [0xf4bb2c]
00425a5e  d9c0                     fld       st(0)
00425a60  d801                     fadd      dword ptr [ecx]
00425a62  d801                     fadd      dword ptr [ecx]
00425a64  decb                     fmulp     st(3)
00425a66  d902                     fld       dword ptr [edx]
00425a68  d80a                     fmul      dword ptr [edx]
00425a6a  d80d34bcf400             fmul      dword ptr [0xf4bc34]
00425a70  defb                     fdivp     st(3)
00425a72  d905c8f2f200             fld       dword ptr [0xf2f2c8]
00425a78  d809                     fmul      dword ptr [ecx]
00425a7a  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00425a7d  8b7520                   mov       esi, dword ptr [ebp + 0x20]
00425a80  d906                     fld       dword ptr [esi]
00425a82  d808                     fmul      dword ptr [eax]
00425a84  def9                     fdivp     st(1)
00425a86  deeb                     fsubp     st(3)
00425a88  deca                     fmulp     st(2)
00425a8a  db6de4                   fld       xword ptr [ebp - 0x1c]
00425a8d  dec2                     faddp     st(2)
00425a8f  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00425a92  8b752c                   mov       esi, dword ptr [ebp + 0x2c]
00425a95  d906                     fld       dword ptr [esi]
00425a97  d808                     fmul      dword ptr [eax]
00425a99  d9ca                     fxch      st(2)
00425a9b  d8f4                     fdiv      st(4)
00425a9d  d9fa                     fsqrt
00425a9f  d95dfc                   fstp      dword ptr [ebp - 4]
00425aa2  d9c9                     fxch      st(1)
00425aa4  d84dfc                   fmul      dword ptr [ebp - 4]
00425aa7  d9c0                     fld       st(0)
00425aa9  d8e2                     fsub      st(2)
00425aab  d9e1                     fabs
00425aad  def2                     fdivrp    st(2)
00425aaf  d9c9                     fxch      st(1)
00425ab1  d81d68f70e04             fcomp     dword ptr [0x40ef768]
00425ab7  db6dc0                   fld       xword ptr [ebp - 0x40]
00425aba  d9c9                     fxch      st(1)
00425abc  d9cb                     fxch      st(3)
00425abe  d9c9                     fxch      st(1)
00425ac0  d9ca                     fxch      st(2)
00425ac2  d9c9                     fxch      st(1)
00425ac4  dfe0                     fnstsw    ax
00425ac6  9e                       sahf
00425ac7  0f8a0f000000             jp        0x425adc
00425acd  760d                     jbe       0x425adc
00425acf  d9cb                     fxch      st(3)
00425ad1  d919                     fstp      dword ptr [ecx]
00425ad3  d9c9                     fxch      st(1)
00425ad5  d9ca                     fxch      st(2)
00425ad7  e96dffffff               jmp       0x425a49
00425adc  ddd8                     fstp      st(0)
00425ade  ddd8                     fstp      st(0)
00425ae0  ddd8                     fstp      st(0)
00425ae2  ddd8                     fstp      st(0)
00425ae4  eb02                     jmp       0x425ae8
00425ae6  ddd8                     fstp      st(0)
00425ae8  db6df0                   fld       xword ptr [ebp - 0x10]
00425aeb  db6df0                   fld       xword ptr [ebp - 0x10]
00425aee  dec9                     fmulp     st(1)
00425af0  d83dc8805600             fdivr     dword ptr [0x5680c8] ; bits=0000803f, f32=1.0
00425af6  d825c8805600             fsub      dword ptr [0x5680c8] ; bits=0000803f, f32=1.0
00425afc  d9fa                     fsqrt
00425afe  d95dfc                   fstp      dword ptr [ebp - 4]
00425b01  d945fc                   fld       dword ptr [ebp - 4]
00425b04  d805c8805600             fadd      dword ptr [0x5680c8] ; bits=0000803f, f32=1.0
00425b0a  d83dc8805600             fdivr     dword ptr [0x5680c8] ; bits=0000803f, f32=1.0
00425b10  8b4534                   mov       eax, dword ptr [ebp + 0x34]
00425b13  d9052cbbf400             fld       dword ptr [0xf4bb2c]
00425b19  d800                     fadd      dword ptr [eax]
00425b1b  d832                     fdiv      dword ptr [edx]
00425b1d  d8c8                     fmul      st(0)
00425b1f  d80b                     fmul      dword ptr [ebx]
00425b21  d83534bcf400             fdiv      dword ptr [0xf4bc34]
00425b27  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
00425b2a  d801                     fadd      dword ptr [ecx]
00425b2c  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00425b2f  d9c9                     fxch      st(1)
00425b31  d809                     fmul      dword ptr [ecx]
00425b33  d838                     fdivr     dword ptr [eax]
00425b35  d8c8                     fmul      st(0)
00425b37  d83534bcf400             fdiv      dword ptr [0xf4bc34]
00425b3d  dee9                     fsubp     st(1)
00425b3f  8b4538                   mov       eax, dword ptr [ebp + 0x38]
00425b42  d918                     fstp      dword ptr [eax]
00425b44  b800000000               mov       eax, 0
00425b49  5e                       pop       esi
00425b4a  5b                       pop       ebx
00425b4b  8be5                     mov       esp, ebp
00425b4d  5d                       pop       ebp
00425b4e  c3                       ret
00425b4f  90                       nop
