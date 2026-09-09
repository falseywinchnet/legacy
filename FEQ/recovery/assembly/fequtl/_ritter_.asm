; _ritter_
; Original SHA-256: 031e9e753dfd66f1b7a7f160fffd9832c347dd493babe064e13e952628efe7b2
; Image RVA: 0x71820
00471820  55                       push      ebp
00471821  8bec                     mov       ebp, esp
00471823  b89c000000               mov       eax, 0x9c
00471828  e8d3770700               call      0x4e9000 ; __alloca_probe
0047182d  53                       push      ebx
0047182e  56                       push      esi
0047182f  57                       push      edi
00471830  8b4508                   mov       eax, dword ptr [ebp + 8]
00471833  8b7d0c                   mov       edi, dword ptr [ebp + 0xc]
00471836  8b7510                   mov       esi, dword ptr [ebp + 0x10]
00471839  8945a4                   mov       dword ptr [ebp - 0x5c], eax
0047183c  6a50                     push      0x50
0047183e  6898ef5900               push      0x59ef98
00471843  8d06                     lea       eax, [esi]
00471845  50                       push      eax
00471846  8d07                     lea       eax, [edi]
00471848  50                       push      eax
00471849  e892b0fdff               call      0x44c8e0 ; _inline_
0047184e  83c410                   add       esp, 0x10
00471851  6a10                     push      0x10
00471853  6a06                     push      6
00471855  6a50                     push      0x50
00471857  6810ef5900               push      0x59ef10
0047185c  68f0ef5900               push      0x59eff0
00471861  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00471864  8945a0                   mov       dword ptr [ebp - 0x60], eax
00471867  8d08                     lea       ecx, [eax]
00471869  51                       push      ecx
0047186a  6870eb5900               push      0x59eb70
0047186f  6898ef5900               push      0x59ef98
00471874  8d0e                     lea       ecx, [esi]
00471876  51                       push      ecx
00471877  e8b48efeff               call      0x45a730 ; _read_tabid_
0047187c  83c424                   add       esp, 0x24
0047187f  8b06                     mov       eax, dword ptr [esi]
00471881  89459c                   mov       dword ptr [ebp - 0x64], eax
00471884  8d0dd8ee5900             lea       ecx, [0x59eed8] ; bits=09020000, f32=7.300764999132297e-43
0047188a  8945fc                   mov       dword ptr [ebp - 4], eax
0047188d  8d55fc                   lea       edx, [ebp - 4]
00471890  895108                   mov       dword ptr [ecx + 8], edx
00471893  51                       push      ecx
00471894  e8570d0300               call      0x4a25f0 ; _jwe_isfm
00471899  83c404                   add       esp, 4
0047189c  8b0510ef5900             mov       eax, dword ptr [0x59ef10] ; bits=00000000, f32=0.0
004718a2  833c85ec5a0e0400         cmp       dword ptr [eax*4 + 0x40e5aec], 0
004718aa  7f24                     jg        0x4718d0
004718ac  8d05acee5900             lea       eax, [0x59eeac] ; bits=09020000, f32=7.300764999132297e-43
004718b2  8b4d9c                   mov       ecx, dword ptr [ebp - 0x64]
004718b5  894dfc                   mov       dword ptr [ebp - 4], ecx
004718b8  8d4dfc                   lea       ecx, [ebp - 4]
004718bb  894808                   mov       dword ptr [eax + 8], ecx
004718be  50                       push      eax
004718bf  e82c0d0300               call      0x4a25f0 ; _jwe_isfm
004718c4  83c404                   add       esp, 4
004718c7  8b45a0                   mov       eax, dword ptr [ebp - 0x60]
004718ca  c70001000000             mov       dword ptr [eax], 1
004718d0  6a50                     push      0x50
004718d2  6898ef5900               push      0x59ef98
004718d7  8d06                     lea       eax, [esi]
004718d9  50                       push      eax
004718da  8d07                     lea       eax, [edi]
004718dc  50                       push      eax
004718dd  e8feaffdff               call      0x44c8e0 ; _inline_
004718e2  83c410                   add       esp, 0x10
004718e5  6a10                     push      0x10
004718e7  6a06                     push      6
004718e9  6a50                     push      0x50
004718eb  6814ef5900               push      0x59ef14
004718f0  6800f05900               push      0x59f000
004718f5  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004718f8  894598                   mov       dword ptr [ebp - 0x68], eax
004718fb  8d08                     lea       ecx, [eax]
004718fd  51                       push      ecx
004718fe  6878eb5900               push      0x59eb78
00471903  6898ef5900               push      0x59ef98
00471908  8d0e                     lea       ecx, [esi]
0047190a  51                       push      ecx
0047190b  e8208efeff               call      0x45a730 ; _read_tabid_
00471910  83c424                   add       esp, 0x24
00471913  8b1e                     mov       ebx, dword ptr [esi]
00471915  8d0574ee5900             lea       eax, [0x59ee74] ; bits=09020000, f32=7.300764999132297e-43
0047191b  895dfc                   mov       dword ptr [ebp - 4], ebx
0047191e  8d4dfc                   lea       ecx, [ebp - 4]
00471921  894808                   mov       dword ptr [eax + 8], ecx
00471924  50                       push      eax
00471925  e8c60c0300               call      0x4a25f0 ; _jwe_isfm
0047192a  83c404                   add       esp, 4
0047192d  8b0514ef5900             mov       eax, dword ptr [0x59ef14] ; bits=00000000, f32=0.0
00471933  8b0c85ec5a0e04           mov       ecx, dword ptr [eax*4 + 0x40e5aec]
0047193a  83f900                   cmp       ecx, 0
0047193d  894d94                   mov       dword ptr [ebp - 0x6c], ecx
00471940  7f21                     jg        0x471963
00471942  8d0548ee5900             lea       eax, [0x59ee48] ; bits=09020000, f32=7.300764999132297e-43
00471948  895dfc                   mov       dword ptr [ebp - 4], ebx
0047194b  8d4dfc                   lea       ecx, [ebp - 4]
0047194e  894808                   mov       dword ptr [eax + 8], ecx
00471951  50                       push      eax
00471952  e8990c0300               call      0x4a25f0 ; _jwe_isfm
00471957  83c404                   add       esp, 4
0047195a  8b4598                   mov       eax, dword ptr [ebp - 0x68]
0047195d  c70001000000             mov       dword ptr [eax], 1
00471963  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00471966  833800                   cmp       dword ptr [eax], 0
00471969  0f8f9a040000             jg        0x471e09
0047196f  8b0510ef5900             mov       eax, dword ptr [0x59ef10] ; bits=00000000, f32=0.0
00471975  8b0c85ec5a0e04           mov       ecx, dword ptr [eax*4 + 0x40e5aec]
0047197c  890d10ef5900             mov       dword ptr [0x59ef10], ecx ; bits=00000000, f32=0.0
00471982  8b4594                   mov       eax, dword ptr [ebp - 0x6c]
00471985  890514ef5900             mov       dword ptr [0x59ef14], eax ; bits=00000000, f32=0.0
0047198b  8b0510ef5900             mov       eax, dword ptr [0x59ef10] ; bits=00000000, f32=0.0
00471991  8b0c85c8e5f400           mov       ecx, dword ptr [eax*4 + 0xf4e5c8]
00471998  83f914                   cmp       ecx, 0x14
0047199b  894d90                   mov       dword ptr [ebp - 0x70], ecx
0047199e  7c06                     jl        0x4719a6
004719a0  837d9019                 cmp       dword ptr [ebp - 0x70], 0x19
004719a4  7e21                     jle       0x4719c7
004719a6  8d0528ee5900             lea       eax, [0x59ee28] ; bits=69020000, f32=8.646011524884121e-43
004719ac  895dfc                   mov       dword ptr [ebp - 4], ebx
004719af  8d4dfc                   lea       ecx, [ebp - 4]
004719b2  894808                   mov       dword ptr [eax + 8], ecx
004719b5  50                       push      eax
004719b6  e8350c0300               call      0x4a25f0 ; _jwe_isfm
004719bb  83c404                   add       esp, 4
004719be  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004719c1  c70001000000             mov       dword ptr [eax], 1
004719c7  837d9016                 cmp       dword ptr [ebp - 0x70], 0x16
004719cb  7406                     je        0x4719d3
004719cd  837d9019                 cmp       dword ptr [ebp - 0x70], 0x19
004719d1  752d                     jne       0x471a00
004719d3  8d05fced5900             lea       eax, [0x59edfc] ; bits=09020000, f32=7.300764999132297e-43
004719d9  895dfc                   mov       dword ptr [ebp - 4], ebx
004719dc  8d4dfc                   lea       ecx, [ebp - 4]
004719df  894808                   mov       dword ptr [eax + 8], ecx
004719e2  8b4d90                   mov       ecx, dword ptr [ebp - 0x70]
004719e5  894df8                   mov       dword ptr [ebp - 8], ecx
004719e8  8d55f8                   lea       edx, [ebp - 8]
004719eb  895028                   mov       dword ptr [eax + 0x28], edx
004719ee  50                       push      eax
004719ef  e8fc0b0300               call      0x4a25f0 ; _jwe_isfm
004719f4  83c404                   add       esp, 4
004719f7  8b4514                   mov       eax, dword ptr [ebp + 0x14]
004719fa  c70001000000             mov       dword ptr [eax], 1
00471a00  8b0514ef5900             mov       eax, dword ptr [0x59ef14] ; bits=00000000, f32=0.0
00471a06  833c85c8e5f40002         cmp       dword ptr [eax*4 + 0xf4e5c8], 2
00471a0e  7421                     je        0x471a31
00471a10  8d05dced5900             lea       eax, [0x59eddc] ; bits=69020000, f32=8.646011524884121e-43
00471a16  895dfc                   mov       dword ptr [ebp - 4], ebx
00471a19  8d4dfc                   lea       ecx, [ebp - 4]
00471a1c  894808                   mov       dword ptr [eax + 8], ecx
00471a1f  50                       push      eax
00471a20  e8cb0b0300               call      0x4a25f0 ; _jwe_isfm
00471a25  83c404                   add       esp, 4
00471a28  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00471a2b  c70001000000             mov       dword ptr [eax], 1
00471a31  8b4514                   mov       eax, dword ptr [ebp + 0x14]
00471a34  833800                   cmp       dword ptr [eax], 0
00471a37  89458c                   mov       dword ptr [ebp - 0x74], eax
00471a3a  0f8fc9030000             jg        0x471e09
00471a40  8d05b0ed5900             lea       eax, [0x59edb0] ; bits=09020000, f32=7.300764999132297e-43
00471a46  895dfc                   mov       dword ptr [ebp - 4], ebx
00471a49  8d4dfc                   lea       ecx, [ebp - 4]
00471a4c  894808                   mov       dword ptr [eax + 8], ecx
00471a4f  50                       push      eax
00471a50  e89b0b0300               call      0x4a25f0 ; _jwe_isfm
00471a55  83c404                   add       esp, 4
00471a58  681cef5900               push      0x59ef1c
00471a5d  6810ef5900               push      0x59ef10
00471a62  8d06                     lea       eax, [esi]
00471a64  50                       push      eax
00471a65  8b45a4                   mov       eax, dword ptr [ebp - 0x5c]
00471a68  8d08                     lea       ecx, [eax]
00471a6a  51                       push      ecx
00471a6b  e8905efcff               call      0x437900 ; _chkcfc_
00471a70  83c410                   add       esp, 0x10
00471a73  8b458c                   mov       eax, dword ptr [ebp - 0x74]
00471a76  833800                   cmp       dword ptr [eax], 0
00471a79  0f8f8a030000             jg        0x471e09
00471a7f  8b4590                   mov       eax, dword ptr [ebp - 0x70]
00471a82  8b0c85445b5700           mov       ecx, dword ptr [eax*4 + 0x575b44]
00471a89  890d20ef5900             mov       dword ptr [0x59ef20], ecx ; bits=00000000, f32=0.0
00471a8f  8b0510ef5900             mov       eax, dword ptr [0x59ef10] ; bits=00000000, f32=0.0
00471a95  8b0c85c0e5f400           mov       ecx, dword ptr [eax*4 + 0xf4e5c0]
00471a9c  8b16                     mov       edx, dword ptr [esi]
00471a9e  895580                   mov       dword ptr [ebp - 0x80], edx
00471aa1  894588                   mov       dword ptr [ebp - 0x78], eax
00471aa4  8d0590ed5900             lea       eax, [0x59ed90] ; bits=69020000, f32=8.646011524884121e-43
00471aaa  8955fc                   mov       dword ptr [ebp - 4], edx
00471aad  894d84                   mov       dword ptr [ebp - 0x7c], ecx
00471ab0  8d4dfc                   lea       ecx, [ebp - 4]
00471ab3  894808                   mov       dword ptr [eax + 8], ecx
00471ab6  50                       push      eax
00471ab7  e8340b0300               call      0x4a25f0 ; _jwe_isfm
00471abc  83c404                   add       esp, 4
00471abf  8d0570ed5900             lea       eax, [0x59ed70] ; bits=69020000, f32=8.646011524884121e-43
00471ac5  8b4d80                   mov       ecx, dword ptr [ebp - 0x80]
00471ac8  894dfc                   mov       dword ptr [ebp - 4], ecx
00471acb  8d55fc                   lea       edx, [ebp - 4]
00471ace  895008                   mov       dword ptr [eax + 8], edx
00471ad1  50                       push      eax
00471ad2  e8190b0300               call      0x4a25f0 ; _jwe_isfm
00471ad7  83c404                   add       esp, 4
00471ada  8b4588                   mov       eax, dword ptr [ebp - 0x78]
00471add  c70485c8e5f40000000000   mov       dword ptr [eax*4 + 0xf4e5c8], 0
00471ae8  c704854ce6f40000000000   mov       dword ptr [eax*4 + 0xf4e64c], 0
00471af3  8b0510ef5900             mov       eax, dword ptr [0x59ef10] ; bits=00000000, f32=0.0
00471af9  c7048550e6f40000000000   mov       dword ptr [eax*4 + 0xf4e650], 0
00471b04  8b0510ef5900             mov       eax, dword ptr [0x59ef10] ; bits=00000000, f32=0.0
00471b0a  8d4820                   lea       ecx, [eax + 0x20]
00471b0d  8d1538ed5900             lea       edx, [0x59ed38] ; bits=09020000, f32=7.300764999132297e-43
00471b13  89857cffffff             mov       dword ptr [ebp - 0x84], eax
00471b19  8b4580                   mov       eax, dword ptr [ebp - 0x80]
00471b1c  8945fc                   mov       dword ptr [ebp - 4], eax
00471b1f  8d45fc                   lea       eax, [ebp - 4]
00471b22  894208                   mov       dword ptr [edx + 8], eax
00471b25  8d0c8dc0e5f400           lea       ecx, [ecx*4 + 0xf4e5c0]
00471b2c  894a30                   mov       dword ptr [edx + 0x30], ecx
00471b2f  52                       push      edx
00471b30  e8bb0a0300               call      0x4a25f0 ; _jwe_isfm
00471b35  83c404                   add       esp, 4
00471b38  8b0520ef5900             mov       eax, dword ptr [0x59ef20] ; bits=00000000, f32=0.0
00471b3e  8d4820                   lea       ecx, [eax + 0x20]
00471b41  d9ee                     fldz
00471b43  d9c0                     fld       st(0)
00471b45  8b55a4                   mov       edx, dword ptr [ebp - 0x5c]
00471b48  d9c1                     fld       st(1)
00471b4a  d902                     fld       dword ptr [edx]
00471b4c  d9c0                     fld       st(0)
00471b4e  d802                     fadd      dword ptr [edx]
00471b50  d9ca                     fxch      st(2)
00471b52  d9cb                     fxch      st(3)
00471b54  d9ca                     fxch      st(2)
00471b56  8b16                     mov       edx, dword ptr [esi]
00471b58  898578ffffff             mov       dword ptr [ebp - 0x88], eax
00471b5e  8b857cffffff             mov       eax, dword ptr [ebp - 0x84]
00471b64  01c1                     add       ecx, eax
00471b66  89cb                     mov       ebx, ecx
00471b68  8b8578ffffff             mov       eax, dword ptr [ebp - 0x88]
00471b6e  898574ffffff             mov       dword ptr [ebp - 0x8c], eax
00471b74  899570ffffff             mov       dword ptr [ebp - 0x90], edx
00471b7a  db7dcc                   fstp      xword ptr [ebp - 0x34]
00471b7d  db7dd8                   fstp      xword ptr [ebp - 0x28]
00471b80  d9049dc0e5f400           fld       dword ptr [ebx*4 + 0xf4e5c0]
00471b87  db7dc0                   fstp      xword ptr [ebp - 0x40]
00471b8a  d9049dc4e5f400           fld       dword ptr [ebx*4 + 0xf4e5c4]
00471b91  d9049dc8e5f400           fld       dword ptr [ebx*4 + 0xf4e5c8]
00471b98  db6dd8                   fld       xword ptr [ebp - 0x28]
00471b9b  d80c9dc8e5f400           fmul      dword ptr [ebx*4 + 0xf4e5c8]
00471ba2  d8349dc4e5f400           fdiv      dword ptr [ebx*4 + 0xf4e5c4]
00471ba9  d9fa                     fsqrt
00471bab  d95df4                   fstp      dword ptr [ebp - 0xc]
00471bae  d945f4                   fld       dword ptr [ebp - 0xc]
00471bb1  db7db4                   fstp      xword ptr [ebp - 0x4c]
00471bb4  db6dc0                   fld       xword ptr [ebp - 0x40]
00471bb7  dee3                     fsubrp    st(3)
00471bb9  db6dcc                   fld       xword ptr [ebp - 0x34]
00471bbc  decb                     fmulp     st(3)
00471bbe  db6db4                   fld       xword ptr [ebp - 0x4c]
00471bc1  dec5                     faddp     st(5)
00471bc3  d9ca                     fxch      st(2)
00471bc5  def4                     fdivrp    st(4)
00471bc7  d9cb                     fxch      st(3)
00471bc9  dec2                     faddp     st(2)
00471bcb  d9c9                     fxch      st(1)
00471bcd  db7da8                   fstp      xword ptr [ebp - 0x58]
00471bd0  8d05dcec5900             lea       eax, [0x59ecdc] ; bits=09020000, f32=7.300764999132297e-43
00471bd6  8b8d70ffffff             mov       ecx, dword ptr [ebp - 0x90]
00471bdc  894dfc                   mov       dword ptr [ebp - 4], ecx
00471bdf  8d55fc                   lea       edx, [ebp - 4]
00471be2  895008                   mov       dword ptr [eax + 8], edx
00471be5  db6dc0                   fld       xword ptr [ebp - 0x40]
00471be8  d95df4                   fstp      dword ptr [ebp - 0xc]
00471beb  8d55f4                   lea       edx, [ebp - 0xc]
00471bee  895028                   mov       dword ptr [eax + 0x28], edx
00471bf1  d9c9                     fxch      st(1)
00471bf3  d95df0                   fstp      dword ptr [ebp - 0x10]
00471bf6  8d55f0                   lea       edx, [ebp - 0x10]
00471bf9  895034                   mov       dword ptr [eax + 0x34], edx
00471bfc  d95dec                   fstp      dword ptr [ebp - 0x14]
00471bff  8d55ec                   lea       edx, [ebp - 0x14]
00471c02  895040                   mov       dword ptr [eax + 0x40], edx
00471c05  db6db4                   fld       xword ptr [ebp - 0x4c]
00471c08  d95de8                   fstp      dword ptr [ebp - 0x18]
00471c0b  8d55e8                   lea       edx, [ebp - 0x18]
00471c0e  89504c                   mov       dword ptr [eax + 0x4c], edx
00471c11  db6da8                   fld       xword ptr [ebp - 0x58]
00471c14  d95de4                   fstp      dword ptr [ebp - 0x1c]
00471c17  8d55e4                   lea       edx, [ebp - 0x1c]
00471c1a  895058                   mov       dword ptr [eax + 0x58], edx
00471c1d  50                       push      eax
00471c1e  e8cd090300               call      0x4a25f0 ; _jwe_isfm
00471c23  83c404                   add       esp, 4
00471c26  db6db4                   fld       xword ptr [ebp - 0x4c]
00471c29  db6dc0                   fld       xword ptr [ebp - 0x40]
00471c2c  db6da8                   fld       xword ptr [ebp - 0x58]
00471c2f  db6db4                   fld       xword ptr [ebp - 0x4c]
00471c32  d91c9dcce5f400           fstp      dword ptr [ebx*4 + 0xf4e5cc]
00471c39  db6da8                   fld       xword ptr [ebp - 0x58]
00471c3c  d91c9dd0e5f400           fstp      dword ptr [ebx*4 + 0xf4e5d0]
00471c43  db6dd8                   fld       xword ptr [ebp - 0x28]
00471c46  db6dcc                   fld       xword ptr [ebp - 0x34]
00471c49  d9ca                     fxch      st(2)
00471c4b  d9cb                     fxch      st(3)
00471c4d  d9ca                     fxch      st(2)
00471c4f  039d74ffffff             add       ebx, dword ptr [ebp - 0x8c]
00471c55  8b4584                   mov       eax, dword ptr [ebp - 0x7c]
00471c58  39c3                     cmp       ebx, eax
00471c5a  0f8e1affffff             jle       0x471b7a
00471c60  ddd8                     fstp      st(0)
00471c62  ddd8                     fstp      st(0)
00471c64  ddd8                     fstp      st(0)
00471c66  ddd8                     fstp      st(0)
00471c68  ddd8                     fstp      st(0)
00471c6a  6a50                     push      0x50
00471c6c  6898ef5900               push      0x59ef98
00471c71  8d06                     lea       eax, [esi]
00471c73  50                       push      eax
00471c74  8d07                     lea       eax, [edi]
00471c76  50                       push      eax
00471c77  e864acfdff               call      0x44c8e0 ; _inline_
00471c7c  83c410                   add       esp, 0x10
00471c7f  68bcec5900               push      0x59ecbc
00471c84  e8c7fe0200               call      0x4a1b50 ; _jwe_iinf
00471c89  83c404                   add       esp, 4
00471c8c  85c0                     test      eax, eax
00471c8e  0f8536010000             jne       0x471dca
00471c94  68b0ec5900               push      0x59ecb0
00471c99  e8b2fe0200               call      0x4a1b50 ; _jwe_iinf
00471c9e  83c404                   add       esp, 4
00471ca1  85c0                     test      eax, eax
00471ca3  0f8521010000             jne       0x471dca
00471ca9  8b06                     mov       eax, dword ptr [esi]
00471cab  8d0d84ec5900             lea       ecx, [0x59ec84] ; bits=09020000, f32=7.300764999132297e-43
00471cb1  8945fc                   mov       dword ptr [ebp - 4], eax
00471cb4  8d45fc                   lea       eax, [ebp - 4]
00471cb7  894108                   mov       dword ptr [ecx + 8], eax
00471cba  51                       push      ecx
00471cbb  e830090300               call      0x4a25f0 ; _jwe_isfm
00471cc0  83c404                   add       esp, 4
00471cc3  6a50                     push      0x50
00471cc5  6898ef5900               push      0x59ef98
00471cca  8d06                     lea       eax, [esi]
00471ccc  50                       push      eax
00471ccd  8d07                     lea       eax, [edi]
00471ccf  50                       push      eax
00471cd0  e80bacfdff               call      0x44c8e0 ; _inline_
00471cd5  83c410                   add       esp, 0x10
00471cd8  6864ec5900               push      0x59ec64
00471cdd  e86efe0200               call      0x4a1b50 ; _jwe_iinf
00471ce2  83c404                   add       esp, 4
00471ce5  85c0                     test      eax, eax
00471ce7  0f85dd000000             jne       0x471dca
00471ced  684cec5900               push      0x59ec4c
00471cf2  e859fe0200               call      0x4a1b50 ; _jwe_iinf
00471cf7  83c404                   add       esp, 4
00471cfa  85c0                     test      eax, eax
00471cfc  0f85c8000000             jne       0x471dca
00471d02  d90540ef5900             fld       dword ptr [0x59ef40] ; bits=00000000, f32=0.0
00471d08  d81d24ea5900             fcomp     dword ptr [0x59ea24] ; bits=00000000, f32=0.0
00471d0e  dfe0                     fnstsw    ax
00471d10  9e                       sahf
00471d11  0f8a06000000             jp        0x471d1d
00471d17  0f86ec000000             jbe       0x471e09
00471d1d  6830ef5900               push      0x59ef30
00471d22  6844ef5900               push      0x59ef44
00471d27  682cef5900               push      0x59ef2c
00471d2c  6840ef5900               push      0x59ef40
00471d31  6814ef5900               push      0x59ef14
00471d36  6820ef5900               push      0x59ef20
00471d3b  6810ef5900               push      0x59ef10
00471d40  8d06                     lea       eax, [esi]
00471d42  50                       push      eax
00471d43  e8c8f9ffff               call      0x471710 ; _fndrit_
00471d48  83c420                   add       esp, 0x20
00471d4b  8b06                     mov       eax, dword ptr [esi]
00471d4d  8b0d40ef5900             mov       ecx, dword ptr [0x59ef40] ; bits=00000000, f32=0.0
00471d53  8b152cef5900             mov       edx, dword ptr [0x59ef2c] ; bits=00000000, f32=0.0
00471d59  8b1d44ef5900             mov       ebx, dword ptr [0x59ef44] ; bits=00000000, f32=0.0
00471d5f  89856cffffff             mov       dword ptr [ebp - 0x94], eax
00471d65  8b0530ef5900             mov       eax, dword ptr [0x59ef30] ; bits=00000000, f32=0.0
00471d6b  898d68ffffff             mov       dword ptr [ebp - 0x98], ecx
00471d71  8d0dfceb5900             lea       ecx, [0x59ebfc] ; bits=09020000, f32=7.300764999132297e-43
00471d77  899564ffffff             mov       dword ptr [ebp - 0x9c], edx
00471d7d  8b956cffffff             mov       edx, dword ptr [ebp - 0x94]
00471d83  8955fc                   mov       dword ptr [ebp - 4], edx
00471d86  8d55fc                   lea       edx, [ebp - 4]
00471d89  895108                   mov       dword ptr [ecx + 8], edx
00471d8c  8b9568ffffff             mov       edx, dword ptr [ebp - 0x98]
00471d92  8955f4                   mov       dword ptr [ebp - 0xc], edx
00471d95  8d55f4                   lea       edx, [ebp - 0xc]
00471d98  895128                   mov       dword ptr [ecx + 0x28], edx
00471d9b  8b9564ffffff             mov       edx, dword ptr [ebp - 0x9c]
00471da1  8955f0                   mov       dword ptr [ebp - 0x10], edx
00471da4  8d55f0                   lea       edx, [ebp - 0x10]
00471da7  895134                   mov       dword ptr [ecx + 0x34], edx
00471daa  895dec                   mov       dword ptr [ebp - 0x14], ebx
00471dad  8d55ec                   lea       edx, [ebp - 0x14]
00471db0  895140                   mov       dword ptr [ecx + 0x40], edx
00471db3  8945e8                   mov       dword ptr [ebp - 0x18], eax
00471db6  8d45e8                   lea       eax, [ebp - 0x18]
00471db9  89414c                   mov       dword ptr [ecx + 0x4c], eax
00471dbc  51                       push      ecx
00471dbd  e82e080300               call      0x4a25f0 ; _jwe_isfm
00471dc2  83c404                   add       esp, 4
00471dc5  e9f9feffff               jmp       0x471cc3
00471dca  8b1e                     mov       ebx, dword ptr [esi]
00471dcc  8d05d0eb5900             lea       eax, [0x59ebd0] ; bits=09820000, f32=4.664782457890884e-41
00471dd2  895dfc                   mov       dword ptr [ebp - 4], ebx
00471dd5  8d4dfc                   lea       ecx, [ebp - 4]
00471dd8  894808                   mov       dword ptr [eax + 8], ecx
00471ddb  50                       push      eax
00471ddc  e89f100300               call      0x4a2e80 ; _jwe_ilst
00471de1  83c404                   add       esp, 4
00471de4  8d05a4eb5900             lea       eax, [0x59eba4] ; bits=09820000, f32=4.664782457890884e-41
00471dea  895dfc                   mov       dword ptr [ebp - 4], ebx
00471ded  8d4dfc                   lea       ecx, [ebp - 4]
00471df0  894808                   mov       dword ptr [eax + 8], ecx
00471df3  50                       push      eax
00471df4  e887100300               call      0x4a2e80 ; _jwe_ilst
00471df9  83c404                   add       esp, 4
00471dfc  6880eb5900               push      0x59eb80
00471e01  e83a160300               call      0x4a3440 ; _jwe_xstp
00471e06  83c404                   add       esp, 4
00471e09  b800000000               mov       eax, 0
00471e0e  5f                       pop       edi
00471e0f  5e                       pop       esi
00471e10  5b                       pop       ebx
00471e11  8be5                     mov       esp, ebp
00471e13  5d                       pop       ebp
00471e14  c3                       ret
00471e15  8d642400                 lea       esp, [esp]
00471e19  8da42400000000           lea       esp, [esp]
