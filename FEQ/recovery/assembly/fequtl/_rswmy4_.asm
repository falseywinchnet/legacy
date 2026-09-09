; _rswmy4_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x7ec40
0047ec40  55                       push      ebp
0047ec41  8bec                     mov       ebp, esp
0047ec43  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0047ec46  8b01                     mov       eax, dword ptr [ecx]
0047ec48  8905c077b400             mov       dword ptr [0xb477c0], eax
0047ec4e  68e477b400               push      0xb477e4
0047ec53  681078b400               push      0xb47810
0047ec58  682478b400               push      0xb47824
0047ec5d  681478b400               push      0xb47814
0047ec62  68f077b400               push      0xb477f0
0047ec67  68d877b400               push      0xb477d8
0047ec6c  68d477b400               push      0xb477d4
0047ec71  68ac77b400               push      0xb477ac
0047ec76  68148d5a00               push      0x5a8d14
0047ec7b  68c477b400               push      0xb477c4
0047ec80  68a077b400               push      0xb477a0
0047ec85  68c077b400               push      0xb477c0
0047ec8a  688477b400               push      0xb47784
0047ec8f  e83ca5fcff               call      0x4491d0 ; _xlkt22_
0047ec94  83c434                   add       esp, 0x34
0047ec97  d905ac77b400             fld       dword ptr [0xb477ac]
0047ec9d  d9c0                     fld       st(0)
0047ec9f  d82d2078b400             fsubr     dword ptr [0xb47820]
0047eca5  d80d0878b400             fmul      dword ptr [0xb47808]
0047ecab  d9059077b400             fld       dword ptr [0xb47790]
0047ecb1  d8051c78b400             fadd      dword ptr [0xb4781c]
0047ecb7  d80dfc77b400             fmul      dword ptr [0xb477fc]
0047ecbd  d83d108d5a00             fdivr     dword ptr [0x5a8d10] ; bits=0000803f, f32=1.0
0047ecc3  d905a077b400             fld       dword ptr [0xb477a0]
0047ecc9  d83df077b400             fdivr     dword ptr [0xb477f0]
0047eccf  dee9                     fsubp     st(1)
0047ecd1  d80d1878b400             fmul      dword ptr [0xb47818]
0047ecd7  dec1                     faddp     st(1)
0047ecd9  d9c9                     fxch      st(1)
0047ecdb  d80d0878b400             fmul      dword ptr [0xb47808]
0047ece1  def9                     fdivp     st(1)
0047ece3  8be5                     mov       esp, ebp
0047ece5  5d                       pop       ebp
0047ece6  c3                       ret
0047ece7  8bff                     mov       edi, edi
0047ece9  8da42400000000           lea       esp, [esp]
