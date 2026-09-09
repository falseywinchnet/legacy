; _rsomy4_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x7eac0
0047eac0  55                       push      ebp
0047eac1  8bec                     mov       ebp, esp
0047eac3  8b4d08                   mov       ecx, dword ptr [ebp + 8]
0047eac6  8b01                     mov       eax, dword ptr [ecx]
0047eac8  8905c077b400             mov       dword ptr [0xb477c0], eax
0047eace  68e477b400               push      0xb477e4
0047ead3  681078b400               push      0xb47810
0047ead8  682478b400               push      0xb47824
0047eadd  681478b400               push      0xb47814
0047eae2  68f077b400               push      0xb477f0
0047eae7  68d877b400               push      0xb477d8
0047eaec  68d477b400               push      0xb477d4
0047eaf1  68ac77b400               push      0xb477ac
0047eaf6  68048d5a00               push      0x5a8d04
0047eafb  68c477b400               push      0xb477c4
0047eb00  68a077b400               push      0xb477a0
0047eb05  68c077b400               push      0xb477c0
0047eb0a  688477b400               push      0xb47784
0047eb0f  e8bca6fcff               call      0x4491d0 ; _xlkt22_
0047eb14  83c434                   add       esp, 0x34
0047eb17  d905ac77b400             fld       dword ptr [0xb477ac]
0047eb1d  d9c0                     fld       st(0)
0047eb1f  d82d2078b400             fsubr     dword ptr [0xb47820]
0047eb25  d80d0878b400             fmul      dword ptr [0xb47808]
0047eb2b  d905f877b400             fld       dword ptr [0xb477f8]
0047eb31  d80d0478b400             fmul      dword ptr [0xb47804]
0047eb37  d83d008d5a00             fdivr     dword ptr [0x5a8d00] ; bits=0000803f, f32=1.0
0047eb3d  d905a077b400             fld       dword ptr [0xb477a0]
0047eb43  d83df077b400             fdivr     dword ptr [0xb477f0]
0047eb49  dee9                     fsubp     st(1)
0047eb4b  d80d1878b400             fmul      dword ptr [0xb47818]
0047eb51  dec1                     faddp     st(1)
0047eb53  d9c9                     fxch      st(1)
0047eb55  d80d0878b400             fmul      dword ptr [0xb47808]
0047eb5b  def9                     fdivp     st(1)
0047eb5d  8be5                     mov       esp, ebp
0047eb5f  5d                       pop       ebp
0047eb60  c3                       ret
0047eb61  90                       nop
0047eb62  8da42400000000           lea       esp, [esp]
0047eb69  8da42400000000           lea       esp, [esp]
