; _rsomy3_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x7ea00
0047ea00  55                       push      ebp
0047ea01  8bec                     mov       ebp, esp
0047ea03  53                       push      ebx
0047ea04  8b5d08                   mov       ebx, dword ptr [ebp + 8]
0047ea07  8b03                     mov       eax, dword ptr [ebx]
0047ea09  8905c077b400             mov       dword ptr [0xb477c0], eax
0047ea0f  682078b400               push      0xb47820
0047ea14  68c077b400               push      0xb477c0
0047ea19  688477b400               push      0xb47784
0047ea1e  e83d98ffff               call      0x478260 ; _lktj_
0047ea23  83c40c                   add       esp, 0xc
0047ea26  d905cc77b400             fld       dword ptr [0xb477cc]
0047ea2c  d9c0                     fld       st(0)
0047ea2e  d80dcc77b400             fmul      dword ptr [0xb477cc]
0047ea34  d9058877b400             fld       dword ptr [0xb47788]
0047ea3a  d805b077b400             fadd      dword ptr [0xb477b0]
0047ea40  d823                     fsub      dword ptr [ebx]
0047ea42  d825b877b400             fsub      dword ptr [0xb477b8]
0047ea48  d80d0c78b400             fmul      dword ptr [0xb4780c]
0047ea4e  dec9                     fmulp     st(1)
0047ea50  d9c9                     fxch      st(1)
0047ea52  d8359c77b400             fdiv      dword ptr [0xb4779c]
0047ea58  d8c8                     fmul      st(0)
0047ea5a  d80dec77b400             fmul      dword ptr [0xb477ec]
0047ea60  d82df88c5a00             fsubr     dword ptr [0x5a8cf8] ; bits=0000803f, f32=1.0
0047ea66  def9                     fdivp     st(1)
0047ea68  d91d1878b400             fstp      dword ptr [0xb47818]
0047ea6e  d905ac77b400             fld       dword ptr [0xb477ac]
0047ea74  d9c0                     fld       st(0)
0047ea76  d82d2078b400             fsubr     dword ptr [0xb47820]
0047ea7c  d80d0878b400             fmul      dword ptr [0xb47808]
0047ea82  d905f877b400             fld       dword ptr [0xb477f8]
0047ea88  d80d0478b400             fmul      dword ptr [0xb47804]
0047ea8e  d83df88c5a00             fdivr     dword ptr [0x5a8cf8] ; bits=0000803f, f32=1.0
0047ea94  d905a077b400             fld       dword ptr [0xb477a0]
0047ea9a  d83df077b400             fdivr     dword ptr [0xb477f0]
0047eaa0  dee9                     fsubp     st(1)
0047eaa2  d80d1878b400             fmul      dword ptr [0xb47818]
0047eaa8  dec1                     faddp     st(1)
0047eaaa  d9c9                     fxch      st(1)
0047eaac  d80d0878b400             fmul      dword ptr [0xb47808]
0047eab2  def9                     fdivp     st(1)
0047eab4  5b                       pop       ebx
0047eab5  8be5                     mov       esp, ebp
0047eab7  5d                       pop       ebp
0047eab8  c3                       ret
0047eab9  8da42400000000           lea       esp, [esp]
