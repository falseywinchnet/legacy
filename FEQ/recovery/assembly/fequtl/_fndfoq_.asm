; _fndfoq_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x7ee20
0047ee20  55                       push      ebp
0047ee21  8bec                     mov       ebp, esp
0047ee23  b804000000               mov       eax, 4
0047ee28  e8d3a10600               call      0x4e9000 ; __alloca_probe
0047ee2d  53                       push      ebx
0047ee2e  56                       push      esi
0047ee2f  57                       push      edi
0047ee30  8b5d08                   mov       ebx, dword ptr [ebp + 8]
0047ee33  8b750c                   mov       esi, dword ptr [ebp + 0xc]
0047ee36  8b7d10                   mov       edi, dword ptr [ebp + 0x10]
0047ee39  d906                     fld       dword ptr [esi]
0047ee3b  d803                     fadd      dword ptr [ebx]
0047ee3d  d825b077b400             fsub      dword ptr [0xb477b0]
0047ee43  d91d8877b400             fstp      dword ptr [0xb47788]
0047ee49  68e477b400               push      0xb477e4
0047ee4e  681078b400               push      0xb47810
0047ee53  68ec77b400               push      0xb477ec
0047ee58  681478b400               push      0xb47814
0047ee5d  68dc77b400               push      0xb477dc
0047ee62  68d877b400               push      0xb477d8
0047ee67  68d477b400               push      0xb477d4
0047ee6c  68d077b400               push      0xb477d0
0047ee71  68488d5a00               push      0x5a8d48
0047ee76  68c477b400               push      0xb477c4
0047ee7b  689c77b400               push      0xb4779c
0047ee80  688877b400               push      0xb47788
0047ee85  688077b400               push      0xb47780 ; _ufcom_
0047ee8a  e841a3fcff               call      0x4491d0 ; _xlkt22_
0047ee8f  83c434                   add       esp, 0x34
0047ee92  d9050078b400             fld       dword ptr [0xb47800]
0047ee98  d80d0478b400             fmul      dword ptr [0xb47804]
0047ee9e  d80df877b400             fmul      dword ptr [0xb477f8]
0047eea4  d91dcc77b400             fstp      dword ptr [0xb477cc]
0047eeaa  d905f477b400             fld       dword ptr [0xb477f4]
0047eeb0  d80d0478b400             fmul      dword ptr [0xb47804]
0047eeb6  d805b477b400             fadd      dword ptr [0xb477b4]
0047eebc  d826                     fsub      dword ptr [esi]
0047eebe  d82b                     fsubr     dword ptr [ebx]
0047eec0  d80d0c78b400             fmul      dword ptr [0xb4780c]
0047eec6  d905cc77b400             fld       dword ptr [0xb477cc]
0047eecc  d9059c77b400             fld       dword ptr [0xb4779c]
0047eed2  d83dcc77b400             fdivr     dword ptr [0xb477cc]
0047eed8  d8c8                     fmul      st(0)
0047eeda  d80dec77b400             fmul      dword ptr [0xb477ec]
0047eee0  d82d408d5a00             fsubr     dword ptr [0x5a8d40] ; bits=0000803f, f32=1.0
0047eee6  defa                     fdivp     st(2)
0047eee8  d9c9                     fxch      st(1)
0047eeea  d9fa                     fsqrt
0047eeec  d95dfc                   fstp      dword ptr [ebp - 4]
0047eeef  d84dfc                   fmul      dword ptr [ebp - 4]
0047eef2  d91f                     fstp      dword ptr [edi]
0047eef4  b800000000               mov       eax, 0
0047eef9  5f                       pop       edi
0047eefa  5e                       pop       esi
0047eefb  5b                       pop       ebx
0047eefc  8be5                     mov       esp, ebp
0047eefe  5d                       pop       ebp
0047eeff  c3                       ret
