; _frfchn_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x6de0
00406de0  55                       push      ebp
00406de1  8bec                     mov       ebp, esp
00406de3  b81c000000               mov       eax, 0x1c
00406de8  e813220e00               call      0x4e9000 ; __alloca_probe
00406ded  53                       push      ebx
00406dee  56                       push      esi
00406def  8b7508                   mov       esi, dword ptr [ebp + 8]
00406df2  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
00406df5  8b5d10                   mov       ebx, dword ptr [ebp + 0x10]
00406df8  d903                     fld       dword ptr [ebx]
00406dfa  d801                     fadd      dword ptr [ecx]
00406dfc  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00406dff  d9c0                     fld       st(0)
00406e01  d820                     fsub      dword ptr [eax]
00406e03  d91d94f70e04             fstp      dword ptr [0x40ef794]
00406e09  d90590f70e04             fld       dword ptr [0x40ef790]
00406e0f  d81dd83b5500             fcomp     dword ptr [0x553bd8] ; bits=00000000, f32=0.0
00406e15  dfe0                     fnstsw    ax
00406e17  9e                       sahf
00406e18  0f8a7f010000             jp        0x406f9d
00406e1e  0f8679010000             jbe       0x406f9d
00406e24  db7de4                   fstp      xword ptr [ebp - 0x1c]
00406e27  8d1d483c5500             lea       ebx, [0x553c48] ; bits=00000000, f32=0.0
00406e2d  8d4360                   lea       eax, [ebx + 0x60]
00406e30  50                       push      eax
00406e31  8d4358                   lea       eax, [ebx + 0x58]
00406e34  50                       push      eax
00406e35  8d4364                   lea       eax, [ebx + 0x64]
00406e38  50                       push      eax
00406e39  8d435c                   lea       eax, [ebx + 0x5c]
00406e3c  50                       push      eax
00406e3d  8d4368                   lea       eax, [ebx + 0x68]
00406e40  50                       push      eax
00406e41  8d4374                   lea       eax, [ebx + 0x74]
00406e44  50                       push      eax
00406e45  8d4370                   lea       eax, [ebx + 0x70]
00406e48  50                       push      eax
00406e49  8d436c                   lea       eax, [ebx + 0x6c]
00406e4c  50                       push      eax
00406e4d  8d4378                   lea       eax, [ebx + 0x78]
00406e50  50                       push      eax
00406e51  8d4354                   lea       eax, [ebx + 0x54]
00406e54  50                       push      eax
00406e55  6894f70e04               push      0x40ef794
00406e5a  6880f70e04               push      0x40ef780 ; _chncom_
00406e5f  e83c470400               call      0x44b5a0 ; _xlktal_
00406e64  83c430                   add       esp, 0x30
00406e67  d90590f70e04             fld       dword ptr [0x40ef790]
00406e6d  d9fa                     fsqrt
00406e6f  d95dfc                   fstp      dword ptr [ebp - 4]
00406e72  d94374                   fld       dword ptr [ebx + 0x74]
00406e75  d84dfc                   fmul      dword ptr [ebp - 4]
00406e78  d91d88f70e04             fstp      dword ptr [0x40ef788]
00406e7e  8b0594f70e04             mov       eax, dword ptr [0x40ef794]
00406e84  8905c83c5500             mov       dword ptr [0x553cc8], eax ; bits=00000000, f32=0.0
00406e8a  68c83c5500               push      0x553cc8
00406e8f  6888f70e04               push      0x40ef788
00406e94  6880f70e04               push      0x40ef780 ; _chncom_
00406e99  8d06                     lea       eax, [esi]
00406e9b  50                       push      eax
00406e9c  e88f1c0200               call      0x428b30 ; _fndcde_
00406ea1  83c410                   add       esp, 0x10
00406ea4  d905c83c5500             fld       dword ptr [0x553cc8] ; bits=00000000, f32=0.0
00406eaa  d90594f70e04             fld       dword ptr [0x40ef794]
00406eb0  d9c9                     fxch      st(1)
00406eb2  d81d94f70e04             fcomp     dword ptr [0x40ef794]
00406eb8  db6de4                   fld       xword ptr [ebp - 0x1c]
00406ebb  d9c9                     fxch      st(1)
00406ebd  dfe0                     fnstsw    ax
00406ebf  9e                       sahf
00406ec0  0f8a2b000000             jp        0x406ef1
00406ec6  7629                     jbe       0x406ef1
00406ec8  ddd8                     fstp      st(0)
00406eca  ddd8                     fstp      st(0)
00406ecc  8b06                     mov       eax, dword ptr [esi]
00406ece  8d4b10                   lea       ecx, [ebx + 0x10]
00406ed1  8945f8                   mov       dword ptr [ebp - 8], eax
00406ed4  8d45f8                   lea       eax, [ebp - 8]
00406ed7  894108                   mov       dword ptr [ecx + 8], eax
00406eda  51                       push      ecx
00406edb  e810b70900               call      0x4a25f0 ; _jwe_isfm
00406ee0  83c404                   add       esp, 4
00406ee3  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00406ee6  c70001000000             mov       dword ptr [eax], 1
00406eec  e947020000               jmp       0x407138
00406ef1  d905a8f70e04             fld       dword ptr [0x40ef7a8]
00406ef7  d82de03b5500             fsubr     dword ptr [0x553be0] ; bits=0000803f, f32=1.0
00406efd  d8c9                     fmul      st(1)
00406eff  d9c9                     fxch      st(1)
00406f01  d825a4f70e04             fsub      dword ptr [0x40ef7a4]
00406f07  d8d1                     fcom      st(1)
00406f09  d9ca                     fxch      st(2)
00406f0b  d9c9                     fxch      st(1)
00406f0d  dfe0                     fnstsw    ax
00406f0f  66a90041                 test      ax, 0x4100
00406f13  7404                     je        0x406f19
00406f15  ddda                     fstp      st(2)
00406f17  eb02                     jmp       0x406f1b
00406f19  ddd8                     fstp      st(0)
00406f1b  db7de4                   fstp      xword ptr [ebp - 0x1c]
00406f1e  d91dcc3c5500             fstp      dword ptr [0x553ccc] ; bits=00000000, f32=0.0
00406f24  8b0588f70e04             mov       eax, dword ptr [0x40ef788]
00406f2a  890584f70e04             mov       dword ptr [0x40ef784], eax
00406f30  8d1d483c5500             lea       ebx, [0x553c48] ; bits=00000000, f32=0.0
00406f36  8d4330                   lea       eax, [ebx + 0x30]
00406f39  50                       push      eax
00406f3a  689cf70e04               push      0x40ef79c
00406f3f  68e0664000               push      0x4066e0 ; _fdxdy_
00406f44  68c83c5500               push      0x553cc8
00406f49  68cc3c5500               push      0x553ccc
00406f4e  e8bd160600               call      0x468610 ; _qfun_
00406f53  83c414                   add       esp, 0x14
00406f56  d9058cf70e04             fld       dword ptr [0x40ef78c]
00406f5c  dd4330                   fld       qword ptr [ebx + 0x30]
00406f5f  ded9                     fcompp
00406f61  db6de4                   fld       xword ptr [ebp - 0x1c]
00406f64  dfe0                     fnstsw    ax
00406f66  9e                       sahf
00406f67  0f8a3c000000             jp        0x406fa9
00406f6d  733a                     jae       0x406fa9
00406f6f  8b05c83c5500             mov       eax, dword ptr [0x553cc8] ; bits=00000000, f32=0.0
00406f75  890598f70e04             mov       dword ptr [0x40ef798], eax
00406f7b  8b4518                   mov       eax, dword ptr [ebp + 0x18]
00406f7e  d905c83c5500             fld       dword ptr [0x553cc8] ; bits=00000000, f32=0.0
00406f84  d800                     fadd      dword ptr [eax]
00406f86  dee9                     fsubp     st(1)
00406f88  8b4528                   mov       eax, dword ptr [ebp + 0x28]
00406f8b  d918                     fstp      dword ptr [eax]
00406f8d  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00406f90  8b0d84f70e04             mov       ecx, dword ptr [0x40ef784]
00406f96  8908                     mov       dword ptr [eax], ecx
00406f98  e99b010000               jmp       0x407138
00406f9d  8b056cf70e04             mov       eax, dword ptr [0x40ef76c]
00406fa3  8905c83c5500             mov       dword ptr [0x553cc8], eax ; bits=00000000, f32=0.0
00406fa9  8b0594f70e04             mov       eax, dword ptr [0x40ef794]
00406faf  8d0d483c5500             lea       ecx, [0x553c48] ; bits=00000000, f32=0.0
00406fb5  89417c                   mov       dword ptr [ecx + 0x7c], eax
00406fb8  d9058cf70e04             fld       dword ptr [0x40ef78c]
00406fbe  d9c0                     fld       st(0)
00406fc0  d9e0                     fchs
00406fc2  dd5938                   fstp      qword ptr [ecx + 0x38]
00406fc5  dc4980                   fmul      qword ptr [ecx - 0x80]
00406fc8  dd5940                   fstp      qword ptr [ecx + 0x40]
00406fcb  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
00406fce  d90594f70e04             fld       dword ptr [0x40ef794]
00406fd4  d808                     fmul      dword ptr [eax]
00406fd6  dd5948                   fstp      qword ptr [ecx + 0x48]
00406fd9  d905c83c5500             fld       dword ptr [0x553cc8] ; bits=00000000, f32=0.0
00406fdf  d9c0                     fld       st(0)
00406fe1  dd4148                   fld       qword ptr [ecx + 0x48]
00406fe4  ded9                     fcompp
00406fe6  dfe0                     fnstsw    ax
00406fe8  9e                       sahf
00406fe9  0f8a14000000             jp        0x407003
00406fef  7312                     jae       0x407003
00406ff1  d9417c                   fld       dword ptr [ecx + 0x7c]
00406ff4  d8499c                   fmul      dword ptr [ecx - 0x64]
00406ff7  d9c9                     fxch      st(1)
00406ff9  d849a0                   fmul      dword ptr [ecx - 0x60]
00406ffc  dec1                     faddp     st(1)
00406ffe  dd5948                   fstp      qword ptr [ecx + 0x48]
00407001  eb31                     jmp       0x407034
00407003  89c8                     mov       eax, ecx
00407005  d9407c                   fld       dword ptr [eax + 0x7c]
00407008  89c8                     mov       eax, ecx
0040700a  dd4048                   fld       qword ptr [eax + 0x48]
0040700d  ded9                     fcompp
0040700f  dfe0                     fnstsw    ax
00407011  9e                       sahf
00407012  0f8a1a000000             jp        0x407032
00407018  7618                     jbe       0x407032
0040701a  89c8                     mov       eax, ecx
0040701c  d8489c                   fmul      dword ptr [eax - 0x64]
0040701f  89c8                     mov       eax, ecx
00407021  89ca                     mov       edx, ecx
00407023  d9427c                   fld       dword ptr [edx + 0x7c]
00407026  d848a0                   fmul      dword ptr [eax - 0x60]
00407029  dec1                     faddp     st(1)
0040702b  89c8                     mov       eax, ecx
0040702d  dd5848                   fstp      qword ptr [eax + 0x48]
00407030  eb02                     jmp       0x407034
00407032  ddd8                     fstp      st(0)
00407034  db7de4                   fstp      xword ptr [ebp - 0x1c]
00407037  d9056cf70e04             fld       dword ptr [0x40ef76c]
0040703d  dd5df0                   fstp      qword ptr [ebp - 0x10]
00407040  8d1d483c5500             lea       ebx, [0x553c48] ; bits=00000000, f32=0.0
00407046  8d4350                   lea       eax, [ebx + 0x50]
00407049  50                       push      eax
0040704a  8d4348                   lea       eax, [ebx + 0x48]
0040704d  50                       push      eax
0040704e  8d4340                   lea       eax, [ebx + 0x40]
00407051  50                       push      eax
00407052  8d4338                   lea       eax, [ebx + 0x38]
00407055  50                       push      eax
00407056  68c83c5500               push      0x553cc8
0040705b  8d437c                   lea       eax, [ebx + 0x7c]
0040705e  50                       push      eax
0040705f  6820664000               push      0x406620 ; _ffpres_
00407064  6860f70e04               push      0x40ef760 ; _epscom_
00407069  8d45f0                   lea       eax, [ebp - 0x10]
0040706c  50                       push      eax
0040706d  e87ebc0600               call      0x472cf0 ; _dblrgf_
00407072  db6de4                   fld       xword ptr [ebp - 0x1c]
00407075  83c424                   add       esp, 0x24
00407078  837b5000                 cmp       dword ptr [ebx + 0x50], 0
0040707c  7e78                     jle       0x4070f6
0040707e  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00407081  c70001000000             mov       dword ptr [eax], 1
00407087  837b5001                 cmp       dword ptr [ebx + 0x50], 1
0040708b  7521                     jne       0x4070ae
0040708d  db7de4                   fstp      xword ptr [ebp - 0x1c]
00407090  8b06                     mov       eax, dword ptr [esi]
00407092  89d9                     mov       ecx, ebx
00407094  8d49f0                   lea       ecx, [ecx - 0x10]
00407097  8945f8                   mov       dword ptr [ebp - 8], eax
0040709a  8d45f8                   lea       eax, [ebp - 8]
0040709d  894108                   mov       dword ptr [ecx + 8], eax
004070a0  51                       push      ecx
004070a1  e84ab50900               call      0x4a25f0 ; _jwe_isfm
004070a6  db6de4                   fld       xword ptr [ebp - 0x1c]
004070a9  83c404                   add       esp, 4
004070ac  eb48                     jmp       0x4070f6
004070ae  89d8                     mov       eax, ebx
004070b0  83785002                 cmp       dword ptr [eax + 0x50], 2
004070b4  7521                     jne       0x4070d7
004070b6  db7de4                   fstp      xword ptr [ebp - 0x1c]
004070b9  8b06                     mov       eax, dword ptr [esi]
004070bb  89d9                     mov       ecx, ebx
004070bd  8d49d0                   lea       ecx, [ecx - 0x30]
004070c0  8945f8                   mov       dword ptr [ebp - 8], eax
004070c3  8d45f8                   lea       eax, [ebp - 8]
004070c6  894108                   mov       dword ptr [ecx + 8], eax
004070c9  51                       push      ecx
004070ca  e821b50900               call      0x4a25f0 ; _jwe_isfm
004070cf  db6de4                   fld       xword ptr [ebp - 0x1c]
004070d2  83c404                   add       esp, 4
004070d5  eb1f                     jmp       0x4070f6
004070d7  db7de4                   fstp      xword ptr [ebp - 0x1c]
004070da  8b06                     mov       eax, dword ptr [esi]
004070dc  89d9                     mov       ecx, ebx
004070de  8d49b0                   lea       ecx, [ecx - 0x50]
004070e1  8945f8                   mov       dword ptr [ebp - 8], eax
004070e4  8d45f8                   lea       eax, [ebp - 8]
004070e7  894108                   mov       dword ptr [ecx + 8], eax
004070ea  51                       push      ecx
004070eb  e800b50900               call      0x4a25f0 ; _jwe_isfm
004070f0  db6de4                   fld       xword ptr [ebp - 0x1c]
004070f3  83c404                   add       esp, 4
004070f6  d90594f70e04             fld       dword ptr [0x40ef794]
004070fc  dd05903c5500             fld       qword ptr [0x553c90] ; bits=0000000000000000, f64=0.0
00407102  d9c9                     fxch      st(1)
00407104  dc3d903c5500             fdivr     qword ptr [0x553c90] ; bits=0000000000000000, f64=0.0
0040710a  d95dfc                   fstp      dword ptr [ebp - 4]
0040710d  8b45fc                   mov       eax, dword ptr [ebp - 4]
00407110  8b4d1c                   mov       ecx, dword ptr [ebp + 0x1c]
00407113  8901                     mov       dword ptr [ecx], eax
00407115  d91d98f70e04             fstp      dword ptr [0x40ef798]
0040711b  8b4518                   mov       eax, dword ptr [ebp + 0x18]
0040711e  d90598f70e04             fld       dword ptr [0x40ef798]
00407124  d800                     fadd      dword ptr [eax]
00407126  dee9                     fsubp     st(1)
00407128  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0040712b  d918                     fstp      dword ptr [eax]
0040712d  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00407130  8b0d84f70e04             mov       ecx, dword ptr [0x40ef784]
00407136  8908                     mov       dword ptr [eax], ecx
00407138  b800000000               mov       eax, 0
0040713d  5e                       pop       esi
0040713e  5b                       pop       ebx
0040713f  8be5                     mov       esp, ebp
00407141  5d                       pop       ebp
00407142  c3                       ret
00407143  8d9b00000000             lea       ebx, [ebx]
00407149  8da42400000000           lea       esp, [esp]
