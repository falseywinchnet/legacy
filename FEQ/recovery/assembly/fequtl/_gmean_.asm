; _gmean_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x33e40
00433e40  55                       push      ebp
00433e41  8bec                     mov       ebp, esp
00433e43  b820000000               mov       eax, 0x20
00433e48  e8b3510b00               call      0x4e9000 ; __alloca_probe
00433e4d  53                       push      ebx
00433e4e  8b4d08                   mov       ecx, dword ptr [ebp + 8]
00433e51  8b550c                   mov       edx, dword ptr [ebp + 0xc]
00433e54  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
00433e57  d903                     fld       dword ptr [ebx]
00433e59  d9c0                     fld       st(0)
00433e5b  d9e1                     fabs
00433e5d  8d1de0f55600             lea       ebx, [0x56f5e0] ; bits=00000042, f32=32.0
00433e63  d85b90                   fcomp     dword ptr [ebx - 0x70]
00433e66  dfe0                     fnstsw    ax
00433e68  9e                       sahf
00433e69  0f8a0a000000             jp        0x433e79
00433e6f  7308                     jae       0x433e79
00433e71  ddd8                     fstp      st(0)
00433e73  d902                     fld       dword ptr [edx]
00433e75  d809                     fmul      dword ptr [ecx]
00433e77  eb54                     jmp       0x433ecd
00433e79  d901                     fld       dword ptr [ecx]
00433e7b  d902                     fld       dword ptr [edx]
00433e7d  dd5de0                   fstp      qword ptr [ebp - 0x20]
00433e80  d9c9                     fxch      st(1)
00433e82  dd5ba0                   fstp      qword ptr [ebx - 0x60]
00433e85  dc75e0                   fdiv      qword ptr [ebp - 0x20]
00433e88  dd5b98                   fstp      qword ptr [ebx - 0x68]
00433e8b  8d43a0                   lea       eax, [ebx - 0x60]
00433e8e  50                       push      eax
00433e8f  8d4398                   lea       eax, [ebx - 0x68]
00433e92  50                       push      eax
00433e93  e8e8d20600               call      0x4a1180 ; _g_adxd
00433e98  83c408                   add       esp, 8
00433e9b  dc4b88                   fmul      qword ptr [ebx - 0x78]
00433e9e  dc4388                   fadd      qword ptr [ebx - 0x78]
00433ea1  dd43a0                   fld       qword ptr [ebx - 0x60]
00433ea4  dc3d60f55600             fdivr     qword ptr [0x56f560] ; bits=000000000000f03f, f64=1.0
00433eaa  d9c9                     fxch      st(1)
00433eac  dd5df8                   fstp      qword ptr [ebp - 8]
00433eaf  dd5df0                   fstp      qword ptr [ebp - 0x10]
00433eb2  8d45f0                   lea       eax, [ebp - 0x10]
00433eb5  50                       push      eax
00433eb6  8d45f8                   lea       eax, [ebp - 8]
00433eb9  50                       push      eax
00433eba  e8c1d20600               call      0x4a1180 ; _g_adxd
00433ebf  83c408                   add       esp, 8
00433ec2  dc4de0                   fmul      qword ptr [ebp - 0x20]
00433ec5  d8c8                     fmul      st(0)
00433ec7  d95dec                   fstp      dword ptr [ebp - 0x14]
00433eca  d945ec                   fld       dword ptr [ebp - 0x14]
00433ecd  5b                       pop       ebx
00433ece  8be5                     mov       esp, ebp
00433ed0  5d                       pop       ebp
00433ed1  c3                       ret
00433ed2  8da42400000000           lea       esp, [esp]
00433ed9  8da42400000000           lea       esp, [esp]
