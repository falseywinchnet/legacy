; _sfpsbm_
; Original SHA-256: 16e46628e3d55f654e5b39ceecc621bcfcec86a0b881197a6e5f5fd17ec42399
; Image RVA: 0x92070
00492070  81ecc0020000             sub       esp, 0x2c0
00492076  55                       push      ebp
00492077  53                       push      ebx
00492078  56                       push      esi
00492079  57                       push      edi
0049207a  8b8424d4020000           mov       eax, dword ptr [esp + 0x2d4]
00492081  8b8c24d8020000           mov       ecx, dword ptr [esp + 0x2d8]
00492088  8b9424dc020000           mov       edx, dword ptr [esp + 0x2dc]
0049208f  8944246c                 mov       dword ptr [esp + 0x6c], eax
00492093  894c2468                 mov       dword ptr [esp + 0x68], ecx
00492097  89542464                 mov       dword ptr [esp + 0x64], edx
0049209b  d9ec                     fldlg2
0049209d  8b8424ec020000           mov       eax, dword ptr [esp + 0x2ec]
004920a4  89442460                 mov       dword ptr [esp + 0x60], eax
004920a8  d900                     fld       dword ptr [eax]
004920aa  d9f1                     fyl2x
004920ac  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
004920b3  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
004920ba  51                       push      ecx
004920bb  e8c08e0200               call      0x4baf80 ; _f_anint
004920c0  83c404                   add       esp, 4
004920c3  d9bc24ca020000           fnstcw    word ptr [esp + 0x2ca]
004920ca  668b8424ca020000         mov       ax, word ptr [esp + 0x2ca]
004920d2  660d000c                 or        ax, 0xc00
004920d6  66898424c8020000         mov       word ptr [esp + 0x2c8], ax
004920de  d9ac24c8020000           fldcw     word ptr [esp + 0x2c8]
004920e5  dfbc24c0020000           fistp     qword ptr [esp + 0x2c0]
004920ec  d9ac24ca020000           fldcw     word ptr [esp + 0x2ca]
004920f3  8b8424c0020000           mov       eax, dword ptr [esp + 0x2c0]
004920fa  8944245c                 mov       dword ptr [esp + 0x5c], eax
004920fe  8b8c24f8020000           mov       ecx, dword ptr [esp + 0x2f8]
00492105  8b09                     mov       ecx, dword ptr [ecx]
00492107  890d30285700             mov       dword ptr [0x572830], ecx ; bits=00000000, f32=0.0
0049210d  8b8c24e0020000           mov       ecx, dword ptr [esp + 0x2e0]
00492114  894c2458                 mov       dword ptr [esp + 0x58], ecx
00492118  8b11                     mov       edx, dword ptr [ecx]
0049211a  8b14953cd4e201           mov       edx, dword ptr [edx*4 + 0x1e2d43c]
00492121  8915c4275700             mov       dword ptr [0x5727c4], edx ; bits=00000000, f32=0.0
00492127  68c4275700               push      0x5727c4
0049212c  e8af23faff               call      0x4344e0 ; _gettbn_
00492131  83c404                   add       esp, 4
00492134  898424bc020000           mov       dword ptr [esp + 0x2bc], eax
0049213b  8d8424bc020000           lea       eax, [esp + 0x2bc]
00492142  50                       push      eax
00492143  6a10                     push      0x10
00492145  6860285700               push      0x572860
0049214a  e821920000               call      0x49b370 ; _get_tabid_
0049214f  83c40c                   add       esp, 0xc
00492152  8d0550285700             lea       eax, [0x572850] ; bits=00000000, f32=0.0
00492158  8d0d60285700             lea       ecx, [0x572860] ; bits=00000000, f32=0.0
0049215e  8a11                     mov       dl, byte ptr [ecx]
00492160  8810                     mov       byte ptr [eax], dl
00492162  8a5101                   mov       dl, byte ptr [ecx + 1]
00492165  885001                   mov       byte ptr [eax + 1], dl
00492168  8a5102                   mov       dl, byte ptr [ecx + 2]
0049216b  885002                   mov       byte ptr [eax + 2], dl
0049216e  8a5103                   mov       dl, byte ptr [ecx + 3]
00492171  885003                   mov       byte ptr [eax + 3], dl
00492174  8a5104                   mov       dl, byte ptr [ecx + 4]
00492177  885004                   mov       byte ptr [eax + 4], dl
0049217a  8a5105                   mov       dl, byte ptr [ecx + 5]
0049217d  885005                   mov       byte ptr [eax + 5], dl
00492180  8a5106                   mov       dl, byte ptr [ecx + 6]
00492183  885006                   mov       byte ptr [eax + 6], dl
00492186  8a5107                   mov       dl, byte ptr [ecx + 7]
00492189  885007                   mov       byte ptr [eax + 7], dl
0049218c  8a5108                   mov       dl, byte ptr [ecx + 8]
0049218f  885008                   mov       byte ptr [eax + 8], dl
00492192  8a5109                   mov       dl, byte ptr [ecx + 9]
00492195  885009                   mov       byte ptr [eax + 9], dl
00492198  8a510a                   mov       dl, byte ptr [ecx + 0xa]
0049219b  88500a                   mov       byte ptr [eax + 0xa], dl
0049219e  8a510b                   mov       dl, byte ptr [ecx + 0xb]
004921a1  88500b                   mov       byte ptr [eax + 0xb], dl
004921a4  8a510c                   mov       dl, byte ptr [ecx + 0xc]
004921a7  88500c                   mov       byte ptr [eax + 0xc], dl
004921aa  8a510d                   mov       dl, byte ptr [ecx + 0xd]
004921ad  88500d                   mov       byte ptr [eax + 0xd], dl
004921b0  8a510e                   mov       dl, byte ptr [ecx + 0xe]
004921b3  88500e                   mov       byte ptr [eax + 0xe], dl
004921b6  8a510f                   mov       dl, byte ptr [ecx + 0xf]
004921b9  88500f                   mov       byte ptr [eax + 0xf], dl
004921bc  8b442458                 mov       eax, dword ptr [esp + 0x58]
004921c0  8b28                     mov       ebp, dword ptr [eax]
004921c2  d904ade4b8f101           fld       dword ptr [ebp*4 + 0x1f1b8e4]
004921c9  dbbc2480020000           fstp      xword ptr [esp + 0x280]
004921d0  d904ade4c5f301           fld       dword ptr [ebp*4 + 0x1f3c5e4]
004921d7  dbbc2474020000           fstp      xword ptr [esp + 0x274]
004921de  d90530285700             fld       dword ptr [0x572830] ; bits=00000000, f32=0.0
004921e4  d9ee                     fldz
004921e6  dff1                     fcompi    st(1)
004921e8  ddd8                     fstp      st(0)
004921ea  0f8a51000000             jp        0x492241
004921f0  724f                     jb        0x492241
004921f2  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004921f6  8b08                     mov       ecx, dword ptr [eax]
004921f8  8b442468                 mov       eax, dword ptr [esp + 0x68]
004921fc  8b10                     mov       edx, dword ptr [eax]
004921fe  8d0598275700             lea       eax, [0x572798] ; bits=09020000, f32=7.300764999132297e-43
00492204  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
0049220b  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
00492212  894808                   mov       dword ptr [eax + 8], ecx
00492215  899424b8020000           mov       dword ptr [esp + 0x2b8], edx
0049221c  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
00492223  894828                   mov       dword ptr [eax + 0x28], ecx
00492226  50                       push      eax
00492227  e894a90200               call      0x4bcbc0 ; _jwe_isfm
0049222c  83c404                   add       esp, 4
0049222f  8b842408030000           mov       eax, dword ptr [esp + 0x308]
00492236  c70001000000             mov       dword ptr [eax], 1
0049223c  e9c4150000               jmp       0x493805
00492241  8b0cada428ef01           mov       ecx, dword ptr [ebp*4 + 0x1ef28a4]
00492248  890d18285700             mov       dword ptr [0x572818], ecx ; bits=00000000, f32=0.0
0049224e  890cade4abef01           mov       dword ptr [ebp*4 + 0x1efabe4], ecx
00492255  8b0d30285700             mov       ecx, dword ptr [0x572830] ; bits=00000000, f32=0.0
0049225b  890cad243cf201           mov       dword ptr [ebp*4 + 0x1f23c24], ecx
00492262  68e8275700               push      0x5727e8
00492267  68e0275700               push      0x5727e0
0049226c  68f8275700               push      0x5727f8
00492271  6810285700               push      0x572810
00492276  6800285700               push      0x572800
0049227b  6824285700               push      0x572824
00492280  68d8275700               push      0x5727d8
00492285  6830285700               push      0x572830
0049228a  68c4275700               push      0x5727c4
0049228f  e85c85faff               call      0x43a7f0 ; _xlkt20_
00492294  83c424                   add       esp, 0x24
00492297  8b442458                 mov       eax, dword ptr [esp + 0x58]
0049229b  8b08                     mov       ecx, dword ptr [eax]
0049229d  8b0530285700             mov       eax, dword ptr [0x572830] ; bits=00000000, f32=0.0
004922a3  89048d243cf201           mov       dword ptr [ecx*4 + 0x1f23c24], eax
004922aa  89048d64bff201           mov       dword ptr [ecx*4 + 0x1f2bf64], eax
004922b1  8b2dd8275700             mov       ebp, dword ptr [0x5727d8] ; bits=00000000, f32=0.0
004922b7  892c8da401e901           mov       dword ptr [ecx*4 + 0x1e901a4], ebp
004922be  892c8de484e901           mov       dword ptr [ecx*4 + 0x1e984e4], ebp
004922c5  d90518285700             fld       dword ptr [0x572818] ; bits=00000000, f32=0.0
004922cb  d905d8275700             fld       dword ptr [0x5727d8] ; bits=00000000, f32=0.0
004922d1  d9c0                     fld       st(0)
004922d3  d83d18285700             fdivr     dword ptr [0x572818] ; bits=00000000, f32=0.0
004922d9  dbbc2468020000           fstp      xword ptr [esp + 0x268]
004922e0  8b1524285700             mov       edx, dword ptr [0x572824] ; bits=00000000, f32=0.0
004922e6  8954244c                 mov       dword ptr [esp + 0x4c], edx
004922ea  89148d64b2f001           mov       dword ptr [ecx*4 + 0x1f0b264], edx
004922f1  89148da435f101           mov       dword ptr [ecx*4 + 0x1f135a4], edx
004922f8  8b1d10285700             mov       ebx, dword ptr [0x572810] ; bits=00000000, f32=0.0
004922fe  891c8d2415ec01           mov       dword ptr [ecx*4 + 0x1ec1524], ebx
00492305  891c8d6498ec01           mov       dword ptr [ecx*4 + 0x1ec9864], ebx
0049230c  8b1de0275700             mov       ebx, dword ptr [0x5727e0] ; bits=00000000, f32=0.0
00492312  891c8d2408ea01           mov       dword ptr [ecx*4 + 0x1ea0824], ebx
00492319  891c8d648bea01           mov       dword ptr [ecx*4 + 0x1ea8b64], ebx
00492320  dbac2474020000           fld       xword ptr [esp + 0x274]
00492327  d80530285700             fadd      dword ptr [0x572830] ; bits=00000000, f32=0.0
0049232d  dbbc245c020000           fstp      xword ptr [esp + 0x25c]
00492334  8b4c2460                 mov       ecx, dword ptr [esp + 0x60]
00492338  dbac2480020000           fld       xword ptr [esp + 0x280]
0049233f  d831                     fdiv      dword ptr [ecx]
00492341  dbbc2450020000           fstp      xword ptr [esp + 0x250]
00492348  d9c9                     fxch      st(1)
0049234a  d8c8                     fmul      st(0)
0049234c  d80d24285700             fmul      dword ptr [0x572824] ; bits=00000000, f32=0.0
00492352  d9c1                     fld       st(1)
00492354  d8c8                     fmul      st(0)
00492356  deca                     fmulp     st(2)
00492358  8b8c24f0020000           mov       ecx, dword ptr [esp + 0x2f0]
0049235f  d9c9                     fxch      st(1)
00492361  d809                     fmul      dword ptr [ecx]
00492363  def9                     fdivp     st(1)
00492365  dbbc2444020000           fstp      xword ptr [esp + 0x244]
0049236c  6a07                     push      7
0049236e  6840285700               push      0x572840
00492373  6830285700               push      0x572830
00492378  e843fcfaff               call      0x441fc0 ; _var_decimal_
0049237d  83c40c                   add       esp, 0xc
00492380  6a08                     push      8
00492382  6848285700               push      0x572848
00492387  6818285700               push      0x572818
0049238c  e82ffcfaff               call      0x441fc0 ; _var_decimal_
00492391  83c40c                   add       esp, 0xc
00492394  8b842404030000           mov       eax, dword ptr [esp + 0x304]
0049239b  dbac245c020000           fld       xword ptr [esp + 0x25c]
004923a2  d800                     fadd      dword ptr [eax]
004923a4  dbbc2438020000           fstp      xword ptr [esp + 0x238]
004923ab  837c245c04               cmp       dword ptr [esp + 0x5c], 4
004923b0  730d                     jae       0x4923bf
004923b2  8b44245c                 mov       eax, dword ptr [esp + 0x5c]
004923b6  8b0c85782a5700           mov       ecx, dword ptr [eax*4 + 0x572a78]
004923bd  ffe1                     jmp       ecx
004923bf  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004923c3  8b08                     mov       ecx, dword ptr [eax]
004923c5  8b15d8275700             mov       edx, dword ptr [0x5727d8] ; bits=00000000, f32=0.0
004923cb  8b1d24285700             mov       ebx, dword ptr [0x572824] ; bits=00000000, f32=0.0
004923d1  8d35e8265700             lea       esi, [0x5726e8] ; bits=09020000, f32=7.300764999132297e-43
004923d7  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
004923de  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
004923e5  894e08                   mov       dword ptr [esi + 8], ecx
004923e8  dbac2450020000           fld       xword ptr [esp + 0x250]
004923ef  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
004923f6  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
004923fd  894e28                   mov       dword ptr [esi + 0x28], ecx
00492400  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
00492407  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
0049240e  894e58                   mov       dword ptr [esi + 0x58], ecx
00492411  899c24b0020000           mov       dword ptr [esp + 0x2b0], ebx
00492418  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
0049241f  894e64                   mov       dword ptr [esi + 0x64], ecx
00492422  dbac2438020000           fld       xword ptr [esp + 0x238]
00492429  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
00492430  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
00492437  898e88000000             mov       dword ptr [esi + 0x88], ecx
0049243d  dbac2444020000           fld       xword ptr [esp + 0x244]
00492444  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
0049244b  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
00492452  898ea0000000             mov       dword ptr [esi + 0xa0], ecx
00492458  56                       push      esi
00492459  e862a70200               call      0x4bcbc0 ; _jwe_isfm
0049245e  83c404                   add       esp, 4
00492461  e97d020000               jmp       0x4926e3
00492466  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
0049246a  8b08                     mov       ecx, dword ptr [eax]
0049246c  89ea                     mov       edx, ebp
0049246e  8b5c244c                 mov       ebx, dword ptr [esp + 0x4c]
00492472  8d3538265700             lea       esi, [0x572638] ; bits=09020000, f32=7.300764999132297e-43
00492478  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
0049247f  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
00492486  894e08                   mov       dword ptr [esi + 8], ecx
00492489  dbac2450020000           fld       xword ptr [esp + 0x250]
00492490  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
00492497  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
0049249e  894e28                   mov       dword ptr [esi + 0x28], ecx
004924a1  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
004924a8  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
004924af  894e58                   mov       dword ptr [esi + 0x58], ecx
004924b2  899c24b0020000           mov       dword ptr [esp + 0x2b0], ebx
004924b9  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
004924c0  894e64                   mov       dword ptr [esi + 0x64], ecx
004924c3  dbac2438020000           fld       xword ptr [esp + 0x238]
004924ca  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
004924d1  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
004924d8  898e88000000             mov       dword ptr [esi + 0x88], ecx
004924de  dbac2444020000           fld       xword ptr [esp + 0x244]
004924e5  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
004924ec  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
004924f3  898ea0000000             mov       dword ptr [esi + 0xa0], ecx
004924f9  56                       push      esi
004924fa  e8c1a60200               call      0x4bcbc0 ; _jwe_isfm
004924ff  83c404                   add       esp, 4
00492502  e9dc010000               jmp       0x4926e3
00492507  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
0049250b  8b08                     mov       ecx, dword ptr [eax]
0049250d  89ea                     mov       edx, ebp
0049250f  8b5c244c                 mov       ebx, dword ptr [esp + 0x4c]
00492513  8d3588255700             lea       esi, [0x572588] ; bits=09020000, f32=7.300764999132297e-43
00492519  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
00492520  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
00492527  894e08                   mov       dword ptr [esi + 8], ecx
0049252a  dbac2450020000           fld       xword ptr [esp + 0x250]
00492531  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
00492538  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
0049253f  894e28                   mov       dword ptr [esi + 0x28], ecx
00492542  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
00492549  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
00492550  894e58                   mov       dword ptr [esi + 0x58], ecx
00492553  899c24b0020000           mov       dword ptr [esp + 0x2b0], ebx
0049255a  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
00492561  894e64                   mov       dword ptr [esi + 0x64], ecx
00492564  dbac2438020000           fld       xword ptr [esp + 0x238]
0049256b  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
00492572  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
00492579  898e88000000             mov       dword ptr [esi + 0x88], ecx
0049257f  dbac2444020000           fld       xword ptr [esp + 0x244]
00492586  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
0049258d  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
00492594  898ea0000000             mov       dword ptr [esi + 0xa0], ecx
0049259a  56                       push      esi
0049259b  e820a60200               call      0x4bcbc0 ; _jwe_isfm
004925a0  83c404                   add       esp, 4
004925a3  e93b010000               jmp       0x4926e3
004925a8  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004925ac  8b08                     mov       ecx, dword ptr [eax]
004925ae  89ea                     mov       edx, ebp
004925b0  8b5c244c                 mov       ebx, dword ptr [esp + 0x4c]
004925b4  8d35d8245700             lea       esi, [0x5724d8] ; bits=09020000, f32=7.300764999132297e-43
004925ba  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
004925c1  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
004925c8  894e08                   mov       dword ptr [esi + 8], ecx
004925cb  dbac2450020000           fld       xword ptr [esp + 0x250]
004925d2  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
004925d9  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
004925e0  894e28                   mov       dword ptr [esi + 0x28], ecx
004925e3  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
004925ea  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
004925f1  894e58                   mov       dword ptr [esi + 0x58], ecx
004925f4  899c24b0020000           mov       dword ptr [esp + 0x2b0], ebx
004925fb  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
00492602  894e64                   mov       dword ptr [esi + 0x64], ecx
00492605  dbac2438020000           fld       xword ptr [esp + 0x238]
0049260c  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
00492613  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
0049261a  898e88000000             mov       dword ptr [esi + 0x88], ecx
00492620  dbac2444020000           fld       xword ptr [esp + 0x244]
00492627  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
0049262e  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
00492635  898ea0000000             mov       dword ptr [esi + 0xa0], ecx
0049263b  56                       push      esi
0049263c  e87fa50200               call      0x4bcbc0 ; _jwe_isfm
00492641  83c404                   add       esp, 4
00492644  e99a000000               jmp       0x4926e3
00492649  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
0049264d  8b08                     mov       ecx, dword ptr [eax]
0049264f  8d1528245700             lea       edx, [0x572428] ; bits=09020000, f32=7.300764999132297e-43
00492655  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
0049265c  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
00492663  894a08                   mov       dword ptr [edx + 8], ecx
00492666  dbac2450020000           fld       xword ptr [esp + 0x250]
0049266d  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
00492674  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
0049267b  894a28                   mov       dword ptr [edx + 0x28], ecx
0049267e  89ac24b4020000           mov       dword ptr [esp + 0x2b4], ebp
00492685  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
0049268c  894a58                   mov       dword ptr [edx + 0x58], ecx
0049268f  8b4c244c                 mov       ecx, dword ptr [esp + 0x4c]
00492693  898c24b0020000           mov       dword ptr [esp + 0x2b0], ecx
0049269a  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
004926a1  894a64                   mov       dword ptr [edx + 0x64], ecx
004926a4  dbac2438020000           fld       xword ptr [esp + 0x238]
004926ab  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
004926b2  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
004926b9  898a88000000             mov       dword ptr [edx + 0x88], ecx
004926bf  dbac2444020000           fld       xword ptr [esp + 0x244]
004926c6  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
004926cd  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
004926d4  898aa0000000             mov       dword ptr [edx + 0xa0], ecx
004926da  52                       push      edx
004926db  e8e0a40200               call      0x4bcbc0 ; _jwe_isfm
004926e0  83c404                   add       esp, 4
004926e3  8b8424e0020000           mov       eax, dword ptr [esp + 0x2e0]
004926ea  8b08                     mov       ecx, dword ptr [eax]
004926ec  8d41ff                   lea       eax, [ecx - 1]
004926ef  89442448                 mov       dword ptr [esp + 0x48], eax
004926f3  894c2444                 mov       dword ptr [esp + 0x44], ecx
004926f7  8b442464                 mov       eax, dword ptr [esp + 0x64]
004926fb  8b28                     mov       ebp, dword ptr [eax]
004926fd  8b542448                 mov       edx, dword ptr [esp + 0x48]
00492701  29ea                     sub       edx, ebp
00492703  42                       inc       edx
00492704  83fa00                   cmp       edx, 0
00492707  8954243c                 mov       dword ptr [esp + 0x3c], edx
0049270b  0f8ec4100000             jle       0x4937d5
00492711  896c2438                 mov       dword ptr [esp + 0x38], ebp
00492715  8b842400030000           mov       eax, dword ptr [esp + 0x300]
0049271c  d900                     fld       dword ptr [eax]
0049271e  dbbc242c020000           fstp      xword ptr [esp + 0x22c]
00492725  8b8424f0020000           mov       eax, dword ptr [esp + 0x2f0]
0049272c  d900                     fld       dword ptr [eax]
0049272e  dbbc2420020000           fstp      xword ptr [esp + 0x220]
00492735  8b442444                 mov       eax, dword ptr [esp + 0x44]
00492739  89c6                     mov       esi, eax
0049273b  48                       dec       eax
0049273c  89442444                 mov       dword ptr [esp + 0x44], eax
00492740  8b8c24e4020000           mov       ecx, dword ptr [esp + 0x2e4]
00492747  8b29                     mov       ebp, dword ptr [ecx]
00492749  8b4c2464                 mov       ecx, dword ptr [esp + 0x64]
0049274d  2b6c2438                 sub       ebp, dword ptr [esp + 0x38]
00492751  8b19                     mov       ebx, dword ptr [ecx]
00492753  01eb                     add       ebx, ebp
00492755  4b                       dec       ebx
00492756  895c2434                 mov       dword ptr [esp + 0x34], ebx
0049275a  8b14853cd4e201           mov       edx, dword ptr [eax*4 + 0x1e2d43c]
00492761  8915c4275700             mov       dword ptr [0x5727c4], edx ; bits=00000000, f32=0.0
00492767  68c4275700               push      0x5727c4
0049276c  e86f1dfaff               call      0x4344e0 ; _gettbn_
00492771  83c404                   add       esp, 4
00492774  898424bc020000           mov       dword ptr [esp + 0x2bc], eax
0049277b  8d8424bc020000           lea       eax, [esp + 0x2bc]
00492782  50                       push      eax
00492783  6a10                     push      0x10
00492785  6870285700               push      0x572870
0049278a  e8e18b0000               call      0x49b370 ; _get_tabid_
0049278f  83c40c                   add       esp, 0xc
00492792  8d0550285700             lea       eax, [0x572850] ; bits=00000000, f32=0.0
00492798  8d0d70285700             lea       ecx, [0x572870] ; bits=00000000, f32=0.0
0049279e  8a11                     mov       dl, byte ptr [ecx]
004927a0  8810                     mov       byte ptr [eax], dl
004927a2  8a5101                   mov       dl, byte ptr [ecx + 1]
004927a5  885001                   mov       byte ptr [eax + 1], dl
004927a8  8a5102                   mov       dl, byte ptr [ecx + 2]
004927ab  885002                   mov       byte ptr [eax + 2], dl
004927ae  8a5103                   mov       dl, byte ptr [ecx + 3]
004927b1  885003                   mov       byte ptr [eax + 3], dl
004927b4  8a5104                   mov       dl, byte ptr [ecx + 4]
004927b7  885004                   mov       byte ptr [eax + 4], dl
004927ba  8a5105                   mov       dl, byte ptr [ecx + 5]
004927bd  885005                   mov       byte ptr [eax + 5], dl
004927c0  8a5106                   mov       dl, byte ptr [ecx + 6]
004927c3  885006                   mov       byte ptr [eax + 6], dl
004927c6  8a5107                   mov       dl, byte ptr [ecx + 7]
004927c9  885007                   mov       byte ptr [eax + 7], dl
004927cc  8a5108                   mov       dl, byte ptr [ecx + 8]
004927cf  885008                   mov       byte ptr [eax + 8], dl
004927d2  8a5109                   mov       dl, byte ptr [ecx + 9]
004927d5  885009                   mov       byte ptr [eax + 9], dl
004927d8  8a510a                   mov       dl, byte ptr [ecx + 0xa]
004927db  88500a                   mov       byte ptr [eax + 0xa], dl
004927de  8a510b                   mov       dl, byte ptr [ecx + 0xb]
004927e1  88500b                   mov       byte ptr [eax + 0xb], dl
004927e4  8a510c                   mov       dl, byte ptr [ecx + 0xc]
004927e7  88500c                   mov       byte ptr [eax + 0xc], dl
004927ea  8a510d                   mov       dl, byte ptr [ecx + 0xd]
004927ed  88500d                   mov       byte ptr [eax + 0xd], dl
004927f0  8a510e                   mov       dl, byte ptr [ecx + 0xe]
004927f3  88500e                   mov       byte ptr [eax + 0xe], dl
004927f6  8a510f                   mov       dl, byte ptr [ecx + 0xf]
004927f9  88500f                   mov       byte ptr [eax + 0xf], dl
004927fc  8b04b5fc50e201           mov       eax, dword ptr [esi*4 + 0x1e250fc]
00492803  8905c8275700             mov       dword ptr [0x5727c8], eax ; bits=00000000, f32=0.0
00492809  8b442444                 mov       eax, dword ptr [esp + 0x44]
0049280d  d90485e4b8f101           fld       dword ptr [eax*4 + 0x1f1b8e4]
00492814  dbbc2414020000           fstp      xword ptr [esp + 0x214]
0049281b  d90485e4c5f301           fld       dword ptr [eax*4 + 0x1f3c5e4]
00492822  dbbc2408020000           fstp      xword ptr [esp + 0x208]
00492829  dbac2414020000           fld       xword ptr [esp + 0x214]
00492830  dbac2480020000           fld       xword ptr [esp + 0x280]
00492837  dee9                     fsubp     st(1)
00492839  d9e1                     fabs
0049283b  dbbc24fc010000           fstp      xword ptr [esp + 0x1fc]
00492842  dbac24fc010000           fld       xword ptr [esp + 0x1fc]
00492849  d91cb5a40eeb01           fstp      dword ptr [esi*4 + 0x1eb0ea4]
00492850  dbac2474020000           fld       xword ptr [esp + 0x274]
00492857  dbac2408020000           fld       xword ptr [esp + 0x208]
0049285e  dee9                     fsubp     st(1)
00492860  dbbc24f0010000           fstp      xword ptr [esp + 0x1f0]
00492867  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
0049286e  d91cb5e491eb01           fstp      dword ptr [esi*4 + 0x1eb91e4]
00492875  bd00000000               mov       ebp, 0
0049287a  d905e0275700             fld       dword ptr [0x5727e0] ; bits=00000000, f32=0.0
00492880  dbac242c020000           fld       xword ptr [esp + 0x22c]
00492887  d80de0275700             fmul      dword ptr [0x5727e0] ; bits=00000000, f32=0.0
0049288d  d90518285700             fld       dword ptr [0x572818] ; bits=00000000, f32=0.0
00492893  d80d18285700             fmul      dword ptr [0x572818] ; bits=00000000, f32=0.0
00492899  dcc9                     fmul      st(1), st(0)
0049289b  d905d8275700             fld       dword ptr [0x5727d8] ; bits=00000000, f32=0.0
004928a1  d9ca                     fxch      st(2)
004928a3  d835d8275700             fdiv      dword ptr [0x5727d8] ; bits=00000000, f32=0.0
004928a9  dbbc24e4010000           fstp      xword ptr [esp + 0x1e4]
004928b0  deca                     fmulp     st(2)
004928b2  def9                     fdivp     st(1)
004928b4  dbbc24d8010000           fstp      xword ptr [esp + 0x1d8]
004928bb  8b1530285700             mov       edx, dword ptr [0x572830] ; bits=00000000, f32=0.0
004928c1  8954242c                 mov       dword ptr [esp + 0x2c], edx
004928c5  d9e8                     fld1
004928c7  dbbc24cc010000           fstp      xword ptr [esp + 0x1cc]
004928ce  83fd01                   cmp       ebp, 1
004928d1  7552                     jne       0x492925
004928d3  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004928d7  8b542468                 mov       edx, dword ptr [esp + 0x68]
004928db  8b08                     mov       ecx, dword ptr [eax]
004928dd  8b1a                     mov       ebx, dword ptr [edx]
004928df  8d3df0235700             lea       edi, [0x5723f0] ; bits=09020000, f32=7.300764999132297e-43
004928e5  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
004928ec  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
004928f3  894f08                   mov       dword ptr [edi + 8], ecx
004928f6  899c24b8020000           mov       dword ptr [esp + 0x2b8], ebx
004928fd  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
00492904  894f28                   mov       dword ptr [edi + 0x28], ecx
00492907  8b4c2434                 mov       ecx, dword ptr [esp + 0x34]
0049290b  898c24a4020000           mov       dword ptr [esp + 0x2a4], ecx
00492912  8d9c24a4020000           lea       ebx, [esp + 0x2a4]
00492919  895f34                   mov       dword ptr [edi + 0x34], ebx
0049291c  57                       push      edi
0049291d  e89ea20200               call      0x4bcbc0 ; _jwe_isfm
00492922  83c404                   add       esp, 4
00492925  8b44242c                 mov       eax, dword ptr [esp + 0x2c]
00492929  8b4c2444                 mov       ecx, dword ptr [esp + 0x44]
0049292d  890528285700             mov       dword ptr [0x572828], eax ; bits=00000000, f32=0.0
00492933  8b148da428ef01           mov       edx, dword ptr [ecx*4 + 0x1ef28a4]
0049293a  891514285700             mov       dword ptr [0x572814], edx ; bits=00000000, f32=0.0
00492940  89148de4abef01           mov       dword ptr [ecx*4 + 0x1efabe4], edx
00492947  bb01000000               mov       ebx, 1
0049294c  d90514285700             fld       dword ptr [0x572814] ; bits=00000000, f32=0.0
00492952  d9c0                     fld       st(0)
00492954  d82d18285700             fsubr     dword ptr [0x572818] ; bits=00000000, f32=0.0
0049295a  8d15081f5700             lea       edx, [0x571f08] ; bits=fa000000, f32=3.5032461608120427e-43
00492960  d84a90                   fmul      dword ptr [edx - 0x70]
00492963  dec1                     faddp     st(1)
00492965  d9c0                     fld       st(0)
00492967  d9e1                     fabs
00492969  d9c0                     fld       st(0)
0049296b  d8ca                     fmul      st(2)
0049296d  dbbc24c0010000           fstp      xword ptr [esp + 0x1c0]
00492974  d9c1                     fld       st(1)
00492976  d84a98                   fmul      dword ptr [edx - 0x68]
00492979  d8c9                     fmul      st(1)
0049297b  dbbc24b4010000           fstp      xword ptr [esp + 0x1b4]
00492982  dbbc24a8010000           fstp      xword ptr [esp + 0x1a8]
00492989  dbbc249c010000           fstp      xword ptr [esp + 0x19c]
00492990  68e4275700               push      0x5727e4
00492995  68dc275700               push      0x5727dc
0049299a  68f4275700               push      0x5727f4
0049299f  680c285700               push      0x57280c
004929a4  68fc275700               push      0x5727fc
004929a9  6820285700               push      0x572820
004929ae  68d0275700               push      0x5727d0
004929b3  6828285700               push      0x572828
004929b8  68c4275700               push      0x5727c4
004929bd  e82e7efaff               call      0x43a7f0 ; _xlkt20_
004929c2  83c424                   add       esp, 0x24
004929c5  833dc827570000           cmp       dword ptr [0x5727c8], 0 ; bits=00000000, f32=0.0
004929cc  7e42                     jle       0x492a10
004929ce  d90528285700             fld       dword ptr [0x572828] ; bits=00000000, f32=0.0
004929d4  d80530285700             fadd      dword ptr [0x572830] ; bits=00000000, f32=0.0
004929da  8d05081f5700             lea       eax, [0x571f08] ; bits=fa000000, f32=3.5032461608120427e-43
004929e0  d84890                   fmul      dword ptr [eax - 0x70]
004929e3  d91d2c285700             fstp      dword ptr [0x57282c] ; bits=00000000, f32=0.0
004929e9  68f0275700               push      0x5727f0
004929ee  68cc275700               push      0x5727cc
004929f3  6808285700               push      0x572808
004929f8  8d40a4                   lea       eax, [eax - 0x5c]
004929fb  50                       push      eax
004929fc  682c285700               push      0x57282c
00492a01  68c8275700               push      0x5727c8
00492a06  e83533faff               call      0x435d40 ; _lktab_
00492a0b  83c418                   add       esp, 0x18
00492a0e  eb14                     jmp       0x492a24
00492a10  c7050828570000000000     mov       dword ptr [0x572808], 0 ; bits=00000000, f32=0.0
00492a1a  c705f027570000000000     mov       dword ptr [0x5727f0], 0 ; bits=00000000, f32=0.0
00492a24  d905d0275700             fld       dword ptr [0x5727d0] ; bits=00000000, f32=0.0
00492a2a  d83d14285700             fdivr     dword ptr [0x572814] ; bits=00000000, f32=0.0
00492a30  dbbc2490010000           fstp      xword ptr [esp + 0x190]
00492a37  d90510285700             fld       dword ptr [0x572810] ; bits=00000000, f32=0.0
00492a3d  d9050c285700             fld       dword ptr [0x57280c] ; bits=00000000, f32=0.0
00492a43  d9c0                     fld       st(0)
00492a45  d80510285700             fadd      dword ptr [0x572810] ; bits=00000000, f32=0.0
00492a4b  8d0d081f5700             lea       ecx, [0x571f08] ; bits=fa000000, f32=3.5032461608120427e-43
00492a51  d94190                   fld       dword ptr [ecx - 0x70]
00492a54  d9c9                     fxch      st(1)
00492a56  d84990                   fmul      dword ptr [ecx - 0x70]
00492a59  d9c9                     fxch      st(1)
00492a5b  dbbc2484010000           fstp      xword ptr [esp + 0x184]
00492a62  d9ca                     fxch      st(2)
00492a64  dbbc2478010000           fstp      xword ptr [esp + 0x178]
00492a6b  dbbc246c010000           fstp      xword ptr [esp + 0x16c]
00492a72  833d0026e50101           cmp       dword ptr [0x1e52600], 1
00492a79  0f8cef000000             jl        0x492b6e
00492a7f  d9ee                     fldz
00492a81  dbac249c010000           fld       xword ptr [esp + 0x19c]
00492a88  dff1                     fcompi    st(1)
00492a8a  dbbc2460010000           fstp      xword ptr [esp + 0x160]
00492a91  0f8a87000000             jp        0x492b1e
00492a97  0f8281000000             jb        0x492b1e
00492a9d  d90528285700             fld       dword ptr [0x572828] ; bits=00000000, f32=0.0
00492aa3  d82d30285700             fsubr     dword ptr [0x572830] ; bits=00000000, f32=0.0
00492aa9  d9e0                     fchs
00492aab  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
00492ab2  dee9                     fsubp     st(1)
00492ab4  d80df8275700             fmul      dword ptr [0x5727f8] ; bits=00000000, f32=0.0
00492aba  d9c0                     fld       st(0)
00492abc  d8e2                     fsub      st(2)
00492abe  dbac2460010000           fld       xword ptr [esp + 0x160]
00492ac5  dff1                     fcompi    st(1)
00492ac7  ddd8                     fstp      st(0)
00492ac9  dbbc2454010000           fstp      xword ptr [esp + 0x154]
00492ad0  0f8a3f000000             jp        0x492b15
00492ad6  773d                     ja        0x492b15
00492ad8  ddd8                     fstp      st(0)
00492ada  dbac246c010000           fld       xword ptr [esp + 0x16c]
00492ae1  d8498c                   fmul      dword ptr [ecx - 0x74]
00492ae4  dbac2478010000           fld       xword ptr [esp + 0x178]
00492aeb  dbac246c010000           fld       xword ptr [esp + 0x16c]
00492af2  dee9                     fsubp     st(1)
00492af4  dbac2484010000           fld       xword ptr [esp + 0x184]
00492afb  d8c9                     fmul      st(1)
00492afd  dbac2454010000           fld       xword ptr [esp + 0x154]
00492b04  dee1                     fsubrp    st(1)
00492b06  defa                     fdivp     st(2)
00492b08  d8c9                     fmul      st(1)
00492b0a  dbac246c010000           fld       xword ptr [esp + 0x16c]
00492b11  dec1                     faddp     st(1)
00492b13  eb4c                     jmp       0x492b61
00492b15  89c8                     mov       eax, ecx
00492b17  d94090                   fld       dword ptr [eax - 0x70]
00492b1a  d9c9                     fxch      st(1)
00492b1c  eb43                     jmp       0x492b61
00492b1e  d90528285700             fld       dword ptr [0x572828] ; bits=00000000, f32=0.0
00492b24  d82d30285700             fsubr     dword ptr [0x572830] ; bits=00000000, f32=0.0
00492b2a  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
00492b31  dec1                     faddp     st(1)
00492b33  d80df4275700             fmul      dword ptr [0x5727f4] ; bits=00000000, f32=0.0
00492b39  d8e1                     fsub      st(1)
00492b3b  dbac2460010000           fld       xword ptr [esp + 0x160]
00492b42  dff1                     fcompi    st(1)
00492b44  ddd8                     fstp      st(0)
00492b46  0f8a0e000000             jp        0x492b5a
00492b4c  770c                     ja        0x492b5a
00492b4e  ddd8                     fstp      st(0)
00492b50  d9e8                     fld1
00492b52  d90510285700             fld       dword ptr [0x572810] ; bits=00000000, f32=0.0
00492b58  eb07                     jmp       0x492b61
00492b5a  89c8                     mov       eax, ecx
00492b5c  d94090                   fld       dword ptr [eax - 0x70]
00492b5f  d9c9                     fxch      st(1)
00492b61  d9c9                     fxch      st(1)
00492b63  d914b5a45cf701           fst       dword ptr [esi*4 + 0x1f75ca4]
00492b6a  d9c9                     fxch      st(1)
00492b6c  eb07                     jmp       0x492b75
00492b6e  89c8                     mov       eax, ecx
00492b70  d94090                   fld       dword ptr [eax - 0x70]
00492b73  d9c9                     fxch      st(1)
00492b75  dbac2468020000           fld       xword ptr [esp + 0x268]
00492b7c  dbac2490010000           fld       xword ptr [esp + 0x190]
00492b83  dee9                     fsubp     st(1)
00492b85  d9ee                     fldz
00492b87  dff1                     fcompi    st(1)
00492b89  0f8a21000000             jp        0x492bb0
00492b8f  721f                     jb        0x492bb0
00492b91  d905a81e5700             fld       dword ptr [0x571ea8] ; bits=000080bf, f32=-1.0
00492b97  dbbc2448010000           fstp      xword ptr [esp + 0x148]
00492b9e  d904b5e49eed01           fld       dword ptr [esi*4 + 0x1ed9ee4]
00492ba5  dbbc243c010000           fstp      xword ptr [esp + 0x13c]
00492bac  d9e1                     fabs
00492bae  eb17                     jmp       0x492bc7
00492bb0  d9e8                     fld1
00492bb2  dbbc2448010000           fstp      xword ptr [esp + 0x148]
00492bb9  d904b5a41bed01           fld       dword ptr [esi*4 + 0x1ed1ba4]
00492bc0  dbbc243c010000           fstp      xword ptr [esp + 0x13c]
00492bc7  dbbc24b8000000           fstp      xword ptr [esp + 0xb8]
00492bce  dbbc24ac000000           fstp      xword ptr [esp + 0xac]
00492bd5  dbbc24a0000000           fstp      xword ptr [esp + 0xa0]
00492bdc  d905d0275700             fld       dword ptr [0x5727d0] ; bits=00000000, f32=0.0
00492be2  dbbc24c4000000           fstp      xword ptr [esp + 0xc4]
00492be9  d905d0275700             fld       dword ptr [0x5727d0] ; bits=00000000, f32=0.0
00492bef  d82dd8275700             fsubr     dword ptr [0x5727d8] ; bits=00000000, f32=0.0
00492bf5  8d0d081f5700             lea       ecx, [0x571f08] ; bits=fa000000, f32=3.5032461608120427e-43
00492bfb  d94190                   fld       dword ptr [ecx - 0x70]
00492bfe  dbbc24d0000000           fstp      xword ptr [esp + 0xd0]
00492c05  d84990                   fmul      dword ptr [ecx - 0x70]
00492c08  dbac24c4000000           fld       xword ptr [esp + 0xc4]
00492c0f  dec1                     faddp     st(1)
00492c11  dbbc24dc000000           fstp      xword ptr [esp + 0xdc]
00492c18  d90528285700             fld       dword ptr [0x572828] ; bits=00000000, f32=0.0
00492c1e  dbbc24e8000000           fstp      xword ptr [esp + 0xe8]
00492c25  d90528285700             fld       dword ptr [0x572828] ; bits=00000000, f32=0.0
00492c2b  d82d30285700             fsubr     dword ptr [0x572830] ; bits=00000000, f32=0.0
00492c31  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
00492c38  dec1                     faddp     st(1)
00492c3a  dbbc24f4000000           fstp      xword ptr [esp + 0xf4]
00492c41  dbac24ac000000           fld       xword ptr [esp + 0xac]
00492c48  d8c8                     fmul      st(0)
00492c4a  dbac24c0010000           fld       xword ptr [esp + 0x1c0]
00492c51  def1                     fdivrp    st(1)
00492c53  dbbc2494000000           fstp      xword ptr [esp + 0x94]
00492c5a  dbac2420020000           fld       xword ptr [esp + 0x220]
00492c61  dbac24dc000000           fld       xword ptr [esp + 0xdc]
00492c68  dec9                     fmulp     st(1)
00492c6a  dbac24fc010000           fld       xword ptr [esp + 0x1fc]
00492c71  dbac2494000000           fld       xword ptr [esp + 0x94]
00492c78  dec9                     fmulp     st(1)
00492c7a  d9c0                     fld       st(0)
00492c7c  d80530285700             fadd      dword ptr [0x572830] ; bits=00000000, f32=0.0
00492c82  d8ca                     fmul      st(2)
00492c84  dbac24e4010000           fld       xword ptr [esp + 0x1e4]
00492c8b  dec1                     faddp     st(1)
00492c8d  dbbc2430010000           fstp      xword ptr [esp + 0x130]
00492c94  d90514285700             fld       dword ptr [0x572814] ; bits=00000000, f32=0.0
00492c9a  d905dc275700             fld       dword ptr [0x5727dc] ; bits=00000000, f32=0.0
00492ca0  d9c0                     fld       st(0)
00492ca2  d80d14285700             fmul      dword ptr [0x572814] ; bits=00000000, f32=0.0
00492ca8  dbac2490010000           fld       xword ptr [esp + 0x190]
00492caf  dec9                     fmulp     st(1)
00492cb1  dbac24d8010000           fld       xword ptr [esp + 0x1d8]
00492cb8  dee1                     fsubrp    st(1)
00492cba  dbac242c020000           fld       xword ptr [esp + 0x22c]
00492cc1  dec9                     fmulp     st(1)
00492cc3  dbac24f4000000           fld       xword ptr [esp + 0xf4]
00492cca  dec4                     faddp     st(4)
00492ccc  d9cc                     fxch      st(4)
00492cce  d8cb                     fmul      st(3)
00492cd0  dec4                     faddp     st(4)
00492cd2  dbac243c010000           fld       xword ptr [esp + 0x13c]
00492cd9  dbac24b8000000           fld       xword ptr [esp + 0xb8]
00492ce0  dec9                     fmulp     st(1)
00492ce2  dbac249c010000           fld       xword ptr [esp + 0x19c]
00492ce9  dec9                     fmulp     st(1)
00492ceb  dec4                     faddp     st(4)
00492ced  d90508285700             fld       dword ptr [0x572808] ; bits=00000000, f32=0.0
00492cf3  dbac24d0000000           fld       xword ptr [esp + 0xd0]
00492cfa  d80d08285700             fmul      dword ptr [0x572808] ; bits=00000000, f32=0.0
00492d00  dbac249c010000           fld       xword ptr [esp + 0x19c]
00492d07  dec9                     fmulp     st(1)
00492d09  dbac24a8010000           fld       xword ptr [esp + 0x1a8]
00492d10  dec9                     fmulp     st(1)
00492d12  dbac24dc000000           fld       xword ptr [esp + 0xdc]
00492d19  d83d901e5700             fdivr     dword ptr [0x571e90] ; bits=0000803f, f32=1.0
00492d1f  dcc9                     fmul      st(1), st(0)
00492d21  d9c9                     fxch      st(1)
00492d23  dec6                     faddp     st(6)
00492d25  d9cd                     fxch      st(5)
00492d27  dbbc2424010000           fstp      xword ptr [esp + 0x124]
00492d2e  dbac2490010000           fld       xword ptr [esp + 0x190]
00492d35  dbac2490010000           fld       xword ptr [esp + 0x190]
00492d3c  dec9                     fmulp     st(1)
00492d3e  d9ca                     fxch      st(2)
00492d40  d80d20285700             fmul      dword ptr [0x572820] ; bits=00000000, f32=0.0
00492d46  dbac24c4000000           fld       xword ptr [esp + 0xc4]
00492d4d  d80de4275700             fmul      dword ptr [0x5727e4] ; bits=00000000, f32=0.0
00492d53  dee9                     fsubp     st(1)
00492d55  deca                     fmulp     st(2)
00492d57  dbac242c020000           fld       xword ptr [esp + 0x22c]
00492d5e  deca                     fmulp     st(2)
00492d60  dbac24d0000000           fld       xword ptr [esp + 0xd0]
00492d67  d80d20285700             fmul      dword ptr [0x572820] ; bits=00000000, f32=0.0
00492d6d  decc                     fmulp     st(4)
00492d6f  dbac24a0000000           fld       xword ptr [esp + 0xa0]
00492d76  d82d901e5700             fsubr     dword ptr [0x571e90] ; bits=0000803f, f32=1.0
00492d7c  d8c0                     fadd      st(0)
00492d7e  dbac24fc010000           fld       xword ptr [esp + 0x1fc]
00492d85  dec9                     fmulp     st(1)
00492d87  dbac2494000000           fld       xword ptr [esp + 0x94]
00492d8e  dec9                     fmulp     st(1)
00492d90  d80df4275700             fmul      dword ptr [0x5727f4] ; bits=00000000, f32=0.0
00492d96  dbac24ac000000           fld       xword ptr [esp + 0xac]
00492d9d  def9                     fdivp     st(1)
00492d9f  d805901e5700             fadd      dword ptr [0x571e90] ; bits=0000803f, f32=1.0
00492da5  dbac24dc000000           fld       xword ptr [esp + 0xdc]
00492dac  dec9                     fmulp     st(1)
00492dae  deec                     fsubp     st(4)
00492db0  dbac2420020000           fld       xword ptr [esp + 0x220]
00492db7  decc                     fmulp     st(4)
00492db9  d9cb                     fxch      st(3)
00492dbb  dec1                     faddp     st(1)
00492dbd  dbac249c010000           fld       xword ptr [esp + 0x19c]
00492dc4  dbac243c010000           fld       xword ptr [esp + 0x13c]
00492dcb  dec9                     fmulp     st(1)
00492dcd  dbac2448010000           fld       xword ptr [esp + 0x148]
00492dd4  dec9                     fmulp     st(1)
00492dd6  deca                     fmulp     st(2)
00492dd8  d9c9                     fxch      st(1)
00492dda  d80d20285700             fmul      dword ptr [0x572820] ; bits=00000000, f32=0.0
00492de0  dbac24c4000000           fld       xword ptr [esp + 0xc4]
00492de7  dbac24c4000000           fld       xword ptr [esp + 0xc4]
00492dee  dec9                     fmulp     st(1)
00492df0  def9                     fdivp     st(1)
00492df2  dec1                     faddp     st(1)
00492df4  d9c9                     fxch      st(1)
00492df6  d80d20285700             fmul      dword ptr [0x572820] ; bits=00000000, f32=0.0
00492dfc  d8ca                     fmul      st(2)
00492dfe  d82df0275700             fsubr     dword ptr [0x5727f0] ; bits=00000000, f32=0.0
00492e04  dbac24b4010000           fld       xword ptr [esp + 0x1b4]
00492e0b  dec9                     fmulp     st(1)
00492e0d  deca                     fmulp     st(2)
00492e0f  dec1                     faddp     st(1)
00492e11  d9ee                     fldz
00492e13  dff1                     fcompi    st(1)
00492e15  dbbc2418010000           fstp      xword ptr [esp + 0x118]
00492e1c  dbac24d0000000           fld       xword ptr [esp + 0xd0]
00492e23  dbbc240c010000           fstp      xword ptr [esp + 0x10c]
00492e2a  dbac24e8000000           fld       xword ptr [esp + 0xe8]
00492e31  dbbc2400010000           fstp      xword ptr [esp + 0x100]
00492e38  0f8a58010000             jp        0x492f96
00492e3e  0f8752010000             ja        0x492f96
00492e44  dbac24cc010000           fld       xword ptr [esp + 0x1cc]
00492e4b  dbac2400010000           fld       xword ptr [esp + 0x100]
00492e52  d8499c                   fmul      dword ptr [ecx - 0x64]
00492e55  dbac240c010000           fld       xword ptr [esp + 0x10c]
00492e5c  deca                     fmulp     st(2)
00492e5e  d9c9                     fxch      st(1)
00492e60  dbbc24cc010000           fstp      xword ptr [esp + 0x1cc]
00492e67  43                       inc       ebx
00492e68  89d8                     mov       eax, ebx
00492e6a  f7d8                     neg       eax
00492e6c  89442428                 mov       dword ptr [esp + 0x28], eax
00492e70  83fd01                   cmp       ebp, 1
00492e73  0f85c0000000             jne       0x492f39
00492e79  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
00492e7d  dbbc248c020000           fstp      xword ptr [esp + 0x28c]
00492e84  8b08                     mov       ecx, dword ptr [eax]
00492e86  8b1528285700             mov       edx, dword ptr [0x572828] ; bits=00000000, f32=0.0
00492e8c  8d3d88235700             lea       edi, [0x572388] ; bits=09020000, f32=7.300764999132297e-43
00492e92  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
00492e99  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
00492ea0  894f08                   mov       dword ptr [edi + 8], ecx
00492ea3  8b4c2428                 mov       ecx, dword ptr [esp + 0x28]
00492ea7  898c24b8020000           mov       dword ptr [esp + 0x2b8], ecx
00492eae  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
00492eb5  894f28                   mov       dword ptr [edi + 0x28], ecx
00492eb8  dbac248c020000           fld       xword ptr [esp + 0x28c]
00492ebf  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
00492ec6  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
00492ecd  894f34                   mov       dword ptr [edi + 0x34], ecx
00492ed0  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
00492ed7  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
00492ede  894f40                   mov       dword ptr [edi + 0x40], ecx
00492ee1  dbac2424010000           fld       xword ptr [esp + 0x124]
00492ee8  d99c24b0020000           fstp      dword ptr [esp + 0x2b0]
00492eef  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
00492ef6  894f4c                   mov       dword ptr [edi + 0x4c], ecx
00492ef9  dbac2418010000           fld       xword ptr [esp + 0x118]
00492f00  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
00492f07  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
00492f0e  894f58                   mov       dword ptr [edi + 0x58], ecx
00492f11  dbac2430010000           fld       xword ptr [esp + 0x130]
00492f18  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
00492f1f  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
00492f26  894f64                   mov       dword ptr [edi + 0x64], ecx
00492f29  57                       push      edi
00492f2a  e8919c0200               call      0x4bcbc0 ; _jwe_isfm
00492f2f  dbac2490020000           fld       xword ptr [esp + 0x290]
00492f36  83c404                   add       esp, 4
00492f39  d91d28285700             fstp      dword ptr [0x572828] ; bits=00000000, f32=0.0
00492f3f  8b8424fc020000           mov       eax, dword ptr [esp + 0x2fc]
00492f46  8b00                     mov       eax, dword ptr [eax]
00492f48  39c3                     cmp       ebx, eax
00492f4a  0f8e40faffff             jle       0x492990
00492f50  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
00492f54  8b08                     mov       ecx, dword ptr [eax]
00492f56  8d1568235700             lea       edx, [0x572368] ; bits=69020000, f32=8.646011524884121e-43
00492f5c  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
00492f63  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
00492f6a  894a08                   mov       dword ptr [edx + 8], ecx
00492f6d  52                       push      edx
00492f6e  e84d9c0200               call      0x4bcbc0 ; _jwe_isfm
00492f73  83c404                   add       esp, 4
00492f76  8b842408030000           mov       eax, dword ptr [esp + 0x308]
00492f7d  c70001000000             mov       dword ptr [eax], 1
00492f83  83fd01                   cmp       ebp, 1
00492f86  0f8479080000             je        0x493805
00492f8c  bd01000000               mov       ebp, 1
00492f91  e92ff9ffff               jmp       0x4928c5
00492f96  dbac2424010000           fld       xword ptr [esp + 0x124]
00492f9d  dbac24cc010000           fld       xword ptr [esp + 0x1cc]
00492fa4  dec9                     fmulp     st(1)
00492fa6  dbac2418010000           fld       xword ptr [esp + 0x118]
00492fad  def9                     fdivp     st(1)
00492faf  dbbc2488000000           fstp      xword ptr [esp + 0x88]
00492fb6  dbac2424010000           fld       xword ptr [esp + 0x124]
00492fbd  dbac2430010000           fld       xword ptr [esp + 0x130]
00492fc4  def9                     fdivp     st(1)
00492fc6  d9e1                     fabs
00492fc8  8b8424f4020000           mov       eax, dword ptr [esp + 0x2f4]
00492fcf  d900                     fld       dword ptr [eax]
00492fd1  d9c9                     fxch      st(1)
00492fd3  dff1                     fcompi    st(1)
00492fd5  db7c247c                 fstp      xword ptr [esp + 0x7c]
00492fd9  0f8a06000000             jp        0x492fe5
00492fdf  0f8671010000             jbe       0x493156
00492fe5  dbac2400010000           fld       xword ptr [esp + 0x100]
00492fec  dbac2488000000           fld       xword ptr [esp + 0x88]
00492ff3  def1                     fdivrp    st(1)
00492ff5  d9e1                     fabs
00492ff7  db6c247c                 fld       xword ptr [esp + 0x7c]
00492ffb  dff1                     fcompi    st(1)
00492ffd  ddd8                     fstp      st(0)
00492fff  0f8a06000000             jp        0x49300b
00493005  0f834b010000             jae       0x493156
0049300b  8b8424fc020000           mov       eax, dword ptr [esp + 0x2fc]
00493012  8b00                     mov       eax, dword ptr [eax]
00493014  39c3                     cmp       ebx, eax
00493016  7e46                     jle       0x49305e
00493018  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
0049301c  8b08                     mov       ecx, dword ptr [eax]
0049301e  8d1548235700             lea       edx, [0x572348] ; bits=69020000, f32=8.646011524884121e-43
00493024  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
0049302b  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
00493032  894a08                   mov       dword ptr [edx + 8], ecx
00493035  52                       push      edx
00493036  e8859b0200               call      0x4bcbc0 ; _jwe_isfm
0049303b  83c404                   add       esp, 4
0049303e  8b842408030000           mov       eax, dword ptr [esp + 0x308]
00493045  c70001000000             mov       dword ptr [eax], 1
0049304b  83fd01                   cmp       ebp, 1
0049304e  0f84b1070000             je        0x493805
00493054  bd01000000               mov       ebp, 1
00493059  e967f8ffff               jmp       0x4928c5
0049305e  dbac2488000000           fld       xword ptr [esp + 0x88]
00493065  d82d28285700             fsubr     dword ptr [0x572828] ; bits=00000000, f32=0.0
0049306b  83fd01                   cmp       ebp, 1
0049306e  0f85bc000000             jne       0x493130
00493074  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
00493078  dbbc248c020000           fstp      xword ptr [esp + 0x28c]
0049307f  8b08                     mov       ecx, dword ptr [eax]
00493081  8b1528285700             mov       edx, dword ptr [0x572828] ; bits=00000000, f32=0.0
00493087  8d3de0225700             lea       edi, [0x5722e0] ; bits=09020000, f32=7.300764999132297e-43
0049308d  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
00493094  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
0049309b  894f08                   mov       dword ptr [edi + 8], ecx
0049309e  899c24b8020000           mov       dword ptr [esp + 0x2b8], ebx
004930a5  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
004930ac  894f28                   mov       dword ptr [edi + 0x28], ecx
004930af  dbac248c020000           fld       xword ptr [esp + 0x28c]
004930b6  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
004930bd  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
004930c4  894f34                   mov       dword ptr [edi + 0x34], ecx
004930c7  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
004930ce  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
004930d5  894f40                   mov       dword ptr [edi + 0x40], ecx
004930d8  dbac2424010000           fld       xword ptr [esp + 0x124]
004930df  d99c24b0020000           fstp      dword ptr [esp + 0x2b0]
004930e6  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
004930ed  894f4c                   mov       dword ptr [edi + 0x4c], ecx
004930f0  dbac2418010000           fld       xword ptr [esp + 0x118]
004930f7  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
004930fe  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
00493105  894f58                   mov       dword ptr [edi + 0x58], ecx
00493108  dbac2430010000           fld       xword ptr [esp + 0x130]
0049310f  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
00493116  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
0049311d  894f64                   mov       dword ptr [edi + 0x64], ecx
00493120  57                       push      edi
00493121  e89a9a0200               call      0x4bcbc0 ; _jwe_isfm
00493126  dbac2490020000           fld       xword ptr [esp + 0x290]
0049312d  83c404                   add       esp, 4
00493130  d9ee                     fldz
00493132  dff1                     fcompi    st(1)
00493134  0f8a10000000             jp        0x49314a
0049313a  720e                     jb        0x49314a
0049313c  ddd8                     fstp      st(0)
0049313e  d90528285700             fld       dword ptr [0x572828] ; bits=00000000, f32=0.0
00493144  d80d981e5700             fmul      dword ptr [0x571e98] ; bits=0000003f, f32=0.5
0049314a  d91d28285700             fstp      dword ptr [0x572828] ; bits=00000000, f32=0.0
00493150  43                       inc       ebx
00493151  e93af8ffff               jmp       0x492990
00493156  8b742444                 mov       esi, dword ptr [esp + 0x44]
0049315a  8b0528285700             mov       eax, dword ptr [0x572828] ; bits=00000000, f32=0.0
00493160  8904b5243cf201           mov       dword ptr [esi*4 + 0x1f23c24], eax
00493167  8904b564bff201           mov       dword ptr [esi*4 + 0x1f2bf64], eax
0049316e  8b2dd0275700             mov       ebp, dword ptr [0x5727d0] ; bits=00000000, f32=0.0
00493174  892cb5a401e901           mov       dword ptr [esi*4 + 0x1e901a4], ebp
0049317b  892cb5e484e901           mov       dword ptr [esi*4 + 0x1e984e4], ebp
00493182  8b1520285700             mov       edx, dword ptr [0x572820] ; bits=00000000, f32=0.0
00493188  8954241c                 mov       dword ptr [esp + 0x1c], edx
0049318c  8914b564b2f001           mov       dword ptr [esi*4 + 0x1f0b264], edx
00493193  8914b5a435f101           mov       dword ptr [esi*4 + 0x1f135a4], edx
0049319a  8b3d0c285700             mov       edi, dword ptr [0x57280c] ; bits=00000000, f32=0.0
004931a0  893cb52415ec01           mov       dword ptr [esi*4 + 0x1ec1524], edi
004931a7  893cb56498ec01           mov       dword ptr [esi*4 + 0x1ec9864], edi
004931ae  89442424                 mov       dword ptr [esp + 0x24], eax
004931b2  8b05dc275700             mov       eax, dword ptr [0x5727dc] ; bits=00000000, f32=0.0
004931b8  8904b52408ea01           mov       dword ptr [esi*4 + 0x1ea0824], eax
004931bf  8904b5648bea01           mov       dword ptr [esi*4 + 0x1ea8b64], eax
004931c6  8b0d14285700             mov       ecx, dword ptr [0x572814] ; bits=00000000, f32=0.0
004931cc  890d18285700             mov       dword ptr [0x572818], ecx ; bits=00000000, f32=0.0
004931d2  8b4c2424                 mov       ecx, dword ptr [esp + 0x24]
004931d6  890d30285700             mov       dword ptr [0x572830], ecx ; bits=00000000, f32=0.0
004931dc  892dd8275700             mov       dword ptr [0x5727d8], ebp ; bits=00000000, f32=0.0
004931e2  891524285700             mov       dword ptr [0x572824], edx ; bits=00000000, f32=0.0
004931e8  dbac2408020000           fld       xword ptr [esp + 0x208]
004931ef  dbbc2474020000           fstp      xword ptr [esp + 0x274]
004931f6  dbac2414020000           fld       xword ptr [esp + 0x214]
004931fd  dbbc2480020000           fstp      xword ptr [esp + 0x280]
00493204  dbac2490010000           fld       xword ptr [esp + 0x190]
0049320b  dbbc2468020000           fstp      xword ptr [esp + 0x268]
00493212  893d10285700             mov       dword ptr [0x572810], edi ; bits=00000000, f32=0.0
00493218  8b3df4275700             mov       edi, dword ptr [0x5727f4] ; bits=00000000, f32=0.0
0049321e  893df8275700             mov       dword ptr [0x5727f8], edi ; bits=00000000, f32=0.0
00493224  8905e0275700             mov       dword ptr [0x5727e0], eax ; bits=00000000, f32=0.0
0049322a  dbac2408020000           fld       xword ptr [esp + 0x208]
00493231  d80528285700             fadd      dword ptr [0x572828] ; bits=00000000, f32=0.0
00493237  db7c2470                 fstp      xword ptr [esp + 0x70]
0049323b  8b8424ec020000           mov       eax, dword ptr [esp + 0x2ec]
00493242  dbac2414020000           fld       xword ptr [esp + 0x214]
00493249  d830                     fdiv      dword ptr [eax]
0049324b  dbbc2450020000           fstp      xword ptr [esp + 0x250]
00493252  d90514285700             fld       dword ptr [0x572814] ; bits=00000000, f32=0.0
00493258  d80d14285700             fmul      dword ptr [0x572814] ; bits=00000000, f32=0.0
0049325e  d80d20285700             fmul      dword ptr [0x572820] ; bits=00000000, f32=0.0
00493264  d905d0275700             fld       dword ptr [0x5727d0] ; bits=00000000, f32=0.0
0049326a  d9c0                     fld       st(0)
0049326c  d80dd0275700             fmul      dword ptr [0x5727d0] ; bits=00000000, f32=0.0
00493272  dec9                     fmulp     st(1)
00493274  8b8424f0020000           mov       eax, dword ptr [esp + 0x2f0]
0049327b  d808                     fmul      dword ptr [eax]
0049327d  def9                     fdivp     st(1)
0049327f  dbbc2444020000           fstp      xword ptr [esp + 0x244]
00493286  6a07                     push      7
00493288  6840285700               push      0x572840
0049328d  6828285700               push      0x572828
00493292  e829edfaff               call      0x441fc0 ; _var_decimal_
00493297  83c40c                   add       esp, 0xc
0049329a  6a08                     push      8
0049329c  6848285700               push      0x572848
004932a1  6814285700               push      0x572814
004932a6  e815edfaff               call      0x441fc0 ; _var_decimal_
004932ab  83c40c                   add       esp, 0xc
004932ae  8b842404030000           mov       eax, dword ptr [esp + 0x304]
004932b5  db6c2470                 fld       xword ptr [esp + 0x70]
004932b9  d800                     fadd      dword ptr [eax]
004932bb  dbbc2438020000           fstp      xword ptr [esp + 0x238]
004932c2  837c245c04               cmp       dword ptr [esp + 0x5c], 4
004932c7  730d                     jae       0x4932d6
004932c9  8b44245c                 mov       eax, dword ptr [esp + 0x5c]
004932cd  8b0c85682a5700           mov       ecx, dword ptr [eax*4 + 0x572a68]
004932d4  ffe1                     jmp       ecx
004932d6  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004932da  8b08                     mov       ecx, dword ptr [eax]
004932dc  8b15d0275700             mov       edx, dword ptr [0x5727d0] ; bits=00000000, f32=0.0
004932e2  8b3520285700             mov       esi, dword ptr [0x572820] ; bits=00000000, f32=0.0
004932e8  8d3d30225700             lea       edi, [0x572230] ; bits=09020000, f32=7.300764999132297e-43
004932ee  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
004932f5  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
004932fc  894f08                   mov       dword ptr [edi + 8], ecx
004932ff  dbac2450020000           fld       xword ptr [esp + 0x250]
00493306  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
0049330d  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
00493314  894f28                   mov       dword ptr [edi + 0x28], ecx
00493317  899c24b8020000           mov       dword ptr [esp + 0x2b8], ebx
0049331e  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
00493325  894f34                   mov       dword ptr [edi + 0x34], ecx
00493328  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
0049332f  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
00493336  894f58                   mov       dword ptr [edi + 0x58], ecx
00493339  89b424b0020000           mov       dword ptr [esp + 0x2b0], esi
00493340  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
00493347  894f64                   mov       dword ptr [edi + 0x64], ecx
0049334a  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
00493351  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
00493358  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
0049335f  894f70                   mov       dword ptr [edi + 0x70], ecx
00493362  dbac24fc010000           fld       xword ptr [esp + 0x1fc]
00493369  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
00493370  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
00493377  894f7c                   mov       dword ptr [edi + 0x7c], ecx
0049337a  dbac2438020000           fld       xword ptr [esp + 0x238]
00493381  d99c24a0020000           fstp      dword ptr [esp + 0x2a0]
00493388  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
0049338f  898f88000000             mov       dword ptr [edi + 0x88], ecx
00493395  dbac2424010000           fld       xword ptr [esp + 0x124]
0049339c  d99c249c020000           fstp      dword ptr [esp + 0x29c]
004933a3  8d8c249c020000           lea       ecx, [esp + 0x29c]
004933aa  898f94000000             mov       dword ptr [edi + 0x94], ecx
004933b0  dbac2444020000           fld       xword ptr [esp + 0x244]
004933b7  d99c2498020000           fstp      dword ptr [esp + 0x298]
004933be  8d8c2498020000           lea       ecx, [esp + 0x298]
004933c5  898fa0000000             mov       dword ptr [edi + 0xa0], ecx
004933cb  57                       push      edi
004933cc  e8ef970200               call      0x4bcbc0 ; _jwe_isfm
004933d1  83c404                   add       esp, 4
004933d4  e9ed030000               jmp       0x4937c6
004933d9  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004933dd  8b08                     mov       ecx, dword ptr [eax]
004933df  89ea                     mov       edx, ebp
004933e1  8b74241c                 mov       esi, dword ptr [esp + 0x1c]
004933e5  8d3d80215700             lea       edi, [0x572180] ; bits=09020000, f32=7.300764999132297e-43
004933eb  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
004933f2  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
004933f9  894f08                   mov       dword ptr [edi + 8], ecx
004933fc  dbac2450020000           fld       xword ptr [esp + 0x250]
00493403  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
0049340a  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
00493411  894f28                   mov       dword ptr [edi + 0x28], ecx
00493414  899c24b8020000           mov       dword ptr [esp + 0x2b8], ebx
0049341b  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
00493422  894f34                   mov       dword ptr [edi + 0x34], ecx
00493425  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
0049342c  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
00493433  894f58                   mov       dword ptr [edi + 0x58], ecx
00493436  89b424b0020000           mov       dword ptr [esp + 0x2b0], esi
0049343d  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
00493444  894f64                   mov       dword ptr [edi + 0x64], ecx
00493447  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
0049344e  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
00493455  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
0049345c  894f70                   mov       dword ptr [edi + 0x70], ecx
0049345f  dbac24fc010000           fld       xword ptr [esp + 0x1fc]
00493466  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
0049346d  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
00493474  894f7c                   mov       dword ptr [edi + 0x7c], ecx
00493477  dbac2438020000           fld       xword ptr [esp + 0x238]
0049347e  d99c24a0020000           fstp      dword ptr [esp + 0x2a0]
00493485  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
0049348c  898f88000000             mov       dword ptr [edi + 0x88], ecx
00493492  dbac2424010000           fld       xword ptr [esp + 0x124]
00493499  d99c249c020000           fstp      dword ptr [esp + 0x29c]
004934a0  8d8c249c020000           lea       ecx, [esp + 0x29c]
004934a7  898f94000000             mov       dword ptr [edi + 0x94], ecx
004934ad  dbac2444020000           fld       xword ptr [esp + 0x244]
004934b4  d99c2498020000           fstp      dword ptr [esp + 0x298]
004934bb  8d8c2498020000           lea       ecx, [esp + 0x298]
004934c2  898fa0000000             mov       dword ptr [edi + 0xa0], ecx
004934c8  57                       push      edi
004934c9  e8f2960200               call      0x4bcbc0 ; _jwe_isfm
004934ce  83c404                   add       esp, 4
004934d1  e9f0020000               jmp       0x4937c6
004934d6  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004934da  8b08                     mov       ecx, dword ptr [eax]
004934dc  89ea                     mov       edx, ebp
004934de  8b74241c                 mov       esi, dword ptr [esp + 0x1c]
004934e2  8d3dd0205700             lea       edi, [0x5720d0] ; bits=09020000, f32=7.300764999132297e-43
004934e8  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
004934ef  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
004934f6  894f08                   mov       dword ptr [edi + 8], ecx
004934f9  dbac2450020000           fld       xword ptr [esp + 0x250]
00493500  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
00493507  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
0049350e  894f28                   mov       dword ptr [edi + 0x28], ecx
00493511  899c24b8020000           mov       dword ptr [esp + 0x2b8], ebx
00493518  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
0049351f  894f34                   mov       dword ptr [edi + 0x34], ecx
00493522  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
00493529  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
00493530  894f58                   mov       dword ptr [edi + 0x58], ecx
00493533  89b424b0020000           mov       dword ptr [esp + 0x2b0], esi
0049353a  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
00493541  894f64                   mov       dword ptr [edi + 0x64], ecx
00493544  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
0049354b  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
00493552  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
00493559  894f70                   mov       dword ptr [edi + 0x70], ecx
0049355c  dbac24fc010000           fld       xword ptr [esp + 0x1fc]
00493563  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
0049356a  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
00493571  894f7c                   mov       dword ptr [edi + 0x7c], ecx
00493574  dbac2438020000           fld       xword ptr [esp + 0x238]
0049357b  d99c24a0020000           fstp      dword ptr [esp + 0x2a0]
00493582  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
00493589  898f88000000             mov       dword ptr [edi + 0x88], ecx
0049358f  dbac2424010000           fld       xword ptr [esp + 0x124]
00493596  d99c249c020000           fstp      dword ptr [esp + 0x29c]
0049359d  8d8c249c020000           lea       ecx, [esp + 0x29c]
004935a4  898f94000000             mov       dword ptr [edi + 0x94], ecx
004935aa  dbac2444020000           fld       xword ptr [esp + 0x244]
004935b1  d99c2498020000           fstp      dword ptr [esp + 0x298]
004935b8  8d8c2498020000           lea       ecx, [esp + 0x298]
004935bf  898fa0000000             mov       dword ptr [edi + 0xa0], ecx
004935c5  57                       push      edi
004935c6  e8f5950200               call      0x4bcbc0 ; _jwe_isfm
004935cb  83c404                   add       esp, 4
004935ce  e9f3010000               jmp       0x4937c6
004935d3  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004935d7  8b08                     mov       ecx, dword ptr [eax]
004935d9  89ea                     mov       edx, ebp
004935db  8b74241c                 mov       esi, dword ptr [esp + 0x1c]
004935df  8d3d20205700             lea       edi, [0x572020] ; bits=09020000, f32=7.300764999132297e-43
004935e5  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
004935ec  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
004935f3  894f08                   mov       dword ptr [edi + 8], ecx
004935f6  dbac2450020000           fld       xword ptr [esp + 0x250]
004935fd  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
00493604  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
0049360b  894f28                   mov       dword ptr [edi + 0x28], ecx
0049360e  899c24b8020000           mov       dword ptr [esp + 0x2b8], ebx
00493615  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
0049361c  894f34                   mov       dword ptr [edi + 0x34], ecx
0049361f  899424b4020000           mov       dword ptr [esp + 0x2b4], edx
00493626  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
0049362d  894f58                   mov       dword ptr [edi + 0x58], ecx
00493630  89b424b0020000           mov       dword ptr [esp + 0x2b0], esi
00493637  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
0049363e  894f64                   mov       dword ptr [edi + 0x64], ecx
00493641  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
00493648  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
0049364f  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
00493656  894f70                   mov       dword ptr [edi + 0x70], ecx
00493659  dbac24fc010000           fld       xword ptr [esp + 0x1fc]
00493660  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
00493667  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
0049366e  894f7c                   mov       dword ptr [edi + 0x7c], ecx
00493671  dbac2438020000           fld       xword ptr [esp + 0x238]
00493678  d99c24a0020000           fstp      dword ptr [esp + 0x2a0]
0049367f  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
00493686  898f88000000             mov       dword ptr [edi + 0x88], ecx
0049368c  dbac2424010000           fld       xword ptr [esp + 0x124]
00493693  d99c249c020000           fstp      dword ptr [esp + 0x29c]
0049369a  8d8c249c020000           lea       ecx, [esp + 0x29c]
004936a1  898f94000000             mov       dword ptr [edi + 0x94], ecx
004936a7  dbac2444020000           fld       xword ptr [esp + 0x244]
004936ae  d99c2498020000           fstp      dword ptr [esp + 0x298]
004936b5  8d8c2498020000           lea       ecx, [esp + 0x298]
004936bc  898fa0000000             mov       dword ptr [edi + 0xa0], ecx
004936c2  57                       push      edi
004936c3  e8f8940200               call      0x4bcbc0 ; _jwe_isfm
004936c8  83c404                   add       esp, 4
004936cb  e9f6000000               jmp       0x4937c6
004936d0  8b44246c                 mov       eax, dword ptr [esp + 0x6c]
004936d4  8b08                     mov       ecx, dword ptr [eax]
004936d6  8d15701f5700             lea       edx, [0x571f70] ; bits=09020000, f32=7.300764999132297e-43
004936dc  898c24bc020000           mov       dword ptr [esp + 0x2bc], ecx
004936e3  8d8c24bc020000           lea       ecx, [esp + 0x2bc]
004936ea  894a08                   mov       dword ptr [edx + 8], ecx
004936ed  dbac2450020000           fld       xword ptr [esp + 0x250]
004936f4  d99c24cc020000           fstp      dword ptr [esp + 0x2cc]
004936fb  8d8c24cc020000           lea       ecx, [esp + 0x2cc]
00493702  894a28                   mov       dword ptr [edx + 0x28], ecx
00493705  899c24b8020000           mov       dword ptr [esp + 0x2b8], ebx
0049370c  8d8c24b8020000           lea       ecx, [esp + 0x2b8]
00493713  894a34                   mov       dword ptr [edx + 0x34], ecx
00493716  89ac24b4020000           mov       dword ptr [esp + 0x2b4], ebp
0049371d  8d8c24b4020000           lea       ecx, [esp + 0x2b4]
00493724  894a58                   mov       dword ptr [edx + 0x58], ecx
00493727  8b4c241c                 mov       ecx, dword ptr [esp + 0x1c]
0049372b  898c24b0020000           mov       dword ptr [esp + 0x2b0], ecx
00493732  8d8c24b0020000           lea       ecx, [esp + 0x2b0]
00493739  894a64                   mov       dword ptr [edx + 0x64], ecx
0049373c  dbac24f0010000           fld       xword ptr [esp + 0x1f0]
00493743  d99c24ac020000           fstp      dword ptr [esp + 0x2ac]
0049374a  8d8c24ac020000           lea       ecx, [esp + 0x2ac]
00493751  894a70                   mov       dword ptr [edx + 0x70], ecx
00493754  dbac24fc010000           fld       xword ptr [esp + 0x1fc]
0049375b  d99c24a8020000           fstp      dword ptr [esp + 0x2a8]
00493762  8d8c24a8020000           lea       ecx, [esp + 0x2a8]
00493769  894a7c                   mov       dword ptr [edx + 0x7c], ecx
0049376c  dbac2438020000           fld       xword ptr [esp + 0x238]
00493773  d99c24a0020000           fstp      dword ptr [esp + 0x2a0]
0049377a  8d8c24a0020000           lea       ecx, [esp + 0x2a0]
00493781  898a88000000             mov       dword ptr [edx + 0x88], ecx
00493787  dbac2424010000           fld       xword ptr [esp + 0x124]
0049378e  d99c249c020000           fstp      dword ptr [esp + 0x29c]
00493795  8d8c249c020000           lea       ecx, [esp + 0x29c]
0049379c  898a94000000             mov       dword ptr [edx + 0x94], ecx
004937a2  dbac2444020000           fld       xword ptr [esp + 0x244]
004937a9  d99c2498020000           fstp      dword ptr [esp + 0x298]
004937b0  8d8c2498020000           lea       ecx, [esp + 0x298]
004937b7  898aa0000000             mov       dword ptr [edx + 0xa0], ecx
004937bd  52                       push      edx
004937be  e8fd930200               call      0x4bcbc0 ; _jwe_isfm
004937c3  83c404                   add       esp, 4
004937c6  ff442438                 inc       dword ptr [esp + 0x38]
004937ca  836c243c01               sub       dword ptr [esp + 0x3c], 1
004937cf  0f8560efffff             jne       0x492735
004937d5  8b8424e8020000           mov       eax, dword ptr [esp + 0x2e8]
004937dc  8b00                     mov       eax, dword ptr [eax]
004937de  8b0d28285700             mov       ecx, dword ptr [0x572828] ; bits=00000000, f32=0.0
004937e4  8b742444                 mov       esi, dword ptr [esp + 0x44]
004937e8  890c85dc1a0002           mov       dword ptr [eax*4 + 0x2001adc], ecx
004937ef  c704b5a40eeb0100000000   mov       dword ptr [esi*4 + 0x1eb0ea4], 0
004937fa  c704b5e491eb0100000000   mov       dword ptr [esi*4 + 0x1eb91e4], 0
00493805  b800000000               mov       eax, 0
0049380a  5f                       pop       edi
0049380b  5e                       pop       esi
0049380c  5b                       pop       ebx
0049380d  5d                       pop       ebp
0049380e  81c4c0020000             add       esp, 0x2c0
00493814  c3                       ret
00493815  8d642400                 lea       esp, [esp]
00493819  8da42400000000           lea       esp, [esp]
