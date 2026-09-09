; _xlkt22_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x491d0
004491d0  55                       push      ebp
004491d1  8bec                     mov       ebp, esp
004491d3  b898010000               mov       eax, 0x198
004491d8  e823fe0900               call      0x4e9000 ; __alloca_probe
004491dd  53                       push      ebx
004491de  56                       push      esi
004491df  57                       push      edi
004491e0  8b4508                   mov       eax, dword ptr [ebp + 8]
004491e3  8b4d0c                   mov       ecx, dword ptr [ebp + 0xc]
004491e6  8b5510                   mov       edx, dword ptr [ebp + 0x10]
004491e9  898598feffff             mov       dword ptr [ebp - 0x168], eax
004491ef  898d94feffff             mov       dword ptr [ebp - 0x16c], ecx
004491f5  899590feffff             mov       dword ptr [ebp - 0x170], edx
004491fb  8b8594feffff             mov       eax, dword ptr [ebp - 0x16c]
00449201  d900                     fld       dword ptr [eax]
00449203  8bb598feffff             mov       esi, dword ptr [ebp - 0x168]
00449209  db7de0                   fstp      xword ptr [ebp - 0x20]
0044920c  8b16                     mov       edx, dword ptr [esi]
0044920e  8b3c95c0e5f400           mov       edi, dword ptr [edx*4 + 0xf4e5c0]
00449215  8d4220                   lea       eax, [edx + 0x20]
00449218  8b0c95cce5f400           mov       ecx, dword ptr [edx*4 + 0xf4e5cc]
0044921f  8b349514e6f400           mov       esi, dword ptr [edx*4 + 0xf4e614]
00449226  89bd8cfeffff             mov       dword ptr [ebp - 0x174], edi
0044922c  8b3c95c8e5f400           mov       edi, dword ptr [edx*4 + 0xf4e5c8]
00449233  8b1cbd445b5700           mov       ebx, dword ptr [edi*4 + 0x575b44]
0044923a  833cbd4420580000         cmp       dword ptr [edi*4 + 0x582044], 0
00449242  898588feffff             mov       dword ptr [ebp - 0x178], eax
00449248  89b584feffff             mov       dword ptr [ebp - 0x17c], esi
0044924e  89bd80feffff             mov       dword ptr [ebp - 0x180], edi
00449254  7528                     jne       0x44927e
00449256  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
0044925c  8d08                     lea       ecx, [eax]
0044925e  51                       push      ecx
0044925f  6848205800               push      0x582048
00449264  685495b700               push      0xb79554
00449269  e812330000               call      0x44c580 ; _xstype_
0044926e  83c40c                   add       esp, 0xc
00449271  68541f5800               push      0x581f54
00449276  e8c5a10500               call      0x4a3440 ; _jwe_xstp
0044927b  83c404                   add       esp, 4
0044927e  db6de0                   fld       xword ptr [ebp - 0x20]
00449281  d81c8dc0e5f400           fcomp     dword ptr [ecx*4 + 0xf4e5c0]
00449288  dfe0                     fnstsw    ax
0044928a  9e                       sahf
0044928b  0f8a57010000             jp        0x4493e8
00449291  0f8251010000             jb        0x4493e8
00449297  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
0044929d  db6de0                   fld       xword ptr [ebp - 0x20]
004492a0  d81c85c0e5f400           fcomp     dword ptr [eax*4 + 0xf4e5c0]
004492a7  dfe0                     fnstsw    ax
004492a9  9e                       sahf
004492aa  0f8a16010000             jp        0x4493c6
004492b0  0f8610010000             jbe       0x4493c6
004492b6  89d0                     mov       eax, edx
004492b8  83c010                   add       eax, 0x10
004492bb  8945fc                   mov       dword ptr [ebp - 4], eax
004492be  8d45fc                   lea       eax, [ebp - 4]
004492c1  50                       push      eax
004492c2  6a10                     push      0x10
004492c4  6828205800               push      0x582028
004492c9  e88258ffff               call      0x43eb50 ; _get_string_from_ft_
004492ce  83c40c                   add       esp, 0xc
004492d1  8d0518205800             lea       eax, [0x582018] ; bits=00000000, f32=0.0
004492d7  8d3528205800             lea       esi, [0x582028] ; bits=00000000, f32=0.0
004492dd  50                       push      eax
004492de  8a06                     mov       al, byte ptr [esi]
004492e0  5f                       pop       edi
004492e1  8807                     mov       byte ptr [edi], al
004492e3  8a4601                   mov       al, byte ptr [esi + 1]
004492e6  884701                   mov       byte ptr [edi + 1], al
004492e9  8a4602                   mov       al, byte ptr [esi + 2]
004492ec  884702                   mov       byte ptr [edi + 2], al
004492ef  8a4603                   mov       al, byte ptr [esi + 3]
004492f2  884703                   mov       byte ptr [edi + 3], al
004492f5  8a4604                   mov       al, byte ptr [esi + 4]
004492f8  884704                   mov       byte ptr [edi + 4], al
004492fb  8a4605                   mov       al, byte ptr [esi + 5]
004492fe  884705                   mov       byte ptr [edi + 5], al
00449301  8a4606                   mov       al, byte ptr [esi + 6]
00449304  884706                   mov       byte ptr [edi + 6], al
00449307  8a4607                   mov       al, byte ptr [esi + 7]
0044930a  884707                   mov       byte ptr [edi + 7], al
0044930d  8a4608                   mov       al, byte ptr [esi + 8]
00449310  884708                   mov       byte ptr [edi + 8], al
00449313  8a4609                   mov       al, byte ptr [esi + 9]
00449316  884709                   mov       byte ptr [edi + 9], al
00449319  8a460a                   mov       al, byte ptr [esi + 0xa]
0044931c  88470a                   mov       byte ptr [edi + 0xa], al
0044931f  8a460b                   mov       al, byte ptr [esi + 0xb]
00449322  88470b                   mov       byte ptr [edi + 0xb], al
00449325  8a460c                   mov       al, byte ptr [esi + 0xc]
00449328  88470c                   mov       byte ptr [edi + 0xc], al
0044932b  8a460d                   mov       al, byte ptr [esi + 0xd]
0044932e  88470d                   mov       byte ptr [edi + 0xd], al
00449331  8a460e                   mov       al, byte ptr [esi + 0xe]
00449334  88470e                   mov       byte ptr [edi + 0xe], al
00449337  8a460f                   mov       al, byte ptr [esi + 0xf]
0044933a  88470f                   mov       byte ptr [edi + 0xf], al
0044933d  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00449343  8b30                     mov       esi, dword ptr [eax]
00449345  8b34b5d0e5f400           mov       esi, dword ptr [esi*4 + 0xf4e5d0]
0044934c  8b3d4095b700             mov       edi, dword ptr [0xb79540] ; _xscom_
00449352  8b054495b700             mov       eax, dword ptr [0xb79544]
00449358  89b578feffff             mov       dword ptr [ebp - 0x188], esi
0044935e  8d35b01f5800             lea       esi, [0x581fb0] ; bits=09020000, f32=7.300764999132297e-43
00449364  89bd74feffff             mov       dword ptr [ebp - 0x18c], edi
0044936a  8bbd78feffff             mov       edi, dword ptr [ebp - 0x188]
00449370  897df8                   mov       dword ptr [ebp - 8], edi
00449373  8d7df8                   lea       edi, [ebp - 8]
00449376  897e34                   mov       dword ptr [esi + 0x34], edi
00449379  8bbd74feffff             mov       edi, dword ptr [ebp - 0x18c]
0044937f  897df0                   mov       dword ptr [ebp - 0x10], edi
00449382  8945f4                   mov       dword ptr [ebp - 0xc], eax
00449385  8d45f0                   lea       eax, [ebp - 0x10]
00449388  894640                   mov       dword ptr [esi + 0x40], eax
0044938b  db6de0                   fld       xword ptr [ebp - 0x20]
0044938e  d95dec                   fstp      dword ptr [ebp - 0x14]
00449391  8d45ec                   lea       eax, [ebp - 0x14]
00449394  89464c                   mov       dword ptr [esi + 0x4c], eax
00449397  56                       push      esi
00449398  e853920500               call      0x4a25f0 ; _jwe_isfm
0044939d  83c404                   add       esp, 4
004493a0  8b858cfeffff             mov       eax, dword ptr [ebp - 0x174]
004493a6  89c6                     mov       esi, eax
004493a8  29de                     sub       esi, ebx
004493aa  89f1                     mov       ecx, esi
004493ac  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
004493b3  db7de0                   fstp      xword ptr [ebp - 0x20]
004493b6  8b8594feffff             mov       eax, dword ptr [ebp - 0x16c]
004493bc  db6de0                   fld       xword ptr [ebp - 0x20]
004493bf  d918                     fstp      dword ptr [eax]
004493c1  e96c010000               jmp       0x449532
004493c6  8d140b                   lea       edx, [ebx + ecx]
004493c9  db6de0                   fld       xword ptr [ebp - 0x20]
004493cc  d81495c0e5f400           fcom      dword ptr [edx*4 + 0xf4e5c0]
004493d3  dfe0                     fnstsw    ax
004493d5  9e                       sahf
004493d6  0f8a53010000             jp        0x44952f
004493dc  0f864d010000             jbe       0x44952f
004493e2  01d9                     add       ecx, ebx
004493e4  01da                     add       edx, ebx
004493e6  ebe4                     jmp       0x4493cc
004493e8  8b8588feffff             mov       eax, dword ptr [ebp - 0x178]
004493ee  db6de0                   fld       xword ptr [ebp - 0x20]
004493f1  d81c85c0e5f400           fcomp     dword ptr [eax*4 + 0xf4e5c0]
004493f8  dfe0                     fnstsw    ax
004493fa  9e                       sahf
004493fb  0f8a12010000             jp        0x449513
00449401  0f830c010000             jae       0x449513
00449407  89d0                     mov       eax, edx
00449409  83c010                   add       eax, 0x10
0044940c  8945fc                   mov       dword ptr [ebp - 4], eax
0044940f  8d45fc                   lea       eax, [ebp - 4]
00449412  50                       push      eax
00449413  6a10                     push      0x10
00449415  6838205800               push      0x582038
0044941a  e83157ffff               call      0x43eb50 ; _get_string_from_ft_
0044941f  83c40c                   add       esp, 0xc
00449422  8d0518205800             lea       eax, [0x582018] ; bits=00000000, f32=0.0
00449428  8d3538205800             lea       esi, [0x582038] ; bits=00000000, f32=0.0
0044942e  50                       push      eax
0044942f  8a06                     mov       al, byte ptr [esi]
00449431  5f                       pop       edi
00449432  8807                     mov       byte ptr [edi], al
00449434  8a4601                   mov       al, byte ptr [esi + 1]
00449437  884701                   mov       byte ptr [edi + 1], al
0044943a  8a4602                   mov       al, byte ptr [esi + 2]
0044943d  884702                   mov       byte ptr [edi + 2], al
00449440  8a4603                   mov       al, byte ptr [esi + 3]
00449443  884703                   mov       byte ptr [edi + 3], al
00449446  8a4604                   mov       al, byte ptr [esi + 4]
00449449  884704                   mov       byte ptr [edi + 4], al
0044944c  8a4605                   mov       al, byte ptr [esi + 5]
0044944f  884705                   mov       byte ptr [edi + 5], al
00449452  8a4606                   mov       al, byte ptr [esi + 6]
00449455  884706                   mov       byte ptr [edi + 6], al
00449458  8a4607                   mov       al, byte ptr [esi + 7]
0044945b  884707                   mov       byte ptr [edi + 7], al
0044945e  8a4608                   mov       al, byte ptr [esi + 8]
00449461  884708                   mov       byte ptr [edi + 8], al
00449464  8a4609                   mov       al, byte ptr [esi + 9]
00449467  884709                   mov       byte ptr [edi + 9], al
0044946a  8a460a                   mov       al, byte ptr [esi + 0xa]
0044946d  88470a                   mov       byte ptr [edi + 0xa], al
00449470  8a460b                   mov       al, byte ptr [esi + 0xb]
00449473  88470b                   mov       byte ptr [edi + 0xb], al
00449476  8a460c                   mov       al, byte ptr [esi + 0xc]
00449479  88470c                   mov       byte ptr [edi + 0xc], al
0044947c  8a460d                   mov       al, byte ptr [esi + 0xd]
0044947f  88470d                   mov       byte ptr [edi + 0xd], al
00449482  8a460e                   mov       al, byte ptr [esi + 0xe]
00449485  88470e                   mov       byte ptr [edi + 0xe], al
00449488  8a460f                   mov       al, byte ptr [esi + 0xf]
0044948b  88470f                   mov       byte ptr [edi + 0xf], al
0044948e  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00449494  8b30                     mov       esi, dword ptr [eax]
00449496  8b34b5d0e5f400           mov       esi, dword ptr [esi*4 + 0xf4e5d0]
0044949d  8b3d4095b700             mov       edi, dword ptr [0xb79540] ; _xscom_
004494a3  8b054495b700             mov       eax, dword ptr [0xb79544]
004494a9  89b56cfeffff             mov       dword ptr [ebp - 0x194], esi
004494af  8d35601f5800             lea       esi, [0x581f60] ; bits=09020000, f32=7.300764999132297e-43
004494b5  89bd68feffff             mov       dword ptr [ebp - 0x198], edi
004494bb  8bbd6cfeffff             mov       edi, dword ptr [ebp - 0x194]
004494c1  897df8                   mov       dword ptr [ebp - 8], edi
004494c4  8d7df8                   lea       edi, [ebp - 8]
004494c7  897e34                   mov       dword ptr [esi + 0x34], edi
004494ca  8bbd68feffff             mov       edi, dword ptr [ebp - 0x198]
004494d0  897df0                   mov       dword ptr [ebp - 0x10], edi
004494d3  8945f4                   mov       dword ptr [ebp - 0xc], eax
004494d6  8d45f0                   lea       eax, [ebp - 0x10]
004494d9  894640                   mov       dword ptr [esi + 0x40], eax
004494dc  db6de0                   fld       xword ptr [ebp - 0x20]
004494df  d95dec                   fstp      dword ptr [ebp - 0x14]
004494e2  8d45ec                   lea       eax, [ebp - 0x14]
004494e5  89464c                   mov       dword ptr [esi + 0x4c], eax
004494e8  56                       push      esi
004494e9  e802910500               call      0x4a25f0 ; _jwe_isfm
004494ee  83c404                   add       esp, 4
004494f1  8b8588feffff             mov       eax, dword ptr [ebp - 0x178]
004494f7  89c1                     mov       ecx, eax
004494f9  8d3403                   lea       esi, [ebx + eax]
004494fc  d904b5c0e5f400           fld       dword ptr [esi*4 + 0xf4e5c0]
00449503  db7de0                   fstp      xword ptr [ebp - 0x20]
00449506  8b8594feffff             mov       eax, dword ptr [ebp - 0x16c]
0044950c  db6de0                   fld       xword ptr [ebp - 0x20]
0044950f  d918                     fstp      dword ptr [eax]
00449511  eb1f                     jmp       0x449532
00449513  db6de0                   fld       xword ptr [ebp - 0x20]
00449516  29d9                     sub       ecx, ebx
00449518  d8148dc0e5f400           fcom      dword ptr [ecx*4 + 0xf4e5c0]
0044951f  dfe0                     fnstsw    ax
00449521  9e                       sahf
00449522  0f8a02000000             jp        0x44952a
00449528  72ec                     jb        0x449516
0044952a  db7de0                   fstp      xword ptr [ebp - 0x20]
0044952d  eb03                     jmp       0x449532
0044952f  db7de0                   fstp      xword ptr [ebp - 0x20]
00449532  8b8598feffff             mov       eax, dword ptr [ebp - 0x168]
00449538  8b30                     mov       esi, dword ptr [eax]
0044953a  890cb5cce5f400           mov       dword ptr [esi*4 + 0xf4e5cc], ecx
00449541  d9048dc0e5f400           fld       dword ptr [ecx*4 + 0xf4e5c0]
00449548  dbbd50ffffff             fstp      xword ptr [ebp - 0xb0]
0044954e  d9048dc4e5f400           fld       dword ptr [ecx*4 + 0xf4e5c4]
00449555  dbbd5cffffff             fstp      xword ptr [ebp - 0xa4]
0044955b  d9048dc8e5f400           fld       dword ptr [ecx*4 + 0xf4e5c8]
00449562  dbbd68ffffff             fstp      xword ptr [ebp - 0x98]
00449568  d9048dcce5f400           fld       dword ptr [ecx*4 + 0xf4e5cc]
0044956f  db7dd4                   fstp      xword ptr [ebp - 0x2c]
00449572  d9048dd0e5f400           fld       dword ptr [ecx*4 + 0xf4e5d0]
00449579  db7dc8                   fstp      xword ptr [ebp - 0x38]
0044957c  d9048dd4e5f400           fld       dword ptr [ecx*4 + 0xf4e5d4]
00449583  dbbd74ffffff             fstp      xword ptr [ebp - 0x8c]
00449589  d9048dd8e5f400           fld       dword ptr [ecx*4 + 0xf4e5d8]
00449590  dbbd44ffffff             fstp      xword ptr [ebp - 0xbc]
00449596  8d140b                   lea       edx, [ebx + ecx]
00449599  d90495cce5f400           fld       dword ptr [edx*4 + 0xf4e5cc]
004495a0  db7dbc                   fstp      xword ptr [ebp - 0x44]
004495a3  d90495d0e5f400           fld       dword ptr [edx*4 + 0xf4e5d0]
004495aa  db7db0                   fstp      xword ptr [ebp - 0x50]
004495ad  d90495d8e5f400           fld       dword ptr [edx*4 + 0xf4e5d8]
004495b4  db7da4                   fstp      xword ptr [ebp - 0x5c]
004495b7  d90495c0e5f400           fld       dword ptr [edx*4 + 0xf4e5c0]
004495be  dbad50ffffff             fld       xword ptr [ebp - 0xb0]
004495c4  d82c95c0e5f400           fsubr     dword ptr [edx*4 + 0xf4e5c0]
004495cb  db6de0                   fld       xword ptr [ebp - 0x20]
004495ce  dbad50ffffff             fld       xword ptr [ebp - 0xb0]
004495d4  dee9                     fsubp     st(1)
004495d6  8d05d01e5800             lea       eax, [0x581ed0] ; bits=00020000, f32=7.174648137343064e-43
004495dc  d9c0                     fld       st(0)
004495de  d84888                   fmul      dword ptr [eax - 0x78]
004495e1  dbad5cffffff             fld       xword ptr [ebp - 0xa4]
004495e7  d82c95c4e5f400           fsubr     dword ptr [edx*4 + 0xf4e5c4]
004495ee  d8f3                     fdiv      st(3)
004495f0  8b7518                   mov       esi, dword ptr [ebp + 0x18]
004495f3  d916                     fst       dword ptr [esi]
004495f5  d90495dce5f400           fld       dword ptr [edx*4 + 0xf4e5dc]
004495fc  d9c9                     fxch      st(1)
004495fe  d8cb                     fmul      st(3)
00449600  dbad5cffffff             fld       xword ptr [ebp - 0xa4]
00449606  dec1                     faddp     st(1)
00449608  8b7514                   mov       esi, dword ptr [ebp + 0x14]
0044960b  d916                     fst       dword ptr [esi]
0044960d  dbad5cffffff             fld       xword ptr [ebp - 0xa4]
00449613  dec1                     faddp     st(1)
00449615  d8ca                     fmul      st(2)
00449617  dbad68ffffff             fld       xword ptr [ebp - 0x98]
0044961d  8bbd90feffff             mov       edi, dword ptr [ebp - 0x170]
00449623  dec1                     faddp     st(1)
00449625  d917                     fst       dword ptr [edi]
00449627  dbad68ffffff             fld       xword ptr [ebp - 0x98]
0044962d  dec1                     faddp     st(1)
0044962f  dbad5cffffff             fld       xword ptr [ebp - 0xa4]
00449635  d82e                     fsubr     dword ptr [esi]
00449637  d8cc                     fmul      st(4)
00449639  d84898                   fmul      dword ptr [eax - 0x68]
0044963c  dee9                     fsubp     st(1)
0044963e  deca                     fmulp     st(2)
00449640  dbad74ffffff             fld       xword ptr [ebp - 0x8c]
00449646  dec2                     faddp     st(2)
00449648  8b451c                   mov       eax, dword ptr [ebp + 0x1c]
0044964b  d9c9                     fxch      st(1)
0044964d  d918                     fstp      dword ptr [eax]
0044964f  d9ee                     fldz
00449651  dbad50ffffff             fld       xword ptr [ebp - 0xb0]
00449657  dde9                     fucomp    st(1)
00449659  ddd8                     fstp      st(0)
0044965b  dbad50ffffff             fld       xword ptr [ebp - 0xb0]
00449661  db7d98                   fstp      xword ptr [ebp - 0x68]
00449664  d9c9                     fxch      st(1)
00449666  db7d8c                   fstp      xword ptr [ebp - 0x74]
00449669  d9c9                     fxch      st(1)
0044966b  db7d80                   fstp      xword ptr [ebp - 0x80]
0044966e  dbad44ffffff             fld       xword ptr [ebp - 0xbc]
00449674  d9c9                     fxch      st(1)
00449676  d9ca                     fxch      st(2)
00449678  d9c9                     fxch      st(1)
0044967a  dfe0                     fnstsw    ax
0044967c  9e                       sahf
0044967d  0f8a27000000             jp        0x4496aa
00449683  7525                     jne       0x4496aa
00449685  d9c9                     fxch      st(1)
00449687  db7d98                   fstp      xword ptr [ebp - 0x68]
0044968a  89d8                     mov       eax, ebx
0044968c  01d0                     add       eax, edx
0044968e  d90485c0e5f400           fld       dword ptr [eax*4 + 0xf4e5c0]
00449695  d9ca                     fxch      st(2)
00449697  dbbd38ffffff             fstp      xword ptr [ebp - 0xc8]
0044969d  d90485dce5f400           fld       dword ptr [eax*4 + 0xf4e5dc]
004496a4  d9ca                     fxch      st(2)
004496a6  d9c9                     fxch      st(1)
004496a8  eb0d                     jmp       0x4496b7
004496aa  d9048ddce5f400           fld       dword ptr [ecx*4 + 0xf4e5dc]
004496b1  dbbd38ffffff             fstp      xword ptr [ebp - 0xc8]
004496b7  db6de0                   fld       xword ptr [ebp - 0x20]
004496ba  d81d501e5800             fcomp     dword ptr [0x581e50] ; bits=00000000, f32=0.0
004496c0  dfe0                     fnstsw    ax
004496c2  9e                       sahf
004496c3  0f8a7c000000             jp        0x449745
004496c9  767a                     jbe       0x449745
004496cb  db6de0                   fld       xword ptr [ebp - 0x20]
004496ce  db6d98                   fld       xword ptr [ebp - 0x68]
004496d1  def9                     fdivp     st(1)
004496d3  d9ed                     fldln2
004496d5  d9c0                     fld       st(0)
004496d7  d9c9                     fxch      st(1)
004496d9  d9ca                     fxch      st(2)
004496db  d9f1                     fyl2x
004496dd  d95df8                   fstp      dword ptr [ebp - 8]
004496e0  d945f8                   fld       dword ptr [ebp - 8]
004496e3  dbad38ffffff             fld       xword ptr [ebp - 0xc8]
004496e9  defd                     fdivp     st(5)
004496eb  d9c1                     fld       st(1)
004496ed  d9c9                     fxch      st(1)
004496ef  d9cd                     fxch      st(5)
004496f1  d9f1                     fyl2x
004496f3  d95df8                   fstp      dword ptr [ebp - 8]
004496f6  d9cb                     fxch      st(3)
004496f8  d84df8                   fmul      dword ptr [ebp - 8]
004496fb  db6d98                   fld       xword ptr [ebp - 0x68]
004496fe  defb                     fdivp     st(3)
00449700  d9cb                     fxch      st(3)
00449702  d9c9                     fxch      st(1)
00449704  d9ca                     fxch      st(2)
00449706  d9f1                     fyl2x
00449708  d95df8                   fstp      dword ptr [ebp - 8]
0044970b  d9c9                     fxch      st(1)
0044970d  d875f8                   fdiv      dword ptr [ebp - 8]
00449710  d91d0c205800             fstp      dword ptr [0x58200c] ; bits=00000000, f32=0.0
00449716  d9ea                     fldl2e
00449718  d80d0c205800             fmul      dword ptr [0x58200c] ; bits=00000000, f32=0.0
0044971e  d9c0                     fld       st(0)
00449720  d9fc                     frndint
00449722  dce9                     fsub      st(1), st(0)
00449724  d9c9                     fxch      st(1)
00449726  d9f0                     f2xm1
00449728  d8055c1e5800             fadd      dword ptr [0x581e5c] ; bits=0000803f, f32=1.0
0044972e  d9fd                     fscale
00449730  ddd9                     fstp      st(1)
00449732  d95df8                   fstp      dword ptr [ebp - 8]
00449735  dbad38ffffff             fld       xword ptr [ebp - 0xc8]
0044973b  d84df8                   fmul      dword ptr [ebp - 8]
0044973e  8b4538                   mov       eax, dword ptr [ebp + 0x38]
00449741  d918                     fstp      dword ptr [eax]
00449743  eb0d                     jmp       0x449752
00449745  ddd9                     fstp      st(1)
00449747  ddd9                     fstp      st(1)
00449749  8b4538                   mov       eax, dword ptr [ebp + 0x38]
0044974c  c70000000000             mov       dword ptr [eax], 0
00449752  8b8584feffff             mov       eax, dword ptr [ebp - 0x17c]
00449758  85c0                     test      eax, eax
0044975a  7562                     jne       0x4497be
0044975c  db6db0                   fld       xword ptr [ebp - 0x50]
0044975f  db6dc8                   fld       xword ptr [ebp - 0x38]
00449762  dee9                     fsubp     st(1)
00449764  db6d80                   fld       xword ptr [ebp - 0x80]
00449767  def9                     fdivp     st(1)
00449769  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
0044976c  d910                     fst       dword ptr [eax]
0044976e  db6d8c                   fld       xword ptr [ebp - 0x74]
00449771  dec9                     fmulp     st(1)
00449773  db6dc8                   fld       xword ptr [ebp - 0x38]
00449776  dec1                     faddp     st(1)
00449778  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0044977b  d918                     fstp      dword ptr [eax]
0044977d  db6da4                   fld       xword ptr [ebp - 0x5c]
00449780  d8e1                     fsub      st(1)
00449782  db6d80                   fld       xword ptr [ebp - 0x80]
00449785  def9                     fdivp     st(1)
00449787  8b4534                   mov       eax, dword ptr [ebp + 0x34]
0044978a  d910                     fst       dword ptr [eax]
0044978c  db6d8c                   fld       xword ptr [ebp - 0x74]
0044978f  dec9                     fmulp     st(1)
00449791  dec1                     faddp     st(1)
00449793  8b4530                   mov       eax, dword ptr [ebp + 0x30]
00449796  d918                     fstp      dword ptr [eax]
00449798  db6dbc                   fld       xword ptr [ebp - 0x44]
0044979b  db6dd4                   fld       xword ptr [ebp - 0x2c]
0044979e  dee9                     fsubp     st(1)
004497a0  db6d80                   fld       xword ptr [ebp - 0x80]
004497a3  def9                     fdivp     st(1)
004497a5  8b4524                   mov       eax, dword ptr [ebp + 0x24]
004497a8  d910                     fst       dword ptr [eax]
004497aa  db6d8c                   fld       xword ptr [ebp - 0x74]
004497ad  dec9                     fmulp     st(1)
004497af  db6dd4                   fld       xword ptr [ebp - 0x2c]
004497b2  dec1                     faddp     st(1)
004497b4  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004497b7  d918                     fstp      dword ptr [eax]
004497b9  e966020000               jmp       0x449a24
004497be  db6d8c                   fld       xword ptr [ebp - 0x74]
004497c1  db6d80                   fld       xword ptr [ebp - 0x80]
004497c4  def9                     fdivp     st(1)
004497c6  d9c0                     fld       st(0)
004497c8  d82d5c1e5800             fsubr     dword ptr [0x581e5c] ; bits=0000803f, f32=1.0
004497ce  d9c0                     fld       st(0)
004497d0  d8ca                     fmul      st(2)
004497d2  db6d80                   fld       xword ptr [ebp - 0x80]
004497d5  dec9                     fmulp     st(1)
004497d7  d9c0                     fld       st(0)
004497d9  d8cb                     fmul      st(3)
004497db  d9e0                     fchs
004497dd  dbbd2cffffff             fstp      xword ptr [ebp - 0xd4]
004497e3  d8c9                     fmul      st(1)
004497e5  d9c2                     fld       st(2)
004497e7  d8c0                     fadd      st(0)
004497e9  d8055c1e5800             fadd      dword ptr [0x581e5c] ; bits=0000803f, f32=1.0
004497ef  8d05d01e5800             lea       eax, [0x581ed0] ; bits=00020000, f32=7.174648137343064e-43
004497f5  d9c0                     fld       st(0)
004497f7  d86894                   fsubr     dword ptr [eax - 0x6c]
004497fa  d8cc                     fmul      st(4)
004497fc  d8cc                     fmul      st(4)
004497fe  dbbd20ffffff             fstp      xword ptr [ebp - 0xe0]
00449804  d9c2                     fld       st(2)
00449806  d8c8                     fmul      st(0)
00449808  dec9                     fmulp     st(1)
0044980a  d9c3                     fld       st(3)
0044980c  d8489c                   fmul      dword ptr [eax - 0x64]
0044980f  d82d5c1e5800             fsubr     dword ptr [0x581e5c] ; bits=0000803f, f32=1.0
00449815  d9c0                     fld       st(0)
00449817  d8055c1e5800             fadd      dword ptr [0x581e5c] ; bits=0000803f, f32=1.0
0044981d  d8cd                     fmul      st(5)
0044981f  d9e0                     fchs
00449821  dbbd14ffffff             fstp      xword ptr [ebp - 0xec]
00449827  d8cb                     fmul      st(3)
00449829  d9cb                     fxch      st(3)
0044982b  d848a0                   fmul      dword ptr [eax - 0x60]
0044982e  decc                     fmulp     st(4)
00449830  db6d80                   fld       xword ptr [ebp - 0x80]
00449833  defc                     fdivp     st(4)
00449835  d9cb                     fxch      st(3)
00449837  dbbd08ffffff             fstp      xword ptr [ebp - 0xf8]
0044983d  8b8584feffff             mov       eax, dword ptr [ebp - 0x17c]
00449843  01c1                     add       ecx, eax
00449845  89d3                     mov       ebx, edx
00449847  01c3                     add       ebx, eax
00449849  89da                     mov       edx, ebx
0044984b  d9048dc0e5f400           fld       dword ptr [ecx*4 + 0xf4e5c0]
00449852  dbbdfcfeffff             fstp      xword ptr [ebp - 0x104]
00449858  d90495c0e5f400           fld       dword ptr [edx*4 + 0xf4e5c0]
0044985f  dbbdf0feffff             fstp      xword ptr [ebp - 0x110]
00449865  d9048dc4e5f400           fld       dword ptr [ecx*4 + 0xf4e5c4]
0044986c  dbbde4feffff             fstp      xword ptr [ebp - 0x11c]
00449872  d90495c4e5f400           fld       dword ptr [edx*4 + 0xf4e5c4]
00449879  dbbdd8feffff             fstp      xword ptr [ebp - 0x128]
0044987f  d9c9                     fxch      st(1)
00449881  dbbdccfeffff             fstp      xword ptr [ebp - 0x134]
00449887  d9c9                     fxch      st(1)
00449889  dbbdc0feffff             fstp      xword ptr [ebp - 0x140]
0044988f  dbbdb4feffff             fstp      xword ptr [ebp - 0x14c]
00449895  83bd80feffff20           cmp       dword ptr [ebp - 0x180], 0x20
0044989c  751c                     jne       0x4498ba
0044989e  d9048dc8e5f400           fld       dword ptr [ecx*4 + 0xf4e5c8]
004498a5  dbbda8feffff             fstp      xword ptr [ebp - 0x158]
004498ab  d90495c8e5f400           fld       dword ptr [edx*4 + 0xf4e5c8]
004498b2  dbbd9cfeffff             fstp      xword ptr [ebp - 0x164]
004498b8  eb1a                     jmp       0x4498d4
004498ba  d9048dd0e5f400           fld       dword ptr [ecx*4 + 0xf4e5d0]
004498c1  dbbda8feffff             fstp      xword ptr [ebp - 0x158]
004498c7  d90495d0e5f400           fld       dword ptr [edx*4 + 0xf4e5d0]
004498ce  dbbd9cfeffff             fstp      xword ptr [ebp - 0x164]
004498d4  dbadb4feffff             fld       xword ptr [ebp - 0x14c]
004498da  dbade4feffff             fld       xword ptr [ebp - 0x11c]
004498e0  dec9                     fmulp     st(1)
004498e2  dbad2cffffff             fld       xword ptr [ebp - 0xd4]
004498e8  dbadd8feffff             fld       xword ptr [ebp - 0x128]
004498ee  dec9                     fmulp     st(1)
004498f0  dec1                     faddp     st(1)
004498f2  dbadc0feffff             fld       xword ptr [ebp - 0x140]
004498f8  db6dc8                   fld       xword ptr [ebp - 0x38]
004498fb  dec9                     fmulp     st(1)
004498fd  dec1                     faddp     st(1)
004498ff  dbad20ffffff             fld       xword ptr [ebp - 0xe0]
00449905  db6db0                   fld       xword ptr [ebp - 0x50]
00449908  dec9                     fmulp     st(1)
0044990a  dec1                     faddp     st(1)
0044990c  8b4528                   mov       eax, dword ptr [ebp + 0x28]
0044990f  d918                     fstp      dword ptr [eax]
00449911  dbadccfeffff             fld       xword ptr [ebp - 0x134]
00449917  dbade4feffff             fld       xword ptr [ebp - 0x11c]
0044991d  dec9                     fmulp     st(1)
0044991f  dbad14ffffff             fld       xword ptr [ebp - 0xec]
00449925  dbadd8feffff             fld       xword ptr [ebp - 0x128]
0044992b  dec9                     fmulp     st(1)
0044992d  dec1                     faddp     st(1)
0044992f  db6db0                   fld       xword ptr [ebp - 0x50]
00449932  db6dc8                   fld       xword ptr [ebp - 0x38]
00449935  dee9                     fsubp     st(1)
00449937  dbad08ffffff             fld       xword ptr [ebp - 0xf8]
0044993d  dec9                     fmulp     st(1)
0044993f  dec1                     faddp     st(1)
00449941  8b452c                   mov       eax, dword ptr [ebp + 0x2c]
00449944  d918                     fstp      dword ptr [eax]
00449946  dbadb4feffff             fld       xword ptr [ebp - 0x14c]
0044994c  dbada8feffff             fld       xword ptr [ebp - 0x158]
00449952  dec9                     fmulp     st(1)
00449954  dbad2cffffff             fld       xword ptr [ebp - 0xd4]
0044995a  dbad9cfeffff             fld       xword ptr [ebp - 0x164]
00449960  dec9                     fmulp     st(1)
00449962  dec1                     faddp     st(1)
00449964  dbadc0feffff             fld       xword ptr [ebp - 0x140]
0044996a  d8ca                     fmul      st(2)
0044996c  dec1                     faddp     st(1)
0044996e  dbad20ffffff             fld       xword ptr [ebp - 0xe0]
00449974  db6da4                   fld       xword ptr [ebp - 0x5c]
00449977  dec9                     fmulp     st(1)
00449979  dec1                     faddp     st(1)
0044997b  8b4530                   mov       eax, dword ptr [ebp + 0x30]
0044997e  d918                     fstp      dword ptr [eax]
00449980  dbadccfeffff             fld       xword ptr [ebp - 0x134]
00449986  dbada8feffff             fld       xword ptr [ebp - 0x158]
0044998c  dec9                     fmulp     st(1)
0044998e  dbad14ffffff             fld       xword ptr [ebp - 0xec]
00449994  dbad9cfeffff             fld       xword ptr [ebp - 0x164]
0044999a  dec9                     fmulp     st(1)
0044999c  dec1                     faddp     st(1)
0044999e  db6da4                   fld       xword ptr [ebp - 0x5c]
004499a1  dee2                     fsubrp    st(2)
004499a3  dbad08ffffff             fld       xword ptr [ebp - 0xf8]
004499a9  deca                     fmulp     st(2)
004499ab  dec1                     faddp     st(1)
004499ad  8b4534                   mov       eax, dword ptr [ebp + 0x34]
004499b0  d918                     fstp      dword ptr [eax]
004499b2  dbadb4feffff             fld       xword ptr [ebp - 0x14c]
004499b8  dbadfcfeffff             fld       xword ptr [ebp - 0x104]
004499be  dec9                     fmulp     st(1)
004499c0  dbad2cffffff             fld       xword ptr [ebp - 0xd4]
004499c6  dbadf0feffff             fld       xword ptr [ebp - 0x110]
004499cc  dec9                     fmulp     st(1)
004499ce  dec1                     faddp     st(1)
004499d0  dbadc0feffff             fld       xword ptr [ebp - 0x140]
004499d6  db6dd4                   fld       xword ptr [ebp - 0x2c]
004499d9  dec9                     fmulp     st(1)
004499db  dec1                     faddp     st(1)
004499dd  dbad20ffffff             fld       xword ptr [ebp - 0xe0]
004499e3  db6dbc                   fld       xword ptr [ebp - 0x44]
004499e6  dec9                     fmulp     st(1)
004499e8  dec1                     faddp     st(1)
004499ea  8b4520                   mov       eax, dword ptr [ebp + 0x20]
004499ed  d918                     fstp      dword ptr [eax]
004499ef  dbadccfeffff             fld       xword ptr [ebp - 0x134]
004499f5  dbadfcfeffff             fld       xword ptr [ebp - 0x104]
004499fb  dec9                     fmulp     st(1)
004499fd  dbad14ffffff             fld       xword ptr [ebp - 0xec]
00449a03  dbadf0feffff             fld       xword ptr [ebp - 0x110]
00449a09  dec9                     fmulp     st(1)
00449a0b  dec1                     faddp     st(1)
00449a0d  db6dbc                   fld       xword ptr [ebp - 0x44]
00449a10  db6dd4                   fld       xword ptr [ebp - 0x2c]
00449a13  dee9                     fsubp     st(1)
00449a15  dbad08ffffff             fld       xword ptr [ebp - 0xf8]
00449a1b  dec9                     fmulp     st(1)
00449a1d  dec1                     faddp     st(1)
00449a1f  8b4524                   mov       eax, dword ptr [ebp + 0x24]
00449a22  d918                     fstp      dword ptr [eax]
00449a24  8b4520                   mov       eax, dword ptr [ebp + 0x20]
00449a27  d900                     fld       dword ptr [eax]
00449a29  d9c0                     fld       st(0)
00449a2b  d800                     fadd      dword ptr [eax]
00449a2d  8b4d24                   mov       ecx, dword ptr [ebp + 0x24]
00449a30  d809                     fmul      dword ptr [ecx]
00449a32  d919                     fstp      dword ptr [ecx]
00449a34  d8c8                     fmul      st(0)
00449a36  d918                     fstp      dword ptr [eax]
00449a38  b800000000               mov       eax, 0
00449a3d  5f                       pop       edi
00449a3e  5e                       pop       esi
00449a3f  5b                       pop       ebx
00449a40  8be5                     mov       esp, ebp
00449a42  5d                       pop       ebp
00449a43  c3                       ret
00449a44  0500000000               add       eax, 0
00449a49  8da42400000000           lea       esp, [esp]
