; _rswmy3_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x7eb70
0047eb70  55                       push      ebp
0047eb71  8bec                     mov       ebp, esp
0047eb73  53                       push      ebx
0047eb74  8b5d08                   mov       ebx, dword ptr [ebp + 8]
0047eb77  8b03                     mov       eax, dword ptr [ebx]
0047eb79  8905c077b400             mov       dword ptr [0xb477c0], eax
0047eb7f  682078b400               push      0xb47820
0047eb84  68c077b400               push      0xb477c0
0047eb89  688477b400               push      0xb47784
0047eb8e  e8cd96ffff               call      0x478260 ; _lktj_
0047eb93  83c40c                   add       esp, 0xc
0047eb96  d9058877b400             fld       dword ptr [0xb47788]
0047eb9c  d805b077b400             fadd      dword ptr [0xb477b0]
0047eba2  d825b877b400             fsub      dword ptr [0xb477b8]
0047eba8  d823                     fsub      dword ptr [ebx]
0047ebaa  d80d0c78b400             fmul      dword ptr [0xb4780c]
0047ebb0  d905fc77b400             fld       dword ptr [0xb477fc]
0047ebb6  d9c0                     fld       st(0)
0047ebb8  d80d0078b400             fmul      dword ptr [0xb47800]
0047ebbe  d9051c78b400             fld       dword ptr [0xb4781c]
0047ebc4  d803                     fadd      dword ptr [ebx]
0047ebc6  dcc9                     fmul      st(1), st(0)
0047ebc8  d9c9                     fxch      st(1)
0047ebca  d8c8                     fmul      st(0)
0047ebcc  d83d088d5a00             fdivr     dword ptr [0x5a8d08] ; bits=0000803f, f32=1.0
0047ebd2  d9059c77b400             fld       dword ptr [0xb4779c]
0047ebd8  d80d9c77b400             fmul      dword ptr [0xb4779c]
0047ebde  d83dec77b400             fdivr     dword ptr [0xb477ec]
0047ebe4  dee9                     fsubp     st(1)
0047ebe6  defb                     fdivp     st(3)
0047ebe8  d9ca                     fxch      st(2)
0047ebea  d91d1878b400             fstp      dword ptr [0xb47818]
0047ebf0  d905ac77b400             fld       dword ptr [0xb477ac]
0047ebf6  d9c0                     fld       st(0)
0047ebf8  d82d2078b400             fsubr     dword ptr [0xb47820]
0047ebfe  d80d0878b400             fmul      dword ptr [0xb47808]
0047ec04  d9cb                     fxch      st(3)
0047ec06  deca                     fmulp     st(2)
0047ec08  d9c9                     fxch      st(1)
0047ec0a  d83d088d5a00             fdivr     dword ptr [0x5a8d08] ; bits=0000803f, f32=1.0
0047ec10  d905a077b400             fld       dword ptr [0xb477a0]
0047ec16  d83df077b400             fdivr     dword ptr [0xb477f0]
0047ec1c  dee9                     fsubp     st(1)
0047ec1e  d80d1878b400             fmul      dword ptr [0xb47818]
0047ec24  dec2                     faddp     st(2)
0047ec26  d80d0878b400             fmul      dword ptr [0xb47808]
0047ec2c  def9                     fdivp     st(1)
0047ec2e  5b                       pop       ebx
0047ec2f  8be5                     mov       esp, ebp
0047ec31  5d                       pop       ebp
0047ec32  c3                       ret
0047ec33  8d9b00000000             lea       ebx, [ebx]
0047ec39  8da42400000000           lea       esp, [esp]
