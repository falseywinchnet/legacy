; _cuttab_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x93530
00493530  55                       push      ebp
00493531  8bec                     mov       ebp, esp
00493533  b80c000000               mov       eax, 0xc
00493538  e8c35a0500               call      0x4e9000 ; __alloca_probe
0049353d  53                       push      ebx
0049353e  8b4508                   mov       eax, dword ptr [ebp + 8]
00493541  8b550c                   mov       edx, dword ptr [ebp + 0xc]
00493544  8945fc                   mov       dword ptr [ebp - 4], eax
00493547  d90530bcf400             fld       dword ptr [0xf4bc30] ; _grvcom_
0049354d  8d0d886f5b00             lea       ecx, [0x5b6f88] ; bits=c0d40100, f32=1.6815581571897805e-40
00493553  d85988                   fcomp     dword ptr [ecx - 0x78]
00493556  dfe0                     fnstsw    ax
00493558  9e                       sahf
00493559  0f8a0d000000             jp        0x49356c
0049355f  760b                     jbe       0x49356c
00493561  d9418c                   fld       dword ptr [ecx - 0x74]
00493564  8b4190                   mov       eax, dword ptr [ecx - 0x70]
00493567  8945f8                   mov       dword ptr [ebp - 8], eax
0049356a  eb0d                     jmp       0x493579
0049356c  89c8                     mov       eax, ecx
0049356e  d94094                   fld       dword ptr [eax - 0x6c]
00493571  89c8                     mov       eax, ecx
00493573  8b5898                   mov       ebx, dword ptr [eax - 0x68]
00493576  895df8                   mov       dword ptr [ebp - 8], ebx
00493579  d9829c0f0000             fld       dword ptr [edx + 0xf9c]
0049357f  d9c9                     fxch      st(1)
00493581  8b45fc                   mov       eax, dword ptr [ebp - 4]
00493584  8b18                     mov       ebx, dword ptr [eax]
00493586  83c3ff                   add       ebx, -1
00493589  83fb00                   cmp       ebx, 0
0049358c  0f8ec3020000             jle       0x493855
00493592  b902000000               mov       ecx, 2
00493597  83fb02                   cmp       ebx, 2
0049359a  0f8cd2010000             jl        0x493772
004935a0  d9848a980f0000           fld       dword ptr [edx + ecx*4 + 0xf98]
004935a7  d9ee                     fldz
004935a9  d9c9                     fxch      st(1)
004935ab  dde1                     fucom     st(1)
004935ad  ddd9                     fstp      st(1)
004935af  d9ca                     fxch      st(2)
004935b1  d9c9                     fxch      st(1)
004935b3  dfe0                     fnstsw    ax
004935b5  9e                       sahf
004935b6  0f8a06000000             jp        0x4935c2
004935bc  0f84bc000000             je        0x49367e
004935c2  d9c2                     fld       st(2)
004935c4  d8e2                     fsub      st(2)
004935c6  d9e1                     fabs
004935c8  d8f3                     fdiv      st(3)
004935ca  d81d246f5b00             fcomp     dword ptr [0x5b6f24] ; bits=6f12833a, f32=0.0010000000474974513
004935d0  dfe0                     fnstsw    ax
004935d2  9e                       sahf
004935d3  0f8aa1000000             jp        0x49367a
004935d9  0f879b000000             ja        0x49367a
004935df  d9ca                     fxch      st(2)
004935e1  d8d2                     fcom      st(2)
004935e3  d9ca                     fxch      st(2)
004935e5  dfe0                     fnstsw    ax
004935e7  9e                       sahf
004935e8  0f8a8c000000             jp        0x49367a
004935ee  0f8786000000             ja        0x49367a
004935f4  ddd8                     fstp      st(0)
004935f6  8b45f8                   mov       eax, dword ptr [ebp - 8]
004935f9  89448afc                 mov       dword ptr [edx + ecx*4 - 4], eax
004935fd  8b848a683e0000           mov       eax, dword ptr [edx + ecx*4 + 0x3e68]
00493604  89848a6c3e0000           mov       dword ptr [edx + ecx*4 + 0x3e6c], eax
0049360b  8b848a044e0000           mov       eax, dword ptr [edx + ecx*4 + 0x4e04]
00493612  89848a084e0000           mov       dword ptr [edx + ecx*4 + 0x4e08], eax
00493619  8b848aa05d0000           mov       eax, dword ptr [edx + ecx*4 + 0x5da0]
00493620  89848aa45d0000           mov       dword ptr [edx + ecx*4 + 0x5da4], eax
00493627  8b848a48bb0000           mov       eax, dword ptr [edx + ecx*4 + 0xbb48]
0049362e  89848a4cbb0000           mov       dword ptr [edx + ecx*4 + 0xbb4c], eax
00493635  d9448af8                 fld       dword ptr [edx + ecx*4 - 8]
00493639  d86c8afc                 fsubr     dword ptr [edx + ecx*4 - 4]
0049363d  d80d286f5b00             fmul      dword ptr [0x5b6f28] ; bits=0000003f, f32=0.5
00493643  d9c9                     fxch      st(1)
00493645  dec2                     faddp     st(2)
00493647  dcc9                     fmul      st(1), st(0)
00493649  d9c9                     fxch      st(1)
0049364b  d8848a301f0000           fadd      dword ptr [edx + ecx*4 + 0x1f30]
00493652  d9948a341f0000           fst       dword ptr [edx + ecx*4 + 0x1f34]
00493659  d8848a301f0000           fadd      dword ptr [edx + ecx*4 + 0x1f30]
00493660  dec9                     fmulp     st(1)
00493662  d8848acc2e0000           fadd      dword ptr [edx + ecx*4 + 0x2ecc]
00493669  8b45fc                   mov       eax, dword ptr [ebp - 4]
0049366c  d99c8ad02e0000           fstp      dword ptr [edx + ecx*4 + 0x2ed0]
00493673  8908                     mov       dword ptr [eax], ecx
00493675  e9fb010000               jmp       0x493875
0049367a  ddd9                     fstp      st(1)
0049367c  eb04                     jmp       0x493682
0049367e  ddda                     fstp      st(2)
00493680  d9c9                     fxch      st(1)
00493682  41                       inc       ecx
00493683  d9848a980f0000           fld       dword ptr [edx + ecx*4 + 0xf98]
0049368a  d9ee                     fldz
0049368c  d9c9                     fxch      st(1)
0049368e  dde1                     fucom     st(1)
00493690  ddd9                     fstp      st(1)
00493692  d9ca                     fxch      st(2)
00493694  d9c9                     fxch      st(1)
00493696  dfe0                     fnstsw    ax
00493698  9e                       sahf
00493699  0f8a06000000             jp        0x4936a5
0049369f  0f84bc000000             je        0x493761
004936a5  d9c2                     fld       st(2)
004936a7  d8e2                     fsub      st(2)
004936a9  d9e1                     fabs
004936ab  d8f3                     fdiv      st(3)
004936ad  d81d246f5b00             fcomp     dword ptr [0x5b6f24] ; bits=6f12833a, f32=0.0010000000474974513
004936b3  dfe0                     fnstsw    ax
004936b5  9e                       sahf
004936b6  0f8aa1000000             jp        0x49375d
004936bc  0f879b000000             ja        0x49375d
004936c2  d9ca                     fxch      st(2)
004936c4  d8d2                     fcom      st(2)
004936c6  d9ca                     fxch      st(2)
004936c8  dfe0                     fnstsw    ax
004936ca  9e                       sahf
004936cb  0f8a8c000000             jp        0x49375d
004936d1  0f8786000000             ja        0x49375d
004936d7  ddd8                     fstp      st(0)
004936d9  8b45f8                   mov       eax, dword ptr [ebp - 8]
004936dc  89448afc                 mov       dword ptr [edx + ecx*4 - 4], eax
004936e0  8b848a683e0000           mov       eax, dword ptr [edx + ecx*4 + 0x3e68]
004936e7  89848a6c3e0000           mov       dword ptr [edx + ecx*4 + 0x3e6c], eax
004936ee  8b848a044e0000           mov       eax, dword ptr [edx + ecx*4 + 0x4e04]
004936f5  89848a084e0000           mov       dword ptr [edx + ecx*4 + 0x4e08], eax
004936fc  8b848aa05d0000           mov       eax, dword ptr [edx + ecx*4 + 0x5da0]
00493703  89848aa45d0000           mov       dword ptr [edx + ecx*4 + 0x5da4], eax
0049370a  8b848a48bb0000           mov       eax, dword ptr [edx + ecx*4 + 0xbb48]
00493711  89848a4cbb0000           mov       dword ptr [edx + ecx*4 + 0xbb4c], eax
00493718  d9448af8                 fld       dword ptr [edx + ecx*4 - 8]
0049371c  d86c8afc                 fsubr     dword ptr [edx + ecx*4 - 4]
00493720  d80d286f5b00             fmul      dword ptr [0x5b6f28] ; bits=0000003f, f32=0.5
00493726  d9c9                     fxch      st(1)
00493728  dec2                     faddp     st(2)
0049372a  dcc9                     fmul      st(1), st(0)
0049372c  d9c9                     fxch      st(1)
0049372e  d8848a301f0000           fadd      dword ptr [edx + ecx*4 + 0x1f30]
00493735  d9948a341f0000           fst       dword ptr [edx + ecx*4 + 0x1f34]
0049373c  d8848a301f0000           fadd      dword ptr [edx + ecx*4 + 0x1f30]
00493743  dec9                     fmulp     st(1)
00493745  d8848acc2e0000           fadd      dword ptr [edx + ecx*4 + 0x2ecc]
0049374c  8b45fc                   mov       eax, dword ptr [ebp - 4]
0049374f  d99c8ad02e0000           fstp      dword ptr [edx + ecx*4 + 0x2ed0]
00493756  8908                     mov       dword ptr [eax], ecx
00493758  e918010000               jmp       0x493875
0049375d  ddd9                     fstp      st(1)
0049375f  eb04                     jmp       0x493765
00493761  ddda                     fstp      st(2)
00493763  d9c9                     fxch      st(1)
00493765  41                       inc       ecx
00493766  83eb02                   sub       ebx, 2
00493769  83fb02                   cmp       ebx, 2
0049376c  0f8d2efeffff             jge       0x4935a0
00493772  85db                     test      ebx, ebx
00493774  0f84e1000000             je        0x49385b
0049377a  d9848a980f0000           fld       dword ptr [edx + ecx*4 + 0xf98]
00493781  d9ee                     fldz
00493783  d9c9                     fxch      st(1)
00493785  dde1                     fucom     st(1)
00493787  ddd9                     fstp      st(1)
00493789  d9ca                     fxch      st(2)
0049378b  d9c9                     fxch      st(1)
0049378d  dfe0                     fnstsw    ax
0049378f  9e                       sahf
00493790  0f8a06000000             jp        0x49379c
00493796  0f84c5000000             je        0x493861
0049379c  d9c2                     fld       st(2)
0049379e  d8e2                     fsub      st(2)
004937a0  d9e1                     fabs
004937a2  d8f3                     fdiv      st(3)
004937a4  8d05886f5b00             lea       eax, [0x5b6f88] ; bits=c0d40100, f32=1.6815581571897805e-40
004937aa  d8589c                   fcomp     dword ptr [eax - 0x64]
004937ad  8945f4                   mov       dword ptr [ebp - 0xc], eax
004937b0  dfe0                     fnstsw    ax
004937b2  9e                       sahf
004937b3  0f8ab0000000             jp        0x493869
004937b9  0f87aa000000             ja        0x493869
004937bf  d9ca                     fxch      st(2)
004937c1  d8d2                     fcom      st(2)
004937c3  ddda                     fstp      st(2)
004937c5  dfe0                     fnstsw    ax
004937c7  9e                       sahf
004937c8  0f8aa3000000             jp        0x493871
004937ce  0f879d000000             ja        0x493871
004937d4  8b45f8                   mov       eax, dword ptr [ebp - 8]
004937d7  89448afc                 mov       dword ptr [edx + ecx*4 - 4], eax
004937db  8b848a683e0000           mov       eax, dword ptr [edx + ecx*4 + 0x3e68]
004937e2  89848a6c3e0000           mov       dword ptr [edx + ecx*4 + 0x3e6c], eax
004937e9  8b848a044e0000           mov       eax, dword ptr [edx + ecx*4 + 0x4e04]
004937f0  89848a084e0000           mov       dword ptr [edx + ecx*4 + 0x4e08], eax
004937f7  8b848aa05d0000           mov       eax, dword ptr [edx + ecx*4 + 0x5da0]
004937fe  89848aa45d0000           mov       dword ptr [edx + ecx*4 + 0x5da4], eax
00493805  8b848a48bb0000           mov       eax, dword ptr [edx + ecx*4 + 0xbb48]
0049380c  89848a4cbb0000           mov       dword ptr [edx + ecx*4 + 0xbb4c], eax
00493813  d9448af8                 fld       dword ptr [edx + ecx*4 - 8]
00493817  8b45f4                   mov       eax, dword ptr [ebp - 0xc]
0049381a  d86c8afc                 fsubr     dword ptr [edx + ecx*4 - 4]
0049381e  d848a0                   fmul      dword ptr [eax - 0x60]
00493821  d9c9                     fxch      st(1)
00493823  dec2                     faddp     st(2)
00493825  dcc9                     fmul      st(1), st(0)
00493827  d9c9                     fxch      st(1)
00493829  d8848a301f0000           fadd      dword ptr [edx + ecx*4 + 0x1f30]
00493830  d9948a341f0000           fst       dword ptr [edx + ecx*4 + 0x1f34]
00493837  d8848a301f0000           fadd      dword ptr [edx + ecx*4 + 0x1f30]
0049383e  dec9                     fmulp     st(1)
00493840  d8848acc2e0000           fadd      dword ptr [edx + ecx*4 + 0x2ecc]
00493847  8b45fc                   mov       eax, dword ptr [ebp - 4]
0049384a  d99c8ad02e0000           fstp      dword ptr [edx + ecx*4 + 0x2ed0]
00493851  8908                     mov       dword ptr [eax], ecx
00493853  eb20                     jmp       0x493875
00493855  ddd8                     fstp      st(0)
00493857  ddd8                     fstp      st(0)
00493859  eb1a                     jmp       0x493875
0049385b  ddd8                     fstp      st(0)
0049385d  ddd8                     fstp      st(0)
0049385f  eb14                     jmp       0x493875
00493861  ddd8                     fstp      st(0)
00493863  ddd8                     fstp      st(0)
00493865  ddd8                     fstp      st(0)
00493867  eb0c                     jmp       0x493875
00493869  ddd8                     fstp      st(0)
0049386b  ddd8                     fstp      st(0)
0049386d  ddd8                     fstp      st(0)
0049386f  eb04                     jmp       0x493875
00493871  ddd8                     fstp      st(0)
00493873  ddd8                     fstp      st(0)
00493875  b800000000               mov       eax, 0
0049387a  5b                       pop       ebx
0049387b  8be5                     mov       esp, ebp
0049387d  5d                       pop       ebp
0049387e  c3                       ret
0049387f  90                       nop
