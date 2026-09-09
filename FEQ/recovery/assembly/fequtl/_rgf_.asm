; _rgf_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x72840
00472840  55                       push      ebp
00472841  8bec                     mov       ebp, esp
00472843  b840000000               mov       eax, 0x40
00472848  e8b3670700               call      0x4e9000 ; __alloca_probe
0047284d  53                       push      ebx
0047284e  56                       push      esi
0047284f  57                       push      edi
00472850  8b7508                   mov       esi, dword ptr [ebp + 8]
00472853  8b450c                   mov       eax, dword ptr [ebp + 0xc]
00472856  8b4d10                   mov       ecx, dword ptr [ebp + 0x10]
00472859  8945d8                   mov       dword ptr [ebp - 0x28], eax
0047285c  894dd4                   mov       dword ptr [ebp - 0x2c], ecx
0047285f  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00472862  c70000000000             mov       dword ptr [eax], 0
00472868  8b4d14                   mov       ecx, dword ptr [ebp + 0x14]
0047286b  d901                     fld       dword ptr [ecx]
0047286d  8b4d18                   mov       ecx, dword ptr [ebp + 0x18]
00472870  d901                     fld       dword ptr [ecx]
00472872  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00472875  d901                     fld       dword ptr [ecx]
00472877  8b5520                   mov       edx, dword ptr [ebp + 0x20]
0047287a  d902                     fld       dword ptr [edx]
0047287c  d809                     fmul      dword ptr [ecx]
0047287e  d81d14f35900             fcomp     dword ptr [0x59f314] ; bits=00000000, f32=0.0
00472884  8945d0                   mov       dword ptr [ebp - 0x30], eax
00472887  dfe0                     fnstsw    ax
00472889  9e                       sahf
0047288a  894dcc                   mov       dword ptr [ebp - 0x34], ecx
0047288d  8955c8                   mov       dword ptr [ebp - 0x38], edx
00472890  0f8a16000000             jp        0x4728ac
00472896  7614                     jbe       0x4728ac
00472898  ddd8                     fstp      st(0)
0047289a  ddd8                     fstp      st(0)
0047289c  8b45d0                   mov       eax, dword ptr [ebp - 0x30]
0047289f  ddd8                     fstp      st(0)
004728a1  c70001000000             mov       dword ptr [eax], 1
004728a7  e9c3010000               jmp       0x472a6f
004728ac  bb00000000               mov       ebx, 0
004728b1  8b45c8                   mov       eax, dword ptr [ebp - 0x38]
004728b4  8945c4                   mov       dword ptr [ebp - 0x3c], eax
004728b7  8b45cc                   mov       eax, dword ptr [ebp - 0x34]
004728ba  8945c0                   mov       dword ptr [ebp - 0x40], eax
004728bd  db7ddc                   fstp      xword ptr [ebp - 0x24]
004728c0  db7de8                   fstp      xword ptr [ebp - 0x18]
004728c3  db7df4                   fstp      xword ptr [ebp - 0xc]
004728c6  8b45c4                   mov       eax, dword ptr [ebp - 0x3c]
004728c9  db6df4                   fld       xword ptr [ebp - 0xc]
004728cc  d808                     fmul      dword ptr [eax]
004728ce  8b4dc0                   mov       ecx, dword ptr [ebp - 0x40]
004728d1  db6de8                   fld       xword ptr [ebp - 0x18]
004728d4  d809                     fmul      dword ptr [ecx]
004728d6  dee9                     fsubp     st(1)
004728d8  8b5520                   mov       edx, dword ptr [ebp + 0x20]
004728db  8b7d1c                   mov       edi, dword ptr [ebp + 0x1c]
004728de  d907                     fld       dword ptr [edi]
004728e0  d82a                     fsubr     dword ptr [edx]
004728e2  def9                     fdivp     st(1)
004728e4  8b5524                   mov       edx, dword ptr [ebp + 0x24]
004728e7  d91a                     fstp      dword ptr [edx]
004728e9  8d12                     lea       edx, [edx]
004728eb  52                       push      edx
004728ec  8b55d4                   mov       edx, dword ptr [ebp - 0x2c]
004728ef  ffd2                     call      edx
004728f1  83c404                   add       esp, 4
004728f4  d81520f35900             fcom      dword ptr [0x59f320] ; bits=cded47f1, f32=-9.900000073412052e+29
004728fa  db6df4                   fld       xword ptr [ebp - 0xc]
004728fd  db6de8                   fld       xword ptr [ebp - 0x18]
00472900  db6ddc                   fld       xword ptr [ebp - 0x24]
00472903  dfe0                     fnstsw    ax
00472905  9e                       sahf
00472906  0f8a18000000             jp        0x472924
0047290c  7316                     jae       0x472924
0047290e  ddd8                     fstp      st(0)
00472910  ddd8                     fstp      st(0)
00472912  ddd8                     fstp      st(0)
00472914  ddd8                     fstp      st(0)
00472916  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00472919  c70003000000             mov       dword ptr [eax], 3
0047291f  e94b010000               jmp       0x472a6f
00472924  d9ee                     fldz
00472926  d9cc                     fxch      st(4)
00472928  dde4                     fucom     st(4)
0047292a  dddc                     fstp      st(4)
0047292c  dfe0                     fnstsw    ax
0047292e  9e                       sahf
0047292f  0f8a1a000000             jp        0x47294f
00472935  7518                     jne       0x47294f
00472937  ddd8                     fstp      st(0)
00472939  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0047293c  d9c9                     fxch      st(1)
0047293e  d918                     fstp      dword ptr [eax]
00472940  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00472943  d918                     fstp      dword ptr [eax]
00472945  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00472948  d918                     fstp      dword ptr [eax]
0047294a  e920010000               jmp       0x472a6f
0047294f  d9c3                     fld       st(3)
00472951  8b45d8                   mov       eax, dword ptr [ebp - 0x28]
00472954  d9e1                     fabs
00472956  d818                     fcomp     dword ptr [eax]
00472958  dfe0                     fnstsw    ax
0047295a  9e                       sahf
0047295b  0f8a1a000000             jp        0x47297b
00472961  7318                     jae       0x47297b
00472963  ddd8                     fstp      st(0)
00472965  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00472968  d9c9                     fxch      st(1)
0047296a  d918                     fstp      dword ptr [eax]
0047296c  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0047296f  d918                     fstp      dword ptr [eax]
00472971  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00472974  d918                     fstp      dword ptr [eax]
00472976  e9f4000000               jmp       0x472a6f
0047297b  d9c2                     fld       st(2)
0047297d  d9e1                     fabs
0047297f  d9c2                     fld       st(2)
00472981  d9e1                     fabs
00472983  dec1                     faddp     st(1)
00472985  d9c3                     fld       st(3)
00472987  d8e3                     fsub      st(3)
00472989  d9e1                     fabs
0047298b  def1                     fdivrp    st(1)
0047298d  d81e                     fcomp     dword ptr [esi]
0047298f  dfe0                     fnstsw    ax
00472991  9e                       sahf
00472992  0f8a1a000000             jp        0x4729b2
00472998  7318                     jae       0x4729b2
0047299a  ddd8                     fstp      st(0)
0047299c  8b4514                   mov       eax, dword ptr [ebp + 0x14]
0047299f  d9c9                     fxch      st(1)
004729a1  d918                     fstp      dword ptr [eax]
004729a3  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004729a6  d918                     fstp      dword ptr [eax]
004729a8  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004729ab  d918                     fstp      dword ptr [eax]
004729ad  e9bd000000               jmp       0x472a6f
004729b2  43                       inc       ebx
004729b3  83fb64                   cmp       ebx, 0x64
004729b6  7e21                     jle       0x4729d9
004729b8  ddd8                     fstp      st(0)
004729ba  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004729bd  d9c9                     fxch      st(1)
004729bf  d918                     fstp      dword ptr [eax]
004729c1  8b4518                   mov       eax, dword ptr [ebp + 0x18]
004729c4  d918                     fstp      dword ptr [eax]
004729c6  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
004729c9  d918                     fstp      dword ptr [eax]
004729cb  8b4528                   mov       eax, dword ptr [ebp + 0x28]
004729ce  c70002000000             mov       dword ptr [eax], 2
004729d4  e996000000               jmp       0x472a6f
004729d9  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
004729dc  d901                     fld       dword ptr [ecx]
004729de  d9c4                     fld       st(4)
004729e0  d809                     fmul      dword ptr [ecx]
004729e2  d9ee                     fldz
004729e4  d9c9                     fxch      st(1)
004729e6  d81d14f35900             fcomp     dword ptr [0x59f314] ; bits=00000000, f32=0.0
004729ec  d9c9                     fxch      st(1)
004729ee  dfe0                     fnstsw    ax
004729f0  9e                       sahf
004729f1  0f8a3a000000             jp        0x472a31
004729f7  7738                     ja        0x472a31
004729f9  dddb                     fstp      st(3)
004729fb  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004729fe  d900                     fld       dword ptr [eax]
00472a00  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00472a03  d9cd                     fxch      st(5)
00472a05  d910                     fst       dword ptr [eax]
00472a07  dcca                     fmul      st(2), st(0)
00472a09  d9ca                     fxch      st(2)
00472a0b  ded9                     fcompp
00472a0d  d9cb                     fxch      st(3)
00472a0f  d9c9                     fxch      st(1)
00472a11  dfe0                     fnstsw    ax
00472a13  9e                       sahf
00472a14  0f8a0c000000             jp        0x472a26
00472a1a  760a                     jbe       0x472a26
00472a1c  d80d1cf35900             fmul      dword ptr [0x59f31c] ; bits=6666663f, f32=0.8999999761581421
00472a22  d919                     fstp      dword ptr [ecx]
00472a24  eb02                     jmp       0x472a28
00472a26  ddd8                     fstp      st(0)
00472a28  d9c9                     fxch      st(1)
00472a2a  d9ca                     fxch      st(2)
00472a2c  e98cfeffff               jmp       0x4728bd
00472a31  ddd8                     fstp      st(0)
00472a33  dddb                     fstp      st(3)
00472a35  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00472a38  d900                     fld       dword ptr [eax]
00472a3a  89c8                     mov       eax, ecx
00472a3c  d9cc                     fxch      st(4)
00472a3e  d910                     fst       dword ptr [eax]
00472a40  dcc9                     fmul      st(1), st(0)
00472a42  d9c9                     fxch      st(1)
00472a44  d8db                     fcomp     st(3)
00472a46  ddda                     fstp      st(2)
00472a48  d9c9                     fxch      st(1)
00472a4a  d9ca                     fxch      st(2)
00472a4c  d9c9                     fxch      st(1)
00472a4e  dfe0                     fnstsw    ax
00472a50  9e                       sahf
00472a51  0f8a0f000000             jp        0x472a66
00472a57  760d                     jbe       0x472a66
00472a59  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00472a5c  d9051cf35900             fld       dword ptr [0x59f31c] ; bits=6666663f, f32=0.8999999761581421
00472a62  d808                     fmul      dword ptr [eax]
00472a64  d918                     fstp      dword ptr [eax]
00472a66  d9c9                     fxch      st(1)
00472a68  d9ca                     fxch      st(2)
00472a6a  e94efeffff               jmp       0x4728bd
00472a6f  b800000000               mov       eax, 0
00472a74  5f                       pop       edi
00472a75  5e                       pop       esi
00472a76  5b                       pop       ebx
00472a77  8be5                     mov       esp, ebp
00472a79  5d                       pop       ebp
00472a7a  c3                       ret
00472a7b  0500000000               add       eax, 0
